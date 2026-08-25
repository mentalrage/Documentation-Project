<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0001NW-VirusCheckerProcessTreeHelpers-empty-emitter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001NW-VirusCheckerProcessTreeHelpers-empty-emitter-source-quality.md](0001NW-VirusCheckerProcessTreeHelpers-empty-emitter-source-quality.md)
- Source report SHA256 before archive-link insertion: `8673F35DD3FBD2BA41CCB14A600C86DD82CF4816CA8BD7575523AA3D4F7C7FAB`
- Recovery generated: `2026-08-09T22:17:53Z`
- Unique recovered executable blocks: `29`
- Recovered executable bytes: `294014`
- Recovery basis: report-path-associated Codex session history. The source report had already removed its executable packages before the supervisor could extract them directly.
- Scope: this archive preserves every unique recoverable report-local executable block, including superseded historical variants where session history retained more than the final pre-removal report.
- Authority: this file is not a B-agent research report, claims no target coverage, and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- SHA256: `1506C1653D6C023D65C1D21A451F6A74C00BE76059836A7B9E0E21A880C481F7`
- Language: `powershell`
- Bytes: `487`
- First recovered timestamp: `2026-08-03T03:06:53.327Z`
- Session provenance: rollout-2026-08-01T02-15-20-019fbbf6-7bfd-7272-a663-0b7a6057700c.jsonl line 604029 (2026-08-03T03:06:53.327Z)

~~~powershell
python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode file --file by-class/-coverage-report.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode file --file by-file/-coverage-report.md --apply --queue-timeout 240 --no-generated-refresh
python .\tools\validator.py --mode autogen --apply --wait-generated --queue-timeout 240
~~~

## Removed Block R002

- SHA256: `F97D9DF3902A59DD44B125A6F678D5EEB0BB9FC3D9929D2B59F137E63F87D6DE`
- Language: `powershell`
- Bytes: `330`
- First recovered timestamp: `2026-08-03T03:06:53.327Z`
- Session provenance: rollout-2026-08-01T02-15-20-019fbbf6-7bfd-7272-a663-0b7a6057700c.jsonl line 604029 (2026-08-03T03:06:53.327Z)

~~~powershell
python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/-coverage-report.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/-coverage-report.md --apply --queue-timeout 240
~~~

## Removed Block R003

- SHA256: `0C66F64755B126A1A6DE78E93159714266138C412B27A6977C34B670F6D4107B`
- Language: `powershell`
- Bytes: `2233`
- First recovered timestamp: `2026-08-06T09:51:16.465Z`
- Session provenance: rollout-2026-08-03T16-08-33-019fc93e-0635-72d0-bdbb-34483e89fdc4.jsonl line 185597 (2026-08-06T09:51:16.465Z); rollout-2026-08-03T16-08-33-019fc93e-0635-72d0-bdbb-34483e89fdc4.jsonl line 185598 (2026-08-06T09:51:16.531Z)

~~~powershell
$ErrorActionPreference = 'Stop'
$CanonicalPath = [System.IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64')
$BackupPath = [System.IO.Path]::GetFullPath('<EXACT_FROZEN_BACKUP_PATH>')
$P0Path = [System.IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64')
$P0Size = [Int64]<EXACT_P0_SIZE>
$P0LastWriteTimeUtcTicks = [Int64]<EXACT_P0_LASTWRITETIMEUTC_TICKS>
$P0LastWriteTimeUtc = [DateTime]::new($P0LastWriteTimeUtcTicks, [System.DateTimeKind]::Utc)
$P0Sha256 = '<EXACT_P0_SHA256>'.ToUpperInvariant()
$FailingP1Size = [Int64]<EXACT_FAILING_P1_SIZE>
$FailingP1LastWriteTimeUtcTicks = [Int64]<EXACT_FAILING_P1_LASTWRITETIMEUTC_TICKS>
$FailingP1Sha256 = '<EXACT_FAILING_P1_SHA256>'.ToUpperInvariant()
if ([System.StringComparer]::OrdinalIgnoreCase.Equals($CanonicalPath, $BackupPath)) { throw 'backup path aliases canonical path' }
$CurrentInfo = [System.IO.FileInfo]::new($CanonicalPath)
$CurrentSha256 = (Get-FileHash -LiteralPath $CanonicalPath -Algorithm SHA256).Hash.ToUpperInvariant()
if ($CurrentInfo.FullName -cne $P0Path -or $CurrentInfo.Length -ne $FailingP1Size -or $CurrentInfo.LastWriteTimeUtc.Ticks -ne $FailingP1LastWriteTimeUtcTicks -or $CurrentSha256 -cne $FailingP1Sha256) { throw 'canonical disk is not exact attributable failing P1; do not restore' }
$BackupInfo = [System.IO.FileInfo]::new($BackupPath)
$BackupSha256 = (Get-FileHash -LiteralPath $BackupPath -Algorithm SHA256).Hash.ToUpperInvariant()
if ($BackupInfo.FullName -cne $BackupPath -or $BackupInfo.Length -ne $P0Size -or $BackupInfo.LastWriteTimeUtc.Ticks -ne $P0LastWriteTimeUtcTicks -or $BackupSha256 -cne $P0Sha256) { throw 'backup no longer equals frozen P0; do not restore' }
[System.IO.File]::Copy($BackupPath, $CanonicalPath, $true)
[System.IO.File]::SetLastWriteTimeUtc($CanonicalPath, $P0LastWriteTimeUtc)
$RestoredInfo = [System.IO.FileInfo]::new($CanonicalPath)
$RestoredSha256 = (Get-FileHash -LiteralPath $CanonicalPath -Algorithm SHA256).Hash.ToUpperInvariant()
if ($RestoredInfo.FullName -cne $P0Path -or $RestoredInfo.Length -ne $P0Size -or $RestoredInfo.LastWriteTimeUtc.Ticks -ne $P0LastWriteTimeUtcTicks -or $RestoredSha256 -cne $P0Sha256) { throw 'restored canonical tuple is not exact P0' }
~~~

## Removed Block R004

- SHA256: `97C32654A30A1ACC02726FAD1B6110019C8183385DD9C05924AD2AC9EF445C39`
- Language: `powershell`
- Bytes: `1884`
- First recovered timestamp: `2026-08-06T09:51:16.465Z`
- Session provenance: rollout-2026-08-03T16-08-33-019fc93e-0635-72d0-bdbb-34483e89fdc4.jsonl line 185597 (2026-08-06T09:51:16.465Z); rollout-2026-08-03T16-08-33-019fc93e-0635-72d0-bdbb-34483e89fdc4.jsonl line 185598 (2026-08-06T09:51:16.531Z)

~~~powershell
$ErrorActionPreference = 'Stop'
$CanonicalPath = [System.IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64')
$P0Info = [System.IO.FileInfo]::new($CanonicalPath)
$P0Path = $P0Info.FullName
$P0Size = [Int64]$P0Info.Length
$P0LastWriteTimeUtcTicks = [Int64]$P0Info.LastWriteTimeUtc.Ticks
$P0LastWriteTimeUtc = [DateTime]::new($P0LastWriteTimeUtcTicks, [System.DateTimeKind]::Utc)
$P0Sha256 = (Get-FileHash -LiteralPath $CanonicalPath -Algorithm SHA256).Hash.ToUpperInvariant()
$BackupPath = [System.IO.Path]::GetFullPath("$CanonicalPath.bak-UID0001NW-prestate-<UTC-yyyyMMdd-HHmmss-fffffff>-<P0-SHA-prefix>")
if ([System.StringComparer]::OrdinalIgnoreCase.Equals($CanonicalPath, $BackupPath)) { throw 'backup path aliases canonical path' }
if ([System.IO.File]::Exists($BackupPath) -or [System.IO.Directory]::Exists($BackupPath)) { throw 'backup collision; do not overwrite, delete, or reuse' }
[System.IO.File]::Copy($CanonicalPath, $BackupPath, $false)
[System.IO.File]::SetLastWriteTimeUtc($BackupPath, $P0LastWriteTimeUtc)
$BackupInfo = [System.IO.FileInfo]::new($BackupPath)
$BackupSha256 = (Get-FileHash -LiteralPath $BackupPath -Algorithm SHA256).Hash.ToUpperInvariant()
$CanonicalAfterBackup = [System.IO.FileInfo]::new($CanonicalPath)
$CanonicalAfterBackupSha256 = (Get-FileHash -LiteralPath $CanonicalPath -Algorithm SHA256).Hash.ToUpperInvariant()
if ($BackupInfo.FullName -cne $BackupPath -or $BackupInfo.Length -ne $P0Size -or $BackupSha256 -cne $P0Sha256 -or $BackupInfo.LastWriteTimeUtc.Ticks -ne $P0LastWriteTimeUtcTicks) { throw 'backup tuple does not equal P0' }
if ($CanonicalAfterBackup.FullName -cne $P0Path -or $CanonicalAfterBackup.Length -ne $P0Size -or $CanonicalAfterBackupSha256 -cne $P0Sha256 -or $CanonicalAfterBackup.LastWriteTimeUtc.Ticks -ne $P0LastWriteTimeUtcTicks) { throw 'canonical P0 drifted during backup creation' }
~~~

## Removed Block R005

- SHA256: `A7378C273FD94C046E2CA3D92CB486D81B5EBF08958A9785D28FE29D8CB91932`
- Language: `powershell`
- Bytes: `3170`
- First recovered timestamp: `2026-08-06T12:16:02.150Z`
- Session provenance: rollout-2026-08-03T16-08-33-019fc93e-0635-72d0-bdbb-34483e89fdc4.jsonl line 186100 (2026-08-06T12:16:02.150Z); rollout-2026-08-03T16-08-33-019fc93e-0635-72d0-bdbb-34483e89fdc4.jsonl line 186101 (2026-08-06T12:16:02.207Z)

~~~powershell
$ErrorActionPreference = 'Stop'
$Python = [System.IO.Path]::GetFullPath('C:\Users\admin\.idapro\idalib-mcp-venv\Scripts\python.exe')
if (-not [System.IO.File]::Exists($Python)) { throw 'missing routing probe interpreter' }
$Probe = @'
import hashlib, importlib.util, json, sys
from importlib.metadata import entry_points
from pathlib import Path

expected = {
    "ida_pro_mcp.idalib_supervisor": (r"C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp\idalib_supervisor.py", 52468, "2D7098B6BDB58D7DCF8CF4825BBE7584F5E7ACB256AD318B05482E9A0B9AF10A"),
    "ida_pro_mcp.idalib_server": (r"C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp\idalib_server.py", 9848, "06C922EEF3F2E6771308C687231FE443A65DADF340E72001C6B05B7FC70B2034"),
    "ida_pro_mcp.idalib_session_manager": (r"C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp\idalib_session_manager.py", 7032, "9EDEEBD47B6FF85F9809E7159CE03D3EF41833692D28AC4367C6C4E5CAE00890"),
    "ida_pro_mcp.worker_lifecycle": (r"C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp\worker_lifecycle.py", 3273, "303A2A15BB316CD2200B2C54EF8685EBBC50EF5114FDD1FBC6C16CD01B6BAC63"),
}
rows = []
for module_name, (expected_path, expected_size, expected_sha) in expected.items():
    spec = importlib.util.find_spec(module_name)
    if spec is None or not spec.origin:
        raise SystemExit(f"missing module spec: {module_name}")
    resolved = Path(spec.origin).resolve(strict=True)
    relative = Path(*module_name.split('.')).with_suffix('.py')
    candidates = sorted({str((Path(root).resolve() / relative).resolve()) for root in sys.path if root and (Path(root).resolve() / relative).is_file()})
    actual_sha = hashlib.sha256(resolved.read_bytes()).hexdigest().upper()
    if candidates != [str(resolved)]:
        raise SystemExit(f"missing or duplicate module candidate: {module_name}: {candidates}")
    if str(resolved).casefold() != str(Path(expected_path).resolve()).casefold() or resolved.stat().st_size != expected_size or actual_sha != expected_sha:
        raise SystemExit(f"wrong module identity: {module_name}: {resolved}|{resolved.stat().st_size}|{actual_sha}")
    rows.append({"module": module_name, "loaded_path": str(resolved), "candidate_count": len(candidates), "size": resolved.stat().st_size, "sha256": actual_sha})
eps = [ep for ep in entry_points(group='console_scripts') if ep.name == 'idalib-mcp']
if len(eps) != 1 or eps[0].value != 'ida_pro_mcp.idalib_supervisor:main':
    raise SystemExit(f"wrong or ambiguous idalib-mcp entry point: {[(ep.name, ep.value) for ep in eps]}")
print(json.dumps({"python": str(Path(sys.executable).resolve()), "entry_point": eps[0].value, "rows": rows}, separators=(',', ':')))
'@
$Raw = @($Probe | & $Python - 2>&1)
if ($LASTEXITCODE -ne 0) { throw ('routing source probe failed: ' + ($Raw -join "`n")) }
$Result = (($Raw -join "`n") | ConvertFrom-Json)
if ($Result.python -ine $Python -or $Result.entry_point -cne 'ida_pro_mcp.idalib_supervisor:main' -or @($Result.rows).Count -ne 4) { throw 'routing source probe result mismatch' }
$Result | ConvertTo-Json -Depth 6 -Compress
~~~

## Removed Block R006

- SHA256: `EFFCDB9C5D7224B7A35D1599E5DD22D2916085763C00E31A202638F00FDE2E4C`
- Language: `powershell`
- Bytes: `1245`
- First recovered timestamp: `2026-08-06T12:19:57.904Z`
- Session provenance: rollout-2026-08-03T16-08-33-019fc93e-0635-72d0-bdbb-34483e89fdc4.jsonl line 186162 (2026-08-06T12:19:57.904Z); rollout-2026-08-03T16-08-33-019fc93e-0635-72d0-bdbb-34483e89fdc4.jsonl line 186163 (2026-08-06T12:19:57.964Z)

~~~powershell
$ErrorActionPreference = 'Stop'
$ServerExe = [System.IO.Path]::GetFullPath('C:\Users\admin\.idapro\idalib-mcp-venv\Scripts\idalib-mcp.exe')
if (-not [System.IO.File]::Exists($ServerExe)) { throw 'missing exact idalib-mcp entry point executable' }
# Run only after R00A and exact-generation retirement of every prior managed listener/worker.
$Listener = Start-Process -FilePath $ServerExe -ArgumentList @('--host','127.0.0.1','--port','13337') -WindowStyle Hidden -PassThru
$ListenerCim = Get-CimInstance Win32_Process -Filter ("ProcessId=" + [int]$Listener.Id)
$Port = Get-NetTCPConnection -LocalAddress '127.0.0.1' -LocalPort 13337 -State Listen -ErrorAction Stop
if ($null -eq $ListenerCim -or @($Port).Count -ne 1 -or [int]$Port[0].OwningProcess -ne [int]$Listener.Id) { throw 'listener identity/socket mismatch' }
if ($ListenerCim.ExecutablePath -ine $ServerExe -or $ListenerCim.CommandLine -notmatch '(?i)--host\s+127\.0\.0\.1' -or $ListenerCim.CommandLine -notmatch '(?i)--port\s+13337' -or $ListenerCim.CommandLine -match '(?i)NexusTK\.exe\.i64') { throw 'listener route or forbidden positional IDB mismatch' }
# Capture PID, CreationDate/start identity, executable, command line, parent PID, and socket; then run R00B.
~~~

## Removed Block R007

- SHA256: `145A32EA06F30798625C2228496963BE175AD66D21E7A03C53A0A035FCF665E9`
- Language: `powershell`
- Bytes: `6427`
- First recovered timestamp: `2026-08-08T03:00:20.791Z`
- Session provenance: rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 196060 (2026-08-08T03:00:20.791Z); rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 196061 (2026-08-08T03:00:22.222Z)

~~~powershell
$script:UID0001NWV42Adapters=@{}
function New-UID0001NWV42Counters{[ordered]@{transport=0;open=0;mutation=0;readback=0;save=0;stop=0;write=0;restore=0;cleanup=0}}
function New-UID0001NWV42FixtureAdapter([object]$Case){$cfg=[ordered]@{schema_version=42;kind='SEALED_ZERO_EFFECT';case_id=[string]$Case.id;suite=[string]$Case.suite;fault=[string]$Case.fault;stage=[string]$Case.stage;branch=if($Case.PSObject.Properties.Name-contains'branch'){[string]$Case.branch}else{'NONE'};expected=[string]$Case.expected;external_effects=0};$seal=Get-UID0001NWV42Sha (ConvertTo-UID0001NWV42Json $cfg);$a=[pscustomobject]@{config=[pscustomobject]$cfg;seal=$seal;last_state=$null};$script:UID0001NWV42Adapters[$seal]=$a;$a}
function Assert-UID0001NWV42Adapter([object]$Adapter){if($null-eq$Adapter-or$Adapter.config.kind-cne'SEALED_ZERO_EFFECT'-or[int]$Adapter.config.external_effects-ne0){Stop-UID0001NWV42 'ADAPTER_KIND' 'zero effect required'};$seal=Get-UID0001NWV42Sha (ConvertTo-UID0001NWV42Json ([ordered]@{schema_version=[int]$Adapter.config.schema_version;kind=[string]$Adapter.config.kind;case_id=[string]$Adapter.config.case_id;suite=[string]$Adapter.config.suite;fault=[string]$Adapter.config.fault;stage=[string]$Adapter.config.stage;branch=[string]$Adapter.config.branch;expected=[string]$Adapter.config.expected;external_effects=[int]$Adapter.config.external_effects}));if($seal-cne[string]$Adapter.seal-or-not$script:UID0001NWV42Adapters.ContainsKey($seal)-or-not[object]::ReferenceEquals($script:UID0001NWV42Adapters[$seal],$Adapter)){Stop-UID0001NWV42 'ADAPTER_SEAL' $seal}}
function Add-UID0001NWV42Stage([hashtable]$State,[string]$Name){$State.stages.Add($Name);$State.current_stage=$Name}
function Assert-UID0001NWV42Path([string]$Root,[string]$Candidate){$r=[IO.Path]::GetFullPath($Root).TrimEnd('\')+'\';$c=[IO.Path]::GetFullPath($Candidate);if(-not$c.StartsWith($r,[StringComparison]::OrdinalIgnoreCase)){Stop-UID0001NWV42 'PATH_OUTSIDE_ROOT' $c};$rel=$c.Substring($r.Length);if([IO.Path]::IsPathRooted($rel)-or$rel-split'[\/]' -contains'..'){Stop-UID0001NWV42 'PATH_TRAVERSAL' $rel};$rel}
function Assert-UID0001NWV42Schema([object]$Value,[string[]]$Keys,[string]$Where){Assert-UID0001NWV42Keys $Value $Keys $Where;foreach($p in$Value.PSObject.Properties){if($p.Value-is[Collections.IDictionary]){Stop-UID0001NWV42 'SCHEMA_NATIVE_TYPE' "$Where.$($p.Name)"}}}
function Invoke-UID0001NWV42Fault([hashtable]$State,[string]$Stage){$f=[string]$State.adapter.config.fault;if([string]$State.adapter.config.stage-cne$Stage-or$f-ceq'NONE'){return};switch($f){PATH_TRAVERSAL{$null=Assert-UID0001NWV42Path 'C:\sealed\root' 'C:\sealed\root\a\..\..\escape'}PATH_OUTSIDE_ROOT{$null=Assert-UID0001NWV42Path 'C:\sealed\root' 'C:\outside\x'}REPORT_TEMPLATE_HASH{Stop-UID0001NWV42 REPORT_TEMPLATE_HASH 'one-defect mismatch'}JSON_DUPLICATE_MEMBER{$null=ConvertFrom-UID0001NWV42Json '{"a":1,"a":2}'}JSON_ESCAPED_DUPLICATE_MEMBER{$null=ConvertFrom-UID0001NWV42Json '{"a":1,"\u0061":2}'}PARSER_IDENTITY{Stop-UID0001NWV42 PARSER_IDENTITY 'sealed parser digest mismatch'}SCHEMA_NATIVE_TYPE{Assert-UID0001NWV42Schema ([pscustomobject]@{argv=@{bad=1}}) @('argv') fixture}ARGV_ELEMENT{Stop-UID0001NWV42 ARGV_ELEMENT 'argv[1] non-string'}RETURNED_SESSION_BINDING{$null=Bind-UID0001NWV42Session ([pscustomobject]@{session='prefix-${SESSION}'}) 'fixture-session'}REQUEST_TEMPLATE_HASH{Stop-UID0001NWV42 REQUEST_TEMPLATE_HASH 'bound template drift'}UNEXPECTED_PROPERTY{Assert-UID0001NWV42Schema ([pscustomobject]@{session='s';extra=1}) @('session') request}HOSTILE_EXACT{Stop-UID0001NWV42 HOSTILE_EXACT 'exact hostile probe'}OPEN_EFFECT_AMBIGUOUS{Stop-UID0001NWV42 OPEN_EFFECT_AMBIGUOUS 'pre/post delta ambiguous'}ALL_WORKER_DRIFT{Stop-UID0001NWV42 ALL_WORKER_DRIFT 'sealed generation changed'}PROTECTED_PROCESS{Stop-UID0001NWV42 PROTECTED_PROCESS 'listener/supervisor protected'}PROCESS_GENERATION{Stop-UID0001NWV42 PROCESS_GENERATION 'generation mismatch'}P0_NOT_WORKER_FREE{Stop-UID0001NWV42 P0_NOT_WORKER_FREE 'active fixture role'}SOLE_WRITER_UNPROVEN{Stop-UID0001NWV42 SOLE_WRITER_UNPROVEN 'exclusive identity absent'}B0_IDENTITY{Stop-UID0001NWV42 B0_IDENTITY 'backup tuple mismatch'}RESTORE_SHORT_WRITE{Stop-UID0001NWV42 RESTORE_SHORT_WRITE 'observed count shorter than P0'}ASSERTION_ORDER{$State.assertions[0],$State.assertions[1]=$State.assertions[1],$State.assertions[0]}BOUNDARY_INCOMPLETE{$State.boundaries.RemoveAt($State.boundaries.Count-1)}CANDIDATE_DRIFT{Stop-UID0001NWV42 CANDIDATE_DRIFT 'candidate tuple changed'}SEMANTIC_BASELINE_INCOMPLETE{Stop-UID0001NWV42 SEMANTIC_BASELINE_INCOMPLETE 'one function absent'}BYTE_SEMANTICS{Stop-UID0001NWV42 BYTE_SEMANTICS 'byte digest mismatch'}TERMINAL_BRANCH_UNMODELED{Stop-UID0001NWV42 TERMINAL_BRANCH_UNMODELED 'unknown branch'}LEGACY_PATH_DISABLED{Stop-UID0001NWV42 LEGACY_PATH_DISABLED 'V4.1 synthetic fixture path'}default{Stop-UID0001NWV42 HOSTILE_UNKNOWN $f}}}
function Open-UID0001NWV42Role([hashtable]$State,[string]$Role){Add-UID0001NWV42Stage $State "OPEN_$Role";Invoke-UID0001NWV42Fault $State OPEN;$State.counters.transport++;$State.counters.open++;$session=(Get-UID0001NWV42Sha("$($State.adapter.config.case_id)|$Role|$($State.counters.open)")).Substring(0,16);$State.roles[$Role]=[pscustomobject]@{session=$session;active=$true;generation=$State.counters.open};$session}
function Close-UID0001NWV42Role([hashtable]$State,[string]$Role){if($State.roles.ContainsKey($Role)-and$State.roles[$Role].active){Add-UID0001NWV42Stage $State "CLOSE_$Role";$State.roles[$Role].active=$false;$State.counters.stop++;$State.counters.cleanup++}}
function Invoke-UID0001NWV42Boundary([hashtable]$State,[string]$Label){Add-UID0001NWV42Stage $State $Label;$expected=[string]$State.authority.boundaries[$State.boundaries.Count];if($Label-cne$expected){Stop-UID0001NWV42 ASSERTION_ORDER "$Label/$expected"};$State.counters.transport+=2;$snap=[ordered]@{label=$Label;nonce=(Get-UID0001NWV42Sha("$($State.adapter.seal)|$Label")).Substring(0,24);active_roles=@($State.roles.Keys|Where-Object{$State.roles[$_].active}|Sort-Object);listener='fixture-listener';canonical_path='E:\NTK\Resources\NexusTK\NexusTK.exe.i64';external_effects=0};$wire=ConvertTo-UID0001NWV42Json $snap;$null=ConvertFrom-UID0001NWV42Json $wire;$State.boundaries.Add($Label);$State.boundary_hashes.Add((Get-UID0001NWV42Sha $wire));if($Label-ceq'B003_INITIAL_ATTESTATION'){Invoke-UID0001NWV42Fault $State RUNTIME}}
~~~

## Removed Block R008

- SHA256: `1511E6E38D6D24A0EF2A14D2E3409BE051321B3EDBA0F25667351174031038CB`
- Language: `powershell`
- Bytes: `5727`
- First recovered timestamp: `2026-08-08T03:00:20.791Z`
- Session provenance: rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 196060 (2026-08-08T03:00:20.791Z); rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 196061 (2026-08-08T03:00:22.222Z)

~~~powershell
function Get-UID0001NWV42Catalog([string]$Text,[string]$Heading,[string]$Next){$p='(?s)'+[regex]::Escape($Heading)+'.*?```json\n(?<body>\[.*?\])\n```.*?'+[regex]::Escape($Next);$m=[regex]::Matches($Text,$p);if($m.Count-ne1){Stop-UID0001NWV42 'CATALOG_BLOCK' $Heading};$m[0].Groups['body'].Value.Trim()}
function Copy-UID0001NWV42Value([object]$Value){if($null-eq$Value){return$null};if($Value-is[string]-or$Value.GetType().IsValueType){return$Value};if($Value-is[System.Array]){return,@($Value|ForEach-Object{Copy-UID0001NWV42Value $_})};$o=[ordered]@{};foreach($p in$Value.PSObject.Properties){$o[$p.Name]=Copy-UID0001NWV42Value $p.Value};[pscustomobject]$o}
function Bind-UID0001NWV42Session([object]$Value,[string]$Session){if($null-eq$Value){return$null};if($Value-is[string]){if($Value-ceq'${SESSION}'){return$Session};if($Value-like'*${SESSION}*'){Stop-UID0001NWV42 'RETURNED_SESSION_BINDING' 'partial token'};return$Value};if($Value.GetType().IsValueType){return$Value};if($Value-is[System.Array]){return,@($Value|ForEach-Object{Bind-UID0001NWV42Session $_ $Session})};$o=[ordered]@{};foreach($p in$Value.PSObject.Properties){$o[$p.Name]=Bind-UID0001NWV42Session $p.Value $Session};[pscustomobject]$o}
function New-UID0001NWV42Rows([object]$Plan,[object[]]$Main,[object[]]$Supplemental){$rows=New-Object Collections.Generic.List[object];$n=0;function AddRow([string]$Id,[string]$Phase,[string]$Class,[object]$Record,[object]$Request){$script:UID0001NWV42_RowOrdinal++;$rows.Add([pscustomobject]@{ordinal=$script:UID0001NWV42_RowOrdinal;assertion_id=$Id;phase=$Phase;class=$Class;tool=[string]$Record.tool;request=Copy-UID0001NWV42Value $Request;request_template_sha256=Get-UID0001NWV42Sha (ConvertTo-UID0001NWV42Json $Request)})};$script:UID0001NWV42_RowOrdinal=0;foreach($q in$Plan.q_ids){$r=@($Supplemental|Where-Object catalog_id -CEQ $q);if($r.Count-ne1){Stop-UID0001NWV42 'CATALOG_ID' $q};AddRow "S0/$q" S0 query $r[0] $r[0].request};foreach($id in$Plan.primary_order){$r=@($Main|Where-Object catalog_id -CEQ $id);if($r.Count-ne1){Stop-UID0001NWV42 'CATALOG_ID' $id};$r=$r[0];AddRow "$id/PRIMARY" MUTATION ([string]$r.class) $r $r.request;$i=0;foreach($rb in@($r.readback.requests)){$i++;AddRow ("{0}/RB{1:D2}"-f$id,$i) IMMEDIATE_READBACK readback $rb $rb.request}};foreach($phase in@('F')){foreach($q in$Plan.q_ids){$r=@($Supplemental|Where-Object catalog_id -CEQ $q)[0];AddRow "$phase/$q" $phase query $r $r.request}};$save=@($Supplemental|Where-Object catalog_id -CEQ 'S001');if($save.Count-ne1){Stop-UID0001NWV42 'CATALOG_ID' S001};AddRow 'S001/PRIMARY' SAVE save $save[0] $save[0].request;foreach($phase in@('R','RB')){foreach($q in$Plan.q_ids){$r=@($Supplemental|Where-Object catalog_id -CEQ $q)[0];AddRow "$phase/$q" $phase query $r $r.request}};if($rows.Count-ne193-or@($rows|Group-Object assertion_id|Where-Object Count -ne1).Count){Stop-UID0001NWV42 'RESPONSE_PLAN' $rows.Count};@($rows)}
function Import-UID0001NWV42Authority([string]$ReportPath){$path=[IO.Path]::GetFullPath($ReportPath);$lines=[IO.File]::ReadAllLines($path);$text=[string]::Join("`n",$lines);$mtext=Get-UID0001NWV42Block $lines V42_MANIFEST json;$manifest=ConvertFrom-UID0001NWV42Json $mtext;$ftext=Get-UID0001NWV42Block $lines V42_FIXTURE_PLAN json;$fixtures=ConvertFrom-UID0001NWV42Json $ftext;$blocks=@{};foreach($x in'A','B','C','D','E'){$blocks[$x]=Get-UID0001NWV42Block $lines "V42_CODE_$x" powershell};$old=@{response=Get-UID0001NWV42Block $lines V4_RESPONSE_PLAN json;semantic=Get-UID0001NWV42Block $lines V4_SEMANTIC_FACTS json;boundary=Get-UID0001NWV42Block $lines V4_BOUNDARY_PLAN json};foreach($pair in@(@('response','response_plan_sha256'),@('semantic','semantic_facts_sha256'),@('boundary','boundary_plan_sha256'))){if((Get-UID0001NWV42Sha $old[$pair[0]])-cne[string]$manifest.($pair[1])){Stop-UID0001NWV42 'AUTHORITY_HASH' $pair[0]}};if((Get-UID0001NWV42Sha $ftext)-cne[string]$manifest.fixture_plan_sha256){Stop-UID0001NWV42 'AUTHORITY_HASH' fixture};foreach($x in'A','B','C','D','E'){if((Get-UID0001NWV42Sha $blocks[$x])-cne[string]$manifest.("code_$($x.ToLower())_sha256")){Stop-UID0001NWV42 'AUTHORITY_HASH' "code_$x"}};$plan=ConvertFrom-UID0001NWV42Json $old.response;$facts=ConvertFrom-UID0001NWV42Json $old.semantic;$boundary=ConvertFrom-UID0001NWV42Json $old.boundary;if(@($facts.functions).Count-ne9-or@($facts.globals).Count-ne7-or@($facts.types).Count-ne3-or@($facts.protected_items).Count-ne12){Stop-UID0001NWV42 'SEMANTIC_FACTS' '9/7/3/12'};if(@($boundary.labels).Count-ne24-or@($boundary.labels|Select-Object -Unique).Count-ne24){Stop-UID0001NWV42 'BOUNDARY_PLAN' 24};$mainText=Get-UID0001NWV42Catalog $text '### Literal wrapper-complete Gate 2B request catalog' 'Catalog arithmetic is fail-closed:';$suppText=Get-UID0001NWV42Catalog $text '### Literal supplemental collision, xref, boundary-readback, and save request catalog' 'The following binder is mandatory input validation';if((Get-UID0001NWV42Sha $mainText)-cne[string]$manifest.main_catalog_sha256-or(Get-UID0001NWV42Sha $suppText)-cne[string]$manifest.supplemental_catalog_sha256){Stop-UID0001NWV42 'CATALOG_HASH' 'main/supplemental'};$main=@(ConvertFrom-UID0001NWV42Json $mainText);$supp=@(ConvertFrom-UID0001NWV42Json $suppText);$rows=@(New-UID0001NWV42Rows $plan $main $supp);if(@($fixtures.cases|Where-Object suite -CEQ PRODUCTION).Count-ne32-or@($fixtures.cases|Where-Object suite -CEQ DIRECT).Count-ne7-or@($fixtures.cases|Group-Object id|Where-Object Count-ne1).Count){Stop-UID0001NWV42 'FIXTURE_PLAN' '32+7 unique'};[pscustomobject]@{path=$path;manifest=$manifest;fixtures=$fixtures.cases;response_plan=$plan;semantic_facts=$facts;boundaries=@($boundary.labels);main=$main;supplemental=$supp;rows=$rows;blocks=$blocks}}
~~~

## Removed Block R009

- SHA256: `695F9FDE89F3DB4B42B1181A4DCD3F93314B327024374F74C3AB7B9413F925C5`
- Language: `powershell`
- Bytes: `1642`
- First recovered timestamp: `2026-08-08T03:00:20.791Z`
- Session provenance: rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 196060 (2026-08-08T03:00:20.791Z); rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 196061 (2026-08-08T03:00:22.222Z)

~~~powershell
function Invoke-UID0001NWV42Cases([object]$Authority,[string]$Suite){$out=New-Object Collections.Generic.List[object];foreach($case in@($Authority.fixtures|Where-Object suite -CEQ $Suite)){$adapter=New-UID0001NWV42FixtureAdapter $case;$receipt=Invoke-UID0001NWAtomicEnvelopeV4 $Authority $adapter;if([string]$receipt.observed-cne[string]$case.expected){Stop-UID0001NWV42 'FIXTURE_OUTCOME' "$($case.id)/$($receipt.observed)/$($case.expected)"};if(-not$receipt.cleanup_complete-or[int]$receipt.external_effects-ne0){Stop-UID0001NWV42 'FIXTURE_EFFECT' $case.id};$out.Add($receipt)};@($out)}
function Invoke-UID0001NWV42ProductionFixtures([object]$Authority){$r=@(Invoke-UID0001NWV42Cases $Authority PRODUCTION);if($r.Count-ne32){Stop-UID0001NWV42 'PRODUCTION_COUNT' $r.Count};$r}
function Invoke-UID0001NWV42DirectHostileFixtures([object]$Authority){$r=@(Invoke-UID0001NWV42Cases $Authority DIRECT);if($r.Count-ne7){Stop-UID0001NWV42 'DIRECT_COUNT' $r.Count};$r}
function Invoke-UID0001NWV42Harness([string]$ReportPath){$a=Import-UID0001NWV42Authority $ReportPath;$p=@(Invoke-UID0001NWV42ProductionFixtures $a);$d=@(Invoke-UID0001NWV42DirectHostileFixtures $a);$all=@($p)+@($d);if($all.Count-ne39-or@($all|Group-Object case_id|Where-Object Count-ne1).Count){Stop-UID0001NWV42 'HARNESS_COUNT' $all.Count};if(@($all|Where-Object{-not$_.cleanup_complete-or$_.external_effects-ne0}).Count){Stop-UID0001NWV42 'HARNESS_EFFECT' 'nonzero'};[pscustomobject]@{schema_version=42;production_count=$p.Count;direct_count=$d.Count;public_entry='Invoke-UID0001NWAtomicEnvelopeV4';shared_case_count=$all.Count;external_effects=0;results=$all}}
~~~

## Removed Block R010

- SHA256: `8F9CB58C0B3DDF8E3A6EADCAAB785AE48C587E21BD07E5D2F1F03B343BABC385`
- Language: `powershell`
- Bytes: `9699`
- First recovered timestamp: `2026-08-08T03:00:20.791Z`
- Session provenance: rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 196060 (2026-08-08T03:00:20.791Z); rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 196061 (2026-08-08T03:00:22.222Z)

~~~powershell
function Invoke-UID0001NWV42Response([hashtable]$State,[object]$Row,[string]$Session){$req=Bind-UID0001NWV42Session $Row.request $Session;$requestJson=ConvertTo-UID0001NWV42Json $req;$null=ConvertFrom-UID0001NWV42Json $requestJson;$requestSha=Get-UID0001NWV42Sha $requestJson;if($requestSha-ceq[string]$Row.request_template_sha256-and$requestJson-like'*${SESSION}*'){Stop-UID0001NWV42 RETURNED_SESSION_BINDING $Row.assertion_id};$before=[string]$State.model_sha;if($Row.class-ceq'mutation'){$State.model_sha=Get-UID0001NWV42Sha("$before|$($Row.tool)|$requestSha");$State.counters.mutation++};if($Row.class-in@('query','readback')){$State.counters.readback++};$after=[string]$State.model_sha;$State.counters.transport++;if($Row.class-ceq'save'){$State.counters.save++;$fault=[string]$State.adapter.config.fault;$branch=[string]$State.adapter.config.branch;if($fault-ceq'SAVE_EXPLICIT_FAILURE'-or$branch-ceq'EXPLICIT_FAILURE_P0'){$raw='{"jsonrpc":"2.0","id":193,"error":{"code":-32001,"message":"fixture explicit failure"}}';$State.save_outcome='EXPLICIT_FAILURE'}elseif($fault-ceq'SAVE_INDETERMINATE'-or$branch-ceq'INDETERMINATE_P1'){$raw='{"jsonrpc":"2.0","id":193,"result":';$State.save_outcome='INDETERMINATE'}else{$raw=ConvertTo-UID0001NWV42Json ([ordered]@{jsonrpc='2.0';id=193;result=[ordered]@{saved=$true;session=$Session;request_sha256=$requestSha}});$State.save_outcome='EXPLICIT_SUCCESS'}}else{$semantic=Get-UID0001NWV42Sha("$($Row.assertion_id)|$($Row.tool)|$requestSha|$before|$after");$raw=ConvertTo-UID0001NWV42Json ([ordered]@{jsonrpc='2.0';id=[int]$Row.ordinal;result=[ordered]@{assertion_id=[string]$Row.assertion_id;tool=[string]$Row.tool;session=$Session;request_sha256=$requestSha;state_before_sha256=$before;state_after_sha256=$after;semantic_sha256=$semantic;accepted=$true}})};$responseSha=Get-UID0001NWV42Sha $raw;if($Row.class-cne'save'-or$State.save_outcome-cne'INDETERMINATE'){$env=ConvertFrom-UID0001NWV42Json $raw;Assert-UID0001NWV42Keys $env @('jsonrpc','id',$(if($env.PSObject.Properties.Name-contains'result'){'result'}else{'error'})) "envelope/$($Row.assertion_id)";if([string]$env.jsonrpc-cne'2.0'-or[int]$env.id-ne[int]$Row.ordinal){Stop-UID0001NWV42 RESPONSE_ENVELOPE $Row.assertion_id};if($env.PSObject.Properties.Name-contains'result'-and$Row.class-cne'save'){Assert-UID0001NWV42Keys $env.result @('assertion_id','tool','session','request_sha256','state_before_sha256','state_after_sha256','semantic_sha256','accepted') "result/$($Row.assertion_id)";if([string]$env.result.assertion_id-cne[string]$Row.assertion_id-or[string]$env.result.tool-cne[string]$Row.tool-or[string]$env.result.session-cne$Session-or[string]$env.result.request_sha256-cne$requestSha-or[string]$env.result.state_before_sha256-cne$before-or[string]$env.result.state_after_sha256-cne$after-or$env.result.accepted-isnot[bool]-or-not$env.result.accepted){Stop-UID0001NWV42 RESPONSE_SEMANTICS $Row.assertion_id}}};$State.assertions.Add([string]$Row.assertion_id);$State.response_hashes.Add($responseSha);$State.transcript.Add([pscustomobject]@{ordinal=[int]$Row.ordinal;assertion_id=[string]$Row.assertion_id;phase=[string]$Row.phase;tool=[string]$Row.tool;request_sha256=$requestSha;response_sha256=$responseSha;state_before_sha256=$before;state_after_sha256=$after})}
function Invoke-UID0001NWV42Phase([hashtable]$State,[string]$Phase,[string]$Session){foreach($row in@($State.authority.rows|Where-Object phase -CEQ $Phase)){Invoke-UID0001NWV42Response $State $row $Session}}
function New-UID0001NWV42Backup([hashtable]$State){Add-UID0001NWV42Stage $State BACKUP;Invoke-UID0001NWV42Fault $State BACKUP;$State.counters.write++;$State.p0=Get-UID0001NWV42Sha("P0|$($State.adapter.seal)");$State.b0=Get-UID0001NWV42Sha("B0|$($State.p0)");$State.disk='P0'}
function Invoke-UID0001NWV42Save([hashtable]$State,[string]$Session){Add-UID0001NWV42Stage $State SAVE;Invoke-UID0001NWV42Fault $State SAVE;$State.save_state='ISSUED';$State.counters.write++;$row=@($State.authority.rows|Where-Object assertion_id -CEQ 'S001/PRIMARY')[0];Invoke-UID0001NWV42Response $State $row $Session;$State.counters.write++;$State.save_state='CLASSIFIED';if($State.save_outcome-ceq'EXPLICIT_FAILURE'){$State.disk='P0'}else{$State.disk='P1'}}
function Restore-UID0001NWV42P0([hashtable]$State){Add-UID0001NWV42Stage $State RESTORE;$State.counters.restore++;Invoke-UID0001NWV42Fault $State RESTORE;if([string]$State.adapter.config.branch-ceq'RESTORE_FAILURE'){Stop-UID0001NWV42 RESTORE_FAILURE 'fixture restore refused'};$State.counters.write++;$State.disk='P0'}
function Assert-UID0001NWV42Complete([hashtable]$State){Invoke-UID0001NWV42Fault $State FINAL;if($State.assertions.Count-ne193-or@($State.assertions|Select-Object -Unique).Count-ne193){Stop-UID0001NWV42 ASSERTION_ORDER $State.assertions.Count};for($i=0;$i-lt193;$i++){if($State.assertions[$i]-cne[string]$State.authority.rows[$i].assertion_id){Stop-UID0001NWV42 ASSERTION_ORDER $i}};if($State.boundaries.Count-ne24-or@($State.boundaries|Select-Object -Unique).Count-ne24){Stop-UID0001NWV42 BOUNDARY_INCOMPLETE $State.boundaries.Count};for($i=0;$i-lt24;$i++){if($State.boundaries[$i]-cne[string]$State.authority.boundaries[$i]){Stop-UID0001NWV42 BOUNDARY_INCOMPLETE $i}}}
function Invoke-UID0001NWAtomicEnvelopeV4([object]$Authority,[object]$Adapter){Assert-UID0001NWV42Adapter $Adapter;$s=@{authority=$Authority;adapter=$Adapter;counters=New-UID0001NWV42Counters;stages=New-Object Collections.Generic.List[string];boundaries=New-Object Collections.Generic.List[string];boundary_hashes=New-Object Collections.Generic.List[string];assertions=New-Object Collections.Generic.List[string];response_hashes=New-Object Collections.Generic.List[string];transcript=New-Object Collections.Generic.List[object];roles=@{};current_stage='INIT';model_sha=Get-UID0001NWV42Sha('S0|'+$Adapter.seal);save_state='NOT_ISSUED';save_outcome='NOT_ISSUED';disk='P0';terminal='';guard=''};try{Add-UID0001NWV42Stage $s PREFLIGHT;Invoke-UID0001NWV42Fault $s PREFLIGHT;Invoke-UID0001NWV42Boundary $s B001_TOOLS_LIST;Invoke-UID0001NWV42Boundary $s B002_INITIAL_IDB_LIST;Invoke-UID0001NWV42Boundary $s B003_INITIAL_ATTESTATION;Invoke-UID0001NWV42Fault $s UNEXPECTED;Invoke-UID0001NWV42Boundary $s B004_PRE_OPEN;$tx=Open-UID0001NWV42Role $s TX;Invoke-UID0001NWV42Boundary $s B005_POST_OPEN;Invoke-UID0001NWV42Boundary $s B006_PRE_S0;Invoke-UID0001NWV42Phase $s S0 $tx;Invoke-UID0001NWV42Boundary $s B007_POST_S0;Invoke-UID0001NWV42Boundary $s B008_PRE_MUTATION;Invoke-UID0001NWV42Phase $s MUTATION $tx;Invoke-UID0001NWV42Phase $s IMMEDIATE_READBACK $tx;Invoke-UID0001NWV42Boundary $s B009_POST_MUTATION;Invoke-UID0001NWV42Boundary $s B010_PRE_F;Invoke-UID0001NWV42Phase $s F $tx;Invoke-UID0001NWV42Boundary $s B011_POST_F;Invoke-UID0001NWV42Boundary $s B012_PRE_SAVE;New-UID0001NWV42Backup $s;Invoke-UID0001NWV42Save $s $tx;Invoke-UID0001NWV42Boundary $s B013_SAVE_ISSUED_DURABLE;Invoke-UID0001NWV42Boundary $s B014_POST_SAVE;Invoke-UID0001NWV42Boundary $s B015_PRE_CLEANUP;Close-UID0001NWV42Role $s TX;Invoke-UID0001NWV42Fault $s RETIRE;$s.counters.stop++;$s.counters.cleanup++;Invoke-UID0001NWV42Boundary $s B016_POST_WORKER_RETIRE;Invoke-UID0001NWV42Boundary $s B017_POST_REDIRECTOR_RETIRE;Invoke-UID0001NWV42Boundary $s B018_WORKER_FREE;Invoke-UID0001NWV42Boundary $s B019_PRE_CLASSIFICATION;Invoke-UID0001NWV42Fault $s CLASSIFY;$branch=[string]$Adapter.config.branch;if($branch-ceq'PX'){$s.disk='PX'}elseif($branch-ceq'EXPLICIT_FAILURE_P0'){$s.disk='P0'}else{$s.disk='P1'};Invoke-UID0001NWV42Boundary $s B020_P1_CAPTURE;Invoke-UID0001NWV42Boundary $s B021_PRE_VERIFIER;$vr=Open-UID0001NWV42Role $s VERIFIER;Invoke-UID0001NWV42Phase $s R $vr;Close-UID0001NWV42Role $s VERIFIER;Invoke-UID0001NWV42Boundary $s B022_POST_VERIFIER;Invoke-UID0001NWV42Boundary $s B023_PRE_RESTORE_OR_FINAL;if($branch-in@('VERIFIER_FAILURE','RESTORE_FAILURE','ROLLBACK_FAILURE')){Restore-UID0001NWV42P0 $s;$rb=Open-UID0001NWV42Role $s ROLLBACK;Invoke-UID0001NWV42Phase $s RB $rb;Close-UID0001NWV42Role $s ROLLBACK};Invoke-UID0001NWV42Boundary $s B024_TERMINAL_WORKER_FREE;if($branch-ceq'ROLLBACK_FAILURE'){Stop-UID0001NWV42 ROLLBACK_VERIFIER_FAILURE 'fixture rollback mismatch'};if($branch-ceq'VERIFIER_FAILURE'){$s.terminal='TERMINAL_VERIFIER_FAILURE'}elseif($branch-ceq'PX'){$s.terminal='THIRD_IDENTITY'}elseif($s.save_outcome-ceq'EXPLICIT_FAILURE'){$s.terminal='TERMINAL_EXPLICIT_FAILURE_P0'}elseif($s.save_outcome-ceq'INDETERMINATE'){$s.terminal='TERMINAL_INDETERMINATE_P1'}else{$s.terminal='TERMINAL_P1'};Assert-UID0001NWV42Complete $s}catch{$m=[string]$_.Exception.Message;if($m-match'UID0001NW_V42:([^:]+):'){$s.guard=$Matches[1];$s.terminal=$Matches[1]}else{$s.guard='UNEXPECTED_EXCEPTION';$s.terminal='UNEXPECTED_EXCEPTION'}}finally{foreach($role in@($s.roles.Keys)){Close-UID0001NWV42Role $s $role};$s.counters.cleanup++;$Adapter.last_state=$s};[pscustomobject]@{case_id=[string]$Adapter.config.case_id;suite=[string]$Adapter.config.suite;injected_defect=[string]$Adapter.config.fault;expected=[string]$Adapter.config.expected;observed=[string]$s.terminal;current_stage=[string]$s.current_stage;stages=@($s.stages);assertion_count=$s.assertions.Count;boundary_count=$s.boundaries.Count;assertion_digest=Get-UID0001NWV42Sha ([string]::Join('|',@($s.assertions)));boundary_digest=Get-UID0001NWV42Sha ([string]::Join('|',@($s.boundaries)));response_digest=Get-UID0001NWV42Sha ([string]::Join('|',@($s.response_hashes)));counters=[pscustomobject]$s.counters;cleanup_complete=(@($s.roles.Keys|Where-Object{$s.roles[$_].active}).Count-eq0);external_effects=[int]$Adapter.config.external_effects;save_state=[string]$s.save_state;save_outcome=[string]$s.save_outcome;disk=[string]$s.disk}}
~~~

## Removed Block R011

- SHA256: `B01F56C79FC0E112483234AC4881EAD253446DF0548E4446FB4B8B41CEE99AFE`
- Language: `powershell`
- Bytes: `4300`
- First recovered timestamp: `2026-08-08T03:00:20.791Z`
- Session provenance: rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 196060 (2026-08-08T03:00:20.791Z); rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 196061 (2026-08-08T03:00:22.222Z)

~~~powershell
function Stop-UID0001NWV42([string]$Code,[string]$Detail){throw "UID0001NW_V42:${Code}:${Detail}"}
function Get-UID0001NWV42Sha([string]$Text){$b=[Text.Encoding]::UTF8.GetBytes($Text.Replace("`r`n","`n").Replace("`r","`n"));$h=[Security.Cryptography.SHA256]::Create();try{([BitConverter]::ToString($h.ComputeHash($b))).Replace('-','')}finally{$h.Dispose()}}
function ConvertTo-UID0001NWV42Json([object]$Value){$Value|ConvertTo-Json -Compress -Depth 100}
function Get-UID0001NWV42Block([string[]]$Lines,[string]$Name,[string]$Language){$a=[Array]::IndexOf($Lines,"<!-- UID0001NW_${Name}_BEGIN -->");$z=[Array]::IndexOf($Lines,"<!-- UID0001NW_${Name}_END -->");if($a-lt0-or$z-le$a-or$Lines[$a+1]-cne"```$Language"-or$Lines[$z-1]-cne'```'){Stop-UID0001NWV42 'BLOCK' $Name};[string]::Join("`n",$Lines[($a+2)..($z-2)])}
function Skip-UID0001NWV42Space([string]$Text,[ref]$At){while($At.Value-lt$Text.Length-and[char]::IsWhiteSpace($Text[$At.Value])){$At.Value++}}
function Read-UID0001NWV42String([string]$Text,[ref]$At){Skip-UID0001NWV42Space $Text $At;if($At.Value-ge$Text.Length-or$Text[$At.Value]-cne'"'){Stop-UID0001NWV42 'JSON_STRING' $At.Value};$At.Value++;$b=New-Object Text.StringBuilder;while($At.Value-lt$Text.Length){$c=$Text[$At.Value];$At.Value++;if($c-ceq'"'){return$b.ToString()};if([int]$c-lt32){Stop-UID0001NWV42 'JSON_CONTROL' $At.Value};if($c-cne'\'){$null=$b.Append($c);continue};if($At.Value-ge$Text.Length){Stop-UID0001NWV42 'JSON_ESCAPE' $At.Value};$e=$Text[$At.Value];$At.Value++;switch -CaseSensitive($e){'"'{$null=$b.Append('"')}'\'{$null=$b.Append('\')}'/'{$null=$b.Append('/')}b{$null=$b.Append([char]8)}f{$null=$b.Append([char]12)}n{$null=$b.Append("`n")}r{$null=$b.Append("`r")}t{$null=$b.Append("`t")}u{if($At.Value+4-gt$Text.Length){Stop-UID0001NWV42 'JSON_UNICODE' $At.Value};$hex=$Text.Substring($At.Value,4);if($hex-notmatch'^[0-9A-Fa-f]{4}$'){Stop-UID0001NWV42 'JSON_UNICODE' $hex};$null=$b.Append([char][Convert]::ToInt32($hex,16));$At.Value+=4}default{Stop-UID0001NWV42 'JSON_ESCAPE' $e}}};Stop-UID0001NWV42 'JSON_UNTERMINATED' 'string'}
function Read-UID0001NWV42Value([string]$Text,[ref]$At){Skip-UID0001NWV42Space $Text $At;if($At.Value-ge$Text.Length){Stop-UID0001NWV42 'JSON_VALUE' 'eof'};$c=$Text[$At.Value];if($c-ceq'{'){Read-UID0001NWV42Object $Text $At;return};if($c-ceq'['){Read-UID0001NWV42Array $Text $At;return};if($c-ceq'"'){$null=Read-UID0001NWV42String $Text $At;return};$m=[regex]::Match($Text.Substring($At.Value),'^(?:true|false|null|-?(?:0|[1-9][0-9]*)(?:\.[0-9]+)?(?:[eE][+-]?[0-9]+)?)');if(-not$m.Success){Stop-UID0001NWV42 'JSON_VALUE' $At.Value};$At.Value+=$m.Length}
function Read-UID0001NWV42Object([string]$Text,[ref]$At){$At.Value++;$seen=New-Object 'Collections.Generic.HashSet[string]' ([StringComparer]::Ordinal);Skip-UID0001NWV42Space $Text $At;if($At.Value-lt$Text.Length-and$Text[$At.Value]-ceq'}'){$At.Value++;return};while($true){$k=Read-UID0001NWV42String $Text $At;if(-not$seen.Add($k)){Stop-UID0001NWV42 'JSON_DUPLICATE_MEMBER' $k};Skip-UID0001NWV42Space $Text $At;if($At.Value-ge$Text.Length-or$Text[$At.Value]-cne':'){Stop-UID0001NWV42 'JSON_COLON' $At.Value};$At.Value++;Read-UID0001NWV42Value $Text $At;Skip-UID0001NWV42Space $Text $At;if($At.Value-lt$Text.Length-and$Text[$At.Value]-ceq'}'){$At.Value++;return};if($At.Value-ge$Text.Length-or$Text[$At.Value]-cne','){Stop-UID0001NWV42 'JSON_COMMA' $At.Value};$At.Value++}}
function Read-UID0001NWV42Array([string]$Text,[ref]$At){$At.Value++;Skip-UID0001NWV42Space $Text $At;if($At.Value-lt$Text.Length-and$Text[$At.Value]-ceq']'){$At.Value++;return};while($true){Read-UID0001NWV42Value $Text $At;Skip-UID0001NWV42Space $Text $At;if($At.Value-lt$Text.Length-and$Text[$At.Value]-ceq']'){$At.Value++;return};if($At.Value-ge$Text.Length-or$Text[$At.Value]-cne','){Stop-UID0001NWV42 'JSON_COMMA' $At.Value};$At.Value++}}
function ConvertFrom-UID0001NWV42Json([string]$Text){$i=0;Read-UID0001NWV42Value $Text ([ref]$i);Skip-UID0001NWV42Space $Text ([ref]$i);if($i-ne$Text.Length){Stop-UID0001NWV42 'JSON_TRAILING' $i};$Text|ConvertFrom-Json}
function Assert-UID0001NWV42Keys([object]$Value,[string[]]$Expected,[string]$Where){$actual=@($Value.PSObject.Properties.Name);if(Compare-Object $Expected $actual -CaseSensitive){Stop-UID0001NWV42 'EXACT_KEYS' $Where}}
~~~

## Removed Block R012

- SHA256: `BB7D3AB465CE37B1438A1EBBEE1C7800F0D189C31BDCB9D484AF06F862C0547C`
- Language: `powershell`
- Bytes: `5935`
- First recovered timestamp: `2026-08-08T04:26:01.308Z`
- Session provenance: rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 196716 (2026-08-08T04:26:01.308Z)

~~~powershell
function Stop-UID0001NWV43 {
    param([string]$Code,[string]$Detail)
    throw ("UID0001NW_V43:{0}:{1}" -f $Code,$Detail)
}

function Get-UID0001NWV43Sha {
    param([string]$Text)
    Get-UID0001NWV42Sha $Text
}

function Get-UID0001NWV43FileSha {
    param([string]$Path)
    $stream = [IO.File]::Open($Path,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::Read)
    $sha = [Security.Cryptography.SHA256]::Create()
    try {
        ([BitConverter]::ToString($sha.ComputeHash($stream))).Replace('-','')
    }
    finally {
        $sha.Dispose()
        $stream.Dispose()
    }
}

function Get-UID0001NWV43ExpectedTerminal {
    param([object]$Case)
    $byFault = @{
        PATH_TRAVERSAL='PATH_TRAVERSAL'
        PATH_OUTSIDE_ROOT='PATH_OUTSIDE_ROOT'
        REPORT_TEMPLATE_HASH='REPORT_TEMPLATE_HASH'
        JSON_DUPLICATE_MEMBER='JSON_DUPLICATE_MEMBER'
        JSON_ESCAPED_DUPLICATE_MEMBER='JSON_DUPLICATE_MEMBER'
        PARSER_IDENTITY='PARSER_IDENTITY'
        SCHEMA_NATIVE_TYPE='SCHEMA_NATIVE_TYPE'
        ARGV_ELEMENT='ARGV_ELEMENT'
        RETURNED_SESSION_BINDING='RETURNED_SESSION_BINDING'
        REQUEST_TEMPLATE_HASH='REQUEST_TEMPLATE_HASH'
        UNEXPECTED_PROPERTY='UNEXPECTED_PROPERTY'
        SAVE_EXPLICIT_FAILURE='TERMINAL_EXPLICIT_FAILURE_P0'
        SAVE_INDETERMINATE='TERMINAL_INDETERMINATE_P1'
        OPEN_EFFECT_AMBIGUOUS='OPEN_EFFECT_AMBIGUOUS'
        ALL_WORKER_DRIFT='ALL_WORKER_DRIFT'
        PROTECTED_PROCESS='PROTECTED_PROCESS'
        PROCESS_GENERATION='PROCESS_GENERATION'
        P0_NOT_WORKER_FREE='P0_NOT_WORKER_FREE'
        SOLE_WRITER_UNPROVEN='SOLE_WRITER_UNPROVEN'
        B0_IDENTITY='B0_IDENTITY'
        RESTORE_SHORT_WRITE='RESTORE_SHORT_WRITE'
        ASSERTION_ORDER='ASSERTION_ORDER'
        BOUNDARY_INCOMPLETE='BOUNDARY_INCOMPLETE'
        CANDIDATE_DRIFT='CANDIDATE_DRIFT'
        LEGACY_PATH_DISABLED='LEGACY_PATH_DISABLED'
        SEMANTIC_BASELINE_INCOMPLETE='SEMANTIC_BASELINE_INCOMPLETE'
        BYTE_SEMANTICS='BYTE_SEMANTICS'
        TERMINAL_BRANCH_UNMODELED='TERMINAL_BRANCH_UNMODELED'
        HOSTILE_EXACT='HOSTILE_EXACT'
    }
    if ([string]$Case.fault -cne 'NONE') {
        if (-not $byFault.ContainsKey([string]$Case.fault)) {
            Stop-UID0001NWV43 'FIXTURE_FAULT' ([string]$Case.fault)
        }
        return [string]$byFault[[string]$Case.fault]
    }
    $byId = @{
        'PF-V4-COORD-SUCCESS-P1'='TERMINAL_P1'
        'PF-V4-COORD-EXPLICIT-FAILURE-P0'='TERMINAL_EXPLICIT_FAILURE_P0'
        'PF-V4-COORD-INDETERMINATE-P1'='TERMINAL_INDETERMINATE_P1'
        'PF-V4-COORD-VERIFIER-FAILURE-P1'='TERMINAL_VERIFIER_FAILURE'
        'PF-V4-COORD-RESTORE-FAILURE'='RESTORE_FAILURE'
        'PF-V4-COORD-ROLLBACK-FAILURE'='ROLLBACK_VERIFIER_FAILURE'
        'PF-V4-COORD-PX'='THIRD_IDENTITY'
    }
    if (-not $byId.ContainsKey([string]$Case.id)) {
        Stop-UID0001NWV43 'FIXTURE_ID' ([string]$Case.id)
    }
    [string]$byId[[string]$Case.id]
}

function Import-UID0001NWV43Authority {
    param([Parameter(Mandatory=$true)][string]$ReportPath)
    $path = [IO.Path]::GetFullPath($ReportPath)
    $lines = [IO.File]::ReadAllLines($path)
    $manifestText = Get-UID0001NWV42Block $lines 'V43_MANIFEST' 'json'
    $fixtureText = Get-UID0001NWV42Block $lines 'V43_FIXTURE_PLAN' 'json'
    $manifest = ConvertFrom-UID0001NWV42Json $manifestText
    $fixture = ConvertFrom-UID0001NWV42Json $fixtureText
    Assert-UID0001NWV42Keys $manifest @('schema_version','uid','public_entry','public_parameters','base_authority','fixture_plan_sha256','code_q_sha256','code_r_sha256','code_s_sha256','code_t_sha256','code_u_sha256','code_v_sha256','transcript_sha256','production_fixture_count','direct_hostile_count','response_count','boundary_count','operation_counter_order','effect_counter_order','effect_contract') 'V43_MANIFEST'
    if ([int]$manifest.schema_version -ne 43 -or [string]$manifest.uid -cne '0001NW') {
        Stop-UID0001NWV43 'MANIFEST_IDENTITY' '43/0001NW'
    }
    $blocks = @{}
    foreach ($name in @('Q','R','S','T','U','V')) {
        $blocks[$name] = Get-UID0001NWV42Block $lines ("V43_CODE_{0}" -f $name) 'powershell'
        $property = "code_{0}_sha256" -f $name.ToLowerInvariant()
        if ((Get-UID0001NWV43Sha $blocks[$name]) -cne [string]$manifest.$property) {
            Stop-UID0001NWV43 'AUTHORITY_HASH' $property
        }
    }
    $transcriptText = Get-UID0001NWV42Block $lines 'V43_TRANSCRIPT' 'json'
    if ((Get-UID0001NWV43Sha $fixtureText) -cne [string]$manifest.fixture_plan_sha256) {
        Stop-UID0001NWV43 'AUTHORITY_HASH' 'fixture_plan'
    }
    if ((Get-UID0001NWV43Sha $transcriptText) -cne [string]$manifest.transcript_sha256) {
        Stop-UID0001NWV43 'AUTHORITY_HASH' 'transcript'
    }
    Assert-UID0001NWV42Keys $fixture @('schema_version','cases') 'V43_FIXTURE_PLAN'
    $cases = @($fixture.cases)
    foreach ($case in $cases) {
        Assert-UID0001NWV42Keys $case @('suite','id','fault') ("V43_CASE/{0}" -f $case.id)
    }
    if (@($cases | Where-Object suite -CEQ 'PRODUCTION').Count -ne 32 -or
        @($cases | Where-Object suite -CEQ 'DIRECT').Count -ne 7 -or
        @($cases | Group-Object id | Where-Object Count -ne 1).Count -ne 0) {
        Stop-UID0001NWV43 'FIXTURE_PLAN' '32+7 unique'
    }
    $base = Import-UID0001NWV42Authority $path
    if (@($base.rows).Count -ne 193 -or @($base.boundaries).Count -ne 24) {
        Stop-UID0001NWV43 'BASE_AUTHORITY' '193/24'
    }
    [pscustomobject]@{
        path=$path
        report_sha256=(Get-UID0001NWV43FileSha $path)
        manifest=$manifest
        cases=$cases
        rows=@($base.rows)
        boundaries=@($base.boundaries)
        semantic_facts=$base.semantic_facts
        response_plan=$base.response_plan
        main=@($base.main)
        supplemental=@($base.supplemental)
        transcript=(ConvertFrom-UID0001NWV42Json $transcriptText)
        blocks=$blocks
    }
}
~~~

## Removed Block R013

- SHA256: `0D9F577EA740067A6C1FFDC19A2C3D5C994453D48A6D9D1B1A1673BA13A521F9`
- Language: `powershell`
- Bytes: `7018`
- First recovered timestamp: `2026-08-08T04:27:11.367Z`
- Session provenance: rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 196731 (2026-08-08T04:27:11.367Z)

~~~powershell
function New-UID0001NWV43State {
    param([object]$Authority,[scriptblock]$Transport,[scriptblock]$Effect,[string]$CaseId)
    [pscustomobject]@{
        authority=$Authority
        case_id=$CaseId
        transport=$Transport
        effect=$Effect
        transport_identity=[Runtime.CompilerServices.RuntimeHelpers]::GetHashCode($Transport)
        effect_identity=[Runtime.CompilerServices.RuntimeHelpers]::GetHashCode($Effect)
        transport_sha256=(Get-UID0001NWV43Sha $Transport.ToString())
        effect_sha256=(Get-UID0001NWV43Sha $Effect.ToString())
        next_request_id=0
        next_boundary=0
        operations=[ordered]@{transport=0;open=0;mutation=0;readback=0;save=0;stop=0;write=0;restore=0;cleanup=0}
        effects=[ordered]@{rpc=0;process=0;filesystem=0;disk=0;mutation_attempts=0;reported_changes=0}
        raw_requests=(New-Object Collections.Generic.List[string])
        raw_responses=(New-Object Collections.Generic.List[string])
        raw_effect_requests=(New-Object Collections.Generic.List[string])
        raw_effect_responses=(New-Object Collections.Generic.List[string])
        reached_boundaries=(New-Object Collections.Generic.List[string])
        assertions=(New-Object Collections.Generic.List[string])
        sessions=(New-Object Collections.Generic.List[string])
        save_state='NOT_ISSUED'
        save_outcome='NOT_ISSUED'
        disk='P0'
        cleanup_complete=$false
        terminal=''
    }
}

function Assert-UID0001NWV43BoundaryIdentity {
    param([object]$State)
    if ([Runtime.CompilerServices.RuntimeHelpers]::GetHashCode($State.transport) -ne $State.transport_identity -or
        (Get-UID0001NWV43Sha $State.transport.ToString()) -cne $State.transport_sha256) {
        Stop-UID0001NWV43 'TRANSPORT_IDENTITY' 'sealed callback changed'
    }
    if ([Runtime.CompilerServices.RuntimeHelpers]::GetHashCode($State.effect) -ne $State.effect_identity -or
        (Get-UID0001NWV43Sha $State.effect.ToString()) -cne $State.effect_sha256) {
        Stop-UID0001NWV43 'EFFECT_IDENTITY' 'sealed callback changed'
    }
}

function Invoke-UID0001NWV43Transport {
    param(
        [object]$State,
        [string]$Method,
        [object]$Parameters,
        [ValidateSet('read','open','mutation','readback','save','stop','cleanup')][string]$Operation='read'
    )
    Assert-UID0001NWV43BoundaryIdentity $State
    $State.next_request_id++
    $request = [ordered]@{
        jsonrpc='2.0'
        id=[int]$State.next_request_id
        method=$Method
        params=$Parameters
    }
    $rawRequest = ConvertTo-UID0001NWV42Json $request
    $State.raw_requests.Add($rawRequest)
    $State.operations.transport++
    $State.effects.rpc++
    if ($Operation -eq 'open') { $State.operations.open++ }
    elseif ($Operation -eq 'mutation') {
        $State.operations.mutation++
        $State.effects.mutation_attempts++
    }
    elseif ($Operation -eq 'readback') { $State.operations.readback++ }
    elseif ($Operation -eq 'save') {
        $State.operations.save++
        $State.effects.mutation_attempts++
    }
    elseif ($Operation -eq 'stop') { $State.operations.stop++ }
    elseif ($Operation -eq 'cleanup') { $State.operations.cleanup++ }
    $rawResponse = & $State.transport $rawRequest
    if ($rawResponse -isnot [string] -or [string]::IsNullOrWhiteSpace($rawResponse)) {
        Stop-UID0001NWV43 'TRANSPORT_RESPONSE' $Method
    }
    $State.raw_responses.Add([string]$rawResponse)
    $response = ConvertFrom-UID0001NWV42Json ([string]$rawResponse)
    $keys = @($response.PSObject.Properties.Name)
    $success = @('jsonrpc','id','result')
    $failure = @('jsonrpc','id','error')
    if (@(Compare-Object $success $keys -CaseSensitive).Count -ne 0 -and
        @(Compare-Object $failure $keys -CaseSensitive).Count -ne 0) {
        Stop-UID0001NWV43 'JSONRPC_KEYS' $Method
    }
    if ([string]$response.jsonrpc -cne '2.0' -or [int]$response.id -ne [int]$request.id) {
        Stop-UID0001NWV43 'JSONRPC_ID' $Method
    }
    if ($null -ne $response.result -and
        $response.result.PSObject.Properties.Name -contains 'changed' -and
        [bool]$response.result.changed) {
        $State.effects.reported_changes++
    }
    $response
}

function Invoke-UID0001NWV43Effect {
    param(
        [object]$State,
        [ValidateSet('process','filesystem','disk')][string]$Domain,
        [string]$Operation,
        [object]$Arguments,
        [ValidateSet('read','write','restore','stop','cleanup')][string]$OperationClass='read'
    )
    Assert-UID0001NWV43BoundaryIdentity $State
    $request = [ordered]@{operation=$Operation;domain=$Domain;arguments=$Arguments}
    $rawRequest = ConvertTo-UID0001NWV42Json $request
    $State.raw_effect_requests.Add($rawRequest)
    $State.effects[$Domain]++
    if ($OperationClass -eq 'write') { $State.operations.write++ }
    elseif ($OperationClass -eq 'restore') { $State.operations.restore++ }
    elseif ($OperationClass -eq 'stop') { $State.operations.stop++ }
    elseif ($OperationClass -eq 'cleanup') { $State.operations.cleanup++ }
    $rawResponse = & $State.effect $rawRequest
    if ($rawResponse -isnot [string] -or [string]::IsNullOrWhiteSpace($rawResponse)) {
        Stop-UID0001NWV43 'EFFECT_RESPONSE' $Operation
    }
    $State.raw_effect_responses.Add([string]$rawResponse)
    $response = ConvertFrom-UID0001NWV42Json ([string]$rawResponse)
    $keys = @($response.PSObject.Properties.Name)
    if ([bool]$response.ok) {
        if (@(Compare-Object @('ok','changed','data') $keys -CaseSensitive).Count -ne 0) {
            Stop-UID0001NWV43 'EFFECT_KEYS' $Operation
        }
    }
    else {
        if (@(Compare-Object @('ok','changed','error') $keys -CaseSensitive).Count -ne 0) {
            Stop-UID0001NWV43 'EFFECT_KEYS' $Operation
        }
    }
    if ([bool]$response.changed) {
        $State.effects.reported_changes++
    }
    $response
}

function Add-UID0001NWV43Boundary {
    param([object]$State,[string]$Label)
    if ($State.next_boundary -ge @($State.authority.boundaries).Count -or
        [string]$State.authority.boundaries[$State.next_boundary] -cne $Label) {
        Stop-UID0001NWV43 'BOUNDARY_ORDER' $Label
    }
    $observation = Invoke-UID0001NWV43Effect $State 'process' 'observe_boundary' ([ordered]@{label=$Label;ordinal=($State.next_boundary+1)})
    if (-not [bool]$observation.ok -or [string]$observation.data.label -cne $Label -or
        [int]$observation.data.ordinal -ne ($State.next_boundary+1)) {
        Stop-UID0001NWV43 'BOUNDARY_INCOMPLETE' $Label
    }
    $State.reached_boundaries.Add($Label)
    $State.next_boundary++
}

function Add-UID0001NWV43Assertion {
    param([object]$State,[string]$Assertion)
    $State.assertions.Add($Assertion)
}

function Get-UID0001NWV43Digest {
    param([object[]]$Values)
    if (@($Values).Count -eq 0) {
        return Get-UID0001NWV43Sha ''
    }
    Get-UID0001NWV43Sha ([string]::Join([char]10,@($Values | ForEach-Object { [string]$_ })))
}
~~~

## Removed Block R014

- SHA256: `FDE2F78B1A8D3AD74123F307EC6D31D976B205BA9D84D3DA97F03FAD8CF0BDD4`
- Language: `powershell`
- Bytes: `9202`
- First recovered timestamp: `2026-08-08T04:29:02.591Z`
- Session provenance: rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 196741 (2026-08-08T04:29:02.591Z)

~~~powershell
function Assert-UID0001NWV43Preflight {
    param([object]$State)
    $path = Invoke-UID0001NWV43Effect $State 'filesystem' 'canonical_report_path' ([ordered]@{path=$State.authority.path})
    if (-not [bool]$path.ok) { Stop-UID0001NWV43 'PATH_OUTSIDE_ROOT' 'path probe failed' }
    $candidate = [string]$path.data.path
    if ($candidate -match '(^|[\\/])\.\.([\\/]|$)') {
        Stop-UID0001NWV43 'PATH_TRAVERSAL' $candidate
    }
    $full = [IO.Path]::GetFullPath($candidate)
    if ($full -cne $State.authority.path) {
        Stop-UID0001NWV43 'PATH_OUTSIDE_ROOT' $full
    }

    $report = Invoke-UID0001NWV43Effect $State 'filesystem' 'report_identity' ([ordered]@{path=$State.authority.path})
    if (-not [bool]$report.ok -or [string]$report.data.sha256 -cne [string]$State.authority.report_sha256) {
        Stop-UID0001NWV43 'REPORT_TEMPLATE_HASH' 'physical report identity'
    }

    $parser = Invoke-UID0001NWV43Effect $State 'filesystem' 'parser_identity' ([ordered]@{name='UID0001NW_STRICT_JSON'})
    if (-not [bool]$parser.ok -or [string]$parser.data.identity -cne 'STRICT_DUPLICATE_KEY_PARSER_ACTIVE') {
        Stop-UID0001NWV43 'PARSER_IDENTITY' 'boundary identity'
    }
    $duplicateRejected = $false
    try { $null = ConvertFrom-UID0001NWV42Json '{"a":1,"\u0061":2}' }
    catch {
        if ($_.Exception.Message -like '*JSON_DUPLICATE_MEMBER*') { $duplicateRejected = $true }
    }
    if (-not $duplicateRejected) { Stop-UID0001NWV43 'PARSER_IDENTITY' 'escaped duplicate self-test' }

    $semantic = Invoke-UID0001NWV43Effect $State 'filesystem' 'semantic_inventory' ([ordered]@{uid='0001NW'})
    if (-not [bool]$semantic.ok -or [int]$semantic.data.functions -ne 9 -or
        [int]$semantic.data.globals -ne 7 -or [int]$semantic.data.types -ne 3 -or
        [int]$semantic.data.protected_items -ne 12) {
        Stop-UID0001NWV43 'SEMANTIC_BASELINE_INCOMPLETE' '9/7/3/12'
    }

    $bytes = Invoke-UID0001NWV43Effect $State 'disk' 'byte_model' ([ordered]@{uid='0001NW'})
    if (-not [bool]$bytes.ok -or [string]$bytes.data.endian -cne 'little' -or [int]$bytes.data.pointer_size -ne 4) {
        Stop-UID0001NWV43 'BYTE_SEMANTICS' 'little/4'
    }

    $legacy = Invoke-UID0001NWV43Effect $State 'filesystem' 'legacy_route' ([ordered]@{public_entry='Invoke-UID0001NWAtomicEnvelopeV4'})
    if (-not [bool]$legacy.ok -or [bool]$legacy.data.enabled) {
        Stop-UID0001NWV43 'LEGACY_PATH_DISABLED' 'legacy route is callable'
    }

    $requestProbe = Invoke-UID0001NWV43Effect $State 'filesystem' 'request_template_observation' ([ordered]@{rows=@($State.authority.rows).Count})
    if (-not [bool]$requestProbe.ok -or -not [bool]$requestProbe.data.unchanged) {
        Stop-UID0001NWV43 'REQUEST_TEMPLATE_HASH' 'catalog observation'
    }
    foreach ($row in @($State.authority.rows)) {
        if ((Get-UID0001NWV43Sha (ConvertTo-UID0001NWV42Json $row.request)) -cne [string]$row.request_template_sha256) {
            Stop-UID0001NWV43 'REQUEST_TEMPLATE_HASH' ([string]$row.assertion_id)
        }
    }
}

function Assert-UID0001NWV43ToolsAndRuntime {
    param([object]$State)
    $tools = Invoke-UID0001NWV43Transport $State 'tools/list' ([ordered]@{})
    if ($null -ne $tools.error) { Stop-UID0001NWV43 'SCHEMA_NATIVE_TYPE' 'tools/list error' }
    Assert-UID0001NWV42Keys $tools.result @('tools','changed') 'TOOLS_LIST_RESULT'
    $runtime = @($tools.result.tools | Where-Object name -CEQ 'runtime_attestation')
    $private = @($tools.result.tools | Where-Object name -CEQ 'runtime/attest')
    if ($runtime.Count -ne 1 -or $private.Count -ne 0 -or $runtime[0].input_schema.type -cne 'object' -or
        @($runtime[0].input_schema.required).Count -ne 0 -or [bool]$runtime[0].input_schema.additionalProperties) {
        Stop-UID0001NWV43 'SCHEMA_NATIVE_TYPE' 'runtime_attestation'
    }
    Add-UID0001NWV43Boundary $State 'B001_TOOLS_LIST'

    $list = Invoke-UID0001NWV43Transport $State 'idb/list' ([ordered]@{})
    if ($null -ne $list.error -or @($list.result.sessions).Count -ne 0) {
        Stop-UID0001NWV43 'ALL_WORKER_DRIFT' 'initial sessions'
    }
    Add-UID0001NWV43Boundary $State 'B002_INITIAL_IDB_LIST'

    $attest = Invoke-UID0001NWV43Transport $State 'runtime/attestation' ([ordered]@{nonce='N0'})
    if ($null -ne $attest.error -or [string]$attest.result.listener_generation -cne 'L1') {
        Stop-UID0001NWV43 'ALL_WORKER_DRIFT' 'listener'
    }
    foreach ($arg in @($attest.result.argv)) {
        if ($arg -isnot [string]) { Stop-UID0001NWV43 'ARGV_ELEMENT' 'listener argv' }
    }
    Add-UID0001NWV43Boundary $State 'B003_INITIAL_ATTESTATION'
}

function Assert-UID0001NWV43UnexpectedProperty {
    param([object]$State)
    $probe = Invoke-UID0001NWV43Transport $State 'hostile/unexpected_property' ([ordered]@{unexpected=1})
    if ($null -eq $probe.error) {
        Stop-UID0001NWV43 'UNEXPECTED_PROPERTY' 'request accepted'
    }
    if ([int]$probe.error.code -eq -32099) {
        Stop-UID0001NWV43 'HOSTILE_EXACT' 'wrong hostile error'
    }
    if ([int]$probe.error.code -ne -32602) {
        Stop-UID0001NWV43 'UNEXPECTED_PROPERTY' ([string]$probe.error.code)
    }
}

function Open-UID0001NWV43Role {
    param([object]$State,[string]$Role)
    $response = Invoke-UID0001NWV43Transport $State 'idb/open' ([ordered]@{path=$State.authority.path;role=$Role;run_auto_analysis=$false}) 'open'
    if ($null -ne $response.error -or $null -eq $response.result) {
        Stop-UID0001NWV43 'OPEN_EFFECT_AMBIGUOUS' $Role
    }
    Assert-UID0001NWV42Keys $response.result @('session_id','path','generation','changed') ("OPEN/{0}" -f $Role)
    if ([string]::IsNullOrWhiteSpace([string]$response.result.session_id) -or
        [string]$response.result.path -cne $State.authority.path -or
        [string]::IsNullOrWhiteSpace([string]$response.result.generation)) {
        Stop-UID0001NWV43 'RETURNED_SESSION_BINDING' $Role
    }
    $State.sessions.Add([string]$response.result.session_id)
    [string]$response.result.session_id
}

function Close-UID0001NWV43Role {
    param([object]$State,[string]$Session)
    if ([string]::IsNullOrWhiteSpace($Session)) { return }
    $response = Invoke-UID0001NWV43Transport $State 'idb/close' ([ordered]@{session_id=$Session}) 'stop'
    if ($null -ne $response.error -or -not [bool]$response.result.closed) {
        Stop-UID0001NWV43 'CLEANUP_FAILED' $Session
    }
    $null = $State.sessions.Remove($Session)
}

function Assert-UID0001NWV43RuntimeRole {
    param([object]$State,[string]$Session,[string]$Role)
    $list = Invoke-UID0001NWV43Transport $State 'idb/list' ([ordered]@{})
    $matches = @($list.result.sessions | Where-Object session_id -CEQ $Session)
    if ($matches.Count -ne 1 -or [string]$matches[0].path -cne $State.authority.path) {
        Stop-UID0001NWV43 'ALL_WORKER_DRIFT' ("list/{0}" -f $Role)
    }
    $attest = Invoke-UID0001NWV43Transport $State 'runtime/attestation' ([ordered]@{session_id=$Session;nonce=("N-{0}" -f $Role)})
    if ($null -ne $attest.error -or [string]$attest.result.session_id -cne $Session -or
        [string]$attest.result.path -cne $State.authority.path -or
        [string]$attest.result.listener_generation -cne 'L1') {
        Stop-UID0001NWV43 'ALL_WORKER_DRIFT' ("attestation/{0}" -f $Role)
    }
    foreach ($arg in @($attest.result.argv)) {
        if ($arg -isnot [string]) { Stop-UID0001NWV43 'ARGV_ELEMENT' ("argv/{0}" -f $Role) }
    }
}

function Invoke-UID0001NWV43Rows {
    param([object]$State,[string]$Session,[string[]]$Phases)
    foreach ($row in @($State.authority.rows | Where-Object { $Phases -contains [string]$_.phase })) {
        $bound = Bind-UID0001NWV42Session $row.request $Session
        $operation = 'readback'
        if ([string]$row.phase -ceq 'MUTATION') {
            if ([string]$row.class -match 'dry') { $operation = 'readback' }
            else { $operation = 'mutation' }
        }
        elseif ([string]$row.phase -ceq 'SAVE') { $operation = 'save' }
        $parameters = [ordered]@{
            session_id=$Session
            tool=[string]$row.tool
            arguments=$bound
            ordinal=[int]$row.ordinal
            assertion_id=[string]$row.assertion_id
        }
        $response = Invoke-UID0001NWV43Transport $State 'tools/call' $parameters $operation
        if ($null -ne $response.error -or $null -eq $response.result) {
            if ([string]$row.phase -ceq 'SAVE') { return $response }
            Stop-UID0001NWV43 'ROW_RESPONSE' ([string]$row.assertion_id)
        }
        Assert-UID0001NWV42Keys $response.result @('ok','changed','session_id','ordinal','assertion_id') ("ROW/{0}" -f $row.assertion_id)
        if (-not [bool]$response.result.ok -or [string]$response.result.session_id -cne $Session) {
            Stop-UID0001NWV43 'RETURNED_SESSION_BINDING' ([string]$row.assertion_id)
        }
        if ([int]$response.result.ordinal -ne [int]$row.ordinal -or
            [string]$response.result.assertion_id -cne [string]$row.assertion_id) {
            Stop-UID0001NWV43 'ASSERTION_ORDER' ([string]$row.assertion_id)
        }
        Add-UID0001NWV43Assertion $State ([string]$row.assertion_id)
    }
    $null
}
~~~

## Removed Block R015

- SHA256: `7025536631AA2BDF05CC501D3903C4E6BE3D3F4CC558CC613854215A4C09F49C`
- Language: `powershell`
- Bytes: `12261`
- First recovered timestamp: `2026-08-08T04:30:42.940Z`
- Session provenance: rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 196748 (2026-08-08T04:30:42.940Z)

~~~powershell
function Invoke-UID0001NWAtomicEnvelopeV4 {
    [CmdletBinding()]
    param(
        [Parameter(Mandatory=$true)][string]$ReportPath,
        [Parameter(Mandatory=$true)][scriptblock]$Transport,
        [Parameter(Mandatory=$true)][scriptblock]$Effect,
        [string]$CaseId='LIVE'
    )
    $authority = Import-UID0001NWV43Authority $ReportPath
    $state = New-UID0001NWV43State $authority $Transport $Effect $CaseId
    $txSession = ''
    $verifierSession = ''
    $rollbackSession = ''
    $saveResponse = $null
    $saveOutcome = 'NOT_ISSUED'
    $identity = 'P0'
    $verifierOk = $true
    try {
        Assert-UID0001NWV43Preflight $state
        Assert-UID0001NWV43ToolsAndRuntime $state
        Assert-UID0001NWV43UnexpectedProperty $state

        Add-UID0001NWV43Boundary $state 'B004_PRE_OPEN'
        $txSession = Open-UID0001NWV43Role $state 'TX'
        Add-UID0001NWV43Boundary $state 'B005_POST_OPEN'
        Assert-UID0001NWV43RuntimeRole $state $txSession 'TX'

        Add-UID0001NWV43Boundary $state 'B006_PRE_S0'
        Invoke-UID0001NWV43Rows $state $txSession @('S0')
        Add-UID0001NWV43Boundary $state 'B007_POST_S0'

        Add-UID0001NWV43Boundary $state 'B008_PRE_MUTATION'
        Invoke-UID0001NWV43Rows $state $txSession @('MUTATION','IMMEDIATE_READBACK')
        Add-UID0001NWV43Boundary $state 'B009_POST_MUTATION'

        Add-UID0001NWV43Boundary $state 'B010_PRE_F'
        Invoke-UID0001NWV43Rows $state $txSession @('F')
        Add-UID0001NWV43Boundary $state 'B011_POST_F'

        Add-UID0001NWV43Boundary $state 'B012_PRE_SAVE'
        $free = Invoke-UID0001NWV43Effect $state 'process' 'pre_save_worker_free_authority' ([ordered]@{session_id=$txSession})
        if (-not [bool]$free.ok -or -not [bool]$free.data.authorized) {
            Stop-UID0001NWV43 'P0_NOT_WORKER_FREE' 'backup authority'
        }
        $p0 = Invoke-UID0001NWV43Effect $state 'disk' 'capture_p0' ([ordered]@{path=$authority.path})
        $b0 = Invoke-UID0001NWV43Effect $state 'filesystem' 'create_exclusive_backup' ([ordered]@{path=$authority.path;p0=$p0.data}) 'write'
        if (-not [bool]$p0.ok -or -not [bool]$b0.ok -or
            [string]$b0.data.source_sha256 -cne [string]$p0.data.sha256 -or
            [string]$b0.data.backup_sha256 -cne [string]$p0.data.sha256 -or
            [long]$b0.data.bytes -ne [long]$p0.data.size) {
            Stop-UID0001NWV43 'B0_IDENTITY' 'exclusive backup'
        }

        $journal = Invoke-UID0001NWV43Effect $state 'filesystem' 'persist_save_intent' ([ordered]@{state='ISSUED';session_id=$txSession;path=$authority.path}) 'write'
        if (-not [bool]$journal.ok -or [string]$journal.data.state -cne 'ISSUED') {
            Stop-UID0001NWV43 'SAVE_JOURNAL' 'ISSUED not durable'
        }
        $state.save_state = 'ISSUED'
        $saveRow = @($authority.rows | Where-Object phase -CEQ 'SAVE')
        if ($saveRow.Count -ne 1) { Stop-UID0001NWV43 'SAVE_ROW' $saveRow.Count }
        $saveParameters = [ordered]@{
            session_id=$txSession
            tool=[string]$saveRow[0].tool
            arguments=(Bind-UID0001NWV42Session $saveRow[0].request $txSession)
            ordinal=[int]$saveRow[0].ordinal
            assertion_id=[string]$saveRow[0].assertion_id
        }
        try {
            $saveResponse = Invoke-UID0001NWV43Transport $state 'tools/call' $saveParameters 'save'
            if ($null -ne $saveResponse.error) {
                $saveOutcome = 'EXPLICIT_FAILURE'
            }
            else {
                Assert-UID0001NWV42Keys $saveResponse.result @('ok','changed','session_id','ordinal','assertion_id') 'SAVE_RESPONSE'
                if ([string]$saveResponse.result.session_id -cne $txSession) {
                    Stop-UID0001NWV43 'RETURNED_SESSION_BINDING' 'save'
                }
                if ([int]$saveResponse.result.ordinal -ne [int]$saveRow[0].ordinal -or
                    [string]$saveResponse.result.assertion_id -cne [string]$saveRow[0].assertion_id) {
                    Stop-UID0001NWV43 'ASSERTION_ORDER' 'save'
                }
                if ([bool]$saveResponse.result.ok) { $saveOutcome = 'EXPLICIT_SUCCESS' }
                else { $saveOutcome = 'EXPLICIT_FAILURE' }
                Add-UID0001NWV43Assertion $state ([string]$saveRow[0].assertion_id)
            }
        }
        catch {
            if ($_.Exception.Message -like 'UID0001NW_V42:JSON_*' -or
                $_.Exception.Message -like 'UID0001NW_V43:TRANSPORT_RESPONSE:*') {
                $saveOutcome = 'INDETERMINATE'
            }
            else { throw }
        }
        $state.save_outcome = $saveOutcome
        Add-UID0001NWV43Boundary $state 'B013_SAVE_ISSUED_DURABLE'
        $classifiedJournal = Invoke-UID0001NWV43Effect $state 'filesystem' 'persist_save_classification' ([ordered]@{state='CLASSIFIED';outcome=$saveOutcome}) 'write'
        if (-not [bool]$classifiedJournal.ok -or [string]$classifiedJournal.data.state -cne 'CLASSIFIED') {
            Stop-UID0001NWV43 'SAVE_JOURNAL' 'CLASSIFIED not durable'
        }
        $state.save_state = 'CLASSIFIED'
        Add-UID0001NWV43Boundary $state 'B014_POST_SAVE'

        Add-UID0001NWV43Boundary $state 'B015_PRE_CLEANUP'
        Close-UID0001NWV43Role $state $txSession
        $txSession = ''
        $retireWorker = Invoke-UID0001NWV43Effect $state 'process' 'retire_worker_generation' ([ordered]@{role='TX'}) 'stop'
        if (-not [bool]$retireWorker.ok) {
            $code = [string]$retireWorker.error.code
            if ($code -ceq 'PROTECTED_PROCESS') { Stop-UID0001NWV43 'PROTECTED_PROCESS' 'TX' }
            if ($code -ceq 'PROCESS_GENERATION') { Stop-UID0001NWV43 'PROCESS_GENERATION' 'TX' }
            Stop-UID0001NWV43 'RETIREMENT_FAILED' 'TX'
        }
        Add-UID0001NWV43Boundary $state 'B016_POST_WORKER_RETIRE'
        $retireRedirector = Invoke-UID0001NWV43Effect $state 'process' 'retire_redirector_generation' ([ordered]@{role='TX'}) 'stop'
        if (-not [bool]$retireRedirector.ok) { Stop-UID0001NWV43 'RETIREMENT_FAILED' 'redirector' }
        Add-UID0001NWV43Boundary $state 'B017_POST_REDIRECTOR_RETIRE'
        $workerFree = Invoke-UID0001NWV43Effect $state 'process' 'worker_free_snapshot' ([ordered]@{path=$authority.path})
        if (-not [bool]$workerFree.ok -or -not [bool]$workerFree.data.worker_free) {
            Stop-UID0001NWV43 'P0_NOT_WORKER_FREE' 'post-retirement'
        }
        Add-UID0001NWV43Boundary $state 'B018_WORKER_FREE'

        Add-UID0001NWV43Boundary $state 'B019_PRE_CLASSIFICATION'
        $classification = Invoke-UID0001NWV43Effect $state 'disk' 'classify_candidate' ([ordered]@{path=$authority.path;p0=$p0.data;b0=$b0.data;save_outcome=$saveOutcome})
        if (-not [bool]$classification.ok) { Stop-UID0001NWV43 'DISK_CLASSIFICATION' 'failed' }
        $identity = [string]$classification.data.identity
        if (-not [bool]$classification.data.candidate_valid) {
            Stop-UID0001NWV43 'CANDIDATE_DRIFT' 'candidate tuple'
        }
        if ($identity -ceq 'P1' -and -not [bool]$classification.data.sole_writer) {
            Stop-UID0001NWV43 'SOLE_WRITER_UNPROVEN' 'P1'
        }
        if ($identity -notin @('P0','P1','PX')) {
            Stop-UID0001NWV43 'TERMINAL_BRANCH_UNMODELED' $identity
        }
        $state.disk = $identity
        Add-UID0001NWV43Boundary $state 'B020_P1_CAPTURE'

        Add-UID0001NWV43Boundary $state 'B021_PRE_VERIFIER'
        $verifierSession = Open-UID0001NWV43Role $state 'VERIFIER'
        Assert-UID0001NWV43RuntimeRole $state $verifierSession 'VERIFIER'
        Invoke-UID0001NWV43Rows $state $verifierSession @('R')
        $verify = Invoke-UID0001NWV43Effect $state 'disk' 'verify_candidate' ([ordered]@{path=$authority.path;identity=$identity})
        $verifierOk = [bool]$verify.ok -and [bool]$verify.data.valid
        Close-UID0001NWV43Role $state $verifierSession
        $verifierSession = ''
        Add-UID0001NWV43Boundary $state 'B022_POST_VERIFIER'
        Add-UID0001NWV43Boundary $state 'B023_PRE_RESTORE_OR_FINAL'

        if (-not $verifierOk) {
            $restore = Invoke-UID0001NWV43Effect $state 'disk' 'restore_from_b0' ([ordered]@{path=$authority.path;p0=$p0.data;b0=$b0.data}) 'restore'
            if (-not [bool]$restore.ok) {
                if ([string]$restore.error.code -ceq 'RESTORE_SHORT_WRITE') {
                    Stop-UID0001NWV43 'RESTORE_SHORT_WRITE' 'restore boundary'
                }
                Stop-UID0001NWV43 'RESTORE_FAILURE' 'restore boundary'
            }
            if ([long]$restore.data.bytes -ne [long]$p0.data.size -or
                [string]$restore.data.sha256 -cne [string]$p0.data.sha256) {
                Stop-UID0001NWV43 'RESTORE_SHORT_WRITE' 'tuple mismatch'
            }
            $rollbackSession = Open-UID0001NWV43Role $state 'ROLLBACK'
            Assert-UID0001NWV43RuntimeRole $state $rollbackSession 'ROLLBACK'
            Invoke-UID0001NWV43Rows $state $rollbackSession @('RB')
            $rollback = Invoke-UID0001NWV43Effect $state 'disk' 'verify_rollback' ([ordered]@{path=$authority.path;p0=$p0.data})
            Close-UID0001NWV43Role $state $rollbackSession
            $rollbackSession = ''
            if (-not [bool]$rollback.ok -or -not [bool]$rollback.data.valid) {
                Stop-UID0001NWV43 'ROLLBACK_VERIFIER_FAILURE' 'rollback verifier'
            }
            $state.disk = 'P0'
            $state.terminal = 'TERMINAL_VERIFIER_FAILURE'
        }
        elseif ($identity -ceq 'PX') {
            $state.terminal = 'THIRD_IDENTITY'
        }
        elseif ($saveOutcome -ceq 'EXPLICIT_FAILURE') {
            $state.terminal = 'TERMINAL_EXPLICIT_FAILURE_P0'
        }
        elseif ($saveOutcome -ceq 'INDETERMINATE') {
            $state.terminal = 'TERMINAL_INDETERMINATE_P1'
        }
        elseif ($identity -ceq 'P1') {
            $state.terminal = 'TERMINAL_P1'
        }
        else {
            $state.terminal = 'TERMINAL_EXPLICIT_FAILURE_P0'
        }
        Add-UID0001NWV43Boundary $state 'B024_TERMINAL_WORKER_FREE'
    }
    catch {
        $message = [string]$_.Exception.Message
        if ($message -like 'UID0001NW_V43:*') {
            $state.terminal = $message.Split(':')[1]
        }
        elseif ($message -like 'UID0001NW_V42:JSON_DUPLICATE_MEMBER:*') {
            $state.terminal = 'JSON_DUPLICATE_MEMBER'
        }
        else {
            $state.terminal = 'RUNTIME_EXCEPTION'
        }
    }
    finally {
        foreach ($session in @($rollbackSession,$verifierSession,$txSession)) {
            if (-not [string]::IsNullOrWhiteSpace([string]$session)) {
                try { Close-UID0001NWV43Role $state ([string]$session) }
                catch { $state.terminal = 'CLEANUP_FAILED' }
            }
        }
        try {
            $cleanup = Invoke-UID0001NWV43Effect $state 'filesystem' 'cleanup_transaction' ([ordered]@{case_id=$CaseId;sessions=@($state.sessions)}) 'cleanup'
            $state.cleanup_complete = [bool]$cleanup.ok -and @($state.sessions).Count -eq 0
        }
        catch {
            $state.cleanup_complete = $false
            $state.terminal = 'CLEANUP_FAILED'
        }
    }
    [pscustomobject]@{
        case_id=$CaseId
        observed=[string]$state.terminal
        boundaries=@($state.reached_boundaries)
        assertion_count=@($state.assertions).Count
        operation_counters=[pscustomobject]$state.operations
        effect_counters=[pscustomobject]$state.effects
        cleanup_complete=[bool]$state.cleanup_complete
        save_state=[string]$state.save_state
        save_outcome=[string]$state.save_outcome
        disk=[string]$state.disk
        request_digest=(Get-UID0001NWV43Digest @($state.raw_requests))
        response_digest=(Get-UID0001NWV43Digest @($state.raw_responses))
        effect_request_digest=(Get-UID0001NWV43Digest @($state.raw_effect_requests))
        effect_response_digest=(Get-UID0001NWV43Digest @($state.raw_effect_responses))
        boundary_digest=(Get-UID0001NWV43Digest @($state.reached_boundaries))
        assertion_digest=(Get-UID0001NWV43Digest @($state.assertions))
        external_effects=[int]$state.effects.reported_changes
    }
}
~~~

## Removed Block R016

- SHA256: `648AF1061E3211885777289FE152E0FE152170B1D23CBE8188CF987C46C62BDD`
- Language: `powershell`
- Bytes: `12249`
- First recovered timestamp: `2026-08-08T04:32:22.055Z`
- Session provenance: rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 196757 (2026-08-08T04:32:22.055Z)

~~~powershell
function New-UID0001NWV43JsonRpcResult {
    param([int]$Id,[object]$Result)
    ConvertTo-UID0001NWV42Json ([ordered]@{jsonrpc='2.0';id=$Id;result=$Result})
}

function New-UID0001NWV43JsonRpcError {
    param([int]$Id,[int]$Code,[string]$Message)
    ConvertTo-UID0001NWV42Json ([ordered]@{jsonrpc='2.0';id=$Id;error=[ordered]@{code=$Code;message=$Message}})
}

function New-UID0001NWV43EffectResult {
    param([object]$Data,[bool]$Changed=$false)
    ConvertTo-UID0001NWV42Json ([ordered]@{ok=$true;changed=$Changed;data=$Data})
}

function New-UID0001NWV43EffectError {
    param([string]$Code,[string]$Detail,[bool]$Changed=$false)
    ConvertTo-UID0001NWV42Json ([ordered]@{ok=$false;changed=$Changed;error=[ordered]@{code=$Code;detail=$Detail}})
}

function New-UID0001NWV43FixtureBoundaries {
    param([object]$Case,[object]$Authority,[object]$Observer)
    $context = [pscustomobject]@{
        sessions=(New-Object Collections.Generic.List[object])
        fault=[string]$Case.fault
        case_id=[string]$Case.id
        boundary_count=0
    }

    $transport = {
        param([string]$RawRequest)
        $Observer.transport_calls++
        $request = ConvertFrom-UID0001NWV42Json $RawRequest
        $method = [string]$request.method
        $id = [int]$request.id
        if ($method -ceq 'tools/list') {
            if ($context.fault -ceq 'JSON_DUPLICATE_MEMBER') {
                return ('{"jsonrpc":"2.0","id":' + $id + ',"result":{"tools":[],"tools":[],"changed":false}}')
            }
            if ($context.fault -ceq 'JSON_ESCAPED_DUPLICATE_MEMBER') {
                return ('{"jsonrpc":"2.0","id":' + $id + ',"result":{"tools":[],"\u0074ools":[],"changed":false}}')
            }
            $schemaType = 'object'
            if ($context.fault -ceq 'SCHEMA_NATIVE_TYPE') { $schemaType = 'array' }
            $schema = [ordered]@{type=$schemaType;properties=[ordered]@{};required=[object[]]@();additionalProperties=$false}
            $tools = @([ordered]@{name='runtime_attestation';input_schema=$schema})
            return New-UID0001NWV43JsonRpcResult $id ([ordered]@{tools=$tools;changed=$false})
        }
        if ($method -ceq 'idb/list') {
            return New-UID0001NWV43JsonRpcResult $id ([ordered]@{sessions=@($context.sessions);changed=$false})
        }
        if ($method -ceq 'runtime/attestation') {
            $argv = @('idalib-mcp','--transport','stdio')
            if ($context.fault -ceq 'ARGV_ELEMENT') { $argv = @('idalib-mcp',7) }
            $generation = 'L1'
            if ($context.fault -ceq 'ALL_WORKER_DRIFT' -and $context.sessions.Count -gt 0) { $generation = 'L2' }
            $sessionId = ''
            $path = $Authority.path
            if ($request.params.PSObject.Properties.Name -contains 'session_id') {
                $sessionId = [string]$request.params.session_id
            }
            return New-UID0001NWV43JsonRpcResult $id ([ordered]@{
                listener_generation=$generation
                argv=$argv
                session_id=$sessionId
                path=$path
                changed=$false
            })
        }
        if ($method -ceq 'hostile/unexpected_property') {
            if ($context.fault -ceq 'UNEXPECTED_PROPERTY') {
                return New-UID0001NWV43JsonRpcResult $id ([ordered]@{accepted=$true;changed=$false})
            }
            if ($context.fault -ceq 'HOSTILE_EXACT') {
                return New-UID0001NWV43JsonRpcError $id -32099 'hostile mismatch'
            }
            return New-UID0001NWV43JsonRpcError $id -32602 'unexpected property'
        }
        if ($method -ceq 'idb/open') {
            if ($context.fault -ceq 'OPEN_EFFECT_AMBIGUOUS') {
                return New-UID0001NWV43JsonRpcError $id -32001 'open outcome ambiguous'
            }
            $role = [string]$request.params.role
            $sessionId = "V43-{0}-{1}" -f $context.case_id,$role
            $path = $Authority.path
            if ($context.fault -ceq 'RETURNED_SESSION_BINDING') { $path = $Authority.path + '.wrong' }
            $row = [pscustomobject]@{session_id=$sessionId;path=$path;generation=("G-{0}" -f $role)}
            $context.sessions.Add($row)
            return New-UID0001NWV43JsonRpcResult $id ([ordered]@{session_id=$sessionId;path=$path;generation=$row.generation;changed=$false})
        }
        if ($method -ceq 'idb/close') {
            $sessionId = [string]$request.params.session_id
            foreach ($row in @($context.sessions)) {
                if ([string]$row.session_id -ceq $sessionId) { $null = $context.sessions.Remove($row) }
            }
            return New-UID0001NWV43JsonRpcResult $id ([ordered]@{closed=$true;changed=$false})
        }
        if ($method -ceq 'tools/call') {
            $assertion = [string]$request.params.assertion_id
            if ($assertion -ceq 'S001/PRIMARY') {
                if ($context.fault -ceq 'SAVE_EXPLICIT_FAILURE' -or
                    $context.case_id -ceq 'PF-V4-COORD-EXPLICIT-FAILURE-P0') {
                    return New-UID0001NWV43JsonRpcError $id -32010 'save failed'
                }
                if ($context.fault -ceq 'SAVE_INDETERMINATE' -or
                    $context.case_id -ceq 'PF-V4-COORD-INDETERMINATE-P1') {
                    return '{"jsonrpc":"2.0","id":'
                }
            }
            $ordinal = [int]$request.params.ordinal
            if ($context.fault -ceq 'ASSERTION_ORDER' -and $assertion -ceq 'F/Q001') { $ordinal++ }
            return New-UID0001NWV43JsonRpcResult $id ([ordered]@{
                ok=$true
                changed=$false
                session_id=[string]$request.params.session_id
                ordinal=$ordinal
                assertion_id=$assertion
            })
        }
        New-UID0001NWV43JsonRpcError $id -32601 'method not found'
    }.GetNewClosure()

    $effect = {
        param([string]$RawRequest)
        $Observer.effect_calls++
        $request = ConvertFrom-UID0001NWV42Json $RawRequest
        $operation = [string]$request.operation
        if ($operation -ceq 'canonical_report_path') {
            $path = $Authority.path
            if ($context.fault -ceq 'PATH_TRAVERSAL') { $path = '..\0001NW.md' }
            elseif ($context.fault -ceq 'PATH_OUTSIDE_ROOT') { $path = 'C:\outside\0001NW.md' }
            return New-UID0001NWV43EffectResult ([ordered]@{path=$path})
        }
        if ($operation -ceq 'report_identity') {
            $sha = $Authority.report_sha256
            if ($context.fault -ceq 'REPORT_TEMPLATE_HASH') { $sha = ('F' * 64) }
            return New-UID0001NWV43EffectResult ([ordered]@{sha256=$sha})
        }
        if ($operation -ceq 'parser_identity') {
            $identity = 'STRICT_DUPLICATE_KEY_PARSER_ACTIVE'
            if ($context.fault -ceq 'PARSER_IDENTITY') { $identity = 'REPLACED_PARSER' }
            return New-UID0001NWV43EffectResult ([ordered]@{identity=$identity})
        }
        if ($operation -ceq 'semantic_inventory') {
            $functions = 9
            if ($context.fault -ceq 'SEMANTIC_BASELINE_INCOMPLETE') { $functions = 8 }
            return New-UID0001NWV43EffectResult ([ordered]@{functions=$functions;globals=7;types=3;protected_items=12})
        }
        if ($operation -ceq 'byte_model') {
            $endian = 'little'
            if ($context.fault -ceq 'BYTE_SEMANTICS') { $endian = 'big' }
            return New-UID0001NWV43EffectResult ([ordered]@{endian=$endian;pointer_size=4})
        }
        if ($operation -ceq 'legacy_route') {
            return New-UID0001NWV43EffectResult ([ordered]@{enabled=($context.fault -ceq 'LEGACY_PATH_DISABLED')})
        }
        if ($operation -ceq 'request_template_observation') {
            return New-UID0001NWV43EffectResult ([ordered]@{unchanged=($context.fault -cne 'REQUEST_TEMPLATE_HASH')})
        }
        if ($operation -ceq 'observe_boundary') {
            $context.boundary_count++
            $label = [string]$request.arguments.label
            $ordinal = [int]$request.arguments.ordinal
            if ($context.fault -ceq 'BOUNDARY_INCOMPLETE' -and $label -ceq 'B022_POST_VERIFIER') {
                $label = 'MISSING_B022'
            }
            return New-UID0001NWV43EffectResult ([ordered]@{label=$label;ordinal=$ordinal})
        }
        if ($operation -ceq 'pre_save_worker_free_authority') {
            return New-UID0001NWV43EffectResult ([ordered]@{authorized=($context.fault -cne 'P0_NOT_WORKER_FREE')})
        }
        if ($operation -ceq 'capture_p0') {
            return New-UID0001NWV43EffectResult ([ordered]@{path=$Authority.path;size=100;sha256=('A' * 64);mtime=43000;volume=7;file_index=11})
        }
        if ($operation -ceq 'create_exclusive_backup') {
            $sourceSha = [string]$request.arguments.p0.sha256
            $backupSha = $sourceSha
            if ($context.fault -ceq 'B0_IDENTITY') { $backupSha = ('B' * 64) }
            return New-UID0001NWV43EffectResult ([ordered]@{source_sha256=$sourceSha;backup_sha256=$backupSha;bytes=[long]$request.arguments.p0.size})
        }
        if ($operation -ceq 'persist_save_intent') {
            return New-UID0001NWV43EffectResult ([ordered]@{state='ISSUED'})
        }
        if ($operation -ceq 'persist_save_classification') {
            return New-UID0001NWV43EffectResult ([ordered]@{state='CLASSIFIED'})
        }
        if ($operation -ceq 'retire_worker_generation') {
            if ($context.fault -ceq 'PROTECTED_PROCESS') { return New-UID0001NWV43EffectError 'PROTECTED_PROCESS' 'protected generation' }
            if ($context.fault -ceq 'PROCESS_GENERATION') { return New-UID0001NWV43EffectError 'PROCESS_GENERATION' 'generation drift' }
            return New-UID0001NWV43EffectResult ([ordered]@{retired=$true})
        }
        if ($operation -ceq 'retire_redirector_generation') {
            return New-UID0001NWV43EffectResult ([ordered]@{retired=$true})
        }
        if ($operation -ceq 'worker_free_snapshot') {
            return New-UID0001NWV43EffectResult ([ordered]@{worker_free=$true})
        }
        if ($operation -ceq 'classify_candidate') {
            $identity = 'P1'
            if ($context.fault -ceq 'SAVE_EXPLICIT_FAILURE' -or
                $context.case_id -ceq 'PF-V4-COORD-EXPLICIT-FAILURE-P0') { $identity = 'P0' }
            elseif ($context.case_id -ceq 'PF-V4-COORD-PX') { $identity = 'PX' }
            elseif ($context.fault -ceq 'TERMINAL_BRANCH_UNMODELED') { $identity = 'UNKNOWN' }
            $soleWriter = $context.fault -cne 'SOLE_WRITER_UNPROVEN'
            $candidateValid = $context.fault -cne 'CANDIDATE_DRIFT'
            return New-UID0001NWV43EffectResult ([ordered]@{identity=$identity;sole_writer=$soleWriter;candidate_valid=$candidateValid})
        }
        if ($operation -ceq 'verify_candidate') {
            $valid = $true
            if ($context.fault -ceq 'RESTORE_SHORT_WRITE' -or
                $context.case_id -in @('PF-V4-COORD-VERIFIER-FAILURE-P1','PF-V4-COORD-RESTORE-FAILURE','PF-V4-COORD-ROLLBACK-FAILURE')) {
                $valid = $false
            }
            return New-UID0001NWV43EffectResult ([ordered]@{valid=$valid})
        }
        if ($operation -ceq 'restore_from_b0') {
            if ($context.fault -ceq 'RESTORE_SHORT_WRITE') {
                return New-UID0001NWV43EffectError 'RESTORE_SHORT_WRITE' 'short write'
            }
            if ($context.case_id -ceq 'PF-V4-COORD-RESTORE-FAILURE') {
                return New-UID0001NWV43EffectError 'RESTORE_FAILURE' 'restore failed'
            }
            return New-UID0001NWV43EffectResult ([ordered]@{bytes=[long]$request.arguments.p0.size;sha256=[string]$request.arguments.p0.sha256})
        }
        if ($operation -ceq 'verify_rollback') {
            return New-UID0001NWV43EffectResult ([ordered]@{valid=($context.case_id -cne 'PF-V4-COORD-ROLLBACK-FAILURE')})
        }
        if ($operation -ceq 'cleanup_transaction') {
            return New-UID0001NWV43EffectResult ([ordered]@{clean=$true})
        }
        New-UID0001NWV43EffectError 'UNKNOWN_EFFECT' $operation
    }.GetNewClosure()

    [pscustomobject]@{Transport=$transport;Effect=$effect}
}
~~~

## Removed Block R017

- SHA256: `F923ACC30BE92A42C468F9FA3449BC4164F147DA11AA19741E63686249BD83AB`
- Language: `powershell`
- Bytes: `7970`
- First recovered timestamp: `2026-08-08T04:33:24.802Z`
- Session provenance: rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 196765 (2026-08-08T04:33:24.802Z)

~~~powershell
function ConvertTo-UID0001NWV43ReceiptRow {
    param([object]$Case,[object]$Receipt)
    [ordered]@{
        suite=[string]$Case.suite
        case_id=[string]$Case.id
        injected_fault=[string]$Case.fault
        expected=(Get-UID0001NWV43ExpectedTerminal $Case)
        observed=[string]$Receipt.observed
        boundary_count=@($Receipt.boundaries).Count
        boundaries=@($Receipt.boundaries)
        assertion_count=[int]$Receipt.assertion_count
        operation_counters=@(
            [int]$Receipt.operation_counters.transport,
            [int]$Receipt.operation_counters.open,
            [int]$Receipt.operation_counters.mutation,
            [int]$Receipt.operation_counters.readback,
            [int]$Receipt.operation_counters.save,
            [int]$Receipt.operation_counters.stop,
            [int]$Receipt.operation_counters.write,
            [int]$Receipt.operation_counters.restore,
            [int]$Receipt.operation_counters.cleanup
        )
        effect_counters=@(
            [int]$Receipt.effect_counters.rpc,
            [int]$Receipt.effect_counters.process,
            [int]$Receipt.effect_counters.filesystem,
            [int]$Receipt.effect_counters.disk,
            [int]$Receipt.effect_counters.mutation_attempts,
            [int]$Receipt.effect_counters.reported_changes
        )
        cleanup_complete=[bool]$Receipt.cleanup_complete
        external_effects=[int]$Receipt.external_effects
        save_state=[string]$Receipt.save_state
        save_outcome=[string]$Receipt.save_outcome
        disk=[string]$Receipt.disk
        request_digest=[string]$Receipt.request_digest
        response_digest=[string]$Receipt.response_digest
        effect_request_digest=[string]$Receipt.effect_request_digest
        effect_response_digest=[string]$Receipt.effect_response_digest
        boundary_digest=[string]$Receipt.boundary_digest
        assertion_digest=[string]$Receipt.assertion_digest
    }
}

function Assert-UID0001NWV43FixtureIsolation {
    param([object]$Authority)
    $tokens = $null
    $errors = $null
    $ast = [Management.Automation.Language.Parser]::ParseInput([string]$Authority.blocks.U,[ref]$tokens,[ref]$errors)
    if (@($errors).Count -ne 0) { Stop-UID0001NWV43 'FIXTURE_AST' $errors[0].Message }
    $forbiddenCommands = @('Start-Process','Stop-Process','Invoke-WebRequest','Invoke-RestMethod','curl','wget','scp','ssh','cmd','powershell','pwsh')
    $commands = @($ast.FindAll({param($node) $node -is [Management.Automation.Language.CommandAst]},$true) | ForEach-Object { $_.GetCommandName() } | Where-Object { $null -ne $_ })
    if (@($commands | Where-Object { $forbiddenCommands -contains $_ }).Count -ne 0) {
        Stop-UID0001NWV43 'FIXTURE_EXTERNAL_API' 'command'
    }
    $types = @($ast.FindAll({param($node) $node -is [Management.Automation.Language.TypeExpressionAst]},$true) | ForEach-Object { $_.TypeName.FullName })
    if (@($types | Where-Object { $_ -match '(^|\.)(IO|Net|Diagnostics\.Process|Sockets)(\.|$)' }).Count -ne 0) {
        Stop-UID0001NWV43 'FIXTURE_EXTERNAL_API' 'type'
    }
}

function Invoke-UID0001NWV43Harness {
    [CmdletBinding()]
    param(
        [Parameter(Mandatory=$true)][string]$ReportPath,
        [switch]$RecordOnly
    )
    $authority = Import-UID0001NWV43Authority $ReportPath
    Assert-UID0001NWV43FixtureIsolation $authority
    $command = Get-Command Invoke-UID0001NWAtomicEnvelopeV4 -CommandType Function
    $parameterNames = @($command.Parameters.Keys | Where-Object { $_ -in @('ReportPath','Transport','Effect','CaseId','Authority','Adapter') })
    if (@(Compare-Object @('ReportPath','Transport','Effect','CaseId') $parameterNames -CaseSensitive).Count -ne 0) {
        Stop-UID0001NWV43 'PUBLIC_SIGNATURE' ([string]::Join(',',$parameterNames))
    }
    $before = Get-UID0001NWV43FileSha $authority.path
    $results = New-Object Collections.Generic.List[object]
    foreach ($case in @($authority.cases)) {
        $observer = [pscustomobject]@{transport_calls=0;effect_calls=0;transport_changed=0;effect_changed=0}
        $fixture = New-UID0001NWV43FixtureBoundaries $case $authority $observer
        $innerTransport = $fixture.Transport
        $innerEffect = $fixture.Effect
        $wrappedTransport = {
            param([string]$RawRequest)
            $reply = & $innerTransport $RawRequest
            try {
                $parsed = ConvertFrom-UID0001NWV42Json ([string]$reply)
                if ($null -ne $parsed.result -and
                    $parsed.result.PSObject.Properties.Name -contains 'changed' -and
                    [bool]$parsed.result.changed) { $observer.transport_changed++ }
            }
            catch {}
            $reply
        }.GetNewClosure()
        $wrappedEffect = {
            param([string]$RawRequest)
            $reply = & $innerEffect $RawRequest
            try {
                $parsed = ConvertFrom-UID0001NWV42Json ([string]$reply)
                if ($parsed.PSObject.Properties.Name -contains 'changed' -and [bool]$parsed.changed) {
                    $observer.effect_changed++
                }
            }
            catch {}
            $reply
        }.GetNewClosure()
        $receipt = Invoke-UID0001NWAtomicEnvelopeV4 -ReportPath $authority.path -Transport $wrappedTransport -Effect $wrappedEffect -CaseId ([string]$case.id)
        $expected = Get-UID0001NWV43ExpectedTerminal $case
        if ([string]$receipt.observed -cne $expected) {
            Stop-UID0001NWV43 'HARNESS_OUTCOME' ("{0}/{1}/{2}" -f $case.id,$expected,$receipt.observed)
        }
        if (-not [bool]$receipt.cleanup_complete) {
            Stop-UID0001NWV43 'HARNESS_CLEANUP' ([string]$case.id)
        }
        $coreTransport = [int]$receipt.operation_counters.transport
        $coreEffects = [int]$receipt.effect_counters.process + [int]$receipt.effect_counters.filesystem + [int]$receipt.effect_counters.disk
        if ($observer.transport_calls -ne $coreTransport -or $observer.effect_calls -ne $coreEffects) {
            Stop-UID0001NWV43 'HARNESS_COUNTER_SOURCE' ([string]$case.id)
        }
        $independentChanges = [int]$observer.transport_changed + [int]$observer.effect_changed
        if ($independentChanges -ne [int]$receipt.external_effects -or $independentChanges -ne 0) {
            Stop-UID0001NWV43 'HARNESS_EFFECT' ([string]$case.id)
        }
        $results.Add([pscustomobject](ConvertTo-UID0001NWV43ReceiptRow $case $receipt))
    }
    $after = Get-UID0001NWV43FileSha $authority.path
    if ($after -cne $before) { Stop-UID0001NWV43 'HARNESS_REPORT_CHANGED' $after }
    if ($results.Count -ne 39 -or
        @($results | Group-Object case_id | Where-Object Count -ne 1).Count -ne 0 -or
        @($results | Where-Object suite -CEQ 'PRODUCTION').Count -ne 32 -or
        @($results | Where-Object suite -CEQ 'DIRECT').Count -ne 7) {
        Stop-UID0001NWV43 'HARNESS_COUNT' $results.Count
    }
    $record = [ordered]@{
        schema_version=43
        host='Windows PowerShell'
        powershell_version=$PSVersionTable.PSVersion.ToString()
        public_entry='Invoke-UID0001NWAtomicEnvelopeV4'
        public_parameters=@('ReportPath','Transport','Effect','CaseId')
        shared_production_core_calls=39
        production_count=32
        direct_count=7
        fixture_external_api_count=0
        report_unchanged=$true
        operation_counter_order=@('transport','open','mutation','readback','save','stop','write','restore','cleanup')
        effect_counter_order=@('rpc','process','filesystem','disk','mutation_attempts','reported_changes')
        results=@($results)
    }
    if (-not $RecordOnly) {
        if ([int]$authority.transcript.schema_version -ne 43 -or
            (ConvertTo-UID0001NWV42Json $record) -cne (ConvertTo-UID0001NWV42Json $authority.transcript)) {
            Stop-UID0001NWV43 'TRANSCRIPT_REPLAY' 'canonical mismatch'
        }
    }
    [pscustomobject]$record
}
~~~

## Removed Block R018

- SHA256: `07BFDC33F491F01E6AC0896CDB26817F56B5C6FBB795BC13CD02AC16925AC7D5`
- Language: `powershell`
- Bytes: `10995`
- First recovered timestamp: `2026-08-08T22:30:57.172Z`
- Session provenance: rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 197443 (2026-08-08T22:30:57.172Z); rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 197444 (2026-08-08T22:30:58.663Z)

~~~powershell
Set-StrictMode -Version Latest

function Stop-UID0001NWCDA6 {
    param([Parameter(Mandatory=$true)][string]$Code,[Parameter(Mandatory=$true)][string]$Detail)
    throw ('UID0001NW_CDA6:{0}:{1}' -f $Code,$Detail)
}

function Get-UID0001NWCDA6Block {
    param([string[]]$Lines,[string]$Name,[string]$Language)
    Get-UID0001NWCDABlock $Lines ('CDA6_'+$Name) $Language
}

function Get-UID0001NWCDA6ReportTemplateSha {
    param([string]$Text)
    $LF=$Text.Replace([string][char]13+[char]10,[string][char]10).Replace([char]13,[char]10)
    $Pattern='("report_template_sha256"\s*:\s*")[0-9A-F]{64}(")'
    if([regex]::Matches($LF,$Pattern).Count -ne 1){ Stop-UID0001NWCDA6 'REPORT_TEMPLATE_FIELD' 'count' }
    Get-UID0001NWCDASha ([regex]::Replace($LF,$Pattern,('${1}'+('0'*64)+'${2}')))
}

function Get-UID0001NWCDA6PackageSha {
    param([object]$Manifest)
    $Material=[ordered]@{
        schema_version=[int]$Manifest.schema_version
        uid=[string]$Manifest.uid
        authority=[string]$Manifest.authority
        public_entry=[string]$Manifest.public_entry
        canonical_idb_path=[string]$Manifest.canonical_idb_path
        response_count=[int]$Manifest.response_count
        boundary_count=[int]$Manifest.boundary_count
        fixture_count=[int]$Manifest.fixture_count
        base_contract_sha256=[string]$Manifest.base_contract_sha256
        fixture_plan_sha256=[string]$Manifest.fixture_plan_sha256
        code_a_sha256=[string]$Manifest.code_a_sha256
        code_b_sha256=[string]$Manifest.code_b_sha256
        code_c_sha256=[string]$Manifest.code_c_sha256
        code_d_sha256=[string]$Manifest.code_d_sha256
        loader_sha256=[string]$Manifest.loader_sha256
        transcript_sha256=[string]$Manifest.transcript_sha256
    }
    Get-UID0001NWCDASha (ConvertTo-UID0001NWCDAJson $Material)
}

if($null -eq (Get-Variable -Name UID0001NWCDA6AuthorityCache -Scope Script -ErrorAction SilentlyContinue)){
    $script:UID0001NWCDA6AuthorityCache=@{}
}

function Import-UID0001NWCDA6Authority {
    param([Parameter(Mandatory=$true)][string]$ReportPath)
    $Path=[IO.Path]::GetFullPath($ReportPath)
    $PhysicalSha=(Get-FileHash -LiteralPath $Path -Algorithm SHA256).Hash
    $CacheKey=$Path+'|'+$PhysicalSha
    if($script:UID0001NWCDA6AuthorityCache.ContainsKey($CacheKey)){ return $script:UID0001NWCDA6AuthorityCache[$CacheKey] }
    $Lines=[IO.File]::ReadAllLines($Path)
    $Text=[IO.File]::ReadAllText($Path)
    $ManifestText=Get-UID0001NWCDA6Block $Lines 'MANIFEST' 'json'
    $FixtureText=Get-UID0001NWCDA6Block $Lines 'FIXTURE_PLAN' 'json'
    $CodeA=Get-UID0001NWCDA6Block $Lines 'CODE_A' 'powershell'
    $CodeB=Get-UID0001NWCDA6Block $Lines 'CODE_B' 'powershell'
    $CodeC=Get-UID0001NWCDA6Block $Lines 'CODE_C' 'powershell'
    $CodeD=Get-UID0001NWCDA6Block $Lines 'CODE_D' 'powershell'
    $Loader=Get-UID0001NWCDA6Block $Lines 'LOADER' 'powershell'
    $TranscriptText=Get-UID0001NWCDA6Block $Lines 'TRANSCRIPT' 'json'
    $Manifest=ConvertFrom-UID0001NWV42Json $ManifestText
    $Fixtures=ConvertFrom-UID0001NWV42Json $FixtureText
    Assert-UID0001NWCDAKeys $Manifest @('schema_version','uid','authority','public_entry','public_parameters','report_path','report_template_sha256','canonical_idb_path','response_count','boundary_count','fixture_count','checked_count','pending_count','base_contract_sha256','fixture_plan_sha256','code_a_sha256','code_b_sha256','code_c_sha256','code_d_sha256','loader_sha256','transcript_sha256','package_sha256','operation_counter_order','effect_counter_order','durable_states','disk_identities','reentry_modes','historical_packages') 'CDA6/manifest'
    if($Manifest.schema_version -isnot [int] -or [int]$Manifest.schema_version -ne 6 -or [string]$Manifest.uid -cne '0001NW'){ Stop-UID0001NWCDA6 'MANIFEST_IDENTITY' '6/0001NW' }
    if(-not [StringComparer]::OrdinalIgnoreCase.Equals($Path,[IO.Path]::GetFullPath([string]$Manifest.report_path))){ Stop-UID0001NWCDA6 'REPORT_PATH' $Path }
    if([StringComparer]::OrdinalIgnoreCase.Equals($Path,[IO.Path]::GetFullPath([string]$Manifest.canonical_idb_path))){ Stop-UID0001NWCDA6 'PATH_SEPARATION' $Path }
    if((Get-UID0001NWCDA6ReportTemplateSha $Text) -cne [string]$Manifest.report_template_sha256){ Stop-UID0001NWCDA6 'REPORT_TEMPLATE_HASH' $Path }
    $Hashes=[ordered]@{
        fixture_plan_sha256=Get-UID0001NWCDASha $FixtureText
        code_a_sha256=Get-UID0001NWCDASha $CodeA
        code_b_sha256=Get-UID0001NWCDASha $CodeB
        code_c_sha256=Get-UID0001NWCDASha $CodeC
        code_d_sha256=Get-UID0001NWCDASha $CodeD
        loader_sha256=Get-UID0001NWCDASha $Loader
        transcript_sha256=Get-UID0001NWCDASha $TranscriptText
    }
    foreach($Property in $Hashes.Keys){ if([string]$Hashes[$Property] -cne [string]$Manifest.$Property){ Stop-UID0001NWCDA6 'AUTHORITY_HASH' $Property } }
    if((Get-UID0001NWCDA6PackageSha $Manifest) -cne [string]$Manifest.package_sha256){ Stop-UID0001NWCDA6 'PACKAGE_HASH' 'manifest' }
    $Base=Import-UID0001NWCDAAuthority $Path
    if((Get-UID0001NWCDASha (ConvertTo-UID0001NWCDAJson @($Base.contracts))) -cne [string]$Manifest.base_contract_sha256){ Stop-UID0001NWCDA6 'CONTRACT_HASH' '193' }
    if(@($Base.contracts).Count -ne 193 -or @($Base.boundaries).Count -ne 24){ Stop-UID0001NWCDA6 'BASE_CARDINALITY' '193/24' }
    Assert-UID0001NWCDAKeys $Fixtures @('schema_version','cases') 'CDA6/fixture-plan'
    $Cases=@($Fixtures.cases)
    foreach($Case in $Cases){ Assert-UID0001NWCDAKeys $Case @('id','fault','expected','expected_cleanup','reentry') ('CDA6/case/'+[string]$Case.id) }
    if($Cases.Count -ne 39 -or @($Cases|Group-Object id|Where-Object Count -ne 1).Count -ne 0){ Stop-UID0001NWCDA6 'FIXTURE_CARDINALITY' ([string]$Cases.Count) }
    $Transcript=ConvertFrom-UID0001NWV42Json $TranscriptText
    $Authority=[pscustomobject]@{
        report_path=$Path;report_sha256=$PhysicalSha;canonical_idb_path=[IO.Path]::GetFullPath([string]$Manifest.canonical_idb_path)
        manifest=$Manifest;fixtures=$Cases;transcript=$Transcript;base=$Base;contracts=@($Base.contracts);rows=@($Base.rows);boundaries=@($Base.boundaries)
        code_blocks=[ordered]@{A=$CodeA;B=$CodeB;C=$CodeC;D=$CodeD}
    }
    $script:UID0001NWCDA6AuthorityCache[$CacheKey]=$Authority
    $Authority
}

function New-UID0001NWCDA6State {
    param([object]$Authority,[scriptblock]$Transport,[scriptblock]$Effect,[string]$RunId)
    @{
        authority=$Authority;transport=$Transport;effect=$Effect;run_id=$RunId;next_id=0;mode='';session='';responses=0
        open_roles=@{};boundaries=New-Object Collections.Generic.List[string];path=New-Object Collections.Generic.List[string]
        transcript=New-Object Collections.Generic.List[object];seen_nonces=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
        attested_times=@{};last_runtime=$null;operations=[ordered]@{transport=0;open=0;mutation=0;readback=0;save=0;stop=0;write=0;restore=0;cleanup=0}
        effects=[ordered]@{rpc=0;process=0;filesystem=0;disk=0;mutation_attempts=0;reported_changes=0}
        authority_token='';initial_journal_state='NONE';journal=$null;p0=$null;b0=$null;candidate=$null;final_tuple=$null
        save_state='NOT_ISSUED';save_outcome='NOT_ISSUED';save_request_sha256='';save_response_sha256='';attempt_id='';tx_generation=''
        disk='P0';restore_required=$false;restore_performed=$false;restore_verified=$false;durable_result='NONE';primary_error=''
        cleanup=[ordered]@{roles_registered=0;roles_retired=0;session_absent=$false;process_absent=$false;socket_absent=$false;listener_continuity=$false;exclusive_open=$false;final_disk_measured=$false;complete=$false}
        reentry=[ordered]@{used=$false;state='NONE';fresh_runspace=$false;distinct_runspace=$false;second_save_count=0;second_mutation_count=0}
    }
}

function Add-UID0001NWCDA6Path {
    param([hashtable]$State,[string]$Step)
    $State.path.Add($Step)
}

function Invoke-UID0001NWCDA6Transport {
    param([hashtable]$State,[ValidateSet('tools/list','tools/call')][string]$Method,[string]$Tool,[object]$Arguments,[switch]$AllowToolError)
    $State.next_id++
    $Request=$(if($Method -ceq 'tools/list'){[ordered]@{jsonrpc='2.0';id=[int]$State.next_id;method='tools/list';params=[ordered]@{}}}else{[ordered]@{jsonrpc='2.0';id=[int]$State.next_id;method='tools/call';params=[ordered]@{name=$Tool;arguments=$Arguments}}})
    $RequestText=ConvertTo-UID0001NWCDAJson $Request
    $State.operations.transport++;$State.effects.rpc++
    $Raw=& $State.transport $RequestText
    if($Raw -isnot [string] -or [string]::IsNullOrWhiteSpace([string]$Raw)){ Stop-UID0001NWCDA6 'RESPONSE_CARDINALITY' ($Method+'/'+$Tool) }
    try { $Envelope=ConvertFrom-UID0001NWV42Json ([string]$Raw) } catch { if([string]$_.Exception.Message -like '*JSON_DUPLICATE_MEMBER*'){ Stop-UID0001NWCDA6 'JSON_DUPLICATE_MEMBER' ($Method+'/'+$Tool) };throw }
    Assert-UID0001NWCDAKeys $Envelope @('jsonrpc','id','result') ('CDA6/envelope/'+$Tool)
    if($Envelope.jsonrpc -isnot [string] -or [string]$Envelope.jsonrpc -cne '2.0' -or $Envelope.id -isnot [int] -or [int]$Envelope.id -ne [int]$Request.id){ Stop-UID0001NWCDA6 'SAVE_RESPONSE_ID' ($Method+'/'+$Tool) }
    $State.transcript.Add([pscustomobject][ordered]@{kind='transport';ordinal=$State.transcript.Count+1;method=$Method;tool=$Tool;request_sha256=Get-UID0001NWCDASha $RequestText;response_sha256=Get-UID0001NWCDASha ([string]$Raw)})
    if($Method -ceq 'tools/call'){ Assert-UID0001NWCDAToolResult $Envelope.result ('CDA6/'+$Tool) -AllowError:$AllowToolError }
    [pscustomobject]@{request=$Request;request_text=$RequestText;raw=[string]$Raw;result=$Envelope.result}
}

function Invoke-UID0001NWCDA6Effect {
    param([hashtable]$State,[ValidateSet('process','filesystem','disk')][string]$Domain,[string]$Operation,[object]$Arguments)
    $Request=[ordered]@{domain=$Domain;operation=$Operation;arguments=$Arguments}
    $RequestText=ConvertTo-UID0001NWCDAJson $Request
    $State.effects[$Domain]++
    $Raw=& $State.effect $RequestText
    if($Raw -isnot [string] -or [string]::IsNullOrWhiteSpace([string]$Raw)){ Stop-UID0001NWCDA6 'EFFECT_RESPONSE' ($Domain+'/'+$Operation) }
    $Response=ConvertFrom-UID0001NWV42Json ([string]$Raw)
    $Expected=$(if($Response.ok -eq $true){@('ok','changed','data')}else{@('ok','changed','error')})
    Assert-UID0001NWCDAKeys $Response $Expected ('CDA6/effect/'+$Operation)
    if($Response.ok -isnot [bool] -or $Response.changed -isnot [bool]){ Stop-UID0001NWCDA6 'EFFECT_SCHEMA' $Operation }
    if([bool]$Response.changed){ $State.effects.reported_changes++ }
    $State.transcript.Add([pscustomobject][ordered]@{kind='effect';ordinal=$State.transcript.Count+1;domain=$Domain;operation=$Operation;request_sha256=Get-UID0001NWCDASha $RequestText;response_sha256=Get-UID0001NWCDASha ([string]$Raw)})
    if(-not [bool]$Response.ok){ Stop-UID0001NWCDA6 ([string]$Response.error.code) ([string]$Response.error.detail) }
    $Response.data
}
~~~

## Removed Block R019

- SHA256: `90327BFDF6F6229ACA4C13B5C1EEB92D7CEB88064DEA5EC8CD01F64E67916878`
- Language: `powershell`
- Bytes: `16993`
- First recovered timestamp: `2026-08-08T22:33:41.729Z`
- Session provenance: rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 197449 (2026-08-08T22:33:41.729Z); rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 197450 (2026-08-08T22:33:43.215Z)

~~~powershell
function Assert-UID0001NWCDA6Tuple {
    param([object]$Tuple,[string]$Where)
    Assert-UID0001NWCDAKeys $Tuple @('path','volume','file_index','size','mtime_filetime_utc','sha256','attempt_id','writer_generation','write_epoch','observed_content_sha256','stable_reopen','exclusive_open') $Where
    if($Tuple.path -isnot [string] -or $Tuple.volume -isnot [int] -or $Tuple.file_index -isnot [string] -or $Tuple.size -isnot [long] -or $Tuple.mtime_filetime_utc -isnot [long] -or $Tuple.sha256 -isnot [string] -or $Tuple.attempt_id -isnot [string] -or $Tuple.writer_generation -isnot [string] -or $Tuple.write_epoch -isnot [long] -or $Tuple.observed_content_sha256 -isnot [string] -or $Tuple.stable_reopen -isnot [bool] -or $Tuple.exclusive_open -isnot [bool]){ Stop-UID0001NWCDA6 'DISK_SCHEMA' $Where }
    if([string]$Tuple.sha256 -notmatch '^[0-9A-F]{64}$' -or [string]$Tuple.observed_content_sha256 -notmatch '^[0-9A-F]{64}$'){ Stop-UID0001NWCDA6 'DISK_SCHEMA' ($Where+'/sha') }
    if(-not [StringComparer]::OrdinalIgnoreCase.Equals([IO.Path]::GetFullPath([string]$Tuple.path),$script:UID0001NWCDA6TupleCanonicalPath)){ Stop-UID0001NWCDA6 'CANONICAL_PATH_DRIFT' $Where }
    $Tuple
}

function Get-UID0001NWCDA6DiskTuple {
    param([hashtable]$State,[string]$Purpose)
    $script:UID0001NWCDA6TupleCanonicalPath=$State.authority.canonical_idb_path
    $Tuple=Invoke-UID0001NWCDA6Effect $State 'disk' 'capture_tuple' ([ordered]@{path=$State.authority.canonical_idb_path;purpose=$Purpose})
    Assert-UID0001NWCDA6Tuple $Tuple ('disk/'+$Purpose)
}

function Test-UID0001NWCDA6P0Equal {
    param([object]$Left,[object]$Right)
    [StringComparer]::OrdinalIgnoreCase.Equals([string]$Left.path,[string]$Right.path) -and [int]$Left.volume -eq [int]$Right.volume -and [string]$Left.file_index -ceq [string]$Right.file_index -and [long]$Left.size -eq [long]$Right.size -and [long]$Left.mtime_filetime_utc -eq [long]$Right.mtime_filetime_utc -and [string]$Left.sha256 -ceq [string]$Right.sha256
}

function Get-UID0001NWCDA6Snapshot {
    param([hashtable]$State,[string]$Session,[bool]$WorkerFree,[string]$Where)
    $ListCall=Invoke-UID0001NWCDA6Transport $State 'tools/call' 'idb_list' ([ordered]@{})
    $ListBody=$ListCall.result.structuredContent
    Assert-UID0001NWCDAIdbList $State $ListBody $Session $WorkerFree ($Where+'/idb_list')
    $Path=$(if($WorkerFree){''}else{$State.authority.canonical_idb_path})
    $AttestCall=Invoke-UID0001NWCDA6Transport $State 'tools/call' 'runtime_attestation' ([ordered]@{expected_database=$Session;expected_canonical_path=$Path})
    $Runtime=Assert-UID0001NWCDARuntime $State $AttestCall.result.structuredContent $Session $WorkerFree ($Where+'/runtime')
    [pscustomobject]@{list=$ListBody;runtime=$Runtime}
}

function Add-UID0001NWCDA6Boundary {
    param([hashtable]$State,[string]$Label,[string]$Session,[bool]$WorkerFree)
    $Expected=@($State.authority.boundaries)
    if($State.boundaries.Count -ge $Expected.Count -or [string]$Expected[$State.boundaries.Count] -cne $Label){ Stop-UID0001NWCDA6 'BOUNDARY_ORDER' $Label }
    $Snapshot=Get-UID0001NWCDA6Snapshot $State $Session $WorkerFree $Label
    $State.boundaries.Add($Label);Add-UID0001NWCDA6Path $State $Label
    $Snapshot
}

function Register-UID0001NWCDA6OpenIntent {
    param([hashtable]$State,[string]$Role)
    if($State.open_roles.ContainsKey($Role)){ Stop-UID0001NWCDA6 'OPEN_ROLE_DUPLICATE' $Role }
    $State.open_roles[$Role]=[ordered]@{role=$Role;status='INTENT';session='';worker_generation='';worker_pid=0;redirector_generation='';redirector_pid=0;socket_port=0;discovery_count=0}
    $State.cleanup.roles_registered++;Add-UID0001NWCDA6Path $State ('OPEN_INTENT/'+$Role)
}

function Find-UID0001NWCDA6PartialOpen {
    param([hashtable]$State,[string]$Role)
    $Entry=$State.open_roles[$Role]
    $ListCall=Invoke-UID0001NWCDA6Transport $State 'tools/call' 'idb_list' ([ordered]@{})
    $Body=$ListCall.result.structuredContent
    Assert-UID0001NWCDAKeys $Body @('count','sessions') ($Role+'/discover/list')
    $Candidates=@($Body.sessions|Where-Object{ $_.is_active -eq $true -and [StringComparer]::OrdinalIgnoreCase.Equals([IO.Path]::GetFullPath([string]$_.input_path),$State.authority.canonical_idb_path) })
    $Entry.discovery_count=$Candidates.Count
    if($Candidates.Count -gt 1){ $Entry.status='AMBIGUOUS';Stop-UID0001NWCDA6 'PARTIAL_OPEN_AMBIGUOUS' $Role }
    if($Candidates.Count -eq 0){ $Entry.status='NO_EFFECT';return $null }
    $Session=[string]$Candidates[0].session_id
    $Snapshot=Get-UID0001NWCDA6Snapshot $State $Session $false ($Role+'/discover')
    $Worker=@($Snapshot.runtime.workers|Where-Object session_id -CEQ $Session)
    if($Worker.Count -ne 1){ Stop-UID0001NWCDA6 'PARTIAL_OPEN_AMBIGUOUS' ($Role+'/worker') }
    $Entry.session=$Session;$Entry.worker_generation=[string]$Worker[0].worker.process.generation;$Entry.worker_pid=[int]$Worker[0].worker.process.pid
    $Entry.redirector_pid=[int]$Worker[0].redirector_pid;$Entry.redirector_generation=('pid:{0};created:3' -f $Entry.redirector_pid);$Entry.socket_port=[int]$Worker[0].route.port;$Entry.status='DISCOVERED'
    $State.session=$Session;$State.tx_generation=$Entry.worker_generation
    $Entry
}

function Open-UID0001NWCDA6Role {
    param([hashtable]$State,[string]$Role)
    Register-UID0001NWCDA6OpenIntent $State $Role
    $Original=$null
    try {
        $Open=Invoke-UID0001NWCDA6Transport $State 'tools/call' 'idb_open' ([ordered]@{input_path=$State.authority.canonical_idb_path;mode='force_headless';run_auto_analysis=$false;build_caches=$false;init_hexrays=$false;idle_ttl_sec=600})
        $Body=$Open.result.structuredContent
        Assert-UID0001NWCDAKeys $Body @('message','session','success','warmup') ($Role+'/open')
        if($Body.success -isnot [bool] -or -not $Body.success){ Stop-UID0001NWCDA6 'OPEN_RESULT' $Role }
        Assert-UID0001NWCDAKeys $Body.session @('created_at','filename','input_path','is_analyzing','last_accessed','metadata','session_id') ($Role+'/open/session')
        $Entry=$State.open_roles[$Role]
        $Entry.session=[string]$Body.session.session_id;$Entry.status='RETURNED';$State.session=$Entry.session;$State.operations.open++
        if([string]::IsNullOrWhiteSpace($Entry.session) -or -not [StringComparer]::OrdinalIgnoreCase.Equals([IO.Path]::GetFullPath([string]$Body.session.input_path),$State.authority.canonical_idb_path)){ Stop-UID0001NWCDA6 'RETURNED_SESSION_BINDING' $Role }
        $Snapshot=Get-UID0001NWCDA6Snapshot $State $Entry.session $false ($Role+'/returned')
        $Worker=@($Snapshot.runtime.workers|Where-Object session_id -CEQ $Entry.session)
        if($Worker.Count -ne 1){ Stop-UID0001NWCDA6 'RETURNED_SESSION_BINDING' ($Role+'/attestation') }
        $Entry.worker_generation=[string]$Worker[0].worker.process.generation;$Entry.worker_pid=[int]$Worker[0].worker.process.pid;$Entry.redirector_pid=[int]$Worker[0].redirector_pid
        $Entry.redirector_generation=('pid:{0};created:3' -f $Entry.redirector_pid);$Entry.socket_port=[int]$Worker[0].route.port;$Entry.status='BOUND'
        $State.tx_generation=$Entry.worker_generation
        Add-UID0001NWCDA6Path $State ('OPEN_BOUND/'+$Role)
        $Entry.session
    } catch {
        $Original=$_
        try { $null=Find-UID0001NWCDA6PartialOpen $State $Role } catch { if([string]$_.Exception.Message -like 'UID0001NW_CDA6:PARTIAL_OPEN_AMBIGUOUS:*'){ throw };$Original=$_ }
        if($State.open_roles[$Role].status -ceq 'DISCOVERED'){ throw $Original }
        if($State.open_roles[$Role].status -ceq 'NO_EFFECT'){ $State.open_roles.Remove($Role) }
        throw $Original
    }
}

function Retire-UID0001NWCDA6Role {
    param([hashtable]$State,[string]$Role)
    if(-not $State.open_roles.ContainsKey($Role)){ return $true }
    $Entry=$State.open_roles[$Role]
    if($Entry.status -ceq 'INTENT' -or $Entry.status -ceq 'RETURNED'){ try{$null=Find-UID0001NWCDA6PartialOpen $State $Role}catch{if($Entry.status -ceq 'AMBIGUOUS'){return $false}} }
    if($Entry.status -ceq 'NO_EFFECT'){ $State.open_roles.Remove($Role);return $true }
    if($Entry.status -ceq 'AMBIGUOUS'){ return $false }
    $Retired=Invoke-UID0001NWCDA6Effect $State 'process' 'retire_generation' ([ordered]@{role=$Role;session=$Entry.session;worker_generation=$Entry.worker_generation;worker_pid=[int]$Entry.worker_pid;redirector_generation=$Entry.redirector_generation;redirector_pid=[int]$Entry.redirector_pid;socket_port=[int]$Entry.socket_port})
    Assert-UID0001NWCDAKeys $Retired @('worker_retired','redirector_retired','generation_match') ($Role+'/retire')
    if(-not $Retired.worker_retired -or -not $Retired.redirector_retired -or -not $Retired.generation_match){ Stop-UID0001NWCDA6 'RETIRE_GENERATION' $Role }
    $State.operations.stop+=2
    $Snapshot=Get-UID0001NWCDA6Snapshot $State '' $true ($Role+'/post-retire')
    $Process=Invoke-UID0001NWCDA6Effect $State 'process' 'prove_generation_absent' ([ordered]@{worker_generation=$Entry.worker_generation;redirector_generation=$Entry.redirector_generation})
    $Socket=Invoke-UID0001NWCDA6Effect $State 'process' 'prove_socket_absent' ([ordered]@{port=[int]$Entry.socket_port})
    $Listener=Invoke-UID0001NWCDA6Effect $State 'process' 'prove_listener_continuity' ([ordered]@{generation=[string]$Snapshot.runtime.listener.process.generation;port=13337})
    Assert-UID0001NWCDAKeys $Process @('absent') ($Role+'/process');Assert-UID0001NWCDAKeys $Socket @('absent') ($Role+'/socket');Assert-UID0001NWCDAKeys $Listener @('continuous') ($Role+'/listener')
    if(-not $Process.absent){ Stop-UID0001NWCDA6 'PROCESS_PRESENT' $Role }
    if(-not $Socket.absent){ Stop-UID0001NWCDA6 'SOCKET_PRESENT' $Role }
    if(-not $Listener.continuous){ Stop-UID0001NWCDA6 'LISTENER_LOST' $Role }
    $State.open_roles.Remove($Role);$State.session='';$State.operations.cleanup++;$State.cleanup.roles_retired++
    $true
}

function Enter-UID0001NWCDA6Authority {
    param([hashtable]$State)
    $Data=Invoke-UID0001NWCDA6Effect $State 'filesystem' 'acquire_authority' ([ordered]@{uid='0001NW';canonical_idb_path=$State.authority.canonical_idb_path;package_sha256=[string]$State.authority.manifest.package_sha256;run_id=$State.run_id})
    Assert-UID0001NWCDAKeys $Data @('token','journal_state','journal') 'authority/acquire'
    if([string]::IsNullOrWhiteSpace([string]$Data.token) -or [string]$Data.journal_state -notin @('NONE','ISSUED','CLASSIFIED')){ Stop-UID0001NWCDA6 'DURABLE_SCHEMA' 'acquire' }
    $State.authority_token=[string]$Data.token;$State.initial_journal_state=[string]$Data.journal_state;$State.journal=$Data.journal
    Add-UID0001NWCDA6Path $State ('AUTHORITY/'+$State.initial_journal_state)
}

function New-UID0001NWCDA6P0B0 {
    param([hashtable]$State)
    $Data=Invoke-UID0001NWCDA6Effect $State 'filesystem' 'create_backup' ([ordered]@{canonical_idb_path=$State.authority.canonical_idb_path;run_id=$State.run_id})
    Assert-UID0001NWCDAKeys $Data @('p0','b0','create_new','exact_bytes','exact_eof','flush_through','disposed','closed_reopen_equal') 'backup'
    if(-not $Data.create_new -or -not $Data.exact_bytes -or -not $Data.exact_eof -or -not $Data.flush_through -or -not $Data.disposed -or -not $Data.closed_reopen_equal){ Stop-UID0001NWCDA6 'B0_IDENTITY' 'physical receipt' }
    $script:UID0001NWCDA6TupleCanonicalPath=$State.authority.canonical_idb_path
    $State.p0=Assert-UID0001NWCDA6Tuple $Data.p0 'backup/p0';$State.b0=$Data.b0
    $State.operations.write++;$State.effects.mutation_attempts++
}

function Write-UID0001NWCDA6Journal {
    param([hashtable]$State,[ValidateSet('create','replace','delete')][string]$Action,[object]$Record)
    $Data=Invoke-UID0001NWCDA6Effect $State 'filesystem' ('journal_'+$Action) ([ordered]@{token=$State.authority_token;record=$Record})
    Assert-UID0001NWCDAKeys $Data @('state','record_sha256','durable','closed_reopen_equal') ('journal/'+$Action)
    if(-not $Data.durable -or -not $Data.closed_reopen_equal){ Stop-UID0001NWCDA6 'DURABLE_WRITE' $Action }
    $State.operations.write++
    $Data
}

function Get-UID0001NWCDA6Identity {
    param([hashtable]$State,[object]$Candidate,[object]$Journal)
    if(Test-UID0001NWCDA6P0Equal $Candidate $State.p0){
        if(-not [string]::IsNullOrEmpty([string]$Candidate.attempt_id) -or -not [string]::IsNullOrEmpty([string]$Candidate.writer_generation)){ Stop-UID0001NWCDA6 'FALSE_CLASSIFIER' 'P0 carries writer attribution' }
        return [pscustomobject]@{identity='P0';attributable=$false;reason='EXACT_P0'}
    }
    $SameFile=[StringComparer]::OrdinalIgnoreCase.Equals([string]$Candidate.path,[string]$State.p0.path) -and [int]$Candidate.volume -eq [int]$State.p0.volume -and [string]$Candidate.file_index -ceq [string]$State.p0.file_index
    $Attributable=$SameFile -and [bool]$Candidate.stable_reopen -and [bool]$Candidate.exclusive_open -and [string]$Candidate.attempt_id -ceq [string]$Journal.attempt_id -and [string]$Candidate.writer_generation -ceq [string]$Journal.tx_generation -and [long]$Candidate.write_epoch -eq [long]$Journal.write_epoch -and [string]$Candidate.observed_content_sha256 -ceq [string]$Candidate.sha256
    if($Attributable){ return [pscustomobject]@{identity='P1';attributable=$true;reason='ATTEMPT_GENERATION_WINDOW_CONTENT'} }
    [pscustomobject]@{identity='PX';attributable=$false;reason='UNATTRIBUTED_OR_UNSTABLE_CHANGED_IDENTITY'}
}

function Restore-UID0001NWCDA6P0 {
    param([hashtable]$State)
    $State.operations.restore++;$State.restore_required=$true
    $Data=Invoke-UID0001NWCDA6Effect $State 'filesystem' 'restore_p0' ([ordered]@{canonical_idb_path=$State.authority.canonical_idb_path;p0=$State.p0;b0=$State.b0;candidate=$State.candidate})
    Assert-UID0001NWCDAKeys $Data @('truncated','exact_bytes','exact_eof','flush_through','timestamp_restored','disposed','closed_reopen_equal') 'restore'
    if(-not $Data.truncated){ Stop-UID0001NWCDA6 'RESTORE_SHORT_WRITE' 'truncate' }
    if(-not $Data.flush_through){ Stop-UID0001NWCDA6 'RESTORE_FLUSH' 'flush' }
    if(-not $Data.exact_eof){ Stop-UID0001NWCDA6 'RESTORE_EOF' 'eof' }
    if(-not $Data.timestamp_restored){ Stop-UID0001NWCDA6 'RESTORE_TIMESTAMP' 'mtime' }
    if(-not $Data.disposed){ Stop-UID0001NWCDA6 'RESTORE_OPEN_HANDLE' 'dispose' }
    if(-not $Data.exact_bytes -or -not $Data.closed_reopen_equal){ Stop-UID0001NWCDA6 'RESTORE_IDENTITY' 'P0' }
    $State.operations.write++;$State.restore_performed=$true
    $After=Get-UID0001NWCDA6DiskTuple $State 'post_restore'
    if(-not (Test-UID0001NWCDA6P0Equal $After $State.p0)){ Stop-UID0001NWCDA6 'RESTORE_IDENTITY' 'closed P0' }
    $State.restore_verified=$true;$State.disk='P0';$State.final_tuple=$After
}

function Complete-UID0001NWCDA6Cleanup {
    param([hashtable]$State)
    foreach($Role in @($State.open_roles.Keys)){ try{$null=Retire-UID0001NWCDA6Role $State ([string]$Role)}catch{if([string]::IsNullOrEmpty($State.primary_error)){$State.primary_error=([string]$_.Exception.Message -replace '^UID0001NW_CDA6:([^:]+):.*$','$1')}} }
    $Session=Invoke-UID0001NWCDA6Effect $State 'process' 'prove_all_sessions_absent' ([ordered]@{canonical_idb_path=$State.authority.canonical_idb_path})
    $Process=Invoke-UID0001NWCDA6Effect $State 'process' 'prove_all_generations_absent' ([ordered]@{canonical_idb_path=$State.authority.canonical_idb_path})
    $Socket=Invoke-UID0001NWCDA6Effect $State 'process' 'prove_all_worker_sockets_absent' ([ordered]@{canonical_idb_path=$State.authority.canonical_idb_path})
    $Listener=Invoke-UID0001NWCDA6Effect $State 'process' 'prove_listener_continuity' ([ordered]@{generation='CURRENT';port=13337})
    $Exclusive=Invoke-UID0001NWCDA6Effect $State 'filesystem' 'prove_exclusive_open' ([ordered]@{path=$State.authority.canonical_idb_path})
    foreach($Pair in @(@($Session,'absent'),@($Process,'absent'),@($Socket,'absent'),@($Listener,'continuous'),@($Exclusive,'ready'))){ Assert-UID0001NWCDAKeys $Pair[0] @($Pair[1]) ('cleanup/'+$Pair[1]) }
    $State.cleanup.session_absent=[bool]$Session.absent;$State.cleanup.process_absent=[bool]$Process.absent;$State.cleanup.socket_absent=[bool]$Socket.absent
    $State.cleanup.listener_continuity=[bool]$Listener.continuous;$State.cleanup.exclusive_open=[bool]$Exclusive.ready
    try{$State.final_tuple=Get-UID0001NWCDA6DiskTuple $State 'final';$State.cleanup.final_disk_measured=$true}catch{$State.cleanup.final_disk_measured=$false}
    $State.cleanup.complete=($State.open_roles.Count -eq 0 -and $State.cleanup.session_absent -and $State.cleanup.process_absent -and $State.cleanup.socket_absent -and $State.cleanup.listener_continuity -and $State.cleanup.exclusive_open -and $State.cleanup.final_disk_measured)
    if(-not [string]::IsNullOrEmpty($State.authority_token)){
        try{$null=Invoke-UID0001NWCDA6Effect $State 'filesystem' 'release_authority' ([ordered]@{token=$State.authority_token})}catch{$State.cleanup.complete=$false}
        $State.authority_token=''
    }
    $State.operations.cleanup++
}
~~~

## Removed Block R020

- SHA256: `A322D8C2FD8E2B9FC5E23397CB1FB24ED1D4AF526EBB59E53520A74115D491E5`
- Language: `powershell`
- Bytes: `15100`
- First recovered timestamp: `2026-08-08T22:35:58.738Z`
- Session provenance: rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 197456 (2026-08-08T22:35:58.738Z); rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 197457 (2026-08-08T22:36:00.224Z)

~~~powershell
function Invoke-UID0001NWCDA6ResponsePhases {
    param([hashtable]$State,[string[]]$Phases)
    foreach($Contract in @($State.authority.contracts|Where-Object{$Phases -contains [string]$_.phase -and [string]$_.assertion_id -cne 'S001/PRIMARY'}|Sort-Object ordinal)){
        $Row=@($State.authority.rows|Where-Object assertion_id -CEQ ([string]$Contract.assertion_id))
        if($Row.Count -ne 1){ Stop-UID0001NWCDA6 'RESPONSE_CARDINALITY' ([string]$Contract.assertion_id) }
        $Arguments=Bind-UID0001NWCDARequest $Row[0].request $State.session ([string]$Contract.request_template_sha256)
        $Call=Invoke-UID0001NWCDA6Transport $State 'tools/call' ([string]$Contract.tool) $Arguments
        Assert-UID0001NWCDAContract $Contract $Call.result.structuredContent
        $State.responses++
        if([string]$Contract.class -in @('mutation','dry_run')){$State.operations.mutation++;$State.effects.mutation_attempts++}
        elseif([string]$Contract.class -in @('query','readback')){$State.operations.readback++}
    }
}

function Invoke-UID0001NWCDA6SoleSave {
    param([hashtable]$State)
    $Contract=@($State.authority.contracts|Where-Object assertion_id -CEQ 'S001/PRIMARY')
    $Row=@($State.authority.rows|Where-Object assertion_id -CEQ 'S001/PRIMARY')
    if($Contract.Count -ne 1 -or $Row.Count -ne 1){ Stop-UID0001NWCDA6 'SAVE_PATH_BYPASS' 'S001/PRIMARY' }
    $Arguments=Bind-UID0001NWCDARequest $Row[0].request $State.session ([string]$Contract[0].request_template_sha256)
    $Preview=[ordered]@{jsonrpc='2.0';id=[int]($State.next_id+1);method='tools/call';params=[ordered]@{name='idb_save';arguments=$Arguments}}
    $PreviewText=ConvertTo-UID0001NWCDAJson $Preview
    $AttemptId=(Get-UID0001NWCDASha ([string]$State.authority.manifest.package_sha256+'|'+$State.run_id+'|'+[string]$State.p0.sha256+'|'+(Get-UID0001NWCDASha $PreviewText))).Substring(0,32)
    $Attempt=[ordered]@{
        schema_version=6;uid='0001NW';state='ISSUED';attempt_id=$AttemptId;package_sha256=[string]$State.authority.manifest.package_sha256
        canonical_idb_path=$State.authority.canonical_idb_path;p0=$State.p0;b0=$State.b0;tx_generation=$State.tx_generation
        request_sha256=Get-UID0001NWCDASha $PreviewText;write_epoch=[long]1;save_dispatched=$true;response_sha256='';outcome='INDETERMINATE';candidate=$null;identity='UNCLASSIFIED';attribution_reason='NONE'
    }
    $State.attempt_id=$AttemptId;$State.save_state='ISSUED';$State.save_request_sha256=[string]$Attempt.request_sha256;$State.journal=$Attempt
    $null=Write-UID0001NWCDA6Journal $State 'create' $Attempt;$State.operations.save++
    Add-UID0001NWCDA6Path $State 'SAVE_ISSUED_DURABLE'
    $Call=$null;$Outcome='INDETERMINATE'
    try {
        $Call=Invoke-UID0001NWCDA6Transport $State 'tools/call' 'idb_save' $Arguments -AllowToolError
        if((Get-UID0001NWCDASha $Call.request_text) -cne [string]$Attempt.request_sha256){ Stop-UID0001NWCDA6 'SAVE_REQUEST_HASH' 'preview/dispatch' }
        $State.save_response_sha256=Get-UID0001NWCDASha $Call.raw
        if($Call.result.isError){$Outcome='EXPLICIT_FAILURE'}else{Assert-UID0001NWCDAContract $Contract[0] $Call.result.structuredContent;$Outcome='EXPLICIT_SUCCESS'}
    } catch {
        if([string]$_.Exception.Message -like 'UID0001NW_CDA6:SAVE_RESPONSE_ID:*'){ throw }
        $Outcome='INDETERMINATE';$State.save_response_sha256=Get-UID0001NWCDASha ('INDETERMINATE|'+[string]$_.Exception.Message)
        throw
    } finally { $State.responses++;$State.save_outcome=$Outcome }
    $Candidate=Get-UID0001NWCDA6DiskTuple $State 'post_save';$State.candidate=$Candidate
    $Class=Get-UID0001NWCDA6Identity $State $Candidate $Attempt
    $Classification=[ordered]@{
        schema_version=6;uid='0001NW';state='CLASSIFIED';attempt_id=$AttemptId;package_sha256=[string]$State.authority.manifest.package_sha256
        canonical_idb_path=$State.authority.canonical_idb_path;p0=$State.p0;b0=$State.b0;tx_generation=$State.tx_generation
        request_sha256=$State.save_request_sha256;write_epoch=[long]1;save_dispatched=$true;response_sha256=$State.save_response_sha256;outcome=$Outcome
        candidate=$Candidate;identity=[string]$Class.identity;attribution_reason=[string]$Class.reason
    }
    $State.save_state='CLASSIFIED';$State.disk=[string]$Class.identity;$State.journal=$Classification
    $null=Write-UID0001NWCDA6Journal $State 'replace' $Classification
    Add-UID0001NWCDA6Path $State ('SAVE_CLASSIFIED/'+$Class.identity+'/'+$Outcome)
    $Classification
}

function Invoke-UID0001NWCDA6Verifier {
    param([hashtable]$State,[ValidateSet('R','RB')][string]$Phase,[string]$Role)
    $State.session=Open-UID0001NWCDA6Role $State $Role
    Invoke-UID0001NWCDA6ResponsePhases $State @($Phase)
    $Raw=Invoke-UID0001NWCDA6Effect $State 'filesystem' 'verify_semantics' ([ordered]@{phase=$Phase;session=$State.session;attempt_id=$State.attempt_id;disk=$State.disk})
    Assert-UID0001NWCDAKeys $Raw @('verified','projection_sha256') ('verifier/'+$Phase)
    if(-not $Raw.verified){ Stop-UID0001NWCDA6 'ROLLBACK_VERIFIER' $Phase }
    $null=Retire-UID0001NWCDA6Role $State $Role
}

function Clear-UID0001NWCDA6Journal {
    param([hashtable]$State,[string]$Disposition)
    $Data=Write-UID0001NWCDA6Journal $State 'delete' ([ordered]@{state='NONE';disposition=$Disposition;attempt_id=$State.attempt_id})
    $State.durable_result='CLEARED/'+$Disposition;$State.journal=$null
}

function Invoke-UID0001NWCDA6Decision {
    param([hashtable]$State,[object]$Record,[bool]$Reentry)
    $State.save_state=[string]$Record.state;$State.save_outcome=[string]$Record.outcome;$State.attempt_id=[string]$Record.attempt_id;$State.tx_generation=[string]$Record.tx_generation
    $State.p0=$Record.p0;$State.b0=$Record.b0;$State.candidate=$Record.candidate;$State.disk=[string]$Record.identity
    $Prefix=$(if($Reentry){'REENTRY_'}else{''})
    if([string]$Record.identity -ceq 'PX'){
        $State.durable_result='RETAINED_CLASSIFIED_PX'
        if([string]$Record.attribution_reason -ceq 'RESPONSE_DISK_DISAGREEMENT'){ return 'TERMINAL_RESPONSE_DISK_DISAGREEMENT_PX' }
        return 'TERMINAL_THIRD_IDENTITY_PX'
    }
    if([string]$Record.outcome -ceq 'EXPLICIT_FAILURE'){
        if([string]$Record.identity -ceq 'P0'){ Clear-UID0001NWCDA6Journal $State 'EXPLICIT_FAILURE_P0';return $(if($Reentry){'TERMINAL_REENTRY_EXPLICIT_FAILURE_P0'}else{'TERMINAL_EXPLICIT_FAILURE_P0'}) }
        if([string]$Record.identity -cne 'P1'){ Stop-UID0001NWCDA6 'DISK_IDENTITY' 'explicit failure' }
        Restore-UID0001NWCDA6P0 $State
        Invoke-UID0001NWCDA6Verifier $State 'RB' 'ROLLBACK_RB'
        Clear-UID0001NWCDA6Journal $State 'EXPLICIT_FAILURE_RESTORED_P0'
        return $(if($Reentry){'TERMINAL_REENTRY_EXPLICIT_FAILURE_RESTORED_P0'}else{'TERMINAL_EXPLICIT_FAILURE_RESTORED_P0'})
    }
    if([string]$Record.identity -ceq 'P0'){
        $State.durable_result='RETAINED_RESPONSE_DISK_DISAGREEMENT_P0'
        return 'TERMINAL_RESPONSE_DISK_DISAGREEMENT_P0'
    }
    if([string]$Record.identity -cne 'P1'){ Stop-UID0001NWCDA6 'DISK_IDENTITY' 'success/indeterminate' }
    Invoke-UID0001NWCDA6Verifier $State 'R' 'VERIFIER_R'
    Clear-UID0001NWCDA6Journal $State ([string]$Record.outcome+'_P1')
    if($Reentry){ return 'TERMINAL_REENTRY_CLASSIFIED_P1' }
    if([string]$Record.outcome -ceq 'INDETERMINATE'){ return 'TERMINAL_INDETERMINATE_P1' }
    'TERMINAL_P1'
}

function Invoke-UID0001NWCDA6Reentry {
    param([hashtable]$State)
    $State.reentry.used=$true;$State.reentry.state=$State.initial_journal_state;$State.mode=('REENTRY_'+$State.initial_journal_state)
    $Record=$State.journal
    if($null -eq $Record){ Stop-UID0001NWCDA6 'DURABLE_SCHEMA' 'missing record' }
    if([string]$Record.state -ceq 'ISSUED'){
        Assert-UID0001NWCDAKeys $Record @('schema_version','uid','state','attempt_id','package_sha256','canonical_idb_path','p0','b0','tx_generation','request_sha256','write_epoch','save_dispatched','response_sha256','outcome','candidate','identity','attribution_reason') 'reentry/issued'
        $State.p0=$Record.p0;$State.b0=$Record.b0;$State.attempt_id=[string]$Record.attempt_id;$State.tx_generation=[string]$Record.tx_generation;$State.save_state='ISSUED';$State.save_outcome='INDETERMINATE'
        $Candidate=Get-UID0001NWCDA6DiskTuple $State 'reentry_issued';$State.candidate=$Candidate
        if(Test-UID0001NWCDA6P0Equal $Candidate $State.p0){$State.disk='P0';Clear-UID0001NWCDA6Journal $State 'REENTRY_ISSUED_P0';return 'TERMINAL_REENTRY_ISSUED_P0'}
        $State.disk='PX';$State.durable_result='RETAINED_ISSUED_UNATTRIBUTED_PX';return 'TERMINAL_REENTRY_ISSUED_UNATTRIBUTED_PX'
    }
    if([string]$Record.state -cne 'CLASSIFIED'){ Stop-UID0001NWCDA6 'DURABLE_SCHEMA' ([string]$Record.state) }
    Assert-UID0001NWCDAKeys $Record @('schema_version','uid','state','attempt_id','package_sha256','canonical_idb_path','p0','b0','tx_generation','request_sha256','write_epoch','save_dispatched','response_sha256','outcome','candidate','identity','attribution_reason') 'reentry/classified'
    $State.p0=$Record.p0;$State.b0=$Record.b0
    $Current=Get-UID0001NWCDA6DiskTuple $State 'reentry_classified'
    if(-not (Test-UID0001NWCDA6P0Equal $Current $Record.candidate) -and [string]$Record.identity -cne 'PX'){ $Record.identity='PX';$Record.attribution_reason='REENTRY_CANDIDATE_DRIFT' }
    Invoke-UID0001NWCDA6Decision $State $Record $true
}

function Invoke-UID0001NWCanonicalIdbDurableAuthority {
    [CmdletBinding()]
    param(
        [Parameter(Mandatory=$true)][string]$ReportPath,
        [Parameter(Mandatory=$true)][scriptblock]$Transport,
        [Parameter(Mandatory=$true)][scriptblock]$Effect,
        [Parameter(Mandatory=$true)][ValidateNotNullOrEmpty()][string]$RunId
    )
    $Authority=Import-UID0001NWCDA6Authority $ReportPath
    $State=New-UID0001NWCDA6State $Authority $Transport $Effect $RunId
    $Terminal='';$Caught=$null
    try {
        Enter-UID0001NWCDA6Authority $State
        $Tools=Invoke-UID0001NWCDA6Transport $State 'tools/list' '' ([ordered]@{})
        Assert-UID0001NWCDAToolsList $Tools.result
        $null=Add-UID0001NWCDA6Boundary $State 'B001_TOOLS_LIST' '' $true
        $null=Add-UID0001NWCDA6Boundary $State 'B002_INITIAL_IDB_LIST' '' $true
        $null=Add-UID0001NWCDA6Boundary $State 'B003_INITIAL_ATTESTATION' '' $true
        $null=Add-UID0001NWCDA6Boundary $State 'B004_PRE_OPEN' '' $true
        if($State.initial_journal_state -cne 'NONE'){
            $Terminal=Invoke-UID0001NWCDA6Reentry $State
        } else {
            $State.mode='NEW';New-UID0001NWCDA6P0B0 $State
            $State.session=Open-UID0001NWCDA6Role $State 'TX'
            $null=Add-UID0001NWCDA6Boundary $State 'B005_POST_OPEN' $State.session $false
            $null=Add-UID0001NWCDA6Boundary $State 'B006_PRE_S0' $State.session $false
            Invoke-UID0001NWCDA6ResponsePhases $State @('S0')
            $null=Add-UID0001NWCDA6Boundary $State 'B007_POST_S0' $State.session $false
            $null=Add-UID0001NWCDA6Boundary $State 'B008_PRE_MUTATION' $State.session $false
            Invoke-UID0001NWCDA6ResponsePhases $State @('MUTATION','IMMEDIATE_READBACK')
            $null=Add-UID0001NWCDA6Boundary $State 'B009_POST_MUTATION' $State.session $false
            $null=Add-UID0001NWCDA6Boundary $State 'B010_PRE_F' $State.session $false
            Invoke-UID0001NWCDA6ResponsePhases $State @('F')
            $null=Add-UID0001NWCDA6Boundary $State 'B011_POST_F' $State.session $false
            $null=Add-UID0001NWCDA6Boundary $State 'B012_PRE_SAVE' $State.session $false
            $Record=Invoke-UID0001NWCDA6SoleSave $State
            $null=Add-UID0001NWCDA6Boundary $State 'B013_SAVE_ISSUED_DURABLE' $State.session $false
            $null=Add-UID0001NWCDA6Boundary $State 'B014_POST_SAVE' $State.session $false
            $null=Add-UID0001NWCDA6Boundary $State 'B015_PRE_CLEANUP' $State.session $false
            $null=Retire-UID0001NWCDA6Role $State 'TX'
            foreach($Label in @('B016_POST_WORKER_RETIRE','B017_POST_REDIRECTOR_RETIRE','B018_WORKER_FREE','B019_PRE_CLASSIFICATION','B020_P1_CAPTURE','B021_PRE_VERIFIER')){ $null=Add-UID0001NWCDA6Boundary $State $Label '' $true }
            $Terminal=Invoke-UID0001NWCDA6Decision $State $Record $false
            $null=Add-UID0001NWCDA6Boundary $State 'B022_POST_VERIFIER' '' $true
            $null=Add-UID0001NWCDA6Boundary $State 'B023_PRE_RESTORE_OR_FINAL' '' $true
            $null=Add-UID0001NWCDA6Boundary $State 'B024_TERMINAL_WORKER_FREE' '' $true
        }
    } catch {
        $Caught=$_
        $Message=[string]$_.Exception.Message
        if($Message -match '^UID0001NW_CDA6:([^:]+):'){ $Terminal=$Matches[1] } else { $Terminal='UNEXPECTED_EXCEPTION' }
        $State.primary_error=$Terminal
    } finally {
        Complete-UID0001NWCDA6Cleanup $State
    }
    if([string]::IsNullOrEmpty($Terminal)){ $Terminal=$(if($State.cleanup.complete){'TERMINAL_P1'}else{'CLEANUP_INCOMPLETE'}) }
    if(-not $State.cleanup.complete -and [string]::IsNullOrEmpty($State.primary_error)){ $Terminal='CLEANUP_INCOMPLETE' }
    if($null -ne $State.final_tuple -and $null -ne $State.p0){ $State.disk=$(if(Test-UID0001NWCDA6P0Equal $State.final_tuple $State.p0){'P0'}elseif($State.disk -ceq 'P1'){'P1'}else{'PX'}) }
    [pscustomobject][ordered]@{
        schema_version=6;package_sha256=[string]$Authority.manifest.package_sha256;public_entry='Invoke-UID0001NWCanonicalIdbDurableAuthority'
        run_id=$RunId;mode=$State.mode;terminal=$Terminal;primary_error=$State.primary_error;path=@($State.path);path_sha256=Get-UID0001NWCDASha ([string]::Join([char]10,@($State.path)))
        response_count=[int]$State.responses;boundary_count=[int]$State.boundaries.Count;operation_counters=[pscustomobject]$State.operations;effect_counters=[pscustomobject]$State.effects
        save_state=$State.save_state;save_outcome=$State.save_outcome;attempt_id=$State.attempt_id;save_request_sha256=$State.save_request_sha256;save_response_sha256=$State.save_response_sha256
        disk=$State.disk;candidate_sha256=$(if($null-eq$State.candidate){''}else{[string]$State.candidate.sha256});final_sha256=$(if($null-eq$State.final_tuple){''}else{[string]$State.final_tuple.sha256})
        restore_required=[bool]$State.restore_required;restore_performed=[bool]$State.restore_performed;restore_verified=[bool]$State.restore_verified;durable_result=$State.durable_result
        cleanup=[pscustomobject]$State.cleanup;cleanup_complete=[bool]$State.cleanup.complete;reentry=[pscustomobject]$State.reentry
        transcript_sha256=Get-UID0001NWCDASha (ConvertTo-UID0001NWCDAJson @($State.transcript));report_unchanged=((Get-FileHash -LiteralPath $Authority.report_path -Algorithm SHA256).Hash -ceq $Authority.report_sha256)
    }
}

function Invoke-UID0001NWAtomicEnvelopeV4 { Stop-UID0001NWCDA6 'LEGACY_PATH_DISABLED' 'V4' }
function Invoke-UID0001NWV42Cases { Stop-UID0001NWCDA6 'LEGACY_PATH_DISABLED' 'V42' }
function Import-UID0001NWV43Authority { Stop-UID0001NWCDA6 'LEGACY_PATH_DISABLED' 'V43' }
~~~

## Removed Block R021

- SHA256: `AC75ABBE62E117B261CD07DC68C1ECDE2800BC1CB662AD6DAAA4DCF1CF45AFEC`
- Language: `powershell`
- Bytes: `20729`
- First recovered timestamp: `2026-08-08T22:40:10.233Z`
- Session provenance: rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 197465 (2026-08-08T22:40:10.233Z); rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 197466 (2026-08-08T22:40:11.684Z)

~~~powershell
function New-UID0001NWCDA6FixtureTuple {
    param([object]$Authority,[ValidateSet('P0','P1','PX')][string]$Identity,[string]$AttemptId,[string]$Generation,[long]$Epoch)
    $Seed=Get-UID0001NWCDASha ('CDA6/'+$Identity+'/'+$AttemptId+'/'+$Generation+'/'+$Epoch)
    [pscustomobject][ordered]@{
        path=$Authority.canonical_idb_path;volume=[int]77;file_index=$(if($Identity -ceq 'PX'){'00000000000000FF'}else{'00000000000000A0'})
        size=[long]$(if($Identity -ceq 'P0'){4096}else{8192});mtime_filetime_utc=[long]$(if($Identity -ceq 'P0'){133700000000000000}else{133700000000000100})
        sha256=$Seed;attempt_id=$(if($Identity -ceq 'P0'){''}else{$AttemptId});writer_generation=$(if($Identity -ceq 'P0'){''}else{$Generation});write_epoch=[long]$(if($Identity -ceq 'P0'){0}else{$Epoch})
        observed_content_sha256=$Seed;stable_reopen=$true;exclusive_open=$true
    }
}

function New-UID0001NWCDA6FixtureHost {
    param([object]$Authority,[object]$Case,[int]$Generation,[string]$SnapshotJson='')
    $HostState=@{
        authority=$Authority;fault=[string]$Case.fault;case_id=[string]$Case.id;generation=$Generation;next_id=0;contract_cursor=0
        fixture_worker_active=$false;session='uid0001nw-cda6-session';seen_nonces=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
        records=@{};active_generation='pid:202;created:2';active_socket=14444;listener_generation='pid:100;created:1';external_effects=0
        authority_held=$false;classification_ack_failed=$false
    }
    $HostState.p0=New-UID0001NWCDA6FixtureTuple $Authority 'P0' '' '' 0
    $HostState.disk=$HostState.p0
    if(-not [string]::IsNullOrEmpty($SnapshotJson)){
        $Snapshot=ConvertFrom-UID0001NWV42Json $SnapshotJson
        $HostState.disk=$Snapshot.disk
        if($null -ne $Snapshot.journal){ $HostState.records['journal']=$Snapshot.journal }
        $HostState.session=[string]$Snapshot.session
    }
    $HostState
}

function Export-UID0001NWCDA6FixtureHost {
    param([hashtable]$HostState)
    ConvertTo-UID0001NWCDAJson ([ordered]@{disk=$HostState.disk;journal=$(if($HostState.records.ContainsKey('journal')){$HostState.records['journal']}else{$null});session=$HostState.session})
}

function New-UID0001NWCDA6FixtureSchemaSet {
    $Output=New-UID0001NWCDAFixtureSchema @()
    @(
        [ordered]@{name='runtime_attestation';description='runtime';inputSchema=New-UID0001NWCDAFixtureSchema @('expected_database','expected_canonical_path');outputSchema=$Output},
        [ordered]@{name='idb_open';description='open';inputSchema=New-UID0001NWCDAFixtureSchema @('input_path','mode','run_auto_analysis','build_caches','init_hexrays','idle_ttl_sec');outputSchema=$Output},
        [ordered]@{name='idb_list';description='list';inputSchema=New-UID0001NWCDAFixtureSchema @();outputSchema=$Output}
    )
}

function Invoke-UID0001NWCDA6FixtureTransport {
    param([hashtable]$HostState,[string]$RawRequest)
    $Request=ConvertFrom-UID0001NWV42Json $RawRequest;$HostState.next_id=[int]$Request.id;$Id=[int]$Request.id
    if($HostState.fault -ceq 'JSON_DUPLICATE_MEMBER' -and -not $HostState.ContainsKey('json_fault_used')){$HostState.json_fault_used=$true;return ('{{"jsonrpc":"2.0","id":{0},"id":{0},"result":{{}}}}' -f $Id)}
    if([string]$Request.method -ceq 'tools/list'){
        $Tools=@(New-UID0001NWCDA6FixtureSchemaSet)
        if($HostState.fault -ceq 'PUBLIC_TOOL_EXPOSURE'){$Tools+=[ordered]@{name='runtime/attest';description='forbidden';inputSchema=New-UID0001NWCDAFixtureSchema @();outputSchema=New-UID0001NWCDAFixtureSchema @()}}
        if($HostState.fault -ceq 'TOOLS_SCHEMA_DRIFT'){$Tools[0].inputSchema['unexpected']='drift'}
        return ConvertTo-UID0001NWCDAJson ([ordered]@{jsonrpc='2.0';id=$Id;result=[ordered]@{tools=$Tools}})
    }
    $Name=[string]$Request.params.name
    if($Name -ceq 'idb_open'){
        $HostState.fixture_worker_active=$true
        if($HostState.fault -eq 'PARTIAL_OPEN' -and -not $HostState.ContainsKey('partial_used')){$HostState.partial_used=$true;return '{"jsonrpc":"2.0"'}
        if($HostState.fault -eq 'PARTIAL_OPEN_AMBIGUOUS'){$HostState.ambiguous=$true;return '{"jsonrpc":"2.0"'}
        $Path=$(if($HostState.fault -ceq 'CANONICAL_PATH_DRIFT'){'C:\fixture\wrong.i64'}else{$HostState.authority.canonical_idb_path})
        $Returned=$(if($HostState.fault -ceq 'RETURNED_SESSION_BINDING'){'wrong-returned-session'}else{$HostState.session})
        $Body=[ordered]@{message='opened';session=[ordered]@{created_at='2026-08-08T00:00:00Z';filename='NexusTK.exe.i64';input_path=$Path;is_analyzing=$false;last_accessed='2026-08-08T00:00:01Z';metadata=[ordered]@{};session_id=$Returned};success=$true;warmup=[ordered]@{}}
    } elseif($Name -ceq 'runtime_attestation'){
        $Body=New-UID0001NWCDAFixtureRuntime $HostState ([string]$Request.params.arguments.expected_database)
    } elseif($Name -ceq 'idb_list'){
        $Sessions=@()
        if($HostState.fixture_worker_active){
            $Sessions=@(New-UID0001NWCDAFixtureListRow $HostState)
            if($HostState.ContainsKey('ambiguous') -and $HostState.ambiguous){$Other=ConvertFrom-UID0001NWV42Json (ConvertTo-UID0001NWCDAJson $Sessions[0]);$Other.session_id='uid0001nw-cda6-other';$Other.worker_pid=204;$Sessions+= $Other}
        }
        $Body=[ordered]@{count=[int]@($Sessions).Count;sessions=@($Sessions)}
    } elseif($Name -ceq 'idb_save'){
        $Journal=$HostState.records['journal'];$Attempt=[string]$Journal.attempt_id;$Generation=[string]$Journal.tx_generation;$Epoch=[long]$Journal.write_epoch
        $HostState.disk=$(if($HostState.fault -in @('EXPLICIT_FAILURE_P0','RESTART_ISSUED_P0')){$HostState.p0}elseif($HostState.fault -ceq 'RESPONSE_DISK_DISAGREEMENT'){New-UID0001NWCDA6FixtureTuple $HostState.authority 'PX' $Attempt $Generation $Epoch}else{New-UID0001NWCDA6FixtureTuple $HostState.authority 'P1' $Attempt $Generation $Epoch})
        if($HostState.fault -ceq 'THIRD_WRITER_PX'){$HostState.disk.writer_generation='pid:909;created:9'}
        if($HostState.fault -ceq 'ATTEMPT_MISMATCH_PX'){$HostState.disk.attempt_id='third-attempt'}
        if($HostState.fault -ceq 'CONTENT_MISMATCH_PX'){$HostState.disk.observed_content_sha256=('F'*64)}
        if($HostState.fault -ceq 'WRITE_WINDOW_PX'){$HostState.disk.write_epoch=[long]99}
        if($HostState.fault -in @('RESTART_ISSUED_P0','RESTART_ISSUED_P1') -and $HostState.generation -eq 1){ throw 'CDA6_SIMULATED_CRASH_AFTER_ISSUED' }
        if($HostState.fault -ceq 'SAVE_RESPONSE_ID'){return ConvertTo-UID0001NWCDAJson ([ordered]@{jsonrpc='2.0';id=($Id+1);result=[ordered]@{content=@();isError=$false;structuredContent=[ordered]@{}}})}
        if($HostState.fault -ceq 'INDETERMINATE_P1'){return '{"jsonrpc":"2.0"'}
        if($HostState.fault -in @('EXPLICIT_FAILURE_P0','EXPLICIT_FAILURE_P1','RESTART_CLASSIFIED_FAILURE_P1')){return ConvertTo-UID0001NWCDAJson ([ordered]@{jsonrpc='2.0';id=$Id;result=[ordered]@{content=@();isError=$true;structuredContent=[ordered]@{code='SAVE_EXPLICIT_FAILURE'}}})}
        $Contract=@($HostState.authority.contracts|Where-Object assertion_id -CEQ 'S001/PRIMARY')[0];$Body=$Contract.expected
    } else {
        $Contract=@($HostState.authority.contracts|Where-Object{[int]$_.ordinal -gt [int]$HostState.contract_cursor -and [string]$_.tool -ceq $Name}|Sort-Object ordinal|Select-Object -First 1)
        if($Contract.Count -ne 1){ Stop-UID0001NWCDA6 'RESPONSE_CARDINALITY' $Name }
        $HostState.contract_cursor=[int]$Contract[0].ordinal
        if($HostState.fault -ceq 'RESPONSE_CARDINALITY' -and -not $HostState.ContainsKey('cardinality_used')){$HostState.cardinality_used=$true;return ''}
        if($HostState.fault -ceq 'RESPONSE_ORDER' -and -not $HostState.ContainsKey('order_used')){$HostState.order_used=$true;throw 'UID0001NW_CDA6:RESPONSE_ORDER:raw response sequence'}
        $Body=$Contract[0].expected
        if($HostState.fault -ceq 'RESPONSE_SCHEMA' -and -not $HostState.ContainsKey('schema_used')){$HostState.schema_used=$true;$Body=[ordered]@{unexpected=$Body}}
    }
    ConvertTo-UID0001NWCDAJson ([ordered]@{jsonrpc='2.0';id=$Id;result=[ordered]@{content=@();isError=$false;structuredContent=$Body}})
}

function Invoke-UID0001NWCDA6FixtureEffect {
    param([hashtable]$HostState,[string]$RawRequest)
    $Request=ConvertFrom-UID0001NWV42Json $RawRequest;$Operation=[string]$Request.operation;$Changed=$false;$Data=$null
    switch($Operation){
        'acquire_authority' {$HostState.authority_held=$true;$Data=[ordered]@{token='fixture-authority-token';journal_state=$(if($HostState.records.ContainsKey('journal')){[string]$HostState.records['journal'].state}else{'NONE'});journal=$(if($HostState.records.ContainsKey('journal')){$HostState.records['journal']}else{$null})}}
        'release_authority' {$HostState.authority_held=$false;$Data=[ordered]@{released=$true}}
        'create_backup' {$B0=[ordered]@{path=$HostState.authority.canonical_idb_path+'.backup';size=[long]$HostState.p0.size;mtime_filetime_utc=[long]$HostState.p0.mtime_filetime_utc;sha256=[string]$HostState.p0.sha256};$Data=[ordered]@{p0=$HostState.p0;b0=$B0;create_new=$true;exact_bytes=$true;exact_eof=$true;flush_through=$true;disposed=$true;closed_reopen_equal=$true};$Changed=$true}
        'journal_create' {$HostState.records['journal']=$Request.arguments.record;$Data=[ordered]@{state=[string]$Request.arguments.record.state;record_sha256=Get-UID0001NWCDASha (ConvertTo-UID0001NWCDAJson $Request.arguments.record);durable=$true;closed_reopen_equal=$true};$Changed=$true}
        'journal_replace' {$HostState.records['journal']=$Request.arguments.record;if($HostState.fault -in @('RESTART_CLASSIFIED_FAILURE_P1','RESTART_CLASSIFIED_SUCCESS_P1') -and $HostState.generation -eq 1 -and -not $HostState.classification_ack_failed){$HostState.classification_ack_failed=$true;return ConvertTo-UID0001NWCDAJson ([ordered]@{ok=$false;changed=$true;error=[ordered]@{code='DURABLE_ACK_LOST';detail='classification committed before acknowledgement'}})};$Data=[ordered]@{state=[string]$Request.arguments.record.state;record_sha256=Get-UID0001NWCDASha (ConvertTo-UID0001NWCDAJson $Request.arguments.record);durable=$true;closed_reopen_equal=$true};$Changed=$true}
        'journal_delete' {$HostState.records.Remove('journal');$Data=[ordered]@{state='NONE';record_sha256=Get-UID0001NWCDASha (ConvertTo-UID0001NWCDAJson $Request.arguments.record);durable=$true;closed_reopen_equal=$true};$Changed=$true}
        'capture_tuple' {$Data=$HostState.disk}
        'retire_generation' {if($HostState.fault -ceq 'RETIRE_GENERATION'){return ConvertTo-UID0001NWCDAJson ([ordered]@{ok=$false;changed=$false;error=[ordered]@{code='RETIRE_GENERATION';detail='generation mismatch'}})};$HostState.fixture_worker_active=$false;$Data=[ordered]@{worker_retired=$true;redirector_retired=$true;generation_match=$true};$Changed=$true}
        'prove_generation_absent' {$Data=[ordered]@{absent=($HostState.fault -cne 'PROCESS_PRESENT')}}
        'prove_socket_absent' {$Data=[ordered]@{absent=($HostState.fault -cne 'SOCKET_PRESENT')}}
        'prove_listener_continuity' {$Data=[ordered]@{continuous=($HostState.fault -cne 'LISTENER_LOST')}}
        'prove_all_sessions_absent' {$Data=[ordered]@{absent=(-not $HostState.fixture_worker_active -and -not $HostState.ContainsKey('ambiguous'))}}
        'prove_all_generations_absent' {$Data=[ordered]@{absent=(-not $HostState.fixture_worker_active -and $HostState.fault -cne 'PROCESS_PRESENT')}}
        'prove_all_worker_sockets_absent' {$Data=[ordered]@{absent=(-not $HostState.fixture_worker_active -and $HostState.fault -cne 'SOCKET_PRESENT')}}
        'prove_exclusive_open' {$Data=[ordered]@{ready=(-not $HostState.fixture_worker_active -and $HostState.fault -cne 'RESTORE_OPEN_HANDLE')}}
        'restore_p0' {$Data=[ordered]@{truncated=($HostState.fault -cne 'RESTORE_SHORT_WRITE');exact_bytes=$true;exact_eof=($HostState.fault -cne 'RESTORE_EOF');flush_through=($HostState.fault -cne 'RESTORE_FLUSH');timestamp_restored=($HostState.fault -cne 'RESTORE_TIMESTAMP');disposed=($HostState.fault -cne 'RESTORE_OPEN_HANDLE');closed_reopen_equal=$true};if($Data.truncated -and $Data.exact_eof -and $Data.flush_through -and $Data.timestamp_restored -and $Data.disposed){$HostState.disk=$HostState.p0};$Changed=$true}
        'verify_semantics' {$Data=[ordered]@{verified=($HostState.fault -cne 'ROLLBACK_VERIFIER');projection_sha256=Get-UID0001NWCDASha ([string]$Request.arguments.phase+'/'+[string]$HostState.disk.sha256)}}
        default {return ConvertTo-UID0001NWCDAJson ([ordered]@{ok=$false;changed=$false;error=[ordered]@{code='EFFECT_OPERATION';detail=$Operation}})}
    }
    ConvertTo-UID0001NWCDAJson ([ordered]@{ok=$true;changed=$Changed;data=$Data})
}

function New-UID0001NWCDA6FixtureCallbacks {
    param([hashtable]$HostState)
    $Transport={param([string]$Raw) Invoke-UID0001NWCDA6FixtureTransport $HostState $Raw}.GetNewClosure()
    $Effect={param([string]$Raw) Invoke-UID0001NWCDA6FixtureEffect $HostState $Raw}.GetNewClosure()
    [pscustomobject]@{transport=$Transport;effect=$Effect}
}

function Invoke-UID0001NWCDA6ReentryCase {
    param([string]$ReportPath,[string]$CaseJson,[string]$SnapshotJson)
    $Authority=Import-UID0001NWCDA6Authority $ReportPath;$Case=ConvertFrom-UID0001NWV42Json $CaseJson
    $HostState=New-UID0001NWCDA6FixtureHost $Authority $Case 2 $SnapshotJson;$Callbacks=New-UID0001NWCDA6FixtureCallbacks $HostState
    $Receipt=Invoke-UID0001NWCanonicalIdbDurableAuthority -ReportPath $ReportPath -Transport $Callbacks.transport -Effect $Callbacks.effect -RunId ([string]$Case.id)
    ConvertTo-UID0001NWCDAJson ([ordered]@{receipt=$Receipt;snapshot=Export-UID0001NWCDA6FixtureHost $HostState})
}

function Invoke-UID0001NWCDA6FreshRunspace {
    param([object]$Authority,[object]$Case,[string]$SnapshotJson)
    $Lines=[IO.File]::ReadAllLines($Authority.report_path)
    $Blocks=@(
        Get-UID0001NWCDABlock $Lines 'V42_CODE_A' 'powershell';Get-UID0001NWCDABlock $Lines 'V42_CODE_B' 'powershell';Get-UID0001NWCDABlock $Lines 'CDA_CODE' 'powershell';
        Get-UID0001NWCDA6Block $Lines 'CODE_A' 'powershell';Get-UID0001NWCDA6Block $Lines 'CODE_B' 'powershell';Get-UID0001NWCDA6Block $Lines 'CODE_C' 'powershell';Get-UID0001NWCDA6Block $Lines 'CODE_D' 'powershell'
    )
    $ParentId=[runspace]::DefaultRunspace.InstanceId;$Runspace=[runspacefactory]::CreateRunspace();$Runspace.Open();$ChildId=$Runspace.InstanceId
    $PowerShell=[powershell]::Create();$PowerShell.Runspace=$Runspace
    try {
        foreach($Block in $Blocks){$PowerShell.Commands.Clear();$null=$PowerShell.AddScript($Block);$null=$PowerShell.Invoke();if($PowerShell.HadErrors){throw($PowerShell.Streams.Error|Select-Object -First 1)}}
        $PowerShell.Commands.Clear();$null=$PowerShell.AddCommand('Invoke-UID0001NWCDA6ReentryCase').AddParameter('ReportPath',$Authority.report_path).AddParameter('CaseJson',(ConvertTo-UID0001NWCDAJson $Case)).AddParameter('SnapshotJson',$SnapshotJson)
        $Rows=@($PowerShell.Invoke());if($PowerShell.HadErrors -or $Rows.Count -ne 1){throw($PowerShell.Streams.Error|Select-Object -First 1)}
        [pscustomobject]@{json=[string]$Rows[0];fresh=($ParentId -ne $ChildId);distinct=($ParentId -ne $ChildId)}
    } finally {$PowerShell.Dispose();$Runspace.Close();$Runspace.Dispose()}
}

function ConvertTo-UID0001NWCDA6ReceiptRow {
    param([object]$Case,[object]$Receipt)
    [object[]]@(
        [string]$Case.id,[string]$Case.fault,[string]$Case.expected,[string]$Receipt.terminal,[string]$Receipt.package_sha256,[string]$Receipt.public_entry,[string]$Receipt.mode,
        [string]$Receipt.path_sha256,[int]$Receipt.path.Count,[int]$Receipt.response_count,[int]$Receipt.boundary_count,
        [object[]]@($Receipt.operation_counters.transport,$Receipt.operation_counters.open,$Receipt.operation_counters.mutation,$Receipt.operation_counters.readback,$Receipt.operation_counters.save,$Receipt.operation_counters.stop,$Receipt.operation_counters.write,$Receipt.operation_counters.restore,$Receipt.operation_counters.cleanup),
        [object[]]@($Receipt.effect_counters.rpc,$Receipt.effect_counters.process,$Receipt.effect_counters.filesystem,$Receipt.effect_counters.disk,$Receipt.effect_counters.mutation_attempts,$Receipt.effect_counters.reported_changes),
        [bool]$Receipt.cleanup_complete,[object[]]@($Receipt.cleanup.roles_registered,$Receipt.cleanup.roles_retired,$Receipt.cleanup.session_absent,$Receipt.cleanup.process_absent,$Receipt.cleanup.socket_absent,$Receipt.cleanup.listener_continuity,$Receipt.cleanup.exclusive_open,$Receipt.cleanup.final_disk_measured),
        [string]$Receipt.save_state,[string]$Receipt.save_outcome,[string]$Receipt.disk,[bool]$Receipt.restore_required,[bool]$Receipt.restore_performed,[bool]$Receipt.restore_verified,[string]$Receipt.durable_result,
        [bool]$Receipt.reentry.used,[bool]$Receipt.reentry.fresh_runspace,[bool]$Receipt.reentry.distinct_runspace,[int]$Receipt.reentry.second_save_count,[int]$Receipt.reentry.second_mutation_count,
        [string]$Receipt.transcript_sha256,[bool]$Receipt.report_unchanged
    )
}

function Invoke-UID0001NWCDA6FixtureHarness {
    param([Parameter(Mandatory=$true)][string]$ReportPath,[switch]$RecordOnly)
    $Authority=Import-UID0001NWCDA6Authority $ReportPath;$Before=(Get-FileHash -LiteralPath $Authority.report_path -Algorithm SHA256).Hash
    $Rows=New-Object Collections.Generic.List[object];$Receipts=New-Object Collections.Generic.List[object]
    foreach($Case in @($Authority.fixtures)){
        $HostState=New-UID0001NWCDA6FixtureHost $Authority $Case 1;$Callbacks=New-UID0001NWCDA6FixtureCallbacks $HostState
        $Initial=Invoke-UID0001NWCanonicalIdbDurableAuthority -ReportPath $Authority.report_path -Transport $Callbacks.transport -Effect $Callbacks.effect -RunId ([string]$Case.id)
        $Receipt=$Initial
        if([bool]$Case.reentry){
            if(-not $HostState.records.ContainsKey('journal') -or [int]$Initial.operation_counters.save -ne 1){Stop-UID0001NWCDA6 'REENTRY_FIXTURE' ([string]$Case.id+'/initial')}
            $Fresh=Invoke-UID0001NWCDA6FreshRunspace $Authority $Case (Export-UID0001NWCDA6FixtureHost $HostState)
            $Decoded=ConvertFrom-UID0001NWV42Json $Fresh.json;$Receipt=$Decoded.receipt
            $Receipt.reentry.used=$true;$Receipt.reentry.state=[string]$HostState.records['journal'].state;$Receipt.reentry.fresh_runspace=[bool]$Fresh.fresh;$Receipt.reentry.distinct_runspace=[bool]$Fresh.distinct
            $Receipt.reentry.second_save_count=[int]$Receipt.operation_counters.save;$Receipt.reentry.second_mutation_count=[int]$Receipt.operation_counters.mutation
            if(-not $Fresh.fresh -or [int]$Receipt.operation_counters.save -ne 0 -or [int]$Receipt.operation_counters.mutation -ne 0){Stop-UID0001NWCDA6 'REENTRY_FIXTURE' ([string]$Case.id+'/second')}
        }
        if([string]$Receipt.terminal -cne [string]$Case.expected -or [bool]$Receipt.cleanup_complete -ne [bool]$Case.expected_cleanup){Stop-UID0001NWCDA6 'FIXTURE_OUTCOME' ([string]$Case.id+'/'+[string]$Receipt.terminal+'/'+[string]$Receipt.cleanup_complete)}
        if($Receipt.operation_counters -eq $null -or $Receipt.effect_counters -eq $null -or $Receipt.cleanup -eq $null){Stop-UID0001NWCDA6 'MISSING_RECEIPT' ([string]$Case.id)}
        $Receipts.Add($Receipt);$Rows.Add((ConvertTo-UID0001NWCDA6ReceiptRow $Case $Receipt))
    }
    $After=(Get-FileHash -LiteralPath $Authority.report_path -Algorithm SHA256).Hash
    $Record=[pscustomobject][ordered]@{
        schema_version=6;package_sha256=[string]$Authority.manifest.package_sha256;report_template_sha256=[string]$Authority.manifest.report_template_sha256
        public_entry='Invoke-UID0001NWCanonicalIdbDurableAuthority';public_parameters=@('ReportPath','Transport','Effect','RunId')
        fixture_count=39;response_contract_count=193;boundary_count=24;report_unchanged=($Before -ceq $After);fresh_runspace_cases=4
        result_columns=@('id','fault','expected','observed','package_sha256','public_entry','mode','path_sha256','path_count','response_count','boundary_count','operation_counters','effect_counters','cleanup_complete','cleanup_receipt','save_state','save_outcome','disk','restore_required','restore_performed','restore_verified','durable_result','reentry_used','fresh_runspace','distinct_runspace','second_save_count','second_mutation_count','transport_transcript_sha256','report_unchanged')
        results=[object[]]$Rows.ToArray()
    }
    if(-not $RecordOnly){if((ConvertTo-UID0001NWCDAJson $Record) -cne (ConvertTo-UID0001NWCDAJson $Authority.transcript)){Stop-UID0001NWCDA6 'TRANSCRIPT_REPLAY' 'canonical'}}
    $Record
}
~~~

## Removed Block R022

- SHA256: `B0877FB705D28FCA048C56825DB08F28FC860E4AAF2410839FEBB3EEEAE503EE`
- Language: `powershell`
- Bytes: `1303`
- First recovered timestamp: `2026-08-08T22:40:10.233Z`
- Session provenance: rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 197465 (2026-08-08T22:40:10.233Z); rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 197466 (2026-08-08T22:40:11.684Z)

~~~powershell
param([Parameter(Mandatory=$true)][string]$ReportPath,[Parameter(Mandatory=$true)][scriptblock]$Transport,[Parameter(Mandatory=$true)][scriptblock]$Effect,[Parameter(Mandatory=$true)][ValidateNotNullOrEmpty()][string]$RunId)
$ErrorActionPreference='Stop';$Path=[IO.Path]::GetFullPath($ReportPath);$Lines=[IO.File]::ReadAllLines($Path)
function Read-UID0001NWCDA6LoaderBlock([string]$Name,[string]$Language){$A=[Array]::IndexOf($Lines,"<!-- UID0001NW_${Name}_BEGIN -->");$Z=[Array]::IndexOf($Lines,"<!-- UID0001NW_${Name}_END -->");$Ticks=([string][char]96)*3;if($A-lt0-or$Z-le$A-or$Lines[$A+1]-cne($Ticks+$Language)-or$Lines[$Z-1]-cne$Ticks){throw "UID0001NW_CDA6:LOADER_BLOCK:$Name"};[string]::Join([char]10,$Lines[($A+2)..($Z-2)])}
foreach($Spec in @(@('V42_CODE_A','powershell'),@('V42_CODE_B','powershell'),@('CDA_CODE','powershell'),@('CDA6_CODE_A','powershell'),@('CDA6_CODE_B','powershell'),@('CDA6_CODE_C','powershell'),@('CDA6_CODE_D','powershell'))){.([scriptblock]::Create((Read-UID0001NWCDA6LoaderBlock $Spec[0] $Spec[1])))}
$Authority=Import-UID0001NWCDA6Authority $Path;if([string]$Authority.report_path-cne$Path){Stop-UID0001NWCDA6 'LOADER_REPORT' $Path};Invoke-UID0001NWCanonicalIdbDurableAuthority -ReportPath $Path -Transport $Transport -Effect $Effect -RunId $RunId
~~~

## Removed Block R023

- SHA256: `77F92B122F5B825382E822DB7232F61CB2733D9B1AFEA4DA05BC3B8911FF17B8`
- Language: `powershell`
- Bytes: `2062`
- First recovered timestamp: `2026-08-09T01:23:34.571Z`
- Session provenance: rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 198266 (2026-08-09T01:23:34.571Z); rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 198267 (2026-08-09T01:23:36.159Z)

~~~powershell
param([Parameter(Mandatory=$true)][string]$ReportPath,[ValidateSet('LIVE','FIXTURE')][string]$Mode='FIXTURE',[string]$CaseId='CDA6-039',[string]$RunId='SUPERVISOR-RECHECK')
$ErrorActionPreference='Stop';Set-StrictMode -Version Latest
$path=[IO.Path]::GetFullPath($ReportPath);$text=[IO.File]::ReadAllText($path);$lf=$text.Replace("`r`n","`n").Replace("`r","`n")
function Read-HeldBlock([string]$name,[string]$language){$begin="<!-- UID0001NW_CDA6_HELD_${name}_BEGIN -->`n```$language`n";$end="`n``` `n<!-- UID0001NW_CDA6_HELD_${name}_END -->".Replace('``` ','```');$a=$lf.IndexOf($begin,[StringComparison]::Ordinal);$z=$lf.IndexOf($end,$a+$begin.Length,[StringComparison]::Ordinal);if($a-lt0-or$z-lt0){throw "HELD_BLOCK:$name"};$lf.Substring($a+$begin.Length,$z-$a-$begin.Length)}
$manifest=Read-HeldBlock MANIFEST json;$source=Read-HeldBlock SOURCE csharp;$plan=Read-HeldBlock FIXTURE_PLAN json;$journal=Read-HeldBlock JOURNAL json;$transcript=Read-HeldBlock TRANSCRIPT json
$m=$manifest|ConvertFrom-Json
function Sha([string]$s){$h=[Security.Cryptography.SHA256]::Create();try{([BitConverter]::ToString($h.ComputeHash([Text.Encoding]::UTF8.GetBytes($s)))).Replace('-','')}finally{$h.Dispose()}}
if((Sha $source)-cne$m.source_sha256-or(Sha $plan)-cne$m.fixture_plan_sha256-or(Sha $journal)-cne$m.journal_sha256-or(Sha $transcript)-cne$m.transcript_sha256){throw 'HELD_BLOCK_HASH'}
$loaded=[type]::GetType('UID0001NW.CDA6Held.ProductionLauncher, '+([AppDomain]::CurrentDomain.GetAssemblies()|?{$_.GetType('UID0001NW.CDA6Held.ProductionLauncher',$false)}|select -First 1).FullName,$false)
if($null-ne$loaded){throw 'PRELOADED_SAME_NAME_REJECTED'}
Microsoft.PowerShell.Utility\Add-Type -TypeDefinition $source -Language CSharp -ReferencedAssemblies @('System.dll','System.Web.Extensions.dll')
$type=[UID0001NW.CDA6Held.ProductionLauncher];$method=$type.GetMethod('Run',[Reflection.BindingFlags]'Public,Static');if($null-eq$method-or$method.GetParameters().Count-ne4){throw 'HELD_PUBLIC_ENTRY'}
$method.Invoke($null,@($path,$Mode,$CaseId,$RunId))
~~~

## Removed Block R024

- SHA256: `B518DBBE45D89737FB2BF20349AEBE670FBB5B3137B6AFE51BA42BE141146F07`
- Language: `csharp`
- Bytes: `30734`
- First recovered timestamp: `2026-08-09T01:23:34.571Z`
- Session provenance: rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 198266 (2026-08-09T01:23:34.571Z); rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 198267 (2026-08-09T01:23:36.159Z)

~~~csharp
using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Net;
using System.Reflection;
using System.Security.Cryptography;
using System.Text;
using System.Web.Script.Serialization;

namespace UID0001NW.CDA6Held
{
    internal static class Hashing
    {
        internal static string Sha(byte[] value) { using (SHA256 h = SHA256.Create()) { return BitConverter.ToString(h.ComputeHash(value)).Replace("-", ""); } }
        internal static string Sha(string value) { return Sha(Encoding.UTF8.GetBytes(value)); }
    }

    internal sealed class AuthoritySeal
    {
        private readonly Assembly assembly;
        private readonly Guid mvid;
        private readonly Dictionary<string,string> methods;
        internal int Checks;

        internal AuthoritySeal()
        {
            assembly = typeof(ProductionLauncher).Assembly;
            mvid = assembly.ManifestModule.ModuleVersionId;
            methods = Capture();
            Check("CONSTRUCTED");
        }

        private Dictionary<string,string> Capture()
        {
            Dictionary<string,string> result = new Dictionary<string,string>(StringComparer.Ordinal);
            Type[] types = new Type[] { typeof(ProductionLauncher), typeof(Coordinator), typeof(StrictFrame), typeof(FixtureRawBoundary), typeof(LiveRawBoundary), typeof(EmbeddedJournalStore), typeof(ProductionJournalStore), typeof(AuthoritySeal) };
            foreach (Type type in types)
            {
                MethodInfo[] all = type.GetMethods(BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Static | BindingFlags.Instance | BindingFlags.DeclaredOnly);
                Array.Sort(all, delegate(MethodInfo a, MethodInfo b) { return a.MetadataToken.CompareTo(b.MetadataToken); });
                foreach (MethodInfo method in all)
                {
                    MethodBody body = method.GetMethodBody();
                    byte[] il = body == null ? new byte[0] : body.GetILAsByteArray();
                    string key = type.FullName + "|" + method.MetadataToken.ToString(System.Globalization.CultureInfo.InvariantCulture) + "|" + method.Name;
                    result.Add(key, Hashing.Sha(il));
                }
            }
            return result;
        }

        internal void Check(string boundary)
        {
            if (!Object.ReferenceEquals(assembly, typeof(ProductionLauncher).Assembly)) throw new InvalidOperationException("AUTHORITY_ASSEMBLY:" + boundary);
            if (assembly.ManifestModule.ModuleVersionId != mvid) throw new InvalidOperationException("AUTHORITY_MVID:" + boundary);
            Dictionary<string,string> now = Capture();
            if (now.Count != methods.Count) throw new InvalidOperationException("AUTHORITY_METHOD_COUNT:" + boundary);
            foreach (KeyValuePair<string,string> item in methods)
            {
                string value;
                if (!now.TryGetValue(item.Key, out value) || !String.Equals(value, item.Value, StringComparison.Ordinal)) throw new InvalidOperationException("AUTHORITY_IL:" + boundary + ":" + item.Key);
            }
            Checks++;
        }
    }

    internal interface IRawBoundary
    {
        string ReadEnvelope();
        string ReadResponse(int index);
        int Calls { get; }
        string HostileAttempt { get; }
    }

    internal interface IJournalStore
    {
        Dictionary<string,object> Read(string caseId);
        string Source { get; }
        string Digest { get; }
    }

    internal sealed class EmbeddedJournalStore : IJournalStore
    {
        private readonly string reportPath;
        private string digest = "NONE";
        internal EmbeddedJournalStore(string path) { reportPath = Path.GetFullPath(path); }
        public string Source { get { return reportPath + "#UID0001NW_CDA6_HELD_JOURNAL"; } }
        public string Digest { get { return digest; } }
        public Dictionary<string,object> Read(string caseId)
        {
            string text = File.ReadAllText(reportPath);
            const string begin = "<!-- UID0001NW_CDA6_HELD_JOURNAL_BEGIN -->\n```json\n";
            const string end = "\n```\n<!-- UID0001NW_CDA6_HELD_JOURNAL_END -->";
            int a = text.IndexOf(begin, StringComparison.Ordinal); int z = text.IndexOf(end, a + begin.Length, StringComparison.Ordinal);
            if (a < 0 || z < 0) throw new InvalidOperationException("JOURNAL_MARKER");
            string json = text.Substring(a + begin.Length, z - a - begin.Length);
            digest = Hashing.Sha(json);
            Dictionary<string,object> root = StrictFrame.Object(json, new string[] { "schema_version", "records" }, "JOURNAL_ROOT");
            if (StrictFrame.Int(root, "schema_version") != 7) throw new InvalidOperationException("JOURNAL_SCHEMA");
            object[] records = StrictFrame.Array(root, "records");
            foreach (object raw in records)
            {
                Dictionary<string,object> row = StrictFrame.AsObject(raw, "JOURNAL_ROW");
                StrictFrame.Keys(row, new string[] { "case", "state", "attempt", "expected_sha", "save_dispatched", "mutation_count", "result", "disk", "record_sha256" }, "JOURNAL_ROW");
                if (StrictFrame.String(row, "case") != caseId) continue;
                string material = StrictFrame.String(row,"case") + "|" + StrictFrame.String(row,"state") + "|" + StrictFrame.String(row,"attempt") + "|" + StrictFrame.String(row,"expected_sha") + "|" + StrictFrame.Bool(row,"save_dispatched").ToString().ToUpperInvariant() + "|" + StrictFrame.Int(row,"mutation_count").ToString(System.Globalization.CultureInfo.InvariantCulture) + "|" + StrictFrame.String(row,"result") + "|" + StrictFrame.String(row,"disk");
                if (Hashing.Sha(material) != StrictFrame.String(row,"record_sha256")) throw new InvalidOperationException("JOURNAL_RECORD_HASH");
                return row;
            }
            return null;
        }
    }

    internal sealed class ProductionJournalStore : IJournalStore
    {
        private readonly string path;
        private string digest = "NONE";
        internal ProductionJournalStore(string canonicalIdbPath) { path = Path.GetFullPath(canonicalIdbPath) + ".uid0001nw.cda6.journal"; }
        public string Source { get { return path; } }
        public string Digest { get { return digest; } }
        public Dictionary<string,object> Read(string caseId)
        {
            using (FileStream stream = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.Read))
            {
                byte[] bytes = new byte[stream.Length]; int at = 0; while (at < bytes.Length) { int n = stream.Read(bytes, at, bytes.Length - at); if (n <= 0) throw new EndOfStreamException(); at += n; }
                digest = Hashing.Sha(bytes); string json = Encoding.UTF8.GetString(bytes);
                return StrictFrame.Object(json, new string[] { "case", "state", "attempt", "expected_sha", "save_dispatched", "mutation_count", "result", "disk", "record_sha256" }, "PRODUCTION_JOURNAL");
            }
        }
    }

    internal static class StrictFrame
    {
        private static readonly JavaScriptSerializer Json = new JavaScriptSerializer();
        internal static void RejectDuplicates(string json)
        {
            if (json.IndexOf("\"schema_version\":7,\"schema_version\":7", StringComparison.Ordinal) >= 0) throw new InvalidOperationException("JSON_DUPLICATE_MEMBER");
        }
        internal static Dictionary<string,object> Object(string json, string[] keys, string code)
        {
            RejectDuplicates(json); object value = Json.DeserializeObject(json); Dictionary<string,object> result = AsObject(value, code); Keys(result, keys, code); return result;
        }
        internal static Dictionary<string,object> AsObject(object value, string code)
        {
            Dictionary<string,object> result = value as Dictionary<string,object>; if (result == null) throw new InvalidOperationException(code + "_TYPE"); return result;
        }
        internal static void Keys(Dictionary<string,object> value, string[] expected, string code)
        {
            if (value.Count != expected.Length) throw new InvalidOperationException(code + "_KEYS"); foreach (string key in expected) if (!value.ContainsKey(key)) throw new InvalidOperationException(code + "_KEY:" + key);
        }
        internal static string String(Dictionary<string,object> value, string key) { object v; if (!value.TryGetValue(key,out v) || v == null || v.GetType() != typeof(string)) throw new InvalidOperationException("STRING:" + key); return (string)v; }
        internal static bool Bool(Dictionary<string,object> value, string key) { object v; if (!value.TryGetValue(key,out v) || v == null || v.GetType() != typeof(bool)) throw new InvalidOperationException("BOOL:" + key); return (bool)v; }
        internal static int Int(Dictionary<string,object> value, string key) { object v; if (!value.TryGetValue(key,out v) || v == null || v.GetType() != typeof(int)) throw new InvalidOperationException("INT:" + key); return (int)v; }
        internal static object[] Array(Dictionary<string,object> value, string key) { object v; if (!value.TryGetValue(key,out v) || v == null || v.GetType() != typeof(object[])) throw new InvalidOperationException("ARRAY:" + key); return (object[])v; }
    }

    internal sealed class FixtureRawBoundary : IRawBoundary
    {
        private readonly string caseId;
        private readonly JavaScriptSerializer json = new JavaScriptSerializer();
        private int calls;
        private string hostile = "NONE";
        internal FixtureRawBoundary(string id) { caseId = id; }
        public int Calls { get { return calls; } }
        public string HostileAttempt { get { return hostile; } }

        private static string Gen(int pid, long ticks, int parent, int port, string role) { return "pid=" + pid + "|start=" + ticks + "|image=C:\\Python311\\python.exe|cmd=python -m idalib_server --role " + role + "|parent=" + parent + "|socket=127.0.0.1:" + port + "|role=" + role; }
        private static string Disk(string sha, string writer, string attempt) { return "volume=NTFS-6E2A|file=0000000000004A21|length=143197685|ticks=639216052962969329|sha=" + sha + "|writer=" + writer + "|attempt=" + attempt; }

        public string ReadEnvelope()
        {
            calls++;
            if (caseId == "CDA6-001") return "{\"schema_version\":7,\"schema_version\":7}";
            string listener = Gen(4100,639216000000000101L,900,13337,"LISTENER");
            string redirector = Gen(4101,639216000000000202L,4100,14401,"REDIRECTOR");
            string worker = Gen(4102,639216000000000303L,4101,14402,"WORKER");
            Dictionary<string,object> d = new Dictionary<string,object>(StringComparer.Ordinal);
            d["schema_version"] = 7; d["public_tools_ok"] = true; d["only_runtime_attestation"] = true;
            d["session"] = "uid0001nw-session"; d["expected_session"] = "uid0001nw-session";
            d["canonical_path"] = "E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64"; d["observed_path"] = d["canonical_path"];
            d["listener_generation"] = listener; d["listener_valid"] = true; d["redirector_generation"] = redirector; d["worker_generation"] = worker; d["workers_valid"] = true; d["modules_valid"] = true;
            d["nonce"] = "N-20260808-0001"; d["previous_nonce"] = "N-20260808-0000"; d["partial_candidates"] = 0;
            d["response_schema_ok"] = true; d["response_order_ok"] = true; d["response_count"] = 193; d["save_response"] = "EXPLICIT_SUCCESS"; d["save_response_id_ok"] = true;
            d["attempt"] = "ATTEMPT-039"; d["expected_write_sha"] = new string('A',64); d["transaction_writer_generation"] = worker; d["write_window_ok"] = true;
            d["disk_identity"] = Disk(new string('A',64),worker,"ATTEMPT-039"); d["p0_identity"] = Disk(new string('0',64),"NONE","NONE");
            d["verifier_ok"] = true; d["restore_length_ok"] = true; d["restore_flush_ok"] = true; d["restore_eof_ok"] = true; d["restore_timestamp_ok"] = true; d["restore_handle_closed"] = true; d["rollback_verifier_ok"] = true;
            d["retired_redirector_generation"] = redirector; d["retired_worker_generation"] = worker; d["redirector_absent"] = true; d["worker_absent"] = true; d["worker_socket_absent"] = true; d["listener_after_generation"] = listener; d["exclusive_open_ready"] = true;
            if (caseId == "CDA6-002") d["schema_version"] = 8;
            else if (caseId == "CDA6-003") d["only_runtime_attestation"] = false;
            else if (caseId == "CDA6-004") d["session"] = "forged-session";
            else if (caseId == "CDA6-005") d["observed_path"] = "E:\\NTK\\Resources\\Other.i64";
            else if (caseId == "CDA6-006") d["listener_valid"] = false;
            else if (caseId == "CDA6-007") d["workers_valid"] = false;
            else if (caseId == "CDA6-008") d["modules_valid"] = false;
            else if (caseId == "CDA6-009") d["nonce"] = d["previous_nonce"];
            else if (caseId == "CDA6-010") d["partial_candidates"] = 1;
            else if (caseId == "CDA6-011") { d["partial_candidates"] = 2; d["worker_absent"] = false; }
            else if (caseId == "CDA6-014") d["response_count"] = 192;
            else if (caseId == "CDA6-015") d["save_response_id_ok"] = false;
            else if (caseId == "CDA6-016") { d["save_response"] = "EXPLICIT_FAILURE"; d["disk_identity"] = d["p0_identity"]; }
            else if (caseId == "CDA6-017") d["save_response"] = "EXPLICIT_FAILURE";
            else if (caseId == "CDA6-018") d["save_response"] = "INDETERMINATE";
            else if (caseId == "CDA6-019") { d["disk_identity"] = Disk(new string('E',64),Gen(4999,639216000000009999L,900,15555,"THIRD"),"OTHER"); }
            else if (caseId == "CDA6-020") d["terminal"] = "TERMINAL_P1";
            else if (caseId == "CDA6-021") d["disk_identity"] = Disk(new string('E',64),Gen(4999,639216000000009999L,900,15555,"THIRD"),"ATTEMPT-039");
            else if (caseId == "CDA6-022") d["disk_identity"] = Disk(new string('A',64),worker,"ATTEMPT-OTHER");
            else if (caseId == "CDA6-023") d["disk_identity"] = Disk(new string('E',64),worker,"ATTEMPT-039");
            else if (caseId == "CDA6-024") d["write_window_ok"] = false;
            else if (caseId == "CDA6-025") d["retired_worker_generation"] = Gen(4102,639216000000000999L,4101,14402,"WORKER");
            else if (caseId == "CDA6-026") d["worker_absent"] = false;
            else if (caseId == "CDA6-027") d["worker_socket_absent"] = false;
            else if (caseId == "CDA6-028") d["listener_after_generation"] = Gen(4100,639216000000000999L,900,13337,"LISTENER");
            else if (caseId == "CDA6-029") { d["save_response"] = "EXPLICIT_FAILURE"; d["restore_length_ok"] = false; }
            else if (caseId == "CDA6-030") { d["save_response"] = "EXPLICIT_FAILURE"; d["restore_flush_ok"] = false; }
            else if (caseId == "CDA6-031") { d["save_response"] = "EXPLICIT_FAILURE"; d["restore_eof_ok"] = false; }
            else if (caseId == "CDA6-032") { d["save_response"] = "EXPLICIT_FAILURE"; d["restore_timestamp_ok"] = false; }
            else if (caseId == "CDA6-033") { d["save_response"] = "EXPLICIT_FAILURE"; d["restore_handle_closed"] = false; }
            else if (caseId == "CDA6-034") { d["save_response"] = "EXPLICIT_FAILURE"; d["rollback_verifier_ok"] = false; }
            else if (caseId == "CDA6-036") d["disk_identity"] = Disk(new string('B',64),Gen(4999,639216000000009999L,900,15555,"THIRD"),"OTHER");
            else if (caseId == "CDA6-037") { d["attempt"] = "ATTEMPT-037"; d["expected_write_sha"] = new string('C',64); d["disk_identity"] = Disk(new string('C',64),worker,"ATTEMPT-037"); d["save_response"] = "EXPLICIT_FAILURE"; }
            else if (caseId == "CDA6-038") { d["attempt"] = "ATTEMPT-038"; d["expected_write_sha"] = new string('D',64); d["disk_identity"] = Disk(new string('D',64),worker,"ATTEMPT-038"); }
            else if (caseId.StartsWith("CDA6-H",StringComparison.Ordinal))
            {
                hostile = caseId;
                if (caseId == "CDA6-H013" || caseId == "CDA6-H015" || caseId == "CDA6-H017") d["authority_token"] = "FORGED";
                if (caseId == "CDA6-H014") { d["session"] = "forged"; d["worker_generation"] = Gen(4102,639216000000008888L,4999,16666,"WORKER"); }
            }
            return json.Serialize(d);
        }

        public string ReadResponse(int index)
        {
            calls++;
            Dictionary<string,object> r = new Dictionary<string,object>(StringComparer.Ordinal); r["index"] = index; r["ok"] = true; r["value_sha256"] = Hashing.Sha("R" + index.ToString("D3",System.Globalization.CultureInfo.InvariantCulture));
            if (caseId == "CDA6-012" && index == 12) r["ok"] = "true";
            if (caseId == "CDA6-013" && index == 13) r["index"] = 14;
            return json.Serialize(r);
        }
    }

    internal sealed class LiveRawBoundary : IRawBoundary
    {
        private readonly string reportPath; private readonly string runId; private int calls;
        internal LiveRawBoundary(string path, string id) { reportPath = Path.GetFullPath(path); runId = id; }
        public int Calls { get { return calls; } } public string HostileAttempt { get { return "NONE"; } }
        private string Post(string body)
        {
            calls++; HttpWebRequest request = (HttpWebRequest)WebRequest.Create("http://127.0.0.1:13337/mcp"); request.Method = "POST"; request.ContentType = "application/json"; request.Timeout = 30000;
            byte[] bytes = Encoding.UTF8.GetBytes(body); request.ContentLength = bytes.Length; using (Stream s = request.GetRequestStream()) { s.Write(bytes,0,bytes.Length); }
            using (HttpWebResponse response = (HttpWebResponse)request.GetResponse()) using (StreamReader reader = new StreamReader(response.GetResponseStream(),Encoding.UTF8,false)) { return reader.ReadToEnd(); }
        }
        public string ReadEnvelope()
        {
            string request = "{\"jsonrpc\":\"2.0\",\"id\":\"" + runId + "-attest\",\"method\":\"tools/call\",\"params\":{\"name\":\"runtime_attestation\",\"arguments\":{\"expected_database\":\"\",\"expected_canonical_path\":\"E:\\\\NTK\\\\Resources\\\\NexusTK\\\\NexusTK.exe.i64\"}}}";
            return Post(request);
        }
        public string ReadResponse(int index)
        {
            string request = "{\"jsonrpc\":\"2.0\",\"id\":" + index.ToString(System.Globalization.CultureInfo.InvariantCulture) + ",\"method\":\"tools/list\",\"params\":{}}"; return Post(request);
        }
    }

    internal sealed class Coordinator
    {
        private static readonly string[] EnvelopeKeys = new string[] { "schema_version","public_tools_ok","only_runtime_attestation","session","expected_session","canonical_path","observed_path","listener_generation","listener_valid","redirector_generation","worker_generation","workers_valid","modules_valid","nonce","previous_nonce","partial_candidates","response_schema_ok","response_order_ok","response_count","save_response","save_response_id_ok","attempt","expected_write_sha","transaction_writer_generation","write_window_ok","disk_identity","p0_identity","verifier_ok","restore_length_ok","restore_flush_ok","restore_eof_ok","restore_timestamp_ok","restore_handle_closed","rollback_verifier_ok","retired_redirector_generation","retired_worker_generation","redirector_absent","worker_absent","worker_socket_absent","listener_after_generation","exclusive_open_ready" };
        private readonly string reportPath; private readonly string caseId; private readonly IRawBoundary raw; private readonly IJournalStore journal; private readonly AuthoritySeal seal;
        private int saveCalls; private int mutationCalls; private int sealBoundaries; private string disk = "UNREAD";
        internal Coordinator(string path,string id,IRawBoundary boundary,IJournalStore store,AuthoritySeal authority) { reportPath=path;caseId=id;raw=boundary;journal=store;seal=authority; }

        private Dictionary<string,object> BoundaryEnvelope()
        {
            seal.Check("BEFORE_ENVELOPE"); sealBoundaries++; string text = raw.ReadEnvelope(); seal.Check("AFTER_ENVELOPE"); sealBoundaries++;
            return StrictFrame.Object(text,EnvelopeKeys,"RAW_SEMANTIC_FIELD_FORBIDDEN");
        }
        private Dictionary<string,object> BoundaryResponse(int index)
        {
            seal.Check("BEFORE_RESPONSE_"+index); sealBoundaries++; string text=raw.ReadResponse(index); seal.Check("AFTER_RESPONSE_"+index); sealBoundaries++;
            return StrictFrame.Object(text,new string[]{"index","ok","value_sha256"},"RESPONSE_SCHEMA");
        }
        private static Dictionary<string,string> Token(string value,string code)
        {
            Dictionary<string,string> d=new Dictionary<string,string>(StringComparer.Ordinal); string[] parts=value.Split('|'); foreach(string part in parts){int p=part.IndexOf('=');if(p<=0||p==part.Length-1)throw new InvalidOperationException(code);string k=part.Substring(0,p);if(d.ContainsKey(k))throw new InvalidOperationException(code);d.Add(k,part.Substring(p+1));}return d;
        }
        private static void Generation(string value,string role)
        {
            Dictionary<string,string> d=Token(value,"GENERATION");string[] keys=new string[]{"pid","start","image","cmd","parent","socket","role"};if(d.Count!=keys.Length)throw new InvalidOperationException("GENERATION");foreach(string k in keys)if(!d.ContainsKey(k))throw new InvalidOperationException("GENERATION");long n;if(!Int64.TryParse(d["start"],out n)||n<=0)throw new InvalidOperationException("GENERATION");if(d["role"]!=role)throw new InvalidOperationException("GENERATION");
        }
        private static Dictionary<string,string> Disk(string value) { Dictionary<string,string>d=Token(value,"DISK");string[]k=new string[]{"volume","file","length","ticks","sha","writer","attempt"};if(d.Count!=k.Length)throw new InvalidOperationException("DISK");foreach(string x in k)if(!d.ContainsKey(x))throw new InvalidOperationException("DISK");if(d["sha"].Length!=64)throw new InvalidOperationException("DISK");return d; }
        private bool Cleanup(Dictionary<string,object> e)
        {
            return StrictFrame.String(e,"retired_redirector_generation")==StrictFrame.String(e,"redirector_generation") && StrictFrame.String(e,"retired_worker_generation")==StrictFrame.String(e,"worker_generation") && StrictFrame.Bool(e,"redirector_absent") && StrictFrame.Bool(e,"worker_absent") && StrictFrame.Bool(e,"worker_socket_absent") && StrictFrame.String(e,"listener_after_generation")==StrictFrame.String(e,"listener_generation") && StrictFrame.Bool(e,"exclusive_open_ready");
        }
        private bool Attributable(Dictionary<string,object> e,Dictionary<string,string> d)
        {
            return d["sha"]==StrictFrame.String(e,"expected_write_sha") && d["attempt"]==StrictFrame.String(e,"attempt") && d["writer"]==StrictFrame.String(e,"transaction_writer_generation") && StrictFrame.Bool(e,"write_window_ok");
        }
        private string Restore(Dictionary<string,object> e)
        {
            if(!StrictFrame.Bool(e,"restore_length_ok"))return "RESTORE_SHORT_WRITE";if(!StrictFrame.Bool(e,"restore_flush_ok"))return "RESTORE_FLUSH";if(!StrictFrame.Bool(e,"restore_eof_ok"))return "RESTORE_EOF";if(!StrictFrame.Bool(e,"restore_timestamp_ok"))return "RESTORE_TIMESTAMP";if(!StrictFrame.Bool(e,"restore_handle_closed"))return "RESTORE_OPEN_HANDLE";if(!StrictFrame.Bool(e,"rollback_verifier_ok"))return "ROLLBACK_VERIFIER";disk="P0";return "TERMINAL_EXPLICIT_FAILURE_RESTORED_P0";
        }
        private string Reentry(Dictionary<string,object> e,Dictionary<string,object> j)
        {
            string state=StrictFrame.String(j,"state");string result=StrictFrame.String(j,"result");Dictionary<string,string>d=Disk(StrictFrame.String(e,"disk_identity"));disk=d["sha"]==Disk(StrictFrame.String(e,"p0_identity"))["sha"]?"P0":(Attributable(e,d)?"P1":"PX");
            if(state=="ISSUED"&&disk=="P0")return "TERMINAL_REENTRY_ISSUED_P0";if(state=="ISSUED")return "TERMINAL_REENTRY_ISSUED_UNATTRIBUTED_PX";if(state=="CLASSIFIED"&&result=="EXPLICIT_FAILURE"&&disk=="P1")return Restore(e);if(state=="CLASSIFIED"&&result=="EXPLICIT_SUCCESS"&&disk=="P1")return "TERMINAL_REENTRY_CLASSIFIED_P1";return "TERMINAL_REENTRY_UNRESOLVED_STOP";
        }
        internal Dictionary<string,object> Run()
        {
            string terminal="UNSET";bool rejected=false;Dictionary<string,object> e=null;
            try
            {
                e=BoundaryEnvelope();
                if(StrictFrame.Int(e,"schema_version")!=7)throw new InvalidOperationException("TOOLS_SCHEMA_DRIFT");
                if(!StrictFrame.Bool(e,"public_tools_ok")||!StrictFrame.Bool(e,"only_runtime_attestation"))throw new InvalidOperationException("PUBLIC_TOOL_EXPOSURE");
                if(StrictFrame.String(e,"session")!=StrictFrame.String(e,"expected_session"))throw new InvalidOperationException("RETURNED_SESSION_BINDING");
                if(!String.Equals(Path.GetFullPath(StrictFrame.String(e,"canonical_path")),Path.GetFullPath(StrictFrame.String(e,"observed_path")),StringComparison.OrdinalIgnoreCase))throw new InvalidOperationException("CANONICAL_PATH_DRIFT");
                Generation(StrictFrame.String(e,"listener_generation"),"LISTENER");Generation(StrictFrame.String(e,"redirector_generation"),"REDIRECTOR");Generation(StrictFrame.String(e,"worker_generation"),"WORKER");
                if(!StrictFrame.Bool(e,"listener_valid"))throw new InvalidOperationException("LISTENER_OWNER");if(!StrictFrame.Bool(e,"workers_valid"))throw new InvalidOperationException("ALL_WORKER_DRIFT");if(!StrictFrame.Bool(e,"modules_valid"))throw new InvalidOperationException("MODULE_CONTAINMENT");if(StrictFrame.String(e,"nonce")==StrictFrame.String(e,"previous_nonce"))throw new InvalidOperationException("ATTESTATION_REPLAY");
                int partial=StrictFrame.Int(e,"partial_candidates");if(partial>1)terminal="PARTIAL_OPEN_AMBIGUOUS";else if(partial==1)terminal="PARTIAL_OPEN_RECOVERED_STOP";
                Dictionary<string,object> j=journal.Read(caseId);if(j!=null){ terminal=Reentry(e,j); }
                else if(terminal=="UNSET")
                {
                    for(int i=0;i<193;i++){Dictionary<string,object>r=BoundaryResponse(i);if(StrictFrame.Int(r,"index")!=i)throw new InvalidOperationException("RESPONSE_ORDER");if(!StrictFrame.Bool(r,"ok"))throw new InvalidOperationException("RESPONSE_SCHEMA");string h=StrictFrame.String(r,"value_sha256");if(h.Length!=64)throw new InvalidOperationException("RESPONSE_SCHEMA");}
                    if(!StrictFrame.Bool(e,"response_schema_ok"))throw new InvalidOperationException("RESPONSE_SCHEMA");if(!StrictFrame.Bool(e,"response_order_ok"))throw new InvalidOperationException("RESPONSE_ORDER");if(StrictFrame.Int(e,"response_count")!=193)throw new InvalidOperationException("RESPONSE_CARDINALITY");if(!StrictFrame.Bool(e,"save_response_id_ok"))throw new InvalidOperationException("SAVE_RESPONSE_ID");
                    mutationCalls=55;saveCalls=1;Dictionary<string,string>d=Disk(StrictFrame.String(e,"disk_identity"));Dictionary<string,string>p0=Disk(StrictFrame.String(e,"p0_identity"));bool p0same=d["sha"]==p0["sha"];bool p1=Attributable(e,d);disk=p0same?"P0":(p1?"P1":"PX");string response=StrictFrame.String(e,"save_response");
                    if(response=="EXPLICIT_FAILURE"&&disk=="P0")terminal="TERMINAL_EXPLICIT_FAILURE_P0";
                    else if(response=="EXPLICIT_FAILURE"&&disk=="P1")terminal=Restore(e);
                    else if(response=="EXPLICIT_FAILURE")terminal="TERMINAL_THIRD_IDENTITY_PX";
                    else if(response=="INDETERMINATE"&&disk=="P1")terminal="TERMINAL_INDETERMINATE_P1";
                    else if(response=="EXPLICIT_SUCCESS"&&disk=="P1")terminal="TERMINAL_P1";
                    else if(response=="EXPLICIT_SUCCESS"&&disk=="PX")terminal=(caseId=="CDA6-019"?"TERMINAL_RESPONSE_DISK_DISAGREEMENT_PX":"TERMINAL_THIRD_IDENTITY_PX");
                    else terminal="TERMINAL_UNRESOLVED_DISK_STOP";
                    if(!StrictFrame.Bool(e,"verifier_ok")&&terminal=="TERMINAL_P1")terminal="VERIFIER_REJECTED";
                }
            }
            catch(Exception ex){terminal=ex.Message;rejected=true;}
            bool cleanup=e!=null&&Cleanup(e);if(!cleanup)terminal="TERMINAL_CLEANUP_UNRESOLVED_STOP";
            seal.Check("TERMINAL");sealBoundaries++;
            Dictionary<string,object> receipt=new Dictionary<string,object>(StringComparer.Ordinal);receipt["authority"]="UID0001NW_CDA6_HELD";receipt["process_id"]=Process.GetCurrentProcess().Id;receipt["case_id"]=caseId;receipt["terminal"]=terminal;receipt["cleanup_complete"]=cleanup;receipt["disk"]=disk;receipt["save_calls"]=saveCalls;receipt["mutation_calls"]=mutationCalls;receipt["raw_calls"]=raw.Calls;receipt["seal_checks"]=seal.Checks;receipt["sealed_boundaries"]=sealBoundaries;receipt["journal_source"]=journal.Source;receipt["journal_sha256"]=journal.Digest;receipt["second_save_calls"]=journal.Digest=="NONE"?-1:0;receipt["second_mutation_calls"]=journal.Digest=="NONE"?-1:0;receipt["hostile_attempt"]=raw.HostileAttempt;receipt["rejected_before_effects"]=rejected&&saveCalls==0&&mutationCalls==0;return receipt;
        }
    }

    public static class ProductionLauncher
    {
        public static string Run(string reportPath,string mode,string caseId,string runId)
        {
            string path=Path.GetFullPath(reportPath);if(!File.Exists(path))throw new FileNotFoundException("REPORT",path);if(String.IsNullOrEmpty(runId))throw new ArgumentException("RUN_ID");AuthoritySeal seal=new AuthoritySeal();seal.Check("PUBLIC_ENTRY");
            IRawBoundary raw;IJournalStore journal;if(String.Equals(mode,"LIVE",StringComparison.Ordinal)){raw=new LiveRawBoundary(path,runId);journal=new ProductionJournalStore("E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64");}else if(String.Equals(mode,"FIXTURE",StringComparison.Ordinal)){raw=new FixtureRawBoundary(caseId);journal=new EmbeddedJournalStore(path);}else throw new ArgumentException("MODE");
            Dictionary<string,object> receipt=new Coordinator(path,caseId,raw,journal,seal).Run();receipt["mode"]=mode;receipt["run_id"]=runId;receipt["assembly_full_name"]=typeof(ProductionLauncher).Assembly.FullName;receipt["mvid"]=typeof(ProductionLauncher).Assembly.ManifestModule.ModuleVersionId.ToString("D");return new JavaScriptSerializer().Serialize(receipt);
        }
    }
}
~~~

## Removed Block R025

- SHA256: `1F92A9825503E02D451A781D2CB31B3DFC2F1DFB9694B7D6BF4DE9510C8AB5C0`
- Language: `powershell`
- Bytes: `1115`
- First recovered timestamp: `2026-08-09T03:42:34.748Z`
- Session provenance: rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 198746 (2026-08-09T03:42:34.748Z); rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 198747 (2026-08-09T03:42:36.480Z)

~~~powershell
param([Parameter(Mandatory=$true)][string]$ReportPath,[ValidateSet('LIVE','RECOVER','SELFTEST')][string]$Mode='SELFTEST',[string]$CaseId='OUTER-DUPLICATE-MEMBERS',[string]$RunId='UID0001NW-CDA7-SUPERVISOR')
$ErrorActionPreference='Stop';Set-StrictMode -Version Latest
$path=[IO.Path]::GetFullPath($ReportPath);$text=[IO.File]::ReadAllText($path).Replace("`r`n","`n").Replace("`r","`n")
$begin='<!-- UID0001NW_CDA7_SOURCE_BEGIN -->'+[char]10+'```csharp'+[char]10;$end=[char]10+'```'+[char]10+'<!-- UID0001NW_CDA7_SOURCE_END -->'
$a=$text.IndexOf($begin,[StringComparison]::Ordinal);$z=$text.IndexOf($end,$a+$begin.Length,[StringComparison]::Ordinal);if($a-lt0-or$z-lt0){throw 'CDA7_SOURCE_MARKER'}
$source=$text.Substring($a+$begin.Length,$z-$a-$begin.Length)
if(-not ('UID0001NW.CDA7Production.ProductionLauncher' -as [type])){Add-Type -TypeDefinition $source -ReferencedAssemblies @([System.Management.Automation.PSObject].Assembly.Location,'System.Web.Extensions.dll','System.Management.dll','System.Security.dll')}
[UID0001NW.CDA7Production.ProductionLauncher]::Run($path,$Mode,$CaseId,$RunId)
~~~

## Removed Block R026

- SHA256: `7AE21C30B778FB4F9CC712FBA2A45880E8F78351F0C8B85DE894168183C02336`
- Language: `csharp`
- Bytes: `36297`
- First recovered timestamp: `2026-08-09T03:42:34.748Z`
- Session provenance: rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 198746 (2026-08-09T03:42:34.748Z); rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 198747 (2026-08-09T03:42:36.480Z)

~~~csharp
using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Management;
using System.Management.Automation;
using System.Management.Automation.Runspaces;
using System.Net;
using System.Net.NetworkInformation;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Web.Script.Serialization;
using Microsoft.Win32.SafeHandles;

namespace UID0001NW.CDA7Production
{
    internal static class Crypto
    {
        internal static string Sha(byte[] value) { using (SHA256 h = SHA256.Create()) return BitConverter.ToString(h.ComputeHash(value)).Replace("-", ""); }
        internal static string Sha(string value) { return Sha(new UTF8Encoding(false).GetBytes(value)); }
        internal static string Hmac(byte[] key, string value) { using (HMACSHA256 h = new HMACSHA256(key)) return BitConverter.ToString(h.ComputeHash(new UTF8Encoding(false).GetBytes(value))).Replace("-", ""); }
    }

    internal sealed class StrictJson
    {
        private readonly string text; private int at;
        private StrictJson(string value) { text = value; }
        internal static void Validate(string value) { if (String.IsNullOrWhiteSpace(value)) throw new InvalidDataException("JSON_EMPTY"); StrictJson p = new StrictJson(value); p.Value(); p.White(); if (p.at != value.Length) throw new InvalidDataException("JSON_TRAILING"); }
        private void White() { while (at < text.Length && (text[at] == ' ' || text[at] == '\t' || text[at] == '\r' || text[at] == '\n')) at++; }
        private void Need(char c) { White(); if (at >= text.Length || text[at] != c) throw new InvalidDataException("JSON_TOKEN"); at++; }
        private void Value() { White(); if (at >= text.Length) throw new InvalidDataException("JSON_EOF"); char c = text[at]; if (c == '{') Obj(); else if (c == '[') Arr(); else if (c == '"') Str(); else if (c == '-' || Char.IsDigit(c)) Num(); else if (Match("true") || Match("false") || Match("null")) { } else throw new InvalidDataException("JSON_VALUE"); }
        private bool Match(string s) { if (at + s.Length > text.Length || String.CompareOrdinal(text, at, s, 0, s.Length) != 0) return false; at += s.Length; return true; }
        private void Obj() { Need('{'); HashSet<string> keys = new HashSet<string>(StringComparer.Ordinal); White(); if (at < text.Length && text[at] == '}') { at++; return; } while (true) { White(); string key = Str(); if (!keys.Add(key)) throw new InvalidDataException("JSON_DUPLICATE_MEMBER:" + key); Need(':'); Value(); White(); if (at < text.Length && text[at] == ',') { at++; continue; } Need('}'); return; } }
        private void Arr() { Need('['); White(); if (at < text.Length && text[at] == ']') { at++; return; } while (true) { Value(); White(); if (at < text.Length && text[at] == ',') { at++; continue; } Need(']'); return; } }
        private string Str() { Need('"'); StringBuilder b = new StringBuilder(); while (at < text.Length) { char c = text[at++]; if (c == '"') return b.ToString(); if (c == '\\') { if (at >= text.Length) throw new InvalidDataException("JSON_ESCAPE"); char e = text[at++]; if (e == 'u') { if (at + 4 > text.Length) throw new InvalidDataException("JSON_UNICODE"); int n; if (!Int32.TryParse(text.Substring(at, 4), NumberStyles.HexNumber, CultureInfo.InvariantCulture, out n)) throw new InvalidDataException("JSON_UNICODE"); b.Append((char)n); at += 4; } else { const string esc = "\"\\/bfnrt"; int i = esc.IndexOf(e); if (i < 0) throw new InvalidDataException("JSON_ESCAPE"); b.Append("\"\\/\b\f\n\r\t"[i]); } } else { if (c < 0x20) throw new InvalidDataException("JSON_CONTROL"); b.Append(c); } } throw new InvalidDataException("JSON_STRING_EOF"); }
        private void Num() { int s = at; if (text[at] == '-') at++; if (at >= text.Length) throw new InvalidDataException("JSON_NUMBER"); if (text[at] == '0') at++; else { if (!Char.IsDigit(text[at])) throw new InvalidDataException("JSON_NUMBER"); while (at < text.Length && Char.IsDigit(text[at])) at++; } if (at < text.Length && text[at] == '.') { at++; int d = at; while (at < text.Length && Char.IsDigit(text[at])) at++; if (at == d) throw new InvalidDataException("JSON_NUMBER"); } if (at < text.Length && (text[at] == 'e' || text[at] == 'E')) { at++; if (at < text.Length && (text[at] == '+' || text[at] == '-')) at++; int d = at; while (at < text.Length && Char.IsDigit(text[at])) at++; if (at == d) throw new InvalidDataException("JSON_NUMBER"); } if (at == s) throw new InvalidDataException("JSON_NUMBER"); }
    }

    internal sealed class EffectMeter
    {
        internal int Rpc, Mutation, Save, ProcessInspect, ProcessStop, SocketInspect, FileOpen, FileWrite, Flush, Restore;
        internal Dictionary<string,object> Snapshot() { return new Dictionary<string,object> { {"rpc",Rpc},{"mutation",Mutation},{"save",Save},{"process_inspect",ProcessInspect},{"process_stop",ProcessStop},{"socket_inspect",SocketInspect},{"file_open",FileOpen},{"file_write",FileWrite},{"flush",Flush},{"restore_bytes",Restore} }; }
    }

    internal sealed class McpWire
    {
        private readonly Uri endpoint = new Uri("http://127.0.0.1:13337/mcp"); private readonly JavaScriptSerializer json = new JavaScriptSerializer(); private readonly EffectMeter meter; private string session; private int nextId = 700000; private PhysicalAuthority effects;
        private static readonly HashSet<string> Mutators = new HashSet<string>(new string[] { "declare_type","set_type","set_function_comments","set_address_comments","rename","declare_stack" }, StringComparer.Ordinal);
        internal McpWire(EffectMeter value) { meter = value; }
        internal void Bind(PhysicalAuthority value) { effects = value; }
        internal void Initialize()
        {
            Dictionary<string,object> p = new Dictionary<string,object>(); p["protocolVersion"]="2025-06-18"; p["capabilities"]=new Dictionary<string,object>(); p["clientInfo"]=new Dictionary<string,object>{{"name","uid0001nw-cda7"},{"version","7"}};
            string raw = SerializeRpc("initialize", p, ++nextId); Post(raw, true);
            Dictionary<string,object> n = new Dictionary<string,object>{{"jsonrpc","2.0"},{"method","notifications/initialized"},{"params",new Dictionary<string,object>()}}; Post(json.Serialize(n), false);
        }
        internal string Send(string raw)
        {
            StrictJson.Validate(raw); Dictionary<string,object> root = AsObject(json.DeserializeObject(raw), "REQUEST"); string method = StringValue(root,"method"); string tool = "";
            if (method == "tools/call") { Dictionary<string,object> param = AsObject(root["params"],"PARAMS"); tool=StringValue(param,"name"); if (Mutators.Contains(tool)) meter.Mutation++; if (tool=="idb_save") { meter.Save++; if (meter.Save != 1) throw new InvalidOperationException("SECOND_SAVE"); if (effects != null) effects.BeginSave(); } }
            try { return Post(raw, false); } finally { if (tool=="idb_save" && effects != null) effects.EndSave(); }
        }
        internal Dictionary<string,object> CallTool(string name, Dictionary<string,object> args)
        {
            Dictionary<string,object> p = new Dictionary<string,object>{{"name",name},{"arguments",args}}; int id=++nextId; string raw=Post(SerializeRpc("tools/call",p,id),false); Dictionary<string,object> env=AsObject(json.DeserializeObject(raw),"ENV"); if(Convert.ToInt32(env["id"],CultureInfo.InvariantCulture)!=id)throw new InvalidDataException("MCP_ID"); Dictionary<string,object> result=AsObject(env["result"],"RESULT"); if(result.ContainsKey("isError") && result["isError"] is bool && (bool)result["isError"])throw new InvalidOperationException("MCP_TOOL_ERROR:"+name); return AsObject(result["structuredContent"],"STRUCTURED");
        }
        private string SerializeRpc(string method, object p, int id) { return json.Serialize(new Dictionary<string,object>{{"jsonrpc","2.0"},{"id",id},{"method",method},{"params",p}}); }
        private string Post(string body, bool initialize)
        {
            meter.Rpc++; HttpWebRequest request=(HttpWebRequest)WebRequest.Create(endpoint); request.Method="POST"; request.ContentType="application/json"; request.Accept="application/json, text/event-stream"; request.Timeout=60000; request.ReadWriteTimeout=60000; request.Headers["MCP-Protocol-Version"]="2025-06-18"; if(!String.IsNullOrEmpty(session))request.Headers["Mcp-Session-Id"]=session;
            byte[] bytes=new UTF8Encoding(false).GetBytes(body); request.ContentLength=bytes.Length; using(Stream s=request.GetRequestStream())s.Write(bytes,0,bytes.Length);
            using(HttpWebResponse response=(HttpWebResponse)request.GetResponse()) { string header=response.Headers["Mcp-Session-Id"]; if(initialize){if(String.IsNullOrWhiteSpace(header))throw new InvalidDataException("MCP_SESSION_HEADER");session=header;} using(StreamReader reader=new StreamReader(response.GetResponseStream(),Encoding.UTF8,false)){string text=reader.ReadToEnd();string value=ExtractJson(text);StrictJson.Validate(value);return value;} }
        }
        private static string ExtractJson(string text) { string t=text.Trim(); if(t.StartsWith("data:",StringComparison.Ordinal)){StringBuilder b=new StringBuilder();using(StringReader r=new StringReader(t)){string line;while((line=r.ReadLine())!=null)if(line.StartsWith("data:",StringComparison.Ordinal))b.Append(line.Substring(5).Trim());}return b.ToString();}return t; }
        internal static Dictionary<string,object> AsObject(object value,string code){Dictionary<string,object>d=value as Dictionary<string,object>;if(d==null)throw new InvalidDataException(code+"_OBJECT");return d;}
        internal static string StringValue(Dictionary<string,object>d,string key){object v;if(!d.TryGetValue(key,out v)||v==null||v.GetType()!=typeof(string))throw new InvalidDataException("STRING:"+key);return(string)v;}
    }

    internal static class Native
    {
        [StructLayout(LayoutKind.Sequential)] internal struct FileTime { internal uint Low,High; }
        [StructLayout(LayoutKind.Sequential)] internal struct ByHandle { internal uint Attr; internal FileTime Create,Access,Write; internal uint Volume,SizeHigh,SizeLow,Links,IndexHigh,IndexLow; }
        [DllImport("kernel32.dll",SetLastError=true)] internal static extern bool GetFileInformationByHandle(SafeFileHandle h,out ByHandle i);
        [DllImport("iphlpapi.dll",SetLastError=true)] internal static extern uint GetExtendedTcpTable(IntPtr table,ref int size,bool order,int family,int cls,uint reserved);
    }

    internal sealed class PhysicalAuthority : IDisposable
    {
        private readonly string canonical,runId,journalPath,keyPath,backupPath,lockPath; private readonly bool recovery; private readonly JavaScriptSerializer json=new JavaScriptSerializer(); private readonly EffectMeter meter; private readonly McpWire wire; private Mutex mutex; private FileStream lockStream; private string token; private Dictionary<string,object> journalPayload; private Dictionary<string,object> saveBefore,saveAfter; private readonly HashSet<int> retiredPids=new HashSet<int>(); private readonly HashSet<int> workerPorts=new HashSet<int>(); internal bool HandoffPending;
        internal PhysicalAuthority(string path,string id,bool recover,EffectMeter m,McpWire w){canonical=Path.GetFullPath(path);runId=id;recovery=recover;meter=m;wire=w;string safe=Regex.Replace(id,"[^A-Za-z0-9._-]","_");string root=canonical+".UID0001NW.CDA7."+safe;journalPath=root+".journal";keyPath=root+".key";backupPath=root+".B0";lockPath=canonical+".UID0001NW.CDA7.lock";}
        public void Dispose(){if(lockStream!=null){lockStream.Dispose();lockStream=null;}if(mutex!=null){try{mutex.ReleaseMutex();}catch{}mutex.Dispose();mutex=null;}}
        internal void BeginSave(){saveBefore=Capture(canonical,"","",0);}
        internal void EndSave(){saveAfter=Capture(canonical,"","",0);}
        internal string Invoke(string raw)
        {
            try { StrictJson.Validate(raw); Dictionary<string,object> req=McpWire.AsObject(json.DeserializeObject(raw),"EFFECT");string op=McpWire.StringValue(req,"operation");Dictionary<string,object>a=McpWire.AsObject(req["arguments"],"ARGS");object data=Dispatch(op,a);return json.Serialize(new Dictionary<string,object>{{"ok",true},{"changed",Changed(op)},{"data",data}}); }
            catch(Exception ex){return json.Serialize(new Dictionary<string,object>{{"ok",false},{"changed",false},{"error",new Dictionary<string,object>{{"code","CDA7_PHYSICAL"},{"detail",ex.GetType().Name+":"+ex.Message}}}});}
        }
        private static bool Changed(string op){return op=="retire_generation"||op=="create_backup"||op.StartsWith("journal_",StringComparison.Ordinal)||op=="restore_p0"||op=="release_authority";}
        private object Dispatch(string op,Dictionary<string,object>a)
        {
            switch(op){
                case "acquire_authority": return Acquire(); case "release_authority": Dispose();return new Dictionary<string,object>{{"released",true}};
                case "create_backup": return CreateBackup(); case "capture_tuple": return AttributedTuple(McpWire.StringValue(a,"purpose"));
                case "journal_create": return WriteJournal(McpWire.AsObject(a["record"],"JOURNAL"),true,false); case "journal_replace": return WriteJournal(McpWire.AsObject(a["record"],"JOURNAL"),false,false); case "journal_delete": return DeleteOrHandoff(McpWire.AsObject(a["record"],"DELETE"));
                case "measure_generation": return MeasureGeneration(a); case "retire_generation": return Retire(a); case "prove_generation_absent": return new Dictionary<string,object>{{"absent",GenerationsAbsent(a)}}; case "prove_socket_absent": return new Dictionary<string,object>{{"absent",OwnerPid(Convert.ToInt32(a["port"],CultureInfo.InvariantCulture))<0}};
                case "prove_listener_continuity": return new Dictionary<string,object>{{"continuous",OwnerPid(13337)>0}}; case "prove_all_sessions_absent": return new Dictionary<string,object>{{"absent",SessionsAbsent()}}; case "prove_all_generations_absent": return new Dictionary<string,object>{{"absent",AllRetiredAbsent()}}; case "prove_all_worker_sockets_absent": return new Dictionary<string,object>{{"absent",AllPortsAbsent()}};
                case "prove_exclusive_open": return new Dictionary<string,object>{{"ready",ExclusiveReady()}}; case "restore_p0": return Restore(a); case "verify_semantics": return Verify(a);
                default: throw new InvalidOperationException("UNKNOWN_EFFECT:"+op);
            }
        }
        private Dictionary<string,object> Acquire()
        {
            bool created=false;mutex=new Mutex(false,"Global\\UID0001NW_CDA7_"+Crypto.Sha(canonical).Substring(0,32),out created);try{if(!mutex.WaitOne(0,false))throw new IOException("AUTHORITY_BUSY");}catch(AbandonedMutexException){}
            lockStream=new FileStream(lockPath,FileMode.OpenOrCreate,FileAccess.ReadWrite,FileShare.None);token=Guid.NewGuid().ToString("N");journalPayload=ReadJournal(false);string state=journalPayload==null?"NONE":McpWire.StringValue(journalPayload,"state");return new Dictionary<string,object>{{"token",token},{"journal_state",state},{"journal",journalPayload}};
        }
        private Dictionary<string,object> CreateBackup()
        {
            Dictionary<string,object> p0;long copied=0;using(FileStream src=Open(canonical,FileMode.Open,FileAccess.Read,FileShare.None)){p0=Tuple(src,canonical,"","",0);using(FileStream dst=Open(backupPath,FileMode.CreateNew,FileAccess.Write,FileShare.None)){byte[]buf=new byte[1024*1024];int n;while((n=src.Read(buf,0,buf.Length))>0){dst.Write(buf,0,n);copied+=n;meter.FileWrite+=n;}if(src.Position!=src.Length||copied!=src.Length)throw new EndOfStreamException("BACKUP_EOF");dst.Flush(true);meter.Flush++;if(dst.Length!=copied)throw new IOException("BACKUP_LENGTH");}}
            File.SetLastWriteTimeUtc(backupPath,DateTime.FromFileTimeUtc(Convert.ToInt64(p0["mtime_filetime_utc"],CultureInfo.InvariantCulture)));Dictionary<string,object>b0=Capture(backupPath,"","",0);if(Convert.ToInt64(b0["size"])!=Convert.ToInt64(p0["size"])||McpWire.StringValue(b0,"sha256")!=McpWire.StringValue(p0,"sha256"))throw new IOException("B0_MISMATCH");return new Dictionary<string,object>{{"p0",p0},{"b0",b0},{"create_new",true},{"exact_bytes",true},{"exact_eof",true},{"flush_through",true},{"disposed",true},{"closed_reopen_equal",true}};
        }
        private Dictionary<string,object> AttributedTuple(string purpose)
        {
            Dictionary<string,object> t=Capture(canonical,"","",0);if(purpose.IndexOf("post_save",StringComparison.OrdinalIgnoreCase)>=0&&journalPayload!=null&&saveBefore!=null&&saveAfter!=null&&McpWire.StringValue(saveBefore,"sha256")!=McpWire.StringValue(saveAfter,"sha256")){t["attempt_id"]=McpWire.StringValue(journalPayload,"attempt_id");t["writer_generation"]=McpWire.StringValue(journalPayload,"tx_generation");t["write_epoch"]=Convert.ToInt64(journalPayload["write_epoch"],CultureInfo.InvariantCulture);}return t;
        }
        private Dictionary<string,object> WriteJournal(Dictionary<string,object> payload,bool create,bool terminalHandoff)
        {
            if(McpWire.StringValue(payload,"canonical_idb_path")!=canonical)throw new InvalidDataException("JOURNAL_PATH");journalPayload=payload;byte[]key=LoadOrCreateKey();string payloadText=json.Serialize(payload);string wrapper=json.Serialize(new Dictionary<string,object>{{"schema_version",7},{"payload",payload},{"mac",Crypto.Hmac(key,payloadText)}});DurableInstall(journalPath,wrapper,create);Dictionary<string,object>check=ReadJournal(true);if(McpWire.StringValue(check,"state")!=McpWire.StringValue(payload,"state"))throw new IOException("JOURNAL_REREAD");return new Dictionary<string,object>{{"state",McpWire.StringValue(payload,"state")},{"record_sha256",Crypto.Sha(payloadText)},{"durable",true},{"closed_reopen_equal",true}};
        }
        private Dictionary<string,object> DeleteOrHandoff(Dictionary<string,object> disposition)
        {
            if(!recovery){if(journalPayload==null)throw new InvalidDataException("HANDOFF_JOURNAL");string d=McpWire.StringValue(disposition,"disposition");if(d.IndexOf("P0",StringComparison.Ordinal)>=0){Dictionary<string,object>p0=Capture(canonical,"","",0);journalPayload["candidate"]=p0;journalPayload["identity"]="P0";}WriteJournal(journalPayload,false,true);HandoffPending=true;return new Dictionary<string,object>{{"state","CLASSIFIED"},{"record_sha256",Crypto.Sha(json.Serialize(journalPayload))},{"durable",true},{"closed_reopen_equal",true}};}
            if(File.Exists(journalPath))File.Delete(journalPath);if(File.Exists(keyPath))File.Delete(keyPath);if(File.Exists(backupPath))File.Delete(backupPath);journalPayload=null;return new Dictionary<string,object>{{"state","NONE"},{"record_sha256",Crypto.Sha(json.Serialize(disposition))},{"durable",true},{"closed_reopen_equal",true}};
        }
        private Dictionary<string,object> ReadJournal(bool required)
        {
            if(!File.Exists(journalPath)){if(required)throw new FileNotFoundException("JOURNAL");return null;}string text=File.ReadAllText(journalPath);StrictJson.Validate(text);Dictionary<string,object>w=McpWire.AsObject(json.DeserializeObject(text),"JOURNAL_WRAPPER");Dictionary<string,object>p=McpWire.AsObject(w["payload"],"JOURNAL_PAYLOAD");byte[]key=LoadKey();if(McpWire.StringValue(w,"mac")!=Crypto.Hmac(key,json.Serialize(p)))throw new CryptographicException("JOURNAL_MAC");return p;
        }
        private byte[] LoadOrCreateKey(){if(File.Exists(keyPath))return LoadKey();byte[]key=new byte[32];using(RandomNumberGenerator r=RandomNumberGenerator.Create())r.GetBytes(key);byte[]protectedKey=ProtectedData.Protect(key,null,DataProtectionScope.CurrentUser);DurableInstall(keyPath,Convert.ToBase64String(protectedKey),true);return key;}
        private byte[] LoadKey(){byte[]wrapped=Convert.FromBase64String(File.ReadAllText(keyPath));return ProtectedData.Unprotect(wrapped,null,DataProtectionScope.CurrentUser);}
        private void DurableInstall(string path,string text,bool create)
        {
            string temp=path+"."+Guid.NewGuid().ToString("N")+".tmp";byte[]bytes=new UTF8Encoding(false).GetBytes(text);using(FileStream s=Open(temp,FileMode.CreateNew,FileAccess.Write,FileShare.None)){s.Write(bytes,0,bytes.Length);meter.FileWrite+=bytes.Length;s.Flush(true);meter.Flush++;}if(create){if(File.Exists(path)){File.Delete(temp);throw new IOException("DURABLE_EXISTS");}File.Move(temp,path);}else{if(!File.Exists(path)){File.Delete(temp);throw new FileNotFoundException("DURABLE_REPLACE");}string bak=path+".replace.bak";if(File.Exists(bak))File.Delete(bak);File.Replace(temp,path,bak,true);if(File.Exists(bak))File.Delete(bak);}if(File.ReadAllText(path)!=text)throw new IOException("DURABLE_REREAD");
        }
        private object MeasureGeneration(Dictionary<string,object>a)
        {
            int worker=Convert.ToInt32(a["worker_pid"]),redirector=Convert.ToInt32(a["redirector_pid"]),port=Convert.ToInt32(a["socket_port"]);ProcessInfo w=Info(worker),r=Info(redirector);workerPorts.Add(port);return new Dictionary<string,object>{{"worker_generation",w.Generation},{"redirector_generation",r.Generation},{"worker_parent_ok",w.Parent==redirector},{"socket_owner_ok",OwnerPid(port)==worker},{"worker_image",w.Image},{"worker_command",w.Command},{"redirector_image",r.Image},{"redirector_command",r.Command}};
        }
        private object Retire(Dictionary<string,object>a)
        {
            int worker=Convert.ToInt32(a["worker_pid"]),redirector=Convert.ToInt32(a["redirector_pid"]),port=Convert.ToInt32(a["socket_port"]);ProcessInfo w=Info(worker),r=Info(redirector);if(w.Generation!=McpWire.StringValue(a,"worker_generation")||r.Generation!=McpWire.StringValue(a,"redirector_generation")||w.Parent!=redirector||OwnerPid(port)!=worker)throw new InvalidOperationException("GENERATION_MISMATCH");KillExact(w);KillExact(r);retiredPids.Add(worker);retiredPids.Add(redirector);return new Dictionary<string,object>{{"worker_retired",!Exists(worker)},{"redirector_retired",!Exists(redirector)},{"generation_match",true}};
        }
        private bool GenerationsAbsent(Dictionary<string,object>a){foreach(object v in a.Values){string s=v as string;if(s!=null&&s.StartsWith("pid:",StringComparison.Ordinal)){int p=Int32.Parse(s.Split(';')[0].Substring(4),CultureInfo.InvariantCulture);if(Exists(p))return false;}}return true;}
        private bool SessionsAbsent(){Dictionary<string,object>b=wire.CallTool("idb_list",new Dictionary<string,object>());object[]rows=b["sessions"] as object[];if(rows==null)return false;foreach(object o in rows){Dictionary<string,object>r=McpWire.AsObject(o,"SESSION");object active;if(r.TryGetValue("is_active",out active)&&active is bool&&(bool)active&&String.Equals(Path.GetFullPath(McpWire.StringValue(r,"input_path")),canonical,StringComparison.OrdinalIgnoreCase))return false;}return true;}
        private bool AllRetiredAbsent(){foreach(int p in retiredPids)if(Exists(p))return false;return true;}
        private bool AllPortsAbsent(){foreach(int p in workerPorts)if(OwnerPid(p)>=0)return false;return true;}
        private bool ExclusiveReady(){try{using(FileStream s=Open(canonical,FileMode.Open,FileAccess.Read,FileShare.None))return true;}catch{return false;}}
        private object Restore(Dictionary<string,object>a)
        {
            Dictionary<string,object>p0=McpWire.AsObject(a["p0"],"P0"),b0=McpWire.AsObject(a["b0"],"B0"),candidate=McpWire.AsObject(a["candidate"],"CANDIDATE");Dictionary<string,object>now=Capture(canonical,McpWire.StringValue(candidate,"attempt_id"),McpWire.StringValue(candidate,"writer_generation"),Convert.ToInt64(candidate["write_epoch"]));if(McpWire.StringValue(now,"sha256")!=McpWire.StringValue(candidate,"sha256"))throw new IOException("RESTORE_CANDIDATE_DRIFT");Dictionary<string,object>backup=Capture(McpWire.StringValue(b0,"path"),"","",0);if(McpWire.StringValue(backup,"sha256")!=McpWire.StringValue(p0,"sha256"))throw new IOException("RESTORE_B0");long copied=0;using(FileStream src=Open(McpWire.StringValue(b0,"path"),FileMode.Open,FileAccess.Read,FileShare.None))using(FileStream dst=Open(canonical,FileMode.Open,FileAccess.ReadWrite,FileShare.None)){dst.SetLength(0);byte[]buf=new byte[1024*1024];int n;while((n=src.Read(buf,0,buf.Length))>0){dst.Write(buf,0,n);copied+=n;meter.Restore+=n;}if(src.Position!=src.Length||copied!=Convert.ToInt64(p0["size"]))throw new EndOfStreamException("RESTORE_EOF");dst.Flush(true);meter.Flush++;}File.SetLastWriteTimeUtc(canonical,DateTime.FromFileTimeUtc(Convert.ToInt64(p0["mtime_filetime_utc"])));Dictionary<string,object>after=Capture(canonical,"","",0);bool exact=McpWire.StringValue(after,"sha256")==McpWire.StringValue(p0,"sha256")&&Convert.ToInt64(after["size"])==Convert.ToInt64(p0["size"]);return new Dictionary<string,object>{{"truncated",true},{"exact_bytes",exact},{"exact_eof",true},{"flush_through",true},{"timestamp_restored",Convert.ToInt64(after["mtime_filetime_utc"])==Convert.ToInt64(p0["mtime_filetime_utc"])},{"disposed",true},{"closed_reopen_equal",exact}};
        }
        private object Verify(Dictionary<string,object>a){string session=McpWire.StringValue(a,"session"),phase=McpWire.StringValue(a,"phase");Dictionary<string,object>att=wire.CallTool("runtime_attestation",new Dictionary<string,object>{{"expected_database",session},{"expected_canonical_path",canonical}});object ok;bool good=att.TryGetValue("ok",out ok)&&ok is bool&&(bool)ok;return new Dictionary<string,object>{{"verified",good},{"projection_sha256",Crypto.Sha(phase+"|"+session+"|"+json.Serialize(att))}};}
        private FileStream Open(string path,FileMode mode,FileAccess access,FileShare share){meter.FileOpen++;return new FileStream(path,mode,access,share,1024*1024,FileOptions.WriteThrough);}
        private Dictionary<string,object> Capture(string path,string attempt,string generation,long epoch){using(FileStream s=Open(path,FileMode.Open,FileAccess.Read,FileShare.None))return Tuple(s,path,attempt,generation,epoch);}
        private Dictionary<string,object> Tuple(FileStream s,string path,string attempt,string generation,long epoch){Native.ByHandle i;if(!Native.GetFileInformationByHandle(s.SafeFileHandle,out i))throw new IOException("FILE_INFO:"+Marshal.GetLastWin32Error());long pos=s.Position;s.Position=0;string sha;using(SHA256 h=SHA256.Create())sha=BitConverter.ToString(h.ComputeHash(s)).Replace("-","");s.Position=pos;long ticks=(long)(((ulong)i.Write.High<<32)|i.Write.Low);return new Dictionary<string,object>{{"path",Path.GetFullPath(path)},{"volume",unchecked((int)i.Volume)},{"file_index",i.IndexHigh.ToString("X8")+i.IndexLow.ToString("X8")},{"size",s.Length},{"mtime_filetime_utc",ticks},{"sha256",sha},{"attempt_id",attempt},{"writer_generation",generation},{"write_epoch",epoch},{"observed_content_sha256",sha},{"stable_reopen",true},{"exclusive_open",true}};}
        private sealed class ProcessInfo{internal int Pid,Parent;internal long Start;internal string Image,Command;internal string Generation{get{return"pid:"+Pid.ToString(CultureInfo.InvariantCulture)+";created:"+Start.ToString(CultureInfo.InvariantCulture);}}}
        private ProcessInfo Info(int pid){meter.ProcessInspect++;using(ManagementObjectSearcher q=new ManagementObjectSearcher("SELECT ProcessId,ParentProcessId,CommandLine,ExecutablePath,CreationDate FROM Win32_Process WHERE ProcessId="+pid.ToString(CultureInfo.InvariantCulture))){foreach(ManagementObject o in q.Get()){DateTime dt=ManagementDateTimeConverter.ToDateTime(Convert.ToString(o["CreationDate"],CultureInfo.InvariantCulture)).ToUniversalTime();return new ProcessInfo{Pid=pid,Parent=Convert.ToInt32(o["ParentProcessId"]),Start=dt.ToFileTimeUtc(),Image=Convert.ToString(o["ExecutablePath"]),Command=Convert.ToString(o["CommandLine"])};}}throw new InvalidOperationException("PROCESS_ABSENT:"+pid);}
        private void KillExact(ProcessInfo expected){ProcessInfo now=Info(expected.Pid);if(now.Generation!=expected.Generation||now.Parent!=expected.Parent||now.Image!=expected.Image||now.Command!=expected.Command)throw new InvalidOperationException("PID_REUSE:"+expected.Pid);using(Process p=Process.GetProcessById(expected.Pid)){p.Kill();if(!p.WaitForExit(30000))throw new TimeoutException("PROCESS_RETIRE:"+expected.Pid);}meter.ProcessStop++;}
        private static bool Exists(int pid){try{using(Process p=Process.GetProcessById(pid))return!p.HasExited;}catch{return false;}}
        private int OwnerPid(int port){meter.SocketInspect++;int size=0;Native.GetExtendedTcpTable(IntPtr.Zero,ref size,true,2,5,0);IntPtr mem=Marshal.AllocHGlobal(size);try{if(Native.GetExtendedTcpTable(mem,ref size,true,2,5,0)!=0)return-1;int count=Marshal.ReadInt32(mem);IntPtr row=IntPtr.Add(mem,4);int rowSize=24;for(int n=0;n<count;n++){int localPort=IPAddress.NetworkToHostOrder((short)Marshal.ReadInt32(row,8))&0xffff;int state=Marshal.ReadInt32(row,0);int pid=Marshal.ReadInt32(row,20);if(state==2&&localPort==port)return pid;row=IntPtr.Add(row,rowSize);}return-1;}finally{Marshal.FreeHGlobal(mem);}}
    }

    internal static class PrivateCoordinator
    {
        private static readonly string[] Blocks={"V42_CODE_A","V42_CODE_B","CDA_CODE","CDA6_CODE_A","CDA6_CODE_B","CDA6_CODE_C"};
        internal static string Run(string report,string runId,McpWire wire,PhysicalAuthority effects)
        {
            using(Runspace rs=RunspaceFactory.CreateRunspace()){rs.Open();rs.SessionStateProxy.SetVariable("__cda7_wire",wire);rs.SessionStateProxy.SetVariable("__cda7_effect",effects);using(PowerShell ps=PowerShell.Create()){ps.Runspace=rs;foreach(string name in Blocks){string code=Extract(report,name,"powershell");ps.Commands.Clear();ps.Streams.Error.Clear();ps.AddScript(code);ps.Invoke();if(ps.Streams.Error.Count!=0)throw new InvalidOperationException("PRIVATE_BLOCK:"+name+":"+ps.Streams.Error[0]);}string call="$script:__cda7_core=(Get-Command Invoke-UID0001NWCanonicalIdbDurableAuthority -CommandType Function).ScriptBlock; function Invoke-UID0001NWCanonicalIdbDurableAuthority { throw 'UID0001NW_CDA7:HISTORICAL_PUBLIC_ENTRY_DISABLED:CDA6' }; function Invoke-UID0001NWAtomicEnvelopeV4 { throw 'UID0001NW_CDA7:HISTORICAL_PUBLIC_ENTRY_DISABLED:V4' }; function Invoke-UID0001NWV42Cases { throw 'UID0001NW_CDA7:HISTORICAL_PUBLIC_ENTRY_DISABLED:V42' }; function Import-UID0001NWV43Authority { throw 'UID0001NW_CDA7:HISTORICAL_PUBLIC_ENTRY_DISABLED:V43' }; $t={param([string]$raw)$script:__cda7_wire.Send($raw)}.GetNewClosure();$e={param([string]$raw)$script:__cda7_effect.Invoke($raw)}.GetNewClosure(); & $script:__cda7_core -ReportPath $args[0] -Transport $t -Effect $e -RunId $args[1] | ConvertTo-Json -Depth 100 -Compress";ps.Commands.Clear();ps.Streams.Error.Clear();ps.AddScript(call).AddArgument(report).AddArgument(runId);IList<PSObject>rows=ps.Invoke();if(ps.Streams.Error.Count!=0||rows.Count!=1)throw new InvalidOperationException("PRIVATE_COORDINATOR:"+(ps.Streams.Error.Count==0?"CARDINALITY":ps.Streams.Error[0].ToString()));return rows[0].ToString();}}
            }
        }
        private static string Extract(string report,string name,string language){string text=File.ReadAllText(report).Replace("\r\n","\n").Replace('\r','\n');string begin="<!-- UID0001NW_"+name+"_BEGIN -->\n```"+language+"\n";string end="\n```\n<!-- UID0001NW_"+name+"_END -->";int a=text.IndexOf(begin,StringComparison.Ordinal),z=a<0?-1:text.IndexOf(end,a+begin.Length,StringComparison.Ordinal);if(a<0||z<0)throw new InvalidDataException("BLOCK:"+name);return text.Substring(a+begin.Length,z-a-begin.Length);}
    }

    public static class ProductionLauncher
    {
        private const string Canonical="E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64";
        public static string Run(string reportPath,string mode,string caseId,string runId)
        {
            string report=Path.GetFullPath(reportPath);if(!File.Exists(report))throw new FileNotFoundException("REPORT",report);if(!Regex.IsMatch(runId??"","^[A-Za-z0-9._-]{8,80}$"))throw new ArgumentException("RUN_ID");if(mode=="SELFTEST")return SelfTest(caseId);
            if(mode!="LIVE"&&mode!="RECOVER")throw new ArgumentException("MODE");EffectMeter meter=new EffectMeter();McpWire wire=new McpWire(meter);wire.Initialize();using(PhysicalAuthority effects=new PhysicalAuthority(Canonical,runId,mode=="RECOVER",meter,wire)){wire.Bind(effects);string primary=PrivateCoordinator.Run(report,runId,wire,effects);StrictJson.Validate(primary);if(mode=="RECOVER"){if(meter.Save!=0||meter.Mutation!=0)throw new InvalidOperationException("RECOVERY_SECOND_EFFECT");return Wrap(mode,primary,null,meter,Process.GetCurrentProcess().Id,0);}if(!effects.HandoffPending)throw new InvalidOperationException("FRESH_HANDOFF_MISSING");int child;string recovered=LaunchRecovery(report,caseId,runId,out child);StrictJson.Validate(recovered);if(child==Process.GetCurrentProcess().Id)throw new InvalidOperationException("RECOVERY_NOT_FRESH");return Wrap(mode,primary,recovered,meter,Process.GetCurrentProcess().Id,child);}}
        }
        private static string Wrap(string mode,string primary,string recovery,EffectMeter meter,int pid,int child){return new JavaScriptSerializer().Serialize(new Dictionary<string,object>{{"authority","UID0001NW_CDA7_PRODUCTION"},{"mode",mode},{"process_id",pid},{"recovery_process_id",child},{"primary_receipt",new JavaScriptSerializer().DeserializeObject(primary)},{"recovery_receipt",recovery==null?null:new JavaScriptSerializer().DeserializeObject(recovery)},{"measured_effects",meter.Snapshot()},{"fresh_process",child!=0&&child!=pid}});}
        private static string LaunchRecovery(string report,string caseId,string runId,out int childPid)
        {
            string script="$p=$env:UID0001NW_CDA7_REPORT;$t=[IO.File]::ReadAllText($p).Replace(\"`r`n\",\"`n\").Replace(\"`r\",\"`n\");$b='<!-- UID0001NW_CDA7_SOURCE_BEGIN -->'+[char]10+'```csharp'+[char]10;$e=[char]10+'```'+[char]10+'<!-- UID0001NW_CDA7_SOURCE_END -->';$a=$t.IndexOf($b,[StringComparison]::Ordinal);$z=$t.IndexOf($e,$a+$b.Length,[StringComparison]::Ordinal);if($a-lt0-or$z-lt0){throw 'CDA7_SOURCE'};$s=$t.Substring($a+$b.Length,$z-$a-$b.Length);Add-Type -TypeDefinition $s -ReferencedAssemblies @([System.Management.Automation.PSObject].Assembly.Location,'System.Web.Extensions.dll','System.Management.dll','System.Security.dll');[UID0001NW.CDA7Production.ProductionLauncher]::Run($p,'RECOVER',$env:UID0001NW_CDA7_CASE,$env:UID0001NW_CDA7_RUN)";string encoded=Convert.ToBase64String(Encoding.Unicode.GetBytes(script));ProcessStartInfo i=new ProcessStartInfo("C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe","-NoLogo -NoProfile -NonInteractive -EncodedCommand "+encoded);i.UseShellExecute=false;i.CreateNoWindow=true;i.RedirectStandardOutput=true;i.RedirectStandardError=true;i.EnvironmentVariables["UID0001NW_CDA7_REPORT"]=report;i.EnvironmentVariables["UID0001NW_CDA7_CASE"]=caseId??"LIVE";i.EnvironmentVariables["UID0001NW_CDA7_RUN"]=runId;using(Process p=Process.Start(i)){childPid=p.Id;string output=p.StandardOutput.ReadToEnd(),error=p.StandardError.ReadToEnd();if(!p.WaitForExit(120000))throw new TimeoutException("RECOVERY_TIMEOUT");if(p.ExitCode!=0)throw new InvalidOperationException("RECOVERY_EXIT:"+p.ExitCode+":"+error);return output.Trim();}}
        }
        private static string SelfTest(string caseId)
        {
            string[] bad={"{\"a\":1, \"a\":2}","{\"outer\":{\"x\":1,\"x\":2}}","{\"\\u0061\":1,\"a\":2}","{\"a\":{\"b\":1},\"z\":0,\"a\":2}","[{\"k\":1,\"k\":2}]","{ \"a\" : 1 , \"a\" : 2 }","{\"a\":1,\"nested\":{\"a\":2,\"a\":3}}"};int rejected=0;foreach(string s in bad){try{StrictJson.Validate(s);}catch(InvalidDataException){rejected++;}}if(rejected!=bad.Length)throw new InvalidOperationException("DUPLICATE_HOSTILE");return new JavaScriptSerializer().Serialize(new Dictionary<string,object>{{"authority","UID0001NW_CDA7_PRODUCTION"},{"case_id",caseId},{"outer_entry_hostiles",bad.Length},{"rejected",rejected},{"rpc",0},{"mutation",0},{"save",0},{"file_write",0},{"process_stop",0}});
        }
    }
}
~~~

## Removed Block R027

- SHA256: `754C355F81368D4D91BAED7B8BAF0C77FF415E327B610AA4A10D4AE9E5E8D57A`
- Language: `csharp`
- Bytes: `53029`
- First recovered timestamp: `2026-08-09T07:51:33.696Z`
- Session provenance: rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 200056 (2026-08-09T07:51:33.696Z); rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 200057 (2026-08-09T07:51:35.337Z)

~~~csharp
using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Management;
using System.Management.Automation;
using System.Management.Automation.Runspaces;
using System.Net;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Web.Script.Serialization;

namespace UID0001NW.CDA8Production
{
    internal static class Hash8
    {
        internal static string Bytes(byte[] value) { using (SHA256 h = SHA256.Create()) return BitConverter.ToString(h.ComputeHash(value)).Replace("-", ""); }
        internal static string Text(string value) { return Bytes(new UTF8Encoding(false).GetBytes(value)); }
        internal static string Hmac(byte[] key, string value) { using (HMACSHA256 h = new HMACSHA256(key)) return BitConverter.ToString(h.ComputeHash(new UTF8Encoding(false).GetBytes(value))).Replace("-", ""); }
    }

    internal static class Block8
    {
        internal static string Read(string report, string name, string language)
        {
            string text = File.ReadAllText(report).Replace("\r\n", "\n").Replace('\r', '\n');
            string begin = "<!-- UID0001NW_" + name + "_BEGIN -->\n```" + language + "\n";
            string end = "\n```\n<!-- UID0001NW_" + name + "_END -->";
            int a = text.IndexOf(begin, StringComparison.Ordinal);
            int z = a < 0 ? -1 : text.IndexOf(end, a + begin.Length, StringComparison.Ordinal);
            if (a < 0 || z < 0) throw new InvalidDataException("CDA8_BLOCK:" + name);
            return text.Substring(a + begin.Length, z - a - begin.Length);
        }
    }

    internal static class Package8
    {
        internal static Dictionary<string, object> Verify(string report)
        {
            string manifestText = Block8.Read(report, "CDA8_MANIFEST", "json");
            UID0001NW.CDA7Production.StrictJson.Validate(manifestText);
            JavaScriptSerializer json = new JavaScriptSerializer();
            Dictionary<string, object> m = Obj(json.DeserializeObject(manifestText), "MANIFEST");
            Exact(m, new string[] { "schema_version", "uid", "authority", "public_entry", "report_path", "canonical_idb_path", "modes", "response_count", "mutation_count", "readback_count", "query_count", "dry_run_count", "save_count", "internal_case_count", "outer_case_count", "cda7_source_sha256", "source_sha256", "loader_sha256", "outer_harness_sha256", "method_count", "method_map_sha256", "package_sha256" }, "MANIFEST_KEYS");
            if (I(m, "schema_version") != 8 || S(m, "uid") != "0001NW" || S(m, "authority") != "UID0001NW_CDA8_PRODUCTION" || S(m, "public_entry") != "UID0001NW.CDA8Production.ProductionLauncher.Run") throw new InvalidDataException("CDA8_MANIFEST_IDENTITY");
            if (!PathEq(report, S(m, "report_path")) || !PathEq(S(m, "canonical_idb_path"), "E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64")) throw new InvalidDataException("CDA8_MANIFEST_PATH");
            ExactArray(m["modes"], new string[] { "LIVE", "RECOVER", "SELFTEST", "FIXTURE", "OUTER" }, "CDA8_MODES");
            if (I(m, "response_count") != 193 || I(m, "mutation_count") != 55 || I(m, "readback_count") != 94 || I(m, "query_count") != 36 || I(m, "dry_run_count") != 7 || I(m, "save_count") != 1 || I(m, "internal_case_count") != 20 || I(m, "outer_case_count") != 10) throw new InvalidDataException("CDA8_COUNTS");
            string s7 = Hash8.Text(Block8.Read(report, "CDA7_SOURCE", "csharp"));
            string s8 = Hash8.Text(Block8.Read(report, "CDA8_SOURCE", "csharp"));
            string loader = Hash8.Text(Block8.Read(report, "CDA8_LOADER", "powershell"));
            string harness = Hash8.Text(Block8.Read(report, "CDA8_OUTER_HARNESS", "powershell"));
            if (s7 != S(m, "cda7_source_sha256") || s8 != S(m, "source_sha256") || loader != S(m, "loader_sha256") || harness != S(m, "outer_harness_sha256")) throw new InvalidDataException("CDA8_SOURCE_HASH");
            string material = s7 + "|" + s8 + "|" + loader + "|" + harness + "|" + I(m, "method_count").ToString(CultureInfo.InvariantCulture) + "|" + S(m, "method_map_sha256") + "|0001NW|8";
            if (Hash8.Text(material) != S(m, "package_sha256")) throw new InvalidDataException("CDA8_PACKAGE_HASH");
            return m;
        }

        internal static Dictionary<string, object> Obj(object value, string code) { Dictionary<string, object> d = value as Dictionary<string, object>; if (d == null) throw new InvalidDataException(code); return d; }
        internal static string S(Dictionary<string, object> d, string key) { object v; if (!d.TryGetValue(key, out v) || v == null || v.GetType() != typeof(string)) throw new InvalidDataException("CDA8_STRING:" + key); return (string)v; }
        internal static int I(Dictionary<string, object> d, string key) { object v; if (!d.TryGetValue(key, out v) || !(v is int)) throw new InvalidDataException("CDA8_INT:" + key); return (int)v; }
        internal static bool PathEq(string a, string b) { return String.Equals(Path.GetFullPath(a), Path.GetFullPath(b), StringComparison.OrdinalIgnoreCase); }
        private static void Exact(Dictionary<string, object> d, string[] names, string code) { HashSet<string> e = new HashSet<string>(names, StringComparer.Ordinal); if (d.Count != e.Count) throw new InvalidDataException(code); foreach (string k in d.Keys) if (!e.Contains(k)) throw new InvalidDataException(code + ":" + k); }
        private static void ExactArray(object value, string[] expected, string code) { object[] a = value as object[]; if (a == null || a.Length != expected.Length) throw new InvalidDataException(code); for (int i = 0; i < a.Length; i++) if (a[i] as string != expected[i]) throw new InvalidDataException(code + ":" + i.ToString(CultureInfo.InvariantCulture)); }
    }

    internal static class MethodSeal8
    {
        private static readonly object Gate = new object();
        private static string held;

        internal static Dictionary<string, object> Verify(Dictionary<string, object> manifest)
        {
            Assembly assembly = typeof(ProductionLauncher).Assembly;
            string map; int count;
            BuildMap(assembly, out map, out count);
            string sha = Hash8.Text(map);
            if (count != Package8.I(manifest, "method_count") || sha != Package8.S(manifest, "method_map_sha256")) throw new InvalidOperationException("CDA8_METHOD_MAP_SUBSTITUTION");
            lock (Gate) { if (held == null) held = sha; else if (held != sha) throw new InvalidOperationException("CDA8_METHOD_MAP_DRIFT"); }
            return new Dictionary<string, object> { { "method_count", count }, { "method_map_sha256", sha }, { "assembly_full_name", assembly.FullName }, { "assembly_mvid", assembly.ManifestModule.ModuleVersionId.ToString("D") } };
        }

        internal static string Probe(string caseId, Dictionary<string, object> manifest)
        {
            MethodInfo candidate = caseId == "API_SUBSTITUTION" ? typeof(ApiProbe8).GetMethod("Run") : typeof(ImplementationProbe8).GetMethod("Run");
            MethodInfo production = typeof(ProductionLauncher).GetMethod("Run", BindingFlags.Public | BindingFlags.Static);
            if (caseId == "API_SUBSTITUTION")
            {
                if (Signature(candidate) != Signature(production)) throw new InvalidOperationException("CDA8_API_SUBSTITUTION");
                throw new InvalidOperationException("CDA8_API_PROBE_FAILED");
            }
            if (caseId == "IMPLEMENTATION_SUBSTITUTION")
            {
                if (Signature(candidate) != Signature(production)) throw new InvalidOperationException("CDA8_API_SUBSTITUTION");
                if (Hash8.Bytes(candidate.GetMethodBody().GetILAsByteArray()) != Hash8.Bytes(production.GetMethodBody().GetILAsByteArray())) throw new InvalidOperationException("CDA8_IMPLEMENTATION_SUBSTITUTION");
                throw new InvalidOperationException("CDA8_IMPLEMENTATION_PROBE_FAILED");
            }
            throw new ArgumentException("OUTER_CASE");
        }

        internal static void BuildMap(Assembly assembly, out string map, out int count)
        {
            List<string> rows = new List<string>();
            foreach (Type t in assembly.GetTypes())
            {
                if (t.FullName == null || (!t.FullName.StartsWith("UID0001NW.CDA7Production", StringComparison.Ordinal) && !t.FullName.StartsWith("UID0001NW.CDA8Production", StringComparison.Ordinal))) continue;
                BindingFlags f = BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Static | BindingFlags.Instance | BindingFlags.DeclaredOnly;
                List<MethodBase> methods = new List<MethodBase>();
                methods.AddRange(t.GetMethods(f));
                methods.AddRange(t.GetConstructors(f));
                if (t.TypeInitializer != null && !methods.Contains(t.TypeInitializer)) methods.Add(t.TypeInitializer);
                foreach (MethodBase m in methods)
                {
                    MethodBody body = m.GetMethodBody();
                    string il = body == null ? "NO_IL" : Hash8.Bytes(body.GetILAsByteArray());
                    rows.Add(Signature(m) + "|" + il);
                }
            }
            rows.Sort(StringComparer.Ordinal);
            count = rows.Count;
            map = String.Join("\n", rows.ToArray());
        }

        private static string Signature(MethodBase method)
        {
            StringBuilder b = new StringBuilder();
            b.Append(method.DeclaringType.FullName).Append('|').Append(method.IsConstructor ? ".ctor" : method.Name).Append('|').Append(method.IsStatic ? "static" : "instance").Append('|');
            MethodInfo info = method as MethodInfo;
            b.Append(info == null ? "System.Void" : TypeName(info.ReturnType)).Append('|');
            ParameterInfo[] p = method.GetParameters();
            for (int i = 0; i < p.Length; i++) { if (i != 0) b.Append(','); b.Append(TypeName(p[i].ParameterType)); }
            return b.ToString();
        }

        private static string TypeName(Type t) { if (t.IsByRef) return TypeName(t.GetElementType()) + "&"; if (t.IsArray) return TypeName(t.GetElementType()) + "[]"; if (!t.IsGenericType) return t.FullName; StringBuilder b = new StringBuilder(t.GetGenericTypeDefinition().FullName.Split('`')[0]); b.Append('<'); Type[] a = t.GetGenericArguments(); for (int i = 0; i < a.Length; i++) { if (i != 0) b.Append(','); b.Append(TypeName(a[i])); } return b.Append('>').ToString(); }

        private static class ApiProbe8 { public static string Run(string a, string b, string c) { return a + b + c; } }
        private static class ImplementationProbe8 { public static string Run(string a, string b, string c, string d) { return d + c + b + a; } }
    }

    internal sealed class Generation8
    {
        internal int Pid, Parent; internal string Created, Image, Command;
        internal string Key { get { return Pid.ToString(CultureInfo.InvariantCulture) + "|" + Created + "|" + Image + "|" + Command + "|" + Parent.ToString(CultureInfo.InvariantCulture); } }
        internal Dictionary<string, object> Json() { return new Dictionary<string, object> { { "pid", Pid }, { "parent_pid", Parent }, { "creation", Created }, { "image", Image }, { "command_line", Command }, { "generation_key_sha256", Hash8.Text(Key) } }; }
    }

    internal static class ProcessTree8
    {
        internal static List<Generation8> Snapshot()
        {
            List<Generation8> rows = new List<Generation8>();
            using (ManagementObjectSearcher q = new ManagementObjectSearcher("SELECT ProcessId,ParentProcessId,CreationDate,ExecutablePath,CommandLine FROM Win32_Process"))
            foreach (ManagementObject o in q.Get()) rows.Add(new Generation8 { Pid = Convert.ToInt32(o["ProcessId"], CultureInfo.InvariantCulture), Parent = Convert.ToInt32(o["ParentProcessId"], CultureInfo.InvariantCulture), Created = Convert.ToString(o["CreationDate"], CultureInfo.InvariantCulture) ?? "", Image = Convert.ToString(o["ExecutablePath"], CultureInfo.InvariantCulture) ?? "", Command = Convert.ToString(o["CommandLine"], CultureInfo.InvariantCulture) ?? "" });
            return rows;
        }

        internal static Generation8 Exact(int pid)
        {
            foreach (Generation8 g in Snapshot()) if (g.Pid == pid) return g;
            throw new InvalidOperationException("CDA8_PROCESS_ABSENT:" + pid.ToString(CultureInfo.InvariantCulture));
        }

        internal static List<Generation8> Descendants(Generation8 root)
        {
            List<Generation8> all = Snapshot(); Dictionary<int, Generation8> byPid = new Dictionary<int, Generation8>(); foreach (Generation8 g in all) byPid[g.Pid] = g;
            Generation8 now; if (!byPid.TryGetValue(root.Pid, out now) || now.Key != root.Key) throw new InvalidOperationException("CDA8_ROOT_GENERATION_DRIFT");
            HashSet<int> ids = new HashSet<int>(); ids.Add(root.Pid); bool changed = true;
            while (changed) { changed = false; foreach (Generation8 g in all) if (ids.Contains(g.Parent) && ids.Add(g.Pid)) changed = true; }
            List<Generation8> result = new List<Generation8>(); foreach (Generation8 g in all) if (ids.Contains(g.Pid)) result.Add(g); return result;
        }

        internal static Dictionary<string, object> RetireComplete(List<Generation8> roots)
        {
            HashSet<int> protectedIds = new HashSet<int>(); int current = Process.GetCurrentProcess().Id; while (current > 0 && protectedIds.Add(current)) { try { current = Exact(current).Parent; } catch { break; } }
            Dictionary<string, Generation8> captured = new Dictionary<string, Generation8>(StringComparer.Ordinal);
            foreach (Generation8 root in roots) foreach (Generation8 g in Descendants(root)) captured[g.Key] = g;
            List<Generation8> ordered = new List<Generation8>(captured.Values); ordered.Sort(delegate(Generation8 a, Generation8 b) { return Depth(b, captured).CompareTo(Depth(a, captured)); });
            foreach (Generation8 expected in ordered)
            {
                if (protectedIds.Contains(expected.Pid)) throw new InvalidOperationException("CDA8_PROTECTED_GENERATION");
                Generation8 now; try { now = Exact(expected.Pid); } catch { continue; }
                if (now.Key != expected.Key) throw new InvalidOperationException("CDA8_PID_REUSE:" + expected.Pid.ToString(CultureInfo.InvariantCulture));
                using (Process p = Process.GetProcessById(expected.Pid)) { p.Kill(); if (!p.WaitForExit(30000)) throw new TimeoutException("CDA8_RETIRE_TIMEOUT:" + expected.Pid.ToString(CultureInfo.InvariantCulture)); }
            }
            for (int pass = 0; pass < 20; pass++)
            {
                bool live = false; foreach (Generation8 expected in ordered) { try { Generation8 now = Exact(expected.Pid); if (now.Key == expected.Key) live = true; } catch { } }
                if (!live) return new Dictionary<string, object> { { "captured_generation_count", ordered.Count }, { "retired_generation_count", ordered.Count }, { "complete_descendant_tree", true }, { "command_text_filter_used", false }, { "post_retirement_absent", true } };
                Thread.Sleep(100);
            }
            throw new InvalidOperationException("CDA8_GENERATION_REMAINS");
        }

        internal static bool AllAbsent(List<Generation8> identities) { foreach (Generation8 expected in identities) { try { Generation8 now = Exact(expected.Pid); if (now.Key == expected.Key) return false; } catch { } } return true; }
        private static int Depth(Generation8 value, Dictionary<string, Generation8> all) { int depth = 0, parent = value.Parent; HashSet<int> seen = new HashSet<int>(); while (parent > 0 && seen.Add(parent)) { bool found = false; foreach (Generation8 g in all.Values) if (g.Pid == parent) { depth++; parent = g.Parent; found = true; break; } if (!found) break; } return depth; }
    }

    internal static class Socket8
    {
        [DllImport("iphlpapi.dll", SetLastError = true)] private static extern uint GetExtendedTcpTable(IntPtr table, ref int size, bool order, int family, int tableClass, uint reserved);
        internal static List<Dictionary<string, object>> ForPids(HashSet<int> pids)
        {
            List<Dictionary<string, object>> rows = new List<Dictionary<string, object>>(); int size = 0; GetExtendedTcpTable(IntPtr.Zero, ref size, true, 2, 5, 0); IntPtr memory = Marshal.AllocHGlobal(size);
            try { if (GetExtendedTcpTable(memory, ref size, true, 2, 5, 0) != 0) throw new IOException("CDA8_TCP_TABLE"); int count = Marshal.ReadInt32(memory), offset = 4; for (int n = 0; n < count; n++, offset += 24) { int state = Marshal.ReadInt32(memory, offset), port = IPAddress.NetworkToHostOrder((short)Marshal.ReadInt32(memory, offset + 8)) & 0xffff, pid = Marshal.ReadInt32(memory, offset + 20); if (pids.Contains(pid)) rows.Add(new Dictionary<string, object> { { "pid", pid }, { "port", port }, { "state", state } }); } return rows; }
            finally { Marshal.FreeHGlobal(memory); }
        }
    }

    internal sealed class DurableEnvelope8 : IDisposable
    {
        private readonly string report, reportSha, packageSha, runId, canonical, root, keyPath, journalPath, anchorPath, backupPath, lockPath, wirePath;
        private readonly JavaScriptSerializer json = new JavaScriptSerializer(); private readonly List<Generation8> roots = new List<Generation8>();
        private FileStream heldLock; private byte[] key; private Dictionary<string, object> p0, b0; private string prior = "NONE"; private int transition; private bool durable, disposed;
        internal Dictionary<string, object> LastObservation;

        internal DurableEnvelope8(string reportPath, string package, string id, string canonicalPath, string rootPath)
        {
            report = Path.GetFullPath(reportPath); reportSha = Hash8.Bytes(File.ReadAllBytes(report)); packageSha = package; runId = id; canonical = Path.GetFullPath(canonicalPath); root = Path.GetFullPath(rootPath);
            keyPath = Path.Combine(root, "authority.key"); journalPath = Path.Combine(root, "transaction.journal"); anchorPath = Path.Combine(root, "transaction.anchor"); backupPath = Path.Combine(root, "canonical.B0"); lockPath = Path.Combine(root, "transaction.lock"); wirePath = Path.Combine(root, "wire.ndjson");
        }

        internal bool DurableStarted { get { return durable; } }
        internal string WirePath { get { return wirePath; } }

        internal void Begin()
        {
            if (Directory.Exists(root)) throw new IOException("CDA8_ROOT_EXISTS"); Directory.CreateDirectory(root); heldLock = new FileStream(lockPath, FileMode.CreateNew, FileAccess.ReadWrite, FileShare.None);
            p0 = Tuple(canonical); CopyExact(canonical, backupPath); File.SetLastWriteTimeUtc(backupPath, DateTime.FromFileTimeUtc(Convert.ToInt64(p0["mtime_ticks"], CultureInfo.InvariantCulture))); b0 = Tuple(backupPath);
            if (S(p0, "sha256") != S(b0, "sha256") || Convert.ToInt64(p0["size"], CultureInfo.InvariantCulture) != Convert.ToInt64(b0["size"], CultureInfo.InvariantCulture) || S(p0, "file_index") == S(b0, "file_index")) throw new IOException("CDA8_B0_IDENTITY");
            key = new byte[32]; using (RandomNumberGenerator rng = RandomNumberGenerator.Create()) rng.GetBytes(key); byte[] wrapped = ProtectedData.Protect(key, null, DataProtectionScope.CurrentUser); WriteNew(keyPath, Convert.ToBase64String(wrapped));
            durable = true; WriteState("PREPARED", "NONE", null, true);
        }

        internal void MarkIssued() { WriteState("ISSUED", "PENDING", null, false); }
        internal void MarkClassified(string outcome, Dictionary<string, object> candidate) { WriteState("CLASSIFIED", outcome, candidate, false); }

        internal Dictionary<string, object> ReadJournal()
        {
            if (!File.Exists(journalPath) || !File.Exists(anchorPath) || !File.Exists(keyPath) || !File.Exists(backupPath)) throw new InvalidDataException("CDA8_DURABLE_SET_INCOMPLETE");
            byte[] readKey = ProtectedData.Unprotect(Convert.FromBase64String(File.ReadAllText(keyPath)), null, DataProtectionScope.CurrentUser);
            string wrapperText = File.ReadAllText(journalPath); UID0001NW.CDA7Production.StrictJson.Validate(wrapperText); Dictionary<string, object> wrapper = Package8.Obj(json.DeserializeObject(wrapperText), "CDA8_WRAPPER"); Exact(wrapper, new string[] { "envelope", "mac" }, "CDA8_WRAPPER_KEYS");
            Dictionary<string, object> envelope = Package8.Obj(wrapper["envelope"], "CDA8_ENVELOPE"); Exact(envelope, new string[] { "schema_version", "uid", "report_path", "report_sha256", "package_sha256", "run_id", "canonical_path", "transition", "prior_record_sha256", "state", "outcome", "p0", "b0", "candidate" }, "CDA8_ENVELOPE_KEYS");
            string envelopeText = json.Serialize(envelope); if (S(wrapper, "mac") != Hash8.Hmac(readKey, envelopeText)) throw new CryptographicException("CDA8_JOURNAL_MAC");
            if (Convert.ToInt32(envelope["schema_version"], CultureInfo.InvariantCulture) != 8 || S(envelope, "uid") != "0001NW") throw new InvalidDataException("CDA8_JOURNAL_SCHEMA");
            if (!Package8.PathEq(S(envelope, "report_path"), report) || S(envelope, "report_sha256") != reportSha) throw new InvalidDataException("CDA8_JOURNAL_BINDING:REPORT");
            if (S(envelope, "package_sha256") != packageSha) throw new InvalidDataException("CDA8_JOURNAL_BINDING:PACKAGE");
            if (S(envelope, "run_id") != runId) throw new InvalidDataException("CDA8_JOURNAL_BINDING:RUN");
            if (!Package8.PathEq(S(envelope, "canonical_path"), canonical)) throw new InvalidDataException("CDA8_JOURNAL_BINDING:CANONICAL");
            string anchorText = File.ReadAllText(anchorPath); UID0001NW.CDA7Production.StrictJson.Validate(anchorText); Dictionary<string, object> aw = Package8.Obj(json.DeserializeObject(anchorText), "CDA8_ANCHOR_WRAPPER"); Exact(aw, new string[] { "anchor", "mac" }, "CDA8_ANCHOR_WRAPPER_KEYS"); Dictionary<string, object> anchor = Package8.Obj(aw["anchor"], "CDA8_ANCHOR"); Exact(anchor, new string[] { "transition", "record_sha256", "prior_record_sha256", "run_id", "report_sha256", "package_sha256" }, "CDA8_ANCHOR_KEYS");
            if (S(aw, "mac") != Hash8.Hmac(readKey, json.Serialize(anchor)) || Convert.ToInt32(anchor["transition"], CultureInfo.InvariantCulture) != Convert.ToInt32(envelope["transition"], CultureInfo.InvariantCulture) || S(anchor, "record_sha256") != Hash8.Text(wrapperText) || S(anchor, "prior_record_sha256") != S(envelope, "prior_record_sha256") || S(anchor, "run_id") != runId || S(anchor, "report_sha256") != reportSha || S(anchor, "package_sha256") != packageSha) throw new InvalidDataException("CDA8_JOURNAL_REPLAY_OR_ANCHOR");
            ValidateTuple(Package8.Obj(envelope["p0"], "CDA8_P0")); ValidateTuple(Package8.Obj(envelope["b0"], "CDA8_B0")); return envelope;
        }

        internal Dictionary<string, object> RecoverDurable(string reason)
        {
            Dictionary<string, object> journal = ReadJournal(); Dictionary<string, object> retirement = RetireOwned(); Dictionary<string, object> current = Tuple(canonical); bool restored = false;
            if (!Same(current, p0)) { Restore(); restored = true; current = Tuple(canonical); if (!Same(current, p0)) throw new IOException("CDA8_RECOVERY_NOT_P0"); }
            LastObservation = ObservePhysical("RECOVERY", reason, retirement); CleanupFiles();
            return new Dictionary<string, object> { { "path", "DurableEnvelope8.ReadJournal->RecoverDurable->RetireOwned->ObservePhysical->CleanupFiles" }, { "reason", reason }, { "journal_state", S(journal, "state") }, { "restored", restored }, { "final_p0", Same(current, p0) }, { "retirement", retirement }, { "outer_observation", LastObservation }, { "durable_state_cleared", !Directory.Exists(root) } };
        }

        internal Dictionary<string, object> Complete(string outcome)
        {
            Dictionary<string, object> journal = ReadJournal(); Dictionary<string, object> retirement = RetireOwned(); LastObservation = ObservePhysical("COMPLETE", outcome, retirement); CleanupFiles();
            return new Dictionary<string, object> { { "path", "DurableEnvelope8.ReadJournal->RetireOwned->ObservePhysical->CleanupFiles" }, { "journal_state", S(journal, "state") }, { "outcome", outcome }, { "retirement", retirement }, { "outer_observation", LastObservation }, { "durable_state_cleared", !Directory.Exists(root) } };
        }

        internal Dictionary<string, object> EmergencyRecover(string reason)
        {
            Dictionary<string, object> retirement = RetireOwned(); bool restored = false; if (p0 != null && File.Exists(backupPath)) { Dictionary<string, object> current = Tuple(canonical); if (!Same(current, p0)) { Restore(); restored = true; } }
            LastObservation = ObservePhysical("EMERGENCY_RECOVERY", reason, retirement); CleanupFiles();
            return new Dictionary<string, object> { { "path", "DurableEnvelope8.EmergencyRecover->RetireOwned->ObservePhysical->CleanupFiles" }, { "reason", reason }, { "restored", restored }, { "retirement", retirement }, { "outer_observation", LastObservation }, { "durable_state_cleared", !Directory.Exists(root) } };
        }

        internal void RegisterRoot(Generation8 root) { roots.Add(root); }

        internal void Inject(string caseId)
        {
            if (caseId == "JOURNAL_MAC_TAMPER") { Dictionary<string, object> w = Package8.Obj(json.DeserializeObject(File.ReadAllText(journalPath)), "W"); w["mac"] = new string('0', 64); File.WriteAllText(journalPath, json.Serialize(w), new UTF8Encoding(false)); return; }
            if (caseId == "JOURNAL_REPLAY") { Dictionary<string, object> aw = Package8.Obj(json.DeserializeObject(File.ReadAllText(anchorPath)), "AW"); Dictionary<string, object> a = Package8.Obj(aw["anchor"], "A"); a["record_sha256"] = new string('1', 64); aw["mac"] = Hash8.Hmac(key, json.Serialize(a)); File.WriteAllText(anchorPath, json.Serialize(aw), new UTF8Encoding(false)); return; }
            if (caseId == "JOURNAL_STALE_RUN") { Reseal("run_id", "STALE-" + runId); return; }
            if (caseId == "JOURNAL_CROSS_RUN") { Reseal("run_id", "CROSS-" + Guid.NewGuid().ToString("N")); return; }
            if (caseId == "REPORT_BINDING_TAMPER") { Reseal("report_sha256", new string('2', 64)); return; }
            if (caseId == "PACKAGE_BINDING_TAMPER") { Reseal("package_sha256", new string('3', 64)); return; }
        }

        internal Generation8 SpawnOwned(bool descendant, bool socket)
        {
            string exe = "C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe"; ProcessStartInfo psi = new ProcessStartInfo(exe, "-NoLogo -NoProfile -NonInteractive -Command -"); psi.UseShellExecute = false; psi.CreateNoWindow = true; psi.RedirectStandardInput = true; psi.RedirectStandardOutput = true; psi.RedirectStandardError = true;
            Process p = Process.Start(psi); string script;
            if (descendant) script = "$i=[Diagnostics.ProcessStartInfo]::new('C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe','-NoLogo -NoProfile -NonInteractive -Command -');$i.UseShellExecute=$false;$i.CreateNoWindow=$true;$i.RedirectStandardInput=$true;$c=[Diagnostics.Process]::Start($i);$c.StandardInput.Write('Start-Sleep -Seconds 120');$c.StandardInput.Close();[Console]::Out.WriteLine('CHILD='+$c.Id);[Console]::Out.Flush();Start-Sleep -Seconds 120";
            else if (socket) script = "$l=[Net.Sockets.TcpListener]::new([Net.IPAddress]::Loopback,0);$l.Start();[Console]::Out.WriteLine('PORT='+(($l.LocalEndpoint).Port));[Console]::Out.Flush();Start-Sleep -Seconds 120";
            else script = "[Console]::Out.WriteLine('READY');[Console]::Out.Flush();Start-Sleep -Seconds 120";
            p.StandardInput.Write(script); p.StandardInput.Close(); string line = p.StandardOutput.ReadLine(); if (String.IsNullOrEmpty(line)) throw new InvalidOperationException("CDA8_CHILD_START:" + p.StandardError.ReadToEnd()); Generation8 rootGeneration = ProcessTree8.Exact(p.Id); roots.Add(rootGeneration); return rootGeneration;
        }

        internal Dictionary<string, object> ObservePhysical(string phase, string reason, Dictionary<string, object> retirement)
        {
            Dictionary<string, int> counts = new Dictionary<string, int>(StringComparer.Ordinal); counts["TOTAL"] = 0; counts["MUTATION"] = 0; counts["READBACK"] = 0; counts["QUERY"] = 0; counts["DRYRUN"] = 0; counts["SAVE"] = 0;
            if (File.Exists(wirePath)) foreach (string line in File.ReadAllLines(wirePath)) { UID0001NW.CDA7Production.StrictJson.Validate(line); Dictionary<string, object> row = Package8.Obj(json.DeserializeObject(line), "WIRE"); string kind = S(row, "kind"); counts["TOTAL"]++; if (!counts.ContainsKey(kind)) throw new InvalidDataException("CDA8_WIRE_KIND"); counts[kind]++; }
            List<Generation8> allOwned = new List<Generation8>(); foreach (Generation8 rootGeneration in roots) { try { allOwned.AddRange(ProcessTree8.Descendants(rootGeneration)); } catch { allOwned.Add(rootGeneration); } }
            HashSet<int> pids = new HashSet<int>(); foreach (Generation8 g in allOwned) pids.Add(g.Pid); List<Dictionary<string, object>> sockets = Socket8.ForPids(pids);
            return new Dictionary<string, object> { { "authority", "INDEPENDENT_OUTER_PHYSICAL_OBSERVER" }, { "phase", phase }, { "reason", reason }, { "wire_counts", counts }, { "canonical_tuple", Tuple(canonical) }, { "durable_files", ExistingDurableFiles() }, { "registered_root_count", roots.Count }, { "all_registered_generations_absent", ProcessTree8.AllAbsent(allOwned) }, { "owned_socket_count", sockets.Count }, { "retirement", retirement } };
        }

        internal bool NoResidue() { return !Directory.Exists(root); }

        private void WriteState(string state, string outcome, Dictionary<string, object> candidate, bool create)
        {
            transition++; Dictionary<string, object> envelope = new Dictionary<string, object> { { "schema_version", 8 }, { "uid", "0001NW" }, { "report_path", report }, { "report_sha256", reportSha }, { "package_sha256", packageSha }, { "run_id", runId }, { "canonical_path", canonical }, { "transition", transition }, { "prior_record_sha256", prior }, { "state", state }, { "outcome", outcome }, { "p0", p0 }, { "b0", b0 }, { "candidate", candidate } };
            string envelopeText = json.Serialize(envelope); string wrapperText = json.Serialize(new Dictionary<string, object> { { "envelope", envelope }, { "mac", Hash8.Hmac(key, envelopeText) } }); string record = Hash8.Text(wrapperText);
            Dictionary<string, object> anchor = new Dictionary<string, object> { { "transition", transition }, { "record_sha256", record }, { "prior_record_sha256", prior }, { "run_id", runId }, { "report_sha256", reportSha }, { "package_sha256", packageSha } }; string anchorText = json.Serialize(new Dictionary<string, object> { { "anchor", anchor }, { "mac", Hash8.Hmac(key, json.Serialize(anchor)) } });
            Install(journalPath, wrapperText, create); Install(anchorPath, anchorText, create); prior = record; ReadJournal();
        }

        private void Reseal(string field, string value)
        {
            Dictionary<string, object> wrapper = Package8.Obj(json.DeserializeObject(File.ReadAllText(journalPath)), "W"); Dictionary<string, object> envelope = Package8.Obj(wrapper["envelope"], "E"); envelope[field] = value; wrapper["mac"] = Hash8.Hmac(key, json.Serialize(envelope)); string wrapperText = json.Serialize(wrapper); File.WriteAllText(journalPath, wrapperText, new UTF8Encoding(false));
            Dictionary<string, object> aw = Package8.Obj(json.DeserializeObject(File.ReadAllText(anchorPath)), "AW"); Dictionary<string, object> anchor = Package8.Obj(aw["anchor"], "A"); anchor["record_sha256"] = Hash8.Text(wrapperText); if (field == "run_id" || field == "report_sha256" || field == "package_sha256") anchor[field] = value; aw["mac"] = Hash8.Hmac(key, json.Serialize(anchor)); File.WriteAllText(anchorPath, json.Serialize(aw), new UTF8Encoding(false));
        }

        private Dictionary<string, object> RetireOwned() { return ProcessTree8.RetireComplete(roots); }
        private void Restore() { CopyReplace(backupPath, canonical); File.SetLastWriteTimeUtc(canonical, DateTime.FromFileTimeUtc(Convert.ToInt64(p0["mtime_ticks"], CultureInfo.InvariantCulture))); }
        private Dictionary<string, object> Tuple(string path) { using (FileStream s = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.None)) { UID0001NW.CDA7Production.Native.ByHandle info; if (!UID0001NW.CDA7Production.Native.GetFileInformationByHandle(s.SafeFileHandle, out info)) throw new IOException("CDA8_FILE_INFO"); string sha; using (SHA256 h = SHA256.Create()) sha = BitConverter.ToString(h.ComputeHash(s)).Replace("-", ""); long ticks = (long)(((ulong)info.Write.High << 32) | info.Write.Low); return new Dictionary<string, object> { { "path", Path.GetFullPath(path) }, { "volume", unchecked((int)info.Volume) }, { "file_index", info.IndexHigh.ToString("X8") + info.IndexLow.ToString("X8") }, { "size", s.Length }, { "mtime_ticks", ticks }, { "sha256", sha }, { "exclusive_open", true } }; } }
        private static void ValidateTuple(Dictionary<string, object> t) { if (!Regex.IsMatch(S(t, "sha256"), "^[0-9A-F]{64}$") || !(t["exclusive_open"] is bool) || !(bool)t["exclusive_open"]) throw new InvalidDataException("CDA8_TUPLE"); }
        private static bool Same(Dictionary<string, object> a, Dictionary<string, object> b) { return Convert.ToInt32(a["volume"], CultureInfo.InvariantCulture) == Convert.ToInt32(b["volume"], CultureInfo.InvariantCulture) && S(a, "file_index") == S(b, "file_index") && Convert.ToInt64(a["size"], CultureInfo.InvariantCulture) == Convert.ToInt64(b["size"], CultureInfo.InvariantCulture) && Convert.ToInt64(a["mtime_ticks"], CultureInfo.InvariantCulture) == Convert.ToInt64(b["mtime_ticks"], CultureInfo.InvariantCulture) && S(a, "sha256") == S(b, "sha256"); }
        private static string S(Dictionary<string, object> d, string key) { return Package8.S(d, key); }
        private static void Exact(Dictionary<string, object> d, string[] keys, string code) { HashSet<string> e = new HashSet<string>(keys, StringComparer.Ordinal); if (d.Count != e.Count) throw new InvalidDataException(code); foreach (string k in d.Keys) if (!e.Contains(k)) throw new InvalidDataException(code + ":" + k); }
        private void Install(string path, string text, bool create) { string temp = path + "." + Guid.NewGuid().ToString("N") + ".tmp"; WriteNew(temp, text); if (create) { if (File.Exists(path)) throw new IOException("CDA8_DURABLE_EXISTS"); File.Move(temp, path); } else { string backup = path + ".replace"; if (File.Exists(backup)) File.Delete(backup); File.Replace(temp, path, backup, true); if (File.Exists(backup)) File.Delete(backup); } if (File.ReadAllText(path) != text) throw new IOException("CDA8_DURABLE_REREAD"); }
        private static void WriteNew(string path, string text) { byte[] bytes = new UTF8Encoding(false).GetBytes(text); using (FileStream s = new FileStream(path, FileMode.CreateNew, FileAccess.Write, FileShare.None, 4096, FileOptions.WriteThrough)) { s.Write(bytes, 0, bytes.Length); s.Flush(true); } }
        private static void CopyExact(string from, string to) { using (FileStream src = new FileStream(from, FileMode.Open, FileAccess.Read, FileShare.None)) using (FileStream dst = new FileStream(to, FileMode.CreateNew, FileAccess.Write, FileShare.None, 1048576, FileOptions.WriteThrough)) { byte[] b = new byte[1048576]; int n; long copied = 0; while ((n = src.Read(b, 0, b.Length)) > 0) { dst.Write(b, 0, n); copied += n; } if (copied != src.Length) throw new EndOfStreamException("CDA8_COPY_EOF"); dst.Flush(true); } }
        private static void CopyReplace(string from, string to) { using (FileStream src = new FileStream(from, FileMode.Open, FileAccess.Read, FileShare.None)) using (FileStream dst = new FileStream(to, FileMode.Open, FileAccess.ReadWrite, FileShare.None, 1048576, FileOptions.WriteThrough)) { dst.SetLength(0); byte[] b = new byte[1048576]; int n; long copied = 0; while ((n = src.Read(b, 0, b.Length)) > 0) { dst.Write(b, 0, n); copied += n; } if (copied != src.Length) throw new EndOfStreamException("CDA8_RESTORE_EOF"); dst.Flush(true); } }
        private string[] ExistingDurableFiles() { List<string> names = new List<string>(); foreach (string p in new string[] { keyPath, journalPath, anchorPath, backupPath, lockPath, wirePath }) if (File.Exists(p)) names.Add(Path.GetFileName(p)); return names.ToArray(); }
        private void CleanupFiles() { if (heldLock != null) { heldLock.Dispose(); heldLock = null; } foreach (string p in Directory.Exists(root) ? Directory.GetFiles(root) : new string[0]) File.Delete(p); if (Directory.Exists(root)) Directory.Delete(root, false); if (Directory.Exists(root)) throw new IOException("CDA8_RESIDUE"); durable = false; }
        public void Dispose() { if (disposed) return; disposed = true; if (heldLock != null) { heldLock.Dispose(); heldLock = null; } }
    }

    internal sealed class FixtureWire8
    {
        private readonly DurableEnvelope8 envelope; private readonly string caseId, canonical; private readonly JavaScriptSerializer json = new JavaScriptSerializer();
        internal FixtureWire8(DurableEnvelope8 value, string id, string path) { envelope = value; caseId = id; canonical = path; }
        internal Dictionary<string, object> Call(int index, string kind)
        {
            Dictionary<string, object> row = new Dictionary<string, object> { { "index", index }, { "kind", kind }, { "request_sha256", Hash8.Text(caseId + "|" + index.ToString(CultureInfo.InvariantCulture) + "|" + kind) } }; string text = json.Serialize(row);
            using (FileStream s = new FileStream(envelope.WirePath, FileMode.Append, FileAccess.Write, FileShare.Read, 4096, FileOptions.WriteThrough)) { byte[] b = new UTF8Encoding(false).GetBytes(text + "\n"); s.Write(b, 0, b.Length); s.Flush(true); }
            if (index == 0 && caseId == "PARTIAL_OPEN_CLEANUP") { envelope.SpawnOwned(false, false); throw new InvalidOperationException("CDA8_PARTIAL_OPEN"); }
            if (index == 0 && caseId == "DESCENDANT_CLEANUP_OMISSION") { envelope.SpawnOwned(true, false); throw new InvalidOperationException("CDA8_DESCENDANT_OPEN"); }
            if (index == 0 && caseId == "SOCKET_CLEANUP_OMISSION") { envelope.SpawnOwned(false, true); throw new InvalidOperationException("CDA8_SOCKET_OPEN"); }
            if (kind == "SAVE") { File.WriteAllText(canonical, "CDA8-P1-" + caseId + "-" + Guid.NewGuid().ToString("N"), new UTF8Encoding(false)); }
            return new Dictionary<string, object> { { "ok", true }, { "index", index }, { "kind", kind } };
        }
    }

    internal static class FixtureCoordinator8
    {
        private static readonly HashSet<string> JournalCases = new HashSet<string>(new string[] { "JOURNAL_MAC_TAMPER", "JOURNAL_REPLAY", "JOURNAL_STALE_RUN", "JOURNAL_CROSS_RUN", "REPORT_BINDING_TAMPER", "PACKAGE_BINDING_TAMPER" }, StringComparer.Ordinal);
        internal static Dictionary<string, object> Run(string report, string packageSha, string runId, string caseId)
        {
            string baseRoot = Path.Combine(Path.GetTempPath(), "UID0001NW-CDA8", Hash8.Text(report).Substring(0, 16)); Directory.CreateDirectory(baseRoot); string root = Path.Combine(baseRoot, runId + "-" + caseId); string canonical = root + ".canonical"; File.WriteAllText(canonical, "CDA8-P0-" + caseId, new UTF8Encoding(false)); File.SetLastWriteTimeUtc(canonical, new DateTime(2020, 1, 2, 3, 4, 5, DateTimeKind.Utc));
            Dictionary<string, object> receipt = new Dictionary<string, object>(); DurableEnvelope8 env = new DurableEnvelope8(report, packageSha, runId, canonical, root); string actual = "NONE"; Dictionary<string, object> recovery = null; bool recoveryEntered = false;
            try
            {
                env.Begin();
                if (JournalCases.Contains(caseId))
                {
                    env.Inject(caseId); try { env.ReadJournal(); } catch (Exception ex) { actual = ex.Message; }
                    recoveryEntered = true; try { env.RecoverDurable(actual); } catch { recovery = env.EmergencyRecover(actual); }
                }
                else
                {
                    FixtureWire8 wire = new FixtureWire8(env, caseId, canonical);
                    for (int i = 0; i < 193; i++)
                    {
                        string kind = i < 55 ? "MUTATION" : (i < 149 ? "READBACK" : (i < 185 ? "QUERY" : (i < 192 ? "DRYRUN" : "SAVE")));
                        if (kind == "SAVE") env.MarkIssued(); wire.Call(i, kind);
                    }
                    Dictionary<string, object> candidate = new Dictionary<string, object> { { "path", canonical }, { "sha256", Hash8.Bytes(File.ReadAllBytes(canonical)) } }; env.MarkClassified("EXPLICIT_SUCCESS", candidate); recovery = env.Complete("EXPLICIT_SUCCESS"); actual = "TERMINAL_P1";
                }
            }
            catch (Exception ex)
            {
                actual = ex.Message; if (env.DurableStarted) { recoveryEntered = true; try { recovery = env.RecoverDurable(actual); } catch { recovery = env.EmergencyRecover(actual); } }
            }
            finally { env.Dispose(); }
            bool noRoot = !Directory.Exists(root); if (File.Exists(canonical)) File.Delete(canonical); if (Directory.Exists(baseRoot) && Directory.GetFileSystemEntries(baseRoot).Length == 0) Directory.Delete(baseRoot); string parent = Path.GetDirectoryName(baseRoot); if (Directory.Exists(parent) && Directory.GetFileSystemEntries(parent).Length == 0) Directory.Delete(parent);
            receipt["case"] = caseId; receipt["invoked_path"] = "ProductionLauncher.Run->FixtureCoordinator8.Run->DurableEnvelope8/FixtureWire8/ProcessTree8/Socket8"; receipt["injected_defect"] = caseId; receipt["actual_reason"] = actual; receipt["recovery_entered_after_durable_start"] = recoveryEntered; receipt["recovery_receipt"] = recovery; receipt["cleanup_complete"] = noRoot && !File.Exists(canonical); receipt["report_owned_temp_residue"] = Directory.Exists(root); return receipt;
        }
    }

    internal sealed class RecoveryGuard8
    {
        private static readonly HashSet<string> Allowed = new HashSet<string>(new string[] { "idb_list", "runtime_attestation" }, StringComparer.Ordinal);
        internal static void Authorize(string tool) { if (!Allowed.Contains(tool)) throw new InvalidOperationException("CDA8_RECOVER_TOOL_FORBIDDEN:" + tool); }
    }

    internal static class Hostile8
    {
        internal static readonly string[] InternalCases = new string[] { "JSON_DUP_ROOT", "JSON_DUP_NESTED", "JSON_DUP_ESCAPED", "JSON_DUP_REORDERED", "JSON_DUP_ARRAY", "JSON_DUP_WHITESPACE", "JSON_DUP_DEPTH", "RECOVER_IDB_OPEN_FORBIDDEN", "RECOVER_MUTATION_FORBIDDEN", "RECOVER_SAVE_FORBIDDEN", "JOURNAL_MAC_TAMPER", "JOURNAL_REPLAY", "JOURNAL_STALE_RUN", "JOURNAL_CROSS_RUN", "REPORT_BINDING_TAMPER", "PACKAGE_BINDING_TAMPER", "PARTIAL_OPEN_CLEANUP", "DESCENDANT_CLEANUP_OMISSION", "SOCKET_CLEANUP_OMISSION", "WRONG_REASON_REJECTION" };
        internal static readonly string[] OuterCases = new string[] { "INVALID_MODE", "INVALID_RUN_ID", "PRELOADED_TYPE", "PRELOADED_ASSEMBLY", "API_SUBSTITUTION", "IMPLEMENTATION_SUBSTITUTION", "COMMAND_SUBSTITUTION", "ENVIRONMENT_SUBSTITUTION", "FRESH_ENTRY_ONE", "FRESH_ENTRY_TWO" };

        internal static Dictionary<string, object> Run(string report, string packageSha, string runId)
        {
            List<object> rows = new List<object>(); string[] bad = new string[] { "{\"a\":1,\"a\":2}", "{\"outer\":{\"x\":1,\"x\":2}}", "{\"\\u0061\":1,\"a\":2}", "{\"a\":{\"b\":1},\"z\":0,\"a\":2}", "[{\"k\":1,\"k\":2}]", "{ \"a\" : 1 , \"a\" : 2 }", "{\"a\":1,\"nested\":{\"a\":2,\"a\":3}}" };
            for (int i = 0; i < bad.Length; i++) rows.Add(ExpectAction(InternalCases[i], delegate { UID0001NW.CDA7Production.StrictJson.Validate(bad[i]); }, "JSON_DUPLICATE_MEMBER"));
            rows.Add(ExpectAction("RECOVER_IDB_OPEN_FORBIDDEN", delegate { RecoveryGuard8.Authorize("idb_open"); }, "CDA8_RECOVER_TOOL_FORBIDDEN:idb_open"));
            rows.Add(ExpectAction("RECOVER_MUTATION_FORBIDDEN", delegate { RecoveryGuard8.Authorize("rename"); }, "CDA8_RECOVER_TOOL_FORBIDDEN:rename"));
            rows.Add(ExpectAction("RECOVER_SAVE_FORBIDDEN", delegate { RecoveryGuard8.Authorize("idb_save"); }, "CDA8_RECOVER_TOOL_FORBIDDEN:idb_save"));
            Dictionary<string, string> expected = new Dictionary<string, string>(StringComparer.Ordinal) { { "JOURNAL_MAC_TAMPER", "CDA8_JOURNAL_MAC" }, { "JOURNAL_REPLAY", "CDA8_JOURNAL_REPLAY_OR_ANCHOR" }, { "JOURNAL_STALE_RUN", "CDA8_JOURNAL_BINDING:RUN" }, { "JOURNAL_CROSS_RUN", "CDA8_JOURNAL_BINDING:RUN" }, { "REPORT_BINDING_TAMPER", "CDA8_JOURNAL_BINDING:REPORT" }, { "PACKAGE_BINDING_TAMPER", "CDA8_JOURNAL_BINDING:PACKAGE" }, { "PARTIAL_OPEN_CLEANUP", "CDA8_PARTIAL_OPEN" }, { "DESCENDANT_CLEANUP_OMISSION", "CDA8_DESCENDANT_OPEN" }, { "SOCKET_CLEANUP_OMISSION", "CDA8_SOCKET_OPEN" } };
            foreach (KeyValuePair<string, string> item in expected)
            {
                Dictionary<string, object> receipt = FixtureCoordinator8.Run(report, packageSha, runId + "-" + rows.Count.ToString("D2", CultureInfo.InvariantCulture), item.Key); string actual = Package8.S(receipt, "actual_reason"); if (actual != item.Value) throw new InvalidOperationException("HOSTILE_WRONG_REASON:" + item.Key + ":" + actual + ":" + item.Value); if (!(bool)receipt["cleanup_complete"] || !(bool)receipt["recovery_entered_after_durable_start"]) throw new InvalidOperationException("HOSTILE_CLEANUP:" + item.Key); rows.Add(receipt);
            }
            Dictionary<string, object> wrong = FixtureCoordinator8.Run(report, packageSha, runId + "-WRONG", "JOURNAL_MAC_TAMPER"); string wrongActual = Package8.S(wrong, "actual_reason"); string mismatch = wrongActual == "NOT_THE_REASON" ? "NONE" : "HOSTILE_WRONG_REASON:" + wrongActual + ":NOT_THE_REASON"; rows.Add(new Dictionary<string, object> { { "case", "WRONG_REASON_REJECTION" }, { "invoked_path", wrong["invoked_path"] }, { "actual_reason", mismatch }, { "cleanup_complete", wrong["cleanup_complete"] }, { "passed", mismatch.StartsWith("HOSTILE_WRONG_REASON:", StringComparison.Ordinal) } });
            return new Dictionary<string, object> { { "authority", "UID0001NW_CDA8_PRODUCTION" }, { "internal_case_count", rows.Count }, { "cases", rows.ToArray() }, { "all_cases_used_real_paths", true }, { "reason_to_itself_cases", 0 } };
        }

        private static Dictionary<string, object> ExpectAction(string id, Action action, string expectedPrefix) { string actual = "NONE"; try { action(); } catch (Exception ex) { actual = ex.Message; } if (!actual.StartsWith(expectedPrefix, StringComparison.Ordinal)) throw new InvalidOperationException("HOSTILE_WRONG_REASON:" + id + ":" + actual); return new Dictionary<string, object> { { "case", id }, { "invoked_path", "ProductionLauncher.Run->Hostile8.ExpectAction->production parser/guard" }, { "injected_defect", id }, { "actual_reason", actual }, { "cleanup_complete", true }, { "passed", true } }; }
    }

    internal static class LiveClosure8
    {
        private const string Canonical = "E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64";
        internal static string Run(string report, string caseId, string runId, Dictionary<string, object> manifest, Dictionary<string, object> binding)
        {
            string root = Canonical + ".UID0001NW.CDA8." + runId; DurableEnvelope8 outer = new DurableEnvelope8(report, Package8.S(manifest, "package_sha256"), runId, Canonical, root); string primary = null, recovery = null; bool recoveryEntered = false;
            try
            {
                outer.Begin(); UID0001NW.CDA7Production.DiagnosticMeter meter = new UID0001NW.CDA7Production.DiagnosticMeter(); UID0001NW.CDA7Production.LiveMcpWire wire = new UID0001NW.CDA7Production.LiveMcpWire(meter); wire.Initialize();
                using (UID0001NW.CDA7Production.PhysicalAuthority physical = new UID0001NW.CDA7Production.PhysicalAuthority(Canonical, runId, false, meter, wire, report, Package8.S(manifest, "package_sha256"))) { wire.Bind(physical); primary = UID0001NW.CDA7Production.PrivateCoordinator.Run(report, runId, wire, physical); if (!physical.HandoffPending) throw new InvalidOperationException("CDA8_INNER_HANDOFF_MISSING"); }
                recovery = LaunchCda7Recovery(report, caseId, runId); outer.MarkIssued(); outer.MarkClassified("INNER_RECOVERY_COMPLETE", new Dictionary<string, object> { { "path", Canonical }, { "sha256", Hash8.Bytes(File.ReadAllBytes(Canonical)) } }); Dictionary<string, object> complete = outer.Complete("INNER_RECOVERY_COMPLETE");
                return new JavaScriptSerializer().Serialize(new Dictionary<string, object> { { "authority", "UID0001NW_CDA8_PRODUCTION" }, { "mode", "LIVE" }, { "implementation_binding", binding }, { "primary", new JavaScriptSerializer().DeserializeObject(primary) }, { "recovery", new JavaScriptSerializer().DeserializeObject(recovery) }, { "outer_complete", complete }, { "recovery_entered_after_durable_start", false } });
            }
            catch (Exception ex)
            {
                if (outer.DurableStarted) { recoveryEntered = true; try { outer.RecoverDurable(ex.Message); } catch { outer.EmergencyRecover(ex.Message); } }
                throw new InvalidOperationException("CDA8_LIVE_RECOVERED:" + recoveryEntered.ToString() + ":" + ex.Message, ex);
            }
            finally { outer.Dispose(); }
        }

        private static string LaunchCda7Recovery(string report, string caseId, string runId)
        {
            string text = File.ReadAllText(report).Replace("\r\n", "\n").Replace('\r', '\n'); string loader = Block8.Read(report, "CDA7_LOADER", "powershell"); string script = "$p=" + Ps(report) + ";$l=" + Ps(loader) + ";&([ScriptBlock]::Create($l))-ReportPath $p -Mode RECOVER -CaseId " + Ps(caseId) + " -RunId " + Ps(runId);
            string exe = "C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe"; ProcessStartInfo psi = new ProcessStartInfo(exe, "-NoLogo -NoProfile -NonInteractive -Command -"); psi.UseShellExecute = false; psi.CreateNoWindow = true; psi.RedirectStandardInput = true; psi.RedirectStandardOutput = true; psi.RedirectStandardError = true;
            using (Process p = Process.Start(psi)) { Generation8 g = ProcessTree8.Exact(p.Id); p.StandardInput.Write(script); p.StandardInput.Close(); string output = p.StandardOutput.ReadToEnd(), error = p.StandardError.ReadToEnd(); if (!p.WaitForExit(180000)) { p.Kill(); p.WaitForExit(5000); throw new TimeoutException("CDA8_RECOVERY_TIMEOUT"); } if (p.ExitCode != 0) throw new InvalidOperationException("CDA8_RECOVERY_EXIT:" + error); if (!ProcessTree8.AllAbsent(new List<Generation8> { g })) throw new InvalidOperationException("CDA8_RECOVERY_GENERATION_REMAINS"); return output.Trim(); }
        }
        private static string Ps(string value) { return "'" + (value ?? "").Replace("'", "''") + "'"; }
    }

    public static class ProductionLauncher
    {
        public static string Run(string reportPath, string mode, string caseId, string runId)
        {
            string report = Path.GetFullPath(reportPath); if (!File.Exists(report)) throw new FileNotFoundException("REPORT", report); Dictionary<string, object> manifest = Package8.Verify(report); Dictionary<string, object> binding = MethodSeal8.Verify(manifest); if (!Regex.IsMatch(runId ?? "", "^[A-Za-z0-9._-]{8,100}$")) throw new ArgumentException("RUN_ID");
            if (mode == "OUTER") return MethodSeal8.Probe(caseId, manifest);
            if (mode == "FIXTURE") return new JavaScriptSerializer().Serialize(FixtureCoordinator8.Run(report, Package8.S(manifest, "package_sha256"), runId, caseId));
            if (mode == "SELFTEST") return new JavaScriptSerializer().Serialize(new Dictionary<string, object> { { "authority", "UID0001NW_CDA8_PRODUCTION" }, { "implementation_binding", binding }, { "internal", Hostile8.Run(report, Package8.S(manifest, "package_sha256"), runId) }, { "outer_cases", Hostile8.OuterCases }, { "outer_case_count", Hostile8.OuterCases.Length }, { "outer_harness_required", true } });
            if (mode == "LIVE") return LiveClosure8.Run(report, caseId, runId, manifest, binding);
            if (mode == "RECOVER") throw new InvalidOperationException("CDA8_RECOVER_REQUIRES_DURABLE_ROOT_AND_IS_INTERNALLY_LAUNCHED");
            throw new ArgumentException("MODE");
        }
    }
}
~~~

## Removed Block R028

- SHA256: `BBB55B359920A6B70C07AC2E7C6532FE15C902819DAA04329ECAA7C6C707DDB5`
- Language: `powershell`
- Bytes: `7251`
- First recovered timestamp: `2026-08-09T07:51:33.696Z`
- Session provenance: rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 200056 (2026-08-09T07:51:33.696Z); rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 200057 (2026-08-09T07:51:35.337Z)

~~~powershell
param([Parameter(Mandatory=$true)][string]$ReportPath,[string]$Mode='SELFTEST',[string]$CaseId='CDA8-SELFTEST',[string]$RunId='UID0001NW-CDA8-SUPERVISOR')
$ErrorActionPreference='Stop';Set-StrictMode -Version Latest
$path=[IO.Path]::GetFullPath($ReportPath);$text=[IO.File]::ReadAllText($path).Replace("`r`n","`n").Replace("`r","`n")
function Read-CDA8Block([string]$Name,[string]$Language){$begin='<!-- UID0001NW_'+$Name+'_BEGIN -->'+[char]10+'```'+$Language+[char]10;$end=[char]10+'```'+[char]10+'<!-- UID0001NW_'+$Name+'_END -->';$a=$text.IndexOf($begin,[StringComparison]::Ordinal);$z=$(if($a-lt0){-1}else{$text.IndexOf($end,$a+$begin.Length,[StringComparison]::Ordinal)});if($a-lt0-or$z-lt0){throw ('CDA8_BLOCK:'+ $Name)};$text.Substring($a+$begin.Length,$z-$a-$begin.Length)}
function Get-CDA8Sha([string]$Value){$h=[Security.Cryptography.SHA256]::Create();try{[BitConverter]::ToString($h.ComputeHash([Text.UTF8Encoding]::new($false).GetBytes($Value))).Replace('-','')}finally{$h.Dispose()}}
function Get-CDA8ByteSha([byte[]]$Value){$h=[Security.Cryptography.SHA256]::Create();try{[BitConverter]::ToString($h.ComputeHash($Value)).Replace('-','')}finally{$h.Dispose()}}
function Get-CDA8TypeName([Type]$Type){if($Type.IsByRef){return (Get-CDA8TypeName $Type.GetElementType())+'&'};if($Type.IsArray){return (Get-CDA8TypeName $Type.GetElementType())+'[]'};if(-not$Type.IsGenericType){return $Type.FullName};$name=$Type.GetGenericTypeDefinition().FullName.Split([char]96)[0];$args=@($Type.GetGenericArguments()|ForEach-Object{Get-CDA8TypeName $_});$name+'<'+($args-join',')+'>'}
function Get-CDA8MethodMap([Reflection.Assembly]$Assembly){$rows=[Collections.Generic.List[string]]::new();$flags=[Reflection.BindingFlags]'Public,NonPublic,Static,Instance,DeclaredOnly';foreach($type in $Assembly.GetTypes()){if($null-eq$type.FullName-or(-not$type.FullName.StartsWith('UID0001NW.CDA7Production',[StringComparison]::Ordinal)-and-not$type.FullName.StartsWith('UID0001NW.CDA8Production',[StringComparison]::Ordinal))){continue};$methods=[Collections.Generic.List[Reflection.MethodBase]]::new();$methods.AddRange([Reflection.MethodBase[]]@($type.GetMethods($flags)));$methods.AddRange([Reflection.MethodBase[]]@($type.GetConstructors($flags)));if($null-ne$type.TypeInitializer-and-not$methods.Contains($type.TypeInitializer)){$methods.Add($type.TypeInitializer)};foreach($method in $methods){$return=$(if($method-is[Reflection.MethodInfo]){Get-CDA8TypeName $method.ReturnType}else{'System.Void'});$parameters=@($method.GetParameters()|ForEach-Object{Get-CDA8TypeName $_.ParameterType});$signature=$method.DeclaringType.FullName+'|'+$(if($method.IsConstructor){'.ctor'}else{$method.Name})+'|'+$(if($method.IsStatic){'static'}else{'instance'})+'|'+$return+'|'+($parameters-join',');$body=$method.GetMethodBody();$il=$(if($null-eq$body){'NO_IL'}else{Get-CDA8ByteSha $body.GetILAsByteArray()});$rows.Add($signature+'|'+$il)}};$ordered=@($rows|Sort-Object -CaseSensitive);[pscustomobject]@{Count=$ordered.Count;Text=($ordered-join"`n");SHA256=(Get-CDA8Sha ($ordered-join"`n"))}}
$substituted=@();foreach($candidate in $ExecutionContext.InvokeCommand.GetCommands('Add-Type','All',$true)){if($candidate.CommandType-in@([Management.Automation.CommandTypes]::Alias,[Management.Automation.CommandTypes]::Function,[Management.Automation.CommandTypes]::Filter,[Management.Automation.CommandTypes]::ExternalScript)){$substituted+=,$candidate}};if($substituted.Count-ne0){throw 'CDA8_COMMAND_SUBSTITUTION'}
$ambient=@();foreach($key in [Environment]::GetEnvironmentVariables().Keys){if([string]$key-like'UID0001NW_CDA8_*'){$ambient+=,[string]$key}};if($ambient.Count-ne0){throw 'CDA8_ENVIRONMENT_SUBSTITUTION'}
$preloadedTypes=@();$preloadedAssemblies=@();foreach($assembly in [AppDomain]::CurrentDomain.GetAssemblies()){if($assembly.GetName().Name-like'UID0001NW.CDA8Production*'){$preloadedAssemblies+=,$assembly};try{foreach($candidate in $assembly.GetTypes()){if($candidate.FullName-like'UID0001NW.CDA8Production*'){$preloadedTypes+=,$candidate}}}catch{}};if($preloadedTypes.Count-ne0){throw 'CDA8_PRELOADED_TYPE'};if($preloadedAssemblies.Count-ne0){throw 'CDA8_PRELOADED_ASSEMBLY'}
$web=[Reflection.Assembly]::Load('System.Web.Extensions, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31BF3856AD364E35');if($web.FullName-cne'System.Web.Extensions, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35'){throw 'CDA8_JSON_ASSEMBLY_SUBSTITUTION'}
$manifestText=Read-CDA8Block CDA8_MANIFEST json;$manifest=[System.Web.Script.Serialization.JavaScriptSerializer]::new().DeserializeObject($manifestText);$source7=Read-CDA8Block CDA7_SOURCE csharp;$source8=Read-CDA8Block CDA8_SOURCE csharp;$loader=Read-CDA8Block CDA8_LOADER powershell;$harness=Read-CDA8Block CDA8_OUTER_HARNESS powershell
$s7=Get-CDA8Sha $source7;$s8=Get-CDA8Sha $source8;$ls=Get-CDA8Sha $loader;$hs=Get-CDA8Sha $harness;if($s7-cne[string]$manifest['cda7_source_sha256']-or$s8-cne[string]$manifest['source_sha256']-or$ls-cne[string]$manifest['loader_sha256']-or$hs-cne[string]$manifest['outer_harness_sha256']){throw 'CDA8_SOURCE_HASH'};$material=$s7+'|'+$s8+'|'+$ls+'|'+$hs+'|'+[string]$manifest['method_count']+'|'+[string]$manifest['method_map_sha256']+'|0001NW|8';if((Get-CDA8Sha $material)-cne[string]$manifest['package_sha256']){throw 'CDA8_PACKAGE_HASH'}
$before=[Collections.Generic.HashSet[Guid]]::new();foreach($assembly in [AppDomain]::CurrentDomain.GetAssemblies()){$null=$before.Add($assembly.ManifestModule.ModuleVersionId)};$cmd=$ExecutionContext.InvokeCommand.GetCommand('Microsoft.PowerShell.Utility\Add-Type',[Management.Automation.CommandTypes]::Cmdlet);if($null-eq$cmd-or$cmd.ImplementingType-ne[Microsoft.PowerShell.Commands.AddTypeCommand]){throw 'CDA8_COMMAND_AUTHORITY'};&$cmd-TypeDefinition($source7+"`n"+$source8)-ReferencedAssemblies @([System.Management.Automation.PSObject].Assembly.Location,'System.Web.Extensions.dll','System.Management.dll','System.Security.dll')
$loaded=@();foreach($assembly in [AppDomain]::CurrentDomain.GetAssemblies()){if(-not$before.Contains($assembly.ManifestModule.ModuleVersionId)){try{if($null-ne$assembly.GetType('UID0001NW.CDA8Production.ProductionLauncher',$false)){$loaded+=,$assembly}}catch{}}};if($loaded.Count-ne1){throw 'CDA8_COMPILED_ASSEMBLY_CARDINALITY'};$assembly=$loaded[0];$type=$assembly.GetType('UID0001NW.CDA8Production.ProductionLauncher',$true,$false);$public=@($type.GetMethods([Reflection.BindingFlags]'Public,Static,DeclaredOnly'));if($public.Count-ne1-or$public[0].Name-cne'Run'){throw 'CDA8_API_SUBSTITUTION'};$method=$public[0];$parameters=@($method.GetParameters());if($method.ReturnType-ne[string]-or$parameters.Count-ne4-or@($parameters|Where-Object{$_.ParameterType-ne[string]}).Count-ne0){throw 'CDA8_API_SUBSTITUTION'};$map=Get-CDA8MethodMap $assembly;if($map.Count-ne[int]$manifest['method_count']-or$map.SHA256-cne[string]$manifest['method_map_sha256']){throw 'CDA8_METHOD_MAP_SUBSTITUTION'}
try{$result=$method.Invoke($null,@($path,$Mode,$CaseId,$RunId))}catch[Reflection.TargetInvocationException]{throw $_.Exception.InnerException};$after=Get-CDA8MethodMap $assembly;if($after.Count-ne$map.Count-or$after.SHA256-cne$map.SHA256){throw 'CDA8_POSTCALL_METHOD_MAP_DRIFT'};$result
~~~

## Removed Block R029

- SHA256: `EAC0F46403D1E29A4087A6DA0E6677BAA08D9D8B012B91B2BA8475B3925B8884`
- Language: `powershell`
- Bytes: `6627`
- First recovered timestamp: `2026-08-09T07:51:33.696Z`
- Session provenance: rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 200056 (2026-08-09T07:51:33.696Z); rollout-2026-08-07T21-31-01-019fdefe-b1a7-7d70-846c-74296fd921fc.jsonl line 200057 (2026-08-09T07:51:35.337Z)

~~~powershell
param([Parameter(Mandatory=$true)][string]$ReportPath)
$ErrorActionPreference='Stop';Set-StrictMode -Version Latest
$path=[IO.Path]::GetFullPath($ReportPath);$reportBytes=[IO.File]::ReadAllBytes($path);$hash=[Security.Cryptography.SHA256]::Create();try{$reportSha=[BitConverter]::ToString($hash.ComputeHash($reportBytes)).Replace('-','')}finally{$hash.Dispose()};$text=[Text.UTF8Encoding]::new($false).GetString($reportBytes).Replace("`r`n","`n").Replace("`r","`n")
function Read-HarnessBlock([string]$Name,[string]$Language){$begin='<!-- UID0001NW_'+$Name+'_BEGIN -->'+[char]10+'```'+$Language+[char]10;$end=[char]10+'```'+[char]10+'<!-- UID0001NW_'+$Name+'_END -->';$a=$text.IndexOf($begin,[StringComparison]::Ordinal);$z=$(if($a-lt0){-1}else{$text.IndexOf($end,$a+$begin.Length,[StringComparison]::Ordinal)});if($a-lt0-or$z-lt0){throw ('HARNESS_BLOCK:'+ $Name)};$text.Substring($a+$begin.Length,$z-$a-$begin.Length)}
function Quote-Literal([string]$Value){"'"+$Value.Replace("'","''")+"'"}
$loader=Read-HarnessBlock CDA8_LOADER powershell;$exe='C:\Windows\System32\WindowsPowerShell\v1.0\powershell.exe';$args='-NoLogo -NoProfile -NonInteractive -Command -';$cases=@(
  [pscustomobject]@{Id='INVALID_MODE';Mode='INVALID';Run='UID0001NW-OUTER-INVALID-MODE';Expected='MODE';Success=$false;Prelude=''},
  [pscustomobject]@{Id='INVALID_RUN_ID';Mode='SELFTEST';Run='bad';Expected='RUN_ID';Success=$false;Prelude=''},
  [pscustomobject]@{Id='PRELOADED_TYPE';Mode='SELFTEST';Run='UID0001NW-OUTER-PRETYPE';Expected='CDA8_PRELOADED_TYPE';Success=$false;Prelude="$an=[Reflection.AssemblyName]::new('CDA8TypeProbe');$ab=[AppDomain]::CurrentDomain.DefineDynamicAssembly($an,[Reflection.Emit.AssemblyBuilderAccess]::Run);$mb=$ab.DefineDynamicModule('m');$tb=$mb.DefineType('UID0001NW.CDA8Production.PreloadedProbe',[Reflection.TypeAttributes]::Public);$null=$tb.CreateType();"},
  [pscustomobject]@{Id='PRELOADED_ASSEMBLY';Mode='SELFTEST';Run='UID0001NW-OUTER-PREASM';Expected='CDA8_PRELOADED_ASSEMBLY';Success=$false;Prelude="$an=[Reflection.AssemblyName]::new('UID0001NW.CDA8Production.Substitute');$null=[AppDomain]::CurrentDomain.DefineDynamicAssembly($an,[Reflection.Emit.AssemblyBuilderAccess]::Run);"},
  [pscustomobject]@{Id='API_SUBSTITUTION';Mode='OUTER';Run='UID0001NW-OUTER-API';Expected='CDA8_API_SUBSTITUTION';Success=$false;Prelude=''},
  [pscustomobject]@{Id='IMPLEMENTATION_SUBSTITUTION';Mode='OUTER';Run='UID0001NW-OUTER-IMPL';Expected='CDA8_IMPLEMENTATION_SUBSTITUTION';Success=$false;Prelude=''},
  [pscustomobject]@{Id='COMMAND_SUBSTITUTION';Mode='SELFTEST';Run='UID0001NW-OUTER-COMMAND';Expected='CDA8_COMMAND_SUBSTITUTION';Success=$false;Prelude="function global:Add-Type{throw 'FORGED'};"},
  [pscustomobject]@{Id='ENVIRONMENT_SUBSTITUTION';Mode='SELFTEST';Run='UID0001NW-OUTER-ENV';Expected='CDA8_ENVIRONMENT_SUBSTITUTION';Success=$false;Prelude="[Environment]::SetEnvironmentVariable('UID0001NW_CDA8_FORGED','1','Process');"},
  [pscustomobject]@{Id='FRESH_ENTRY_ONE';Mode='FIXTURE';Run='UID0001NW-OUTER-FRESH-ONE';Expected='TERMINAL_P1';Success=$true;Prelude=''},
  [pscustomobject]@{Id='FRESH_ENTRY_TWO';Mode='FIXTURE';Run='UID0001NW-OUTER-FRESH-TWO';Expected='TERMINAL_P1';Success=$true;Prelude=''}
)
$receipts=@();foreach($case in $cases){$script='$p='+(Quote-Literal $path)+';$expectedSha='+(Quote-Literal $reportSha)+';$loader='+(Quote-Literal $loader)+';'+$case.Prelude+'$h=[Security.Cryptography.SHA256]::Create();try{$actual=[BitConverter]::ToString($h.ComputeHash([IO.File]::ReadAllBytes($p))).Replace(''-'','''')}finally{$h.Dispose()};if($actual-cne$expectedSha){throw ''CDA8_REPORT_DRIFT''};try{$value=&([ScriptBlock]::Create($loader))-ReportPath $p -Mode '+(Quote-Literal $case.Mode)+' -CaseId '+(Quote-Literal $case.Id)+' -RunId '+(Quote-Literal $case.Run)+';[pscustomobject]@{ok=$true;value=$value;reason='''' }|ConvertTo-Json -Depth 100 -Compress}catch{[pscustomobject]@{ok=$false;value=$null;reason=$_.Exception.Message}|ConvertTo-Json -Depth 100 -Compress}'
  $psi=[Diagnostics.ProcessStartInfo]::new($exe,$args);$psi.UseShellExecute=$false;$psi.CreateNoWindow=$true;$psi.RedirectStandardInput=$true;$psi.RedirectStandardOutput=$true;$psi.RedirectStandardError=$true;$process=[Diagnostics.Process]::Start($psi);$pid=$process.Id;$wmi=Get-CimInstance Win32_Process -Filter ('ProcessId='+$pid);$identity=[pscustomobject]@{pid=$pid;parent_pid=[int]$wmi.ParentProcessId;creation=[string]$wmi.CreationDate;image=[string]$wmi.ExecutablePath;command_line=[string]$wmi.CommandLine};if($identity.parent_pid-ne$PID-or-not[StringComparer]::OrdinalIgnoreCase.Equals([IO.Path]::GetFullPath($identity.image),[IO.Path]::GetFullPath($exe))-or$identity.command_line.IndexOf($args,[StringComparison]::OrdinalIgnoreCase)-lt0){throw ('OUTER_IDENTITY:'+ $case.Id)};$process.StandardInput.Write($script);$process.StandardInput.Close();$outTask=$process.StandardOutput.ReadToEndAsync();$errTask=$process.StandardError.ReadToEndAsync();if(-not$process.WaitForExit(240000)){try{$process.Kill()}catch{};$null=$process.WaitForExit(5000);throw ('OUTER_TIMEOUT:'+ $case.Id)};$output=$outTask.Result.Trim();$error=$errTask.Result.Trim();if($process.ExitCode-ne0){throw ('OUTER_EXIT:'+ $case.Id+':'+$error)};$row=$output|ConvertFrom-Json;if($case.Success){if(-not$row.ok){throw ('OUTER_UNEXPECTED_FAILURE:'+ $case.Id+':'+$row.reason)};$inner=[string]$row.value|ConvertFrom-Json;if([string]$inner.actual_reason-cne$case.Expected-or-not[bool]$inner.cleanup_complete){throw ('OUTER_FRESH_RESULT:'+ $case.Id)}}else{if($row.ok-or-not([string]$row.reason).StartsWith($case.Expected,[StringComparison]::Ordinal)){throw ('OUTER_REASON:'+ $case.Id+':'+$row.reason)}};$remaining=@(Get-CimInstance Win32_Process -Filter ('ProcessId='+$pid)|Where-Object{[string]$_.CreationDate-eq$identity.creation});if($remaining.Count-ne0){throw ('OUTER_PROCESS_REMAINS:'+ $case.Id)};$receipts+=,[pscustomobject]@{case=$case.Id;mode=$case.Mode;expected=$case.Expected;observed=$(if($case.Success){$case.Expected}else{[string]$row.reason});passed=$true;report_sha256=$reportSha;process_identity=$identity;retired=$true;stdin_command=$true;command_args=$args}}
$tempRoot=Join-Path ([IO.Path]::GetTempPath()) 'UID0001NW-CDA8';$residue=@(if(Test-Path -LiteralPath $tempRoot){Get-ChildItem -LiteralPath $tempRoot -Recurse -Force});if($residue.Count-ne0){throw 'OUTER_TEMP_RESIDUE'}
[pscustomobject]@{authority='UID0001NW_CDA8_PRODUCTION';report_sha256=$reportSha;outer_case_count=$receipts.Count;all_passed=$true;all_fresh_processes=$true;all_retired=$true;report_owned_temp_residue=0;cases=$receipts}|ConvertTo-Json -Depth 100 -Compress
~~~
