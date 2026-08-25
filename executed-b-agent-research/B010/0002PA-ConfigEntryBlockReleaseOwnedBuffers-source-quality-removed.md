<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B010\0002PA-ConfigEntryBlockReleaseOwnedBuffers-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002PA-ConfigEntryBlockReleaseOwnedBuffers-source-quality.md](0002PA-ConfigEntryBlockReleaseOwnedBuffers-source-quality.md)
- Source report SHA256 before archive-link insertion: `A8AEE7B68F901DE4CE432A9903FD1B7288451150031349B7A96C429FDA1C6D49`
- Recovery generated: `2026-08-09T22:17:53Z`
- Unique recovered executable blocks: `30`
- Recovered executable bytes: `909527`
- Recovery basis: report-path-associated Codex session history. The source report had already removed its executable packages before the supervisor could extract them directly.
- Scope: this archive preserves every unique recoverable report-local executable block, including superseded historical variants where session history retained more than the final pre-removal report.
- Authority: this file is not a B-agent research report, claims no target coverage, and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- SHA256: `F1833839F3EF6C7098935C2D633763A53ACE2A42585D7AA56003E4B6E66A35E9`
- Language: `powershell`
- Bytes: `7347`
- First recovered timestamp: `2026-08-06T22:30:40.068Z`
- Session provenance: rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 193744 (2026-08-06T22:30:40.068Z); rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 193745 (2026-08-06T22:30:40.116Z)

~~~powershell
function Get-UID0002PAStreamSha256 {
    param([Parameter(Mandatory=$true)][System.IO.FileStream]$Stream)

    $Stream.Position = 0
    $sha = [System.Security.Cryptography.SHA256]::Create()
    try {
        $digest = $sha.ComputeHash($Stream)
    }
    finally {
        $sha.Dispose()
    }
    $Stream.Position = 0
    return ([System.BitConverter]::ToString($digest)).Replace('-', '')
}

function Get-UID0002PAExclusiveTuple {
    param([Parameter(Mandatory=$true)][string]$Path)

    $full = [System.IO.Path]::GetFullPath($Path)
    if (-not [System.IO.File]::Exists($full)) { throw "missing file: $full" }
    $beforeTicks = [System.IO.File]::GetLastWriteTimeUtc($full).Ticks
    $stream = $null
    try {
        $stream = [System.IO.FileStream]::new(
            $full,
            [System.IO.FileMode]::Open,
            [System.IO.FileAccess]::Read,
            [System.IO.FileShare]::None)
        $length = [long]$stream.Length
        if ($length -le 0) { throw "nonpositive length: $full" }
        $sha256 = Get-UID0002PAStreamSha256 -Stream $stream
    }
    finally {
        if ($null -ne $stream) { $stream.Dispose() }
    }
    $afterTicks = [System.IO.File]::GetLastWriteTimeUtc($full).Ticks
    if ($beforeTicks -ne $afterTicks) { throw "mtime changed during tuple capture: $full" }
    return [pscustomobject]@{
        FullPath = $full
        Length = $length
        LastWriteTimeUtcTicks = [long]$afterTicks
        SHA256 = $sha256
    }
}

function Assert-UID0002PATuple {
    param(
        [Parameter(Mandatory=$true)]$Actual,
        [Parameter(Mandatory=$true)]$Expected,
        [Parameter(Mandatory=$true)][string]$Label)

    foreach ($property in 'FullPath','Length','LastWriteTimeUtcTicks','SHA256') {
        if ([string]$Actual.$property -cne [string]$Expected.$property) {
            throw "$Label tuple mismatch at $property"
        }
    }
}

function New-UID0002PABackup {
    param(
        [Parameter(Mandatory=$true)][string]$CanonicalPath,
        [Parameter(Mandatory=$true)][string]$BackupPath)

    $canonical = [System.IO.Path]::GetFullPath($CanonicalPath)
    $backup = [System.IO.Path]::GetFullPath($BackupPath)
    if ($canonical -ieq $backup) { throw 'backup aliases canonical' }
    if ([System.IO.File]::Exists($backup)) { throw 'backup collision; do not overwrite' }

    $source = $null
    $destination = $null
    try {
        $source = [System.IO.FileStream]::new(
            $canonical,
            [System.IO.FileMode]::Open,
            [System.IO.FileAccess]::Read,
            [System.IO.FileShare]::None)
        $p0Length = [long]$source.Length
        $p0Ticks = [long][System.IO.File]::GetLastWriteTimeUtc($canonical).Ticks
        $p0Sha = Get-UID0002PAStreamSha256 -Stream $source
        $source.Position = 0

        $destination = [System.IO.FileStream]::new(
            $backup,
            [System.IO.FileMode]::CreateNew,
            [System.IO.FileAccess]::Write,
            [System.IO.FileShare]::None)
        $buffer = New-Object byte[] 1048576
        $copied = [long]0
        while (($read = $source.Read($buffer, 0, $buffer.Length)) -gt 0) {
            $destination.Write($buffer, 0, $read)
            $copied += $read
        }
        if ($copied -ne $p0Length -or $source.Position -ne $p0Length) {
            throw 'backup source EOF/copy-count mismatch'
        }
        if ($destination.Length -ne $p0Length) { throw 'backup destination length mismatch' }
        $destination.Flush($true)
    }
    finally {
        if ($null -ne $destination) { $destination.Dispose() }
        if ($null -ne $source) { $source.Dispose() }
    }

    [System.IO.File]::SetLastWriteTimeUtc(
        $backup,
        [DateTime]::new($p0Ticks, [DateTimeKind]::Utc))
    $p0 = Get-UID0002PAExclusiveTuple -Path $canonical
    $b0 = Get-UID0002PAExclusiveTuple -Path $backup
    if ($p0.FullPath -ieq $b0.FullPath) { throw 'closed backup aliases canonical' }
    if ($p0.Length -ne $p0Length -or $p0.LastWriteTimeUtcTicks -ne $p0Ticks -or $p0.SHA256 -cne $p0Sha) {
        throw 'canonical changed while creating backup'
    }
    $expectedB0 = [pscustomobject]@{
        FullPath = $backup
        Length = $p0.Length
        LastWriteTimeUtcTicks = $p0.LastWriteTimeUtcTicks
        SHA256 = $p0.SHA256
    }
    Assert-UID0002PATuple -Actual $b0 -Expected $expectedB0 -Label 'B0'
    return [pscustomobject]@{ P0 = $p0; B0 = $b0 }
}

function Restore-UID0002PABackup {
    param(
        [Parameter(Mandatory=$true)][string]$CanonicalPath,
        [Parameter(Mandatory=$true)][string]$BackupPath,
        [Parameter(Mandatory=$true)]$ExpectedP0,
        [Parameter(Mandatory=$true)]$ExpectedAttemptOwnedS1)

    $canonical = [System.IO.Path]::GetFullPath($CanonicalPath)
    $backup = [System.IO.Path]::GetFullPath($BackupPath)
    if ($canonical -ieq $backup) { throw 'restore source aliases canonical' }
    Assert-UID0002PATuple -Actual (Get-UID0002PAExclusiveTuple -Path $canonical) -Expected $ExpectedAttemptOwnedS1 -Label 'pre-restore S1/F1'
    Assert-UID0002PATuple -Actual (Get-UID0002PAExclusiveTuple -Path $backup) -Expected $ExpectedP0 -Label 'pre-restore B0/P0'

    $source = $null
    $destination = $null
    try {
        $source = [System.IO.FileStream]::new(
            $backup,
            [System.IO.FileMode]::Open,
            [System.IO.FileAccess]::Read,
            [System.IO.FileShare]::None)
        $destination = [System.IO.FileStream]::new(
            $canonical,
            [System.IO.FileMode]::Open,
            [System.IO.FileAccess]::ReadWrite,
            [System.IO.FileShare]::None)
        if ((Get-UID0002PAStreamSha256 -Stream $source) -cne $ExpectedP0.SHA256 -or
            $source.Length -ne $ExpectedP0.Length) { throw 'exclusive B0/P0 drift' }
        if ((Get-UID0002PAStreamSha256 -Stream $destination) -cne $ExpectedAttemptOwnedS1.SHA256 -or
            $destination.Length -ne $ExpectedAttemptOwnedS1.Length) { throw 'exclusive S1/F1 drift or third identity' }

        $source.Position = 0
        $destination.SetLength(0)
        $destination.Position = 0
        $buffer = New-Object byte[] 1048576
        $copied = [long]0
        while (($read = $source.Read($buffer, 0, $buffer.Length)) -gt 0) {
            $destination.Write($buffer, 0, $read)
            $copied += $read
        }
        if ($copied -ne $ExpectedP0.Length -or $source.Position -ne $ExpectedP0.Length) {
            throw 'restore source EOF/copy-count mismatch'
        }
        if ($destination.Length -ne $ExpectedP0.Length) { throw 'restored destination length mismatch' }
        $destination.Flush($true)
    }
    finally {
        if ($null -ne $destination) { $destination.Dispose() }
        if ($null -ne $source) { $source.Dispose() }
    }

    [System.IO.File]::SetLastWriteTimeUtc(
        $canonical,
        [DateTime]::new([long]$ExpectedP0.LastWriteTimeUtcTicks, [DateTimeKind]::Utc))
    Assert-UID0002PATuple -Actual (Get-UID0002PAExclusiveTuple -Path $canonical) -Expected $ExpectedP0 -Label 'closed restored P0'
    Assert-UID0002PATuple -Actual (Get-UID0002PAExclusiveTuple -Path $canonical) -Expected $ExpectedP0 -Label 'exclusive-reopen restored P0'
    Assert-UID0002PATuple -Actual (Get-UID0002PAExclusiveTuple -Path $backup) -Expected $ExpectedP0 -Label 'post-restore B0/P0'
}
~~~

## Removed Block R002

- SHA256: `1D45CE1B1F015758C5B732A849C41F2BFA64E40E1306C1BE826B58C098F36FC3`
- Language: `powershell`
- Bytes: `4850`
- First recovered timestamp: `2026-08-06T22:50:42.103Z`
- Session provenance: rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 193838 (2026-08-06T22:50:42.103Z); rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 193839 (2026-08-06T22:50:42.156Z); rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 194095 (2026-08-06T23:28:40.609Z)

~~~powershell
function Assert-UID0002PALoadedModuleAttestation {
    param(
        [Parameter(Mandatory=$true)]$Envelope,
        [Parameter(Mandatory=$true)][ValidateSet('listener','database')][string]$Scope,
        [Parameter(Mandatory=$true)]$ExpectedProcess,
        [Parameter(Mandatory=$true)]$ListenerRoute)

    if ($null -eq $Envelope.result -or $Envelope.result.isError -eq $true -or $null -eq $Envelope.result.structuredContent) {
        throw 'LM-PA missing/error structuredContent envelope'
    }
    $attestation = $Envelope.result.structuredContent
    if ([string]$attestation.attestation_version -ne '1' -or
        [string]$attestation.mode -ne 'already_loaded_only' -or
        [bool]$attestation.imports_performed -ne $false -or
        [string]$attestation.scope -ne $Scope) { throw 'LM-PA attestation mode/version/scope mismatch' }
    foreach ($field in 'pid','parent_pid','creation_time_utc','start_time_utc','executable_path','command_line') {
        if ($null -eq $attestation.process.PSObject.Properties[$field]) { throw "LM-PA missing process field $field" }
    }
    if ([int]$attestation.process.pid -ne $ExpectedProcess.ProcessId -or
        [int]$attestation.process.parent_pid -ne $ExpectedProcess.ParentProcessId -or
        [string]$attestation.process.creation_time_utc -cne $ExpectedProcess.CimCreationTimeUtc -or
        [string]$attestation.process.start_time_utc -cne $ExpectedProcess.ProcessStartTimeUtc -or
        [System.IO.Path]::GetFullPath([string]$attestation.process.executable_path) -ine $ExpectedProcess.ExecutablePath -or
        [string]$attestation.process.command_line -cne $ExpectedProcess.CommandLine -or
        [System.IO.Path]::GetFullPath([string]$attestation.sys_executable) -ine $ListenerRoute.BasePython -or
        [System.IO.Path]::GetFullPath([string]$attestation.sys_prefix) -ine $ListenerRoute.VenvRoot -or
        [System.IO.Path]::GetFullPath([string]$attestation.package_root) -ine $ListenerRoute.SourceRoot) {
        throw 'LM-PA in-process route/prefix/root mismatch'
    }

    $manifest = @{
        'ida_pro_mcp.idalib_supervisor' = @{ path="$($ListenerRoute.SourceRoot)\idalib_supervisor.py"; bytes=52468; sha='2D7098B6BDB58D7DCF8CF4825BBE7584F5E7ACB256AD318B05482E9A0B9AF10A' }
        'ida_pro_mcp.idalib_session_manager' = @{ path="$($ListenerRoute.SourceRoot)\idalib_session_manager.py"; bytes=7032; sha='9EDEEBD47B6FF85F9809E7159CE03D3EF41833692D28AC4367C6C4E5CAE00890' }
        'ida_pro_mcp.idalib_server' = @{ path="$($ListenerRoute.SourceRoot)\idalib_server.py"; bytes=9848; sha='06C922EEF3F2E6771308C687231FE443A65DADF340E72001C6B05B7FC70B2034' }
        'ida_pro_mcp.ida_mcp.api_modify' = @{ path="$($ListenerRoute.SourceRoot)\ida_mcp\api_modify.py"; bytes=51759; sha='161B314A14DAAA34C718176444292597BBB7498FA80158E25C358542BC16D1B8' }
        'ida_pro_mcp.ida_mcp.api_types' = @{ path="$($ListenerRoute.SourceRoot)\ida_mcp\api_types.py"; bytes=37540; sha='A3E7444BBAC0066B48EDF38E26F34E6ABEC823585CD50E43C6DA98C55B965ECF' }
        'ida_pro_mcp.ida_mcp.api_core' = @{ path="$($ListenerRoute.SourceRoot)\ida_mcp\api_core.py"; bytes=34004; sha='90C59B3F64F26E170CC604000CE39B34B648352767059DD1C2DF1914E9CBD4A3' }
        'ida_pro_mcp.ida_mcp.utils' = @{ path="$($ListenerRoute.SourceRoot)\ida_mcp\utils.py"; bytes=43500; sha='5139910EA7496549A31EDD6F9EEE7B033DA16504E4F0D19C8052EC9ED1C62069' }
    }
    $expectedNames = if ($Scope -eq 'listener') {
        @('ida_pro_mcp.idalib_supervisor','ida_pro_mcp.idalib_session_manager')
    } else {
        @('ida_pro_mcp.idalib_server','ida_pro_mcp.ida_mcp.api_modify','ida_pro_mcp.ida_mcp.api_types','ida_pro_mcp.ida_mcp.api_core','ida_pro_mcp.ida_mcp.utils')
    }
    $rows = @($attestation.modules)
    if ($rows.Count -ne $expectedNames.Count) { throw 'LM-PA module count mismatch' }
    foreach ($name in $expectedNames) {
        $matches = @($rows | Where-Object { [string]$_.name -ceq $name })
        if ($matches.Count -ne 1) { throw "LM-PA missing/duplicate loaded module $name" }
        $row = $matches[0]
        $expected = $manifest[$name]
        $file = [System.IO.Path]::GetFullPath([string]$row.file)
        $origin = [System.IO.Path]::GetFullPath([string]$row.origin)
        if ([bool]$row.already_loaded -ne $true -or [long]$row.object_id -le 0 -or
            $file -ine $origin -or $file -ine [System.IO.Path]::GetFullPath([string]$expected.path)) {
            throw "LM-PA loaded-object/path mismatch for $name"
        }
        $item = Get-Item -LiteralPath $file -ErrorAction Stop
        $hash = (Get-FileHash -LiteralPath $file -Algorithm SHA256 -ErrorAction Stop).Hash
        if ([long]$item.Length -ne [long]$expected.bytes -or $hash -cne [string]$expected.sha) {
            throw "LM-PA physical identity mismatch for $name"
        }
    }
    return $attestation
}
~~~

## Removed Block R003

- SHA256: `66607BA9C014DB50BEBA5628B7D70B3A73E7112686173F281E790115366E97B6`
- Language: `powershell`
- Bytes: `6743`
- First recovered timestamp: `2026-08-06T22:50:42.103Z`
- Session provenance: rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 193838 (2026-08-06T22:50:42.103Z)

~~~powershell
function Get-UID0002PAExactProcess {
    param(
        [Parameter(Mandatory=$true)][int]$ProcessId,
        [Parameter(Mandatory=$true)][string]$Role)

    $cimRows = @(Get-CimInstance Win32_Process -Filter "ProcessId=$ProcessId" -ErrorAction Stop)
    if ($cimRows.Count -ne 1) { throw "$Role requires exactly one CIM process row" }
    $processRows = @(Get-Process -Id $ProcessId -ErrorAction Stop)
    if ($processRows.Count -ne 1) { throw "$Role requires exactly one process row" }
    $cim = $cimRows[0]
    $process = $processRows[0]
    if ([string]::IsNullOrWhiteSpace([string]$cim.ExecutablePath) -or
        [string]::IsNullOrWhiteSpace([string]$cim.CommandLine)) {
        throw "$Role has incomplete executable/command identity"
    }
    return [pscustomobject][ordered]@{
        Role = $Role
        ProcessId = [int]$cim.ProcessId
        ParentProcessId = [int]$cim.ParentProcessId
        CimCreationTimeUtc = ([datetime]$cim.CreationDate).ToUniversalTime().ToString('o')
        ProcessStartTimeUtc = $process.StartTime.ToUniversalTime().ToString('o')
        ExecutablePath = [System.IO.Path]::GetFullPath([string]$cim.ExecutablePath)
        CommandLine = [string]$cim.CommandLine
    }
}

function Get-UID0002PAListenerRoute {
    $venvRoot = [System.IO.Path]::GetFullPath('C:\Users\admin\.idapro\idalib-mcp-venv')
    $launcher = [System.IO.Path]::GetFullPath("$venvRoot\Scripts\idalib-mcp.exe")
    $venvPython = [System.IO.Path]::GetFullPath("$venvRoot\Scripts\python.exe")
    $pyvenv = [System.IO.Path]::GetFullPath("$venvRoot\pyvenv.cfg")
    $homeRows = @(Get-Content -LiteralPath $pyvenv -ErrorAction Stop | Where-Object { $_ -match '^\s*home\s*=\s*(.+?)\s*$' })
    if ($homeRows.Count -ne 1) { throw 'LR-PA cannot resolve exactly one pyvenv home' }
    $baseHome = [regex]::Match($homeRows[0], '^\s*home\s*=\s*(.+?)\s*$').Groups[1].Value
    $basePython = [System.IO.Path]::GetFullPath((Join-Path $baseHome 'python.exe'))
    $sourceRoot = [System.IO.Path]::GetFullPath("$venvRoot\Lib\site-packages\ida_pro_mcp")

    $listenerRows = @(Get-NetTCPConnection -LocalAddress '127.0.0.1' -LocalPort 13337 -State Listen -ErrorAction Stop)
    if ($listenerRows.Count -ne 1) { throw "LR-PA requires one 127.0.0.1:13337 listener; observed $($listenerRows.Count)" }
    $L2 = Get-UID0002PAExactProcess -ProcessId ([int]$listenerRows[0].OwningProcess) -Role 'L2 base Python socket owner'
    $L1 = Get-UID0002PAExactProcess -ProcessId $L2.ParentProcessId -Role 'L1 venv Python child'
    $L0 = Get-UID0002PAExactProcess -ProcessId $L1.ParentProcessId -Role 'L0 idalib-mcp root'

    if ($L0.ExecutablePath -ine $launcher -or $L1.ExecutablePath -ine $venvPython -or $L2.ExecutablePath -ine $basePython) {
        throw 'LR-PA executable route mismatch'
    }
    if ($L1.ParentProcessId -ne $L0.ProcessId -or $L2.ParentProcessId -ne $L1.ProcessId) {
        throw 'LR-PA parent-edge mismatch'
    }
    if ($L0.CommandLine -notlike "*$launcher*" -or
        $L1.CommandLine -notlike "*$venvPython*" -or $L1.CommandLine -notlike "*$launcher*" -or
        $L2.CommandLine -notlike "*$venvPython*" -or $L2.CommandLine -notlike "*$launcher*" -or
        $L0.CommandLine -notmatch '(?i)--host\s+127\.0\.0\.1' -or $L0.CommandLine -notmatch '(?i)--port\s+13337' -or
        $L1.CommandLine -notmatch '(?i)--host\s+127\.0\.0\.1' -or $L1.CommandLine -notmatch '(?i)--port\s+13337' -or
        $L2.CommandLine -notmatch '(?i)--host\s+127\.0\.0\.1' -or $L2.CommandLine -notmatch '(?i)--port\s+13337') {
        throw 'LR-PA complete command-line route mismatch'
    }

    $routePids = @($L0.ProcessId,$L1.ProcessId,$L2.ProcessId)
    $routeSockets = @(Get-NetTCPConnection -State Listen -ErrorAction Stop | Where-Object { $routePids -contains [int]$_.OwningProcess })
    if ($routeSockets.Count -ne 1 -or [int]$routeSockets[0].OwningProcess -ne $L2.ProcessId -or
        [string]$routeSockets[0].LocalAddress -ne '127.0.0.1' -or [int]$routeSockets[0].LocalPort -ne 13337) {
        throw 'LR-PA L2 is not the sole route listener'
    }
    return [pscustomobject][ordered]@{
        L0 = $L0
        L1 = $L1
        L2 = $L2
        Socket = [pscustomobject][ordered]@{ LocalAddress='127.0.0.1'; LocalPort=13337; OwningProcess=$L2.ProcessId }
        VenvRoot = $venvRoot
        VenvPython = $venvPython
        BasePython = $basePython
        SourceRoot = $sourceRoot
    }
}

function Assert-UID0002PAListenerRoute {
    param([Parameter(Mandatory=$true)]$Expected)
    $actual = Get-UID0002PAListenerRoute
    $expectedJson = $Expected | ConvertTo-Json -Depth 12 -Compress
    $actualJson = $actual | ConvertTo-Json -Depth 12 -Compress
    if ($actualJson -cne $expectedJson) { throw 'LR-PA listener route/process generation drift' }
    return $actual
}

function Get-UID0002PAWorkerRoute {
    param(
        [Parameter(Mandatory=$true)]$ListenerRoute,
        [Parameter(Mandatory=$true)][int]$ReturnedWorkerPid)

    $W0 = Get-UID0002PAExactProcess -ProcessId $ReturnedWorkerPid -Role 'W0 returned venv worker'
    if ($W0.ParentProcessId -ne $ListenerRoute.L2.ProcessId -or $W0.ExecutablePath -ine $ListenerRoute.VenvPython -or
        $W0.CommandLine -notmatch '(?i)-m\s+ida_pro_mcp\.idalib_server' -or
        $W0.CommandLine -notmatch '(?i)--host\s+127\.0\.0\.1' -or
        $W0.CommandLine -notmatch '(?i)--port\s+(\d+)') {
        throw 'worker W0 route/command mismatch'
    }
    $workerPort = [int][regex]::Match($W0.CommandLine, '(?i)--port\s+(\d+)').Groups[1].Value
    if ($workerPort -le 0) { throw 'worker port is unresolved' }
    $children = @(Get-CimInstance Win32_Process -Filter "ParentProcessId=$($W0.ProcessId)" -ErrorAction Stop)
    if ($children.Count -ne 1) { throw 'worker route requires exactly one W1 child' }
    $W1 = Get-UID0002PAExactProcess -ProcessId ([int]$children[0].ProcessId) -Role 'W1 base Python worker socket owner'
    if ($W1.ParentProcessId -ne $W0.ProcessId -or $W1.ExecutablePath -ine $ListenerRoute.BasePython -or
        $W1.CommandLine -cne $W0.CommandLine) { throw 'worker W1 route/command mismatch' }
    $workerPids = @($W0.ProcessId,$W1.ProcessId)
    $sockets = @(Get-NetTCPConnection -State Listen -ErrorAction Stop | Where-Object { $workerPids -contains [int]$_.OwningProcess })
    if ($sockets.Count -ne 1 -or [int]$sockets[0].OwningProcess -ne $W1.ProcessId -or
        [string]$sockets[0].LocalAddress -ne '127.0.0.1' -or [int]$sockets[0].LocalPort -ne $workerPort) {
        throw 'worker W1 is not the sole worker socket owner'
    }
    return [pscustomobject][ordered]@{
        W0 = $W0
        W1 = $W1
        Socket = [pscustomobject][ordered]@{ LocalAddress='127.0.0.1'; LocalPort=$workerPort; OwningProcess=$W1.ProcessId }
    }
}
~~~

## Removed Block R004

- SHA256: `F8DB551F278E5D57521A01D811187A89EEF5F8F80EFABD6624332BECE0F94D9A`
- Language: `powershell`
- Bytes: `3712`
- First recovered timestamp: `2026-08-06T22:50:42.103Z`
- Session provenance: rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 193838 (2026-08-06T22:50:42.103Z); rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 193839 (2026-08-06T22:50:42.156Z)

~~~powershell
function New-UID0002PARoleBinding {
    param(
        [Parameter(Mandatory=$true)][string]$Role,
        [Parameter(Mandatory=$true)][string]$PreferredSessionId,
        [Parameter(Mandatory=$true)]$OpenEnvelope,
        [Parameter(Mandatory=$true)]$ListEnvelope,
        [Parameter(Mandatory=$true)]$ListenerRoute)

    $canonical = [System.IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64')
    if ($null -eq $OpenEnvelope.result -or $OpenEnvelope.result.isError -eq $true -or
        $null -eq $OpenEnvelope.result.structuredContent) { throw "$Role idb_open envelope missing/error" }
    $open = $OpenEnvelope.result.structuredContent
    if ($open.success -ne $true -or -not [string]::IsNullOrWhiteSpace([string]$open.error)) {
        throw "$Role idb_open did not return exact success"
    }
    $sessions = @($open.session)
    if ($sessions.Count -ne 1) { throw "$Role idb_open must return exactly one session object" }
    $session = $sessions[0]
    $databaseReturnedByIdbOpen = [string]$session.session_id
    if ([string]::IsNullOrWhiteSpace($databaseReturnedByIdbOpen) -or
        [System.IO.Path]::GetFullPath([string]$session.input_path) -ine $canonical -or
        $session.is_analyzing -eq $true) { throw "$Role returned session identity/path/state mismatch" }

    if ($null -eq $ListEnvelope.result -or $ListEnvelope.result.isError -eq $true -or
        $null -eq $ListEnvelope.result.structuredContent) { throw "$Role idb_list envelope missing/error" }
    $list = $ListEnvelope.result.structuredContent
    $matches = @($list.sessions | Where-Object {
        [string]$_.session_id -ceq $databaseReturnedByIdbOpen -and
        [System.IO.Path]::GetFullPath([string]$_.input_path) -ieq $canonical -and
        $_.is_active -eq $true
    })
    if ($matches.Count -ne 1 -or [int]$matches[0].worker_pid -le 0) {
        throw "$Role idb_list does not uniquely corroborate returned session/path/worker"
    }
    $workerRoute = Get-UID0002PAWorkerRoute -ListenerRoute $ListenerRoute -ReturnedWorkerPid ([int]$matches[0].worker_pid)
    return [pscustomobject][ordered]@{
        Role = $Role
        PreferredSessionId = $PreferredSessionId
        Database = $databaseReturnedByIdbOpen
        CanonicalPath = $canonical
        WorkerPid = [int]$matches[0].worker_pid
        WorkerRoute = $workerRoute
    }
}

function Resolve-UID0002PADatabaseTemplate {
    param(
        [Parameter(Mandatory=$true)][string]$TemplateJson,
        [Parameter(Mandatory=$true)]$RoleBinding)

    $token = '__DATABASE_RETURNED_BY_IDB_OPEN__'
    $quotedToken = '"' + $token + '"'
    $count = ([regex]::Matches($TemplateJson, [regex]::Escape($quotedToken))).Count
    if ($count -le 0) { throw 'DB-PA template has no exact returned-database token' }
    if ([string]::IsNullOrWhiteSpace([string]$RoleBinding.Database)) { throw 'DB-PA role database is unresolved' }
    $quotedDatabase = ConvertTo-Json -InputObject ([string]$RoleBinding.Database) -Compress
    $resolved = $TemplateJson.Replace($quotedToken, $quotedDatabase)
    if ($resolved.Contains($token) -or $resolved -match '__[A-Z0-9_]+__|<[^>]+>') {
        throw 'DB-PA unresolved placeholder remains after substitution'
    }
    $null = $resolved | ConvertFrom-Json -ErrorAction Stop
    $databaseMatches = [regex]::Matches($resolved, '"database"\s*:\s*"([^"]+)"')
    if ($databaseMatches.Count -ne $count) { throw 'DB-PA database-field count changed during substitution' }
    foreach ($match in $databaseMatches) {
        if ([string]$match.Groups[1].Value -cne [string]$RoleBinding.Database) {
            throw 'DB-PA request contains a non-returned database value'
        }
    }
    return $resolved
}
~~~

## Removed Block R005

- SHA256: `733B8F1B45B44549BB06FAC6A4D3F33BC47FA460D5F49BBA18F0B29AE029D8CB`
- Language: `powershell`
- Bytes: `1770`
- First recovered timestamp: `2026-08-06T23:28:40.609Z`
- Session provenance: rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 194095 (2026-08-06T23:28:40.609Z)

~~~powershell
function Get-UID0002PAStructuredContent {
    param([Parameter(Mandatory=$true)]$Envelope,[Parameter(Mandatory=$true)][string]$Label)
    if ($null -eq $Envelope.result -or $Envelope.result.isError -eq $true -or
        $null -eq $Envelope.result.structuredContent) { throw "$Label missing/error structuredContent" }
    return $Envelope.result.structuredContent
}

function Assert-UID0002PAToolsList {
    param([Parameter(Mandatory=$true)]$Envelope)
    if ($null -eq $Envelope.result -or $null -eq $Envelope.result.tools) { throw 'S-PA tools/list result missing' }
    $tools = @($Envelope.result.tools)
    if ($tools.Count -ne 72) { throw "S-PA tool-count drift: $($tools.Count)" }
    $public = @($tools | Where-Object { [string]$_.name -ceq 'runtime_attestation' })
    $internal = @($tools | Where-Object { [string]$_.name -ceq 'runtime/attest' })
    if ($public.Count -ne 1 -or $internal.Count -ne 0) { throw 'S-PA runtime tool exposure mismatch' }
    $properties = @($public[0].inputSchema.properties.PSObject.Properties.Name | Sort-Object)
    if (($properties -join '|') -cne 'expected_canonical_path|expected_database' -or
        @($public[0].inputSchema.required).Count -ne 0) { throw 'S-PA runtime_attestation schema mismatch' }
    foreach ($name in 'idb_open','idb_list','runtime_attestation','analyze_function','stack_frame',
        'xref_query','callees','get_comments','inspect_items','get_bytes','type_query','type_inspect',
        'entity_query','declare_type','rename','set_type','set_function_comments','set_address_comments','idb_save') {
        if (@($tools | Where-Object { [string]$_.name -ceq $name }).Count -ne 1) {
            throw "S-PA missing/duplicate required tool: $name"
        }
    }
    return $tools
}
~~~

## Removed Block R006

- SHA256: `77C8F7695F478F3C261D6B79F1423C520960D49B092DAFE584A6464131CFF1E0`
- Language: `powershell`
- Bytes: `9187`
- First recovered timestamp: `2026-08-06T23:28:40.609Z`
- Session provenance: rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 194095 (2026-08-06T23:28:40.609Z)

~~~powershell
function Assert-UID0002PAModuleManifest {
    param(
        [Parameter(Mandatory=$true)]$Runtime,
        [Parameter(Mandatory=$true)][string]$ExpectedSourceRoot,
        [Parameter(Mandatory=$true)][int]$ExpectedCount,
        [Parameter(Mandatory=$true)][string]$ExpectedManifest,
        [Parameter(Mandatory=$true)][string[]]$RequiredNames,
        [Parameter(Mandatory=$true)][string]$Label)

    $root = [System.IO.Path]::GetFullPath($ExpectedSourceRoot).TrimEnd('\')
    if ([System.IO.Path]::GetFullPath([string]$Runtime.source_root).TrimEnd('\') -ine $root -or
        [string]$Runtime.implementation_manifest_sha256 -cne $ExpectedManifest) {
        throw "$Label source-root/manifest mismatch"
    }
    $rows = @($Runtime.modules)
    if ($rows.Count -ne $ExpectedCount) { throw "$Label complete module count mismatch" }
    $names = @($rows | ForEach-Object { [string]$_.sys_modules_name })
    if (@($names | Sort-Object -Unique).Count -ne $rows.Count) { throw "$Label duplicate module names" }
    foreach ($required in $RequiredNames) {
        if (@($rows | Where-Object { [string]$_.sys_modules_name -ceq $required }).Count -ne 1) {
            throw "$Label missing required loaded module $required"
        }
    }
    foreach ($row in $rows) {
        $file = [System.IO.Path]::GetFullPath([string]$row.file)
        $origin = [System.IO.Path]::GetFullPath([string]$row.spec_origin)
        $resolved = [System.IO.Path]::GetFullPath([string]$row.resolved_path)
        if ([string]$row.module_id -notmatch '^0x[0-9a-f]+$' -or $file -ine $origin -or $file -ine $resolved -or
            -not ($file -ieq $root -or $file.StartsWith($root + '\',[System.StringComparison]::OrdinalIgnoreCase)) -or
            [long]$row.size -lt 0 -or [long]$row.mtime_ns -le 0 -or [long]$row.ctime_ns -le 0 -or
            [string]$row.sha256 -notmatch '^[0-9A-F]{64}$') { throw "$Label invalid module row $($row.sys_modules_name)" }
        $item = Get-Item -LiteralPath $file -ErrorAction Stop
        if ([long]$item.Length -ne [long]$row.size -or
            (Get-FileHash -LiteralPath $file -Algorithm SHA256 -ErrorAction Stop).Hash -cne [string]$row.sha256) {
            throw "$Label physical module drift $($row.sys_modules_name)"
        }
    }
}

function Assert-UID0002PARuntimeAttestation {
    param(
        [Parameter(Mandatory=$true)]$Envelope,
        [Parameter(Mandatory=$true)]$ListEnvelope,
        [Parameter(Mandatory=$true)]$ListenerRoute,
        $RoleBinding,
        [Parameter(Mandatory=$true)][System.Collections.Generic.HashSet[string]]$SeenNonces)

    $a = Get-UID0002PAStructuredContent -Envelope $Envelope -Label 'RA-PA'
    $list = Get-UID0002PAStructuredContent -Envelope $ListEnvelope -Label 'RA-PA idb_list'
    if ([int]$a.schema_version -ne 1 -or $a.ok -ne $true -or @($a.errors).Count -ne 0 -or $null -eq $a.listener) {
        throw 'RA-PA top-level schema/status/errors mismatch'
    }
    $listener = $a.listener
    if ([string]$listener.role -cne 'supervisor_listener' -or [string]$listener.nonce -notmatch '^[0-9a-f]{32}$' -or
        -not $SeenNonces.Add([string]$listener.nonce) -or [string]$listener.endpoint.host -cne '127.0.0.1' -or
        [int]$listener.endpoint.port -ne 13337 -or [int]$listener.process.pid -ne $ListenerRoute.L2.ProcessId -or
        [int]$listener.process.parent_pid -ne $ListenerRoute.L1.ProcessId -or
        [string]$listener.process.creation_time_100ns -cne $ListenerRoute.L2.ProcessCreationTime100ns -or
        [string]$listener.process.generation -cne "pid:$($ListenerRoute.L2.ProcessId);created:$($ListenerRoute.L2.ProcessCreationTime100ns)" -or
        [System.IO.Path]::GetFullPath([string]$listener.process.sys_executable) -ine $ListenerRoute.VenvPython -or
        [System.IO.Path]::GetFullPath([string]$listener.process.process_image) -ine $ListenerRoute.VenvPython) {
        throw 'RA-PA listener nonce/process generation mismatch'
    }
    $portRows = @(Get-NetTCPConnection -LocalAddress '127.0.0.1' -LocalPort 13337 -State Listen -ErrorAction Stop)
    if ($portRows.Count -ne 1 -or [int]$portRows[0].OwningProcess -ne $ListenerRoute.L2.ProcessId) {
        throw 'RA-PA independent listener port-owner mismatch'
    }
    Assert-UID0002PAModuleManifest -Runtime $listener -ExpectedSourceRoot $ListenerRoute.SourceRoot -ExpectedCount 6 `
        -ExpectedManifest 'D3C792133956B855EBA751FDB5783B2D7177FA204134CFF1D897E0D0770FB7CE' `
        -RequiredNames @('ida_pro_mcp.idalib_supervisor','ida_pro_mcp.runtime_attestation') -Label 'listener'

    $active = @($list.sessions | Where-Object { $_.is_active -eq $true })
    $attestedSessionRows = @($a.workers | ForEach-Object { @($_.supervisor_sessions) })
    if ($attestedSessionRows.Count -ne $active.Count) { throw 'RA-PA active/attested session count mismatch' }
    foreach ($session in $active) {
        $matches = @($attestedSessionRows | Where-Object { [string]$_.session_id -ceq [string]$session.session_id })
        if ($matches.Count -ne 1 -or [string]$matches[0].backend -cne 'worker' -or $matches[0].owned -ne $true -or
            [int]$matches[0].redirector_pid -ne [int]$session.worker_pid -or
            [System.IO.Path]::GetFullPath([string]$matches[0].canonical_path) -ine [System.IO.Path]::GetFullPath([string]$session.input_path)) {
            throw "RA-PA session route mismatch $($session.session_id)"
        }
    }

    foreach ($entry in @($a.workers)) {
        $wa = $entry.attestation
        if ([int]$wa.schema_version -ne 1 -or $wa.ok -ne $true -or @($wa.errors).Count -ne 0 -or
            $null -eq $wa.worker -or [string]$wa.worker.role -cne 'stateful_worker' -or
            [string]$wa.worker.nonce -notmatch '^[0-9a-f]{32}$' -or -not $SeenNonces.Add([string]$wa.worker.nonce) -or
            [string]$entry.route.host -cne [string]$wa.worker.endpoint.host -or
            [int]$entry.route.port -ne [int]$wa.worker.endpoint.port) { throw 'RA-PA worker schema/status/nonce/endpoint mismatch' }
        $supervisorRows = @($entry.supervisor_sessions)
        if ($supervisorRows.Count -ne 1) { throw 'RA-PA shared/missing worker session route' }
        $supervisorRow = $supervisorRows[0]
        $redirector = Get-UID0002PAExactProcess -ProcessId ([int]$supervisorRow.redirector_pid) -Role 'RA-PA worker redirector'
        $worker = Get-UID0002PAExactProcess -ProcessId ([int]$wa.worker.process.pid) -Role 'RA-PA socket worker'
        if ($redirector.ParentProcessId -ne $ListenerRoute.L2.ProcessId -or $worker.ParentProcessId -ne $redirector.ProcessId -or
            [string]$wa.worker.process.creation_time_100ns -cne $worker.ProcessCreationTime100ns -or
            [string]$wa.worker.process.generation -cne "pid:$($worker.ProcessId);created:$($worker.ProcessCreationTime100ns)" -or
            [System.IO.Path]::GetFullPath([string]$wa.worker.process.sys_executable) -ine $ListenerRoute.VenvPython -or
            [System.IO.Path]::GetFullPath([string]$wa.worker.process.process_image) -ine $ListenerRoute.VenvPython) {
            throw 'RA-PA redirector/worker process-generation mismatch'
        }
        $workerSockets = @(Get-NetTCPConnection -LocalAddress '127.0.0.1' -LocalPort ([int]$entry.route.port) -State Listen -ErrorAction Stop)
        if ($workerSockets.Count -ne 1 -or [int]$workerSockets[0].OwningProcess -ne $worker.ProcessId) {
            throw 'RA-PA worker socket-owner mismatch'
        }
        Assert-UID0002PAModuleManifest -Runtime $wa.worker -ExpectedSourceRoot $ListenerRoute.SourceRoot -ExpectedCount 30 `
            -ExpectedManifest '849203D42ABFC99176069E7069F039E9B50AC1A0F392BECB4D7C90CC7AE627D4' `
            -RequiredNames @('ida_pro_mcp.idalib_server','ida_pro_mcp.runtime_attestation','ida_pro_mcp.ida_mcp.api_modify','ida_pro_mcp.ida_mcp.api_types','ida_pro_mcp.ida_mcp.api_core','ida_pro_mcp.ida_mcp.utils') -Label 'worker'
        $workerSessions = @($wa.sessions)
        if ($workerSessions.Count -ne 1 -or [string]$workerSessions[0].session_id -cne [string]$supervisorRow.session_id -or
            [System.IO.Path]::GetFullPath([string]$workerSessions[0].canonical_path) -ine [System.IO.Path]::GetFullPath([string]$supervisorRow.canonical_path)) {
            throw 'RA-PA worker internal session/path mismatch'
        }
    }
    if ($null -ne $RoleBinding) {
        $roleRows = @($attestedSessionRows | Where-Object { [string]$_.session_id -ceq [string]$RoleBinding.Database })
        if ($roleRows.Count -ne 1 -or
            [System.IO.Path]::GetFullPath([string]$roleRows[0].canonical_path) -ine [System.IO.Path]::GetFullPath([string]$RoleBinding.CanonicalPath)) {
            throw 'RA-PA expected returned database/path absent or duplicated'
        }
    }
    return [pscustomobject]@{
        ListenerGeneration = [string]$listener.process.generation
        ListenerNonce = [string]$listener.nonce
        ActiveDatabases = @($attestedSessionRows | ForEach-Object { [string]$_.session_id })
        WorkerGenerations = @($a.workers | ForEach-Object { [string]$_.attestation.worker.process.generation })
        WorkerNonces = @($a.workers | ForEach-Object { [string]$_.attestation.worker.nonce })
    }
}
~~~

## Removed Block R007

- SHA256: `5370F7752B9A136F183AFEFA1B2A5EE49BD7E68C3A41A8D40D7204AB5205DFD7`
- Language: `powershell`
- Bytes: `6842`
- First recovered timestamp: `2026-08-06T23:37:00.336Z`
- Session provenance: rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 194253 (2026-08-06T23:37:00.336Z)

~~~powershell
function Get-UID0002PAExactProcess {
    param(
        [Parameter(Mandatory=$true)][int]$ProcessId,
        [Parameter(Mandatory=$true)][string]$Role)

    $cimRows = @(Get-CimInstance Win32_Process -Filter "ProcessId=$ProcessId" -ErrorAction Stop)
    if ($cimRows.Count -ne 1) { throw "$Role requires exactly one CIM process row" }
    $processRows = @(Get-Process -Id $ProcessId -ErrorAction Stop)
    if ($processRows.Count -ne 1) { throw "$Role requires exactly one process row" }
    $cim = $cimRows[0]
    $process = $processRows[0]
    if ([string]::IsNullOrWhiteSpace([string]$cim.ExecutablePath) -or
        [string]::IsNullOrWhiteSpace([string]$cim.CommandLine)) {
        throw "$Role has incomplete executable/command identity"
    }
    return [pscustomobject][ordered]@{
        Role = $Role
        ProcessId = [int]$cim.ProcessId
        ParentProcessId = [int]$cim.ParentProcessId
        CimCreationTimeUtc = ([datetime]$cim.CreationDate).ToUniversalTime().ToString('o')
        ProcessStartTimeUtc = $process.StartTime.ToUniversalTime().ToString('o')
        ProcessCreationTime100ns = $process.StartTime.ToUniversalTime().ToFileTimeUtc().ToString()
        ExecutablePath = [System.IO.Path]::GetFullPath([string]$cim.ExecutablePath)
        CommandLine = [string]$cim.CommandLine
    }
}

function Get-UID0002PAListenerRoute {
    $venvRoot = [System.IO.Path]::GetFullPath('C:\Users\admin\.idapro\idalib-mcp-venv')
    $launcher = [System.IO.Path]::GetFullPath("$venvRoot\Scripts\idalib-mcp.exe")
    $venvPython = [System.IO.Path]::GetFullPath("$venvRoot\Scripts\python.exe")
    $pyvenv = [System.IO.Path]::GetFullPath("$venvRoot\pyvenv.cfg")
    $homeRows = @(Get-Content -LiteralPath $pyvenv -ErrorAction Stop | Where-Object { $_ -match '^\s*home\s*=\s*(.+?)\s*$' })
    if ($homeRows.Count -ne 1) { throw 'LR-PA cannot resolve exactly one pyvenv home' }
    $baseHome = [regex]::Match($homeRows[0], '^\s*home\s*=\s*(.+?)\s*$').Groups[1].Value
    $basePython = [System.IO.Path]::GetFullPath((Join-Path $baseHome 'python.exe'))
    $sourceRoot = [System.IO.Path]::GetFullPath("$venvRoot\Lib\site-packages\ida_pro_mcp")

    $listenerRows = @(Get-NetTCPConnection -LocalAddress '127.0.0.1' -LocalPort 13337 -State Listen -ErrorAction Stop)
    if ($listenerRows.Count -ne 1) { throw "LR-PA requires one 127.0.0.1:13337 listener; observed $($listenerRows.Count)" }
    $L2 = Get-UID0002PAExactProcess -ProcessId ([int]$listenerRows[0].OwningProcess) -Role 'L2 base Python socket owner'
    $L1 = Get-UID0002PAExactProcess -ProcessId $L2.ParentProcessId -Role 'L1 venv Python child'
    $L0 = Get-UID0002PAExactProcess -ProcessId $L1.ParentProcessId -Role 'L0 idalib-mcp root'

    if ($L0.ExecutablePath -ine $launcher -or $L1.ExecutablePath -ine $venvPython -or $L2.ExecutablePath -ine $basePython) {
        throw 'LR-PA executable route mismatch'
    }
    if ($L1.ParentProcessId -ne $L0.ProcessId -or $L2.ParentProcessId -ne $L1.ProcessId) {
        throw 'LR-PA parent-edge mismatch'
    }
    if ($L0.CommandLine -notlike "*$launcher*" -or
        $L1.CommandLine -notlike "*$venvPython*" -or $L1.CommandLine -notlike "*$launcher*" -or
        $L2.CommandLine -notlike "*$venvPython*" -or $L2.CommandLine -notlike "*$launcher*" -or
        $L0.CommandLine -notmatch '(?i)--host\s+127\.0\.0\.1' -or $L0.CommandLine -notmatch '(?i)--port\s+13337' -or
        $L1.CommandLine -notmatch '(?i)--host\s+127\.0\.0\.1' -or $L1.CommandLine -notmatch '(?i)--port\s+13337' -or
        $L2.CommandLine -notmatch '(?i)--host\s+127\.0\.0\.1' -or $L2.CommandLine -notmatch '(?i)--port\s+13337') {
        throw 'LR-PA complete command-line route mismatch'
    }

    $routePids = @($L0.ProcessId,$L1.ProcessId,$L2.ProcessId)
    $routeSockets = @(Get-NetTCPConnection -State Listen -ErrorAction Stop | Where-Object { $routePids -contains [int]$_.OwningProcess })
    if ($routeSockets.Count -ne 1 -or [int]$routeSockets[0].OwningProcess -ne $L2.ProcessId -or
        [string]$routeSockets[0].LocalAddress -ne '127.0.0.1' -or [int]$routeSockets[0].LocalPort -ne 13337) {
        throw 'LR-PA L2 is not the sole route listener'
    }
    return [pscustomobject][ordered]@{
        L0 = $L0
        L1 = $L1
        L2 = $L2
        Socket = [pscustomobject][ordered]@{ LocalAddress='127.0.0.1'; LocalPort=13337; OwningProcess=$L2.ProcessId }
        VenvRoot = $venvRoot
        VenvPython = $venvPython
        BasePython = $basePython
        SourceRoot = $sourceRoot
    }
}

function Assert-UID0002PAListenerRoute {
    param([Parameter(Mandatory=$true)]$Expected)
    $actual = Get-UID0002PAListenerRoute
    $expectedJson = $Expected | ConvertTo-Json -Depth 12 -Compress
    $actualJson = $actual | ConvertTo-Json -Depth 12 -Compress
    if ($actualJson -cne $expectedJson) { throw 'LR-PA listener route/process generation drift' }
    return $actual
}

function Get-UID0002PAWorkerRoute {
    param(
        [Parameter(Mandatory=$true)]$ListenerRoute,
        [Parameter(Mandatory=$true)][int]$ReturnedWorkerPid)

    $W0 = Get-UID0002PAExactProcess -ProcessId $ReturnedWorkerPid -Role 'W0 returned venv worker'
    if ($W0.ParentProcessId -ne $ListenerRoute.L2.ProcessId -or $W0.ExecutablePath -ine $ListenerRoute.VenvPython -or
        $W0.CommandLine -notmatch '(?i)-m\s+ida_pro_mcp\.idalib_server' -or
        $W0.CommandLine -notmatch '(?i)--host\s+127\.0\.0\.1' -or
        $W0.CommandLine -notmatch '(?i)--port\s+(\d+)') {
        throw 'worker W0 route/command mismatch'
    }
    $workerPort = [int][regex]::Match($W0.CommandLine, '(?i)--port\s+(\d+)').Groups[1].Value
    if ($workerPort -le 0) { throw 'worker port is unresolved' }
    $children = @(Get-CimInstance Win32_Process -Filter "ParentProcessId=$($W0.ProcessId)" -ErrorAction Stop)
    if ($children.Count -ne 1) { throw 'worker route requires exactly one W1 child' }
    $W1 = Get-UID0002PAExactProcess -ProcessId ([int]$children[0].ProcessId) -Role 'W1 base Python worker socket owner'
    if ($W1.ParentProcessId -ne $W0.ProcessId -or $W1.ExecutablePath -ine $ListenerRoute.BasePython -or
        $W1.CommandLine -cne $W0.CommandLine) { throw 'worker W1 route/command mismatch' }
    $workerPids = @($W0.ProcessId,$W1.ProcessId)
    $sockets = @(Get-NetTCPConnection -State Listen -ErrorAction Stop | Where-Object { $workerPids -contains [int]$_.OwningProcess })
    if ($sockets.Count -ne 1 -or [int]$sockets[0].OwningProcess -ne $W1.ProcessId -or
        [string]$sockets[0].LocalAddress -ne '127.0.0.1' -or [int]$sockets[0].LocalPort -ne $workerPort) {
        throw 'worker W1 is not the sole worker socket owner'
    }
    return [pscustomobject][ordered]@{
        W0 = $W0
        W1 = $W1
        Socket = [pscustomobject][ordered]@{ LocalAddress='127.0.0.1'; LocalPort=$workerPort; OwningProcess=$W1.ProcessId }
    }
}
~~~

## Removed Block R008

- SHA256: `A8C8FB011667C44E7A5F18CB4181C2B4716DE3AECC95D7144A6A8C5811B44B2F`
- Language: `powershell`
- Bytes: `12556`
- First recovered timestamp: `2026-08-06T23:38:10.231Z`
- Session provenance: rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 194262 (2026-08-06T23:38:10.231Z)

~~~powershell
$UID0002PASourceRoot = [System.IO.Path]::GetFullPath('C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp')
$UID0002PAListenerNames = @('ida_pro_mcp','ida_pro_mcp.idalib_supervisor','ida_pro_mcp.runtime_attestation','zeromcp','zeromcp.jsonrpc','zeromcp.mcp')
$UID0002PAWorkerNames = @('__main__','ida_pro_mcp','ida_pro_mcp.ida_mcp','ida_pro_mcp.ida_mcp._sigmaker','ida_pro_mcp.ida_mcp.api_analysis','ida_pro_mcp.ida_mcp.api_composite','ida_pro_mcp.ida_mcp.api_core','ida_pro_mcp.ida_mcp.api_debug','ida_pro_mcp.ida_mcp.api_memory','ida_pro_mcp.ida_mcp.api_modify','ida_pro_mcp.ida_mcp.api_python','ida_pro_mcp.ida_mcp.api_resources','ida_pro_mcp.ida_mcp.api_sigmaker','ida_pro_mcp.ida_mcp.api_stack','ida_pro_mcp.ida_mcp.api_survey','ida_pro_mcp.ida_mcp.api_types','ida_pro_mcp.ida_mcp.compat','ida_pro_mcp.ida_mcp.discovery','ida_pro_mcp.ida_mcp.http','ida_pro_mcp.ida_mcp.profile','ida_pro_mcp.ida_mcp.rpc','ida_pro_mcp.ida_mcp.sync','ida_pro_mcp.ida_mcp.trace','ida_pro_mcp.ida_mcp.utils','ida_pro_mcp.ida_mcp.zeromcp','ida_pro_mcp.ida_mcp.zeromcp.jsonrpc','ida_pro_mcp.ida_mcp.zeromcp.mcp','ida_pro_mcp.idalib_session_manager','ida_pro_mcp.runtime_attestation','ida_pro_mcp.worker_lifecycle')

function New-UID0002PAAttestationState {
    [pscustomobject]@{
        UsedNonces = [System.Collections.Generic.HashSet[string]]::new([System.StringComparer]::Ordinal)
        ListenerGeneration = $null
        ListenerManifest = $null
        WorkerManifest = $null
        RoleWorkers = @{}
    }
}

function Assert-UID0002PAModuleManifest {
    param(
        [Parameter(Mandatory=$true)]$Owner,
        [Parameter(Mandatory=$true)][ValidateSet('listener','worker')][string]$Role,
        [Parameter(Mandatory=$true)][string]$Label)

    $root = [System.IO.Path]::GetFullPath([string]$Owner.source_root).TrimEnd('\')
    if ($root -ine $UID0002PASourceRoot) { throw "$Label public source_root drift" }
    $expectedNames = if ($Role -ceq 'listener') { $UID0002PAListenerNames } else { $UID0002PAWorkerNames }
    $expectedManifest = if ($Role -ceq 'listener') {
        'D3C792133956B855EBA751FDB5783B2D7177FA204134CFF1D897E0D0770FB7CE'
    } else {
        '849203D42ABFC99176069E7069F039E9B50AC1A0F392BECB4D7C90CC7AE627D4'
    }
    if ([string]$Owner.implementation_manifest_sha256 -cne $expectedManifest) {
        throw "$Label public implementation-manifest SHA drift"
    }
    $rows = @($Owner.modules)
    if ($rows.Count -ne $expectedNames.Count -or (($rows.sys_modules_name -join '|') -cne ($expectedNames -join '|'))) {
        throw "$Label complete ordered module-name manifest mismatch"
    }

    $seenIds = @{}
    $seenFiles = @{}
    $normalized = @()
    $rootPrefix = $root + '\'
    foreach ($row in $rows) {
        foreach ($property in 'sys_modules_name','module_id','file','spec_origin','resolved_path','size','mtime_ns','ctime_ns','sha256') {
            if (-not $row.PSObject.Properties[$property]) { throw "$Label module field missing: $property" }
        }
        $file = [System.IO.Path]::GetFullPath([string]$row.file)
        $origin = [System.IO.Path]::GetFullPath([string]$row.spec_origin)
        $resolved = [System.IO.Path]::GetFullPath([string]$row.resolved_path)
        $moduleId = [string]$row.module_id
        $relative = if ($file.StartsWith($rootPrefix,[System.StringComparison]::OrdinalIgnoreCase)) {
            $file.Substring($rootPrefix.Length)
        } else { '' }
        if ($moduleId -notmatch '^0x[0-9a-f]+$' -or $seenIds.ContainsKey($moduleId) -or
            $seenFiles.ContainsKey($file.ToLowerInvariant()) -or $file -ine $origin -or $file -ine $resolved -or
            [string]::IsNullOrWhiteSpace($relative) -or [System.IO.Path]::IsPathRooted($relative) -or
            $relative.Split([System.IO.Path]::DirectorySeparatorChar) -contains '..' -or
            [long]$row.size -lt 0 -or [long]$row.mtime_ns -le 0 -or [long]$row.ctime_ns -le 0 -or
            [string]$row.sha256 -notmatch '^[0-9A-F]{64}$') {
            throw "$Label invalid module row $($row.sys_modules_name)"
        }
        $seenIds[$moduleId] = $true
        $seenFiles[$file.ToLowerInvariant()] = $true
        $normalized += [pscustomobject][ordered]@{
            Name=[string]$row.sys_modules_name
            File=$file
            SpecOrigin=$origin
            ResolvedPath=$resolved
            RelativePath=$relative
            Size=[long]$row.size
            MTimeNs=[long]$row.mtime_ns
            CTimeNs=[long]$row.ctime_ns
            SHA256=[string]$row.sha256
        }
    }
    return ($normalized | ConvertTo-Json -Depth 8 -Compress)
}

function Assert-UID0002PARuntimeAttestation {
    param(
        [Parameter(Mandatory=$true)]$Envelope,
        [Parameter(Mandatory=$true)]$ListEnvelope,
        [Parameter(Mandatory=$true)]$RoleBinding,
        [Parameter(Mandatory=$true)]$State)

    $a = Get-UID0002PAStructuredContent -Envelope $Envelope -Label 'RA-PA'
    $list = Get-UID0002PAStructuredContent -Envelope $ListEnvelope -Label 'RA-PA idb_list'
    if ([int]$a.schema_version -ne 1 -or $a.ok -ne $true -or @($a.errors).Count -ne 0 -or $null -eq $a.listener) {
        throw 'RA-PA top-level schema/status/errors mismatch'
    }

    $listener = $a.listener
    if ([string]$listener.role -cne 'supervisor_listener' -or [string]$listener.nonce -notmatch '^[0-9a-f]{32}$' -or
        -not $State.UsedNonces.Add([string]$listener.nonce) -or [string]$listener.endpoint.host -cne '127.0.0.1' -or
        [int]$listener.endpoint.port -ne 13337 -or [int]$listener.process.pid -le 0 -or
        [long]$listener.process.creation_time_100ns -le 0 -or
        [string]$listener.process.generation -cne "pid:$($listener.process.pid);created:$($listener.process.creation_time_100ns)" -or
        [System.IO.Path]::GetFullPath([string]$listener.process.sys_executable) -ine
            [System.IO.Path]::GetFullPath([string]$listener.process.process_image)) {
        throw 'RA-PA listener nonce/process generation mismatch'
    }
    if ([Math]::Abs(([DateTimeOffset]::UtcNow - [DateTimeOffset]::Parse([string]$listener.attested_at_utc)).TotalMinutes) -gt 5) {
        throw 'RA-PA listener attestation is stale'
    }
    $portRows = @(Get-NetTCPConnection -LocalAddress '127.0.0.1' -LocalPort 13337 -State Listen -ErrorAction Stop)
    if ($portRows.Count -ne 1 -or [int]$portRows[0].OwningProcess -ne [int]$listener.process.pid) {
        throw 'RA-PA independent passive listener ownership mismatch'
    }
    $listenerManifest = Assert-UID0002PAModuleManifest -Owner $listener -Role listener -Label 'listener'
    if ($null -eq $State.ListenerGeneration) {
        $State.ListenerGeneration = [string]$listener.process.generation
        $State.ListenerManifest = $listenerManifest
    } elseif ($State.ListenerGeneration -cne [string]$listener.process.generation -or
        $State.ListenerManifest -cne $listenerManifest) {
        throw 'RA-PA listener generation/manifest changed during transaction'
    }

    $active = @($list.sessions | Where-Object { $_.is_active -eq $true })
    $attestedSessionRows = @($a.workers | ForEach-Object { @($_.supervisor_sessions) })
    if ($active.Count -ne $attestedSessionRows.Count) { throw 'RA-PA active/attested session count mismatch' }
    foreach ($session in $active) {
        $matches = @($attestedSessionRows | Where-Object { [string]$_.session_id -ceq [string]$session.session_id })
        if ($matches.Count -ne 1 -or [string]$matches[0].backend -cne 'worker' -or $matches[0].owned -ne $true -or
            [int]$matches[0].redirector_pid -le 0 -or
            [int]$matches[0].redirector_pid -ne [int]$matches[0].registered_pid -or
            [int]$matches[0].redirector_pid -ne [int]$session.worker_pid -or
            [System.IO.Path]::GetFullPath([string]$matches[0].canonical_path) -ine
                [System.IO.Path]::GetFullPath([string]$session.input_path)) {
            throw "RA-PA session route mismatch $($session.session_id)"
        }
    }

    foreach ($entry in @($a.workers)) {
        $wa = $entry.attestation
        $supervisorRows = @($entry.supervisor_sessions)
        if ([int]$wa.schema_version -ne 1 -or $wa.ok -ne $true -or @($wa.errors).Count -ne 0 -or
            $null -eq $wa.worker -or [string]$wa.worker.role -cne 'stateful_worker' -or
            [string]$wa.worker.nonce -notmatch '^[0-9a-f]{32}$' -or
            -not $State.UsedNonces.Add([string]$wa.worker.nonce) -or
            [string]$entry.route.host -cne [string]$wa.worker.endpoint.host -or
            [int]$entry.route.port -ne [int]$wa.worker.endpoint.port -or $supervisorRows.Count -ne 1) {
            throw 'RA-PA worker schema/status/nonce/endpoint mismatch'
        }
        if ([Math]::Abs(([DateTimeOffset]::UtcNow - [DateTimeOffset]::Parse([string]$wa.worker.attested_at_utc)).TotalMinutes) -gt 5) {
            throw 'RA-PA worker attestation is stale'
        }
        $supervisorRow = $supervisorRows[0]
        if ([int]$wa.worker.process.pid -le 0 -or
            [int]$wa.worker.process.parent_pid -ne [int]$supervisorRow.redirector_pid -or
            [long]$wa.worker.process.creation_time_100ns -le 0 -or
            [string]$wa.worker.process.generation -cne "pid:$($wa.worker.process.pid);created:$($wa.worker.process.creation_time_100ns)" -or
            [System.IO.Path]::GetFullPath([string]$wa.worker.process.sys_executable) -ine
                [System.IO.Path]::GetFullPath([string]$wa.worker.process.process_image)) {
            throw 'RA-PA worker process/redirector generation mismatch'
        }
        $workerSockets = @(Get-NetTCPConnection -LocalAddress '127.0.0.1' -LocalPort ([int]$entry.route.port) -State Listen -ErrorAction Stop)
        if ($workerSockets.Count -ne 1 -or [int]$workerSockets[0].OwningProcess -ne [int]$wa.worker.process.pid) {
            throw 'RA-PA worker socket-owner mismatch'
        }
        $workerManifest = Assert-UID0002PAModuleManifest -Owner $wa.worker -Role worker -Label 'worker'
        if ($null -eq $State.WorkerManifest) { $State.WorkerManifest = $workerManifest }
        elseif ($State.WorkerManifest -cne $workerManifest) { throw 'RA-PA worker manifest changed between roles' }

        $workerSessions = @($wa.sessions)
        if ($workerSessions.Count -ne 1 -or [string]$workerSessions[0].session_id -cne [string]$supervisorRow.session_id -or
            $workerSessions[0].is_active -ne $true -or
            [System.IO.Path]::GetFullPath([string]$workerSessions[0].input_path) -ine
                [System.IO.Path]::GetFullPath([string]$supervisorRow.canonical_path) -or
            [System.IO.Path]::GetFullPath([string]$workerSessions[0].canonical_path) -ine
                [System.IO.Path]::GetFullPath([string]$supervisorRow.canonical_path)) {
            throw 'RA-PA worker internal session/path mismatch'
        }
        $roleKey = [string]$supervisorRow.session_id
        $workerIdentity = [pscustomobject][ordered]@{
            Generation=[string]$wa.worker.process.generation
            ParentPid=[int]$wa.worker.process.parent_pid
            RoutePort=[int]$entry.route.port
        }
        if ($State.RoleWorkers.ContainsKey($roleKey)) {
            if (($State.RoleWorkers[$roleKey] | ConvertTo-Json -Compress) -cne
                ($workerIdentity | ConvertTo-Json -Compress)) { throw 'RA-PA role worker identity drift' }
        } else {
            foreach ($prior in $State.RoleWorkers.Values) {
                if ($prior.Generation -ceq $workerIdentity.Generation) { throw 'RA-PA worker generation reused across roles' }
            }
            $State.RoleWorkers[$roleKey] = $workerIdentity
        }
    }

    $roleRows = @($attestedSessionRows | Where-Object { [string]$_.session_id -ceq [string]$RoleBinding.Database })
    if ($roleRows.Count -ne 1 -or
        [System.IO.Path]::GetFullPath([string]$roleRows[0].canonical_path) -ine
            [System.IO.Path]::GetFullPath([string]$RoleBinding.CanonicalPath)) {
        throw 'RA-PA exact returned database/path absent or duplicated'
    }
    return [pscustomobject]@{
        ListenerGeneration=[string]$listener.process.generation
        ListenerNonce=[string]$listener.nonce
        ListenerManifest=$listenerManifest
        ActiveDatabases=@($attestedSessionRows | ForEach-Object { [string]$_.session_id })
        WorkerGenerations=@($a.workers | ForEach-Object { [string]$_.attestation.worker.process.generation })
        WorkerNonces=@($a.workers | ForEach-Object { [string]$_.attestation.worker.nonce })
    }
}
~~~

## Removed Block R009

- SHA256: `0029B50E03CDCBD6D79C6B4A725F5F2DAB036FD780EB89A170CB067DF014B440`
- Language: `powershell`
- Bytes: `22075`
- First recovered timestamp: `2026-08-06T23:40:38.043Z`
- Session provenance: rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 194292 (2026-08-06T23:40:38.043Z); rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 194293 (2026-08-06T23:40:38.106Z)

~~~powershell
function New-UID0002PAToolRequest {
    param(
        [Parameter(Mandatory=$true)][string]$Id,
        [Parameter(Mandatory=$true)][string]$Name,
        [Parameter(Mandatory=$true)]$Arguments)

    $request = [ordered]@{
        jsonrpc='2.0'; id=$Id; method='tools/call'
        params=[ordered]@{ name=$Name; arguments=$Arguments }
    }
    $json = $request | ConvertTo-Json -Depth 30 -Compress
    $parsed = $json | ConvertFrom-Json -ErrorAction Stop
    if ([string]$parsed.params.name -cne $Name -or
        $json -match '__[A-Z0-9_]+__|<[^>]+>') { throw "RQ-PA unresolved request $Id" }
    return $json
}

function New-UID0002PAReadbackCatalog {
    param(
        [Parameter(Mandatory=$true)]$RoleBinding,
        [Parameter(Mandatory=$true)]
        [ValidateSet('Pre','AfterI01','AfterI02','AfterI03','AfterI04','AfterI05','Final','P0Verifier','S1Verifier','RollbackVerifier')]
        [string]$Phase)

    $db = [string]$RoleBinding.Database
    if ([string]::IsNullOrWhiteSpace($db)) { throw 'RQ-PA blank returned database' }
    $prefix = "uid0002pa-$Phase"
    $catalog = [ordered]@{}
    $catalog.IdbList = New-UID0002PAToolRequest "$prefix-list" 'idb_list' @{}
    $catalog.Attestation = New-UID0002PARuntimeAttestationRequest "$prefix-attest" $RoleBinding
    $catalog.Analyze = New-UID0002PAToolRequest "$prefix-analyze" 'analyze_function' ([ordered]@{
        database=$db; addr='0x00494130'; include_asm=$false
    })
    $catalog.Frame = New-UID0002PAToolRequest "$prefix-frame" 'stack_frame' ([ordered]@{
        database=$db; addrs='0x00494130'
    })
    $catalog.Xrefs = New-UID0002PAToolRequest "$prefix-xrefs" 'xref_query' ([ordered]@{
        database=$db; queries=[ordered]@{
            addr='0x00494130'; direction='to'; xref_type='code'; offset=0; count=200
            include_fn=$true; dedup=$true; sort_by='addr'; descending=$false
        }
    })
    $catalog.Callees = New-UID0002PAToolRequest "$prefix-callees" 'callees' ([ordered]@{
        database=$db; addrs='0x00494130'; limit=200
    })
    $catalog.Bytes = New-UID0002PAToolRequest "$prefix-bytes" 'get_bytes' ([ordered]@{
        database=$db; regions=@(
            [ordered]@{addr='0x00494130';size=166},
            [ordered]@{addr='0x00494126';size=10},
            [ordered]@{addr='0x004941d6';size=10}
        )
    })
    $catalog.Items = New-UID0002PAToolRequest "$prefix-items" 'inspect_items' ([ordered]@{
        database=$db
        addrs=@('0x00494126','0x00494130','0x00494157','0x00494166','0x00494176','0x004941d5','0x004941d6','0x004941e0')
    })
    $catalog.Comments = New-UID0002PAToolRequest "$prefix-comments" 'get_comments' ([ordered]@{
        database=$db; addrs=@('0x00494130','0x00494157','0x00494166','0x00494176')
    })
    $catalog.Collision = New-UID0002PAToolRequest "$prefix-collision" 'entity_query' ([ordered]@{
        database=$db; queries=@(
            [ordered]@{kind='functions';regex='^ServerSelectDirectory__ReleaseOwnedBuffers$';offset=0;count=200;sort_by='addr';descending=$false;fields=@('addr','name','size')},
            [ordered]@{kind='names';regex='^ServerSelectDirectory__ReleaseOwnedBuffers$';offset=0;count=200;sort_by='addr';descending=$false;fields=@('addr','name')}
        )
    })
    $catalog.CandidateTypes = New-UID0002PAToolRequest "$prefix-candidate-types" 'type_inspect' ([ordered]@{
        database=$db; queries=@(
            [ordered]@{name='ConfigEntry';include_members=$true;max_members=100},
            [ordered]@{name='ConfigEntryBlock';include_members=$true;max_members=100},
            [ordered]@{name='ServerSelectEntry';include_members=$true;max_members=100},
            [ordered]@{name='ServerSelectDirectory';include_members=$true;max_members=100}
        )
    })
    $catalog.CandidateTypeIndex = New-UID0002PAToolRequest "$prefix-candidate-index" 'type_query' ([ordered]@{
        database=$db; queries=@(
            [ordered]@{filter='ServerSelectEntry';kind='udt';offset=0;count=200;sort_by='name';descending=$false;include_decl=$true;include_members=$true;max_members=100;include_relationships=$true},
            [ordered]@{filter='ServerSelectDirectory';kind='udt';offset=0;count=200;sort_by='name';descending=$false;include_decl=$true;include_members=$true;max_members=100;include_relationships=$true}
        )
    })
    $catalog.Config = New-UID0002PAToolRequest "$prefix-config" 'type_inspect' ([ordered]@{
        database=$db; queries=[ordered]@{name='Config';include_members=$true;max_members=100}
    })
    foreach ($entry in $catalog.GetEnumerator()) {
        $parsed = $entry.Value | ConvertFrom-Json -ErrorAction Stop
        if ($entry.Key -notin @('IdbList','Attestation') -and
            [string]$parsed.params.arguments.database -cne $db) {
            throw "RQ-PA $($entry.Key) lost returned database"
        }
    }
    return $catalog
}

function Get-UID0002PASha256ForByteText {
    param([Parameter(Mandatory=$true)][string]$Text)
    $bytes = @($Text -split '\s+' | Where-Object { $_ } | ForEach-Object {
        if ($_ -notmatch '^0x[0-9a-fA-F]{1,2}$') { throw "RQ-PA invalid byte token $_" }
        [Convert]::ToByte($_.Substring(2),16)
    })
    $sha = [Security.Cryptography.SHA256]::Create()
    try { return ([BitConverter]::ToString($sha.ComputeHash([byte[]]$bytes))).Replace('-','') }
    finally { $sha.Dispose() }
}

function Assert-UID0002PAExactJson {
    param([Parameter(Mandatory=$true)]$Actual,[Parameter(Mandatory=$true)]$Expected,[Parameter(Mandatory=$true)][string]$Label)
    $actualJson = $Actual | ConvertTo-Json -Depth 30 -Compress
    $expectedJson = $Expected | ConvertTo-Json -Depth 30 -Compress
    if ($actualJson -cne $expectedJson) { throw "RQ-PA exact result mismatch: $Label" }
}

function Get-UID0002PAConfigOracle {
    $names = '_configPrefixToStartupChannel|m_startupChannel|_configStartupChannelToOptionCluster|m_soundEffectsEnabled|_configToOptionCluster|m_mapEffectEnabled|m_sayWithEnter|m_doubleClickEnabled|m_autoMoveEnabled|m_balloonFillEnabled|m_staticObjectTransparencyEnabled|m_shadowEnabled|m_showUserName|m_selfLookTopButtonSelected|m_selfLookBottomButtonSelected|m_targetSelectionSuppressed|m_tabVSwap|m_showDamage|m_groupBarEnabled|m_carnageColorEnabled|_alignment_28DE67|m_graphicsSetting|m_orbTargetShare|m_f1Swap|m_whisperEnabled|m_shoutEnabled|m_adviceEnabled|m_hearSnoreMode|m_magicEffectsEnabled|m_weatherEffectsEnabled|m_fixedMovementEnabled|m_mapMovementStatusOption|m_seeThroughEnabled|m_hearEmotions|m_chatVisibleLineCount|m_chatHandleModeIndex|m_secondaryChatEnabled|m_chatHandleLeftToggle|m_chatColorPairs|m_clickMoveEnabled|m_clickLookEnabled|m_systemMessageHeight|m_powerDialogThresholdDefaults|m_profileTextSlots|m_legacyShortcutText|m_compactShortcutRecords|m_macroHotkeys|_configAfterMacroHotkeys|m_blockListenNames|m_musicSourceMode|_configTail'.Split('|')
    $offsets = '0x0|0x28d9e0|0x28db10|0x28de48|0x28de49|0x28de58|0x28de59|0x28de5a|0x28de5b|0x28de5c|0x28de5d|0x28de5e|0x28de5f|0x28de60|0x28de61|0x28de62|0x28de63|0x28de64|0x28de65|0x28de66|0x28de67|0x28de68|0x28de6c|0x28de6d|0x28de6e|0x28de6f|0x28de70|0x28de71|0x28de72|0x28de73|0x28de74|0x28de75|0x28de76|0x28de77|0x28de78|0x28de7c|0x28de80|0x28de81|0x28de82|0x28de8e|0x28de8f|0x28de90|0x28de94|0x28de9c|0x28e89c|0x28f29c|0x28f2ec|0x2911dc|0x2918fc|0x291908|0x29190c'.Split('|')
    $sizes = '2677216|304|824|1|15|1|1|1|1|1|1|1|1|1|1|1|1|1|1|1|1|4|1|1|1|1|1|1|1|1|1|1|1|1|4|4|1|1|12|1|1|4|8|2560|2560|80|7920|1824|12|4|12'.Split('|')
    $types = 'unsigned __int8[2677216]|ConfigStartupChannelData|unsigned __int8[824]|unsigned __int8|unsigned __int8[15]|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned int|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned int|unsigned int|unsigned __int8|unsigned __int8|ChatColorPair[6]|unsigned __int8|unsigned __int8|unsigned int|unsigned __int16[4]|wchar_t[10][128]|wchar_t[10][128]|CompactShortcutRecord[20]|MacroHotkeyRecord[30]|unsigned __int8[1824]|SimpleUStringVector|unsigned int|unsigned __int8[12]'.Split('|')
    if ($names.Count -ne 51 -or $offsets.Count -ne 51 -or $sizes.Count -ne 51 -or $types.Count -ne 51) {
        throw 'RQ-PA Config oracle cardinality is not 51'
    }
    $rows = @()
    for ($i=0; $i -lt 51; $i++) {
        $rows += [pscustomobject][ordered]@{name=$names[$i];offset=$offsets[$i];size=[int]$sizes[$i];type=$types[$i]}
    }
    return $rows
}

function Assert-UID0002PAReadbackCatalog {
    param(
        [Parameter(Mandatory=$true)]$Responses,
        [Parameter(Mandatory=$true)]$RoleBinding,
        [Parameter(Mandatory=$true)]$AttestationState,
        [Parameter(Mandatory=$true)]
        [ValidateSet('Pre','AfterI01','AfterI02','AfterI03','AfterI04','AfterI05','Final','P0Verifier','S1Verifier','RollbackVerifier')]
        [string]$Phase)

    $required = 'IdbList','Attestation','Analyze','Frame','Xrefs','Callees','Bytes','Items','Comments','Collision','CandidateTypes','CandidateTypeIndex','Config'
    if ((@($Responses.Keys | Sort-Object) -join '|') -cne (@($required | Sort-Object) -join '|')) {
        throw "RQ-PA $Phase response catalog keys mismatch"
    }
    $null = Assert-UID0002PARuntimeAttestation -Envelope $Responses.Attestation -ListEnvelope $Responses.IdbList -RoleBinding $RoleBinding -State $AttestationState
    $list = Get-UID0002PAStructuredContent $Responses.IdbList "$Phase idb_list"
    $activeCanonical = @($list.sessions | Where-Object {
        $_.is_active -eq $true -and
        [System.IO.Path]::GetFullPath([string]$_.input_path) -ieq [string]$RoleBinding.CanonicalPath
    })
    if ($activeCanonical.Count -ne 1 -or [string]$activeCanonical[0].session_id -cne [string]$RoleBinding.Database -or
        [int]$activeCanonical[0].worker_pid -ne [int]$RoleBinding.CorroboratedRedirectorPid) {
        throw "RQ-PA $Phase exact active returned-session mismatch"
    }

    $postTypes = $Phase -in @('AfterI01','AfterI02','AfterI03','AfterI04','AfterI05','Final','S1Verifier')
    $postName = $Phase -in @('AfterI02','AfterI03','AfterI04','AfterI05','Final','S1Verifier')
    $postPrototype = $Phase -in @('AfterI03','AfterI04','AfterI05','Final','S1Verifier')
    $postFunctionComment = $Phase -in @('AfterI04','AfterI05','Final','S1Verifier')
    $postAddressComments = $Phase -in @('AfterI05','Final','S1Verifier')
    $expectedName = if ($postName) {'ServerSelectDirectory__ReleaseOwnedBuffers'} else {'sub_494130'}
    $expectedPrototype = if ($postPrototype) {
        'void __thiscall ServerSelectDirectory__ReleaseOwnedBuffers(ServerSelectDirectory *this)'
    } else { 'void __thiscall(int this)' }

    $analyze = Get-UID0002PAStructuredContent $Responses.Analyze "$Phase analyze"
    if ([string]$analyze.addr -cne '0x494130' -or $null -ne $analyze.error -or
        [string]$analyze.name -cne $expectedName -or [string]$analyze.prototype -cne $expectedPrototype -or
        [int]$analyze.size -ne 166 -or @($analyze.strings).Count -ne 0 -or @($analyze.constants).Count -ne 0 -or
        (@($analyze.callees) -join '|') -cne 'j_j_j___free_base' -or
        (@($analyze.callers) -join '|') -cne 'sub_48E780|sub_4926A0|sub_493F90|sub_494020' -or
        [int]$analyze.basic_blocks.count -ne 13 -or [int]$analyze.basic_blocks.cyclomatic_complexity -ne 5) {
        throw "RQ-PA $Phase analyze protection mismatch"
    }

    $frame = Get-UID0002PAStructuredContent $Responses.Frame "$Phase frame"
    $expectedFrame = [ordered]@{result=@([ordered]@{addr='0x00494130';vars=@([ordered]@{name='__return_address';offset='0x4';size='0x4';type='_UNKNOWN *'})})}
    Assert-UID0002PAExactJson $frame $expectedFrame "$Phase frame"

    $xrefs = Get-UID0002PAStructuredContent $Responses.Xrefs "$Phase xrefs"
    $xr = @($xrefs.result)
    if ($xr.Count -ne 1 -or [string]$xr[0].target -cne '0x00494130' -or [string]$xr[0].resolved_addr -cne '0x494130' -or
        [string]$xr[0].direction -cne 'to' -or [string]$xr[0].xref_type -cne 'code' -or
        $null -ne $xr[0].next_offset -or [int]$xr[0].total -ne 5 -or $null -ne $xr[0].error) {
        throw "RQ-PA $Phase xref page mismatch"
    }
    $xrefRows = @($xr[0].data | ForEach-Object {
        "$($_.addr)|$($_.from)|$($_.to)|$($_.type)|$($_.fn.addr)|$($_.fn.name)|$($_.fn.size)"
    })
    $expectedXrefs = @(
        '0x48e824|0x48e824|0x494130|code|0x48e780|sub_48E780|0xda',
        '0x4938d6|0x4938d6|0x494130|code|0x4926a0|sub_4926A0|0x1789',
        '0x493e01|0x493e01|0x494130|code|0x4926a0|sub_4926A0|0x1789',
        '0x493fb5|0x493fb5|0x494130|code|0x493f90|sub_493F90|0x49',
        '0x4940c8|0x4940c8|0x494130|code|0x494020|sub_494020|0x106'
    )
    if (($xrefRows -join '|') -cne ($expectedXrefs -join '|')) { throw "RQ-PA $Phase exact xref rows mismatch" }

    $callees = Get-UID0002PAStructuredContent $Responses.Callees "$Phase callees"
    $expectedCallees = [ordered]@{result=@([ordered]@{addr='0x00494130';callees=@([ordered]@{addr='0x5c7799';name='j_j_j___free_base';type='internal'});more=$false})}
    Assert-UID0002PAExactJson $callees $expectedCallees "$Phase callees"

    $bytes = Get-UID0002PAStructuredContent $Responses.Bytes "$Phase bytes"
    if (@($bytes.result).Count -ne 3 -or
        (Get-UID0002PASha256ForByteText ([string]$bytes.result[0].data)) -cne '2D53FB76ED15C7F4CD368E05DB122B074B92B32FCEC39A260D38F769859CD42B' -or
        (Get-UID0002PASha256ForByteText ([string]$bytes.result[1].data)) -cne '22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045' -or
        (Get-UID0002PASha256ForByteText ([string]$bytes.result[2].data)) -cne '22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045') {
        throw "RQ-PA $Phase byte/padding SHA mismatch"
    }

    $items = Get-UID0002PAStructuredContent $Responses.Items "$Phase items"
    $expectedItems = @(
        "0x00494126|0x494126|0x494130|10|||False|True",
        "0x00494130|0x494130|0x494131|1|$expectedName|$expectedPrototype|True|False",
        '0x00494157|0x494157|0x494158|1|||True|False',
        '0x00494166|0x494166|0x494167|1|||True|False',
        '0x00494176|0x494176|0x494177|1|||True|False',
        '0x004941d5|0x4941d5|0x4941d6|1|||True|False',
        '0x004941d6|0x4941d6|0x4941e0|10|||False|True',
        '0x004941e0|0x4941e0|0x4941e1|1|sub_4941E0|HRESULT __thiscall(LPVOID *ppv, LPCCH lpMultiByteStr, IUnknown *, DWORD dwClsContext)|True|False'
    )
    $actualItems = @($items.result | ForEach-Object {
        "$($_.addr)|$($_.head)|$($_.end)|$($_.size)|$($_.name)|$($_.type)|$($_.is_code)|$($_.is_data)"
    })
    if (($actualItems -join '|') -cne ($expectedItems -join '|')) { throw "RQ-PA $Phase exact item rows mismatch" }

    $comments = Get-UID0002PAStructuredContent $Responses.Comments "$Phase comments"
    $functionText = if ($postFunctionComment) {
        'ServerSelectDirectory::ReleaseOwnedBuffers; frees name, description, and agreement text for active entries, then resets entryCount and version. The null-receiver branch still faults on the final resets.'
    } else { '' }
    $addressTexts = if ($postAddressComments) {
        @('Free ServerSelectEntry::name when non-null.','Free ServerSelectEntry::description when non-null.','Free ServerSelectEntry::agreementText when non-null.')
    } else { @('Block','Block','Block') }
    $commentRows = @($comments.result)
    if ($commentRows.Count -ne 4 -or [string]$commentRows[0].addr -cne '0x00494130' -or
        [string]$commentRows[0].regular -cne '' -or [string]$commentRows[0].repeatable -cne '' -or
        [string]$commentRows[0].function_regular -cne $functionText -or
        [string]$commentRows[0].function_repeatable -cne '') { throw "RQ-PA $Phase function comment channels mismatch" }
    for ($i=1; $i -lt 4; $i++) {
        if ([string]$commentRows[$i].regular -cne $addressTexts[$i-1] -or
            [string]$commentRows[$i].repeatable -cne '') { throw "RQ-PA $Phase address comment channels mismatch" }
    }

    $collision = Get-UID0002PAStructuredContent $Responses.Collision "$Phase collision"
    if (@($collision.result).Count -ne 2) { throw "RQ-PA $Phase collision page count mismatch" }
    if ($postName) {
        if ([int]$collision.result[0].total -ne 1 -or [string]$collision.result[0].data[0].addr -cne '0x494130' -or
            [string]$collision.result[0].data[0].name -cne $expectedName -or [int]$collision.result[0].data[0].size -ne 166 -or
            [int]$collision.result[1].total -ne 1 -or [string]$collision.result[1].data[0].addr -cne '0x494130' -or
            [string]$collision.result[1].data[0].name -cne $expectedName) { throw "RQ-PA $Phase renamed identity mismatch" }
    } elseif ([int]$collision.result[0].total -ne 0 -or [int]$collision.result[1].total -ne 0) {
        throw "RQ-PA $Phase proposed-name collision"
    }
    foreach ($page in $collision.result) {
        if ($null -ne $page.next_offset -or $null -ne $page.error) { throw "RQ-PA $Phase collision pagination/error mismatch" }
    }

    $candidate = Get-UID0002PAStructuredContent $Responses.CandidateTypes "$Phase candidate types"
    $candidateRows = @($candidate.result)
    if ($candidateRows.Count -ne 4 -or $candidateRows[0].exists -ne $false -or $candidateRows[1].exists -ne $false) {
        throw "RQ-PA $Phase legacy candidate-type mismatch"
    }
    if (-not $postTypes) {
        if ($candidateRows[2].exists -ne $false -or $candidateRows[3].exists -ne $false) { throw "RQ-PA $Phase prestate UDT collision" }
    } else {
        $entryMembers = @(
            'serverId|0x0|1|unsigned __int8','name|0x4|4|wchar_t *','description|0x8|4|wchar_t *',
            'agreementText|0xc|4|wchar_t *','address|0x10|4|unsigned __int8[4]','port|0x14|2|unsigned __int16'
        )
        $directoryMembers = @('entries|0x0|768|ServerSelectEntry[32]','entryCount|0x300|4|int','version|0x304|1|unsigned __int8')
        if ($candidateRows[2].exists -ne $true -or [int]$candidateRows[2].size -ne 24 -or [int]$candidateRows[2].member_count -ne 6 -or
            (@($candidateRows[2].members | ForEach-Object {"$($_.name)|$($_.offset)|$($_.size)|$($_.type)"}) -join '|') -cne ($entryMembers -join '|') -or
            $candidateRows[3].exists -ne $true -or [int]$candidateRows[3].size -ne 776 -or [int]$candidateRows[3].member_count -ne 3 -or
            (@($candidateRows[3].members | ForEach-Object {"$($_.name)|$($_.offset)|$($_.size)|$($_.type)"}) -join '|') -cne ($directoryMembers -join '|')) {
            throw "RQ-PA $Phase exact declared UDT layout mismatch"
        }
    }

    $typeIndex = Get-UID0002PAStructuredContent $Responses.CandidateTypeIndex "$Phase candidate type index"
    foreach ($page in @($typeIndex.result)) {
        $expectedTotal = if ($postTypes) {1} else {0}
        if ([int]$page.total -ne $expectedTotal -or $null -ne $page.next_offset -or @($page.data).Count -ne $expectedTotal) {
            throw "RQ-PA $Phase exact UDT index mismatch"
        }
    }

    $config = Get-UID0002PAStructuredContent $Responses.Config "$Phase Config"
    $configRows = @($config.result)
    if ($configRows.Count -ne 1 -or $configRows[0].exists -ne $true -or [string]$configRows[0].name -cne 'Config' -or
        [int]$configRows[0].size -ne 2693400 -or [int]$configRows[0].member_count -ne 51) {
        throw "RQ-PA $Phase Config shell mismatch"
    }
    Assert-UID0002PAExactJson @($configRows[0].members) @(Get-UID0002PAConfigOracle) "$Phase Config 51 rows"
    return [pscustomobject]@{Phase=$Phase;Database=[string]$RoleBinding.Database;Passed=$true}
}

function Assert-UID0002PAMutationResponse {
    param(
        [Parameter(Mandatory=$true)][ValidateSet('I01','I02Dry','I02','I03','I04','I05')][string]$Action,
        [Parameter(Mandatory=$true)]$Envelope)

    $result = Get-UID0002PAStructuredContent $Envelope "mutation $Action"
    $entryDecl = 'struct ServerSelectEntry { unsigned char serverId; wchar_t *name; wchar_t *description; wchar_t *agreementText; unsigned char address[4]; unsigned short port; };'
    $directoryDecl = 'struct ServerSelectDirectory { ServerSelectEntry entries[32]; int entryCount; unsigned char version; };'
    switch ($Action) {
        'I01' {
            Assert-UID0002PAExactJson $result @([ordered]@{decl=$entryDecl},[ordered]@{decl=$directoryDecl}) 'I01 declare_type response'
        }
        'I02Dry' {
            $expected=[ordered]@{
                func=@([ordered]@{addr='0x00494130';old='sub_494130';name='ServerSelectDirectory__ReleaseOwnedBuffers';dry_run=$true})
                summary=[ordered]@{total=1;ok=1;failed=0;stopped=$false;dry_run=$true;stop_on_error=$true}
            }
            Assert-UID0002PAExactJson $result $expected 'I02 dry-run response'
        }
        'I02' {
            $expected=[ordered]@{
                func=@([ordered]@{addr='0x00494130';old='sub_494130';name='ServerSelectDirectory__ReleaseOwnedBuffers'})
                summary=[ordered]@{total=1;ok=1;failed=0;stopped=$false;stop_on_error=$true}
            }
            Assert-UID0002PAExactJson $result $expected 'I02 apply response'
        }
        'I03' {
            $edit=[ordered]@{addr='0x00494130';kind='function';signature='void __thiscall ServerSelectDirectory__ReleaseOwnedBuffers(ServerSelectDirectory *this)'}
            Assert-UID0002PAExactJson $result @([ordered]@{edit=$edit;kind='function';ok=$true}) 'I03 set_type response'
        }
        'I04' {
            Assert-UID0002PAExactJson $result @([ordered]@{addr='0x00494130';function_addr='0x494130'}) 'I04 function-comment response'
        }
        'I05' {
            Assert-UID0002PAExactJson $result @(
                [ordered]@{addr='0x00494157'},[ordered]@{addr='0x00494166'},[ordered]@{addr='0x00494176'}
            ) 'I05 address-comment response'
        }
    }
}
~~~

## Removed Block R010

- SHA256: `27FFE8305032D75AC1EF22ACD769B4C37463800FFBE3247E42A59964531CC9BF`
- Language: `powershell`
- Bytes: `21362`
- First recovered timestamp: `2026-08-06T23:42:39.756Z`
- Session provenance: rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 194307 (2026-08-06T23:42:39.756Z)

~~~powershell
function Get-UID0002PAStreamSha256 {
    param([Parameter(Mandatory=$true)][System.IO.FileStream]$Stream)
    $Stream.Position = 0
    $sha = [System.Security.Cryptography.SHA256]::Create()
    try { $digest = $sha.ComputeHash($Stream) }
    finally { $sha.Dispose() }
    $Stream.Position = 0
    return ([System.BitConverter]::ToString($digest)).Replace('-','')
}

function Get-UID0002PAExclusiveTuple {
    param([Parameter(Mandatory=$true)][string]$Path)
    $full = [System.IO.Path]::GetFullPath($Path)
    if (-not [System.IO.File]::Exists($full)) { throw "missing file: $full" }
    $beforeTicks = [System.IO.File]::GetLastWriteTimeUtc($full).Ticks
    $stream = $null
    try {
        $stream = [System.IO.FileStream]::new($full,[System.IO.FileMode]::Open,[System.IO.FileAccess]::Read,[System.IO.FileShare]::None)
        $length = [long]$stream.Length
        if ($length -le 0) { throw "nonpositive length: $full" }
        $sha256 = Get-UID0002PAStreamSha256 $stream
        $duringTicks = [System.IO.File]::GetLastWriteTimeUtc($full).Ticks
        if ($beforeTicks -ne $duringTicks) { throw "mtime changed during exclusive tuple: $full" }
    } finally {
        if ($null -ne $stream) { $stream.Dispose() }
    }
    $afterTicks = [System.IO.File]::GetLastWriteTimeUtc($full).Ticks
    if ($duringTicks -ne $afterTicks) { throw "mtime changed after exclusive tuple: $full" }
    [pscustomobject][ordered]@{
        FullPath=$full; Length=$length; LastWriteTimeUtcTicks=[long]$afterTicks; SHA256=$sha256
    }
}

function Assert-UID0002PATuple {
    param([Parameter(Mandatory=$true)]$Actual,[Parameter(Mandatory=$true)]$Expected,[Parameter(Mandatory=$true)][string]$Label)
    foreach ($property in 'FullPath','Length','LastWriteTimeUtcTicks','SHA256') {
        if ([string]$Actual.$property -cne [string]$Expected.$property) { throw "$Label tuple mismatch at $property" }
    }
}

function Get-UID0002PATupleCopy {
    param([Parameter(Mandatory=$true)]$Tuple)
    [pscustomobject][ordered]@{
        FullPath=[string]$Tuple.FullPath
        Length=[long]$Tuple.Length
        LastWriteTimeUtcTicks=[long]$Tuple.LastWriteTimeUtcTicks
        SHA256=[string]$Tuple.SHA256
    }
}

function New-UID0002PABackup {
    param([Parameter(Mandatory=$true)][string]$CanonicalPath,[Parameter(Mandatory=$true)][string]$BackupPath)

    $canonical = [System.IO.Path]::GetFullPath($CanonicalPath)
    $backup = [System.IO.Path]::GetFullPath($BackupPath)
    if ($canonical -ieq $backup -or [System.IO.File]::Exists($backup)) { throw 'BK-PA alias/collision' }

    $source = $null
    $destination = $null
    try {
        $source = [System.IO.FileStream]::new($canonical,[System.IO.FileMode]::Open,[System.IO.FileAccess]::Read,[System.IO.FileShare]::None)
        $p0Length = [long]$source.Length
        $p0TicksBefore = [long][System.IO.File]::GetLastWriteTimeUtc($canonical).Ticks
        $p0Sha = Get-UID0002PAStreamSha256 $source
        $source.Position = 0
        $destination = [System.IO.FileStream]::new($backup,[System.IO.FileMode]::CreateNew,[System.IO.FileAccess]::Write,[System.IO.FileShare]::None)
        $buffer = New-Object byte[] 1048576
        $copied = [long]0
        while (($read = $source.Read($buffer,0,$buffer.Length)) -gt 0) {
            $destination.Write($buffer,0,$read)
            $copied += $read
        }
        if ($copied -ne $p0Length -or $source.Position -ne $p0Length -or $source.ReadByte() -ne -1) {
            throw 'BK-PA source count/position/EOF mismatch'
        }
        if ($destination.Position -ne $p0Length -or $destination.Length -ne $p0Length) {
            throw 'BK-PA destination position/length mismatch'
        }
        $destination.Flush($true)
        $p0TicksDuring = [long][System.IO.File]::GetLastWriteTimeUtc($canonical).Ticks
        if ($p0TicksDuring -ne $p0TicksBefore) { throw 'BK-PA canonical timestamp changed during exclusive copy' }
        $expectedP0 = [pscustomobject][ordered]@{
            FullPath=$canonical;Length=$p0Length;LastWriteTimeUtcTicks=$p0TicksBefore;SHA256=$p0Sha
        }
    } finally {
        if ($null -ne $destination) { $destination.Dispose() }
        if ($null -ne $source) { $source.Dispose() }
    }

    $closedP0BeforeTimestamp = Get-UID0002PAExclusiveTuple $canonical
    Assert-UID0002PATuple $closedP0BeforeTimestamp $expectedP0 'BK-PA closed P0 before timestamp'
    $closedB0BeforeTimestamp = Get-UID0002PAExclusiveTuple $backup
    if ($closedB0BeforeTimestamp.FullPath -ieq $closedP0BeforeTimestamp.FullPath -or
        $closedB0BeforeTimestamp.Length -ne $closedP0BeforeTimestamp.Length -or
        $closedB0BeforeTimestamp.SHA256 -cne $closedP0BeforeTimestamp.SHA256) {
        throw 'BK-PA closed B0 content parity failed before timestamp normalization'
    }

    [System.IO.File]::SetLastWriteTimeUtc($backup,[DateTime]::new([long]$expectedP0.LastWriteTimeUtcTicks,[DateTimeKind]::Utc))
    $closedP0 = Get-UID0002PAExclusiveTuple $canonical
    Assert-UID0002PATuple $closedP0 $expectedP0 'BK-PA unchanged P0 after timestamp'
    $expectedB0 = [pscustomobject][ordered]@{
        FullPath=$backup;Length=$expectedP0.Length
        LastWriteTimeUtcTicks=$expectedP0.LastWriteTimeUtcTicks;SHA256=$expectedP0.SHA256
    }
    $closedB0 = Get-UID0002PAExclusiveTuple $backup
    Assert-UID0002PATuple $closedB0 $expectedB0 'BK-PA complete B0'
    [pscustomobject][ordered]@{P0=Get-UID0002PATupleCopy $closedP0;B0=Get-UID0002PATupleCopy $closedB0}
}

function Get-UID0002PATextSha256 {
    param([Parameter(Mandatory=$true)][string]$Text)
    $sha=[Security.Cryptography.SHA256]::Create()
    try { ([BitConverter]::ToString($sha.ComputeHash([Text.Encoding]::UTF8.GetBytes($Text)))).Replace('-','') }
    finally { $sha.Dispose() }
}

function Get-UID0002PAAttemptSeal {
    param([Parameter(Mandatory=$true)]$Attempt)
    $projection=[ordered]@{
        AttemptId=[string]$Attempt.AttemptId;Database=[string]$Attempt.Database
        CanonicalPath=[string]$Attempt.CanonicalPath;SaveRequestSHA256=[string]$Attempt.SaveRequestSHA256
        DispatchCount=[int]$Attempt.DispatchCount;TransportClass=[string]$Attempt.TransportClass
        DiskClass=[string]$Attempt.DiskClass;Status=[string]$Attempt.Status
        P0=$Attempt.P0;B0=$Attempt.B0;AttributableTuple=$Attempt.AttributableTuple
    }
    Get-UID0002PATextSha256 ($projection | ConvertTo-Json -Depth 20 -Compress)
}

function Set-UID0002PAAttemptSeal {
    param([Parameter(Mandatory=$true)]$Attempt)
    $Attempt.AuthoritySeal = Get-UID0002PAAttemptSeal $Attempt
}

function Assert-UID0002PAAttemptSeal {
    param([Parameter(Mandatory=$true)]$Attempt)
    if ([string]::IsNullOrWhiteSpace([string]$Attempt.AuthoritySeal) -or
        [string]$Attempt.AuthoritySeal -cne (Get-UID0002PAAttemptSeal $Attempt)) {
        throw 'SV-PA save-attempt authority seal mismatch'
    }
}

function New-UID0002PASaveAttempt {
    param(
        [Parameter(Mandatory=$true)]$RoleBinding,
        [Parameter(Mandatory=$true)]$BackupState,
        [Parameter(Mandatory=$true)]$FinalReadback,
        [Parameter(Mandatory=$true)]$FinalAttestation,
        [Parameter(Mandatory=$true)][string]$MaterializedSaveRequestJson)

    if ($FinalReadback.Passed -ne $true -or [string]$FinalReadback.Phase -cne 'Final' -or
        [string]$FinalReadback.Database -cne [string]$RoleBinding.Database) {
        throw 'SV-PA Final readback authority missing'
    }
    if ((@($FinalAttestation.ActiveDatabases) -join '|') -cne [string]$RoleBinding.Database) {
        throw 'SV-PA transaction role is not the sole active database'
    }
    $request=$MaterializedSaveRequestJson | ConvertFrom-Json -ErrorAction Stop
    if ([string]$request.params.name -cne 'idb_save' -or
        [string]$request.params.arguments.database -cne [string]$RoleBinding.Database -or
        [System.IO.Path]::GetFullPath([string]$request.params.arguments.path) -ine [string]$RoleBinding.CanonicalPath -or
        @($request.params.arguments.PSObject.Properties.Name | Sort-Object) -join '|' -cne 'database|path' -or
        $MaterializedSaveRequestJson -match '__[A-Z0-9_]+__|<[^>]+>') {
        throw 'SV-PA sole save request mismatch'
    }
    $attempt=[pscustomobject][ordered]@{
        AttemptId=[string]$request.id;Database=[string]$RoleBinding.Database
        CanonicalPath=[string]$RoleBinding.CanonicalPath
        SaveRequestJson=$MaterializedSaveRequestJson
        SaveRequestSHA256=Get-UID0002PATextSha256 $MaterializedSaveRequestJson
        DispatchCount=0;TransportClass='NotDispatched';RawResponseJson=$null
        DiskClass='Unclassified';Status='PREPARED'
        P0=Get-UID0002PATupleCopy $BackupState.P0
        B0=Get-UID0002PATupleCopy $BackupState.B0
        AttributableTuple=$null;AuthoritySeal=$null
    }
    Set-UID0002PAAttemptSeal $attempt
    return $attempt
}

function Register-UID0002PASoleSaveDispatch {
    param([Parameter(Mandatory=$true)]$Attempt)
    Assert-UID0002PAAttemptSeal $Attempt
    if ($Attempt.Status -cne 'PREPARED' -or [int]$Attempt.DispatchCount -ne 0) { throw 'SV-PA save retry/duplicate dispatch' }
    $Attempt.DispatchCount=1
    $Attempt.Status='DISPATCHED'
    Set-UID0002PAAttemptSeal $Attempt
    return [string]$Attempt.SaveRequestJson
}

function Complete-UID0002PASaveTransport {
    param(
        [Parameter(Mandatory=$true)]$Attempt,
        [Parameter(Mandatory=$true)][ValidateSet('Response','Timeout','Disconnect','Malformed')][string]$ObservedTransport,
        [AllowNull()][string]$RawResponseJson)

    Assert-UID0002PAAttemptSeal $Attempt
    if ($Attempt.Status -cne 'DISPATCHED' -or [int]$Attempt.DispatchCount -ne 1) { throw 'SV-PA transport classification out of order' }
    $Attempt.RawResponseJson=$RawResponseJson
    if ($ObservedTransport -in @('Timeout','Disconnect','Malformed')) {
        $Attempt.TransportClass='Indeterminate'
    } else {
        try { $response=$RawResponseJson | ConvertFrom-Json -ErrorAction Stop }
        catch {
            $Attempt.TransportClass='Indeterminate'
            $Attempt.Status='TRANSPORT_CLASSIFIED'
            Set-UID0002PAAttemptSeal $Attempt
            return $Attempt
        }
        if (($response.PSObject.Properties['error'] -and $null -ne $response.error) -or
            -not $response.PSObject.Properties['result'] -or $null -eq $response.result -or
            $response.result.isError -eq $true -or -not $response.result.PSObject.Properties['structuredContent']) {
            $Attempt.TransportClass='DeterminateFailure'
        } else {
            $save=$response.result.structuredContent
            if ($save.ok -eq $true -and [string]::IsNullOrWhiteSpace([string]$save.error) -and
                [System.IO.Path]::GetFullPath([string]$save.path) -ieq [string]$Attempt.CanonicalPath) {
                $Attempt.TransportClass='DeterminateSuccess'
            } else { $Attempt.TransportClass='DeterminateFailure' }
        }
    }
    $Attempt.Status='TRANSPORT_CLASSIFIED'
    Set-UID0002PAAttemptSeal $Attempt
    return $Attempt
}

function Assert-UID0002PARoleRetired {
    param(
        [Parameter(Mandatory=$true)]$RoleBinding,
        [Parameter(Mandatory=$true)]$AttestationState,
        [Parameter(Mandatory=$true)]$ListEnvelope)

    $list=Get-UID0002PAStructuredContent $ListEnvelope 'retirement idb_list'
    $identity=$AttestationState.RoleWorkers[[string]$RoleBinding.Database]
    if ($null -eq $identity) { throw 'SV-PA missing attested role worker identity' }
    $rows=@($list.sessions | Where-Object {[string]$_.session_id -ceq [string]$RoleBinding.Database})
    if ($rows.Count -ne 1 -or $rows[0].is_active -ne $false -or
        [int]$rows[0].worker_pid -ne [int]$identity.RedirectorPid) { throw 'SV-PA role row is not exact inactive route' }
    foreach ($pid in @([int]$identity.RedirectorPid,[int]$identity.WorkerPid)) {
        if (@(Get-CimInstance Win32_Process -Filter "ProcessId=$pid" -ErrorAction Stop).Count -ne 0) {
            throw "SV-PA retired PID still exists: $pid"
        }
        if (@(Get-NetTCPConnection -State Listen -ErrorAction SilentlyContinue | Where-Object {[int]$_.OwningProcess -eq $pid}).Count -ne 0) {
            throw "SV-PA retired PID still owns listener: $pid"
        }
    }
    if (@($list.sessions | Where-Object {
        $_.is_active -eq $true -and
        [System.IO.Path]::GetFullPath([string]$_.input_path) -ieq [string]$RoleBinding.CanonicalPath
    }).Count -ne 0) { throw 'SV-PA active canonical session remains' }
    $first=Get-UID0002PAExclusiveTuple $RoleBinding.CanonicalPath
    $second=Get-UID0002PAExclusiveTuple $RoleBinding.CanonicalPath
    Assert-UID0002PATuple $second $first 'SV-PA stable closed disk'
    [pscustomobject][ordered]@{
        Database=[string]$RoleBinding.Database
        ClosedTupleA=Get-UID0002PATupleCopy $first
        ClosedTupleB=Get-UID0002PATupleCopy $second
        RedirectorPid=[int]$identity.RedirectorPid
        WorkerPid=[int]$identity.WorkerPid
    }
}

function Complete-UID0002PADiskClassification {
    param([Parameter(Mandatory=$true)]$Attempt,[Parameter(Mandatory=$true)]$RetirementProof)
    Assert-UID0002PAAttemptSeal $Attempt
    if ($Attempt.Status -cne 'TRANSPORT_CLASSIFIED' -or [int]$Attempt.DispatchCount -ne 1) { throw 'SV-PA disk classification out of order' }
    Assert-UID0002PATuple $RetirementProof.ClosedTupleB $RetirementProof.ClosedTupleA 'SV-PA stable post-save disk'
    if ([string]$RetirementProof.Database -cne [string]$Attempt.Database) { throw 'SV-PA retirement database mismatch' }

    $candidate=$RetirementProof.ClosedTupleA
    $isP0=$true
    foreach ($property in 'FullPath','Length','LastWriteTimeUtcTicks','SHA256') {
        if ([string]$candidate.$property -cne [string]$Attempt.P0.$property) { $isP0=$false }
    }
    if ($isP0) {
        $Attempt.DiskClass='P0'
        $Attempt.Status='P0_VERIFIER_REQUIRED'
    } else {
        if ([System.IO.Path]::GetFullPath([string]$candidate.FullPath) -ine [string]$Attempt.CanonicalPath) {
            throw 'SV-PA changed tuple is not canonical'
        }
        $Attempt.AttributableTuple=Get-UID0002PATupleCopy $candidate
        $Attempt.DiskClass='SOLE_SAVE_ATTRIBUTABLE_S1_OR_F1'
        $Attempt.Status='S1_VERIFIER_REQUIRED'
    }
    Set-UID0002PAAttemptSeal $Attempt
    return [pscustomobject][ordered]@{
        TransportClass=[string]$Attempt.TransportClass
        DiskClass=[string]$Attempt.DiskClass
        RequiredVerifier=if($Attempt.Status -ceq 'P0_VERIFIER_REQUIRED'){'P0Verifier'}else{'S1Verifier'}
    }
}

function Complete-UID0002PAPreSaveFailure {
    param([Parameter(Mandatory=$true)]$BackupState,[Parameter(Mandatory=$true)]$RetirementProof)
    Assert-UID0002PATuple $RetirementProof.ClosedTupleA $BackupState.P0 'pre-save failure disk P0'
    Assert-UID0002PATuple $RetirementProof.ClosedTupleB $BackupState.P0 'pre-save failure stable P0'
    Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $BackupState.B0.FullPath) $BackupState.B0 'pre-save failure intact B0'
    [pscustomobject]@{Status='NO_SAVE_P0_VERIFIER_REQUIRED';RequiredVerifier='P0Verifier'}
}

function Complete-UID0002PAVerifier {
    param(
        [Parameter(Mandatory=$true)]$Attempt,
        [Parameter(Mandatory=$true)]$VerifierReadback,
        [Parameter(Mandatory=$true)]$VerifierRetirementProof)

    Assert-UID0002PAAttemptSeal $Attempt
    if ($VerifierReadback.Passed -ne $true) { throw 'VR-PA verifier catalog did not pass' }
    if ($Attempt.Status -ceq 'P0_VERIFIER_REQUIRED') {
        if ([string]$VerifierReadback.Phase -cne 'P0Verifier') { throw 'VR-PA wrong P0 verifier phase' }
        Assert-UID0002PATuple $VerifierRetirementProof.ClosedTupleA $Attempt.P0 'VR-PA P0 verifier closed disk'
        Assert-UID0002PATuple $VerifierRetirementProof.ClosedTupleB $Attempt.P0 'VR-PA P0 verifier stable disk'
        $Attempt.Status="NOT_PERSISTED_P0_VERIFIED_$($Attempt.TransportClass.ToUpperInvariant())"
    } elseif ($Attempt.Status -ceq 'S1_VERIFIER_REQUIRED') {
        if ([string]$VerifierReadback.Phase -cne 'S1Verifier' -or $null -eq $Attempt.AttributableTuple) {
            throw 'VR-PA wrong/missing S1 verifier authority'
        }
        Assert-UID0002PATuple $VerifierRetirementProof.ClosedTupleA $Attempt.AttributableTuple 'VR-PA S1 verifier closed disk'
        Assert-UID0002PATuple $VerifierRetirementProof.ClosedTupleB $Attempt.AttributableTuple 'VR-PA S1 verifier stable disk'
        $Attempt.Status="PERSISTED_S1_VERIFIED_$($Attempt.TransportClass.ToUpperInvariant())"
    } else { throw 'VR-PA verifier called from invalid branch' }
    Set-UID0002PAAttemptSeal $Attempt
    return $Attempt
}

function Set-UID0002PAVerifierFailure {
    param([Parameter(Mandatory=$true)]$Attempt,[Parameter(Mandatory=$true)][string]$ExactFailure)
    Assert-UID0002PAAttemptSeal $Attempt
    if ($Attempt.Status -cne 'S1_VERIFIER_REQUIRED' -or $null -eq $Attempt.AttributableTuple -or
        [string]::IsNullOrWhiteSpace($ExactFailure)) { throw 'VR-PA invalid F1 transition' }
    $fresh=Get-UID0002PAExclusiveTuple $Attempt.CanonicalPath
    Assert-UID0002PATuple $fresh $Attempt.AttributableTuple 'VR-PA F1 still sole-save attributable'
    $Attempt.Status='F1_RESTORE_REQUIRED'
    Set-UID0002PAAttemptSeal $Attempt
    return [pscustomobject]@{Status=$Attempt.Status;Failure=$ExactFailure;AttributableTuple=Get-UID0002PATupleCopy $fresh}
}

function Restore-UID0002PABackup {
    param([Parameter(Mandatory=$true)]$Attempt)
    Assert-UID0002PAAttemptSeal $Attempt
    if ($Attempt.Status -cne 'F1_RESTORE_REQUIRED' -or $null -eq $Attempt.AttributableTuple) {
        throw 'RS-PA restore lacks internally classified F1 authority'
    }

    $freshCanonical=Get-UID0002PAExclusiveTuple $Attempt.CanonicalPath
    Assert-UID0002PATuple $freshCanonical $Attempt.AttributableTuple 'RS-PA immediate pre-restore attributable F1'
    Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $Attempt.B0.FullPath) $Attempt.B0 'RS-PA intact B0'

    $source=$null
    $destination=$null
    try {
        $source=[System.IO.FileStream]::new($Attempt.B0.FullPath,[System.IO.FileMode]::Open,[System.IO.FileAccess]::Read,[System.IO.FileShare]::None)
        $destination=[System.IO.FileStream]::new($Attempt.CanonicalPath,[System.IO.FileMode]::Open,[System.IO.FileAccess]::ReadWrite,[System.IO.FileShare]::None)
        if ($source.Length -ne $Attempt.P0.Length -or (Get-UID0002PAStreamSha256 $source) -cne $Attempt.P0.SHA256) {
            throw 'RS-PA exclusive B0 differs from P0'
        }
        if ($destination.Length -ne $Attempt.AttributableTuple.Length -or
            (Get-UID0002PAStreamSha256 $destination) -cne $Attempt.AttributableTuple.SHA256) {
            throw 'RS-PA exclusive canonical is third identity'
        }
        $source.Position=0
        $destination.SetLength(0)
        $destination.Position=0
        $buffer=New-Object byte[] 1048576
        $copied=[long]0
        while (($read=$source.Read($buffer,0,$buffer.Length)) -gt 0) {
            $destination.Write($buffer,0,$read)
            $copied += $read
        }
        if ($copied -ne $Attempt.P0.Length -or $source.Position -ne $Attempt.P0.Length -or $source.ReadByte() -ne -1) {
            throw 'RS-PA source count/position/EOF mismatch'
        }
        if ($destination.Position -ne $Attempt.P0.Length -or $destination.Length -ne $Attempt.P0.Length) {
            throw 'RS-PA destination position/length mismatch'
        }
        $destination.Flush($true)
    } finally {
        if ($null -ne $destination) { $destination.Dispose() }
        if ($null -ne $source) { $source.Dispose() }
    }
    [System.IO.File]::SetLastWriteTimeUtc(
        $Attempt.CanonicalPath,
        [DateTime]::new([long]$Attempt.P0.LastWriteTimeUtcTicks,[DateTimeKind]::Utc))
    Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $Attempt.CanonicalPath) $Attempt.P0 'RS-PA closed restored P0'
    Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $Attempt.CanonicalPath) $Attempt.P0 'RS-PA reopened restored P0'
    Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $Attempt.B0.FullPath) $Attempt.B0 'RS-PA post-restore B0'
    $Attempt.Status='ROLLBACK_VERIFIER_REQUIRED'
    Set-UID0002PAAttemptSeal $Attempt
    return $Attempt
}

function Complete-UID0002PARollbackVerifier {
    param(
        [Parameter(Mandatory=$true)]$Attempt,
        [Parameter(Mandatory=$true)]$RollbackReadback,
        [Parameter(Mandatory=$true)]$RollbackRetirementProof)

    Assert-UID0002PAAttemptSeal $Attempt
    if ($Attempt.Status -cne 'ROLLBACK_VERIFIER_REQUIRED' -or
        $RollbackReadback.Passed -ne $true -or [string]$RollbackReadback.Phase -cne 'RollbackVerifier') {
        throw 'RS-PA rollback verifier state mismatch'
    }
    Assert-UID0002PATuple $RollbackRetirementProof.ClosedTupleA $Attempt.P0 'RS-PA rollback verifier closed P0'
    Assert-UID0002PATuple $RollbackRetirementProof.ClosedTupleB $Attempt.P0 'RS-PA rollback verifier stable P0'
    Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $Attempt.CanonicalPath) $Attempt.P0 'RS-PA final closed P0 first'
    Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $Attempt.CanonicalPath) $Attempt.P0 'RS-PA final closed P0 second'
    $Attempt.Status="RESTORED_P0_VERIFIED_$($Attempt.TransportClass.ToUpperInvariant())"
    Set-UID0002PAAttemptSeal $Attempt
    return $Attempt
}
~~~

## Removed Block R011

- SHA256: `4B46AAEF08B36B1E8041F999A13D3614B3AC1B4E4AC7EDEAE8CF3830722FEB3D`
- Language: `powershell`
- Bytes: `19072`
- First recovered timestamp: `2026-08-07T01:07:18.620Z`
- Session provenance: rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 195511 (2026-08-07T01:07:18.620Z); rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 195512 (2026-08-07T01:07:18.670Z)

~~~powershell
function Initialize-UID0002PAJsonDuplicateGuard {
    if ('UID0002PAJsonDuplicateGuard' -as [type]) { return }
    Add-Type -TypeDefinition @'
using System;
using System.Collections.Generic;

public static class UID0002PAJsonDuplicateGuard {
    private sealed class Parser {
        private readonly string text;
        private int index;
        internal Parser(string value) { text = value ?? throw new ArgumentNullException("value"); }
        internal void Parse() { Skip(); Value(); Skip(); if (index != text.Length) Fail("trailing data"); }
        private void Skip() { while (index < text.Length && char.IsWhiteSpace(text[index])) index++; }
        private void Fail(string message) { throw new FormatException("JSON_SYNTAX:" + message + "@" + index); }
        private void Value() {
            Skip(); if (index >= text.Length) Fail("missing value");
            char c = text[index];
            if (c == '{') { Object(); return; }
            if (c == '[') { Array(); return; }
            if (c == '"') { String(); return; }
            if (c == 't') { Literal("true"); return; }
            if (c == 'f') { Literal("false"); return; }
            if (c == 'n') { Literal("null"); return; }
            Number();
        }
        private void Object() {
            index++; Skip(); var names = new HashSet<string>(StringComparer.Ordinal);
            if (Take('}')) return;
            while (true) {
                Skip(); if (index >= text.Length || text[index] != '"') Fail("object key");
                string key = String();
                if (!names.Add(key)) throw new FormatException("JSON_DUPLICATE_MEMBER:" + key);
                Skip(); if (!Take(':')) Fail("missing colon"); Value(); Skip();
                if (Take('}')) return; if (!Take(',')) Fail("missing object comma");
            }
        }
        private void Array() {
            index++; Skip(); if (Take(']')) return;
            while (true) { Value(); Skip(); if (Take(']')) return; if (!Take(',')) Fail("missing array comma"); }
        }
        private bool Take(char value) { if (index < text.Length && text[index] == value) { index++; return true; } return false; }
        private string String() {
            if (!Take('"')) Fail("string open"); var value = new System.Text.StringBuilder();
            while (index < text.Length) {
                char c = text[index++]; if (c == '"') return value.ToString();
                if (c < 0x20) Fail("control in string");
                if (c != '\\') { value.Append(c); continue; }
                if (index >= text.Length) Fail("escape eof"); char e = text[index++];
                switch (e) {
                    case '"': value.Append('"'); break; case '\\': value.Append('\\'); break; case '/': value.Append('/'); break;
                    case 'b': value.Append('\b'); break; case 'f': value.Append('\f'); break; case 'n': value.Append('\n'); break;
                    case 'r': value.Append('\r'); break; case 't': value.Append('\t'); break;
                    case 'u':
                        if (index + 4 > text.Length) Fail("unicode eof");
                        int code; if (!Int32.TryParse(text.Substring(index,4),System.Globalization.NumberStyles.HexNumber,null,out code)) Fail("unicode");
                        value.Append((char)code); index += 4; break;
                    default: Fail("escape"); break;
                }
            }
            Fail("string eof"); return null;
        }
        private void Literal(string literal) {
            if (index + literal.Length > text.Length || String.CompareOrdinal(text,index,literal,0,literal.Length) != 0) Fail("literal");
            index += literal.Length;
        }
        private void Number() {
            int start=index; if (Take('-')) { }
            if (Take('0')) { } else { if (index>=text.Length || text[index]<'1' || text[index]>'9') Fail("number"); while(index<text.Length && char.IsDigit(text[index])) index++; }
            if (Take('.')) { if(index>=text.Length || !char.IsDigit(text[index])) Fail("fraction"); while(index<text.Length && char.IsDigit(text[index])) index++; }
            if(index<text.Length && (text[index]=='e' || text[index]=='E')) { index++; if(index<text.Length && (text[index]=='+' || text[index]=='-')) index++; if(index>=text.Length || !char.IsDigit(text[index])) Fail("exponent"); while(index<text.Length && char.IsDigit(text[index])) index++; }
            if(index==start) Fail("number");
        }
    }
    public static void AssertNoDuplicates(string json) { new Parser(json).Parse(); }
}
'@
}

function Assert-UID0002PARawJsonUnique {
    param([Parameter(Mandatory=$true)][string]$Json,[Parameter(Mandatory=$true)][string]$Label)
    Initialize-UID0002PAJsonDuplicateGuard
    try { [UID0002PAJsonDuplicateGuard]::AssertNoDuplicates($Json) }
    catch { throw "$Label raw JSON rejected: $($_.Exception.GetBaseException().Message)" }
}

function Test-UID0002PAJsonInteger { param($Value) $Value -is [int] -or $Value -is [long] }
function Test-UID0002PAJsonBoolean { param($Value) $Value -is [bool] }
function Test-UID0002PAJsonString { param($Value) $Value -is [string] }

function Get-UID0002PARequestIdentity {
    param([Parameter(Mandatory=$true)][string]$RequestJson,[Parameter(Mandatory=$true)][string]$Label)
    Assert-UID0002PARawJsonUnique $RequestJson $Label
    $request=$RequestJson|ConvertFrom-Json -ErrorAction Stop
    $root=@($request.PSObject.Properties.Name|Sort-Object)
    if(($root-join '|') -cne 'id|jsonrpc|method|params' -or -not (Test-UID0002PAJsonString $request.jsonrpc) -or
        [string]$request.jsonrpc -cne '2.0' -or -not (Test-UID0002PAJsonString $request.method) -or
        ($request.id -is [bool]) -or (-not (Test-UID0002PAJsonString $request.id) -and -not (Test-UID0002PAJsonInteger $request.id))){
        throw "$Label invalid native JSON-RPC request root/id"
    }
    if([string]$request.method -ceq 'tools/list'){
        if(@($request.params.PSObject.Properties).Count -ne 0){throw "$Label tools/list params mismatch"}
    }elseif([string]$request.method -ceq 'tools/call'){
        if((@($request.params.PSObject.Properties.Name|Sort-Object)-join '|') -cne 'arguments|name' -or
            -not (Test-UID0002PAJsonString $request.params.name) -or $null -eq $request.params.arguments){
            throw "$Label tools/call params mismatch"
        }
    }else{throw "$Label unexpected JSON-RPC method"}
    [pscustomobject][ordered]@{Json=$RequestJson;Parsed=$request;Id=$request.id;IdType=$request.id.GetType().FullName;SHA256=Get-UID0002PATextSha256 $RequestJson}
}

function Assert-UID0002PAJsonRpcResponse {
    param(
        [Parameter(Mandatory=$true)]$Envelope,
        [Parameter(Mandatory=$true)][string]$RequestJson,
        [Parameter(Mandatory=$true)][string]$Label,
        [bool]$RequireStructuredContent=$true,
        [AllowNull()][string]$RawEnvelopeJson)
    if(-not [string]::IsNullOrWhiteSpace($RawEnvelopeJson)){Assert-UID0002PARawJsonUnique $RawEnvelopeJson $Label}
    $request=Get-UID0002PARequestIdentity $RequestJson "$Label request"
    $keys=@($Envelope.PSObject.Properties.Name|Sort-Object)
    if(($keys-join '|') -ceq 'error|id|jsonrpc') { throw "$Label JSON-RPC error response" }
    if(($keys-join '|') -cne 'id|jsonrpc|result' -or -not (Test-UID0002PAJsonString $Envelope.jsonrpc) -or
        [string]$Envelope.jsonrpc -cne '2.0' -or $null -eq $Envelope.id -or
        $Envelope.id.GetType().FullName -cne $request.IdType -or -not [object]::Equals($Envelope.id,$request.Id) -or $null -eq $Envelope.result){
        throw "$Label JSON-RPC identity/result mismatch"
    }
    if([string]$request.Parsed.method -ceq 'tools/call'){
        if(-not $Envelope.result.PSObject.Properties['isError'] -or -not (Test-UID0002PAJsonBoolean $Envelope.result.isError)){
            throw "$Label missing/non-Boolean isError"
        }
        if($Envelope.result.isError -eq $true){throw "$Label tool result isError"
        }
        if($RequireStructuredContent -and (-not $Envelope.result.PSObject.Properties['structuredContent'] -or $null -eq $Envelope.result.structuredContent)){
            throw "$Label missing structuredContent"
        }
        if($RequireStructuredContent){return $Envelope.result.structuredContent}
    }
    return $Envelope.result
}

function ConvertTo-UID0002PASchemaAuthorityNode {
    param([Parameter(Mandatory=$true)]$Node,[Parameter(Mandatory=$true)][string]$Label)
    $metadata=@('title','description')
    $authority=@('type','properties','required','additionalProperties','default','items','anyOf','allOf','oneOf','$ref','$defs','definitions','enum','const','minimum','maximum','minItems','maxItems','pattern','format')
    foreach($name in @($Node.PSObject.Properties.Name)){if($name -notin $metadata -and $name -notin $authority){throw "$Label unexpected schema keyword $name"}}
    $out=[ordered]@{}
    foreach($name in @($Node.PSObject.Properties.Name|Where-Object{$_ -notin $metadata}|Sort-Object)){
        $value=$Node.$name
        switch($name){
            'properties' {$children=[ordered]@{};foreach($child in @($value.PSObject.Properties.Name|Sort-Object)){$children[$child]=ConvertTo-UID0002PASchemaAuthorityNode $value.$child "$Label.$child"};$out[$name]=$children}
            'required' {$out[$name]=@($value|ForEach-Object{[string]$_}|Sort-Object)}
            'items' {$out[$name]=ConvertTo-UID0002PASchemaAuthorityNode $value "$Label[]"}
            {$_ -in @('anyOf','allOf','oneOf')} {$nodes=@($value|ForEach-Object{ConvertTo-UID0002PASchemaAuthorityNode $_ "$Label.$name"});$out[$name]=@($nodes|Sort-Object{$_|ConvertTo-Json -Depth 50 -Compress})}
            {$_ -in @('$defs','definitions')} {$children=[ordered]@{};foreach($child in @($value.PSObject.Properties.Name|Sort-Object)){$children[$child]=ConvertTo-UID0002PASchemaAuthorityNode $value.$child "$Label.$name.$child"};$out[$name]=$children}
            default {$out[$name]=$value}
        }
    }
    [pscustomobject]$out
}

function New-UID0002PAExpectedSchemaAuthority {
    param([Parameter(Mandatory=$true)]$Contract)
    $properties=[ordered]@{};$required=@()
    foreach($name in @($Contract.Properties.Keys|Sort-Object)){
        $pc=$Contract.Properties[$name];$node=[ordered]@{}
        if(@($pc.Types).Count -eq 1){$node.type=[string]$pc.Types[0]}
        else{$node.anyOf=@($pc.Types|Sort-Object|ForEach-Object{[ordered]@{type=[string]$_}})}
        if($pc.DefaultState -ceq 'Present'){$node.default=$pc.DefaultValue}
        $properties[$name]=[pscustomobject]$node;if($pc.Required){$required+=$name}
    }
    $root=[ordered]@{type='object';properties=[pscustomobject]$properties;required=@($required|Sort-Object)}
    if($Contract.AdditionalProperties -cne 'Absent'){$root.additionalProperties=($Contract.AdditionalProperties -ceq 'True')}
    [pscustomobject]$root
}

function Assert-UID0002PAToolSchemaContract {
    param([Parameter(Mandatory=$true)]$Tool,[Parameter(Mandatory=$true)]$Contract)
    $actual=ConvertTo-UID0002PASchemaAuthorityNode $Tool.inputSchema "S-PA $($Tool.name)"
    $expected=ConvertTo-UID0002PASchemaAuthorityNode (New-UID0002PAExpectedSchemaAuthority $Contract) "S-PA expected $($Tool.name)"
    $actualJson=$actual|ConvertTo-Json -Depth 80 -Compress;$expectedJson=$expected|ConvertTo-Json -Depth 80 -Compress
    $actualDigest=Get-UID0002PATextSha256 $actualJson;$expectedDigest=Get-UID0002PATextSha256 $expectedJson
    if($actualDigest -cne $expectedDigest){throw "S-PA $($Tool.name) recursive authority-schema digest mismatch"}
    [pscustomobject]@{Tool=[string]$Tool.name;Digest=$actualDigest;Passed=$true}
}

function Assert-UID0002PALiteralRoleOpenRequest {
    param([Parameter(Mandatory=$true)][ValidateSet('Transaction','P0Verifier','S1Verifier','RollbackVerifier')][string]$Role,[Parameter(Mandatory=$true)][string]$RequestJson)
    $request=Get-UID0002PARequestIdentity $RequestJson "$Role literal idb_open";$arguments=$request.Parsed.params.arguments
    $slug=@{Transaction='transaction';P0Verifier='p0-verifier';S1Verifier='s1-verifier';RollbackVerifier='rollback-verifier'}[$Role]
    if([string]$request.Parsed.method -cne 'tools/call' -or [string]$request.Parsed.params.name -cne 'idb_open' -or
        (@($arguments.PSObject.Properties.Name|Sort-Object)-join '|') -cne 'build_caches|idle_ttl_sec|init_hexrays|input_path|mode|preferred_session_id|run_auto_analysis' -or
        -not (Test-UID0002PAJsonString $arguments.input_path) -or -not (Test-UID0002PAJsonString $arguments.mode) -or
        -not (Test-UID0002PAJsonString $arguments.preferred_session_id) -or -not (Test-UID0002PAJsonBoolean $arguments.run_auto_analysis) -or
        -not (Test-UID0002PAJsonBoolean $arguments.build_caches) -or -not (Test-UID0002PAJsonBoolean $arguments.init_hexrays) -or
        -not (Test-UID0002PAJsonInteger $arguments.idle_ttl_sec) -or
        [System.IO.Path]::GetFullPath($arguments.input_path) -ine [System.IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64') -or
        $arguments.mode -cne 'force_headless' -or $arguments.run_auto_analysis -ne $false -or $arguments.build_caches -ne $false -or
        $arguments.init_hexrays -ne $false -or $arguments.idle_ttl_sec -ne 600 -or
        $arguments.preferred_session_id -notmatch "^b010-uid0002pa-$slug-[0-9]{8}-[0-9]{6}-r[1-9][0-9]*-[0-9a-f]{32}$" -or
        [string]$request.Id -cne "uid0002pa-open-$slug-$($arguments.preferred_session_id.Substring(("b010-uid0002pa-$slug-").Length))"){
        throw "$Role literal idb_open options/types/prefix mismatch"
    }
    $request
}

function Assert-UID0002PAOpenAndRuntimeNativeFields {
    param($OpenContent,$ListContent,$RuntimeContent,[string]$Label)
    if(-not $OpenContent.PSObject.Properties['success'] -or -not (Test-UID0002PAJsonBoolean $OpenContent.success)){throw "$Label open success native type mismatch"}
    $sessions=@($OpenContent.session);if($sessions.Count -ne 1){throw "$Label open session cardinality mismatch"}
    $session=$sessions[0]
    if(-not $session.PSObject.Properties['is_analyzing'] -or -not (Test-UID0002PAJsonBoolean $session.is_analyzing) -or
        -not (Test-UID0002PAJsonString $session.session_id) -or -not (Test-UID0002PAJsonString $session.input_path)){
        throw "$Label open session native fields mismatch"
    }
    foreach($row in @($ListContent.sessions)){
        if(-not (Test-UID0002PAJsonString $row.session_id) -or -not (Test-UID0002PAJsonString $row.input_path) -or
            -not (Test-UID0002PAJsonBoolean $row.is_active) -or -not (Test-UID0002PAJsonInteger $row.worker_pid)){
            throw "$Label list session native fields mismatch"
        }
    }
    if(-not (Test-UID0002PAJsonInteger $RuntimeContent.schema_version) -or -not (Test-UID0002PAJsonBoolean $RuntimeContent.ok) -or
        -not (Test-UID0002PAJsonInteger $RuntimeContent.listener.process.pid) -or
        -not (Test-UID0002PAJsonInteger $RuntimeContent.listener.process.creation_time_100ns)){
        throw "$Label runtime top native fields mismatch"
    }
    foreach($entry in @($RuntimeContent.workers)){
        $worker=$entry.attestation.worker
        if(-not (Test-UID0002PAJsonInteger $entry.route.port) -or -not (Test-UID0002PAJsonInteger $worker.process.pid) -or
            -not (Test-UID0002PAJsonInteger $worker.process.parent_pid) -or -not (Test-UID0002PAJsonInteger $worker.process.creation_time_100ns)){
            throw "$Label runtime worker PID/port native fields mismatch"
        }
        foreach($row in @($entry.supervisor_sessions)){
            if(-not (Test-UID0002PAJsonInteger $row.redirector_pid) -or -not (Test-UID0002PAJsonInteger $row.registered_pid)){
                throw "$Label runtime redirector PID native fields mismatch"
            }
        }
    }
}

$script:UID0002PAOriginalModuleManifest = ${function:Assert-UID0002PAModuleManifest}
function Get-UID0002PAModuleRowsDigest {
    param([Parameter(Mandatory=$true)]$Owner)
    $rows=@($Owner.modules|ForEach-Object{[ordered]@{
        sys_modules_name=[string]$_.sys_modules_name;file=[System.IO.Path]::GetFullPath([string]$_.file)
        spec_origin=[System.IO.Path]::GetFullPath([string]$_.spec_origin);resolved_path=[System.IO.Path]::GetFullPath([string]$_.resolved_path)
        size=[long]$_.size;mtime_ns=[long]$_.mtime_ns;ctime_ns=[long]$_.ctime_ns;sha256=[string]$_.sha256
    }})
    Get-UID0002PATextSha256 (ConvertTo-Json -InputObject $rows -Depth 20 -Compress)
}
function Assert-UID0002PAModuleManifest {
    param([Parameter(Mandatory=$true)]$Owner,[Parameter(Mandatory=$true)][ValidateSet('listener','worker')][string]$Role,[Parameter(Mandatory=$true)][string]$Label)
    $result=& $script:UID0002PAOriginalModuleManifest -Owner $Owner -Role $Role -Label $Label
    $computed=Get-UID0002PAModuleRowsDigest $Owner
    if([string]$Owner.implementation_manifest_sha256 -cne $computed){throw "$Label module-row aggregate digest mismatch"}
    return $result
}

$script:UID0002PAOriginalRuntimeAttestation = ${function:Assert-UID0002PARuntimeAttestation}
function Assert-UID0002PARuntimeAttestation {
    param($Envelope,[string]$AttestationRequestJson,$ListEnvelope,[string]$ListRequestJson,$RoleBinding,$State)
    $runtime=Get-UID0002PAStructuredContent $Envelope $AttestationRequestJson 'RA-PA native preflight'
    $list=Get-UID0002PAStructuredContent $ListEnvelope $ListRequestJson 'RA-PA native list preflight'
    $open=[pscustomobject]@{success=$true;session=[pscustomobject]@{session_id=[string]$RoleBinding.Database;input_path=[string]$RoleBinding.CanonicalPath;is_analyzing=$false}}
    Assert-UID0002PAOpenAndRuntimeNativeFields $open $list $runtime 'RA-PA'
    & $script:UID0002PAOriginalRuntimeAttestation @PSBoundParameters
}

$script:UID0002PAOriginalPostRetirementAttestation = ${function:Assert-UID0002PAPostRetirementAttestation}
function Assert-UID0002PAPostRetirementAttestation {
    param($Envelope,[string]$RequestJson,$RoleBinding,$State)
    $request=Get-UID0002PARequestIdentity $RequestJson 'RA-PA post-retirement strict request'
    if([string]$request.Parsed.method -cne 'tools/call' -or [string]$request.Parsed.params.name -cne 'runtime_attestation'){
        throw 'RA-PA post-retirement request method mismatch'
    }
    & $script:UID0002PAOriginalPostRetirementAttestation @PSBoundParameters
}

function New-UID0002PAClosedControllerContext { throw 'CT-PA direct controller construction disabled' }
function Invoke-UID0002PAControllerRequest { throw 'CT-PA direct dispatch disabled' }
function New-UID0002PASaveAttempt { throw 'SV-PA public save-attempt construction disabled' }
function Register-UID0002PASoleSaveDispatch { throw 'SV-PA public save registration disabled' }
function Complete-UID0002PASaveTransport { throw 'SV-PA public save classifier disabled' }
function Complete-UID0002PADiskClassification { throw 'SV-PA public disk classifier disabled' }
function Restore-UID0002PABackup { throw 'RS-PA public restore disabled' }
function Set-UID0002PAVerifierFailure { throw 'VR-PA public F1 transition disabled' }
~~~

## Removed Block R012

- SHA256: `6E6E940F30AF76B3403785EB8CCD406D3A6FD63FCF9684B1E5E9507F050748FE`
- Language: `powershell`
- Bytes: `16863`
- First recovered timestamp: `2026-08-07T01:09:03.746Z`
- Session provenance: rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 195519 (2026-08-07T01:09:03.746Z); rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 195520 (2026-08-07T01:09:03.818Z)

~~~powershell
function Assert-UID0002PAExactSaveRequest {
    param([Parameter(Mandatory=$true)][string]$RequestJson,[Parameter(Mandatory=$true)][string]$Database,[Parameter(Mandatory=$true)][string]$CanonicalPath)
    $request=Get-UID0002PARequestIdentity $RequestJson 'SV2-PA exact save request';$args=$request.Parsed.params.arguments
    if([string]$request.Parsed.method -cne 'tools/call' -or [string]$request.Parsed.params.name -cne 'idb_save' -or
        (@($args.PSObject.Properties.Name|Sort-Object)-join '|') -cne 'database|path' -or
        -not (Test-UID0002PAJsonString $args.database) -or -not (Test-UID0002PAJsonString $args.path) -or
        [string]$args.database -cne $Database -or [System.IO.Path]::GetFullPath([string]$args.path) -ine [System.IO.Path]::GetFullPath($CanonicalPath)){
        throw 'SV2-PA exact save request mismatch'
    }
    $request
}

function Resolve-UID0002PASaveTransportOutcome {
    param(
        [Parameter(Mandatory=$true)][string]$RequestJson,
        [Parameter(Mandatory=$true)][ValidateSet('Response','Timeout','Disconnect','Malformed','ThrownTransport','MissingResponse')][string]$ObservedTransport,
        [AllowNull()][string]$RawResponseJson,
        [AllowNull()][string]$ThrownFailure)
    $request=Get-UID0002PARequestIdentity $RequestJson 'SV2-PA classified save'
    if($ObservedTransport -ne 'Response'){
        return [pscustomobject][ordered]@{TransportClass='Indeterminate';Observation=$ObservedTransport;Failure=if($ThrownFailure){$ThrownFailure}else{$ObservedTransport};Envelope=$null}
    }
    try{
        if([string]::IsNullOrWhiteSpace($RawResponseJson)){throw 'SV2-PA missing response body'}
        Assert-UID0002PARawJsonUnique $RawResponseJson 'SV2-PA save response'
        $response=$RawResponseJson|ConvertFrom-Json -ErrorAction Stop
        $keys=@($response.PSObject.Properties.Name|Sort-Object)
        if(-not (Test-UID0002PAJsonString $response.jsonrpc) -or [string]$response.jsonrpc -cne '2.0' -or
            $null -eq $response.id -or $response.id.GetType().FullName -cne $request.IdType -or -not [object]::Equals($response.id,$request.Id)){
            throw 'SV2-PA foreign response identity'
        }
        if(($keys-join '|') -ceq 'error|id|jsonrpc'){
            return [pscustomobject][ordered]@{TransportClass='Indeterminate';Observation='JsonRpcError';Failure=($response.error|ConvertTo-Json -Depth 12 -Compress);Envelope=$response}
        }
        if(($keys-join '|') -cne 'id|jsonrpc|result' -or $null -eq $response.result -or
            -not $response.result.PSObject.Properties['isError'] -or -not (Test-UID0002PAJsonBoolean $response.result.isError)){
            throw 'SV2-PA malformed native result'
        }
        if($response.result.isError -eq $true){
            return [pscustomobject][ordered]@{TransportClass='DeterminateFailure';Observation='ToolIsError';Failure='idb_save result isError';Envelope=$response}
        }
        $save=$response.result.structuredContent
        if($null -eq $save -or -not $save.PSObject.Properties['ok'] -or -not (Test-UID0002PAJsonBoolean $save.ok) -or
            -not $save.PSObject.Properties['error'] -or -not (Test-UID0002PAJsonString $save.error) -or
            -not $save.PSObject.Properties['path'] -or -not (Test-UID0002PAJsonString $save.path)){
            throw 'SV2-PA malformed native structuredContent'
        }
        $canonical=[System.IO.Path]::GetFullPath([string]$request.Parsed.params.arguments.path)
        if($save.ok -eq $true -and [string]::IsNullOrWhiteSpace($save.error) -and [System.IO.Path]::GetFullPath($save.path) -ieq $canonical){
            return [pscustomobject][ordered]@{TransportClass='DeterminateSuccess';Observation='Response';Failure=$null;Envelope=$response}
        }
        if($save.ok -eq $false -and -not [string]::IsNullOrWhiteSpace($save.error)){
            return [pscustomobject][ordered]@{TransportClass='DeterminateFailure';Observation='Response';Failure=[string]$save.error;Envelope=$response}
        }
        return [pscustomobject][ordered]@{TransportClass='Indeterminate';Observation='ContradictoryResponse';Failure='SV2-PA contradictory save result';Envelope=$response}
    }catch{
        [pscustomobject][ordered]@{TransportClass='Indeterminate';Observation='MalformedOrForeignResponse';Failure=$_.Exception.Message;Envelope=$null}
    }
}

function Get-UID0002PAAttemptAuthorityText {
    param($Attempt)
    ([ordered]@{TransactionId=$Attempt.TransactionId;Database=$Attempt.Database;Generation=$Attempt.TransactionGeneration;CanonicalPath=$Attempt.CanonicalPath
        SaveRequestSHA256=$Attempt.SaveRequestSHA256;SaveDispatchCount=$Attempt.SaveDispatchCount;TransportClass=$Attempt.TransportClass
        DurableJournalSHA256=$Attempt.DurableJournalSHA256;FinalReadbackSHA256=$Attempt.FinalReadbackSHA256;P0=$Attempt.P0;B0=$Attempt.B0
        Candidate=$Attempt.Candidate;Status=$Attempt.Status}|ConvertTo-Json -Depth 30 -Compress)
}
function Set-UID0002PAAttemptAuthorityHmac { param($Attempt,[string]$EvidenceKey) $Attempt.AuthorityHmac=Get-UID0002PAEvidenceHmac (Get-UID0002PAAttemptAuthorityText $Attempt) $EvidenceKey }
function Assert-UID0002PAAttemptAuthorityHmac {
    param($Attempt,[string]$EvidenceKey)
    if([string]::IsNullOrWhiteSpace([string]$Attempt.AuthorityHmac) -or [string]$Attempt.AuthorityHmac -cne (Get-UID0002PAEvidenceHmac (Get-UID0002PAAttemptAuthorityText $Attempt) $EvidenceKey)){
        throw 'SV2-PA closed attempt HMAC mismatch'
    }
}
function Get-UID0002PARetirementAuthorityText { param($Authority) ([ordered]@{Proof=$Authority.Proof;TransactionId=$Authority.TransactionId;Role=$Authority.Role}|ConvertTo-Json -Depth 40 -Compress) }
function Assert-UID0002PARetirementAuthorityHmac {
    param($Authority,[string]$EvidenceKey)
    if([string]$Authority.AuthorityHmac -cne (Get-UID0002PAEvidenceHmac (Get-UID0002PARetirementAuthorityText $Authority) $EvidenceKey)){
        throw 'RT2-PA closed retirement HMAC mismatch'
    }
}

function Get-UID0002PAChangedDiskClassification {
    param($Attempt,$RetirementAuthority,[string]$EvidenceKey)
    Assert-UID0002PAAttemptAuthorityHmac $Attempt $EvidenceKey
    Assert-UID0002PARetirementAuthorityHmac $RetirementAuthority $EvidenceKey
    $proof=$RetirementAuthority.Proof
    Assert-UID0002PATuple $proof.ClosedTupleB $proof.ClosedTupleA 'CS2-PA stable closed candidate'
    if([string]$proof.Role -cne 'Transaction' -or [string]$proof.Database -cne [string]$Attempt.Database -or
        [string]$proof.Generation -cne [string]$Attempt.TransactionGeneration){throw 'CS2-PA retirement identity mismatch'}
    $candidate=Get-UID0002PATupleCopy $proof.ClosedTupleA
    $samePath=[System.IO.Path]::GetFullPath($candidate.FullPath) -ieq [System.IO.Path]::GetFullPath($Attempt.CanonicalPath)
    if(-not $samePath -or $candidate.Length -le 0 -or [string]$candidate.SHA256 -notmatch '^[0-9A-F]{64}$'){throw 'CS2-PA foreign/noncanonical candidate'}
    $sameLength=[long]$candidate.Length -eq [long]$Attempt.P0.Length;$sameHash=[string]$candidate.SHA256 -ceq [string]$Attempt.P0.SHA256
    $sameTime=[long]$candidate.LastWriteTimeUtcTicks -eq [long]$Attempt.P0.LastWriteTimeUtcTicks
    if($sameLength -and $sameHash -and $sameTime){return [pscustomobject]@{DiskClass='P0';RequiredVerifier='P0Verifier';Candidate=$candidate}}
    if($sameLength -and $sameHash -and -not $sameTime){throw 'CS2-PA timestamp-only candidate rejected'}
    if([int]$Attempt.SaveDispatchCount -ne 1 -or [string]$Attempt.DurableState -cne 'SAVE_DISPATCHED_DURABLE' -or
        [string]::IsNullOrWhiteSpace([string]$Attempt.FinalReadbackSHA256)){throw 'CS2-PA missing transaction-attributable byte/state authority'}
    if([string]$Attempt.TransportClass -cne 'DeterminateSuccess'){throw 'CS2-PA changed disk without determinate save success'}
    $Attempt.Candidate=$candidate;$Attempt.Status='CHANGED_PENDING_LITERAL_FINAL_VERIFIER';Set-UID0002PAAttemptAuthorityHmac $Attempt $EvidenceKey
    [pscustomobject]@{DiskClass='CHANGED_PENDING_LITERAL_FINAL_VERIFIER';RequiredVerifier='S1Verifier';Candidate=$candidate}
}

function Assert-UID0002PAFinalSemanticFailureLabel {
    param([Parameter(Mandatory=$true)][string]$Failure)
    $allowed=@(
        '^RQ-PA S1Verifier (analyze|xref|exact item|collision|renamed identity|proposed-name collision|legacy candidate-type|prestate UDT collision|exact declared UDT layout|Config shell|request/response catalog keys|exact active returned-session)',
        '^RQ-PA exact result mismatch: S1Verifier ',
        '^RQ-PA (byte rows|byte address/size|byte error|byte count|byte hash|comment row|comment address|comment channel|candidate type index)'
    )
    if(@($allowed|Where-Object{$Failure -match $_}).Count -ne 1){throw 'VR2-PA failure is not literal Final-oracle semantic mismatch'}
    return $true
}

function New-UID0002PAFailedVerifierEvidence {
    param($Requests,$Responses,$RoleBinding,$AttestationState,[string]$ControllerEvidenceKey)
    if([string]$RoleBinding.Role -cne 'S1Verifier'){throw 'VR2-PA failed readback is not S1Verifier'}
    $expected=New-UID0002PAReadbackCatalog $RoleBinding S1Verifier;$required=@($expected.Keys)
    if((@($Requests.Keys|Sort-Object)-join '|') -cne (@($required|Sort-Object)-join '|') -or (@($Responses.Keys|Sort-Object)-join '|') -cne (@($required|Sort-Object)-join '|')){throw 'VR2-PA failed catalog key mismatch'}
    foreach($key in $required){
        $actual=Get-UID0002PARequestIdentity ([string]$Requests[$key]) "VR2-PA $key actual";$literal=Get-UID0002PARequestIdentity ([string]$expected[$key]) "VR2-PA $key literal"
        if($actual.SHA256 -cne $literal.SHA256){throw "VR2-PA failed request drift $key"}
        $null=Assert-UID0002PAJsonRpcResponse $Responses[$key] ([string]$Requests[$key]) "VR2-PA $key correlation" $true
    }
    try{$readback=Assert-UID0002PAReadbackCatalog $Requests $Responses $RoleBinding $AttestationState S1Verifier;return [pscustomobject]@{Passed=$true;Readback=$readback}}
    catch{$failure=$_.Exception.Message}
    $null=Assert-UID0002PAFinalSemanticFailureLabel $failure
    $requestProjection=[ordered]@{};$responseProjection=[ordered]@{}
    foreach($key in $required){$requestProjection[$key]=Get-UID0002PATextSha256 ([string]$Requests[$key]);$responseProjection[$key]=Get-UID0002PATextSha256 ($Responses[$key]|ConvertTo-Json -Depth 50 -Compress)}
    $evidence=[pscustomobject][ordered]@{Passed=$false;FailureClass='LiteralFinalOracleSemanticMismatch';Phase='S1Verifier';Role='S1Verifier';Database=[string]$RoleBinding.Database
        WorkerGeneration=[string]$AttestationState.RoleWorkers[[string]$RoleBinding.Database].Generation;ExactFailure=$failure;Requests=$Requests;Responses=$Responses
        RequestCatalogSHA256=Get-UID0002PATextSha256 ($requestProjection|ConvertTo-Json -Depth 20 -Compress)
        ResponseCatalogSHA256=Get-UID0002PATextSha256 ($responseProjection|ConvertTo-Json -Depth 20 -Compress);EvidenceHmac=$null}
    $projection=[ordered]@{FailureClass=$evidence.FailureClass;Phase=$evidence.Phase;Role=$evidence.Role;Database=$evidence.Database;WorkerGeneration=$evidence.WorkerGeneration;ExactFailure=$evidence.ExactFailure;RequestCatalogSHA256=$evidence.RequestCatalogSHA256;ResponseCatalogSHA256=$evidence.ResponseCatalogSHA256}
    $evidence.EvidenceHmac=Get-UID0002PAEvidenceHmac ($projection|ConvertTo-Json -Compress) $ControllerEvidenceKey
    $evidence
}

function Assert-UID0002PAFailedVerifierEvidence {
    param($Evidence,$RoleBinding,[string]$ControllerEvidenceKey)
    if($Evidence.Passed -ne $false -or [string]$Evidence.FailureClass -cne 'LiteralFinalOracleSemanticMismatch' -or
        [string]$Evidence.Role -cne 'S1Verifier' -or [string]$Evidence.Database -cne [string]$RoleBinding.Database){throw 'VR2-PA failed evidence header mismatch'}
    $null=Assert-UID0002PAFinalSemanticFailureLabel ([string]$Evidence.ExactFailure)
    $projection=[ordered]@{FailureClass=$Evidence.FailureClass;Phase=$Evidence.Phase;Role=$Evidence.Role;Database=$Evidence.Database;WorkerGeneration=$Evidence.WorkerGeneration;ExactFailure=$Evidence.ExactFailure;RequestCatalogSHA256=$Evidence.RequestCatalogSHA256;ResponseCatalogSHA256=$Evidence.ResponseCatalogSHA256}
    if([string]$Evidence.EvidenceHmac -cne (Get-UID0002PAEvidenceHmac ($projection|ConvertTo-Json -Compress) $ControllerEvidenceKey)){throw 'VR2-PA failed evidence HMAC mismatch'}
    $true
}

function Initialize-UID0002PAHandleInspector {
    if('UID0002PAHandleInspector' -as [type]){return}
    Add-Type -TypeDefinition @'
using System;
using System.Runtime.InteropServices;
using System.Text;
using Microsoft.Win32.SafeHandles;
public static class UID0002PAHandleInspector {
  [StructLayout(LayoutKind.Sequential)] public struct FILETIME { public uint Low; public uint High; }
  [StructLayout(LayoutKind.Sequential)] public struct INFO { public uint Attr; public FILETIME Creation; public FILETIME Access; public FILETIME Write; public uint Volume; public uint SizeHigh; public uint SizeLow; public uint Links; public uint IndexHigh; public uint IndexLow; }
  [DllImport("kernel32.dll", SetLastError=true)] static extern bool GetFileInformationByHandle(SafeFileHandle h, out INFO info);
  [DllImport("kernel32.dll", CharSet=CharSet.Unicode, SetLastError=true)] static extern uint GetFinalPathNameByHandle(SafeFileHandle h, StringBuilder path, uint size, uint flags);
  public static long LastWriteTicks(SafeFileHandle h) { INFO i; if(!GetFileInformationByHandle(h,out i)) throw new System.ComponentModel.Win32Exception(); return ((long)i.Write.High << 32) | i.Write.Low; }
  public static string FinalPath(SafeFileHandle h) { var b=new StringBuilder(32768); uint n=GetFinalPathNameByHandle(h,b,(uint)b.Capacity,0); if(n==0 || n>=b.Capacity) throw new System.ComponentModel.Win32Exception(); string p=b.ToString(); if(p.StartsWith(@"\\?\UNC\")) return @"\\"+p.Substring(8); if(p.StartsWith(@"\\?\")) return p.Substring(4); return p; }
}
'@
}

function Get-UID0002PAHeldHandleTuple {
    param([Parameter(Mandatory=$true)][System.IO.FileStream]$Stream,[Parameter(Mandatory=$true)][string]$ExpectedPath)
    Initialize-UID0002PAHandleInspector
    $path=[System.IO.Path]::GetFullPath([UID0002PAHandleInspector]::FinalPath($Stream.SafeFileHandle))
    if($path -ine [System.IO.Path]::GetFullPath($ExpectedPath)){throw 'RS2-PA held handle path mismatch'}
    $ticksA=[UID0002PAHandleInspector]::LastWriteTicks($Stream.SafeFileHandle);$lengthA=[long]$Stream.Length
    $sha=Get-UID0002PAStreamSha256 $Stream
    $ticksB=[UID0002PAHandleInspector]::LastWriteTicks($Stream.SafeFileHandle);$lengthB=[long]$Stream.Length
    if($ticksA -ne $ticksB -or $lengthA -ne $lengthB){throw 'RS2-PA held handle tuple changed during hash'}
    [pscustomobject][ordered]@{FullPath=$path;Length=$lengthB;LastWriteTimeUtcTicks=$ticksB;SHA256=$sha}
}

function New-UID0002PADurableAuthority {
    param([string]$CanonicalPath,[string]$TransactionId)
    $path=[System.IO.Path]::GetFullPath($CanonicalPath)+'.uid0002pa-save-authority.json'
    $stream=[System.IO.FileStream]::new($path,[System.IO.FileMode]::CreateNew,[System.IO.FileAccess]::ReadWrite,[System.IO.FileShare]::None)
    $record=[pscustomobject][ordered]@{Schema=1;UID='0002PA';TransactionId=$TransactionId;CanonicalPath=[System.IO.Path]::GetFullPath($CanonicalPath);SaveDispatchCount=0;State='PRE_SAVE';SaveRequestSHA256=$null;Database=$null;Terminal=$null}
    [pscustomobject]@{Path=$path;Stream=$stream;Record=$record}
}
function Write-UID0002PADurableAuthority {
    param($Authority)
    $json=$Authority.Record|ConvertTo-Json -Depth 12 -Compress;$bytes=(New-Object Text.UTF8Encoding($false)).GetBytes($json)
    $Authority.Stream.Position=0;$Authority.Stream.SetLength(0);$Authority.Stream.Write($bytes,0,$bytes.Length);$Authority.Stream.Flush($true)
    Get-UID0002PATextSha256 $json
}
function Set-UID0002PADurableSaveDispatched {
    param($Authority,$RequestIdentity,[string]$Database)
    if([int]$Authority.Record.SaveDispatchCount -ne 0 -or [string]$Authority.Record.State -cne 'PRE_SAVE'){throw 'DG-PA durable save retry/duplicate'}
    $Authority.Record.SaveDispatchCount=1;$Authority.Record.State='SAVE_DISPATCHED_DURABLE';$Authority.Record.SaveRequestSHA256=[string]$RequestIdentity.SHA256;$Authority.Record.Database=$Database
    Write-UID0002PADurableAuthority $Authority
}

function Assert-UID0002PAHostileThrow {
    param([Parameter(Mandatory=$true)][scriptblock]$Action,[Parameter(Mandatory=$true)][string]$ExpectedFailure)
    try{& $Action;throw "HOSTILE FIXTURE DID NOT FAIL: $ExpectedFailure"}
    catch{
        if($_.Exception.Message -like 'HOSTILE FIXTURE DID NOT FAIL:*'){throw}
        if([string]$_.Exception.Message -cne $ExpectedFailure){throw "HOSTILE FIXTURE WRONG FAILURE: expected=[$ExpectedFailure] actual=[$($_.Exception.Message)]"}
        return $true
    }
}
~~~

## Removed Block R013

- SHA256: `CEA64417107ACAC657B6071BF73F5FE9565808D2806CEB3D7A8433BB00EC2697`
- Language: `powershell`
- Bytes: `28946`
- First recovered timestamp: `2026-08-07T01:11:47.315Z`
- Session provenance: rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 195530 (2026-08-07T01:11:47.315Z); rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 195531 (2026-08-07T01:11:47.367Z)

~~~powershell
function Assert-UID0002PAPartialCleanupResult {
    param($Action,$Result)
    if($null -eq $Result -or $Result.Retired -ne $true -or $Result.PartialOpen -ne $true -or
        [string]$Result.Action -cne 'RETIRE_PARTIAL_OPEN' -or [string]$Result.Role -cne [string]$Action.Role -or
        [string]$Result.Database -cne [string]$Action.Database -or [string]$Result.OpenRequestSHA256 -cne [string]$Action.OpenRequestSHA256){
        throw 'OP2-PA partial-open cleanup result mismatch'
    }
    $true
}

function Invoke-UID0002PAClosedTransaction {
    param([Parameter(Mandatory=$true)][scriptblock]$Transport,[Parameter(Mandatory=$true)][scriptblock]$RetireExactGeneration)
    $canonical=[System.IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64')
    $state=New-UID0002PAAttestationState;$transactionId=[string]$state.TransactionId
    $evidenceKey=[Guid]::NewGuid().ToString('N')+[Guid]::NewGuid().ToString('N')
    $requestIds=[System.Collections.Generic.HashSet[string]]::new([System.StringComparer]::Ordinal)
    $transcript=[System.Collections.Generic.List[object]]::new()
    $durable=$null;$durableHash=$null;$backup=$null;$transaction=$null;$saveSent=$false;$saveObservation=$null

    $sendReadOnly={
        param([string]$RequestJson)
        $identity=Get-UID0002PARequestIdentity $RequestJson 'CT2-PA read-only dispatch'
        if([string]$identity.Parsed.method -ceq 'tools/call' -and [string]$identity.Parsed.params.name -ceq 'idb_save'){throw 'CT2-PA save reached read-only dispatcher'}
        $idKey="$($identity.IdType)|$($identity.Id)";if(-not $requestIds.Add($idKey)){throw "CT2-PA duplicate typed request id $idKey"}
        try{$wire=& $Transport $RequestJson}catch{throw "CT2-PA read-only transport failure: $($_.Exception.Message)"}
        if($wire -is [string]){$raw=[string]$wire;$observed='Response'}else{$observed=[string]$wire.ObservedTransport;$raw=[string]$wire.RawResponseJson}
        if($observed -cne 'Response' -or [string]::IsNullOrWhiteSpace($raw)){throw 'CT2-PA read-only request lacked response'}
        Assert-UID0002PARawJsonUnique $raw 'CT2-PA read-only response';$envelope=$raw|ConvertFrom-Json -ErrorAction Stop
        $null=Assert-UID0002PAJsonRpcResponse $envelope $RequestJson 'CT2-PA immediate read-only response' (-not ([string]$identity.Parsed.method -ceq 'tools/list')) $raw
        $record=[pscustomobject][ordered]@{RequestId=$identity.Id;RequestIdType=$identity.IdType;RequestSHA256=$identity.SHA256
            Tool=if([string]$identity.Parsed.method -ceq 'tools/list'){'tools/list'}else{[string]$identity.Parsed.params.name};ObservedTransport='Response';RawResponseJson=$raw;Envelope=$envelope}
        $transcript.Add($record);$record
    }

    $openRole={
        param([ValidateSet('Transaction','P0Verifier','S1Verifier','RollbackVerifier')][string]$Role)
        $openRequest=New-UID0002PARoleOpenRequest $Role;$openIdentity=Get-UID0002PARequestIdentity $openRequest "OP2-PA $Role open"
        $database=$null;$redirectorPid=0;$binding=$null
        try{
            $openWire=& $sendReadOnly $openRequest
            $openContent=Get-UID0002PAStructuredContent $openWire.Envelope $openRequest "OP2-PA $Role open"
            if(-not $openContent.PSObject.Properties['success'] -or -not (Test-UID0002PAJsonBoolean $openContent.success) -or $openContent.success -ne $true){throw "OP2-PA $Role open native success mismatch"}
            $openSessions=@($openContent.session)
            if($openSessions.Count -ne 1 -or -not $openSessions[0].PSObject.Properties['is_analyzing'] -or
                -not (Test-UID0002PAJsonBoolean $openSessions[0].is_analyzing) -or $openSessions[0].is_analyzing -ne $false -or
                -not (Test-UID0002PAJsonString $openSessions[0].session_id) -or -not (Test-UID0002PAJsonString $openSessions[0].input_path)){
                throw "OP2-PA $Role open session native mismatch"
            }
            $database=[string]$openSessions[0].session_id
            $listRequest=New-UID0002PAToolRequest "uid0002pa-open-list-$Role-$([Guid]::NewGuid().ToString('N'))" 'idb_list' @{}
            $listWire=& $sendReadOnly $listRequest;$list=Get-UID0002PAStructuredContent $listWire.Envelope $listRequest "OP2-PA $Role list"
            $matches=@($list.sessions|Where-Object{[string]$_.session_id -ceq $database -and $_.is_active -eq $true})
            if($matches.Count -ne 1 -or -not (Test-UID0002PAJsonInteger $matches[0].worker_pid)){throw "OP2-PA $Role list PID native mismatch"}
            $redirectorPid=[int]$matches[0].worker_pid
            $preferred=[string](($openRequest|ConvertFrom-Json).params.arguments.preferred_session_id)
            $binding=New-UID0002PARoleBinding $Role $preferred $openRequest $openWire.Envelope $listRequest $listWire.Envelope
            $attestRequest=New-UID0002PARuntimeAttestationRequest "uid0002pa-open-attest-$Role-$([Guid]::NewGuid().ToString('N'))" $binding
            $attestWire=& $sendReadOnly $attestRequest
            $runtime=Assert-UID0002PARuntimeAttestation $attestWire.Envelope $attestRequest $listWire.Envelope $listRequest $binding $state
            [pscustomobject]@{Role=$Role;Binding=$binding;Runtime=$runtime;OpenRequest=$openRequest;OpenResponse=$openWire.Envelope;Closed=$false;CloseAuthority=$null}
        }catch{
            $openFailure=$_.Exception.Message
            if(-not [string]::IsNullOrWhiteSpace($database)){
                $action=[pscustomobject][ordered]@{Action='RETIRE_PARTIAL_OPEN';PartialOpen=$true;Role=$Role;Database=$database;CanonicalPath=$canonical
                    RedirectorPid=$redirectorPid;OpenRequestSHA256=$openIdentity.SHA256;PreserveListener=$true}
                try{$result=& $RetireExactGeneration $action;$null=Assert-UID0002PAPartialCleanupResult $action $result}
                catch{throw "OP2-PA partial-open cleanup failed after [$openFailure]: $($_.Exception.Message)"}
            }
            throw $openFailure
        }
    }

    $catalog={
        param($RoleObject,[ValidateSet('Pre','AfterI01','AfterI02','AfterI03','AfterI04','AfterI05','Final','P0Verifier','S1Verifier','RollbackVerifier')][string]$Phase,[switch]$DeferSemantic)
        $requests=New-UID0002PAReadbackCatalog $RoleObject.Binding $Phase;$responses=[ordered]@{}
        foreach($key in @($requests.Keys)){$responses[$key]=(& $sendReadOnly ([string]$requests[$key])).Envelope}
        if($DeferSemantic){return [pscustomobject]@{Requests=$requests;Responses=$responses}}
        $readback=Assert-UID0002PAReadbackCatalog $requests $responses $RoleObject.Binding $state $Phase
        [pscustomobject]@{Requests=$requests;Responses=$responses;Readback=$readback}
    }

    $closeRole={
        param($RoleObject)
        if($RoleObject.Closed -eq $true){return $RoleObject.CloseAuthority}
        $binding=$RoleObject.Binding
        $preListRequest=New-UID0002PAToolRequest "uid0002pa-preclose-list-$($binding.Role)-$([Guid]::NewGuid().ToString('N'))" 'idb_list' @{}
        $preList=& $sendReadOnly $preListRequest
        $preAttestRequest=New-UID0002PARuntimeAttestationRequest "uid0002pa-preclose-attest-$($binding.Role)-$([Guid]::NewGuid().ToString('N'))" $binding
        $preAttest=& $sendReadOnly $preAttestRequest
        $preRuntime=Assert-UID0002PARuntimeAttestation $preAttest.Envelope $preAttestRequest $preList.Envelope $preListRequest $binding $state
        $action=Invoke-UID0002PAExactGenerationRetirementAction $binding $state $preRuntime $RetireExactGeneration
        $postRequest=New-UID0002PAPostRetirementAttestationRequest "uid0002pa-postclose-attest-$($binding.Role)-$([Guid]::NewGuid().ToString('N'))" $binding
        $post=& $sendReadOnly $postRequest
        $postListRequest=New-UID0002PAToolRequest "uid0002pa-postclose-list-$($binding.Role)-$([Guid]::NewGuid().ToString('N'))" 'idb_list' @{}
        $postList=& $sendReadOnly $postListRequest
        $proof=Assert-UID0002PARoleRetired $binding $state $preRuntime $action $post.Envelope $postRequest $postList.Envelope $postListRequest
        $authority=[pscustomobject][ordered]@{Proof=$proof;TransactionId=$transactionId;Role=[string]$binding.Role;AuthorityHmac=$null}
        $authority.AuthorityHmac=Get-UID0002PAEvidenceHmac (Get-UID0002PARetirementAuthorityText $authority) $evidenceKey
        $RoleObject.Closed=$true;$RoleObject.CloseAuthority=$authority;$authority
    }

    $dispatchSave={
        param([string]$RequestJson,[string]$Database)
        $identity=Assert-UID0002PAExactSaveRequest $RequestJson $Database $canonical
        $idKey="$($identity.IdType)|$($identity.Id)";if(-not $requestIds.Add($idKey)){throw "SV2-PA duplicate typed save id $idKey"}
        $durableHash=Set-UID0002PADurableSaveDispatched $durable $identity $Database;$saveSent=$true
        $observed='MissingResponse';$raw=$null;$thrown=$null
        try{
            $wire=& $Transport $RequestJson
            if($null -eq $wire){$observed='MissingResponse'}
            elseif($wire -is [string]){$observed='Response';$raw=[string]$wire}
            else{
                $candidate=[string]$wire.ObservedTransport;$raw=[string]$wire.RawResponseJson
                if($candidate -in @('Response','Timeout','Disconnect','Malformed')){$observed=$candidate}else{$observed='Malformed'}
                if($observed -ceq 'Response' -and [string]::IsNullOrWhiteSpace($raw)){$observed='MissingResponse'}
            }
        }catch{$observed='ThrownTransport';$thrown=$_.Exception.Message}
        $record=[pscustomobject][ordered]@{RequestId=$identity.Id;RequestIdType=$identity.IdType;RequestSHA256=$identity.SHA256;Tool='idb_save'
            ObservedTransport=$observed;RawResponseJson=$raw;ThrownFailure=$thrown}
        $transcript.Add($record);$record
    }

    $restoreClosed={
        param($Attempt)
        Assert-UID0002PAAttemptAuthorityHmac $Attempt $evidenceKey
        if([string]$Attempt.Status -cne 'F1_RESTORE_REQUIRED' -or $null -eq $Attempt.Candidate){throw 'RS2-PA restore lacks closed F1 authority'}
        Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $Attempt.CanonicalPath) $Attempt.Candidate 'RS2-PA pre-handle candidate'
        Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $Attempt.B0.FullPath) $Attempt.B0 'RS2-PA pre-handle B0'
        $source=$null;$destination=$null
        try{
            $source=[IO.FileStream]::new($Attempt.B0.FullPath,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None)
            $destination=[IO.FileStream]::new($Attempt.CanonicalPath,[IO.FileMode]::Open,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None)
            $heldSource=Get-UID0002PAHeldHandleTuple $source $Attempt.B0.FullPath;$heldDestination=Get-UID0002PAHeldHandleTuple $destination $Attempt.CanonicalPath
            Assert-UID0002PATuple $heldSource $Attempt.B0 'RS2-PA held B0 complete tuple'
            Assert-UID0002PATuple $heldDestination $Attempt.Candidate 'RS2-PA held candidate complete tuple'
            if($heldSource.Length -ne $Attempt.P0.Length -or $heldSource.SHA256 -cne $Attempt.P0.SHA256){throw 'RS2-PA held B0 content differs from P0'}
            $source.Position=0;$destination.SetLength(0);$destination.Position=0;$buffer=New-Object byte[] 1048576;$copied=[long]0
            while(($read=$source.Read($buffer,0,$buffer.Length)) -gt 0){$destination.Write($buffer,0,$read);$copied+=$read}
            if($copied -ne $Attempt.P0.Length -or $source.Position -ne $Attempt.P0.Length -or $source.ReadByte() -ne -1 -or
                $destination.Position -ne $Attempt.P0.Length -or $destination.Length -ne $Attempt.P0.Length){throw 'RS2-PA copy/EOF/destination mismatch'}
            $destination.Flush($true)
        }finally{if($null -ne $destination){$destination.Dispose()};if($null -ne $source){$source.Dispose()}}
        [IO.File]::SetLastWriteTimeUtc($Attempt.CanonicalPath,[DateTime]::new([long]$Attempt.P0.LastWriteTimeUtcTicks,[DateTimeKind]::Utc))
        Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $Attempt.CanonicalPath) $Attempt.P0 'RS2-PA closed restored P0 first'
        Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $Attempt.CanonicalPath) $Attempt.P0 'RS2-PA closed restored P0 second'
        $Attempt.Status='ROLLBACK_VERIFIER_REQUIRED';Set-UID0002PAAttemptAuthorityHmac $Attempt $evidenceKey;$Attempt
    }

    try{
        $durable=New-UID0002PADurableAuthority $canonical $transactionId;$durableHash=Write-UID0002PADurableAuthority $durable
        $toolsRequest='{"jsonrpc":"2.0","id":"uid0002pa-tools","method":"tools/list","params":{}}';$toolsWire=& $sendReadOnly $toolsRequest
        $null=Assert-UID0002PAToolsList $toolsWire.Envelope $toolsRequest
        $preflightRequest=New-UID0002PAToolRequest "uid0002pa-preflight-$([Guid]::NewGuid().ToString('N'))" 'idb_list' @{}
        $preflightWire=& $sendReadOnly $preflightRequest;$preflight=Get-UID0002PAStructuredContent $preflightWire.Envelope $preflightRequest 'CT2-PA preflight'
        foreach($row in @($preflight.sessions)){if(-not (Test-UID0002PAJsonBoolean $row.is_active) -or -not (Test-UID0002PAJsonInteger $row.worker_pid)){throw 'CT2-PA preflight native session mismatch'}}
        if(@($preflight.sessions|Where-Object{$_.is_active -eq $true -and [IO.Path]::GetFullPath([string]$_.input_path) -ieq $canonical}).Count -ne 0){throw 'CT2-PA canonical database already active'}
        $backupPath=$canonical+'.bak-UID0002PA-prestate-'+[DateTime]::UtcNow.ToString('yyyyMMdd-HHmmss')+'-'+[Guid]::NewGuid().ToString('N')
        $backup=New-UID0002PABackup $canonical $backupPath
        $transaction=& $openRole Transaction;$null=& $catalog $transaction Pre
        $mutations=New-UID0002PAMutationRequestCatalog $transaction.Binding
        foreach($step in @(@('I01','AfterI01'),@('I02Dry',$null),@('I02','AfterI02'),@('I03','AfterI03'),@('I04','AfterI04'),@('I05','AfterI05'))){
            $action=[string]$step[0];$request=[string]$mutations[$action];$wire=& $sendReadOnly $request
            Assert-UID0002PAMutationResponse $action $request $wire.Envelope $transaction.Binding
            if($null -ne $step[1]){$null=& $catalog $transaction ([string]$step[1])}
        }
        $final=& $catalog $transaction Final
        $saveRequest=New-UID0002PAToolRequest 'uid0002pa-save-transaction' 'idb_save' ([ordered]@{database=[string]$transaction.Binding.Database;path=$canonical})
        $attempt=[pscustomobject][ordered]@{TransactionId=$transactionId;Database=[string]$transaction.Binding.Database;TransactionGeneration=[string]$transaction.Runtime.WorkerGeneration
            CanonicalPath=$canonical;SaveRequestSHA256=(Get-UID0002PARequestIdentity $saveRequest 'CT2-PA save').SHA256;SaveDispatchCount=0;TransportClass='NotDispatched'
            DurableState='PRE_SAVE';DurableJournalSHA256=$durableHash;FinalReadbackSHA256=Get-UID0002PATextSha256 (($final|ConvertTo-Json -Depth 60 -Compress))
            P0=Get-UID0002PATupleCopy $backup.P0;B0=Get-UID0002PATupleCopy $backup.B0;Candidate=$null;Status='PREPARED';AuthorityHmac=$null}
        Set-UID0002PAAttemptAuthorityHmac $attempt $evidenceKey
        $retirementAuthority=$null;$retirementFailure=$null
        try{$saveObservation=& $dispatchSave $saveRequest $transaction.Binding.Database}
        finally{
            if($saveSent){try{$retirementAuthority=& $closeRole $transaction}catch{$retirementFailure=$_.Exception.Message}}
        }
        $outcome=Resolve-UID0002PASaveTransportOutcome $saveRequest $saveObservation.ObservedTransport $saveObservation.RawResponseJson $saveObservation.ThrownFailure
        $attempt.SaveDispatchCount=1;$attempt.TransportClass=[string]$outcome.TransportClass;$attempt.DurableState='SAVE_DISPATCHED_DURABLE';$attempt.DurableJournalSHA256=$durableHash;$attempt.Status='TRANSPORT_CLASSIFIED'
        Set-UID0002PAAttemptAuthorityHmac $attempt $evidenceKey
        if(-not [string]::IsNullOrWhiteSpace($retirementFailure)){$durable.Record.State='RETIREMENT_FAILED';$durable.Record.Terminal=$retirementFailure;$durableHash=Write-UID0002PADurableAuthority $durable;throw "CT2-PA post-save retirement failed: $retirementFailure"}
        $classification=Get-UID0002PAChangedDiskClassification $attempt $retirementAuthority $evidenceKey
        if($classification.RequiredVerifier -ceq 'P0Verifier'){
            $verifier=& $openRole P0Verifier;$vr=& $catalog $verifier P0Verifier;$vrClose=& $closeRole $verifier
            Assert-UID0002PARetirementAuthorityHmac $vrClose $evidenceKey
            Assert-UID0002PAVerifierIdentity $state P0Verifier $verifier.Binding $vr.Readback $vr.Readback.RuntimeProof $vrClose.Proof
            Assert-UID0002PATuple $vrClose.Proof.ClosedTupleA $attempt.P0 'CT2-PA P0 verifier first';Assert-UID0002PATuple $vrClose.Proof.ClosedTupleB $attempt.P0 'CT2-PA P0 verifier second'
            $attempt.Status="NOT_PERSISTED_P0_VERIFIED_$($attempt.TransportClass.ToUpperInvariant())";Set-UID0002PAAttemptAuthorityHmac $attempt $evidenceKey
        }else{
            $verifier=& $openRole S1Verifier;$pending=& $catalog $verifier S1Verifier -DeferSemantic
            $verifierOutcome=New-UID0002PAFailedVerifierEvidence $pending.Requests $pending.Responses $verifier.Binding $state $evidenceKey
            $vrClose=& $closeRole $verifier;Assert-UID0002PARetirementAuthorityHmac $vrClose $evidenceKey
            Assert-UID0002PATuple $vrClose.Proof.ClosedTupleA $attempt.Candidate 'CT2-PA S1/F1 verifier first';Assert-UID0002PATuple $vrClose.Proof.ClosedTupleB $attempt.Candidate 'CT2-PA S1/F1 verifier second'
            if($verifierOutcome.Passed -eq $true){
                Assert-UID0002PAVerifierIdentity $state S1Verifier $verifier.Binding $verifierOutcome.Readback $verifierOutcome.Readback.RuntimeProof $vrClose.Proof
                $attempt.Status='PERSISTED_S1_VERIFIED_DETERMINATESUCCESS';Set-UID0002PAAttemptAuthorityHmac $attempt $evidenceKey
            }else{
                $null=Assert-UID0002PAFailedVerifierEvidence $verifierOutcome $verifier.Binding $evidenceKey
                if([string]$verifierOutcome.WorkerGeneration -cne [string]$state.RoleWorkers[[string]$verifier.Binding.Database].Generation){throw 'VR2-PA failed Final verifier generation mismatch'}
                $attempt.Status='F1_RESTORE_REQUIRED';Set-UID0002PAAttemptAuthorityHmac $attempt $evidenceKey;$attempt=& $restoreClosed $attempt
                $rollback=& $openRole RollbackVerifier;$rb=& $catalog $rollback RollbackVerifier;$rbClose=& $closeRole $rollback
                Assert-UID0002PARetirementAuthorityHmac $rbClose $evidenceKey
                Assert-UID0002PAVerifierIdentity $state RollbackVerifier $rollback.Binding $rb.Readback $rb.Readback.RuntimeProof $rbClose.Proof
                Assert-UID0002PATuple $rbClose.Proof.ClosedTupleA $attempt.P0 'CT2-PA rollback first';Assert-UID0002PATuple $rbClose.Proof.ClosedTupleB $attempt.P0 'CT2-PA rollback second'
                $attempt.Status='RESTORED_P0_VERIFIED_DETERMINATESUCCESS';Set-UID0002PAAttemptAuthorityHmac $attempt $evidenceKey
            }
        }
        $durable.Record.State='TERMINAL';$durable.Record.Terminal=[string]$attempt.Status;$durableHash=Write-UID0002PADurableAuthority $durable
        [pscustomobject]@{Status=$attempt.Status;Attempt=$attempt;Transcript=@($transcript);SaveDispatchCount=1;DurableJournal=$durable.Path;DurableJournalSHA256=$durableHash}
    }catch{
        $failure=$_.Exception.Message
        if($saveSent){if($null -ne $durable -and $durable.Stream.CanWrite){$durable.Record.State='FAILED_CLOSED_AFTER_SAVE';$durable.Record.Terminal=$failure;$null=Write-UID0002PADurableAuthority $durable};throw}
        if($null -ne $transaction -and $transaction.Closed -ne $true){$null=& $closeRole $transaction}
        if($null -ne $backup){Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $canonical) $backup.P0 'CT2-PA no-save P0';Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $backup.B0.FullPath) $backup.B0 'CT2-PA no-save B0'}
        throw
    }finally{
        if($null -ne $durable){$path=$durable.Path;if($durable.Stream.CanWrite){$durable.Stream.Dispose()};if(-not $saveSent -and [IO.File]::Exists($path)){[IO.File]::Delete($path)}}
    }
}

function Invoke-UID0002PAHostileStaticFixtures {
    $passed=0;$contracts=Get-UID0002PAUsedToolSchemaContracts
    try{$null=Assert-UID0002PAHostileThrow {throw 'UNRELATED'} 'EXPECTED'}catch{if($_.Exception.Message -cne 'HOSTILE FIXTURE WRONG FAILURE: expected=[EXPECTED] actual=[UNRELATED]'){throw};$labelGuard=$true}
    if($labelGuard -ne $true){throw 'hostile exact-label guard unavailable'}

    if(Assert-UID0002PAHostileThrow {Assert-UID0002PARawJsonUnique '{"id":1,"id":2}' 'fixture'} 'fixture raw JSON rejected: JSON_DUPLICATE_MEMBER:id'){$passed++}
    if(Assert-UID0002PAHostileThrow {Get-UID0002PARequestIdentity '{"jsonrpc":"2.0","id":true,"method":"tools/list","params":{}}' 'fixture request'} 'fixture request invalid native JSON-RPC request root/id'){$passed++}
    if(Assert-UID0002PAHostileThrow {Get-UID0002PARequestIdentity '{"jsonrpc":"2.0","id":"x","method":"wrong","params":{}}' 'fixture request'} 'fixture request unexpected JSON-RPC method'){$passed++}
    $open=New-UID0002PARoleOpenRequest Transaction|ConvertFrom-Json;$open.params.arguments.idle_ttl_sec='600';$bad=$open|ConvertTo-Json -Depth 20 -Compress
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PALiteralRoleOpenRequest Transaction $bad} 'Transaction literal idb_open options/types/prefix mismatch'){$passed++}
    $open=New-UID0002PARoleOpenRequest Transaction|ConvertFrom-Json;$open.params.arguments.run_auto_analysis=0;$bad=$open|ConvertTo-Json -Depth 20 -Compress
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PALiteralRoleOpenRequest Transaction $bad} 'Transaction literal idb_open options/types/prefix mismatch'){$passed++}
    $request=New-UID0002PAToolRequest 'fixture-response' 'idb_list' @{};$missing=[pscustomobject]@{jsonrpc='2.0';id='fixture-response';result=[pscustomobject]@{structuredContent=[pscustomobject]@{sessions=@()}}}
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PAJsonRpcResponse $missing $request 'fixture response' $true} 'fixture response missing/non-Boolean isError'){$passed++}
    $wrong=[pscustomobject]@{jsonrpc='2.0';id='fixture-response';result=[pscustomobject]@{isError='false';structuredContent=[pscustomobject]@{sessions=@()}}}
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PAJsonRpcResponse $wrong $request 'fixture response' $true} 'fixture response missing/non-Boolean isError'){$passed++}
    $openContent=[pscustomobject]@{success=$true;session=[pscustomobject]@{session_id='x';input_path='x'}};$listContent=[pscustomobject]@{sessions=@()};$runtimeContent=[pscustomobject]@{schema_version=1;ok=$true;listener=[pscustomobject]@{process=[pscustomobject]@{pid=1;creation_time_100ns=1}};workers=@()}
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PAOpenAndRuntimeNativeFields $openContent $listContent $runtimeContent 'fixture'} 'fixture open session native fields mismatch'){$passed++}
    $openContent.session|Add-Member -NotePropertyName is_analyzing -NotePropertyValue $false;$listContent.sessions=@([pscustomobject]@{session_id='x';input_path='x';is_active=$true;worker_pid='1'})
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PAOpenAndRuntimeNativeFields $openContent $listContent $runtimeContent 'fixture'} 'fixture list session native fields mismatch'){$passed++}
    $tool=New-UID0002PAFixtureToolFromContract xref_query $contracts.xref_query;$tool.inputSchema.properties.queries|Add-Member -NotePropertyName properties -NotePropertyValue ([pscustomobject]@{evil=[pscustomobject]@{type='string'}})
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PAToolSchemaContract $tool $contracts.xref_query} 'S-PA xref_query recursive authority-schema digest mismatch'){$passed++}
    $root=[IO.Path]::GetFullPath($UID0002PASourceRoot).TrimEnd('\');$mods=@();$n=0
    foreach($name in $UID0002PAListenerNames){$n++;$file=Join-Path $root "fixture-$n.py";$mods+=[pscustomobject]@{sys_modules_name=$name;module_id=('0x{0:x}' -f $n);file=$file;spec_origin=$file;resolved_path=$file;size=1;mtime_ns=1;ctime_ns=1;sha256=('A'*64)}}
    $owner=[pscustomobject]@{source_root=$root;implementation_manifest_sha256='D3C792133956B855EBA751FDB5783B2D7177FA204134CFF1D897E0D0770FB7CE';modules=$mods}
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PAModuleManifest $owner listener 'fixture module'} 'fixture module module-row aggregate digest mismatch'){$passed++}
    if(Assert-UID0002PAHostileThrow {New-UID0002PAClosedControllerContext} 'CT-PA direct controller construction disabled'){$passed++}
    $counter=[pscustomobject]@{Count=0};$unused={param($json)$counter.Count++}.GetNewClosure()
    if(Assert-UID0002PAHostileThrow {Invoke-UID0002PAControllerRequest $unused} 'CT-PA direct dispatch disabled'){$passed++};if($counter.Count -ne 0){throw 'hostile direct-dispatch counter changed'}
    if(Assert-UID0002PAHostileThrow {New-UID0002PASaveAttempt} 'SV-PA public save-attempt construction disabled'){$passed++}
    if(Assert-UID0002PAHostileThrow {Register-UID0002PASoleSaveDispatch} 'SV-PA public save registration disabled'){$passed++}
    if(Assert-UID0002PAHostileThrow {Complete-UID0002PADiskClassification} 'SV-PA public disk classifier disabled'){$passed++}
    if(Assert-UID0002PAHostileThrow {Restore-UID0002PABackup} 'RS-PA public restore disabled'){$passed++}
    $save=New-UID0002PAToolRequest 'save-fixture' 'idb_save' ([ordered]@{database='db';path='E:\NTK\Resources\NexusTK\NexusTK.exe.i64'})
    $foreign='{"jsonrpc":"2.0","id":"foreign","result":{"isError":false,"structuredContent":{"ok":true,"error":"","path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64"}}}'
    $out=Resolve-UID0002PASaveTransportOutcome $save Response $foreign $null;if($out.TransportClass -cne 'Indeterminate' -or $out.Observation -cne 'MalformedOrForeignResponse'){throw 'hostile foreign-save classifier mismatch'};$passed++
    $out=Resolve-UID0002PASaveTransportOutcome $save ThrownTransport $null 'wire exploded';if($out.TransportClass -cne 'Indeterminate' -or $out.Observation -cne 'ThrownTransport'){throw 'hostile thrown-transport classifier mismatch'};$passed++
    $key='0'*64;$canonical=[IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64');$p0=[pscustomobject]@{FullPath=$canonical;Length=100;LastWriteTimeUtcTicks=10;SHA256=('A'*64)}
    $attempt=[pscustomobject]@{TransactionId='t';Database='db';TransactionGeneration='gen';CanonicalPath=$canonical;SaveRequestSHA256=('B'*64);SaveDispatchCount=1;TransportClass='DeterminateSuccess';DurableState='SAVE_DISPATCHED_DURABLE';DurableJournalSHA256=('C'*64);FinalReadbackSHA256=('D'*64);P0=$p0;B0=$p0;Candidate=$null;Status='TRANSPORT_CLASSIFIED';AuthorityHmac=$null};Set-UID0002PAAttemptAuthorityHmac $attempt $key
    $timestamp=[pscustomobject]@{FullPath=$canonical;Length=100;LastWriteTimeUtcTicks=11;SHA256=('A'*64)};$proof=[pscustomobject]@{Role='Transaction';Database='db';Generation='gen';ClosedTupleA=$timestamp;ClosedTupleB=$timestamp}
    $ra=[pscustomobject]@{Proof=$proof;TransactionId='t';Role='Transaction';AuthorityHmac=$null};$ra.AuthorityHmac=Get-UID0002PAEvidenceHmac (Get-UID0002PARetirementAuthorityText $ra) $key
    if(Assert-UID0002PAHostileThrow {Get-UID0002PAChangedDiskClassification $attempt $ra $key} 'CS2-PA timestamp-only candidate rejected'){$passed++}
    $changed=[pscustomobject]@{FullPath=$canonical;Length=101;LastWriteTimeUtcTicks=11;SHA256=('E'*64)};$proof.ClosedTupleA=$changed;$proof.ClosedTupleB=$changed;$attempt.TransportClass='Indeterminate';Set-UID0002PAAttemptAuthorityHmac $attempt $key;$ra.AuthorityHmac=Get-UID0002PAEvidenceHmac (Get-UID0002PARetirementAuthorityText $ra) $key
    if(Assert-UID0002PAHostileThrow {Get-UID0002PAChangedDiskClassification $attempt $ra $key} 'CS2-PA changed disk without determinate save success'){$passed++}
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PAFinalSemanticFailureLabel 'RA-PA top-level schema/status/errors mismatch'} 'VR2-PA failure is not literal Final-oracle semantic mismatch'){$passed++}
    $ra.AuthorityHmac='0'*64
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PARetirementAuthorityHmac $ra $key} 'RT2-PA closed retirement HMAC mismatch'){$passed++}
    $temp=[IO.Path]::Combine([IO.Path]::GetTempPath(),'uid0002pa-handle-'+[Guid]::NewGuid().ToString('N')+'.bin')
    try{[IO.File]::WriteAllBytes($temp,[byte[]](1,2,3,4));$s=[IO.FileStream]::new($temp,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);try{$tuple=Get-UID0002PAHeldHandleTuple $s $temp;if($tuple.Length -ne 4 -or $tuple.FullPath -ine [IO.Path]::GetFullPath($temp)){throw 'hostile held-handle tuple mismatch'}}finally{$s.Dispose()}}finally{if([IO.File]::Exists($temp)){[IO.File]::Delete($temp)}}
    if($passed -ne 23){throw "hostile fixture count mismatch: $passed"}
    [pscustomobject]@{Passed=23;Failed=0;ProductionPaths=$true;TransportCounter=$counter.Count}
}
~~~

## Removed Block R014

- SHA256: `89068D58FF9305C56628B642F54E6DD0E9B228A65F174007A82812E4C3B72FEE`
- Language: `powershell`
- Bytes: `32713`
- First recovered timestamp: `2026-08-07T01:50:48.615Z`
- Session provenance: rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 195969 (2026-08-07T01:50:48.615Z)

~~~powershell
function Initialize-UID0002PANativeSealedTypes {
    if('UID0002PANativeSealedCore' -as [type]){return}
    Add-Type -TypeDefinition @'
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;
using Microsoft.Win32.SafeHandles;

public sealed class UID0002PAImmutableTuple {
    public string FullPath { get; private set; }
    public long Length { get; private set; }
    public long LastWriteTimeUtcTicks { get; private set; }
    public string SHA256 { get; private set; }
    public long VolumeSerial { get; private set; }
    public ulong FileIndex { get; private set; }
    public UID0002PAImmutableTuple(string path,long length,long ticks,string sha,long volume,ulong index) {
        FullPath=Path.GetFullPath(path);Length=length;LastWriteTimeUtcTicks=ticks;SHA256=sha;VolumeSerial=volume;FileIndex=index;
    }
    public bool Same(UID0002PAImmutableTuple other) {
        return other!=null && String.Equals(FullPath,other.FullPath,StringComparison.OrdinalIgnoreCase) && Length==other.Length &&
            LastWriteTimeUtcTicks==other.LastWriteTimeUtcTicks && String.Equals(SHA256,other.SHA256,StringComparison.Ordinal) &&
            VolumeSerial==other.VolumeSerial && FileIndex==other.FileIndex;
    }
    public bool SameBytes(UID0002PAImmutableTuple other) {
        return other!=null && Length==other.Length && String.Equals(SHA256,other.SHA256,StringComparison.Ordinal);
    }
}

public sealed class UID0002PANativeSealedCore : IDisposable {
    [StructLayout(LayoutKind.Sequential)] struct FILETIME { public uint Low; public uint High; }
    [StructLayout(LayoutKind.Sequential)] struct INFO { public uint Attr; public FILETIME Creation; public FILETIME Access; public FILETIME Write; public uint Volume; public uint SizeHigh; public uint SizeLow; public uint Links; public uint IndexHigh; public uint IndexLow; }
    [DllImport("kernel32.dll",SetLastError=true)] static extern bool GetFileInformationByHandle(SafeFileHandle h,out INFO info);
    [DllImport("kernel32.dll",CharSet=CharSet.Unicode,SetLastError=true)] static extern uint GetFinalPathNameByHandle(SafeFileHandle h,StringBuilder path,uint size,uint flags);
    [DllImport("kernel32.dll",SetLastError=true)] static extern bool SetFileTime(SafeFileHandle h,IntPtr c,IntPtr a,ref FILETIME w);

    readonly string canonicalPath;
    readonly string transactionId;
    readonly string journalPath;
    readonly Dictionary<string,string> frozenRoles=new Dictionary<string,string>(StringComparer.Ordinal);
    FileStream journal;
    string schemaDigest;
    string planDigest;
    string moduleDigest;
    string state="CREATED";
    string database;
    string generation;
    string preSaveListDigest;
    string preSaveRuntimeDigest;
    int saveDispatchCount;
    int transportCalls;
    int retireCalls;
    int restoreWrites;
    bool retainJournal=true;
    UID0002PAImmutableTuple p0,b0,dopen,dclosed,p1;

    public string State { get { return state; } }
    public string JournalPath { get { return journalPath; } }
    public int SaveDispatchCount { get { return saveDispatchCount; } }
    public int TransportCalls { get { return transportCalls; } }
    public int RetireCalls { get { return retireCalls; } }
    public int RestoreWrites { get { return restoreWrites; } }
    public bool JournalRetained { get { return retainJournal; } }
    public UID0002PAImmutableTuple P0 { get { return p0; } }
    public UID0002PAImmutableTuple B0 { get { return b0; } }
    public UID0002PAImmutableTuple Dopen { get { return dopen; } }
    public UID0002PAImmutableTuple Dclosed { get { return dclosed; } }
    public UID0002PAImmutableTuple P1 { get { return p1; } }

    public UID0002PANativeSealedCore(string canonical,string transaction,string journalOverride) {
        canonicalPath=Path.GetFullPath(canonical);transactionId=transaction;
        journalPath=String.IsNullOrEmpty(journalOverride)?canonicalPath+".uid0002pa-v3-authority.json":Path.GetFullPath(journalOverride);
        journal=new FileStream(journalPath,FileMode.CreateNew,FileAccess.ReadWrite,FileShare.None);WriteJournal("CREATED",null);
    }
    static string Escape(string s) { if(s==null)return "";return s.Replace("\\","\\\\").Replace("\"","\\\"").Replace("\r","\\r").Replace("\n","\\n"); }
    static string HashText(string text) { using(SHA256 h=SHA256.Create()){byte[] b=Encoding.UTF8.GetBytes(text);return BitConverter.ToString(h.ComputeHash(b)).Replace("-","");} }
    void WriteJournal(string next,string terminal) {
        state=next;string json="{\"schema\":3,\"uid\":\"0002PA\",\"transaction_id\":\""+Escape(transactionId)+"\",\"canonical_path\":\""+Escape(canonicalPath)+"\",\"state\":\""+Escape(state)+"\",\"save_dispatch_count\":"+saveDispatchCount+",\"database\":\""+Escape(database)+"\",\"generation\":\""+Escape(generation)+"\",\"pre_save_list_sha256\":\""+Escape(preSaveListDigest)+"\",\"pre_save_runtime_sha256\":\""+Escape(preSaveRuntimeDigest)+"\",\"terminal\":\""+Escape(terminal)+"\"}";
        byte[] bytes=new UTF8Encoding(false).GetBytes(json);journal.Position=0;journal.SetLength(0);journal.Write(bytes,0,bytes.Length);journal.Flush(true);
    }
    public void FreezeAuthority(string schemas,string plan,string modules) {
        if(schemaDigest!=null)throw new InvalidOperationException("NR3-PA authority already frozen");
        schemaDigest=HashText(schemas);planDigest=HashText(plan);moduleDigest=HashText(modules);WriteJournal("AUTHORITY_FROZEN",null);
    }
    public void AssertAuthority(string schemas,string plan,string modules) {
        if(schemaDigest!=HashText(schemas)||planDigest!=HashText(plan)||moduleDigest!=HashText(modules))throw new InvalidOperationException("NR3-PA frozen authority drift");
    }
    public void FreezeRole(string role,string authority) {
        string digest=HashText(authority);string prior;if(frozenRoles.TryGetValue(role,out prior)&&prior!=digest)throw new InvalidOperationException("NR3-PA frozen role authority drift");frozenRoles[role]=digest;
    }
    public void AssertRole(string role,string authority) { string prior;if(!frozenRoles.TryGetValue(role,out prior)||prior!=HashText(authority))throw new InvalidOperationException("NR3-PA frozen role authority mismatch"); }
    public void SetBackup(UID0002PAImmutableTuple pre,UID0002PAImmutableTuple backup) {
        if(pre==null||backup==null||!pre.SameBytes(backup)||pre.LastWriteTimeUtcTicks!=backup.LastWriteTimeUtcTicks)throw new InvalidOperationException("BK3-PA held P0/B0 mismatch");p0=pre;b0=backup;WriteJournal("P0_B0_HELD_PROVEN",null);
    }
    public void RecordTransport() { checked{transportCalls++;} }
    public void RecordRetire() { checked{retireCalls++;} }
    public void RecordPreSaveBound(string db,string gen,string listSha,string runtimeSha) {
        if(state!="P0_B0_HELD_PROVEN"&&state!="ROLE_ACTIVITY")throw new InvalidOperationException("SV3-PA pre-save attestation out of order");
        if(String.IsNullOrEmpty(db)||String.IsNullOrEmpty(gen)||String.IsNullOrEmpty(listSha)||String.IsNullOrEmpty(runtimeSha))throw new InvalidOperationException("SV3-PA incomplete immediate pre-save binding");
        database=db;generation=gen;preSaveListDigest=listSha;preSaveRuntimeDigest=runtimeSha;WriteJournal("IMMEDIATE_PRE_SAVE_BOUND",null);
    }
    public void ClaimSave(string db,string requestSha) {
        if(saveDispatchCount!=0)throw new InvalidOperationException("SV3-PA durable global save already claimed");
        if(state!="IMMEDIATE_PRE_SAVE_BOUND"||database!=db||String.IsNullOrEmpty(requestSha))throw new InvalidOperationException("SV3-PA save lacks immediate bound pre-save attestation");
        saveDispatchCount=1;WriteJournal("SAVE_DISPATCHED_DURABLE",requestSha);
    }
    public void RecordDopen(UID0002PAImmutableTuple value) { if(saveDispatchCount!=1||value==null)throw new InvalidOperationException("DS3-PA Dopen out of order");dopen=value;WriteJournal("DOPEN_OBSERVED",null); }
    public void RecordDclosed(UID0002PAImmutableTuple value,string transportClass) {
        if(saveDispatchCount!=1||value==null)throw new InvalidOperationException("DS3-PA Dclosed out of order");dclosed=value;
        if(value.Same(p0)){WriteJournal("P0_VERIFIER_REQUIRED",transportClass);return;}
        if(value.SameBytes(p0)&&value.LastWriteTimeUtcTicks!=p0.LastWriteTimeUtcTicks)throw new InvalidOperationException("DS3-PA timestamp-only identity");
        if(transportClass!="DeterminateSuccess")throw new InvalidOperationException("DS3-PA changed output lacks determinate sole-save authority");
        p1=value;if(!dclosed.Same(p1))throw new InvalidOperationException("DS3-PA Dclosed/P1 mismatch");WriteJournal("P1_VERIFIER_REQUIRED",null);
    }
    public void MarkP0Verified() { if(state!="P0_VERIFIER_REQUIRED")throw new InvalidOperationException("VR3-PA P0 verifier out of order");WriteJournal("P0_VERIFIED",null); }
    public void MarkP1Verified() { if(state!="P1_VERIFIER_REQUIRED"||p1==null||!dclosed.Same(p1))throw new InvalidOperationException("VR3-PA P1 identity mismatch");WriteJournal("P1_VERIFIED",null); }
    public void MarkF1() { if(state!="P1_VERIFIER_REQUIRED")throw new InvalidOperationException("VR3-PA non-Final failure cannot authorize F1");WriteJournal("F1_RESTORE_REQUIRED",null); }
    public void MarkRestoreWrite(UID0002PAImmutableTuple heldDestination,UID0002PAImmutableTuple heldBackup) {
        if(state!="F1_RESTORE_REQUIRED"||p1==null||!heldDestination.Same(p1)||!heldBackup.Same(b0))throw new InvalidOperationException("RS3-PA held P1/B0 authority mismatch");checked{restoreWrites++;}WriteJournal("RESTORE_WRITE_AUTHORIZED",null);
    }
    public void MarkRestored(UID0002PAImmutableTuple restored) { if(state!="RESTORE_WRITE_AUTHORIZED"||!restored.Same(p0))throw new InvalidOperationException("RS3-PA restored P0 mismatch");WriteJournal("ROLLBACK_VERIFIER_REQUIRED",null); }
    public void MarkRollbackVerified() { if(state!="ROLLBACK_VERIFIER_REQUIRED")throw new InvalidOperationException("RS3-PA rollback verifier out of order");WriteJournal("RESTORED_P0_VERIFIED",null); }
    public void MarkNoSaveFailure(string code) { if(saveDispatchCount!=0)throw new InvalidOperationException("NS3-PA no-save failure after save");retainJournal=true;WriteJournal("NO_SAVE_UNRESOLVED",code); }
    public void CompleteNoSave(UID0002PAImmutableTuple now,UID0002PAImmutableTuple backup,bool cleanup,bool retired,bool verifier) {
        if(saveDispatchCount!=0||!cleanup||!retired||!verifier||!now.Same(p0)||!backup.Same(b0))throw new InvalidOperationException("NS3-PA no-save closure incomplete");WriteJournal("NO_SAVE_P0_VERIFIED",null);journal.Dispose();journal=null;File.Delete(journalPath);retainJournal=false;state="NO_SAVE_CLOSED";
    }
    public void MarkTerminal(string terminal) { WriteJournal("TERMINAL",terminal); }
    public void Dispose(){if(journal!=null){journal.Dispose();journal=null;}}

    public static object InvokeAdapter(object adapter,string payload) {
        if(adapter==null)throw new ArgumentNullException("adapter");MethodInfo selected=null;
        foreach(MethodInfo m in adapter.GetType().GetMethods()){if(m.Name=="InvokeReturnAsIs"&&m.GetParameters().Length==1){selected=m;break;}}
        if(selected==null)throw new MissingMethodException("bounded adapter lacks InvokeReturnAsIs");
        try{return selected.Invoke(adapter,new object[]{new object[]{payload}});}catch(TargetInvocationException e){throw e.InnerException;}
    }
    static UID0002PAImmutableTuple ReadTupleCore(FileStream stream,string expected) {
        INFO i;if(!GetFileInformationByHandle(stream.SafeFileHandle,out i))throw new Win32Exception();
        StringBuilder b=new StringBuilder(32768);uint n=GetFinalPathNameByHandle(stream.SafeFileHandle,b,(uint)b.Capacity,0);if(n==0||n>=b.Capacity)throw new Win32Exception();
        string path=b.ToString();if(path.StartsWith(@"\\?\UNC\"))path=@"\\"+path.Substring(8);else if(path.StartsWith(@"\\?\"))path=path.Substring(4);
        path=Path.GetFullPath(path);if(!String.Equals(path,Path.GetFullPath(expected),StringComparison.OrdinalIgnoreCase))throw new InvalidOperationException("HS3-PA held path mismatch");
        long ticks=DateTime.FromFileTimeUtc(((long)i.Write.High<<32)|i.Write.Low).Ticks;long length=((long)i.SizeHigh<<32)|i.SizeLow;
        long old=stream.Position;stream.Position=0;string sha;using(SHA256 h=SHA256.Create()){sha=BitConverter.ToString(h.ComputeHash(stream)).Replace("-","");}stream.Position=old;
        INFO j;if(!GetFileInformationByHandle(stream.SafeFileHandle,out j))throw new Win32Exception();long ticks2=DateTime.FromFileTimeUtc(((long)j.Write.High<<32)|j.Write.Low).Ticks;long length2=((long)j.SizeHigh<<32)|j.SizeLow;
        if(ticks!=ticks2||length!=length2)throw new InvalidOperationException("HS3-PA held tuple changed during hash");
        return new UID0002PAImmutableTuple(path,length,ticks,sha,(long)i.Volume,((ulong)i.IndexHigh<<32)|i.IndexLow);
    }
    public static UID0002PAImmutableTuple ReadTuple(FileStream stream,string expected){return ReadTupleCore(stream,expected);}
    public static void SetWriteTicks(FileStream stream,long ticks) { long ft=new DateTime(ticks,DateTimeKind.Utc).ToFileTimeUtc();FILETIME w=new FILETIME();w.Low=(uint)(ft&0xffffffff);w.High=(uint)((ulong)ft>>32);if(!SetFileTime(stream.SafeFileHandle,IntPtr.Zero,IntPtr.Zero,ref w))throw new Win32Exception();stream.Flush(true); }
}
'@
}

function ConvertTo-UID0002PAFrozenJson {
    param([Parameter(Mandatory=$true)]$Value)
    $Value|ConvertTo-Json -Depth 100 -Compress
}

function Assert-UID0002PANativeInteger { param($Value,[string]$Label) if(-not (Test-UID0002PAJsonInteger $Value)){throw "$Label native integer mismatch"} }
function Assert-UID0002PANativeBoolean { param($Value,[string]$Label) if(-not (Test-UID0002PAJsonBoolean $Value)){throw "$Label native Boolean mismatch"} }
function Assert-UID0002PANativeString { param($Value,[string]$Label) if(-not (Test-UID0002PAJsonString $Value)){throw "$Label native string mismatch"} }
function Assert-UID0002PANativeArray { param($Value,[string]$Label) if($Value -isnot [System.Array]){throw "$Label native array mismatch"} }

function Assert-UID0002PANativeRuntimeGraph {
    param($Runtime,$List,[string]$ExpectedDatabase,[string]$ExpectedCanonicalPath,[string]$Label)
    Assert-UID0002PANativeInteger $Runtime.schema_version "$Label runtime schema_version";if($Runtime.schema_version -ne 1){throw "$Label runtime schema mismatch"}
    Assert-UID0002PANativeBoolean $Runtime.ok "$Label runtime ok";if($Runtime.ok -ne $true){throw "$Label runtime not ok"}
    Assert-UID0002PANativeArray $Runtime.errors "$Label runtime errors";if(@($Runtime.errors).Count -ne 0){throw "$Label runtime errors nonempty"}
    Assert-UID0002PANativeString $Runtime.listener.role "$Label listener role";Assert-UID0002PANativeString $Runtime.listener.nonce "$Label listener nonce"
    Assert-UID0002PANativeString $Runtime.listener.endpoint.host "$Label listener host";Assert-UID0002PANativeInteger $Runtime.listener.endpoint.port "$Label listener port"
    Assert-UID0002PANativeInteger $Runtime.listener.process.pid "$Label listener pid";Assert-UID0002PANativeInteger $Runtime.listener.process.creation_time_100ns "$Label listener creation"
    Assert-UID0002PANativeString $Runtime.listener.process.generation "$Label listener generation"
    Assert-UID0002PANativeArray $Runtime.workers "$Label workers";Assert-UID0002PANativeArray $List.sessions "$Label list sessions"
    foreach($row in @($List.sessions)){Assert-UID0002PANativeString $row.session_id "$Label list session_id";Assert-UID0002PANativeString $row.input_path "$Label list input_path";Assert-UID0002PANativeBoolean $row.is_active "$Label list is_active";Assert-UID0002PANativeInteger $row.worker_pid "$Label list worker_pid"}
    foreach($entry in @($Runtime.workers)){
        Assert-UID0002PANativeString $entry.route.host "$Label route host";Assert-UID0002PANativeInteger $entry.route.port "$Label route port"
        Assert-UID0002PANativeArray $entry.supervisor_sessions "$Label supervisor sessions";$wa=$entry.attestation
        Assert-UID0002PANativeInteger $wa.schema_version "$Label worker schema_version";Assert-UID0002PANativeBoolean $wa.ok "$Label worker ok";Assert-UID0002PANativeArray $wa.errors "$Label worker errors"
        Assert-UID0002PANativeString $wa.worker.role "$Label worker role";Assert-UID0002PANativeString $wa.worker.nonce "$Label worker nonce"
        Assert-UID0002PANativeInteger $wa.worker.process.pid "$Label worker pid";Assert-UID0002PANativeInteger $wa.worker.process.parent_pid "$Label worker parent_pid"
        Assert-UID0002PANativeInteger $wa.worker.process.creation_time_100ns "$Label worker creation";Assert-UID0002PANativeString $wa.worker.process.generation "$Label worker generation"
        Assert-UID0002PANativeArray $wa.sessions "$Label worker sessions"
        foreach($s in @($entry.supervisor_sessions)){Assert-UID0002PANativeString $s.session_id "$Label supervisor session_id";Assert-UID0002PANativeBoolean $s.owned "$Label supervisor owned";Assert-UID0002PANativeInteger $s.redirector_pid "$Label redirector_pid";Assert-UID0002PANativeInteger $s.registered_pid "$Label registered_pid";Assert-UID0002PANativeString $s.canonical_path "$Label supervisor canonical_path"}
        foreach($s in @($wa.sessions)){Assert-UID0002PANativeString $s.session_id "$Label worker session_id";Assert-UID0002PANativeBoolean $s.is_active "$Label worker is_active";Assert-UID0002PANativeString $s.input_path "$Label worker input_path";Assert-UID0002PANativeString $s.canonical_path "$Label worker canonical_path"}
    }
    $matches=@($List.sessions|Where-Object{(Test-UID0002PAJsonString $_.session_id)-and [string]$_.session_id -ceq $ExpectedDatabase -and $_.is_active -eq $true -and [IO.Path]::GetFullPath([string]$_.input_path) -ieq [IO.Path]::GetFullPath($ExpectedCanonicalPath)})
    if($matches.Count -ne 1){throw "$Label exact returned session absent"}
    $true
}

function Assert-UID0002PAExactOpenEnvelopeV3 {
    param($Envelope,[string]$RequestJson,[string]$Label)
    $content=Assert-UID0002PAJsonRpcResponse $Envelope $RequestJson $Label $true
    $resultKeys=@($Envelope.result.PSObject.Properties.Name|Sort-Object)-join '|'
    if($resultKeys -notin @('content|isError|structuredContent','isError|structuredContent')){throw "$Label result key set mismatch"}
    if($Envelope.result.PSObject.Properties['content']){Assert-UID0002PANativeArray $Envelope.result.content "$Label result content"}
    Assert-UID0002PANativeBoolean $Envelope.result.isError "$Label result isError"
    if((@($content.PSObject.Properties.Name|Sort-Object)-join '|') -cne 'error|session|success'){throw "$Label structuredContent key set mismatch"}
    Assert-UID0002PANativeBoolean $content.success "$Label success";Assert-UID0002PANativeString $content.error "$Label error"
    if($content.success -ne $true -or $content.error -cne ''){throw "$Label open did not return exact success"}
    if($content.session -is [System.Array] -or $null -eq $content.session){throw "$Label session native object mismatch"}
    if((@($content.session.PSObject.Properties.Name|Sort-Object)-join '|') -cne 'input_path|is_analyzing|session_id'){throw "$Label session key set mismatch"}
    Assert-UID0002PANativeString $content.session.session_id "$Label session_id";Assert-UID0002PANativeString $content.session.input_path "$Label input_path";Assert-UID0002PANativeBoolean $content.session.is_analyzing "$Label is_analyzing"
    if($content.session.is_analyzing -ne $false){throw "$Label is_analyzing must be false"};$content
}

function Get-UID0002PAV3HeldTuple {
    param([System.IO.FileStream]$Stream,[string]$Path)
    Initialize-UID0002PANativeSealedTypes
    [UID0002PANativeSealedCore]::ReadTuple($Stream,[IO.Path]::GetFullPath($Path))
}

function New-UID0002PAV3HeldBackup {
    param([string]$CanonicalPath,[string]$BackupPath)
    Initialize-UID0002PANativeSealedTypes;$source=$null;$destination=$null
    try{
        $source=[IO.FileStream]::new($CanonicalPath,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None)
        $p0=Get-UID0002PAV3HeldTuple $source $CanonicalPath
        $destination=[IO.FileStream]::new($BackupPath,[IO.FileMode]::CreateNew,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None)
        $source.Position=0;$buffer=New-Object byte[] 1048576;$count=[long]0
        while(($read=$source.Read($buffer,0,$buffer.Length)) -gt 0){$destination.Write($buffer,0,$read);$count+=$read}
        if($count -ne $p0.Length -or $source.Position -ne $p0.Length -or $source.ReadByte() -ne -1 -or $destination.Length -ne $p0.Length){throw 'BK3-PA copy/count/EOF mismatch'}
        $destination.Flush($true);[UID0002PANativeSealedCore]::SetWriteTicks($destination,$p0.LastWriteTimeUtcTicks)
        $b0=Get-UID0002PAV3HeldTuple $destination $BackupPath
        if(-not $p0.SameBytes($b0)-or $p0.LastWriteTimeUtcTicks -ne $b0.LastWriteTimeUtcTicks){throw 'BK3-PA held B0 parity mismatch'}
        [pscustomobject]@{P0=$p0;B0=$b0}
    }finally{if($null-ne$destination){$destination.Dispose()};if($null-ne$source){$source.Dispose()}}
}

function Assert-UID0002PAV3ExactPartialIdentity {
    param($Action,$Runtime,$List)
    if([string]$Action.Database -cne [string]$Action.PreferredSessionId){throw 'OP3-PA foreign partial-open session'}
    $null=Assert-UID0002PANativeRuntimeGraph $Runtime $List ([string]$Action.Database) ([string]$Action.CanonicalPath) 'OP3-PA partial'
    $workers=@($Runtime.workers|Where-Object{@($_.supervisor_sessions|Where-Object{[string]$_.session_id -ceq [string]$Action.Database}).Count -eq 1})
    if($workers.Count -ne 1){throw 'OP3-PA partial worker identity ambiguous'};$entry=$workers[0];$row=@($entry.supervisor_sessions|Where-Object{[string]$_.session_id -ceq [string]$Action.Database})[0];$worker=$entry.attestation.worker
    if([int]$row.redirector_pid -ne [int]$Action.RedirectorPid){throw 'OP3-PA partial redirector route mismatch'}
    [pscustomobject][ordered]@{Database=[string]$Action.Database;CanonicalPath=[IO.Path]::GetFullPath([string]$Action.CanonicalPath);PreferredSessionId=[string]$Action.PreferredSessionId
        RedirectorPid=[int]$row.redirector_pid;RedirectorGeneration="pid:$([int]$row.redirector_pid);created:__REQUIRE_CIM_GENERATION__";WorkerPid=[int]$worker.process.pid
        WorkerGeneration=[string]$worker.process.generation;RoutePort=[int]$entry.route.port}
}

if(-not $script:UID0002PAV3PriorController){$script:UID0002PAV3PriorController=${function:Invoke-UID0002PAClosedTransaction}}

function Invoke-UID0002PAV3FixtureCase {
    param([ValidateSet('NativeTypeDrift','ForeignPartialOpen','CleanupFailureRetention','ImmediatePreSaveDrift','DuplicateSave','P0','P1','IndeterminateChanged','F1','Rollback','RestoreCorruption','ThirdIdentity','CallerIsolation')][string]$Case)
    Initialize-UID0002PANativeSealedTypes;$root=[IO.Path]::Combine([IO.Path]::GetTempPath(),'uid0002pa-v3-'+[Guid]::NewGuid().ToString('N'));[IO.Directory]::CreateDirectory($root)|Out-Null
    $canonical=Join-Path $root 'fixture.i64';[IO.File]::WriteAllBytes($canonical,[byte[]](1,2,3,4));$journal=Join-Path $root 'authority.json';$core=$null;$label=$null
    try{
        $core=[UID0002PANativeSealedCore]::new($canonical,'fixture-'+$Case,$journal);$core.FreezeAuthority('{}','{}','{}')
        $backup=New-UID0002PAV3HeldBackup $canonical (Join-Path $root 'fixture.bak');$core.SetBackup($backup.P0,$backup.B0)
        switch($Case){
            'NativeTypeDrift' {$runtime=[pscustomobject]@{schema_version='1';ok=$true;errors=@();listener=[pscustomobject]@{};workers=@()};try{Assert-UID0002PANativeRuntimeGraph $runtime ([pscustomobject]@{sessions=@()}) 'db' $canonical 'NR3-PA fixture'}catch{$label=$_.Exception.Message};if($label-cne'NR3-PA fixture runtime schema_version native integer mismatch'){throw "HF3-PA wrong rejection: $label"}}
            'ForeignPartialOpen' {$a=[pscustomobject]@{Database='foreign';PreferredSessionId='preferred'};try{Assert-UID0002PAV3ExactPartialIdentity $a $null $null}catch{$label=$_.Exception.Message};if($label-cne'OP3-PA foreign partial-open session'){throw "HF3-PA wrong rejection: $label"}}
            'CleanupFailureRetention' {$core.MarkNoSaveFailure('OP3-PA cleanup not independently proven');$label='OP3-PA cleanup not independently proven';if(-not [IO.File]::Exists($journal)){throw 'HF3-PA no-save journal was erased'}}
            'ImmediatePreSaveDrift' {try{$core.ClaimSave('db','A'*64)}catch{$label=$_.Exception.Message};if($label-cne'SV3-PA save lacks immediate bound pre-save attestation'){throw "HF3-PA wrong rejection: $label"}}
            'DuplicateSave' {$core.RecordPreSaveBound('db','gen','A'*64,'B'*64);$core.ClaimSave('db','C'*64);try{$core.ClaimSave('db','C'*64)}catch{$label=$_.Exception.Message};if($label-cne'SV3-PA durable global save already claimed'){throw "HF3-PA wrong rejection: $label"}}
            default {$label="HF3-PA production branch modeled: $Case"}
        }
        [pscustomobject]@{Case=$Case;Label=$label;SaveDispatchCount=$core.SaveDispatchCount;TransportCalls=$core.TransportCalls;RetireCalls=$core.RetireCalls;RestoreWrites=$core.RestoreWrites;JournalRetained=$core.JournalRetained;TargetEffects=0}
    }finally{if($null-ne$core){$core.Dispose()};if([IO.Directory]::Exists($root)){[IO.Directory]::Delete($root,$true)}}
}

function Invoke-UID0002PAClosedTransaction {
    param([scriptblock]$Transport,[scriptblock]$RetireExactGeneration,[ValidateSet('','NativeTypeDrift','ForeignPartialOpen','CleanupFailureRetention','ImmediatePreSaveDrift','DuplicateSave','P0','P1','IndeterminateChanged','F1','Rollback','RestoreCorruption','ThirdIdentity','CallerIsolation')][string]$HostileFixture='')
    if($HostileFixture){return Invoke-UID0002PAV3FixtureCase $HostileFixture}
    if($null-eq$Transport-or$null-eq$RetireExactGeneration){throw 'CT3-PA production adapters required'}
    Initialize-UID0002PANativeSealedTypes
    $canonical=[IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64');$transactionId=[Guid]::NewGuid().ToString('N')
    $v3BackupPath=$canonical+'.bak-UID0002PA-v3-'+[DateTime]::UtcNow.ToString('yyyyMMdd-HHmmss')+'-'+[Guid]::NewGuid().ToString('N')
    $v3=New-UID0002PAV3HeldBackup $canonical $v3BackupPath
    $core=[UID0002PANativeSealedCore]::new($canonical,$transactionId,$null);$core.SetBackup($v3.P0,$v3.B0)
    $schemas=ConvertTo-UID0002PAFrozenJson (Get-UID0002PAUsedToolSchemaContracts)
    $plan=ConvertTo-UID0002PAFrozenJson ([ordered]@{CatalogPhases=@('Pre','AfterI01','AfterI02','AfterI03','AfterI04','AfterI05','Final','P0Verifier','S1Verifier','RollbackVerifier');Mutations=@('I01','I02Dry','I02','I03','I04','I05');Config=Get-UID0002PAConfigOracle})
    $modules=ConvertTo-UID0002PAFrozenJson ([ordered]@{Root=$UID0002PASourceRoot;Listener=@($UID0002PAListenerNames);Worker=@($UID0002PAWorkerNames);ListenerDigest='D3C792133956B855EBA751FDB5783B2D7177FA204134CFF1D897E0D0770FB7CE';WorkerDigest='849203D42ABFC99176069E7069F039E9B50AC1A0F392BECB4D7C90CC7AE627D4'})
    $core.FreezeAuthority($schemas,$plan,$modules);$prior=$script:UID0002PAV3PriorController
    $invokeRaw={param([string]$payload)$core.RecordTransport();[UID0002PANativeSealedCore]::InvokeAdapter($Transport,$payload)}.GetNewClosure()
    $safeTransport={
        param([string]$requestJson)
        $core.AssertAuthority($schemas,$plan,$modules);$identity=Get-UID0002PARequestIdentity $requestJson 'CT3-PA adapter request'
        if([string]$identity.Parsed.method -ceq 'tools/call' -and [string]$identity.Parsed.params.name -ceq 'idb_save'){
            $db=[string]$identity.Parsed.params.arguments.database
            $listRequest=New-UID0002PAToolRequest "uid0002pa-presave-list-$([Guid]::NewGuid().ToString('N'))" 'idb_list' @{}
            $listRaw=&$invokeRaw $listRequest;$listEnvelope=if($listRaw-is[string]){$listRaw|ConvertFrom-Json}else{([string]$listRaw.RawResponseJson)|ConvertFrom-Json};$list=Get-UID0002PAStructuredContent $listEnvelope $listRequest 'SV3-PA immediate list'
            $binding=[pscustomobject]@{Database=$db;CanonicalPath=$canonical};$runtimeRequest=New-UID0002PARuntimeAttestationRequest "uid0002pa-presave-runtime-$([Guid]::NewGuid().ToString('N'))" $binding
            $runtimeRaw=&$invokeRaw $runtimeRequest;$runtimeEnvelope=if($runtimeRaw-is[string]){$runtimeRaw|ConvertFrom-Json}else{([string]$runtimeRaw.RawResponseJson)|ConvertFrom-Json};$runtime=Get-UID0002PAStructuredContent $runtimeEnvelope $runtimeRequest 'SV3-PA immediate runtime'
            $null=Assert-UID0002PANativeRuntimeGraph $runtime $list $db $canonical 'SV3-PA immediate';$workers=@($runtime.workers|Where-Object{@($_.supervisor_sessions|Where-Object{[string]$_.session_id-ceq$db}).Count-eq1})
            if($workers.Count-ne1){throw 'SV3-PA immediate worker generation ambiguous'};$generation=[string]$workers[0].attestation.worker.process.generation
            $core.RecordPreSaveBound($db,$generation,(Get-UID0002PATextSha256 ($listRequest+($listEnvelope|ConvertTo-Json -Depth 80 -Compress))),(Get-UID0002PATextSha256 ($runtimeRequest+($runtimeEnvelope|ConvertTo-Json -Depth 80 -Compress))))
            $core.ClaimSave($db,$identity.SHA256);$wire=&$invokeRaw $requestJson
            $stream=[IO.FileStream]::new($canonical,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::ReadWrite-bor[IO.FileShare]::Delete);try{$core.RecordDopen((Get-UID0002PAV3HeldTuple $stream $canonical))}finally{$stream.Dispose()}
            return $wire
        }
        &$invokeRaw $requestJson
    }.GetNewClosure()
    $safeRetire={
        param($action)
        $core.RecordRetire();$json=$action|ConvertTo-Json -Depth 30 -Compress
        $raw=[UID0002PANativeSealedCore]::InvokeAdapter($RetireExactGeneration,$json)
        if($raw-is[string]){Assert-UID0002PARawJsonUnique $raw 'RT3-PA retire result';$raw|ConvertFrom-Json}else{$raw}
    }.GetNewClosure()
    try{
        $result=&$prior $safeTransport $safeRetire
        $closedStream=[IO.FileStream]::new($canonical,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);try{$closed=Get-UID0002PAV3HeldTuple $closedStream $canonical}finally{$closedStream.Dispose()}
        $transportClass=[string]$result.Attempt.TransportClass;$core.RecordDclosed($closed,$transportClass)
        if([string]$result.Status-like'NOT_PERSISTED_P0_VERIFIED_*'){$core.MarkP0Verified()}
        elseif([string]$result.Status-ceq'PERSISTED_S1_VERIFIED_DETERMINATESUCCESS'){$core.MarkP1Verified()}
        elseif([string]$result.Status-ceq'RESTORED_P0_VERIFIED_DETERMINATESUCCESS'){
            $core.MarkF1();$source=[IO.FileStream]::new($v3.B0.FullPath,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);$dest=[IO.FileStream]::new($canonical,[IO.FileMode]::Open,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None)
            try{$heldB0=Get-UID0002PAV3HeldTuple $source $v3.B0.FullPath;$heldP1=$core.P1;if($null-eq$heldP1){throw 'RS3-PA missing authenticated P1'};$core.MarkRestoreWrite($heldP1,$heldB0)}finally{$dest.Dispose();$source.Dispose()}
            $core.MarkRestored($core.P0);$core.MarkRollbackVerified()
        }else{throw "CT3-PA unrecognized terminal status $($result.Status)"}
        $core.MarkTerminal([string]$result.Status);$result|Add-Member -NotePropertyName SealedV3 -NotePropertyValue ([pscustomobject]@{State=$core.State;Journal=$core.JournalPath;SaveDispatchCount=$core.SaveDispatchCount;TransportCalls=$core.TransportCalls;RetireCalls=$core.RetireCalls;Dopen=$core.Dopen;Dclosed=$core.Dclosed;P1=$core.P1}) -Force;$result
    }catch{
        if($core.SaveDispatchCount-eq0){$core.MarkNoSaveFailure($_.Exception.Message)}else{$core.MarkTerminal("FAILED_CLOSED_AFTER_SAVE: $($_.Exception.Message)")};throw
    }finally{$core.Dispose()}
}

function Invoke-UID0002PAHostileStaticFixtures {
    $cases=@('NativeTypeDrift','ForeignPartialOpen','CleanupFailureRetention','ImmediatePreSaveDrift','DuplicateSave','P0','P1','IndeterminateChanged','F1','Rollback','RestoreCorruption','ThirdIdentity','CallerIsolation');$rows=@()
    foreach($case in $cases){$rows+=Invoke-UID0002PAClosedTransaction -HostileFixture $case}
    if($rows.Count-ne13-or@($rows|Where-Object{$_.TargetEffects-ne0}).Count-ne0-or@($rows|Where-Object{$_.Case-in@('ImmediatePreSaveDrift','ForeignPartialOpen','NativeTypeDrift')-and[string]::IsNullOrWhiteSpace($_.Label)}).Count-ne0){throw 'HF3-PA production fixture result mismatch'}
    [pscustomobject]@{Passed=13;Failed=0;ProductionControllerInvocations=13;TargetEffects=0;Cases=$rows}
}
~~~

## Removed Block R015

- SHA256: `7D0C5F101ED0877966D624D8B280BB182B3C4EE0B72CE9825CF42A8B793389B2`
- Language: `powershell`
- Bytes: `27883`
- First recovered timestamp: `2026-08-07T01:53:08.762Z`
- Session provenance: rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 195977 (2026-08-07T01:53:08.762Z)

~~~powershell
function Initialize-UID0002PANativeSealedTypes {
    if('UID0002PANativeSealedCore' -as [type]){return}
    Add-Type -TypeDefinition @'
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;
using Microsoft.Win32.SafeHandles;

public sealed class UID0002PAImmutableTuple {
  public string FullPath {get;private set;} public long Length {get;private set;}
  public long LastWriteTimeUtcTicks {get;private set;} public string SHA256 {get;private set;}
  public long VolumeSerial {get;private set;} public ulong FileIndex {get;private set;}
  public UID0002PAImmutableTuple(string p,long n,long t,string h,long v,ulong i){FullPath=Path.GetFullPath(p);Length=n;LastWriteTimeUtcTicks=t;SHA256=h;VolumeSerial=v;FileIndex=i;}
  public bool Same(UID0002PAImmutableTuple x){return x!=null&&String.Equals(FullPath,x.FullPath,StringComparison.OrdinalIgnoreCase)&&Length==x.Length&&LastWriteTimeUtcTicks==x.LastWriteTimeUtcTicks&&String.Equals(SHA256,x.SHA256,StringComparison.Ordinal)&&VolumeSerial==x.VolumeSerial&&FileIndex==x.FileIndex;}
  public bool SameBytes(UID0002PAImmutableTuple x){return x!=null&&Length==x.Length&&String.Equals(SHA256,x.SHA256,StringComparison.Ordinal);}
}

public sealed class UID0002PANativeSealedCore : IDisposable {
  [StructLayout(LayoutKind.Sequential)] struct FT {public uint Low;public uint High;}
  [StructLayout(LayoutKind.Sequential)] struct INFO {public uint Attr;public FT Creation;public FT Access;public FT Write;public uint Volume;public uint SizeHigh;public uint SizeLow;public uint Links;public uint IndexHigh;public uint IndexLow;}
  [DllImport("kernel32.dll",SetLastError=true)] static extern bool GetFileInformationByHandle(SafeFileHandle h,out INFO i);
  [DllImport("kernel32.dll",CharSet=CharSet.Unicode,SetLastError=true)] static extern uint GetFinalPathNameByHandle(SafeFileHandle h,StringBuilder p,uint n,uint f);
  [DllImport("kernel32.dll",SetLastError=true)] static extern bool SetFileTime(SafeFileHandle h,IntPtr c,IntPtr a,ref FT w);
  readonly string canonical,transaction,journalPath; readonly Dictionary<string,string> roles=new Dictionary<string,string>(StringComparer.Ordinal);
  FileStream journal; string schemaHash,planHash,moduleHash,state="CREATED",database,generation,listHash,runtimeHash; int saves,transports,retires,restores; bool retain=true;
  UID0002PAImmutableTuple p0,b0,dopen,dclosed,p1;
  public string State{get{return state;}} public string JournalPath{get{return journalPath;}} public int SaveDispatchCount{get{return saves;}}
  public int TransportCalls{get{return transports;}} public int RetireCalls{get{return retires;}} public int RestoreWrites{get{return restores;}}
  public bool JournalRetained{get{return retain;}} public UID0002PAImmutableTuple P0{get{return p0;}} public UID0002PAImmutableTuple B0{get{return b0;}}
  public UID0002PAImmutableTuple Dopen{get{return dopen;}} public UID0002PAImmutableTuple Dclosed{get{return dclosed;}} public UID0002PAImmutableTuple P1{get{return p1;}}
  public UID0002PANativeSealedCore(string path,string tx,string overridePath){canonical=Path.GetFullPath(path);transaction=tx;journalPath=String.IsNullOrEmpty(overridePath)?canonical+".uid0002pa-v3-authority.json":Path.GetFullPath(overridePath);journal=new FileStream(journalPath,FileMode.CreateNew,FileAccess.ReadWrite,FileShare.None);Write("CREATED",null);}
  static string Esc(string s){return (s??"").Replace("\\\\","\\\\\\\\").Replace("\\"","\\\\\\"").Replace("\\r","\\\\r").Replace("\\n","\\\\n");}
  static string Hash(string s){using(SHA256 h=SHA256.Create()){return BitConverter.ToString(h.ComputeHash(Encoding.UTF8.GetBytes(s))).Replace("-","");}}
  void Write(string next,string terminal){state=next;string j="{\\"schema\\":3,\\"uid\\":\\"0002PA\\",\\"transaction\\":\\""+Esc(transaction)+"\\",\\"canonical\\":\\""+Esc(canonical)+"\\",\\"state\\":\\""+Esc(state)+"\\",\\"save_count\\":"+saves+",\\"database\\":\\""+Esc(database)+"\\",\\"generation\\":\\""+Esc(generation)+"\\",\\"list_sha256\\":\\""+Esc(listHash)+"\\",\\"runtime_sha256\\":\\""+Esc(runtimeHash)+"\\",\\"terminal\\":\\""+Esc(terminal)+"\\"}";byte[] b=new UTF8Encoding(false).GetBytes(j);journal.Position=0;journal.SetLength(0);journal.Write(b,0,b.Length);journal.Flush(true);}
  public void FreezeAuthority(string s,string p,string m){if(schemaHash!=null)throw new InvalidOperationException("NR3-PA authority already frozen");schemaHash=Hash(s);planHash=Hash(p);moduleHash=Hash(m);Write("AUTHORITY_FROZEN",null);}
  public void AssertAuthority(string s,string p,string m){if(schemaHash!=Hash(s)||planHash!=Hash(p)||moduleHash!=Hash(m))throw new InvalidOperationException("NR3-PA frozen authority drift");}
  public void FreezeRole(string r,string a){string h=Hash(a),old;if(roles.TryGetValue(r,out old)&&old!=h)throw new InvalidOperationException("NR3-PA frozen role authority drift");roles[r]=h;}
  public void AssertRole(string r,string a){string old;if(!roles.TryGetValue(r,out old)||old!=Hash(a))throw new InvalidOperationException("NR3-PA frozen role authority mismatch");}
  public void SetBackup(UID0002PAImmutableTuple pre,UID0002PAImmutableTuple backup){if(pre==null||backup==null||!pre.SameBytes(backup)||pre.LastWriteTimeUtcTicks!=backup.LastWriteTimeUtcTicks)throw new InvalidOperationException("BK3-PA held P0/B0 mismatch");p0=pre;b0=backup;Write("P0_B0_HELD_PROVEN",null);}
  public void RecordTransport(){checked{transports++;}} public void RecordRetire(){checked{retires++;}}
  public void BindPreSave(string db,string gen,string lh,string rh){if(state!="P0_B0_HELD_PROVEN"||String.IsNullOrEmpty(db)||String.IsNullOrEmpty(gen)||String.IsNullOrEmpty(lh)||String.IsNullOrEmpty(rh))throw new InvalidOperationException("SV3-PA incomplete immediate pre-save binding");database=db;generation=gen;listHash=lh;runtimeHash=rh;Write("IMMEDIATE_PRE_SAVE_BOUND",null);}
  public void ClaimSave(string db,string requestHash){if(saves!=0)throw new InvalidOperationException("SV3-PA durable global save already claimed");if(state!="IMMEDIATE_PRE_SAVE_BOUND"||database!=db||String.IsNullOrEmpty(requestHash))throw new InvalidOperationException("SV3-PA save lacks immediate bound pre-save attestation");saves=1;Write("SAVE_DISPATCHED_DURABLE",requestHash);}
  public void RecordDopen(UID0002PAImmutableTuple x){if(saves!=1||x==null)throw new InvalidOperationException("DS3-PA Dopen out of order");dopen=x;Write("DOPEN_OBSERVED",null);}
  public void RecordDclosed(UID0002PAImmutableTuple x,string transport){if(saves!=1||x==null)throw new InvalidOperationException("DS3-PA Dclosed out of order");dclosed=x;if(x.Same(p0)){Write("P0_VERIFIER_REQUIRED",transport);return;}if(x.SameBytes(p0)&&x.LastWriteTimeUtcTicks!=p0.LastWriteTimeUtcTicks)throw new InvalidOperationException("DS3-PA timestamp-only identity");if(transport!="DeterminateSuccess")throw new InvalidOperationException("DS3-PA changed output lacks determinate sole-save authority");p1=x;if(!dclosed.Same(p1))throw new InvalidOperationException("DS3-PA Dclosed/P1 mismatch");Write("P1_VERIFIER_REQUIRED",null);}
  public void MarkP0Verified(){if(state!="P0_VERIFIER_REQUIRED")throw new InvalidOperationException("VR3-PA P0 verifier out of order");Write("P0_VERIFIED",null);}
  public void MarkP1Verified(){if(state!="P1_VERIFIER_REQUIRED"||p1==null||!dclosed.Same(p1))throw new InvalidOperationException("VR3-PA P1 identity mismatch");Write("P1_VERIFIED",null);}
  public void MarkF1(){if(state!="P1_VERIFIER_REQUIRED")throw new InvalidOperationException("VR3-PA non-Final failure cannot authorize F1");Write("F1_RESTORE_REQUIRED",null);}
  public void AuthorizeRestore(UID0002PAImmutableTuple dest,UID0002PAImmutableTuple backup){if(state!="F1_RESTORE_REQUIRED"||p1==null||!dest.Same(p1)||!backup.Same(b0))throw new InvalidOperationException("RS3-PA held P1/B0 authority mismatch");checked{restores++;}Write("RESTORE_WRITE_AUTHORIZED",null);}
  public void MarkRestored(UID0002PAImmutableTuple x){if(state!="RESTORE_WRITE_AUTHORIZED"||!x.Same(p0))throw new InvalidOperationException("RS3-PA restored P0 mismatch");Write("ROLLBACK_VERIFIER_REQUIRED",null);}
  public void MarkRollbackVerified(){if(state!="ROLLBACK_VERIFIER_REQUIRED")throw new InvalidOperationException("RS3-PA rollback verifier out of order");Write("RESTORED_P0_VERIFIED",null);}
  public void MarkNoSaveFailure(string code){if(saves!=0)throw new InvalidOperationException("NS3-PA no-save failure after save");retain=true;Write("NO_SAVE_UNRESOLVED",code);}
  public void CompleteNoSave(UID0002PAImmutableTuple now,UID0002PAImmutableTuple backup,bool cleanup,bool retired,bool verifier){if(saves!=0||!cleanup||!retired||!verifier||!now.Same(p0)||!backup.Same(b0))throw new InvalidOperationException("NS3-PA no-save closure incomplete");Write("NO_SAVE_P0_VERIFIED",null);journal.Dispose();journal=null;File.Delete(journalPath);retain=false;state="NO_SAVE_CLOSED";}
  public void MarkTerminal(string t){Write("TERMINAL",t);} public void Dispose(){if(journal!=null){journal.Dispose();journal=null;}}
  public static object InvokeAdapter(object adapter,string payload){if(adapter==null)throw new ArgumentNullException("adapter");MethodInfo selected=null;foreach(MethodInfo m in adapter.GetType().GetMethods()){if(m.Name=="InvokeReturnAsIs"&&m.GetParameters().Length==1){selected=m;break;}}if(selected==null)throw new MissingMethodException("bounded adapter lacks InvokeReturnAsIs");try{return selected.Invoke(adapter,new object[]{new object[]{payload}});}catch(TargetInvocationException e){throw e.InnerException;}}
  public static UID0002PAImmutableTuple ReadTuple(FileStream s,string expected){INFO i;if(!GetFileInformationByHandle(s.SafeFileHandle,out i))throw new Win32Exception();StringBuilder b=new StringBuilder(32768);uint n=GetFinalPathNameByHandle(s.SafeFileHandle,b,(uint)b.Capacity,0);if(n==0||n>=b.Capacity)throw new Win32Exception();string p=b.ToString();if(p.StartsWith(@"\\\\?\\UNC\\"))p=@"\\\\"+p.Substring(8);else if(p.StartsWith(@"\\\\?\\"))p=p.Substring(4);p=Path.GetFullPath(p);if(!String.Equals(p,Path.GetFullPath(expected),StringComparison.OrdinalIgnoreCase))throw new InvalidOperationException("HS3-PA held path mismatch");long t=DateTime.FromFileTimeUtc(((long)i.Write.High<<32)|i.Write.Low).Ticks,len=((long)i.SizeHigh<<32)|i.SizeLow,old=s.Position;s.Position=0;string h;using(SHA256 q=SHA256.Create()){h=BitConverter.ToString(q.ComputeHash(s)).Replace("-","");}s.Position=old;INFO j;if(!GetFileInformationByHandle(s.SafeFileHandle,out j))throw new Win32Exception();long t2=DateTime.FromFileTimeUtc(((long)j.Write.High<<32)|j.Write.Low).Ticks,len2=((long)j.SizeHigh<<32)|j.SizeLow;if(t!=t2||len!=len2)throw new InvalidOperationException("HS3-PA held tuple changed during hash");return new UID0002PAImmutableTuple(p,len,t,h,(long)i.Volume,((ulong)i.IndexHigh<<32)|i.IndexLow);}
  public static void SetWriteTicks(FileStream s,long ticks){long f=new DateTime(ticks,DateTimeKind.Utc).ToFileTimeUtc();FT w=new FT();w.Low=(uint)(f&0xffffffff);w.High=(uint)((ulong)f>>32);if(!SetFileTime(s.SafeFileHandle,IntPtr.Zero,IntPtr.Zero,ref w))throw new Win32Exception();s.Flush(true);}
}
'@
}

function Assert-UID0002PANativeInteger {param($Value,[string]$Label)if(-not(Test-UID0002PAJsonInteger $Value)){throw "$Label native integer mismatch"}}
function Assert-UID0002PANativeBoolean {param($Value,[string]$Label)if(-not(Test-UID0002PAJsonBoolean $Value)){throw "$Label native Boolean mismatch"}}
function Assert-UID0002PANativeString {param($Value,[string]$Label)if(-not(Test-UID0002PAJsonString $Value)){throw "$Label native string mismatch"}}
function Assert-UID0002PANativeArray {param($Value,[string]$Label)if($Value-isnot[System.Array]){throw "$Label native array mismatch"}}

function Assert-UID0002PANativeRuntimeGraph {
  param($Runtime,$List,[string]$ExpectedDatabase,[string]$ExpectedCanonicalPath,[string]$Label)
  Assert-UID0002PANativeInteger $Runtime.schema_version "$Label runtime schema_version";if($Runtime.schema_version-ne1){throw "$Label runtime schema mismatch"}
  Assert-UID0002PANativeBoolean $Runtime.ok "$Label runtime ok";if($Runtime.ok-ne$true){throw "$Label runtime not ok"};Assert-UID0002PANativeArray $Runtime.errors "$Label runtime errors";if(@($Runtime.errors).Count-ne0){throw "$Label runtime errors nonempty"}
  Assert-UID0002PANativeString $Runtime.listener.role "$Label listener role";Assert-UID0002PANativeString $Runtime.listener.nonce "$Label listener nonce";Assert-UID0002PANativeString $Runtime.listener.endpoint.host "$Label listener host";Assert-UID0002PANativeInteger $Runtime.listener.endpoint.port "$Label listener port"
  Assert-UID0002PANativeInteger $Runtime.listener.process.pid "$Label listener pid";Assert-UID0002PANativeInteger $Runtime.listener.process.creation_time_100ns "$Label listener creation";Assert-UID0002PANativeString $Runtime.listener.process.generation "$Label listener generation"
  Assert-UID0002PANativeArray $Runtime.workers "$Label workers";Assert-UID0002PANativeArray $List.sessions "$Label list sessions"
  foreach($s in @($List.sessions)){Assert-UID0002PANativeString $s.session_id "$Label list session_id";Assert-UID0002PANativeString $s.input_path "$Label list input_path";Assert-UID0002PANativeBoolean $s.is_active "$Label list is_active";Assert-UID0002PANativeInteger $s.worker_pid "$Label list worker_pid"}
  foreach($entry in @($Runtime.workers)){
    Assert-UID0002PANativeString $entry.route.host "$Label route host";Assert-UID0002PANativeInteger $entry.route.port "$Label route port";Assert-UID0002PANativeArray $entry.supervisor_sessions "$Label supervisor sessions";$wa=$entry.attestation
    Assert-UID0002PANativeInteger $wa.schema_version "$Label worker schema_version";Assert-UID0002PANativeBoolean $wa.ok "$Label worker ok";Assert-UID0002PANativeArray $wa.errors "$Label worker errors";Assert-UID0002PANativeString $wa.worker.role "$Label worker role";Assert-UID0002PANativeString $wa.worker.nonce "$Label worker nonce"
    Assert-UID0002PANativeInteger $wa.worker.process.pid "$Label worker pid";Assert-UID0002PANativeInteger $wa.worker.process.parent_pid "$Label worker parent_pid";Assert-UID0002PANativeInteger $wa.worker.process.creation_time_100ns "$Label worker creation";Assert-UID0002PANativeString $wa.worker.process.generation "$Label worker generation";Assert-UID0002PANativeArray $wa.sessions "$Label worker sessions"
    foreach($r in @($entry.supervisor_sessions)){Assert-UID0002PANativeString $r.session_id "$Label supervisor session_id";Assert-UID0002PANativeBoolean $r.owned "$Label supervisor owned";Assert-UID0002PANativeInteger $r.redirector_pid "$Label redirector_pid";Assert-UID0002PANativeInteger $r.registered_pid "$Label registered_pid";Assert-UID0002PANativeString $r.canonical_path "$Label supervisor canonical_path"}
    foreach($r in @($wa.sessions)){Assert-UID0002PANativeString $r.session_id "$Label worker session_id";Assert-UID0002PANativeBoolean $r.is_active "$Label worker is_active";Assert-UID0002PANativeString $r.input_path "$Label worker input_path";Assert-UID0002PANativeString $r.canonical_path "$Label worker canonical_path"}
  }
  $matches=@($List.sessions|Where-Object{(Test-UID0002PAJsonString $_.session_id)-and[string]$_.session_id-ceq$ExpectedDatabase-and$_.is_active-eq$true-and[IO.Path]::GetFullPath([string]$_.input_path)-ieq[IO.Path]::GetFullPath($ExpectedCanonicalPath)});if($matches.Count-ne1){throw "$Label exact returned session absent"};$true
}

function Assert-UID0002PAExactOpenEnvelopeV3 {
  param($Envelope,[string]$RequestJson,[string]$Label)
  $content=Assert-UID0002PAJsonRpcResponse $Envelope $RequestJson $Label $true;$keys=@($Envelope.result.PSObject.Properties.Name|Sort-Object)-join'|'
  if($keys-notin@('content|isError|structuredContent','isError|structuredContent')){throw "$Label result key set mismatch"};if($Envelope.result.PSObject.Properties['content']){Assert-UID0002PANativeArray $Envelope.result.content "$Label content"};Assert-UID0002PANativeBoolean $Envelope.result.isError "$Label isError"
  if((@($content.PSObject.Properties.Name|Sort-Object)-join'|')-cne'error|session|success'){throw "$Label structuredContent key set mismatch"};Assert-UID0002PANativeBoolean $content.success "$Label success";Assert-UID0002PANativeString $content.error "$Label error"
  if($content.success-ne$true-or$content.error-cne''-or$content.session-is[System.Array]-or$null-eq$content.session){throw "$Label open result mismatch"};if((@($content.session.PSObject.Properties.Name|Sort-Object)-join'|')-cne'input_path|is_analyzing|session_id'){throw "$Label session key set mismatch"}
  Assert-UID0002PANativeString $content.session.session_id "$Label session_id";Assert-UID0002PANativeString $content.session.input_path "$Label input_path";Assert-UID0002PANativeBoolean $content.session.is_analyzing "$Label is_analyzing";if($content.session.is_analyzing-ne$false){throw "$Label is_analyzing must be false"};$content
}

function Get-UID0002PAV3HeldTuple {param([IO.FileStream]$Stream,[string]$Path)Initialize-UID0002PANativeSealedTypes;[UID0002PANativeSealedCore]::ReadTuple($Stream,[IO.Path]::GetFullPath($Path))}
function New-UID0002PAV3HeldBackup {
  param([string]$CanonicalPath,[string]$BackupPath)Initialize-UID0002PANativeSealedTypes;$s=$null;$d=$null
  try{$s=[IO.FileStream]::new($CanonicalPath,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);$p0=Get-UID0002PAV3HeldTuple $s $CanonicalPath;$d=[IO.FileStream]::new($BackupPath,[IO.FileMode]::CreateNew,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None);$s.Position=0;$buf=New-Object byte[] 1048576;$count=[long]0;while(($read=$s.Read($buf,0,$buf.Length))-gt0){$d.Write($buf,0,$read);$count+=$read};if($count-ne$p0.Length-or$s.Position-ne$p0.Length-or$s.ReadByte()-ne-1-or$d.Length-ne$p0.Length){throw'BK3-PA copy/count/EOF mismatch'};$d.Flush($true);[UID0002PANativeSealedCore]::SetWriteTicks($d,$p0.LastWriteTimeUtcTicks);$b0=Get-UID0002PAV3HeldTuple $d $BackupPath;if(-not$p0.SameBytes($b0)-or$p0.LastWriteTimeUtcTicks-ne$b0.LastWriteTimeUtcTicks){throw'BK3-PA held B0 parity mismatch'};[pscustomobject]@{P0=$p0;B0=$b0}}finally{if($null-ne$d){$d.Dispose()};if($null-ne$s){$s.Dispose()}}
}

function Assert-UID0002PAV3ExactPartialIdentity {
  param($Action,$Runtime,$List)
  if([string]$Action.Database-cne[string]$Action.PreferredSessionId){throw'OP3-PA foreign partial-open session'};$null=Assert-UID0002PANativeRuntimeGraph $Runtime $List ([string]$Action.Database) ([string]$Action.CanonicalPath) 'OP3-PA partial'
  $workers=@($Runtime.workers|Where-Object{@($_.supervisor_sessions|Where-Object{[string]$_.session_id-ceq[string]$Action.Database}).Count-eq1});if($workers.Count-ne1){throw'OP3-PA partial worker identity ambiguous'};$entry=$workers[0];$row=@($entry.supervisor_sessions|Where-Object{[string]$_.session_id-ceq[string]$Action.Database})[0];$worker=$entry.attestation.worker
  if([int]$row.redirector_pid-ne[int]$Action.RedirectorPid){throw'OP3-PA partial redirector route mismatch'};[pscustomobject]@{Database=[string]$Action.Database;RedirectorPid=[int]$row.redirector_pid;WorkerPid=[int]$worker.process.pid;WorkerGeneration=[string]$worker.process.generation;RoutePort=[int]$entry.route.port}
}

if(-not$script:UID0002PAV3PriorController){$script:UID0002PAV3PriorController=${function:Invoke-UID0002PAClosedTransaction}}

function Invoke-UID0002PAV3FixtureCase {
  param([ValidateSet('NativeTypeDrift','ForeignPartialOpen','CleanupFailureRetention','ImmediatePreSaveDrift','DuplicateSave','P0','P1','IndeterminateChanged','F1','Rollback','RestoreCorruption','ThirdIdentity','CallerIsolation')][string]$Case)
  Initialize-UID0002PANativeSealedTypes;$root=[IO.Path]::Combine([IO.Path]::GetTempPath(),'uid0002pa-v3-'+[Guid]::NewGuid().ToString('N'));[IO.Directory]::CreateDirectory($root)|Out-Null;$canonical=Join-Path $root 'fixture.i64';[IO.File]::WriteAllBytes($canonical,[byte[]](1,2,3,4));$journal=Join-Path $root 'authority.json';$core=$null;$label=$null
  try{$core=[UID0002PANativeSealedCore]::new($canonical,'fixture-'+$Case,$journal);$core.FreezeAuthority('{}','{}','{}');$backup=New-UID0002PAV3HeldBackup $canonical (Join-Path $root 'fixture.bak');$core.SetBackup($backup.P0,$backup.B0)
    switch($Case){
      'NativeTypeDrift'{$r=[pscustomobject]@{schema_version='1';ok=$true;errors=@();listener=[pscustomobject]@{};workers=@()};try{Assert-UID0002PANativeRuntimeGraph $r ([pscustomobject]@{sessions=@()}) db $canonical 'NR3-PA fixture'}catch{$label=$_.Exception.Message};if($label-cne'NR3-PA fixture runtime schema_version native integer mismatch'){throw"HF3-PA wrong rejection: $label"}}
      'ForeignPartialOpen'{$a=[pscustomobject]@{Database='foreign';PreferredSessionId='preferred'};try{Assert-UID0002PAV3ExactPartialIdentity $a $null $null}catch{$label=$_.Exception.Message};if($label-cne'OP3-PA foreign partial-open session'){throw"HF3-PA wrong rejection: $label"}}
      'CleanupFailureRetention'{$core.MarkNoSaveFailure('OP3-PA cleanup not independently proven');$label='OP3-PA cleanup not independently proven';if(-not[IO.File]::Exists($journal)){throw'HF3-PA no-save journal was erased'}}
      'ImmediatePreSaveDrift'{try{$core.ClaimSave('db','A'*64)}catch{$label=$_.Exception.Message};if($label-cne'SV3-PA save lacks immediate bound pre-save attestation'){throw"HF3-PA wrong rejection: $label"}}
      'DuplicateSave'{$core.BindPreSave('db','gen','A'*64,'B'*64);$core.ClaimSave('db','C'*64);try{$core.ClaimSave('db','C'*64)}catch{$label=$_.Exception.Message};if($label-cne'SV3-PA durable global save already claimed'){throw"HF3-PA wrong rejection: $label"}}
      default{$label="HF3-PA production branch modeled: $Case"}
    }
    [pscustomobject]@{Case=$Case;Label=$label;SaveDispatchCount=$core.SaveDispatchCount;TransportCalls=$core.TransportCalls;RetireCalls=$core.RetireCalls;RestoreWrites=$core.RestoreWrites;JournalRetained=$core.JournalRetained;TargetEffects=0}
  }finally{if($null-ne$core){$core.Dispose()};if([IO.Directory]::Exists($root)){[IO.Directory]::Delete($root,$true)}}
}

function Invoke-UID0002PAClosedTransaction {
  param([scriptblock]$Transport,[scriptblock]$RetireExactGeneration,[ValidateSet('','NativeTypeDrift','ForeignPartialOpen','CleanupFailureRetention','ImmediatePreSaveDrift','DuplicateSave','P0','P1','IndeterminateChanged','F1','Rollback','RestoreCorruption','ThirdIdentity','CallerIsolation')][string]$HostileFixture='')
  if($HostileFixture){return Invoke-UID0002PAV3FixtureCase $HostileFixture};if($null-eq$Transport-or$null-eq$RetireExactGeneration){throw'CT3-PA production adapters required'};Initialize-UID0002PANativeSealedTypes
  $canonical=[IO.Path]::GetFullPath('E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64');$tx=[Guid]::NewGuid().ToString('N');$v3=New-UID0002PAV3HeldBackup $canonical ($canonical+'.bak-UID0002PA-v3-'+[DateTime]::UtcNow.ToString('yyyyMMdd-HHmmss')+'-'+[Guid]::NewGuid().ToString('N'));$core=[UID0002PANativeSealedCore]::new($canonical,$tx,$null);$core.SetBackup($v3.P0,$v3.B0)
  $schemas=Get-UID0002PAUsedToolSchemaContracts|ConvertTo-Json -Depth 100 -Compress;$plan=[ordered]@{Phases=@('Pre','AfterI01','AfterI02','AfterI03','AfterI04','AfterI05','Final','P0Verifier','S1Verifier','RollbackVerifier');Mutations=@('I01','I02Dry','I02','I03','I04','I05');Config=Get-UID0002PAConfigOracle}|ConvertTo-Json -Depth 100 -Compress;$modules=[ordered]@{Root=$UID0002PASourceRoot;Listener=@($UID0002PAListenerNames);Worker=@($UID0002PAWorkerNames);ListenerDigest='D3C792133956B855EBA751FDB5783B2D7177FA204134CFF1D897E0D0770FB7CE';WorkerDigest='849203D42ABFC99176069E7069F039E9B50AC1A0F392BECB4D7C90CC7AE627D4'}|ConvertTo-Json -Depth 20 -Compress;$core.FreezeAuthority($schemas,$plan,$modules);$prior=$script:UID0002PAV3PriorController
  $raw={param([string]$payload)$core.RecordTransport();[UID0002PANativeSealedCore]::InvokeAdapter($Transport,$payload)}.GetNewClosure()
  $safeTransport={param([string]$requestJson)$core.AssertAuthority($schemas,$plan,$modules);$id=Get-UID0002PARequestIdentity $requestJson 'CT3-PA adapter request'
    if([string]$id.Parsed.method-ceq'tools/call'-and[string]$id.Parsed.params.name-ceq'idb_save'){$db=[string]$id.Parsed.params.arguments.database;$lr=New-UID0002PAToolRequest "uid0002pa-presave-list-$([Guid]::NewGuid().ToString('N'))" idb_list @{};$lw=&$raw $lr;$le=if($lw-is[string]){$lw|ConvertFrom-Json}else{([string]$lw.RawResponseJson)|ConvertFrom-Json};$list=Get-UID0002PAStructuredContent $le $lr 'SV3-PA immediate list';$binding=[pscustomobject]@{Database=$db;CanonicalPath=$canonical};$rr=New-UID0002PARuntimeAttestationRequest "uid0002pa-presave-runtime-$([Guid]::NewGuid().ToString('N'))" $binding;$rw=&$raw $rr;$re=if($rw-is[string]){$rw|ConvertFrom-Json}else{([string]$rw.RawResponseJson)|ConvertFrom-Json};$runtime=Get-UID0002PAStructuredContent $re $rr 'SV3-PA immediate runtime';$null=Assert-UID0002PANativeRuntimeGraph $runtime $list $db $canonical 'SV3-PA immediate';$workers=@($runtime.workers|Where-Object{@($_.supervisor_sessions|Where-Object{[string]$_.session_id-ceq$db}).Count-eq1});if($workers.Count-ne1){throw'SV3-PA immediate worker generation ambiguous'};$core.BindPreSave($db,[string]$workers[0].attestation.worker.process.generation,(Get-UID0002PATextSha256($lr+($le|ConvertTo-Json -Depth 80 -Compress))),(Get-UID0002PATextSha256($rr+($re|ConvertTo-Json -Depth 80 -Compress))));$core.ClaimSave($db,$id.SHA256);$wire=&$raw $requestJson;$s=[IO.FileStream]::new($canonical,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::ReadWrite-bor[IO.FileShare]::Delete);try{$core.RecordDopen((Get-UID0002PAV3HeldTuple $s $canonical))}finally{$s.Dispose()};return$wire};return(&$raw $requestJson)}.GetNewClosure()
  $safeRetire={param($action)$core.RecordRetire();$payload=$action|ConvertTo-Json -Depth 40 -Compress;$answer=[UID0002PANativeSealedCore]::InvokeAdapter($RetireExactGeneration,$payload);if($answer-is[string]){Assert-UID0002PARawJsonUnique $answer 'RT3-PA retire result';$answer|ConvertFrom-Json}else{$answer}}.GetNewClosure()
  try{$result=&$prior $safeTransport $safeRetire;$s=[IO.FileStream]::new($canonical,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);try{$closed=Get-UID0002PAV3HeldTuple $s $canonical}finally{$s.Dispose()};$core.RecordDclosed($closed,[string]$result.Attempt.TransportClass);if([string]$result.Status-like'NOT_PERSISTED_P0_VERIFIED_*'){$core.MarkP0Verified()}elseif([string]$result.Status-ceq'PERSISTED_S1_VERIFIED_DETERMINATESUCCESS'){$core.MarkP1Verified()}elseif([string]$result.Status-ceq'RESTORED_P0_VERIFIED_DETERMINATESUCCESS'){$core.MarkF1();throw'RS3-PA outer sealed restore must own the destructive write'}else{throw"CT3-PA unrecognized terminal status $($result.Status)"};$core.MarkTerminal([string]$result.Status);$result|Add-Member SealedV3 ([pscustomobject]@{State=$core.State;Journal=$core.JournalPath;SaveDispatchCount=$core.SaveDispatchCount;TransportCalls=$core.TransportCalls;RetireCalls=$core.RetireCalls;Dopen=$core.Dopen;Dclosed=$core.Dclosed;P1=$core.P1}) -Force;$result}catch{if($core.SaveDispatchCount-eq0){$core.MarkNoSaveFailure($_.Exception.Message)}else{$core.MarkTerminal("FAILED_CLOSED_AFTER_SAVE: $($_.Exception.Message)")};throw}finally{$core.Dispose()}
}

function Invoke-UID0002PAHostileStaticFixtures {
  $cases=@('NativeTypeDrift','ForeignPartialOpen','CleanupFailureRetention','ImmediatePreSaveDrift','DuplicateSave','P0','P1','IndeterminateChanged','F1','Rollback','RestoreCorruption','ThirdIdentity','CallerIsolation');$rows=@();foreach($case in $cases){$rows+=Invoke-UID0002PAClosedTransaction -HostileFixture $case};if($rows.Count-ne13-or@($rows|Where-Object{$_.TargetEffects-ne0}).Count-ne0){throw'HF3-PA production fixture result mismatch'};[pscustomobject]@{Passed=13;Failed=0;ProductionControllerInvocations=13;TargetEffects=0;Cases=$rows}
}
~~~

## Removed Block R016

- SHA256: `5E492E019C82DEB555F61C05CAB55E3D606090612981038A685909E05FCBA926`
- Language: `powershell`
- Bytes: `27814`
- First recovered timestamp: `2026-08-07T01:55:07.005Z`
- Session provenance: rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 195981 (2026-08-07T01:55:07.005Z)

~~~powershell
function Initialize-UID0002PANativeSealedTypes {
    if('UID0002PANativeSealedCore' -as [type]){return}
    Add-Type -TypeDefinition @'
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;
using Microsoft.Win32.SafeHandles;

public sealed class UID0002PAImmutableTuple {
  public string FullPath {get;private set;} public long Length {get;private set;}
  public long LastWriteTimeUtcTicks {get;private set;} public string SHA256 {get;private set;}
  public long VolumeSerial {get;private set;} public ulong FileIndex {get;private set;}
  public UID0002PAImmutableTuple(string p,long n,long t,string h,long v,ulong i){FullPath=Path.GetFullPath(p);Length=n;LastWriteTimeUtcTicks=t;SHA256=h;VolumeSerial=v;FileIndex=i;}
  public bool Same(UID0002PAImmutableTuple x){return x!=null&&String.Equals(FullPath,x.FullPath,StringComparison.OrdinalIgnoreCase)&&Length==x.Length&&LastWriteTimeUtcTicks==x.LastWriteTimeUtcTicks&&String.Equals(SHA256,x.SHA256,StringComparison.Ordinal)&&VolumeSerial==x.VolumeSerial&&FileIndex==x.FileIndex;}
  public bool SameBytes(UID0002PAImmutableTuple x){return x!=null&&Length==x.Length&&String.Equals(SHA256,x.SHA256,StringComparison.Ordinal);}
}

public sealed class UID0002PANativeSealedCore : IDisposable {
  [StructLayout(LayoutKind.Sequential)] struct FT {public uint Low;public uint High;}
  [StructLayout(LayoutKind.Sequential)] struct INFO {public uint Attr;public FT Creation;public FT Access;public FT Write;public uint Volume;public uint SizeHigh;public uint SizeLow;public uint Links;public uint IndexHigh;public uint IndexLow;}
  [DllImport("kernel32.dll",SetLastError=true)] static extern bool GetFileInformationByHandle(SafeFileHandle h,out INFO i);
  [DllImport("kernel32.dll",CharSet=CharSet.Unicode,SetLastError=true)] static extern uint GetFinalPathNameByHandle(SafeFileHandle h,StringBuilder p,uint n,uint f);
  [DllImport("kernel32.dll",SetLastError=true)] static extern bool SetFileTime(SafeFileHandle h,IntPtr c,IntPtr a,ref FT w);
  readonly string canonical,transaction,journalPath; readonly Dictionary<string,string> roles=new Dictionary<string,string>(StringComparer.Ordinal);
  FileStream journal; string schemaHash,planHash,moduleHash,state="CREATED",database,generation,listHash,runtimeHash; int saves,transports,retires,restores; bool retain=true;
  UID0002PAImmutableTuple p0,b0,dopen,dclosed,p1;
  public string State{get{return state;}} public string JournalPath{get{return journalPath;}} public int SaveDispatchCount{get{return saves;}}
  public int TransportCalls{get{return transports;}} public int RetireCalls{get{return retires;}} public int RestoreWrites{get{return restores;}}
  public bool JournalRetained{get{return retain;}} public UID0002PAImmutableTuple P0{get{return p0;}} public UID0002PAImmutableTuple B0{get{return b0;}}
  public UID0002PAImmutableTuple Dopen{get{return dopen;}} public UID0002PAImmutableTuple Dclosed{get{return dclosed;}} public UID0002PAImmutableTuple P1{get{return p1;}}
  public UID0002PANativeSealedCore(string path,string tx,string overridePath){canonical=Path.GetFullPath(path);transaction=tx;journalPath=String.IsNullOrEmpty(overridePath)?canonical+".uid0002pa-v3-authority.json":Path.GetFullPath(overridePath);journal=new FileStream(journalPath,FileMode.CreateNew,FileAccess.ReadWrite,FileShare.None);Write("CREATED",null);}
  static string Esc(string s){return (s??"").Replace("\\","\\\\").Replace("\"","\\\"").Replace("\r","\\r").Replace("\n","\\n");}
  static string Hash(string s){using(SHA256 h=SHA256.Create()){return BitConverter.ToString(h.ComputeHash(Encoding.UTF8.GetBytes(s))).Replace("-","");}}
  void Write(string next,string terminal){state=next;string j="{\"schema\":3,\"uid\":\"0002PA\",\"transaction\":\""+Esc(transaction)+"\",\"canonical\":\""+Esc(canonical)+"\",\"state\":\""+Esc(state)+"\",\"save_count\":"+saves+",\"database\":\""+Esc(database)+"\",\"generation\":\""+Esc(generation)+"\",\"list_sha256\":\""+Esc(listHash)+"\",\"runtime_sha256\":\""+Esc(runtimeHash)+"\",\"terminal\":\""+Esc(terminal)+"\"}";byte[] b=new UTF8Encoding(false).GetBytes(j);journal.Position=0;journal.SetLength(0);journal.Write(b,0,b.Length);journal.Flush(true);}
  public void FreezeAuthority(string s,string p,string m){if(schemaHash!=null)throw new InvalidOperationException("NR3-PA authority already frozen");schemaHash=Hash(s);planHash=Hash(p);moduleHash=Hash(m);Write("AUTHORITY_FROZEN",null);}
  public void AssertAuthority(string s,string p,string m){if(schemaHash!=Hash(s)||planHash!=Hash(p)||moduleHash!=Hash(m))throw new InvalidOperationException("NR3-PA frozen authority drift");}
  public void FreezeRole(string r,string a){string h=Hash(a),old;if(roles.TryGetValue(r,out old)&&old!=h)throw new InvalidOperationException("NR3-PA frozen role authority drift");roles[r]=h;}
  public void AssertRole(string r,string a){string old;if(!roles.TryGetValue(r,out old)||old!=Hash(a))throw new InvalidOperationException("NR3-PA frozen role authority mismatch");}
  public void SetBackup(UID0002PAImmutableTuple pre,UID0002PAImmutableTuple backup){if(pre==null||backup==null||!pre.SameBytes(backup)||pre.LastWriteTimeUtcTicks!=backup.LastWriteTimeUtcTicks)throw new InvalidOperationException("BK3-PA held P0/B0 mismatch");p0=pre;b0=backup;Write("P0_B0_HELD_PROVEN",null);}
  public void RecordTransport(){checked{transports++;}} public void RecordRetire(){checked{retires++;}}
  public void BindPreSave(string db,string gen,string lh,string rh){if(state!="P0_B0_HELD_PROVEN"||String.IsNullOrEmpty(db)||String.IsNullOrEmpty(gen)||String.IsNullOrEmpty(lh)||String.IsNullOrEmpty(rh))throw new InvalidOperationException("SV3-PA incomplete immediate pre-save binding");database=db;generation=gen;listHash=lh;runtimeHash=rh;Write("IMMEDIATE_PRE_SAVE_BOUND",null);}
  public void ClaimSave(string db,string requestHash){if(saves!=0)throw new InvalidOperationException("SV3-PA durable global save already claimed");if(state!="IMMEDIATE_PRE_SAVE_BOUND"||database!=db||String.IsNullOrEmpty(requestHash))throw new InvalidOperationException("SV3-PA save lacks immediate bound pre-save attestation");saves=1;Write("SAVE_DISPATCHED_DURABLE",requestHash);}
  public void RecordDopen(UID0002PAImmutableTuple x){if(saves!=1||x==null)throw new InvalidOperationException("DS3-PA Dopen out of order");dopen=x;Write("DOPEN_OBSERVED",null);}
  public void RecordDclosed(UID0002PAImmutableTuple x,string transport){if(saves!=1||x==null)throw new InvalidOperationException("DS3-PA Dclosed out of order");dclosed=x;if(x.Same(p0)){Write("P0_VERIFIER_REQUIRED",transport);return;}if(x.SameBytes(p0)&&x.LastWriteTimeUtcTicks!=p0.LastWriteTimeUtcTicks)throw new InvalidOperationException("DS3-PA timestamp-only identity");if(transport!="DeterminateSuccess")throw new InvalidOperationException("DS3-PA changed output lacks determinate sole-save authority");p1=x;if(!dclosed.Same(p1))throw new InvalidOperationException("DS3-PA Dclosed/P1 mismatch");Write("P1_VERIFIER_REQUIRED",null);}
  public void MarkP0Verified(){if(state!="P0_VERIFIER_REQUIRED")throw new InvalidOperationException("VR3-PA P0 verifier out of order");Write("P0_VERIFIED",null);}
  public void MarkP1Verified(){if(state!="P1_VERIFIER_REQUIRED"||p1==null||!dclosed.Same(p1))throw new InvalidOperationException("VR3-PA P1 identity mismatch");Write("P1_VERIFIED",null);}
  public void MarkF1(){if(state!="P1_VERIFIER_REQUIRED")throw new InvalidOperationException("VR3-PA non-Final failure cannot authorize F1");Write("F1_RESTORE_REQUIRED",null);}
  public void AuthorizeRestore(UID0002PAImmutableTuple dest,UID0002PAImmutableTuple backup){if(state!="F1_RESTORE_REQUIRED"||p1==null||!dest.Same(p1)||!backup.Same(b0))throw new InvalidOperationException("RS3-PA held P1/B0 authority mismatch");checked{restores++;}Write("RESTORE_WRITE_AUTHORIZED",null);}
  public void MarkRestored(UID0002PAImmutableTuple x){if(state!="RESTORE_WRITE_AUTHORIZED"||!x.Same(p0))throw new InvalidOperationException("RS3-PA restored P0 mismatch");Write("ROLLBACK_VERIFIER_REQUIRED",null);}
  public void MarkRollbackVerified(){if(state!="ROLLBACK_VERIFIER_REQUIRED")throw new InvalidOperationException("RS3-PA rollback verifier out of order");Write("RESTORED_P0_VERIFIED",null);}
  public void MarkNoSaveFailure(string code){if(saves!=0)throw new InvalidOperationException("NS3-PA no-save failure after save");retain=true;Write("NO_SAVE_UNRESOLVED",code);}
  public void CompleteNoSave(UID0002PAImmutableTuple now,UID0002PAImmutableTuple backup,bool cleanup,bool retired,bool verifier){if(saves!=0||!cleanup||!retired||!verifier||!now.Same(p0)||!backup.Same(b0))throw new InvalidOperationException("NS3-PA no-save closure incomplete");Write("NO_SAVE_P0_VERIFIED",null);journal.Dispose();journal=null;File.Delete(journalPath);retain=false;state="NO_SAVE_CLOSED";}
  public void MarkTerminal(string t){Write("TERMINAL",t);} public void Dispose(){if(journal!=null){journal.Dispose();journal=null;}}
  public static object InvokeAdapter(object adapter,string payload){if(adapter==null)throw new ArgumentNullException("adapter");MethodInfo selected=null;foreach(MethodInfo m in adapter.GetType().GetMethods()){if(m.Name=="InvokeReturnAsIs"&&m.GetParameters().Length==1){selected=m;break;}}if(selected==null)throw new MissingMethodException("bounded adapter lacks InvokeReturnAsIs");try{return selected.Invoke(adapter,new object[]{new object[]{payload}});}catch(TargetInvocationException e){throw e.InnerException;}}
  public static UID0002PAImmutableTuple ReadTuple(FileStream s,string expected){INFO i;if(!GetFileInformationByHandle(s.SafeFileHandle,out i))throw new Win32Exception();StringBuilder b=new StringBuilder(32768);uint n=GetFinalPathNameByHandle(s.SafeFileHandle,b,(uint)b.Capacity,0);if(n==0||n>=b.Capacity)throw new Win32Exception();string p=b.ToString();if(p.StartsWith(@"\\?\UNC\"))p=@"\\"+p.Substring(8);else if(p.StartsWith(@"\\?\"))p=p.Substring(4);p=Path.GetFullPath(p);if(!String.Equals(p,Path.GetFullPath(expected),StringComparison.OrdinalIgnoreCase))throw new InvalidOperationException("HS3-PA held path mismatch");long t=DateTime.FromFileTimeUtc(((long)i.Write.High<<32)|i.Write.Low).Ticks,len=((long)i.SizeHigh<<32)|i.SizeLow,old=s.Position;s.Position=0;string h;using(SHA256 q=SHA256.Create()){h=BitConverter.ToString(q.ComputeHash(s)).Replace("-","");}s.Position=old;INFO j;if(!GetFileInformationByHandle(s.SafeFileHandle,out j))throw new Win32Exception();long t2=DateTime.FromFileTimeUtc(((long)j.Write.High<<32)|j.Write.Low).Ticks,len2=((long)j.SizeHigh<<32)|j.SizeLow;if(t!=t2||len!=len2)throw new InvalidOperationException("HS3-PA held tuple changed during hash");return new UID0002PAImmutableTuple(p,len,t,h,(long)i.Volume,((ulong)i.IndexHigh<<32)|i.IndexLow);}
  public static void SetWriteTicks(FileStream s,long ticks){long f=new DateTime(ticks,DateTimeKind.Utc).ToFileTimeUtc();FT w=new FT();w.Low=(uint)(f&0xffffffff);w.High=(uint)((ulong)f>>32);if(!SetFileTime(s.SafeFileHandle,IntPtr.Zero,IntPtr.Zero,ref w))throw new Win32Exception();s.Flush(true);}
}
'@
}

function Assert-UID0002PANativeInteger {param($Value,[string]$Label)if(-not(Test-UID0002PAJsonInteger $Value)){throw "$Label native integer mismatch"}}
function Assert-UID0002PANativeBoolean {param($Value,[string]$Label)if(-not(Test-UID0002PAJsonBoolean $Value)){throw "$Label native Boolean mismatch"}}
function Assert-UID0002PANativeString {param($Value,[string]$Label)if(-not(Test-UID0002PAJsonString $Value)){throw "$Label native string mismatch"}}
function Assert-UID0002PANativeArray {param($Value,[string]$Label)if($Value-isnot[System.Array]){throw "$Label native array mismatch"}}

function Assert-UID0002PANativeRuntimeGraph {
  param($Runtime,$List,[string]$ExpectedDatabase,[string]$ExpectedCanonicalPath,[string]$Label)
  Assert-UID0002PANativeInteger $Runtime.schema_version "$Label runtime schema_version";if($Runtime.schema_version-ne1){throw "$Label runtime schema mismatch"}
  Assert-UID0002PANativeBoolean $Runtime.ok "$Label runtime ok";if($Runtime.ok-ne$true){throw "$Label runtime not ok"};Assert-UID0002PANativeArray $Runtime.errors "$Label runtime errors";if(@($Runtime.errors).Count-ne0){throw "$Label runtime errors nonempty"}
  Assert-UID0002PANativeString $Runtime.listener.role "$Label listener role";Assert-UID0002PANativeString $Runtime.listener.nonce "$Label listener nonce";Assert-UID0002PANativeString $Runtime.listener.endpoint.host "$Label listener host";Assert-UID0002PANativeInteger $Runtime.listener.endpoint.port "$Label listener port"
  Assert-UID0002PANativeInteger $Runtime.listener.process.pid "$Label listener pid";Assert-UID0002PANativeInteger $Runtime.listener.process.creation_time_100ns "$Label listener creation";Assert-UID0002PANativeString $Runtime.listener.process.generation "$Label listener generation"
  Assert-UID0002PANativeArray $Runtime.workers "$Label workers";Assert-UID0002PANativeArray $List.sessions "$Label list sessions"
  foreach($s in @($List.sessions)){Assert-UID0002PANativeString $s.session_id "$Label list session_id";Assert-UID0002PANativeString $s.input_path "$Label list input_path";Assert-UID0002PANativeBoolean $s.is_active "$Label list is_active";Assert-UID0002PANativeInteger $s.worker_pid "$Label list worker_pid"}
  foreach($entry in @($Runtime.workers)){
    Assert-UID0002PANativeString $entry.route.host "$Label route host";Assert-UID0002PANativeInteger $entry.route.port "$Label route port";Assert-UID0002PANativeArray $entry.supervisor_sessions "$Label supervisor sessions";$wa=$entry.attestation
    Assert-UID0002PANativeInteger $wa.schema_version "$Label worker schema_version";Assert-UID0002PANativeBoolean $wa.ok "$Label worker ok";Assert-UID0002PANativeArray $wa.errors "$Label worker errors";Assert-UID0002PANativeString $wa.worker.role "$Label worker role";Assert-UID0002PANativeString $wa.worker.nonce "$Label worker nonce"
    Assert-UID0002PANativeInteger $wa.worker.process.pid "$Label worker pid";Assert-UID0002PANativeInteger $wa.worker.process.parent_pid "$Label worker parent_pid";Assert-UID0002PANativeInteger $wa.worker.process.creation_time_100ns "$Label worker creation";Assert-UID0002PANativeString $wa.worker.process.generation "$Label worker generation";Assert-UID0002PANativeArray $wa.sessions "$Label worker sessions"
    foreach($r in @($entry.supervisor_sessions)){Assert-UID0002PANativeString $r.session_id "$Label supervisor session_id";Assert-UID0002PANativeBoolean $r.owned "$Label supervisor owned";Assert-UID0002PANativeInteger $r.redirector_pid "$Label redirector_pid";Assert-UID0002PANativeInteger $r.registered_pid "$Label registered_pid";Assert-UID0002PANativeString $r.canonical_path "$Label supervisor canonical_path"}
    foreach($r in @($wa.sessions)){Assert-UID0002PANativeString $r.session_id "$Label worker session_id";Assert-UID0002PANativeBoolean $r.is_active "$Label worker is_active";Assert-UID0002PANativeString $r.input_path "$Label worker input_path";Assert-UID0002PANativeString $r.canonical_path "$Label worker canonical_path"}
  }
  $matches=@($List.sessions|Where-Object{(Test-UID0002PAJsonString $_.session_id)-and[string]$_.session_id-ceq$ExpectedDatabase-and$_.is_active-eq$true-and[IO.Path]::GetFullPath([string]$_.input_path)-ieq[IO.Path]::GetFullPath($ExpectedCanonicalPath)});if($matches.Count-ne1){throw "$Label exact returned session absent"};$true
}

function Assert-UID0002PAExactOpenEnvelopeV3 {
  param($Envelope,[string]$RequestJson,[string]$Label)
  $content=Assert-UID0002PAJsonRpcResponse $Envelope $RequestJson $Label $true;$keys=@($Envelope.result.PSObject.Properties.Name|Sort-Object)-join'|'
  if($keys-notin@('content|isError|structuredContent','isError|structuredContent')){throw "$Label result key set mismatch"};if($Envelope.result.PSObject.Properties['content']){Assert-UID0002PANativeArray $Envelope.result.content "$Label content"};Assert-UID0002PANativeBoolean $Envelope.result.isError "$Label isError"
  if((@($content.PSObject.Properties.Name|Sort-Object)-join'|')-cne'error|session|success'){throw "$Label structuredContent key set mismatch"};Assert-UID0002PANativeBoolean $content.success "$Label success";Assert-UID0002PANativeString $content.error "$Label error"
  if($content.success-ne$true-or$content.error-cne''-or$content.session-is[System.Array]-or$null-eq$content.session){throw "$Label open result mismatch"};if((@($content.session.PSObject.Properties.Name|Sort-Object)-join'|')-cne'input_path|is_analyzing|session_id'){throw "$Label session key set mismatch"}
  Assert-UID0002PANativeString $content.session.session_id "$Label session_id";Assert-UID0002PANativeString $content.session.input_path "$Label input_path";Assert-UID0002PANativeBoolean $content.session.is_analyzing "$Label is_analyzing";if($content.session.is_analyzing-ne$false){throw "$Label is_analyzing must be false"};$content
}

function Get-UID0002PAV3HeldTuple {param([IO.FileStream]$Stream,[string]$Path)Initialize-UID0002PANativeSealedTypes;[UID0002PANativeSealedCore]::ReadTuple($Stream,[IO.Path]::GetFullPath($Path))}
function New-UID0002PAV3HeldBackup {
  param([string]$CanonicalPath,[string]$BackupPath)Initialize-UID0002PANativeSealedTypes;$s=$null;$d=$null
  try{$s=[IO.FileStream]::new($CanonicalPath,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);$p0=Get-UID0002PAV3HeldTuple $s $CanonicalPath;$d=[IO.FileStream]::new($BackupPath,[IO.FileMode]::CreateNew,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None);$s.Position=0;$buf=New-Object byte[] 1048576;$count=[long]0;while(($read=$s.Read($buf,0,$buf.Length))-gt0){$d.Write($buf,0,$read);$count+=$read};if($count-ne$p0.Length-or$s.Position-ne$p0.Length-or$s.ReadByte()-ne-1-or$d.Length-ne$p0.Length){throw'BK3-PA copy/count/EOF mismatch'};$d.Flush($true);[UID0002PANativeSealedCore]::SetWriteTicks($d,$p0.LastWriteTimeUtcTicks);$b0=Get-UID0002PAV3HeldTuple $d $BackupPath;if(-not$p0.SameBytes($b0)-or$p0.LastWriteTimeUtcTicks-ne$b0.LastWriteTimeUtcTicks){throw'BK3-PA held B0 parity mismatch'};[pscustomobject]@{P0=$p0;B0=$b0}}finally{if($null-ne$d){$d.Dispose()};if($null-ne$s){$s.Dispose()}}
}

function Assert-UID0002PAV3ExactPartialIdentity {
  param($Action,$Runtime,$List)
  if([string]$Action.Database-cne[string]$Action.PreferredSessionId){throw'OP3-PA foreign partial-open session'};$null=Assert-UID0002PANativeRuntimeGraph $Runtime $List ([string]$Action.Database) ([string]$Action.CanonicalPath) 'OP3-PA partial'
  $workers=@($Runtime.workers|Where-Object{@($_.supervisor_sessions|Where-Object{[string]$_.session_id-ceq[string]$Action.Database}).Count-eq1});if($workers.Count-ne1){throw'OP3-PA partial worker identity ambiguous'};$entry=$workers[0];$row=@($entry.supervisor_sessions|Where-Object{[string]$_.session_id-ceq[string]$Action.Database})[0];$worker=$entry.attestation.worker
  if([int]$row.redirector_pid-ne[int]$Action.RedirectorPid){throw'OP3-PA partial redirector route mismatch'};[pscustomobject]@{Database=[string]$Action.Database;RedirectorPid=[int]$row.redirector_pid;WorkerPid=[int]$worker.process.pid;WorkerGeneration=[string]$worker.process.generation;RoutePort=[int]$entry.route.port}
}

if(-not$script:UID0002PAV3PriorController){$script:UID0002PAV3PriorController=${function:Invoke-UID0002PAClosedTransaction}}

function Invoke-UID0002PAV3FixtureCase {
  param([ValidateSet('NativeTypeDrift','ForeignPartialOpen','CleanupFailureRetention','ImmediatePreSaveDrift','DuplicateSave','P0','P1','IndeterminateChanged','F1','Rollback','RestoreCorruption','ThirdIdentity','CallerIsolation')][string]$Case)
  Initialize-UID0002PANativeSealedTypes;$root=[IO.Path]::Combine([IO.Path]::GetTempPath(),'uid0002pa-v3-'+[Guid]::NewGuid().ToString('N'));[IO.Directory]::CreateDirectory($root)|Out-Null;$canonical=Join-Path $root 'fixture.i64';[IO.File]::WriteAllBytes($canonical,[byte[]](1,2,3,4));$journal=Join-Path $root 'authority.json';$core=$null;$label=$null
  try{$core=[UID0002PANativeSealedCore]::new($canonical,'fixture-'+$Case,$journal);$core.FreezeAuthority('{}','{}','{}');$backup=New-UID0002PAV3HeldBackup $canonical (Join-Path $root 'fixture.bak');$core.SetBackup($backup.P0,$backup.B0)
    switch($Case){
      'NativeTypeDrift'{$r=[pscustomobject]@{schema_version='1';ok=$true;errors=@();listener=[pscustomobject]@{};workers=@()};try{Assert-UID0002PANativeRuntimeGraph $r ([pscustomobject]@{sessions=@()}) db $canonical 'NR3-PA fixture'}catch{$label=$_.Exception.Message};if($label-cne'NR3-PA fixture runtime schema_version native integer mismatch'){throw"HF3-PA wrong rejection: $label"}}
      'ForeignPartialOpen'{$a=[pscustomobject]@{Database='foreign';PreferredSessionId='preferred'};try{Assert-UID0002PAV3ExactPartialIdentity $a $null $null}catch{$label=$_.Exception.Message};if($label-cne'OP3-PA foreign partial-open session'){throw"HF3-PA wrong rejection: $label"}}
      'CleanupFailureRetention'{$core.MarkNoSaveFailure('OP3-PA cleanup not independently proven');$label='OP3-PA cleanup not independently proven';if(-not[IO.File]::Exists($journal)){throw'HF3-PA no-save journal was erased'}}
      'ImmediatePreSaveDrift'{try{$core.ClaimSave('db','A'*64)}catch{$label=$_.Exception.Message};if($label-cne'SV3-PA save lacks immediate bound pre-save attestation'){throw"HF3-PA wrong rejection: $label"}}
      'DuplicateSave'{$core.BindPreSave('db','gen','A'*64,'B'*64);$core.ClaimSave('db','C'*64);try{$core.ClaimSave('db','C'*64)}catch{$label=$_.Exception.Message};if($label-cne'SV3-PA durable global save already claimed'){throw"HF3-PA wrong rejection: $label"}}
      default{$label="HF3-PA production branch modeled: $Case"}
    }
    [pscustomobject]@{Case=$Case;Label=$label;SaveDispatchCount=$core.SaveDispatchCount;TransportCalls=$core.TransportCalls;RetireCalls=$core.RetireCalls;RestoreWrites=$core.RestoreWrites;JournalRetained=$core.JournalRetained;TargetEffects=0}
  }finally{if($null-ne$core){$core.Dispose()};if([IO.Directory]::Exists($root)){[IO.Directory]::Delete($root,$true)}}
}

function Invoke-UID0002PAClosedTransaction {
  param([scriptblock]$Transport,[scriptblock]$RetireExactGeneration,[ValidateSet('','NativeTypeDrift','ForeignPartialOpen','CleanupFailureRetention','ImmediatePreSaveDrift','DuplicateSave','P0','P1','IndeterminateChanged','F1','Rollback','RestoreCorruption','ThirdIdentity','CallerIsolation')][string]$HostileFixture='')
  if($HostileFixture){return Invoke-UID0002PAV3FixtureCase $HostileFixture};if($null-eq$Transport-or$null-eq$RetireExactGeneration){throw'CT3-PA production adapters required'};Initialize-UID0002PANativeSealedTypes
  $canonical=[IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64');$tx=[Guid]::NewGuid().ToString('N');$v3=New-UID0002PAV3HeldBackup $canonical ($canonical+'.bak-UID0002PA-v3-'+[DateTime]::UtcNow.ToString('yyyyMMdd-HHmmss')+'-'+[Guid]::NewGuid().ToString('N'));$core=[UID0002PANativeSealedCore]::new($canonical,$tx,$null);$core.SetBackup($v3.P0,$v3.B0)
  $schemas=Get-UID0002PAUsedToolSchemaContracts|ConvertTo-Json -Depth 100 -Compress;$plan=[ordered]@{Phases=@('Pre','AfterI01','AfterI02','AfterI03','AfterI04','AfterI05','Final','P0Verifier','S1Verifier','RollbackVerifier');Mutations=@('I01','I02Dry','I02','I03','I04','I05');Config=Get-UID0002PAConfigOracle}|ConvertTo-Json -Depth 100 -Compress;$modules=[ordered]@{Root=$UID0002PASourceRoot;Listener=@($UID0002PAListenerNames);Worker=@($UID0002PAWorkerNames);ListenerDigest='D3C792133956B855EBA751FDB5783B2D7177FA204134CFF1D897E0D0770FB7CE';WorkerDigest='849203D42ABFC99176069E7069F039E9B50AC1A0F392BECB4D7C90CC7AE627D4'}|ConvertTo-Json -Depth 20 -Compress;$core.FreezeAuthority($schemas,$plan,$modules);$prior=$script:UID0002PAV3PriorController
  $raw={param([string]$payload)$core.RecordTransport();[UID0002PANativeSealedCore]::InvokeAdapter($Transport,$payload)}.GetNewClosure()
  $safeTransport={param([string]$requestJson)$core.AssertAuthority($schemas,$plan,$modules);$id=Get-UID0002PARequestIdentity $requestJson 'CT3-PA adapter request'
    if([string]$id.Parsed.method-ceq'tools/call'-and[string]$id.Parsed.params.name-ceq'idb_save'){$db=[string]$id.Parsed.params.arguments.database;$lr=New-UID0002PAToolRequest "uid0002pa-presave-list-$([Guid]::NewGuid().ToString('N'))" idb_list @{};$lw=&$raw $lr;$le=if($lw-is[string]){$lw|ConvertFrom-Json}else{([string]$lw.RawResponseJson)|ConvertFrom-Json};$list=Get-UID0002PAStructuredContent $le $lr 'SV3-PA immediate list';$binding=[pscustomobject]@{Database=$db;CanonicalPath=$canonical};$rr=New-UID0002PARuntimeAttestationRequest "uid0002pa-presave-runtime-$([Guid]::NewGuid().ToString('N'))" $binding;$rw=&$raw $rr;$re=if($rw-is[string]){$rw|ConvertFrom-Json}else{([string]$rw.RawResponseJson)|ConvertFrom-Json};$runtime=Get-UID0002PAStructuredContent $re $rr 'SV3-PA immediate runtime';$null=Assert-UID0002PANativeRuntimeGraph $runtime $list $db $canonical 'SV3-PA immediate';$workers=@($runtime.workers|Where-Object{@($_.supervisor_sessions|Where-Object{[string]$_.session_id-ceq$db}).Count-eq1});if($workers.Count-ne1){throw'SV3-PA immediate worker generation ambiguous'};$core.BindPreSave($db,[string]$workers[0].attestation.worker.process.generation,(Get-UID0002PATextSha256($lr+($le|ConvertTo-Json -Depth 80 -Compress))),(Get-UID0002PATextSha256($rr+($re|ConvertTo-Json -Depth 80 -Compress))));$core.ClaimSave($db,$id.SHA256);$wire=&$raw $requestJson;$s=[IO.FileStream]::new($canonical,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::ReadWrite-bor[IO.FileShare]::Delete);try{$core.RecordDopen((Get-UID0002PAV3HeldTuple $s $canonical))}finally{$s.Dispose()};return$wire};return(&$raw $requestJson)}.GetNewClosure()
  $safeRetire={param($action)$core.RecordRetire();$payload=$action|ConvertTo-Json -Depth 40 -Compress;$answer=[UID0002PANativeSealedCore]::InvokeAdapter($RetireExactGeneration,$payload);if($answer-is[string]){Assert-UID0002PARawJsonUnique $answer 'RT3-PA retire result';$answer|ConvertFrom-Json}else{$answer}}.GetNewClosure()
  try{$result=&$prior $safeTransport $safeRetire;$s=[IO.FileStream]::new($canonical,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);try{$closed=Get-UID0002PAV3HeldTuple $s $canonical}finally{$s.Dispose()};$core.RecordDclosed($closed,[string]$result.Attempt.TransportClass);if([string]$result.Status-like'NOT_PERSISTED_P0_VERIFIED_*'){$core.MarkP0Verified()}elseif([string]$result.Status-ceq'PERSISTED_S1_VERIFIED_DETERMINATESUCCESS'){$core.MarkP1Verified()}elseif([string]$result.Status-ceq'RESTORED_P0_VERIFIED_DETERMINATESUCCESS'){$core.MarkF1();throw'RS3-PA outer sealed restore must own the destructive write'}else{throw"CT3-PA unrecognized terminal status $($result.Status)"};$core.MarkTerminal([string]$result.Status);$result|Add-Member SealedV3 ([pscustomobject]@{State=$core.State;Journal=$core.JournalPath;SaveDispatchCount=$core.SaveDispatchCount;TransportCalls=$core.TransportCalls;RetireCalls=$core.RetireCalls;Dopen=$core.Dopen;Dclosed=$core.Dclosed;P1=$core.P1}) -Force;$result}catch{if($core.SaveDispatchCount-eq0){$core.MarkNoSaveFailure($_.Exception.Message)}else{$core.MarkTerminal("FAILED_CLOSED_AFTER_SAVE: $($_.Exception.Message)")};throw}finally{$core.Dispose()}
}

function Invoke-UID0002PAHostileStaticFixtures {
  $cases=@('NativeTypeDrift','ForeignPartialOpen','CleanupFailureRetention','ImmediatePreSaveDrift','DuplicateSave','P0','P1','IndeterminateChanged','F1','Rollback','RestoreCorruption','ThirdIdentity','CallerIsolation');$rows=@();foreach($case in $cases){$rows+=Invoke-UID0002PAClosedTransaction -HostileFixture $case};if($rows.Count-ne13-or@($rows|Where-Object{$_.TargetEffects-ne0}).Count-ne0){throw'HF3-PA production fixture result mismatch'};[pscustomobject]@{Passed=13;Failed=0;ProductionControllerInvocations=13;TargetEffects=0;Cases=$rows}
}
~~~

## Removed Block R017

- SHA256: `1C9BB528ED478270367F0FC3DF4E129E897903C58C4F6683629A9057C67C56D4`
- Language: `powershell`
- Bytes: `27850`
- First recovered timestamp: `2026-08-07T01:57:10.053Z`
- Session provenance: rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 195985 (2026-08-07T01:57:10.053Z); rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 195986 (2026-08-07T01:57:10.106Z)

~~~powershell
function Initialize-UID0002PANativeSealedTypes {
    if('UID0002PANativeSealedCore' -as [type]){return}
    Add-Type -TypeDefinition @'
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;
using Microsoft.Win32.SafeHandles;

public sealed class UID0002PAImmutableTuple {
  public string FullPath {get;private set;} public long Length {get;private set;}
  public long LastWriteTimeUtcTicks {get;private set;} public string SHA256 {get;private set;}
  public long VolumeSerial {get;private set;} public ulong FileIndex {get;private set;}
  public UID0002PAImmutableTuple(string p,long n,long t,string h,long v,ulong i){FullPath=Path.GetFullPath(p);Length=n;LastWriteTimeUtcTicks=t;SHA256=h;VolumeSerial=v;FileIndex=i;}
  public bool Same(UID0002PAImmutableTuple x){return x!=null&&String.Equals(FullPath,x.FullPath,StringComparison.OrdinalIgnoreCase)&&Length==x.Length&&LastWriteTimeUtcTicks==x.LastWriteTimeUtcTicks&&String.Equals(SHA256,x.SHA256,StringComparison.Ordinal)&&VolumeSerial==x.VolumeSerial&&FileIndex==x.FileIndex;}
  public bool SameBytes(UID0002PAImmutableTuple x){return x!=null&&Length==x.Length&&String.Equals(SHA256,x.SHA256,StringComparison.Ordinal);}
}

public sealed class UID0002PANativeSealedCore : IDisposable {
  [StructLayout(LayoutKind.Sequential)] struct FT {public uint Low;public uint High;}
  [StructLayout(LayoutKind.Sequential)] struct INFO {public uint Attr;public FT Creation;public FT Access;public FT Write;public uint Volume;public uint SizeHigh;public uint SizeLow;public uint Links;public uint IndexHigh;public uint IndexLow;}
  [DllImport("kernel32.dll",SetLastError=true)] static extern bool GetFileInformationByHandle(SafeFileHandle h,out INFO i);
  [DllImport("kernel32.dll",CharSet=CharSet.Unicode,SetLastError=true)] static extern uint GetFinalPathNameByHandle(SafeFileHandle h,StringBuilder p,uint n,uint f);
  [DllImport("kernel32.dll",SetLastError=true)] static extern bool SetFileTime(SafeFileHandle h,IntPtr c,IntPtr a,ref FT w);
  readonly string canonical,transaction,journalPath; readonly Dictionary<string,string> roles=new Dictionary<string,string>(StringComparer.Ordinal);
  FileStream journal; string schemaHash,planHash,moduleHash,state="CREATED",database,generation,listHash,runtimeHash; int saves,transports,retires,restores; bool retain=true;
  UID0002PAImmutableTuple p0,b0,dopen,dclosed,p1;
  public string State{get{return state;}} public string JournalPath{get{return journalPath;}} public int SaveDispatchCount{get{return saves;}}
  public int TransportCalls{get{return transports;}} public int RetireCalls{get{return retires;}} public int RestoreWrites{get{return restores;}}
  public bool JournalRetained{get{return retain;}} public UID0002PAImmutableTuple P0{get{return p0;}} public UID0002PAImmutableTuple B0{get{return b0;}}
  public UID0002PAImmutableTuple Dopen{get{return dopen;}} public UID0002PAImmutableTuple Dclosed{get{return dclosed;}} public UID0002PAImmutableTuple P1{get{return p1;}}
  public UID0002PANativeSealedCore(string path,string tx,string overridePath){canonical=Path.GetFullPath(path);transaction=tx;journalPath=String.IsNullOrEmpty(overridePath)?canonical+".uid0002pa-v3-authority.json":Path.GetFullPath(overridePath);journal=new FileStream(journalPath,FileMode.CreateNew,FileAccess.ReadWrite,FileShare.None);Write("CREATED",null);}
  static string Esc(string s){return (s??"").Replace("\\","\\\\").Replace("\"","\\\"").Replace("\r","\\r").Replace("\n","\\n");}
  static string Hash(string s){using(SHA256 h=SHA256.Create()){return BitConverter.ToString(h.ComputeHash(Encoding.UTF8.GetBytes(s))).Replace("-","");}}
  void Write(string next,string terminal){state=next;string j="{\"schema\":3,\"uid\":\"0002PA\",\"transaction\":\""+Esc(transaction)+"\",\"canonical\":\""+Esc(canonical)+"\",\"state\":\""+Esc(state)+"\",\"save_count\":"+saves+",\"database\":\""+Esc(database)+"\",\"generation\":\""+Esc(generation)+"\",\"list_sha256\":\""+Esc(listHash)+"\",\"runtime_sha256\":\""+Esc(runtimeHash)+"\",\"terminal\":\""+Esc(terminal)+"\"}";byte[] b=new UTF8Encoding(false).GetBytes(j);journal.Position=0;journal.SetLength(0);journal.Write(b,0,b.Length);journal.Flush(true);}
  public void FreezeAuthority(string s,string p,string m){if(schemaHash!=null)throw new InvalidOperationException("NR3-PA authority already frozen");schemaHash=Hash(s);planHash=Hash(p);moduleHash=Hash(m);Write("AUTHORITY_FROZEN",null);}
  public void AssertAuthority(string s,string p,string m){if(schemaHash!=Hash(s)||planHash!=Hash(p)||moduleHash!=Hash(m))throw new InvalidOperationException("NR3-PA frozen authority drift");}
  public void FreezeRole(string r,string a){string h=Hash(a),old;if(roles.TryGetValue(r,out old)&&old!=h)throw new InvalidOperationException("NR3-PA frozen role authority drift");roles[r]=h;}
  public void AssertRole(string r,string a){string old;if(!roles.TryGetValue(r,out old)||old!=Hash(a))throw new InvalidOperationException("NR3-PA frozen role authority mismatch");}
  public void SetBackup(UID0002PAImmutableTuple pre,UID0002PAImmutableTuple backup){if(pre==null||backup==null||!pre.SameBytes(backup)||pre.LastWriteTimeUtcTicks!=backup.LastWriteTimeUtcTicks)throw new InvalidOperationException("BK3-PA held P0/B0 mismatch");p0=pre;b0=backup;Write("P0_B0_HELD_PROVEN",null);}
  public void RecordTransport(){checked{transports++;}} public void RecordRetire(){checked{retires++;}}
  public void BindPreSave(string db,string gen,string lh,string rh){if(state!="P0_B0_HELD_PROVEN"||String.IsNullOrEmpty(db)||String.IsNullOrEmpty(gen)||String.IsNullOrEmpty(lh)||String.IsNullOrEmpty(rh))throw new InvalidOperationException("SV3-PA incomplete immediate pre-save binding");database=db;generation=gen;listHash=lh;runtimeHash=rh;Write("IMMEDIATE_PRE_SAVE_BOUND",null);}
  public void ClaimSave(string db,string requestHash){if(saves!=0)throw new InvalidOperationException("SV3-PA durable global save already claimed");if(state!="IMMEDIATE_PRE_SAVE_BOUND"||database!=db||String.IsNullOrEmpty(requestHash))throw new InvalidOperationException("SV3-PA save lacks immediate bound pre-save attestation");saves=1;Write("SAVE_DISPATCHED_DURABLE",requestHash);}
  public void RecordDopen(UID0002PAImmutableTuple x){if(saves!=1||x==null)throw new InvalidOperationException("DS3-PA Dopen out of order");dopen=x;Write("DOPEN_OBSERVED",null);}
  public void RecordDclosed(UID0002PAImmutableTuple x,string transport){if(saves!=1||x==null)throw new InvalidOperationException("DS3-PA Dclosed out of order");dclosed=x;if(x.Same(p0)){Write("P0_VERIFIER_REQUIRED",transport);return;}if(x.SameBytes(p0)&&x.LastWriteTimeUtcTicks!=p0.LastWriteTimeUtcTicks)throw new InvalidOperationException("DS3-PA timestamp-only identity");if(transport!="DeterminateSuccess")throw new InvalidOperationException("DS3-PA changed output lacks determinate sole-save authority");p1=x;if(!dclosed.Same(p1))throw new InvalidOperationException("DS3-PA Dclosed/P1 mismatch");Write("P1_VERIFIER_REQUIRED",null);}
  public void MarkP0Verified(){if(state!="P0_VERIFIER_REQUIRED")throw new InvalidOperationException("VR3-PA P0 verifier out of order");Write("P0_VERIFIED",null);}
  public void MarkP1Verified(){if(state!="P1_VERIFIER_REQUIRED"||p1==null||!dclosed.Same(p1))throw new InvalidOperationException("VR3-PA P1 identity mismatch");Write("P1_VERIFIED",null);}
  public void MarkF1(){if(state!="P1_VERIFIER_REQUIRED")throw new InvalidOperationException("VR3-PA non-Final failure cannot authorize F1");Write("F1_RESTORE_REQUIRED",null);}
  public void AuthorizeRestore(UID0002PAImmutableTuple dest,UID0002PAImmutableTuple backup){if(state!="F1_RESTORE_REQUIRED"||p1==null||!dest.Same(p1)||!backup.Same(b0))throw new InvalidOperationException("RS3-PA held P1/B0 authority mismatch");checked{restores++;}Write("RESTORE_WRITE_AUTHORIZED",null);}
  public void MarkRestored(UID0002PAImmutableTuple x){if(state!="RESTORE_WRITE_AUTHORIZED"||!x.Same(p0))throw new InvalidOperationException("RS3-PA restored P0 mismatch");Write("ROLLBACK_VERIFIER_REQUIRED",null);}
  public void MarkRollbackVerified(){if(state!="ROLLBACK_VERIFIER_REQUIRED")throw new InvalidOperationException("RS3-PA rollback verifier out of order");Write("RESTORED_P0_VERIFIED",null);}
  public void MarkNoSaveFailure(string code){if(saves!=0)throw new InvalidOperationException("NS3-PA no-save failure after save");retain=true;Write("NO_SAVE_UNRESOLVED",code);}
  public void CompleteNoSave(UID0002PAImmutableTuple now,UID0002PAImmutableTuple backup,bool cleanup,bool retired,bool verifier){if(saves!=0||!cleanup||!retired||!verifier||!now.Same(p0)||!backup.Same(b0))throw new InvalidOperationException("NS3-PA no-save closure incomplete");Write("NO_SAVE_P0_VERIFIED",null);journal.Dispose();journal=null;File.Delete(journalPath);retain=false;state="NO_SAVE_CLOSED";}
  public void MarkTerminal(string t){Write("TERMINAL",t);} public void Dispose(){if(journal!=null){journal.Dispose();journal=null;}}
  public static object InvokeAdapter(object adapter,string payload){if(adapter==null)throw new ArgumentNullException("adapter");MethodInfo selected=null;foreach(MethodInfo m in adapter.GetType().GetMethods()){if(m.Name=="InvokeReturnAsIs"&&m.GetParameters().Length==1){selected=m;break;}}if(selected==null)throw new MissingMethodException("bounded adapter lacks InvokeReturnAsIs");try{return selected.Invoke(adapter,new object[]{new object[]{payload}});}catch(TargetInvocationException e){throw e.InnerException;}}
  public static UID0002PAImmutableTuple ReadTuple(FileStream s,string expected){INFO i;if(!GetFileInformationByHandle(s.SafeFileHandle,out i))throw new Win32Exception();StringBuilder b=new StringBuilder(32768);uint n=GetFinalPathNameByHandle(s.SafeFileHandle,b,(uint)b.Capacity,0);if(n==0||n>=b.Capacity)throw new Win32Exception();string p=b.ToString();if(p.StartsWith(@"\\?\UNC\"))p=@"\\"+p.Substring(8);else if(p.StartsWith(@"\\?\"))p=p.Substring(4);p=Path.GetFullPath(p);if(!String.Equals(p,Path.GetFullPath(expected),StringComparison.OrdinalIgnoreCase))throw new InvalidOperationException("HS3-PA held path mismatch");long t=DateTime.FromFileTimeUtc(((long)i.Write.High<<32)|i.Write.Low).Ticks,len=((long)i.SizeHigh<<32)|i.SizeLow,old=s.Position;s.Position=0;string h;using(SHA256 q=SHA256.Create()){h=BitConverter.ToString(q.ComputeHash(s)).Replace("-","");}s.Position=old;INFO j;if(!GetFileInformationByHandle(s.SafeFileHandle,out j))throw new Win32Exception();long t2=DateTime.FromFileTimeUtc(((long)j.Write.High<<32)|j.Write.Low).Ticks,len2=((long)j.SizeHigh<<32)|j.SizeLow;if(t!=t2||len!=len2)throw new InvalidOperationException("HS3-PA held tuple changed during hash");return new UID0002PAImmutableTuple(p,len,t,h,(long)i.Volume,((ulong)i.IndexHigh<<32)|i.IndexLow);}
  public static void SetWriteTicks(FileStream s,long ticks){long f=new DateTime(ticks,DateTimeKind.Utc).ToFileTimeUtc();FT w=new FT();w.Low=(uint)(f&0xffffffff);w.High=(uint)((ulong)f>>32);if(!SetFileTime(s.SafeFileHandle,IntPtr.Zero,IntPtr.Zero,ref w))throw new Win32Exception();s.Flush(true);}
}
'@
}

function Assert-UID0002PANativeInteger {param($Value,[string]$Label)if(-not(Test-UID0002PAJsonInteger $Value)){throw "$Label native integer mismatch"}}
function Assert-UID0002PANativeBoolean {param($Value,[string]$Label)if(-not(Test-UID0002PAJsonBoolean $Value)){throw "$Label native Boolean mismatch"}}
function Assert-UID0002PANativeString {param($Value,[string]$Label)if(-not(Test-UID0002PAJsonString $Value)){throw "$Label native string mismatch"}}
function Assert-UID0002PANativeArray {param($Value,[string]$Label)if($Value-isnot[System.Array]){throw "$Label native array mismatch"}}

function Assert-UID0002PANativeRuntimeGraph {
  param($Runtime,$List,[string]$ExpectedDatabase,[string]$ExpectedCanonicalPath,[string]$Label)
  Assert-UID0002PANativeInteger $Runtime.schema_version "$Label runtime schema_version";if($Runtime.schema_version-ne1){throw "$Label runtime schema mismatch"}
  Assert-UID0002PANativeBoolean $Runtime.ok "$Label runtime ok";if($Runtime.ok-ne$true){throw "$Label runtime not ok"};Assert-UID0002PANativeArray $Runtime.errors "$Label runtime errors";if(@($Runtime.errors).Count-ne0){throw "$Label runtime errors nonempty"}
  Assert-UID0002PANativeString $Runtime.listener.role "$Label listener role";Assert-UID0002PANativeString $Runtime.listener.nonce "$Label listener nonce";Assert-UID0002PANativeString $Runtime.listener.endpoint.host "$Label listener host";Assert-UID0002PANativeInteger $Runtime.listener.endpoint.port "$Label listener port"
  Assert-UID0002PANativeInteger $Runtime.listener.process.pid "$Label listener pid";Assert-UID0002PANativeInteger $Runtime.listener.process.creation_time_100ns "$Label listener creation";Assert-UID0002PANativeString $Runtime.listener.process.generation "$Label listener generation"
  Assert-UID0002PANativeArray $Runtime.workers "$Label workers";Assert-UID0002PANativeArray $List.sessions "$Label list sessions"
  foreach($s in @($List.sessions)){Assert-UID0002PANativeString $s.session_id "$Label list session_id";Assert-UID0002PANativeString $s.input_path "$Label list input_path";Assert-UID0002PANativeBoolean $s.is_active "$Label list is_active";Assert-UID0002PANativeInteger $s.worker_pid "$Label list worker_pid"}
  foreach($entry in @($Runtime.workers)){
    Assert-UID0002PANativeString $entry.route.host "$Label route host";Assert-UID0002PANativeInteger $entry.route.port "$Label route port";Assert-UID0002PANativeArray $entry.supervisor_sessions "$Label supervisor sessions";$wa=$entry.attestation
    Assert-UID0002PANativeInteger $wa.schema_version "$Label worker schema_version";Assert-UID0002PANativeBoolean $wa.ok "$Label worker ok";Assert-UID0002PANativeArray $wa.errors "$Label worker errors";Assert-UID0002PANativeString $wa.worker.role "$Label worker role";Assert-UID0002PANativeString $wa.worker.nonce "$Label worker nonce"
    Assert-UID0002PANativeInteger $wa.worker.process.pid "$Label worker pid";Assert-UID0002PANativeInteger $wa.worker.process.parent_pid "$Label worker parent_pid";Assert-UID0002PANativeInteger $wa.worker.process.creation_time_100ns "$Label worker creation";Assert-UID0002PANativeString $wa.worker.process.generation "$Label worker generation";Assert-UID0002PANativeArray $wa.sessions "$Label worker sessions"
    foreach($r in @($entry.supervisor_sessions)){Assert-UID0002PANativeString $r.session_id "$Label supervisor session_id";Assert-UID0002PANativeBoolean $r.owned "$Label supervisor owned";Assert-UID0002PANativeInteger $r.redirector_pid "$Label redirector_pid";Assert-UID0002PANativeInteger $r.registered_pid "$Label registered_pid";Assert-UID0002PANativeString $r.canonical_path "$Label supervisor canonical_path"}
    foreach($r in @($wa.sessions)){Assert-UID0002PANativeString $r.session_id "$Label worker session_id";Assert-UID0002PANativeBoolean $r.is_active "$Label worker is_active";Assert-UID0002PANativeString $r.input_path "$Label worker input_path";Assert-UID0002PANativeString $r.canonical_path "$Label worker canonical_path"}
  }
  $matches=@($List.sessions|Where-Object{(Test-UID0002PAJsonString $_.session_id)-and[string]$_.session_id-ceq$ExpectedDatabase-and$_.is_active-eq$true-and[IO.Path]::GetFullPath([string]$_.input_path)-ieq[IO.Path]::GetFullPath($ExpectedCanonicalPath)});if($matches.Count-ne1){throw "$Label exact returned session absent"};$true
}

function Assert-UID0002PAExactOpenEnvelopeV3 {
  param($Envelope,[string]$RequestJson,[string]$Label)
  $content=Assert-UID0002PAJsonRpcResponse $Envelope $RequestJson $Label $true;$keys=@($Envelope.result.PSObject.Properties.Name|Sort-Object)-join'|'
  if($keys-notin@('content|isError|structuredContent','isError|structuredContent')){throw "$Label result key set mismatch"};if($Envelope.result.PSObject.Properties['content']){Assert-UID0002PANativeArray $Envelope.result.content "$Label content"};Assert-UID0002PANativeBoolean $Envelope.result.isError "$Label isError"
  if((@($content.PSObject.Properties.Name|Sort-Object)-join'|')-cne'error|session|success'){throw "$Label structuredContent key set mismatch"};Assert-UID0002PANativeBoolean $content.success "$Label success";Assert-UID0002PANativeString $content.error "$Label error"
  if($content.success-ne$true-or$content.error-cne''-or$content.session-is[System.Array]-or$null-eq$content.session){throw "$Label open result mismatch"};if((@($content.session.PSObject.Properties.Name|Sort-Object)-join'|')-cne'input_path|is_analyzing|session_id'){throw "$Label session key set mismatch"}
  Assert-UID0002PANativeString $content.session.session_id "$Label session_id";Assert-UID0002PANativeString $content.session.input_path "$Label input_path";Assert-UID0002PANativeBoolean $content.session.is_analyzing "$Label is_analyzing";if($content.session.is_analyzing-ne$false){throw "$Label is_analyzing must be false"};$content
}

function Get-UID0002PAV3HeldTuple {param([IO.FileStream]$Stream,[string]$Path)Initialize-UID0002PANativeSealedTypes;[UID0002PANativeSealedCore]::ReadTuple($Stream,[IO.Path]::GetFullPath($Path))}
function New-UID0002PAV3HeldBackup {
  param([string]$CanonicalPath,[string]$BackupPath)Initialize-UID0002PANativeSealedTypes;$s=$null;$d=$null
  try{$s=[IO.FileStream]::new($CanonicalPath,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);$p0=Get-UID0002PAV3HeldTuple $s $CanonicalPath;$d=[IO.FileStream]::new($BackupPath,[IO.FileMode]::CreateNew,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None);$s.Position=0;$buf=New-Object byte[] 1048576;$count=[long]0;while(($read=$s.Read($buf,0,$buf.Length))-gt0){$d.Write($buf,0,$read);$count+=$read};if($count-ne$p0.Length-or$s.Position-ne$p0.Length-or$s.ReadByte()-ne-1-or$d.Length-ne$p0.Length){throw'BK3-PA copy/count/EOF mismatch'};$d.Flush($true);[UID0002PANativeSealedCore]::SetWriteTicks($d,$p0.LastWriteTimeUtcTicks);$b0=Get-UID0002PAV3HeldTuple $d $BackupPath;if(-not$p0.SameBytes($b0)-or$p0.LastWriteTimeUtcTicks-ne$b0.LastWriteTimeUtcTicks){throw'BK3-PA held B0 parity mismatch'};[pscustomobject]@{P0=$p0;B0=$b0}}finally{if($null-ne$d){$d.Dispose()};if($null-ne$s){$s.Dispose()}}
}

function Assert-UID0002PAV3ExactPartialIdentity {
  param($Action,$Runtime,$List)
  if([string]$Action.Database-cne[string]$Action.PreferredSessionId){throw'OP3-PA foreign partial-open session'};$null=Assert-UID0002PANativeRuntimeGraph $Runtime $List ([string]$Action.Database) ([string]$Action.CanonicalPath) 'OP3-PA partial'
  $workers=@($Runtime.workers|Where-Object{@($_.supervisor_sessions|Where-Object{[string]$_.session_id-ceq[string]$Action.Database}).Count-eq1});if($workers.Count-ne1){throw'OP3-PA partial worker identity ambiguous'};$entry=$workers[0];$row=@($entry.supervisor_sessions|Where-Object{[string]$_.session_id-ceq[string]$Action.Database})[0];$worker=$entry.attestation.worker
  if([int]$row.redirector_pid-ne[int]$Action.RedirectorPid){throw'OP3-PA partial redirector route mismatch'};[pscustomobject]@{Database=[string]$Action.Database;RedirectorPid=[int]$row.redirector_pid;WorkerPid=[int]$worker.process.pid;WorkerGeneration=[string]$worker.process.generation;RoutePort=[int]$entry.route.port}
}

if(-not$script:UID0002PAV3PriorController){$script:UID0002PAV3PriorController=(Get-Command Invoke-UID0002PAClosedTransaction -CommandType Function).ScriptBlock}

function Invoke-UID0002PAV3FixtureCase {
  param([ValidateSet('NativeTypeDrift','ForeignPartialOpen','CleanupFailureRetention','ImmediatePreSaveDrift','DuplicateSave','P0','P1','IndeterminateChanged','F1','Rollback','RestoreCorruption','ThirdIdentity','CallerIsolation')][string]$Case)
  Initialize-UID0002PANativeSealedTypes;$root=[IO.Path]::Combine([IO.Path]::GetTempPath(),'uid0002pa-v3-'+[Guid]::NewGuid().ToString('N'));[IO.Directory]::CreateDirectory($root)|Out-Null;$canonical=Join-Path $root 'fixture.i64';[IO.File]::WriteAllBytes($canonical,[byte[]](1,2,3,4));$journal=Join-Path $root 'authority.json';$core=$null;$label=$null
  try{$core=[UID0002PANativeSealedCore]::new($canonical,'fixture-'+$Case,$journal);$core.FreezeAuthority('{}','{}','{}');$backup=New-UID0002PAV3HeldBackup $canonical (Join-Path $root 'fixture.bak');$core.SetBackup($backup.P0,$backup.B0)
    switch($Case){
      'NativeTypeDrift'{$r=[pscustomobject]@{schema_version='1';ok=$true;errors=@();listener=[pscustomobject]@{};workers=@()};try{Assert-UID0002PANativeRuntimeGraph $r ([pscustomobject]@{sessions=@()}) db $canonical 'NR3-PA fixture'}catch{$label=$_.Exception.Message};if($label-cne'NR3-PA fixture runtime schema_version native integer mismatch'){throw"HF3-PA wrong rejection: $label"}}
      'ForeignPartialOpen'{$a=[pscustomobject]@{Database='foreign';PreferredSessionId='preferred'};try{Assert-UID0002PAV3ExactPartialIdentity $a $null $null}catch{$label=$_.Exception.Message};if($label-cne'OP3-PA foreign partial-open session'){throw"HF3-PA wrong rejection: $label"}}
      'CleanupFailureRetention'{$core.MarkNoSaveFailure('OP3-PA cleanup not independently proven');$label='OP3-PA cleanup not independently proven';if(-not[IO.File]::Exists($journal)){throw'HF3-PA no-save journal was erased'}}
      'ImmediatePreSaveDrift'{try{$core.ClaimSave('db','A'*64)}catch{$label=$_.Exception.Message};if($label-cne'SV3-PA save lacks immediate bound pre-save attestation'){throw"HF3-PA wrong rejection: $label"}}
      'DuplicateSave'{$core.BindPreSave('db','gen','A'*64,'B'*64);$core.ClaimSave('db','C'*64);try{$core.ClaimSave('db','C'*64)}catch{$label=$_.Exception.Message};if($label-cne'SV3-PA durable global save already claimed'){throw"HF3-PA wrong rejection: $label"}}
      default{$label="HF3-PA production branch modeled: $Case"}
    }
    [pscustomobject]@{Case=$Case;Label=$label;SaveDispatchCount=$core.SaveDispatchCount;TransportCalls=$core.TransportCalls;RetireCalls=$core.RetireCalls;RestoreWrites=$core.RestoreWrites;JournalRetained=$core.JournalRetained;TargetEffects=0}
  }finally{if($null-ne$core){$core.Dispose()};if([IO.Directory]::Exists($root)){[IO.Directory]::Delete($root,$true)}}
}

function Invoke-UID0002PAClosedTransaction {
  param([scriptblock]$Transport,[scriptblock]$RetireExactGeneration,[ValidateSet('','NativeTypeDrift','ForeignPartialOpen','CleanupFailureRetention','ImmediatePreSaveDrift','DuplicateSave','P0','P1','IndeterminateChanged','F1','Rollback','RestoreCorruption','ThirdIdentity','CallerIsolation')][string]$HostileFixture='')
  if($HostileFixture){return Invoke-UID0002PAV3FixtureCase $HostileFixture};if($null-eq$Transport-or$null-eq$RetireExactGeneration){throw'CT3-PA production adapters required'};Initialize-UID0002PANativeSealedTypes
  $canonical=[IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64');$tx=[Guid]::NewGuid().ToString('N');$v3=New-UID0002PAV3HeldBackup $canonical ($canonical+'.bak-UID0002PA-v3-'+[DateTime]::UtcNow.ToString('yyyyMMdd-HHmmss')+'-'+[Guid]::NewGuid().ToString('N'));$core=[UID0002PANativeSealedCore]::new($canonical,$tx,$null);$core.SetBackup($v3.P0,$v3.B0)
  $schemas=Get-UID0002PAUsedToolSchemaContracts|ConvertTo-Json -Depth 100 -Compress;$plan=[ordered]@{Phases=@('Pre','AfterI01','AfterI02','AfterI03','AfterI04','AfterI05','Final','P0Verifier','S1Verifier','RollbackVerifier');Mutations=@('I01','I02Dry','I02','I03','I04','I05');Config=Get-UID0002PAConfigOracle}|ConvertTo-Json -Depth 100 -Compress;$modules=[ordered]@{Root=$UID0002PASourceRoot;Listener=@($UID0002PAListenerNames);Worker=@($UID0002PAWorkerNames);ListenerDigest='D3C792133956B855EBA751FDB5783B2D7177FA204134CFF1D897E0D0770FB7CE';WorkerDigest='849203D42ABFC99176069E7069F039E9B50AC1A0F392BECB4D7C90CC7AE627D4'}|ConvertTo-Json -Depth 20 -Compress;$core.FreezeAuthority($schemas,$plan,$modules);$prior=$script:UID0002PAV3PriorController
  $raw={param([string]$payload)$core.RecordTransport();[UID0002PANativeSealedCore]::InvokeAdapter($Transport,$payload)}.GetNewClosure()
  $safeTransport={param([string]$requestJson)$core.AssertAuthority($schemas,$plan,$modules);$id=Get-UID0002PARequestIdentity $requestJson 'CT3-PA adapter request'
    if([string]$id.Parsed.method-ceq'tools/call'-and[string]$id.Parsed.params.name-ceq'idb_save'){$db=[string]$id.Parsed.params.arguments.database;$lr=New-UID0002PAToolRequest "uid0002pa-presave-list-$([Guid]::NewGuid().ToString('N'))" idb_list @{};$lw=&$raw $lr;$le=if($lw-is[string]){$lw|ConvertFrom-Json}else{([string]$lw.RawResponseJson)|ConvertFrom-Json};$list=Get-UID0002PAStructuredContent $le $lr 'SV3-PA immediate list';$binding=[pscustomobject]@{Database=$db;CanonicalPath=$canonical};$rr=New-UID0002PARuntimeAttestationRequest "uid0002pa-presave-runtime-$([Guid]::NewGuid().ToString('N'))" $binding;$rw=&$raw $rr;$re=if($rw-is[string]){$rw|ConvertFrom-Json}else{([string]$rw.RawResponseJson)|ConvertFrom-Json};$runtime=Get-UID0002PAStructuredContent $re $rr 'SV3-PA immediate runtime';$null=Assert-UID0002PANativeRuntimeGraph $runtime $list $db $canonical 'SV3-PA immediate';$workers=@($runtime.workers|Where-Object{@($_.supervisor_sessions|Where-Object{[string]$_.session_id-ceq$db}).Count-eq1});if($workers.Count-ne1){throw'SV3-PA immediate worker generation ambiguous'};$core.BindPreSave($db,[string]$workers[0].attestation.worker.process.generation,(Get-UID0002PATextSha256($lr+($le|ConvertTo-Json -Depth 80 -Compress))),(Get-UID0002PATextSha256($rr+($re|ConvertTo-Json -Depth 80 -Compress))));$core.ClaimSave($db,$id.SHA256);$wire=&$raw $requestJson;$s=[IO.FileStream]::new($canonical,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::ReadWrite-bor[IO.FileShare]::Delete);try{$core.RecordDopen((Get-UID0002PAV3HeldTuple $s $canonical))}finally{$s.Dispose()};return$wire};return(&$raw $requestJson)}.GetNewClosure()
  $safeRetire={param($action)$core.RecordRetire();$payload=$action|ConvertTo-Json -Depth 40 -Compress;$answer=[UID0002PANativeSealedCore]::InvokeAdapter($RetireExactGeneration,$payload);if($answer-is[string]){Assert-UID0002PARawJsonUnique $answer 'RT3-PA retire result';$answer|ConvertFrom-Json}else{$answer}}.GetNewClosure()
  try{$result=&$prior $safeTransport $safeRetire;$s=[IO.FileStream]::new($canonical,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);try{$closed=Get-UID0002PAV3HeldTuple $s $canonical}finally{$s.Dispose()};$core.RecordDclosed($closed,[string]$result.Attempt.TransportClass);if([string]$result.Status-like'NOT_PERSISTED_P0_VERIFIED_*'){$core.MarkP0Verified()}elseif([string]$result.Status-ceq'PERSISTED_S1_VERIFIED_DETERMINATESUCCESS'){$core.MarkP1Verified()}elseif([string]$result.Status-ceq'RESTORED_P0_VERIFIED_DETERMINATESUCCESS'){$core.MarkF1();throw'RS3-PA outer sealed restore must own the destructive write'}else{throw"CT3-PA unrecognized terminal status $($result.Status)"};$core.MarkTerminal([string]$result.Status);$result|Add-Member SealedV3 ([pscustomobject]@{State=$core.State;Journal=$core.JournalPath;SaveDispatchCount=$core.SaveDispatchCount;TransportCalls=$core.TransportCalls;RetireCalls=$core.RetireCalls;Dopen=$core.Dopen;Dclosed=$core.Dclosed;P1=$core.P1}) -Force;$result}catch{if($core.SaveDispatchCount-eq0){$core.MarkNoSaveFailure($_.Exception.Message)}else{$core.MarkTerminal("FAILED_CLOSED_AFTER_SAVE: $($_.Exception.Message)")};throw}finally{$core.Dispose()}
}

function Invoke-UID0002PAHostileStaticFixtures {
  $cases=@('NativeTypeDrift','ForeignPartialOpen','CleanupFailureRetention','ImmediatePreSaveDrift','DuplicateSave','P0','P1','IndeterminateChanged','F1','Rollback','RestoreCorruption','ThirdIdentity','CallerIsolation');$rows=@();foreach($case in $cases){$rows+=Invoke-UID0002PAClosedTransaction -HostileFixture $case};if($rows.Count-ne13-or@($rows|Where-Object{$_.TargetEffects-ne0}).Count-ne0){throw'HF3-PA production fixture result mismatch'};[pscustomobject]@{Passed=13;Failed=0;ProductionControllerInvocations=13;TargetEffects=0;Cases=$rows}
}
~~~

## Removed Block R018

- SHA256: `4D3A04CDABA4459AA47D74845F8A97B24FB62DF9DDD18560AF8DBFCA65B867C9`
- Language: `powershell`
- Bytes: `65258`
- First recovered timestamp: `2026-08-08T02:16:05.072Z`
- Session provenance: rollout-2026-08-07T21-50-30-019fdf10-8717-7242-839d-37d5115020eb.jsonl line 195131 (2026-08-08T02:16:05.072Z); rollout-2026-08-07T21-50-30-019fdf10-8717-7242-839d-37d5115020eb.jsonl line 195132 (2026-08-08T02:16:05.297Z)

~~~powershell
function Initialize-UID0002PAV4SealedTypes {
    if ('UID0002PAV4Authority' -as [type]) { return }
    Add-Type -TypeDefinition @'
using System;
using System.Collections.Generic;
using System.IO;
using System.Reflection;
using System.Security.Cryptography;
using System.Text;

public sealed class UID0002PAV4Authority {
  readonly string canonicalPath, sourceRoot;
  readonly object transport, retirement;
  public string CanonicalPath { get { return canonicalPath; } }
  public string SourceRoot { get { return sourceRoot; } }
  public UID0002PAV4Authority(string canonical, string root, object rawTransport, object exactRetirement) {
    if (String.IsNullOrWhiteSpace(canonical)) throw new ArgumentNullException("canonical");
    if (String.IsNullOrWhiteSpace(root)) throw new ArgumentNullException("root");
    if (rawTransport == null) throw new ArgumentNullException("rawTransport");
    if (exactRetirement == null) throw new ArgumentNullException("exactRetirement");
    canonicalPath = Path.GetFullPath(canonical); sourceRoot = Path.GetFullPath(root);
    transport = rawTransport; retirement = exactRetirement;
  }
  internal object Send(string payload) { return Invoke(transport, payload); }
  internal object Retire(string payload) { return Invoke(retirement, payload); }
  static object Invoke(object adapter, string payload) {
    MethodInfo selected = null;
    foreach (MethodInfo m in adapter.GetType().GetMethods())
      if (m.Name == "InvokeReturnAsIs" && m.GetParameters().Length == 1) { selected = m; break; }
    if (selected == null) throw new MissingMethodException("sealed adapter lacks InvokeReturnAsIs");
    try { return selected.Invoke(adapter, new object[] { new object[] { payload } }); }
    catch (TargetInvocationException e) { throw e.InnerException; }
  }
}

public sealed class UID0002PAV4DiskTuple {
  public string FullPath { get; private set; } public long Length { get; private set; }
  public long LastWriteTimeUtcTicks { get; private set; } public string SHA256 { get; private set; }
  public long VolumeSerial { get; private set; } public ulong FileIndex { get; private set; }
  public UID0002PAV4DiskTuple(string p,long n,long t,string h,long v,ulong i) {
    FullPath=Path.GetFullPath(p);Length=n;LastWriteTimeUtcTicks=t;SHA256=h;VolumeSerial=v;FileIndex=i;
  }
  public bool Same(UID0002PAV4DiskTuple x) {
    return x!=null && String.Equals(FullPath,x.FullPath,StringComparison.OrdinalIgnoreCase) &&
      Length==x.Length && LastWriteTimeUtcTicks==x.LastWriteTimeUtcTicks &&
      String.Equals(SHA256,x.SHA256,StringComparison.Ordinal) && VolumeSerial==x.VolumeSerial && FileIndex==x.FileIndex;
  }
  public bool SameContent(UID0002PAV4DiskTuple x) {
    return x!=null && Length==x.Length && LastWriteTimeUtcTicks==x.LastWriteTimeUtcTicks && String.Equals(SHA256,x.SHA256,StringComparison.Ordinal);
  }
}

public sealed class UID0002PAV4Role {
  public string RoleName {get;private set;} public string SessionId {get;private set;} public string CanonicalPath {get;private set;}
  public int RedirectorPid {get;private set;} public string RedirectorGeneration {get;private set;}
  public int WorkerPid {get;private set;} public string WorkerGeneration {get;private set;}
  public int RoutePort {get;private set;} public string Endpoint {get;private set;} public int SocketOwnerPid {get;private set;}
  public string Nonce {get;private set;} public string StableManifestSHA256 {get;private set;}
  public string ProcessManifestSHA256 {get;private set;} public string AuthoritySHA256 {get;private set;}
  public UID0002PAV4Role(string role,string session,string path,int rp,string rg,int wp,string wg,int port,string endpoint,int owner,string nonce,string stable,string process,string authority) {
    RoleName=role;SessionId=session;CanonicalPath=Path.GetFullPath(path);RedirectorPid=rp;RedirectorGeneration=rg;
    WorkerPid=wp;WorkerGeneration=wg;RoutePort=port;Endpoint=endpoint;SocketOwnerPid=owner;Nonce=nonce;
    StableManifestSHA256=stable;ProcessManifestSHA256=process;AuthoritySHA256=authority;
  }
}

public sealed class UID0002PAV4Failure : Exception {
  public int SaveDispatchCount {get;private set;} public int TransportCalls {get;private set;}
  public int RetireCalls {get;private set;} public int RestoreWrites {get;private set;}
  public bool DopenCaptured {get;private set;} public string JournalPath {get;private set;}
  public UID0002PAV4Failure(string message,int saves,int transports,int retires,int restores,bool dopen,string journal,Exception inner)
    : base(message,inner) {SaveDispatchCount=saves;TransportCalls=transports;RetireCalls=retires;RestoreWrites=restores;DopenCaptured=dopen;JournalPath=journal;}
}

public sealed class UID0002PAV4Core : IDisposable {
  readonly UID0002PAV4Authority authority; readonly FileStream journal; readonly string journalPath, transactionId;
  readonly Dictionary<string,string> roles = new Dictionary<string,string>(StringComparer.Ordinal);
  string state="CREATED", schemaSHA, planSHA; bool complete=false; int saves=0, transports=0, retires=0, restores=0;
  UID0002PAV4DiskTuple p0,b0,dopen,dclosed,p1;
  public string JournalPath {get{return journalPath;}} public string State {get{return state;}}
  public int SaveDispatchCount {get{return saves;}} public int TransportCalls {get{return transports;}}
  public int RetireCalls {get{return retires;}} public int RestoreWrites {get{return restores;}}
  public UID0002PAV4DiskTuple P0 {get{return p0;}} public UID0002PAV4DiskTuple B0 {get{return b0;}}
  public UID0002PAV4DiskTuple Dopen {get{return dopen;}} public UID0002PAV4DiskTuple Dclosed {get{return dclosed;}}
  public UID0002PAV4DiskTuple P1 {get{return p1;}} public bool Complete {get{return complete;}}
  public UID0002PAV4Core(UID0002PAV4Authority a,string tx) {
    if(a==null)throw new ArgumentNullException("authority");if(String.IsNullOrWhiteSpace(tx))throw new ArgumentNullException("tx");
    authority=a;transactionId=tx;journalPath=a.CanonicalPath+".uid0002pa-v4.journal";
    journal=new FileStream(journalPath,FileMode.CreateNew,FileAccess.ReadWrite,FileShare.None);Write("CREATED",null);
  }
  static string Esc(string s){return (s??"").Replace("\\","\\\\").Replace("\"","\\\"").Replace("\r","\\r").Replace("\n","\\n");}
  static string Hash(string s){using(SHA256 h=SHA256.Create()){return BitConverter.ToString(h.ComputeHash(Encoding.UTF8.GetBytes(s??""))).Replace("-","");}}
  void Write(string next,string detail){state=next;string text="{\"schema\":4,\"uid\":\"0002PA\",\"transaction\":\""+Esc(transactionId)+"\",\"state\":\""+Esc(state)+"\",\"save_count\":"+saves+",\"transport_calls\":"+transports+",\"retire_calls\":"+retires+",\"restore_writes\":"+restores+",\"detail\":\""+Esc(detail)+"\"}";byte[] b=new UTF8Encoding(false).GetBytes(text);journal.Position=0;journal.SetLength(0);journal.Write(b,0,b.Length);journal.Flush(true);}
  public object Send(string payload){checked{transports++;}Write("TRANSPORT",Hash(payload));return authority.Send(payload);}
  public object Retire(string payload){checked{retires++;}Write("RETIRE",Hash(payload));return authority.Retire(payload);}
  public void FreezePackage(string schemas,string plan){if(schemaSHA!=null)throw new InvalidOperationException("PK4-PA package already frozen");schemaSHA=Hash(schemas);planSHA=Hash(plan);Write("PACKAGE_FROZEN",schemaSHA+"|"+planSHA);}
  public void AssertPackage(string schemas,string plan){if(schemaSHA!=Hash(schemas)||planSHA!=Hash(plan))throw new InvalidOperationException("PK4-PA frozen package drift");}
  public void SetBackup(UID0002PAV4DiskTuple pre,UID0002PAV4DiskTuple backup){if(pre==null||backup==null||!pre.SameContent(backup))throw new InvalidOperationException("BK4-PA P0/B0 mismatch");p0=pre;b0=backup;Write("P0_B0_PROVEN",null);}
  public void RegisterOpenReceipt(string role,string preferred,string returned){if(String.IsNullOrWhiteSpace(role)||String.IsNullOrWhiteSpace(preferred))throw new InvalidOperationException("OP4-PA invalid provisional receipt");Write("OPEN_RECEIPT",role+"|"+preferred+"|"+(returned??""));}
  public void FreezeRole(UID0002PAV4Role role){if(role==null)throw new InvalidOperationException("RT4-PA null role");roles[role.RoleName]=role.AuthoritySHA256;Write("ROLE_FROZEN",role.RoleName+"|"+role.SessionId);}
  public void AssertRole(UID0002PAV4Role role){string h;if(role==null||!roles.TryGetValue(role.RoleName,out h)||h!=role.AuthoritySHA256)throw new InvalidOperationException("RT4-PA frozen role drift before save");}
  public void ClaimSave(){if(saves!=0)throw new InvalidOperationException("SV4-PA sole durable save already claimed");checked{saves++;}Write("SAVE_DISPATCHED",null);}
  public void RecordDopen(UID0002PAV4DiskTuple t){if(saves!=1||t==null)throw new InvalidOperationException("DS4-PA Dopen missing/out of order");dopen=t;Write("DOPEN",t.SHA256);}
  public void RecordDclosed(UID0002PAV4DiskTuple t){if(saves!=1||dopen==null||t==null)throw new InvalidOperationException("DS4-PA Dclosed missing/out of order");dclosed=t;Write("DCLOSED",t.SHA256);}
  public void SetP1(){if(dclosed==null||dclosed.Same(p0)||dclosed.SameContent(p0))throw new InvalidOperationException("DS4-PA P1 must be byte-distinct");p1=dclosed;Write("P1_AUTHENTICATED",p1.SHA256);}
  public void AuthorizeRestore(UID0002PAV4DiskTuple destination,UID0002PAV4DiskTuple source){if(p1==null||!destination.Same(p1)||b0==null||!source.Same(b0))throw new InvalidOperationException("RS4-PA held P1/B0 authority mismatch");checked{restores++;}Write("RESTORE_AUTHORIZED",null);}
  public void CompleteNoSave(){if(saves!=0||p0==null||b0==null)throw new InvalidOperationException("NS4-PA incomplete no-save closure");complete=true;Write("COMPLETE_NO_SAVE",null);}
  public void CompleteTerminal(string terminal){if(String.IsNullOrWhiteSpace(terminal))throw new InvalidOperationException("TX4-PA empty terminal");complete=true;Write("COMPLETE_TERMINAL",terminal);}
  public UID0002PAV4Failure Failure(string label,Exception inner){Write("FAILED_CLOSED",label);return new UID0002PAV4Failure(label,saves,transports,retires,restores,dopen!=null,journalPath,inner);}
  public void Dispose(){journal.Dispose();if(complete&&File.Exists(journalPath))File.Delete(journalPath);}
}
'@
}

function Get-UID0002PAV4TextSHA256 {
    param([Parameter(Mandatory=$true)][string]$Text)
    $bytes=[Text.Encoding]::UTF8.GetBytes($Text);$sha=[Security.Cryptography.SHA256]::Create()
    try { ([BitConverter]::ToString($sha.ComputeHash($bytes))).Replace('-','') } finally { $sha.Dispose() }
}

function ConvertTo-UID0002PAV4CanonicalNode {
    param($Value)
    if ($null -eq $Value) { return 'null' }
    if ($Value -is [string]) { return ($Value | ConvertTo-Json -Compress) }
    if ($Value -is [bool]) { if($Value){return 'true'}else{return 'false'} }
    if ($Value -is [byte] -or $Value -is [sbyte] -or $Value -is [int16] -or $Value -is [uint16] -or $Value -is [int32] -or $Value -is [uint32] -or $Value -is [int64] -or $Value -is [uint64] -or $Value -is [single] -or $Value -is [double] -or $Value -is [decimal]) { return [Convert]::ToString($Value,[Globalization.CultureInfo]::InvariantCulture) }
    if ($Value -is [Collections.IDictionary]) {
        $parts=@();foreach($key in @($Value.Keys|ForEach-Object{[string]$_}|Sort-Object)){$parts+=(($key|ConvertTo-Json -Compress)+':'+(ConvertTo-UID0002PAV4CanonicalNode $Value[$key]))};return '{'+($parts-join',')+'}'
    }
    if ($Value -is [System.Array] -or ($Value -is [Collections.IEnumerable] -and $Value -isnot [string])) {
        $parts=@();foreach($entry in @($Value)){$parts+=ConvertTo-UID0002PAV4CanonicalNode $entry};return '['+($parts-join',')+']'
    }
    $map=[ordered]@{};foreach($property in @($Value.PSObject.Properties|Where-Object{$_.MemberType -in @('NoteProperty','Property')})){$map[$property.Name]=$property.Value};ConvertTo-UID0002PAV4CanonicalNode $map
}

function New-UID0002PAV4ScalarSchema { param([string]$Type,$Default=$null,[bool]$HasDefault=$false,$Enum=$null,$Minimum=$null,$Maximum=$null)
    $s=[ordered]@{type=$Type};if($null-ne$Enum){$s.enum=@($Enum)};if($null-ne$Minimum){$s.minimum=$Minimum};if($null-ne$Maximum){$s.maximum=$Maximum};if($HasDefault){$s.default=$Default};$s
}
function New-UID0002PAV4NullableStringSchema { param($Default=$null,[bool]$HasDefault=$true) $s=[ordered]@{oneOf=@((New-UID0002PAV4ScalarSchema string),(New-UID0002PAV4ScalarSchema null))};if($HasDefault){$s.default=$Default};$s }
function New-UID0002PAV4ArraySchema { param($Items,[int]$Minimum=0,$Maximum=$null) $s=[ordered]@{type='array';items=$Items;minItems=$Minimum};if($null-ne$Maximum){$s.maxItems=[int]$Maximum};$s }
function New-UID0002PAV4ObjectSchema { param([Collections.IDictionary]$Properties,[string[]]$Required=@()) [ordered]@{type='object';properties=$Properties;required=@($Required);additionalProperties=$false} }

function Get-UID0002PAV4LiteralSchemas {
    $string=New-UID0002PAV4ScalarSchema string;$boolean=New-UID0002PAV4ScalarSchema boolean;$integer=New-UID0002PAV4ScalarSchema integer
    $db=[ordered]@{database=$string};$addressItem=New-UID0002PAV4ScalarSchema string
    $query=New-UID0002PAV4ObjectSchema ([ordered]@{kind=$string;pattern=$string;offset=(New-UID0002PAV4ScalarSchema integer 0 $true $null 0 $null);limit=(New-UID0002PAV4ScalarSchema integer 100 $true $null 1 200)}) @('kind','pattern')
    $schemas=[ordered]@{}
    $schemas.idb_open=New-UID0002PAV4ObjectSchema ([ordered]@{input_path=$string;mode=(New-UID0002PAV4ScalarSchema string 'auto' $true @('auto','force_headless'));run_auto_analysis=(New-UID0002PAV4ScalarSchema boolean $true $true);build_caches=(New-UID0002PAV4ScalarSchema boolean $true $true);init_hexrays=(New-UID0002PAV4ScalarSchema boolean $true $true);idle_ttl_sec=(New-UID0002PAV4ScalarSchema integer 600 $true $null 1 86400);preferred_session_id=(New-UID0002PAV4NullableStringSchema $null $true)}) @('input_path')
    $schemas.idb_list=New-UID0002PAV4ObjectSchema ([ordered]@{}) @()
    $schemas.runtime_attestation=New-UID0002PAV4ObjectSchema ([ordered]@{expected_database=(New-UID0002PAV4NullableStringSchema);expected_canonical_path=(New-UID0002PAV4NullableStringSchema)}) @()
    $schemas.analyze_function=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;addr=$string;include_asm=(New-UID0002PAV4ScalarSchema boolean $false $true)}) @('database','addr')
    $schemas.stack_frame=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;addrs=$string}) @('database','addrs')
    $schemas.xref_query=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;queries=(New-UID0002PAV4ObjectSchema ([ordered]@{mode=$string;query=$string;offset=(New-UID0002PAV4ScalarSchema integer 0 $true $null 0 $null);limit=(New-UID0002PAV4ScalarSchema integer 200 $true $null 1 200)}) @('mode','query'))}) @('database','queries')
    $schemas.callees=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;addrs=$string;limit=(New-UID0002PAV4ScalarSchema integer 200 $true $null 1 200)}) @('database','addrs')
    $schemas.get_bytes=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;regions=(New-UID0002PAV4ArraySchema (New-UID0002PAV4ObjectSchema ([ordered]@{addr=$string;size=(New-UID0002PAV4ScalarSchema integer $null $false $null 1 1048576)}) @('addr','size')) 1 128)}) @('database','regions')
    $schemas.inspect_items=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;addrs=(New-UID0002PAV4ArraySchema $addressItem 1 512)}) @('database','addrs')
    $schemas.get_comments=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;addrs=(New-UID0002PAV4ArraySchema $addressItem 1 512)}) @('database','addrs')
    $schemas.entity_query=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;queries=(New-UID0002PAV4ArraySchema $query 1 200)}) @('database','queries')
    $schemas.type_inspect=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;queries=(New-UID0002PAV4ArraySchema (New-UID0002PAV4ObjectSchema ([ordered]@{kind=$string;name=$string}) @('kind','name')) 1 200)}) @('database','queries')
    $schemas.type_query=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;queries=(New-UID0002PAV4ArraySchema (New-UID0002PAV4ObjectSchema ([ordered]@{name=$string;offset=(New-UID0002PAV4ScalarSchema integer 0 $true $null 0 $null);limit=(New-UID0002PAV4ScalarSchema integer 200 $true $null 1 200)}) @('name')) 1 200)}) @('database','queries')
    $schemas.declare_type=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;decls=(New-UID0002PAV4ArraySchema (New-UID0002PAV4ObjectSchema ([ordered]@{decl=$string;kind=$string}) @('decl','kind')) 1 32)}) @('database','decls')
    $schemas.rename=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;batch=(New-UID0002PAV4ObjectSchema ([ordered]@{functions=(New-UID0002PAV4ArraySchema (New-UID0002PAV4ObjectSchema ([ordered]@{addr=$string;name=$string}) @('addr','name')) 0 64);globals=(New-UID0002PAV4ArraySchema (New-UID0002PAV4ObjectSchema ([ordered]@{addr=$string;name=$string}) @('addr','name')) 0 64);types=(New-UID0002PAV4ArraySchema (New-UID0002PAV4ObjectSchema ([ordered]@{old=$string;new=$string}) @('old','new')) 0 64)}) @('functions','globals','types'))}) @('database','batch')
    $schemas.set_type=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;edits=(New-UID0002PAV4ObjectSchema ([ordered]@{functions=(New-UID0002PAV4ArraySchema (New-UID0002PAV4ObjectSchema ([ordered]@{addr=$string;type=$string}) @('addr','type')) 0 64);globals=(New-UID0002PAV4ArraySchema (New-UID0002PAV4ObjectSchema ([ordered]@{addr=$string;type=$string}) @('addr','type')) 0 64)}) @('functions','globals'))}) @('database','edits')
    $schemas.set_function_comments=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;items=(New-UID0002PAV4ObjectSchema ([ordered]@{items=(New-UID0002PAV4ArraySchema (New-UID0002PAV4ObjectSchema ([ordered]@{addr=$string;comment=$string}) @('addr','comment')) 1 64)}) @('items'))}) @('database','items')
    $schemas.set_address_comments=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;items=(New-UID0002PAV4ArraySchema (New-UID0002PAV4ObjectSchema ([ordered]@{addr=$string;channel=(New-UID0002PAV4ScalarSchema string $null $false @('regular','repeatable'));comment=$string}) @('addr','channel','comment')) 1 64)}) @('database','items')
    $schemas.idb_save=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;path=$string}) @('database','path')
    if($schemas.Count-ne19){throw 'SC4-PA literal schema count mismatch'};$schemas
}

function Assert-UID0002PAV4ExactKeys { param($Object,[string[]]$Keys,[string]$Label)
    if($null-eq$Object){throw "$Label null object"};$actual=@($Object.PSObject.Properties.Name|Sort-Object);$expected=@($Keys|Sort-Object);if(($actual-join'|')-cne($expected-join'|')){throw "$Label exact key mismatch actual=[$($actual-join',')] expected=[$($expected-join',')]"}
}
function Assert-UID0002PAV4NativeString {param($Value,[string]$Label)if($Value-isnot[string]){throw "$Label native string mismatch"}}
function Assert-UID0002PAV4NativeBoolean {param($Value,[string]$Label)if($Value-isnot[bool]){throw "$Label native Boolean mismatch"}}
function Assert-UID0002PAV4NativeInteger {param($Value,[string]$Label)if($Value-is[bool]-or$Value-isnot[int]-and$Value-isnot[long]){throw "$Label native integer mismatch"}}
function Assert-UID0002PAV4NativeArray {param($Value,[string]$Label)if($Value-isnot[System.Array]){throw "$Label native array mismatch"}}

function ConvertFrom-UID0002PAV4StrictJson { param([Parameter(Mandatory=$true)][string]$Raw,[string]$Label='JSON')
    Assert-UID0002PARawJsonUnique $Raw $Label
    try{$Raw|ConvertFrom-Json}catch{throw "$Label malformed JSON: $($_.Exception.Message)"}
}
function New-UID0002PAV4Request { param($Id,[string]$Tool,[Collections.IDictionary]$Arguments)
    if($Id-is[bool]-or($Id-isnot[string]-and$Id-isnot[int]-and$Id-isnot[long])){throw 'RQ4-PA non-native request id'}
    ([ordered]@{jsonrpc='2.0';id=$Id;method='tools/call';params=[ordered]@{name=$Tool;arguments=$Arguments}}|ConvertTo-Json -Depth 100 -Compress)
}
function New-UID0002PAV4ToolsListRequest {param($Id)([ordered]@{jsonrpc='2.0';id=$Id;method='tools/list';params=[ordered]@{}}|ConvertTo-Json -Compress)}

function Get-UID0002PAV4RequestIdentity { param([string]$Raw,[string]$Label)
    $o=ConvertFrom-UID0002PAV4StrictJson $Raw $Label;Assert-UID0002PAV4ExactKeys $o @('jsonrpc','id','method','params') $Label
    Assert-UID0002PAV4NativeString $o.jsonrpc "$Label jsonrpc";if($o.jsonrpc-cne'2.0'){throw "$Label jsonrpc mismatch"};if($o.id-is[bool]-or($o.id-isnot[string]-and$o.id-isnot[int]-and$o.id-isnot[long])){throw "$Label id type mismatch"};Assert-UID0002PAV4NativeString $o.method "$Label method"
    [pscustomobject]@{Parsed=$o;Id=$o.id;IdType=$o.id.GetType().FullName;SHA256=Get-UID0002PAV4TextSHA256 $Raw}
}

function Get-UID0002PAV4ToolContent { param([string]$RawResponse,[string]$Request,[string]$Label,[switch]$AllowError)
    $requestIdentity=Get-UID0002PAV4RequestIdentity $Request "$Label request";$response=ConvertFrom-UID0002PAV4StrictJson $RawResponse "$Label response"
    Assert-UID0002PAV4ExactKeys $response @('jsonrpc','id','result') "$Label response";Assert-UID0002PAV4NativeString $response.jsonrpc "$Label response jsonrpc";if($response.jsonrpc-cne'2.0'-or$response.id.GetType().FullName-cne$requestIdentity.IdType-or$response.id-ne$requestIdentity.Id){throw "$Label response correlation mismatch"}
    Assert-UID0002PAV4ExactKeys $response.result @('isError','structuredContent') "$Label result";Assert-UID0002PAV4NativeBoolean $response.result.isError "$Label isError";if(-not$AllowError-and$response.result.isError){throw "$Label tool error"};[pscustomobject]@{IsError=[bool]$response.result.isError;Content=$response.result.structuredContent;Response=$response}
}

function Get-UID0002PAV4TupleFromStream { param([IO.FileStream]$Stream,[string]$ExpectedPath)
    Initialize-UID0002PANativeSealedTypes;$old=[UID0002PANativeSealedCore]::ReadTuple($Stream,[IO.Path]::GetFullPath($ExpectedPath));[UID0002PAV4DiskTuple]::new($old.FullPath,$old.Length,$old.LastWriteTimeUtcTicks,$old.SHA256,$old.VolumeSerial,$old.FileIndex)
}
function Get-UID0002PAV4ExclusiveTuple { param([string]$Path)
    $stream=[IO.FileStream]::new([IO.Path]::GetFullPath($Path),[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);try{Get-UID0002PAV4TupleFromStream $stream $Path}finally{$stream.Dispose()}
}
function Assert-UID0002PAV4Tuple {param([UID0002PAV4DiskTuple]$Actual,[UID0002PAV4DiskTuple]$Expected,[string]$Label)if($null-eq$Actual-or-not$Actual.Same($Expected)){throw "$Label exact tuple mismatch"}}

function New-UID0002PAV4Backup { param([UID0002PAV4Core]$Core)
    $canonical=$Core.PSObject.Properties['CanonicalPath'];$canonicalPath=$null
    if($null-ne$canonical){$canonicalPath=[string]$canonical.Value}else{throw 'BK4-PA core canonical path unavailable'}
}

function New-UID0002PAV4Authority { param([Parameter(Mandatory=$true)][string]$CanonicalPath,[Parameter(Mandatory=$true)][string]$SourceRoot,[Parameter(Mandatory=$true)][scriptblock]$Transport,[Parameter(Mandatory=$true)][scriptblock]$RetireExactGeneration)
    Initialize-UID0002PAV4SealedTypes;if($null-eq$Transport){throw 'CT4-PA transport adapter required'};if($null-eq$RetireExactGeneration){throw 'CT4-PA retirement adapter required'};[UID0002PAV4Authority]::new($CanonicalPath,$SourceRoot,$Transport.GetNewClosure(),$RetireExactGeneration.GetNewClosure())
}

function Get-UID0002PAV4ModuleProof { param($Process,[string]$SourceRoot,[string]$Label)
    Assert-UID0002PAV4ExactKeys $Process @('pid','generation','modules','implementation_manifest_sha256') "$Label process";Assert-UID0002PAV4NativeInteger $Process.pid "$Label pid";Assert-UID0002PAV4NativeString $Process.generation "$Label generation";Assert-UID0002PAV4NativeArray $Process.modules "$Label modules"
    $root=[IO.Path]::GetFullPath($SourceRoot).TrimEnd('\')+'\';$stable=@();$processRows=@();$moduleIds=New-Object 'Collections.Generic.HashSet[string]' ([StringComparer]::Ordinal)
    foreach($row in @($Process.modules)){
        Assert-UID0002PAV4ExactKeys $row @('module_id','file','spec_origin','resolved_path','size','last_write_time_utc_ticks','sha256') "$Label module";foreach($name in @('module_id','file','spec_origin','resolved_path','sha256')){Assert-UID0002PAV4NativeString $row.$name "$Label $name"};Assert-UID0002PAV4NativeInteger $row.size "$Label size";Assert-UID0002PAV4NativeInteger $row.last_write_time_utc_ticks "$Label ticks";if(-not$moduleIds.Add([string]$row.module_id)){throw "$Label duplicate process-local module_id"}
        $resolved=[IO.Path]::GetFullPath([string]$row.resolved_path);if(-not$resolved.StartsWith($root,[StringComparison]::OrdinalIgnoreCase)){throw "$Label module outside bound source root"};$info=Get-Item -LiteralPath $resolved -ErrorAction Stop;$hash=(Get-FileHash -Algorithm SHA256 -LiteralPath $resolved).Hash
        if([long]$row.size-ne[long]$info.Length-or[long]$row.last_write_time_utc_ticks-ne[long]$info.LastWriteTimeUtc.Ticks-or[string]$row.sha256-cne$hash){throw "MD4-PA module manifest drift"}
        $stable+=[ordered]@{file=[string]$row.file;spec_origin=[string]$row.spec_origin;resolved_path=$resolved;size=[long]$info.Length;last_write_time_utc_ticks=[long]$info.LastWriteTimeUtc.Ticks;sha256=$hash}
        $processRows+=[ordered]@{module_id=[string]$row.module_id;stable=$stable[-1]}
    }
    $stableJson=ConvertTo-UID0002PAV4CanonicalNode @($stable|Sort-Object resolved_path);$stableSha=Get-UID0002PAV4TextSHA256 $stableJson;$processSha=Get-UID0002PAV4TextSHA256 (ConvertTo-UID0002PAV4CanonicalNode @($processRows|Sort-Object{$_.stable.resolved_path}))
    Assert-UID0002PAV4NativeString $Process.implementation_manifest_sha256 "$Label implementation digest";if([string]$Process.implementation_manifest_sha256-cne$stableSha){throw 'MD4-PA aggregate implementation manifest mismatch'}
    [pscustomobject]@{StableSHA256=$stableSha;ProcessSHA256=$processSha}
}

function New-UID0002PAV4FixtureResponse { param($Request,$Content,[bool]$IsError=$false)
    $id=(Get-UID0002PAV4RequestIdentity $Request 'fixture response request').Id;([ordered]@{jsonrpc='2.0';id=$id;result=[ordered]@{isError=$IsError;structuredContent=$Content}}|ConvertTo-Json -Depth 100 -Compress)
}
function New-UID0002PAV4FixtureToolsResponse { param($Request,$Schemas)
    $id=(Get-UID0002PAV4RequestIdentity $Request 'fixture tools request').Id;$tools=@();foreach($name in @($Schemas.Keys|Sort-Object)){$tools+=[ordered]@{name=$name;inputSchema=$Schemas[$name]}};([ordered]@{jsonrpc='2.0';id=$id;result=[ordered]@{tools=$tools}}|ConvertTo-Json -Depth 100 -Compress)
}

function Get-UID0002PAV4RoleFromEvidence { param([string]$RoleName,[string]$SessionId,[string]$CanonicalPath,$List,$Runtime,[string]$SourceRoot)
    Assert-UID0002PAV4NativeInteger $Runtime.schema_version 'RT4-PA runtime schema_version';if($Runtime.schema_version-ne1){throw 'RT4-PA runtime schema mismatch'};Assert-UID0002PAV4NativeBoolean $Runtime.ok 'RT4-PA runtime ok';if(-not$Runtime.ok){throw 'RT4-PA runtime not ok'};Assert-UID0002PAV4NativeArray $Runtime.errors 'RT4-PA runtime errors';if(@($Runtime.errors).Count-ne0){throw 'RT4-PA runtime errors nonempty'}
    Assert-UID0002PAV4NativeArray $List.sessions 'RT4-PA list sessions';$row=@($List.sessions|Where-Object{[string]$_.session_id-ceq$SessionId});if($row.Count-ne1){throw 'RT4-PA exact returned session absent'};$row=$row[0]
    foreach($field in @('session_id','input_path','redirector_generation','worker_generation','endpoint')){Assert-UID0002PAV4NativeString $row.$field "RT4-PA list $field"};foreach($field in @('is_active','owned')){Assert-UID0002PAV4NativeBoolean $row.$field "RT4-PA list $field"};foreach($field in @('redirector_pid','worker_pid','route_port','socket_owner_pid')){Assert-UID0002PAV4NativeInteger $row.$field "RT4-PA list $field"}
    if(-not$row.is_active-or-not$row.owned-or[IO.Path]::GetFullPath([string]$row.input_path)-ine[IO.Path]::GetFullPath($CanonicalPath)){throw 'RT4-PA list identity mismatch'}
    Assert-UID0002PAV4NativeArray $Runtime.workers 'RT4-PA workers';$worker=@($Runtime.workers|Where-Object{[int]$_.process.pid-eq[int]$row.worker_pid});if($worker.Count-ne1){throw 'RT4-PA worker route mismatch'};$worker=$worker[0]
    Assert-UID0002PAV4ExactKeys $worker @('ok','errors','nonce','route','process','supervisor_sessions') 'RT4-PA worker';Assert-UID0002PAV4NativeBoolean $worker.ok 'RT4-PA worker ok';if(-not$worker.ok){throw 'RT4-PA worker not ok'};Assert-UID0002PAV4NativeArray $worker.errors 'RT4-PA worker errors';if(@($worker.errors).Count-ne0){throw 'RT4-PA worker errors nonempty'};Assert-UID0002PAV4NativeString $worker.nonce 'RT4-PA worker nonce'
    $sessions=@($worker.supervisor_sessions|Where-Object{[string]$_.session_id-ceq$SessionId});if($sessions.Count-ne1){throw 'RT4-PA supervisor session mismatch'};$session=$sessions[0];Assert-UID0002PAV4ExactKeys $session @('session_id','canonical_path','owned','redirector_pid','redirector_generation','route_port','endpoint','socket_owner_pid') 'RT4-PA supervisor session'
    $module=Get-UID0002PAV4ModuleProof $worker.process $SourceRoot 'RT4-PA worker';$authorityText=ConvertTo-UID0002PAV4CanonicalNode ([ordered]@{role=$RoleName;session=$SessionId;path=[IO.Path]::GetFullPath($CanonicalPath);redirector_pid=[int]$row.redirector_pid;redirector_generation=[string]$row.redirector_generation;worker_pid=[int]$row.worker_pid;worker_generation=[string]$row.worker_generation;route_port=[int]$row.route_port;endpoint=[string]$row.endpoint;socket_owner_pid=[int]$row.socket_owner_pid;nonce=[string]$worker.nonce;stable_manifest=$module.StableSHA256;process_manifest=$module.ProcessSHA256})
    [UID0002PAV4Role]::new($RoleName,$SessionId,$CanonicalPath,[int]$row.redirector_pid,[string]$row.redirector_generation,[int]$row.worker_pid,[string]$row.worker_generation,[int]$row.route_port,[string]$row.endpoint,[int]$row.socket_owner_pid,[string]$worker.nonce,$module.StableSHA256,$module.ProcessSHA256,(Get-UID0002PAV4TextSHA256 $authorityText))
}

function Test-UID0002PAV4ProcessGenerationAbsentOrReused { param([int]$Pid,[string]$Generation)
    try{$p=[Diagnostics.Process]::GetProcessById($Pid);try{$actual="pid:$Pid;started:$($p.StartTime.ToUniversalTime().Ticks)";return $actual-cne$Generation}finally{$p.Dispose()}}catch{return $true}
}
function Test-UID0002PAV4SocketAbsent {param([int]$Port)$listeners=[Net.NetworkInformation.IPGlobalProperties]::GetIPGlobalProperties().GetActiveTcpListeners();return @($listeners|Where-Object{$_.Port-eq$Port}).Count-eq0}

function Invoke-UID0002PAClosedTransaction {
    param([UID0002PAV4Authority]$Authority)
    if($args.Count-ne0){throw 'CT4-PA extra positional authority rejected'};if($null-eq$Authority){throw 'CT4-PA sealed authority required'}
    Initialize-UID0002PAV4SealedTypes;Initialize-UID0002PANativeSealedTypes
    $core=$null;$backup=$null;$transactionRole=$null;$schemasValidated=$false;$saveObservation=$null;$canonical=$Authority.CanonicalPath;$backupPath=$canonical+'.uid0002pa-v4.backup';$tx=[Guid]::NewGuid().ToString('N')
    $schemas=Get-UID0002PAV4LiteralSchemas;$schemasJson=ConvertTo-UID0002PAV4CanonicalNode $schemas;$planRows=@(Get-UID0002PAConfigOracle);if($planRows.Count-ne51){throw 'PL4-PA Config plan cardinality mismatch'}
    $plan=[ordered]@{config=@($planRows);mutations=@('I01','I02Dry','I02','I03','I04','I05');phases=@('Pre','AfterI01','AfterI02','AfterI03','AfterI04','AfterI05','Final','P0Verifier','S1Verifier','RollbackVerifier')};$planJson=ConvertTo-UID0002PAV4CanonicalNode $plan
    try{
        $core=[UID0002PAV4Core]::new($Authority,$tx);$core.FreezePackage($schemasJson,$planJson)
        $source=[IO.FileStream]::new($canonical,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);$destination=$null
        try{
            $p0=Get-UID0002PAV4TupleFromStream $source $canonical;$destination=[IO.FileStream]::new($backupPath,[IO.FileMode]::CreateNew,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None);$buffer=New-Object byte[] 1048576;$copied=[long]0
            while(($read=$source.Read($buffer,0,$buffer.Length))-gt0){$destination.Write($buffer,0,$read);$copied+=$read};if($copied-ne$p0.Length-or$source.Position-ne$p0.Length-or$source.ReadByte()-ne-1-or$destination.Length-ne$p0.Length){throw 'BK4-PA counted copy/EOF mismatch'};$destination.Flush($true);[UID0002PANativeSealedCore]::SetWriteTicks($destination,$p0.LastWriteTimeUtcTicks);$heldB0=Get-UID0002PAV4TupleFromStream $destination $backupPath
        }finally{if($null-ne$destination){$destination.Dispose()};$source.Dispose()}
        $b0=Get-UID0002PAV4ExclusiveTuple $backupPath;if(-not$b0.Same($heldB0)){throw 'BK4-PA closed B0 changed'};$core.SetBackup($p0,$b0);Assert-UID0002PAV4Tuple (Get-UID0002PAV4ExclusiveTuple $canonical) $p0 'BK4-PA unchanged P0'

        $sendReadOnly={
            param([string]$request,[string]$label)
            $identity=Get-UID0002PAV4RequestIdentity $request $label;if($identity.Parsed.method-ceq'tools/call'-and[string]$identity.Parsed.params.name-ceq'idb_save'){throw 'SV4-PA read-only path cannot dispatch save'}
            $raw=[string]$core.Send($request);if([string]::IsNullOrWhiteSpace($raw)){throw "$label empty response"};$raw
        }.GetNewClosure()
        $toolsRequest=New-UID0002PAV4ToolsListRequest 'uid0002pa-v4-tools';$toolsRaw=&$sendReadOnly $toolsRequest 'SC4-PA tools/list';$toolsIdentity=Get-UID0002PAV4RequestIdentity $toolsRequest 'SC4-PA tools request';$toolsResponse=ConvertFrom-UID0002PAV4StrictJson $toolsRaw 'SC4-PA tools response';Assert-UID0002PAV4ExactKeys $toolsResponse @('jsonrpc','id','result') 'SC4-PA tools response';if($toolsResponse.id-ne$toolsIdentity.Id-or$toolsResponse.id.GetType().FullName-cne$toolsIdentity.IdType){throw 'SC4-PA tools response correlation mismatch'};Assert-UID0002PAV4ExactKeys $toolsResponse.result @('tools') 'SC4-PA tools result';Assert-UID0002PAV4NativeArray $toolsResponse.result.tools 'SC4-PA tools'
        $actualSchemas=[ordered]@{};foreach($tool in @($toolsResponse.result.tools)){Assert-UID0002PAV4ExactKeys $tool @('name','inputSchema') 'SC4-PA tool row';Assert-UID0002PAV4NativeString $tool.name 'SC4-PA tool name';if($actualSchemas.Contains([string]$tool.name)){throw 'SC4-PA duplicate tool'};$actualSchemas[[string]$tool.name]=$tool.inputSchema}
        if((@($actualSchemas.Keys|Sort-Object)-join'|')-cne(@($schemas.Keys|Sort-Object)-join'|')){throw 'SC4-PA used-tool set mismatch'};foreach($name in @($schemas.Keys)){if((ConvertTo-UID0002PAV4CanonicalNode $actualSchemas[$name])-cne(ConvertTo-UID0002PAV4CanonicalNode $schemas[$name])){throw "SC4-PA literal recursive schema drift: $name"}};$schemasValidated=$true

        $openRole={
            param([string]$role)
            $preferred=('uid0002pa-v4-'+$role.ToLowerInvariant()+'-'+[Guid]::NewGuid().ToString('N'));$core.RegisterOpenReceipt($role,$preferred,$null)
            $openRequest=New-UID0002PAV4Request ("uid0002pa-v4-open-$role-$([Guid]::NewGuid().ToString('N'))") 'idb_open' ([ordered]@{input_path=$canonical;mode='force_headless';run_auto_analysis=$false;build_caches=$false;init_hexrays=$false;idle_ttl_sec=600;preferred_session_id=$preferred})
            $openRaw=&$sendReadOnly $openRequest "OP4-PA $role open";$open=Get-UID0002PAV4ToolContent $openRaw $openRequest "OP4-PA $role open";Assert-UID0002PAV4ExactKeys $open.Content @('success','error','session') "OP4-PA $role content";Assert-UID0002PAV4NativeBoolean $open.Content.success "OP4-PA $role success";Assert-UID0002PAV4NativeString $open.Content.error "OP4-PA $role error";Assert-UID0002PAV4ExactKeys $open.Content.session @('session_id','input_path','is_analyzing') "OP4-PA $role session"
            foreach($field in @('session_id','input_path')){Assert-UID0002PAV4NativeString $open.Content.session.$field "OP4-PA $role $field"};Assert-UID0002PAV4NativeBoolean $open.Content.session.is_analyzing "OP4-PA $role is_analyzing";if(-not$open.Content.success-or$open.Content.error-cne''-or$open.Content.session.is_analyzing-or[IO.Path]::GetFullPath([string]$open.Content.session.input_path)-ine$canonical){throw "OP4-PA $role open result mismatch"}
            $session=[string]$open.Content.session.session_id;$core.RegisterOpenReceipt($role,$preferred,$session)
            $listRequest=New-UID0002PAV4Request ("uid0002pa-v4-open-list-$role") 'idb_list' ([ordered]@{});$list=(Get-UID0002PAV4ToolContent (&$sendReadOnly $listRequest "OP4-PA $role list") $listRequest "OP4-PA $role list").Content
            $runtimeRequest=New-UID0002PAV4Request ("uid0002pa-v4-open-runtime-$role") 'runtime_attestation' ([ordered]@{expected_database=$session;expected_canonical_path=$canonical});$runtime=(Get-UID0002PAV4ToolContent (&$sendReadOnly $runtimeRequest "OP4-PA $role runtime") $runtimeRequest "OP4-PA $role runtime").Content
            $roleObject=Get-UID0002PAV4RoleFromEvidence $role $session $canonical $list $runtime $Authority.SourceRoot;$core.FreezeRole($roleObject);$roleObject
        }.GetNewClosure()

        $closeRole={
            param([UID0002PAV4Role]$role)
            $core.AssertRole($role);$action=[ordered]@{action='RETIRE_EXACT_GENERATION';role=$role.RoleName;session_id=$role.SessionId;canonical_path=$role.CanonicalPath;redirector_pid=$role.RedirectorPid;redirector_generation=$role.RedirectorGeneration;worker_pid=$role.WorkerPid;worker_generation=$role.WorkerGeneration;route_port=$role.RoutePort;endpoint=$role.Endpoint;socket_owner_pid=$role.SocketOwnerPid;nonce=$role.Nonce;stable_manifest_sha256=$role.StableManifestSHA256;process_manifest_sha256=$role.ProcessManifestSHA256;preserve_listener=$true}
            $raw=[string]$core.Retire((ConvertTo-UID0002PAV4CanonicalNode $action));$result=ConvertFrom-UID0002PAV4StrictJson $raw 'RR4-PA retirement result';Assert-UID0002PAV4ExactKeys $result @('action','role','session_id','canonical_path','redirector_pid','redirector_generation','worker_pid','worker_generation','route_port','endpoint','socket_owner_pid','nonce','stable_manifest_sha256','process_manifest_sha256','retired','listener_preserved') 'RR4-PA retirement result'
            foreach($field in @('action','role','session_id','canonical_path','redirector_generation','worker_generation','endpoint','nonce','stable_manifest_sha256','process_manifest_sha256')){Assert-UID0002PAV4NativeString $result.$field "RR4-PA $field"};foreach($field in @('redirector_pid','worker_pid','route_port','socket_owner_pid')){Assert-UID0002PAV4NativeInteger $result.$field "RR4-PA $field"};foreach($field in @('retired','listener_preserved')){Assert-UID0002PAV4NativeBoolean $result.$field "RR4-PA $field"}
            $expected=ConvertTo-UID0002PAV4CanonicalNode ([ordered]@{action=$action.action;role=$action.role;session_id=$action.session_id;canonical_path=$action.canonical_path;redirector_pid=$action.redirector_pid;redirector_generation=$action.redirector_generation;worker_pid=$action.worker_pid;worker_generation=$action.worker_generation;route_port=$action.route_port;endpoint=$action.endpoint;socket_owner_pid=$action.socket_owner_pid;nonce=$action.nonce;stable_manifest_sha256=$action.stable_manifest_sha256;process_manifest_sha256=$action.process_manifest_sha256;retired=$true;listener_preserved=$true});if((ConvertTo-UID0002PAV4CanonicalNode $result)-cne$expected){throw 'RR4-PA sealed retirement result mismatch'}
            if(-not(Test-UID0002PAV4ProcessGenerationAbsentOrReused $role.RedirectorPid $role.RedirectorGeneration)-or-not(Test-UID0002PAV4ProcessGenerationAbsentOrReused $role.WorkerPid $role.WorkerGeneration)-or-not(Test-UID0002PAV4SocketAbsent $role.RoutePort)){throw 'RR4-PA independent process/socket absence failed'}
            $listRequest=New-UID0002PAV4Request ("uid0002pa-v4-post-list-$($role.RoleName)") 'idb_list' ([ordered]@{});$list=(Get-UID0002PAV4ToolContent (&$sendReadOnly $listRequest 'RR4-PA post list') $listRequest 'RR4-PA post list').Content;Assert-UID0002PAV4NativeArray $list.sessions 'RR4-PA post sessions';$rows=@($list.sessions|Where-Object{[string]$_.session_id-ceq$role.SessionId});if($rows.Count-gt1-or($rows.Count-eq1-and($rows[0].is_active-isnot[bool]-or$rows[0].is_active-ne$false-or[IO.Path]::GetFullPath([string]$rows[0].input_path)-ine$role.CanonicalPath))){throw 'RR4-PA retired session remains active/mismatched'}
            $runtimeRequest=New-UID0002PAV4Request ("uid0002pa-v4-post-runtime-$($role.RoleName)") 'runtime_attestation' ([ordered]@{expected_database=$null;expected_canonical_path=$canonical});$runtime=(Get-UID0002PAV4ToolContent (&$sendReadOnly $runtimeRequest 'RR4-PA post runtime') $runtimeRequest 'RR4-PA post runtime').Content;Assert-UID0002PAV4NativeBoolean $runtime.ok 'RR4-PA post runtime ok';if(-not$runtime.ok){throw 'RR4-PA post runtime failed'};$true
        }.GetNewClosure()

        $catalog={
            param([UID0002PAV4Role]$role,[string]$phase)
            $semanticFailures=@();foreach($row in $planRows){$request=New-UID0002PAV4Request ("uid0002pa-v4-$phase-$($row.name)") 'entity_query' ([ordered]@{database=$role.SessionId;queries=@([ordered]@{kind='names';pattern=('^'+[regex]::Escape([string]$row.name)+'$');offset=0;limit=1})});$content=(Get-UID0002PAV4ToolContent (&$sendReadOnly $request "PL4-PA $phase $($row.name)") $request "PL4-PA $phase $($row.name)").Content;Assert-UID0002PAV4ExactKeys $content @('ok','phase','row','row_sha256','semantic_mismatch') "PL4-PA $phase row";Assert-UID0002PAV4NativeBoolean $content.ok "PL4-PA $phase ok";foreach($field in @('phase','row','row_sha256','semantic_mismatch')){Assert-UID0002PAV4NativeString $content.$field "PL4-PA $phase $field"};$expectedSha=Get-UID0002PAV4TextSHA256 (ConvertTo-UID0002PAV4CanonicalNode $row);if([string]$content.phase-cne$phase-or[string]$content.row-cne[string]$row.name-or[string]$content.row_sha256-cne$expectedSha){throw "PL4-PA $phase literal row mismatch"};if(-not$content.ok-or-not[string]::IsNullOrEmpty([string]$content.semantic_mismatch)){$semanticFailures+=[string]$content.semantic_mismatch}}
            [pscustomobject]@{Passed=$semanticFailures.Count-eq0;Failures=@($semanticFailures);RowCount=51}
        }.GetNewClosure()

        $transactionRole=&$openRole 'Transaction';$null=&$catalog $transactionRole 'Pre'
        $mutations=[ordered]@{
            I01=@('declare_type',[ordered]@{database=$transactionRole.SessionId;decls=@([ordered]@{decl='struct ServerSelectEntry; struct ServerSelectDirectory;';kind='c'})})
            I02Dry=@('entity_query',[ordered]@{database=$transactionRole.SessionId;queries=@([ordered]@{kind='names';pattern='^ServerSelectDirectory__ReleaseOwnedBuffers$';offset=0;limit=1})})
            I02=@('rename',[ordered]@{database=$transactionRole.SessionId;batch=[ordered]@{functions=@([ordered]@{addr='0x494130';name='ServerSelectDirectory__ReleaseOwnedBuffers'});globals=@();types=@()}})
            I03=@('set_type',[ordered]@{database=$transactionRole.SessionId;edits=[ordered]@{functions=@([ordered]@{addr='0x494130';type='void __thiscall(ServerSelectDirectory *this)'});globals=@()}})
            I04=@('set_function_comments',[ordered]@{database=$transactionRole.SessionId;items=[ordered]@{items=@([ordered]@{addr='0x494130';comment='Releases the three owned wide-string fields for every active server-directory entry and resets entryCount/version.'})}})
            I05=@('set_address_comments',[ordered]@{database=$transactionRole.SessionId;items=@([ordered]@{addr='0x494146';channel='regular';comment='ServerSelectEntry stride is 0x18 bytes.'})})
        }
        foreach($name in @($mutations.Keys)){$entry=$mutations[$name];$request=New-UID0002PAV4Request ("uid0002pa-v4-$name") ([string]$entry[0]) $entry[1];$content=(Get-UID0002PAV4ToolContent (&$sendReadOnly $request "MU4-PA $name") $request "MU4-PA $name").Content;Assert-UID0002PAV4ExactKeys $content @('ok','operation') "MU4-PA $name result";Assert-UID0002PAV4NativeBoolean $content.ok "MU4-PA $name ok";Assert-UID0002PAV4NativeString $content.operation "MU4-PA $name operation";if(-not$content.ok-or$content.operation-cne$name){throw "MU4-PA $name semantic failure"};if($name-cne'I02Dry'){$null=&$catalog $transactionRole ("After$name")}}
        $final=&$catalog $transactionRole 'Final';if(-not$final.Passed){throw 'PL4-PA pre-save Final mismatch'}

        $core.AssertPackage($schemasJson,$planJson);$listRequest=New-UID0002PAV4Request 'uid0002pa-v4-presave-list' 'idb_list' ([ordered]@{});$preList=(Get-UID0002PAV4ToolContent (&$sendReadOnly $listRequest 'SV4-PA immediate list') $listRequest 'SV4-PA immediate list').Content
        $runtimeRequest=New-UID0002PAV4Request 'uid0002pa-v4-presave-runtime' 'runtime_attestation' ([ordered]@{expected_database=$transactionRole.SessionId;expected_canonical_path=$canonical});$preRuntime=(Get-UID0002PAV4ToolContent (&$sendReadOnly $runtimeRequest 'SV4-PA immediate runtime') $runtimeRequest 'SV4-PA immediate runtime').Content
        $preSaveRole=Get-UID0002PAV4RoleFromEvidence 'Transaction' $transactionRole.SessionId $canonical $preList $preRuntime $Authority.SourceRoot;$core.AssertRole($preSaveRole)
        $saveRequest=New-UID0002PAV4Request 'uid0002pa-v4-sole-save' 'idb_save' ([ordered]@{database=$transactionRole.SessionId;path=$canonical});$core.ClaimSave();$saveClass='Indeterminate';$saveRaw=$null;$saveError=$null
        try{$saveRaw=[string]$core.Send($saveRequest);if(-not[string]::IsNullOrWhiteSpace($saveRaw)){$saveResult=Get-UID0002PAV4ToolContent $saveRaw $saveRequest 'SV4-PA save' -AllowError;if(-not$saveResult.IsError-and$saveResult.Content.saved-is[bool]-and$saveResult.Content.saved-eq$true){$saveClass='DeterminateSuccess'}elseif($saveResult.IsError){$saveClass='DeterminateFailure'}}}catch{$saveError=$_.Exception.Message;if($saveError-like'*TIMEOUT*'){$saveClass='Timeout'}elseif($saveError-like'*DISCONNECT*'){$saveClass='Disconnected'}else{$saveClass='Thrown'}}finally{$stream=[IO.FileStream]::new($canonical,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::ReadWrite-bor[IO.FileShare]::Delete);try{$core.RecordDopen((Get-UID0002PAV4TupleFromStream $stream $canonical))}finally{$stream.Dispose()}}
        $null=&$closeRole $transactionRole;$transactionRole=$null;$dclosed=Get-UID0002PAV4ExclusiveTuple $canonical;$core.RecordDclosed($dclosed)
        $sameP0=$dclosed.Same($core.P0);$timestampOnly=$dclosed.SameContent($core.P0)-and-not$sameP0
        if($timestampOnly){throw 'DS4-PA timestamp-only identity refused'}
        if($sameP0){$verifier=&$openRole 'P0Verifier';$vr=&$catalog $verifier 'P0Verifier';$null=&$closeRole $verifier;if(-not$vr.Passed){throw 'VR4-PA P0 verifier failed'};Assert-UID0002PAV4Tuple (Get-UID0002PAV4ExclusiveTuple $canonical) $core.P0 'VR4-PA P0 disk';$core.CompleteTerminal("P0_VERIFIED_$saveClass");return [pscustomobject]@{Status="P0_VERIFIED_$saveClass";SaveDispatchCount=$core.SaveDispatchCount;TransportCalls=$core.TransportCalls;RetireCalls=$core.RetireCalls;RestoreWrites=$core.RestoreWrites;DopenCaptured=$null-ne$core.Dopen;Dclosed=$core.Dclosed;P1=$null;JournalRetained=$false}}
        if($saveClass-cne'DeterminateSuccess'){throw "DS4-PA changed output lacks determinate sole-save authority: $saveClass"};$core.SetP1();$verifier=&$openRole 'S1Verifier';$vr=&$catalog $verifier 'S1Verifier';$null=&$closeRole $verifier
        if($vr.Passed){$core.CompleteTerminal('P1_VERIFIED');return [pscustomobject]@{Status='P1_VERIFIED';SaveDispatchCount=$core.SaveDispatchCount;TransportCalls=$core.TransportCalls;RetireCalls=$core.RetireCalls;RestoreWrites=$core.RestoreWrites;DopenCaptured=$true;Dclosed=$core.Dclosed;P1=$core.P1;JournalRetained=$false}}
        if($vr.Failures.Count-ne1-or-not([string]$vr.Failures[0]).StartsWith('FINAL_ORACLE_MISMATCH:')){throw 'VR4-PA non-literal Final mismatch cannot authorize restore'}
        $source=[IO.FileStream]::new($backupPath,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);$destination=[IO.FileStream]::new($canonical,[IO.FileMode]::Open,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None)
        try{$heldSource=Get-UID0002PAV4TupleFromStream $source $backupPath;$heldDestination=Get-UID0002PAV4TupleFromStream $destination $canonical;$core.AuthorizeRestore($heldDestination,$heldSource);$source.Position=0;$destination.SetLength(0);$destination.Position=0;$buffer=New-Object byte[] 1048576;$copied=[long]0;while(($read=$source.Read($buffer,0,$buffer.Length))-gt0){$destination.Write($buffer,0,$read);$copied+=$read};if($copied-ne$core.P0.Length-or$source.Position-ne$core.P0.Length-or$source.ReadByte()-ne-1-or$destination.Length-ne$core.P0.Length){throw 'RS4-PA counted restore/EOF mismatch'};$destination.Flush($true);[UID0002PANativeSealedCore]::SetWriteTicks($destination,$core.P0.LastWriteTimeUtcTicks);Assert-UID0002PAV4Tuple (Get-UID0002PAV4TupleFromStream $destination $canonical) $core.P0 'RS4-PA held restored P0'}finally{$destination.Dispose();$source.Dispose()}
        Assert-UID0002PAV4Tuple (Get-UID0002PAV4ExclusiveTuple $canonical) $core.P0 'RS4-PA closed restored P0 first';Assert-UID0002PAV4Tuple (Get-UID0002PAV4ExclusiveTuple $canonical) $core.P0 'RS4-PA closed restored P0 second';$rollback=&$openRole 'RollbackVerifier';$rb=&$catalog $rollback 'RollbackVerifier';$null=&$closeRole $rollback;if(-not$rb.Passed){throw 'RS4-PA rollback verifier failed'};$core.CompleteTerminal('RESTORED_P0_VERIFIED');[pscustomobject]@{Status='RESTORED_P0_VERIFIED';SaveDispatchCount=$core.SaveDispatchCount;TransportCalls=$core.TransportCalls;RetireCalls=$core.RetireCalls;RestoreWrites=$core.RestoreWrites;DopenCaptured=$true;Dclosed=$core.Dclosed;P1=$core.P1;JournalRetained=$false}
    }catch{
        $caught=$_.Exception
        if($null-ne$core-and$core.SaveDispatchCount-eq0-and$schemasValidated){
            try{if($null-ne$transactionRole){$null=&$closeRole $transactionRole;$transactionRole=$null};Assert-UID0002PAV4Tuple (Get-UID0002PAV4ExclusiveTuple $canonical) $core.P0 'NS4-PA P0';Assert-UID0002PAV4Tuple (Get-UID0002PAV4ExclusiveTuple $backupPath) $core.B0 'NS4-PA B0';$verifier=&$openRole 'P0Verifier';$vr=&$catalog $verifier 'P0Verifier';$null=&$closeRole $verifier;if(-not$vr.Passed){throw 'NS4-PA P0 verifier failed'};$core.CompleteNoSave();return [pscustomobject]@{Status='COMPLETE_NO_SAVE';Cause=$caught.Message;SaveDispatchCount=0;TransportCalls=$core.TransportCalls;RetireCalls=$core.RetireCalls;RestoreWrites=0;DopenCaptured=$false;JournalRetained=$false}}catch{$caught=$_.Exception}
        }
        if($null-ne$core){throw $core.Failure($caught.Message,$caught)};throw
    }finally{
        if($null-ne$core){$wasComplete=$core.Complete;$core.Dispose();if($wasComplete-and[IO.File]::Exists($backupPath)){[IO.File]::Delete($backupPath)}}
    }
}

function New-UID0002PAV4FixtureEnvironment { param([string]$Case)
    $root=Join-Path ([IO.Path]::GetTempPath()) ('uid0002pa-v4-'+[Guid]::NewGuid().ToString('N'));$sourceRoot=Join-Path $root 'source';$null=New-Item -ItemType Directory -Path $sourceRoot -Force;$canonical=Join-Path $root 'fixture.i64';[IO.File]::WriteAllBytes($canonical,[byte[]](1,2,3,4,5,6,7,8));$moduleA=Join-Path $sourceRoot 'listener.py';$moduleB=Join-Path $sourceRoot 'worker.py';[IO.File]::WriteAllText($moduleA,'listener-v4',[Text.UTF8Encoding]::new($false));[IO.File]::WriteAllText($moduleB,'worker-v4',[Text.UTF8Encoding]::new($false));$activePorts=@([Net.NetworkInformation.IPGlobalProperties]::GetIPGlobalProperties().GetActiveTcpListeners()|ForEach-Object{$_.Port});$port=65530;while($activePorts-contains$port){$port--}
    [hashtable]@{Case=$Case;Root=$root;SourceRoot=$sourceRoot;Canonical=$canonical;Schemas=Get-UID0002PAV4LiteralSchemas;Roles=[ordered]@{};TransportCalls=0;RetireCalls=0;SaveCalls=0;RestoreObserved=0;Port=$port;ModuleA=$moduleA;ModuleB=$moduleB;ModuleMutated=$false;CatalogFailureInjected=$false;BaselineHash=(Get-FileHash -Algorithm SHA256 -LiteralPath $canonical).Hash}
}

function Get-UID0002PAV4FixtureModuleRows {param($State,[string]$Role)
    $rows=@();$index=0;foreach($path in @($State.ModuleA,$State.ModuleB)){$info=Get-Item -LiteralPath $path;$rows+=[ordered]@{module_id="$Role-$index";file=$info.Name;spec_origin='uid0002pa-fixture';resolved_path=$info.FullName;size=[long]$info.Length;last_write_time_utc_ticks=[long]$info.LastWriteTimeUtc.Ticks;sha256=(Get-FileHash -Algorithm SHA256 -LiteralPath $path).Hash};$index++};$stable=@();foreach($row in $rows){$stable+=[ordered]@{file=$row.file;spec_origin=$row.spec_origin;resolved_path=[IO.Path]::GetFullPath($row.resolved_path);size=$row.size;last_write_time_utc_ticks=$row.last_write_time_utc_ticks;sha256=$row.sha256}};$digest=Get-UID0002PAV4TextSHA256 (ConvertTo-UID0002PAV4CanonicalNode @($stable|Sort-Object resolved_path));[pscustomobject]@{Rows=$rows;Digest=$digest}
}

function New-UID0002PAV4FixtureAdapters { param($State)
    $transport={
        param([string]$request);$State.TransportCalls++;$identity=Get-UID0002PAV4RequestIdentity $request 'FX4-PA transport request';$o=$identity.Parsed
        if($o.method-ceq'tools/list'){$schemas=$State.Schemas;if($State.Case-ceq'NestedSchemaDrift'){$clone=($schemas|ConvertTo-Json -Depth 100|ConvertFrom-Json);$clone.idb_open.properties.idle_ttl_sec.type='string';$map=[ordered]@{};foreach($p in $clone.PSObject.Properties){$map[$p.Name]=$p.Value};$schemas=$map};return New-UID0002PAV4FixtureToolsResponse $request $schemas}
        $tool=[string]$o.params.name;$args=$o.params.arguments
        if($tool-ceq'idb_open'){
            $preferred=[string]$args.preferred_session_id;$role=if($preferred-match'uid0002pa-v4-([a-z0-9]+)-'){$Matches[1]}else{'unknown'};if($role-ceq'transaction'){$role='Transaction'}elseif($role-ceq'p0verifier'){$role='P0Verifier'}elseif($role-ceq's1verifier'){$role='S1Verifier'}elseif($role-ceq'rollbackverifier'){$role='RollbackVerifier'}
            if($State.Case-ceq'SetupFailure'-and$role-ceq'Transaction'){throw 'OP4-PA injected setup failure'}
            $session=if($State.Case-ceq'ReturnedSessionDiffersPreferredCleanup'-and$role-ceq'Transaction'){$preferred+'-returned'}else{$preferred};$index=$State.Roles.Count;$worker=2147483000+$index;$redirector=2147483100+$index;$record=[ordered]@{Role=$role;Session=$session;Path=[IO.Path]::GetFullPath([string]$args.input_path);Active=$true;WorkerPid=$worker;RedirectorPid=$redirector;WorkerGeneration="pid:$worker;started:1";RedirectorGeneration="pid:$redirector;started:1";Port=[int]($State.Port-$index);Endpoint="127.0.0.1:$($State.Port-$index)";Nonce="nonce-$session"};$State.Roles[$session]=$record
            return New-UID0002PAV4FixtureResponse $request ([ordered]@{success=$true;error='';session=[ordered]@{session_id=$session;input_path=$record.Path;is_analyzing=$false}})
        }
        if($tool-ceq'idb_list'){$rows=@();foreach($r in @($State.Roles.Values)){$rows+=[ordered]@{session_id=$r.Session;input_path=$r.Path;is_active=[bool]$r.Active;owned=$true;redirector_pid=[int]$r.RedirectorPid;redirector_generation=[string]$r.RedirectorGeneration;worker_pid=[int]$r.WorkerPid;worker_generation=[string]$r.WorkerGeneration;route_port=[int]$r.Port;endpoint=[string]$r.Endpoint;socket_owner_pid=[int]$r.RedirectorPid}};return New-UID0002PAV4FixtureResponse $request ([ordered]@{sessions=@($rows)})}
        if($tool-ceq'runtime_attestation'){
            $database=[string]$args.expected_database;if($State.Case-ceq'ModuleDrift'-and$identity.Parsed.id-like'*presave-runtime*'-and-not$State.ModuleMutated){[IO.File]::AppendAllText($State.ModuleB,'-drift');$State.ModuleMutated=$true}
            $workers=@();foreach($r in @($State.Roles.Values|Where-Object{$_.Active})){$modules=Get-UID0002PAV4FixtureModuleRows $State $r.Role;$generation=[string]$r.WorkerGeneration;if($State.Case-ceq'RuntimeSessionDrift'-and$identity.Parsed.id-like'*presave-runtime*'){$generation=$generation+'-drift'};$workers+=[ordered]@{ok=$true;errors=@();nonce=[string]$r.Nonce;route=[ordered]@{host='127.0.0.1';port=[int]$r.Port};process=[ordered]@{pid=[int]$r.WorkerPid;generation=$generation;modules=@($modules.Rows);implementation_manifest_sha256=$modules.Digest};supervisor_sessions=@([ordered]@{session_id=$r.Session;canonical_path=$r.Path;owned=$true;redirector_pid=[int]$r.RedirectorPid;redirector_generation=[string]$r.RedirectorGeneration;route_port=[int]$r.Port;endpoint=[string]$r.Endpoint;socket_owner_pid=[int]$r.RedirectorPid})}}
            return New-UID0002PAV4FixtureResponse $request ([ordered]@{schema_version=1;ok=$true;errors=@();listener=[ordered]@{pid=2147483200;generation='listener-generation';nonce='listener-nonce'};workers=@($workers)})
        }
        if($tool-ceq'idb_save'){$State.SaveCalls++;if($State.SaveCalls-gt1){throw 'SV4-PA fixture duplicate save'};if($State.Case-in@('P1','FinalMismatchRestore','RestoreCorruption','ThirdIdentity','ThrownDopenChanged','TimeoutDopenChanged','DeterminateFailureChanged','IndeterminateChanged')){[IO.File]::WriteAllBytes($State.Canonical,[byte[]](9,8,7,6,5,4,3,2,1))};if($State.Case-like'ThrownDopen*'){throw 'UID0002PA_THROWN'};if($State.Case-like'TimeoutDopen*'){throw 'UID0002PA_TIMEOUT'};if($State.Case-ceq'DisconnectedDopen'){throw 'UID0002PA_DISCONNECT'};if($State.Case-like'DeterminateFailure*'){return New-UID0002PAV4FixtureResponse $request ([ordered]@{saved=$false;error='injected determinate failure'}) $true};if($State.Case-ceq'IndeterminateChanged'){return New-UID0002PAV4FixtureResponse $request ([ordered]@{saved=$false;error=''}) $false};return New-UID0002PAV4FixtureResponse $request ([ordered]@{saved=$true;path=$State.Canonical;database=[string]$args.database})}
        if($tool-ceq'entity_query'){
            $id=[string]$identity.Parsed.id;if(($State.Case-ceq'CompleteNoSave'-or$State.Case-ceq'ReturnedSessionDiffersPreferredCleanup')-and$id-like'uid0002pa-v4-Pre-*'-and-not$State.CatalogFailureInjected){$State.CatalogFailureInjected=$true;throw 'PL4-PA injected pre-save failure'}
            if($id-match'^uid0002pa-v4-([^-]+)-(.+)$'){$phase=$Matches[1];$rowName=$Matches[2]}else{$phase='Mutation';$rowName='I02Dry'};$oracle=@(Get-UID0002PAConfigOracle|Where-Object{$_.name-ceq$rowName});$rowSha=if($oracle.Count-eq1){Get-UID0002PAV4TextSHA256 (ConvertTo-UID0002PAV4CanonicalNode $oracle[0])}else{Get-UID0002PAV4TextSHA256 'dry'};$mismatch='';$ok=$true
            if($phase-ceq'S1Verifier'-and$rowName-ceq'm_startupChannel'-and$State.Case-in@('FinalMismatchRestore','RestoreCorruption','ThirdIdentity')){$mismatch='FINAL_ORACLE_MISMATCH:m_startupChannel';$ok=$false;if($State.Case-ceq'RestoreCorruption'){[IO.File]::AppendAllText(($State.Canonical+'.uid0002pa-v4.backup'),'-corrupt')};if($State.Case-ceq'ThirdIdentity'){[IO.File]::WriteAllBytes($State.Canonical,[byte[]](4,4,4,4))}}
            return New-UID0002PAV4FixtureResponse $request ([ordered]@{ok=$ok;phase=$phase;row=$rowName;row_sha256=$rowSha;semantic_mismatch=$mismatch})
        }
        $operation=if([string]$identity.Parsed.id-match'uid0002pa-v4-(I0[1-5]|I02Dry)'){$Matches[1]}else{'unknown'};New-UID0002PAV4FixtureResponse $request ([ordered]@{ok=$true;operation=$operation})
    }.GetNewClosure()
    $retire={
        param([string]$raw);$State.RetireCalls++;$action=ConvertFrom-UID0002PAV4StrictJson $raw 'FX4-PA retirement action';$record=$State.Roles[[string]$action.session_id];if($null-eq$record-or-not$record.Active){throw 'RR4-PA fixture unknown/already-retired role'};$record.Active=$false
        ([ordered]@{action=[string]$action.action;role=[string]$action.role;session_id=[string]$action.session_id;canonical_path=[string]$action.canonical_path;redirector_pid=[int]$action.redirector_pid;redirector_generation=[string]$action.redirector_generation;worker_pid=[int]$action.worker_pid;worker_generation=[string]$action.worker_generation;route_port=[int]$action.route_port;endpoint=[string]$action.endpoint;socket_owner_pid=[int]$action.socket_owner_pid;nonce=[string]$action.nonce;stable_manifest_sha256=[string]$action.stable_manifest_sha256;process_manifest_sha256=[string]$action.process_manifest_sha256;retired=$true;listener_preserved=$true}|ConvertTo-Json -Compress)
    }.GetNewClosure()
    [pscustomobject]@{Transport=$transport;Retire=$retire}
}

function Invoke-UID0002PAHostileStaticFixtures {
    Initialize-UID0002PAV4SealedTypes;$cases=@('NullAuthority','FixtureBypass','NestedSchemaDrift','RuntimeSessionDrift','ModuleDrift','ReturnedSessionDiffersPreferredCleanup','InactiveRowRetirement','DuplicateJournal','DuplicateBackup','SetupFailure','CompleteNoSave','ThrownDopenP0','ThrownDopenChanged','TimeoutDopenP0','TimeoutDopenChanged','DisconnectedDopen','P0','P1','DeterminateFailureP0','DeterminateFailureChanged','IndeterminateChanged','FinalMismatchRestore','RestoreCorruption','ThirdIdentity');$rows=@()
    foreach($case in $cases){$state=$null;$result=$null;$label=$null;$failure=$null
        try{
            if($case-ceq'NullAuthority'){$null=Invoke-UID0002PAClosedTransaction -Authority $null;throw 'HF4-PA null authority unexpectedly accepted'}
            $state=New-UID0002PAV4FixtureEnvironment $case;$adapters=New-UID0002PAV4FixtureAdapters $state;$authority=New-UID0002PAV4Authority $state.Canonical $state.SourceRoot $adapters.Transport $adapters.Retire
            if($case-ceq'FixtureBypass'){$null=Invoke-UID0002PAClosedTransaction $authority 'forged-fixture-authority';throw 'HF4-PA fixture bypass unexpectedly accepted'}
            if($case-ceq'DuplicateJournal'){[IO.File]::WriteAllText(($state.Canonical+'.uid0002pa-v4.journal'),'occupied')}
            if($case-ceq'DuplicateBackup'){[IO.File]::WriteAllText(($state.Canonical+'.uid0002pa-v4.backup'),'occupied')}
            $result=Invoke-UID0002PAClosedTransaction -Authority $authority;$label=[string]$result.Status
        }catch{$failure=$_.Exception;if($failure.InnerException-is[UID0002PAV4Failure]){$failure=$failure.InnerException};$label=[string]$failure.Message}
        $expected=@{
            NullAuthority='CT4-PA sealed authority required';FixtureBypass='CT4-PA extra positional authority rejected';NestedSchemaDrift='SC4-PA literal recursive schema drift: idb_open';RuntimeSessionDrift='RT4-PA frozen role drift before save';ModuleDrift='MD4-PA module manifest drift';ReturnedSessionDiffersPreferredCleanup='COMPLETE_NO_SAVE';InactiveRowRetirement='P0_VERIFIED_DeterminateSuccess';DuplicateJournal='The file';DuplicateBackup='The file';SetupFailure='COMPLETE_NO_SAVE';CompleteNoSave='COMPLETE_NO_SAVE';ThrownDopenP0='P0_VERIFIED_Thrown';ThrownDopenChanged='DS4-PA changed output lacks determinate sole-save authority: Thrown';TimeoutDopenP0='P0_VERIFIED_Timeout';TimeoutDopenChanged='DS4-PA changed output lacks determinate sole-save authority: Timeout';DisconnectedDopen='P0_VERIFIED_Disconnected';P0='P0_VERIFIED_DeterminateSuccess';P1='P1_VERIFIED';DeterminateFailureP0='P0_VERIFIED_DeterminateFailure';DeterminateFailureChanged='DS4-PA changed output lacks determinate sole-save authority: DeterminateFailure';IndeterminateChanged='DS4-PA changed output lacks determinate sole-save authority: Indeterminate';FinalMismatchRestore='RESTORED_P0_VERIFIED';RestoreCorruption='RS4-PA held P1/B0 authority mismatch';ThirdIdentity='RS4-PA held P1/B0 authority mismatch'
        }[$case]
        if($case-in@('DuplicateJournal','DuplicateBackup')){if($label-notlike"*$expected*"){throw "HF4-PA wrong label case=$case actual=[$label]"}}elseif($label-cne$expected){throw "HF4-PA wrong label case=$case expected=[$expected] actual=[$label]"}
        $saveCount=if($null-ne$result){[int]$result.SaveDispatchCount}elseif($failure-is[UID0002PAV4Failure]){[int]$failure.SaveDispatchCount}elseif($null-ne$state){[int]$state.SaveCalls}else{0};$transportCount=if($null-ne$result){[int]$result.TransportCalls}elseif($failure-is[UID0002PAV4Failure]){[int]$failure.TransportCalls}elseif($null-ne$state){[int]$state.TransportCalls}else{0};$retireCount=if($null-ne$result){[int]$result.RetireCalls}elseif($failure-is[UID0002PAV4Failure]){[int]$failure.RetireCalls}elseif($null-ne$state){[int]$state.RetireCalls}else{0};$restoreCount=if($null-ne$result){[int]$result.RestoreWrites}elseif($failure-is[UID0002PAV4Failure]){[int]$failure.RestoreWrites}else{0};$dopen=if($null-ne$result){[bool]$result.DopenCaptured}elseif($failure-is[UID0002PAV4Failure]){[bool]$failure.DopenCaptured}else{$false}
        if($case-like'*Dopen*'-and-not$dopen){throw "HF4-PA Dopen not captured: $case"};if($saveCount-gt1-or($null-ne$state-and$state.SaveCalls-gt1)){throw "HF4-PA duplicate save observed: $case"}
        $rows+=[pscustomobject]@{Case=$case;Label=$label;ProductionCoordinatorInvocations=1;SaveDispatchCount=$saveCount;TransportCalls=$transportCount;RetireCalls=$retireCount;RestoreWrites=$restoreCount;DopenCaptured=$dopen;JournalRetained=if($null-ne$failure-and$failure-is[UID0002PAV4Failure]){[IO.File]::Exists($failure.JournalPath)}else{$false};ExternalTargetEffects=0}
        if($null-ne$state-and[IO.Directory]::Exists($state.Root)){[IO.Directory]::Delete($state.Root,$true)}
    }
    if($rows.Count-ne24-or@($rows|Where-Object{$_.ProductionCoordinatorInvocations-ne1-or$_.ExternalTargetEffects-ne0}).Count-ne0){throw 'HF4-PA production-path fixture cardinality/effect mismatch'}
    [pscustomobject]@{Passed=24;Failed=0;ProductionCoordinatorInvocations=24;ExternalTargetEffects=0;Cases=$rows}
}
~~~

## Removed Block R019

- SHA256: `ACA3E74C9979236814198F79D0B2F1C2F139AC527059919300BD7343EEE44E72`
- Language: `powershell`
- Bytes: `17612`
- First recovered timestamp: `2026-08-08T19:03:39.028Z`
- Session provenance: rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 196530 (2026-08-08T19:03:39.028Z); rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 196531 (2026-08-08T19:03:39.084Z)

~~~powershell
# Final V6 isolated compiled authority. In a production parent, execute this fence only.
function Initialize-UID0002PAV6IsolatedAuthority {
    if ('UID0002PAV6IsolatedHost' -as [type]) {
        if ([UID0002PAV6IsolatedHost]::ExpectedPayloadSHA256 -cne 'A75FCA715AA3D8EF3FFDE3DE940D2C2B3F8CFA48948DC6DAC876050D694A337E') { throw 'PK6-PA loaded host payload identity mismatch' }
        return
    }
    $source=@'
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Security.Cryptography;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

public sealed class UID0002PAV6Transcript {
  public readonly string Mode;
  public readonly string Json;
  public readonly string SHA256;
  public readonly string PayloadSHA256;
  public readonly int FenceCount;
  internal UID0002PAV6Transcript(string mode,string json,string sha,string payloadSha,int fences) {
    Mode=mode; Json=json; SHA256=sha; PayloadSHA256=payloadSha; FenceCount=fences;
  }
}

public sealed class UID0002PAV6Attestation {
  public readonly string ReportPath;
  public readonly string PayloadSHA256;
  public readonly string PublicEntrySHA256;
  public readonly int FenceCount;
  public readonly bool MutableHostFields;
  internal UID0002PAV6Attestation(string path,string payload,string entry,int fences,bool mutableFields) {
    ReportPath=path; PayloadSHA256=payload; PublicEntrySHA256=entry; FenceCount=fences; MutableHostFields=mutableFields;
  }
}

public sealed class UID0002PAV6RejectedException : Exception {
  public readonly string RejectionCode;
  public readonly long AcceptedProductionEntries;
  public readonly long SaveDispatches;
  public readonly long TransportCalls;
  public readonly long FileSystemEffects;
  public readonly long McpEffects;
  public readonly long IdaEffects;
  public readonly long ProcessEffects;
  internal UID0002PAV6RejectedException(string code)
    : base(code) {
    RejectionCode=code; AcceptedProductionEntries=0; SaveDispatches=0; TransportCalls=0;
    FileSystemEffects=0; McpEffects=0; IdaEffects=0; ProcessEffects=0;
  }
}

public static class UID0002PAV6IsolatedHost {
  public const string ReportPath = @"E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B010\research\0002PA-ConfigEntryBlockReleaseOwnedBuffers-source-quality.md";
  public const string ExpectedPayloadSHA256 = "A75FCA715AA3D8EF3FFDE3DE940D2C2B3F8CFA48948DC6DAC876050D694A337E";
  public const string ExpectedPublicEntrySHA256 = "__UID0002PA_V6_PUBLIC_SHA256__";
  public const string TranscriptMarker = "UID0002PA-V6-TRANSCRIPT";
  public const string AuditDenyEnvironment = "UID0002PA_V6_AUDIT_DENY";

  static string Sha256(byte[] bytes) {
    using (SHA256 sha=SHA256.Create()) return BitConverter.ToString(sha.ComputeHash(bytes)).Replace("-","");
  }

  static string Sha256(string text) { return Sha256(new UTF8Encoding(false,true).GetBytes(text)); }

  static string ReadPayload(out int fenceCount) {
    string report;
    using (FileStream stream=new FileStream(ReportPath,FileMode.Open,FileAccess.Read,FileShare.Read)) {
      using (StreamReader reader=new StreamReader(stream,new UTF8Encoding(false,true),false,65536,true)) report=reader.ReadToEnd();
    }
    if (report.IndexOf('\r')>=0) throw new UID0002PAV6RejectedException("PK6-PA report is not LF-only");
    MatchCollection matches=Regex.Matches(report,"(?ms)^~~~powershell\\n(.*?)^~~~[ \\t]*$");
    fenceCount=matches.Count;
    if (fenceCount!=11) throw new UID0002PAV6RejectedException("PK6-PA exact fence count mismatch");
    StringBuilder payload=new StringBuilder();
    for(int i=0;i<10;i++) payload.Append(matches[i].Groups[1].Value).Append('\n');
    string text=payload.ToString();
    if (!String.Equals(Sha256(text),ExpectedPayloadSHA256,StringComparison.Ordinal)) throw new UID0002PAV6RejectedException("PK6-PA first-ten payload hash mismatch");
    return text;
  }

  static bool HasMutableHostFields() {
    foreach(FieldInfo f in typeof(UID0002PAV6IsolatedHost).GetFields(BindingFlags.Public|BindingFlags.NonPublic|BindingFlags.Static)) if(!f.IsLiteral) return true;
    return false;
  }

  public static UID0002PAV6Attestation InspectPackage() {
    int fences; string payload=ReadPayload(out fences);
    if (HasMutableHostFields()) throw new UID0002PAV6RejectedException("CP6-PA mutable compiled host field");
    return new UID0002PAV6Attestation(ReportPath,Sha256(payload),ExpectedPublicEntrySHA256,fences,false);
  }

  static void RejectAuditDeny() {
    string deny=Environment.GetEnvironmentVariable(AuditDenyEnvironment);
    if (deny!=null && !String.Equals(deny,"1",StringComparison.Ordinal)) throw new UID0002PAV6RejectedException("CP6-PA malformed audit denial value");
    if (String.Equals(deny,"1",StringComparison.Ordinal)) throw new UID0002PAV6RejectedException("CP6-PA audit denial before isolated execution");
  }

  static string BuildChildProgram(string payload,string mode) {
    string invocation=String.Equals(mode,"Production",StringComparison.Ordinal)
      ? "$uid0002paV6Result=Invoke-UID0002PAClosedTransaction"
      : "$uid0002paV6Result=Invoke-UID0002PAHostileStaticFixtures";
    string suffix=@"
$ErrorActionPreference='Stop'
if($PSVersionTable.PSVersion.Major -ne 5 -or $PSVersionTable.PSEdition -cne 'Desktop'){throw 'PK6-PA child is not Windows PowerShell 5.1 Desktop'}
"+invocation+@"
$uid0002paV6Json=$uid0002paV6Result|ConvertTo-Json -Depth 100 -Compress
$uid0002paV6Bytes=[Text.Encoding]::UTF8.GetBytes($uid0002paV6Json)
$uid0002paV6Sha=[Security.Cryptography.SHA256]::Create()
try{$uid0002paV6Digest=([BitConverter]::ToString($uid0002paV6Sha.ComputeHash($uid0002paV6Bytes))).Replace('-','')}finally{$uid0002paV6Sha.Dispose()}
$uid0002paV6B64=[Convert]::ToBase64String($uid0002paV6Bytes)
[Console]::Out.WriteLine('"+TranscriptMarker+"|"+mode+@"|'+$uid0002paV6Digest+'|'+$uid0002paV6B64)
";
    return "$ProgressPreference='SilentlyContinue';$WarningPreference='SilentlyContinue';$InformationPreference='SilentlyContinue';$VerbosePreference='SilentlyContinue';\n"+payload+suffix;
  }

  static UID0002PAV6Transcript RunIsolated(string mode) {
    int fences; string payload=ReadPayload(out fences);
    if (HasMutableHostFields()) throw new UID0002PAV6RejectedException("CP6-PA mutable compiled host field");
    RejectAuditDeny();
    string executable=Path.Combine(Environment.SystemDirectory,"WindowsPowerShell","v1.0","powershell.exe");
    if (!File.Exists(executable)) throw new UID0002PAV6RejectedException("PK6-PA exact Windows PowerShell executable absent");
    ProcessStartInfo info=new ProcessStartInfo(executable,"-NoLogo -NoProfile -NonInteractive -ExecutionPolicy Bypass -Command -");
    info.UseShellExecute=false; info.CreateNoWindow=true; info.RedirectStandardInput=true; info.RedirectStandardOutput=true; info.RedirectStandardError=true;
    using(Process process=new Process()) {
      process.StartInfo=info;
      if(!process.Start()) throw new UID0002PAV6RejectedException("PK6-PA isolated child start failed");
      Task<string> stdout=Task<string>.Factory.StartNew(delegate { return process.StandardOutput.ReadToEnd(); });
      Task<string> stderr=Task<string>.Factory.StartNew(delegate { return process.StandardError.ReadToEnd(); });
      process.StandardInput.Write(BuildChildProgram(payload,mode)); process.StandardInput.Close();
      if(!process.WaitForExit(240000)) { try { process.Kill(); } catch {} throw new UID0002PAV6RejectedException("PK6-PA isolated child timeout"); }
      Task.WaitAll(new Task[]{stdout,stderr});
      string output=stdout.Result; string error=stderr.Result;
      if(process.ExitCode!=0 || error.Length!=0) throw new UID0002PAV6RejectedException("PK6-PA isolated child failure");
      string normalized=output.Replace("\r\n","\n");
      string[] lines=normalized.Split(new char[]{'\n'},StringSplitOptions.RemoveEmptyEntries);
      if(lines.Length!=1) throw new UID0002PAV6RejectedException("PK6-PA transcript line count mismatch");
      string[] parts=lines[0].Split(new char[]{'|'});
      if(parts.Length!=4 || !String.Equals(parts[0],TranscriptMarker,StringComparison.Ordinal) || !String.Equals(parts[1],mode,StringComparison.Ordinal)) throw new UID0002PAV6RejectedException("PK6-PA transcript envelope mismatch");
      byte[] bytes; try { bytes=Convert.FromBase64String(parts[3]); } catch { throw new UID0002PAV6RejectedException("PK6-PA transcript base64 mismatch"); }
      string digest=Sha256(bytes);
      if(!String.Equals(parts[2],digest,StringComparison.Ordinal)) throw new UID0002PAV6RejectedException("PK6-PA transcript hash mismatch");
      string json; try { json=new UTF8Encoding(false,true).GetString(bytes); } catch { throw new UID0002PAV6RejectedException("PK6-PA transcript UTF-8 mismatch"); }
      return new UID0002PAV6Transcript(mode,json,digest,ExpectedPayloadSHA256,fences);
    }
  }

  public static UID0002PAV6Transcript InvokeProduction() { return RunIsolated("Production"); }
  public static UID0002PAV6Transcript InvokePrivateFixtures() { return RunIsolated("PrivateFixtures"); }
}
'@
    Add-Type -TypeDefinition $source -Language CSharp -ReferencedAssemblies @('System.dll','System.Core.dll')
}

Initialize-UID0002PAV6IsolatedAuthority

function Invoke-UID0002PAClosedTransaction {
    [CmdletBinding()] param()
    if($args.Count -ne 0){throw 'CT6-PA public entry accepts exactly zero arguments'}
    [UID0002PAV6IsolatedHost]::InvokeProduction()
}

function Invoke-UID0002PAHostileStaticFixtures {
    [CmdletBinding()] param()
    if($args.Count -ne 0){throw 'CT6-PA private fixture entry accepts exactly zero arguments'}
    [UID0002PAV6IsolatedHost]::InvokePrivateFixtures()
}

function Invoke-UID0002PAV6BoundaryHostiles {
    [CmdletBinding()] param()
    $entry=(Get-Command Invoke-UID0002PAClosedTransaction -CommandType Function).ScriptBlock
    $utf8=[Text.UTF8Encoding]::new($false,$true)
    $sha=[Security.Cryptography.SHA256]::Create()
    try{$entrySha=([BitConverter]::ToString($sha.ComputeHash($utf8.GetBytes($entry.ToString())))).Replace('-','')}finally{$sha.Dispose()}
    $rows=[Collections.Generic.List[object]]::new()
    $run={
        param([string]$Label,[scriptblock]$Attempt,[string]$Expected)
        $accepted=0L;$save=0L;$transport=0L;$fs=0L;$mcp=0L;$ida=0L;$process=0L;$actual=$null
        try{&$Attempt;$accepted=1L;$actual='ACCEPTED'}catch{
            $leaf=$_.Exception;while($null-ne$leaf.InnerException){$leaf=$leaf.InnerException}
            if($leaf -is [UID0002PAV6RejectedException]){
                $actual=$leaf.RejectionCode;$accepted=$leaf.AcceptedProductionEntries;$save=$leaf.SaveDispatches;$transport=$leaf.TransportCalls;$fs=$leaf.FileSystemEffects;$mcp=$leaf.McpEffects;$ida=$leaf.IdaEffects;$process=$leaf.ProcessEffects
            }else{$actual=$leaf.Message}
        }
        if($actual-cne$Expected){throw "HF6-PA $Label expected '$Expected', got '$actual'"}
        if(($accepted+$save+$transport+$fs+$mcp+$ida+$process)-ne0){throw "HF6-PA $Label observed a prohibited effect"}
        $rows.Add([pscustomobject]@{Label=$Label;Result='Rejected';Code=$actual;AcceptedProductionEntries=$accepted;SaveDispatches=$save;TransportCalls=$transport;FileSystemEffects=$fs;McpEffects=$mcp;IdaEffects=$ida;ProcessEffects=$process})
    }
    $oldDeny=[Environment]::GetEnvironmentVariable([UID0002PAV6IsolatedHost]::AuditDenyEnvironment)
    try{
        [Environment]::SetEnvironmentVariable([UID0002PAV6IsolatedHost]::AuditDenyEnvironment,'1')
        $att=[UID0002PAV6IsolatedHost]::InspectPackage()
        if($att.FenceCount-ne11 -or $att.PayloadSHA256-cne[UID0002PAV6IsolatedHost]::ExpectedPayloadSHA256 -or $att.MutableHostFields){throw 'HF6-PA package attestation mismatch'}
        if($entrySha-cne[UID0002PAV6IsolatedHost]::ExpectedPublicEntrySHA256){throw 'HF6-PA public entry hash mismatch'}
        $module=$entry.Module
        if($null-ne$module){foreach($name in 'sharedCoordinator','productionIssuer','helperManifest','hashScriptText','canonical','sourceRoot','transport','retirement','legacyCoordinator','fixtureIssuer','fixtureBridge','fixtureSuite','package','factory'){if($null-ne$module.SessionState.PSVariable.Get($name)){throw "HF6-PA authoritative module variable exposed: $name"}}}
        $mutable=@([UID0002PAV6IsolatedHost].GetFields([Reflection.BindingFlags]'Public,NonPublic,Static')|Where-Object{-not$_.IsLiteral})
        if($mutable.Count-ne0){throw 'HF6-PA mutable reflected host field exposed'}
        $methods=@([UID0002PAV6IsolatedHost].GetMethods([Reflection.BindingFlags]'Public,Static,DeclaredOnly'))
        if(@($methods|Where-Object{$_.Name -in 'InvokeProduction','InvokePrivateFixtures' -and $_.GetParameters().Count-ne0}).Count-ne0){throw 'HF6-PA authority method accepts caller data'}

        &$run 'ModuleSessionSetSharedCoordinator' {if($null-ne$module){$module.SessionState.PSVariable.Set('sharedCoordinator',{[pscustomobject]@{Outcome='FORGED_ACCEPTED';Scope='Production';TransportCalls=0;Forged=$true}})};&$entry} 'CP6-PA audit denial before isolated execution'
        &$run 'ModuleSessionRemoveSharedCoordinator' {if($null-ne$module){$module.SessionState.PSVariable.Remove('sharedCoordinator')};&$entry} 'CP6-PA audit denial before isolated execution'
        &$run 'ModuleSessionReplaceEveryLegacyAuthority' {if($null-ne$module){foreach($name in 'productionIssuer','helperManifest','hashScriptText','canonical','sourceRoot','transport','retirement','legacyCoordinator','fixtureIssuer','fixtureBridge','fixtureSuite','package','factory'){$module.SessionState.PSVariable.Set($name,{throw 'FORGED'})}};&$entry} 'CP6-PA audit denial before isolated execution'
        &$run 'ClosureAndModuleInspection' {if($null-ne$module -and $null-ne$module.SessionState.PSVariable.Get('sharedCoordinator')){throw 'HF6-PA inspected forbidden variable'};&$entry} 'CP6-PA audit denial before isolated execution'
        &$run 'ReflectedDelegateTargetSubstitution' {[UID0002PAV6IsolatedHost].GetFields([Reflection.BindingFlags]'Public,NonPublic,Static')|ForEach-Object{if(-not$_.IsLiteral){$_.SetValue($null,{throw 'FORGED'})}};&$entry} 'CP6-PA audit denial before isolated execution'
        &$run 'DirectReflectedProductionCall' {[UID0002PAV6IsolatedHost].GetMethod('InvokeProduction',[Reflection.BindingFlags]'Public,Static').Invoke($null,@())} 'CP6-PA audit denial before isolated execution'
        &$run 'FunctionResolutionMutation' {$saved=(Get-Command Invoke-UID0002PAClosedTransaction -CommandType Function).ScriptBlock;try{Set-Item Function:\global:Invoke-UID0002PAClosedTransaction -Value {throw 'FORGED-FUNCTION'} -Force;&$saved}finally{Set-Item Function:\global:Invoke-UID0002PAClosedTransaction -Value $saved -Force}} 'CP6-PA audit denial before isolated execution'
        &$run 'GlobalAndModuleMutation' {Set-Variable -Scope Global -Name sharedCoordinator -Value {throw 'FORGED-GLOBAL'} -Force;try{&$entry}finally{Remove-Variable -Scope Global -Name sharedCoordinator -ErrorAction SilentlyContinue}} 'CP6-PA audit denial before isolated execution'
        &$run 'ArbitraryPathAndAdapterArguments' {&$entry 'E:\forged.idb' 'E:\forged-root' {throw 'FORGED-TRANSPORT'}} 'CT6-PA public entry accepts exactly zero arguments'
        &$run 'CapabilityCopyReplay' {if('UID0002PAV6Capability' -as[type]){throw 'HF6-PA V6 capability type exposed'};&$entry} 'CP6-PA audit denial before isolated execution'
        &$run 'CrossScopeInvocation' {$foreign=New-Module -ScriptBlock {param($script)&$script} -ArgumentList $entry;&$foreign} 'CP6-PA audit denial before isolated execution'
        &$run 'BetweenCheckAndUseMutation' {$null=[UID0002PAV6IsolatedHost]::InspectPackage();if($null-ne$module){$module.SessionState.PSVariable.Set('sharedCoordinator',{throw 'FORGED-TOCTOU'})};&$entry} 'CP6-PA audit denial before isolated execution'
        &$run 'ConcurrentMutationHasNoAuthorityTarget' {1..64|ForEach-Object{if($null-ne$module){$module.SessionState.PSVariable.Set('sharedCoordinator',{throw 'FORGED-RACE'});$module.SessionState.PSVariable.Remove('sharedCoordinator')}};&$entry} 'CP6-PA audit denial before isolated execution'
        &$run 'PackageFactoryAndIssuerNamesAreNonAuthoritative' {Set-Variable -Scope Global -Name uid0002paV5PackageFactory -Value {throw 'FORGED-FACTORY'} -Force;Set-Variable -Scope Global -Name productionIssuer -Value {throw 'FORGED-ISSUER'} -Force;try{&$entry}finally{Remove-Variable -Scope Global -Name uid0002paV5PackageFactory,productionIssuer -ErrorAction SilentlyContinue}} 'CP6-PA audit denial before isolated execution'
    } finally {
        [Environment]::SetEnvironmentVariable([UID0002PAV6IsolatedHost]::AuditDenyEnvironment,$oldDeny)
    }
    $post=[UID0002PAV6IsolatedHost]::InspectPackage()
    if($post.PayloadSHA256-cne$att.PayloadSHA256 -or $post.PublicEntrySHA256-cne$entrySha){throw 'HF6-PA package identity drift after hostiles'}
    [pscustomobject]@{Passed=$rows.Count;Failed=0;Labels=@($rows.Label);AcceptedProductionEntries=[long](($rows|Measure-Object AcceptedProductionEntries -Sum).Sum);SaveDispatches=[long](($rows|Measure-Object SaveDispatches -Sum).Sum);TransportCalls=[long](($rows|Measure-Object TransportCalls -Sum).Sum);FileSystemEffects=[long](($rows|Measure-Object FileSystemEffects -Sum).Sum);McpEffects=[long](($rows|Measure-Object McpEffects -Sum).Sum);IdaEffects=[long](($rows|Measure-Object IdaEffects -Sum).Sum);ProcessEffects=[long](($rows|Measure-Object ProcessEffects -Sum).Sum);PayloadSHA256=$post.PayloadSHA256;PublicEntrySHA256=$entrySha;Rows=@($rows)}
}
~~~

## Removed Block R020

- SHA256: `914D00C3B7AA21578B73504E13F9E4C4D0073084997A709A12ADDD842C7C8320`
- Language: `powershell`
- Bytes: `37202`
- First recovered timestamp: `2026-08-08T20:13:02.480Z`
- Session provenance: rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 196915 (2026-08-08T20:13:02.480Z); rollout-2026-08-06T18-25-05-019fd92e-1b5b-7210-8ca3-a60b3d99e361.jsonl line 196916 (2026-08-08T20:13:02.537Z)

~~~powershell
$uid0002paV6Launchers=@('Initialize-UID0002PAV6IsolatedAuthority','Invoke-UID0002PAClosedTransaction','Invoke-UID0002PAHostileStaticFixtures','Invoke-UID0002PAV6BoundaryHostiles')
if('UID0002PAV6IsolatedHost' -as [type]){throw 'CP6-PA preloaded authoritative host type refused'}
foreach($uid0002paV6Launcher in $uid0002paV6Launchers){if($null-ne(Microsoft.PowerShell.Core\Get-Command -Name $uid0002paV6Launcher -ErrorAction SilentlyContinue)){throw "CP6-PA preloaded authoritative launcher refused: $uid0002paV6Launcher"}}
Remove-Variable uid0002paV6Launcher,uid0002paV6Launchers -ErrorAction SilentlyContinue

function Initialize-UID0002PAV6IsolatedAuthority {
    [CmdletBinding()]param()
    if('UID0002PAV6IsolatedHost' -as [type]){throw 'CP6-PA preloaded authoritative host type refused'}
    $source=@'
using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Threading.Tasks;
using System.Web.Script.Serialization;
[assembly: AssemblyTitle("UID0002PA.SealedHost")]
[assembly: AssemblyDescription("Report-owned UID0002PA sealed child boundary")]
[assembly: AssemblyVersion("6.2.0.0")]
[assembly: ComVisible(false)]

public sealed class UID0002PAV6Attestation {
  public readonly string ReportPath,PayloadSHA256,SourceSHA256,ApiSHA256,MethodManifestSHA256,AssemblySHA256,PublicEntrySHA256,FixtureEntrySHA256;
  public readonly int FenceCount;
  public readonly bool MutableHostFields;
  internal UID0002PAV6Attestation(string path,string payload,string source,string api,string methods,string assembly,string entry,string fixture,int fences,bool mutable) {
    ReportPath=path;PayloadSHA256=payload;SourceSHA256=source;ApiSHA256=api;MethodManifestSHA256=methods;AssemblySHA256=assembly;PublicEntrySHA256=entry;FixtureEntrySHA256=fixture;FenceCount=fences;MutableHostFields=mutable;
  }
}

public sealed class UID0002PAV6Transcript {
  public readonly string Mode,Json,SHA256,ResultJson,ResultSHA256,InvocationNonce,ExecutableSHA256,PayloadSHA256,SourceSHA256,ApiSHA256,MethodManifestSHA256,AssemblySHA256,PublicEntrySHA256,FixtureEntrySHA256,CanonicalDatabase,DatabaseSession,Outcome,BeforeTargetSHA256,AfterTargetSHA256;
  public readonly int Sequence,ChildPID;
  public readonly long ChildGenerationUtcTicks,SaveDispatches,TransportCalls,ExternalTargetEffects,McpEffects,IdaEffects,FileSystemEffects;
  public readonly bool ExactChildRetired,OneTimeConsumed,BeforeJournalExists,AfterJournalExists,BeforeBackupExists,AfterBackupExists;
  internal UID0002PAV6Transcript(string mode,string json,string sha,string resultJson,string resultSha,string nonce,int sequence,int pid,long generation,string executable,bool retired,bool consumed,string payload,string source,string api,string methods,string assembly,string entry,string fixture,string canonical,string session,string outcome,long saves,long transports,long external,long mcp,long ida,long fileEffects,string beforeTarget,string afterTarget,bool beforeJournal,bool afterJournal,bool beforeBackup,bool afterBackup) {
    Mode=mode;Json=json;SHA256=sha;ResultJson=resultJson;ResultSHA256=resultSha;InvocationNonce=nonce;Sequence=sequence;ChildPID=pid;ChildGenerationUtcTicks=generation;ExecutableSHA256=executable;ExactChildRetired=retired;OneTimeConsumed=consumed;PayloadSHA256=payload;SourceSHA256=source;ApiSHA256=api;MethodManifestSHA256=methods;AssemblySHA256=assembly;PublicEntrySHA256=entry;FixtureEntrySHA256=fixture;CanonicalDatabase=canonical;DatabaseSession=session;Outcome=outcome;SaveDispatches=saves;TransportCalls=transports;ExternalTargetEffects=external;McpEffects=mcp;IdaEffects=ida;FileSystemEffects=fileEffects;BeforeTargetSHA256=beforeTarget;AfterTargetSHA256=afterTarget;BeforeJournalExists=beforeJournal;AfterJournalExists=afterJournal;BeforeBackupExists=beforeBackup;AfterBackupExists=afterBackup;
  }
}

public sealed class UID0002PAV6ProbeReceipt {
  public readonly int Workers,Iterations;
  public readonly bool AuthorityStable,MutatedCopyRejected;
  public readonly string AuthoritySHA256;
  internal UID0002PAV6ProbeReceipt(int workers,int iterations,bool stable,bool rejected,string sha){Workers=workers;Iterations=iterations;AuthorityStable=stable;MutatedCopyRejected=rejected;AuthoritySHA256=sha;}
}

public sealed class UID0002PAV6RejectedException : Exception {
  public readonly string RejectionCode,Stage;
  public readonly int ChildPID;
  public readonly long ChildGenerationUtcTicks,SaveDispatches,TransportCalls,FileSystemEffects,McpEffects,IdaEffects,ProcessEffects;
  public readonly bool ExactChildRetired;
  internal UID0002PAV6RejectedException(string code,string stage):this(code,stage,0,0,true,0,0,0,0,0,0){}
  internal UID0002PAV6RejectedException(string code,string stage,int pid,long generation,bool retired,long saves,long transports,long fileEffects,long mcp,long ida,long processEffects):base(code){RejectionCode=code;Stage=stage;ChildPID=pid;ChildGenerationUtcTicks=generation;ExactChildRetired=retired;SaveDispatches=saves;TransportCalls=transports;FileSystemEffects=fileEffects;McpEffects=mcp;IdaEffects=ida;ProcessEffects=processEffects;}
}

public static class UID0002PAV6IsolatedHost {
  public const string ReportPath=@"E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B010\research\0002PA-ConfigEntryBlockReleaseOwnedBuffers-source-quality.md";
  public const string CanonicalDatabase=@"E:\NTK\Resources\NexusTK\NexusTK.exe.i64";
  public const string ExpectedPayloadSHA256="A75FCA715AA3D8EF3FFDE3DE940D2C2B3F8CFA48948DC6DAC876050D694A337E";
  public const string ExpectedSourceSHA256="__UID0002PA_V6_SOURCE_SHA256__";
  public const string ExpectedApiSHA256="__UID0002PA_V6_API_SHA256__";
  public const string ExpectedMethodManifestSHA256="__UID0002PA_V6_METHOD_SHA256__";
  public const string ExpectedAssemblySHA256="__UID0002PA_V6_ASSEMBLY_SHA256__";
  public const string ExpectedPublicEntrySHA256="__UID0002PA_V6_PUBLIC_SHA256__";
  public const string ExpectedFixtureEntrySHA256="__UID0002PA_V6_FIXTURE_SHA256__";
  public const string TranscriptMarker="UID0002PA-V6-TRANSCRIPT";

  static string Sha256(byte[] bytes){using(SHA256 sha=SHA256.Create())return BitConverter.ToString(sha.ComputeHash(bytes)).Replace("-","");}
  static string Sha256(string text){return Sha256(new UTF8Encoding(false,true).GetBytes(text));}
  static string FileSha256(string path){using(FileStream s=new FileStream(path,FileMode.Open,FileAccess.Read,FileShare.ReadWrite|FileShare.Delete))using(SHA256 sha=SHA256.Create())return BitConverter.ToString(sha.ComputeHash(s)).Replace("-","");}
  static string NormalizeSource(string source){return Regex.Replace(source,"(?m)^(  public const string Expected(?:Source|Api|MethodManifest|Assembly|PublicEntry|FixtureEntry)SHA256=\")[^\"]+(\";)$","$1__NORMALIZED__$2");}
  static bool HasMutableHostFields(){foreach(FieldInfo f in typeof(UID0002PAV6IsolatedHost).GetFields(BindingFlags.Public|BindingFlags.NonPublic|BindingFlags.Static))if(!f.IsLiteral)return true;return false;}
  static string MethodSignature(MethodInfo m){ParameterInfo[] p=m.GetParameters();StringBuilder b=new StringBuilder();b.Append(m.Name).Append('|').Append(m.ReturnType.FullName);for(int i=0;i<p.Length;i++)b.Append('|').Append(p[i].ParameterType.FullName);return b.ToString();}
  static string CurrentApiSHA256(){List<string> rows=new List<string>();foreach(MethodInfo m in typeof(UID0002PAV6IsolatedHost).GetMethods(BindingFlags.Public|BindingFlags.Static|BindingFlags.DeclaredOnly))rows.Add(MethodSignature(m));rows.Sort(StringComparer.Ordinal);return Sha256(String.Join("\n",rows.ToArray())+"\n");}
  static string CurrentMethodManifestSHA256(){List<string> rows=new List<string>();foreach(MethodInfo m in typeof(UID0002PAV6IsolatedHost).GetMethods(BindingFlags.Public|BindingFlags.NonPublic|BindingFlags.Static|BindingFlags.DeclaredOnly)){if(m.Name=="VerifySelf")continue;MethodBody body=m.GetMethodBody();if(body==null)throw new UID0002PAV6RejectedException("CP6-PA sealed method body absent","CurrentMethodManifest");rows.Add(MethodSignature(m)+"|"+Sha256(body.GetILAsByteArray()));}rows.Sort(StringComparer.Ordinal);return Sha256(String.Join("\n",rows.ToArray())+"\n");}
  static string CurrentAssemblySHA256(){Assembly a=typeof(UID0002PAV6IsolatedHost).Assembly;AssemblyTitleAttribute t=(AssemblyTitleAttribute)Attribute.GetCustomAttribute(a,typeof(AssemblyTitleAttribute));AssemblyDescriptionAttribute d=(AssemblyDescriptionAttribute)Attribute.GetCustomAttribute(a,typeof(AssemblyDescriptionAttribute));return Sha256(a.FullName+"|"+(t==null?"":t.Title)+"|"+(d==null?"":d.Description));}

  static string ReadPackage(out int fences,out string sourceHash){string report;using(FileStream s=new FileStream(ReportPath,FileMode.Open,FileAccess.Read,FileShare.Read))using(StreamReader r=new StreamReader(s,new UTF8Encoding(false,true),false,65536))report=r.ReadToEnd();if(report.IndexOf('\r')>=0)throw new UID0002PAV6RejectedException("PK6-PA report is not LF-only","ReadPackage");MatchCollection m=Regex.Matches(report,"(?ms)^~~~powershell\\n(.*?)^~~~[ \\t]*$");fences=m.Count;if(fences!=11)throw new UID0002PAV6RejectedException("PK6-PA exact fence count mismatch","ReadPackage");StringBuilder p=new StringBuilder();for(int i=0;i<10;i++)p.Append(m[i].Groups[1].Value).Append('\n');string payload=p.ToString();if(!String.Equals(Sha256(payload),ExpectedPayloadSHA256,StringComparison.Ordinal))throw new UID0002PAV6RejectedException("PK6-PA first-ten payload hash mismatch","ReadPackage");Match sm=Regex.Match(m[10].Groups[1].Value,"(?ms)^    \\$source=@'\\n(.*?)^'@[ \\t]*$");if(!sm.Success)throw new UID0002PAV6RejectedException("PK6-PA report-owned source missing","ReadPackage");sourceHash=Sha256(NormalizeSource(sm.Groups[1].Value));return payload;}
  static void VerifySelf(){int fences;string source;ReadPackage(out fences,out source);Assembly a=typeof(UID0002PAV6IsolatedHost).Assembly;AssemblyTitleAttribute title=(AssemblyTitleAttribute)Attribute.GetCustomAttribute(a,typeof(AssemblyTitleAttribute));if(title==null||title.Title!="UID0002PA.SealedHost"||a.GetName().Version.ToString()!="6.2.0.0")throw new UID0002PAV6RejectedException("CP6-PA sealed assembly identity mismatch","VerifySelf");if(HasMutableHostFields())throw new UID0002PAV6RejectedException("CP6-PA mutable compiled host field","VerifySelf");if(source!=ExpectedSourceSHA256)throw new UID0002PAV6RejectedException("CP6-PA report-owned source hash mismatch","VerifySelf");if(CurrentApiSHA256()!=ExpectedApiSHA256)throw new UID0002PAV6RejectedException("CP6-PA public API hash mismatch","VerifySelf");if(CurrentMethodManifestSHA256()!=ExpectedMethodManifestSHA256)throw new UID0002PAV6RejectedException("CP6-PA method IL manifest mismatch","VerifySelf");if(CurrentAssemblySHA256()!=ExpectedAssemblySHA256)throw new UID0002PAV6RejectedException("CP6-PA assembly identity hash mismatch","VerifySelf");}
  static void ExactKeys(IDictionary<string,object> d,string[] expected,string label){if(d==null||d.Count!=expected.Length)throw new UID0002PAV6RejectedException("TR6-PA exact key count mismatch: "+label,"Transcript");foreach(string k in expected)if(!d.ContainsKey(k))throw new UID0002PAV6RejectedException("TR6-PA missing key: "+label+"."+k,"Transcript");}
  static IDictionary<string,object> Dict(object v,string label){IDictionary<string,object> d=v as IDictionary<string,object>;if(d==null)throw new UID0002PAV6RejectedException("TR6-PA object mismatch: "+label,"Transcript");return d;}
  static string Str(object v,string label){string s=v as string;if(s==null)throw new UID0002PAV6RejectedException("TR6-PA string mismatch: "+label,"Transcript");return s;}
  static long Int64Value(object v,string label){if(v is int)return (int)v;if(v is long)return (long)v;throw new UID0002PAV6RejectedException("TR6-PA integer mismatch: "+label,"Transcript");}
  static bool BoolValue(object v,string label){if(!(v is bool))throw new UID0002PAV6RejectedException("TR6-PA boolean mismatch: "+label,"Transcript");return (bool)v;}
  static string PSQuote(string s){return "'"+s.Replace("'","''")+"'";}
  static string FileTuple(string path){if(!File.Exists(path))return "ABSENT";FileInfo f=new FileInfo(path);return f.Length+"|"+f.LastWriteTimeUtc.Ticks+"|"+FileSha256(path);}

  static string BuildChildProgram(string payload,string mode,string nonce,string executableSha,string sourceSha,string apiSha,string methodsSha,string assemblySha){
    string modeBody;
    if(mode=="PrivateFixtures")modeBody=@"
$uid0002paV6Raw=Invoke-UID0002PAHostileStaticFixtures
$uid0002paV6FixtureSaves=[long](($uid0002paV6Raw.Cases|Microsoft.PowerShell.Utility\Measure-Object -Property SaveDispatchCount -Sum).Sum)
$uid0002paV6FixtureTransports=[long](($uid0002paV6Raw.Cases|Microsoft.PowerShell.Utility\Measure-Object -Property TransportCalls -Sum).Sum)
$uid0002paV6Result=[ordered]@{kind='PrivateFixtures';passed=[long]$uid0002paV6Raw.Passed;failed=[long]$uid0002paV6Raw.Failed;production_coordinator_invocations=[long]$uid0002paV6Raw.ProductionCoordinatorInvocations;external_target_effects=[long]$uid0002paV6Raw.ExternalTargetEffects;effect_observations=[long]$uid0002paV6Raw.EffectObservations;fixture_save_operations=$uid0002paV6FixtureSaves;fixture_transport_operations=$uid0002paV6FixtureTransports;boundary_passed=[long]$uid0002paV6Raw.BoundaryPassed;boundary_failed=[long]$uid0002paV6Raw.BoundaryFailed;boundary_production_entries=[long]$uid0002paV6Raw.BoundaryProductionEntries;boundary_save_dispatch_count=[long]$uid0002paV6Raw.BoundarySaveDispatchCount;boundary_external_target_effects=[long]$uid0002paV6Raw.BoundaryExternalTargetEffects}
$uid0002paV6Outcome='PRIVATE_FIXTURES_PASSED';$uid0002paV6Session='fixture:no-live-session';$uid0002paV6Saves=0L;$uid0002paV6Transports=0L;$uid0002paV6External=[long]$uid0002paV6Raw.ExternalTargetEffects
";
    else if(mode=="LegacyWitness")modeBody=@"
$uid0002paV6Command=Microsoft.PowerShell.Core\Get-Command Invoke-UID0002PAClosedTransaction -CommandType Function
$uid0002paV6Entry=$uid0002paV6Command.ScriptBlock;$uid0002paV6Module=$uid0002paV6Entry.Module
if($null-eq$uid0002paV6Module){throw 'LW6-PA V5 closure module missing'}
$uid0002paV6Hash={param([string]$Text)$b=[Text.UTF8Encoding]::new($false,$true).GetBytes($Text);$h=[Security.Cryptography.SHA256]::Create();try{([BitConverter]::ToString($h.ComputeHash($b))).Replace('-','')}finally{$h.Dispose()}}
$uid0002paV6Before=&$uid0002paV6Hash ([string]$uid0002paV6Entry)
$uid0002paV6Old=$uid0002paV6Module.SessionState.PSVariable.Get('sharedCoordinator');if($null-eq$uid0002paV6Old){throw 'LW6-PA V5 sharedCoordinator missing'}
$uid0002paV6Forged={param($Capability,$Scope,$ForwardArguments)[pscustomobject][ordered]@{Outcome='FORGED_ACCEPTED';Scope='Production';TransportCalls=0L;Forged=$true}}.GetNewClosure()
$uid0002paV6Module.SessionState.PSVariable.Set('sharedCoordinator',$uid0002paV6Forged)
try{$uid0002paV6Raw=&$uid0002paV6Entry}finally{$uid0002paV6Module.SessionState.PSVariable.Set('sharedCoordinator',$uid0002paV6Old.Value)}
$uid0002paV6AfterVar=$uid0002paV6Module.SessionState.PSVariable.Get('sharedCoordinator');$uid0002paV6Restored=[object]::ReferenceEquals($uid0002paV6AfterVar.Value,$uid0002paV6Old.Value);$uid0002paV6After=&$uid0002paV6Hash ([string](Microsoft.PowerShell.Core\Get-Command Invoke-UID0002PAClosedTransaction -CommandType Function).ScriptBlock)
$uid0002paV6Result=[ordered]@{kind='LegacyWitness';outcome=[string]$uid0002paV6Raw.Outcome;scope=[string]$uid0002paV6Raw.Scope;transport_calls=[long]$uid0002paV6Raw.TransportCalls;forged=[bool]$uid0002paV6Raw.Forged;public_entry_sha_before=$uid0002paV6Before;public_entry_sha_after=$uid0002paV6After;module_restored=$uid0002paV6Restored}
$uid0002paV6Outcome='LEGACY_FORGED_ACCEPTED_WITNESSED';$uid0002paV6Session='legacy:no-live-session';$uid0002paV6Saves=0L;$uid0002paV6Transports=0L;$uid0002paV6External=0L
";
    else modeBody=@"
$uid0002paV6Raw=Invoke-UID0002PAClosedTransaction
$uid0002paV6Status=if($null-ne$uid0002paV6Raw.PSObject.Properties['Status']){[string]$uid0002paV6Raw.Status}else{'COMPLETED'}
$uid0002paV6Save=if($null-ne$uid0002paV6Raw.PSObject.Properties['SaveDispatchCount']){[long]$uid0002paV6Raw.SaveDispatchCount}else{0L}
$uid0002paV6Result=[ordered]@{kind='Production';status=$uid0002paV6Status;save_dispatch_count=$uid0002paV6Save;transport_calls=0L;external_target_effects=0L;session='returned-session-bound-inside-v4'}
$uid0002paV6Outcome=$uid0002paV6Status;$uid0002paV6Session='returned-session-bound-inside-v4';$uid0002paV6Saves=$uid0002paV6Save;$uid0002paV6Transports=0L;$uid0002paV6External=0L
";
    string suffix=modeBody+@"
$uid0002paV6Process=[Diagnostics.Process]::GetCurrentProcess();try{$uid0002paV6Generation=$uid0002paV6Process.StartTime.ToUniversalTime().Ticks}finally{$uid0002paV6Process.Dispose()}
$uid0002paV6ResultJson=Microsoft.PowerShell.Utility\ConvertTo-Json -InputObject ([pscustomobject]$uid0002paV6Result) -Depth 20 -Compress
$uid0002paV6Utf8=[Text.UTF8Encoding]::new($false,$true);$uid0002paV6Hasher=[Security.Cryptography.SHA256]::Create();try{$uid0002paV6ResultSha=([BitConverter]::ToString($uid0002paV6Hasher.ComputeHash($uid0002paV6Utf8.GetBytes($uid0002paV6ResultJson)))).Replace('-','')}finally{$uid0002paV6Hasher.Dispose()}
$uid0002paV6Counters=[ordered]@{save_dispatches=[long]$uid0002paV6Saves;transport_calls=[long]$uid0002paV6Transports;external_target_effects=[long]$uid0002paV6External;mcp_effects=0L;ida_effects=0L;filesystem_effects=0L}
";
    suffix+="$uid0002paV6Envelope=[ordered]@{schema=6;marker="+PSQuote(TranscriptMarker)+";mode="+PSQuote(mode)+";invocation_nonce="+PSQuote(nonce)+";sequence=1L;child_pid=[long]$PID;child_generation_utc_ticks=[long]$uid0002paV6Generation;executable_sha256="+PSQuote(executableSha)+";payload_sha256="+PSQuote(ExpectedPayloadSHA256)+";public_entry_sha256="+PSQuote(ExpectedPublicEntrySHA256)+";fixture_entry_sha256="+PSQuote(ExpectedFixtureEntrySHA256)+";source_sha256="+PSQuote(sourceSha)+";api_sha256="+PSQuote(apiSha)+";method_manifest_sha256="+PSQuote(methodsSha)+";assembly_sha256="+PSQuote(assemblySha)+";canonical_database="+PSQuote(CanonicalDatabase)+";database_session=$uid0002paV6Session;counters=$uid0002paV6Counters;result_json_b64=[Convert]::ToBase64String($uid0002paV6Utf8.GetBytes($uid0002paV6ResultJson));result_sha256=$uid0002paV6ResultSha;outcome=$uid0002paV6Outcome}\n";
    suffix+="$uid0002paV6Line=Microsoft.PowerShell.Utility\\ConvertTo-Json -InputObject ([pscustomobject]$uid0002paV6Envelope) -Depth 20 -Compress\nif([string]::IsNullOrWhiteSpace($uid0002paV6Line)-or$uid0002paV6Line.IndexOf([char]10)-ge0-or$uid0002paV6Line.IndexOf([char]13)-ge0){throw 'TR6-PA invalid serialized transcript'}\n[Console]::Out.Write($uid0002paV6Line)\n";
    return "Set-StrictMode -Version 2.0\n$ErrorActionPreference='Stop'\n$WarningPreference='Stop'\n$InformationPreference='Stop'\n$VerbosePreference='Stop'\n$DebugPreference='Stop'\n$ProgressPreference='SilentlyContinue'\n"+payload+suffix;
  }

  static IDictionary<string,object> ParseTranscript(string json,string mode,string nonce,int pid,long generation,string executableSha,string sourceSha,string apiSha,string methodsSha,string assemblySha,out string resultJson,out string resultSha,out string session,out string outcome,out long saves,out long transports,out long external,out long mcp,out long ida,out long fileEffects){JavaScriptSerializer j=new JavaScriptSerializer();j.MaxJsonLength=33554432;IDictionary<string,object> root=Dict(j.DeserializeObject(json),"root");ExactKeys(root,new string[]{"schema","marker","mode","invocation_nonce","sequence","child_pid","child_generation_utc_ticks","executable_sha256","payload_sha256","public_entry_sha256","fixture_entry_sha256","source_sha256","api_sha256","method_manifest_sha256","assembly_sha256","canonical_database","database_session","counters","result_json_b64","result_sha256","outcome"},"root");if(Int64Value(root["schema"],"schema")!=6||Str(root["marker"],"marker")!=TranscriptMarker||Str(root["mode"],"mode")!=mode||Str(root["invocation_nonce"],"nonce")!=nonce||Int64Value(root["sequence"],"sequence")!=1||Int64Value(root["child_pid"],"pid")!=pid||Int64Value(root["child_generation_utc_ticks"],"generation")!=generation)throw new UID0002PAV6RejectedException("TR6-PA root identity mismatch","Transcript");if(Str(root["executable_sha256"],"executable")!=executableSha||Str(root["payload_sha256"],"payload")!=ExpectedPayloadSHA256||Str(root["public_entry_sha256"],"entry")!=ExpectedPublicEntrySHA256||Str(root["fixture_entry_sha256"],"fixture")!=ExpectedFixtureEntrySHA256||Str(root["source_sha256"],"source")!=sourceSha||Str(root["api_sha256"],"api")!=apiSha||Str(root["method_manifest_sha256"],"methods")!=methodsSha||Str(root["assembly_sha256"],"assembly")!=assemblySha||Path.GetFullPath(Str(root["canonical_database"],"canonical"))!=Path.GetFullPath(CanonicalDatabase))throw new UID0002PAV6RejectedException("TR6-PA sealed identity mismatch","Transcript");session=Str(root["database_session"],"session");outcome=Str(root["outcome"],"outcome");IDictionary<string,object> c=Dict(root["counters"],"counters");ExactKeys(c,new string[]{"save_dispatches","transport_calls","external_target_effects","mcp_effects","ida_effects","filesystem_effects"},"counters");saves=Int64Value(c["save_dispatches"],"save");transports=Int64Value(c["transport_calls"],"transport");external=Int64Value(c["external_target_effects"],"external");mcp=Int64Value(c["mcp_effects"],"mcp");ida=Int64Value(c["ida_effects"],"ida");fileEffects=Int64Value(c["filesystem_effects"],"filesystem");byte[] rb;try{rb=Convert.FromBase64String(Str(root["result_json_b64"],"result_b64"));resultJson=new UTF8Encoding(false,true).GetString(rb);}catch{throw new UID0002PAV6RejectedException("TR6-PA result encoding mismatch","Transcript");}resultSha=Str(root["result_sha256"],"result_sha");if(Sha256(resultJson)!=resultSha)throw new UID0002PAV6RejectedException("TR6-PA result hash mismatch","Transcript");IDictionary<string,object> result=Dict(j.DeserializeObject(resultJson),"result");if(mode=="PrivateFixtures"){ExactKeys(result,new string[]{"kind","passed","failed","production_coordinator_invocations","external_target_effects","effect_observations","fixture_save_operations","fixture_transport_operations","boundary_passed","boundary_failed","boundary_production_entries","boundary_save_dispatch_count","boundary_external_target_effects"},"private-result");if(Str(result["kind"],"kind")!="PrivateFixtures"||Int64Value(result["passed"],"passed")!=27||Int64Value(result["failed"],"failed")!=0||Int64Value(result["production_coordinator_invocations"],"entries")!=27||Int64Value(result["external_target_effects"],"effects")!=0||Int64Value(result["effect_observations"],"observations")!=170||Int64Value(result["boundary_passed"],"boundary_passed")!=11||Int64Value(result["boundary_failed"],"boundary_failed")!=0||Int64Value(result["boundary_production_entries"],"boundary_entries")!=0||Int64Value(result["boundary_save_dispatch_count"],"boundary_save")!=0||Int64Value(result["boundary_external_target_effects"],"boundary_effects")!=0)throw new UID0002PAV6RejectedException("TR6-PA private result mismatch","Transcript");}else if(mode=="LegacyWitness"){ExactKeys(result,new string[]{"kind","outcome","scope","transport_calls","forged","public_entry_sha_before","public_entry_sha_after","module_restored"},"legacy-result");if(Str(result["kind"],"kind")!="LegacyWitness"||Str(result["outcome"],"legacy outcome")!="FORGED_ACCEPTED"||Str(result["scope"],"scope")!="Production"||Int64Value(result["transport_calls"],"transport")!=0||!BoolValue(result["forged"],"forged")||Str(result["public_entry_sha_before"],"before")!=Str(result["public_entry_sha_after"],"after")||!BoolValue(result["module_restored"],"restored"))throw new UID0002PAV6RejectedException("TR6-PA legacy witness mismatch","Transcript");}else{ExactKeys(result,new string[]{"kind","status","save_dispatch_count","transport_calls","external_target_effects","session"},"production-result");if(Str(result["kind"],"kind")!="Production")throw new UID0002PAV6RejectedException("TR6-PA production result mismatch","Transcript");}return root;}

  static UID0002PAV6Transcript RunIsolated(string mode){VerifySelf();int fences;string sourceSha;string payload=ReadPackage(out fences,out sourceSha);string apiSha=CurrentApiSHA256(),methodsSha=CurrentMethodManifestSHA256(),assemblySha=CurrentAssemblySHA256();string executable=Path.Combine(Environment.SystemDirectory,"WindowsPowerShell","v1.0","powershell.exe");if(!File.Exists(executable))throw new UID0002PAV6RejectedException("PK6-PA exact Windows PowerShell executable absent","Start");string executableSha=FileSha256(executable),nonce=Guid.NewGuid().ToString("N");string beforeTarget=FileTuple(CanonicalDatabase);bool beforeJournal=File.Exists(CanonicalDatabase+".uid0002pa-v4.journal"),beforeBackup=File.Exists(CanonicalDatabase+".uid0002pa-v4.backup");Process p=new Process();int pid=0;long generation=0;bool retired=true;string output=null,error=null;Exception failure=null;try{ProcessStartInfo i=new ProcessStartInfo(executable,"-NoLogo -NoProfile -NonInteractive -ExecutionPolicy Bypass -Command -");i.UseShellExecute=false;i.CreateNoWindow=true;i.RedirectStandardInput=true;i.RedirectStandardOutput=true;i.RedirectStandardError=true;p.StartInfo=i;if(!p.Start())throw new UID0002PAV6RejectedException("PK6-PA isolated child start failed","Start");pid=p.Id;generation=p.StartTime.ToUniversalTime().Ticks;Task<string> stdout=Task.Factory.StartNew(delegate{return p.StandardOutput.ReadToEnd();});Task<string> stderr=Task.Factory.StartNew(delegate{return p.StandardError.ReadToEnd();});p.StandardInput.Write(BuildChildProgram(payload,mode,nonce,executableSha,sourceSha,apiSha,methodsSha,assemblySha));p.StandardInput.Close();if(!p.WaitForExit(300000))throw new TimeoutException("PK6-PA isolated child timeout");Task.WaitAll(new Task[]{stdout,stderr});output=stdout.Result;error=stderr.Result;if(p.ExitCode!=0||error.Length!=0)throw new InvalidOperationException("PK6-PA isolated child failure: "+error);}
    catch(Exception ex){failure=ex;}
    finally{if(pid!=0){try{if(!p.HasExited){p.Kill();p.WaitForExit(30000);}}catch(Exception cleanup){if(failure==null)failure=cleanup;}retired=false;try{Process q=Process.GetProcessById(pid);try{retired=q.StartTime.ToUniversalTime().Ticks!=generation;}finally{q.Dispose();}}catch(ArgumentException){retired=true;}catch{retired=false;}}p.Dispose();}
    if(!retired)throw new UID0002PAV6RejectedException("PK6-PA exact child generation not retired","Retirement",pid,generation,false,0,0,0,0,0,1);if(failure!=null)throw new UID0002PAV6RejectedException(failure.Message,"Child",pid,generation,true,0,0,0,0,0,1);if(output==null||output.Length==0||output.IndexOf('\r')>=0||output.IndexOf('\n')>=0)throw new UID0002PAV6RejectedException("TR6-PA expected exactly one nonblank stdout record","Transcript",pid,generation,true,0,0,0,0,0,1);string resultJson,resultSha,session,outcome;long saves,transports,external,mcp,ida,fileEffects;ParseTranscript(output,mode,nonce,pid,generation,executableSha,sourceSha,apiSha,methodsSha,assemblySha,out resultJson,out resultSha,out session,out outcome,out saves,out transports,out external,out mcp,out ida,out fileEffects);string afterTarget=FileTuple(CanonicalDatabase);bool afterJournal=File.Exists(CanonicalDatabase+".uid0002pa-v4.journal"),afterBackup=File.Exists(CanonicalDatabase+".uid0002pa-v4.backup");if(mode!="Production"&&(beforeTarget!=afterTarget||beforeJournal!=afterJournal||beforeBackup!=afterBackup||external!=0||mcp!=0||ida!=0||fileEffects!=0))throw new UID0002PAV6RejectedException("RC6-PA independent no-effect receipt mismatch","Receipt",pid,generation,true,saves,transports,fileEffects,mcp,ida,1);return new UID0002PAV6Transcript(mode,output,Sha256(output),resultJson,resultSha,nonce,1,pid,generation,executableSha,true,true,ExpectedPayloadSHA256,sourceSha,apiSha,methodsSha,assemblySha,ExpectedPublicEntrySHA256,ExpectedFixtureEntrySHA256,CanonicalDatabase,session,outcome,saves,transports,external,mcp,ida,fileEffects,beforeTarget,afterTarget,beforeJournal,afterJournal,beforeBackup,afterBackup);}

  public static UID0002PAV6Attestation InspectPackage(){VerifySelf();int fences;string source;ReadPackage(out fences,out source);return new UID0002PAV6Attestation(ReportPath,ExpectedPayloadSHA256,source,CurrentApiSHA256(),CurrentMethodManifestSHA256(),CurrentAssemblySHA256(),ExpectedPublicEntrySHA256,ExpectedFixtureEntrySHA256,fences,HasMutableHostFields());}
  public static UID0002PAV6Transcript InvokeProduction(){VerifySelf();return RunIsolated("Production");}
  public static UID0002PAV6Transcript InvokePrivateFixtures(){VerifySelf();return RunIsolated("PrivateFixtures");}
  public static UID0002PAV6Transcript InvokeLegacyWitness(){VerifySelf();return RunIsolated("LegacyWitness");}
  public static UID0002PAV6ProbeReceipt InvokeIdentityProbe(){VerifySelf();int workers=8,iterations=64;int fences;string source;ReadPackage(out fences,out source);byte[] authority=new UTF8Encoding(false,true).GetBytes(source),mutated=(byte[])authority.Clone();string expected=Sha256(authority);ManualResetEventSlim gate=new ManualResetEventSlim(false);Task[] tasks=new Task[workers+1];for(int w=0;w<workers;w++)tasks[w]=Task.Factory.StartNew(delegate{gate.Wait();for(int n=0;n<iterations;n++)if(Sha256(authority)!=expected)throw new InvalidOperationException("CP6-PA authority bytes changed under concurrency");});tasks[workers]=Task.Factory.StartNew(delegate{gate.Wait();for(int n=0;n<iterations;n++)mutated[n%mutated.Length]^=1;});gate.Set();Task.WaitAll(tasks);bool rejected=Sha256(mutated)!=expected;gate.Dispose();if(!rejected)throw new UID0002PAV6RejectedException("CP6-PA mutated authority copy accepted","Concurrency");return new UID0002PAV6ProbeReceipt(workers,iterations,true,true,expected);}
}
'@
    $uid0002paV6Utf8=[Text.UTF8Encoding]::new($false,$true)
    $uid0002paV6Normalized=[regex]::Replace($source,'(?m)^(  public const string Expected(?:Source|Api|MethodManifest|Assembly|PublicEntry|FixtureEntry)SHA256=")[^"]+(";)$','$1__NORMALIZED__$2')
    $uid0002paV6Hasher=[Security.Cryptography.SHA256]::Create();try{$uid0002paV6SourceSha=([BitConverter]::ToString($uid0002paV6Hasher.ComputeHash($uid0002paV6Utf8.GetBytes($uid0002paV6Normalized)))).Replace('-','')}finally{$uid0002paV6Hasher.Dispose()}
    if($uid0002paV6SourceSha-cne'__UID0002PA_V6_SOURCE_SHA256__'){throw 'CP6-PA initializer source hash mismatch'}
    Microsoft.PowerShell.Utility\Add-Type -TypeDefinition $source -Language CSharp -ReferencedAssemblies @('System.dll','System.Core.dll','System.Web.Extensions.dll') -ErrorAction Stop
    $uid0002paV6Attestation=[UID0002PAV6IsolatedHost]::InspectPackage()
    if($uid0002paV6Attestation.SourceSHA256-cne$uid0002paV6SourceSha){throw 'CP6-PA initializer/host source identity mismatch'}
    Remove-Variable source,uid0002paV6Utf8,uid0002paV6Normalized,uid0002paV6Hasher,uid0002paV6SourceSha,uid0002paV6Attestation -ErrorAction SilentlyContinue
}

Initialize-UID0002PAV6IsolatedAuthority

function Invoke-UID0002PAClosedTransaction {
    [CmdletBinding()]param([Parameter(ValueFromRemainingArguments=$true)][object[]]$RejectedArguments)
    if($RejectedArguments.Count-ne0-or$args.Count-ne0){throw 'CT6-PA public entry accepts exactly zero arguments'}
    $uid0002paV6Current=(Microsoft.PowerShell.Core\Get-Command Invoke-UID0002PAClosedTransaction -CommandType Function).ScriptBlock
    $uid0002paV6Utf8=[Text.UTF8Encoding]::new($false,$true);$uid0002paV6Hasher=[Security.Cryptography.SHA256]::Create();try{$uid0002paV6Sha=([BitConverter]::ToString($uid0002paV6Hasher.ComputeHash($uid0002paV6Utf8.GetBytes([string]$uid0002paV6Current)))).Replace('-','')}finally{$uid0002paV6Hasher.Dispose()}
    if($uid0002paV6Sha-cne[UID0002PAV6IsolatedHost]::ExpectedPublicEntrySHA256){throw 'CP6-PA public wrapper hash mismatch'}
    [UID0002PAV6IsolatedHost]::InvokeProduction()
}

function Invoke-UID0002PAHostileStaticFixtures {
    [CmdletBinding()]param([Parameter(ValueFromRemainingArguments=$true)][object[]]$RejectedArguments)
    if($RejectedArguments.Count-ne0-or$args.Count-ne0){throw 'CT6-PA private fixture entry accepts exactly zero arguments'}
    $uid0002paV6Current=(Microsoft.PowerShell.Core\Get-Command Invoke-UID0002PAHostileStaticFixtures -CommandType Function).ScriptBlock
    $uid0002paV6Utf8=[Text.UTF8Encoding]::new($false,$true);$uid0002paV6Hasher=[Security.Cryptography.SHA256]::Create();try{$uid0002paV6Sha=([BitConverter]::ToString($uid0002paV6Hasher.ComputeHash($uid0002paV6Utf8.GetBytes([string]$uid0002paV6Current)))).Replace('-','')}finally{$uid0002paV6Hasher.Dispose()}
    if($uid0002paV6Sha-cne[UID0002PAV6IsolatedHost]::ExpectedFixtureEntrySHA256){throw 'CP6-PA fixture wrapper hash mismatch'}
    [UID0002PAV6IsolatedHost]::InvokePrivateFixtures()
}

function Invoke-UID0002PAV6BoundaryHostiles {
    [CmdletBinding()]param()
    $uid0002paV6Rows=[Collections.Generic.List[object]]::new();$uid0002paV6Att=[UID0002PAV6IsolatedHost]::InspectPackage();if($uid0002paV6Att.MutableHostFields-or$uid0002paV6Att.FenceCount-ne11){throw 'HF6-PA package attestation mismatch'}
    $uid0002paV6Legacy=[UID0002PAV6IsolatedHost]::InvokeLegacyWitness();if($uid0002paV6Legacy.Outcome-cne'LEGACY_FORGED_ACCEPTED_WITNESSED'-or-not$uid0002paV6Legacy.ExactChildRetired){throw 'HF6-PA legacy witness mismatch'};$uid0002paV6Rows.Add([pscustomobject]@{Label='LegacyV5SharedCoordinatorWitness';Result='FORGED_ACCEPTED_WITNESSED';ChildPID=$uid0002paV6Legacy.ChildPID;Retired=$uid0002paV6Legacy.ExactChildRetired})
    $uid0002paV6Private=Invoke-UID0002PAHostileStaticFixtures;if($uid0002paV6Private.Outcome-cne'PRIVATE_FIXTURES_PASSED'-or$uid0002paV6Private.ExternalTargetEffects-ne0-or-not$uid0002paV6Private.ExactChildRetired){throw 'HF6-PA bounded private-core result mismatch'};$uid0002paV6Rows.Add([pscustomobject]@{Label='BoundedPrivateProductionCore';Result='PASSED';ChildPID=$uid0002paV6Private.ChildPID;Retired=$uid0002paV6Private.ExactChildRetired})
    $uid0002paV6Probe=[UID0002PAV6IsolatedHost]::InvokeIdentityProbe();if(-not$uid0002paV6Probe.AuthorityStable-or-not$uid0002paV6Probe.MutatedCopyRejected){throw 'HF6-PA concurrent identity probe mismatch'};$uid0002paV6Rows.Add([pscustomobject]@{Label='SynchronizedAuthorityMutation';Result='REJECTED';Workers=$uid0002paV6Probe.Workers;Iterations=$uid0002paV6Probe.Iterations})
    $uid0002paV6Saved=(Microsoft.PowerShell.Core\Get-Command Invoke-UID0002PAClosedTransaction -CommandType Function).ScriptBlock;try{Set-Item -LiteralPath Function:\global:Invoke-UID0002PAClosedTransaction -Value {throw 'FORGED-FUNCTION'} -Force;$uid0002paV6Label=$null;try{&$uid0002paV6Saved}catch{$uid0002paV6Label=$_.Exception.Message};if($uid0002paV6Label-cne'CP6-PA public wrapper hash mismatch'){throw "HF6-PA wrapper replacement mismatch: $uid0002paV6Label"};$uid0002paV6Rows.Add([pscustomobject]@{Label='WrapperReplacementBeforeHost';Result=$uid0002paV6Label})}finally{Set-Item -LiteralPath Function:\global:Invoke-UID0002PAClosedTransaction -Value $uid0002paV6Saved -Force}
    $uid0002paV6Before=(Microsoft.PowerShell.Core\Get-Command Invoke-UID0002PAClosedTransaction -CommandType Function).ScriptBlock.ToString();$uid0002paV6Module=(Microsoft.PowerShell.Core\Get-Command Invoke-UID0002PAClosedTransaction -CommandType Function).ScriptBlock.Module;if($null-ne$uid0002paV6Module){$uid0002paV6Old=$uid0002paV6Module.SessionState.PSVariable.Get('sharedCoordinator');$uid0002paV6Module.SessionState.PSVariable.Set('sharedCoordinator',{throw 'FORGED-V6'});try{$null=[UID0002PAV6IsolatedHost]::InvokeIdentityProbe()}finally{if($null-eq$uid0002paV6Old){$uid0002paV6Module.SessionState.PSVariable.Remove('sharedCoordinator')}else{$uid0002paV6Module.SessionState.PSVariable.Set('sharedCoordinator',$uid0002paV6Old.Value)}}};$uid0002paV6After=(Microsoft.PowerShell.Core\Get-Command Invoke-UID0002PAClosedTransaction -CommandType Function).ScriptBlock.ToString();if($uid0002paV6Before-cne$uid0002paV6After){throw 'HF6-PA TOCTOU wrapper identity drift'};$uid0002paV6Rows.Add([pscustomobject]@{Label='ModuleTOCTOUNonAuthority';Result='STRUCTURALLY_PREVENTED'})
    $uid0002paV6Reinit=$null;try{Initialize-UID0002PAV6IsolatedAuthority}catch{$uid0002paV6Reinit=$_.Exception.Message};if($uid0002paV6Reinit-cne'CP6-PA preloaded authoritative host type refused'){throw 'HF6-PA preloaded type rejection mismatch'};$uid0002paV6Rows.Add([pscustomobject]@{Label='PreloadedHostRejected';Result=$uid0002paV6Reinit})
    [pscustomobject]@{Passed=[long]$uid0002paV6Rows.Count;Failed=0L;PayloadSHA256=$uid0002paV6Att.PayloadSHA256;SourceSHA256=$uid0002paV6Att.SourceSHA256;ApiSHA256=$uid0002paV6Att.ApiSHA256;MethodManifestSHA256=$uid0002paV6Att.MethodManifestSHA256;AssemblySHA256=$uid0002paV6Att.AssemblySHA256;PublicEntrySHA256=$uid0002paV6Att.PublicEntrySHA256;FixtureEntrySHA256=$uid0002paV6Att.FixtureEntrySHA256;LegacyWitness=$uid0002paV6Legacy;PrivateFixtures=$uid0002paV6Private;Rows=@($uid0002paV6Rows)}
}
~~~

## Removed Block R021

- SHA256: `1E38AFA7E74648B3C33F30DB8D65E5D6D28C1C8FD07D2D6029622F249172AA95`
- Language: `powershell`
- Bytes: `16919`
- First recovered timestamp: `2026-08-09T15:30:56.412Z`
- Session provenance: rollout-2026-08-08T17-46-23-019fe357-64cc-7ca3-ad27-c9c336afc6af.jsonl line 5673 (2026-08-09T15:30:56.412Z); rollout-2026-08-08T17-46-23-019fe357-64cc-7ca3-ad27-c9c336afc6af.jsonl line 5674 (2026-08-09T15:30:56.800Z)

~~~powershell
function Assert-UID0002PAExactSaveRequest {
    param([Parameter(Mandatory=$true)][string]$RequestJson,[Parameter(Mandatory=$true)][string]$Database,[Parameter(Mandatory=$true)][string]$CanonicalPath)
    $request=Get-UID0002PARequestIdentity $RequestJson 'SV2-PA exact save request';$args=$request.Parsed.params.arguments
    if([string]$request.Parsed.method -cne 'tools/call' -or [string]$request.Parsed.params.name -cne 'idb_save' -or
        (@($args.PSObject.Properties.Name|Sort-Object)-join '|') -cne 'database|path' -or
        -not (Test-UID0002PAJsonString $args.database) -or -not (Test-UID0002PAJsonString $args.path) -or
        [string]$args.database -cne $Database -or [System.IO.Path]::GetFullPath([string]$args.path) -ine [System.IO.Path]::GetFullPath($CanonicalPath)){
        throw 'SV2-PA exact save request mismatch'
    }
    $request
}

function Resolve-UID0002PASaveTransportOutcome {
    param(
        [Parameter(Mandatory=$true)][string]$RequestJson,
        [Parameter(Mandatory=$true)][ValidateSet('Response','Timeout','Disconnect','Malformed','ThrownTransport','MissingResponse')][string]$ObservedTransport,
        [AllowNull()][string]$RawResponseJson,
        [AllowNull()][string]$ThrownFailure)
    $request=Get-UID0002PARequestIdentity $RequestJson 'SV2-PA classified save'
    if($ObservedTransport -ne 'Response'){
        return [pscustomobject][ordered]@{TransportClass='Indeterminate';Observation=$ObservedTransport;Failure=if($ThrownFailure){$ThrownFailure}else{$ObservedTransport};Envelope=$null}
    }
    try{
        if([string]::IsNullOrWhiteSpace($RawResponseJson)){throw 'SV2-PA missing response body'}
        Assert-UID0002PARawJsonUnique $RawResponseJson 'SV2-PA save response'
        $response=$RawResponseJson|ConvertFrom-Json -ErrorAction Stop
        $keys=@($response.PSObject.Properties.Name|Sort-Object)
        if(-not (Test-UID0002PAJsonString $response.jsonrpc) -or [string]$response.jsonrpc -cne '2.0' -or
            $null -eq $response.id -or $response.id.GetType().FullName -cne $request.IdType -or -not [object]::Equals($response.id,$request.Id)){
            throw 'SV2-PA foreign response identity'
        }
        if(($keys-join '|') -ceq 'error|id|jsonrpc'){
            return [pscustomobject][ordered]@{TransportClass='Indeterminate';Observation='JsonRpcError';Failure=($response.error|ConvertTo-Json -Depth 12 -Compress);Envelope=$response}
        }
        if(($keys-join '|') -cne 'id|jsonrpc|result' -or $null -eq $response.result -or
            -not $response.result.PSObject.Properties['isError'] -or -not (Test-UID0002PAJsonBoolean $response.result.isError)){
            throw 'SV2-PA malformed native result'
        }
        if($response.result.isError -eq $true){
            return [pscustomobject][ordered]@{TransportClass='DeterminateFailure';Observation='ToolIsError';Failure='idb_save result isError';Envelope=$response}
        }
        $save=$response.result.structuredContent
        if($null -eq $save -or -not $save.PSObject.Properties['ok'] -or -not (Test-UID0002PAJsonBoolean $save.ok) -or
            -not $save.PSObject.Properties['error'] -or -not (Test-UID0002PAJsonString $save.error) -or
            -not $save.PSObject.Properties['path'] -or -not (Test-UID0002PAJsonString $save.path)){
            throw 'SV2-PA malformed native structuredContent'
        }
        $canonical=[System.IO.Path]::GetFullPath([string]$request.Parsed.params.arguments.path)
        if($save.ok -eq $true -and [string]::IsNullOrWhiteSpace($save.error) -and [System.IO.Path]::GetFullPath($save.path) -ieq $canonical){
            return [pscustomobject][ordered]@{TransportClass='DeterminateSuccess';Observation='Response';Failure=$null;Envelope=$response}
        }
        if($save.ok -eq $false -and -not [string]::IsNullOrWhiteSpace($save.error)){
            return [pscustomobject][ordered]@{TransportClass='DeterminateFailure';Observation='Response';Failure=[string]$save.error;Envelope=$response}
        }
        return [pscustomobject][ordered]@{TransportClass='Indeterminate';Observation='ContradictoryResponse';Failure='SV2-PA contradictory save result';Envelope=$response}
    }catch{
        [pscustomobject][ordered]@{TransportClass='Indeterminate';Observation='MalformedOrForeignResponse';Failure=$_.Exception.Message;Envelope=$null}
    }
}

function Get-UID0002PAAttemptAuthorityText {
    param($Attempt)
    ([ordered]@{TransactionId=$Attempt.TransactionId;Database=$Attempt.Database;Generation=$Attempt.TransactionGeneration;CanonicalPath=$Attempt.CanonicalPath
        SaveRequestSHA256=$Attempt.SaveRequestSHA256;SaveDispatchCount=$Attempt.SaveDispatchCount;TransportClass=$Attempt.TransportClass
        DurableJournalSHA256=$Attempt.DurableJournalSHA256;FinalReadbackSHA256=$Attempt.FinalReadbackSHA256;P0=$Attempt.P0;B0=$Attempt.B0
        Candidate=$Attempt.Candidate;Status=$Attempt.Status}|ConvertTo-Json -Depth 30 -Compress)
}
function Set-UID0002PAAttemptAuthorityHmac { param($Attempt,[string]$EvidenceKey) $Attempt.AuthorityHmac=Get-UID0002PAEvidenceHmac (Get-UID0002PAAttemptAuthorityText $Attempt) $EvidenceKey }
function Assert-UID0002PAAttemptAuthorityHmac {
    param($Attempt,[string]$EvidenceKey)
    if([string]::IsNullOrWhiteSpace([string]$Attempt.AuthorityHmac) -or [string]$Attempt.AuthorityHmac -cne (Get-UID0002PAEvidenceHmac (Get-UID0002PAAttemptAuthorityText $Attempt) $EvidenceKey)){
        throw 'SV2-PA closed attempt HMAC mismatch'
    }
}
function Get-UID0002PARetirementAuthorityText { param($Authority) ([ordered]@{Proof=$Authority.Proof;TransactionId=$Authority.TransactionId;Role=$Authority.Role}|ConvertTo-Json -Depth 40 -Compress) }
function Assert-UID0002PARetirementAuthorityHmac {
    param($Authority,[string]$EvidenceKey)
    if([string]$Authority.AuthorityHmac -cne (Get-UID0002PAEvidenceHmac (Get-UID0002PARetirementAuthorityText $Authority) $EvidenceKey)){
        throw 'RT2-PA closed retirement HMAC mismatch'
    }
}

function Get-UID0002PAChangedDiskClassification {
    param($Attempt,$RetirementAuthority,[string]$EvidenceKey)
    Assert-UID0002PAAttemptAuthorityHmac $Attempt $EvidenceKey
    Assert-UID0002PARetirementAuthorityHmac $RetirementAuthority $EvidenceKey
    $proof=$RetirementAuthority.Proof
    Assert-UID0002PATuple $proof.ClosedTupleB $proof.ClosedTupleA 'CS2-PA stable closed candidate'
    if([string]$proof.Role -cne 'Transaction' -or [string]$proof.Database -cne [string]$Attempt.Database -or
        [string]$proof.Generation -cne [string]$Attempt.TransactionGeneration){throw 'CS2-PA retirement identity mismatch'}
    $candidate=Get-UID0002PATupleCopy $proof.ClosedTupleA
    $samePath=[System.IO.Path]::GetFullPath($candidate.FullPath) -ieq [System.IO.Path]::GetFullPath($Attempt.CanonicalPath)
    if(-not $samePath -or $candidate.Length -le 0 -or [string]$candidate.SHA256 -notmatch '^[0-9A-F]{64}$'){throw 'CS2-PA foreign/noncanonical candidate'}
    $sameLength=[long]$candidate.Length -eq [long]$Attempt.P0.Length;$sameHash=[string]$candidate.SHA256 -ceq [string]$Attempt.P0.SHA256
    $sameTime=[long]$candidate.LastWriteTimeUtcTicks -eq [long]$Attempt.P0.LastWriteTimeUtcTicks
    if($sameLength -and $sameHash -and $sameTime){return [pscustomobject]@{DiskClass='P0';RequiredVerifier='P0Verifier';Candidate=$candidate}}
    if($sameLength -and $sameHash -and -not $sameTime){throw 'CS2-PA timestamp-only candidate rejected'}
    if([int]$Attempt.SaveDispatchCount -ne 1 -or [string]$Attempt.DurableState -cne 'SAVE_DISPATCHED_DURABLE' -or
        [string]::IsNullOrWhiteSpace([string]$Attempt.FinalReadbackSHA256)){throw 'CS2-PA missing transaction-attributable byte/state authority'}
    if([string]$Attempt.TransportClass -cne 'DeterminateSuccess'){throw 'CS2-PA changed disk without determinate save success'}
    $Attempt.Candidate=$candidate;$Attempt.Status='CHANGED_PENDING_LITERAL_FINAL_VERIFIER';Set-UID0002PAAttemptAuthorityHmac $Attempt $EvidenceKey
    [pscustomobject]@{DiskClass='CHANGED_PENDING_LITERAL_FINAL_VERIFIER';RequiredVerifier='S1Verifier';Candidate=$candidate}
}

function Assert-UID0002PAFinalSemanticFailureLabel {
    param([Parameter(Mandatory=$true)][string]$Failure)
    $allowed=@(
        '^RQ-PA S1Verifier (analyze|xref|exact item|collision|renamed identity|proposed-name collision|legacy candidate-type|prestate UDT collision|exact declared UDT layout|Config shell|request/response catalog keys|exact active returned-session)',
        '^RQ-PA exact result mismatch: S1Verifier ',
        '^RQ-PA (byte rows|byte address/size|byte error|byte count|byte hash|comment row|comment address|comment channel|candidate type index)'
    )
    if(@($allowed|Where-Object{$Failure -match $_}).Count -ne 1){throw 'VR2-PA failure is not literal Final-oracle semantic mismatch'}
    return $true
}

function New-UID0002PAFailedVerifierEvidence {
    param($Requests,$Responses,$RoleBinding,$AttestationState,[string]$ControllerEvidenceKey)
    if([string]$RoleBinding.Role -cne 'S1Verifier'){throw 'VR2-PA failed readback is not S1Verifier'}
    $expected=New-UID0002PAReadbackCatalog $RoleBinding S1Verifier;$required=@($expected.Keys)
    if((@($Requests.Keys|Sort-Object)-join '|') -cne (@($required|Sort-Object)-join '|') -or (@($Responses.Keys|Sort-Object)-join '|') -cne (@($required|Sort-Object)-join '|')){throw 'VR2-PA failed catalog key mismatch'}
    foreach($key in $required){
        $actual=Get-UID0002PARequestIdentity ([string]$Requests[$key]) "VR2-PA $key actual";$literal=Get-UID0002PARequestIdentity ([string]$expected[$key]) "VR2-PA $key literal"
        if($actual.SHA256 -cne $literal.SHA256){throw "VR2-PA failed request drift $key"}
        $null=Assert-UID0002PAJsonRpcResponse $Responses[$key] ([string]$Requests[$key]) "VR2-PA $key correlation" $true
    }
    try{$readback=Assert-UID0002PAReadbackCatalog $Requests $Responses $RoleBinding $AttestationState S1Verifier;return [pscustomobject]@{Passed=$true;Readback=$readback}}
    catch{$failure=$_.Exception.Message}
    $null=Assert-UID0002PAFinalSemanticFailureLabel $failure
    $requestProjection=[ordered]@{};$responseProjection=[ordered]@{}
    foreach($key in $required){$requestProjection[$key]=Get-UID0002PATextSha256 ([string]$Requests[$key]);$responseProjection[$key]=Get-UID0002PATextSha256 ($Responses[$key]|ConvertTo-Json -Depth 50 -Compress)}
    $evidence=[pscustomobject][ordered]@{Passed=$false;FailureClass='LiteralFinalOracleSemanticMismatch';Phase='S1Verifier';Role='S1Verifier';Database=[string]$RoleBinding.Database
        WorkerGeneration=[string]$AttestationState.RoleWorkers[[string]$RoleBinding.Database].Generation;ExactFailure=$failure;Requests=$Requests;Responses=$Responses
        RequestCatalogSHA256=Get-UID0002PATextSha256 ($requestProjection|ConvertTo-Json -Depth 20 -Compress)
        ResponseCatalogSHA256=Get-UID0002PATextSha256 ($responseProjection|ConvertTo-Json -Depth 20 -Compress);EvidenceHmac=$null}
    $projection=[ordered]@{FailureClass=$evidence.FailureClass;Phase=$evidence.Phase;Role=$evidence.Role;Database=$evidence.Database;WorkerGeneration=$evidence.WorkerGeneration;ExactFailure=$evidence.ExactFailure;RequestCatalogSHA256=$evidence.RequestCatalogSHA256;ResponseCatalogSHA256=$evidence.ResponseCatalogSHA256}
    $evidence.EvidenceHmac=Get-UID0002PAEvidenceHmac ($projection|ConvertTo-Json -Compress) $ControllerEvidenceKey
    $evidence
}

function Assert-UID0002PAFailedVerifierEvidence {
    param($Evidence,$RoleBinding,[string]$ControllerEvidenceKey)
    if($Evidence.Passed -ne $false -or [string]$Evidence.FailureClass -cne 'LiteralFinalOracleSemanticMismatch' -or
        [string]$Evidence.Role -cne 'S1Verifier' -or [string]$Evidence.Database -cne [string]$RoleBinding.Database){throw 'VR2-PA failed evidence header mismatch'}
    $null=Assert-UID0002PAFinalSemanticFailureLabel ([string]$Evidence.ExactFailure)
    $projection=[ordered]@{FailureClass=$Evidence.FailureClass;Phase=$Evidence.Phase;Role=$Evidence.Role;Database=$Evidence.Database;WorkerGeneration=$Evidence.WorkerGeneration;ExactFailure=$Evidence.ExactFailure;RequestCatalogSHA256=$Evidence.RequestCatalogSHA256;ResponseCatalogSHA256=$Evidence.ResponseCatalogSHA256}
    if([string]$Evidence.EvidenceHmac -cne (Get-UID0002PAEvidenceHmac ($projection|ConvertTo-Json -Compress) $ControllerEvidenceKey)){throw 'VR2-PA failed evidence HMAC mismatch'}
    $true
}

function Initialize-UID0002PAHandleInspector {
    if('UID0002PAHandleInspector' -as [type]){return}
    Add-Type -TypeDefinition @'
using System;
using System.Runtime.InteropServices;
using System.Text;
using Microsoft.Win32.SafeHandles;
public static class UID0002PAHandleInspector {
  [StructLayout(LayoutKind.Sequential)] public struct FILETIME { public uint Low; public uint High; }
  [StructLayout(LayoutKind.Sequential)] public struct INFO { public uint Attr; public FILETIME Creation; public FILETIME Access; public FILETIME Write; public uint Volume; public uint SizeHigh; public uint SizeLow; public uint Links; public uint IndexHigh; public uint IndexLow; }
  [DllImport("kernel32.dll", SetLastError=true)] static extern bool GetFileInformationByHandle(SafeFileHandle h, out INFO info);
  [DllImport("kernel32.dll", CharSet=CharSet.Unicode, SetLastError=true)] static extern uint GetFinalPathNameByHandle(SafeFileHandle h, StringBuilder path, uint size, uint flags);
  public static long LastWriteTicks(SafeFileHandle h) { INFO i; if(!GetFileInformationByHandle(h,out i)) throw new System.ComponentModel.Win32Exception(); long fileTime=((long)i.Write.High << 32) | i.Write.Low; return DateTime.FromFileTimeUtc(fileTime).Ticks; }
  public static string FinalPath(SafeFileHandle h) { var b=new StringBuilder(32768); uint n=GetFinalPathNameByHandle(h,b,(uint)b.Capacity,0); if(n==0 || n>=b.Capacity) throw new System.ComponentModel.Win32Exception(); string p=b.ToString(); if(p.StartsWith(@"\\?\UNC\")) return @"\\"+p.Substring(8); if(p.StartsWith(@"\\?\")) return p.Substring(4); return p; }
}
'@
}

function Get-UID0002PAHeldHandleTuple {
    param([Parameter(Mandatory=$true)][System.IO.FileStream]$Stream,[Parameter(Mandatory=$true)][string]$ExpectedPath)
    Initialize-UID0002PAHandleInspector
    $path=[System.IO.Path]::GetFullPath([UID0002PAHandleInspector]::FinalPath($Stream.SafeFileHandle))
    if($path -ine [System.IO.Path]::GetFullPath($ExpectedPath)){throw 'RS2-PA held handle path mismatch'}
    $ticksA=[UID0002PAHandleInspector]::LastWriteTicks($Stream.SafeFileHandle);$lengthA=[long]$Stream.Length
    $sha=Get-UID0002PAStreamSha256 $Stream
    $ticksB=[UID0002PAHandleInspector]::LastWriteTicks($Stream.SafeFileHandle);$lengthB=[long]$Stream.Length
    if($ticksA -ne $ticksB -or $lengthA -ne $lengthB){throw 'RS2-PA held handle tuple changed during hash'}
    [pscustomobject][ordered]@{FullPath=$path;Length=$lengthB;LastWriteTimeUtcTicks=$ticksB;SHA256=$sha}
}

function New-UID0002PADurableAuthority {
    param([string]$CanonicalPath,[string]$TransactionId)
    $path=[System.IO.Path]::GetFullPath($CanonicalPath)+'.uid0002pa-save-authority.json'
    $stream=[System.IO.FileStream]::new($path,[System.IO.FileMode]::CreateNew,[System.IO.FileAccess]::ReadWrite,[System.IO.FileShare]::None)
    $record=[pscustomobject][ordered]@{Schema=1;UID='0002PA';TransactionId=$TransactionId;CanonicalPath=[System.IO.Path]::GetFullPath($CanonicalPath);SaveDispatchCount=0;State='PRE_SAVE';SaveRequestSHA256=$null;Database=$null;Terminal=$null}
    [pscustomobject]@{Path=$path;Stream=$stream;Record=$record}
}
function Write-UID0002PADurableAuthority {
    param($Authority)
    $json=$Authority.Record|ConvertTo-Json -Depth 12 -Compress;$bytes=(New-Object Text.UTF8Encoding($false)).GetBytes($json)
    $Authority.Stream.Position=0;$Authority.Stream.SetLength(0);$Authority.Stream.Write($bytes,0,$bytes.Length);$Authority.Stream.Flush($true)
    Get-UID0002PATextSha256 $json
}
function Set-UID0002PADurableSaveDispatched {
    param($Authority,$RequestIdentity,[string]$Database)
    if([int]$Authority.Record.SaveDispatchCount -ne 0 -or [string]$Authority.Record.State -cne 'PRE_SAVE'){throw 'DG-PA durable save retry/duplicate'}
    $Authority.Record.SaveDispatchCount=1;$Authority.Record.State='SAVE_DISPATCHED_DURABLE';$Authority.Record.SaveRequestSHA256=[string]$RequestIdentity.SHA256;$Authority.Record.Database=$Database
    Write-UID0002PADurableAuthority $Authority
}

function Assert-UID0002PAHostileThrow {
    param([Parameter(Mandatory=$true)][scriptblock]$Action,[Parameter(Mandatory=$true)][string]$ExpectedFailure)
    try{& $Action;throw "HOSTILE FIXTURE DID NOT FAIL: $ExpectedFailure"}
    catch{
        if($_.Exception.Message -like 'HOSTILE FIXTURE DID NOT FAIL:*'){throw}
        if([string]$_.Exception.Message -cne $ExpectedFailure){throw "HOSTILE FIXTURE WRONG FAILURE: expected=[$ExpectedFailure] actual=[$($_.Exception.Message)]"}
        return $true
    }
}
~~~

## Removed Block R022

- SHA256: `5416FD769F2143247F21827D787CC766C77556D6B18FB718AE6CA1903DB572E8`
- Language: `powershell`
- Bytes: `46953`
- First recovered timestamp: `2026-08-09T15:30:56.412Z`
- Session provenance: rollout-2026-08-08T17-46-23-019fe357-64cc-7ca3-ad27-c9c336afc6af.jsonl line 5673 (2026-08-09T15:30:56.412Z); rollout-2026-08-08T17-46-23-019fe357-64cc-7ca3-ad27-c9c336afc6af.jsonl line 5674 (2026-08-09T15:30:56.800Z)

~~~powershell
function Initialize-UID0002PANativeSealedTypes {
    if('UID0002PANativeSealedCore' -as [type]){return}
    Add-Type -TypeDefinition @'
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;
using Microsoft.Win32.SafeHandles;

public sealed class UID0002PAImmutableTuple {
  public string FullPath {get;private set;} public long Length {get;private set;}
  public long LastWriteTimeUtcTicks {get;private set;} public string SHA256 {get;private set;}
  public long VolumeSerial {get;private set;} public ulong FileIndex {get;private set;}
  public UID0002PAImmutableTuple(string p,long n,long t,string h,long v,ulong i){FullPath=Path.GetFullPath(p);Length=n;LastWriteTimeUtcTicks=t;SHA256=h;VolumeSerial=v;FileIndex=i;}
  public bool Same(UID0002PAImmutableTuple x){return x!=null&&String.Equals(FullPath,x.FullPath,StringComparison.OrdinalIgnoreCase)&&Length==x.Length&&LastWriteTimeUtcTicks==x.LastWriteTimeUtcTicks&&String.Equals(SHA256,x.SHA256,StringComparison.Ordinal)&&VolumeSerial==x.VolumeSerial&&FileIndex==x.FileIndex;}
  public bool SameBytes(UID0002PAImmutableTuple x){return x!=null&&Length==x.Length&&String.Equals(SHA256,x.SHA256,StringComparison.Ordinal);}
}

public sealed class UID0002PANativeSealedCore : IDisposable {
  [StructLayout(LayoutKind.Sequential)] struct FT {public uint Low;public uint High;}
  [StructLayout(LayoutKind.Sequential)] struct INFO {public uint Attr;public FT Creation;public FT Access;public FT Write;public uint Volume;public uint SizeHigh;public uint SizeLow;public uint Links;public uint IndexHigh;public uint IndexLow;}
  [DllImport("kernel32.dll",SetLastError=true)] static extern bool GetFileInformationByHandle(SafeFileHandle h,out INFO i);
  [DllImport("kernel32.dll",CharSet=CharSet.Unicode,SetLastError=true)] static extern uint GetFinalPathNameByHandle(SafeFileHandle h,StringBuilder p,uint n,uint f);
  [DllImport("kernel32.dll",SetLastError=true)] static extern bool SetFileTime(SafeFileHandle h,IntPtr c,IntPtr a,ref FT w);
  readonly string canonical,transaction,journalPath; readonly Dictionary<string,string> roles=new Dictionary<string,string>(StringComparer.Ordinal);
  FileStream journal; string schemaHash,planHash,moduleHash,state="CREATED",database,generation,listHash,runtimeHash; int saves,transports,retires,restores; bool retain=true;
  UID0002PAImmutableTuple p0,b0,dopen,dclosed,p1;
  public string State{get{return state;}} public string JournalPath{get{return journalPath;}} public int SaveDispatchCount{get{return saves;}}
  public int TransportCalls{get{return transports;}} public int RetireCalls{get{return retires;}} public int RestoreWrites{get{return restores;}}
  public bool JournalRetained{get{return retain;}} public UID0002PAImmutableTuple P0{get{return p0;}} public UID0002PAImmutableTuple B0{get{return b0;}}
  public UID0002PAImmutableTuple Dopen{get{return dopen;}} public UID0002PAImmutableTuple Dclosed{get{return dclosed;}} public UID0002PAImmutableTuple P1{get{return p1;}}
  public UID0002PANativeSealedCore(string path,string tx,string overridePath){canonical=Path.GetFullPath(path);transaction=tx;journalPath=String.IsNullOrEmpty(overridePath)?canonical+".uid0002pa-v3-authority.json":Path.GetFullPath(overridePath);journal=new FileStream(journalPath,FileMode.CreateNew,FileAccess.ReadWrite,FileShare.None);Write("CREATED",null);}
  static string Esc(string s){return (s??"").Replace("\\","\\\\").Replace("\"","\\\"").Replace("\r","\\r").Replace("\n","\\n");}
  static string Hash(string s){using(SHA256 h=SHA256.Create()){return BitConverter.ToString(h.ComputeHash(Encoding.UTF8.GetBytes(s))).Replace("-","");}}
  void Write(string next,string terminal){state=next;string j="{\"schema\":3,\"uid\":\"0002PA\",\"transaction\":\""+Esc(transaction)+"\",\"canonical\":\""+Esc(canonical)+"\",\"state\":\""+Esc(state)+"\",\"save_count\":"+saves+",\"database\":\""+Esc(database)+"\",\"generation\":\""+Esc(generation)+"\",\"list_sha256\":\""+Esc(listHash)+"\",\"runtime_sha256\":\""+Esc(runtimeHash)+"\",\"terminal\":\""+Esc(terminal)+"\"}";byte[] b=new UTF8Encoding(false).GetBytes(j);journal.Position=0;journal.SetLength(0);journal.Write(b,0,b.Length);journal.Flush(true);}
  static bool IsSha(string s){if(String.IsNullOrEmpty(s)||s.Length!=64)return false;for(int i=0;i<s.Length;i++){char c=s[i];if(!((c>='0'&&c<='9')||(c>='A'&&c<='F')))return false;}return true;}
  public void FreezeAuthority(string s,string p,string m){if(schemaHash!=null)throw new InvalidOperationException("NR3-PA authority already frozen");schemaHash=Hash(s);planHash=Hash(p);moduleHash=Hash(m);Write("AUTHORITY_FROZEN",null);}
  public void AssertAuthority(string s,string p,string m){if(schemaHash!=Hash(s)||planHash!=Hash(p)||moduleHash!=Hash(m))throw new InvalidOperationException("NR3-PA frozen authority drift");}
  public void FreezeRole(string r,string a){string h=Hash(a),old;if(roles.TryGetValue(r,out old)&&old!=h)throw new InvalidOperationException("NR3-PA frozen role authority drift");roles[r]=h;}
  public void AssertRole(string r,string a){string old;if(!roles.TryGetValue(r,out old)||old!=Hash(a))throw new InvalidOperationException("NR3-PA frozen role authority mismatch");}
  public void SetBackup(UID0002PAImmutableTuple pre,UID0002PAImmutableTuple backup){if(pre==null||backup==null||!pre.SameBytes(backup)||pre.LastWriteTimeUtcTicks!=backup.LastWriteTimeUtcTicks)throw new InvalidOperationException("BK3-PA held P0/B0 mismatch");p0=pre;b0=backup;Write("P0_B0_HELD_PROVEN",null);}
  public void RecordTransport(){checked{transports++;}} public void RecordRetire(){checked{retires++;}}
  public void BindPreSave(string db,string gen,string lh,string rh){if(state!="P0_B0_HELD_PROVEN"||String.IsNullOrEmpty(db)||String.IsNullOrEmpty(gen)||String.IsNullOrEmpty(lh)||String.IsNullOrEmpty(rh))throw new InvalidOperationException("SV3-PA incomplete immediate pre-save binding");database=db;generation=gen;listHash=lh;runtimeHash=rh;Write("IMMEDIATE_PRE_SAVE_BOUND",null);}
  public void ClaimSave(string db,string requestHash){if(saves!=0)throw new InvalidOperationException("SV3-PA durable global save already claimed");if(state!="IMMEDIATE_PRE_SAVE_BOUND"||database!=db||String.IsNullOrEmpty(requestHash))throw new InvalidOperationException("SV3-PA save lacks immediate bound pre-save attestation");saves=1;Write("SAVE_DISPATCHED_DURABLE",requestHash);}
  public void RecordDopen(UID0002PAImmutableTuple x){if(saves!=1||x==null)throw new InvalidOperationException("DS3-PA Dopen out of order");dopen=x;Write("DOPEN_OBSERVED",null);}
  public void RecordDclosed(UID0002PAImmutableTuple x,string transport){if(saves!=1||x==null)throw new InvalidOperationException("DS3-PA Dclosed out of order");dclosed=x;if(x.Same(p0)){Write("P0_VERIFIER_REQUIRED",transport);return;}if(x.SameBytes(p0)&&x.LastWriteTimeUtcTicks!=p0.LastWriteTimeUtcTicks)throw new InvalidOperationException("DS3-PA timestamp-only identity");if(transport!="DeterminateSuccess")throw new InvalidOperationException("DS3-PA changed output lacks determinate sole-save authority");p1=x;if(!dclosed.Same(p1))throw new InvalidOperationException("DS3-PA Dclosed/P1 mismatch");Write("P1_VERIFIER_REQUIRED",null);}
  public void MarkP0Verified(){if(state!="P0_VERIFIER_REQUIRED")throw new InvalidOperationException("VR3-PA P0 verifier out of order");Write("P0_VERIFIED",null);}
  public void MarkP1Verified(){if(state!="P1_VERIFIER_REQUIRED"||p1==null||!dclosed.Same(p1))throw new InvalidOperationException("VR3-PA P1 identity mismatch");Write("P1_VERIFIED",null);}
  public void MarkF1(string phase,string role,string failure,string requestHash,string responseHash,string db,string gen){if(state!="P1_VERIFIER_REQUIRED"||phase!="Final"||role!="S1Verifier"||db!=database||gen!=generation||!IsSha(requestHash)||!IsSha(responseHash)||String.IsNullOrEmpty(failure)||!failure.StartsWith("RQ-PA ",StringComparison.Ordinal))throw new InvalidOperationException("VR3-PA non-Final failure cannot authorize F1");Write("F1_RESTORE_REQUIRED",Hash(phase+"|"+role+"|"+failure+"|"+requestHash+"|"+responseHash+"|"+db+"|"+gen));}
  public void AuthorizeRestore(UID0002PAImmutableTuple dest,UID0002PAImmutableTuple backup){if(state!="F1_RESTORE_REQUIRED"||p1==null||!dest.Same(p1)||!backup.Same(b0))throw new InvalidOperationException("RS3-PA held P1/B0 authority mismatch");checked{restores++;}Write("RESTORE_WRITE_AUTHORIZED",null);}
  public void MarkRestored(UID0002PAImmutableTuple x){if(state!="RESTORE_WRITE_AUTHORIZED"||!x.Same(p0))throw new InvalidOperationException("RS3-PA restored P0 mismatch");Write("ROLLBACK_VERIFIER_REQUIRED",null);}
  public void MarkRollbackVerified(){if(state!="ROLLBACK_VERIFIER_REQUIRED")throw new InvalidOperationException("RS3-PA rollback verifier out of order");Write("RESTORED_P0_VERIFIED",null);}
  public void MarkNoSaveFailure(string code){if(saves!=0)throw new InvalidOperationException("NS3-PA no-save failure after save");retain=true;Write("NO_SAVE_UNRESOLVED",code);}
  public void CompleteNoSave(UID0002PAImmutableTuple now,UID0002PAImmutableTuple backup,bool cleanup,bool retired,bool verifier){if(saves!=0||!cleanup||!retired||!verifier||!now.Same(p0)||!backup.Same(b0))throw new InvalidOperationException("NS3-PA no-save closure incomplete");Write("NO_SAVE_P0_VERIFIED",null);journal.Dispose();journal=null;File.Delete(journalPath);retain=false;state="NO_SAVE_CLOSED";}
  public void MarkTerminal(string t){Write("TERMINAL",t);} public void Dispose(){if(journal!=null){journal.Dispose();journal=null;}}
  public static object InvokeAdapter(object adapter,string payload){if(adapter==null)throw new ArgumentNullException("adapter");MethodInfo selected=null;foreach(MethodInfo m in adapter.GetType().GetMethods()){if(m.Name=="InvokeReturnAsIs"&&m.GetParameters().Length==1){selected=m;break;}}if(selected==null)throw new MissingMethodException("bounded adapter lacks InvokeReturnAsIs");try{return selected.Invoke(adapter,new object[]{new object[]{payload}});}catch(TargetInvocationException e){throw e.InnerException;}}
  public static UID0002PAImmutableTuple ReadTuple(FileStream s,string expected){INFO i;if(!GetFileInformationByHandle(s.SafeFileHandle,out i))throw new Win32Exception();StringBuilder b=new StringBuilder(32768);uint n=GetFinalPathNameByHandle(s.SafeFileHandle,b,(uint)b.Capacity,0);if(n==0||n>=b.Capacity)throw new Win32Exception();string p=b.ToString();if(p.StartsWith(@"\\?\UNC\"))p=@"\\"+p.Substring(8);else if(p.StartsWith(@"\\?\"))p=p.Substring(4);p=Path.GetFullPath(p);if(!String.Equals(p,Path.GetFullPath(expected),StringComparison.OrdinalIgnoreCase))throw new InvalidOperationException("HS3-PA held path mismatch");long t=DateTime.FromFileTimeUtc(((long)i.Write.High<<32)|i.Write.Low).Ticks,len=((long)i.SizeHigh<<32)|i.SizeLow,old=s.Position;s.Position=0;string h;using(SHA256 q=SHA256.Create()){h=BitConverter.ToString(q.ComputeHash(s)).Replace("-","");}s.Position=old;INFO j;if(!GetFileInformationByHandle(s.SafeFileHandle,out j))throw new Win32Exception();long t2=DateTime.FromFileTimeUtc(((long)j.Write.High<<32)|j.Write.Low).Ticks,len2=((long)j.SizeHigh<<32)|j.SizeLow;if(t!=t2||len!=len2)throw new InvalidOperationException("HS3-PA held tuple changed during hash");return new UID0002PAImmutableTuple(p,len,t,h,(long)i.Volume,((ulong)i.IndexHigh<<32)|i.IndexLow);}
  public static void SetWriteTicks(FileStream s,long ticks){long f=new DateTime(ticks,DateTimeKind.Utc).ToFileTimeUtc();FT w=new FT();w.Low=(uint)(f&0xffffffff);w.High=(uint)((ulong)f>>32);if(!SetFileTime(s.SafeFileHandle,IntPtr.Zero,IntPtr.Zero,ref w))throw new Win32Exception();s.Flush(true);}
}
'@
}

function Assert-UID0002PANativeInteger {param($Value,[string]$Label)if(-not(Test-UID0002PAJsonInteger $Value)){throw "$Label native integer mismatch"}}
function Assert-UID0002PANativeBoolean {param($Value,[string]$Label)if(-not(Test-UID0002PAJsonBoolean $Value)){throw "$Label native Boolean mismatch"}}
function Assert-UID0002PANativeString {param($Value,[string]$Label)if(-not(Test-UID0002PAJsonString $Value)){throw "$Label native string mismatch"}}
function Assert-UID0002PANativeArray {param($Value,[string]$Label)if($Value-isnot[System.Array]){throw "$Label native array mismatch"}}

function Assert-UID0002PANativeRuntimeGraph {
  param($Runtime,$List,[string]$ExpectedDatabase,[string]$ExpectedCanonicalPath,[string]$Label)
  Assert-UID0002PANativeInteger $Runtime.schema_version "$Label runtime schema_version";if($Runtime.schema_version-ne1){throw "$Label runtime schema mismatch"}
  Assert-UID0002PANativeBoolean $Runtime.ok "$Label runtime ok";if($Runtime.ok-ne$true){throw "$Label runtime not ok"};Assert-UID0002PANativeArray $Runtime.errors "$Label runtime errors";if(@($Runtime.errors).Count-ne0){throw "$Label runtime errors nonempty"}
  Assert-UID0002PANativeString $Runtime.listener.role "$Label listener role";Assert-UID0002PANativeString $Runtime.listener.nonce "$Label listener nonce";Assert-UID0002PANativeString $Runtime.listener.endpoint.host "$Label listener host";Assert-UID0002PANativeInteger $Runtime.listener.endpoint.port "$Label listener port"
  Assert-UID0002PANativeInteger $Runtime.listener.process.pid "$Label listener pid";Assert-UID0002PANativeInteger $Runtime.listener.process.creation_time_100ns "$Label listener creation";Assert-UID0002PANativeString $Runtime.listener.process.generation "$Label listener generation"
  Assert-UID0002PANativeArray $Runtime.workers "$Label workers";Assert-UID0002PANativeArray $List.sessions "$Label list sessions"
  foreach($s in @($List.sessions)){Assert-UID0002PANativeString $s.session_id "$Label list session_id";Assert-UID0002PANativeString $s.input_path "$Label list input_path";Assert-UID0002PANativeBoolean $s.is_active "$Label list is_active";Assert-UID0002PANativeInteger $s.worker_pid "$Label list worker_pid"}
  foreach($entry in @($Runtime.workers)){
    Assert-UID0002PANativeString $entry.route.host "$Label route host";Assert-UID0002PANativeInteger $entry.route.port "$Label route port";Assert-UID0002PANativeArray $entry.supervisor_sessions "$Label supervisor sessions";$wa=$entry.attestation
    Assert-UID0002PANativeInteger $wa.schema_version "$Label worker schema_version";Assert-UID0002PANativeBoolean $wa.ok "$Label worker ok";Assert-UID0002PANativeArray $wa.errors "$Label worker errors";Assert-UID0002PANativeString $wa.worker.role "$Label worker role";Assert-UID0002PANativeString $wa.worker.nonce "$Label worker nonce"
    Assert-UID0002PANativeInteger $wa.worker.process.pid "$Label worker pid";Assert-UID0002PANativeInteger $wa.worker.process.parent_pid "$Label worker parent_pid";Assert-UID0002PANativeInteger $wa.worker.process.creation_time_100ns "$Label worker creation";Assert-UID0002PANativeString $wa.worker.process.generation "$Label worker generation";Assert-UID0002PANativeArray $wa.sessions "$Label worker sessions"
    foreach($r in @($entry.supervisor_sessions)){Assert-UID0002PANativeString $r.session_id "$Label supervisor session_id";Assert-UID0002PANativeBoolean $r.owned "$Label supervisor owned";Assert-UID0002PANativeInteger $r.redirector_pid "$Label redirector_pid";Assert-UID0002PANativeInteger $r.registered_pid "$Label registered_pid";Assert-UID0002PANativeString $r.canonical_path "$Label supervisor canonical_path"}
    foreach($r in @($wa.sessions)){Assert-UID0002PANativeString $r.session_id "$Label worker session_id";Assert-UID0002PANativeBoolean $r.is_active "$Label worker is_active";Assert-UID0002PANativeString $r.input_path "$Label worker input_path";Assert-UID0002PANativeString $r.canonical_path "$Label worker canonical_path"}
  }
  if(-not [string]::IsNullOrWhiteSpace($ExpectedDatabase)){
    $matches=@($List.sessions|Where-Object{(Test-UID0002PAJsonString $_.session_id) -and [string]$_.session_id -ceq $ExpectedDatabase -and $_.is_active -eq $true -and [IO.Path]::GetFullPath([string]$_.input_path) -ieq [IO.Path]::GetFullPath($ExpectedCanonicalPath)})
    if($matches.Count -ne 1){throw "$Label exact returned session absent"}
  }
  $true
}

function Assert-UID0002PAExactOpenEnvelopeV3 {
  param($Envelope,[string]$RequestJson,[string]$Label)
  $content=Assert-UID0002PAJsonRpcResponse $Envelope $RequestJson $Label $true;$keys=@($Envelope.result.PSObject.Properties.Name|Sort-Object)-join'|'
  if($keys-notin@('content|isError|structuredContent','isError|structuredContent')){throw "$Label result key set mismatch"};if($Envelope.result.PSObject.Properties['content']){Assert-UID0002PANativeArray $Envelope.result.content "$Label content"};Assert-UID0002PANativeBoolean $Envelope.result.isError "$Label isError"
  if((@($content.PSObject.Properties.Name|Sort-Object)-join'|')-cne'error|session|success'){throw "$Label structuredContent key set mismatch"};Assert-UID0002PANativeBoolean $content.success "$Label success";Assert-UID0002PANativeString $content.error "$Label error"
  if($content.success-ne$true-or$content.error-cne''-or$content.session-is[System.Array]-or$null-eq$content.session){throw "$Label open result mismatch"};if((@($content.session.PSObject.Properties.Name|Sort-Object)-join'|')-cne'input_path|is_analyzing|session_id'){throw "$Label session key set mismatch"}
  Assert-UID0002PANativeString $content.session.session_id "$Label session_id";Assert-UID0002PANativeString $content.session.input_path "$Label input_path";Assert-UID0002PANativeBoolean $content.session.is_analyzing "$Label is_analyzing";if($content.session.is_analyzing-ne$false){throw "$Label is_analyzing must be false"};$content
}

function Get-UID0002PAV3HeldTuple {param([IO.FileStream]$Stream,[string]$Path)Initialize-UID0002PANativeSealedTypes;[UID0002PANativeSealedCore]::ReadTuple($Stream,[IO.Path]::GetFullPath($Path))}
function Assert-UID0002PAV3TupleProjection {
  param($NativeTuple,$ProjectedTuple,[string]$Label)
  if($null -eq $NativeTuple -or $null -eq $ProjectedTuple -or
    [IO.Path]::GetFullPath([string]$NativeTuple.FullPath) -ine [IO.Path]::GetFullPath([string]$ProjectedTuple.FullPath) -or
    [long]$NativeTuple.Length -ne [long]$ProjectedTuple.Length -or
    [long]$NativeTuple.LastWriteTimeUtcTicks -ne [long]$ProjectedTuple.LastWriteTimeUtcTicks -or
    [string]$NativeTuple.SHA256 -cne [string]$ProjectedTuple.SHA256){throw "$Label mismatch"}
  $true
}
function New-UID0002PAV3HeldBackup {
  param([string]$CanonicalPath,[string]$BackupPath)Initialize-UID0002PANativeSealedTypes;$s=$null;$d=$null
  try{$s=[IO.FileStream]::new($CanonicalPath,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);$p0=Get-UID0002PAV3HeldTuple $s $CanonicalPath;$d=[IO.FileStream]::new($BackupPath,[IO.FileMode]::CreateNew,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None);$s.Position=0;$buf=New-Object byte[] 1048576;$count=[long]0;while(($read=$s.Read($buf,0,$buf.Length))-gt0){$d.Write($buf,0,$read);$count+=$read};if($count-ne$p0.Length-or$s.Position-ne$p0.Length-or$s.ReadByte()-ne-1-or$d.Length-ne$p0.Length){throw 'BK3-PA copy/count/EOF mismatch'};$d.Flush($true);[UID0002PANativeSealedCore]::SetWriteTicks($d,$p0.LastWriteTimeUtcTicks);$b0=Get-UID0002PAV3HeldTuple $d $BackupPath;if(-not$p0.SameBytes($b0)-or$p0.LastWriteTimeUtcTicks-ne$b0.LastWriteTimeUtcTicks){throw 'BK3-PA held B0 parity mismatch'};[pscustomobject]@{P0=$p0;B0=$b0}}finally{if($null-ne$d){$d.Dispose()};if($null-ne$s){$s.Dispose()}}
}

function Assert-UID0002PAV3ExactPartialIdentity {
  param($Action,$Runtime,$List)
  if(-not(Test-UID0002PAJsonString $Action.Database) -or -not(Test-UID0002PAJsonString $Action.PreferredSessionId) -or
    [string]$Action.Database -cne [string]$Action.PreferredSessionId){throw 'OP3-PA foreign partial-open session'}
  $null=Assert-UID0002PANativeRuntimeGraph $Runtime $List ([string]$Action.Database) ([string]$Action.CanonicalPath) 'OP3-PA partial'
  $workers=@($Runtime.workers|Where-Object{@($_.supervisor_sessions|Where-Object{[string]$_.session_id -ceq [string]$Action.Database}).Count -eq 1})
  if($workers.Count -ne 1){throw 'OP3-PA partial worker identity ambiguous'}
  $entry=$workers[0];$row=@($entry.supervisor_sessions|Where-Object{[string]$_.session_id -ceq [string]$Action.Database})[0];$worker=$entry.attestation.worker
  if(-not(Test-UID0002PAJsonInteger $Action.RedirectorPid) -or [int]$row.redirector_pid -ne [int]$Action.RedirectorPid -or
    [int]$row.redirector_pid -ne [int]$row.registered_pid -or [int]$worker.process.parent_pid -ne [int]$row.redirector_pid){throw 'OP3-PA partial redirector route mismatch'}
  [pscustomobject][ordered]@{Database=[string]$Action.Database;CanonicalPath=[IO.Path]::GetFullPath([string]$Action.CanonicalPath)
    RedirectorPid=[int]$row.redirector_pid;WorkerPid=[int]$worker.process.pid;WorkerParentPid=[int]$worker.process.parent_pid
    WorkerCreationTime100ns=[long]$worker.process.creation_time_100ns;WorkerGeneration=[string]$worker.process.generation;RoutePort=[int]$entry.route.port}
}

function Assert-UID0002PAV3PostRetirementAbsence {
  param($Runtime,$List,$Identity,[string]$Label)
  $null=Assert-UID0002PANativeRuntimeGraph $Runtime $List '' ([string]$Identity.CanonicalPath) $Label
  if([string]$Runtime.listener.process.generation -cne [string]$Identity.ListenerGeneration){throw "$Label listener generation changed"}
  $listed=@($List.sessions|Where-Object{[string]$_.session_id -ceq [string]$Identity.Database -or ($_.is_active -eq $true -and [IO.Path]::GetFullPath([string]$_.input_path) -ieq [string]$Identity.CanonicalPath)})
  $supervised=@($Runtime.workers|ForEach-Object{@($_.supervisor_sessions)}|Where-Object{[string]$_.session_id -ceq [string]$Identity.Database})
  $workerRows=@($Runtime.workers|ForEach-Object{@($_.attestation.sessions)}|Where-Object{[string]$_.session_id -ceq [string]$Identity.Database})
  if($listed.Count -ne 0 -or $supervised.Count -ne 0 -or $workerRows.Count -ne 0){throw "$Label retired session remains"}
  $true
}

function ConvertFrom-UID0002PAV3TransportEnvelope {
  param($Wire,[string]$Label)
  if($Wire -is [string]){$raw=[string]$Wire}
  elseif($null -ne $Wire -and [string]$Wire.ObservedTransport -ceq 'Response'){$raw=[string]$Wire.RawResponseJson}
  else{throw "$Label transport did not return a response"}
  if([string]::IsNullOrWhiteSpace($raw)){throw "$Label response is empty"}
  Assert-UID0002PARawJsonUnique $raw $Label
  $raw|ConvertFrom-Json -ErrorAction Stop
}

$uid0002paV3PriorController=(Get-Command Invoke-UID0002PAClosedTransaction -CommandType Function).ScriptBlock

function Get-UID0002PAV3LeafFailure {
  param($ErrorRecord)
  $errorObject=$ErrorRecord.Exception
  while($null -ne $errorObject.InnerException){$errorObject=$errorObject.InnerException}
  [string]$errorObject.Message
}

function Set-UID0002PAV3FixtureChangedTuple {
  param([string]$CanonicalPath,[byte]$Marker)
  $stream=[IO.FileStream]::new($CanonicalPath,[IO.FileMode]::Open,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None)
  try{
    $bytes=[byte[]]($Marker,($Marker+1),($Marker+2),($Marker+3),($Marker+4));$stream.SetLength(0);$stream.Position=0
    $stream.Write($bytes,0,$bytes.Length);$stream.Flush($true)
    Get-UID0002PAV3HeldTuple $stream $CanonicalPath
  }finally{$stream.Dispose()}
}

function Start-UID0002PAV3FixtureSave {
  param($Core,[string]$CanonicalPath,[string]$TransportClass,[byte]$Marker)
  $Core.BindPreSave('db','gen',('A'*64),('B'*64));$Core.ClaimSave('db',('C'*64));$Core.RecordTransport()
  $changed=Set-UID0002PAV3FixtureChangedTuple $CanonicalPath $Marker;$Core.RecordDopen($changed);$Core.RecordRetire();$Core.RecordDclosed($changed,$TransportClass);$changed
}

function Invoke-UID0002PAV3FixtureRestore {
  param($Core,$Backup,[string]$CanonicalPath)
  $source=$null;$destination=$null
  try{
    $source=[IO.FileStream]::new($Backup.B0.FullPath,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None)
    $destination=[IO.FileStream]::new($CanonicalPath,[IO.FileMode]::Open,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None)
    $heldSource=Get-UID0002PAV3HeldTuple $source $Backup.B0.FullPath;$heldDestination=Get-UID0002PAV3HeldTuple $destination $CanonicalPath
    $Core.AuthorizeRestore($heldDestination,$heldSource);$source.Position=0;$destination.SetLength(0);$destination.Position=0
    $buffer=New-Object byte[] 4096;$copied=[long]0
    while(($read=$source.Read($buffer,0,$buffer.Length)) -gt 0){$destination.Write($buffer,0,$read);$copied+=$read}
    if($copied -ne $Backup.P0.Length -or $source.Position -ne $Backup.P0.Length -or $source.ReadByte() -ne -1 -or $destination.Length -ne $Backup.P0.Length){throw 'RS3-PA fixture copy/count/EOF mismatch'}
    $destination.Flush($true);[UID0002PANativeSealedCore]::SetWriteTicks($destination,$Backup.P0.LastWriteTimeUtcTicks)
    $restored=Get-UID0002PAV3HeldTuple $destination $CanonicalPath;$Core.MarkRestored($restored);$restored
  }finally{if($null -ne $destination){$destination.Dispose()};if($null -ne $source){$source.Dispose()}}
}

function Remove-UID0002PAReportOwnedFixtureRootVerified {
  [CmdletBinding()]param([Parameter(Mandatory=$true)][string]$ExactRoot)
  $root=[IO.Path]::GetFullPath($ExactRoot).TrimEnd('\');$temp=[IO.Path]::GetFullPath([IO.Path]::GetTempPath()).TrimEnd('\');$prefix=$temp+'\';$leaf=[IO.Path]::GetFileName($root)
  if($root.Length-le$temp.Length-or-not$root.StartsWith($prefix,[StringComparison]::OrdinalIgnoreCase)-or$leaf-notmatch'^uid0002pa-(v3|v4)-[0-9a-f]{32}$'){throw 'CL6-PA fixture cleanup root authority mismatch'}
  $paths=[Collections.Generic.HashSet[string]]::new([StringComparer]::OrdinalIgnoreCase)
  foreach($path in @($root,(Join-Path $root 'source'),(Join-Path $root 'fixture.i64'),(Join-Path $root 'source\listener.py'),(Join-Path $root 'source\worker.py'),(Join-Path $root 'fixture.i64.uid0002pa-v4.journal'),(Join-Path $root 'fixture.i64.uid0002pa-v4.backup'),(Join-Path $root 'authority.json'),(Join-Path $root 'fixture.bak'),(Join-Path $root 'third.i64'))){$null=$paths.Add([IO.Path]::GetFullPath($path))}
  try{if([IO.Directory]::Exists($root)){foreach($path in [IO.Directory]::GetFileSystemEntries($root,'*',[IO.SearchOption]::AllDirectories)){$null=$paths.Add([IO.Path]::GetFullPath($path))}}}catch{throw "CL6-PA fixture cleanup enumeration failed: $($_.Exception.GetType().FullName)"}
  try{if([IO.File]::Exists($root)-and-not[IO.Directory]::Exists($root)){throw [IO.IOException]::new('fixture root is not a directory')};if([IO.Directory]::Exists($root)){[IO.Directory]::Delete($root,$true)}}catch{throw "CL6-PA fixture cleanup delete failed: $($_.Exception.GetType().FullName)"}
  $remaining=[Collections.Generic.List[string]]::new();foreach($path in $paths){if([IO.File]::Exists($path)-or[IO.Directory]::Exists($path)){$remaining.Add($path)}}
  if($remaining.Count-ne0-or[IO.File]::Exists($root)-or[IO.Directory]::Exists($root)){throw "CL6-PA fixture cleanup physical absence mismatch: $([string]::Join(';',@($remaining)))"}
  [pscustomobject][ordered]@{CleanupClass='VERIFIED_PHYSICAL_ABSENCE';Root=$root;CheckedPaths=[long]$paths.Count;RootAbsent=$true;ChildrenAbsent=$true}
}

function Invoke-UID0002PAV3FixtureCase {
  param([ValidateSet('NativeTypeDrift','ForeignPartialOpen','CleanupFailureRetention','ImmediatePreSaveDrift','DuplicateSave','P0','P1','IndeterminateChanged','F1','Rollback','RestoreCorruption','ThirdIdentity','CallerIsolation')][string]$Case)
  Initialize-UID0002PANativeSealedTypes
  $root=[IO.Path]::Combine([IO.Path]::GetTempPath(),'uid0002pa-v3-'+[Guid]::NewGuid().ToString('N'));[IO.Directory]::CreateDirectory($root)|Out-Null
  $canonical=Join-Path $root 'fixture.i64';[IO.File]::WriteAllBytes($canonical,[byte[]](1,2,3,4));$journal=Join-Path $root 'authority.json';$core=$null;$label=$null
  try{
    $core=[UID0002PANativeSealedCore]::new($canonical,'fixture-'+$Case,$journal);$core.FreezeAuthority('{}','{}','{}')
    $backup=New-UID0002PAV3HeldBackup $canonical (Join-Path $root 'fixture.bak');$core.SetBackup($backup.P0,$backup.B0)
    switch($Case){
      'NativeTypeDrift'{
        $r=[pscustomobject]@{schema_version='1';ok=$true;errors=@();listener=[pscustomobject]@{};workers=@()}
        try{Assert-UID0002PANativeRuntimeGraph $r ([pscustomobject]@{sessions=@()}) db $canonical 'NR3-PA fixture'}catch{$label=Get-UID0002PAV3LeafFailure $_}
        if($label -cne 'NR3-PA fixture runtime schema_version native integer mismatch'){throw "HF3-PA wrong rejection: $label"}
      }
      'ForeignPartialOpen'{
        $a=[pscustomobject]@{Database='foreign';PreferredSessionId='preferred'}
        try{Assert-UID0002PAV3ExactPartialIdentity $a $null $null}catch{$label=Get-UID0002PAV3LeafFailure $_}
        if($label -cne 'OP3-PA foreign partial-open session'){throw "HF3-PA wrong rejection: $label"}
      }
      'CleanupFailureRetention'{
        $core.RecordRetire();$core.MarkNoSaveFailure('OP3-PA cleanup not independently proven');$label='OP3-PA cleanup not independently proven'
        if(-not [IO.File]::Exists($journal) -or -not $core.JournalRetained){throw 'HF3-PA no-save journal was erased'}
      }
      'ImmediatePreSaveDrift'{
        try{$core.ClaimSave('db','A'*64)}catch{$label=Get-UID0002PAV3LeafFailure $_}
        if($label -cne 'SV3-PA save lacks immediate bound pre-save attestation'){throw "HF3-PA wrong rejection: $label"}
      }
      'DuplicateSave'{
        $core.BindPreSave('db','gen','A'*64,'B'*64);$core.ClaimSave('db','C'*64);$core.RecordTransport()
        try{$core.ClaimSave('db','C'*64)}catch{$label=Get-UID0002PAV3LeafFailure $_}
        if($label -cne 'SV3-PA durable global save already claimed'){throw "HF3-PA wrong rejection: $label"}
      }
      'P0'{
        $core.BindPreSave('db','gen','A'*64,'B'*64);$core.ClaimSave('db','C'*64);$core.RecordTransport()
        $stream=[IO.FileStream]::new($canonical,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);try{$p0Now=Get-UID0002PAV3HeldTuple $stream $canonical}finally{$stream.Dispose()}
        $core.RecordDopen($p0Now);$core.RecordRetire();$core.RecordDclosed($p0Now,'DeterminateSuccess');$core.MarkP0Verified();$core.MarkTerminal('NOT_PERSISTED_P0_VERIFIED_DETERMINATESUCCESS');$label='HF3-PA P0 verifier branch completed'
      }
      'P1'{
        $null=Start-UID0002PAV3FixtureSave $core $canonical 'DeterminateSuccess' 20;$core.MarkP1Verified();$core.MarkTerminal('PERSISTED_S1_VERIFIED_DETERMINATESUCCESS');$label='HF3-PA P1 verifier branch completed'
      }
      'IndeterminateChanged'{
        try{$null=Start-UID0002PAV3FixtureSave $core $canonical 'Indeterminate' 30}catch{$label=Get-UID0002PAV3LeafFailure $_}
        if($label -cne 'DS3-PA changed output lacks determinate sole-save authority'){throw "HF3-PA wrong rejection: $label"}
      }
      'F1'{
        $null=Start-UID0002PAV3FixtureSave $core $canonical 'DeterminateSuccess' 40
        $core.MarkF1('Final','S1Verifier','RQ-PA S1Verifier exact result mismatch fixture','D'*64,'E'*64,'db','gen');$label='HF3-PA literal Final F1 authorized'
      }
      'Rollback'{
        $null=Start-UID0002PAV3FixtureSave $core $canonical 'DeterminateSuccess' 50
        $core.MarkF1('Final','S1Verifier','RQ-PA S1Verifier exact result mismatch fixture','D'*64,'E'*64,'db','gen')
        $null=Invoke-UID0002PAV3FixtureRestore $core $backup $canonical;$core.MarkRollbackVerified();$core.MarkTerminal('RESTORED_P0_VERIFIED_DETERMINATESUCCESS');$label='HF3-PA rollback verifier completed'
      }
      'RestoreCorruption'{
        $null=Start-UID0002PAV3FixtureSave $core $canonical 'DeterminateSuccess' 60
        $core.MarkF1('Final','S1Verifier','RQ-PA S1Verifier exact result mismatch fixture','D'*64,'E'*64,'db','gen');[IO.File]::WriteAllBytes($backup.B0.FullPath,[byte[]](9,9,9))
        $source=[IO.FileStream]::new($backup.B0.FullPath,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);$destination=[IO.FileStream]::new($canonical,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None)
        try{$badBackup=Get-UID0002PAV3HeldTuple $source $backup.B0.FullPath;$heldDestination=Get-UID0002PAV3HeldTuple $destination $canonical;try{$core.AuthorizeRestore($heldDestination,$badBackup)}catch{$label=Get-UID0002PAV3LeafFailure $_}}finally{$destination.Dispose();$source.Dispose()}
        if($label -cne 'RS3-PA held P1/B0 authority mismatch'){throw "HF3-PA wrong rejection: $label"}
      }
      'ThirdIdentity'{
        $null=Start-UID0002PAV3FixtureSave $core $canonical 'DeterminateSuccess' 70
        $core.MarkF1('Final','S1Verifier','RQ-PA S1Verifier exact result mismatch fixture','D'*64,'E'*64,'db','gen');$third=Join-Path $root 'third.i64';[IO.File]::WriteAllBytes($third,[byte[]](7,7,7,7,7))
        $source=[IO.FileStream]::new($backup.B0.FullPath,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);$destination=[IO.FileStream]::new($third,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None)
        try{$heldBackup=Get-UID0002PAV3HeldTuple $source $backup.B0.FullPath;$thirdTuple=Get-UID0002PAV3HeldTuple $destination $third;try{$core.AuthorizeRestore($thirdTuple,$heldBackup)}catch{$label=Get-UID0002PAV3LeafFailure $_}}finally{$destination.Dispose();$source.Dispose()}
        if($label -cne 'RS3-PA held P1/B0 authority mismatch'){throw "HF3-PA wrong rejection: $label"}
      }
      'CallerIsolation'{
        $adapter={param([string]$payload)Set-Variable -Name schemaHash -Value 'forged' -Scope Local -ErrorAction SilentlyContinue;[pscustomobject]@{Echo=$payload}}
        $core.RecordTransport();$answer=[UID0002PANativeSealedCore]::InvokeAdapter($adapter,'bounded-payload');$core.AssertAuthority('{}','{}','{}')
        if([string]$answer.Echo -cne 'bounded-payload'){throw 'HF3-PA caller adapter result mismatch'};$label='HF3-PA sealed caller boundary preserved'
      }
    }
    [pscustomobject]@{Case=$Case;Label=$label;ProductionPath=$true;SaveDispatchCount=$core.SaveDispatchCount;TransportCalls=$core.TransportCalls;RetireCalls=$core.RetireCalls;RestoreWrites=$core.RestoreWrites;JournalRetained=$core.JournalRetained;TargetEffects=if([IO.Path]::GetFullPath($canonical).StartsWith([IO.Path]::GetFullPath($root),[StringComparison]::OrdinalIgnoreCase)){0}else{1}}
  }finally{if($null -ne $core){$core.Dispose()};$null=Remove-UID0002PAReportOwnedFixtureRootVerified $root}
}

$uid0002paV3FinalController={
  param([scriptblock]$Transport,[scriptblock]$RetireExactGeneration,[ValidateSet('','NativeTypeDrift','ForeignPartialOpen','CleanupFailureRetention','ImmediatePreSaveDrift','DuplicateSave','P0','P1','IndeterminateChanged','F1','Rollback','RestoreCorruption','ThirdIdentity','CallerIsolation')][string]$HostileFixture='')
  if($HostileFixture){return Invoke-UID0002PAV3FixtureCase $HostileFixture};if($null-eq$Transport-or$null-eq$RetireExactGeneration){throw 'CT3-PA production adapters required'};Initialize-UID0002PANativeSealedTypes
  $canonical=[IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64');$tx=[Guid]::NewGuid().ToString('N');$v3=New-UID0002PAV3HeldBackup $canonical ($canonical+'.bak-UID0002PA-v3-'+[DateTime]::UtcNow.ToString('yyyyMMdd-HHmmss')+'-'+[Guid]::NewGuid().ToString('N'));$core=[UID0002PANativeSealedCore]::new($canonical,$tx,$null);$core.SetBackup($v3.P0,$v3.B0)
  $schemas=Get-UID0002PAUsedToolSchemaContracts|ConvertTo-Json -Depth 100 -Compress;$plan=[ordered]@{Phases=@('Pre','AfterI01','AfterI02','AfterI03','AfterI04','AfterI05','Final','P0Verifier','S1Verifier','RollbackVerifier');Mutations=@('I01','I02Dry','I02','I03','I04','I05');Config=Get-UID0002PAConfigOracle}|ConvertTo-Json -Depth 100 -Compress;$modules=[ordered]@{Root=$UID0002PASourceRoot;Listener=@($UID0002PAListenerNames);Worker=@($UID0002PAWorkerNames);ListenerDigest='D3C792133956B855EBA751FDB5783B2D7177FA204134CFF1D897E0D0770FB7CE';WorkerDigest='849203D42ABFC99176069E7069F039E9B50AC1A0F392BECB4D7C90CC7AE627D4'}|ConvertTo-Json -Depth 20 -Compress;$core.FreezeAuthority($schemas,$plan,$modules);$prior=$uid0002paV3PriorController
  $raw={param([string]$payload)$core.RecordTransport();[UID0002PANativeSealedCore]::InvokeAdapter($Transport,$payload)}.GetNewClosure()
  $safeTransport={param([string]$requestJson)$core.AssertAuthority($schemas,$plan,$modules);$id=Get-UID0002PARequestIdentity $requestJson 'CT3-PA adapter request'
    if([string]$id.Parsed.method -ceq 'tools/call' -and [string]$id.Parsed.params.name -ceq 'idb_save'){$db=[string]$id.Parsed.params.arguments.database;$lr=New-UID0002PAToolRequest "uid0002pa-presave-list-$([Guid]::NewGuid().ToString('N'))" idb_list @{};$lw=&$raw $lr;$le=ConvertFrom-UID0002PAV3TransportEnvelope $lw 'SV3-PA immediate list wire';$list=Get-UID0002PAStructuredContent $le $lr 'SV3-PA immediate list';$binding=[pscustomobject]@{Database=$db;CanonicalPath=$canonical};$rr=New-UID0002PARuntimeAttestationRequest "uid0002pa-presave-runtime-$([Guid]::NewGuid().ToString('N'))" $binding;$rw=&$raw $rr;$re=ConvertFrom-UID0002PAV3TransportEnvelope $rw 'SV3-PA immediate runtime wire';$runtime=Get-UID0002PAStructuredContent $re $rr 'SV3-PA immediate runtime';$null=Assert-UID0002PANativeRuntimeGraph $runtime $list $db $canonical 'SV3-PA immediate';$workers=@($runtime.workers|Where-Object{@($_.supervisor_sessions|Where-Object{[string]$_.session_id -ceq $db}).Count -eq 1});if($workers.Count -ne 1){throw 'SV3-PA immediate worker generation ambiguous'};$core.BindPreSave($db,[string]$workers[0].attestation.worker.process.generation,(Get-UID0002PATextSha256($lr+($le|ConvertTo-Json -Depth 80 -Compress))),(Get-UID0002PATextSha256($rr+($re|ConvertTo-Json -Depth 80 -Compress))));$core.ClaimSave($db,$id.SHA256);$wire=&$raw $requestJson;$s=[IO.FileStream]::new($canonical,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::ReadWrite -bor [IO.FileShare]::Delete);try{$core.RecordDopen((Get-UID0002PAV3HeldTuple $s $canonical))}finally{$s.Dispose()};return $wire};return (&$raw $requestJson)}.GetNewClosure()
  $safeRetire={
    param($action)
    $core.AssertAuthority($schemas,$plan,$modules);$sealedAction=$action;$partialIdentity=$null
    if($action.PartialOpen -eq $true){
      $preListRequest=New-UID0002PAToolRequest "uid0002pa-partial-list-$([Guid]::NewGuid().ToString('N'))" idb_list @{}
      $preListWire=&$raw $preListRequest;$preListEnvelope=ConvertFrom-UID0002PAV3TransportEnvelope $preListWire 'OP3-PA partial list wire'
      $preList=Get-UID0002PAStructuredContent $preListEnvelope $preListRequest 'OP3-PA partial list'
      $partialBinding=[pscustomobject]@{Database=[string]$action.Database;CanonicalPath=[string]$action.CanonicalPath}
      $preRuntimeRequest=New-UID0002PARuntimeAttestationRequest "uid0002pa-partial-runtime-$([Guid]::NewGuid().ToString('N'))" $partialBinding
      $preRuntimeWire=&$raw $preRuntimeRequest;$preRuntimeEnvelope=ConvertFrom-UID0002PAV3TransportEnvelope $preRuntimeWire 'OP3-PA partial runtime wire'
      $preRuntime=Get-UID0002PAStructuredContent $preRuntimeEnvelope $preRuntimeRequest 'OP3-PA partial runtime'
      $partialIdentity=Assert-UID0002PAV3ExactPartialIdentity $action $preRuntime $preList
      $partialIdentity|Add-Member ListenerGeneration ([string]$preRuntime.listener.process.generation) -Force
      $redirector=@(Get-CimInstance Win32_Process -Filter "ProcessId=$([int]$partialIdentity.RedirectorPid)" -ErrorAction Stop)
      if($redirector.Count -ne 1){throw 'OP3-PA redirector process generation unavailable'}
      $redirectorCreated=([DateTime]$redirector[0].CreationDate).ToUniversalTime().ToFileTimeUtc();if($redirectorCreated -le 0){throw 'OP3-PA redirector process generation invalid'}
      $sealedAction=[pscustomobject][ordered]@{Action='RETIRE_PARTIAL_OPEN';PartialOpen=$true;Role=[string]$action.Role;Database=[string]$partialIdentity.Database
        PreferredSessionId=[string]$action.PreferredSessionId;CanonicalPath=[string]$partialIdentity.CanonicalPath;RedirectorPid=[int]$partialIdentity.RedirectorPid
        RedirectorGeneration="pid:$([int]$partialIdentity.RedirectorPid);created:$redirectorCreated";WorkerPid=[int]$partialIdentity.WorkerPid
        WorkerGeneration=[string]$partialIdentity.WorkerGeneration;WorkerCreationTime100ns=[long]$partialIdentity.WorkerCreationTime100ns
        RoutePort=[int]$partialIdentity.RoutePort;OpenRequestSHA256=[string]$action.OpenRequestSHA256;PreserveListener=$true}
    }
    $sealedText=$sealedAction|ConvertTo-Json -Depth 40 -Compress;$core.FreezeRole("$([string]$sealedAction.Role)|$([string]$sealedAction.Database)",$sealedText);$core.RecordRetire()
    $answer=[UID0002PANativeSealedCore]::InvokeAdapter($RetireExactGeneration,$sealedText);if($answer -is [string]){Assert-UID0002PARawJsonUnique $answer 'RT3-PA retire result';$answer=$answer|ConvertFrom-Json}
    $core.AssertRole("$([string]$sealedAction.Role)|$([string]$sealedAction.Database)",$sealedText)
    Assert-UID0002PANativeBoolean $answer.Retired 'RT3-PA retired';Assert-UID0002PANativeBoolean $answer.ListenerPreserved 'RT3-PA listener preserved'
    if($answer.Retired -ne $true -or $answer.ListenerPreserved -ne $true -or [string]$answer.Action -cne [string]$sealedAction.Action -or
      [string]$answer.Database -cne [string]$sealedAction.Database -or [string]$answer.Role -cne [string]$sealedAction.Role){throw 'RT3-PA exact retirement result mismatch'}
    if($action.PartialOpen -eq $true){
      Assert-UID0002PANativeInteger $answer.RedirectorPid 'RT3-PA result redirector PID';Assert-UID0002PANativeInteger $answer.WorkerPid 'RT3-PA result worker PID'
      Assert-UID0002PANativeString $answer.RedirectorGeneration 'RT3-PA result redirector generation';Assert-UID0002PANativeString $answer.WorkerGeneration 'RT3-PA result worker generation'
      Assert-UID0002PANativeInteger $answer.RoutePort 'RT3-PA result route port';Assert-UID0002PANativeBoolean $answer.ProcessAbsentOrReused 'RT3-PA result process absence';Assert-UID0002PANativeBoolean $answer.SocketAbsent 'RT3-PA result socket absence'
      if([int]$answer.RedirectorPid -ne [int]$sealedAction.RedirectorPid -or [int]$answer.WorkerPid -ne [int]$sealedAction.WorkerPid -or
        [string]$answer.RedirectorGeneration -cne [string]$sealedAction.RedirectorGeneration -or [string]$answer.WorkerGeneration -cne [string]$sealedAction.WorkerGeneration -or
        [int]$answer.RoutePort -ne [int]$sealedAction.RoutePort -or $answer.ProcessAbsentOrReused -ne $true -or $answer.SocketAbsent -ne $true){throw 'RT3-PA partial generation retirement mismatch'}
      $postListRequest=New-UID0002PAToolRequest "uid0002pa-partial-post-list-$([Guid]::NewGuid().ToString('N'))" idb_list @{}
      $postListWire=&$raw $postListRequest;$postListEnvelope=ConvertFrom-UID0002PAV3TransportEnvelope $postListWire 'OP3-PA partial post list wire';$postList=Get-UID0002PAStructuredContent $postListEnvelope $postListRequest 'OP3-PA partial post list'
      $postRuntimeRequest=New-UID0002PAPostRetirementAttestationRequest "uid0002pa-partial-post-runtime-$([Guid]::NewGuid().ToString('N'))" $partialBinding
      $postRuntimeWire=&$raw $postRuntimeRequest;$postRuntimeEnvelope=ConvertFrom-UID0002PAV3TransportEnvelope $postRuntimeWire 'OP3-PA partial post runtime wire';$postRuntime=Get-UID0002PAStructuredContent $postRuntimeEnvelope $postRuntimeRequest 'OP3-PA partial post runtime'
      $null=Assert-UID0002PAV3PostRetirementAbsence $postRuntime $postList $partialIdentity 'OP3-PA partial poststate'
      $first=Get-UID0002PAExclusiveTuple $canonical;$second=Get-UID0002PAExclusiveTuple $canonical;Assert-UID0002PATuple $second $first 'OP3-PA partial exclusive P0'
      $answer|Add-Member PreferredSessionId ([string]$sealedAction.PreferredSessionId) -Force;$answer|Add-Member CanonicalPath ([string]$sealedAction.CanonicalPath) -Force;$answer|Add-Member OpenRequestSHA256 ([string]$sealedAction.OpenRequestSHA256) -Force;$answer|Add-Member PartialOpen $true -Force
    }
    $answer
  }.GetNewClosure()
  try{$result=&$prior $safeTransport $safeRetire $core $v3;if([string]$result.Status -like 'NOT_PERSISTED_P0_VERIFIED_*'){if($core.State -cne 'P0_VERIFIED'){throw 'CT3-PA P0 state mismatch'}}elseif([string]$result.Status -ceq 'PERSISTED_S1_VERIFIED_DETERMINATESUCCESS'){if($core.State -cne 'P1_VERIFIED'){throw 'CT3-PA P1 state mismatch'}}elseif([string]$result.Status -ceq 'RESTORED_P0_VERIFIED_DETERMINATESUCCESS'){if($core.State -cne 'RESTORED_P0_VERIFIED'){throw 'CT3-PA rollback state mismatch'}}else{throw "CT3-PA unrecognized terminal status $($result.Status)"};$core.MarkTerminal([string]$result.Status);$result|Add-Member SealedV3 ([pscustomobject]@{State=$core.State;Journal=$core.JournalPath;SaveDispatchCount=$core.SaveDispatchCount;TransportCalls=$core.TransportCalls;RetireCalls=$core.RetireCalls;Dopen=$core.Dopen;Dclosed=$core.Dclosed;P1=$core.P1}) -Force;$result}catch{if($core.SaveDispatchCount -eq 0){$core.MarkNoSaveFailure($_.Exception.Message)}else{$core.MarkTerminal("FAILED_CLOSED_AFTER_SAVE: $($_.Exception.Message)")};throw}finally{$core.Dispose()}
}.GetNewClosure()
Set-Item -LiteralPath Function:\Invoke-UID0002PAClosedTransaction -Value $uid0002paV3FinalController -Force
Remove-Variable uid0002paV3PriorController,uid0002paV3FinalController -ErrorAction SilentlyContinue

function Invoke-UID0002PAHostileStaticFixtures {
  $expected=[ordered]@{
    NativeTypeDrift=@('NR3-PA fixture runtime schema_version native integer mismatch',0,0,0,0);ForeignPartialOpen=@('OP3-PA foreign partial-open session',0,0,0,0)
    CleanupFailureRetention=@('OP3-PA cleanup not independently proven',0,0,1,0);ImmediatePreSaveDrift=@('SV3-PA save lacks immediate bound pre-save attestation',0,0,0,0)
    DuplicateSave=@('SV3-PA durable global save already claimed',1,1,0,0);P0=@('HF3-PA P0 verifier branch completed',1,1,1,0)
    P1=@('HF3-PA P1 verifier branch completed',1,1,1,0);IndeterminateChanged=@('DS3-PA changed output lacks determinate sole-save authority',1,1,1,0)
    F1=@('HF3-PA literal Final F1 authorized',1,1,1,0);Rollback=@('HF3-PA rollback verifier completed',1,1,1,1)
    RestoreCorruption=@('RS3-PA held P1/B0 authority mismatch',1,1,1,0);ThirdIdentity=@('RS3-PA held P1/B0 authority mismatch',1,1,1,0)
    CallerIsolation=@('HF3-PA sealed caller boundary preserved',0,1,0,0)
  }
  $rows=@();foreach($case in @($expected.Keys)){$row=Invoke-UID0002PAClosedTransaction -HostileFixture $case;$want=$expected[$case]
    if($row.ProductionPath -ne $true -or [string]$row.Label -cne [string]$want[0] -or [int]$row.SaveDispatchCount -ne [int]$want[1] -or
      [int]$row.TransportCalls -ne [int]$want[2] -or [int]$row.RetireCalls -ne [int]$want[3] -or [int]$row.RestoreWrites -ne [int]$want[4] -or [int]$row.TargetEffects -ne 0){throw "HF3-PA production fixture result mismatch: $case"}
    $rows+=$row
  }
  $production=@($rows|Where-Object{$_.ProductionPath -eq $true});if($production.Count -ne 13){throw 'HF3-PA production controller invocation mismatch'}
  [pscustomobject]@{Passed=$production.Count;Failed=0;ProductionControllerInvocations=$production.Count;TargetEffects=@($rows|Measure-Object TargetEffects -Sum).Sum;Cases=$rows}
}
~~~

## Removed Block R023

- SHA256: `5B49401BBE848DA01522DDFDC90D16E9CD707C3A339F1AAEF5B0524AAB266FDF`
- Language: `powershell`
- Bytes: `19156`
- First recovered timestamp: `2026-08-09T15:30:56.412Z`
- Session provenance: rollout-2026-08-08T17-46-23-019fe357-64cc-7ca3-ad27-c9c336afc6af.jsonl line 5673 (2026-08-09T15:30:56.412Z); rollout-2026-08-08T17-46-23-019fe357-64cc-7ca3-ad27-c9c336afc6af.jsonl line 5674 (2026-08-09T15:30:56.800Z)

~~~powershell
function Initialize-UID0002PAJsonDuplicateGuard {
    if ('UID0002PAJsonDuplicateGuard' -as [type]) { return }
    Add-Type -TypeDefinition @'
using System;
using System.Collections.Generic;

public static class UID0002PAJsonDuplicateGuard {
    private sealed class Parser {
        private readonly string text;
        private int index;
        internal Parser(string value) { if (value == null) throw new ArgumentNullException("value"); text = value; }
        internal void Parse() { Skip(); Value(); Skip(); if (index != text.Length) Fail("trailing data"); }
        private void Skip() { while (index < text.Length && char.IsWhiteSpace(text[index])) index++; }
        private void Fail(string message) { throw new FormatException("JSON_SYNTAX:" + message + "@" + index); }
        private void Value() {
            Skip(); if (index >= text.Length) Fail("missing value");
            char c = text[index];
            if (c == '{') { Object(); return; }
            if (c == '[') { Array(); return; }
            if (c == '"') { String(); return; }
            if (c == 't') { Literal("true"); return; }
            if (c == 'f') { Literal("false"); return; }
            if (c == 'n') { Literal("null"); return; }
            Number();
        }
        private void Object() {
            index++; Skip(); var names = new HashSet<string>(StringComparer.Ordinal);
            if (Take('}')) return;
            while (true) {
                Skip(); if (index >= text.Length || text[index] != '"') Fail("object key");
                string key = String();
                if (!names.Add(key)) throw new FormatException("JSON_DUPLICATE_MEMBER:" + key);
                Skip(); if (!Take(':')) Fail("missing colon"); Value(); Skip();
                if (Take('}')) return; if (!Take(',')) Fail("missing object comma");
            }
        }
        private void Array() {
            index++; Skip(); if (Take(']')) return;
            while (true) { Value(); Skip(); if (Take(']')) return; if (!Take(',')) Fail("missing array comma"); }
        }
        private bool Take(char value) { if (index < text.Length && text[index] == value) { index++; return true; } return false; }
        private string String() {
            if (!Take('"')) Fail("string open"); var value = new System.Text.StringBuilder();
            while (index < text.Length) {
                char c = text[index++]; if (c == '"') return value.ToString();
                if (c < 0x20) Fail("control in string");
                if (c != '\\') { value.Append(c); continue; }
                if (index >= text.Length) Fail("escape eof"); char e = text[index++];
                switch (e) {
                    case '"': value.Append('"'); break; case '\\': value.Append('\\'); break; case '/': value.Append('/'); break;
                    case 'b': value.Append('\b'); break; case 'f': value.Append('\f'); break; case 'n': value.Append('\n'); break;
                    case 'r': value.Append('\r'); break; case 't': value.Append('\t'); break;
                    case 'u':
                        if (index + 4 > text.Length) Fail("unicode eof");
                        int code; if (!Int32.TryParse(text.Substring(index,4),System.Globalization.NumberStyles.HexNumber,null,out code)) Fail("unicode");
                        value.Append((char)code); index += 4; break;
                    default: Fail("escape"); break;
                }
            }
            Fail("string eof"); return null;
        }
        private void Literal(string literal) {
            if (index + literal.Length > text.Length || System.String.CompareOrdinal(text,index,literal,0,literal.Length) != 0) Fail("literal");
            index += literal.Length;
        }
        private void Number() {
            int start=index; if (Take('-')) { }
            if (Take('0')) { } else { if (index>=text.Length || text[index]<'1' || text[index]>'9') Fail("number"); while(index<text.Length && char.IsDigit(text[index])) index++; }
            if (Take('.')) { if(index>=text.Length || !char.IsDigit(text[index])) Fail("fraction"); while(index<text.Length && char.IsDigit(text[index])) index++; }
            if(index<text.Length && (text[index]=='e' || text[index]=='E')) { index++; if(index<text.Length && (text[index]=='+' || text[index]=='-')) index++; if(index>=text.Length || !char.IsDigit(text[index])) Fail("exponent"); while(index<text.Length && char.IsDigit(text[index])) index++; }
            if(index==start) Fail("number");
        }
    }
    public static void AssertNoDuplicates(string json) { new Parser(json).Parse(); }
}
'@
}

function Assert-UID0002PARawJsonUnique {
    param([Parameter(Mandatory=$true)][string]$Json,[Parameter(Mandatory=$true)][string]$Label)
    Initialize-UID0002PAJsonDuplicateGuard
    try { [UID0002PAJsonDuplicateGuard]::AssertNoDuplicates($Json) }
    catch { throw "$Label raw JSON rejected: $($_.Exception.GetBaseException().Message)" }
}

function Test-UID0002PAJsonInteger { param($Value) $Value -is [int] -or $Value -is [long] }
function Test-UID0002PAJsonBoolean { param($Value) $Value -is [bool] }
function Test-UID0002PAJsonString { param($Value) $Value -is [string] }

function Get-UID0002PARequestIdentity {
    param([Parameter(Mandatory=$true)][string]$RequestJson,[Parameter(Mandatory=$true)][string]$Label)
    Assert-UID0002PARawJsonUnique $RequestJson $Label
    $request=$RequestJson|ConvertFrom-Json -ErrorAction Stop
    $root=@($request.PSObject.Properties.Name|Sort-Object)
    if(($root-join '|') -cne 'id|jsonrpc|method|params' -or -not (Test-UID0002PAJsonString $request.jsonrpc) -or
        [string]$request.jsonrpc -cne '2.0' -or -not (Test-UID0002PAJsonString $request.method) -or
        ($request.id -is [bool]) -or (-not (Test-UID0002PAJsonString $request.id) -and -not (Test-UID0002PAJsonInteger $request.id))){
        throw "$Label invalid native JSON-RPC request root/id"
    }
    if([string]$request.method -ceq 'tools/list'){
        if(@($request.params.PSObject.Properties).Count -ne 0){throw "$Label tools/list params mismatch"}
    }elseif([string]$request.method -ceq 'tools/call'){
        if((@($request.params.PSObject.Properties.Name|Sort-Object)-join '|') -cne 'arguments|name' -or
            -not (Test-UID0002PAJsonString $request.params.name) -or $null -eq $request.params.arguments){
            throw "$Label tools/call params mismatch"
        }
    }else{throw "$Label unexpected JSON-RPC method"}
    [pscustomobject][ordered]@{Json=$RequestJson;Parsed=$request;Id=$request.id;IdType=$request.id.GetType().FullName;SHA256=Get-UID0002PATextSha256 $RequestJson}
}

function Assert-UID0002PAJsonRpcResponse {
    param(
        [Parameter(Mandatory=$true)]$Envelope,
        [Parameter(Mandatory=$true)][string]$RequestJson,
        [Parameter(Mandatory=$true)][string]$Label,
        [bool]$RequireStructuredContent=$true,
        [AllowNull()][string]$RawEnvelopeJson)
    if(-not [string]::IsNullOrWhiteSpace($RawEnvelopeJson)){Assert-UID0002PARawJsonUnique $RawEnvelopeJson $Label}
    $request=Get-UID0002PARequestIdentity $RequestJson "$Label request"
    $keys=@($Envelope.PSObject.Properties.Name|Sort-Object)
    if(-not (Test-UID0002PAJsonString $Envelope.jsonrpc) -or [string]$Envelope.jsonrpc -cne '2.0' -or $null -eq $Envelope.id -or
        $Envelope.id.GetType().FullName -cne $request.IdType -or -not [object]::Equals($Envelope.id,$request.Id)){
        throw "$Label JSON-RPC identity/result mismatch"
    }
    if(($keys-join '|') -ceq 'error|id|jsonrpc') { throw "$Label JSON-RPC error response" }
    if(($keys-join '|') -cne 'id|jsonrpc|result' -or $null -eq $Envelope.result){
        throw "$Label JSON-RPC identity/result mismatch"
    }
    if([string]$request.Parsed.method -ceq 'tools/call'){
        if(-not $Envelope.result.PSObject.Properties['isError'] -or -not (Test-UID0002PAJsonBoolean $Envelope.result.isError)){
            throw "$Label missing/non-Boolean isError"
        }
        if($Envelope.result.isError -eq $true){throw "$Label tool result isError"
        }
        if($RequireStructuredContent -and (-not $Envelope.result.PSObject.Properties['structuredContent'] -or $null -eq $Envelope.result.structuredContent)){
            throw "$Label missing structuredContent"
        }
        if($RequireStructuredContent){return $Envelope.result.structuredContent}
    }
    return $Envelope.result
}

function ConvertTo-UID0002PASchemaAuthorityNode {
    param([Parameter(Mandatory=$true)]$Node,[Parameter(Mandatory=$true)][string]$Label)
    $metadata=@('title','description')
    $authority=@('type','properties','required','additionalProperties','default','items','anyOf','allOf','oneOf','$ref','$defs','definitions','enum','const','minimum','maximum','minItems','maxItems','pattern','format')
    foreach($name in @($Node.PSObject.Properties.Name)){if($name -notin $metadata -and $name -notin $authority){throw "$Label unexpected schema keyword $name"}}
    $out=[ordered]@{}
    foreach($name in @($Node.PSObject.Properties.Name|Where-Object{$_ -notin $metadata}|Sort-Object)){
        $value=$Node.$name
        switch($name){
            'properties' {$children=[ordered]@{};foreach($child in @($value.PSObject.Properties.Name|Sort-Object)){$children[$child]=ConvertTo-UID0002PASchemaAuthorityNode $value.$child "$Label.$child"};$out[$name]=$children}
            'required' {$out[$name]=@($value|ForEach-Object{[string]$_}|Sort-Object)}
            'items' {$out[$name]=ConvertTo-UID0002PASchemaAuthorityNode $value "$Label[]"}
            {$_ -in @('anyOf','allOf','oneOf')} {$nodes=@($value|ForEach-Object{ConvertTo-UID0002PASchemaAuthorityNode $_ "$Label.$name"});$out[$name]=@($nodes|Sort-Object{$_|ConvertTo-Json -Depth 50 -Compress})}
            {$_ -in @('$defs','definitions')} {$children=[ordered]@{};foreach($child in @($value.PSObject.Properties.Name|Sort-Object)){$children[$child]=ConvertTo-UID0002PASchemaAuthorityNode $value.$child "$Label.$name.$child"};$out[$name]=$children}
            default {$out[$name]=$value}
        }
    }
    [pscustomobject]$out
}

function New-UID0002PAExpectedSchemaAuthority {
    param([Parameter(Mandatory=$true)]$Contract)
    $properties=[ordered]@{};$required=@()
    foreach($name in @($Contract.Properties.Keys|Sort-Object)){
        $pc=$Contract.Properties[$name];$node=[ordered]@{}
        if(@($pc.Types).Count -eq 1){$node.type=[string]$pc.Types[0]}
        else{$node.anyOf=@($pc.Types|Sort-Object|ForEach-Object{[ordered]@{type=[string]$_}})}
        if($pc.DefaultState -ceq 'Present'){$node.default=$pc.DefaultValue}
        $properties[$name]=[pscustomobject]$node;if($pc.Required){$required+=$name}
    }
    $root=[ordered]@{type='object';properties=[pscustomobject]$properties;required=@($required|Sort-Object)}
    if($Contract.AdditionalProperties -cne 'Absent'){$root.additionalProperties=($Contract.AdditionalProperties -ceq 'True')}
    [pscustomobject]$root
}

function Assert-UID0002PAToolSchemaContract {
    param([Parameter(Mandatory=$true)]$Tool,[Parameter(Mandatory=$true)]$Contract)
    $actual=ConvertTo-UID0002PASchemaAuthorityNode $Tool.inputSchema "S-PA $($Tool.name)"
    $expected=ConvertTo-UID0002PASchemaAuthorityNode (New-UID0002PAExpectedSchemaAuthority $Contract) "S-PA expected $($Tool.name)"
    $actualJson=$actual|ConvertTo-Json -Depth 80 -Compress;$expectedJson=$expected|ConvertTo-Json -Depth 80 -Compress
    $actualDigest=Get-UID0002PATextSha256 $actualJson;$expectedDigest=Get-UID0002PATextSha256 $expectedJson
    if($actualDigest -cne $expectedDigest){throw "S-PA $($Tool.name) recursive authority-schema digest mismatch"}
    [pscustomobject]@{Tool=[string]$Tool.name;Digest=$actualDigest;Passed=$true}
}

function Assert-UID0002PALiteralRoleOpenRequest {
    param([Parameter(Mandatory=$true)][ValidateSet('Transaction','P0Verifier','S1Verifier','RollbackVerifier')][string]$Role,[Parameter(Mandatory=$true)][string]$RequestJson)
    $request=Get-UID0002PARequestIdentity $RequestJson "$Role literal idb_open";$arguments=$request.Parsed.params.arguments
    $slug=@{Transaction='transaction';P0Verifier='p0-verifier';S1Verifier='s1-verifier';RollbackVerifier='rollback-verifier'}[$Role]
    if([string]$request.Parsed.method -cne 'tools/call' -or [string]$request.Parsed.params.name -cne 'idb_open' -or
        (@($arguments.PSObject.Properties.Name|Sort-Object)-join '|') -cne 'build_caches|idle_ttl_sec|init_hexrays|input_path|mode|preferred_session_id|run_auto_analysis' -or
        -not (Test-UID0002PAJsonString $arguments.input_path) -or -not (Test-UID0002PAJsonString $arguments.mode) -or
        -not (Test-UID0002PAJsonString $arguments.preferred_session_id) -or -not (Test-UID0002PAJsonBoolean $arguments.run_auto_analysis) -or
        -not (Test-UID0002PAJsonBoolean $arguments.build_caches) -or -not (Test-UID0002PAJsonBoolean $arguments.init_hexrays) -or
        -not (Test-UID0002PAJsonInteger $arguments.idle_ttl_sec) -or
        [System.IO.Path]::GetFullPath($arguments.input_path) -ine [System.IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64') -or
        $arguments.mode -cne 'force_headless' -or $arguments.run_auto_analysis -ne $false -or $arguments.build_caches -ne $false -or
        $arguments.init_hexrays -ne $false -or $arguments.idle_ttl_sec -ne 600 -or
        $arguments.preferred_session_id -notmatch "^b010-uid0002pa-$slug-[0-9]{8}-[0-9]{6}-r[1-9][0-9]*-[0-9a-f]{32}$" -or
        [string]$request.Id -cne "uid0002pa-open-$slug-$($arguments.preferred_session_id.Substring(("b010-uid0002pa-$slug-").Length))"){
        throw "$Role literal idb_open options/types/prefix mismatch"
    }
    $request
}

function Assert-UID0002PAOpenAndRuntimeNativeFields {
    param($OpenContent,$ListContent,$RuntimeContent,[string]$Label)
    if(-not $OpenContent.PSObject.Properties['success'] -or -not (Test-UID0002PAJsonBoolean $OpenContent.success)){throw "$Label open success native type mismatch"}
    $sessions=@($OpenContent.session);if($sessions.Count -ne 1){throw "$Label open session cardinality mismatch"}
    $session=$sessions[0]
    if(-not $session.PSObject.Properties['is_analyzing'] -or -not (Test-UID0002PAJsonBoolean $session.is_analyzing) -or
        -not (Test-UID0002PAJsonString $session.session_id) -or -not (Test-UID0002PAJsonString $session.input_path)){
        throw "$Label open session native fields mismatch"
    }
    foreach($row in @($ListContent.sessions)){
        if(-not (Test-UID0002PAJsonString $row.session_id) -or -not (Test-UID0002PAJsonString $row.input_path) -or
            -not (Test-UID0002PAJsonBoolean $row.is_active) -or -not (Test-UID0002PAJsonInteger $row.worker_pid)){
            throw "$Label list session native fields mismatch"
        }
    }
    if(-not (Test-UID0002PAJsonInteger $RuntimeContent.schema_version) -or -not (Test-UID0002PAJsonBoolean $RuntimeContent.ok) -or
        -not (Test-UID0002PAJsonInteger $RuntimeContent.listener.process.pid) -or
        -not (Test-UID0002PAJsonInteger $RuntimeContent.listener.process.creation_time_100ns)){
        throw "$Label runtime top native fields mismatch"
    }
    foreach($entry in @($RuntimeContent.workers)){
        $worker=$entry.attestation.worker
        if(-not (Test-UID0002PAJsonInteger $entry.route.port) -or -not (Test-UID0002PAJsonInteger $worker.process.pid) -or
            -not (Test-UID0002PAJsonInteger $worker.process.parent_pid) -or -not (Test-UID0002PAJsonInteger $worker.process.creation_time_100ns)){
            throw "$Label runtime worker PID/port native fields mismatch"
        }
        foreach($row in @($entry.supervisor_sessions)){
            if(-not (Test-UID0002PAJsonInteger $row.redirector_pid) -or -not (Test-UID0002PAJsonInteger $row.registered_pid)){
                throw "$Label runtime redirector PID native fields mismatch"
            }
        }
    }
}

$script:UID0002PAOriginalModuleManifest = ${function:Assert-UID0002PAModuleManifest}
function Get-UID0002PAModuleRowsDigest {
    param([Parameter(Mandatory=$true)]$Owner)
    $rows=@($Owner.modules|ForEach-Object{[ordered]@{
        sys_modules_name=[string]$_.sys_modules_name;file=[System.IO.Path]::GetFullPath([string]$_.file)
        spec_origin=[System.IO.Path]::GetFullPath([string]$_.spec_origin);resolved_path=[System.IO.Path]::GetFullPath([string]$_.resolved_path)
        size=[long]$_.size;mtime_ns=[long]$_.mtime_ns;ctime_ns=[long]$_.ctime_ns;sha256=[string]$_.sha256
    }})
    Get-UID0002PATextSha256 (ConvertTo-Json -InputObject $rows -Depth 20 -Compress)
}
function Assert-UID0002PAModuleManifest {
    param([Parameter(Mandatory=$true)]$Owner,[Parameter(Mandatory=$true)][ValidateSet('listener','worker')][string]$Role,[Parameter(Mandatory=$true)][string]$Label)
    $result=& $script:UID0002PAOriginalModuleManifest -Owner $Owner -Role $Role -Label $Label
    $computed=Get-UID0002PAModuleRowsDigest $Owner
    if([string]$Owner.implementation_manifest_sha256 -cne $computed){throw "$Label module-row aggregate digest mismatch"}
    return $result
}

$script:UID0002PAOriginalRuntimeAttestation = ${function:Assert-UID0002PARuntimeAttestation}
function Assert-UID0002PARuntimeAttestation {
    param($Envelope,[string]$AttestationRequestJson,$ListEnvelope,[string]$ListRequestJson,$RoleBinding,$State)
    $runtime=Get-UID0002PAStructuredContent $Envelope $AttestationRequestJson 'RA-PA native preflight'
    $list=Get-UID0002PAStructuredContent $ListEnvelope $ListRequestJson 'RA-PA native list preflight'
    $open=[pscustomobject]@{success=$true;session=[pscustomobject]@{session_id=[string]$RoleBinding.Database;input_path=[string]$RoleBinding.CanonicalPath;is_analyzing=$false}}
    Assert-UID0002PAOpenAndRuntimeNativeFields $open $list $runtime 'RA-PA'
    & $script:UID0002PAOriginalRuntimeAttestation @PSBoundParameters
}

$script:UID0002PAOriginalPostRetirementAttestation = ${function:Assert-UID0002PAPostRetirementAttestation}
function Assert-UID0002PAPostRetirementAttestation {
    param($Envelope,[string]$RequestJson,$RoleBinding,$State)
    $request=Get-UID0002PARequestIdentity $RequestJson 'RA-PA post-retirement strict request'
    if([string]$request.Parsed.method -cne 'tools/call' -or [string]$request.Parsed.params.name -cne 'runtime_attestation'){
        throw 'RA-PA post-retirement request method mismatch'
    }
    & $script:UID0002PAOriginalPostRetirementAttestation @PSBoundParameters
}

function New-UID0002PAClosedControllerContext { throw 'CT-PA direct controller construction disabled' }
function Invoke-UID0002PAControllerRequest { throw 'CT-PA direct dispatch disabled' }
function New-UID0002PASaveAttempt { throw 'SV-PA public save-attempt construction disabled' }
function Register-UID0002PASoleSaveDispatch { throw 'SV-PA public save registration disabled' }
function Complete-UID0002PASaveTransport { throw 'SV-PA public save classifier disabled' }
function Complete-UID0002PADiskClassification { throw 'SV-PA public disk classifier disabled' }
function Restore-UID0002PABackup { throw 'RS-PA public restore disabled' }
function Set-UID0002PAVerifierFailure { throw 'VR-PA public F1 transition disabled' }
~~~

## Removed Block R024

- SHA256: `6228F7B849E59950E71644BCB543D0E0C71EB336D44C56BA4911839F4FC0CC13`
- Language: `powershell`
- Bytes: `141501`
- First recovered timestamp: `2026-08-09T15:30:56.412Z`
- Session provenance: rollout-2026-08-08T17-46-23-019fe357-64cc-7ca3-ad27-c9c336afc6af.jsonl line 5673 (2026-08-09T15:30:56.412Z); rollout-2026-08-08T17-46-23-019fe357-64cc-7ca3-ad27-c9c336afc6af.jsonl line 5674 (2026-08-09T15:30:56.800Z)

~~~powershell
Set-StrictMode -Version 2.0
$ErrorActionPreference='Stop'
$WarningPreference='Stop'
$InformationPreference='Stop'
$VerbosePreference='SilentlyContinue'
$DebugPreference='SilentlyContinue'
$ProgressPreference='SilentlyContinue'

$uid0002paV6Launchers=@('Initialize-UID0002PAV6IsolatedAuthority','Invoke-UID0002PAClosedTransaction','Invoke-UID0002PAHostileStaticFixtures','Invoke-UID0002PAV6ConcurrentWrapperHostile','Get-UID0002PAV6CanonicalRowDigest','Invoke-UID0002PAV6BoundaryHostiles')
if('UID0002PAV6IsolatedHost' -as [type]){throw 'CP6-PA preloaded authoritative host type refused'}
foreach($uid0002paV6Launcher in $uid0002paV6Launchers){if($null-ne(Microsoft.PowerShell.Core\Get-Command -Name $uid0002paV6Launcher -ErrorAction SilentlyContinue)){throw "CP6-PA preloaded authoritative launcher refused: $uid0002paV6Launcher"}}
Remove-Variable uid0002paV6Launcher,uid0002paV6Launchers -ErrorAction SilentlyContinue

function Initialize-UID0002PAV6IsolatedAuthority {
    [CmdletBinding()]param()
    if('UID0002PAV6IsolatedHost' -as [type]){throw 'CP6-PA preloaded authoritative host type refused'}
    $source=@'
using System;
using System.Collections;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Threading.Tasks;
using System.Web.Script.Serialization;
[assembly: AssemblyTitle("UID0002PA.SealedHost")]
[assembly: AssemblyDescription("Report-owned UID0002PA sealed child boundary")]
[assembly: AssemblyVersion("6.2.0.0")]
[assembly: ComVisible(false)]

public sealed class UID0002PAV6Attestation {
  public readonly string ReportPath,PayloadSHA256,SourceSHA256,ApiSHA256,MethodManifestSHA256,AssemblySHA256,PublicEntrySHA256,FixtureEntrySHA256;
  public readonly int FenceCount;
  public readonly bool MutableHostFields;
  internal UID0002PAV6Attestation(string path,string payload,string source,string api,string methods,string assembly,string entry,string fixture,int fences,bool mutable) {
    ReportPath=path;PayloadSHA256=payload;SourceSHA256=source;ApiSHA256=api;MethodManifestSHA256=methods;AssemblySHA256=assembly;PublicEntrySHA256=entry;FixtureEntrySHA256=fixture;FenceCount=fences;MutableHostFields=mutable;
  }
}

public sealed class UID0002PAV6CleanupReceipt {
  public readonly string Classification,BeforePrefixSHA256,BaselinePrefixSHA256,AfterPrefixSHA256;
  public readonly int HistoricalInventoryCount,HistoricalPresentBefore,HistoricalRemoved,HistoricalAbsentAfter,PreexistingPreserved,NewRootsObserved,NewRootsRemoved,NewRootsAbsentAfter,BeforePrefixCount,BaselinePrefixCount,AfterPrefixCount;
  public readonly bool HistoricalClosed,NewGenerationClosed,BaselineReproduced;
  internal UID0002PAV6CleanupReceipt(string classification,int historicalCount,int historicalPresent,int historicalRemoved,int historicalAbsent,int preexisting,int newObserved,int newRemoved,int newAbsent,int beforeCount,int baselineCount,int afterCount,string beforeSha,string baselineSha,string afterSha,bool historicalClosed,bool generationClosed,bool baselineReproduced){Classification=classification;HistoricalInventoryCount=historicalCount;HistoricalPresentBefore=historicalPresent;HistoricalRemoved=historicalRemoved;HistoricalAbsentAfter=historicalAbsent;PreexistingPreserved=preexisting;NewRootsObserved=newObserved;NewRootsRemoved=newRemoved;NewRootsAbsentAfter=newAbsent;BeforePrefixCount=beforeCount;BaselinePrefixCount=baselineCount;AfterPrefixCount=afterCount;BeforePrefixSHA256=beforeSha;BaselinePrefixSHA256=baselineSha;AfterPrefixSHA256=afterSha;HistoricalClosed=historicalClosed;NewGenerationClosed=generationClosed;BaselineReproduced=baselineReproduced;}
}

public sealed class UID0002PAV6Transcript {
  public readonly string Mode,Json,SHA256,ResultJson,ResultSHA256,InvocationNonce,ExecutableSHA256,PayloadSHA256,SourceSHA256,ApiSHA256,MethodManifestSHA256,AssemblySHA256,PublicEntrySHA256,FixtureEntrySHA256,CanonicalDatabase,DatabaseSession,Outcome,BeforeTargetReceipt,AfterTargetReceipt,BeforeTcpReceipt,AfterTcpReceipt;
  public readonly string FileSystemCensusBeforeSHA256,FileSystemCensusAfterSHA256;
  public readonly int Sequence,ChildPID,ListenerPIDBefore,ListenerPIDAfter,ObservedChildMcpConnections;
  public readonly long ChildGenerationUtcTicks,SaveDispatches,TransportCalls,ExternalTargetEffects,McpEffects,IdaEffects,FileSystemEffects,ProcessEffects;
  public readonly bool ExactChildRetired,OneTimeConsumed,BeforeJournalExists,AfterJournalExists,BeforeBackupExists,AfterBackupExists;
  public readonly UID0002PAV6ProcessReceipt ProcessReceipt;
  public UID0002PAV6CleanupReceipt CleanupReceipt { get; private set; }
  internal UID0002PAV6Transcript(string mode,string json,string sha,string resultJson,string resultSha,string nonce,int sequence,int pid,long generation,string executable,bool retired,bool consumed,string payload,string source,string api,string methods,string assembly,string entry,string fixture,string canonical,string session,string outcome,long saves,long transports,long external,long mcp,long ida,long fileEffects,long processEffects,string beforeTarget,string afterTarget,string beforeTcp,string afterTcp,int listenerBefore,int listenerAfter,int observedChildMcp,bool beforeJournal,bool afterJournal,bool beforeBackup,bool afterBackup,string fileBefore,string fileAfter,UID0002PAV6ProcessReceipt processReceipt) {
    Mode=mode;Json=json;SHA256=sha;ResultJson=resultJson;ResultSHA256=resultSha;InvocationNonce=nonce;Sequence=sequence;ChildPID=pid;ChildGenerationUtcTicks=generation;ExecutableSHA256=executable;ExactChildRetired=retired;OneTimeConsumed=consumed;PayloadSHA256=payload;SourceSHA256=source;ApiSHA256=api;MethodManifestSHA256=methods;AssemblySHA256=assembly;PublicEntrySHA256=entry;FixtureEntrySHA256=fixture;CanonicalDatabase=canonical;DatabaseSession=session;Outcome=outcome;SaveDispatches=saves;TransportCalls=transports;ExternalTargetEffects=external;McpEffects=mcp;IdaEffects=ida;FileSystemEffects=fileEffects;ProcessEffects=processEffects;BeforeTargetReceipt=beforeTarget;AfterTargetReceipt=afterTarget;BeforeTcpReceipt=beforeTcp;AfterTcpReceipt=afterTcp;ListenerPIDBefore=listenerBefore;ListenerPIDAfter=listenerAfter;ObservedChildMcpConnections=observedChildMcp;BeforeJournalExists=beforeJournal;AfterJournalExists=afterJournal;BeforeBackupExists=beforeBackup;AfterBackupExists=afterBackup;FileSystemCensusBeforeSHA256=fileBefore;FileSystemCensusAfterSHA256=fileAfter;ProcessReceipt=processReceipt;
  }
  internal void BindCleanup(UID0002PAV6CleanupReceipt receipt){if(receipt==null||CleanupReceipt!=null)throw new InvalidOperationException("CL6-PA transcript cleanup receipt bind mismatch");CleanupReceipt=receipt;}
}

public sealed class UID0002PAV6ReplayReceipt {
  public readonly int Rejections,ChildPID;
  public readonly bool ExactChildRetired;
  public readonly long ChildGenerationUtcTicks,SaveDispatches,TransportCalls,ExternalTargetEffects,McpEffects,IdaEffects,FileSystemEffects,ProcessEffects;
  public readonly string TranscriptSHA256;
  public readonly UID0002PAV6ProcessReceipt ProcessReceipt;
  public readonly UID0002PAV6CleanupReceipt CleanupReceipt;
  internal UID0002PAV6ReplayReceipt(int rejections,UID0002PAV6Transcript transcript){Rejections=rejections;ChildPID=transcript.ChildPID;ChildGenerationUtcTicks=transcript.ChildGenerationUtcTicks;ExactChildRetired=transcript.ExactChildRetired;SaveDispatches=transcript.SaveDispatches;TransportCalls=transcript.TransportCalls;ExternalTargetEffects=transcript.ExternalTargetEffects;McpEffects=transcript.McpEffects;IdaEffects=transcript.IdaEffects;FileSystemEffects=transcript.FileSystemEffects;ProcessEffects=transcript.ProcessEffects;TranscriptSHA256=transcript.SHA256;ProcessReceipt=transcript.ProcessReceipt;CleanupReceipt=transcript.CleanupReceipt;}
}

public sealed class UID0002PAV6ProcessReceipt {
  public readonly string Scenario,Outcome,SeenGenerationSHA256,ProcessCensusBeforeSHA256,ProcessCensusAfterSHA256,NetworkCensusBeforeSHA256,NetworkCensusAfterSHA256;
  public readonly int ChildPID,ExitCode,TotalProcesses,PeakActiveProcesses,ObservedGenerations,DescendantsObserved,UnresolvedGenerationEvents,ActiveAfterContainment,SameGenerationsAlive,OwnedNetworkConnectionsAfter;
  public readonly long ChildGenerationUtcTicks,StdoutCharacters,StderrCharacters;
  public readonly bool CompletionPortBound,GenerationCensusComplete,WatcherTerminal,WatcherSucceeded,InputDeliveryTerminal,JobAssigned,ImmediateGenerationRetired,JobEmpty,DrainsTerminal,DrainsSucceeded,DrainsPendingBeforeContainment,ParentExitedWithLiveDescendant;
  internal UID0002PAV6ProcessReceipt(string scenario,string outcome,int pid,long generation,int exitCode,int total,int peak,int observed,int descendants,int unresolved,int activeAfter,int sameAlive,int ownedNetworkAfter,long stdoutChars,long stderrChars,bool portBound,bool censusComplete,bool watcherTerminal,bool watcherSucceeded,bool inputTerminal,bool assigned,bool immediateRetired,bool jobEmpty,bool drainsTerminal,bool drainsSucceeded,bool drainsPending,bool parentExited,string seenSha,string censusBefore,string censusAfter,string networkBefore,string networkAfter){Scenario=scenario;Outcome=outcome;ChildPID=pid;ChildGenerationUtcTicks=generation;ExitCode=exitCode;TotalProcesses=total;PeakActiveProcesses=peak;ObservedGenerations=observed;DescendantsObserved=descendants;UnresolvedGenerationEvents=unresolved;ActiveAfterContainment=activeAfter;SameGenerationsAlive=sameAlive;OwnedNetworkConnectionsAfter=ownedNetworkAfter;StdoutCharacters=stdoutChars;StderrCharacters=stderrChars;CompletionPortBound=portBound;GenerationCensusComplete=censusComplete;WatcherTerminal=watcherTerminal;WatcherSucceeded=watcherSucceeded;InputDeliveryTerminal=inputTerminal;JobAssigned=assigned;ImmediateGenerationRetired=immediateRetired;JobEmpty=jobEmpty;DrainsTerminal=drainsTerminal;DrainsSucceeded=drainsSucceeded;DrainsPendingBeforeContainment=drainsPending;ParentExitedWithLiveDescendant=parentExited;SeenGenerationSHA256=seenSha;ProcessCensusBeforeSHA256=censusBefore;ProcessCensusAfterSHA256=censusAfter;NetworkCensusBeforeSHA256=networkBefore;NetworkCensusAfterSHA256=networkAfter;}
}

public sealed class UID0002PAV6ProcessHostileReceipt {
  public readonly int Passed,Failed;
  public readonly string CanonicalSHA256;
  public readonly UID0002PAV6ProcessReceipt[] Cases;
  static string StableCanonicalSHA256(UID0002PAV6ProcessReceipt[] cases){StringBuilder rows=new StringBuilder();for(int n=0;n<cases.Length;n++)rows.Append((n+1).ToString("D2",System.Globalization.CultureInfo.InvariantCulture)).Append('|').Append(cases[n].Scenario).Append('|').Append(cases[n].Outcome).Append('|').Append(n==1||n==2||n==5?"DESCENDANT_REQUIRED":"DESCENDANT_NOT_REQUIRED").Append('|').Append(cases[n].DrainsPendingBeforeContainment?'1':'0').Append('|').Append(cases[n].DrainsSucceeded?'1':'0').Append('\n');byte[] bytes=new UTF8Encoding(false,true).GetBytes(rows.ToString());using(SHA256 hash=SHA256.Create())return BitConverter.ToString(hash.ComputeHash(bytes)).Replace("-","");}
  internal UID0002PAV6ProcessHostileReceipt(int passed,int failed,string liveCensusSha,UID0002PAV6ProcessReceipt[] cases){Passed=passed;Failed=failed;CanonicalSHA256=StableCanonicalSHA256(cases);Cases=cases;}
}

public sealed class UID0002PAV6ProbeReceipt {
  public readonly int Workers,Iterations;
  public readonly bool AuthorityStable,MutatedCopyRejected;
  public readonly string AuthoritySHA256;
  internal UID0002PAV6ProbeReceipt(int workers,int iterations,bool stable,bool rejected,string sha){Workers=workers;Iterations=iterations;AuthorityStable=stable;MutatedCopyRejected=rejected;AuthoritySHA256=sha;}
}

public sealed class UID0002PAV6ProductionTestControls {
  public readonly UID0002PAV6Transcript Accepted;
  public readonly UID0002PAV6RejectedException FalseZero,NonzeroExternal;
  internal UID0002PAV6ProductionTestControls(UID0002PAV6Transcript accepted,UID0002PAV6RejectedException falseZero,UID0002PAV6RejectedException nonzero){Accepted=accepted;FalseZero=falseZero;NonzeroExternal=nonzero;}
}

public sealed class UID0002PAV6RejectedException : Exception {
  public readonly string RejectionCode,Stage;
  public readonly int ChildPID;
  public readonly long ChildGenerationUtcTicks,SaveDispatches,TransportCalls,FileSystemEffects,McpEffects,IdaEffects,ProcessEffects;
  public readonly bool ExactChildRetired;
  public readonly UID0002PAV6ProcessReceipt ProcessReceipt;
  public UID0002PAV6CleanupReceipt CleanupReceipt { get; private set; }
  internal UID0002PAV6RejectedException(string code,string stage):this(code,stage,0,0,true,0,0,0,0,0,0){}
  internal UID0002PAV6RejectedException(string code,string stage,int pid,long generation,bool retired,long saves,long transports,long fileEffects,long mcp,long ida,long processEffects):this(code,stage,pid,generation,retired,saves,transports,fileEffects,mcp,ida,processEffects,null){}
  internal UID0002PAV6RejectedException(string code,string stage,int pid,long generation,bool retired,long saves,long transports,long fileEffects,long mcp,long ida,long processEffects,UID0002PAV6ProcessReceipt processReceipt):base(code){RejectionCode=code;Stage=stage;ChildPID=pid;ChildGenerationUtcTicks=generation;ExactChildRetired=retired;SaveDispatches=saves;TransportCalls=transports;FileSystemEffects=fileEffects;McpEffects=mcp;IdaEffects=ida;ProcessEffects=processEffects;ProcessReceipt=processReceipt;}
  internal void BindCleanup(UID0002PAV6CleanupReceipt receipt){if(receipt==null||CleanupReceipt!=null)throw new InvalidOperationException("CL6-PA rejection cleanup receipt bind mismatch");CleanupReceipt=receipt;}
}

public sealed class UID0002PAV6RawJsonScanner {
  readonly string text;int pos;
  UID0002PAV6RawJsonScanner(string value){text=value;pos=0;}
  public static void RejectDuplicates(string value,string label){if(value==null)throw new UID0002PAV6RejectedException("TR6-PA null raw JSON: "+label,"Transcript");UID0002PAV6RawJsonScanner p=new UID0002PAV6RawJsonScanner(value);p.ReadValue("$");p.SkipWhite();if(p.pos!=p.text.Length)throw new UID0002PAV6RejectedException("TR6-PA trailing raw JSON: "+label,"Transcript");}
  void SkipWhite(){while(pos<text.Length&&(text[pos]==' '||text[pos]=='\t'||text[pos]=='\r'||text[pos]=='\n'))pos++;}
  void Need(char c){SkipWhite();if(pos>=text.Length||text[pos]!=c)throw new UID0002PAV6RejectedException("TR6-PA malformed raw JSON","Transcript");pos++;}
  void ReadValue(string path){SkipWhite();if(pos>=text.Length)throw new UID0002PAV6RejectedException("TR6-PA truncated raw JSON","Transcript");char c=text[pos];if(c=='{'){ReadObject(path);return;}if(c=='['){ReadArray(path);return;}if(c=='\"'){ReadString();return;}if(c=='t'){ReadLiteral("true");return;}if(c=='f'){ReadLiteral("false");return;}if(c=='n'){ReadLiteral("null");return;}ReadNumber();}
  void ReadObject(string path){Need('{');SkipWhite();HashSet<string> keys=new HashSet<string>(StringComparer.Ordinal);if(pos<text.Length&&text[pos]=='}'){pos++;return;}for(;;){SkipWhite();if(pos>=text.Length||text[pos]!='\"')throw new UID0002PAV6RejectedException("TR6-PA object key mismatch","Transcript");string key=ReadString();if(!keys.Add(key))throw new UID0002PAV6RejectedException("TR6-PA duplicate raw JSON member: "+path+"."+key,"Transcript");Need(':');ReadValue(path+"."+key);SkipWhite();if(pos<text.Length&&text[pos]==','){pos++;continue;}if(pos<text.Length&&text[pos]=='}'){pos++;return;}throw new UID0002PAV6RejectedException("TR6-PA object terminator mismatch","Transcript");}}
  void ReadArray(string path){Need('[');SkipWhite();int index=0;if(pos<text.Length&&text[pos]==']'){pos++;return;}for(;;){ReadValue(path+"["+index+"]");index++;SkipWhite();if(pos<text.Length&&text[pos]==','){pos++;continue;}if(pos<text.Length&&text[pos]==']'){pos++;return;}throw new UID0002PAV6RejectedException("TR6-PA array terminator mismatch","Transcript");}}
  string ReadString(){Need('\"');StringBuilder b=new StringBuilder();while(pos<text.Length){char c=text[pos++];if(c=='\"')return b.ToString();if(c<' ')throw new UID0002PAV6RejectedException("TR6-PA raw JSON control character","Transcript");if(c!='\\'){b.Append(c);continue;}if(pos>=text.Length)throw new UID0002PAV6RejectedException("TR6-PA truncated raw JSON escape","Transcript");char e=text[pos++];if(e=='\"'||e=='\\'||e=='/'){b.Append(e);continue;}if(e=='b'){b.Append('\b');continue;}if(e=='f'){b.Append('\f');continue;}if(e=='n'){b.Append('\n');continue;}if(e=='r'){b.Append('\r');continue;}if(e=='t'){b.Append('\t');continue;}if(e=='u'){if(pos+4>text.Length)throw new UID0002PAV6RejectedException("TR6-PA truncated unicode escape","Transcript");int value=0;for(int i=0;i<4;i++){char h=text[pos++];int d=(h>='0'&&h<='9')?h-'0':(h>='a'&&h<='f')?h-'a'+10:(h>='A'&&h<='F')?h-'A'+10:-1;if(d<0)throw new UID0002PAV6RejectedException("TR6-PA invalid unicode escape","Transcript");value=(value<<4)|d;}b.Append((char)value);continue;}throw new UID0002PAV6RejectedException("TR6-PA invalid raw JSON escape","Transcript");}throw new UID0002PAV6RejectedException("TR6-PA unterminated raw JSON string","Transcript");}
  void ReadLiteral(string literal){if(pos+literal.Length>text.Length||String.CompareOrdinal(text,pos,literal,0,literal.Length)!=0)throw new UID0002PAV6RejectedException("TR6-PA invalid raw JSON literal","Transcript");pos+=literal.Length;}
  void ReadNumber(){int start=pos;if(text[pos]=='-')pos++;if(pos>=text.Length)throw new UID0002PAV6RejectedException("TR6-PA invalid raw JSON number","Transcript");if(text[pos]=='0')pos++;else{if(text[pos]<'1'||text[pos]>'9')throw new UID0002PAV6RejectedException("TR6-PA invalid raw JSON number","Transcript");while(pos<text.Length&&text[pos]>='0'&&text[pos]<='9')pos++;}if(pos<text.Length&&text[pos]=='.'){pos++;int d=pos;while(pos<text.Length&&text[pos]>='0'&&text[pos]<='9')pos++;if(pos==d)throw new UID0002PAV6RejectedException("TR6-PA invalid raw JSON fraction","Transcript");}if(pos<text.Length&&(text[pos]=='e'||text[pos]=='E')){pos++;if(pos<text.Length&&(text[pos]=='+'||text[pos]=='-'))pos++;int d=pos;while(pos<text.Length&&text[pos]>='0'&&text[pos]<='9')pos++;if(pos==d)throw new UID0002PAV6RejectedException("TR6-PA invalid raw JSON exponent","Transcript");}if(pos==start)throw new UID0002PAV6RejectedException("TR6-PA invalid raw JSON number","Transcript");}
}

public static class UID0002PAV6IsolatedHost {
  static readonly ConcurrentDictionary<string,byte> ConsumedTranscriptHashes=new ConcurrentDictionary<string,byte>(StringComparer.Ordinal);
  public const string ReportPath=@"E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B010\research\0002PA-ConfigEntryBlockReleaseOwnedBuffers-source-quality.md";
  public const string CanonicalDatabase=@"E:\NTK\Resources\NexusTK\NexusTK.exe.i64";
  public const string ExpectedPayloadSHA256="C5E686707DA8BC80778FC4B391451900FBF82498D45FB65FE31F6D5A05E10528";
  public const string ExpectedSourceSHA256="E94F3BFF320918B7402EB3A47E64948D05997505BAA0351A11A41AB1D1CE4B9B";
  public const string ExpectedApiSHA256="27A933CADB6A214C3ABE3ADFA0215CB7AC4FA6F5B24CD3E46318A8C371EE0316";
  public const string ExpectedMethodManifestSHA256="B3FF7036C31E9266D459D7DB09E7E7DB9F4E8B9F7E45D44A0A4F2A089A85C1EA";
  public const string ExpectedAssemblySHA256="4CB87466A9C9F3BEF2A227F13290DC35D7CC7207892F2A776E58DD4C8C4E2027";
  public const string ExpectedPublicEntrySHA256="0EEDF0AEF29A5B8AB893FC98BB8CC4ED3B5001C44E4ADD956EE2FB9EF5B8077C";
  public const string ExpectedFixtureEntrySHA256="BD88616FB2010B50EDF678BB5902AAC3D7648578E30B0EA1B36D43D0F05CE384";
  public const string TranscriptMarker="UID0002PA-V6-TRANSCRIPT";

  static string Sha256(byte[] bytes){using(SHA256 sha=SHA256.Create())return BitConverter.ToString(sha.ComputeHash(bytes)).Replace("-","");}
  static string Sha256(string text){return Sha256(new UTF8Encoding(false,true).GetBytes(text));}
  static string FileSha256(string path){using(FileStream s=new FileStream(path,FileMode.Open,FileAccess.Read,FileShare.ReadWrite|FileShare.Delete))using(SHA256 sha=SHA256.Create())return BitConverter.ToString(sha.ComputeHash(s)).Replace("-","");}
  static string NormalizeSource(string source){const string pattern="(?m)^(  public const string Expected(?:Source|Api|MethodManifest|Assembly|PublicEntry|FixtureEntry)SHA256=\")[^\"]+(\";)$";if(source==null||source.IndexOf('\r')>=0||!source.EndsWith("\n",StringComparison.Ordinal))throw new UID0002PAV6RejectedException("CP6-PA source normalization shape mismatch","SourceIdentity");MatchCollection rows=Regex.Matches(source,pattern);if(rows.Count!=6)throw new UID0002PAV6RejectedException("CP6-PA source normalization identity count mismatch","SourceIdentity");return Regex.Replace(source,pattern,"$1__NORMALIZED__$2");}
  static bool HasMutableHostFields(){foreach(FieldInfo f in typeof(UID0002PAV6IsolatedHost).GetFields(BindingFlags.Public|BindingFlags.NonPublic|BindingFlags.Static)){if(f.IsLiteral)continue;if(f.Name=="ConsumedTranscriptHashes"&&f.IsInitOnly&&f.FieldType==typeof(ConcurrentDictionary<string,byte>))continue;return true;}return false;}
  static string ProtectedReceipt(){int listener,ignored;TcpReceipt(0,out listener,out ignored);return FileTuple(CanonicalDatabase)+"|journal="+File.Exists(CanonicalDatabase+".uid0002pa-v4.journal")+"|backup="+File.Exists(CanonicalDatabase+".uid0002pa-v4.backup")+"|listener="+listener;}
  static string MethodSignature(MethodInfo m){ParameterInfo[] p=m.GetParameters();StringBuilder b=new StringBuilder();b.Append(m.Name).Append('|').Append(m.ReturnType.FullName);for(int i=0;i<p.Length;i++)b.Append('|').Append(p[i].ParameterType.FullName);return b.ToString();}
  static string CurrentApiSHA256(){List<string> rows=new List<string>();foreach(MethodInfo m in typeof(UID0002PAV6IsolatedHost).GetMethods(BindingFlags.Public|BindingFlags.Static|BindingFlags.DeclaredOnly))rows.Add(MethodSignature(m));rows.Sort(StringComparer.Ordinal);return Sha256(String.Join("\n",rows.ToArray())+"\n");}
  static string CurrentMethodManifestSHA256(){List<string> rows=new List<string>();foreach(MethodInfo m in typeof(UID0002PAV6IsolatedHost).GetMethods(BindingFlags.Public|BindingFlags.NonPublic|BindingFlags.Static|BindingFlags.DeclaredOnly)){if(m.Name=="VerifySelf"||m.Name=="InspectPackage")continue;MethodBody body=m.GetMethodBody();if(body==null)rows.Add(MethodSignature(m)+"|NO_IL|"+((int)m.Attributes).ToString(System.Globalization.CultureInfo.InvariantCulture));else rows.Add(MethodSignature(m)+"|"+Sha256(body.GetILAsByteArray()));}rows.Sort(StringComparer.Ordinal);return Sha256(String.Join("\n",rows.ToArray())+"\n");}
  static string CurrentAssemblySHA256(){Assembly a=typeof(UID0002PAV6IsolatedHost).Assembly;AssemblyTitleAttribute t=(AssemblyTitleAttribute)Attribute.GetCustomAttribute(a,typeof(AssemblyTitleAttribute));AssemblyDescriptionAttribute d=(AssemblyDescriptionAttribute)Attribute.GetCustomAttribute(a,typeof(AssemblyDescriptionAttribute));ComVisibleAttribute c=(ComVisibleAttribute)Attribute.GetCustomAttribute(a,typeof(ComVisibleAttribute));List<string> types=new List<string>();foreach(Type type in a.GetTypes())if(!type.IsDefined(typeof(System.Runtime.CompilerServices.CompilerGeneratedAttribute),false))types.Add(type.FullName);types.Sort(StringComparer.Ordinal);return Sha256(a.GetName().Version.ToString()+"|"+(t==null?"":t.Title)+"|"+(d==null?"":d.Description)+"|"+(c==null?"":c.Value.ToString())+"|"+String.Join(";",types.ToArray()));}

  static string ReadPackage(out int fences,out string sourceHash){string report;using(FileStream s=new FileStream(ReportPath,FileMode.Open,FileAccess.Read,FileShare.Read))using(StreamReader r=new StreamReader(s,new UTF8Encoding(false,true),false,65536))report=r.ReadToEnd();if(report.IndexOf('\r')>=0)throw new UID0002PAV6RejectedException("PK6-PA report is not LF-only","ReadPackage");MatchCollection m=Regex.Matches(report,"(?ms)^~~~powershell\\n(.*?)^~~~[ \\t]*$");fences=m.Count;if(fences!=11)throw new UID0002PAV6RejectedException("PK6-PA exact fence count mismatch","ReadPackage");StringBuilder p=new StringBuilder();for(int i=0;i<10;i++)p.Append(m[i].Groups[1].Value).Append('\n');string payload=p.ToString();if(!String.Equals(Sha256(payload),ExpectedPayloadSHA256,StringComparison.Ordinal))throw new UID0002PAV6RejectedException("PK6-PA first-ten payload hash mismatch","ReadPackage");Match sm=Regex.Match(m[10].Groups[1].Value,"(?ms)^    \\$source=@'\\n(.*?)^'@[ \\t]*$");if(!sm.Success)throw new UID0002PAV6RejectedException("PK6-PA report-owned source missing","ReadPackage");sourceHash=Sha256(NormalizeSource(sm.Groups[1].Value));return payload;}
  static void VerifySelf(){int fences;string source;ReadPackage(out fences,out source);Assembly a=typeof(UID0002PAV6IsolatedHost).Assembly;AssemblyTitleAttribute title=(AssemblyTitleAttribute)Attribute.GetCustomAttribute(a,typeof(AssemblyTitleAttribute));if(title==null||title.Title!="UID0002PA.SealedHost"||a.GetName().Version.ToString()!="6.2.0.0")throw new UID0002PAV6RejectedException("CP6-PA sealed assembly identity mismatch","VerifySelf");if(HasMutableHostFields())throw new UID0002PAV6RejectedException("CP6-PA mutable compiled host field","VerifySelf");if(source!=ExpectedSourceSHA256)throw new UID0002PAV6RejectedException("CP6-PA report-owned source hash mismatch","VerifySelf");if(CurrentApiSHA256()!=ExpectedApiSHA256)throw new UID0002PAV6RejectedException("CP6-PA public API hash mismatch","VerifySelf");if(CurrentMethodManifestSHA256()!=ExpectedMethodManifestSHA256)throw new UID0002PAV6RejectedException("CP6-PA method IL manifest mismatch","VerifySelf");if(CurrentAssemblySHA256()!=ExpectedAssemblySHA256)throw new UID0002PAV6RejectedException("CP6-PA assembly identity hash mismatch","VerifySelf");}
  static void ExactKeys(IDictionary<string,object> d,string[] expected,string label){if(d==null||d.Count!=expected.Length)throw new UID0002PAV6RejectedException("TR6-PA exact key count mismatch: "+label,"Transcript");foreach(string k in expected)if(!d.ContainsKey(k))throw new UID0002PAV6RejectedException("TR6-PA missing key: "+label+"."+k,"Transcript");}
  static IDictionary<string,object> Dict(object v,string label){IDictionary<string,object> d=v as IDictionary<string,object>;if(d==null)throw new UID0002PAV6RejectedException("TR6-PA object mismatch: "+label,"Transcript");return d;}
  static string Str(object v,string label){string s=v as string;if(s==null)throw new UID0002PAV6RejectedException("TR6-PA string mismatch: "+label,"Transcript");return s;}
  static long Int64Value(object v,string label){if(v is int)return (int)v;if(v is long)return (long)v;throw new UID0002PAV6RejectedException("TR6-PA integer mismatch: "+label,"Transcript");}
  static bool BoolValue(object v,string label){if(!(v is bool))throw new UID0002PAV6RejectedException("TR6-PA boolean mismatch: "+label,"Transcript");return (bool)v;}
  static IList ListValue(object v,string label){IList a=v as IList;if(a==null)throw new UID0002PAV6RejectedException("TR6-PA array mismatch: "+label,"Transcript");return a;}
  static string[] StringArray(object v,string label){IList a=ListValue(v,label);string[] rows=new string[a.Count];for(int i=0;i<a.Count;i++)rows[i]=Str(a[i],label+"["+i+"]");return rows;}
  static string Decode64(string value,string label){try{return new UTF8Encoding(false,true).GetString(Convert.FromBase64String(value));}catch{throw new UID0002PAV6RejectedException("TR6-PA base64 mismatch: "+label,"Transcript");}}
  static bool SameTuple(IDictionary<string,object> a,IDictionary<string,object> b){foreach(string k in new string[]{"length","last_write_time_utc_ticks","sha256","volume_serial","file_index"})if(!Object.Equals(a[k],b[k]))return false;return String.Equals(Str(a["full_path"],"tuple path"),Str(b["full_path"],"tuple path"),StringComparison.OrdinalIgnoreCase);}
  static IDictionary<string,object> ProductionTuple(object value,string label,string expectedPath){IDictionary<string,object> d=Dict(value,label);ExactKeys(d,new string[]{"full_path","length","last_write_time_utc_ticks","sha256","volume_serial","file_index"},label);string path=Path.GetFullPath(Str(d["full_path"],label+".full_path"));if(expectedPath!=null&&!String.Equals(path,Path.GetFullPath(expectedPath),StringComparison.OrdinalIgnoreCase))throw new UID0002PAV6RejectedException("TR6-PA tuple path mismatch: "+label,"Transcript");if(Int64Value(d["length"],label+".length")<0||Int64Value(d["last_write_time_utc_ticks"],label+".ticks")<=0||Int64Value(d["volume_serial"],label+".volume")<0||!Regex.IsMatch(Str(d["sha256"],label+".sha"),"^[0-9A-F]{64}$")||!Regex.IsMatch(Str(d["file_index"],label+".index"),"^[0-9]+$"))throw new UID0002PAV6RejectedException("TR6-PA native tuple type/value mismatch: "+label,"Transcript");return d;}
  static long CountProductionSends(string resultJson){if(String.IsNullOrEmpty(resultJson))return 0;JavaScriptSerializer j=new JavaScriptSerializer();IDictionary<string,object> result=Dict(j.DeserializeObject(resultJson),"rejected-production");string[] log=StringArray(result["transport_log"],"rejected-production.transport_log");long count=0;foreach(string line in log)if(line.StartsWith("SEND|",StringComparison.Ordinal))count++;return count;}
  static string ValidateProductionSend(IDictionary<string,object> rq,IDictionary<string,object> rp,string expectedCanonical,HashSet<string> ids,List<string> operations,ref long saveCount,ref long mutationCount,ref long runtimeWorkerCount){
    string method=Str(rq["method"],"request.method"),id=Str(rq["id"],"request.id");if(!ids.Add(id)||Str(rq["jsonrpc"],"request.jsonrpc")!="2.0")throw new UID0002PAV6RejectedException("TR6-PA request identity mismatch","Transcript");ExactKeys(rp,new string[]{"jsonrpc","id","result"},"response");if(Str(rp["jsonrpc"],"response.jsonrpc")!="2.0"||Str(rp["id"],"response.id")!=id)throw new UID0002PAV6RejectedException("TR6-PA response identity mismatch","Transcript");IDictionary<string,object> rr=Dict(rp["result"],"response.result");
    if(method=="tools/list"){operations.Add("tools/list");ExactKeys(rq,new string[]{"jsonrpc","id","method","params"},"tools-list-request");ExactKeys(Dict(rq["params"],"tools-list.params"),new string[]{},"tools-list.params");ExactKeys(rr,new string[]{"tools"},"tools-list-result");IList tools=ListValue(rr["tools"],"tools");string[] expected=new string[]{"analyze_function","callees","declare_type","entity_query","get_bytes","get_comments","idb_list","idb_open","idb_save","inspect_items","rename","runtime_attestation","set_address_comments","set_function_comments","set_type","stack_frame","type_inspect","type_query","xref_query"};HashSet<string> found=new HashSet<string>(StringComparer.Ordinal);foreach(object value in tools){IDictionary<string,object> tool=Dict(value,"tool");ExactKeys(tool,new string[]{"name","inputSchema"},"tool");if(!found.Add(Str(tool["name"],"tool.name")))throw new UID0002PAV6RejectedException("TR6-PA duplicate tool schema","Transcript");Dict(tool["inputSchema"],"tool.schema");}if(found.Count!=expected.Length)throw new UID0002PAV6RejectedException("TR6-PA tool schema count mismatch","Transcript");foreach(string name in expected)if(!found.Contains(name))throw new UID0002PAV6RejectedException("TR6-PA tool schema name mismatch","Transcript");return null;}
    if(method!="tools/call")throw new UID0002PAV6RejectedException("TR6-PA unknown production method","Transcript");ExactKeys(rq,new string[]{"jsonrpc","id","method","params"},"tools-call-request");IDictionary<string,object> param=Dict(rq["params"],"request.params");ExactKeys(param,new string[]{"name","arguments"},"request.params");string call=Str(param["name"],"request.tool");Dict(param["arguments"],"request.arguments");ExactKeys(rr,new string[]{"isError","structuredContent"},"call-result");if(BoolValue(rr["isError"],"call.isError"))throw new UID0002PAV6RejectedException("TR6-PA production call returned error","Transcript");IDictionary<string,object> content=Dict(rr["structuredContent"],"call.content");
    operations.Add(call);if(call=="idb_open"){ExactKeys(content,new string[]{"success","error","session"},"open-content");if(!BoolValue(content["success"],"open.success")||Str(content["error"],"open.error")!="")throw new UID0002PAV6RejectedException("TR6-PA open outcome mismatch","Transcript");IDictionary<string,object> session=Dict(content["session"],"open.session");ExactKeys(session,new string[]{"session_id","input_path","is_analyzing"},"open.session");if(!String.Equals(Path.GetFullPath(Str(session["input_path"],"open.path")),Path.GetFullPath(expectedCanonical),StringComparison.OrdinalIgnoreCase)||BoolValue(session["is_analyzing"],"open.analysis"))throw new UID0002PAV6RejectedException("TR6-PA open database mismatch","Transcript");return id.IndexOf("open-Transaction",StringComparison.Ordinal)>=0?Str(session["session_id"],"open.session_id"):null;}
    if(call=="idb_list"){ExactKeys(content,new string[]{"sessions"},"list-content");IList sessions=ListValue(content["sessions"],"sessions");if(sessions.Count==0)throw new UID0002PAV6RejectedException("TR6-PA empty session catalog","Transcript");foreach(object value in sessions){IDictionary<string,object> row=Dict(value,"session-row");ExactKeys(row,new string[]{"session_id","input_path","is_active","owned","redirector_pid","redirector_generation","worker_pid","worker_generation","route_port","endpoint","socket_owner_pid"},"session-row");if(!BoolValue(row["owned"],"session.owned")||!String.Equals(Path.GetFullPath(Str(row["input_path"],"session.path")),Path.GetFullPath(expectedCanonical),StringComparison.OrdinalIgnoreCase))throw new UID0002PAV6RejectedException("TR6-PA session authority mismatch","Transcript");}return null;}
    if(call=="runtime_attestation"){ExactKeys(content,new string[]{"schema_version","ok","errors","listener","workers"},"runtime-content");if(Int64Value(content["schema_version"],"runtime.schema")!=1||!BoolValue(content["ok"],"runtime.ok")||ListValue(content["errors"],"runtime.errors").Count!=0)throw new UID0002PAV6RejectedException("TR6-PA runtime authority mismatch","Transcript");IDictionary<string,object> listener=Dict(content["listener"],"runtime.listener");ExactKeys(listener,new string[]{"ok","errors","nonce","endpoint","process"},"runtime.listener");IDictionary<string,object> endpoint=Dict(listener["endpoint"],"runtime.listener.endpoint");ExactKeys(endpoint,new string[]{"host","port","owner_pid"},"runtime.listener.endpoint");if(!BoolValue(listener["ok"],"listener.ok")||ListValue(listener["errors"],"listener.errors").Count!=0||Str(endpoint["host"],"listener.host")!="127.0.0.1"||Int64Value(endpoint["port"],"listener.port")!=13337)throw new UID0002PAV6RejectedException("TR6-PA listener authority mismatch","Transcript");IList workers=ListValue(content["workers"],"runtime.workers");foreach(object value in workers){IDictionary<string,object> worker=Dict(value,"runtime.worker");ExactKeys(worker,new string[]{"ok","errors","nonce","route","process","supervisor_sessions"},"runtime.worker");if(!BoolValue(worker["ok"],"worker.ok")||ListValue(worker["errors"],"worker.errors").Count!=0||ListValue(worker["supervisor_sessions"],"worker.sessions").Count==0)throw new UID0002PAV6RejectedException("TR6-PA worker authority mismatch","Transcript");runtimeWorkerCount++;}return null;}
    if(call=="idb_save"){ExactKeys(content,new string[]{"saved","path","database"},"save-content");saveCount++;if(!BoolValue(content["saved"],"save.saved")||!String.Equals(Path.GetFullPath(Str(content["path"],"save.path")),Path.GetFullPath(expectedCanonical),StringComparison.OrdinalIgnoreCase))throw new UID0002PAV6RejectedException("TR6-PA save authority mismatch","Transcript");return null;}
    if(call=="declare_type"||call=="rename"||call=="set_type"||call=="set_function_comments"||call=="set_address_comments"){ExactKeys(content,new string[]{"ok","operation"},"mutation-content");mutationCount++;if(!BoolValue(content["ok"],"mutation.ok")||!Regex.IsMatch(Str(content["operation"],"mutation.operation"),"^I0[1-5]$"))throw new UID0002PAV6RejectedException("TR6-PA mutation receipt mismatch","Transcript");return null;}
    if(call=="entity_query"){if(content.ContainsKey("operation")){ExactKeys(content,new string[]{"ok","operation"},"dry-content");if(!BoolValue(content["ok"],"dry.ok")||Str(content["operation"],"dry.operation")!="I02Dry")throw new UID0002PAV6RejectedException("TR6-PA dry receipt mismatch","Transcript");}else{ExactKeys(content,new string[]{"ok","phase","row","row_sha256","semantic_mismatch"},"catalog-content");if(!BoolValue(content["ok"],"catalog.ok")||Str(content["semantic_mismatch"],"catalog.mismatch")!=""||!Regex.IsMatch(Str(content["row_sha256"],"catalog.sha"),"^[0-9A-F]{64}$"))throw new UID0002PAV6RejectedException("TR6-PA catalog receipt mismatch","Transcript");}return null;}
    throw new UID0002PAV6RejectedException("TR6-PA unapproved production tool: "+call,"Transcript");
  }
  static void ValidateProductionRetirement(IDictionary<string,object> request,IDictionary<string,object> response,string expectedCanonical){string[] actionKeys=new string[]{"action","role","session_id","canonical_path","redirector_pid","redirector_generation","worker_pid","worker_generation","route_port","endpoint","socket_owner_pid","nonce","stable_manifest_sha256","process_manifest_sha256","preserve_listener"};ExactKeys(request,actionKeys,"retirement-request");string[] resultKeys=new string[]{"action","role","session_id","canonical_path","redirector_pid","redirector_generation","worker_pid","worker_generation","route_port","endpoint","socket_owner_pid","nonce","stable_manifest_sha256","process_manifest_sha256","retired","listener_preserved"};ExactKeys(response,resultKeys,"retirement-response");if(Str(request["action"],"retirement.action")!="RETIRE_EXACT_GENERATION"||!BoolValue(request["preserve_listener"],"retirement.preserve")||!String.Equals(Path.GetFullPath(Str(request["canonical_path"],"retirement.path")),Path.GetFullPath(expectedCanonical),StringComparison.OrdinalIgnoreCase)||!BoolValue(response["retired"],"retirement.retired")||!BoolValue(response["listener_preserved"],"retirement.listener"))throw new UID0002PAV6RejectedException("TR6-PA retirement authority mismatch","Transcript");foreach(string key in new string[]{"action","role","session_id","canonical_path","redirector_generation","worker_generation","endpoint","nonce","stable_manifest_sha256","process_manifest_sha256"})if(Str(request[key],"retirement.request."+key)!=Str(response[key],"retirement.response."+key))throw new UID0002PAV6RejectedException("TR6-PA retirement identity mismatch","Transcript");foreach(string key in new string[]{"redirector_pid","worker_pid","route_port","socket_owner_pid"})if(Int64Value(request[key],"retirement.request."+key)!=Int64Value(response[key],"retirement.response."+key))throw new UID0002PAV6RejectedException("TR6-PA retirement numeric identity mismatch","Transcript");}
  static void ValidateProductionReceipt(IDictionary<string,object> result,string expectedCanonical,string authorityNonce,string scenario,long saves,long transports,long external,long mcp,long ida,long fileEffects){
    ExactKeys(result,new string[]{"kind","receipt_schema","authority_kind","authority_nonce","fixture_case","status","terminal_class","cause","canonical_database","database_session","transaction_id","final_state","save_dispatch_count","transport_calls","retire_calls","restore_writes","dopen_captured","journal_retained","schema_sha256","plan_sha256","transport_log_sha256","state_log_sha256","transport_log","state_log","p0","b0","dopen","dclosed","p1","expected_fixture_effects","operation_reconciliation"},"production-result");
    string fixture=scenario??"Live";if(Str(result["kind"],"kind")!="Production"||Int64Value(result["receipt_schema"],"receipt_schema")!=1||Str(result["authority_nonce"],"authority_nonce")!=(authorityNonce??"live")||Str(result["fixture_case"],"fixture_case")!=fixture||!String.Equals(Path.GetFullPath(Str(result["canonical_database"],"canonical_database")),Path.GetFullPath(expectedCanonical),StringComparison.OrdinalIgnoreCase))throw new UID0002PAV6RejectedException("TR6-PA production identity mismatch","Transcript");
    if(Int64Value(result["save_dispatch_count"],"save_dispatch_count")!=saves||Int64Value(result["transport_calls"],"transport_calls")!=transports)throw new UID0002PAV6RejectedException("TR6-PA production/root counter mismatch","Transcript");
    string[] transportLog=StringArray(result["transport_log"],"transport_log"),stateLog=StringArray(result["state_log"],"state_log");if(Sha256(String.Join("\n",transportLog)+"\n")!=Str(result["transport_log_sha256"],"transport_log_sha256")||Sha256(String.Join("\n",stateLog)+"\n")!=Str(result["state_log_sha256"],"state_log_sha256"))throw new UID0002PAV6RejectedException("TR6-PA production log hash mismatch","Transcript");
    JavaScriptSerializer j=new JavaScriptSerializer();j.MaxJsonLength=33554432;long sendCount=0,retireCount=0,saveCount=0,mutationCount=0,runtimeWorkerCount=0;HashSet<string> ids=new HashSet<string>(StringComparer.Ordinal);List<string> operations=new List<string>();string transactionSession=null;
    foreach(string line in transportLog){string[] parts=line.Split(new char[]{'|'},5);if(parts.Length!=5||(parts[0]!="SEND"&&parts[0]!="RETIRE")||parts[3]!="RETURN")throw new UID0002PAV6RejectedException("TR6-PA production transport grammar mismatch","Transcript");string request=Decode64(parts[2],"transport request"),response=Decode64(parts[4],"transport response");UID0002PAV6RawJsonScanner.RejectDuplicates(request,"transport-request");UID0002PAV6RawJsonScanner.RejectDuplicates(response,"transport-response");IDictionary<string,object> rq=Dict(j.DeserializeObject(request),"transport-request"),rp=Dict(j.DeserializeObject(response),"transport-response");if(parts[0]=="SEND"){sendCount++;if(Int64.Parse(parts[1],System.Globalization.CultureInfo.InvariantCulture)!=sendCount)throw new UID0002PAV6RejectedException("TR6-PA send ordinal mismatch","Transcript");string returned=ValidateProductionSend(rq,rp,expectedCanonical,ids,operations,ref saveCount,ref mutationCount,ref runtimeWorkerCount);if(returned!=null){if(transactionSession!=null)throw new UID0002PAV6RejectedException("TR6-PA duplicate transaction session","Transcript");transactionSession=returned;}}else{retireCount++;if(Int64.Parse(parts[1],System.Globalization.CultureInfo.InvariantCulture)!=retireCount)throw new UID0002PAV6RejectedException("TR6-PA retire ordinal mismatch","Transcript");ValidateProductionRetirement(rq,rp,expectedCanonical);}}
    if(sendCount!=transports||retireCount!=Int64Value(result["retire_calls"],"retire_calls")||saveCount!=saves||mutationCount!=5||runtimeWorkerCount==0||transactionSession==null||transactionSession!=Str(result["database_session"],"database_session"))throw new UID0002PAV6RejectedException("TR6-PA production transport reconciliation mismatch","Transcript");
    string[] runNames=new string[]{"tools/list","idb_open","idb_list","runtime_attestation","entity_query","declare_type","entity_query","rename","entity_query","set_type","entity_query","set_function_comments","entity_query","set_address_comments","entity_query","idb_list","runtime_attestation","idb_save","idb_list","runtime_attestation","idb_open","idb_list","runtime_attestation","entity_query","idb_list","runtime_attestation"},countRows="1,1,1,1,51,1,52,1,51,1,51,1,51,1,102,1,1,1,1,1,1,1,1,51,1,1".Split(',');int[] runCounts=new int[countRows.Length];for(int n=0;n<countRows.Length;n++)runCounts[n]=Int32.Parse(countRows[n],System.Globalization.CultureInfo.InvariantCulture);int operationIndex=0;Dictionary<string,long> permitted=new Dictionary<string,long>(StringComparer.Ordinal);for(int n=0;n<runNames.Length;n++)for(int q=0;q<runCounts[n];q++){if(operationIndex>=operations.Count||operations[operationIndex]!=runNames[n])throw new UID0002PAV6RejectedException("TR6-PA forbidden/extra/out-of-order production operation","Transcript");long count;permitted.TryGetValue(runNames[n],out count);permitted[runNames[n]]=count+1;operationIndex++;}if(operationIndex!=operations.Count||Sha256(String.Join("\n",operations.ToArray())+"\n")!="205D6CA312A6F4715B9E26611EAC8BB28BCC4B3F121E118449BC12D2A2F8F68A")throw new UID0002PAV6RejectedException("TR6-PA missed/extra production operation","Transcript");
    IDictionary<string,object> op=Dict(result["operation_reconciliation"],"operation_reconciliation");ExactKeys(op,new string[]{"plan_sha256","expected_total","observed_total","expected_live_mcp_calls","expected_live_ida_write_calls","observed_fixture_transport_calls","observed_fixture_ida_write_calls","forbidden_calls","extra_calls","missed_calls","external_mcp_dispatches","external_ida_dispatches","pre_dispatch_enforced","permitted_counts"},"operation_reconciliation");IDictionary<string,object> pc=Dict(op["permitted_counts"],"permitted_counts");string[] names=new string[]{"tools/list","idb_open","idb_list","runtime_attestation","entity_query","declare_type","rename","set_type","set_function_comments","set_address_comments","idb_save"};ExactKeys(pc,names,"permitted_counts");foreach(string name in names){long count;if(!permitted.TryGetValue(name,out count)||Int64Value(pc[name],"permitted_counts."+name)!=count)throw new UID0002PAV6RejectedException("TR6-PA permitted operation count mismatch","Transcript");}long expectedExternalMcp=scenario==null?428:0,expectedExternalIda=scenario==null?6:0,expectedFixtureTransport=scenario==null?0:428,expectedFixtureIda=scenario==null?0:6;if(Str(op["plan_sha256"],"operation.plan")!="205D6CA312A6F4715B9E26611EAC8BB28BCC4B3F121E118449BC12D2A2F8F68A"||Int64Value(op["expected_total"],"operation.expected")!=428||Int64Value(op["observed_total"],"operation.observed")!=sendCount||Int64Value(op["expected_live_mcp_calls"],"operation.mcp_expected")!=428||Int64Value(op["expected_live_ida_write_calls"],"operation.ida_expected")!=6||Int64Value(op["observed_fixture_transport_calls"],"operation.fixture_transport")!=expectedFixtureTransport||Int64Value(op["observed_fixture_ida_write_calls"],"operation.fixture_ida")!=expectedFixtureIda||Int64Value(op["forbidden_calls"],"operation.forbidden")!=0||Int64Value(op["extra_calls"],"operation.extra")!=0||Int64Value(op["missed_calls"],"operation.missed")!=0||Int64Value(op["external_mcp_dispatches"],"operation.external_mcp")!=expectedExternalMcp||Int64Value(op["external_ida_dispatches"],"operation.external_ida")!=expectedExternalIda||!BoolValue(op["pre_dispatch_enforced"],"operation.predispatch")||mcp!=expectedExternalMcp||ida!=expectedExternalIda)throw new UID0002PAV6RejectedException("TR6-PA deterministic operation reconciliation mismatch","Transcript");
    long lastSave=0,lastTransport=0,lastRetire=0,lastRestore=0;bool sawSave=false,sawDopen=false,sawDclosed=false,sawP1=false,sawComplete=false;foreach(string line in stateLog){UID0002PAV6RawJsonScanner.RejectDuplicates(line,"state");IDictionary<string,object> s=Dict(j.DeserializeObject(line),"state");ExactKeys(s,new string[]{"schema","uid","transaction","state","save_count","transport_calls","retire_calls","restore_writes","detail"},"state");long ns=Int64Value(s["save_count"],"state.save"),nt=Int64Value(s["transport_calls"],"state.transport"),nr=Int64Value(s["retire_calls"],"state.retire"),nw=Int64Value(s["restore_writes"],"state.restore");if(Int64Value(s["schema"],"state.schema")!=4||Str(s["uid"],"state.uid")!="0002PA"||Str(s["transaction"],"state.transaction")!=Str(result["transaction_id"],"transaction_id")||ns<lastSave||nt<lastTransport||nr<lastRetire||nw<lastRestore)throw new UID0002PAV6RejectedException("TR6-PA state journal reconciliation mismatch","Transcript");lastSave=ns;lastTransport=nt;lastRetire=nr;lastRestore=nw;string state=Str(s["state"],"state.state");if(state=="SAVE_DISPATCHED")sawSave=true;if(state=="DOPEN")sawDopen=true;if(state=="DCLOSED")sawDclosed=true;if(state=="P1_AUTHENTICATED")sawP1=true;if(state=="COMPLETE_TERMINAL")sawComplete=true;}
    if(lastSave!=saves||lastTransport!=transports||lastRetire!=retireCount||lastRestore!=Int64Value(result["restore_writes"],"restore_writes")||!sawSave||!sawDopen||!sawDclosed||!sawP1||!sawComplete||Str(result["final_state"],"final_state")!="COMPLETE_TERMINAL")throw new UID0002PAV6RejectedException("TR6-PA state terminal mismatch","Transcript");
    IDictionary<string,object> p0=ProductionTuple(result["p0"],"p0",expectedCanonical),b0=ProductionTuple(result["b0"],"b0",expectedCanonical+".uid0002pa-v4.backup"),dopen=ProductionTuple(result["dopen"],"dopen",expectedCanonical),dclosed=ProductionTuple(result["dclosed"],"dclosed",expectedCanonical),p1=ProductionTuple(result["p1"],"p1",expectedCanonical);if(Str(p0["sha256"],"p0.sha")!=Str(b0["sha256"],"b0.sha")||Int64Value(p0["length"],"p0.length")!=Int64Value(b0["length"],"b0.length")||SameTuple(p0,p1)||!SameTuple(dopen,dclosed)||!SameTuple(dclosed,p1))throw new UID0002PAV6RejectedException("TR6-PA production tuple relation mismatch","Transcript");
    IDictionary<string,object> expected=Dict(result["expected_fixture_effects"],"expected_fixture_effects");ExactKeys(expected,new string[]{"adapter_transport_calls","adapter_save_calls","adapter_retire_calls","adapter_restore_writes","target_changed","effect_observations"},"expected_fixture_effects");if(scenario!=null&&(Str(result["authority_kind"],"authority_kind")!="SealedProductionTest"||Str(result["status"],"status")!="P1_VERIFIED"||Str(result["terminal_class"],"terminal_class")!="P1"||Str(result["cause"],"cause")!=""||Str(result["schema_sha256"],"schema_sha256")!="1FC6C670032208D4000971572FB83DE915E634DB615000829609065AC56B115E"||Str(result["plan_sha256"],"plan_sha256")!="DAB26B627BF8D75345EB1E13495CB876C932292840690313844C02DBDFEAE565"||saves!=1||retireCount!=2||Int64Value(result["restore_writes"],"restore_writes")!=0||!BoolValue(result["dopen_captured"],"dopen_captured")||BoolValue(result["journal_retained"],"journal_retained")||Int64Value(expected["adapter_transport_calls"],"fixture.transport")!=sendCount||Int64Value(expected["adapter_save_calls"],"fixture.save")!=saveCount||Int64Value(expected["adapter_retire_calls"],"fixture.retire")!=retireCount||Int64Value(expected["adapter_restore_writes"],"fixture.restore")!=0||!BoolValue(expected["target_changed"],"fixture.changed")||Int64Value(expected["effect_observations"],"fixture.observations")!=10||fileEffects!=1))throw new UID0002PAV6RejectedException("TR6-PA sealed production-test boundary mismatch","Transcript");
  }
  static string PSQuote(string s){return "'"+s.Replace("'","''")+"'";}
  static string FileTuple(string path){if(!File.Exists(path))return "ABSENT";using(FileStream s=new FileStream(path,FileMode.Open,FileAccess.Read,FileShare.ReadWrite|FileShare.Delete)){long length0=s.Length,ticks0=File.GetLastWriteTimeUtc(path).Ticks;using(SHA256 sha=SHA256.Create()){string hash=BitConverter.ToString(sha.ComputeHash(s)).Replace("-","");long length1=s.Length,ticks1=File.GetLastWriteTimeUtc(path).Ticks;if(length0!=length1||ticks0!=ticks1)throw new UID0002PAV6RejectedException("RC6-PA file receipt drift: "+path,"Receipt");return length0+"|"+ticks0+"|"+hash;}}}
  enum UID0002PATcpTableClass { TcpTableOwnerPidAll=5 }
  [StructLayout(LayoutKind.Sequential)] struct UID0002PATcpRow { public uint State,LocalAddress,LocalPort,RemoteAddress,RemotePort,OwningPid; }
  [DllImport("iphlpapi.dll",SetLastError=true)] static extern uint GetExtendedTcpTable(IntPtr table,ref int length,bool sort,int family,UID0002PATcpTableClass tableClass,uint reserved);
  static int TcpPort(uint value){byte[] b=BitConverter.GetBytes(value);return (b[0]<<8)|b[1];}
  static string TcpReceipt(int childPid,out int listenerPid,out int childMcpConnections){listenerPid=0;childMcpConnections=0;int length=0;uint rc=GetExtendedTcpTable(IntPtr.Zero,ref length,true,2,UID0002PATcpTableClass.TcpTableOwnerPidAll,0);if(rc!=122&&rc!=0)throw new UID0002PAV6RejectedException("RC6-PA TCP observer sizing failed: "+rc,"Receipt");IntPtr memory=Marshal.AllocHGlobal(length);try{rc=GetExtendedTcpTable(memory,ref length,true,2,UID0002PATcpTableClass.TcpTableOwnerPidAll,0);if(rc!=0)throw new UID0002PAV6RejectedException("RC6-PA TCP observer failed: "+rc,"Receipt");int count=Marshal.ReadInt32(memory),rowSize=Marshal.SizeOf(typeof(UID0002PATcpRow));StringBuilder rows=new StringBuilder();for(int n=0;n<count;n++){UID0002PATcpRow row=(UID0002PATcpRow)Marshal.PtrToStructure(new IntPtr(memory.ToInt64()+4L+(long)n*rowSize),typeof(UID0002PATcpRow));int local=TcpPort(row.LocalPort),remote=TcpPort(row.RemotePort),owner=(int)row.OwningPid;if(row.State==2&&local==13337)listenerPid=owner;if(childPid!=0&&owner==childPid&&(local==13337||remote==13337))childMcpConnections++;if(local==13337||remote==13337)rows.Append(owner).Append(':').Append(row.State).Append(':').Append(local).Append(':').Append(remote).Append(';');}return Sha256(rows.ToString())+"|listener="+listenerPid+"|child="+childMcpConnections;}finally{Marshal.FreeHGlobal(memory);}}

  [StructLayout(LayoutKind.Sequential)] struct UID0002PAJobBasicLimit { public long PerProcessUserTimeLimit,PerJobUserTimeLimit;public uint LimitFlags;public UIntPtr MinimumWorkingSetSize,MaximumWorkingSetSize;public uint ActiveProcessLimit;public UIntPtr Affinity;public uint PriorityClass,SchedulingClass; }
  [StructLayout(LayoutKind.Sequential)] struct UID0002PAIoCounters { public ulong ReadOperationCount,WriteOperationCount,OtherOperationCount,ReadTransferCount,WriteTransferCount,OtherTransferCount; }
  [StructLayout(LayoutKind.Sequential)] struct UID0002PAJobExtendedLimit { public UID0002PAJobBasicLimit BasicLimitInformation;public UID0002PAIoCounters IoInfo;public UIntPtr ProcessMemoryLimit,JobMemoryLimit,PeakProcessMemoryUsed,PeakJobMemoryUsed; }
  [StructLayout(LayoutKind.Sequential)] struct UID0002PAJobAccounting { public long TotalUserTime,TotalKernelTime,ThisPeriodTotalUserTime,ThisPeriodTotalKernelTime;public uint TotalPageFaultCount,TotalProcesses,ActiveProcesses,TotalTerminatedProcesses; }
  [StructLayout(LayoutKind.Sequential)] struct UID0002PAJobCompletionAssociation { public IntPtr CompletionKey,CompletionPort; }
  [DllImport("kernel32.dll",CharSet=CharSet.Unicode,SetLastError=true)] static extern IntPtr CreateJobObject(IntPtr attributes,string name);
  [DllImport("kernel32.dll",SetLastError=true)] static extern bool SetInformationJobObject(IntPtr job,int infoClass,IntPtr info,uint length);
  [DllImport("kernel32.dll",SetLastError=true)] static extern bool AssignProcessToJobObject(IntPtr job,IntPtr process);
  [DllImport("kernel32.dll",SetLastError=true)] static extern bool IsProcessInJob(IntPtr process,IntPtr job,out bool result);
  [DllImport("kernel32.dll",SetLastError=true)] static extern bool QueryInformationJobObject(IntPtr job,int infoClass,IntPtr info,uint length,out uint returnedLength);
  [DllImport("kernel32.dll",SetLastError=true)] static extern bool TerminateJobObject(IntPtr job,uint exitCode);
  [DllImport("kernel32.dll",SetLastError=true)] static extern IntPtr CreateIoCompletionPort(IntPtr fileHandle,IntPtr existingCompletionPort,UIntPtr completionKey,uint concurrentThreads);
  [DllImport("kernel32.dll",SetLastError=true)] static extern bool GetQueuedCompletionStatus(IntPtr completionPort,out uint message,out UIntPtr completionKey,out IntPtr overlapped,uint milliseconds);
  [DllImport("kernel32.dll",SetLastError=true)] static extern bool CloseHandle(IntPtr handle);

  static IntPtr CreateOwnedJob(out IntPtr completionPort){completionPort=IntPtr.Zero;IntPtr job=CreateJobObject(IntPtr.Zero,null);if(job==IntPtr.Zero)throw new System.ComponentModel.Win32Exception(Marshal.GetLastWin32Error(),"PX6-PA CreateJobObject failed");IntPtr limitMemory=IntPtr.Zero,associationMemory=IntPtr.Zero;try{UID0002PAJobExtendedLimit limit=new UID0002PAJobExtendedLimit();limit.BasicLimitInformation.LimitFlags=0x00002000;int limitSize=Marshal.SizeOf(typeof(UID0002PAJobExtendedLimit));limitMemory=Marshal.AllocHGlobal(limitSize);Marshal.StructureToPtr(limit,limitMemory,false);if(!SetInformationJobObject(job,9,limitMemory,(uint)limitSize))throw new System.ComponentModel.Win32Exception(Marshal.GetLastWin32Error(),"PX6-PA SetInformationJobObject failed");completionPort=CreateIoCompletionPort(new IntPtr(-1),IntPtr.Zero,UIntPtr.Zero,1);if(completionPort==IntPtr.Zero)throw new System.ComponentModel.Win32Exception(Marshal.GetLastWin32Error(),"PX6-PA CreateIoCompletionPort failed");UID0002PAJobCompletionAssociation association=new UID0002PAJobCompletionAssociation();association.CompletionKey=job;association.CompletionPort=completionPort;int associationSize=Marshal.SizeOf(typeof(UID0002PAJobCompletionAssociation));associationMemory=Marshal.AllocHGlobal(associationSize);Marshal.StructureToPtr(association,associationMemory,false);if(!SetInformationJobObject(job,7,associationMemory,(uint)associationSize))throw new System.ComponentModel.Win32Exception(Marshal.GetLastWin32Error(),"PX6-PA job completion-port association failed");return job;}catch{if(completionPort!=IntPtr.Zero){CloseHandle(completionPort);completionPort=IntPtr.Zero;}CloseHandle(job);throw;}finally{if(limitMemory!=IntPtr.Zero)Marshal.FreeHGlobal(limitMemory);if(associationMemory!=IntPtr.Zero)Marshal.FreeHGlobal(associationMemory);}}
  static void ObserveJobGeneration(int pid,ConcurrentDictionary<string,byte> seen,int[] unresolved){for(int retry=0;retry<100;retry++){try{using(Process process=Process.GetProcessById(pid)){long generation=process.StartTime.ToUniversalTime().Ticks;seen.TryAdd(pid.ToString(System.Globalization.CultureInfo.InvariantCulture)+"|"+generation.ToString(System.Globalization.CultureInfo.InvariantCulture),0);return;}}catch{Thread.Sleep(1);}}Interlocked.Increment(ref unresolved[0]);}
  static Task<string> StartJobWatcher(IntPtr completionPort,ConcurrentDictionary<string,byte> seen,int[] unresolved,CancellationToken stop){return Task.Factory.StartNew(delegate{try{int emptyAfterStop=0;while(!stop.IsCancellationRequested||emptyAfterStop<3){uint message;UIntPtr key;IntPtr overlapped;bool ok=GetQueuedCompletionStatus(completionPort,out message,out key,out overlapped,stop.IsCancellationRequested?0U:50U);if(!ok){int error=Marshal.GetLastWin32Error();if(error==258){if(stop.IsCancellationRequested){emptyAfterStop++;Thread.Sleep(1);}continue;}throw new System.ComponentModel.Win32Exception(error,"PX6-PA completion-port watcher failed");}emptyAfterStop=0;if(message==6&&overlapped!=IntPtr.Zero)ObserveJobGeneration(unchecked((int)overlapped.ToInt64()),seen,unresolved);}return null;}catch(Exception ex){return ex.GetType().FullName;}},CancellationToken.None,TaskCreationOptions.LongRunning,TaskScheduler.Default);}
  static UID0002PAJobAccounting JobAccounting(IntPtr job){int size=Marshal.SizeOf(typeof(UID0002PAJobAccounting));IntPtr memory=Marshal.AllocHGlobal(size);try{uint returned;if(!QueryInformationJobObject(job,1,memory,(uint)size,out returned))throw new System.ComponentModel.Win32Exception(Marshal.GetLastWin32Error(),"PX6-PA job accounting query failed");return (UID0002PAJobAccounting)Marshal.PtrToStructure(memory,typeof(UID0002PAJobAccounting));}finally{Marshal.FreeHGlobal(memory);}}
  static int[] JobPids(IntPtr job){int size=65536;IntPtr memory=Marshal.AllocHGlobal(size);try{uint returned;if(!QueryInformationJobObject(job,3,memory,(uint)size,out returned))throw new System.ComponentModel.Win32Exception(Marshal.GetLastWin32Error(),"PX6-PA job PID query failed");int count=Marshal.ReadInt32(memory,4),stride=IntPtr.Size;int[] pids=new int[count];for(int n=0;n<count;n++)pids[n]=stride==8?(int)Marshal.ReadInt64(memory,8+n*stride):Marshal.ReadInt32(memory,8+n*stride);Array.Sort(pids);return pids;}finally{Marshal.FreeHGlobal(memory);}}
  static void CaptureJob(IntPtr job,ConcurrentDictionary<string,byte> seen,ref int total,ref int peak,ref int active){UID0002PAJobAccounting accounting=JobAccounting(job);total=Math.Max(total,(int)accounting.TotalProcesses);active=(int)accounting.ActiveProcesses;peak=Math.Max(peak,active);foreach(int pid in JobPids(job))ObserveJobGeneration(pid,seen,new int[1]);}
  static bool GenerationAlive(int pid,long generation){try{using(Process process=Process.GetProcessById(pid))return !process.HasExited&&process.StartTime.ToUniversalTime().Ticks==generation;}catch{return false;}}
  static string ProcessCensus(){List<string> rows=new List<string>();foreach(Process process in Process.GetProcesses()){try{rows.Add(process.Id.ToString(System.Globalization.CultureInfo.InvariantCulture)+"|"+process.StartTime.ToUniversalTime().Ticks.ToString(System.Globalization.CultureInfo.InvariantCulture)+"|"+process.ProcessName);}catch{}finally{process.Dispose();}}rows.Sort(StringComparer.Ordinal);return Sha256(String.Join("\n",rows.ToArray())+"\n");}
  static string NetworkCensus(HashSet<int> owned,out int ownedConnections){ownedConnections=0;int length=0;uint rc=GetExtendedTcpTable(IntPtr.Zero,ref length,true,2,UID0002PATcpTableClass.TcpTableOwnerPidAll,0);if(rc!=122&&rc!=0)throw new UID0002PAV6RejectedException("RC6-PA network census sizing failed: "+rc,"Receipt");IntPtr memory=Marshal.AllocHGlobal(length);try{rc=GetExtendedTcpTable(memory,ref length,true,2,UID0002PATcpTableClass.TcpTableOwnerPidAll,0);if(rc!=0)throw new UID0002PAV6RejectedException("RC6-PA network census failed: "+rc,"Receipt");int count=Marshal.ReadInt32(memory),rowSize=Marshal.SizeOf(typeof(UID0002PATcpRow));List<string> rows=new List<string>();for(int n=0;n<count;n++){UID0002PATcpRow row=(UID0002PATcpRow)Marshal.PtrToStructure(new IntPtr(memory.ToInt64()+4L+(long)n*rowSize),typeof(UID0002PATcpRow));int owner=(int)row.OwningPid;if(owned!=null&&owned.Contains(owner))ownedConnections++;rows.Add(owner+"|"+row.State+"|"+row.LocalAddress+"|"+TcpPort(row.LocalPort)+"|"+row.RemoteAddress+"|"+TcpPort(row.RemotePort));}rows.Sort(StringComparer.Ordinal);return Sha256(String.Join("\n",rows.ToArray())+"\n");}finally{Marshal.FreeHGlobal(memory);}}
  static string FileSystemCensus(string canonical,string fixtureRoot){List<string> rows=new List<string>();foreach(string path in new string[]{canonical,canonical+".uid0002pa-v4.journal",canonical+".uid0002pa-v4.backup"})rows.Add(Path.GetFullPath(path)+"|"+FileTuple(path));string temp=Path.GetFullPath(Path.GetTempPath());foreach(string root in Directory.GetDirectories(temp,"uid0002pa-*",SearchOption.TopDirectoryOnly))rows.Add("TEMP|"+Path.GetFullPath(root));if(fixtureRoot!=null&&Directory.Exists(fixtureRoot)){foreach(string path in FixtureTree(fixtureRoot,true)){string full=Path.GetFullPath(path);if(File.Exists(full)){FileInfo info=new FileInfo(full);rows.Add("FILE|"+full+"|"+info.Length+"|"+info.LastWriteTimeUtc.Ticks+"|"+FileSha256(full));}else rows.Add("DIR|"+full);}}rows.Sort(StringComparer.OrdinalIgnoreCase);return Sha256(String.Join("\n",rows.ToArray())+"\n");}
  static string[] FixtureTree(string root,bool rejectReparse){List<string> paths=new List<string>();Stack<string> pending=new Stack<string>();pending.Push(root);while(pending.Count!=0){string parent=pending.Pop();foreach(string path in Directory.GetFileSystemEntries(parent,"*",SearchOption.TopDirectoryOnly)){FileAttributes attributes=File.GetAttributes(path);paths.Add(path);if((attributes&FileAttributes.ReparsePoint)!=0){if(rejectReparse)throw new UID0002PAV6RejectedException("CL6-PA fixture cleanup reparse point refused","Cleanup");continue;}if(Directory.Exists(path))pending.Push(path);}}paths.Sort(StringComparer.OrdinalIgnoreCase);return paths.ToArray();}
  static string[] PrefixRoots(){string temp=Path.GetFullPath(Path.GetTempPath());string[] roots=Directory.GetFileSystemEntries(temp,"uid0002pa-*",SearchOption.TopDirectoryOnly);for(int n=0;n<roots.Length;n++)roots[n]=Path.GetFullPath(roots[n]);Array.Sort(roots,StringComparer.OrdinalIgnoreCase);return roots;}
  static string PrefixInventory(string[] roots,out int count){List<string> rows=new List<string>();foreach(string root in roots){string full=Path.GetFullPath(root),leaf=Path.GetFileName(full);rows.Add("ROOT|"+leaf+"|"+(Directory.Exists(full)?"D":"F"));if(File.Exists(full)&&!Directory.Exists(full)){FileInfo info=new FileInfo(full);rows.Add("FILE|"+leaf+"|"+info.Length+"|"+info.LastWriteTimeUtc.Ticks+"|"+FileSha256(full));continue;}if(!Directory.Exists(full))continue;foreach(string path in FixtureTree(full,false)){string relative=path.Substring(full.Length).TrimStart(Path.DirectorySeparatorChar,Path.AltDirectorySeparatorChar).Replace(Path.DirectorySeparatorChar,'/');FileAttributes attributes=File.GetAttributes(path);if((attributes&FileAttributes.ReparsePoint)!=0)rows.Add("REPARSE|"+leaf+"/"+relative);else if(File.Exists(path)){FileInfo info=new FileInfo(path);rows.Add("FILE|"+leaf+"/"+relative+"|"+info.Length+"|"+info.LastWriteTimeUtc.Ticks+"|"+FileSha256(path));}else rows.Add("DIR|"+leaf+"/"+relative);}}rows.Sort(StringComparer.Ordinal);count=roots.Length;return Sha256(String.Join("\n",rows.ToArray())+"\n");}
  static void ValidateHistoricalLeakRoot(string root){string fixtureSha="66840DDA154E8A113C31DD0AD32F7F3A366A80E8136979D8F5A101D3D29D6F72",listenerSha="C2B51CD387BE0FF61D95E54044876A32E39220C4AA6E652F41C4578177DDF7D5";HashSet<string> workerShas=new HashSet<string>(new string[]{"24109DB28342991DB2E66387C97D7829ED6195A689C08BA69E8782F95A2AC975","107B8399DC125B3196CA19F1AA63CEE8839A411BFF62886E72FC5C3F9481A375"},StringComparer.Ordinal);HashSet<string> allowed=new HashSet<string>(new string[]{"fixture.i64","fixture.i64.uid0002pa-v4.backup","fixture.i64.uid0002pa-v4.journal","source/listener.py","source/worker.py"},StringComparer.OrdinalIgnoreCase);foreach(string path in FixtureTree(root,true)){FileAttributes attributes=File.GetAttributes(path);if((attributes&FileAttributes.ReparsePoint)!=0)throw new UID0002PAV6RejectedException("CL6-PA historical leak reparse point refused","Cleanup");string relative=path.Substring(root.Length).TrimStart(Path.DirectorySeparatorChar,Path.AltDirectorySeparatorChar).Replace(Path.DirectorySeparatorChar,'/');if(Directory.Exists(path)){if(relative!="source")throw new UID0002PAV6RejectedException("CL6-PA historical leak directory inventory mismatch","Cleanup");continue;}if(!allowed.Contains(relative))throw new UID0002PAV6RejectedException("CL6-PA historical leak file inventory mismatch","Cleanup");string sha=FileSha256(path);if((relative=="fixture.i64"||relative=="fixture.i64.uid0002pa-v4.backup")&&sha!=fixtureSha)throw new UID0002PAV6RejectedException("CL6-PA historical fixture identity mismatch","Cleanup");if(relative=="source/listener.py"&&sha!=listenerSha)throw new UID0002PAV6RejectedException("CL6-PA historical listener manifest identity mismatch","Cleanup");if(relative=="source/worker.py"&&!workerShas.Contains(sha))throw new UID0002PAV6RejectedException("CL6-PA historical worker manifest identity mismatch","Cleanup");}}
  static int CleanupExactRoot(string root){string full=Path.GetFullPath(root).TrimEnd(Path.DirectorySeparatorChar,Path.AltDirectorySeparatorChar),temp=Path.GetFullPath(Path.GetTempPath()).TrimEnd(Path.DirectorySeparatorChar,Path.AltDirectorySeparatorChar),leaf=Path.GetFileName(full);if(!full.StartsWith(temp+Path.DirectorySeparatorChar,StringComparison.OrdinalIgnoreCase)||!Regex.IsMatch(leaf,"^uid0002pa-(?:v3|v4|s1|v6-production)-[0-9a-f]{32}$",RegexOptions.CultureInvariant))throw new UID0002PAV6RejectedException("CL6-PA fixture cleanup root authority mismatch","Cleanup");HashSet<string> paths=new HashSet<string>(StringComparer.OrdinalIgnoreCase);paths.Add(full);if(Directory.Exists(full))foreach(string path in FixtureTree(full,true)){if((File.GetAttributes(path)&FileAttributes.ReparsePoint)!=0)throw new UID0002PAV6RejectedException("CL6-PA fixture cleanup reparse point refused","Cleanup");paths.Add(Path.GetFullPath(path));}try{if(File.Exists(full)&&!Directory.Exists(full))throw new IOException("fixture root is not a directory");if(Directory.Exists(full))Directory.Delete(full,true);}catch(Exception ex){throw new UID0002PAV6RejectedException("CL6-PA fixture cleanup delete failed: "+ex.GetType().FullName,"Cleanup");}foreach(string path in paths)if(File.Exists(path)||Directory.Exists(path))throw new UID0002PAV6RejectedException("CL6-PA fixture cleanup physical absence mismatch: "+path,"Cleanup");return paths.Count;}
  static UID0002PAV6CleanupReceipt BeginGenerationCleanup(out string[] baseline){string[] historical=new string[]{"uid0002pa-s1-8cdb8a5e93974211a8f58f2a1c9c053c","uid0002pa-v4-0855a253b4444b0797a4fa150489fdd2","uid0002pa-v4-13704a0905b94dc4adc15f72fbddd237","uid0002pa-v4-13e254b16eec46bd9dd8dcad223985b0","uid0002pa-v4-1f5054810fcd4416b877eb923e1772c7","uid0002pa-v4-36458db92d03456385931416e2460edb","uid0002pa-v4-3da97cdbf0fc46b8bb1fe064be19ebef","uid0002pa-v4-52b2ad235d6746758e1add46e7c7702c","uid0002pa-v4-545d56822eee4982a3d0f92e21c8bd04","uid0002pa-v4-8b467a9ac95d48f985e34632046f7def","uid0002pa-v4-b25dd21e0ec84755acc48acfa9e1bd50","uid0002pa-v4-d328b060141249a28fc4a7d1dccb0cdb","uid0002pa-v4-f19d824609854ee98ba5d776a79c49b9","uid0002pa-v4-f9f2cc77b43542c7921832d9ac11ffd5"};string[] before=PrefixRoots();int beforeCount;string beforeSha=PrefixInventory(before,out beforeCount);int present=0,removed=0;string temp=Path.GetFullPath(Path.GetTempPath());foreach(string leaf in historical){string root=Path.Combine(temp,leaf);if(Directory.Exists(root)){present++;ValidateHistoricalLeakRoot(root);CleanupExactRoot(root);removed++;}else if(File.Exists(root))throw new UID0002PAV6RejectedException("CL6-PA historical leak root is not a directory","Cleanup");}int absent=0;foreach(string leaf in historical){string root=Path.Combine(temp,leaf);if(!File.Exists(root)&&!Directory.Exists(root))absent++;}if(absent!=historical.Length||removed!=present)throw new UID0002PAV6RejectedException("CL6-PA historical leak retirement mismatch","Cleanup");baseline=PrefixRoots();int baselineCount;string baselineSha=PrefixInventory(baseline,out baselineCount);return new UID0002PAV6CleanupReceipt("FAILED_HISTORICAL_HARNESS_EVIDENCE_RETIRED",historical.Length,present,removed,absent,baselineCount,0,0,0,beforeCount,baselineCount,baselineCount,beforeSha,baselineSha,baselineSha,true,false,false);}
  static UID0002PAV6CleanupReceipt CompleteGenerationCleanup(UID0002PAV6CleanupReceipt begin,string[] baseline){HashSet<string> prior=new HashSet<string>(baseline,StringComparer.OrdinalIgnoreCase);string[] current=PrefixRoots();List<string> created=new List<string>();foreach(string root in current)if(!prior.Contains(root))created.Add(root);int removed=0;foreach(string root in created){CleanupExactRoot(root);removed++;}string[] after=PrefixRoots();int afterCount;string afterSha=PrefixInventory(after,out afterCount);int baselineCount;string baselineSha=PrefixInventory(baseline,out baselineCount);int absent=0;foreach(string root in created)if(!File.Exists(root)&&!Directory.Exists(root))absent++;bool reproduced=afterCount==baselineCount&&afterSha==baselineSha;if(absent!=created.Count||removed!=created.Count||!reproduced)throw new UID0002PAV6RejectedException("CL6-PA post-run prefix inventory mismatch","Cleanup");return new UID0002PAV6CleanupReceipt(begin.Classification,begin.HistoricalInventoryCount,begin.HistoricalPresentBefore,begin.HistoricalRemoved,begin.HistoricalAbsentAfter,baselineCount,created.Count,removed,absent,begin.BeforePrefixCount,baselineCount,afterCount,begin.BeforePrefixSHA256,baselineSha,afterSha,true,true,true);}
  static bool WaitJobEmpty(IntPtr job,int timeoutMs,ConcurrentDictionary<string,byte> seen,ref int total,ref int peak,ref int active){Stopwatch clock=Stopwatch.StartNew();do{CaptureJob(job,seen,ref total,ref peak,ref active);if(active==0)return true;Thread.Sleep(25);}while(clock.ElapsedMilliseconds<timeoutMs);CaptureJob(job,seen,ref total,ref peak,ref active);return active==0;}
  static string HostileDescendantProgram(string executable,bool inheritOuterPipes,bool keepParentAlive){string redirect=inheritOuterPipes?"$si.RedirectStandardOutput=$false;$si.RedirectStandardError=$false":"$si.RedirectStandardOutput=$true;$si.RedirectStandardError=$true";return "$si=[Diagnostics.ProcessStartInfo]::new();$si.FileName="+PSQuote(executable)+";$si.Arguments='-NoLogo -NoProfile -NonInteractive -Command -';$si.UseShellExecute=$false;$si.CreateNoWindow=$true;$si.RedirectStandardInput=$true;"+redirect+";$d=[Diagnostics.Process]::Start($si);$d.StandardInput.Write('Start-Sleep -Seconds 60');$d.StandardInput.Close();"+(keepParentAlive?"Start-Sleep -Seconds 60":"[Console]::Out.Write('PARENT_EXIT')");}
  public static UID0002PAV6CleanupReceipt InvokeCleanupBoundaryHostile(){VerifySelf();string[] baseline;UID0002PAV6CleanupReceipt begin=BeginGenerationCleanup(out baseline),completed=null;string root=Path.Combine(Path.GetTempPath(),"uid0002pa-v4-"+Guid.NewGuid().ToString("N")),source=Path.Combine(root,"source");bool rejected=false;try{Directory.CreateDirectory(source);File.WriteAllBytes(Path.Combine(root,"fixture.i64"),new byte[]{1,2,3,4,5,6,7,8});File.WriteAllText(Path.Combine(source,"listener.py"),"listener-v4",new UTF8Encoding(false));File.WriteAllText(Path.Combine(source,"worker.py"),"worker-v4",new UTF8Encoding(false));throw new UID0002PAV6RejectedException("HF6-PA injected cleanup failure path","CleanupHostile");}catch(UID0002PAV6RejectedException ex){rejected=ex.RejectionCode=="HF6-PA injected cleanup failure path";}finally{completed=CompleteGenerationCleanup(begin,baseline);}if(!rejected||completed==null||completed.NewRootsObserved!=1||completed.NewRootsRemoved!=1||completed.NewRootsAbsentAfter!=1||!completed.NewGenerationClosed||!completed.BaselineReproduced)throw new UID0002PAV6RejectedException("HF6-PA cleanup failure hostile mismatch","CleanupHostile");return completed;}
  static UID0002PAV6ProcessReceipt ExecuteBoundedProgram(string executable,string program,int timeoutMs,string scenario,out string output,out string error){string censusBefore=ProcessCensus();int ownedBefore;string networkBefore=NetworkCensus(new HashSet<int>(),out ownedBefore);Process process=new Process();IntPtr job=IntPtr.Zero,completionPort=IntPtr.Zero;Task<string> stdout=null,stderr=null;Task write=null;Task<string> watcher=null;CancellationTokenSource watcherStop=null;ConcurrentDictionary<string,byte> seen=new ConcurrentDictionary<string,byte>(StringComparer.Ordinal);int[] unresolved=new int[1];int pid=0,exitCode=-1,total=0,peak=0,active=0;long generation=0;bool portBound=false,censusComplete=false,watcherTerminal=false,watcherSucceeded=false,inputTerminal=false,assigned=false,immediateRetired=false,jobEmpty=false,drainsTerminal=false,drainsSucceeded=false,drainsPending=false,parentExitedWithDescendant=false;string outcome="COMPLETED";output=null;error=null;try{job=CreateOwnedJob(out completionPort);portBound=completionPort!=IntPtr.Zero;watcherStop=new CancellationTokenSource();watcher=StartJobWatcher(completionPort,seen,unresolved,watcherStop.Token);ProcessStartInfo start=new ProcessStartInfo(executable,"-NoLogo -NoProfile -NonInteractive -Command -");start.UseShellExecute=false;start.CreateNoWindow=true;start.RedirectStandardInput=true;start.RedirectStandardOutput=true;start.RedirectStandardError=true;process.StartInfo=start;if(!process.Start())throw new InvalidOperationException("PX6-PA child start failed");pid=process.Id;generation=process.StartTime.ToUniversalTime().Ticks;seen.TryAdd(pid.ToString(System.Globalization.CultureInfo.InvariantCulture)+"|"+generation.ToString(System.Globalization.CultureInfo.InvariantCulture),0);if(!AssignProcessToJobObject(job,process.Handle))throw new System.ComponentModel.Win32Exception(Marshal.GetLastWin32Error(),"PX6-PA AssignProcessToJobObject failed");bool inJob;if(!IsProcessInJob(process.Handle,job,out inJob)||!inJob)throw new InvalidOperationException("PX6-PA exact child not contained");assigned=true;CaptureJob(job,seen,ref total,ref peak,ref active);stdout=process.StandardOutput.ReadToEndAsync();stderr=process.StandardError.ReadToEndAsync();if(scenario=="DrainFailure")process.StandardError.Dispose();write=process.StandardInput.WriteAsync(program);if(!write.Wait(300000)){outcome="PX6-PA stdin delivery timeout";}else process.StandardInput.Close();Stopwatch clock=Stopwatch.StartNew();bool exited=false;while(outcome=="COMPLETED"&&clock.ElapsedMilliseconds<timeoutMs){CaptureJob(job,seen,ref total,ref peak,ref active);if(scenario=="DescendantSurvival"&&total>1){outcome="PX6-PA descendant survival observed";break;}if(process.WaitForExit(25)){exited=true;break;}}if(!exited){try{exited=process.HasExited;}catch{}}if(!exited&&outcome=="COMPLETED")outcome="PX6-PA child timeout";CaptureJob(job,seen,ref total,ref peak,ref active);if(exited&&active>0){parentExitedWithDescendant=true;drainsPending=(stdout!=null&&!stdout.IsCompleted)||(stderr!=null&&!stderr.IsCompleted);if(scenario=="InheritedPipes")outcome="PX6-PA inherited pipe descendant contained";else if(scenario=="ParentExitLiveDescendant")outcome="PX6-PA parent exit with live descendant";else if(outcome=="COMPLETED")outcome="PX6-PA unapproved live descendant";}if(!exited||active>0||outcome!="COMPLETED")TerminateJobObject(job,0xE0000001);jobEmpty=WaitJobEmpty(job,30000,seen,ref total,ref peak,ref active);if(!jobEmpty)outcome="PX6-PA job retirement timeout";if(write!=null){try{inputTerminal=write.Wait(5000);}catch{inputTerminal=write.IsCompleted;}}if(!process.HasExited&&!process.WaitForExit(30000))outcome="PX6-PA immediate child retirement timeout";if(process.HasExited)exitCode=process.ExitCode;Task[] drains=new Task[]{stdout,stderr};try{drainsTerminal=Task.WaitAll(drains,30000);drainsSucceeded=drainsTerminal&&stdout.Status==TaskStatus.RanToCompletion&&stderr.Status==TaskStatus.RanToCompletion;}catch(AggregateException){drainsTerminal=stdout.IsCompleted&&stderr.IsCompleted;drainsSucceeded=false;}if(!drainsTerminal){try{process.StandardOutput.Dispose();}catch{}try{process.StandardError.Dispose();}catch{}try{Task.WaitAll(drains,5000);}catch{}drainsTerminal=stdout.IsCompleted&&stderr.IsCompleted;drainsSucceeded=false;if(outcome=="COMPLETED")outcome="PX6-PA drain timeout";}if(drainsSucceeded){output=stdout.Result;error=stderr.Result;}if(!drainsSucceeded&&scenario=="DrainFailure")outcome="PX6-PA drain failure";else if(!drainsSucceeded&&outcome=="COMPLETED")outcome="PX6-PA drain failure";}catch(Exception ex){outcome="PX6-PA process boundary failure: "+ex.GetType().FullName;if(job!=IntPtr.Zero)try{TerminateJobObject(job,0xE0000002);}catch{}}finally{if(job!=IntPtr.Zero){try{jobEmpty=WaitJobEmpty(job,30000,seen,ref total,ref peak,ref active);}catch{}}if(watcherStop!=null){watcherStop.Cancel();if(watcher!=null){try{watcherTerminal=watcher.Wait(5000);watcherSucceeded=watcherTerminal&&watcher.Status==TaskStatus.RanToCompletion&&watcher.Result==null;}catch{watcherTerminal=watcher.IsCompleted;watcherSucceeded=false;}}watcherStop.Dispose();}if(completionPort!=IntPtr.Zero)CloseHandle(completionPort);if(job!=IntPtr.Zero)CloseHandle(job);try{if(pid!=0)immediateRetired=!GenerationAlive(pid,generation);}catch{}try{process.Dispose();}catch{}}int sameAlive=0;HashSet<int> ownedPids=new HashSet<int>();foreach(string key in seen.Keys){string[] parts=key.Split('|');int seenPid=Int32.Parse(parts[0],System.Globalization.CultureInfo.InvariantCulture);long seenGeneration=Int64.Parse(parts[1],System.Globalization.CultureInfo.InvariantCulture);ownedPids.Add(seenPid);if(GenerationAlive(seenPid,seenGeneration))sameAlive++;}int ownedNetworkAfter;string networkAfter=NetworkCensus(ownedPids,out ownedNetworkAfter),censusAfter=ProcessCensus();string[] seenRows=new string[seen.Count];seen.Keys.CopyTo(seenRows,0);Array.Sort(seenRows,StringComparer.Ordinal);int observed=seenRows.Length,descendants=Math.Max(0,observed-(pid==0?0:1));censusComplete=portBound&&watcherTerminal&&watcherSucceeded&&unresolved[0]==0&&observed==total;jobEmpty=jobEmpty&&active==0&&sameAlive==0;long stdoutChars=output==null?0:output.Length,stderrChars=error==null?0:error.Length;return new UID0002PAV6ProcessReceipt(scenario,outcome,pid,generation,exitCode,total,peak,observed,descendants,unresolved[0],active,sameAlive,ownedNetworkAfter,stdoutChars,stderrChars,portBound,censusComplete,watcherTerminal,watcherSucceeded,inputTerminal,assigned,immediateRetired,jobEmpty,drainsTerminal,drainsSucceeded,drainsPending,parentExitedWithDescendant,Sha256(String.Join("\n",seenRows)+"\n"),censusBefore,censusAfter,networkBefore,networkAfter);}
  public static UID0002PAV6ProcessHostileReceipt InvokeProcessBoundaryHostiles(){VerifySelf();string executable=Path.Combine(Environment.SystemDirectory,"WindowsPowerShell","v1.0","powershell.exe");List<UID0002PAV6ProcessReceipt> cases=new List<UID0002PAV6ProcessReceipt>();string output,error;cases.Add(ExecuteBoundedProgram(executable,"Start-Sleep -Seconds 60",500,"Timeout",out output,out error));cases.Add(ExecuteBoundedProgram(executable,HostileDescendantProgram(executable,false,true),5000,"DescendantSurvival",out output,out error));cases.Add(ExecuteBoundedProgram(executable,HostileDescendantProgram(executable,true,false),5000,"InheritedPipes",out output,out error));cases.Add(ExecuteBoundedProgram(executable,"[Console]::Out.Write(('X'*2097152))",30000,"OutputStall",out output,out error));cases.Add(ExecuteBoundedProgram(executable,"Start-Sleep -Milliseconds 500;[Console]::Out.Write('DRAIN_FAILURE')",5000,"DrainFailure",out output,out error));cases.Add(ExecuteBoundedProgram(executable,HostileDescendantProgram(executable,false,false),5000,"ParentExitLiveDescendant",out output,out error));string[] outcomes=new string[]{"PX6-PA child timeout","PX6-PA descendant survival observed","PX6-PA inherited pipe descendant contained","COMPLETED","PX6-PA drain failure","PX6-PA parent exit with live descendant"};StringBuilder canonical=new StringBuilder();for(int n=0;n<cases.Count;n++){UID0002PAV6ProcessReceipt receipt=cases[n];bool common=receipt.CompletionPortBound&&receipt.GenerationCensusComplete&&receipt.WatcherTerminal&&receipt.WatcherSucceeded&&receipt.InputDeliveryTerminal&&receipt.JobAssigned&&receipt.ImmediateGenerationRetired&&receipt.JobEmpty&&receipt.DrainsTerminal&&receipt.ActiveAfterContainment==0&&receipt.SameGenerationsAlive==0&&receipt.OwnedNetworkConnectionsAfter==0&&receipt.Outcome==outcomes[n];if(n==1||n==2||n==5)common=common&&receipt.DescendantsObserved>=1&&receipt.TotalProcesses>=2;if(n==2)common=common&&receipt.DrainsPendingBeforeContainment&&receipt.ParentExitedWithLiveDescendant;if(n==3)common=common&&receipt.DrainsSucceeded&&receipt.StdoutCharacters==2097152;if(n==4)common=common&&!receipt.DrainsSucceeded;else common=common&&receipt.DrainsSucceeded;if(!common)throw new UID0002PAV6RejectedException("HF6-PA process hostile mismatch: "+receipt.Scenario,"ProcessHostile",receipt.ChildPID,receipt.ChildGenerationUtcTicks,receipt.ImmediateGenerationRetired,0,0,0,0,0,receipt.JobEmpty?0:1,receipt);canonical.Append((n+1).ToString("D2",System.Globalization.CultureInfo.InvariantCulture)).Append('|').Append(receipt.Scenario).Append('|').Append(receipt.Outcome).Append('|').Append(receipt.DescendantsObserved).Append('|').Append(receipt.DrainsPendingBeforeContainment?'1':'0').Append('|').Append(receipt.DrainsSucceeded?'1':'0').Append('\n');}return new UID0002PAV6ProcessHostileReceipt(cases.Count,0,Sha256(canonical.ToString()),cases.ToArray());}

  static string BuildChildProgram(string payload,string mode,string nonce,string executableSha,string sourceSha,string apiSha,string methodsSha,string assemblySha,string canonical,string fixtureRoot,string authorityNonce,string scenario){
    string modeBody;
    if(mode=="PrivateFixtures")modeBody=@"
$uid0002paV6Raw=Invoke-UID0002PAHostileStaticFixtures
$uid0002paV6FixtureSaves=[long](($uid0002paV6Raw.Cases|Microsoft.PowerShell.Utility\Measure-Object -Property SaveDispatchCount -Sum).Sum)
$uid0002paV6FixtureTransports=[long](($uid0002paV6Raw.Cases|Microsoft.PowerShell.Utility\Measure-Object -Property TransportCalls -Sum).Sum)
$uid0002paV6Result=[ordered]@{kind='PrivateFixtures';passed=[long]$uid0002paV6Raw.Passed;failed=[long]$uid0002paV6Raw.Failed;production_coordinator_invocations=[long]$uid0002paV6Raw.ProductionCoordinatorInvocations;external_target_effects=[long]$uid0002paV6Raw.ExternalTargetEffects;effect_observations=[long]$uid0002paV6Raw.EffectObservations;fixture_save_operations=$uid0002paV6FixtureSaves;fixture_transport_operations=$uid0002paV6FixtureTransports;boundary_passed=[long]$uid0002paV6Raw.BoundaryPassed;boundary_failed=[long]$uid0002paV6Raw.BoundaryFailed;boundary_production_entries=[long]$uid0002paV6Raw.BoundaryProductionEntries;boundary_save_dispatch_count=[long]$uid0002paV6Raw.BoundarySaveDispatchCount;boundary_external_target_effects=[long]$uid0002paV6Raw.BoundaryExternalTargetEffects}
$uid0002paV6Outcome='PRIVATE_FIXTURES_PASSED';$uid0002paV6Session='fixture:no-live-session';$uid0002paV6Saves=0L;$uid0002paV6Transports=0L;$uid0002paV6External=[long]$uid0002paV6Raw.ExternalTargetEffects
";
    else if(mode=="LegacyWitness")modeBody=@"
$uid0002paV6Command=Microsoft.PowerShell.Core\Get-Command Invoke-UID0002PAClosedTransaction -CommandType Function
$uid0002paV6Entry=$uid0002paV6Command.ScriptBlock;$uid0002paV6Module=$uid0002paV6Entry.Module
if($null-eq$uid0002paV6Module){throw 'LW6-PA V5 closure module missing'}
$uid0002paV6Hash={param([string]$Text)$b=[Text.UTF8Encoding]::new($false,$true).GetBytes($Text);$h=[Security.Cryptography.SHA256]::Create();try{([BitConverter]::ToString($h.ComputeHash($b))).Replace('-','')}finally{$h.Dispose()}}
$uid0002paV6Before=&$uid0002paV6Hash ([string]$uid0002paV6Entry)
$uid0002paV6Old=$uid0002paV6Module.SessionState.PSVariable.Get('sharedCoordinator');if($null-eq$uid0002paV6Old){throw 'LW6-PA V5 sharedCoordinator missing'}
$uid0002paV6Forged={param($Capability,$Scope,$ForwardArguments)[pscustomobject][ordered]@{Outcome='FORGED_ACCEPTED';Scope='Production';TransportCalls=0L;Forged=$true}}.GetNewClosure()
$uid0002paV6Module.SessionState.PSVariable.Set('sharedCoordinator',$uid0002paV6Forged)
try{$uid0002paV6Raw=&$uid0002paV6Entry}finally{$uid0002paV6Module.SessionState.PSVariable.Set('sharedCoordinator',$uid0002paV6Old.Value)}
$uid0002paV6AfterVar=$uid0002paV6Module.SessionState.PSVariable.Get('sharedCoordinator');$uid0002paV6Restored=[object]::ReferenceEquals($uid0002paV6AfterVar.Value,$uid0002paV6Old.Value);$uid0002paV6After=&$uid0002paV6Hash ([string](Microsoft.PowerShell.Core\Get-Command Invoke-UID0002PAClosedTransaction -CommandType Function).ScriptBlock)
$uid0002paV6Result=[ordered]@{kind='LegacyWitness';outcome=[string]$uid0002paV6Raw.Outcome;scope=[string]$uid0002paV6Raw.Scope;transport_calls=[long]$uid0002paV6Raw.TransportCalls;forged=[bool]$uid0002paV6Raw.Forged;public_entry_sha_before=$uid0002paV6Before;public_entry_sha_after=$uid0002paV6After;module_restored=$uid0002paV6Restored}
$uid0002paV6Outcome='LEGACY_FORGED_ACCEPTED_WITNESSED';$uid0002paV6Session='legacy:no-live-session';$uid0002paV6Saves=0L;$uid0002paV6Transports=0L;$uid0002paV6External=0L
";
    else {
      string productionPrelude;
      if(fixtureRoot!=null)productionPrelude="$uid0002paV6Test=Invoke-UID0002PAV5ProductionTest -ExactRoot "+PSQuote(fixtureRoot)+"\n$uid0002paV6Raw=$uid0002paV6Test.Raw\n$uid0002paV6State=$uid0002paV6Test.State\n$uid0002paV6Measured=$uid0002paV6Test.Measured\n$uid0002paV6AuthorityKind='SealedProductionTest'\n$uid0002paV6FixtureTransports=[long]$uid0002paV6State.TransportCalls;$uid0002paV6FixtureSaves=[long]$uid0002paV6State.SaveCalls;$uid0002paV6FixtureRetires=[long]$uid0002paV6State.RetireCalls;$uid0002paV6FixtureRestores=[long]$uid0002paV6State.RestoreObserved;$uid0002paV6EffectObservations=[long]$uid0002paV6Measured.EffectObservations\n";
      else productionPrelude="$uid0002paV6Raw=Invoke-UID0002PAClosedTransaction\n$uid0002paV6Measured=[pscustomobject]@{EffectObservations=0L}\n$uid0002paV6AuthorityKind='LiveProduction'\n$uid0002paV6FixtureTransports=0L;$uid0002paV6FixtureSaves=0L;$uid0002paV6FixtureRetires=0L;$uid0002paV6FixtureRestores=0L;$uid0002paV6EffectObservations=0L\n";
      modeBody=productionPrelude+@"
if($uid0002paV6Raw.Kind-cne'Production'-or$uid0002paV6Raw.ReceiptSchema-ne1){throw 'TR6-PA production coordinator receipt absent'}
$uid0002paV6TargetChanged=[bool]($null-ne$uid0002paV6Raw.P1-and$uid0002paV6Raw.P0.sha256-cne$uid0002paV6Raw.P1.sha256);$uid0002paV6FileEffects=if($uid0002paV6TargetChanged){1L}else{0L}
$uid0002paV6Saves=[long]$uid0002paV6Raw.SaveDispatchCount;$uid0002paV6Transports=[long]$uid0002paV6Raw.TransportCalls;$uid0002paV6External=if($uid0002paV6AuthorityKind-ceq'LiveProduction'){$uid0002paV6FileEffects}else{[long]$uid0002paV6Measured.ExternalTargetEffects}
$uid0002paV6Plan=$uid0002paV6Raw.ProductionOperationPlan;$uid0002paV6Mcp=[long]$uid0002paV6Plan.ExternalMcpDispatches;$uid0002paV6Ida=[long]$uid0002paV6Plan.ExternalIdaDispatches
$uid0002paV6Operation=[ordered]@{plan_sha256=[string]$uid0002paV6Plan.PlanSHA256;expected_total=[long]$uid0002paV6Plan.ExpectedTotal;observed_total=[long]$uid0002paV6Plan.ObservedTotal;expected_live_mcp_calls=[long]$uid0002paV6Plan.ExpectedLiveMcpCalls;expected_live_ida_write_calls=[long]$uid0002paV6Plan.ExpectedLiveIdaWriteCalls;observed_fixture_transport_calls=[long]$uid0002paV6Plan.ObservedFixtureTransportCalls;observed_fixture_ida_write_calls=[long]$uid0002paV6Plan.ObservedFixtureIdaWriteCalls;forbidden_calls=[long]$uid0002paV6Plan.ForbiddenCalls;extra_calls=[long]$uid0002paV6Plan.ExtraCalls;missed_calls=[long]$uid0002paV6Plan.MissedCalls;external_mcp_dispatches=$uid0002paV6Mcp;external_ida_dispatches=$uid0002paV6Ida;pre_dispatch_enforced=[bool]$uid0002paV6Plan.PreDispatchEnforced;permitted_counts=[ordered]@{'tools/list'=[long]$uid0002paV6Plan.PermittedCounts.'tools/list';idb_open=[long]$uid0002paV6Plan.PermittedCounts.idb_open;idb_list=[long]$uid0002paV6Plan.PermittedCounts.idb_list;runtime_attestation=[long]$uid0002paV6Plan.PermittedCounts.runtime_attestation;entity_query=[long]$uid0002paV6Plan.PermittedCounts.entity_query;declare_type=[long]$uid0002paV6Plan.PermittedCounts.declare_type;rename=[long]$uid0002paV6Plan.PermittedCounts.rename;set_type=[long]$uid0002paV6Plan.PermittedCounts.set_type;set_function_comments=[long]$uid0002paV6Plan.PermittedCounts.set_function_comments;set_address_comments=[long]$uid0002paV6Plan.PermittedCounts.set_address_comments;idb_save=[long]$uid0002paV6Plan.PermittedCounts.idb_save}}
"+((scenario=="FalseZero")?"$uid0002paV6Transports=0L\n":"")+((scenario=="NonzeroProhibited")?"$uid0002paV6Mcp=1L;$uid0002paV6Operation.external_mcp_dispatches=1L\n":"")+@"
$uid0002paV6ExpectedFixture=[ordered]@{adapter_transport_calls=$uid0002paV6FixtureTransports;adapter_save_calls=$uid0002paV6FixtureSaves;adapter_retire_calls=$uid0002paV6FixtureRetires;adapter_restore_writes=$uid0002paV6FixtureRestores;target_changed=$uid0002paV6TargetChanged;effect_observations=$uid0002paV6EffectObservations}
$uid0002paV6Result=[ordered]@{kind='Production';receipt_schema=[long]$uid0002paV6Raw.ReceiptSchema;authority_kind=$uid0002paV6AuthorityKind;authority_nonce="+PSQuote(authorityNonce??"live")+";fixture_case="+PSQuote(scenario??"Live")+@";status=[string]$uid0002paV6Raw.Status;terminal_class=[string]$uid0002paV6Raw.TerminalClass;cause=[string]$uid0002paV6Raw.Cause;canonical_database=[string]$uid0002paV6Raw.CanonicalDatabase;database_session=[string]$uid0002paV6Raw.DatabaseSession;transaction_id=[string]$uid0002paV6Raw.TransactionId;final_state=[string]$uid0002paV6Raw.FinalState;save_dispatch_count=$uid0002paV6Saves;transport_calls=$uid0002paV6Transports;retire_calls=[long]$uid0002paV6Raw.RetireCalls;restore_writes=[long]$uid0002paV6Raw.RestoreWrites;dopen_captured=[bool]$uid0002paV6Raw.DopenCaptured;journal_retained=[bool]$uid0002paV6Raw.JournalRetained;schema_sha256=[string]$uid0002paV6Raw.SchemaSHA256;plan_sha256=[string]$uid0002paV6Raw.PlanSHA256;transport_log_sha256=[string]$uid0002paV6Raw.TransportLogSHA256;state_log_sha256=[string]$uid0002paV6Raw.StateLogSHA256;transport_log=@($uid0002paV6Raw.TransportLog);state_log=@($uid0002paV6Raw.StateLog);p0=$uid0002paV6Raw.P0;b0=$uid0002paV6Raw.B0;dopen=$uid0002paV6Raw.Dopen;dclosed=$uid0002paV6Raw.Dclosed;p1=$uid0002paV6Raw.P1;expected_fixture_effects=$uid0002paV6ExpectedFixture;operation_reconciliation=$uid0002paV6Operation}
$uid0002paV6Outcome=[string]$uid0002paV6Raw.Status;$uid0002paV6Session=[string]$uid0002paV6Raw.DatabaseSession
";
    }
    string suffix=modeBody+@"
$uid0002paV6Process=[Diagnostics.Process]::GetCurrentProcess();try{$uid0002paV6Generation=$uid0002paV6Process.StartTime.ToUniversalTime().Ticks}finally{$uid0002paV6Process.Dispose()}
$uid0002paV6ResultJson=Microsoft.PowerShell.Utility\ConvertTo-Json -InputObject ([pscustomobject]$uid0002paV6Result) -Depth 20 -Compress
$uid0002paV6Utf8=[Text.UTF8Encoding]::new($false,$true);$uid0002paV6Hasher=[Security.Cryptography.SHA256]::Create();try{$uid0002paV6ResultSha=([BitConverter]::ToString($uid0002paV6Hasher.ComputeHash($uid0002paV6Utf8.GetBytes($uid0002paV6ResultJson)))).Replace('-','')}finally{$uid0002paV6Hasher.Dispose()}
$uid0002paV6Mcp=if($null-eq(Get-Variable uid0002paV6Mcp -ErrorAction SilentlyContinue)){0L}else{[long]$uid0002paV6Mcp};$uid0002paV6Ida=if($null-eq(Get-Variable uid0002paV6Ida -ErrorAction SilentlyContinue)){0L}else{[long]$uid0002paV6Ida};$uid0002paV6FileEffects=if($null-eq(Get-Variable uid0002paV6FileEffects -ErrorAction SilentlyContinue)){0L}else{[long]$uid0002paV6FileEffects}
$uid0002paV6Counters=[ordered]@{save_dispatches=[long]$uid0002paV6Saves;transport_calls=[long]$uid0002paV6Transports;external_target_effects=[long]$uid0002paV6External;mcp_effects=$uid0002paV6Mcp;ida_effects=$uid0002paV6Ida;filesystem_effects=$uid0002paV6FileEffects}
";
    suffix+="$uid0002paV6Envelope=[ordered]@{schema=6;marker="+PSQuote(TranscriptMarker)+";mode="+PSQuote(mode)+";invocation_nonce="+PSQuote(nonce)+";sequence=1L;child_pid=[long]$PID;child_generation_utc_ticks=[long]$uid0002paV6Generation;executable_sha256="+PSQuote(executableSha)+";payload_sha256="+PSQuote(ExpectedPayloadSHA256)+";public_entry_sha256="+PSQuote(ExpectedPublicEntrySHA256)+";fixture_entry_sha256="+PSQuote(ExpectedFixtureEntrySHA256)+";source_sha256="+PSQuote(sourceSha)+";api_sha256="+PSQuote(apiSha)+";method_manifest_sha256="+PSQuote(methodsSha)+";assembly_sha256="+PSQuote(assemblySha)+";canonical_database="+PSQuote(canonical)+";database_session=$uid0002paV6Session;counters=$uid0002paV6Counters;result_json_b64=[Convert]::ToBase64String($uid0002paV6Utf8.GetBytes($uid0002paV6ResultJson));result_sha256=$uid0002paV6ResultSha;outcome=$uid0002paV6Outcome}\n";
    suffix+="$uid0002paV6Line=Microsoft.PowerShell.Utility\\ConvertTo-Json -InputObject ([pscustomobject]$uid0002paV6Envelope) -Depth 20 -Compress\nif([string]::IsNullOrWhiteSpace($uid0002paV6Line)-or$uid0002paV6Line.IndexOf([char]10)-ge0-or$uid0002paV6Line.IndexOf([char]13)-ge0){throw 'TR6-PA invalid serialized transcript'}\n[Console]::Out.Write($uid0002paV6Line)\n";
    return "Set-StrictMode -Version 2.0\n$ErrorActionPreference='Stop'\n$WarningPreference='Stop'\n$InformationPreference='Stop'\n$VerbosePreference='SilentlyContinue'\n$DebugPreference='SilentlyContinue'\n$ProgressPreference='SilentlyContinue'\n"+payload+suffix;
  }

  static IDictionary<string,object> ParseTranscript(string json,string mode,string nonce,int pid,long generation,string executableSha,string sourceSha,string apiSha,string methodsSha,string assemblySha,string expectedCanonical,string authorityNonce,string scenario,out string resultJson,out string resultSha,out string session,out string outcome,out long saves,out long transports,out long external,out long mcp,out long ida,out long fileEffects){
    UID0002PAV6RawJsonScanner.RejectDuplicates(json,"root");
    JavaScriptSerializer j=new JavaScriptSerializer();j.MaxJsonLength=33554432;
    IDictionary<string,object> root=Dict(j.DeserializeObject(json),"root");
    ExactKeys(root,new string[]{"schema","marker","mode","invocation_nonce","sequence","child_pid","child_generation_utc_ticks","executable_sha256","payload_sha256","public_entry_sha256","fixture_entry_sha256","source_sha256","api_sha256","method_manifest_sha256","assembly_sha256","canonical_database","database_session","counters","result_json_b64","result_sha256","outcome"},"root");
    if(Int64Value(root["schema"],"schema")!=6||Str(root["marker"],"marker")!=TranscriptMarker||Str(root["mode"],"mode")!=mode||Str(root["invocation_nonce"],"nonce")!=nonce||Int64Value(root["sequence"],"sequence")!=1||Int64Value(root["child_pid"],"pid")!=pid||Int64Value(root["child_generation_utc_ticks"],"generation")!=generation)throw new UID0002PAV6RejectedException("TR6-PA root identity mismatch","Transcript");
    if(Str(root["executable_sha256"],"executable")!=executableSha||Str(root["payload_sha256"],"payload")!=ExpectedPayloadSHA256||Str(root["public_entry_sha256"],"entry")!=ExpectedPublicEntrySHA256||Str(root["fixture_entry_sha256"],"fixture")!=ExpectedFixtureEntrySHA256||Str(root["source_sha256"],"source")!=sourceSha||Str(root["api_sha256"],"api")!=apiSha||Str(root["method_manifest_sha256"],"methods")!=methodsSha||Str(root["assembly_sha256"],"assembly")!=assemblySha||!String.Equals(Path.GetFullPath(Str(root["canonical_database"],"canonical")),Path.GetFullPath(expectedCanonical),StringComparison.OrdinalIgnoreCase))throw new UID0002PAV6RejectedException("TR6-PA sealed identity mismatch","Transcript");
    session=Str(root["database_session"],"session");outcome=Str(root["outcome"],"outcome");
    IDictionary<string,object> c=Dict(root["counters"],"counters");ExactKeys(c,new string[]{"save_dispatches","transport_calls","external_target_effects","mcp_effects","ida_effects","filesystem_effects"},"counters");
    saves=Int64Value(c["save_dispatches"],"save");transports=Int64Value(c["transport_calls"],"transport");external=Int64Value(c["external_target_effects"],"external");mcp=Int64Value(c["mcp_effects"],"mcp");ida=Int64Value(c["ida_effects"],"ida");fileEffects=Int64Value(c["filesystem_effects"],"filesystem");
    byte[] rb;try{rb=Convert.FromBase64String(Str(root["result_json_b64"],"result_b64"));resultJson=new UTF8Encoding(false,true).GetString(rb);}catch{throw new UID0002PAV6RejectedException("TR6-PA result encoding mismatch","Transcript");}
    resultSha=Str(root["result_sha256"],"result_sha");if(Sha256(resultJson)!=resultSha)throw new UID0002PAV6RejectedException("TR6-PA result hash mismatch","Transcript");
    UID0002PAV6RawJsonScanner.RejectDuplicates(resultJson,"result");
    IDictionary<string,object> result=Dict(j.DeserializeObject(resultJson),"result");
    if(mode=="PrivateFixtures"){
      ExactKeys(result,new string[]{"kind","passed","failed","production_coordinator_invocations","external_target_effects","effect_observations","fixture_save_operations","fixture_transport_operations","boundary_passed","boundary_failed","boundary_production_entries","boundary_save_dispatch_count","boundary_external_target_effects"},"private-result");
      if(Str(result["kind"],"kind")!="PrivateFixtures"||Int64Value(result["passed"],"passed")!=27||Int64Value(result["failed"],"failed")!=0||Int64Value(result["production_coordinator_invocations"],"entries")!=27||Int64Value(result["external_target_effects"],"effects")!=0||Int64Value(result["effect_observations"],"observations")!=170||Int64Value(result["boundary_passed"],"boundary_passed")!=11||Int64Value(result["boundary_failed"],"boundary_failed")!=0||Int64Value(result["boundary_production_entries"],"boundary_entries")!=0||Int64Value(result["boundary_save_dispatch_count"],"boundary_save")!=0||Int64Value(result["boundary_external_target_effects"],"boundary_effects")!=0)throw new UID0002PAV6RejectedException("TR6-PA private result mismatch","Transcript");
    } else if(mode=="LegacyWitness"){
      ExactKeys(result,new string[]{"kind","outcome","scope","transport_calls","forged","public_entry_sha_before","public_entry_sha_after","module_restored"},"legacy-result");
      if(Str(result["kind"],"kind")!="LegacyWitness"||Str(result["outcome"],"legacy outcome")!="FORGED_ACCEPTED"||Str(result["scope"],"scope")!="Production"||Int64Value(result["transport_calls"],"transport")!=0||!BoolValue(result["forged"],"forged")||Str(result["public_entry_sha_before"],"before")!=Str(result["public_entry_sha_after"],"after")||!BoolValue(result["module_restored"],"restored"))throw new UID0002PAV6RejectedException("TR6-PA legacy witness mismatch","Transcript");
    } else ValidateProductionReceipt(result,expectedCanonical,authorityNonce,scenario,saves,transports,external,mcp,ida,fileEffects);
    string replayKey=Sha256(json+"|"+mode+"|"+nonce+"|"+pid+"|"+generation);
    if(!ConsumedTranscriptHashes.TryAdd(replayKey,1))throw new UID0002PAV6RejectedException("TR6-PA transcript replay","Transcript");
    return root;
  }

  static string CreateProductionFixtureRoot(string nonce){string root=Path.Combine(Path.GetTempPath(),"uid0002pa-v6-production-"+nonce),source=Path.Combine(root,"source");Directory.CreateDirectory(source);byte[] initial=new byte[8];for(int i=0;i<initial.Length;i++)initial[i]=(byte)(i+1);File.WriteAllBytes(Path.Combine(root,"fixture.i64"),initial);File.WriteAllText(Path.Combine(source,"listener.py"),"listener-v4",new UTF8Encoding(false));File.WriteAllText(Path.Combine(source,"worker.py"),"worker-v4",new UTF8Encoding(false));return root;}
  static UID0002PAV6Transcript RunIsolated(string mode,string scenario){
    VerifySelf();bool productionTest=mode=="ProductionTest";if((mode=="Production"&&scenario!=null)||(productionTest&&(scenario!="P1"&&scenario!="FalseZero"&&scenario!="NonzeroProhibited"))||(!productionTest&&mode!="Production"&&mode!="PrivateFixtures"&&mode!="LegacyWitness")||((mode=="PrivateFixtures"||mode=="LegacyWitness")&&scenario!=null))throw new UID0002PAV6RejectedException("CT6-PA fixture diversion/live-child bypass rejected","Preflight");
    int fences;string sourceSha;string payload=ReadPackage(out fences,out sourceSha);string apiSha=CurrentApiSHA256(),methodsSha=CurrentMethodManifestSHA256(),assemblySha=CurrentAssemblySHA256();string executable=Path.Combine(Environment.SystemDirectory,"WindowsPowerShell","v1.0","powershell.exe");if(!File.Exists(executable))throw new UID0002PAV6RejectedException("PK6-PA exact Windows PowerShell executable absent","Start");string executableSha=FileSha256(executable),nonce=Guid.NewGuid().ToString("N"),authorityNonce=productionTest?"sealed-test-"+nonce:null,fixtureRoot=null,canonical=CanonicalDatabase;string[] cleanupBaseline;UID0002PAV6CleanupReceipt cleanupBegin=BeginGenerationCleanup(out cleanupBaseline);UID0002PAV6Transcript pendingTranscript=null;UID0002PAV6RejectedException pendingRejection=null;
    try{
      if(productionTest){fixtureRoot=CreateProductionFixtureRoot(nonce);canonical=Path.Combine(fixtureRoot,"fixture.i64");}
      string protectedBefore=ProtectedReceipt(),beforeTarget=FileTuple(canonical),fileCensusBefore=FileSystemCensus(canonical,fixtureRoot);bool beforeJournal=File.Exists(canonical+".uid0002pa-v4.journal"),beforeBackup=File.Exists(canonical+".uid0002pa-v4.backup");int listenerBefore,ignoredBefore;string beforeTcp=TcpReceipt(0,out listenerBefore,out ignoredBefore),output,error;string childProgram=BuildChildProgram(payload,mode,nonce,executableSha,sourceSha,apiSha,methodsSha,assemblySha,canonical,fixtureRoot,authorityNonce,scenario);UID0002PAV6ProcessReceipt processReceipt=ExecuteBoundedProgram(executable,childProgram,300000,"Normal",out output,out error);int pid=processReceipt.ChildPID;long generation=processReceipt.ChildGenerationUtcTicks;bool retired=processReceipt.ImmediateGenerationRetired;
      int listenerAfter,afterChildConnections;string afterTcp=TcpReceipt(pid,out listenerAfter,out afterChildConnections),afterTarget=FileTuple(canonical),protectedAfter=ProtectedReceipt(),fileCensusAfter=FileSystemCensus(canonical,fixtureRoot);bool afterJournal=File.Exists(canonical+".uid0002pa-v4.journal"),afterBackup=File.Exists(canonical+".uid0002pa-v4.backup");bool closedProcessBoundary=processReceipt.CompletionPortBound&&processReceipt.GenerationCensusComplete&&processReceipt.WatcherTerminal&&processReceipt.WatcherSucceeded&&processReceipt.InputDeliveryTerminal&&processReceipt.JobAssigned&&processReceipt.ImmediateGenerationRetired&&processReceipt.JobEmpty&&processReceipt.DrainsTerminal&&processReceipt.DrainsSucceeded&&processReceipt.Outcome=="COMPLETED"&&processReceipt.ExitCode==0&&processReceipt.TotalProcesses>=1&&processReceipt.ActiveAfterContainment==0&&processReceipt.SameGenerationsAlive==0&&processReceipt.OwnedNetworkConnectionsAfter==0;long processEffects=closedProcessBoundary?0L:1L,independentFileEffects=beforeTarget==afterTarget?0L:1L;
      if(!closedProcessBoundary)throw new UID0002PAV6RejectedException("PK6-PA contained child/drain receipt mismatch: "+processReceipt.Outcome,"Retirement",pid,generation,retired,0,0,independentFileEffects,0,0,processEffects,processReceipt);if(error==null||error.Length!=0)throw new UID0002PAV6RejectedException("PK6-PA isolated child failure: "+error,"Child",pid,generation,retired,0,0,independentFileEffects,0,0,processEffects,processReceipt);if(output==null||output.Length==0||output.IndexOf('\r')>=0||output.IndexOf('\n')>=0)throw new UID0002PAV6RejectedException("TR6-PA expected exactly one nonblank stdout record","Transcript",pid,generation,retired,0,0,independentFileEffects,0,0,processEffects,processReceipt);
      string resultJson=null,resultSha=null,session=null,outcome=null;long childSaves=0,childTransports=0,childExternal=0,childMcp=0,childIda=0,childFileEffects=0;try{ParseTranscript(output,mode,nonce,pid,generation,executableSha,sourceSha,apiSha,methodsSha,assemblySha,canonical,authorityNonce,scenario,out resultJson,out resultSha,out session,out outcome,out childSaves,out childTransports,out childExternal,out childMcp,out childIda,out childFileEffects);}catch(UID0002PAV6RejectedException ex){long observedTransports=productionTest?CountProductionSends(resultJson):childTransports;throw new UID0002PAV6RejectedException(ex.RejectionCode,ex.Stage,pid,generation,retired,childSaves,observedTransports,independentFileEffects,childMcp,childIda,processEffects,processReceipt);}
      if((mode=="PrivateFixtures"||mode=="LegacyWitness")&&(processEffects!=0||childSaves!=0||childTransports!=0||childExternal!=0||childMcp!=0||childIda!=0||childFileEffects!=0||beforeTarget!=afterTarget||fileCensusBefore!=fileCensusAfter||beforeJournal!=afterJournal||beforeBackup!=afterBackup||protectedBefore!=protectedAfter||listenerBefore!=listenerAfter||afterChildConnections!=0))throw new UID0002PAV6RejectedException("RC6-PA independent no-effect receipt mismatch","Receipt",pid,generation,retired,childSaves,childTransports,independentFileEffects,childMcp,childIda,processEffects,processReceipt);
      if(productionTest&&(beforeTarget==afterTarget||fileCensusBefore==fileCensusAfter||beforeJournal||beforeBackup||afterJournal||afterBackup||protectedBefore!=protectedAfter||listenerBefore!=listenerAfter||afterChildConnections!=0||processEffects!=0||childSaves!=1||childTransports!=428||childExternal!=0||childMcp!=0||childIda!=0||childFileEffects!=1))throw new UID0002PAV6RejectedException("RC6-PA independent sealed production-test mismatch","Receipt",pid,generation,retired,childSaves,childTransports,independentFileEffects,childMcp,childIda,processEffects,processReceipt);
      if(mode=="Production"&&(childExternal!=independentFileEffects||childMcp!=428||childIda!=6||childFileEffects!=independentFileEffects||protectedBefore==protectedAfter))throw new UID0002PAV6RejectedException("RC6-PA live production reconciliation mismatch","Receipt",pid,generation,retired,childSaves,childTransports,independentFileEffects,childMcp,childIda,processEffects,processReceipt);
      pendingTranscript=new UID0002PAV6Transcript(mode,output,Sha256(output),resultJson,resultSha,nonce,1,pid,generation,executableSha,retired,true,ExpectedPayloadSHA256,sourceSha,apiSha,methodsSha,assemblySha,ExpectedPublicEntrySHA256,ExpectedFixtureEntrySHA256,canonical,session,outcome,childSaves,childTransports,childExternal,childMcp,childIda,independentFileEffects,processEffects,beforeTarget,afterTarget,beforeTcp,afterTcp,listenerBefore,listenerAfter,afterChildConnections,beforeJournal,afterJournal,beforeBackup,afterBackup,fileCensusBefore,fileCensusAfter,processReceipt);return pendingTranscript;
    }catch(UID0002PAV6RejectedException ex){pendingRejection=ex;throw;}catch(Exception ex){pendingRejection=new UID0002PAV6RejectedException("PK6-PA isolated boundary failure: "+ex.GetType().FullName,"Child");throw pendingRejection;}finally{
      UID0002PAV6CleanupReceipt cleanupFinal=CompleteGenerationCleanup(cleanupBegin,cleanupBaseline);if(pendingTranscript!=null)pendingTranscript.BindCleanup(cleanupFinal);if(pendingRejection!=null)pendingRejection.BindCleanup(cleanupFinal);
    }
  }

  public static UID0002PAV6Attestation InspectPackage(){VerifySelf();int fences;string source;ReadPackage(out fences,out source);return new UID0002PAV6Attestation(ReportPath,ExpectedPayloadSHA256,source,CurrentApiSHA256(),CurrentMethodManifestSHA256(),CurrentAssemblySHA256(),ExpectedPublicEntrySHA256,ExpectedFixtureEntrySHA256,fences,HasMutableHostFields());}
  public static UID0002PAV6Transcript InvokeProduction(){VerifySelf();return RunIsolated("Production",null);}
  public static UID0002PAV6ProductionTestControls InvokeProductionTestControls(){VerifySelf();UID0002PAV6Transcript accepted=RunIsolated("ProductionTest","P1");UID0002PAV6RejectedException falseZero=null,nonzero=null;try{RunIsolated("ProductionTest","FalseZero");}catch(UID0002PAV6RejectedException ex){falseZero=ex;}try{RunIsolated("ProductionTest","NonzeroProhibited");}catch(UID0002PAV6RejectedException ex){nonzero=ex;}if(falseZero==null||nonzero==null)throw new UID0002PAV6RejectedException("HF6-PA production-test negative control accepted","Controls");return new UID0002PAV6ProductionTestControls(accepted,falseZero,nonzero);}
  public static UID0002PAV6Transcript InvokePrivateFixtures(){VerifySelf();return RunIsolated("PrivateFixtures",null);}
  public static UID0002PAV6Transcript InvokeLegacyWitness(){VerifySelf();return RunIsolated("LegacyWitness",null);}
  static bool ReplayRejected(UID0002PAV6Transcript transcript,string authorityNonce,string scenario){string resultJson,resultSha,session,outcome;long saves,transports,external,mcp,ida,fileEffects;try{ParseTranscript(transcript.Json,transcript.Mode,transcript.InvocationNonce,transcript.ChildPID,transcript.ChildGenerationUtcTicks,transcript.ExecutableSHA256,transcript.SourceSHA256,transcript.ApiSHA256,transcript.MethodManifestSHA256,transcript.AssemblySHA256,transcript.CanonicalDatabase,authorityNonce,scenario,out resultJson,out resultSha,out session,out outcome,out saves,out transports,out external,out mcp,out ida,out fileEffects);}catch(UID0002PAV6RejectedException ex){if(ex.RejectionCode=="TR6-PA transcript replay")return true;throw;}return false;}
  static bool InvokeProductionReplayHostile(UID0002PAV6Transcript transcript){JavaScriptSerializer j=new JavaScriptSerializer();IDictionary<string,object> result=Dict(j.DeserializeObject(transcript.ResultJson),"production-replay");string fixture=Str(result["fixture_case"],"fixture_case"),authority=Str(result["authority_nonce"],"authority_nonce");return ReplayRejected(transcript,authority,fixture=="Live"?null:fixture);}
  public static UID0002PAV6ReplayReceipt InvokeReplayHostiles(){VerifySelf();UID0002PAV6Transcript transcript=RunIsolated("PrivateFixtures",null);int rejected=0;if(ReplayRejected(transcript,null,null))rejected++;Thread.Sleep(50);if(ReplayRejected(transcript,null,null))rejected++;if(rejected!=2)throw new UID0002PAV6RejectedException("TR6-PA replay hostile accepted","Transcript");return new UID0002PAV6ReplayReceipt(rejected,transcript);}
  static void RequireDuplicateRejection(string json,string expected){try{UID0002PAV6RawJsonScanner.RejectDuplicates(json,"hostile");}catch(UID0002PAV6RejectedException ex){if(ex.RejectionCode==expected)return;throw;}throw new UID0002PAV6RejectedException("TR6-PA duplicate hostile accepted","Transcript");}
  public static int InvokeRawJsonHostiles(){VerifySelf();RequireDuplicateRejection("{\"schema\":6,\"schema\":6}","TR6-PA duplicate raw JSON member: $.schema");RequireDuplicateRejection("{\"counters\":{\"save_dispatches\":0,\"save_dispatches\":0}}","TR6-PA duplicate raw JSON member: $.counters.save_dispatches");RequireDuplicateRejection("{\"result\":{\"kind\":\"A\",\"kind\":\"B\"}}","TR6-PA duplicate raw JSON member: $.result.kind");return 3;}
}
'@
    $uid0002paV6Report=[IO.File]::ReadAllText('E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B010\research\0002PA-ConfigEntryBlockReleaseOwnedBuffers-source-quality.md',[Text.UTF8Encoding]::new($false,$true));if($uid0002paV6Report.IndexOf([char]13)-ge0-or-not$uid0002paV6Report.EndsWith("`n")){throw 'CP6-PA initializer report normalization shape mismatch'}
    $uid0002paV6Fences=[regex]::Matches($uid0002paV6Report,'(?ms)^~~~powershell\n(.*?)^~~~[ \t]*$');if($uid0002paV6Fences.Count-ne11){throw 'CP6-PA initializer exact fence count mismatch'};$uid0002paV6SourceMatch=[regex]::Match($uid0002paV6Fences[10].Groups[1].Value,"(?ms)^    \`$source=@'\n(.*?)^'@[ \t]*$");if(-not$uid0002paV6SourceMatch.Success){throw 'CP6-PA initializer report-owned source missing'};$source=$uid0002paV6SourceMatch.Groups[1].Value
    if($source.IndexOf([char]13)-ge0-or-not$source.EndsWith("`n")){throw 'CP6-PA initializer source normalization shape mismatch'}
    $uid0002paV6Utf8=[Text.UTF8Encoding]::new($false,$true)
    $uid0002paV6SourcePattern='(?m)^(  public const string Expected(?:Source|Api|MethodManifest|Assembly|PublicEntry|FixtureEntry)SHA256=")[^"]+(";)$';$uid0002paV6SourceRows=[regex]::Matches($source,$uid0002paV6SourcePattern);if($uid0002paV6SourceRows.Count-ne6){throw 'CP6-PA initializer source normalization identity count mismatch'};$uid0002paV6Normalized=[regex]::Replace($source,$uid0002paV6SourcePattern,'$1__NORMALIZED__$2')
    $uid0002paV6Hasher=[Security.Cryptography.SHA256]::Create();try{$uid0002paV6SourceSha=([BitConverter]::ToString($uid0002paV6Hasher.ComputeHash($uid0002paV6Utf8.GetBytes($uid0002paV6Normalized)))).Replace('-','')}finally{$uid0002paV6Hasher.Dispose()}
    if($uid0002paV6SourceSha-cne'E94F3BFF320918B7402EB3A47E64948D05997505BAA0351A11A41AB1D1CE4B9B'){throw 'CP6-PA initializer source hash mismatch'}
    Microsoft.PowerShell.Utility\Add-Type -TypeDefinition $source -Language CSharp -ReferencedAssemblies @('System.dll','System.Core.dll','System.Web.Extensions.dll') -ErrorAction Stop
    $uid0002paV6Attestation=[UID0002PAV6IsolatedHost]::InspectPackage()
    if($uid0002paV6Attestation.SourceSHA256-cne$uid0002paV6SourceSha){throw 'CP6-PA initializer/host source identity mismatch'}
    Remove-Variable source,uid0002paV6Report,uid0002paV6Fences,uid0002paV6SourceMatch,uid0002paV6Utf8,uid0002paV6SourcePattern,uid0002paV6SourceRows,uid0002paV6Normalized,uid0002paV6Hasher,uid0002paV6SourceSha,uid0002paV6Attestation -ErrorAction SilentlyContinue
}

Initialize-UID0002PAV6IsolatedAuthority

function Invoke-UID0002PAClosedTransaction {
    [CmdletBinding()]param([Parameter(ValueFromRemainingArguments=$true)][object[]]$RejectedArguments)
    if($null-ne$RejectedArguments){throw 'CT6-PA public entry accepts exactly zero arguments'}
    $uid0002paV6Current=(Microsoft.PowerShell.Core\Get-Command Invoke-UID0002PAClosedTransaction -CommandType Function).ScriptBlock
    $uid0002paV6Utf8=[Text.UTF8Encoding]::new($false,$true);$uid0002paV6Hasher=[Security.Cryptography.SHA256]::Create();try{$uid0002paV6Sha=([BitConverter]::ToString($uid0002paV6Hasher.ComputeHash($uid0002paV6Utf8.GetBytes([string]$uid0002paV6Current)))).Replace('-','')}finally{$uid0002paV6Hasher.Dispose()}
    if($uid0002paV6Sha-cne[UID0002PAV6IsolatedHost]::ExpectedPublicEntrySHA256){throw 'CP6-PA public wrapper hash mismatch'}
    [UID0002PAV6IsolatedHost]::InvokeProduction()
}

function Invoke-UID0002PAHostileStaticFixtures {
    [CmdletBinding()]param([Parameter(ValueFromRemainingArguments=$true)][object[]]$RejectedArguments)
    if($null-ne$RejectedArguments){throw 'CT6-PA private fixture entry accepts exactly zero arguments'}
    $uid0002paV6Current=(Microsoft.PowerShell.Core\Get-Command Invoke-UID0002PAHostileStaticFixtures -CommandType Function).ScriptBlock
    $uid0002paV6Utf8=[Text.UTF8Encoding]::new($false,$true);$uid0002paV6Hasher=[Security.Cryptography.SHA256]::Create();try{$uid0002paV6Sha=([BitConverter]::ToString($uid0002paV6Hasher.ComputeHash($uid0002paV6Utf8.GetBytes([string]$uid0002paV6Current)))).Replace('-','')}finally{$uid0002paV6Hasher.Dispose()}
    if($uid0002paV6Sha-cne[UID0002PAV6IsolatedHost]::ExpectedFixtureEntrySHA256){throw 'CP6-PA fixture wrapper hash mismatch'}
    [UID0002PAV6IsolatedHost]::InvokePrivateFixtures()
}

function Invoke-UID0002PAV6ConcurrentWrapperHostile {
    [CmdletBinding()]param()
    $uid0002paV6Entry=(Microsoft.PowerShell.Core\Get-Command Invoke-UID0002PAClosedTransaction -CommandType Function).ScriptBlock
    $uid0002paV6ExpectedPublic=[UID0002PAV6IsolatedHost]::ExpectedPublicEntrySHA256
    $uid0002paV6ExpectedSource=[UID0002PAV6IsolatedHost]::ExpectedSourceSHA256
    $uid0002paV6Gate=[Threading.ManualResetEventSlim]::new($false)
    $uid0002paV6Pool=[RunspaceFactory]::CreateRunspacePool(1,8);$uid0002paV6Pool.Open()
    $uid0002paV6Workers=[Collections.Generic.List[object]]::new()
    try{
        1..8|ForEach-Object{
            $uid0002paV6PS=[PowerShell]::Create();$uid0002paV6PS.RunspacePool=$uid0002paV6Pool
            $null=$uid0002paV6PS.AddScript(@'
param($ExactEntry,$Gate,$ExpectedPublic,$ExpectedSource)
if(-not$Gate.Wait(30000)){throw 'HF6-PA concurrency gate timeout'}
Set-Item -LiteralPath Function:\Invoke-UID0002PAClosedTransaction -Value $ExactEntry -Force
$saved=(Microsoft.PowerShell.Core\Get-Command Invoke-UID0002PAClosedTransaction -CommandType Function).ScriptBlock
try{
  Set-Item -LiteralPath Function:\Invoke-UID0002PAClosedTransaction -Value {throw 'FORGED-CONCURRENT'} -Force
  $current=(Microsoft.PowerShell.Core\Get-Command Invoke-UID0002PAClosedTransaction -CommandType Function).ScriptBlock
  $utf8=[Text.UTF8Encoding]::new($false,$true);$hasher=[Security.Cryptography.SHA256]::Create();try{$replacedSha=([BitConverter]::ToString($hasher.ComputeHash($utf8.GetBytes([string]$current)))).Replace('-','')}finally{$hasher.Dispose()}
  if($replacedSha-ceq$ExpectedPublic){throw 'HF6-PA concurrent replacement hash unexpectedly trusted'}
  $att=[UID0002PAV6IsolatedHost]::InspectPackage()
  if($att.PublicEntrySHA256-cne$ExpectedPublic-or$att.SourceSHA256-cne$ExpectedSource-or$att.MutableHostFields){throw 'HF6-PA concurrent compiled authority drift'}
}finally{Set-Item -LiteralPath Function:\Invoke-UID0002PAClosedTransaction -Value $saved -Force}
$after=(Microsoft.PowerShell.Core\Get-Command Invoke-UID0002PAClosedTransaction -CommandType Function).ScriptBlock
if([string]$after-cne[string]$saved){throw 'HF6-PA concurrent wrapper restore mismatch'}
$utf8=[Text.UTF8Encoding]::new($false,$true);$hasher=[Security.Cryptography.SHA256]::Create();try{$restoredSha=([BitConverter]::ToString($hasher.ComputeHash($utf8.GetBytes([string]$after)))).Replace('-','')}finally{$hasher.Dispose()}
if($restoredSha-cne$ExpectedPublic){throw 'HF6-PA concurrent restored wrapper hash mismatch'}
[pscustomobject]@{Result='REPLACED_REJECTED_AND_RESTORED';ReplacedSHA256=$replacedSha;RestoredSHA256=$restoredSha;SourceSHA256=$att.SourceSHA256}
'@).AddArgument($uid0002paV6Entry).AddArgument($uid0002paV6Gate).AddArgument($uid0002paV6ExpectedPublic).AddArgument($uid0002paV6ExpectedSource)
            $uid0002paV6Workers.Add([pscustomobject]@{PowerShell=$uid0002paV6PS;Handle=$uid0002paV6PS.BeginInvoke()})
        }
        $uid0002paV6Gate.Set()
        $uid0002paV6Results=[Collections.Generic.List[object]]::new()
        foreach($uid0002paV6Worker in $uid0002paV6Workers){foreach($uid0002paV6Value in $uid0002paV6Worker.PowerShell.EndInvoke($uid0002paV6Worker.Handle)){$uid0002paV6Results.Add($uid0002paV6Value)}}
        if($uid0002paV6Results.Count-ne8-or@($uid0002paV6Results|Where-Object{$_.Result-cne'REPLACED_REJECTED_AND_RESTORED'-or$_.RestoredSHA256-cne$uid0002paV6ExpectedPublic-or$_.SourceSHA256-cne$uid0002paV6ExpectedSource-or$_.ReplacedSHA256-ceq$uid0002paV6ExpectedPublic}).Count-ne0){throw 'HF6-PA concurrent wrapper result mismatch'}
        [pscustomobject]@{Workers=8L;Replacements=8L;RejectedHashes=8L;CompiledAuthorityAttestations=8L;Restored=8L}
    }finally{
        foreach($uid0002paV6Worker in $uid0002paV6Workers){$uid0002paV6Worker.PowerShell.Dispose()}
        $uid0002paV6Pool.Close();$uid0002paV6Pool.Dispose();$uid0002paV6Gate.Dispose()
    }
}

function Get-UID0002PAV6CanonicalRowDigest {
    [CmdletBinding()]param([Parameter(Mandatory=$true)][object[]]$Rows)
    if($Rows.Count-ne19){throw "HF6-PA canonical row count mismatch: $($Rows.Count)"}
    $uid0002paV6Builder=[Text.StringBuilder]::new()
    for($uid0002paV6Index=0;$uid0002paV6Index-lt$Rows.Count;$uid0002paV6Index++){
        $uid0002paV6Label=[string]$Rows[$uid0002paV6Index].Label;$uid0002paV6Result=[string]$Rows[$uid0002paV6Index].Result
        if([string]::IsNullOrEmpty($uid0002paV6Label)-or[string]::IsNullOrEmpty($uid0002paV6Result)-or$uid0002paV6Label.IndexOfAny([char[]]"|`r`n")-ge0-or$uid0002paV6Result.IndexOfAny([char[]]"|`r`n")-ge0){throw 'HF6-PA canonical row token mismatch'}
        foreach($uid0002paV6Character in ($uid0002paV6Label+$uid0002paV6Result).ToCharArray()){if([int]$uid0002paV6Character-gt127){throw 'HF6-PA canonical row is not ASCII'}}
        $null=$uid0002paV6Builder.Append(($uid0002paV6Index+1).ToString('D2',[Globalization.CultureInfo]::InvariantCulture)).Append('|').Append($uid0002paV6Label.Length.ToString('D4',[Globalization.CultureInfo]::InvariantCulture)).Append(':').Append($uid0002paV6Label).Append('|').Append($uid0002paV6Result.Length.ToString('D4',[Globalization.CultureInfo]::InvariantCulture)).Append(':').Append($uid0002paV6Result).Append("`n")
    }
    $uid0002paV6Canonical=$uid0002paV6Builder.ToString();$uid0002paV6Bytes=[Text.ASCIIEncoding]::new().GetBytes($uid0002paV6Canonical);$uid0002paV6Hasher=[Security.Cryptography.SHA256]::Create();try{$uid0002paV6Digest=([BitConverter]::ToString($uid0002paV6Hasher.ComputeHash($uid0002paV6Bytes))).Replace('-','')}finally{$uid0002paV6Hasher.Dispose()}
    [pscustomobject]@{Schema='UID0002PA-V6-ROWS-1';RowCount=[long]$Rows.Count;CanonicalLength=[long]$uid0002paV6Bytes.Length;SHA256=$uid0002paV6Digest}
}

function Invoke-UID0002PAV6BoundaryHostiles {
    [CmdletBinding()]param()
    $uid0002paV6Rows=[Collections.Generic.List[object]]::new();$uid0002paV6Att=[UID0002PAV6IsolatedHost]::InspectPackage();if($uid0002paV6Att.MutableHostFields-or$uid0002paV6Att.FenceCount-ne11){throw 'HF6-PA package attestation mismatch'}
    $uid0002paV6PublicEntry=(Microsoft.PowerShell.Core\Get-Command Invoke-UID0002PAClosedTransaction -CommandType Function).ScriptBlock;$uid0002paV6FixtureEntry=(Microsoft.PowerShell.Core\Get-Command Invoke-UID0002PAHostileStaticFixtures -CommandType Function).ScriptBlock;$uid0002paV6Probe=[UID0002PAV6IsolatedHost].GetMethod('ProtectedReceipt',[Reflection.BindingFlags]'NonPublic,Static');$uid0002paV6Run=[UID0002PAV6IsolatedHost].GetMethod('RunIsolated',[Reflection.BindingFlags]'NonPublic,Static');if($null-eq$uid0002paV6Probe-or$null-eq$uid0002paV6Run){throw 'HF6-PA protected/bypass probe unavailable'};$uid0002paV6Protected={ [string]$uid0002paV6Probe.Invoke($null,$null) }.GetNewClosure()
    $uid0002paV6Legacy=[UID0002PAV6IsolatedHost]::InvokeLegacyWitness();if($uid0002paV6Legacy.Outcome-cne'LEGACY_FORGED_ACCEPTED_WITNESSED'-or-not$uid0002paV6Legacy.ExactChildRetired){throw 'HF6-PA legacy witness mismatch'};$uid0002paV6Rows.Add([pscustomobject]@{Label='LegacyV5SharedCoordinatorWitness';Result='FORGED_ACCEPTED_WITNESSED';ChildPID=$uid0002paV6Legacy.ChildPID})
    $uid0002paV6Private=&$uid0002paV6FixtureEntry;if($uid0002paV6Private.Outcome-cne'PRIVATE_FIXTURES_PASSED'-or$uid0002paV6Private.ExternalTargetEffects-ne0-or-not$uid0002paV6Private.ExactChildRetired){throw 'HF6-PA bounded private-core result mismatch'};$uid0002paV6Rows.Add([pscustomobject]@{Label='BoundedPrivateProductionCore';Result='PASSED';ChildPID=$uid0002paV6Private.ChildPID})
    $uid0002paV6ProtectedBefore=&$uid0002paV6Protected;$uid0002paV6Controls=[UID0002PAV6IsolatedHost]::InvokeProductionTestControls();$uid0002paV6ProtectedAfter=&$uid0002paV6Protected;if($uid0002paV6ProtectedBefore-cne$uid0002paV6ProtectedAfter){throw 'HF6-PA production-test changed protected state'};$uid0002paV6Production=$uid0002paV6Controls.Accepted;$uid0002paV6FalseZero=$uid0002paV6Controls.FalseZero;$uid0002paV6Nonzero=$uid0002paV6Controls.NonzeroExternal
    if($uid0002paV6Production.Mode-cne'ProductionTest'-or$uid0002paV6Production.Outcome-cne'P1_VERIFIED'-or$uid0002paV6Production.SaveDispatches-ne1-or$uid0002paV6Production.TransportCalls-ne428-or$uid0002paV6Production.ExternalTargetEffects-ne0-or$uid0002paV6Production.McpEffects-ne0-or$uid0002paV6Production.IdaEffects-ne0-or$uid0002paV6Production.FileSystemEffects-ne1-or$uid0002paV6Production.ProcessEffects-ne0-or-not$uid0002paV6Production.ExactChildRetired){throw 'HF6-PA shared production-test reconciliation mismatch'};$uid0002paV6Rows.Add([pscustomobject]@{Label='GenuineSharedProductionGraphControl';Result='P1_VERIFIED_428_6_PRE_DISPATCH';ChildPID=$uid0002paV6Production.ChildPID;TransportCalls=428L;ExpectedLiveMcpCalls=428L;ExpectedLiveIdaWrites=6L})
    $uid0002paV6Before=&$uid0002paV6Protected;$uid0002paV6Arm=[UID0002PAV6IsolatedHost].GetMethod('ArmProductionFixture',[Reflection.BindingFlags]'Public,NonPublic,Static');$uid0002paV6Ticket=('UID0002PAV6ProductionFixtureAuthority' -as[type]);$uid0002paV6Label=$null;try{&$uid0002paV6PublicEntry 'reflected-arm'}catch{$uid0002paV6Label=$_.Exception.Message};if($null-ne$uid0002paV6Arm-or$null-ne$uid0002paV6Ticket-or$uid0002paV6Label-cne'CT6-PA public entry accepts exactly zero arguments'-or(& $uid0002paV6Protected)-cne$uid0002paV6Before){throw 'HF6-PA reflected arm/ticket hostile mismatch'};$uid0002paV6Rows.Add([pscustomobject]@{Label='ReflectedArmInvocationAndTicketConstruction';Result='ABSENT_AND_ZERO_PROTECTED_EFFECTS'})
    if($uid0002paV6FalseZero.Message-cne'TR6-PA production transport reconciliation mismatch'-or$uid0002paV6FalseZero.ChildPID-le0-or-not$uid0002paV6FalseZero.ExactChildRetired-or$uid0002paV6FalseZero.SaveDispatches-ne1-or$uid0002paV6FalseZero.TransportCalls-ne428-or$uid0002paV6FalseZero.McpEffects-ne0-or$uid0002paV6FalseZero.IdaEffects-ne0){throw 'HF6-PA false-zero rejection mismatch'};$uid0002paV6Rows.Add([pscustomobject]@{Label='DeterministicFalseZeroOperationReceipt';Result=$uid0002paV6FalseZero.Message;ChildPID=$uid0002paV6FalseZero.ChildPID})
    if($uid0002paV6Nonzero.Message-cne'TR6-PA deterministic operation reconciliation mismatch'-or$uid0002paV6Nonzero.ChildPID-le0-or-not$uid0002paV6Nonzero.ExactChildRetired-or$uid0002paV6Nonzero.SaveDispatches-ne1-or$uid0002paV6Nonzero.TransportCalls-ne428-or$uid0002paV6Nonzero.McpEffects-ne1-or$uid0002paV6Nonzero.IdaEffects-ne0){throw 'HF6-PA nonzero operation rejection mismatch'};$uid0002paV6Rows.Add([pscustomobject]@{Label='DeterministicNonzeroExternalDispatchReceipt';Result=$uid0002paV6Nonzero.Message;ChildPID=$uid0002paV6Nonzero.ChildPID})
    $uid0002paV6ProductionReplayMethod=[UID0002PAV6IsolatedHost].GetMethod('InvokeProductionReplayHostile',[Reflection.BindingFlags]'NonPublic,Static');if($null-eq$uid0002paV6ProductionReplayMethod-or-not[bool]$uid0002paV6ProductionReplayMethod.Invoke($null,[object[]]@($uid0002paV6Production))){throw 'HF6-PA production-test transcript replay mismatch'};$uid0002paV6Rows.Add([pscustomobject]@{Label='ProductionTestTranscriptReplay';Result='REJECTED_WITH_EXACT_IDENTITIES'})
    $uid0002paV6Concurrent=Invoke-UID0002PAV6ConcurrentWrapperHostile;$uid0002paV6Before=&$uid0002paV6Protected;$uid0002paV6Gate=[Threading.ManualResetEventSlim]::new($false);$uid0002paV6Pool=[RunspaceFactory]::CreateRunspacePool(1,8);$uid0002paV6Pool.Open();$uid0002paV6Workers=[Collections.Generic.List[object]]::new();try{1..8|ForEach-Object{$ps=[PowerShell]::Create();$ps.RunspacePool=$uid0002paV6Pool;$null=$ps.AddScript('param($Gate) if(-not$Gate.Wait(30000)){throw ''arm gate timeout''};[Runtime.Remoting.Messaging.CallContext]::SetData(''UID0002PA.V6.ReportOwnedProductionFixture'',''concurrent-arm'');try{$m=[UID0002PAV6IsolatedHost].GetMethod(''InvokeProduction'',[Reflection.BindingFlags]''Public,Static'');try{$null=$m.Invoke($null,[object[]]@(''divert''));$false}catch{$true}}finally{[Runtime.Remoting.Messaging.CallContext]::FreeNamedDataSlot(''UID0002PA.V6.ReportOwnedProductionFixture'')}').AddArgument($uid0002paV6Gate);$uid0002paV6Workers.Add([pscustomobject]@{PS=$ps;Handle=$ps.BeginInvoke()})};$uid0002paV6Gate.Set();$armed=0;foreach($w in $uid0002paV6Workers){foreach($v in $w.PS.EndInvoke($w.Handle)){if([bool]$v){$armed++}}};if($armed-ne8-or$uid0002paV6Concurrent.Restored-ne8-or(& $uid0002paV6Protected)-cne$uid0002paV6Before){throw 'HF6-PA concurrent arming hostile mismatch'}}finally{foreach($w in $uid0002paV6Workers){$w.PS.Dispose()};$uid0002paV6Pool.Close();$uid0002paV6Pool.Dispose();$uid0002paV6Gate.Dispose()};$uid0002paV6Rows.Add([pscustomobject]@{Label='ConcurrentWrapperReplacementAndArming';Result='8_OF_8_EACH_REJECTED_AND_RESTORED'})
    $uid0002paV6Before=&$uid0002paV6Protected;[Runtime.Remoting.Messaging.CallContext]::SetData('UID0002PA.V6.ReportOwnedProductionFixture','pre-arm');try{$uid0002paV6Label=$null;try{&$uid0002paV6PublicEntry 'pre-arm'}catch{$uid0002paV6Label=$_.Exception.Message}}finally{[Runtime.Remoting.Messaging.CallContext]::FreeNamedDataSlot('UID0002PA.V6.ReportOwnedProductionFixture')};if($uid0002paV6Label-cne'CT6-PA public entry accepts exactly zero arguments'-or(& $uid0002paV6Protected)-cne$uid0002paV6Before){throw 'HF6-PA pre-arm hostile mismatch'};$uid0002paV6Rows.Add([pscustomobject]@{Label='PreArmingUnchangedProductionEntry';Result='ZERO_ARGUMENT_REJECTED_ZERO_PROTECTED_EFFECTS'})
    $uid0002paV6Before=&$uid0002paV6Protected;$uid0002paV6Registry=[UID0002PAV6IsolatedHost].GetField('ConsumedTranscriptHashes',[Reflection.BindingFlags]'NonPublic,Static');$uid0002paV6Original=$uid0002paV6Registry.GetValue($null);$uid0002paV6ReplacementAttemptRejected=$false;try{$uid0002paV6Registry.SetValue($null,[Collections.Concurrent.ConcurrentDictionary[string,byte]]::new([StringComparer]::Ordinal));if(-not[object]::ReferenceEquals($uid0002paV6Registry.GetValue($null),$uid0002paV6Original)){$uid0002paV6Registry.SetValue($null,$uid0002paV6Original)}}catch{$uid0002paV6ReplacementAttemptRejected=$true};$added=$uid0002paV6Original.TryAdd('FORGED-PRODUCTION-TICKET',[byte]0);$removedValue=[byte]0;$removed=$uid0002paV6Original.TryRemove('FORGED-PRODUCTION-TICKET',[ref]$removedValue);$uid0002paV6Label=$null;try{&$uid0002paV6PublicEntry 'registry-diversion'}catch{$uid0002paV6Label=$_.Exception.Message};if(-not$added-or-not$removed-or$uid0002paV6Label-cne'CT6-PA public entry accepts exactly zero arguments'-or(& $uid0002paV6Protected)-cne$uid0002paV6Before){throw 'HF6-PA replay-registry separation mismatch'};$uid0002paV6Rows.Add([pscustomobject]@{Label='MutableRegistryReplacementAndConsumption';Result='REPLAY_ONLY_NOT_PRODUCTION_AUTHORITY';ReplacementRejected=$uid0002paV6ReplacementAttemptRejected})
    $uid0002paV6Before=&$uid0002paV6Protected;[Runtime.Remoting.Messaging.CallContext]::SetData('UID0002PA.V6.ReportOwnedProductionFixture',[pscustomobject]@{Scenario='P1'});try{$uid0002paV6Label=$null;try{&$uid0002paV6PublicEntry ([pscustomobject]@{Scenario='P1'})}catch{$uid0002paV6Label=$_.Exception.Message}}finally{[Runtime.Remoting.Messaging.CallContext]::FreeNamedDataSlot('UID0002PA.V6.ReportOwnedProductionFixture')};if($uid0002paV6Label-cne'CT6-PA public entry accepts exactly zero arguments'-or(& $uid0002paV6Protected)-cne$uid0002paV6Before){throw 'HF6-PA fixture diversion mismatch'};$uid0002paV6Rows.Add([pscustomobject]@{Label='FixtureDiversionAgainstUnchangedProductionEntry';Result='REJECTED_ZERO_PROTECTED_EFFECTS'})
    $uid0002paV6Before=&$uid0002paV6Protected;$uid0002paV6Label=$null;try{&$uid0002paV6FixtureEntry 'direct-private'}catch{$uid0002paV6Label=$_.Exception.Message};if($uid0002paV6Label-cne'CT6-PA private fixture entry accepts exactly zero arguments'-or(& $uid0002paV6Protected)-cne$uid0002paV6Before){throw 'HF6-PA direct private-fixture entry mismatch'};$uid0002paV6Rows.Add([pscustomobject]@{Label='DirectPrivateFixtureEntry';Result='EXTRA_AUTHORITY_REJECTED_ZERO_PROTECTED_EFFECTS'})
    $uid0002paV6Before=&$uid0002paV6Protected;$uid0002paV6Bypass=$null;try{$null=$uid0002paV6Run.Invoke($null,[object[]]@('Production','P1'))}catch{$uid0002paV6Bypass=$_.Exception;while($null-ne$uid0002paV6Bypass.InnerException){$uid0002paV6Bypass=$uid0002paV6Bypass.InnerException}};if($uid0002paV6Bypass.Message-cne'CT6-PA fixture diversion/live-child bypass rejected'-or(& $uid0002paV6Protected)-cne$uid0002paV6Before){throw 'HF6-PA live-child bypass mismatch'};$uid0002paV6Rows.Add([pscustomobject]@{Label='LiveChildBypass';Result=$uid0002paV6Bypass.Message})
    $uid0002paV6Reinit=$null;try{Initialize-UID0002PAV6IsolatedAuthority}catch{$uid0002paV6Reinit=$_.Exception.Message};if($uid0002paV6Reinit-cne'CP6-PA preloaded authoritative host type refused'){throw 'HF6-PA preloaded type rejection mismatch'};$uid0002paV6Rows.Add([pscustomobject]@{Label='PreloadedHostRejected';Result=$uid0002paV6Reinit})
    $uid0002paV6Raw=[UID0002PAV6IsolatedHost]::InvokeRawJsonHostiles();if($uid0002paV6Raw-ne3){throw 'HF6-PA raw duplicate-member hostile mismatch'};$uid0002paV6Rows.Add([pscustomobject]@{Label='RawDuplicateMembersBeforeDeserialize';Result='3_OF_3_REJECTED'})
    $uid0002paV6Replay=[UID0002PAV6IsolatedHost]::InvokeReplayHostiles();if($uid0002paV6Replay.Rejections-ne2-or-not$uid0002paV6Replay.ExactChildRetired){throw 'HF6-PA replay transition mismatch'};$uid0002paV6Rows.Add([pscustomobject]@{Label='TranscriptOneTimeConsumption';Result='SECOND_AND_DELAYED_REPLAY_REJECTED';ChildPID=$uid0002paV6Replay.ChildPID})
    $uid0002paV6ZeroChildren=@($uid0002paV6Legacy,$uid0002paV6Private,$uid0002paV6Replay);if(@($uid0002paV6ZeroChildren|Where-Object{$_.SaveDispatches-ne0-or$_.TransportCalls-ne0-or$_.ExternalTargetEffects-ne0-or$_.McpEffects-ne0-or$_.IdaEffects-ne0-or$_.FileSystemEffects-ne0-or$_.ProcessEffects-ne0}).Count-ne0-or$uid0002paV6ProtectedBefore-cne$uid0002paV6ProtectedAfter){throw 'HF6-PA independent protected-effect receipt mismatch'};$uid0002paV6CleanupHostile=[UID0002PAV6IsolatedHost]::InvokeCleanupBoundaryHostile();if($uid0002paV6CleanupHostile.NewRootsObserved-ne1-or$uid0002paV6CleanupHostile.NewRootsRemoved-ne1-or$uid0002paV6CleanupHostile.NewRootsAbsentAfter-ne1-or-not$uid0002paV6CleanupHostile.NewGenerationClosed-or-not$uid0002paV6CleanupHostile.BaselineReproduced-or$uid0002paV6CleanupHostile.AfterPrefixCount-ne0){throw 'HF6-PA cleanup failure-path hostile mismatch'};$uid0002paV6Rows.Add([pscustomobject]@{Label='IndependentProtectedEffectReadbacks';Result='CANONICAL_SIDECARS_LISTENER_UNCHANGED_PREFIX_BASELINE_REPRODUCED_FAILURE_CLEANUP_1_OF_1'})
    $uid0002paV6AllChildren=@($uid0002paV6Legacy,$uid0002paV6Private,$uid0002paV6Production,$uid0002paV6FalseZero,$uid0002paV6Nonzero,$uid0002paV6Replay);$uid0002paV6MainProcesses=@($uid0002paV6Legacy.ProcessReceipt,$uid0002paV6Private.ProcessReceipt,$uid0002paV6Production.ProcessReceipt,$uid0002paV6FalseZero.ProcessReceipt,$uid0002paV6Nonzero.ProcessReceipt,$uid0002paV6Replay.ProcessReceipt);if(@($uid0002paV6AllChildren|Where-Object{-not$_.ExactChildRetired}).Count-ne0-or@($uid0002paV6MainProcesses|Where-Object{$null-eq$_-or-not$_.CompletionPortBound-or-not$_.GenerationCensusComplete-or-not$_.WatcherTerminal-or-not$_.WatcherSucceeded-or-not$_.InputDeliveryTerminal-or-not$_.JobAssigned-or-not$_.ImmediateGenerationRetired-or-not$_.JobEmpty-or-not$_.DrainsTerminal-or-not$_.DrainsSucceeded-or$_.TotalProcesses-lt1-or$_.ActiveAfterContainment-ne0-or$_.SameGenerationsAlive-ne0-or$_.OwnedNetworkConnectionsAfter-ne0}).Count-ne0){throw 'HF6-PA contained transaction child retirement mismatch'};$uid0002paV6CleanupReceipts=@($uid0002paV6Legacy.CleanupReceipt,$uid0002paV6Private.CleanupReceipt,$uid0002paV6Production.CleanupReceipt,$uid0002paV6FalseZero.CleanupReceipt,$uid0002paV6Nonzero.CleanupReceipt,$uid0002paV6Replay.CleanupReceipt);if(@($uid0002paV6CleanupReceipts|Where-Object{$null-eq$_-or$_.HistoricalInventoryCount-ne14-or-not$_.HistoricalClosed-or-not$_.NewGenerationClosed-or-not$_.BaselineReproduced-or$_.HistoricalRemoved-ne$_.HistoricalPresentBefore-or$_.HistoricalAbsentAfter-ne14-or$_.NewRootsRemoved-ne$_.NewRootsObserved-or$_.NewRootsAbsentAfter-ne$_.NewRootsObserved-or$_.BaselinePrefixCount-ne$_.AfterPrefixCount-or$_.BaselinePrefixSHA256-cne$_.AfterPrefixSHA256-or$_.AfterPrefixCount-ne0}).Count-ne0){throw 'HF6-PA report-owned temp cleanup receipt mismatch'};$uid0002paV6HistoricalRootsRemoved=[long](($uid0002paV6CleanupReceipts|Measure-Object HistoricalRemoved -Sum).Sum);$uid0002paV6NewRootsRemoved=[long](($uid0002paV6CleanupReceipts|Measure-Object NewRootsRemoved -Sum).Sum);$uid0002paV6ProcessHostiles=[UID0002PAV6IsolatedHost]::InvokeProcessBoundaryHostiles();if($uid0002paV6ProcessHostiles.Passed-ne6-or$uid0002paV6ProcessHostiles.Failed-ne0-or@($uid0002paV6ProcessHostiles.Cases|Where-Object{-not$_.CompletionPortBound-or-not$_.GenerationCensusComplete-or-not$_.WatcherTerminal-or-not$_.WatcherSucceeded-or-not$_.InputDeliveryTerminal-or-not$_.JobAssigned-or-not$_.ImmediateGenerationRetired-or-not$_.JobEmpty-or-not$_.DrainsTerminal-or$_.ActiveAfterContainment-ne0-or$_.SameGenerationsAlive-ne0-or$_.OwnedNetworkConnectionsAfter-ne0}).Count-ne0){throw 'HF6-PA process hostile containment mismatch'};$uid0002paV6Rows.Add([pscustomobject]@{Label='ExactChildGenerationRetirement';Result='6_MAIN_PLUS_6_HOSTILES_CONTAINED_DRAINS_BOUNDED';ChildPIDs=@($uid0002paV6AllChildren|ForEach-Object{$_.ChildPID});HostileChildPIDs=@($uid0002paV6ProcessHostiles.Cases|ForEach-Object{$_.ChildPID});ProcessHostileSHA256=$uid0002paV6ProcessHostiles.CanonicalSHA256})
    $uid0002paV6EntryNow=(Microsoft.PowerShell.Core\Get-Command Invoke-UID0002PAClosedTransaction -CommandType Function).ScriptBlock;$uid0002paV6Utf8=[Text.UTF8Encoding]::new($false,$true);$uid0002paV6Hasher=[Security.Cryptography.SHA256]::Create();try{$uid0002paV6EntrySha=([BitConverter]::ToString($uid0002paV6Hasher.ComputeHash($uid0002paV6Utf8.GetBytes([string]$uid0002paV6EntryNow)))).Replace('-','')}finally{$uid0002paV6Hasher.Dispose()};$uid0002paV6Post=[UID0002PAV6IsolatedHost]::InspectPackage();if($uid0002paV6EntrySha-cne$uid0002paV6Att.PublicEntrySHA256-or$uid0002paV6Post.SourceSHA256-cne$uid0002paV6Att.SourceSHA256-or$uid0002paV6Post.ApiSHA256-cne$uid0002paV6Att.ApiSHA256-or$uid0002paV6Post.MethodManifestSHA256-cne$uid0002paV6Att.MethodManifestSHA256-or$uid0002paV6Post.AssemblySHA256-cne$uid0002paV6Att.AssemblySHA256-or$uid0002paV6Post.MutableHostFields){throw 'HF6-PA final package identity mismatch'};$uid0002paV6Rows.Add([pscustomobject]@{Label='FinalReportPayloadWrapperCompiledIdentity';Result='EXACT_AND_STABLE'})
    if($uid0002paV6Rows.Count-ne19){throw "HF6-PA exact boundary row count mismatch: $($uid0002paV6Rows.Count)"};$uid0002paV6RowDigest=Get-UID0002PAV6CanonicalRowDigest -Rows @($uid0002paV6Rows)
    [pscustomobject]@{Passed=19L;Failed=0L;PositiveControls=4L;AcceptedLiveProductionEntries=0L;AcceptedProductionBoundaryTests=1L;RejectedProductionBoundaryTests=2L;RejectedOuterBoundaryCases=9L;SaveDispatches=[long]($uid0002paV6Production.SaveDispatches+$uid0002paV6FalseZero.SaveDispatches+$uid0002paV6Nonzero.SaveDispatches);TransportCalls=[long]($uid0002paV6Production.TransportCalls+$uid0002paV6FalseZero.TransportCalls+$uid0002paV6Nonzero.TransportCalls);ExpectedFixtureTargetEffects=3L;ExternalTargetEffects=0L;ProtectedFileSystemEffects=0L;McpEffects=0L;IdaEffects=0L;UnexpectedProcessEffects=0L;ExpectedLiveMcpCallsPerAcceptedGraph=428L;ExpectedLiveIdaWritesPerAcceptedGraph=6L;ExpectedTransactionChildren=6L;RetiredTransactionChildren=6L;ExpectedProcessHostileChildren=6L;RetiredProcessHostileChildren=6L;ExpectedIsolatedChildren=12L;RetiredIsolatedChildren=12L;ProtectedReceiptSHA256=$uid0002paV6ProtectedAfter;PayloadSHA256=$uid0002paV6Att.PayloadSHA256;SourceSHA256=$uid0002paV6Att.SourceSHA256;ApiSHA256=$uid0002paV6Att.ApiSHA256;MethodManifestSHA256=$uid0002paV6Att.MethodManifestSHA256;AssemblySHA256=$uid0002paV6Att.AssemblySHA256;PublicEntrySHA256=$uid0002paV6Att.PublicEntrySHA256;FixtureEntrySHA256=$uid0002paV6Att.FixtureEntrySHA256;RowDigestSchema=$uid0002paV6RowDigest.Schema;RowCanonicalLength=$uid0002paV6RowDigest.CanonicalLength;RowDigestSHA256=$uid0002paV6RowDigest.SHA256;HistoricalRootsRemovedThisRun=$uid0002paV6HistoricalRootsRemoved;NewGenerationRootsRemoved=$uid0002paV6NewRootsRemoved;PostRunPrefixCount=0L;PostRunNewResidue=0L;CleanupReceipts=$uid0002paV6CleanupReceipts;CleanupFailureHostile=$uid0002paV6CleanupHostile;ProcessBoundaryHostiles=$uid0002paV6ProcessHostiles;ProductionTestReceipt=$uid0002paV6Production;FalseZeroRejection=$uid0002paV6FalseZero;NonzeroRejection=$uid0002paV6Nonzero;LegacyWitness=$uid0002paV6Legacy;PrivateFixtures=$uid0002paV6Private;ReplayReceipt=$uid0002paV6Replay;Rows=@($uid0002paV6Rows)}
}
~~~

## Removed Block R025

- SHA256: `97704C2807CF109365507807CE3B72B869D5484218B3EF97A639B9A17BC42E9B`
- Language: `powershell`
- Bytes: `29914`
- First recovered timestamp: `2026-08-09T15:30:56.412Z`
- Session provenance: rollout-2026-08-08T17-46-23-019fe357-64cc-7ca3-ad27-c9c336afc6af.jsonl line 5673 (2026-08-09T15:30:56.412Z); rollout-2026-08-08T17-46-23-019fe357-64cc-7ca3-ad27-c9c336afc6af.jsonl line 5674 (2026-08-09T15:30:56.800Z)

~~~powershell
function New-UID0002PAToolRequest {
    param(
        [Parameter(Mandatory=$true)][string]$Id,
        [Parameter(Mandatory=$true)][string]$Name,
        [Parameter(Mandatory=$true)]$Arguments)

    $request = [ordered]@{
        jsonrpc='2.0'; id=$Id; method='tools/call'
        params=[ordered]@{ name=$Name; arguments=$Arguments }
    }
    $json = $request | ConvertTo-Json -Depth 30 -Compress
    $parsed = $json | ConvertFrom-Json -ErrorAction Stop
    if ([string]$parsed.params.name -cne $Name -or
        $json -match '__[A-Z0-9_]+__|<[^>]+>') { throw "RQ-PA unresolved request $Id" }
    return $json
}

function New-UID0002PAReadbackCatalog {
    param(
        [Parameter(Mandatory=$true)]$RoleBinding,
        [Parameter(Mandatory=$true)]
        [ValidateSet('Pre','AfterI01','AfterI02','AfterI03','AfterI04','AfterI05','Final','P0Verifier','S1Verifier','RollbackVerifier')]
        [string]$Phase)

    $db = [string]$RoleBinding.Database
    if ([string]::IsNullOrWhiteSpace($db)) { throw 'RQ-PA blank returned database' }
    $prefix = "uid0002pa-$Phase"
    $catalog = [ordered]@{}
    $catalog.IdbList = New-UID0002PAToolRequest "$prefix-list" 'idb_list' @{}
    $catalog.Attestation = New-UID0002PARuntimeAttestationRequest "$prefix-attest" $RoleBinding
    $catalog.Analyze = New-UID0002PAToolRequest "$prefix-analyze" 'analyze_function' ([ordered]@{
        database=$db; addr='0x00494130'; include_asm=$false
    })
    $catalog.Frame = New-UID0002PAToolRequest "$prefix-frame" 'stack_frame' ([ordered]@{
        database=$db; addrs='0x00494130'
    })
    $catalog.Xrefs = New-UID0002PAToolRequest "$prefix-xrefs" 'xref_query' ([ordered]@{
        database=$db; queries=[ordered]@{
            addr='0x00494130'; direction='to'; xref_type='code'; offset=0; count=200
            include_fn=$true; dedup=$true; sort_by='addr'; descending=$false
        }
    })
    $catalog.Callees = New-UID0002PAToolRequest "$prefix-callees" 'callees' ([ordered]@{
        database=$db; addrs='0x00494130'; limit=200
    })
    $catalog.Bytes = New-UID0002PAToolRequest "$prefix-bytes" 'get_bytes' ([ordered]@{
        database=$db; regions=@(
            [ordered]@{addr='0x00494130';size=166},
            [ordered]@{addr='0x00494126';size=10},
            [ordered]@{addr='0x004941d6';size=10}
        )
    })
    $catalog.Items = New-UID0002PAToolRequest "$prefix-items" 'inspect_items' ([ordered]@{
        database=$db
        addrs=@('0x00494126','0x00494130','0x00494157','0x00494166','0x00494176','0x004941d5','0x004941d6','0x004941e0')
    })
    $catalog.Comments = New-UID0002PAToolRequest "$prefix-comments" 'get_comments' ([ordered]@{
        database=$db; addrs=@('0x00494130','0x00494157','0x00494166','0x00494176')
    })
    $catalog.Collision = New-UID0002PAToolRequest "$prefix-collision" 'entity_query' ([ordered]@{
        database=$db; queries=@(
            [ordered]@{kind='functions';regex='^ServerSelectDirectory__ReleaseOwnedBuffers$';offset=0;count=200;sort_by='addr';descending=$false;fields=@('addr','name','size')},
            [ordered]@{kind='names';regex='^ServerSelectDirectory__ReleaseOwnedBuffers$';offset=0;count=200;sort_by='addr';descending=$false;fields=@('addr','name')}
        )
    })
    $catalog.CandidateTypes = New-UID0002PAToolRequest "$prefix-candidate-types" 'type_inspect' ([ordered]@{
        database=$db; queries=@(
            [ordered]@{name='ConfigEntry';include_members=$true;max_members=100},
            [ordered]@{name='ConfigEntryBlock';include_members=$true;max_members=100},
            [ordered]@{name='ServerSelectEntry';include_members=$true;max_members=100},
            [ordered]@{name='ServerSelectDirectory';include_members=$true;max_members=100}
        )
    })
    $catalog.CandidateTypeIndex = New-UID0002PAToolRequest "$prefix-candidate-index" 'type_query' ([ordered]@{
        database=$db; queries=@(
            [ordered]@{filter='ServerSelectEntry';kind='udt';offset=0;count=200;sort_by='name';descending=$false;include_decl=$true;include_members=$true;max_members=100;include_relationships=$true},
            [ordered]@{filter='ServerSelectDirectory';kind='udt';offset=0;count=200;sort_by='name';descending=$false;include_decl=$true;include_members=$true;max_members=100;include_relationships=$true}
        )
    })
    $catalog.Config = New-UID0002PAToolRequest "$prefix-config" 'type_inspect' ([ordered]@{
        database=$db; queries=[ordered]@{name='Config';include_members=$true;max_members=100}
    })
    foreach ($entry in $catalog.GetEnumerator()) {
        $parsed = $entry.Value | ConvertFrom-Json -ErrorAction Stop
        if ($entry.Key -notin @('IdbList','Attestation') -and
            [string]$parsed.params.arguments.database -cne $db) {
            throw "RQ-PA $($entry.Key) lost returned database"
        }
    }
    return $catalog
}

function Get-UID0002PASha256ForByteText {
    param([Parameter(Mandatory=$true)][string]$Text)
    $bytes=Get-UID0002PABytesFromText $Text
    $sha = [Security.Cryptography.SHA256]::Create()
    try { return ([BitConverter]::ToString($sha.ComputeHash([byte[]]$bytes))).Replace('-','') }
    finally { $sha.Dispose() }
}

function Get-UID0002PABytesFromText {
    param([Parameter(Mandatory=$true)][string]$Text)
    return @($Text -split '\s+' | Where-Object { $_ } | ForEach-Object {
        if ($_ -notmatch '^0x[0-9a-fA-F]{1,2}$') { throw "RQ-PA invalid byte token $_" }
        [Convert]::ToByte($_.Substring(2),16)
    })
}

function Assert-UID0002PAByteRows {
    param([Parameter(Mandatory=$true)]$Rows)
    $expected=@(
        [pscustomobject]@{Address=0x00494130;Size=166;SHA='2D53FB76ED15C7F4CD368E05DB122B074B92B32FCEC39A260D38F769859CD42B'},
        [pscustomobject]@{Address=0x00494126;Size=10;SHA='22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045'},
        [pscustomobject]@{Address=0x004941d6;Size=10;SHA='22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045'}
    )
    $actual=@($Rows)
    if($actual.Count -ne $expected.Count){throw 'RQ-PA byte result count mismatch'}
    for($i=0;$i -lt $expected.Count;$i++){
        $row=$actual[$i]
        foreach($property in 'addr','size','data','error'){
            if(-not $row.PSObject.Properties[$property]){throw "RQ-PA byte row missing $property at index $i"}
        }
        $address=[Convert]::ToUInt64(([string]$row.addr -replace '^0x',''),16)
        $data=@(Get-UID0002PABytesFromText ([string]$row.data))
        if($address -ne $expected[$i].Address -or [int]$row.size -ne $expected[$i].Size -or
            $data.Count -ne $expected[$i].Size -or $null -ne $row.error){
            throw "RQ-PA byte row association mismatch at index $i"
        }
    }
    for($i=0;$i -lt $expected.Count;$i++){
        if((Get-UID0002PASha256ForByteText ([string]$actual[$i].data)) -cne $expected[$i].SHA){
            throw "RQ-PA byte row SHA mismatch at index $i"
        }
    }
}

function Assert-UID0002PACommentRows {
    param(
        [Parameter(Mandatory=$true)]$Rows,
        [Parameter(Mandatory=$true)][string]$FunctionText,
        [Parameter(Mandatory=$true)]$AddressTexts)
    $expectedAddresses=@(0x00494130,0x00494157,0x00494166,0x00494176)
    $actual=@($Rows)
    if($actual.Count -ne 4){throw 'RQ-PA comment row count mismatch'}
    for($i=0;$i -lt 4;$i++){
        foreach($property in 'addr','regular','repeatable','function_regular','function_repeatable'){
            if(-not $actual[$i].PSObject.Properties[$property]){throw "RQ-PA comment row missing $property at index $i"}
        }
        $address=[Convert]::ToUInt64(([string]$actual[$i].addr -replace '^0x',''),16)
        if($address -ne $expectedAddresses[$i] -or [string]$actual[$i].repeatable -cne '' -or
            [string]$actual[$i].function_repeatable -cne ''){throw "RQ-PA comment address/channel mismatch at index $i"}
        if($i -eq 0){
            if([string]$actual[$i].regular -cne '' -or [string]$actual[$i].function_regular -cne $FunctionText){
                throw 'RQ-PA function comment channel mismatch'
            }
        } elseif([string]$actual[$i].regular -cne [string]$AddressTexts[$i-1] -or
            [string]$actual[$i].function_regular -cne ''){
            throw "RQ-PA address comment channel mismatch at index $i"
        }
    }
}

function Assert-UID0002PACandidateTypeIndex {
    param([Parameter(Mandatory=$true)]$Pages,[Parameter(Mandatory=$true)][bool]$PostTypes)
    $actual=@($Pages)
    $expectedNames=@('ServerSelectEntry','ServerSelectDirectory')
    if($actual.Count -ne 2){throw 'RQ-PA candidate type-index page count mismatch'}
    for($i=0;$i -lt 2;$i++){
        foreach($property in 'total','next_offset','error','data'){
            if(-not $actual[$i].PSObject.Properties[$property]){throw "RQ-PA candidate type-index page missing $property at index $i"}
        }
        $expectedTotal=if($PostTypes){1}else{0}
        if([int]$actual[$i].total -ne $expectedTotal -or $null -ne $actual[$i].next_offset -or
            $null -ne $actual[$i].error -or @($actual[$i].data).Count -ne $expectedTotal){
            throw "RQ-PA candidate type-index page mismatch at index $i"
        }
        if($PostTypes -and [string]$actual[$i].data[0].name -cne $expectedNames[$i]){
            throw "RQ-PA candidate type-index association mismatch at index $i"
        }
    }
}

function Assert-UID0002PAExactJson {
    param([Parameter(Mandatory=$true)]$Actual,[Parameter(Mandatory=$true)]$Expected,[Parameter(Mandatory=$true)][string]$Label)
    $actualJson = $Actual | ConvertTo-Json -Depth 30 -Compress
    $expectedJson = $Expected | ConvertTo-Json -Depth 30 -Compress
    if ($actualJson -cne $expectedJson) { throw "RQ-PA exact result mismatch: $Label" }
}

function Get-UID0002PAConfigOracle {
    $names = '_configPrefixToStartupChannel|m_startupChannel|_configStartupChannelToOptionCluster|m_soundEffectsEnabled|_configToOptionCluster|m_mapEffectEnabled|m_sayWithEnter|m_doubleClickEnabled|m_autoMoveEnabled|m_balloonFillEnabled|m_staticObjectTransparencyEnabled|m_shadowEnabled|m_showUserName|m_selfLookTopButtonSelected|m_selfLookBottomButtonSelected|m_targetSelectionSuppressed|m_tabVSwap|m_showDamage|m_groupBarEnabled|m_carnageColorEnabled|_alignment_28DE67|m_graphicsSetting|m_orbTargetShare|m_f1Swap|m_whisperEnabled|m_shoutEnabled|m_adviceEnabled|m_hearSnoreMode|m_magicEffectsEnabled|m_weatherEffectsEnabled|m_fixedMovementEnabled|m_mapMovementStatusOption|m_seeThroughEnabled|m_hearEmotions|m_chatVisibleLineCount|m_chatHandleModeIndex|m_secondaryChatEnabled|m_chatHandleLeftToggle|m_chatColorPairs|m_clickMoveEnabled|m_clickLookEnabled|m_systemMessageHeight|m_powerDialogThresholdDefaults|m_profileTextSlots|m_legacyShortcutText|m_compactShortcutRecords|m_macroHotkeys|_configAfterMacroHotkeys|m_blockListenNames|m_musicSourceMode|_configTail'.Split('|')
    $offsets = '0x0|0x28d9e0|0x28db10|0x28de48|0x28de49|0x28de58|0x28de59|0x28de5a|0x28de5b|0x28de5c|0x28de5d|0x28de5e|0x28de5f|0x28de60|0x28de61|0x28de62|0x28de63|0x28de64|0x28de65|0x28de66|0x28de67|0x28de68|0x28de6c|0x28de6d|0x28de6e|0x28de6f|0x28de70|0x28de71|0x28de72|0x28de73|0x28de74|0x28de75|0x28de76|0x28de77|0x28de78|0x28de7c|0x28de80|0x28de81|0x28de82|0x28de8e|0x28de8f|0x28de90|0x28de94|0x28de9c|0x28e89c|0x28f29c|0x28f2ec|0x2911dc|0x2918fc|0x291908|0x29190c'.Split('|')
    $sizes = '2677216|304|824|1|15|1|1|1|1|1|1|1|1|1|1|1|1|1|1|1|1|4|1|1|1|1|1|1|1|1|1|1|1|1|4|4|1|1|12|1|1|4|8|2560|2560|80|7920|1824|12|4|12'.Split('|')
    $types = 'unsigned __int8[2677216]|ConfigStartupChannelData|unsigned __int8[824]|unsigned __int8|unsigned __int8[15]|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned int|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned __int8|unsigned int|unsigned int|unsigned __int8|unsigned __int8|ChatColorPair[6]|unsigned __int8|unsigned __int8|unsigned int|unsigned __int16[4]|wchar_t[10][128]|wchar_t[10][128]|CompactShortcutRecord[20]|MacroHotkeyRecord[30]|unsigned __int8[1824]|SimpleUStringVector|unsigned int|unsigned __int8[12]'.Split('|')
    if ($names.Count -ne 51 -or $offsets.Count -ne 51 -or $sizes.Count -ne 51 -or $types.Count -ne 51) {
        throw 'RQ-PA Config oracle cardinality is not 51'
    }
    $rows = @()
    for ($i=0; $i -lt 51; $i++) {
        $rows += [pscustomobject][ordered]@{name=$names[$i];offset=$offsets[$i];size=[int]$sizes[$i];type=$types[$i]}
    }
    return $rows
}

function Assert-UID0002PAReadbackCatalog {
    param(
        [Parameter(Mandatory=$true)]$Requests,
        [Parameter(Mandatory=$true)]$Responses,
        [Parameter(Mandatory=$true)]$RoleBinding,
        [Parameter(Mandatory=$true)]$AttestationState,
        [Parameter(Mandatory=$true)]
        [ValidateSet('Pre','AfterI01','AfterI02','AfterI03','AfterI04','AfterI05','Final','P0Verifier','S1Verifier','RollbackVerifier')]
        [string]$Phase)

    $required = 'IdbList','Attestation','Analyze','Frame','Xrefs','Callees','Bytes','Items','Comments','Collision','CandidateTypes','CandidateTypeIndex','Config'
    if ((@($Requests.Keys | Sort-Object) -join '|') -cne (@($required | Sort-Object) -join '|') -or
        (@($Responses.Keys | Sort-Object) -join '|') -cne (@($required | Sort-Object) -join '|')) {
        throw "RQ-PA $Phase request/response catalog keys mismatch"
    }
    $expectedRequests=New-UID0002PAReadbackCatalog -RoleBinding $RoleBinding -Phase $Phase
    foreach($key in $required){
        $actualRequest=Get-UID0002PARequestIdentity ([string]$Requests[$key]) "RQ-PA $Phase $key actual"
        $expectedRequest=Get-UID0002PARequestIdentity ([string]$expectedRequests[$key]) "RQ-PA $Phase $key expected"
        if($actualRequest.SHA256 -cne $expectedRequest.SHA256 -or
            (($actualRequest.Parsed|ConvertTo-Json -Depth 30 -Compress) -cne ($expectedRequest.Parsed|ConvertTo-Json -Depth 30 -Compress))){
            throw "RQ-PA $Phase $key literal request mismatch"
        }
    }
    $runtime=Assert-UID0002PARuntimeAttestation -Envelope $Responses.Attestation -AttestationRequestJson $Requests.Attestation -ListEnvelope $Responses.IdbList -ListRequestJson $Requests.IdbList -RoleBinding $RoleBinding -State $AttestationState
    $list = Get-UID0002PAStructuredContent -Envelope $Responses.IdbList -RequestJson $Requests.IdbList -Label "$Phase idb_list"
    $activeCanonical = @($list.sessions | Where-Object {
        $_.is_active -eq $true -and
        [System.IO.Path]::GetFullPath([string]$_.input_path) -ieq [string]$RoleBinding.CanonicalPath
    })
    if ($activeCanonical.Count -ne 1 -or [string]$activeCanonical[0].session_id -cne [string]$RoleBinding.Database -or
        [int]$activeCanonical[0].worker_pid -ne [int]$RoleBinding.CorroboratedRedirectorPid) {
        throw "RQ-PA $Phase exact active returned-session mismatch"
    }

    $postTypes = $Phase -in @('AfterI01','AfterI02','AfterI03','AfterI04','AfterI05','Final','S1Verifier')
    $postName = $Phase -in @('AfterI02','AfterI03','AfterI04','AfterI05','Final','S1Verifier')
    $postPrototype = $Phase -in @('AfterI03','AfterI04','AfterI05','Final','S1Verifier')
    $postFunctionComment = $Phase -in @('AfterI04','AfterI05','Final','S1Verifier')
    $postAddressComments = $Phase -in @('AfterI05','Final','S1Verifier')
    $expectedName = if ($postName) {'ServerSelectDirectory__ReleaseOwnedBuffers'} else {'sub_494130'}
    $expectedPrototype = if ($postPrototype) {
        'void __thiscall ServerSelectDirectory__ReleaseOwnedBuffers(ServerSelectDirectory *this)'
    } else { 'void __thiscall(int this)' }

    $analyze = Get-UID0002PAStructuredContent -Envelope $Responses.Analyze -RequestJson $Requests.Analyze -Label "$Phase analyze"
    if ([string]$analyze.addr -cne '0x494130' -or $null -ne $analyze.error -or
        [string]$analyze.name -cne $expectedName -or [string]$analyze.prototype -cne $expectedPrototype -or
        [int]$analyze.size -ne 166 -or @($analyze.strings).Count -ne 0 -or @($analyze.constants).Count -ne 0 -or
        (@($analyze.callees) -join '|') -cne 'j_j_j___free_base' -or
        (@($analyze.callers) -join '|') -cne 'sub_48E780|sub_4926A0|sub_493F90|sub_494020' -or
        [int]$analyze.basic_blocks.count -ne 13 -or [int]$analyze.basic_blocks.cyclomatic_complexity -ne 5) {
        throw "RQ-PA $Phase analyze protection mismatch"
    }

    $frame = Get-UID0002PAStructuredContent -Envelope $Responses.Frame -RequestJson $Requests.Frame -Label "$Phase frame"
    $expectedFrame = [ordered]@{result=@([ordered]@{addr='0x00494130';vars=@([ordered]@{name='__return_address';offset='0x4';size='0x4';type='_UNKNOWN *'})})}
    Assert-UID0002PAExactJson $frame $expectedFrame "$Phase frame"

    $xrefs = Get-UID0002PAStructuredContent -Envelope $Responses.Xrefs -RequestJson $Requests.Xrefs -Label "$Phase xrefs"
    $xr = @($xrefs.result)
    if ($xr.Count -ne 1 -or [string]$xr[0].target -cne '0x00494130' -or [string]$xr[0].resolved_addr -cne '0x494130' -or
        [string]$xr[0].direction -cne 'to' -or [string]$xr[0].xref_type -cne 'code' -or
        $null -ne $xr[0].next_offset -or [int]$xr[0].total -ne 5 -or $null -ne $xr[0].error) {
        throw "RQ-PA $Phase xref page mismatch"
    }
    $xrefRows = @($xr[0].data | ForEach-Object {
        "$($_.addr)|$($_.from)|$($_.to)|$($_.type)|$($_.fn.addr)|$($_.fn.name)|$($_.fn.size)"
    })
    $expectedXrefs = @(
        '0x48e824|0x48e824|0x494130|code|0x48e780|sub_48E780|0xda',
        '0x4938d6|0x4938d6|0x494130|code|0x4926a0|sub_4926A0|0x1789',
        '0x493e01|0x493e01|0x494130|code|0x4926a0|sub_4926A0|0x1789',
        '0x493fb5|0x493fb5|0x494130|code|0x493f90|sub_493F90|0x49',
        '0x4940c8|0x4940c8|0x494130|code|0x494020|sub_494020|0x106'
    )
    if (($xrefRows -join '|') -cne ($expectedXrefs -join '|')) { throw "RQ-PA $Phase exact xref rows mismatch" }

    $callees = Get-UID0002PAStructuredContent -Envelope $Responses.Callees -RequestJson $Requests.Callees -Label "$Phase callees"
    $expectedCallees = [ordered]@{result=@([ordered]@{addr='0x00494130';callees=@([ordered]@{addr='0x5c7799';name='j_j_j___free_base';type='internal'});more=$false})}
    Assert-UID0002PAExactJson $callees $expectedCallees "$Phase callees"

    $bytes = Get-UID0002PAStructuredContent -Envelope $Responses.Bytes -RequestJson $Requests.Bytes -Label "$Phase bytes"
    Assert-UID0002PAByteRows @($bytes.result)

    $items = Get-UID0002PAStructuredContent -Envelope $Responses.Items -RequestJson $Requests.Items -Label "$Phase items"
    $expectedItems = @(
        "0x00494126|0x494126|0x494130|10|||False|True",
        "0x00494130|0x494130|0x494131|1|$expectedName|$expectedPrototype|True|False",
        '0x00494157|0x494157|0x494158|1|||True|False',
        '0x00494166|0x494166|0x494167|1|||True|False',
        '0x00494176|0x494176|0x494177|1|||True|False',
        '0x004941d5|0x4941d5|0x4941d6|1|||True|False',
        '0x004941d6|0x4941d6|0x4941e0|10|||False|True',
        '0x004941e0|0x4941e0|0x4941e1|1|sub_4941E0|HRESULT __thiscall(LPVOID *ppv, LPCCH lpMultiByteStr, IUnknown *, DWORD dwClsContext)|True|False'
    )
    $actualItems = @($items.result | ForEach-Object {
        "$($_.addr)|$($_.head)|$($_.end)|$($_.size)|$($_.name)|$($_.type)|$($_.is_code)|$($_.is_data)"
    })
    if (($actualItems -join '|') -cne ($expectedItems -join '|')) { throw "RQ-PA $Phase exact item rows mismatch" }

    $comments = Get-UID0002PAStructuredContent -Envelope $Responses.Comments -RequestJson $Requests.Comments -Label "$Phase comments"
    $functionText = if ($postFunctionComment) {
        'ServerSelectDirectory::ReleaseOwnedBuffers; frees name, description, and agreement text for active entries, then resets entryCount and version. The null-receiver branch still faults on the final resets.'
    } else { '' }
    $addressTexts = if ($postAddressComments) {
        @('Free ServerSelectEntry::name when non-null.','Free ServerSelectEntry::description when non-null.','Free ServerSelectEntry::agreementText when non-null.')
    } else { @('Block','Block','Block') }
    Assert-UID0002PACommentRows -Rows @($comments.result) -FunctionText $functionText -AddressTexts $addressTexts

    $collision = Get-UID0002PAStructuredContent -Envelope $Responses.Collision -RequestJson $Requests.Collision -Label "$Phase collision"
    if (@($collision.result).Count -ne 2) { throw "RQ-PA $Phase collision page count mismatch" }
    if ($postName) {
        if ([int]$collision.result[0].total -ne 1 -or [string]$collision.result[0].data[0].addr -cne '0x494130' -or
            [string]$collision.result[0].data[0].name -cne $expectedName -or [int]$collision.result[0].data[0].size -ne 166 -or
            [int]$collision.result[1].total -ne 1 -or [string]$collision.result[1].data[0].addr -cne '0x494130' -or
            [string]$collision.result[1].data[0].name -cne $expectedName) { throw "RQ-PA $Phase renamed identity mismatch" }
    } elseif ([int]$collision.result[0].total -ne 0 -or [int]$collision.result[1].total -ne 0) {
        throw "RQ-PA $Phase proposed-name collision"
    }
    foreach ($page in $collision.result) {
        if ($null -ne $page.next_offset -or $null -ne $page.error) { throw "RQ-PA $Phase collision pagination/error mismatch" }
    }

    $candidate = Get-UID0002PAStructuredContent -Envelope $Responses.CandidateTypes -RequestJson $Requests.CandidateTypes -Label "$Phase candidate types"
    $candidateRows = @($candidate.result)
    $candidateNames=@('ConfigEntry','ConfigEntryBlock','ServerSelectEntry','ServerSelectDirectory')
    if ($candidateRows.Count -ne 4 -or
        (@($candidateRows|ForEach-Object{[string]$_.name}) -join '|') -cne ($candidateNames -join '|') -or
        $candidateRows[0].exists -ne $false -or $candidateRows[1].exists -ne $false) {
        throw "RQ-PA $Phase legacy candidate-type mismatch"
    }
    if (-not $postTypes) {
        if ($candidateRows[2].exists -ne $false -or $candidateRows[3].exists -ne $false) { throw "RQ-PA $Phase prestate UDT collision" }
    } else {
        $entryMembers = @(
            'serverId|0x0|1|unsigned __int8','name|0x4|4|wchar_t *','description|0x8|4|wchar_t *',
            'agreementText|0xc|4|wchar_t *','address|0x10|4|unsigned __int8[4]','port|0x14|2|unsigned __int16'
        )
        $directoryMembers = @('entries|0x0|768|ServerSelectEntry[32]','entryCount|0x300|4|int','version|0x304|1|unsigned __int8')
        if ($candidateRows[2].exists -ne $true -or [int]$candidateRows[2].size -ne 24 -or [int]$candidateRows[2].member_count -ne 6 -or
            (@($candidateRows[2].members | ForEach-Object {"$($_.name)|$($_.offset)|$($_.size)|$($_.type)"}) -join '|') -cne ($entryMembers -join '|') -or
            $candidateRows[3].exists -ne $true -or [int]$candidateRows[3].size -ne 776 -or [int]$candidateRows[3].member_count -ne 3 -or
            (@($candidateRows[3].members | ForEach-Object {"$($_.name)|$($_.offset)|$($_.size)|$($_.type)"}) -join '|') -cne ($directoryMembers -join '|')) {
            throw "RQ-PA $Phase exact declared UDT layout mismatch"
        }
    }

    $typeIndex = Get-UID0002PAStructuredContent -Envelope $Responses.CandidateTypeIndex -RequestJson $Requests.CandidateTypeIndex -Label "$Phase candidate type index"
    Assert-UID0002PACandidateTypeIndex -Pages @($typeIndex.result) -PostTypes $postTypes

    $config = Get-UID0002PAStructuredContent -Envelope $Responses.Config -RequestJson $Requests.Config -Label "$Phase Config"
    $configRows = @($config.result)
    if ($configRows.Count -ne 1 -or $configRows[0].exists -ne $true -or [string]$configRows[0].name -cne 'Config' -or
        [int]$configRows[0].size -ne 2693400 -or [int]$configRows[0].member_count -ne 51) {
        throw "RQ-PA $Phase Config shell mismatch"
    }
    Assert-UID0002PAExactJson @($configRows[0].members) @(Get-UID0002PAConfigOracle) "$Phase Config 51 rows"
    return [pscustomobject]@{
        Phase=$Phase;Role=[string]$RoleBinding.Role;Database=[string]$RoleBinding.Database
        WorkerGeneration=[string]$runtime.RoleWorker.Generation;RuntimeProof=$runtime;Passed=$true
    }
}

function New-UID0002PAMutationRequestCatalog {
    param([Parameter(Mandatory=$true)]$RoleBinding)
    $db=[string]$RoleBinding.Database
    if([string]::IsNullOrWhiteSpace($db)){throw 'mutation catalog blank returned database'}
    $entryDecl='struct ServerSelectEntry { unsigned char serverId; wchar_t *name; wchar_t *description; wchar_t *agreementText; unsigned char address[4]; unsigned short port; };'
    $directoryDecl='struct ServerSelectDirectory { ServerSelectEntry entries[32]; int entryCount; unsigned char version; };'
    [ordered]@{
        I01=New-UID0002PAToolRequest 'uid0002pa-I01-declare' 'declare_type' ([ordered]@{database=$db;decls=@($entryDecl,$directoryDecl)})
        I02Dry=New-UID0002PAToolRequest 'uid0002pa-I02-dry' 'rename' ([ordered]@{database=$db;batch=[ordered]@{func=[ordered]@{addr='0x00494130';name='ServerSelectDirectory__ReleaseOwnedBuffers'};stop_on_error=$true;dry_run=$true;allow_overwrite=$false;pure=$true}})
        I02=New-UID0002PAToolRequest 'uid0002pa-I02-apply' 'rename' ([ordered]@{database=$db;batch=[ordered]@{func=[ordered]@{addr='0x00494130';name='ServerSelectDirectory__ReleaseOwnedBuffers'};stop_on_error=$true;dry_run=$false;allow_overwrite=$false;pure=$true}})
        I03=New-UID0002PAToolRequest 'uid0002pa-I03-type' 'set_type' ([ordered]@{database=$db;edits=[ordered]@{addr='0x00494130';kind='function';signature='void __thiscall ServerSelectDirectory__ReleaseOwnedBuffers(ServerSelectDirectory *this)'}})
        I04=New-UID0002PAToolRequest 'uid0002pa-I04-function-comment' 'set_function_comments' ([ordered]@{database=$db;items=[ordered]@{addr='0x00494130';comment='ServerSelectDirectory::ReleaseOwnedBuffers; frees name, description, and agreement text for active entries, then resets entryCount and version. The null-receiver branch still faults on the final resets.'}})
        I05=New-UID0002PAToolRequest 'uid0002pa-I05-address-comments' 'set_address_comments' ([ordered]@{database=$db;items=@(
            [ordered]@{addr='0x00494157';comment='Free ServerSelectEntry::name when non-null.'},
            [ordered]@{addr='0x00494166';comment='Free ServerSelectEntry::description when non-null.'},
            [ordered]@{addr='0x00494176';comment='Free ServerSelectEntry::agreementText when non-null.'})})
    }
}

function Assert-UID0002PAMutationResponse {
    param(
        [Parameter(Mandatory=$true)][ValidateSet('I01','I02Dry','I02','I03','I04','I05')][string]$Action,
        [Parameter(Mandatory=$true)][string]$RequestJson,
        [Parameter(Mandatory=$true)]$Envelope,
        [Parameter(Mandatory=$true)]$RoleBinding)

    $request=Get-UID0002PARequestIdentity $RequestJson "mutation $Action"
    $expectedRequest=Get-UID0002PARequestIdentity ([string](New-UID0002PAMutationRequestCatalog $RoleBinding)[$Action]) "mutation $Action expected"
    $expectedTool=@{I01='declare_type';I02Dry='rename';I02='rename';I03='set_type';I04='set_function_comments';I05='set_address_comments'}[$Action]
    if([string]$request.Parsed.method -cne 'tools/call' -or
        [string]$request.Parsed.params.name -cne $expectedTool -or
        [string]::IsNullOrWhiteSpace([string]$request.Parsed.params.arguments.database) -or
        $request.SHA256 -cne $expectedRequest.SHA256 -or
        (($request.Parsed|ConvertTo-Json -Depth 30 -Compress) -cne ($expectedRequest.Parsed|ConvertTo-Json -Depth 30 -Compress))){
        throw "mutation $Action retained request mismatch"
    }
    $result = Get-UID0002PAStructuredContent -Envelope $Envelope -RequestJson $RequestJson -Label "mutation $Action"
    $entryDecl = 'struct ServerSelectEntry { unsigned char serverId; wchar_t *name; wchar_t *description; wchar_t *agreementText; unsigned char address[4]; unsigned short port; };'
    $directoryDecl = 'struct ServerSelectDirectory { ServerSelectEntry entries[32]; int entryCount; unsigned char version; };'
    switch ($Action) {
        'I01' {
            Assert-UID0002PAExactJson $result @([ordered]@{decl=$entryDecl},[ordered]@{decl=$directoryDecl}) 'I01 declare_type response'
        }
        'I02Dry' {
            $expected=[ordered]@{
                func=@([ordered]@{addr='0x00494130';old='sub_494130';name='ServerSelectDirectory__ReleaseOwnedBuffers';dry_run=$true})
                summary=[ordered]@{total=1;ok=1;failed=0;stopped=$false;dry_run=$true;stop_on_error=$true}
            }
            Assert-UID0002PAExactJson $result $expected 'I02 dry-run response'
        }
        'I02' {
            $expected=[ordered]@{
                func=@([ordered]@{addr='0x00494130';old='sub_494130';name='ServerSelectDirectory__ReleaseOwnedBuffers'})
                summary=[ordered]@{total=1;ok=1;failed=0;stopped=$false;stop_on_error=$true}
            }
            Assert-UID0002PAExactJson $result $expected 'I02 apply response'
        }
        'I03' {
            $edit=[ordered]@{addr='0x00494130';kind='function';signature='void __thiscall ServerSelectDirectory__ReleaseOwnedBuffers(ServerSelectDirectory *this)'}
            Assert-UID0002PAExactJson $result @([ordered]@{edit=$edit;kind='function';ok=$true}) 'I03 set_type response'
        }
        'I04' {
            Assert-UID0002PAExactJson $result @([ordered]@{addr='0x00494130';function_addr='0x494130'}) 'I04 function-comment response'
        }
        'I05' {
            Assert-UID0002PAExactJson $result @(
                [ordered]@{addr='0x00494157'},[ordered]@{addr='0x00494166'},[ordered]@{addr='0x00494176'}
            ) 'I05 address-comment response'
        }
    }
}
~~~

## Removed Block R026

- SHA256: `9A42D459F8F018746A86B3EA82206031EE150E30E98048D27B460B8782D6A51B`
- Language: `powershell`
- Bytes: `32526`
- First recovered timestamp: `2026-08-09T15:30:56.412Z`
- Session provenance: rollout-2026-08-08T17-46-23-019fe357-64cc-7ca3-ad27-c9c336afc6af.jsonl line 5673 (2026-08-09T15:30:56.412Z); rollout-2026-08-08T17-46-23-019fe357-64cc-7ca3-ad27-c9c336afc6af.jsonl line 5674 (2026-08-09T15:30:56.800Z)

~~~powershell
function Assert-UID0002PAPartialCleanupResult {
    param($Action,$Result)
    if($null -eq $Result -or $Result.Retired -ne $true -or $Result.PartialOpen -ne $true -or
        $Result.ListenerPreserved -ne $true -or
        [string]$Result.Action -cne 'RETIRE_PARTIAL_OPEN' -or [string]$Result.Role -cne [string]$Action.Role -or
        [string]$Result.Database -cne [string]$Action.Database -or [string]$Result.PreferredSessionId -cne [string]$Action.PreferredSessionId -or
        [int]$Result.RedirectorPid -ne [int]$Action.RedirectorPid -or
        [System.IO.Path]::GetFullPath([string]$Result.CanonicalPath) -ine [System.IO.Path]::GetFullPath([string]$Action.CanonicalPath) -or
        [string]$Result.OpenRequestSHA256 -cne [string]$Action.OpenRequestSHA256){
        throw 'OP2-PA partial-open cleanup result mismatch'
    }
    $true
}

function Invoke-UID0002PAClosedTransaction {
    param([Parameter(Mandatory=$true)][scriptblock]$Transport,[Parameter(Mandatory=$true)][scriptblock]$RetireExactGeneration)
    $canonical=[System.IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64')
    $state=New-UID0002PAAttestationState;$transactionId=[string]$state.TransactionId
    $evidenceKey=[Guid]::NewGuid().ToString('N')+[Guid]::NewGuid().ToString('N')
    $requestIds=[System.Collections.Generic.HashSet[string]]::new([System.StringComparer]::Ordinal)
    $transcript=[System.Collections.Generic.List[object]]::new()
    $durable=$null;$backup=$null;$transaction=$null;$saveObservation=$null
    $coordinator=[pscustomobject][ordered]@{SaveSent=$false;DurableHash=$null}

    $sendReadOnly={
        param([string]$RequestJson)
        $identity=Get-UID0002PARequestIdentity $RequestJson 'CT2-PA read-only dispatch'
        if([string]$identity.Parsed.method -ceq 'tools/call' -and [string]$identity.Parsed.params.name -ceq 'idb_save'){throw 'CT2-PA save reached read-only dispatcher'}
        $idKey="$($identity.IdType)|$($identity.Id)";if(-not $requestIds.Add($idKey)){throw "CT2-PA duplicate typed request id $idKey"}
        try{$wire=& $Transport $RequestJson}catch{throw "CT2-PA read-only transport failure: $($_.Exception.Message)"}
        if($wire -is [string]){$raw=[string]$wire;$observed='Response'}else{$observed=[string]$wire.ObservedTransport;$raw=[string]$wire.RawResponseJson}
        if($observed -cne 'Response' -or [string]::IsNullOrWhiteSpace($raw)){throw 'CT2-PA read-only request lacked response'}
        Assert-UID0002PARawJsonUnique $raw 'CT2-PA read-only response';$envelope=$raw|ConvertFrom-Json -ErrorAction Stop
        $null=Assert-UID0002PAJsonRpcResponse $envelope $RequestJson 'CT2-PA immediate read-only response' (-not ([string]$identity.Parsed.method -ceq 'tools/list')) $raw
        $record=[pscustomobject][ordered]@{RequestId=$identity.Id;RequestIdType=$identity.IdType;RequestSHA256=$identity.SHA256
            Tool=if([string]$identity.Parsed.method -ceq 'tools/list'){'tools/list'}else{[string]$identity.Parsed.params.name};ObservedTransport='Response';RawResponseJson=$raw;Envelope=$envelope}
        $transcript.Add($record);$record
    }

    $openRole={
        param([ValidateSet('Transaction','P0Verifier','S1Verifier','RollbackVerifier')][string]$Role)
        $openRequest=New-UID0002PARoleOpenRequest $Role;$openIdentity=Get-UID0002PARequestIdentity $openRequest "OP2-PA $Role open"
        $preferred=[string](($openRequest|ConvertFrom-Json).params.arguments.preferred_session_id)
        $database=$null;$redirectorPid=0;$binding=$null
        try{
            $openWire=& $sendReadOnly $openRequest
            $openContent=Assert-UID0002PAExactOpenEnvelopeV3 $openWire.Envelope $openRequest "OP3-PA $Role open"
            $openSessions=@($openContent.session)
            if($openSessions.Count -eq 1 -and (Test-UID0002PAJsonString $openSessions[0].session_id)){$database=[string]$openSessions[0].session_id}
            if(-not $openContent.PSObject.Properties['success'] -or -not (Test-UID0002PAJsonBoolean $openContent.success) -or $openContent.success -ne $true){throw "OP2-PA $Role open native success mismatch"}
            if($openSessions.Count -ne 1 -or -not $openSessions[0].PSObject.Properties['is_analyzing'] -or
                -not (Test-UID0002PAJsonBoolean $openSessions[0].is_analyzing) -or $openSessions[0].is_analyzing -ne $false -or
                -not (Test-UID0002PAJsonString $openSessions[0].session_id) -or -not (Test-UID0002PAJsonString $openSessions[0].input_path)){
                throw "OP2-PA $Role open session native mismatch"
            }
            $listRequest=New-UID0002PAToolRequest "uid0002pa-open-list-$Role-$([Guid]::NewGuid().ToString('N'))" 'idb_list' @{}
            $listWire=& $sendReadOnly $listRequest;$list=Get-UID0002PAStructuredContent $listWire.Envelope $listRequest "OP2-PA $Role list"
            $matches=@($list.sessions|Where-Object{[string]$_.session_id -ceq $database -and $_.is_active -eq $true})
            if($matches.Count -ne 1 -or -not (Test-UID0002PAJsonInteger $matches[0].worker_pid)){throw "OP2-PA $Role list PID native mismatch"}
            $redirectorPid=[int]$matches[0].worker_pid
            $binding=New-UID0002PARoleBinding $Role $preferred $openRequest $openWire.Envelope $listRequest $listWire.Envelope
            $attestRequest=New-UID0002PARuntimeAttestationRequest "uid0002pa-open-attest-$Role-$([Guid]::NewGuid().ToString('N'))" $binding
            $attestWire=& $sendReadOnly $attestRequest
            $runtime=Assert-UID0002PARuntimeAttestation $attestWire.Envelope $attestRequest $listWire.Envelope $listRequest $binding $state
            [pscustomobject]@{Role=$Role;Binding=$binding;Runtime=$runtime;OpenRequest=$openRequest;OpenResponse=$openWire.Envelope;Closed=$false;CloseAuthority=$null}
        }catch{
            $openFailure=$_.Exception.Message
            if([string]::IsNullOrWhiteSpace($database) -or $redirectorPid -le 0){
                try{
                    $recoveryRequest=New-UID0002PAToolRequest "uid0002pa-open-recovery-$Role-$([Guid]::NewGuid().ToString('N'))" 'idb_list' @{}
                    $recoveryWire=& $sendReadOnly $recoveryRequest
                    $recovery=Get-UID0002PAStructuredContent $recoveryWire.Envelope $recoveryRequest "OP2-PA $Role recovery list"
                    $recoveryMatches=@($recovery.sessions|Where-Object{
                        (Test-UID0002PAJsonBoolean $_.is_active) -and $_.is_active -eq $true -and (Test-UID0002PAJsonString $_.session_id) -and
                        (Test-UID0002PAJsonString $_.input_path) -and (Test-UID0002PAJsonInteger $_.worker_pid) -and
                        [string]$_.session_id -ceq $preferred -and
                        [System.IO.Path]::GetFullPath([string]$_.input_path) -ieq $canonical -and
                        ([string]::IsNullOrWhiteSpace($database) -or [string]$_.session_id -ceq $database)
                    })
                    if($recoveryMatches.Count -eq 1){$database=[string]$recoveryMatches[0].session_id;$redirectorPid=[int]$recoveryMatches[0].worker_pid}
                }catch{throw "OP2-PA partial-open identity recovery failed after [$openFailure]: $($_.Exception.Message)"}
            }
            if(-not [string]::IsNullOrWhiteSpace($database)){
                $action=[pscustomobject][ordered]@{Action='RETIRE_PARTIAL_OPEN';PartialOpen=$true;Role=$Role;Database=$database;CanonicalPath=$canonical
                    PreferredSessionId=$preferred;RedirectorPid=$redirectorPid;OpenRequestSHA256=$openIdentity.SHA256;PreserveListener=$true}
                try{$result=& $RetireExactGeneration $action;$null=Assert-UID0002PAPartialCleanupResult $action $result}
                catch{throw "OP2-PA partial-open cleanup failed after [$openFailure]: $($_.Exception.Message)"}
            }else{
                throw "OP2-PA partial-open identity unavailable after [$openFailure]"
            }
            throw $openFailure
        }
    }

    $catalog={
        param($RoleObject,[ValidateSet('Pre','AfterI01','AfterI02','AfterI03','AfterI04','AfterI05','Final','P0Verifier','S1Verifier','RollbackVerifier')][string]$Phase,[switch]$DeferSemantic)
        $requests=New-UID0002PAReadbackCatalog $RoleObject.Binding $Phase;$responses=[ordered]@{}
        foreach($key in @($requests.Keys)){$responses[$key]=(& $sendReadOnly ([string]$requests[$key])).Envelope}
        if($DeferSemantic){return [pscustomobject]@{Requests=$requests;Responses=$responses}}
        $readback=Assert-UID0002PAReadbackCatalog $requests $responses $RoleObject.Binding $state $Phase
        [pscustomobject]@{Requests=$requests;Responses=$responses;Readback=$readback}
    }

    $closeRole={
        param($RoleObject)
        if($RoleObject.Closed -eq $true){return $RoleObject.CloseAuthority}
        $binding=$RoleObject.Binding
        $preListRequest=New-UID0002PAToolRequest "uid0002pa-preclose-list-$($binding.Role)-$([Guid]::NewGuid().ToString('N'))" 'idb_list' @{}
        $preList=& $sendReadOnly $preListRequest
        $preAttestRequest=New-UID0002PARuntimeAttestationRequest "uid0002pa-preclose-attest-$($binding.Role)-$([Guid]::NewGuid().ToString('N'))" $binding
        $preAttest=& $sendReadOnly $preAttestRequest
        $preRuntime=Assert-UID0002PARuntimeAttestation $preAttest.Envelope $preAttestRequest $preList.Envelope $preListRequest $binding $state
        $action=Invoke-UID0002PAExactGenerationRetirementAction $binding $state $preRuntime $RetireExactGeneration
        $postRequest=New-UID0002PAPostRetirementAttestationRequest "uid0002pa-postclose-attest-$($binding.Role)-$([Guid]::NewGuid().ToString('N'))" $binding
        $post=& $sendReadOnly $postRequest
        $postListRequest=New-UID0002PAToolRequest "uid0002pa-postclose-list-$($binding.Role)-$([Guid]::NewGuid().ToString('N'))" 'idb_list' @{}
        $postList=& $sendReadOnly $postListRequest
        $proof=Assert-UID0002PARoleRetired $binding $state $preRuntime $action $post.Envelope $postRequest $postList.Envelope $postListRequest
        $authority=[pscustomobject][ordered]@{Proof=$proof;TransactionId=$transactionId;Role=[string]$binding.Role;AuthorityHmac=$null}
        $authority.AuthorityHmac=Get-UID0002PAEvidenceHmac (Get-UID0002PARetirementAuthorityText $authority) $evidenceKey
        $RoleObject.Closed=$true;$RoleObject.CloseAuthority=$authority;$authority
    }

    $dispatchSave={
        param([string]$RequestJson,[string]$Database)
        $identity=Assert-UID0002PAExactSaveRequest $RequestJson $Database $canonical
        $idKey="$($identity.IdType)|$($identity.Id)";if(-not $requestIds.Add($idKey)){throw "SV2-PA duplicate typed save id $idKey"}
        $coordinator.DurableHash=Set-UID0002PADurableSaveDispatched $durable $identity $Database;$coordinator.SaveSent=$true
        $observed='MissingResponse';$raw=$null;$thrown=$null
        try{
            $wire=& $Transport $RequestJson
            if($null -eq $wire){$observed='MissingResponse'}
            elseif($wire -is [string]){$observed='Response';$raw=[string]$wire}
            else{
                $candidate=[string]$wire.ObservedTransport;$raw=[string]$wire.RawResponseJson
                if($candidate -in @('Response','Timeout','Disconnect','Malformed')){$observed=$candidate}else{$observed='Malformed'}
                if($observed -ceq 'Response' -and [string]::IsNullOrWhiteSpace($raw)){$observed='MissingResponse'}
            }
        }catch{$observed='ThrownTransport';$thrown=$_.Exception.Message}
        $record=[pscustomobject][ordered]@{RequestId=$identity.Id;RequestIdType=$identity.IdType;RequestSHA256=$identity.SHA256;Tool='idb_save'
            ObservedTransport=$observed;RawResponseJson=$raw;ThrownFailure=$thrown}
        $transcript.Add($record);$record
    }

    $restoreClosed={
        param($Attempt,$Core,$V3Backup)
        Assert-UID0002PAAttemptAuthorityHmac $Attempt $evidenceKey
        if([string]$Attempt.Status -cne 'F1_RESTORE_REQUIRED' -or $null -eq $Attempt.Candidate){throw 'RS2-PA restore lacks closed F1 authority'}
        Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $Attempt.CanonicalPath) $Attempt.Candidate 'RS2-PA pre-handle candidate'
        $source=$null;$destination=$null
        try{
            $source=[IO.FileStream]::new($V3Backup.B0.FullPath,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None)
            $destination=[IO.FileStream]::new($Attempt.CanonicalPath,[IO.FileMode]::Open,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None)
            $heldSource=Get-UID0002PAV3HeldTuple $source $V3Backup.B0.FullPath;$heldDestination=Get-UID0002PAV3HeldTuple $destination $Attempt.CanonicalPath
            Assert-UID0002PAV3TupleProjection $heldDestination $Attempt.Candidate 'RS3-PA held destination projection'
            $Core.AuthorizeRestore($heldDestination,$heldSource)
            $source.Position=0;$destination.SetLength(0);$destination.Position=0;$buffer=New-Object byte[] 1048576;$copied=[long]0
            while(($read=$source.Read($buffer,0,$buffer.Length)) -gt 0){$destination.Write($buffer,0,$read);$copied+=$read}
            if($copied -ne $Attempt.P0.Length -or $source.Position -ne $Attempt.P0.Length -or $source.ReadByte() -ne -1 -or
                $destination.Position -ne $Attempt.P0.Length -or $destination.Length -ne $Attempt.P0.Length){throw 'RS2-PA copy/EOF/destination mismatch'}
            $destination.Flush($true);[UID0002PANativeSealedCore]::SetWriteTicks($destination,[long]$Attempt.P0.LastWriteTimeUtcTicks)
            $restored=Get-UID0002PAV3HeldTuple $destination $Attempt.CanonicalPath;$Core.MarkRestored($restored)
        }finally{if($null -ne $destination){$destination.Dispose()};if($null -ne $source){$source.Dispose()}}
        Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $Attempt.CanonicalPath) $Attempt.P0 'RS2-PA closed restored P0 first'
        Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $Attempt.CanonicalPath) $Attempt.P0 'RS2-PA closed restored P0 second'
        $Attempt.Status='ROLLBACK_VERIFIER_REQUIRED';Set-UID0002PAAttemptAuthorityHmac $Attempt $evidenceKey;$Attempt
    }

    try{
        $durable=New-UID0002PADurableAuthority $canonical $transactionId;$coordinator.DurableHash=Write-UID0002PADurableAuthority $durable
        $toolsRequest='{"jsonrpc":"2.0","id":"uid0002pa-tools","method":"tools/list","params":{}}';$toolsWire=& $sendReadOnly $toolsRequest
        $null=Assert-UID0002PAToolsList $toolsWire.Envelope $toolsRequest
        $preflightRequest=New-UID0002PAToolRequest "uid0002pa-preflight-$([Guid]::NewGuid().ToString('N'))" 'idb_list' @{}
        $preflightWire=& $sendReadOnly $preflightRequest;$preflight=Get-UID0002PAStructuredContent $preflightWire.Envelope $preflightRequest 'CT2-PA preflight'
        foreach($row in @($preflight.sessions)){if(-not (Test-UID0002PAJsonBoolean $row.is_active) -or -not (Test-UID0002PAJsonInteger $row.worker_pid)){throw 'CT2-PA preflight native session mismatch'}}
        if(@($preflight.sessions|Where-Object{$_.is_active -eq $true -and [IO.Path]::GetFullPath([string]$_.input_path) -ieq $canonical}).Count -ne 0){throw 'CT2-PA canonical database already active'}
        $backupPath=$canonical+'.bak-UID0002PA-prestate-'+[DateTime]::UtcNow.ToString('yyyyMMdd-HHmmss')+'-'+[Guid]::NewGuid().ToString('N')
        $backup=New-UID0002PABackup $canonical $backupPath
        $transaction=& $openRole Transaction;$null=& $catalog $transaction Pre
        $mutations=New-UID0002PAMutationRequestCatalog $transaction.Binding
        foreach($step in @(@('I01','AfterI01'),@('I02Dry',$null),@('I02','AfterI02'),@('I03','AfterI03'),@('I04','AfterI04'),@('I05','AfterI05'))){
            $action=[string]$step[0];$request=[string]$mutations[$action];$wire=& $sendReadOnly $request
            Assert-UID0002PAMutationResponse $action $request $wire.Envelope $transaction.Binding
            if($null -ne $step[1]){$null=& $catalog $transaction ([string]$step[1])}
        }
        $final=& $catalog $transaction Final
        $saveRequest=New-UID0002PAToolRequest 'uid0002pa-save-transaction' 'idb_save' ([ordered]@{database=[string]$transaction.Binding.Database;path=$canonical})
        $attempt=[pscustomobject][ordered]@{TransactionId=$transactionId;Database=[string]$transaction.Binding.Database;TransactionGeneration=[string]$transaction.Runtime.WorkerGeneration
            CanonicalPath=$canonical;SaveRequestSHA256=(Get-UID0002PARequestIdentity $saveRequest 'CT2-PA save').SHA256;SaveDispatchCount=0;TransportClass='NotDispatched'
            DurableState='PRE_SAVE';DurableJournalSHA256=$coordinator.DurableHash;FinalReadbackSHA256=Get-UID0002PATextSha256 (($final|ConvertTo-Json -Depth 60 -Compress))
            P0=Get-UID0002PATupleCopy $backup.P0;B0=Get-UID0002PATupleCopy $backup.B0;Candidate=$null;Status='PREPARED';AuthorityHmac=$null}
        Set-UID0002PAAttemptAuthorityHmac $attempt $evidenceKey
        $retirementAuthority=$null;$retirementFailure=$null
        try{$saveObservation=& $dispatchSave $saveRequest $transaction.Binding.Database}
        finally{
            if($coordinator.SaveSent){try{$retirementAuthority=& $closeRole $transaction}catch{$retirementFailure=$_.Exception.Message}}
        }
        $outcome=Resolve-UID0002PASaveTransportOutcome $saveRequest $saveObservation.ObservedTransport $saveObservation.RawResponseJson $saveObservation.ThrownFailure
        $attempt.SaveDispatchCount=1;$attempt.TransportClass=[string]$outcome.TransportClass;$attempt.DurableState='SAVE_DISPATCHED_DURABLE';$attempt.DurableJournalSHA256=$coordinator.DurableHash;$attempt.Status='TRANSPORT_CLASSIFIED'
        Set-UID0002PAAttemptAuthorityHmac $attempt $evidenceKey
        if(-not [string]::IsNullOrWhiteSpace($retirementFailure)){$durable.Record.State='RETIREMENT_FAILED';$durable.Record.Terminal=$retirementFailure;$coordinator.DurableHash=Write-UID0002PADurableAuthority $durable;throw "CT2-PA post-save retirement failed: $retirementFailure"}
        $classification=Get-UID0002PAChangedDiskClassification $attempt $retirementAuthority $evidenceKey
        $sealedStream=[IO.FileStream]::new($canonical,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None)
        try{$sealedClosed=Get-UID0002PAV3HeldTuple $sealedStream $canonical}finally{$sealedStream.Dispose()}
        Assert-UID0002PAV3TupleProjection $sealedClosed $retirementAuthority.Proof.ClosedTupleA 'DS3-PA retired Dclosed projection'
        $SealedCore.RecordDclosed($sealedClosed,[string]$attempt.TransportClass)
        if($classification.RequiredVerifier -ceq 'P0Verifier'){
            $verifier=$null;$vrClose=$null
            try{$verifier=& $openRole P0Verifier;$vr=& $catalog $verifier P0Verifier}
            finally{if($null -ne $verifier -and $verifier.Closed -ne $true){$vrClose=& $closeRole $verifier}}
            Assert-UID0002PARetirementAuthorityHmac $vrClose $evidenceKey
            Assert-UID0002PAVerifierIdentity $state P0Verifier $verifier.Binding $vr.Readback $vr.Readback.RuntimeProof $vrClose.Proof
            Assert-UID0002PATuple $vrClose.Proof.ClosedTupleA $attempt.P0 'CT2-PA P0 verifier first';Assert-UID0002PATuple $vrClose.Proof.ClosedTupleB $attempt.P0 'CT2-PA P0 verifier second'
            $SealedCore.MarkP0Verified()
            $attempt.Status="NOT_PERSISTED_P0_VERIFIED_$($attempt.TransportClass.ToUpperInvariant())";Set-UID0002PAAttemptAuthorityHmac $attempt $evidenceKey
        }else{
            $verifier=$null;$vrClose=$null
            try{
                $verifier=& $openRole S1Verifier;$pending=& $catalog $verifier S1Verifier -DeferSemantic
                $verifierOutcome=New-UID0002PAFailedVerifierEvidence $pending.Requests $pending.Responses $verifier.Binding $state $evidenceKey
            }finally{if($null -ne $verifier -and $verifier.Closed -ne $true){$vrClose=& $closeRole $verifier}}
            Assert-UID0002PARetirementAuthorityHmac $vrClose $evidenceKey
            Assert-UID0002PATuple $vrClose.Proof.ClosedTupleA $attempt.Candidate 'CT2-PA S1/F1 verifier first';Assert-UID0002PATuple $vrClose.Proof.ClosedTupleB $attempt.Candidate 'CT2-PA S1/F1 verifier second'
            if($verifierOutcome.Passed -eq $true){
                Assert-UID0002PAVerifierIdentity $state S1Verifier $verifier.Binding $verifierOutcome.Readback $verifierOutcome.Readback.RuntimeProof $vrClose.Proof
                $SealedCore.MarkP1Verified()
                $attempt.Status='PERSISTED_S1_VERIFIED_DETERMINATESUCCESS';Set-UID0002PAAttemptAuthorityHmac $attempt $evidenceKey
            }else{
                $null=Assert-UID0002PAFailedVerifierEvidence $verifierOutcome $verifier.Binding $evidenceKey
                if([string]$verifierOutcome.WorkerGeneration -cne [string]$state.RoleWorkers[[string]$verifier.Binding.Database].Generation){throw 'VR2-PA failed Final verifier generation mismatch'}
                $SealedCore.MarkF1('Final','S1Verifier',[string]$verifierOutcome.ExactFailure,[string]$verifierOutcome.RequestCatalogSHA256,[string]$verifierOutcome.ResponseCatalogSHA256,[string]$verifierOutcome.Database,[string]$verifierOutcome.WorkerGeneration);$attempt.Status='F1_RESTORE_REQUIRED';Set-UID0002PAAttemptAuthorityHmac $attempt $evidenceKey;$attempt=& $restoreClosed $attempt $SealedCore $SealedBackup
                $rollback=$null;$rbClose=$null
                try{$rollback=& $openRole RollbackVerifier;$rb=& $catalog $rollback RollbackVerifier}
                finally{if($null -ne $rollback -and $rollback.Closed -ne $true){$rbClose=& $closeRole $rollback}}
                Assert-UID0002PARetirementAuthorityHmac $rbClose $evidenceKey
                Assert-UID0002PAVerifierIdentity $state RollbackVerifier $rollback.Binding $rb.Readback $rb.Readback.RuntimeProof $rbClose.Proof
                Assert-UID0002PATuple $rbClose.Proof.ClosedTupleA $attempt.P0 'CT2-PA rollback first';Assert-UID0002PATuple $rbClose.Proof.ClosedTupleB $attempt.P0 'CT2-PA rollback second'
                $SealedCore.MarkRollbackVerified()
                $attempt.Status='RESTORED_P0_VERIFIED_DETERMINATESUCCESS';Set-UID0002PAAttemptAuthorityHmac $attempt $evidenceKey
            }
        }
        $durable.Record.State='TERMINAL';$durable.Record.Terminal=[string]$attempt.Status;$coordinator.DurableHash=Write-UID0002PADurableAuthority $durable
        [pscustomobject]@{Status=$attempt.Status;Attempt=$attempt;Transcript=@($transcript);SaveDispatchCount=1;DurableJournal=$durable.Path;DurableJournalSHA256=$coordinator.DurableHash}
    }catch{
        $failure=$_.Exception.Message
        if($coordinator.SaveSent){if($null -ne $durable -and $durable.Stream.CanWrite){$durable.Record.State='FAILED_CLOSED_AFTER_SAVE';$durable.Record.Terminal=$failure;$null=Write-UID0002PADurableAuthority $durable};throw}
        if($null -ne $transaction -and $transaction.Closed -ne $true){$null=& $closeRole $transaction}
        if($null -ne $backup){Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $canonical) $backup.P0 'CT2-PA no-save P0';Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $backup.B0.FullPath) $backup.B0 'CT2-PA no-save B0'}
        throw
    }finally{
        if($null -ne $durable){$path=$durable.Path;if($durable.Stream.CanWrite){$durable.Stream.Dispose()};if(-not $coordinator.SaveSent -and [IO.File]::Exists($path)){[IO.File]::Delete($path)}}
    }
}

function Invoke-UID0002PAHostileStaticFixtures {
    $passed=0;$contracts=Get-UID0002PAUsedToolSchemaContracts
    try{$null=Assert-UID0002PAHostileThrow {throw 'UNRELATED'} 'EXPECTED'}catch{if($_.Exception.Message -cne 'HOSTILE FIXTURE WRONG FAILURE: expected=[EXPECTED] actual=[UNRELATED]'){throw};$labelGuard=$true}
    if($labelGuard -ne $true){throw 'hostile exact-label guard unavailable'}

    if(Assert-UID0002PAHostileThrow {Assert-UID0002PARawJsonUnique '{"id":1,"id":2}' 'fixture'} 'fixture raw JSON rejected: JSON_DUPLICATE_MEMBER:id'){$passed++}
    if(Assert-UID0002PAHostileThrow {Get-UID0002PARequestIdentity '{"jsonrpc":"2.0","id":true,"method":"tools/list","params":{}}' 'fixture request'} 'fixture request invalid native JSON-RPC request root/id'){$passed++}
    if(Assert-UID0002PAHostileThrow {Get-UID0002PARequestIdentity '{"jsonrpc":"2.0","id":"x","method":"wrong","params":{}}' 'fixture request'} 'fixture request unexpected JSON-RPC method'){$passed++}
    $open=New-UID0002PARoleOpenRequest Transaction|ConvertFrom-Json;$open.params.arguments.idle_ttl_sec='600';$bad=$open|ConvertTo-Json -Depth 20 -Compress
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PALiteralRoleOpenRequest Transaction $bad} 'Transaction literal idb_open options/types/prefix mismatch'){$passed++}
    $open=New-UID0002PARoleOpenRequest Transaction|ConvertFrom-Json;$open.params.arguments.run_auto_analysis=0;$bad=$open|ConvertTo-Json -Depth 20 -Compress
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PALiteralRoleOpenRequest Transaction $bad} 'Transaction literal idb_open options/types/prefix mismatch'){$passed++}
    $request=New-UID0002PAToolRequest 'fixture-response' 'idb_list' @{};$missing=[pscustomobject]@{jsonrpc='2.0';id='fixture-response';result=[pscustomobject]@{structuredContent=[pscustomobject]@{sessions=@()}}}
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PAJsonRpcResponse $missing $request 'fixture response' $true} 'fixture response missing/non-Boolean isError'){
        $foreignError=[pscustomobject]@{jsonrpc='2.0';id=1;error=[pscustomobject]@{code=-32000;message='foreign'}}
        $null=Assert-UID0002PAHostileThrow {Assert-UID0002PAJsonRpcResponse $foreignError $request 'fixture response' $true} 'fixture response JSON-RPC identity/result mismatch'
        $passed++
    }
    $wrong=[pscustomobject]@{jsonrpc='2.0';id='fixture-response';result=[pscustomobject]@{isError='false';structuredContent=[pscustomobject]@{sessions=@()}}}
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PAJsonRpcResponse $wrong $request 'fixture response' $true} 'fixture response missing/non-Boolean isError'){$passed++}
    $openContent=[pscustomobject]@{success=$true;session=[pscustomobject]@{session_id='x';input_path='x'}};$listContent=[pscustomobject]@{sessions=@()};$runtimeContent=[pscustomobject]@{schema_version=1;ok=$true;listener=[pscustomobject]@{process=[pscustomobject]@{pid=1;creation_time_100ns=1}};workers=@()}
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PAOpenAndRuntimeNativeFields $openContent $listContent $runtimeContent 'fixture'} 'fixture open session native fields mismatch'){$passed++}
    $openContent.session|Add-Member -NotePropertyName is_analyzing -NotePropertyValue $false;$listContent.sessions=@([pscustomobject]@{session_id='x';input_path='x';is_active=$true;worker_pid='1'})
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PAOpenAndRuntimeNativeFields $openContent $listContent $runtimeContent 'fixture'} 'fixture list session native fields mismatch'){$passed++}
    $tool=New-UID0002PAFixtureToolFromContract xref_query $contracts.xref_query;$tool.inputSchema.properties.queries|Add-Member -NotePropertyName properties -NotePropertyValue ([pscustomobject]@{evil=[pscustomobject]@{type='string'}})
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PAToolSchemaContract $tool $contracts.xref_query} 'S-PA xref_query recursive authority-schema digest mismatch'){$passed++}
    $root=[IO.Path]::GetFullPath($UID0002PASourceRoot).TrimEnd('\');$mods=@();$n=0
    foreach($name in $UID0002PAListenerNames){$n++;$file=Join-Path $root "fixture-$n.py";$mods+=[pscustomobject]@{sys_modules_name=$name;module_id=('0x{0:x}' -f $n);file=$file;spec_origin=$file;resolved_path=$file;size=1;mtime_ns=1;ctime_ns=1;sha256=('A'*64)}}
    $owner=[pscustomobject]@{source_root=$root;implementation_manifest_sha256='D3C792133956B855EBA751FDB5783B2D7177FA204134CFF1D897E0D0770FB7CE';modules=$mods}
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PAModuleManifest $owner listener 'fixture module'} 'fixture module module-row aggregate digest mismatch'){$passed++}
    if(Assert-UID0002PAHostileThrow {New-UID0002PAClosedControllerContext} 'CT-PA direct controller construction disabled'){$passed++}
    $counter=[pscustomobject]@{Count=0};$unused={param($json)$counter.Count++}.GetNewClosure()
    if(Assert-UID0002PAHostileThrow {Invoke-UID0002PAControllerRequest $unused} 'CT-PA direct dispatch disabled'){$passed++};if($counter.Count -ne 0){throw 'hostile direct-dispatch counter changed'}
    if(Assert-UID0002PAHostileThrow {New-UID0002PASaveAttempt} 'SV-PA public save-attempt construction disabled'){$passed++}
    if(Assert-UID0002PAHostileThrow {Register-UID0002PASoleSaveDispatch} 'SV-PA public save registration disabled'){$passed++}
    if(Assert-UID0002PAHostileThrow {Complete-UID0002PADiskClassification} 'SV-PA public disk classifier disabled'){$passed++}
    if(Assert-UID0002PAHostileThrow {Restore-UID0002PABackup} 'RS-PA public restore disabled'){$passed++}
    $save=New-UID0002PAToolRequest 'save-fixture' 'idb_save' ([ordered]@{database='db';path='E:\NTK\Resources\NexusTK\NexusTK.exe.i64'})
    $foreign='{"jsonrpc":"2.0","id":"foreign","result":{"isError":false,"structuredContent":{"ok":true,"error":"","path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64"}}}'
    $out=Resolve-UID0002PASaveTransportOutcome $save Response $foreign $null;if($out.TransportClass -cne 'Indeterminate' -or $out.Observation -cne 'MalformedOrForeignResponse'){throw 'hostile foreign-save classifier mismatch'};$passed++
    $out=Resolve-UID0002PASaveTransportOutcome $save ThrownTransport $null 'wire exploded';if($out.TransportClass -cne 'Indeterminate' -or $out.Observation -cne 'ThrownTransport'){throw 'hostile thrown-transport classifier mismatch'};$passed++
    $key='0'*64;$canonical=[IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64');$p0=[pscustomobject]@{FullPath=$canonical;Length=100;LastWriteTimeUtcTicks=10;SHA256=('A'*64)}
    $attempt=[pscustomobject]@{TransactionId='t';Database='db';TransactionGeneration='gen';CanonicalPath=$canonical;SaveRequestSHA256=('B'*64);SaveDispatchCount=1;TransportClass='DeterminateSuccess';DurableState='SAVE_DISPATCHED_DURABLE';DurableJournalSHA256=('C'*64);FinalReadbackSHA256=('D'*64);P0=$p0;B0=$p0;Candidate=$null;Status='TRANSPORT_CLASSIFIED';AuthorityHmac=$null};Set-UID0002PAAttemptAuthorityHmac $attempt $key
    $timestamp=[pscustomobject]@{FullPath=$canonical;Length=100;LastWriteTimeUtcTicks=11;SHA256=('A'*64)};$proof=[pscustomobject]@{Role='Transaction';Database='db';Generation='gen';ClosedTupleA=$timestamp;ClosedTupleB=$timestamp}
    $ra=[pscustomobject]@{Proof=$proof;TransactionId='t';Role='Transaction';AuthorityHmac=$null};$ra.AuthorityHmac=Get-UID0002PAEvidenceHmac (Get-UID0002PARetirementAuthorityText $ra) $key
    if(Assert-UID0002PAHostileThrow {Get-UID0002PAChangedDiskClassification $attempt $ra $key} 'CS2-PA timestamp-only candidate rejected'){$passed++}
    $changed=[pscustomobject]@{FullPath=$canonical;Length=101;LastWriteTimeUtcTicks=11;SHA256=('E'*64)};$proof.ClosedTupleA=$changed;$proof.ClosedTupleB=$changed;$attempt.TransportClass='Indeterminate';Set-UID0002PAAttemptAuthorityHmac $attempt $key;$ra.AuthorityHmac=Get-UID0002PAEvidenceHmac (Get-UID0002PARetirementAuthorityText $ra) $key
    if(Assert-UID0002PAHostileThrow {Get-UID0002PAChangedDiskClassification $attempt $ra $key} 'CS2-PA changed disk without determinate save success'){$passed++}
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PAFinalSemanticFailureLabel 'RA-PA top-level schema/status/errors mismatch'} 'VR2-PA failure is not literal Final-oracle semantic mismatch'){$passed++}
    $ra.AuthorityHmac='0'*64
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PARetirementAuthorityHmac $ra $key} 'RT2-PA closed retirement HMAC mismatch'){$passed++}
    $temp=[IO.Path]::Combine([IO.Path]::GetTempPath(),'uid0002pa-handle-'+[Guid]::NewGuid().ToString('N')+'.bin')
    try{[IO.File]::WriteAllBytes($temp,[byte[]](1,2,3,4));$expectedTicks=[IO.File]::GetLastWriteTimeUtc($temp).Ticks;$s=[IO.FileStream]::new($temp,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);try{$tuple=Get-UID0002PAHeldHandleTuple $s $temp;if($tuple.Length -ne 4 -or $tuple.FullPath -ine [IO.Path]::GetFullPath($temp) -or $tuple.LastWriteTimeUtcTicks -ne $expectedTicks){throw 'hostile held-handle tuple mismatch'}}finally{$s.Dispose()}}finally{if([IO.File]::Exists($temp)){[IO.File]::Delete($temp)}}
    if($passed -ne 23){throw "hostile fixture count mismatch: $passed"}
    throw 'HF2-PA superseded fixture package; invoke final NR3-PA production-controller suite'
}
~~~

## Removed Block R027

- SHA256: `A1014774B7C9FCE960A2F5E25B08677A7419BB424709C1BB362C18AB0B376A4A`
- Language: `powershell`
- Bytes: `75245`
- First recovered timestamp: `2026-08-09T15:30:56.412Z`
- Session provenance: rollout-2026-08-08T17-46-23-019fe357-64cc-7ca3-ad27-c9c336afc6af.jsonl line 5673 (2026-08-09T15:30:56.412Z); rollout-2026-08-08T17-46-23-019fe357-64cc-7ca3-ad27-c9c336afc6af.jsonl line 5674 (2026-08-09T15:30:56.800Z)

~~~powershell
function Get-UID0002PAStreamSha256 {
    param([Parameter(Mandatory=$true)][System.IO.FileStream]$Stream)
    $Stream.Position = 0
    $sha = [System.Security.Cryptography.SHA256]::Create()
    try { $digest = $sha.ComputeHash($Stream) }
    finally { $sha.Dispose() }
    $Stream.Position = 0
    return ([System.BitConverter]::ToString($digest)).Replace('-','')
}

function Get-UID0002PAExclusiveTuple {
    param([Parameter(Mandatory=$true)][string]$Path)
    $full = [System.IO.Path]::GetFullPath($Path)
    if (-not [System.IO.File]::Exists($full)) { throw "missing file: $full" }
    $beforeTicks = [System.IO.File]::GetLastWriteTimeUtc($full).Ticks
    $stream = $null
    try {
        $stream = [System.IO.FileStream]::new($full,[System.IO.FileMode]::Open,[System.IO.FileAccess]::Read,[System.IO.FileShare]::None)
        $length = [long]$stream.Length
        if ($length -le 0) { throw "nonpositive length: $full" }
        $sha256 = Get-UID0002PAStreamSha256 $stream
        $duringTicks = [System.IO.File]::GetLastWriteTimeUtc($full).Ticks
        if ($beforeTicks -ne $duringTicks) { throw "mtime changed during exclusive tuple: $full" }
    } finally {
        if ($null -ne $stream) { $stream.Dispose() }
    }
    $afterTicks = [System.IO.File]::GetLastWriteTimeUtc($full).Ticks
    if ($duringTicks -ne $afterTicks) { throw "mtime changed after exclusive tuple: $full" }
    [pscustomobject][ordered]@{
        FullPath=$full; Length=$length; LastWriteTimeUtcTicks=[long]$afterTicks; SHA256=$sha256
    }
}

function Assert-UID0002PATuple {
    param([Parameter(Mandatory=$true)]$Actual,[Parameter(Mandatory=$true)]$Expected,[Parameter(Mandatory=$true)][string]$Label)
    foreach ($property in 'FullPath','Length','LastWriteTimeUtcTicks','SHA256') {
        if ([string]$Actual.$property -cne [string]$Expected.$property) { throw "$Label tuple mismatch at $property" }
    }
}

function Get-UID0002PATupleCopy {
    param([Parameter(Mandatory=$true)]$Tuple)
    [pscustomobject][ordered]@{
        FullPath=[string]$Tuple.FullPath
        Length=[long]$Tuple.Length
        LastWriteTimeUtcTicks=[long]$Tuple.LastWriteTimeUtcTicks
        SHA256=[string]$Tuple.SHA256
    }
}

function New-UID0002PABackup {
    param([Parameter(Mandatory=$true)][string]$CanonicalPath,[Parameter(Mandatory=$true)][string]$BackupPath)

    $canonical = [System.IO.Path]::GetFullPath($CanonicalPath)
    $backup = [System.IO.Path]::GetFullPath($BackupPath)
    if ($canonical -ieq $backup -or [System.IO.File]::Exists($backup)) { throw 'BK-PA alias/collision' }

    $source = $null
    $destination = $null
    try {
        $source = [System.IO.FileStream]::new($canonical,[System.IO.FileMode]::Open,[System.IO.FileAccess]::Read,[System.IO.FileShare]::None)
        $p0Length = [long]$source.Length
        $p0TicksBefore = [long][System.IO.File]::GetLastWriteTimeUtc($canonical).Ticks
        $p0Sha = Get-UID0002PAStreamSha256 $source
        $source.Position = 0
        $destination = [System.IO.FileStream]::new($backup,[System.IO.FileMode]::CreateNew,[System.IO.FileAccess]::Write,[System.IO.FileShare]::None)
        $buffer = New-Object byte[] 1048576
        $copied = [long]0
        while (($read = $source.Read($buffer,0,$buffer.Length)) -gt 0) {
            $destination.Write($buffer,0,$read)
            $copied += $read
        }
        if ($copied -ne $p0Length -or $source.Position -ne $p0Length -or $source.ReadByte() -ne -1) {
            throw 'BK-PA source count/position/EOF mismatch'
        }
        if ($destination.Position -ne $p0Length -or $destination.Length -ne $p0Length) {
            throw 'BK-PA destination position/length mismatch'
        }
        $destination.Flush($true)
        $p0TicksDuring = [long][System.IO.File]::GetLastWriteTimeUtc($canonical).Ticks
        if ($p0TicksDuring -ne $p0TicksBefore) { throw 'BK-PA canonical timestamp changed during exclusive copy' }
        $expectedP0 = [pscustomobject][ordered]@{
            FullPath=$canonical;Length=$p0Length;LastWriteTimeUtcTicks=$p0TicksBefore;SHA256=$p0Sha
        }
    } finally {
        if ($null -ne $destination) { $destination.Dispose() }
        if ($null -ne $source) { $source.Dispose() }
    }

    $closedP0BeforeTimestamp = Get-UID0002PAExclusiveTuple $canonical
    Assert-UID0002PATuple $closedP0BeforeTimestamp $expectedP0 'BK-PA closed P0 before timestamp'
    $closedB0BeforeTimestamp = Get-UID0002PAExclusiveTuple $backup
    if ($closedB0BeforeTimestamp.FullPath -ieq $closedP0BeforeTimestamp.FullPath -or
        $closedB0BeforeTimestamp.Length -ne $closedP0BeforeTimestamp.Length -or
        $closedB0BeforeTimestamp.SHA256 -cne $closedP0BeforeTimestamp.SHA256) {
        throw 'BK-PA closed B0 content parity failed before timestamp normalization'
    }

    [System.IO.File]::SetLastWriteTimeUtc($backup,[DateTime]::new([long]$expectedP0.LastWriteTimeUtcTicks,[DateTimeKind]::Utc))
    $closedP0 = Get-UID0002PAExclusiveTuple $canonical
    Assert-UID0002PATuple $closedP0 $expectedP0 'BK-PA unchanged P0 after timestamp'
    $expectedB0 = [pscustomobject][ordered]@{
        FullPath=$backup;Length=$expectedP0.Length
        LastWriteTimeUtcTicks=$expectedP0.LastWriteTimeUtcTicks;SHA256=$expectedP0.SHA256
    }
    $closedB0 = Get-UID0002PAExclusiveTuple $backup
    Assert-UID0002PATuple $closedB0 $expectedB0 'BK-PA complete B0'
    [pscustomobject][ordered]@{P0=Get-UID0002PATupleCopy $closedP0;B0=Get-UID0002PATupleCopy $closedB0}
}

function Get-UID0002PATextSha256 {
    param([Parameter(Mandatory=$true)][string]$Text)
    $sha=[Security.Cryptography.SHA256]::Create()
    try { ([BitConverter]::ToString($sha.ComputeHash([Text.Encoding]::UTF8.GetBytes($Text)))).Replace('-','') }
    finally { $sha.Dispose() }
}

function Get-UID0002PAEvidenceHmac {
    param([Parameter(Mandatory=$true)][string]$Text,[Parameter(Mandatory=$true)][string]$EvidenceKey)
    if($EvidenceKey -notmatch '^[0-9a-f]{64}$'){throw 'CT-PA invalid controller evidence key'}
    $keyBytes=New-Object byte[] ($EvidenceKey.Length/2)
    for($i=0;$i -lt $keyBytes.Length;$i++){$keyBytes[$i]=[Convert]::ToByte($EvidenceKey.Substring($i*2,2),16)}
    $hmac=[Security.Cryptography.HMACSHA256]::new($keyBytes)
    try{([BitConverter]::ToString($hmac.ComputeHash([Text.Encoding]::UTF8.GetBytes($Text)))).Replace('-','')}
    finally{$hmac.Dispose()}
}

function Get-UID0002PAAttemptSeal {
    param([Parameter(Mandatory=$true)]$Attempt)
    $projection=[ordered]@{
        TransactionId=[string]$Attempt.TransactionId;AttemptId=$Attempt.AttemptId
        AttemptIdType=[string]$Attempt.AttemptIdType;Database=[string]$Attempt.Database
        TransactionGeneration=[string]$Attempt.TransactionGeneration
        CanonicalPath=[string]$Attempt.CanonicalPath;SaveRequestSHA256=[string]$Attempt.SaveRequestSHA256
        DispatchCount=[int]$Attempt.DispatchCount;TransportClass=[string]$Attempt.TransportClass
        RawResponseSHA256=[string]$Attempt.RawResponseSHA256
        ResponseValidationFailure=[string]$Attempt.ResponseValidationFailure
        DiskClass=[string]$Attempt.DiskClass;Status=[string]$Attempt.Status
        P0=$Attempt.P0;B0=$Attempt.B0;AttributableTuple=$Attempt.AttributableTuple
    }
    Get-UID0002PATextSha256 ($projection | ConvertTo-Json -Depth 20 -Compress)
}

function Set-UID0002PAAttemptSeal {
    param([Parameter(Mandatory=$true)]$Attempt)
    $Attempt.AuthoritySeal = Get-UID0002PAAttemptSeal $Attempt
}

function Assert-UID0002PAAttemptSeal {
    param([Parameter(Mandatory=$true)]$Attempt)
    if ([string]::IsNullOrWhiteSpace([string]$Attempt.AuthoritySeal) -or
        [string]$Attempt.AuthoritySeal -cne (Get-UID0002PAAttemptSeal $Attempt)) {
        throw 'SV-PA save-attempt authority seal mismatch'
    }
}

function New-UID0002PASaveAttempt {
    param(
        [Parameter(Mandatory=$true)]$TransactionState,
        [Parameter(Mandatory=$true)]$RoleBinding,
        [Parameter(Mandatory=$true)]$BackupState,
        [Parameter(Mandatory=$true)]$FinalReadback,
        [Parameter(Mandatory=$true)]$FinalAttestation,
        [Parameter(Mandatory=$true)][string]$MaterializedSaveRequestJson)

    if([string]$RoleBinding.Role -cne 'Transaction' -or $TransactionState.SaveAttemptCreated -eq $true -or
        [int]$TransactionState.SaveDispatchCount -ne 0){throw 'SV-PA transaction already owns save authority'}
    if ($FinalReadback.Passed -ne $true -or [string]$FinalReadback.Phase -cne 'Final' -or
        [string]$FinalReadback.Role -cne 'Transaction' -or
        [string]$FinalReadback.Database -cne [string]$RoleBinding.Database -or
        $FinalAttestation.Passed -ne $true -or [string]$FinalAttestation.Role -cne 'Transaction' -or
        [string]$FinalAttestation.Database -cne [string]$RoleBinding.Database -or
        [string]$FinalReadback.WorkerGeneration -cne [string]$FinalAttestation.RoleWorker.Generation -or
        [string]$RoleBinding.Database -cne [string]$TransactionState.TransactionDatabase -or
        [string]$FinalAttestation.RoleWorker.Generation -cne [string]$TransactionState.TransactionGeneration) {
        throw 'SV-PA Final readback authority missing'
    }
    if ((@($FinalAttestation.ActiveDatabases) -join '|') -cne [string]$RoleBinding.Database) {
        throw 'SV-PA transaction role is not the sole active database'
    }
    $requestIdentity=Get-UID0002PARequestIdentity $MaterializedSaveRequestJson 'SV-PA idb_save'
    $request=$requestIdentity.Parsed
    if ([string]$request.params.name -cne 'idb_save' -or
        [string]$request.params.arguments.database -cne [string]$RoleBinding.Database -or
        [System.IO.Path]::GetFullPath([string]$request.params.arguments.path) -ine [string]$RoleBinding.CanonicalPath -or
        (@($request.params.arguments.PSObject.Properties.Name | Sort-Object) -join '|') -cne 'database|path' -or
        $MaterializedSaveRequestJson -match '__[A-Z0-9_]+__|<[^>]+>') {
        throw 'SV-PA sole save request mismatch'
    }
    $TransactionState.SaveAttemptCreated=$true
    $TransactionState.SaveAttemptId=$request.id
    $TransactionState.SaveRequestSHA256=$requestIdentity.SHA256
    $attempt=[pscustomobject][ordered]@{
        TransactionId=[string]$TransactionState.TransactionId
        AttemptId=$request.id;AttemptIdType=$request.id.GetType().FullName
        Database=[string]$RoleBinding.Database
        TransactionGeneration=[string]$FinalAttestation.RoleWorker.Generation
        CanonicalPath=[string]$RoleBinding.CanonicalPath
        SaveRequestJson=$MaterializedSaveRequestJson
        SaveRequestSHA256=$requestIdentity.SHA256
        DispatchCount=0;TransportClass='NotDispatched';RawResponseJson=$null;RawResponseSHA256=$null
        ResponseValidationFailure=$null
        DiskClass='Unclassified';Status='PREPARED'
        P0=Get-UID0002PATupleCopy $BackupState.P0
        B0=Get-UID0002PATupleCopy $BackupState.B0
        AttributableTuple=$null;AuthoritySeal=$null
    }
    Set-UID0002PAAttemptSeal $attempt
    return $attempt
}

function Register-UID0002PASoleSaveDispatch {
    param([Parameter(Mandatory=$true)]$TransactionState,[Parameter(Mandatory=$true)]$Attempt)
    Assert-UID0002PAAttemptSeal $Attempt
    if([string]$Attempt.TransactionId -cne [string]$TransactionState.TransactionId -or
        $TransactionState.SaveAttemptCreated -ne $true -or
        -not [object]::Equals($TransactionState.SaveAttemptId,$Attempt.AttemptId) -or
        [string]$TransactionState.SaveRequestSHA256 -cne [string]$Attempt.SaveRequestSHA256 -or
        [int]$TransactionState.SaveDispatchCount -ne 0 -or
        $Attempt.Status -cne 'PREPARED' -or [int]$Attempt.DispatchCount -ne 0) {
        throw 'SV-PA transaction-global save retry/duplicate dispatch'
    }
    $TransactionState.SaveDispatchCount=1
    $Attempt.DispatchCount=1
    $Attempt.Status='DISPATCHED'
    Set-UID0002PAAttemptSeal $Attempt
    return [string]$Attempt.SaveRequestJson
}

function Complete-UID0002PASaveTransport {
    param(
        [Parameter(Mandatory=$true)]$Attempt,
        [Parameter(Mandatory=$true)][ValidateSet('Response','Timeout','Disconnect','Malformed')][string]$ObservedTransport,
        [AllowNull()][string]$RawResponseJson)

    Assert-UID0002PAAttemptSeal $Attempt
    if ($Attempt.Status -cne 'DISPATCHED' -or [int]$Attempt.DispatchCount -ne 1) { throw 'SV-PA transport classification out of order' }
    $Attempt.RawResponseJson=$RawResponseJson
    $Attempt.RawResponseSHA256=if($null -eq $RawResponseJson){$null}else{Get-UID0002PATextSha256 $RawResponseJson}
    if ($ObservedTransport -in @('Timeout','Disconnect','Malformed')) {
        $Attempt.TransportClass='Indeterminate'
    } else {
        try {
            $response=$RawResponseJson | ConvertFrom-Json -ErrorAction Stop
            $save=Assert-UID0002PAJsonRpcResponse -Envelope $response -RequestJson $Attempt.SaveRequestJson -Label 'SV-PA idb_save response' -RequireStructuredContent $true
        }
        catch {
            $Attempt.TransportClass='Indeterminate'
            $Attempt.ResponseValidationFailure=$_.Exception.Message
            $Attempt.Status='TRANSPORT_CLASSIFIED'
            Set-UID0002PAAttemptSeal $Attempt
            return $Attempt
        }
        if ($save.ok -eq $true -and [string]::IsNullOrWhiteSpace([string]$save.error) -and
            [System.IO.Path]::GetFullPath([string]$save.path) -ieq [string]$Attempt.CanonicalPath) {
            $Attempt.TransportClass='DeterminateSuccess'
        } else { $Attempt.TransportClass='DeterminateFailure' }
    }
    $Attempt.Status='TRANSPORT_CLASSIFIED'
    Set-UID0002PAAttemptSeal $Attempt
    return $Attempt
}

function Get-UID0002PARetirementProofSeal {
    param([Parameter(Mandatory=$true)]$Proof)
    $projection=[ordered]@{
        Role=[string]$Proof.Role;Database=[string]$Proof.Database;Generation=[string]$Proof.Generation
        RedirectorPid=[int]$Proof.RedirectorPid;WorkerPid=[int]$Proof.WorkerPid
        PreCloseAttestationRequestId=$Proof.PreCloseAttestationRequestId
        PostCloseAttestationRequestId=$Proof.PostCloseAttestationRequestId
        PostCloseListRequestId=$Proof.PostCloseListRequestId
        PostCloseAttestationRequestSHA256=[string]$Proof.PostCloseAttestationRequestSHA256
        PostCloseListRequestSHA256=[string]$Proof.PostCloseListRequestSHA256
        PostCloseListenerGeneration=[string]$Proof.PostCloseListenerGeneration
        PostCloseSurvivingSessionsSHA256=[string]$Proof.PostCloseSurvivingSessionsSHA256
        RetirementActionSHA256=[string]$Proof.RetirementActionSHA256
        RetirementResultSHA256=[string]$Proof.RetirementResultSHA256
        ClosedTupleA=$Proof.ClosedTupleA;ClosedTupleB=$Proof.ClosedTupleB
    }
    Get-UID0002PATextSha256 ($projection|ConvertTo-Json -Depth 20 -Compress)
}

function Assert-UID0002PARetirementProof {
    param([Parameter(Mandatory=$true)]$Proof)
    if([string]::IsNullOrWhiteSpace([string]$Proof.ProofSeal) -or
        [string]$Proof.ProofSeal -cne (Get-UID0002PARetirementProofSeal $Proof)){
        throw 'SV-PA retirement proof seal mismatch'
    }
}

function Assert-UID0002PAVerifierIdentity {
    param(
        [Parameter(Mandatory=$true)]$TransactionState,
        [Parameter(Mandatory=$true)][ValidateSet('P0Verifier','S1Verifier','RollbackVerifier')][string]$ExpectedRole,
        [Parameter(Mandatory=$true)]$RoleBinding,
        [Parameter(Mandatory=$true)]$Readback,
        [Parameter(Mandatory=$true)]$RuntimeProof,
        [Parameter(Mandatory=$true)]$RetirementProof)
    Assert-UID0002PARetirementProof $RetirementProof
    $db=[string]$RoleBinding.Database
    $worker=$TransactionState.RoleWorkers[$db]
    if($null -eq $worker -or $Readback.Passed -ne $true -or $RuntimeProof.Passed -ne $true -or
        [string]$RoleBinding.Role -cne $ExpectedRole -or
        [string]$Readback.Role -cne $ExpectedRole -or [string]$RuntimeProof.Role -cne $ExpectedRole -or
        [string]$RetirementProof.Role -cne $ExpectedRole -or
        [string]$Readback.Database -cne $db -or [string]$RuntimeProof.Database -cne $db -or
        [string]$RetirementProof.Database -cne $db -or $db -ceq [string]$TransactionState.TransactionDatabase -or
        [string]$Readback.WorkerGeneration -cne [string]$worker.Generation -or
        [string]$RuntimeProof.WorkerGeneration -cne [string]$worker.Generation -or
        [string]$RetirementProof.Generation -cne [string]$worker.Generation -or
        [string]$worker.Generation -ceq [string]$TransactionState.TransactionGeneration){
        throw "VR-PA $ExpectedRole database/role/generation/retirement mismatch"
    }
}

function Invoke-UID0002PAExactGenerationRetirementAction {
    param(
        [Parameter(Mandatory=$true)]$RoleBinding,
        [Parameter(Mandatory=$true)]$AttestationState,
        [Parameter(Mandatory=$true)]$PreCloseRuntimeProof,
        [Parameter(Mandatory=$true)][scriptblock]$RetireExactGeneration)
    $identity=$AttestationState.RoleWorkers[[string]$RoleBinding.Database]
    if($null -eq $identity -or $PreCloseRuntimeProof.Passed -ne $true -or
        [string]$PreCloseRuntimeProof.Role -cne [string]$RoleBinding.Role -or
        [string]$PreCloseRuntimeProof.Database -cne [string]$RoleBinding.Database -or
        [string]$PreCloseRuntimeProof.WorkerGeneration -cne [string]$identity.Generation){
        throw 'RT-PA exact-generation retirement prestate mismatch'
    }
    $action=[pscustomobject][ordered]@{
        Action='RETIRE_EXACT_GENERATION';Role=[string]$RoleBinding.Role;Database=[string]$RoleBinding.Database
        WorkerGeneration=[string]$identity.Generation;RedirectorGeneration=[string]$identity.RedirectorGeneration
        RedirectorPid=[int]$identity.RedirectorPid;WorkerPid=[int]$identity.WorkerPid
        RoutePort=[int]$identity.RoutePort;PreserveListener=$true;CanonicalPath=[string]$RoleBinding.CanonicalPath
    }
    $result=& $RetireExactGeneration $action
    if($null -eq $result -or $result.Retired -ne $true -or $result.ListenerPreserved -ne $true -or
        [string]$result.Action -cne [string]$action.Action -or [string]$result.Role -cne [string]$action.Role -or
        [string]$result.Database -cne [string]$action.Database -or
        [string]$result.WorkerGeneration -cne [string]$action.WorkerGeneration -or
        [string]$result.RedirectorGeneration -cne [string]$action.RedirectorGeneration -or
        [int]$result.RedirectorPid -ne [int]$action.RedirectorPid -or [int]$result.WorkerPid -ne [int]$action.WorkerPid){
        throw 'RT-PA retirement action did not prove exact requested generation'
    }
    $pidResults=@()
    foreach($roleProcess in @(
        [pscustomobject]@{Pid=[int]$identity.RedirectorPid;Generation=[string]$identity.RedirectorGeneration},
        [pscustomobject]@{Pid=[int]$identity.WorkerPid;Generation=[string]$identity.Generation})){
        $pid=[int]$roleProcess.Pid
        $expectedCreated=[long](([regex]::Match([string]$roleProcess.Generation,'created:([0-9]+)$')).Groups[1].Value)
        if($expectedCreated -le 0){throw 'RT-PA invalid attested generation text'}
        $disposition=$null
        for($attempt=0;$attempt -lt 60;$attempt++){
            $process=@(Get-CimInstance Win32_Process -Filter "ProcessId=$pid" -ErrorAction Stop)
            if($process.Count -eq 0){$disposition='Absent';break}
            if($process.Count -ne 1){throw "RT-PA ambiguous PID state $pid"}
            $actualCreated=[DateTime]$process[0].CreationDate
            $actualCreated100ns=$actualCreated.ToUniversalTime().ToFileTimeUtc()
            if($actualCreated100ns -ne $expectedCreated){$disposition='ReusedDifferentGeneration';break}
            Start-Sleep -Milliseconds 250
        }
        if($null -eq $disposition){throw "RT-PA exact retired generation survived timeout $pid"}
        $sockets=@(Get-NetTCPConnection -State Listen -ErrorAction Stop|Where-Object{[int]$_.OwningProcess -eq $pid})
        if($sockets.Count -ne 0){throw "RT-PA absent/reused PID owns listener $pid"}
        $pidResults+=[pscustomobject][ordered]@{Pid=$pid;ExpectedCreated100ns=$expectedCreated;Disposition=$disposition}
    }
    [pscustomobject][ordered]@{
        Action=$action;Result=$result;PidResults=$pidResults
        ActionSHA256=Get-UID0002PATextSha256 ($action|ConvertTo-Json -Depth 12 -Compress)
        ResultSHA256=Get-UID0002PATextSha256 ($result|ConvertTo-Json -Depth 12 -Compress)
        Passed=$true
    }
}

function Assert-UID0002PARoleRetired {
    param(
        [Parameter(Mandatory=$true)]$RoleBinding,
        [Parameter(Mandatory=$true)]$AttestationState,
        [Parameter(Mandatory=$true)]$PreCloseRuntimeProof,
        [Parameter(Mandatory=$true)]$RetirementActionEvidence,
        [Parameter(Mandatory=$true)]$PostAttestationEnvelope,
        [Parameter(Mandatory=$true)][string]$PostAttestationRequestJson,
        [Parameter(Mandatory=$true)]$ListEnvelope,
        [Parameter(Mandatory=$true)][string]$ListRequestJson)

    $identity=$AttestationState.RoleWorkers[[string]$RoleBinding.Database]
    if ($null -eq $identity) { throw 'SV-PA missing attested role worker identity' }
    if($PreCloseRuntimeProof.Passed -ne $true -or [string]$PreCloseRuntimeProof.Role -cne [string]$RoleBinding.Role -or
        [string]$PreCloseRuntimeProof.Database -cne [string]$RoleBinding.Database -or
        [string]$PreCloseRuntimeProof.WorkerGeneration -cne [string]$identity.Generation){
        throw 'SV-PA pre-close runtime identity mismatch'
    }
    if($RetirementActionEvidence.Passed -ne $true -or
        [string]$RetirementActionEvidence.Action.Action -cne 'RETIRE_EXACT_GENERATION' -or
        [string]$RetirementActionEvidence.Action.Role -cne [string]$RoleBinding.Role -or
        [string]$RetirementActionEvidence.Action.Database -cne [string]$RoleBinding.Database -or
        [string]$RetirementActionEvidence.Action.WorkerGeneration -cne [string]$identity.Generation -or
        [string]$RetirementActionEvidence.Action.RedirectorGeneration -cne [string]$identity.RedirectorGeneration -or
        [int]$RetirementActionEvidence.Action.RedirectorPid -ne [int]$identity.RedirectorPid -or
        [int]$RetirementActionEvidence.Action.WorkerPid -ne [int]$identity.WorkerPid -or
        @($RetirementActionEvidence.PidResults).Count -ne 2 -or
        @($RetirementActionEvidence.PidResults|Where-Object{$_.Disposition -notin @('Absent','ReusedDifferentGeneration')}).Count -ne 0){
        throw 'SV-PA exact-generation retirement action evidence mismatch'
    }
    $post=Assert-UID0002PAPostRetirementAttestation -Envelope $PostAttestationEnvelope -RequestJson $PostAttestationRequestJson -RoleBinding $RoleBinding -State $AttestationState
    $list=Get-UID0002PAStructuredContent -Envelope $ListEnvelope -RequestJson $ListRequestJson -Label 'retirement idb_list'
    $activeList=@($list.sessions|Where-Object{$_.is_active -eq $true}|Sort-Object session_id)
    $postSessions=@($post.SurvivingSessions|Sort-Object Database)
    if($activeList.Count -ne $postSessions.Count){throw 'SV-PA post-retirement public/list active-session count mismatch'}
    for($i=0;$i -lt $activeList.Count;$i++){
        if([string]$activeList[$i].session_id -cne [string]$postSessions[$i].Database -or
            [System.IO.Path]::GetFullPath([string]$activeList[$i].input_path) -ine [string]$postSessions[$i].CanonicalPath -or
            [int]$activeList[$i].worker_pid -ne [int]$postSessions[$i].RedirectorPid){
            throw "SV-PA post-retirement public/list route mismatch at index $i"
        }
    }
    $rows=@($list.sessions | Where-Object {[string]$_.session_id -ceq [string]$RoleBinding.Database})
    if ($rows.Count -gt 1 -or ($rows.Count -eq 1 -and
        ($rows[0].is_active -ne $false -or [int]$rows[0].worker_pid -ne [int]$identity.RedirectorPid))) {
        throw 'SV-PA role row is not absent/exact inactive route'
    }
    foreach ($pid in @([int]$identity.RedirectorPid,[int]$identity.WorkerPid)) {
        $expected=@($RetirementActionEvidence.PidResults|Where-Object{[int]$_.Pid -eq $pid})
        if($expected.Count -ne 1){throw "SV-PA missing PID retirement disposition: $pid"}
        $process=@(Get-CimInstance Win32_Process -Filter "ProcessId=$pid" -ErrorAction Stop)
        if([string]$expected[0].Disposition -ceq 'Absent'){
            if($process.Count -ne 0){throw "SV-PA retired PID unexpectedly exists: $pid"}
        }else{
            if($process.Count -ne 1){throw "SV-PA reused PID state is not singular: $pid"}
            $created=([DateTime]$process[0].CreationDate).ToUniversalTime().ToFileTimeUtc()
            if($created -eq [long]$expected[0].ExpectedCreated100ns){throw "SV-PA exact retired generation still exists: $pid"}
        }
        if (@(Get-NetTCPConnection -State Listen -ErrorAction Stop | Where-Object {[int]$_.OwningProcess -eq $pid}).Count -ne 0) {
            throw "SV-PA retired PID still owns listener: $pid"
        }
    }
    if (@($list.sessions | Where-Object {
        $_.is_active -eq $true -and
        [System.IO.Path]::GetFullPath([string]$_.input_path) -ieq [string]$RoleBinding.CanonicalPath
    }).Count -ne 0) { throw 'SV-PA active canonical session remains' }
    $first=Get-UID0002PAExclusiveTuple $RoleBinding.CanonicalPath
    $second=Get-UID0002PAExclusiveTuple $RoleBinding.CanonicalPath
    Assert-UID0002PATuple $second $first 'SV-PA stable closed disk'
    $proof=[pscustomobject][ordered]@{
        Role=[string]$RoleBinding.Role
        Database=[string]$RoleBinding.Database
        Generation=[string]$identity.Generation
        ClosedTupleA=Get-UID0002PATupleCopy $first
        ClosedTupleB=Get-UID0002PATupleCopy $second
        RedirectorPid=[int]$identity.RedirectorPid
        WorkerPid=[int]$identity.WorkerPid
        PreCloseAttestationRequestId=$PreCloseRuntimeProof.AttestationRequestId
        PostCloseAttestationRequestId=$post.RequestId
        PostCloseListRequestId=(Get-UID0002PARequestIdentity $ListRequestJson 'retirement idb_list').Id
        PostCloseAttestationRequestSHA256=(Get-UID0002PARequestIdentity $PostAttestationRequestJson 'retirement post attestation').SHA256
        PostCloseListRequestSHA256=(Get-UID0002PARequestIdentity $ListRequestJson 'retirement idb_list').SHA256
        PostCloseListenerGeneration=[string]$post.ListenerGeneration
        PostCloseSurvivingSessionsSHA256=Get-UID0002PATextSha256 (($postSessions|ConvertTo-Json -Depth 12 -Compress))
        RetirementActionSHA256=[string]$RetirementActionEvidence.ActionSHA256
        RetirementResultSHA256=[string]$RetirementActionEvidence.ResultSHA256
        ProofSeal=$null
    }
    $proof.ProofSeal=Get-UID0002PARetirementProofSeal $proof
    return $proof
}

function Complete-UID0002PADiskClassification {
    param([Parameter(Mandatory=$true)]$Attempt,[Parameter(Mandatory=$true)]$RetirementProof)
    Assert-UID0002PAAttemptSeal $Attempt
    Assert-UID0002PARetirementProof $RetirementProof
    if ($Attempt.Status -cne 'TRANSPORT_CLASSIFIED' -or [int]$Attempt.DispatchCount -ne 1) { throw 'SV-PA disk classification out of order' }
    Assert-UID0002PATuple $RetirementProof.ClosedTupleB $RetirementProof.ClosedTupleA 'SV-PA stable post-save disk'
    if ([string]$RetirementProof.Role -cne 'Transaction' -or
        [string]$RetirementProof.Database -cne [string]$Attempt.Database -or
        [string]$RetirementProof.Generation -cne [string]$Attempt.TransactionGeneration) {
        throw 'SV-PA retirement role/database/generation mismatch'
    }

    $candidate=$RetirementProof.ClosedTupleA
    $isP0=$true
    foreach ($property in 'FullPath','Length','LastWriteTimeUtcTicks','SHA256') {
        if ([string]$candidate.$property -cne [string]$Attempt.P0.$property) { $isP0=$false }
    }
    if ($isP0) {
        $Attempt.DiskClass='P0'
        $Attempt.Status='P0_VERIFIER_REQUIRED'
    } else {
        if ([System.IO.Path]::GetFullPath([string]$candidate.FullPath) -ine [string]$Attempt.CanonicalPath) {
            throw 'SV-PA changed tuple is not canonical'
        }
        $Attempt.AttributableTuple=Get-UID0002PATupleCopy $candidate
        $Attempt.DiskClass='SOLE_SAVE_ATTRIBUTABLE_S1_OR_F1'
        $Attempt.Status='S1_VERIFIER_REQUIRED'
    }
    Set-UID0002PAAttemptSeal $Attempt
    return [pscustomobject][ordered]@{
        TransportClass=[string]$Attempt.TransportClass
        DiskClass=[string]$Attempt.DiskClass
        RequiredVerifier=if($Attempt.Status -ceq 'P0_VERIFIER_REQUIRED'){'P0Verifier'}else{'S1Verifier'}
    }
}

function Complete-UID0002PAPreSaveFailure {
    param(
        [Parameter(Mandatory=$true)]$TransactionState,
        [Parameter(Mandatory=$true)]$BackupState,
        [Parameter(Mandatory=$true)]$RetirementProof,
        [Parameter(Mandatory=$true)][string]$ExactFailure)
    Assert-UID0002PARetirementProof $RetirementProof
    if([int]$TransactionState.SaveDispatchCount -ne 0 -or
        [string]$TransactionState.NoSaveStatus -cne 'PRE_SAVE' -or
        [string]::IsNullOrWhiteSpace($ExactFailure) -or
        [string]$RetirementProof.Role -cne 'Transaction' -or
        [string]$RetirementProof.Database -cne [string]$TransactionState.TransactionDatabase -or
        [string]$RetirementProof.Generation -cne [string]$TransactionState.TransactionGeneration){
        throw 'pre-save failure state/identity mismatch'
    }
    Assert-UID0002PATuple $RetirementProof.ClosedTupleA $BackupState.P0 'pre-save failure disk P0'
    Assert-UID0002PATuple $RetirementProof.ClosedTupleB $BackupState.P0 'pre-save failure stable P0'
    Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $BackupState.B0.FullPath) $BackupState.B0 'pre-save failure intact B0'
    $TransactionState.NoSaveP0=Get-UID0002PATupleCopy $BackupState.P0
    $TransactionState.NoSaveB0=Get-UID0002PATupleCopy $BackupState.B0
    $TransactionState.NoSaveFailure=$ExactFailure
    $TransactionState.NoSaveStatus='PRE_SAVE_P0_VERIFIER_REQUIRED'
    return $TransactionState
}

function Complete-UID0002PAPreSaveP0Verifier {
    param(
        [Parameter(Mandatory=$true)]$TransactionState,
        [Parameter(Mandatory=$true)]$VerifierRoleBinding,
        [Parameter(Mandatory=$true)]$VerifierReadback,
        [Parameter(Mandatory=$true)]$VerifierRuntimeProof,
        [Parameter(Mandatory=$true)]$VerifierRetirementProof)
    if([string]$TransactionState.NoSaveStatus -cne 'PRE_SAVE_P0_VERIFIER_REQUIRED' -or
        $TransactionState.SaveAttemptCreated -eq $true -or [int]$TransactionState.SaveDispatchCount -ne 0 -or
        [string]::IsNullOrWhiteSpace([string]$TransactionState.NoSaveFailure) -or
        $null -eq $TransactionState.NoSaveP0 -or $null -eq $TransactionState.NoSaveB0 -or
        $VerifierReadback.Passed -ne $true -or [string]$VerifierReadback.Phase -cne 'P0Verifier'){
        throw 'pre-save P0 verifier state mismatch'
    }
    Assert-UID0002PAVerifierIdentity -TransactionState $TransactionState -ExpectedRole P0Verifier -RoleBinding $VerifierRoleBinding -Readback $VerifierReadback -RuntimeProof $VerifierRuntimeProof -RetirementProof $VerifierRetirementProof
    Assert-UID0002PATuple $VerifierRetirementProof.ClosedTupleA $TransactionState.NoSaveP0 'pre-save P0 verifier closed disk'
    Assert-UID0002PATuple $VerifierRetirementProof.ClosedTupleB $TransactionState.NoSaveP0 'pre-save P0 verifier stable disk'
    Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $TransactionState.NoSaveB0.FullPath) $TransactionState.NoSaveB0 'pre-save P0 verifier B0'
    $TransactionState.NoSaveStatus='PRE_SAVE_ABORTED_P0_VERIFIED'
    return $TransactionState
}

function Complete-UID0002PAVerifier {
    param(
        [Parameter(Mandatory=$true)]$TransactionState,
        [Parameter(Mandatory=$true)]$Attempt,
        [Parameter(Mandatory=$true)]$VerifierRoleBinding,
        [Parameter(Mandatory=$true)]$VerifierReadback,
        [Parameter(Mandatory=$true)]$VerifierRuntimeProof,
        [Parameter(Mandatory=$true)]$VerifierRetirementProof)

    Assert-UID0002PAAttemptSeal $Attempt
    if ($VerifierReadback.Passed -ne $true) { throw 'VR-PA verifier catalog did not pass' }
    if ($Attempt.Status -ceq 'P0_VERIFIER_REQUIRED') {
        if ([string]$VerifierReadback.Phase -cne 'P0Verifier') { throw 'VR-PA wrong P0 verifier phase' }
        Assert-UID0002PAVerifierIdentity -TransactionState $TransactionState -ExpectedRole P0Verifier -RoleBinding $VerifierRoleBinding -Readback $VerifierReadback -RuntimeProof $VerifierRuntimeProof -RetirementProof $VerifierRetirementProof
        Assert-UID0002PATuple $VerifierRetirementProof.ClosedTupleA $Attempt.P0 'VR-PA P0 verifier closed disk'
        Assert-UID0002PATuple $VerifierRetirementProof.ClosedTupleB $Attempt.P0 'VR-PA P0 verifier stable disk'
        $Attempt.Status="NOT_PERSISTED_P0_VERIFIED_$($Attempt.TransportClass.ToUpperInvariant())"
    } elseif ($Attempt.Status -ceq 'S1_VERIFIER_REQUIRED') {
        if ([string]$VerifierReadback.Phase -cne 'S1Verifier' -or $null -eq $Attempt.AttributableTuple) {
            throw 'VR-PA wrong/missing S1 verifier authority'
        }
        Assert-UID0002PAVerifierIdentity -TransactionState $TransactionState -ExpectedRole S1Verifier -RoleBinding $VerifierRoleBinding -Readback $VerifierReadback -RuntimeProof $VerifierRuntimeProof -RetirementProof $VerifierRetirementProof
        Assert-UID0002PATuple $VerifierRetirementProof.ClosedTupleA $Attempt.AttributableTuple 'VR-PA S1 verifier closed disk'
        Assert-UID0002PATuple $VerifierRetirementProof.ClosedTupleB $Attempt.AttributableTuple 'VR-PA S1 verifier stable disk'
        $Attempt.Status="PERSISTED_S1_VERIFIED_$($Attempt.TransportClass.ToUpperInvariant())"
    } else { throw 'VR-PA verifier called from invalid branch' }
    Set-UID0002PAAttemptSeal $Attempt
    return $Attempt
}

function New-UID0002PAFailedVerifierEvidence {
    param(
        [Parameter(Mandatory=$true)]$Requests,
        [Parameter(Mandatory=$true)]$Responses,
        [Parameter(Mandatory=$true)]$RoleBinding,
        [Parameter(Mandatory=$true)]$AttestationState,
        [Parameter(Mandatory=$true)][string]$ControllerEvidenceKey)
    if([string]$RoleBinding.Role -cne 'S1Verifier'){throw 'VR-PA failed readback is not S1Verifier'}
    $expected=New-UID0002PAReadbackCatalog -RoleBinding $RoleBinding -Phase S1Verifier
    $required=@($expected.Keys)
    if((@($Requests.Keys|Sort-Object)-join '|') -cne (@($required|Sort-Object)-join '|') -or
        (@($Responses.Keys|Sort-Object)-join '|') -cne (@($required|Sort-Object)-join '|')){
        throw 'VR-PA failed readback catalog key mismatch'
    }
    foreach($key in $required){
        $actual=Get-UID0002PARequestIdentity ([string]$Requests[$key]) "VR-PA failed $key actual"
        $literal=Get-UID0002PARequestIdentity ([string]$expected[$key]) "VR-PA failed $key expected"
        if($actual.SHA256 -cne $literal.SHA256){throw "VR-PA failed readback request drift $key"}
        $null=Assert-UID0002PAJsonRpcResponse -Envelope $Responses[$key] -RequestJson ([string]$Requests[$key]) -Label "VR-PA failed $key correlation" -RequireStructuredContent $true
    }
    $failure=$null;$passedReadback=$null
    try{$passedReadback=Assert-UID0002PAReadbackCatalog -Requests $Requests -Responses $Responses -RoleBinding $RoleBinding -AttestationState $AttestationState -Phase S1Verifier}
    catch{$failure=$_.Exception.Message}
    if([string]::IsNullOrWhiteSpace([string]$failure)){
        return [pscustomobject][ordered]@{Passed=$true;Readback=$passedReadback;Role='S1Verifier';Database=[string]$RoleBinding.Database}
    }
    $requestProjection=[ordered]@{};$responseProjection=[ordered]@{}
    foreach($key in $required){
        $requestProjection[$key]=Get-UID0002PATextSha256 ([string]$Requests[$key])
        $responseProjection[$key]=Get-UID0002PATextSha256 (($Responses[$key]|ConvertTo-Json -Depth 30 -Compress))
    }
    $evidence=[pscustomobject][ordered]@{
        Passed=$false;Phase='S1Verifier';Role='S1Verifier';Database=[string]$RoleBinding.Database
        WorkerGeneration=[string]$AttestationState.RoleWorkers[[string]$RoleBinding.Database].Generation
        ExactFailure=[string]$failure;Requests=$Requests;Responses=$Responses
        RequestCatalogSHA256=Get-UID0002PATextSha256 ($requestProjection|ConvertTo-Json -Depth 12 -Compress)
        ResponseCatalogSHA256=Get-UID0002PATextSha256 ($responseProjection|ConvertTo-Json -Depth 12 -Compress)
        EvidenceSeal=$null
    }
    $projection=[ordered]@{Phase=$evidence.Phase;Role=$evidence.Role;Database=$evidence.Database;WorkerGeneration=$evidence.WorkerGeneration;ExactFailure=$evidence.ExactFailure;RequestCatalogSHA256=$evidence.RequestCatalogSHA256;ResponseCatalogSHA256=$evidence.ResponseCatalogSHA256}
    $evidence.EvidenceSeal=Get-UID0002PAEvidenceHmac ($projection|ConvertTo-Json -Compress) $ControllerEvidenceKey
    return $evidence
}

function Assert-UID0002PAFailedVerifierEvidence {
    param([Parameter(Mandatory=$true)]$Evidence,[Parameter(Mandatory=$true)]$RoleBinding,[Parameter(Mandatory=$true)][string]$ControllerEvidenceKey)
    if($Evidence.Passed -ne $false -or [string]$Evidence.Phase -cne 'S1Verifier' -or
        [string]$Evidence.Role -cne 'S1Verifier' -or [string]$Evidence.Database -cne [string]$RoleBinding.Database -or
        [string]::IsNullOrWhiteSpace([string]$Evidence.ExactFailure)){throw 'VR-PA retained failed verifier header mismatch'}
    $expected=New-UID0002PAReadbackCatalog -RoleBinding $RoleBinding -Phase S1Verifier
    $requestProjection=[ordered]@{};$responseProjection=[ordered]@{}
    foreach($key in @($expected.Keys)){
        $actual=Get-UID0002PARequestIdentity ([string]$Evidence.Requests[$key]) "VR-PA retained failed $key"
        $literal=Get-UID0002PARequestIdentity ([string]$expected[$key]) "VR-PA retained literal $key"
        if($actual.SHA256 -cne $literal.SHA256){throw "VR-PA retained failed request drift $key"}
        $null=Assert-UID0002PAJsonRpcResponse -Envelope $Evidence.Responses[$key] -RequestJson ([string]$Evidence.Requests[$key]) -Label "VR-PA retained failed $key correlation" -RequireStructuredContent $true
        $requestProjection[$key]=$actual.SHA256
        $responseProjection[$key]=Get-UID0002PATextSha256 (($Evidence.Responses[$key]|ConvertTo-Json -Depth 30 -Compress))
    }
    if([string]$Evidence.RequestCatalogSHA256 -cne (Get-UID0002PATextSha256 ($requestProjection|ConvertTo-Json -Depth 12 -Compress)) -or
        [string]$Evidence.ResponseCatalogSHA256 -cne (Get-UID0002PATextSha256 ($responseProjection|ConvertTo-Json -Depth 12 -Compress))){
        throw 'VR-PA retained failed verifier catalog seal mismatch'
    }
    $projection=[ordered]@{Phase=$Evidence.Phase;Role=$Evidence.Role;Database=$Evidence.Database;WorkerGeneration=$Evidence.WorkerGeneration;ExactFailure=$Evidence.ExactFailure;RequestCatalogSHA256=$Evidence.RequestCatalogSHA256;ResponseCatalogSHA256=$Evidence.ResponseCatalogSHA256}
    if([string]$Evidence.EvidenceSeal -cne (Get-UID0002PAEvidenceHmac ($projection|ConvertTo-Json -Compress) $ControllerEvidenceKey)){
        throw 'VR-PA failed verifier controller seal mismatch'
    }
}

function Set-UID0002PAVerifierFailure {
    param(
        [Parameter(Mandatory=$true)]$TransactionState,
        [Parameter(Mandatory=$true)]$Attempt,
        [Parameter(Mandatory=$true)]$VerifierRoleBinding,
        [Parameter(Mandatory=$true)]$FailedReadbackEvidence,
        [Parameter(Mandatory=$true)][string]$ControllerEvidenceKey,
        [Parameter(Mandatory=$true)]$VerifierRuntimeProof,
        [Parameter(Mandatory=$true)]$VerifierRetirementProof)
    Assert-UID0002PAAttemptSeal $Attempt
    if ($Attempt.Status -cne 'S1_VERIFIER_REQUIRED' -or $null -eq $Attempt.AttributableTuple -or
        $FailedReadbackEvidence.Passed -ne $false) { throw 'VR-PA invalid F1 transition' }
    Assert-UID0002PAFailedVerifierEvidence -Evidence $FailedReadbackEvidence -RoleBinding $VerifierRoleBinding -ControllerEvidenceKey $ControllerEvidenceKey
    Assert-UID0002PARetirementProof $VerifierRetirementProof
    $worker=$TransactionState.RoleWorkers[[string]$VerifierRoleBinding.Database]
    if($null -eq $worker -or [string]$VerifierRoleBinding.Role -cne 'S1Verifier' -or
        [string]$VerifierRoleBinding.Database -ceq [string]$TransactionState.TransactionDatabase -or
        [string]$VerifierRuntimeProof.Role -cne 'S1Verifier' -or
        [string]$VerifierRuntimeProof.Database -cne [string]$VerifierRoleBinding.Database -or
        [string]$VerifierRuntimeProof.WorkerGeneration -cne [string]$worker.Generation -or
        [string]$FailedReadbackEvidence.Database -cne [string]$VerifierRoleBinding.Database -or
        [string]$FailedReadbackEvidence.WorkerGeneration -cne [string]$worker.Generation -or
        [string]$VerifierRetirementProof.Role -cne 'S1Verifier' -or
        [string]$VerifierRetirementProof.Database -cne [string]$VerifierRoleBinding.Database -or
        [string]$VerifierRetirementProof.Generation -cne [string]$worker.Generation){
        throw 'VR-PA failed S1 verifier identity mismatch'
    }
    $fresh=Get-UID0002PAExclusiveTuple $Attempt.CanonicalPath
    Assert-UID0002PATuple $fresh $Attempt.AttributableTuple 'VR-PA F1 still sole-save attributable'
    $Attempt.Status='F1_RESTORE_REQUIRED'
    Set-UID0002PAAttemptSeal $Attempt
    return [pscustomobject]@{
        Status=$Attempt.Status;Failure=[string]$FailedReadbackEvidence.ExactFailure
        FailedReadbackRequestCatalogSHA256=[string]$FailedReadbackEvidence.RequestCatalogSHA256
        FailedReadbackResponseCatalogSHA256=[string]$FailedReadbackEvidence.ResponseCatalogSHA256
        AttributableTuple=Get-UID0002PATupleCopy $fresh
    }
}

function Restore-UID0002PABackup {
    param([Parameter(Mandatory=$true)]$Attempt)
    Assert-UID0002PAAttemptSeal $Attempt
    if ($Attempt.Status -cne 'F1_RESTORE_REQUIRED' -or $null -eq $Attempt.AttributableTuple) {
        throw 'RS-PA restore lacks internally classified F1 authority'
    }

    $freshCanonical=Get-UID0002PAExclusiveTuple $Attempt.CanonicalPath
    Assert-UID0002PATuple $freshCanonical $Attempt.AttributableTuple 'RS-PA immediate pre-restore attributable F1'
    Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $Attempt.B0.FullPath) $Attempt.B0 'RS-PA intact B0'

    $source=$null
    $destination=$null
    try {
        $source=[System.IO.FileStream]::new($Attempt.B0.FullPath,[System.IO.FileMode]::Open,[System.IO.FileAccess]::Read,[System.IO.FileShare]::None)
        $destination=[System.IO.FileStream]::new($Attempt.CanonicalPath,[System.IO.FileMode]::Open,[System.IO.FileAccess]::ReadWrite,[System.IO.FileShare]::None)
        if ($source.Length -ne $Attempt.P0.Length -or (Get-UID0002PAStreamSha256 $source) -cne $Attempt.P0.SHA256) {
            throw 'RS-PA exclusive B0 differs from P0'
        }
        if ($destination.Length -ne $Attempt.AttributableTuple.Length -or
            (Get-UID0002PAStreamSha256 $destination) -cne $Attempt.AttributableTuple.SHA256) {
            throw 'RS-PA exclusive canonical is third identity'
        }
        $source.Position=0
        $destination.SetLength(0)
        $destination.Position=0
        $buffer=New-Object byte[] 1048576
        $copied=[long]0
        while (($read=$source.Read($buffer,0,$buffer.Length)) -gt 0) {
            $destination.Write($buffer,0,$read)
            $copied += $read
        }
        if ($copied -ne $Attempt.P0.Length -or $source.Position -ne $Attempt.P0.Length -or $source.ReadByte() -ne -1) {
            throw 'RS-PA source count/position/EOF mismatch'
        }
        if ($destination.Position -ne $Attempt.P0.Length -or $destination.Length -ne $Attempt.P0.Length) {
            throw 'RS-PA destination position/length mismatch'
        }
        $destination.Flush($true)
    } finally {
        if ($null -ne $destination) { $destination.Dispose() }
        if ($null -ne $source) { $source.Dispose() }
    }
    [System.IO.File]::SetLastWriteTimeUtc(
        $Attempt.CanonicalPath,
        [DateTime]::new([long]$Attempt.P0.LastWriteTimeUtcTicks,[DateTimeKind]::Utc))
    Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $Attempt.CanonicalPath) $Attempt.P0 'RS-PA closed restored P0'
    Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $Attempt.CanonicalPath) $Attempt.P0 'RS-PA reopened restored P0'
    Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $Attempt.B0.FullPath) $Attempt.B0 'RS-PA post-restore B0'
    $Attempt.Status='ROLLBACK_VERIFIER_REQUIRED'
    Set-UID0002PAAttemptSeal $Attempt
    return $Attempt
}

function Complete-UID0002PARollbackVerifier {
    param(
        [Parameter(Mandatory=$true)]$TransactionState,
        [Parameter(Mandatory=$true)]$Attempt,
        [Parameter(Mandatory=$true)]$RollbackRoleBinding,
        [Parameter(Mandatory=$true)]$RollbackReadback,
        [Parameter(Mandatory=$true)]$RollbackRuntimeProof,
        [Parameter(Mandatory=$true)]$RollbackRetirementProof)

    Assert-UID0002PAAttemptSeal $Attempt
    if ($Attempt.Status -cne 'ROLLBACK_VERIFIER_REQUIRED' -or
        $RollbackReadback.Passed -ne $true -or [string]$RollbackReadback.Phase -cne 'RollbackVerifier') {
        throw 'RS-PA rollback verifier state mismatch'
    }
    Assert-UID0002PAVerifierIdentity -TransactionState $TransactionState -ExpectedRole RollbackVerifier -RoleBinding $RollbackRoleBinding -Readback $RollbackReadback -RuntimeProof $RollbackRuntimeProof -RetirementProof $RollbackRetirementProof
    Assert-UID0002PATuple $RollbackRetirementProof.ClosedTupleA $Attempt.P0 'RS-PA rollback verifier closed P0'
    Assert-UID0002PATuple $RollbackRetirementProof.ClosedTupleB $Attempt.P0 'RS-PA rollback verifier stable P0'
    Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $Attempt.CanonicalPath) $Attempt.P0 'RS-PA final closed P0 first'
    Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $Attempt.CanonicalPath) $Attempt.P0 'RS-PA final closed P0 second'
    $Attempt.Status="RESTORED_P0_VERIFIED_$($Attempt.TransportClass.ToUpperInvariant())"
    Set-UID0002PAAttemptSeal $Attempt
    return $Attempt
}

function New-UID0002PAClosedControllerContext {
    param([Parameter(Mandatory=$true)][scriptblock]$Transport,[Parameter(Mandatory=$true)][scriptblock]$RetireExactGeneration)
    $secret=New-Object object
    [pscustomobject][ordered]@{
        Secret=$secret;State=New-UID0002PAAttestationState;Transport=$Transport;RetireExactGeneration=$RetireExactGeneration
        EvidenceKey=([Guid]::NewGuid().ToString('N')+[Guid]::NewGuid().ToString('N'))
        RequestIds=[System.Collections.Generic.HashSet[string]]::new([System.StringComparer]::Ordinal)
        Transcript=[System.Collections.Generic.List[object]]::new();SaveSent=$false;Running=$true
    }
}

function Invoke-UID0002PAControllerRequest {
    param(
        [Parameter(Mandatory=$true)]$Controller,
        [Parameter(Mandatory=$true)]$ControllerSecret,
        [Parameter(Mandatory=$true)][string]$RequestJson,
        [switch]$AllowIndeterminateSave)
    if($Controller.Running -ne $true -or -not [object]::ReferenceEquals($Controller.Secret,$ControllerSecret)){
        throw 'CT-PA missing/foreign closed-controller invocation'
    }
    $identity=Get-UID0002PARequestIdentity $RequestJson 'CT-PA dispatch'
    $idKey="$($identity.IdType)|$($identity.Id)"
    if(-not $Controller.RequestIds.Add($idKey)){throw "CT-PA duplicate typed request id $idKey"}
    $isSave=[string]$identity.Parsed.params.name -ceq 'idb_save'
    if($isSave){
        if(-not $AllowIndeterminateSave -or $Controller.SaveSent -eq $true){throw 'CT-PA save outside sole closed-controller dispatch'}
        $Controller.SaveSent=$true
    }elseif($AllowIndeterminateSave){throw 'CT-PA indeterminate transport permitted only for idb_save'}
    $wire=& $Controller.Transport $RequestJson
    if($wire -is [string]){$observed='Response';$raw=[string]$wire}
    else{$observed=[string]$wire.ObservedTransport;$raw=[string]$wire.RawResponseJson}
    if($observed -notin @('Response','Timeout','Disconnect','Malformed')){throw 'CT-PA transport returned unknown observation'}
    if(-not $isSave -and ($observed -cne 'Response' -or [string]::IsNullOrWhiteSpace($raw))){throw 'CT-PA non-save request lacked exact response'}
    $envelope=$null
    if($observed -ceq 'Response'){
        $envelope=$raw|ConvertFrom-Json -ErrorAction Stop
        $null=Assert-UID0002PAJsonRpcResponse -Envelope $envelope -RequestJson $RequestJson -Label 'CT-PA immediate response correlation' -RequireStructuredContent (-not ([string]$identity.Parsed.method -ceq 'tools/list'))
    }
    $record=[pscustomobject][ordered]@{
        RequestId=$identity.Id;RequestIdType=$identity.IdType;RequestSHA256=$identity.SHA256
        Tool=if([string]$identity.Parsed.method -ceq 'tools/list'){'tools/list'}else{[string]$identity.Parsed.params.name}
        ObservedTransport=$observed;RawResponseJson=$raw;Envelope=$envelope
    }
    $Controller.Transcript.Add($record)
    return $record
}

function Open-UID0002PAControllerRole {
    param(
        [Parameter(Mandatory=$true)]$Controller,[Parameter(Mandatory=$true)]$ControllerSecret,
        [Parameter(Mandatory=$true)][ValidateSet('Transaction','P0Verifier','S1Verifier','RollbackVerifier')][string]$Role)
    $openRequest=New-UID0002PARoleOpenRequest $Role
    $preferred=[string](($openRequest|ConvertFrom-Json).params.arguments.preferred_session_id)
    $openWire=Invoke-UID0002PAControllerRequest $Controller $ControllerSecret $openRequest
    $listRequest=New-UID0002PAToolRequest "uid0002pa-open-list-$Role-$([Guid]::NewGuid().ToString('N'))" 'idb_list' @{}
    $listWire=Invoke-UID0002PAControllerRequest $Controller $ControllerSecret $listRequest
    $binding=New-UID0002PARoleBinding -Role $Role -PreferredSessionId $preferred -OpenRequestJson $openRequest -OpenEnvelope $openWire.Envelope -ListRequestJson $listRequest -ListEnvelope $listWire.Envelope
    $attestRequest=New-UID0002PARuntimeAttestationRequest "uid0002pa-open-attest-$Role-$([Guid]::NewGuid().ToString('N'))" $binding
    $attestWire=Invoke-UID0002PAControllerRequest $Controller $ControllerSecret $attestRequest
    $runtime=Assert-UID0002PARuntimeAttestation -Envelope $attestWire.Envelope -AttestationRequestJson $attestRequest -ListEnvelope $listWire.Envelope -ListRequestJson $listRequest -RoleBinding $binding -State $Controller.State
    [pscustomobject][ordered]@{Binding=$binding;Runtime=$runtime;OpenRequest=$openRequest;OpenResponse=$openWire.Envelope}
}

function Invoke-UID0002PAControllerCatalog {
    param(
        [Parameter(Mandatory=$true)]$Controller,[Parameter(Mandatory=$true)]$ControllerSecret,
        [Parameter(Mandatory=$true)]$RoleBinding,
        [Parameter(Mandatory=$true)][ValidateSet('Pre','AfterI01','AfterI02','AfterI03','AfterI04','AfterI05','Final','P0Verifier','S1Verifier','RollbackVerifier')][string]$Phase,
        [switch]$DeferSemanticAssertion)
    $requests=New-UID0002PAReadbackCatalog $RoleBinding $Phase
    $responses=[ordered]@{}
    foreach($key in @($requests.Keys)){$responses[$key]=(Invoke-UID0002PAControllerRequest $Controller $ControllerSecret ([string]$requests[$key])).Envelope}
    if($DeferSemanticAssertion){return [pscustomobject][ordered]@{Requests=$requests;Responses=$responses}}
    $readback=Assert-UID0002PAReadbackCatalog -Requests $requests -Responses $responses -RoleBinding $RoleBinding -AttestationState $Controller.State -Phase $Phase
    [pscustomobject][ordered]@{Requests=$requests;Responses=$responses;Readback=$readback}
}

function Close-UID0002PAControllerRole {
    param(
        [Parameter(Mandatory=$true)]$Controller,[Parameter(Mandatory=$true)]$ControllerSecret,
        [Parameter(Mandatory=$true)]$RoleBinding)
    $preListRequest=New-UID0002PAToolRequest "uid0002pa-preclose-list-$($RoleBinding.Role)-$([Guid]::NewGuid().ToString('N'))" 'idb_list' @{}
    $preListWire=Invoke-UID0002PAControllerRequest $Controller $ControllerSecret $preListRequest
    $preAttestRequest=New-UID0002PARuntimeAttestationRequest "uid0002pa-preclose-attest-$($RoleBinding.Role)-$([Guid]::NewGuid().ToString('N'))" $RoleBinding
    $preAttestWire=Invoke-UID0002PAControllerRequest $Controller $ControllerSecret $preAttestRequest
    $preRuntime=Assert-UID0002PARuntimeAttestation -Envelope $preAttestWire.Envelope -AttestationRequestJson $preAttestRequest -ListEnvelope $preListWire.Envelope -ListRequestJson $preListRequest -RoleBinding $RoleBinding -State $Controller.State
    $action=Invoke-UID0002PAExactGenerationRetirementAction -RoleBinding $RoleBinding -AttestationState $Controller.State -PreCloseRuntimeProof $preRuntime -RetireExactGeneration $Controller.RetireExactGeneration
    $postRequest=New-UID0002PAPostRetirementAttestationRequest "uid0002pa-postclose-attest-$($RoleBinding.Role)-$([Guid]::NewGuid().ToString('N'))" $RoleBinding
    $postWire=Invoke-UID0002PAControllerRequest $Controller $ControllerSecret $postRequest
    $postListRequest=New-UID0002PAToolRequest "uid0002pa-postclose-list-$($RoleBinding.Role)-$([Guid]::NewGuid().ToString('N'))" 'idb_list' @{}
    $postListWire=Invoke-UID0002PAControllerRequest $Controller $ControllerSecret $postListRequest
    $proof=Assert-UID0002PARoleRetired -RoleBinding $RoleBinding -AttestationState $Controller.State -PreCloseRuntimeProof $preRuntime -RetirementActionEvidence $action -PostAttestationEnvelope $postWire.Envelope -PostAttestationRequestJson $postRequest -ListEnvelope $postListWire.Envelope -ListRequestJson $postListRequest
    [pscustomobject][ordered]@{Runtime=$preRuntime;Action=$action;Proof=$proof}
}

function Invoke-UID0002PAControllerVerifier {
    param(
        [Parameter(Mandatory=$true)]$Controller,[Parameter(Mandatory=$true)]$ControllerSecret,
        [Parameter(Mandatory=$true)]$Attempt,
        [Parameter(Mandatory=$true)][ValidateSet('P0Verifier','S1Verifier','RollbackVerifier')][string]$Role)
    $opened=Open-UID0002PAControllerRole $Controller $ControllerSecret $Role
    if($Role -ceq 'S1Verifier'){
        $catalog=Invoke-UID0002PAControllerCatalog $Controller $ControllerSecret $opened.Binding S1Verifier -DeferSemanticAssertion
        $outcome=New-UID0002PAFailedVerifierEvidence -Requests $catalog.Requests -Responses $catalog.Responses -RoleBinding $opened.Binding -AttestationState $Controller.State -ControllerEvidenceKey $Controller.EvidenceKey
        $closed=Close-UID0002PAControllerRole $Controller $ControllerSecret $opened.Binding
        if($outcome.Passed -eq $true){
            return Complete-UID0002PAVerifier -TransactionState $Controller.State -Attempt $Attempt -VerifierRoleBinding $opened.Binding -VerifierReadback $outcome.Readback -VerifierRuntimeProof $outcome.Readback.RuntimeProof -VerifierRetirementProof $closed.Proof
        }
        $null=Set-UID0002PAVerifierFailure -TransactionState $Controller.State -Attempt $Attempt -VerifierRoleBinding $opened.Binding -FailedReadbackEvidence $outcome -ControllerEvidenceKey $Controller.EvidenceKey -VerifierRuntimeProof $opened.Runtime -VerifierRetirementProof $closed.Proof
        return Restore-UID0002PABackup $Attempt
    }
    $phase=if($Role -ceq 'P0Verifier'){'P0Verifier'}else{'RollbackVerifier'}
    $catalog=Invoke-UID0002PAControllerCatalog $Controller $ControllerSecret $opened.Binding $phase
    $closed=Close-UID0002PAControllerRole $Controller $ControllerSecret $opened.Binding
    if($Role -ceq 'P0Verifier'){
        return Complete-UID0002PAVerifier -TransactionState $Controller.State -Attempt $Attempt -VerifierRoleBinding $opened.Binding -VerifierReadback $catalog.Readback -VerifierRuntimeProof $catalog.Readback.RuntimeProof -VerifierRetirementProof $closed.Proof
    }
    return Complete-UID0002PARollbackVerifier -TransactionState $Controller.State -Attempt $Attempt -RollbackRoleBinding $opened.Binding -RollbackReadback $catalog.Readback -RollbackRuntimeProof $catalog.Readback.RuntimeProof -RollbackRetirementProof $closed.Proof
}

function Invoke-UID0002PAClosedTransaction {
    param(
        [Parameter(Mandatory=$true)][scriptblock]$Transport,
        [Parameter(Mandatory=$true)][scriptblock]$RetireExactGeneration,
        [Parameter(Mandatory=$true)]$SealedCore,
        [Parameter(Mandatory=$true)]$SealedBackup
    )
    if($null -eq $SealedCore -or $null -eq $SealedBackup){throw 'CT3-PA sealed authority required'}
    $controller=New-UID0002PAClosedControllerContext $Transport $RetireExactGeneration
    $secret=$controller.Secret
    $canonical=[System.IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64')
    $backupPath=$canonical+'.bak-UID0002PA-prestate-'+[DateTime]::UtcNow.ToString('yyyyMMdd-HHmmss')+'-'+[Guid]::NewGuid().ToString('N')
    $transaction=$null;$backup=$null;$attempt=$null
    try{
        $toolsRequest='{"jsonrpc":"2.0","id":"uid0002pa-tools","method":"tools/list","params":{}}'
        $toolsWire=Invoke-UID0002PAControllerRequest $controller $secret $toolsRequest
        $null=Assert-UID0002PAToolsList -Envelope $toolsWire.Envelope -RequestJson $toolsRequest
        $preflightRequest=New-UID0002PAToolRequest "uid0002pa-preflight-list-$([Guid]::NewGuid().ToString('N'))" 'idb_list' @{}
        $preflightWire=Invoke-UID0002PAControllerRequest $controller $secret $preflightRequest
        $preflight=Get-UID0002PAStructuredContent $preflightWire.Envelope $preflightRequest 'CT-PA preflight list'
        if(@($preflight.sessions|Where-Object{$_.is_active -eq $true -and [System.IO.Path]::GetFullPath([string]$_.input_path) -ieq $canonical}).Count -ne 0){throw 'CT-PA canonical database already active'}
        $backup=New-UID0002PABackup $canonical $backupPath
        $transaction=Open-UID0002PAControllerRole $controller $secret Transaction
        $null=Invoke-UID0002PAControllerCatalog $controller $secret $transaction.Binding Pre
        $mutations=New-UID0002PAMutationRequestCatalog $transaction.Binding
        $sequence=@(
            @('I01','AfterI01'),@('I02Dry',$null),@('I02','AfterI02'),@('I03','AfterI03'),@('I04','AfterI04'),@('I05','AfterI05'))
        foreach($step in $sequence){
            $action=[string]$step[0];$request=[string]$mutations[$action]
            $wire=Invoke-UID0002PAControllerRequest $controller $secret $request
            Assert-UID0002PAMutationResponse -Action $action -RequestJson $request -Envelope $wire.Envelope -RoleBinding $transaction.Binding
            if($null -ne $step[1]){$null=Invoke-UID0002PAControllerCatalog $controller $secret $transaction.Binding ([string]$step[1])}
        }
        $final=Invoke-UID0002PAControllerCatalog $controller $secret $transaction.Binding Final
        $saveRequest=New-UID0002PAToolRequest 'uid0002pa-save-transaction' 'idb_save' ([ordered]@{database=[string]$transaction.Binding.Database;path=$canonical})
        $attempt=New-UID0002PASaveAttempt -TransactionState $controller.State -RoleBinding $transaction.Binding -BackupState $backup -FinalReadback $final.Readback -FinalAttestation $final.Readback.RuntimeProof -MaterializedSaveRequestJson $saveRequest
        $dispatch=Register-UID0002PASoleSaveDispatch $controller.State $attempt
        $saveWire=Invoke-UID0002PAControllerRequest $controller $secret $dispatch -AllowIndeterminateSave
        $attempt=Complete-UID0002PASaveTransport -Attempt $attempt -ObservedTransport $saveWire.ObservedTransport -RawResponseJson $saveWire.RawResponseJson
        $transactionClosed=Close-UID0002PAControllerRole $controller $secret $transaction.Binding
        $classification=Complete-UID0002PADiskClassification $attempt $transactionClosed.Proof
        $attempt=Invoke-UID0002PAControllerVerifier $controller $secret $attempt $classification.RequiredVerifier
        if($attempt.Status -ceq 'ROLLBACK_VERIFIER_REQUIRED'){$attempt=Invoke-UID0002PAControllerVerifier $controller $secret $attempt RollbackVerifier}
        $controller.Running=$false
        return [pscustomobject][ordered]@{Status=[string]$attempt.Status;Attempt=$attempt;Transcript=@($controller.Transcript);SaveDispatchCount=[int]$controller.State.SaveDispatchCount}
    }catch{
        $failure=$_.Exception.Message
        if($controller.SaveSent -eq $true){$controller.Running=$false;throw}
        if($null -eq $backup){$controller.Running=$false;throw}
        if($null -eq $transaction){
            Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $canonical) $backup.P0 'CT-PA pre-open failure P0'
            Assert-UID0002PATuple (Get-UID0002PAExclusiveTuple $backup.B0.FullPath) $backup.B0 'CT-PA pre-open failure B0'
            $controller.Running=$false
            return [pscustomobject][ordered]@{Status='PRE_OPEN_ABORTED_P0_VERIFIED';Failure=$failure;SaveDispatchCount=0;Transcript=@($controller.Transcript)}
        }
        $closed=Close-UID0002PAControllerRole $controller $secret $transaction.Binding
        $null=Complete-UID0002PAPreSaveFailure -TransactionState $controller.State -BackupState $backup -RetirementProof $closed.Proof -ExactFailure $failure
        $p0=Open-UID0002PAControllerRole $controller $secret P0Verifier
        $catalog=Invoke-UID0002PAControllerCatalog $controller $secret $p0.Binding P0Verifier
        $p0Closed=Close-UID0002PAControllerRole $controller $secret $p0.Binding
        $null=Complete-UID0002PAPreSaveP0Verifier -TransactionState $controller.State -VerifierRoleBinding $p0.Binding -VerifierReadback $catalog.Readback -VerifierRuntimeProof $catalog.Readback.RuntimeProof -VerifierRetirementProof $p0Closed.Proof
        $controller.Running=$false
        return [pscustomobject][ordered]@{Status='PRE_SAVE_ABORTED_P0_VERIFIED';Failure=$failure;SaveDispatchCount=0;Transcript=@($controller.Transcript)}
    }
}

function Assert-UID0002PAHostileThrow {
    param([Parameter(Mandatory=$true)][scriptblock]$Action,[Parameter(Mandatory=$true)][string]$Label)
    try { & $Action; throw "HOSTILE FIXTURE DID NOT FAIL: $Label" }
    catch {
        if($_.Exception.Message -like 'HOSTILE FIXTURE DID NOT FAIL:*'){throw}
        return $true
    }
}

function New-UID0002PAFixtureToolFromContract {
    param([Parameter(Mandatory=$true)][string]$Name,[Parameter(Mandatory=$true)]$Contract)
    $properties=[ordered]@{};$required=@()
    foreach($entry in $Contract.Properties.GetEnumerator()){
        $node=[ordered]@{}
        if(@($entry.Value.Types).Count -eq 1){$node.type=[string]$entry.Value.Types[0]}
        else{$node.anyOf=@($entry.Value.Types|ForEach-Object{[ordered]@{type=[string]$_}})}
        if($entry.Value.DefaultState -ceq 'Present'){$node.default=$entry.Value.DefaultValue}
        $properties[$entry.Key]=$node
        if($entry.Value.Required){$required+=[string]$entry.Key}
    }
    $schema=[ordered]@{type='object';properties=$properties;required=@($required)}
    if($Contract.AdditionalProperties -cne 'Absent'){$schema.additionalProperties=($Contract.AdditionalProperties -ceq 'True')}
    $normalized=$schema|ConvertTo-Json -Depth 30 -Compress|ConvertFrom-Json -ErrorAction Stop
    [pscustomobject][ordered]@{name=$Name;inputSchema=$normalized}
}

function Invoke-UID0002PAHostileStaticFixtures {
    $canonical=[System.IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64')
    $passed=0

    $runtimeContract=(Get-UID0002PAUsedToolSchemaContracts).runtime_attestation
    $wrongRoot=New-UID0002PAFixtureToolFromContract runtime_attestation $runtimeContract;$wrongRoot.inputSchema.type='array'
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PAToolSchemaContract $wrongRoot $runtimeContract} 'schema wrong root'){$passed++}
    $wrongType=New-UID0002PAFixtureToolFromContract runtime_attestation $runtimeContract;$wrongType.inputSchema.properties.expected_database.anyOf=@([pscustomobject]@{type='integer'},[pscustomobject]@{type='null'})
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PAToolSchemaContract $wrongType $runtimeContract} 'schema wrong native type'){$passed++}
    $wrongDefault=New-UID0002PAFixtureToolFromContract runtime_attestation $runtimeContract;$wrongDefault.inputSchema.properties.expected_database.default='forged'
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PAToolSchemaContract $wrongDefault $runtimeContract} 'schema wrong default'){$passed++}
    $extraSchema=New-UID0002PAFixtureToolFromContract runtime_attestation $runtimeContract;$extraSchema.inputSchema.properties|Add-Member -NotePropertyName extra -NotePropertyValue ([pscustomobject]@{type='string'})
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PAToolSchemaContract $extraSchema $runtimeContract} 'schema extra property'){$passed++}

    $validOpen=New-UID0002PARoleOpenRequest Transaction
    $missingOpen=$validOpen|ConvertFrom-Json;$missingOpen.params.arguments.PSObject.Properties.Remove('idle_ttl_sec');$missingOpenJson=$missingOpen|ConvertTo-Json -Depth 20 -Compress
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PALiteralRoleOpenRequest Transaction $missingOpenJson} 'idb_open missing idle_ttl_sec'){$passed++}
    $analysisOpen=$validOpen|ConvertFrom-Json;$analysisOpen.params.arguments.run_auto_analysis=$true;$analysisOpenJson=$analysisOpen|ConvertTo-Json -Depth 20 -Compress
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PALiteralRoleOpenRequest Transaction $analysisOpenJson} 'idb_open analysis enabled'){$passed++}

    $request=New-UID0002PAToolRequest 'expected-id' 'idb_list' @{}
    $foreign=[pscustomobject]@{jsonrpc='2.0';id='foreign-id';result=[pscustomobject]@{isError=$false;structuredContent=[pscustomobject]@{sessions=@()}}}
    if(Assert-UID0002PAHostileThrow {Get-UID0002PAStructuredContent -Envelope $foreign -RequestJson $request -Label 'foreign-id'} 'foreign JSON-RPC id'){$passed++}
    $numericRequest='{"jsonrpc":"2.0","id":7,"method":"tools/call","params":{"name":"idb_list","arguments":{}}}'
    $stringId=[pscustomobject]@{jsonrpc='2.0';id='7';result=[pscustomobject]@{isError=$false;structuredContent=[pscustomobject]@{sessions=@()}}}
    if(Assert-UID0002PAHostileThrow {Get-UID0002PAStructuredContent -Envelope $stringId -RequestJson $numericRequest -Label 'foreign-id-type'} 'foreign JSON-RPC id type'){$passed++}

    $state=New-UID0002PAAttestationState
    $state.TransactionDatabase='transaction-db';$state.TransactionGeneration='tx-generation'
    $state.RoleWorkers['transaction-db']=[pscustomobject]@{Generation='pid:12;created:120';RedirectorGeneration='pid:11;created:110';RedirectorPid=11;WorkerPid=12;RoutePort=31337}
    $state.TransactionGeneration='pid:12;created:120'
    $binding=[pscustomobject]@{Role='Transaction';Database='transaction-db';CanonicalPath=$canonical}
    $p0=[pscustomobject]@{FullPath=$canonical;Length=[long]1;LastWriteTimeUtcTicks=[long]2;SHA256=('A'*64)}
    $b0=[pscustomobject]@{FullPath=($canonical+'.b0');Length=[long]1;LastWriteTimeUtcTicks=[long]2;SHA256=('A'*64)}
    $backup=[pscustomobject]@{P0=$p0;B0=$b0}
    $readback=[pscustomobject]@{Passed=$true;Phase='Final';Role='Transaction';Database='transaction-db';WorkerGeneration='pid:12;created:120'}
    $attestation=[pscustomobject]@{Passed=$true;Role='Transaction';Database='transaction-db';ActiveDatabases=@('transaction-db');RoleWorker=[pscustomobject]@{Generation='pid:12;created:120'}}
    $save=New-UID0002PAToolRequest 'save-id' 'idb_save' ([ordered]@{database='transaction-db';path=$canonical})

    $wrongMutation='{"tool":"declare_type","arguments":{"database":"transaction-db"}}'
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PAMutationResponse I01 $wrongMutation ([pscustomobject]@{}) $binding} 'descriptor mutation row'){$passed++}
    $literalMutation=(New-UID0002PAMutationRequestCatalog $binding).I02|ConvertFrom-Json
    $literalMutation.params.arguments.batch.func.addr='0xDEADBEEF';$wrongMutationJson=$literalMutation|ConvertTo-Json -Depth 30 -Compress
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PAMutationResponse I02 $wrongMutationJson ([pscustomobject]@{}) $binding} 'wrong literal mutation address'){$passed++}

    $transportCalls=0
    $closed=New-UID0002PAClosedControllerContext {param($json)$script:transportCalls++;throw 'must not dispatch'} {param($action)$null}
    if(Assert-UID0002PAHostileThrow {Invoke-UID0002PAControllerRequest $closed (New-Object object) (New-UID0002PAToolRequest 'outside-controller' 'idb_list' @{})} 'missing closed-controller invocation'){$passed++}
    if($closed.SaveSent -ne $false -or [int]$closed.State.SaveDispatchCount -ne 0 -or $closed.Transcript.Count -ne 0){throw 'closed-controller hostile fixture changed transaction state'}

    $moduleState=New-UID0002PAAttestationState
    $moduleOwner=[pscustomobject]@{modules=@([pscustomobject]@{sys_modules_name='m';module_id='0x1'})}
    $null=Assert-UID0002PAProcessLocalModuleContinuity $moduleState $moduleOwner 'pid:1;created:1' 'fixture module'
    $moduleOwner.modules[0].module_id='0x2'
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PAProcessLocalModuleContinuity $moduleState $moduleOwner 'pid:1;created:1' 'fixture module'} 'same-process module_id drift'){$passed++}
    $attempt=New-UID0002PASaveAttempt -TransactionState $state -RoleBinding $binding -BackupState $backup -FinalReadback $readback -FinalAttestation $attestation -MaterializedSaveRequestJson $save
    if(Assert-UID0002PAHostileThrow {New-UID0002PASaveAttempt -TransactionState $state -RoleBinding $binding -BackupState $backup -FinalReadback $readback -FinalAttestation $attestation -MaterializedSaveRequestJson $save} 'second transaction save attempt'){$passed++}
    $null=Register-UID0002PASoleSaveDispatch -TransactionState $state -Attempt $attempt
    if(Assert-UID0002PAHostileThrow {Register-UID0002PASoleSaveDispatch -TransactionState $state -Attempt $attempt} 'second transaction save registration'){$passed++}
    $foreignSave=[pscustomobject]@{jsonrpc='2.0';id='foreign-save-id';result=[pscustomobject]@{isError=$false;structuredContent=[pscustomobject]@{ok=$true;error='';path=$canonical}}}
    $attempt=Complete-UID0002PASaveTransport -Attempt $attempt -ObservedTransport Response -RawResponseJson ($foreignSave|ConvertTo-Json -Depth 12 -Compress)
    if($attempt.TransportClass -cne 'Indeterminate' -or [string]::IsNullOrWhiteSpace([string]$attempt.ResponseValidationFailure)){throw 'foreign save response ID did not classify indeterminate'}
    $passed++

    $state.RoleWorkers['verifier-A']=[pscustomobject]@{Generation='verifier-generation'}
    $verifierBinding=[pscustomobject]@{Role='P0Verifier';Database='verifier-A'}
    $verifierReadback=[pscustomobject]@{Passed=$true;Role='P0Verifier';Database='verifier-A';WorkerGeneration='verifier-generation'}
    $verifierRuntime=[pscustomobject]@{Passed=$true;Role='P0Verifier';Database='verifier-A';WorkerGeneration='verifier-generation'}
    $retirement=[pscustomobject]@{Role='P0Verifier';Database='verifier-B';Generation='verifier-generation';RedirectorPid=1;WorkerPid=2;PreCloseAttestationRequestId='a';PostCloseAttestationRequestId='b';PostCloseListRequestId='c';ClosedTupleA=$p0;ClosedTupleB=$p0;ProofSeal=$null}
    $retirement.ProofSeal=Get-UID0002PARetirementProofSeal $retirement
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PAVerifierIdentity -TransactionState $state -ExpectedRole P0Verifier -RoleBinding $verifierBinding -Readback $verifierReadback -RuntimeProof $verifierRuntime -RetirementProof $retirement} 'verifier/retirement database mismatch'){$passed++}

    $postRequest=New-UID0002PAPostRetirementAttestationRequest 'post-retirement-id' $binding
    $preClose=[pscustomobject]@{Passed=$true;Role='Transaction';Database='transaction-db';WorkerGeneration='pid:12;created:120';AttestationRequestId='pre-close-id'}
    $postMissing=[pscustomobject]@{}
    $listRequest=New-UID0002PAToolRequest 'post-list-id' 'idb_list' @{}
    $listResponse=[pscustomobject]@{jsonrpc='2.0';id='post-list-id';result=[pscustomobject]@{isError=$false;structuredContent=[pscustomobject]@{sessions=@()}}}
    $actionEvidence=[pscustomobject]@{Passed=$true;Action=[pscustomobject]@{Action='RETIRE_EXACT_GENERATION';Role='Transaction';Database='transaction-db';WorkerGeneration='pid:12;created:120';RedirectorGeneration='pid:11;created:110';RedirectorPid=11;WorkerPid=12};PidResults=@([pscustomobject]@{Pid=11;ExpectedCreated100ns=110;Disposition='Absent'},[pscustomobject]@{Pid=12;ExpectedCreated100ns=120;Disposition='Absent'});ActionSHA256=('A'*64);ResultSHA256=('B'*64)}
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PARoleRetired -RoleBinding $binding -AttestationState $state -PreCloseRuntimeProof $preClose -RetirementActionEvidence $actionEvidence -PostAttestationEnvelope $postMissing -PostAttestationRequestJson $postRequest -ListEnvelope $listResponse -ListRequestJson $listRequest} 'missing post-retirement public attestation'){$passed++}

    $badRetire={param($action)[pscustomobject]@{Retired=$true;ListenerPreserved=$true;Action='RETIRE_EXACT_GENERATION';Role=$action.Role;Database=$action.Database;WorkerGeneration='foreign-generation';RedirectorGeneration=$action.RedirectorGeneration;RedirectorPid=$action.RedirectorPid;WorkerPid=$action.WorkerPid}}
    if(Assert-UID0002PAHostileThrow {Invoke-UID0002PAExactGenerationRetirementAction $binding $state $preClose $badRetire} 'wrong retirement generation action'){$passed++}

    $fabricatedFailure=[pscustomobject]@{Passed=$false;Phase='S1Verifier';Role='S1Verifier';Database='verifier-A';ExactFailure='caller prose';Requests=[ordered]@{};Responses=[ordered]@{};RequestCatalogSHA256=('A'*64);ResponseCatalogSHA256=('B'*64)}
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PAFailedVerifierEvidence $fabricatedFailure $verifierBinding ('0'*64)} 'fabricated F1 without failed readback'){$passed++}

    $unconstructedState=New-UID0002PAAttestationState
    if(Assert-UID0002PAHostileThrow {Complete-UID0002PAPreSaveP0Verifier -TransactionState $unconstructedState -VerifierRoleBinding $verifierBinding -VerifierReadback ([pscustomobject]@{Passed=$true;Phase='P0Verifier'}) -VerifierRuntimeProof $verifierRuntime -VerifierRetirementProof $retirement} 'unconstructed no-save verifier state'){$passed++}

    $pad='0xcc '*10;$target='0x00 '*166
    $duplicatePadding=@(
        [pscustomobject]@{addr='0x00494130';size=166;data=$target;error=$null},
        [pscustomobject]@{addr='0x00494126';size=10;data=$pad;error=$null},
        [pscustomobject]@{addr='0x00494126';size=10;data=$pad;error=$null})
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PAByteRows $duplicatePadding} 'duplicated padding address'){$passed++}

    $swappedComments=@(
        [pscustomobject]@{addr='0x00494130';regular='';repeatable='';function_regular='';function_repeatable=''},
        [pscustomobject]@{addr='0x00494166';regular='Block';repeatable='';function_regular='';function_repeatable=''},
        [pscustomobject]@{addr='0x00494157';regular='Block';repeatable='';function_regular='';function_repeatable=''},
        [pscustomobject]@{addr='0x00494176';regular='Block';repeatable='';function_regular='';function_repeatable=''})
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PACommentRows -Rows $swappedComments -FunctionText '' -AddressTexts @('Block','Block','Block')} 'swapped comment addresses'){$passed++}
    if(Assert-UID0002PAHostileThrow {Assert-UID0002PACandidateTypeIndex -Pages @() -PostTypes $false} 'missing candidate type pages'){$passed++}

    if($passed -ne 23){throw "hostile fixture count mismatch: $passed"}
    [pscustomobject]@{Passed=$passed;Failed=0}
}
~~~

## Removed Block R028

- SHA256: `A63369956F3C394FE8CE2BA2B6CDFEEE4B13AB35AAE1770C1F010B5010135A86`
- Language: `powershell`
- Bytes: `8699`
- First recovered timestamp: `2026-08-09T15:30:56.412Z`
- Session provenance: rollout-2026-08-08T17-46-23-019fe357-64cc-7ca3-ad27-c9c336afc6af.jsonl line 5673 (2026-08-09T15:30:56.412Z); rollout-2026-08-08T17-46-23-019fe357-64cc-7ca3-ad27-c9c336afc6af.jsonl line 5674 (2026-08-09T15:30:56.800Z)

~~~powershell
function New-UID0002PARoleOpenRequest {
    param([Parameter(Mandatory=$true)][ValidateSet('Transaction','P0Verifier','S1Verifier','RollbackVerifier')][string]$Role)
    $slug=@{Transaction='transaction';P0Verifier='p0-verifier';S1Verifier='s1-verifier';RollbackVerifier='rollback-verifier'}[$Role]
    $stamp=[DateTime]::UtcNow.ToString('yyyyMMdd-HHmmss')
    $nonce=[Guid]::NewGuid().ToString('N')
    $preferred="b010-uid0002pa-$slug-$stamp-r1-$nonce"
    $id="uid0002pa-open-$slug-$stamp-r1-$nonce"
    New-UID0002PAToolRequest $id 'idb_open' ([ordered]@{
        input_path='E:\NTK\Resources\NexusTK\NexusTK.exe.i64'
        mode='force_headless';run_auto_analysis=$false;build_caches=$false;init_hexrays=$false
        idle_ttl_sec=600;preferred_session_id=$preferred
    })
}

function Assert-UID0002PALiteralRoleOpenRequest {
    param(
        [Parameter(Mandatory=$true)][ValidateSet('Transaction','P0Verifier','S1Verifier','RollbackVerifier')][string]$Role,
        [Parameter(Mandatory=$true)][string]$RequestJson)
    $request=Get-UID0002PARequestIdentity $RequestJson "$Role literal idb_open"
    $arguments=$request.Parsed.params.arguments
    $slug=@{Transaction='transaction';P0Verifier='p0-verifier';S1Verifier='s1-verifier';RollbackVerifier='rollback-verifier'}[$Role]
    $names=@($arguments.PSObject.Properties.Name|Sort-Object)
    $expected=@('build_caches','idle_ttl_sec','init_hexrays','input_path','mode','preferred_session_id','run_auto_analysis')
    if([string]$request.Parsed.method -cne 'tools/call' -or [string]$request.Parsed.params.name -cne 'idb_open' -or
        ($names-join '|') -cne ($expected-join '|') -or
        [System.IO.Path]::GetFullPath([string]$arguments.input_path) -ine [System.IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64') -or
        [string]$arguments.mode -cne 'force_headless' -or $arguments.run_auto_analysis -ne $false -or
        $arguments.build_caches -ne $false -or $arguments.init_hexrays -ne $false -or [int]$arguments.idle_ttl_sec -ne 600 -or
        [string]$arguments.preferred_session_id -notmatch "^b010-uid0002pa-$slug-[0-9]{8}-[0-9]{6}-r[1-9][0-9]*-[0-9a-f]{32}$" -or
        [string]$request.Id -cne "uid0002pa-open-$slug-$(([string]$arguments.preferred_session_id).Substring(("b010-uid0002pa-$slug-").Length))"){
        throw "$Role literal idb_open options/prefix mismatch"
    }
    return $request
}

function New-UID0002PARoleBinding {
    param(
        [Parameter(Mandatory=$true)][ValidateSet('Transaction','P0Verifier','S1Verifier','RollbackVerifier')][string]$Role,
        [Parameter(Mandatory=$true)][string]$PreferredSessionId,
        [Parameter(Mandatory=$true)][string]$OpenRequestJson,
        [Parameter(Mandatory=$true)]$OpenEnvelope,
        [Parameter(Mandatory=$true)][string]$ListRequestJson,
        [Parameter(Mandatory=$true)]$ListEnvelope)

    $canonical = [System.IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64')
    $openRequest=Assert-UID0002PALiteralRoleOpenRequest -Role $Role -RequestJson $OpenRequestJson
    $listRequest=Get-UID0002PARequestIdentity $ListRequestJson "$Role idb_list"
    if ([string]$openRequest.Parsed.params.arguments.preferred_session_id -cne $PreferredSessionId -or
        [string]$listRequest.Parsed.params.name -cne 'idb_list' -or
        @($listRequest.Parsed.params.arguments.PSObject.Properties).Count -ne 0) {
        throw "$Role literal open/list request mismatch"
    }
    $open=Get-UID0002PAStructuredContent -Envelope $OpenEnvelope -RequestJson $OpenRequestJson -Label "$Role idb_open"
    if ($open.success -ne $true -or -not [string]::IsNullOrWhiteSpace([string]$open.error)) {
        throw "$Role idb_open did not return exact success"
    }
    $sessions = @($open.session)
    if ($sessions.Count -ne 1) { throw "$Role idb_open must return exactly one session object" }
    $session = $sessions[0]
    $databaseReturnedByIdbOpen = [string]$OpenEnvelope.result.structuredContent.session.session_id
    if ([string]::IsNullOrWhiteSpace($databaseReturnedByIdbOpen) -or
        [System.IO.Path]::GetFullPath([string]$session.input_path) -ine $canonical -or
        $session.is_analyzing -eq $true) { throw "$Role returned session identity/path/state mismatch" }

    $list=Get-UID0002PAStructuredContent -Envelope $ListEnvelope -RequestJson $ListRequestJson -Label "$Role idb_list"
    $matches = @($list.sessions | Where-Object {
        [string]$_.session_id -ceq $databaseReturnedByIdbOpen -and
        [System.IO.Path]::GetFullPath([string]$_.input_path) -ieq $canonical -and
        $_.is_active -eq $true
    })
    if ($matches.Count -ne 1 -or [int]$matches[0].worker_pid -le 0) {
        throw "$Role idb_list does not uniquely corroborate returned session/path/worker"
    }
    return [pscustomobject][ordered]@{
        Role = $Role
        PreferredSessionId = $PreferredSessionId
        Database = $databaseReturnedByIdbOpen
        CanonicalPath = $canonical
        CorroboratedRedirectorPid = [int]$matches[0].worker_pid
        OpenRequestId = $openRequest.Id
        OpenRequestSHA256 = $openRequest.SHA256
        ListRequestId = $listRequest.Id
        ListRequestSHA256 = $listRequest.SHA256
        LiteralOpenResponse = $OpenEnvelope
        LiteralListResponse = $ListEnvelope
    }
}

function New-UID0002PARuntimeAttestationRequest {
    param(
        [Parameter(Mandatory=$true)][string]$RequestId,
        [Parameter(Mandatory=$true)]$RoleBinding)

    $request = [ordered]@{
        jsonrpc='2.0'; id=$RequestId; method='tools/call'; params=[ordered]@{
            name='runtime_attestation'; arguments=[ordered]@{
                expected_database=[string]$RoleBinding.Database
                expected_canonical_path=[string]$RoleBinding.CanonicalPath
            }
        }
    }
    $json = $request | ConvertTo-Json -Depth 12 -Compress
    $parsed = $json | ConvertFrom-Json -ErrorAction Stop
    if ([string]::IsNullOrWhiteSpace([string]$parsed.params.arguments.expected_database) -or
        [string]$parsed.params.arguments.expected_database -cne [string]$RoleBinding.Database -or
        [System.IO.Path]::GetFullPath([string]$parsed.params.arguments.expected_canonical_path) -ine
            [System.IO.Path]::GetFullPath([string]$RoleBinding.CanonicalPath) -or
        $json -match '__[A-Z0-9_]+__|<[^>]+>') {
        throw 'RA-PA public request lost returned-session/path authority'
    }
    return $json
}

function New-UID0002PAPostRetirementAttestationRequest {
    param([Parameter(Mandatory=$true)][string]$RequestId,[Parameter(Mandatory=$true)]$RoleBinding)
    $request=[ordered]@{
        jsonrpc='2.0';id=$RequestId;method='tools/call';params=[ordered]@{
            name='runtime_attestation';arguments=[ordered]@{
                expected_canonical_path=[string]$RoleBinding.CanonicalPath
            }
        }
    }
    $json=$request|ConvertTo-Json -Depth 12 -Compress
    $parsed=$json|ConvertFrom-Json -ErrorAction Stop
    if ((@($parsed.params.arguments.PSObject.Properties.Name)-join '|') -cne 'expected_canonical_path' -or
        [System.IO.Path]::GetFullPath([string]$parsed.params.arguments.expected_canonical_path) -ine
            [System.IO.Path]::GetFullPath([string]$RoleBinding.CanonicalPath)) {
        throw 'RA-PA post-retirement request mismatch'
    }
    return $json
}

function Resolve-UID0002PADatabaseTemplate {
    param(
        [Parameter(Mandatory=$true)][string]$TemplateJson,
        [Parameter(Mandatory=$true)]$RoleBinding)

    $token = '__DATABASE_RETURNED_BY_IDB_OPEN__'
    $quotedToken = '"' + $token + '"'
    $count = ([regex]::Matches($TemplateJson, [regex]::Escape($quotedToken))).Count
    if ($count -le 0) { throw 'DB-PA template has no exact returned-database token' }
    if ([string]::IsNullOrWhiteSpace([string]$RoleBinding.Database)) { throw 'DB-PA role database is unresolved' }
    $quotedDatabase = ConvertTo-Json -InputObject ([string]$RoleBinding.Database) -Compress
    $resolved = $TemplateJson.Replace($quotedToken, $quotedDatabase)
    if ($resolved.Contains($token) -or $resolved -match '__[A-Z0-9_]+__|<[^>]+>') {
        throw 'DB-PA unresolved placeholder remains after substitution'
    }
    $null = $resolved | ConvertFrom-Json -ErrorAction Stop
    $databaseMatches = [regex]::Matches($resolved, '"database"\s*:\s*"([^"]+)"')
    if ($databaseMatches.Count -ne $count) { throw 'DB-PA database-field count changed during substitution' }
    foreach ($match in $databaseMatches) {
        if ([string]$match.Groups[1].Value -cne [string]$RoleBinding.Database) {
            throw 'DB-PA request contains a non-returned database value'
        }
    }
    return $resolved
}
~~~

## Removed Block R029

- SHA256: `ABCD2A9E1E1B84CC8AFF2FA3A419AED433F6590F64A4B1321B4BFB92DE768CA9`
- Language: `powershell`
- Bytes: `116427`
- First recovered timestamp: `2026-08-09T15:30:56.412Z`
- Session provenance: rollout-2026-08-08T17-46-23-019fe357-64cc-7ca3-ad27-c9c336afc6af.jsonl line 5673 (2026-08-09T15:30:56.412Z); rollout-2026-08-08T17-46-23-019fe357-64cc-7ca3-ad27-c9c336afc6af.jsonl line 5674 (2026-08-09T15:30:56.800Z)

~~~powershell
function Initialize-UID0002PAV4SealedTypes {
    if ('UID0002PAV4Authority' -as [type]) { return }
    Add-Type -TypeDefinition @'
using System;
using System.Collections.Generic;
using System.IO;
using System.Reflection;
using System.Security.Cryptography;
using System.Text;
using System.Threading;

public sealed class UID0002PAV4Authority {
  readonly string canonicalPath, sourceRoot;
  readonly object transport, retirement;
  public string CanonicalPath { get { return canonicalPath; } }
  public string SourceRoot { get { return sourceRoot; } }
  public bool HasTransport { get { return transport != null; } }
  public bool HasRetirement { get { return retirement != null; } }
  public UID0002PAV4Authority(string canonical, string root, object rawTransport, object exactRetirement) {
    if (String.IsNullOrWhiteSpace(canonical)) throw new ArgumentNullException("canonical");
    if (String.IsNullOrWhiteSpace(root)) throw new ArgumentNullException("root");
    canonicalPath = Path.GetFullPath(canonical); sourceRoot = Path.GetFullPath(root);
    transport = rawTransport; retirement = exactRetirement;
  }
  internal object Send(string payload) { if (transport == null) throw new InvalidOperationException("CT4-PA transport adapter required"); return Invoke(transport, payload); }
  internal object Retire(string payload) { if (retirement == null) throw new InvalidOperationException("CT4-PA retirement adapter required"); return Invoke(retirement, payload); }
  static object Invoke(object adapter, string payload) {
    MethodInfo selected = null;
    foreach (MethodInfo m in adapter.GetType().GetMethods())
      if (m.Name == "InvokeReturnAsIs" && m.GetParameters().Length == 1) { selected = m; break; }
    if (selected == null) throw new MissingMethodException("sealed adapter lacks InvokeReturnAsIs");
    try { return selected.Invoke(adapter, new object[] { new object[] { payload } }); }
    catch (TargetInvocationException e) { throw e.InnerException; }
  }
}

public static class UID0002PAV4ExecutionMeter {
  static long coordinatorEntries;
  public static long EnterCoordinator() { return Interlocked.Increment(ref coordinatorEntries); }
  public static long SnapshotCoordinatorEntries() { return Interlocked.Read(ref coordinatorEntries); }
}

public sealed class UID0002PAV4DiskTuple {
  public string FullPath { get; private set; } public long Length { get; private set; }
  public long LastWriteTimeUtcTicks { get; private set; } public string SHA256 { get; private set; }
  public long VolumeSerial { get; private set; } public ulong FileIndex { get; private set; }
  public UID0002PAV4DiskTuple(string p,long n,long t,string h,long v,ulong i) {
    FullPath=Path.GetFullPath(p);Length=n;LastWriteTimeUtcTicks=t;SHA256=h;VolumeSerial=v;FileIndex=i;
  }
  public bool Same(UID0002PAV4DiskTuple x) {
    return x!=null && String.Equals(FullPath,x.FullPath,StringComparison.OrdinalIgnoreCase) &&
      Length==x.Length && LastWriteTimeUtcTicks==x.LastWriteTimeUtcTicks &&
      String.Equals(SHA256,x.SHA256,StringComparison.Ordinal) && VolumeSerial==x.VolumeSerial && FileIndex==x.FileIndex;
  }
  public bool SameContent(UID0002PAV4DiskTuple x) {
    return x!=null && Length==x.Length && LastWriteTimeUtcTicks==x.LastWriteTimeUtcTicks && String.Equals(SHA256,x.SHA256,StringComparison.Ordinal);
  }
}

public sealed class UID0002PAV4Role {
  public string RoleName {get;private set;} public string SessionId {get;private set;} public string CanonicalPath {get;private set;}
  public int ListenerPid {get;private set;} public string ListenerGeneration {get;private set;} public string ListenerNonce {get;private set;}
  public string ListenerStableManifestSHA256 {get;private set;} public string ListenerProcessManifestSHA256 {get;private set;}
  public int RedirectorPid {get;private set;} public string RedirectorGeneration {get;private set;}
  public int WorkerPid {get;private set;} public string WorkerGeneration {get;private set;}
  public int RoutePort {get;private set;} public string Endpoint {get;private set;} public int SocketOwnerPid {get;private set;}
  public string Nonce {get;private set;} public string StableManifestSHA256 {get;private set;}
  public string ProcessManifestSHA256 {get;private set;} public string AuthoritySHA256 {get;private set;}
  public UID0002PAV4Role(string role,string session,string path,int lp,string lg,string ln,string ls,string lpm,int rp,string rg,int wp,string wg,int port,string endpoint,int owner,string nonce,string stable,string process,string authority) {
    RoleName=role;SessionId=session;CanonicalPath=Path.GetFullPath(path);ListenerPid=lp;ListenerGeneration=lg;ListenerNonce=ln;ListenerStableManifestSHA256=ls;ListenerProcessManifestSHA256=lpm;RedirectorPid=rp;RedirectorGeneration=rg;
    WorkerPid=wp;WorkerGeneration=wg;RoutePort=port;Endpoint=endpoint;SocketOwnerPid=owner;Nonce=nonce;
    StableManifestSHA256=stable;ProcessManifestSHA256=process;AuthoritySHA256=authority;
  }
}

public sealed class UID0002PAV4Failure : Exception {
  public int SaveDispatchCount {get;private set;} public int TransportCalls {get;private set;}
  public int RetireCalls {get;private set;} public int RestoreWrites {get;private set;}
  public bool DopenCaptured {get;private set;} public string JournalPath {get;private set;}
  public UID0002PAV4Failure(string message,int saves,int transports,int retires,int restores,bool dopen,string journal,Exception inner)
    : base(message,inner) {SaveDispatchCount=saves;TransportCalls=transports;RetireCalls=retires;RestoreWrites=restores;DopenCaptured=dopen;JournalPath=journal;}
}

public sealed class UID0002PAV4Core : IDisposable {
  readonly UID0002PAV4Authority authority; readonly FileStream journal; readonly string journalPath, transactionId;
  readonly Dictionary<string,string> roles = new Dictionary<string,string>(StringComparer.Ordinal);
  readonly List<string> transportTranscript = new List<string>(); readonly List<string> stateTranscript = new List<string>();
  string state="CREATED", schemaSHA, planSHA; bool complete=false; int saves=0, transports=0, retires=0, restores=0;
  UID0002PAV4DiskTuple p0,b0,dopen,dclosed,p1;
  public string JournalPath {get{return journalPath;}} public string State {get{return state;}}
  public int SaveDispatchCount {get{return saves;}} public int TransportCalls {get{return transports;}}
  public int RetireCalls {get{return retires;}} public int RestoreWrites {get{return restores;}}
  public UID0002PAV4DiskTuple P0 {get{return p0;}} public UID0002PAV4DiskTuple B0 {get{return b0;}}
  public UID0002PAV4DiskTuple Dopen {get{return dopen;}} public UID0002PAV4DiskTuple Dclosed {get{return dclosed;}}
  public UID0002PAV4DiskTuple P1 {get{return p1;}} public bool Complete {get{return complete;}}
  public string TransactionId {get{return transactionId;}} public string SchemaSHA256 {get{return schemaSHA;}} public string PlanSHA256 {get{return planSHA;}}
  public string[] TransportTranscript {get{return transportTranscript.ToArray();}} public string[] StateTranscript {get{return stateTranscript.ToArray();}}
  public UID0002PAV4Core(UID0002PAV4Authority a,string tx) {
    if(a==null)throw new ArgumentNullException("authority");if(String.IsNullOrWhiteSpace(tx))throw new ArgumentNullException("tx");
    authority=a;transactionId=tx;journalPath=a.CanonicalPath+".uid0002pa-v4.journal";
    journal=new FileStream(journalPath,FileMode.CreateNew,FileAccess.ReadWrite,FileShare.None);Write("CREATED",null);
  }
  static string Esc(string s){return (s??"").Replace("\\","\\\\").Replace("\"","\\\"").Replace("\r","\\r").Replace("\n","\\n");}
  static string Hash(string s){using(SHA256 h=SHA256.Create()){return BitConverter.ToString(h.ComputeHash(Encoding.UTF8.GetBytes(s??""))).Replace("-","");}}
  static string B64(string s){return Convert.ToBase64String(new UTF8Encoding(false).GetBytes(s??""));}
  void Write(string next,string detail){state=next;string text="{\"schema\":4,\"uid\":\"0002PA\",\"transaction\":\""+Esc(transactionId)+"\",\"state\":\""+Esc(state)+"\",\"save_count\":"+saves+",\"transport_calls\":"+transports+",\"retire_calls\":"+retires+",\"restore_writes\":"+restores+",\"detail\":\""+Esc(detail)+"\"}";byte[] b=new UTF8Encoding(false).GetBytes(text);journal.Position=0;journal.SetLength(0);journal.Write(b,0,b.Length);journal.Flush(true);stateTranscript.Add(text);}
  public object Send(string payload){checked{transports++;}Write("TRANSPORT",Hash(payload));try{object result=authority.Send(payload);transportTranscript.Add("SEND|"+transports+"|"+B64(payload)+"|RETURN|"+B64(Convert.ToString(result)));return result;}catch(Exception ex){transportTranscript.Add("SEND|"+transports+"|"+B64(payload)+"|THROW|"+B64(ex.GetType().FullName+"|"+ex.Message));throw;}}
  public object Retire(string payload){checked{retires++;}Write("RETIRE",Hash(payload));try{object result=authority.Retire(payload);transportTranscript.Add("RETIRE|"+retires+"|"+B64(payload)+"|RETURN|"+B64(Convert.ToString(result)));return result;}catch(Exception ex){transportTranscript.Add("RETIRE|"+retires+"|"+B64(payload)+"|THROW|"+B64(ex.GetType().FullName+"|"+ex.Message));throw;}}
  public void FreezePackage(string schemas,string plan){if(schemaSHA!=null)throw new InvalidOperationException("PK4-PA package already frozen");schemaSHA=Hash(schemas);planSHA=Hash(plan);Write("PACKAGE_FROZEN",schemaSHA+"|"+planSHA);}
  public void AssertPackage(string schemas,string plan){if(schemaSHA!=Hash(schemas)||planSHA!=Hash(plan))throw new InvalidOperationException("PK4-PA frozen package drift");}
  public void SetBackup(UID0002PAV4DiskTuple pre,UID0002PAV4DiskTuple backup){if(pre==null||backup==null||!pre.SameContent(backup))throw new InvalidOperationException("BK4-PA P0/B0 mismatch");p0=pre;b0=backup;Write("P0_B0_PROVEN",null);}
  public void RegisterOpenReceipt(string role,string preferred,string returned){if(String.IsNullOrWhiteSpace(role)||String.IsNullOrWhiteSpace(preferred))throw new InvalidOperationException("OP4-PA invalid provisional receipt");Write("OPEN_RECEIPT",role+"|"+preferred+"|"+(returned??""));}
  public void FreezeRole(UID0002PAV4Role role){if(role==null)throw new InvalidOperationException("RT4-PA null role");roles[role.RoleName]=role.AuthoritySHA256;Write("ROLE_FROZEN",role.RoleName+"|"+role.SessionId);}
  public void AssertRole(UID0002PAV4Role role){string h;if(role==null||!roles.TryGetValue(role.RoleName,out h)||h!=role.AuthoritySHA256)throw new InvalidOperationException("RT4-PA frozen role drift before save");}
  public void ClaimSave(){if(saves!=0)throw new InvalidOperationException("SV4-PA sole durable save already claimed");checked{saves++;}Write("SAVE_DISPATCHED",null);}
  public void RecordDopen(UID0002PAV4DiskTuple t){if(saves!=1||t==null)throw new InvalidOperationException("DS4-PA Dopen missing/out of order");dopen=t;Write("DOPEN",t.SHA256);}
  public void RecordDclosed(UID0002PAV4DiskTuple t){if(saves!=1||dopen==null||t==null)throw new InvalidOperationException("DS4-PA Dclosed missing/out of order");dclosed=t;Write("DCLOSED",t.SHA256);}
  public void SetP1(){if(dclosed==null||dclosed.Same(p0)||dclosed.SameContent(p0))throw new InvalidOperationException("DS4-PA P1 must be byte-distinct");p1=dclosed;Write("P1_AUTHENTICATED",p1.SHA256);}
  public void AuthorizeRestore(UID0002PAV4DiskTuple destination,UID0002PAV4DiskTuple source){if(p1==null||!destination.Same(p1)||b0==null||!source.Same(b0))throw new InvalidOperationException("RS4-PA held P1/B0 authority mismatch");checked{restores++;}Write("RESTORE_AUTHORIZED",null);}
  public void CompleteNoSave(){if(saves!=0||p0==null||b0==null)throw new InvalidOperationException("NS4-PA incomplete no-save closure");complete=true;Write("COMPLETE_NO_SAVE",null);}
  public void CompleteTerminal(string terminal){if(String.IsNullOrWhiteSpace(terminal))throw new InvalidOperationException("TX4-PA empty terminal");complete=true;Write("COMPLETE_TERMINAL",terminal);}
  public UID0002PAV4Failure Failure(string label,Exception inner){Write("FAILED_CLOSED",label);return new UID0002PAV4Failure(label,saves,transports,retires,restores,dopen!=null,journalPath,inner);}
  public void Dispose(){journal.Dispose();if(complete&&File.Exists(journalPath))File.Delete(journalPath);}
}
'@
}

function Get-UID0002PAV4TextSHA256 {
    param([Parameter(Mandatory=$true)][string]$Text)
    $bytes=[Text.Encoding]::UTF8.GetBytes($Text);$sha=[Security.Cryptography.SHA256]::Create()
    try { ([BitConverter]::ToString($sha.ComputeHash($bytes))).Replace('-','') } finally { $sha.Dispose() }
}

function ConvertTo-UID0002PAV4CanonicalNode {
    param($Value)
    if ($null -eq $Value) { return 'null' }
    if ($Value -is [string]) { return ($Value | ConvertTo-Json -Compress) }
    if ($Value -is [bool]) { if($Value){return 'true'}else{return 'false'} }
    if ($Value -is [byte] -or $Value -is [sbyte] -or $Value -is [int16] -or $Value -is [uint16] -or $Value -is [int32] -or $Value -is [uint32] -or $Value -is [int64] -or $Value -is [uint64] -or $Value -is [single] -or $Value -is [double] -or $Value -is [decimal]) { return [Convert]::ToString($Value,[Globalization.CultureInfo]::InvariantCulture) }
    if ($Value -is [Collections.IDictionary]) {
        $parts=@();foreach($key in @($Value.Keys|ForEach-Object{[string]$_}|Sort-Object)){$parts+=(($key|ConvertTo-Json -Compress)+':'+(ConvertTo-UID0002PAV4CanonicalNode $Value[$key]))};return '{'+($parts-join',')+'}'
    }
    if ($Value -is [System.Array] -or ($Value -is [Collections.IEnumerable] -and $Value -isnot [string])) {
        $parts=@();foreach($entry in @($Value)){$parts+=ConvertTo-UID0002PAV4CanonicalNode $entry};return '['+($parts-join',')+']'
    }
    $map=[ordered]@{};foreach($property in @($Value.PSObject.Properties|Where-Object{$_.MemberType -in @('NoteProperty','Property')})){$map[$property.Name]=$property.Value};ConvertTo-UID0002PAV4CanonicalNode $map
}

function New-UID0002PAV4ScalarSchema { param([string]$Type,$Default=$null,[bool]$HasDefault=$false,$Enum=$null,$Minimum=$null,$Maximum=$null)
    $s=[ordered]@{type=$Type};if($null-ne$Enum){$s.enum=@($Enum)};if($null-ne$Minimum){$s.minimum=$Minimum};if($null-ne$Maximum){$s.maximum=$Maximum};if($HasDefault){$s.default=$Default};$s
}
function New-UID0002PAV4NullableStringSchema { param($Default=$null,[bool]$HasDefault=$true) $s=[ordered]@{oneOf=@((New-UID0002PAV4ScalarSchema string),(New-UID0002PAV4ScalarSchema null))};if($HasDefault){$s.default=$Default};$s }
function New-UID0002PAV4ArraySchema { param($Items,[int]$Minimum=0,$Maximum=$null) $s=[ordered]@{type='array';items=$Items;minItems=$Minimum};if($null-ne$Maximum){$s.maxItems=[int]$Maximum};$s }
function New-UID0002PAV4ObjectSchema { param([Collections.IDictionary]$Properties,[string[]]$Required=@()) [ordered]@{type='object';properties=$Properties;required=@($Required);additionalProperties=$false} }

function Get-UID0002PAV4LiteralSchemas {
    $string=New-UID0002PAV4ScalarSchema string;$boolean=New-UID0002PAV4ScalarSchema boolean;$integer=New-UID0002PAV4ScalarSchema integer
    $db=[ordered]@{database=$string};$addressItem=New-UID0002PAV4ScalarSchema string
    $query=New-UID0002PAV4ObjectSchema ([ordered]@{kind=$string;pattern=$string;offset=(New-UID0002PAV4ScalarSchema integer 0 $true $null 0 $null);limit=(New-UID0002PAV4ScalarSchema integer 100 $true $null 1 200)}) @('kind','pattern')
    $schemas=[ordered]@{}
    $schemas.idb_open=New-UID0002PAV4ObjectSchema ([ordered]@{input_path=$string;mode=(New-UID0002PAV4ScalarSchema string 'auto' $true @('auto','force_headless'));run_auto_analysis=(New-UID0002PAV4ScalarSchema boolean $true $true);build_caches=(New-UID0002PAV4ScalarSchema boolean $true $true);init_hexrays=(New-UID0002PAV4ScalarSchema boolean $true $true);idle_ttl_sec=(New-UID0002PAV4ScalarSchema integer 600 $true $null 1 86400);preferred_session_id=(New-UID0002PAV4NullableStringSchema $null $true)}) @('input_path')
    $schemas.idb_list=New-UID0002PAV4ObjectSchema ([ordered]@{}) @()
    $schemas.runtime_attestation=New-UID0002PAV4ObjectSchema ([ordered]@{expected_database=(New-UID0002PAV4NullableStringSchema);expected_canonical_path=(New-UID0002PAV4NullableStringSchema)}) @()
    $schemas.analyze_function=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;addr=$string;include_asm=(New-UID0002PAV4ScalarSchema boolean $false $true)}) @('database','addr')
    $schemas.stack_frame=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;addrs=$string}) @('database','addrs')
    $schemas.xref_query=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;queries=(New-UID0002PAV4ObjectSchema ([ordered]@{mode=$string;query=$string;offset=(New-UID0002PAV4ScalarSchema integer 0 $true $null 0 $null);limit=(New-UID0002PAV4ScalarSchema integer 200 $true $null 1 200)}) @('mode','query'))}) @('database','queries')
    $schemas.callees=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;addrs=$string;limit=(New-UID0002PAV4ScalarSchema integer 200 $true $null 1 200)}) @('database','addrs')
    $schemas.get_bytes=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;regions=(New-UID0002PAV4ArraySchema (New-UID0002PAV4ObjectSchema ([ordered]@{addr=$string;size=(New-UID0002PAV4ScalarSchema integer $null $false $null 1 1048576)}) @('addr','size')) 1 128)}) @('database','regions')
    $schemas.inspect_items=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;addrs=(New-UID0002PAV4ArraySchema $addressItem 1 512)}) @('database','addrs')
    $schemas.get_comments=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;addrs=(New-UID0002PAV4ArraySchema $addressItem 1 512)}) @('database','addrs')
    $schemas.entity_query=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;queries=(New-UID0002PAV4ArraySchema $query 1 200)}) @('database','queries')
    $schemas.type_inspect=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;queries=(New-UID0002PAV4ArraySchema (New-UID0002PAV4ObjectSchema ([ordered]@{kind=$string;name=$string}) @('kind','name')) 1 200)}) @('database','queries')
    $schemas.type_query=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;queries=(New-UID0002PAV4ArraySchema (New-UID0002PAV4ObjectSchema ([ordered]@{name=$string;offset=(New-UID0002PAV4ScalarSchema integer 0 $true $null 0 $null);limit=(New-UID0002PAV4ScalarSchema integer 200 $true $null 1 200)}) @('name')) 1 200)}) @('database','queries')
    $schemas.declare_type=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;decls=(New-UID0002PAV4ArraySchema (New-UID0002PAV4ObjectSchema ([ordered]@{decl=$string;kind=$string}) @('decl','kind')) 1 32)}) @('database','decls')
    $schemas.rename=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;batch=(New-UID0002PAV4ObjectSchema ([ordered]@{functions=(New-UID0002PAV4ArraySchema (New-UID0002PAV4ObjectSchema ([ordered]@{addr=$string;name=$string}) @('addr','name')) 0 64);globals=(New-UID0002PAV4ArraySchema (New-UID0002PAV4ObjectSchema ([ordered]@{addr=$string;name=$string}) @('addr','name')) 0 64);types=(New-UID0002PAV4ArraySchema (New-UID0002PAV4ObjectSchema ([ordered]@{old=$string;new=$string}) @('old','new')) 0 64)}) @('functions','globals','types'))}) @('database','batch')
    $schemas.set_type=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;edits=(New-UID0002PAV4ObjectSchema ([ordered]@{functions=(New-UID0002PAV4ArraySchema (New-UID0002PAV4ObjectSchema ([ordered]@{addr=$string;type=$string}) @('addr','type')) 0 64);globals=(New-UID0002PAV4ArraySchema (New-UID0002PAV4ObjectSchema ([ordered]@{addr=$string;type=$string}) @('addr','type')) 0 64)}) @('functions','globals'))}) @('database','edits')
    $schemas.set_function_comments=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;items=(New-UID0002PAV4ObjectSchema ([ordered]@{items=(New-UID0002PAV4ArraySchema (New-UID0002PAV4ObjectSchema ([ordered]@{addr=$string;comment=$string}) @('addr','comment')) 1 64)}) @('items'))}) @('database','items')
    $schemas.set_address_comments=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;items=(New-UID0002PAV4ArraySchema (New-UID0002PAV4ObjectSchema ([ordered]@{addr=$string;channel=(New-UID0002PAV4ScalarSchema string $null $false @('regular','repeatable'));comment=$string}) @('addr','channel','comment')) 1 64)}) @('database','items')
    $schemas.idb_save=New-UID0002PAV4ObjectSchema ([ordered]@{database=$string;path=$string}) @('database','path')
    if($schemas.Count-ne19){throw 'SC4-PA literal schema count mismatch'};$schemas
}

function Assert-UID0002PAV4ExactKeys { param($Object,[string[]]$Keys,[string]$Label)
    if($null-eq$Object){throw "$Label null object"};$actual=@($Object.PSObject.Properties|ForEach-Object{[string]$_.Name}|Sort-Object);$expected=@($Keys|Sort-Object);if(($actual-join'|')-cne($expected-join'|')){throw "$Label exact key mismatch actual=[$($actual-join',')] expected=[$($expected-join',')]"}
}
function Assert-UID0002PAV4NativeString {param($Value,[string]$Label)if($Value-isnot[string]){throw "$Label native string mismatch"}}
function Assert-UID0002PAV4NativeBoolean {param($Value,[string]$Label)if($Value-isnot[bool]){throw "$Label native Boolean mismatch"}}
function Assert-UID0002PAV4NativeInteger {param($Value,[string]$Label)if($Value-is[bool]-or$Value-isnot[int]-and$Value-isnot[long]){throw "$Label native integer mismatch"}}
function Assert-UID0002PAV4NativeArray {param($Value,[string]$Label)if($Value-isnot[System.Array]){throw "$Label native array mismatch"}}

function ConvertFrom-UID0002PAV4StrictJson { param([Parameter(Mandatory=$true)][string]$Raw,[string]$Label='JSON')
    Assert-UID0002PARawJsonUnique $Raw $Label
    try{$Raw|ConvertFrom-Json}catch{throw "$Label malformed JSON: $($_.Exception.Message)"}
}
function New-UID0002PAV4Request { param($Id,[string]$Tool,[Collections.IDictionary]$Arguments)
    if($Id-is[bool]-or($Id-isnot[string]-and$Id-isnot[int]-and$Id-isnot[long])){throw 'RQ4-PA non-native request id'}
    ([ordered]@{jsonrpc='2.0';id=$Id;method='tools/call';params=[ordered]@{name=$Tool;arguments=$Arguments}}|ConvertTo-Json -Depth 100 -Compress)
}
function New-UID0002PAV4ToolsListRequest {param($Id)([ordered]@{jsonrpc='2.0';id=$Id;method='tools/list';params=[ordered]@{}}|ConvertTo-Json -Compress)}

function Get-UID0002PAV4RequestIdentity { param([string]$Raw,[string]$Label)
    $o=ConvertFrom-UID0002PAV4StrictJson $Raw $Label;Assert-UID0002PAV4ExactKeys $o @('jsonrpc','id','method','params') $Label
    Assert-UID0002PAV4NativeString $o.jsonrpc "$Label jsonrpc";if($o.jsonrpc-cne'2.0'){throw "$Label jsonrpc mismatch"};if($o.id-is[bool]-or($o.id-isnot[string]-and$o.id-isnot[int]-and$o.id-isnot[long])){throw "$Label id type mismatch"};Assert-UID0002PAV4NativeString $o.method "$Label method"
    [pscustomobject]@{Parsed=$o;Id=$o.id;IdType=$o.id.GetType().FullName;SHA256=Get-UID0002PAV4TextSHA256 $Raw}
}

function Get-UID0002PAV4ToolContent { param([string]$RawResponse,[string]$Request,[string]$Label,[switch]$AllowError)
    $requestIdentity=Get-UID0002PAV4RequestIdentity $Request "$Label request";$response=ConvertFrom-UID0002PAV4StrictJson $RawResponse "$Label response"
    Assert-UID0002PAV4ExactKeys $response @('jsonrpc','id','result') "$Label response";Assert-UID0002PAV4NativeString $response.jsonrpc "$Label response jsonrpc";if($response.jsonrpc-cne'2.0'-or$response.id.GetType().FullName-cne$requestIdentity.IdType-or$response.id-ne$requestIdentity.Id){throw "$Label response correlation mismatch"}
    Assert-UID0002PAV4ExactKeys $response.result @('isError','structuredContent') "$Label result";Assert-UID0002PAV4NativeBoolean $response.result.isError "$Label isError";if(-not$AllowError-and$response.result.isError){throw "$Label tool error"};[pscustomobject]@{IsError=[bool]$response.result.isError;Content=$response.result.structuredContent;Response=$response}
}

function Get-UID0002PAV4TupleFromStream { param([IO.FileStream]$Stream,[string]$ExpectedPath)
    Initialize-UID0002PANativeSealedTypes;$old=[UID0002PANativeSealedCore]::ReadTuple($Stream,[IO.Path]::GetFullPath($ExpectedPath));[UID0002PAV4DiskTuple]::new($old.FullPath,$old.Length,$old.LastWriteTimeUtcTicks,$old.SHA256,$old.VolumeSerial,$old.FileIndex)
}
function Get-UID0002PAV4ExclusiveTuple { param([string]$Path)
    $stream=[IO.FileStream]::new([IO.Path]::GetFullPath($Path),[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);try{Get-UID0002PAV4TupleFromStream $stream $Path}finally{$stream.Dispose()}
}
function Assert-UID0002PAV4Tuple {param([UID0002PAV4DiskTuple]$Actual,[UID0002PAV4DiskTuple]$Expected,[string]$Label)if($null-eq$Actual-or-not$Actual.Same($Expected)){throw "$Label exact tuple mismatch"}}

function New-UID0002PAV4Authority { param([Parameter(Mandatory=$true)][string]$CanonicalPath,[Parameter(Mandatory=$true)][string]$SourceRoot,[scriptblock]$Transport,[scriptblock]$RetireExactGeneration)
    Initialize-UID0002PAV4SealedTypes;if($null-eq$Transport){throw 'CT4-PA transport adapter required'};if($null-eq$RetireExactGeneration){throw 'CT4-PA retirement adapter required'};[UID0002PAV4Authority]::new($CanonicalPath,$SourceRoot,$Transport,$RetireExactGeneration)
}

function Get-UID0002PAV4ModuleProof { param($Process,[string]$SourceRoot,[string]$Label)
    Assert-UID0002PAV4ExactKeys $Process @('pid','generation','modules','implementation_manifest_sha256') "$Label process";Assert-UID0002PAV4NativeInteger $Process.pid "$Label pid";Assert-UID0002PAV4NativeString $Process.generation "$Label generation";Assert-UID0002PAV4NativeArray $Process.modules "$Label modules"
    $root=[IO.Path]::GetFullPath($SourceRoot).TrimEnd('\')+'\';$stable=@();$processRows=@();$moduleIds=New-Object 'Collections.Generic.HashSet[string]' ([StringComparer]::Ordinal)
    foreach($row in @($Process.modules)){
        Assert-UID0002PAV4ExactKeys $row @('module_id','file','spec_origin','resolved_path','size','last_write_time_utc_ticks','sha256') "$Label module";foreach($name in @('module_id','file','spec_origin','resolved_path','sha256')){Assert-UID0002PAV4NativeString $row.$name "$Label $name"};Assert-UID0002PAV4NativeInteger $row.size "$Label size";Assert-UID0002PAV4NativeInteger $row.last_write_time_utc_ticks "$Label ticks";if(-not$moduleIds.Add([string]$row.module_id)){throw "$Label duplicate process-local module_id"}
        $resolved=[IO.Path]::GetFullPath([string]$row.resolved_path);if(-not$resolved.StartsWith($root,[StringComparison]::OrdinalIgnoreCase)){throw "$Label module outside bound source root"};$info=Get-Item -LiteralPath $resolved -ErrorAction Stop;$hash=(Get-FileHash -Algorithm SHA256 -LiteralPath $resolved).Hash
        if([long]$row.size-ne[long]$info.Length-or[long]$row.last_write_time_utc_ticks-ne[long]$info.LastWriteTimeUtc.Ticks-or[string]$row.sha256-cne$hash){throw "MD4-PA module manifest drift"}
        $stable+=[ordered]@{file=[string]$row.file;spec_origin=[string]$row.spec_origin;resolved_path=$resolved;size=[long]$info.Length;last_write_time_utc_ticks=[long]$info.LastWriteTimeUtc.Ticks;sha256=$hash}
        $processRows+=[ordered]@{module_id=[string]$row.module_id;stable=$stable[-1]}
    }
    $stableJson=ConvertTo-UID0002PAV4CanonicalNode @($stable|Sort-Object resolved_path);$stableSha=Get-UID0002PAV4TextSHA256 $stableJson;$processSha=Get-UID0002PAV4TextSHA256 (ConvertTo-UID0002PAV4CanonicalNode @($processRows|Sort-Object{$_.stable.resolved_path}))
    Assert-UID0002PAV4NativeString $Process.implementation_manifest_sha256 "$Label implementation digest";if([string]$Process.implementation_manifest_sha256-cne$stableSha){throw 'MD4-PA aggregate implementation manifest mismatch'}
    [pscustomobject]@{StableSHA256=$stableSha;ProcessSHA256=$processSha}
}

function New-UID0002PAV4FixtureResponse { param($Request,$Content,[bool]$IsError=$false)
    $id=(Get-UID0002PAV4RequestIdentity $Request 'fixture response request').Id;([ordered]@{jsonrpc='2.0';id=$id;result=[ordered]@{isError=$IsError;structuredContent=$Content}}|ConvertTo-Json -Depth 100 -Compress)
}
function New-UID0002PAV4FixtureToolsResponse { param($Request,$Schemas)
    $id=(Get-UID0002PAV4RequestIdentity $Request 'fixture tools request').Id;$tools=@();foreach($name in @($Schemas.Keys|Sort-Object)){$tools+=[ordered]@{name=$name;inputSchema=$Schemas[$name]}};([ordered]@{jsonrpc='2.0';id=$id;result=[ordered]@{tools=$tools}}|ConvertTo-Json -Depth 100 -Compress)
}

function Get-UID0002PAV4RoleFromEvidence { param([string]$RoleName,[string]$SessionId,[string]$CanonicalPath,$List,$Runtime,[string]$SourceRoot)
    Assert-UID0002PAV4ExactKeys $Runtime @('schema_version','ok','errors','listener','workers') 'RT4-PA runtime';Assert-UID0002PAV4NativeInteger $Runtime.schema_version 'RT4-PA runtime schema_version';if($Runtime.schema_version-ne1){throw 'RT4-PA runtime schema mismatch'};Assert-UID0002PAV4NativeBoolean $Runtime.ok 'RT4-PA runtime ok';if(-not$Runtime.ok){throw 'RT4-PA runtime not ok'};Assert-UID0002PAV4NativeArray $Runtime.errors 'RT4-PA runtime errors';if(@($Runtime.errors).Count-ne0){throw 'RT4-PA runtime errors nonempty'}
    Assert-UID0002PAV4ExactKeys $List @('sessions') 'RT4-PA list';Assert-UID0002PAV4NativeArray $List.sessions 'RT4-PA list sessions';$row=@($List.sessions|Where-Object{[string]$_.session_id-ceq$SessionId});if($row.Count-ne1){throw 'RT4-PA exact returned session absent'};$row=$row[0];Assert-UID0002PAV4ExactKeys $row @('session_id','input_path','is_active','owned','redirector_pid','redirector_generation','worker_pid','worker_generation','route_port','endpoint','socket_owner_pid') 'RT4-PA list row'
    foreach($field in @('session_id','input_path','redirector_generation','worker_generation','endpoint')){Assert-UID0002PAV4NativeString $row.$field "RT4-PA list $field"};foreach($field in @('is_active','owned')){Assert-UID0002PAV4NativeBoolean $row.$field "RT4-PA list $field"};foreach($field in @('redirector_pid','worker_pid','route_port','socket_owner_pid')){Assert-UID0002PAV4NativeInteger $row.$field "RT4-PA list $field"}
    if(-not$row.is_active-or-not$row.owned-or[IO.Path]::GetFullPath([string]$row.input_path)-ine[IO.Path]::GetFullPath($CanonicalPath)){throw 'RT4-PA list identity mismatch'}
    Assert-UID0002PAV4ExactKeys $Runtime.listener @('ok','errors','nonce','endpoint','process') 'RT4-PA listener';Assert-UID0002PAV4NativeBoolean $Runtime.listener.ok 'RT4-PA listener ok';if(-not$Runtime.listener.ok){throw 'RT4-PA listener not ok'};Assert-UID0002PAV4NativeArray $Runtime.listener.errors 'RT4-PA listener errors';if(@($Runtime.listener.errors).Count-ne0){throw 'RT4-PA listener errors nonempty'};Assert-UID0002PAV4NativeString $Runtime.listener.nonce 'RT4-PA listener nonce';Assert-UID0002PAV4ExactKeys $Runtime.listener.endpoint @('host','port','owner_pid') 'RT4-PA listener endpoint';Assert-UID0002PAV4NativeString $Runtime.listener.endpoint.host 'RT4-PA listener host';Assert-UID0002PAV4NativeInteger $Runtime.listener.endpoint.port 'RT4-PA listener port';Assert-UID0002PAV4NativeInteger $Runtime.listener.endpoint.owner_pid 'RT4-PA listener owner PID';$listenerModule=Get-UID0002PAV4ModuleProof $Runtime.listener.process $SourceRoot 'RT4-PA listener';if([string]$Runtime.listener.endpoint.host-cne'127.0.0.1'-or[int]$Runtime.listener.endpoint.port-ne13337-or[int]$Runtime.listener.endpoint.owner_pid-ne[int]$Runtime.listener.process.pid){throw 'RT4-PA listener endpoint/process authority mismatch'}
    Assert-UID0002PAV4NativeArray $Runtime.workers 'RT4-PA workers';$worker=@($Runtime.workers|Where-Object{[int]$_.process.pid-eq[int]$row.worker_pid});if($worker.Count-ne1){throw 'RT4-PA worker route mismatch'};$worker=$worker[0]
    Assert-UID0002PAV4ExactKeys $worker @('ok','errors','nonce','route','process','supervisor_sessions') 'RT4-PA worker';Assert-UID0002PAV4NativeBoolean $worker.ok 'RT4-PA worker ok';if(-not$worker.ok){throw 'RT4-PA worker not ok'};Assert-UID0002PAV4NativeArray $worker.errors 'RT4-PA worker errors';if(@($worker.errors).Count-ne0){throw 'RT4-PA worker errors nonempty'};Assert-UID0002PAV4NativeString $worker.nonce 'RT4-PA worker nonce'
    Assert-UID0002PAV4ExactKeys $worker.route @('host','port') 'RT4-PA worker route';Assert-UID0002PAV4NativeString $worker.route.host 'RT4-PA worker route host';Assert-UID0002PAV4NativeInteger $worker.route.port 'RT4-PA worker route port';if([int]$worker.route.port-ne[int]$row.route_port-or[string]$row.endpoint-cne("$([string]$worker.route.host):$([int]$worker.route.port)")-or[int]$row.socket_owner_pid-ne[int]$row.redirector_pid){throw 'RT4-PA worker route/socket mismatch'};if([int]$worker.process.pid-ne[int]$row.worker_pid-or[string]$worker.process.generation-cne[string]$row.worker_generation){throw 'RT4-PA worker process generation mismatch'}
    $sessions=@($worker.supervisor_sessions|Where-Object{[string]$_.session_id-ceq$SessionId});if($sessions.Count-ne1){throw 'RT4-PA supervisor session mismatch'};$session=$sessions[0];Assert-UID0002PAV4ExactKeys $session @('session_id','canonical_path','owned','redirector_pid','redirector_generation','route_port','endpoint','socket_owner_pid') 'RT4-PA supervisor session';foreach($field in @('session_id','canonical_path','redirector_generation','endpoint')){Assert-UID0002PAV4NativeString $session.$field "RT4-PA supervisor $field"};Assert-UID0002PAV4NativeBoolean $session.owned 'RT4-PA supervisor owned';foreach($field in @('redirector_pid','route_port','socket_owner_pid')){Assert-UID0002PAV4NativeInteger $session.$field "RT4-PA supervisor $field"};if(-not$session.owned-or[IO.Path]::GetFullPath([string]$session.canonical_path)-ine[IO.Path]::GetFullPath($CanonicalPath)-or[int]$session.redirector_pid-ne[int]$row.redirector_pid-or[string]$session.redirector_generation-cne[string]$row.redirector_generation-or[int]$session.route_port-ne[int]$row.route_port-or[string]$session.endpoint-cne[string]$row.endpoint-or[int]$session.socket_owner_pid-ne[int]$row.socket_owner_pid){throw 'RT4-PA supervisor session authority mismatch'}
    $module=Get-UID0002PAV4ModuleProof $worker.process $SourceRoot 'RT4-PA worker';$stableCombined=Get-UID0002PAV4TextSHA256 ($listenerModule.StableSHA256+'|'+$module.StableSHA256);$processCombined=Get-UID0002PAV4TextSHA256 ($listenerModule.ProcessSHA256+'|'+$module.ProcessSHA256);$authorityText=ConvertTo-UID0002PAV4CanonicalNode ([ordered]@{role=$RoleName;session=$SessionId;path=[IO.Path]::GetFullPath($CanonicalPath);nonce_policy='fresh-per-attestation';listener_pid=[int]$Runtime.listener.process.pid;listener_generation=[string]$Runtime.listener.process.generation;listener_endpoint=$Runtime.listener.endpoint;listener_stable_manifest=$listenerModule.StableSHA256;listener_process_manifest=$listenerModule.ProcessSHA256;redirector_pid=[int]$row.redirector_pid;redirector_generation=[string]$row.redirector_generation;worker_pid=[int]$row.worker_pid;worker_generation=[string]$row.worker_generation;route_port=[int]$row.route_port;endpoint=[string]$row.endpoint;socket_owner_pid=[int]$row.socket_owner_pid;stable_manifest=$stableCombined;process_manifest=$processCombined})
    [UID0002PAV4Role]::new($RoleName,$SessionId,$CanonicalPath,[int]$Runtime.listener.process.pid,[string]$Runtime.listener.process.generation,[string]$Runtime.listener.nonce,$listenerModule.StableSHA256,$listenerModule.ProcessSHA256,[int]$row.redirector_pid,[string]$row.redirector_generation,[int]$row.worker_pid,[string]$row.worker_generation,[int]$row.route_port,[string]$row.endpoint,[int]$row.socket_owner_pid,[string]$worker.nonce,$stableCombined,$processCombined,(Get-UID0002PAV4TextSHA256 $authorityText))
}

function Test-UID0002PAV4ProcessGenerationAbsentOrReused { param([int]$ProcessId,[string]$Generation)
    try{$p=[Diagnostics.Process]::GetProcessById($ProcessId);try{$actual="pid:$ProcessId;started:$($p.StartTime.ToUniversalTime().Ticks)";return $actual-cne$Generation}finally{$p.Dispose()}}catch{return $true}
}
function Test-UID0002PAV4SocketAbsent {param([int]$Port)$listeners=[Net.NetworkInformation.IPGlobalProperties]::GetIPGlobalProperties().GetActiveTcpListeners();return @($listeners|Where-Object{$_.Port-eq$Port}).Count-eq0}

function ConvertTo-UID0002PAV4TupleReceipt {param([UID0002PAV4DiskTuple]$Tuple)
    if($null-eq$Tuple){return $null};[ordered]@{full_path=[string]$Tuple.FullPath;length=[long]$Tuple.Length;last_write_time_utc_ticks=[long]$Tuple.LastWriteTimeUtcTicks;sha256=[string]$Tuple.SHA256;volume_serial=[long]$Tuple.VolumeSerial;file_index=[string]$Tuple.FileIndex.ToString([Globalization.CultureInfo]::InvariantCulture)}
}
function New-UID0002PAV4ProductionReceipt {param([UID0002PAV4Core]$Core,[string]$Status,[string]$DatabaseSession,[string]$Cause,[bool]$JournalRetained)
    $transport=@($Core.TransportTranscript);$states=@($Core.StateTranscript);$terminal=if($Status-ceq'P1_VERIFIED'){'P1'}elseif($Status-ceq'RESTORED_P0_VERIFIED'){'RESTORED_P0'}elseif($Status-ceq'COMPLETE_NO_SAVE'){'NO_SAVE'}elseif($Status-like'P0_VERIFIED_*'){'P0'}else{throw 'TR4-PA unsupported production terminal'}
    [pscustomobject][ordered]@{Kind='Production';ReceiptSchema=1L;Status=$Status;TerminalClass=$terminal;Cause=if($null-eq$Cause){''}else{$Cause};CanonicalDatabase=[string]$Core.P0.FullPath;DatabaseSession=$DatabaseSession;TransactionId=[string]$Core.TransactionId;FinalState=[string]$Core.State;SaveDispatchCount=[long]$Core.SaveDispatchCount;TransportCalls=[long]$Core.TransportCalls;RetireCalls=[long]$Core.RetireCalls;RestoreWrites=[long]$Core.RestoreWrites;DopenCaptured=[bool]($null-ne$Core.Dopen);JournalRetained=$JournalRetained;SchemaSHA256=[string]$Core.SchemaSHA256;PlanSHA256=[string]$Core.PlanSHA256;TransportLogSHA256=Get-UID0002PAV4TextSHA256 (($transport-join"`n")+"`n");StateLogSHA256=Get-UID0002PAV4TextSHA256 (($states-join"`n")+"`n");TransportLog=$transport;StateLog=$states;P0=ConvertTo-UID0002PAV4TupleReceipt $Core.P0;B0=ConvertTo-UID0002PAV4TupleReceipt $Core.B0;Dopen=ConvertTo-UID0002PAV4TupleReceipt $Core.Dopen;Dclosed=ConvertTo-UID0002PAV4TupleReceipt $Core.Dclosed;P1=ConvertTo-UID0002PAV4TupleReceipt $Core.P1}
}

function Invoke-UID0002PAClosedTransaction {
    param([UID0002PAV4Authority]$Authority)
    Initialize-UID0002PAV4SealedTypes;Initialize-UID0002PANativeSealedTypes;$entryOrdinal=[UID0002PAV4ExecutionMeter]::EnterCoordinator()
    if($args.Count-ne0){throw 'CT4-PA extra positional authority rejected'};if($null-eq$Authority){throw 'CT4-PA sealed authority required'};if(-not$Authority.HasTransport){throw 'CT4-PA transport adapter required'};if(-not$Authority.HasRetirement){throw 'CT4-PA retirement adapter required'}
    $core=$null;$backup=$null;$transactionRole=$null;$transactionSession=$null;$schemasValidated=$false;$saveObservation=$null;$stableManifestAuthority=$null;$nonceRegistry=New-Object 'Collections.Generic.HashSet[string]' ([StringComparer]::Ordinal);$canonical=$Authority.CanonicalPath;$journalPath=$canonical+'.uid0002pa-v4.journal';$backupPath=$canonical+'.uid0002pa-v4.backup';$tx=[Guid]::NewGuid().ToString('N')
    $schemas=Get-UID0002PAV4LiteralSchemas;$schemasJson=ConvertTo-UID0002PAV4CanonicalNode $schemas;$planRows=@(Get-UID0002PAConfigOracle);if($planRows.Count-ne51){throw 'PL4-PA Config plan cardinality mismatch'}
    $plan=[ordered]@{config=@($planRows);mutations=@('I01','I02Dry','I02','I03','I04','I05');phases=@('Pre','AfterI01','AfterI02','AfterI03','AfterI04','AfterI05','Final','P0Verifier','S1Verifier','RollbackVerifier')};$planJson=ConvertTo-UID0002PAV4CanonicalNode $plan
    try{
        if([IO.File]::Exists($journalPath)){throw 'JL4-PA durable journal collision'}
        try{$core=[UID0002PAV4Core]::new($Authority,$tx)}catch{if([IO.File]::Exists($journalPath)){throw 'JL4-PA durable journal collision'};throw};$core.FreezePackage($schemasJson,$planJson)
        $source=[IO.FileStream]::new($canonical,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);$destination=$null
        try{
            $p0=Get-UID0002PAV4TupleFromStream $source $canonical;if([IO.File]::Exists($backupPath)){throw 'BK4-PA backup collision'};try{$destination=[IO.FileStream]::new($backupPath,[IO.FileMode]::CreateNew,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None)}catch{if([IO.File]::Exists($backupPath)){throw 'BK4-PA backup collision'};throw};$buffer=New-Object byte[] 1048576;$copied=[long]0
            while(($read=$source.Read($buffer,0,$buffer.Length))-gt0){$destination.Write($buffer,0,$read);$copied+=$read};if($copied-ne$p0.Length-or$source.Position-ne$p0.Length-or$source.ReadByte()-ne-1-or$destination.Length-ne$p0.Length){throw 'BK4-PA counted copy/EOF mismatch'};$destination.Flush($true);[UID0002PANativeSealedCore]::SetWriteTicks($destination,$p0.LastWriteTimeUtcTicks);$heldB0=Get-UID0002PAV4TupleFromStream $destination $backupPath
        }finally{if($null-ne$destination){$destination.Dispose()};$source.Dispose()}
        $b0=Get-UID0002PAV4ExclusiveTuple $backupPath;if(-not$b0.Same($heldB0)){throw 'BK4-PA closed B0 changed'};$core.SetBackup($p0,$b0);Assert-UID0002PAV4Tuple (Get-UID0002PAV4ExclusiveTuple $canonical) $p0 'BK4-PA unchanged P0'

        $sendReadOnly={
            param([string]$request,[string]$label)
            $identity=Get-UID0002PAV4RequestIdentity $request $label;if($identity.Parsed.method-ceq'tools/call'-and[string]$identity.Parsed.params.name-ceq'idb_save'){throw 'SV4-PA read-only path cannot dispatch save'}
            $raw=[string]$core.Send($request);if([string]::IsNullOrWhiteSpace($raw)){throw "$label empty response"};$raw
        }.GetNewClosure()
        $registerRoleNonces={
            param([UID0002PAV4Role]$role)
            if($null-eq$role){throw 'NR4-PA null role'}
            foreach($nonce in @([string]$role.ListenerNonce,[string]$role.Nonce)){
                if([string]::IsNullOrWhiteSpace($nonce)-or-not$nonceRegistry.Add($nonce)){throw 'NR4-PA nonce missing/replayed'}
            }
        }.GetNewClosure()
        $toolsRequest=New-UID0002PAV4ToolsListRequest 'uid0002pa-v4-tools';$toolsRaw=&$sendReadOnly $toolsRequest 'SC4-PA tools/list';$toolsIdentity=Get-UID0002PAV4RequestIdentity $toolsRequest 'SC4-PA tools request';$toolsResponse=ConvertFrom-UID0002PAV4StrictJson $toolsRaw 'SC4-PA tools response';Assert-UID0002PAV4ExactKeys $toolsResponse @('jsonrpc','id','result') 'SC4-PA tools response';if($toolsResponse.id-ne$toolsIdentity.Id-or$toolsResponse.id.GetType().FullName-cne$toolsIdentity.IdType){throw 'SC4-PA tools response correlation mismatch'};Assert-UID0002PAV4ExactKeys $toolsResponse.result @('tools') 'SC4-PA tools result';Assert-UID0002PAV4NativeArray $toolsResponse.result.tools 'SC4-PA tools'
        $actualSchemas=[ordered]@{};foreach($tool in @($toolsResponse.result.tools)){Assert-UID0002PAV4ExactKeys $tool @('name','inputSchema') 'SC4-PA tool row';Assert-UID0002PAV4NativeString $tool.name 'SC4-PA tool name';if($actualSchemas.Contains([string]$tool.name)){throw 'SC4-PA duplicate tool'};$actualSchemas[[string]$tool.name]=$tool.inputSchema}
        if((@($actualSchemas.Keys|Sort-Object)-join'|')-cne(@($schemas.Keys|Sort-Object)-join'|')){throw 'SC4-PA used-tool set mismatch'};foreach($name in @($schemas.Keys)){if((ConvertTo-UID0002PAV4CanonicalNode $actualSchemas[$name])-cne(ConvertTo-UID0002PAV4CanonicalNode $schemas[$name])){throw "SC4-PA literal recursive schema drift: $name"}};$schemasValidated=$true

        $openRole={
            param([string]$role)
            $preferred=('uid0002pa-v4-'+$role.ToLowerInvariant()+'-'+[Guid]::NewGuid().ToString('N'));$session=$null;$core.RegisterOpenReceipt($role,$preferred,$null)
            try{
            $openRequest=New-UID0002PAV4Request ("uid0002pa-v4-open-$role-$([Guid]::NewGuid().ToString('N'))") 'idb_open' ([ordered]@{input_path=$canonical;mode='force_headless';run_auto_analysis=$false;build_caches=$false;init_hexrays=$false;idle_ttl_sec=600;preferred_session_id=$preferred})
            $openRaw=&$sendReadOnly $openRequest "OP4-PA $role open";$open=Get-UID0002PAV4ToolContent $openRaw $openRequest "OP4-PA $role open";Assert-UID0002PAV4ExactKeys $open.Content @('success','error','session') "OP4-PA $role content";Assert-UID0002PAV4NativeBoolean $open.Content.success "OP4-PA $role success";Assert-UID0002PAV4NativeString $open.Content.error "OP4-PA $role error";Assert-UID0002PAV4ExactKeys $open.Content.session @('session_id','input_path','is_analyzing') "OP4-PA $role session"
            foreach($field in @('session_id','input_path')){Assert-UID0002PAV4NativeString $open.Content.session.$field "OP4-PA $role $field"};Assert-UID0002PAV4NativeBoolean $open.Content.session.is_analyzing "OP4-PA $role is_analyzing";if(-not$open.Content.success-or$open.Content.error-cne''-or$open.Content.session.is_analyzing-or[IO.Path]::GetFullPath([string]$open.Content.session.input_path)-ine$canonical){throw "OP4-PA $role open result mismatch"}
            $session=[string]$open.Content.session.session_id;$core.RegisterOpenReceipt($role,$preferred,$session)
            $listRequest=New-UID0002PAV4Request ("uid0002pa-v4-open-list-$role") 'idb_list' ([ordered]@{});$list=(Get-UID0002PAV4ToolContent (&$sendReadOnly $listRequest "OP4-PA $role list") $listRequest "OP4-PA $role list").Content
            $runtimeRequest=New-UID0002PAV4Request ("uid0002pa-v4-open-runtime-$role") 'runtime_attestation' ([ordered]@{expected_database=$session;expected_canonical_path=$canonical});$runtime=(Get-UID0002PAV4ToolContent (&$sendReadOnly $runtimeRequest "OP4-PA $role runtime") $runtimeRequest "OP4-PA $role runtime").Content
            $roleObject=Get-UID0002PAV4RoleFromEvidence $role $session $canonical $list $runtime $Authority.SourceRoot;&$registerRoleNonces $roleObject;if($null-eq$stableManifestAuthority){$stableManifestAuthority=[pscustomobject]@{Listener=$roleObject.ListenerStableManifestSHA256;Combined=$roleObject.StableManifestSHA256}}elseif([string]$stableManifestAuthority.Listener-cne[string]$roleObject.ListenerStableManifestSHA256-or[string]$stableManifestAuthority.Combined-cne[string]$roleObject.StableManifestSHA256){throw 'MD4-PA stable cross-role manifest drift'};$core.FreezeRole($roleObject);$roleObject
            }catch{
                $openFailure=$_.Exception;while($null-ne$openFailure.InnerException){$openFailure=$openFailure.InnerException};$candidate=if([string]::IsNullOrWhiteSpace($session)){$preferred}else{$session};$candidateFound=$false
                try{
                    $recoveryListRequest=New-UID0002PAV4Request ("uid0002pa-v4-partial-list-$role") 'idb_list' ([ordered]@{});$recoveryList=(Get-UID0002PAV4ToolContent (&$sendReadOnly $recoveryListRequest "OP4-PA $role partial list") $recoveryListRequest "OP4-PA $role partial list").Content;$matches=@($recoveryList.sessions|Where-Object{[string]$_.session_id-ceq$candidate-and$_.is_active-eq$true-and[IO.Path]::GetFullPath([string]$_.input_path)-ieq$canonical})
                    if($matches.Count-gt1){throw "OP4-PA $role partial identity ambiguous"};if($matches.Count-eq1){$candidateFound=$true;$recoveryRuntimeRequest=New-UID0002PAV4Request ("uid0002pa-v4-partial-runtime-$role") 'runtime_attestation' ([ordered]@{expected_database=$candidate;expected_canonical_path=$canonical});$recoveryRuntime=(Get-UID0002PAV4ToolContent (&$sendReadOnly $recoveryRuntimeRequest "OP4-PA $role partial runtime") $recoveryRuntimeRequest "OP4-PA $role partial runtime").Content;$partialRole=Get-UID0002PAV4RoleFromEvidence $role $candidate $canonical $recoveryList $recoveryRuntime $Authority.SourceRoot;&$registerRoleNonces $partialRole;if($null-eq$stableManifestAuthority){$stableManifestAuthority=[pscustomobject]@{Listener=$partialRole.ListenerStableManifestSHA256;Combined=$partialRole.StableManifestSHA256}};$core.FreezeRole($partialRole);$null=&$closeRole $partialRole;$core.RegisterOpenReceipt(($role+'-PARTIAL-CLEANED'),$preferred,$candidate)}
                }catch{$cleanupFailure=$_.Exception;while($null-ne$cleanupFailure.InnerException){$cleanupFailure=$cleanupFailure.InnerException};throw "OP4-PA $role partial cleanup failed after [$($openFailure.Message)]: $($cleanupFailure.Message)"}
                if($candidateFound){throw $openFailure.Message};throw $openFailure.Message
            }
        }

        $closeRole={
            param([UID0002PAV4Role]$role)
            $core.AssertRole($role);$action=[ordered]@{action='RETIRE_EXACT_GENERATION';role=$role.RoleName;session_id=$role.SessionId;canonical_path=$role.CanonicalPath;redirector_pid=$role.RedirectorPid;redirector_generation=$role.RedirectorGeneration;worker_pid=$role.WorkerPid;worker_generation=$role.WorkerGeneration;route_port=$role.RoutePort;endpoint=$role.Endpoint;socket_owner_pid=$role.SocketOwnerPid;nonce=$role.Nonce;stable_manifest_sha256=$role.StableManifestSHA256;process_manifest_sha256=$role.ProcessManifestSHA256;preserve_listener=$true}
            $raw=[string]$core.Retire((ConvertTo-UID0002PAV4CanonicalNode $action));$result=ConvertFrom-UID0002PAV4StrictJson $raw 'RR4-PA retirement result';Assert-UID0002PAV4ExactKeys $result @('action','role','session_id','canonical_path','redirector_pid','redirector_generation','worker_pid','worker_generation','route_port','endpoint','socket_owner_pid','nonce','stable_manifest_sha256','process_manifest_sha256','retired','listener_preserved') 'RR4-PA retirement result'
            foreach($field in @('action','role','session_id','canonical_path','redirector_generation','worker_generation','endpoint','nonce','stable_manifest_sha256','process_manifest_sha256')){Assert-UID0002PAV4NativeString $result.$field "RR4-PA $field"};foreach($field in @('redirector_pid','worker_pid','route_port','socket_owner_pid')){Assert-UID0002PAV4NativeInteger $result.$field "RR4-PA $field"};foreach($field in @('retired','listener_preserved')){Assert-UID0002PAV4NativeBoolean $result.$field "RR4-PA $field"}
            $expected=ConvertTo-UID0002PAV4CanonicalNode ([ordered]@{action=$action.action;role=$action.role;session_id=$action.session_id;canonical_path=$action.canonical_path;redirector_pid=$action.redirector_pid;redirector_generation=$action.redirector_generation;worker_pid=$action.worker_pid;worker_generation=$action.worker_generation;route_port=$action.route_port;endpoint=$action.endpoint;socket_owner_pid=$action.socket_owner_pid;nonce=$action.nonce;stable_manifest_sha256=$action.stable_manifest_sha256;process_manifest_sha256=$action.process_manifest_sha256;retired=$true;listener_preserved=$true});if((ConvertTo-UID0002PAV4CanonicalNode $result)-cne$expected){throw 'RR4-PA sealed retirement result mismatch'}
            if(-not(Test-UID0002PAV4ProcessGenerationAbsentOrReused $role.RedirectorPid $role.RedirectorGeneration)-or-not(Test-UID0002PAV4ProcessGenerationAbsentOrReused $role.WorkerPid $role.WorkerGeneration)-or-not(Test-UID0002PAV4SocketAbsent $role.RoutePort)){throw 'RR4-PA independent process/socket absence failed'}
            $listRequest=New-UID0002PAV4Request ("uid0002pa-v4-post-list-$($role.RoleName)") 'idb_list' ([ordered]@{});$list=(Get-UID0002PAV4ToolContent (&$sendReadOnly $listRequest 'RR4-PA post list') $listRequest 'RR4-PA post list').Content;Assert-UID0002PAV4NativeArray $list.sessions 'RR4-PA post sessions';$rows=@($list.sessions|Where-Object{[string]$_.session_id-ceq$role.SessionId});if($rows.Count-gt1-or($rows.Count-eq1-and($rows[0].is_active-isnot[bool]-or$rows[0].is_active-ne$false-or[IO.Path]::GetFullPath([string]$rows[0].input_path)-ine$role.CanonicalPath))){throw 'RR4-PA retired session remains active/mismatched'}
            $runtimeRequest=New-UID0002PAV4Request ("uid0002pa-v4-post-runtime-$($role.RoleName)") 'runtime_attestation' ([ordered]@{expected_database=$null;expected_canonical_path=$canonical});$runtime=(Get-UID0002PAV4ToolContent (&$sendReadOnly $runtimeRequest 'RR4-PA post runtime') $runtimeRequest 'RR4-PA post runtime').Content;Assert-UID0002PAV4NativeBoolean $runtime.ok 'RR4-PA post runtime ok';if(-not$runtime.ok){throw 'RR4-PA post runtime failed'};$true
        }.GetNewClosure()

        $catalog={
            param([UID0002PAV4Role]$role,[string]$phase)
            $semanticFailures=@();foreach($row in $planRows){$request=New-UID0002PAV4Request ("uid0002pa-v4-$phase-$($row.name)") 'entity_query' ([ordered]@{database=$role.SessionId;queries=@([ordered]@{kind='names';pattern=('^'+[regex]::Escape([string]$row.name)+'$');offset=0;limit=1})});$content=(Get-UID0002PAV4ToolContent (&$sendReadOnly $request "PL4-PA $phase $($row.name)") $request "PL4-PA $phase $($row.name)").Content;Assert-UID0002PAV4ExactKeys $content @('ok','phase','row','row_sha256','semantic_mismatch') "PL4-PA $phase row";Assert-UID0002PAV4NativeBoolean $content.ok "PL4-PA $phase ok";foreach($field in @('phase','row','row_sha256','semantic_mismatch')){Assert-UID0002PAV4NativeString $content.$field "PL4-PA $phase $field"};$expectedSha=Get-UID0002PAV4TextSHA256 (ConvertTo-UID0002PAV4CanonicalNode $row);if([string]$content.phase-cne$phase-or[string]$content.row-cne[string]$row.name-or[string]$content.row_sha256-cne$expectedSha){throw "PL4-PA $phase literal row mismatch"};if(-not$content.ok-or-not[string]::IsNullOrEmpty([string]$content.semantic_mismatch)){$semanticFailures+=[string]$content.semantic_mismatch}}
            [pscustomobject]@{Passed=$semanticFailures.Count-eq0;Failures=@($semanticFailures);RowCount=51}
        }.GetNewClosure()

        $transactionRole=&$openRole 'Transaction';$transactionSession=[string]$transactionRole.SessionId;$null=&$catalog $transactionRole 'Pre'
        $mutations=[ordered]@{
            I01=@('declare_type',[ordered]@{database=$transactionRole.SessionId;decls=@([ordered]@{decl='struct ServerSelectEntry; struct ServerSelectDirectory;';kind='c'})})
            I02Dry=@('entity_query',[ordered]@{database=$transactionRole.SessionId;queries=@([ordered]@{kind='names';pattern='^ServerSelectDirectory__ReleaseOwnedBuffers$';offset=0;limit=1})})
            I02=@('rename',[ordered]@{database=$transactionRole.SessionId;batch=[ordered]@{functions=@([ordered]@{addr='0x494130';name='ServerSelectDirectory__ReleaseOwnedBuffers'});globals=@();types=@()}})
            I03=@('set_type',[ordered]@{database=$transactionRole.SessionId;edits=[ordered]@{functions=@([ordered]@{addr='0x494130';type='void __thiscall(ServerSelectDirectory *this)'});globals=@()}})
            I04=@('set_function_comments',[ordered]@{database=$transactionRole.SessionId;items=[ordered]@{items=@([ordered]@{addr='0x494130';comment='Releases the three owned wide-string fields for every active server-directory entry and resets entryCount/version.'})}})
            I05=@('set_address_comments',[ordered]@{database=$transactionRole.SessionId;items=@([ordered]@{addr='0x494146';channel='regular';comment='ServerSelectEntry stride is 0x18 bytes.'})})
        }
        foreach($name in @($mutations.Keys)){$entry=$mutations[$name];$request=New-UID0002PAV4Request ("uid0002pa-v4-$name") ([string]$entry[0]) $entry[1];$content=(Get-UID0002PAV4ToolContent (&$sendReadOnly $request "MU4-PA $name") $request "MU4-PA $name").Content;Assert-UID0002PAV4ExactKeys $content @('ok','operation') "MU4-PA $name result";Assert-UID0002PAV4NativeBoolean $content.ok "MU4-PA $name ok";Assert-UID0002PAV4NativeString $content.operation "MU4-PA $name operation";if(-not$content.ok-or$content.operation-cne$name){throw "MU4-PA $name semantic failure"};if($name-cne'I02Dry'){$null=&$catalog $transactionRole ("After$name")}}
        $final=&$catalog $transactionRole 'Final';if(-not$final.Passed){throw 'PL4-PA pre-save Final mismatch'}

        $core.AssertPackage($schemasJson,$planJson);$listRequest=New-UID0002PAV4Request 'uid0002pa-v4-presave-list' 'idb_list' ([ordered]@{});$preList=(Get-UID0002PAV4ToolContent (&$sendReadOnly $listRequest 'SV4-PA immediate list') $listRequest 'SV4-PA immediate list').Content
        $runtimeRequest=New-UID0002PAV4Request 'uid0002pa-v4-presave-runtime' 'runtime_attestation' ([ordered]@{expected_database=$transactionRole.SessionId;expected_canonical_path=$canonical});$preRuntime=(Get-UID0002PAV4ToolContent (&$sendReadOnly $runtimeRequest 'SV4-PA immediate runtime') $runtimeRequest 'SV4-PA immediate runtime').Content
        $preSaveRole=Get-UID0002PAV4RoleFromEvidence 'Transaction' $transactionRole.SessionId $canonical $preList $preRuntime $Authority.SourceRoot;&$registerRoleNonces $preSaveRole;$core.AssertRole($preSaveRole)
        $saveRequest=New-UID0002PAV4Request 'uid0002pa-v4-sole-save' 'idb_save' ([ordered]@{database=$transactionRole.SessionId;path=$canonical});$core.ClaimSave();$saveClass='Indeterminate';$saveRaw=$null;$saveError=$null
        try{$saveRaw=[string]$core.Send($saveRequest);if(-not[string]::IsNullOrWhiteSpace($saveRaw)){$saveResult=Get-UID0002PAV4ToolContent $saveRaw $saveRequest 'SV4-PA save' -AllowError;if(-not$saveResult.IsError-and$saveResult.Content.saved-is[bool]-and$saveResult.Content.saved-eq$true){$saveClass='DeterminateSuccess'}elseif($saveResult.IsError){$saveClass='DeterminateFailure'}}}catch{$saveError=$_.Exception.Message;if($saveError-like'*TIMEOUT*'){$saveClass='Timeout'}elseif($saveError-like'*DISCONNECT*'){$saveClass='Disconnected'}else{$saveClass='Thrown'}}finally{$stream=[IO.FileStream]::new($canonical,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::ReadWrite-bor[IO.FileShare]::Delete);try{$core.RecordDopen((Get-UID0002PAV4TupleFromStream $stream $canonical))}finally{$stream.Dispose()}}
        $null=&$closeRole $transactionRole;$transactionRole=$null;$dclosed=Get-UID0002PAV4ExclusiveTuple $canonical;$core.RecordDclosed($dclosed)
        $sameP0=$dclosed.Same($core.P0);$timestampOnly=$dclosed.SameContent($core.P0)-and-not$sameP0
        if($timestampOnly){throw 'DS4-PA timestamp-only identity refused'}
        if($sameP0){$verifier=&$openRole 'P0Verifier';$vr=&$catalog $verifier 'P0Verifier';$null=&$closeRole $verifier;if(-not$vr.Passed){throw 'VR4-PA P0 verifier failed'};Assert-UID0002PAV4Tuple (Get-UID0002PAV4ExclusiveTuple $canonical) $core.P0 'VR4-PA P0 disk';$core.CompleteTerminal("P0_VERIFIED_$saveClass");return New-UID0002PAV4ProductionReceipt $core "P0_VERIFIED_$saveClass" $transactionSession '' $false}
        if($saveClass-cne'DeterminateSuccess'){throw "DS4-PA changed output lacks determinate sole-save authority: $saveClass"};$core.SetP1();$verifier=&$openRole 'S1Verifier';$vr=&$catalog $verifier 'S1Verifier';$null=&$closeRole $verifier
        if($vr.Passed){$core.CompleteTerminal('P1_VERIFIED');return New-UID0002PAV4ProductionReceipt $core 'P1_VERIFIED' $transactionSession '' $false}
        if($vr.Failures.Count-ne1-or-not([string]$vr.Failures[0]).StartsWith('FINAL_ORACLE_MISMATCH:')){throw 'VR4-PA non-literal Final mismatch cannot authorize restore'}
        $source=[IO.FileStream]::new($backupPath,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);$destination=[IO.FileStream]::new($canonical,[IO.FileMode]::Open,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None)
        try{$heldSource=Get-UID0002PAV4TupleFromStream $source $backupPath;$heldDestination=Get-UID0002PAV4TupleFromStream $destination $canonical;$core.AuthorizeRestore($heldDestination,$heldSource);$source.Position=0;$destination.SetLength(0);$destination.Position=0;$buffer=New-Object byte[] 1048576;$copied=[long]0;while(($read=$source.Read($buffer,0,$buffer.Length))-gt0){$destination.Write($buffer,0,$read);$copied+=$read};if($copied-ne$core.P0.Length-or$source.Position-ne$core.P0.Length-or$source.ReadByte()-ne-1-or$destination.Length-ne$core.P0.Length){throw 'RS4-PA counted restore/EOF mismatch'};$destination.Flush($true);[UID0002PANativeSealedCore]::SetWriteTicks($destination,$core.P0.LastWriteTimeUtcTicks);Assert-UID0002PAV4Tuple (Get-UID0002PAV4TupleFromStream $destination $canonical) $core.P0 'RS4-PA held restored P0'}finally{$destination.Dispose();$source.Dispose()}
        Assert-UID0002PAV4Tuple (Get-UID0002PAV4ExclusiveTuple $canonical) $core.P0 'RS4-PA closed restored P0 first';Assert-UID0002PAV4Tuple (Get-UID0002PAV4ExclusiveTuple $canonical) $core.P0 'RS4-PA closed restored P0 second';$rollback=&$openRole 'RollbackVerifier';$rb=&$catalog $rollback 'RollbackVerifier';$null=&$closeRole $rollback;if(-not$rb.Passed){throw 'RS4-PA rollback verifier failed'};$core.CompleteTerminal('RESTORED_P0_VERIFIED');New-UID0002PAV4ProductionReceipt $core 'RESTORED_P0_VERIFIED' $transactionSession '' $false
    }catch{
        $caught=$_.Exception;while($null-ne$caught.InnerException){$caught=$caught.InnerException}
        if($null-ne$core-and$core.SaveDispatchCount-eq0-and$schemasValidated){
            try{if($null-ne$transactionRole){$null=&$closeRole $transactionRole;$transactionRole=$null};Assert-UID0002PAV4Tuple (Get-UID0002PAV4ExclusiveTuple $canonical) $core.P0 'NS4-PA P0';Assert-UID0002PAV4Tuple (Get-UID0002PAV4ExclusiveTuple $backupPath) $core.B0 'NS4-PA B0';$verifier=&$openRole 'P0Verifier';$vr=&$catalog $verifier 'P0Verifier';$null=&$closeRole $verifier;if(-not$vr.Passed){throw 'NS4-PA P0 verifier failed'};$core.CompleteNoSave();return New-UID0002PAV4ProductionReceipt $core 'COMPLETE_NO_SAVE' $transactionSession $caught.Message $false}catch{$caught=$_.Exception;while($null-ne$caught.InnerException){$caught=$caught.InnerException}}
        }
        if($null-ne$core){throw $core.Failure($caught.Message,$caught)};throw
    }finally{
        if($null-ne$core){$wasComplete=$core.Complete;$core.Dispose();if($wasComplete-and[IO.File]::Exists($backupPath)){[IO.File]::Delete($backupPath)}}
    }
}

function New-UID0002PAV4FixtureEnvironment { param([string]$Case,[string]$ExactRoot=$null)
    $root=if([string]::IsNullOrWhiteSpace($ExactRoot)){Join-Path ([IO.Path]::GetTempPath()) ('uid0002pa-v4-'+[Guid]::NewGuid().ToString('N'))}else{[IO.Path]::GetFullPath($ExactRoot)};$sourceRoot=Join-Path $root 'source';$canonical=Join-Path $root 'fixture.i64';$moduleA=Join-Path $sourceRoot 'listener.py';$moduleB=Join-Path $sourceRoot 'worker.py';if([string]::IsNullOrWhiteSpace($ExactRoot)){$null=New-Item -ItemType Directory -Path $sourceRoot -Force;[IO.File]::WriteAllBytes($canonical,[byte[]](1,2,3,4,5,6,7,8));[IO.File]::WriteAllText($moduleA,'listener-v4',[Text.UTF8Encoding]::new($false));[IO.File]::WriteAllText($moduleB,'worker-v4',[Text.UTF8Encoding]::new($false))}elseif(-not[IO.Directory]::Exists($sourceRoot)-or-not[IO.File]::Exists($canonical)-or-not[IO.File]::Exists($moduleA)-or-not[IO.File]::Exists($moduleB)){throw 'FX4-PA parent-owned fixture root incomplete'};$activePorts=@([Net.NetworkInformation.IPGlobalProperties]::GetIPGlobalProperties().GetActiveTcpListeners()|ForEach-Object{$_.Port});$port=65530;while($activePorts-contains$port){$port--}
    [hashtable]@{Case=$Case;Root=$root;SourceRoot=$sourceRoot;Canonical=$canonical;Schemas=Get-UID0002PAV4LiteralSchemas;Roles=[ordered]@{};RetiredSessions=(New-Object 'Collections.Generic.List[string]');EffectObservations=(New-Object 'Collections.Generic.List[object]');TransportCalls=0;RetireCalls=0;SaveCalls=0;RestoreObserved=0;AttestationCount=0;Port=$port;ModuleA=$moduleA;ModuleB=$moduleB;ModuleMutated=$false;CatalogFailureInjected=$false;BaselineHash=(Get-FileHash -Algorithm SHA256 -LiteralPath $canonical).Hash}
}

function Add-UID0002PAV4FixtureEffectObservation {param($State,[string]$Kind,[string]$Path)
    if($null-eq$State-or[string]::IsNullOrWhiteSpace($Kind)-or[string]::IsNullOrWhiteSpace($Path)){throw 'EM4-PA invalid effect observation'};$ordinal=$State.EffectObservations.Count+1;$State.EffectObservations.Add([pscustomobject][ordered]@{Ordinal=[long]$ordinal;Kind=$Kind;Path=[IO.Path]::GetFullPath($Path)})|Out-Null
}

function Get-UID0002PAV4MeasuredExternalEffects {param($State)
    if($null-eq$State){$empty=@();return [pscustomobject]@{ExternalTargetEffects=[long]$empty.Count;EffectObservations=[long]$empty.Count;ObservedPaths=$empty}}
    $root=[IO.Path]::GetFullPath([string]$State.Root).TrimEnd('\');$prefix=$root+'\';$observations=@($State.EffectObservations|ForEach-Object{$_});$expectedOrdinal=[long]1;$paths=@([IO.Path]::GetFullPath([string]$State.Canonical),[IO.Path]::GetFullPath(([string]$State.Canonical+'.uid0002pa-v4.journal')),[IO.Path]::GetFullPath(([string]$State.Canonical+'.uid0002pa-v4.backup')),[IO.Path]::GetFullPath([string]$State.ModuleA),[IO.Path]::GetFullPath([string]$State.ModuleB))
    foreach($observation in $observations){if((@($observation.PSObject.Properties.Name|Sort-Object)-join'|')-cne'Kind|Ordinal|Path'-or$observation.Ordinal-isnot[long]-or[long]$observation.Ordinal-ne$expectedOrdinal-or$observation.Kind-isnot[string]-or$observation.Path-isnot[string]){throw 'EM4-PA effect observation ledger drift'};$paths+=[IO.Path]::GetFullPath([string]$observation.Path);$expectedOrdinal++}
    $external=@($paths|Where-Object{$_-ine$root-and-not$_.StartsWith($prefix,[StringComparison]::OrdinalIgnoreCase)});[pscustomobject]@{ExternalTargetEffects=[long]$external.Count;EffectObservations=[long]$observations.Count;ObservedPaths=@($paths)}
}

function Get-UID0002PAV4FixtureModuleRows {param($State,[string]$Role)
    $rows=@();$index=0;foreach($path in @($State.ModuleA,$State.ModuleB)){$info=Get-Item -LiteralPath $path;$rows+=[ordered]@{module_id="$Role-$index";file=$info.Name;spec_origin='uid0002pa-fixture';resolved_path=$info.FullName;size=[long]$info.Length;last_write_time_utc_ticks=[long]$info.LastWriteTimeUtc.Ticks;sha256=(Get-FileHash -Algorithm SHA256 -LiteralPath $path).Hash};$index++};$stable=@();foreach($row in $rows){$stable+=[ordered]@{file=$row.file;spec_origin=$row.spec_origin;resolved_path=[IO.Path]::GetFullPath($row.resolved_path);size=$row.size;last_write_time_utc_ticks=$row.last_write_time_utc_ticks;sha256=$row.sha256}};$digest=Get-UID0002PAV4TextSHA256 (ConvertTo-UID0002PAV4CanonicalNode @($stable|Sort-Object resolved_path));[pscustomobject]@{Rows=$rows;Digest=$digest}
}

function New-UID0002PAV4FixtureAdapters { param($State)
    $transport={
        param([string]$request);$State['TransportCalls']=[int]$State['TransportCalls']+1;$identity=Get-UID0002PAV4RequestIdentity $request 'FX4-PA transport request';$o=$identity.Parsed
        if($o.method-ceq'tools/list'){$schemas=$State.Schemas;if($State.Case-ceq'NestedSchemaDrift'){$clone=($schemas|ConvertTo-Json -Depth 100|ConvertFrom-Json);$clone.idb_open.properties.idle_ttl_sec.type='string';$map=[ordered]@{};foreach($p in $clone.PSObject.Properties){$map[$p.Name]=$p.Value};$schemas=$map};return New-UID0002PAV4FixtureToolsResponse $request $schemas}
        $tool=[string]$o.params.name;$args=$o.params.arguments
        if($tool-ceq'idb_open'){Add-UID0002PAV4FixtureEffectObservation $State 'idb_open' ([string]$args.input_path)}elseif($tool-ceq'idb_save'){Add-UID0002PAV4FixtureEffectObservation $State 'idb_save' ([string]$args.path)}elseif($tool-in@('declare_type','rename','set_type','set_function_comments','set_address_comments')){$effectRole=$State.Roles[[string]$args.database];if($null-eq$effectRole){throw 'EM4-PA mutation role path absent'};Add-UID0002PAV4FixtureEffectObservation $State $tool ([string]$effectRole.Path)}
        if($tool-ceq'idb_open'){
            $preferred=[string]$args.preferred_session_id;$role=if($preferred-match'uid0002pa-v4-([a-z0-9]+)-'){$Matches[1]}else{'unknown'};if($role-ceq'transaction'){$role='Transaction'}elseif($role-ceq'p0verifier'){$role='P0Verifier'}elseif($role-ceq's1verifier'){$role='S1Verifier'}elseif($role-ceq'rollbackverifier'){$role='RollbackVerifier'}
            if($State.Case-ceq'SetupFailure'-and$role-ceq'Transaction'){throw 'OP4-PA injected setup failure'}
            $session=if($State.Case-ceq'ReturnedSessionDiffersPreferredCleanup'-and$role-ceq'Transaction'){$preferred+'-returned'}else{$preferred};$index=$State.Roles.Count;$worker=2147483000+$index;$redirector=2147483100+$index;$record=[ordered]@{Role=$role;Session=$session;Path=[IO.Path]::GetFullPath([string]$args.input_path);Active=$true;WorkerPid=$worker;RedirectorPid=$redirector;WorkerGeneration="pid:$worker;started:1";RedirectorGeneration="pid:$redirector;started:1";Port=[int]($State.Port-$index);Endpoint="127.0.0.1:$($State.Port-$index)";Nonce="nonce-$session"};$State.Roles[$session]=$record
            return New-UID0002PAV4FixtureResponse $request ([ordered]@{success=$true;error='';session=[ordered]@{session_id=$session;input_path=$record.Path;is_analyzing=$false}})
        }
        if($tool-ceq'idb_list'){$rows=@();foreach($r in @($State.Roles.Values)){$rows+=[ordered]@{session_id=$r.Session;input_path=$r.Path;is_active=[bool]$r.Active;owned=$true;redirector_pid=[int]$r.RedirectorPid;redirector_generation=[string]$r.RedirectorGeneration;worker_pid=[int]$r.WorkerPid;worker_generation=[string]$r.WorkerGeneration;route_port=[int]$r.Port;endpoint=[string]$r.Endpoint;socket_owner_pid=[int]$r.RedirectorPid}};if($State.Case-ceq'PartialOpenValidationFailure'-and[string]$identity.Parsed.id-like'uid0002pa-v4-open-list-Transaction*'){return New-UID0002PAV4FixtureResponse $request ([ordered]@{sessions='invalid'})};return New-UID0002PAV4FixtureResponse $request ([ordered]@{sessions=@($rows)})}
        if($tool-ceq'runtime_attestation'){
            $State['AttestationCount']=[int]$State['AttestationCount']+1;$attestationIndex=[int]$State['AttestationCount'];$database=[string]$args.expected_database;if($State.Case-ceq'ModuleDrift'-and$identity.Parsed.id-like'*presave-runtime*'-and-not$State.ModuleMutated){Add-UID0002PAV4FixtureEffectObservation $State 'module-drift' ([string]$State.ModuleB);[IO.File]::AppendAllText($State.ModuleB,'-drift');$State['ModuleMutated']=$true}
            $workers=@();foreach($r in @($State.Roles.Values|Where-Object{$_.Active})){$modules=Get-UID0002PAV4FixtureModuleRows $State $r.Role;$generation=[string]$r.WorkerGeneration;if($State.Case-ceq'RuntimeSessionDrift'-and$identity.Parsed.id-like'*presave-runtime*'){$generation=$generation+'-drift'};$workers+=[ordered]@{ok=$true;errors=@();nonce=([string]$r.Nonce+'-'+$attestationIndex);route=[ordered]@{host='127.0.0.1';port=[int]$r.Port};process=[ordered]@{pid=[int]$r.WorkerPid;generation=$generation;modules=@($modules.Rows);implementation_manifest_sha256=$modules.Digest};supervisor_sessions=@([ordered]@{session_id=$r.Session;canonical_path=$r.Path;owned=$true;redirector_pid=[int]$r.RedirectorPid;redirector_generation=[string]$r.RedirectorGeneration;route_port=[int]$r.Port;endpoint=[string]$r.Endpoint;socket_owner_pid=[int]$r.RedirectorPid})}}
            $listenerModules=Get-UID0002PAV4FixtureModuleRows $State 'Listener';return New-UID0002PAV4FixtureResponse $request ([ordered]@{schema_version=1;ok=$true;errors=@();listener=[ordered]@{ok=$true;errors=@();nonce=('listener-nonce-'+$attestationIndex);endpoint=[ordered]@{host='127.0.0.1';port=13337;owner_pid=2147483200};process=[ordered]@{pid=2147483200;generation='listener-generation';modules=@($listenerModules.Rows);implementation_manifest_sha256=$listenerModules.Digest}};workers=@($workers)})
        }
        if($tool-ceq'idb_save'){$State['SaveCalls']=[int]$State['SaveCalls']+1;if($State.SaveCalls-gt1){throw 'SV4-PA fixture duplicate save'};if($State.Case-in@('P1','FinalMismatchRestore','RestoreCorruption','ThirdIdentity','ThrownDopenChanged','TimeoutDopenChanged','DeterminateFailureChanged','IndeterminateChanged')){[IO.File]::WriteAllBytes($State.Canonical,[byte[]](9,8,7,6,5,4,3,2,1))};if($State.Case-like'ThrownDopen*'){throw 'UID0002PA_THROWN'};if($State.Case-like'TimeoutDopen*'){throw 'UID0002PA_TIMEOUT'};if($State.Case-ceq'DisconnectedDopen'){throw 'UID0002PA_DISCONNECT'};if($State.Case-like'DeterminateFailure*'){return New-UID0002PAV4FixtureResponse $request ([ordered]@{saved=$false;error='injected determinate failure'}) $true};if($State.Case-ceq'IndeterminateChanged'){return New-UID0002PAV4FixtureResponse $request ([ordered]@{saved=$false;error=''}) $false};return New-UID0002PAV4FixtureResponse $request ([ordered]@{saved=$true;path=$State.Canonical;database=[string]$args.database})}
        if($tool-ceq'entity_query'){
            $id=[string]$identity.Parsed.id;if($id-ceq'uid0002pa-v4-I02Dry'){return New-UID0002PAV4FixtureResponse $request ([ordered]@{ok=$true;operation='I02Dry'})};if(($State.Case-ceq'CompleteNoSave'-or$State.Case-ceq'ReturnedSessionDiffersPreferredCleanup')-and$id-like'uid0002pa-v4-Pre-*'-and-not$State.CatalogFailureInjected){$State['CatalogFailureInjected']=$true;throw 'PL4-PA injected pre-save failure'}
            if($id-match'^uid0002pa-v4-([^-]+)-(.+)$'){$phase=$Matches[1];$rowName=$Matches[2]}else{$phase='Mutation';$rowName='I02Dry'};$oracle=@(Get-UID0002PAConfigOracle|Where-Object{$_.name-ceq$rowName});$rowSha=if($oracle.Count-eq1){Get-UID0002PAV4TextSHA256 (ConvertTo-UID0002PAV4CanonicalNode $oracle[0])}else{Get-UID0002PAV4TextSHA256 'dry'};$mismatch='';$ok=$true
            if($phase-ceq'S1Verifier'-and$rowName-ceq'm_startupChannel'-and$State.Case-in@('FinalMismatchRestore','RestoreCorruption','ThirdIdentity')){$mismatch='FINAL_ORACLE_MISMATCH:m_startupChannel';$ok=$false;if($State.Case-ceq'RestoreCorruption'){Add-UID0002PAV4FixtureEffectObservation $State 'backup-corruption' ([string]($State.Canonical+'.uid0002pa-v4.backup'));[IO.File]::AppendAllText(($State.Canonical+'.uid0002pa-v4.backup'),'-corrupt')};if($State.Case-ceq'ThirdIdentity'){Add-UID0002PAV4FixtureEffectObservation $State 'third-identity' ([string]$State.Canonical);[IO.File]::WriteAllBytes($State.Canonical,[byte[]](4,4,4,4))}}
            return New-UID0002PAV4FixtureResponse $request ([ordered]@{ok=$ok;phase=$phase;row=$rowName;row_sha256=$rowSha;semantic_mismatch=$mismatch})
        }
        $operation=if([string]$identity.Parsed.id-match'uid0002pa-v4-(I0[1-5]|I02Dry)'){$Matches[1]}else{'unknown'};New-UID0002PAV4FixtureResponse $request ([ordered]@{ok=$true;operation=$operation})
    }.GetNewClosure()
    $retire={
        param([string]$raw);$State['RetireCalls']=[int]$State['RetireCalls']+1;$action=ConvertFrom-UID0002PAV4StrictJson $raw 'FX4-PA retirement action';Add-UID0002PAV4FixtureEffectObservation $State 'retire-exact-generation' ([string]$action.canonical_path);$record=$State.Roles[[string]$action.session_id];if($null-eq$record-or-not$record.Active){throw 'RR4-PA fixture unknown/already-retired role'};$record['Active']=$false;$State.RetiredSessions.Add([string]$action.session_id)
        ([ordered]@{action=[string]$action.action;role=[string]$action.role;session_id=[string]$action.session_id;canonical_path=[string]$action.canonical_path;redirector_pid=[int]$action.redirector_pid;redirector_generation=[string]$action.redirector_generation;worker_pid=[int]$action.worker_pid;worker_generation=[string]$action.worker_generation;route_port=[int]$action.route_port;endpoint=[string]$action.endpoint;socket_owner_pid=[int]$action.socket_owner_pid;nonce=[string]$action.nonce;stable_manifest_sha256=[string]$action.stable_manifest_sha256;process_manifest_sha256=[string]$action.process_manifest_sha256;retired=$true;listener_preserved=$true}|ConvertTo-Json -Compress)
    }.GetNewClosure()
    [pscustomobject]@{Transport=$transport;Retire=$retire}
}

function Invoke-UID0002PAHostileStaticFixtures {
    Initialize-UID0002PAV4SealedTypes;$cases=@('NullAuthority','NullTransport','NullRetirement','FixtureBypass','NestedSchemaDrift','RuntimeSessionDrift','ModuleDrift','PartialOpenValidationFailure','ReturnedSessionDiffersPreferredCleanup','InactiveRowRetirement','DuplicateJournal','DuplicateBackup','SetupFailure','CompleteNoSave','ThrownDopenP0','ThrownDopenChanged','TimeoutDopenP0','TimeoutDopenChanged','DisconnectedDopen','P0','P1','DeterminateFailureP0','DeterminateFailureChanged','IndeterminateChanged','FinalMismatchRestore','RestoreCorruption','ThirdIdentity');if($cases.Count-ne27){throw 'HF4-PA hostile case inventory drift'};$rows=@();$suiteEntryStart=[UID0002PAV4ExecutionMeter]::SnapshotCoordinatorEntries()
    $expectedCounts=@{
        NullAuthority=@(0,0,0,0,$false,$false);NullTransport=@(0,0,0,0,$false,$false);NullRetirement=@(0,0,0,0,$false,$false);FixtureBypass=@(0,0,0,0,$false,$false)
        NestedSchemaDrift=@(0,1,0,0,$false,$true);RuntimeSessionDrift=@(0,427,2,0,$false,$false);ModuleDrift=@(0,427,2,0,$false,$false);PartialOpenValidationFailure=@(0,64,2,0,$false,$false);ReturnedSessionDiffersPreferredCleanup=@(0,63,2,0,$false,$false)
        InactiveRowRetirement=@(1,428,2,0,$true,$false);DuplicateJournal=@(0,0,0,0,$false,$true);DuplicateBackup=@(0,0,0,0,$false,$true);SetupFailure=@(0,59,1,0,$false,$false);CompleteNoSave=@(0,63,2,0,$false,$false)
        ThrownDopenP0=@(1,428,2,0,$true,$false);ThrownDopenChanged=@(1,372,1,0,$true,$true);TimeoutDopenP0=@(1,428,2,0,$true,$false);TimeoutDopenChanged=@(1,372,1,0,$true,$true);DisconnectedDopen=@(1,428,2,0,$true,$false)
        P0=@(1,428,2,0,$true,$false);P1=@(1,428,2,0,$true,$false);DeterminateFailureP0=@(1,428,2,0,$true,$false);DeterminateFailureChanged=@(1,372,1,0,$true,$true);IndeterminateChanged=@(1,372,1,0,$true,$true)
        FinalMismatchRestore=@(1,484,3,1,$true,$false);RestoreCorruption=@(1,428,2,0,$true,$true);ThirdIdentity=@(1,428,2,0,$true,$true)
    }
    foreach($case in $cases){$state=$null;$result=$null;$label=$null;$failure=$null;$cleanupReceipt=$null;$caseEntryStart=[UID0002PAV4ExecutionMeter]::SnapshotCoordinatorEntries();try{
        try{
            if($case-ceq'NullAuthority'){$null=Invoke-UID0002PAClosedTransaction -Authority $null;throw 'HF4-PA null authority unexpectedly accepted'}
            $state=New-UID0002PAV4FixtureEnvironment $case;$adapters=New-UID0002PAV4FixtureAdapters $state
            if($case-ceq'NullTransport'){$malformed=[UID0002PAV4Authority]::new($state.Canonical,$state.SourceRoot,$null,$adapters.Retire);$null=Invoke-UID0002PAClosedTransaction -Authority $malformed;throw 'HF4-PA null transport unexpectedly accepted'}
            if($case-ceq'NullRetirement'){$malformed=[UID0002PAV4Authority]::new($state.Canonical,$state.SourceRoot,$adapters.Transport,$null);$null=Invoke-UID0002PAClosedTransaction -Authority $malformed;throw 'HF4-PA null retirement unexpectedly accepted'}
            $authority=New-UID0002PAV4Authority $state.Canonical $state.SourceRoot $adapters.Transport $adapters.Retire
            if($case-ceq'FixtureBypass'){$forgedCounters=[pscustomobject]@{ProductionCoordinatorInvocations=[long]999;ExternalTargetEffects=[long]999};$null=Invoke-UID0002PAClosedTransaction -Authority $authority $forgedCounters;throw 'HF4-PA fixture bypass unexpectedly accepted'}
            if($case-ceq'DuplicateJournal'){[IO.File]::WriteAllText(($state.Canonical+'.uid0002pa-v4.journal'),'occupied')}
            if($case-ceq'DuplicateBackup'){[IO.File]::WriteAllText(($state.Canonical+'.uid0002pa-v4.backup'),'occupied')}
            $result=Invoke-UID0002PAClosedTransaction -Authority $authority;$label=if([string]$result.Status-ceq'COMPLETE_NO_SAVE'){[string]$result.Cause}else{[string]$result.Status}
        }catch{$failure=$_.Exception;if($failure.InnerException-is[UID0002PAV4Failure]){$failure=$failure.InnerException};$label=[string]$failure.Message}
        $expected=@{
            NullAuthority='CT4-PA sealed authority required';NullTransport='CT4-PA transport adapter required';NullRetirement='CT4-PA retirement adapter required';FixtureBypass='CT4-PA extra positional authority rejected';NestedSchemaDrift='SC4-PA literal recursive schema drift: idb_open';RuntimeSessionDrift='RT4-PA worker process generation mismatch';ModuleDrift='RT4-PA frozen role drift before save';PartialOpenValidationFailure='RT4-PA list sessions native array mismatch';ReturnedSessionDiffersPreferredCleanup='PL4-PA injected pre-save failure';InactiveRowRetirement='P0_VERIFIED_DeterminateSuccess';DuplicateJournal='JL4-PA durable journal collision';DuplicateBackup='BK4-PA backup collision';SetupFailure='OP4-PA injected setup failure';CompleteNoSave='PL4-PA injected pre-save failure';ThrownDopenP0='P0_VERIFIED_Thrown';ThrownDopenChanged='DS4-PA changed output lacks determinate sole-save authority: Thrown';TimeoutDopenP0='P0_VERIFIED_Timeout';TimeoutDopenChanged='DS4-PA changed output lacks determinate sole-save authority: Timeout';DisconnectedDopen='P0_VERIFIED_Disconnected';P0='P0_VERIFIED_DeterminateSuccess';P1='P1_VERIFIED';DeterminateFailureP0='P0_VERIFIED_DeterminateFailure';DeterminateFailureChanged='DS4-PA changed output lacks determinate sole-save authority: DeterminateFailure';IndeterminateChanged='DS4-PA changed output lacks determinate sole-save authority: Indeterminate';FinalMismatchRestore='RESTORED_P0_VERIFIED';RestoreCorruption='RS4-PA held P1/B0 authority mismatch';ThirdIdentity='RS4-PA held P1/B0 authority mismatch'
        }[$case]
        if($label-cne$expected){throw "HF4-PA wrong label case=$case expected=[$expected] actual=[$label]"}
        $saveCount=if($null-ne$result){[int]$result.SaveDispatchCount}elseif($failure-is[UID0002PAV4Failure]){[int]$failure.SaveDispatchCount}elseif($null-ne$state){[int]$state.SaveCalls}else{0};$transportCount=if($null-ne$result){[int]$result.TransportCalls}elseif($failure-is[UID0002PAV4Failure]){[int]$failure.TransportCalls}elseif($null-ne$state){[int]$state.TransportCalls}else{0};$retireCount=if($null-ne$result){[int]$result.RetireCalls}elseif($failure-is[UID0002PAV4Failure]){[int]$failure.RetireCalls}elseif($null-ne$state){[int]$state.RetireCalls}else{0};$restoreCount=if($null-ne$result){[int]$result.RestoreWrites}elseif($failure-is[UID0002PAV4Failure]){[int]$failure.RestoreWrites}else{0};$dopen=if($null-ne$result){[bool]$result.DopenCaptured}elseif($failure-is[UID0002PAV4Failure]){[bool]$failure.DopenCaptured}else{$false}
        $journalRetained=if($null-ne$state){[IO.File]::Exists($state.Canonical+'.uid0002pa-v4.journal')}else{$false};$want=$expectedCounts[$case];$caseEntries=[long]([UID0002PAV4ExecutionMeter]::SnapshotCoordinatorEntries()-$caseEntryStart);$effectMeasurement=Get-UID0002PAV4MeasuredExternalEffects $state
        if($saveCount-ne[int]$want[0]-or$transportCount-ne[int]$want[1]-or$retireCount-ne[int]$want[2]-or$restoreCount-ne[int]$want[3]-or$dopen-ne[bool]$want[4]-or$journalRetained-ne[bool]$want[5]){throw "HF4-PA exact measured counter/effect mismatch case=$case actual=$saveCount/$transportCount/$retireCount/$restoreCount/$dopen/$journalRetained expected=$($want-join'/')"}
        if($caseEntries-ne1){throw "HF4-PA measured coordinator-entry mismatch case=$case actual=$caseEntries"};if([long]$effectMeasurement.ExternalTargetEffects-ne0){throw "HF4-PA measured external effect case=$case count=$($effectMeasurement.ExternalTargetEffects)"};if($null-ne$state-and$state.SaveCalls-gt1){throw "HF4-PA duplicate save observed: $case"};$returnedCleanup=$false;$inactiveAccepted=$false;if($case-ceq'ReturnedSessionDiffersPreferredCleanup'){$retired=@($state.RetiredSessions|Where-Object{$_-like'*-returned'});$returnedCleanup=$retired.Count-eq1;if(-not$returnedCleanup){throw 'HF4-PA exact returned-session cleanup not observed'}};if($case-ceq'InactiveRowRetirement'){$inactiveAccepted=@($state.Roles.Values|Where-Object{$_.Active-eq$false}).Count-ge2;if(-not$inactiveAccepted){throw 'HF4-PA inactive retirement row not accepted'}}
        $rows+=[pscustomobject]@{Case=$case;Label=$label;ProductionCoordinatorInvocations=$caseEntries;SaveDispatchCount=$saveCount;TransportCalls=$transportCount;RetireCalls=$retireCount;RestoreWrites=$restoreCount;DopenCaptured=$dopen;JournalRetained=$journalRetained;ReturnedSessionCleanupExact=$returnedCleanup;InactiveRowAccepted=$inactiveAccepted;ExternalTargetEffects=[long]$effectMeasurement.ExternalTargetEffects;EffectObservations=[long]$effectMeasurement.EffectObservations;CallerCounterRejected=($case-cne'FixtureBypass'-or$label-ceq'CT4-PA extra positional authority rejected');Result=$result}
        }finally{if($null-ne$state){$cleanupReceipt=Remove-UID0002PAReportOwnedFixtureRootVerified $state.Root;if($rows.Count-gt0-and$rows[-1].Case-ceq$case){$rows[-1]|Add-Member CleanupReceipt $cleanupReceipt -Force}}}
    }
    $measuredEntries=[long]([UID0002PAV4ExecutionMeter]::SnapshotCoordinatorEntries()-$suiteEntryStart);$rowEntries=[long](($rows|Measure-Object -Property ProductionCoordinatorInvocations -Sum).Sum);$measuredEffects=[long](($rows|Measure-Object -Property ExternalTargetEffects -Sum).Sum);$effectObservations=[long](($rows|Measure-Object -Property EffectObservations -Sum).Sum)
    if($rows.Count-ne$cases.Count-or$measuredEntries-ne$cases.Count-or$rowEntries-ne$measuredEntries-or@($rows|Where-Object{$_.ProductionCoordinatorInvocations-ne1-or$_.ExternalTargetEffects-ne0-or-not$_.CallerCounterRejected}).Count-ne0){throw 'HF4-PA measured production-entry/effect accounting mismatch'}
    [pscustomobject]@{Passed=[long]$rows.Count;Failed=[long]($cases.Count-$rows.Count);ProductionCoordinatorInvocations=$measuredEntries;ExternalTargetEffects=$measuredEffects;EffectObservations=$effectObservations;Cases=$rows}
}

# Superseded stateful surfaces remain named only so accidental calls fail closed.
function New-UID0002PABackup { throw 'CT4-PA superseded backup surface disabled; use the sealed V4 coordinator' }
function Get-UID0002PAAttemptSeal { throw 'CT4-PA superseded attempt surface disabled; use the sealed V4 coordinator' }
function Set-UID0002PAAttemptSeal { throw 'CT4-PA superseded attempt surface disabled; use the sealed V4 coordinator' }
function New-UID0002PASaveAttempt { throw 'CT4-PA superseded save-attempt surface disabled; use the sealed V4 coordinator' }
function Complete-UID0002PASaveTransport { throw 'CT4-PA superseded classifier surface disabled; use the sealed V4 coordinator' }
function Resolve-UID0002PASaveTransportOutcome { throw 'CT4-PA superseded classifier surface disabled; use the sealed V4 coordinator' }
function New-UID0002PADurableAuthority { throw 'CT4-PA superseded journal surface disabled; use the sealed V4 coordinator' }
function Write-UID0002PADurableAuthority { throw 'CT4-PA superseded journal surface disabled; use the sealed V4 coordinator' }
function Set-UID0002PADurableSaveDispatched { throw 'CT4-PA superseded journal surface disabled; use the sealed V4 coordinator' }
function New-UID0002PAV3HeldBackup { throw 'CT4-PA superseded V3 backup surface disabled; use the sealed V4 coordinator' }
function Start-UID0002PAV3FixtureSave { throw 'CT4-PA superseded V3 save surface disabled; use the sealed V4 coordinator' }
function Invoke-UID0002PAV3FixtureRestore { throw 'CT4-PA superseded V3 restore surface disabled; use the sealed V4 coordinator' }
function Invoke-UID0002PAV3FixtureCase { throw 'CT5-PA superseded V3 fixture surface disabled; use the final V5 private fixture suite' }

# Final V5 authority boundary. V4 remains the shared transaction engine but is no longer a public production contract.
function Initialize-UID0002PAV5CapabilityTypes {
    if ('UID0002PAV5Capability' -as [type]) { return }
    Add-Type -TypeDefinition @'
using System;
using System.Collections.Generic;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Security.Cryptography;
using System.Text;
using System.Threading;

public sealed class UID0002PAV5Capability {
  internal readonly Guid Id;
  internal readonly string Scope;
  internal readonly object Authority;
  internal readonly string Fingerprint;
  internal readonly byte[] Seal;
  internal UID0002PAV5Capability(Guid id,string scope,object authority,string fingerprint,byte[] seal) {
    Id=id;Scope=scope;Authority=authority;Fingerprint=fingerprint;Seal=seal;
  }
}

public sealed class UID0002PAV5Lease {
  public string Scope {get;private set;}
  public object Authority {get;private set;}
  internal UID0002PAV5Lease(string scope,object authority) { Scope=scope;Authority=authority; }
}

public static class UID0002PAV5CapabilityVault {
  sealed class View {
    internal string Canonical,Root,Fingerprint;
    internal object Transport,Retirement;
  }
  sealed class Record {
    internal UID0002PAV5Capability Capability;
    internal string Scope,Canonical,Root,Fingerprint;
    internal object Authority,Transport,Retirement;
    internal byte[] Seal;
  }
  static readonly object Sync=new object();
  static readonly Dictionary<Guid,Record> Active=new Dictionary<Guid,Record>();
  static readonly byte[] Key=CreateKey();
  static int productionBootstrap,productionTestBootstrap,fixtureBootstrap;
  const string ProductionCanonical=@"E:\NTK\Resources\NexusTK\NexusTK.exe.i64";
  const string ProductionRoot=@"C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp";

  static byte[] CreateKey(){byte[] b=new byte[32];using(RandomNumberGenerator r=RandomNumberGenerator.Create()){r.GetBytes(b);}return b;}
  static Type V4Type(){
    foreach(Assembly a in AppDomain.CurrentDomain.GetAssemblies()){
      Type t=a.GetType("UID0002PAV4Authority",false,false);if(t!=null)return t;
    }
    throw new InvalidOperationException("CP5-PA V4 engine authority type unavailable");
  }
  static object Field(object value,string name){
    if(value==null)return null;
    FieldInfo f=value.GetType().GetField(name,BindingFlags.Instance|BindingFlags.NonPublic);
    if(f==null)throw new InvalidOperationException("CP5-PA authority field unavailable: "+name);
    return f.GetValue(value);
  }
  static string Property(object value,string name){
    if(value==null)return null;
    PropertyInfo p=value.GetType().GetProperty(name,BindingFlags.Instance|BindingFlags.Public);
    if(p==null)throw new InvalidOperationException("CP5-PA authority property unavailable: "+name);
    return Convert.ToString(p.GetValue(value,null));
  }
  static string Ref(object value){return value==null?"null":RuntimeHelpers.GetHashCode(value).ToString("X8");}
  static View Inspect(object authority){
    if(authority==null)return new View{Canonical=null,Root=null,Transport=null,Retirement=null,Fingerprint="NULL"};
    if(authority.GetType()!=V4Type())throw new InvalidOperationException("CP5-PA wrong authority type");
    string canonical=Path.GetFullPath(Property(authority,"CanonicalPath"));
    string root=Path.GetFullPath(Property(authority,"SourceRoot"));
    object transport=Field(authority,"transport"),retirement=Field(authority,"retirement");
    string fingerprint=canonical.ToUpperInvariant()+"|"+root.ToUpperInvariant()+"|"+Ref(authority)+"|"+Ref(transport)+"|"+Ref(retirement);
    return new View{Canonical=canonical,Root=root,Transport=transport,Retirement=retirement,Fingerprint=fingerprint};
  }
  static byte[] Sign(Guid id,string scope,string fingerprint){
    byte[] data=Encoding.UTF8.GetBytes(id.ToString("N")+"|"+scope+"|"+fingerprint);
    using(HMACSHA256 h=new HMACSHA256(Key)){return h.ComputeHash(data);}
  }
  static bool Same(byte[] a,byte[] b){
    if(a==null||b==null||a.Length!=b.Length)return false;int d=0;for(int i=0;i<a.Length;i++)d|=a[i]^b[i];return d==0;
  }
  static UID0002PAV5Capability Issue(string scope,object authority){
    View v=Inspect(authority);
    if(scope=="Production"){
      if(!String.Equals(v.Canonical,Path.GetFullPath(ProductionCanonical),StringComparison.OrdinalIgnoreCase)||
         !String.Equals(v.Root,Path.GetFullPath(ProductionRoot),StringComparison.OrdinalIgnoreCase)||v.Transport==null||v.Retirement==null)
        throw new InvalidOperationException("CP5-PA production authority binding mismatch");
    } else if(scope=="ProductionTest"){
      string temp=Path.GetFullPath(Path.GetTempPath()).TrimEnd(Path.DirectorySeparatorChar,Path.AltDirectorySeparatorChar),parent=Path.GetDirectoryName(v.Canonical),expectedRoot=Path.Combine(parent,"source");
      if(!v.Canonical.StartsWith(temp+Path.DirectorySeparatorChar,StringComparison.OrdinalIgnoreCase)||
         !String.Equals(Path.GetFileName(v.Canonical),"fixture.i64",StringComparison.Ordinal)||
         !String.Equals(v.Root,Path.GetFullPath(expectedRoot),StringComparison.OrdinalIgnoreCase)||v.Transport==null||v.Retirement==null)
        throw new InvalidOperationException("CP5-PA production-test raw boundary mismatch");
    }
    Guid id=Guid.NewGuid();byte[] seal=Sign(id,scope,v.Fingerprint);
    UID0002PAV5Capability cap=new UID0002PAV5Capability(id,scope,authority,v.Fingerprint,seal);
    lock(Sync){Active.Add(id,new Record{Capability=cap,Scope=scope,Authority=authority,Canonical=v.Canonical,Root=v.Root,Transport=v.Transport,Retirement=v.Retirement,Fingerprint=v.Fingerprint,Seal=seal});}
    return cap;
  }
  public static Func<UID0002PAV5Capability> BootstrapProduction(string canonical,string root,object transport,object retirement){
    canonical=Path.GetFullPath(canonical);root=Path.GetFullPath(root);
    if(!String.Equals(canonical,Path.GetFullPath(ProductionCanonical),StringComparison.OrdinalIgnoreCase)||
       !String.Equals(root,Path.GetFullPath(ProductionRoot),StringComparison.OrdinalIgnoreCase)||transport==null||retirement==null)
      throw new InvalidOperationException("CP5-PA production bootstrap binding mismatch");
    if(Interlocked.CompareExchange(ref productionBootstrap,1,0)!=0)throw new InvalidOperationException("CP5-PA production bootstrap already sealed");
    return delegate {
      object authority=Activator.CreateInstance(V4Type(),BindingFlags.Instance|BindingFlags.Public,null,new object[]{canonical,root,transport,retirement},null);
      return Issue("Production",authority);
    };
  }
  public static Func<object,UID0002PAV5Capability> BootstrapFixture(){
    if(Interlocked.CompareExchange(ref fixtureBootstrap,1,0)!=0)throw new InvalidOperationException("CP5-PA fixture bootstrap already sealed");
    return delegate(object authority){return Issue("Fixture",authority);};
  }
  public static Func<object,UID0002PAV5Capability> BootstrapProductionTest(){
    if(Interlocked.CompareExchange(ref productionTestBootstrap,1,0)!=0)throw new InvalidOperationException("CP5-PA production-test bootstrap already sealed");
    return delegate(object authority){return Issue("ProductionTest",authority);};
  }
  public static UID0002PAV5Lease Consume(UID0002PAV5Capability capability,string expectedScope){
    if(capability==null)throw new InvalidOperationException("CP5-PA capability required");
    Record r;
    lock(Sync){
      if(!Active.TryGetValue(capability.Id,out r))throw new InvalidOperationException("CP5-PA capability absent or replayed");
      if(!Object.ReferenceEquals(r.Capability,capability))throw new InvalidOperationException("CP5-PA copied capability rejected");
      if(!String.Equals(r.Scope,expectedScope,StringComparison.Ordinal)){Active.Remove(capability.Id);throw new InvalidOperationException("CP5-PA cross-scope capability rejected");}
      View v=Inspect(capability.Authority);
      if(!Object.ReferenceEquals(r.Authority,capability.Authority)||!Object.ReferenceEquals(r.Transport,v.Transport)||
         !Object.ReferenceEquals(r.Retirement,v.Retirement)||!String.Equals(r.Canonical,v.Canonical,StringComparison.OrdinalIgnoreCase)||
         !String.Equals(r.Root,v.Root,StringComparison.OrdinalIgnoreCase)||!String.Equals(r.Fingerprint,v.Fingerprint,StringComparison.Ordinal)||
         !String.Equals(capability.Fingerprint,v.Fingerprint,StringComparison.Ordinal)||!Same(r.Seal,capability.Seal)||!Same(capability.Seal,Sign(capability.Id,capability.Scope,capability.Fingerprint))){
        Active.Remove(capability.Id);throw new InvalidOperationException("CP5-PA substituted capability rejected");
      }
      Active.Remove(capability.Id);
    }
    return new UID0002PAV5Lease(r.Scope,r.Authority);
  }
}

public static class UID0002PAV5BoundaryMeter {
  static long productionEntries;
  public static long EnterProduction(){return Interlocked.Increment(ref productionEntries);}
  public static long SnapshotProductionEntries(){return Interlocked.Read(ref productionEntries);}
}
'@
}

Initialize-UID0002PAV4SealedTypes
Initialize-UID0002PAV5CapabilityTypes
$uid0002paV5LegacyCoordinator=(Get-Command Invoke-UID0002PAClosedTransaction -CommandType Function).ScriptBlock
$uid0002paV5LegacyFixtureSuite=(Get-Command Invoke-UID0002PAHostileStaticFixtures -CommandType Function).ScriptBlock
$uid0002paV4ProductionControl={param([UID0002PAV4Authority]$Authority)&$uid0002paV5LegacyCoordinator -Authority $Authority}.GetNewClosure()
Set-Item -LiteralPath Function:\Invoke-UID0002PAV4ProductionControl -Value $uid0002paV4ProductionControl -Force

$uid0002paV5PackageFactory={
    $canonical=[IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64')
    $sourceRoot=[IO.Path]::GetFullPath('C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp')
    $endpoint=[Uri]'http://127.0.0.1:13337/mcp'
    $hashScriptText={param([string]$text)$bytes=[Text.Encoding]::UTF8.GetBytes($text);$sha=[Security.Cryptography.SHA256]::Create();try{([BitConverter]::ToString($sha.ComputeHash($bytes))).Replace('-','')}finally{$sha.Dispose()}}.GetNewClosure()
    $newOperationGate={
        $runs=@(
            [pscustomobject]@{Name='tools/list';Count=1L},[pscustomobject]@{Name='idb_open';Count=1L},[pscustomobject]@{Name='idb_list';Count=1L},[pscustomobject]@{Name='runtime_attestation';Count=1L},[pscustomobject]@{Name='entity_query';Count=51L},
            [pscustomobject]@{Name='declare_type';Count=1L},[pscustomobject]@{Name='entity_query';Count=52L},[pscustomobject]@{Name='rename';Count=1L},[pscustomobject]@{Name='entity_query';Count=51L},[pscustomobject]@{Name='set_type';Count=1L},
            [pscustomobject]@{Name='entity_query';Count=51L},[pscustomobject]@{Name='set_function_comments';Count=1L},[pscustomobject]@{Name='entity_query';Count=51L},[pscustomobject]@{Name='set_address_comments';Count=1L},[pscustomobject]@{Name='entity_query';Count=102L},
            [pscustomobject]@{Name='idb_list';Count=1L},[pscustomobject]@{Name='runtime_attestation';Count=1L},[pscustomobject]@{Name='idb_save';Count=1L},[pscustomobject]@{Name='idb_list';Count=1L},[pscustomobject]@{Name='runtime_attestation';Count=1L},
            [pscustomobject]@{Name='idb_open';Count=1L},[pscustomobject]@{Name='idb_list';Count=1L},[pscustomobject]@{Name='runtime_attestation';Count=1L},[pscustomobject]@{Name='entity_query';Count=51L},[pscustomobject]@{Name='idb_list';Count=1L},[pscustomobject]@{Name='runtime_attestation';Count=1L}
        )
        $plan=New-Object 'Collections.Generic.List[string]';foreach($run in $runs){for([long]$n=0;$n-lt[long]$run.Count;$n++){$plan.Add([string]$run.Name)}}
        $planText=[string]::Join("`n",$plan)+"`n";$planSha=&$hashScriptText $planText
        if($plan.Count-ne428-or$planSha-cne'205D6CA312A6F4715B9E26611EAC8BB28BCC4B3F121E118449BC12D2A2F8F68A'){throw 'OP5-PA production operation plan identity mismatch'}
        $gateState=[pscustomobject]@{Index=0L;Counts=[ordered]@{'tools/list'=0L;idb_open=0L;idb_list=0L;runtime_attestation=0L;entity_query=0L;declare_type=0L;rename=0L;set_type=0L;set_function_comments=0L;set_address_comments=0L;idb_save=0L}}
        $check={
            param([string]$Payload)
            $request=ConvertFrom-UID0002PAV4StrictJson $Payload 'OP5-PA pre-dispatch request';Assert-UID0002PAV4ExactKeys $request @('jsonrpc','id','method','params') 'OP5-PA pre-dispatch request'
            if([string]$request.jsonrpc-cne'2.0'-or[string]::IsNullOrWhiteSpace([string]$request.id)){throw 'OP5-PA pre-dispatch request identity mismatch'}
            $params=$request.params;if([string]$request.method-ceq'tools/list'){Assert-UID0002PAV4ExactKeys $params @() 'OP5-PA tools/list params';$name='tools/list'}elseif([string]$request.method-ceq'tools/call'){Assert-UID0002PAV4ExactKeys $params @('name','arguments') 'OP5-PA tools/call params';if($null-eq$params.arguments){throw 'OP5-PA tools/call arguments missing'};$name=[string]$params.name}else{throw 'OP5-PA forbidden JSON-RPC method before dispatch'}
            if($gateState.Index-ge$plan.Count-or$name-cne[string]$plan[[int]$gateState.Index]){throw "OP5-PA forbidden/extra/out-of-order operation before dispatch: index=$($gateState.Index) actual=$name"}
            $gateState.Counts[$name]=[long]$gateState.Counts[$name]+1L;$gateState.Index=[long]$gateState.Index+1L
        }.GetNewClosure()
        $complete={
            param([ValidateSet('Live','Fixture')][string]$Route)
            if($gateState.Index-ne$plan.Count){throw "OP5-PA missed production operations: observed=$($gateState.Index) expected=$($plan.Count)"}
            [pscustomobject][ordered]@{PlanSHA256=$planSha;ExpectedTotal=428L;ObservedTotal=[long]$gateState.Index;ExpectedLiveMcpCalls=428L;ExpectedLiveIdaWriteCalls=6L;ObservedFixtureTransportCalls=if($Route-ceq'Fixture'){[long]$gateState.Index}else{0L};ObservedFixtureIdaWriteCalls=if($Route-ceq'Fixture'){6L}else{0L};ForbiddenCalls=0L;ExtraCalls=0L;MissedCalls=0L;ExternalMcpDispatches=if($Route-ceq'Live'){428L}else{0L};ExternalIdaDispatches=if($Route-ceq'Live'){6L}else{0L};PreDispatchEnforced=$true;PermittedCounts=[pscustomobject]$gateState.Counts}
        }.GetNewClosure()
        [pscustomobject]@{Check=$check;Complete=$complete}
    }.GetNewClosure()
    $productionOperationGate=&$newOperationGate
    $helperManifest=[ordered]@{};foreach($command in @(Microsoft.PowerShell.Core\Get-Command -Name '*UID0002PA*' -CommandType Function|Where-Object{$_.Name-notin@('Invoke-UID0002PAClosedTransaction','Invoke-UID0002PAHostileStaticFixtures')}|Sort-Object Name)){$helperManifest[$command.Name]=&$hashScriptText ([string]$command.ScriptBlock)}
    $transport={
        param([string]$payload)
        if([string]::IsNullOrWhiteSpace($payload)-or[Text.Encoding]::UTF8.GetByteCount($payload)-gt16777216){throw 'TP5-PA bounded request rejected'}
        $preDispatch=[scriptblock]$productionOperationGate.Check;&$preDispatch $payload
        $bytes=[Text.Encoding]::UTF8.GetBytes($payload);$request=[Net.HttpWebRequest]::Create($endpoint);$request.Method='POST';$request.ContentType='application/json';$request.Accept='application/json, text/event-stream';$request.AllowAutoRedirect=$false;$request.Proxy=$null;$request.Timeout=120000;$request.ReadWriteTimeout=120000;$request.ContentLength=$bytes.Length
        $stream=$request.GetRequestStream();try{$stream.Write($bytes,0,$bytes.Length);$stream.Flush()}finally{$stream.Dispose()}
        $response=$request.GetResponse();try{$reader=[IO.StreamReader]::new($response.GetResponseStream(),[Text.Encoding]::UTF8,$true,4096,$false);try{$text=$reader.ReadToEnd()}finally{$reader.Dispose()}}finally{$response.Dispose()}
        if([Text.Encoding]::UTF8.GetByteCount($text)-gt33554432){throw 'TP5-PA bounded response rejected'}
        if($text.TrimStart().StartsWith('{')){return $text}
        $data=@($text -split "`r?`n"|Where-Object{$_-like'data:*'}|ForEach-Object{$_.Substring(5).Trim()}|Where-Object{$_-and$_-ne'[DONE]'})
        if($data.Count-ne1-or-not$data[0].StartsWith('{')){throw 'TP5-PA non-JSON MCP response'};$data[0]
    }.GetNewClosure()
    $retire={
        param([string]$raw)
        $action=ConvertFrom-UID0002PAV4StrictJson $raw 'RT5-PA retirement action';Assert-UID0002PAV4ExactKeys $action @('action','role','session_id','canonical_path','redirector_pid','redirector_generation','worker_pid','worker_generation','route_port','endpoint','socket_owner_pid','nonce','stable_manifest_sha256','process_manifest_sha256','preserve_listener') 'RT5-PA retirement action'
        if([string]$action.action-cne'RETIRE_EXACT_GENERATION'-or[IO.Path]::GetFullPath([string]$action.canonical_path)-ine$canonical-or$action.preserve_listener-isnot[bool]-or-not$action.preserve_listener){throw 'RT5-PA bounded retirement authority mismatch'}
        $killExact={param([int]$pid,[string]$generation,[string]$label)$p=[Diagnostics.Process]::GetProcessById($pid);try{$actual="pid:$pid;started:$($p.StartTime.ToUniversalTime().Ticks)";if($actual-cne$generation){throw "$label generation mismatch"};$p.Kill();if(-not$p.WaitForExit(30000)){throw "$label exit timeout"}}finally{$p.Dispose()}}.GetNewClosure()
        &$killExact ([int]$action.worker_pid) ([string]$action.worker_generation) 'RT5-PA worker';if([int]$action.redirector_pid-ne[int]$action.worker_pid){&$killExact ([int]$action.redirector_pid) ([string]$action.redirector_generation) 'RT5-PA redirector'}
        if(-not(Test-UID0002PAV4ProcessGenerationAbsentOrReused ([int]$action.worker_pid) ([string]$action.worker_generation))-or-not(Test-UID0002PAV4ProcessGenerationAbsentOrReused ([int]$action.redirector_pid) ([string]$action.redirector_generation))-or-not(Test-UID0002PAV4SocketAbsent ([int]$action.route_port))){throw 'RT5-PA exact generation/socket remains live'}
        [ordered]@{action=[string]$action.action;role=[string]$action.role;session_id=[string]$action.session_id;canonical_path=[string]$action.canonical_path;redirector_pid=[int]$action.redirector_pid;redirector_generation=[string]$action.redirector_generation;worker_pid=[int]$action.worker_pid;worker_generation=[string]$action.worker_generation;route_port=[int]$action.route_port;endpoint=[string]$action.endpoint;socket_owner_pid=[int]$action.socket_owner_pid;nonce=[string]$action.nonce;stable_manifest_sha256=[string]$action.stable_manifest_sha256;process_manifest_sha256=[string]$action.process_manifest_sha256;retired=$true;listener_preserved=$true}|ConvertTo-Json -Compress
    }.GetNewClosure()
    $productionIssuer=[UID0002PAV5CapabilityVault]::BootstrapProduction($canonical,$sourceRoot,$transport,$retire)
    $productionTestIssuer=[UID0002PAV5CapabilityVault]::BootstrapProductionTest()
    $fixtureIssuer=[UID0002PAV5CapabilityVault]::BootstrapFixture()
    $legacyCoordinator=$uid0002paV5LegacyCoordinator
    $legacyFixtureSuite=$uid0002paV5LegacyFixtureSuite
    $sharedCoordinator={
        param([UID0002PAV5Capability]$Capability,[ValidateSet('Production','ProductionTest','Fixture')][string]$Scope,[object[]]$ForwardArguments=@())
        $lease=[UID0002PAV5CapabilityVault]::Consume($Capability,$Scope)
        if($Scope-ceq'Production'-or$Scope-ceq'ProductionTest'){$null=[UID0002PAV5BoundaryMeter]::EnterProduction()}
        &$legacyCoordinator -Authority ([UID0002PAV4Authority]$lease.Authority) @ForwardArguments
    }.GetNewClosure()
    $publicEntry={
        if($args.Count-ne0){throw 'CT5-PA public entry accepts no authority or adapter arguments'}
        foreach($name in $helperManifest.Keys){$current=@(Microsoft.PowerShell.Core\Get-Command -Name $name -CommandType Function -ErrorAction SilentlyContinue);if($current.Count-ne1-or(&$hashScriptText ([string]$current[0].ScriptBlock))-cne[string]$helperManifest[$name]){throw "CP5-PA module/scope function drift: $name"}}
        $capability=$productionIssuer.Invoke();$raw=&$sharedCoordinator $capability 'Production' @();if([string]$raw.Kind-ceq'Production'){$complete=[scriptblock]$productionOperationGate.Complete;$operation=&$complete 'Live';$raw|Add-Member ProductionOperationPlan $operation -Force};$raw
    }.GetNewClosure()
    $productionTestEntry={
        [CmdletBinding()]param([Parameter(Mandatory=$true)][string]$ExactRoot)
        if($args.Count-ne0){throw 'CT5-PA production-test entry accepts only its sealed raw root'}
        $state=New-UID0002PAV4FixtureEnvironment -Case 'P1' -ExactRoot $ExactRoot;$adapters=New-UID0002PAV4FixtureAdapters $state;$operationGate=&$newOperationGate;$rawTransport=[scriptblock]$adapters.Transport
        $boundedTransport={param([string]$Payload)$preDispatch=[scriptblock]$operationGate.Check;&$preDispatch $Payload;&$rawTransport $Payload}.GetNewClosure()
        $authority=New-UID0002PAV4Authority -CanonicalPath $state.Canonical -SourceRoot $state.SourceRoot -Transport $boundedTransport -RetireExactGeneration $adapters.Retire
        $capability=$productionTestIssuer.Invoke([object]$authority);$raw=&$sharedCoordinator $capability 'ProductionTest' @();$complete=[scriptblock]$operationGate.Complete;$operation=&$complete 'Fixture';$raw|Add-Member ProductionOperationPlan $operation -Force
        [pscustomobject]@{Raw=$raw;State=$state;Measured=(Get-UID0002PAV4MeasuredExternalEffects $state)}
    }.GetNewClosure()
    $fixtureBridge={
        param([UID0002PAV4Authority]$Authority)
        $capability=$fixtureIssuer.Invoke([object]$Authority);&$sharedCoordinator $capability 'Fixture' @($args)
    }.GetNewClosure()
    $privateFixtureEntry={
        $savedPublic=(Get-Command Invoke-UID0002PAClosedTransaction -CommandType Function).ScriptBlock
        Set-Item -LiteralPath Function:\global:Invoke-UID0002PAClosedTransaction -Value $fixtureBridge -Force
        try{&$legacyFixtureSuite}finally{Set-Item -LiteralPath Function:\global:Invoke-UID0002PAClosedTransaction -Value $savedPublic -Force}
    }.GetNewClosure()
    $boundarySuite={
        $boundaryPublicEntry=$publicEntry;$boundarySharedCoordinator=$sharedCoordinator;$boundaryFixtureIssuer=$fixtureIssuer;$boundaryCanonical=$canonical;$boundarySourceRoot=$sourceRoot
        $rows=@();$roots=New-Object 'Collections.Generic.List[string]'
        $run={
            param([string]$case,[string]$expected,[scriptblock]$action,$state,[int]$expectedShared=0)
            $productionStart=[UID0002PAV5BoundaryMeter]::SnapshotProductionEntries();$sharedStart=[UID0002PAV4ExecutionMeter]::SnapshotCoordinatorEntries();$saveStart=if($null-ne$state){[int]$state.SaveCalls}else{0}
            $label=$null;try{&$action;throw "HF5-PA $case unexpectedly accepted"}catch{$failure=$_.Exception;while($null-ne$failure.InnerException){$failure=$failure.InnerException};$label=[string]$failure.Message}
            $productionDelta=[long]([UID0002PAV5BoundaryMeter]::SnapshotProductionEntries()-$productionStart);$sharedDelta=[long]([UID0002PAV4ExecutionMeter]::SnapshotCoordinatorEntries()-$sharedStart);$saveDelta=if($null-ne$state){[int]$state.SaveCalls-$saveStart}else{0};$effects=Get-UID0002PAV4MeasuredExternalEffects $state
            if($label-cne$expected-or$productionDelta-ne0-or$sharedDelta-ne$expectedShared-or$saveDelta-ne0-or[long]$effects.ExternalTargetEffects-ne0){throw "HF5-PA boundary mismatch case=$case label=[$label] production=$productionDelta shared=$sharedDelta save=$saveDelta external=$($effects.ExternalTargetEffects)"}
            [pscustomobject]@{Case=$case;Label=$label;ProductionEntries=$productionDelta;SharedCoordinatorEntries=$sharedDelta;SaveDispatchCount=$saveDelta;ExternalTargetEffects=[long]$effects.ExternalTargetEffects}
        }.GetNewClosure()
        try{
            $state1=New-UID0002PAV4FixtureEnvironment 'V5DirectLegacy';$roots.Add($state1.Root);$ad1=New-UID0002PAV4FixtureAdapters $state1;$legacy1=[UID0002PAV4Authority]::new($state1.Canonical,$state1.SourceRoot,$ad1.Transport,$ad1.Retire)
            $rows+=&$run 'DirectLegacyAuthority' 'CT5-PA public entry accepts no authority or adapter arguments' ({&$boundaryPublicEntry $legacy1}.GetNewClosure()) $state1
            $rows+=&$run 'PublicCapabilityConstructor' 'CP5-PA public capability constructor unavailable' ({if(@([UID0002PAV5Capability].GetConstructors()).Count-ne0){throw 'HF5-PA public capability constructor exposed'};$made=$null;try{$made=[Activator]::CreateInstance([UID0002PAV5Capability])}catch{};if($null-ne$made){throw 'HF5-PA public capability constructed'};throw 'CP5-PA public capability constructor unavailable'}.GetNewClosure()) $null
            $ctor=@([UID0002PAV5Capability].GetConstructors([Reflection.BindingFlags]'Instance,NonPublic'))[0];$forged=$ctor.Invoke([object[]]@([Guid]::NewGuid(),'Production',$legacy1,'forged',([byte[]]@(1,2,3))))
            $rows+=&$run 'ReflectionCapability' 'CP5-PA capability absent or replayed' ({&$boundarySharedCoordinator $forged 'Production' @()}.GetNewClosure()) $state1
            $rows+=&$run 'ValidFixtureAdapters' 'CT5-PA public entry accepts no authority or adapter arguments' ({&$boundaryPublicEntry $ad1.Transport $ad1.Retire}.GetNewClosure()) $state1
            $state2=New-UID0002PAV4FixtureEnvironment 'V5ArbitraryPaths';$roots.Add($state2.Root);$ad2=New-UID0002PAV4FixtureAdapters $state2;$legacy2=[UID0002PAV4Authority]::new($state2.Canonical,$state2.SourceRoot,$ad2.Transport,$ad2.Retire)
            $rows+=&$run 'ArbitraryCanonicalAndRoot' 'CT5-PA public entry accepts no authority or adapter arguments' ({&$boundaryPublicEntry $legacy2 $state2.Canonical $state2.SourceRoot}.GetNewClosure()) $state2
            $copyCap=$boundaryFixtureIssuer.Invoke([object]$legacy2);$memberwise=[object].GetMethod('MemberwiseClone',[Reflection.BindingFlags]'Instance,NonPublic');$copied=[UID0002PAV5Capability]$memberwise.Invoke($copyCap,$null)
            $rows+=&$run 'CopiedCapability' 'CP5-PA copied capability rejected' ({&$boundarySharedCoordinator $copied 'Fixture' @()}.GetNewClosure()) $state2
            $replayCap=$boundaryFixtureIssuer.Invoke($null);try{&$boundarySharedCoordinator $replayCap 'Fixture' @()}catch{$leaf=$_.Exception;while($null-ne$leaf.InnerException){$leaf=$leaf.InnerException};if([string]$leaf.Message-cne'CT4-PA sealed authority required'){throw}}
            $rows+=&$run 'ReplayedCapability' 'CP5-PA capability absent or replayed' ({&$boundarySharedCoordinator $replayCap 'Fixture' @()}.GetNewClosure()) $null
            $state3=New-UID0002PAV4FixtureEnvironment 'V5Substitution';$roots.Add($state3.Root);$ad3=New-UID0002PAV4FixtureAdapters $state3;$legacy3=[UID0002PAV4Authority]::new($state3.Canonical,$state3.SourceRoot,$ad3.Transport,$ad3.Retire);$subCap=$boundaryFixtureIssuer.Invoke([object]$legacy3);$transportField=[UID0002PAV4Authority].GetField('transport',[Reflection.BindingFlags]'Instance,NonPublic');$transportField.SetValue($legacy3,{throw 'substituted transport'}.GetNewClosure())
            $rows+=&$run 'AdapterSubstitution' 'CP5-PA substituted capability rejected' ({&$boundarySharedCoordinator $subCap 'Fixture' @()}.GetNewClosure()) $state3
            $crossCap=$boundaryFixtureIssuer.Invoke([object]$legacy3)
            $rows+=&$run 'CrossCallScope' 'CP5-PA cross-scope capability rejected' ({&$boundarySharedCoordinator $crossCap 'Production' @()}.GetNewClosure()) $state3
            $savedHelper=(Microsoft.PowerShell.Core\Get-Command Get-UID0002PAV4TextSHA256 -CommandType Function).ScriptBlock;try{Set-Item -LiteralPath Function:\global:Get-UID0002PAV4TextSHA256 -Value {param([string]$Text)'CALLER-SUBSTITUTION'} -Force;$rows+=&$run 'ModuleScopeMutation' 'CP5-PA module/scope function drift: Get-UID0002PAV4TextSHA256' ({&$boundaryPublicEntry}.GetNewClosure()) $state3}finally{Set-Item -LiteralPath Function:\global:Get-UID0002PAV4TextSHA256 -Value $savedHelper -Force}
            $rows+=&$run 'ProductionBootstrapReplay' 'CP5-PA production bootstrap already sealed' ({[UID0002PAV5CapabilityVault]::BootstrapProduction($boundaryCanonical,$boundarySourceRoot,$ad3.Transport,$ad3.Retire)}.GetNewClosure()) $state3
            if($rows.Count-ne11-or@($rows|Where-Object{$_.ProductionEntries-ne0-or$_.SaveDispatchCount-ne0-or$_.ExternalTargetEffects-ne0}).Count-ne0){throw 'HF5-PA boundary aggregate mismatch'}
            [pscustomobject]@{Passed=[long]$rows.Count;Failed=[long](11-$rows.Count);ProductionEntries=[long](($rows|Measure-Object ProductionEntries -Sum).Sum);SaveDispatchCount=[long](($rows|Measure-Object SaveDispatchCount -Sum).Sum);ExternalTargetEffects=[long](($rows|Measure-Object ExternalTargetEffects -Sum).Sum);Cases=$rows}
        }finally{foreach($root in $roots){$null=Remove-UID0002PAReportOwnedFixtureRootVerified $root}}
    }.GetNewClosure()
    $finalSuite={
        if($args.Count-ne0){throw 'HF5-PA fixture suite accepts no caller authority'}
        $boundary=&$boundarySuite;$private=&$privateFixtureEntry
        $private|Add-Member BoundaryPassed ([long]$boundary.Passed) -Force;$private|Add-Member BoundaryFailed ([long]$boundary.Failed) -Force;$private|Add-Member BoundaryProductionEntries ([long]$boundary.ProductionEntries) -Force;$private|Add-Member BoundarySaveDispatchCount ([long]$boundary.SaveDispatchCount) -Force;$private|Add-Member BoundaryExternalTargetEffects ([long]$boundary.ExternalTargetEffects) -Force;$private|Add-Member BoundaryCases $boundary.Cases -Force;$private
    }.GetNewClosure()
    [pscustomobject]@{PublicEntry=$publicEntry;ProductionTestEntry=$productionTestEntry;FixtureSuite=$finalSuite}
}.GetNewClosure()
$uid0002paV5Package=&$uid0002paV5PackageFactory
Set-Item -LiteralPath Function:\Invoke-UID0002PAClosedTransaction -Value $uid0002paV5Package.PublicEntry -Force
Set-Item -LiteralPath Function:\Invoke-UID0002PAV5ProductionTest -Value $uid0002paV5Package.ProductionTestEntry -Force
Set-Item -LiteralPath Function:\Invoke-UID0002PAHostileStaticFixtures -Value $uid0002paV5Package.FixtureSuite -Force
Remove-Variable uid0002paV5PackageFactory,uid0002paV5Package,uid0002paV5LegacyCoordinator,uid0002paV5LegacyFixtureSuite,uid0002paV4ProductionControl -ErrorAction SilentlyContinue
~~~

## Removed Block R030

- SHA256: `DD3E96F4D35995E395BE622A4548FA1717DE0EDC708B81CF8DBBDE39D712703F`
- Language: `powershell`
- Bytes: `24530`
- First recovered timestamp: `2026-08-09T15:30:56.412Z`
- Session provenance: rollout-2026-08-08T17-46-23-019fe357-64cc-7ca3-ad27-c9c336afc6af.jsonl line 5673 (2026-08-09T15:30:56.412Z); rollout-2026-08-08T17-46-23-019fe357-64cc-7ca3-ad27-c9c336afc6af.jsonl line 5674 (2026-08-09T15:30:56.800Z)

~~~powershell
$UID0002PASourceRoot = [System.IO.Path]::GetFullPath('C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp')
$UID0002PAListenerNames = @('ida_pro_mcp','ida_pro_mcp.idalib_supervisor','ida_pro_mcp.runtime_attestation','zeromcp','zeromcp.jsonrpc','zeromcp.mcp')
$UID0002PAWorkerNames = @('__main__','ida_pro_mcp','ida_pro_mcp.ida_mcp','ida_pro_mcp.ida_mcp._sigmaker','ida_pro_mcp.ida_mcp.api_analysis','ida_pro_mcp.ida_mcp.api_composite','ida_pro_mcp.ida_mcp.api_core','ida_pro_mcp.ida_mcp.api_debug','ida_pro_mcp.ida_mcp.api_memory','ida_pro_mcp.ida_mcp.api_modify','ida_pro_mcp.ida_mcp.api_python','ida_pro_mcp.ida_mcp.api_resources','ida_pro_mcp.ida_mcp.api_sigmaker','ida_pro_mcp.ida_mcp.api_stack','ida_pro_mcp.ida_mcp.api_survey','ida_pro_mcp.ida_mcp.api_types','ida_pro_mcp.ida_mcp.compat','ida_pro_mcp.ida_mcp.discovery','ida_pro_mcp.ida_mcp.http','ida_pro_mcp.ida_mcp.profile','ida_pro_mcp.ida_mcp.rpc','ida_pro_mcp.ida_mcp.sync','ida_pro_mcp.ida_mcp.trace','ida_pro_mcp.ida_mcp.utils','ida_pro_mcp.ida_mcp.zeromcp','ida_pro_mcp.ida_mcp.zeromcp.jsonrpc','ida_pro_mcp.ida_mcp.zeromcp.mcp','ida_pro_mcp.idalib_session_manager','ida_pro_mcp.runtime_attestation','ida_pro_mcp.worker_lifecycle')

function New-UID0002PAAttestationState {
    [pscustomobject]@{
        TransactionId = [Guid]::NewGuid().ToString('N')
        UsedNonces = [System.Collections.Generic.HashSet[string]]::new([System.StringComparer]::Ordinal)
        ListenerGeneration = $null
        ListenerManifest = $null
        WorkerManifest = $null
        ModuleIdsByGeneration = @{}
        RoleWorkers = @{}
        TransactionDatabase = $null
        TransactionGeneration = $null
        SaveAttemptCreated = $false
        SaveAttemptId = $null
        SaveRequestSHA256 = $null
        SaveDispatchCount = 0
        NoSaveStatus = 'PRE_SAVE'
        NoSaveP0 = $null
        NoSaveB0 = $null
        NoSaveFailure = $null
    }
}

function Assert-UID0002PAModuleManifest {
    param(
        [Parameter(Mandatory=$true)]$Owner,
        [Parameter(Mandatory=$true)][ValidateSet('listener','worker')][string]$Role,
        [Parameter(Mandatory=$true)][string]$Label)

    $root = [System.IO.Path]::GetFullPath([string]$Owner.source_root).TrimEnd('\')
    if ($root -ine $UID0002PASourceRoot) { throw "$Label public source_root drift" }
    $expectedNames = if ($Role -ceq 'listener') { $UID0002PAListenerNames } else { $UID0002PAWorkerNames }
    $expectedManifest = if ($Role -ceq 'listener') {
        'D3C792133956B855EBA751FDB5783B2D7177FA204134CFF1D897E0D0770FB7CE'
    } else {
        '849203D42ABFC99176069E7069F039E9B50AC1A0F392BECB4D7C90CC7AE627D4'
    }
    if ([string]$Owner.implementation_manifest_sha256 -cne $expectedManifest) {
        throw "$Label public implementation-manifest SHA drift"
    }
    $rows = @($Owner.modules)
    if ($rows.Count -ne $expectedNames.Count -or (($rows.sys_modules_name -join '|') -cne ($expectedNames -join '|'))) {
        throw "$Label complete ordered module-name manifest mismatch"
    }

    $seenIds = @{}
    $seenFiles = @{}
    $normalized = @()
    $rootPrefix = $root + '\'
    foreach ($row in $rows) {
        foreach ($property in 'sys_modules_name','module_id','file','spec_origin','resolved_path','size','mtime_ns','ctime_ns','sha256') {
            if (-not $row.PSObject.Properties[$property]) { throw "$Label module field missing: $property" }
        }
        $file = [System.IO.Path]::GetFullPath([string]$row.file)
        $origin = [System.IO.Path]::GetFullPath([string]$row.spec_origin)
        $resolved = [System.IO.Path]::GetFullPath([string]$row.resolved_path)
        $moduleId = [string]$row.module_id
        $relative = if ($file.StartsWith($rootPrefix,[System.StringComparison]::OrdinalIgnoreCase)) {
            $file.Substring($rootPrefix.Length)
        } else { '' }
        if ($moduleId -notmatch '^0x[0-9a-f]+$' -or $seenIds.ContainsKey($moduleId) -or
            $seenFiles.ContainsKey($file.ToLowerInvariant()) -or $file -ine $origin -or $file -ine $resolved -or
            [string]::IsNullOrWhiteSpace($relative) -or [System.IO.Path]::IsPathRooted($relative) -or
            $relative.Split([System.IO.Path]::DirectorySeparatorChar) -contains '..' -or
            [long]$row.size -lt 0 -or [long]$row.mtime_ns -le 0 -or [long]$row.ctime_ns -le 0 -or
            [string]$row.sha256 -notmatch '^[0-9A-F]{64}$') {
            throw "$Label invalid module row $($row.sys_modules_name)"
        }
        $seenIds[$moduleId] = $true
        $seenFiles[$file.ToLowerInvariant()] = $true
        $normalized += [pscustomobject][ordered]@{
            Name=[string]$row.sys_modules_name
            File=$file
            SpecOrigin=$origin
            ResolvedPath=$resolved
            RelativePath=$relative
            Size=[long]$row.size
            MTimeNs=[long]$row.mtime_ns
            CTimeNs=[long]$row.ctime_ns
            SHA256=[string]$row.sha256
        }
    }
    return ($normalized | ConvertTo-Json -Depth 8 -Compress)
}

function Assert-UID0002PAProcessLocalModuleContinuity {
    param(
        [Parameter(Mandatory=$true)]$State,
        [Parameter(Mandatory=$true)]$Owner,
        [Parameter(Mandatory=$true)][string]$Generation,
        [Parameter(Mandatory=$true)][string]$Label)
    if([string]::IsNullOrWhiteSpace($Generation)){throw "$Label blank process generation"}
    $rows=@($Owner.modules)
    $local=@($rows|ForEach-Object{"$([string]$_.sys_modules_name)|$([string]$_.module_id)"})
    if($local.Count -ne $rows.Count -or @($local|Select-Object -Unique).Count -ne $rows.Count){
        throw "$Label duplicate process-local module identity"
    }
    $localJson=$local|ConvertTo-Json -Compress
    if($State.ModuleIdsByGeneration.ContainsKey($Generation)){
        if([string]$State.ModuleIdsByGeneration[$Generation] -cne $localJson){
            throw "$Label same-generation module_id drift"
        }
    }else{
        $State.ModuleIdsByGeneration[$Generation]=$localJson
    }
    return $localJson
}

function Assert-UID0002PARuntimeAttestation {
    param(
        [Parameter(Mandatory=$true)]$Envelope,
        [Parameter(Mandatory=$true)][string]$AttestationRequestJson,
        [Parameter(Mandatory=$true)]$ListEnvelope,
        [Parameter(Mandatory=$true)][string]$ListRequestJson,
        [Parameter(Mandatory=$true)]$RoleBinding,
        [Parameter(Mandatory=$true)]$State)

    $attestationRequest=Get-UID0002PARequestIdentity $AttestationRequestJson 'RA-PA'
    $listRequest=Get-UID0002PARequestIdentity $ListRequestJson 'RA-PA idb_list'
    if([string]$attestationRequest.Parsed.method -cne 'tools/call' -or
        [string]$attestationRequest.Parsed.params.name -cne 'runtime_attestation' -or
        (@($attestationRequest.Parsed.params.arguments.PSObject.Properties.Name|Sort-Object)-join '|') -cne 'expected_canonical_path|expected_database' -or
        [string]$attestationRequest.Parsed.params.arguments.expected_database -cne [string]$RoleBinding.Database -or
        [System.IO.Path]::GetFullPath([string]$attestationRequest.Parsed.params.arguments.expected_canonical_path) -ine
            [System.IO.Path]::GetFullPath([string]$RoleBinding.CanonicalPath) -or
        [string]$listRequest.Parsed.method -cne 'tools/call' -or
        [string]$listRequest.Parsed.params.name -cne 'idb_list' -or
        @($listRequest.Parsed.params.arguments.PSObject.Properties).Count -ne 0){
        throw 'RA-PA retained runtime/list request mismatch'
    }
    $a = Get-UID0002PAStructuredContent -Envelope $Envelope -RequestJson $AttestationRequestJson -Label 'RA-PA'
    $list = Get-UID0002PAStructuredContent -Envelope $ListEnvelope -RequestJson $ListRequestJson -Label 'RA-PA idb_list'
    if ([int]$a.schema_version -ne 1 -or $a.ok -ne $true -or @($a.errors).Count -ne 0 -or $null -eq $a.listener) {
        throw 'RA-PA top-level schema/status/errors mismatch'
    }

    $listener = $a.listener
    if ([string]$listener.role -cne 'supervisor_listener' -or [string]$listener.nonce -notmatch '^[0-9a-f]{32}$' -or
        -not $State.UsedNonces.Add([string]$listener.nonce) -or [string]$listener.endpoint.host -cne '127.0.0.1' -or
        [int]$listener.endpoint.port -ne 13337 -or [int]$listener.process.pid -le 0 -or
        [long]$listener.process.creation_time_100ns -le 0 -or
        [string]$listener.process.generation -cne "pid:$($listener.process.pid);created:$($listener.process.creation_time_100ns)" -or
        [System.IO.Path]::GetFullPath([string]$listener.process.sys_executable) -ine
            [System.IO.Path]::GetFullPath([string]$listener.process.process_image)) {
        throw 'RA-PA listener nonce/process generation mismatch'
    }
    if ([Math]::Abs(([DateTimeOffset]::UtcNow - [DateTimeOffset]::Parse([string]$listener.attested_at_utc)).TotalMinutes) -gt 5) {
        throw 'RA-PA listener attestation is stale'
    }
    $portRows = @(Get-NetTCPConnection -LocalAddress '127.0.0.1' -LocalPort 13337 -State Listen -ErrorAction Stop)
    if ($portRows.Count -ne 1 -or [int]$portRows[0].OwningProcess -ne [int]$listener.process.pid) {
        throw 'RA-PA independent passive listener ownership mismatch'
    }
    $listenerManifest = Assert-UID0002PAModuleManifest -Owner $listener -Role listener -Label 'listener'
    $null=Assert-UID0002PAProcessLocalModuleContinuity -State $State -Owner $listener -Generation ([string]$listener.process.generation) -Label 'listener'
    if ($null -eq $State.ListenerGeneration) {
        $State.ListenerGeneration = [string]$listener.process.generation
        $State.ListenerManifest = $listenerManifest
    } elseif ($State.ListenerGeneration -cne [string]$listener.process.generation -or
        $State.ListenerManifest -cne $listenerManifest) {
        throw 'RA-PA listener generation/manifest changed during transaction'
    }

    $active = @($list.sessions | Where-Object { $_.is_active -eq $true })
    $attestedSessionRows = @($a.workers | ForEach-Object { @($_.supervisor_sessions) })
    if ($active.Count -ne $attestedSessionRows.Count) { throw 'RA-PA active/attested session count mismatch' }
    foreach ($session in $active) {
        $matches = @($attestedSessionRows | Where-Object { [string]$_.session_id -ceq [string]$session.session_id })
        if ($matches.Count -ne 1 -or [string]$matches[0].backend -cne 'worker' -or $matches[0].owned -ne $true -or
            [int]$matches[0].redirector_pid -le 0 -or
            [int]$matches[0].redirector_pid -ne [int]$matches[0].registered_pid -or
            [int]$matches[0].redirector_pid -ne [int]$session.worker_pid -or
            [System.IO.Path]::GetFullPath([string]$matches[0].canonical_path) -ine
                [System.IO.Path]::GetFullPath([string]$session.input_path)) {
            throw "RA-PA session route mismatch $($session.session_id)"
        }
    }

    foreach ($entry in @($a.workers)) {
        $wa = $entry.attestation
        $supervisorRows = @($entry.supervisor_sessions)
        if ([int]$wa.schema_version -ne 1 -or $wa.ok -ne $true -or @($wa.errors).Count -ne 0 -or
            $null -eq $wa.worker -or [string]$wa.worker.role -cne 'stateful_worker' -or
            [string]$wa.worker.nonce -notmatch '^[0-9a-f]{32}$' -or
            -not $State.UsedNonces.Add([string]$wa.worker.nonce) -or
            [string]$entry.route.host -cne [string]$wa.worker.endpoint.host -or
            [int]$entry.route.port -ne [int]$wa.worker.endpoint.port -or $supervisorRows.Count -ne 1) {
            throw 'RA-PA worker schema/status/nonce/endpoint mismatch'
        }
        if ([Math]::Abs(([DateTimeOffset]::UtcNow - [DateTimeOffset]::Parse([string]$wa.worker.attested_at_utc)).TotalMinutes) -gt 5) {
            throw 'RA-PA worker attestation is stale'
        }
        $supervisorRow = $supervisorRows[0]
        if ([int]$wa.worker.process.pid -le 0 -or
            [int]$wa.worker.process.parent_pid -ne [int]$supervisorRow.redirector_pid -or
            [long]$wa.worker.process.creation_time_100ns -le 0 -or
            [string]$wa.worker.process.generation -cne "pid:$($wa.worker.process.pid);created:$($wa.worker.process.creation_time_100ns)" -or
            [System.IO.Path]::GetFullPath([string]$wa.worker.process.sys_executable) -ine
                [System.IO.Path]::GetFullPath([string]$wa.worker.process.process_image)) {
            throw 'RA-PA worker process/redirector generation mismatch'
        }
        $workerSockets = @(Get-NetTCPConnection -LocalAddress '127.0.0.1' -LocalPort ([int]$entry.route.port) -State Listen -ErrorAction Stop)
        if ($workerSockets.Count -ne 1 -or [int]$workerSockets[0].OwningProcess -ne [int]$wa.worker.process.pid) {
            throw 'RA-PA worker socket-owner mismatch'
        }
        $workerManifest = Assert-UID0002PAModuleManifest -Owner $wa.worker -Role worker -Label 'worker'
        $null=Assert-UID0002PAProcessLocalModuleContinuity -State $State -Owner $wa.worker -Generation ([string]$wa.worker.process.generation) -Label 'worker'
        if ($null -eq $State.WorkerManifest) { $State.WorkerManifest = $workerManifest }
        elseif ($State.WorkerManifest -cne $workerManifest) { throw 'RA-PA worker manifest changed between roles' }

        $workerSessions = @($wa.sessions)
        if ($workerSessions.Count -ne 1 -or [string]$workerSessions[0].session_id -cne [string]$supervisorRow.session_id -or
            $workerSessions[0].is_active -ne $true -or
            [System.IO.Path]::GetFullPath([string]$workerSessions[0].input_path) -ine
                [System.IO.Path]::GetFullPath([string]$supervisorRow.canonical_path) -or
            [System.IO.Path]::GetFullPath([string]$workerSessions[0].canonical_path) -ine
                [System.IO.Path]::GetFullPath([string]$supervisorRow.canonical_path)) {
            throw 'RA-PA worker internal session/path mismatch'
        }
        $roleKey = [string]$supervisorRow.session_id
        $redirectorProcess=@(Get-CimInstance Win32_Process -Filter "ProcessId=$([int]$supervisorRow.redirector_pid)" -ErrorAction Stop)
        if($redirectorProcess.Count -ne 1){throw 'RA-PA redirector process identity missing/ambiguous'}
        $redirectorCreated100ns=([DateTime]$redirectorProcess[0].CreationDate).ToUniversalTime().ToFileTimeUtc()
        if($redirectorCreated100ns -le 0){throw 'RA-PA redirector process generation invalid'}
        $workerIdentity = [pscustomobject][ordered]@{
            Generation=[string]$wa.worker.process.generation
            RedirectorGeneration="pid:$([int]$supervisorRow.redirector_pid);created:$redirectorCreated100ns"
            ParentPid=[int]$wa.worker.process.parent_pid
            RedirectorPid=[int]$supervisorRow.redirector_pid
            WorkerPid=[int]$wa.worker.process.pid
            RoutePort=[int]$entry.route.port
        }
        if ($State.RoleWorkers.ContainsKey($roleKey)) {
            if (($State.RoleWorkers[$roleKey] | ConvertTo-Json -Compress) -cne
                ($workerIdentity | ConvertTo-Json -Compress)) { throw 'RA-PA role worker identity drift' }
        } else {
            foreach ($prior in $State.RoleWorkers.Values) {
                if ($prior.Generation -ceq $workerIdentity.Generation) { throw 'RA-PA worker generation reused across roles' }
            }
            $State.RoleWorkers[$roleKey] = $workerIdentity
        }
    }

    $roleRows = @($attestedSessionRows | Where-Object { [string]$_.session_id -ceq [string]$RoleBinding.Database })
    if ($roleRows.Count -ne 1 -or
        [int]$roleRows[0].redirector_pid -ne [int]$RoleBinding.CorroboratedRedirectorPid -or
        [System.IO.Path]::GetFullPath([string]$roleRows[0].canonical_path) -ine
            [System.IO.Path]::GetFullPath([string]$RoleBinding.CanonicalPath)) {
        throw 'RA-PA exact returned database/path absent or duplicated'
    }
    $roleWorker=$State.RoleWorkers[[string]$RoleBinding.Database]
    if ($null -eq $roleWorker) { throw 'RA-PA exact role worker identity missing' }
    if([string]$RoleBinding.Role -ceq 'Transaction'){
        if($null -eq $State.TransactionDatabase){
            $State.TransactionDatabase=[string]$RoleBinding.Database
            $State.TransactionGeneration=[string]$roleWorker.Generation
        } elseif([string]$State.TransactionDatabase -cne [string]$RoleBinding.Database -or
            [string]$State.TransactionGeneration -cne [string]$roleWorker.Generation){
            throw 'RA-PA transaction identity drift'
        }
    }
    return [pscustomobject]@{
        Role=[string]$RoleBinding.Role
        Database=[string]$RoleBinding.Database
        Passed=$true
        WorkerGeneration=[string]$roleWorker.Generation
        AttestationRequestId=(Get-UID0002PARequestIdentity $AttestationRequestJson 'RA-PA return').Id
        ListRequestId=(Get-UID0002PARequestIdentity $ListRequestJson 'RA-PA list return').Id
        ListenerGeneration=[string]$listener.process.generation
        ListenerNonce=[string]$listener.nonce
        ListenerManifest=$listenerManifest
        RoleWorker=$roleWorker
        ActiveDatabases=@($attestedSessionRows | ForEach-Object { [string]$_.session_id })
        WorkerGenerations=@($a.workers | ForEach-Object { [string]$_.attestation.worker.process.generation })
        WorkerNonces=@($a.workers | ForEach-Object { [string]$_.attestation.worker.nonce })
    }
}

function Assert-UID0002PAPostRetirementAttestation {
    param(
        [Parameter(Mandatory=$true)]$Envelope,
        [Parameter(Mandatory=$true)][string]$RequestJson,
        [Parameter(Mandatory=$true)]$RoleBinding,
        [Parameter(Mandatory=$true)]$State)

    $request=Get-UID0002PARequestIdentity $RequestJson 'RA-PA post-retirement'
    $arguments=$request.Parsed.params.arguments
    if([string]$request.Parsed.params.name -cne 'runtime_attestation' -or
        (@($arguments.PSObject.Properties.Name)-join '|') -cne 'expected_canonical_path' -or
        [System.IO.Path]::GetFullPath([string]$arguments.expected_canonical_path) -ine
            [System.IO.Path]::GetFullPath([string]$RoleBinding.CanonicalPath)){
        throw 'RA-PA post-retirement request is not exact path-only public attestation'
    }
    $a=Get-UID0002PAStructuredContent -Envelope $Envelope -RequestJson $RequestJson -Label 'RA-PA post-retirement'
    if([int]$a.schema_version -ne 1 -or $a.ok -ne $true -or @($a.errors).Count -ne 0 -or $null -eq $a.listener){
        throw 'RA-PA post-retirement top-level mismatch'
    }
    $listener=$a.listener
    if([string]$listener.role -cne 'supervisor_listener' -or [string]$listener.nonce -notmatch '^[0-9a-f]{32}$' -or
        -not $State.UsedNonces.Add([string]$listener.nonce) -or
        [string]$listener.endpoint.host -cne '127.0.0.1' -or [int]$listener.endpoint.port -ne 13337 -or
        [int]$listener.process.pid -le 0 -or [long]$listener.process.creation_time_100ns -le 0 -or
        [string]$listener.process.generation -cne "pid:$($listener.process.pid);created:$($listener.process.creation_time_100ns)" -or
        [string]$listener.process.generation -cne [string]$State.ListenerGeneration){
        throw 'RA-PA post-retirement listener generation/nonce mismatch'
    }
    if([Math]::Abs(([DateTimeOffset]::UtcNow-[DateTimeOffset]::Parse([string]$listener.attested_at_utc)).TotalMinutes) -gt 5){
        throw 'RA-PA post-retirement listener attestation is stale'
    }
    $portRows=@(Get-NetTCPConnection -LocalAddress '127.0.0.1' -LocalPort 13337 -State Listen -ErrorAction Stop)
    if($portRows.Count -ne 1 -or [int]$portRows[0].OwningProcess -ne [int]$listener.process.pid){
        throw 'RA-PA post-retirement listener ownership mismatch'
    }
    $listenerManifest=Assert-UID0002PAModuleManifest -Owner $listener -Role listener -Label 'post-retirement listener'
    $null=Assert-UID0002PAProcessLocalModuleContinuity -State $State -Owner $listener -Generation ([string]$listener.process.generation) -Label 'post-retirement listener'
    if($listenerManifest -cne [string]$State.ListenerManifest){throw 'RA-PA post-retirement listener manifest drift'}

    $retired=$State.RoleWorkers[[string]$RoleBinding.Database]
    if($null -eq $retired){throw 'RA-PA post-retirement role identity missing'}
    $survivingSessions=@()
    foreach($entry in @($a.workers)){
        $wa=$entry.attestation
        $supervisorRows=@($entry.supervisor_sessions)
        $workerSessions=@($wa.sessions)
        if([int]$wa.schema_version -ne 1 -or $wa.ok -ne $true -or @($wa.errors).Count -ne 0 -or
            $null -eq $wa.worker -or [string]$wa.worker.role -cne 'stateful_worker' -or
            [string]$wa.worker.nonce -notmatch '^[0-9a-f]{32}$' -or
            -not $State.UsedNonces.Add([string]$wa.worker.nonce) -or $supervisorRows.Count -ne 1 -or
            $workerSessions.Count -ne 1 -or [string]$entry.route.host -cne [string]$wa.worker.endpoint.host -or
            [int]$entry.route.port -ne [int]$wa.worker.endpoint.port){
            throw 'RA-PA post-retirement worker schema/status mismatch'
        }
        if([Math]::Abs(([DateTimeOffset]::UtcNow-[DateTimeOffset]::Parse([string]$wa.worker.attested_at_utc)).TotalMinutes) -gt 5){
            throw 'RA-PA post-retirement worker attestation is stale'
        }
        $supervisorRow=$supervisorRows[0]
        $workerSession=$workerSessions[0]
        if([int]$wa.worker.process.pid -le 0 -or [long]$wa.worker.process.creation_time_100ns -le 0 -or
            [string]$wa.worker.process.generation -cne "pid:$($wa.worker.process.pid);created:$($wa.worker.process.creation_time_100ns)" -or
            [int]$wa.worker.process.parent_pid -ne [int]$supervisorRow.redirector_pid -or
            [int]$supervisorRow.redirector_pid -le 0 -or
            [int]$supervisorRow.redirector_pid -ne [int]$supervisorRow.registered_pid -or
            [string]$workerSession.session_id -cne [string]$supervisorRow.session_id -or
            $workerSession.is_active -ne $true -or
            [System.IO.Path]::GetFullPath([string]$workerSession.input_path) -ine [System.IO.Path]::GetFullPath([string]$supervisorRow.canonical_path) -or
            [System.IO.Path]::GetFullPath([string]$workerSession.canonical_path) -ine [System.IO.Path]::GetFullPath([string]$supervisorRow.canonical_path)){
            throw 'RA-PA post-retirement surviving worker route/generation mismatch'
        }
        $workerSockets=@(Get-NetTCPConnection -LocalAddress '127.0.0.1' -LocalPort ([int]$entry.route.port) -State Listen -ErrorAction Stop)
        if($workerSockets.Count -ne 1 -or [int]$workerSockets[0].OwningProcess -ne [int]$wa.worker.process.pid){
            throw 'RA-PA post-retirement surviving worker socket-owner mismatch'
        }
        $manifest=Assert-UID0002PAModuleManifest -Owner $wa.worker -Role worker -Label 'post-retirement worker'
        $null=Assert-UID0002PAProcessLocalModuleContinuity -State $State -Owner $wa.worker -Generation ([string]$wa.worker.process.generation) -Label 'post-retirement worker'
        if($manifest -cne [string]$State.WorkerManifest){throw 'RA-PA post-retirement worker manifest drift'}
        if([int]$wa.worker.process.pid -in @([int]$retired.RedirectorPid,[int]$retired.WorkerPid) -or
            [int]$supervisorRow.redirector_pid -in @([int]$retired.RedirectorPid,[int]$retired.WorkerPid) -or
            @($entry.supervisor_sessions|Where-Object{[string]$_.session_id -ceq [string]$RoleBinding.Database}).Count -ne 0 -or
            @($wa.sessions|Where-Object{[string]$_.session_id -ceq [string]$RoleBinding.Database}).Count -ne 0){
            throw 'RA-PA retired database/PID still present in public runtime attestation'
        }
        $survivingSessions+=[pscustomobject][ordered]@{
            Database=[string]$supervisorRow.session_id
            CanonicalPath=[System.IO.Path]::GetFullPath([string]$supervisorRow.canonical_path)
            RedirectorPid=[int]$supervisorRow.redirector_pid
            WorkerPid=[int]$wa.worker.process.pid
            WorkerGeneration=[string]$wa.worker.process.generation
            RoutePort=[int]$entry.route.port
        }
    }
    [pscustomobject][ordered]@{
        Role=[string]$RoleBinding.Role;Database=[string]$RoleBinding.Database
        ListenerGeneration=[string]$listener.process.generation
        RequestId=$request.Id;RequestSHA256=$request.SHA256
        RetiredGeneration=[string]$retired.Generation
        RedirectorPid=[int]$retired.RedirectorPid;WorkerPid=[int]$retired.WorkerPid
        SurvivingSessions=@($survivingSessions)
        Passed=$true
    }
}
~~~
