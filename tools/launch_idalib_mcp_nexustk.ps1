[CmdletBinding()]
param(
    [string]$TargetPath = "E:\NTK\Resources\NexusTK\NexusTK.exe.i64",
    [string]$HostAddress = "127.0.0.1",
    [int]$Port = 13337,
    [string]$ServerExe = (Join-Path $env:USERPROFILE ".idapro\idalib-mcp-venv\Scripts\idalib-mcp.exe"),
    [int]$RefreshSeconds = 300,
    [switch]$StatusOnly,
    [switch]$NoRestartOnLaunch,
    [switch]$RestartOnce
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$LogDir = Join-Path $PSScriptRoot "idalib-mcp-logs"
$EventLog = Join-Path $LogDir "idalib-mcp-supervisor-events.log"

function Write-EventLogLine {
    param([string]$Message)

    try {
        New-Item -ItemType Directory -Force -Path $LogDir | Out-Null
        $stamp = Get-Date -Format "o"
        Add-Content -LiteralPath $EventLog -Value ("{0}`tlauncher_pid={1}`t{2}" -f $stamp, $PID, $Message)
    } catch {
    }
}

function Get-NowStamp {
    Get-Date -Format "yyyyMMdd_HHmmss"
}

function Get-ListeningPort {
    @(Get-NetTCPConnection -LocalAddress $HostAddress -LocalPort $Port -ErrorAction SilentlyContinue |
        Where-Object { $_.State -eq "Listen" })
}

function Get-ManagedProcessInfo {
    $serverPath = $ServerExe

    @(Get-CimInstance Win32_Process | Where-Object {
        ($_.Name -eq "idalib-mcp.exe" -and $_.ExecutablePath -eq $serverPath) -or
        ($_.Name -eq "python.exe" -and $null -ne $_.CommandLine -and
            $_.CommandLine -like "*$serverPath*" -and $_.CommandLine -like "*--port $Port*") -or
        ($_.Name -eq "python.exe" -and $null -ne $_.CommandLine -and
            $_.CommandLine -like "*-m ida_pro_mcp.idalib_server*--port*")
    })
}

function Get-ProcessLabel {
    param([int]$ProcessId)

    try {
        $process = Get-Process -Id $ProcessId -ErrorAction Stop
        return ("PID {0} ({1})" -f $ProcessId, $process.ProcessName)
    } catch {
        return ("PID {0}" -f $ProcessId)
    }
}

function Test-McpHealth {
    $headers = @{ Accept = "application/json, text/event-stream" }
    $listBody = @{
        jsonrpc = "2.0"
        id      = 1
        method  = "tools/call"
        params  = @{
            name      = "idb_list"
            arguments = @{}
        }
    } | ConvertTo-Json -Depth 8

    try {
        $listResponse = Invoke-WebRequest `
            -UseBasicParsing `
            -Uri "http://$HostAddress`:$Port/mcp" `
            -Method Post `
            -ContentType "application/json" `
            -Headers $headers `
            -Body $listBody `
            -TimeoutSec 10

        if ($listResponse.StatusCode -ne 200) {
            return $false
        }

        $listPayload = $listResponse.Content | ConvertFrom-Json
        $sessions = @($listPayload.result.structuredContent.sessions)
        $session = $sessions | Where-Object {
            $_.is_active -eq $true -and -not [string]::IsNullOrWhiteSpace([string]$_.session_id)
        } | Select-Object -First 1
        if ($null -eq $session) {
            Write-EventLogLine "health_check_failed reason=no_active_idb_session"
            return $false
        }

        $healthBody = @{
            jsonrpc = "2.0"
            id      = 2
            method  = "tools/call"
            params  = @{
                name      = "server_health"
                arguments = @{ database = [string]$session.session_id }
            }
        } | ConvertTo-Json -Depth 8
        $healthResponse = Invoke-WebRequest `
            -UseBasicParsing `
            -Uri "http://$HostAddress`:$Port/mcp" `
            -Method Post `
            -ContentType "application/json" `
            -Headers $headers `
            -Body $healthBody `
            -TimeoutSec 10
        if ($healthResponse.StatusCode -ne 200) {
            return $false
        }

        $healthPayload = $healthResponse.Content | ConvertFrom-Json
        return ($healthPayload.result.isError -ne $true)
    } catch {
        Write-EventLogLine ("health_check_failed endpoint=http://{0}:{1}/mcp error={2}" -f $HostAddress, $Port, $_.Exception.Message)
        return $false
    }
}

function Get-ServerStatus {
    $listeners = @(Get-ListeningPort)
    if ($listeners.Count -eq 0) {
        return [pscustomobject]@{
            Label     = "Stopped"
            Running   = $false
            Healthy   = $false
            Detail    = "No listener is active on $HostAddress`:$Port."
            Listeners = @()
        }
    }

    $healthy = Test-McpHealth
    $listenerText = @()
    foreach ($listener in $listeners) {
        $listenerText += Get-ProcessLabel -ProcessId ([int]$listener.OwningProcess)
    }

    if ($healthy) {
        $label = "Healthy, Running"
        $detail = "MCP endpoint, active IDB session, and IDB-backed server_health answered on http://$HostAddress`:$Port/mcp."
    } else {
        $label = "Unhealthy, Running"
        $detail = "Something is listening on $HostAddress`:$Port, but MCP did not answer cleanly."
    }

    return [pscustomobject]@{
        Label     = $label
        Running   = $true
        Healthy   = $healthy
        Detail    = $detail
        Listeners = $listenerText
    }
}

function Stop-Server {
    $managed = @(Get-ManagedProcessInfo)
    $managedIds = @{}
    foreach ($proc in $managed) {
        $id = [int]$proc.ProcessId
        if ($id -gt 4 -and $id -ne $PID) {
            $managedIds[$id] = $true
        }
    }

    $changed = $true
    while ($changed) {
        $changed = $false
        $children = @(Get-CimInstance Win32_Process | Where-Object {
            $parentId = [int]$_.ParentProcessId
            $childId = [int]$_.ProcessId
            $managedIds.ContainsKey($parentId) -and $childId -gt 4 -and $childId -ne $PID
        })

        foreach ($child in $children) {
            $childId = [int]$child.ProcessId
            if (-not $managedIds.ContainsKey($childId)) {
                $managedIds[$childId] = $true
                $changed = $true
            }
        }
    }

    $targets = @($managedIds.Keys | Sort-Object -Descending)
    if ($targets.Count -eq 0) {
        Write-EventLogLine "stop_requested result=no_managed_processes"
        return "No managed idalib-mcp processes were found."
    }

    Write-EventLogLine ("stop_requested target_pids={0}" -f (($targets -join ",")))
    foreach ($targetId in $targets) {
        try {
            Stop-Process -Id $targetId -Force -ErrorAction Stop
        } catch {
            Write-EventLogLine ("stop_failed pid={0} error={1}" -f $targetId, $_.Exception.Message)
        }
    }

    Start-Sleep -Seconds 2
    Write-EventLogLine ("stop_completed count={0}" -f $targets.Count)
    return ("Stopped {0} managed process(es)." -f $targets.Count)
}

function Start-Server {
    if (-not (Test-Path -LiteralPath $ServerExe)) {
        Write-EventLogLine ("start_failed missing_server path={0}" -f $ServerExe)
        return "Cannot start: idalib-mcp was not found at $ServerExe"
    }

    if (-not (Test-Path -LiteralPath $TargetPath)) {
        Write-EventLogLine ("start_failed missing_target path={0}" -f $TargetPath)
        return "Cannot start: target file was not found at $TargetPath"
    }

    $listeners = @(Get-ListeningPort)
    if ($listeners.Count -gt 0) {
        Write-EventLogLine ("start_refused port_already_listening listeners={0}" -f (($listeners | ForEach-Object { "$($_.OwningProcess):$($_.State)" }) -join ","))
        return "Cannot start: port $Port is already listening. Use Restart or Stop first."
    }

    New-Item -ItemType Directory -Force -Path $LogDir | Out-Null
    $stamp = Get-NowStamp
    $stdout = Join-Path $LogDir "idalib-mcp-$stamp.out.log"
    $stderr = Join-Path $LogDir "idalib-mcp-$stamp.err.log"

    $oldCallLog = $env:IDA_MCP_LOG_CALLS
    $env:IDA_MCP_LOG_CALLS = "1"
    try {
        $proc = Start-Process `
            -FilePath $ServerExe `
            -ArgumentList @("--host", $HostAddress, "--port", [string]$Port, $TargetPath) `
            -WindowStyle Hidden `
            -RedirectStandardOutput $stdout `
            -RedirectStandardError $stderr `
            -PassThru
    } finally {
        if ($null -eq $oldCallLog) {
            Remove-Item Env:\IDA_MCP_LOG_CALLS -ErrorAction SilentlyContinue
        } else {
            $env:IDA_MCP_LOG_CALLS = $oldCallLog
        }
    }
    Write-EventLogLine ("start_requested pid={0} target={1} stdout={2} stderr={3} call_logging=enabled" -f $proc.Id, $TargetPath, $stdout, $stderr)

    $postStatus = $null
    for ($attempt = 1; $attempt -le 15; $attempt++) {
        Start-Sleep -Seconds 2
        $postStatus = Get-ServerStatus
        if ($postStatus.Healthy) {
            break
        }
    }
    Write-EventLogLine ("start_post_status label={0} detail={1}" -f $postStatus.Label, $postStatus.Detail)
    return "Started idalib-mcp. Logs: $stdout ; $stderr"
}

function Restart-Server {
    Write-EventLogLine "restart_requested"
    $stopMessage = Stop-Server
    Start-Sleep -Seconds 1
    $startMessage = Start-Server
    Write-EventLogLine ("restart_completed stop=[{0}] start=[{1}]" -f (($stopMessage -replace "`r?`n", " | ")), (($startMessage -replace "`r?`n", " | ")))
    return "$stopMessage`n$startMessage"
}

function Show-StatusScreen {
    param(
        [object]$Status,
        [string]$Message
    )

    Clear-Host
    Write-Host "NexusTK IDA MCP Headless Launcher"
    Write-Host ""
    Write-Host "Target:   $TargetPath"
    Write-Host "Server:   $ServerExe"
    Write-Host "Endpoint: http://$HostAddress`:$Port/mcp"
    Write-Host "Refresh:  every $RefreshSeconds seconds"
    Write-Host ""
    Write-Host "Status:   $($Status.Label)"
    Write-Host "Detail:   $($Status.Detail)"

    if (@($Status.Listeners).Count -gt 0) {
        Write-Host "Listener:"
        foreach ($listener in @($Status.Listeners)) {
            Write-Host "  $listener"
        }
    }

    if (-not [string]::IsNullOrWhiteSpace($Message)) {
        Write-Host ""
        Write-Host "Last action:"
        foreach ($line in ($Message -split "`n")) {
            Write-Host "  $line"
        }
    }

    Write-Host ""
    Write-Host "Options:"
    if (-not $Status.Running) {
        Write-Host "  O - Open/start server"
    }
    Write-Host "  R - Restart server"
    Write-Host "  S - Stop server"
    Write-Host "  C - Check now"
    Write-Host "  Q - Quit this menu without changing server state"
    Write-Host ""
    Write-Host "Waiting for input, or auto-refreshing at the next interval..."
}

function Read-KeyOrTimeout {
    param([int]$Seconds)

    $deadline = (Get-Date).AddSeconds($Seconds)
    while ((Get-Date) -lt $deadline) {
        try {
            if ($Host.UI.RawUI.KeyAvailable) {
                $key = $Host.UI.RawUI.ReadKey("NoEcho,IncludeKeyDown")
                if ($key.Character -and [int][char]$key.Character -ne 0) {
                    return $key.Character.ToString().ToUpperInvariant()
                }
            }
        } catch {
            try {
                if ([Console]::KeyAvailable) {
                    return ([Console]::ReadKey($true).KeyChar.ToString().ToUpperInvariant())
                }
            } catch {
            }
        }
        Start-Sleep -Milliseconds 500
    }

    return ""
}

if ($StatusOnly) {
    $status = Get-ServerStatus
    Write-EventLogLine ("status_only label={0} detail={1}" -f $status.Label, $status.Detail)
    Write-Host "Target: $TargetPath"
    Write-Host "Status: $($status.Label)"
    Write-Host "Detail: $($status.Detail)"
    exit 0
}

if ($RestartOnce) {
    Write-EventLogLine "restart_once_requested"
    $message = Restart-Server
    $status = Get-ServerStatus
    Write-EventLogLine ("restart_once_finished label={0} detail={1}" -f $status.Label, $status.Detail)
    Write-Host $message
    Write-Host "Status: $($status.Label)"
    Write-Host "Detail: $($status.Detail)"
    exit 0
}

$lastMessage = ""
if (-not $NoRestartOnLaunch) {
    $initialStatus = Get-ServerStatus
    if ($initialStatus.Running) {
        Write-EventLogLine ("startup_existing_listener_action=restart label={0} detail={1}" -f $initialStatus.Label, $initialStatus.Detail)
        $lastMessage = "Server was already listening on startup; restarting it.`n$(Restart-Server)"
    }
} else {
    $initialStatus = Get-ServerStatus
    Write-EventLogLine ("startup_no_restart label={0} detail={1}" -f $initialStatus.Label, $initialStatus.Detail)
}

while ($true) {
    $status = Get-ServerStatus
    Show-StatusScreen -Status $status -Message $lastMessage
    $lastMessage = ""

    $key = Read-KeyOrTimeout -Seconds $RefreshSeconds
    switch ($key) {
        "O" {
            if ($status.Running) {
                Write-EventLogLine "open_requested result=already_running"
                $lastMessage = "Server is already running."
            } else {
                Write-EventLogLine "open_requested result=start"
                $lastMessage = Start-Server
            }
        }
        "R" {
            Write-EventLogLine "manual_restart_key"
            $lastMessage = Restart-Server
        }
        "S" {
            Write-EventLogLine "manual_stop_key"
            $lastMessage = Stop-Server
        }
        "C" {
            Write-EventLogLine "manual_check_key"
            $lastMessage = "Manual health check completed."
        }
        "Q" {
            Write-EventLogLine "quit_menu_no_state_change"
            Write-Host "Leaving menu. Server state was not changed."
            exit 0
        }
        default {
            $lastMessage = ""
        }
    }
}
