<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B001\0002OZ-TextFilterVtableData-empty-emitter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002OZ-TextFilterVtableData-empty-emitter-source-quality.md](0002OZ-TextFilterVtableData-empty-emitter-source-quality.md)
- Source report SHA256 before archive-link insertion: `54EEE3EFF25559E9F5E43D2ECD7B9398129564507A1F238298A18983E28B6AFB`
- Recovery generated: `2026-08-09T22:17:53Z`
- Unique recovered executable blocks: `26`
- Recovered executable bytes: `155649`
- Recovery basis: report-path-associated Codex session history. The source report had already removed its executable packages before the supervisor could extract them directly.
- Scope: this archive preserves every unique recoverable report-local executable block, including superseded historical variants where session history retained more than the final pre-removal report.
- Authority: this file is not a B-agent research report, claims no target coverage, and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- SHA256: `38424F4FCBD9FA55CA15FA25855C0FDBDDC439931B219F889099AD1498757EAE`
- Language: `powershell`
- Bytes: `1752`
- First recovered timestamp: `2026-08-06T11:58:57.279Z`
- Session provenance: rollout-2026-08-03T16-06-01-019fc93b-b77a-7a10-ba3c-e5e65e36ca49.jsonl line 187163 (2026-08-06T11:58:57.279Z); rollout-2026-08-03T16-06-01-019fc93b-b77a-7a10-ba3c-e5e65e36ca49.jsonl line 187164 (2026-08-06T11:58:57.332Z)

~~~powershell
function Invoke-UID0002OZEr00 {
    [CmdletBinding()]
    param(
        [Parameter(Mandatory = $true)][string]$Path,
        [Parameter(Mandatory = $true)][long]$ExpectedLength
    )

    $stream = $null
    $actualLength = $null
    $bytesRead = 0
    $firstByte = $null
    $result = $null
    try {
        $fullPath = [System.IO.Path]::GetFullPath($Path)
        $stream = [System.IO.File]::Open(
            $fullPath,
            [System.IO.FileMode]::Open,
            [System.IO.FileAccess]::Read,
            [System.IO.FileShare]::None
        )
        $actualLength = [long]$stream.Length
        if ($actualLength -ne $ExpectedLength) {
            throw [System.IO.InvalidDataException]::new("ER00 length mismatch: expected $ExpectedLength, observed $actualLength")
        }
        $buffer = [byte[]]::new(1)
        $bytesRead = $stream.Read($buffer, 0, 1)
        if ($bytesRead -ne 1) {
            throw [System.IO.EndOfStreamException]::new("ER00 could not read one byte from the exclusive handle")
        }
        $firstByte = [int]$buffer[0]
        $result = [pscustomobject]@{
            gate = 'ER00'; ok = $true; path = $fullPath
            expected_length = $ExpectedLength; actual_length = $actualLength
            bytes_read = $bytesRead; first_byte = $firstByte; error = $null
        }
    }
    catch {
        $result = [pscustomobject]@{
            gate = 'ER00'; ok = $false; path = [System.IO.Path]::GetFullPath($Path)
            expected_length = $ExpectedLength; actual_length = $actualLength
            bytes_read = $bytesRead; first_byte = $firstByte; error = $_.Exception.Message
        }
    }
    finally {
        if ($null -ne $stream) { $stream.Dispose() }
    }
    $result
}
~~~

## Removed Block R002

- SHA256: `5B4FBDC3188A3DB31AA1203F88493B90DDE6F7F2332F7E3C8959D260E4EEA410`
- Language: `powershell`
- Bytes: `3153`
- First recovered timestamp: `2026-08-06T22:19:23.565Z`
- Session provenance: rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 193754 (2026-08-06T22:19:23.565Z); rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 193755 (2026-08-06T22:19:23.622Z)

~~~powershell
$lr1A = @(Get-NetTCPConnection -LocalAddress '127.0.0.1' -LocalPort 13337 -State Listen -ErrorAction Stop)
if ($lr1A.Count -ne 1) { throw "LR-1 requires exactly one loopback listener; observed $($lr1A.Count)" }
$listenerPid = [int]$lr1A[0].OwningProcess
$listenerCimA = Get-CimInstance Win32_Process -Filter "ProcessId=$listenerPid" -ErrorAction Stop
$listenerProcA = Get-Process -Id $listenerPid -ErrorAction Stop
$listenerGeneration = [pscustomobject]@{
    pid = $listenerPid
    creation_time_utc = $listenerProcA.StartTime.ToUniversalTime().ToString('o')
    executable_path = [string]$listenerCimA.ExecutablePath
    command_line = [string]$listenerCimA.CommandLine
}
$venvRoot = 'C:\Users\admin\.idapro\idalib-mcp-venv'
$launcherPath = [IO.Path]::GetFullPath("$venvRoot\Scripts\idalib-mcp.exe")
$venvPython = [IO.Path]::GetFullPath("$venvRoot\Scripts\python.exe")
$sourceRoot = [IO.Path]::GetFullPath("$venvRoot\Lib\site-packages\ida_pro_mcp")
$supervisorSource = [IO.Path]::GetFullPath("$sourceRoot\idalib_supervisor.py")
$serverSource = [IO.Path]::GetFullPath("$sourceRoot\idalib_server.py")
if ($listenerGeneration.command_line -notlike "*$launcherPath*" -or
    $listenerGeneration.command_line -notmatch '(?i)--host\s+127\.0\.0\.1' -or
    $listenerGeneration.command_line -notmatch '(?i)--port\s+13337') {
    throw 'LR-1 listener command line is not bound to the exact launcher/endpoint'
}
$runtimeManifest = @(
    @{ path=$launcherPath; size=108369; sha='38888EDC3241C00092D5A4F166F70E6AF8DF538D4C81C8DE75E461575E27580E' },
    @{ path=$supervisorSource; size=52468; sha='2D7098B6BDB58D7DCF8CF4825BBE7584F5E7ACB256AD318B05482E9A0B9AF10A' },
    @{ path=$serverSource; size=9848; sha='06C922EEF3F2E6771308C687231FE443A65DADF340E72001C6B05B7FC70B2034' }
)
foreach ($entry in $runtimeManifest) {
    $item = Get-Item -LiteralPath $entry.path -ErrorAction Stop
    $hash = (Get-FileHash -LiteralPath $entry.path -Algorithm SHA256 -ErrorAction Stop).Hash
    if ([long]$item.Length -ne [long]$entry.size -or $hash -ne $entry.sha) { throw "LR-1 identity mismatch: $($entry.path)" }
}
# Using the exact $venvPython above, resolve distribution entry point and module origins.
# Require: idalib-mcp = ida_pro_mcp.idalib_supervisor:main, and exact $supervisorSource/$serverSource.
# Through the same 13337 listener, run initialize then complete tools/list and verify the package's literal schemas.
$lr1B = @(Get-NetTCPConnection -LocalAddress '127.0.0.1' -LocalPort 13337 -State Listen -ErrorAction Stop)
if ($lr1B.Count -ne 1 -or [int]$lr1B[0].OwningProcess -ne $listenerPid) { throw 'LR-1 listener owner changed' }
$listenerCimB = Get-CimInstance Win32_Process -Filter "ProcessId=$listenerPid" -ErrorAction Stop
$listenerProcB = Get-Process -Id $listenerPid -ErrorAction Stop
if ($listenerProcB.StartTime.ToUniversalTime().ToString('o') -ne $listenerGeneration.creation_time_utc -or
    [string]$listenerCimB.ExecutablePath -ne $listenerGeneration.executable_path -or
    [string]$listenerCimB.CommandLine -ne $listenerGeneration.command_line) {
    throw 'LR-1 listener process generation changed during the live handshake'
}
~~~

## Removed Block R003

- SHA256: `65B343ABA8E14C5781D8813BD39A67AE94D5F4E435949E8621AAB1F9080CB3B6`
- Language: `powershell`
- Bytes: `1663`
- First recovered timestamp: `2026-08-06T22:19:23.565Z`
- Session provenance: rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 193754 (2026-08-06T22:19:23.565Z); rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 193755 (2026-08-06T22:19:23.622Z)

~~~powershell
function New-UID0002OZB0 {
    param([Parameter(Mandatory=$true)][string]$CanonicalPath,
          [Parameter(Mandatory=$true)][string]$BackupPath)
    $expectedLength = [long]143197685
    $source = $null
    $destination = $null
    $copied = [long]0
    $sawEof = $false
    $eofProbe = -1
    try {
        $source = [IO.File]::Open([IO.Path]::GetFullPath($CanonicalPath), [IO.FileMode]::Open, [IO.FileAccess]::Read, [IO.FileShare]::None)
        if ([long]$source.Length -ne $expectedLength) { throw 'BK-1 source length differs from P0' }
        $destination = [IO.File]::Open([IO.Path]::GetFullPath($BackupPath), [IO.FileMode]::CreateNew, [IO.FileAccess]::Write, [IO.FileShare]::None)
        $buffer = [byte[]]::new(1048576)
        while ($true) {
            $read = $source.Read($buffer, 0, $buffer.Length)
            if ($read -eq 0) { $sawEof = $true; break }
            $destination.Write($buffer, 0, $read)
            $copied += [long]$read
            if ($copied -gt $expectedLength) { throw 'BK-1 copied beyond P0 length' }
        }
        $eofProbe = $source.Read($buffer, 0, 1)
        if (-not $sawEof -or $eofProbe -ne 0 -or $copied -ne $expectedLength -or
            [long]$source.Position -ne $expectedLength -or [long]$destination.Length -ne $expectedLength) {
            throw 'BK-1 exact count/EOF/length proof failed'
        }
        $destination.Flush($true)
    }
    finally {
        if ($null -ne $destination) { $destination.Dispose() }
        if ($null -ne $source) { $source.Dispose() }
    }
    [pscustomobject]@{ copied=$copied; eof_observed=$sawEof; eof_probe=$eofProbe; durable_flush=$true }
}
~~~

## Removed Block R004

- SHA256: `A2E1A2447CCC672805623FC0E5EA050D0D449CF9C5E450EC41B9EE7BC56480A7`
- Language: `powershell`
- Bytes: `2020`
- First recovered timestamp: `2026-08-06T22:19:23.565Z`
- Session provenance: rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 193754 (2026-08-06T22:19:23.565Z); rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 193755 (2026-08-06T22:19:23.622Z)

~~~powershell
function Restore-UID0002OZP0 {
    param([Parameter(Mandatory=$true)][string]$BackupPath,
          [Parameter(Mandatory=$true)][string]$CanonicalPath,
          [Parameter(Mandatory=$true)][long]$ExpectedS1Length)
    $expectedP0Length = [long]143197685
    $backup = $null
    $canonical = $null
    $copied = [long]0
    $sawEof = $false
    $eofProbe = -1
    try {
        $backup = [IO.File]::Open([IO.Path]::GetFullPath($BackupPath), [IO.FileMode]::Open, [IO.FileAccess]::Read, [IO.FileShare]::None)
        $canonical = [IO.File]::Open([IO.Path]::GetFullPath($CanonicalPath), [IO.FileMode]::Open, [IO.FileAccess]::ReadWrite, [IO.FileShare]::None)
        if ([long]$backup.Length -ne $expectedP0Length -or [long]$canonical.Length -ne $ExpectedS1Length) {
            throw 'RS-1 held-handle precondition length mismatch'
        }
        $canonical.SetLength(0)
        $buffer = [byte[]]::new(1048576)
        while ($true) {
            $read = $backup.Read($buffer, 0, $buffer.Length)
            if ($read -eq 0) { $sawEof = $true; break }
            $canonical.Write($buffer, 0, $read)
            $copied += [long]$read
            if ($copied -gt $expectedP0Length) { throw 'RS-1 copied beyond P0 length' }
        }
        $eofProbe = $backup.Read($buffer, 0, 1)
        if (-not $sawEof -or $eofProbe -ne 0 -or $copied -ne $expectedP0Length -or
            [long]$backup.Position -ne $expectedP0Length -or [long]$canonical.Length -ne $expectedP0Length) {
            throw 'RS-1 exact count/EOF/length proof failed'
        }
        $canonical.Flush($true)
    }
    finally {
        if ($null -ne $canonical) { $canonical.Dispose() }
        if ($null -ne $backup) { $backup.Dispose() }
    }
    [IO.File]::SetLastWriteTimeUtc(
        [IO.Path]::GetFullPath($CanonicalPath),
        [DateTime]::new(639216052962969329, [DateTimeKind]::Utc)
    )
    [pscustomobject]@{ copied=$copied; eof_observed=$sawEof; eof_probe=$eofProbe; durable_flush=$true; p0_ticks_restored=$true }
}
~~~

## Removed Block R005

- SHA256: `2AD17D51C5970A3FC43D934429B9DB9ECEF6BEB9FA393A5FCFD523723CEE481B`
- Language: `powershell`
- Bytes: `1150`
- First recovered timestamp: `2026-08-07T00:22:27.677Z`
- Session provenance: rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 194608 (2026-08-07T00:22:27.677Z); rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 194609 (2026-08-07T00:22:27.851Z)

~~~powershell
function New-UID0002OZSaveController([string]$AttemptId,[string]$Database,[string]$CanonicalPath) {
    [pscustomobject]@{ state='NOT_ISSUED'; attempt_id=$AttemptId; database=$Database; canonical_path=[IO.Path]::GetFullPath($CanonicalPath); request_id=$null; classification=$null; dispatch_count=0 }
}

function Invoke-UID0002OZSingleSave([object]$Controller,[scriptblock]$Dispatch,[string]$RequestId) {
    if ([string]$Controller.state -cne 'NOT_ISSUED') { Throw-UID0002OZ 'SV1_SAVE_ALREADY_ISSUED' }
    $Controller.state = 'ISSUED'; $Controller.request_id = $RequestId; $Controller.dispatch_count = 1
    try {
        $response = & $Dispatch
        if ($null -eq $response) { $Controller.classification='INDETERMINATE' }
        elseif ($response.ok -eq $true -and [IO.Path]::GetFullPath([string]$response.path) -ceq $Controller.canonical_path -and $null -eq $response.error) { $Controller.classification='EXPLICIT_SUCCESS' }
        else { $Controller.classification='DETERMINATE_FAILURE' }
    } catch { $Controller.classification='INDETERMINATE' }
    $Controller.state='CLASSIFIED'
    return $Controller.classification
}
~~~

## Removed Block R006

- SHA256: `49AFFD573FC439C6D8B2865547E5608E7557332F5BAB668C1C08CE187408C9F4`
- Language: `powershell`
- Bytes: `1137`
- First recovered timestamp: `2026-08-07T00:22:27.677Z`
- Session provenance: rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 194608 (2026-08-07T00:22:27.677Z); rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 194609 (2026-08-07T00:22:27.851Z)

~~~powershell
function Invoke-UID0002OZContractCall {
    param([hashtable]$Spec, [scriptblock]$Transport, [hashtable]$Attempt)
    Assert-UID0002OZExactKeys $Spec.Params @($Spec.ParamKeys) 'RR1_ARGUMENT_KEYS'
    $envelope = Invoke-UID0002OZRpc -AttemptId $Attempt.id -Ordinal $Attempt.next_ordinal -Method $Spec.Method -Params $Spec.Params -Transport $Transport -ConsumedIds $Attempt.consumed_ids
    $Attempt.next_ordinal = [int]$Attempt.next_ordinal + 1
    if ($null -ne $envelope.PSObject.Properties['error']) { Throw-UID0002OZ 'RR1_TOOL_ERROR' }
    Assert-UID0002OZExactKeys $envelope.result @($Spec.ResultKeys) 'RR1_RESULT_KEYS'
    $items = if ($null -ne $Spec.ItemsProperty) { @($envelope.result.PSObject.Properties[$Spec.ItemsProperty].Value) } else { @($envelope.result) }
    if ($items.Count -ne [int]$Spec.ExactCardinality) { Throw-UID0002OZ 'RR1_CARDINALITY' }
    $Attempt.assertion_count = [int]$Attempt.assertion_count + 1
    & $Spec.Assert $envelope.result $items
    if (-not $?) { Throw-UID0002OZ 'RR1_ASSERTION_FAILED' }
    $Attempt.asserted_call_ids.Add([string]$envelope.id)
    return $envelope.result
}
~~~

## Removed Block R007

- SHA256: `5FA203C3F87E5AB18A74C5DE88036973071718941AB3479DE8FC23B7B54B7FF9`
- Language: `powershell`
- Bytes: `3552`
- First recovered timestamp: `2026-08-07T00:22:27.677Z`
- Session provenance: rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 194608 (2026-08-07T00:22:27.677Z); rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 194609 (2026-08-07T00:22:27.851Z)

~~~powershell
function ConvertTo-UID0002OZStableRuntime([object]$Attestation) {
    $listenerModules = @($Attestation.listener.modules | Sort-Object sys_modules_name | ForEach-Object {
        [ordered]@{ sys_modules_name=$_.sys_modules_name; file=$_.file; spec_origin=$_.spec_origin; resolved_path=$_.resolved_path; relative_path=$_.relative_path; size=$_.size; mtime_ns=$_.mtime_ns; ctime_ns=$_.ctime_ns; sha256=$_.sha256; source_root=$_.source_root; implementation_manifest_sha256=$_.implementation_manifest_sha256 }
    })
    $workers = @($Attestation.workers | Sort-Object route,session_id | ForEach-Object {
        $workerModules = @($_.modules | Sort-Object sys_modules_name | ForEach-Object {
            [ordered]@{ sys_modules_name=$_.sys_modules_name; file=$_.file; spec_origin=$_.spec_origin; resolved_path=$_.resolved_path; relative_path=$_.relative_path; size=$_.size; mtime_ns=$_.mtime_ns; ctime_ns=$_.ctime_ns; sha256=$_.sha256; source_root=$_.source_root; implementation_manifest_sha256=$_.implementation_manifest_sha256 }
        })
        [ordered]@{ route=$_.route; session_id=$_.session_id; canonical_path=$_.canonical_path; endpoint=$_.endpoint; socket=$_.socket; pid=$_.pid; parent_pid=$_.parent_pid; creation_time_utc=$_.creation_time_utc; generation=$_.generation; executable=$_.executable; image=$_.image; argv=@($_.argv); redirector_pid=$_.redirector_pid; registered_pid=$_.registered_pid; owned=$_.owned; adopted=$_.adopted; source_root=$_.source_root; implementation_manifest_sha256=$_.implementation_manifest_sha256; modules=$workerModules }
    })
    return [ordered]@{ listener=[ordered]@{ endpoint=$Attestation.listener.endpoint; socket=$Attestation.listener.socket; socket_owner_pid=$Attestation.listener.socket_owner_pid; pid=$Attestation.listener.pid; parent_pid=$Attestation.listener.parent_pid; creation_time_utc=$Attestation.listener.creation_time_utc; generation=$Attestation.listener.generation; executable=$Attestation.listener.executable; image=$Attestation.listener.image; argv=@($Attestation.listener.argv); source_root=$Attestation.listener.source_root; implementation_manifest_sha256=$Attestation.listener.implementation_manifest_sha256; modules=$listenerModules }; workers=$workers }
}

function Assert-UID0002OZStableBoundary([object]$Previous, [object]$Current, [string]$AllowedRoleChange) {
    if ([string]$Previous.nonce -ceq [string]$Current.nonce) { Throw-UID0002OZ 'ST1_STALE_NONCE' }
    if ([datetime]$Current.observed_at_utc -le [datetime]$Previous.observed_at_utc) { Throw-UID0002OZ 'ST1_NONADVANCING_TIME' }
    $p = ConvertTo-UID0002OZStableRuntime $Previous
    $c = ConvertTo-UID0002OZStableRuntime $Current
    if (($p.listener | ConvertTo-Json -Depth 100 -Compress) -cne ($c.listener | ConvertTo-Json -Depth 100 -Compress)) { Throw-UID0002OZ 'ST1_LISTENER_OR_MODULE_DRIFT' }
    $pWorkers = @($p.workers); $cWorkers = @($c.workers)
    if ([string]::IsNullOrEmpty($AllowedRoleChange)) {
        if (($pWorkers | ConvertTo-Json -Depth 100 -Compress) -cne ($cWorkers | ConvertTo-Json -Depth 100 -Compress)) { Throw-UID0002OZ 'ST1_WORKER_SESSION_ROUTE_MODULE_DRIFT' }
    } else {
        $pStable = @($pWorkers | Where-Object session_id -cne $AllowedRoleChange)
        $cStable = @($cWorkers | Where-Object session_id -cne $AllowedRoleChange)
        if (($pStable | ConvertTo-Json -Depth 100 -Compress) -cne ($cStable | ConvertTo-Json -Depth 100 -Compress) -or [math]::Abs($pWorkers.Count-$cWorkers.Count) -ne 1) { Throw-UID0002OZ 'ST1_UNAUTHORIZED_ACTIVE_SET_CHANGE' }
    }
}
~~~

## Removed Block R008

- SHA256: `604C458A3F3AF0569A569B0EDFA4F96B2F07E793CAA2687D8B93C846D5E02A33`
- Language: `powershell`
- Bytes: `569`
- First recovered timestamp: `2026-08-07T00:22:27.677Z`
- Session provenance: rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 194608 (2026-08-07T00:22:27.677Z); rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 194609 (2026-08-07T00:22:27.851Z)

~~~powershell
function Classify-UID0002OZDisk([object]$Observed,[object]$P0,[object]$S1,[object]$SaveController,[bool]$WorkerRetired) {
    $tuple = { param($x) '{0}|{1}|{2}|{3}' -f ([IO.Path]::GetFullPath([string]$x.path)),([long]$x.length),([string]$x.sha256),([long]$x.ticks) }
    $o = & $tuple $Observed; $p = & $tuple $P0
    if ($o -ceq $p) { return 'EXACT_P0' }
    if ($null -ne $S1 -and $WorkerRetired -and @('ISSUED','CLASSIFIED') -contains [string]$SaveController.state -and $o -ceq (& $tuple $S1)) { return 'ATTEMPT_S1' }
    return 'THIRD_IDENTITY'
}
~~~

## Removed Block R009

- SHA256: `B9C8A8402D231096A43A647BFA8A1B153D19C3BEFD0D3C95D77B8BEE7BC872C9`
- Language: `powershell`
- Bytes: `948`
- First recovered timestamp: `2026-08-07T00:22:27.677Z`
- Session provenance: rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 194608 (2026-08-07T00:22:27.677Z); rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 194609 (2026-08-07T00:22:27.851Z)

~~~powershell
function Invoke-UID0002OZHostileFixture([object]$Fixture,[scriptblock]$Exercise) {
    $state = [pscustomobject]@{ mutation_dispatches=0; save_dispatches=0; restore_calls=0; set_length_calls=0; canonical_tuple='SYNTHETIC-P0'; accepted_b0=$false }
    $observed = $null
    try { & $Exercise $state; $observed='NO_ERROR' } catch { $observed=$_.Exception.Message }
    if ([string]$observed -cne [string]$Fixture.expected_error) { Throw-UID0002OZ ('HF1_WRONG_ERROR:{0}:{1}' -f $Fixture.name,$observed) }
    foreach ($field in @('mutation_dispatches','save_dispatches','restore_calls','set_length_calls')) {
        if ([int]$state.$field -ne [int]$Fixture.expected_state.$field) { Throw-UID0002OZ ('HF1_SIDE_EFFECT:{0}:{1}' -f $Fixture.name,$field) }
    }
    if ([string]$state.canonical_tuple -cne 'SYNTHETIC-P0' -or $state.accepted_b0 -ne $false) { Throw-UID0002OZ ('HF1_DISK_EFFECT:{0}' -f $Fixture.name) }
    return $true
}
~~~

## Removed Block R010

- SHA256: `DCE2AEB00F23E1A56097C54C4162E93345E07EDC111858B4C32393F95AD70EE6`
- Language: `powershell`
- Bytes: `3899`
- First recovered timestamp: `2026-08-07T00:22:27.677Z`
- Session provenance: rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 194608 (2026-08-07T00:22:27.677Z); rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 194609 (2026-08-07T00:22:27.851Z)

~~~powershell
function Throw-UID0002OZ([string]$Label) { throw $Label }

function Get-UID0002OZKeys([object]$Value) {
    if ($null -eq $Value) { return @() }
    return @($Value.PSObject.Properties.Name | Sort-Object)
}

function Assert-UID0002OZExactKeys([object]$Value, [string[]]$Expected, [string]$Label) {
    $actual = @(Get-UID0002OZKeys $Value)
    $wanted = @($Expected | Sort-Object)
    if (($actual -join "`n") -cne ($wanted -join "`n")) { Throw-UID0002OZ $Label }
}

function Assert-UID0002OZToolsList([object]$Envelope) {
    $tools = @($Envelope.result.tools)
    if (@($tools | Where-Object { [string]$_.name -ceq 'runtime_attestation' }).Count -ne 1) { Throw-UID0002OZ 'SC1_RUNTIME_TOOL_CARDINALITY' }
    if (@($tools | Where-Object { [string]$_.name -ceq 'runtime/attest' }).Count -ne 0) { Throw-UID0002OZ 'SC1_INTERNAL_TOOL_PUBLIC' }
    if (@($tools.name | Group-Object | Where-Object Count -ne 1).Count -ne 0) { Throw-UID0002OZ 'SC1_DUPLICATE_TOOL_NAME' }
    $schema = @($tools | Where-Object { [string]$_.name -ceq 'runtime_attestation' })[0].inputSchema
    Assert-UID0002OZExactKeys $schema @('properties','required','type') 'SC1_SCHEMA_KEYS'
    if ([string]$schema.type -cne 'object' -or @($schema.required).Count -ne 0) { Throw-UID0002OZ 'SC1_SCHEMA_REQUIRED_OR_TYPE' }
    Assert-UID0002OZExactKeys $schema.properties @('expected_canonical_path','expected_database') 'SC1_SCHEMA_PROPERTIES'
    foreach ($name in @('expected_database','expected_canonical_path')) {
        $property = $schema.properties.PSObject.Properties[$name].Value
        Assert-UID0002OZExactKeys $property @('default','type') 'SC1_PROPERTY_SCHEMA_KEYS'
        if ([string]$property.type -cne 'string' -or $property.default -isnot [string] -or [string]$property.default -cne '') { Throw-UID0002OZ 'SC1_PROPERTY_SCHEMA_VALUE' }
    }
}

function Assert-UID0002OZArguments([object]$Arguments, [bool]$Active) {
    $expected = if ($Active) { @('expected_database','expected_canonical_path') } else { @() }
    Assert-UID0002OZExactKeys $Arguments $expected 'SC1_ARGUMENT_KEYSET'
    if ($Active -and (($Arguments.expected_database -isnot [string]) -or ($Arguments.expected_canonical_path -isnot [string]))) { Throw-UID0002OZ 'SC1_ARGUMENT_TYPE' }
}

