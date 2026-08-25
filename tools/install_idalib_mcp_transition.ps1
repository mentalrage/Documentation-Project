[CmdletBinding()]
param(
    [ValidateSet("Install", "Restore", "Status")]
    [string]$Action = "Install",

    [string]$IdaPath = "C:\Program Files\IDA Professional 9.1",

    [int]$Port = 13337,

    [string]$VenvPath = (Join-Path $env:USERPROFILE ".idapro\idalib-mcp-venv"),

    [string]$Python = "python",

    [string]$PackageUrl = "https://github.com/mrexodia/ida-pro-mcp/archive/refs/heads/main.zip",

    [string]$BinaryPath = "",

    [string]$BackupStamp = "",

    [switch]$Launch,

    [switch]$Force
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

function Get-PluginPaths {
    $pluginRoot = Join-Path $env:APPDATA "Hex-Rays\IDA Pro\plugins"
    [pscustomobject]@{
        Root       = $pluginRoot
        OldPy      = Join-Path $pluginRoot "ida_mcp.py"
        OldDir     = Join-Path $pluginRoot "ida_mcp"
        BackupRoot = Join-Path $pluginRoot "_ida_mcp_backups"
    }
}

function Test-RealPath {
    param([object]$Path)

    if ($null -eq $Path) {
        return $false
    }

    $text = [string]$Path
    if ([string]::IsNullOrWhiteSpace($text)) {
        return $false
    }

    return Test-Path -LiteralPath $text
}

function Get-PortUsers {
    param([int]$LocalPort)

    try {
        Get-NetTCPConnection -LocalPort $LocalPort -ErrorAction Stop |
            Select-Object LocalAddress, LocalPort, State, OwningProcess
    } catch {
        @()
    }
}

function Write-PortStatus {
    param([int]$LocalPort)

    $users = @(Get-PortUsers -LocalPort $LocalPort)
    if ($users.Count -eq 0) {
        Write-Host "Port $LocalPort is not currently in use."
        return
    }

    Write-Warning "Port $LocalPort is already in use:"
    foreach ($entry in $users) {
        $processName = "<unknown>"
        try {
            $processName = (Get-Process -Id $entry.OwningProcess -ErrorAction Stop).ProcessName
        } catch {
        }

        Write-Host ("  PID {0} ({1}) {2}:{3} {4}" -f $entry.OwningProcess, $processName, $entry.LocalAddress, $entry.LocalPort, $entry.State)
    }
}

function Get-LatestManifest {
    param(
        [string]$BackupRoot,
        [string]$Stamp
    )

    if (-not (Test-Path -LiteralPath $BackupRoot)) {
        throw "No backup root exists at: $BackupRoot"
    }

    if (-not [string]::IsNullOrWhiteSpace($Stamp)) {
        $manifestPath = Join-Path (Join-Path $BackupRoot $Stamp) "manifest.json"
        if (-not (Test-Path -LiteralPath $manifestPath)) {
            throw "Requested backup stamp was not found: $Stamp"
        }
        return $manifestPath
    }

    $manifest = Get-ChildItem -LiteralPath $BackupRoot -Directory |
        Sort-Object Name -Descending |
        ForEach-Object {
            $candidate = Join-Path $_.FullName "manifest.json"
            if (Test-Path -LiteralPath $candidate) {
                $candidate
            }
        } |
        Select-Object -First 1

    if ([string]::IsNullOrWhiteSpace($manifest)) {
        throw "No backup manifests were found in: $BackupRoot"
    }

    return $manifest
}

function Install-IdalibMcp {
    $idalibPython = Join-Path $IdaPath "idalib\python"
    $activateScript = Join-Path $idalibPython "py-activate-idalib.py"
    $setupScript = Join-Path $idalibPython "setup.py"

    if (-not (Test-Path -LiteralPath $IdaPath)) {
        throw "IDA path does not exist: $IdaPath"
    }
    if (-not (Test-Path -LiteralPath $activateScript)) {
        throw "Could not find py-activate-idalib.py at: $activateScript"
    }
    if (-not (Test-Path -LiteralPath $setupScript)) {
        throw "Could not find idalib setup.py at: $setupScript"
    }

    if (-not (Test-Path -LiteralPath $VenvPath)) {
        Write-Host "Creating venv: $VenvPath"
        & $Python -m venv $VenvPath
    } else {
        Write-Host "Reusing venv: $VenvPath"
    }

    $venvPython = Join-Path $VenvPath "Scripts\python.exe"
    if (-not (Test-Path -LiteralPath $venvPython)) {
        throw "The venv Python was not created: $venvPython"
    }

    Write-Host "Upgrading pip..."
    & $venvPython -m pip install --upgrade pip

    Write-Host "Installing IDA idalib Python package from local IDA install..."
    & $venvPython -m pip install $idalibPython

    Write-Host "Activating idalib for this Python environment..."
    & $venvPython $activateScript -d $IdaPath

    Write-Host "Installing latest ida-pro-mcp from upstream main..."
    & $venvPython -m pip install --upgrade $PackageUrl

    $server = Join-Path $VenvPath "Scripts\idalib-mcp.exe"
    if (-not (Test-Path -LiteralPath $server)) {
        throw "idalib-mcp.exe was not installed at: $server"
    }

    Write-Host "Installed idalib-mcp: $server"
}

function Backup-And-Disable-OldPlugin {
    $paths = Get-PluginPaths

    if (-not (Test-Path -LiteralPath $paths.Root)) {
        Write-Host "IDA user plugin directory does not exist yet: $($paths.Root)"
        return
    }

    $hasOldPy = Test-Path -LiteralPath $paths.OldPy
    $hasOldDir = Test-Path -LiteralPath $paths.OldDir
    if (-not $hasOldPy -and -not $hasOldDir) {
        Write-Host "No active ida_mcp GUI plugin files were found to disable."
        return
    }

    $stamp = Get-Date -Format "yyyyMMdd_HHmmss"
    $backupDir = Join-Path $paths.BackupRoot $stamp
    New-Item -ItemType Directory -Force -Path $backupDir | Out-Null

    $disabledPy = Join-Path $paths.Root "ida_mcp.py.disabled.$stamp"
    $disabledDir = Join-Path $paths.Root "ida_mcp.disabled.$stamp"
    $backupPy = $null
    $backupPluginDir = $null

    if ($hasOldPy) {
        $backupPy = Join-Path $backupDir "ida_mcp.py"
        Copy-Item -LiteralPath $paths.OldPy -Destination $backupPy
    }

    if ($hasOldDir) {
        $backupPluginDir = Join-Path $backupDir "ida_mcp"
        Copy-Item -LiteralPath $paths.OldDir -Destination $backupPluginDir -Recurse
    }

    $manifest = [ordered]@{
        stamp          = $stamp
        created_at     = (Get-Date).ToString("o")
        old_plugin_py  = $paths.OldPy
        old_plugin_dir = $paths.OldDir
        disabled_py    = $disabledPy
        disabled_dir   = $disabledDir
        backup_py      = $backupPy
        backup_dir     = $backupPluginDir
        ida_path       = $IdaPath
        venv_path      = $VenvPath
        package_url    = $PackageUrl
    }

    $manifestPath = Join-Path $backupDir "manifest.json"
    $manifest | ConvertTo-Json -Depth 6 | Set-Content -LiteralPath $manifestPath -Encoding UTF8

    if ($hasOldPy) {
        Move-Item -LiteralPath $paths.OldPy -Destination $disabledPy
        Write-Host "Disabled old plugin file: $disabledPy"
    }

    if ($hasOldDir) {
        Move-Item -LiteralPath $paths.OldDir -Destination $disabledDir
        Write-Host "Disabled old plugin folder: $disabledDir"
    }

    Write-Host "Backup manifest: $manifestPath"
}

function Restore-OldPlugin {
    $paths = Get-PluginPaths
    $manifestPath = Get-LatestManifest -BackupRoot $paths.BackupRoot -Stamp $BackupStamp
    $manifest = Get-Content -LiteralPath $manifestPath -Raw | ConvertFrom-Json

    Write-Host "Restoring from backup manifest: $manifestPath"

    if (Test-Path -LiteralPath $paths.OldPy) {
        if (-not $Force) {
            throw "Active plugin file already exists. Use -Force to move it aside: $($paths.OldPy)"
        }
        $aside = "$($paths.OldPy).pre_restore.$(Get-Date -Format 'yyyyMMdd_HHmmss')"
        Move-Item -LiteralPath $paths.OldPy -Destination $aside
        Write-Host "Moved current plugin file aside: $aside"
    }

    if (Test-Path -LiteralPath $paths.OldDir) {
        if (-not $Force) {
            throw "Active plugin folder already exists. Use -Force to move it aside: $($paths.OldDir)"
        }
        $aside = "$($paths.OldDir).pre_restore.$(Get-Date -Format 'yyyyMMdd_HHmmss')"
        Move-Item -LiteralPath $paths.OldDir -Destination $aside
        Write-Host "Moved current plugin folder aside: $aside"
    }

    if (Test-RealPath $manifest.disabled_py) {
        Move-Item -LiteralPath ([string]$manifest.disabled_py) -Destination $paths.OldPy
        Write-Host "Restored plugin file from disabled copy."
    } elseif (Test-RealPath $manifest.backup_py) {
        Copy-Item -LiteralPath ([string]$manifest.backup_py) -Destination $paths.OldPy
        Write-Host "Restored plugin file from backup copy."
    } else {
        Write-Warning "No plugin file was found in the disabled copy or backup."
    }

    if (Test-RealPath $manifest.disabled_dir) {
        Move-Item -LiteralPath ([string]$manifest.disabled_dir) -Destination $paths.OldDir
        Write-Host "Restored plugin folder from disabled copy."
    } elseif (Test-RealPath $manifest.backup_dir) {
        Copy-Item -LiteralPath ([string]$manifest.backup_dir) -Destination $paths.OldDir -Recurse
        Write-Host "Restored plugin folder from backup copy."
    } else {
        Write-Warning "No plugin folder was found in the disabled copy or backup."
    }
}

function Show-Status {
    $paths = Get-PluginPaths
    $server = Join-Path $VenvPath "Scripts\idalib-mcp.exe"

    Write-Host "IDA path: $IdaPath"
    Write-Host "Venv path: $VenvPath"
    Write-Host "idalib-mcp installed: $(Test-Path -LiteralPath $server)"
    Write-Host "Active old plugin file: $(Test-Path -LiteralPath $paths.OldPy) - $($paths.OldPy)"
    Write-Host "Active old plugin folder: $(Test-Path -LiteralPath $paths.OldDir) - $($paths.OldDir)"

    if (Test-Path -LiteralPath $paths.Root) {
        $disabled = @(Get-ChildItem -LiteralPath $paths.Root -Force -ErrorAction SilentlyContinue |
            Where-Object { $_.Name -like "ida_mcp*.disabled.*" } |
            Select-Object -ExpandProperty Name)
        if ($disabled.Count -gt 0) {
            Write-Host "Disabled old plugin items:"
            foreach ($item in $disabled) {
                Write-Host "  $item"
            }
        }
    }

    if (Test-Path -LiteralPath $paths.BackupRoot) {
        $backups = @(Get-ChildItem -LiteralPath $paths.BackupRoot -Directory |
            Sort-Object Name -Descending |
            Select-Object -First 5 -ExpandProperty Name)
        if ($backups.Count -gt 0) {
            Write-Host "Recent backups:"
            foreach ($backup in $backups) {
                Write-Host "  $backup"
            }
        }
    }

    Write-PortStatus -LocalPort $Port
}

function Start-IdalibMcp {
    $server = Join-Path $VenvPath "Scripts\idalib-mcp.exe"
    if (-not (Test-Path -LiteralPath $server)) {
        throw "idalib-mcp is not installed at: $server"
    }

    $users = @(Get-PortUsers -LocalPort $Port)
    if ($users.Count -gt 0) {
        Write-PortStatus -LocalPort $Port
        throw "Port $Port is already in use. Close the old IDA MCP server or the IDA process using that port, then run the launch command again."
    }

    $args = @("--host", "127.0.0.1", "--port", [string]$Port)
    if (-not [string]::IsNullOrWhiteSpace($BinaryPath)) {
        if (-not (Test-Path -LiteralPath $BinaryPath)) {
            throw "Binary path does not exist: $BinaryPath"
        }
        $args += $BinaryPath
    }

    Write-Host "Starting idalib-mcp on 127.0.0.1:$Port. Press Ctrl+C to stop it."
    & $server @args
}

switch ($Action) {
    "Install" {
        Install-IdalibMcp
        Backup-And-Disable-OldPlugin
        Show-Status

        $server = Join-Path $VenvPath "Scripts\idalib-mcp.exe"
        Write-Host ""
        Write-Host "Launch command:"
        if ([string]::IsNullOrWhiteSpace($BinaryPath)) {
            Write-Host "  & `"$server`" --host 127.0.0.1 --port $Port"
        } else {
            Write-Host "  & `"$server`" --host 127.0.0.1 --port $Port `"$BinaryPath`""
        }

        if ($Launch) {
            Start-IdalibMcp
        }
    }

    "Restore" {
        Restore-OldPlugin
        Show-Status
    }

    "Status" {
        Show-Status
    }
}
