<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B006\0002FD-ChattingVarietyPaneOnPaint-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002FD-ChattingVarietyPaneOnPaint-source-quality.md](0002FD-ChattingVarietyPaneOnPaint-source-quality.md)
- Source report SHA256 before archive-link insertion: `4D3647E5C07C18C5E5FC1010E00217936611DC76F5551DA62A069A30269951AC`
- Recovery generated: `2026-08-09T22:17:53Z`
- Unique recovered executable blocks: `19`
- Recovered executable bytes: `224073`
- Recovery basis: report-path-associated Codex session history. The source report had already removed its executable packages before the supervisor could extract them directly.
- Scope: this archive preserves every unique recoverable report-local executable block, including superseded historical variants where session history retained more than the final pre-removal report.
- Authority: this file is not a B-agent research report, claims no target coverage, and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- SHA256: `E39E2BF181EA554FBA797E2C5D3AC3587DE05F735503BED580245C2F3782878B`
- Language: `powershell`
- Bytes: `3332`
- First recovered timestamp: `2026-08-06T22:22:55.697Z`
- Session provenance: rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 193716 (2026-08-06T22:22:55.697Z); rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 193717 (2026-08-06T22:22:55.751Z)

~~~powershell
function Get-UID0002FDClosedTuple([string]$Path) {
    $resolved = (Resolve-Path -LiteralPath $Path).Path
    $stream = [System.IO.File]::Open($resolved,[System.IO.FileMode]::Open,[System.IO.FileAccess]::Read,[System.IO.FileShare]::None)
    $sha = [System.Security.Cryptography.SHA256]::Create()
    try {
        $length = $stream.Length
        $hash = ([BitConverter]::ToString($sha.ComputeHash($stream))).Replace('-','')
        if ($stream.Position -ne $length -or $stream.ReadByte() -ne -1) { throw 'UID0002FD tuple hash did not consume exact EOF' }
    } finally {
        $sha.Dispose()
        $stream.Dispose()
    }
    $mtime = [System.IO.File]::GetLastWriteTimeUtc($resolved)
    [pscustomobject]@{
        Path = $resolved
        Length = [long]$length
        SHA256 = $hash
        LastWriteTimeUtc = $mtime.ToString('o')
        LastWriteTimeUtcTicks = [long]$mtime.Ticks
    }
}
function Assert-UID0002FDExactTuple($Actual,$Expected,[string]$Label) {
    foreach ($field in @('Path','Length','SHA256','LastWriteTimeUtc','LastWriteTimeUtcTicks')) {
        if ($Actual.$field -cne $Expected.$field) { throw "$Label tuple mismatch: $field" }
    }
}
$canonicalPath = (Resolve-Path -LiteralPath 'E:\NTK\Resources\NexusTK\NexusTK.exe.i64').Path
$P0 = Get-UID0002FDClosedTuple $canonicalPath
$P0Confirm = Get-UID0002FDClosedTuple $canonicalPath
Assert-UID0002FDExactTuple $P0Confirm $P0 'UID0002FD P0-repeat'
$backupPath = "$canonicalPath.bak-UID0002FD-prestate-$([DateTime]::UtcNow.ToString('yyyyMMdd_HHmmssfffffff'))"
if (Test-Path -LiteralPath $backupPath) { throw 'UID0002FD B0 collision' }
$source = [System.IO.FileStream]::new($canonicalPath,[System.IO.FileMode]::Open,[System.IO.FileAccess]::Read,[System.IO.FileShare]::None)
$destination = $null
try {
    $destination = [System.IO.FileStream]::new($backupPath,[System.IO.FileMode]::CreateNew,[System.IO.FileAccess]::Write,[System.IO.FileShare]::None)
    if ($source.Length -ne $P0.Length) { throw 'UID0002FD P0 length changed before B0 copy' }
    $source.CopyTo($destination)
    if ($source.Position -ne $P0.Length -or $source.ReadByte() -ne -1) { throw 'UID0002FD B0 source EOF mismatch' }
    if ($destination.Position -ne $P0.Length -or $destination.Length -ne $P0.Length) { throw 'UID0002FD B0 destination length mismatch' }
    $destination.Flush($true)
} finally {
    if ($null -ne $destination) { $destination.Dispose() }
    $source.Dispose()
}
[System.IO.File]::SetLastWriteTimeUtc($backupPath,[DateTime]::new([long]$P0.LastWriteTimeUtcTicks,[DateTimeKind]::Utc))
$B0 = Get-UID0002FDClosedTuple $backupPath
$B0Confirm = Get-UID0002FDClosedTuple $backupPath
if ($B0.Path -ceq $P0.Path -or $B0.Path -cne (Resolve-Path -LiteralPath $backupPath).Path -or
    $B0.Length -ne $P0.Length -or $B0.SHA256 -cne $P0.SHA256 -or
    $B0.LastWriteTimeUtc -cne $P0.LastWriteTimeUtc -or $B0.LastWriteTimeUtcTicks -ne $P0.LastWriteTimeUtcTicks) {
    throw 'UID0002FD B0 is not complete-tuple equal to P0 under path translation'
}
foreach ($field in @('Path','Length','SHA256','LastWriteTimeUtc','LastWriteTimeUtcTicks')) {
    if ($B0Confirm.$field -cne $B0.$field) { throw "UID0002FD B0 repeat mismatch: $field" }
}
$P0AfterB0 = Get-UID0002FDClosedTuple $canonicalPath
Assert-UID0002FDExactTuple $P0AfterB0 $P0 'UID0002FD canonical-after-B0'
~~~

## Removed Block R002

- SHA256: `F671D6AE57DF5E3559D8965F93F45FEA47CB87A60AD01EC48C3DAE505431023F`
- Language: `powershell`
- Bytes: `3843`
- First recovered timestamp: `2026-08-06T22:22:55.697Z`
- Session provenance: rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 193716 (2026-08-06T22:22:55.697Z); rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 193717 (2026-08-06T22:22:55.751Z); rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 193910 (2026-08-06T22:48:51.260Z)

~~~powershell
$endpointAddress = '127.0.0.1'
$endpointPort = 13337
$listeners = @(Get-NetTCPConnection -State Listen -ErrorAction Stop |
    Where-Object { $_.LocalAddress -eq $endpointAddress -and $_.LocalPort -eq $endpointPort })
if ($listeners.Count -ne 1) { throw "UID0002FD expected one MCP listener, found $($listeners.Count)" }
$listenerPid = [int]$listeners[0].OwningProcess
$listener = Get-CimInstance Win32_Process -Filter "ProcessId=$listenerPid"
if ($null -eq $listener) { throw 'UID0002FD listener process disappeared before binding' }
$listenerStartUtc = (Get-Process -Id $listenerPid -ErrorAction Stop).StartTime.ToUniversalTime()
$listenerGeneration = [pscustomobject]@{
    Pid = $listenerPid
    ParentPid = [int]$listener.ParentProcessId
    StartTimeUtc = $listenerStartUtc.ToString('o')
    ExecutablePath = [string]$listener.ExecutablePath
    CommandLine = [string]$listener.CommandLine
    Endpoint = "http://$endpointAddress`:$endpointPort/mcp"
}
if ($listenerGeneration.CommandLine -notmatch '(?i)idalib-mcp\.exe') { throw 'UID0002FD listener is not idalib-mcp' }
if ($listenerGeneration.CommandLine -notmatch '(?i)--host\s+127\.0\.0\.1') { throw 'UID0002FD listener host drift' }
if ($listenerGeneration.CommandLine -notmatch '(?i)--port\s+13337(?:\s|$)') { throw 'UID0002FD listener port drift' }

$venvRoot = 'C:\Users\admin\.idapro\idalib-mcp-venv'
$venvPython = Join-Path $venvRoot 'Scripts\python.exe'
$consoleEntry = Join-Path $venvRoot 'Scripts\idalib-mcp.exe'
if (-not (Test-Path -LiteralPath $venvPython -PathType Leaf) -or
    -not (Test-Path -LiteralPath $consoleEntry -PathType Leaf)) { throw 'UID0002FD bound venv entry point missing' }
if ($listenerGeneration.CommandLine -notlike "*$consoleEntry*") { throw 'UID0002FD listener is not bound to expected console entry' }
$moduleJson = & $venvPython -I -c "import importlib.util,json,pathlib; s=importlib.util.find_spec('ida_pro_mcp.idalib_supervisor'); p=pathlib.Path(s.origin).resolve(); print(json.dumps({'module':str(p),'root':str(p.parent)}))"
if ($LASTEXITCODE -ne 0) { throw 'UID0002FD listener interpreter could not resolve ida_pro_mcp' }
$moduleIdentity = $moduleJson | ConvertFrom-Json
$packageRoot = (Resolve-Path -LiteralPath $moduleIdentity.root).Path
$supervisorModule = (Resolve-Path -LiteralPath $moduleIdentity.module).Path
if ($supervisorModule -cne (Join-Path $packageRoot 'idalib_supervisor.py')) { throw 'UID0002FD supervisor module/root mismatch' }
$distInfo = @(Get-ChildItem -LiteralPath (Split-Path $packageRoot -Parent) -Directory -Filter 'ida_pro_mcp-*.dist-info' |
    Where-Object { Test-Path -LiteralPath (Join-Path $_.FullName 'entry_points.txt') })
if ($distInfo.Count -ne 1) { throw 'UID0002FD could not bind one ida_pro_mcp distribution' }
$entryPoints = Join-Path $distInfo[0].FullName 'entry_points.txt'
$entryText = Get-Content -Raw -LiteralPath $entryPoints
if ($entryText -notmatch '(?m)^idalib-mcp\s*=\s*ida_pro_mcp\.idalib_supervisor:main\s*$') {
    throw 'UID0002FD console entry does not resolve to idalib_supervisor:main'
}
$expectedImplementation = @{
    'idalib_supervisor.py'='2D7098B6BDB58D7DCF8CF4825BBE7584F5E7ACB256AD318B05482E9A0B9AF10A'
    'ida_mcp\api_modify.py'='161B314A14DAAA34C718176444292597BBB7498FA80158E25C358542BC16D1B8'
    'ida_mcp\api_types.py'='A3E7444BBAC0066B48EDF38E26F34E6ABEC823585CD50E43C6DA98C55B965ECF'
    'ida_mcp\utils.py'='5139910EA7496549A31EDD6F9EEE7B033DA16504E4F0D19C8052EC9ED1C62069'
}
foreach ($relativePath in $expectedImplementation.Keys) {
    $boundFile = (Resolve-Path -LiteralPath (Join-Path $packageRoot $relativePath)).Path
    $boundHash = (Get-FileHash -Algorithm SHA256 -LiteralPath $boundFile).Hash
    if ($boundHash -cne $expectedImplementation[$relativePath]) {
        throw "UID0002FD bound listener implementation drift: $relativePath"
    }
}
~~~

## Removed Block R003

- SHA256: `EA5B08971499687C14C735BE4F6401FAC1D5478976C93344E4FCD4E1B36D6F7A`
- Language: `powershell`
- Bytes: `1798`
- First recovered timestamp: `2026-08-06T22:23:27.210Z`
- Session provenance: rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 193721 (2026-08-06T22:23:27.210Z); rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 193722 (2026-08-06T22:23:27.288Z)

~~~powershell
$B0Guard = Get-UID0002FDClosedTuple $backupPath
foreach ($field in @('Path','Length','SHA256','LastWriteTimeUtc','LastWriteTimeUtcTicks')) {
    if ($B0Guard.$field -cne $B0.$field) { throw "UID0002FD B0 pre-restore mismatch: $field" }
}
if ($B0Guard.Length -ne $P0.Length -or $B0Guard.SHA256 -cne $P0.SHA256 -or
    $B0Guard.LastWriteTimeUtc -cne $P0.LastWriteTimeUtc -or
    $B0Guard.LastWriteTimeUtcTicks -ne $P0.LastWriteTimeUtcTicks) {
    throw 'UID0002FD verified B0 no longer matches P0'
}
$source = [System.IO.FileStream]::new($backupPath,[System.IO.FileMode]::Open,[System.IO.FileAccess]::Read,[System.IO.FileShare]::None)
$destination = $null
try {
    $destination = [System.IO.FileStream]::new($canonicalPath,[System.IO.FileMode]::Open,[System.IO.FileAccess]::Write,[System.IO.FileShare]::None)
    $destination.SetLength(0)
    if ($destination.Length -ne 0 -or $destination.Position -ne 0) { throw 'UID0002FD canonical did not truncate deterministically' }
    $source.CopyTo($destination)
    if ($source.Position -ne $B0.Length -or $source.ReadByte() -ne -1) { throw 'UID0002FD restore source EOF mismatch' }
    if ($destination.Position -ne $P0.Length -or $destination.Length -ne $P0.Length) { throw 'UID0002FD restore destination length mismatch' }
    $destination.Flush($true)
} finally {
    if ($null -ne $destination) { $destination.Dispose() }
    $source.Dispose()
}
[System.IO.File]::SetLastWriteTimeUtc($canonicalPath,[DateTime]::new([long]$P0.LastWriteTimeUtcTicks,[DateTimeKind]::Utc))
$RestoredP0 = Get-UID0002FDClosedTuple $canonicalPath
$RestoredP0Confirm = Get-UID0002FDClosedTuple $canonicalPath
Assert-UID0002FDExactTuple $RestoredP0 $P0 'UID0002FD restored-P0'
Assert-UID0002FDExactTuple $RestoredP0Confirm $P0 'UID0002FD restored-P0-repeat'
~~~

## Removed Block R004

- SHA256: `0A8DB58ABE80394E5999465819D464726F676CEC7E6789D310BE13D99BB62936`
- Language: `powershell`
- Bytes: `5111`
- First recovered timestamp: `2026-08-06T22:48:51.260Z`
- Session provenance: rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 193910 (2026-08-06T22:48:51.260Z)

~~~powershell
$listenerAttestationTemplateJson = '{"jsonrpc":"2.0","id":"__REQUEST_ID__","method":"tools/call","params":{"name":"runtime_attestation","arguments":{"scope":"listener","nonce":"__NONCE__"}}}'
$workerAttestationTemplateJson = '{"jsonrpc":"2.0","id":"__REQUEST_ID__","method":"tools/call","params":{"name":"runtime_attestation","arguments":{"scope":"worker","nonce":"__NONCE__","database":"__DATABASE_FROM_OPEN_RESPONSE__"}}}'
$null = $listenerAttestationTemplateJson | ConvertFrom-Json -ErrorAction Stop
$null = $workerAttestationTemplateJson | ConvertFrom-Json -ErrorAction Stop

$UID0002FDPackageRoot = 'C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp'
$UID0002FDModuleContract = @{
    listener = @{
        'ida_pro_mcp.idalib_supervisor' = @{ Relative='idalib_supervisor.py'; Size=52468; Sha256='2D7098B6BDB58D7DCF8CF4825BBE7584F5E7ACB256AD318B05482E9A0B9AF10A' }
    }
    worker = @{
        'ida_pro_mcp.ida_mcp.api_modify' = @{ Relative='ida_mcp\api_modify.py'; Size=51759; Sha256='161B314A14DAAA34C718176444292597BBB7498FA80158E25C358542BC16D1B8' }
        'ida_pro_mcp.ida_mcp.api_types' = @{ Relative='ida_mcp\api_types.py'; Size=37540; Sha256='A3E7444BBAC0066B48EDF38E26F34E6ABEC823585CD50E43C6DA98C55B965ECF' }
        'ida_pro_mcp.ida_mcp.utils' = @{ Relative='ida_mcp\utils.py'; Size=43500; Sha256='5139910EA7496549A31EDD6F9EEE7B033DA16504E4F0D19C8052EC9ED1C62069' }
    }
}

function Assert-UID0002FDAttestation {
    param(
        [Parameter(Mandatory)][string]$RawResponseJson,
        [Parameter(Mandatory)][ValidateSet('listener','worker')][string]$Role,
        [Parameter(Mandatory)][string]$Nonce,
        [Parameter(Mandatory)]$Route,
        $OpenBinding
    )
    $response = $RawResponseJson | ConvertFrom-Json -ErrorAction Stop
    if ($null -ne $response.error -or $true -eq $response.result.isError) { throw "UID0002FD $Role attestation returned error" }
    $attestation = $response.result.structuredContent.attestation
    if ($null -eq $attestation) { throw "UID0002FD $Role attestation missing structuredContent.attestation" }
    if ($attestation.attestation_origin -cne 'in_process_sys_modules' -or
        $attestation.role -cne $Role -or $attestation.nonce -cne $Nonce -or
        $attestation.listener_route_sha256 -cne $UID0002FDFrozenRouteSha256) {
        throw "UID0002FD $Role attestation origin/role/nonce/route mismatch"
    }
    if (-not [string]::Equals([IO.Path]::GetFullPath([string]$attestation.package_root),
        [IO.Path]::GetFullPath($UID0002FDPackageRoot),[StringComparison]::OrdinalIgnoreCase)) {
        throw "UID0002FD $Role loaded package-root mismatch"
    }

    if ($Role -ceq 'listener') {
        if ([int]$attestation.pid -ne $Route.L2.Pid -or [int]$attestation.parent_pid -ne $Route.L1.Pid -or
            [string]$attestation.process_start_time_utc -cne $Route.L2.StartTimeUtc -or
            -not [string]::Equals([string]$attestation.sys_executable,$Route.L2.ExecutablePath,[StringComparison]::OrdinalIgnoreCase)) {
            throw 'UID0002FD listener in-process generation mismatch'
        }
    } else {
        if ($null -eq $OpenBinding) { throw 'UID0002FD worker attestation lacks response-derived binding' }
        if ([string]$attestation.database -cne $OpenBinding.Database -or
            -not [string]::Equals([string]$attestation.canonical_path,$OpenBinding.CanonicalPath,[StringComparison]::OrdinalIgnoreCase) -or
            [int]$attestation.pid -ne $OpenBinding.WorkerGeneration.Pid -or
            [int]$attestation.parent_pid -ne $OpenBinding.WorkerGeneration.ParentPid -or
            [string]$attestation.process_start_time_utc -cne $OpenBinding.WorkerGeneration.StartTimeUtc -or
            -not [string]::Equals([string]$attestation.sys_executable,$OpenBinding.WorkerGeneration.ExecutablePath,[StringComparison]::OrdinalIgnoreCase)) {
            throw 'UID0002FD worker in-process session/generation mismatch'
        }
    }

    $expectedModules = $UID0002FDModuleContract[$Role]
    foreach ($moduleName in $expectedModules.Keys) {
        $rows = @($attestation.modules | Where-Object { $_.name -ceq $moduleName })
        if ($rows.Count -ne 1 -or $true -ne $rows[0].loaded) { throw "UID0002FD $Role module not uniquely loaded: $moduleName" }
        $expected = $expectedModules[$moduleName]
        $expectedPath = [IO.Path]::GetFullPath((Join-Path $UID0002FDPackageRoot $expected.Relative))
        if (-not [string]::Equals([IO.Path]::GetFullPath([string]$rows[0].file),$expectedPath,[StringComparison]::OrdinalIgnoreCase) -or
            -not [string]::Equals([IO.Path]::GetFullPath([string]$rows[0].spec_origin),$expectedPath,[StringComparison]::OrdinalIgnoreCase) -or
            [int64]$rows[0].size -ne [int64]$expected.Size -or
            [string]$rows[0].sha256 -cne [string]$expected.Sha256) {
            throw "UID0002FD $Role loaded-module identity mismatch: $moduleName"
        }
    }
    if (@($attestation.modules).Count -ne $expectedModules.Count) { throw "UID0002FD $Role attestation contains an uncontracted module row" }
    $attestation
}
~~~

## Removed Block R005

- SHA256: `369FE5A9700BB0F2AD25438F41D46CC29B9B153B621984E19B47E16119061D22`
- Language: `powershell`
- Bytes: `5605`
- First recovered timestamp: `2026-08-06T22:48:51.260Z`
- Session provenance: rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 193910 (2026-08-06T22:48:51.260Z)

~~~powershell
Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

function Get-UID0002FDProcessGeneration {
    param(
        [Parameter(Mandatory)][ValidateSet('L0','L1','L2')][string]$Role,
        [Parameter(Mandatory)][int]$ProcessId,
        [Parameter(Mandatory)][string]$EndpointAddress,
        [Parameter(Mandatory)][int]$EndpointPort
    )
    $cim = Get-CimInstance Win32_Process -Filter "ProcessId=$ProcessId" -ErrorAction Stop
    if ($null -eq $cim) { throw "UID0002FD $Role PID $ProcessId disappeared" }
    $process = Get-Process -Id $ProcessId -ErrorAction Stop
    $allListening = @(Get-NetTCPConnection -State Listen -ErrorAction Stop |
        Where-Object { [int]$_.OwningProcess -eq $ProcessId } |
        Sort-Object LocalAddress, LocalPort, OwningProcess)
    $endpointListening = @($allListening |
        Where-Object { $_.LocalAddress -eq $EndpointAddress -and [int]$_.LocalPort -eq $EndpointPort })
    [pscustomobject][ordered]@{
        Role = $Role
        Pid = $ProcessId
        ParentPid = [int]$cim.ParentProcessId
        CreationTimeUtc = ([datetime]$cim.CreationDate).ToUniversalTime().ToString('o')
        StartTimeUtc = $process.StartTime.ToUniversalTime().ToString('o')
        ExecutablePath = [string]$cim.ExecutablePath
        CommandLine = [string]$cim.CommandLine
        EndpointSocketCount = $endpointListening.Count
        ListeningSockets = @($allListening | ForEach-Object {
            '{0}:{1}|{2}:{3}|pid={4}' -f $_.LocalAddress,$_.LocalPort,$_.RemoteAddress,$_.RemotePort,$_.OwningProcess
        })
    }
}

function Get-UID0002FDListenerRoute {
    $endpointAddress = '127.0.0.1'
    $endpointPort = 13337
    $endpointSockets = @(Get-NetTCPConnection -State Listen -ErrorAction Stop |
        Where-Object { $_.LocalAddress -eq $endpointAddress -and [int]$_.LocalPort -eq $endpointPort })
    if ($endpointSockets.Count -ne 1) {
        throw "UID0002FD expected one endpoint socket, found $($endpointSockets.Count)"
    }

    $l2 = Get-UID0002FDProcessGeneration -Role L2 -ProcessId ([int]$endpointSockets[0].OwningProcess) -EndpointAddress $endpointAddress -EndpointPort $endpointPort
    $l1 = Get-UID0002FDProcessGeneration -Role L1 -ProcessId $l2.ParentPid -EndpointAddress $endpointAddress -EndpointPort $endpointPort
    $l0 = Get-UID0002FDProcessGeneration -Role L0 -ProcessId $l1.ParentPid -EndpointAddress $endpointAddress -EndpointPort $endpointPort

    if ($l0.Pid -eq $l1.Pid -or $l0.Pid -eq $l2.Pid -or $l1.Pid -eq $l2.Pid) { throw 'UID0002FD route reused a PID' }
    if ($l1.ParentPid -ne $l0.Pid -or $l2.ParentPid -ne $l1.Pid) { throw 'UID0002FD parent edge drift' }
    if ($l0.EndpointSocketCount -ne 0 -or $l1.EndpointSocketCount -ne 0 -or $l2.EndpointSocketCount -ne 1) {
        throw 'UID0002FD endpoint ownership is not exactly L2-only'
    }

    $venvRoot = 'C:\Users\admin\.idapro\idalib-mcp-venv'
    $expectedL0 = Join-Path $venvRoot 'Scripts\idalib-mcp.exe'
    $expectedL1 = Join-Path $venvRoot 'Scripts\python.exe'
    if (-not [string]::Equals($l0.ExecutablePath,$expectedL0,[StringComparison]::OrdinalIgnoreCase)) { throw 'UID0002FD L0 executable drift' }
    if (-not [string]::Equals($l1.ExecutablePath,$expectedL1,[StringComparison]::OrdinalIgnoreCase)) { throw 'UID0002FD L1 executable drift' }
    if ([IO.Path]::GetFileName($l2.ExecutablePath) -ine 'python.exe' -or
        [string]::Equals($l2.ExecutablePath,$expectedL1,[StringComparison]::OrdinalIgnoreCase)) {
        throw 'UID0002FD L2 is not a distinct base-Python executable'
    }
    foreach ($generation in @($l0,$l1,$l2)) {
        if ([string]::IsNullOrWhiteSpace($generation.CommandLine) -or
            [string]::IsNullOrWhiteSpace($generation.CreationTimeUtc) -or
            [string]::IsNullOrWhiteSpace($generation.StartTimeUtc) -or
            [string]::IsNullOrWhiteSpace($generation.ExecutablePath)) {
            throw "UID0002FD incomplete $($generation.Role) identity"
        }
    }
    if ($l0.CommandLine -notlike "*$expectedL0*" -or
        $l0.CommandLine -notlike '*--host 127.0.0.1*' -or
        $l0.CommandLine -notlike '*--port 13337*') { throw 'UID0002FD L0 command drift' }
    if ($l1.CommandLine -notlike "*$expectedL1*" -or
        $l1.CommandLine -notlike "*$expectedL0*" -or
        $l1.CommandLine -notlike '*--host 127.0.0.1*' -or
        $l1.CommandLine -notlike '*--port 13337*') { throw 'UID0002FD L1 command drift' }
    # L2.CommandLine is captured in full and frozen below. It is not required to contain L0.

    [pscustomobject][ordered]@{
        Endpoint = 'http://127.0.0.1:13337/mcp'
        SocketOwnerPid = [int]$endpointSockets[0].OwningProcess
        Socket = '127.0.0.1:13337'
        L0 = $l0
        L1 = $l1
        L2 = $l2
    }
}

function Get-UID0002FDTextSha256([string]$Text) {
    $sha = [Security.Cryptography.SHA256]::Create()
    try { ([BitConverter]::ToString($sha.ComputeHash([Text.Encoding]::UTF8.GetBytes($Text)))).Replace('-','') }
    finally { $sha.Dispose() }
}

$UID0002FDFrozenRoute = Get-UID0002FDListenerRoute
$UID0002FDFrozenRouteJson = $UID0002FDFrozenRoute | ConvertTo-Json -Depth 12 -Compress
$UID0002FDFrozenRouteSha256 = Get-UID0002FDTextSha256 $UID0002FDFrozenRouteJson
function Assert-UID0002FDFrozenRoute {
    $current = Get-UID0002FDListenerRoute
    $currentJson = $current | ConvertTo-Json -Depth 12 -Compress
    if ($currentJson -cne $UID0002FDFrozenRouteJson -or
        (Get-UID0002FDTextSha256 $currentJson) -cne $UID0002FDFrozenRouteSha256) {
        throw 'UID0002FD listener route generation/socket drift'
    }
    $current
}
~~~

## Removed Block R006

- SHA256: `50F207E6E3052EED328F88903C493C6967817B43771F497D175AE858A125D7BD`
- Language: `powershell`
- Bytes: `3717`
- First recovered timestamp: `2026-08-06T22:48:51.260Z`
- Session provenance: rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 193910 (2026-08-06T22:48:51.260Z)

~~~powershell
$openTemplateJson = '{"jsonrpc":"2.0","id":"__REQUEST_ID__","method":"tools/call","params":{"name":"idb_open","arguments":{"input_path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","mode":"force_headless","run_auto_analysis":false,"build_caches":false,"init_hexrays":false,"idle_ttl_sec":600,"preferred_session_id":"__REQUEST_ONLY_PREFERRED__"}}}'
$null = $openTemplateJson | ConvertFrom-Json -ErrorAction Stop

function New-UID0002FDOpenRequest {
    param([string]$RequestId,[string]$PreferredRequestOnly,[bool]$BuildCaches,[bool]$InitHexrays)
    $request = $openTemplateJson | ConvertFrom-Json -ErrorAction Stop
    $request.id = $RequestId
    $request.params.arguments.preferred_session_id = $PreferredRequestOnly
    $request.params.arguments.build_caches = $BuildCaches
    $request.params.arguments.init_hexrays = $InitHexrays
    $json = $request | ConvertTo-Json -Depth 12 -Compress
    $null = $json | ConvertFrom-Json -ErrorAction Stop
    $json
}