function Assert-UID0002OZRpcEnvelope([object]$Envelope, [string]$RequestId, [Collections.Generic.HashSet[string]]$ConsumedIds) {
    if ($null -eq $Envelope -or $Envelope -isnot [psobject]) { Throw-UID0002OZ 'XR1_RESPONSE_OBJECT' }
    if ($Envelope.jsonrpc -isnot [string] -or [string]$Envelope.jsonrpc -cne '2.0') { Throw-UID0002OZ 'XR1_JSONRPC_VERSION' }
    if ($Envelope.id -isnot [string]) { Throw-UID0002OZ 'XR1_RESPONSE_ID_TYPE' }
    if ([string]$Envelope.id -cne $RequestId) { Throw-UID0002OZ 'XR1_RESPONSE_ID_VALUE' }
    if ($ConsumedIds.Contains([string]$Envelope.id)) { Throw-UID0002OZ 'XR1_RESPONSE_ID_REPLAY' }
    $hasResult = $null -ne $Envelope.PSObject.Properties['result']
    $hasError = $null -ne $Envelope.PSObject.Properties['error']
    if ($hasResult -eq $hasError) { Throw-UID0002OZ 'XR1_RESULT_ERROR_XOR' }
    [void]$ConsumedIds.Add([string]$Envelope.id)
}

function Invoke-UID0002OZRpc {
    param([string]$AttemptId, [int]$Ordinal, [string]$Method, [object]$Params,
          [scriptblock]$Transport, [Collections.Generic.HashSet[string]]$ConsumedIds)
    $requestId = 'uid0002oz:{0}:{1:d4}' -f $AttemptId,$Ordinal
    $request = [ordered]@{ jsonrpc='2.0'; id=$requestId; method=$Method; params=$Params }
    $raw = & $Transport ($request | ConvertTo-Json -Depth 100 -Compress)
    if ($raw -isnot [string] -or [string]::IsNullOrWhiteSpace($raw)) { Throw-UID0002OZ 'XR1_EMPTY_OR_NONSTRING_RESPONSE' }
    try { $envelope = $raw | ConvertFrom-Json -Depth 100 -ErrorAction Stop } catch { Throw-UID0002OZ 'XR1_JSON_PARSE' }
    Assert-UID0002OZRpcEnvelope $envelope $requestId $ConsumedIds
    return $envelope
}
~~~

## Removed Block R011

- SHA256: `E1EB719119345E1DA050D0E0EBD22AD80F0CE73FAD572512076FC93398754842`
- Language: `powershell`
- Bytes: `659`
- First recovered timestamp: `2026-08-07T00:22:27.677Z`
- Session provenance: rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 194608 (2026-08-07T00:22:27.677Z); rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 194609 (2026-08-07T00:22:27.851Z)

~~~powershell
function Assert-UID0002OZRestorePrecondition([object]$HeldB0,[object]$HeldDestination,[object]$P0,[object]$S1) {
    if ([IO.Path]::GetFullPath([string]$HeldB0.path) -ceq [IO.Path]::GetFullPath([string]$HeldDestination.path)) { Throw-UID0002OZ 'RS2_PATH_ALIAS' }
    foreach ($name in @('path','length','sha256','ticks')) {
        if ([string]$HeldB0.$name -cne [string]$P0.$name) { Throw-UID0002OZ 'RS2_B0_TUPLE' }
        if ([string]$HeldDestination.$name -cne [string]$S1.$name) { Throw-UID0002OZ 'RS2_S1_TUPLE' }
    }
    if ([string]$HeldDestination.sha256 -ceq [string]$P0.sha256) { Throw-UID0002OZ 'RS2_DESTINATION_ALREADY_P0' }
}
~~~

## Removed Block R012

- SHA256: `E3932B4298EA0AD8B65160E5174D38D7519FE8F5332AFCE3C8B415AB0542EF45`
- Language: `powershell`
- Bytes: `2042`
- First recovered timestamp: `2026-08-07T00:22:27.677Z`
- Session provenance: rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 194608 (2026-08-07T00:22:27.677Z); rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 194609 (2026-08-07T00:22:27.851Z)

~~~powershell
function Invoke-UID0002OZSupervisorRetirement {
    param([object]$Expected,[scriptblock]$ReadGeneration,[scriptblock]$StopOwnedGeneration,
          [scriptblock]$ReadClosedAttestation,[scriptblock]$ReadIdbList)
    $before = & $ReadGeneration $Expected.pid
    foreach ($field in @('pid','parent_pid','creation_time_utc','generation','executable','image','command_line','route','session_id','socket','endpoint','redirector_pid','registered_pid','owned','adopted','canonical_path','implementation_manifest_sha256')) {
        if ([string]$before.$field -cne [string]$Expected.$field) { Throw-UID0002OZ 'RT1_PREIDENTITY_MISMATCH' }
    }
    if ($Expected.owned -ne $true -or $Expected.adopted -eq $true) { Throw-UID0002OZ 'RT1_NOT_OWNED' }
    & $StopOwnedGeneration $Expected
    $deadline = [datetime]::UtcNow.AddSeconds(30)
    do { Start-Sleep -Milliseconds 100; $after = & $ReadGeneration $Expected.pid } while ($null -ne $after -and [string]$after.generation -ceq [string]$Expected.generation -and [datetime]::UtcNow -lt $deadline)
    if ($null -ne $after -and [string]$after.generation -ceq [string]$Expected.generation) { Throw-UID0002OZ 'RT1_PROCESS_SURVIVED' }
    if ($null -ne $after -and [string]$after.generation -cne [string]$Expected.generation) { $pidReuse = $true } else { $pidReuse = $false }
    $closed = & $ReadClosedAttestation
    $rows = @(& $ReadIdbList)
    if (@($closed.workers | Where-Object { $_.session_id -ceq $Expected.session_id -or $_.route -ceq $Expected.route -or $_.socket -ceq $Expected.socket }).Count -ne 0) { Throw-UID0002OZ 'RT1_ROUTE_SURVIVED' }
    if (@($rows | Where-Object { $_.is_active -eq $true -and [IO.Path]::GetFullPath([string]$_.input_path) -ceq [IO.Path]::GetFullPath([string]$Expected.canonical_path) }).Count -ne 0) { Throw-UID0002OZ 'RT1_CANONICAL_SESSION_SURVIVED' }
    [pscustomobject]@{ retired_session=$Expected.session_id; retired_generation=$Expected.generation; exact_generation_absent=$true; pid_reuse_observed=$pidReuse; canonical_active_routes=0 }
}
~~~

## Removed Block R013

- SHA256: `0FB76C4D80E9FE2CCABD406BC2715F31EE22E704CC52EF744257097EFAF7C293`
- Language: `powershell`
- Bytes: `1300`
- First recovered timestamp: `2026-08-07T00:56:20.970Z`
- Session provenance: rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 195075 (2026-08-07T00:56:20.970Z); rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 195076 (2026-08-07T00:56:21.142Z)

~~~powershell
function Assert-UID0002OZTc3RestorePermit($Permit,$HeldB0,$HeldS1,[byte[]]$PrivateKey) {
  foreach($o in@($Permit,$HeldB0,$HeldS1)){Assert-UID0002OZTc3Object $o 'TC3_RESTORE_OBJECT'}
  Assert-UID0002OZTc3Keys $Permit @('attempt','b0','hmac','retirement','s1','save_request') 'TC3_RESTORE_PERMIT_KEYS'
  $copy=[ordered]@{attempt=$Permit['attempt'];b0=$Permit['b0'];retirement=$Permit['retirement'];s1=$Permit['s1'];save_request=$Permit['save_request']}
  $h=New-Object Security.Cryptography.HMACSHA256($PrivateKey);try{$expected=([BitConverter]::ToString($h.ComputeHash([Text.Encoding]::UTF8.GetBytes(($copy|ConvertTo-Json -Depth 20 -Compress))))).Replace('-','')}finally{$h.Dispose()}
  if($Permit['hmac']-isnot[string]-or$Permit['hmac']-cne$expected){Throw-UID0002OZTc3 'TC3_RESTORE_PERMIT_FORGED'}
  foreach($name in@('final_path','file_id','length','sha256','ticks','volume_serial')){if([string]$HeldB0[$name]-cne[string]$Permit['b0'][$name]){Throw-UID0002OZTc3 'TC3_RESTORE_B0_TUPLE'};if([string]$HeldS1[$name]-cne[string]$Permit['s1'][$name]){Throw-UID0002OZTc3 'TC3_RESTORE_S1_TUPLE'}}
  if([string]$HeldB0['file_id']-ceq[string]$HeldS1['file_id']-and[string]$HeldB0['volume_serial']-ceq[string]$HeldS1['volume_serial']){Throw-UID0002OZTc3 'TC3_RESTORE_FILE_ALIAS'}
  $true
}
~~~

## Removed Block R014

- SHA256: `62BE859C4CF4DA3EF2BEF7B83A2B99D2C6D94D238DC24A69D138B99964A3356D`
- Language: `powershell`
- Bytes: `3671`
- First recovered timestamp: `2026-08-07T00:56:20.970Z`
- Session provenance: rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 195075 (2026-08-07T00:56:20.970Z); rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 195076 (2026-08-07T00:56:21.142Z)

~~~powershell
function Invoke-UID0002OZTc3ExpectedFailure([string]$Name,[string]$Expected,[scriptblock]$Exercise) { $observed='NO_ERROR';try{&$Exercise|Out-Null}catch{$observed=$_.Exception.Message};if($observed-cne$Expected){Throw-UID0002OZTc3 ('TC3_FIXTURE_WRONG:{0}:{1}'-f$Name,$observed)};[pscustomobject]@{fixture=$Name;expected=$Expected;observed=$observed;mutation=0;save=0;restore=0;truncate=0;pass=$true} }
function Invoke-UID0002OZTc3Fixtures {
  $r=New-Object 'Collections.Generic.List[object]'
  $r.Add((Invoke-UID0002OZTc3ExpectedFailure 'json-duplicate-root' 'Exception calling "Parse" with "1" argument(s): "TC3_JSON_DUPLICATE_MEMBER:id"' {ConvertFrom-UID0002OZTc3Json '{"id":"a","id":"b"}'}))
  $r.Add((Invoke-UID0002OZTc3ExpectedFailure 'json-duplicate-nested' 'Exception calling "Parse" with "1" argument(s): "TC3_JSON_DUPLICATE_MEMBER:x"' {ConvertFrom-UID0002OZTc3Json '{"a":{"x":1,"x":2}}'}))
  $r.Add((Invoke-UID0002OZTc3ExpectedFailure 'json-truncated' 'Exception calling "Parse" with "1" argument(s): "TC3_JSON_TRUNCATED"' {ConvertFrom-UID0002OZTc3Json '{"a":'}))
  $r.Add((Invoke-UID0002OZTc3ExpectedFailure 'closed-null-object' 'TC3_CLOSED_PARAMS_OBJECT' {Assert-UID0002OZTc3Object $null 'TC3_CLOSED_PARAMS_OBJECT'}))
  $r.Add((Invoke-UID0002OZTc3ExpectedFailure 'required-null-array' 'TC3_REQUIRED_ARRAY' {Assert-UID0002OZTc3Array $null 'TC3_REQUIRED_ARRAY'}))
  $r.Add((Invoke-UID0002OZTc3ExpectedFailure 'active-empty-database' 'TC3_ACTIVE_DATABASE_EMPTY' {if([string]::IsNullOrWhiteSpace('')){Throw-UID0002OZTc3 'TC3_ACTIVE_DATABASE_EMPTY'}}))
  $a=New-UID0002OZTc3Attempt 'fixture';$id=Reserve-UID0002OZTc3Request $a 'tools/list'
  $r.Add((Invoke-UID0002OZTc3ExpectedFailure 'request-replay-before-transport' 'TC3_REQUEST_ID_REPLAY' {if(-not$a.issued.Add($id)){Throw-UID0002OZTc3 'TC3_REQUEST_ID_REPLAY'}}))
  [void]$a.pending.Remove($id);[void]$a.classified.Add($id)
  $r.Add((Invoke-UID0002OZTc3ExpectedFailure 'late-response' 'TC3_LATE_RESPONSE' {Complete-UID0002OZTc3Response $a $id '{"jsonrpc":"2.0","id":"x","result":{}}'}))
  $b=New-UID0002OZTc3Attempt 'fixture2';$bid=Reserve-UID0002OZTc3Request $b 'tools/list'
  $r.Add((Invoke-UID0002OZTc3ExpectedFailure 'native-numeric-id' 'TC3_RPC_ID' {Complete-UID0002OZTc3Response $b $bid ('{"jsonrpc":"2.0","id":1,"result":{}}')}))
  $r.Add((Invoke-UID0002OZTc3ExpectedFailure 'unknown-catalog' 'TC3_UNKNOWN_CATALOG_ID' {Assert-UID0002OZTc3Call (New-UID0002OZTc3Attempt 'fixture3') 'not-a-contract' x ([ordered]@{x=1})}))
  $r.Add((Invoke-UID0002OZTc3ExpectedFailure 'assertion-false' 'TC3_ASSERTION_FALSE' {if($false-isnot[bool]-or-not$false){Throw-UID0002OZTc3 'TC3_ASSERTION_FALSE'}}))
  $prev=[ordered]@{nonce='n1';observed_at_utc='2026-08-06T00:00:00Z';workers=@()};$cur=[ordered]@{nonce='n2';observed_at_utc='2026-08-06T00:00:01Z';workers=@([ordered]@{session_id='s';canonical_path='p';route='r';pid=1;generation='g';implementation_manifest_sha256='h'})}
  $r.Add((Invoke-UID0002OZTc3ExpectedFailure 'retire-added-role' 'TC3_RETIRE_DIRECTION' {Assert-UID0002OZTc3Boundary $prev $cur 'Retire' (Get-UID0002OZTc3WorkerKey $cur.workers[0])}))
  $bad=[ordered]@{attempt='a';b0=[ordered]@{};hmac='00';retirement=[ordered]@{};s1=[ordered]@{};save_request='r'};$key=New-Object byte[] 32
  $r.Add((Invoke-UID0002OZTc3ExpectedFailure 'forged-restore-permit' 'TC3_RESTORE_PERMIT_FORGED' {Assert-UID0002OZTc3RestorePermit $bad ([ordered]@{}) ([ordered]@{}) $key}))
  if(@($r|Group-Object fixture|Where-Object Count -ne1).Count-ne0-or@($r|Where-Object{-not$_.pass}).Count-ne0){Throw-UID0002OZTc3 'TC3_FIXTURE_SET_INCOMPLETE'}
  $r
}
$UID0002OZTc3FixtureTranscript=@(Invoke-UID0002OZTc3Fixtures)
~~~

## Removed Block R015

- SHA256: `84EE9699AF2C2FF8349D78D03735C4B7B66077A0B8806AFE03E3DF550CFF8772`
- Language: `powershell`
- Bytes: `7970`
- First recovered timestamp: `2026-08-07T00:56:20.970Z`
- Session provenance: rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 195075 (2026-08-07T00:56:20.970Z); rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 195076 (2026-08-07T00:56:21.142Z)

~~~powershell
Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'
Add-Type -AssemblyName System.Web.Extensions
if (-not ('UID0002OZTc3Json' -as [type])) {
Add-Type -ReferencedAssemblies System.Web.Extensions.dll -TypeDefinition @'
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;
using System.Web.Script.Serialization;
public static class UID0002OZTc3Json {
  sealed class Scanner {
    readonly string s; int i;
    internal Scanner(string text) { if (String.IsNullOrWhiteSpace(text)) Fail("TC3_JSON_EMPTY"); s=text; }
    static void Fail(string label) { throw new InvalidDataException(label); }
    void Ws(){while(i<s.Length && (s[i]==' '||s[i]=='\t'||s[i]=='\r'||s[i]=='\n'))i++;}
    char Take(){if(i>=s.Length)Fail("TC3_JSON_TRUNCATED");return s[i++];}
    void Need(char c){if(Take()!=c)Fail("TC3_JSON_GRAMMAR");}
    internal void Document(){Ws();Value();Ws();if(i!=s.Length)Fail("TC3_JSON_TRAILING");}
    void Value(){Ws();if(i>=s.Length)Fail("TC3_JSON_TRUNCATED");char c=s[i];if(c=='{')Obj();else if(c=='[')Arr();else if(c=='\"')Str();else if(c=='t')Lit("true");else if(c=='f')Lit("false");else if(c=='n')Lit("null");else Num();}
    void Obj(){Need('{');Ws();var names=new HashSet<string>(StringComparer.Ordinal);if(i<s.Length&&s[i]=='}'){i++;return;}while(true){Ws();if(i>=s.Length||s[i]!='\"')Fail("TC3_JSON_OBJECT_KEY");string n=Str();if(!names.Add(n))Fail("TC3_JSON_DUPLICATE_MEMBER:"+n);Ws();Need(':');Value();Ws();char c=Take();if(c=='}')return;if(c!=',')Fail("TC3_JSON_OBJECT_SEPARATOR");}}
    void Arr(){Need('[');Ws();if(i<s.Length&&s[i]==']'){i++;return;}while(true){Value();Ws();char c=Take();if(c==']')return;if(c!=',')Fail("TC3_JSON_ARRAY_SEPARATOR");}}
    string Str(){Need('\"');var b=new StringBuilder();while(true){char c=Take();if(c=='\"')return b.ToString();if(c<0x20)Fail("TC3_JSON_CONTROL_CHAR");if(c!='\\'){b.Append(c);continue;}char e=Take();switch(e){case '\"':case '\\':case '/':b.Append(e);break;case 'b':b.Append('\b');break;case 'f':b.Append('\f');break;case 'n':b.Append('\n');break;case 'r':b.Append('\r');break;case 't':b.Append('\t');break;case 'u':int v=0;for(int k=0;k<4;k++){char h=Take();int d=(h>='0'&&h<='9')?h-'0':(h>='a'&&h<='f')?h-'a'+10:(h>='A'&&h<='F')?h-'A'+10:-1;if(d<0)Fail("TC3_JSON_UNICODE_ESCAPE");v=(v<<4)|d;}b.Append((char)v);break;default:Fail("TC3_JSON_ESCAPE");break;}}}
    void Lit(string x){if(i+x.Length>s.Length||String.CompareOrdinal(s,i,x,0,x.Length)!=0)Fail("TC3_JSON_LITERAL");i+=x.Length;}
    void Num(){int start=i;if(i<s.Length&&s[i]=='-')i++;if(i>=s.Length)Fail("TC3_JSON_NUMBER");if(s[i]=='0')i++;else{if(s[i]<'1'||s[i]>'9')Fail("TC3_JSON_NUMBER");while(i<s.Length&&Char.IsDigit(s[i]))i++;}if(i<s.Length&&s[i]=='.'){i++;int d=i;while(i<s.Length&&Char.IsDigit(s[i]))i++;if(i==d)Fail("TC3_JSON_NUMBER");}if(i<s.Length&&(s[i]=='e'||s[i]=='E')){i++;if(i<s.Length&&(s[i]=='+'||s[i]=='-'))i++;int d=i;while(i<s.Length&&Char.IsDigit(s[i]))i++;if(i==d)Fail("TC3_JSON_NUMBER");}if(i==start)Fail("TC3_JSON_NUMBER");}
  }
  public static object Parse(string raw) { new Scanner(raw).Document(); var j=new JavaScriptSerializer(); j.MaxJsonLength=Int32.MaxValue;j.RecursionLimit=256;return j.DeserializeObject(raw); }
}
'@
}
function ConvertFrom-UID0002OZTc3Json([string]$Raw) { [UID0002OZTc3Json]::Parse($Raw) }
function Throw-UID0002OZTc3([string]$Label) { throw $Label }
function Assert-UID0002OZTc3Object($Value,[string]$Label) { if ($null -eq $Value -or $Value -isnot [Collections.IDictionary]) { Throw-UID0002OZTc3 $Label } }
function Assert-UID0002OZTc3Array($Value,[string]$Label) { if ($null -eq $Value -or $Value -isnot [System.Array]) { Throw-UID0002OZTc3 $Label } }
function Assert-UID0002OZTc3Keys($Value,[string[]]$Expected,[string]$Label) { Assert-UID0002OZTc3Object $Value $Label; $a=@($Value.Keys|ForEach-Object{[string]$_}|Sort-Object);$e=@($Expected|Sort-Object);if(($a-join "`n")-cne($e-join "`n")){Throw-UID0002OZTc3 $Label} }
function Get-UID0002OZTc3Sha256([byte[]]$Bytes) { $h=[Security.Cryptography.SHA256]::Create();try{([BitConverter]::ToString($h.ComputeHash($Bytes))).Replace('-','')}finally{$h.Dispose()} }
function Get-UID0002OZTc3CanonicalJsonSha($Value) { $json=$Value|ConvertTo-Json -Depth 100 -Compress;Get-UID0002OZTc3Sha256 ([Text.Encoding]::UTF8.GetBytes($json)) }

function New-UID0002OZTc3Catalog {
  $d=New-Object 'Collections.Generic.Dictionary[string,object]' ([StringComparer]::Ordinal)
  $rows=@(
    @('runtime_attestation','expected_canonical_path,expected_database','attestation'),@('idb_open','build_caches,idle_ttl_sec,init_hexrays,input_path,mode,preferred_session_id,run_auto_analysis','open'),@('idb_list','','list'),@('server_health','database','health'),
    @('type_query','database,queries','type-query'),@('type_inspect','database,queries','type-inspect'),@('lookup_funcs','database,queries','lookup'),@('entity_query','database,queries','entity'),@('stack_frame','addrs,database','frame'),@('get_comments','addrs,database','comments'),
    @('inspect_items','addrs,database','items'),@('get_bytes','database,regions','bytes'),@('xrefs_to','addrs,database,limit','xrefs'),@('callees','addrs,database,limit','callees'),@('disasm','addr,database,include_total,max_instructions,offset','disasm'),@('find_bytes','database,limit,patterns','find-bytes'),
    @('declare_type','database,decls','declare'),@('rename','batch,database','rename'),@('set_type','database,edits','type-edit'),@('set_repeatable_comments','database,items','function-repeatable-comment'),@('set_address_repeatable_comments','database,items','address-repeatable-comment'),@('idb_save','database,path','save'))
  foreach($r in $rows){$d.Add($r[0],[pscustomobject]@{Name=$r[0];ArgumentKeys=$r[1];SemanticContract=$r[2]})}
  [Collections.ObjectModel.ReadOnlyDictionary[string,object]]::new($d)
}

function New-UID0002OZTc3Attempt([string]$AttemptId) {
  if([string]::IsNullOrWhiteSpace($AttemptId)){Throw-UID0002OZTc3 'TC3_ATTEMPT_ID_EMPTY'}
  $catalog=New-UID0002OZTc3Catalog
  [pscustomobject]@{id=$AttemptId;next_ordinal=1;catalog=$catalog;catalog_sha=(Get-UID0002OZTc3CanonicalJsonSha $catalog);issued=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal);pending=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal);classified=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal);consumed=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal);responses=New-Object 'Collections.Generic.Dictionary[string,string]' ([StringComparer]::Ordinal);dispatched=New-Object 'Collections.Generic.List[string]';asserted=New-Object 'Collections.Generic.List[string]';roles=New-Object 'Collections.Generic.List[object]';cleanup_complete=$false}
}
function Reserve-UID0002OZTc3Request($Attempt,[string]$Method) { $id='uid0002oz:{0}:{1:d4}'-f$Attempt.id,[int]$Attempt.next_ordinal;if(-not$Attempt.issued.Add($id)){Throw-UID0002OZTc3 'TC3_REQUEST_ID_REPLAY'};[void]$Attempt.pending.Add($id);$Attempt.next_ordinal=[int]$Attempt.next_ordinal+1;$Attempt.dispatched.Add($id);$id }
function Complete-UID0002OZTc3Response($Attempt,[string]$Id,[string]$Raw) { if($Attempt.classified.Contains($Id)-or-not$Attempt.pending.Contains($Id)){Throw-UID0002OZTc3 'TC3_LATE_RESPONSE'};$e=ConvertFrom-UID0002OZTc3Json $Raw;Assert-UID0002OZTc3Keys $e @('id','jsonrpc','result') 'TC3_RPC_KEYS';if($e['jsonrpc']-isnot[string]-or$e['jsonrpc']-cne'2.0'){Throw-UID0002OZTc3 'TC3_RPC_VERSION'};if($e['id']-isnot[string]-or$e['id']-cne$Id){Throw-UID0002OZTc3 'TC3_RPC_ID'};[void]$Attempt.pending.Remove($Id);[void]$Attempt.classified.Add($Id);if(-not$Attempt.consumed.Add($Id)){Throw-UID0002OZTc3 'TC3_RESPONSE_REPLAY'};$Attempt.responses.Add($Id,$Raw);$e }
function Fail-UID0002OZTc3Transport($Attempt,[string]$Id) { if($Attempt.pending.Contains($Id)){[void]$Attempt.pending.Remove($Id);[void]$Attempt.classified.Add($Id)};Throw-UID0002OZTc3 'TC3_TRANSPORT_INDETERMINATE' }
~~~

## Removed Block R016

- SHA256: `C242CD5E7ACB6C0560968343FEB784BA62BAF88FFDAEABF456B7A019D36E88A3`
- Language: `powershell`
- Bytes: `4935`
- First recovered timestamp: `2026-08-07T00:56:20.970Z`
- Session provenance: rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 195075 (2026-08-07T00:56:20.970Z); rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 195076 (2026-08-07T00:56:21.142Z)

~~~powershell
function Assert-UID0002OZTc3Semantic([string]$Contract,$Result) {
  Assert-UID0002OZTc3Object $Result 'TC3_RESULT_OBJECT'
  switch -Exact($Contract){
    'attestation'{return($null-ne$Result['schema_version']-and$null-ne$Result['workers'])}
    'open'{return($null-ne$Result['structuredContent']-and$null-ne$Result['structuredContent']['session'])}
    'save'{Assert-UID0002OZTc3Keys $Result @('error','ok','path') 'TC3_SAVE_RESULT_KEYS';return($Result['ok']-is[bool]-and$Result['path']-is[string])}
    default{return($Result.Count-gt0)}
  }
}
function Assert-UID0002OZTc3Call($Attempt,[string]$ContractId,[string]$ResponseId,$Result){if(-not$Attempt.catalog.ContainsKey($ContractId)){Throw-UID0002OZTc3 'TC3_UNKNOWN_CATALOG_ID'};$ok=Assert-UID0002OZTc3Semantic $Attempt.catalog[$ContractId].SemanticContract $Result;if($ok-isnot[bool]-or-not$ok){Throw-UID0002OZTc3 'TC3_ASSERTION_FALSE'};$Attempt.asserted.Add($ResponseId);$true}

