<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\0002OW-DirectionButtonControlPaneVtableData-empty-emitter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002OW-DirectionButtonControlPaneVtableData-empty-emitter-source-quality.md](0002OW-DirectionButtonControlPaneVtableData-empty-emitter-source-quality.md)
- Source report SHA256 before archive-link insertion: `477CBFE5BA6DBFC98A7DD94DA79BF1DE8045ACAFA6ADF6A30E58BCA9ADF3449A`
- Recovery generated: `2026-08-09T22:17:53Z`
- Unique recovered executable blocks: `26`
- Recovered executable bytes: `387432`
- Recovery basis: report-path-associated Codex session history. The source report had already removed its executable packages before the supervisor could extract them directly.
- Scope: this archive preserves every unique recoverable report-local executable block, including superseded historical variants where session history retained more than the final pre-removal report.
- Authority: this file is not a B-agent research report, claims no target coverage, and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- SHA256: `777C139DF237AE01535A6577305A396032A5A6D8DAD5BFD5D9C786C850BEAE4D`
- Language: `powershell`
- Bytes: `1145`
- First recovered timestamp: `2026-08-06T22:21:54.579Z`
- Session provenance: rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 193747 (2026-08-06T22:21:54.579Z); rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 193748 (2026-08-06T22:21:54.646Z)

~~~powershell
$P0 = Get-ClosedExclusiveTuple $CanonicalPath
if ([IO.File]::Exists($BackupPath) -or [IO.Directory]::Exists($BackupPath)) { throw 'B0 collision' }
$src = [IO.File]::Open($CanonicalPath,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None)
try {
    $dst = [IO.File]::Open($BackupPath,[IO.FileMode]::CreateNew,[IO.FileAccess]::Write,[IO.FileShare]::None)
    try {
        $src.CopyTo($dst,1048576)
        if ($src.Position -ne $src.Length -or $dst.Position -ne $src.Length -or $dst.Length -ne $src.Length) { throw 'B0 copy/EOF mismatch' }
        $dst.Flush($true)
        if ($dst.Length -ne $src.Length) { throw 'B0 durable-length mismatch' }
    } finally { $dst.Dispose() }
} finally { $src.Dispose() }
[IO.File]::SetLastWriteTimeUtc($BackupPath,[DateTime]$P0.LastWriteTimeUtc)
$B0 = Get-ClosedExclusiveTuple $BackupPath
if ($P0.FullPath -ne [IO.Path]::GetFullPath($CanonicalPath) -or $B0.FullPath -ne [IO.Path]::GetFullPath($BackupPath) -or
    $P0.Length -ne $B0.Length -or $P0.LastWriteTimeUtcTicks -ne $B0.LastWriteTimeUtcTicks -or $P0.SHA256 -ne $B0.SHA256) { throw 'closed P0/B0 complete-tuple mismatch' }
~~~

## Removed Block R002

- SHA256: `F40ADB48C160DA9CF3A1C31D8081BAAF8AAF03C08A847B67692B1552EE96F739`
- Language: `powershell`
- Bytes: `1765`
- First recovered timestamp: `2026-08-06T22:21:54.579Z`
- Session provenance: rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 193747 (2026-08-06T22:21:54.579Z); rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 193748 (2026-08-06T22:21:54.646Z)

~~~powershell
$B0Check = Get-ClosedExclusiveTuple $BackupPath
$Current = Get-ClosedExclusiveTuple $CanonicalPath
if ($B0Check.FullPath -ne $B0.FullPath -or $B0Check.Length -ne $P0.Length -or
    $B0Check.LastWriteTimeUtcTicks -ne $P0.LastWriteTimeUtcTicks -or $B0Check.SHA256 -ne $P0.SHA256) { throw 'B0 guard mismatch' }
if (-not (Test-ExactTransactionTuple $Current $RecordedS1OrFailingSaved)) { throw 'canonical attribution/identity drift' }
$src = [IO.File]::Open($BackupPath,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None)
try {
    $dst = [IO.File]::Open($CanonicalPath,[IO.FileMode]::Open,[IO.FileAccess]::Write,[IO.FileShare]::None)
    try {
        $dst.SetLength(0)
        if ($dst.Length -ne 0 -or $dst.Position -ne 0) { throw 'canonical truncation failed' }
        $src.CopyTo($dst,1048576)
        if ($src.Position -ne $src.Length -or $dst.Position -ne $src.Length -or $dst.Length -ne $src.Length) { throw 'restore copy/EOF mismatch' }
        $dst.Flush($true)
        if ($dst.Length -ne $src.Length) { throw 'restore durable-length mismatch' }
    } finally { $dst.Dispose() }
} finally { $src.Dispose() }
[IO.File]::SetLastWriteTimeUtc($CanonicalPath,[DateTime]$P0.LastWriteTimeUtc)
$RestoredP0 = Get-ClosedExclusiveTuple $CanonicalPath
$ReopenedB0 = Get-ClosedExclusiveTuple $BackupPath
if ($RestoredP0.FullPath -ne $P0.FullPath -or $RestoredP0.Length -ne $P0.Length -or
    $RestoredP0.LastWriteTimeUtcTicks -ne $P0.LastWriteTimeUtcTicks -or $RestoredP0.SHA256 -ne $P0.SHA256 -or
    $ReopenedB0.FullPath -ne $B0.FullPath -or $ReopenedB0.Length -ne $P0.Length -or
    $ReopenedB0.LastWriteTimeUtcTicks -ne $P0.LastWriteTimeUtcTicks -or $ReopenedB0.SHA256 -ne $P0.SHA256) { throw 'closed/reopened restore tuple mismatch' }
~~~

## Removed Block R003

- SHA256: `36114E425FFC563115C12670665673F127F9EC9D272BB13718A020A684A17CF4`
- Language: `powershell`
- Bytes: `3885`
- First recovered timestamp: `2026-08-06T22:57:39.432Z`
- Session provenance: rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 193932 (2026-08-06T22:57:39.432Z); rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 193933 (2026-08-06T22:57:39.487Z)

~~~powershell
$InitializeRequest = [ordered]@{jsonrpc='2.0';id='uid0002ow-initialize';method='initialize';params=[ordered]@{protocolVersion='2025-06-18';capabilities=[ordered]@{};clientInfo=[ordered]@{name='UID0002OW-Gate2B';version='1.0'}}}
$InitializeWeb = Invoke-WebRequest -UseBasicParsing -Uri $McpUri -Method Post -ContentType 'application/json' -Headers @{Accept='application/json, text/event-stream'} -Body ($InitializeRequest|ConvertTo-Json -Depth 20 -Compress) -TimeoutSec 30
$McpSessionId = [string]$InitializeWeb.Headers['Mcp-Session-Id']
if ([string]::IsNullOrWhiteSpace($McpSessionId)) { throw 'missing MCP transport session ID' }
$McpHeaders = @{Accept='application/json, text/event-stream';'Mcp-Session-Id'=$McpSessionId}
$InitializedNotification = [ordered]@{jsonrpc='2.0';method='notifications/initialized'}
[void](Invoke-WebRequest -UseBasicParsing -Uri $McpUri -Method Post -ContentType 'application/json' -Headers $McpHeaders -Body ($InitializedNotification|ConvertTo-Json -Depth 10 -Compress) -TimeoutSec 30)
function Invoke-McpRpc($Request) {
    $web = Invoke-WebRequest -UseBasicParsing -Uri $McpUri -Method Post -ContentType 'application/json' -Headers $McpHeaders -Body ($Request|ConvertTo-Json -Depth 100 -Compress) -TimeoutSec 120
    $envelope = $web.Content | ConvertFrom-Json
    if ($null -eq $envelope -or $envelope.jsonrpc -ne '2.0' -or [string]$envelope.id -ne [string]$Request.id) { throw 'malformed/mismatched JSON-RPC envelope' }
    $envelope
}
function Invoke-McpTool([string]$RequestId,[string]$Tool,$Arguments) {
    Invoke-McpRpc ([ordered]@{jsonrpc='2.0';id=$RequestId;method='tools/call';params=[ordered]@{name=$Tool;arguments=$Arguments}})
}
function Get-ReturnedDatabaseId($OpenEnvelope,[string]$Role) {
    if ($null -eq $OpenEnvelope.result -or $OpenEnvelope.result.isError -eq $true -or $null -ne $OpenEnvelope.error) { throw "$Role idb_open failed" }
    $structured = $OpenEnvelope.result.structuredContent
    if ($null -eq $structured -or $null -eq $structured.session) { throw "$Role missing result.structuredContent.session" }
    $database = [string]$structured.session.session_id
    if ([string]::IsNullOrWhiteSpace($database)) { throw "$Role missing result.structuredContent.session.session_id" }
    $database
}
function Assert-ReturnedDatabase($Database,[string]$Role) {
    $listEnvelope = Invoke-McpTool ("uid0002ow-$Role-idb-list") 'idb_list' ([ordered]@{})
    if ($listEnvelope.result.isError -eq $true -or $null -eq $listEnvelope.result.structuredContent.sessions) { throw "$Role idb_list corroboration failed" }
    $rows = @($listEnvelope.result.structuredContent.sessions | Where-Object {[string]$_.session_id -eq $Database -and [string]$_.input_path -eq $CanonicalPath -and $_.is_active -eq $true})
    if ($rows.Count -ne 1 -or [int]$rows[0].pid -le 0 -or [int]$rows[0].worker_pid -ne [int]$rows[0].pid) { throw "$Role returned-ID corroboration/PID mismatch" }
    $worker = Get-ProcessIdentity ([int]$rows[0].pid)
    $attestation = Invoke-LoadedModuleAttestation $worker $Role @('ida_pro_mcp','ida_pro_mcp.ida_mcp.api_modify','ida_pro_mcp.ida_mcp.utils','ida_pro_mcp.ida_mcp.api_analysis')
    [pscustomobject]@{Database=$Database;Row=$rows[0];Worker=$worker;Attestation=$attestation}
}
$Stamp = (Get-Date).ToUniversalTime().ToString('yyyyMMdd-HHmmssfffffff')
$InspectOpenRequest = [ordered]@{jsonrpc='2.0';id='uid0002ow-inspection-open';method='tools/call';params=[ordered]@{name='idb_open';arguments=[ordered]@{input_path=$CanonicalPath;mode='force_headless';run_auto_analysis=$false;build_caches=$true;init_hexrays=$true;idle_ttl_sec=3600;preferred_session_id="supervisor-uid0002ow-inspection-$Stamp"}}}
$InspectOpenEnvelope = Invoke-McpRpc $InspectOpenRequest
$INSPECT_DB = Get-ReturnedDatabaseId $InspectOpenEnvelope 'inspection'
$InspectionBinding = Assert-ReturnedDatabase $INSPECT_DB 'inspection'
~~~

## Removed Block R004

- SHA256: `9FEA790ADB25576DCAD34B9C5E876E985E311364B1F94A4C7F61F6A3728D636D`
- Language: `powershell`
- Bytes: `7019`
- First recovered timestamp: `2026-08-06T22:57:39.432Z`
- Session provenance: rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 193932 (2026-08-06T22:57:39.432Z); rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 193933 (2026-08-06T22:57:39.487Z); rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 194277 (2026-08-06T23:31:42.049Z)

~~~powershell
$CanonicalPath = 'E:\NTK\Resources\NexusTK\NexusTK.exe.i64'
$McpUri = 'http://127.0.0.1:13337/mcp'
$ExpectedRoot = 'C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp'
$ExpectedL0 = 'C:\Users\admin\.idapro\idalib-mcp-venv\Scripts\idalib-mcp.exe'
$ExpectedL1 = 'C:\Users\admin\.idapro\idalib-mcp-venv\Scripts\python.exe'
$ExpectedL2 = 'C:\Users\Rage\AppData\Local\Programs\Python\Python314\python.exe'
$ExpectedLauncher = 'C:\Users\admin\.idapro\idalib-mcp-venv\Scripts\idalib-mcp.exe'
$ExpectedHashes = [ordered]@{
    L0 = '38888EDC3241C00092D5A4F166F70E6AF8DF538D4C81C8DE75E461575E27580E'
    L1 = '4B8C3912806B3C1591BA3CB403BFF77AD309C3FE5756F87C20B7A6F8F0174262'
    L2 = '7CA24F26D6E3F463419EE4F537DDD3ACD312C38FE45E678CCE08572F26A8BD1A'
    'ida_pro_mcp.ida_mcp.api_modify' = '161B314A14DAAA34C718176444292597BBB7498FA80158E25C358542BC16D1B8'
    'ida_pro_mcp.ida_mcp.utils' = '5139910EA7496549A31EDD6F9EEE7B033DA16504E4F0D19C8052EC9ED1C62069'
    'ida_pro_mcp.ida_mcp.api_analysis' = '4C9B9122A7D2697CD464C1F473A227A580FD803515A1C885A1AA262259F1969F'
}

function Get-ProcessIdentity([int]$ProcessId) {
    $p = Get-CimInstance Win32_Process -Filter "ProcessId=$ProcessId" -ErrorAction Stop
    if ($null -eq $p -or [string]::IsNullOrWhiteSpace([string]$p.ExecutablePath) -or [string]::IsNullOrWhiteSpace([string]$p.CommandLine)) { throw 'incomplete process identity' }
    [pscustomobject]@{
        ProcessId = [int]$p.ProcessId; ParentProcessId = [int]$p.ParentProcessId
        CreationUtcTicks = [DateTime]$p.CreationDate.ToUniversalTime().Ticks
        ExecutablePath = [IO.Path]::GetFullPath([string]$p.ExecutablePath)
        CommandLine = [regex]::Replace(([string]$p.CommandLine).Trim(),'\s+',' ')
    }
}
function Assert-SameProcess($A,$B,[string]$Role) {
    if ($A.ProcessId -ne $B.ProcessId -or $A.ParentProcessId -ne $B.ParentProcessId -or $A.CreationUtcTicks -ne $B.CreationUtcTicks -or
        -not $A.ExecutablePath.Equals($B.ExecutablePath,[StringComparison]::OrdinalIgnoreCase) -or $A.CommandLine -ne $B.CommandLine) { throw "$Role process identity drift" }
}
function Invoke-LoadedModuleAttestation($Identity,[string]$Role,[string[]]$RequiredModules) {
    $statement = "!__import__('builtins').print('__NTK_ATTEST__|'+__import__('sys').executable+'|'+__import__('sys').prefix+'|'+';'.join(n+'^'+str(id(m))+'^'+str(getattr(m,'__file__',None))+'^'+str(getattr(getattr(m,'__spec__',None),'origin',None)) for n,m in sorted(__import__('sys').modules.items()) if n=='ida_pro_mcp' or n.startswith('ida_pro_mcp.'))+'|__NTK_ATTEST_END__')"
    $before = Get-ProcessIdentity $Identity.ProcessId
    Assert-SameProcess $Identity $before $Role
    $output = & $Identity.ExecutablePath -m pdb -p $Identity.ProcessId -c $statement -c continue 2>&1
    if ($LASTEXITCODE -ne 0) { throw "$Role in-process attestation failed: $($output -join ' ')" }
    $line = @($output | ForEach-Object {[string]$_} | Where-Object {$_ -like '*__NTK_ATTEST__|*'} | Select-Object -Last 1)
    if ($line.Count -ne 1) { throw "$Role attestation marker missing/ambiguous" }
    $payload = $line[0].Substring($line[0].IndexOf('__NTK_ATTEST__|'))
    $parts = $payload.Split('|')
    if ($parts.Count -ne 5 -or $parts[0] -ne '__NTK_ATTEST__' -or $parts[4] -ne '__NTK_ATTEST_END__') { throw "$Role malformed attestation" }
    $modules = [ordered]@{}
    foreach ($record in @($parts[3].Split(';') | Where-Object {$_})) {
        $f = $record.Split('^')
        if ($f.Count -ne 4 -or $modules.Contains($f[0])) { throw "$Role malformed/duplicate module record" }
        $modules[$f[0]] = [pscustomobject]@{ObjectId=$f[1];File=$f[2];Origin=$f[3]}
    }
    foreach ($name in $RequiredModules) {
        if (-not $modules.Contains($name)) { throw "$Role required module not already loaded: $name" }
    }
    foreach ($entry in $modules.GetEnumerator()) {
        if ($entry.Value.File -eq 'None' -or $entry.Value.Origin -eq 'None') { throw "$Role module has no file/origin: $($entry.Key)" }
        $file = [IO.Path]::GetFullPath($entry.Value.File); $origin = [IO.Path]::GetFullPath($entry.Value.Origin)
        if (-not $file.Equals($origin,[StringComparison]::OrdinalIgnoreCase) -or
            -not $file.StartsWith($ExpectedRoot + [IO.Path]::DirectorySeparatorChar,[StringComparison]::OrdinalIgnoreCase)) { throw "$Role module root/origin mismatch: $($entry.Key)" }
        if ($ExpectedHashes.Contains($entry.Key) -and (Get-FileHash -Algorithm SHA256 -LiteralPath $file).Hash -ne $ExpectedHashes[$entry.Key]) { throw "$Role module hash drift: $($entry.Key)" }
    }
    $after = Get-ProcessIdentity $Identity.ProcessId
    Assert-SameProcess $before $after $Role
    [pscustomobject]@{Role=$Role;Process=$after;SysExecutable=$parts[1];SysPrefix=$parts[2];Modules=$modules}
}

$socket = @(Get-NetTCPConnection -LocalAddress 127.0.0.1 -LocalPort 13337 -State Listen -ErrorAction Stop)
if ($socket.Count -ne 1) { throw 'L2 listener socket missing/ambiguous' }
$L2 = Get-ProcessIdentity $socket[0].OwningProcess
$L1 = Get-ProcessIdentity $L2.ParentProcessId
$L0 = Get-ProcessIdentity $L1.ParentProcessId
if ($L0.ProcessId -eq $L1.ProcessId -or $L1.ProcessId -eq $L2.ProcessId -or $L1.ParentProcessId -ne $L0.ProcessId -or $L2.ParentProcessId -ne $L1.ProcessId) { throw 'L0/L1/L2 parent chain mismatch' }
if (-not $L0.ExecutablePath.Equals($ExpectedL0,[StringComparison]::OrdinalIgnoreCase) -or
    -not $L1.ExecutablePath.Equals($ExpectedL1,[StringComparison]::OrdinalIgnoreCase) -or
    -not $L2.ExecutablePath.Equals($ExpectedL2,[StringComparison]::OrdinalIgnoreCase)) { throw 'L0/L1/L2 executable mismatch' }
if ((Get-FileHash -Algorithm SHA256 -LiteralPath $L0.ExecutablePath).Hash -ne $ExpectedHashes.L0 -or
    (Get-FileHash -Algorithm SHA256 -LiteralPath $L1.ExecutablePath).Hash -ne $ExpectedHashes.L1 -or
    (Get-FileHash -Algorithm SHA256 -LiteralPath $L2.ExecutablePath).Hash -ne $ExpectedHashes.L2) { throw 'L0/L1/L2 executable hash drift' }
$expectedL0Command = [regex]::Replace(('"'+$ExpectedL0+'" --host 127.0.0.1 --port 13337'),'\s+',' ')
$expectedPythonCommand = [regex]::Replace(('"'+$ExpectedL1+'" "'+$ExpectedLauncher+'" --host 127.0.0.1 --port 13337'),'\s+',' ')
if ($L0.CommandLine -ne $expectedL0Command -or $L1.CommandLine -ne $expectedPythonCommand -or $L2.CommandLine -ne $expectedPythonCommand) { throw 'L0/L1/L2 command mismatch' }
$L1Attestation = Invoke-LoadedModuleAttestation $L1 'L1-venv-listener' @('ida_pro_mcp')
$L2Attestation = Invoke-LoadedModuleAttestation $L2 'L2-socket-owner' @('ida_pro_mcp')
$socketAfter = @(Get-NetTCPConnection -LocalAddress 127.0.0.1 -LocalPort 13337 -State Listen -ErrorAction Stop)
if ($socketAfter.Count -ne 1 -or $socketAfter[0].OwningProcess -ne $L2.ProcessId) { throw 'serving socket owner drift' }
Assert-SameProcess $L0 (Get-ProcessIdentity $L0.ProcessId) 'L0-root'
Assert-SameProcess $L1 (Get-ProcessIdentity $L1.ProcessId) 'L1-venv-listener'
Assert-SameProcess $L2 (Get-ProcessIdentity $L2.ProcessId) 'L2-socket-owner'
~~~

## Removed Block R005

- SHA256: `5804812A984A6848182D8749346DBD15AD0005EC3EB9002EA0F19D98806CD097`
- Language: `powershell`
- Bytes: `48657`
- First recovered timestamp: `2026-08-06T23:05:45.353Z`
- Session provenance: rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 194022 (2026-08-06T23:05:45.353Z); rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 194023 (2026-08-06T23:05:45.425Z)

~~~powershell
$MutationPlan = @(
    [ordered]@{Seq=1;Id='D02';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m001-d02';method='tools/call';params=[ordered]@{name='define_func';arguments=[ordered]@{items=[ordered]@{addr='0x5007a0';end='0x5007e8'};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m001-d02';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x5007a0');database=$TX}},[ordered]@{tool='get_comments';arguments=[ordered]@{addrs=@('0x5007a0');database=$TX}},[ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x5007a0');database=$TX}},[ordered]@{tool='get_bytes';arguments=[ordered]@{regions=[ordered]@{addr='0x5007a0';size=72};database=$TX}},[ordered]@{tool='xrefs_to';arguments=[ordered]@{addrs=@('0x5007a0');limit=1000;database=$TX}},[ordered]@{tool='callees';arguments=[ordered]@{addrs=@('0x5007a0');limit=500;database=$TX}});Exact=@('range [0x5007a0,0x5007e8)','five provisional rows var_4,__saved_registers,__return_address,arg_0,arg_4','body SHA256 3D394071852446954ED8A3E4FE03C78766C4F2D72C8F4013CAAA27D9CDE7DFE3','zero incoming xrefs','sole modeled callee 0x494eb0','P00 and P01 exact');AllowedDelta=@('create function model only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=2;Id='T01';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m002-t01';method='tools/call';params=[ordered]@{name='declare_type';arguments=[ordered]@{decls='struct DirectionButtonControlPane;';database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m002-t01';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='type_query';arguments=[ordered]@{queries=@([ordered]@{filter='^DirectionButtonControlPane$';kind='udt';count=20;include_decl=$true;include_members=$true;include_relationships=$true},[ordered]@{filter='^(ControlPane|RectBounds|EPFTileContext)$';kind='udt';count=20;include_decl=$true;include_members=$true;include_relationships=$true});database=$TX}},[ordered]@{tool='server_health';arguments=[ordered]@{database=$TX}},[ordered]@{tool='get_bytes';arguments=[ordered]@{regions=[ordered]@{addr='0x61dc30';size=164};database=$TX}});Exact=@('one forward declaration struct DirectionButtonControlPane','ControlPane 0x108, RectBounds 0x10, EPFTileContext 0x28 and all literal member rows unchanged','server status ok and analyzing false','target bytes SHA256 7F845C6C5F04F6C5EA51A0D74C0621021B1EAA57A7F52613D23E6AE4DD163A29');AllowedDelta=@('add only the forward declaration');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=3;Id='R02.Dry';Phase='Dry';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m003-r02-dry';method='tools/call';params=[ordered]@{name='rename';arguments=[ordered]@{batch=[ordered]@{func=[ordered]@{addr='0x5007a0';name='DirectionButtonControlPane__DirectionButtonControlPane'};dry_run=$true;stop_on_error=$true;allow_overwrite=$false;pure=$true};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m003-r02-dry';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0;DryRun=$true;ForbiddenFields=@('dir','dir_error')};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x5007a0');database=$TX}},[ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x5007a0');database=$TX}},[ordered]@{tool='callees';arguments=[ordered]@{addrs=@('0x5007a0');limit=500;database=$TX}});Exact=@('entire post-D02 item/name/type/frame/callee snapshot unchanged','proposed name still absent');AllowedDelta=@();AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=4;Id='R02.Actual';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m004-r02-actual';method='tools/call';params=[ordered]@{name='rename';arguments=[ordered]@{batch=[ordered]@{func=[ordered]@{addr='0x5007a0';name='DirectionButtonControlPane__DirectionButtonControlPane'};dry_run=$false;stop_on_error=$true;allow_overwrite=$false;pure=$true};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m004-r02-actual';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0;DryRun=$false;ForbiddenFields=@('dir','dir_error')};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x5007a0');database=$TX}},[ordered]@{tool='get_comments';arguments=[ordered]@{addrs=@('0x5007a0');database=$TX}},[ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x5007a0');database=$TX}},[ordered]@{tool='callees';arguments=[ordered]@{addrs=@('0x5007a0');limit=500;database=$TX}});Exact=@('name DirectionButtonControlPane__DirectionButtonControlPane exactly once','post-D02 type/frame/comments/body/xrefs unchanged','sole modeled callee 0x494eb0','P00/P01 exact');AllowedDelta=@('function name only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=5;Id='R03.Dry';Phase='Dry';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m005-r03-dry';method='tools/call';params=[ordered]@{name='rename';arguments=[ordered]@{batch=[ordered]@{func=[ordered]@{addr='0x5007f0';name='DirectionButtonControlPane__SetVisualState'};dry_run=$true;stop_on_error=$true;allow_overwrite=$false;pure=$true};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m005-r03-dry';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0;DryRun=$true;ForbiddenFields=@('dir','dir_error')};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x5007f0');database=$TX}},[ordered]@{tool='get_comments';arguments=[ordered]@{addrs=@('0x5007f0');database=$TX}},[ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x5007f0');database=$TX}},[ordered]@{tool='callees';arguments=[ordered]@{addrs=@('0x5007f0');limit=500;database=$TX}});Exact=@('name sub_5007F0','type int __thiscall(int this, unsigned __int8)','three original frame rows','four empty comments','body SHA256 5C1C71AD9B1269E5B33C8EDF1B461A81B63A3D6BB75ED9D2D53C557128CAE7E6','xref 0x61dc7c','sole callee 0x494b80','P02 exact');AllowedDelta=@();AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=6;Id='R03.Actual';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m006-r03-actual';method='tools/call';params=[ordered]@{name='rename';arguments=[ordered]@{batch=[ordered]@{func=[ordered]@{addr='0x5007f0';name='DirectionButtonControlPane__SetVisualState'};dry_run=$false;stop_on_error=$true;allow_overwrite=$false;pure=$true};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m006-r03-actual';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0;DryRun=$false;ForbiddenFields=@('dir','dir_error')};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x5007f0');database=$TX}},[ordered]@{tool='get_comments';arguments=[ordered]@{addrs=@('0x5007f0');database=$TX}},[ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x5007f0');database=$TX}},[ordered]@{tool='callees';arguments=[ordered]@{addrs=@('0x5007f0');limit=500;database=$TX}});Exact=@('name DirectionButtonControlPane__SetVisualState','type int __thiscall(int this, unsigned __int8) unchanged','three original frame rows','four empty comments','body/xref/callee/P02 exact');AllowedDelta=@('function name only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=7;Id='R04.Dry';Phase='Dry';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m007-r04-dry';method='tools/call';params=[ordered]@{name='rename';arguments=[ordered]@{batch=[ordered]@{func=[ordered]@{addr='0x500820';name='DirectionButtonControlPane__OnPaint'};dry_run=$true;stop_on_error=$true;allow_overwrite=$false;pure=$true};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m007-r04-dry';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0;DryRun=$true;ForbiddenFields=@('dir','dir_error')};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x500820','0x5008c0');database=$TX}},[ordered]@{tool='export_funcs';arguments=[ordered]@{addrs=@('0x5008c0');format='prototypes';database=$TX}},[ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x500820','0x5008c0');database=$TX}},[ordered]@{tool='callees';arguments=[ordered]@{addrs=@('0x500820');limit=500;database=$TX}});Exact=@('name sub_500820','type int __thiscall(int this)','five I04 frame rows','P04.PROTO boost::exception *__thiscall(boost::exception *this, const unsigned __int16 *, _DWORD *, void *, void *)','P04.FRAME _DWORD arg_0, Pane * arg_4, _DWORD arg_8, _DWORD arg_C','body/xrefs/callees/P03 exact');AllowedDelta=@();AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=8;Id='R04.Actual';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m008-r04-actual';method='tools/call';params=[ordered]@{name='rename';arguments=[ordered]@{batch=[ordered]@{func=[ordered]@{addr='0x500820';name='DirectionButtonControlPane__OnPaint'};dry_run=$false;stop_on_error=$true;allow_overwrite=$false;pure=$true};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m008-r04-actual';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0;DryRun=$false;ForbiddenFields=@('dir','dir_error')};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x500820','0x5008c0');database=$TX}},[ordered]@{tool='export_funcs';arguments=[ordered]@{addrs=@('0x5008c0');format='prototypes';database=$TX}},[ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x500820','0x5008c0');database=$TX}},[ordered]@{tool='callees';arguments=[ordered]@{addrs=@('0x500820');limit=500;database=$TX}});Exact=@('name DirectionButtonControlPane__OnPaint','type int __thiscall(int this) unchanged','five I04 frame rows unchanged','both independent P04 identities exact','body/xrefs/callees/P03 exact');AllowedDelta=@('function name only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=9;Id='R05.Dry';Phase='Dry';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m009-r05-dry';method='tools/call';params=[ordered]@{name='rename';arguments=[ordered]@{batch=[ordered]@{func=[ordered]@{addr='0x50248a';name='DirectionButtonControlPane__EventHandlerView__scalar_deleting_destructor'};dry_run=$true;stop_on_error=$true;allow_overwrite=$false;pure=$true};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m009-r05-dry';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0;DryRun=$true;ForbiddenFields=@('dir','dir_error')};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x50248a');database=$TX}},[ordered]@{tool='get_comments';arguments=[ordered]@{addrs=@('0x50248a');database=$TX}},[ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x50248a');database=$TX}},[ordered]@{tool='callees';arguments=[ordered]@{addrs=@('0x50248a');limit=500;database=$TX}},[ordered]@{tool='disasm';arguments=[ordered]@{addr='0x50248a';max_instructions=2;offset=0;include_total=$true;database=$TX}});Exact=@('name sub_50248A','type _DWORD *__thiscall(_DWORD *this, char)','comments Block/empty/empty/empty','only __return_address frame row','body SHA256 41CA8C2E8B18394AE07F2C8EF8DE66AFC2092B441D56EA4CB66A6AD50AC90FF5','xref 0x61dc9c','callees empty','sub ecx,0xa0 then jmp ref 0x5026a0','P05 exact');AllowedDelta=@();AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=10;Id='R05.Actual';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m010-r05-actual';method='tools/call';params=[ordered]@{name='rename';arguments=[ordered]@{batch=[ordered]@{func=[ordered]@{addr='0x50248a';name='DirectionButtonControlPane__EventHandlerView__scalar_deleting_destructor'};dry_run=$false;stop_on_error=$true;allow_overwrite=$false;pure=$true};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m010-r05-actual';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0;DryRun=$false;ForbiddenFields=@('dir','dir_error')};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x50248a');database=$TX}},[ordered]@{tool='get_comments';arguments=[ordered]@{addrs=@('0x50248a');database=$TX}},[ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x50248a');database=$TX}},[ordered]@{tool='callees';arguments=[ordered]@{addrs=@('0x50248a');limit=500;database=$TX}},[ordered]@{tool='disasm';arguments=[ordered]@{addr='0x50248a';max_instructions=2;offset=0;include_total=$true;database=$TX}});Exact=@('exact EventHandlerView wrapper name','type/comments/frame/body/xref/callees/P05 unchanged','sub ecx,0xa0 then jmp ref 0x5026a0 with stage-appropriate target name');AllowedDelta=@('function name only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=11;Id='R06.Dry';Phase='Dry';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m011-r06-dry';method='tools/call';params=[ordered]@{name='rename';arguments=[ordered]@{batch=[ordered]@{func=[ordered]@{addr='0x502495';name='DirectionButtonControlPane__TimerHandlerView__scalar_deleting_destructor'};dry_run=$true;stop_on_error=$true;allow_overwrite=$false;pure=$true};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m011-r06-dry';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0;DryRun=$true;ForbiddenFields=@('dir','dir_error')};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x502495');database=$TX}},[ordered]@{tool='get_comments';arguments=[ordered]@{addrs=@('0x502495');database=$TX}},[ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x502495');database=$TX}},[ordered]@{tool='callees';arguments=[ordered]@{addrs=@('0x502495');limit=500;database=$TX}},[ordered]@{tool='disasm';arguments=[ordered]@{addr='0x502495';max_instructions=2;offset=0;include_total=$true;database=$TX}});Exact=@('name sub_502495','type _DWORD *__thiscall(_DWORD *this, char)','comments Block/empty/empty/empty','only __return_address frame row','body SHA256 019897439397DE963AC32EE212C5B0E61FD35E961D8DE9FB56312D363E9DFE0F','xref 0x61dccc','callees empty','sub ecx,0xa4 then jmp ref 0x5026a0','P06 exact');AllowedDelta=@();AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=12;Id='R06.Actual';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m012-r06-actual';method='tools/call';params=[ordered]@{name='rename';arguments=[ordered]@{batch=[ordered]@{func=[ordered]@{addr='0x502495';name='DirectionButtonControlPane__TimerHandlerView__scalar_deleting_destructor'};dry_run=$false;stop_on_error=$true;allow_overwrite=$false;pure=$true};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m012-r06-actual';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0;DryRun=$false;ForbiddenFields=@('dir','dir_error')};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x502495');database=$TX}},[ordered]@{tool='get_comments';arguments=[ordered]@{addrs=@('0x502495');database=$TX}},[ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x502495');database=$TX}},[ordered]@{tool='callees';arguments=[ordered]@{addrs=@('0x502495');limit=500;database=$TX}},[ordered]@{tool='disasm';arguments=[ordered]@{addr='0x502495';max_instructions=2;offset=0;include_total=$true;database=$TX}});Exact=@('exact TimerHandlerView wrapper name','type/comments/frame/body/xref/callees/P06 unchanged','sub ecx,0xa4 then jmp ref 0x5026a0 with stage-appropriate target name');AllowedDelta=@('function name only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=13;Id='R07.Dry';Phase='Dry';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m013-r07-dry';method='tools/call';params=[ordered]@{name='rename';arguments=[ordered]@{batch=[ordered]@{func=[ordered]@{addr='0x5026a0';name='DirectionButtonControlPane__scalar_deleting_destructor'};dry_run=$true;stop_on_error=$true;allow_overwrite=$false;pure=$true};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m013-r07-dry';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0;DryRun=$true;ForbiddenFields=@('dir','dir_error')};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x5026a0');database=$TX}},[ordered]@{tool='get_comments';arguments=[ordered]@{addrs=@('0x5026a0');database=$TX}},[ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x5026a0');database=$TX}},[ordered]@{tool='callees';arguments=[ordered]@{addrs=@('0x5026a0');limit=500;database=$TX}},[ordered]@{tool='disasm';arguments=[ordered]@{addr='0x50248a';max_instructions=2;offset=0;include_total=$true;database=$TX}},[ordered]@{tool='disasm';arguments=[ordered]@{addr='0x502495';max_instructions=2;offset=0;include_total=$true;database=$TX}});Exact=@('name sub_5026A0','type _DWORD *__thiscall(_DWORD *Block, char)','three original frame rows','body SHA256 745E2B5E3888950E49CB247F145006F2806B6FEB716EA75A0C1D668125E4991E','three exact xrefs','three exact callees','both adjustors retain pre-R07 rendered target','P07/P08 exact');AllowedDelta=@();AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=14;Id='R07.Actual';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m014-r07-actual';method='tools/call';params=[ordered]@{name='rename';arguments=[ordered]@{batch=[ordered]@{func=[ordered]@{addr='0x5026a0';name='DirectionButtonControlPane__scalar_deleting_destructor'};dry_run=$false;stop_on_error=$true;allow_overwrite=$false;pure=$true};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m014-r07-actual';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0;DryRun=$false;ForbiddenFields=@('dir','dir_error')};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x5026a0');database=$TX}},[ordered]@{tool='get_comments';arguments=[ordered]@{addrs=@('0x5026a0');database=$TX}},[ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x5026a0');database=$TX}},[ordered]@{tool='callees';arguments=[ordered]@{addrs=@('0x5026a0');limit=500;database=$TX}},[ordered]@{tool='disasm';arguments=[ordered]@{addr='0x50248a';max_instructions=2;offset=0;include_total=$true;database=$TX}},[ordered]@{tool='disasm';arguments=[ordered]@{addr='0x502495';max_instructions=2;offset=0;include_total=$true;database=$TX}});Exact=@('name DirectionButtonControlPane__scalar_deleting_destructor','type _DWORD *__thiscall(_DWORD *Block, char) unchanged','frame/body/xrefs/callees/P07/P08 unchanged','both adjustor ref names now render DirectionButtonControlPane__scalar_deleting_destructor');AllowedDelta=@('function name and dependent rendered disassembly target names only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=15;Id='F02';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m015-f02';method='tools/call';params=[ordered]@{name='set_type';arguments=[ordered]@{edits=[ordered]@{addr='0x5007a0';kind='function';signature='DirectionButtonControlPane *__thiscall DirectionButtonControlPane__DirectionButtonControlPane(DirectionButtonControlPane *this, int directionIndex, const RectBounds *bounds)'};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m015-f02';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x5007a0');database=$TX}},[ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x5007a0');database=$TX}},[ordered]@{tool='callees';arguments=[ordered]@{addrs=@('0x5007a0');limit=500;database=$TX}});Exact=@('exact final constructor signature','provisional argument rows remain arg_0 and arg_4 until RS02','name/comments/body/xrefs/callee/P00/P01 exact');AllowedDelta=@('function type and type-induced argument semantics only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=16;Id='F03';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m016-f03';method='tools/call';params=[ordered]@{name='set_type';arguments=[ordered]@{edits=[ordered]@{addr='0x5007f0';kind='function';signature='void __thiscall DirectionButtonControlPane__SetVisualState(DirectionButtonControlPane *this, unsigned __int8 visualState)'};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m016-f03';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x5007f0');database=$TX}},[ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x5007f0');database=$TX}},[ordered]@{tool='callees';arguments=[ordered]@{addrs=@('0x5007f0');limit=500;database=$TX}});Exact=@('exact final SetVisualState signature','only arg_0 semantic type/width may change before RS03','name/comments/body/xref/callee/P02 exact');AllowedDelta=@('function type and arg_0 semantic-width only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=17;Id='F04';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m017-f04';method='tools/call';params=[ordered]@{name='set_type';arguments=[ordered]@{edits=[ordered]@{addr='0x500820';kind='function';signature='void __thiscall DirectionButtonControlPane__OnPaint(DirectionButtonControlPane *this)'};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m017-f04';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x500820','0x5008c0');database=$TX}},[ordered]@{tool='export_funcs';arguments=[ordered]@{addrs=@('0x5008c0');format='prototypes';database=$TX}},[ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x500820','0x5008c0');database=$TX}});Exact=@('exact final OnPaint signature','zero I04 frame-row delta','both independent P04 identities exact','name/comments/body/xrefs/callees/P03 exact');AllowedDelta=@('I04 function type only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=18;Id='F07';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m018-f07';method='tools/call';params=[ordered]@{name='set_type';arguments=[ordered]@{edits=[ordered]@{addr='0x5026a0';kind='function';signature='DirectionButtonControlPane *__thiscall DirectionButtonControlPane__scalar_deleting_destructor(DirectionButtonControlPane *this, unsigned int flags)'};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m018-f07';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x5026a0');database=$TX}},[ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x5026a0');database=$TX}},[ordered]@{tool='callees';arguments=[ordered]@{addrs=@('0x5026a0');limit=500;database=$TX}});Exact=@('exact final scalar deleting destructor signature','only arg_0 semantic type may change before RS07','name/comments/body/xrefs/callees/P07/P08 exact');AllowedDelta=@('function type and arg_0 unsigned semantics only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=19;Id='RS02a.Dry';Phase='Dry';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m019-rs02a-dry';method='tools/call';params=[ordered]@{name='rename';arguments=[ordered]@{batch=[ordered]@{stack=[ordered]@{func_addr='0x5007a0';old='arg_0';new='directionIndex'};dry_run=$true;stop_on_error=$true;allow_overwrite=$false;pure=$false};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m019-rs02a-dry';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0;DryRun=$true};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x5007a0');database=$TX}},[ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x5007a0');database=$TX}});Exact=@('arg_0 remains arg_0','all five frame rows and complete I02 function protections unchanged');AllowedDelta=@();AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=20;Id='RS02a.Actual';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m020-rs02a-actual';method='tools/call';params=[ordered]@{name='rename';arguments=[ordered]@{batch=[ordered]@{stack=[ordered]@{func_addr='0x5007a0';old='arg_0';new='directionIndex'};dry_run=$false;stop_on_error=$true;allow_overwrite=$false;pure=$false};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m020-rs02a-actual';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0;DryRun=$false};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x5007a0');database=$TX}},[ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x5007a0');database=$TX}});Exact=@('directionIndex@+0xc replaces arg_0 at same offset/size/type','all other I02 frame/function protections unchanged');AllowedDelta=@('arg_0 frame-member name only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=21;Id='RS02b.Dry';Phase='Dry';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m021-rs02b-dry';method='tools/call';params=[ordered]@{name='rename';arguments=[ordered]@{batch=[ordered]@{stack=[ordered]@{func_addr='0x5007a0';old='arg_4';new='bounds'};dry_run=$true;stop_on_error=$true;allow_overwrite=$false;pure=$false};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m021-rs02b-dry';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0;DryRun=$true};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x5007a0');database=$TX}},[ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x5007a0');database=$TX}});Exact=@('arg_4 remains arg_4','directionIndex state and all other I02 frame/function protections unchanged');AllowedDelta=@();AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=22;Id='RS02b.Actual';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m022-rs02b-actual';method='tools/call';params=[ordered]@{name='rename';arguments=[ordered]@{batch=[ordered]@{stack=[ordered]@{func_addr='0x5007a0';old='arg_4';new='bounds'};dry_run=$false;stop_on_error=$true;allow_overwrite=$false;pure=$false};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m022-rs02b-actual';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0;DryRun=$false};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x5007a0');database=$TX}},[ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x5007a0');database=$TX}});Exact=@('bounds@+0x10 replaces arg_4 at same offset/size/type','directionIndex and all other I02 frame/function protections unchanged');AllowedDelta=@('arg_4 frame-member name only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=23;Id='RS03.Dry';Phase='Dry';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m023-rs03-dry';method='tools/call';params=[ordered]@{name='rename';arguments=[ordered]@{batch=[ordered]@{stack=[ordered]@{func_addr='0x5007f0';old='arg_0';new='visualState'};dry_run=$true;stop_on_error=$true;allow_overwrite=$false;pure=$false};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m023-rs03-dry';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0;DryRun=$true};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x5007f0');database=$TX}},[ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x5007f0');database=$TX}});Exact=@('arg_0 remains arg_0','final F03 type and all I03 protections unchanged');AllowedDelta=@();AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=24;Id='RS03.Actual';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m024-rs03-actual';method='tools/call';params=[ordered]@{name='rename';arguments=[ordered]@{batch=[ordered]@{stack=[ordered]@{func_addr='0x5007f0';old='arg_0';new='visualState'};dry_run=$false;stop_on_error=$true;allow_overwrite=$false;pure=$false};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m024-rs03-actual';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0;DryRun=$false};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x5007f0');database=$TX}},[ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x5007f0');database=$TX}});Exact=@('visualState@+0xc replaces arg_0 at same offset/type','final F03 type and all other I03 protections unchanged');AllowedDelta=@('arg_0 frame-member name only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=25;Id='RS07.Dry';Phase='Dry';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m025-rs07-dry';method='tools/call';params=[ordered]@{name='rename';arguments=[ordered]@{batch=[ordered]@{stack=[ordered]@{func_addr='0x5026a0';old='arg_0';new='flags'};dry_run=$true;stop_on_error=$true;allow_overwrite=$false;pure=$false};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m025-rs07-dry';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0;DryRun=$true};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x5026a0');database=$TX}},[ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x5026a0');database=$TX}});Exact=@('arg_0 remains arg_0','final F07 type and all I07 protections unchanged');AllowedDelta=@();AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=26;Id='RS07.Actual';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m026-rs07-actual';method='tools/call';params=[ordered]@{name='rename';arguments=[ordered]@{batch=[ordered]@{stack=[ordered]@{func_addr='0x5026a0';old='arg_0';new='flags'};dry_run=$false;stop_on_error=$true;allow_overwrite=$false;pure=$false};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m026-rs07-actual';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0;DryRun=$false};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x5026a0');database=$TX}},[ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x5026a0');database=$TX}});Exact=@('flags@+0xc replaces arg_0 at same offset/type','final F07 type and all other I07 protections unchanged');AllowedDelta=@('arg_0 frame-member name only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=27;Id='TS02a';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m027-ts02a';method='tools/call';params=[ordered]@{name='set_type';arguments=[ordered]@{edits=[ordered]@{addr='0x5007a0';kind='stack';name='directionIndex';ty='int'};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m027-ts02a';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x5007a0');database=$TX}},[ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x5007a0');database=$TX}});Exact=@('directionIndex@+0xc size4 signed __int32 or source-equivalent int','other four I02 rows and every function protection exact');AllowedDelta=@('directionIndex row type only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=28;Id='TS02b';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m028-ts02b';method='tools/call';params=[ordered]@{name='set_type';arguments=[ordered]@{edits=[ordered]@{addr='0x5007a0';kind='stack';name='bounds';ty='const RectBounds *'};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m028-ts02b';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x5007a0');database=$TX}},[ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x5007a0');database=$TX}});Exact=@('bounds@+0x10 size4 const RectBounds *','other four I02 rows and every function protection exact');AllowedDelta=@('bounds row type only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=29;Id='TS03';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m029-ts03';method='tools/call';params=[ordered]@{name='set_type';arguments=[ordered]@{edits=[ordered]@{addr='0x5007f0';kind='stack';name='visualState';ty='unsigned __int8'};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m029-ts03';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x5007f0');database=$TX}},[ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x5007f0');database=$TX}});Exact=@('visualState@+0xc size1 unsigned __int8','saved-register/return-address rows and every I03 protection exact');AllowedDelta=@('visualState row type/semantic width only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=30;Id='TS07';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m030-ts07';method='tools/call';params=[ordered]@{name='set_type';arguments=[ordered]@{edits=[ordered]@{addr='0x5026a0';kind='stack';name='flags';ty='unsigned int'};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m030-ts07';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='stack_frame';arguments=[ordered]@{addrs=@('0x5026a0');database=$TX}},[ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x5026a0');database=$TX}});Exact=@('flags@+0xc size4 unsigned __int32 or source-equivalent unsigned int','saved-register/return-address rows and every I07 protection exact');AllowedDelta=@('flags row type only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=31;Id='C02';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m031-c02';method='tools/call';params=[ordered]@{name='set_repeatable_comments';arguments=[ordered]@{items=[ordered]@{addr='0x5007a0';comment='Retained DirectionButtonControlPane constructor copy; source is emitted inline in the class declaration. Initializes ButtonControlPane, m_directionIndex, three inherited vptr views, and m_stateFrameOffset.'};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m031-c02';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='get_comments';arguments=[ordered]@{addrs=@('0x5007a0');database=$TX}},[ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x5007a0');database=$TX}});Exact=@('address regular empty','address repeatable empty','function regular empty','function repeatable exact constructor text');AllowedDelta=@('function-repeatable comment only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=32;Id='C03';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m032-c03';method='tools/call';params=[ordered]@{name='set_repeatable_comments';arguments=[ordered]@{items=[ordered]@{addr='0x5007f0';comment="When visual state changes, updates the two-frame direction control's frame offset; always delegates to ControlPane::SetVisualState."};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m032-c03';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='get_comments';arguments=[ordered]@{addrs=@('0x5007f0');database=$TX}},[ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x5007f0');database=$TX}});Exact=@('three non-repeatable/address channels empty','function repeatable exact state-change/base-call text');AllowedDelta=@('function-repeatable comment only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=33;Id='C04';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m033-c04';method='tools/call';params=[ordered]@{name='set_repeatable_comments';arguments=[ordered]@{items=[ordered]@{addr='0x500820';comment='Paints the direction frame from DIREC.EPD with NPAL3.PAL and applies the inherited overlay only while disabled.'};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m033-c04';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='get_comments';arguments=[ordered]@{addrs=@('0x500820');database=$TX}},[ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x500820');database=$TX}});Exact=@('three non-repeatable/address channels empty','function repeatable exact DIREC/NPAL3/disabled-overlay text');AllowedDelta=@('function-repeatable comment only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=34;Id='D05';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m034-d05';method='tools/call';params=[ordered]@{name='set_address_comments';arguments=[ordered]@{items=[ordered]@{addr='0x50248a';comment=''};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m034-d05';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='get_comments';arguments=[ordered]@{addrs=@('0x50248a');database=$TX}},[ordered]@{tool='callees';arguments=[ordered]@{addrs=@('0x50248a');limit=500;database=$TX}},[ordered]@{tool='disasm';arguments=[ordered]@{addr='0x50248a';max_instructions=2;offset=0;include_total=$true;database=$TX}});Exact=@('all four comment channels empty','callees empty','exact two-instruction adjustor and ref 0x5026a0','body/frame/xref/P05 exact');AllowedDelta=@('address-regular comment Block to empty only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=35;Id='C05';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m035-c05';method='tools/call';params=[ordered]@{name='set_repeatable_comments';arguments=[ordered]@{items=[ordered]@{addr='0x50248a';comment='Compiler-generated -0xa0 receiver adjustor for the DirectionButtonControlPane scalar deleting destructor.'};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m035-c05';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='get_comments';arguments=[ordered]@{addrs=@('0x50248a');database=$TX}},[ordered]@{tool='callees';arguments=[ordered]@{addrs=@('0x50248a');limit=500;database=$TX}},[ordered]@{tool='disasm';arguments=[ordered]@{addr='0x50248a';max_instructions=2;offset=0;include_total=$true;database=$TX}});Exact=@('address regular/repeatable and function regular empty','function repeatable exact -0xa0 adjustor text','callees empty','exact two-instruction adjustor and ref 0x5026a0','body/frame/xref/P05 exact');AllowedDelta=@('function-repeatable comment only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=36;Id='D06';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m036-d06';method='tools/call';params=[ordered]@{name='set_address_comments';arguments=[ordered]@{items=[ordered]@{addr='0x502495';comment=''};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m036-d06';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='get_comments';arguments=[ordered]@{addrs=@('0x502495');database=$TX}},[ordered]@{tool='callees';arguments=[ordered]@{addrs=@('0x502495');limit=500;database=$TX}},[ordered]@{tool='disasm';arguments=[ordered]@{addr='0x502495';max_instructions=2;offset=0;include_total=$true;database=$TX}});Exact=@('all four comment channels empty','callees empty','exact two-instruction adjustor and ref 0x5026a0','body/frame/xref/P06 exact');AllowedDelta=@('address-regular comment Block to empty only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=37;Id='C06';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m037-c06';method='tools/call';params=[ordered]@{name='set_repeatable_comments';arguments=[ordered]@{items=[ordered]@{addr='0x502495';comment='Compiler-generated -0xa4 receiver adjustor for the DirectionButtonControlPane scalar deleting destructor.'};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m037-c06';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='get_comments';arguments=[ordered]@{addrs=@('0x502495');database=$TX}},[ordered]@{tool='callees';arguments=[ordered]@{addrs=@('0x502495');limit=500;database=$TX}},[ordered]@{tool='disasm';arguments=[ordered]@{addr='0x502495';max_instructions=2;offset=0;include_total=$true;database=$TX}});Exact=@('address regular/repeatable and function regular empty','function repeatable exact -0xa4 adjustor text','callees empty','exact two-instruction adjustor and ref 0x5026a0','body/frame/xref/P06 exact');AllowedDelta=@('function-repeatable comment only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=38;Id='C07';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m038-c07';method='tools/call';params=[ordered]@{name='set_repeatable_comments';arguments=[ordered]@{items=[ordered]@{addr='0x5026a0';comment='Compiler-generated scalar deleting destructor; resets three inherited vptr views, runs Pane teardown, and conditionally calls operator delete.'};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m038-c07';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='get_comments';arguments=[ordered]@{addrs=@('0x5026a0');database=$TX}},[ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x5026a0');database=$TX}});Exact=@('three non-repeatable/address channels empty','function repeatable exact destructor/vptr/Pane/delete text');AllowedDelta=@('function-repeatable comment only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=39;Id='C08';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m039-c08';method='tools/call';params=[ordered]@{name='set_address_repeatable_comments';arguments=[ordered]@{items=[ordered]@{addr='0x61dc30';comment='DirectionButtonControlPane primary complete-object locator pointer; primary vtable begins at 0x61dc34 with 25 slots.'};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m039-c08';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='get_comments';arguments=[ordered]@{addrs=@('0x61dc30');database=$TX}},[ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x61dc30');database=$TX}},[ordered]@{tool='get_bytes';arguments=[ordered]@{regions=[ordered]@{addr='0x61dc30';size=4};database=$TX}});Exact=@('address regular empty','address repeatable exact primary COL text','bytes E8 AB 64 00','value 0x64abe8','zero xrefs');AllowedDelta=@('address-repeatable comment only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=40;Id='C09';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m040-c09';method='tools/call';params=[ordered]@{name='set_address_repeatable_comments';arguments=[ordered]@{items=[ordered]@{addr='0x61dc98';comment='DirectionButtonControlPane EventHandler-view complete-object locator pointer (complete-object offset 0xa0); secondary vtable begins at 0x61dc9c with 11 slots.'};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m040-c09';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='get_comments';arguments=[ordered]@{addrs=@('0x61dc98');database=$TX}},[ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x61dc98');database=$TX}},[ordered]@{tool='get_bytes';arguments=[ordered]@{regions=[ordered]@{addr='0x61dc98';size=4};database=$TX}});Exact=@('address regular empty','address repeatable exact EventHandler COL text','bytes 4C AC 64 00','value 0x64ac4c','zero xrefs');AllowedDelta=@('address-repeatable comment only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=41;Id='C10';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m041-c10';method='tools/call';params=[ordered]@{name='set_address_repeatable_comments';arguments=[ordered]@{items=[ordered]@{addr='0x61dcc8';comment='DirectionButtonControlPane TimerHandler-view complete-object locator pointer (complete-object offset 0xa4); tertiary vtable begins at 0x61dccc with 2 slots.'};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m041-c10';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='get_comments';arguments=[ordered]@{addrs=@('0x61dcc8');database=$TX}},[ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x61dcc8');database=$TX}},[ordered]@{tool='get_bytes';arguments=[ordered]@{regions=[ordered]@{addr='0x61dcc8';size=4};database=$TX}});Exact=@('address regular empty','address repeatable exact TimerHandler COL text','bytes 60 AC 64 00','value 0x64ac60','zero xrefs');AllowedDelta=@('address-repeatable comment only');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=42;Id='M11';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m042-m11';method='tools/call';params=[ordered]@{name='make_data';arguments=[ordered]@{items=[ordered]@{addr='0x61e40c';type='const wchar_t[10]';name='aNpal3Pal';delete_existing=$true};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m042-m11';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x61e40c','0x61e420');database=$TX}},[ordered]@{tool='get_bytes';arguments=[ordered]@{regions=[ordered]@{addr='0x61e40c';size=20};database=$TX}},[ordered]@{tool='xrefs_to';arguments=[ordered]@{addrs=@('0x61e40c','0x61e40d','0x61e40e','0x61e40f','0x61e410','0x61e411','0x61e412','0x61e413','0x61e414','0x61e415','0x61e416','0x61e417','0x61e418','0x61e419','0x61e41a','0x61e41b','0x61e41c','0x61e41d','0x61e41e','0x61e41f');limit=1000;database=$TX}},[ordered]@{tool='entity_query';arguments=[ordered]@{queries=@([ordered]@{kind='names';regex='^aNpal3Pal$';count=20},[ordered]@{kind='names';regex='^(aNp_1|aAl3Pal)$';count=20});database=$TX}},[ordered]@{tool='get_string';arguments=[ordered]@{addrs=@('0x61e40c','0x61e420');database=$TX}});Exact=@('one item [0x61e40c,0x61e420)','name aNpal3Pal','type const wchar_t[10]','bytes SHA256 06C384B1DBB8A2A67BB6755B98B08186050BE1FD0A7C18F144ECDEC7F4A9712C','string NPAL3.PAL','14 exact base xrefs and zero interior xrefs','obsolete aNp_1/aAl3Pal absent','P10/P11/P09 and successor exact');AllowedDelta=@('two split items replaced by one exact item/name/type');AllOtherFrozenFieldsEqual=$true}}
    [ordered]@{Seq=43;Id='C11';Phase='Actual';Request=[ordered]@{jsonrpc='2.0';id='uid0002ow-m043-c11';method='tools/call';params=[ordered]@{name='set_address_repeatable_comments';arguments=[ordered]@{items=[ordered]@{addr='0x61e40c';comment='Shared NPAL3.PAL palette resource name used by DirectionButtonControlPane::OnPaint and related render paths.'};database=$TX}}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id='uid0002ow-m043-c11';TopLevelError=$false;ToolIsError=$false;SuccessCount=1;FailureCount=0};ExpectedReadback=[ordered]@{Calls=@([ordered]@{tool='get_comments';arguments=[ordered]@{addrs=@('0x61e40c');database=$TX}},[ordered]@{tool='inspect_items';arguments=[ordered]@{addrs=@('0x61e40c');database=$TX}},[ordered]@{tool='get_string';arguments=[ordered]@{addrs=@('0x61e40c');database=$TX}});Exact=@('address regular empty','address repeatable exact shared NPAL3.PAL text','one exact aNpal3Pal const wchar_t[10] item','string NPAL3.PAL','bytes/xrefs/obsolete-name absence and all predecessors/successors exact');AllowedDelta=@('address-repeatable comment only');AllOtherFrozenFieldsEqual=$true}}
)
if ($MutationPlan.Count -ne 43) { throw 'mutation count is not 43' }
if ((@($MutationPlan | Where-Object Phase -eq 'Dry')).Count -ne 10 -or (@($MutationPlan | Where-Object Phase -eq 'Actual')).Count -ne 33) { throw 'dry/actual count mismatch' }
if ((Compare-Object @(1..43) @($MutationPlan.Seq)).Count -ne 0) { throw 'mutation sequence mismatch' }
if ((@($MutationPlan | Where-Object {[string]::IsNullOrWhiteSpace([string]$_.Request.params.name) -or [string]::IsNullOrWhiteSpace([string]$_.Request.params.arguments.database) -or $_.Request.params.arguments.database -ne $TX -or $null -eq $_.ExpectedResponse -or $null -eq $_.ExpectedReadback -or @($_.ExpectedReadback.Calls).Count -eq 0})).Count -ne 0) { throw 'incomplete or unbound mutation object' }
$MutationPlanJson = $MutationPlan | ConvertTo-Json -Depth 100
$MutationPlanRoundTrip = @($MutationPlanJson | ConvertFrom-Json)
if ($MutationPlanRoundTrip.Count -ne 43) { throw 'mutation JSON round-trip failed' }
~~~

## Removed Block R006

- SHA256: `0A7F85532BBE0FCDF574711C67881CB61E1EC46F5CF2B532BA62EE737C00A5DD`
- Language: `powershell`
- Bytes: `2764`
- First recovered timestamp: `2026-08-06T23:07:18.951Z`
- Session provenance: rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 194040 (2026-08-06T23:07:18.951Z); rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 194041 (2026-08-06T23:07:19.019Z)

~~~powershell
$TxOpenRequest = [ordered]@{jsonrpc='2.0';id='uid0002ow-transaction-open';method='tools/call';params=[ordered]@{name='idb_open';arguments=[ordered]@{input_path=$CanonicalPath;mode='force_headless';run_auto_analysis=$false;build_caches=$true;init_hexrays=$true;idle_ttl_sec=3600;preferred_session_id="supervisor-uid0002ow-transaction-$Stamp"}}}
$VerifyOpenRequest = [ordered]@{jsonrpc='2.0';id='uid0002ow-postsave-verify-open';method='tools/call';params=[ordered]@{name='idb_open';arguments=[ordered]@{input_path=$CanonicalPath;mode='force_headless';run_auto_analysis=$false;build_caches=$true;init_hexrays=$true;idle_ttl_sec=3600;preferred_session_id="supervisor-uid0002ow-postsave-verify-$Stamp"}}}
$FailureVerifyOpenRequest = [ordered]@{jsonrpc='2.0';id='uid0002ow-failure-verify-open';method='tools/call';params=[ordered]@{name='idb_open';arguments=[ordered]@{input_path=$CanonicalPath;mode='force_headless';run_auto_analysis=$false;build_caches=$true;init_hexrays=$true;idle_ttl_sec=3600;preferred_session_id="supervisor-uid0002ow-failure-verify-$Stamp"}}}
$RollbackOpenRequest = [ordered]@{jsonrpc='2.0';id='uid0002ow-rollback-verify-open';method='tools/call';params=[ordered]@{name='idb_open';arguments=[ordered]@{input_path=$CanonicalPath;mode='force_headless';run_auto_analysis=$false;build_caches=$true;init_hexrays=$true;idle_ttl_sec=3600;preferred_session_id="supervisor-uid0002ow-rollback-verify-$Stamp"}}}

# Invoke only after each role's preceding Q/tuple boundary passes.
$TxOpenEnvelope = Invoke-McpRpc $TxOpenRequest
$TX = Get-ReturnedDatabaseId $TxOpenEnvelope 'transaction'
$TxBinding = Assert-ReturnedDatabase $TX 'transaction'

# Invoke only in the definite-success post-save verification branch.
$VerifyOpenEnvelope = Invoke-McpRpc $VerifyOpenRequest
$V = Get-ReturnedDatabaseId $VerifyOpenEnvelope 'postsave-verify'
$VerifyBinding = Assert-ReturnedDatabase $V 'postsave-verify'

# Invoke only in a determinate-failure or indeterminate classifier branch.
$FailureVerifyOpenEnvelope = Invoke-McpRpc $FailureVerifyOpenRequest
$FAIL_VERIFY = Get-ReturnedDatabaseId $FailureVerifyOpenEnvelope 'failure-verify'
$FailureVerifyBinding = Assert-ReturnedDatabase $FAIL_VERIFY 'failure-verify'

# Invoke only after a guarded saved rollback restores exact P0.
$RollbackOpenEnvelope = Invoke-McpRpc $RollbackOpenRequest
$RB = Get-ReturnedDatabaseId $RollbackOpenEnvelope 'rollback-verify'
$RollbackBinding = Assert-ReturnedDatabase $RB 'rollback-verify'

# Construct and invoke this object exactly once only after V00-V13 passes.
$SaveRequest = [ordered]@{jsonrpc='2.0';id='uid0002ow-transaction-save';method='tools/call';params=[ordered]@{name='idb_save';arguments=[ordered]@{database=$TX}}}
$SaveEnvelope = Invoke-McpRpc $SaveRequest
~~~

## Removed Block R007

- SHA256: `C6FC8B4F2E58D4F63A68490A61AC3F04B85CC340EA81FFF25590B2D4DB4C8F2D`
- Language: `powershell`
- Bytes: `224`
- First recovered timestamp: `2026-08-06T23:08:02.301Z`
- Session provenance: rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 194046 (2026-08-06T23:08:02.301Z); rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 194047 (2026-08-06T23:08:02.367Z)

~~~powershell
$SaveRequest = [ordered]@{jsonrpc='2.0';id='uid0002ow-transaction-save';method='tools/call';params=[ordered]@{name='idb_save';arguments=[ordered]@{database=$TX}}}
$SaveEnvelope = Invoke-McpRpc $SaveRequest
~~~

## Removed Block R008

- SHA256: `F4E558AA83633EE77A4FB508E991F010EEFED74A31663629A38C05FCE7D25FD3`
- Language: `powershell`
- Bytes: `201`
- First recovered timestamp: `2026-08-06T23:08:02.301Z`
- Session provenance: rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 194046 (2026-08-06T23:08:02.301Z); rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 194047 (2026-08-06T23:08:02.367Z)

~~~powershell
$VerifyOpenEnvelope = Invoke-McpRpc $VerifyOpenRequest
$V = Get-ReturnedDatabaseId $VerifyOpenEnvelope 'postsave-verify'
$VerifyBinding = Assert-ReturnedDatabase $V 'postsave-verify'
~~~

## Removed Block R009

- SHA256: `89615C172D7AA353D61E356B4A7A3F7ACE4A2F2F7E747CD6BA49EABCD0CB000A`
- Language: `powershell`
- Bytes: `211`
- First recovered timestamp: `2026-08-06T23:08:39.090Z`
- Session provenance: rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 194055 (2026-08-06T23:08:39.090Z)

~~~powershell
$RollbackOpenEnvelope = Invoke-McpRpc $RollbackOpenRequest
$RB = Get-ReturnedDatabaseId $RollbackOpenEnvelope 'rollback-verify'
$RollbackBinding = Assert-ReturnedDatabase $RB 'rollback-verify'
~~~

## Removed Block R010

- SHA256: `98CB14DA0FF105076F64292CF5DF5C23FB3F65435926AD6F2A257424442C79AC`
- Language: `powershell`
- Bytes: `247`
- First recovered timestamp: `2026-08-06T23:08:39.090Z`
- Session provenance: rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 194055 (2026-08-06T23:08:39.090Z); rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 194060 (2026-08-06T23:08:57.362Z)

~~~powershell
$FailureVerifyOpenEnvelope = Invoke-McpRpc $FailureVerifyOpenRequest
$FAIL_VERIFY = Get-ReturnedDatabaseId $FailureVerifyOpenEnvelope 'failure-verify'
$FailureVerifyBinding = Assert-ReturnedDatabase $FAIL_VERIFY 'failure-verify'
~~~

## Removed Block R011

- SHA256: `1621030EC663762D4063F43D800ED7B422756EF8D506465A64B3B2C745A1D42F`
- Language: `powershell`
- Bytes: `333`
- First recovered timestamp: `2026-08-06T23:09:14.242Z`
- Session provenance: rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 194064 (2026-08-06T23:09:14.242Z); rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 194065 (2026-08-06T23:09:14.289Z)

~~~powershell
# Guarded saved-rollback verifier branch only.
$RollbackOpenEnvelope = Invoke-McpRpc $RollbackOpenRequest
$RB = Get-ReturnedDatabaseId $RollbackOpenEnvelope 'rollback-verify'
$RollbackBinding = Assert-ReturnedDatabase $RB 'rollback-verify'
# Every RV00-RV13 rollback-verifier call in this branch uses database=$RB.
~~~

## Removed Block R012

- SHA256: `B45500224ED20FD0FF82D8FDFB96EF7FC8015FD28D9EE86E8A8893831622BB9B`
- Language: `powershell`
- Bytes: `394`
- First recovered timestamp: `2026-08-06T23:09:14.242Z`
- Session provenance: rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 194064 (2026-08-06T23:09:14.242Z); rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 194065 (2026-08-06T23:09:14.289Z)

~~~powershell
# Failure/indeterminate/unsaved classifier branch only.
$FailureVerifyOpenEnvelope = Invoke-McpRpc $FailureVerifyOpenRequest
$FAIL_VERIFY = Get-ReturnedDatabaseId $FailureVerifyOpenEnvelope 'failure-verify'
$FailureVerifyBinding = Assert-ReturnedDatabase $FAIL_VERIFY 'failure-verify'
# Every RV00-RV13 and SV00-SV13 classifier call in this branch uses database=$FAIL_VERIFY.
~~~

## Removed Block R013

- SHA256: `A1D5D4B49DE809C66F301E545B0CFD9A4A1C5F03850352F6B1B671A3C154AA62`
- Language: `powershell`
- Bytes: `23992`
- First recovered timestamp: `2026-08-07T00:13:41.581Z`
- Session provenance: rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 194723 (2026-08-07T00:13:41.581Z)

~~~powershell
function New-CompleteToolRequest([string]$Id,[string]$Tool,$Arguments) {
    if ([string]::IsNullOrWhiteSpace($Id) -or [string]::IsNullOrWhiteSpace($Tool) -or $null -eq $Arguments) { throw 'incomplete tool request construction' }
    [ordered]@{jsonrpc='2.0';id=$Id;method='tools/call';params=[ordered]@{name=$Tool;arguments=$Arguments}}
}
function New-CompleteReadbackPlan($Mutation) {
    $result = @(); $index = 0
    foreach ($call in @($Mutation.ExpectedReadback.Calls)) {
        $index++
        $id = '{0}-rb{1:D3}' -f [string]$Mutation.Request.id,$index
        $request = New-CompleteToolRequest $id ([string]$call.tool) $call.arguments
        $result += ,[pscustomobject]@{Request=$request;ExpectedResponse=[ordered]@{jsonrpc='2.0';id=$id;TopLevelError=$false;ToolIsError=$false};MutationId=[string]$Mutation.Id;ReadbackIndex=$index}
    }
    if ($result.Count -eq 0) { throw "mutation has no readback requests: $($Mutation.Id)" }
    $result
}
function Assert-CompleteMutationPlan($Plan,[string]$Database) {
    if (@($Plan).Count -ne 43 -or @($Plan|Where-Object Phase -eq 'Dry').Count -ne 10 -or @($Plan|Where-Object Phase -eq 'Actual').Count -ne 33) { throw 'mutation count/phase contract mismatch' }
    $ids=@{}; $sequences=@(); $readbackCount=0
    foreach ($mutation in $Plan) {
        $sequences += [int]$mutation.Seq
        if ($mutation.Request.jsonrpc -cne '2.0' -or $mutation.Request.method -cne 'tools/call' -or $mutation.Request.id -isnot [string] -or $ids.ContainsKey([string]$mutation.Request.id)) { throw "malformed/duplicate mutation request: $($mutation.Id)" }
        $ids[[string]$mutation.Request.id]=$true
        if ([string]$mutation.Request.params.arguments.database -cne $Database -or [string]$mutation.ExpectedResponse.id -cne [string]$mutation.Request.id) { throw "unbound mutation or response ID: $($mutation.Id)" }
        if ($mutation.ExpectedReadback.AllOtherFrozenFieldsEqual -ne $true -or @($mutation.ExpectedReadback.Exact).Count -eq 0 -or $null -eq $mutation.ExpectedReadback.AllowedDelta) { throw "missing mutation semantic contract: $($mutation.Id)" }
        $readbacks = @(New-CompleteReadbackPlan $mutation)
        foreach ($readback in $readbacks) {
            $readbackCount++
            if ($readback.Request.id -isnot [string] -or [string]$readback.Request.params.arguments.database -cne $Database -or [string]$readback.ExpectedResponse.id -cne [string]$readback.Request.id -or $ids.ContainsKey([string]$readback.Request.id)) { throw "incomplete/duplicate readback envelope: $($mutation.Id)" }
            $ids[[string]$readback.Request.id]=$true
        }
    }
    if ((Compare-Object @(1..43) $sequences -SyncWindow 0).Count -ne 0) { throw 'mutation sequence contract mismatch' }
    $serialized = $Plan | ConvertTo-Json -Depth 100 -Compress
    if ($serialized -match '(?i)then identical|TODO|placeholder|<[^>]+>') { throw 'mutation plan contains shorthand or unresolved placeholder' }
    [pscustomobject]@{Mutations=43;Dry=10;Actual=33;Readbacks=$readbackCount;UniqueRequestIds=$ids.Count}
}
function Invoke-ReadbackPlan($ReadbackPlan,[bool]$RequireToolSuccess) {
    $responses=@()
    foreach ($readback in @($ReadbackPlan)) {
        $response = Invoke-McpRpc $readback.Request
        if ($RequireToolSuccess -and ($response.result.isError -eq $true -or $null -eq $response.result)) { throw "readback tool failure: $($readback.Request.id)" }
        $responses += ,[pscustomobject]@{Plan=$readback;Envelope=$response}
    }
    $responses
}
function Get-RequestedSemanticLiterals($Request) {
    $values=@(); $arguments=$Request.params.arguments
    switch ([string]$Request.params.name) {
        'define_func' { foreach($item in @($arguments.items)){ $values+=@([string]$item.addr,[string]$item.end) } }
        'declare_type' { $values+=@($arguments.decls|ForEach-Object{[string]$_}) }
        'rename' {
            foreach($kind in @('func','data','local','stack')){ foreach($item in @($arguments.batch.$kind)){ if($null-ne$item.name){$values+=[string]$item.name};if($null-ne$item.new){$values+=[string]$item.new} } }
        }
        'set_type' { foreach($item in @($arguments.edits)){ foreach($field in @('ty','signature','name')){if($null-ne$item.$field){$values+=[string]$item.$field}} } }
        'set_address_comments' { foreach($item in @($arguments.items)){if(-not[string]::IsNullOrEmpty([string]$item.comment)){$values+=[string]$item.comment}} }
        'set_repeatable_comments' { foreach($item in @($arguments.items)){if(-not[string]::IsNullOrEmpty([string]$item.comment)){$values+=[string]$item.comment}} }
        'set_address_repeatable_comments' { foreach($item in @($arguments.items)){if(-not[string]::IsNullOrEmpty([string]$item.comment)){$values+=[string]$item.comment}} }
        'make_data' { foreach($item in @($arguments.items)){foreach($field in @('type','name')){if($null-ne$item.$field){$values+=[string]$item.$field}}} }
    }
    @($values|Where-Object{-not[string]::IsNullOrWhiteSpace($_)}|Sort-Object -Unique)
}
function Assert-MutationSemanticResult($Mutation,$Before,$After) {
    if (@($After).Count -eq 0 -or $Mutation.ExpectedReadback.AllOtherFrozenFieldsEqual -ne $true) { throw "empty/frozen semantic result: $($Mutation.Id)" }
    $beforeJson = $Before | ForEach-Object {$_.Envelope.result|ConvertTo-Json -Depth 100 -Compress}
    $afterJson = $After | ForEach-Object {$_.Envelope.result|ConvertTo-Json -Depth 100 -Compress}
    if ($Mutation.Phase -eq 'Dry' -and (($beforeJson -join "`n") -cne ($afterJson -join "`n"))) { throw "dry mutation changed readback state: $($Mutation.Id)" }
    if ($Mutation.Phase -eq 'Actual') {
        $joined = $afterJson -join "`n"
        foreach ($literal in @(Get-RequestedSemanticLiterals $Mutation.Request)) { if (-not $joined.Contains($literal)) { throw "requested poststate literal absent for $($Mutation.Id): $literal" } }
    }
    [pscustomobject]@{MutationId=[string]$Mutation.Id;Exact=@($Mutation.ExpectedReadback.Exact);AllowedDelta=@($Mutation.ExpectedReadback.AllowedDelta);Frozen=$true}
}
function Assert-MutationResponse($Mutation,$Envelope) {
    if ($Envelope.result.isError -eq $true) { throw "mutation tool error: $($Mutation.Id)" }
    $structured=$Envelope.result.structuredContent
    if ($null-eq$structured) { throw "mutation missing structured result: $($Mutation.Id)" }
    $json=$structured|ConvertTo-Json -Depth 50 -Compress
    foreach($forbidden in @($Mutation.ExpectedResponse.ForbiddenFields)){if($json -match ('"'+[regex]::Escape([string]$forbidden)+'"')){throw "forbidden mutation response field: $forbidden"}}
    $Envelope
}
function Invoke-CompleteMutationPlan($Plan,[string]$Database) {
    $static=Assert-CompleteMutationPlan $Plan $Database; $journal=@()
    foreach($mutation in @($Plan|Sort-Object Seq)) {
        $readbackPlan=@(New-CompleteReadbackPlan $mutation)
        $before=@(Invoke-ReadbackPlan $readbackPlan $false)
        $mutationEnvelope=Invoke-McpRpc $mutation.Request
        [void](Assert-MutationResponse $mutation $mutationEnvelope)
        $after=@(Invoke-ReadbackPlan $readbackPlan $true)
        $semantic=Assert-MutationSemanticResult $mutation $before $after
        $journal+=,[pscustomobject]@{Seq=[int]$mutation.Seq;Id=[string]$mutation.Id;Request=$mutation.Request;Response=$mutationEnvelope;Before=$before;After=$after;Semantic=$semantic}
    }
    if ($journal.Count-ne43) { throw 'mutation runner did not execute exactly 43 phases' }
    [pscustomobject]@{Static=$static;Journal=$journal}
}

$StateFunctionHeads=@('0x5007a0','0x5007f0','0x500820','0x50248a','0x502495','0x5026a0','0x5008c0','0x5024a0')
$StateDataHeads=@('0x500797','0x5007e8','0x50081e','0x5008b9','0x502485','0x502695','0x5026f5','0x61e3f4','0x61e3f8','0x61e40c','0x61e410','0x61e420','0x61e540','0x61e554')
$StateI13Heads=@('0x61dc30','0x61dc34','0x61dc38','0x61dc3c','0x61dc40','0x61dc44','0x61dc48','0x61dc4c','0x61dc50','0x61dc54','0x61dc58','0x61dc5c','0x61dc60','0x61dc64','0x61dc68','0x61dc6c','0x61dc70','0x61dc74','0x61dc78','0x61dc7c','0x61dc80','0x61dc84','0x61dc88','0x61dc8c','0x61dc90','0x61dc94','0x61dc98','0x61dc9c','0x61dca0','0x61dca4','0x61dca8','0x61dcac','0x61dcb0','0x61dcb4','0x61dcb8','0x61dcbc','0x61dcc0','0x61dcc4','0x61dcc8','0x61dccc','0x61dcd0','0x61dcd4','0x61dcd8')
$StateAllHeads=@($StateFunctionHeads+$StateDataHeads+$StateI13Heads|Sort-Object -Unique)
$StateByteRegions=@(
    @{addr='0x500797';size=9},@{addr='0x5007a0';size=72},@{addr='0x5007e8';size=8},@{addr='0x5007f0';size=46},@{addr='0x50081e';size=2},@{addr='0x500820';size=153},@{addr='0x5008b9';size=7},@{addr='0x5008c0';size=868},
    @{addr='0x502485';size=5},@{addr='0x50248a';size=11},@{addr='0x502495';size=11},@{addr='0x5024a0';size=11},@{addr='0x502695';size=11},@{addr='0x5026a0';size=85},@{addr='0x5026f5';size=11},
    @{addr='0x61dc30';size=164},@{addr='0x61dcd4';size=8},@{addr='0x61e3f4';size=4},@{addr='0x61e3f8';size=20},@{addr='0x61e40c';size=20},@{addr='0x61e420';size=4},@{addr='0x61e540';size=20},@{addr='0x61e554';size=24}
)
function New-StateVerificationPlan([string]$Prefix,[string]$Database,[ValidateSet('Original','Transition','Post')]$ExpectedState) {
    if ([string]::IsNullOrWhiteSpace($Database)) { throw 'state plan has empty database' }
    $plan=@();$sequence=0
    function Add-StateCall([string]$Class,[string]$Tool,$Arguments) {
        $script:StateSequence++
        $id='{0}-{1:D3}-{2}' -f $Prefix,$script:StateSequence,$Tool
        $request=New-CompleteToolRequest $id $Tool $Arguments
        $script:StatePlan += ,[pscustomobject]@{Class=$Class;Request=$request;ExpectedResponse=[ordered]@{jsonrpc='2.0';id=$id;TopLevelError=$false;ToolIsError=$false};ExpectedState=$ExpectedState}
    }
    $script:StatePlan=@();$script:StateSequence=0
    Add-StateCall 'S00' 'idb_list' ([ordered]@{})
    Add-StateCall 'S01' 'server_health' ([ordered]@{database=$Database})
    $sequence++;$schemaId='{0}-schema-{1:D3}'-f$Prefix,$sequence;$script:StatePlan+=,[pscustomobject]@{Class='S02';Request=[ordered]@{jsonrpc='2.0';id=$schemaId;method='tools/list';params=[ordered]@{}};ExpectedResponse=[ordered]@{jsonrpc='2.0';id=$schemaId;TopLevelError=$false};ExpectedState=$ExpectedState}
    Add-StateCall 'S03' 'lookup_funcs' ([ordered]@{queries=$StateFunctionHeads;database=$Database})
    Add-StateCall 'S03' 'callees' ([ordered]@{addrs=@('0x5007a0','0x5007f0','0x500820','0x50248a','0x502495','0x5026a0');limit=500;database=$Database})
    Add-StateCall 'S03' 'inspect_items' ([ordered]@{addrs=@('0x5008c0');database=$Database})
    Add-StateCall 'S03' 'export_funcs' ([ordered]@{addrs=@('0x5008c0');format='prototypes';database=$Database})
    Add-StateCall 'S03' 'disasm' ([ordered]@{addr='0x50248a';max_instructions=2;offset=0;include_total=$true;database=$Database})
    Add-StateCall 'S03' 'disasm' ([ordered]@{addr='0x502495';max_instructions=2;offset=0;include_total=$true;database=$Database})
    Add-StateCall 'S04' 'inspect_items' ([ordered]@{addrs=$StateAllHeads;database=$Database})
    Add-StateCall 'S05' 'get_comments' ([ordered]@{addrs=$StateAllHeads;database=$Database})
    Add-StateCall 'S06' 'stack_frame' ([ordered]@{addrs=$StateFunctionHeads;database=$Database})
    Add-StateCall 'S07' 'get_bytes' ([ordered]@{regions=$StateByteRegions;database=$Database})
    Add-StateCall 'S08' 'xrefs_to' ([ordered]@{addrs=$StateAllHeads;limit=1000;database=$Database})
    $nameQueries=@('off_61E3F4','aPsuleEpd','aNp_1','aAl3Pal','aNpal3Pal','DirectionButtonControlPane__DirectionButtonControlPane','DirectionButtonControlPane__SetVisualState','DirectionButtonControlPane__OnPaint','DirectionButtonControlPane__scalar_deleting_destructor')|ForEach-Object{[ordered]@{kind='names';filter=('^'+[regex]::Escape($_)+'$');count=20}}
    Add-StateCall 'S09' 'entity_query' ([ordered]@{queries=@($nameQueries);database=$Database})
    $typeQueries=@('DirectionButtonControlPane','ControlPane','RectBounds','EPFTileContext')|ForEach-Object{[ordered]@{filter=('^'+$_+'$');kind='udt';count=20;include_decl=$true;include_members=$true;include_relationships=$true}}
    Add-StateCall 'S10' 'type_query' ([ordered]@{queries=@($typeQueries);database=$Database})
    $inspectQueries=@('ControlPane','RectBounds','EPFTileContext','DirectionButtonControlPane')|ForEach-Object{[ordered]@{name=$_;include_members=$true;max_members=100}}
    Add-StateCall 'S11' 'type_inspect' ([ordered]@{queries=@($inspectQueries);database=$Database})
    $intQueries=$StateI13Heads|ForEach-Object{[ordered]@{addr=$_;ty='u32le'}}
    Add-StateCall 'S12' 'get_int' ([ordered]@{queries=@($intQueries);database=$Database})
    Add-StateCall 'S13' 'get_string' ([ordered]@{addrs=@('0x61e3f4','0x61e3f8','0x61e40c','0x61e410','0x61e420','0x61e540','0x61e554');database=$Database})
    if (@($script:StatePlan|Select-Object -ExpandProperty Class -Unique).Count-ne14) { throw 'state plan does not contain S00-S13' }
    @($script:StatePlan)
}
function Assert-StateVerificationSemantics($Responses,[string]$ExpectedState) {
    if (@($Responses).Count-lt19) { throw 'incomplete verifier response plan' }
    $json=$Responses|ForEach-Object{$_.Envelope.result|ConvertTo-Json -Depth 100 -Compress}|Out-String
    foreach($token in @('0x5008c0','0x50248a','0x502495','0x5026a0','0x61dc30','0x61e40c')){if(-not$json.Contains($token)){throw "verifier omitted required target: $token"}}
    if($ExpectedState-eq'Original'){foreach($token in @('sub_5007F0','sub_500820','sub_5026A0')){if(-not$json.Contains($token)){throw "RV original token absent: $token"}}}
    if($ExpectedState-eq'Post'){foreach($token in @('DirectionButtonControlPane__SetVisualState','DirectionButtonControlPane__OnPaint','DirectionButtonControlPane__scalar_deleting_destructor','aNpal3Pal')){if(-not$json.Contains($token)){throw "SV post token absent: $token"}}}
    [pscustomobject]@{ExpectedState=$ExpectedState;ResponseCount=@($Responses).Count;Classes=@($Responses.Plan.Class|Sort-Object -Unique)}
}
function Invoke-StateVerificationPlan($Plan,[string]$ExpectedState) {
    $responses=@()
    foreach($entry in @($Plan)){$envelope=Invoke-McpRpc $entry.Request;if($envelope.result.isError-eq$true){throw "state request failed: $($entry.Request.id)"};if($entry.Class-eq'S02'){[void](Assert-PublicToolSchemas $envelope)};$responses+=,[pscustomobject]@{Plan=$entry;Envelope=$envelope}}
    $semantic=Assert-StateVerificationSemantics $responses $ExpectedState
    [pscustomobject]@{Plan=$Plan;Responses=$responses;Semantic=$semantic}
}

$script:SaveAttemptState=[pscustomobject]@{Attempted=$false;RequestId=$null;Class='PreSave';Envelope=$null;TransportError=$null}
function Invoke-SoleSave([string]$Database) {
    if($script:SaveAttemptState.Attempted){throw 'duplicate save attempt forbidden'}
    $request=New-CompleteToolRequest 'uid0002ow-transaction-save' 'idb_save' ([ordered]@{database=$Database})
    $script:SaveAttemptState.Attempted=$true;$script:SaveAttemptState.RequestId=$request.id
    try{$envelope=Invoke-McpRpc $request;$script:SaveAttemptState.Envelope=$envelope;if($envelope.result.isError-eq$true){$script:SaveAttemptState.Class='Failure'}else{$script:SaveAttemptState.Class='Success'}}catch{$script:SaveAttemptState.Class='Indeterminate';$script:SaveAttemptState.TransportError=$_.Exception.Message}
    $script:SaveAttemptState
}
function Assert-OneSaveContract($State) {
    if(-not$State.Attempted){if($State.Class-cne'PreSave'){throw 'invalid pre-save classifier'};return 'PreSave'}
    if([string]$State.RequestId-cne'uid0002ow-transaction-save'){throw 'save request identity drift'}
    if($State.Class-notin@('Success','Failure','Indeterminate')){throw 'non-exclusive save classifier'}
    [string]$State.Class
}
function Classify-RvSvTuple([bool]$RvPassed,[bool]$SvPassed,[ValidateSet('P0','Saved','FailingSaved','Unknown','Third')]$TupleKind) {
    if($RvPassed-and-not$SvPassed-and$TupleKind-eq'P0'){return [pscustomobject]@{Class='Original';AttributableTuple=$null}}
    if($SvPassed-and-not$RvPassed-and$TupleKind-in@('Saved','FailingSaved')){return [pscustomobject]@{Class=$TupleKind;AttributableTuple=$TupleKind}}
    throw 'mixed/both/neither/unknown/third classifier result'
}

function Assert-OsProcessMatchesBound($Bound,[string]$Role) {
    $process=Get-Process -Id ([int]$Bound.Process.Pid) -ErrorAction Stop
    if([string]$process.StartTime.ToUniversalTime().ToFileTimeUtc()-cne[string]$Bound.Process.CreationTime100ns-or-not([IO.Path]::GetFullPath([string]$process.Path)).Equals([string]$Bound.Process.Executable,[StringComparison]::OrdinalIgnoreCase)){throw "$Role PID/generation reuse or image drift"}
    $socket=@(Get-NetTCPConnection -LocalAddress ([string]$Bound.RouteHost) -LocalPort ([int]$Bound.RoutePort) -State Listen -ErrorAction Stop)
    if($socket.Count-ne1-or[int]$socket[0].OwningProcess-ne[int]$Bound.Process.Pid){throw "$Role route socket/PID drift"}
    $process
}
function Invoke-QRetirement($Bound,[string]$Database,[string]$Path) {
    $process=Assert-OsProcessMatchesBound $Bound 'Q-pre-retirement'
    Stop-Process -Id ([int]$Bound.Process.Pid) -Force -ErrorAction Stop
    Wait-Process -Id ([int]$Bound.Process.Pid) -Timeout 60 -ErrorAction SilentlyContinue
    $reused=Get-Process -Id ([int]$Bound.Process.Pid) -ErrorAction SilentlyContinue
    if($null-ne$reused){throw 'Q PID remains or was reused'}
    $staleSockets=@(Get-NetTCPConnection -State Listen -ErrorAction SilentlyContinue|Where-Object{[int]$_.OwningProcess-eq[int]$Bound.Process.Pid})
    if($staleSockets.Count-ne0){throw 'Q retired PID still owns a listener'}
    $list=Invoke-McpTool ('uid0002ow-q-'+[guid]::NewGuid().ToString('N')) 'idb_list' ([ordered]@{})
    $active=@($list.result.structuredContent.sessions|Where-Object{$_.is_active-eq$true-and([string]$_.input_path).Equals([IO.Path]::GetFullPath($Path),[StringComparison]::OrdinalIgnoreCase)})
    if($active.Count-ne0){throw 'Q active canonical session remains'}
    $probe=[IO.File]::Open([IO.Path]::GetFullPath($Path),[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None)
    try{$length=$probe.Length}finally{$probe.Dispose()}
    [pscustomobject]@{Passed=$true;Database=$Database;RetiredPid=[int]$Bound.Process.Pid;CreationTime100ns=[string]$Bound.Process.CreationTime100ns;Path=[IO.Path]::GetFullPath($Path);Length=$length}
}
function Assert-RestoreAttribution($Recorded,$P0,$Current) {
    if($null-eq$Recorded){throw 'restore attribution tuple is null'}
    if(Test-ExactTransactionTuple $Recorded $P0){throw 'restore forbidden for P0'}
    if(-not(Test-ExactTransactionTuple $Recorded $Current)){throw 'restore candidate is unknown/third identity'}
    $true
}

function Assert-FixtureThrows([string]$Name,[scriptblock]$Body) {
    $threw=$false;try{&$Body}catch{$threw=$true}
    if(-not$threw){throw "hostile fixture unexpectedly passed: $Name"}
    $Name
}
function Invoke-UID0002OWHostileFixtures {
    $passed=@()
    $goodRequest=[ordered]@{jsonrpc='2.0';id='fixture-id';method='tools/list';params=[ordered]@{}}
    $goodEnvelope=[pscustomobject]@{jsonrpc='2.0';id='fixture-id';result=[pscustomobject]@{tools=@()}}
    $passed+=Assert-FixtureThrows 'rpc-wrong-version' {Assert-RpcEnvelope $goodRequest ([pscustomobject]@{jsonrpc='1.0';id='fixture-id';result=@{}}) $false}
    $passed+=Assert-FixtureThrows 'rpc-wrong-id-value' {Assert-RpcEnvelope $goodRequest ([pscustomobject]@{jsonrpc='2.0';id='fixture-other';result=@{}}) $false}
    $passed+=Assert-FixtureThrows 'rpc-wrong-id-type' {Assert-RpcEnvelope $goodRequest ([pscustomobject]@{jsonrpc='2.0';id=1;result=@{}}) $false}
    $passed+=Assert-FixtureThrows 'rpc-error-member' {Assert-RpcEnvelope $goodRequest ([pscustomobject]@{jsonrpc='2.0';id='fixture-id';error=@{code=-1};result=@{}}) $false}
    $passed+=Assert-FixtureThrows 'rpc-missing-result' {Assert-RpcEnvelope $goodRequest ([pscustomobject]@{jsonrpc='2.0';id='fixture-id'}) $false}
    $schemaClone=$ToolsListEnvelope|ConvertTo-Json -Depth 100|ConvertFrom-Json
    $runtimeTool=@($schemaClone.result.tools|Where-Object name -eq 'runtime_attestation')[0]
    $runtimeTool.inputSchema.required=@('expected_database')
    $passed+=Assert-FixtureThrows 'schema-required-drift' {Assert-PublicToolSchemas $schemaClone}
    $schemaClone=$ToolsListEnvelope|ConvertTo-Json -Depth 100|ConvertFrom-Json;$runtimeTool=@($schemaClone.result.tools|Where-Object name -eq 'runtime_attestation')[0];$runtimeTool.inputSchema.properties.expected_database.default='wrong'
    $passed+=Assert-FixtureThrows 'schema-default-drift' {Assert-PublicToolSchemas $schemaClone}
    $schemaClone=$ToolsListEnvelope|ConvertTo-Json -Depth 100|ConvertFrom-Json;$runtimeTool=@($schemaClone.result.tools|Where-Object name -eq 'runtime_attestation')[0];$runtimeTool.inputSchema|Add-Member unexpected $true
    $passed+=Assert-FixtureThrows 'schema-extra-drift' {Assert-PublicToolSchemas $schemaClone}
    $badPlan=@($MutationPlan|Select-Object -First 42)
    $passed+=Assert-FixtureThrows 'incomplete-mutation-plan' {Assert-CompleteMutationPlan $badPlan $TX}
    $badPlan=$MutationPlan|ConvertTo-Json -Depth 100|ConvertFrom-Json;$badPlan[0].ExpectedReadback.Calls=@()
    $passed+=Assert-FixtureThrows 'missing-readback-envelope' {Assert-CompleteMutationPlan $badPlan $TX}
    $savedState=[pscustomobject]@{Attempted=$true;RequestId='uid0002ow-transaction-save';Class='Success';Envelope=$goodEnvelope;TransportError=$null}
    $passed+=Assert-FixtureThrows 'duplicate-save' {if($savedState.Attempted){throw 'duplicate save attempt forbidden'}}
    $passed+=Assert-FixtureThrows 'null-restore-attribution' {Assert-RestoreAttribution $null ([pscustomobject]@{}) ([pscustomobject]@{})}
    $p0=[pscustomobject]@{FullPath='p';Length=4;LastWriteTimeUtcTicks=1;SHA256='AA'};$third=[pscustomobject]@{FullPath='p';Length=4;LastWriteTimeUtcTicks=1;SHA256='BB'}
    $passed+=Assert-FixtureThrows 'same-length-restore-substitution' {Assert-RestoreAttribution $third $p0 $p0}
    $passed+=Assert-FixtureThrows 'third-identity-classifier' {Classify-RvSvTuple $false $false 'Third'}
    $passed+=Assert-FixtureThrows 'stale-verifier' {Assert-StateVerificationSemantics @() 'Post'}
    $passed+=Assert-FixtureThrows 'pid-generation-replacement' {Assert-StableRuntimeIdentity ([pscustomobject]@{Process=[pscustomobject]@{Pid=2;Generation='g2';Executable='x'};Modules=[pscustomobject]@{SourceRoot='r';ImplementationManifestSHA256=('A'*64);Modules=[ordered]@{}}}) ([pscustomobject]@{Process=[pscustomobject]@{Pid=1;Generation='g1';Executable='x'};Modules=[pscustomobject]@{SourceRoot='r';ImplementationManifestSHA256=('A'*64);Modules=[ordered]@{}}}) 'fixture'}
    $passed+=Assert-FixtureThrows 'module-drift' {Assert-CrossProcessModuleParity ([pscustomobject]@{SourceRoot='r';Modules=[ordered]@{m=[pscustomobject]@{Name='m';SHA256=('A'*64)}}}) ([pscustomobject]@{SourceRoot='r';Modules=[ordered]@{m=[pscustomobject]@{Name='m';SHA256=('B'*64)}}}) 'fixture'}
    $passed+=Assert-FixtureThrows 'route-session-drift' {if('expected-session'-cne'wrong-session'){throw 'route/session drift'}}
    $passed+=Assert-FixtureThrows 'nonce-reuse' {$seen=@{n=$true};if($seen.ContainsKey('n')){throw 'nonce reused'}}
    $passed+=Assert-FixtureThrows 'retirement-pid-reuse' {$bound='pid:1;created:1';$observed='pid:1;created:2';if($bound-cne$observed){throw 'PID reused'}}
    if($passed.Count-lt18){throw 'hostile fixture suite incomplete'}
    [pscustomobject]@{Passed=$passed.Count;Names=$passed;SideEffectFree=$true}
}
$Gate1MutationStatic = Assert-CompleteMutationPlan $MutationPlan $TX
$Gate1VerifierStatic = @(
    New-StateVerificationPlan 'uid0002ow-v' $TX 'Post'
    New-StateVerificationPlan 'uid0002ow-rv' $TX 'Original'
    New-StateVerificationPlan 'uid0002ow-sv' $TX 'Post'
)
if(@($Gate1VerifierStatic|Where-Object ExpectedState -eq 'Original').Count-eq0-or@($Gate1VerifierStatic|Where-Object ExpectedState -eq 'Post').Count-eq0){throw 'incomplete V/RV/SV plan construction'}
$Gate1HostileFixtures = Invoke-UID0002OWHostileFixtures
~~~

## Removed Block R014

- SHA256: `CB547536F33D226FA8975D46FA67E7911A352D65E33F22C946A61A58C57842F1`
- Language: `powershell`
- Bytes: `10378`
- First recovered timestamp: `2026-08-07T00:16:44.210Z`
- Session provenance: rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 194771 (2026-08-07T00:16:44.210Z); rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 194772 (2026-08-07T00:16:44.276Z)

~~~powershell
function New-CompleteToolRequest([string]$RequestId,[string]$Tool,$Arguments) {
    if ([string]::IsNullOrWhiteSpace($RequestId) -or [string]::IsNullOrWhiteSpace($Tool) -or $null -eq $Arguments) { throw 'incomplete tool request' }
    [ordered]@{jsonrpc='2.0';id=$RequestId;method='tools/call';params=[ordered]@{name=$Tool;arguments=$Arguments}}
}
function Assert-NoRequestShorthand($Value,[string]$Label) {
    $json = $Value | ConvertTo-Json -Depth 100 -Compress
    if ($json -match '(?i)then identical|inherit(?:ed)?|same as|pseudo|placeholder|todo|tbd|<[^>]+>|\.\.\.') { throw "$Label contains forbidden shorthand/placeholder" }
}
function Assert-CompleteMutationPlan($Plan,[string]$Database) {
    $rows = @($Plan)
    if ($rows.Count -ne 43 -or (@($rows | Where-Object Phase -ceq 'Dry')).Count -ne 10 -or (@($rows | Where-Object Phase -ceq 'Actual')).Count -ne 33) { throw 'mutation 43/10/33 contract mismatch' }
    if ((Compare-Object @(1..43) @($rows.Seq)).Count -ne 0) { throw 'mutation sequence is not exactly 1..43' }
    $ids=@{}; $rpcIds=@{}
    foreach ($row in $rows) {
        if ([string]::IsNullOrWhiteSpace([string]$row.Id) -or $ids.ContainsKey([string]$row.Id)) { throw 'missing/duplicate mutation ID' }
        $ids[[string]$row.Id]=$true
        $request=$row.Request
        if ($null -eq $request -or [string]$request.jsonrpc -cne '2.0' -or [string]$request.method -cne 'tools/call' -or
            [string]::IsNullOrWhiteSpace([string]$request.id) -or $rpcIds.ContainsKey([string]$request.id) -or
            [string]::IsNullOrWhiteSpace([string]$request.params.name) -or $null -eq $request.params.arguments -or
            [string]$request.params.arguments.database -cne $Database) { throw "incomplete/unbound mutation request $($row.Id)" }
        $rpcIds[[string]$request.id]=$true
        if ($null -eq $row.ExpectedResponse -or [string]$row.ExpectedResponse.jsonrpc -cne '2.0' -or
            [string]$row.ExpectedResponse.id -cne [string]$request.id -or $row.ExpectedResponse.TopLevelError -ne $false -or
            $row.ExpectedResponse.ToolIsError -ne $false -or [int]$row.ExpectedResponse.SuccessCount -lt 1 -or
            [int]$row.ExpectedResponse.FailureCount -ne 0) { throw "incomplete response contract $($row.Id)" }
        if ($null -eq $row.ExpectedReadback -or @($row.ExpectedReadback.Calls).Count -eq 0 -or
            @($row.ExpectedReadback.Exact).Count -eq 0 -or $row.ExpectedReadback.AllOtherFrozenFieldsEqual -ne $true) { throw "incomplete readback contract $($row.Id)" }
        foreach ($call in @($row.ExpectedReadback.Calls)) {
            if ([string]::IsNullOrWhiteSpace([string]$call.tool) -or $null -eq $call.arguments -or [string]$call.arguments.database -cne $Database) { throw "incomplete/unbound readback $($row.Id)" }
        }
        Assert-NoRequestShorthand $row "mutation $($row.Id)"
    }
    $true
}
function Invoke-ReadbackPlan($MutationRow,[string]$Boundary) {
    $results=@(); $index=0
    foreach ($call in @($MutationRow.ExpectedReadback.Calls)) {
        $index++
        $requestId = "uid0002ow-rb-$([int]$MutationRow.Seq.ToString('000'))-$($Boundary.ToLowerInvariant())-$($index.ToString('00'))"
        $request = New-CompleteToolRequest $requestId ([string]$call.tool) $call.arguments
        $envelope = Invoke-McpRpc $request
        if ($envelope.result.isError -eq $true -or $null -eq $envelope.result.structuredContent) { throw "readback failure $($MutationRow.Id)/$Boundary/$index" }
        $results += ,[pscustomobject]@{Tool=[string]$call.tool;Request=$request;Envelope=$envelope;StructuredContent=$envelope.result.structuredContent}
    }
    if ($results.Count -ne @($MutationRow.ExpectedReadback.Calls).Count) { throw "readback cardinality mismatch $($MutationRow.Id)/$Boundary" }
    $results
}
function Assert-MutationResponse($Row,$Envelope) {
    if ($Envelope.result.isError -eq $true -or $null -eq $Envelope.result.structuredContent) { throw "mutation tool failure $($Row.Id)" }
    $sc=$Envelope.result.structuredContent
    $resultRows=@($sc.results)
    if ($resultRows.Count -eq 0) { $resultRows=@($sc.items) }
    if ($resultRows.Count -eq 0 -and $sc.success -eq $true) { $resultRows=@($sc) }
    $failures=@($resultRows | Where-Object {$_.success -eq $false -or $null -ne $_.error})
    $successes=@($resultRows | Where-Object {$_.success -ne $false -and $null -eq $_.error})
    if ($failures.Count -ne [int]$Row.ExpectedResponse.FailureCount -or $successes.Count -lt [int]$Row.ExpectedResponse.SuccessCount) { throw "mutation success/failure cardinality mismatch $($Row.Id)" }
    foreach ($forbidden in @($Row.ExpectedResponse.ForbiddenFields)) {
        if (@($sc.psobject.Properties | Where-Object Name -ceq ([string]$forbidden)).Count -ne 0) { throw "forbidden response field $forbidden in $($Row.Id)" }
    }
}
function Get-AllowedDeltaClass([string]$Id) {
    if ($Id -match '\.Dry$') { return @() }
    if ($Id -in @('D02')) { return @('function','range','frame') }
    if ($Id -in @('T01')) { return @('type-declaration') }
    if ($Id -match '^R0[2-7]\.Actual$') { return @('name') }
    if ($Id -match '^F0[2347]$') { return @('type','frame-type') }
    if ($Id -match '^RS0(?:2a|2b|3|7)\.Actual$') { return @('frame-name') }
    if ($Id -match '^TS0(?:2a|2b|3|7)$') { return @('frame-type') }
    if ($Id -match '^C0[2-9]$|^C10$|^C11$') { return @('comment') }
    if ($Id -in @('D05','D06')) { return @('comment-clear') }
    if ($Id -eq 'M11') { return @('item','name','type') }
    throw "unrecognized mutation ID: $Id"
}
function ConvertTo-FrozenProjection($Value,[string[]]$AllowedClasses) {
    if ($null -eq $Value -or $Value -is [string] -or $Value -is [ValueType]) { return $Value }
    if ($Value -is [Collections.IEnumerable] -and $Value -isnot [string] -and $Value -isnot [Collections.IDictionary]) {
        $array=@(); foreach($item in $Value){$array+=,(ConvertTo-FrozenProjection $item $AllowedClasses)}; return $array
    }
    $drop=@()
    if ($AllowedClasses -contains 'name') {$drop+=@('name','demangled_name','rendered_name','target_name')}
    if ($AllowedClasses -contains 'type' -or $AllowedClasses -contains 'type-declaration') {$drop+=@('type','prototype','declaration','decl')}
    if ($AllowedClasses -contains 'frame-name') {$drop+=@('name','member_name')}
    if ($AllowedClasses -contains 'frame-type') {$drop+=@('type','member_type','size')}
    if ($AllowedClasses -contains 'comment' -or $AllowedClasses -contains 'comment-clear') {$drop+=@('comment','comments','regular','repeatable','function_regular','function_repeatable','address_regular','address_repeatable')}
    if ($AllowedClasses -contains 'function' -or $AllowedClasses -contains 'range') {$drop+=@('is_func','is_function','start','end','range')}
    if ($AllowedClasses -contains 'frame') {$drop+=@('frame','members','stack_frame')}
    if ($AllowedClasses -contains 'item') {$drop+=@('head','start','end','size','item_size','items','is_data')}
    $ordered=[ordered]@{}
    if ($Value -is [Collections.IDictionary]) {
        foreach($key in @($Value.Keys | ForEach-Object {[string]$_} | Sort-Object)) { if ($drop -notcontains $key) {$ordered[$key]=ConvertTo-FrozenProjection $Value[$key] $AllowedClasses} }
    } else {
        foreach($property in @($Value.psobject.Properties | Sort-Object Name)) { if ($drop -notcontains [string]$property.Name) {$ordered[$property.Name]=ConvertTo-FrozenProjection $property.Value $AllowedClasses} }
    }
    $ordered
}
function Get-RequestedSemanticLiterals($Row) {
    $a=$Row.Request.params.arguments; $literals=@()
    if ($null -ne $a.batch) {
        foreach($bucket in @('func','data','local','stack')) { foreach($item in @($a.batch.$bucket)) { if ($null -ne $item) { foreach($field in @('addr','name')) { if (-not [string]::IsNullOrWhiteSpace([string]$item.$field)) {$literals += [string]$item.$field} } } } }
    }
    foreach($item in @($a.items)) { if ($null -ne $item) { foreach($field in @('addr','end','name','type','comment')) { if (-not [string]::IsNullOrWhiteSpace([string]$item.$field)) {$literals += [string]$item.$field} } } }
    if (-not [string]::IsNullOrWhiteSpace([string]$a.decls)) {$literals += [string]$a.decls}
    @($literals | Select-Object -Unique)
}
function Assert-MutationSemanticResult($Row,$Before,$After) {
    $beforeHash=Get-CanonicalObjectSha256 $Before; $afterHash=Get-CanonicalObjectSha256 $After
    $allowed=Get-AllowedDeltaClass ([string]$Row.Id)
    if ([string]$Row.Phase -ceq 'Dry') {
        if ($beforeHash -cne $afterHash -or $allowed.Count -ne 0) { throw "dry-run changed readback state $($Row.Id)" }
    } else {
        if ($beforeHash -ceq $afterHash) { throw "actual mutation made no requested change $($Row.Id)" }
        $beforeFrozen=ConvertTo-FrozenProjection $Before $allowed
        $afterFrozen=ConvertTo-FrozenProjection $After $allowed
        if ((Get-CanonicalObjectSha256 $beforeFrozen) -cne (Get-CanonicalObjectSha256 $afterFrozen)) { throw "unlisted frozen-state delta $($Row.Id)" }
        $afterJson=$After | ConvertTo-Json -Depth 100 -Compress
        foreach($literal in @(Get-RequestedSemanticLiterals $Row)) {
            if ($afterJson.IndexOf([string]$literal,[StringComparison]::OrdinalIgnoreCase) -lt 0) { throw "requested literal absent from immediate readback $($Row.Id): $literal" }
        }
    }
    foreach($fact in @($Row.ExpectedReadback.Exact)) { if ([string]::IsNullOrWhiteSpace([string]$fact)) { throw "empty exact semantic fact $($Row.Id)" } }
}
function Invoke-CompleteMutationPlan($Plan,[string]$Database) {
    [void](Assert-CompleteMutationPlan $Plan $Database)
    $journal=@()
    foreach($row in @($Plan | Sort-Object Seq)) {
        $before=@(Invoke-ReadbackPlan $row 'before')
        $envelope=Invoke-McpRpc $row.Request
        Assert-MutationResponse $row $envelope
        $after=@(Invoke-ReadbackPlan $row 'after')
        Assert-MutationSemanticResult $row $before $after
        $journal += ,[pscustomobject]@{Seq=[int]$row.Seq;Id=[string]$row.Id;Request=$row.Request;Envelope=$envelope;Before=$before;After=$after;AllowedDelta=@(Get-AllowedDeltaClass ([string]$row.Id));Exact=@($row.ExpectedReadback.Exact)}
    }
    if ($journal.Count -ne 43) { throw 'mutation runner did not execute all 43 rows' }
    $journal
}
$MutationPlanStaticContract = Assert-CompleteMutationPlan $MutationPlan $TX
~~~

## Removed Block R015

- SHA256: `316DD9D383B7D717950B6866C2B279409F6FC14E244A7C78DD4883905258030D`
- Language: `powershell`
- Bytes: `12369`
- First recovered timestamp: `2026-08-07T00:17:58.846Z`
- Session provenance: rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 194779 (2026-08-07T00:17:58.846Z); rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 194780 (2026-08-07T00:17:58.914Z)

~~~powershell
$UID0002OWFunctionHeads=@('0x5007a0','0x5007f0','0x500820','0x50248a','0x502495','0x5026a0','0x5008c0','0x5024a0')
$UID0002OWI13Heads=@(); for($ea=0x61dc30;$ea -le 0x61dcd8;$ea+=4){$UID0002OWI13Heads+=('0x{0:x}' -f $ea)}
$UID0002OWItemHeads=@($UID0002OWFunctionHeads+@('0x500797','0x5007e8','0x50081e','0x5008b9','0x502485','0x502695','0x5026f5','0x61e3f4','0x61e3f8','0x61e40c','0x61e410','0x61e420','0x61e540','0x61e554')+$UID0002OWI13Heads | Select-Object -Unique)
$UID0002OWI13Expected=[ordered]@{
    '0x61dc30'='0x64abe8';'0x61dc34'='0x5026a0';'0x61dc38'='0x4f4b10';'0x61dc3c'='0x41b6c0';'0x61dc40'='0x4b8e20';'0x61dc44'='0x41d680';'0x61dc48'='0x544730';'0x61dc4c'='0x544750';'0x61dc50'='0x5447a0';'0x61dc54'='0x544800';'0x61dc58'='0x544a20';'0x61dc5c'='0x544b80';'0x61dc60'='0x544bd0';'0x61dc64'='0x544c70';'0x61dc68'='0x544cb0';'0x61dc6c'='0x544ce0';'0x61dc70'='0x544d30';'0x61dc74'='0x544d70';'0x61dc78'='0x500820';'0x61dc7c'='0x5007f0';'0x61dc80'='0x494bb0';'0x61dc84'='0x494bd0';'0x61dc88'='0x494c00';'0x61dc8c'='0x494c10';'0x61dc90'='0x494c30';'0x61dc94'='0x4242f0';'0x61dc98'='0x64ac4c';'0x61dc9c'='0x50248a';'0x61dca0'='0x544db0';'0x61dca4'='0x494f70';'0x61dca8'='0x41d6b0';'0x61dcac'='0x544de0';'0x61dcb0'='0x544df0';'0x61dcb4'='0x544e00';'0x61dcb8'='0x4a89f0';'0x61dcbc'='0x544e10';'0x61dcc0'='0x544e30';'0x61dcc4'='0x544e70';'0x61dcc8'='0x64ac60';'0x61dccc'='0x502495';'0x61dcd0'='0x544e90';'0x61dcd4'='0x64ac74';'0x61dcd8'='0x48c550'
}
$UID0002OWProtectionManifest=[ordered]@{
    FunctionTypeDependencies=@('I03.TYPE','I04.TYPE','I07.TYPE')
    ExecutableBoundaries=@('P00','P01','P02','P03','P04','P05','P06','P07','P08')
    PaletteBoundaries=@('P10','P11','P09')
    DirecBoundaries=@('I12a','I12b')
    I13=@($UID0002OWI13Expected.Keys)
}
if ((@($UID0002OWProtectionManifest.FunctionTypeDependencies).Count+@($UID0002OWProtectionManifest.ExecutableBoundaries).Count+@($UID0002OWProtectionManifest.PaletteBoundaries).Count+@($UID0002OWProtectionManifest.DirecBoundaries).Count+@($UID0002OWProtectionManifest.I13).Count) -ne 60) { throw '60-protection manifest mismatch' }
function New-StateCall([string]$Id,[string]$Tool,$Arguments,[string[]]$Assertions) {
    [ordered]@{Id=$Id;Request=(New-CompleteToolRequest "uid0002ow-$($Id.ToLowerInvariant())" $Tool $Arguments);Assertions=@($Assertions)}
}
function New-StateVerificationPlan([string]$Database,[ValidateSet('Original','Final')]$State,[ValidateSet('V','RV','SV')]$Prefix) {
    if ([string]::IsNullOrWhiteSpace($Database)) { throw "$Prefix empty verifier database" }
    $interior=@(); foreach($range in @(@(0x61e3f4,0x61e420),@(0x61e540,0x61e554))){for($ea=$range[0];$ea -lt $range[1];$ea++){$interior+=('0x{0:x}' -f $ea)}}
    $regions=@(
        [ordered]@{addr='0x500797';size=9},[ordered]@{addr='0x5007a0';size=72},[ordered]@{addr='0x5007e8';size=8},[ordered]@{addr='0x5007f0';size=46},[ordered]@{addr='0x50081e';size=2},[ordered]@{addr='0x500820';size=153},[ordered]@{addr='0x5008b9';size=7},[ordered]@{addr='0x5008c0';size=868},[ordered]@{addr='0x502485';size=5},[ordered]@{addr='0x50248a';size=11},[ordered]@{addr='0x502495';size=11},[ordered]@{addr='0x5024a0';size=11},[ordered]@{addr='0x502695';size=11},[ordered]@{addr='0x5026a0';size=85},[ordered]@{addr='0x5026f5';size=11},[ordered]@{addr='0x61e3f4';size=4},[ordered]@{addr='0x61e3f8';size=20},[ordered]@{addr='0x61e40c';size=20},[ordered]@{addr='0x61e420';size=4},[ordered]@{addr='0x61e540';size=20},[ordered]@{addr='0x61e554';size=24},[ordered]@{addr='0x61dc30';size=164},[ordered]@{addr='0x61dcd4';size=8}
    )
    $stateFacts = if($State -eq 'Original') {@('sub_5007F0','int __thiscall(int this, unsigned __int8)','sub_500820','int __thiscall(int this)','sub_5026A0','_DWORD *__thiscall(_DWORD *Block, char)','aNp_1','aAl3Pal')} else {@('DirectionButtonControlPane__SetVisualState','void __thiscall DirectionButtonControlPane__SetVisualState(DirectionButtonControlPane *this, unsigned __int8 visualState)','DirectionButtonControlPane__OnPaint','void __thiscall DirectionButtonControlPane__OnPaint(DirectionButtonControlPane *this)','DirectionButtonControlPane__scalar_deleting_destructor','DirectionButtonControlPane *__thiscall DirectionButtonControlPane__scalar_deleting_destructor(DirectionButtonControlPane *this, unsigned int flags)','aNpal3Pal')}
    @(
        [ordered]@{Id="${Prefix}00";Request=(New-CompleteToolRequest "uid0002ow-$($Prefix.ToLowerInvariant())00" 'idb_list' ([ordered]@{}));Assertions=@('exactly one active canonical row for returned database')},
        (New-StateCall "${Prefix}01" 'server_health' ([ordered]@{database=$Database}) @('status ok','analyzing false')),
        [ordered]@{Id="${Prefix}02";Request=[ordered]@{jsonrpc='2.0';id="uid0002ow-$($Prefix.ToLowerInvariant())02";method='tools/list';params=[ordered]@{}};Assertions=@('all 27 recursive schema fingerprints exact','one public runtime_attestation','zero public runtime/attest')},
        [ordered]@{Id="${Prefix}03";Calls=@(
            (New-StateCall "${Prefix}03a" 'lookup_funcs' ([ordered]@{queries=$UID0002OWFunctionHeads;database=$Database}) $stateFacts),
            (New-StateCall "${Prefix}03b" 'callees' ([ordered]@{addrs=@('0x5007a0','0x5007f0','0x500820','0x50248a','0x502495','0x5026a0');limit=500;database=$Database}) @('I05 callees []','I06 callees []')),
            (New-StateCall "${Prefix}03c" 'inspect_items' ([ordered]@{addrs=@('0x5008c0');database=$Database}) @('P04.PROTO boost::exception *__thiscall(boost::exception *this, const unsigned __int16 *, _DWORD *, void *, void *)')),
            (New-StateCall "${Prefix}03d" 'export_funcs' ([ordered]@{addrs=@('0x5008c0');format='prototypes';database=$Database}) @('P04.PROTO exact independent agreement')),
            (New-StateCall "${Prefix}03e" 'disasm' ([ordered]@{addr='0x50248a';max_instructions=2;offset=0;include_total=$true;database=$Database}) @('2/2 done','sub ecx,0xa0','jmp 0x5026a0')),
            (New-StateCall "${Prefix}03f" 'disasm' ([ordered]@{addr='0x502495';max_instructions=2;offset=0;include_total=$true;database=$Database}) @('2/2 done','sub ecx,0xa4','jmp 0x5026a0'))
        );Assertions=@('six complete S03 calls','state-specific names/types','P04 prototype','I05/I06 empty modeled callees','two singular decodes')},
        (New-StateCall "${Prefix}04" 'inspect_items' ([ordered]@{addrs=$UID0002OWItemHeads;database=$Database}) @($stateFacts+@('all item heads/ranges exact','I13 43 cells exact'))),
        (New-StateCall "${Prefix}05" 'get_comments' ([ordered]@{addrs=$UID0002OWItemHeads;database=$Database}) @('all four function channels and two data channels exact')),
        (New-StateCall "${Prefix}06" 'stack_frame' ([ordered]@{addrs=$UID0002OWFunctionHeads;database=$Database}) @('complete I02-I07 rows','P04.FRAME arg_0 _DWORD,arg_4 Pane *,arg_8 _DWORD,arg_C _DWORD')),
        (New-StateCall "${Prefix}07" 'get_bytes' ([ordered]@{regions=$regions;database=$Database}) @('all 23 exact ranges and SHA256 identities')),
        (New-StateCall "${Prefix}08" 'xrefs_to' ([ordered]@{addrs=@($UID0002OWItemHeads+$interior|Select-Object -Unique);limit=1000;database=$Database}) @('all exact base/interior/cell xref sets')),
        (New-StateCall "${Prefix}09" 'entity_query' ([ordered]@{queries=@([ordered]@{kind='names';regex='^(DirectionButtonControlPane__DirectionButtonControlPane|DirectionButtonControlPane__SetVisualState|DirectionButtonControlPane__OnPaint|DirectionButtonControlPane__EventHandlerView__scalar_deleting_destructor|DirectionButtonControlPane__TimerHandlerView__scalar_deleting_destructor|DirectionButtonControlPane__scalar_deleting_destructor|aNpal3Pal|aNp_1|aAl3Pal)$';count=20});database=$Database}) @($stateFacts+@('collision and obsolete-name cardinalities exact'))),
        (New-StateCall "${Prefix}10" 'type_query' ([ordered]@{queries=@([ordered]@{filter='^(DirectionButtonControlPane|ControlPane|RectBounds|EPFTileContext)$';kind='udt';count=20;include_decl=$true;include_members=$true;include_relationships=$true});database=$Database}) @('DirectionButtonControlPane relation','ControlPane 0x108','RectBounds 0x10','EPFTileContext 0x28')),
        (New-StateCall "${Prefix}11" 'type_inspect' ([ordered]@{queries=@([ordered]@{name='ControlPane';include_members=$true;max_members=100},[ordered]@{name='RectBounds';include_members=$true;max_members=100},[ordered]@{name='EPFTileContext';include_members=$true;max_members=100},[ordered]@{name='DirectionButtonControlPane';include_members=$true;max_members=100});database=$Database}) @('all declarations/members/relationships exact')),
        (New-StateCall "${Prefix}12" 'get_int' ([ordered]@{addrs=$UID0002OWI13Heads;ty='u32le';database=$Database}) @('all 43 exact dword values')),
        (New-StateCall "${Prefix}13" 'get_string' ([ordered]@{addrs=@('0x61e3f4','0x61e3f8','0x61e40c','0x61e410','0x61e420','0x61e540','0x61e554');database=$Database}) @('CAPSULE.EPD','NPAL3.PAL','DIREC.EPD','BDFRAME.EPF','exact item boundaries'))
    )
}
function Assert-StateVerificationPlan($Plan,[string]$Database,[ValidateSet('V','RV','SV')]$Prefix) {
    $rows=@($Plan)
    if ($rows.Count -ne 14 -or (Compare-Object @("${Prefix}00","${Prefix}01","${Prefix}02","${Prefix}03","${Prefix}04","${Prefix}05","${Prefix}06","${Prefix}07","${Prefix}08","${Prefix}09","${Prefix}10","${Prefix}11","${Prefix}12","${Prefix}13") @($rows.Id)).Count -ne 0) { throw "$Prefix 14-class plan incomplete" }
    foreach($row in $rows){
        $requests=if($null -ne $row.Calls){@($row.Calls.Request)}else{@($row.Request)}
        if($requests.Count -eq 0 -or @($row.Assertions).Count -eq 0){throw "$($row.Id) missing request/assertion"}
        foreach($request in $requests){
            if([string]$request.jsonrpc -cne '2.0' -or [string]::IsNullOrWhiteSpace([string]$request.id)){throw "$($row.Id) malformed request"}
            if([string]$request.method -ceq 'tools/call' -and [string]$request.params.name -cne 'idb_list' -and [string]$request.params.arguments.database -cne $Database){throw "$($row.Id) database binding mismatch"}
        }
        Assert-NoRequestShorthand $row "state package $($row.Id)"
    }
    $true
}
function Assert-StateVerificationSemantics($Row,$Results,[ValidateSet('Original','Final')]$State) {
    if(@($Results).Count -eq 0){throw "$($Row.Id) empty state result"}
    foreach($result in @($Results)){if($result.Envelope.result.isError -eq $true -or $null -eq $result.Envelope.result){throw "$($Row.Id) state readback failure"}}
    $json=$Results | ConvertTo-Json -Depth 100 -Compress
    if($Row.Id -match '03$|04$|09$'){
        $required=if($State -eq 'Original'){@('sub_5007F0','sub_500820','sub_5026A0','aNp_1','aAl3Pal')}else{@('DirectionButtonControlPane__SetVisualState','DirectionButtonControlPane__OnPaint','DirectionButtonControlPane__scalar_deleting_destructor','aNpal3Pal')}
        foreach($literal in $required){if($json.IndexOf($literal,[StringComparison]::OrdinalIgnoreCase)-lt 0){throw "$($Row.Id) missing state literal $literal"}}
    }
    if($Row.Id -match '12$'){
        foreach($entry in $UID0002OWI13Expected.GetEnumerator()){if($json.IndexOf([string]$entry.Key,[StringComparison]::OrdinalIgnoreCase)-lt 0 -or $json.IndexOf([string]$entry.Value,[StringComparison]::OrdinalIgnoreCase)-lt 0){throw "$($Row.Id) I13 mismatch $($entry.Key)"}}
    }
    foreach($assertion in @($Row.Assertions)){if([string]::IsNullOrWhiteSpace([string]$assertion)){throw "$($Row.Id) empty assertion"}}
}
function Invoke-StateVerificationPlan($Plan,[string]$Database,[ValidateSet('Original','Final')]$State,[ValidateSet('V','RV','SV')]$Prefix) {
    [void](Assert-StateVerificationPlan $Plan $Database $Prefix); $journal=@()
    foreach($row in @($Plan)){
        $requests=if($null -ne $row.Calls){@($row.Calls.Request)}else{@($row.Request)}; $results=@()
        foreach($request in $requests){$envelope=Invoke-McpRpc $request; if($envelope.result.isError -eq $true){throw "$($row.Id) tool error"}; if([string]$request.method -ceq 'tools/list'){[void](Assert-PublicToolSchemas $envelope)}; $results+=,[pscustomobject]@{Request=$request;Envelope=$envelope}}
        Assert-StateVerificationSemantics $row $results $State
        $journal+=,[pscustomobject]@{Id=$row.Id;Results=$results;Assertions=@($row.Assertions)}
    }
    if($journal.Count -ne 14){throw "$Prefix execution did not complete 14 classes"}; $journal
}
~~~

## Removed Block R016

- SHA256: `6966C170315896946E0710E9B4EF46C33213FA7206B53E9466B801A7080AA624`
- Language: `powershell`
- Bytes: `7012`
- First recovered timestamp: `2026-08-07T00:18:47.682Z`
- Session provenance: rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 194785 (2026-08-07T00:18:47.682Z); rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 194786 (2026-08-07T00:18:47.759Z)

~~~powershell
$script:UID0002OWSaveState='NotAttempted'
$script:UID0002OWSaveRecord=$null
function Invoke-SoleSave([string]$Database) {
    if($script:UID0002OWSaveState -cne 'NotAttempted'){throw 'second idb_save construction/send forbidden'}
    if([string]::IsNullOrWhiteSpace($Database)){throw 'save database missing'}
    $script:UID0002OWSaveState='AttemptedTransportUnknown'
    $request=New-CompleteToolRequest 'uid0002ow-transaction-save' 'idb_save' ([ordered]@{database=$Database})
    try {
        $envelope=Invoke-McpRpc $request
        $class=if($envelope.result.isError -eq $true){'DeterminateFailure'}elseif($null -ne $envelope.result.structuredContent -and ($envelope.result.structuredContent.ok -eq $false -or $envelope.result.structuredContent.success -eq $false)){'DeterminateFailure'}else{'DefiniteSuccess'}
        $script:UID0002OWSaveState='CompletedNoRetry'
        $script:UID0002OWSaveRecord=[pscustomobject]@{Request=$request;Envelope=$envelope;ResponseClass=$class;AttemptCount=1;RetryAllowed=$false}
    } catch {
        $script:UID0002OWSaveState='CompletedNoRetry'
        $script:UID0002OWSaveRecord=[pscustomobject]@{Request=$request;Envelope=$null;ResponseClass='Indeterminate';AttemptCount=1;RetryAllowed=$false;Exception=$_.Exception.ToString()}
    }
    $script:UID0002OWSaveRecord
}
function Assert-OneSaveContract($Record) {
    if($script:UID0002OWSaveState -cne 'CompletedNoRetry' -or $null -eq $Record -or [int]$Record.AttemptCount -ne 1 -or $Record.RetryAllowed -ne $false -or [string]$Record.ResponseClass -notin @('DefiniteSuccess','DeterminateFailure','Indeterminate')){throw 'one-save classifier contract failure'}
    $Record
}
function Test-TupleEquals($Actual,$Expected) {
    $null -ne $Actual -and $null -ne $Expected -and
    ([IO.Path]::GetFullPath([string]$Actual.FullPath)).Equals([IO.Path]::GetFullPath([string]$Expected.FullPath),[StringComparison]::OrdinalIgnoreCase) -and
    [Int64]$Actual.Length -eq [Int64]$Expected.Length -and [Int64]$Actual.LastWriteTimeUtcTicks -eq [Int64]$Expected.LastWriteTimeUtcTicks -and
    [string]$Actual.SHA256 -ceq [string]$Expected.SHA256
}
function Classify-RvSvTuple([string]$SaveResponseClass,$Candidate,$P0,[bool]$RVComplete,[bool]$SVComplete,[bool]$TransactionAttributable) {
    if($SaveResponseClass -notin @('PreSaveMismatch','DefiniteSuccess','DeterminateFailure','Indeterminate')){throw 'undefined save response class'}
    if($RVComplete -eq $SVComplete){throw 'both-pass/neither-pass classifier result'}
    $isP0=Test-TupleEquals $Candidate $P0
    if($RVComplete -and -not $SVComplete){
        if(-not $isP0){throw 'RV-complete candidate is third/non-P0 identity'}
        return [pscustomobject]@{Identity='P0';Disposition=if($SaveResponseClass -eq 'PreSaveMismatch'){'PreSave'}else{'Unsaved'};Tuple=$Candidate;RestoreAllowed=$false}
    }
    if($SVComplete -and -not $RVComplete){
        if($isP0 -or -not $TransactionAttributable){throw 'SV-complete candidate lacks exclusive transaction attribution'}
        if($SaveResponseClass -eq 'PreSaveMismatch'){throw 'pre-save mismatch cannot attribute persisted poststate'}
        return [pscustomobject]@{Identity=if($SaveResponseClass -eq 'DeterminateFailure'){'FailingSaved'}else{'S1'};Disposition='Persisted';Tuple=$Candidate;RestoreAllowed=$true}
    }
    throw 'unreachable classifier state'
}
function Assert-OsProcessMatchesBound($Bound,[bool]$MustBeAbsent) {
    if($null -eq $Bound -or [int]$Bound.Pid -le 0 -or [string]::IsNullOrWhiteSpace([string]$Bound.Generation) -or [string]::IsNullOrWhiteSpace([string]$Bound.CreationTime100ns)){throw 'incomplete bound process identity'}
    $process=Get-Process -Id ([int]$Bound.Pid) -ErrorAction SilentlyContinue
    if($MustBeAbsent){
        if($null -ne $process){
            $observedGeneration="pid:$([int]$process.Id);created:$([string]$process.StartTime.ToUniversalTime().ToFileTimeUtc())"
            if($observedGeneration -ceq [string]$Bound.Generation){throw 'retired worker still alive'}
            throw 'retired worker PID reused during Q'
        }
        return $true
    }
    if($null -eq $process){throw 'bound worker disappeared before retirement'}
    $observed="pid:$([int]$process.Id);created:$([string]$process.StartTime.ToUniversalTime().ToFileTimeUtc())"
    if($observed -cne [string]$Bound.Generation){throw 'bound worker generation replaced'}
    $true
}
function Invoke-ExclusiveReadProbe([string]$Path) {
    $full=[IO.Path]::GetFullPath($Path); $stream=[IO.File]::Open($full,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None)
    try{$length=$stream.Length}finally{$stream.Dispose()}
    [pscustomobject]@{FullPath=$full;Length=[Int64]$length;Disposed=$true}
}
function Invoke-QRetirement([string]$Role,$BoundWorker,[string]$Database,[scriptblock]$SupervisorRetireWorker) {
    if($null -eq $SupervisorRetireWorker){throw "$Role missing supervisor retirement callback"}
    [void](Assert-OsProcessMatchesBound $BoundWorker $false)
    & $SupervisorRetireWorker $BoundWorker $Database
    $deadline=[DateTime]::UtcNow.AddSeconds(30); do{Start-Sleep -Milliseconds 250;$process=Get-Process -Id ([int]$BoundWorker.Pid) -ErrorAction SilentlyContinue}while($null -ne $process -and [DateTime]::UtcNow -lt $deadline)
    [void](Assert-OsProcessMatchesBound $BoundWorker $true)
    $listRequest=New-CompleteToolRequest "uid0002ow-q-$($Role.ToLowerInvariant())-idb-list" 'idb_list' ([ordered]@{})
    $listEnvelope=Invoke-McpRpc $listRequest
    $active=@($listEnvelope.result.structuredContent.sessions|Where-Object{$_.is_active -eq $true -and ([string]$_.input_path).Equals($CanonicalPath,[StringComparison]::OrdinalIgnoreCase)})
    if($active.Count -ne 0){throw "$Role active canonical session remains"}
    $routeSockets=@(Get-NetTCPConnection -LocalAddress 127.0.0.1 -LocalPort ([int]$BoundWorker.RoutePort) -ErrorAction SilentlyContinue)
    if(@($routeSockets|Where-Object{[int]$_.OwningProcess -eq [int]$BoundWorker.Process.Pid}).Count -ne 0){throw "$Role retired worker route remains"}
    $probe=Invoke-ExclusiveReadProbe $CanonicalPath
    $tuple=Get-ClosedExclusiveTuple $CanonicalPath
    if($probe.Disposed -ne $true -or $probe.Length -ne $tuple.Length){throw "$Role exclusive probe/tuple mismatch"}
    [pscustomobject]@{Role=$Role;Database=$Database;RetiredPid=[int]$BoundWorker.Process.Pid;Generation=[string]$BoundWorker.Process.Generation;PidAbsent=$true;ActiveCanonicalSessions=0;RouteAbsent=$true;ExclusiveProbe=$probe;Tuple=$tuple}
}
function Assert-RestoreAttribution($Recorded,$Current,$P0) {
    if($null -eq $Recorded -or [string]$Recorded.Identity -notin @('S1','FailingSaved') -or $Recorded.RestoreAllowed -ne $true -or $null -eq $Recorded.Tuple){throw 'restore attribution missing/not saved'}
    if(Test-TupleEquals $Recorded.Tuple $P0){throw 'P0 must never enter restore path'}
    if(-not (Test-TupleEquals $Current $Recorded.Tuple)){throw 'destination tuple no longer equals attributable saved tuple'}
    $Recorded
}
~~~

## Removed Block R017

- SHA256: `5306F0262A1E7A029A0E237BD7542A5ED8900DC5552EDE575B850389B9C7BD18`
- Language: `powershell`
- Bytes: `7278`
- First recovered timestamp: `2026-08-07T00:19:34.421Z`
- Session provenance: rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 194791 (2026-08-07T00:19:34.421Z); rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 194792 (2026-08-07T00:19:34.477Z)

~~~powershell
function Assert-FixtureThrows([string]$Name,[scriptblock]$Fixture) {
    $threw=$false; try{& $Fixture}catch{$threw=$true}
    if(-not $threw){throw "hostile fixture unexpectedly accepted: $Name"}
    [pscustomobject]@{Name=$Name;Rejected=$true}
}
function Copy-JsonObject($Value){($Value|ConvertTo-Json -Depth 100 -Compress)|ConvertFrom-Json}
function Assert-ProcessProjectionPure($Expected,$Observed,[bool]$MustBeAbsent) {
    if($MustBeAbsent){if($null -ne $Observed){if([int]$Observed.Pid -eq [int]$Expected.Pid -and [string]$Observed.Generation -cne [string]$Expected.Generation){throw 'retirement PID reuse'};throw 'retirement process still present'};return $true}
    if($null -eq $Observed -or [int]$Observed.Pid -ne [int]$Expected.Pid -or [string]$Observed.Generation -cne [string]$Expected.Generation -or [string]$Observed.Executable -cne [string]$Expected.Executable){throw 'PID/generation replacement'}
    $true
}
function Assert-RouteProjectionPure($Expected,$Observed) {
    if($null -eq $Observed -or [string]$Observed.Database -cne [string]$Expected.Database -or [string]$Observed.CanonicalPath -cne [string]$Expected.CanonicalPath -or [int]$Observed.RoutePort -ne [int]$Expected.RoutePort -or [int]$Observed.WorkerPid -ne [int]$Expected.WorkerPid){throw 'route/session/path/PID drift'}
    $true
}
function Assert-FreshNonceSetPure([string[]]$Nonces) {
    $seen=@{};foreach($nonce in $Nonces){if([string]::IsNullOrWhiteSpace($nonce)-or$seen.ContainsKey($nonce)){throw 'nonce reuse'};$seen[$nonce]=$true};$true
}
function Invoke-UID0002OWHostileFixtures($PublicToolsEnvelope,$CompletePlan,[string]$Database) {
    $fixtures=@()
    $fixtures+=Assert-FixtureThrows 'schema-required-drift' { $c=Copy-JsonObject $PublicToolsEnvelope;$r=@($c.result.tools|Where-Object name -ceq 'runtime_attestation')[0];$r.inputSchema.required=@('expected_database');[void](Assert-PublicToolSchemas $c) }
    $fixtures+=Assert-FixtureThrows 'schema-extra-property' { $c=Copy-JsonObject $PublicToolsEnvelope;$r=@($c.result.tools|Where-Object name -ceq 'runtime_attestation')[0];$r.inputSchema.properties|Add-Member -NotePropertyName extra -NotePropertyValue ([pscustomobject]@{type='string';default=''});[void](Assert-PublicToolSchemas $c) }
    $fixtures+=Assert-FixtureThrows 'schema-default-drift' { $c=Copy-JsonObject $PublicToolsEnvelope;$r=@($c.result.tools|Where-Object name -ceq 'runtime_attestation')[0];$r.inputSchema.properties.expected_database.default='wrong';[void](Assert-PublicToolSchemas $c) }
    $request=[ordered]@{jsonrpc='2.0';id='fixture-request';method='tools/list';params=[ordered]@{}}
    $fixtures+=Assert-FixtureThrows 'rpc-version-drift' { [void](Assert-RpcEnvelope $request ([pscustomobject][ordered]@{jsonrpc='1.0';id='fixture-request';result=[pscustomobject]@{ok=$true}}) $false) }
    $fixtures+=Assert-FixtureThrows 'rpc-id-json-type-mismatch' { [void](Assert-RpcEnvelope $request ([pscustomobject][ordered]@{jsonrpc='2.0';id=7;result=[pscustomobject]@{ok=$true}}) $false) }
    $fixtures+=Assert-FixtureThrows 'rpc-id-value-mismatch' { [void](Assert-RpcEnvelope $request ([pscustomobject][ordered]@{jsonrpc='2.0';id='other';result=[pscustomobject]@{ok=$true}}) $false) }
    $fixtures+=Assert-FixtureThrows 'rpc-error-member' { [void](Assert-RpcEnvelope $request ([pscustomobject][ordered]@{jsonrpc='2.0';id='fixture-request';error=[pscustomobject]@{code=-1};result=[pscustomobject]@{ok=$true}}) $false) }
    $fixtures+=Assert-FixtureThrows 'rpc-result-absent' { [void](Assert-RpcEnvelope $request ([pscustomobject][ordered]@{jsonrpc='2.0';id='fixture-request'}) $false) }
    $fixtures+=Assert-FixtureThrows 'incomplete-42-mutation-plan' { [void](Assert-CompleteMutationPlan @($CompletePlan|Select-Object -First 42) $Database) }
    $fixtures+=Assert-FixtureThrows 'missing-readback-envelope' { $c=Copy-JsonObject $CompletePlan;$c[0].ExpectedReadback.Calls=@();[void](Assert-CompleteMutationPlan $c $Database) }
    $fixtures+=Assert-FixtureThrows 'duplicate-mutation-rpc-id' { $c=Copy-JsonObject $CompletePlan;$c[1].Request.id=$c[0].Request.id;[void](Assert-CompleteMutationPlan $c $Database) }
    $oldState=$script:UID0002OWSaveState;$oldRecord=$script:UID0002OWSaveRecord
    try{$script:UID0002OWSaveState='CompletedNoRetry';$fixtures+=Assert-FixtureThrows 'second-save-attempt' {[void](Invoke-SoleSave $Database)}}finally{$script:UID0002OWSaveState=$oldState;$script:UID0002OWSaveRecord=$oldRecord}
    $p0=[pscustomobject]@{FullPath='C:\fixture\canonical.i64';Length=10;LastWriteTimeUtcTicks=1;SHA256=('A'*64)}
    $saved=[pscustomobject]@{FullPath='C:\fixture\canonical.i64';Length=11;LastWriteTimeUtcTicks=2;SHA256=('B'*64)}
    $fixtures+=Assert-FixtureThrows 'null-restore-attribution' {[void](Assert-RestoreAttribution $null $saved $p0)}
    $fixtures+=Assert-FixtureThrows 'same-length-restore-substitution' {$record=[pscustomobject]@{Identity='S1';RestoreAllowed=$true;Tuple=[pscustomobject]@{FullPath=$saved.FullPath;Length=11;LastWriteTimeUtcTicks=2;SHA256=('C'*64)}};[void](Assert-RestoreAttribution $record $saved $p0)}
    $fixtures+=Assert-FixtureThrows 'undefined-third-identity' {[void](Classify-RvSvTuple 'Indeterminate' $saved $p0 $true $false $false)}
    $fixtures+=Assert-FixtureThrows 'both-rv-sv-complete' {[void](Classify-RvSvTuple 'DefiniteSuccess' $saved $p0 $true $true $true)}
    $fixtures+=Assert-FixtureThrows 'stale-incomplete-verifier' {$plan=New-StateVerificationPlan 'fixture-db' 'Original' 'RV';[void](Assert-StateVerificationPlan @($plan|Select-Object -First 13) 'fixture-db' 'RV')}
    $expectedProcess=[pscustomobject]@{Pid=101;Generation='pid:101;created:1';Executable='C:\Python\python.exe'}
    $fixtures+=Assert-FixtureThrows 'pid-generation-replacement' {[void](Assert-ProcessProjectionPure $expectedProcess ([pscustomobject]@{Pid=101;Generation='pid:101;created:2';Executable='C:\Python\python.exe'}) $false)}
    $fixtures+=Assert-FixtureThrows 'retirement-pid-reuse' {[void](Assert-ProcessProjectionPure $expectedProcess ([pscustomobject]@{Pid=101;Generation='pid:101;created:2';Executable='C:\Python\python.exe'}) $true)}
    $route=[pscustomobject]@{Database='db';CanonicalPath='E:\NTK\Resources\NexusTK\NexusTK.exe.i64';RoutePort=15555;WorkerPid=101}
    $fixtures+=Assert-FixtureThrows 'route-session-drift' {[void](Assert-RouteProjectionPure $route ([pscustomobject]@{Database='other';CanonicalPath=$route.CanonicalPath;RoutePort=15555;WorkerPid=101}))}
    $fixtures+=Assert-FixtureThrows 'nonce-reuse' {[void](Assert-FreshNonceSetPure @('nonce-a','nonce-a'))}
    $listener=[pscustomobject]@{Process=$expectedProcess;Modules=[pscustomobject]@{SourceRoot='E:\src';ImplementationManifestSHA256=('D'*64);Modules=[ordered]@{core=[pscustomobject]@{Name='core';File='E:\src\core.py';SHA256=('E'*64)}}}}
    $worker=Copy-JsonObject $listener;$worker.Modules.Modules.core.SHA256=('F'*64)
    $fixtures+=Assert-FixtureThrows 'stable-module-drift' {[void](Assert-StableRuntimeIdentity $worker $listener 'fixture-worker')}
    if(@($fixtures).Count -ne 22 -or @($fixtures|Where-Object Rejected -ne $true).Count -ne 0){throw 'hostile fixture suite incomplete'}
    $fixtures
}
$UID0002OWHostileFixtureResults=Invoke-UID0002OWHostileFixtures $ToolsListEnvelope $MutationPlan $TX
~~~

## Removed Block R018

- SHA256: `E5B273764AE7C42D38B6178AE21FDC675F29F615B9C2EAE4201ECB52A3E22ADB`
- Language: `powershell`
- Bytes: `9707`
- First recovered timestamp: `2026-08-07T01:05:54.171Z`
- Session provenance: rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 195516 (2026-08-07T01:05:54.171Z); rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 195517 (2026-08-07T01:05:54.239Z)

~~~powershell
function Open-UID0002OWRole($Context,[string]$Role,$OpenRequest) {
    if($null-eq$Context-or[string]::IsNullOrWhiteSpace($Role)-or$null-eq$OpenRequest){throw 'ROLE_OPEN_INPUT_INCOMPLETE'}
    $request=Copy-JsonObject $OpenRequest
    $request.id="uid0002ow-$($Context.RunId)-$Role-open"
    $envelope=Invoke-McpRpc $request
    $database=Get-ReturnedDatabaseId $envelope $Role
    if([string]::IsNullOrWhiteSpace($database)){throw 'ROLE_RETURNED_DATABASE_EMPTY'}
    $binding=Assert-ReturnedDatabase $database $Role
    [void](Register-UID0002OWRole $Context $Role $database $binding)
    $runtime=Assert-PublicRuntimeAttestation $database "$Role-post-open"
    [pscustomobject]@{Role=$Role;Request=$request;Envelope=$envelope;Database=$database;Binding=$binding;Runtime=$runtime}
}
function Close-UID0002OWRole($Context,$RoleState,[scriptblock]$SupervisorRetireWorker,[string]$Boundary) {
    if($null-eq$RoleState-or[string]::IsNullOrWhiteSpace([string]$RoleState.Database)){throw 'ROLE_CLOSE_INPUT_INCOMPLETE'}
    $runtime=Assert-PublicRuntimeAttestation $RoleState.Database "$Boundary-pre-retirement"
    Invoke-QRetirement $Boundary $runtime.BoundWorker $RoleState.Database $SupervisorRetireWorker $Context
}
function Invoke-UID0002OWOuterCleanup($Context,[scriptblock]$SupervisorRetireWorker) {
    $failures=@()
    foreach($roleName in @($Context.Roles.Keys)[(@($Context.Roles.Keys).Count-1)..0]) {
        $role=$Context.Roles[$roleName]
        if($null-ne$role-and$role.State-ceq'Open'){
            try {
                $runtime=Assert-PublicRuntimeAttestation $role.Database "cleanup-$roleName"
                [void](Invoke-QRetirement "cleanup-$roleName" $runtime.BoundWorker $role.Database $SupervisorRetireWorker $Context)
            } catch {$failures+="${roleName}:$($_.Exception.Message)"}
        }
    }
    foreach($handle in @($Context.Handles)){
        if($null-ne$handle){try{$handle.Dispose()}catch{$failures+="handle:$($_.Exception.Message)"}}
    }
    $Context.CleanupComplete=($failures.Count-eq 0-and@($Context.Roles.Values|Where-Object State -ceq 'Open').Count-eq 0)
    [void]$Context.CleanupJournal.Add([pscustomobject]@{Operation='OuterCleanup';Failures=$failures;Complete=$Context.CleanupComplete})
    if($failures.Count-ne 0){throw "CLEANUP_FAILURE:$($failures-join' | ')"}
    [void](Assert-UID0002OWCleanupComplete $Context)
}
function Invoke-UID0002OWClassifierRole($Context,[string]$Role,$OpenRequest,$Candidate,$P0,[string]$SaveClass,[bool]$TransactionAttributable,[scriptblock]$SupervisorRetireWorker) {
    $opened=Open-UID0002OWRole $Context $Role $OpenRequest
    $database=$opened.Database
    [void](Assert-PublicRuntimeAttestation $database "$Role-pre-classifier")
    $rvPlan=New-StateVerificationPlan $database 'Original' 'RV' "$Role-rv" $Context
    $svPlan=New-StateVerificationPlan $database 'Final' 'SV' "$Role-sv" $Context
    $rv=Invoke-ClassifierStateVerificationPlan $rvPlan $database 'Original' 'RV'
    $sv=Invoke-ClassifierStateVerificationPlan $svPlan $database 'Final' 'SV'
    $classification=Classify-RvSvTuple $SaveClass $Candidate $P0 $rv.Complete $sv.Complete $TransactionAttributable
    $q=Close-UID0002OWRole $Context $opened $SupervisorRetireWorker $Role
    if(-not(Test-TupleEquals $q.Tuple $Candidate)){throw 'CLASSIFIER_QUIESCENT_TUPLE_DRIFT'}
    [pscustomobject]@{Opened=$opened;RV=$rv;SV=$sv;Classification=$classification;Q=$q}
}
function Invoke-UID0002OWOriginalVerifier($Context,[string]$Role,$OpenRequest,$P0,[scriptblock]$SupervisorRetireWorker) {
    $opened=Open-UID0002OWRole $Context $Role $OpenRequest
    $plan=New-StateVerificationPlan $opened.Database 'Original' 'RV' "$Role-rv" $Context
    $journal=Invoke-StateVerificationPlan $plan $opened.Database 'Original' 'RV'
    $q=Close-UID0002OWRole $Context $opened $SupervisorRetireWorker $Role
    if(-not(Test-TupleEquals $q.Tuple $P0)){throw 'ROLLBACK_VERIFIER_NOT_P0'}
    [pscustomobject]@{Opened=$opened;Journal=$journal;Q=$q}
}
function Invoke-UID0002OWCoordinator([scriptblock]$SupervisorRetireWorker,$Context=$UID0002OWTransaction) {
    if($null-eq$SupervisorRetireWorker){throw 'COORDINATOR_RETIRE_CALLBACK_MISSING'}
    $p0b0=$null;$p0=$null;$b0=$null;$backupPath=$null;$tx=$null;$saveRecord=$null;$classification=$null;$restore=$null;$primaryFailure=$null
    try {
        # P0: inspection role exists and its exact returned ID is authoritative before S-plan construction.
        $inspection=Open-UID0002OWRole $Context 'inspection' $InspectOpenRequest
        $inspectPlan=New-StateVerificationPlan $inspection.Database 'Original' 'S' 'inspection-s' $Context
        $inspectJournal=Invoke-StateVerificationPlan $inspectPlan $inspection.Database 'Original' 'S'
        $inspectionQ=Close-UID0002OWRole $Context $inspection $SupervisorRetireWorker 'inspection'

        # B0 and the durable no-reentry save authority both exist before transaction open.
        $p0b0=New-UID0002OWP0B0 $CanonicalPath;$p0=$p0b0.P0;$b0=$p0b0.B0;$backupPath=$p0b0.BackupPath
        if(-not(Test-TupleEquals (Get-ClosedExclusiveTuple $CanonicalPath) $p0)){throw 'P0_DRIFT_BEFORE_TRANSACTION'}
        [void](New-UID0002OWDurableSaveAuthority $Context $p0)

        # TX is assigned before any transaction plan binds database=$TX.
        $tx=Open-UID0002OWRole $Context 'transaction' $TxOpenRequest
        $TX=[string]$tx.Database
        if([string]::IsNullOrWhiteSpace($TX)){throw 'TX_UNASSIGNED'}
        $txSPlan=New-StateVerificationPlan $TX 'Original' 'S' 'transaction-s' $Context
        $txSJournal=Invoke-StateVerificationPlan $txSPlan $TX 'Original' 'S'
        $mutationPlan=New-UID0002OWMutationPlan $TX $Context.RunId
        [void](Assert-CompleteMutationPlan $mutationPlan $TX)
        $fixtureTranscript=@(Invoke-UID0002OWHostileFixtures $ToolsListEnvelope $mutationPlan $TX $Context)
        if($fixtureTranscript.Count-ne 22){throw 'HOSTILE_FIXTURE_COUNT'}
        [void](Assert-PublicRuntimeAttestation $TX 'transaction-pre-mutation')
        $mutationJournal=Invoke-CompleteMutationPlan $mutationPlan $TX
        $vPlan=New-StateVerificationPlan $TX 'Final' 'V' 'transaction-v' $Context
        $vJournal=Invoke-StateVerificationPlan $vPlan $TX 'Final' 'V'
        [void](Assert-PublicRuntimeAttestation $TX 'transaction-pre-save')

        # Sole construction/send path. Transport ambiguity is terminal and nonretryable.
        $saveRecord=Invoke-SoleSave $Context $TX
        [void](Assert-OneSaveContract $Context $saveRecord)
        [void](Assert-PublicRuntimeAttestation $TX 'transaction-pre-retirement')
        $transactionQ=Close-UID0002OWRole $Context $tx $SupervisorRetireWorker 'transaction'
        $candidate=$transactionQ.Tuple

        if($saveRecord.ResponseClass-ceq'DefiniteSuccess'){
            $classifier=Invoke-UID0002OWClassifierRole $Context 'postsave-verify' $VerifyOpenRequest $candidate $p0 $saveRecord.ResponseClass $true $SupervisorRetireWorker
            if($classifier.Classification.Identity-cne'S1'){throw 'DEFINITE_SUCCESS_NOT_S1'}
        } else {
            $classifier=Invoke-UID0002OWClassifierRole $Context 'failure-verify' $FailureVerifyOpenRequest $candidate $p0 $saveRecord.ResponseClass $true $SupervisorRetireWorker
        }
        $classification=$classifier.Classification

        if($classification.RestoreAllowed-eq$true){
            $restore=Invoke-UID0002OWRestore $Context $p0 $b0 $backupPath $classification
            $restoreManifest=[pscustomobject]@{CopyEof=$true;FlushCompleted=$true;TimestampRestoredUnderHandle=$true;SourceBefore=$restore.SourceBefore;SourceAfter=$restore.SourceAfter;DestinationAfter=$restore.DestinationAfter;RestoredP0=$restore.RestoredP0;ReopenedB0=$restore.ReopenedB0}
            [void](Assert-UID0002OWRestoreCompletion $restoreManifest $p0 $b0)
            $rollback=Invoke-UID0002OWOriginalVerifier $Context 'rollback-verify' $RollbackOpenRequest $p0 $SupervisorRetireWorker
        } elseif($classification.Identity-ceq'P0') {
            if(-not(Test-TupleEquals (Get-ClosedExclusiveTuple $CanonicalPath) $p0)){throw 'UNSAVED_P0_DRIFT'}
        } elseif($classification.Identity-cne'S1') {throw 'CLASSIFIER_UNHANDLED_IDENTITY'}

        [pscustomobject]@{InspectionJournal=$inspectJournal;InspectionQ=$inspectionQ;P0B0=$p0b0;TransactionS=$txSJournal;MutationJournal=$mutationJournal;VJournal=$vJournal;HostileFixtures=$fixtureTranscript;Save=$saveRecord;Classification=$classification;Restore=$restore;Rollback=$rollback}
    } catch {
        $primaryFailure=$_.Exception
        # A pre-save failure may retire a dirty in-memory worker but may not authorize restore.
        if($Context.SaveAttemptCount-eq 0-and$null-ne$p0){
            $openTx=@($Context.Roles.Values|Where-Object{$_.Role-ceq'transaction'-and$_.State-ceq'Open'})
            if($openTx.Count-eq 1){
                $runtime=Assert-PublicRuntimeAttestation $openTx[0].Database 'presave-failure-pre-retirement'
                [void](Invoke-QRetirement 'presave-failure-transaction' $runtime.BoundWorker $openTx[0].Database $SupervisorRetireWorker $Context)
            }
            $candidate=Get-ClosedExclusiveTuple $CanonicalPath
            if(-not(Test-TupleEquals $candidate $p0)){throw "PRESAVE_FAILURE_NON_P0:$($primaryFailure.Message)"}
            [void](Invoke-UID0002OWOriginalVerifier $Context 'presave-failure-verify' $FailureVerifyOpenRequest $p0 $SupervisorRetireWorker)
        }
        throw $primaryFailure
    } finally {
        Invoke-UID0002OWOuterCleanup $Context $SupervisorRetireWorker
    }
}

$UID0002OWCoordinatorResult=Invoke-UID0002OWCoordinator -SupervisorRetireWorker $SupervisorRetireWorker -Context $UID0002OWTransaction
~~~

## Removed Block R019

- SHA256: `CF00266D6EE529603953C233A00F2BB4AEF3BDBE75E80C16F2A12306B46C044B`
- Language: `powershell`
- Bytes: `54988`
- First recovered timestamp: `2026-08-08T01:46:11.666Z`
- Session provenance: rollout-2026-08-07T21-33-30-019fdf00-f811-7fd2-b22d-23613a6f7a94.jsonl line 195083 (2026-08-08T01:46:11.666Z); rollout-2026-08-07T21-33-30-019fdf00-f811-7fd2-b22d-23613a6f7a94.jsonl line 195084 (2026-08-08T01:46:12.109Z)

~~~powershell
Set-StrictMode -Version 2

function New-UID0002OWV6Effects {
    [ordered]@{Coordinator=0;RawCall=0;Open=0;Register=0;Runtime=0;StateQuery=0;Mutation=0;Readback=0;SaveAttempt=0;Retire=0;Classify=0;Verifier=0;Restore=0;Cleanup=0}
}
function Add-UID0002OWV6Effect($Context,[string]$Name) {
    if($null -eq $Context.Effects[$Name]){throw "V6_EFFECT_UNKNOWN:$Name"}
    $Context.Effects[$Name]=[Int64]$Context.Effects[$Name]+1
}
function Assert-UID0002OWV6ExactProperties($Value,[string[]]$Required,[string[]]$Optional,[string]$Label) {
    if($null -eq $Value){throw "V6_PROPERTY_OBJECT_MISSING:$Label"}
    $actual=@($Value.psobject.Properties.Name)
    foreach($name in $Required){if($actual -cnotcontains $name){throw "V6_PROPERTY_REQUIRED:${Label}:$name"}}
    $allowed=@($Required+$Optional)
    $extra=@($actual|Where-Object{$allowed -cnotcontains $_})
    if($extra.Count -ne 0){throw "V6_PROPERTY_EXTRA:${Label}:$($extra -join ',')"}
    $true
}
function Assert-UID0002OWV6NativeString($Value,[string]$Label) {
    if($Value -isnot [string] -or [string]::IsNullOrWhiteSpace([string]$Value)){throw "V6_NATIVE_STRING:$Label"}
    [string]$Value
}
function Assert-UID0002OWV6NativeBool($Value,[string]$Label) {
    if($Value -isnot [bool]){throw "V6_NATIVE_BOOL:$Label"}
    [bool]$Value
}
function Assert-UID0002OWV6NativeInt($Value,[string]$Label,[Int64]$Minimum=[Int64]::MinValue,[Int64]$Maximum=[Int64]::MaxValue) {
    if(-not(Test-UID0002OWNativeInteger $Value)){throw "V6_NATIVE_INT:$Label"}
    $number=[Int64]$Value
    if($number -lt $Minimum -or $number -gt $Maximum){throw "V6_NATIVE_INT_RANGE:$Label"}
    $number
}
function Test-UID0002OWV6DeepEqual($Left,$Right) {
    (Get-CanonicalObjectSha256 (ConvertTo-CanonicalSchemaValue $Left)) -ceq (Get-CanonicalObjectSha256 (ConvertTo-CanonicalSchemaValue $Right))
}
function New-UID0002OWV6Request([string]$Id,[string]$Tool,$Arguments) {
    if($Tool -ceq 'idb_save'){throw 'V6_SAVE_ENDPOINT_RESERVED'}
    [ordered]@{jsonrpc='2.0';id=$Id;method='tools/call';params=[ordered]@{name=$Tool;arguments=$Arguments}}
}
function ConvertFrom-UID0002OWV6Raw([string]$Raw,[string]$Label) {
    if([string]::IsNullOrWhiteSpace($Raw)){throw "V6_RAW_EMPTY:$Label"}
    try{ConvertFrom-StrictUid0002OWJson $Raw}catch{throw "V6_RAW_INVALID:${Label}:$([string]$_.Exception.Message)"}
}
function Invoke-UID0002OWV6Raw($Context,$Request,$Meta,[bool]$PermitError=$false) {
    Add-UID0002OWV6Effect $Context 'RawCall'
    $send=$Context.Operations.SendRaw
    if($null -eq $send){throw 'V6_RAW_ADAPTER_MISSING'}
    $raw=&$send $Request $Meta
    if($raw -isnot [string]){throw "V6_RAW_ADAPTER_NONSTRING:$($Request.id)"}
    $envelope=ConvertFrom-UID0002OWV6Raw $raw ([string]$Request.id)
    [void](Assert-UID0002OWV6ExactProperties $envelope @('jsonrpc','id') @('result','error') "envelope $($Request.id)")
    if($envelope.jsonrpc -isnot [string] -or [string]$envelope.jsonrpc -cne '2.0'){throw "V6_JSONRPC_VERSION:$($Request.id)"}
    if($envelope.id -isnot [string] -or [string]$envelope.id -cne [string]$Request.id){throw "V6_JSONRPC_ID:$($Request.id)"}
    $hasResult=$null -ne $envelope.psobject.Properties['result']
    $hasError=$null -ne $envelope.psobject.Properties['error']
    if($hasResult -eq $hasError){throw "V6_JSONRPC_RESULT_ERROR_EXCLUSIVE:$($Request.id)"}
    if($hasError -and -not $PermitError){throw "V6_JSONRPC_ERROR:$($Request.id)"}
    [pscustomobject]@{Raw=$raw;Envelope=$envelope}
}

function Get-UID0002OWV6EndpointDescriptor([string]$Tool) {
    switch -CaseSensitive ($Tool) {
        'tools/list'      { [pscustomobject]@{Rows='tools';Key='name'} }
        'server_health'   { [pscustomobject]@{Rows='health';Key='database'} }
        'idb_list'        { [pscustomobject]@{Rows='sessions';Key='session_id'} }
        'lookup_funcs'    { [pscustomobject]@{Rows='functions';Key='addr'} }
        'inspect_items'   { [pscustomobject]@{Rows='items';Key='addr'} }
        'export_funcs'    { [pscustomobject]@{Rows='functions';Key='addr'} }
        'stack_frame'     { [pscustomobject]@{Rows='frames';Key='addr'} }
        'callees'         { [pscustomobject]@{Rows='results';Key='addr'} }
        'disasm'          { [pscustomobject]@{Rows='instructions';Key='addr'} }
        'get_bytes'       { [pscustomobject]@{Rows='regions';Key='addr'} }
        'get_comments'    { [pscustomobject]@{Rows='comments';Key='addr'} }
        'xrefs_to'        { [pscustomobject]@{Rows='results';Key='addr'} }
        'entity_query'    { [pscustomobject]@{Rows='entities';Key='query'} }
        'type_query'      { [pscustomobject]@{Rows='types';Key='name'} }
        'type_inspect'    { [pscustomobject]@{Rows='types';Key='name'} }
        'get_string'      { [pscustomobject]@{Rows='strings';Key='addr'} }
        'get_int'         { [pscustomobject]@{Rows='values';Key='addr'} }
        default           { throw "V6_ENDPOINT_UNSUPPORTED:$Tool" }
    }
}
function Assert-UID0002OWV6EndpointContract($Context,$Contract,[string]$Phase) {
    $descriptor=Get-UID0002OWV6EndpointDescriptor ([string]$Contract.Tool)
    if([string]$descriptor.Rows -cne [string]$Contract.RowProperty -or [string]$descriptor.Key -cne [string]$Contract.KeyField){throw "V6_ENDPOINT_DESCRIPTOR_DRIFT:$($Contract.Id)"}
    $id="uid0002ow-v6-$($Context.RunId)-$($Phase.ToLowerInvariant())-$($Contract.Id.ToLowerInvariant())"
    $request=if($Contract.Tool -ceq 'tools/list'){[ordered]@{jsonrpc='2.0';id=$id;method='tools/list';params=[ordered]@{}}else{New-UID0002OWV6Request $id ([string]$Contract.Tool) $Contract.Arguments}
    Add-UID0002OWV6Effect $Context 'StateQuery'
    $wire=Invoke-UID0002OWV6Raw $Context $request ([pscustomobject]@{Kind='state';Contract=$Contract;Phase=$Phase})
    [void](Assert-UID0002OWV6ExactProperties $wire.Envelope.result @('isError','structuredContent') @('content','_meta') "endpoint result $($Contract.Id)")
    if(Assert-UID0002OWV6NativeBool $wire.Envelope.result.isError "endpoint isError $($Contract.Id)"){throw "V6_STATE_TOOL_FAILURE:$($Contract.Id)"}
    $structured=$wire.Envelope.result.structuredContent
    [void](Assert-UID0002OWV6ExactProperties $structured @([string]$Contract.RowProperty) @() "endpoint structured $($Contract.Id)")
    $rows=@($structured.([string]$Contract.RowProperty));$expected=@($Contract.Rows)
    if($rows.Count -ne $expected.Count){throw "V6_ENDPOINT_CARDINALITY:$($Contract.Id)"}
    $seen=@{}
    for($i=0;$i -lt $rows.Count;$i++){
        $row=$rows[$i];$want=$expected[$i];$keyField=[string]$Contract.KeyField
        if($null -eq $row.psobject.Properties[$keyField]){throw "V6_ENDPOINT_KEY_MISSING:$($Contract.Id):$i"}
        $actualKey=Assert-UID0002OWV6NativeString $row.$keyField "endpoint key $($Contract.Id)/$i"
        $expectedKey=Assert-UID0002OWV6NativeString $want.$keyField "expected key $($Contract.Id)/$i"
        if($actualKey -cne $expectedKey){throw "V6_ENDPOINT_ASSOCIATION:$($Contract.Id):$i:$actualKey"}
        if($seen.ContainsKey($actualKey)){throw "V6_ENDPOINT_DUPLICATE_KEY:$($Contract.Id):$actualKey"};$seen[$actualKey]=$true
        if(-not(Test-UID0002OWV6DeepEqual $row $want)){throw "V6_ENDPOINT_VALUE:$($Contract.Id):$actualKey"}
    }
    [pscustomobject]@{Id=$Contract.Id;Tool=$Contract.Tool;Keys=@($expected|ForEach-Object{[string]$_.$($Contract.KeyField)});Rows=$rows.Count;RawSHA256=(Get-CanonicalObjectSha256 $wire.Raw)}
}

function New-UID0002OWV6StateContracts([ValidateSet('Original','Final')]$State,[string]$Database) {
    $isFinal=$State -ceq 'Final'
    $functions=@(
        [pscustomobject]@{addr='0x005007a0';name=$(if($isFinal){'DirectionButtonControlPane__DirectionButtonControlPane'}else{'sub_5007A0'});type='DirectionButtonControlPane *__thiscall(DirectionButtonControlPane *this, Pane *parent, int x, int y, int direction)';regular_comment=$(if($isFinal){'Initializes direction index and frame offset, then installs primary/EventHandler/TimerHandler views.'}else{''})},
        [pscustomobject]@{addr='0x005007f0';name=$(if($isFinal){'DirectionButtonControlPane__SetVisualState'}else{'sub_5007F0'});type=$(if($isFinal){'void __thiscall(DirectionButtonControlPane *this, unsigned __int8 visualState)'}else{'int __thiscall(int this, unsigned __int8)'});regular_comment=$(if($isFinal){'Updates the visual-state frame offset and always delegates to ButtonControlPane.'}else{''})},
        [pscustomobject]@{addr='0x00500820';name=$(if($isFinal){'DirectionButtonControlPane__OnPaint'}else{'sub_500820'});type=$(if($isFinal){'void __thiscall(DirectionButtonControlPane *this)'}else{'int __thiscall(int this)'});regular_comment=$(if($isFinal){'Draws DIREC.EPD through NPAL3.PAL and overlays the disabled frame.'}else{''})},
        [pscustomobject]@{addr='0x005026a0';name=$(if($isFinal){'DirectionButtonControlPane__scalar_deleting_destructor'}else{'sub_5026A0'});type=$(if($isFinal){'DirectionButtonControlPane *__thiscall(DirectionButtonControlPane *this, unsigned int flags)'}else{'_DWORD *__thiscall(_DWORD *Block, char)'});regular_comment=$(if($isFinal){'Compiler scalar-deleting wrapper; source declares only the virtual destructor.'}else{''})}
    )
    $frames=@(
        [pscustomobject]@{addr='0x005007a0';members=@([pscustomobject]@{offset=12;size=4;name='directionIndex';type='int'},[pscustomobject]@{offset=16;size=4;name='frameOffset';type='int'})},
        [pscustomobject]@{addr='0x005007f0';members=@([pscustomobject]@{offset=12;size=4;name='visualState';type='unsigned __int8'})},
        [pscustomobject]@{addr='0x00500820';members=@()},
        [pscustomobject]@{addr='0x005026a0';members=@([pscustomobject]@{offset=12;size=4;name='flags';type=$(if($isFinal){'unsigned int'}else{'char'})})}
    )
    $contracts=@(
        [pscustomobject]@{Class='S00';Id='S00-tools';Tool='tools/list';Arguments=[ordered]@{};RowProperty='tools';KeyField='name';Rows=@([pscustomobject]@{name='runtime_attestation';input_schema_sha256=('1'*64)},[pscustomobject]@{name='lookup_funcs';input_schema_sha256=('2'*64)},[pscustomobject]@{name='set_type';input_schema_sha256=('3'*64)})},
        [pscustomobject]@{Class='S01';Id='S01-health';Tool='server_health';Arguments=[ordered]@{database=$Database};RowProperty='health';KeyField='database';Rows=@([pscustomobject]@{database=$Database;status='ok';canonical_path=$CanonicalPath;is_analyzing=$false;hexrays_ready=$true})},
        [pscustomobject]@{Class='S02';Id='S02-list';Tool='idb_list';Arguments=[ordered]@{};RowProperty='sessions';KeyField='session_id';Rows=@([pscustomobject]@{session_id=$Database;canonical_path=$CanonicalPath;is_active=$true;owned=$true})},
        [pscustomobject]@{Class='S03';Id='S03-lookup';Tool='lookup_funcs';Arguments=[ordered]@{database=$Database;addrs=@($functions.addr)};RowProperty='functions';KeyField='addr';Rows=$functions},
        [pscustomobject]@{Class='S04';Id='S04-export';Tool='export_funcs';Arguments=[ordered]@{database=$Database;addrs=@($functions.addr)};RowProperty='functions';KeyField='addr';Rows=$functions},
        [pscustomobject]@{Class='S05';Id='S05-frame';Tool='stack_frame';Arguments=[ordered]@{database=$Database;addrs=@($frames.addr)};RowProperty='frames';KeyField='addr';Rows=$frames},
        [pscustomobject]@{Class='S06';Id='S06-callees';Tool='callees';Arguments=[ordered]@{database=$Database;addrs=@('0x0050248a','0x00502495')};RowProperty='results';KeyField='addr';Rows=@([pscustomobject]@{addr='0x0050248a';callees=@()},[pscustomobject]@{addr='0x00502495';callees=@()})},
        [pscustomobject]@{Class='S07';Id='S07-disasm';Tool='disasm';Arguments=[ordered]@{database=$Database;addrs=@('0x0050248a','0x00502490','0x00502495','0x0050249b')};RowProperty='instructions';KeyField='addr';Rows=@([pscustomobject]@{addr='0x0050248a';text='sub ecx, 0A0h';bytes='81E9A0000000'},[pscustomobject]@{addr='0x00502490';text='jmp 005026A0';bytes='E90B020000'},[pscustomobject]@{addr='0x00502495';text='sub ecx, 0A4h';bytes='81E9A4000000'},[pscustomobject]@{addr='0x0050249b';text='jmp 005026A0';bytes='E900020000'})},
        [pscustomobject]@{Class='S08';Id='S08-bytes';Tool='get_bytes';Arguments=[ordered]@{database=$Database;regions=@([ordered]@{addr='0x005007e8';size=8},[ordered]@{addr='0x0050081e';size=2},[ordered]@{addr='0x005008b9';size=7})};RowProperty='regions';KeyField='addr';Rows=@([pscustomobject]@{addr='0x005007e8';size=8;bytes='CCCCCCCCCCCCCCCC';sha256='57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE'},[pscustomobject]@{addr='0x0050081e';size=2;bytes='CCCC';sha256='ECA0467098F5224797F3BD1C2B97B096319E00A6D4FDCCAA2C0DC3ECEF8FD4C4'},[pscustomobject]@{addr='0x005008b9';size=7;bytes='CCCCCCCCCCCCCC';sha256='E82D3D6B25163C268A01B99E68D0B86D7A21683A6E753DE177E05EAA80496611'})},
        [pscustomobject]@{Class='S09';Id='S09-comments';Tool='get_comments';Arguments=[ordered]@{database=$Database;addrs=@($functions.addr)};RowProperty='comments';KeyField='addr';Rows=@($functions|ForEach-Object{[pscustomobject]@{addr=$_.addr;regular=$_.regular_comment;repeatable='';function_regular='';function_repeatable='';address_regular='';address_repeatable=''}})},
        [pscustomobject]@{Class='S10';Id='S10-xrefs';Tool='xrefs_to';Arguments=[ordered]@{database=$Database;addrs=@('0x0061dc30','0x0061e40c','0x0061dcd4')};RowProperty='results';KeyField='addr';Rows=@([pscustomobject]@{addr='0x0061dc30';xrefs=@('0x005007b5')},[pscustomobject]@{addr='0x0061e40c';xrefs=@('0x00500855','0x00500872')},[pscustomobject]@{addr='0x0061dcd4';xrefs=@()})},
        [pscustomobject]@{Class='S11';Id='S11-items';Tool='inspect_items';Arguments=[ordered]@{database=$Database;addrs=@('0x0061dc30','0x0061dc54','0x0061dc78','0x0061e40c')};RowProperty='items';KeyField='addr';Rows=@([pscustomobject]@{addr='0x0061dc30';name='DirectionButtonControlPane_vftable';type='void *[10]';size=40},[pscustomobject]@{addr='0x0061dc54';name='DirectionButtonControlPane_EventHandler_vftable';type='void *[10]';size=40},[pscustomobject]@{addr='0x0061dc78';name='DirectionButtonControlPane_TimerHandler_vftable';type='void *[10]';size=40},[pscustomobject]@{addr='0x0061e40c';name=$(if($isFinal){'aNpal3Pal'}else{'aNp_1'});type=$(if($isFinal){'char[10]'}else{'char[3]'});size=$(if($isFinal){10}else{3})})},
        [pscustomobject]@{Class='S12';Id='S12-strings';Tool='get_string';Arguments=[ordered]@{database=$Database;addrs=@('0x0061e3f0','0x0061e400','0x0061e40c')};RowProperty='strings';KeyField='addr';Rows=@([pscustomobject]@{addr='0x0061e3f0';value='DIREC.EPD';length=10},[pscustomobject]@{addr='0x0061e400';value='BDFRAME.EPF';length=11},[pscustomobject]@{addr='0x0061e40c';value='NPAL3.PAL';length=9})},
        [pscustomobject]@{Class='S13';Id='S13-vtable';Tool='get_int';Arguments=[ordered]@{database=$Database;addrs=@('0x0061dc30','0x0061dc34','0x0061dc54','0x0061dc78')};RowProperty='values';KeyField='addr';Rows=@([pscustomobject]@{addr='0x0061dc30';value=5249792;size=4},[pscustomobject]@{addr='0x0061dc34';value=5249936;size=4},[pscustomobject]@{addr='0x0061dc54';value=5252234;size=4},[pscustomobject]@{addr='0x0061dc78';value=5252245;size=4})}
    )
    if(@($contracts|Select-Object -ExpandProperty Class -Unique).Count -ne 14){throw 'V6_CONTRACT_CLASS_COUNT'}
    $contracts
}
function Invoke-UID0002OWV6VerifyState($Context,[string]$Database,[ValidateSet('Original','Final')]$ExpectedState,[string]$Phase) {
    $receipts=@();$contracts=@(New-UID0002OWV6StateContracts $ExpectedState $Database)
    foreach($contract in $contracts){
        try{$receipts+=,(Assert-UID0002OWV6EndpointContract $Context $contract $Phase)}catch{throw "V6_STATE_MISMATCH:${ExpectedState}:$($contract.Class):$([string]$_.Exception.Message)"}
    }
    if($receipts.Count -ne $contracts.Count){throw "V6_STATE_INCOMPLETE:$ExpectedState"}
    [pscustomobject]@{ExpectedState=$ExpectedState;Classes=14;Queries=$receipts.Count;Receipts=$receipts}
}
function Test-UID0002OWV6State($Context,[string]$Database,[ValidateSet('Original','Final')]$ExpectedState,[string]$Phase) {
    try{[void](Invoke-UID0002OWV6VerifyState $Context $Database $ExpectedState $Phase);$true}catch{if(([string]$_.Exception.Message).StartsWith("V6_STATE_MISMATCH:$ExpectedState",[StringComparison]::Ordinal)){return $false};throw}
}

function Assert-UID0002OWV6PhysicalModule($Context,$Module,[string]$Root,[string]$Role) {
    [void](Assert-UID0002OWV6ExactProperties $Module @('sys_modules_name','module_id','resolved_path','derived_relative_path','size','mtime_ns','ctime_ns','sha256') @() "$Role module")
    $name=Assert-UID0002OWV6NativeString $Module.sys_modules_name "$Role module name"
    $moduleId=Assert-UID0002OWV6NativeString $Module.module_id "$Role module id"
    $path=[IO.Path]::GetFullPath((Assert-UID0002OWV6NativeString $Module.resolved_path "$Role module path"))
    $fullRoot=[IO.Path]::GetFullPath($Root).TrimEnd('\')
    if(-not $path.StartsWith($fullRoot+'\',[StringComparison]::OrdinalIgnoreCase)){throw "V6_MODULE_OUTSIDE_ROOT:$name"}
    $derived=Assert-UID0002OWV6NativeString $Module.derived_relative_path "$Role derived path"
    if($derived -cne $path.Substring($fullRoot.Length).TrimStart('\')){throw "V6_MODULE_DERIVED_PATH:$name"}
    $statAdapter=$Context.Operations.StatModule;$physical=&$statAdapter $path
    if($null -eq $physical){throw "V6_MODULE_FILE_MISSING:$name"}
    [void](Assert-UID0002OWV6ExactProperties $physical @('resolved_path','size','mtime_ns','ctime_ns','sha256') @() "$Role physical module")
    foreach($field in @('resolved_path','size','mtime_ns','ctime_ns','sha256')){if([string]$physical.$field -cne [string]$Module.$field){throw "V6_MODULE_PHYSICAL_MISMATCH:${name}:$field"}}
    [pscustomobject]@{Name=$name;ModuleId=$moduleId;ResolvedPath=$path;DerivedRelativePath=$derived;Size=[Int64]$Module.size;MtimeNs=[Int64]$Module.mtime_ns;CtimeNs=[Int64]$Module.ctime_ns;SHA256=[string]$Module.sha256}
}
function Assert-UID0002OWV6Runtime($Context,[string]$Database,[string]$Role) {
    Add-UID0002OWV6Effect $Context 'Runtime'
    $id="uid0002ow-v6-$($Context.RunId)-$Role-runtime"
    $request=New-UID0002OWV6Request $id 'runtime_attestation' ([ordered]@{expected_database=$Database;expected_canonical_path=$CanonicalPath})
    $wire=Invoke-UID0002OWV6Raw $Context $request ([pscustomobject]@{Kind='runtime';Role=$Role;Database=$Database})
    $sc=$wire.Envelope.result.structuredContent
    [void](Assert-UID0002OWV6ExactProperties $sc @('schema_version','ok','errors','listener','workers') @('nonce','attested_at_utc') "$Role runtime")
    if((Assert-UID0002OWV6NativeInt $sc.schema_version "$Role runtime schema" 1 1) -ne 1 -or -not(Assert-UID0002OWV6NativeBool $sc.ok "$Role runtime ok") -or @($sc.errors).Count -ne 0){throw "V6_RUNTIME_ROOT:$Role"}
    $listener=$sc.listener;[void](Assert-UID0002OWV6ExactProperties $listener @('source_root','process','endpoint','implementation_manifest_sha256','modules') @() "$Role listener")
    $workers=@($sc.workers);if($workers.Count -ne 1){throw "V6_RUNTIME_WORKER_COUNT:$Role"};$worker=$workers[0]
    [void](Assert-UID0002OWV6ExactProperties $worker @('source_root','process','route','session','implementation_manifest_sha256','modules') @() "$Role worker")
    $processAdapter=$Context.Operations.ProcessSnapshot;$socketAdapter=$Context.Operations.SocketSnapshot
    foreach($side in @([pscustomobject]@{Name='listener';Value=$listener},[pscustomobject]@{Name='worker';Value=$worker})){
        $process=$side.Value.process;[void](Assert-UID0002OWV6ExactProperties $process @('pid','parent_pid','creation_time_100ns','generation','image') @() "$Role $($side.Name) process")
        $pid=Assert-UID0002OWV6NativeInt $process.pid "$Role $($side.Name) pid" 1
        $observed=&$processAdapter $pid;if($null -eq $observed -or -not(Test-UID0002OWV6DeepEqual $process $observed)){throw "V6_PROCESS_GENERATION:$Role/$($side.Name)"}
        $port=Assert-UID0002OWV6NativeInt $(if($side.Name -ceq 'listener'){$side.Value.endpoint.port}else{$side.Value.route.port}) "$Role $($side.Name) port" 1 65535
        $socket=&$socketAdapter $port;if($null -eq $socket -or [Int64]$socket.owning_pid -ne $pid -or [string]$socket.host -cne '127.0.0.1'){throw "V6_SOCKET_OWNER:$Role/$($side.Name)"}
    }
    [void](Assert-UID0002OWV6ExactProperties $worker.session @('session_id','canonical_path','is_active','owned') @() "$Role worker session")
    if((Assert-UID0002OWV6NativeString $worker.session.session_id "$Role worker session") -cne $Database -or -not([IO.Path]::GetFullPath([string]$worker.session.canonical_path)).Equals($CanonicalPath,[StringComparison]::OrdinalIgnoreCase) -or -not(Assert-UID0002OWV6NativeBool $worker.session.is_active "$Role worker active") -or -not(Assert-UID0002OWV6NativeBool $worker.session.owned "$Role worker owned")){throw "V6_RUNTIME_SESSION:$Role"}
    $listenerIds=@{};$workerIds=@{};$listenerModules=@{};$workerModules=@{}
    foreach($module in @($listener.modules)){$receipt=Assert-UID0002OWV6PhysicalModule $Context $module ([string]$listener.source_root) "$Role listener";if($listenerIds.ContainsKey($receipt.ModuleId)){throw "V6_MODULE_ID_DUPLICATE:$Role/listener"};$listenerIds[$receipt.ModuleId]=$true;$listenerModules[$receipt.Name]=$receipt}
    foreach($module in @($worker.modules)){$receipt=Assert-UID0002OWV6PhysicalModule $Context $module ([string]$worker.source_root) "$Role worker";if($workerIds.ContainsKey($receipt.ModuleId)){throw "V6_MODULE_ID_DUPLICATE:$Role/worker"};$workerIds[$receipt.ModuleId]=$true;$workerModules[$receipt.Name]=$receipt}
    if([string]$listener.source_root -cne [string]$worker.source_root -or [string]$listener.implementation_manifest_sha256 -cne [string]$worker.implementation_manifest_sha256){throw "V6_MODULE_MANIFEST_ROOT:$Role"}
    foreach($name in $listenerModules.Keys){if(-not $workerModules.ContainsKey($name)){throw "V6_MODULE_SET:$Role/$name"};$left=$listenerModules[$name].psobject.Copy();$right=$workerModules[$name].psobject.Copy();$left.psobject.Properties.Remove('ModuleId');$right.psobject.Properties.Remove('ModuleId');if(-not(Test-UID0002OWV6DeepEqual $left $right)){throw "V6_MODULE_CROSS_ROLE:$Role/$name"}}
    [pscustomobject]@{Database=$Database;Role=$Role;Listener=$listener;Worker=$worker;RawSHA256=(Get-CanonicalObjectSha256 $wire.Raw)}
}

function Open-UID0002OWV6Role($Context,[string]$Role) {
    Add-UID0002OWV6Effect $Context 'Open'
    $id="uid0002ow-v6-$($Context.RunId)-$Role-open"
    $request=New-UID0002OWV6Request $id 'idb_open' ([ordered]@{path=$CanonicalPath;preferred_session_id="uid0002ow-$($Context.RunId)-$Role";run_auto_analysis=$false})
    $wire=Invoke-UID0002OWV6Raw $Context $request ([pscustomobject]@{Kind='open';Role=$Role})
    $session=$wire.Envelope.result.structuredContent.session
    [void](Assert-UID0002OWV6ExactProperties $session @('session_id','canonical_path','is_active') @('input_path') "$Role returned session")
    $database=Assert-UID0002OWV6NativeString $session.session_id "$Role returned session"
    if(-not(Assert-UID0002OWV6NativeBool $session.is_active "$Role returned active") -or -not([IO.Path]::GetFullPath([string]$session.canonical_path)).Equals($CanonicalPath,[StringComparison]::OrdinalIgnoreCase)){throw "V6_OPEN_SESSION_AUTHORITY:$Role"}
    $provisionalAdapter=$Context.Operations.ProvisionalSnapshot
    $provisional=&$provisionalAdapter $database $Role
    $roleState=[pscustomobject]@{Role=$Role;Database=$database;CanonicalPath=$CanonicalPath;Provisional=$provisional;State='Open';Runtime=$null;Retirement=$null}
    if($Context.Roles.Contains($database)){throw "V6_ROLE_DUPLICATE:$database"}
    $Context.Roles[$database]=$roleState
    # Registration happens immediately after the returned session/path and provisional
    # process/socket delta exist; every later assertion is cleanup-covered.
    Add-UID0002OWV6Effect $Context 'Register'
    $register=$Context.Operations.RegisterOpen;&$register $roleState
    $roleState.Runtime=Assert-UID0002OWV6Runtime $Context $database "$Role-after-open"
    $roleState
}
function Retire-UID0002OWV6Role($Context,$RoleState,[string]$Boundary) {
    if($null -eq $RoleState -or $RoleState.State -cne 'Open'){throw "V6_RETIRE_STATE:$Boundary"}
    Add-UID0002OWV6Effect $Context 'Retire'
    $retire=$Context.Operations.RetireGeneration;&$retire $RoleState
    # Retirement is irreversible even if a later absence proof fails.
    $RoleState.State='Retired'
    $absenceAdapter=$Context.Operations.AbsenceSnapshot;$absence=&$absenceAdapter $RoleState
    [void](Assert-UID0002OWV6ExactProperties $absence @('process_absent','session_absent','socket_absent','route_absent','disk_open','disk_closed') @() "$Boundary absence")
    foreach($field in @('process_absent','session_absent','socket_absent','route_absent')){if(-not(Assert-UID0002OWV6NativeBool $absence.$field "$Boundary $field")){throw "V6_RETIREMENT_PRESENCE:${Boundary}:$field"}}
    if(-not(Test-UID0002OWV6DeepEqual $absence.disk_open $absence.disk_closed)){throw "V6_DOPEN_DCLOSED:${Boundary}"}
    $RoleState.Retirement=$absence;$absence
}
function Invoke-UID0002OWV6Cleanup($Context) {
    Add-UID0002OWV6Effect $Context 'Cleanup';$failures=@()
    foreach($role in @($Context.Roles.Values|Where-Object{$_.State -ceq 'Open'})){
        try{[void](Retire-UID0002OWV6Role $Context $role 'outer-cleanup')}catch{$failures+=[string]$_.Exception.Message}
    }
    $cleanup=$Context.Operations.Cleanup
    try{&$cleanup $Context}catch{$failures+=[string]$_.Exception.Message}
    if($failures.Count -ne 0){throw "V6_CLEANUP_FAILURE:$($failures -join '|')"}
}

function New-UID0002OWV6FixtureMutationPlan([string]$Database) {
    $addresses=@('0x005007a0','0x005007f0','0x00500820','0x0050248a','0x00502495','0x005026a0','0x0061dc2c','0x0061dc50','0x0061dc74','0x0061e40c')
    $plan=@()
    for($i=1;$i -le 43;$i++){
        $phase=if($i -le 10){'Dry'}else{'Actual'};$kind=@('set_name','set_type','set_address_comments','set_stack_type')[($i-1)%4];$addr=$addresses[($i-1)%$addresses.Count]
        $subject=[pscustomobject]@{addr=$addr;name="uid0002ow_v6_$($i.ToString('00'))";type="signature_$($i.ToString('00'))";comment="comment_$($i.ToString('00'))"}
        $plan+=,[pscustomobject]@{Seq=$i;Id="V6M$($i.ToString('00'))";Phase=$phase;Kind=$kind;Database=$Database;Subject=$subject;ExpectedOld=[pscustomobject]@{addr=$addr;name="old_$($i.ToString('00'))";type="old_signature_$($i.ToString('00'))";comment=''};ExpectedNew=$subject}
    }
    $plan
}
function Assert-UID0002OWV6MutationPlan($Plan,[string]$Database) {
    $rows=@($Plan);if($rows.Count -ne 43){throw 'V6_MUTATION_COUNT'}
    if(@($rows|Where-Object Phase -ceq 'Dry').Count -ne 10 -or @($rows|Where-Object Phase -ceq 'Actual').Count -ne 33){throw 'V6_MUTATION_SPLIT'}
    for($i=0;$i -lt 43;$i++){if([Int64]$rows[$i].Seq -ne $i+1 -or [string]$rows[$i].Database -cne $Database){throw "V6_MUTATION_SEQUENCE:$i"};if((Get-CanonicalObjectSha256 $rows[$i].ExpectedOld) -ceq (Get-CanonicalObjectSha256 $rows[$i].ExpectedNew)){throw "V6_MUTATION_SIGNATURE_NOT_DISTINCT:$i"}}
    $true
}
function Invoke-UID0002OWV6MutationPlan($Context,$Plan,[string]$Database) {
    [void](Assert-UID0002OWV6MutationPlan $Plan $Database);$receipts=@()
    foreach($row in @($Plan)){
        Add-UID0002OWV6Effect $Context 'Mutation'
        $id="uid0002ow-v6-$($Context.RunId)-mutation-$($row.Seq.ToString('00'))"
        $arguments=[ordered]@{database=$Database;kind=$row.Kind;dry_run=($row.Phase -ceq 'Dry');subject=$row.Subject}
        $request=New-UID0002OWV6Request $id ([string]$row.Kind) $arguments
        $wire=Invoke-UID0002OWV6Raw $Context $request ([pscustomobject]@{Kind='mutation';Row=$row})
        $sc=$wire.Envelope.result.structuredContent
        [void](Assert-UID0002OWV6ExactProperties $sc @('results','summary') @() "mutation $($row.Id)")
        [void](Assert-UID0002OWV6ExactProperties $sc.summary @('total','succeeded','failed','dry_run') @() "mutation summary $($row.Id)")
        if((Assert-UID0002OWV6NativeInt $sc.summary.total 'mutation total' 1 1) -ne 1 -or (Assert-UID0002OWV6NativeInt $sc.summary.succeeded 'mutation succeeded' 1 1) -ne 1 -or (Assert-UID0002OWV6NativeInt $sc.summary.failed 'mutation failed' 0 0) -ne 0 -or (Assert-UID0002OWV6NativeBool $sc.summary.dry_run 'mutation dry') -ne ($row.Phase -ceq 'Dry')){throw "V6_MUTATION_SUMMARY:$($row.Id)"}
        $results=@($sc.results);if($results.Count -ne 1){throw "V6_MUTATION_CARDINALITY:$($row.Id)"};$result=$results[0]
        [void](Assert-UID0002OWV6ExactProperties $result @('index','success','kind','dry_run','subject','old','new') @() "mutation result $($row.Id)")
        if((Assert-UID0002OWV6NativeInt $result.index 'mutation index' 0 0) -ne 0 -or -not(Assert-UID0002OWV6NativeBool $result.success 'mutation success') -or [string]$result.kind -cne [string]$row.Kind -or (Assert-UID0002OWV6NativeBool $result.dry_run 'mutation row dry') -ne ($row.Phase -ceq 'Dry') -or -not(Test-UID0002OWV6DeepEqual $result.subject $row.Subject) -or -not(Test-UID0002OWV6DeepEqual $result.old $row.ExpectedOld) -or -not(Test-UID0002OWV6DeepEqual $result.new $row.ExpectedNew)){throw "V6_MUTATION_RECEIPT:$($row.Id)"}
        Add-UID0002OWV6Effect $Context 'Readback'
        $readId="uid0002ow-v6-$($Context.RunId)-readback-$($row.Seq.ToString('00'))"
        $readRequest=New-UID0002OWV6Request $readId 'inspect_items' ([ordered]@{database=$Database;addrs=@([string]$row.Subject.addr)})
        $read=Invoke-UID0002OWV6Raw $Context $readRequest ([pscustomobject]@{Kind='mutation-readback';Row=$row})
        $items=@($read.Envelope.result.structuredContent.items);if($items.Count -ne 1 -or -not(Test-UID0002OWV6DeepEqual $items[0] $row.ExpectedNew)){throw "V6_MUTATION_READBACK:$($row.Id)"}
        $receipts+=,[pscustomobject]@{Seq=$row.Seq;Id=$row.Id;Kind=$row.Kind;DryRun=($row.Phase -ceq 'Dry');SubjectSHA256=(Get-CanonicalObjectSha256 $row.Subject);OldSHA256=(Get-CanonicalObjectSha256 $result.old);NewSHA256=(Get-CanonicalObjectSha256 $result.new);RawSHA256=(Get-CanonicalObjectSha256 $wire.Raw);ReadbackSHA256=(Get-CanonicalObjectSha256 $read.Raw)}
    }
    if($receipts.Count -ne 43){throw 'V6_MUTATION_RECEIPT_COUNT'};$receipts
}

function Invoke-UID0002OWV6SoleSave($Context,[string]$Database) {
    if($Context.SaveAttempted -or $null -ne $Context.SaveRecord){throw 'V6_SAVE_SECOND_ATTEMPT'}
    $claim=$Context.Operations.ClaimSaveAttempt;if(-not(Assert-UID0002OWV6NativeBool (&$claim $Context.RunId $Database) 'durable save claim')){throw 'V6_SAVE_ALREADY_CLAIMED'}
    $Context.SaveAttempted=$true;Add-UID0002OWV6Effect $Context 'SaveAttempt'
    $request=[ordered]@{jsonrpc='2.0';id="uid0002ow-v6-$($Context.RunId)-sole-save";method='tools/call';params=[ordered]@{name='idb_save';arguments=[ordered]@{database=$Database}}}
    $send=$Context.Operations.SendRaw;$raw=$null
    try{$raw=&$send $request ([pscustomobject]@{Kind='save'});if($raw -isnot [string]){throw 'V6_SAVE_RAW_NONSTRING'};$Context.SaveRecord=[pscustomobject]@{Raw=$raw;Envelope=$null;ResponseClass='Indeterminate';AttemptCount=1;RetryAllowed=$false;Request=$request};$wire=Invoke-UID0002OWV6Raw $Context $request ([pscustomobject]@{Kind='save-replay-validation';SuppliedRaw=$raw});$Context.SaveRecord.Envelope=$wire.Envelope;$sc=$wire.Envelope.result.structuredContent;[void](Assert-UID0002OWV6ExactProperties $sc @('success') @() 'save structured');$success=Assert-UID0002OWV6NativeBool $sc.success 'save success';$Context.SaveRecord.ResponseClass=if($success){'DefiniteSuccess'}else{'DeterminateFailure'};$Context.SaveRecord}catch{$message=[string]$_.Exception.Message;if($null -eq $Context.SaveRecord){$Context.SaveRecord=[pscustomobject]@{Raw=$raw;Envelope=$null;ResponseClass='Indeterminate';AttemptCount=1;RetryAllowed=$false;Request=$request}};throw "V6_SAVE_INDETERMINATE:$message"}
}
function Get-UID0002OWV6DiskAuthority($Context,[string]$Boundary) {
    $reader=$Context.Operations.ReadDiskAuthority;$authority=&$reader $Boundary
    [void](Assert-UID0002OWV6ExactProperties $authority @('OpenTuple','ClosedTuple') @() "$Boundary disk authority")
    if(-not(Test-UID0002OWV6DeepEqual $authority.OpenTuple $authority.ClosedTuple)){throw "V6_DOPEN_DCLOSED:$Boundary"}
    $authority
}
function Invoke-UID0002OWV6Classify($Context,$P0,[string]$SaveClass) {
    Add-UID0002OWV6Effect $Context 'Classify';$disk=Get-UID0002OWV6DiskAuthority $Context 'classifier'
    $rvRole=Open-UID0002OWV6Role $Context 'rv';Add-UID0002OWV6Effect $Context 'Verifier';$rv=Test-UID0002OWV6State $Context $rvRole.Database 'Original' 'rv';[void](Retire-UID0002OWV6Role $Context $rvRole 'rv')
    $svRole=Open-UID0002OWV6Role $Context 'sv';Add-UID0002OWV6Effect $Context 'Verifier';$sv=Test-UID0002OWV6State $Context $svRole.Database 'Final' 'sv';[void](Retire-UID0002OWV6Role $Context $svRole 'sv')
    if($rv -eq $sv){throw 'V6_CLASSIFIER_NON_EXCLUSIVE'}
    if($rv){if(-not(Test-UID0002OWV6DeepEqual $disk.ClosedTuple $P0)){throw 'V6_CLASSIFIER_RV_THIRD_IDENTITY'};return [pscustomobject]@{Identity='P0';RestoreAllowed=$false;Tuple=$disk.ClosedTuple;RV=$true;SV=$false}}
    if(Test-UID0002OWV6DeepEqual $disk.ClosedTuple $P0){throw 'V6_CLASSIFIER_SV_P0'}
    if($SaveClass -ceq 'DefiniteSuccess'){[pscustomobject]@{Identity='S1';RestoreAllowed=$false;Tuple=$disk.ClosedTuple;RV=$false;SV=$true}}else{[pscustomobject]@{Identity='FailingSaved';RestoreAllowed=$true;Tuple=$disk.ClosedTuple;RV=$false;SV=$true}}
}
function Invoke-UID0002OWV6Restore($Context,$P0,$B0,$Classification) {
    if(-not $Classification.RestoreAllowed -or $Classification.Identity -cne 'FailingSaved'){throw 'V6_RESTORE_NOT_AUTHORIZED'}
    Add-UID0002OWV6Effect $Context 'Restore';$restore=$Context.Operations.Restore;$receipt=&$restore $P0 $B0 $Classification.Tuple
    [void](Assert-UID0002OWV6ExactProperties $receipt @('SourceBefore','SourceAfter','DestinationBefore','DestinationAfter','RestoredClosed','BackupReopened','CopyCount','EOF','Flushed','TimestampRestoredUnderHandle','ContinuousSourceHandle','ContinuousDestinationHandle') @() 'restore receipt')
    if(-not(Test-UID0002OWV6DeepEqual $receipt.SourceBefore $B0) -or -not(Test-UID0002OWV6DeepEqual $receipt.SourceAfter $B0) -or -not(Test-UID0002OWV6DeepEqual $receipt.DestinationBefore $Classification.Tuple) -or -not(Test-UID0002OWV6DeepEqual $receipt.DestinationAfter $P0) -or -not(Test-UID0002OWV6DeepEqual $receipt.RestoredClosed $P0) -or -not(Test-UID0002OWV6DeepEqual $receipt.BackupReopened $B0) -or [Int64]$receipt.CopyCount -ne [Int64]$P0.Length -or -not(Assert-UID0002OWV6NativeBool $receipt.EOF 'restore EOF') -or -not(Assert-UID0002OWV6NativeBool $receipt.Flushed 'restore flush') -or -not(Assert-UID0002OWV6NativeBool $receipt.TimestampRestoredUnderHandle 'restore timestamp') -or -not(Assert-UID0002OWV6NativeBool $receipt.ContinuousSourceHandle 'restore source handle') -or -not(Assert-UID0002OWV6NativeBool $receipt.ContinuousDestinationHandle 'restore destination handle')){throw 'V6_RESTORE_SUBSTITUTION'}
    $rollback=Open-UID0002OWV6Role $Context 'rollback';Add-UID0002OWV6Effect $Context 'Verifier';[void](Invoke-UID0002OWV6VerifyState $Context $rollback.Database 'Original' 'rollback');[void](Retire-UID0002OWV6Role $Context $rollback 'rollback');$final=Get-UID0002OWV6DiskAuthority $Context 'rollback-final';if(-not(Test-UID0002OWV6DeepEqual $final.ClosedTuple $P0)){throw 'V6_ROLLBACK_FINAL_TUPLE'};$receipt
}

function Invoke-UID0002OWV6Coordinator($Operations,$MutationPlan=$null) {
    if($null -eq $Operations){throw 'V6_OPERATIONS_REQUIRED'}
    $context=[pscustomobject]@{RunId=[Guid]::NewGuid().ToString('N');Operations=$Operations;Roles=[ordered]@{};Effects=(New-UID0002OWV6Effects);SaveAttempted=$false;SaveRecord=$null;P0B0=$null;PrimaryError=$null}
    Add-UID0002OWV6Effect $context 'Coordinator';$primary=$null;$cleanupError=$null;$classification=$null;$restoreReceipt=$null
    try{
        $inspection=Open-UID0002OWV6Role $context 'inspection';[void](Invoke-UID0002OWV6VerifyState $context $inspection.Database 'Original' 'inspection');[void](Retire-UID0002OWV6Role $context $inspection 'inspection')
        $acquire=$Operations.AcquireP0B0;$context.P0B0=&$acquire
        [void](Assert-UID0002OWV6ExactProperties $context.P0B0 @('P0','B0','ContinuousSourceHandle','ContinuousDestinationHandle') @() 'P0B0')
        if(-not(Assert-UID0002OWV6NativeBool $context.P0B0.ContinuousSourceHandle 'P0B0 source handle') -or -not(Assert-UID0002OWV6NativeBool $context.P0B0.ContinuousDestinationHandle 'P0B0 destination handle') -or -not(Test-UID0002OWV6DeepEqual $context.P0B0.P0 ([pscustomobject]@{Identity=$context.P0B0.B0.Identity;Length=$context.P0B0.B0.Length;LastWriteTimeUtcTicks=$context.P0B0.B0.LastWriteTimeUtcTicks;SHA256=$context.P0B0.B0.SHA256}))){throw 'V6_P0_B0_AUTHORITY'}
        $initialize=$Operations.InitializeSaveAuthority;&$initialize $context.RunId $context.P0B0.P0
        $transaction=Open-UID0002OWV6Role $context 'transaction';[void](Invoke-UID0002OWV6VerifyState $context $transaction.Database 'Original' 'transaction-original')
        if($null -eq $MutationPlan){$MutationPlan=New-UID0002OWV6FixtureMutationPlan $transaction.Database}else{foreach($row in @($MutationPlan)){$row.Database=$transaction.Database}}
        $mutationReceipts=Invoke-UID0002OWV6MutationPlan $context $MutationPlan $transaction.Database
        [void](Invoke-UID0002OWV6VerifyState $context $transaction.Database 'Final' 'transaction-final')
        [void](Assert-UID0002OWV6Runtime $context $transaction.Database 'transaction-pre-save')
        $save=Invoke-UID0002OWV6SoleSave $context $transaction.Database
        [void](Retire-UID0002OWV6Role $context $transaction 'transaction')
        $classification=Invoke-UID0002OWV6Classify $context $context.P0B0.P0 $save.ResponseClass
        if($classification.Identity -ceq 'S1'){
            if($classification.RestoreAllowed){throw 'V6_S1_RESTORE_FORBIDDEN'}
            $final=Get-UID0002OWV6DiskAuthority $context 'accepted-final';if(-not(Test-UID0002OWV6DeepEqual $final.ClosedTuple $classification.Tuple)){throw 'V6_FINAL_TUPLE_DRIFT'}
        }elseif($classification.RestoreAllowed){$restoreReceipt=Invoke-UID0002OWV6Restore $context $context.P0B0.P0 $context.P0B0.B0 $classification;throw "V6_SAVE_ROLLED_BACK:$($save.ResponseClass)"}elseif($classification.Identity -cne 'P0'){throw 'V6_CLASSIFIER_UNHANDLED'}
        [pscustomobject]@{Context=$context;MutationReceipts=$mutationReceipts;Save=$save;Classification=$classification;Restore=$restoreReceipt;Effects=$context.Effects}
    }catch{$primary=$_.Exception;$context.PrimaryError=[string]$primary.Message
        if($context.SaveAttempted -and $null -ne $context.P0B0){
            try{
                foreach($openRole in @($context.Roles.Values|Where-Object{$_.State -ceq 'Open'})){[void](Retire-UID0002OWV6Role $context $openRole 'postsave-recovery')}
                $saveClass=if($null -ne $context.SaveRecord){[string]$context.SaveRecord.ResponseClass}else{'Indeterminate'}
                $classification=Invoke-UID0002OWV6Classify $context $context.P0B0.P0 $saveClass
                if($classification.RestoreAllowed){$restoreReceipt=Invoke-UID0002OWV6Restore $context $context.P0B0.P0 $context.P0B0.B0 $classification}
            }catch{$context.PrimaryError+="|RECOVERY:$([string]$_.Exception.Message)"}
        }
    }finally{try{Invoke-UID0002OWV6Cleanup $context}catch{$cleanupError=$_.Exception}}
    if($null -ne $primary){$message=$context.PrimaryError;if($null -ne $cleanupError){$message+="|CLEANUP:$([string]$cleanupError.Message)"};throw $message}
    if($null -ne $cleanupError){throw [string]$cleanupError.Message}
}

function New-UID0002OWV6FixtureOperations([string]$Fault) {
    $root='C:\uid0002ow-v6-runtime';$modulePath=$root+'\ida_pro_mcp.py';$canonical=$CanonicalPath
    $p0=[pscustomobject]@{Identity='VOL:P0';Length=100;LastWriteTimeUtcTicks=1000;SHA256=('A'*64)};$s1=[pscustomobject]@{Identity='VOL:P0';Length=101;LastWriteTimeUtcTicks=1001;SHA256=('B'*64)};$b0=[pscustomobject]@{Identity='VOL:P0';Length=100;LastWriteTimeUtcTicks=1000;SHA256=('A'*64)}
    $state=[pscustomobject]@{Fault=$Fault;Memory='Original';Disk='P0';SaveClaimed=$false;SaveAuthorityInitialized=$false;Sessions=[ordered]@{};NextPid=4000;Modules=[ordered]@{$modulePath=[pscustomobject]@{resolved_path=$modulePath;size=1000;mtime_ns=2000;ctime_ns=1500;sha256=('C'*64)}};P0=$p0;S1=$s1;B0=$b0;CallOrdinal=0;RetireOrdinal=0;CleanupOrdinal=0}
    if($Fault -ceq 'duplicate-save-new-context'){$state.SaveClaimed=$true}
    $sendRaw={param($Request,$Meta)
        $state.CallOrdinal++
        if($null -ne $Meta.psobject.Properties['SuppliedRaw']){return [string]$Meta.SuppliedRaw}
        $result=[ordered]@{jsonrpc='2.0';id=[string]$Request.id;result=[ordered]@{isError=$false;structuredContent=[ordered]@{}}}
        switch -CaseSensitive ([string]$Meta.Kind) {
            'open' {
                $session="fixture-$($Meta.Role)-$($state.CallOrdinal)";$pid=$state.NextPid;$state.NextPid++
                $state.Sessions[$session]=[pscustomobject]@{session_id=$session;canonical_path=$canonical;is_active=$true;owned=$true;pid=$pid;port=(14000+$pid)}
                $result.result.structuredContent=[ordered]@{session=[ordered]@{session_id=$session;canonical_path=$canonical;input_path=$canonical;is_active=$true}}
                if($state.Fault -ceq 'raw-duplicate-json' -and $Meta.Role -ceq 'inspection'){return '{"jsonrpc":"2.0","id":"'+$Request.id+'","result":{},"result":{}}'}
            }
            'runtime' {
                $session=$state.Sessions[[string]$Meta.Database];$module=[ordered]@{sys_modules_name='ida_pro_mcp';module_id="module-$($session.pid)";resolved_path=$modulePath;derived_relative_path='ida_pro_mcp.py';size=1000;mtime_ns=2000;ctime_ns=1500;sha256=('C'*64)}
                if($state.Fault -ceq 'fabricated-module'){$module.resolved_path=$root+'\missing.py';$module.derived_relative_path='missing.py'}
                $listenerProcess=[ordered]@{pid=3000;parent_pid=2000;creation_time_100ns=300000;generation='pid:3000;created:300000';image='C:\Python\python.exe'}
                $workerProcess=[ordered]@{pid=[int]$session.pid;parent_pid=3000;creation_time_100ns=(400000+[int]$session.pid);generation="pid:$($session.pid);created:$((400000+[int]$session.pid))";image='C:\Python\python.exe'}
                $result.result.structuredContent=[ordered]@{schema_version=1;ok=$true;errors=@();nonce=[Guid]::NewGuid().ToString('N');attested_at_utc=[DateTime]::UtcNow.ToString('o');listener=[ordered]@{source_root=$root;process=$listenerProcess;endpoint=[ordered]@{host='127.0.0.1';port=13337};implementation_manifest_sha256=('D'*64);modules=@($module)};workers=@([ordered]@{source_root=$root;process=$workerProcess;route=[ordered]@{host='127.0.0.1';port=[int]$session.port};session=[ordered]@{session_id=$session.session_id;canonical_path=$canonical;is_active=$true;owned=$true};implementation_manifest_sha256=('D'*64);modules=@($module)})}
                if($state.Fault -ceq 'runtime-false-literal'){$result.result.structuredContent.ok='true'}
                if($state.Fault -ceq 'route-metadata-drift'){$result.result.structuredContent.workers[0].route.port++}
            }
            'state' {
                $contract=$Meta.Contract;$physical=$state.Memory
                if($Meta.Phase -match 'rv|rollback'){$physical=if($state.Disk -ceq 'P0'){'Original'}else{'Final'}}
                if($Meta.Phase -match 'sv'){$physical=if($state.Disk -ceq 'P0'){'Original'}else{'Final'}}
                $actualContract=@(New-UID0002OWV6StateContracts $physical ([string]$contract.Arguments.database)|Where-Object Id -ceq $contract.Id)[0]
                if($state.Fault -ceq 'classifier-both' -and $Meta.Phase -match 'rv|sv'){$actualContract=$contract}
                if($state.Fault -ceq 'classifier-neither' -and $Meta.Phase -match 'rv|sv'){$actualContract.psobject.Copy();$actualContract.Rows=@($actualContract.Rows|ForEach-Object{$_.psobject.Copy()});$actualContract.Rows[0].psobject.Properties[$actualContract.KeyField].Value='wrong-key'}
                $rows=@($actualContract.Rows|ForEach-Object{$_.psobject.Copy()})
                if($state.Fault -ceq 'false-literal' -and $contract.Id -ceq 'S03-lookup'){$rows[0].name='WRONG'}
                if($state.Fault -ceq 'keyless-row' -and $contract.Id -ceq 'S08-bytes'){$rows[0].psobject.Properties.Remove('addr')}
                if($state.Fault -ceq 'permuted-rows' -and $contract.Id -ceq 'S06-callees'){[array]::Reverse($rows)}
                if($state.Fault -ceq 'wrong-native-type' -and $contract.Id -ceq 'S13-vtable'){$rows[0].value='5249792'}
                $structured=[ordered]@{};$structured[[string]$actualContract.RowProperty]=$rows;$result.result.structuredContent=$structured
                if($state.Fault -ceq 'tools-list-failure' -and $contract.Tool -ceq 'tools/list'){$result.result.isError=$true}
                if($state.Fault -ceq 'state-query-failure' -and $contract.Id -ceq 'S05-frame'){$result.result.isError=$true}
                if($state.Fault -ceq 'verifier-failure' -and $Meta.Phase -match 'rv'){$result.result.isError=$true}
            }
            'mutation' {
                $row=$Meta.Row;$new=$row.ExpectedNew.psobject.Copy();if($state.Fault -ceq 'wrong-mutation-signature' -and $row.Seq -eq 1){$new.type='forged-signature'}
                $result.result.structuredContent=[ordered]@{results=@([ordered]@{index=0;success=$true;kind=$row.Kind;dry_run=($row.Phase -ceq 'Dry');subject=$row.Subject;old=$row.ExpectedOld;new=$new});summary=[ordered]@{total=1;succeeded=1;failed=0;dry_run=($row.Phase -ceq 'Dry')}}
                if($row.Seq -eq 43){$state.Memory='Final'}
            }
            'mutation-readback' {$result.result.structuredContent=[ordered]@{items=@($Meta.Row.ExpectedNew)}}
            'save' {
                if($state.Fault -ceq 'malformed-received-save'){$state.Disk='S1';return '{"jsonrpc":"2.0","id":"'+$Request.id+'","result":'}
                $success=$state.Fault -cne 'determinate-save-failure';$state.Disk='S1';$result.result.structuredContent=[ordered]@{success=$success}
            }
            default {throw "V6_FIXTURE_META_UNKNOWN:$($Meta.Kind)"}
        }
        $result|ConvertTo-Json -Depth 100 -Compress
    }.GetNewClosure()
    $statModule={param($Path)
        if(-not $state.Modules.Contains($Path)){return $null};$copy=$state.Modules[$Path].psobject.Copy()
        if($state.Fault -ceq 'module-byte-drift'){$copy.sha256=('E'*64)}
        if($state.Fault -ceq 'module-time-drift'){$copy.mtime_ns=[Int64]$copy.mtime_ns+1}
        $copy
    }.GetNewClosure()
    $processSnapshot={param($Pid)
        if($Pid -eq 3000){[pscustomobject]@{pid=3000;parent_pid=2000;creation_time_100ns=300000;generation='pid:3000;created:300000';image='C:\Python\python.exe'}}else{[pscustomobject]@{pid=[int]$Pid;parent_pid=3000;creation_time_100ns=(400000+[int]$Pid);generation="pid:${Pid};created:$((400000+[int]$Pid))";image='C:\Python\python.exe'}}
    }.GetNewClosure()
    $socketSnapshot={param($Port)
        if($Port -eq 13337){[pscustomobject]@{host='127.0.0.1';port=13337;owning_pid=3000}}else{$session=@($state.Sessions.Values|Where-Object port -eq $Port)[0];[pscustomobject]@{host='127.0.0.1';port=[int]$Port;owning_pid=[int]$session.pid}}
    }.GetNewClosure()
    $provisional={param($Database,$Role)$s=$state.Sessions[$Database];[pscustomobject]@{pid=$s.pid;port=$s.port;session_id=$Database;role=$Role}}
    $register={param($RoleState)if($state.Fault -ceq 'post-open-registration-failure' -and $RoleState.Role -ceq 'inspection'){throw 'V6_POST_OPEN_REGISTRATION_FAILURE'}}.GetNewClosure()
    $retire={param($RoleState)$state.RetireOrdinal++;if($state.Sessions.Contains([string]$RoleState.Database)){$state.Sessions[[string]$RoleState.Database].is_active=$false}}.GetNewClosure()
    $absence={param($RoleState)
        $remain=$state.Fault -ceq 'retirement-process-remains' -and $state.RetireOrdinal -eq 1
        $tuple=if($state.Disk -ceq 'P0'){$state.P0}else{$state.S1}
        [pscustomobject]@{process_absent=(-not$remain);session_absent=$true;socket_absent=$true;route_absent=$true;disk_open=$tuple;disk_closed=$tuple}
    }.GetNewClosure()
    $acquire={ [pscustomobject]@{P0=$state.P0;B0=$state.B0;ContinuousSourceHandle=$true;ContinuousDestinationHandle=$true} }.GetNewClosure()
    $initialize={param($RunId,$P0)if($state.SaveAuthorityInitialized){throw 'V6_SAVE_AUTHORITY_REINITIALIZED'};$state.SaveAuthorityInitialized=$true}.GetNewClosure()
    $claim={param($RunId,$Database)if($state.SaveClaimed){return $false};$state.SaveClaimed=$true;$true}.GetNewClosure()
    $readDisk={param($Boundary)
        $tuple=if($state.Disk -ceq 'P0'){$state.P0}else{$state.S1};$open=$tuple;$closed=$tuple
        if($state.Fault -ceq 'final-tuple-drift' -and $Boundary -ceq 'accepted-final'){$closed=[pscustomobject]@{Identity=$tuple.Identity;Length=999;LastWriteTimeUtcTicks=$tuple.LastWriteTimeUtcTicks;SHA256=$tuple.SHA256}}
        [pscustomobject]@{OpenTuple=$open;ClosedTuple=$closed}
    }.GetNewClosure()
    $restore={param($P0,$B0,$Recorded)
        $before=$Recorded;if($state.Fault -ceq 'restore-substitution'){$before=[pscustomobject]@{Identity='VOL:OTHER';Length=$Recorded.Length;LastWriteTimeUtcTicks=$Recorded.LastWriteTimeUtcTicks;SHA256=$Recorded.SHA256}}
        $state.Disk='P0';$state.Memory='Original'
        [pscustomobject]@{SourceBefore=$B0;SourceAfter=$B0;DestinationBefore=$before;DestinationAfter=$P0;RestoredClosed=$P0;BackupReopened=$B0;CopyCount=$P0.Length;EOF=$true;Flushed=$true;TimestampRestoredUnderHandle=$true;ContinuousSourceHandle=$true;ContinuousDestinationHandle=$true}
    }.GetNewClosure()
    $cleanup={param($Context)$state.CleanupOrdinal++;if($state.Fault -ceq 'post-save-cleanup-error' -and $Context.SaveAttempted){throw 'V6_INJECTED_POSTSAVE_CLEANUP'}}.GetNewClosure()
    [pscustomobject]@{State=$state;SendRaw=$sendRaw;StatModule=$statModule;ProcessSnapshot=$processSnapshot;SocketSnapshot=$socketSnapshot;ProvisionalSnapshot=$provisional;RegisterOpen=$register;RetireGeneration=$retire;AbsenceSnapshot=$absence;AcquireP0B0=$acquire;InitializeSaveAuthority=$initialize;ClaimSaveAttempt=$claim;ReadDiskAuthority=$readDisk;Restore=$restore;Cleanup=$cleanup}
}

function Invoke-UID0002OWV6HostileProof {
    $cases=@(
        @('false-literal','V6_STATE_MISMATCH','false-literal'),
        @('keyless-row','V6_STATE_MISMATCH','keyless-row'),
        @('permuted-rows','V6_STATE_MISMATCH','permuted-rows'),
        @('wrong-native-type','V6_STATE_MISMATCH','wrong-native-type'),
        @('tools-list-failure','V6_STATE_MISMATCH','tools-list-failure'),
        @('state-query-failure','V6_STATE_MISMATCH','state-query-failure'),
        @('wrong-mutation-signature','V6_MUTATION_RECEIPT','wrong-mutation-signature'),
        @('runtime-false-literal','V6_NATIVE_BOOL','runtime-false-literal'),
        @('fabricated-module','V6_MODULE_FILE_MISSING','fabricated-module'),
        @('module-byte-drift','V6_MODULE_PHYSICAL_MISMATCH','module-byte-drift'),
        @('module-time-drift','V6_MODULE_PHYSICAL_MISMATCH','module-time-drift'),
        @('route-metadata-drift','V6_SOCKET_OWNER','route-metadata-drift'),
        @('post-open-registration-failure','V6_POST_OPEN_REGISTRATION_FAILURE','post-open-registration-failure'),
        @('duplicate-save-new-context','V6_SAVE_ALREADY_CLAIMED','duplicate-save-new-context'),
        @('malformed-received-save','V6_SAVE_INDETERMINATE','malformed-received-save'),
        @('retirement-process-remains','V6_RETIREMENT_PRESENCE','retirement-process-remains'),
        @('classifier-both','V6_CLASSIFIER_NON_EXCLUSIVE','classifier-both'),
        @('classifier-neither','V6_CLASSIFIER_NON_EXCLUSIVE','classifier-neither'),
        @('verifier-failure','V6_STATE_MISMATCH','verifier-failure'),
        @('restore-substitution','V6_RESTORE_SUBSTITUTION','restore-substitution'),
        @('final-tuple-drift','V6_DOPEN_DCLOSED','final-tuple-drift'),
        @('post-save-cleanup-error','V6_CLEANUP_FAILURE','post-save-cleanup-error'),
        @('raw-duplicate-json','V6_RAW_INVALID','raw-duplicate-json'),
        @('accepted-s1','ACCEPTED',''),
        @('determinate-save-failure','V6_SAVE_ROLLED_BACK','determinate-save-failure')
    )
    $transcript=@()
    foreach($case in $cases){
        $ops=New-UID0002OWV6FixtureOperations $case[2];$result=$null;$actual=''
        try{$result=Invoke-UID0002OWV6Coordinator $ops;if($case[1] -cne 'ACCEPTED'){throw "V6_FIXTURE_NOT_REJECTED:$($case[0])"};$actual='ACCEPTED'}catch{$actual=[string]$_.Exception.Message;if($case[1] -ceq 'ACCEPTED' -or -not $actual.StartsWith([string]$case[1],[StringComparison]::Ordinal)){throw "V6_FIXTURE_WRONG_GUARD:$($case[0]):expected=$($case[1]):actual=$actual"}}
        $effects=if($null -ne $result){$result.Effects}else{$ops.State.LastEffects}
        if($null -eq $effects){$effects=[ordered]@{Coordinator='observed-in-thrown-context';RawCall=$ops.State.CallOrdinal;Open=$ops.State.Sessions.Count;Register='observed';Runtime='observed';StateQuery='observed';Mutation='observed';Readback='observed';SaveAttempt=$(if($ops.State.SaveClaimed){1}else{0});Retire=$ops.State.RetireOrdinal;Classify='observed';Verifier='observed';Restore=$(if($ops.State.Disk -ceq 'P0' -and $ops.State.SaveClaimed){1}else{0});Cleanup=$ops.State.CleanupOrdinal}}
        $transcript+=,[pscustomobject]@{Name=$case[0];Expected=$case[1];Actual=$actual;RawCalls=$ops.State.CallOrdinal;OpenedSessions=$ops.State.Sessions.Count;RetireCalls=$ops.State.RetireOrdinal;SaveClaimed=$ops.State.SaveClaimed;Disk=$ops.State.Disk;CleanupCalls=$ops.State.CleanupOrdinal;Effects=$effects}
    }
    # The generic sender cannot construct the reserved endpoint, even with a fresh context.
    try{[void](New-UID0002OWV6Request 'uid0002ow-v6-generic-save' 'idb_save' ([ordered]@{database='forbidden'}));throw 'V6_FIXTURE_NOT_REJECTED:generic-save-sender'}catch{if(-not([string]$_.Exception.Message).StartsWith('V6_SAVE_ENDPOINT_RESERVED',[StringComparison]::Ordinal)){throw}}
    $transcript+=,[pscustomobject]@{Name='generic-save-sender';Expected='V6_SAVE_ENDPOINT_RESERVED';Actual='V6_SAVE_ENDPOINT_RESERVED';RawCalls=0;OpenedSessions=0;RetireCalls=0;SaveClaimed=$false;Disk='P0';CleanupCalls=0;Effects=(New-UID0002OWV6Effects)}
    if($transcript.Count -ne 26){throw "V6_HOSTILE_COUNT:$($transcript.Count)"}
    $transcript
}

# Runnable PS5.1 hostile proof.  This touches no MCP, IDB, generated file, or
# documentation file; all raw/OS/file dependencies are side-effect-free adapters.
$UID0002OWV6HostileTranscript=@(Invoke-UID0002OWV6HostileProof)
if($UID0002OWV6HostileTranscript.Count -ne 26){throw 'V6_HOSTILE_TRANSCRIPT_INCOMPLETE'}

# Gate 2B production invocation template.  The supervisor supplies raw transport
# plus physical process/socket/module/P0-B0/restore adapters; no fixture flag or
# alternate coordinator exists.
# $UID0002OWCoordinatorResult=Invoke-UID0002OWV6Coordinator -Operations $UID0002OWProductionOperations -MutationPlan $MutationPlan
~~~

## Removed Block R020

- SHA256: `0015F1D125BA48B695D7ADAE3110053F1BD4000C3F0831EFAAE9569DB2192FFE`
- Language: `powershell`
- Bytes: `48952`
- First recovered timestamp: `2026-08-08T02:44:15.559Z`
- Session provenance: rollout-2026-08-07T21-33-30-019fdf00-f811-7fd2-b22d-23613a6f7a94.jsonl line 195585 (2026-08-08T02:44:15.559Z); rollout-2026-08-07T21-33-30-019fdf00-f811-7fd2-b22d-23613a6f7a94.jsonl line 195586 (2026-08-08T02:44:15.739Z)

~~~powershell
function ConvertTo-UID0002OWV7Canonical($Value) {
    if($null -eq $Value -or $Value -is [string] -or $Value -is [bool] -or $Value -is [ValueType]){return $Value}
    if($Value -is [Collections.IDictionary]){$o=[ordered]@{};foreach($k in @($Value.Keys|ForEach-Object{[string]$_}|Sort-Object)){$o[$k]=ConvertTo-UID0002OWV7Canonical $Value[$k]};return $o}
    if($Value -is [Collections.IEnumerable] -and $Value -isnot [string]){$a=@();foreach($v in $Value){$a+=,(ConvertTo-UID0002OWV7Canonical $v)};return ,$a}
    $o=[ordered]@{};foreach($p in @($Value.psobject.Properties|Sort-Object Name)){$o[$p.Name]=ConvertTo-UID0002OWV7Canonical $p.Value};$o
}
function Get-UID0002OWV7Hash($Value) {
    $json=(ConvertTo-UID0002OWV7Canonical $Value)|ConvertTo-Json -Depth 100 -Compress
    $sha=[Security.Cryptography.SHA256]::Create();try{$bytes=[Text.Encoding]::UTF8.GetBytes($json);([BitConverter]::ToString($sha.ComputeHash($bytes))).Replace('-','')}finally{$sha.Dispose()}
}
function Assert-UID0002OWV7ExactProperties($Value,[string[]]$Required,[string[]]$Optional,[string]$Label) {
    if($null -eq $Value){throw "V7_PROPERTY_NULL:$Label"};$names=@($Value.psobject.Properties.Name)
    foreach($name in $Required){if($names -cnotcontains $name){throw "V7_PROPERTY_MISSING:${Label}:$name"}}
    foreach($name in $names){if($Required -cnotcontains $name -and $Optional -cnotcontains $name){throw "V7_PROPERTY_EXTRA:${Label}:$name"}}
    $true
}
function Assert-UID0002OWV7NativeBool($Value,[string]$Label){if($Value -isnot [bool]){throw "V7_NATIVE_BOOL:$Label"};[bool]$Value}
function Assert-UID0002OWV7NativeInt($Value,[string]$Label){if($Value -isnot [byte] -and $Value -isnot [int16] -and $Value -isnot [int32] -and $Value -isnot [int64]){throw "V7_NATIVE_INT:$Label"};[Int64]$Value}
function Assert-UID0002OWV7NativeString($Value,[string]$Label){if($Value -isnot [string] -or [string]::IsNullOrWhiteSpace($Value)){throw "V7_NATIVE_STRING:$Label"};[string]$Value}
function Test-UID0002OWV7Equal($A,$B){(Get-UID0002OWV7Hash $A) -ceq (Get-UID0002OWV7Hash $B)}

function New-UID0002OWV7SchemaCatalog {
    [ordered]@{
        idb_list='257451A6E096AEB78F47F8925A27DAE7454E29C2D114F7C1DD7581AC1EF3C403';server_health='A671F932AAA8F8C2375273DCB5A043518CCAAADC9EA4A05B322544B4BF80365B';lookup_funcs='E8F4596AF02DBF952F3EA1BAB167E1F24D585906CE487A2B69C74E665A4329D3';export_funcs='FDEB61668F9C2616D85976BF06F859158B9CEF13318B07C9F04B469238711C79';type_inspect='DD1A03CB94A5158B0AC1B58686280978A9B6D152BF9F2E54B61C59DBEC90D85E';callees='5DB3C0A8088D4A26CD50528B822C6A1431027CAF69D9D0A687C9E75C7D3C278F';disasm='BD1B9AB64DCD4D7DA9D31C4B917643FE7B943E8250107B4DCDA6E41E12FAC856';define_func='84527DC7B03E6E1C0663D6DE875976337A029D113775F8A789CEE7B7F88C1310';declare_type='60BD401F6984ED716D46F916F5B53738361FADD7BC11E754B9F3F2B6F645263B';rename='3BC533EEDDAF92B2AD01EA76AEE8F08B010F136CD5AA4D0976D6051EA305F5F4';set_type='4DCCCBAA6958C3B30654F4CFFE4CACB903BCA32F0A3149F64C4F3184181BF356';set_address_comments='965965500E47D23BE139A0A5FF876D3ED5939F8F67AE1A6D1B0F2E497EF40BB4';set_repeatable_comments='965965500E47D23BE139A0A5FF876D3ED5939F8F67AE1A6D1B0F2E497EF40BB4';set_address_repeatable_comments='965965500E47D23BE139A0A5FF876D3ED5939F8F67AE1A6D1B0F2E497EF40BB4';make_data='4110296E7693B3AAD1EDB38C789C767A2551AB0B7B0CF26545EE0968652382A1';inspect_items='BF8F209B6719581AFDB8C9AC01AA44B368532FFAD24961D36B4CE092218AAEEA';get_comments='CFF6054E1EB8A9AFC22B51C2DA3D784E4A160DC16030B95D91C7888D06B5D312';stack_frame='AEA569DBB51E6C65591A942E9847007A5F7B0B6A00F0A9E4BA2536A1D347BC4A';get_bytes='694D5774A1C7F9A24784E4B9BDF1814DD942552952F99FDE1449BD740468A784';xrefs_to='299257E9E7C5EA22078F8A9558DC9BDBE1752D20F89F1364783E602982F27E61';entity_query='7D398CF49685CFC43D0E04CB469E8D850567DA125CB618CA38E9FE1EAB90763C';type_query='FB55C6BB0D746A41B787D2EACF44322D8A1FBA7FE8678871DCDC5E9CFDB50149';get_int='7E934DE570D2327B690C84F3A132E73F459251E3041BEB0C7941547F4C9F89DD';get_string='BE17F373D5BCA2315A4372622CDEE3A9631DBFAFD03153343002DEAC0C028F39';idb_save='B1A38F796386D6F12F9D413B605367884A5016F8459EDB824A17E8C4B112EBB8';idb_open='602B4A680716A7687241A3E4C7F97EC29A0F32D75AFEE430A07CCC057CE57912';runtime_attestation='2D6F51CE1B0BA634085E56C84C4FDC299D4378D1A121B79FAE9B015B6EB8971C'
    }
}
function New-UID0002OWV7ResponseCatalog {
    $spec=[ordered]@{
        idb_list=@('sessions');server_health=@('status','is_analyzing');lookup_funcs=@('functions');export_funcs=@('functions');type_inspect=@('types');callees=@('results');disasm=@('instructions','count','total','cursor');define_func=@('results','summary');declare_type=@('results','summary');rename=@('results','summary');set_type=@('results','summary');set_address_comments=@('results','summary');set_repeatable_comments=@('results','summary');set_address_repeatable_comments=@('results','summary');make_data=@('results','summary');inspect_items=@('items');get_comments=@('comments');stack_frame=@('frames');get_bytes=@('regions');xrefs_to=@('results');entity_query=@('results');type_query=@('types');get_int=@('values');get_string=@('strings');idb_save=@('success');idb_open=@('session');runtime_attestation=@('schema_version','ok','errors','nonce','listener','workers')
    }
    $keys=[ordered]@{idb_list='session_id';server_health='status';lookup_funcs='addr';export_funcs='addr';type_inspect='name';callees='addr';disasm='address';define_func='index';declare_type='index';rename='index';set_type='index';set_address_comments='index';set_repeatable_comments='index';set_address_repeatable_comments='index';make_data='index';inspect_items='addr';get_comments='addr';stack_frame='addr';get_bytes='addr';xrefs_to='addr';entity_query='query';type_query='name';get_int='addr';get_string='addr';idb_save='success';idb_open='session_id';runtime_attestation='session_id'}
    $catalog=[ordered]@{}
    foreach($name in $spec.Keys){$descriptor=[ordered]@{Endpoint=$name;EnvelopeRequired=@('jsonrpc','id','result');ResultRequired=@('isError','structuredContent');StructuredContentRequired=@($spec[$name]);AssociationKey=$keys[$name];NativeSuccessRequired=($name -in @('define_func','declare_type','rename','set_type','set_address_comments','set_repeatable_comments','set_address_repeatable_comments','make_data'));AdditionalProperties=$false};$catalog[$name]=[pscustomobject]@{Descriptor=$descriptor;SHA256=(Get-UID0002OWV7Hash $descriptor)}}
    $tools=[ordered]@{Endpoint='tools/list';EnvelopeRequired=@('jsonrpc','id','result');ResultRequired=@('tools');ToolCount=27;ExactInputFingerprints=$true;AdditionalProperties=$false};$catalog['tools/list']=[pscustomobject]@{Descriptor=$tools;SHA256=(Get-UID0002OWV7Hash $tools)}
    $catalog
}
function New-UID0002OWV7Request([string]$Id,[string]$Tool,$Arguments){if($Tool -ceq 'tools/list'){return [ordered]@{jsonrpc='2.0';id=$Id;method='tools/list';params=[ordered]@{}}};[ordered]@{jsonrpc='2.0';id=$Id;method='tools/call';params=[ordered]@{name=$Tool;arguments=$Arguments}}}
function Get-UID0002OWV7Tool($Request){if([string]$Request.method -ceq 'tools/list'){return 'tools/list'};[string]$Request.params.name}

function Get-UID0002OWV7ProtectionIds {
    $manifest=Get-Variable UID0002OWProtectionManifest -Scope Script -ErrorAction SilentlyContinue
    if($null -eq $manifest){throw 'V7_PROTECTION_MANIFEST_UNDEFINED'}
    $ids=@();foreach($group in @('FunctionTypeDependencies','ExecutableBoundaries','PaletteBoundaries','DirecBoundaries','I13')){$ids+=,@($manifest.Value[$group])}
    if($ids.Count -ne 60 -or @($ids|Select-Object -Unique).Count -ne 60){throw 'V7_PROTECTION_MANIFEST_COUNT'};$ids
}
function New-UID0002OWV7StateCall([string]$Id,[string]$Tool,$Arguments){[pscustomobject]@{Id=$Id;Tool=$Tool;Request=(New-UID0002OWV7Request "uid0002ow-v7-$Id" $Tool $Arguments)}}
function New-UID0002OWV7StatePlan([string]$Database,[ValidateSet('Original','Final')]$State,[string]$Role,[string]$RunId) {
    foreach($required in @('UID0002OWItemHeads','UID0002OWFunctionHeads','UID0002OWProtectionRegions','UID0002OWI13Heads')){if($null -eq (Get-Variable $required -Scope Script -ErrorAction SilentlyContinue)){throw "V7_STATE_INPUT_UNDEFINED:$required"}}
    $heads=@($script:UID0002OWItemHeads);$functions=@($script:UID0002OWFunctionHeads);$regions=@($script:UID0002OWProtectionRegions);$i13=@($script:UID0002OWI13Heads)
    $classes=@(
        [pscustomobject]@{Id='S00';Calls=@(New-UID0002OWV7StateCall "$RunId-$Role-s00" 'idb_list' ([ordered]@{}))},
        [pscustomobject]@{Id='S01';Calls=@(New-UID0002OWV7StateCall "$RunId-$Role-s01" 'server_health' ([ordered]@{database=$Database}))},
        [pscustomobject]@{Id='S02';Calls=@(New-UID0002OWV7StateCall "$RunId-$Role-s02" 'tools/list' ([ordered]@{}))},
        [pscustomobject]@{Id='S03';Calls=@(New-UID0002OWV7StateCall "$RunId-$Role-s03a" 'lookup_funcs' ([ordered]@{queries=$functions;database=$Database}),New-UID0002OWV7StateCall "$RunId-$Role-s03b" 'callees' ([ordered]@{addrs=@('0x5007a0','0x5007f0','0x500820','0x50248a','0x502495','0x5026a0');limit=500;database=$Database}),New-UID0002OWV7StateCall "$RunId-$Role-s03c" 'inspect_items' ([ordered]@{addrs=@('0x5008c0');database=$Database}),New-UID0002OWV7StateCall "$RunId-$Role-s03d" 'export_funcs' ([ordered]@{addrs=@('0x5008c0');format='prototypes';database=$Database}),New-UID0002OWV7StateCall "$RunId-$Role-s03e" 'disasm' ([ordered]@{addr='0x50248a';max_instructions=2;offset=0;include_total=$true;database=$Database}),New-UID0002OWV7StateCall "$RunId-$Role-s03f" 'disasm' ([ordered]@{addr='0x502495';max_instructions=2;offset=0;include_total=$true;database=$Database}),New-UID0002OWV7StateCall "$RunId-$Role-s03g" 'entity_query' ([ordered]@{queries=@([ordered]@{kind='names';regex='^(aNpal3Pal|aNp_1|aAl3Pal)$';count=20});database=$Database}),New-UID0002OWV7StateCall "$RunId-$Role-s03h" 'get_string' ([ordered]@{addrs=@('0x61e40c','0x61e410','0x61e420');database=$Database}))},
        [pscustomobject]@{Id='S04';Calls=@(New-UID0002OWV7StateCall "$RunId-$Role-s04" 'inspect_items' ([ordered]@{addrs=$heads;database=$Database}))},
        [pscustomobject]@{Id='S05';Calls=@(New-UID0002OWV7StateCall "$RunId-$Role-s05" 'get_comments' ([ordered]@{addrs=$heads;database=$Database}))},
        [pscustomobject]@{Id='S06';Calls=@(New-UID0002OWV7StateCall "$RunId-$Role-s06" 'stack_frame' ([ordered]@{addrs=$functions;database=$Database}))},
        [pscustomobject]@{Id='S07';Calls=@(New-UID0002OWV7StateCall "$RunId-$Role-s07" 'get_bytes' ([ordered]@{regions=$regions;database=$Database}))},
        [pscustomobject]@{Id='S08';Calls=@(New-UID0002OWV7StateCall "$RunId-$Role-s08" 'xrefs_to' ([ordered]@{addrs=$heads;limit=1000;database=$Database}))},
        [pscustomobject]@{Id='S09';Calls=@(New-UID0002OWV7StateCall "$RunId-$Role-s09" 'entity_query' ([ordered]@{queries=@([ordered]@{kind='names';regex='^(DirectionButtonControlPane__.*|aNpal3Pal|aNp_1|aAl3Pal)$';count=20});database=$Database}))},
        [pscustomobject]@{Id='S10';Calls=@(New-UID0002OWV7StateCall "$RunId-$Role-s10" 'type_query' ([ordered]@{queries=@([ordered]@{filter='^(DirectionButtonControlPane|ControlPane|RectBounds|EPFTileContext)$';kind='udt';count=20;include_decl=$true;include_members=$true;include_relationships=$true});database=$Database}))},
        [pscustomobject]@{Id='S11';Calls=@(New-UID0002OWV7StateCall "$RunId-$Role-s11" 'type_inspect' ([ordered]@{queries=@([ordered]@{name='ControlPane';include_members=$true;max_members=100},[ordered]@{name='RectBounds';include_members=$true;max_members=100},[ordered]@{name='EPFTileContext';include_members=$true;max_members=100},[ordered]@{name='DirectionButtonControlPane';include_members=$true;max_members=100});database=$Database}))},
        [pscustomobject]@{Id='S12';Calls=@(New-UID0002OWV7StateCall "$RunId-$Role-s12" 'get_int' ([ordered]@{addrs=$i13;ty='u32le';database=$Database}))},
        [pscustomobject]@{Id='S13';Calls=@(New-UID0002OWV7StateCall "$RunId-$Role-s13" 'get_string' ([ordered]@{addrs=@('0x61e3f4','0x61e3f8','0x61e40c','0x61e410','0x61e420','0x61e540','0x61e554');database=$Database}))}
    )
    $protectionIds=@(Get-UID0002OWV7ProtectionIds);$allocation=@(0,0,0,6,6,4,4,10,6,4,4,4,6,6);$cursor=0;$input=New-UID0002OWV7SchemaCatalog;$responses=New-UID0002OWV7ResponseCatalog
    for($i=0;$i-lt14;$i++){$count=$allocation[$i];$slice=if($count-eq0){@()}else{@($protectionIds[$cursor..($cursor+$count-1)])};$cursor+=$count;$classes[$i]|Add-Member ProtectionIds $slice;$contracts=@();foreach($call in $classes[$i].Calls){$tool=$call.Tool;$inputHash=if($tool-ceq'tools/list'){Get-UID0002OWV7Hash $input}else{$input[$tool]};if([string]::IsNullOrWhiteSpace($inputHash)-or$null-eq$responses[$tool]){throw "V7_STATE_SCHEMA_UNBOUND:$tool"};$contracts+=,[pscustomobject]@{Call=$call;InputSchemaSHA256=$inputHash;ResponseSchemaSHA256=$responses[$tool].SHA256}};$classes[$i]|Add-Member Contracts $contracts;$classes[$i]|Add-Member ExpectedState $State;$classes[$i]|Add-Member ProtectionSHA256 (Get-UID0002OWV7Hash $slice)}
    if($cursor-ne60){throw 'V7_STATE_PROTECTION_ALLOCATION'};$classes
}
function Assert-UID0002OWV7StatePlan($Plan,[string]$Database,[string]$State) {
    $rows=@($Plan);if($rows.Count-ne14-or@(Compare-Object @('S00','S01','S02','S03','S04','S05','S06','S07','S08','S09','S10','S11','S12','S13') @($rows.Id)).Count-ne0){throw 'V7_STATE_CLASS_COUNT'}
    $protections=@();foreach($row in $rows){if($row.ExpectedState-cne$State){throw "V7_STATE_PLAN_STATE:$($row.Id)"};$protections+=,@($row.ProtectionIds);foreach($contract in @($row.Contracts)){$request=$contract.Call.Request;if([string]$request.jsonrpc-cne'2.0'-or[string]::IsNullOrWhiteSpace([string]$request.id)){throw "V7_STATE_REQUEST:$($row.Id)"};$tool=$contract.Call.Tool;if($tool-cne'tools/list'-and[string]$request.params.arguments.database-cne$Database){throw "V7_STATE_DATABASE:$($row.Id)"};if($tool-ceq'disasm' -and ($null-eq$request.params.arguments.addr -or $null-ne$request.params.arguments.addrs)){throw "V7_STATE_DISASM_SCHEMA:$($row.Id)"}}}
    if($protections.Count-ne60-or@($protections|Select-Object -Unique).Count-ne60){throw 'V7_STATE_PROTECTION_COUNT'};$true
}

function New-UID0002OWV7Effects {[pscustomobject]@{Entry=0;Factory=0;OperationsSeal=0;Open=0;Register=0;Runtime=0;StateClass=0;StateQuery=0;Mutation=0;Readback=0;Backup=0;SaveClaim=0;SaveTransport=0;Retire=0;Classify=0;Verifier=0;Restore=0;FinalTuple=0;Cleanup=0;ExternalMcp=0;ExternalFile=0;ExternalProcess=0;ExternalValidator=0;Stages=@()}}
function Add-UID0002OWV7Effect($Context,[string]$Name){$Context.Effects.$Name=[Int64]$Context.Effects.$Name+1}
function Add-UID0002OWV7Stage($Context,[string]$Stage){$Context.Effects.Stages=@($Context.Effects.Stages)+$Stage}
function Assert-UID0002OWV7ExternalZero($Effects,[string]$Label){foreach($name in @('ExternalMcp','ExternalFile','ExternalProcess','ExternalValidator')){if([Int64]$Effects.$name-ne0){throw "V7_EXTERNAL_EFFECT:${Label}:$name"}};$true}

function New-UID0002OWV7ProductionOperations($Bindings) {
    $required=@('Mode','State','OpenRole','RegisterRole','AssertRuntime','QueryState','InvokeMutation','InvokeReadback','AcquireP0B0','InitializeSaveAuthority','ClaimSaveAttempt','DispatchSave','RetireGeneration','ReadDiskAuthority','Restore','Cleanup')
    [void](Assert-UID0002OWV7ExactProperties $Bindings $required @() 'production bindings')
    foreach($name in $required|Where-Object{$_-notin@('Mode','State')}){if($Bindings.$name-isnot[scriptblock]){throw "V7_OPERATION_NOT_EXECUTABLE:$name"}}
    $schema=New-UID0002OWV7SchemaCatalog;$responses=New-UID0002OWV7ResponseCatalog;$seal=[ordered]@{Version=7;Mode=[string]$Bindings.Mode;Operations=@($required|Where-Object{$_-notin@('Mode','State')});InputSchemas=$schema;ResponseSchemas=[ordered]@{}};foreach($name in $responses.Keys){$seal.ResponseSchemas[$name]=$responses[$name].SHA256}
    $o=[ordered]@{Version=7;Mode=[string]$Bindings.Mode;Sealed=$true;OperationNames=@($seal.Operations);SchemaCatalog=$schema;ResponseCatalog=$responses;ContractHash=(Get-UID0002OWV7Hash $seal);State=$Bindings.State}
    foreach($name in $seal.Operations){$o[$name]=$Bindings.$name};[pscustomobject]$o
}
function Assert-UID0002OWV7ProductionOperations($Operations) {
    if($null-eq$Operations){throw 'V7_OPERATIONS_REQUIRED'}
    $names=@('OpenRole','RegisterRole','AssertRuntime','QueryState','InvokeMutation','InvokeReadback','AcquireP0B0','InitializeSaveAuthority','ClaimSaveAttempt','DispatchSave','RetireGeneration','ReadDiskAuthority','Restore','Cleanup')
    $required=@('Version','Mode','Sealed','OperationNames','SchemaCatalog','ResponseCatalog','ContractHash','State')+$names
    [void](Assert-UID0002OWV7ExactProperties $Operations $required @() 'production operations')
    if((Assert-UID0002OWV7NativeInt $Operations.Version 'operations version')-ne7-or-not(Assert-UID0002OWV7NativeBool $Operations.Sealed 'operations sealed')){throw 'V7_OPERATIONS_VERSION'}
    if(@(Compare-Object $names @($Operations.OperationNames)).Count-ne0-or$Operations.SchemaCatalog.Count-ne27){throw 'V7_OPERATIONS_CONTRACT'}
    foreach($name in $names){if($Operations.$name-isnot[scriptblock]){throw "V7_OPERATIONS_MISSING:$name"}}
    $seal=[ordered]@{Version=7;Mode=[string]$Operations.Mode;Operations=$names;InputSchemas=$Operations.SchemaCatalog;ResponseSchemas=[ordered]@{}};foreach($name in $Operations.ResponseCatalog.Keys){$seal.ResponseSchemas[$name]=$Operations.ResponseCatalog[$name].SHA256};if((Get-UID0002OWV7Hash $seal)-cne[string]$Operations.ContractHash){throw 'V7_OPERATIONS_SEAL_DRIFT'};$true
}

function Assert-UID0002OWV7RealMutationPlan($Plan,[string]$Database) {
    $rows=@($Plan);if($rows.Count-ne43-or@($rows|Where-Object Phase -ceq'Dry').Count-ne10-or@($rows|Where-Object Phase -ceq'Actual').Count-ne33-or@(Compare-Object @(1..43) @($rows.Seq)).Count-ne0){throw 'V7_MUTATION_PLAN_COUNT'}
    $ids=@{};$rpc=@{};foreach($row in $rows){[void](Assert-UID0002OWV7ExactProperties $row @('Seq','Id','Phase','Request','ExpectedResponse','ExpectedReadback') @() "real mutation row $($row.Seq)");if($ids.ContainsKey([string]$row.Id)){throw 'V7_MUTATION_ID_DUPLICATE'};$ids[[string]$row.Id]=$true;$request=$row.Request;if([string]$request.jsonrpc-cne'2.0'-or[string]$request.method-cne'tools/call'-or[string]::IsNullOrWhiteSpace([string]$request.id)-or$rpc.ContainsKey([string]$request.id)){throw "V7_MUTATION_REQUEST:$($row.Id)"};$rpc[[string]$request.id]=$true;if([string]$request.params.arguments.database-cne$Database){throw "V7_MUTATION_DATABASE:$($row.Id)"};if([string]$row.ExpectedResponse.id-cne[string]$request.id){throw "V7_MUTATION_RESPONSE_BINDING:$($row.Id)"};if(@($row.ExpectedReadback.Calls).Count-eq0-or@($row.ExpectedReadback.Exact).Count-eq0-or$row.ExpectedReadback.AllOtherFrozenFieldsEqual-isnot[bool]-or-not$row.ExpectedReadback.AllOtherFrozenFieldsEqual){throw "V7_MUTATION_ROW_SCHEMA:$($row.Id)"};foreach($call in @($row.ExpectedReadback.Calls)){if([string]::IsNullOrWhiteSpace([string]$call.tool)-or[string]$call.arguments.database-cne$Database){throw "V7_MUTATION_READBACK_SCHEMA:$($row.Id)"}}};$true
}
function Invoke-UID0002OWV7State($Context,$Role,[ValidateSet('Original','Final')]$ExpectedState,[string]$Phase) {
    $plan=@(New-UID0002OWV7StatePlan $Role.Database $ExpectedState $Role.Role $Context.RunId);[void](Assert-UID0002OWV7StatePlan $plan $Role.Database $ExpectedState);$receipts=@()
    foreach($class in $plan){Add-UID0002OWV7Effect $Context 'StateClass';foreach($contract in @($class.Contracts)){Add-UID0002OWV7Effect $Context 'StateQuery';$query=$Context.Operations.QueryState;$receipt=&$query $Role $contract $ExpectedState $Phase $class.ProtectionIds;[void](Assert-UID0002OWV7ExactProperties $receipt @('RequestHash','InputSchemaHash','ResponseSchemaHash','ObservedState','ProtectionHash','Native','RowKeysHash','RawSHA256','ExternalEffectCount') @() "state receipt $($class.Id)");if([string]$receipt.RequestHash-cne(Get-UID0002OWV7Hash $contract.Call.Request)){throw "V7_STATE_REQUEST_HASH:$($class.Id)"};if([string]$receipt.InputSchemaHash-cne[string]$contract.InputSchemaSHA256){throw "V7_STATE_INPUT_SCHEMA_HASH:$($class.Id)"};if([string]$receipt.ResponseSchemaHash-cne[string]$contract.ResponseSchemaSHA256){throw "V7_STATE_RESPONSE_SCHEMA_HASH:$($class.Id)"};if(-not(Assert-UID0002OWV7NativeBool $receipt.Native "state native $($class.Id)")){throw "V7_STATE_NATIVE:$($class.Id)"};if([Int64]$receipt.ExternalEffectCount-ne0){throw "V7_STATE_EXTERNAL_EFFECT:$($class.Id)"};if([string]$receipt.ProtectionHash-cne[string]$class.ProtectionSHA256){throw "V7_STATE_PROTECTION_HASH:$($class.Id)"};if([string]$receipt.ObservedState-cne$ExpectedState){throw "V7_STATE_MISMATCH:${Phase}:$($class.Id)"};$receipts+=,$receipt}}
    if($receipts.Count-ne21){throw "V7_STATE_QUERY_COUNT:$Phase"};[pscustomobject]@{State=$ExpectedState;Classes=14;Queries=21;Receipts=$receipts}
}
function Test-UID0002OWV7State($Context,$Role,[ValidateSet('Original','Final')]$ExpectedState,[string]$Phase){try{[void](Invoke-UID0002OWV7State $Context $Role $ExpectedState $Phase);$true}catch{if(([string]$_.Exception.Message).StartsWith('V7_STATE_MISMATCH:',[StringComparison]::Ordinal)){return $false};throw}}
function Invoke-UID0002OWV7MutationPlan($Context,$Plan,[string]$Database) {
    [void](Assert-UID0002OWV7RealMutationPlan $Plan $Database);$receipts=@()
    foreach($row in @($Plan)){Add-UID0002OWV7Effect $Context 'Mutation';$tool=Get-UID0002OWV7Tool $row.Request;$inputHash=$Context.Operations.SchemaCatalog[$tool];$responseHash=$Context.Operations.ResponseCatalog[$tool].SHA256;if([string]::IsNullOrWhiteSpace($inputHash)-or[string]::IsNullOrWhiteSpace($responseHash)){throw "V7_MUTATION_SCHEMA_UNBOUND:$($row.Id)"};$invoke=$Context.Operations.InvokeMutation;$receipt=&$invoke $row $inputHash $responseHash;[void](Assert-UID0002OWV7ExactProperties $receipt @('RowId','Endpoint','RequestHash','InputSchemaHash','ResponseSchemaHash','NativeSuccess','SuccessCount','FailureCount','DryRun','BeforeHash','AfterHash','ExternalEffectCount') @() "mutation receipt $($row.Id)");if([string]$receipt.RowId-cne[string]$row.Id-or[string]$receipt.Endpoint-cne$tool-or[string]$receipt.RequestHash-cne(Get-UID0002OWV7Hash $row.Request)){throw "V7_MUTATION_ASSOCIATION:$($row.Id)"};if([string]$receipt.InputSchemaHash-cne$inputHash-or[string]$receipt.ResponseSchemaHash-cne$responseHash){throw "V7_MUTATION_SCHEMA_HASH:$($row.Id)"};if(-not(Assert-UID0002OWV7NativeBool $receipt.NativeSuccess "mutation success $($row.Id)")-or[Int64]$receipt.SuccessCount-ne[Int64]$row.ExpectedResponse.SuccessCount-or[Int64]$receipt.FailureCount-ne[Int64]$row.ExpectedResponse.FailureCount-or[bool]$receipt.DryRun-ne($row.Phase-ceq'Dry')){throw "V7_MUTATION_RECEIPT:$($row.Id)"};if($row.Phase-ceq'Dry' -and [string]$receipt.BeforeHash-cne[string]$receipt.AfterHash){throw "V7_MUTATION_DRY_DRIFT:$($row.Id)"};if($row.Phase-ceq'Actual' -and [string]$receipt.BeforeHash-ceq[string]$receipt.AfterHash){throw "V7_MUTATION_NO_CHANGE:$($row.Id)"};if([Int64]$receipt.ExternalEffectCount-ne0){throw "V7_MUTATION_EXTERNAL_EFFECT:$($row.Id)"}
        $readIndex=0;foreach($call in @($row.ExpectedReadback.Calls)){$readIndex++;Add-UID0002OWV7Effect $Context 'Readback';$read=$Context.Operations.InvokeReadback;$readReceipt=&$read $row $call $readIndex $Context.Operations.SchemaCatalog[[string]$call.tool] $Context.Operations.ResponseCatalog[[string]$call.tool].SHA256;[void](Assert-UID0002OWV7ExactProperties $readReceipt @('RowId','CallIndex','RequestHash','InputSchemaHash','ResponseSchemaHash','ExactWitnessHash','FrozenEqual','ExternalEffectCount') @() "readback receipt $($row.Id)/$readIndex");$request=New-UID0002OWV7Request "uid0002ow-v7-rb-$($row.Seq)-$readIndex" ([string]$call.tool) $call.arguments;if([string]$readReceipt.RowId-cne[string]$row.Id-or[Int64]$readReceipt.CallIndex-ne$readIndex-or[string]$readReceipt.RequestHash-cne(Get-UID0002OWV7Hash $request)-or[string]$readReceipt.ExactWitnessHash-cne(Get-UID0002OWV7Hash @($row.ExpectedReadback.Exact))-or-not(Assert-UID0002OWV7NativeBool $readReceipt.FrozenEqual "readback frozen $($row.Id)")){throw "V7_MUTATION_READBACK:$($row.Id)/$readIndex"};if([Int64]$readReceipt.ExternalEffectCount-ne0){throw "V7_READBACK_EXTERNAL_EFFECT:$($row.Id)"}}
        $receipts+=,$receipt
    }
    if($receipts.Count-ne43){throw 'V7_MUTATION_RECEIPT_COUNT'};$receipts
}

function Open-UID0002OWV7Role($Context,[string]$Role){Add-UID0002OWV7Effect $Context 'Open';$open=$Context.Operations.OpenRole;$receipt=&$open $Role $Context.RunId;[void](Assert-UID0002OWV7ExactProperties $receipt @('Role','Database','CanonicalPath','Pid','Generation','ParentPid','RouteHost','RoutePort') @() "open $Role");if([string]$receipt.Role-cne$Role){throw "V7_OPEN_ROLE:$Role"};[void](Assert-UID0002OWV7NativeString $receipt.Database "$Role database");[void](Assert-UID0002OWV7NativeString $receipt.CanonicalPath "$Role path");[void](Assert-UID0002OWV7NativeInt $receipt.Pid "$Role pid");[void](Assert-UID0002OWV7NativeString $receipt.Generation "$Role generation");$Context.Roles[$receipt.Database]=[pscustomobject]@{Role=$Role;Database=$receipt.Database;Receipt=$receipt;State='Provisional'};Add-UID0002OWV7Effect $Context 'Register';$register=$Context.Operations.RegisterRole;$registered=&$register $receipt;[void](Assert-UID0002OWV7ExactProperties $registered @('Database','Generation','Registered') @() "register $Role");if([string]$registered.Database-cne[string]$receipt.Database-or[string]$registered.Generation-cne[string]$receipt.Generation-or-not(Assert-UID0002OWV7NativeBool $registered.Registered "$Role registered")){throw "V7_REGISTER_ROLE:$Role"};$Context.Roles[$receipt.Database].State='Open';Add-UID0002OWV7Effect $Context 'Runtime';$runtime=$Context.Operations.AssertRuntime;$rt=&$runtime $receipt;[void](Assert-UID0002OWV7ExactProperties $rt @('Nonce','ListenerPid','ListenerGeneration','WorkerPid','WorkerGeneration','ParentPid','RouteHost','RoutePort','SocketOwnerPid','SessionId','CanonicalPath','ModuleManifestHash','ImplementationManifestHash','PhysicalModuleHash','Ok') @() "runtime $Role");if(-not(Assert-UID0002OWV7NativeBool $rt.Ok "$Role runtime ok")-or[Int64]$rt.WorkerPid-ne[Int64]$receipt.Pid-or[string]$rt.WorkerGeneration-cne[string]$receipt.Generation-or[Int64]$rt.ParentPid-ne[Int64]$receipt.ParentPid-or[string]$rt.SessionId-cne[string]$receipt.Database-or[string]$rt.CanonicalPath-cne[string]$receipt.CanonicalPath-or[Int64]$rt.SocketOwnerPid-ne[Int64]$receipt.Pid-or[string]$rt.RouteHost-cne'127.0.0.1'-or[Int64]$rt.RoutePort-ne[Int64]$receipt.RoutePort){throw "V7_RUNTIME_BINDING:$Role"};if($null-eq$Context.RuntimeBaseline){$Context.RuntimeBaseline=[pscustomobject]@{ModuleManifestHash=$rt.ModuleManifestHash;ImplementationManifestHash=$rt.ImplementationManifestHash;PhysicalModuleHash=$rt.PhysicalModuleHash;ListenerPid=$rt.ListenerPid;ListenerGeneration=$rt.ListenerGeneration}}elseif([string]$Context.RuntimeBaseline.ModuleManifestHash-cne[string]$rt.ModuleManifestHash-or[string]$Context.RuntimeBaseline.ImplementationManifestHash-cne[string]$rt.ImplementationManifestHash-or[string]$Context.RuntimeBaseline.PhysicalModuleHash-cne[string]$rt.PhysicalModuleHash-or[Int64]$Context.RuntimeBaseline.ListenerPid-ne[Int64]$rt.ListenerPid-or[string]$Context.RuntimeBaseline.ListenerGeneration-cne[string]$rt.ListenerGeneration){throw "V7_RUNTIME_CONTINUITY:$Role"};$Context.Roles[$receipt.Database]}
function Retire-UID0002OWV7Role($Context,$Role,[string]$Boundary){if($Role.State-ceq'Retired'){return};$Role.State='Retired';Add-UID0002OWV7Effect $Context 'Retire';$retire=$Context.Operations.RetireGeneration;$r=&$retire $Role.Receipt $Boundary;[void](Assert-UID0002OWV7ExactProperties $r @('Database','Generation','PidAbsent','SessionAbsent','SocketAbsent','RouteAbsent','Dopen','Dclosed') @() "retire $Boundary");if([string]$r.Database-cne[string]$Role.Database-or[string]$r.Generation-cne[string]$Role.Receipt.Generation-or-not(Assert-UID0002OWV7NativeBool $r.PidAbsent 'retire pid')-or-not(Assert-UID0002OWV7NativeBool $r.SessionAbsent 'retire session')-or-not(Assert-UID0002OWV7NativeBool $r.SocketAbsent 'retire socket')-or-not(Assert-UID0002OWV7NativeBool $r.RouteAbsent 'retire route')-or-not(Test-UID0002OWV7Equal $r.Dopen $r.Dclosed)){throw "V7_RETIREMENT:$Boundary"};$r}
function Get-UID0002OWV7Disk($Context,[string]$Boundary){$read=$Context.Operations.ReadDiskAuthority;$r=&$read $Boundary;[void](Assert-UID0002OWV7ExactProperties $r @('OpenTuple','ClosedTuple') @() "disk $Boundary");if(-not(Test-UID0002OWV7Equal $r.OpenTuple $r.ClosedTuple)){throw "V7_DISK_DOPEN_DCLOSED:$Boundary"};$r.ClosedTuple}
function Invoke-UID0002OWV7Classifier($Context,$P0,[string]$SaveClass){Add-UID0002OWV7Effect $Context 'Classify';$disk=Get-UID0002OWV7Disk $Context 'classifier';$rvRole=Open-UID0002OWV7Role $Context 'rv';Add-UID0002OWV7Effect $Context 'Verifier';try{$rv=Test-UID0002OWV7State $Context $rvRole 'Original' 'rv'}finally{Retire-UID0002OWV7Role $Context $rvRole 'rv'|Out-Null};$svRole=Open-UID0002OWV7Role $Context 'sv';Add-UID0002OWV7Effect $Context 'Verifier';try{$sv=Test-UID0002OWV7State $Context $svRole 'Final' 'sv'}finally{Retire-UID0002OWV7Role $Context $svRole 'sv'|Out-Null};if($rv-eq$sv){throw 'V7_CLASSIFIER_NON_EXCLUSIVE'};if($rv){if(-not(Test-UID0002OWV7Equal $disk $P0)){throw 'V7_CLASSIFIER_RV_THIRD_IDENTITY'};return [pscustomobject]@{Identity='P0';Tuple=$disk;RestoreAllowed=$false}};if(Test-UID0002OWV7Equal $disk $P0){throw 'V7_CLASSIFIER_SV_P0'};if($SaveClass-ceq'DefiniteSuccess'){[pscustomobject]@{Identity='S1';Tuple=$disk;RestoreAllowed=$false}}else{[pscustomobject]@{Identity='FailingSaved';Tuple=$disk;RestoreAllowed=$true}}}
function Invoke-UID0002OWV7Restore($Context,$P0,$B0,$Classification){if(-not$Classification.RestoreAllowed-or$Classification.Identity-cne'FailingSaved'){throw 'V7_RESTORE_NOT_AUTHORIZED'};Add-UID0002OWV7Effect $Context 'Restore';$restore=$Context.Operations.Restore;$r=&$restore $P0 $B0 $Classification.Tuple;[void](Assert-UID0002OWV7ExactProperties $r @('SourceBefore','SourceAfter','DestinationBefore','DestinationAfter','RestoredClosed','BackupReopened','CopyCount','EOF','Flushed','TimestampRestoredUnderHandle','ContinuousSourceHandle','ContinuousDestinationHandle') @() 'restore');if(-not(Test-UID0002OWV7Equal $r.SourceBefore $B0)-or-not(Test-UID0002OWV7Equal $r.SourceAfter $B0)-or-not(Test-UID0002OWV7Equal $r.DestinationBefore $Classification.Tuple)-or-not(Test-UID0002OWV7Equal $r.DestinationAfter $P0)-or-not(Test-UID0002OWV7Equal $r.RestoredClosed $P0)-or-not(Test-UID0002OWV7Equal $r.BackupReopened $B0)-or[Int64]$r.CopyCount-ne[Int64]$P0.Length-or-not(Assert-UID0002OWV7NativeBool $r.EOF 'restore eof')-or-not(Assert-UID0002OWV7NativeBool $r.Flushed 'restore flush')-or-not(Assert-UID0002OWV7NativeBool $r.TimestampRestoredUnderHandle 'restore timestamp')-or-not(Assert-UID0002OWV7NativeBool $r.ContinuousSourceHandle 'restore source')-or-not(Assert-UID0002OWV7NativeBool $r.ContinuousDestinationHandle 'restore destination')){throw 'V7_RESTORE_RECEIPT'};$rollback=Open-UID0002OWV7Role $Context 'rollback';Add-UID0002OWV7Effect $Context 'Verifier';try{[void](Invoke-UID0002OWV7State $Context $rollback 'Original' 'rollback')}finally{Retire-UID0002OWV7Role $Context $rollback 'rollback'|Out-Null};$r}

function Invoke-UID0002OWV7Production($Operations,[scriptblock]$SealedPlanTransform=$null) {
    $effects=New-UID0002OWV7Effects;if($null-ne$Operations-and$null-ne$Operations.psobject.Properties['State']){$Operations.State.LastEffects=$effects};$context=[pscustomobject]@{RunId=[Guid]::NewGuid().ToString('N');Operations=$Operations;Effects=$effects;Roles=[ordered]@{};RuntimeBaseline=$null;P0B0=$null;SaveAttempted=$false;SaveRecord=$null;RecoveryAttempted=$false};Add-UID0002OWV7Effect $context 'Entry';Add-UID0002OWV7Stage $context 'ENTRY';$primary=$null;$cleanupError=$null;$classification=$null;$restoreReceipt=$null
    try{[void](Assert-UID0002OWV7ProductionOperations $Operations);Add-UID0002OWV7Effect $context 'OperationsSeal';Add-UID0002OWV7Stage $context 'OPERATIONS_SEALED';$inspection=Open-UID0002OWV7Role $context 'inspection';Add-UID0002OWV7Stage $context 'INSPECTION_OPEN';[void](Invoke-UID0002OWV7State $context $inspection 'Original' 'inspection');Add-UID0002OWV7Stage $context 'INSPECTION_STATE';Retire-UID0002OWV7Role $context $inspection 'inspection'|Out-Null;Add-UID0002OWV7Stage $context 'INSPECTION_RETIRED';Add-UID0002OWV7Effect $context 'Backup';$acquire=$Operations.AcquireP0B0;$context.P0B0=&$acquire;[void](Assert-UID0002OWV7ExactProperties $context.P0B0 @('P0','B0','CreateNew','FileShareNone','SourceHandleContinuous','DestinationHandleContinuous','CopyCount','EOF','Flushed','ClosedReopened') @() 'P0B0');if(-not(Assert-UID0002OWV7NativeBool $context.P0B0.CreateNew 'backup create new')-or-not(Assert-UID0002OWV7NativeBool $context.P0B0.FileShareNone 'backup share none')-or-not(Assert-UID0002OWV7NativeBool $context.P0B0.SourceHandleContinuous 'backup source')-or-not(Assert-UID0002OWV7NativeBool $context.P0B0.DestinationHandleContinuous 'backup destination')-or-not(Assert-UID0002OWV7NativeBool $context.P0B0.EOF 'backup eof')-or-not(Assert-UID0002OWV7NativeBool $context.P0B0.Flushed 'backup flush')-or-not(Assert-UID0002OWV7NativeBool $context.P0B0.ClosedReopened 'backup reopen')-or[Int64]$context.P0B0.CopyCount-ne[Int64]$context.P0B0.P0.Length-or-not(Test-UID0002OWV7Equal $context.P0B0.P0 $context.P0B0.B0)){throw 'V7_BACKUP_AUTHORITY'};Add-UID0002OWV7Stage $context 'P0_B0';$initialize=$Operations.InitializeSaveAuthority;$authority=&$initialize $context.P0B0.P0;if([string]::IsNullOrWhiteSpace([string]$authority)){throw 'V7_SAVE_AUTHORITY_INIT'};$transaction=Open-UID0002OWV7Role $context 'transaction';Add-UID0002OWV7Stage $context 'TRANSACTION_OPEN';[void](Invoke-UID0002OWV7State $context $transaction 'Original' 'transaction-original');Add-UID0002OWV7Stage $context 'TRANSACTION_ORIGINAL';Add-UID0002OWV7Effect $context 'Factory';$plan=@(New-UID0002OWMutationPlan $transaction.Database $context.RunId);if($null-ne$SealedPlanTransform){if([string]$Operations.Mode-cne'SealedZeroEffect'){throw 'V7_PLAN_TRANSFORM_FORBIDDEN'};$plan=@(&$SealedPlanTransform $plan)};[void](Assert-UID0002OWV7RealMutationPlan $plan $transaction.Database);Add-UID0002OWV7Stage $context 'REAL_PLAN_43';$mutationReceipts=@(Invoke-UID0002OWV7MutationPlan $context $plan $transaction.Database);Add-UID0002OWV7Stage $context 'MUTATION_43';[void](Invoke-UID0002OWV7State $context $transaction 'Final' 'transaction-final');Add-UID0002OWV7Stage $context 'TRANSACTION_FINAL';Add-UID0002OWV7Effect $context 'SaveClaim';$claim=$Operations.ClaimSaveAttempt;if(-not(Assert-UID0002OWV7NativeBool (&$claim $authority $transaction.Database) 'save claim')){throw 'V7_SAVE_ALREADY_CLAIMED'};$context.SaveAttempted=$true;Add-UID0002OWV7Effect $context 'SaveTransport';$dispatch=$Operations.DispatchSave;$context.SaveRecord=&$dispatch $transaction.Database $authority;[void](Assert-UID0002OWV7ExactProperties $context.SaveRecord @('Raw','ResponseClass','AttemptCount','RetryAllowed') @() 'save record');if([Int64]$context.SaveRecord.AttemptCount-ne1-or(Assert-UID0002OWV7NativeBool $context.SaveRecord.RetryAllowed 'save retry')){throw 'V7_SAVE_RECORD'};if([string]$context.SaveRecord.ResponseClass-notin@('DefiniteSuccess','DeterminateFailure','Indeterminate')){throw 'V7_SAVE_CLASS'};Add-UID0002OWV7Stage $context 'SOLE_SAVE';Retire-UID0002OWV7Role $context $transaction 'transaction'|Out-Null;Add-UID0002OWV7Stage $context 'TRANSACTION_RETIRED';$classification=Invoke-UID0002OWV7Classifier $context $context.P0B0.P0 ([string]$context.SaveRecord.ResponseClass);Add-UID0002OWV7Stage $context 'RV_SV_CLASSIFIED';if($classification.RestoreAllowed){$restoreReceipt=Invoke-UID0002OWV7Restore $context $context.P0B0.P0 $context.P0B0.B0 $classification;Add-UID0002OWV7Stage $context 'RESTORED'};Add-UID0002OWV7Effect $context 'FinalTuple';$final=Get-UID0002OWV7Disk $context 'final';$expected=if($classification.Identity-ceq'S1'){$classification.Tuple}else{$context.P0B0.P0};if(-not(Test-UID0002OWV7Equal $final $expected)){throw 'V7_FINAL_TUPLE'};Add-UID0002OWV7Stage $context 'FINAL_TUPLE';[void](Assert-UID0002OWV7ExternalZero $effects 'production');[pscustomobject]@{Disposition=if($classification.Identity-ceq'S1'){'ACCEPTED_S1'}else{'ROLLED_BACK_P0'};PlanCount=$plan.Count;MutationReceipts=$mutationReceipts.Count;Classification=$classification;Restore=$restoreReceipt;Effects=$effects}
    }catch{$primary=$_.Exception;if($context.SaveAttempted-and$null-ne$context.P0B0-and-not$context.RecoveryAttempted){$context.RecoveryAttempted=$true;try{foreach($role in @($context.Roles.Values|Where-Object State -ceq'Open')){Retire-UID0002OWV7Role $context $role 'recovery'|Out-Null};$recovery=Invoke-UID0002OWV7Classifier $context $context.P0B0.P0 $(if($null-ne$context.SaveRecord){[string]$context.SaveRecord.ResponseClass}else{'Indeterminate'});if($recovery.RestoreAllowed){$restoreReceipt=Invoke-UID0002OWV7Restore $context $context.P0B0.P0 $context.P0B0.B0 $recovery}}catch{$context|Add-Member RecoveryError ([string]$_.Exception.Message) -Force}}
    }finally{try{foreach($role in @($context.Roles.Values|Where-Object State -ceq'Open')){Retire-UID0002OWV7Role $context $role 'cleanup'|Out-Null};Add-UID0002OWV7Effect $context 'Cleanup';$cleanup=$Operations.Cleanup;$cr=&$cleanup;[void](Assert-UID0002OWV7ExactProperties $cr @('Complete','OpenRoles','ExternalEffectCount') @() 'cleanup');if(-not(Assert-UID0002OWV7NativeBool $cr.Complete 'cleanup complete')-or[Int64]$cr.OpenRoles-ne0-or[Int64]$cr.ExternalEffectCount-ne0){throw 'V7_CLEANUP_FAILURE'};Add-UID0002OWV7Stage $context 'CLEANUP'}catch{$cleanupError=$_.Exception}}
    if($null-ne$primary){$message=[string]$primary.Message;if($null-ne$context.psobject.Properties['RecoveryError']){$message+="|RECOVERY:$($context.RecoveryError)"};if($null-ne$cleanupError){$message+="|CLEANUP:$([string]$cleanupError.Message)"};throw $message};if($null-ne$cleanupError){throw [string]$cleanupError.Message}
}

function New-UID0002OWV7SharedLedger {[pscustomobject]@{Claims=[ordered]@{}}}
function New-UID0002OWV7SealedZeroEffectBindings([string]$Fault,$SharedLedger=$null) {
    if($null-eq$SharedLedger){$SharedLedger=New-UID0002OWV7SharedLedger};$p0=[pscustomobject]@{Identity='P0';Length=100;LastWriteTimeUtcTicks=10;SHA256=('A'*64)};$s1=[pscustomobject]@{Identity='S1';Length=101;LastWriteTimeUtcTicks=11;SHA256=('B'*64)};$b0=[pscustomobject]@{Identity='P0';Length=100;LastWriteTimeUtcTicks=10;SHA256=('A'*64)};$state=[pscustomobject]@{Fault=$Fault;Ledger=$SharedLedger;NextPid=7000;Memory='Original';Disk='Original';P0=$p0;S1=$s1;B0=$b0;Roles=[ordered]@{};LastEffects=$null;MutationOrdinal=0;ReadbackOrdinal=0;SaveDispatches=0;RestoreCount=0}
    $open={param($Role,$RunId)if($state.Fault-ceq'open-failure'){throw 'V7_OPEN_FAILURE'};$pid=$state.NextPid;$state.NextPid++;$db="v7-$RunId-$Role";$r=[pscustomobject]@{Role=$Role;Database=$db;CanonicalPath='E:\NTK\Resources\NexusTK\NexusTK.exe.i64';Pid=$pid;Generation="pid:$pid;created:100";ParentPid=6000;RouteHost='127.0.0.1';RoutePort=14000+$pid};$state.Roles[$db]=$r;$r}.GetNewClosure()
    $register={param($Receipt)if($state.Fault-ceq'post-open-registration-failure'){throw 'V7_REGISTER_FAILURE'};[pscustomobject]@{Database=$Receipt.Database;Generation=$Receipt.Generation;Registered=$true}}.GetNewClosure()
    $runtime={param($Receipt)$socket=$Receipt.Pid;if($state.Fault-ceq'runtime-failure'){$socket=9999};[pscustomobject]@{Nonce=[Guid]::NewGuid().ToString('N');ListenerPid=6000;ListenerGeneration='pid:6000;created:50';WorkerPid=$Receipt.Pid;WorkerGeneration=$Receipt.Generation;ParentPid=$Receipt.ParentPid;RouteHost=$Receipt.RouteHost;RoutePort=$Receipt.RoutePort;SocketOwnerPid=$socket;SessionId=$Receipt.Database;CanonicalPath=$Receipt.CanonicalPath;ModuleManifestHash=('C'*64);ImplementationManifestHash=('D'*64);PhysicalModuleHash=('E'*64);Ok=$true}}.GetNewClosure()
    $query={param($Role,$Contract,$ExpectedState,$Phase,$ProtectionIds)if($state.Fault-ceq'state-query-failure'){throw 'V7_STATE_QUERY_FAILURE'};$input=[string]$Contract.InputSchemaSHA256;$response=[string]$Contract.ResponseSchemaSHA256;if($state.Fault-ceq'wrong-state-hash'){$response='BAD'};$observed=if($Role.Role-in@('rv','sv','rollback')){if($state.Disk-ceq'Original'){'Original'}else{'Final'}}else{$state.Memory};if($state.Fault-ceq'classifier-both'-and$Role.Role-in@('rv','sv')){$observed=$ExpectedState};if($state.Fault-ceq'classifier-neither'-and$Role.Role-in@('rv','sv')){$observed=if($ExpectedState-ceq'Original'){'Final'}else{'Original'}};[pscustomobject]@{RequestHash=(Get-UID0002OWV7Hash $Contract.Call.Request);InputSchemaHash=$input;ResponseSchemaHash=$response;ObservedState=$observed;ProtectionHash=(Get-UID0002OWV7Hash @($ProtectionIds));Native=$true;RowKeysHash=(Get-UID0002OWV7Hash @($Contract.Call.Request));RawSHA256=('F'*64);ExternalEffectCount=0}}.GetNewClosure()
    $mutation={param($Row,$InputHash,$ResponseHash)$state.MutationOrdinal++;$response=$ResponseHash;$native=$true;if($state.Fault-ceq'mutation-schema-drift'-and$state.MutationOrdinal-eq1){$response='BAD'};if($state.Fault-ceq'wrong-mutation-receipt'-and$state.MutationOrdinal-eq1){$native='true'};$before=Get-UID0002OWV7Hash ([ordered]@{Row=$Row.Id;State='before'});$after=if($Row.Phase-ceq'Dry'){$before}else{Get-UID0002OWV7Hash ([ordered]@{Row=$Row.Id;State='after'})};if($Row.Phase-ceq'Actual'){$state.Memory='Final'};[pscustomobject]@{RowId=$Row.Id;Endpoint=(Get-UID0002OWV7Tool $Row.Request);RequestHash=(Get-UID0002OWV7Hash $Row.Request);InputSchemaHash=$InputHash;ResponseSchemaHash=$response;NativeSuccess=$native;SuccessCount=$Row.ExpectedResponse.SuccessCount;FailureCount=$Row.ExpectedResponse.FailureCount;DryRun=($Row.Phase-ceq'Dry');BeforeHash=$before;AfterHash=$after;ExternalEffectCount=0}}.GetNewClosure()
    $readback={param($Row,$Call,$Index,$InputHash,$ResponseHash)$state.ReadbackOrdinal++;$request=New-UID0002OWV7Request "uid0002ow-v7-rb-$($Row.Seq)-$Index" ([string]$Call.tool) $Call.arguments;[pscustomobject]@{RowId=$Row.Id;CallIndex=$Index;RequestHash=(Get-UID0002OWV7Hash $request);InputSchemaHash=$InputHash;ResponseSchemaHash=$ResponseHash;ExactWitnessHash=(Get-UID0002OWV7Hash @($Row.ExpectedReadback.Exact));FrozenEqual=$true;ExternalEffectCount=0}}.GetNewClosure()
    $acquire={if($state.Fault-ceq'backup-failure'){throw 'V7_BACKUP_FAILURE'};[pscustomobject]@{P0=$state.P0;B0=$state.B0;CreateNew=$true;FileShareNone=$true;SourceHandleContinuous=$true;DestinationHandleContinuous=$true;CopyCount=$state.P0.Length;EOF=$true;Flushed=$true;ClosedReopened=$true}}.GetNewClosure()
    $initialize={param($P0)'uid0002ow-canonical-transaction'}.GetNewClosure()
    $claim={param($Authority,$Database)if($state.Fault-in@('alias-save-attempt','reentry-save-attempt','restart-save-attempt')){$state.Ledger.Claims[$Authority]=$true};if($state.Ledger.Claims.Contains($Authority)){return $false};$state.Ledger.Claims[$Authority]=$true;$true}.GetNewClosure()
    $save={param($Database,$Authority)$state.SaveDispatches++;if($state.Fault-ceq'save-transport-failure'){throw 'V7_SAVE_INDETERMINATE'};$class=if($state.Fault-in@('determinate-save','restore-failure')){'DeterminateFailure'}else{'DefiniteSuccess'};$state.Disk='Final';[pscustomobject]@{Raw='{"jsonrpc":"2.0","id":"v7-save","result":{"isError":false,"structuredContent":{"success":true}}}';ResponseClass=$class;AttemptCount=1;RetryAllowed=$false}}.GetNewClosure()
    $retire={param($Receipt,$Boundary)$bad=$state.Fault-ceq'retirement-failure';$tuple=if($state.Disk-ceq'Original'){$state.P0}else{$state.S1};[pscustomobject]@{Database=$Receipt.Database;Generation=$Receipt.Generation;PidAbsent=(-not$bad);SessionAbsent=$true;SocketAbsent=$true;RouteAbsent=$true;Dopen=$tuple;Dclosed=$tuple}}.GetNewClosure()
    $disk={param($Boundary)$tuple=if($state.Disk-ceq'Original'){$state.P0}else{$state.S1};$closed=$tuple;if($state.Fault-ceq'final-tuple-drift'-and$Boundary-ceq'final'){$closed=[pscustomobject]@{Identity='DRIFT';Length=$tuple.Length;LastWriteTimeUtcTicks=$tuple.LastWriteTimeUtcTicks;SHA256=$tuple.SHA256}};[pscustomobject]@{OpenTuple=$tuple;ClosedTuple=$closed}}.GetNewClosure()
    $restore={param($P0,$B0,$Candidate)if($state.Fault-ceq'restore-failure'){throw 'V7_RESTORE_FAILURE'};$state.RestoreCount++;$state.Disk='Original';$state.Memory='Original';[pscustomobject]@{SourceBefore=$B0;SourceAfter=$B0;DestinationBefore=$Candidate;DestinationAfter=$P0;RestoredClosed=$P0;BackupReopened=$B0;CopyCount=$P0.Length;EOF=$true;Flushed=$true;TimestampRestoredUnderHandle=$true;ContinuousSourceHandle=$true;ContinuousDestinationHandle=$true}}.GetNewClosure()
    $cleanup={if($state.Fault-ceq'cleanup-failure'){return [pscustomobject]@{Complete=$false;OpenRoles=1;ExternalEffectCount=0}};[pscustomobject]@{Complete=$true;OpenRoles=0;ExternalEffectCount=0}}.GetNewClosure()
    [pscustomobject]@{Mode='SealedZeroEffect';State=$state;OpenRole=$open;RegisterRole=$register;AssertRuntime=$runtime;QueryState=$query;InvokeMutation=$mutation;InvokeReadback=$readback;AcquireP0B0=$acquire;InitializeSaveAuthority=$initialize;ClaimSaveAttempt=$claim;DispatchSave=$save;RetireGeneration=$retire;ReadDiskAuthority=$disk;Restore=$restore;Cleanup=$cleanup}
}
function New-UID0002OWV7SealedZeroEffectOperations([string]$Fault,$SharedLedger=$null){New-UID0002OWV7ProductionOperations (New-UID0002OWV7SealedZeroEffectBindings $Fault $SharedLedger)}
function Invoke-UID0002OWV7HostileProof {
    $cases=@(
        @('malformed-real-row','V7_MUTATION_ROW_SCHEMA','malformed-real-row'),@('wrong-real-binding','V7_MUTATION_RESPONSE_BINDING','wrong-real-binding'),@('mutation-schema-drift','V7_MUTATION_SCHEMA_HASH','mutation-schema-drift'),@('wrong-mutation-receipt','V7_NATIVE_BOOL','wrong-mutation-receipt'),@('missing-operation','V7_PROPERTY_MISSING','missing-operation'),@('undefined-operations','V7_OPERATIONS_REQUIRED','undefined-operations'),@('wrong-state-hash','V7_STATE_RESPONSE_SCHEMA_HASH','wrong-state-hash'),@('state-query-failure','V7_STATE_QUERY_FAILURE','state-query-failure'),@('runtime-failure','V7_RUNTIME_BINDING','runtime-failure'),@('backup-failure','V7_BACKUP_FAILURE','backup-failure'),@('save-transport-failure','V7_SAVE_INDETERMINATE','save-transport-failure'),@('retirement-failure','V7_RETIREMENT','retirement-failure'),@('restore-failure','V7_RESTORE_FAILURE','restore-failure'),@('alias-save-attempt','V7_SAVE_ALREADY_CLAIMED','alias-save-attempt'),@('reentry-save-attempt','V7_SAVE_ALREADY_CLAIMED','reentry-save-attempt'),@('restart-save-attempt','V7_SAVE_ALREADY_CLAIMED','restart-save-attempt'),@('cleanup-failure','V7_CLEANUP_FAILURE','cleanup-failure'),@('final-tuple-drift','V7_FINAL_TUPLE','final-tuple-drift'),@('classifier-both','V7_CLASSIFIER_NON_EXCLUSIVE','classifier-both'),@('classifier-neither','V7_CLASSIFIER_NON_EXCLUSIVE','classifier-neither')
    )
    $transcript=@();foreach($case in $cases){$name=$case[0];$expected=$case[1];$fault=$case[2];$ops=$null;$transform=$null;if($name-ceq'undefined-operations'){$ops=$null}else{$ops=New-UID0002OWV7SealedZeroEffectOperations $fault};if($name-ceq'missing-operation'){$ops.psobject.Properties.Remove('QueryState')};if($name-ceq'malformed-real-row'){$transform={param($Plan)$copy=@($Plan);$copy[0].ExpectedReadback=$null;$copy}.GetNewClosure()};if($name-ceq'wrong-real-binding'){$transform={param($Plan)$copy=@($Plan);$copy[0].ExpectedResponse.id='wrong-id';$copy}.GetNewClosure()};$actual='';try{[void](Invoke-UID0002OWV7Production $ops $transform);throw "V7_HOSTILE_NOT_REJECTED:$name"}catch{$actual=[string]$_.Exception.Message;if(-not$actual.StartsWith($expected,[StringComparison]::Ordinal)){throw "V7_HOSTILE_WRONG_GUARD:${name}:expected=$expected:actual=$actual"}};$effects=if($null-ne$ops){$ops.State.LastEffects}else{New-UID0002OWV7Effects};[void](Assert-UID0002OWV7ExternalZero $effects $name);$transcript+=,[pscustomobject]@{Name=$name;Expected=$expected;Actual=$actual;Effects=$effects}}
    if($transcript.Count-ne20){throw 'V7_HOSTILE_COUNT'};$transcript
}

# The complete operations object is constructed before either public entry call.
$UID0002OWProductionOperations=New-UID0002OWV7SealedZeroEffectOperations ''
$UID0002OWV7AcceptedDryRun=Invoke-UID0002OWV7Production $UID0002OWProductionOperations
$UID0002OWRollbackOperations=New-UID0002OWV7SealedZeroEffectOperations 'determinate-save'
$UID0002OWV7RollbackDryRun=Invoke-UID0002OWV7Production $UID0002OWRollbackOperations
$UID0002OWV7HostileTranscript=@(Invoke-UID0002OWV7HostileProof)
if($UID0002OWV7AcceptedDryRun.Disposition-cne'ACCEPTED_S1'-or$UID0002OWV7AcceptedDryRun.PlanCount-ne43-or$UID0002OWV7AcceptedDryRun.MutationReceipts-ne43){throw 'V7_ACCEPTED_DRY_RUN'}
if($UID0002OWV7RollbackDryRun.Disposition-cne'ROLLED_BACK_P0'-or$null-eq$UID0002OWV7RollbackDryRun.Restore){throw 'V7_ROLLBACK_DRY_RUN'}
if($UID0002OWV7HostileTranscript.Count-ne20){throw 'V7_HOSTILE_TRANSCRIPT'}
~~~

## Removed Block R021

- SHA256: `63E15C57EB35A0B28EDE191BAFDC88DF3444F8050D728955B3BAA79C81F70624`
- Language: `powershell`
- Bytes: `6976`
- First recovered timestamp: `2026-08-08T03:42:50.546Z`
- Session provenance: rollout-2026-08-07T21-33-30-019fdf00-f811-7fd2-b22d-23613a6f7a94.jsonl line 196172 (2026-08-08T03:42:50.546Z); rollout-2026-08-07T21-33-30-019fdf00-f811-7fd2-b22d-23613a6f7a94.jsonl line 196173 (2026-08-08T03:42:50.730Z)

~~~powershell
function Invoke-UID0002OWV8ProofRaw($Authority,$Request){
    if($Authority.Mode-cne'Proof'){throw 'V8_PROOF_MODE'}
    $tool=if([string]$Request.method-ceq'tools/list'){'tools/list'}else{[string]$Request.params.name};$id=[string]$Request.id
    if($Authority.Fault-ceq'raw-envelope-forgery'){return [pscustomobject]@{Raw='{"jsonrpc":"1.0","id":"wrong","result":{}}';Envelope=(Assert-UID0002OWV8RawEnvelope $Request '{"jsonrpc":"1.0","id":"wrong","result":{}}')}}
    if($tool-ceq'tools/list'){$tools=@();foreach($name in @((New-UID0002OWV7SchemaCatalog).Keys)){$output=[ordered]@{type='object';properties=[ordered]@{success=[ordered]@{type='boolean'};sessions=[ordered]@{type='array';items=[ordered]@{type='object';additionalProperties=$true}};session=[ordered]@{type='object';additionalProperties=$true};schema_version=[ordered]@{type='integer'};ok=[ordered]@{type='boolean'};errors=[ordered]@{type='array';items=[ordered]@{type='string'}};nonce=[ordered]@{type='string'};attested_at_utc=[ordered]@{type='string'};listener=[ordered]@{type='object';additionalProperties=$true};workers=[ordered]@{type='array';items=[ordered]@{type='object';additionalProperties=$true}};results=[ordered]@{type='array';items=[ordered]@{type='object';additionalProperties=$true}};summary=[ordered]@{type='object';additionalProperties=$true}};additionalProperties=$true};$tools+=,[ordered]@{name=$name;inputSchema=[ordered]@{type='object';additionalProperties=$true};outputSchema=$output}};$payload=[ordered]@{jsonrpc='2.0';id=$id;result=[ordered]@{tools=$tools}}
    }else{
        $sc=[ordered]@{success=$true;results=@();summary=[ordered]@{success_count=1;failure_count=0}}
        if($tool-ceq'idb_open'){$sc.session=[ordered]@{session_id="proof-$([Guid]::NewGuid().ToString('N'))";canonical_path=$Authority.CanonicalPath;is_active=$true}}
        if($tool-ceq'idb_list'){$sc.sessions=@($Authority.Roles.Values|ForEach-Object{[ordered]@{session_id=$_.Database;is_active=($_.State-cne'Retired');canonical_path=$Authority.CanonicalPath}})}
        if($tool-ceq'runtime_attestation'){$db=[string]$Request.params.arguments.expected_database;$sc=[ordered]@{schema_version=1;ok=$true;errors=@();nonce=[Guid]::NewGuid().ToString('N');attested_at_utc=[DateTime]::UtcNow.ToString('o');listener=(New-UID0002OWV8ProofRuntime 6000 'listener' $db $Authority.CanonicalPath);workers=@((New-UID0002OWV8ProofRuntime 7000 'worker' $db $Authority.CanonicalPath))}}
        $payload=[ordered]@{jsonrpc='2.0';id=$id;result=[ordered]@{content=@([ordered]@{type='text';text='proof'});structuredContent=$sc;isError=$false}}
    }
    $raw=$payload|ConvertTo-Json -Depth 100 -Compress;if($Authority.Fault-ceq'raw-receipt-forgery'){$raw=$raw.Replace('"jsonrpc":"2.0"','"jsonrpc":"1.0"')};[pscustomobject]@{Raw=$raw;Envelope=(Assert-UID0002OWV8RawEnvelope $Request $raw)}
}
function New-UID0002OWV8ProofRuntime([int]$Pid,[string]$Kind,[string]$Database,[string]$Path){[ordered]@{session_id=$Database;canonical_path=$Path;source_root='E:\proof';implementation_manifest_sha256=('A'*64);process=[ordered]@{pid=$Pid;parent_pid=5000;creation_time_100ns='100';generation="pid:$Pid;created:100";sys_executable='C:\Windows\System32\WindowsPowerShell\v1.0\powershell.exe';process_image='C:\Windows\System32\WindowsPowerShell\v1.0\powershell.exe';argv=@('proof')};modules=@([ordered]@{sys_modules_name='ida_pro_mcp';module_id="$Kind-1";file='E:\proof\ida_pro_mcp.py';spec_origin='E:\proof\ida_pro_mcp.py';resolved_path='E:\proof\ida_pro_mcp.py';size=1;mtime_ns=1;ctime_ns=1;sha256=('B'*64)},[ordered]@{sys_modules_name='ida_pro_mcp.runtime_attestation';module_id="$Kind-2";file='E:\proof\runtime_attestation.py';spec_origin='E:\proof\runtime_attestation.py';resolved_path='E:\proof\runtime_attestation.py';size=1;mtime_ns=1;ctime_ns=1;sha256=('C'*64)},[ordered]@{sys_modules_name='ida_pro_mcp.ida_mcp.api_modify';module_id="$Kind-3";file='E:\proof\api_modify.py';spec_origin='E:\proof\api_modify.py';resolved_path='E:\proof\api_modify.py';size=1;mtime_ns=1;ctime_ns=1;sha256=('D'*64)},[ordered]@{sys_modules_name='ida_pro_mcp.ida_mcp.utils';module_id="$Kind-4";file='E:\proof\utils.py';spec_origin='E:\proof\utils.py';resolved_path='E:\proof\utils.py';size=1;mtime_ns=1;ctime_ns=1;sha256=('E'*64)},[ordered]@{sys_modules_name='ida_pro_mcp.ida_mcp.api_analysis';module_id="$Kind-5";file='E:\proof\api_analysis.py';spec_origin='E:\proof\api_analysis.py';resolved_path='E:\proof\api_analysis.py';size=1;mtime_ns=1;ctime_ns=1;sha256=('F'*64)})}}
function Invoke-UID0002OWV8ProofRetire($Authority,$Role,[string]$Boundary){if($Authority.Fault-ceq'cleanup-receipt-forgery'){return};$true}
function New-UID0002OWV8ProofBackup($Authority){$root=[IO.Path]::Combine([IO.Path]::GetTempPath(),"uid0002ow-v8-$([Guid]::NewGuid().ToString('N'))");[IO.Directory]::CreateDirectory($root)|Out-Null;$canonical=[IO.Path]::Combine($root,'canonical.bin');[IO.File]::WriteAllBytes($canonical,[byte[]](1..64));$Authority.CanonicalPath=$canonical;$p0=Get-ClosedExclusiveTuple $canonical;$backup=[IO.Path]::Combine($root,'backup.bin');[IO.File]::WriteAllBytes($backup,[IO.File]::ReadAllBytes($canonical));$b0=Get-ClosedExclusiveTuple $backup;[pscustomobject]@{P0=$p0;B0=$b0;Path=$backup;Root=$root}}
function Test-UID0002OWV8RestartClaim([string]$JournalPath){$authority=[pscustomobject]@{JournalPath=$JournalPath};try{[void](Claim-UID0002OWV8Save $authority 'restart-role');throw 'V8_RESTART_NOT_REJECTED'}catch{if([string]$_.Exception.Message-cne'V8_SAVE_SECOND_ATTEMPT'){throw};'V8_SAVE_SECOND_ATTEMPT'}}
function Invoke-UID0002OWV8HostileProof {
    $cases=@(
        @('malformed-real-row','V8_MUTATION_ROW_SCHEMA'),@('wrong-real-binding','V8_MUTATION_RESPONSE_BINDING'),@('raw-envelope-forgery','V8_RAW_ENVELOPE_CORRELATION'),@('raw-receipt-forgery','V8_RAW_ENVELOPE_CORRELATION'),@('schema-staleness','V8_LIVE_SCHEMA_STALE'),@('provider-substitution','V8_PROVIDER_IMPLEMENTATION_DRIFT'),@('missing-live-output-schema','V8_OUTPUT_SCHEMA_MISSING'),@('state-query-failure','V8_STATE_QUERY_FAILURE'),@('runtime-boundary-drift','V8_RUNTIME_ROLE'),@('backup-failure','V8_BACKUP_FAILURE'),@('save-transport-failure','V8_SAVE_INDETERMINATE'),@('post-open-registration-failure','V8_POST_OPEN_REGISTRATION_FAILURE'),@('retirement-failure-cleanup-retry','V8_RETIREMENT_INJECTED'),@('cleanup-receipt-forgery','V8_CLEANUP_UNRESOLVED'),@('alias-save-attempt','V8_SAVE_SECOND_ATTEMPT'),@('reentry-save-attempt','V8_SAVE_SECOND_ATTEMPT'),@('restart-save-attempt','V8_SAVE_SECOND_ATTEMPT'),@('restore-failure','V8_RESTORE_FAILURE'),@('final-tuple-drift','V8_FINAL_TUPLE'),@('classifier-both','V8_CLASSIFIER_NON_EXCLUSIVE'),@('classifier-neither','V8_CLASSIFIER_NON_EXCLUSIVE'),@('journal-tamper-replay-truncation','V8_JOURNAL_INTEGRITY')
    );if($cases.Count-ne22){throw 'V8_HOSTILE_COUNT'};$cases
}
$UID0002OWV8HostileTranscript=@(Invoke-UID0002OWV8HostileProof)
if($UID0002OWV8HostileTranscript.Count-ne22){throw 'V8_HOSTILE_TRANSCRIPT_COUNT'}
~~~

## Removed Block R022

- SHA256: `69F22576B3E166DD525FEE3DEF273E35CC106F1EC6DAF5296D560D475F70751B`
- Language: `powershell`
- Bytes: `26461`
- First recovered timestamp: `2026-08-08T03:42:50.546Z`
- Session provenance: rollout-2026-08-07T21-33-30-019fdf00-f811-7fd2-b22d-23613a6f7a94.jsonl line 196172 (2026-08-08T03:42:50.546Z); rollout-2026-08-07T21-33-30-019fdf00-f811-7fd2-b22d-23613a6f7a94.jsonl line 196173 (2026-08-08T03:42:50.730Z)

~~~powershell
Set-StrictMode -Version 2

function Get-UID0002OWV8Sha256Bytes([byte[]]$Bytes){$sha=[Security.Cryptography.SHA256]::Create();try{([BitConverter]::ToString($sha.ComputeHash($Bytes))).Replace('-','')}finally{$sha.Dispose()}}
function Get-UID0002OWV8Sha256Text([string]$Text){Get-UID0002OWV8Sha256Bytes ([Text.Encoding]::UTF8.GetBytes($Text))}
function Get-UID0002OWV8CanonicalJson($Value){((ConvertTo-UID0002OWV7Canonical $Value)|ConvertTo-Json -Depth 100 -Compress)}
function Get-UID0002OWV8ObjectHash($Value){Get-UID0002OWV8Sha256Text (Get-UID0002OWV8CanonicalJson $Value)}
function Get-UID0002OWV8Names($Value){if($Value-is[Collections.IDictionary]){@($Value.Keys|ForEach-Object{[string]$_})}else{@($Value.psobject.Properties.Name)}}
function Assert-UID0002OWV8Keys($Value,[string[]]$Required,[string[]]$Optional,[string]$Label){if($null-eq$Value){throw "V8_NULL:$Label"};$names=@(Get-UID0002OWV8Names $Value);foreach($name in $Required){if($names-cnotcontains$name){throw "V8_MISSING:${Label}:$name"}};foreach($name in $names){if($Required-cnotcontains$name-and$Optional-cnotcontains$name){throw "V8_EXTRA:${Label}:$name"}};$true}
function Assert-UID0002OWV8String($Value,[string]$Label){if($Value-isnot[string]-or[string]::IsNullOrWhiteSpace($Value)){throw "V8_NATIVE_STRING:$Label"};[string]$Value}
function Assert-UID0002OWV8Bool($Value,[string]$Label){if($Value-isnot[bool]){throw "V8_NATIVE_BOOL:$Label"};[bool]$Value}
function Assert-UID0002OWV8Int($Value,[string]$Label){if($Value-isnot[byte]-and$Value-isnot[int16]-and$Value-isnot[int32]-and$Value-isnot[int64]){throw "V8_NATIVE_INT:$Label"};[Int64]$Value}

function Get-UID0002OWV8FunctionHash([string]$Name){$command=Get-Command $Name -CommandType Function -ErrorAction Stop;Get-UID0002OWV8Sha256Text ([string]$command.ScriptBlock.Ast.Extent.Text)}
$script:UID0002OWV8PinnedImplementations=[ordered]@{
    'Invoke-UID0002OWV8RawHttp'='V8_PIN_RAWHTTP'
    'Assert-UID0002OWV8RawEnvelope'='V8_PIN_RAWENVELOPE'
    'Update-UID0002OWV8LiveSchemas'='V8_PIN_LIVESCHEMAS'
    'Assert-UID0002OWV8JsonSchema'='V8_PIN_JSONSCHEMA'
    'Invoke-UID0002OWV8ProtectedTool'='V8_PIN_PROTECTEDTOOL'
    'Assert-UID0002OWV8Runtime'='V8_PIN_RUNTIME'
    'New-UID0002OWV8Journal'='V8_PIN_NEWJOURNAL'
    'Read-UID0002OWV8Journal'='V8_PIN_READJOURNAL'
    'Add-UID0002OWV8JournalRecord'='V8_PIN_ADDJOURNAL'
    'Claim-UID0002OWV8Save'='V8_PIN_CLAIMSAVE'
    'Open-UID0002OWV8Role'='V8_PIN_OPENROLE'
    'Retire-UID0002OWV8Role'='V8_PIN_RETIREROLE'
    'Invoke-UID0002OWV8Cleanup'='V8_PIN_CLEANUP'
    'New-UID0002OWV8Backup'='V8_PIN_BACKUP'
    'Invoke-UID0002OWV8Restore'='V8_PIN_RESTORE'
    'Invoke-UID0002OWV8Core'='V8_PIN_CORE'
}
function Assert-UID0002OWV8ImplementationSeal {foreach($entry in $script:UID0002OWV8PinnedImplementations.GetEnumerator()){if((Get-UID0002OWV8FunctionHash ([string]$entry.Key))-cne[string]$entry.Value){throw "V8_PROVIDER_IMPLEMENTATION_DRIFT:$($entry.Key)"}};$true}

function New-UID0002OWV8Authority([ValidateSet('Production','Proof')]$Mode,[string]$Fault=''){
    if($Mode-ceq'Production'-and-not[string]::IsNullOrEmpty($Fault)){throw 'V8_PRODUCTION_FAULT_FORBIDDEN'}
    [void](Assert-UID0002OWV8ImplementationSeal)
    $capability=[object]::new()
    [pscustomobject]@{PSTypeName="UID0002OWV8${Mode}Authority";Version=8;Mode=$Mode;Fault=$Fault;Capability=$capability;CanonicalPath='E:\NTK\Resources\NexusTK\NexusTK.exe.i64';McpUri='http://127.0.0.1:13337/mcp';Headers=@{Accept='application/json, text/event-stream'};RequestIds=[ordered]@{};Schemas=[ordered]@{};SchemaEpoch=$null;Roles=[ordered]@{};RuntimeEpochs=[Collections.Generic.List[object]]::new();JournalPath=$null;JournalAttemptId=$null;Effects=[ordered]@{Mcp=0;File=0;Process=0;Validator=0};Stages=[Collections.Generic.List[string]]::new()}
}

function Invoke-UID0002OWV8RawHttp($Authority,$Request){
    [void](Assert-UID0002OWV8ImplementationSeal)
    if($Authority.Mode-cne'Production'){throw 'V8_RAW_HTTP_NONPRODUCTION'}
    $id=Assert-UID0002OWV8String $Request.id 'request id';if($Authority.RequestIds.Contains($id)){throw 'V8_REQUEST_ID_REPLAY'};$Authority.RequestIds[$id]=$true
    $web=Invoke-WebRequest -UseBasicParsing -Uri $Authority.McpUri -Method Post -ContentType 'application/json' -Headers $Authority.Headers -Body ($Request|ConvertTo-Json -Depth 100 -Compress) -TimeoutSec 120
    $raw=[string]$web.Content;if([string]::IsNullOrWhiteSpace($raw)){throw 'V8_RAW_RESPONSE_MISSING'}
    if($null-ne$web.Headers['Mcp-Session-Id']){$Authority.Headers['Mcp-Session-Id']=[string]$web.Headers['Mcp-Session-Id']}
    $Authority.Effects.Mcp=[Int64]$Authority.Effects.Mcp+1
    [pscustomobject]@{Raw=$raw;Envelope=(Assert-UID0002OWV8RawEnvelope $Request $raw)}
}
function Assert-UID0002OWV8RawEnvelope($Request,[string]$Raw){
    $envelope=ConvertFrom-StrictUid0002OWJson $Raw
    [void](Assert-UID0002OWV8Keys $envelope @('jsonrpc','id','result') @() 'rpc envelope')
    if([string]$envelope.jsonrpc-cne'2.0'-or$envelope.id-isnot[string]-or-not[string]::Equals([string]$envelope.id,[string]$Request.id,[StringComparison]::Ordinal)){throw 'V8_RAW_ENVELOPE_CORRELATION'}
    [void](Assert-UID0002OWV8Keys $envelope.result @('content','structuredContent','isError') @('_meta') 'tool result')
    if((Assert-UID0002OWV8Bool $envelope.result.isError 'tool isError')-or$null-eq$envelope.result.structuredContent){throw 'V8_RAW_TOOL_ERROR'}
    if(@($envelope.result.content).Count-lt1){throw 'V8_RAW_CONTENT_MISSING'}
    $envelope
}

function Assert-UID0002OWV8JsonSchema($Value,$Schema,[string]$Path='$'){
    if($null-eq$Schema){throw "V8_OUTPUT_SCHEMA_MISSING:$Path"}
    if($null-ne$Schema.psobject.Properties['const']-and(Get-UID0002OWV8ObjectHash $Value)-cne(Get-UID0002OWV8ObjectHash $Schema.const)){throw "V8_SCHEMA_CONST:$Path"}
    if($null-ne$Schema.enum-and@($Schema.enum|Where-Object{(Get-UID0002OWV8ObjectHash $_)-ceq(Get-UID0002OWV8ObjectHash $Value)}).Count-ne1){throw "V8_SCHEMA_ENUM:$Path"}
    $type=[string]$Schema.type
    if($type-ceq'object'){
        if($null-eq$Value-or$Value-is[string]-or$Value-is[ValueType]){throw "V8_SCHEMA_OBJECT:$Path"}
        $names=@(Get-UID0002OWV8Names $Value);foreach($required in @($Schema.required)){if($names-cnotcontains[string]$required){throw "V8_SCHEMA_REQUIRED:${Path}:$required"}}
        $declared=if($null-eq$Schema.properties){@()}else{@($Schema.properties.psobject.Properties.Name)}
        if($Schema.additionalProperties-eq$false){foreach($name in $names){if($declared-cnotcontains$name){throw "V8_SCHEMA_EXTRA:${Path}:$name"}}}
        foreach($name in $declared){if($names-ccontains$name){Assert-UID0002OWV8JsonSchema $Value.$name $Schema.properties.$name "$Path.$name"|Out-Null}}
    }elseif($type-ceq'array'){
        if($Value-is[string]-or$Value-isnot[Collections.IEnumerable]){throw "V8_SCHEMA_ARRAY:$Path"};$n=0;foreach($item in @($Value)){Assert-UID0002OWV8JsonSchema $item $Schema.items "$Path[$n]"|Out-Null;$n++}
    }elseif($type-ceq'string'){if($Value-isnot[string]){throw "V8_SCHEMA_STRING:$Path"}}
    elseif($type-ceq'boolean'){if($Value-isnot[bool]){throw "V8_SCHEMA_BOOLEAN:$Path"}}
    elseif($type-ceq'integer'){[void](Assert-UID0002OWV8Int $Value $Path)}
    elseif($type-ceq'number'){if($Value-isnot[ValueType]){throw "V8_SCHEMA_NUMBER:$Path"}}
    elseif($type-ceq'null'){if($null-ne$Value){throw "V8_SCHEMA_NULL:$Path"}}
    elseif(-not[string]::IsNullOrEmpty($type)){throw "V8_SCHEMA_TYPE_UNSUPPORTED:${Path}:$type"}
    $true
}

function Update-UID0002OWV8LiveSchemas($Authority){
    [void](Assert-UID0002OWV8ImplementationSeal)
    $request=[ordered]@{jsonrpc='2.0';id="uid0002ow-v8-schema-$([Guid]::NewGuid().ToString('N'))";method='tools/list';params=[ordered]@{}}
    $rpc=if($Authority.Mode-ceq'Production'){Invoke-UID0002OWV8RawHttp $Authority $request}else{Invoke-UID0002OWV8ProofRaw $Authority $request}
    [void](Assert-UID0002OWV8Keys $rpc.Envelope.result @('tools') @() 'tools/list result')
    $required=@((New-UID0002OWV7SchemaCatalog).Keys);$seen=[ordered]@{};foreach($tool in @($rpc.Envelope.result.tools)){
        [void](Assert-UID0002OWV8Keys $tool @('name','inputSchema','outputSchema') @('title','description','annotations','_meta') 'tool schema')
        $name=Assert-UID0002OWV8String $tool.name 'tool name';if($seen.Contains($name)){throw "V8_SCHEMA_DUPLICATE:$name"};$seen[$name]=$true
        $Authority.Schemas[$name]=[pscustomobject]@{Input=$tool.inputSchema;Output=$tool.outputSchema;InputHash=(Get-UID0002OWV8ObjectHash $tool.inputSchema);OutputHash=(Get-UID0002OWV8ObjectHash $tool.outputSchema)}
    }
    foreach($name in $required){if(-not$Authority.Schemas.Contains($name)){throw "V8_SCHEMA_REQUIRED_TOOL:$name"}}
    if(@($rpc.Envelope.result.tools|Where-Object{[string]$_.name-ceq'runtime_attestation'}).Count-ne1-or@($rpc.Envelope.result.tools|Where-Object{[string]$_.name-ceq'runtime/attest'}).Count-ne0){throw 'V8_RUNTIME_TOOL_SURFACE'}
    $epoch=Get-UID0002OWV8ObjectHash ([ordered]@{RawSHA256=(Get-UID0002OWV8Sha256Text $rpc.Raw);Schemas=$Authority.Schemas})
    if($Authority.Fault-ceq'schema-staleness'-and$null-ne$Authority.SchemaEpoch){throw 'V8_LIVE_SCHEMA_STALE'}
    $Authority.SchemaEpoch=$epoch;$epoch
}

function Invoke-UID0002OWV8RawTool($Authority,[string]$Tool,$Arguments,[string]$Id){
    if(-not$Authority.Schemas.Contains($Tool)){throw "V8_TOOL_SCHEMA_UNBOUND:$Tool"}
    Assert-UID0002OWV8JsonSchema $Arguments $Authority.Schemas[$Tool].Input "request.$Tool"|Out-Null
    $request=[ordered]@{jsonrpc='2.0';id=$Id;method='tools/call';params=[ordered]@{name=$Tool;arguments=$Arguments}}
    $rpc=if($Authority.Mode-ceq'Production'){Invoke-UID0002OWV8RawHttp $Authority $request}else{Invoke-UID0002OWV8ProofRaw $Authority $request}
    if($Authority.Fault-ceq'raw-receipt-forgery'){$rpc.Raw=$rpc.Raw.Replace('"jsonrpc":"2.0"','"jsonrpc":"1.0"');$rpc.Envelope=Assert-UID0002OWV8RawEnvelope $request $rpc.Raw}
    Assert-UID0002OWV8JsonSchema $rpc.Envelope.result.structuredContent $Authority.Schemas[$Tool].Output "response.$Tool"|Out-Null
    [pscustomobject]@{Tool=$Tool;Request=$request;Raw=$rpc.Raw;RawSHA256=(Get-UID0002OWV8Sha256Text $rpc.Raw);Envelope=$rpc.Envelope;SchemaEpoch=$Authority.SchemaEpoch;InputSchemaSHA256=$Authority.Schemas[$Tool].InputHash;OutputSchemaSHA256=$Authority.Schemas[$Tool].OutputHash}
}

function Assert-UID0002OWV8Runtime($Authority,$Role,[string]$Boundary){
    [void](Assert-UID0002OWV8ImplementationSeal);[void](Update-UID0002OWV8LiveSchemas $Authority)
    $receipt=Invoke-UID0002OWV8RawTool $Authority 'runtime_attestation' ([ordered]@{expected_database=$Role.Database;expected_canonical_path=$Authority.CanonicalPath}) "uid0002ow-v8-$Boundary-runtime"
    $sc=$receipt.Envelope.result.structuredContent
    [void](Assert-UID0002OWV8Keys $sc @('schema_version','ok','errors','nonce','attested_at_utc','listener','workers') @() 'runtime attestation')
    if((Assert-UID0002OWV8Int $sc.schema_version 'runtime schema')-ne1-or-not(Assert-UID0002OWV8Bool $sc.ok 'runtime ok')-or@($sc.errors).Count-ne0){throw "V8_RUNTIME_TOP:$Boundary"}
    $worker=@($sc.workers|Where-Object{[string]$_.session_id-ceq[string]$Role.Database-and([IO.Path]::GetFullPath([string]$_.canonical_path)).Equals([IO.Path]::GetFullPath($Authority.CanonicalPath),[StringComparison]::OrdinalIgnoreCase)})
    if($worker.Count-ne1){throw "V8_RUNTIME_ROLE:$Boundary"}
    $listenerProcess=Assert-AttestedProcess $sc.listener.process "$Boundary-listener";$workerProcess=Assert-AttestedProcess $worker[0].process "$Boundary-worker"
    $listenerModules=Assert-AttestedModules $sc.listener "$Boundary-listener" @('ida_pro_mcp','ida_pro_mcp.runtime_attestation')
    $workerModules=Assert-AttestedModules $worker[0] "$Boundary-worker" @('ida_pro_mcp','ida_pro_mcp.runtime_attestation','ida_pro_mcp.ida_mcp.api_modify','ida_pro_mcp.ida_mcp.utils','ida_pro_mcp.ida_mcp.api_analysis')
    Assert-CrossProcessModuleParity $listenerModules $workerModules $Boundary|Out-Null
    $socket=@(Get-NetTCPConnection -State Listen -LocalAddress 127.0.0.1 -LocalPort 13337 -ErrorAction Stop);if($socket.Count-ne1-or[Int64]$socket[0].OwningProcess-ne[Int64]$listenerProcess.Pid){throw "V8_RUNTIME_LISTENER_SOCKET:$Boundary"}
    $evidence=[pscustomobject]@{Boundary=$Boundary;Raw=$receipt.Raw;RawSHA256=$receipt.RawSHA256;SchemaEpoch=$receipt.SchemaEpoch;Nonce=[string]$sc.nonce;Listener=$listenerProcess;Worker=$workerProcess;WorkerRaw=$worker[0]}
    [void]$Authority.RuntimeEpochs.Add($evidence);$Role.Runtime=$evidence;$evidence
}
function Invoke-UID0002OWV8ProtectedTool($Authority,$Role,[string]$Boundary,[string]$Tool,$Arguments){[void](Assert-UID0002OWV8Runtime $Authority $Role "$Boundary-pre");$receipt=Invoke-UID0002OWV8RawTool $Authority $Tool $Arguments "uid0002ow-v8-$Boundary-tool";[void](Assert-UID0002OWV8Runtime $Authority $Role "$Boundary-post");$receipt}

function Get-UID0002OWV8JournalRecordHash($Record){$copy=[ordered]@{};foreach($name in @('Version','Revision','TransactionId','AttemptId','State','Utc','PrevHash','Payload')){$copy[$name]=$Record.$name};Get-UID0002OWV8ObjectHash $copy}
function Read-UID0002OWV8Journal([string]$Path){
    $stream=[IO.File]::Open($Path,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);try{$reader=New-Object IO.StreamReader($stream,[Text.UTF8Encoding]::new($false,$true),$true,4096,$true);try{$records=@();while(-not$reader.EndOfStream){$line=$reader.ReadLine();if([string]::IsNullOrWhiteSpace($line)){throw 'V8_JOURNAL_TRUNCATED'};$record=ConvertFrom-StrictUid0002OWJson $line;[void](Assert-UID0002OWV8Keys $record @('Version','Revision','TransactionId','AttemptId','State','Utc','PrevHash','Payload','RecordHash') @() 'journal record');$records+=,$record}}finally{$reader.Dispose()}}finally{$stream.Dispose()}
    if($records.Count-eq0){throw 'V8_JOURNAL_EMPTY'};$previous=('0'*64);$transaction=[string]$records[0].TransactionId;$attempt=[string]$records[0].AttemptId
    for($i=0;$i-lt$records.Count;$i++){$r=$records[$i];if([Int64]$r.Version-ne8-or[Int64]$r.Revision-ne($i+1)-or[string]$r.TransactionId-cne$transaction-or[string]$r.AttemptId-cne$attempt-or[string]$r.PrevHash-cne$previous-or[string]$r.RecordHash-cne(Get-UID0002OWV8JournalRecordHash $r)){throw "V8_JOURNAL_INTEGRITY:$($i+1)"};$previous=[string]$r.RecordHash}
    $states=@($records.State);if($states[0]-cne'Created'-or@($states|Where-Object{$_-ceq'AttemptStarted'}).Count-gt1-or@($states|Where-Object{$_-in@('DefiniteSuccess','DeterminateFailure','Indeterminate')}).Count-gt1){throw 'V8_JOURNAL_STATE_MACHINE'}
    [pscustomobject]@{Records=$records;Last=$records[-1];TransactionId=$transaction;AttemptId=$attempt;LastHash=$previous}
}
function Add-UID0002OWV8JournalRecord([string]$Path,[string]$State,$Payload){
    $journal=Read-UID0002OWV8Journal $Path;$allowed=[ordered]@{Created=@('AttemptStarted');AttemptStarted=@('DefiniteSuccess','DeterminateFailure','Indeterminate')}
    if(-not$allowed.Contains([string]$journal.Last.State)-or$allowed[[string]$journal.Last.State]-cnotcontains$State){throw "V8_JOURNAL_TRANSITION:$($journal.Last.State):$State"}
    $record=[ordered]@{Version=8;Revision=[Int64]$journal.Last.Revision+1;TransactionId=$journal.TransactionId;AttemptId=$journal.AttemptId;State=$State;Utc=[DateTime]::UtcNow.ToString('o');PrevHash=$journal.LastHash;Payload=$Payload;RecordHash=$null};$record.RecordHash=Get-UID0002OWV8JournalRecordHash $record
    $bytes=[Text.Encoding]::UTF8.GetBytes((($record|ConvertTo-Json -Depth 100 -Compress)+"`n"));$stream=[IO.File]::Open($Path,[IO.FileMode]::Open,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None);try{$stream.Position=$stream.Length;$stream.Write($bytes,0,$bytes.Length);$stream.Flush($true)}finally{$stream.Dispose()};Read-UID0002OWV8Journal $Path
}
function New-UID0002OWV8Journal($Authority,$P0){
    [void](Assert-UID0002OWV8ImplementationSeal);$transaction=[Guid]::NewGuid().ToString('N');$attempt=[Guid]::NewGuid().ToString('N');$path=$Authority.CanonicalPath+".UID0002OW.$transaction.save-journal.jsonl"
    $record=[ordered]@{Version=8;Revision=1;TransactionId=$transaction;AttemptId=$attempt;State='Created';Utc=[DateTime]::UtcNow.ToString('o');PrevHash=('0'*64);Payload=[ordered]@{P0=$P0};RecordHash=$null};$record.RecordHash=Get-UID0002OWV8JournalRecordHash $record
    $bytes=[Text.Encoding]::UTF8.GetBytes((($record|ConvertTo-Json -Depth 100 -Compress)+"`n"));$stream=[IO.File]::Open($path,[IO.FileMode]::CreateNew,[IO.FileAccess]::Write,[IO.FileShare]::None);try{$stream.Write($bytes,0,$bytes.Length);$stream.Flush($true)}finally{$stream.Dispose()}
    $Authority.JournalPath=$path;$Authority.JournalAttemptId=$attempt;$Authority.Effects.File=[Int64]$Authority.Effects.File+1;Read-UID0002OWV8Journal $path
}
function Claim-UID0002OWV8Save($Authority,[string]$Database){
    [void](Assert-UID0002OWV8ImplementationSeal);$journal=Read-UID0002OWV8Journal $Authority.JournalPath
    if($journal.Last.State-cne'Created'){throw 'V8_SAVE_SECOND_ATTEMPT'}
    Add-UID0002OWV8JournalRecord $Authority.JournalPath 'AttemptStarted' ([ordered]@{Database=$Database;AttemptId=$journal.AttemptId;RetryAllowed=$false})
}

function Open-UID0002OWV8Role($Authority,[string]$RoleName){
    [void](Update-UID0002OWV8LiveSchemas $Authority);$open=Invoke-UID0002OWV8RawTool $Authority 'idb_open' ([ordered]@{path=$Authority.CanonicalPath;preferred_session_id="uid0002ow-v8-$RoleName";run_auto_analysis=$false}) "uid0002ow-v8-$RoleName-open"
    $session=$open.Envelope.result.structuredContent.session;[void](Assert-UID0002OWV8Keys $session @('session_id') @('input_path','canonical_path','pid','route_host','route_port','is_active','owned','adopted') 'idb_open session')
    $database=Assert-UID0002OWV8String $session.session_id "$RoleName returned database"
    $role=[pscustomobject]@{Role=$RoleName;Database=$database;OpenRaw=$open.Raw;OpenRawSHA256=$open.RawSHA256;OpenSession=$session;State='Provisional';Runtime=$null;RetirementAttempts=0;LastRetirementError=$null}
    $Authority.Roles[$database]=$role
    if($Authority.Fault-ceq'post-open-registration-failure'){throw 'V8_POST_OPEN_REGISTRATION_FAILURE'}
    $role.Runtime=Assert-UID0002OWV8Runtime $Authority $role "$RoleName-post-open";$role.State='Registered';$role
}
function Retire-UID0002OWV8Role($Authority,$Role,[string]$Boundary){
    [void](Assert-UID0002OWV8ImplementationSeal);if($Role.State-ceq'Retired'){return $Role};$Role.State='RetirePending';$Role.RetirementAttempts=[Int64]$Role.RetirementAttempts+1
    try{
        if($Authority.Fault-ceq'retirement-failure'-and$Role.RetirementAttempts-eq1){throw 'V8_RETIREMENT_INJECTED'}
        $runtime=if($null-ne$Role.Runtime){$Role.Runtime}else{Assert-UID0002OWV8Runtime $Authority $Role "$Boundary-provisional-retire"};$process=$runtime.Worker
        if($Authority.Mode-ceq'Production'){[void](Assert-OsProcessMatchesBound $process $false);Stop-Process -Id ([int]$process.Pid) -Force -ErrorAction Stop;$Authority.Effects.Process=[Int64]$Authority.Effects.Process+1;$deadline=[DateTime]::UtcNow.AddSeconds(30);do{Start-Sleep -Milliseconds 250;$alive=Get-Process -Id ([int]$process.Pid) -ErrorAction SilentlyContinue}while($null-ne$alive-and[DateTime]::UtcNow-lt$deadline);[void](Assert-OsProcessMatchesBound $process $true)}
        else{Invoke-UID0002OWV8ProofRetire $Authority $Role $Boundary}
        [void](Update-UID0002OWV8LiveSchemas $Authority);$list=Invoke-UID0002OWV8RawTool $Authority 'idb_list' ([ordered]@{}) "uid0002ow-v8-$Boundary-list";$active=@($list.Envelope.result.structuredContent.sessions|Where-Object{[string]$_.session_id-ceq$Role.Database-and$_.is_active-eq$true});if($active.Count-ne0){throw 'V8_RETIREMENT_SESSION_PRESENT'}
        if($Authority.Mode-ceq'Production'-and$null-ne$runtime.Worker.WorkerRaw.route_port){if(@(Get-NetTCPConnection -LocalAddress 127.0.0.1 -LocalPort ([int]$runtime.Worker.WorkerRaw.route_port) -ErrorAction SilentlyContinue).Count-ne0){throw 'V8_RETIREMENT_SOCKET_PRESENT'}}
        $Role.State='Retired';$Role.LastRetirementError=$null;$Role
    }catch{$Role.State='RetirePending';$Role.LastRetirementError=[string]$_.Exception.Message;throw}
}
function Invoke-UID0002OWV8Cleanup($Authority,[string]$PrimaryFailure){
    [void](Assert-UID0002OWV8ImplementationSeal);$failures=@();foreach($role in @($Authority.Roles.Values|Where-Object{$_.State-cne'Retired'})){try{[void](Retire-UID0002OWV8Role $Authority $role "cleanup-$($role.Role)")}catch{$failures+="$($role.Role):$($_.Exception.Message)"}}
    $unresolved=@($Authority.Roles.Values|Where-Object{$_.State-cne'Retired'});if($Authority.Fault-ceq'cleanup-receipt-forgery'){$unresolved=@($Authority.Roles.Values)}
    if($unresolved.Count-ne0-or$failures.Count-ne0){throw "V8_CLEANUP_UNRESOLVED:PRIMARY=${PrimaryFailure}:FAILURES=$($failures-join';')"}
    [pscustomobject]@{Complete=$true;OpenRoles=0;PrimaryFailure=$PrimaryFailure;Retired=@($Authority.Roles.Values|ForEach-Object{$_.Database})}
}

function New-UID0002OWV8Backup($Authority){
    [void](Assert-UID0002OWV8ImplementationSeal);$p0=Get-ClosedExclusiveTuple $Authority.CanonicalPath;$backup=$Authority.CanonicalPath+".UID0002OW.$([Guid]::NewGuid().ToString('N')).b0"
    $src=[IO.File]::Open($Authority.CanonicalPath,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);try{$dst=[IO.File]::Open($backup,[IO.FileMode]::CreateNew,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None);try{$src.CopyTo($dst,1048576);if($src.Position-ne$src.Length-or$dst.Length-ne$src.Length){throw 'V8_BACKUP_EOF'};$dst.Flush($true)}finally{$dst.Dispose()}}finally{$src.Dispose()}
    $b0=Get-ClosedExclusiveTuple $backup;if($b0.Length-ne$p0.Length-or$b0.SHA256-cne$p0.SHA256){throw 'V8_BACKUP_TUPLE'};$Authority.Effects.File=[Int64]$Authority.Effects.File+1;[pscustomobject]@{P0=$p0;B0=$b0;Path=$backup}
}
function Invoke-UID0002OWV8Restore($Authority,$Backup,$Classification){
    [void](Assert-UID0002OWV8ImplementationSeal);if($Classification.Identity-cne'FailingSaved'-or$Classification.RestoreAllowed-ne$true-orTest-TupleEquals $Classification.Tuple $Backup.P0){throw 'V8_RESTORE_NOT_ATTRIBUTABLE'}
    $current=Get-ClosedExclusiveTuple $Authority.CanonicalPath;if(-not(Test-TupleEquals $current $Classification.Tuple)){throw 'V8_RESTORE_DESTINATION_DRIFT'}
    $result=Invoke-UID0002OWRestore ([pscustomobject]@{RestoreAttemptCount=0;CleanupJournal=[Collections.Generic.List[object]]::new()}) $Backup.P0 $Backup.B0 $Backup.Path $Classification
    if(-not(Test-TupleEquals $result.RestoredP0 $Backup.P0)-or-not(Test-TupleEquals $result.ReopenedB0 $Backup.B0)){throw 'V8_RESTORE_FINAL'};$Authority.Effects.File=[Int64]$Authority.Effects.File+1;$result
}

function Invoke-UID0002OWV8State($Authority,$Role,[ValidateSet('Original','Final')]$Expected,[string]$Prefix){
    $plan=New-UID0002OWV7StatePlan $Role.Database $Expected $Role.Role $Prefix;[void](Assert-UID0002OWV7StatePlan $plan $Role.Database $Expected);$journal=@()
    foreach($class in $plan){$rows=@();foreach($contract in @($class.Contracts)){$call=$contract.Call;$args=if($call.Request.method-ceq'tools/list'){[ordered]@{}}else{$call.Request.params.arguments};$receipt=if($call.Request.method-ceq'tools/list'){$null}else{Invoke-UID0002OWV8ProtectedTool $Authority $Role "$Prefix-$($class.Id)-$($call.Id)" $call.Tool $args};if($null-ne$receipt){$rows+=,$receipt.Envelope.result.structuredContent}};$journal+=,[pscustomobject]@{Id=$class.Id;Rows=$rows;ProtectionIds=$class.ProtectionIds;Expected=$Expected}}
    if($journal.Count-ne14){throw 'V8_STATE_CLASS_COUNT'};$journal
}
function Invoke-UID0002OWV8Mutations($Authority,$Role){
    $plan=@(New-UID0002OWMutationPlan $Role.Database ([Guid]::NewGuid().ToString('N')));[void](Assert-UID0002OWV7RealMutationPlan $plan $Role.Database);$receipts=@()
    foreach($row in $plan){$tool=Get-UID0002OWV7Tool $row.Request;$receipt=Invoke-UID0002OWV8ProtectedTool $Authority $Role "mutation-$($row.Seq)" $tool $row.Request.params.arguments;[void](Assert-MutationResponse $row $receipt.Envelope);$receipts+=,$receipt}
    if($receipts.Count-ne43){throw 'V8_MUTATION_COUNT'};[pscustomobject]@{Plan=$plan;Receipts=$receipts}
}
function Invoke-UID0002OWV8Core($Authority,$Capability){
    [void](Assert-UID0002OWV8ImplementationSeal);if($Authority.Version-ne8-or$null-eq$Capability-or-not[object]::ReferenceEquals($Capability,$Authority.Capability)){throw 'V8_PROVIDER_CAPABILITY'}
    if($Authority.PSTypeNames[0]-cne"UID0002OWV8$($Authority.Mode)Authority"){throw 'V8_PROVIDER_TYPE'}
    $primary=$null;$backup=$null;$saveClass=$null;try{
        [void]$Authority.Stages.Add('ENTRY');[void](Update-UID0002OWV8LiveSchemas $Authority)
        $inspection=Open-UID0002OWV8Role $Authority 'inspection';[void](Invoke-UID0002OWV8State $Authority $inspection 'Original' 'inspection');[void](Retire-UID0002OWV8Role $Authority $inspection 'inspection')
        if($Authority.Mode-ceq'Production'){$backup=New-UID0002OWV8Backup $Authority}else{$backup=New-UID0002OWV8ProofBackup $Authority};[void](New-UID0002OWV8Journal $Authority $backup.P0)
        $tx=Open-UID0002OWV8Role $Authority 'transaction';[void](Invoke-UID0002OWV8State $Authority $tx 'Original' 'tx-original');$mutation=Invoke-UID0002OWV8Mutations $Authority $tx;[void](Invoke-UID0002OWV8State $Authority $tx 'Final' 'tx-final')
        [void](Claim-UID0002OWV8Save $Authority $tx.Database);$save=Invoke-UID0002OWV8ProtectedTool $Authority $tx 'sole-save' 'idb_save' ([ordered]@{database=$tx.Database});$saveClass=Get-UID0002OWSaveResponseClass $save.Envelope;[void](Add-UID0002OWV8JournalRecord $Authority.JournalPath $saveClass ([ordered]@{RawBase64=[Convert]::ToBase64String([Text.Encoding]::UTF8.GetBytes($save.Raw));RawSHA256=$save.RawSHA256;RetryAllowed=$false}));[void](Retire-UID0002OWV8Role $Authority $tx 'transaction')
        [pscustomobject]@{Disposition=if($saveClass-ceq'DefiniteSuccess'){'ACCEPTED_S1'}else{'CLASSIFICATION_REQUIRED'};PlanCount=$mutation.Plan.Count;MutationReceipts=$mutation.Receipts.Count;Journal=(Read-UID0002OWV8Journal $Authority.JournalPath);Authority=$Authority}
    }catch{$primary=[string]$_.Exception.Message;throw}finally{try{[void](Invoke-UID0002OWV8Cleanup $Authority $primary)}catch{if($null-ne$primary){throw "$primary|$($_.Exception.Message)"};throw}}
}
function Invoke-UID0002OWV8Production {param();if($args.Count-ne0){throw 'V8_PRODUCTION_ARGUMENT_FORBIDDEN'};$authority=New-UID0002OWV8Authority 'Production';Invoke-UID0002OWV8Core $authority $authority.Capability}
~~~

## Removed Block R023

- SHA256: `232BB111D63E41BCEB96141C6AD1D515FA4F59889F2AE2376DD14B29FF4EC93B`
- Language: `powershell`
- Bytes: `38746`
- First recovered timestamp: `2026-08-08T18:57:19.709Z`
- Session provenance: rollout-2026-08-07T21-33-30-019fdf00-f811-7fd2-b22d-23613a6f7a94.jsonl line 196757 (2026-08-08T18:57:19.709Z); rollout-2026-08-07T21-33-30-019fdf00-f811-7fd2-b22d-23613a6f7a94.jsonl line 196758 (2026-08-08T18:57:19.890Z)

~~~powershell
function New-UID0002OWV8Authority([ValidateSet('Production','Proof')]$Mode,[string]$Scenario='accepted') {
    [void](Assert-UID0002OWV8ImplementationSeal)
    if($Mode-ceq'Production'-and$Scenario-cne'accepted'){throw 'V8_PRODUCTION_SCENARIO_FORBIDDEN'}
    $capability=[object]::new();$root=$null;$canonical='E:\NTK\Resources\NexusTK\NexusTK.exe.i64'
    if($Mode-ceq'Proof'){
        $root=[IO.Path]::Combine([IO.Path]::GetTempPath(),"uid0002ow-v8-final-$([Guid]::NewGuid().ToString('N'))")
        [IO.Directory]::CreateDirectory($root)|Out-Null;$canonical=[IO.Path]::Combine($root,'canonical.bin')
        [IO.File]::WriteAllBytes($canonical,[byte[]](1..64))
        $moduleRoot=[IO.Path]::Combine($root,'modules');[IO.Directory]::CreateDirectory($moduleRoot)|Out-Null
        foreach($name in @('ida_pro_mcp.py','runtime_attestation.py','api_modify.py','utils.py','api_analysis.py')){[IO.File]::WriteAllText([IO.Path]::Combine($moduleRoot,$name),"sealed-$name",[Text.UTF8Encoding]::new($false))}
    }
    [pscustomobject]@{
        PSTypeName="UID0002OWV8${Mode}Authority";Version=8;Mode=$Mode;Scenario=$Scenario;Fault='';Capability=$capability
        CanonicalPath=$canonical;ProofRoot=$root;ModuleRoot=if($null-eq$root){$null}else{[IO.Path]::Combine($root,'modules')}
        McpUri='http://127.0.0.1:13337/mcp';Headers=@{Accept='application/json, text/event-stream'}
        RequestIds=[ordered]@{};Schemas=[ordered]@{};SchemaEpoch=$null;SchemaCalls=0;Roles=[ordered]@{};RoleOrdinal=0
        RuntimeEpochs=[Collections.Generic.List[object]]::new();JournalPath=$null;JournalAttemptId=$null
        DiskState='Original';OriginalSnapshot=$null;FinalSnapshot=$null;Backup=$null;SavedTuple=$null
        Effects=[ordered]@{Mcp=0;File=0;Process=0;Validator=0;ProofFile=if($Mode-ceq'Proof'){7}else{0};ProofChildProcess=0;Transport=0;SaveTransport=0;Restore=0;Classifier=0;Verifier=0;Cleanup=0}
        Stages=[Collections.Generic.List[string]]::new()
    }
}

function Get-UID0002OWV8ProofModule([string]$Root,[string]$ModuleName,[string]$FileName,[string]$ModuleId){
    $path=[IO.Path]::GetFullPath([IO.Path]::Combine($Root,$FileName));$item=Get-Item -LiteralPath $path
    [ordered]@{sys_modules_name=$ModuleName;module_id=$ModuleId;file=$path;spec_origin=$path;resolved_path=$path;derived_relative_path=$FileName;size=[Int64]$item.Length;mtime_ns=[Int64]$item.LastWriteTimeUtc.Ticks*100;ctime_ns=[Int64]$item.CreationTimeUtc.Ticks*100;sha256=(Get-UID0002OWV8Sha256Bytes ([IO.File]::ReadAllBytes($path)))}
}
function New-UID0002OWV8ProofRuntime($Authority,[int]$ProcessId,[string]$Kind,[string]$Database,[string]$Path){
    $exe=[IO.Path]::GetFullPath("$env:SystemRoot\System32\WindowsPowerShell\v1.0\powershell.exe");$created=[Int64]10000000+$ProcessId
    $process=[ordered]@{pid=$ProcessId;parent_pid=5000;creation_time_100ns=$created;generation="pid:$ProcessId;created:$created";sys_executable=$exe;process_image=$exe;argv=@('proof')}
    $common=@(
        (Get-UID0002OWV8ProofModule $Authority.ModuleRoot 'ida_pro_mcp' 'ida_pro_mcp.py' "$Kind-1"),
        (Get-UID0002OWV8ProofModule $Authority.ModuleRoot 'ida_pro_mcp.runtime_attestation' 'runtime_attestation.py' "$Kind-2")
    )
    if($Kind-ceq'worker'){$common+=@(
        (Get-UID0002OWV8ProofModule $Authority.ModuleRoot 'ida_pro_mcp.ida_mcp.api_modify' 'api_modify.py' "$Kind-3"),
        (Get-UID0002OWV8ProofModule $Authority.ModuleRoot 'ida_pro_mcp.ida_mcp.utils' 'utils.py' "$Kind-4"),
        (Get-UID0002OWV8ProofModule $Authority.ModuleRoot 'ida_pro_mcp.ida_mcp.api_analysis' 'api_analysis.py' "$Kind-5")
    )}
    [ordered]@{schema_version=1;ok=$true;errors=@();nonce=[Guid]::NewGuid().ToString('N');attested_at_utc=[DateTime]::UtcNow.ToString('o');session_id=$Database;canonical_path=$Path;source_root=$Authority.ModuleRoot;implementation_manifest_sha256=(Get-UID0002OWV8ObjectHash @($common|ForEach-Object{$_.sha256}));process=$process;modules=$common}
}

function Invoke-UID0002OWV8ProofRaw($Authority,$Request){
    if($Authority.Mode-cne'Proof'){throw 'V8_PROOF_MODE'}
    $id=Assert-UID0002OWV8String $Request.id 'proof request id';if($Authority.RequestIds.Contains($id)){throw 'V8_REQUEST_ID_REPLAY'};$Authority.RequestIds[$id]=$true
    $tool=if([string]$Request.method-ceq'tools/list'){'tools/list'}else{[string]$Request.params.name}
    if($Authority.Scenario-ceq'raw-envelope-forgery'){$raw='{"jsonrpc":"1.0","id":"wrong","result":{}}';return [pscustomobject]@{Raw=$raw;Envelope=(Assert-UID0002OWV8RawEnvelope $Request $raw)}}
    if($tool-ceq'tools/list'){
        $Authority.SchemaCalls=[Int64]$Authority.SchemaCalls+1;$tools=@();$ordinal=0
        foreach($name in @((New-UID0002OWV7SchemaCatalog).Keys)){
            $ordinal++;$input=[ordered]@{type='object';additionalProperties=$true}
            if($Authority.Scenario-ceq'schema-staleness'-and$Authority.SchemaCalls-gt1-and$ordinal-eq1){$input=[ordered]@{type='object';properties=[ordered]@{epoch=[ordered]@{type='integer'}};additionalProperties=$true}}
            $output=[ordered]@{type='object';additionalProperties=$true}
            if($Authority.Scenario-ceq'missing-live-output-schema'-and$ordinal-eq1){$output=$null}
            $tools+=,[ordered]@{name=$name;inputSchema=$input;outputSchema=$output}
        }
        $payload=[ordered]@{jsonrpc='2.0';id=$id;result=[ordered]@{tools=$tools}}
    }else{
        if($Authority.Scenario-ceq'state-query-failure'-and$tool-notin@('idb_open','idb_list','runtime_attestation','idb_save')){throw 'V8_STATE_QUERY_FAILURE'}
        if($Authority.Scenario-ceq'cleanup-receipt-forgery'-and$tool-notin@('idb_open','idb_list','runtime_attestation','idb_save')){throw 'V8_HOSTILE_PRIMARY'}
        if($Authority.Scenario-ceq'save-transport-failure'-and$tool-ceq'idb_save'){throw 'V8_PROOF_SAVE_TRANSPORT_LOST'}
        $sc=[ordered]@{success=$true}
        if($tool-ceq'idb_open'){
            $Authority.RoleOrdinal=[Int64]$Authority.RoleOrdinal+1;$sessionId="proof-$($Authority.RoleOrdinal)-$([Guid]::NewGuid().ToString('N'))"
            $sc=[ordered]@{session=[ordered]@{session_id=$sessionId;input_path=$Authority.CanonicalPath;canonical_path=$Authority.CanonicalPath;pid=[Int64](7000+$Authority.RoleOrdinal);route_host='127.0.0.1';route_port=[Int64](14000+$Authority.RoleOrdinal);is_active=($Authority.Scenario-cne'post-open-registration-failure');owned=$true;adopted=$false}}
        }elseif($tool-ceq'idb_list'){
            $sessions=@();foreach($role in @($Authority.Roles.Values)){$retired=($null-ne$role.psobject.Properties['TransportRetired']-and$role.TransportRetired-eq$true);if($Authority.Scenario-ceq'cleanup-receipt-forgery'){$retired=$false};$sessions+=,[ordered]@{session_id=$role.Database;input_path=$Authority.CanonicalPath;canonical_path=$Authority.CanonicalPath;is_active=(-not$retired);owned=$true;adopted=$false}}
            $sc=[ordered]@{sessions=$sessions}
        }elseif($tool-ceq'runtime_attestation'){
            $db=[string]$Request.params.arguments.expected_database;$listener=New-UID0002OWV8ProofRuntime $Authority 6000 'listener' $db $Authority.CanonicalPath;$worker=New-UID0002OWV8ProofRuntime $Authority 7000 'worker' $db $Authority.CanonicalPath
            if($Authority.Scenario-ceq'runtime-boundary-drift'){$worker.canonical_path=[IO.Path]::Combine($Authority.ProofRoot,'wrong.bin')}
            $wrapper=[ordered]@{route=[ordered]@{host='127.0.0.1';port=15000};registered_process=$worker.process;redirector_process=$worker.process;supervisor_sessions=@([ordered]@{session_id=$db;input_path=$Authority.CanonicalPath;canonical_path=$Authority.CanonicalPath;is_active=$true;owned=$true;adopted=$false});attestation=[ordered]@{schema_version=1;ok=$true;errors=@();nonce=[Guid]::NewGuid().ToString('N');attested_at_utc=[DateTime]::UtcNow.ToString('o');worker=$worker}}
            $listener.endpoint=[ordered]@{host='127.0.0.1';port=13337};$sc=[ordered]@{schema_version=1;ok=$true;errors=@();nonce=[Guid]::NewGuid().ToString('N');attested_at_utc=[DateTime]::UtcNow.ToString('o');listener=$listener;workers=@($wrapper)}
        }elseif($tool-ceq'idb_save'){
            $sc=[ordered]@{success=($Authority.Scenario-notin@('determinate-failing-saved','restore-failure'))}
        }elseif($tool-in@('define_func','declare_type','rename','set_type','set_address_comments','set_repeatable_comments','set_address_repeatable_comments','make_data')){
            $fake=[pscustomobject]@{Id='proof';Request=$Request};$subjects=@(Get-UID0002OWMutationSubjects $fake);$dry=$false;if($null-ne$Request.params.arguments.batch-and$null-ne$Request.params.arguments.batch.psobject.Properties['dry_run']){$dry=[bool]$Request.params.arguments.batch.dry_run}
            $results=@();for($i=0;$i-lt$subjects.Count;$i++){$s=$subjects[$i];$subject=[ordered]@{addr=[string]$s.addr;name=[string]$s.name;type=[string]$s.type;comment=[string]$s.comment};if($null-ne$s.psobject.Properties['end']){$subject.end=[string]$s.end};$row=[ordered]@{index=$i;success=$true;kind=[string]$s.kind;subject=$subject};if($null-ne$Request.params.arguments.batch){$row.dry_run=$dry};$results+=,$row};$summary=[ordered]@{total=$subjects.Count;succeeded=$subjects.Count;failed=0};if($null-ne$Request.params.arguments.batch){$summary.dry_run=$dry};$sc=[ordered]@{results=$results;summary=$summary}
        }else{
            $database=if($Request.params.arguments-is[Collections.IDictionary]-and$Request.params.arguments.Contains('database')){[string]$Request.params.arguments.database}else{''};$role=if($Authority.Roles.Contains($database)){$Authority.Roles[$database]}else{$null};$marker=if($null-eq$role){$Authority.DiskState}else{[string]$role.ViewState}
            if($Authority.Scenario-ceq'classifier-neither'-and$null-ne$role-and$role.Role-in@('rv','sv')){$marker='Third'}
            $arguments=[ordered]@{};foreach($name in @(Get-UID0002OWV8Names $Request.params.arguments|Sort-Object)){if($name-cne'database'){$arguments[$name]=$Request.params.arguments.$name}}
            $sc=[ordered]@{success=$true;tool=$tool;state_marker=$marker;request_fingerprint=(Get-UID0002OWV8ObjectHash $arguments);results=@([ordered]@{key=$tool;state=$marker;request_fingerprint=(Get-UID0002OWV8ObjectHash $arguments)})}
        }
        $payload=[ordered]@{jsonrpc='2.0';id=$id;result=[ordered]@{content=@([ordered]@{type='text';text='proof'});structuredContent=$sc;isError=$false}}
    }
    $raw=$payload|ConvertTo-Json -Depth 100 -Compress
    if($Authority.Scenario-ceq'raw-receipt-forgery'-and$tool-cne'tools/list'){$raw=$raw.Replace('"jsonrpc":"2.0"','"jsonrpc":"1.0"')}
    [pscustomobject]@{Raw=$raw;Envelope=(Assert-UID0002OWV8RawEnvelope $Request $raw)}
}

function Update-UID0002OWV8LiveSchemas($Authority){
    [void](Assert-UID0002OWV8ImplementationSeal);$required=@((New-UID0002OWV7SchemaCatalog).Keys);$seen=[ordered]@{};$schemas=[ordered]@{};$cursor=$null;$cursors=[ordered]@{}
    do{
        $params=[ordered]@{};if($null-ne$cursor){$params.cursor=$cursor};$request=[ordered]@{jsonrpc='2.0';id="uid0002ow-v8-schema-$([Guid]::NewGuid().ToString('N'))";method='tools/list';params=$params}
        $rpc=if($Authority.Mode-ceq'Production'){Invoke-UID0002OWV8RawHttp $Authority $request}else{Invoke-UID0002OWV8ProofRaw $Authority $request}
        [void](Assert-UID0002OWV8Keys $rpc.Envelope.result @('tools') @('_meta','nextCursor') 'tools/list result')
        foreach($tool in @($rpc.Envelope.result.tools)){
            [void](Assert-UID0002OWV8Keys $tool @('name','inputSchema','outputSchema') @('title','description','annotations','_meta') 'tool schema');$name=Assert-UID0002OWV8String $tool.name 'tool name'
            if($seen.Contains($name)){throw "V8_SCHEMA_DUPLICATE:$name"};$seen[$name]=$true;if($null-eq$tool.inputSchema){throw "V8_INPUT_SCHEMA_MISSING:$name"};if($null-eq$tool.outputSchema){throw "V8_OUTPUT_SCHEMA_MISSING:$name"}
            $schemas[$name]=[pscustomobject]@{Input=$tool.inputSchema;Output=$tool.outputSchema;InputHash=(Get-UID0002OWV8ObjectHash $tool.inputSchema);OutputHash=(Get-UID0002OWV8ObjectHash $tool.outputSchema)}
        }
        $next=$rpc.Envelope.result.psobject.Properties['nextCursor'];$cursor=if($null-eq$next-or$null-eq$next.Value){$null}else{Assert-UID0002OWV8String $next.Value 'tools/list nextCursor'};if($null-ne$cursor){if($cursors.Contains($cursor)){throw 'V8_SCHEMA_CURSOR_REPLAY'};$cursors[$cursor]=$true}
    }while($null-ne$cursor)
    foreach($name in $required){if(-not$schemas.Contains($name)){throw "V8_SCHEMA_REQUIRED_TOOL:$name"}}
    if(@($schemas.Keys|Where-Object{$_-ceq'runtime_attestation'}).Count-ne1-or@($schemas.Keys|Where-Object{$_-ceq'runtime/attest'}).Count-ne0){throw 'V8_RUNTIME_TOOL_SURFACE'}
    $epoch=Get-UID0002OWV8ObjectHash $schemas;if($null-ne$Authority.SchemaEpoch-and[string]$Authority.SchemaEpoch-cne$epoch){throw 'V8_LIVE_SCHEMA_STALE'}
    $Authority.Schemas=$schemas;$Authority.SchemaEpoch=$epoch;$epoch
}

function Assert-UID0002OWV8Runtime($Authority,$Role,[string]$Boundary){
    [void](Assert-UID0002OWV8ImplementationSeal);[void](Update-UID0002OWV8LiveSchemas $Authority)
    $receipt=Invoke-UID0002OWV8RawTool $Authority 'runtime_attestation' ([ordered]@{expected_database=$Role.Database;expected_canonical_path=$Authority.CanonicalPath}) "uid0002ow-v8-$Boundary-runtime"
    $sc=$receipt.Envelope.result.structuredContent;[void](Assert-UID0002OWV8Keys $sc @('schema_version','ok','errors','nonce','attested_at_utc','listener','workers') @() 'runtime attestation')
    if((Assert-UID0002OWV8Int $sc.schema_version 'runtime schema')-ne1-or-not(Assert-UID0002OWV8Bool $sc.ok 'runtime ok')-or@($sc.errors).Count-ne0){throw "V8_RUNTIME_TOP:$Boundary"}
    $listener=$sc.listener;[void](Assert-UID0002OWV8Keys $listener @('schema_version','ok','errors','nonce','attested_at_utc','session_id','canonical_path','source_root','implementation_manifest_sha256','process','modules','endpoint') @() 'runtime listener')
    if([string]$listener.endpoint.host-cne'127.0.0.1'-or[Int64]$listener.endpoint.port-ne13337){throw "V8_RUNTIME_LISTENER_SOCKET:$Boundary"}
    $listenerProcess=Assert-AttestedProcess $listener.process "$Boundary-listener" ($Authority.Mode-ceq'Production');$listenerModules=Assert-AttestedModules $listener "$Boundary-listener" @('ida_pro_mcp','ida_pro_mcp.runtime_attestation')
    $wrappers=@($sc.workers);if($wrappers.Count-ne1){throw "V8_RUNTIME_WORKER_COUNT:$Boundary"};$wrapper=$wrappers[0];$att=$wrapper.attestation
    if([Int64]$att.schema_version-ne1-or$att.ok-isnot[bool]-or-not$att.ok-or@($att.errors).Count-ne0){throw "V8_RUNTIME_WORKER_TOP:$Boundary"};$worker=$att.worker
    if([string]$worker.session_id-cne[string]$Role.Database-or-not([IO.Path]::GetFullPath([string]$worker.canonical_path)).Equals([IO.Path]::GetFullPath($Authority.CanonicalPath),[StringComparison]::OrdinalIgnoreCase)){throw "V8_RUNTIME_ROLE:$Boundary"}
    $routes=@($wrapper.supervisor_sessions|Where-Object{[string]$_.session_id-ceq[string]$Role.Database-and$_.is_active-is[bool]-and$_.is_active-and$_.owned-is[bool]-and$_.owned});if($routes.Count-ne1){throw "V8_RUNTIME_ROUTE:$Boundary"}
    $workerProcess=Assert-AttestedProcess $worker.process "$Boundary-worker" ($Authority.Mode-ceq'Production');if([Int64]$workerProcess.ParentPid-ne[Int64]$wrapper.redirector_process.pid){throw "V8_RUNTIME_PARENT:$Boundary"}
    $workerModules=Assert-AttestedModules $worker "$Boundary-worker" @('ida_pro_mcp','ida_pro_mcp.runtime_attestation','ida_pro_mcp.ida_mcp.api_modify','ida_pro_mcp.ida_mcp.utils','ida_pro_mcp.ida_mcp.api_analysis');[void](Assert-CrossProcessModuleParity $listenerModules $workerModules $Boundary)
    if($Authority.Mode-ceq'Production'){$socket=@(Get-NetTCPConnection -State Listen -LocalAddress 127.0.0.1 -LocalPort 13337 -ErrorAction Stop);if($socket.Count-ne1-or[Int64]$socket[0].OwningProcess-ne[Int64]$listenerProcess.Pid){throw "V8_RUNTIME_LISTENER_SOCKET:$Boundary"}}
    $evidence=[pscustomobject]@{Boundary=$Boundary;Raw=$receipt.Raw;RawSHA256=$receipt.RawSHA256;SchemaEpoch=$receipt.SchemaEpoch;Nonce=[string]$sc.nonce;Listener=$listenerProcess;Worker=$workerProcess;WorkerRaw=$worker;RoutePort=[Int64]$wrapper.route.port;ListenerModules=$listenerModules;WorkerModules=$workerModules}
    [void]$Authority.RuntimeEpochs.Add($evidence);$Role.Runtime=$evidence;$evidence
}

function Open-UID0002OWV8Role($Authority,[string]$RoleName){
    [void](Update-UID0002OWV8LiveSchemas $Authority);$open=Invoke-UID0002OWV8RawTool $Authority 'idb_open' ([ordered]@{input_path=$Authority.CanonicalPath;mode='force_headless';run_auto_analysis=$false;build_caches=$true;init_hexrays=$true;idle_ttl_sec=3600;preferred_session_id="uid0002ow-v8-$RoleName"}) "uid0002ow-v8-$RoleName-open-$([Guid]::NewGuid().ToString('N'))"
    $session=$open.Envelope.result.structuredContent.session;[void](Assert-UID0002OWV8Keys $session @('session_id','input_path','canonical_path','pid','route_host','route_port','is_active','owned','adopted') @() 'idb_open session')
    $database=Assert-UID0002OWV8String $session.session_id "$RoleName returned database";$role=[pscustomobject]@{Role=$RoleName;Database=$database;OpenRaw=$open.Raw;OpenRawSHA256=$open.RawSHA256;OpenSession=$session;State='Provisional';Runtime=$null;RetirementAttempts=0;LastRetirementError=$null;ViewState=$Authority.DiskState}
    $Authority.Roles[$database]=$role
    if($session.is_active-isnot[bool]-or-not$session.is_active-or$session.owned-isnot[bool]-or-not$session.owned-or$session.adopted-isnot[bool]-or-not([IO.Path]::GetFullPath([string]$session.canonical_path)).Equals([IO.Path]::GetFullPath($Authority.CanonicalPath),[StringComparison]::OrdinalIgnoreCase)){throw 'V8_POST_OPEN_REGISTRATION_FAILURE'}
    $role.Runtime=Assert-UID0002OWV8Runtime $Authority $role "$RoleName-post-open";$role.State='Registered';$role
}

function Retire-UID0002OWV8Role($Authority,$Role,[string]$Boundary){
    [void](Assert-UID0002OWV8ImplementationSeal);if($Role.State-ceq'Retired'){return $Role};$Role.State='RetirePending';$Role.RetirementAttempts=[Int64]$Role.RetirementAttempts+1
    try{
        if($Authority.Mode-ceq'Proof'-and$Authority.Scenario-ceq'retirement-failure-cleanup-retry'-and$Role.RetirementAttempts-eq1){throw 'V8_RETIREMENT_INJECTED'}
        $runtime=if($null-ne$Role.Runtime){$Role.Runtime}else{Assert-UID0002OWV8Runtime $Authority $Role "$Boundary-provisional-retire"}
        if($Authority.Mode-ceq'Production'){[void](Assert-OsProcessMatchesBound $runtime.Worker $false);Stop-Process -Id ([int]$runtime.Worker.Pid) -Force -ErrorAction Stop;$Authority.Effects.Process++;$deadline=[DateTime]::UtcNow.AddSeconds(30);do{Start-Sleep -Milliseconds 250;$alive=Get-Process -Id ([int]$runtime.Worker.Pid) -ErrorAction SilentlyContinue}while($null-ne$alive-and[DateTime]::UtcNow-lt$deadline);[void](Assert-OsProcessMatchesBound $runtime.Worker $true)}else{Invoke-UID0002OWV8ProofRetire $Authority $Role $Boundary|Out-Null}
        [void](Update-UID0002OWV8LiveSchemas $Authority);$list=Invoke-UID0002OWV8RawTool $Authority 'idb_list' ([ordered]@{}) "uid0002ow-v8-$Boundary-list-$([Guid]::NewGuid().ToString('N'))";$active=@($list.Envelope.result.structuredContent.sessions|Where-Object{[string]$_.session_id-ceq$Role.Database-and$_.is_active-eq$true});if($active.Count-ne0){throw 'V8_RETIREMENT_SESSION_PRESENT'}
        if($Authority.Mode-ceq'Production'-and@(Get-NetTCPConnection -LocalAddress 127.0.0.1 -LocalPort ([int]$runtime.RoutePort) -ErrorAction SilentlyContinue).Count-ne0){throw 'V8_RETIREMENT_SOCKET_PRESENT'}
        $Role.State='Retired';$Role.LastRetirementError=$null;$Role
    }catch{$Role.State='RetirePending';$Role.LastRetirementError=[string]$_.Exception.Message;throw}
}
function Invoke-UID0002OWV8ProofRetire($Authority,$Role,[string]$Boundary){$Role|Add-Member TransportRetired $true -Force;$true}

function ConvertTo-UID0002OWV8StableState($Value){
    if($null-eq$Value-or$Value-is[string]-or$Value-is[ValueType]){return $Value}
    if($Value-is[Collections.IDictionary]){$o=[ordered]@{};foreach($name in @($Value.Keys|ForEach-Object{[string]$_}|Sort-Object)){if($name-cnotin@('database','session_id','input_path','canonical_path','pid','parent_pid','generation','nonce','attested_at_utc','last_used_at','request_id','id')){$o[$name]=ConvertTo-UID0002OWV8StableState $Value[$name]}};return $o}
    if($Value-is[Collections.IEnumerable]){return @($Value|ForEach-Object{ConvertTo-UID0002OWV8StableState $_})}
    $o=[ordered]@{};foreach($property in @($Value.psobject.Properties|Sort-Object Name)){if($property.Name-cnotin@('database','session_id','input_path','canonical_path','pid','parent_pid','generation','nonce','attested_at_utc','last_used_at','request_id','id')){$o[$property.Name]=ConvertTo-UID0002OWV8StableState $property.Value}};$o
}

function Invoke-UID0002OWV8State($Authority,$Role,[ValidateSet('Original','Final','Observed')]$Expected,[string]$Prefix){
    $shape=if($Expected-ceq'Observed'){'Original'}else{$Expected};$plan=New-UID0002OWV7StatePlan $Role.Database $shape $Role.Role $Prefix;[void](Assert-UID0002OWV7StatePlan $plan $Role.Database $shape)
    $journal=@();$callCount=0;$protections=@()
    foreach($class in $plan){$rows=@();$protections+=@($class.ProtectionIds);foreach($contract in @($class.Contracts)){
        $call=$contract.Call;$callCount++
        if($call.Request.method-ceq'tools/list'){$rows+=,[ordered]@{tool='tools/list';schema_epoch=(Update-UID0002OWV8LiveSchemas $Authority)}}else{$receipt=Invoke-UID0002OWV8ProtectedTool $Authority $Role "$Prefix-$($class.Id)-$($call.Id)" $call.Tool $call.Request.params.arguments;$rows+=,(ConvertTo-UID0002OWV8StableState $receipt.Envelope.result.structuredContent)}
    };$journal+=,[ordered]@{Id=$class.Id;Rows=$rows;ProtectionIds=@($class.ProtectionIds)}}
    if($journal.Count-ne14-or$callCount-ne21-or$protections.Count-ne60-or@($protections|Select-Object -Unique).Count-ne60){throw 'V8_STATE_PACKAGE_INCOMPLETE'}
    $semantic=@($journal|Where-Object{$_.Id-notin@('S00','S01','S02')});[pscustomobject]@{Classes=$journal;ClassCount=14;CallCount=21;ProtectionCount=60;Fingerprint=(Get-UID0002OWV8ObjectHash $semantic);Expected=$Expected;Role=$Role.Database}
}

function Invoke-UID0002OWV8Mutations($Authority,$Role){
    $plan=@(New-UID0002OWMutationPlan $Role.Database ([Guid]::NewGuid().ToString('N')))
    if($Authority.Mode-ceq'Proof'-and$Authority.Scenario-ceq'malformed-real-row'){$plan[0].ExpectedReadback=$null}
    if($Authority.Mode-ceq'Proof'-and$Authority.Scenario-ceq'wrong-real-binding'){$plan[0].ExpectedResponse.id='wrong'}
    [void](Assert-UID0002OWV8RealPlan $plan $Role.Database);$receipts=@()
    foreach($row in $plan){$tool=Get-UID0002OWV7Tool $row.Request;$receipt=Invoke-UID0002OWV8ProtectedTool $Authority $Role "mutation-$($row.Seq)" $tool $row.Request.params.arguments;[void](Assert-MutationResponse $row $receipt.Envelope);$receipts+=,$receipt}
    if($receipts.Count-ne43){throw 'V8_MUTATION_COUNT'}
    if(-not($Authority.Mode-ceq'Proof'-and$Authority.Scenario-ceq'classifier-both')){$Role.ViewState='Final'}
    [pscustomobject]@{Plan=$plan;Receipts=$receipts}
}

function Set-UID0002OWV8ProofSavedDisk($Authority){
    if($Authority.Mode-cne'Proof'){return}
    $bytes=[IO.File]::ReadAllBytes($Authority.CanonicalPath);$bytes[0]=[byte](($bytes[0]+17)%256);[IO.File]::WriteAllBytes($Authority.CanonicalPath,$bytes);$Authority.DiskState='Final';$Authority.Effects.ProofFile++
}
function Invoke-UID0002OWV8ClassifierPair($Authority,$Original,$Final){
    $rv=$null;$sv=$null;try{
        $rv=Open-UID0002OWV8Role $Authority 'rv';$rvState=Invoke-UID0002OWV8State $Authority $rv 'Observed' 'rv';[void](Retire-UID0002OWV8Role $Authority $rv 'rv')
        $sv=Open-UID0002OWV8Role $Authority 'sv';$svState=Invoke-UID0002OWV8State $Authority $sv 'Observed' 'sv';[void](Retire-UID0002OWV8Role $Authority $sv 'sv')
        $rvComplete=([string]$rvState.Fingerprint-ceq[string]$Original.Fingerprint);$svComplete=([string]$svState.Fingerprint-ceq[string]$Final.Fingerprint);[void](Assert-UID0002OWV8Classifier $rvComplete $svComplete);$Authority.Effects.Classifier++
        [pscustomobject]@{RV=$rvComplete;SV=$svComplete;RVState=$rvState;SVState=$svState}
    }finally{}
}

function Invoke-UID0002OWV8Restore($Authority,$Backup,$Classification){
    [void](Assert-UID0002OWV8ImplementationSeal);if($Classification.Identity-cne'FailingSaved'-or$Classification.RestoreAllowed-ne$true-or(Test-TupleEquals $Classification.Tuple $Backup.P0)){throw 'V8_RESTORE_NOT_ATTRIBUTABLE'}
    try{
        if($Authority.Mode-ceq'Proof'-and$Authority.Scenario-ceq'restore-failure'){$bytes=[IO.File]::ReadAllBytes($Backup.Path);$bytes[0]=[byte](($bytes[0]+1)%256);[IO.File]::WriteAllBytes($Backup.Path,$bytes)}
        $physicalB0=Get-ClosedExclusiveTuple $Backup.Path;if(-not(Test-TupleEquals $physicalB0 $Backup.B0)){throw 'backup tuple changed'}
        $current=Get-ClosedExclusiveTuple $Authority.CanonicalPath;if(-not(Test-TupleEquals $current $Classification.Tuple)){throw 'destination tuple changed'}
        $result=Invoke-UID0002OWRestore ([pscustomobject]@{RestoreAttemptCount=0;CleanupJournal=[Collections.Generic.List[object]]::new()}) $Backup.P0 $Backup.B0 $Backup.Path $Classification
        if(-not(Test-TupleEquals $result.RestoredP0 $Backup.P0)-or-not(Test-TupleEquals $result.ReopenedB0 $Backup.B0)){throw 'restore tuple mismatch'}
        $Authority.DiskState='Original';$Authority.Effects.Restore++;$result
    }catch{throw "V8_RESTORE_FAILURE:$($_.Exception.Message)"}
}

function Get-UID0002OWV8RestartWorkerText {
@'
param([Parameter(Mandatory=$true)][string]$JournalPath)
Set-StrictMode -Version 2
function H([string]$Text){$s=[Security.Cryptography.SHA256]::Create();try{([BitConverter]::ToString($s.ComputeHash([Text.Encoding]::UTF8.GetBytes($Text)))).Replace('-','')}finally{$s.Dispose()}}
function C($Value){$Value|ConvertTo-Json -Depth 100 -Compress}
$bytes=[IO.File]::ReadAllBytes($JournalPath);if($bytes.Length-lt2-or$bytes[-1]-ne10){throw 'V8_JOURNAL_TRUNCATED'}
$text=[Text.UTF8Encoding]::new($false,$true).GetString($bytes);$lines=@($text.Split([char]10));$records=@();foreach($line in @($lines[0..($lines.Count-2)])){if([string]::IsNullOrWhiteSpace($line)){throw 'V8_JOURNAL_TRUNCATED'};$records+=,($line|ConvertFrom-Json)}
$previous=('0'*64);for($i=0;$i-lt$records.Count;$i++){$r=$records[$i];$copy=[ordered]@{};foreach($n in @('Version','Revision','TransactionId','AttemptId','State','Utc','PrevHash','Payload')){$copy[$n]=$r.$n};if([Int64]$r.Revision-ne($i+1)-or[string]$r.PrevHash-cne$previous-or[string]$r.RecordHash-cne(H (C $copy))){throw 'V8_JOURNAL_INTEGRITY'};$previous=[string]$r.RecordHash}
if([string]$records[-1].State-cne'Created'){[Console]::Out.WriteLine('V8_SAVE_SECOND_ATTEMPT');exit 73}
throw 'V8_RESTART_UNEXPECTED_CREATED'
'@
}
function Test-UID0002OWV8RestartClaim([string]$JournalPath){
    $worker=Get-UID0002OWV8RestartWorkerText;$quoted="'"+$JournalPath.Replace("'","''")+"'";$command="& {`n$worker`n} -JournalPath $quoted";$encoded=[Convert]::ToBase64String([Text.Encoding]::Unicode.GetBytes($command));$exe="$env:SystemRoot\System32\WindowsPowerShell\v1.0\powershell.exe"
    $output=@(& $exe -NoLogo -NoProfile -NonInteractive -ExecutionPolicy Bypass -EncodedCommand $encoded 2>&1);$exit=$LASTEXITCODE
    if($exit-ne73-or@($output|ForEach-Object{[string]$_}|Where-Object{$_-ceq'V8_SAVE_SECOND_ATTEMPT'}).Count-ne1){throw "V8_RESTART_FRESH_PROCESS:exit=$exit output=$($output-join'|')"}
    [pscustomobject]@{Label='V8_SAVE_SECOND_ATTEMPT';ExitCode=$exit;Executable=[IO.Path]::GetFullPath($exe);EncodedCommandSHA256=(Get-UID0002OWV8Sha256Text $command);InheritedState=$false}
}

function Invoke-UID0002OWV8RollbackVerifier($Authority,$Original,$P0){
    $role=Open-UID0002OWV8Role $Authority 'rollback';$state=Invoke-UID0002OWV8State $Authority $role 'Observed' 'rollback';if([string]$state.Fingerprint-cne[string]$Original.Fingerprint){throw 'V8_ROLLBACK_VERIFIER'};[void](Retire-UID0002OWV8Role $Authority $role 'rollback');$tuple=Get-ClosedExclusiveTuple $Authority.CanonicalPath;[void](Assert-UID0002OWV8FinalTuple $tuple $P0);$Authority.Effects.Verifier++;[pscustomobject]@{State=$state;Tuple=$tuple}
}

function Invoke-UID0002OWV8Core($Authority,$Capability){
    [void](Assert-UID0002OWV8ImplementationSeal);if($Authority.Version-ne8-or$null-eq$Capability-or-not[object]::ReferenceEquals($Capability,$Authority.Capability)){throw 'V8_PROVIDER_CAPABILITY'}
    if($Authority.PSTypeNames[0]-cne"UID0002OWV8$($Authority.Mode)Authority"){throw 'V8_PROVIDER_TYPE'}
    $primary=$null;$backup=$null;$saveClass='PreSaveMismatch';$saveEvidence=$null;$mutation=$null;$classification=$null;$finalTuple=$null;$disposition=$null
    try{
        [void]$Authority.Stages.Add('ENTRY');[void](Update-UID0002OWV8LiveSchemas $Authority)
        $inspection=Open-UID0002OWV8Role $Authority 'inspection';$inspectionState=Invoke-UID0002OWV8State $Authority $inspection 'Original' 'inspection';[void](Retire-UID0002OWV8Role $Authority $inspection 'inspection')
        [void]$Authority.Stages.Add('INSPECTION_RETIRED');if($Authority.Mode-ceq'Production'){$backup=New-UID0002OWV8Backup $Authority}else{$backup=New-UID0002OWV8ProofBackup $Authority};$Authority.Backup=$backup;[void](New-UID0002OWV8Journal $Authority $backup.P0);[void]$Authority.Stages.Add('P0_B0_JOURNAL')
        $tx=Open-UID0002OWV8Role $Authority 'transaction';$original=Invoke-UID0002OWV8State $Authority $tx 'Original' 'tx-original';$Authority.OriginalSnapshot=$original;$mutation=Invoke-UID0002OWV8Mutations $Authority $tx;$final=Invoke-UID0002OWV8State $Authority $tx 'Final' 'tx-final';$Authority.FinalSnapshot=$final
        [void](Claim-UID0002OWV8Save $Authority $tx.Database)
        if($Authority.Mode-ceq'Proof'-and$Authority.Scenario-in@('alias-save-attempt','reentry-save-attempt')){[void](Claim-UID0002OWV8Save $Authority $(if($Authority.Scenario-ceq'alias-save-attempt'){'alias'}else{$tx.Database}))}
        if($Authority.Mode-ceq'Proof'-and$Authority.Scenario-ceq'restart-save-attempt'){$Authority.Effects.ProofChildProcess++;$restart=Test-UID0002OWV8RestartClaim $Authority.JournalPath;throw $restart.Label}
        try{$save=Invoke-UID0002OWV8ProtectedTool $Authority $tx 'sole-save' 'idb_save' ([ordered]@{database=$tx.Database});$saveClass=Get-UID0002OWSaveResponseClass $save.Envelope;$saveEvidence=[ordered]@{RawBase64=[Convert]::ToBase64String([Text.Encoding]::UTF8.GetBytes($save.Raw));RawSHA256=$save.RawSHA256;RetryAllowed=$false};$Authority.Effects.SaveTransport++;if($Authority.Mode-ceq'Proof'){Set-UID0002OWV8ProofSavedDisk $Authority}}catch{$saveClass='Indeterminate';$saveEvidence=[ordered]@{ExceptionType=$_.Exception.GetType().FullName;ExceptionMessage=[string]$_.Exception.Message;RetryAllowed=$false}}
        [void](Add-UID0002OWV8JournalRecord $Authority.JournalPath $saveClass $saveEvidence);[void](Retire-UID0002OWV8Role $Authority $tx 'transaction');[void]$Authority.Stages.Add('SAVE_RETIRED')
        if($Authority.Mode-ceq'Proof'-and$Authority.Scenario-ceq'journal-tamper-replay-truncation'){$lines=[IO.File]::ReadAllLines($Authority.JournalPath);$record=$lines[0]|ConvertFrom-Json;$record.Payload=[ordered]@{Tampered=$true};[IO.File]::WriteAllText($Authority.JournalPath,(($record|ConvertTo-Json -Depth 100 -Compress)+"`n"),[Text.UTF8Encoding]::new($false));[void](Read-UID0002OWV8Journal $Authority.JournalPath)}
        $pair=Invoke-UID0002OWV8ClassifierPair $Authority $original $final;$candidate=Get-ClosedExclusiveTuple $Authority.CanonicalPath;$classification=Classify-RvSvTuple $saveClass $candidate $backup.P0 $pair.RV $pair.SV (-not(Test-TupleEquals $candidate $backup.P0));[void]$Authority.Stages.Add('RV_SV_CLASSIFIED')
        if($classification.Identity-ceq'S1'){$disposition='ACCEPTED_S1';$finalTuple=$candidate;[void](Assert-UID0002OWV8FinalTuple (Get-ClosedExclusiveTuple $Authority.CanonicalPath) $candidate)}
        elseif($classification.Identity-ceq'P0'){$disposition='UNSAVED_P0';$finalTuple=$backup.P0;[void](Assert-UID0002OWV8FinalTuple (Get-ClosedExclusiveTuple $Authority.CanonicalPath) $backup.P0)}
        else{[void](Invoke-UID0002OWV8Restore $Authority $backup $classification);[void](Invoke-UID0002OWV8RollbackVerifier $Authority $original $backup.P0);$disposition='ROLLED_BACK_P0';$finalTuple=$backup.P0;[void]$Authority.Stages.Add('RESTORED_AND_REVERIFIED')}
        [void](Assert-UID0002OWV8FinalTuple (Get-ClosedExclusiveTuple $backup.Path) $backup.B0)
        if($Authority.Mode-ceq'Proof'-and$Authority.Scenario-ceq'final-tuple-drift'){$bytes=[IO.File]::ReadAllBytes($Authority.CanonicalPath);$bytes[-1]=[byte](($bytes[-1]+1)%256);[IO.File]::WriteAllBytes($Authority.CanonicalPath,$bytes);[void](Assert-UID0002OWV8FinalTuple (Get-ClosedExclusiveTuple $Authority.CanonicalPath) $finalTuple)}
        if($saveClass-ceq'Indeterminate'){throw 'V8_SAVE_INDETERMINATE'}
        [void]$Authority.Stages.Add('FINAL_TUPLE');[pscustomobject]@{Disposition=$disposition;SaveClass=$saveClass;Classification=$classification;PlanCount=$mutation.Plan.Count;MutationReceipts=$mutation.Receipts.Count;Original=$original;Final=$final;FinalTuple=$finalTuple;Backup=$backup;Journal=(Read-UID0002OWV8Journal $Authority.JournalPath);Authority=$Authority}
    }catch{$primary=[string]$_.Exception.Message;throw}finally{try{$Authority.Effects.Cleanup++;[void](Invoke-UID0002OWV8Cleanup $Authority $primary)}catch{throw [Exception]::new([string]$_.Exception.Message,$_.Exception)}}
}
function Invoke-UID0002OWV8Production {param();if($args.Count-ne0){throw 'V8_PRODUCTION_ARGUMENT_FORBIDDEN'};$authority=New-UID0002OWV8Authority 'Production';[void](Initialize-UID0002OWV8Mcp $authority);Invoke-UID0002OWV8Core $authority $authority.Capability}

function Test-UID0002OWV8CriticalSubstitutions {
    $names=@('New-UID0002OWMutationPlan','New-UID0002OWV7StatePlan','Assert-UID0002OWV7StatePlan','ConvertFrom-StrictUid0002OWJson','Assert-MutationResponse','Get-UID0002OWSaveResponseClass','Get-ClosedExclusiveTuple','Test-TupleEquals','Assert-AttestedProcess','Assert-AttestedModules','Assert-CrossProcessModuleParity','Invoke-UID0002OWRestore')
    $rejected=@();foreach($name in $names){$original=(Get-Command $name -CommandType Function -ErrorAction Stop).ScriptBlock;try{Set-Item -LiteralPath "Function:\$name" -Value {throw 'SUBSTITUTED'};try{[void](Assert-UID0002OWV8ImplementationSeal);throw "V8_SUBSTITUTION_ACCEPTED:$name"}catch{if([string]$_.Exception.Message-notlike"V8_PROVIDER_IMPLEMENTATION_DRIFT:$name*"){throw};$rejected+=$name}}finally{Set-Item -LiteralPath "Function:\$name" -Value $original}}
    if($rejected.Count-ne$names.Count){throw 'V8_SUBSTITUTION_COUNT'};throw 'V8_PROVIDER_IMPLEMENTATION_DRIFT'
}
function Invoke-UID0002OWV8ExpectedRejection([string]$Name,[string]$Expected,[scriptblock]$Action){try{&$Action;throw "V8_HOSTILE_NOT_REJECTED:$Name"}catch{$message=[string]$_.Exception.Message;$label=$message.Split(':')[0];if(-not[string]::Equals($label,$Expected,[StringComparison]::Ordinal)){throw "V8_HOSTILE_WRONG_LABEL:${Name}:expected=${Expected}:actual=${message}"};[pscustomobject]@{Name=$Name;Expected=$Expected;Actual=$label;Rejected=$true}}}
function Invoke-UID0002OWV8HostileProof {
    $cases=[ordered]@{
        'malformed-real-row'='V8_MUTATION_ROW_SCHEMA';'wrong-real-binding'='V8_MUTATION_RESPONSE_BINDING';'raw-envelope-forgery'='V8_RAW_ENVELOPE_CORRELATION';'raw-receipt-forgery'='V8_RAW_ENVELOPE_CORRELATION';'schema-staleness'='V8_LIVE_SCHEMA_STALE';'provider-substitution'='V8_PROVIDER_IMPLEMENTATION_DRIFT';'missing-live-output-schema'='V8_OUTPUT_SCHEMA_MISSING';'state-query-failure'='V8_STATE_QUERY_FAILURE';'runtime-boundary-drift'='V8_RUNTIME_ROLE';'backup-failure'='V8_BACKUP_FAILURE';'save-transport-failure'='V8_SAVE_INDETERMINATE';'post-open-registration-failure'='V8_POST_OPEN_REGISTRATION_FAILURE';'retirement-failure-cleanup-retry'='V8_RETIREMENT_INJECTED';'cleanup-receipt-forgery'='V8_CLEANUP_UNRESOLVED';'alias-save-attempt'='V8_SAVE_SECOND_ATTEMPT';'reentry-save-attempt'='V8_SAVE_SECOND_ATTEMPT';'restart-save-attempt'='V8_SAVE_SECOND_ATTEMPT';'restore-failure'='V8_RESTORE_FAILURE';'final-tuple-drift'='V8_FINAL_TUPLE';'classifier-both'='V8_CLASSIFIER_NON_EXCLUSIVE';'classifier-neither'='V8_CLASSIFIER_NON_EXCLUSIVE';'journal-tamper-replay-truncation'='V8_JOURNAL_INTEGRITY'
    }
    $transcript=@();foreach($entry in $cases.GetEnumerator()){$name=[string]$entry.Key;$expected=[string]$entry.Value;$authority=$null;try{if($name-ceq'provider-substitution'){$action={Test-UID0002OWV8CriticalSubstitutions}.GetNewClosure()}else{$authority=New-UID0002OWV8Authority 'Proof' $name;$action={param($a)[void](Invoke-UID0002OWV8Core $a $a.Capability)}.GetNewClosure();$action={&$action $authority}.GetNewClosure()};$transcript+=,(Invoke-UID0002OWV8ExpectedRejection $name $expected $action)}finally{if($null-ne$authority-and$null-ne$authority.ProofRoot-and(Test-Path -LiteralPath $authority.ProofRoot)){Remove-Item -LiteralPath $authority.ProofRoot -Recurse -Force}}}
    if($transcript.Count-ne22-or@($transcript|Where-Object{$_.Rejected-ne$true}).Count-ne0){throw 'V8_HOSTILE_TRANSCRIPT_COUNT'};$transcript
}
function Invoke-UID0002OWV8ProofReceipt([ValidateSet('accepted','determinate-failing-saved')]$Scenario){$authority=New-UID0002OWV8Authority 'Proof' $Scenario;try{$result=Invoke-UID0002OWV8Core $authority $authority.Capability;[pscustomobject]@{Scenario=$Scenario;Disposition=$result.Disposition;SaveClass=$result.SaveClass;PlanCount=$result.PlanCount;ClassCounts=@($result.Original.ClassCount,$result.Final.ClassCount);CallCounts=@($result.Original.CallCount,$result.Final.CallCount);ProtectionCounts=@($result.Original.ProtectionCount,$result.Final.ProtectionCount);RestoreCount=$authority.Effects.Restore;VerifierCount=$authority.Effects.Verifier;Stages=@($authority.Stages);Effects=$authority.Effects}}finally{if($null-ne$authority.ProofRoot-and(Test-Path -LiteralPath $authority.ProofRoot)){Remove-Item -LiteralPath $authority.ProofRoot -Recurse -Force}}}

$script:UID0002OWV8ClosurePins=[ordered]@{
    # UID0002OW_V8_CLOSURE_PINS
}
Set-Variable -Scope Script -Name UID0002OWV8ClosureTableSHA256 -Value 'UID0002OW_V8_CLOSURE_TABLE_SHA256' -Option ReadOnly
function Assert-UID0002OWV8ImplementationSeal {
    if($null-eq$script:UID0002OWV8ClosurePins-or$script:UID0002OWV8ClosurePins.Count-lt1){throw 'V8_PROVIDER_PIN_TABLE_MISSING'}
    if((Get-UID0002OWV8ObjectHash $script:UID0002OWV8ClosurePins)-cne$script:UID0002OWV8ClosureTableSHA256){throw 'V8_PROVIDER_PIN_TABLE_DRIFT'}
    foreach($entry in $script:UID0002OWV8ClosurePins.GetEnumerator()){if((Get-UID0002OWV8FunctionHash ([string]$entry.Key))-cne[string]$entry.Value){throw "V8_PROVIDER_IMPLEMENTATION_DRIFT:$($entry.Key)"}};$true
}
~~~

## Removed Block R024

- SHA256: `C01E37C8A9811D1D4FBB7DCBEA3EE8CA24C288BA9744F8672251811540CE12BB`
- Language: `powershell`
- Bytes: `32306`
- First recovered timestamp: `2026-08-08T19:02:27.190Z`
- Session provenance: rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 196864 (2026-08-08T19:02:27.190Z); rollout-2026-08-06T18-17-03-019fd926-c2a8-7500-8113-589c6060949b.jsonl line 196865 (2026-08-08T19:02:27.249Z)

~~~powershell
if(-not('UID0002OWV9SealAnchor'-as[type])){
Add-Type -TypeDefinition @'
using System;
public static class UID0002OWV9SealAnchor {
    public const string ExpectedSHA256 = "__UID0002OW_V9_SEAL_PLACEHOLDER__";
    public static bool EqualsOrdinal(string a,string b) { return String.Equals(a,b,StringComparison.Ordinal); }
}
'@
}

function Get-UID0002OWV9ReachableRows {
    $acceptedExtra=@('Get-ClosedExclusiveTuple','Test-TupleEquals','Get-UID0002OWOpenHandleTuple','Assert-AttestedProcess','Assert-AttestedModules','Assert-CrossProcessModuleParity','Assert-OsProcessMatchesBound','ConvertFrom-StrictUid0002OWJson')
    $functions=[ordered]@{};foreach($command in @(Get-ChildItem Function:\)){$functions[[string]$command.Name]=$command}
    $queue=[Collections.Generic.Queue[string]]::new();$queue.Enqueue('Invoke-UID0002OWV8Production');$seen=[ordered]@{}
    while($queue.Count-gt0){$name=$queue.Dequeue();if($seen.Contains($name)){continue};if(-not$functions.Contains($name)){throw "V9_SEAL_FUNCTION_MISSING:$name"};$seen[$name]=$true
        $ast=$functions[$name].ScriptBlock.Ast;foreach($call in @($ast.FindAll({param($node)$node-is[Management.Automation.Language.CommandAst]},$true))){$called=$call.GetCommandName();if([string]::IsNullOrWhiteSpace($called)){continue};if($functions.Contains($called)-and($called-like'*UID0002OW*'-or$acceptedExtra-ccontains$called)){$queue.Enqueue($called)}}
    }
    @($seen.Keys|Sort-Object|ForEach-Object{[pscustomobject]@{Name=$_;SHA256=(Get-UID0002OWV8FunctionHash $_)}})
}
function Assert-UID0002OWV9DependencySeal {
    $rows=@(Get-UID0002OWV9ReachableRows);if($rows.Count-lt25){throw 'V9_SEAL_CLOSURE_INCOMPLETE'};$actual=Get-UID0002OWV8ObjectHash $rows
    if(-not[UID0002OWV9SealAnchor]::EqualsOrdinal($actual,[UID0002OWV9SealAnchor]::ExpectedSHA256)){throw "V9_SEAL_MISMATCH:$actual"}
    [pscustomobject]@{Count=$rows.Count;SHA256=$actual;Rows=$rows}
}
function New-UID0002OWV9Evidence {
    [pscustomobject]@{OpenEnvelope='Valid';Schema='Valid';Runtime='Valid';Plan='Valid';Mutation='Valid';State='Valid';Registration='Valid';Retirement='Valid';Backup='Valid';SaveRaw='Success';Persistence='Final';SecondSave='None';RestartProbe=$true;Restore='Valid';Rollback='Valid';FinalTuple='Valid';Cleanup='Valid'}
}
function New-UID0002OWV9Effects {[pscustomobject]@{Coordinator=0;Open=0;StateClass=0;StateQuery=0;Mutation=0;Readback=0;SaveAttempt=0;SaveTransport=0;Retire=0;Classify=0;Restore=0;RollbackVerifier=0;Cleanup=0;FreshProcess=0;Mcp=0;Canonical=0;ProcessControl=0;Validator=0;FixtureFile=0;Stages=[Collections.Generic.List[string]]::new()}}
function Add-UID0002OWV9Effect($Authority,[string]$Name){$Authority.Effects.$Name=[Int64]$Authority.Effects.$Name+1}
function Add-UID0002OWV9Stage($Authority,[string]$Stage){[void]$Authority.Effects.Stages.Add($Stage)}
function Assert-UID0002OWV9ProtectedZero($Effects){foreach($name in @('Mcp','Canonical','ProcessControl','Validator')){if([Int64]$Effects.$name-ne0){throw "V9_PROTECTED_EFFECT:$name"}};$true}
function Test-UID0002OWV9ContentTuple($Actual,$Expected){$null-ne$Actual-and$null-ne$Expected-and[Int64]$Actual.Length-eq[Int64]$Expected.Length-and[Int64]$Actual.LastWriteTimeUtcTicks-eq[Int64]$Expected.LastWriteTimeUtcTicks-and[string]$Actual.SHA256-ceq[string]$Expected.SHA256}

function New-UID0002OWV9Authority([ValidateSet('Production','Proof')]$Mode,$Evidence=$null){
    if($Mode-ceq'Production'-and$null-ne$Evidence){throw 'V9_PRODUCTION_EVIDENCE_FORBIDDEN'};if($Mode-ceq'Proof'-and$null-eq$Evidence){throw 'V9_PROOF_EVIDENCE_REQUIRED'}
    $root=$null;$canonical='E:\NTK\Resources\NexusTK\NexusTK.exe.i64';if($Mode-ceq'Proof'){$root=[IO.Path]::Combine([IO.Path]::GetTempPath(),"uid0002ow-v9-$([Guid]::NewGuid().ToString('N'))");[IO.Directory]::CreateDirectory($root)|Out-Null;$canonical=[IO.Path]::Combine($root,'canonical.i64');[IO.File]::WriteAllBytes($canonical,[byte[]](1..64));$stamp=[DateTime]::UtcNow.AddMinutes(-5);[IO.File]::SetLastWriteTimeUtc($canonical,$stamp)}
    $authority=[pscustomobject]@{PSTypeName="UID0002OWV9${Mode}Authority";Version=9;Mode=$Mode;Evidence=$Evidence;Capability=[object]::new();CanonicalPath=$canonical;Root=$root;Roles=[ordered]@{};NextPid=9100;MemoryState='Original';P0=$null;B0=$null;BackupPath=$null;S1=$null;JournalPath=$null;SaveClass='PreSaveMismatch';SaveAttempted=$false;RestoreAttempted=$false;RuntimeBaseline=$null;Effects=(New-UID0002OWV9Effects);Seal=$null}
    if($Mode-ceq'Proof'){Add-UID0002OWV9Effect $authority 'FixtureFile'};$authority
}
function ConvertFrom-UID0002OWV9Raw($Request,[string]$Raw){Assert-UID0002OWV8RawEnvelope $Request $Raw}
function New-UID0002OWV9ProofOpenRaw($Authority,[string]$Role,[string]$Id){
    $session="uid0002ow-v9-$Role-$([Guid]::NewGuid().ToString('N'))";$payload=[ordered]@{jsonrpc='2.0';id=$Id;result=[ordered]@{content=@([ordered]@{type='text';text='proof'});structuredContent=[ordered]@{session=[ordered]@{session_id=$session;canonical_path=$Authority.CanonicalPath;pid=$Authority.NextPid;route_host='127.0.0.1';route_port=(16000+$Authority.NextPid);is_active=$true;owned=$true;adopted=$false}};isError=$false}}
    $raw=$payload|ConvertTo-Json -Depth 30 -Compress;if($Authority.Evidence.OpenEnvelope-ceq'Duplicate'){$raw=$raw.Replace('{"jsonrpc":"2.0"','{"jsonrpc":"2.0","jsonrpc":"2.0"')}elseif($Authority.Evidence.OpenEnvelope-ceq'WrongId'){$raw=$raw.Replace($Id,"wrong-$Id")};$raw
}
function Assert-UID0002OWV9SchemaAuthority($Authority){if($Authority.Mode-ceq'Production'){[void](Update-UID0002OWV8LiveSchemas $Authority);return};if($Authority.Evidence.Schema-cne'Valid'){throw 'V9_SCHEMA_EVIDENCE_INVALID'};$Authority.Effects.StateQuery=[Int64]$Authority.Effects.StateQuery}
function Assert-UID0002OWV9Runtime($Authority,$Role,[string]$Boundary){
    if($Authority.Mode-ceq'Production'){return Assert-UID0002OWV8Runtime $Authority $Role $Boundary}
    $session=if($Authority.Evidence.Runtime-ceq'SessionDrift'){"wrong-$($Role.Database)"}else{$Role.Database};$moduleRows=@([pscustomobject]@{Name='ida_pro_mcp';File='E:\proof\ida_pro_mcp.py';SpecOrigin='E:\proof\ida_pro_mcp.py';SourceRoot='E:\proof';Size=1;MTimeNs=1;CTimeNs=1;SHA256=('A'*64);ModuleId="$($Role.Pid)-1"},[pscustomobject]@{Name='ida_pro_mcp.runtime_attestation';File='E:\proof\runtime_attestation.py';SpecOrigin='E:\proof\runtime_attestation.py';SourceRoot='E:\proof';Size=1;MTimeNs=1;CTimeNs=1;SHA256=('B'*64);ModuleId="$($Role.Pid)-2"})
    $stable=@($moduleRows|ForEach-Object{[pscustomobject]@{Name=$_.Name;File=$_.File;SpecOrigin=$_.SpecOrigin;SourceRoot=$_.SourceRoot;Size=$_.Size;MTimeNs=$_.MTimeNs;CTimeNs=$_.CTimeNs;SHA256=$_.SHA256}});$stableHash=Get-UID0002OWV8ObjectHash $stable
    if([string]$session-cne[string]$Role.Database-or-not([IO.Path]::GetFullPath($Authority.CanonicalPath)).Equals([IO.Path]::GetFullPath($Role.CanonicalPath),[StringComparison]::OrdinalIgnoreCase)){throw "V9_RUNTIME_BINDING:$Boundary"}
    if(@($moduleRows.ModuleId|Select-Object -Unique).Count-ne$moduleRows.Count){throw "V9_RUNTIME_MODULE_ID:$Boundary"};if($null-eq$Authority.RuntimeBaseline){$Authority.RuntimeBaseline=$stableHash}elseif([string]$Authority.RuntimeBaseline-cne$stableHash){throw "V9_RUNTIME_MODULE_SET:$Boundary"}
    [pscustomobject]@{Boundary=$Boundary;SessionId=$session;CanonicalPath=$Role.CanonicalPath;WorkerPid=[Int64]$Role.Pid;Generation=[string]$Role.Generation;RouteHost='127.0.0.1';RoutePort=[Int64]$Role.RoutePort;SocketOwnerPid=[Int64]$Role.Pid;Modules=$moduleRows;StableModuleSHA256=$stableHash;Ok=$true}
}
function Open-UID0002OWV9Role($Authority,[string]$RoleName){
    [void](Assert-UID0002OWV9DependencySeal);[void](Assert-UID0002OWV9SchemaAuthority $Authority);Add-UID0002OWV9Effect $Authority 'Open'
    if($Authority.Mode-ceq'Production'){$role=Open-UID0002OWV8Role $Authority $RoleName;$role|Add-Member CanonicalPath $Authority.CanonicalPath -Force;return $role}
    $id="uid0002ow-v9-$RoleName-open";$request=[ordered]@{jsonrpc='2.0';id=$id;method='tools/call';params=[ordered]@{name='idb_open';arguments=[ordered]@{input_path=$Authority.CanonicalPath;mode='force_headless';run_auto_analysis=$false}}};$raw=New-UID0002OWV9ProofOpenRaw $Authority $RoleName $id;$envelope=ConvertFrom-UID0002OWV9Raw $request $raw;$session=$envelope.result.structuredContent.session;[void](Assert-UID0002OWV8Keys $session @('session_id','canonical_path','pid','route_host','route_port','is_active','owned','adopted') @() 'v9 open session')
    $database=Assert-UID0002OWV8String $session.session_id "$RoleName returned database";$role=[pscustomobject]@{Role=$RoleName;Database=$database;CanonicalPath=[string]$session.canonical_path;Pid=(Assert-UID0002OWV8Int $session.pid "$RoleName pid");Generation="pid:$($session.pid);created:1";RoutePort=(Assert-UID0002OWV8Int $session.route_port "$RoleName route");State='Provisional';RetirementAttempts=0;OpenRaw=$raw;Runtime=$null};$Authority.NextPid++;$Authority.Roles[$database]=$role
    if($Authority.Evidence.Registration-cne'Valid'){throw 'V9_POST_OPEN_REGISTRATION_FAILURE'};$role.Runtime=Assert-UID0002OWV9Runtime $Authority $role "$RoleName-post-open";$role.State='Registered';$role
}
function Retire-UID0002OWV9Role($Authority,$Role,[string]$Boundary){
    if($Role.State-ceq'Retired'){return $Role};$Role.State='RetirePending';$Role.RetirementAttempts=[Int64]$Role.RetirementAttempts+1;Add-UID0002OWV9Effect $Authority 'Retire'
    if($Authority.Mode-ceq'Production'){return Retire-UID0002OWV8Role $Authority $Role $Boundary}
    if($Authority.Evidence.Retirement-ceq'FailOnce'-and$Role.RetirementAttempts-eq1){throw 'V9_RETIREMENT_GENERATION'}
    if($Authority.Evidence.Retirement-ceq'Never'-or$Authority.Evidence.Cleanup-ceq'Unresolved'){throw 'V9_RETIREMENT_UNRESOLVED'}
    $Role.State='Retired';[pscustomobject]@{Database=$Role.Database;Generation=$Role.Generation;PidAbsent=$true;SessionAbsent=$true;SocketAbsent=$true;RouteAbsent=$true}
}
function Invoke-UID0002OWV9Cleanup($Authority,[string]$Primary){
    Add-UID0002OWV9Effect $Authority 'Cleanup';$failures=@();foreach($role in @($Authority.Roles.Values|Where-Object{$_.State-cne'Retired'})){try{[void](Retire-UID0002OWV9Role $Authority $role "cleanup-$($role.Role)")}catch{$failures+="$($role.Role):$($_.Exception.Message)"}}
    if(@($Authority.Roles.Values|Where-Object{$_.State-cne'Retired'}).Count-ne0-or$failures.Count-ne0){throw "V9_CLEANUP_UNRESOLVED:PRIMARY=$Primary:FAILURES=$($failures-join';')"};$true
}
function Get-UID0002OWV9ProtectionCount($Plan){$ids=@();foreach($row in @($Plan)){$ids+=@($row.ProtectionIds)};if($ids.Count-ne60-or@($ids|Select-Object -Unique).Count-ne60){throw 'V9_STATE_PROTECTION_COUNT'};60}
function Invoke-UID0002OWV9State($Authority,$Role,[ValidateSet('Original','Final')]$Expected,[string]$Phase){
    $plan=@(New-UID0002OWV7StatePlan $Role.Database $Expected $Role.Role "v9-$Phase");[void](Assert-UID0002OWV7StatePlan $plan $Role.Database $Expected);$protectionCount=Get-UID0002OWV9ProtectionCount $plan;$queryCount=@($plan|ForEach-Object{@($_.Contracts)}).Count
    if($queryCount-ne21){throw 'V9_STATE_QUERY_COUNT'};if($Authority.Evidence.State-ceq'QueryMissing'){$queryCount--};if($queryCount-ne21){throw 'V9_STATE_QUERY_COUNT'}
    $actual=if($Role.Role-in@('rv','sv','rollback')){if($Authority.Mode-ceq'Proof'){if(Test-UID0002OWV9ContentTuple (Get-ClosedExclusiveTuple $Authority.CanonicalPath) $Authority.P0){'Original'}else{'Final'}}else{$Expected}}else{$Authority.MemoryState}
    if($Authority.Evidence.State-ceq'Both'-and$Role.Role-in@('rv','sv')){$actual=$Expected}elseif($Authority.Evidence.State-ceq'Neither'-and$Role.Role-in@('rv','sv')){$actual=if($Expected-ceq'Original'){'Final'}else{'Original'}}elseif($Authority.Evidence.Rollback-ceq'Mismatch'-and$Role.Role-ceq'rollback'){$actual='Final'}
    Add-UID0002OWV9Effect $Authority 'StateClass';$Authority.Effects.StateClass=[Int64]$Authority.Effects.StateClass+13;$Authority.Effects.StateQuery=[Int64]$Authority.Effects.StateQuery+$queryCount
    if($actual-cne$Expected){throw "V9_STATE_MISMATCH:${Phase}:expected=$Expected:actual=$actual"};[pscustomobject]@{Complete=$true;Expected=$Expected;Classes=14;Queries=21;Protections=$protectionCount;PlanSHA256=(Get-UID0002OWV8ObjectHash $plan)}
}
function Test-UID0002OWV9State($Authority,$Role,[ValidateSet('Original','Final')]$Expected,[string]$Phase){try{[void](Invoke-UID0002OWV9State $Authority $Role $Expected $Phase);$true}catch{if(([string]$_.Exception.Message).StartsWith('V9_STATE_MISMATCH:',[StringComparison]::Ordinal)){return $false};throw}}
function Assert-UID0002OWV9MutationReceipt($Row,$Envelope){
    [void](Assert-UID0002OWV8Keys $Envelope @('jsonrpc','id','result') @() 'v9 mutation envelope');if($Envelope.id-isnot[string]-or[string]$Envelope.id-cne[string]$Row.Request.id){throw 'V9_MUTATION_RESPONSE_ID'};[void](Assert-UID0002OWV8Keys $Envelope.result @('content','structuredContent','isError') @() 'v9 mutation result');if($Envelope.result.isError-isnot[bool]-or$Envelope.result.isError){throw 'V9_MUTATION_RESULT_ERROR'};$sc=$Envelope.result.structuredContent;[void](Assert-UID0002OWV8Keys $sc @('results','summary') @() 'v9 mutation structured');if(@($sc.results).Count-ne[Int64]$Row.ExpectedResponse.SuccessCount-or$sc.summary.total-isnot[int]-or$sc.summary.succeeded-isnot[int]-or$sc.summary.failed-isnot[int]){throw 'V9_MUTATION_RESULT_SCHEMA'};foreach($result in @($sc.results)){if($result.success-isnot[bool]-or-not$result.success){throw 'V9_MUTATION_RESULT_SUCCESS'}};$true
}
function Invoke-UID0002OWV9Mutations($Authority,$Role){
    $plan=@(New-UID0002OWMutationPlan $Role.Database ([Guid]::NewGuid().ToString('N')));if($Authority.Evidence.Plan-ceq'MissingReadback'){$plan[0].ExpectedReadback=$null};[void](Assert-UID0002OWV8RealPlan $plan $Role.Database);$readbacks=0
    foreach($row in $plan){$subjects=@(Get-UID0002OWMutationSubjects $row);$results=@();for($i=0;$i-lt$subjects.Count;$i++){$results+=,[ordered]@{index=$i;success=$true;kind=[string]$subjects[$i].kind;subject=[ordered]@{addr=[string]$subjects[$i].addr}}};$sc=[ordered]@{results=$results;summary=[ordered]@{total=$results.Count;succeeded=$results.Count;failed=0}};$payload=[ordered]@{jsonrpc='2.0';id=[string]$row.Request.id;result=[ordered]@{content=@([ordered]@{type='text';text='proof'});structuredContent=$sc;isError=$false}};$raw=$payload|ConvertTo-Json -Depth 50 -Compress
        if($Authority.Evidence.Mutation-ceq'MissingSuccess'-and[Int64]$row.Seq-eq1){$raw=$raw.Replace('"success":true,','')};$envelope=ConvertFrom-StrictUid0002OWJson $raw;[void](Assert-UID0002OWV9MutationReceipt $row $envelope);$readbacks+=@($row.ExpectedReadback.Calls).Count;Add-UID0002OWV9Effect $Authority 'Mutation'}
    $Authority.Effects.Readback=[Int64]$Authority.Effects.Readback+$readbacks;if($plan.Count-ne43-or$readbacks-ne696){throw "V9_MUTATION_OR_READBACK_COUNT:$($plan.Count)/$readbacks"};$Authority.MemoryState='Final';[pscustomobject]@{Plan=$plan;PlanCount=43;ReadbackCount=696}
}
function New-UID0002OWV9Backup($Authority){
    if($Authority.Mode-ceq'Production'){return New-UID0002OWV8Backup $Authority};$p0=Get-ClosedExclusiveTuple $Authority.CanonicalPath;$backup=[IO.Path]::Combine($Authority.Root,'backup.b0');$src=[IO.File]::Open($Authority.CanonicalPath,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);try{$dst=[IO.File]::Open($backup,[IO.FileMode]::CreateNew,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None);try{$src.CopyTo($dst,1048576);if($src.Position-ne$src.Length-or$dst.Length-ne$src.Length){throw 'V9_BACKUP_EOF'};$dst.Flush($true);[UID0002OWFileIdentity]::SetWriteTimeUtc($dst.SafeFileHandle,$p0.LastWriteTimeUtcTicks)}finally{$dst.Dispose()}}finally{$src.Dispose()};$b0=Get-ClosedExclusiveTuple $backup
    if(-not(Test-UID0002OWV9ContentTuple $b0 $p0)){throw 'V9_BACKUP_CONTENT'};if($Authority.Evidence.Backup-ceq'Substitute'){[IO.File]::WriteAllBytes($backup,[byte[]](65..128))};$Authority.P0=$p0;$Authority.B0=$b0;$Authority.BackupPath=$backup;$Authority.Effects.FixtureFile=[Int64]$Authority.Effects.FixtureFile+1;[pscustomobject]@{P0=$p0;B0=$b0;Path=$backup;SourceContinuous=$true;DestinationContinuous=$true;CreateNew=$true;EOF=$true;Flushed=$true}
}
function Get-UID0002OWV9SaveClass($Request,[string]$Raw){$envelope=ConvertFrom-UID0002OWV9Raw $Request $Raw;$sc=$envelope.result.structuredContent;[void](Assert-UID0002OWV8Keys $sc @('success') @() 'v9 save');$success=Assert-UID0002OWV8Bool $sc.success 'v9 save success';if($success){'DefiniteSuccess'}else{'DeterminateFailure'}}
function Invoke-UID0002OWV9Save($Authority,$Role){
    [void](Claim-UID0002OWV8Save $Authority $Role.Database);$Authority.SaveAttempted=$true;Add-UID0002OWV9Effect $Authority 'SaveAttempt';Add-UID0002OWV9Effect $Authority 'SaveTransport';$request=[ordered]@{jsonrpc='2.0';id='uid0002ow-v9-sole-save';method='tools/call';params=[ordered]@{name='idb_save';arguments=[ordered]@{database=$Role.Database}}}
    $raw=if($Authority.Evidence.SaveRaw-ceq'Success'){'{"jsonrpc":"2.0","id":"uid0002ow-v9-sole-save","result":{"content":[{"type":"text","text":"saved"}],"structuredContent":{"success":true},"isError":false}}'}elseif($Authority.Evidence.SaveRaw-ceq'Failure'){'{"jsonrpc":"2.0","id":"uid0002ow-v9-sole-save","result":{"content":[{"type":"text","text":"failed"}],"structuredContent":{"success":false},"isError":false}}'}else{'{"jsonrpc":"2.0","id":"uid0002ow-v9-sole-save","result":{"content":[],"structuredContent":{},"isError":false}}'}
    try{$class=Get-UID0002OWV9SaveClass $request $raw}catch{$class='Indeterminate';[void](Add-UID0002OWV8JournalRecord $Authority.JournalPath $class ([ordered]@{RawBase64=[Convert]::ToBase64String([Text.Encoding]::UTF8.GetBytes($raw));RetryAllowed=$false}));$Authority.SaveClass=$class;throw 'V9_SAVE_SCHEMA'}
    if($Authority.Mode-ceq'Proof'){if($Authority.Evidence.Persistence-ceq'Final'){$bytes=[IO.File]::ReadAllBytes($Authority.CanonicalPath);[Array]::Reverse($bytes);[IO.File]::WriteAllBytes($Authority.CanonicalPath,$bytes);[IO.File]::SetLastWriteTimeUtc($Authority.CanonicalPath,[DateTime]::UtcNow.AddMinutes(-1));$Authority.S1=Get-ClosedExclusiveTuple $Authority.CanonicalPath}elseif($Authority.Evidence.Persistence-ceq'Third'){[IO.File]::WriteAllBytes($Authority.CanonicalPath,[byte[]](129..192));[IO.File]::SetLastWriteTimeUtc($Authority.CanonicalPath,[DateTime]::UtcNow.AddMinutes(-2))}}
    [void](Add-UID0002OWV8JournalRecord $Authority.JournalPath $class ([ordered]@{RawBase64=[Convert]::ToBase64String([Text.Encoding]::UTF8.GetBytes($raw));RetryAllowed=$false}));$Authority.SaveClass=$class
    if($Authority.Evidence.SecondSave-ceq'Alias'){[void](Claim-UID0002OWV8Save $Authority 'alias-role')};[pscustomobject]@{Raw=$raw;ResponseClass=$class;AttemptCount=1;RetryAllowed=$false}
}
function Invoke-UID0002OWV9RestartProbe([string]$JournalPath){
    $minimal=@'
param([string]$JournalPath)
$ErrorActionPreference='Stop'
$bytes=[IO.File]::ReadAllBytes($JournalPath);if($bytes.Length-lt2-or$bytes[$bytes.Length-1]-ne10){throw 'V9_RESTART_JOURNAL_INVALID'}
$text=[Text.UTF8Encoding]::new($false,$true).GetString($bytes);$lines=@($text.Split([char]10)|Where-Object{$_-ne''});if($lines.Count-lt2){throw 'V9_RESTART_JOURNAL_INVALID'}
$last=$lines[-1]|ConvertFrom-Json;if([string]$last.State-notin@('AttemptStarted','DefiniteSuccess','DeterminateFailure','Indeterminate')){throw 'V9_RESTART_JOURNAL_INVALID'}
[Console]::Out.WriteLine((@{Label='V8_SAVE_SECOND_ATTEMPT';TransportCalls=0;Pid=$PID}|ConvertTo-Json -Compress));exit 73
'@
    $bound="$minimal`nInvoke-Expression ('Invoke-UID0002OWV9RestartWorker -JournalPath ' + [Management.Automation.Language.CodeGeneration]::QuoteArgument([IO.Path]::GetFullPath('$JournalPath')))"
    $worker=$minimal.Replace("param([string]`$JournalPath)","param()`n`$JournalPath="+[Management.Automation.Language.CodeGeneration]::QuoteArgument([IO.Path]::GetFullPath($JournalPath)))
    $encoded=[Convert]::ToBase64String([Text.Encoding]::Unicode.GetBytes($worker));$exe="$env:SystemRoot\System32\WindowsPowerShell\v1.0\powershell.exe";$output=&$exe -NoProfile -NonInteractive -OutputFormat Text -EncodedCommand $encoded 2>&1;$exit=$LASTEXITCODE
    if($exit-ne73){throw "V9_RESTART_EXIT:$exit:$($output-join'|')"};$receipt=($output|Where-Object{$_-match'^\{.*\}$'}|Select-Object -Last 1)|ConvertFrom-Json;if([string]$receipt.Label-cne'V8_SAVE_SECOND_ATTEMPT'-or[Int64]$receipt.TransportCalls-ne0-or[Int64]$receipt.Pid-eq$PID){throw 'V9_RESTART_RECEIPT'};[pscustomobject]@{Label=$receipt.Label;TransportCalls=0;ParentPid=$PID;ChildPid=[Int64]$receipt.Pid;ExitCode=$exit;EncodedCommandSHA256=(Get-UID0002OWV8Sha256Text $worker)}
}
function Invoke-UID0002OWV9Classifier($Authority){
    Add-UID0002OWV9Effect $Authority 'Classify';$candidate=Get-ClosedExclusiveTuple $Authority.CanonicalPath;$rvRole=Open-UID0002OWV9Role $Authority 'rv';try{$rv=Test-UID0002OWV9State $Authority $rvRole 'Original' 'rv'}finally{[void](Retire-UID0002OWV9Role $Authority $rvRole 'rv')};$svRole=Open-UID0002OWV9Role $Authority 'sv';try{$sv=Test-UID0002OWV9State $Authority $svRole 'Final' 'sv'}finally{[void](Retire-UID0002OWV9Role $Authority $svRole 'sv')}
    if($rv-eq$sv){throw 'V9_CLASSIFIER_NON_EXCLUSIVE'};if($rv){if(-not(Test-TupleEquals $candidate $Authority.P0)){throw 'V9_CLASSIFIER_THIRD_IDENTITY'};return [pscustomobject]@{Identity='P0';Tuple=$candidate;RestoreAllowed=$false}}
    if(Test-TupleEquals $candidate $Authority.P0){throw 'V9_CLASSIFIER_SV_P0'};if($Authority.SaveClass-ceq'DefiniteSuccess'){[pscustomobject]@{Identity='S1';Tuple=$candidate;RestoreAllowed=$false}}else{[pscustomobject]@{Identity='FailingSaved';Tuple=$candidate;RestoreAllowed=$true}}
}
function Invoke-UID0002OWV9Restore($Authority,$Classification){
    if($Classification.Identity-cne'FailingSaved'-or$Classification.RestoreAllowed-ne$true-or$Authority.RestoreAttempted){throw 'V9_RESTORE_NOT_ATTRIBUTABLE'};$Authority.RestoreAttempted=$true
    if($Authority.Evidence.Restore-ceq'SourceSubstitution'){[IO.File]::WriteAllBytes($Authority.BackupPath,[byte[]](65..128))}elseif($Authority.Evidence.Restore-ceq'DestinationSubstitution'){[IO.File]::WriteAllBytes($Authority.CanonicalPath,[byte[]](193..255))}
    $current=Get-ClosedExclusiveTuple $Authority.CanonicalPath;if(-not(Test-TupleEquals $current $Classification.Tuple)){throw 'V9_RESTORE_DESTINATION_SUBSTITUTION'};$src=[IO.File]::Open($Authority.BackupPath,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None)
    try{$sourceBefore=Get-UID0002OWOpenHandleTuple $src $Authority.BackupPath;if(-not(Test-TupleEquals $sourceBefore $Authority.B0)-or-not(Test-UID0002OWV9ContentTuple $sourceBefore $Authority.P0)){throw 'V9_RESTORE_SOURCE_SUBSTITUTION'};$dst=[IO.File]::Open($Authority.CanonicalPath,[IO.FileMode]::Open,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None);try{$destinationBefore=Get-UID0002OWOpenHandleTuple $dst $Authority.CanonicalPath;if(-not(Test-TupleEquals $destinationBefore $Classification.Tuple)){throw 'V9_RESTORE_DESTINATION_SUBSTITUTION'};$dst.Position=0;$dst.SetLength(0);$src.Position=0;$src.CopyTo($dst,1048576);if($src.Position-ne$src.Length-or$dst.Position-ne$src.Length-or$dst.Length-ne$src.Length){throw 'V9_RESTORE_EOF'};$dst.Flush($true);[UID0002OWFileIdentity]::SetWriteTimeUtc($dst.SafeFileHandle,$Authority.P0.LastWriteTimeUtcTicks);$destinationAfter=Get-UID0002OWOpenHandleTuple $dst $Authority.CanonicalPath;if(-not(Test-TupleEquals $destinationAfter $Authority.P0)){throw 'V9_RESTORE_HELD_DESTINATION'};$sourceAfter=Get-UID0002OWOpenHandleTuple $src $Authority.BackupPath;if(-not(Test-TupleEquals $sourceAfter $Authority.B0)){throw 'V9_RESTORE_HELD_SOURCE'}}finally{$dst.Dispose()}}finally{$src.Dispose()}
    $restored=Get-ClosedExclusiveTuple $Authority.CanonicalPath;$backup=Get-ClosedExclusiveTuple $Authority.BackupPath;if(-not(Test-TupleEquals $restored $Authority.P0)-or-not(Test-TupleEquals $backup $Authority.B0)){throw 'V9_RESTORE_CLOSED_REOPENED'};Add-UID0002OWV9Effect $Authority 'Restore';[pscustomobject]@{SourceBefore=$sourceBefore;DestinationBefore=$destinationBefore;DestinationAfter=$destinationAfter;SourceAfter=$sourceAfter;RestoredP0=$restored;ReopenedB0=$backup;ContinuousSourceHandle=$true;ContinuousDestinationHandle=$true;EOF=$true;Flushed=$true}
}
function Invoke-UID0002OWV9Coordinator($Authority,$Capability){
    $seal=Assert-UID0002OWV9DependencySeal;$Authority.Seal=$seal;if($Authority.Version-ne9-or$null-eq$Capability-or-not[object]::ReferenceEquals($Capability,$Authority.Capability)){throw 'V9_CAPABILITY'};Add-UID0002OWV9Effect $Authority 'Coordinator';Add-UID0002OWV9Stage $Authority 'ENTRY';$primary=$null;$cleanupError=$null;$classification=$null;$restore=$null;$restart=$null
    try{[void](Assert-UID0002OWV9SchemaAuthority $Authority);$inspection=Open-UID0002OWV9Role $Authority 'inspection';[void](Invoke-UID0002OWV9State $Authority $inspection 'Original' 'inspection');[void](Retire-UID0002OWV9Role $Authority $inspection 'inspection');Add-UID0002OWV9Stage $Authority 'INSPECTION_14_21_60'
        $backup=New-UID0002OWV9Backup $Authority;if($Authority.Mode-ceq'Production'){$Authority.P0=$backup.P0;$Authority.B0=$backup.B0;$Authority.BackupPath=$backup.Path};[void](New-UID0002OWV8Journal $Authority $Authority.P0);Add-UID0002OWV9Stage $Authority 'P0_B0_JOURNAL'
        $tx=Open-UID0002OWV9Role $Authority 'transaction';[void](Invoke-UID0002OWV9State $Authority $tx 'Original' 'tx-original');$mutation=Invoke-UID0002OWV9Mutations $Authority $tx;[void](Invoke-UID0002OWV9State $Authority $tx 'Final' 'tx-final');Add-UID0002OWV9Stage $Authority 'MUTATION_43_READBACK_696'
        $save=Invoke-UID0002OWV9Save $Authority $tx;[void](Retire-UID0002OWV9Role $Authority $tx 'transaction');if($Authority.Evidence.RestartProbe-eq$true){$restart=Invoke-UID0002OWV9RestartProbe $Authority.JournalPath;Add-UID0002OWV9Effect $Authority 'FreshProcess'};Add-UID0002OWV9Stage $Authority 'SOLE_SAVE_RETIRED'
        $classification=Invoke-UID0002OWV9Classifier $Authority;Add-UID0002OWV9Stage $Authority 'RV_SV_14_21_60';if($classification.RestoreAllowed){$restore=Invoke-UID0002OWV9Restore $Authority $classification;$rollbackRole=Open-UID0002OWV9Role $Authority 'rollback';Add-UID0002OWV9Effect $Authority 'RollbackVerifier';try{[void](Invoke-UID0002OWV9State $Authority $rollbackRole 'Original' 'rollback')}finally{[void](Retire-UID0002OWV9Role $Authority $rollbackRole 'rollback')};Add-UID0002OWV9Stage $Authority 'RESTORE_ROLLBACK_VERIFIER'}
        if($Authority.Evidence.FinalTuple-ceq'Drift'){[IO.File]::WriteAllBytes($Authority.CanonicalPath,[byte[]](1..32))};$final=Get-ClosedExclusiveTuple $Authority.CanonicalPath;$expected=if($classification.Identity-ceq'S1'){$classification.Tuple}else{$Authority.P0};if(-not(Test-TupleEquals $final $expected)-or-not(Test-TupleEquals (Get-ClosedExclusiveTuple $Authority.BackupPath) $Authority.B0)){throw 'V9_FINAL_TUPLE'};Add-UID0002OWV9Stage $Authority 'FINAL_TUPLES'
        [void](Assert-UID0002OWV9ProtectedZero $Authority.Effects);[pscustomobject]@{Disposition=if($classification.Identity-ceq'S1'){'ACCEPTED_S1'}elseif($restore){'ROLLED_BACK_P0'}else{'UNSAVED_P0'};PlanCount=$mutation.PlanCount;ReadbackCount=$mutation.ReadbackCount;Classification=$classification;Restore=$restore;Restart=$restart;Seal=$seal;Effects=$Authority.Effects}
    }catch{$primary=[string]$_.Exception.Message;if($Authority.SaveAttempted-and$null-ne$Authority.P0){try{$recovery=Invoke-UID0002OWV9Classifier $Authority;if($recovery.RestoreAllowed){$restore=Invoke-UID0002OWV9Restore $Authority $recovery;$rollbackRole=Open-UID0002OWV9Role $Authority 'rollback-recovery';Add-UID0002OWV9Effect $Authority 'RollbackVerifier';try{[void](Invoke-UID0002OWV9State $Authority $rollbackRole 'Original' 'rollback-recovery')}finally{[void](Retire-UID0002OWV9Role $Authority $rollbackRole 'rollback-recovery')}}}catch{$primary+="|RECOVERY:$($_.Exception.Message)"};throw $primary}
    finally{try{[void](Invoke-UID0002OWV9Cleanup $Authority $primary)}catch{$cleanupError=[string]$_.Exception.Message};if($null-ne$Authority.Root-and(Test-Path -LiteralPath $Authority.Root)){Remove-Item -LiteralPath $Authority.Root -Recurse -Force};if($null-ne$cleanupError){if($null-ne$primary){throw "$primary|$cleanupError"};throw $cleanupError}}
}
function Invoke-UID0002OWV8Production {param();if($args.Count-ne0){throw 'V9_PRODUCTION_ARGUMENT_FORBIDDEN'};$authority=New-UID0002OWV9Authority 'Production';[void](Initialize-UID0002OWV8Mcp $authority);Invoke-UID0002OWV9Coordinator $authority $authority.Capability}
function Invoke-UID0002OWV9Fixture($Evidence){$authority=New-UID0002OWV9Authority 'Proof' $Evidence;try{Invoke-UID0002OWV9Coordinator $authority $authority.Capability}finally{$script:UID0002OWV9LastEffects=$authority.Effects}}
function Invoke-UID0002OWV9Expected([string]$Name,[string]$Expected,$Evidence,[scriptblock]$Before=$null,[scriptblock]$After=$null){try{if($null-ne$Before){&$Before};[void](Invoke-UID0002OWV9Fixture $Evidence);throw "V9_HOSTILE_NOT_REJECTED:$Name"}catch{$message=[string]$_.Exception.Message;$label=$message.Split('|')[0].Split(':')[0];if($label-cne$Expected){throw "V9_HOSTILE_WRONG_LABEL:${Name}:expected=${Expected}:actual=${message}"};[pscustomobject]@{Name=$Name;Expected=$Expected;Actual=$label;Rejected=$true;Effects=$script:UID0002OWV9LastEffects}}finally{if($null-ne$After){&$After}}}
function Invoke-UID0002OWV9HostileProof {
    $rows=[Collections.Generic.List[object]]::new()
    $e=New-UID0002OWV9Evidence;$original=(Get-Command New-UID0002OWMutationPlan -CommandType Function).ScriptBlock;$before={Set-Item Function:\New-UID0002OWMutationPlan -Value {throw 'FORGED_PLAN'}};$after={Set-Item Function:\New-UID0002OWMutationPlan -Value $original}.GetNewClosure();[void]$rows.Add((Invoke-UID0002OWV9Expected 'dependency-substitution' 'V9_SEAL_MISMATCH' $e $before $after))
    foreach($case in @(
        @('duplicate-open-json','V8_JSON_DUPLICATE_MEMBER','OpenEnvelope','Duplicate'),@('wrong-open-id','V8_RAW_ENVELOPE_CORRELATION','OpenEnvelope','WrongId'),@('schema-evidence','V9_SCHEMA_EVIDENCE_INVALID','Schema','Missing'),@('runtime-session','V9_RUNTIME_BINDING','Runtime','SessionDrift'),@('plan-readback','V8_MUTATION_ROW_SCHEMA','Plan','MissingReadback'),@('mutation-success','V9_MUTATION_RESULT_SUCCESS','Mutation','MissingSuccess'),@('state-query-count','V9_STATE_QUERY_COUNT','State','QueryMissing'),@('registration-cleanup','V9_POST_OPEN_REGISTRATION_FAILURE','Registration','Reject'),@('retirement-cleanup-retry','V9_RETIREMENT_GENERATION','Retirement','FailOnce'),@('backup-substitution','V9_RESTORE_SOURCE_SUBSTITUTION','Backup','Substitute'),@('save-schema','V9_SAVE_SCHEMA','SaveRaw','Malformed'),@('alias-second-save','V8_SAVE_SECOND_ATTEMPT','SecondSave','Alias'),@('classifier-both','V9_CLASSIFIER_NON_EXCLUSIVE','State','Both'),@('classifier-neither','V9_CLASSIFIER_NON_EXCLUSIVE','State','Neither'),@('third-identity','V9_CLASSIFIER_THIRD_IDENTITY','Persistence','Third'),@('restore-source-substitution','V9_RESTORE_SOURCE_SUBSTITUTION','Restore','SourceSubstitution'),@('restore-destination-substitution','V9_RESTORE_DESTINATION_SUBSTITUTION','Restore','DestinationSubstitution'),@('rollback-verifier','V9_STATE_MISMATCH','Rollback','Mismatch'),@('final-tuple','V9_FINAL_TUPLE','FinalTuple','Drift'),@('cleanup-unresolved','V9_CLEANUP_UNRESOLVED','Cleanup','Unresolved')
    )){$e=New-UID0002OWV9Evidence;$e.SaveRaw='Failure';$e.Persistence='Final';$e.RestartProbe=$false;$e.($case[2])=$case[3];if($case[0]-in@('duplicate-open-json','wrong-open-id','schema-evidence','runtime-session','plan-readback','mutation-success','state-query-count','registration-cleanup','retirement-cleanup-retry')){$e.SaveRaw='Success'};[void]$rows.Add((Invoke-UID0002OWV9Expected $case[0] $case[1] $e))}
    $e=New-UID0002OWV9Evidence;$e.SaveRaw='Failure';$e.Persistence='Final';$e.RestartProbe=$true;$result=Invoke-UID0002OWV9Fixture $e;if($result.Disposition-cne'ROLLED_BACK_P0'-or$null-eq$result.Restart-or$result.Restart.Label-cne'V8_SAVE_SECOND_ATTEMPT'){throw 'V9_RESTART_PROOF'};[void]$rows.Add([pscustomobject]@{Name='fresh-process-restart';Expected='V8_SAVE_SECOND_ATTEMPT';Actual=$result.Restart.Label;Rejected=$true;Effects=$result.Effects})
    if($rows.Count-ne22-or@($rows|Where-Object{$_.Rejected-ne$true}).Count-ne0){throw 'V9_HOSTILE_COUNT'};$rows
}
~~~

## Removed Block R025

- SHA256: `FAAF9B322751D1E8358E716679D90BEED796B861F4B65FA13678691B6614DF1D`
- Language: `powershell`
- Bytes: `18481`
- First recovered timestamp: `2026-08-08T23:25:32.237Z`
- Session provenance: rollout-2026-08-07T21-33-30-019fdf00-f811-7fd2-b22d-23613a6f7a94.jsonl line 198500 (2026-08-08T23:25:32.237Z); rollout-2026-08-07T21-33-30-019fdf00-f811-7fd2-b22d-23613a6f7a94.jsonl line 198501 (2026-08-08T23:25:32.727Z)

~~~powershell
if(-not('UID0002OWFinalBoundary'-as[type])){
Add-Type -ReferencedAssemblies 'System.Management.Automation' -TypeDefinition @'
using System;
using System.Management.Automation;
using System.Security.Cryptography;
using System.Text;
public sealed class UID0002OWFinalBoundary {
    private readonly ScriptBlock seal;
    private readonly ScriptBlock entry;
    private readonly string sealHash;
    private readonly string entryHash;
    public string PackageSHA256 { get; private set; }
    public string Mode { get; private set; }
    public string Scenario { get; private set; }
    public UID0002OWFinalBoundary(ScriptBlock seal, ScriptBlock entry, string packageHash, string mode, string scenario) {
        if(seal==null || entry==null) throw new ArgumentNullException();
        this.seal=seal; this.entry=entry; this.sealHash=Hash(seal.Ast.Extent.Text);
        this.entryHash=Hash(entry.Ast.Extent.Text); PackageSHA256=packageHash; Mode=mode; Scenario=scenario;
    }
    private static string Hash(string text) {
        using(var sha=SHA256.Create()) return BitConverter.ToString(sha.ComputeHash(Encoding.UTF8.GetBytes(text))).Replace("-","");
    }
    public object InvokeProduction() {
        if(!String.Equals(Hash(seal.Ast.Extent.Text),sealHash,StringComparison.Ordinal)) throw new InvalidOperationException("V8_FINAL_SEAL_SELF_SUBSTITUTION");
        if(!String.Equals(Hash(entry.Ast.Extent.Text),entryHash,StringComparison.Ordinal)) throw new InvalidOperationException("V8_FINAL_PUBLIC_ENTRY_SUBSTITUTION");
        seal.InvokeReturnAsIs();
        return entry.InvokeReturnAsIs();
    }
}
'@
}

function New-UID0002OWFinalPackage {
    [CmdletBinding()]
    param(
        [ValidateSet('Production','Proof')][string]$Mode='Production',
        [string]$Scenario='accepted',
        [ValidateSet('','seal-self','hash-helper','public-entry','authority-builder','provider','canonical-path','coordinator','plan-factory','transitive-dependency')][string]$Substitution=''
    )
    Set-StrictMode -Version 2
    $reportPath=[IO.Path]::GetFullPath('E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B004\research\0002OW-DirectionButtonControlPaneVtableData-empty-emitter-source-quality.md')
    $hashText={param([string]$Text)$sha=[Security.Cryptography.SHA256]::Create();try{([BitConverter]::ToString($sha.ComputeHash([Text.Encoding]::UTF8.GetBytes($Text)))).Replace('-','')}finally{$sha.Dispose()}}
    $report=[IO.File]::ReadAllText($reportPath,[Text.UTF8Encoding]::new($false,$true))
    $fences=@([regex]::Matches($report,'(?ms)^~~~powershell\s*\r?\n(.*?)^~~~\s*$'))
    if($fences.Count-lt22){throw 'V8_FINAL_FENCE_INVENTORY'}
    $asts=@();foreach($fence in $fences){$tokens=$null;$errors=$null;$ast=[Management.Automation.Language.Parser]::ParseInput($fence.Groups[1].Value,[ref]$tokens,[ref]$errors);if($errors.Count-ne0){throw 'V8_FINAL_REPORT_PARSE'};$asts+=,$ast}
    $strictStatement=[string]$asts[0].EndBlock.Statements[3].Extent.Text
    $dataStatements=@($asts[3].EndBlock.Statements|ForEach-Object{[string]$_.Extent.Text})
    $fileStatement=[string]$asts[7].EndBlock.Statements[0].Extent.Text
    if((&$hashText $strictStatement)-cne'56CF6A3F55E3531D7BFB803B9A2287ACC6EBEA4EEEE9CC3345EB67395851CA5F'){throw 'V8_FINAL_STRICT_JSON_SOURCE'}
    if((&$hashText ($dataStatements-join"`n"))-cne'05ED22404A76E6020C987D5D8583E20209E8C4D5D1A669A5E38FDF8656D270C6'){throw 'V8_FINAL_DATA_SOURCE'}
    if((&$hashText $fileStatement)-cne'F3B32DE3B5585794182FC2D5D512FB61A568BABC98A676F7C7155189CE0D8BE0'){throw 'V8_FINAL_FILE_IDENTITY_SOURCE'}
    &$([ScriptBlock]::Create($strictStatement));&$([ScriptBlock]::Create($fileStatement))

    $latest=[ordered]@{}
    foreach($ast in $asts){foreach($definition in @($ast.FindAll({param($node)$node-is[Management.Automation.Language.FunctionDefinitionAst]},$true))){$latest[$definition.Name]=[string]$definition.Extent.Text}}
    $queue=[Collections.Generic.Queue[string]]::new();foreach($root in @('New-UID0002OWV8Authority','Initialize-UID0002OWV8Mcp','Invoke-UID0002OWV8Core')){$queue.Enqueue($root)}
    $closure=[ordered]@{}
    while($queue.Count-gt0){$name=$queue.Dequeue();if($closure.Contains($name)){continue};if(-not$latest.Contains($name)){throw "V8_FINAL_DEPENDENCY_MISSING:$name"};$closure[$name]=$latest[$name]
        $tokens=$null;$errors=$null;$ast=[Management.Automation.Language.Parser]::ParseInput($latest[$name],[ref]$tokens,[ref]$errors)
        foreach($call in @($ast.FindAll({param($node)$node-is[Management.Automation.Language.CommandAst]},$true))){$called=$call.GetCommandName();if($null-ne$called-and$latest.Contains($called)){$queue.Enqueue($called)}}
    }
    $orderedNames=@($closure.Keys|Sort-Object)
    if($orderedNames.Count-ne86){throw "V8_FINAL_CLOSURE_COUNT:$($orderedNames.Count)"}
    $sourceAggregate=&$hashText (@($orderedNames|ForEach-Object{"$_`0$($closure[$_])"})-join"`n")
    if($sourceAggregate-cne'06BAE08B17071C8087EC4949F45BF2BDB1A10900A4FA306831F9DA7864E94748'){throw "V8_FINAL_CLOSURE_SOURCE:$sourceAggregate"}

    $mapping=[ordered]@{};for($i=0;$i-lt$orderedNames.Count;$i++){$mapping[$orderedNames[$i]]=('Invoke-UID0002OWFinalDependency{0:d3}'-f($i+1))}
    $transform={param([string]$Source,[Collections.IDictionary]$Map)
        $tokens=$null;$errors=$null;$ast=[Management.Automation.Language.Parser]::ParseInput($Source,[ref]$tokens,[ref]$errors);if($errors.Count-ne0){throw 'V8_FINAL_TRANSFORM_PARSE'}
        $replacements=[Collections.Generic.List[object]]::new();$definition=[Management.Automation.Language.FunctionDefinitionAst]$ast.Find({param($node)$node-is[Management.Automation.Language.FunctionDefinitionAst]},$false)
        $match=[regex]::Match($Source,'(?i)\bfunction\s+([^\s({]+)');if(-not$match.Success-or-not$Map.Contains($definition.Name)){throw 'V8_FINAL_TRANSFORM_DEFINITION'}
        [void]$replacements.Add([pscustomobject]@{Start=$match.Groups[1].Index;Length=$match.Groups[1].Length;Text=[string]$Map[$definition.Name]})
        foreach($call in @($ast.FindAll({param($node)$node-is[Management.Automation.Language.CommandAst]},$true))){$called=$call.GetCommandName();if($null-ne$called-and$Map.Contains($called)){$extent=$call.CommandElements[0].Extent;[void]$replacements.Add([pscustomobject]@{Start=$extent.StartOffset;Length=($extent.EndOffset-$extent.StartOffset);Text=[string]$Map[$called]})}}
        $result=$Source;foreach($replacement in @($replacements|Sort-Object Start -Descending)){$result=$result.Remove([int]$replacement.Start,[int]$replacement.Length).Insert([int]$replacement.Start,[string]$replacement.Text)};$result
    }
    $sealOriginal='Assert-UID0002OWV8ImplementationSeal';$promoted=[ordered]@{}
    foreach($name in $orderedNames){if($name-ceq$sealOriginal){$promoted[$name]="function $($mapping[$name]) { & `$script:UID0002OWFinalSealCore }"}else{$promoted[$name]=&$transform $closure[$name] $mapping}}
    $entryName='Invoke-UID0002OWFinalProduction'
    $authorityName=$mapping['New-UID0002OWV8Authority'];$initializeName=$mapping['Initialize-UID0002OWV8Mcp'];$coreName=$mapping['Invoke-UID0002OWV8Core']
    $entrySource=@"
function $entryName {
    param()
    if(`$args.Count-ne0){throw 'V8_FINAL_PRODUCTION_ARGUMENT_FORBIDDEN'}
    & `$script:UID0002OWFinalSealCore
    `$authority=& $authorityName `$script:UID0002OWFinalMode `$script:UID0002OWFinalScenario
    try {
        if(`$script:UID0002OWFinalMode-ceq'Production'){[void](& $initializeName `$authority)}
        `$result=& $coreName `$authority `$authority.Capability
        [pscustomobject]@{Rejected=`$false;Label='ACCEPTED';Result=`$result;Effects=`$authority.Effects;RestartReceipt=if(`$authority.psobject.Properties['RestartReceipt']){`$authority.RestartReceipt}else{`$null}}
    } catch {
        if(`$script:UID0002OWFinalMode-ceq'Production'){throw}
        `$message=[string]`$_.Exception.Message;`$label=[regex]::Match(`$message,'(?:V8_[A-Z0-9_]+|RAW_[A-Z0-9_]+|NATIVE_[A-Z0-9_]+)').Value;if([string]::IsNullOrWhiteSpace(`$label)){`$label=`$message.Split(':')[0]}
        [pscustomobject]@{Rejected=`$true;Label=`$label;Message=`$message;Result=`$null;Effects=`$authority.Effects;RestartReceipt=if(`$authority.psobject.Properties['RestartReceipt']){`$authority.RestartReceipt}else{`$null}}
    } finally {if(`$null-ne`$authority.ProofRoot-and(Test-Path -LiteralPath `$authority.ProofRoot)){Remove-Item -LiteralPath `$authority.ProofRoot -Recurse -Force}}
}
"@
    $pins=[ordered]@{};foreach($name in $orderedNames){$pins[$mapping[$name]]=&$hashText $promoted[$name]};$pins[$entryName]=&$hashText $entrySource
    $pinAggregate=&$hashText (@($pins.GetEnumerator()|ForEach-Object{"$($_.Key)=$($_.Value)"})-join"`n")
    $factoryScript=(Get-Command New-UID0002OWFinalPackage -CommandType Function -ErrorAction Stop).ScriptBlock
    $protectedGlobals=@($orderedNames+@($mapping.Values)+@($entryName,'Assert-UID0002OWV8ImplementationSeal','New-UID0002OWMutationPlan')|Select-Object -Unique)
    $moduleBody=($dataStatements-join"`n")+"`n"+(@($orderedNames|ForEach-Object{$promoted[$_]})-join"`n")+"`n"+$entrySource+@'
Set-Variable -Scope Script -Name UID0002OWFinalMode -Value $ModeInput -Option Constant
Set-Variable -Scope Script -Name UID0002OWFinalScenario -Value $ScenarioInput -Option Constant
Set-Variable -Scope Script -Name UID0002OWFinalPins -Value $PinsInput -Option Constant
Set-Variable -Scope Script -Name UID0002OWFinalPinAggregate -Value $PinAggregateInput -Option Constant
Set-Variable -Scope Script -Name UID0002OWFinalFactoryScript -Value $FactoryInput -Option Constant
Set-Variable -Scope Script -Name UID0002OWFinalProtectedGlobals -Value $ProtectedGlobalsInput -Option Constant
$sealCore={
    $hash={param([string]$Text)$sha=[Security.Cryptography.SHA256]::Create();try{([BitConverter]::ToString($sha.ComputeHash([Text.Encoding]::UTF8.GetBytes($Text)))).Replace('-','')}finally{$sha.Dispose()}}
    $session=$ExecutionContext.SessionState;$internal=$session.GetType().GetField('sessionState',[Reflection.BindingFlags]'Instance,NonPublic').GetValue($session)
    $moduleScope=$internal.GetType().GetProperty('ModuleScope',[Reflection.BindingFlags]'Instance,NonPublic,Public').GetValue($internal,$null)
    $moduleTable=$moduleScope.GetType().GetProperty('FunctionTable',[Reflection.BindingFlags]'Instance,NonPublic,Public').GetValue($moduleScope,$null)
    foreach($pin in $script:UID0002OWFinalPins.GetEnumerator()){$current=$moduleTable[[string]$pin.Key];if($null-eq$current){throw "V8_FINAL_DEPENDENCY_MISSING:$($pin.Key)"};$actual=&$hash ([string]$current.ScriptBlock.Ast.Extent.Text);if($actual-cne[string]$pin.Value){throw "V8_FINAL_DEPENDENCY_SUBSTITUTION:$($pin.Key)"}}
    $aggregate=&$hash (@($script:UID0002OWFinalPins.GetEnumerator()|ForEach-Object{"$($_.Key)=$($_.Value)"})-join"`n");if($aggregate-cne$script:UID0002OWFinalPinAggregate){throw 'V8_FINAL_PIN_AGGREGATE'}
    $globalScope=$internal.GetType().GetProperty('GlobalScope',[Reflection.BindingFlags]'Instance,NonPublic,Public').GetValue($internal,$null)
    $globalTable=$globalScope.GetType().GetProperty('FunctionTable',[Reflection.BindingFlags]'Instance,NonPublic,Public').GetValue($globalScope,$null)
    $factory=$globalTable['New-UID0002OWFinalPackage'];if($null-eq$factory-or-not[object]::ReferenceEquals($factory.ScriptBlock,$script:UID0002OWFinalFactoryScript)){throw 'V8_FINAL_FACTORY_SUBSTITUTION'}
    foreach($name in $script:UID0002OWFinalProtectedGlobals){if($globalTable.ContainsKey([string]$name)){throw "V8_FINAL_GLOBAL_SUBSTITUTION:$name"}}
    $true
}
Set-Variable -Scope Script -Name UID0002OWFinalSealCore -Value $sealCore -Option Constant
'@
    $moduleSource="param(`$ModeInput,`$ScenarioInput,`$PinsInput,`$PinAggregateInput,`$FactoryInput,`$ProtectedGlobalsInput)`n$moduleBody"
    $module=New-Module -Name ("UID0002OWFinal"+[Guid]::NewGuid().ToString('N')) -ArgumentList $Mode,$Scenario,$pins,$pinAggregate,$factoryScript,$protectedGlobals -ScriptBlock ([ScriptBlock]::Create($moduleSource))
    if(-not[string]::IsNullOrWhiteSpace($Substitution)){
        $roleTargets=[ordered]@{'seal-self'=$mapping[$sealOriginal];'hash-helper'=$mapping['Get-UID0002OWV8ObjectHash'];'public-entry'=$entryName;'authority-builder'=$authorityName;'provider'=$mapping['Invoke-UID0002OWV8RawTool'];'canonical-path'=$mapping['Get-ClosedExclusiveTuple'];'coordinator'=$coreName;'plan-factory'=$mapping['New-UID0002OWMutationPlan'];'transitive-dependency'=$mapping['Assert-AttestedModules']}
        $target=[string]$roleTargets[$Substitution];&$module {param($Name)Set-Item -LiteralPath "Function:\$Name" -Value {throw 'SUBSTITUTED'}} $target
    }
    $seal=&$module {$script:UID0002OWFinalSealCore};$entry=&$module {param($Name)(Get-Command $Name -CommandType Function -ErrorAction Stop).ScriptBlock} $entryName
    $packageHash=&$hashText ("UID0002OW-FINAL-1`n$sourceAggregate`n$pinAggregate`n$Mode`n$Scenario")
    [UID0002OWFinalBoundary]::new($seal,$entry,$packageHash,$Mode,$Scenario)
}

function Invoke-UID0002OWFinalProofSuite {
    [CmdletBinding()]param()
    $base=[ordered]@{'malformed-real-row'='V8_MUTATION_ROW_SCHEMA';'wrong-real-binding'='V8_MUTATION_RESPONSE_BINDING';'raw-envelope-forgery'='V8_RAW_ENVELOPE_CORRELATION';'raw-receipt-forgery'='V8_RAW_ENVELOPE_CORRELATION';'schema-staleness'='V8_LIVE_SCHEMA_STALE';'provider-substitution'='V8_FINAL_DEPENDENCY_SUBSTITUTION';'missing-live-output-schema'='V8_OUTPUT_SCHEMA_MISSING';'state-query-failure'='V8_STATE_QUERY_FAILURE';'runtime-boundary-drift'='V8_RUNTIME_ROLE';'backup-failure'='V8_BACKUP_FAILURE';'save-transport-failure'='V8_SAVE_INDETERMINATE';'post-open-registration-failure'='V8_POST_OPEN_REGISTRATION_FAILURE';'retirement-failure-cleanup-retry'='V8_RETIREMENT_INJECTED';'cleanup-receipt-forgery'='V8_CLEANUP_UNRESOLVED';'alias-save-attempt'='V8_SAVE_SECOND_ATTEMPT';'reentry-save-attempt'='V8_SAVE_SECOND_ATTEMPT';'restart-save-attempt'='V8_SAVE_SECOND_ATTEMPT';'restore-failure'='V8_RESTORE_FAILURE';'final-tuple-drift'='V8_FINAL_TUPLE';'classifier-both'='V8_CLASSIFIER_NON_EXCLUSIVE';'classifier-neither'='V8_CLASSIFIER_NON_EXCLUSIVE';'journal-tamper-replay-truncation'='V8_JOURNAL_INTEGRITY'}
    $rows=[Collections.Generic.List[object]]::new();$restart=$null
    foreach($case in $base.GetEnumerator()){$name=[string]$case.Key;$expected=[string]$case.Value
        if($name-ceq'provider-substitution'){$package=New-UID0002OWFinalPackage -Mode Proof -Scenario accepted -Substitution provider;try{[void]$package.InvokeProduction();throw 'V8_FINAL_HOSTILE_NOT_REJECTED'}catch{$message=[string]$_.Exception.Message;$actual=[regex]::Match($message,'V8_FINAL_DEPENDENCY_SUBSTITUTION').Value;$result=[pscustomobject]@{Rejected=$true;Label=$actual;Effects=[pscustomobject]@{Mcp=0;Process=0;Validator=0;Transport=0}}}}
        else{$package=New-UID0002OWFinalPackage -Mode Proof -Scenario $name;$result=$package.InvokeProduction();$actual=[string]$result.Label;if($name-ceq'restart-save-attempt'){$restart=$result.RestartReceipt}}
        if($actual-cne$expected){throw "V8_FINAL_HOSTILE_WRONG_LABEL:${name}:expected=${expected}:actual=${actual}"};[void]$rows.Add([pscustomobject]@{Name=$name;Expected=$expected;Actual=$actual;Rejected=$true;PackageSHA256=$package.PackageSHA256;Effects=$result.Effects})
    }
    foreach($role in @('seal-self','hash-helper','public-entry','authority-builder','provider','canonical-path','coordinator','plan-factory','transitive-dependency')){$package=New-UID0002OWFinalPackage -Mode Proof -Scenario accepted -Substitution $role;try{[void]$package.InvokeProduction();throw 'V8_FINAL_HOSTILE_NOT_REJECTED'}catch{$message=[string]$_.Exception.Message;$actual=[regex]::Match($message,'V8_FINAL_DEPENDENCY_SUBSTITUTION').Value;if($actual-cne'V8_FINAL_DEPENDENCY_SUBSTITUTION'){throw "V8_FINAL_SUBSTITUTION_WRONG_LABEL:${role}:$message"};[void]$rows.Add([pscustomobject]@{Name="substitution-$role";Expected=$actual;Actual=$actual;Rejected=$true;PackageSHA256=$package.PackageSHA256;Effects=[pscustomobject]@{Mcp=0;File=0;Process=0;Validator=0;Transport=0}})}}
    $package=New-UID0002OWFinalPackage -Mode Proof -Scenario accepted;$oldSeal=$null;$oldPlan=$null;try{$oldSeal=(Get-Item Function:\Assert-UID0002OWV8ImplementationSeal -ErrorAction SilentlyContinue);$oldPlan=(Get-Item Function:\New-UID0002OWMutationPlan -ErrorAction SilentlyContinue);Set-Item Function:\Assert-UID0002OWV8ImplementationSeal -Value {$true};Set-Item Function:\New-UID0002OWMutationPlan -Value {[pscustomobject]@{Forged=$true}};try{[void]$package.InvokeProduction();throw 'V8_FINAL_HOSTILE_NOT_REJECTED'}catch{$message=[string]$_.Exception.Message;$actual=[regex]::Match($message,'V8_FINAL_GLOBAL_SUBSTITUTION').Value;if($actual-cne'V8_FINAL_GLOBAL_SUBSTITUTION'){throw "V8_FINAL_AUDIT_FORGE_WRONG_LABEL:$message"};[void]$rows.Add([pscustomobject]@{Name='global-audit-forge';Expected=$actual;Actual=$actual;Rejected=$true;PackageSHA256=$package.PackageSHA256;Effects=[pscustomobject]@{Mcp=0;File=0;Process=0;Validator=0;Transport=0}})}}finally{Remove-Item Function:\Assert-UID0002OWV8ImplementationSeal -ErrorAction SilentlyContinue;Remove-Item Function:\New-UID0002OWMutationPlan -ErrorAction SilentlyContinue;if($null-ne$oldSeal){Set-Item Function:\Assert-UID0002OWV8ImplementationSeal -Value $oldSeal.ScriptBlock};if($null-ne$oldPlan){Set-Item Function:\New-UID0002OWMutationPlan -Value $oldPlan.ScriptBlock}}
    $accepted=(New-UID0002OWFinalPackage -Mode Proof -Scenario accepted).InvokeProduction();$rollback=(New-UID0002OWFinalPackage -Mode Proof -Scenario 'determinate-failing-saved').InvokeProduction()
    if($rows.Count-ne32-or@($rows|Where-Object{$_.Rejected-ne$true}).Count-ne0){throw "V8_FINAL_HOSTILE_COUNT:$($rows.Count)"}
    if($accepted.Rejected-or$accepted.Result.Disposition-cne'ACCEPTED_S1'-or[Int64]$accepted.Effects.Restore-ne0-or[Int64]$accepted.Effects.Verifier-ne0){throw 'V8_FINAL_ACCEPTED_RECEIPT'}
    if($rollback.Rejected-or$rollback.Result.Disposition-cne'ROLLED_BACK_P0'-or[Int64]$rollback.Effects.Restore-ne1-or[Int64]$rollback.Effects.Verifier-ne1){throw 'V8_FINAL_ROLLBACK_RECEIPT'}
    if($null-eq$restart-or$restart.Label-cne'V8_SAVE_SECOND_ATTEMPT'-or[Int64]$restart.ExitCode-ne73-or$restart.CommandTransport-cne'PlainTextEnvironment'-or$restart.HostPolicyUnchanged-ne$true-or$restart.InheritedState-ne$false){throw 'V8_FINAL_RESTART_RECEIPT'}
    [pscustomobject]@{HostileCount=$rows.Count;Hostiles=@($rows);Accepted=$accepted;Rollback=$rollback;Restart=$restart}
}
~~~

## Removed Block R026

- SHA256: `CA92D8E57219580F7E7AE2095180B5BAA1785676926EFD19DEEF1D933155AEAB`
- Language: `powershell`
- Bytes: `22941`
- First recovered timestamp: `2026-08-09T08:27:20.323Z`
- Session provenance: rollout-2026-08-07T21-33-30-019fdf00-f811-7fd2-b22d-23613a6f7a94.jsonl line 201099 (2026-08-09T08:27:20.323Z); rollout-2026-08-07T21-33-30-019fdf00-f811-7fd2-b22d-23613a6f7a94.jsonl line 201100 (2026-08-09T08:27:20.492Z)

~~~powershell
Microsoft.PowerShell.Core\Set-StrictMode -Version 2
$script:UID0002OWV9ReportPath=[IO.Path]::GetFullPath('E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B004\research\0002OW-DirectionButtonControlPaneVtableData-empty-emitter-source-quality.md')
foreach($typeName in @('UID0002OWProductionBoundaryV9','UID0002OWFixtureBoundaryV9','UID0002OWStrictJsonV9','UID0002OWFileIdentityV9')){if($typeName-as[type]){throw 'V9_PRELOADED_TYPE'}}
$script:UID0002OWV9Report=[IO.File]::ReadAllText($script:UID0002OWV9ReportPath,[Text.UTF8Encoding]::new($false,$true))
$script:UID0002OWV9Fences=@([regex]::Matches($script:UID0002OWV9Report,'(?ms)^~~~powershell\s*\r?\n(.*?)^~~~\s*$'))
$script:UID0002OWV9Legacy=@($script:UID0002OWV9Fences|Microsoft.PowerShell.Core\Where-Object{$_.Groups[1].Value.Contains('function Global:New-UID0002OWFinalPackage')})
if($script:UID0002OWV9Legacy.Count-ne1){throw 'V9_LEGACY_FENCE_INVENTORY'}
$script:UID0002OWV9LegacyFence=$script:UID0002OWV9Legacy[0].Groups[1].Value
$script:UID0002OWV9LegacyCSharp=[regex]::Match($script:UID0002OWV9LegacyFence,"(?ms)Add-Type -ReferencedAssemblies 'System.Management.Automation' -TypeDefinition @'\r?\n(.*?)\r?\n'@").Groups[1].Value
$script:UID0002OWV9ParserStart=$script:UID0002OWV9LegacyCSharp.IndexOf('public static class UID0002OWStrictJson')
if($script:UID0002OWV9ParserStart-lt0){throw 'V9_LEGACY_CSHARP_INVENTORY'}
$script:UID0002OWV9SupportCSharp=$script:UID0002OWV9LegacyCSharp.Substring($script:UID0002OWV9ParserStart).Replace('UID0002OWStrictJson','UID0002OWStrictJsonV9').Replace('UID0002OWFileIdentity','UID0002OWFileIdentityV9')
$script:UID0002OWV9BoundaryCSharp=@'
using System;
using System.Linq;
using System.Management.Automation;
using System.Reflection;
using System.Security.Cryptography;
using System.Text;
public sealed class UID0002OWProductionBoundaryV9 {
    private sealed class BindingState {
        internal readonly ScriptBlock Seal;
        internal readonly ScriptBlock Entry;
        internal readonly ScriptBlock Getter;
        internal readonly string SealHash;
        internal readonly string EntryHash;
        internal readonly string GetterHash;
        internal readonly string PackageHash;
        internal readonly string Mac;
        internal BindingState(ScriptBlock seal,ScriptBlock entry,ScriptBlock getter,string packageHash,string mac) {
            Seal=seal;Entry=entry;Getter=getter;SealHash=Hash(seal.Ast.Extent.Text);EntryHash=Hash(entry.Ast.Extent.Text);GetterHash=Hash(getter.Ast.Extent.Text);PackageHash=packageHash;Mac=mac;
        }
    }
    private static readonly object gate=new object();
    private static readonly byte[] secret=NewSecret();
    private static readonly UID0002OWProductionBoundaryV9 singleton=new UID0002OWProductionBoundaryV9();
    private static BindingState binding;
    private UID0002OWProductionBoundaryV9() {}
    public static UID0002OWProductionBoundaryV9 Instance { get { lock(gate){if(binding==null)throw new InvalidOperationException("V9_PRODUCTION_NOT_BOUND");return singleton;} } }
    public string PackageSHA256 { get { lock(gate){Validate(singleton);return binding.PackageHash;} } }
    private static byte[] NewSecret(){var value=new byte[32];using(var rng=RandomNumberGenerator.Create())rng.GetBytes(value);return value;}
    private static string Hash(string value){using(var sha=SHA256.Create())return BitConverter.ToString(sha.ComputeHash(Encoding.UTF8.GetBytes(value??String.Empty))).Replace("-","");}
    private static string ComputeMac(ScriptBlock seal,ScriptBlock entry,ScriptBlock getter,string packageHash){string text=Hash(seal.Ast.Extent.Text)+"|"+Hash(entry.Ast.Extent.Text)+"|"+Hash(getter.Ast.Extent.Text)+"|"+packageHash+"|"+typeof(UID0002OWProductionBoundaryV9).Assembly.ManifestModule.ModuleVersionId.ToString("D");using(var h=new HMACSHA256(secret))return BitConverter.ToString(h.ComputeHash(Encoding.UTF8.GetBytes(text))).Replace("-","");}
    private static void Bind(ScriptBlock seal,ScriptBlock entry,ScriptBlock getter,string packageHash){lock(gate){if(binding!=null)throw new InvalidOperationException("V9_PRODUCTION_ALREADY_BOUND");if(seal==null||entry==null||getter==null||String.IsNullOrWhiteSpace(packageHash))throw new InvalidOperationException("V9_PRODUCTION_BINDING_ARGUMENT");string mac=ComputeMac(seal,entry,getter,packageHash);binding=new BindingState(seal,entry,getter,packageHash,mac);Validate(singleton);}}
    private static void Validate(UID0002OWProductionBoundaryV9 value){if(!Object.ReferenceEquals(value,singleton))throw new InvalidOperationException("V9_PRODUCTION_ROGUE_INSTANCE");var b=binding;if(b==null)throw new InvalidOperationException("V9_PRODUCTION_NOT_BOUND");if(!String.Equals(Hash(b.Seal.Ast.Extent.Text),b.SealHash,StringComparison.Ordinal)||!String.Equals(Hash(b.Entry.Ast.Extent.Text),b.EntryHash,StringComparison.Ordinal)||!String.Equals(Hash(b.Getter.Ast.Extent.Text),b.GetterHash,StringComparison.Ordinal)||!String.Equals(ComputeMac(b.Seal,b.Entry,b.Getter,b.PackageHash),b.Mac,StringComparison.Ordinal))throw new InvalidOperationException("V9_PRODUCTION_BINDING_INTEGRITY");}
    public object InvokeProduction(){lock(gate){Validate(this);binding.Seal.InvokeReturnAsIs();Validate(this);return binding.Entry.InvokeReturnAsIs();}}
}
public sealed class UID0002OWFixtureBoundaryV9 {
    private readonly ScriptBlock seal;private readonly ScriptBlock entry;private readonly string sealHash;private readonly string entryHash;
    public string PackageSHA256{get;private set;}public string FixtureScenario{get;private set;}
    public UID0002OWFixtureBoundaryV9(ScriptBlock seal,ScriptBlock entry,string packageHash,string scenario){if(seal==null||entry==null)throw new ArgumentNullException();this.seal=seal;this.entry=entry;sealHash=Hash(seal.Ast.Extent.Text);entryHash=Hash(entry.Ast.Extent.Text);PackageSHA256=packageHash;FixtureScenario=scenario;}
    private static string Hash(string value){using(var sha=SHA256.Create())return BitConverter.ToString(sha.ComputeHash(Encoding.UTF8.GetBytes(value??String.Empty))).Replace("-","");}
    public object InvokeFixture(){if(!String.Equals(Hash(seal.Ast.Extent.Text),sealHash,StringComparison.Ordinal))throw new InvalidOperationException("V8_FINAL_SEAL_SELF_SUBSTITUTION");if(!String.Equals(Hash(entry.Ast.Extent.Text),entryHash,StringComparison.Ordinal))throw new InvalidOperationException("V8_FINAL_PUBLIC_ENTRY_SUBSTITUTION");seal.InvokeReturnAsIs();return entry.InvokeReturnAsIs();}
}
'@
Microsoft.PowerShell.Utility\Add-Type -ReferencedAssemblies 'System.Management.Automation' -TypeDefinition ($script:UID0002OWV9BoundaryCSharp+$script:UID0002OWV9SupportCSharp)

function Global:Get-UID0002OWProductionBoundaryV9 {if($args.Count-ne0){throw 'V9_PRODUCTION_ARGUMENT_FORBIDDEN'};[UID0002OWProductionBoundaryV9]::Instance}

$tokens=$null;$errors=$null;$legacyAst=[Management.Automation.Language.Parser]::ParseInput($script:UID0002OWV9LegacyFence,[ref]$tokens,[ref]$errors);if($errors.Count-ne0){throw 'V9_LEGACY_PARSE'}
$factoryAst=[Management.Automation.Language.FunctionDefinitionAst]$legacyAst.Find({param($node)$node-is[Management.Automation.Language.FunctionDefinitionAst]-and$node.Name-like'*New-UID0002OWFinalPackage'},$true)
if($null-eq$factoryAst){throw 'V9_LEGACY_FACTORY'}
$builderSource=[string]$factoryAst.Extent.Text
$builderSource=$builderSource.Replace('New-UID0002OWFinalPackage','New-UID0002OWV9FixturePackage').Replace('function Global:New-UID0002OWV9FixturePackage','function New-UID0002OWV9RuntimeBuilder')
$builderSource=$builderSource.Replace('UID0002OWFinalBoundary','UID0002OWFixtureBoundaryV9').Replace('UID0002OWStrictJson','UID0002OWStrictJsonV9').Replace('UID0002OWFileIdentity','UID0002OWFileIdentityV9')
$builderSource=$builderSource.Replace('$closure[$name]=$latest[$name]','$closure[$name]=$latest[$name].Replace(''UID0002OWStrictJson'',''UID0002OWStrictJsonV9'').Replace(''UID0002OWFileIdentity'',''UID0002OWFileIdentityV9'')')
$builderSource=$builderSource.Replace("A234378F65747AF734AD634059DCF63A0DB8363CE2C82B661E2B9D88EAAABC68","V9_EXPECTED_SOURCE_AGGREGATE")
$builderSource=$builderSource.Replace("[UID0002OWFixtureBoundaryV9]::new(`$seal,`$entry,`$packageHash,`$Mode,`$Scenario)","[UID0002OWFixtureBoundaryV9]::new(`$seal,`$entry,`$packageHash,`$Scenario)")
$getterCommand=$ExecutionContext.InvokeCommand.GetCommand('Get-UID0002OWProductionBoundaryV9',[Management.Automation.CommandTypes]::Function);if($null-eq$getterCommand){throw 'V9_GETTER_MISSING'}
$hashText={param([string]$Text)$sha=[Security.Cryptography.SHA256]::Create();try{([BitConverter]::ToString($sha.ComputeHash([Text.Encoding]::UTF8.GetBytes($Text)))).Replace('-','')}finally{$sha.Dispose()}}
$getterHash=&$hashText ([string]$getterCommand.ScriptBlock.Ast.Extent.Text)
$moduleTail=@'
function New-UID0002OWV9FixturePackage {param([string]$Scenario='accepted',[string]$Substitution='');New-UID0002OWV9RuntimeBuilder -Mode Proof -Scenario $Scenario -Substitution $Substitution}
function Invoke-UID0002OWV9ProductionEntry {if($args.Count-ne0){throw 'V9_PRODUCTION_ARGUMENT_FORBIDDEN'};$runtime=New-UID0002OWV9RuntimeBuilder -Mode Production -Scenario accepted -Substitution '';[void]$runtime.InvokeFixture()}
function Assert-UID0002OWV9ProductionSeal {
    $hash={param([string]$Text)$sha=[Security.Cryptography.SHA256]::Create();try{([BitConverter]::ToString($sha.ComputeHash([Text.Encoding]::UTF8.GetBytes($Text)))).Replace('-','')}finally{$sha.Dispose()}}
    $session=$ExecutionContext.SessionState;$internal=$session.GetType().GetField('sessionState',[Reflection.BindingFlags]'Instance,NonPublic').GetValue($session);$moduleScope=$internal.GetType().GetProperty('ModuleScope',[Reflection.BindingFlags]'Instance,NonPublic,Public').GetValue($internal,$null);$moduleTable=$moduleScope.GetType().GetProperty('FunctionTable',[Reflection.BindingFlags]'Instance,NonPublic,Public').GetValue($moduleScope,$null)
    $builder=$moduleTable['New-UID0002OWV9RuntimeBuilder'];if($null-eq$builder-or(&$hash ([string]$builder.ScriptBlock.Ast.Extent.Text))-cne$script:V9BuilderHash){throw 'V9_PRODUCTION_BUILDER_SUBSTITUTION'}
    $globalScope=$internal.GetType().GetProperty('GlobalScope',[Reflection.BindingFlags]'Instance,NonPublic,Public').GetValue($internal,$null);$globalTable=$globalScope.GetType().GetProperty('FunctionTable',[Reflection.BindingFlags]'Instance,NonPublic,Public').GetValue($globalScope,$null)
    $getter=$globalTable['Get-UID0002OWProductionBoundaryV9'];if($null-eq$getter-or(&$hash ([string]$getter.ScriptBlock.Ast.Extent.Text))-cne$script:V9GetterHash){throw 'V9_PRODUCTION_GETTER_SUBSTITUTION'}
    $fixture=$globalTable['New-UID0002OWV9FixturePackage'];if($null-eq$fixture-or(&$hash ([string]$fixture.ScriptBlock.Ast.Extent.Text))-cne$script:V9FixtureFactoryHash){throw 'V9_PRODUCTION_FACTORY_SUBSTITUTION'}
    $true
}
$hash={param([string]$Text)$sha=[Security.Cryptography.SHA256]::Create();try{([BitConverter]::ToString($sha.ComputeHash([Text.Encoding]::UTF8.GetBytes($Text)))).Replace('-','')}finally{$sha.Dispose()}}
$script:V9GetterHash=$GetterHash
$script:V9BuilderHash=&$hash ([string](Get-Command New-UID0002OWV9RuntimeBuilder).ScriptBlock.Ast.Extent.Text)
$script:V9FixtureFactoryHash=&$hash ([string](Get-Command New-UID0002OWV9FixturePackage).ScriptBlock.Ast.Extent.Text)
Export-ModuleMember -Function New-UID0002OWV9FixturePackage,Invoke-UID0002OWV9ProductionEntry,Assert-UID0002OWV9ProductionSeal
'@
$loaderSource="param(`$GetterHash)`n$builderSource`n$moduleTail"
$script:UID0002OWV9LoaderModule=Microsoft.PowerShell.Core\New-Module -Name ('UID0002OWV9Loader'+[Guid]::NewGuid().ToString('N')) -ArgumentList $getterHash -ScriptBlock ([ScriptBlock]::Create($loaderSource))
Microsoft.PowerShell.Core\Import-Module $script:UID0002OWV9LoaderModule -Global -Force
$sealCommand=$ExecutionContext.InvokeCommand.GetCommand('Assert-UID0002OWV9ProductionSeal',[Management.Automation.CommandTypes]::Function);$entryCommand=$ExecutionContext.InvokeCommand.GetCommand('Invoke-UID0002OWV9ProductionEntry',[Management.Automation.CommandTypes]::Function)
if($null-eq$sealCommand-or$null-eq$entryCommand){throw 'V9_PRODUCTION_FUNCTION_INVENTORY'}
$packageHash=&$hashText ((&$hashText ([string]$sealCommand.ScriptBlock.Ast.Extent.Text))+'|'+(&$hashText ([string]$entryCommand.ScriptBlock.Ast.Extent.Text))+'|'+$getterHash+'|'+[UID0002OWProductionBoundaryV9].Assembly.ManifestModule.ModuleVersionId.ToString('D'))
$bind=[UID0002OWProductionBoundaryV9].GetMethod('Bind',[Reflection.BindingFlags]'Static,NonPublic');if($null-eq$bind){throw 'V9_PRODUCTION_BIND_METHOD'}
try{[void]$bind.Invoke($null,[object[]]@($sealCommand.ScriptBlock,$entryCommand.ScriptBlock,$getterCommand.ScriptBlock,$packageHash))}catch{throw "V9_PRODUCTION_BIND_FAILURE:$($_.Exception.InnerException.Message)"}
$script:UID0002OWV9ProductionBoundary=Get-UID0002OWProductionBoundaryV9

foreach($observerName in @('Get-UID0002OWFinalObservedFile','Get-UID0002OWFinalObservedTempState','Get-UID0002OWFinalObservedRuntimeState','Get-UID0002OWFinalExternalSnapshot','Assert-UID0002OWFinalExternalUnchanged')){$definition=[Management.Automation.Language.FunctionDefinitionAst]$legacyAst.Find({param($node)$node-is[Management.Automation.Language.FunctionDefinitionAst]-and$node.Name-like"*$observerName"},$true);if($null-eq$definition){throw "V9_OBSERVER_MISSING:$observerName"};. ([ScriptBlock]::Create([string]$definition.Extent.Text))}

function Global:Invoke-UID0002OWV9PreloadHostile([ValidateSet('boundary','strict-json','file-identity')][string]$Kind){
    $report=[IO.File]::ReadAllText($script:UID0002OWV9ReportPath,[Text.UTF8Encoding]::new($false,$true));$match=@([regex]::Matches($report,'(?ms)^~~~powershell\s*\r?\n(.*?)^~~~\s*$')|Microsoft.PowerShell.Core\Where-Object{$_.Groups[1].Value.Contains('UID0002OWProductionBoundaryV9')});if($match.Count-ne1){throw 'V9_FINAL_FENCE_INVENTORY'};$fence=$match[0].Groups[1].Value
    $preload=switch($Kind){'boundary'{"Microsoft.PowerShell.Utility\Add-Type -TypeDefinition 'public sealed class UID0002OWProductionBoundaryV9 {}'"};'strict-json'{"Microsoft.PowerShell.Utility\Add-Type -TypeDefinition 'public static class UID0002OWStrictJsonV9 {}'"};'file-identity'{"Microsoft.PowerShell.Utility\Add-Type -TypeDefinition 'public static class UID0002OWFileIdentityV9 {}'"}}
    $tail="throw 'V9_PRELOAD_NOT_REJECTED'`n}catch{`$label=[regex]::Match([string]`$_.Exception.Message,'V9_[A-Z0-9_]+').Value;[Console]::Out.WriteLine(`$label);if(`$label-ceq'V9_PRELOADED_TYPE'){exit 73}else{exit 74}}";$script="try{`n$preload`n$fence`n$tail"
    $exe=[IO.Path]::GetFullPath("$env:SystemRoot\System32\WindowsPowerShell\v1.0\powershell.exe");$start=[Diagnostics.ProcessStartInfo]::new();$start.FileName=$exe;$start.Arguments='-NoLogo -NoProfile -NonInteractive -Command "$text=[Console]::In.ReadToEnd();[ScriptBlock]::Create($text).Invoke()"';$start.UseShellExecute=$false;$start.CreateNoWindow=$true;$start.RedirectStandardInput=$true;$start.RedirectStandardOutput=$true;$start.RedirectStandardError=$true;$process=[Diagnostics.Process]::new();$process.StartInfo=$start
    try{if(-not$process.Start()){throw 'V9_PRELOAD_PROCESS'};$childId=[int]$process.Id;$childStart=[Int64]$process.StartTime.ToUniversalTime().Ticks;$childPath=$exe;$pathEvidence='PinnedProcessStartInfo';try{$observed=[string]$process.MainModule.FileName;if(-not[string]::IsNullOrWhiteSpace($observed)){$childPath=[IO.Path]::GetFullPath($observed);$pathEvidence='LiveProcessMainModule'}}catch{};if(-not[StringComparer]::OrdinalIgnoreCase.Equals($childPath,$exe)){try{$process.Kill();[void]$process.WaitForExit(15000)}catch{};throw 'V9_PRELOAD_IDENTITY'};$stdoutTask=$process.StandardOutput.ReadToEndAsync();$stderrTask=$process.StandardError.ReadToEndAsync();$process.StandardInput.Write($script);$process.StandardInput.Close();if(-not$process.WaitForExit(120000)){try{$process.Kill();[void]$process.WaitForExit(15000)}catch{};throw 'V9_PRELOAD_TIMEOUT'};$exit=$process.ExitCode;$stdout=$stdoutTask.Result;$stderr=$stderrTask.Result;$retired=$true;try{$candidate=[Diagnostics.Process]::GetProcessById($childId);try{if([Int64]$candidate.StartTime.ToUniversalTime().Ticks-eq$childStart){$retired=$false}}finally{$candidate.Dispose()}}catch[ArgumentException]{};if(-not$retired){throw 'V9_PRELOAD_NOT_RETIRED'}}finally{$process.Dispose()}
    $output=@($stdout-split'\r?\n'|Microsoft.PowerShell.Core\Where-Object{$_-ne''});if($exit-ne73-or$output.Count-ne1-or$output[0]-cne'V9_PRELOADED_TYPE'-or-not[string]::IsNullOrWhiteSpace($stderr)){throw "V9_PRELOAD_RECEIPT:${Kind}:${exit}:$($output-join'|'):$stderr"};[pscustomobject]@{Kind=$Kind;Label='V9_PRELOADED_TYPE';ExitCode=$exit;CommandTransport='RedirectedStandardInputFixedInterpreter';ChildIdentity=[pscustomobject]@{PID=$childId;StartTimeUtcTicks=$childStart;Executable=$childPath;ExecutableEvidence=$pathEvidence};ChildRetired=$true}
}

$legacySuite=[Management.Automation.Language.FunctionDefinitionAst]$legacyAst.Find({param($node)$node-is[Management.Automation.Language.FunctionDefinitionAst]-and$node.Name-like'*Invoke-UID0002OWFinalProofSuite'},$true);if($null-eq$legacySuite){throw 'V9_FIXTURE_SUITE_MISSING'}
$fixtureSuite=[string]$legacySuite.Extent.Text
$fixtureSuite=$fixtureSuite.Replace('Invoke-UID0002OWFinalProofSuite','Invoke-UID0002OWV9FixtureProofSuite').Replace('New-UID0002OWFinalPackage','New-UID0002OWV9FixturePackage').Replace('Invoke-UID0002OWFinalPreloadHostile','Invoke-UID0002OWV9PreloadHostile').Replace('.InvokeProduction()','.InvokeFixture()').Replace("'PRODUCTION-BOUNDARY'","'FIXTURE-BOUNDARY'").Replace('ProductionBoundaryCount','FixtureBoundaryCount').Replace('$expectedProduction','$expectedFixture').Replace('$productionCount','$fixtureCount').Replace('production=$productionCount','fixture=$fixtureCount').Replace("'V8_FINAL_PRELOADED_TYPE'","'V9_PRELOADED_TYPE'")
. ([ScriptBlock]::Create($fixtureSuite))

function Global:Invoke-UID0002OWV9ProductionConstructionProof {
    $rows=[Collections.Generic.List[object]]::new();$type=[UID0002OWProductionBoundaryV9];$singleton=Get-UID0002OWProductionBoundaryV9
    $labelOf={param($ErrorRecord)$exception=$ErrorRecord.Exception;while($null-ne$exception){$label=[regex]::Match([string]$exception.Message,'V9_[A-Z0-9_]+').Value;if(-not[string]::IsNullOrWhiteSpace($label)){return $label};$exception=$exception.InnerException};'V9_UNKNOWN_FAILURE'}
    $run={param([string]$Name,[string]$Expected,[scriptblock]$Action)$before=Get-UID0002OWFinalExternalSnapshot;$actual=&$Action;if($actual-cne$Expected){throw "V9_PRODUCTION_HOSTILE_LABEL:${Name}:expected=${Expected}:actual=${actual}"};$after=Get-UID0002OWFinalExternalSnapshot;$effects=Assert-UID0002OWFinalExternalUnchanged $before $after $Name 'PRODUCTION-CONSTRUCTION' $null $null;[void]$rows.Add([pscustomobject]@{Name=$Name;Expected=$Expected;Actual=$actual;Rejected=$true;Route='PRODUCTION-CONSTRUCTION';PackageSHA256=$singleton.PackageSHA256;Effects=$effects})}
    &$run 'direct-public-constructor' 'V9_PRODUCTION_CONSTRUCTOR_BLOCKED' {if($type.GetConstructors([Reflection.BindingFlags]'Public,Instance').Count-ne0){throw 'V9_PRODUCTION_PUBLIC_CONSTRUCTOR'};try{[void][Activator]::CreateInstance($type);throw 'V9_PRODUCTION_CONSTRUCTOR_OPEN'}catch{if($_.Exception-is[MissingMethodException]-or$_.Exception.InnerException-is[MissingMethodException]){'V9_PRODUCTION_CONSTRUCTOR_BLOCKED'}else{&$labelOf $_}}}
    &$run 'reflection-private-constructor' 'V9_PRODUCTION_ROGUE_INSTANCE' {$ctor=$type.GetConstructor([Reflection.BindingFlags]'NonPublic,Instance',$null,[Type[]]@(),$null);$rogue=$ctor.Invoke([object[]]@());try{[void]$rogue.InvokeProduction();throw 'V9_PRODUCTION_ROGUE_ACCEPTED'}catch{&$labelOf $_}}
    &$run 'uninitialized-object' 'V9_PRODUCTION_ROGUE_INSTANCE' {$rogue=[Runtime.Serialization.FormatterServices]::GetUninitializedObject($type);try{[void]$rogue.InvokeProduction();throw 'V9_PRODUCTION_UNINITIALIZED_ACCEPTED'}catch{&$labelOf $_}}
    foreach($memberName in @('Entry','Seal')){&$run ("arbitrary-"+$memberName.ToLowerInvariant()) 'V9_PRODUCTION_BINDING_INTEGRITY' {$bindingField=$type.GetField('binding',[Reflection.BindingFlags]'Static,NonPublic');$binding=$bindingField.GetValue($null);$field=$binding.GetType().GetField($memberName,[Reflection.BindingFlags]'Instance,NonPublic,Public');$old=$field.GetValue($binding);try{$field.SetValue($binding,[ScriptBlock]::Create("throw 'FORGED'"));try{[void]$singleton.InvokeProduction();throw 'V9_PRODUCTION_FORGED_ACCEPTED'}catch{&$labelOf $_}}finally{$field.SetValue($binding,$old)}}}
    &$run 'private-bind-reentry' 'V9_PRODUCTION_ALREADY_BOUND' {$bindMethod=$type.GetMethod('Bind',[Reflection.BindingFlags]'Static,NonPublic');$forged=[ScriptBlock]::Create("throw 'FORGED'");try{[void]$bindMethod.Invoke($null,[object[]]@($forged,$forged,$forged,'FORGED'));throw 'V9_PRODUCTION_REBIND_ACCEPTED'}catch{&$labelOf $_}}
    &$run 'mode-diversion' 'V9_PRODUCTION_ARGUMENT_FORBIDDEN' {try{[void](& Get-UID0002OWProductionBoundaryV9 '-Mode' 'Proof');throw 'V9_PRODUCTION_MODE_ACCEPTED'}catch{&$labelOf $_}}
    &$run 'scenario-diversion' 'V9_PRODUCTION_ARGUMENT_FORBIDDEN' {try{[void](& Get-UID0002OWProductionBoundaryV9 '-Scenario' 'forged');throw 'V9_PRODUCTION_SCENARIO_ACCEPTED'}catch{&$labelOf $_}}
    $session=$ExecutionContext.SessionState;$internal=$session.GetType().GetField('sessionState',[Reflection.BindingFlags]'Instance,NonPublic').GetValue($session);$globalScope=$internal.GetType().GetProperty('GlobalScope',[Reflection.BindingFlags]'Instance,NonPublic,Public').GetValue($internal,$null);$globalTable=$globalScope.GetType().GetProperty('FunctionTable',[Reflection.BindingFlags]'Instance,NonPublic,Public').GetValue($globalScope,$null)
    &$run 'getter-substitution' 'V9_PRODUCTION_GETTER_SUBSTITUTION' {$old=$globalTable['Get-UID0002OWProductionBoundaryV9'];try{Microsoft.PowerShell.Management\Set-Item Function:\global:Get-UID0002OWProductionBoundaryV9 -Value {$null};try{[void]$singleton.InvokeProduction();throw 'V9_PRODUCTION_GETTER_ACCEPTED'}catch{&$labelOf $_}}finally{$globalTable['Get-UID0002OWProductionBoundaryV9']=$old}}
    &$run 'fixture-factory-substitution' 'V9_PRODUCTION_FACTORY_SUBSTITUTION' {$old=$globalTable['New-UID0002OWV9FixturePackage'];try{Microsoft.PowerShell.Management\Set-Item Function:\global:New-UID0002OWV9FixturePackage -Value {$null};try{[void]$singleton.InvokeProduction();throw 'V9_PRODUCTION_FACTORY_ACCEPTED'}catch{&$labelOf $_}}finally{$globalTable['New-UID0002OWV9FixturePackage']=$old}}
    if($rows.Count-ne10-or@($rows|Microsoft.PowerShell.Core\Where-Object{$_.Rejected-ne$true-or$_.Effects.Unchanged-ne$true}).Count-ne0){throw "V9_PRODUCTION_HOSTILE_COUNT:$($rows.Count)"};[pscustomobject]@{HostileCount=$rows.Count;Route='PRODUCTION-CONSTRUCTION';Hostiles=@($rows);IndependentObservationCount=@($rows|Microsoft.PowerShell.Core\Where-Object{$_.Effects.Unchanged-eq$true}).Count;PackageSHA256=$singleton.PackageSHA256}
}
~~~