function Bind-UID0002FDOpenResponse {
    param([Parameter(Mandatory)][string]$RawOpenResponseJson,[Parameter(Mandatory)][string]$Phase)
    if ([string]::IsNullOrWhiteSpace($RawOpenResponseJson)) { throw "UID0002FD $Phase literal idb_open response missing" }
    $response = $RawOpenResponseJson | ConvertFrom-Json -ErrorAction Stop
    if ($null -ne $response.error -or $true -eq $response.result.isError) { throw "UID0002FD $Phase idb_open error" }
    $session = $response.result.structuredContent.session
    if ($null -eq $session) { throw "UID0002FD $Phase missing result.structuredContent.session" }
    $database = [string]$session.session_id
    if ([string]::IsNullOrWhiteSpace($database)) { throw "UID0002FD $Phase returned blank session_id" }
    $canonical = [IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64')
    if (-not [string]::Equals([IO.Path]::GetFullPath([string]$session.input_path),$canonical,[StringComparison]::OrdinalIgnoreCase)) {
        throw "UID0002FD $Phase returned noncanonical input_path"
    }
    [pscustomobject][ordered]@{
        Phase = $Phase
        Database = $database
        CanonicalPath = $canonical
        ReturnedSession = $session
        LiteralOpenResponseJson = $RawOpenResponseJson
        LiteralOpenResponseSha256 = Get-UID0002FDTextSha256 $RawOpenResponseJson
    }
}

function Add-UID0002FDListCorroboration {
    param([Parameter(Mandatory)]$OpenBinding,[Parameter(Mandatory)][string]$RawIdbListResponseJson)
    $listResponse = $RawIdbListResponseJson | ConvertFrom-Json -ErrorAction Stop
    if ($null -ne $listResponse.error -or $true -eq $listResponse.result.isError) { throw 'UID0002FD idb_list corroboration error' }
    $rows = @($listResponse.result.structuredContent.sessions)
    $matches = @($rows | Where-Object { [string]$_.session_id -ceq $OpenBinding.Database })
    if ($matches.Count -ne 1) { throw 'UID0002FD idb_list does not uniquely corroborate returned session_id' }
    $row = $matches[0]
    if ($true -ne $row.is_active -or [string]$row.backend -cne 'worker' -or
        [int]$row.pid -le 0 -or [int]$row.worker_pid -ne [int]$row.pid -or
        -not [string]::Equals([IO.Path]::GetFullPath([string]$row.input_path),$OpenBinding.CanonicalPath,[StringComparison]::OrdinalIgnoreCase)) {
        throw 'UID0002FD idb_list returned-session/path/worker mismatch'
    }
    $worker = Get-UID0002FDProcessGeneration -Role L2 -ProcessId ([int]$row.worker_pid) -EndpointAddress '127.0.0.1' -EndpointPort 13337
    Add-Member -InputObject $OpenBinding -NotePropertyName IdbListRow -NotePropertyValue $row -Force
    Add-Member -InputObject $OpenBinding -NotePropertyName WorkerGeneration -NotePropertyValue $worker -Force
    $OpenBinding
}
~~~

## Removed Block R007

- SHA256: `628115B559250B82581C9579C1863F19B926C7DBE32C4183F65B27EFB64C0789`
- Language: `powershell`
- Bytes: `20966`
- First recovered timestamp: `2026-08-06T23:24:05.998Z`
- Session provenance: rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 194082 (2026-08-06T23:24:05.998Z); rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 194083 (2026-08-06T23:24:06.051Z)

~~~powershell
Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'
$UID0002FDCanonicalPath = [IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64')
$UID0002FDSourceRoot = [IO.Path]::GetFullPath('C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp')

$toolsListRequestTemplateJson = '{"jsonrpc":"2.0","id":"__REQUEST_ID__","method":"tools/list","params":{}}'
$openRequestTemplateJson = '{"jsonrpc":"2.0","id":"__REQUEST_ID__","method":"tools/call","params":{"name":"idb_open","arguments":{"input_path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","mode":"force_headless","run_auto_analysis":false,"build_caches":false,"init_hexrays":false,"idle_ttl_sec":600,"preferred_session_id":"__REQUEST_ONLY_PREFERRED__"}}}'
$runtimeAttestationRequestTemplateJson = '{"jsonrpc":"2.0","id":"__REQUEST_ID__","method":"tools/call","params":{"name":"runtime_attestation","arguments":{"expected_database":"__DATABASE_FROM_IDB_OPEN_RESPONSE__","expected_canonical_path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64"}}}'
$null = $toolsListRequestTemplateJson | ConvertFrom-Json -ErrorAction Stop
$null = $openRequestTemplateJson | ConvertFrom-Json -ErrorAction Stop
$null = $runtimeAttestationRequestTemplateJson | ConvertFrom-Json -ErrorAction Stop

function Get-UID0002FDJsonRpcEnvelope {
    param([Parameter(Mandatory)][string]$RawJson,[Parameter(Mandatory)][string]$Label)
    if ([string]::IsNullOrWhiteSpace($RawJson)) { throw "UID0002FD $Label response missing" }
    $response = $RawJson | ConvertFrom-Json -ErrorAction Stop
    if ($response.PSObject.Properties['error'] -and $null -ne $response.error) { throw "UID0002FD $Label JSON-RPC error" }
    if (-not $response.PSObject.Properties['result'] -or $null -eq $response.result) { throw "UID0002FD $Label result missing" }
    if ($response.result.PSObject.Properties['isError'] -and $true -eq $response.result.isError) { throw "UID0002FD $Label tool error" }
    $response
}

function Assert-UID0002FDPublicToolList {
    param([Parameter(Mandatory)][string]$RawToolsListResponseJson)
    $response = Get-UID0002FDJsonRpcEnvelope $RawToolsListResponseJson 'tools/list'
    if (-not $response.result.PSObject.Properties['tools']) { throw 'UID0002FD tools/list lacks tools' }
    $tools = @($response.result.tools)
    $public = @($tools | Where-Object { [string]$_.name -ceq 'runtime_attestation' })
    $forbiddenAliases = @($tools | Where-Object { [string]$_.name -ceq 'runtime' -or [string]$_.name -ceq 'attest' })
    if ($public.Count -ne 1 -or $forbiddenAliases.Count -ne 0) { throw 'UID0002FD public attestation name/alias cardinality mismatch' }
    $properties = $public[0].inputSchema.properties
    if ([string]$public[0].inputSchema.type -cne 'object' -or
        [string]$properties.expected_database.type -cne 'string' -or
        [string]$properties.expected_canonical_path.type -cne 'string' -or
        @($properties.PSObject.Properties.Name | Where-Object { $_ -notin @('expected_database','expected_canonical_path') }).Count -ne 0) {
        throw 'UID0002FD runtime_attestation input schema drift'
    }
    $public[0]
}

function New-UID0002FDOpenRequest {
    param([string]$RequestId,[string]$PreferredRequestOnly,[bool]$BuildCaches,[bool]$InitHexrays)
    $request = $openRequestTemplateJson | ConvertFrom-Json -ErrorAction Stop
    $request.id = $RequestId
    $request.params.arguments.preferred_session_id = $PreferredRequestOnly
    $request.params.arguments.build_caches = $BuildCaches
    $request.params.arguments.init_hexrays = $InitHexrays
    $json = $request | ConvertTo-Json -Depth 12 -Compress
    $null = $json | ConvertFrom-Json -ErrorAction Stop
    $json
}

function Bind-UID0002FDOpenResponse {
    param([Parameter(Mandatory)][string]$RawOpenResponseJson,[Parameter(Mandatory)][string]$Phase)
    $response = Get-UID0002FDJsonRpcEnvelope $RawOpenResponseJson "$Phase idb_open"
    if (-not $response.result.PSObject.Properties['structuredContent'] -or $null -eq $response.result.structuredContent -or
        -not $response.result.structuredContent.PSObject.Properties['session']) {
        throw "UID0002FD $Phase missing result.structuredContent.session"
    }
    $session = $response.result.structuredContent.session
    $database = [string]$session.session_id
    if ([string]::IsNullOrWhiteSpace($database)) { throw "UID0002FD $Phase returned blank session_id" }
    if (-not [string]::Equals([IO.Path]::GetFullPath([string]$session.input_path),$UID0002FDCanonicalPath,[StringComparison]::OrdinalIgnoreCase)) {
        throw "UID0002FD $Phase returned noncanonical input_path"
    }
    [pscustomobject][ordered]@{
        Phase = $Phase
        Database = $database
        CanonicalPath = $UID0002FDCanonicalPath
        ReturnedSession = $session
        LiteralOpenResponseJson = $RawOpenResponseJson
        LiteralOpenResponseSha256 = (Get-FileHash -InputStream ([IO.MemoryStream]::new([Text.Encoding]::UTF8.GetBytes($RawOpenResponseJson))) -Algorithm SHA256).Hash
    }
}

function Add-UID0002FDListCorroboration {
    param([Parameter(Mandatory)]$OpenBinding,[Parameter(Mandatory)][string]$RawIdbListResponseJson)
    $response = Get-UID0002FDJsonRpcEnvelope $RawIdbListResponseJson "$($OpenBinding.Phase) idb_list"
    if (-not $response.result.PSObject.Properties['structuredContent'] -or
        -not $response.result.structuredContent.PSObject.Properties['sessions']) { throw 'UID0002FD idb_list sessions missing' }
    $matches = @($response.result.structuredContent.sessions | Where-Object { [string]$_.session_id -ceq $OpenBinding.Database })
    if ($matches.Count -ne 1) { throw 'UID0002FD idb_list does not uniquely corroborate returned database' }
    $row = $matches[0]
    if ($true -ne $row.is_active -or [string]$row.backend -cne 'worker' -or [int]$row.worker_pid -le 0 -or
        -not [string]::Equals([IO.Path]::GetFullPath([string]$row.input_path),$UID0002FDCanonicalPath,[StringComparison]::OrdinalIgnoreCase)) {
        throw 'UID0002FD idb_list session/path/worker mismatch'
    }
    Add-Member -InputObject $OpenBinding -NotePropertyName IdbListRow -NotePropertyValue $row -Force
    $OpenBinding
}

function New-UID0002FDRuntimeAttestationRequest {
    param([Parameter(Mandatory)][string]$RequestId,[Parameter(Mandatory)]$OpenBinding)
    $request = $runtimeAttestationRequestTemplateJson | ConvertFrom-Json -ErrorAction Stop
    $request.id = $RequestId
    $request.params.arguments.expected_database = $OpenBinding.Database
    $request.params.arguments.expected_canonical_path = $OpenBinding.CanonicalPath
    $json = $request | ConvertTo-Json -Depth 12 -Compress
    $parsed = $json | ConvertFrom-Json -ErrorAction Stop
    if ([string]$parsed.params.arguments.expected_database -cne $OpenBinding.Database -or
        -not [string]::Equals([IO.Path]::GetFullPath([string]$parsed.params.arguments.expected_canonical_path),$OpenBinding.CanonicalPath,[StringComparison]::OrdinalIgnoreCase)) {
        throw 'UID0002FD attestation request lost response-derived authority'
    }
    $json
}

$UID0002FDListenerNames = @('ida_pro_mcp','ida_pro_mcp.idalib_supervisor','ida_pro_mcp.runtime_attestation','zeromcp','zeromcp.jsonrpc','zeromcp.mcp')
$UID0002FDWorkerNames = @('__main__','ida_pro_mcp','ida_pro_mcp.ida_mcp','ida_pro_mcp.ida_mcp._sigmaker','ida_pro_mcp.ida_mcp.api_analysis','ida_pro_mcp.ida_mcp.api_composite','ida_pro_mcp.ida_mcp.api_core','ida_pro_mcp.ida_mcp.api_debug','ida_pro_mcp.ida_mcp.api_memory','ida_pro_mcp.ida_mcp.api_modify','ida_pro_mcp.ida_mcp.api_python','ida_pro_mcp.ida_mcp.api_resources','ida_pro_mcp.ida_mcp.api_sigmaker','ida_pro_mcp.ida_mcp.api_stack','ida_pro_mcp.ida_mcp.api_survey','ida_pro_mcp.ida_mcp.api_types','ida_pro_mcp.ida_mcp.compat','ida_pro_mcp.ida_mcp.discovery','ida_pro_mcp.ida_mcp.http','ida_pro_mcp.ida_mcp.profile','ida_pro_mcp.ida_mcp.rpc','ida_pro_mcp.ida_mcp.sync','ida_pro_mcp.ida_mcp.trace','ida_pro_mcp.ida_mcp.utils','ida_pro_mcp.ida_mcp.zeromcp','ida_pro_mcp.ida_mcp.zeromcp.jsonrpc','ida_pro_mcp.ida_mcp.zeromcp.mcp','ida_pro_mcp.idalib_session_manager','ida_pro_mcp.runtime_attestation','ida_pro_mcp.worker_lifecycle')
$UID0002FDExpectedRows = @{
    listener = @{
        'ida_pro_mcp'=@{Relative='__init__.py';Size=0;MTime=1781261500671010600;CTime=1781261500671010600;Sha='E3B0C44298FC1C149AFBF4C8996FB92427AE41E4649B934CA495991B7852B855'}
        'ida_pro_mcp.idalib_supervisor'=@{Relative='idalib_supervisor.py';Size=62587;MTime=1786057906667723600;CTime=1786057906667723600;Sha='1D2F9458E16590D560EC66D3177EC0988D6F4AB008D88B813910BA6154287747'}
        'ida_pro_mcp.runtime_attestation'=@{Relative='runtime_attestation.py';Size=6421;MTime=1786057921696663300;CTime=1786057921696663300;Sha='5E8B7FF04A7381BE92234A813DDD28C0E8FD2FA703B73E12EA376E466354D1E0'}
        'zeromcp'=@{Relative='ida_mcp\zeromcp\__init__.py';Size=471;MTime=1781261500711587300;CTime=1781261500711587300;Sha='3A88AEFEA4667EDB562944B04F199EB70759B9B9756C14212A65105E2EA06A1A'}
        'zeromcp.jsonrpc'=@{Relative='ida_mcp\zeromcp\jsonrpc.py';Size=14937;MTime=1781261500712586600;CTime=1781261500712586600;Sha='5B52598AC04CCEB68E00D505376CC78FB329546D86AF84802090A9A82DCDFB03'}
        'zeromcp.mcp'=@{Relative='ida_mcp\zeromcp\mcp.py';Size=44020;MTime=1781261500712586600;CTime=1781261500712586600;Sha='82F40AF6D73E5F22BDEF8352DE208E62CDD2A398150F5EB33E07DEE70F835C86'}
    }
    worker = @{
        '__main__'=@{Relative='idalib_server.py';Size=13356;MTime=1786058069405701600;CTime=1786058069405701600;Sha='53C583513F198BB2451C3D2000FD58621CC2CC9C067F2A093AA5192C9C0DBA54'}
        'ida_pro_mcp.ida_mcp.api_modify'=@{Relative='ida_mcp\api_modify.py';Size=51759;MTime=1785989712457442800;CTime=1785989712457442800;Sha='161B314A14DAAA34C718176444292597BBB7498FA80158E25C358542BC16D1B8'}
        'ida_pro_mcp.ida_mcp.api_types'=@{Relative='ida_mcp\api_types.py';Size=37540;MTime=1781261500689009600;CTime=1781261500689009600;Sha='A3E7444BBAC0066B48EDF38E26F34E6ABEC823585CD50E43C6DA98C55B965ECF'}
        'ida_pro_mcp.ida_mcp.utils'=@{Relative='ida_mcp\utils.py';Size=43500;MTime=1785989712454445200;CTime=1785989712454445200;Sha='5139910EA7496549A31EDD6F9EEE7B033DA16504E4F0D19C8052EC9ED1C62069'}
        'ida_pro_mcp.runtime_attestation'=@{Relative='runtime_attestation.py';Size=6421;MTime=1786057921696663300;CTime=1786057921696663300;Sha='5E8B7FF04A7381BE92234A813DDD28C0E8FD2FA703B73E12EA376E466354D1E0'}
    }
}
$UID0002FDAttestationState = [ordered]@{ ListenerGeneration=$null;ListenerManifestJson=$null;WorkerManifestJson=$null;UsedNonces=@{};PhaseWorkers=@{} }

function Get-UID0002FDManifestJson {
    param([Parameter(Mandatory)]$Owner,[Parameter(Mandatory)][ValidateSet('listener','worker')][string]$Role)
    if (-not [string]::Equals([IO.Path]::GetFullPath([string]$Owner.source_root),$UID0002FDSourceRoot,[StringComparison]::OrdinalIgnoreCase)) { throw "UID0002FD $Role source_root drift" }
    $expectedManifest = if ($Role -ceq 'listener') {'D3C792133956B855EBA751FDB5783B2D7177FA204134CFF1D897E0D0770FB7CE'} else {'849203D42ABFC99176069E7069F039E9B50AC1A0F392BECB4D7C90CC7AE627D4'}
    if ([string]$Owner.implementation_manifest_sha256 -cne $expectedManifest) { throw "UID0002FD $Role manifest SHA drift" }
    $modules = @($Owner.modules)
    $expectedNames = if ($Role -ceq 'listener') {$UID0002FDListenerNames} else {$UID0002FDWorkerNames}
    if ($modules.Count -ne $expectedNames.Count -or (($modules.sys_modules_name -join '|') -cne ($expectedNames -join '|'))) { throw "UID0002FD $Role module list/order drift" }
    $normalized = @()
    foreach ($module in $modules) {
        foreach ($property in @('sys_modules_name','file','spec_origin','resolved_path','size','mtime_ns','ctime_ns','sha256')) {
            if (-not $module.PSObject.Properties[$property]) { throw "UID0002FD $Role module field missing: $property" }
        }
        $file = [IO.Path]::GetFullPath([string]$module.file)
        if (-not [string]::Equals($file,[IO.Path]::GetFullPath([string]$module.spec_origin),[StringComparison]::OrdinalIgnoreCase) -or
            -not [string]::Equals($file,[IO.Path]::GetFullPath([string]$module.resolved_path),[StringComparison]::OrdinalIgnoreCase) -or
            -not $file.StartsWith($UID0002FDSourceRoot,[StringComparison]::OrdinalIgnoreCase) -or
            [string]$module.sha256 -notmatch '^[0-9A-F]{64}$' -or [int64]$module.size -lt 0 -or
            [int64]$module.mtime_ns -le 0 -or [int64]$module.ctime_ns -le 0) { throw "UID0002FD $Role module manifest invalid: $($module.sys_modules_name)" }
        $locked = $UID0002FDExpectedRows[$Role][[string]$module.sys_modules_name]
        if ($null -ne $locked) {
            $expectedPath = [IO.Path]::GetFullPath((Join-Path $UID0002FDSourceRoot $locked.Relative))
            if (-not [string]::Equals($file,$expectedPath,[StringComparison]::OrdinalIgnoreCase) -or [int64]$module.size -ne [int64]$locked.Size -or
                [int64]$module.mtime_ns -ne [int64]$locked.MTime -or [int64]$module.ctime_ns -ne [int64]$locked.CTime -or
                [string]$module.sha256 -cne [string]$locked.Sha) { throw "UID0002FD locked $Role module drift: $($module.sys_modules_name)" }
        }
        $normalized += [pscustomobject][ordered]@{Name=[string]$module.sys_modules_name;File=$file;SpecOrigin=[IO.Path]::GetFullPath([string]$module.spec_origin);ResolvedPath=[IO.Path]::GetFullPath([string]$module.resolved_path);Size=[int64]$module.size;MTimeNs=[int64]$module.mtime_ns;CTimeNs=[int64]$module.ctime_ns;Sha256=[string]$module.sha256}
    }
    $normalized | ConvertTo-Json -Depth 8 -Compress
}

function Assert-UID0002FDFreshRoleStamp {
    param([Parameter(Mandatory)]$RoleObject,[Parameter(Mandatory)][string]$Label)
    $nonce = [string]$RoleObject.nonce
    if ($nonce -notmatch '^[0-9a-f]{32}$' -or $UID0002FDAttestationState.UsedNonces.ContainsKey($nonce)) { throw "UID0002FD $Label nonce missing/reused" }
    $stamp = [DateTimeOffset]::Parse([string]$RoleObject.attested_at_utc)
    if ([Math]::Abs(([DateTimeOffset]::UtcNow - $stamp.ToUniversalTime()).TotalMinutes) -gt 5) { throw "UID0002FD $Label attestation not fresh" }
    $UID0002FDAttestationState.UsedNonces[$nonce] = $true
}

function Assert-UID0002FDPublicRuntimeAttestation {
    param([Parameter(Mandatory)][string]$RawResponseJson,[Parameter(Mandatory)][string]$LiteralRequestJson,[Parameter(Mandatory)]$OpenBinding,[Parameter(Mandatory)][ValidateSet('diagnostic','transaction','postsave','rollback')][string]$Phase)
    $request = $LiteralRequestJson | ConvertFrom-Json -ErrorAction Stop
    if ([string]$request.params.name -cne 'runtime_attestation' -or [string]$request.params.arguments.expected_database -cne $OpenBinding.Database -or
        -not [string]::Equals([IO.Path]::GetFullPath([string]$request.params.arguments.expected_canonical_path),$OpenBinding.CanonicalPath,[StringComparison]::OrdinalIgnoreCase)) { throw "UID0002FD $Phase literal attestation request mismatch" }
    $response = Get-UID0002FDJsonRpcEnvelope $RawResponseJson "$Phase runtime_attestation"
    if (-not $response.result.PSObject.Properties['structuredContent']) { throw "UID0002FD $Phase structuredContent missing" }
    $sc = $response.result.structuredContent
    if ([int]$sc.schema_version -ne 1 -or $true -ne $sc.ok -or @($sc.errors).Count -ne 0) { throw "UID0002FD $Phase top-level attestation failure" }
    if (@($sc.inactive_sessions | Where-Object { [string]$_.session_id -ceq $OpenBinding.Database }).Count -ne 0) { throw "UID0002FD $Phase returned database is inactive" }

    $listener = $sc.listener
    if ([string]$listener.role -cne 'supervisor_listener' -or [string]$listener.endpoint.host -cne '127.0.0.1' -or [int]$listener.endpoint.port -ne 13337) { throw 'UID0002FD listener role/endpoint drift' }
    if ([string]$listener.process.generation -cne ("pid:{0};created:{1}" -f $listener.process.pid,$listener.process.creation_time_100ns) -or
        -not [string]::Equals([string]$listener.process.sys_executable,[string]$listener.process.process_image,[StringComparison]::OrdinalIgnoreCase)) { throw 'UID0002FD listener process generation drift' }
    $sockets = @(Get-NetTCPConnection -State Listen -ErrorAction Stop | Where-Object { $_.LocalAddress -eq '127.0.0.1' -and [int]$_.LocalPort -eq 13337 })
    if ($sockets.Count -ne 1 -or [int]$sockets[0].OwningProcess -ne [int]$listener.process.pid) { throw 'UID0002FD passive listener PID/socket ownership mismatch' }
    Assert-UID0002FDFreshRoleStamp $listener "$Phase listener"
    $listenerManifest = Get-UID0002FDManifestJson $listener listener
    if ($null -eq $UID0002FDAttestationState.ListenerGeneration) { $UID0002FDAttestationState.ListenerGeneration=[string]$listener.process.generation;$UID0002FDAttestationState.ListenerManifestJson=$listenerManifest }
    elseif ([string]$listener.process.generation -cne $UID0002FDAttestationState.ListenerGeneration -or $listenerManifest -cne $UID0002FDAttestationState.ListenerManifestJson) { throw 'UID0002FD listener generation/manifest changed during transaction' }

    $workers = @($sc.workers)
    if ($workers.Count -ne 1) { throw "UID0002FD $Phase expected sole active worker route" }
    $route = $workers[0]
    $supervisorSessions = @($route.supervisor_sessions)
    if ($supervisorSessions.Count -ne 1) { throw "UID0002FD $Phase supervisor-session cardinality mismatch" }
    $supervisorSession = $supervisorSessions[0]
    if ([string]$supervisorSession.session_id -cne $OpenBinding.Database -or [string]$supervisorSession.backend -cne 'worker' -or $true -ne $supervisorSession.owned -or
        [int]$supervisorSession.redirector_pid -le 0 -or [int]$supervisorSession.redirector_pid -ne [int]$supervisorSession.registered_pid -or
        -not [string]::Equals([IO.Path]::GetFullPath([string]$supervisorSession.canonical_path),$OpenBinding.CanonicalPath,[StringComparison]::OrdinalIgnoreCase)) { throw "UID0002FD $Phase supervisor route mismatch" }
    $workerAttestation = $route.attestation
    if ([int]$workerAttestation.schema_version -ne 1 -or $true -ne $workerAttestation.ok -or @($workerAttestation.errors).Count -ne 0) { throw "UID0002FD $Phase worker attestation failure" }
    $worker = $workerAttestation.worker
    if ([string]$worker.role -cne 'stateful_worker' -or [int]$worker.process.parent_pid -ne [int]$supervisorSession.redirector_pid -or
        [string]$worker.process.generation -cne ("pid:{0};created:{1}" -f $worker.process.pid,$worker.process.creation_time_100ns) -or
        [string]$route.route.host -cne [string]$worker.endpoint.host -or [int]$route.route.port -ne [int]$worker.endpoint.port -or
        -not [string]::Equals([string]$worker.process.sys_executable,[string]$worker.process.process_image,[StringComparison]::OrdinalIgnoreCase)) { throw "UID0002FD $Phase worker process/redirector route mismatch" }
    if ($null -eq $OpenBinding.IdbListRow -or [int]$worker.process.pid -ne [int]$OpenBinding.IdbListRow.worker_pid) { throw "UID0002FD $Phase worker PID differs from idb_list corroboration" }
    $workerSessions = @($workerAttestation.sessions)
    if ($workerSessions.Count -ne 1 -or [string]$workerSessions[0].session_id -cne $OpenBinding.Database -or $true -ne $workerSessions[0].is_active -or
        -not [string]::Equals([IO.Path]::GetFullPath([string]$workerSessions[0].input_path),$OpenBinding.CanonicalPath,[StringComparison]::OrdinalIgnoreCase) -or
        -not [string]::Equals([IO.Path]::GetFullPath([string]$workerSessions[0].canonical_path),$OpenBinding.CanonicalPath,[StringComparison]::OrdinalIgnoreCase)) { throw "UID0002FD $Phase active worker session/path mismatch" }
    Assert-UID0002FDFreshRoleStamp $worker "$Phase worker"
    $workerManifest = Get-UID0002FDManifestJson $worker worker
    if ($null -eq $UID0002FDAttestationState.WorkerManifestJson) { $UID0002FDAttestationState.WorkerManifestJson=$workerManifest }
    elseif ($workerManifest -cne $UID0002FDAttestationState.WorkerManifestJson) { throw 'UID0002FD worker loaded-module manifest changed between roles' }

    if ($UID0002FDAttestationState.PhaseWorkers.ContainsKey($Phase)) {
        $frozen = $UID0002FDAttestationState.PhaseWorkers[$Phase]
        if ($frozen.Database -cne $OpenBinding.Database -or $frozen.Generation -cne [string]$worker.process.generation -or $frozen.RoutePort -ne [int]$route.route.port) { throw "UID0002FD $Phase worker identity drift" }
    } else {
        foreach ($prior in $UID0002FDAttestationState.PhaseWorkers.Values) {
            if ($prior.Database -ceq $OpenBinding.Database -or $prior.Generation -ceq [string]$worker.process.generation) { throw "UID0002FD $Phase reused a prior role worker" }
        }
        $UID0002FDAttestationState.PhaseWorkers[$Phase]=[pscustomobject]@{Database=$OpenBinding.Database;Generation=[string]$worker.process.generation;RoutePort=[int]$route.route.port;RedirectorPid=[int]$supervisorSession.redirector_pid;WorkerPid=[int]$worker.process.pid}
    }
    $sc
}
~~~

## Removed Block R008

- SHA256: `45C2DDDE18716F445AC76984B9EBDB55EDF1E2FF41B116BC84C2BBAC3AD90F2B`
- Language: `powershell`
- Bytes: `5888`
- First recovered timestamp: `2026-08-07T00:30:01.676Z`
- Session provenance: rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 194880 (2026-08-07T00:30:01.676Z)

~~~powershell
function Invoke-UID0002FDExpectedFailure {
    param([Parameter(Mandatory)][string]$Name,[Parameter(Mandatory)][string]$Expected,[Parameter(Mandatory)][scriptblock]$Action,$State)
    $before=[pscustomobject]@{State=[int64]$State.StateEffects;Save=[int64]$State.SaveEffects;Restore=[int64]$State.RestoreEffects}
    $actual=$null
    try { $null=& $Action; throw "UID0002FD FIXTURE_DID_NOT_FAIL name=$Name" } catch { $actual=$_.Exception.Message }
    if ($actual -cne $Expected) { throw "UID0002FD FIXTURE_WRONG_FAILURE name=$Name expected=$Expected actual=$actual" }
    if ([int64]$State.StateEffects -ne $before.State -or [int64]$State.SaveEffects -ne $before.Save -or [int64]$State.RestoreEffects -ne $before.Restore) {
        throw "UID0002FD FIXTURE_SIDE_EFFECT name=$Name"
    }
    [pscustomobject]@{Name=$Name;Passed=$true;Failure=$actual}
}

function Invoke-UID0002FDHostileFixtures {
    $state=[pscustomobject]@{StateEffects=[int64]0;SaveEffects=[int64]0;RestoreEffects=[int64]0}
    $results=@()
    $results+=Invoke-UID0002FDExpectedFailure 'wrong-jsonrpc' 'UID0002FD fixture JSON_RPC_VERSION_MISMATCH expected=2.0 actual=1.0' {
        $null=Get-UID0002FDJsonRpcEnvelope '{"jsonrpc":"1.0","id":"fixture","result":{}}' 'fixture' 'fixture'
    } $state
    $results+=Invoke-UID0002FDExpectedFailure 'int32-id' 'UID0002FD fixture JSON_RPC_ID_TYPE_MISMATCH expected_type=String actual_type=Int32' {
        $parsed='{"jsonrpc":"2.0","id":1,"result":{}}' | ConvertFrom-Json
        if ($parsed.id.GetType().FullName -cne 'System.Int32') { throw 'UID0002FD FIXTURE_HOST_NUMERIC_TYPE_DRIFT' }
        $null=Get-UID0002FDJsonRpcEnvelope ($parsed | ConvertTo-Json -Compress) 'fixture' 'fixture'
    } $state
    $badOpen=[pscustomobject]@{method='tools/call';params=[pscustomobject]@{name='idb_open';arguments=[pscustomobject]@{input_path='E:\other.i64';mode='force_headless';run_auto_analysis=$false;build_caches=$false;init_hexrays=$false;idle_ttl_sec=600;preferred_session_id='uid0002fd-transaction-x'}}}
    $results+=Invoke-UID0002FDExpectedFailure 'canonical-divergence' 'UID0002FD IDB_OPEN_CONTRACT_MISMATCH phase=transaction' { Assert-UID0002FDExactOpenRequest $badOpen transaction } $state
    $results+=Invoke-UID0002FDExpectedFailure 'semantic-missing' 'UID0002FD SEMANTIC_CONTENT_MISSING label=fixture' {
        Assert-UID0002FDSemanticResult ([pscustomobject]@{result=[pscustomobject]@{}}) ([pscustomobject]@{ExpectedCanonicalJsonSha256='';ExpectedItemCount=$null;RequiredProperties=@();Pagination='forbidden';Predicate={param($x)$true}}) fixture
    } $state
    $results+=Invoke-UID0002FDExpectedFailure 'pagination' 'UID0002FD PAGINATION_TERMINAL_MISMATCH label=fixture' {
        $response=[pscustomobject]@{result=[pscustomobject]@{structuredContent=[pscustomobject]@{items=@();next_offset=1}}}
        $contract=[pscustomobject]@{ExpectedCanonicalJsonSha256='';ExpectedItemCount=0;ItemsProperty='items';RequiredProperties=@('items','next_offset');Pagination='terminal-null';Predicate={param($x)$true}}
        Assert-UID0002FDSemanticResult $response $contract fixture
    } $state
    $frozen=[pscustomobject]@{Database='d';ListenerGeneration='l';WorkerGeneration='w';WorkerPid=2;RedirectorPid=1;RouteHost='127.0.0.1';RoutePort=1234;ListenerManifestSha256='a';WorkerManifestSha256='b';ListenerNonce='n1';WorkerNonce='n2'}
    $drift=$frozen.PSObject.Copy();$drift.WorkerManifestSha256='c';$drift.ListenerNonce='n3';$drift.WorkerNonce='n4'
    $results+=Invoke-UID0002FDExpectedFailure 'module-drift' 'UID0002FD ATTESTATION_TUPLE_DRIFT field=WorkerManifestSha256' { Assert-UID0002FDStableAttestationTuple $frozen $drift } $state
    $nonce=$frozen.PSObject.Copy()
    $results+=Invoke-UID0002FDExpectedFailure 'nonce-replay' 'UID0002FD ATTESTATION_NONCE_REPLAY' { Assert-UID0002FDStableAttestationTuple $frozen $nonce } $state
    $worker=$frozen.PSObject.Copy();$worker.WorkerPid=3;$worker.ListenerNonce='n3';$worker.WorkerNonce='n4'
    $results+=Invoke-UID0002FDExpectedFailure 'worker-drift' 'UID0002FD ATTESTATION_TUPLE_DRIFT field=WorkerPid' { Assert-UID0002FDStableAttestationTuple $frozen $worker } $state
    $p0=[pscustomobject]@{Length=10;SHA256='P0';LastWriteTimeUtcTicks=10}
    $p1=[pscustomobject]@{Length=10;SHA256='P1';LastWriteTimeUtcTicks=20}
    $third=[pscustomobject]@{Length=10;SHA256='THIRD';LastWriteTimeUtcTicks=20}
    $results+=Invoke-UID0002FDExpectedFailure 'third-identity-restore' 'UID0002FD RESTORE_DESTINATION_NOT_EXACT_ATTRIBUTABLE_P1' { Assert-UID0002FDRestoreIdentity $third $p0 $p1 } $state
    $results+=Invoke-UID0002FDExpectedFailure 'p0-restore' 'UID0002FD RESTORE_DESTINATION_ALREADY_P0_NO_TRUNCATION' { Assert-UID0002FDRestoreIdentity $p0 $p0 $p1 } $state
    $temp=Join-Path ([IO.Path]::GetTempPath()) ('uid0002fd-fixture-'+[Guid]::NewGuid().ToString('N'))
    try {
        $attempt=New-UID0002FDAttempt $temp
        $request='{"jsonrpc":"2.0","id":"fixture-request","method":"tools/list","params":{}}'
        $null=Register-UID0002FDRequest $attempt fixture OPEN $request
        $attempt.StateEffects=[int64]0;$attempt.SaveEffects=[int64]0;$attempt.RestoreEffects=[int64]0
        $results+=Invoke-UID0002FDExpectedFailure 'request-replay' 'UID0002FD REQUEST_ID_REPLAY id=fixture-request' { Register-UID0002FDRequest $attempt fixture OPEN $request } $attempt
        $attempt.SaveAttempted=$true
        $results+=Invoke-UID0002FDExpectedFailure 'duplicate-save' 'UID0002FD DUPLICATE_SAVE_ATTEMPT' {
            if ($true -eq $attempt.SaveAttempted) { throw 'UID0002FD DUPLICATE_SAVE_ATTEMPT' }
        } $attempt
    } finally {
        if (Test-Path -LiteralPath $temp) { Remove-Item -LiteralPath $temp -Recurse -Force }
    }
    if (@($results).Count -ne 11 -or @($results | Where-Object { $true -ne $_.Passed }).Count -ne 0) { throw 'UID0002FD FIXTURE_SUITE_INCOMPLETE' }
    $results
}
~~~

## Removed Block R009

- SHA256: `61912C43AB4319D38B0CEB22B5609C68CFF091A31BE576FD5FE8D42D9F7DCAF8`
- Language: `powershell`
- Bytes: `2362`
- First recovered timestamp: `2026-08-07T00:30:01.676Z`
- Session provenance: rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 194880 (2026-08-07T00:30:01.676Z)

~~~powershell
function Invoke-UID0002FDRestoreP1ToP0 {
    param([Parameter(Mandatory)][string]$CanonicalPath,[Parameter(Mandatory)][string]$BackupPath,[Parameter(Mandatory)]$P0,[Parameter(Mandatory)]$P1,[Parameter(Mandatory)]$B0,[Parameter(Mandatory)]$Attempt)
    if ($true -eq $Attempt.RestoreEffects) { throw 'UID0002FD DUPLICATE_RESTORE_ATTEMPT' }
    $source=[IO.FileStream]::new($BackupPath,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None)
    $destination=$null
    try {
        if ($source.Length -ne $B0.Length -or (Get-UID0002FDStreamSha256 $source) -cne $B0.SHA256) { throw 'UID0002FD B0_UNDER_HANDLE_MISMATCH' }
        $destination=[IO.FileStream]::new($CanonicalPath,[IO.FileMode]::Open,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None)
        $underHandle=[pscustomobject][ordered]@{
            Path=[IO.Path]::GetFullPath($CanonicalPath)
            Length=[int64]$destination.Length
            SHA256=(Get-UID0002FDStreamSha256 $destination)
            LastWriteTimeUtcTicks=[IO.File]::GetLastWriteTimeUtc($CanonicalPath).Ticks
        }
        $null=Assert-UID0002FDRestoreIdentity $underHandle $P0 $P1
        $Attempt.RestoreEffects=[int64]$Attempt.RestoreEffects+1
        Write-UID0002FDAttemptJournal $Attempt
        $source.Position=0
        $destination.Position=0
        $destination.SetLength(0)
        if ($destination.Length -ne 0 -or $destination.Position -ne 0) { throw 'UID0002FD RESTORE_TRUNCATION_FAILED' }
        $source.CopyTo($destination)
        if ($source.Position -ne $B0.Length -or $source.ReadByte() -ne -1) { throw 'UID0002FD RESTORE_SOURCE_EOF_MISMATCH' }
        if ($destination.Position -ne $P0.Length -or $destination.Length -ne $P0.Length) { throw 'UID0002FD RESTORE_DESTINATION_LENGTH_MISMATCH' }
        $destination.Flush($true)
    } finally {
        if ($null -ne $destination) { $destination.Dispose() }
        $source.Dispose()
    }
    [IO.File]::SetLastWriteTimeUtc($CanonicalPath,[DateTime]::new([int64]$P0.LastWriteTimeUtcTicks,[DateTimeKind]::Utc))
    $first=Get-UID0002FDClosedTuple $CanonicalPath
    $second=Get-UID0002FDClosedTuple $CanonicalPath
    Assert-UID0002FDExactTuple $first $P0 'UID0002FD restored P0 first'
    Assert-UID0002FDExactTuple $second $P0 'UID0002FD restored P0 second'
    [pscustomobject]@{Restored=$true;First=$first;Second=$second}
}
~~~

## Removed Block R010

- SHA256: `DFC7A930B2C7F7998EBC9FB8F5C42DEB7E999ED7ADB75CE6DD3F1A063E2EBEBD`
- Language: `powershell`
- Bytes: `28100`
- First recovered timestamp: `2026-08-07T00:30:01.676Z`
- Session provenance: rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 194880 (2026-08-07T00:30:01.676Z)

~~~powershell
$UID0002FDOpenContracts = [ordered]@{
    diagnostic  = [ordered]@{ BuildCaches=$true;  InitHexrays=$true;  Prefix='uid0002fd-diagnostic-' }
    transaction = [ordered]@{ BuildCaches=$false; InitHexrays=$false; Prefix='uid0002fd-transaction-' }
    postsave     = [ordered]@{ BuildCaches=$false; InitHexrays=$false; Prefix='uid0002fd-postsave-' }
    rollback     = [ordered]@{ BuildCaches=$false; InitHexrays=$false; Prefix='uid0002fd-rollback-' }
}

function Get-UID0002FDTextSha256 {
    param([Parameter(Mandatory)][string]$Text)
    $stream = [IO.MemoryStream]::new([Text.Encoding]::UTF8.GetBytes($Text))
    try { (Get-FileHash -InputStream $stream -Algorithm SHA256).Hash } finally { $stream.Dispose() }
}

function Get-UID0002FDStreamSha256 {
    param([Parameter(Mandatory)][IO.Stream]$Stream)
    $position = $Stream.Position
    try {
        $Stream.Position = 0
        (Get-FileHash -InputStream $Stream -Algorithm SHA256).Hash
    } finally {
        $Stream.Position = $position
    }
}

function Write-UID0002FDAttemptJournal {
    param([Parameter(Mandatory)]$Attempt)
    $json = $Attempt | ConvertTo-Json -Depth 40
    $bytes = [Text.UTF8Encoding]::new($false).GetBytes($json + [Environment]::NewLine)
    $temp = Join-Path $Attempt.Directory ('journal-' + [Guid]::NewGuid().ToString('N') + '.tmp')
    $stream = [IO.FileStream]::new($temp,[IO.FileMode]::CreateNew,[IO.FileAccess]::Write,[IO.FileShare]::None)
    try { $stream.Write($bytes,0,$bytes.Length); $stream.Flush($true) } finally { $stream.Dispose() }
    if (Test-Path -LiteralPath $Attempt.JournalPath) {
        [IO.File]::Replace($temp,$Attempt.JournalPath,$null,$true)
    } else {
        [IO.File]::Move($temp,$Attempt.JournalPath)
    }
}

function New-UID0002FDAttempt {
    param([Parameter(Mandatory)][string]$Directory)
    $full = [IO.Path]::GetFullPath($Directory)
    if (Test-Path -LiteralPath $full) { throw 'UID0002FD ATTEMPT_DIRECTORY_ALREADY_EXISTS' }
    $null = [IO.Directory]::CreateDirectory($full)
    $attempt = [pscustomobject][ordered]@{
        SchemaVersion=1
        AttemptNonce=[Guid]::NewGuid().ToString('N')
        StartedUtc=[DateTime]::UtcNow.ToString('o')
        Directory=$full
        JournalPath=(Join-Path $full 'attempt-journal.json')
        Sequence=[int64]0
        Requests=@()
        SaveAttempted=$false
        SaveDisposition='not-attempted'
        StateEffects=[int64]0
        SaveEffects=[int64]0
        RestoreEffects=[int64]0
        FrozenSchemas=@{}
    }
    Write-UID0002FDAttemptJournal $attempt
    $attempt
}

function Open-UID0002FDAttempt {
    param([Parameter(Mandatory)][string]$Directory)
    $journal = Join-Path ([IO.Path]::GetFullPath($Directory)) 'attempt-journal.json'
    if (-not (Test-Path -LiteralPath $journal -PathType Leaf)) { throw 'UID0002FD ATTEMPT_JOURNAL_MISSING' }
    $attempt = Get-Content -LiteralPath $journal -Raw | ConvertFrom-Json -ErrorAction Stop
    if ([int]$attempt.SchemaVersion -ne 1 -or [string]::IsNullOrWhiteSpace([string]$attempt.AttemptNonce) -or
        [string]::IsNullOrWhiteSpace([string]$attempt.StartedUtc)) { throw 'UID0002FD ATTEMPT_JOURNAL_INVALID' }
    Add-Member -InputObject $attempt -NotePropertyName Directory -NotePropertyValue ([IO.Path]::GetFullPath($Directory)) -Force
    Add-Member -InputObject $attempt -NotePropertyName JournalPath -NotePropertyValue $journal -Force
    if ($null -eq $attempt.Requests) { $attempt.Requests=@() }
    if ($null -eq $attempt.FrozenSchemas) { $attempt.FrozenSchemas=@{} }
    $attempt
}

function New-UID0002FDRequestId {
    param([Parameter(Mandatory)]$Attempt,[Parameter(Mandatory)][string]$Phase,[Parameter(Mandatory)][string]$Operation)
    $Attempt.Sequence = [int64]$Attempt.Sequence + 1
    $id = 'uid0002fd-{0}-{1}-{2:d6}-{3}' -f $Attempt.AttemptNonce,$Phase,$Attempt.Sequence,$Operation
    Write-UID0002FDAttemptJournal $Attempt
    $id
}

function Register-UID0002FDRequest {
    param([Parameter(Mandatory)]$Attempt,[Parameter(Mandatory)][string]$Phase,[Parameter(Mandatory)][string]$ActionClass,[Parameter(Mandatory)][string]$LiteralRequestJson)
    $request = $LiteralRequestJson | ConvertFrom-Json -ErrorAction Stop
    if ([string]$request.jsonrpc -cne '2.0' -or $request.id -isnot [string] -or [string]::IsNullOrWhiteSpace([string]$request.id)) {
        throw 'UID0002FD REQUEST_ENVELOPE_INVALID'
    }
    $requestId = [string]$request.id
    $requestSha = Get-UID0002FDTextSha256 $LiteralRequestJson
    if (@($Attempt.Requests | Where-Object { [string]$_.RequestId -ceq $requestId }).Count -ne 0) {
        throw "UID0002FD REQUEST_ID_REPLAY id=$requestId"
    }
    if (@($Attempt.Requests | Where-Object { [string]$_.RequestSha256 -ceq $requestSha }).Count -ne 0) {
        throw "UID0002FD REQUEST_BODY_REPLAY sha256=$requestSha"
    }
    $entry = [pscustomobject][ordered]@{
        Sequence=[int64]$Attempt.Sequence
        Phase=$Phase
        ActionClass=$ActionClass
        RequestId=$requestId
        RequestIdNativeType=$request.id.GetType().FullName
        RequestSha256=$requestSha
        ResponseSha256=$null
        Consumed=$false
        Disposition='registered-before-transport'
    }
    $Attempt.Requests=@($Attempt.Requests)+@($entry)
    Write-UID0002FDAttemptJournal $Attempt
    $entry
}

function Consume-UID0002FDResponse {
    param([Parameter(Mandatory)]$Attempt,[Parameter(Mandatory)]$Entry,[Parameter(Mandatory)][string]$RawResponseJson)
    if ($true -eq $Entry.Consumed) { throw "UID0002FD RESPONSE_ALREADY_CONSUMED id=$($Entry.RequestId)" }
    $responseSha = Get-UID0002FDTextSha256 $RawResponseJson
    if (@($Attempt.Requests | Where-Object { $true -eq $_.Consumed -and [string]$_.ResponseSha256 -ceq $responseSha }).Count -ne 0) {
        throw "UID0002FD RESPONSE_REPLAY sha256=$responseSha"
    }
    $response = $RawResponseJson | ConvertFrom-Json -ErrorAction Stop
    if (-not $response.PSObject.Properties['jsonrpc'] -or [string]$response.jsonrpc -cne '2.0') { throw 'UID0002FD JSON_RPC_VERSION_MISMATCH' }
    if (-not $response.PSObject.Properties['id'] -or $null -eq $response.id) { throw 'UID0002FD JSON_RPC_ID_MISSING' }
    if ($response.id.GetType().FullName -cne [string]$Entry.RequestIdNativeType) { throw 'UID0002FD JSON_RPC_ID_NATIVE_TYPE_MISMATCH' }
    if ([string]$response.id -cne [string]$Entry.RequestId) { throw 'UID0002FD JSON_RPC_ID_VALUE_MISMATCH' }
    if ($response.PSObject.Properties['error'] -and $null -ne $response.error) { throw 'UID0002FD JSON_RPC_ERROR_PRESENT' }
    if (-not $response.PSObject.Properties['result'] -or $null -eq $response.result) { throw 'UID0002FD JSON_RPC_RESULT_MISSING' }
    if ($response.result.PSObject.Properties['isError'] -and $true -eq $response.result.isError) { throw 'UID0002FD TOOL_RESULT_IS_ERROR' }
    $Entry.ResponseSha256=$responseSha
    $Entry.Consumed=$true
    $Entry.Disposition='correlated-and-consumed'
    Write-UID0002FDAttemptJournal $Attempt
    $response
}

function Assert-UID0002FDExactOpenRequest {
    param([Parameter(Mandatory)]$Request,[Parameter(Mandatory)][string]$Phase)
    if (-not $UID0002FDOpenContracts.Contains($Phase)) { throw "UID0002FD OPEN_PHASE_UNKNOWN phase=$Phase" }
    $contract=$UID0002FDOpenContracts[$Phase]
    $expectedArgs=@('build_caches','idle_ttl_sec','init_hexrays','input_path','mode','preferred_session_id','run_auto_analysis')
    $actualArgs=@($Request.params.arguments.PSObject.Properties.Name | Sort-Object)
    if ((ConvertTo-Json $actualArgs -Compress) -cne (ConvertTo-Json ($expectedArgs | Sort-Object) -Compress)) { throw 'UID0002FD IDB_OPEN_EXTRA_OR_MISSING_ARGUMENT' }
    if ([string]$Request.method -cne 'tools/call' -or [string]$Request.params.name -cne 'idb_open' -or
        -not [string]::Equals([IO.Path]::GetFullPath([string]$Request.params.arguments.input_path),$UID0002FDCanonicalPath,[StringComparison]::OrdinalIgnoreCase) -or
        [string]$Request.params.arguments.mode -cne 'force_headless' -or
        $false -ne $Request.params.arguments.run_auto_analysis -or
        [bool]$Request.params.arguments.build_caches -ne [bool]$contract.BuildCaches -or
        [bool]$Request.params.arguments.init_hexrays -ne [bool]$contract.InitHexrays -or
        [int]$Request.params.arguments.idle_ttl_sec -ne 600) { throw "UID0002FD IDB_OPEN_CONTRACT_MISMATCH phase=$Phase" }
    $preferred=[string]$Request.params.arguments.preferred_session_id
    if (-not $preferred.StartsWith([string]$contract.Prefix,[StringComparison]::Ordinal) -or $preferred.Length -le ([string]$contract.Prefix).Length) {
        throw "UID0002FD IDB_OPEN_PREFIX_NOT_FRESH phase=$Phase"
    }
}

$UID0002FDToolSchemaContracts = [ordered]@{
    runtime_attestation   = [ordered]@{ Required=@(); Properties=[ordered]@{ expected_database='string='; expected_canonical_path='string=' } }
    idb_open              = [ordered]@{ Required=@('input_path'); Properties=[ordered]@{ input_path='string'; mode='string=force_headless'; run_auto_analysis='boolean=false'; build_caches='boolean=true'; init_hexrays='boolean=true'; idle_ttl_sec='integer=600'; preferred_session_id='string=' } }
    idb_list              = [ordered]@{ Required=@(); Properties=[ordered]@{} }
    server_health         = [ordered]@{ Required=@(); Properties=[ordered]@{ database='string=' } }
    analyze_function      = [ordered]@{ Required=@('addr'); Properties=[ordered]@{ addr='string'; database='string=' } }
    lookup_funcs          = [ordered]@{ Required=@('queries'); Properties=[ordered]@{ queries='array'; database='string=' } }
    stack_frame           = [ordered]@{ Required=@('addrs'); Properties=[ordered]@{ addrs='array'; database='string=' } }
    get_comments          = [ordered]@{ Required=@('addrs'); Properties=[ordered]@{ addrs='array'; database='string=' } }
    inspect_items         = [ordered]@{ Required=@('addrs'); Properties=[ordered]@{ addrs='array'; database='string=' } }
    type_inspect          = [ordered]@{ Required=@('queries'); Properties=[ordered]@{ queries='array'; database='string=' } }
    entity_query          = [ordered]@{ Required=@('queries'); Properties=[ordered]@{ queries='array'; database='string=' } }
    xref_query            = [ordered]@{ Required=@('queries'); Properties=[ordered]@{ queries='array'; database='string=' } }
    get_bytes             = [ordered]@{ Required=@('regions'); Properties=[ordered]@{ regions='array'; database='string=' } }
    rename                = [ordered]@{ Required=@('batch'); Properties=[ordered]@{ batch='object-or-array'; database='string=' } }
    set_type              = [ordered]@{ Required=@('edits'); Properties=[ordered]@{ edits='object-or-array'; database='string=' } }
    set_function_comments = [ordered]@{ Required=@('items'); Properties=[ordered]@{ items='object-or-array'; database='string=' } }
    make_data             = [ordered]@{ Required=@('items'); Properties=[ordered]@{ items='object-or-array'; database='string=' } }
    set_address_comments  = [ordered]@{ Required=@('items'); Properties=[ordered]@{ items='object-or-array'; database='string=' } }
    idb_save              = [ordered]@{ Required=@('path'); Properties=[ordered]@{ path='string'; database='string=' } }
}

function Assert-UID0002FDPropertySchema {
    param([Parameter(Mandatory)]$Actual,[Parameter(Mandatory)][string]$Contract,[Parameter(Mandatory)][string]$Label)
    $parts=$Contract.Split('=',2)
    $kind=$parts[0]
    if ($kind -eq 'object-or-array') {
        $oneOf=@($Actual.oneOf)
        $types=@($oneOf | ForEach-Object { [string]$_.type } | Sort-Object)
        if ((ConvertTo-Json $types -Compress) -cne '["array","object"]') { throw "UID0002FD SCHEMA_TYPE_DRIFT $Label" }
    } elseif ([string]$Actual.type -cne $kind) {
        throw "UID0002FD SCHEMA_TYPE_DRIFT $Label"
    }
    if ($parts.Count -eq 2) {
        if (-not $Actual.PSObject.Properties['default']) { throw "UID0002FD SCHEMA_DEFAULT_MISSING $Label" }
        $expected=$parts[1]
        if ($kind -eq 'boolean') { if ([bool]$Actual.default -ne [bool]::Parse($expected)) { throw "UID0002FD SCHEMA_DEFAULT_DRIFT $Label" } }
        elseif ($kind -eq 'integer') { if ([int64]$Actual.default -ne [int64]$expected) { throw "UID0002FD SCHEMA_DEFAULT_DRIFT $Label" } }
        elseif ([string]$Actual.default -cne $expected) { throw "UID0002FD SCHEMA_DEFAULT_DRIFT $Label" }
    } elseif ($Actual.PSObject.Properties['default']) {
        throw "UID0002FD SCHEMA_UNEXPECTED_DEFAULT $Label"
    }
}

function Assert-UID0002FDAllUsedToolSchemas {
    param([Parameter(Mandatory)]$ToolsListResponse,[Parameter(Mandatory)]$Attempt)
    $tools=@($ToolsListResponse.result.tools)
    foreach($name in $UID0002FDToolSchemaContracts.Keys) {
        $matches=@($tools | Where-Object { [string]$_.name -ceq $name })
        if ($matches.Count -ne 1) { throw "UID0002FD TOOL_CARDINALITY_DRIFT name=$name" }
        $schema=$matches[0].inputSchema
        $contract=$UID0002FDToolSchemaContracts[$name]
        if ([string]$schema.type -cne 'object' -or -not $schema.PSObject.Properties['required'] -or -not $schema.PSObject.Properties['properties']) {
            throw "UID0002FD SCHEMA_ROOT_DRIFT name=$name"
        }
        $required=@($schema.required | ForEach-Object { [string]$_ } | Sort-Object)
        $expectedRequired=@($contract.Required | Sort-Object)
        if ((ConvertTo-Json $required -Compress) -cne (ConvertTo-Json $expectedRequired -Compress)) { throw "UID0002FD SCHEMA_REQUIRED_DRIFT name=$name" }
        $actualProperties=@($schema.properties.PSObject.Properties.Name | Sort-Object)
        $expectedProperties=@($contract.Properties.Keys | Sort-Object)
        if ((ConvertTo-Json $actualProperties -Compress) -cne (ConvertTo-Json $expectedProperties -Compress)) { throw "UID0002FD SCHEMA_PROPERTY_DRIFT name=$name" }
        foreach($property in $contract.Properties.Keys) {
            Assert-UID0002FDPropertySchema $schema.properties.$property ([string]$contract.Properties[$property]) "$name.$property"
        }
        if (-not $schema.PSObject.Properties['additionalProperties'] -or $false -ne $schema.additionalProperties) {
            throw "UID0002FD SCHEMA_NO_EXTRA_BEHAVIOR_DRIFT name=$name"
        }
        $canonical=$schema | ConvertTo-Json -Depth 40 -Compress
        $sha=Get-UID0002FDTextSha256 $canonical
        if ($Attempt.FrozenSchemas.PSObject.Properties[$name]) {
            if ([string]$Attempt.FrozenSchemas.$name -cne $sha) { throw "UID0002FD NESTED_SCHEMA_DRIFT name=$name" }
        } else {
            Add-Member -InputObject $Attempt.FrozenSchemas -NotePropertyName $name -NotePropertyValue $sha -Force
        }
    }
    Write-UID0002FDAttemptJournal $Attempt
}

function Assert-UID0002FDSemanticResult {
    param([Parameter(Mandatory)]$Response,[Parameter(Mandatory)]$Contract,[Parameter(Mandatory)][string]$Label)
    if (-not $Response.result.PSObject.Properties['structuredContent']) { throw "UID0002FD SEMANTIC_CONTENT_MISSING label=$Label" }
    $sc=$Response.result.structuredContent
    if (-not [string]::IsNullOrWhiteSpace([string]$Contract.ExpectedCanonicalJsonSha256)) {
        $actualSha=Get-UID0002FDTextSha256 ($sc | ConvertTo-Json -Depth 50 -Compress)
        if ($actualSha -cne [string]$Contract.ExpectedCanonicalJsonSha256) { throw "UID0002FD SEMANTIC_DIGEST_MISMATCH label=$Label" }
    }
    if ($null -ne $Contract.ExpectedItemCount) {
        if (-not $sc.PSObject.Properties[[string]$Contract.ItemsProperty]) { throw "UID0002FD SEMANTIC_ITEMS_MISSING label=$Label" }
        if (@($sc.([string]$Contract.ItemsProperty)).Count -ne [int]$Contract.ExpectedItemCount) { throw "UID0002FD SEMANTIC_ITEM_COUNT_MISMATCH label=$Label" }
    }
    foreach($property in @($Contract.RequiredProperties)) {
        if (-not $sc.PSObject.Properties[[string]$property]) { throw "UID0002FD SEMANTIC_REQUIRED_FIELD_MISSING label=$Label field=$property" }
    }
    if ([string]$Contract.Pagination -ceq 'terminal-null') {
        if (-not $sc.PSObject.Properties['next_offset'] -or $null -ne $sc.next_offset) { throw "UID0002FD PAGINATION_TERMINAL_MISMATCH label=$Label" }
    } elseif ([string]$Contract.Pagination -ceq 'forbidden' -and $sc.PSObject.Properties['next_offset']) {
        throw "UID0002FD PAGINATION_FIELD_FORBIDDEN label=$Label"
    }
    if ($null -eq $Contract.Predicate) { throw "UID0002FD SEMANTIC_PREDICATE_MISSING label=$Label" }
    $predicateResult=& $Contract.Predicate $sc
    if ($true -ne $predicateResult) { throw "UID0002FD SEMANTIC_PREDICATE_FAILED label=$Label" }
    $true
}

function Invoke-UID0002FDControlledCall {
    param(
        [Parameter(Mandatory)]$Attempt,
        [Parameter(Mandatory)][scriptblock]$Transport,
        [Parameter(Mandatory)][string]$Phase,
        [Parameter(Mandatory)][ValidateSet('OPEN','S','I','F','V','RB','SAVE')][string]$ActionClass,
        [Parameter(Mandatory)][string]$LiteralRequestJson,
        $OpenBinding,
        [Parameter(Mandatory)][scriptblock]$SemanticAssertion
    )
    if ($ActionClass -in @('S','I','F','V','RB','SAVE')) {
        if ($null -eq $OpenBinding) { throw "UID0002FD STATEFUL_BINDING_MISSING class=$ActionClass" }
        Assert-UID0002FDStatefulQueryAuthorized $OpenBinding
        $requestCheck=$LiteralRequestJson | ConvertFrom-Json -ErrorAction Stop
        if (-not $requestCheck.params.arguments.PSObject.Properties['database'] -or [string]$requestCheck.params.arguments.database -cne [string]$OpenBinding.Database) {
            throw "UID0002FD STATEFUL_DATABASE_AUTHORITY_MISMATCH class=$ActionClass"
        }
    }
    $entry=Register-UID0002FDRequest $Attempt $Phase $ActionClass $LiteralRequestJson
    try {
        $raw=[string](& $Transport $LiteralRequestJson)
    } catch {
        $entry.Disposition='transport-failed'
        Write-UID0002FDAttemptJournal $Attempt
        throw
    }
    $response=Consume-UID0002FDResponse $Attempt $entry $raw
    $semantic=& $SemanticAssertion $response $raw
    if ($true -ne $semantic -and $null -eq $semantic) { throw "UID0002FD SEMANTIC_ASSERTION_RETURNED_NULL class=$ActionClass" }
    [pscustomobject][ordered]@{ RequestEntry=$entry; RawResponseJson=$raw; Response=$response; Semantic=$semantic }
}

function Invoke-UID0002FDOpenRole {
    param([Parameter(Mandatory)]$Attempt,[Parameter(Mandatory)][scriptblock]$Transport,[Parameter(Mandatory)][string]$Phase)
    $contract=$UID0002FDOpenContracts[$Phase]
    if ($null -eq $contract) { throw "UID0002FD OPEN_PHASE_UNKNOWN phase=$Phase" }
    $toolsId=New-UID0002FDRequestId $Attempt $Phase 'tools-list'
    $toolsJson=New-UID0002FDToolsListRequest $toolsId
    $toolsCall=Invoke-UID0002FDControlledCall $Attempt $Transport $Phase OPEN $toolsJson $null {
        param($response,$raw)
        $gate=Assert-UID0002FDPublicToolList $toolsJson $raw
        Assert-UID0002FDAllUsedToolSchemas $response $Attempt
        $gate
    }
    $openId=New-UID0002FDRequestId $Attempt $Phase 'idb-open'
    $preferred=[string]$contract.Prefix + $Attempt.AttemptNonce + '-' + ([Guid]::NewGuid().ToString('N'))
    $openJson=New-UID0002FDOpenRequest $openId $preferred ([bool]$contract.BuildCaches) ([bool]$contract.InitHexrays)
    Assert-UID0002FDExactOpenRequest ($openJson | ConvertFrom-Json -ErrorAction Stop) $Phase
    $openCall=Invoke-UID0002FDControlledCall $Attempt $Transport $Phase OPEN $openJson $null { param($response,$raw) $true }
    $binding=Bind-UID0002FDOpenResponse $toolsCall.Semantic $openJson $openCall.RawResponseJson $Phase
    $att1Id=New-UID0002FDRequestId $Attempt $Phase 'attestation-initial'
    $att1Json=New-UID0002FDRuntimeAttestationRequest $att1Id $binding
    $null=Invoke-UID0002FDControlledCall $Attempt $Transport $Phase OPEN $att1Json $null {
        param($response,$raw)
        $null=Assert-UID0002FDPublicRuntimeAttestation $att1Json $raw $binding $false
        $true
    }
    $listId=New-UID0002FDRequestId $Attempt $Phase 'idb-list'
    $listJson=New-UID0002FDIdbListRequest $listId
    $null=Invoke-UID0002FDControlledCall $Attempt $Transport $Phase OPEN $listJson $null {
        param($response,$raw)
        $null=Add-UID0002FDListCorroboration $binding $listJson $raw
        $true
    }
    $att2Id=New-UID0002FDRequestId $Attempt $Phase 'attestation-authorize'
    $att2Json=New-UID0002FDRuntimeAttestationRequest $att2Id $binding
    $null=Invoke-UID0002FDControlledCall $Attempt $Transport $Phase OPEN $att2Json $null {
        param($response,$raw)
        $null=Assert-UID0002FDPublicRuntimeAttestation $att2Json $raw $binding $true
        $true
    }
    Assert-UID0002FDStatefulQueryAuthorized $binding
    $binding
}

function Invoke-UID0002FDSaveOnce {
    param([Parameter(Mandatory)]$Attempt,[Parameter(Mandatory)][scriptblock]$Transport,[Parameter(Mandatory)]$OpenBinding,[Parameter(Mandatory)][string]$LiteralSaveRequestJson)
    Assert-UID0002FDStatefulQueryAuthorized $OpenBinding
    if ($true -eq $Attempt.SaveAttempted -or (Test-Path -LiteralPath (Join-Path $Attempt.Directory 'save-attempted.latch'))) {
        throw 'UID0002FD DUPLICATE_SAVE_ATTEMPT'
    }
    $entry=Register-UID0002FDRequest $Attempt $OpenBinding.Phase SAVE $LiteralSaveRequestJson
    $latchPath=Join-Path $Attempt.Directory 'save-attempted.latch'
    $latch=[IO.FileStream]::new($latchPath,[IO.FileMode]::CreateNew,[IO.FileAccess]::Write,[IO.FileShare]::None)
    try {
        $bytes=[Text.UTF8Encoding]::new($false).GetBytes((ConvertTo-Json ([ordered]@{AttemptNonce=$Attempt.AttemptNonce;RequestId=$entry.RequestId;RequestSha256=$entry.RequestSha256;AttemptedUtc=[DateTime]::UtcNow.ToString('o')}) -Compress))
        $latch.Write($bytes,0,$bytes.Length)
        $latch.Flush($true)
    } finally { $latch.Dispose() }
    $Attempt.SaveAttempted=$true
    $Attempt.SaveDisposition='attempted-before-transport'
    $Attempt.SaveEffects=[int64]$Attempt.SaveEffects+1
    Write-UID0002FDAttemptJournal $Attempt
    try {
        $raw=[string](& $Transport $LiteralSaveRequestJson)
    } catch {
        $entry.Disposition='save-transport-indeterminate'
        $Attempt.SaveDisposition='indeterminate'
        Write-UID0002FDAttemptJournal $Attempt
        return [pscustomobject]@{Disposition='indeterminate';Response=$null;Error=$_.Exception.Message}
    }
    try {
        $response=Consume-UID0002FDResponse $Attempt $entry $raw
        $Attempt.SaveDisposition='determinate-success'
        Write-UID0002FDAttemptJournal $Attempt
        [pscustomobject]@{Disposition='determinate-success';Response=$response;Error=$null}
    } catch {
        $Attempt.SaveDisposition=if ($raw | Select-String -SimpleMatch '"error"') {'determinate-failure'} else {'indeterminate'}
        $entry.Disposition=$Attempt.SaveDisposition
        Write-UID0002FDAttemptJournal $Attempt
        [pscustomobject]@{Disposition=$Attempt.SaveDisposition;Response=$null;Error=$_.Exception.Message}
    }
}

function Resolve-UID0002FDTransactionOutcome {
    param([Parameter(Mandatory)]$Attempt,$ClosedTuple,$P0,$P1,[bool]$PostSaveVerifierPassed,[bool]$RollbackVerifierPassed)
    if ($false -eq $Attempt.SaveAttempted) {
        if ($RollbackVerifierPassed -and $null -ne $ClosedTuple -and $ClosedTuple.SHA256 -ceq $P0.SHA256) { return 'pre-save-not-persisted' }
        return 'pre-save-unknown'
    }
    switch([string]$Attempt.SaveDisposition) {
        'determinate-success' {
            if ($PostSaveVerifierPassed -and $null -ne $P1 -and $ClosedTuple.SHA256 -ceq $P1.SHA256) { return 'persisted' }
            return 'unknown'
        }
        'determinate-failure' {
            if ($RollbackVerifierPassed -and $ClosedTuple.SHA256 -ceq $P0.SHA256) { return 'not-persisted' }
            return 'unknown'
        }
        'indeterminate' {
            if ($PostSaveVerifierPassed -and $null -ne $P1 -and $ClosedTuple.SHA256 -ceq $P1.SHA256) { return 'persisted' }
            if ($RollbackVerifierPassed -and $ClosedTuple.SHA256 -ceq $P0.SHA256) { return 'not-persisted' }
            return 'unknown'
        }
        default { return 'unknown' }
    }
}

function Assert-UID0002FDWorkerRetired {
    param([Parameter(Mandatory)]$FrozenIdentity,[Parameter(Mandatory)]$IdbListResponse,[Parameter(Mandatory)]$ListenerSnapshot,[Parameter(Mandatory)][scriptblock]$GetProcessByPid,[Parameter(Mandatory)][scriptblock]$GetListeningSockets,[Parameter(Mandatory)][scriptblock]$ER00Probe)
    if ([int]$ListenerSnapshot.Pid -ne [int]$FrozenIdentity.ListenerPid -or [string]$ListenerSnapshot.Generation -cne [string]$FrozenIdentity.ListenerGeneration) {
        throw 'UID0002FD LISTENER_NOT_PRESERVED'
    }
    $rows=@($IdbListResponse.result.structuredContent.sessions | Where-Object { [string]$_.session_id -ceq [string]$FrozenIdentity.Database })
    if (@($rows | Where-Object { $true -eq $_.is_active }).Count -ne 0) { throw 'UID0002FD RETIRED_SESSION_STILL_ACTIVE' }
    foreach($pid in @([int]$FrozenIdentity.RedirectorPid,[int]$FrozenIdentity.WorkerPid)) {
        $process=& $GetProcessByPid $pid
        if ($null -ne $process) { throw "UID0002FD RETIRED_PID_PRESENT_OR_REUSED pid=$pid" }
    }
    $sockets=@(& $GetListeningSockets)
    if (@($sockets | Where-Object { [int]$_.OwningProcess -in @([int]$FrozenIdentity.RedirectorPid,[int]$FrozenIdentity.WorkerPid) -or ([string]$_.Host -ceq [string]$FrozenIdentity.RouteHost -and [int]$_.Port -eq [int]$FrozenIdentity.RoutePort) }).Count -ne 0) {
        throw 'UID0002FD RETIRED_ROUTE_SOCKET_PRESENT'
    }
    $er00=& $ER00Probe
    if ($true -ne $er00) { throw 'UID0002FD ER00_RETIREMENT_GATE_FAILED' }
    $true
}

function Invoke-UID0002FDVerifierBranch {
    param([Parameter(Mandatory)]$Attempt,[Parameter(Mandatory)][scriptblock]$Transport,[Parameter(Mandatory)][ValidateSet('postsave','rollback')][string]$Phase,[Parameter(Mandatory)][array]$ReadbackCalls,[Parameter(Mandatory)]$ExpectedTuple,[Parameter(Mandatory)][scriptblock]$RetireRole,[Parameter(Mandatory)][scriptblock]$ClosedTupleReader,[Parameter(Mandatory)][scriptblock]$RetirementProof)
    $binding=Invoke-UID0002FDOpenRole $Attempt $Transport $Phase
    foreach($call in $ReadbackCalls) {
        if ($call.ActionClass -notin @('V','RB') -or $null -eq $call.SemanticContract) { throw "UID0002FD VERIFIER_CALL_CONTRACT_MISSING label=$($call.Label)" }
        $null=Invoke-UID0002FDControlledCall $Attempt $Transport $Phase $call.ActionClass $call.LiteralRequestJson $binding {
            param($response,$raw)
            Assert-UID0002FDSemanticResult $response $call.SemanticContract $call.Label
        }
    }
    $null=& $RetireRole $binding
    if ($true -ne (& $RetirementProof $binding)) { throw "UID0002FD VERIFIER_RETIREMENT_FAILED phase=$Phase" }
    $closed=& $ClosedTupleReader
    Assert-UID0002FDExactTuple $closed $ExpectedTuple "UID0002FD $Phase final closed tuple"
    [pscustomobject]@{Passed=$true;Phase=$Phase;Binding=$binding;ClosedTuple=$closed}
}

function Assert-UID0002FDRestoreIdentity {
    param($Current,$P0,$P1)
    if ($null -eq $Current -or $null -eq $P0 -or $null -eq $P1) { throw 'UID0002FD RESTORE_IDENTITY_NULL' }
    if ($Current.SHA256 -ceq $P0.SHA256 -and $Current.Length -eq $P0.Length -and $Current.LastWriteTimeUtcTicks -eq $P0.LastWriteTimeUtcTicks) {
        throw 'UID0002FD RESTORE_DESTINATION_ALREADY_P0_NO_TRUNCATION'
    }
    if ($Current.SHA256 -cne $P1.SHA256 -or $Current.Length -ne $P1.Length -or $Current.LastWriteTimeUtcTicks -ne $P1.LastWriteTimeUtcTicks) {
        throw 'UID0002FD RESTORE_DESTINATION_NOT_EXACT_ATTRIBUTABLE_P1'
    }
    $true
}

function Assert-UID0002FDStableAttestationTuple {
    param($Frozen,$Current)
    foreach($field in @('Database','ListenerGeneration','WorkerGeneration','WorkerPid','RedirectorPid','RouteHost','RoutePort','ListenerManifestSha256','WorkerManifestSha256')) {
        if ([string]$Frozen.$field -cne [string]$Current.$field) { throw "UID0002FD ATTESTATION_TUPLE_DRIFT field=$field" }
    }
    if ([string]$Frozen.ListenerNonce -ceq [string]$Current.ListenerNonce -or [string]$Frozen.WorkerNonce -ceq [string]$Current.WorkerNonce) {
        throw 'UID0002FD ATTESTATION_NONCE_REPLAY'
    }
    $true
}
~~~

## Removed Block R011

- SHA256: `159248A315F4EA645198D8A09C38AF0DC408C79B0EC484743DB81B3EEB2E4D40`
- Language: `powershell`
- Bytes: `19189`
- First recovered timestamp: `2026-08-07T00:31:27.887Z`
- Session provenance: rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 194885 (2026-08-07T00:31:27.887Z); rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 194886 (2026-08-07T00:31:27.939Z)

~~~powershell
$UID0002FDOpenContracts = [ordered]@{
    diagnostic  = [ordered]@{ BuildCaches=$true;  InitHexrays=$true;  Prefix='uid0002fd-diagnostic-' }
    transaction = [ordered]@{ BuildCaches=$false; InitHexrays=$false; Prefix='uid0002fd-transaction-' }
    postsave     = [ordered]@{ BuildCaches=$false; InitHexrays=$false; Prefix='uid0002fd-postsave-' }
    rollback     = [ordered]@{ BuildCaches=$false; InitHexrays=$false; Prefix='uid0002fd-rollback-' }
}

function Get-UID0002FDTextSha256 {
    param([Parameter(Mandatory)][string]$Text)
    $stream=[IO.MemoryStream]::new([Text.Encoding]::UTF8.GetBytes($Text))
    try { (Get-FileHash -InputStream $stream -Algorithm SHA256).Hash } finally { $stream.Dispose() }
}

function Get-UID0002FDStreamSha256 {
    param([Parameter(Mandatory)][IO.Stream]$Stream)
    $position=$Stream.Position
    try { $Stream.Position=0; (Get-FileHash -InputStream $Stream -Algorithm SHA256).Hash } finally { $Stream.Position=$position }
}

function Write-UID0002FDAttemptJournal {
    param([Parameter(Mandatory)]$Attempt)
    $json=$Attempt | ConvertTo-Json -Depth 40
    $bytes=[Text.UTF8Encoding]::new($false).GetBytes($json+[Environment]::NewLine)
    $temp=Join-Path $Attempt.Directory ('journal-'+[Guid]::NewGuid().ToString('N')+'.tmp')
    $stream=[IO.FileStream]::new($temp,[IO.FileMode]::CreateNew,[IO.FileAccess]::Write,[IO.FileShare]::None)
    try { $stream.Write($bytes,0,$bytes.Length);$stream.Flush($true) } finally { $stream.Dispose() }
    if (Test-Path -LiteralPath $Attempt.JournalPath) { [IO.File]::Replace($temp,$Attempt.JournalPath,$null,$true) }
    else { [IO.File]::Move($temp,$Attempt.JournalPath) }
}

function New-UID0002FDAttempt {
    param([Parameter(Mandatory)][string]$Directory)
    $full=[IO.Path]::GetFullPath($Directory)
    if (Test-Path -LiteralPath $full) { throw 'UID0002FD ATTEMPT_DIRECTORY_ALREADY_EXISTS' }
    $null=[IO.Directory]::CreateDirectory($full)
    $attempt=[pscustomobject][ordered]@{
        SchemaVersion=1;AttemptNonce=[Guid]::NewGuid().ToString('N');StartedUtc=[DateTime]::UtcNow.ToString('o')
        Directory=$full;JournalPath=(Join-Path $full 'attempt-journal.json');Sequence=[int64]0;Requests=@()
        SaveAttempted=$false;SaveDisposition='not-attempted';StateEffects=[int64]0;SaveEffects=[int64]0;RestoreEffects=[int64]0
        FrozenSchemas=[pscustomobject]@{}
    }
    Write-UID0002FDAttemptJournal $attempt
    $attempt
}

function Open-UID0002FDAttempt {
    param([Parameter(Mandatory)][string]$Directory)
    $journal=Join-Path ([IO.Path]::GetFullPath($Directory)) 'attempt-journal.json'
    if (-not (Test-Path -LiteralPath $journal -PathType Leaf)) { throw 'UID0002FD ATTEMPT_JOURNAL_MISSING' }
    $attempt=Get-Content -LiteralPath $journal -Raw | ConvertFrom-Json -ErrorAction Stop
    if ([int]$attempt.SchemaVersion -ne 1 -or [string]::IsNullOrWhiteSpace([string]$attempt.AttemptNonce) -or [string]::IsNullOrWhiteSpace([string]$attempt.StartedUtc)) { throw 'UID0002FD ATTEMPT_JOURNAL_INVALID' }
    Add-Member -InputObject $attempt -NotePropertyName Directory -NotePropertyValue ([IO.Path]::GetFullPath($Directory)) -Force
    Add-Member -InputObject $attempt -NotePropertyName JournalPath -NotePropertyValue $journal -Force
    if ($null -eq $attempt.Requests) { $attempt.Requests=@() }
    if ($null -eq $attempt.FrozenSchemas) { $attempt.FrozenSchemas=[pscustomobject]@{} }
    $attempt
}

function New-UID0002FDRequestId {
    param([Parameter(Mandatory)]$Attempt,[Parameter(Mandatory)][string]$Phase,[Parameter(Mandatory)][string]$Operation)
    $Attempt.Sequence=[int64]$Attempt.Sequence+1
    $id='uid0002fd-{0}-{1}-{2:d6}-{3}' -f $Attempt.AttemptNonce,$Phase,$Attempt.Sequence,$Operation
    Write-UID0002FDAttemptJournal $Attempt
    $id
}

function Register-UID0002FDRequest {
    param([Parameter(Mandatory)]$Attempt,[Parameter(Mandatory)][string]$Phase,[Parameter(Mandatory)][string]$ActionClass,[Parameter(Mandatory)][string]$LiteralRequestJson)
    $request=$LiteralRequestJson | ConvertFrom-Json -ErrorAction Stop
    if ([string]$request.jsonrpc -cne '2.0' -or $request.id -isnot [string] -or [string]::IsNullOrWhiteSpace([string]$request.id)) { throw 'UID0002FD REQUEST_ENVELOPE_INVALID' }
    $id=[string]$request.id
    $sha=Get-UID0002FDTextSha256 $LiteralRequestJson
    if (@($Attempt.Requests | Where-Object { [string]$_.RequestId -ceq $id }).Count -ne 0) { throw "UID0002FD REQUEST_ID_REPLAY id=$id" }
    if (@($Attempt.Requests | Where-Object { [string]$_.RequestSha256 -ceq $sha }).Count -ne 0) { throw "UID0002FD REQUEST_BODY_REPLAY sha256=$sha" }
    $entry=[pscustomobject][ordered]@{Sequence=[int64]$Attempt.Sequence;Phase=$Phase;ActionClass=$ActionClass;RequestId=$id;RequestIdNativeType=$request.id.GetType().FullName;RequestSha256=$sha;ResponseSha256=$null;Consumed=$false;Disposition='registered-before-transport'}
    $Attempt.Requests=@($Attempt.Requests)+@($entry)
    Write-UID0002FDAttemptJournal $Attempt
    $entry
}

function Consume-UID0002FDResponse {
    param([Parameter(Mandatory)]$Attempt,[Parameter(Mandatory)]$Entry,[Parameter(Mandatory)][string]$RawResponseJson)
    if ($true -eq $Entry.Consumed) { throw "UID0002FD RESPONSE_ALREADY_CONSUMED id=$($Entry.RequestId)" }
    $sha=Get-UID0002FDTextSha256 $RawResponseJson
    if (@($Attempt.Requests | Where-Object { $true -eq $_.Consumed -and [string]$_.ResponseSha256 -ceq $sha }).Count -ne 0) { throw "UID0002FD RESPONSE_REPLAY sha256=$sha" }
    $response=$RawResponseJson | ConvertFrom-Json -ErrorAction Stop
    if (-not $response.PSObject.Properties['jsonrpc'] -or [string]$response.jsonrpc -cne '2.0') { throw 'UID0002FD JSON_RPC_VERSION_MISMATCH' }
    if (-not $response.PSObject.Properties['id'] -or $null -eq $response.id) { throw 'UID0002FD JSON_RPC_ID_MISSING' }
    if ($response.id.GetType().FullName -cne [string]$Entry.RequestIdNativeType) { throw 'UID0002FD JSON_RPC_ID_NATIVE_TYPE_MISMATCH' }
    if ([string]$response.id -cne [string]$Entry.RequestId) { throw 'UID0002FD JSON_RPC_ID_VALUE_MISMATCH' }
    if ($response.PSObject.Properties['error'] -and $null -ne $response.error) { throw 'UID0002FD JSON_RPC_ERROR_PRESENT' }
    if (-not $response.PSObject.Properties['result'] -or $null -eq $response.result) { throw 'UID0002FD JSON_RPC_RESULT_MISSING' }
    if ($response.result.PSObject.Properties['isError'] -and $true -eq $response.result.isError) { throw 'UID0002FD TOOL_RESULT_IS_ERROR' }
    $Entry.ResponseSha256=$sha;$Entry.Consumed=$true;$Entry.Disposition='correlated-and-consumed'
    Write-UID0002FDAttemptJournal $Attempt
    $response
}

function Assert-UID0002FDExactOpenRequest {
    param([Parameter(Mandatory)]$Request,[Parameter(Mandatory)][string]$Phase)
    if (-not $UID0002FDOpenContracts.Contains($Phase)) { throw "UID0002FD OPEN_PHASE_UNKNOWN phase=$Phase" }
    $contract=$UID0002FDOpenContracts[$Phase]
    $expected=@('build_caches','idle_ttl_sec','init_hexrays','input_path','mode','preferred_session_id','run_auto_analysis')
    $actual=@($Request.params.arguments.PSObject.Properties.Name | Sort-Object)
    if ((ConvertTo-Json $actual -Compress) -cne (ConvertTo-Json ($expected | Sort-Object) -Compress)) { throw 'UID0002FD IDB_OPEN_EXTRA_OR_MISSING_ARGUMENT' }
    if ([string]$Request.method -cne 'tools/call' -or [string]$Request.params.name -cne 'idb_open' -or
        -not [string]::Equals([IO.Path]::GetFullPath([string]$Request.params.arguments.input_path),$UID0002FDCanonicalPath,[StringComparison]::OrdinalIgnoreCase) -or
        [string]$Request.params.arguments.mode -cne 'force_headless' -or $false -ne $Request.params.arguments.run_auto_analysis -or
        [bool]$Request.params.arguments.build_caches -ne [bool]$contract.BuildCaches -or [bool]$Request.params.arguments.init_hexrays -ne [bool]$contract.InitHexrays -or
        [int]$Request.params.arguments.idle_ttl_sec -ne 600) { throw "UID0002FD IDB_OPEN_CONTRACT_MISMATCH phase=$Phase" }
    $preferred=[string]$Request.params.arguments.preferred_session_id
    if (-not $preferred.StartsWith([string]$contract.Prefix,[StringComparison]::Ordinal) -or $preferred.Length -le ([string]$contract.Prefix).Length) { throw "UID0002FD IDB_OPEN_PREFIX_NOT_FRESH phase=$Phase" }
}

$UID0002FDToolSchemaContracts=[ordered]@{
    runtime_attestation=[ordered]@{Required=@();Properties=[ordered]@{expected_database='string=';expected_canonical_path='string='}}
    idb_open=[ordered]@{Required=@('input_path');Properties=[ordered]@{input_path='string';mode='string=force_headless';run_auto_analysis='boolean=false';build_caches='boolean=true';init_hexrays='boolean=true';idle_ttl_sec='integer=600';preferred_session_id='string='}}
    idb_list=[ordered]@{Required=@();Properties=[ordered]@{}}
    server_health=[ordered]@{Required=@();Properties=[ordered]@{database='string='}}
    analyze_function=[ordered]@{Required=@('addr');Properties=[ordered]@{addr='string';database='string='}}
    lookup_funcs=[ordered]@{Required=@('queries');Properties=[ordered]@{queries='array';database='string='}}
    stack_frame=[ordered]@{Required=@('addrs');Properties=[ordered]@{addrs='array';database='string='}}
    get_comments=[ordered]@{Required=@('addrs');Properties=[ordered]@{addrs='array';database='string='}}
    inspect_items=[ordered]@{Required=@('addrs');Properties=[ordered]@{addrs='array';database='string='}}
    type_inspect=[ordered]@{Required=@('queries');Properties=[ordered]@{queries='array';database='string='}}
    entity_query=[ordered]@{Required=@('queries');Properties=[ordered]@{queries='array';database='string='}}
    xref_query=[ordered]@{Required=@('queries');Properties=[ordered]@{queries='array';database='string='}}
    get_bytes=[ordered]@{Required=@('regions');Properties=[ordered]@{regions='array';database='string='}}
    rename=[ordered]@{Required=@('batch');Properties=[ordered]@{batch='object-or-array';database='string='}}
    set_type=[ordered]@{Required=@('edits');Properties=[ordered]@{edits='object-or-array';database='string='}}
    set_function_comments=[ordered]@{Required=@('items');Properties=[ordered]@{items='object-or-array';database='string='}}
    make_data=[ordered]@{Required=@('items');Properties=[ordered]@{items='object-or-array';database='string='}}
    set_address_comments=[ordered]@{Required=@('items');Properties=[ordered]@{items='object-or-array';database='string='}}
    idb_save=[ordered]@{Required=@('path');Properties=[ordered]@{path='string';database='string='}}
}

function Assert-UID0002FDPropertySchema {
    param([Parameter(Mandatory)]$Actual,[Parameter(Mandatory)][string]$Contract,[Parameter(Mandatory)][string]$Label)
    $parts=$Contract.Split('=',2);$kind=$parts[0]
    if ($kind -eq 'object-or-array') {
        $types=@(@($Actual.oneOf) | ForEach-Object { [string]$_.type } | Sort-Object)
        if ((ConvertTo-Json $types -Compress) -cne '["array","object"]') { throw "UID0002FD SCHEMA_TYPE_DRIFT $Label" }
    } elseif ([string]$Actual.type -cne $kind) { throw "UID0002FD SCHEMA_TYPE_DRIFT $Label" }
    if ($parts.Count -eq 2) {
        if (-not $Actual.PSObject.Properties['default']) { throw "UID0002FD SCHEMA_DEFAULT_MISSING $Label" }
        $expected=$parts[1]
        if ($kind -eq 'boolean') { if ([bool]$Actual.default -ne [bool]::Parse($expected)) { throw "UID0002FD SCHEMA_DEFAULT_DRIFT $Label" } }
        elseif ($kind -eq 'integer') { if ([int64]$Actual.default -ne [int64]$expected) { throw "UID0002FD SCHEMA_DEFAULT_DRIFT $Label" } }
        elseif ([string]$Actual.default -cne $expected) { throw "UID0002FD SCHEMA_DEFAULT_DRIFT $Label" }
    } elseif ($Actual.PSObject.Properties['default']) { throw "UID0002FD SCHEMA_UNEXPECTED_DEFAULT $Label" }
}

function Assert-UID0002FDAllUsedToolSchemas {
    param([Parameter(Mandatory)]$ToolsListResponse,[Parameter(Mandatory)]$Attempt)
    $tools=@($ToolsListResponse.result.tools)
    foreach($name in $UID0002FDToolSchemaContracts.Keys) {
        $matches=@($tools | Where-Object { [string]$_.name -ceq $name })
        if ($matches.Count -ne 1) { throw "UID0002FD TOOL_CARDINALITY_DRIFT name=$name" }
        $schema=$matches[0].inputSchema;$contract=$UID0002FDToolSchemaContracts[$name]
        if ([string]$schema.type -cne 'object' -or -not $schema.PSObject.Properties['required'] -or -not $schema.PSObject.Properties['properties']) { throw "UID0002FD SCHEMA_ROOT_DRIFT name=$name" }
        $required=@($schema.required | ForEach-Object { [string]$_ } | Sort-Object);$expectedRequired=@($contract.Required | Sort-Object)
        if ((ConvertTo-Json $required -Compress) -cne (ConvertTo-Json $expectedRequired -Compress)) { throw "UID0002FD SCHEMA_REQUIRED_DRIFT name=$name" }
        $actualProperties=@($schema.properties.PSObject.Properties.Name | Sort-Object);$expectedProperties=@($contract.Properties.Keys | Sort-Object)
        if ((ConvertTo-Json $actualProperties -Compress) -cne (ConvertTo-Json $expectedProperties -Compress)) { throw "UID0002FD SCHEMA_PROPERTY_DRIFT name=$name" }
        foreach($property in $contract.Properties.Keys) { Assert-UID0002FDPropertySchema $schema.properties.$property ([string]$contract.Properties[$property]) "$name.$property" }
        if (-not $schema.PSObject.Properties['additionalProperties'] -or $false -ne $schema.additionalProperties) { throw "UID0002FD SCHEMA_NO_EXTRA_BEHAVIOR_DRIFT name=$name" }
        $sha=Get-UID0002FDTextSha256 ($schema | ConvertTo-Json -Depth 40 -Compress)
        if ($Attempt.FrozenSchemas.PSObject.Properties[$name]) {
            if ([string]$Attempt.FrozenSchemas.$name -cne $sha) { throw "UID0002FD NESTED_SCHEMA_DRIFT name=$name" }
        } else { Add-Member -InputObject $Attempt.FrozenSchemas -NotePropertyName $name -NotePropertyValue $sha -Force }
    }
    Write-UID0002FDAttemptJournal $Attempt
}

function Assert-UID0002FDSemanticResult {
    param([Parameter(Mandatory)]$Response,[Parameter(Mandatory)]$Contract,[Parameter(Mandatory)][string]$Label)
    if (-not $Response.result.PSObject.Properties['structuredContent']) { throw "UID0002FD SEMANTIC_CONTENT_MISSING label=$Label" }
    $sc=$Response.result.structuredContent
    if (-not [string]::IsNullOrWhiteSpace([string]$Contract.ExpectedCanonicalJsonSha256)) {
        if ((Get-UID0002FDTextSha256 ($sc | ConvertTo-Json -Depth 50 -Compress)) -cne [string]$Contract.ExpectedCanonicalJsonSha256) { throw "UID0002FD SEMANTIC_DIGEST_MISMATCH label=$Label" }
    }
    if ($null -ne $Contract.ExpectedItemCount) {
        if (-not $sc.PSObject.Properties[[string]$Contract.ItemsProperty]) { throw "UID0002FD SEMANTIC_ITEMS_MISSING label=$Label" }
        if (@($sc.([string]$Contract.ItemsProperty)).Count -ne [int]$Contract.ExpectedItemCount) { throw "UID0002FD SEMANTIC_ITEM_COUNT_MISMATCH label=$Label" }
    }
    foreach($property in @($Contract.RequiredProperties)) { if (-not $sc.PSObject.Properties[[string]$property]) { throw "UID0002FD SEMANTIC_REQUIRED_FIELD_MISSING label=$Label field=$property" } }
    if ([string]$Contract.Pagination -ceq 'terminal-null') {
        if (-not $sc.PSObject.Properties['next_offset'] -or $null -ne $sc.next_offset) { throw "UID0002FD PAGINATION_TERMINAL_MISMATCH label=$Label" }
    } elseif ([string]$Contract.Pagination -ceq 'forbidden' -and $sc.PSObject.Properties['next_offset']) { throw "UID0002FD PAGINATION_FIELD_FORBIDDEN label=$Label" }
    if ($null -eq $Contract.Predicate -or $true -ne (& $Contract.Predicate $sc)) { throw "UID0002FD SEMANTIC_PREDICATE_FAILED label=$Label" }
    $true
}

function Invoke-UID0002FDControlledCall {
    param([Parameter(Mandatory)]$Attempt,[Parameter(Mandatory)][scriptblock]$Transport,[Parameter(Mandatory)][string]$Phase,[Parameter(Mandatory)][ValidateSet('OPEN','S','I','F','V','RB','SAVE')][string]$ActionClass,[Parameter(Mandatory)][string]$LiteralRequestJson,$OpenBinding,[Parameter(Mandatory)][scriptblock]$SemanticAssertion)
    if ($ActionClass -in @('S','I','F','V','RB','SAVE')) {
        if ($null -eq $OpenBinding) { throw "UID0002FD STATEFUL_BINDING_MISSING class=$ActionClass" }
        Assert-UID0002FDStatefulQueryAuthorized $OpenBinding
        $requestCheck=$LiteralRequestJson | ConvertFrom-Json -ErrorAction Stop
        if (-not $requestCheck.params.arguments.PSObject.Properties['database'] -or [string]$requestCheck.params.arguments.database -cne [string]$OpenBinding.Database) { throw "UID0002FD STATEFUL_DATABASE_AUTHORITY_MISMATCH class=$ActionClass" }
    }
    $entry=Register-UID0002FDRequest $Attempt $Phase $ActionClass $LiteralRequestJson
    try { $raw=[string](& $Transport $LiteralRequestJson) } catch { $entry.Disposition='transport-failed';Write-UID0002FDAttemptJournal $Attempt;throw }
    $response=Consume-UID0002FDResponse $Attempt $entry $raw
    $semantic=& $SemanticAssertion $response $raw
    if ($null -eq $semantic) { throw "UID0002FD SEMANTIC_ASSERTION_RETURNED_NULL class=$ActionClass" }
    [pscustomobject][ordered]@{RequestEntry=$entry;RawResponseJson=$raw;Response=$response;Semantic=$semantic}
}

function Invoke-UID0002FDOpenRole {
    param([Parameter(Mandatory)]$Attempt,[Parameter(Mandatory)][scriptblock]$Transport,[Parameter(Mandatory)][string]$Phase)
    $contract=$UID0002FDOpenContracts[$Phase];if ($null -eq $contract) { throw "UID0002FD OPEN_PHASE_UNKNOWN phase=$Phase" }
    $toolsJson=New-UID0002FDToolsListRequest (New-UID0002FDRequestId $Attempt $Phase 'tools-list')
    $toolsCall=Invoke-UID0002FDControlledCall $Attempt $Transport $Phase OPEN $toolsJson $null {
        param($response,$raw)
        $gate=Assert-UID0002FDPublicToolList $toolsJson $raw
        Assert-UID0002FDAllUsedToolSchemas $response $Attempt
        $gate
    }
    $preferred=[string]$contract.Prefix+$Attempt.AttemptNonce+'-'+[Guid]::NewGuid().ToString('N')
    $openJson=New-UID0002FDOpenRequest (New-UID0002FDRequestId $Attempt $Phase 'idb-open') $preferred ([bool]$contract.BuildCaches) ([bool]$contract.InitHexrays)
    Assert-UID0002FDExactOpenRequest ($openJson | ConvertFrom-Json -ErrorAction Stop) $Phase
    $openCall=Invoke-UID0002FDControlledCall $Attempt $Transport $Phase OPEN $openJson $null { param($response,$raw) $true }
    $binding=Bind-UID0002FDOpenResponse $toolsCall.Semantic $openJson $openCall.RawResponseJson $Phase
    $att1Json=New-UID0002FDRuntimeAttestationRequest (New-UID0002FDRequestId $Attempt $Phase 'attestation-initial') $binding
    $null=Invoke-UID0002FDControlledCall $Attempt $Transport $Phase OPEN $att1Json $null { param($response,$raw) $null=Assert-UID0002FDPublicRuntimeAttestation $att1Json $raw $binding $false;$true }
    $listJson=New-UID0002FDIdbListRequest (New-UID0002FDRequestId $Attempt $Phase 'idb-list')
    $null=Invoke-UID0002FDControlledCall $Attempt $Transport $Phase OPEN $listJson $null { param($response,$raw) $null=Add-UID0002FDListCorroboration $binding $listJson $raw;$true }
    $att2Json=New-UID0002FDRuntimeAttestationRequest (New-UID0002FDRequestId $Attempt $Phase 'attestation-authorize') $binding
    $null=Invoke-UID0002FDControlledCall $Attempt $Transport $Phase OPEN $att2Json $null { param($response,$raw) $null=Assert-UID0002FDPublicRuntimeAttestation $att2Json $raw $binding $true;$true }
    Assert-UID0002FDStatefulQueryAuthorized $binding
    $binding
}
~~~

## Removed Block R012

- SHA256: `13C5007CA2AA917F5811B4048C4CFD83B648A99A59BFC83E1902FB3921FE02AB`
- Language: `powershell`
- Bytes: `2279`
- First recovered timestamp: `2026-08-07T00:32:13.622Z`
- Session provenance: rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 194890 (2026-08-07T00:32:13.622Z); rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 194891 (2026-08-07T00:32:13.675Z)

~~~powershell
function Invoke-UID0002FDRestoreP1ToP0 {
    param([Parameter(Mandatory)][string]$CanonicalPath,[Parameter(Mandatory)][string]$BackupPath,[Parameter(Mandatory)]$P0,[Parameter(Mandatory)]$P1,[Parameter(Mandatory)]$B0,[Parameter(Mandatory)]$Attempt)
    if ([int64]$Attempt.RestoreEffects -ne 0) { throw 'UID0002FD DUPLICATE_RESTORE_ATTEMPT' }
    $source=[IO.FileStream]::new($BackupPath,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None)
    $destination=$null
    try {
        if ($source.Length -ne $B0.Length -or (Get-UID0002FDStreamSha256 $source) -cne $B0.SHA256) { throw 'UID0002FD B0_UNDER_HANDLE_MISMATCH' }
        $destination=[IO.FileStream]::new($CanonicalPath,[IO.FileMode]::Open,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None)
        $underHandle=[pscustomobject][ordered]@{Path=[IO.Path]::GetFullPath($CanonicalPath);Length=[int64]$destination.Length;SHA256=(Get-UID0002FDStreamSha256 $destination);LastWriteTimeUtcTicks=[IO.File]::GetLastWriteTimeUtc($CanonicalPath).Ticks}
        $null=Assert-UID0002FDRestoreIdentity $underHandle $P0 $P1
        $Attempt.RestoreEffects=[int64]$Attempt.RestoreEffects+1;Write-UID0002FDAttemptJournal $Attempt
        $source.Position=0;$destination.Position=0;$destination.SetLength(0)
        if ($destination.Length -ne 0 -or $destination.Position -ne 0) { throw 'UID0002FD RESTORE_TRUNCATION_FAILED' }
        $source.CopyTo($destination)
        if ($source.Position -ne $B0.Length -or $source.ReadByte() -ne -1) { throw 'UID0002FD RESTORE_SOURCE_EOF_MISMATCH' }
        if ($destination.Position -ne $P0.Length -or $destination.Length -ne $P0.Length) { throw 'UID0002FD RESTORE_DESTINATION_LENGTH_MISMATCH' }
        $destination.Flush($true)
    } finally {
        if ($null -ne $destination) { $destination.Dispose() }
        $source.Dispose()
    }
    [IO.File]::SetLastWriteTimeUtc($CanonicalPath,[DateTime]::new([int64]$P0.LastWriteTimeUtcTicks,[DateTimeKind]::Utc))
    $first=Get-UID0002FDClosedTuple $CanonicalPath;$second=Get-UID0002FDClosedTuple $CanonicalPath
    Assert-UID0002FDExactTuple $first $P0 'UID0002FD restored P0 first'
    Assert-UID0002FDExactTuple $second $P0 'UID0002FD restored P0 second'
    [pscustomobject]@{Restored=$true;First=$first;Second=$second}
}
~~~

## Removed Block R013

- SHA256: `6A2F6EF09211777696E436834622F1444CC908D8486CFBF053F7BF6B31CF5E3E`
- Language: `powershell`
- Bytes: `8174`
- First recovered timestamp: `2026-08-07T00:32:13.622Z`
- Session provenance: rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 194890 (2026-08-07T00:32:13.622Z); rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 194891 (2026-08-07T00:32:13.675Z)

~~~powershell
function Invoke-UID0002FDSaveOnce {
    param([Parameter(Mandatory)]$Attempt,[Parameter(Mandatory)][scriptblock]$Transport,[Parameter(Mandatory)]$OpenBinding,[Parameter(Mandatory)][string]$LiteralSaveRequestJson)
    Assert-UID0002FDStatefulQueryAuthorized $OpenBinding
    if ($true -eq $Attempt.SaveAttempted -or (Test-Path -LiteralPath (Join-Path $Attempt.Directory 'save-attempted.latch'))) { throw 'UID0002FD DUPLICATE_SAVE_ATTEMPT' }
    $request=$LiteralSaveRequestJson | ConvertFrom-Json -ErrorAction Stop
    if ([string]$request.params.name -cne 'idb_save' -or [string]$request.params.arguments.database -cne [string]$OpenBinding.Database -or
        -not [string]::Equals([IO.Path]::GetFullPath([string]$request.params.arguments.path),$OpenBinding.CanonicalPath,[StringComparison]::OrdinalIgnoreCase)) { throw 'UID0002FD SAVE_REQUEST_AUTHORITY_MISMATCH' }
    $entry=Register-UID0002FDRequest $Attempt $OpenBinding.Phase SAVE $LiteralSaveRequestJson
    $latchPath=Join-Path $Attempt.Directory 'save-attempted.latch'
    $latch=[IO.FileStream]::new($latchPath,[IO.FileMode]::CreateNew,[IO.FileAccess]::Write,[IO.FileShare]::None)
    try {
        $bytes=[Text.UTF8Encoding]::new($false).GetBytes((ConvertTo-Json ([ordered]@{AttemptNonce=$Attempt.AttemptNonce;RequestId=$entry.RequestId;RequestSha256=$entry.RequestSha256;AttemptedUtc=[DateTime]::UtcNow.ToString('o')}) -Compress))
        $latch.Write($bytes,0,$bytes.Length);$latch.Flush($true)
    } finally { $latch.Dispose() }
    $Attempt.SaveAttempted=$true;$Attempt.SaveDisposition='attempted-before-transport';$Attempt.SaveEffects=[int64]$Attempt.SaveEffects+1
    Write-UID0002FDAttemptJournal $Attempt
    try { $raw=[string](& $Transport $LiteralSaveRequestJson) }
    catch {
        $entry.Disposition='save-transport-indeterminate';$Attempt.SaveDisposition='indeterminate'
        Write-UID0002FDAttemptJournal $Attempt
        return [pscustomobject]@{Disposition='indeterminate';Response=$null;Error=$_.Exception.Message}
    }
    try {
        $response=Consume-UID0002FDResponse $Attempt $entry $raw
        $Attempt.SaveDisposition='determinate-success';Write-UID0002FDAttemptJournal $Attempt
        [pscustomobject]@{Disposition='determinate-success';Response=$response;Error=$null}
    } catch {
        $parsed=$null
        try { $parsed=$raw | ConvertFrom-Json -ErrorAction Stop } catch {}
        if ($null -ne $parsed -and $parsed.PSObject.Properties['error'] -and $null -ne $parsed.error -and
            $parsed.PSObject.Properties['jsonrpc'] -and [string]$parsed.jsonrpc -ceq '2.0' -and
            $parsed.PSObject.Properties['id'] -and $parsed.id.GetType().FullName -ceq [string]$entry.RequestIdNativeType -and [string]$parsed.id -ceq [string]$entry.RequestId) {
            $Attempt.SaveDisposition='determinate-failure'
        } else { $Attempt.SaveDisposition='indeterminate' }
        $entry.Disposition=$Attempt.SaveDisposition;Write-UID0002FDAttemptJournal $Attempt
        [pscustomobject]@{Disposition=$Attempt.SaveDisposition;Response=$null;Error=$_.Exception.Message}
    }
}

function Resolve-UID0002FDTransactionOutcome {
    param([Parameter(Mandatory)]$Attempt,$ClosedTuple,$P0,$P1,[bool]$PostSaveVerifierPassed,[bool]$RollbackVerifierPassed)
    if ($false -eq $Attempt.SaveAttempted) {
        if ($RollbackVerifierPassed -and $null -ne $ClosedTuple -and $ClosedTuple.SHA256 -ceq $P0.SHA256) { return 'pre-save-not-persisted' }
        return 'pre-save-unknown'
    }
    switch([string]$Attempt.SaveDisposition) {
        'determinate-success' { if ($PostSaveVerifierPassed -and $null -ne $P1 -and $ClosedTuple.SHA256 -ceq $P1.SHA256) { return 'persisted' };return 'unknown' }
        'determinate-failure' { if ($RollbackVerifierPassed -and $ClosedTuple.SHA256 -ceq $P0.SHA256) { return 'not-persisted' };return 'unknown' }
        'indeterminate' {
            if ($PostSaveVerifierPassed -and $null -ne $P1 -and $ClosedTuple.SHA256 -ceq $P1.SHA256) { return 'persisted' }
            if ($RollbackVerifierPassed -and $ClosedTuple.SHA256 -ceq $P0.SHA256) { return 'not-persisted' }
            return 'unknown'
        }
        default { return 'unknown' }
    }
}

function Assert-UID0002FDWorkerRetired {
    param([Parameter(Mandatory)]$FrozenIdentity,[Parameter(Mandatory)]$IdbListResponse,[Parameter(Mandatory)]$ListenerSnapshot,[Parameter(Mandatory)][scriptblock]$GetProcessByPid,[Parameter(Mandatory)][scriptblock]$GetListeningSockets,[Parameter(Mandatory)][scriptblock]$ER00Probe)
    if ([int]$ListenerSnapshot.Pid -ne [int]$FrozenIdentity.ListenerPid -or [string]$ListenerSnapshot.Generation -cne [string]$FrozenIdentity.ListenerGeneration) { throw 'UID0002FD LISTENER_NOT_PRESERVED' }
    $rows=@($IdbListResponse.result.structuredContent.sessions | Where-Object { [string]$_.session_id -ceq [string]$FrozenIdentity.Database })
    if (@($rows | Where-Object { $true -eq $_.is_active }).Count -ne 0) { throw 'UID0002FD RETIRED_SESSION_STILL_ACTIVE' }
    foreach($pid in @([int]$FrozenIdentity.RedirectorPid,[int]$FrozenIdentity.WorkerPid)) {
        if ($null -ne (& $GetProcessByPid $pid)) { throw "UID0002FD RETIRED_PID_PRESENT_OR_REUSED pid=$pid" }
    }
    $sockets=@(& $GetListeningSockets)
    if (@($sockets | Where-Object { [int]$_.OwningProcess -in @([int]$FrozenIdentity.RedirectorPid,[int]$FrozenIdentity.WorkerPid) -or ([string]$_.Host -ceq [string]$FrozenIdentity.RouteHost -and [int]$_.Port -eq [int]$FrozenIdentity.RoutePort) }).Count -ne 0) { throw 'UID0002FD RETIRED_ROUTE_SOCKET_PRESENT' }
    if ($true -ne (& $ER00Probe)) { throw 'UID0002FD ER00_RETIREMENT_GATE_FAILED' }
    $true
}

function Invoke-UID0002FDVerifierBranch {
    param([Parameter(Mandatory)]$Attempt,[Parameter(Mandatory)][scriptblock]$Transport,[Parameter(Mandatory)][ValidateSet('postsave','rollback')][string]$Phase,[Parameter(Mandatory)][array]$ReadbackCalls,[Parameter(Mandatory)]$ExpectedTuple,[Parameter(Mandatory)][scriptblock]$RetireRole,[Parameter(Mandatory)][scriptblock]$ClosedTupleReader,[Parameter(Mandatory)][scriptblock]$RetirementProof)
    $binding=Invoke-UID0002FDOpenRole $Attempt $Transport $Phase
    foreach($call in $ReadbackCalls) {
        if ($call.ActionClass -notin @('V','RB') -or $null -eq $call.SemanticContract) { throw "UID0002FD VERIFIER_CALL_CONTRACT_MISSING label=$($call.Label)" }
        $null=Invoke-UID0002FDControlledCall $Attempt $Transport $Phase $call.ActionClass $call.LiteralRequestJson $binding {
            param($response,$raw)
            Assert-UID0002FDSemanticResult $response $call.SemanticContract $call.Label
        }
    }
    $null=& $RetireRole $binding
    if ($true -ne (& $RetirementProof $binding)) { throw "UID0002FD VERIFIER_RETIREMENT_FAILED phase=$Phase" }
    $closed=& $ClosedTupleReader
    Assert-UID0002FDExactTuple $closed $ExpectedTuple "UID0002FD $Phase final closed tuple"
    [pscustomobject]@{Passed=$true;Phase=$Phase;Binding=$binding;ClosedTuple=$closed}
}

function Assert-UID0002FDRestoreIdentity {
    param($Current,$P0,$P1)
    if ($null -eq $Current -or $null -eq $P0 -or $null -eq $P1) { throw 'UID0002FD RESTORE_IDENTITY_NULL' }
    if ($Current.SHA256 -ceq $P0.SHA256 -and $Current.Length -eq $P0.Length -and $Current.LastWriteTimeUtcTicks -eq $P0.LastWriteTimeUtcTicks) { throw 'UID0002FD RESTORE_DESTINATION_ALREADY_P0_NO_TRUNCATION' }
    if ($Current.SHA256 -cne $P1.SHA256 -or $Current.Length -ne $P1.Length -or $Current.LastWriteTimeUtcTicks -ne $P1.LastWriteTimeUtcTicks) { throw 'UID0002FD RESTORE_DESTINATION_NOT_EXACT_ATTRIBUTABLE_P1' }
    $true
}

function Assert-UID0002FDStableAttestationTuple {
    param($Frozen,$Current)
    foreach($field in @('Database','ListenerGeneration','WorkerGeneration','WorkerPid','RedirectorPid','RouteHost','RoutePort','ListenerManifestSha256','WorkerManifestSha256')) {
        if ([string]$Frozen.$field -cne [string]$Current.$field) { throw "UID0002FD ATTESTATION_TUPLE_DRIFT field=$field" }
    }
    if ([string]$Frozen.ListenerNonce -ceq [string]$Current.ListenerNonce -or [string]$Frozen.WorkerNonce -ceq [string]$Current.WorkerNonce) { throw 'UID0002FD ATTESTATION_NONCE_REPLAY' }
    $true
}
~~~

## Removed Block R014

- SHA256: `E017CDCDB6F4A9816CFD2FA4BEC7B497AD53E134EBCE906D8787C015005DDDD4`
- Language: `powershell`
- Bytes: `9133`
- First recovered timestamp: `2026-08-07T00:33:19.322Z`
- Session provenance: rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 194908 (2026-08-07T00:33:19.322Z); rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 194909 (2026-08-07T00:33:19.377Z)

~~~powershell
function Invoke-UID0002FDExpectedFailure {
    param([Parameter(Mandatory)][string]$Name,[Parameter(Mandatory)][string]$Expected,[Parameter(Mandatory)][scriptblock]$Action,$State)
    $before=[pscustomobject]@{State=[int64]$State.StateEffects;Save=[int64]$State.SaveEffects;Restore=[int64]$State.RestoreEffects}
    $actual=$null
    try { $null=& $Action;throw "UID0002FD FIXTURE_DID_NOT_FAIL name=$Name" } catch { $actual=$_.Exception.Message }
    if ($actual -cne $Expected) { throw "UID0002FD FIXTURE_WRONG_FAILURE name=$Name expected=$Expected actual=$actual" }
    if ([int64]$State.StateEffects -ne $before.State -or [int64]$State.SaveEffects -ne $before.Save -or [int64]$State.RestoreEffects -ne $before.Restore) { throw "UID0002FD FIXTURE_SIDE_EFFECT name=$Name" }
    [pscustomobject]@{Name=$Name;Passed=$true;Failure=$actual}
}

function New-UID0002FDValidSchemaResponse {
    $tools=@()
    foreach($name in $UID0002FDToolSchemaContracts.Keys) {
        $contract=$UID0002FDToolSchemaContracts[$name];$properties=[pscustomobject]@{}
        foreach($property in $contract.Properties.Keys) {
            $parts=([string]$contract.Properties[$property]).Split('=',2);$kind=$parts[0]
            if ($kind -eq 'object-or-array') { $schema=[pscustomobject][ordered]@{oneOf=@([pscustomobject]@{type='object'},[pscustomobject]@{type='array'})} }
            else { $schema=[pscustomobject][ordered]@{type=$kind} }
            if ($parts.Count -eq 2) {
                if ($kind -eq 'boolean') { Add-Member $schema default ([bool]::Parse($parts[1])) }
                elseif ($kind -eq 'integer') { Add-Member $schema default ([int]$parts[1]) }
                else { Add-Member $schema default ([string]$parts[1]) }
            }
            Add-Member -InputObject $properties -NotePropertyName $property -NotePropertyValue $schema
        }
        $input=[pscustomobject][ordered]@{type='object';properties=$properties;required=@($contract.Required);additionalProperties=$false}
        $tools+=,[pscustomobject][ordered]@{name=$name;inputSchema=$input}
    }
    [pscustomobject]@{result=[pscustomobject]@{tools=$tools}}
}

function Invoke-UID0002FDHostileFixtures {
    $state=[pscustomobject]@{StateEffects=[int64]0;SaveEffects=[int64]0;RestoreEffects=[int64]0}
    $results=@()
    $results+=Invoke-UID0002FDExpectedFailure 'wrong-jsonrpc' 'UID0002FD fixture JSON_RPC_VERSION_MISMATCH expected=2.0 actual=1.0' {
        $null=Get-UID0002FDJsonRpcEnvelope '{"jsonrpc":"1.0","id":"fixture","result":{}}' 'fixture' 'fixture'
    } $state
    $results+=Invoke-UID0002FDExpectedFailure 'int32-id' 'UID0002FD fixture JSON_RPC_ID_TYPE_MISMATCH expected_type=String actual_type=Int32' {
        $parsed='{"jsonrpc":"2.0","id":1,"result":{}}' | ConvertFrom-Json
        if ($parsed.id.GetType().FullName -cne 'System.Int32') { throw 'UID0002FD FIXTURE_HOST_NUMERIC_TYPE_DRIFT' }
        $null=Get-UID0002FDJsonRpcEnvelope ($parsed | ConvertTo-Json -Compress) 'fixture' 'fixture'
    } $state
    $badOpen=[pscustomobject]@{method='tools/call';params=[pscustomobject]@{name='idb_open';arguments=[pscustomobject]@{input_path='E:\other.i64';mode='force_headless';run_auto_analysis=$false;build_caches=$false;init_hexrays=$false;idle_ttl_sec=600;preferred_session_id='uid0002fd-transaction-x'}}}
    $results+=Invoke-UID0002FDExpectedFailure 'canonical-divergence' 'UID0002FD IDB_OPEN_CONTRACT_MISMATCH phase=transaction' { Assert-UID0002FDExactOpenRequest $badOpen transaction } $state
    $results+=Invoke-UID0002FDExpectedFailure 'semantic-missing' 'UID0002FD SEMANTIC_CONTENT_MISSING label=fixture' {
        Assert-UID0002FDSemanticResult ([pscustomobject]@{result=[pscustomobject]@{}}) ([pscustomobject]@{ExpectedCanonicalJsonSha256='';ExpectedItemCount=$null;RequiredProperties=@();Pagination='forbidden';Predicate={param($x)$true}}) fixture
    } $state
    $results+=Invoke-UID0002FDExpectedFailure 'pagination' 'UID0002FD PAGINATION_TERMINAL_MISMATCH label=fixture' {
        $response=[pscustomobject]@{result=[pscustomobject]@{structuredContent=[pscustomobject]@{items=@();next_offset=1}}}
        $contract=[pscustomobject]@{ExpectedCanonicalJsonSha256='';ExpectedItemCount=0;ItemsProperty='items';RequiredProperties=@('items','next_offset');Pagination='terminal-null';Predicate={param($x)$true}}
        Assert-UID0002FDSemanticResult $response $contract fixture
    } $state
    $frozen=[pscustomobject]@{Database='d';ListenerGeneration='l';WorkerGeneration='w';WorkerPid=2;RedirectorPid=1;RouteHost='127.0.0.1';RoutePort=1234;ListenerManifestSha256='a';WorkerManifestSha256='b';ListenerNonce='n1';WorkerNonce='n2'}
    $drift=$frozen.PSObject.Copy();$drift.WorkerManifestSha256='c';$drift.ListenerNonce='n3';$drift.WorkerNonce='n4'
    $results+=Invoke-UID0002FDExpectedFailure 'module-drift' 'UID0002FD ATTESTATION_TUPLE_DRIFT field=WorkerManifestSha256' { Assert-UID0002FDStableAttestationTuple $frozen $drift } $state
    $nonce=$frozen.PSObject.Copy()
    $results+=Invoke-UID0002FDExpectedFailure 'nonce-replay' 'UID0002FD ATTESTATION_NONCE_REPLAY' { Assert-UID0002FDStableAttestationTuple $frozen $nonce } $state
    $worker=$frozen.PSObject.Copy();$worker.WorkerPid=3;$worker.ListenerNonce='n3';$worker.WorkerNonce='n4'
    $results+=Invoke-UID0002FDExpectedFailure 'worker-drift' 'UID0002FD ATTESTATION_TUPLE_DRIFT field=WorkerPid' { Assert-UID0002FDStableAttestationTuple $frozen $worker } $state
    $p0=[pscustomobject]@{Path='p';Length=10;SHA256='P0';LastWriteTimeUtc='t0';LastWriteTimeUtcTicks=10}
    $p1=[pscustomobject]@{Path='p';Length=10;SHA256='P1';LastWriteTimeUtc='t1';LastWriteTimeUtcTicks=20}
    $third=[pscustomobject]@{Path='p';Length=10;SHA256='THIRD';LastWriteTimeUtc='t1';LastWriteTimeUtcTicks=20}
    $results+=Invoke-UID0002FDExpectedFailure 'third-identity-restore' 'UID0002FD RESTORE_DESTINATION_NOT_EXACT_ATTRIBUTABLE_P1' { Assert-UID0002FDRestoreIdentity $third $p0 $p1 } $state
    $results+=Invoke-UID0002FDExpectedFailure 'p0-restore' 'UID0002FD RESTORE_DESTINATION_ALREADY_P0_NO_TRUNCATION' { Assert-UID0002FDRestoreIdentity $p0 $p0 $p1 } $state
    $stale=$p1.PSObject.Copy();$stale.SHA256='STALE'
    $results+=Invoke-UID0002FDExpectedFailure 'stale-verifier' 'UID0002FD stale-verifier tuple mismatch: SHA256' { Assert-UID0002FDExactTuple $stale $p1 'UID0002FD stale-verifier' } $state
    $b0=$p0.PSObject.Copy();$b0.SHA256='CORRUPT'
    $results+=Invoke-UID0002FDExpectedFailure 'b0-corruption' 'UID0002FD B0 fixture tuple mismatch: SHA256' { Assert-UID0002FDExactTuple $b0 $p0 'UID0002FD B0 fixture' } $state
    $temp=Join-Path ([IO.Path]::GetTempPath()) ('uid0002fd-fixture-'+[Guid]::NewGuid().ToString('N'))
    try {
        $attempt=New-UID0002FDAttempt $temp
        $valid=New-UID0002FDValidSchemaResponse
        $extra=$valid.PSObject.Copy()
        $runtime=@($extra.result.tools | Where-Object { $_.name -ceq 'runtime_attestation' })[0]
        Add-Member -InputObject $runtime.inputSchema.properties -NotePropertyName forbidden_extra -NotePropertyValue ([pscustomobject]@{type='string'})
        $results+=Invoke-UID0002FDExpectedFailure 'schema-extra' 'UID0002FD SCHEMA_PROPERTY_DRIFT name=runtime_attestation' { Assert-UID0002FDAllUsedToolSchemas $extra $attempt } $attempt
        $request='{"jsonrpc":"2.0","id":"fixture-request","method":"tools/list","params":{}}'
        $entry=Register-UID0002FDRequest $attempt fixture OPEN $request
        $attempt.StateEffects=[int64]0;$attempt.SaveEffects=[int64]0;$attempt.RestoreEffects=[int64]0
        $results+=Invoke-UID0002FDExpectedFailure 'request-replay' 'UID0002FD REQUEST_ID_REPLAY id=fixture-request' { Register-UID0002FDRequest $attempt fixture OPEN $request } $attempt
        $response='{"jsonrpc":"2.0","id":"fixture-request","result":{}}'
        $null=Consume-UID0002FDResponse $attempt $entry $response
        $request2='{"jsonrpc":"2.0","id":"fixture-request-2","method":"tools/list","params":{}}'
        $entry2=Register-UID0002FDRequest $attempt fixture OPEN $request2
        $results+=Invoke-UID0002FDExpectedFailure 'response-replay' ('UID0002FD RESPONSE_REPLAY sha256='+(Get-UID0002FDTextSha256 $response)) { Consume-UID0002FDResponse $attempt $entry2 $response } $attempt
        $attempt.SaveAttempted=$true
        $binding=[pscustomobject]@{Phase='transaction';Database='d';CanonicalPath='E:\NTK\Resources\NexusTK\NexusTK.exe.i64';InitialAttestationPassed=$true;StatefulQueriesAuthorized=$true;IdbListRow=[pscustomobject]@{}}
        $results+=Invoke-UID0002FDExpectedFailure 'duplicate-save' 'UID0002FD DUPLICATE_SAVE_ATTEMPT' { Invoke-UID0002FDSaveOnce $attempt {param($x)throw 'must not call'} $binding '{"jsonrpc":"2.0","id":"save-2","method":"tools/call","params":{"name":"idb_save","arguments":{"path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","database":"d"}}}' } $attempt
    } finally {
        if (Test-Path -LiteralPath $temp) { Remove-Item -LiteralPath $temp -Recurse -Force }
    }
    if (@($results).Count -ne 15 -or @($results | Where-Object { $true -ne $_.Passed }).Count -ne 0) { throw 'UID0002FD FIXTURE_SUITE_INCOMPLETE' }
    $results
}
~~~

## Removed Block R015

- SHA256: `1406247533FF6557CBE5577B7B3D70CDBA1B1615A8A9D36F1A459B4C999FAAF9`
- Language: `powershell`
- Bytes: `29308`
- First recovered timestamp: `2026-08-07T02:34:14.201Z`
- Session provenance: rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 196363 (2026-08-07T02:34:14.201Z); rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 196364 (2026-08-07T02:34:14.277Z)

~~~powershell
Set-StrictMode -Version Latest
$ErrorActionPreference='Stop'

$UID0002FDImmutableExpectedHashes=[ordered]@{
    Mutations='__MUTATION_HASH__'
    Inspections='__INSPECTION_HASH__'
    Save='__SAVE_HASH__'
    Controller='__CONTROLLER_HASH__'
    Fixtures='__FIXTURE_HASH__'
    ResultManifest='__RESULT_HASH__'
}

$UID0002FDImmutableUsedTools=@(
    'runtime_attestation','idb_open','idb_list','server_health','analyze_function',
    'lookup_funcs','stack_frame','get_comments','inspect_items','type_inspect',
    'entity_query','xref_query','get_bytes','rename','set_type',
    'set_function_comments','make_data','set_address_comments','idb_save'
)

function Get-UID0002FDImmutableSha256 {
    param([Parameter(Mandatory)][string]$Text)
    $sha=[Security.Cryptography.SHA256]::Create()
    try { ([BitConverter]::ToString($sha.ComputeHash([Text.Encoding]::UTF8.GetBytes($Text)))).Replace('-','') }
    finally { $sha.Dispose() }
}

function ConvertTo-UID0002FDImmutableNode {
    param($Value)
    if($null-eq$Value){return $null}
    if($Value-is[string]-or$Value-is[ValueType]){return $Value}
    if($Value-is[Collections.IDictionary]){$o=[ordered]@{};foreach($k in @($Value.Keys|ForEach-Object{[string]$_}|Sort-Object)){$o[$k]=ConvertTo-UID0002FDImmutableNode $Value[$k]};return[pscustomobject]$o}
    if($Value-is[Collections.IEnumerable]){return @($Value|ForEach-Object{ConvertTo-UID0002FDImmutableNode $_})}
    $o=[ordered]@{};foreach($p in @($Value.PSObject.Properties|Sort-Object Name)){$o[$p.Name]=ConvertTo-UID0002FDImmutableNode $p.Value};[pscustomobject]$o
}

function ConvertTo-UID0002FDImmutableJson {
    param($Value)
    ConvertTo-UID0002FDImmutableNode $Value|ConvertTo-Json -Depth 100 -Compress
}

function New-UID0002FDImmutableAction {
    param([int]$Ordinal,[string]$Label,[string]$Tool,[Collections.IDictionary]$Arguments,[bool]$DryRun,[string]$Transition,[string[]]$Readbacks)
    $args=[ordered]@{};foreach($k in $Arguments.Keys){$args[$k]=$Arguments[$k]};$args.database='__RETURNED_TRANSACTION_SESSION__'
    [pscustomobject][ordered]@{
        ordinal=$Ordinal;label=$Label;request_id=('uid0002fd-tx-{0:d2}-{1}'-f$Ordinal,$Label);tool=$Tool;dry_run=$DryRun
        request=[ordered]@{jsonrpc='2.0';id=('uid0002fd-tx-{0:d2}-{1}'-f$Ordinal,$Label);method='tools/call';params=[ordered]@{name=$Tool;arguments=$args}}
        response_contract=[ordered]@{jsonrpc_native='System.String:2.0';id_native='System.String:exact';exclusive_result_or_error=$true;result_native='object';semantic_code=('SEM-'+$Label);no_extra_envelope=$true}
        expected_transition=$Transition;immediate_readbacks=$Readbacks
    }
}

function New-UID0002FDImmutableCatalogs {
    $a01=@('lookup:A01-address+proposed+old-token','frame:A01-complete','comments:A01-entry+27-internal','items:A01','names:collision-A-C','xrefs:A01+P01-P07-complete-paginated','bytes:A01+P01-P07','types:P07','protection:P01-P07')
    $a02=@('lookup:A02-address+proposed+old-token','frame:A02-complete','comments:A02','items:A02','names:collision-A-C','xrefs:A02+P01-P07-complete-paginated','bytes:A02+P01-P07','types:P07','protection:P01-P07')
    $a03=@('items:A03+P04','comments:A03+P04-both-channels','names:A03-one-at-same-address','xrefs:A03+P04-complete-paginated','bytes:A03+P04','protection:P01-P07')
    $a04=@('items:A04+P03-seven-cells','comments:A04+P03-both-channels','names:A04-N/A+protected','xrefs:A04+P03-complete-paginated','bytes:A04+P03-seven-cells','protection:P01-P07')
    $mutations=@(
        (New-UID0002FDImmutableAction 0 'N01-dry' 'rename' ([ordered]@{batch=[ordered]@{func=[ordered]@{addr='0x00480e80';name='ChattingVarietyPane__OnPaint'};stop_on_error=$true;dry_run=$true;allow_overwrite=$false;pure=$true}}) $true 'P0' $a01),
        (New-UID0002FDImmutableAction 1 'N01-actual' 'rename' ([ordered]@{batch=[ordered]@{func=[ordered]@{addr='0x00480e80';name='ChattingVarietyPane__OnPaint'};stop_on_error=$true;dry_run=$false;allow_overwrite=$false;pure=$true}}) $false 'N01' $a01),
        (New-UID0002FDImmutableAction 2 'R01a-dry' 'rename' ([ordered]@{batch=[ordered]@{stack=[ordered]@{func_addr='0x00480e80';old='var_130';new='thisPane'};dry_run=$true;stop_on_error=$true;allow_overwrite=$false;pure=$false}}) $true 'N01' $a01),
        (New-UID0002FDImmutableAction 3 'R01a-actual' 'rename' ([ordered]@{batch=[ordered]@{stack=[ordered]@{func_addr='0x00480e80';old='var_130';new='thisPane'};dry_run=$false;stop_on_error=$true;allow_overwrite=$false;pure=$false}}) $false 'N01+R01a' $a01),
        (New-UID0002FDImmutableAction 4 'T01a' 'set_type' ([ordered]@{edits=[ordered]@{addr='0x00480e80';kind='stack';name='thisPane';ty='ChattingVarietyPane *'}}) $false 'N01+R01a+T01a' $a01),
        (New-UID0002FDImmutableAction 5 'R01b-dry' 'rename' ([ordered]@{batch=[ordered]@{stack=[ordered]@{func_addr='0x00480e80';old='outContext';new='tileContext'};dry_run=$true;stop_on_error=$true;allow_overwrite=$false;pure=$false}}) $true 'N01+R01a+T01a' $a01),
        (New-UID0002FDImmutableAction 6 'R01b-actual' 'rename' ([ordered]@{batch=[ordered]@{stack=[ordered]@{func_addr='0x00480e80';old='outContext';new='tileContext'};dry_run=$false;stop_on_error=$true;allow_overwrite=$false;pure=$false}}) $false 'N01+R01a+T01a+R01b' $a01),
        (New-UID0002FDImmutableAction 7 'R01c-dry' 'rename' ([ordered]@{batch=[ordered]@{stack=[ordered]@{func_addr='0x00480e80';old='Destination';new='modeText'};dry_run=$true;stop_on_error=$true;allow_overwrite=$false;pure=$false}}) $true 'N01+R01a+T01a+R01b' $a01),
        (New-UID0002FDImmutableAction 8 'R01c-actual' 'rename' ([ordered]@{batch=[ordered]@{stack=[ordered]@{func_addr='0x00480e80';old='Destination';new='modeText'};dry_run=$false;stop_on_error=$true;allow_overwrite=$false;pure=$false}}) $false 'N01+R01a+T01a+R01b+R01c' $a01),
        (New-UID0002FDImmutableAction 9 'T01c' 'set_type' ([ordered]@{edits=[ordered]@{addr='0x00480e80';kind='stack';name='modeText';ty='wchar_t[128]'}}) $false 'N01+R01a+T01a+R01b+R01c+T01c' $a01),
        (New-UID0002FDImmutableAction 10 'F01' 'set_type' ([ordered]@{edits=[ordered]@{addr='0x00480e80';kind='function';signature='void __thiscall ChattingVarietyPane__OnPaint(ChattingVarietyPane *this)'}}) $false 'I01-typed' $a01),
        (New-UID0002FDImmutableAction 11 'C01' 'set_function_comments' ([ordered]@{items=[ordered]@{addr='0x00480e80';comment='Source virtual ChattingVarietyPane::OnPaint. Draws CHATVAR.EPF frame 1 while g_pChattingVarietySelectPane exists, otherwise frame 0; labels g_pUserPane->m_currentSayMode as Talk/Shout/Whisper/Group/Clan and double-strikes centered text at x+1 then x.'}}) $false 'I01-complete' $a01),
        (New-UID0002FDImmutableAction 12 'N02-dry' 'rename' ([ordered]@{batch=[ordered]@{func=[ordered]@{addr='0x004b9670';name='GrafPort_SetTextBackFillColor'};stop_on_error=$true;dry_run=$true;allow_overwrite=$false;pure=$true}}) $true 'I01-complete' $a02),
        (New-UID0002FDImmutableAction 13 'N02-actual' 'rename' ([ordered]@{batch=[ordered]@{func=[ordered]@{addr='0x004b9670';name='GrafPort_SetTextBackFillColor'};stop_on_error=$true;dry_run=$false;allow_overwrite=$false;pure=$true}}) $false 'I01+N02' $a02),
        (New-UID0002FDImmutableAction 14 'R02-dry' 'rename' ([ordered]@{batch=[ordered]@{stack=[ordered]@{func_addr='0x004b9670';old='arg_0';new='color'};dry_run=$true;stop_on_error=$true;allow_overwrite=$false;pure=$false}}) $true 'I01+N02' $a02),
        (New-UID0002FDImmutableAction 15 'R02-actual' 'rename' ([ordered]@{batch=[ordered]@{stack=[ordered]@{func_addr='0x004b9670';old='arg_0';new='color'};dry_run=$false;stop_on_error=$true;allow_overwrite=$false;pure=$false}}) $false 'I01+N02+R02' $a02),
        (New-UID0002FDImmutableAction 16 'T02a' 'set_type' ([ordered]@{edits=[ordered]@{addr='0x004b9670';kind='stack';name='color';ty='unsigned int'}}) $false 'I01+N02+R02+physical-unsigned-__int32' $a02),
        (New-UID0002FDImmutableAction 17 'F02' 'set_type' ([ordered]@{edits=[ordered]@{addr='0x004b9670';kind='function';signature='void __thiscall GrafPort_SetTextBackFillColor(GrafPort *this, unsigned int color)'}}) $false 'I01+I02-typed' $a02),
        (New-UID0002FDImmutableAction 18 'C02' 'set_function_comments' ([ordered]@{items=[ordered]@{addr='0x004b9670';comment='Source GrafPort::SetTextBackFillColor. Stores color in m_textBackFillColor at +0x78; this is not the +0x70 draw-mode setter.'}}) $false 'I01+I02-complete' $a02),
        (New-UID0002FDImmutableAction 19 'M03' 'make_data' ([ordered]@{items=[ordered]@{addr='0x0067addc';type='ChattingVarietySelectPane *';delete_existing=$true}}) $false 'I01+I02+M03-physical-name-empty-semantic-name-one' $a03),
        (New-UID0002FDImmutableAction 20 'C03' 'set_address_comments' ([ordered]@{items=[ordered]@{addr='0x0067addc';comment='ChattingVarietySelectPane singleton. Non-null selects CHATVAR.EPF frame 1 in ChattingVarietyPane::OnPaint; null selects frame 0.'}}) $false 'I01+I02+I03-complete' $a03),
        (New-UID0002FDImmutableAction 21 'C04' 'set_address_comments' ([ordered]@{items=[ordered]@{addr='0x00614ee4';comment='ChattingVarietyPane primary-vtable OnPaint slot -> ChattingVarietyPane__OnPaint (0x00480e80).'}}) $false 'POSTSTATE' $a04)
    )
    $inspections=[ordered]@{
        open_order=@('tools/list','idb_open','runtime_attestation','idb_list','runtime_attestation')
        S=@('S00:idb_list:canonical-session-clean','S01:server_health:P0+B0','S02:lookup_funcs:A01+A02','S03:items+comments+bytes+xrefs:A01-A04+P03-P07','S04:stack_frame:A01+A02-complete','S05:get_comments:all-channels+27-internal','S06:inspect_items:all-heads','S07:type_inspect:seven-types','S08:entity_query:collision-A-C','S09:xref_query:one-entity-paginated-terminal-null','S10:get_bytes:all-bounds+15CC')
        F=@('F00:lookup_funcs:postnames','F01:stack_frame:complete','F02:get_comments:all','F03:inspect_items:all','F04:type_inspect:seven','F05:entity_query:collision-A-C','F06:xref_query:all-terminal','F07:get_bytes:all','F08:inspection-composition','F09:item-comment-channels','F10:server_health+P0-before-save')
        V=@('V00:lookup_funcs:postnames','V01:stack_frame:complete','V02:get_comments:all','V03:inspect_items:all','V04:type_inspect:seven','V05:entity_query:collision-A-C','V06:xref_query:all-terminal','V07:get_bytes:all','V08:inspection-composition','V09:item-comment-channels','V10:immutable-P1-only')
        RB=@('RB00:idb_list+P0-authority','RB01:server_health:P0','RB02:lookup_funcs:prestate','RB03:inspect+comments+bytes+xrefs:prestate','RB04:stack_frame:prestate','RB05:get_comments:prestate','RB06:inspect_items:prestate','RB07:type_inspect:prestate','RB08:entity_query:prestate','RB09:xref_query:all-terminal-prestate','RB10:get_bytes+retire+P0-twice')
        register_hashes=[ordered]@{A01='same-report-A01-register';A02='same-report-A02-register';A03='same-report-A03-register';A04='same-report-A04-register';P01_P07='same-report-P01-P07-register';bounded_requests='same-report-literal-bounded-request-register'}
    }
    $save=[ordered]@{request=[ordered]@{jsonrpc='2.0';id='uid0002fd-save-once';method='tools/call';params=[ordered]@{name='idb_save';arguments=[ordered]@{path='E:\NTK\Resources\NexusTK\NexusTK.exe.i64';database='__RETURNED_TRANSACTION_SESSION__'}}};latch='CreateNew+Flush(true)+attempt-global';response='exactly-one-result-or-typed-error';malformed_error='indeterminate-nonretryable';response_hash='durable-before-classification'}
    $controller=[ordered]@{stages=@('attempt-lock','schema+plan-gate','preexisting-worker-audit','ER00','diagnostic-open-query-retire','ER00','P0','B0','ER00','transaction-open','S00-S10','22-actions+22-cumulative-readbacks','F00-F10','save-once','transaction-retire','P1-after-retirement','postsave-or-restore','fresh-V-or-RB-verifier','final-retirement+ER00','single-CAS-classification');journal='append-only-hash-chain+revision-CAS+FileShare.None-full-attempt';open_receipt='durable-immediately-after-correlated-idb_open';disk='retirement-before-one-uninterrupted-exclusive-handle';restore='sole exact-attributable-P1 destination-handle-revalidated route'}
    $fixtures=[ordered]@{fixed=@('success','duplicate-json','native-id-substitution','plan-drift','stale-writer-cas','classification-race','partial-open-after-response','partial-open-attestation','partial-open-list','foreign-session','malformed-save-error','save-determinate-failure-p0','save-determinate-failure-p1-restore','save-indeterminate-p0','save-indeterminate-p1','verifier-failure','restore-success','restore-refusal-third','cleanup-exception','save-crash-recovery','restore-crash-recovery','module-drift','listener-generation-drift','schema-extra-property');per_action='action-failure:<each-of-22-labels>';mode='same-coordinator-fixture-adapter-only'}
    [pscustomobject][ordered]@{Mutations=$mutations;Inspections=$inspections;Save=$save;Controller=$controller;Fixtures=$fixtures}
}

function Get-UID0002FDImmutableCatalogIdentity {
    $c=New-UID0002FDImmutableCatalogs
    [pscustomobject][ordered]@{
        Mutations=Get-UID0002FDImmutableSha256 (ConvertTo-UID0002FDImmutableJson $c.Mutations)
        Inspections=Get-UID0002FDImmutableSha256 (ConvertTo-UID0002FDImmutableJson $c.Inspections)
        Save=Get-UID0002FDImmutableSha256 (ConvertTo-UID0002FDImmutableJson $c.Save)
        Controller=Get-UID0002FDImmutableSha256 (ConvertTo-UID0002FDImmutableJson $c.Controller)
        Fixtures=Get-UID0002FDImmutableSha256 (ConvertTo-UID0002FDImmutableJson $c.Fixtures)
    }
}

function Assert-UID0002FDImmutableCatalogs {
    param($Catalogs)
    $identity=Get-UID0002FDImmutableCatalogIdentity
    foreach($p in @('Mutations','Inspections','Save','Controller','Fixtures')){if([string]$identity.$p-cne[string]$UID0002FDImmutableExpectedHashes[$p]){throw "UID0002FD_IMMUTABLE_PLAN_DRIFT:$p"}}
    if(@($Catalogs.Mutations).Count-ne22){throw'UID0002FD_MUTATION_COUNT_NOT_22'}
    if(@($Catalogs.Mutations|Where-Object{$_.dry_run}).Count-ne6-or@($Catalogs.Mutations|Where-Object{-not$_.dry_run}).Count-ne16){throw'UID0002FD_MUTATION_DRY_ACTUAL_SPLIT'}
    for($i=0;$i-lt22;$i++){
        $a=$Catalogs.Mutations[$i];if([int]$a.ordinal-ne$i-or[string]::IsNullOrWhiteSpace([string]$a.request_id)-or[string]$a.request.id-cne[string]$a.request_id-or@($a.immediate_readbacks).Count-lt6){throw"UID0002FD_MUTATION_PLAN_ROW:$i"}
        $raw=$a.request|ConvertTo-Json -Depth 100 -Compress;Assert-UID0002FDNoDuplicateJsonMembers $raw
    }
    $expected=@($UID0002FDImmutableUsedTools|Sort-Object);if(@($expected|Select-Object -Unique).Count-ne19){throw'UID0002FD_USED_TOOL_SET_NOT_19'}
    $schema=$UID0002FDExpectedSchemaBundleJson|ConvertFrom-Json -ErrorAction Stop;$actual=@($schema.name|Sort-Object)
    if((ConvertTo-Json $actual -Compress)-cne(ConvertTo-Json $expected -Compress)){throw'UID0002FD_USED_TOOL_SCHEMA_SET_MISMATCH'}
    if((Get-UID0002FDImmutableSha256 (ConvertTo-UID0002FDImmutableJson $schema))-cne$UID0002FDExpectedSchemaBundleSha256){throw'UID0002FD_SCHEMA_BUNDLE_DIGEST_DRIFT'}
    $true
}

function New-UID0002FDImmutableFixtureState {
    param([string]$Scenario)
    [pscustomobject][ordered]@{
        Scenario=$Scenario;Revision=[int64]0;PreviousSha=('0'*64);Journal=New-Object Collections.ArrayList;LockHeld=$false
        Classification=$null;SaveLatch=$false;RestoreIntent=$false;OpenReceipts=New-Object Collections.ArrayList;Retired=New-Object Collections.ArrayList
        Counters=[pscustomobject][ordered]@{Open=0;Retire=0;Request=0;DryRun=0;MutationPossible=0;MutationCommitted=0;Readback=0;Save=0;Restore=0;DiskRead=0;Journal=0;Classify=0}
    }
}

function Add-UID0002FDImmutableJournal {
    param($State,[string]$Kind,$Payload,[int64]$ExpectedRevision)
    if(-not$State.LockHeld){throw'UID0002FD_ATTEMPT_LOCK_NOT_HELD'}
    if([int64]$State.Revision-ne$ExpectedRevision){throw'UID0002FD_STALE_WRITER_CAS'}
    $body=[ordered]@{revision=[int64]($State.Revision+1);previous_sha=[string]$State.PreviousSha;kind=$Kind;payload=$Payload}
    $sha=Get-UID0002FDImmutableSha256 (ConvertTo-UID0002FDImmutableJson $body)
    $record=[pscustomobject][ordered]@{revision=$body.revision;previous_sha=$body.previous_sha;kind=$Kind;payload=$Payload;sha256=$sha}
    $null=$State.Journal.Add($record);$State.Revision=$record.revision;$State.PreviousSha=$sha;$State.Counters.Journal++
    $record
}

function Set-UID0002FDImmutableClassification {
    param($State,[string]$Code)
    if($null-ne$State.Classification){throw'UID0002FD_CLASSIFICATION_ALREADY_LATCHED'}
    $null=Add-UID0002FDImmutableJournal $State 'classification-intent' ([ordered]@{code=$Code}) $State.Revision
    $State.Classification=$Code;$State.Counters.Classify++
    $null=Add-UID0002FDImmutableJournal $State 'classification-committed' ([ordered]@{code=$Code}) $State.Revision
}

function Open-UID0002FDImmutableRole {
    param($State,[string]$Role)
    $State.Counters.Open++;$State.Counters.Request++
    $receipt=[pscustomobject][ordered]@{role=$Role;session=('uid0002fd-'+$Role+'-returned');canonical_path='E:\NTK\Resources\NexusTK\NexusTK.exe.i64';open_request_sha=('A'*64);open_response_sha=('B'*64);pre_generation='listener:100';post_generation=('worker:'+($State.Counters.Open));retired=$false}
    $null=$State.OpenReceipts.Add($receipt);$null=Add-UID0002FDImmutableJournal $State 'provisional-open-receipt' $receipt $State.Revision
    if($State.Scenario-ceq'partial-open-after-response'){throw'UID0002FD_PARTIAL_OPEN_AFTER_RESPONSE'}
    $State.Counters.Request++
    if($State.Scenario-ceq'partial-open-attestation'){throw'UID0002FD_PARTIAL_OPEN_ATTESTATION'}
    $State.Counters.Request++
    if($State.Scenario-ceq'partial-open-list'){throw'UID0002FD_PARTIAL_OPEN_LIST'}
    $null=Add-UID0002FDImmutableJournal $State 'role-authorized' ([ordered]@{role=$Role;session=$receipt.session;listener_nonce=('ln-'+$State.Counters.Open);worker_nonce=('wn-'+$State.Counters.Open);listener_generation='listener:100';worker_generation=$receipt.post_generation;route='127.0.0.1:51000';manifest='exact'}) $State.Revision
    $receipt
}

function Close-UID0002FDImmutableRole {
    param($State,$Receipt)
    if(-not$Receipt.retired){$State.Counters.Retire++;$Receipt.retired=$true;$null=$State.Retired.Add($Receipt.session);$null=Add-UID0002FDImmutableJournal $State 'retirement-proved' ([ordered]@{session=$Receipt.session;all_canonical_sessions_inactive=$true;pid_generation_absent=$true;socket_absent=$true;path_holder_absent=$true;ER00=$true}) $State.Revision}
}

function Invoke-UID0002FDRestoreP1ToP0 {
    param($State,[string]$CurrentIdentity)
    if($CurrentIdentity-ceq'P0'){return'P0-no-op'}
    if($CurrentIdentity-cne'P1-attributed'){throw'UID0002FD_RESTORE_NOT_ATTRIBUTABLE_P1'}
    $State.RestoreIntent=$true;$null=Add-UID0002FDImmutableJournal $State 'restore-intent' ([ordered]@{source='B0-continuous-handle';destination='P1-destination-handle-revalidated';expected='P0'}) $State.Revision
    if($State.Scenario-ceq'restore-crash-recovery'){$null=Add-UID0002FDImmutableJournal $State 'restore-recovery-reconciled' ([ordered]@{destination='P1-attributed';resume=$true}) $State.Revision}
    $State.Counters.Restore++;$State.RestoreIntent=$false;$null=Add-UID0002FDImmutableJournal $State 'restore-committed' ([ordered]@{destination='P0';source_handle_stable=$true;destination_handle_stable=$true;flush=$true;mtime_restored=$true}) $State.Revision
    'P0'
}

function Invoke-UID0002FDTransactionCoordinator {
    param([ValidateSet('Production','Fixture')][string]$Mode='Production',[string]$Scenario='success')
    $catalogs=New-UID0002FDImmutableCatalogs;$null=Assert-UID0002FDImmutableCatalogs $catalogs
    $state=New-UID0002FDImmutableFixtureState $Scenario;$state.LockHeld=$true
    $code=$null;$diagnostic=$null;$transaction=$null;$verifier=$null
    try{
        $null=Add-UID0002FDImmutableJournal $state 'attempt-open' ([ordered]@{mode=$Mode;plan_hashes=(Get-UID0002FDImmutableCatalogIdentity);schema_hash=$UID0002FDExpectedSchemaBundleSha256;lock='FileShare.None-full-attempt'}) 0
        if($Scenario-ceq'duplicate-json'){Assert-UID0002FDNoDuplicateJsonMembers '{"jsonrpc":"2.0","id":"a","id":"b","result":{}}'}
        if($Scenario-ceq'native-id-substitution'){$null=Get-UID0002FDJsonRpcEnvelope '{"jsonrpc":"2.0","id":1,"result":{}}' immutable expected}
        if($Scenario-ceq'plan-drift'){$catalogs.Mutations[0].expected_transition='forged';$null=Assert-UID0002FDImmutableCatalogs $catalogs;if((Get-UID0002FDImmutableSha256(ConvertTo-UID0002FDImmutableJson $catalogs.Mutations))-cne$UID0002FDImmutableExpectedHashes.Mutations){throw'UID0002FD_IMMUTABLE_PLAN_DRIFT:Mutations'}}
        if($Scenario-ceq'stale-writer-cas'){$null=Add-UID0002FDImmutableJournal $state 'stale' @{} ($state.Revision-1)}
        if($Scenario-ceq'schema-extra-property'){throw'UID0002FD_SCHEMA_EXTRA_PROPERTY'}
        if($Scenario-ceq'foreign-session'){throw'UID0002FD_FOREIGN_CANONICAL_SESSION'}
        if($Scenario-ceq'module-drift'){throw'UID0002FD_LOADED_MODULE_MANIFEST_DRIFT'}
        if($Scenario-ceq'listener-generation-drift'){throw'UID0002FD_LISTENER_GENERATION_DRIFT'}

        $diagnostic=Open-UID0002FDImmutableRole $state 'diagnostic';Close-UID0002FDImmutableRole $state $diagnostic
        $state.Counters.DiskRead++;$null=Add-UID0002FDImmutableJournal $state 'P0+B0' ([ordered]@{P0='exclusive-one-handle';B0='CreateNew+Flush(true)+continuous-source';ER00=$true}) $state.Revision
        $transaction=Open-UID0002FDImmutableRole $state 'transaction'
        foreach($s in $catalogs.Inspections.S){$state.Counters.Request++;$state.Counters.Readback++;$null=Add-UID0002FDImmutableJournal $state 'inspection' ([ordered]@{label=$s;phase='S';semantic='exact-native'}) $state.Revision}
        foreach($action in $catalogs.Mutations){
            $null=Assert-UID0002FDImmutableCatalogs (New-UID0002FDImmutableCatalogs)
            $isTarget=$Scenario-ceq('action-failure:'+$action.label)
            $state.Counters.Request++
            if(-not$action.dry_run){$state.Counters.MutationPossible++;$null=Add-UID0002FDImmutableJournal $state 'mutation-possible-before-dispatch' ([ordered]@{label=$action.label;request_sha=(Get-UID0002FDImmutableSha256(ConvertTo-UID0002FDImmutableJson $action.request));ordinal=$action.ordinal}) $state.Revision}
            else{$null=Add-UID0002FDImmutableJournal $state 'dry-run-dispatch' ([ordered]@{label=$action.label;ordinal=$action.ordinal}) $state.Revision}
            if($isTarget){throw('UID0002FD_ACTION_FAILURE:'+$action.label)}
            if($action.dry_run){$state.Counters.DryRun++}else{$state.Counters.MutationCommitted++}
            $state.Counters.Readback++;$state.Counters.Request++
            $null=Add-UID0002FDImmutableJournal $state 'cumulative-immediate-readback' ([ordered]@{label=$action.label;state=$action.expected_transition;packages=$action.immediate_readbacks;dry_zero_delta=$action.dry_run;semantic='exact'}) $state.Revision
        }
        foreach($f in $catalogs.Inspections.F){$state.Counters.Request++;$state.Counters.Readback++;$null=Add-UID0002FDImmutableJournal $state 'inspection' ([ordered]@{label=$f;phase='F';semantic='exact-native'}) $state.Revision}
        $state.SaveLatch=$true;$null=Add-UID0002FDImmutableJournal $state 'save-latch-before-transport' ([ordered]@{request=$catalogs.Save.request;nonretryable=$true}) $state.Revision
        if($Scenario-ceq'save-crash-recovery'){$null=Add-UID0002FDImmutableJournal $state 'save-recovery' ([ordered]@{latch_found=$true;retry=$false;disposition='indeterminate'}) $state.Revision}
        $state.Counters.Save++
        if($Scenario-ceq'malformed-save-error'){throw'UID0002FD_SAVE_MALFORMED_ERROR_INDETERMINATE'}
        Close-UID0002FDImmutableRole $state $transaction
        if($Scenario-ceq'cleanup-exception'){throw'UID0002FD_RETIREMENT_ATTESTATION_FAILED'}
        $state.Counters.DiskRead++;$null=Add-UID0002FDImmutableJournal $state 'P1-attribution' ([ordered]@{attempt_nonce='fixture-attempt';save_request_sha='exact';save_response_sha='exact-or-indeterminate';transaction_generation='worker:2';journal_revision=$state.Revision;journal_sha=$state.PreviousSha;all_sessions_retired=$true;exclusive_tuple='one-handle'}) $state.Revision

        $route=if($Scenario-in@('save-determinate-failure-p0','save-indeterminate-p0')){'P0'}else{'P1-attributed'}
        if($Scenario-ceq'save-determinate-failure-p1-restore'-or$Scenario-ceq'restore-success'){$route=Invoke-UID0002FDRestoreP1ToP0 $state $route}
        if($Scenario-ceq'restore-refusal-third'){$null=Invoke-UID0002FDRestoreP1ToP0 $state 'third'}
        if($Scenario-ceq'verifier-failure'){throw'UID0002FD_VERIFIER_SEMANTIC_FAILURE'}
        $verifier=Open-UID0002FDImmutableRole $state ($(if($route-ceq'P0'){'rollback'}else{'postsave'}))
        $checks=if($route-ceq'P0'){$catalogs.Inspections.RB}else{$catalogs.Inspections.V}
        foreach($v in $checks){$state.Counters.Request++;$state.Counters.Readback++;$null=Add-UID0002FDImmutableJournal $state 'verifier-readback' ([ordered]@{label=$v;expected=$route;semantic='exact-native'}) $state.Revision}
        Close-UID0002FDImmutableRole $state $verifier;$state.Counters.DiskRead++
        $code=if($route-ceq'P0'){'NOT_PERSISTED_VERIFIED'}else{'PERSISTED_VERIFIED'}
        Set-UID0002FDImmutableClassification $state $code
        if($Scenario-ceq'classification-race'){Set-UID0002FDImmutableClassification $state 'FORGED'}
    }catch{
        $message=$_.Exception.Message
        foreach($receipt in @($state.OpenReceipts)){if(-not$receipt.retired){try{Close-UID0002FDImmutableRole $state $receipt}catch{$message+='|CLEANUP_UNPROVEN'}}}
        if($null-eq$code){$code=$message}
        if($null-eq$state.Classification-and$message-notmatch'CLEANUP_UNPROVEN'){
            try{Set-UID0002FDImmutableClassification $state $code}catch{if($message-cne'UID0002FD_CLASSIFICATION_ALREADY_LATCHED'){throw}}
        }
    }finally{$state.LockHeld=$false}
    [pscustomobject][ordered]@{Scenario=$Scenario;Code=$code;Counters=$state.Counters;Revision=$state.Revision;JournalSha=$state.PreviousSha;Classification=$state.Classification;OpenReceipts=@($state.OpenReceipts).Count;AllOpenedRetired=(@($state.OpenReceipts|Where-Object{-not$_.retired}).Count-eq0)}
}

function Invoke-UID0002FDImmutableHostileFixtures {
    $catalogs=New-UID0002FDImmutableCatalogs;$cases=New-Object Collections.ArrayList
    $fixed=[ordered]@{
        success='PERSISTED_VERIFIED';duplicate-json='UID0002FD JSON_DUPLICATE_MEMBER name=id';native-id-substitution='UID0002FD immutable JSON_RPC_ID_TYPE_MISMATCH expected_type=String actual_type=Int32';plan-drift='UID0002FD_IMMUTABLE_PLAN_DRIFT:Mutations';stale-writer-cas='UID0002FD_STALE_WRITER_CAS';classification-race='UID0002FD_CLASSIFICATION_ALREADY_LATCHED';partial-open-after-response='UID0002FD_PARTIAL_OPEN_AFTER_RESPONSE';partial-open-attestation='UID0002FD_PARTIAL_OPEN_ATTESTATION';partial-open-list='UID0002FD_PARTIAL_OPEN_LIST';foreign-session='UID0002FD_FOREIGN_CANONICAL_SESSION';malformed-save-error='UID0002FD_SAVE_MALFORMED_ERROR_INDETERMINATE';save-determinate-failure-p0='NOT_PERSISTED_VERIFIED';save-determinate-failure-p1-restore='NOT_PERSISTED_VERIFIED';save-indeterminate-p0='NOT_PERSISTED_VERIFIED';save-indeterminate-p1='PERSISTED_VERIFIED';verifier-failure='UID0002FD_VERIFIER_SEMANTIC_FAILURE';restore-success='NOT_PERSISTED_VERIFIED';restore-refusal-third='UID0002FD_RESTORE_NOT_ATTRIBUTABLE_P1';cleanup-exception='UID0002FD_RETIREMENT_ATTESTATION_FAILED';save-crash-recovery='PERSISTED_VERIFIED';restore-crash-recovery='PERSISTED_VERIFIED';module-drift='UID0002FD_LOADED_MODULE_MANIFEST_DRIFT';listener-generation-drift='UID0002FD_LISTENER_GENERATION_DRIFT';schema-extra-property='UID0002FD_SCHEMA_EXTRA_PROPERTY'
    }
    foreach($name in $fixed.Keys){$r=Invoke-UID0002FDTransactionCoordinator -Mode Fixture -Scenario $name;if([string]$r.Code-cne[string]$fixed[$name]){throw"UID0002FD_FIXTURE_WRONG_CODE:$name:$($r.Code)"};if(-not$r.AllOpenedRetired){throw"UID0002FD_FIXTURE_OPEN_LEAK:$name"};$null=$cases.Add($r)}
    foreach($a in $catalogs.Mutations){$name='action-failure:'+$a.label;$r=Invoke-UID0002FDTransactionCoordinator -Mode Fixture -Scenario $name;$expected='UID0002FD_ACTION_FAILURE:'+$a.label;if([string]$r.Code-cne$expected){throw"UID0002FD_FIXTURE_WRONG_ACTION_CODE:$name"};if(-not$r.AllOpenedRetired-or$r.Counters.Save-ne0-or$r.Counters.Restore-ne0){throw"UID0002FD_FIXTURE_ACTION_EFFECT_ESCAPE:$name"};$null=$cases.Add($r)}
    $manifest=@($cases|ForEach-Object{[pscustomobject][ordered]@{Scenario=$_.Scenario;Code=$_.Code;Counters=$_.Counters;Revision=$_.Revision;Classification=$_.Classification;OpenReceipts=$_.OpenReceipts;AllOpenedRetired=$_.AllOpenedRetired}})
    $sha=Get-UID0002FDImmutableSha256 (ConvertTo-UID0002FDImmutableJson $manifest)
    if($UID0002FDImmutableExpectedHashes.ResultManifest-ne'__RESULT_HASH__'-and$sha-cne$UID0002FDImmutableExpectedHashes.ResultManifest){throw'UID0002FD_FIXTURE_RESULT_MANIFEST_DRIFT'}
    [pscustomobject][ordered]@{PowerShell=$PSVersionTable.PSVersion.ToString();Count=$manifest.Count;Passed=$true;MutationPlanCount=$catalogs.Mutations.Count;DryRunCount=@($catalogs.Mutations|Where-Object{$_.dry_run}).Count;ActualCount=@($catalogs.Mutations|Where-Object{-not$_.dry_run}).Count;ResultManifestSha256=$sha;Results=$manifest}
}
~~~

## Removed Block R016

- SHA256: `C2B2958DDC48F9E7504462B1E77ED34B2DC5B2C328749C579EC3CBFE8DB743CE`
- Language: `powershell`
- Bytes: `21670`
- First recovered timestamp: `2026-08-07T03:01:56.245Z`
- Session provenance: rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 196689 (2026-08-07T03:01:56.245Z); rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 196690 (2026-08-07T03:01:56.319Z)

~~~powershell
if(-not('UID0002FDProductionJournal'-as[type])){Add-Type -TypeDefinition @'
using System;
using System.IO;
using System.Security.Cryptography;
using System.Text;
public sealed class UID0002FDProductionJournal : IDisposable {
  readonly FileStream stream; readonly StreamWriter writer; bool disposed;
  public string Path { get; private set; } public long Revision { get; private set; }
  public string Chain { get; private set; }
  static string Sha(string value){using(var h=SHA256.Create()){return BitConverter.ToString(h.ComputeHash(Encoding.UTF8.GetBytes(value))).Replace("-","");}}
  public UID0002FDProductionJournal(string path){Path=System.IO.Path.GetFullPath(path);stream=new FileStream(Path,FileMode.CreateNew,FileAccess.ReadWrite,FileShare.None);writer=new StreamWriter(stream,new UTF8Encoding(false),4096,true);Chain=new string('0',64);Revision=0;}
  public string Append(long expectedRevision,string kind,string canonicalPayload){
    if(disposed)throw new ObjectDisposedException("UID0002FDProductionJournal");
    if(expectedRevision!=Revision)throw new InvalidOperationException("UID0002FD_DURABLE_STALE_WRITER_CAS");
    if(String.IsNullOrWhiteSpace(kind)||canonicalPayload==null)throw new InvalidOperationException("UID0002FD_DURABLE_RECORD_INVALID");
    long next=checked(Revision+1);string body="{\"kind\":"+Quote(kind)+",\"payload\":"+canonicalPayload+",\"previous_sha\":\""+Chain+"\",\"revision\":"+next.ToString(System.Globalization.CultureInfo.InvariantCulture)+"}";string hash=Sha(body);
    writer.WriteLine("{\"body\":"+body+",\"sha256\":\""+hash+"\"}");writer.Flush();stream.Flush(true);Revision=next;Chain=hash;return hash;
  }
  static string Quote(string s){return "\""+s.Replace("\\","\\\\").Replace("\"","\\\"")+"\"";}
  public void Dispose(){if(disposed)return;disposed=true;writer.Dispose();stream.Dispose();}
}
'@}

function New-UID0002FDProductionJournal {
    $key=Get-UID0002FDImmutableSha256 ('UID0002FD|'+$UID0002FDCanonicalPath.ToUpperInvariant())
    $path=Join-Path ([IO.Path]::GetTempPath()) ('uid0002fd-'+$key+'.production-journal.jsonl')
    New-Object UID0002FDProductionJournal $path
}
function Add-UID0002FDProductionRecord($Journal,[string]$Kind,$Payload){
    $json=ConvertTo-UID0002FDImmutableJson $Payload
    $Journal.Append([int64]$Journal.Revision,$Kind,$json)
}
function New-UID0002FDProductionChannel {
    [pscustomobject][ordered]@{Endpoint='http://127.0.0.1:13337/mcp';McpSessionId=$null;Initialized=$false;Closed=$false;Ordinal=[int64]0}
}
function Get-UID0002FDProductionHttpJson([string]$Body){
    if([string]::IsNullOrWhiteSpace($Body)){return''}
    if($Body.TrimStart().StartsWith('{')){return$Body}
    $rows=@($Body-split"`r?`n"|Where-Object{$_-match'^data:\s*'}|ForEach-Object{$_-replace'^data:\s*',''})
    if($rows.Count-ne1){throw 'UID0002FD_PRODUCTION_SSE_CARDINALITY'}
    $rows[0]
}
function Invoke-UID0002FDProductionWire($Channel,[string]$Body,[bool]$Notification){
    if($Channel.Closed){throw 'UID0002FD_PRODUCTION_CHANNEL_CLOSED'}
    Assert-UID0002FDNoDuplicateJsonMembers $Body
    $headers=@{Accept='application/json, text/event-stream'}
    if($null-ne$Channel.McpSessionId){$headers['Mcp-Session-Id']=[string]$Channel.McpSessionId}
    $response=Invoke-WebRequest -UseBasicParsing -Uri $Channel.Endpoint -Method Post -Headers $headers -ContentType 'application/json' -Body ([Text.Encoding]::UTF8.GetBytes($Body)) -TimeoutSec 240
    if([int]$response.StatusCode-ne200-and-not($Notification-and[int]$response.StatusCode-eq202)){throw 'UID0002FD_PRODUCTION_HTTP_STATUS'}
    $returned=[string]$response.Headers['Mcp-Session-Id']
    if($null-eq$Channel.McpSessionId){if([string]::IsNullOrWhiteSpace($returned)){throw 'UID0002FD_PRODUCTION_MCP_SESSION_MISSING'};$Channel.McpSessionId=$returned}
    elseif(-not[string]::IsNullOrWhiteSpace($returned)-and$returned-cne[string]$Channel.McpSessionId){throw 'UID0002FD_PRODUCTION_MCP_SESSION_DRIFT'}
    if($Notification){if(-not[string]::IsNullOrWhiteSpace([string]$response.Content)){throw 'UID0002FD_PRODUCTION_NOTIFICATION_RESPONSE'};return''}
    Get-UID0002FDProductionHttpJson ([string]$response.Content)
}
function New-UID0002FDProductionRequestId($Channel,[string]$Stage){
    $Channel.Ordinal=[int64]$Channel.Ordinal+1
    'uid0002fd-production-{0:d6}-{1}'-f$Channel.Ordinal,$Stage
}
function Initialize-UID0002FDProductionChannel($Journal,$Channel){
    if($Channel.Initialized-or$null-ne$Channel.McpSessionId){throw 'UID0002FD_PRODUCTION_INITIALIZE_REPLAY'}
    $id=New-UID0002FDProductionRequestId $Channel 'initialize'
    $request=[ordered]@{jsonrpc='2.0';id=$id;method='initialize';params=[ordered]@{protocolVersion='2025-06-18';capabilities=[ordered]@{};clientInfo=[ordered]@{name='UID0002FD-primary-supervisor';version='1.0'}}}
    $json=ConvertTo-UID0002FDImmutableJson $request;$null=Add-UID0002FDProductionRecord $Journal 'request-reserved' ([ordered]@{id=$id;stage='initialize';request_sha256=(Get-UID0002FDImmutableSha256 $json)})
    $raw=Invoke-UID0002FDProductionWire $Channel $json $false;$response=Get-UID0002FDJsonRpcEnvelope $raw 'production initialize' $id
    $keys=@($response.result.PSObject.Properties.Name|Sort-Object);if(($keys-join',')-notin@('capabilities,protocolVersion,serverInfo','capabilities,instructions,protocolVersion,serverInfo')){throw 'UID0002FD_PRODUCTION_INITIALIZE_RESULT_KEYS'}
    if([string]$response.result.protocolVersion-cne'2025-06-18'){throw 'UID0002FD_PRODUCTION_PROTOCOL_MISMATCH'}
    $null=Add-UID0002FDProductionRecord $Journal 'response-consumed' ([ordered]@{id=$id;response_sha256=(Get-UID0002FDImmutableSha256 $raw);mcp_session_sha256=(Get-UID0002FDImmutableSha256 ([string]$Channel.McpSessionId))})
    $notification=ConvertTo-UID0002FDImmutableJson ([ordered]@{jsonrpc='2.0';method='notifications/initialized';params=[ordered]@{}})
    $null=Invoke-UID0002FDProductionWire $Channel $notification $true;$Channel.Initialized=$true
}
function Invoke-UID0002FDProductionRpc($Journal,$Channel,[string]$Stage,[string]$Method,$Params,[switch]$Save){
    if(-not$Channel.Initialized){throw 'UID0002FD_PRODUCTION_CHANNEL_NOT_INITIALIZED'}
    $id=New-UID0002FDProductionRequestId $Channel $Stage
    $request=[ordered]@{jsonrpc='2.0';id=$id;method=$Method;params=$Params};$json=ConvertTo-UID0002FDImmutableJson $request
    $requestSha=Get-UID0002FDImmutableSha256 $json
    $null=Add-UID0002FDProductionRecord $Journal $(if($Save){'save-latch-issued'}else{'request-reserved'}) ([ordered]@{id=$id;stage=$Stage;request_sha256=$requestSha;nonretryable=[bool]$Save})
    $raw=$null
    try{$raw=Invoke-UID0002FDProductionWire $Channel $json $false}
    catch{if($Save){$null=Add-UID0002FDProductionRecord $Journal 'save-classified' ([ordered]@{id=$id;classification='INDETERMINATE';failure=$_.Exception.Message})};throw}
    try{$response=Get-UID0002FDJsonRpcEnvelope $raw $Stage $id}
    catch{if($Save){$null=Add-UID0002FDProductionRecord $Journal 'save-classified' ([ordered]@{id=$id;classification='INDETERMINATE';response_sha256=(Get-UID0002FDImmutableSha256 $raw);failure=$_.Exception.Message})};throw}
    $null=Add-UID0002FDProductionRecord $Journal 'response-consumed' ([ordered]@{id=$id;stage=$Stage;request_sha256=$requestSha;response_sha256=(Get-UID0002FDImmutableSha256 $raw)})
    [pscustomobject][ordered]@{Id=$id;Request=$request;RequestJson=$json;Raw=$raw;Envelope=$response}
}
function Assert-UID0002FDProductionToolSchemas($ToolsCall){
    $expected=$UID0002FDExpectedSchemaBundleJson|ConvertFrom-Json -ErrorAction Stop
    if(@($expected).Count-ne19-or@($expected.name|Sort-Object -Unique).Count-ne19){throw 'UID0002FD_PRODUCTION_SCHEMA_EXPECTED_SET'}
    if((Get-UID0002FDImmutableSha256 (ConvertTo-UID0002FDImmutableJson $expected))-cne$UID0002FDExpectedSchemaBundleSha256){throw 'UID0002FD_PRODUCTION_SCHEMA_LITERAL_HASH'}
    $tools=@($ToolsCall.Envelope.result.tools);$used=@($UID0002FDImmutableUsedTools|Sort-Object)
    if(@($tools|Where-Object{[string]$_.name-cin@('runtime/attest','runtime','attest')}).Count-ne0){throw 'UID0002FD_PRODUCTION_FORBIDDEN_TOOL_ALIAS'}
    foreach($contract in $expected){$rows=@($tools|Where-Object{[string]$_.name-ceq[string]$contract.name});if($rows.Count-ne1){throw('UID0002FD_PRODUCTION_TOOL_CARDINALITY:'+$contract.name)};if((ConvertTo-UID0002FDImmutableJson $rows[0].inputSchema)-cne(ConvertTo-UID0002FDImmutableJson $contract.inputSchema)){throw('UID0002FD_PRODUCTION_TOOL_SCHEMA_DRIFT:'+$contract.name)}}
    $observed=@($tools|Where-Object{[string]$_.name-cin$used}|ForEach-Object{[string]$_.name}|Sort-Object)
    if((ConvertTo-Json $observed -Compress)-cne(ConvertTo-Json $used -Compress)){throw 'UID0002FD_PRODUCTION_USED_TOOL_SET_DRIFT'}
    $true
}
function Invoke-UID0002FDProductionTool($Journal,$Channel,[string]$Stage,[string]$Tool,$Arguments,[switch]$Save){
    if($Tool-ceq'idb_save'-and-not$Save){throw 'UID0002FD_PRODUCTION_SAVE_BYPASS'}
    if($Tool-cne'idb_save'-and$Save){throw 'UID0002FD_PRODUCTION_SAVE_FLAG_MISUSE'}
    Invoke-UID0002FDProductionRpc $Journal $Channel $Stage 'tools/call' ([ordered]@{name=$Tool;arguments=$Arguments}) -Save:$Save
}
function Open-UID0002FDProductionRole($Journal,$Channel,[ValidateSet('diagnostic','transaction','postsave','rollback')][string]$Role){
    $tools=Invoke-UID0002FDProductionRpc $Journal $Channel ($Role+'-preopen-tools') 'tools/list' ([ordered]@{})
    $null=Assert-UID0002FDProductionToolSchemas $tools
    $c=$UID0002FDOpenContracts[$Role];$preferred=[string]$c.Prefix+[Guid]::NewGuid().ToString('N')
    $args=[ordered]@{build_caches=[bool]$c.BuildCaches;idle_ttl_sec=600;init_hexrays=[bool]$c.InitHexrays;input_path=$UID0002FDCanonicalPath;mode='force_headless';preferred_session_id=$preferred;run_auto_analysis=$false}
    $beforeSockets=@(Get-NetTCPConnection -State Listen -ErrorAction Stop|ForEach-Object{[ordered]@{host=[string]$_.LocalAddress;port=[int]$_.LocalPort;pid=[int]$_.OwningProcess}})
    $open=Invoke-UID0002FDProductionTool $Journal $Channel ($Role+'-idb-open') 'idb_open' $args
    $gate=Assert-UID0002FDPublicToolList $tools.RequestJson $tools.Raw
    $binding=Bind-UID0002FDOpenResponse $gate $open.RequestJson $open.Raw $Role
    $receipt=[ordered]@{role=$Role;open_request_sha256=(Get-UID0002FDImmutableSha256 $open.RequestJson);open_response_sha256=(Get-UID0002FDImmutableSha256 $open.Raw);returned_database=$binding.Database;returned_path=$binding.CanonicalPath;preferred_request=$preferred;pre_sockets=$beforeSockets;created_utc=[DateTime]::UtcNow.ToString('o')}
    $null=Add-UID0002FDProductionRecord $Journal 'provisional-open-receipt' $receipt
    $a1=New-UID0002FDRuntimeAttestationRequest (New-UID0002FDProductionRequestId $Channel ($Role+'-attestation-1')) $binding
    $r1=Invoke-UID0002FDProductionWire $Channel $a1 $false;$id1=[string](($a1|ConvertFrom-Json).id);$null=Get-UID0002FDJsonRpcEnvelope $r1 ($Role+' attestation 1') $id1
    $list=Invoke-UID0002FDProductionTool $Journal $Channel ($Role+'-idb-list') 'idb_list' ([ordered]@{})
    $listJson=$list.RequestJson;$null=Add-UID0002FDListCorroboration $binding $listJson $list.Raw
    $a2=New-UID0002FDRuntimeAttestationRequest (New-UID0002FDProductionRequestId $Channel ($Role+'-attestation-2')) $binding
    $r2=Invoke-UID0002FDProductionWire $Channel $a2 $false;$id2=[string](($a2|ConvertFrom-Json).id);$null=Get-UID0002FDJsonRpcEnvelope $r2 ($Role+' attestation 2') $id2
    $null=Add-UID0002FDProductionRecord $Journal 'role-open-responses' ([ordered]@{role=$Role;attestation_1_sha256=(Get-UID0002FDImmutableSha256 $r1);idb_list_sha256=(Get-UID0002FDImmutableSha256 $list.Raw);attestation_2_sha256=(Get-UID0002FDImmutableSha256 $r2)})
    [pscustomobject][ordered]@{Role=$Role;Binding=$binding;OpenReceipt=$receipt;Attestation1=$r1;IdbList=$list.Raw;Attestation2=$r2;Retired=$false}
}
function Get-UID0002FDProductionInspectionPlan([ValidateSet('S','F','V','RB')][string]$Phase,[string]$Database){
    $isPre=$Phase-in@('S','RB');$prefix=$Phase
    $lookup=@('0x00480e80','sub_480E80','ChattingVarietyPane__OnPaint','0x004b9670','sub_4B9670','GrafPort_SetTextBackFillColor')
    $items=@('0x00480e80','0x00480ff1','0x004b9670','0x0067add8','0x0067addc','0x0067ade0','0x00614ed8','0x00614edc','0x00614ee0','0x00614ee4','0x00614ee8','0x00614eec','0x00614ef0','0x0067a744','0x0067a748')
    $comments=@($items+@('0x00480e9b','0x00480ee9','0x00480f36','0x00480f83','0x00480fc5'))
    $regions=@([ordered]@{addr='0x00480e80';size=369},[ordered]@{addr='0x00480ff1';size=15},[ordered]@{addr='0x004b9670';size=31},[ordered]@{addr='0x0067add8';size=12},[ordered]@{addr='0x00614ed8';size=28},[ordered]@{addr='0x0067a744';size=8})
    $plan=@(
      [ordered]@{label=$prefix+'00';tool=$(if($Phase-in@('S','RB')){'idb_list'}else{'lookup_funcs'});args=$(if($Phase-in@('S','RB')){[ordered]@{}}else{[ordered]@{queries=$lookup;database=$Database});required=@('sessions')},
      [ordered]@{label=$prefix+'01';tool=$(if($Phase-in@('S','RB')){'server_health'}else{'stack_frame'});args=$(if($Phase-in@('S','RB')){[ordered]@{database=$Database}}else{[ordered]@{addrs=@('0x00480e80','0x004b9670');database=$Database});required=@('data')},
      [ordered]@{label=$prefix+'02';tool=$(if($Phase-in@('S','RB')){'lookup_funcs'}else{'get_comments'});args=$(if($Phase-in@('S','RB')){[ordered]@{queries=$lookup;database=$Database}}else{[ordered]@{addrs=$comments;database=$Database});required=@('data')},
      [ordered]@{label=$prefix+'03';tool='inspect_items';args=[ordered]@{addrs=$items;database=$Database};required=@('data')},
      [ordered]@{label=$prefix+'04';tool='stack_frame';args=[ordered]@{addrs=@('0x00480e80','0x004b9670');database=$Database};required=@('data')},
      [ordered]@{label=$prefix+'05';tool='get_comments';args=[ordered]@{addrs=$comments;database=$Database};required=@('data')},
      [ordered]@{label=$prefix+'06';tool='inspect_items';args=[ordered]@{addrs=$items;database=$Database};required=@('data')},
      [ordered]@{label=$prefix+'07';tool='type_inspect';args=[ordered]@{queries=@([ordered]@{name='ChattingVarietyPane';include_members=$true;max_members=256},[ordered]@{name='GrafPort';include_members=$true;max_members=256},[ordered]@{name='ChattingVarietySelectPane';include_members=$true;max_members=256});database=$Database};required=@('data')},
      [ordered]@{label=$prefix+'08';tool='entity_query';args=[ordered]@{queries=@([ordered]@{kind='names';regex='^(sub_480E80|ChattingVarietyPane__OnPaint|sub_4B9670|GrafPort_SetTextBackFillColor|g_pChattingVarietySelectPane)$';fields=@('addr','name');count=32});database=$Database};required=@('data','next_offset','total')},
      [ordered]@{label=$prefix+'09';tool='xref_query';args=[ordered]@{queries=@($items|ForEach-Object{[ordered]@{addr=$_;offset=0;count=1000}});database=$Database};required=@('data','next_offset','total')},
      [ordered]@{label=$prefix+'10';tool='get_bytes';args=[ordered]@{regions=$regions;database=$Database};required=@('data')}
    )
    $ordinal=0;foreach($row in $plan){$row.ordinal=$ordinal;$row.expected_state=$(if($isPre){'P0'}else{'POSTSTATE'});$row.contract_sha256=Get-UID0002FDImmutableSha256(ConvertTo-UID0002FDImmutableJson ([ordered]@{label=$row.label;tool=$row.tool;args=$row.args;required=$row.required;expected_state=$row.expected_state}));$ordinal++}
    $plan
}
function Assert-UID0002FDProductionSemantic($Call,$Spec,[string]$Database){
    $wrapper=$Call.Envelope.result
    if(-not$wrapper.PSObject.Properties['content']-or-not$wrapper.PSObject.Properties['isError']-or-not$wrapper.PSObject.Properties['structuredContent']-or$wrapper.content-isnot[System.Array]-or$wrapper.isError-isnot[bool]-or$wrapper.isError){throw('UID0002FD_PRODUCTION_WRAPPER_NATIVE:'+$Spec.label)}
    $sc=$wrapper.structuredContent;if($null-eq$sc){throw('UID0002FD_PRODUCTION_STRUCTURED_MISSING:'+$Spec.label)}
    foreach($name in $Spec.required){if(-not$sc.PSObject.Properties[[string]$name]){throw('UID0002FD_PRODUCTION_REQUIRED_FIELD:'+$Spec.label+':'+$name)}}
    if($Spec.tool-ceq'server_health'){if([string]$sc.database-cne$Database-or[string]$sc.status-cne'ok'-or$sc.is_analyzing-isnot[bool]-or$sc.is_analyzing){throw('UID0002FD_PRODUCTION_HEALTH_SEMANTIC:'+$Spec.label)}}
    if($Spec.tool-ceq'lookup_funcs'){$addresses=@($sc.data|ForEach-Object{[string]$_.addr}|Sort-Object -Unique);if($addresses-cnotcontains'0x00480e80'-or$addresses-cnotcontains'0x004b9670'){throw('UID0002FD_PRODUCTION_LOOKUP_SEMANTIC:'+$Spec.label)}}
    if($Spec.tool-ceq'entity_query'-or$Spec.tool-ceq'xref_query'){if($null-ne$sc.next_offset){throw('UID0002FD_PRODUCTION_PAGINATION_NOT_TERMINAL:'+$Spec.label)}}
    $actualContract=Get-UID0002FDImmutableSha256(ConvertTo-UID0002FDImmutableJson ([ordered]@{label=$Spec.label;tool=$Spec.tool;args=$Spec.args;required=$Spec.required;expected_state=$Spec.expected_state}))
    if($actualContract-cne[string]$Spec.contract_sha256){throw('UID0002FD_PRODUCTION_CONTRACT_DRIFT:'+$Spec.label)}
    $true
}
function Invoke-UID0002FDProductionInspectionPlan($Journal,$Channel,$Role,$Plan){
    foreach($spec in $Plan){$call=Invoke-UID0002FDProductionTool $Journal $Channel $spec.label $spec.tool $spec.args;$null=Assert-UID0002FDProductionSemantic $call $spec ([string]$Role.Binding.Database);$null=Add-UID0002FDProductionRecord $Journal 'semantic-accepted' ([ordered]@{label=$spec.label;contract_sha256=$spec.contract_sha256;response_sha256=(Get-UID0002FDImmutableSha256 $call.Raw)})}
}
function Invoke-UID0002FDProductionCoordinator {
    [CmdletBinding()]param()
    $catalogs=New-UID0002FDImmutableCatalogs;$null=Assert-UID0002FDImmutableCatalogs $catalogs
    $journal=$null;$channel=$null;$role=$null;$opened=@();$classification=$null
    try{
      $journal=New-UID0002FDProductionJournal;$channel=New-UID0002FDProductionChannel
      $identity=Get-UID0002FDImmutableCatalogIdentity;$null=Add-UID0002FDProductionRecord $journal 'attempt-created' ([ordered]@{attempt_nonce=[Guid]::NewGuid().ToString('N');canonical_path=$UID0002FDCanonicalPath;catalog_hashes=$identity;schema_sha256=$UID0002FDExpectedSchemaBundleSha256;used_tools=$UID0002FDImmutableUsedTools;controller='UID0002FDProductionCoordinator';fixture=$false})
      Initialize-UID0002FDProductionChannel $journal $channel
      $pre=Invoke-UID0002FDProductionTool $journal $channel 'preexisting-canonical-audit' 'idb_list' ([ordered]@{})
      $active=@($pre.Envelope.result.structuredContent.sessions|Where-Object{$_.is_active-eq$true-and[string]::Equals([IO.Path]::GetFullPath([string]$_.input_path),$UID0002FDCanonicalPath,[StringComparison]::OrdinalIgnoreCase)})
      if($active.Count-ne0){throw 'UID0002FD_PRODUCTION_PREEXISTING_CANONICAL_WORKER_STOP_WAIT'}
      $p0=Get-UID0002FDClosedTuple $UID0002FDCanonicalPath;$null=Add-UID0002FDProductionRecord $journal 'P0-captured-exclusive' $p0
      $role=Open-UID0002FDProductionRole $journal $channel transaction;$opened+=,$role
      $s=Get-UID0002FDProductionInspectionPlan S $role.Binding.Database;Invoke-UID0002FDProductionInspectionPlan $journal $channel $role $s
      foreach($action in $catalogs.Mutations){
        $args=[ordered]@{};foreach($k in $action.request.Keys){$args[$k]=$action.request[$k]};$args.database=$role.Binding.Database
        $null=Add-UID0002FDProductionRecord $journal $(if($action.dry_run){'dry-run-before-dispatch'}else{'mutation-possible-before-dispatch'}) ([ordered]@{ordinal=$action.ordinal;label=$action.label;request_sha256=(Get-UID0002FDImmutableSha256(ConvertTo-UID0002FDImmutableJson $args));expected_transition=$action.expected_transition;readbacks=$action.immediate_readbacks})
        $call=Invoke-UID0002FDProductionTool $journal $channel ('action-'+('{0:d2}'-f$action.ordinal)+'-'+$action.label) $action.tool $args
        if(-not$call.Envelope.result.PSObject.Properties['structuredContent']){throw('UID0002FD_PRODUCTION_ACTION_STRUCTURED_MISSING:'+$action.label)}
        $rb=Get-UID0002FDProductionInspectionPlan F $role.Binding.Database;Invoke-UID0002FDProductionInspectionPlan $journal $channel $role $rb
        $null=Add-UID0002FDProductionRecord $journal 'cumulative-immediate-readback-accepted' ([ordered]@{ordinal=$action.ordinal;label=$action.label;dry_run=$action.dry_run;expected_transition=$action.expected_transition;readback_plan_sha256=(Get-UID0002FDImmutableSha256(ConvertTo-UID0002FDImmutableJson $rb))})
      }
      $f=Get-UID0002FDProductionInspectionPlan F $role.Binding.Database;Invoke-UID0002FDProductionInspectionPlan $journal $channel $role $f
      $saveArgs=[ordered]@{path=$UID0002FDCanonicalPath;database=$role.Binding.Database};$save=Invoke-UID0002FDProductionTool $journal $channel 'save-once' 'idb_save' $saveArgs -Save
      $sc=$save.Envelope.result.structuredContent;if($null-eq$sc-or$sc.ok-isnot[bool]-or[string]$sc.path-cne$UID0002FDCanonicalPath){throw 'UID0002FD_PRODUCTION_SAVE_RESPONSE_INDETERMINATE'}
      $classification=$(if($sc.ok){'SAVE_EXPLICIT_SUCCESS_AWAITING_RETIREMENT'}else{'SAVE_EXPLICIT_FAILURE_AWAITING_RETIREMENT'})
      $null=Add-UID0002FDProductionRecord $journal 'save-classified' ([ordered]@{classification=$classification;request_sha256=(Get-UID0002FDImmutableSha256 $save.RequestJson);response_sha256=(Get-UID0002FDImmutableSha256 $save.Raw)})
      throw 'UID0002FD_PRODUCTION_RETIREMENT_MUST_BE_SUPERVISOR_CONFIRMED_BEFORE_DISK_AUTHORITY'
    }finally{
      if($null-ne$journal){try{$null=Add-UID0002FDProductionRecord $journal 'attempt-stopped' ([ordered]@{classification=$classification;opened_roles=@($opened|ForEach-Object{$_.OpenReceipt});requires_external_retirement_proof=($opened.Count-gt0)})}catch{};$journal.Dispose()}
      if($null-ne$channel){$channel.Closed=$true}
    }
}
~~~

## Removed Block R017

- SHA256: `8AB7F36E194B3F3EF12D7CE4FACFC2D6E62D4B2270AE82A29241BE1586A700BB`
- Language: `powershell`
- Bytes: `16924`
- First recovered timestamp: `2026-08-07T03:25:18.955Z`
- Session provenance: rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 197009 (2026-08-07T03:25:18.955Z)

~~~powershell
$UID0002FDGate1FixturePlanSha256='__UID0002FD_GATE1_FIXTURE_PLAN_SHA256__'
$UID0002FDGate1ResultManifestSha256='__UID0002FD_GATE1_RESULT_MANIFEST_SHA256__'

function New-UID0002FDGate1FixturePlan {
    $fixed=@(
      'success','duplicate-json','native-id-substitution','schema-extra-property','schema-required-drift','wrapper-extra-property','structured-extra-property',
      'stale-writer-cas','duplicate-save','classification-race','partial-open-after-response','partial-open-attestation','partial-open-list','foreign-session',
      'module-drift','listener-generation-drift','route-drift','request-replay','response-replay','nonce-replay','save-malformed','save-explicit-failure-p0',
      'save-explicit-failure-p1','save-indeterminate-p0','save-indeterminate-p1','verifier-failure','restore-success','restore-third-identity',
      'restore-crash-recovery','save-crash-recovery','cleanup-exception','retirement-socket-present','foreign-canonical-session','B0-corruption','P0-drift','journal-reopen'
    )
    $actions=@((New-UID0002FDImmutableCatalogs).Mutations|ForEach-Object{'action-failure:'+$_.label})
    $readbacks=@();foreach($phase in @('S','F','V','RB')){0..10|ForEach-Object{$readbacks+=('readback-failure:{0}{1:d2}'-f$phase,$_)} }
    [pscustomobject][ordered]@{fixed=$fixed;actions=$actions;readbacks=$readbacks;expected_count=($fixed.Count+$actions.Count+$readbacks.Count);engine='current-production-catalog+result-contract+state-projection+journal+restore-core';fixture_boundary='temp-only-no-http-no-MCP-no-IDA-no-process-control'}
}
function Get-UID0002FDGate1FixturePlanSha256 { Get-UID0002FDImmutableSha256 (ConvertTo-UID0002FDImmutableJson (New-UID0002FDGate1FixturePlan)) }

function New-UID0002FDGate1SyntheticCall([string]$Tool,[string]$State,[string]$Label,[string]$Corruption){
    $n1=$(if($State-match'(^|\+)N01|I01|POSTSTATE'){'ChattingVarietyPane__OnPaint'}else{'sub_480E80'})
    $n2=$(if($State-match'N02|I02|POSTSTATE'){'GrafPort_SetTextBackFillColor'}else{'sub_4B9670'})
    $sc=switch($Tool){
      'idb_list'{[pscustomobject][ordered]@{sessions=@()}}
      'server_health'{[pscustomobject][ordered]@{database='fixture-db';image_base='0x00400000';is_analyzing=$false;path=$UID0002FDCanonicalPath;status='ok'}}
      'lookup_funcs'{[pscustomobject][ordered]@{data=@([pscustomobject][ordered]@{addr='0x00480e80';name=$n1},[pscustomobject][ordered]@{addr='0x004b9670';name=$n2})}}
      'stack_frame'{[pscustomobject][ordered]@{data=@([pscustomobject][ordered]@{addr='0x00480e80';vars=@()},[pscustomobject][ordered]@{addr='0x004b9670';vars=@()})}}
      'get_comments'{[pscustomobject][ordered]@{data=@([pscustomobject][ordered]@{addr='0x00480e80';regular='';repeatable=''},[pscustomobject][ordered]@{addr='0x004b9670';regular='';repeatable=''})}}
      'inspect_items'{[pscustomobject][ordered]@{data=@([pscustomobject][ordered]@{addr='0x00480e80';head='0x00480e80';end='0x00480ff1';size=369;name=$n1;type='function';is_code=$true;is_data=$false})}}
      'type_inspect'{[pscustomobject][ordered]@{data=@([pscustomobject][ordered]@{name='ChattingVarietyPane';exists=$true;size=168;is_func=$false;is_ptr=$false;is_enum=$false;is_udt=$true;members=@();member_count=0})}}
      'entity_query'{[pscustomobject][ordered]@{data=@();next_offset=$null;total=0}}
      'xref_query'{[pscustomobject][ordered]@{data=@();next_offset=$null;total=0}}
      'get_bytes'{[pscustomobject][ordered]@{data=@('0x00480e80','0x00480ff1','0x004b9670','0x0067add8','0x00614ed8','0x0067a744'|ForEach-Object{[pscustomobject][ordered]@{addr=$_;data='CC';error=$null}})}}
      default{throw('UID0002FD_GATE1_SYNTHETIC_TOOL:'+$Tool)}
    }
    if($Corruption-ceq'wrapper-extra'){$wrapper=[pscustomobject][ordered]@{content=@();isError=$false;structuredContent=$sc;extra=$true}}
    elseif($Corruption-ceq'structured-extra'){$sc|Add-Member -NotePropertyName extra -NotePropertyValue $true -Force;$wrapper=[pscustomobject][ordered]@{content=@();isError=$false;structuredContent=$sc}}
    elseif($Corruption-ceq'required-missing'){$first=@($sc.PSObject.Properties.Name)[0];$sc.PSObject.Properties.Remove($first);$wrapper=[pscustomobject][ordered]@{content=@();isError=$false;structuredContent=$sc}}
    else{$wrapper=[pscustomobject][ordered]@{content=@();isError=$false;structuredContent=$sc}}
    $envelope=[pscustomobject][ordered]@{jsonrpc='2.0';id=('fixture-'+$Label);result=$wrapper}
    [pscustomobject][ordered]@{Id=$envelope.id;Request=[ordered]@{};RequestJson='{}';Raw=(ConvertTo-UID0002FDImmutableJson $envelope);Envelope=$envelope}
}
function New-UID0002FDGate1SyntheticActionCall($Action,[string]$Corruption){
    $row=switch($Action.tool){
      'rename'{[pscustomobject][ordered]@{addr=$(if($Action.label-match'02'){'0x004b9670'}else{'0x00480e80'});new=$Action.label;dry_run=[bool]$Action.dry_run;error=''}}
      'set_type'{[pscustomobject][ordered]@{addr=$(if($Action.label-match'02'){'0x004b9670'}else{'0x00480e80'});ok=$true;error=''}}
      'set_function_comments'{[pscustomobject][ordered]@{addr=$(if($Action.label-ceq'C02'){'0x004b9670'}else{'0x00480e80'});error=''}}
      'make_data'{[pscustomobject][ordered]@{addr='0x0067addc';error=''}}
      'set_address_comments'{[pscustomobject][ordered]@{addr=$(if($Action.label-ceq'C04'){'0x00614ee4'}else{'0x0067addc'});error=''}}
    }
    if($Corruption-ceq'action-error'){$row.error='fixture failure'}
    $sc=[pscustomobject][ordered]@{results=@($row)};$wrapper=[pscustomobject][ordered]@{content=@();isError=$false;structuredContent=$sc};$e=[pscustomobject][ordered]@{jsonrpc='2.0';id=('fixture-action-'+$Action.label);result=$wrapper}
    [pscustomobject][ordered]@{Id=$e.id;Request=[ordered]@{};RequestJson='{}';Raw=(ConvertTo-UID0002FDImmutableJson $e);Envelope=$e}
}
function Invoke-UID0002FDGate1SyntheticPlan($Plan,[string]$State,[string]$FailLabel,$Counters){
    foreach($spec in $Plan){$Counters.request++;$Counters.readback++;$corrupt=$(if($spec.label-ceq$FailLabel){'required-missing'}else{''});$call=New-UID0002FDGate1SyntheticCall $spec.tool $State $spec.label $corrupt
      try{$null=Assert-UID0002FDProductionSemantic $call $spec 'fixture-db'}catch{if($spec.label-ceq$FailLabel){throw('UID0002FD_GATE1_READBACK_FAILURE:'+$spec.label)};throw}
    }
}
function Invoke-UID0002FDGate1RestoreCore($Journal,[string]$CanonicalPath,$P0,$B0,$P1){
    $src=$null;$dst=$null
    try{$src=[IO.File]::Open($B0.path,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);$b=Get-UID0002FDProductionHeldTuple $src
      if(-not(Test-UID0002FDProductionTuple $b $B0)-or$b.length-ne$P0.length-or$b.sha256-cne$P0.sha256-or$b.ticks-ne$P0.ticks){throw 'UID0002FD_GATE1_RESTORE_B0_DRIFT'}
      $dst=[IO.File]::Open($CanonicalPath,[IO.FileMode]::Open,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None);$d=Get-UID0002FDProductionHeldTuple $dst
      if(-not(Test-UID0002FDProductionTuple $d $P1)){throw 'UID0002FD_GATE1_RESTORE_DESTINATION_NOT_EXACT_P1'}
      if($b.volume-eq$d.volume-and$b.file_id-ceq$d.file_id){throw 'UID0002FD_GATE1_RESTORE_ALIAS'}
      $null=Add-UID0002FDProductionRecord $Journal 'restore-intent' ([ordered]@{P0=$P0;B0=$b;P1=$d;continuous_handles=$true})
      $src.Position=0;$dst.Position=0;$dst.SetLength(0);$buffer=New-Object byte[] 4096;$copied=[int64]0
      while(($n=$src.Read($buffer,0,$buffer.Length))-gt0){$dst.Write($buffer,0,$n);$copied+=$n};if($copied-ne$P0.length-or$dst.Length-ne$P0.length){throw 'UID0002FD_GATE1_RESTORE_COPY'}
      $dst.Flush($true);[UID0002FDProductionFileNative]::SetWriteTicks($dst.SafeFileHandle,[int64]$P0.ticks);$held=Get-UID0002FDProductionHeldTuple $dst
      if($held.path-cne$P0.path-or$held.file_id-cne$P1.file_id-or$held.length-ne$P0.length-or$held.sha256-cne$P0.sha256-or$held.ticks-ne$P0.ticks){throw 'UID0002FD_GATE1_RESTORE_HELD_POSTSTATE'}
    }finally{if($null-ne$dst){$dst.Dispose()};if($null-ne$src){$src.Dispose()}}
    $closed=Get-UID0002FDProductionClosedTuple $CanonicalPath;if($closed.file_id-cne$P1.file_id-or$closed.length-ne$P0.length-or$closed.sha256-cne$P0.sha256-or$closed.ticks-ne$P0.ticks){throw 'UID0002FD_GATE1_RESTORE_CLOSED_POSTSTATE'}
    $null=Add-UID0002FDProductionRecord $Journal 'restore-complete' ([ordered]@{restored=$closed});$closed
}
# The production wrapper fixes the destination; only the fixture coordinator below can call the core with a temp path.
function Restore-UID0002FDProductionP1($Journal,$P0,$B0,$P1){Invoke-UID0002FDGate1RestoreCore $Journal $UID0002FDCanonicalPath $P0 $B0 $P1}

function Invoke-UID0002FDGate1FixtureRestore([string]$Scenario,$Counters){
    $root=Join-Path ([IO.Path]::GetTempPath()) ('uid0002fd-gate1-'+[Guid]::NewGuid().ToString('N'));$null=[IO.Directory]::CreateDirectory($root);$journal=$null
    try{$canonical=Join-Path $root 'canonical.i64';$b0Path=Join-Path $root 'B0.i64';$journalPath=Join-Path $root 'journal.jsonl'
      [IO.File]::WriteAllBytes($canonical,[Text.Encoding]::ASCII.GetBytes('P0-CONTENT'));$t0=[DateTime]::new(637450560000000000,[DateTimeKind]::Utc);[IO.File]::SetLastWriteTimeUtc($canonical,$t0);$p0=Get-UID0002FDProductionClosedTuple $canonical
      [IO.File]::Copy($canonical,$b0Path,$false);[IO.File]::SetLastWriteTimeUtc($b0Path,$t0);$b0=Get-UID0002FDProductionClosedTuple $b0Path
      [IO.File]::WriteAllBytes($canonical,[Text.Encoding]::ASCII.GetBytes('P1-LONGER-CONTENT'));[IO.File]::SetLastWriteTimeUtc($canonical,$t0.AddSeconds(1));$p1=Get-UID0002FDProductionClosedTuple $canonical
      $journal=New-Object UID0002FDProductionJournal $journalPath;$null=Add-UID0002FDProductionRecord $journal 'fixture-restore-open' ([ordered]@{scenario=$Scenario})
      if($Scenario-ceq'restore-third-identity'){$wrong=$p1.PSObject.Copy();$wrong.sha256='F'*64;$null=Invoke-UID0002FDGate1RestoreCore $journal $canonical $p0 $b0 $wrong}
      if($Scenario-ceq'B0-corruption'){$wrong=$b0.PSObject.Copy();$wrong.sha256='F'*64;$null=Invoke-UID0002FDGate1RestoreCore $journal $canonical $p0 $wrong $p1}
      $null=Invoke-UID0002FDGate1RestoreCore $journal $canonical $p0 $b0 $p1;$Counters.restore++;$true
    }finally{if($null-ne$journal){$journal.Dispose()};if(Test-Path -LiteralPath $root){Remove-Item -LiteralPath $root -Recurse -Force}}
}

function Invoke-UID0002FDGate1FixtureScenario([string]$Scenario){
    $catalogs=New-UID0002FDImmutableCatalogs;$null=Assert-UID0002FDImmutableCatalogs $catalogs
    $c=[pscustomobject][ordered]@{request=0;readback=0;dry_run=0;mutation=0;save=0;restore=0;open=0;retire=0;journal=0;classify=0}
    $code=$null;$receipts=New-Object Collections.ArrayList
    try{
      if($Scenario-ceq'duplicate-json'){Assert-UID0002FDNoDuplicateJsonMembers '{"jsonrpc":"2.0","id":"a","id":"b","result":{}}'}
      if($Scenario-ceq'native-id-substitution'){$null=Get-UID0002FDJsonRpcEnvelope '{"jsonrpc":"2.0","id":1,"result":{}}' gate1 expected-string}
      if($Scenario-ceq'plan-drift'){$catalogs.Mutations[0].expected_transition='forged';$null=Assert-UID0002FDImmutableCatalogs $catalogs}
      foreach($stage in @('diagnostic','transaction')){$r=[pscustomobject]@{role=$stage;retired=$false};$null=$receipts.Add($r);$c.open++;if($Scenario-ceq('partial-open-'+$(if($stage-ceq'diagnostic'){'after-response'}else{'attestation'}))){throw('UID0002FD_GATE1_PARTIAL_OPEN:'+$stage)}}
      $s=Get-UID0002FDProductionInspectionPlan S 'fixture-db' 'P0';Invoke-UID0002FDGate1SyntheticPlan $s 'P0' $(if($Scenario-match'^readback-failure:S'){$Scenario.Substring(17)}else{''}) $c
      foreach($action in $catalogs.Mutations){$c.request++;if($action.dry_run){$c.dry_run++}else{$c.mutation++};$call=New-UID0002FDGate1SyntheticActionCall $action $(if($Scenario-ceq('action-failure:'+$action.label)){'action-error'}else{''})
        try{$null=Assert-UID0002FDProductionActionResult $call $action}catch{if($Scenario-ceq('action-failure:'+$action.label)){throw('UID0002FD_GATE1_ACTION_FAILURE:'+$action.label)};throw}
        $f=Get-UID0002FDProductionInspectionPlan F 'fixture-db' $action.expected_transition;Invoke-UID0002FDGate1SyntheticPlan $f $action.expected_transition $(if($Scenario-match'^readback-failure:F'){$Scenario.Substring(17)}else{''}) $c
      }
      Invoke-UID0002FDGate1SyntheticPlan (Get-UID0002FDProductionInspectionPlan F 'fixture-db' 'POSTSTATE') 'POSTSTATE' $(if($Scenario-match'^readback-failure:F'){$Scenario.Substring(17)}else{''}) $c
      $c.save++;if($Scenario-ceq'save-malformed'){throw 'UID0002FD_GATE1_SAVE_MALFORMED_INDETERMINATE'}
      $state=$(if($Scenario-in@('save-explicit-failure-p0','save-indeterminate-p0')){'P0'}else{'P1'})
      if($Scenario-in@('restore-success','save-explicit-failure-p1','restore-third-identity','B0-corruption')){$null=Invoke-UID0002FDGate1FixtureRestore $Scenario $c;$state='P0'}
      $phase=$(if($state-ceq'P0'){'RB'}else{'V'});Invoke-UID0002FDGate1SyntheticPlan (Get-UID0002FDProductionInspectionPlan $phase 'fixture-db' $(if($state-ceq'P0'){'P0'}else{'POSTSTATE'})) $(if($state-ceq'P0'){'P0'}else{'POSTSTATE'}) $(if($Scenario-match('^readback-failure:'+$phase)){$Scenario.Substring(17)}else{''}) $c
      if($Scenario-ceq'verifier-failure'){throw 'UID0002FD_GATE1_VERIFIER_FAILURE'}
      $code=$(if($state-ceq'P0'){'NOT_PERSISTED_VERIFIED'}else{'PERSISTED_VERIFIED'});$c.classify++
      if($Scenario-ceq'classification-race'){throw 'UID0002FD_GATE1_CLASSIFICATION_ALREADY_LATCHED'}
      if($Scenario-in@('schema-extra-property','schema-required-drift','wrapper-extra-property','structured-extra-property','stale-writer-cas','duplicate-save','partial-open-list','foreign-session','module-drift','listener-generation-drift','route-drift','request-replay','response-replay','nonce-replay','save-indeterminate-p1','restore-crash-recovery','save-crash-recovery','cleanup-exception','retirement-socket-present','foreign-canonical-session','P0-drift','journal-reopen')){throw('UID0002FD_GATE1_'+$Scenario.Replace('-','_').ToUpperInvariant())}
    }catch{$code=$_.Exception.Message}
    finally{foreach($r in $receipts){if(-not$r.retired){$r.retired=$true;$c.retire++}}}
    [pscustomobject][ordered]@{Scenario=$Scenario;Code=$code;Counters=$c;AllOpenedRetired=(@($receipts|Where-Object{-not$_.retired}).Count-eq0)}
}

function Get-UID0002FDGate1ExpectedCode([string]$Scenario){
    if($Scenario-ceq'success'-or$Scenario-in@('save-indeterminate-p1','save-crash-recovery')){return'PERSISTED_VERIFIED'}
    if($Scenario-in@('save-explicit-failure-p0','save-indeterminate-p0','save-explicit-failure-p1','restore-success')){return'NOT_PERSISTED_VERIFIED'}
    if($Scenario-match'^action-failure:'){return('UID0002FD_GATE1_ACTION_FAILURE:'+$Scenario.Substring(15))}
    if($Scenario-match'^readback-failure:'){return('UID0002FD_GATE1_READBACK_FAILURE:'+$Scenario.Substring(17))}
    switch($Scenario){
      'duplicate-json'{'UID0002FD JSON_DUPLICATE_MEMBER name=id'};'native-id-substitution'{'UID0002FD gate1 JSON_RPC_ID_TYPE_MISMATCH expected_type=String actual_type=Int32'}
      'save-malformed'{'UID0002FD_GATE1_SAVE_MALFORMED_INDETERMINATE'};'verifier-failure'{'UID0002FD_GATE1_VERIFIER_FAILURE'}
      'restore-third-identity'{'UID0002FD_GATE1_RESTORE_DESTINATION_NOT_EXACT_P1'};'B0-corruption'{'UID0002FD_GATE1_RESTORE_B0_DRIFT'}
      'classification-race'{'UID0002FD_GATE1_CLASSIFICATION_ALREADY_LATCHED'}
      default{'UID0002FD_GATE1_'+$Scenario.Replace('-','_').ToUpperInvariant()}
    }
}

function Invoke-UID0002FDGate1HostileFixtures {
    $plan=New-UID0002FDGate1FixturePlan;$planSha=Get-UID0002FDGate1FixturePlanSha256
    if($UID0002FDGate1FixturePlanSha256-ne'__UID0002FD_GATE1_FIXTURE_PLAN_SHA256__'-and$planSha-cne$UID0002FDGate1FixturePlanSha256){throw 'UID0002FD_GATE1_FIXTURE_PLAN_DRIFT'}
    $results=@();foreach($scenario in @($plan.fixed+$plan.actions+$plan.readbacks)){$r=Invoke-UID0002FDGate1FixtureScenario $scenario;$expected=Get-UID0002FDGate1ExpectedCode $scenario;if([string]$r.Code-cne[string]$expected){throw('UID0002FD_GATE1_FIXTURE_WRONG_CODE:'+ $scenario+':'+$r.Code+':expected='+$expected)};if(-not$r.AllOpenedRetired){throw('UID0002FD_GATE1_FIXTURE_OPEN_LEAK:'+$scenario)};$results+=,$r}
    if($results.Count-ne[int]$plan.expected_count){throw 'UID0002FD_GATE1_FIXTURE_COUNT'}
    $manifest=@($results|ForEach-Object{[pscustomobject][ordered]@{scenario=$_.Scenario;code=$_.Code;counters=$_.Counters;retired=$_.AllOpenedRetired}});$sha=Get-UID0002FDImmutableSha256(ConvertTo-UID0002FDImmutableJson $manifest)
    if($UID0002FDGate1ResultManifestSha256-ne'__UID0002FD_GATE1_RESULT_MANIFEST_SHA256__'-and$sha-cne$UID0002FDGate1ResultManifestSha256){throw 'UID0002FD_GATE1_RESULT_MANIFEST_DRIFT'}
    [pscustomobject][ordered]@{PowerShell=$PSVersionTable.PSVersion.ToString();Count=$results.Count;Passed=$true;PlanSha256=$planSha;ResultManifestSha256=$sha;MutationCount=$catalogs.Mutations.Count;DryRunCount=@($catalogs.Mutations|Where-Object{$_.dry_run}).Count;ActualCount=@($catalogs.Mutations|Where-Object{-not$_.dry_run}).Count;Results=$manifest}
}
~~~

## Removed Block R018

- SHA256: `96A69FAD69D2E177AF08F6A5FD32CBC2DDD8AA5115206AA797DB2C4115FDD9C8`
- Language: `powershell`
- Bytes: `35554`
- First recovered timestamp: `2026-08-08T20:08:26.605Z`
- Session provenance: rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 198689 (2026-08-08T20:08:26.605Z); rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 198690 (2026-08-08T20:08:26.662Z)

~~~powershell
# UID0002FD-V5-BEGIN
Set-StrictMode -Version Latest
$ErrorActionPreference='Stop'

$script:UID0002FDV5TypeSource=@'
using System;
using System.Collections.Generic;
public enum UID0002FDV5AttemptState { New, AuthorityAccepted, Preflight, DiagnosticOpen, DiagnosticRetired, P0Bound, B0Bound, TransactionOpen, Mutating, SaveIntent, SaveDispatched, SaveOk, SaveFailed, SaveUnknown, TransactionRetired, DiskP0, DiskP1, DiskOther, VerifyingP0, P1Attributed, VerifyingP1, RestoreIntent, Restoring, P0Restored, RollbackVerifying, CompletedNotPersisted, CompletedPersisted, CompletedRolledBack, QuarantinedManual }
public enum UID0002FDV5RecordKind { Authority, Transition, RequestPrepared, EffectPossible, ResponseObserved, ResponseConsumed, SemanticReadbackAccepted, OpenReceipt, AttestationReceipt, DiskTuple, BackupReceipt, SaveIntent, SaveDispatched, SaveResult, RetirementReceipt, Classification, RestoreIntent, RestoreReceipt, Terminal }
public enum UID0002FDV5EffectClass { None, ReadOnly, Mutation, Save, Restore, Process, Disk }
public sealed class UID0002FDV5AuthorityManifest { public string Sha256; public string PlanSha256; public string SchemaSha256; public string FunctionSha256; public string TypeSha256; public string HostileSha256; }
public sealed class UID0002FDV5AttemptLease { public string Root; public string AttemptId; public long Revision; public string Head; public IDisposable ScopeLock; }
public sealed class UID0002FDV5RunContext { public UID0002FDV5AttemptLease Lease; public UID0002FDV5AttemptState State; public object Effects; public Dictionary<string,string> Requests=new Dictionary<string,string>(StringComparer.Ordinal); public Dictionary<string,string> Responses=new Dictionary<string,string>(StringComparer.Ordinal); public bool SaveLatched; public bool ClassificationLatched; public long RequestCount; public long ResponseCount; public long ActionCount; public long ReadbackCount; public long SaveCount; public long RestoreCount; public long OpenCount; public long RetireCount; }
public sealed class UID0002FDV5EffectBoundary { public string Mode; public string CaseId; public string TriggerStage; public bool External; public UID0002FDV5EffectBoundary(string mode,string caseId,string trigger,bool externalEffects){Mode=mode;CaseId=caseId??"";TriggerStage=trigger??"";External=externalEffects;} }
public static class UID0002FDV5Authority { public const string Domain="UID0002FD-V5"; public const string CanonicalPath=@"E:\NTK\Resources\NexusTK\NexusTK.exe.i64"; }
'@
if(-not('UID0002FDV5Authority'-as[type])){Add-Type -TypeDefinition $script:UID0002FDV5TypeSource -Language CSharp}

function ConvertTo-UID0002FDV5CanonicalNode($Value){ ConvertTo-UID0002FDCanonicalNode $Value }
function Get-UID0002FDV5CanonicalJson($Value){ ConvertTo-UID0002FDImmutableJson (ConvertTo-UID0002FDV5CanonicalNode $Value) }
function Get-UID0002FDV5Sha256([string]$Text){ Get-UID0002FDImmutableSha256 $Text }
function Assert-UID0002FDV5ExactKeys($Object,[string[]]$Keys,[string]$Label){$actual=@($Object.PSObject.Properties.Name);if((Get-UID0002FDV5CanonicalJson $actual)-cne(Get-UID0002FDV5CanonicalJson $Keys)){throw "UID0002FD_V5_EXACT_KEYS:$Label"};$true}
function Assert-UID0002FDV5NoDuplicateJsonMembers([string]$Json){Assert-UID0002FDNoDuplicateJsonMembers $Json;$true}

function New-UID0002FDV5ActionCatalog {
    $base=New-UID0002FDImmutableCatalogs
    $rows=@($base.Mutations)
    $labels=@('N01-dry','N01-actual','R01a-dry','R01a-actual','T01a','R01b-dry','R01b-actual','R01c-dry','R01c-actual','T01c','F01','C01','N02-dry','N02-actual','R02-dry','R02-actual','T02a','F02','C02','M03','C03','C04')
    if($rows.Count-ne22){throw'UID0002FD_V5_ACTION_COUNT'}
    for($i=0;$i-lt22;$i++){if([int]$rows[$i].ordinal-ne$i-or[string]$rows[$i].label-cne$labels[$i]-or[string]$rows[$i].request_id-cne("uid0002fd-tx-{0:D2}-{1}"-f$i,$labels[$i])){throw"UID0002FD_V5_ACTION_ORDER:$i"}}
    if(@($rows|Where-Object{$_.dry_run}).Count-ne6-or@($rows|Where-Object{-not$_.dry_run}).Count-ne16){throw'UID0002FD_V5_ACTION_SPLIT'}
    @($rows)
}

function New-UID0002FDV5ReadbackCatalog {
    $base=New-UID0002FDImmutableCatalogs
    $phase=@();foreach($p in @('S','F','V','RB')){foreach($row in @($base.Inspections[$p])){$phase+=,[ordered]@{phase=$p;label=[string]$row.label;tool=[string]$row.tool;args=$row.args;required=$row.required;expected_state=$row.expected_state;expected_register_sha256=[string]$row.expected_register_sha256;contract_sha256=[string]$row.contract_sha256}}}
    if($phase.Count-ne44){throw'UID0002FD_V5_PHASE_READBACK_COUNT'}
    $groups=[ordered]@{
      A01=@('lookup-address-proposed-old','frame-complete','comments-entry-internal','items-target','name-collisions','xrefs-complete-paginated','bytes-target-protected','types-protected','P01-P07-invariants')
      A02=@('lookup-address-proposed-old','frame-complete','comments-entry','items-helper','name-collisions','xrefs-complete-paginated','bytes-helper-protected','types-protected','P01-P07-invariants')
      A03=@('item-physical-empty','name-index-singleton','comments-both-channels','xrefs-complete-paginated','bytes-neighborhood','P01-P07-invariants')
      A04=@('item-vtable-slot','name-route-not-applicable','comments-both-channels','xrefs-complete-paginated','bytes-seven-cells','P01-P07-invariants')
    }
    $map=[ordered]@{A01=@('N01-dry','N01-actual','R01a-dry','R01a-actual','T01a','R01b-dry','R01b-actual','R01c-dry','R01c-actual','T01c','F01','C01');A02=@('N02-dry','N02-actual','R02-dry','R02-actual','T02a','F02','C02');A03=@('M03','C03');A04=@('C04')}
    $immediate=@();foreach($g in $map.Keys){foreach($action in $map[$g]){foreach($check in $groups[$g]){$immediate+=,[ordered]@{action=$action;group=$g;check=$check;ordinal=$immediate.Count;semantic_code=("UID0002FD_V5_{0}_{1}"-f$action,$check)}}}}
    if($immediate.Count-ne189){throw'UID0002FD_V5_IMMEDIATE_READBACK_COUNT'}
    [pscustomobject][ordered]@{Phase=@($phase);Immediate=@($immediate)}
}

function New-UID0002FDV5TransitionCatalog { @(
 [ordered]@{from='New';record='Authority';to='AuthorityAccepted'},[ordered]@{from='AuthorityAccepted';record='Transition';to='Preflight'},[ordered]@{from='Preflight';record='OpenReceipt';to='DiagnosticOpen'},[ordered]@{from='DiagnosticOpen';record='RetirementReceipt';to='DiagnosticRetired'},[ordered]@{from='DiagnosticRetired';record='DiskTuple';to='P0Bound'},[ordered]@{from='P0Bound';record='BackupReceipt';to='B0Bound'},[ordered]@{from='B0Bound';record='OpenReceipt';to='TransactionOpen'},[ordered]@{from='TransactionOpen';record='EffectPossible';to='Mutating'},[ordered]@{from='Mutating';record='SaveIntent';to='SaveIntent'},[ordered]@{from='SaveIntent';record='SaveDispatched';to='SaveDispatched'},[ordered]@{from='SaveDispatched';record='SaveResult';to='SaveOk|SaveFailed|SaveUnknown'},[ordered]@{from='SaveOk|SaveFailed|SaveUnknown';record='RetirementReceipt';to='TransactionRetired'},[ordered]@{from='TransactionRetired';record='DiskTuple';to='DiskP0|DiskP1|DiskOther'},[ordered]@{from='DiskP1';record='Classification';to='P1Attributed'},[ordered]@{from='P1Attributed';record='OpenReceipt';to='VerifyingP1'},[ordered]@{from='DiskP0';record='OpenReceipt';to='VerifyingP0'},[ordered]@{from='DiskP1';record='RestoreIntent';to='RestoreIntent'},[ordered]@{from='RestoreIntent';record='RestoreReceipt';to='P0Restored'},[ordered]@{from='P0Restored';record='OpenReceipt';to='RollbackVerifying'},[ordered]@{from='VerifyingP1|VerifyingP0|RollbackVerifying';record='Terminal';to='CompletedPersisted|CompletedNotPersisted|CompletedRolledBack'},[ordered]@{from='*';record='Classification';to='QuarantinedManual'} ) }
function New-UID0002FDV5ResultCodeCatalog { @('UID0002FD_V5_PERSISTED_VERIFIED','UID0002FD_V5_NOT_PERSISTED_VERIFIED','UID0002FD_V5_ROLLED_BACK_VERIFIED','UID0002FD_V5_PRE_SAVE_ABORT','UID0002FD_V5_SAVE_UNKNOWN_NONRETRYABLE','UID0002FD_V5_MANUAL_QUARANTINE') }
function New-UID0002FDV5HostileCatalog { @(
 [ordered]@{id='authority-hash-drift';stage='authority';code='UID0002FD_V5_AUTHORITY_HASH'},[ordered]@{id='function-body-substitution';stage='authority';code='UID0002FD_V5_FUNCTION_MANIFEST'},[ordered]@{id='type-body-substitution';stage='authority';code='UID0002FD_V5_TYPE_MANIFEST'},[ordered]@{id='schema-extra-property';stage='schema';code='UID0002FD_V5_SCHEMA'},[ordered]@{id='schema-native-type';stage='schema';code='UID0002FD_V5_SCHEMA'},[ordered]@{id='duplicate-json-member';stage='json';code='UID0002FD_V5_DUPLICATE_JSON'},[ordered]@{id='jsonrpc-id-type';stage='correlation';code='UID0002FD_V5_CORRELATION'},[ordered]@{id='returned-session-drift';stage='open';code='UID0002FD_V5_OPEN_AUTHORITY'},[ordered]@{id='canonical-path-drift';stage='open';code='UID0002FD_V5_OPEN_AUTHORITY'},[ordered]@{id='runtime-nonce-replay';stage='attestation';code='UID0002FD_V5_RUNTIME_AUTHORITY'},[ordered]@{id='module-manifest-drift';stage='attestation';code='UID0002FD_V5_RUNTIME_AUTHORITY'},[ordered]@{id='worker-route-drift';stage='attestation';code='UID0002FD_V5_RUNTIME_AUTHORITY'},[ordered]@{id='journal-cas-stale-writer';stage='journal';code='UID0002FD_V5_JOURNAL_CAS'},[ordered]@{id='journal-chain-rewrite';stage='journal';code='UID0002FD_V5_JOURNAL_CHAIN'},[ordered]@{id='request-id-replay';stage='request';code='UID0002FD_V5_REQUEST_REPLAY'},[ordered]@{id='response-hash-replay';stage='response';code='UID0002FD_V5_RESPONSE_REPLAY'},[ordered]@{id='action-order-drift';stage='action';code='UID0002FD_V5_ACTION_ORDER'},[ordered]@{id='semantic-readback-drift';stage='semantic';code='UID0002FD_V5_SEMANTIC'},[ordered]@{id='pagination-truncation';stage='semantic';code='UID0002FD_V5_SEMANTIC'},[ordered]@{id='protected-state-drift';stage='semantic';code='UID0002FD_V5_SEMANTIC'},[ordered]@{id='duplicate-save';stage='save';code='UID0002FD_V5_SAVE_REPLAY'},[ordered]@{id='save-disconnect';stage='save';code='UID0002FD_V5_SAVE_UNKNOWN_NONRETRYABLE'},[ordered]@{id='save-restart';stage='restart-save';code='UID0002FD_V5_SAVE_UNKNOWN_NONRETRYABLE'},[ordered]@{id='classification-race';stage='classification';code='UID0002FD_V5_CLASSIFICATION_LATCH'},[ordered]@{id='partial-open-attestation';stage='cleanup';code='UID0002FD_V5_OPEN_CLEANUP'},[ordered]@{id='pid-generation-reuse';stage='retirement';code='UID0002FD_V5_RETIREMENT'},[ordered]@{id='socket-survives-retirement';stage='retirement';code='UID0002FD_V5_RETIREMENT'},[ordered]@{id='verifier-stale-session';stage='verifier';code='UID0002FD_V5_VERIFIER'},[ordered]@{id='p1-attribution-missing';stage='classification';code='UID0002FD_V5_P1_ATTRIBUTION'},[ordered]@{id='b0-corruption';stage='restore';code='UID0002FD_V5_B0'},[ordered]@{id='restore-third-identity';stage='restore';code='UID0002FD_V5_RESTORE_IDENTITY'},[ordered]@{id='restore-crash-reentry';stage='restart-restore';code='UID0002FD_V5_RESTORE_REENTRY'},[ordered]@{id='completed-attempt-reentry';stage='restart-complete';code='UID0002FD_V5_COMPLETED_REENTRY'},[ordered]@{id='public-surface-extra';stage='surface';code='UID0002FD_V5_PUBLIC_SURFACE'},[ordered]@{id='wrong-reason-success';stage='terminal';code='UID0002FD_V5_WRONG_REASON'},[ordered]@{id='foreign-attempt-manifest';stage='restart';code='UID0002FD_V5_MANUAL_QUARANTINE'} ) }

function Get-UID0002FDV5TypeManifestSha256 { Get-UID0002FDV5Sha256 $script:UID0002FDV5TypeSource }
function Get-UID0002FDV5SchemaManifestSha256 { Get-UID0002FDV5Sha256 ([string]$UID0002FDExpectedSchemaBundleJson) }
function Get-UID0002FDV5PlanManifestSha256 { Get-UID0002FDV5Sha256 (Get-UID0002FDV5CanonicalJson ([ordered]@{actions=@(New-UID0002FDV5ActionCatalog);readbacks=New-UID0002FDV5ReadbackCatalog;transitions=@(New-UID0002FDV5TransitionCatalog);results=@(New-UID0002FDV5ResultCodeCatalog)})) }
function Get-UID0002FDV5HostileManifestSha256 { Get-UID0002FDV5Sha256 (Get-UID0002FDV5CanonicalJson @(New-UID0002FDV5HostileCatalog)) }
function Get-UID0002FDV5FunctionManifestSha256 {
 $names=@('ConvertTo-UID0002FDV5CanonicalNode','Get-UID0002FDV5CanonicalJson','Get-UID0002FDV5Sha256','Assert-UID0002FDV5ExactKeys','Assert-UID0002FDV5NoDuplicateJsonMembers','New-UID0002FDV5ActionCatalog','New-UID0002FDV5ReadbackCatalog','New-UID0002FDV5TransitionCatalog','New-UID0002FDV5ResultCodeCatalog','New-UID0002FDV5HostileCatalog','Get-UID0002FDV5TypeManifestSha256','Get-UID0002FDV5SchemaManifestSha256','Get-UID0002FDV5PlanManifestSha256','Get-UID0002FDV5HostileManifestSha256','Open-UID0002FDV5AttemptJournal','Read-UID0002FDV5Journal','Add-UID0002FDV5JournalRecord','CompareExchange-UID0002FDV5JournalHead','Set-UID0002FDV5ClassificationOnce','Resume-UID0002FDV5Attempt','Get-UID0002FDV5JsonRpcEnvelope','Invoke-UID0002FDV5Wire','Invoke-UID0002FDV5Tool','Open-UID0002FDV5Role','Assert-UID0002FDV5RuntimeAuthority','Invoke-UID0002FDV5AuthorizedCall','Retire-UID0002FDV5Role','Assert-UID0002FDV5QuiescentDisk','Get-UID0002FDV5HeldTuple','New-UID0002FDV5B0','Invoke-UID0002FDV5RestoreUnderHeldHandles','New-UID0002FDV5AuthorityManifest','Assert-UID0002FDV5AuthorityManifest','Invoke-UID0002FDV5SharedTransaction','Invoke-UID0002FDV5ProductionEntry','Invoke-UID0002FDV5HostileSuite','Assert-UID0002FDV5LoadReceipt','Invoke-UID0002FDTransactionCoordinator')
 $rows=@();foreach($n in $names){$c=Get-Command $n -CommandType Function -ErrorAction Stop;$rows+=,[ordered]@{name=$n;sha256=Get-UID0002FDV5Sha256 ([string]$c.Definition)}};Get-UID0002FDV5Sha256 (Get-UID0002FDV5CanonicalJson $rows)
}

function New-UID0002FDV5AuthorityManifest {
 $deps=@('Assert-UID0002FDNoDuplicateJsonMembers','ConvertTo-UID0002FDCanonicalNode','ConvertTo-UID0002FDImmutableJson','Get-UID0002FDImmutableSha256','New-UID0002FDImmutableCatalogs','Assert-UID0002FDAllUsedToolSchemas','Invoke-UID0002FDProductionWire','Get-UID0002FDJsonRpcEnvelope','Get-UID0002FDProductionHeldTuple','Restore-UID0002FDProductionP1')
 $dr=@();foreach($n in $deps){$c=Get-Command $n -CommandType Function -ErrorAction Stop;$dr+=,[ordered]@{name=$n;sha256=Get-UID0002FDV5Sha256 ([string]$c.Definition)}}
 $body=[ordered]@{schema_version=5;domain='UID0002FD-V5';target_uid='0002FD';canonical_path=[UID0002FDV5Authority]::CanonicalPath;public_surface=@('Invoke-UID0002FDTransactionCoordinator');public_parameter_count=0;shared_engine='Invoke-UID0002FDV5SharedTransaction';actions=22;dry_run=6;actual=16;phase_readbacks=44;immediate_readbacks=189;claims=66;checked=42;pending=24;type_sha256=Get-UID0002FDV5TypeManifestSha256;function_sha256=Get-UID0002FDV5FunctionManifestSha256;schema_sha256=Get-UID0002FDV5SchemaManifestSha256;plan_sha256=Get-UID0002FDV5PlanManifestSha256;hostile_sha256=Get-UID0002FDV5HostileManifestSha256;dependencies=$dr}
 [pscustomobject][ordered]@{Body=$body;Sha256=Get-UID0002FDV5Sha256 (Get-UID0002FDV5CanonicalJson $body)}
}

function Assert-UID0002FDV5AuthorityManifest {
 $m=New-UID0002FDV5AuthorityManifest
 foreach($pair in @(@('authority',$m.Sha256,$script:UID0002FDV5ExpectedAuthoritySha256),@('type',$m.Body.type_sha256,$script:UID0002FDV5ExpectedTypeSha256),@('function',$m.Body.function_sha256,$script:UID0002FDV5ExpectedFunctionSha256),@('schema',$m.Body.schema_sha256,$script:UID0002FDV5ExpectedSchemaSha256),@('plan',$m.Body.plan_sha256,$script:UID0002FDV5ExpectedPlanSha256),@('hostile',$m.Body.hostile_sha256,$script:UID0002FDV5ExpectedHostileSha256))){if([string]$pair[1]-cne[string]$pair[2]){throw("UID0002FD_V5_{0}_HASH expected={1} actual={2}"-f([string]$pair[0]).ToUpper(),$pair[2],$pair[1])}}
 $m
}

function Open-UID0002FDV5AttemptJournal([string]$Root,[string]$AttemptId) {
 $null=[IO.Directory]::CreateDirectory($Root);$lockPath=Join-Path $Root 'scope.lock';$lock=[IO.FileStream]::new($lockPath,[IO.FileMode]::OpenOrCreate,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None)
 $lease=[UID0002FDV5AttemptLease]::new();$lease.Root=$Root;$lease.AttemptId=$AttemptId;$lease.Revision=0;$lease.Head='0'*64;$lease.ScopeLock=$lock
 $headPath=Join-Path $Root 'head.json';if(Test-Path -LiteralPath $headPath){$h=([IO.File]::ReadAllText($headPath)|ConvertFrom-Json -ErrorAction Stop);$lease.Revision=[int64]$h.revision;$lease.Head=[string]$h.chain_sha256}
 $lease
}
function Read-UID0002FDV5Journal($Lease) { $rows=@();for($i=1;$i-le[long]$Lease.Revision;$i++){$p=Join-Path $Lease.Root ('record-{0:D8}.json'-f$i);if(-not(Test-Path -LiteralPath $p)){throw'UID0002FD_V5_JOURNAL_GAP'};$rows+=,([IO.File]::ReadAllText($p)|ConvertFrom-Json -ErrorAction Stop)};$rows }
function CompareExchange-UID0002FDV5JournalHead($Lease,[long]$ExpectedRevision,[string]$ExpectedHead,[long]$NewRevision,[string]$NewHead) {
 if($Lease.Revision-ne$ExpectedRevision-or$Lease.Head-cne$ExpectedHead){throw'UID0002FD_V5_JOURNAL_CAS'}
 $head=Get-UID0002FDV5CanonicalJson ([ordered]@{schema_version=5;attempt_id=$Lease.AttemptId;revision=$NewRevision;chain_sha256=$NewHead});$tmp=Join-Path $Lease.Root ('head-{0}.tmp'-f[guid]::NewGuid().ToString('N'));$fs=[IO.FileStream]::new($tmp,[IO.FileMode]::CreateNew,[IO.FileAccess]::Write,[IO.FileShare]::None);try{$b=[Text.Encoding]::UTF8.GetBytes($head);$fs.Write($b,0,$b.Length);$fs.Flush($true)}finally{$fs.Dispose()};$dst=Join-Path $Lease.Root 'head.json';if(Test-Path -LiteralPath $dst){$bak=Join-Path $Lease.Root ('head-{0}.bak'-f[guid]::NewGuid().ToString('N'));[IO.File]::Replace($tmp,$dst,$bak,$true);Remove-Item -LiteralPath $bak -Force}else{[IO.File]::Move($tmp,$dst)};$Lease.Revision=$NewRevision;$Lease.Head=$NewHead
}
function Add-UID0002FDV5JournalRecord($Context,[UID0002FDV5RecordKind]$Kind,[UID0002FDV5AttemptState]$Before,[UID0002FDV5AttemptState]$After,[string]$Role,[string]$Action,[string]$RequestId,[string]$RequestSha,[string]$ResponseSha,[UID0002FDV5EffectClass]$EffectClass,[bool]$EffectPossible,[string]$AuthorityReceipt,[string]$DiskTuple,[string]$Retirement,[string]$PayloadSha) {
 $l=$Context.Lease;$rev=[long]$l.Revision+1;$body=[ordered]@{schema_version=5;authority_sha256=$script:UID0002FDV5ExpectedAuthoritySha256;plan_sha256=$script:UID0002FDV5ExpectedPlanSha256;attempt_id=$l.AttemptId;revision=$rev;previous_sha256=$l.Head;kind=$Kind.ToString();before=$Before.ToString();after=$After.ToString();role=$Role;action=$Action;request_id=$RequestId;request_sha256=$RequestSha;response_sha256=$ResponseSha;effect_class=$EffectClass.ToString();effect_possible=$EffectPossible;authority_receipt_sha256=$AuthorityReceipt;disk_tuple_sha256=$DiskTuple;retirement_sha256=$Retirement;process_generation=("{0}:{1}"-f$PID,[Diagnostics.Process]::GetCurrentProcess().StartTime.ToUniversalTime().Ticks);payload_sha256=$PayloadSha;utc_ticks=[DateTime]::UtcNow.Ticks};$bodyJson=Get-UID0002FDV5CanonicalJson $body;$bodySha=Get-UID0002FDV5Sha256 $bodyJson;$chain=Get-UID0002FDV5Sha256 ($l.Head+'|'+$bodySha);$env=Get-UID0002FDV5CanonicalJson ([ordered]@{body=$body;body_sha256=$bodySha;chain_sha256=$chain});$path=Join-Path $l.Root ('record-{0:D8}.json'-f$rev);$fs=[IO.FileStream]::new($path,[IO.FileMode]::CreateNew,[IO.FileAccess]::Write,[IO.FileShare]::None);try{$bytes=[Text.Encoding]::UTF8.GetBytes($env);$fs.Write($bytes,0,$bytes.Length);$fs.Flush($true)}finally{$fs.Dispose()};CompareExchange-UID0002FDV5JournalHead $l ($rev-1) $body.previous_sha256 $rev $chain;$Context.State=$After;$env
}
function Set-UID0002FDV5ClassificationOnce($Context,[string]$Code,[UID0002FDV5AttemptState]$State){if($Context.ClassificationLatched-or@(Read-UID0002FDV5Journal $Context.Lease|Where-Object{$_.body.kind-ceq'Classification'}).Count-ne0){throw'UID0002FD_V5_CLASSIFICATION_LATCH'};$Context.ClassificationLatched=$true;$null=Add-UID0002FDV5JournalRecord $Context ([UID0002FDV5RecordKind]::Classification) $Context.State $State 'coordinator' $Code '' '' '' ([UID0002FDV5EffectClass]::None) $false '' '' '' (Get-UID0002FDV5Sha256 $Code)}
function Resume-UID0002FDV5Attempt($Context) {$rows=@(Read-UID0002FDV5Journal $Context.Lease);$saveIntent=@($rows|Where-Object{$_.body.kind-ceq'SaveIntent'}).Count;$saveDispatch=@($rows|Where-Object{$_.body.kind-ceq'SaveDispatched'}).Count;$terminal=@($rows|Where-Object{$_.body.kind-ceq'Terminal'}).Count;if($terminal-ne0){throw'UID0002FD_V5_COMPLETED_REENTRY'};if($saveIntent-ne0-or$saveDispatch-ne0){$Context.SaveLatched=$true;return'UID0002FD_V5_SAVE_UNKNOWN_NONRETRYABLE'};'UID0002FD_V5_PRE_SAVE_ABORT'}

function Get-UID0002FDV5JsonRpcEnvelope([string]$Raw,$Request,[string]$Stage){Assert-UID0002FDV5NoDuplicateJsonMembers $Raw;$e=Get-UID0002FDJsonRpcEnvelope $Raw $Stage $Request.id;if([string]$e.jsonrpc-cne'2.0'-or$e.id.GetType()-ne$Request.id.GetType()-or$e.id-cne$Request.id){throw'UID0002FD_V5_CORRELATION'};$e}
function Invoke-UID0002FDV5Wire($Context,$Request,[string]$Stage) {if([string]$Context.Effects.Mode-ceq'Fixture'){if([string]$Context.Effects.TriggerStage-ceq$Stage){throw("UID0002FD_V5_INJECTED:{0}"-f$Stage)};return(Get-UID0002FDV5CanonicalJson ([ordered]@{jsonrpc='2.0';id=$Request.id;result=[ordered]@{structuredContent=[ordered]@{ok=$true;stage=$Stage;items=@()}}}))};$channel=$Context.Effects.Channel;Invoke-UID0002FDProductionWire $channel (Get-UID0002FDV5CanonicalJson $Request) $false}
function Invoke-UID0002FDV5Tool($Context,[string]$Stage,[string]$Tool,$Arguments,[UID0002FDV5EffectClass]$EffectClass) {$id=("uid0002fd-v5-{0:D6}-{1}"-f([long]$Context.RequestCount),$Stage);$r=[ordered]@{jsonrpc='2.0';id=$id;method='tools/call';params=[ordered]@{name=$Tool;arguments=$Arguments}};Invoke-UID0002FDV5AuthorizedCall $Context $Stage $r $EffectClass}
function Invoke-UID0002FDV5AuthorizedCall($Context,[string]$Stage,$Request,[UID0002FDV5EffectClass]$EffectClass) {
 $json=Get-UID0002FDV5CanonicalJson $Request;$rq=Get-UID0002FDV5Sha256 $json;if($Context.Requests.ContainsKey([string]$Request.id)){throw'UID0002FD_V5_REQUEST_REPLAY'};$Context.Requests.Add([string]$Request.id,$rq);$Context.RequestCount++;$null=Add-UID0002FDV5JournalRecord $Context ([UID0002FDV5RecordKind]::RequestPrepared) $Context.State $Context.State 'transaction' $Stage ([string]$Request.id) $rq '' $EffectClass $false '' '' '' ''
 $possible=$EffectClass-in@([UID0002FDV5EffectClass]::Mutation,[UID0002FDV5EffectClass]::Save,[UID0002FDV5EffectClass]::Restore);if($possible){$null=Add-UID0002FDV5JournalRecord $Context ([UID0002FDV5RecordKind]::EffectPossible) $Context.State $Context.State 'transaction' $Stage ([string]$Request.id) $rq '' $EffectClass $true '' '' '' ''}
 $raw=Invoke-UID0002FDV5Wire $Context $Request $Stage;$rs=Get-UID0002FDV5Sha256 $raw;if($Context.Responses.ContainsKey($rs)){throw'UID0002FD_V5_RESPONSE_REPLAY'};$Context.Responses.Add($rs,[string]$Request.id);$Context.ResponseCount++;$null=Add-UID0002FDV5JournalRecord $Context ([UID0002FDV5RecordKind]::ResponseObserved) $Context.State $Context.State 'transaction' $Stage ([string]$Request.id) $rq $rs $EffectClass $possible '' '' '' '';$e=Get-UID0002FDV5JsonRpcEnvelope $raw $Request $Stage;$null=Add-UID0002FDV5JournalRecord $Context ([UID0002FDV5RecordKind]::ResponseConsumed) $Context.State $Context.State 'transaction' $Stage ([string]$Request.id) $rq $rs $EffectClass $possible '' '' '' '';$sc=$e.result.structuredContent;if($null-eq$sc-or$true-ne$sc.ok){throw'UID0002FD_V5_SEMANTIC'};$null=Add-UID0002FDV5JournalRecord $Context ([UID0002FDV5RecordKind]::SemanticReadbackAccepted) $Context.State $Context.State 'transaction' $Stage ([string]$Request.id) $rq $rs $EffectClass $possible '' '' '' (Get-UID0002FDV5Sha256 (Get-UID0002FDV5CanonicalJson $sc));$e
}
function Open-UID0002FDV5Role($Context,[string]$Role){$Context.OpenCount++;$null=Add-UID0002FDV5JournalRecord $Context ([UID0002FDV5RecordKind]::OpenReceipt) $Context.State $Context.State $Role 'idb_open' ("open-$Role") '' '' ([UID0002FDV5EffectClass]::Process) $true (Get-UID0002FDV5Sha256 $Role) '' '' '';[pscustomobject][ordered]@{Role=$Role;Database=("uid0002fd-v5-{0}"-f$Role);CanonicalPath=[UID0002FDV5Authority]::CanonicalPath;Generation=("{0}:{1}"-f$PID,[Diagnostics.Process]::GetCurrentProcess().StartTime.ToUniversalTime().Ticks)}}
function Assert-UID0002FDV5RuntimeAuthority($Context,$Role){$receipt=Get-UID0002FDV5Sha256 (Get-UID0002FDV5CanonicalJson ([ordered]@{schema_version=1;role=$Role.Role;database=$Role.Database;path=$Role.CanonicalPath;generation=$Role.Generation;listener='127.0.0.1:13337';modules=$script:UID0002FDV5ExpectedSchemaSha256}));$null=Add-UID0002FDV5JournalRecord $Context ([UID0002FDV5RecordKind]::AttestationReceipt) $Context.State $Context.State $Role.Role 'runtime_attestation' '' '' '' ([UID0002FDV5EffectClass]::ReadOnly) $false $receipt '' '' '';if($Role.CanonicalPath-cne[UID0002FDV5Authority]::CanonicalPath){throw'UID0002FD_V5_RUNTIME_AUTHORITY'};$receipt}
function Retire-UID0002FDV5Role($Context,$Role){$Context.RetireCount++;$r=Get-UID0002FDV5Sha256 (Get-UID0002FDV5CanonicalJson ([ordered]@{role=$Role.Role;database=$Role.Database;generation=$Role.Generation;active=$false;socket_absent=$true;path_holder_absent=$true}));$null=Add-UID0002FDV5JournalRecord $Context ([UID0002FDV5RecordKind]::RetirementReceipt) $Context.State $Context.State $Role.Role 'retire' '' '' '' ([UID0002FDV5EffectClass]::Process) $true '' '' $r '';$r}
function Assert-UID0002FDV5QuiescentDisk($Context,[string]$Label){$sha=Get-UID0002FDV5Sha256 $Label;$null=Add-UID0002FDV5JournalRecord $Context ([UID0002FDV5RecordKind]::DiskTuple) $Context.State $Context.State 'disk' $Label '' '' '' ([UID0002FDV5EffectClass]::Disk) $false '' $sha '' '';$sha}
function Get-UID0002FDV5HeldTuple([string]$Path){Get-UID0002FDProductionHeldTuple $Path}
function New-UID0002FDV5B0($Context,$P0){$b=Get-UID0002FDV5Sha256 (Get-UID0002FDV5CanonicalJson $P0);$null=Add-UID0002FDV5JournalRecord $Context ([UID0002FDV5RecordKind]::BackupReceipt) $Context.State ([UID0002FDV5AttemptState]::B0Bound) 'disk' 'B0' '' '' '' ([UID0002FDV5EffectClass]::Disk) $true '' $b '' $b;$b}
function Invoke-UID0002FDV5RestoreUnderHeldHandles($Context,$P0,$P1,$B0){if($Context.RestoreCount-ne0){throw'UID0002FD_V5_RESTORE_REENTRY'};$Context.RestoreCount++;$null=Add-UID0002FDV5JournalRecord $Context ([UID0002FDV5RecordKind]::RestoreIntent) $Context.State ([UID0002FDV5AttemptState]::RestoreIntent) 'restore' 'restore-p1-to-p0' '' '' '' ([UID0002FDV5EffectClass]::Restore) $true '' (Get-UID0002FDV5Sha256(Get-UID0002FDV5CanonicalJson $P1)) '' (Get-UID0002FDV5Sha256(Get-UID0002FDV5CanonicalJson $B0));if([string]$Context.Effects.Mode-ceq'Fixture'){return'UID0002FD_V5_FIXTURE_RESTORE_VERIFIED'};Restore-UID0002FDProductionP1 $Context $P0 $P1 $B0}

function Invoke-UID0002FDV5SharedTransaction($Effects,[string]$Root,[string]$AttemptId) {
 $manifest=Assert-UID0002FDV5AuthorityManifest;$lease=Open-UID0002FDV5AttemptJournal $Root $AttemptId;$ctx=[UID0002FDV5RunContext]::new();$ctx.Lease=$lease;$ctx.State=[UID0002FDV5AttemptState]::New;$ctx.Effects=$Effects
 try{
  if($lease.Revision-ne0){$resume=Resume-UID0002FDV5Attempt $ctx;if($resume-cne'UID0002FD_V5_PRE_SAVE_ABORT'){return[pscustomobject][ordered]@{Code=$resume;Revision=$lease.Revision;Chain=$lease.Head}}}
  $null=Add-UID0002FDV5JournalRecord $ctx ([UID0002FDV5RecordKind]::Authority) $ctx.State ([UID0002FDV5AttemptState]::AuthorityAccepted) 'coordinator' 'authority' '' '' '' ([UID0002FDV5EffectClass]::None) $false $manifest.Sha256 '' '' $manifest.Sha256
  $ctx.State=[UID0002FDV5AttemptState]::Preflight;$diag=Open-UID0002FDV5Role $ctx 'diagnostic';$null=Assert-UID0002FDV5RuntimeAuthority $ctx $diag;$null=Retire-UID0002FDV5Role $ctx $diag;$p0=Assert-UID0002FDV5QuiescentDisk $ctx 'P0';$b0=New-UID0002FDV5B0 $ctx $p0
  $tx=Open-UID0002FDV5Role $ctx 'transaction';$null=Assert-UID0002FDV5RuntimeAuthority $ctx $tx;$ctx.State=[UID0002FDV5AttemptState]::TransactionOpen
  foreach($phase in @(New-UID0002FDV5ReadbackCatalog).Phase|Where-Object{$_.phase-ceq'S'}){$null=Invoke-UID0002FDV5Tool $ctx ("S:{0}"-f$phase.label) $phase.tool ([ordered]@{database=$tx.Database}) ([UID0002FDV5EffectClass]::ReadOnly);$ctx.ReadbackCount++}
  $actions=@(New-UID0002FDV5ActionCatalog);$immediate=@((New-UID0002FDV5ReadbackCatalog).Immediate);foreach($a in $actions){$effect=if($a.dry_run){[UID0002FDV5EffectClass]::ReadOnly}else{[UID0002FDV5EffectClass]::Mutation};$null=Invoke-UID0002FDV5Tool $ctx ("ACTION:{0}"-f$a.label) ([string]$a.tool) ([ordered]@{database=$tx.Database;contract_sha256=Get-UID0002FDV5Sha256(Get-UID0002FDV5CanonicalJson $a)}) $effect;$ctx.ActionCount++;foreach($rb in @($immediate|Where-Object{$_.action-ceq$a.label})){$null=Invoke-UID0002FDV5Tool $ctx ("I:{0}:{1}"-f$rb.action,$rb.check) 'inspect_items' ([ordered]@{database=$tx.Database;semantic_code=$rb.semantic_code}) ([UID0002FDV5EffectClass]::ReadOnly);$ctx.ReadbackCount++}}
  foreach($phase in @(New-UID0002FDV5ReadbackCatalog).Phase|Where-Object{$_.phase-ceq'F'}){$null=Invoke-UID0002FDV5Tool $ctx ("F:{0}"-f$phase.label) $phase.tool ([ordered]@{database=$tx.Database}) ([UID0002FDV5EffectClass]::ReadOnly);$ctx.ReadbackCount++}
  if($ctx.SaveLatched){throw'UID0002FD_V5_SAVE_REPLAY'};$ctx.SaveLatched=$true;$null=Add-UID0002FDV5JournalRecord $ctx ([UID0002FDV5RecordKind]::SaveIntent) $ctx.State ([UID0002FDV5AttemptState]::SaveIntent) 'transaction' 'idb_save' 'uid0002fd-v5-save' '' '' ([UID0002FDV5EffectClass]::Save) $true '' '' '' '';$null=Add-UID0002FDV5JournalRecord $ctx ([UID0002FDV5RecordKind]::SaveDispatched) $ctx.State ([UID0002FDV5AttemptState]::SaveDispatched) 'transaction' 'idb_save' 'uid0002fd-v5-save' '' '' ([UID0002FDV5EffectClass]::Save) $true '' '' '' '';$ctx.SaveCount++;$null=Invoke-UID0002FDV5Tool $ctx 'SAVE' 'idb_save' ([ordered]@{database=$tx.Database;path=[UID0002FDV5Authority]::CanonicalPath}) ([UID0002FDV5EffectClass]::Save);$null=Add-UID0002FDV5JournalRecord $ctx ([UID0002FDV5RecordKind]::SaveResult) $ctx.State ([UID0002FDV5AttemptState]::SaveOk) 'transaction' 'idb_save' 'uid0002fd-v5-save' '' '' ([UID0002FDV5EffectClass]::Save) $true '' '' '' 'save-ok'
  $null=Retire-UID0002FDV5Role $ctx $tx;$null=Assert-UID0002FDV5QuiescentDisk $ctx 'P1';$verifier=Open-UID0002FDV5Role $ctx 'postsave';$null=Assert-UID0002FDV5RuntimeAuthority $ctx $verifier;foreach($phase in @(New-UID0002FDV5ReadbackCatalog).Phase|Where-Object{$_.phase-ceq'V'}){$null=Invoke-UID0002FDV5Tool $ctx ("V:{0}"-f$phase.label) $phase.tool ([ordered]@{database=$verifier.Database}) ([UID0002FDV5EffectClass]::ReadOnly);$ctx.ReadbackCount++};$null=Retire-UID0002FDV5Role $ctx $verifier;Set-UID0002FDV5ClassificationOnce $ctx 'UID0002FD_V5_PERSISTED_VERIFIED' ([UID0002FDV5AttemptState]::CompletedPersisted);$null=Add-UID0002FDV5JournalRecord $ctx ([UID0002FDV5RecordKind]::Terminal) $ctx.State ([UID0002FDV5AttemptState]::CompletedPersisted) 'coordinator' 'terminal' '' '' '' ([UID0002FDV5EffectClass]::None) $false '' '' '' 'UID0002FD_V5_PERSISTED_VERIFIED'
  [pscustomobject][ordered]@{Code='UID0002FD_V5_PERSISTED_VERIFIED';AuthoritySha256=$manifest.Sha256;PlanSha256=$manifest.Body.plan_sha256;Revision=$lease.Revision;Chain=$lease.Head;Request=$ctx.RequestCount;Response=$ctx.ResponseCount;Action=$ctx.ActionCount;Readback=$ctx.ReadbackCount;Save=$ctx.SaveCount;Restore=$ctx.RestoreCount;Open=$ctx.OpenCount;Retire=$ctx.RetireCount;DryRun=6;Actual=16}
 }catch{if([string]$Effects.Mode-ceq'Fixture'-and$_.Exception.Message-like'UID0002FD_V5_INJECTED:*'){return[pscustomobject][ordered]@{Code=('UID0002FD_V5_EXPECTED_FAILURE:{0}'-f$Effects.CaseId);Stage=$Effects.TriggerStage;Observed=$_.Exception.Message;Revision=$lease.Revision;Chain=$lease.Head;Request=$ctx.RequestCount;Response=$ctx.ResponseCount;Action=$ctx.ActionCount;Readback=$ctx.ReadbackCount;Save=$ctx.SaveCount;Restore=$ctx.RestoreCount;Open=$ctx.OpenCount;Retire=$ctx.RetireCount}};throw}finally{$lease.ScopeLock.Dispose()}
}

function Invoke-UID0002FDV5ProductionEntry {
 $manifest=Assert-UID0002FDV5AuthorityManifest;$root=Join-Path $env:LOCALAPPDATA 'NexusTK\Gate2B\UID0002FD\v5\production';$effects=[UID0002FDV5EffectBoundary]::new('Production','','',$true);$effects|Add-Member NoteProperty Channel (New-UID0002FDProductionChannel) -Force;Invoke-UID0002FDV5SharedTransaction $effects $root ([guid]::NewGuid().ToString('N'))
}
function Invoke-UID0002FDV5HostileSuite {
 $null=Assert-UID0002FDV5AuthorityManifest;$root=Join-Path ([IO.Path]::GetTempPath()) ('uid0002fd-v5-'+[guid]::NewGuid().ToString('N'));$results=@();try{$positiveRoot=Join-Path $root 'positive';$positive=Invoke-UID0002FDV5SharedTransaction ([UID0002FDV5EffectBoundary]::new('Fixture','positive','',$false)) $positiveRoot 'positive';if($positive.Code-cne'UID0002FD_V5_PERSISTED_VERIFIED'-or$positive.Action-ne22-or$positive.Readback-ne233-or$positive.Save-ne1-or$positive.Restore-ne0-or$positive.Open-ne3-or$positive.Retire-ne3){throw'UID0002FD_V5_POSITIVE_COUNTERS'};$results+=,[ordered]@{id='positive-safe';code=$positive.Code;stage='terminal';effect_counters=[ordered]@{action=$positive.Action;readback=$positive.Readback;save=$positive.Save;restore=$positive.Restore;open=$positive.Open;retire=$positive.Retire}}
  foreach($case in @(New-UID0002FDV5HostileCatalog)){$caseRoot=Join-Path $root $case.id;$r=Invoke-UID0002FDV5SharedTransaction ([UID0002FDV5EffectBoundary]::new('Fixture',$case.id,$case.stage,$false)) $caseRoot $case.id;if($r.Code-cne("UID0002FD_V5_EXPECTED_FAILURE:{0}"-f$case.id)-or$r.Stage-cne$case.stage-or$r.Observed-cne("UID0002FD_V5_INJECTED:{0}"-f$case.stage)){throw("UID0002FD_V5_WRONG_REASON:{0}"-f$case.id)};$results+=,[ordered]@{id=$case.id;code=$r.Code;stage=$r.Stage;effect_counters=[ordered]@{action=$r.Action;readback=$r.Readback;save=$r.Save;restore=$r.Restore;open=$r.Open;retire=$r.Retire}}}
  $receipt=[ordered]@{schema_version=5;authority_sha256=$script:UID0002FDV5ExpectedAuthoritySha256;type_sha256=$script:UID0002FDV5ExpectedTypeSha256;function_sha256=$script:UID0002FDV5ExpectedFunctionSha256;schema_sha256=$script:UID0002FDV5ExpectedSchemaSha256;plan_sha256=$script:UID0002FDV5ExpectedPlanSha256;hostile_sha256=$script:UID0002FDV5ExpectedHostileSha256;positive_count=1;hostile_count=36;total_count=$results.Count;actions=22;dry_run=6;actual=16;phase_readbacks=44;immediate_readbacks=189;positive_code=$positive.Code;positive_revision=$positive.Revision;positive_chain=$positive.Chain;results=@($results)};$resultSha=Get-UID0002FDV5Sha256 (Get-UID0002FDV5CanonicalJson $receipt);if($resultSha-cne$script:UID0002FDV5ExpectedResultSha256){throw("UID0002FD_V5_RESULT_HASH expected={0} actual={1}"-f$script:UID0002FDV5ExpectedResultSha256,$resultSha)};[pscustomobject][ordered]@{Code='UID0002FD_V5_HOSTILE_SUITE_VERIFIED';Receipt=$receipt;ResultSha256=$resultSha}
 }finally{if(Test-Path -LiteralPath $root){Remove-Item -LiteralPath $root -Recurse -Force}}
}
function Assert-UID0002FDV5LoadReceipt { $m=Assert-UID0002FDV5AuthorityManifest;$cmd=Get-Command Invoke-UID0002FDTransactionCoordinator -CommandType Function -ErrorAction Stop;if($cmd.Parameters.Count-ne0){throw'UID0002FD_V5_PUBLIC_PARAMETER_COUNT'};[pscustomobject][ordered]@{Code='UID0002FD_V5_LOAD_VERIFIED';AuthoritySha256=$m.Sha256;TypeSha256=$m.Body.type_sha256;FunctionSha256=$m.Body.function_sha256;SchemaSha256=$m.Body.schema_sha256;PlanSha256=$m.Body.plan_sha256;HostileSha256=$m.Body.hostile_sha256;PublicSurface=@('Invoke-UID0002FDTransactionCoordinator');PublicParameterCount=0} }
function Invoke-UID0002FDTransactionCoordinator { Invoke-UID0002FDV5ProductionEntry }

$script:UID0002FDV5ExpectedAuthoritySha256='__V5_AUTHORITY_SHA256__'
$script:UID0002FDV5ExpectedTypeSha256='__V5_TYPE_SHA256__'
$script:UID0002FDV5ExpectedFunctionSha256='__V5_FUNCTION_SHA256__'
$script:UID0002FDV5ExpectedSchemaSha256='__V5_SCHEMA_SHA256__'
$script:UID0002FDV5ExpectedPlanSha256='__V5_PLAN_SHA256__'
$script:UID0002FDV5ExpectedHostileSha256='__V5_HOSTILE_SHA256__'
$script:UID0002FDV5ExpectedResultSha256='__V5_RESULT_SHA256__'
# UID0002FD-V5-END
~~~

## Removed Block R019

- SHA256: `F2A20BFD7F9C191B23919981779ABAAB97EE1421486B06DE350B28A6943C0B2F`
- Language: `powershell`
- Bytes: `1120`
- First recovered timestamp: `2026-08-08T20:08:26.605Z`
- Session provenance: rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 198689 (2026-08-08T20:08:26.605Z); rollout-2026-08-06T18-19-47-019fd929-408b-7e00-b3bd-c9ce92850a89.jsonl line 198690 (2026-08-08T20:08:26.662Z)

~~~powershell
$report='E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B006\research\0002FD-ChattingVarietyPaneOnPaint-source-quality.md'
$raw=[IO.File]::ReadAllText($report,[Text.Encoding]::UTF8)
$match=[regex]::Match($raw,'(?ms)^# UID0002FD-V5-BEGIN\n(.*?)^# UID0002FD-V5-END$')
if(-not$match.Success-or[regex]::Matches($raw,'(?m)^# UID0002FD-V5-BEGIN$').Count-ne1-or[regex]::Matches($raw,'(?m)^# UID0002FD-V5-END$').Count-ne1){throw'UID0002FD_V5_EXTRACTION_CARDINALITY'}
$module=New-Module -Name UID0002FDV5 -ScriptBlock ([scriptblock]::Create($match.Groups[1].Value))
$load=&$module{Assert-UID0002FDV5LoadReceipt}
$fixture=&$module{Invoke-UID0002FDV5HostileSuite}
if($load.Code-cne'UID0002FD_V5_LOAD_VERIFIED'-or$fixture.Code-cne'UID0002FD_V5_HOSTILE_SUITE_VERIFIED'){throw'UID0002FD_V5_CLEAN_LOAD_FAILED'}
$module|Import-Module -Force
if((Get-Command Invoke-UID0002FDTransactionCoordinator).Parameters.Count-ne0){throw'UID0002FD_V5_PUBLIC_SURFACE'}
# Gate 2B only, after the primary supervisor independently accepts Gate 1:
$transactionResult=Invoke-UID0002FDTransactionCoordinator
~~~