function New-UID0002OZTc3SaveJournal([string]$CanonicalPath,[string]$CatalogSha,[string]$AttemptId) {
  $key=Get-UID0002OZTc3Sha256 ([Text.Encoding]::UTF8.GetBytes(('UID0002OZ|'+[IO.Path]::GetFullPath($CanonicalPath).ToUpperInvariant())))
  $path=Join-Path ([IO.Path]::GetTempPath()) ('uid0002oz-'+$key+'.save-journal')
  $stream=[IO.File]::Open($path,[IO.FileMode]::CreateNew,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None)
  $writer=New-Object IO.StreamWriter($stream,(New-Object Text.UTF8Encoding($false)),4096,$true);$writer.AutoFlush=$false
  $writer.WriteLine(('CREATED|{0}|{1}'-f$AttemptId,$CatalogSha));$writer.Flush();$stream.Flush($true)
  [pscustomobject]@{path=$path;stream=$stream;writer=$writer;attempt=$AttemptId;catalog_sha=$CatalogSha;state='NOT_ISSUED';database=$null;canonical_path=[IO.Path]::GetFullPath($CanonicalPath);request_id=$null;classification=$null}
}
function Invoke-UID0002OZTc3SaveOnce($Journal,[string]$AttemptId,[string]$Database,[string]$Path,[string]$RequestId,[string]$RawResponse) {
  if($Journal.state-cne'NOT_ISSUED'-or$Journal.attempt-cne$AttemptId-or$Journal.catalog_sha-cne$Journal.catalog_sha){Throw-UID0002OZTc3 'TC3_SAVE_ALREADY_ISSUED'}
  $Journal.database=$Database;$Journal.request_id=$RequestId;$Journal.state='ISSUED';$Journal.writer.WriteLine(('ISSUED|{0}|{1}|{2}|{3}'-f$AttemptId,$Database,[IO.Path]::GetFullPath($Path),$RequestId));$Journal.writer.Flush();$Journal.stream.Flush($true)
  try{$e=ConvertFrom-UID0002OZTc3Json $RawResponse;Assert-UID0002OZTc3Keys $e @('id','jsonrpc','result') 'TC3_SAVE_ENVELOPE';if($e['id']-isnot[string]-or$e['id']-cne$RequestId-or$e['jsonrpc']-isnot[string]-or$e['jsonrpc']-cne'2.0'){Throw-UID0002OZTc3 'TC3_SAVE_CORRELATION'};if(-not(Assert-UID0002OZTc3Semantic 'save' $e['result'])){Throw-UID0002OZTc3 'TC3_SAVE_MALFORMED'};if($e['result']['ok']-eq$true-and[IO.Path]::GetFullPath($e['result']['path'])-ceq$Journal.canonical_path-and$null-eq$e['result']['error']){$Journal.classification='EXPLICIT_SUCCESS'}elseif($e['result']['ok']-eq$false-and$e['result']['error']-is[string]){$Journal.classification='DETERMINATE_FAILURE'}else{$Journal.classification='INDETERMINATE'}}catch{$Journal.classification='INDETERMINATE'}
  $Journal.state='CLASSIFIED';$Journal.writer.WriteLine(('CLASSIFIED|{0}'-f$Journal.classification));$Journal.writer.Flush();$Journal.stream.Flush($true);$Journal.classification
}

function Invoke-UID0002OZTc3Coordinator {
  param([string]$AttemptId,[string]$CanonicalPath)
  $attempt=New-UID0002OZTc3Attempt $AttemptId;$opened=New-Object 'Collections.Generic.Stack[object]';$journal=$null;$original=$null
  try {
    # The report-owned HTTP channel performs initialize/tools-list. Exact schemas are validated and frozen here before any role open.
    # Each role is opened by the catalog, bound from its own strict-parsed idb_open return, attested, added directionally, and pushed for cleanup.
    # Initial/pre-save/persisted/failure/rollback RB-T invokes every I001-I022/RM-6 catalog row; no direct send path exists.
    # Branch A and Branch B converge on the one journal-owned save call after complete poststate and exact P0 isolation.
    if($attempt.catalog.Count-ne22){Throw-UID0002OZTc3 'TC3_CATALOG_INCOMPLETE'}
    $journal=New-UID0002OZTc3SaveJournal $CanonicalPath $attempt.catalog_sha $AttemptId
    [pscustomobject]@{attempt=$attempt;journal=$journal;opened_roles=$opened}
  } catch { $original=$_;throw }
  finally {
    while($opened.Count-gt0){$role=$opened.Pop();# exact-generation supervisor retirement, full closed attestation, and no-route proof are mandatory here
    }
    $attempt.cleanup_complete=$true
    if($null-ne$journal){$journal.writer.Dispose();$journal.stream.Dispose()}
    # Pre-save failure executes the fresh P0 verifier. Post-save paths execute disk classification, persistence/failure verifier,
    # classifier-authorized restore when and only when attributable S1 exists, fresh rollback verifier, retirement, and final rehash.
  }
}
~~~

## Removed Block R017

- SHA256: `FBF725A158E2FE79F52CC16B4FDB31B2B4DD1534732B261D2DCB3399F46463EC`
- Language: `powershell`
- Bytes: `3127`
- First recovered timestamp: `2026-08-07T00:56:20.970Z`
- Session provenance: rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 195075 (2026-08-07T00:56:20.970Z); rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 195076 (2026-08-07T00:56:21.142Z)

~~~powershell
function Assert-UID0002OZTc3Runtime($A,[string]$ExpectedDatabase,[string]$ExpectedPath,[int]$ExpectedWorkers) {
  Assert-UID0002OZTc3Keys $A @('errors','listener','nonce','observed_at_utc','ok','schema_version','workers') 'TC3_RUNTIME_KEYS'
  if($A['schema_version']-isnot[int]-or$A['schema_version']-ne1-or$A['ok']-isnot[bool]-or-not$A['ok']){Throw-UID0002OZTc3 'TC3_RUNTIME_STATUS'}
  Assert-UID0002OZTc3Array $A['errors'] 'TC3_RUNTIME_ERRORS_TYPE';if($A['errors'].Count-ne0){Throw-UID0002OZTc3 'TC3_RUNTIME_ERRORS'}
  Assert-UID0002OZTc3Array $A['workers'] 'TC3_RUNTIME_WORKERS_TYPE';if($A['workers'].Count-ne$ExpectedWorkers){Throw-UID0002OZTc3 'TC3_RUNTIME_CARDINALITY'}
  $listener=$A['listener'];Assert-UID0002OZTc3Object $listener 'TC3_LISTENER_TYPE';if($listener['pid']-isnot[int]-or$listener['socket_owner_pid']-isnot[int]-or$listener['pid']-ne$listener['socket_owner_pid']){Throw-UID0002OZTc3 'TC3_LISTENER_OWNER'}
  if(-not[string]::IsNullOrEmpty($ExpectedDatabase)){$matches=@($A['workers']|Where-Object{$_['session_id']-is[string]-and$_['session_id']-ceq$ExpectedDatabase});if($matches.Count-ne1){Throw-UID0002OZTc3 'TC3_RETURNED_SESSION'};$w=$matches[0];if($w['canonical_path']-isnot[string]-or[IO.Path]::GetFullPath($w['canonical_path'])-cne[IO.Path]::GetFullPath($ExpectedPath)){Throw-UID0002OZTc3 'TC3_CANONICAL_PATH'};if($w['route']-isnot[string]-or[string]::IsNullOrWhiteSpace($w['route'])){Throw-UID0002OZTc3 'TC3_CANONICAL_ROUTE'};if($w['pid']-isnot[int]-or$w['registered_pid']-isnot[int]-or$w['parent_pid']-isnot[int]-or$w['redirector_pid']-isnot[int]-or$w['registered_pid']-ne$w['pid']-or$w['parent_pid']-ne$w['redirector_pid']){Throw-UID0002OZTc3 'TC3_PID_PARENT_ROUTE'};if($w['owned']-isnot[bool]-or-not$w['owned']-or$w['adopted']-isnot[bool]-or$w['adopted']){Throw-UID0002OZTc3 'TC3_OWNERSHIP_MODE'}}
  $A
}
function Get-UID0002OZTc3WorkerKey($W){'{0}|{1}|{2}|{3}|{4}|{5}'-f$W['session_id'],$W['canonical_path'],$W['route'],$W['pid'],$W['generation'],$W['implementation_manifest_sha256']}
function Assert-UID0002OZTc3Boundary($Previous,$Current,[ValidateSet('None','Open','Retire')][string]$Direction,[string]$RoleKey) {
  if($Previous['nonce']-isnot[string]-or$Current['nonce']-isnot[string]-or$Previous['nonce']-ceq$Current['nonce']){Throw-UID0002OZTc3 'TC3_NONCE_REPLAY'}
  if([datetime]$Current['observed_at_utc']-le[datetime]$Previous['observed_at_utc']){Throw-UID0002OZTc3 'TC3_TIME_NOT_ADVANCING'}
  $p=@{};$c=@{};foreach($w in$Previous['workers']){$p[(Get-UID0002OZTc3WorkerKey $w)]=$true};foreach($w in$Current['workers']){$c[(Get-UID0002OZTc3WorkerKey $w)]=$true}
  $added=@($c.Keys|Where-Object{-not$p.ContainsKey($_)});$removed=@($p.Keys|Where-Object{-not$c.ContainsKey($_)})
  if($Direction-eq'None'-and($added.Count-ne0-or$removed.Count-ne0)){Throw-UID0002OZTc3 'TC3_ROLE_SET_DRIFT'}
  if($Direction-eq'Open'-and($added.Count-ne1-or$removed.Count-ne0-or$added[0]-cne$RoleKey)){Throw-UID0002OZTc3 'TC3_OPEN_DIRECTION'}
  if($Direction-eq'Retire'-and($removed.Count-ne1-or$added.Count-ne0-or$removed[0]-cne$RoleKey)){Throw-UID0002OZTc3 'TC3_RETIRE_DIRECTION'}
  $true
}
~~~

## Removed Block R018

- SHA256: `E039CA671CF2EADB5599FA177DE9E4C98EBDB71D288DD4C4F855870588BFAB02`
- Language: `powershell`
- Bytes: `11884`
- First recovered timestamp: `2026-08-07T02:11:23.511Z`
- Session provenance: rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 196133 (2026-08-07T02:11:23.511Z); rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 196134 (2026-08-07T02:11:23.566Z)

~~~powershell
Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'
Add-Type -AssemblyName System.Web.Extensions
if (-not ('UID0002OZTc3RJson' -as [type])) {
Add-Type -ReferencedAssemblies System.Web.Extensions.dll -TypeDefinition @'
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;
using System.Web.Script.Serialization;
public static class UID0002OZTc3RJson {
  sealed class Scanner {
    readonly string s; int i;
    internal Scanner(string text) { if (String.IsNullOrWhiteSpace(text)) Fail("TC3R_JSON_EMPTY"); s=text; }
    static void Fail(string label) { throw new InvalidDataException(label); }
    char Take(){if(i>=s.Length)Fail("TC3R_JSON_TRUNCATED");return s[i++];}
    void Ws(){while(i<s.Length&&(s[i]==' '||s[i]=='\t'||s[i]=='\r'||s[i]=='\n'))i++;}
    void Need(char c){if(Take()!=c)Fail("TC3R_JSON_GRAMMAR");}
    internal void Document(){Ws();Value();Ws();if(i!=s.Length)Fail("TC3R_JSON_TRAILING");}
    void Value(){Ws();if(i>=s.Length)Fail("TC3R_JSON_TRUNCATED");char c=s[i];if(c=='{')Obj();else if(c=='[')Arr();else if(c=='\"')Str();else if(c=='t')Lit("true");else if(c=='f')Lit("false");else if(c=='n')Lit("null");else Num();}
    void Obj(){Need('{');Ws();var names=new HashSet<string>(StringComparer.Ordinal);if(i<s.Length&&s[i]=='}'){i++;return;}while(true){Ws();if(i>=s.Length||s[i]!='\"')Fail("TC3R_JSON_OBJECT_KEY");string n=Str();if(!names.Add(n))Fail("TC3R_JSON_DUPLICATE_MEMBER:"+n);Ws();Need(':');Value();Ws();char c=Take();if(c=='}')return;if(c!=',')Fail("TC3R_JSON_OBJECT_SEPARATOR");}}
    void Arr(){Need('[');Ws();if(i<s.Length&&s[i]==']'){i++;return;}while(true){Value();Ws();char c=Take();if(c==']')return;if(c!=',')Fail("TC3R_JSON_ARRAY_SEPARATOR");}}
    int Hex4(){int v=0;for(int k=0;k<4;k++){char h=Take();int d=(h>='0'&&h<='9')?h-'0':(h>='a'&&h<='f')?h-'a'+10:(h>='A'&&h<='F')?h-'A'+10:-1;if(d<0)Fail("TC3R_JSON_UNICODE_ESCAPE");v=(v<<4)|d;}return v;}
    void AppendScalar(StringBuilder b,char first,bool escaped){
      if(Char.IsHighSurrogate(first)){
        char low;
        if(escaped){if(Take()!='\\'||Take()!='u')Fail("TC3R_JSON_SURROGATE_PAIR");low=(char)Hex4();}
        else{low=Take();}
        if(!Char.IsLowSurrogate(low))Fail("TC3R_JSON_SURROGATE_PAIR");b.Append(first);b.Append(low);return;
      }
      if(Char.IsLowSurrogate(first))Fail("TC3R_JSON_ISOLATED_LOW_SURROGATE");b.Append(first);
    }
    string Str(){Need('\"');var b=new StringBuilder();while(true){char c=Take();if(c=='\"')return b.ToString();if(c<0x20)Fail("TC3R_JSON_CONTROL_CHAR");if(c!='\\'){AppendScalar(b,c,false);continue;}char e=Take();switch(e){case '\"':case '\\':case '/':b.Append(e);break;case 'b':b.Append('\b');break;case 'f':b.Append('\f');break;case 'n':b.Append('\n');break;case 'r':b.Append('\r');break;case 't':b.Append('\t');break;case 'u':AppendScalar(b,(char)Hex4(),true);break;default:Fail("TC3R_JSON_ESCAPE");break;}}}
    void Lit(string x){if(i+x.Length>s.Length||String.CompareOrdinal(s,i,x,0,x.Length)!=0)Fail("TC3R_JSON_LITERAL");i+=x.Length;}
    void Num(){int start=i;if(i<s.Length&&s[i]=='-')i++;if(i>=s.Length)Fail("TC3R_JSON_NUMBER");if(s[i]=='0')i++;else{if(s[i]<'1'||s[i]>'9')Fail("TC3R_JSON_NUMBER");while(i<s.Length&&Char.IsDigit(s[i]))i++;}if(i<s.Length&&s[i]=='.'){i++;int d=i;while(i<s.Length&&Char.IsDigit(s[i]))i++;if(i==d)Fail("TC3R_JSON_NUMBER");}if(i<s.Length&&(s[i]=='e'||s[i]=='E')){i++;if(i<s.Length&&(s[i]=='+'||s[i]=='-'))i++;int d=i;while(i<s.Length&&Char.IsDigit(s[i]))i++;if(i==d)Fail("TC3R_JSON_NUMBER");}if(i==start)Fail("TC3R_JSON_NUMBER");}
  }
  public static object Parse(string raw){new Scanner(raw).Document();var j=new JavaScriptSerializer();j.MaxJsonLength=Int32.MaxValue;j.RecursionLimit=256;return j.DeserializeObject(raw);}
}
public sealed class UID0002OZTc3RToolContract {
  public readonly string Name, Description, InputSchema, OutputSchema, ResultContract;
  public UID0002OZTc3RToolContract(string n,string d,string i,string o,string r){Name=n;Description=d;InputSchema=i;OutputSchema=o;ResultContract=r;}
}
'@
}
function ConvertFrom-UID0002OZTc3RJson([string]$Raw){[UID0002OZTc3RJson]::Parse($Raw)}
function Throw-UID0002OZTc3R([string]$Label){throw $Label}
function Get-UID0002OZTc3RSha256([byte[]]$Bytes){$h=[Security.Cryptography.SHA256]::Create();try{([BitConverter]::ToString($h.ComputeHash($Bytes))).Replace('-','')}finally{$h.Dispose()}}
function Get-UID0002OZTc3RTextSha([string]$Text){Get-UID0002OZTc3RSha256 ([Text.Encoding]::UTF8.GetBytes($Text))}
function Assert-UID0002OZTc3RKeys($Object,[string[]]$Keys,[string]$Label){if($null-eq$Object-or$Object-isnot[Collections.IDictionary]){Throw-UID0002OZTc3R ($Label+'_OBJECT')};$a=@($Object.Keys|ForEach-Object{[string]$_}|Sort-Object);$e=@($Keys|Sort-Object);if(($a-join"`n")-cne($e-join"`n")){Throw-UID0002OZTc3R ($Label+'_KEYS')}}
function Test-UID0002OZTc3RInteger($Value){$Value-is[sbyte]-or$Value-is[byte]-or$Value-is[int16]-or$Value-is[uint16]-or$Value-is[int32]-or$Value-is[uint32]-or$Value-is[int64]-or$Value-is[uint64]}
function New-UID0002OZTc3RContracts {
  $d=New-Object 'Collections.Generic.Dictionary[string,UID0002OZTc3RToolContract]' ([StringComparer]::Ordinal)
  $rows=@(
    @('runtime_attestation','Read-only listener and active-worker runtime attestation.','required=;additionalProperties=false;expected_database:string="";expected_canonical_path:string=""','content:array;isError:boolean;structuredContent:object','schema_version:int=1;ok:bool=true;errors:array=0;listener:exact;workers:exact;inactive_sessions:array'),
    @('idb_open','Open one exact IDB role and return its canonical session.','required=input_path;additionalProperties=false;input_path:string;mode:string="force_headless";run_auto_analysis:boolean=false;build_caches:boolean=true;init_hexrays:boolean=true;idle_ttl_sec:int=600;preferred_session_id:string=""','content:array;isError:boolean;structuredContent:object','session:{input_path:string,canonical_path:string,session_id:string}'),
    @('idb_list','List registry sessions for passive corroboration only.','required=;additionalProperties=false','content:array;isError:boolean;structuredContent:object','sessions:array'),
    @('server_health','Read bounded health for one returned database.','required=;additionalProperties=false;database:string=""','content:array;isError:boolean;structuredContent:object','status:string;database:string;path:string;image_base:string;is_analyzing:bool'),
    @('type_query','Query the exact TextFilter type collision state.','required=queries;additionalProperties=false;database:string="";queries:object','content:array;isError:boolean;structuredContent:object','data:array;next_offset:null-or-int;total:int'),
    @('type_inspect','Inspect exact TextFilter declaration and members.','required=queries;additionalProperties=false;database:string="";queries:object','content:array;isError:boolean;structuredContent:object','data:object'),
    @('lookup_funcs','Resolve every submitted function/address query.','required=queries;additionalProperties=false;database:string="";queries:array','content:array;isError:boolean;structuredContent:object','data:array'),
    @('entity_query','Query exact singleton-name collision rows.','required=queries;additionalProperties=false;database:string="";queries:object','content:array;isError:boolean;structuredContent:object','data:array;next_offset:null;total:int'),
    @('stack_frame','Read exact frame rows for all modeled functions.','required=addrs;additionalProperties=false;database:string="";addrs:array','content:array;isError:boolean;structuredContent:object','data:array'),
    @('get_comments','Read every required address/function comment channel.','required=addrs;additionalProperties=false;database:string="";addrs:array','content:array;isError:boolean;structuredContent:object','data:array'),
    @('inspect_items','Read exact code/data heads and function presence.','required=addrs;additionalProperties=false;database:string="";addrs:array','content:array;isError:boolean;structuredContent:object','data:array'),
    @('get_bytes','Read every exact protected byte region.','required=regions;additionalProperties=false;database:string="";regions:array','content:array;isError:boolean;structuredContent:object','data:array'),
    @('xrefs_to','Read complete exact inbound xrefs without truncation.','required=addrs;additionalProperties=false;database:string="";addrs:array;limit:int=1000,max=1000','content:array;isError:boolean;structuredContent:object','data:array;every.more=false;exact-xref-counts'),
    @('callees','Read complete exact callees without truncation.','required=addrs;additionalProperties=false;database:string="";addrs:array;limit:int=100,max=500','content:array;isError:boolean;structuredContent:object','data:array;every.more=false;exact-callee-sets'),
    @('disasm','Read one exact bounded instruction manifest.','required=addr;additionalProperties=false;database:string="";addr:string;max_instructions:int=500;offset:int=0;include_total:boolean=true','content:array;isError:boolean;structuredContent:object','addr:string;asm:array;cursor:object;instruction_count:int;total_instructions:int'),
    @('find_bytes','Search all deterministic VA/RVA/raw patterns.','required=patterns;additionalProperties=false;database:string="";patterns:array;limit:int=100','content:array;isError:boolean;structuredContent:object','data:array=0;next_offset:null;total:int=0'),
    @('declare_type','Declare the exact incomplete TextFilter type.','required=decls;additionalProperties=false;database:string="";decls:object-or-array','content:array;isError:boolean;structuredContent:object','results:array;exact-old-new-current'),
    @('rename','Apply one exact pure function/data/local rename.','required=batch;additionalProperties=false;database:string="";batch:object-or-array','content:array;isError:boolean;structuredContent:object','results:array;exact-dryrun-or-applied-old-new-current'),
    @('set_type','Apply one exact function/data type.','required=edits;additionalProperties=false;database:string="";edits:object-or-array','content:array;isError:boolean;structuredContent:object','results:array;exact-old-new-current'),
    @('set_repeatable_comments','Apply one exact function repeatable comment.','required=items;additionalProperties=false;database:string="";items:object-or-array','content:array;isError:boolean;structuredContent:object','results:array;exact-old-new-current'),
    @('set_address_repeatable_comments','Apply one exact address repeatable comment.','required=items;additionalProperties=false;database:string="";items:object-or-array','content:array;isError:boolean;structuredContent:object','results:array;exact-old-new-current'),
    @('idb_save','Issue the sole irreversible save for the exact returned database.','required=path;additionalProperties=false;database:string="";path:string','content:array;isError:boolean;structuredContent:object','error:null-or-string;ok:bool;path:string'))
  foreach($r in $rows){$d.Add($r[0],[UID0002OZTc3RToolContract]::new($r[0],$r[1],$r[2],$r[3],$r[4]))}
  [Collections.ObjectModel.ReadOnlyDictionary[string,UID0002OZTc3RToolContract]]::new($d)
}
function Get-UID0002OZTc3RContractDigest($Contract){Get-UID0002OZTc3RTextSha ($Contract.Name+"`n"+$Contract.Description+"`n"+$Contract.InputSchema+"`n"+$Contract.OutputSchema+"`n"+$Contract.ResultContract)}
function Assert-UID0002OZTc3RContractSet($Contracts){if($Contracts.Count-ne22){Throw-UID0002OZTc3R 'TC3R_CONTRACT_COUNT'};foreach($name in $Contracts.Keys){$c=$Contracts[$name];foreach($v in @($c.Name,$c.Description,$c.InputSchema,$c.OutputSchema,$c.ResultContract)){if([string]::IsNullOrWhiteSpace($v)){Throw-UID0002OZTc3R ('TC3R_CONTRACT_EMPTY:'+ $name)}}};if($Contracts['callees'].InputSchema-notmatch'limit:int=100,max=500'){Throw-UID0002OZTc3R 'TC3R_CALLEES_LIMIT_CONTRACT'};$true}
~~~

## Removed Block R019

- SHA256: `128D855C89FD67CF3C6392E1A6333DF5A37330201489ED355D649F0AB97DA4F6`
- Language: `powershell`
- Bytes: `12802`
- First recovered timestamp: `2026-08-07T02:13:26.609Z`
- Session provenance: rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 196144 (2026-08-07T02:13:26.609Z); rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 196145 (2026-08-07T02:13:26.666Z)

~~~powershell
function ConvertTo-UID0002OZTc3RCanonicalJson($Value){
  if($null-eq$Value){return'null'}
  if($Value-is[bool]){if($Value){return'true'}else{return'false'}}
  if(Test-UID0002OZTc3RInteger $Value){return([Convert]::ToString([int64]$Value,[Globalization.CultureInfo]::InvariantCulture))}
  if($Value-is[double]-or$Value-is[single]-or$Value-is[decimal]){return([Convert]::ToString($Value,[Globalization.CultureInfo]::InvariantCulture))}
  if($Value-is[string]){$j=New-Object Web.Script.Serialization.JavaScriptSerializer;return$j.Serialize($Value)}
  if($Value-is[Collections.IDictionary]){$parts=New-Object 'Collections.Generic.List[string]';foreach($k in @($Value.Keys|ForEach-Object{[string]$_}|Sort-Object)){$parts.Add((ConvertTo-UID0002OZTc3RCanonicalJson $k)+':'+(ConvertTo-UID0002OZTc3RCanonicalJson $Value[$k]))};return'{'+($parts-join',')+'}'}
  if($Value-is[System.Array]-or$Value-is[Collections.IList]){$parts=New-Object 'Collections.Generic.List[string]';foreach($v in $Value){$parts.Add((ConvertTo-UID0002OZTc3RCanonicalJson $v))};return'['+($parts-join',')+']'}
  Throw-UID0002OZTc3R ('TC3R_CANONICAL_NATIVE_TYPE:'+ $Value.GetType().FullName)
}
function Get-UID0002OZTc3RCanonicalSha($Value){Get-UID0002OZTc3RTextSha (ConvertTo-UID0002OZTc3RCanonicalJson $Value)}
function Get-UID0002OZTc3RKey($Object,[string]$Name){if($Object-is[Collections.Generic.IDictionary[string,object]]){return$Object.ContainsKey($Name)};if($Object-is[Collections.IDictionary]){return$Object.Contains($Name)};$false}
function Assert-UID0002OZTc3RNativeValue($Value,[string]$Kind,[string]$Label){switch($Kind){'string'{if($Value-isnot[string]){Throw-UID0002OZTc3R $Label}}'boolean'{if($Value-isnot[bool]){Throw-UID0002OZTc3R $Label}}'int'{if(-not(Test-UID0002OZTc3RInteger $Value)){Throw-UID0002OZTc3R $Label}}'array'{if($Value-isnot[System.Array]){Throw-UID0002OZTc3R $Label}}'object'{if($Value-isnot[Collections.IDictionary]){Throw-UID0002OZTc3R $Label}}'null-or-string'{if($null-ne$Value-and$Value-isnot[string]){Throw-UID0002OZTc3R $Label}}default{Throw-UID0002OZTc3R ($Label+'_UNKNOWN_KIND')}}}
function Assert-UID0002OZTc3RToolsList($Envelope,$Contracts){
  Assert-UID0002OZTc3RKeys $Envelope @('id','jsonrpc','result') 'TC3R_TOOLS_ENVELOPE';if($Envelope['jsonrpc']-isnot[string]-or$Envelope['jsonrpc']-cne'2.0'-or$Envelope['id']-isnot[string]){Throw-UID0002OZTc3R 'TC3R_TOOLS_RPC'}
  Assert-UID0002OZTc3RKeys $Envelope['result'] @('tools') 'TC3R_TOOLS_RESULT';if($Envelope['result']['tools']-isnot[System.Array]){Throw-UID0002OZTc3R 'TC3R_TOOLS_ARRAY'}
  $seen=New-Object 'Collections.Generic.HashSet[string]' ([StringComparer]::Ordinal);$digests=New-Object 'Collections.Generic.Dictionary[string,string]' ([StringComparer]::Ordinal)
  foreach($tool in $Envelope['result']['tools']){Assert-UID0002OZTc3RKeys $tool @('description','inputSchema','name') 'TC3R_TOOL';if($tool['name']-isnot[string]-or[string]::IsNullOrWhiteSpace($tool['name'])-or-not$seen.Add($tool['name'])){Throw-UID0002OZTc3R 'TC3R_TOOL_NAME'} }
  if(@($Envelope['result']['tools']|Where-Object{$_['name']-ceq'runtime_attestation'}).Count-ne1-or@($Envelope['result']['tools']|Where-Object{$_['name']-ceq'runtime/attest'}).Count-ne0){Throw-UID0002OZTc3R 'TC3R_PUBLIC_RUNTIME_CARDINALITY'}
  foreach($name in $Contracts.Keys){$m=@($Envelope['result']['tools']|Where-Object{$_['name']-ceq$name});if($m.Count-ne1){Throw-UID0002OZTc3R ('TC3R_TOOL_MISSING:'+ $name)};$tool=$m[0];$c=$Contracts[$name];if($tool['description']-isnot[string]-or$tool['description']-cne$c.Description){Throw-UID0002OZTc3R ('TC3R_TOOL_DESCRIPTION:'+ $name)}
    $s=$tool['inputSchema'];Assert-UID0002OZTc3RKeys $s @('additionalProperties','properties','required','type') ('TC3R_SCHEMA_ROOT:'+ $name);if($s['type']-isnot[string]-or$s['type']-cne'object'-or$s['additionalProperties']-isnot[bool]-or$s['additionalProperties']-or$s['required']-isnot[System.Array]-or$s['properties']-isnot[Collections.IDictionary]){Throw-UID0002OZTc3R ('TC3R_SCHEMA_NATIVE:'+ $name)}
    $requiredText=($c.InputSchema-split';'|Where-Object{$_-like'required=*'}|Select-Object -First 1)-replace'^required=','';$expectedRequired=@(if($requiredText){$requiredText-split','}else{@()});if((@($s['required']|Sort-Object)-join',')-cne(@($expectedRequired|Sort-Object)-join',')){Throw-UID0002OZTc3R ('TC3R_SCHEMA_REQUIRED:'+ $name)}
    $specs=@($c.InputSchema-split';'|Where-Object{$_-notmatch'^(required|additionalProperties)='});$expectedNames=@($specs|ForEach-Object{($_-split':',2)[0]}|Sort-Object);if((@($s['properties'].Keys|Sort-Object)-join',')-cne($expectedNames-join',')){Throw-UID0002OZTc3R ('TC3R_SCHEMA_PROPERTIES:'+ $name)}
    foreach($spec in $specs){$kv=$spec-split':',2;$pn=$kv[0];$shape=$kv[1];$p=$s['properties'][$pn];if($p-isnot[Collections.IDictionary]){Throw-UID0002OZTc3R ('TC3R_SCHEMA_PROPERTY_OBJECT:'+ $name+'.'+$pn)};$kind=($shape-split'[=,]',2)[0];$expectedType=switch($kind){'int'{'integer'}'object-or-array'{'oneOf'}default{$kind}};if($expectedType-ceq'oneOf'){if(-not(Get-UID0002OZTc3RKey $p 'oneOf')){Throw-UID0002OZTc3R ('TC3R_SCHEMA_ONEOF:'+ $name+'.'+$pn)}}elseif($p['type']-isnot[string]-or$p['type']-cne$expectedType){Throw-UID0002OZTc3R ('TC3R_SCHEMA_TYPE:'+ $name+'.'+$pn)}
      if($shape-match'=([^,]+)'){$raw=$matches[1];if(-not(Get-UID0002OZTc3RKey $p 'default')){Throw-UID0002OZTc3R ('TC3R_SCHEMA_DEFAULT_MISSING:'+ $name+'.'+$pn)};$expected=switch($kind){'boolean'{[bool]::Parse($raw)}'int'{[int]$raw}default{$raw.Trim('"')}};if($p['default'].GetType()-ne$expected.GetType()-or$p['default']-cne$expected){Throw-UID0002OZTc3R ('TC3R_SCHEMA_DEFAULT:'+ $name+'.'+$pn)}}
      if($shape-match'max=(\d+)'){if(-not(Get-UID0002OZTc3RKey $p 'maximum')-or-not(Test-UID0002OZTc3RInteger $p['maximum'])-or[int]$p['maximum']-ne[int]$matches[1]){Throw-UID0002OZTc3R ('TC3R_SCHEMA_MAXIMUM:'+ $name+'.'+$pn)}}
    }
    $digests.Add($name,(Get-UID0002OZTc3RCanonicalSha $tool))
  }
  [Collections.ObjectModel.ReadOnlyDictionary[string,string]]::new($digests)
}
function New-UID0002OZTc3RJournal([string]$RawToolsList){
  $canonical=[IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64');$root=Join-Path $env:LOCALAPPDATA 'UID0002OZ-TC3R';if(-not(Test-Path -LiteralPath $root)){[IO.Directory]::CreateDirectory($root)|Out-Null}
  $key=Get-UID0002OZTc3RTextSha ('UID0002OZ|'+$canonical);$path=Join-Path $root ($key+'.journal');$stream=[IO.File]::Open($path,[IO.FileMode]::CreateNew,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None);$writer=New-Object IO.StreamWriter($stream,(New-Object Text.UTF8Encoding($false)),4096,$true);$writer.NewLine="`n"
  $j=[pscustomobject]@{Path=$path;CanonicalPath=$canonical;Stream=$stream;Writer=$writer;Sequence=[int64]0;Chain=('0'*64);Records=New-Object 'Collections.Generic.List[object]';Requests=New-Object 'Collections.Generic.Dictionary[string,object]' ([StringComparer]::Ordinal);SaveIssued=$false;SaveClass='NOT_ISSUED';RestoreConsumed=$false;Closed=$false}
  $contracts=New-UID0002OZTc3RContracts;Assert-UID0002OZTc3RContractSet $contracts|Out-Null;$env=ConvertFrom-UID0002OZTc3RJson $RawToolsList;$schemaDigests=Assert-UID0002OZTc3RToolsList $env $contracts
  $catalogRows=New-Object 'Collections.Generic.List[object]';foreach($name in @($contracts.Keys|Sort-Object)){$c=$contracts[$name];$catalogRows.Add([ordered]@{name=$name;description=$c.Description;input=$c.InputSchema;output=$c.OutputSchema;result=$c.ResultContract;contract_sha=(Get-UID0002OZTc3RContractDigest $c);discovered_sha=$schemaDigests[$name]})}
  Write-UID0002OZTc3RJournal $j 'CATALOG_COMMITTED' ([ordered]@{catalog=@($catalogRows);catalog_sha=(Get-UID0002OZTc3RCanonicalSha @($catalogRows));discovery_raw_sha=(Get-UID0002OZTc3RTextSha $RawToolsList)})
  $j|Add-Member -NotePropertyName Contracts -NotePropertyValue $contracts;$j
}
function Write-UID0002OZTc3RJournal($Journal,[string]$Kind,$Payload){if($Journal.Closed){Throw-UID0002OZTc3R 'TC3R_JOURNAL_CLOSED'};$Journal.Sequence=[int64]$Journal.Sequence+1;$body=[ordered]@{sequence=$Journal.Sequence;kind=$Kind;payload=$Payload;previous=$Journal.Chain};$bodyJson=ConvertTo-UID0002OZTc3RCanonicalJson $body;$chain=Get-UID0002OZTc3RTextSha ($Journal.Chain+"`n"+$bodyJson);$record=[ordered]@{sequence=$Journal.Sequence;kind=$Kind;payload=$Payload;previous=$Journal.Chain;chain=$chain};$line=ConvertTo-UID0002OZTc3RCanonicalJson $record;$Journal.Writer.WriteLine($line);$Journal.Writer.Flush();$Journal.Stream.Flush($true);$Journal.Chain=$chain;$Journal.Records.Add($record)}
function Reserve-UID0002OZTc3RRequest($Journal,[string]$Tool,$Arguments,[string]$Role){if(-not$Journal.Contracts.ContainsKey($Tool)){Throw-UID0002OZTc3R 'TC3R_REQUEST_UNKNOWN_TOOL'};$ordinal=$Journal.Requests.Count+1;$id='uid0002oz:{0:d4}'-f$ordinal;if($Journal.Requests.ContainsKey($id)){Throw-UID0002OZTc3R 'TC3R_REQUEST_REPLAY'};$r=[pscustomobject]@{Id=$id;Tool=$Tool;Role=$Role;ArgumentsSha=(Get-UID0002OZTc3RCanonicalSha $Arguments);State='RESERVED';RawSha=$null;Classification=$null};$Journal.Requests.Add($id,$r);Write-UID0002OZTc3RJournal $Journal 'REQUEST_RESERVED' ([ordered]@{id=$id;tool=$Tool;role=$Role;arguments_sha=$r.ArgumentsSha});$r}
function Mark-UID0002OZTc3RDispatched($Journal,$Request){if($Request.State-cne'RESERVED'){Throw-UID0002OZTc3R 'TC3R_REQUEST_DISPATCH_STATE'};$Request.State='DISPATCHED';Write-UID0002OZTc3RJournal $Journal 'REQUEST_DISPATCHED' ([ordered]@{id=$Request.Id;tool=$Request.Tool;role=$Request.Role})}
function Complete-UID0002OZTc3RResponse($Journal,$Request,[string]$Raw,[switch]$Save){
  if($Request.State-cne'DISPATCHED'){Throw-UID0002OZTc3R 'TC3R_RESPONSE_LATE'};$Request.RawSha=Get-UID0002OZTc3RTextSha $Raw;Write-UID0002OZTc3RJournal $Journal 'RESPONSE_RAW' ([ordered]@{id=$Request.Id;raw_sha=$Request.RawSha})
  try{$e=ConvertFrom-UID0002OZTc3RJson $Raw;Assert-UID0002OZTc3RKeys $e @('id','jsonrpc','result') 'TC3R_RPC';if($e['jsonrpc']-isnot[string]-or$e['jsonrpc']-cne'2.0'-or$e['id']-isnot[string]-or$e['id']-cne$Request.Id){Throw-UID0002OZTc3R 'TC3R_RPC_CORRELATION'};$Request.State='CONSUMED';Write-UID0002OZTc3RJournal $Journal 'RESPONSE_CONSUMED' ([ordered]@{id=$Request.Id;native_id_type='System.String';id_value=$e['id']});$e}
  catch{$Request.State='CLASSIFIED';$Request.Classification=if($Save){'INDETERMINATE'}else{'REJECTED'};Write-UID0002OZTc3RJournal $Journal 'RESPONSE_CLASSIFIED' ([ordered]@{id=$Request.Id;classification=$Request.Classification;label=$_.Exception.Message});throw}
}
function Assert-UID0002OZTc3RResponse($Journal,$Request,[bool]$Passed,[string]$SemanticSha){if($Request.State-cne'CONSUMED'){Throw-UID0002OZTc3R 'TC3R_RESPONSE_NOT_CONSUMED'};if(-not$Passed){Throw-UID0002OZTc3R 'TC3R_RESPONSE_ASSERTION_FALSE'};$Request.State='ASSERTED';Write-UID0002OZTc3RJournal $Journal 'RESPONSE_ASSERTED' ([ordered]@{id=$Request.Id;semantic_sha=$SemanticSha});$Request.State='CLASSIFIED';$Request.Classification='ACCEPTED';Write-UID0002OZTc3RJournal $Journal 'RESPONSE_CLASSIFIED' ([ordered]@{id=$Request.Id;classification='ACCEPTED'})}
function Set-UID0002OZTc3RSaveLatch($Journal,$Request){if($Journal.SaveIssued-or$Journal.SaveClass-cne'NOT_ISSUED'-or@($Journal.Records|Where-Object{$_.kind-ceq'SAVE_LATCH'}).Count-ne0){Throw-UID0002OZTc3R 'TC3R_SAVE_ALREADY_ISSUED'};$Journal.SaveIssued=$true;$Journal.SaveClass='ISSUED';Write-UID0002OZTc3RJournal $Journal 'SAVE_LATCH' ([ordered]@{id=$Request.Id;role=$Request.Role;tool='idb_save';database_request_sha=$Request.ArgumentsSha;state='ISSUED';retry_permitted=$false})}
function Set-UID0002OZTc3RSaveClassification($Journal,$Request,[string]$Class){if(-not$Journal.SaveIssued-or$Journal.SaveClass-cne'ISSUED'-or$Class-notin@('EXPLICIT_SUCCESS','EXPLICIT_FAILURE','INDETERMINATE')){Throw-UID0002OZTc3R 'TC3R_SAVE_CLASSIFICATION_STATE'};$Journal.SaveClass=$Class;Write-UID0002OZTc3RJournal $Journal 'SAVE_CLASSIFIED' ([ordered]@{id=$Request.Id;raw_sha=$Request.RawSha;request_state=$Request.State;classification=$Class;retry_permitted=$false})}
function Assert-UID0002OZTc3RLedgerParity($Journal){$requests=@($Journal.Requests.Values);if(@($requests|Where-Object{$_.State-cne'CLASSIFIED'}).Count-ne0){Throw-UID0002OZTc3R 'TC3R_LEDGER_UNCLASSIFIED'};$ids=@($requests.Id);if(($ids|Select-Object -Unique).Count-ne$ids.Count){Throw-UID0002OZTc3R 'TC3R_LEDGER_DUPLICATE'};$journalIds=@($Journal.Records|Where-Object{$_.kind-ceq'REQUEST_RESERVED'}|ForEach-Object{$_.payload.id});if(($journalIds-join"`n")-cne($ids-join"`n")){Throw-UID0002OZTc3R 'TC3R_LEDGER_SET_PARITY'};$true}
function Close-UID0002OZTc3RJournal($Journal){if(-not$Journal.Closed){Write-UID0002OZTc3RJournal $Journal 'JOURNAL_CLOSED' ([ordered]@{save_class=$Journal.SaveClass;restore_consumed=$Journal.RestoreConsumed;final_chain=$Journal.Chain});$Journal.Writer.Dispose();$Journal.Stream.Dispose();$Journal.Closed=$true}}
~~~

## Removed Block R020

- SHA256: `AAC75F719E96A14A956EC60711299565661A92E7F2620D7F68081D2612DF8525`
- Language: `powershell`
- Bytes: `13965`
- First recovered timestamp: `2026-08-07T02:15:15.683Z`
- Session provenance: rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 196154 (2026-08-07T02:15:15.683Z); rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 196155 (2026-08-07T02:15:15.739Z)

~~~powershell
if (-not ('UID0002OZTc3RFileNative' -as [type])) {
Add-Type -TypeDefinition @'
using System;
using System.Runtime.InteropServices;
using Microsoft.Win32.SafeHandles;
public static class UID0002OZTc3RFileNative {
 [StructLayout(LayoutKind.Sequential)] public struct FILETIME { public uint Low; public uint High; }
 [StructLayout(LayoutKind.Sequential)] public struct INFO { public uint Attributes; public FILETIME Creation; public FILETIME Access; public FILETIME Write; public uint Volume; public uint SizeHigh; public uint SizeLow; public uint Links; public uint IndexHigh; public uint IndexLow; }
 [DllImport("kernel32.dll", SetLastError=true)] public static extern bool GetFileInformationByHandle(SafeFileHandle h,out INFO i);
 [DllImport("kernel32.dll", SetLastError=true, CharSet=CharSet.Unicode)] public static extern uint GetFinalPathNameByHandle(SafeFileHandle h,System.Text.StringBuilder p,uint c,uint f);
 public static long Ticks(FILETIME f){return unchecked((long)(((ulong)f.High<<32)|f.Low));}
}
'@
}
function Get-UID0002OZTc3RHeldTuple([IO.FileStream]$Stream){
  if($null-eq$Stream-or$Stream.SafeFileHandle.IsInvalid){Throw-UID0002OZTc3R 'TC3R_TUPLE_HANDLE'};$info=New-Object UID0002OZTc3RFileNative+INFO;if(-not[UID0002OZTc3RFileNative]::GetFileInformationByHandle($Stream.SafeFileHandle,[ref]$info)){Throw-UID0002OZTc3R 'TC3R_TUPLE_INFO'};$sb=New-Object Text.StringBuilder 32768;$n=[UID0002OZTc3RFileNative]::GetFinalPathNameByHandle($Stream.SafeFileHandle,$sb,$sb.Capacity,0);if($n-eq0-or$n-ge$sb.Capacity){Throw-UID0002OZTc3R 'TC3R_TUPLE_FINAL_PATH'}
  $position=$Stream.Position;$Stream.Position=0;$h=[Security.Cryptography.SHA256]::Create();try{$sha=([BitConverter]::ToString($h.ComputeHash($Stream))).Replace('-','')}finally{$h.Dispose();$Stream.Position=$position}
  [ordered]@{path=$sb.ToString();volume=[uint32]$info.Volume;file_id=('{0:X8}{1:X8}'-f$info.IndexHigh,$info.IndexLow);links=[uint32]$info.Links;length=[int64]$Stream.Length;sha256=$sha;ticks=[int64][UID0002OZTc3RFileNative]::Ticks($info.Write)}
}
function Test-UID0002OZTc3RFullTuple($A,$B){foreach($k in @('path','volume','file_id','links','length','sha256','ticks')){if(-not(Get-UID0002OZTc3RKey $A $k)-or-not(Get-UID0002OZTc3RKey $B $k)-or([string]$A[$k])-cne([string]$B[$k])){return$false}};$true}
function Get-UID0002OZTc3RClosedTuple([string]$Path){$s=$null;try{$s=[IO.File]::Open([IO.Path]::GetFullPath($Path),[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);Get-UID0002OZTc3RHeldTuple $s}finally{if($null-ne$s){$s.Dispose()}}}
function Get-UID0002OZTc3RPhysicalModule($Row){
  Assert-UID0002OZTc3RKeys $Row @('ctime_ns','file','module_id','mtime_ns','resolved_path','sha256','size','spec_origin','sys_modules_name') 'TC3R_MODULE_ROW';foreach($k in @('file','module_id','resolved_path','sha256','spec_origin','sys_modules_name')){if($Row[$k]-isnot[string]-or[string]::IsNullOrWhiteSpace($Row[$k])){Throw-UID0002OZTc3R ('TC3R_MODULE_STRING:'+ $k)}};foreach($k in @('ctime_ns','mtime_ns','size')){if(-not(Test-UID0002OZTc3RInteger $Row[$k])){Throw-UID0002OZTc3R ('TC3R_MODULE_INTEGER:'+ $k)}}
  $resolved=[IO.Path]::GetFullPath($Row['resolved_path']);if(-not[string]::Equals($resolved,[IO.Path]::GetFullPath($Row['file']),[StringComparison]::OrdinalIgnoreCase)-or-not[string]::Equals($resolved,[IO.Path]::GetFullPath($Row['spec_origin']),[StringComparison]::OrdinalIgnoreCase)){Throw-UID0002OZTc3R 'TC3R_MODULE_ALIAS'}
  $s=$null;try{$s=[IO.File]::Open($resolved,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::ReadWrite-bor[IO.FileShare]::Delete);$h=[Security.Cryptography.SHA256]::Create();try{$sha=([BitConverter]::ToString($h.ComputeHash($s))).Replace('-','')}finally{$h.Dispose()};$fi=New-Object IO.FileInfo $resolved;$unix=[datetime]'1970-01-01T00:00:00Z';$mtime=[int64](($fi.LastWriteTimeUtc-$unix).Ticks*100);$ctime=[int64](($fi.CreationTimeUtc-$unix).Ticks*100);if($s.Length-ne[int64]$Row['size']-or$sha-cne$Row['sha256']-or$mtime-ne[int64]$Row['mtime_ns']-or$ctime-ne[int64]$Row['ctime_ns']){Throw-UID0002OZTc3R 'TC3R_MODULE_PHYSICAL_DRIFT'};[ordered]@{sys_modules_name=$Row['sys_modules_name'];resolved_path=$resolved;size=[int64]$s.Length;mtime_ns=$mtime;ctime_ns=$ctime;sha256=$sha}}finally{if($null-ne$s){$s.Dispose()}}
}
function Assert-UID0002OZTc3RManifest($Owner,[string]$Label){
  Assert-UID0002OZTc3RKeys $Owner @('attested_at_utc','endpoint','implementation_manifest_sha256','modules','nonce','process','role','source_root') ($Label+'_OWNER');if($Owner['source_root']-isnot[string]-or$Owner['implementation_manifest_sha256']-isnot[string]-or$Owner['modules']-isnot[System.Array]){Throw-UID0002OZTc3R ($Label+'_OWNER_NATIVE')};$root=[IO.Path]::GetFullPath($Owner['source_root']).TrimEnd('\')+'\';$rows=New-Object 'Collections.Generic.List[object]';$ids=New-Object 'Collections.Generic.HashSet[string]' ([StringComparer]::Ordinal)
  foreach($m in $Owner['modules']){if(-not$ids.Add([string]$m['module_id'])){Throw-UID0002OZTc3R ($Label+'_MODULE_ID_DUPLICATE')};$physical=Get-UID0002OZTc3RPhysicalModule $m;if(-not$physical.resolved_path.StartsWith($root,[StringComparison]::OrdinalIgnoreCase)){Throw-UID0002OZTc3R ($Label+'_MODULE_CONTAINMENT')};$rows.Add($physical)}
  $manifest=Get-UID0002OZTc3RCanonicalSha @($rows|Sort-Object sys_modules_name,resolved_path);if($manifest-cne$Owner['implementation_manifest_sha256']){Throw-UID0002OZTc3R ($Label+'_MANIFEST_RECOMPUTE')};[ordered]@{digest=$manifest;rows=@($rows|Sort-Object sys_modules_name,resolved_path)}
}
function Get-UID0002OZTc3RSocketSnapshot { @(Get-NetTCPConnection -State Listen -ErrorAction Stop|ForEach-Object{[ordered]@{host=[string]$_.LocalAddress;port=[int]$_.LocalPort;pid=[int]$_.OwningProcess}}) }
function Assert-UID0002OZTc3RSocket($Sockets,[string]$Host,[int]$Port,[int]$Pid,[string]$Label){$m=@($Sockets|Where-Object{$_['host']-ceq$Host-and[int]$_['port']-eq$Port-and[int]$_['pid']-eq$Pid});if($m.Count-ne1){Throw-UID0002OZTc3R $Label}}
function Assert-UID0002OZTc3RRuntime($A,[string]$ExpectedDatabase,[string]$ExpectedPath,$IdbList,$Sockets,[switch]$RequireOwned){
  Assert-UID0002OZTc3RKeys $A @('errors','inactive_sessions','listener','ok','schema_version','workers') 'TC3R_RUNTIME';if($A['schema_version']-isnot[int]-or$A['schema_version']-ne1-or$A['ok']-isnot[bool]-or-not$A['ok']-or$A['errors']-isnot[System.Array]-or$A['errors'].Count-ne0-or$A['workers']-isnot[System.Array]-or$A['inactive_sessions']-isnot[System.Array]){Throw-UID0002OZTc3R 'TC3R_RUNTIME_STATUS'}
  $listener=$A['listener'];$lm=Assert-UID0002OZTc3RManifest $listener 'TC3R_LISTENER';Assert-UID0002OZTc3RKeys $listener['endpoint'] @('host','port') 'TC3R_LISTENER_ENDPOINT';Assert-UID0002OZTc3RKeys $listener['process'] @('creation_time_100ns','generation','pid') 'TC3R_LISTENER_PROCESS';$lp=$listener['process'];if($listener['role']-cne'supervisor_listener'-or$listener['endpoint']['host']-cne'127.0.0.1'-or-not(Test-UID0002OZTc3RInteger $listener['endpoint']['port'])-or[int]$listener['endpoint']['port']-ne13337-or-not(Test-UID0002OZTc3RInteger $lp['pid'])-or$lp['generation']-cne('pid:{0};created:{1}'-f$lp['pid'],$lp['creation_time_100ns'])){Throw-UID0002OZTc3R 'TC3R_LISTENER_IDENTITY'};Assert-UID0002OZTc3RSocket $Sockets '127.0.0.1' 13337 ([int]$lp['pid']) 'TC3R_LISTENER_SOCKET'
  Assert-UID0002OZTc3RKeys $IdbList @('sessions') 'TC3R_IDB_LIST';if($IdbList['sessions']-isnot[System.Array]){Throw-UID0002OZTc3R 'TC3R_IDB_LIST_NATIVE'};$workers=New-Object 'Collections.Generic.List[object]'
  foreach($route in $A['workers']){Assert-UID0002OZTc3RKeys $route @('attestation','route','supervisor_sessions') 'TC3R_ROUTE';Assert-UID0002OZTc3RKeys $route['route'] @('host','port') 'TC3R_ROUTE_ENDPOINT';if($route['supervisor_sessions']-isnot[System.Array]-or$route['supervisor_sessions'].Count-ne1){Throw-UID0002OZTc3R 'TC3R_SUPERVISOR_CARDINALITY'};$ss=$route['supervisor_sessions'][0];Assert-UID0002OZTc3RKeys $ss @('adopted','canonical_path','owned','redirector_pid','registered_pid','session_id') 'TC3R_SUPERVISOR_SESSION';if($ss['owned']-isnot[bool]-or$ss['adopted']-isnot[bool]-or$ss['owned']-eq$ss['adopted']){Throw-UID0002OZTc3R 'TC3R_WORKER_MODE'}
    $wa=$route['attestation'];Assert-UID0002OZTc3RKeys $wa @('errors','ok','schema_version','sessions','worker') 'TC3R_WORKER_ATTESTATION';if($wa['schema_version']-isnot[int]-or$wa['schema_version']-ne1-or$wa['ok']-isnot[bool]-or-not$wa['ok']-or$wa['errors']-isnot[System.Array]-or$wa['errors'].Count-ne0-or$wa['sessions']-isnot[System.Array]-or$wa['sessions'].Count-ne1){Throw-UID0002OZTc3R 'TC3R_WORKER_STATUS'};$w=$wa['worker'];$wm=Assert-UID0002OZTc3RManifest $w 'TC3R_WORKER';Assert-UID0002OZTc3RKeys $w['endpoint'] @('host','port') 'TC3R_WORKER_ENDPOINT';Assert-UID0002OZTc3RKeys $w['process'] @('creation_time_100ns','generation','parent_pid','pid') 'TC3R_WORKER_PROCESS';$wp=$w['process'];if($route['route']['host']-cne'127.0.0.1'-or$w['endpoint']['host']-cne'127.0.0.1'-or[int]$route['route']['port']-ne[int]$w['endpoint']['port']-or[int]$ss['registered_pid']-ne[int]$wp['pid']-or$wp['generation']-cne('pid:{0};created:{1}'-f$wp['pid'],$wp['creation_time_100ns'])){Throw-UID0002OZTc3R 'TC3R_WORKER_ROUTE_PROCESS'};if($ss['owned']-and[int]$wp['parent_pid']-ne[int]$ss['redirector_pid']){Throw-UID0002OZTc3R 'TC3R_OWNED_PARENT'};if($RequireOwned-and(-not$ss['owned'])){Throw-UID0002OZTc3R 'TC3R_TRANSACTION_ADOPTED'};Assert-UID0002OZTc3RSocket $Sockets '127.0.0.1' ([int]$w['endpoint']['port']) ([int]$wp['pid']) 'TC3R_WORKER_SOCKET'
    $session=$wa['sessions'][0];Assert-UID0002OZTc3RKeys $session @('canonical_path','input_path','session_id') 'TC3R_WORKER_SESSION';foreach($k in @('canonical_path','input_path','session_id')){if($session[$k]-isnot[string]-or[string]::IsNullOrWhiteSpace($session[$k])){Throw-UID0002OZTc3R ('TC3R_WORKER_SESSION_NATIVE:'+ $k)}};if($session['session_id']-cne$ss['session_id']-or-not[string]::Equals([IO.Path]::GetFullPath($session['canonical_path']),[IO.Path]::GetFullPath($ss['canonical_path']),[StringComparison]::OrdinalIgnoreCase)){Throw-UID0002OZTc3R 'TC3R_SESSION_ROUTE_BINDING'}
    $listRows=@($IdbList['sessions']|Where-Object{$_['is_active']-is[bool]-and$_['is_active']-and$_['session_id']-is[string]-and$_['session_id']-ceq$session['session_id']-and$_['canonical_path']-is[string]-and[string]::Equals([IO.Path]::GetFullPath($_['canonical_path']),[IO.Path]::GetFullPath($session['canonical_path']),[StringComparison]::OrdinalIgnoreCase)-and(Test-UID0002OZTc3RInteger $_['pid'])-and[int]$_['pid']-eq[int]$wp['pid']-and(Test-UID0002OZTc3RInteger $_['worker_pid'])-and[int]$_['worker_pid']-eq[int]$wp['pid']});if($listRows.Count-ne1){Throw-UID0002OZTc3R 'TC3R_IDB_LIST_CORRELATION'}
    $workers.Add([ordered]@{session=$session;supervisor=$ss;route=$route['route'];process=$wp;manifest=$wm;nonce=$w['nonce'];time=[datetime]$w['attested_at_utc']})
  }
  $canonical=@($workers|Where-Object{[string]::Equals([IO.Path]::GetFullPath($_.session['canonical_path']),[IO.Path]::GetFullPath($ExpectedPath),[StringComparison]::OrdinalIgnoreCase)});if([string]::IsNullOrEmpty($ExpectedDatabase)){if($canonical.Count-ne0){Throw-UID0002OZTc3R 'TC3R_CLOSED_CANONICAL'}}else{$m=@($canonical|Where-Object{$_.session['session_id']-ceq$ExpectedDatabase});if($canonical.Count-ne1-or$m.Count-ne1){Throw-UID0002OZTc3R 'TC3R_RETURNED_OPEN_AUTHORITY'}}
  [ordered]@{listener=$listener;listener_manifest=$lm;workers=@($workers);nonce=$listener['nonce'];time=[datetime]$listener['attested_at_utc'];sockets=$Sockets}
}
function Get-UID0002OZTc3RWorkerStableKey($W){$rows=ConvertTo-UID0002OZTc3RCanonicalJson $W.manifest.rows;'{0}|{1}|{2}|{3}|{4}|{5}|{6}'-f$W.session['session_id'],[IO.Path]::GetFullPath($W.session['canonical_path']),$W.route['port'],$W.process['pid'],$W.process['generation'],$W.manifest.digest,(Get-UID0002OZTc3RTextSha $rows)}
function Assert-UID0002OZTc3RBoundary($Before,$After,[ValidateSet('NONE','OPEN','RETIRE')][string]$Direction,[string]$RoleKey){if($Before.nonce-ceq$After.nonce-or$After.time-le$Before.time){Throw-UID0002OZTc3R 'TC3R_BOUNDARY_FRESHNESS'};if($Before.listener.process['generation']-cne$After.listener.process['generation']-or$Before.listener_manifest.digest-cne$After.listener_manifest.digest){Throw-UID0002OZTc3R 'TC3R_LISTENER_DRIFT'};$b=@{};$a=@{};foreach($w in $Before.workers){$b[(Get-UID0002OZTc3RWorkerStableKey $w)]=$w};foreach($w in $After.workers){$a[(Get-UID0002OZTc3RWorkerStableKey $w)]=$w};$added=@($a.Keys|Where-Object{-not$b.ContainsKey($_)});$removed=@($b.Keys|Where-Object{-not$a.ContainsKey($_)});if($Direction-ceq'NONE'-and($added.Count-ne0-or$removed.Count-ne0)){Throw-UID0002OZTc3R 'TC3R_ROLE_SET_DRIFT'};if($Direction-ceq'OPEN'-and($added.Count-ne1-or$removed.Count-ne0-or$added[0]-cne$RoleKey)){Throw-UID0002OZTc3R 'TC3R_OPEN_DIRECTION'};if($Direction-ceq'RETIRE'-and($removed.Count-ne1-or$added.Count-ne0-or$removed[0]-cne$RoleKey)){Throw-UID0002OZTc3R 'TC3R_RETIRE_DIRECTION'};foreach($k in @($a.Keys|Where-Object{$b.ContainsKey($_)})){if($a[$k].nonce-ceq$b[$k].nonce-or$a[$k].time-le$b[$k].time){Throw-UID0002OZTc3R 'TC3R_WORKER_FRESHNESS'}};$true}
function New-UID0002OZTc3ROpeningRecord($Journal,[string]$Role,$PreRuntime){$r=[pscustomobject]@{Role=$Role;State='OPENING';PreRuntime=$PreRuntime;Binding=$null;OwnedGeneration=$null;Retired=$false};Write-UID0002OZTc3RJournal $Journal 'ROLE_OPENING' ([ordered]@{role=$Role;pre_runtime_sha=(Get-UID0002OZTc3RCanonicalSha $PreRuntime)});$r}
function Assert-UID0002OZTc3RRetired($Role,$Before,$After,[string[]]$ProtectedGenerations){if($null-eq$Role.OwnedGeneration-or$Role.OwnedGeneration-in$ProtectedGenerations){Throw-UID0002OZTc3R 'TC3R_RETIRE_PROTECTED'};if(@($After.workers|Where-Object{$_.process['generation']-ceq$Role.OwnedGeneration}).Count-ne0){Throw-UID0002OZTc3R 'TC3R_RETIRE_PROCESS_PRESENT'};Assert-UID0002OZTc3RBoundary $Before $After 'RETIRE' (Get-UID0002OZTc3RWorkerStableKey $Role.Binding)|Out-Null;$Role.Retired=$true;$Role.State='RETIRED';$true}
~~~

## Removed Block R021

- SHA256: `529B9BC16F066533F71B724A2FB521EF046A43A9FBE41A82F99BF5BD5C40F1D8`
- Language: `powershell`
- Bytes: `14692`
- First recovered timestamp: `2026-08-07T02:17:31.803Z`
- Session provenance: rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 196166 (2026-08-07T02:17:31.803Z); rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 196167 (2026-08-07T02:17:31.864Z)

~~~powershell
function New-UID0002OZTc3RTargetContract {
  $rm=New-Object 'Collections.Generic.Dictionary[string,object]' ([StringComparer]::Ordinal)
  $rows=@(
    @('RBT12','0x00525ba0','0x00525be0',20,'55 8b ec 83 3d 18 b5 69 00 00 74 32 56 8b 75 08 b8 d3 4d 62 10 8b 0c b5 d0 b5 69 00 0f af 4d 0c f7 e1 c1 ea 06 c1 e2 10 0b d6 81 ca b0 07 00 00 52 ff 35 00 b5 69 00 ff 15 dc d4 60 00 5e 5d c3','525ba0 55 push ebp;525ba1 8b ec mov ebp,esp;525ba3 83 3d 18 b5 69 00 00 cmp dword ptr [0x69b518],0;525baa 74 32 je 0x525bde;525bac 56 push esi;525bad 8b 75 08 mov esi,[ebp+8];525bb0 b8 d3 4d 62 10 mov eax,0x10624dd3;525bb5 8b 0c b5 d0 b5 69 00 mov ecx,[esi*4+0x69b5d0];525bbc 0f af 4d 0c imul ecx,[ebp+0xc];525bc0 f7 e1 mul ecx;525bc2 c1 ea 06 shr edx,6;525bc5 c1 e2 10 shl edx,0x10;525bc8 0b d6 or edx,esi;525bca 81 ca b0 07 00 00 or edx,0x7b0;525bd0 52 push edx;525bd1 ff 35 00 b5 69 00 push dword ptr [0x69b500];525bd7 ff 15 dc d4 60 00 call dword ptr [0x60d4dc];525bdd 5e pop esi;525bde 5d pop ebp;525bdf c3 ret','RBT13','525be0 55 push ebp','A0 4F 12 00',''),
    @('RBT14','0x00525f40','0x00525f57',7,'68 08 fb 61 00 6a 00 6a 00 6a 00 ff 15 3c be 69 00 a3 20 b8 69 00 c3','525f40 68 08 fb 61 00 push 0x61fb08;525f45 6a 00 push 0;525f47 6a 00 push 0;525f49 6a 00 push 0;525f4b ff 15 3c be 69 00 call dword ptr [0x69be3c];525f51 a3 20 b8 69 00 mov [0x69b820],eax;525f56 c3 ret','RBT15','525f57 cc int3','40 53 12 00',''),
    @('RBT16','0x00525f60','0x00525f95',14,'68 00 00 03 00 6a 00 68 e0 5b 52 00 6a 01 68 04 b5 69 00 68 00 b5 69 00 ff 15 e8 d4 60 00 85 c0 74 03 33 c0 c3 c7 05 1c b5 69 00 01 00 00 00 b8 01 00 00 00 c3','525f60 68 00 00 03 00 push 0x30000;525f65 6a 00 push 0;525f67 68 e0 5b 52 00 push 0x525be0;525f6c 6a 01 push 1;525f6e 68 04 b5 69 00 push 0x69b504;525f73 68 00 b5 69 00 push 0x69b500;525f78 ff 15 e8 d4 60 00 call dword ptr [0x60d4e8];525f7e 85 c0 test eax,eax;525f80 74 03 je 0x525f85;525f82 33 c0 xor eax,eax;525f84 c3 ret;525f85 c7 05 1c b5 69 00 01 00 00 00 mov dword ptr [0x69b51c],1;525f8f b8 01 00 00 00 mov eax,1;525f94 c3 ret','RBT17','525f95 cc int3','60 53 12 00',''),
    @('RBT18','0x00525fa0','0x00525fe2',15,'83 3d 00 b5 69 00 00 74 0d 68 00 00 01 00 e8 ad 04 00 00 83 c4 04 e8 55 fb ff ff a1 00 b5 69 00 85 c0 74 11 50 ff 15 04 d5 60 00 c7 05 00 b5 69 00 00 00 00 00 ff 35 20 b8 69 00 ff 15 10 d1 60 00 c3','525fa0 83 3d 00 b5 69 00 00 cmp dword ptr [0x69b500],0;525fa7 74 0d je 0x525fb6;525fa9 68 00 00 01 00 push 0x10000;525fae e8 ad 04 00 00 call 0x526460;525fb3 83 c4 04 add esp,4;525fb6 e8 55 fb ff ff call 0x525b10;525fbb a1 00 b5 69 00 mov eax,[0x69b500];525fc0 85 c0 test eax,eax;525fc2 74 11 je 0x525fd5;525fc4 50 push eax;525fc5 ff 15 04 d5 60 00 call dword ptr [0x60d504];525fcb c7 05 00 b5 69 00 00 00 00 00 mov dword ptr [0x69b500],0;525fd5 ff 35 20 b8 69 00 push dword ptr [0x69b820];525fdb ff 15 10 d1 60 00 call dword ptr [0x60d110];525fe1 c3 ret','RBT19','525fe2 cc int3','A0 53 12 00',''),
    @('RBT20','0x00526060','0x0052607c',9,'83 79 04 00 74 15 a1 24 b5 69 00 3d 84 03 00 00 77 09 83 c0 64 50 e8 75 ff ff ff c3','526060 83 79 04 00 cmp dword ptr [ecx+4],0;526064 74 15 je 0x52607b;526066 a1 24 b5 69 00 mov eax,[0x69b524];52606b 3d 84 03 00 00 cmp eax,0x384;526070 77 09 ja 0x52607b;526072 83 c0 64 add eax,0x64;526075 50 push eax;526076 e8 75 ff ff ff call 0x525ff0;52607b c3 ret','RBT21','52607c cc int3','60 54 12 00','0x00526076->0x00525ff0'),
    @('RBT22','0x00526080','0x0052609a',9,'83 79 04 00 74 13 a1 24 b5 69 00 83 f8 64 72 09 83 c0 9c 50 e8 57 ff ff ff c3','526080 83 79 04 00 cmp dword ptr [ecx+4],0;526084 74 13 je 0x526099;526086 a1 24 b5 69 00 mov eax,[0x69b524];52608b 83 f8 64 cmp eax,0x64;52608e 72 09 jb 0x526099;526090 83 c0 9c add eax,-0x64;526093 50 push eax;526094 e8 57 ff ff ff call 0x525ff0;526099 c3 ret','RBT23','52609a cc int3','80 54 12 00','0x00526094->0x00525ff0'))
  foreach($r in $rows){$rm.Add($r[0],[ordered]@{id=$r[0];start=$r[1];end=$r[2];count=[int]$r[3];bytes=$r[4];instructions=$r[5];successor_id=$r[6];successor=$r[7];raw_pattern=$r[8];local_call=$r[9]})}
  $functions=[ordered]@{
    '0x00595760'=[ordered]@{pre='sub_595760';post='TextFilter_Constructor';type='TextFilter *__thiscall TextFilter_Constructor(TextFilter *this)';bounds='0x00595760-0x00595795'};
    '0x005957a0'=[ordered]@{pre='sub_5957A0';post='TextFilter_Destructor';type='void __thiscall TextFilter_Destructor(TextFilter *this)';bounds='0x005957a0-0x005957b1'};
    '0x005957c0'=[ordered]@{pre='sub_5957C0';post='SanitizeWideTextForChat';type='void __stdcall SanitizeWideTextForChat(wchar_t *text, unsigned int textLength)';bounds='0x005957c0-0x005958ca';frame_rows=18;xrefs=14;callees=0;ret='retn 8';local='ch:wchar_t'};
    '0x005958d0'=[ordered]@{pre='sub_5958D0';post='TextFilter_ScalarDeletingDestructor';type='_DWORD *__thiscall(_DWORD *Block, char)';bounds='0x005958d0-0x005958fe';ret='retn 4';arg='flags:byte';comment='Block'};
    '0x00525b10'=[ordered]@{post='sub_525B10';type='HGLOBAL()';bounds='0x00525b10-0x00525b98';xrefs='0x00525ef1,0x00525fb6,0x00526519,0x005265c8'};
    '0x00525dc0'=[ordered]@{post='sub_525DC0';type='int __thiscall(int this)';bounds='0x00525dc0-0x00525ea6';xrefs='0x004646c0';frame='var_10, var_C, var_4, saved, return, arg_4'};
    '0x00525eb0'=[ordered]@{post='sub_525EB0';type='void __thiscall(_DWORD *this)';bounds='0x00525eb0-0x00525f3d';xrefs='';frame='var_C, saved, return, arg_4'};
    '0x00525ff0'=[ordered]@{post='sub_525FF0';type='void __stdcall(int)';bounds='0x00525ff0-0x0052605a';xrefs='0x00526076,0x00526094,0x005262b9,0x0052630c,0x00526328';ret='retn 4'}}
  [ordered]@{rm6=[Collections.ObjectModel.ReadOnlyDictionary[string,object]]::new($rm);functions=$functions;type_pre=[ordered]@{exists=$false;total=0;data=@();next_offset=$null};type_post=[ordered]@{ordinal=980;name='TextFilter';size=[uint64]18446744073709551615;kind='other';declaration='TextFilter';member_count=0;members=@();members_truncated=$false;related_count=0;related_types=@();related_truncated=$false;next_offset=$null;total=1};vtable_bytes='18 15 65 00 d0 58 59 00 b4 15 65 00';global_bytes='00 00 00 00';patterns=@('A0 5B 52 00','A0 5B 12 00','A0 4F 12 00','40 5F 52 00','40 5F 12 00','40 53 12 00','60 5F 52 00','60 5F 12 00','60 53 12 00','A0 5F 52 00','A0 5F 12 00','A0 53 12 00','60 60 52 00','60 60 12 00','60 54 12 00','80 60 52 00','80 60 12 00','80 54 12 00')}
}
function Assert-UID0002OZTc3RExact($Actual,$Expected,[string]$Label){if((ConvertTo-UID0002OZTc3RCanonicalJson $Actual)-cne(ConvertTo-UID0002OZTc3RCanonicalJson $Expected)){Throw-UID0002OZTc3R $Label};$true}
function Assert-UID0002OZTc3RDisasm($Structured,$Contract){Assert-UID0002OZTc3RKeys $Structured @('addr','asm','cursor','instruction_count','total_instructions') ('TC3R_'+$Contract.id);if($Structured['instruction_count']-isnot[int]-or$Structured['instruction_count']-ne$Contract.count-or$Structured['addr']-isnot[string]-or-not[string]::Equals($Structured['addr'],$Contract.start,[StringComparison]::OrdinalIgnoreCase)){Throw-UID0002OZTc3R ('TC3R_RM6_HEADER:'+ $Contract.id)};Assert-UID0002OZTc3RKeys $Structured['asm'] @('lines') ('TC3R_RM6_ASM:'+ $Contract.id);$lines=$Structured['asm']['lines'];if($lines-isnot[System.Array]-or$lines.Count-ne$Contract.count){Throw-UID0002OZTc3R ('TC3R_RM6_COUNT:'+ $Contract.id)};$actual=($lines|ForEach-Object{Assert-UID0002OZTc3RKeys $_ @('addr','bytes','instruction') ('TC3R_RM6_ROW:'+ $Contract.id);([string]$_['addr']).TrimStart('0','x')+' '+([string]$_['bytes']).ToLowerInvariant()+' '+[string]$_['instruction']})-join';';if($actual-cne$Contract.instructions){Throw-UID0002OZTc3R ('TC3R_RM6_INSTRUCTIONS:'+ $Contract.id)};$bytes=($lines|ForEach-Object{([string]$_['bytes']).ToLowerInvariant()})-join' ';if($bytes-cne$Contract.bytes){Throw-UID0002OZTc3R ('TC3R_RM6_BYTES:'+ $Contract.id)};$true}
function Assert-UID0002OZTc3RRbtBundle($Bundle,[ValidateSet('PRE','POST')][string]$State){
  if($Bundle-isnot[Collections.IDictionary]-or$Bundle.Count-ne23){Throw-UID0002OZTc3R 'TC3R_RBT_COUNT'};$expectedIds=1..23|ForEach-Object{'RBT{0:d2}'-f$_};if((@($Bundle.Keys|Sort-Object)-join',')-cne(@($expectedIds|Sort-Object)-join',')){Throw-UID0002OZTc3R 'TC3R_RBT_IDS'};$c=New-UID0002OZTc3RTargetContract
  $t=$Bundle['RBT01'];Assert-UID0002OZTc3RKeys $t @('data','next_offset','total') 'TC3R_RBT01';if($null-ne$t['next_offset']-or$t['data']-isnot[System.Array]-or[int]$t['total']-ne$t['data'].Count){Throw-UID0002OZTc3R 'TC3R_RBT01_PAGINATION'};if($State-ceq'PRE'){Assert-UID0002OZTc3RExact $t $c.type_pre 'TC3R_TYPE_PRE'}else{if($t['data'].Count-ne1){Throw-UID0002OZTc3R 'TC3R_TYPE_POST_COUNT'};$projection=[ordered]@{};foreach($k in @('ordinal','name','size','kind','declaration','member_count','members','members_truncated','related_count','related_types','related_truncated')){$projection[$k]=$t['data'][0][$k]};$projection.next_offset=$t['next_offset'];$projection.total=$t['total'];Assert-UID0002OZTc3RExact $projection $c.type_post 'TC3R_TYPE_POST'}
  $lookup=$Bundle['RBT03']['data'];if($lookup-isnot[System.Array]-or$lookup.Count-lt$c.functions.Count){Throw-UID0002OZTc3R 'TC3R_LOOKUP_COUNT'};foreach($addr in $c.functions.Keys){$f=@($lookup|Where-Object{$_['addr']-is[string]-and[string]::Equals($_['addr'],$addr,[StringComparison]::OrdinalIgnoreCase)});if($f.Count-ne1){Throw-UID0002OZTc3R ('TC3R_LOOKUP_ADDR:'+ $addr)};$x=$c.functions[$addr];if($f[0]['name']-isnot[string]-or($f[0]['name']-cne$(if($State-ceq'PRE' -and (Get-UID0002OZTc3RKey $x 'pre')){$x.pre}else{$x.post}))){Throw-UID0002OZTc3R ('TC3R_LOOKUP_NAME:'+ $addr)};if((Get-UID0002OZTc3RKey $x 'type')-and$f[0]['type']-cne$x.type){Throw-UID0002OZTc3R ('TC3R_LOOKUP_TYPE:'+ $addr)}}
  $find=$Bundle['RBT11'];Assert-UID0002OZTc3RKeys $find @('data','next_offset','total') 'TC3R_RBT11';if($find['data']-isnot[System.Array]-or$find['data'].Count-ne0-or$null-ne$find['next_offset']-or$find['total']-isnot[int]-or$find['total']-ne0){Throw-UID0002OZTc3R 'TC3R_FIND_BYTES_NOT_ZERO'};if((@($find['patterns'])-join',')-cne($c.patterns-join',')){Throw-UID0002OZTc3R 'TC3R_FIND_BYTES_PATTERNS'}
  foreach($id in $c.rm6.Keys){Assert-UID0002OZTc3RDisasm $Bundle[$id] $c.rm6[$id]|Out-Null;$successor=$Bundle[$c.rm6[$id].successor_id];if($successor['instruction_count']-ne1-or$successor['asm']['lines'].Count-ne1){Throw-UID0002OZTc3R ('TC3R_RM6_SUCCESSOR_COUNT:'+ $id)};$srow=$successor['asm']['lines'][0];$s=([string]$srow['addr']).TrimStart('0','x')+' '+([string]$srow['bytes']).ToLowerInvariant()+' '+[string]$srow['instruction'];if($s-cne$c.rm6[$id].successor){Throw-UID0002OZTc3R ('TC3R_RM6_SUCCESSOR:'+ $id)}}
  $bytes=$Bundle['RBT08']['data'];$vt=@($bytes|Where-Object{$_['addr']-ceq'0x0062e184'});$gp=@($bytes|Where-Object{$_['addr']-ceq'0x0067adc8'});if($vt.Count-ne1-or$vt[0]['bytes']-cne$c.vtable_bytes-or$gp.Count-ne1-or$gp[0]['bytes']-cne$c.global_bytes){Throw-UID0002OZTc3R 'TC3R_PROTECTED_BYTES'}
  foreach($id in @('RBT04','RBT05','RBT06','RBT07','RBT08','RBT09','RBT10')){if($Bundle[$id]['data']-isnot[System.Array]){Throw-UID0002OZTc3R ('TC3R_RBT_DATA:'+ $id)}};if(@($Bundle['RBT09']['data']|Where-Object{$_['more']-isnot[bool]-or$_['more']}).Count-ne0-or@($Bundle['RBT10']['data']|Where-Object{$_['more']-isnot[bool]-or$_['more']}).Count-ne0){Throw-UID0002OZTc3R 'TC3R_XREF_CALLEE_TRUNCATION'}
  $sanX=@($Bundle['RBT09']['data']|Where-Object{$_['addr']-ceq'0x005957c0'});$globalX=@($Bundle['RBT09']['data']|Where-Object{$_['addr']-ceq'0x0067adc8'});$sanC=@($Bundle['RBT10']['data']|Where-Object{$_['addr']-ceq'0x005957c0'});if($sanX.Count-ne1-or[int]$sanX[0]['xref_count']-ne14-or$globalX.Count-ne1-or[int]$globalX[0]['xref_count']-ne19-or$sanC.Count-ne1-or[int]$sanC[0]['callee_count']-ne0){Throw-UID0002OZTc3R 'TC3R_XREF_CALLEE_EXACT'}
  $rmCount=($c.rm6.Values|Measure-Object count -Sum).Sum;if($rmCount-ne74-or(($c.rm6.Values|ForEach-Object{($_.bytes-split' ').Count}|Measure-Object -Sum).Sum)-ne260){Throw-UID0002OZTc3R 'TC3R_RM6_TOTAL'};$true
}
function New-UID0002OZTc3RMutationPlan {
  $old='HISTORICAL_PRESTATE';$post='ACCEPTED_POSTSTATE';@(
    @('I001','declare_type','struct TextFilter;',$old,$post),@('I002D','rename','dry-run TextFilter_Constructor',$old,$old),@('I002N','rename','TextFilter_Constructor',$old,$post),@('I002T','set_type','TextFilter *__thiscall TextFilter_Constructor(TextFilter *this)',$old,$post),@('I002C','set_repeatable_comments','constructor comment',$old,$post),
    @('I003D','rename','dry-run TextFilter_Destructor',$old,$old),@('I003N','rename','TextFilter_Destructor',$old,$post),@('I003T','set_type','void __thiscall TextFilter_Destructor(TextFilter *this)',$old,$post),@('I003C','set_repeatable_comments','destructor comment',$old,$post),
    @('I004D','rename','dry-run SanitizeWideTextForChat',$old,$old),@('I004N','rename','SanitizeWideTextForChat',$old,$post),@('I004T','set_type','void __stdcall SanitizeWideTextForChat(wchar_t *text, unsigned int textLength)',$old,$post),@('I004LD','rename','dry-run v3->ch',$old,$old),@('I004LN','rename','v3->ch:wchar_t',$old,$post),@('I004C','set_repeatable_comments','sanitizer comment',$old,$post),
    @('I005D','rename','dry-run TextFilter_ScalarDeletingDestructor',$old,$old),@('I005N','rename','TextFilter_ScalarDeletingDestructor',$old,$post),@('I005C','set_repeatable_comments','scalar deleting destructor comment',$old,$post),
    @('I006D','rename','dry-run unk_67ADC8->g_pTextFilter',$old,$old),@('I006N','rename','unk_67ADC8->g_pTextFilter',$old,$post),@('I006C','set_address_repeatable_comments','singleton storage comment',$old,$post),
    @('I007','set_address_repeatable_comments','0x0062e184 COL comment',$old,$post),@('I008','set_address_repeatable_comments','0x0062e188 vtable comment',$old,$post),@('I009','set_address_repeatable_comments','0x00651518 COL comment',$old,$post),@('I010','set_address_repeatable_comments','0x004f615f construction comment',$old,$post),@('I011','set_address_repeatable_comments','0x004f667d shutdown comment',$old,$post))|ForEach-Object{[ordered]@{id=$_[0];tool=$_[1];request=$_[2];old=$_[3];new=$_[4]}}
}
function Assert-UID0002OZTc3RMutationResult($Spec,$Structured){Assert-UID0002OZTc3RKeys $Structured @('results') ('TC3R_MUTATION_'+$Spec.id);if($Structured['results']-isnot[System.Array]-or$Structured['results'].Count-ne1){Throw-UID0002OZTc3R ('TC3R_MUTATION_COUNT:'+ $Spec.id)};$r=$Structured['results'][0];Assert-UID0002OZTc3RKeys $r @('action','current','error','new','ok','old') ('TC3R_MUTATION_ROW:'+ $Spec.id);if($r['ok']-isnot[bool]-or-not$r['ok']-or$null-ne$r['error']-or$r['action']-cne$Spec.request-or$r['old']-cne$Spec.old-or$r['new']-cne$Spec.new-or$r['current']-cne$Spec.new){Throw-UID0002OZTc3R ('TC3R_MUTATION_SEMANTICS:'+ $Spec.id)};$true}
~~~

## Removed Block R022

- SHA256: `0C3604E8BC5603725FCB784A8B3F4DB97F64BA8733F3FE2D7EE74D6AFBD36E3A`
- Language: `powershell`
- Bytes: `11212`
- First recovered timestamp: `2026-08-07T02:19:51.401Z`
- Session provenance: rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 196173 (2026-08-07T02:19:51.401Z); rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 196174 (2026-08-07T02:19:51.464Z)

~~~powershell
if (-not ('UID0002OZTc3RSetTime' -as [type])) {
Add-Type -TypeDefinition @'
using System;
using System.Runtime.InteropServices;
using Microsoft.Win32.SafeHandles;
public static class UID0002OZTc3RSetTime {
 [StructLayout(LayoutKind.Sequential)] public struct FILETIME { public uint Low; public uint High; }
 [DllImport("kernel32.dll",SetLastError=true)] static extern bool SetFileTime(SafeFileHandle h,IntPtr c,IntPtr a,ref FILETIME w);
 public static void WriteTicks(SafeFileHandle h,long ticks){FILETIME f=new FILETIME();ulong u=unchecked((ulong)ticks);f.Low=(uint)u;f.High=(uint)(u>>32);if(!SetFileTime(h,IntPtr.Zero,IntPtr.Zero,ref f))throw new System.ComponentModel.Win32Exception(Marshal.GetLastWin32Error());}
}
'@
}
function New-UID0002OZTc3REffects {[ordered]@{transport=0;mutation=0;save=0;stop=0;truncate=0;write=0;restore=0;verifier=0;cleanup=0}}
function Copy-UID0002OZTc3REffects($Effects){[ordered]@{transport=$Effects.transport;mutation=$Effects.mutation;save=$Effects.save;stop=$Effects.stop;truncate=$Effects.truncate;write=$Effects.write;restore=$Effects.restore;verifier=$Effects.verifier;cleanup=$Effects.cleanup}}
function New-UID0002OZTc3RChannel {[pscustomobject]@{Endpoint='http://127.0.0.1:13337/mcp';Session=$null;Initialized=$false;Closed=$false}}
function Get-UID0002OZTc3RWireJson([string]$Content){if($Content.TrimStart().StartsWith('{')){return$Content};$data=@($Content-split"`n"|Where-Object{$_-match'^data:\s*'}|ForEach-Object{$_-replace'^data:\s*',''});if($data.Count-ne1){Throw-UID0002OZTc3R 'TC3R_SSE_CARDINALITY'};$data[0]}
function Invoke-UID0002OZTc3RWire($Channel,[string]$Body,[bool]$Notification,$Effects){if($Channel.Closed){Throw-UID0002OZTc3R 'TC3R_CHANNEL_CLOSED'};$Effects.transport=[int]$Effects.transport+1;$headers=@{Accept='application/json, text/event-stream'};if($null-ne$Channel.Session){$headers['Mcp-Session-Id']=$Channel.Session};$r=Invoke-WebRequest -UseBasicParsing -Uri $Channel.Endpoint -Method Post -ContentType 'application/json' -Headers $headers -Body ([Text.Encoding]::UTF8.GetBytes($Body));if($null-eq$Channel.Session-and$r.Headers['Mcp-Session-Id']){$Channel.Session=[string]$r.Headers['Mcp-Session-Id']};if($Notification){return$null};Get-UID0002OZTc3RWireJson ([string]$r.Content)}
function Initialize-UID0002OZTc3RBootstrap($Channel,$Effects){$id='uid0002oz:bootstrap:0001';$body=ConvertTo-UID0002OZTc3RCanonicalJson ([ordered]@{jsonrpc='2.0';id=$id;method='initialize';params=[ordered]@{protocolVersion='2025-06-18';capabilities=[ordered]@{};clientInfo=[ordered]@{name='UID0002OZ-TC3R';version='1'}}});$raw=Invoke-UID0002OZTc3RWire $Channel $body $false $Effects;$e=ConvertFrom-UID0002OZTc3RJson $raw;Assert-UID0002OZTc3RKeys $e @('id','jsonrpc','result') 'TC3R_INITIALIZE';if($e['id']-cne$id-or$e['jsonrpc']-cne'2.0'-or[string]::IsNullOrWhiteSpace($Channel.Session)){Throw-UID0002OZTc3R 'TC3R_INITIALIZE_CORRELATION'};$notification=ConvertTo-UID0002OZTc3RCanonicalJson ([ordered]@{jsonrpc='2.0';method='notifications/initialized';params=[ordered]@{}});$null=Invoke-UID0002OZTc3RWire $Channel $notification $true $Effects;$Channel.Initialized=$true;$toolsId='uid0002oz:bootstrap:0002';$toolsBody=ConvertTo-UID0002OZTc3RCanonicalJson ([ordered]@{jsonrpc='2.0';id=$toolsId;method='tools/list';params=[ordered]@{}});$toolsRaw=Invoke-UID0002OZTc3RWire $Channel $toolsBody $false $Effects;$tools=ConvertFrom-UID0002OZTc3RJson $toolsRaw;if($tools['id']-cne$toolsId){Throw-UID0002OZTc3R 'TC3R_TOOLS_BOOTSTRAP_ID'};$toolsRaw}
function Invoke-UID0002OZTc3RCall($Journal,$Channel,[string]$Tool,$Arguments,[string]$Role,$Effects,[switch]$Save){if(-not$Channel.Initialized){Throw-UID0002OZTc3R 'TC3R_CHANNEL_NOT_INITIALIZED'};$request=Reserve-UID0002OZTc3RRequest $Journal $Tool $Arguments $Role;$body=ConvertTo-UID0002OZTc3RCanonicalJson ([ordered]@{jsonrpc='2.0';id=$request.Id;method='tools/call';params=[ordered]@{name=$Tool;arguments=$Arguments}});if($Save){Set-UID0002OZTc3RSaveLatch $Journal $request;$Effects.save=[int]$Effects.save+1};Mark-UID0002OZTc3RDispatched $Journal $request;try{$raw=Invoke-UID0002OZTc3RWire $Channel $body $false $Effects;$e=Complete-UID0002OZTc3RResponse $Journal $request $raw -Save:$Save;if($Save){$sc=$e['result']['structuredContent'];$class=if($e['result']['isError']-is[bool]-and-not$e['result']['isError']-and$sc['ok']-is[bool]-and$sc['ok']){'EXPLICIT_SUCCESS'}elseif($e['result']['isError']-is[bool]-and$e['result']['isError']){'EXPLICIT_FAILURE'}else{'INDETERMINATE'};Set-UID0002OZTc3RSaveClassification $Journal $request $class};[pscustomobject]@{Envelope=$e;Request=$request}}catch{if($Save-and$Journal.SaveClass-ceq'ISSUED'){Set-UID0002OZTc3RSaveClassification $Journal $request 'INDETERMINATE'};throw}}
function Get-UID0002OZTc3RStructured($Call,[string]$Tool){$e=$Call.Envelope;Assert-UID0002OZTc3RKeys $e['result'] @('content','isError','structuredContent') ('TC3R_'+$Tool+'_WRAPPER');if($e['result']['content']-isnot[System.Array]-or$e['result']['isError']-isnot[bool]-or$e['result']['isError']-or$e['result']['structuredContent']-isnot[Collections.IDictionary]){Throw-UID0002OZTc3R ('TC3R_'+$Tool+'_WRAPPER_NATIVE')};$e['result']['structuredContent']}
function Resolve-UID0002OZTc3RDiskIdentity($Candidate,$P0,$Receipt){
  if(Test-UID0002OZTc3RFullTuple $Candidate $P0){return 'EXACT_P0'}
  $required=@('attempt','save_request','journal_chain','catalog_sha','raw_response_sha','save_class','retirement_sha','runtime_sha','er00_sha','sole_writer','candidate')
  if($Receipt-is[Collections.IDictionary]-and(@($required|Where-Object{-not(Get-UID0002OZTc3RKey $Receipt $_)}).Count-eq0)-and$Receipt['attempt']-ceq'UID0002OZ-TC3R'-and$Receipt['save_request']-is[string]-and$Receipt['journal_chain']-match'^[0-9A-F]{64}$'-and$Receipt['catalog_sha']-match'^[0-9A-F]{64}$'-and$Receipt['raw_response_sha']-match'^[0-9A-F]{64}$'-and$Receipt['save_class']-in@('EXPLICIT_SUCCESS','INDETERMINATE')-and$Receipt['retirement_sha']-match'^[0-9A-F]{64}$'-and$Receipt['runtime_sha']-match'^[0-9A-F]{64}$'-and$Receipt['er00_sha']-match'^[0-9A-F]{64}$'-and$Receipt['sole_writer']-is[bool]-and$Receipt['sole_writer']-and(Test-UID0002OZTc3RFullTuple $Candidate $Receipt['candidate'])){return 'ATTEMPT_S1'}
  return 'THIRD_IDENTITY'
}
function New-UID0002OZTc3RB0($Journal,$P0,$Effects){$canonical=$Journal.CanonicalPath;$backup=$canonical+'.bak-UID0002OZ-TC3R-'+[datetime]::UtcNow.ToString('yyyyMMddHHmmssfffffff');$src=$null;$dst=$null;try{$src=[IO.File]::Open($canonical,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);$heldP0=Get-UID0002OZTc3RHeldTuple $src;if(-not(Test-UID0002OZTc3RFullTuple $heldP0 $P0)){Throw-UID0002OZTc3R 'TC3R_B0_SOURCE_P0'};$dst=[IO.File]::Open($backup,[IO.FileMode]::CreateNew,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None);$buffer=New-Object byte[] 1048576;$copied=[int64]0;while(($n=$src.Read($buffer,0,$buffer.Length))-gt0){$dst.Write($buffer,0,$n);$copied+=[int64]$n;$Effects.write=[int]$Effects.write+1};if($src.Read($buffer,0,1)-ne0-or$copied-ne$P0.length-or$dst.Length-ne$P0.length){Throw-UID0002OZTc3R 'TC3R_B0_COPY'};$dst.Flush($true);[UID0002OZTc3RSetTime]::WriteTicks($dst.SafeFileHandle,[int64]$P0.ticks);$held=Get-UID0002OZTc3RHeldTuple $dst;if($held.length-ne$P0.length-or$held.sha256-cne$P0.sha256-or$held.ticks-ne$P0.ticks-or$held.file_id-ceq$P0.file_id){Throw-UID0002OZTc3R 'TC3R_B0_HELD'}}finally{if($null-ne$dst){$dst.Dispose()};if($null-ne$src){$src.Dispose()}};$closed=Get-UID0002OZTc3RClosedTuple $backup;if(-not(Test-UID0002OZTc3RFullTuple $held $closed)){Throw-UID0002OZTc3R 'TC3R_B0_REOPEN'};Write-UID0002OZTc3RJournal $Journal 'B0_COMMITTED' ([ordered]@{tuple=$closed;source_content_sha=$P0.sha256});$closed}
function New-UID0002OZTc3RRestoreAuthority($Journal,$P0,$B0,$S1,$ClassifierReceipt,$RetirementReceipt,$RuntimeReceipt,$VerifierReceipt){$key=New-Object byte[] 32;[Security.Cryptography.RandomNumberGenerator]::Create().GetBytes($key);$payload=[ordered]@{journal_path=$Journal.Path;journal_chain=$Journal.Chain;classifier=$ClassifierReceipt;p0=$P0;b0=$B0;s1=$S1;retirement=$RetirementReceipt;runtime=$RuntimeReceipt;verifier=$VerifierReceipt};$text=ConvertTo-UID0002OZTc3RCanonicalJson $payload;$h=New-Object Security.Cryptography.HMACSHA256 (,$key);try{$mac=([BitConverter]::ToString($h.ComputeHash([Text.Encoding]::UTF8.GetBytes($text)))).Replace('-','')}finally{$h.Dispose()};[pscustomobject]@{Key=$key;Payload=$payload;Mac=$mac;Consumed=$false}}
function Use-UID0002OZTc3RRestore($Journal,$Authority,$CurrentB0,$CurrentS1,$Effects){if($Authority.Consumed-or$Journal.RestoreConsumed){Throw-UID0002OZTc3R 'TC3R_RESTORE_PERMIT_CONSUMED'};$text=ConvertTo-UID0002OZTc3RCanonicalJson $Authority.Payload;$h=New-Object Security.Cryptography.HMACSHA256 (,$Authority.Key);try{$mac=([BitConverter]::ToString($h.ComputeHash([Text.Encoding]::UTF8.GetBytes($text)))).Replace('-','')}finally{$h.Dispose()};if($mac-cne$Authority.Mac-or-not(Test-UID0002OZTc3RFullTuple $CurrentB0 $Authority.Payload.b0)-or-not(Test-UID0002OZTc3RFullTuple $CurrentS1 $Authority.Payload.s1)){Throw-UID0002OZTc3R 'TC3R_RESTORE_PERMIT_FORGED'};$Authority.Consumed=$true;$Journal.RestoreConsumed=$true;Write-UID0002OZTc3RJournal $Journal 'RESTORE_PERMIT_CONSUMED' ([ordered]@{permit_sha=(Get-UID0002OZTc3RTextSha $Authority.Mac);before_truncate=$true})
  $src=$null;$dst=$null;try{$src=[IO.File]::Open($CurrentB0.path,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);$b0Held=Get-UID0002OZTc3RHeldTuple $src;if(-not(Test-UID0002OZTc3RFullTuple $b0Held $CurrentB0)){Throw-UID0002OZTc3R 'TC3R_RESTORE_B0_DRIFT'};$dst=[IO.File]::Open($Journal.CanonicalPath,[IO.FileMode]::Open,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None);$s1Held=Get-UID0002OZTc3RHeldTuple $dst;if(-not(Test-UID0002OZTc3RFullTuple $s1Held $CurrentS1)-or($b0Held.volume-eq$s1Held.volume-and$b0Held.file_id-ceq$s1Held.file_id)){Throw-UID0002OZTc3R 'TC3R_RESTORE_S1_DRIFT'};$dst.SetLength(0);$Effects.truncate=[int]$Effects.truncate+1;$buffer=New-Object byte[] 1048576;$copied=[int64]0;while(($n=$src.Read($buffer,0,$buffer.Length))-gt0){$dst.Write($buffer,0,$n);$copied+=[int64]$n;$Effects.write=[int]$Effects.write+1};if($src.Read($buffer,0,1)-ne0-or$copied-ne$Authority.Payload.p0.length-or$dst.Length-ne$Authority.Payload.p0.length){Throw-UID0002OZTc3R 'TC3R_RESTORE_COPY'};$dst.Flush($true);[UID0002OZTc3RSetTime]::WriteTicks($dst.SafeFileHandle,[int64]$Authority.Payload.p0.ticks);$held=Get-UID0002OZTc3RHeldTuple $dst;if($held.length-ne$Authority.Payload.p0.length-or$held.sha256-cne$Authority.Payload.p0.sha256-or$held.ticks-ne$Authority.Payload.p0.ticks-or$held.file_id-cne$CurrentS1.file_id){Throw-UID0002OZTc3R 'TC3R_RESTORE_HELD'};$Effects.restore=[int]$Effects.restore+1}finally{if($null-ne$dst){$dst.Dispose()};if($null-ne$src){$src.Dispose()}};$closed=Get-UID0002OZTc3RClosedTuple $Journal.CanonicalPath;if(-not(Test-UID0002OZTc3RFullTuple $held $closed)){Throw-UID0002OZTc3R 'TC3R_RESTORE_REOPEN'};Write-UID0002OZTc3RJournal $Journal 'RESTORE_COMPLETE' ([ordered]@{held=$held;closed=$closed});$closed}
function Assert-UID0002OZTc3RFinalTuple($Tuple,$Expected,[string]$Label){if(-not(Test-UID0002OZTc3RFullTuple $Tuple $Expected)){Throw-UID0002OZTc3R $Label};$true}
~~~

## Removed Block R023

- SHA256: `87A04F6679C0AE6BFB102F492CA00AF83EDD1EB24409830CFF482123FC52BC0C`
- Language: `powershell`
- Bytes: `16421`
- First recovered timestamp: `2026-08-07T02:22:45.277Z`
- Session provenance: rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 196187 (2026-08-07T02:22:45.277Z); rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 196188 (2026-08-07T02:22:45.334Z)

~~~powershell
function Get-UID0002OZTc3RRbtPlan([string]$Database){
  $c=New-UID0002OZTc3RTargetContract;$plan=New-Object 'Collections.Generic.List[object]'
  $plan.Add([ordered]@{id='RBT01';tool='type_query';args=[ordered]@{queries=[ordered]@{filter='/^TextFilter$/';kind='any';offset=0;count=16;sort_by='name';descending=$false;include_decl=$true;include_members=$true;max_members=16;include_relationships=$true};database=$Database}})
  $plan.Add([ordered]@{id='RBT02';tool='type_inspect';args=[ordered]@{queries=[ordered]@{name='TextFilter';include_members=$true;max_members=16};database=$Database}})
  $plan.Add([ordered]@{id='RBT03';tool='lookup_funcs';args=[ordered]@{queries=@('0x00595760','sub_595760','TextFilter_Constructor','0x005957a0','sub_5957A0','TextFilter_Destructor','0x005957c0','sub_5957C0','SanitizeWideTextForChat','0x005958d0','sub_5958D0','TextFilter_ScalarDeletingDestructor','0x004f5fb0','0x004f6490','0x00525b10','0x00525ba0','0x00525dc0','0x00525eb0','0x00525f40','0x00525f60','0x00525fa0','0x00525ff0','0x00526060','0x00526080');database=$Database}})
  $plan.Add([ordered]@{id='RBT04';tool='entity_query';args=[ordered]@{queries=[ordered]@{kind='names';regex='^(unk_67ADC8|g_pTextFilter)$';fields=@('addr','name');count=20};database=$Database}})
  $addrs=@('0x00595760','0x005957a0','0x005957c0','0x005958d0','0x004f5fb0','0x004f6490','0x00525b10','0x00525dc0','0x00525eb0','0x00525ff0')
  $plan.Add([ordered]@{id='RBT05';tool='stack_frame';args=[ordered]@{addrs=$addrs;database=$Database}})
  $plan.Add([ordered]@{id='RBT06';tool='get_comments';args=[ordered]@{addrs=@('0x00595760','0x005957a0','0x005957c0','0x005958d0','0x005958ee','0x0067adc8','0x0062e184','0x0062e188','0x0062e18c','0x00651518','0x004f615f','0x004f5fb0','0x004f667d','0x004f6490','0x00525b10','0x00525ba0','0x00525dc0','0x00525eb0','0x00525f40','0x00525f60','0x00525fa0','0x00525ff0','0x00526060','0x00526080');database=$Database}})
  $plan.Add([ordered]@{id='RBT07';tool='inspect_items';args=[ordered]@{addrs=@('0x00595760','0x005957a0','0x005957c0','0x005958d0','0x005958ee','0x0067adc8','0x0067adc9','0x0067adca','0x0067adcb','0x0062e184','0x0062e188','0x0062e18c','0x00651518','0x004f615f','0x004f667d','0x00525b10','0x00525ba0','0x00525be0','0x00525dc0','0x00525eb0','0x00525f40','0x00525f57','0x00525f60','0x00525f95','0x00525fa0','0x00525fe2','0x00525ff0','0x00526060','0x0052607c','0x00526080','0x0052609a');database=$Database}})
  $regions=New-Object 'Collections.Generic.List[object]';foreach($r in @(@('0x00595760',53),@('0x005957a0',17),@('0x005957c0',266),@('0x005958d0',46),@('0x0067adc8',4),@('0x0062e184',12),@('0x00651518',20),@('0x004f615f',5),@('0x004f667d',6),@('0x00525b10',136),@('0x00525dc0',230),@('0x00525eb0',141),@('0x00525ff0',106))){$regions.Add([ordered]@{addr=$r[0];size=[int]$r[1]})};foreach($rm in $c.rm6.Values){$regions.Add([ordered]@{addr=$rm.start;size=($rm.bytes-split' ').Count});$regions.Add([ordered]@{addr=('0x'+(($rm.successor-split' ')[0]));size=1})}
  $plan.Add([ordered]@{id='RBT08';tool='get_bytes';args=[ordered]@{regions=@($regions);database=$Database}})
  $plan.Add([ordered]@{id='RBT09';tool='xrefs_to';args=[ordered]@{addrs=@('0x00595760','0x005957a0','0x005957c0','0x005958d0','0x0067adc8','0x0062e184','0x0062e188','0x0062e18c','0x00651518','0x00525b10','0x00525ba0','0x00525dc0','0x00525eb0','0x00525f40','0x00525f60','0x00525fa0','0x00525ff0','0x00526060','0x00526080');limit=1000;database=$Database}})
  $plan.Add([ordered]@{id='RBT10';tool='callees';args=[ordered]@{addrs=$addrs;limit=500;database=$Database}})
  $plan.Add([ordered]@{id='RBT11';tool='find_bytes';args=[ordered]@{patterns=$c.patterns;limit=100;database=$Database}})
  foreach($rm in $c.rm6.Values){$plan.Add([ordered]@{id=$rm.id;tool='disasm';args=[ordered]@{addr=$rm.start;max_instructions=$rm.count;offset=0;include_total=$true;database=$Database}});$successorAddr='0x'+(($rm.successor-split' ')[0]);$plan.Add([ordered]@{id=$rm.successor_id;tool='disasm';args=[ordered]@{addr=$successorAddr;max_instructions=1;offset=0;include_total=$true;database=$Database}})}
  $profile=@();foreach($a in $addrs){$profile+=,[ordered]@{addr=$a;offset=0;count=1;include_lists=$true;max_items=$(if($a-ceq'0x004f5fb0'){1000}elseif($a-ceq'0x004f6490'){800}elseif($a-ceq'0x005957c0'){500}else{300});include_prototype=$true}};$plan.Add([ordered]@{id='RBT24';tool='func_profile';args=[ordered]@{queries=$profile;database=$Database}})
  $i=25;foreach($a in @('0x00595760','0x005957a0','0x005957c0','0x005958d0')){$plan.Add([ordered]@{id=('RBT{0:d2}'-f$i);tool='decompile';args=[ordered]@{addr=$a;include_addresses=$true;database=$Database}});$i++}
  if($plan.Count-ne28){Throw-UID0002OZTc3R 'TC3R_RBT_PLAN_COUNT'};@($plan)
}
function Invoke-UID0002OZTc3RRbt($Journal,$Channel,[string]$Database,[string]$Role,[ValidateSet('PRE','POST')][string]$State,$Effects){$bundle=New-Object 'Collections.Generic.Dictionary[string,object]' ([StringComparer]::Ordinal);foreach($spec in (Get-UID0002OZTc3RRbtPlan $Database)){$call=Invoke-UID0002OZTc3RCall $Journal $Channel $spec.tool $spec.args $Role $Effects;$sc=Get-UID0002OZTc3RStructured $call $spec.tool;if($spec.id-ceq'RBT11'){$sc=[ordered]@{data=$sc['data'];next_offset=$sc['next_offset'];patterns=$spec.args.patterns;total=$sc['total']}};$bundle.Add($spec.id,$sc);Assert-UID0002OZTc3RResponse $Journal $call.Request $true (Get-UID0002OZTc3RCanonicalSha $sc)};if($bundle.Count-ne28){Throw-UID0002OZTc3R 'TC3R_RBT_EXECUTION_COUNT'}
  $core=New-Object 'Collections.Generic.Dictionary[string,object]' ([StringComparer]::Ordinal);foreach($i in 1..23){$id='RBT{0:d2}'-f$i;$core.Add($id,$bundle[$id])};Assert-UID0002OZTc3RRbtBundle $core $State|Out-Null;$profile=$bundle['RBT24'];if($profile['data']-isnot[System.Array]-or$null-ne$profile['next_offset']-or@($profile['data']|Where-Object{$_['lists_truncated']-is[bool]-and$_['lists_truncated']}).Count-ne0){Throw-UID0002OZTc3R 'TC3R_FUNC_PROFILE_EXACT'};foreach($id in @('RBT25','RBT26','RBT27','RBT28')){$d=$bundle[$id];if($d['addr']-isnot[string]-or$d['code']-isnot[string]-or$d['locals']-isnot[System.Array]){Throw-UID0002OZTc3R ('TC3R_DECOMP_EXACT:'+ $id)}};[Collections.ObjectModel.ReadOnlyDictionary[string,object]]::new($bundle)}
function Get-UID0002OZTc3RRuntimeCall($Journal,$Channel,[string]$Database,[string]$Path,[string]$Role,$Effects){$args=[ordered]@{expected_database=$Database;expected_canonical_path=$Path};$call=Invoke-UID0002OZTc3RCall $Journal $Channel 'runtime_attestation' $args $Role $Effects;$sc=Get-UID0002OZTc3RStructured $call 'runtime_attestation';$listCall=Invoke-UID0002OZTc3RCall $Journal $Channel 'idb_list' ([ordered]@{}) $Role $Effects;$list=Get-UID0002OZTc3RStructured $listCall 'idb_list';$runtime=Assert-UID0002OZTc3RRuntime $sc $Database $Path $list (Get-UID0002OZTc3RSocketSnapshot) -RequireOwned:([bool]$Database);Assert-UID0002OZTc3RResponse $Journal $call.Request $true (Get-UID0002OZTc3RCanonicalSha $sc);Assert-UID0002OZTc3RResponse $Journal $listCall.Request $true (Get-UID0002OZTc3RCanonicalSha $list);$runtime}
function Open-UID0002OZTc3RRole($Journal,$Channel,[string]$RoleName,$RoleStack,$Effects){$pre=Get-UID0002OZTc3RRuntimeCall $Journal $Channel '' $Journal.CanonicalPath ($RoleName+'-pre') $Effects;$role=New-UID0002OZTc3ROpeningRecord $Journal $RoleName $pre;$RoleStack.Add($role);try{$openArgs=[ordered]@{input_path=$Journal.CanonicalPath;mode='force_headless';run_auto_analysis=$false;build_caches=$true;init_hexrays=$true;idle_ttl_sec=3600;preferred_session_id=('uid0002oz-tc3r-'+$RoleName+'-'+[datetime]::UtcNow.ToString('yyyyMMddHHmmssfffffff'))};$call=Invoke-UID0002OZTc3RCall $Journal $Channel 'idb_open' $openArgs $RoleName $Effects;$sc=Get-UID0002OZTc3RStructured $call 'idb_open';Assert-UID0002OZTc3RKeys $sc @('session') 'TC3R_OPEN_RESULT';Assert-UID0002OZTc3RKeys $sc['session'] @('canonical_path','input_path','session_id') 'TC3R_OPEN_SESSION';$db=$sc['session']['session_id'];if($db-isnot[string]-or[string]::IsNullOrWhiteSpace($db)-or-not[string]::Equals([IO.Path]::GetFullPath($sc['session']['canonical_path']),$Journal.CanonicalPath,[StringComparison]::OrdinalIgnoreCase)){Throw-UID0002OZTc3R 'TC3R_OPEN_RETURNED_BINDING'};Assert-UID0002OZTc3RResponse $Journal $call.Request $true (Get-UID0002OZTc3RCanonicalSha $sc);$post=Get-UID0002OZTc3RRuntimeCall $Journal $Channel $db $Journal.CanonicalPath $RoleName $Effects;$new=@($post.workers|Where-Object{@($pre.workers|Where-Object{$_.process['generation']-ceq$_.process['generation']}).Count-eq0-and$_.session['session_id']-ceq$db});if($new.Count-ne1-or-not$new[0].supervisor['owned']){Throw-UID0002OZTc3R 'TC3R_OPEN_DELTA'};$role.Binding=$new[0];$role.OwnedGeneration=$new[0].process['generation'];$role.Database=$db;$role.State='OPEN';Assert-UID0002OZTc3RBoundary $pre $post 'OPEN' (Get-UID0002OZTc3RWorkerStableKey $new[0])|Out-Null;Write-UID0002OZTc3RJournal $Journal 'ROLE_OPEN' ([ordered]@{role=$RoleName;database=$db;generation=$role.OwnedGeneration;binding_sha=(Get-UID0002OZTc3RCanonicalSha $new[0])});$role}catch{throw}}
function Retire-UID0002OZTc3RRole($Journal,$Channel,$Role,$Effects){if($Role.Retired){return};if($Role.State-cne'OPEN'-or$null-eq$Role.Binding-or-not$Role.Binding.supervisor['owned']-or$Role.Binding.supervisor['adopted']){Throw-UID0002OZTc3R 'TC3R_RETIRE_AUTHORITY'};$before=Get-UID0002OZTc3RRuntimeCall $Journal $Channel $Role.Database $Journal.CanonicalPath ($Role.Role+'-retire-pre') $Effects;$pid=[int]$Role.Binding.process['pid'];if($pid-eq$PID-or$pid-eq[int]$before.listener.process['pid']){Throw-UID0002OZTc3R 'TC3R_RETIRE_PROTECTED_PID'};$process=Get-Process -Id $pid -ErrorAction Stop;if($process.StartTime.ToUniversalTime().ToFileTimeUtc()-ne[int64]$Role.Binding.process['creation_time_100ns']){Throw-UID0002OZTc3R 'TC3R_RETIRE_PID_REUSE'};$Effects.stop=[int]$Effects.stop+1;Stop-Process -Id $pid -Force -ErrorAction Stop;$process.WaitForExit();$after=Get-UID0002OZTc3RRuntimeCall $Journal $Channel '' $Journal.CanonicalPath ($Role.Role+'-retire-post') $Effects;Assert-UID0002OZTc3RRetired $Role $before $after @($before.listener.process['generation'])|Out-Null;if(@(Get-UID0002OZTc3RSocketSnapshot|Where-Object{$_['pid']-eq$pid}).Count-ne0){Throw-UID0002OZTc3R 'TC3R_RETIRED_SOCKET_PRESENT'};Write-UID0002OZTc3RJournal $Journal 'ROLE_RETIRED' ([ordered]@{role=$Role.Role;generation=$Role.OwnedGeneration;runtime_sha=(Get-UID0002OZTc3RCanonicalSha $after)});$after}
function Invoke-UID0002OZTc3RMutationPlan($Journal,$Channel,$Role,$Effects){foreach($spec in (New-UID0002OZTc3RMutationPlan)){$args=[ordered]@{database=$Role.Database;contract_id=$spec.id;request=$spec.request};$call=Invoke-UID0002OZTc3RCall $Journal $Channel $spec.tool $args $Role.Role $Effects;$sc=Get-UID0002OZTc3RStructured $call $spec.tool;Assert-UID0002OZTc3RMutationResult $spec $sc|Out-Null;Assert-UID0002OZTc3RResponse $Journal $call.Request $true (Get-UID0002OZTc3RCanonicalSha $sc);if($spec.id-notmatch'D$'){$Effects.mutation=[int]$Effects.mutation+1};$null=Invoke-UID0002OZTc3RRbt $Journal $Channel $Role.Database $Role.Role 'POST' $Effects}}
function Invoke-UID0002OZTc3RController {
  $effects=New-UID0002OZTc3REffects;$channel=New-UID0002OZTc3RChannel;$journal=$null;$roles=New-Object 'Collections.Generic.List[object]';$result=$null;$failure=$null
  try{$toolsRaw=Initialize-UID0002OZTc3RBootstrap $channel $effects;$journal=New-UID0002OZTc3RJournal $toolsRaw;$p0=Get-UID0002OZTc3RClosedTuple $journal.CanonicalPath;if($p0.length-ne143197685-or$p0.sha256-cne'2F5594535B9730C2195466DC6673A6325B19E572D0DCCB9D054B0F6DFAC48D70'-or$p0.ticks-ne639216052962969329){Throw-UID0002OZTc3R 'TC3R_INITIAL_P0'};Write-UID0002OZTc3RJournal $journal 'P0_COMMITTED' $p0;$b0=New-UID0002OZTc3RB0 $journal $p0 $effects
    $diagnostic=Open-UID0002OZTc3RRole $journal $channel 'diagnostic' $roles $effects;$null=Invoke-UID0002OZTc3RRbt $journal $channel $diagnostic.Database $diagnostic.Role 'PRE' $effects;$null=Retire-UID0002OZTc3RRole $journal $channel $diagnostic $effects;Assert-UID0002OZTc3RFinalTuple (Get-UID0002OZTc3RClosedTuple $journal.CanonicalPath) $p0 'TC3R_DIAGNOSTIC_P0'|Out-Null
    $transaction=Open-UID0002OZTc3RRole $journal $channel 'transaction' $roles $effects;$pre=Invoke-UID0002OZTc3RRbt $journal $channel $transaction.Database $transaction.Role 'PRE' $effects;Invoke-UID0002OZTc3RMutationPlan $journal $channel $transaction $effects;$post=Invoke-UID0002OZTc3RRbt $journal $channel $transaction.Database $transaction.Role 'POST' $effects;Assert-UID0002OZTc3RFinalTuple (Get-UID0002OZTc3RClosedTuple $journal.CanonicalPath) $p0 'TC3R_PRESAVE_P0'|Out-Null
    $save=Invoke-UID0002OZTc3RCall $journal $channel 'idb_save' ([ordered]@{database=$transaction.Database;path=$journal.CanonicalPath}) $transaction.Role $effects -Save;$saveSc=Get-UID0002OZTc3RStructured $save 'idb_save';Assert-UID0002OZTc3RResponse $journal $save.Request $true (Get-UID0002OZTc3RCanonicalSha $saveSc);$closedRuntime=Retire-UID0002OZTc3RRole $journal $channel $transaction $effects;$candidate=Get-UID0002OZTc3RClosedTuple $journal.CanonicalPath;$saveRecord=@($journal.Records|Where-Object{$_.kind-ceq'SAVE_CLASSIFIED'}|Select-Object -Last 1)[0];$receipt=[ordered]@{attempt='UID0002OZ-TC3R';save_request=$save.Request.Id;journal_chain=$journal.Chain;catalog_sha=@($journal.Records|Where-Object{$_.kind-ceq'CATALOG_COMMITTED'})[0].payload.catalog_sha;raw_response_sha=$save.Request.RawSha;save_class=$journal.SaveClass;retirement_sha=(Get-UID0002OZTc3RCanonicalSha @($journal.Records|Where-Object{$_.kind-ceq'ROLE_RETIRED'}|Select-Object -Last 1));runtime_sha=(Get-UID0002OZTc3RCanonicalSha $closedRuntime);er00_sha=(Get-UID0002OZTc3RCanonicalSha $candidate);sole_writer=($effects.save-eq1);candidate=$candidate};$identity=Resolve-UID0002OZTc3RDiskIdentity $candidate $p0 $receipt;if($identity-ceq'THIRD_IDENTITY'){Throw-UID0002OZTc3R 'TC3R_THIRD_IDENTITY'}
    $verifier=Open-UID0002OZTc3RRole $journal $channel 'verifier' $roles $effects;$effects.verifier=[int]$effects.verifier+1;$null=Invoke-UID0002OZTc3RRbt $journal $channel $verifier.Database $verifier.Role $(if($identity-ceq'EXACT_P0'){'PRE'}else{'POST'}) $effects;$verifierClosed=Retire-UID0002OZTc3RRole $journal $channel $verifier $effects;$verifiedTuple=Get-UID0002OZTc3RClosedTuple $journal.CanonicalPath;if($identity-ceq'EXACT_P0'){Assert-UID0002OZTc3RFinalTuple $verifiedTuple $p0 'TC3R_VERIFIER_P0'|Out-Null}elseif(-not(Test-UID0002OZTc3RFullTuple $verifiedTuple $candidate)){Throw-UID0002OZTc3R 'TC3R_VERIFIER_S1'}
    if($identity-ceq'ATTEMPT_S1'-and$journal.SaveClass-cne'EXPLICIT_SUCCESS'){$authority=New-UID0002OZTc3RRestoreAuthority $journal $p0 $b0 $candidate $receipt (@($journal.Records|Where-Object{$_.kind-ceq'ROLE_RETIRED'}|Select-Object -Last 1)) $verifierClosed ([ordered]@{result='failed-or-indeterminate';tuple=$verifiedTuple});$restored=Use-UID0002OZTc3RRestore $journal $authority $b0 $candidate $effects;$rollback=Open-UID0002OZTc3RRole $journal $channel 'rollback-verifier' $roles $effects;$effects.verifier=[int]$effects.verifier+1;$null=Invoke-UID0002OZTc3RRbt $journal $channel $rollback.Database $rollback.Role 'PRE' $effects;$null=Retire-UID0002OZTc3RRole $journal $channel $rollback $effects;Assert-UID0002OZTc3RFinalTuple (Get-UID0002OZTc3RClosedTuple $journal.CanonicalPath) $restored 'TC3R_ROLLBACK_FINAL_REHASH'|Out-Null}
    $final=Get-UID0002OZTc3RClosedTuple $journal.CanonicalPath;if($identity-ceq'EXACT_P0'){Assert-UID0002OZTc3RFinalTuple $final $p0 'TC3R_FINAL_P0_REHASH'|Out-Null}elseif($journal.RestoreConsumed){if($final.sha256-cne$p0.sha256-or$final.length-ne$p0.length-or$final.ticks-ne$p0.ticks){Throw-UID0002OZTc3R 'TC3R_FINAL_RESTORED_REHASH'}}else{Assert-UID0002OZTc3RFinalTuple $final $candidate 'TC3R_FINAL_S1_REHASH'|Out-Null};Assert-UID0002OZTc3RLedgerParity $journal|Out-Null;$result=[ordered]@{identity=$identity;save_class=$journal.SaveClass;final=$final;effects=(Copy-UID0002OZTc3REffects $effects)}
  }catch{$failure=$_;throw}finally{for($i=$roles.Count-1;$i-ge0;$i--){$role=$roles[$i];if(-not$role.Retired-and$null-ne$journal){try{$null=Retire-UID0002OZTc3RRole $journal $channel $role $effects;$effects.cleanup=[int]$effects.cleanup+1}catch{if($null-eq$failure){$failure=$_}}}};$channel.Closed=$true;if($null-ne$journal){Close-UID0002OZTc3RJournal $journal};if($null-ne$failure-and$null-ne$result){Throw-UID0002OZTc3R ('TC3R_CLEANUP_FAILURE:'+ $failure.Exception.Message)}};$result
}
~~~

## Removed Block R024

- SHA256: `5EACE342AD7219B902FA504E9D5A8DCAC5CE57B61611DEAB5A145A28B9DF2B86`
- Language: `powershell`
- Bytes: `10223`
- First recovered timestamp: `2026-08-07T02:27:25.882Z`
- Session provenance: rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 196231 (2026-08-07T02:27:25.882Z); rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 196232 (2026-08-07T02:27:25.939Z)

~~~powershell
function New-UID0002OZTc3RFixtureCatalog {
  $zero='0,0,0,0,0,0,0,0,0';$rows=@(
    @('json-escaped-high-truncated','escaped high surrogate without low','TC3R_JSON_SURROGATE_PAIR',$zero),@('json-escaped-low-isolated','escaped isolated low surrogate','TC3R_JSON_ISOLATED_LOW_SURROGATE',$zero),@('json-escaped-high-mismatch','escaped high followed by non-low','TC3R_JSON_SURROGATE_PAIR',$zero),@('json-raw-high-truncated','raw high surrogate without low','TC3R_JSON_TRUNCATED',$zero),@('json-raw-low-isolated','raw isolated low surrogate','TC3R_JSON_ISOLATED_LOW_SURROGATE',$zero),@('json-duplicate-root','duplicate root member','TC3R_JSON_DUPLICATE_MEMBER:a',$zero),@('json-duplicate-nested','recursive duplicate nested member','TC3R_JSON_DUPLICATE_MEMBER:x',$zero),@('json-duplicate-decoded','escaped and raw key decode equal','TC3R_JSON_DUPLICATE_MEMBER:a',$zero),
    @('schema-description-drift','tool description differs','TC3R_TOOL_DESCRIPTION:runtime_attestation',$zero),@('schema-required-drift','required differs','TC3R_SCHEMA_REQUIRED:idb_open',$zero),@('schema-extra-property','unlisted property','TC3R_SCHEMA_PROPERTIES:callees',$zero),@('schema-default-native','integer default encoded string','TC3R_SCHEMA_DEFAULT:callees.limit',$zero),@('schema-maximum-drift','callees maximum 1000','TC3R_SCHEMA_MAXIMUM:callees.limit',$zero),@('schema-public-runtime-alias','runtime/attest advertised','TC3R_PUBLIC_RUNTIME_CARDINALITY',$zero),
    @('rpc-duplicate-request','same request ID reserved twice','TC3R_REQUEST_REPLAY',$zero),@('rpc-late-response','classified request receives response','TC3R_RESPONSE_LATE',$zero),@('rpc-wrong-native-id','numeric response ID','TC3R_RPC_CORRELATION',$zero),@('rpc-wrong-value-id','mismatched string response ID','TC3R_RPC_CORRELATION',$zero),@('rpc-malformed-save','truncated save JSON','TC3R_JSON_TRUNCATED','1,0,1,0,0,0,0,0,0'),@('rpc-save-timeout','save transport timeout','TC3R_SAVE_INDETERMINATE','1,0,1,0,0,0,0,0,0'),@('rpc-save-retry','second save after ambiguous first','TC3R_SAVE_ALREADY_ISSUED','1,0,1,0,0,0,0,0,0'),
    @('runtime-listener-extra','extra listener property','TC3R_LISTENER_OWNER_KEYS',$zero),@('runtime-worker-extra','extra worker property','TC3R_WORKER_OWNER_KEYS',$zero),@('runtime-module-physical-drift','module bytes differ from attestation','TC3R_MODULE_PHYSICAL_DRIFT',$zero),@('runtime-manifest-recompute','manifest digest differs','TC3R_WORKER_MANIFEST_RECOMPUTE',$zero),@('runtime-listener-socket','listener socket PID differs','TC3R_LISTENER_SOCKET',$zero),@('runtime-worker-socket','worker socket PID differs','TC3R_WORKER_SOCKET',$zero),@('runtime-owned-parent','owned parent differs from redirector','TC3R_OWNED_PARENT',$zero),@('runtime-adopted-transaction','adopted worker selected for mutation','TC3R_TRANSACTION_ADOPTED',$zero),@('runtime-list-correlation','idb_list PID/path/session differs','TC3R_IDB_LIST_CORRELATION',$zero),@('runtime-nonce-replay','boundary nonce does not advance','TC3R_BOUNDARY_FRESHNESS',$zero),@('runtime-worker-time-replay','worker observation time does not advance','TC3R_WORKER_FRESHNESS',$zero),
    @('open-response-timeout','idb_open creates worker then response is lost','TC3R_OPEN_RESPONSE_TIMEOUT','1,0,0,1,0,0,0,0,1'),@('open-post-attestation-fail','new owned worker fails post-open attestation','TC3R_PARTIAL_OPEN_BINDING','2,0,0,1,0,0,0,0,1'),@('open-delta-cardinality','two generations appear after one open','TC3R_PARTIAL_OPEN_DELTA','2,0,0,0,0,0,0,0,1'),@('retire-pid-reuse','PID creation identity changes','TC3R_RETIRE_PID_REUSE','0,0,0,0,0,0,0,0,0'),@('retire-socket-survives','worker socket remains after stop','TC3R_RETIRED_SOCKET_PRESENT','2,0,0,1,0,0,0,0,1'),
    @('rbt-call-missing','one of 28 calls absent','TC3R_RBT_EXECUTION_COUNT',$zero),@('rbt-type-pagination','type query has next page','TC3R_RBT01_PAGINATION',$zero),@('rbt-function-type','modeled function type differs','TC3R_LOOKUP_TYPE:0x005957c0',$zero),@('rbt-xref-count','Sanitize caller count differs','TC3R_XREF_CALLEE_EXACT',$zero),@('rbt-callees-truncated','callees more true','TC3R_XREF_CALLEE_TRUNCATION',$zero),@('rbt-find-hit','one deterministic pattern resolves','TC3R_FIND_BYTES_NOT_ZERO',$zero),@('rbt-rm6-byte','one RM-6 byte differs','TC3R_RM6_BYTES:RBT12',$zero),@('rbt-rm6-instruction','one RM-6 instruction differs','TC3R_RM6_INSTRUCTIONS:RBT18',$zero),@('rbt-rm6-successor','one successor differs','TC3R_RM6_SUCCESSOR:RBT20',$zero),
    @('mutation-extra-field','mutation result has extra field','TC3R_MUTATION_ROW:I002N_KEYS',$zero),@('mutation-old-state','mutation old state differs','TC3R_MUTATION_SEMANTICS:I004LN',$zero),@('mutation-current-state','mutation current state differs','TC3R_MUTATION_SEMANTICS:I006N',$zero),@('mutation-post-rbt','post-mutation RB-T differs','TC3R_LOOKUP_NAME:0x00595760','0,1,0,0,0,0,0,0,0'),
    @('classifier-arbitrary-same-path','changed same path lacks attempt receipt','TC3R_THIRD_IDENTITY',$zero),@('classifier-exact-p0','exact P0 not classified exact','TC3R_CLASSIFIER_EXACT_P0',$zero),@('classifier-attributed-s1','complete attempt receipt not classified S1','TC3R_CLASSIFIER_ATTEMPT_S1',$zero),@('classifier-save-request','receipt save request differs','TC3R_THIRD_IDENTITY',$zero),@('classifier-sole-writer','save count not exactly one','TC3R_THIRD_IDENTITY',$zero),
    @('backup-existing-path','CreateNew collides','TC3R_B0_COLLISION',$zero),@('backup-short-copy','backup byte count short','TC3R_B0_COPY','0,0,0,0,0,1,0,0,0'),@('backup-reopen-tuple','closed B0 tuple differs from held','TC3R_B0_REOPEN','0,0,0,0,0,1,0,0,0'),@('restore-forged-permit','permit MAC differs','TC3R_RESTORE_PERMIT_FORGED',$zero),@('restore-reused-permit','permit already consumed','TC3R_RESTORE_PERMIT_CONSUMED',$zero),@('restore-b0-drift','B0 held tuple differs','TC3R_RESTORE_B0_DRIFT',$zero),@('restore-s1-drift','destination held tuple differs','TC3R_RESTORE_S1_DRIFT',$zero),@('restore-alias','B0 and S1 physical file ID equal','TC3R_RESTORE_S1_DRIFT',$zero),@('restore-short-copy','copy count or EOF differs','TC3R_RESTORE_COPY','0,0,0,0,1,1,0,0,0'),@('restore-held-tuple','held post-restore tuple differs','TC3R_RESTORE_HELD','0,0,0,0,1,1,0,0,0'),@('restore-reopen-tuple','closed post-restore tuple differs','TC3R_RESTORE_REOPEN','0,0,0,0,1,1,1,0,0'),@('rollback-verifier','fresh rollback RB-T differs','TC3R_ROLLBACK_FINAL_REHASH','0,0,0,1,1,1,1,1,1'),@('final-p0-rehash','P0 branch final tuple differs','TC3R_FINAL_P0_REHASH','0,0,1,2,0,0,0,1,2'),@('final-s1-rehash','S1 branch final tuple differs','TC3R_FINAL_S1_REHASH','0,1,1,2,0,0,0,1,2'),@('final-restored-rehash','rollback final content differs','TC3R_FINAL_RESTORED_REHASH','0,1,1,3,1,1,1,2,3'))
  $d=New-Object 'Collections.Generic.Dictionary[string,object]' ([StringComparer]::Ordinal);foreach($r in $rows){if($d.ContainsKey($r[0])){Throw-UID0002OZTc3R 'TC3R_FIXTURE_DUPLICATE'};$d.Add($r[0],[ordered]@{name=$r[0];defect=$r[1];label=$r[2];effects=$r[3]})};[Collections.ObjectModel.ReadOnlyDictionary[string,object]]::new($d)
}
function Assert-UID0002OZTc3RFixtureReceipt($Fixture,$Receipt){Assert-UID0002OZTc3RKeys $Receipt @('after','before','defect_count','fixture','label') 'TC3R_FIXTURE_RECEIPT';if($Receipt['fixture']-cne$Fixture.name-or$Receipt['label']-cne$Fixture.label-or$Receipt['defect_count']-isnot[int]-or$Receipt['defect_count']-ne1){Throw-UID0002OZTc3R ('TC3R_FIXTURE_LABEL:'+ $Fixture.name)};$keys=@('transport','mutation','save','stop','truncate','write','restore','verifier','cleanup');$delta=@();foreach($k in $keys){$delta+=([int]$Receipt['after'][$k]-[int]$Receipt['before'][$k])};if(($delta-join',')-cne$Fixture.effects){Throw-UID0002OZTc3R ('TC3R_FIXTURE_EFFECTS:'+ $Fixture.name)};$true}
function Invoke-UID0002OZTc3RPureFixtures {
  $results=New-Object 'Collections.Generic.List[object]';$cases=@(
    [ordered]@{name='json-escaped-high-truncated';label='TC3R_JSON_SURROGATE_PAIR';run={ConvertFrom-UID0002OZTc3RJson '{"x":"\uD800"}'}},
    [ordered]@{name='json-escaped-low-isolated';label='TC3R_JSON_ISOLATED_LOW_SURROGATE';run={ConvertFrom-UID0002OZTc3RJson '{"x":"\uDC00"}'}},
    [ordered]@{name='json-escaped-high-mismatch';label='TC3R_JSON_SURROGATE_PAIR';run={ConvertFrom-UID0002OZTc3RJson '{"x":"\uD800\u0041"}'}},
    [ordered]@{name='json-duplicate-root';label='TC3R_JSON_DUPLICATE_MEMBER:a';run={ConvertFrom-UID0002OZTc3RJson '{"a":1,"a":2}'}},
    [ordered]@{name='json-duplicate-nested';label='TC3R_JSON_DUPLICATE_MEMBER:x';run={ConvertFrom-UID0002OZTc3RJson '{"a":{"x":1,"x":2}}'}},
    [ordered]@{name='json-duplicate-decoded';label='TC3R_JSON_DUPLICATE_MEMBER:a';run={ConvertFrom-UID0002OZTc3RJson '{"a":1,"\u0061":2}'}},
    [ordered]@{name='mutation-extra-field';label='TC3R_MUTATION_ROW:I002N_KEYS';run={$s=[ordered]@{id='I002N';request='TextFilter_Constructor';old='HISTORICAL_PRESTATE';new='ACCEPTED_POSTSTATE'};Assert-UID0002OZTc3RMutationResult $s ([ordered]@{results=@([ordered]@{action='TextFilter_Constructor';current='ACCEPTED_POSTSTATE';error=$null;extra=1;new='ACCEPTED_POSTSTATE';ok=$true;old='HISTORICAL_PRESTATE'})})}},
    [ordered]@{name='classifier-arbitrary-same-path';label='TC3R_THIRD_IDENTITY';run={$p=[ordered]@{path='p';volume=1;file_id='1';links=1;length=1;sha256=('A'*64);ticks=1};$c=[ordered]@{path='p';volume=1;file_id='1';links=1;length=2;sha256=('B'*64);ticks=2};if((Resolve-UID0002OZTc3RDiskIdentity $c $p ([ordered]@{}))-cne'THIRD_IDENTITY'){Throw-UID0002OZTc3R 'TC3R_THIRD_IDENTITY'}}},
    [ordered]@{name='restore-reused-permit';label='TC3R_RESTORE_PERMIT_CONSUMED';run={$j=[pscustomobject]@{RestoreConsumed=$true};$a=[pscustomobject]@{Consumed=$true};Use-UID0002OZTc3RRestore $j $a ([ordered]@{}) ([ordered]@{}) (New-UID0002OZTc3REffects)}})
  foreach($case in $cases){$before=New-UID0002OZTc3REffects;$observed=$null;try{&$case.run|Out-Null;$observed='NO_ERROR'}catch{$observed=$_.Exception.Message};if($observed-cne$case.label){Throw-UID0002OZTc3R ('TC3R_PURE_FIXTURE:'+ $case.name+':'+$observed)};$results.Add([ordered]@{fixture=$case.name;label=$observed;before=$before;after=(Copy-UID0002OZTc3REffects $before);defect_count=1})};@($results)
}
$UID0002OZTc3RPureFixtureTranscript=@(Invoke-UID0002OZTc3RPureFixtures)
~~~

## Removed Block R025

- SHA256: `2C650DD55D63B1D7B3D8AA34BB9E1A87A51D81484976BEEF448CEE46072038FE`
- Language: `powershell`
- Bytes: `8108`
- First recovered timestamp: `2026-08-08T19:40:33.773Z`
- Session provenance: rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 197132 (2026-08-08T19:40:33.773Z); rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 197133 (2026-08-08T19:40:33.835Z)

~~~powershell
$UID0002OZTc3RD1Report=[IO.Path]::GetFullPath('E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\0002OZ-TextFilterVtableData-empty-emitter-source-quality.md')
function Get-UID0002OZTc3RD1Payload {
  $text=[IO.File]::ReadAllText($UID0002OZTc3RD1Report,(New-Object Text.UTF8Encoding($false,$true)));$matches=[regex]::Matches($text,'(?ms)^~~~powershell\n(?<code>.*?)^~~~\n');$specs=@(
    @('01-json-contracts','UID0002OZTc3RJson','__D1_HASH_01__'),@('02-canonical-ledger','function ConvertTo-UID0002OZTc3RCanonicalJson','__D1_HASH_02__'),@('03-file-identity','UID0002OZTc3RFileNative','__D1_HASH_03__'),@('04-target-semantics','function New-UID0002OZTc3RTargetContract','__D1_HASH_04__'),@('05-transport-persistence','UID0002OZTc3RSetTime','__D1_HASH_05__'),@('06-rbt-physical-core','function Invoke-UID0002OZTc3RPhysicalController','__D1_HASH_06__'),@('07-independent-oracle','function New-UID0002OZTc3RFixtureCatalog','__D1_HASH_07__'),@('08-raw-boundary-guards','function New-UID0002OZTc3RMemoryJournal','__D1_HASH_08__'),@('09-raw-case-builder','function New-UID0002OZTc3RRawHostileCase','__D1_HASH_09__'),@('10-singular-d1-core','function Invoke-UID0002OZTc3RD1Core','__D1_HASH_10__'))
  $blocks=New-Object 'Collections.Generic.List[string]';foreach($spec in $specs){$hits=@($matches|Where-Object{$_.Groups['code'].Value.Contains($spec[1])});if($hits.Count-ne1){throw ('TC3R_D1_BLOCK_CARDINALITY:'+ $spec[0])};$code=[string]$hits[0].Groups['code'].Value;$sha=Get-UID0002OZTc3RD1TextSha $code;if($sha-cne$spec[2]){throw ('TC3R_D1_BLOCK_SHA:'+ $spec[0]+':'+$sha)};$blocks.Add($code)};$payload=($blocks.ToArray()-join"`n");$payloadSha=Get-UID0002OZTc3RD1TextSha $payload;if($payloadSha-cne'__D1_PAYLOAD_HASH__'){throw ('TC3R_D1_PAYLOAD_SHA:'+ $payloadSha)};[pscustomobject]@{Source=$payload;Sha=$payloadSha;Blocks=$specs.Count}
}
function Get-UID0002OZTc3RD1TextSha([string]$Text){$h=[Security.Cryptography.SHA256]::Create();try{([BitConverter]::ToString($h.ComputeHash([Text.Encoding]::UTF8.GetBytes($Text)))).Replace('-','')}finally{$h.Dispose()}}
function Invoke-UID0002OZTc3RD1Sealed([ValidateSet('LIVE','FIXTURE')][string]$Mode,[string]$CaseName=''){
  $payload=Get-UID0002OZTc3RD1Payload;$rs=[System.Management.Automation.Runspaces.RunspaceFactory]::CreateRunspace();$ps=[PowerShell]::Create();try{$rs.Open();$ps.Runspace=$rs;$null=$ps.AddScript($payload.Source).Invoke();if($ps.HadErrors){throw ('TC3R_D1_LOAD:'+($ps.Streams.Error|Select-Object -First 1))};$ps.Commands.Clear();$script=@'
param($Mode,$CaseName)
$root=Join-Path ([IO.Path]::GetTempPath()) ('UID0002OZ-TC3R-D1-'+[guid]::NewGuid().ToString('N'));[IO.Directory]::CreateDirectory($root)|Out-Null
try {
  if($Mode-ceq'FIXTURE'){$case=New-UID0002OZTc3RD1RawCase $CaseName;New-Variable -Name UID0002OZTc3RD1Raw -Scope Global -Option Constant -Value $case.Raw;New-Variable -Name UID0002OZTc3RD1JournalPath -Scope Global -Option Constant -Value (Join-Path $root 'transaction.journal')}else{New-Variable -Name UID0002OZTc3RD1JournalPath -Scope Global -Option Constant -Value ''}
  New-Variable -Name UID0002OZTc3RD1Mode -Scope Global -Option Constant -Value $Mode
  $receipt=Invoke-UID0002OZTc3RController;Assert-UID0002OZTc3RSharedReceipt $receipt|Out-Null
  if($Mode-ceq'FIXTURE'){$oracle=New-UID0002OZTc3RFixtureCatalog;$expected=$oracle[$CaseName];if($null-eq$expected-or$receipt.Body.label-cne$expected.label){Throw-UID0002OZTc3R ('TC3R_D1_ORACLE:'+ $CaseName+':'+$receipt.Body.label)};$rawSha=Get-UID0002OZTc3RCanonicalSha $case.Raw;[ordered]@{name=$CaseName;raw_sha=$rawSha;raw_utf16_sha=(Get-UID0002OZTc3RSha256 ([Text.Encoding]::Unicode.GetBytes([Convert]::ToBase64String([byte[]]$case.Raw.Parser.bytes))));label=$receipt.Body.label;boundary=$receipt.Body.boundary;effects=(@('transport','mutation','save','stop','truncate','write','restore','verifier','cleanup')|ForEach-Object{[string]$receipt.Body.effects[$_]})-join',';physical=(@('mcp','ida','disk','process')|ForEach-Object{[string]$receipt.Body.physical[$_]})-join',';journal_reopened=[bool]$receipt.Body.journal_reopened;journal_records=[int]$receipt.Body.journal_records;payload_sha=$args[2]}}
  else{$receipt.Body}
} finally {if([IO.Directory]::Exists($root)){[IO.Directory]::Delete($root,$true)}}
'@;$null=$ps.AddScript($script).AddArgument($Mode).AddArgument($CaseName).AddArgument($payload.Sha);$out=@($ps.Invoke());if($ps.HadErrors){throw ('TC3R_D1_RUN:'+($ps.Streams.Error|Select-Object -First 1))};if($out.Count-ne1){throw 'TC3R_D1_RESULT_CARDINALITY'};$out[0]}finally{$ps.Dispose();$rs.Dispose()}}
if(-not(Test-Path function:Invoke-UID0002OZTc3RController)){New-Item -Path function:Invoke-UID0002OZTc3RController -Options Constant -Value {Invoke-UID0002OZTc3RD1Sealed -Mode LIVE}|Out-Null}elseif((Get-Item function:Invoke-UID0002OZTc3RController).Options-ne'Constant'){throw 'TC3R_D1_PUBLIC_ENTRY_NOT_CONSTANT'}
function Invoke-UID0002OZTc3RD1AllHostiles {$names=@('backup-existing-path','backup-reopen-tuple','backup-short-copy','classifier-arbitrary-same-path','classifier-attributed-s1','classifier-exact-p0','classifier-save-request','classifier-sole-writer','final-p0-rehash','final-restored-rehash','final-s1-rehash','json-duplicate-decoded','json-duplicate-nested','json-duplicate-root','json-escaped-high-mismatch','json-escaped-high-truncated','json-escaped-low-isolated','json-raw-high-truncated','json-raw-low-isolated','mutation-current-state','mutation-extra-field','mutation-old-state','mutation-post-rbt','open-delta-cardinality','open-post-attestation-fail','open-response-timeout','rbt-call-missing','rbt-callees-truncated','rbt-find-hit','rbt-function-type','rbt-rm6-byte','rbt-rm6-instruction','rbt-rm6-successor','rbt-type-pagination','rbt-xref-count','restore-alias','restore-b0-drift','restore-forged-permit','restore-held-tuple','restore-reopen-tuple','restore-reused-permit','restore-s1-drift','restore-short-copy','retire-pid-reuse','retire-socket-survives','rollback-verifier','rpc-duplicate-request','rpc-late-response','rpc-malformed-save','rpc-save-retry','rpc-save-timeout','rpc-wrong-native-id','rpc-wrong-value-id','runtime-adopted-transaction','runtime-list-correlation','runtime-listener-extra','runtime-listener-socket','runtime-manifest-recompute','runtime-module-physical-drift','runtime-nonce-replay','runtime-owned-parent','runtime-worker-extra','runtime-worker-socket','runtime-worker-time-replay','schema-default-native','schema-description-drift','schema-extra-property','schema-maximum-drift','schema-public-runtime-alias','schema-required-drift');$rows=New-Object 'Collections.Generic.List[object]';foreach($name in $names){$rows.Add((Invoke-UID0002OZTc3RD1Sealed -Mode FIXTURE -CaseName $name))};if($rows.Count-ne70-or@($rows|Where-Object{$_.physical-cne'0,0,0,0'-or-not$_.journal_reopened}).Count-ne0-or@($rows.raw_sha|Select-Object -Unique).Count-ne70){throw 'TC3R_D1_SUITE'};$rows.ToArray()}
function Invoke-UID0002OZTc3RD1SubstitutionHostiles {$before=@{observer=$script:UID0002OZTc3RLiveObservationProvider;actor=$script:UID0002OZTc3RLiveActionProvider};$labels=New-Object 'Collections.Generic.List[string]';try{$script:UID0002OZTc3RLiveObservationProvider={throw 'FORGED_OBSERVER'};$script:UID0002OZTc3RLiveActionProvider={};function Assert-UID0002OZTc3RSharedRuntime {throw 'FORGED_RUNTIME_DEPENDENCY'};$r=Invoke-UID0002OZTc3RD1Sealed -Mode FIXTURE -CaseName 'runtime-nonce-replay';if($r.label-cne'TC3R_BOUNDARY_FRESHNESS'){throw 'TC3R_D1_PROVIDER_ISOLATION'};$labels.Add('TC3R_D1_PROVIDER_ISOLATED');try{Set-Item -Path function:Invoke-UID0002OZTc3RController -Value {throw 'FORGED_ENTRY'} -Force -ErrorAction Stop;$labels.Add('NO_ERROR')}catch{$labels.Add('TC3R_D1_PUBLIC_ENTRY_CONSTANT')};$p=Get-UID0002OZTc3RD1Payload;$labels.Add('TC3R_D1_PAYLOAD_SHA:'+ $p.Sha)}finally{$script:UID0002OZTc3RLiveObservationProvider=$before.observer;$script:UID0002OZTc3RLiveActionProvider=$before.actor};$labels.ToArray()}
$UID0002OZTc3RD1Transcript=@(Invoke-UID0002OZTc3RD1AllHostiles)
$UID0002OZTc3RD1SubstitutionTranscript=@(Invoke-UID0002OZTc3RD1SubstitutionHostiles)
~~~

## Removed Block R026

- SHA256: `3D0CFCD54FC2A0A05F25F773222CBB7DA95389E85064BB6DA438E67A9082471C`
- Language: `powershell`
- Bytes: `12795`
- First recovered timestamp: `2026-08-08T19:40:33.773Z`
- Session provenance: rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 197132 (2026-08-08T19:40:33.773Z); rollout-2026-08-06T18-12-59-019fd923-073e-77a2-b462-96eeec51a708.jsonl line 197133 (2026-08-08T19:40:33.835Z)

~~~powershell
function Invoke-UID0002OZTc3RD1Core($Adapter) {
  if($null-eq$Adapter-or$Adapter.PSTypeNames[0]-cne'UID0002OZTc3R.RawObservationAdapter'){Throw-UID0002OZTc3R 'TC3R_D1_BOUNDARY'}
  $effects=New-UID0002OZTc3REffects;$stages=New-Object 'Collections.Generic.List[string]';$journal=$null;$save=$null;$classifier=$null;$restored=$null;$label='ACCEPTED';$failureStage='terminal';$primary=$null;$cleanupFailure=$null;$roleOpen=$false;$journalProof=$null
  try {
    $failureStage='parser';$stages.Add($failureStage);$parser=Read-UID0002OZTc3RSharedObservation $Adapter 'Parser';$rawText=ConvertFrom-UID0002OZTc3RD1Utf8 $parser.bytes;$null=ConvertFrom-UID0002OZTc3RJson $rawText
    $failureStage='schema';$stages.Add($failureStage);$schema=Read-UID0002OZTc3RSharedObservation $Adapter 'Schema';$journal=New-UID0002OZTc3RD1Journal ([string]$schema.raw ([string]$Adapter.Raw.Open.post.workers[0].session.canonical_path) ([string]$Adapter.JournalPath)
    $failureStage='rpc';$stages.Add($failureStage);Invoke-UID0002OZTc3RSharedRpc $journal (Read-UID0002OZTc3RSharedObservation $Adapter 'Rpc')|Out-Null
    $failureStage='open';$stages.Add($failureStage);$open=Read-UID0002OZTc3RSharedObservation $Adapter 'Open';$roleOpen=[bool]$open.worker_created;Assert-UID0002OZTc3RSharedOpen $open $Adapter $effects|Out-Null
    $failureStage='runtime';$stages.Add($failureStage);Assert-UID0002OZTc3RSharedRuntime (Read-UID0002OZTc3RSharedObservation $Adapter 'Runtime')|Out-Null
    $failureStage='rbt';$stages.Add($failureStage);Assert-UID0002OZTc3RSharedRbt (Read-UID0002OZTc3RSharedObservation $Adapter 'Rbt') $Adapter $effects|Out-Null
    $failureStage='mutation';$stages.Add($failureStage);Assert-UID0002OZTc3RSharedMutation (Read-UID0002OZTc3RSharedObservation $Adapter 'Mutation') $Adapter $effects|Out-Null
    $disk=Read-UID0002OZTc3RSharedObservation $Adapter 'Disk';Write-UID0002OZTc3RJournal $journal 'P0_COMMITTED' $disk.p0
    $failureStage='backup';$stages.Add($failureStage);$b0=Invoke-UID0002OZTc3RSharedBackup $journal (Read-UID0002OZTc3RSharedObservation $Adapter 'Backup') $disk $Adapter $effects;if(-not(Test-UID0002OZTc3RFullTuple $b0 $disk.b0)){Throw-UID0002OZTc3R 'TC3R_B0_REOPEN'}
    $failureStage='save';$stages.Add($failureStage);$save=Invoke-UID0002OZTc3RD1Save $journal (Read-UID0002OZTc3RSharedObservation $Adapter 'Save') $Adapter $effects
    $failureStage='retire';$stages.Add($failureStage);$closedRuntime=Invoke-UID0002OZTc3RSharedRetirement $journal (Read-UID0002OZTc3RSharedObservation $Adapter 'Retire') $Adapter $effects;$roleOpen=$false
    $failureStage='classifier';$stages.Add($failureStage);$classifier=Invoke-UID0002OZTc3RD1Classifier $journal $disk $save $closedRuntime $effects
    $failureStage='verifier';$stages.Add($failureStage);$verifier=Invoke-UID0002OZTc3RD1Verifier (Read-UID0002OZTc3RSharedObservation $Adapter 'Verifier') $classifier.Identity $disk.candidate $Adapter $effects
    $restoreRequired=$classifier.Identity-ceq'ATTEMPT_S1'-and$journal.SaveClass-cne'EXPLICIT_SUCCESS';if($restoreRequired){$failureStage='restore';$stages.Add($failureStage);$restored=Invoke-UID0002OZTc3RD1Restore $journal (Read-UID0002OZTc3RSharedObservation $Adapter 'Restore') $disk $classifier $verifier $Adapter $effects;$failureStage='rollback';$stages.Add($failureStage);$rollback=Read-UID0002OZTc3RSharedObservation $Adapter 'Rollback';Invoke-UID0002OZTc3RSharedOperation $Adapter $effects 'rollback' 'verifier'|Out-Null;Assert-UID0002OZTc3RFinalTuple $rollback.tuple $restored 'TC3R_ROLLBACK_FINAL_REHASH'|Out-Null}
    $failureStage='terminal';$stages.Add($failureStage);$terminal=Read-UID0002OZTc3RSharedObservation $Adapter 'Terminal';if($classifier.Identity-ceq'EXACT_P0'){Assert-UID0002OZTc3RFinalTuple $terminal.tuple $disk.p0 'TC3R_FINAL_P0_REHASH'|Out-Null}elseif($journal.RestoreConsumed){Assert-UID0002OZTc3RFinalTuple $terminal.tuple $restored 'TC3R_FINAL_RESTORED_REHASH'|Out-Null}else{Assert-UID0002OZTc3RFinalTuple $terminal.tuple $disk.candidate 'TC3R_FINAL_S1_REHASH'|Out-Null};Assert-UID0002OZTc3RSaveLedger $journal|Out-Null;Assert-UID0002OZTc3RLedgerParity $journal|Out-Null
  } catch {$primary=$_;$label=Get-UID0002OZTc3RSharedFailureLabel $_}
  finally {
    $stages.Add('cleanup');try{if($roleOpen){Invoke-UID0002OZTc3RSharedOperation $Adapter $effects 'cleanup' 'stop'|Out-Null;$roleOpen=$false};Invoke-UID0002OZTc3RSharedOperation $Adapter $effects 'cleanup' 'cleanup'|Out-Null}catch{$cleanupFailure=$_;if($null-eq$primary){$label=Get-UID0002OZTc3RSharedFailureLabel $_;$failureStage='cleanup'}}
    if($null-ne$journal){try{Complete-UID0002OZTc3RFailedLedger $journal $label;Assert-UID0002OZTc3RSaveLedger $journal|Out-Null;Assert-UID0002OZTc3RLedgerParity $journal|Out-Null;Close-UID0002OZTc3RJournal $journal;$journalProof=Read-UID0002OZTc3RD1Journal $journal.Path}catch{if($null-eq$primary-and$null-eq$cleanupFailure){$label=Get-UID0002OZTc3RSharedFailureLabel $_;$failureStage='cleanup'}}}
  }
  $body=[ordered]@{label=$label;boundary=$failureStage;effects=(Copy-UID0002OZTc3REffects $effects);physical=$Adapter.Physical;stage_trace=$stages.ToArray();read_trace=$Adapter.ReadCore.ToArray();operation_trace=$Adapter.OperationCore.ToArray();journal_chain=$(if($null-ne$journal){$journal.Chain}else{''});journal_records=$(if($null-ne$journalProof){$journalProof.Count}else{0});journal_reopened=($null-ne$journalProof);cleanup_failure=$(if($null-ne$cleanupFailure){Get-UID0002OZTc3RSharedFailureLabel $cleanupFailure}else{''})};New-UID0002OZTc3RSharedReceipt $body
}
function ConvertFrom-UID0002OZTc3RD1Utf8([byte[]]$Bytes){try{(New-Object Text.UTF8Encoding($false,$true)).GetString($Bytes)}catch{if($Bytes.Length-ge3-and$Bytes[0]-eq0xED-and$Bytes[1]-ge0xA0-and$Bytes[1]-le0xAF){Throw-UID0002OZTc3R 'TC3R_JSON_SURROGATE_PAIR'};if($Bytes.Length-ge3-and$Bytes[0]-eq0xED-and$Bytes[1]-ge0xB0-and$Bytes[1]-le0xBF){Throw-UID0002OZTc3R 'TC3R_JSON_ISOLATED_LOW_SURROGATE'};Throw-UID0002OZTc3R 'TC3R_JSON_UTF8'}}
function New-UID0002OZTc3RD1Journal([string]$RawToolsList,[string]$CanonicalPath,[string]$JournalPath){$canonical=[IO.Path]::GetFullPath($CanonicalPath);$path=[IO.Path]::GetFullPath($JournalPath);$stream=[IO.File]::Open($path,[IO.FileMode]::CreateNew,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None);$writer=New-Object IO.StreamWriter($stream,(New-Object Text.UTF8Encoding($false)),4096,$true);$writer.NewLine="`n";$j=[pscustomobject]@{Path=$path;CanonicalPath=$canonical;Stream=$stream;Writer=$writer;Sequence=[int64]0;Chain=('0'*64);Records=New-Object 'Collections.Generic.List[object]';Requests=New-Object 'Collections.Generic.Dictionary[string,object]' ([StringComparer]::Ordinal);SaveIssued=$false;SaveClass='NOT_ISSUED';RestoreConsumed=$false;Closed=$false};$contracts=New-UID0002OZTc3RContracts;Assert-UID0002OZTc3RContractSet $contracts|Out-Null;$env=ConvertFrom-UID0002OZTc3RJson $RawToolsList;$resolved=Assert-UID0002OZTc3RToolsList $env $contracts;$j|Add-Member -NotePropertyName Contracts -NotePropertyValue $contracts;$j|Add-Member -NotePropertyName ResolvedContracts -NotePropertyValue $resolved;$rows=New-Object 'Collections.Generic.List[object]';foreach($name in @($contracts.Keys|Sort-Object)){$live=$resolved[$name];$rows.Add([ordered]@{name=$live.Name;description=$live.PublicDescription;input_schema_sha=$live.InputSchemaSha256;contract_sha=$live.ContractSha256;discovered_tool_sha=$live.DiscoveredToolSha256})};Write-UID0002OZTc3RJournal $j 'CATALOG_COMMITTED' ([ordered]@{catalog=$rows.ToArray();catalog_sha=(Get-UID0002OZTc3RCanonicalSha $rows.ToArray());discovery_raw_sha=(Get-UID0002OZTc3RTextSha $RawToolsList)});$j}
function Read-UID0002OZTc3RD1Journal([string]$Path){$records=New-Object 'Collections.Generic.List[object]';$previous='0'*64;$sequence=[int64]0;foreach($line in [IO.File]::ReadAllLines([IO.Path]::GetFullPath($Path),(New-Object Text.UTF8Encoding($false,$true)))){$r=ConvertFrom-UID0002OZTc3RJson $line;Assert-UID0002OZTc3RKeys $r @('chain','kind','payload','previous','sequence') 'TC3R_D1_JOURNAL_ROW';$sequence++;if([int64]$r.sequence-ne$sequence-or$r.previous-cne$previous){Throw-UID0002OZTc3R 'TC3R_D1_JOURNAL_ORDER'};$body=[ordered]@{sequence=[int64]$r.sequence;kind=[string]$r.kind;payload=$r.payload;previous=[string]$r.previous};$chain=Get-UID0002OZTc3RTextSha ($previous+"`n"+(ConvertTo-UID0002OZTc3RCanonicalJson $body));if($r.chain-cne$chain){Throw-UID0002OZTc3R 'TC3R_D1_JOURNAL_CHAIN'};$previous=$chain;$records.Add($r)};if($records.Count-eq0-or@($records|Where-Object{$_.kind-ceq'JOURNAL_CLOSED'}).Count-ne1){Throw-UID0002OZTc3R 'TC3R_D1_JOURNAL_INCOMPLETE'};,$records.ToArray()}
function New-UID0002OZTc3RD1RawCase([string]$Name){$case=New-UID0002OZTc3RRawHostileCase $Name;$raw=$case.Raw;$text=[string]$raw.Parser.raw;if($Name-ceq'json-raw-high-truncated'){$bytes=[byte[]](0xED,0xA0,0x80)}elseif($Name-ceq'json-raw-low-isolated'){$bytes=[byte[]](0xED,0xB0,0x80)}else{$bytes=(New-Object Text.UTF8Encoding($false,$true)).GetBytes($text)};$raw.Parser.Remove('raw');$raw.Parser['bytes']=$bytes;$disposition=[string]$raw.Save.disposition;$raw.Save.Remove('disposition');$raw.Save['timed_out']=$disposition-ceq'timeout';$raw.Save['wire_bytes']=if($disposition-ceq'malformed'){[byte[]](0x7B)}else{(New-Object Text.UTF8Encoding($false,$true)).GetBytes((ConvertTo-UID0002OZTc3RCanonicalJson ([ordered]@{id=$raw.Save.response_id;jsonrpc='2.0';result=[ordered]@{content=@();isError=($disposition-cne'success');structuredContent=[ordered]@{error=$(if($disposition-ceq'success'){$null}else{'save failed'});ok=($disposition-ceq'success');path=$raw.Open.post.workers[0].session.canonical_path}}})))};$classifierObservation=[string]$raw.Disk.classifier_observation;$natural=if(Test-UID0002OZTc3RFullTuple $raw.Disk.candidate $raw.Disk.p0){'EXACT_P0'}else{'ATTEMPT_S1'};$raw.Disk.Remove('classifier_observation');if($classifierObservation-cne$natural){$raw.Disk['classifier_substitution']=$classifierObservation};$raw.Verifier.Remove('rbt_state');$permit=[string]$raw.Restore.permit_mac_mode;$used=[int]$raw.Restore.permit_use_count;$raw.Restore.Remove('required');$raw.Restore.Remove('permit_mac_mode');$raw.Restore.Remove('permit_use_count');if($permit-cne'valid'){$raw.Restore['permit_mac_bytes']=[byte[]](0)};if($used-ne0){$raw.Restore['permit_use_observation']=$used};[pscustomobject]@{Name=$case.Name;Defect=$case.Defect;MutationCount=$case.MutationCount;Raw=$raw}}
function Invoke-UID0002OZTc3RD1Save($Journal,$Raw,$Adapter,$Effects){$compat=[ordered]@{attempts=[int]$Raw.attempts;response_id=[string]$Raw.response_id;disposition='success'};if([bool]$Raw.timed_out){$compat.disposition='timeout'}else{try{$wire=ConvertFrom-UID0002OZTc3RD1Utf8 ([byte[]]$Raw.wire_bytes);$env=ConvertFrom-UID0002OZTc3RJson $wire;$compat.disposition=if([bool]$env.result.structuredContent.ok){'success'}else{'failure'}}catch{$compat.disposition='malformed'}};Invoke-UID0002OZTc3RSharedSave $Journal $compat $Adapter $Effects}
function Invoke-UID0002OZTc3RD1Classifier($Journal,$Raw,$Save,$ClosedRuntime,$Effects){$compat=[ordered]@{};foreach($k in $Raw.Keys){$compat[$k]=$Raw[$k]};$natural=if(Test-UID0002OZTc3RFullTuple $Raw.candidate $Raw.p0){'EXACT_P0'}else{'ATTEMPT_S1'};$compat['classifier_observation']=$natural;$r=Invoke-UID0002OZTc3RSharedClassifier $Journal $compat $Save $ClosedRuntime $Effects;if($Raw.Contains('classifier_substitution')){if($r.Identity-ceq'EXACT_P0'){Throw-UID0002OZTc3R 'TC3R_CLASSIFIER_EXACT_P0'}else{Throw-UID0002OZTc3R 'TC3R_CLASSIFIER_ATTEMPT_S1'}};$r}
function Invoke-UID0002OZTc3RD1Verifier($Raw,[string]$Identity,$Candidate,$Adapter,$Effects){$compat=[ordered]@{};foreach($k in $Raw.Keys){$compat[$k]=$Raw[$k]};$compat['rbt_state']=if($Identity-ceq'EXACT_P0'){'PRE'}else{'POST'};Assert-UID0002OZTc3RSharedVerifier $compat $Identity $Candidate $Adapter $Effects}
function Invoke-UID0002OZTc3RD1Restore($Journal,$Raw,$Disk,$Classifier,$Verifier,$Adapter,$Effects){$compat=[ordered]@{};foreach($k in $Raw.Keys){$compat[$k]=$Raw[$k]};$compat['permit_mac_mode']=if($Raw.Contains('permit_mac_bytes')){'forged'}else{'valid'};$compat['permit_use_count']=if($Raw.Contains('permit_use_observation')){[int]$Raw.permit_use_observation}else{0};Invoke-UID0002OZTc3RSharedRestore $Journal $compat $Disk $Classifier $Verifier $Adapter $Effects}
function Invoke-UID0002OZTc3RController {if($global:UID0002OZTc3RD1Mode-ceq'LIVE'){Invoke-UID0002OZTc3RPhysicalController;return};if($global:UID0002OZTc3RD1Mode-cne'FIXTURE'-or$null-eq$global:UID0002OZTc3RD1Raw-or[string]::IsNullOrWhiteSpace($global:UID0002OZTc3RD1JournalPath)){Throw-UID0002OZTc3R 'TC3R_D1_CONTEXT'};$adapter=New-UID0002OZTc3RRawFixtureAdapter $global:UID0002OZTc3RD1Raw;$adapter|Add-Member -NotePropertyName JournalPath -NotePropertyValue $global:UID0002OZTc3RD1JournalPath;Invoke-UID0002OZTc3RD1Core $adapter}
~~~
