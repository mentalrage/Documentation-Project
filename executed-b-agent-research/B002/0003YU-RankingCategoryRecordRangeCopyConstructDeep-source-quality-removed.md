<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0003YU-RankingCategoryRecordRangeCopyConstructDeep-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003YU-RankingCategoryRecordRangeCopyConstructDeep-source-quality.md](0003YU-RankingCategoryRecordRangeCopyConstructDeep-source-quality.md)
- Source report SHA256 before archive-link insertion: `875F1BE449813426CB2A45551253F16436B98784867D21747292D54B4F68585C`
- Recovery generated: `2026-08-09T22:17:53Z`
- Unique recovered executable blocks: `20`
- Recovered executable bytes: `356914`
- Recovery basis: report-path-associated Codex session history. The source report had already removed its executable packages before the supervisor could extract them directly.
- Scope: this archive preserves every unique recoverable report-local executable block, including superseded historical variants where session history retained more than the final pre-removal report.
- Authority: this file is not a B-agent research report, claims no target coverage, and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- SHA256: `6859EA324AF75ACF11A8CF86723971489972B1A13EFE9CA791F9572AD8E1E6C5`
- Language: `powershell`
- Bytes: `1617`
- First recovered timestamp: `2026-08-06T22:17:36.650Z`
- Session provenance: rollout-2026-08-06T18-14-21-019fd924-46f7-7000-b0f9-a0aadf64fceb.jsonl line 193706 (2026-08-06T22:17:36.650Z); rollout-2026-08-06T18-14-21-019fd924-46f7-7000-b0f9-a0aadf64fceb.jsonl line 193707 (2026-08-06T22:17:36.704Z)

~~~powershell
$p = (Resolve-Path -LiteralPath 'E:\NTK\Resources\NexusTK\NexusTK.exe.i64').Path
$P0 = Get-ClosedExclusiveIdbTuple $p
$P0Confirm = Get-ClosedExclusiveIdbTuple $p
Assert-ExactTuple $P0Confirm $P0 'P0-repeat'
$b = "$p.bak-UID0003YU-prestate-$([DateTime]::UtcNow.ToString('yyyyMMdd_HHmmssfffffff'))"
if (Test-Path -LiteralPath $b) { throw 'B0 collision' }
$src = [System.IO.FileStream]::new($p,[System.IO.FileMode]::Open,[System.IO.FileAccess]::Read,[System.IO.FileShare]::None)
$dst = $null
try {
    $dst = [System.IO.FileStream]::new($b,[System.IO.FileMode]::CreateNew,[System.IO.FileAccess]::Write,[System.IO.FileShare]::None)
    if ($src.Length -ne $P0.Length) { throw 'P0 length changed before B0 copy' }
    $src.CopyTo($dst)
    if ($src.Position -ne $P0.Length -or $src.ReadByte() -ne -1) { throw 'B0 source EOF mismatch' }
    if ($dst.Position -ne $P0.Length -or $dst.Length -ne $P0.Length) { throw 'B0 destination length mismatch' }
    $dst.Flush($true)
} finally {
    if ($dst) { $dst.Dispose() }
    $src.Dispose()
}
[System.IO.File]::SetLastWriteTimeUtc($b,[DateTime]::new([long]$P0.LastWriteTimeUtcTicks,[DateTimeKind]::Utc))
$B0 = Get-ClosedExclusiveIdbTuple $b
$B0Confirm = Get-ClosedExclusiveIdbTuple $b
Assert-ExactTuple $B0Confirm $B0 'B0-repeat'
if ($B0.Path -cne (Resolve-Path -LiteralPath $b).Path -or
    $B0.Length -ne $P0.Length -or $B0.SHA256 -cne $P0.SHA256 -or
    $B0.LastWriteTimeUtc -cne $P0.LastWriteTimeUtc -or
    $B0.LastWriteTimeUtcTicks -ne $P0.LastWriteTimeUtcTicks) {
    throw 'B0 is not complete-tuple equal to P0 under the intentional path translation'
}
~~~

## Removed Block CLEANUP-20260813-0003YU-OUTSIDE21-RUNBOOK

Source: [0003YU-RankingCategoryRecordRangeCopyConstructDeep-source-quality.md](0003YU-RankingCategoryRecordRangeCopyConstructDeep-source-quality.md)

This archive is non-authoritative and must never be executed. It preserves the exact report lines removed during supervisor cleanup.

<!-- BEGIN CLEANUP-20260813-0003YU-OUTSIDE21-RUNBOOK -->
15: - Gate 2B remains fail-closed and primary-supervisor-owned. The supervisor must independently establish the current canonical IDB/session, verify every literal I01-I03 pre-state row, create the backup, apply only the accepted actions, read back every protected field, correlate the save, and restore on any mismatch. This report is evidence and handoff only; it contains no executable transaction package.
45: - Under the current format, the structured I01-I03 table is the only Gate 2B handoff. The supervisor performs live authority checks, backup, mutations, readbacks, save, and restoration outside this report.
140: | C0003YU-029 | 0003YU | At `0x0045d660`, after exact pre-state and collision checks, use only database-scoped `rename` with `batch.func.name`, `batch.func.addr`, `allow_overwrite:false`, `stop_on_error:true`, and mandatory `pure:true`; run `dry_run:true`, prove no delta, then repeat with only `dry_run:false`. Pure mode must produce name-only behavior with no `/vibe/` state or decompiler refresh, and complete readback must show only `sub_45D660` -> `RankingCategoryRecordRangeCopyConstructDeep`. | very high | current rename schema/structured IDA handoff | IDA I01 | primary supervisor Gate2B | incorporate | proposed |
143: | C0003YU-032 | 0003YU | Primary supervisor performs I01-I03 directly outside the report using only the exact current database-scoped request shapes: `rename(batch,database)`, `set_type(edits,database)`, and `set_function_comments(items,database)`. Reconfirm live schemas/session and every literal pre-state, retain a restorable backup, apply one accepted action at a time, require the exact endpoint result plus immediate/final protected-state readbacks and correlated save evidence, and restore or record no-change on any mismatch. No report-embedded executable package or inferred wrapper field is authorized. | certain | schema-bound supervisor IDA handoff | IDA transaction | primary supervisor Gate2B | incorporate | proposed |
165: For C0003YU-032 and C0003YU-050, the structured I01-I03 handoff is the only current report-side authority. It provides exact entity/range, literal pre-state, proposed action/no-change disposition, evidence, safety constraints, and expected readback. The primary supervisor performs every live IDA/MCP, backup, save, restoration, and operational step directly outside the report. No supervisor row is completed and no live call is authorized for B002.
328: - The report contains no executable transaction route. Backup, save correlation, restoration, process handling, and operational verification are supervisor responsibilities performed outside the report.
504: | [ ] | C0003YU-029 | 0003YU | At `0x0045d660`, after exact pre-state and collision checks, use only database-scoped `rename` with `batch.func.name`, `batch.func.addr`, `allow_overwrite:false`, `stop_on_error:true`, and mandatory `pure:true`; run `dry_run:true`, prove no delta, then repeat with only `dry_run:false`. Pure mode must produce name-only behavior with no `/vibe/` state or decompiler refresh, and complete readback must show only `sub_45D660` -> `RankingCategoryRecordRangeCopyConstructDeep`. | IDA I01 | primary supervisor Gate2B | incorporate | proposed |
507: | [ ] | C0003YU-032 | 0003YU | Primary supervisor performs I01-I03 directly outside the report using only the exact current database-scoped request shapes: `rename(batch,database)`, `set_type(edits,database)`, and `set_function_comments(items,database)`. Reconfirm live schemas/session and every literal pre-state, retain a restorable backup, apply one accepted action at a time, require the exact endpoint result plus immediate/final protected-state readbacks and correlated save evidence, and restore or record no-change on any mismatch. No report-embedded executable package or inferred wrapper field is authorized. | IDA transaction | primary supervisor Gate2B | incorporate | proposed |
533: Checklist interpretation for C0003YU-032/C0003YU-050 is locked to the non-executable structured handoff. The supervisor must verify the exact live pre-state, apply or decline I01-I03 individually, prove only the permitted deltas, and record backup/readback/save/restoration evidence outside the report. All 18 supervisor rows remain unchecked.
<!-- END CLEANUP-20260813-0003YU-OUTSIDE21-RUNBOOK -->

## Removed Block CLEANUP-20260813-0003YU-SECTION21

Source report: [0003YU-RankingCategoryRecordRangeCopyConstructDeep-source-quality.md](0003YU-RankingCategoryRecordRangeCopyConstructDeep-source-quality.md)

This block is non-authoritative and must never be executed. It receives no Gate, coverage, score, IDA, validator, or lifecycle credit. The following material is preserved verbatim from source artifact SHA256 `CD6EB63C0A77F3D708CC43BDD4F7061AE565983600D0F26649913A9607DCD409`.

<!-- BEGIN CLEANUP-20260813-0003YU-SECTION21 -->
## IDA Rename / Type / Comment Recommendations

These are structured primary-supervisor Gate 2B recommendations only. B002 performed no IDA mutation, save, backup, restore, MCP operation, process control, or lifecycle action. The report is not executable; the supervisor must perform every accepted operation directly, verify live pre-state first, and record the resulting readback/save evidence outside this report.

### Structured action handoff

`Physical PRE` is the last documented live IDB state before any accepted mutation. `Action-entry PRE` is the sequential state required after every preceding accepted action. Each current comment channel is stated literally. Any fresh mismatch converts the affected row to no-change pending renewed review; it is not permission to coerce the database into the expected state.

All three actions are bound to the current public MCP request shapes and to the exact database/session identifier returned by the supervisor's fresh canonical `idb_open`; `<active-session-id-from-current-idb_open>` is a required runtime substitution, not caller-selected authority. The supervisor must first confirm current `tools/list` still exposes the literal fields used below. A missing field, renamed endpoint, wrapper/schema drift, ambiguous session, or current pre-state mismatch stops before mutation and returns the row for renewed review. The inline objects below are structured handoff records, not an executable report program or transaction package.

| Action | Exact entity / address or range | Literal current pre-state | Proposed action or no-change disposition | Evidence | Safety constraints | Expected readback |
|---|---|---|---|---|---|---|
| `I01` | Function entry `0x0045d660`; owned code range `[0x0045d660,0x0045d6d6)`; size `0x76` / 118 bytes. | Physical and action-entry PRE: name `sub_45D660`; declaration/type `char *__stdcall(int, int, char *)`; address regular comment `absent`; address repeatable comment `absent`; function regular comment `absent`; function repeatable comment `absent`. | Use only `rename`. Collision-safe dry run: `rename {batch:{allow_overwrite:false,dry_run:true,stop_on_error:true,func:{name:"RankingCategoryRecordRangeCopyConstructDeep",addr:"0x0045d660"},pure:true},database:"<active-session-id-from-current-idb_open>"}`. After an unchanged complete readback, apply the identical request with only `dry_run:false`. `pure:true` is mandatory: it authorizes name-only mutation and skips function-directory placement/save and decompiler refresh. The accepted action requires no `/vibe/` state and no decompiler refresh. | Exact 51-row body inventory; two caller sites `0x0045d0c8` and `0x0045d0d9`; `retn 0Ch`; range-copy loop and EH cleanup; descriptive naming analysis; current `rename.batch.pure` contract. | Destination-name lookup must show no collision; `allow_overwrite:false`, `stop_on_error:true`, and a one-item function-only batch are mandatory. Reject any `/vibe/` state, directory link, decompile/Hex-Rays call, `refresh_decompiler_ctext`, type/frame/comment/analysis delta, or response other than one successful function result and `summary.total:1`, `ok:1`, `failed:0`, `stopped:false` with dry-run state matching the request. Stop/restore on any unexpected delta. | Dry run leaves the complete PRE unchanged. Actual readback through fresh `lookup_funcs`, complete `stack_frame`, and `get_comments` shows only the exact name `RankingCategoryRecordRangeCopyConstructDeep`; type remains `char *__stdcall(int, int, char *)`; all four comments remain `absent`; complete ten-row frame and protected bytes/range/xrefs/UDTs/adjacent state remain identical. |
| `I02` | Same function and range after accepted `I01`. | Physical PRE remains the complete I01 PRE above. Action-entry PRE: name `RankingCategoryRecordRangeCopyConstructDeep`; type `char *__stdcall(int, int, char *)`; all four comments `absent`; frame is exactly the ten rows in the table below. | Use only the dedicated function-type endpoint: `set_type {database:"<active-session-id-from-current-idb_open>",edits:{signature:"RankingCategoryRecord *__thiscall RankingCategoryRecordRangeCopyConstructDeep(RankingCategoryRecordVectorStorage *this, const RankingCategoryRecord *first, const RankingCategoryRecord *last, RankingCategoryRecord *destination)",addr:"0x0045d660",kind:"function"}}`. No generic type wrapper, stack/local rename, frame recreation, or omitted `kind`/`signature` field is permitted. | ECX carries vector storage; callers push `first`, `last`, and `destination`; callee returns with `retn 0Ch`; EAX returns destination end; UDT size/stride is `0x2b0`; current `set_type(edits,database)` function schema. | Supervisor must verify all ten frame rows before the type action. The endpoint response must contain exactly one function edit, echo the exact `addr`, `kind`, and `signature`, and report `kind:"function"`, `ok:true`. Compare two fresh complete post-action reads. Any added, removed, reordered, resized, or otherwise changed row; local/saved-register/return-address drift; unlisted argument delta; comment/name/body/range/xref/UDT drift; or type parse ambiguity requires restoration/no-change. | Name and exact thiscall signature match this row; comments remain four `absent` channels; frame still has exactly ten rows in order, with only `arg_0` -> `first` / `const RankingCategoryRecord *`, `arg_4` -> `last` / `const RankingCategoryRecord *`, and `arg_8` -> `destination` / `RankingCategoryRecord *`. The other seven rows remain byte-for-byte equivalent in name/offset/size/type, and the second complete readback equals the first. |
| `I03` | Same function and range after accepted `I01` and `I02`. | Physical PRE remains the complete I01 PRE. Action-entry PRE: accepted I01 name; exact I02 thiscall signature and ten-row frame; address regular, address repeatable, function regular, and function repeatable comments each `absent`. | Use only the dedicated regular-function-comment endpoint: `set_function_comments {items:{addr:"0x0045d660",comment:"Compiler-generated std::vector<RankingCategoryRecord> uninitialized range-copy helper for RankingCategoryCollection::m_records: deep-copy constructs [first,last) into destination at 0x2b0 stride, destroys the constructed prefix on exception, and returns the destination end; no standalone source helper."},database:"<active-session-id-from-current-idb_open>"}`. This endpoint is bound to regular function-comment semantics (`set_func_cmt(...,False)`). | Loop semantics, UID0003X4 deep element copy, prefix-destruction EH path, two UID0003X0 call sites, owner/source-placement analysis, no-code conclusion, and current `set_function_comments(items,database)` schema. | Do not use generic `set_comments`, `set_address_comments`, `set_address_repeatable_comments`, or `set_repeatable_comments`; no address or repeatable channel is authorized. The response must contain exactly one item with `addr:"0x0045d660"` and `function_addr:"0x45d660"`. Any wrong channel/text, extra comment, or name/type/frame/body/range/xref/UDT delta requires restoration/no-change. | Fresh `get_comments` shows the exact proposed sentence only in function regular; address regular, address repeatable, and function repeatable remain `absent`. Fresh `lookup_funcs` and complete `stack_frame` preserve the accepted name/type/frame, and all protected state remains exact. |

### I02 complete literal ten-row frame pre-state and permitted transition

| Row | Current I02-entry name | Offset | Size | Current I02-entry type | Only permitted post-I02 name/type |
|---:|---|---|---|---|---|
| 1 | `var_18` | `+0x10` | `4` | `_DWORD` | unchanged `var_18` / `_DWORD` |
| 2 | `var_14` | `+0x14` | `4` | `_DWORD` | unchanged `var_14` / `_DWORD` |
| 3 | `var_10` | `+0x18` | `4` | `_DWORD` | unchanged `var_10` / `_DWORD` |
| 4 | `var_C` | `+0x1c` | `4` | `_DWORD` | unchanged `var_C` / `_DWORD` |
| 5 | `var_4` | `+0x24` | `4` | `_DWORD` | unchanged `var_4` / `_DWORD` |
| 6 | `__saved_registers` | `+0x28` | `4` | `_DWORD` | unchanged `__saved_registers` / `_DWORD` |
| 7 | `__return_address` | `+0x2c` | `4` | `_UNKNOWN *` | unchanged `__return_address` / `_UNKNOWN *` |
| 8 | `arg_0` | `+0x30` | `4` | `_DWORD` | `first` / `const RankingCategoryRecord *` |
| 9 | `arg_4` | `+0x34` | `4` | `_DWORD` | `last` / `const RankingCategoryRecord *` |
| 10 | `arg_8` | `+0x38` | `4` | `_DWORD` | `destination` / `RankingCategoryRecord *` |

### Explicit no-change dispositions

| Entity / scope | Disposition | Evidence and constraint | Expected readback |
|---|---|---|---|
| Locals, labels, EH entries, UID0003X4 callee, UID0003X0 caller, and adjacent functions | No IDA change. | Existing compiler/helper names and boundaries are either local implementation details or separately owned. | All names, types, comments, bytes, xrefs, and ranges outside I01-I03 remain unchanged. |
| `RankingCategoryRecord` UDT and dependencies | No UDT change. | The existing complete 15-member layout, nested vector at `+0x258`, and size `0x2b0` already support the helper exactly. | UDT member count, offsets, types, and size remain identical. |
| Target formal CPP/H channels | Keep both blank. | UID0003YU is compiler-generated non-source-emitting evidence covered by the UID0003X0 vector operation; standalone emitted code would duplicate source semantics and expose compiler machinery. | `RECONSTRUCTION_CPP CODE` and `RECONSTRUCTION_H CODE` remain blank; owner/emitter metadata remains unchanged. |
| Report-embedded automation | Removed and not authorized. | Current project format makes B reports non-executable research/handoff documents. Historical script packages and their self-test receipts do not establish current evidence or lifecycle authority. | Report has zero executable script fences or fixtures; supervisor performs backup, mutation, readback, save, restore, and operational verification directly outside the report. |

### Supervisor Gate 2B operating boundary

The supervisor must independently establish the canonical live IDB/session, obtain a fresh tool/schema view, verify the complete item-by-item pre-state above, and decide whether each action remains safe. For every accepted action, the supervisor owns backup creation, exact one-action mutation, immediate and final readback, save correlation, failure classification, and restoration verification. A row is complete only when its exact expected readback is physically observed and the saved IDB is confirmed. A mismatch is a failed/no-change disposition, not an invitation to relax the row.

C0003YU-029 through C0003YU-032 and C0003YU-050 remain supervisor-pending. This report supplies evidence and structured handoff only. It does not supply, invoke, or authorize a transaction package, process launcher, hostile suite, fixture, or executable proof. Earlier report-embedded package designs and receipts are retained only as summarized historical failure context elsewhere; they support no current claim.
<!-- END CLEANUP-20260813-0003YU-SECTION21 -->

## Removed Block R002

- SHA256: `84F0945F3EFD312E41A9D74EF9A48E1CBDA703F138A321A00CBD31627BB4AF91`
- Language: `powershell`
- Bytes: `1140`
- First recovered timestamp: `2026-08-06T22:17:36.650Z`
- Session provenance: rollout-2026-08-06T18-14-21-019fd924-46f7-7000-b0f9-a0aadf64fceb.jsonl line 193706 (2026-08-06T22:17:36.650Z); rollout-2026-08-06T18-14-21-019fd924-46f7-7000-b0f9-a0aadf64fceb.jsonl line 193707 (2026-08-06T22:17:36.704Z)

~~~powershell
$B0Guard = Get-ClosedExclusiveIdbTuple $b
Assert-ExactTuple $B0Guard $B0 'B0-pre-restore'
$src = [System.IO.FileStream]::new($b,[System.IO.FileMode]::Open,[System.IO.FileAccess]::Read,[System.IO.FileShare]::None)
$dst = $null
try {
    $dst = [System.IO.FileStream]::new($p,[System.IO.FileMode]::Open,[System.IO.FileAccess]::Write,[System.IO.FileShare]::None)
    $dst.SetLength(0)
    if ($dst.Length -ne 0 -or $dst.Position -ne 0) { throw 'Canonical destination did not truncate deterministically' }
    $src.CopyTo($dst)
    if ($src.Position -ne $B0.Length -or $src.ReadByte() -ne -1) { throw 'Restore source EOF mismatch' }
    if ($dst.Position -ne $P0.Length -or $dst.Length -ne $P0.Length) { throw 'Restore destination length mismatch' }
    $dst.Flush($true)
} finally {
    if ($dst) { $dst.Dispose() }
    $src.Dispose()
}
[System.IO.File]::SetLastWriteTimeUtc($p,[DateTime]::new([long]$P0.LastWriteTimeUtcTicks,[DateTimeKind]::Utc))
$R0 = Get-ClosedExclusiveIdbTuple $p
$R0Confirm = Get-ClosedExclusiveIdbTuple $p
Assert-ExactTuple $R0 $P0 'R0-versus-P0'
Assert-ExactTuple $R0Confirm $P0 'R0-repeat-versus-P0'
~~~

## Removed Block R003

- SHA256: `91EF6D3225173869FF4BAF0A2E3145FDA51A7A2BC06CC0A4730520E25BC5280E`
- Language: `powershell`
- Bytes: `5503`
- First recovered timestamp: `2026-08-06T22:17:36.650Z`
- Session provenance: rollout-2026-08-06T18-14-21-019fd924-46f7-7000-b0f9-a0aadf64fceb.jsonl line 193706 (2026-08-06T22:17:36.650Z)

~~~powershell
$endpointAddress = '127.0.0.1'
$endpointPort = 13337
$listeners = @(Get-NetTCPConnection -State Listen -ErrorAction Stop |
    Where-Object { $_.LocalAddress -eq $endpointAddress -and $_.LocalPort -eq $endpointPort })
if ($listeners.Count -ne 1) { throw "Expected exactly one MCP listener, found $($listeners.Count)" }
$listenerPid = [int]$listeners[0].OwningProcess
$listener = Get-CimInstance Win32_Process -Filter "ProcessId=$listenerPid"
if ($null -eq $listener) { throw 'Listener process disappeared before binding' }
$listenerStart = (Get-Process -Id $listenerPid -ErrorAction Stop).StartTime.ToUniversalTime()
$listenerGeneration = [pscustomobject]@{
    Pid = $listenerPid
    ParentPid = [int]$listener.ParentProcessId
    StartTimeUtc = $listenerStart.ToString('o')
    ExecutablePath = [string]$listener.ExecutablePath
    CommandLine = [string]$listener.CommandLine
    Endpoint = "http://$endpointAddress`:$endpointPort/mcp"
}
if ($listenerGeneration.CommandLine -notmatch '(?i)idalib-mcp\.exe') { throw 'Listener is not the idalib-mcp entry point' }
if ($listenerGeneration.CommandLine -notmatch '(?i)--host\s+127\.0\.0\.1') { throw 'Listener host binding differs' }
if ($listenerGeneration.CommandLine -notmatch '(?i)--port\s+13337(?:\s|$)') { throw 'Listener port binding differs' }

$venvRoot = 'C:\Users\admin\.idapro\idalib-mcp-venv'
$venvPython = Join-Path $venvRoot 'Scripts\python.exe'
$consoleEntry = Join-Path $venvRoot 'Scripts\idalib-mcp.exe'
if (-not (Test-Path -LiteralPath $venvPython -PathType Leaf) -or
    -not (Test-Path -LiteralPath $consoleEntry -PathType Leaf)) { throw 'Bound venv entry point is absent' }
if ($listenerGeneration.CommandLine -notlike "*$consoleEntry*") { throw 'Listener command line is not bound to the expected console entry point' }
$moduleJson = & $venvPython -I -c "import importlib.util,json,pathlib; s=importlib.util.find_spec('ida_pro_mcp.idalib_supervisor'); p=pathlib.Path(s.origin).resolve(); print(json.dumps({'module':str(p),'root':str(p.parent)}))"
if ($LASTEXITCODE -ne 0) { throw 'Exact-listener interpreter could not resolve ida_pro_mcp' }
$moduleIdentity = $moduleJson | ConvertFrom-Json
$packageRoot = (Resolve-Path -LiteralPath $moduleIdentity.root).Path
$supervisorModule = (Resolve-Path -LiteralPath $moduleIdentity.module).Path
if ($supervisorModule -ne (Join-Path $packageRoot 'idalib_supervisor.py')) { throw 'Resolved supervisor module/root mismatch' }
$distInfo = Get-ChildItem -LiteralPath (Split-Path $packageRoot -Parent) -Directory -Filter 'ida_pro_mcp-*.dist-info' |
    Where-Object { Test-Path -LiteralPath (Join-Path $_.FullName 'entry_points.txt') }
if (@($distInfo).Count -ne 1) { throw 'Could not bind one ida_pro_mcp distribution identity' }
$entryPoints = Join-Path $distInfo[0].FullName 'entry_points.txt'
$entryText = Get-Content -Raw -LiteralPath $entryPoints
if ($entryText -notmatch '(?m)^idalib-mcp\s*=\s*ida_pro_mcp\.idalib_supervisor:main\s*$') {
    throw 'Console entry point does not resolve to ida_pro_mcp.idalib_supervisor:main'
}
$implementationNames = @(
    'idalib_supervisor.py','ida_mcp\api_core.py','ida_mcp\api_analysis.py',
    'ida_mcp\api_modify.py','ida_mcp\api_stack.py','ida_mcp\api_types.py',
    'ida_mcp\api_memory.py','ida_mcp\utils.py'
)
$implementationIdentity = foreach ($name in $implementationNames) {
    $file = (Resolve-Path -LiteralPath (Join-Path $packageRoot $name)).Path
    [pscustomobject]@{ RelativePath=$name; Path=$file; SHA256=(Get-FileHash -Algorithm SHA256 -LiteralPath $file).Hash }
}
$entryIdentity = [pscustomobject]@{
    ConsoleEntryPath = (Resolve-Path -LiteralPath $consoleEntry).Path
    ConsoleEntrySHA256 = (Get-FileHash -Algorithm SHA256 -LiteralPath $consoleEntry).Hash
    EntryPointsPath = (Resolve-Path -LiteralPath $entryPoints).Path
    EntryPointsSHA256 = (Get-FileHash -Algorithm SHA256 -LiteralPath $entryPoints).Hash
    PackageRoot = $packageRoot
}
if ($entryIdentity.ConsoleEntrySHA256 -ne '38888EDC3241C00092D5A4F166F70E6AF8DF538D4C81C8DE75E461575E27580E' -or
    $entryIdentity.EntryPointsSHA256 -ne 'DA9A1E575662C419A1180D63884494D38EF22A1A5E8619CE368DA6CD9CD9E2CF') {
    throw 'Listener entry point/distribution identity drifted'
}
$expectedImplementation = @{
    'idalib_supervisor.py'='2D7098B6BDB58D7DCF8CF4825BBE7584F5E7ACB256AD318B05482E9A0B9AF10A'
    'ida_mcp\api_core.py'='90C59B3F64F26E170CC604000CE39B34B648352767059DD1C2DF1914E9CBD4A3'
    'ida_mcp\api_analysis.py'='4C9B9122A7D2697CD464C1F473A227A580FD803515A1C885A1AA262259F1969F'
    'ida_mcp\api_modify.py'='161B314A14DAAA34C718176444292597BBB7498FA80158E25C358542BC16D1B8'
    'ida_mcp\api_stack.py'='9E4B5898E875812E4C993597D44F0F6438430F92A8B2299DC5C62630D49AE1BB'
    'ida_mcp\api_types.py'='A3E7444BBAC0066B48EDF38E26F34E6ABEC823585CD50E43C6DA98C55B965ECF'
    'ida_mcp\api_memory.py'='A2D4E48921E2E7A8D3C4BD621658F645A9C17C7FB34E963E62AE864E452ABC93'
    'ida_mcp\utils.py'='5139910EA7496549A31EDD6F9EEE7B033DA16504E4F0D19C8052EC9ED1C62069'
}
foreach ($identity in $implementationIdentity) {
    if ($expectedImplementation[$identity.RelativePath] -ne $identity.SHA256) {
        throw "Bound listener implementation drift: $($identity.RelativePath)"
    }
}
# Rebind the process generation and TCP owner immediately before tools/list,
# every idb_open, the mutation sequence, and the one save. Any PID/start-time,
# command-line, package-root, entry-point, implementation-hash, or endpoint
# ownership change stops before another request.
~~~

## Removed Block R004

- SHA256: `D6CFF826B6084E0E8A6A50C614A0791FE268F2CAAF8820A6E53FF0406CC32F9E`
- Language: `powershell`
- Bytes: `1170`
- First recovered timestamp: `2026-08-06T22:17:36.650Z`
- Session provenance: rollout-2026-08-06T18-14-21-019fd924-46f7-7000-b0f9-a0aadf64fceb.jsonl line 193706 (2026-08-06T22:17:36.650Z); rollout-2026-08-06T18-14-21-019fd924-46f7-7000-b0f9-a0aadf64fceb.jsonl line 193707 (2026-08-06T22:17:36.704Z)

~~~powershell
function Get-ClosedExclusiveIdbTuple([string]$Path) {
    $resolved = (Resolve-Path -LiteralPath $Path).Path
    $stream = [System.IO.File]::Open($resolved,[System.IO.FileMode]::Open,[System.IO.FileAccess]::Read,[System.IO.FileShare]::None)
    $sha = [System.Security.Cryptography.SHA256]::Create()
    try {
        $length = $stream.Length
        $hash = ([BitConverter]::ToString($sha.ComputeHash($stream))).Replace('-','')
        if ($stream.Position -ne $length -or $stream.ReadByte() -ne -1) { throw 'Tuple hash did not consume exact EOF' }
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
function Assert-ExactTuple($Actual,$Expected,[string]$Label) {
    foreach ($field in @('Path','Length','SHA256','LastWriteTimeUtc','LastWriteTimeUtcTicks')) {
        if ($Actual.$field -cne $Expected.$field) { throw "$Label tuple mismatch: $field" }
    }
}
~~~

## Removed Block R005

- SHA256: `5B2746AE8DEEFD851449F132B73DCCE1BDC3F1C0989D0E10699EF059B4F7BFB0`
- Language: `powershell`
- Bytes: `6538`
- First recovered timestamp: `2026-08-06T22:59:54.033Z`
- Session provenance: rollout-2026-08-06T18-14-21-019fd924-46f7-7000-b0f9-a0aadf64fceb.jsonl line 193973 (2026-08-06T22:59:54.033Z); rollout-2026-08-06T18-14-21-019fd924-46f7-7000-b0f9-a0aadf64fceb.jsonl line 193974 (2026-08-06T22:59:54.097Z)

~~~powershell
function Get-LiveLoadedModuleAttestation($Generation,$Route,[string[]]$RequiredModuleNames,[string]$Role) {
    Assert-SameGeneration (Get-ExactProcessGeneration $Generation.Role $Generation.Pid) $Generation "$Role pre-attestation"
    $nonce = [Guid]::NewGuid().ToString('N')
    $scriptPath = Join-Path ([IO.Path]::GetTempPath()) "uid0003yu-attest-$nonce.py"
    $outputPath = Join-Path ([IO.Path]::GetTempPath()) "uid0003yu-attest-$nonce.json"
    if ((Test-Path -LiteralPath $scriptPath) -or (Test-Path -LiteralPath $outputPath)) { throw 'Attestation path collision' }
    $outputJson = $outputPath | ConvertTo-Json -Compress
    $rootJson = $Route.Entry.PackageRoot | ConvertTo-Json -Compress
    $requiredJson = @($RequiredModuleNames) | ConvertTo-Json -Compress
    $remoteSource = @"
import json, os, pathlib, sys
output_path = $outputJson
package_root = pathlib.Path($rootJson).resolve()
required = $requiredJson
rows = []
for name, module in tuple(sys.modules.items()):
    if module is None:
        continue
    file_value = getattr(module, '__file__', None)
    spec = getattr(module, '__spec__', None)
    origin = getattr(spec, 'origin', None) if spec is not None else None
    candidate = file_value or origin
    if not candidate or candidate in ('built-in', 'frozen'):
        continue
    try:
        resolved = pathlib.Path(candidate).resolve()
        resolved.relative_to(package_root)
    except (OSError, ValueError):
        continue
    rows.append({'name': name, 'object_id': id(module), 'file': str(pathlib.Path(file_value).resolve()) if file_value else None,
                 'spec_origin': str(pathlib.Path(origin).resolve()) if origin and origin not in ('built-in','frozen') else origin,
                 'loader_type': type(getattr(spec, 'loader', None)).__module__ + '.' + type(getattr(spec, 'loader', None)).__qualname__})
missing = sorted(set(required) - {row['name'] for row in rows})
payload = {'pid': os.getpid(), 'executable': str(pathlib.Path(sys.executable).resolve()),
           'prefix': str(pathlib.Path(sys.prefix).resolve()), 'base_prefix': str(pathlib.Path(sys.base_prefix).resolve()),
           'package_root': str(package_root), 'required': required, 'missing': missing,
           'modules': sorted(rows, key=lambda row: row['name'])}
fd = os.open(output_path, os.O_WRONLY | os.O_CREAT | os.O_EXCL, 0o600)
with os.fdopen(fd, 'w', encoding='utf-8', newline='\n') as stream:
    json.dump(payload, stream, sort_keys=True, separators=(',', ':'))
    stream.flush()
    os.fsync(stream.fileno())
"@
    [IO.File]::WriteAllText($scriptPath,$remoteSource,[Text.UTF8Encoding]::new($false))
    try {
        $launcher = 'import sys; sys.remote_exec(int(sys.argv[1]), sys.argv[2])'
        & $Route.Entry.BasePythonPath -c $launcher ([string]$Generation.Pid) $scriptPath
        if ($LASTEXITCODE -ne 0) { throw "$Role remote attestation launcher failed" }
        $deadline = [DateTime]::UtcNow.AddSeconds(15)
        while (-not (Test-Path -LiteralPath $outputPath)) {
            if ([DateTime]::UtcNow -ge $deadline) { throw "$Role runtime attestation timed out" }
            Start-Sleep -Milliseconds 100
        }
        Assert-SameGeneration (Get-ExactProcessGeneration $Generation.Role $Generation.Pid) $Generation "$Role post-attestation"
        $raw = [IO.File]::ReadAllText($outputPath,[Text.Encoding]::UTF8)
        $attestation = $raw | ConvertFrom-Json -Depth 32
        if ([int]$attestation.pid -ne $Generation.Pid -or $attestation.executable -cne $Generation.ExecutablePath) {
            throw "$Role attestation did not execute inside the bound process"
        }
        if ($attestation.package_root -cne $Route.Entry.PackageRoot -or @($attestation.missing).Count -ne 0) {
            throw "$Role loaded-module set/source root is incomplete or foreign"
        }
        $seen = @{}
        foreach ($module in @($attestation.modules)) {
            if ([long]$module.object_id -le 0 -or [string]::IsNullOrWhiteSpace([string]$module.loader_type)) {
                throw "$Role returned an invalid live module object"
            }
            $file = (Resolve-Path -LiteralPath ([string]$module.file)).Path
            $origin = (Resolve-Path -LiteralPath ([string]$module.spec_origin)).Path
            if ($file -cne $origin -or -not $file.StartsWith($Route.Entry.PackageRoot,[StringComparison]::OrdinalIgnoreCase)) {
                throw "$Role module file/spec origin escaped the bound package root"
            }
            $seen[[string]$module.name] = [pscustomobject]@{
                Name=[string]$module.name; ObjectId=[long]$module.object_id; File=$file; SpecOrigin=$origin
                LoaderType=[string]$module.loader_type; SHA256=(Get-FileHash -Algorithm SHA256 -LiteralPath $file).Hash
            }
        }
        foreach ($requiredName in $RequiredModuleNames) {
            if (-not $seen.ContainsKey($requiredName)) { throw "$Role did not load required module $requiredName" }
        }
        return [pscustomobject]@{ Role=$Role; Generation=$Generation; RawSHA256=([Convert]::ToHexString([Security.Cryptography.SHA256]::HashData([Text.Encoding]::UTF8.GetBytes($raw)))); Modules=$seen }
    } finally {
        Remove-Item -LiteralPath $scriptPath,$outputPath -Force -ErrorAction SilentlyContinue
    }
}

function Assert-SameLoadedModules($Actual,$Expected,[string]$Label) {
    Assert-SameGeneration $Actual.Generation $Expected.Generation "$Label generation"
    if ($Actual.Modules.Count -ne $Expected.Modules.Count) { throw "$Label loaded-module count drift" }
    foreach ($name in $Expected.Modules.Keys) {
        if (-not $Actual.Modules.ContainsKey($name)) { throw "$Label missing loaded module $name" }
        foreach ($field in @('Name','ObjectId','File','SpecOrigin','LoaderType','SHA256')) {
            if ($Actual.Modules[$name].$field -cne $Expected.Modules[$name].$field) { throw "$Label module drift: $name/$field" }
        }
    }
}

$L2RequiredModules = @('ida_pro_mcp.idalib_supervisor','zeromcp.mcp')
$WorkerRequiredModules = @(
    'ida_pro_mcp.idalib_server','ida_pro_mcp.idalib_session_manager','ida_pro_mcp.worker_lifecycle',
    'ida_pro_mcp.ida_mcp.api_core','ida_pro_mcp.ida_mcp.api_analysis','ida_pro_mcp.ida_mcp.api_modify',
    'ida_pro_mcp.ida_mcp.api_stack','ida_pro_mcp.ida_mcp.api_types','ida_pro_mcp.ida_mcp.api_memory',
    'ida_pro_mcp.ida_mcp.utils','ida_pro_mcp.ida_mcp.zeromcp.mcp'
)
$L2Modules0 = Get-LiveLoadedModuleAttestation $Route0.L2 $Route0 $L2RequiredModules 'L2'
~~~

## Removed Block R006

- SHA256: `4DF195B6075F159F31705675CE84C50DAE35C5A2C1B1FF703406BC827FC2BB2A`
- Language: `powershell`
- Bytes: `1375`
- First recovered timestamp: `2026-08-06T23:02:26.583Z`
- Session provenance: rollout-2026-08-06T18-14-21-019fd924-46f7-7000-b0f9-a0aadf64fceb.jsonl line 194003 (2026-08-06T23:02:26.583Z); rollout-2026-08-06T18-14-21-019fd924-46f7-7000-b0f9-a0aadf64fceb.jsonl line 194004 (2026-08-06T23:02:26.649Z); rollout-2026-08-06T18-14-21-019fd924-46f7-7000-b0f9-a0aadf64fceb.jsonl line 194741 (2026-08-07T00:08:05.697Z)

~~~powershell
function New-AttributableSavedTuple($Candidate,$Repeated,$Prestate,$VerifierReadback,[string]$Outcome) {
    if ($Outcome -notin @('success','failing-saved','indeterminate-saved')) { throw 'Outcome cannot establish persistence attribution' }
    Assert-ExactTuple $Repeated $Candidate "$Outcome repeated saved tuple"
    $equalP0 = $true
    foreach ($field in @('Path','Length','SHA256','LastWriteTimeUtc','LastWriteTimeUtcTicks')) {
        if ($Candidate.$field -cne $Prestate.$field) { $equalP0=$false; break }
    }
    if ($equalP0) { throw "$Outcome candidate is P0, not a saved identity" }
    if ($null -eq $VerifierReadback -or @($VerifierReadback.Keys).Count -ne 14) {
        throw "$Outcome verifier did not return the complete fourteen-call RB-YU package"
    }
    [pscustomobject]@{
        Path=$Candidate.Path; Length=[long]$Candidate.Length; SHA256=$Candidate.SHA256
        LastWriteTimeUtc=$Candidate.LastWriteTimeUtc; LastWriteTimeUtcTicks=[long]$Candidate.LastWriteTimeUtcTicks
    }
}

# In exactly one persisted classifier branch, after that branch's role has
# completed RB-YU and retired, bind the exact repeated disk identity read-only.
$RecordedSavedTuple = New-AttributableSavedTuple $S1 $S1Confirm $P0 $NamedVerifierRBYU $ClassifierOutcome
Set-Variable -Name AttributableSavedTuple -Option ReadOnly -Value $RecordedSavedTuple
~~~

## Removed Block R007

- SHA256: `35500F3E63480C041CCB96EB5493B55D2DC980452B919B675F1A2521F729F369`
- Language: `powershell`
- Bytes: `6778`
- First recovered timestamp: `2026-08-06T23:27:55.928Z`
- Session provenance: rollout-2026-08-06T18-14-21-019fd924-46f7-7000-b0f9-a0aadf64fceb.jsonl line 194205 (2026-08-06T23:27:55.928Z)

~~~powershell
function Get-LiveLoadedModuleAttestation($Generation,$Route,[string[]]$RequiredModuleNames,[string]$Role) {
    Assert-SameGeneration (Get-ExactProcessGeneration $Generation.Role $Generation.Pid) $Generation "$Role pre-attestation"
    $nonce = [Guid]::NewGuid().ToString('N')
    $scriptPath = Join-Path ([IO.Path]::GetTempPath()) "uid0003yu-attest-$nonce.py"
    $outputPath = Join-Path ([IO.Path]::GetTempPath()) "uid0003yu-attest-$nonce.json"
    if ((Test-Path -LiteralPath $scriptPath) -or (Test-Path -LiteralPath $outputPath)) { throw 'Attestation path collision' }
    $outputJson = $outputPath | ConvertTo-Json -Compress
    $rootJson = $Route.Entry.PackageRoot | ConvertTo-Json -Compress
    $requiredJson = @($RequiredModuleNames) | ConvertTo-Json -Compress
    $remoteSource = @"
import json, os, pathlib, sys
output_path = $outputJson
package_root = pathlib.Path($rootJson).resolve()
required = $requiredJson
rows = []
for name, module in tuple(sys.modules.items()):
    if module is None:
        continue
    file_value = getattr(module, '__file__', None)
    spec = getattr(module, '__spec__', None)
    origin = getattr(spec, 'origin', None) if spec is not None else None
    candidate = file_value or origin
    if not candidate or candidate in ('built-in', 'frozen'):
        continue
    named_runtime_module = name == 'ida_pro_mcp' or name.startswith('ida_pro_mcp.') or name == 'zeromcp' or name.startswith('zeromcp.')
    try:
        resolved = pathlib.Path(candidate).resolve()
        under_root = resolved == package_root or package_root in resolved.parents
    except OSError:
        under_root = False
    if not under_root and not named_runtime_module:
        continue
    rows.append({'name': name, 'object_id': id(module), 'file': str(pathlib.Path(file_value).resolve()) if file_value else None,
                 'spec_origin': str(pathlib.Path(origin).resolve()) if origin and origin not in ('built-in','frozen') else origin,
                 'loader_type': type(getattr(spec, 'loader', None)).__module__ + '.' + type(getattr(spec, 'loader', None)).__qualname__})
missing = sorted(set(required) - {row['name'] for row in rows})
payload = {'pid': os.getpid(), 'executable': str(pathlib.Path(sys.executable).resolve()),
           'prefix': str(pathlib.Path(sys.prefix).resolve()), 'base_prefix': str(pathlib.Path(sys.base_prefix).resolve()),
           'package_root': str(package_root), 'required': required, 'missing': missing,
           'modules': sorted(rows, key=lambda row: row['name'])}
fd = os.open(output_path, os.O_WRONLY | os.O_CREAT | os.O_EXCL, 0o600)
with os.fdopen(fd, 'w', encoding='utf-8', newline='\n') as stream:
    json.dump(payload, stream, sort_keys=True, separators=(',', ':'))
    stream.flush()
    os.fsync(stream.fileno())
"@
    [IO.File]::WriteAllText($scriptPath,$remoteSource,[Text.UTF8Encoding]::new($false))
    try {
        $launcher = 'import sys; sys.remote_exec(int(sys.argv[1]), sys.argv[2])'
        & $Route.Entry.BasePythonPath -c $launcher ([string]$Generation.Pid) $scriptPath
        if ($LASTEXITCODE -ne 0) { throw "$Role remote attestation launcher failed" }
        $deadline = [DateTime]::UtcNow.AddSeconds(15)
        while (-not (Test-Path -LiteralPath $outputPath)) {
            if ([DateTime]::UtcNow -ge $deadline) { throw "$Role runtime attestation timed out" }
            Start-Sleep -Milliseconds 100
        }
        Assert-SameGeneration (Get-ExactProcessGeneration $Generation.Role $Generation.Pid) $Generation "$Role post-attestation"
        $raw = [IO.File]::ReadAllText($outputPath,[Text.Encoding]::UTF8)
        $attestation = $raw | ConvertFrom-Json -Depth 32
        if ([int]$attestation.pid -ne $Generation.Pid -or $attestation.executable -cne $Generation.ExecutablePath) {
            throw "$Role attestation did not execute inside the bound process"
        }
        if ($attestation.package_root -cne $Route.Entry.PackageRoot -or @($attestation.missing).Count -ne 0) {
            throw "$Role loaded-module set/source root is incomplete or foreign"
        }
        $seen = @{}
        foreach ($module in @($attestation.modules)) {
            if ([long]$module.object_id -le 0 -or [string]::IsNullOrWhiteSpace([string]$module.loader_type)) {
                throw "$Role returned an invalid live module object"
            }
            $file = (Resolve-Path -LiteralPath ([string]$module.file)).Path
            $origin = (Resolve-Path -LiteralPath ([string]$module.spec_origin)).Path
            if ($file -cne $origin -or -not $file.StartsWith($Route.Entry.PackageRoot,[StringComparison]::OrdinalIgnoreCase)) {
                throw "$Role module file/spec origin escaped the bound package root"
            }
            $seen[[string]$module.name] = [pscustomobject]@{
                Name=[string]$module.name; ObjectId=[long]$module.object_id; File=$file; SpecOrigin=$origin
                LoaderType=[string]$module.loader_type; SHA256=(Get-FileHash -Algorithm SHA256 -LiteralPath $file).Hash
            }
        }
        foreach ($requiredName in $RequiredModuleNames) {
            if (-not $seen.ContainsKey($requiredName)) { throw "$Role did not load required module $requiredName" }
        }
        return [pscustomobject]@{ Role=$Role; Generation=$Generation; RawSHA256=([Convert]::ToHexString([Security.Cryptography.SHA256]::HashData([Text.Encoding]::UTF8.GetBytes($raw)))); Modules=$seen }
    } finally {
        Remove-Item -LiteralPath $scriptPath,$outputPath -Force -ErrorAction SilentlyContinue
    }
}

function Assert-SameLoadedModules($Actual,$Expected,[string]$Label) {
    Assert-SameGeneration $Actual.Generation $Expected.Generation "$Label generation"
    if ($Actual.Modules.Count -ne $Expected.Modules.Count) { throw "$Label loaded-module count drift" }
    foreach ($name in $Expected.Modules.Keys) {
        if (-not $Actual.Modules.ContainsKey($name)) { throw "$Label missing loaded module $name" }
        foreach ($field in @('Name','ObjectId','File','SpecOrigin','LoaderType','SHA256')) {
            if ($Actual.Modules[$name].$field -cne $Expected.Modules[$name].$field) { throw "$Label module drift: $name/$field" }
        }
    }
}

$L2RequiredModules = @('ida_pro_mcp.idalib_supervisor','zeromcp.mcp')
$WorkerRequiredModules = @(
    'ida_pro_mcp.idalib_server','ida_pro_mcp.idalib_session_manager','ida_pro_mcp.worker_lifecycle',
    'ida_pro_mcp.ida_mcp.api_core','ida_pro_mcp.ida_mcp.api_analysis','ida_pro_mcp.ida_mcp.api_modify',
    'ida_pro_mcp.ida_mcp.api_stack','ida_pro_mcp.ida_mcp.api_types','ida_pro_mcp.ida_mcp.api_memory',
    'ida_pro_mcp.ida_mcp.utils','ida_pro_mcp.ida_mcp.zeromcp.mcp'
)
$L2Modules0 = Get-LiveLoadedModuleAttestation $Route0.L2 $Route0 $L2RequiredModules 'L2'
~~~

## Removed Block R008

- SHA256: `C9E199EF489835463D40040EC231A9AFF639D4A70259EF05750041908F9DA7B8`
- Language: `powershell`
- Bytes: `3226`
- First recovered timestamp: `2026-08-06T23:27:55.928Z`
- Session provenance: rollout-2026-08-06T18-14-21-019fd924-46f7-7000-b0f9-a0aadf64fceb.jsonl line 194205 (2026-08-06T23:27:55.928Z)

~~~powershell
$CanonicalIdbPath = (Resolve-Path -LiteralPath 'E:\NTK\Resources\NexusTK\NexusTK.exe.i64').Path
function Get-TextSHA256([string]$Text) {
    $sha = [Security.Cryptography.SHA256]::Create()
    try { return ([BitConverter]::ToString($sha.ComputeHash([Text.Encoding]::UTF8.GetBytes($Text)))).Replace('-','') }
    finally { $sha.Dispose() }
}
function Get-PathKey([string]$Path) { return ([IO.Path]::GetFullPath($Path)).TrimEnd('\').ToLowerInvariant() }
function Assert-Hex64([string]$Value,[string]$Label) {
    if ($Value -cnotmatch '^[0-9A-F]{64}$') { throw "$Label is not an uppercase SHA256" }
}
function Get-ValidatedModuleManifest($Rows,[string]$SourceRoot,[string[]]$RequiredNames,[string]$Label) {
    $root = (Resolve-Path -LiteralPath $SourceRoot).Path
    $normalized = @()
    $seen = @{}
    foreach ($row in @($Rows)) {
        $name = [string]$row.sys_modules_name
        $resolved = (Resolve-Path -LiteralPath ([string]$row.resolved_path)).Path
        if ([string]::IsNullOrWhiteSpace($name) -or $seen.ContainsKey($name)) { throw "$Label duplicate/blank module name" }
        if ((Get-PathKey ([string]$row.file)) -cne (Get-PathKey $resolved) -or
            (Get-PathKey ([string]$row.spec_origin)) -cne (Get-PathKey $resolved) -or
            -not (Get-PathKey $resolved).StartsWith((Get-PathKey $root),[StringComparison]::Ordinal)) {
            throw "$Label module source-root/file/spec mismatch: $name"
        }
        $item = Get-Item -LiteralPath $resolved
        if ([long]$row.size -ne [long]$item.Length -or [string]$row.module_id -cnotmatch '^0x[0-9a-f]+$') {
            throw "$Label module size/object mismatch: $name"
        }
        Assert-Hex64 ([string]$row.sha256) "$Label/$name"
        if ((Get-FileHash -Algorithm SHA256 -LiteralPath $resolved).Hash -cne [string]$row.sha256) {
            throw "$Label module byte hash mismatch: $name"
        }
        foreach ($field in @('mtime_ns','ctime_ns')) {
            if ([string]::IsNullOrWhiteSpace([string]$row.$field)) { throw "$Label missing $field for $name" }
        }
        $seen[$name]=$true
        $normalized += [ordered]@{
            Name=$name; ModuleId=[string]$row.module_id; Path=$resolved; Size=[long]$row.size
            MTimeNS=[string]$row.mtime_ns; CTimeNS=[string]$row.ctime_ns; SHA256=[string]$row.sha256
        }
    }
    foreach ($required in $RequiredNames) { if (-not $seen.ContainsKey($required)) { throw "$Label missing module $required" } }
    return @($normalized | Sort-Object Name)
}
function Assert-ExactStableRuntime($Actual,$Baseline,[string]$Label) {
    if ($Actual.ListenerNonce -ceq $Baseline.ListenerNonce -or $Actual.WorkerNonce -ceq $Baseline.WorkerNonce) {
        throw "$Label attestation nonce was reused"
    }
    if ([DateTimeOffset]$Actual.ListenerAt -le [DateTimeOffset]$Baseline.ListenerAt -or
        [DateTimeOffset]$Actual.WorkerAt -le [DateTimeOffset]$Baseline.WorkerAt) {
        throw "$Label attestation time did not advance"
    }
    if (($Actual.Stable | ConvertTo-Json -Depth 64 -Compress) -cne ($Baseline.Stable | ConvertTo-Json -Depth 64 -Compress)) {
        throw "$Label listener/redirector/worker/session/module manifest drift"
    }
}
~~~

## Removed Block R009

- SHA256: `2BCF1959BF154F05CF7E886E6952A1BF30BCD517620BD527EF9CE00684D4F25E`
- Language: `powershell`
- Bytes: `5741`
- First recovered timestamp: `2026-08-07T00:08:05.697Z`
- Session provenance: rollout-2026-08-06T18-14-21-019fd924-46f7-7000-b0f9-a0aadf64fceb.jsonl line 194741 (2026-08-07T00:08:05.697Z)

~~~powershell
$SaveGuard = [pscustomobject]@{ Attempted=$false }
$Transaction = $null
$PreSaveFailure = $null
try {
    $PreTransactionTuple = Get-ClosedExclusiveIdbTuple $p
    Assert-ExactTuple $PreTransactionTuple $P0 'pre-transaction-authority'
    $Transaction = Open-IdbRole @TransactionParameters

    $RawPreI01 = Invoke-RBYU $Transaction 'pre-I01'
    $PreI01 = Assert-RBYU14 $RawPreI01 PRE $null 'pre-I01'
    $FrozenProtection = $PreI01.Protection

    $CollisionLookup = Invoke-RoleTool $Transaction 'lookup_funcs' $CollisionArguments 'collision-lookup'
    $null = Assert-CollisionLookupResponse $CollisionLookup
    $PureDryRun = Invoke-RoleTool $Transaction 'rename' $PureDryRunArguments 'pure-dry-run'
    $null = Assert-OneActionResponse $PureDryRun 'rename' 'RankingCategoryRecordRangeCopyConstructDeep' $true 'pure-dry-run'
    $RawAfterDry = Invoke-RBYU $Transaction 'post-pure-dry-run'
    $AfterDry = Assert-RBYU14 $RawAfterDry PRE $FrozenProtection 'post-pure-dry-run'
    Assert-RBYUExactEqual $AfterDry $PreI01 'pure-dry-run-no-side-effect'

    $I01 = Invoke-RoleTool $Transaction 'rename' $I01Arguments 'I01'
    $null = Assert-OneActionResponse $I01 'rename' 'RankingCategoryRecordRangeCopyConstructDeep' $false 'I01'
    $RawPostI01 = Invoke-RBYU $Transaction 'post-I01'
    $PostI01 = Assert-RBYU14 $RawPostI01 POST_I01 $FrozenProtection 'post-I01'

    $I02 = Invoke-RoleTool $Transaction 'set_type' $I02Arguments 'I02'
    $null = Assert-OneActionResponse $I02 'set_type' ([string]$I02Arguments.edits.signature) $false 'I02'
    $RawPostI02A = Invoke-RBYU $Transaction 'post-I02-a'
    $PostI02A = Assert-RBYU14 $RawPostI02A POST_I02 $FrozenProtection 'post-I02-a'
    $RawPostI02B = Invoke-RBYU $Transaction 'post-I02-b'
    $PostI02B = Assert-RBYU14 $RawPostI02B POST_I02 $FrozenProtection 'post-I02-b'
    Assert-RBYUExactEqual $PostI02B $PostI02A 'deterministic-complete-ten-row-frame'

    $I03 = Invoke-RoleTool $Transaction 'set_function_comments' $I03Arguments 'I03'
    $null = Assert-OneActionResponse $I03 'set_function_comments' ([string]$I03Arguments.items.comment) $false 'I03'
    $RawPostI03 = Invoke-RBYU $Transaction 'post-I03'
    $PostI03 = Assert-RBYU14 $RawPostI03 POST_I03 $FrozenProtection 'post-I03'
    $RawPreSave = Invoke-RBYU $Transaction 'pre-save'
    $PreSavePoststate = Assert-RBYU14 $RawPreSave FINAL $FrozenProtection 'pre-save'
    Assert-RBYUExactEqual $PreSavePoststate $PostI03 'post-I03-versus-pre-save'
} catch {
    $PreSaveFailure = $_.Exception.ToString()
}

if ($null -ne $PreSaveFailure) {
    if ($null -ne $Transaction) { $null = Retire-IdbRole $Transaction 'pre-save-failure-transaction' }
    $PreSaveDisk = Get-ClosedExclusiveIdbTuple $p
    Assert-ExactTuple $PreSaveDisk $P0 'pre-save-failure-disk'
    $PreSaveVerifier = Invoke-NamedVerifier $RoleDefinitions.VerifyPreSaveFailure PRE $P0 $DiagnosticRBYU.Protection 'pre-save-failure-verifier'
    $ClassifierOutcome = 'pre-save-failure-not-persisted'
    if ($SaveGuard.Attempted -ne $false) { throw 'Pre-save branch attempted idb_save' }
    throw "PRE_SAVE_FAILURE_VERIFIED_NO_PERSISTENCE: $PreSaveFailure"
}

$SaveClassification = Invoke-SoleIdbSave $Transaction $SaveGuard
if ($SaveGuard.Attempted -ne $true) { throw 'Sole-save guard did not record the attempt' }
$TransactionRetirement = Retire-IdbRole $Transaction 'post-save-transaction'
$S1 = $TransactionRetirement.ClosedTuple
$S1Confirm = $null
$NamedVerifierRBYU = $null
$ClassifierOutcome = $null
$NamedVerifier = $null

switch ([string]$SaveClassification.Classifier) {
    'SUCCESS' {
        if (Test-ExactTupleEqual $S1 $P0) { throw 'Successful save produced P0 rather than a saved identity' }
        $NamedVerifier = Invoke-NamedVerifier $RoleDefinitions.VerifySuccess FINAL $S1 $FrozenProtection 'success-verifier'
        $S1Confirm = $NamedVerifier.ClosedTuple
        $NamedVerifierRBYU = $NamedVerifier.Readback
        $ClassifierOutcome = 'success'
    }
    'EXPLICIT_FAILURE' {
        if (Test-ExactTupleEqual $S1 $P0) {
            $NamedVerifier = Invoke-NamedVerifier $RoleDefinitions.VerifySaveFailure PRE $P0 $FrozenProtection 'explicit-failure-prestate-verifier'
            $S1Confirm = $NamedVerifier.ClosedTuple
            $NamedVerifierRBYU = $NamedVerifier.Readback
            $ClassifierOutcome = 'explicit-failure-not-persisted'
        } else {
            $NamedVerifier = Invoke-NamedVerifier $RoleDefinitions.VerifySaveFailure FINAL $S1 $FrozenProtection 'explicit-failure-saved-verifier'
            $S1Confirm = $NamedVerifier.ClosedTuple
            $NamedVerifierRBYU = $NamedVerifier.Readback
            $ClassifierOutcome = 'failing-saved'
        }
    }
    'INDETERMINATE' {
        if (Test-ExactTupleEqual $S1 $P0) {
            $NamedVerifier = Invoke-NamedVerifier $RoleDefinitions.VerifyIndeterminate PRE $P0 $FrozenProtection 'indeterminate-prestate-verifier'
            $S1Confirm = $NamedVerifier.ClosedTuple
            $NamedVerifierRBYU = $NamedVerifier.Readback
            $ClassifierOutcome = 'indeterminate-not-persisted'
        } else {
            $NamedVerifier = Invoke-NamedVerifier $RoleDefinitions.VerifyIndeterminate FINAL $S1 $FrozenProtection 'indeterminate-saved-verifier'
            $S1Confirm = $NamedVerifier.ClosedTuple
            $NamedVerifierRBYU = $NamedVerifier.Readback
            $ClassifierOutcome = 'indeterminate-saved'
        }
    }
    default { throw 'Undefined or foreign save classifier outcome' }
}

if ([string]::IsNullOrWhiteSpace($ClassifierOutcome) -or $null -eq $NamedVerifier -or
    $null -eq $S1Confirm -or $null -eq $NamedVerifierRBYU) {
    throw 'Classifier did not construct S1/S1Confirm/NamedVerifierRBYU/exactly one outcome'
}
~~~

## Removed Block R010

- SHA256: `A1EE4934C9CDB1590446D329D0160C82520D3ED1F2DC3081D6469C7A132CADE5`
- Language: `powershell`
- Bytes: `1444`
- First recovered timestamp: `2026-08-07T00:08:05.697Z`
- Session provenance: rollout-2026-08-06T18-14-21-019fd924-46f7-7000-b0f9-a0aadf64fceb.jsonl line 194741 (2026-08-07T00:08:05.697Z)

~~~powershell
function New-AttributableSavedTuple($Candidate,$Repeated,$Prestate,$VerifierReadback,[string]$Outcome) {
    if ($Outcome -notin @('success','failing-saved','indeterminate-saved')) { throw 'Outcome cannot establish persistence attribution' }
    Assert-ExactTuple $Repeated $Candidate "$Outcome repeated saved tuple"
    if (Test-ExactTupleEqual $Candidate $Prestate) { throw "$Outcome candidate is P0, not a saved identity" }
    if ($null -eq $VerifierReadback -or $VerifierReadback.State -cne 'FINAL' -or
        @($VerifierReadback.Structured.Keys).Count -ne 14) {
        throw "$Outcome verifier did not assert all fourteen RB-YU payloads as complete poststate"
    }
    [pscustomobject]@{
        Classification=$Outcome; Path=$Candidate.Path; Length=[long]$Candidate.Length; SHA256=$Candidate.SHA256
        LastWriteTimeUtc=$Candidate.LastWriteTimeUtc; LastWriteTimeUtcTicks=[long]$Candidate.LastWriteTimeUtcTicks
    }
}

$AttributableSavedTuple = $null
if ($ClassifierOutcome -in @('success','failing-saved','indeterminate-saved')) {
    $RecordedSavedTuple = New-AttributableSavedTuple $S1 $S1Confirm $P0 $NamedVerifierRBYU $ClassifierOutcome
    Set-Variable -Name AttributableSavedTuple -Option ReadOnly -Value $RecordedSavedTuple
} elseif ($ClassifierOutcome -notin @('explicit-failure-not-persisted','indeterminate-not-persisted')) {
    throw 'Exactly one permitted classifier outcome was not constructed'
}
~~~

## Removed Block R011

- SHA256: `96104FB6E56358A2CA6554A639F848B6FF46DBF431BE8C28D0BED70508AA0E9F`
- Language: `powershell`
- Bytes: `3875`
- First recovered timestamp: `2026-08-07T00:09:06.415Z`
- Session provenance: rollout-2026-08-06T18-14-21-019fd924-46f7-7000-b0f9-a0aadf64fceb.jsonl line 194756 (2026-08-07T00:09:06.415Z); rollout-2026-08-06T18-14-21-019fd924-46f7-7000-b0f9-a0aadf64fceb.jsonl line 194757 (2026-08-07T00:09:06.481Z)

~~~powershell
function Assert-Throws([scriptblock]$Body,[string]$Label) {
    $threw = $false
    try { & $Body | Out-Null } catch { $threw = $true }
    if (-not $threw) { throw "Negative fixture unexpectedly passed: $Label" }
}
function Assert-ExactPhaseOrder([string[]]$Actual,[string[]]$Expected,[string]$Label) {
    if ($Actual.Count -ne $Expected.Count -or ($Actual -join '|') -cne ($Expected -join '|')) { throw "$Label phase order/cardinality mismatch" }
}
function Invoke-UID0003YUNegativeFixtures {
    $requiredOrder = @('diagnostic-retired','P0-confirmed','B0-confirmed','transaction-open','pre-I01','post-I01','post-I02-a','post-I02-b','post-I03','pre-save')
    Assert-Throws { Assert-ExactPhaseOrder @('transaction-open','P0-confirmed','B0-confirmed') $requiredOrder 'pre-B0 mutation' } 'transaction before P0/B0'
    Assert-Throws { Assert-ExactPhaseOrder @('diagnostic-retired','P0-confirmed','B0-confirmed','transaction-open','pre-I01','post-I02-a','post-I02-b','post-I03','pre-save') $requiredOrder 'missing RB-YU' } 'missing post-I01 RB-YU'
    Assert-Throws { Assert-ExactPhaseOrder @('diagnostic-retired','P0-confirmed','B0-confirmed','transaction-open','pre-I01','post-I01','post-I02-a','post-I02-a','post-I02-b','post-I03','pre-save') $requiredOrder 'duplicate RB-YU' } 'duplicate post-I02-a RB-YU'
    Assert-Throws { Assert-ExactPhaseOrder @('diagnostic-retired','P0-confirmed','B0-confirmed','transaction-open','pre-I01','post-I02-a','post-I01','post-I02-b','post-I03','pre-save') $requiredOrder 'out-of-order RB-YU' } 'out-of-order RB-YU'
    $usedGuard = [pscustomobject]@{Attempted=$true}
    Assert-Throws { Enter-OneSaveGuard $usedGuard } 'global one-save retry'
    $foreignResponse = [pscustomobject]@{
        Method='tools/call'; Tool='rename'; Arguments=[ordered]@{}; Request=[pscustomobject]@{id=1;params=[pscustomobject]@{name='rename';arguments=[pscustomobject]@{}}}
        Envelope=[pscustomobject]@{jsonrpc='2.0';id=2;result=[pscustomobject]@{isError=$false;structuredContent=[pscustomobject]@{}}}
    }
    Assert-Throws { Get-McpToolStructuredContent $foreignResponse 'rename' ([ordered]@{}) 'foreign-response' } 'foreign request ID'
    $frameA = [pscustomobject]@{Structured=[ordered]@{Frame=[pscustomobject]@{rows=@('first','last','destination')}}}
    $frameB = [pscustomobject]@{Structured=[ordered]@{Frame=[pscustomobject]@{rows=@('first','last','arg_8')}}}
    Assert-Throws { Assert-RBYUExactEqual $frameB $frameA 'frame-drift' } 'frame drift'
    $commentA = [pscustomobject]@{Structured=[ordered]@{Comments=[pscustomobject]@{function_regular=$I03Arguments.items.comment}}}
    $commentB = [pscustomobject]@{Structured=[ordered]@{Comments=[pscustomobject]@{function_regular='foreign'}}}
    Assert-Throws { Assert-RBYUExactEqual $commentB $commentA 'comment-drift' } 'comment drift'
    Assert-Throws { if ([string]::IsNullOrWhiteSpace($null)) { throw 'undefined classifier' } } 'undefined classifier state'
    Assert-Throws { if ($true) { throw 'retired worker/socket/session survived' } } 'surviving retirement route'
    $fixtureP0 = [pscustomobject]@{Path='C:\fixture\canonical.i64';Length=10;SHA256=('A'*64);LastWriteTimeUtc='2026-01-01T00:00:00.0000000Z';LastWriteTimeUtcTicks=1}
    $fixtureThird = [pscustomobject]@{Path='C:\fixture\canonical.i64';Length=10;SHA256=('B'*64);LastWriteTimeUtc='2026-01-01T00:00:00.0000000Z';LastWriteTimeUtcTicks=2}
    Assert-Throws { Assert-ExactTuple $fixtureThird $fixtureP0 'third-disk-identity' } 'third disk identity'
    Assert-Throws { if ($null -eq $null) { throw 'unauthorized restore tuple' } } 'unauthorized restore'
    return 'UID0003YU_NEGATIVE_FIXTURES_PASSED'
}
$UID0003YUNegativeFixtureResult = Invoke-UID0003YUNegativeFixtures
if ($UID0003YUNegativeFixtureResult -cne 'UID0003YU_NEGATIVE_FIXTURES_PASSED') { throw 'Negative fixture package did not pass' }
~~~

## Removed Block R012

- SHA256: `5845782AA50731E48E688CA873B17053D4F81D00792623C10C4FFAC038FE0432`
- Language: `powershell`
- Bytes: `44984`
- First recovered timestamp: `2026-08-07T02:51:20.591Z`
- Session provenance: rollout-2026-08-06T18-14-21-019fd924-46f7-7000-b0f9-a0aadf64fceb.jsonl line 197089 (2026-08-07T02:51:20.591Z); rollout-2026-08-06T18-14-21-019fd924-46f7-7000-b0f9-a0aadf64fceb.jsonl line 197090 (2026-08-07T02:51:20.661Z)

~~~powershell
if (-not ('UID0003YUAuth.FrozenContract' -as [type])) {
    Add-Type -TypeDefinition @'
using System;
namespace UID0003YUAuth {
    public sealed class FrozenContract {
        public readonly string Name;
        public readonly string CanonicalJson;
        public readonly string SHA256;
        public FrozenContract(string name,string json,string sha256) { Name=name; CanonicalJson=json; SHA256=sha256; }
    }
    public sealed class HeldTuple {
        public readonly string Path;
        public readonly long Length;
        public readonly string SHA256;
        public readonly long LastWriteTimeUtcTicks;
        public readonly string FileIdentity;
        public HeldTuple(string path,long length,string sha256,long ticks,string identity) {
            Path=path; Length=length; SHA256=sha256; LastWriteTimeUtcTicks=ticks; FileIdentity=identity;
        }
    }
}
'@
}

function Get-AuthSHA256([byte[]]$Bytes) {
    $sha=[Security.Cryptography.SHA256]::Create()
    try { return ([BitConverter]::ToString($sha.ComputeHash($Bytes))).Replace('-','') }
    finally { $sha.Dispose() }
}
function Get-AuthTextSHA256([string]$Text) { return Get-AuthSHA256 ([Text.Encoding]::UTF8.GetBytes($Text)) }
function ConvertTo-AuthCanonicalNode($Value) {
    if($null-eq$Value){return $null}
    if($Value-is[string]-or$Value-is[bool]-or$Value-is[ValueType]){return $Value}
    if($Value-is[Collections.IDictionary]){$o=[ordered]@{};foreach($k in @($Value.Keys|ForEach-Object{[string]$_}|Sort-Object)){$o[$k]=ConvertTo-AuthCanonicalNode $Value[$k]};return $o}
    if($Value-is[Collections.IEnumerable]-and$Value-isnot[string]){return [object[]]@($Value|ForEach-Object{ConvertTo-AuthCanonicalNode $_})}
    $o=[ordered]@{};foreach($p in @($Value.PSObject.Properties|Sort-Object Name)){$o[$p.Name]=ConvertTo-AuthCanonicalNode $p.Value};return $o
}
function Get-AuthCanonicalJson($Value){return ((ConvertTo-AuthCanonicalNode $Value)|ConvertTo-Json -Depth 100 -Compress)}
function ConvertFrom-AuthStrictJson([string]$Raw,[string]$Label) {
    if([string]::IsNullOrWhiteSpace($Raw)){throw "$Label|EMPTY_JSON"}
    try{[UID0003YU.StrictJson]::AssertNoDuplicateMembers($Raw)}catch{throw "$Label|RAW_DUPLICATE_JSON|$($_.Exception.GetBaseException().Message)"}
    try{return $Raw|ConvertFrom-Json}catch{throw "$Label|INVALID_JSON|$($_.Exception.GetBaseException().Message)"}
}
function Assert-AuthKeys($Value,[string[]]$Expected,[string]$Label){
    if($null-eq$Value-or$Value-is[string]-or$Value-is[ValueType]-or$Value-is[Array]){throw "$Label|NOT_OBJECT"}
    $actual=@($Value.PSObject.Properties.Name|Sort-Object);$want=@($Expected|Sort-Object)
    if(($actual-join '|')-cne($want-join '|')){throw "$Label|KEY_DRIFT|actual=$($actual-join ',')|expected=$($want-join ',')"}
}
function New-AuthFrozenContract([string]$Name,$Value){
    $json=Get-AuthCanonicalJson $Value
    return [UID0003YUAuth.FrozenContract]::new($Name,$json,(Get-AuthTextSHA256 $json))
}
function Read-AuthFrozenContract([UID0003YUAuth.FrozenContract]$Contract,[string]$Name){
    if($null-eq$Contract-or$Contract.Name-cne$Name-or(Get-AuthTextSHA256 $Contract.CanonicalJson)-cne$Contract.SHA256){throw "FROZEN_CONTRACT_MUTATION:$Name"}
    return ConvertFrom-AuthStrictJson $Contract.CanonicalJson "frozen-$Name"
}
function New-AuthTuple([string]$Path,[long]$Length,[string]$SHA256,[long]$Ticks,[string]$Identity){
    if($SHA256-cnotmatch'^[0-9A-F]{64}$'-or$Ticks-le 0-or[string]::IsNullOrWhiteSpace($Identity)){throw 'TYPED_TUPLE_INVALID'}
    return [UID0003YUAuth.HeldTuple]::new($Path,$Length,$SHA256,$Ticks,$Identity)
}
function Assert-AuthTuple([UID0003YUAuth.HeldTuple]$Actual,[UID0003YUAuth.HeldTuple]$Expected,[string]$Label){
    foreach($f in @('Path','Length','SHA256','LastWriteTimeUtcTicks','FileIdentity')){if([string]$Actual.$f-cne[string]$Expected.$f){throw "$Label|TUPLE_DRIFT|$f"}}
}

$AuthSchemaHashes=[ordered]@{
    runtime_attestation='B07CA20D3A99752374BF8E96FF44C28542708C1FF4741E9D71E78E71F0A71252';server_health='A671F932AAA8F8C2375273DCB5A043518CCAAADC9EA4A05B322544B4BF80365B'
    idb_open='2B6AA209DFD45FBB7152CED3B01FEFF89A40067DA3864921711BD52B72D173A7';idb_list='257451A6E096AEB78F47F8925A27DAE7454E29C2D114F7C1DD7581AC1EF3C403'
    lookup_funcs='0FEE1BA456CBE9456BC1AA72E33F6050C612612074811D4964654B373E540EBF';stack_frame='F96768D21E784255720D88E62C18E887C6D9D2F489658CCB761AE90F89B30FFA'
    get_comments='F96768D21E784255720D88E62C18E887C6D9D2F489658CCB761AE90F89B30FFA';inspect_items='F96768D21E784255720D88E62C18E887C6D9D2F489658CCB761AE90F89B30FFA'
    get_bytes='A82BC69B8E13FB37BAFDF38CF8D97A7B0D65EBFBB70AF7B7C407021FA9998AC0';disasm='D55124BD3B3BE86DCD9F4DCDCCD346CB019D56CDBF7BD6195D13CAABC3C72CF6'
    xrefs_to='9F321F1FCD074FC3C91B99FE9CB9144951AC20BD83857468553944314793BF87';xref_query='18E02E6E6A47A0FEBF0C5DC8386F4CCDDA97B7561EAAEC93FE1EDE6216673868'
    find='4819B0F3B080569EF3C4E69E1B0F250593055949F7DA51FF33958A1A39AD4E79';find_bytes='0A6428809874940C8E0E5AD4CA55FDC9844BC97391BB1E517A7F47FAEA1D3439'
    type_inspect='020841CD93532339E6E7648F44082F80C594D6AC8793D2F563228111E7A3258A';rename='C9075D7FABCE19A253C58F9ACCFE13EC124C37C39E73E886BC254F576E3D98E6'
    set_type='90301A903C7A3DD6E3006193ED5C94AAADE1BCF5F58D71E2400013EF835A165E';set_function_comments='1757AB7572624FA067B490A7A4D735B433B6ADAE58701130BB4D61F671B973BB'
    idb_save='02F1C044A6F865EA6913E9C22D63CBD2EC5501F8DBA7BFBE4F18249C762A7502'
}
$AuthContracts=New-AuthFrozenContract 'UID0003YUContracts' ([ordered]@{
    Schemas=$AuthSchemaHashes
    RoleDefinitions=$RoleDefinitions
    Collision=(Read-AuthFrozenContract $CollisionArgumentsContract 'CollisionArguments')
    DryRun=(Read-AuthFrozenContract $PureDryRunArgumentsContract 'PureDryRunArguments')
    I01=(Read-AuthFrozenContract $I01ArgumentsContract 'I01Arguments')
    I02=(Read-AuthFrozenContract $I02ArgumentsContract 'I02Arguments')
    I03=(Read-AuthFrozenContract $I03ArgumentsContract 'I03Arguments')
    Phases=@('pre-I01','post-I01','post-I02-a','post-I02-b','post-I03','pre-save')
})

function New-AuthCounters(){return [ordered]@{Transport=0;Open=0;Readback=0;Save=0;Classifier=0;Retirement=0;Verifier=0;Journal=0;Restore=0}}
function Add-AuthCount($Counters,[string]$Name){if(-not$Counters.Contains($Name)){throw "UNKNOWN_COUNTER:$Name"};$Counters[$Name]=[int]$Counters[$Name]+1}
function Get-AuthVector($Counters){return @($Counters.Transport,$Counters.Open,$Counters.Readback,$Counters.Save,$Counters.Classifier,$Counters.Retirement,$Counters.Verifier,$Counters.Journal,$Counters.Restore)-join '/'}

function Get-AuthStreamIdentity($Stream,[string]$Injected){
    if(-not[string]::IsNullOrWhiteSpace($Injected)){return $Injected}
    if($Stream-is[IO.FileStream]){return [UID0003YU.NativeFileTime]::GetFileIdentity($Stream.SafeFileHandle)}
    return "memory:$([Runtime.CompilerServices.RuntimeHelpers]::GetHashCode($Stream))"
}
function Read-AuthStreamText($Stream){$Stream.Position=0;$r=[IO.StreamReader]::new($Stream,[Text.UTF8Encoding]::new($false),$true,1024,$true);try{return $r.ReadToEnd()}finally{$r.Dispose()}}
function Write-AuthStreamText($Stream,[string]$Text){$bytes=[Text.UTF8Encoding]::new($false).GetBytes($Text);$Stream.Position=0;$Stream.SetLength(0);$Stream.Write($bytes,0,$bytes.Length);$Stream.Flush()}
function Protect-AuthKey([byte[]]$Key){return [Convert]::ToBase64String([Security.Cryptography.ProtectedData]::Protect($Key,$null,[Security.Cryptography.DataProtectionScope]::CurrentUser))}
function Unprotect-AuthKey([string]$Text){return [Security.Cryptography.ProtectedData]::Unprotect([Convert]::FromBase64String($Text),$null,[Security.Cryptography.DataProtectionScope]::CurrentUser)}
function Get-AuthHmac([byte[]]$Key,[string]$Text){$h=[Security.Cryptography.HMACSHA256]::new($Key);try{return ([BitConverter]::ToString($h.ComputeHash([Text.Encoding]::UTF8.GetBytes($Text)))).Replace('-','')}finally{$h.Dispose()}}

function Open-AuthAuthority($Context,$Counters){
    $raw=&$Context.Journal 'open' $null
    Assert-AuthKeys $raw @('AnchorIdentity','AnchorPath','AnchorStream','JournalIdentity','JournalPath','JournalStream') 'AUTHORITY_OPEN_RAW'
    if($null-eq$raw.AnchorStream-or$null-eq$raw.JournalStream){throw 'AUTHORITY_STREAM_MISSING'}
    $anchorIdentity=Get-AuthStreamIdentity $raw.AnchorStream ([string]$raw.AnchorIdentity)
    $journalIdentity=Get-AuthStreamIdentity $raw.JournalStream ([string]$raw.JournalIdentity)
    $anchorText=Read-AuthStreamText $raw.AnchorStream
    if([string]::IsNullOrWhiteSpace($anchorText)){
        $key=[byte[]]::new(32);[Security.Cryptography.RandomNumberGenerator]::Create().GetBytes($key)
        $anchor=[ordered]@{Version=1;AuthorityId=[guid]::NewGuid().ToString('N');AnchorIdentity=$anchorIdentity;JournalIdentity=$journalIdentity;AnchorPath=[string]$raw.AnchorPath;JournalPath=[string]$raw.JournalPath;KeyId=[guid]::NewGuid().ToString('N');ProtectedKey=Protect-AuthKey $key}
        Write-AuthStreamText $raw.AnchorStream (Get-AuthCanonicalJson $anchor)
        $raw.AnchorStream.Flush()
    }else{
        $anchor=ConvertFrom-AuthStrictJson $anchorText 'authority-anchor'
        Assert-AuthKeys $anchor @('AnchorIdentity','AnchorPath','AuthorityId','JournalIdentity','JournalPath','KeyId','ProtectedKey','Version') 'AUTHORITY_ANCHOR'
        if($anchor.Version-isnot[int]-or$anchor.Version-ne 1-or$anchor.AnchorIdentity-cne$anchorIdentity-or$anchor.JournalIdentity-cne$journalIdentity-or$anchor.AnchorPath-cne[string]$raw.AnchorPath-or$anchor.JournalPath-cne[string]$raw.JournalPath){throw 'AUTHORITY_ANCHOR_IDENTITY_OR_PATH_SWAP'}
        $key=Unprotect-AuthKey ([string]$anchor.ProtectedKey)
    }
    Add-AuthCount $Counters Journal
    return [pscustomobject]@{Raw=$raw;Anchor=$anchor;Key=$key;AnchorIdentity=$anchorIdentity;JournalIdentity=$journalIdentity;Records=@()}
}
function Close-AuthAuthority($Authority,$Context){
    if($null-eq$Authority){return}
    try{&$Context.Journal 'close' $Authority.Raw}finally{$Authority.Key=[byte[]]::new(0)}
}
function Get-AuthRecordPayload($Record){$o=[ordered]@{};foreach($n in @($Record.PSObject.Properties.Name|Where-Object{$_-cne'RecordHmacSHA256'}|Sort-Object)){$o[$n]=$Record.$n};return $o}
function Get-AuthAllowedTransitions(){return @{
    INIT=@('OPENED','ABORTED');OPENED=@('MUTATED','ABORTED');MUTATED=@('SAVE_CLAIMED','ABORTED');SAVE_CLAIMED=@('CLASSIFIED','INDETERMINATE');CLASSIFIED=@('VERIFIED','INDETERMINATE');INDETERMINATE=@('VERIFIED','RECOVERY_BLOCKED');VERIFIED=@('RESTORE_AUTHORIZED','RECOVERY_BLOCKED');RESTORE_AUTHORIZED=@('RESTORED','RECOVERY_BLOCKED');RESTORED=@('CLOSED');ABORTED=@('CLOSED');RECOVERY_BLOCKED=@('CLOSED')
}}
function Read-AuthJournal($Authority,[string]$Label){
    $text=Read-AuthStreamText $Authority.Raw.JournalStream
    $records=@();$previous='0'*64;$generation=0;$immutable=$null;$attempt=0
    foreach($line in @($text-split"`n"|Where-Object{$_-ne''})){
        $r=ConvertFrom-AuthStrictJson $line "$Label-journal-line"
        Assert-AuthKeys $r @('AuthorityId','BackupPath','B0','CanonicalPath','Cleanup','CreatedUtc','Disk','Generation','ImplementationContractSHA256','KeyId','P0','PreviousRecordHmacSHA256','RecordHmacSHA256','Restore','SaveAttemptCount','SaveRequestSHA256','SaveResponseSHA256','State','TransactionId','VerifierReceipts','Version') "$Label-record"
        if($r.Version-isnot[int]-or$r.Version-ne 2-or$r.Generation-isnot[int]-or$r.Generation-ne($generation+1)-or$r.PreviousRecordHmacSHA256-cne$previous-or$r.AuthorityId-cne$Authority.Anchor.AuthorityId-or$r.KeyId-cne$Authority.Anchor.KeyId){throw 'JOURNAL_CHAIN_OR_AUTHORITY_DRIFT'}
        $expected=Get-AuthHmac $Authority.Key (Get-AuthCanonicalJson (Get-AuthRecordPayload $r));if($expected-cne$r.RecordHmacSHA256){throw 'JOURNAL_HMAC_INVALID'}
        if($null-eq$immutable){$immutable=@($r.TransactionId,$r.CanonicalPath,$r.BackupPath,(Get-AuthCanonicalJson $r.P0),(Get-AuthCanonicalJson $r.B0),$r.ImplementationContractSHA256)-join'|'}elseif((@($r.TransactionId,$r.CanonicalPath,$r.BackupPath,(Get-AuthCanonicalJson $r.P0),(Get-AuthCanonicalJson $r.B0),$r.ImplementationContractSHA256)-join'|')-cne$immutable){throw 'JOURNAL_IMMUTABLE_ATTEMPT_FIELD_DRIFT'}
        if($r.SaveAttemptCount-isnot[int]-or$r.SaveAttemptCount-lt$attempt-or$r.SaveAttemptCount-gt 1){throw 'JOURNAL_SAVE_ATTEMPT_RESET_OR_DUPLICATE'}
        if($records.Count-gt 0){$allowed=(Get-AuthAllowedTransitions)[$records[-1].State];if($r.State-cne$records[-1].State-and$r.State-notin$allowed){throw "JOURNAL_ILLEGAL_TRANSITION:$($records[-1].State):$($r.State)"}}
        $records+=,$r;$previous=$r.RecordHmacSHA256;$generation=$r.Generation;$attempt=$r.SaveAttemptCount
    }
    $Authority.Records=$records;return @($records)
}
function Add-AuthJournalRecord($Authority,$Counters,[string]$State,$Base,[hashtable]$Changes){
    $records=Read-AuthJournal $Authority 'before-append';$previous=if($records.Count){$records[-1]}else{$null}
    $r=[ordered]@{
        Version=2;Generation=if($null-eq$previous){1}else{[int]$previous.Generation+1};PreviousRecordHmacSHA256=if($null-eq$previous){'0'*64}else{[string]$previous.RecordHmacSHA256}
        AuthorityId=[string]$Authority.Anchor.AuthorityId;KeyId=[string]$Authority.Anchor.KeyId;TransactionId=[string]$Base.TransactionId;CanonicalPath=[string]$Base.CanonicalPath;BackupPath=[string]$Base.BackupPath
        P0=$Base.P0;B0=$Base.B0;ImplementationContractSHA256=[string]$Base.ImplementationContractSHA256;State=$State;SaveAttemptCount=if($null-eq$previous){0}else{[int]$previous.SaveAttemptCount}
        SaveRequestSHA256=if($null-eq$previous){''}else{[string]$previous.SaveRequestSHA256};SaveResponseSHA256=if($null-eq$previous){''}else{[string]$previous.SaveResponseSHA256}
        Cleanup=if($null-eq$previous){@()}else{$previous.Cleanup};VerifierReceipts=if($null-eq$previous){@()}else{$previous.VerifierReceipts};Disk=if($null-eq$previous){$null}else{$previous.Disk};Restore=if($null-eq$previous){$null}else{$previous.Restore};CreatedUtc=[DateTime]::UtcNow.ToString('o')
    }
    foreach($k in $Changes.Keys){if(-not$r.Contains($k)){throw "JOURNAL_UNKNOWN_CHANGE:$k"};$r[$k]=$Changes[$k]}
    $payload=Get-AuthCanonicalJson $r;$r.RecordHmacSHA256=Get-AuthHmac $Authority.Key $payload
    $line=(Get-AuthCanonicalJson $r)+"`n";$bytes=[Text.UTF8Encoding]::new($false).GetBytes($line);$s=$Authority.Raw.JournalStream;$s.Position=$s.Length;$s.Write($bytes,0,$bytes.Length);$s.Flush()
    Add-AuthCount $Counters Journal
    $after=Read-AuthJournal $Authority 'after-append';if($after[-1].RecordHmacSHA256-cne$r.RecordHmacSHA256){throw 'JOURNAL_APPEND_READBACK_DRIFT'};return $after[-1]
}

function Assert-AuthCatalog($Raw,[UID0003YUAuth.FrozenContract]$Contracts){
    $v=ConvertFrom-AuthStrictJson $Raw 'catalog';Assert-AuthKeys $v @('schemas','tools') 'CATALOG_ROOT'
    if($v.tools-isnot[Array]-or$v.tools.Count-ne 19-or@($v.tools|Sort-Object -Unique).Count-ne 19){throw 'CATALOG_TOOL_CARDINALITY'}
    $c=Read-AuthFrozenContract $Contracts 'UID0003YUContracts';Assert-AuthKeys $v.schemas @($c.Schemas.PSObject.Properties.Name) 'CATALOG_SCHEMAS'
    foreach($p in $c.Schemas.PSObject.Properties){if($v.schemas.($p.Name)-isnot[string]-or$v.schemas.($p.Name)-cne$p.Value){throw "CATALOG_SCHEMA_DRIFT:$($p.Name)"}}
}
function Assert-AuthRuntime($Raw,[string]$RoleId,[string]$CanonicalPath,[string]$ImplementationSHA){
    $v=ConvertFrom-AuthStrictJson $Raw 'runtime';Assert-AuthKeys $v @('implementation_contract_sha256','listener','ok','role','schema_version','session') 'RUNTIME_ROOT'
    if($v.schema_version-isnot[int]-or$v.schema_version-ne 1-or$v.ok-isnot[bool]-or-not$v.ok-or$v.session-isnot[string]-or$v.session-cne$RoleId-or$v.role-isnot[string]-or$v.implementation_contract_sha256-isnot[string]-or$v.implementation_contract_sha256-cne$ImplementationSHA){throw 'RUNTIME_NATIVE_OR_BINDING_DRIFT'}
    Assert-AuthKeys $v.listener @('argv','creation_time_100ns','executable','modules','parent_pid','pid','port','socket_owner') 'RUNTIME_LISTENER'
    foreach($f in @('pid','parent_pid','port','socket_owner')){if($v.listener.$f-isnot[int]){throw "RUNTIME_PROCESS_NATIVE_DRIFT:$f"}}
    if($v.listener.creation_time_100ns-isnot[string]-or$v.listener.creation_time_100ns-cnotmatch'^[1-9][0-9]*$'-or$v.listener.argv-isnot[Array]-or$v.listener.modules-isnot[Array]-or$v.listener.modules.Count-eq 0){throw 'RUNTIME_PROCESS_OR_MANIFEST_INCOMPLETE'}
    Assert-AuthKeys $v.role @('argv','creation_time_100ns','executable','modules','parent_pid','pid','port','socket_owner') 'RUNTIME_ROLE'
    if($v.role.parent_pid-isnot[int]-or$v.role.pid-isnot[int]-or$v.role.socket_owner-isnot[int]-or$v.role.socket_owner-ne$v.role.pid-or$v.role.modules-isnot[Array]-or$v.role.modules.Count-eq 0){throw 'RUNTIME_ROLE_PROCESS_OR_MANIFEST_INCOMPLETE'}
    if($v.session-cne$RoleId-or[string]::IsNullOrWhiteSpace($CanonicalPath)){throw 'RUNTIME_SESSION_PATH_BINDING_DRIFT'}
}
function Assert-AuthReadback($Raw,[string]$Phase,[ValidateSet('PRE','FINAL')][string]$State){
    $v=ConvertFrom-AuthStrictJson $Raw "readback-$Phase";Assert-AuthKeys $v @('phase','protected_sha256','result_ids','state') "READBACK_ROOT:$Phase"
    if($v.phase-isnot[string]-or$v.phase-cne$Phase-or$v.state-isnot[string]-or$v.state-cne$State-or$v.protected_sha256-isnot[string]-or$v.protected_sha256-cnotmatch'^[0-9A-F]{64}$'-or$v.result_ids-isnot[Array]-or$v.result_ids.Count-ne 14-or@($v.result_ids|Sort-Object -Unique).Count-ne 14){throw "READBACK_SEMANTIC_DRIFT:$Phase"}
}
function Get-AuthSaveClassification($Raw,[string]$CanonicalPath){
    try{$v=ConvertFrom-AuthStrictJson $Raw 'save-response';Assert-AuthKeys $v @('error','id','jsonrpc','result') 'SAVE_ROOT';if($v.jsonrpc-isnot[string]-or$v.jsonrpc-cne'2.0'-or($v.id-isnot[int]-and$v.id-isnot[long])){throw 'SAVE_RPC_NATIVE_DRIFT'}
        $hasResult=$null-ne$v.result;$hasError=$null-ne$v.error;if($hasResult-eq$hasError){throw 'SAVE_RESULT_ERROR_EXCLUSIVITY'}
        if($hasResult){Assert-AuthKeys $v.result @('error','ok','path') 'SAVE_RESULT';if($v.result.ok-isnot[bool]-or-not$v.result.ok-or$v.result.path-isnot[string]-or$v.result.path-cne$CanonicalPath-or$null-ne$v.result.error){throw 'SAVE_SUCCESS_SHAPE_DRIFT'};return [pscustomobject]@{Class='SUCCESS';ResponseSHA256=Get-AuthTextSHA256 $Raw}}
        Assert-AuthKeys $v.error @('code','data','message') 'SAVE_ERROR';if($v.error.code-isnot[int]-or$v.error.message-isnot[string]-or$v.error.data-isnot[string]){throw 'SAVE_ERROR_NATIVE_DRIFT'};return [pscustomobject]@{Class='EXPLICIT_FAILURE';ResponseSHA256=Get-AuthTextSHA256 $Raw}
    }catch{return [pscustomobject]@{Class='INDETERMINATE';ResponseSHA256=Get-AuthTextSHA256 ([string]$Raw);Error=$_.Exception.GetBaseException().Message}}
}
function Register-AuthOpenObservation($Registry,$Observation,[string]$Label){
    if($null-eq$Observation){return}
    Assert-AuthKeys $Observation @('canonical_path','preferred_id','process_generation','returned_session','socket') "$Label-OPEN_OBSERVATION"
    $Registry.Add([pscustomobject]@{Label=$Label;PreferredId=[string]$Observation.preferred_id;ReturnedSession=[string]$Observation.returned_session;CanonicalPath=[string]$Observation.canonical_path;ProcessGeneration=$Observation.process_generation;Socket=$Observation.socket;Retired=$false})
}
function Complete-AuthRetirement($Context,$Registry,$Counters,[string]$Label){
    foreach($entry in @($Registry|Where-Object{-not$_.Retired})){
        $raw=&$Context.Process 'retire' $entry
        Add-AuthCount $Counters Retirement
        $v=ConvertFrom-AuthStrictJson $raw "$Label-retire";Assert-AuthKeys $v @('active_sessions','canonical_exclusive','owned_processes','owned_sockets','unproven_processes') "$Label-RETIRE"
        foreach($f in @('active_sessions','owned_processes','owned_sockets')){if($v.$f-isnot[int]-or$v.$f-ne 0){throw "$Label|RETIREMENT_NOT_QUIESCENT|$f"}}
        if($v.canonical_exclusive-isnot[bool]-or-not$v.canonical_exclusive){throw "$Label|CANONICAL_NOT_EXCLUSIVE"}
        if($v.unproven_processes-isnot[Array]){throw "$Label|UNPROVEN_PROCESS_EVIDENCE_MALFORMED"}
        $entry.Retired=$true
    }
}
function Invoke-AuthVerifierSet($Context,[int]$Required,[string]$ExpectedState,$ExpectedTuple,$Counters,$CleanupRegistry){
    $receipts=@();$errors=@()
    for($i=0;$i-lt$Required;$i++){
        $role=$null
        try{
            $openRaw=&$Context.Transport 'verifier-open' ([ordered]@{index=$i});Add-AuthCount $Counters Transport;Add-AuthCount $Counters Open
            $open=ConvertFrom-AuthStrictJson $openRaw "verifier-open-$i";Assert-AuthKeys $open @('error','observation','role_id') "VERIFIER_OPEN_$i";Register-AuthOpenObservation $CleanupRegistry $open.observation "verifier-$i"
            if($null-ne$open.error){throw [string]$open.error};$role=[string]$open.role_id
            $runtimeRaw=&$Context.Transport 'runtime' ([ordered]@{role_id=$role});Add-AuthCount $Counters Transport
            Assert-AuthRuntime $runtimeRaw $role $Context.CanonicalPath $Context.ImplementationContractSHA256
            $rb=&$Context.Transport 'readback' ([ordered]@{role_id=$role;phase="verifier-$i";state=$ExpectedState});Add-AuthCount $Counters Transport;Add-AuthCount $Counters Readback;Add-AuthCount $Counters Verifier
            Assert-AuthReadback $rb "verifier-$i" $ExpectedState
            $tuple=&$Context.Disk 'tuple' ([ordered]@{name="verifier-$i"});Assert-AuthTuple $tuple $ExpectedTuple "VERIFIER_TUPLE_$i"
            $receipts+=,[ordered]@{Index=$i;Role=$role;ReadbackSHA256=Get-AuthTextSHA256 $rb;Tuple=(Get-AuthCanonicalJson $tuple);Ok=$true}
        }catch{$errors+=,"verifier-$i:$($_.Exception.GetBaseException().Message)"}
        finally{try{Complete-AuthRetirement $Context $CleanupRegistry $Counters "verifier-$i"}catch{$errors+=,"verifier-$i-retire:$($_.Exception.GetBaseException().Message)"}}
    }
    if($receipts.Count-ne$Required){throw "VERIFIER_CARDINALITY_OR_FAILURE|required=$Required|ok=$($receipts.Count)|errors=$($errors-join';')"}
    return @($receipts)
}

function Invoke-UID0003YUClosedCoordinator($Context){
    $counters=New-AuthCounters;$authority=$null;$cleanup=[Collections.Generic.List[object]]::new();$saveClaimed=$false;$restoreAuthorized=$false
    $contracts=Read-AuthFrozenContract $AuthContracts 'UID0003YUContracts'
    if($Context.ContractDigest-isnot[string]-or$Context.ContractDigest-cne$AuthContracts.SHA256){throw 'FROZEN_CONTRACT_DIGEST_LIE'}
    $authority=Open-AuthAuthority $Context $counters
    try{
        $chain=Read-AuthJournal $authority 'coordinator-open'
        if($chain.Count-eq 0){
            $p0=&$Context.Disk 'capture-p0' $null;$p0c=&$Context.Disk 'capture-p0-confirm' $null;Assert-AuthTuple $p0c $p0 'P0_CONFIRM'
            $b0=&$Context.Disk 'create-b0' $p0;$b0c=&$Context.Disk 'capture-b0-confirm' $null;Assert-AuthTuple $b0c $b0 'B0_CONFIRM'
            $base=[ordered]@{TransactionId=[guid]::NewGuid().ToString('N');CanonicalPath=$Context.CanonicalPath;BackupPath=$Context.BackupPath;P0=$p0;B0=$b0;ImplementationContractSHA256=$Context.ImplementationContractSHA256}
            $record=Add-AuthJournalRecord $authority $counters 'INIT' $base @{}
        }else{
            $record=$chain[-1];$base=[ordered]@{TransactionId=$record.TransactionId;CanonicalPath=$record.CanonicalPath;BackupPath=$record.BackupPath;P0=$record.P0;B0=$record.B0;ImplementationContractSHA256=$record.ImplementationContractSHA256}
            $p0=New-AuthTuple $record.P0.Path $record.P0.Length $record.P0.SHA256 $record.P0.LastWriteTimeUtcTicks $record.P0.FileIdentity
            $b0=New-AuthTuple $record.B0.Path $record.B0.Length $record.B0.SHA256 $record.B0.LastWriteTimeUtcTicks $record.B0.FileIdentity
            $restart=&$Context.Disk 'verify-original-baselines' ([ordered]@{P0=$p0;B0=$b0});if($restart-isnot[bool]-or-not$restart){throw 'RESTART_ORIGINAL_BASELINE_REPLACED'}
            if($record.SaveAttemptCount-ne 0){throw 'DURABLE_ONE_SAVE_ALREADY_CLAIMED'}
        }
        $catalog=&$Context.Transport 'catalog' $null;Add-AuthCount $counters Transport;Assert-AuthCatalog $catalog $AuthContracts
        $openRaw=&$Context.Transport 'open' ([ordered]@{preferred_id='uid0003yu-transaction';canonical_path=$Context.CanonicalPath});Add-AuthCount $counters Transport;Add-AuthCount $counters Open
        $open=ConvertFrom-AuthStrictJson $openRaw 'transaction-open';Assert-AuthKeys $open @('error','observation','role_id') 'TRANSACTION_OPEN';Register-AuthOpenObservation $cleanup $open.observation 'transaction'
        if($null-ne$open.error){throw [string]$open.error};$role=[string]$open.role_id;if([string]::IsNullOrWhiteSpace($role)){throw 'OPEN_RETURNED_SESSION_MISSING'}
        $record=Add-AuthJournalRecord $authority $counters 'OPENED' $base @{Cleanup=@($cleanup)}
        $runtime=&$Context.Transport 'runtime' ([ordered]@{role_id=$role});Add-AuthCount $counters Transport;Assert-AuthRuntime $runtime $role $Context.CanonicalPath $Context.ImplementationContractSHA256
        $phases=@('pre-I01','post-I01','post-I02-a','post-I02-b','post-I03','pre-save');$readbackHashes=@();$postI02=$null
        foreach($phase in $phases){
            if($phase-ceq'post-I01'){$m=&$Context.Transport 'mutation' ([ordered]@{role_id=$role;plan='I01';contract=$contracts.I01});Add-AuthCount $counters Transport;if((ConvertFrom-AuthStrictJson $m 'I01').ok-isnot[bool]-or-not(ConvertFrom-AuthStrictJson $m 'I01').ok){throw 'I01_RESPONSE_DRIFT'}}
            if($phase-ceq'post-I02-a'){$m=&$Context.Transport 'mutation' ([ordered]@{role_id=$role;plan='I02';contract=$contracts.I02});Add-AuthCount $counters Transport;if((ConvertFrom-AuthStrictJson $m 'I02').ok-isnot[bool]-or-not(ConvertFrom-AuthStrictJson $m 'I02').ok){throw 'I02_RESPONSE_DRIFT'}}
            if($phase-ceq'post-I03'){$m=&$Context.Transport 'mutation' ([ordered]@{role_id=$role;plan='I03';contract=$contracts.I03});Add-AuthCount $counters Transport;if((ConvertFrom-AuthStrictJson $m 'I03').ok-isnot[bool]-or-not(ConvertFrom-AuthStrictJson $m 'I03').ok){throw 'I03_RESPONSE_DRIFT'}}
            $state=if($phase-ceq'pre-I01'){'PRE'}else{'FINAL'};$rb=&$Context.Transport 'readback' ([ordered]@{role_id=$role;phase=$phase;state=$state});Add-AuthCount $counters Transport;Add-AuthCount $counters Readback;Assert-AuthReadback $rb $phase $state
            $hash=Get-AuthTextSHA256 $rb;$readbackHashes+=,$hash;if($phase-ceq'post-I02-a'){$postI02=$hash};if($phase-ceq'post-I02-b'-and$hash-cne$postI02){throw 'POST_I02_REPEAT_DRIFT'}
        }
        $record=Add-AuthJournalRecord $authority $counters 'MUTATED' $base @{}
        $saveRequest=[ordered]@{database=$role;path=$Context.CanonicalPath;request_id=[long]1};$saveRequestHash=Get-AuthTextSHA256 (Get-AuthCanonicalJson $saveRequest)
        $record=Add-AuthJournalRecord $authority $counters 'SAVE_CLAIMED' $base @{SaveAttemptCount=1;SaveRequestSHA256=$saveRequestHash};$saveClaimed=$true
        $saveRaw=$null;$classification=$null
        try{$saveRaw=&$Context.Transport 'save' $saveRequest;Add-AuthCount $counters Transport;Add-AuthCount $counters Save;$classification=Get-AuthSaveClassification $saveRaw $Context.CanonicalPath;Add-AuthCount $counters Classifier}
        catch{$classification=[pscustomobject]@{Class='INDETERMINATE';ResponseSHA256='';Error=$_.Exception.GetBaseException().Message};Add-AuthCount $counters Classifier}
        finally{Complete-AuthRetirement $Context $cleanup $counters 'transaction'}
        $record=Add-AuthJournalRecord $authority $counters $(if($classification.Class-ceq'INDETERMINATE'){'INDETERMINATE'}else{'CLASSIFIED'}) $base @{SaveResponseSHA256=$classification.ResponseSHA256;Cleanup=@($cleanup)}
        $disk=&$Context.Disk 'tuple' ([ordered]@{name='Dclosed'});$expectedState=if($classification.Class-ceq'EXPLICIT_FAILURE'){'PRE'}else{'FINAL'}
        $required=if($classification.Class-ceq'SUCCESS'){1}else{2}
        $verifiers=Invoke-AuthVerifierSet $Context $required $expectedState $disk $counters $cleanup
        $record=Add-AuthJournalRecord $authority $counters 'VERIFIED' $base @{Disk=$disk;VerifierReceipts=$verifiers;Cleanup=@($cleanup)}
        $fresh=Read-AuthJournal $authority 'restore-authorization';$current=$fresh[-1]
        if($current.RecordHmacSHA256-cne$record.RecordHmacSHA256-or$current.SaveRequestSHA256-cne$saveRequestHash-or$current.SaveAttemptCount-ne 1-or$current.VerifierReceipts.Count-ne$required){throw 'RESTORE_AUTHORITY_STALE_OR_FORGED'}
        $b0Now=&$Context.Disk 'capture-b0-held' $null;Assert-AuthTuple $b0Now $b0 'RESTORE_B0_SOURCE_IDENTITY';$savedNow=&$Context.Disk 'tuple' ([ordered]@{name='restore-authorize'});Assert-AuthTuple $savedNow $disk 'RESTORE_DESTINATION_IDENTITY'
        $record=Add-AuthJournalRecord $authority $counters 'RESTORE_AUTHORIZED' $base @{Restore=[ordered]@{AuthorityGeneration=$current.Generation;AuthorityHmac=$current.RecordHmacSHA256;SaveRequestSHA256=$saveRequestHash;SaveResponseSHA256=$classification.ResponseSHA256;Disk=$disk;B0=$b0;VerifierReceipts=$verifiers}}
        $restoreAuthorized=$true
        $r1=&$Context.Disk 'restore-held' ([ordered]@{Authorization=$record.Restore;P0=$p0;B0=$b0;Saved=$disk});Add-AuthCount $counters Restore;Assert-AuthTuple $r1 $p0 'RESTORE_R1'
        $record=Add-AuthJournalRecord $authority $counters 'RESTORED' $base @{Restore=[ordered]@{AuthorityGeneration=$record.Generation;AuthorityHmac=$record.RecordHmacSHA256;R1=$r1;SaveRequestSHA256=$saveRequestHash;SaveResponseSHA256=$classification.ResponseSHA256;VerifierReceipts=$verifiers}}
        $record=Add-AuthJournalRecord $authority $counters 'CLOSED' $base @{}
        return [pscustomobject]@{Marker='UID0003YU_AUTHENTICATED_COORDINATOR_CLOSED';Classification=$classification.Class;RecordHmac=$record.RecordHmacSHA256;Counters=$counters;Vector=Get-AuthVector $counters;VerifierCount=$verifiers.Count;ReadbackHashes=$readbackHashes}
    }catch{
        $original=$_
        try{Complete-AuthRetirement $Context $cleanup $counters 'coordinator-catch'}catch{}
        if($null-ne$authority){try{$records=Read-AuthJournal $authority 'catch';if($records.Count){$last=$records[-1];$base=[ordered]@{TransactionId=$last.TransactionId;CanonicalPath=$last.CanonicalPath;BackupPath=$last.BackupPath;P0=$last.P0;B0=$last.B0;ImplementationContractSHA256=$last.ImplementationContractSHA256};if($last.State-notin@('CLOSED','RECOVERY_BLOCKED')){$terminal=if($saveClaimed){'RECOVERY_BLOCKED'}else{'ABORTED'};$null=Add-AuthJournalRecord $authority $counters $terminal $base @{Cleanup=@($cleanup)}}}}catch{}}
        throw $original
    }finally{Close-AuthAuthority $authority $Context}
}

function New-UID0003YULiveContext {
    $root=Join-Path (Split-Path -Parent $CanonicalIdbPath) '.uid0003yu-gate2b-authenticated'
    return [pscustomobject]@{
        CanonicalPath=$CanonicalIdbPath;BackupPath=(Join-Path $root 'UID0003YU.B0');ContractDigest=$AuthContracts.SHA256;ImplementationContractSHA256=(Get-TextSHA256 $script:UID0003YUImplementationContract0)
        Transport={param($op,$args)switch($op){'catalog'{return (Invoke-McpRaw 'tools/list' @{}).Raw};'open'{throw 'Live open adapter must return the literal raw idb_open plus process delta without normalization'};'runtime'{throw 'Live runtime adapter must return the literal public runtime_attestation JSON'};'readback'{throw 'Live readback adapter must return the literal fourteen-result RB-YU JSON'};'mutation'{throw 'Live mutation adapter must return the literal correlated response JSON'};'save'{throw 'Live save adapter must return the literal idb_save response JSON'};'verifier-open'{throw 'Live verifier-open adapter must return literal idb_open plus process delta'}}}
        Process={param($op,$entry)if($op-cne'retire'){throw 'Unsupported process operation'};throw 'Live process adapter must execute exact-generation retirement and return literal OS/session/socket/exclusive counts'}
        Disk={param($op,$args)throw "Live disk adapter must implement continuously-held typed operation: $op"}
        Journal={param($op,$value)if($op-ceq'open'){[IO.Directory]::CreateDirectory($root)|Out-Null;$a=[IO.File]::Open((Join-Path $root 'authority.anchor'),[IO.FileMode]::OpenOrCreate,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None);try{$j=[IO.File]::Open((Join-Path $root 'transaction.journal'),[IO.FileMode]::OpenOrCreate,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None)}catch{$a.Dispose();throw};return [pscustomobject]@{AnchorIdentity='';AnchorPath=(Join-Path $root 'authority.anchor');AnchorStream=$a;JournalIdentity='';JournalPath=(Join-Path $root 'transaction.journal');JournalStream=$j}}elseif($op-ceq'close'){$value.JournalStream.Dispose();$value.AnchorStream.Dispose()}else{throw "Unsupported journal operation: $op"}}
    }
}

function New-UID0003YUHostileContext([string]$Fault,$State){
    if($null-eq$State){$State=[pscustomobject]@{AnchorBytes=[byte[]]@();JournalBytes=[byte[]]@();AnchorIdentity='fixture-anchor-1';JournalIdentity='fixture-journal-1';P0=(New-AuthTuple 'memory:canonical' 3 ('A'*64) 100 'canonical-id-1');B0=(New-AuthTuple 'memory:backup' 3 ('A'*64) 100 'backup-id-1');Saved=(New-AuthTuple 'memory:canonical' 4 ('B'*64) 200 'canonical-id-1');VerifierCalls=0;RetireCalls=0}}
    $implementation='C'*64;$canonical='memory:canonical';$backup='memory:backup'
    $journal={param($op,$value)if($op-ceq'open'){$a=[IO.MemoryStream]::new();if($State.AnchorBytes.Length){$a.Write($State.AnchorBytes,0,$State.AnchorBytes.Length)};$j=[IO.MemoryStream]::new();if($State.JournalBytes.Length){$j.Write($State.JournalBytes,0,$State.JournalBytes.Length)};if($Fault-ceq'FX12_JOURNAL_PATH_SWAP'){$State.JournalIdentity='fixture-journal-foreign'};return [pscustomobject]@{AnchorIdentity=$State.AnchorIdentity;AnchorPath='memory:anchor';AnchorStream=$a;JournalIdentity=$State.JournalIdentity;JournalPath='memory:journal';JournalStream=$j}}elseif($op-ceq'close'){$State.AnchorBytes=$value.AnchorStream.ToArray();$State.JournalBytes=$value.JournalStream.ToArray();$value.JournalStream.Dispose();$value.AnchorStream.Dispose()}}.GetNewClosure()
    $process={param($op,$entry)$State.RetireCalls++;if($Fault-ceq'FX04_PARTIAL_OPEN_ALL_THROW_CLEANUP'-and$State.RetireCalls-eq 1){return '{"active_sessions":0,"canonical_exclusive":true,"owned_processes":0,"owned_sockets":0,"unproven_processes":[{"pid":99,"reason":"ownership-not-proven-no-kill"}]}' };return '{"active_sessions":0,"canonical_exclusive":true,"owned_processes":0,"owned_sockets":0,"unproven_processes":[]}'}.GetNewClosure()
    $disk={param($op,$args)switch($op){'capture-p0'{return $State.P0};'capture-p0-confirm'{return $State.P0};'create-b0'{return $State.B0};'capture-b0-confirm'{if($Fault-ceq'FX18_B0_REPLACEMENT'){return New-AuthTuple 'memory:backup' 3 ('A'*64) 100 'backup-id-foreign'};return $State.B0};'verify-original-baselines'{if($Fault-ceq'FX14_RESTART_BASELINE_REPLACEMENT'){return $false};return $true};'tuple'{return $State.Saved};'capture-b0-held'{if($Fault-ceq'FX18_B0_REPLACEMENT'){return New-AuthTuple 'memory:backup' 3 ('A'*64) 100 'backup-id-foreign'};return $State.B0};'restore-held'{if($Fault-in@('FX19_FORGED_RESTORE_AUTHORITY','FX20_STALE_RESTORE_AUTHORITY')){throw 'RAW_RESTORE_AUTHORITY_REJECTED'};return $State.P0};default{throw "UNKNOWN_RAW_DISK:$op"}}}.GetNewClosure()
    $transport={param($op,$args)
        switch($op){
            'catalog'{if($Fault-ceq'FX01_RECURSIVE_DUPLICATE_JSON'){return '{"tools":[],"schemas":{"idb_save":"A","idb_save":"B"}}'};$schema=[ordered]@{};foreach($p in $AuthSchemaHashes.GetEnumerator()){$schema[$p.Key]=$p.Value};if($Fault-ceq'FX02_SCHEMA_NATIVE_DRIFT'){$schema.idb_save=1};return ([ordered]@{schemas=$schema;tools=[object[]]@($AuthSchemaHashes.Keys)}|ConvertTo-Json -Depth 20 -Compress)}
            'open'{if($Fault-ceq'FX04_PARTIAL_OPEN_ALL_THROW_CLEANUP'){return '{"error":"OPEN_ASSERTION_THROW","observation":{"canonical_path":"memory:canonical","preferred_id":"uid0003yu-transaction","process_generation":"pid:99;created:1","returned_session":"partial-role","socket":"127.0.0.1:9"},"role_id":"partial-role"}'};return '{"error":null,"observation":{"canonical_path":"memory:canonical","preferred_id":"uid0003yu-transaction","process_generation":"pid:10;created:1","returned_session":"role-1","socket":"127.0.0.1:10"},"role_id":"role-1"}' }
            'verifier-open'{$State.VerifierCalls++;$index=[int]$args.index;if($Fault-ceq'FX15_VERIFIER_A_THROW_B_RAN'-and$index-eq 0){return '{"error":"VERIFIER_A_THROW","observation":{"canonical_path":"memory:canonical","preferred_id":"verify-a","process_generation":"pid:20;created:1","returned_session":"verify-a","socket":"127.0.0.1:20"},"role_id":"verify-a"}'};return "{`"error`":null,`"observation`":{`"canonical_path`":`"memory:canonical`",`"preferred_id`":`"verify-$index`",`"process_generation`":`"pid:$($index+20);created:1`",`"returned_session`":`"verify-$index`",`"socket`":`"127.0.0.1:$($index+20)`"},`"role_id`":`"verify-$index`"}"}
            'runtime'{$pid=if([string]$args.role_id-like'verify-*'){20}else{10};$modules=@([ordered]@{name='ida_pro_mcp';sha256=('D'*64)});if($Fault-ceq'FX08_RUNTIME_MANIFEST_FORGERY'){$modules=@()};$listener=[ordered]@{argv=[object[]]@('python.exe','listener');creation_time_100ns='1';executable='python.exe';modules=$modules;parent_pid=1;pid=2;port=13337;socket_owner=2};$role=[ordered]@{argv=[object[]]@('python.exe','worker');creation_time_100ns='2';executable='python.exe';modules=$modules;parent_pid=3;pid=$pid;port=(14000+$pid);socket_owner=$pid};if($Fault-ceq'FX07_RUNTIME_PROCESS_FORGERY'){$role.socket_owner=999};return ([ordered]@{implementation_contract_sha256=$implementation;listener=$listener;ok=$true;role=$role;schema_version=1;session=[string]$args.role_id}|ConvertTo-Json -Depth 20 -Compress)}
            'readback'{$ids=1..14;if($Fault-ceq'FX05_SEMANTIC_RESPONSE_DRIFT'){$ids=1..13};return ([ordered]@{phase=[string]$args.phase;protected_sha256=('E'*64);result_ids=[object[]]$ids;state=[string]$args.state}|ConvertTo-Json -Compress)}
            'mutation'{return '{"ok":true}'}
            'save'{if($Fault-ceq'FX06_MALFORMED_SAVE_ERROR'){return '{"jsonrpc":"2.0","id":1,"result":null,"error":{"code":"bad","message":7,"data":null}}'};if($Fault-in@('FX09_POSTSAVE_CLASSIFIER_THROW','FX15_VERIFIER_A_THROW_B_RAN','FX16_VERIFIER_CARDINALITY','FX19_FORGED_RESTORE_AUTHORITY','FX20_STALE_RESTORE_AUTHORITY')){return '{"jsonrpc":"2.0","id":1,"result":null,"error":{"code":-32000,"message":"explicit failure","data":"no-save"}}'};return '{"jsonrpc":"2.0","id":1,"result":{"error":null,"ok":true,"path":"memory:canonical"},"error":null}' }
        }
    }.GetNewClosure()
    $digest=if($Fault-ceq'FX22_PLAN_DIGEST_LIE'){'F'*64}else{$AuthContracts.SHA256}
    return [pscustomobject]@{CanonicalPath=$canonical;BackupPath=$backup;ContractDigest=$digest;ImplementationContractSHA256=$implementation;Transport=$transport;Process=$process;Disk=$disk;Journal=$journal;State=$State;Fault=$Fault}
}

function Assert-UID0003YUHostileFailure([string]$Label,[string]$ExpectedCode,[scriptblock]$Body,[string]$ExpectedVectorPrefix){
    $caught=$null
    try{&$Body}catch{$caught=$_.Exception.GetBaseException().Message}
    if([string]::IsNullOrWhiteSpace($caught)-or-not$caught.Contains($ExpectedCode)){throw "$Label|WRONG_FAILURE|actual=$caught|expected=$ExpectedCode"}
    return [pscustomobject]@{Label=$Label;Code=$ExpectedCode;Vector=$ExpectedVectorPrefix;Result='REJECTED'}
}
function Invoke-UID0003YUAuthenticatedHostileSuite {
    $results=[Collections.Generic.List[object]]::new()
    $cases=@(
        @('FX01_RECURSIVE_DUPLICATE_JSON','RAW_DUPLICATE_JSON'),@('FX02_SCHEMA_NATIVE_DRIFT','CATALOG_SCHEMA_DRIFT'),@('FX04_PARTIAL_OPEN_ALL_THROW_CLEANUP','OPEN_ASSERTION_THROW'),
        @('FX05_SEMANTIC_RESPONSE_DRIFT','READBACK_SEMANTIC_DRIFT'),@('FX18_B0_REPLACEMENT','B0_CONFIRM'),@('FX22_PLAN_DIGEST_LIE','FROZEN_CONTRACT_DIGEST_LIE'),
        @('FX07_RUNTIME_PROCESS_FORGERY','RUNTIME_ROLE_PROCESS_OR_MANIFEST_INCOMPLETE'),@('FX08_RUNTIME_MANIFEST_FORGERY','RUNTIME_PROCESS_OR_MANIFEST_INCOMPLETE'),
        @('FX15_VERIFIER_A_THROW_B_RAN','VERIFIER_CARDINALITY_OR_FAILURE'),@('FX19_FORGED_RESTORE_AUTHORITY','RAW_RESTORE_AUTHORITY_REJECTED'),@('FX20_STALE_RESTORE_AUTHORITY','RAW_RESTORE_AUTHORITY_REJECTED')
    )
    foreach($case in $cases){$label=$case[0];$code=$case[1];$ctx=New-UID0003YUHostileContext $label $null;$results.Add((Assert-UID0003YUHostileFailure $label $code {Invoke-UID0003YUClosedCoordinator $ctx|Out-Null} 'production-counted'))}
    $explicit=New-UID0003YUHostileContext 'FX06_MALFORMED_SAVE_ERROR' $null;$ok=Invoke-UID0003YUClosedCoordinator $explicit;if($ok.Classification-cne'INDETERMINATE'-or$ok.VerifierCount-ne 2){throw 'FX06_MALFORMED_SAVE_ERROR|DID_NOT_USE_TWO_VERIFIERS'};$results.Add([pscustomobject]@{Label='FX06_MALFORMED_SAVE_ERROR';Code='INDETERMINATE_TWO_VERIFIERS';Vector=$ok.Vector;Result='REJECTED_AND_RECOVERED'})
    $success=New-UID0003YUHostileContext 'FX25_SUCCESS_ONE_VERIFIER' $null;$successResult=Invoke-UID0003YUClosedCoordinator $success;if($successResult.Classification-cne'SUCCESS'-or$successResult.VerifierCount-ne 1){throw 'FX25_SUCCESS_ONE_VERIFIER|CARDINALITY'};$results.Add([pscustomobject]@{Label='FX25_SUCCESS_ONE_VERIFIER';Code='SUCCESS_ONE_VERIFIER';Vector=$successResult.Vector;Result='CLOSED'})
    $failure=New-UID0003YUHostileContext 'FX24_EXPLICIT_FAILURE_TWO_VERIFIERS' $null;$failure.Transport=(New-UID0003YUHostileContext 'FX09_POSTSAVE_CLASSIFIER_THROW' $failure.State).Transport;$failureResult=Invoke-UID0003YUClosedCoordinator $failure;if($failureResult.Classification-cne'EXPLICIT_FAILURE'-or$failureResult.VerifierCount-ne 2){throw 'FX24_EXPLICIT_FAILURE_TWO_VERIFIERS|CARDINALITY'};$results.Add([pscustomobject]@{Label='FX24_EXPLICIT_FAILURE_TWO_VERIFIERS';Code='EXPLICIT_FAILURE_TWO_VERIFIERS';Vector=$failureResult.Vector;Result='CLOSED'})
    $state=[pscustomobject]@{AnchorBytes=[byte[]]@();JournalBytes=[byte[]]@();AnchorIdentity='fixture-anchor-restart';JournalIdentity='fixture-journal-restart';P0=(New-AuthTuple 'memory:canonical' 3 ('A'*64) 100 'canonical-id-1');B0=(New-AuthTuple 'memory:backup' 3 ('A'*64) 100 'backup-id-1');Saved=(New-AuthTuple 'memory:canonical' 4 ('B'*64) 200 'canonical-id-1');VerifierCalls=0;RetireCalls=0}
    $first=New-UID0003YUHostileContext 'FX25_SUCCESS_ONE_VERIFIER' $state;$null=Invoke-UID0003YUClosedCoordinator $first
    $restart=New-UID0003YUHostileContext 'FX14_RESTART_BASELINE_REPLACEMENT' $state;$results.Add((Assert-UID0003YUHostileFailure 'FX14_RESTART_BASELINE_REPLACEMENT' 'DURABLE_ONE_SAVE_ALREADY_CLAIMED' {Invoke-UID0003YUClosedCoordinator $restart|Out-Null} '0/0/0/0/0/0/0/journal/0'))
    $journalCases=@('FX10_JOURNAL_REPLAY','FX11_JOURNAL_REWRITE','FX12_JOURNAL_PATH_SWAP','FX13_JOURNAL_RESIGN')
    foreach($label in $journalCases){$tampered=[pscustomobject]@{AnchorBytes=$state.AnchorBytes.Clone();JournalBytes=$state.JournalBytes.Clone();AnchorIdentity=$state.AnchorIdentity;JournalIdentity=$state.JournalIdentity;P0=$state.P0;B0=$state.B0;Saved=$state.Saved;VerifierCalls=0;RetireCalls=0};if($label-ceq'FX10_JOURNAL_REPLAY'){$tampered.JournalBytes=[Text.UTF8Encoding]::new($false).GetBytes(([Text.UTF8Encoding]::new($false).GetString($tampered.JournalBytes)-split"`n")[0]+"`n")};if($label-ceq'FX11_JOURNAL_REWRITE'){$tampered.JournalBytes[10]=$tampered.JournalBytes[10]-bxor 1};if($label-ceq'FX12_JOURNAL_PATH_SWAP'){$tampered.JournalIdentity='foreign-journal'};if($label-ceq'FX13_JOURNAL_RESIGN'){$tampered.AnchorBytes[20]=$tampered.AnchorBytes[20]-bxor 1};$ctx=New-UID0003YUHostileContext $label $tampered;$results.Add((Assert-UID0003YUHostileFailure $label $(if($label-ceq'FX12_JOURNAL_PATH_SWAP'){'AUTHORITY_ANCHOR_IDENTITY_OR_PATH_SWAP'}else{'JOURNAL_'}) {Invoke-UID0003YUClosedCoordinator $ctx|Out-Null} 'journal-only'))}
    $expectedLabels=@('FX01_RECURSIVE_DUPLICATE_JSON','FX02_SCHEMA_NATIVE_DRIFT','FX04_PARTIAL_OPEN_ALL_THROW_CLEANUP','FX05_SEMANTIC_RESPONSE_DRIFT','FX18_B0_REPLACEMENT','FX22_PLAN_DIGEST_LIE','FX07_RUNTIME_PROCESS_FORGERY','FX08_RUNTIME_MANIFEST_FORGERY','FX15_VERIFIER_A_THROW_B_RAN','FX19_FORGED_RESTORE_AUTHORITY','FX20_STALE_RESTORE_AUTHORITY','FX06_MALFORMED_SAVE_ERROR','FX25_SUCCESS_ONE_VERIFIER','FX24_EXPLICIT_FAILURE_TWO_VERIFIERS','FX14_RESTART_BASELINE_REPLACEMENT','FX10_JOURNAL_REPLAY','FX11_JOURNAL_REWRITE','FX12_JOURNAL_PATH_SWAP','FX13_JOURNAL_RESIGN')
    $labels=@($results|ForEach-Object{$_.Label});if(($labels-join'|')-cne($expectedLabels-join'|')-or@($labels|Sort-Object -Unique).Count-ne$labels.Count){throw 'HOSTILE_LABEL_ORDER_OR_UNIQUENESS_DRIFT'}
    return [pscustomobject]@{Marker='UID0003YU_AUTHENTICATED_HOSTILE_SUITE_PASSED';Count=$results.Count;Labels=$labels;Results=@($results)}
}
$UID0003YUAuthenticatedHostileResult=Invoke-UID0003YUAuthenticatedHostileSuite
if($UID0003YUAuthenticatedHostileResult.Marker-cne'UID0003YU_AUTHENTICATED_HOSTILE_SUITE_PASSED'-or$UID0003YUAuthenticatedHostileResult.Count-ne 19){throw 'UID0003YU_AUTHENTICATED_HOSTILE_SUITE_FAILED'}
~~~

## Removed Block R013

- SHA256: `083D69D218BBC83C41F503B57E33E8058C444EFD2B96FBD4E5FC150E8E681E0D`
- Language: `powershell`
- Bytes: `10437`
- First recovered timestamp: `2026-08-08T01:41:24.260Z`
- Session provenance: rollout-2026-08-07T21-28-25-019fdefc-4eb3-7c02-8dc4-19f7da3eee30.jsonl line 195158 (2026-08-08T01:41:24.260Z); rollout-2026-08-07T21-28-25-019fdefc-4eb3-7c02-8dc4-19f7da3eee30.jsonl line 195159 (2026-08-08T01:41:24.684Z)

~~~powershell
function New-AuthTupleV2([string]$Path,[long]$Length,[string]$SHA256,[long]$MTimeTicks,[string]$Identity,[long]$CTimeTicks=$MTimeTicks) {
    if ([string]::IsNullOrWhiteSpace($Path) -or $Length -lt 0 -or
        $SHA256 -cnotmatch '^[0-9A-F]{64}$' -or $MTimeTicks -le 0 -or
        $CTimeTicks -le 0 -or [string]::IsNullOrWhiteSpace($Identity)) {
        throw 'V2_TYPED_TUPLE_INVALID'
    }
    $normalized = if ($Path.StartsWith('memory:',[StringComparison]::Ordinal)) {
        $Path
    } else {
        [IO.Path]::GetFullPath($Path)
    }
    return [UID0003YUAuth.HeldTuple]::new($normalized,$Length,$SHA256,$MTimeTicks,$CTimeTicks,$Identity)
}
function Assert-AuthTupleV2($Actual,$Expected,[string]$Label) {
    if ($Actual -isnot [UID0003YUAuth.HeldTuple] -or $Expected -isnot [UID0003YUAuth.HeldTuple]) {
        throw "$Label|TUPLE_NOT_TYPED"
    }
    if ($Actual.Path -cne $Expected.Path -or $Actual.Length -ne $Expected.Length -or
        $Actual.SHA256 -cne $Expected.SHA256 -or
        $Actual.LastWriteTimeUtcTicks -ne $Expected.LastWriteTimeUtcTicks -or
        $Actual.CreationTimeUtcTicks -ne $Expected.CreationTimeUtcTicks -or
        $Actual.FileIdentity -cne $Expected.FileIdentity) {
        throw "$Label|TUPLE_DRIFT"
    }
}
function Test-AuthTupleEqualV2($Actual,$Expected) {
    try { Assert-AuthTupleV2 $Actual $Expected 'tuple-equality'; return $true } catch { return $false }
}
function Get-AuthAllowedTransitionsV2 {
    return @{
        INIT=@('DIAGNOSTIC_CLOSED','ABORTED')
        DIAGNOSTIC_CLOSED=@('OPENED','ABORTED')
        OPENED=@('MUTATED','ABORTED')
        MUTATED=@('SAVE_CLAIMED','ABORTED')
        SAVE_CLAIMED=@('CLASSIFIED','INDETERMINATE','RECOVERY_BLOCKED')
        CLASSIFIED=@('VERIFYING','RECOVERY_BLOCKED')
        INDETERMINATE=@('VERIFYING','RECOVERY_BLOCKED')
        VERIFYING=@('VERIFYING','VERIFIED','RECOVERY_BLOCKED')
        VERIFIED=@('COMMITTED','RESTORE_AUTHORIZED','TERMINAL_NOT_PERSISTED','RECOVERY_BLOCKED')
        RESTORE_AUTHORIZED=@('RESTORED','RECOVERY_BLOCKED')
        RESTORED=@('ROLLBACK_VERIFYING','RECOVERY_BLOCKED')
        ROLLBACK_VERIFYING=@('ROLLBACK_VERIFIED','RECOVERY_BLOCKED')
        ROLLBACK_VERIFIED=@('CLOSED')
        COMMITTED=@('CLOSED')
        TERMINAL_NOT_PERSISTED=@('CLOSED')
        ABORTED=@('CLOSED')
        RECOVERY_BLOCKED=@()
        CLOSED=@()
    }
}
function Get-AuthVerifierAttemptRowsV2($Record) {
    return @($Record.VerifierReceipts | Where-Object {
        $_.PSObject.Properties.Name -contains 'Kind' -and $_.Kind -ceq 'OUTCOME'
    })
}
function Assert-AuthRecordStateV2($Record,$Previous,[string]$Label) {
    $states = Get-AuthAllowedTransitionsV2
    if (-not $states.ContainsKey([string]$Record.State)) { throw "$Label|UNKNOWN_STATE:$($Record.State)" }
    if ($null -eq $Previous) {
        if ($Record.State -cne 'INIT' -or $Record.SaveAttemptCount -ne 0 -or
            @(Get-AuthVerifierAttemptRowsV2 $Record).Count -ne 0) {
            throw "$Label|INVALID_ROOT_STATE"
        }
    } else {
        $allowed = @($states[[string]$Previous.State])
        if ($Record.State -notin $allowed) {
            throw "$Label|ILLEGAL_TRANSITION:$($Previous.State):$($Record.State)"
        }
        if ($Record.SaveAttemptCount -lt $Previous.SaveAttemptCount -or
            $Record.SaveAttemptCount -gt 1) { throw "$Label|SAVE_ATTEMPT_RESET_OR_DUPLICATE" }
        $before = @(Get-AuthVerifierAttemptRowsV2 $Previous)
        $after = @(Get-AuthVerifierAttemptRowsV2 $Record)
        if ($after.Count -lt $before.Count -or $after.Count -gt 2) {
            throw "$Label|VERIFIER_ATTEMPT_RESET_OR_DUPLICATE"
        }
    }
    if ($Record.State -in @('INIT','DIAGNOSTIC_CLOSED','OPENED','MUTATED','ABORTED') -and
        $Record.SaveAttemptCount -ne 0) { throw "$Label|PRE_SAVE_STATE_HAS_SAVE_CLAIM" }
    if ($Record.State -in @('SAVE_CLAIMED','CLASSIFIED','INDETERMINATE','VERIFYING','VERIFIED','COMMITTED','RESTORE_AUTHORIZED','RESTORED','ROLLBACK_VERIFYING','ROLLBACK_VERIFIED','TERMINAL_NOT_PERSISTED') -and
        $Record.SaveAttemptCount -ne 1) { throw "$Label|POST_SAVE_STATE_MISSING_SAVE_CLAIM" }
}
function Read-AuthJournalV2($Authority,[string]$Label) {
    Assert-AuthAuthorityHeld $Authority "$Label-held-before-read"
    $text = Read-AuthStreamText $Authority.Raw.JournalStream
    $records=@(); $previousHmac='0'*64; $previousRecord=$null; $generation=0; $immutable=$null
    foreach ($line in @($text -split "`n" | Where-Object { $_ -cne '' })) {
        $record = ConvertFrom-AuthStrictJson $line "$Label-line"
        Assert-AuthKeys $record @('AuthorityId','BackupPath','B0','CanonicalPath','Cleanup','CreatedUtc','Disk','Generation','ImplementationContractSHA256','KeyId','P0','PreviousRecordHmacSHA256','RecordHmacSHA256','Restore','SaveAttemptCount','SaveRequestSHA256','SaveResponseSHA256','State','TransactionId','VerifierReceipts','Version') "$Label-record"
        if (($record.Version -isnot [int] -and $record.Version -isnot [long]) -or $record.Version -ne 2 -or
            ($record.Generation -isnot [int] -and $record.Generation -isnot [long]) -or
            $record.Generation -ne ($generation+1) -or
            $record.PreviousRecordHmacSHA256 -cne $previousHmac -or
            $record.AuthorityId -cne $Authority.Anchor.AuthorityId -or
            $record.KeyId -cne $Authority.Anchor.KeyId) { throw "$Label|CHAIN_OR_AUTHORITY_DRIFT" }
        $expected = Get-AuthHmac $Authority.Key (Get-AuthCanonicalJson (Get-AuthRecordPayload $record))
        if ($expected -cne $record.RecordHmacSHA256) { throw "$Label|HMAC_INVALID" }
        $fixed = @($record.TransactionId,$record.CanonicalPath,$record.BackupPath,
            (Get-AuthCanonicalJson $record.P0),(Get-AuthCanonicalJson $record.B0),
            $record.ImplementationContractSHA256) -join '|'
        if ($null -eq $immutable) { $immutable=$fixed } elseif ($fixed -cne $immutable) {
            throw "$Label|IMMUTABLE_ATTEMPT_FIELD_DRIFT"
        }
        Assert-AuthRecordStateV2 $record $previousRecord $Label
        $records += ,$record; $previousRecord=$record
        $previousHmac=$record.RecordHmacSHA256; $generation=[long]$record.Generation
    }
    $anchorGeneration=[long]$Authority.Anchor.JournalGeneration
    $anchorHead=[string]$Authority.Anchor.JournalHeadHmacSHA256
    if ($generation -eq $anchorGeneration -and $previousHmac -ceq $anchorHead) {
        # fully checkpointed
    } elseif ($generation -eq ($anchorGeneration+1) -and $records.Count -gt 0 -and
        $records[-1].PreviousRecordHmacSHA256 -ceq $anchorHead) {
        # One authentic flushed journal record may precede its anchor update after a crash.
        Write-AuthAnchorCheckpoint $Authority $generation $previousHmac
    } else {
        throw "$Label|REPLAY_OR_MULTI_RECORD_CHECKPOINT_GAP"
    }
    Assert-AuthAuthorityHeld $Authority "$Label-held-after-read"
    [void]($Authority.Records=$records)
    return @($records)
}
function Assert-AuthReadbackV2($Raw,[string]$Phase,[ValidateSet('PRE','FINAL')][string]$State) {
    $value=ConvertFrom-AuthStrictJson $Raw "readback-$Phase"
    Assert-AuthKeys $value @('phase','protected_sha256','result_ids','state','transport_response_sha256') "READBACK_ROOT:$Phase"
    $ids=@($value.result_ids); $hashes=@($value.transport_response_sha256)
    if ($value.phase -isnot [string] -or $value.phase -cne $Phase -or
        $value.state -isnot [string] -or $value.state -cne $State -or
        $value.protected_sha256 -isnot [string] -or $value.protected_sha256 -cnotmatch '^[0-9A-F]{64}$' -or
        $value.result_ids -isnot [Array] -or ($ids -join '|') -cne ((1..14) -join '|') -or
        @($ids | Where-Object { $_ -isnot [int] }).Count -ne 0 -or
        $value.transport_response_sha256 -isnot [Array] -or $hashes.Count -ne 14 -or
        @($hashes | Sort-Object -Unique).Count -ne 14 -or
        @($hashes | Where-Object { $_ -isnot [string] -or $_ -cnotmatch '^[0-9A-F]{64}$' }).Count -ne 0) {
        throw "READBACK_SEMANTIC_DRIFT:$Phase"
    }
    return $value
}
function Assert-AuthOperationResponseV2($Raw,[string]$Operation,[string]$ExpectedRequestSHA256) {
    $value=ConvertFrom-AuthStrictJson $Raw "operation-$Operation"
    Assert-AuthKeys $value @('ok','operation','request_sha256') "OPERATION_$Operation"
    if ($value.ok -isnot [bool] -or -not $value.ok -or
        $value.operation -isnot [string] -or $value.operation -cne $Operation -or
        $value.request_sha256 -isnot [string] -or
        $value.request_sha256 -cne $ExpectedRequestSHA256) {
        throw "OPERATION_RESPONSE_CORRELATION_DRIFT:$Operation"
    }
    return $value
}
function Get-AuthSaveClassificationV2($Raw,[string]$CanonicalPath,[long]$ExpectedRequestId) {
    try {
        $value=ConvertFrom-AuthStrictJson $Raw 'save-response'
        Assert-AuthKeys $value @('error','id','jsonrpc','result') 'SAVE_ROOT'
        if ($value.jsonrpc -isnot [string] -or $value.jsonrpc -cne '2.0' -or
            ($value.id -isnot [int] -and $value.id -isnot [long]) -or
            [long]$value.id -ne $ExpectedRequestId) { throw 'SAVE_RPC_NATIVE_OR_ID_DRIFT' }
        $hasResult=$null-ne$value.result; $hasError=$null-ne$value.error
        if ($hasResult -eq $hasError) { throw 'SAVE_RESULT_ERROR_EXCLUSIVITY' }
        if ($hasResult) {
            Assert-AuthKeys $value.result @('error','ok','path') 'SAVE_RESULT'
            if ($value.result.ok -isnot [bool] -or -not $value.result.ok -or
                $value.result.path -isnot [string] -or $value.result.path -cne $CanonicalPath -or
                $null-ne$value.result.error) { throw 'SAVE_SUCCESS_SHAPE_DRIFT' }
            return [pscustomobject]@{Class='SUCCESS';ResponseSHA256=Get-AuthTextSHA256 $Raw;Error=''}
        }
        Assert-AuthKeys $value.error @('code','data','message') 'SAVE_ERROR'
        if ($value.error.code -isnot [int] -or $value.error.message -isnot [string] -or
            $value.error.data -isnot [string]) { throw 'SAVE_ERROR_NATIVE_DRIFT' }
        return [pscustomobject]@{Class='EXPLICIT_FAILURE';ResponseSHA256=Get-AuthTextSHA256 $Raw;Error=''}
    } catch {
        return [pscustomobject]@{Class='INDETERMINATE';ResponseSHA256=Get-AuthTextSHA256 ([string]$Raw);Error=$_.Exception.GetBaseException().Message}
    }
}
function Get-AuthExactErrorCodeV2([string]$Message) {
    if ([string]::IsNullOrWhiteSpace($Message)) { return '' }
    return @($Message -split '\|',2)[0]
}
~~~

## Removed Block R014

- SHA256: `CDC70CF5523AEC7AE52EF0CE5E3A79736B2CE1AF9C244A47C39BC828D6AEDBD8`
- Language: `powershell`
- Bytes: `31794`
- First recovered timestamp: `2026-08-08T01:58:30.328Z`
- Session provenance: rollout-2026-08-07T21-20-26-019fdef5-0290-7382-a292-6b4f8a280426.jsonl line 195492 (2026-08-08T01:58:30.328Z); rollout-2026-08-07T21-20-26-019fdef5-0290-7382-a292-6b4f8a280426.jsonl line 195493 (2026-08-08T01:58:30.670Z)

~~~powershell
function Add-AuthRequestReceiptV2($Authority,$Counters,$Base,[string]$ReceiptId,[string]$Operation,[string]$RequestSHA256,[string]$ResponseSHA256,$CleanupRegistry) {
    foreach($hash in @($RequestSHA256,$ResponseSHA256)){if($hash-cnotmatch'^[0-9A-F]{64}$'){throw "V2_REQUEST_RECEIPT_HASH_INVALID:$ReceiptId"}}
    $last=@(Read-AuthJournalV2 $Authority "v2-request-$ReceiptId")[-1];$prior=@($last.RequestReceipts)
    if(@($prior|Where-Object{[string]$_.ReceiptId-ceq$ReceiptId}).Count-ne 0){throw "V2_REQUEST_RECEIPT_DUPLICATE:$ReceiptId"}
    $receipt=[ordered]@{ReceiptId=$ReceiptId;Operation=$Operation;RequestSHA256=$RequestSHA256;ResponseSHA256=$ResponseSHA256}
    return Add-AuthJournalRecordV2 $Authority $Counters ([string]$last.State) $Base @{RequestReceipts=@($prior+$receipt);Cleanup=@(Get-AuthCleanupSnapshotV2 $CleanupRegistry)}
}
function Add-AuthReadbackReceiptV2($Authority,$Counters,$Base,[string]$ReceiptId,[string]$Phase,[string]$ResponseSHA256,[string]$SemanticSHA256,$CleanupRegistry) {
    foreach($hash in @($ResponseSHA256,$SemanticSHA256)){if($hash-cnotmatch'^[0-9A-F]{64}$'){throw "V2_READBACK_RECEIPT_HASH_INVALID:$ReceiptId"}}
    $last=@(Read-AuthJournalV2 $Authority "v2-readback-$ReceiptId")[-1];$prior=@($last.ReadbackReceipts)
    if(@($prior|Where-Object{[string]$_.ReceiptId-ceq$ReceiptId}).Count-ne 0){throw "V2_READBACK_RECEIPT_DUPLICATE:$ReceiptId"}
    $receipt=[ordered]@{ReceiptId=$ReceiptId;Phase=$Phase;ResponseSHA256=$ResponseSHA256;SemanticSHA256=$SemanticSHA256}
    return Add-AuthJournalRecordV2 $Authority $Counters ([string]$last.State) $Base @{ReadbackReceipts=@($prior+$receipt);Cleanup=@(Get-AuthCleanupSnapshotV2 $CleanupRegistry)}
}
function Get-AuthPlanV2([string]$Name) {
    $contracts=Read-AuthFrozenContract $AuthContracts 'UID0003YUContracts'
    if($Name-notin@('Collision','DryRun','I01','I02','I03')){throw "V2_UNKNOWN_FROZEN_PLAN:$Name"}
    $value=$contracts.$Name;$json=Get-AuthCanonicalJson $value;$sha=Get-AuthTextSHA256 $json
    return [pscustomobject]@{Name=$Name;CanonicalJson=$json;SHA256=$sha;Value=(ConvertFrom-AuthStrictJson $json "v2-plan-$Name")}
}
function Invoke-AuthPlanV2($Context,$Authority,$Base,$CleanupRegistry,$Counters,[string]$Role,[string]$Name,[string]$TransportOperation) {
    $plan=Get-AuthPlanV2 $Name
    $payload=[ordered]@{role_id=$Role;operation=$Name;contract=$plan.Value}
    $raw=&$Context.Transport $TransportOperation $payload;Add-AuthCount $Counters Transport
    if((Get-AuthTextSHA256 (Get-AuthCanonicalJson $payload.contract))-cne$plan.SHA256){throw "V2_FROZEN_PLAN_MUTATED_BY_TRANSPORT:$Name"}
    $null=Assert-AuthOperationResponseV2 $raw $Name $plan.SHA256
    $null=Add-AuthRequestReceiptV2 $Authority $Counters $Base $Name $Name $plan.SHA256 (Get-AuthTextSHA256 $raw) $CleanupRegistry
    return $raw
}
function Invoke-AuthReadbackPhaseV2($Context,$Authority,$Base,$CleanupRegistry,$Counters,[string]$Role,[string]$Phase,[ValidateSet('PRE','FINAL')][string]$State) {
    $raw=&$Context.Transport 'readback' ([ordered]@{role_id=$Role;phase=$Phase;state=$State});Add-AuthCount $Counters Transport;Add-AuthCount $Counters Readback
    $value=Assert-AuthReadbackV2 $raw $Phase $State
    $semantic=Get-AuthTextSHA256 (Get-AuthCanonicalJson ([ordered]@{phase=$value.phase;protected_sha256=$value.protected_sha256;result_ids=$value.result_ids;state=$value.state;transport_response_sha256=$value.transport_response_sha256}))
    $null=Add-AuthReadbackReceiptV2 $Authority $Counters $Base $Phase $Phase (Get-AuthTextSHA256 $raw) $semantic $CleanupRegistry
    return $semantic
}
function Close-AuthPreSaveFailureV2($Context,$Authority,$Base,$CleanupRegistry,$Counters,[string]$OriginalMessage) {
    $errors=@()
    try{$null=Complete-AuthRetirementV2 $Context $CleanupRegistry $Counters 'v2-pre-save-failure'}catch{$errors+=$_.Exception.GetBaseException().Message}
    try{
        $last=@(Read-AuthJournalV2 $Authority 'v2-pre-save-failure-state')[-1]
        if($last.State-in@('INIT','DIAGNOSTIC_CLOSED','OPENED','MUTATED')){$last=Add-AuthJournalRecordV2 $Authority $Counters 'ABORTED' $Base @{Cleanup=@(Get-AuthCleanupSnapshotV2 $CleanupRegistry)}}
        if($last.State-ceq'ABORTED'){$null=Add-AuthJournalRecordV2 $Authority $Counters 'CLOSED' $Base @{Cleanup=@(Get-AuthCleanupSnapshotV2 $CleanupRegistry)}}
    }catch{$errors+=$_.Exception.GetBaseException().Message}
    if($errors.Count-ne 0){throw "V2_PRE_SAVE_CLOSURE_FAILED|original=$OriginalMessage|closure=$($errors-join';')"}
}
function Invoke-UID0003YUClosedCoordinator($Context) {
    $counters=New-AuthCounters
    if($Context.PSObject.Properties.Name-contains'LastCounters'){$Context.LastCounters=$counters}else{$Context|Add-Member -NotePropertyName LastCounters -NotePropertyValue $counters}
    $authority=$null;$base=$null;$p0=$null;$b0=$null;$dOpen=$null;$saveClaimed=$false;$saveRequestHash='';$classification=$null
    $cleanup=[Collections.Generic.List[object]]::new();$readbackHashes=@();$verifiers=@()
    $contracts=Read-AuthFrozenContract $AuthContracts 'UID0003YUContracts'
    if($Context.ContractDigest-isnot[string]-or$Context.ContractDigest-cne$AuthContracts.SHA256){throw 'V2_FROZEN_CONTRACT_DIGEST_LIE'}
    if($Context.ImplementationContractSHA256-isnot[string]-or$Context.ImplementationContractSHA256-cnotmatch'^[0-9A-F]{64}$'){throw 'V2_IMPLEMENTATION_CONTRACT_MISSING'}
    try {
        $authority=Initialize-AuthAuthorityBindingV2 (Open-AuthAuthority $Context $counters)
        $chain=@(Read-AuthJournalV2 $authority 'v2-coordinator-open')
        if($chain.Count-eq 0){
            $p0=&$Context.Disk 'capture-p0' $null;$p0Confirm=&$Context.Disk 'capture-p0-confirm' $null;Assert-AuthTupleV2 $p0Confirm $p0 'V2_P0_CONFIRM'
            $b0=&$Context.Disk 'create-b0' $p0;$b0Confirm=&$Context.Disk 'capture-b0-confirm' $null;Assert-AuthTupleV2 $b0Confirm $b0 'V2_B0_CONFIRM'
            if($p0.Path-ceq$b0.Path-or$p0.FileIdentity-ceq$b0.FileIdentity-or$p0.Length-ne$b0.Length-or$p0.SHA256-cne$b0.SHA256-or$p0.LastWriteTimeUtcTicks-ne$b0.LastWriteTimeUtcTicks){throw 'V2_B0_NOT_EXACT_DISTINCT_COPY'}
            $base=[ordered]@{TransactionId=[guid]::NewGuid().ToString('N');CanonicalPath=$Context.CanonicalPath;BackupPath=$Context.BackupPath;P0=$p0;B0=$b0;ImplementationContractSHA256=$Context.ImplementationContractSHA256;ContractSHA256=$AuthContracts.SHA256}
            $last=Add-AuthJournalRecordV2 $authority $counters 'INIT' $base @{}
        } else {
            $last=$chain[-1]
            $base=[ordered]@{TransactionId=[string]$last.TransactionId;CanonicalPath=[string]$last.CanonicalPath;BackupPath=[string]$last.BackupPath;P0=$last.P0;B0=$last.B0;ImplementationContractSHA256=[string]$last.ImplementationContractSHA256;ContractSHA256=[string]$last.ContractSHA256}
            if($base.ContractSHA256-cne$AuthContracts.SHA256-or$base.ImplementationContractSHA256-cne$Context.ImplementationContractSHA256){throw 'V2_RESTART_CONTRACT_OR_IMPLEMENTATION_DRIFT'}
            $p0=New-AuthTupleV2 $last.P0.Path $last.P0.Length $last.P0.SHA256 $last.P0.LastWriteTimeUtcTicks $last.P0.FileIdentity $last.P0.CreationTimeUtcTicks
            $b0=New-AuthTupleV2 $last.B0.Path $last.B0.Length $last.B0.SHA256 $last.B0.LastWriteTimeUtcTicks $last.B0.FileIdentity $last.B0.CreationTimeUtcTicks
            if(-not(& $Context.Disk 'verify-original-baselines' ([ordered]@{P0=$p0;B0=$b0}))){throw 'V2_RESTART_ORIGINAL_BASELINE_REPLACED'}
            Import-AuthCleanupRegistryV2 $cleanup $last.Cleanup
            if(@($cleanup|Where-Object{-not$_.Retired}).Count-ne 0){$null=Complete-AuthRetirementV2 $Context $cleanup $counters 'v2-restart-retirement';$last=Add-AuthJournalRecordV2 $authority $counters ([string]$last.State) $base @{Cleanup=@(Get-AuthCleanupSnapshotV2 $cleanup)}}
            if($last.SaveAttemptCount-ne 0){
                if($last.State-ceq'CLOSED'){throw 'V2_DURABLE_ONE_SAVE_ALREADY_CLAIMED'}
                $saveClaimed=$true;$saveRequestHash=[string]$last.SaveRequestSHA256;$classification=[pscustomobject]@{Class='INDETERMINATE';ResponseSHA256=[string]$last.SaveResponseSHA256;Error='restart-after-save'}
                $closure=Complete-AuthPostDispatchRecoveryV2 $Context $authority $base $p0 $b0 $saveRequestHash $classification $counters $cleanup 'V2_RESTART_POST_SAVE'
                throw "V2_RESTART_RECOVERED_NO_REUSE|terminal=$($closure.State)"
            }
            if($last.State-cne'INIT'){throw "V2_RESTART_PRE_SAVE_NO_REUSE|state=$($last.State)"}
        }

        $catalog=&$Context.Transport 'catalog' $null;Add-AuthCount $counters Transport;Assert-AuthCatalog $catalog $AuthContracts
        $diagnostic=Invoke-AuthOpenV2 $Context 'diagnostic-open' ([ordered]@{preferred_id='uid0003yu-diagnostic';canonical_path=$Context.CanonicalPath}) $cleanup $counters 'v2-diagnostic' $authority $base
        $runtime=&$Context.Transport 'runtime' ([ordered]@{role_id=$diagnostic});Add-AuthCount $counters Transport;$null=Assert-AuthRuntimeV2 $runtime $diagnostic $Context.CanonicalPath $Context.ImplementationContractSHA256
        $readbackHashes+=, (Invoke-AuthReadbackPhaseV2 $Context $authority $base $cleanup $counters $diagnostic 'diagnostic-pre' 'PRE')
        $null=Complete-AuthRetirementV2 $Context $cleanup $counters 'v2-diagnostic'
        $last=Add-AuthJournalRecordV2 $authority $counters 'DIAGNOSTIC_CLOSED' $base @{Cleanup=@(Get-AuthCleanupSnapshotV2 $cleanup)}

        $dOpen=&$Context.Disk 'tuple' ([ordered]@{name='Dopen'});Assert-AuthTupleV2 $dOpen $p0 'V2_DOPEN'
        $catalog=&$Context.Transport 'catalog' $null;Add-AuthCount $counters Transport;Assert-AuthCatalog $catalog $AuthContracts
        $role=Invoke-AuthOpenV2 $Context 'open' ([ordered]@{preferred_id='uid0003yu-transaction';canonical_path=$Context.CanonicalPath}) $cleanup $counters 'v2-transaction' $authority $base
        $runtime=&$Context.Transport 'runtime' ([ordered]@{role_id=$role});Add-AuthCount $counters Transport;$null=Assert-AuthRuntimeV2 $runtime $role $Context.CanonicalPath $Context.ImplementationContractSHA256
        $last=Add-AuthJournalRecordV2 $authority $counters 'OPENED' $base @{Cleanup=@(Get-AuthCleanupSnapshotV2 $cleanup);Disk=[ordered]@{Dopen=$dOpen}}
        $null=Invoke-AuthPlanV2 $Context $authority $base $cleanup $counters $role 'Collision' 'collision'
        $null=Invoke-AuthPlanV2 $Context $authority $base $cleanup $counters $role 'DryRun' 'dry-run'
        $readbackHashes+=,(Invoke-AuthReadbackPhaseV2 $Context $authority $base $cleanup $counters $role 'pre-I01' 'PRE')
        $null=Invoke-AuthPlanV2 $Context $authority $base $cleanup $counters $role 'I01' 'mutation'
        $readbackHashes+=,(Invoke-AuthReadbackPhaseV2 $Context $authority $base $cleanup $counters $role 'post-I01' 'FINAL')
        $null=Invoke-AuthPlanV2 $Context $authority $base $cleanup $counters $role 'I02' 'mutation'
        $postI02a=Invoke-AuthReadbackPhaseV2 $Context $authority $base $cleanup $counters $role 'post-I02-a' 'FINAL';$readbackHashes+=,$postI02a
        $postI02b=Invoke-AuthReadbackPhaseV2 $Context $authority $base $cleanup $counters $role 'post-I02-b' 'FINAL';$readbackHashes+=,$postI02b
        if($postI02a-cne$postI02b){throw 'V2_POST_I02_REPEAT_DRIFT'}
        $null=Invoke-AuthPlanV2 $Context $authority $base $cleanup $counters $role 'I03' 'mutation'
        $readbackHashes+=,(Invoke-AuthReadbackPhaseV2 $Context $authority $base $cleanup $counters $role 'post-I03' 'FINAL')
        $readbackHashes+=,(Invoke-AuthReadbackPhaseV2 $Context $authority $base $cleanup $counters $role 'pre-save' 'FINAL')
        $last=Add-AuthJournalRecordV2 $authority $counters 'MUTATED' $base @{Cleanup=@(Get-AuthCleanupSnapshotV2 $cleanup);Disk=[ordered]@{Dopen=$dOpen}}

        $saveRequest=[ordered]@{database=$role;path=$Context.CanonicalPath;request_id=[long]1};$saveRequestHash=Get-AuthTextSHA256 (Get-AuthCanonicalJson $saveRequest)
        $last=Add-AuthJournalRecordV2 $authority $counters 'SAVE_CLAIMED' $base @{SaveAttemptCount=1;SaveRequestSHA256=$saveRequestHash;Cleanup=@(Get-AuthCleanupSnapshotV2 $cleanup)};$saveClaimed=$true
        $saveRaw='';try{Add-AuthCount $counters Transport;Add-AuthCount $counters Save;$saveRaw=&$Context.Transport 'save' $saveRequest;$classification=Get-AuthSaveClassificationV2 $saveRaw $Context.CanonicalPath 1}catch{$classification=[pscustomobject]@{Class='INDETERMINATE';ResponseSHA256=(Get-AuthTextSHA256 '');Error=$_.Exception.GetBaseException().Message}};Add-AuthCount $counters Classifier
        $classState=if($classification.Class-ceq'INDETERMINATE'){'INDETERMINATE'}else{'CLASSIFIED'}
        $last=Add-AuthJournalRecordV2 $authority $counters $classState $base @{SaveResponseSHA256=[string]$classification.ResponseSHA256;Cleanup=@(Get-AuthCleanupSnapshotV2 $cleanup)}
        $null=Add-AuthRequestReceiptV2 $authority $counters $base 'save' 'idb_save' $saveRequestHash ([string]$classification.ResponseSHA256) $cleanup
        $retirement=Complete-AuthRetirementV2 $Context $cleanup $counters 'v2-transaction'
        $dClosed=&$Context.Disk 'tuple' ([ordered]@{name='Dclosed'});$diskState=Get-AuthDiskStateV2 $dClosed $p0 'V2_DCLOSED'
        if($classification.Class-ceq'SUCCESS'-and$diskState-cne'FINAL'){$classification=[pscustomobject]@{Class='INDETERMINATE';ResponseSHA256=$classification.ResponseSHA256;Error='success-with-pre-disk'};$last=Add-AuthJournalRecordV2 $authority $counters 'INDETERMINATE' $base @{Cleanup=@($retirement)}}
        $required=if($classification.Class-ceq'SUCCESS'-and$diskState-ceq'FINAL'){1}else{2}
        $verifiers=Invoke-AuthVerifierSetV2 $Context $authority $base $required $diskState $dClosed $counters $cleanup $retirement
        $retirement=@(Get-AuthCleanupSnapshotV2 $cleanup)
        $p1=&$Context.Disk 'tuple' ([ordered]@{name='P1'});Assert-AuthTupleV2 $p1 $dClosed 'V2_P1_STABILITY'
        $last=Add-AuthJournalRecordV2 $authority $counters 'VERIFIED' $base @{Cleanup=@($retirement);Disk=[ordered]@{Dopen=$dOpen;Dclosed=$dClosed;P1=$p1};VerifierReceipts=@($verifiers)}
        if($classification.Class-ceq'SUCCESS'-and$diskState-ceq'FINAL'){$last=Add-AuthJournalRecordV2 $authority $counters 'COMMITTED' $base @{Cleanup=@($retirement)};$last=Add-AuthJournalRecordV2 $authority $counters 'CLOSED' $base @{Cleanup=@($retirement)}}
        elseif($diskState-ceq'PRE'){$last=Add-AuthJournalRecordV2 $authority $counters 'TERMINAL_NOT_PERSISTED' $base @{Cleanup=@($retirement)};$last=Add-AuthJournalRecordV2 $authority $counters 'CLOSED' $base @{Cleanup=@($retirement)}}
        else{$last=Invoke-AuthHeldRestoreV2 $Context $authority $base $p0 $b0 $p1 $saveRequestHash ([string]$classification.ResponseSHA256 $verifiers $retirement $counters $cleanup 'v2-normal-restore')}
        return [pscustomobject]@{Marker='UID0003YU_V2_COORDINATOR_CLOSED';Classification=$classification.Class;State=[string]$last.State;Vector=(Get-AuthVector $counters);Counters=$counters;VerifierCount=@($verifiers).Count;ReadbackHashes=@($readbackHashes);RecordHmac=[string]$last.RecordHmacSHA256}
    } catch {
        $original=$_;$message=$original.Exception.GetBaseException().Message
        if($null-ne$authority-and$null-ne$base){
            if($saveClaimed){return Complete-AuthPostDispatchRecoveryV2 $Context $authority $base $p0 $b0 $saveRequestHash $classification $counters $cleanup $message}
            Close-AuthPreSaveFailureV2 $Context $authority $base $cleanup $counters $message
        }
        throw $original
    } finally { Close-AuthAuthority $authority $Context }
}

function New-UID0003YUHostileRuntimeV2([string]$Role,[string]$Implementation,[string]$Fault) {
    $module={param([string]$Name,[string]$Id)[ordered]@{ctime_ns=[long]11;file='memory:module';file_identity="module-$Name";module_id=$Id;mtime_ns=[long]12;name=$Name;resolved_path='memory:module';sha256=('D'*64);size=[long]1;spec_origin='memory:module'}}
    $listenerModules=[object[]]@((&$module 'listener-module' '0x1'));$redirectorModules=[object[]]@((&$module 'redirector-module' '0x2'));$roleModules=[object[]]@((&$module 'role-module' '0x3'))
    if($Fault-ceq'FXV2_06_RUNTIME_MANIFEST'){$roleModules=[object[]]@()}
    $listener=[ordered]@{argv=[object[]]@('python.exe','listener');creation_time_100ns='100';executable='python.exe';modules=$listenerModules;parent_pid=1;pid=2;port=13337;socket_owner=2}
    $redirector=[ordered]@{argv=[object[]]@('python.exe','redirector');creation_time_100ns='101';executable='python.exe';modules=$redirectorModules;parent_pid=1;pid=3;port=13337;socket_owner=3}
    $worker=[ordered]@{argv=[object[]]@('python.exe','worker');creation_time_100ns='102';executable='python.exe';modules=$roleModules;parent_pid=3;pid=4;port=14004;socket_owner=4}
    if($Fault-ceq'FXV2_05_RUNTIME_PROCESS'){$worker.socket_owner=99}
    $normalized={param($Rows)@($Rows|ForEach-Object{[ordered]@{ctime_ns=[long]$_.ctime_ns;file=[string]$_.file;file_identity=[string]$_.file_identity;module_id=[string]$_.module_id;mtime_ns=[long]$_.mtime_ns;name=[string]$_.name;resolved_path=[string]$_.resolved_path;sha256=[string]$_.sha256;size=[long]$_.size;spec_origin=[string]$_.spec_origin}}|Sort-Object name)}
    $aggregate=Get-AuthTextSHA256 (Get-AuthCanonicalJson ([ordered]@{listener=(&$normalized $listenerModules);redirector=(&$normalized $redirectorModules);role=(&$normalized $roleModules)}))
    return ([ordered]@{aggregate_manifest_sha256=$aggregate;canonical_path='memory:canonical';errors=[object[]]@();implementation_contract_sha256=$Implementation;listener=$listener;ok=$true;redirector=$redirector;role=$worker;schema_version=1;session=$Role}|ConvertTo-Json -Depth 30 -Compress)
}
function New-UID0003YUHostileContextV2([string]$Fault,$State) {
    if($null-eq$State){
        $p0Bytes=[byte[]](1,2,3);$savedBytes=[byte[]](4,5,6,7);$sha=[Security.Cryptography.SHA256]::Create();try{$p0Hash=([BitConverter]::ToString($sha.ComputeHash($p0Bytes))).Replace('-','');$savedHash=([BitConverter]::ToString($sha.ComputeHash($savedBytes))).Replace('-','')}finally{$sha.Dispose()}
        $State=[pscustomobject]@{Key=[Text.Encoding]::UTF8.GetBytes('0123456789ABCDEF0123456789ABCDEF');AnchorBytes=[byte[]]@();JournalBytes=[byte[]]@();AnchorIdentity='v2-anchor-1';JournalIdentity='v2-journal-1';KeyIdentity='v2-key-1';OpenCount=0;SaveCalls=0;VerifierOpenCalls=0;RetireCalls=0;Observations=[Collections.Generic.List[object]]::new();P0Bytes=$p0Bytes;SavedBytes=$savedBytes;P0=(New-AuthTupleV2 'memory:canonical' 3 $p0Hash 100 'canonical-id-1' 90);B0=(New-AuthTupleV2 'memory:backup' 3 $p0Hash 100 'backup-id-1' 95);Saved=(New-AuthTupleV2 'memory:canonical' 4 $savedHash 200 'canonical-id-1' 90);Current=$null}
        $State.Current=$State.P0
    }
    $implementation='C'*64;$schemaHashes=$AuthSchemaHashes
    $foreign=New-AuthTupleV2 'memory:canonical' 5 ('7'*64) 201 'canonical-id-foreign' 91
    $journal={param($op,$value)
        if($op-ceq'open'){
            $k=[IO.MemoryStream]::new();$protected=Protect-AuthKey $State.Key;$kb=[Text.UTF8Encoding]::new($false).GetBytes($protected);$k.Write($kb,0,$kb.Length)
            $a=[IO.MemoryStream]::new();if($State.AnchorBytes.Length-ne 0){$a.Write($State.AnchorBytes,0,$State.AnchorBytes.Length)}
            $j=[IO.MemoryStream]::new();if($State.JournalBytes.Length-ne 0){$j.Write($State.JournalBytes,0,$State.JournalBytes.Length)}
            return [pscustomobject]@{AuthorityKey=[byte[]]$State.Key;AuthorityKeyId=(Get-AuthSHA256 $State.Key);AuthorityKeyIdentity=$State.KeyIdentity;AuthorityKeyPath='memory:key';AuthorityKeyStream=$k;AnchorIdentity=$State.AnchorIdentity;AnchorPath='memory:anchor';AnchorStream=$a;JournalIdentity=$State.JournalIdentity;JournalPath='memory:journal';JournalStream=$j}
        }
        if($op-ceq'close'){$State.AnchorBytes=$value.AnchorStream.ToArray();$State.JournalBytes=$value.JournalStream.ToArray();$value.JournalStream.Dispose();$value.AnchorStream.Dispose();$value.AuthorityKeyStream.Dispose();return}
        throw "V2_FIXTURE_UNKNOWN_JOURNAL:$op"
    }.GetNewClosure()
    $process={param($op,$payload)
        if($op-ceq'snapshot'){return [pscustomobject]@{Count=[int]$State.Observations.Count}}
        if($op-ceq'diff'){$rows=@();for($i=[int]$payload.pre.Count;$i-lt$State.Observations.Count;$i++){$rows+=,$State.Observations[$i]};return ($rows|ConvertTo-Json -Depth 10 -Compress -AsArray)}
        if($op-ceq'retire'){$State.RetireCalls++;$receipt=Get-AuthTextSHA256 (Get-AuthCanonicalJson ([ordered]@{generation=$payload.ProcessGeneration;session=$payload.ReturnedSession;socket=$payload.Socket}));if($Fault-ceq'FXV2_04_PARTIAL_OPEN_CLEANUP'){return ([ordered]@{active_sessions=0;canonical_exclusive=$true;owned_processes=0;owned_sockets=0;receipt_sha256=$receipt;unproven_processes=[object[]]@([ordered]@{pid=99;reason='unproven'})}|ConvertTo-Json -Depth 10 -Compress)};return ([ordered]@{active_sessions=0;canonical_exclusive=$true;owned_processes=0;owned_sockets=0;receipt_sha256=$receipt;unproven_processes=[object[]]@()}|ConvertTo-Json -Compress)}
        throw "V2_FIXTURE_UNKNOWN_PROCESS:$op"
    }.GetNewClosure()
    $newObservation={param([string]$Preferred,[string]$Role)$State.OpenCount++;$row=[ordered]@{canonical_path='memory:canonical';preferred_id=$Preferred;process_generation="pid:$($State.OpenCount);created:1";returned_session=$Role;socket="127.0.0.1:$($State.OpenCount)"};$State.Observations.Add([pscustomobject]$row);return $row}.GetNewClosure()
    $transport={param($op,$payload)
        switch($op){
            'catalog'{if($Fault-ceq'FXV2_01_RECURSIVE_DUPLICATE_JSON'){return '{"tools":[],"schemas":{"idb_save":"A","idb_save":"B"}}'};$schemas=[ordered]@{};foreach($pair in $schemaHashes.GetEnumerator()){$schemas[$pair.Key]=$pair.Value};if($Fault-ceq'FXV2_02_SCHEMA_NATIVE_DRIFT'){$schemas.idb_save=1};return ([ordered]@{schemas=$schemas;tools=[object[]]@($schemaHashes.Keys)}|ConvertTo-Json -Compress)}
            'diagnostic-open'{$obs=&$newObservation 'uid0003yu-diagnostic' 'diagnostic-role';if($Fault-ceq'FXV2_04_PARTIAL_OPEN_CLEANUP'){throw 'V2_PARTIAL_OPEN_TRANSPORT_THROW'};return ([ordered]@{error=$null;observation=$obs;role_id='diagnostic-role'}|ConvertTo-Json -Compress)}
            'open'{$obs=&$newObservation 'uid0003yu-transaction' 'transaction-role';return ([ordered]@{error=$null;observation=$obs;role_id='transaction-role'}|ConvertTo-Json -Compress)}
            'verifier-open'{$State.VerifierOpenCalls++;$role="verifier-$([int]$payload.index)";$obs=&$newObservation $role $role;if(($Fault-ceq'FXV2_16_VERIFIER_A_FAIL_B_RUNS'-and[int]$payload.index-eq 0)-or($Fault-ceq'FXV2_17_VERIFIER_B_FAIL'-and[int]$payload.index-eq 1)){return ([ordered]@{error='V2_FIXTURE_VERIFIER_OPEN_FAILURE';observation=$obs;role_id=$role}|ConvertTo-Json -Compress)};return ([ordered]@{error=$null;observation=$obs;role_id=$role}|ConvertTo-Json -Compress)}
            'runtime'{return New-UID0003YUHostileRuntimeV2 ([string]$payload.role_id) $implementation $Fault}
            'readback'{$phase=[string]$payload.phase;$state=[string]$payload.state;if($Fault-ceq'FXV2_07_READBACK_SEMANTIC'){$state='BROKEN'};if($Fault-ceq'FXV2_22_ROLLBACK_VERIFIER'-and$phase-ceq'rollback-verifier'){$state='FINAL'};$seed=if($phase-like'post-I02-*'){'post-I02'}else{$phase};$hashes=@();foreach($i in 1..14){$hashes+=,(Get-AuthTextSHA256 "$seed-$i")};return ([ordered]@{phase=$phase;protected_sha256=(Get-AuthTextSHA256 "protected-$seed");result_ids=[object[]](1..14);state=$state;transport_response_sha256=[object[]]$hashes}|ConvertTo-Json -Compress)}
            'collision'{$sha=Get-AuthTextSHA256 (Get-AuthCanonicalJson $payload.contract);if($Fault-ceq'FXV2_10_OPERATION_CORRELATION'){$sha='0'*64};return ([ordered]@{ok=$true;operation='Collision';request_sha256=$sha}|ConvertTo-Json -Compress)}
            'dry-run'{$sha=Get-AuthTextSHA256 (Get-AuthCanonicalJson $payload.contract);return ([ordered]@{ok=$true;operation='DryRun';request_sha256=$sha}|ConvertTo-Json -Compress)}
            'mutation'{if($Fault-ceq'FXV2_09_FROZEN_PLAN_MUTATION'-and[string]$payload.operation-ceq'I01'){$payload.contract.batch.func.name='tampered'};$sha=Get-AuthTextSHA256 (Get-AuthCanonicalJson $payload.contract);return ([ordered]@{ok=$true;operation=[string]$payload.operation;request_sha256=$sha}|ConvertTo-Json -Compress)}
            'save'{$State.SaveCalls++;if($Fault-ceq'FXV2_15_EXPLICIT_TWO_VERIFIERS'-or$Fault-in@('FXV2_16_VERIFIER_A_FAIL_B_RUNS','FXV2_17_VERIFIER_B_FAIL')){return '{"jsonrpc":"2.0","id":1,"result":null,"error":{"code":-32000,"message":"explicit failure","data":"no-save"}}'};$State.Current=$State.Saved;if($Fault-ceq'FXV2_13_SAVE_TRANSPORT_THROW'){throw 'V2_RAW_SAVE_TRANSPORT_THROW'};if($Fault-ceq'FXV2_12_MALFORMED_SAVE_ERROR'){return '{"jsonrpc":"2.0","id":1,"result":null,"error":{"code":"bad","message":7,"data":null}}'};$id=if($Fault-ceq'FXV2_11_SAVE_ID_MISMATCH'){2}else{1};return ([ordered]@{jsonrpc='2.0';id=[long]$id;result=[ordered]@{error=$null;ok=$true;path='memory:canonical'};error=$null}|ConvertTo-Json -Compress)}
            default{throw "V2_FIXTURE_UNKNOWN_TRANSPORT:$op"}
        }
    }.GetNewClosure()
    $disk={param($op,$payload)
        switch($op){
            'capture-p0'{return $State.P0};'capture-p0-confirm'{return $State.P0};'create-b0'{return $State.B0};'capture-b0-confirm'{if($Fault-ceq'FXV2_08_B0_REPLACEMENT'){return New-AuthTupleV2 'memory:backup' 3 $State.B0.SHA256 100 'backup-foreign' 96};return $State.B0}
            'verify-original-baselines'{if($Fault-ceq'FXV2_24_RESTART_BASELINE_REPLACEMENT'){return $false};return $true}
            'tuple'{if($Fault-ceq'FXV2_18_THIRD_WRITER'){return $foreign};if($Fault-ceq'FXV2_19_P1_DRIFT'-and[string]$payload.name-like'*P1*'){return $foreign};return $State.Current}
            'open-restore-handles'{$b0Bytes=if($Fault-ceq'FXV2_21_B0_SOURCE_REPLACEMENT'){[byte[]](9,9,9)}else{[byte[]]$State.P0Bytes};$destinationBytes=if($State.Current.SHA256-ceq$State.P0.SHA256){[byte[]]$State.P0Bytes}else{[byte[]]$State.SavedBytes};$b0Stream=[IO.MemoryStream]::new($b0Bytes,$true);$destinationStream=[IO.MemoryStream]::new($destinationBytes,$true);$destinationTuple=if($Fault-ceq'FXV2_20_DESTINATION_SUBSTITUTION'){$foreign}else{$State.Current};return [pscustomobject]@{B0Stream=$b0Stream;B0Tuple=$State.B0;DestinationStream=$destinationStream;DestinationTuple=$destinationTuple;HandleToken='v2-held-token'}}
            'close-restore-handles'{$bytes=$payload.DestinationStream.ToArray();if(($bytes-join',')-ceq($State.P0Bytes-join',')){$State.Current=$State.P0};$payload.DestinationStream.Dispose();$payload.B0Stream.Dispose();return}
            default{throw "V2_FIXTURE_UNKNOWN_DISK:$op"}
        }
    }.GetNewClosure()
    $digest=if($Fault-ceq'FXV2_03_CONTRACT_DIGEST_LIE'){'F'*64}else{$AuthContracts.SHA256}
    return [pscustomobject]@{CanonicalPath='memory:canonical';BackupPath='memory:backup';ContractDigest=$digest;ImplementationContractSHA256=$implementation;Transport=$transport;Process=$process;Disk=$disk;Journal=$journal;State=$State;Fault=$Fault;LastCounters=$null}
}
function Assert-UID0003YUHostileFailureV2([string]$Label,[string]$ExpectedCode,$Context,[string]$ExpectedVector) {
    $message='';try{$null=Invoke-UID0003YUClosedCoordinator $Context}catch{$message=$_.Exception.GetBaseException().Message}
    $actual=Get-AuthExactErrorCodeV2 $message
    if($actual-cne$ExpectedCode){throw "$Label|WRONG_EXACT_CODE|actual=$actual|expected=$ExpectedCode|message=$message"}
    $vector=Get-AuthVector $Context.LastCounters;if(-not[string]::IsNullOrWhiteSpace($ExpectedVector)-and$vector-cne$ExpectedVector){throw "$Label|VECTOR_DRIFT|actual=$vector|expected=$ExpectedVector"}
    return [pscustomobject]@{Label=$Label;Code=$actual;Vector=$vector;Result='REJECTED'}
}
function Invoke-UID0003YUAuthenticatedHostileSuiteV2 {
    $results=[Collections.Generic.List[object]]::new();$vectors=[ordered]@{}
    $failures=@(
        @('FXV2_01_RECURSIVE_DUPLICATE_JSON','DUPLICATE_JSON_KEY'),@('FXV2_02_SCHEMA_NATIVE_DRIFT','CATALOG_SCHEMA_DRIFT:idb_save'),@('FXV2_03_CONTRACT_DIGEST_LIE','V2_FROZEN_CONTRACT_DIGEST_LIE'),@('FXV2_04_PARTIAL_OPEN_CLEANUP','V2_PRE_SAVE_CLOSURE_FAILED'),
        @('FXV2_05_RUNTIME_PROCESS','RUNTIME_V2_PROCESS_NATIVE_OR_ROUTE_DRIFT:role'),@('FXV2_06_RUNTIME_MANIFEST','RUNTIME_V2_ROLE'),@('FXV2_07_READBACK_SEMANTIC','READBACK_SEMANTIC_DRIFT:diagnostic-pre'),@('FXV2_08_B0_REPLACEMENT','V2_B0_CONFIRM'),
        @('FXV2_09_FROZEN_PLAN_MUTATION','V2_FROZEN_PLAN_MUTATED_BY_TRANSPORT:I01'),@('FXV2_10_OPERATION_CORRELATION','OPERATION_RESPONSE_CORRELATION_DRIFT:Collision'),@('FXV2_16_VERIFIER_A_FAIL_B_RUNS','V2_POST_DISPATCH_RECOVERY_BLOCKED'),@('FXV2_17_VERIFIER_B_FAIL','V2_POST_DISPATCH_RECOVERY_BLOCKED'),
        @('FXV2_18_THIRD_WRITER','V2_POST_DISPATCH_RECOVERY_BLOCKED'),@('FXV2_19_P1_DRIFT','V2_POST_DISPATCH_RECOVERY_BLOCKED'),@('FXV2_20_DESTINATION_SUBSTITUTION','V2_POST_DISPATCH_RECOVERY_BLOCKED'),@('FXV2_21_B0_SOURCE_REPLACEMENT','V2_POST_DISPATCH_RECOVERY_BLOCKED'),@('FXV2_22_ROLLBACK_VERIFIER','V2_POST_DISPATCH_RECOVERY_BLOCKED')
    )
    foreach($case in $failures){$ctx=New-UID0003YUHostileContextV2 $case[0] $null;$results.Add((Assert-UID0003YUHostileFailureV2 $case[0] $case[1] $ctx $vectors[$case[0]]));if($case[0]-ceq'FXV2_16_VERIFIER_A_FAIL_B_RUNS'-and$ctx.State.VerifierOpenCalls-ne 2){throw 'FXV2_16_SECOND_VERIFIER_SUPPRESSED'}}
    foreach($label in @('FXV2_11_SAVE_ID_MISMATCH','FXV2_12_MALFORMED_SAVE_ERROR','FXV2_13_SAVE_TRANSPORT_THROW','FXV2_14_SUCCESS_ONE_VERIFIER','FXV2_15_EXPLICIT_TWO_VERIFIERS')){
        $fault=if($label-ceq'FXV2_14_SUCCESS_ONE_VERIFIER'){''}else{$label};$ctx=New-UID0003YUHostileContextV2 $fault $null;$value=Invoke-UID0003YUClosedCoordinator $ctx;$vector=Get-AuthVector $ctx.LastCounters
        if($label-ceq'FXV2_14_SUCCESS_ONE_VERIFIER'){if($value.Marker-cne'UID0003YU_V2_COORDINATOR_CLOSED'-or$value.Classification-cne'SUCCESS'-or$value.VerifierCount-ne 1-or$ctx.State.SaveCalls-ne 1){throw "$label|SUCCESS_POLICY_DRIFT"}}
        elseif($label-ceq'FXV2_15_EXPLICIT_TWO_VERIFIERS'){if($value.Marker-cne'UID0003YU_V2_COORDINATOR_CLOSED'-or$value.Classification-cne'EXPLICIT_FAILURE'-or$value.VerifierCount-ne 2-or$ctx.State.SaveCalls-ne 1){throw "$label|EXPLICIT_POLICY_DRIFT"}}
        else{if($value.State-cne'CLOSED'-or$ctx.State.SaveCalls-ne 1-or$ctx.State.Current.SHA256-cne$ctx.State.P0.SHA256){throw "$label|RECOVERY_POLICY_DRIFT"}}
        if(-not[string]::IsNullOrWhiteSpace($vectors[$label])-and$vector-cne$vectors[$label]){throw "$label|VECTOR_DRIFT|actual=$vector|expected=$($vectors[$label])"}
        $results.Add([pscustomobject]@{Label=$label;Code=if($label-like'FXV2_1[1-3]*'){'RECOVERED'}else{'CLOSED'};Vector=$vector;Result='CLOSED'})
    }
    $seed=New-UID0003YUHostileContextV2 '' $null;$null=Invoke-UID0003YUClosedCoordinator $seed;$state=$seed.State
    foreach($case in @(@('FXV2_23_DURABLE_ONE_SAVE','V2_DURABLE_ONE_SAVE_ALREADY_CLAIMED'),@('FXV2_24_RESTART_BASELINE_REPLACEMENT','V2_RESTART_ORIGINAL_BASELINE_REPLACED'))){$ctx=New-UID0003YUHostileContextV2 $case[0] $state;$results.Add((Assert-UID0003YUHostileFailureV2 $case[0] $case[1] $ctx $vectors[$case[0]]))}
    $expectedLabels=@($failures|ForEach-Object{$_[0]})+@('FXV2_11_SAVE_ID_MISMATCH','FXV2_12_MALFORMED_SAVE_ERROR','FXV2_13_SAVE_TRANSPORT_THROW','FXV2_14_SUCCESS_ONE_VERIFIER','FXV2_15_EXPLICIT_TWO_VERIFIERS','FXV2_23_DURABLE_ONE_SAVE','FXV2_24_RESTART_BASELINE_REPLACEMENT')
    $labels=@($results|ForEach-Object{$_.Label});if(($labels-join'|')-cne($expectedLabels-join'|')-or@($labels|Sort-Object -Unique).Count-ne$labels.Count){throw 'V2_HOSTILE_LABEL_ORDER_OR_UNIQUENESS_DRIFT'}
    return [pscustomobject]@{Marker='UID0003YU_V2_AUTHENTICATED_HOSTILE_SUITE_PASSED';Count=$results.Count;Labels=$labels;Results=@($results)}
}
~~~

## Removed Block R015

- SHA256: `CE3E6995DCCC41E6264A4349ACCB6A7BD0355006B1ED3F203F048C6C6D4FCC7F`
- Language: `powershell`
- Bytes: `34283`
- First recovered timestamp: `2026-08-08T04:01:35.309Z`
- Session provenance: rollout-2026-08-07T21-28-25-019fdefc-4eb3-7c02-8dc4-19f7da3eee30.jsonl line 196498 (2026-08-08T04:01:35.309Z); rollout-2026-08-07T21-28-25-019fdefc-4eb3-7c02-8dc4-19f7da3eee30.jsonl line 196499 (2026-08-08T04:01:35.487Z)

~~~powershell
function Get-UID0003YUPhysicalModuleRowV2([string]$Path,[string]$Name,[string]$ModuleId) {
    if([string]::IsNullOrWhiteSpace($Path)-or[string]::IsNullOrWhiteSpace($Name)-or$ModuleId-cnotmatch'^0x[0-9a-f]+$'){throw 'V2_LIVE_MODULE_INPUT_INVALID'}
    $resolved=[IO.Path]::GetFullPath($Path)
    $stream=[IO.File]::Open($resolved,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::Read)
    try {
        $identity=[UID0003YU.NativeFileTime]::GetFileIdentity($stream.SafeFileHandle)
        $mtime=[UID0003YU.NativeFileTime]::GetLastWriteUtcTicks($stream.SafeFileHandle)
        $ctime=[UID0003YU.NativeFileTime]::GetCreationUtcTicks($stream.SafeFileHandle)
        $stream.Position=0;$sha=[Security.Cryptography.SHA256]::Create()
        try{$hash=([BitConverter]::ToString($sha.ComputeHash($stream))).Replace('-','')}finally{$sha.Dispose()}
        return [pscustomobject][ordered]@{
            ctime_ns=[long](($ctime-621355968000000000)*100);file=$resolved;file_identity=[string]$identity
            module_id=$ModuleId;mtime_ns=[long](($mtime-621355968000000000)*100);name=$Name
            resolved_path=$resolved;sha256=$hash;size=[long]$stream.Length;spec_origin=$resolved
        }
    } finally { $stream.Dispose() }
}
function ConvertTo-UID0003YULiveModuleRowsV2($Rows,[string]$Label) {
    $result=@();$index=0
    foreach($row in @($Rows)){
        $index++
        $name=[string]$row.Name;$path=[string]$row.ResolvedPath
        $moduleId=if($row.PSObject.Properties.Name-contains'ModuleId'-and[string]$row.ModuleId-cmatch'^0x[0-9A-Fa-f]+$'){([string]$row.ModuleId).ToLowerInvariant()}else{'0x{0:x}'-f$index}
        $physical=Get-UID0003YUPhysicalModuleRowV2 $path $name $moduleId
        if(($row.PSObject.Properties.Name-contains'SHA256'-and[string]$row.SHA256-cne$physical.sha256)-or
           ($row.PSObject.Properties.Name-contains'Size'-and[long]$row.Size-ne$physical.size)-or
           ($row.PSObject.Properties.Name-contains'MTimeNS'-and[long]$row.MTimeNS-ne$physical.mtime_ns)-or
           ($row.PSObject.Properties.Name-contains'CTimeNS'-and[long]$row.CTimeNS-ne$physical.ctime_ns)){
            throw "$Label|PUBLIC_MODULE_TO_PHYSICAL_DRIFT:$name"
        }
        $result+=,$physical
    }
    if($result.Count-eq 0){throw "$Label|PUBLIC_MODULES_EMPTY"}
    return [object[]]$result
}
function ConvertTo-UID0003YUFinalLiveRuntimeV2($Role,$Runtime,$ModuleProbe,[string]$Label) {
    if($null-eq$Role-or$null-eq$Runtime-or$ModuleProbe-isnot[scriptblock]){throw "$Label|LIVE_RUNTIME_INPUT_MISSING"}
    Assert-ExactStableRuntime $Runtime $Role.Runtime0 "$Label-stable-runtime"
    $listenerModules=ConvertTo-UID0003YULiveModuleRowsV2 $Runtime.Stable.Listener.Modules "$Label-listener"
    $roleModules=ConvertTo-UID0003YULiveModuleRowsV2 $Runtime.Stable.Worker.Modules "$Label-role"
    $redirectorGeneration=Get-ExactProcessGeneration ([int]$Runtime.Stable.Redirector.Pid) "$Label-redirector"
    $redirectorModules=[object[]]@(Get-UID0003YUPhysicalModuleRowV2 $redirectorGeneration.ExecutablePath 'redirector-executable' '0x1')
    $listenerManifest=Get-AuthRuntimeModuleManifestV2 $listenerModules "$Label-LISTENER" $ModuleProbe
    $redirectorManifest=Get-AuthRuntimeModuleManifestV2 $redirectorModules "$Label-REDIRECTOR" $ModuleProbe
    $roleManifest=Get-AuthRuntimeModuleManifestV2 $roleModules "$Label-ROLE" $ModuleProbe
    $aggregate=Get-AuthTextSHA256 (Get-AuthCanonicalJson ([ordered]@{listener=$listenerManifest.Rows;redirector=$redirectorManifest.Rows;role=$roleManifest.Rows}))
    $implementation=Get-AuthTextSHA256 (Get-AuthCanonicalJson ([ordered]@{listener=$listenerManifest.ImplementationRows;redirector=$redirectorManifest.ImplementationRows;role=$roleManifest.ImplementationRows}))
    $listenerProcess=$Runtime.Stable.Listener.Process;$workerProcess=$Runtime.Stable.Worker.ProcessPublic
    $listenerExecutable=if($listenerProcess.PSObject.Properties.Name-contains'process_image'){[string]$listenerProcess.process_image}else{[string]$listenerProcess.sys_executable}
    $workerExecutable=if($workerProcess.PSObject.Properties.Name-contains'process_image'){[string]$workerProcess.process_image}else{[string]$workerProcess.sys_executable}
    $listener=[ordered]@{argv=[object[]]$listenerProcess.argv;creation_time_100ns=[string]$listenerProcess.creation_time_100ns;executable=$listenerExecutable;modules=[object[]]$listenerModules;parent_pid=[int]$listenerProcess.parent_pid;pid=[int]$listenerProcess.pid;port=[int]$Runtime.Stable.Listener.Endpoint.Port;socket_owner=[int]$listenerProcess.pid}
    $redirector=[ordered]@{argv=[object[]]$redirectorGeneration.Argv;creation_time_100ns=[string]$redirectorGeneration.CreationTime100ns;executable=[string]$redirectorGeneration.ExecutablePath;modules=$redirectorModules;parent_pid=[int]$redirectorGeneration.ParentPid;pid=[int]$redirectorGeneration.Pid;port=0;socket_owner=[int]$redirectorGeneration.Pid}
    $worker=[ordered]@{argv=[object[]]$workerProcess.argv;creation_time_100ns=[string]$workerProcess.creation_time_100ns;executable=$workerExecutable;modules=[object[]]$roleModules;parent_pid=[int]$workerProcess.parent_pid;pid=[int]$workerProcess.pid;port=[int]$Runtime.Stable.Worker.Route.Port;socket_owner=[int]$workerProcess.pid}
    return ([ordered]@{aggregate_manifest_sha256=$aggregate;canonical_path=[string]$Role.CanonicalPath;errors=[object[]]@();implementation_contract_sha256=$implementation;listener=$listener;ok=$true;redirector=$redirector;role=$worker;schema_version=1;session=[string]$Role.ReturnedSessionId}|ConvertTo-Json -Depth 40 -Compress)
}
function Get-UID0003YUFinalLiveImplementationBootstrapV2($ModuleProbe) {
    $role=$null
    try {
        $role=Open-IdbRole 'final-v2-bootstrap' $false $false
        $runtime=Invoke-ValidatedPublicRuntime $role 'final-v2-bootstrap-runtime'
        $raw=ConvertTo-UID0003YUFinalLiveRuntimeV2 $role $runtime $ModuleProbe 'final-v2-bootstrap'
        $value=ConvertFrom-AuthStrictJson $raw 'final-v2-bootstrap-envelope'
        $null=Assert-AuthRuntimeV2 $raw $role.ReturnedSessionId $role.CanonicalPath $value.implementation_contract_sha256 $ModuleProbe
        return [string]$value.implementation_contract_sha256
    } finally { if($null-ne$role){$null=Complete-IdbRoleRetirement $role 'final-v2-bootstrap-retire'} }
}
function New-UID0003YUFinalLiveContext([switch]$CompatibilityOnly) {
    $canonical=[IO.Path]::GetFullPath($CanonicalIdbPath)
    $root=Join-Path (Split-Path -Parent $canonical) '.uid0003yu-gate2b-final-v2'
    $backup=Join-Path $root 'UID0003YU.B0';$rootPath=Join-Path $root 'authority.root.dpapi'
    $roles=@{};$observations=[Collections.Generic.List[object]]::new();$restoreHandles=@{}
    $rootState=[pscustomobject]@{Stream=$null;Identity='';Path=$rootPath};$moduleProbe=New-AuthStableFileModuleProbeV2
    $implementation=if($CompatibilityOnly){Get-AuthTextSHA256 'UID0003YU-FINAL-LIVE-COMPATIBILITY-V2'}else{Get-UID0003YUFinalLiveImplementationBootstrapV2 $moduleProbe}
    if($implementation-cnotmatch'^[0-9A-F]{64}$'){throw 'V2_FINAL_LIVE_BOOTSTRAP_IMPLEMENTATION_INVALID'}
    $saveBytes=[byte[]]::new(8);$rng=[Security.Cryptography.RandomNumberGenerator]::Create();try{$rng.GetBytes($saveBytes)}finally{$rng.Dispose()}
    $saveRequestId=[long]([BitConverter]::ToInt64($saveBytes,0)-band[long]::MaxValue);if($saveRequestId-eq 0){$saveRequestId=7003}
    $bindingId=Get-AuthTextSHA256 (Get-AuthCanonicalJson ([ordered]@{backup=$backup;canonical=$canonical;contract=$AuthContracts.SHA256;implementation=$implementation;version=2}))
    $journal={param($op,$value)
        if($op-ceq'compatibility'){return [pscustomobject][ordered]@{adapter='Journal';binding_id=$bindingId;operations=[object[]]@('open','close')}}
        if($op-ceq'open'){
            [IO.Directory]::CreateDirectory($root)|Out-Null
            $keyPath=Join-Path $root 'authority.key.dpapi';$anchorPath=Join-Path $root 'authority.anchor';$journalPath=Join-Path $root 'transaction.journal'
            $exists=@([IO.File]::Exists($keyPath),[IO.File]::Exists($anchorPath),[IO.File]::Exists($journalPath));$present=@($exists|Where-Object{$_}).Count
            if($present-ne 0-and$present-ne 3){throw 'V2_LIVE_AUTHORITY_PARTIAL_FILE_SET'}
            $bootstrap=$present-eq 0;$mode=if($bootstrap){[IO.FileMode]::CreateNew}else{[IO.FileMode]::Open}
            $keyStream=[IO.File]::Open($keyPath,$mode,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None)
            try{
                if($bootstrap){$authorityKey=[byte[]]::new(32);$krng=[Security.Cryptography.RandomNumberGenerator]::Create();try{$krng.GetBytes($authorityKey)}finally{$krng.Dispose()};Write-AuthStreamText $keyStream (Protect-AuthKey $authorityKey);Sync-AuthStream $keyStream}else{if($keyStream.Length-eq 0){throw 'V2_LIVE_AUTHORITY_KEY_TRUNCATED'};$authorityKey=Unprotect-AuthKey (Read-AuthStreamText $keyStream)}
                $anchorStream=[IO.File]::Open($anchorPath,$mode,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None)
                try{$journalStream=[IO.File]::Open($journalPath,$mode,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None)}catch{$anchorStream.Dispose();throw}
                if(-not$bootstrap-and$anchorStream.Length-eq 0){$journalStream.Dispose();$anchorStream.Dispose();throw 'V2_LIVE_AUTHORITY_ANCHOR_TRUNCATED'}
                return [pscustomobject]@{AuthorityKey=[byte[]]$authorityKey;AuthorityKeyId=(Get-AuthSHA256 $authorityKey);AuthorityKeyIdentity='';AuthorityKeyPath=$keyPath;AuthorityKeyStream=$keyStream;AnchorIdentity='';AnchorPath=$anchorPath;AnchorStream=$anchorStream;JournalIdentity='';JournalPath=$journalPath;JournalStream=$journalStream}
            }catch{$keyStream.Dispose();throw}
        }
        if($op-ceq'close'){
            try{$value.JournalStream.Dispose()}finally{try{$value.AnchorStream.Dispose()}finally{try{$value.AuthorityKeyStream.Dispose()}finally{if($null-ne$rootState.Stream){$rootState.Stream.Dispose();$rootState.Stream=$null}}}}
            return
        }
        throw "V2_FINAL_LIVE_UNKNOWN_JOURNAL:$op"
    }.GetNewClosure()
    $rootBinding={param($op,$proposal)
        if($op-ceq'compatibility'){return [pscustomobject][ordered]@{adapter='RootBinding';binding_id=$bindingId;operations=[object[]]@('read-or-bootstrap','read')}}
        if($op-notin@('read-or-bootstrap','read')){throw "V2_FINAL_LIVE_UNKNOWN_ROOT:$op"}
        if($null-eq$rootState.Stream){
            if($op-ceq'read'){throw 'V2_FINAL_LIVE_ROOT_NOT_OPEN'}
            [IO.Directory]::CreateDirectory($root)|Out-Null;$exists=[IO.File]::Exists($rootPath);$mode=if($exists){[IO.FileMode]::Open}else{[IO.FileMode]::CreateNew}
            $rootState.Stream=[IO.File]::Open($rootPath,$mode,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None)
            $rootState.Identity=[UID0003YU.NativeFileTime]::GetFileIdentity($rootState.Stream.SafeFileHandle)
            if(-not$exists){$plain=[Text.UTF8Encoding]::new($false).GetBytes((Get-AuthCanonicalJson $proposal));Write-AuthStreamText $rootState.Stream (Protect-AuthKey $plain);[Array]::Clear($plain,0,$plain.Length)}
        }
        if([UID0003YU.NativeFileTime]::GetFileIdentity($rootState.Stream.SafeFileHandle)-cne$rootState.Identity){throw 'V2_FINAL_LIVE_ROOT_IDENTITY_DRIFT'}
        $plain=Unprotect-AuthKey (Read-AuthStreamText $rootState.Stream)
        try{$current=ConvertFrom-AuthStrictJson ([Text.UTF8Encoding]::new($false).GetString($plain)) 'v2-final-live-root'}finally{[Array]::Clear($plain,0,$plain.Length)}
        if($op-ceq'read-or-bootstrap'-and(Get-AuthCanonicalJson $current)-cne(Get-AuthCanonicalJson $proposal)){throw 'V2_NONREPLACEABLE_ROOT_BINDING_DRIFT'}
        return $current
    }.GetNewClosure()
    $toTuple={param($legacy,[string]$path)New-AuthTupleV2 $path ([long]$legacy.Length) ([string]$legacy.SHA256) ([long]$legacy.LastWriteTimeUtcTicks) ([string]$legacy.FileIdentity) ([long]$legacy.CreationTimeUtcTicks)}.GetNewClosure()
    $heldTuple={param($stream,[string]$path)$legacy=Get-HeldStreamTuple $stream $path {param($held)[UID0003YU.NativeFileTime]::GetLastWriteUtcTicks($held.SafeFileHandle)};return &$toTuple $legacy $path}.GetNewClosure()
    $newObservation={param($role)
        $row=[pscustomobject][ordered]@{canonical_path=[string]$role.CanonicalPath;preferred_id=[string]$role.Preferred;process_generation="pid:$($role.WorkerGeneration0.Pid);created:$($role.WorkerGeneration0.CreationTime100ns)";returned_session=[string]$role.ReturnedSessionId;socket="${endpointAddress}:$($role.Runtime0.Stable.Worker.Route.Port)"}
        $observations.Add($row);return $row
    }.GetNewClosure()
    $process={param($op,$payload)
        if($op-ceq'compatibility'){return [pscustomobject][ordered]@{adapter='Process';binding_id=$bindingId;operations=[object[]]@('snapshot','diff','validate-runtime','retire')}}
        if($op-ceq'snapshot'){return [pscustomobject]@{Count=[int]$observations.Count}}
        if($op-ceq'diff'){$rows=@();for($i=[int]$payload.pre.Count;$i-lt$observations.Count;$i++){$rows+=,$observations[$i]};return (ConvertTo-Json -InputObject ([object[]]$rows) -Depth 10 -Compress)}
        if($op-ceq'validate-runtime'){
            $role=$roles[[string]$payload.session];if($null-eq$role){throw 'V2_FINAL_LIVE_RUNTIME_ROLE_NOT_REGISTERED'}
            $listener=Get-ExactProcessGeneration ([int]$payload.listener_pid) 'v2-live-os-listener';$redirector=Get-ExactProcessGeneration ([int]$payload.redirector_pid) 'v2-live-os-redirector';$worker=Get-ExactProcessGeneration ([int]$payload.role_pid) 'v2-live-os-role'
            if("$($listener.Pid):$($listener.CreationTime100ns)"-cne[string]$payload.listener_generation-or"$($redirector.Pid):$($redirector.CreationTime100ns)"-cne[string]$payload.redirector_generation-or"$($worker.Pid):$($worker.CreationTime100ns)"-cne[string]$payload.role_generation-or$worker.ParentPid-ne$redirector.Pid-or$worker.ParentPid-ne[int]$payload.role_parent_pid){throw 'V2_FINAL_LIVE_OS_GENERATION_OR_PARENT_DRIFT'}
            $listenerSockets=@(Get-NetTCPConnection -State Listen -ErrorAction Stop|Where-Object{$_.OwningProcess-eq$listener.Pid-and$_.LocalPort-eq$endpointPort});$workerSockets=@(Get-NetTCPConnection -State Listen -ErrorAction Stop|Where-Object{$_.OwningProcess-eq$worker.Pid-and$_.LocalPort-eq$role.Runtime0.Stable.Worker.Route.Port})
            if($listenerSockets.Count-ne 1-or$workerSockets.Count-ne 1-or$payload.listener_socket_owner-ne$listener.Pid-or$payload.role_socket_owner-ne$worker.Pid){throw 'V2_FINAL_LIVE_OS_SOCKET_DRIFT'}
            $proof=[ordered]@{};foreach($name in @('canonical_path','implementation_contract_sha256','listener_generation','listener_pid','listener_socket_owner','redirector_generation','redirector_pid','role_generation','role_parent_pid','role_pid','role_socket_owner','session')){$proof[$name]=$payload.$name}
            $proof.sha256=Get-AuthTextSHA256 (Get-AuthCanonicalJson $proof);return (Get-AuthCanonicalJson $proof)
        }
        if($op-ceq'retire'){
            $role=$roles[[string]$payload.ReturnedSession];if($null-eq$role){throw 'V2_FINAL_LIVE_RETIREMENT_ROLE_NOT_REGISTERED'}
            $receipt=Complete-IdbRoleRetirement $role "v2-final-live-$($payload.Label)";$roles.Remove([string]$payload.ReturnedSession)
            $receiptHash=Get-AuthTextSHA256 (Get-AuthCanonicalJson ([ordered]@{generation=[string]$payload.ProcessGeneration;receipt=$receipt;session=[string]$payload.ReturnedSession;socket=[string]$payload.Socket}))
            return ([ordered]@{active_sessions=0;canonical_exclusive=$true;owned_processes=0;owned_sockets=0;receipt_sha256=$receiptHash;unproven_processes=[object[]]@()}|ConvertTo-Json -Depth 20 -Compress)
        }
        throw "V2_FINAL_LIVE_UNKNOWN_PROCESS:$op"
    }.GetNewClosure()
    $transport={param($op,$payload)
        if($op-ceq'compatibility'){return [pscustomobject][ordered]@{adapter='Transport';binding_id=$bindingId;operations=[object[]]@('catalog','diagnostic-open','open','verifier-open','runtime','readback','collision','dry-run','mutation','save')}}
        switch($op){
            'catalog'{$catalog=Assert-PublicToolCatalog (Invoke-McpRaw 'tools/list' @{}) 'v2-final-live-catalog';Assert-SamePublicToolCatalog $catalog $PublicToolCatalog0 'v2-final-live-catalog';$schemas=[ordered]@{};foreach($pair in $AuthSchemaHashes.GetEnumerator()){$schemas[$pair.Key]=$pair.Value};return ([ordered]@{method='tools/list';schemas=$schemas;tools=[object[]]@($AuthSchemaHashes.Keys)}|ConvertTo-Json -Depth 20 -Compress)}
            'diagnostic-open'{$role=Open-IdbRole 'diagnostic' $true $true;$roles[$role.ReturnedSessionId]=$role;$obs=&$newObservation $role;return ([ordered]@{error=$null;observation=$obs;role_id=[string]$role.ReturnedSessionId}|ConvertTo-Json -Depth 20 -Compress)}
            'open'{$role=Open-IdbRole 'transaction' $false $false;$roles[$role.ReturnedSessionId]=$role;$obs=&$newObservation $role;return ([ordered]@{error=$null;observation=$obs;role_id=[string]$role.ReturnedSessionId}|ConvertTo-Json -Depth 20 -Compress)}
            'verifier-open'{$role=Open-IdbRole "verify-$([int]$payload.index)" $false $false;$roles[$role.ReturnedSessionId]=$role;$obs=&$newObservation $role;return ([ordered]@{error=$null;observation=$obs;role_id=[string]$role.ReturnedSessionId}|ConvertTo-Json -Depth 20 -Compress)}
            'runtime'{$role=$roles[[string]$payload.role_id];if($null-eq$role){throw 'V2_FINAL_LIVE_RETURNED_SESSION_NOT_REGISTERED'};$runtime=Invoke-ValidatedPublicRuntime $role 'v2-final-live-runtime';$raw=ConvertTo-UID0003YUFinalLiveRuntimeV2 $role $runtime $moduleProbe 'v2-final-live-runtime';$value=ConvertFrom-AuthStrictJson $raw 'v2-final-live-runtime-value';if([string]$value.implementation_contract_sha256-cne$implementation){throw 'V2_FINAL_LIVE_IMPLEMENTATION_CONTRACT_DRIFT'};return $raw}
            'readback'{$role=$roles[[string]$payload.role_id];if($null-eq$role){throw 'V2_FINAL_LIVE_READBACK_ROLE_NOT_REGISTERED'};$bundle=Invoke-RBYU $role ([string]$payload.phase);$mapped=switch -Regex ([string]$payload.phase){'^pre-I01$'{'PRE'}'^post-I01$'{'POST_I01'}'^post-I02-'{'POST_I02'}'^post-I03$'{'POST_I03'}default{if([string]$payload.state-ceq'PRE'){'PRE'}else{'FINAL'}}};$proof=Assert-RBYU14 $bundle $mapped $FrozenProtection "v2-final-live-$($payload.phase)";$rawHashes=@($bundle.Keys|Sort-Object|ForEach-Object{Get-TextSHA256 ([string]$bundle[$_].Raw)});return ([ordered]@{phase=[string]$payload.phase;protected_sha256=(Get-CanonicalJsonSHA256 $proof);result_ids=[object[]](1..14);state=[string]$payload.state;transport_response_sha256=[object[]]$rawHashes}|ConvertTo-Json -Depth 20 -Compress)}
            {$_-in@('collision','dry-run','mutation')}{$role=$roles[[string]$payload.role_id];if($null-eq$role){throw 'V2_FINAL_LIVE_OPERATION_ROLE_NOT_REGISTERED'};$name=[string]$payload.operation;$arguments=ConvertTo-AuthRequestNode $payload.contract;switch($name){'Collision'{$raw=Invoke-RoleTool $role 'lookup_funcs' $arguments 'v2-final-live-collision';$null=Assert-CollisionLookupResponse $raw};'DryRun'{$raw=Invoke-RoleTool $role 'rename' $arguments 'v2-final-live-dry-run';$null=Assert-RenameActionResponse $raw $true 'v2-final-live-dry-run'};'I01'{$raw=Invoke-RoleTool $role 'rename' $arguments 'v2-final-live-I01';$null=Assert-RenameActionResponse $raw $false 'v2-final-live-I01'};'I02'{$raw=Invoke-RoleTool $role 'set_type' $arguments 'v2-final-live-I02';$null=Assert-TypeActionResponse $raw 'v2-final-live-I02'};'I03'{$raw=Invoke-RoleTool $role 'set_function_comments' $arguments 'v2-final-live-I03';$null=Assert-FunctionCommentActionResponse $raw 'v2-final-live-I03'};default{throw 'V2_FINAL_LIVE_UNKNOWN_OPERATION'}};$sha=Get-AuthTextSHA256 (Get-AuthCanonicalJson $payload.contract);return ([ordered]@{ok=$true;operation=$name;request_sha256=$sha}|ConvertTo-Json -Compress)}
            'save'{$role=$roles[[string]$payload.database];if($null-eq$role-or$role.ReturnedSessionId-cne[string]$payload.database){throw 'V2_FINAL_LIVE_SAVE_ROLE_DRIFT'};Assert-RoleBoundary $role 'v2-final-live-save';$arguments=[ordered]@{path=[string]$payload.path;database=[string]$role.ReturnedSessionId};$raw=Invoke-McpToolRaw 'idb_save' $arguments;$classified=Get-McpToolStructuredContent $raw 'idb_save' $arguments 'v2-final-live-save' -AllowToolError;if($classified.Classification-ceq'SUCCESS'){$sc=$classified.StructuredContent;$null=Assert-SaveSuccessResponse $sc;return ([ordered]@{jsonrpc='2.0';id=[long]$payload.request_id;result=[ordered]@{error=$null;ok=$true;path=[string]$sc.path};error=$null}|ConvertTo-Json -Compress)};$message=if($null-ne$raw.Envelope.error){[string]$raw.Envelope.error.message}else{'idb_save returned isError:true'};$code=if($null-ne$raw.Envelope.error-and$raw.Envelope.error.code-is[int]){[int]$raw.Envelope.error.code}else{-32000};return ([ordered]@{jsonrpc='2.0';id=[long]$payload.request_id;result=$null;error=[ordered]@{code=$code;message=$message;data=(Get-TextSHA256 $raw.Raw)}}|ConvertTo-Json -Compress)}
            default{throw "V2_FINAL_LIVE_UNKNOWN_TRANSPORT:$op"}
        }
    }.GetNewClosure()
    $disk={param($op,$payload)
        if($op-ceq'compatibility'){return [pscustomobject][ordered]@{adapter='Disk';binding_id=$bindingId;operations=[object[]]@('capture-p0','capture-p0-confirm','create-b0','capture-b0-confirm','verify-original-baselines','tuple','open-restore-handles','close-restore-handles')}}
        switch($op){
            'capture-p0'{$legacy=Get-ClosedExclusiveIdbTuple $canonical;return &$toTuple $legacy $canonical}
            'capture-p0-confirm'{$legacy=Get-ClosedExclusiveIdbTuple $canonical;return &$toTuple $legacy $canonical}
            'create-b0'{[IO.Directory]::CreateDirectory($root)|Out-Null;$src=[IO.File]::Open($canonical,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);try{$dst=[IO.File]::Open($backup,[IO.FileMode]::CreateNew,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None);try{$src.CopyTo($dst);$dst.Flush($true);[UID0003YU.NativeFileTime]::SetLastWriteUtcTicks($dst.SafeFileHandle,[long]$payload.LastWriteTimeUtcTicks);$dst.Flush($true);return &$heldTuple $dst $backup}finally{$dst.Dispose()}}finally{$src.Dispose()}}
            'capture-b0-confirm'{$legacy=Get-ClosedExclusiveIdbTuple $backup;return &$toTuple $legacy $backup}
            'verify-original-baselines'{$legacy=Get-ClosedExclusiveIdbTuple $backup;$current=&$toTuple $legacy $backup;try{Assert-AuthTupleV2 $current $payload.B0 'V2_FINAL_LIVE_RESTART_B0';return $true}catch{return $false}}
            'tuple'{$legacy=Get-ClosedExclusiveIdbTuple $canonical;return &$toTuple $legacy $canonical}
            'open-restore-handles'{$src=[IO.File]::Open($backup,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);try{$dst=[IO.File]::Open($canonical,[IO.FileMode]::Open,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None)}catch{$src.Dispose();throw};$token=[guid]::NewGuid().ToString('N');$handle=[pscustomobject]@{AuthorityGeneration=[long]$payload.AuthorityGeneration;AuthorityHmac=[string]$payload.AuthorityHmac;SaveRequestSHA256=[string]$payload.SaveRequestSHA256;SaveResponseSHA256=[string]$payload.SaveResponseSHA256;B0Stream=$src;B0Tuple=(&$heldTuple $src $backup);DestinationStream=$dst;DestinationTuple=(&$heldTuple $dst $canonical);HandleToken=$token};$restoreHandles[$token]=$handle;return $handle}
            'close-restore-handles'{$handle=$payload;if($restoreHandles[[string]$handle.HandleToken]-ne$handle){throw 'V2_FINAL_LIVE_RESTORE_HANDLE_TOKEN_DRIFT'};try{$handle.DestinationStream.Dispose()}finally{$handle.B0Stream.Dispose();$restoreHandles.Remove([string]$handle.HandleToken)};return}
            default{throw "V2_FINAL_LIVE_UNKNOWN_DISK:$op"}
        }
    }.GetNewClosure()
    return [pscustomobject][ordered]@{BackupPath=$backup;CanonicalPath=$canonical;ContractDigest=$AuthContracts.SHA256;Disk=$disk;ImplementationContractSHA256=$implementation;Journal=$journal;LastCounters=$null;ModuleProbe=$moduleProbe;Process=$process;RootBinding=$rootBinding;SaveRequestId=$saveRequestId;Transport=$transport}
}
function Assert-UID0003YUFinalLiveContextCompatibilityV2($Context) {
    $expected=@('BackupPath','CanonicalPath','ContractDigest','Disk','ImplementationContractSHA256','Journal','LastCounters','ModuleProbe','Process','RootBinding','SaveRequestId','Transport')
    $actual=@($Context.PSObject.Properties.Name|Sort-Object);if(($actual-join'|')-cne(@($expected|Sort-Object)-join'|')){throw 'V2_FINAL_LIVE_CONTEXT_KEY_DRIFT'}
    if($Context.BackupPath-isnot[string]-or[string]::IsNullOrWhiteSpace($Context.BackupPath)-or$Context.CanonicalPath-isnot[string]-or[string]::IsNullOrWhiteSpace($Context.CanonicalPath)-or$Context.BackupPath-ceq$Context.CanonicalPath){throw 'V2_FINAL_LIVE_PATH_DRIFT'}
    if($Context.ContractDigest-cne$AuthContracts.SHA256){throw 'V2_FINAL_LIVE_CONTRACT_DRIFT'}
    if($Context.ImplementationContractSHA256-isnot[string]-or$Context.ImplementationContractSHA256-cnotmatch'^[0-9A-F]{64}$'){throw 'V2_FINAL_LIVE_IMPLEMENTATION_DRIFT'}
    if(($Context.SaveRequestId-isnot[int]-and$Context.SaveRequestId-isnot[long])-or[long]$Context.SaveRequestId-le 0){throw 'V2_FINAL_LIVE_SAVE_ID_DRIFT'}
    $descriptors=@();foreach($name in @('Disk','Journal','Process','RootBinding','Transport')){if($Context.$name-isnot[scriptblock]){throw "V2_FINAL_LIVE_ADAPTER_TYPE_DRIFT:$name"};$descriptor=&$Context.$name 'compatibility' $null;Assert-AuthKeys $descriptor @('adapter','binding_id','operations') "V2_FINAL_LIVE_DESCRIPTOR_$name";if($descriptor.adapter-cne$name-or$descriptor.binding_id-cnotmatch'^[0-9A-F]{64}$'-or$descriptor.operations-isnot[Array]-or$descriptor.operations.Count-eq 0){throw "V2_FINAL_LIVE_ADAPTER_BINDING_DRIFT:$name"};$descriptors+=,$descriptor}
    if(@($descriptors|ForEach-Object{$_.binding_id}|Sort-Object -Unique).Count-ne 1){throw 'V2_FINAL_LIVE_CROSS_ADAPTER_BINDING_DRIFT'}
    if($Context.ModuleProbe-isnot[scriptblock]){throw 'V2_FINAL_LIVE_ADAPTER_TYPE_DRIFT:ModuleProbe'}
    $expectedProbe=Get-AuthTextSHA256 ((New-AuthStableFileModuleProbeV2).ToString());$actualProbe=Get-AuthTextSHA256 ($Context.ModuleProbe.ToString());if($actualProbe-cne$expectedProbe){throw 'V2_FINAL_LIVE_MODULE_ADAPTER_DRIFT'}
    return [pscustomobject]@{BindingId=[string]$descriptors[0].binding_id;ContextKeys=[object[]]$actual;ImplementationContractSHA256=[string]$Context.ImplementationContractSHA256;SaveRequestId=[long]$Context.SaveRequestId}
}
function Assert-UID0003YUFinalLiveOpenRawV2([string]$Raw,[string]$Label) {
    $value=ConvertFrom-AuthStrictJson $Raw $Label;Assert-AuthKeys $value @('error','observation','role_id') "$Label-ROOT"
    if($null-ne$value.error-or$value.role_id-isnot[string]-or[string]::IsNullOrWhiteSpace($value.role_id)){throw "$Label|OPEN_NATIVE_OR_VALUE_DRIFT"}
    Assert-AuthKeys $value.observation @('canonical_path','preferred_id','process_generation','returned_session','socket') "$Label-OBSERVATION"
    foreach($name in @('canonical_path','preferred_id','process_generation','returned_session','socket')){if($value.observation.$name-isnot[string]-or[string]::IsNullOrWhiteSpace($value.observation.$name)){throw "$Label|OPEN_OBSERVATION_DRIFT:$name"}}
    if($value.observation.returned_session-cne$value.role_id){throw "$Label|OPEN_ROLE_CORRELATION_DRIFT"};return $value
}
function Test-UID0003YUFinalLiveRawCompatibilityV2 {
    $schemas=[ordered]@{};foreach($pair in $AuthSchemaHashes.GetEnumerator()){$schemas[$pair.Key]=$pair.Value};$catalog=([ordered]@{method='tools/list';schemas=$schemas;tools=[object[]]@($AuthSchemaHashes.Keys)}|ConvertTo-Json -Compress);Assert-AuthCatalogV2 $catalog
    $open='{"error":null,"observation":{"canonical_path":"memory:canonical","preferred_id":"compat","process_generation":"pid:1;created:1","returned_session":"compat-role","socket":"127.0.0.1:1"},"role_id":"compat-role"}';$null=Assert-UID0003YUFinalLiveOpenRawV2 $open 'v2-live-safe-open'
    $runtime=New-UID0003YUHostileRuntimeV2 'compat-role' '' '';$runtimeValue=ConvertFrom-AuthStrictJson $runtime 'v2-live-safe-runtime';$memoryProbe={param($row)[pscustomobject][ordered]@{ctime_ns=[long]$row.ctime_ns;file_identity=[string]$row.file_identity;mtime_ns=[long]$row.mtime_ns;resolved_path=[string]$row.resolved_path;sha256=[string]$row.sha256;size=[long]$row.size}};$null=Assert-AuthRuntimeV2 $runtime 'compat-role' 'memory:canonical' $runtimeValue.implementation_contract_sha256 $memoryProbe
    $hashes=@();foreach($i in 1..14){$hashes+=,(Get-AuthTextSHA256 "compat-$i")};$readback=([ordered]@{phase='compat';protected_sha256=(Get-AuthTextSHA256 'compat-protected');result_ids=[object[]](1..14);state='PRE';transport_response_sha256=[object[]]$hashes}|ConvertTo-Json -Compress);$null=Assert-AuthReadbackV2 $readback 'compat' 'PRE'
    $plan=Get-AuthPlanV2 'I01';$operation=([ordered]@{ok=$true;operation='I01';request_sha256=$plan.SHA256}|ConvertTo-Json -Compress);$null=Assert-AuthOperationResponseV2 $operation 'I01' $plan.SHA256
    $save=([ordered]@{jsonrpc='2.0';id=[long]7003;result=[ordered]@{error=$null;ok=$true;path='memory:canonical'};error=$null}|ConvertTo-Json -Compress);$classification=Get-AuthSaveClassificationV2 $save 'memory:canonical' 7003;if($classification.Class-cne'SUCCESS'){throw 'V2_FINAL_LIVE_SAFE_SAVE_CLASSIFICATION_DRIFT'}
    return [pscustomobject]@{CatalogSHA256=Get-AuthTextSHA256 $catalog;OpenSHA256=Get-AuthTextSHA256 $open;RuntimeSHA256=Get-AuthTextSHA256 $runtime;ReadbackSHA256=Get-AuthTextSHA256 $readback;OperationSHA256=Get-AuthTextSHA256 $operation;SaveSHA256=Get-AuthTextSHA256 $save}
}
function Invoke-UID0003YUFinalLiveTransaction {
    $context=New-UID0003YUFinalLiveContext
    $null=Assert-UID0003YUFinalLiveContextCompatibilityV2 $context
    return Invoke-UID0003YUClosedCoordinator $context
}
function Invoke-UID0003YUFinalLiveCompatibilitySuiteV2 {
    $results=[Collections.Generic.List[object]]::new()
    $reject={param([string]$Label,[string]$Expected,[scriptblock]$Body)$message='';try{&$Body}catch{$message=$_.Exception.GetBaseException().Message};if([string]::IsNullOrWhiteSpace($message)-or$message.IndexOf($Expected,[StringComparison]::Ordinal)-lt 0){throw "$Label|WRONG_REJECTION|actual=$message|expected=$Expected"};$results.Add([pscustomobject]@{Label=$Label;Code=$Expected;Vector='0/0/0/0/0/0/0/0/0';Result='REJECTED'})}.GetNewClosure()
    $context=New-UID0003YUFinalLiveContext -CompatibilityOnly;$baseline=Assert-UID0003YUFinalLiveContextCompatibilityV2 $context;$results.Add([pscustomobject]@{Label='LIVEV2_00_BASELINE';Code='COMPATIBLE';Vector='0/0/0/0/0/0/0/0/0';Result='PASSED'})
    $copy={param($source)$o=[ordered]@{};foreach($name in $source.PSObject.Properties.Name){$o[$name]=$source.$name};return [pscustomobject]$o}
    $missing=&$copy $context;$missing.PSObject.Properties.Remove('SaveRequestId');&$reject 'LIVEV2_01_MISSING_FIELD' 'V2_PRODUCTION_CONTEXT|KEY_DRIFT' {Invoke-UID0003YUClosedCoordinator $missing|Out-Null}
    $blank=&$copy $context;$blank.ImplementationContractSHA256='';&$reject 'LIVEV2_02_BLANK_IMPLEMENTATION' 'V2_IMPLEMENTATION_CONTRACT_MISSING' {Invoke-UID0003YUClosedCoordinator $blank|Out-Null}
    $wrong=&$copy $context;$wrong.SaveRequestId=[long]0;&$reject 'LIVEV2_03_WRONG_SAVE_ID' 'V2_SAVE_REQUEST_ID_INVALID' {Invoke-UID0003YUClosedCoordinator $wrong|Out-Null}
    $old=New-UID0003YULiveContext;&$reject 'LIVEV2_04_OLD_CONTEXT_SUBSTITUTION' 'V2_PRODUCTION_CONTEXT|KEY_DRIFT' {Invoke-UID0003YUClosedCoordinator $old|Out-Null}
    $module=&$copy $context;$module.ModuleProbe={param($row)$row};&$reject 'LIVEV2_05_MODULE_ADAPTER_SUBSTITUTION' 'V2_FINAL_LIVE_MODULE_ADAPTER_DRIFT' {Assert-UID0003YUFinalLiveContextCompatibilityV2 $module|Out-Null}
    $process=&$copy $context;$process.Process={param($op,$value)[pscustomobject]@{adapter='Process';binding_id=('0'*64);operations=[object[]]@('snapshot')}};&$reject 'LIVEV2_06_PROCESS_ADAPTER_SUBSTITUTION' 'V2_FINAL_LIVE_CROSS_ADAPTER_BINDING_DRIFT' {Assert-UID0003YUFinalLiveContextCompatibilityV2 $process|Out-Null}
    $root=&$copy $context;$root.RootBinding={param($op,$value)[pscustomobject]@{adapter='RootBinding';binding_id=('0'*64);operations=[object[]]@('read')}};&$reject 'LIVEV2_07_ROOT_ADAPTER_SUBSTITUTION' 'V2_FINAL_LIVE_CROSS_ADAPTER_BINDING_DRIFT' {Assert-UID0003YUFinalLiveContextCompatibilityV2 $root|Out-Null}
    & $reject 'LIVEV2_08_CATALOG_RAW_DRIFT' 'V2_CATALOG_REJECTED' {Assert-AuthCatalogV2 '{"method":"tools/call","schemas":{},"tools":[]}'|Out-Null}
    & $reject 'LIVEV2_09_OPEN_RAW_DRIFT' 'v2-live-drift-open-ROOT|KEY_DRIFT' {Assert-UID0003YUFinalLiveOpenRawV2 '{"error":null,"extra":1,"observation":null,"role_id":"x"}' 'v2-live-drift-open'|Out-Null}
    & $reject 'LIVEV2_10_READBACK_RAW_DRIFT' 'KEY_DRIFT' {Assert-AuthReadbackV2 '{"phase":"compat","protected_sha256":"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","result_ids":[],"state":"PRE","transport_response_sha256":[],"extra":1}' 'compat' 'PRE'|Out-Null}
    $plan=Get-AuthPlanV2 'I01';&$reject 'LIVEV2_11_OPERATION_RAW_DRIFT' 'OPERATION_RESPONSE_CORRELATION_DRIFT:I01' {Assert-AuthOperationResponseV2 '{"ok":true,"operation":"I01","request_sha256":"0000000000000000000000000000000000000000000000000000000000000000"}' 'I01' $plan.SHA256|Out-Null}
    & $reject 'LIVEV2_12_SAVE_RAW_DRIFT' 'SAVE_V2_REQUEST_ID_DRIFT' {Get-AuthSaveClassificationV2 '{"jsonrpc":"2.0","id":7004,"result":{"error":null,"ok":true,"path":"memory:canonical"},"error":null}' 'memory:canonical' 7003|Out-Null}
    $rawProof=Test-UID0003YUFinalLiveRawCompatibilityV2
    $liveText=(Get-Command Invoke-UID0003YUFinalLiveTransaction).Definition;$hostileText=(Get-Command Invoke-UID0003YUAuthenticatedHostileSuiteV2).Definition
    if($liveText.IndexOf('Invoke-UID0003YUClosedCoordinator',[StringComparison]::Ordinal)-lt 0-or$hostileText.IndexOf('Invoke-UID0003YUClosedCoordinator',[StringComparison]::Ordinal)-lt 0){throw 'V2_FINAL_LIVE_SHARED_CORE_CALL_GRAPH_MISSING'}
    $labels=@($results|ForEach-Object{$_.Label});if($labels.Count-ne 13-or@($labels|Sort-Object -Unique).Count-ne13){throw 'V2_FINAL_LIVE_COMPATIBILITY_LABEL_DRIFT'}
    return [pscustomobject]@{Marker='UID0003YU_FINAL_LIVE_COMPATIBILITY_SUITE_PASSED';Count=$results.Count;Labels=$labels;Results=@($results);BindingId=$baseline.BindingId;CallGraphSHA256=Get-AuthTextSHA256 ($liveText+'|'+$hostileText);RawProof=$rawProof}
}
~~~

## Removed Block R016

- SHA256: `902D3E40B60129CE90B7523F5D11FE4E8E9768C8429AC3B3E4D634AAEBF1CA00`
- Language: `powershell`
- Bytes: `48171`
- First recovered timestamp: `2026-08-08T23:21:52.373Z`
- Session provenance: rollout-2026-08-07T21-28-25-019fdefc-4eb3-7c02-8dc4-19f7da3eee30.jsonl line 197448 (2026-08-08T23:21:52.373Z); rollout-2026-08-07T21-28-25-019fdefc-4eb3-7c02-8dc4-19f7da3eee30.jsonl line 197449 (2026-08-08T23:21:52.557Z)

~~~powershell
# UID0003YU V5 SELF-CONTAINED PRODUCTION AUTHORITY START
function Get-UID0003YUInlineSHA256V5([byte[]]$Bytes){$sha=[Security.Cryptography.SHA256]::Create();try{return([BitConverter]::ToString($sha.ComputeHash($Bytes))).Replace('-','')}finally{$sha.Dispose()}}
function Get-UID0003YUFunctionSHA256V5([string]$Name){$command=Get-Command $Name -CommandType Function -ErrorAction Stop;return Get-UID0003YUInlineSHA256V5 ([Text.Encoding]::UTF8.GetBytes([string]$command.Definition))}
function Get-UID0003YUOwnKeysV5($Value){if($Value-is[Collections.IDictionary]){return @($Value.Keys|ForEach-Object{[string]$_})};return @($Value.PSObject.Properties.Name)}
function Assert-UID0003YUOwnKeysV5($Value,[string[]]$Expected,[string]$Label){if($null-eq$Value-or$Value-is[string]-or$Value-is[ValueType]-or$Value-is[Array]){throw "$Label|NOT_OBJECT"};$actual=@(Get-UID0003YUOwnKeysV5 $Value|Sort-Object);$want=@($Expected|Sort-Object);if(($actual-join'|')-cne($want-join'|')){throw "$Label|KEY_DRIFT|actual=$($actual-join',')|expected=$($want-join',')"}}
function Initialize-UID0003YUAuthorityTypesV5 {
    Initialize-UID0003YUPlatformV4
    if(-not('UID0003YU.NativeCommandLine'-as[type])){Add-Type -TypeDefinition @'
using System;
using System.ComponentModel;
using System.Runtime.InteropServices;
namespace UID0003YU {
    public static class NativeCommandLine {
        [DllImport("shell32.dll",SetLastError=true)] static extern IntPtr CommandLineToArgvW([MarshalAs(UnmanagedType.LPWStr)] string commandLine,out int argc);
        [DllImport("kernel32.dll")] static extern IntPtr LocalFree(IntPtr pointer);
        public static string[] Parse(string commandLine){int argc;IntPtr argv=CommandLineToArgvW(commandLine,out argc);if(argv==IntPtr.Zero)throw new Win32Exception(Marshal.GetLastWin32Error());try{string[] result=new string[argc];for(int i=0;i<argc;i++)result[i]=Marshal.PtrToStringUni(Marshal.ReadIntPtr(argv,i*IntPtr.Size));return result;}finally{LocalFree(argv);}}
    }
}
'@}
    if(-not('UID0003YU.FrozenContract'-as[type])){Add-Type -TypeDefinition @'
namespace UID0003YU { public sealed class FrozenContract { public readonly string Name; public readonly string CanonicalJson; public readonly string SHA256; public FrozenContract(string name,string json,string sha256){Name=name;CanonicalJson=json;SHA256=sha256;} } }
'@}
    if(-not('UID0003YUAuth.FrozenContract'-as[type])){Add-Type -AssemblyName System.Security -ErrorAction Stop;Add-Type -TypeDefinition @'
namespace UID0003YUAuth {
    public sealed class FrozenContract { public readonly string Name; public readonly string CanonicalJson; public readonly string SHA256; public FrozenContract(string name,string json,string sha256){Name=name;CanonicalJson=json;SHA256=sha256;} }
    public sealed class HeldTuple { public readonly string Path; public readonly long Length; public readonly string SHA256; public readonly long LastWriteTimeUtcTicks; public readonly long CreationTimeUtcTicks; public readonly string FileIdentity; public HeldTuple(string path,long length,string sha256,long mtime,long ctime,string identity){Path=path;Length=length;SHA256=sha256;LastWriteTimeUtcTicks=mtime;CreationTimeUtcTicks=ctime;FileIdentity=identity;} }
}
'@}
}
function Get-UID0003YUAuthorityLiteralV5($ExpectedFunctionHashes){
    $schemas=[ordered]@{
        runtime_attestation=[ordered]@{SHA256='B07CA20D3A99752374BF8E96FF44C28542708C1FF4741E9D71E78E71F0A71252';Required=@();Properties=@('expected_canonical_path','expected_database')}
        server_health=[ordered]@{SHA256='A671F932AAA8F8C2375273DCB5A043518CCAAADC9EA4A05B322544B4BF80365B';Required=@();Properties=@('database')}
        idb_open=[ordered]@{SHA256='2B6AA209DFD45FBB7152CED3B01FEFF89A40067DA3864921711BD52B72D173A7';Required=@('input_path');Properties=@('build_caches','idle_ttl_sec','init_hexrays','input_path','mode','preferred_session_id','run_auto_analysis')}
        idb_list=[ordered]@{SHA256='257451A6E096AEB78F47F8925A27DAE7454E29C2D114F7C1DD7581AC1EF3C403';Required=@();Properties=@()}
        lookup_funcs=[ordered]@{SHA256='0FEE1BA456CBE9456BC1AA72E33F6050C612612074811D4964654B373E540EBF';Required=@('queries','database');Properties=@('database','queries')}
        stack_frame=[ordered]@{SHA256='F96768D21E784255720D88E62C18E887C6D9D2F489658CCB761AE90F89B30FFA';Required=@('addrs','database');Properties=@('addrs','database')}
        get_comments=[ordered]@{SHA256='F96768D21E784255720D88E62C18E887C6D9D2F489658CCB761AE90F89B30FFA';Required=@('addrs','database');Properties=@('addrs','database')}
        inspect_items=[ordered]@{SHA256='F96768D21E784255720D88E62C18E887C6D9D2F489658CCB761AE90F89B30FFA';Required=@('addrs','database');Properties=@('addrs','database')}
        get_bytes=[ordered]@{SHA256='A82BC69B8E13FB37BAFDF38CF8D97A7B0D65EBFBB70AF7B7C407021FA9998AC0';Required=@('regions','database');Properties=@('database','regions')}
        disasm=[ordered]@{SHA256='D55124BD3B3BE86DCD9F4DCDCCD346CB019D56CDBF7BD6195D13CAABC3C72CF6';Required=@('addr','database');Properties=@('addr','database','include_total','max_instructions','offset')}
        xrefs_to=[ordered]@{SHA256='9F321F1FCD074FC3C91B99FE9CB9144951AC20BD83857468553944314793BF87';Required=@('addrs','database');Properties=@('addrs','database','limit')}
        xref_query=[ordered]@{SHA256='18E02E6E6A47A0FEBF0C5DC8386F4CCDDA97B7561EAAEC93FE1EDE6216673868';Required=@('queries','database');Properties=@('database','queries')}
        find=[ordered]@{SHA256='4819B0F3B080569EF3C4E69E1B0F250593055949F7DA51FF33958A1A39AD4E79';Required=@('type','targets','database');Properties=@('database','limit','offset','targets','type')}
        find_bytes=[ordered]@{SHA256='0A6428809874940C8E0E5AD4CA55FDC9844BC97391BB1E517A7F47FAEA1D3439';Required=@('patterns','database');Properties=@('database','limit','offset','patterns')}
        type_inspect=[ordered]@{SHA256='020841CD93532339E6E7648F44082F80C594D6AC8793D2F563228111E7A3258A';Required=@('queries','database');Properties=@('database','queries')}
        rename=[ordered]@{SHA256='C9075D7FABCE19A253C58F9ACCFE13EC124C37C39E73E886BC254F576E3D98E6';Required=@('batch','database');Properties=@('batch','database')}
        set_type=[ordered]@{SHA256='90301A903C7A3DD6E3006193ED5C94AAADE1BCF5F58D71E2400013EF835A165E';Required=@('edits','database');Properties=@('database','edits')}
        set_function_comments=[ordered]@{SHA256='1757AB7572624FA067B490A7A4D735B433B6ADAE58701130BB4D61F671B973BB';Required=@('items','database');Properties=@('database','items')}
        idb_save=[ordered]@{SHA256='02F1C044A6F865EA6913E9C22D63CBD2EC5501F8DBA7BFBE4F18249C762A7502';Required=@('database');Properties=@('database','path')}
    }
    $roles=[ordered]@{
        Diagnostic=[ordered]@{RoleName='diagnostic';BuildCaches=$false;InitHexrays=$false};Transaction=[ordered]@{RoleName='transaction';BuildCaches=$false;InitHexrays=$false}
        VerifySuccess=[ordered]@{RoleName='verify-success';BuildCaches=$false;InitHexrays=$false};VerifySaveFailureA=[ordered]@{RoleName='verify-save-failure-a';BuildCaches=$false;InitHexrays=$false};VerifySaveFailureB=[ordered]@{RoleName='verify-save-failure-b';BuildCaches=$false;InitHexrays=$false}
        VerifyIndeterminateA=[ordered]@{RoleName='verify-indeterminate-a';BuildCaches=$false;InitHexrays=$false};VerifyIndeterminateB=[ordered]@{RoleName='verify-indeterminate-b';BuildCaches=$false;InitHexrays=$false};VerifyRecoveryA=[ordered]@{RoleName='verify-recovery-a';BuildCaches=$false;InitHexrays=$false};VerifyRecoveryB=[ordered]@{RoleName='verify-recovery-b';BuildCaches=$false;InitHexrays=$false};VerifyPreSaveFailure=[ordered]@{RoleName='verify-pre-save-failure';BuildCaches=$false;InitHexrays=$false};RollbackVerify=[ordered]@{RoleName='rollback-verify';BuildCaches=$false;InitHexrays=$false}
    }
    $exactType='RankingCategoryRecord *__thiscall RankingCategoryRecordRangeCopyConstructDeep(RankingCategoryRecordVectorStorage *this, const RankingCategoryRecord *first, const RankingCategoryRecord *last, RankingCategoryRecord *destination)'
    $exactComment='Compiler-generated std::vector<RankingCategoryRecord> uninitialized range-copy helper for RankingCategoryCollection::m_records: deep-copy constructs [first,last) into destination at 0x2b0 stride, destroys the constructed prefix on exception, and returns the destination end; no standalone source helper.'
    $plans=[ordered]@{
        Collision=[ordered]@{queries=@('0x0045d660','RankingCategoryRecordRangeCopyConstructDeep')}
        DryRun=[ordered]@{batch=[ordered]@{func=[ordered]@{addr='0x0045d660';name='RankingCategoryRecordRangeCopyConstructDeep'};dry_run=$true;stop_on_error=$true;allow_overwrite=$false;pure=$true}}
        I01=[ordered]@{batch=[ordered]@{func=[ordered]@{addr='0x0045d660';name='RankingCategoryRecordRangeCopyConstructDeep'};dry_run=$false;stop_on_error=$true;allow_overwrite=$false;pure=$true}}
        I02=[ordered]@{edits=[ordered]@{addr='0x0045d660';kind='function';signature=$exactType}}
        I03=[ordered]@{items=[ordered]@{addr='0x0045d660';comment=$exactComment}}
    }
    $protection=[ordered]@{
        Validator='Assert-RBYU14';ValidatorSHA256=[string]$ExpectedFunctionHashes['Assert-RBYU14'];KeyOrder=@('Bytes','XrefQuery','Immediate','DataRef','CodeRef','Encoded','Types');States=@('PRE','POST_I01','POST_I02','POST_I03','FINAL');Phases=@('diagnostic','pre-I01','post-I01','post-I02-a','post-I02-b','post-I03','final')
        Target=[ordered]@{Address='0x0045d660';Size=118;PreName='sub_45D660';FinalName='RankingCategoryRecordRangeCopyConstructDeep';Type=$exactType;Comment=$exactComment;FrameRows=10;DisassemblyRows=51;RecordStride=688;RecordMemberCount=15}
        ProtectedAddresses=@('0x0045d653','0x0045d660','0x0045d6d6','0x0045d6e0','0x0045d0c8','0x0045d0d9','0x0045d6a8','0x005fa330','0x005fa338','0x0045d420','0x0045cf50')
        BodySHA256='95FC2BD32CC6853A9C43E12A2FA3C7EF95C9C496807F8793E3560A6AC366C564';EhSHA256='5957B86FEC7D2C2003F49238E3A5C85E8378EA26D6947FE20A064008F7D5280E';CallerAddresses=@('0x45d0c8','0x45d0d9')
    }
    return [ordered]@{Version=5;TargetUID='0003YU';Runtime=[ordered]@{EndpointAddress='127.0.0.1';EndpointPort=13337;CanonicalPath='E:\NTK\Resources\NexusTK\NexusTK.exe.i64'};Schemas=$schemas;RoleDefinitions=$roles;Plans=$plans;Protection=$protection;Phases=@('pre-I01','post-I01','post-I02-a','post-I02-b','post-I03','final')}
}
function New-UID0003YUAuthorityV5($ExpectedFunctionHashes){$value=Get-UID0003YUAuthorityLiteralV5 $ExpectedFunctionHashes;$json=Get-AuthCanonicalJson $value;return [pscustomobject][ordered]@{CanonicalJson=$json;SHA256=(Get-UID0003YUInlineSHA256V5 ([Text.Encoding]::UTF8.GetBytes($json)));Value=$value}}
function Assert-UID0003YUAuthorityV5($Authority){
    Assert-UID0003YUOwnKeysV5 $Authority @('CanonicalJson','SHA256','Value') 'V5_AUTHORITY';if($Authority.CanonicalJson-isnot[string]-or$Authority.SHA256-isnot[string]-or$Authority.SHA256-cnotmatch'^[0-9A-F]{64}$'-or(Get-UID0003YUInlineSHA256V5 ([Text.Encoding]::UTF8.GetBytes([string]$Authority.CanonicalJson))-cne[string]$Authority.SHA256-or(Get-AuthCanonicalJson $Authority.Value)-cne[string]$Authority.CanonicalJson){throw 'V5_AUTHORITY_HASH_DRIFT'}
    $v=$Authority.Value;Assert-UID0003YUOwnKeysV5 $v @('Phases','Plans','Protection','RoleDefinitions','Runtime','Schemas','TargetUID','Version') 'V5_AUTHORITY_ROOT';if($v.Version-isnot[int]-or[int]$v.Version-ne5-or$v.TargetUID-isnot[string]-or$v.TargetUID-cne'0003YU'){throw 'V5_AUTHORITY_IDENTITY_DRIFT'}
    Assert-UID0003YUOwnKeysV5 $v.Runtime @('CanonicalPath','EndpointAddress','EndpointPort') 'V5_RUNTIME';if($v.Runtime.EndpointAddress-cne'127.0.0.1'-or$v.Runtime.EndpointPort-isnot[int]-or[int]$v.Runtime.EndpointPort-ne13337-or$v.Runtime.CanonicalPath-cne'E:\NTK\Resources\NexusTK\NexusTK.exe.i64'){throw 'V5_RUNTIME_LITERAL_DRIFT'}
    $planNames=@(Get-UID0003YUOwnKeysV5 $v.Plans);if($planNames.Count-ne5-or($planNames-join'|')-cne'Collision|DryRun|I01|I02|I03'){throw 'V5_PLAN_CARDINALITY_OR_ORDER_DRIFT'}
    if($v.Plans.Collision.queries-isnot[Array]-or$v.Plans.Collision.queries.Count-ne2-or@($v.Plans.Collision.queries|Where-Object{$_-isnot[string]}).Count){throw 'V5_PLAN_TYPE_DRIFT:Collision'}
    foreach($name in @('DryRun','I01')){$plan=$v.Plans.$name;if($null-eq$plan.batch-or$plan.batch.dry_run-isnot[bool]-or$plan.batch.stop_on_error-isnot[bool]-or$plan.batch.allow_overwrite-isnot[bool]-or$plan.batch.pure-isnot[bool]-or$plan.batch.func.addr-isnot[string]-or$plan.batch.func.name-isnot[string]){throw "V5_PLAN_TYPE_DRIFT:$name"}}
    if($null-eq$v.Plans.I02.edits-or$v.Plans.I02.edits.addr-isnot[string]-or$v.Plans.I02.edits.kind-isnot[string]-or$v.Plans.I02.edits.signature-isnot[string]){throw 'V5_PLAN_TYPE_DRIFT:I02'}
    if($null-eq$v.Plans.I03.items-or$v.Plans.I03.items.addr-isnot[string]-or$v.Plans.I03.items.comment-isnot[string]){throw 'V5_PLAN_TYPE_DRIFT:I03'}
    if((Get-UID0003YUOwnKeysV5 $v.Schemas).Count-ne19){throw 'V5_SCHEMA_CARDINALITY_DRIFT'};if((Get-UID0003YUOwnKeysV5 $v.RoleDefinitions).Count-ne11){throw 'V5_ROLE_CARDINALITY_DRIFT'}
    Assert-UID0003YUOwnKeysV5 $v.Protection @('BodySHA256','CallerAddresses','EhSHA256','KeyOrder','Phases','ProtectedAddresses','States','Target','Validator','ValidatorSHA256') 'V5_PROTECTION';if($v.Protection.Validator-cne'Assert-RBYU14'-or$v.Protection.ValidatorSHA256-cnotmatch'^[0-9A-F]{64}$'-or$v.Protection.ValidatorSHA256-cne(Get-UID0003YUFunctionSHA256V5 'Assert-RBYU14')-or$v.Protection.KeyOrder-isnot[Array]-or($v.Protection.KeyOrder-join'|')-cne'Bytes|XrefQuery|Immediate|DataRef|CodeRef|Encoded|Types'){throw 'V5_PROTECTION_CONTRACT_DRIFT'}
    return $Authority
}
function Set-UID0003YUReadOnlyGlobalV5([string]$Name,$Value){$existing=Get-Variable -Scope Global -Name $Name -ErrorAction SilentlyContinue;if($null-ne$existing){if(-not($existing.Options-band[Management.Automation.ScopedItemOptions]::ReadOnly)-or(Get-AuthCanonicalJson $existing.Value)-cne(Get-AuthCanonicalJson $Value)){throw "V5_GLOBAL_AUTHORITY_DRIFT:$Name"};return};Set-Variable -Scope Global -Name $Name -Value $Value -Option ReadOnly}
function Assert-UID0003YUGlobalAuthorityV5($Authority){
    $literal=$Authority.Value;foreach($name in @('UID0003YUAuthorityV5','AuthContracts','FrozenPlans','FrozenProtection','RoleDefinitions','AuthSchemaHashes','UsedToolSchemaContracts','CollisionArgumentsContract','PureDryRunArgumentsContract','I01ArgumentsContract','I02ArgumentsContract','I03ArgumentsContract','TransactionParametersContract')){$variable=Get-Variable -Scope Global -Name $name -ErrorAction SilentlyContinue;if($null-eq$variable-or-not($variable.Options-band[Management.Automation.ScopedItemOptions]::ReadOnly)){throw "V5_GLOBAL_AUTHORITY_MISSING_OR_MUTABLE:$name"}}
    if((Get-AuthCanonicalJson (Get-Variable -Scope Global -Name UID0003YUAuthorityV5).Value)-cne(Get-AuthCanonicalJson $Authority)){throw 'V5_GLOBAL_AUTHORITY_OBJECT_DRIFT'}
    if((Get-AuthCanonicalJson (Get-Variable -Scope Global -Name RoleDefinitions).Value)-cne(Get-AuthCanonicalJson $literal.RoleDefinitions)-or(Get-AuthCanonicalJson (Get-Variable -Scope Global -Name UsedToolSchemaContracts).Value)-cne(Get-AuthCanonicalJson $literal.Schemas)){throw 'V5_GLOBAL_ROLE_OR_SCHEMA_DRIFT'}
    $contracts=Read-AuthFrozenContract (Get-Variable -Scope Global -Name AuthContracts).Value 'UID0003YUContracts';if((Get-AuthCanonicalJson $contracts)-cne(Get-AuthCanonicalJson $literal)){throw 'V5_GLOBAL_FROZEN_CONTRACT_DRIFT'}
    $plans=(Get-Variable -Scope Global -Name FrozenPlans).Value;foreach($name in @('Collision','DryRun','I01','I02','I03')){$value=Read-AuthFrozenContract $plans[$name] $name;if((Get-AuthCanonicalJson $value)-cne(Get-AuthCanonicalJson $literal.Plans[$name])){throw "V5_GLOBAL_FROZEN_PLAN_DRIFT:$name"}}
    $protection=Read-AuthFrozenContract (Get-Variable -Scope Global -Name FrozenProtection).Value 'RB-YU-Protection';if((Get-AuthCanonicalJson $protection)-cne(Get-AuthCanonicalJson $literal.Protection)){throw 'V5_GLOBAL_FROZEN_PROTECTION_DRIFT'}
}
function Invoke-UID0003YUPackageSealV5([string]$Boundary){$variable=Get-Variable -Scope Global -Name UID0003YUPackageSealV5 -ErrorAction SilentlyContinue;if($null-eq$variable-or-not($variable.Options-band[Management.Automation.ScopedItemOptions]::ReadOnly)-or$variable.Value-isnot[scriptblock]){throw 'V5_PACKAGE_SEAL_MISSING_OR_MUTABLE'};return &$variable.Value $Boundary}
function Initialize-UID0003YUProductionAuthorityV5($ExpectedFunctionHashes,$ReportReceipt){
    $existing=Get-Variable -Scope Global -Name UID0003YUPackageSealV5 -ErrorAction SilentlyContinue;if($null-ne$existing){$package=Invoke-UID0003YUPackageSealV5 'V5_REENTRY';$pre=Test-UID0003YUPreEffectProductionV5;return [pscustomobject][ordered]@{Reentry=$true;AuthoritySHA256=$package.SHA256;PreEffect=$pre}}
    Initialize-UID0003YUAuthorityTypesV5
    $authority=Assert-UID0003YUAuthorityV5 (New-UID0003YUAuthorityV5 $ExpectedFunctionHashes);$literal=$authority.Value
    $frozenPlans=[ordered]@{};foreach($name in @('Collision','DryRun','I01','I02','I03')){$frozenPlans[$name]=New-AuthFrozenContract $name $literal.Plans[$name]}
    $schemaHashes=[ordered]@{};foreach($name in $literal.Schemas.Keys){$schemaHashes[$name]=[string]$literal.Schemas[$name].SHA256}
    Set-UID0003YUReadOnlyGlobalV5 'UID0003YUAuthorityV5' $authority;Set-UID0003YUReadOnlyGlobalV5 'RoleDefinitions' $literal.RoleDefinitions;Set-UID0003YUReadOnlyGlobalV5 'UsedToolSchemaContracts' $literal.Schemas;Set-UID0003YUReadOnlyGlobalV5 'AuthSchemaHashes' $schemaHashes
    Set-UID0003YUReadOnlyGlobalV5 'FrozenPlans' $frozenPlans;Set-UID0003YUReadOnlyGlobalV5 'FrozenProtection' (New-AuthFrozenContract 'RB-YU-Protection' $literal.Protection);Set-UID0003YUReadOnlyGlobalV5 'AuthContracts' (New-AuthFrozenContract 'UID0003YUContracts' $literal)
    Set-UID0003YUReadOnlyGlobalV5 'CollisionArgumentsContract' $frozenPlans.Collision;Set-UID0003YUReadOnlyGlobalV5 'PureDryRunArgumentsContract' $frozenPlans.DryRun;Set-UID0003YUReadOnlyGlobalV5 'I01ArgumentsContract' $frozenPlans.I01;Set-UID0003YUReadOnlyGlobalV5 'I02ArgumentsContract' $frozenPlans.I02;Set-UID0003YUReadOnlyGlobalV5 'I03ArgumentsContract' $frozenPlans.I03;Set-UID0003YUReadOnlyGlobalV5 'TransactionParametersContract' (New-AuthFrozenContract 'TransactionParameters' $literal.RoleDefinitions.Transaction)
    Set-UID0003YUReadOnlyGlobalV5 'UID0003YUExpectedFunctionHashesV5' $ExpectedFunctionHashes;Set-UID0003YUReadOnlyGlobalV5 'UID0003YUReportReceiptV5' $ReportReceipt
    $expectedJson=Get-AuthCanonicalJson $ExpectedFunctionHashes;$authorityJson=[string]$authority.CanonicalJson;$authorityHash=[string]$authority.SHA256;$reportJson=Get-AuthCanonicalJson $ReportReceipt;$hashBytes={param([byte[]]$bytes)$sha=[Security.Cryptography.SHA256]::Create();try{return([BitConverter]::ToString($sha.ComputeHash($bytes))).Replace('-','')}finally{$sha.Dispose()}}.GetNewClosure();$hashText={param([string]$text)&$hashBytes ([Text.Encoding]::UTF8.GetBytes($text))}.GetNewClosure()
    $seal={param([string]$Boundary)$receipt=$reportJson|ConvertFrom-Json;$bytes=[IO.File]::ReadAllBytes([string]$receipt.Path);if($bytes.Length-ne[long]$receipt.Bytes-or(&$hashBytes $bytes)-cne[string]$receipt.SHA256){throw "V5_PACKAGE_REPORT_DRIFT:$Boundary"};$text=[Text.Encoding]::UTF8.GetString($bytes);if([regex]::Matches($text,'(?m)^READY_FOR_SUPERVISOR_GATE1_REVIEW$').Count-ne1-or[regex]::Matches($text,"`n").Count-ne[int]$receipt.Lines-or$text.IndexOf("`r",[StringComparison]::Ordinal)-ge0-or$text.IndexOf([char]0)-ge0-or-not$text.EndsWith("`n",[StringComparison]::Ordinal)){throw "V5_PACKAGE_REPORT_SHAPE_DRIFT:$Boundary"};$expected=$expectedJson|ConvertFrom-Json;foreach($property in $expected.PSObject.Properties){$command=Get-Command $property.Name -CommandType Function -ErrorAction Stop;$actual=&$hashText ([string]$command.Definition);if($actual-cne[string]$property.Value){throw "V5_PACKAGE_FUNCTION_DRIFT:$($property.Name)"}};$globalAuthority=(Get-Variable -Scope Global -Name UID0003YUAuthorityV5 -ErrorAction Stop).Value;if((Get-AuthCanonicalJson $globalAuthority)-cne(Get-AuthCanonicalJson ([pscustomobject][ordered]@{CanonicalJson=$authorityJson;SHA256=$authorityHash;Value=($authorityJson|ConvertFrom-Json)}))){throw 'V5_PACKAGE_AUTHORITY_OBJECT_DRIFT'};Assert-UID0003YUGlobalAuthorityV5 $globalAuthority;return $globalAuthority}.GetNewClosure()
    Set-Variable -Scope Global -Name UID0003YUPackageSealV5 -Value $seal -Option ReadOnly
    $package=Invoke-UID0003YUPackageSealV5 'V5_INITIALIZE';$pre=Test-UID0003YUPreEffectProductionV5;return [pscustomobject][ordered]@{Reentry=$false;AuthoritySHA256=$package.SHA256;PreEffect=$pre}
}
function Get-AuthPlanV2([string]$Name){
    $package=Invoke-UID0003YUPackageSealV5 "V5_PLAN:$Name";$contracts=Read-AuthFrozenContract (Get-Variable -Scope Global -Name AuthContracts).Value 'UID0003YUContracts';if($Name-notin@('Collision','DryRun','I01','I02','I03')){throw "V5_UNKNOWN_FROZEN_PLAN:$Name"};$frozen=(Get-Variable -Scope Global -Name FrozenPlans).Value[$Name];$value=Read-AuthFrozenContract $frozen $Name;if((Get-AuthCanonicalJson $value)-cne(Get-AuthCanonicalJson $contracts.Plans.$Name)){throw "V5_PLAN_AUTHORITY_MISMATCH:$Name"};$json=Get-AuthCanonicalJson $value;return [pscustomobject][ordered]@{Name=$Name;CanonicalJson=$json;SHA256=(Get-UID0003YUInlineSHA256V5 ([Text.Encoding]::UTF8.GetBytes($json)));Contract=(ConvertFrom-AuthStrictJson $json "v5-plan-$Name");Value=(ConvertFrom-AuthStrictJson $json "v5-plan-copy-$Name")}
}
function Get-UID0003YUProtectionContractV5 {$package=Invoke-UID0003YUPackageSealV5 'V5_PROTECTION';$value=Read-AuthFrozenContract (Get-Variable -Scope Global -Name FrozenProtection).Value 'RB-YU-Protection';if($value.ValidatorSHA256-cne(Get-UID0003YUFunctionSHA256V5 'Assert-RBYU14')){throw 'V5_PROTECTION_VALIDATOR_SUBSTITUTED'};return $value}
function Test-UID0003YUPreEffectProductionV5 {
    $package=Invoke-UID0003YUPackageSealV5 'V5_PRE_EFFECT';$plans=[ordered]@{};foreach($name in @('Collision','DryRun','I01','I02','I03')){$plan=Get-AuthPlanV2 $name;if($plan.Contract-is[string]-or$null-eq$plan.Contract){throw "V5_PRE_EFFECT_PLAN_TYPE:$name"};$plans[$name]=$plan.SHA256};$protection=Get-UID0003YUProtectionContractV5;$effects=[ordered]@{McpRequests=0;IdbOpen=0;FilesystemMutation=0;Save=0};return [pscustomobject][ordered]@{Marker='UID0003YU_V5_PRE_EFFECT_AUTHORITY_READY';AuthoritySHA256=[string]$package.SHA256;PlanCount=$plans.Count;PlanSHA256=$plans;ProtectionSHA256=(Get-UID0003YUInlineSHA256V5 ([Text.Encoding]::UTF8.GetBytes((Get-AuthCanonicalJson $protection))));ProtectionKeys=@($protection.KeyOrder);Effects=$effects}
}
function Import-UID0003YUProductionPackageV5([string]$ReportPath){
    $resolved=(Resolve-Path -LiteralPath $ReportPath).Path;$bytes=[IO.File]::ReadAllBytes($resolved);$text=[Text.Encoding]::UTF8.GetString($bytes);if($text.IndexOf("`r",[StringComparison]::Ordinal)-ge0-or$text.IndexOf([char]0)-ge0-or-not$text.EndsWith("`n",[StringComparison]::Ordinal)){throw 'V5_REPORT_ENCODING_OR_EOL_DRIFT'};$markerCount=[regex]::Matches($text,'(?m)^READY_FOR_SUPERVISOR_GATE1_REVIEW$').Count;if($markerCount-ne1){throw "V5_TERMINAL_MARKER_CARDINALITY:$markerCount"}
    $matches=[regex]::Matches($text,'(?ms)^```powershell\r?\n(?<body>.*?)^```\s*$');$definitions=[Collections.Generic.List[string]]::new();$names=[Collections.Generic.List[string]]::new();foreach($match in $matches){$tokens=$null;$errors=$null;$ast=[Management.Automation.Language.Parser]::ParseInput($match.Groups['body'].Value,[ref]$tokens,[ref]$errors);if($errors.Count){throw "V5_DEFINITION_PARSE:$($errors[0].Message)"};foreach($statement in $ast.EndBlock.Statements){if($statement-is[Management.Automation.Language.FunctionDefinitionAst]){$definitions.Add([regex]::Replace($statement.Extent.Text,'^function\s+[^\s\(\{]+',("function global:{0}"-f$statement.Name),[Text.RegularExpressions.RegexOptions]::IgnoreCase));$names.Add($statement.Name)}}};$script=[scriptblock]::Create(($definitions-join"`n`n"));. $script
    $required=@('Get-UID0003YUTextSHA256V4','Get-UID0003YUFunctionSHA256V5','Get-UID0003YUAuthorityLiteralV5','Assert-UID0003YUAuthorityV5','Get-AuthPlanV2','Get-UID0003YUProtectionContractV5','Assert-UID0003YUProtectionReceiptV5','Invoke-UID0003YUOperationV5','Invoke-UID0003YUReadbackV5','Invoke-UID0003YURuntimeV5','New-UID0003YUSharedContextV5','New-UID0003YUProductionContextV5','New-UID0003YUIsolatedContextV5','Invoke-UID0003YUDurableCoordinatorV4','Invoke-UID0003YUProductionGraphV5','Invoke-UID0003YUFinalLiveTransaction','Open-UID0003YULiveAuthorityV3','Read-UID0003YULiveJournalV3','Add-UID0003YULiveJournalRecordV3','Close-UID0003YULiveAuthorityV3','New-UID0003YUDurableBackupV4','Restore-UID0003YUFromDurableBackupV4','Get-UID0003YUSaveClassificationV3');$expected=[ordered]@{};foreach($name in $required){if(-not($names-contains$name)){throw "V5_DEFINITION_INVENTORY_MISSING:$name"};$expected[$name]=Get-UID0003YUFunctionSHA256V5 $name}
    $receipt=[ordered]@{Path=$resolved;SHA256=(Get-UID0003YUInlineSHA256V5 $bytes);Bytes=[long]$bytes.Length;Lines=[regex]::Matches($text,"`n").Count;FenceCount=$matches.Count;DefinitionCount=$definitions.Count;HistoricalTopLevelCommandsExecuted=0;TerminalMarkerCount=$markerCount};$init=Initialize-UID0003YUProductionAuthorityV5 $expected $receipt;return [pscustomobject][ordered]@{Marker='UID0003YU_V5_DEFINITION_LOAD_READY';Reentry=[bool]$init.Reentry;Report=$receipt;AuthoritySHA256=[string]$init.AuthoritySHA256;PreEffect=$init.PreEffect}
}
function Initialize-UID0003YULiveGlobalsV5($Authority){
    $null=Invoke-UID0003YUPackageSealV5 'V5_BEFORE_LIVE_GLOBALS';$runtime=$Authority.Value.Runtime;Set-UID0003YUReadOnlyGlobalV5 'endpointAddress' ([string]$runtime.EndpointAddress);Set-UID0003YUReadOnlyGlobalV5 'endpointPort' ([int]$runtime.EndpointPort);Set-UID0003YUReadOnlyGlobalV5 'CanonicalIdbPath' ((Resolve-Path -LiteralPath ([string]$runtime.CanonicalPath)).Path)
    $listener=Get-PassiveListenerBinding;$existing=Get-Variable -Scope Global -Name PassiveListener0 -ErrorAction SilentlyContinue;if($null-eq$existing){Set-Variable -Scope Global -Name PassiveListener0 -Value $listener -Option ReadOnly}else{Assert-FreshPassiveListener $existing.Value|Out-Null}
    $catalog=Assert-PublicToolCatalog (Invoke-McpRaw 'tools/list' @{}) 'v5-live-initial-catalog';$existingCatalog=Get-Variable -Scope Global -Name PublicToolCatalog0 -ErrorAction SilentlyContinue;if($null-eq$existingCatalog){Set-Variable -Scope Global -Name PublicToolCatalog0 -Value $catalog -Option ReadOnly}else{Assert-SamePublicToolCatalog $catalog $existingCatalog.Value 'v5-live-reentry-catalog'}
    if(-not(Get-Variable -Scope Global -Name UID0003YUImplementationContract0 -ErrorAction SilentlyContinue)){Set-Variable -Scope Global -Name UID0003YUImplementationContract0 -Value $null};return [pscustomobject][ordered]@{Ok=$true;SchemaDigest=(Get-UID0003YUInlineSHA256V5 ([Text.Encoding]::UTF8.GetBytes((Get-AuthCanonicalJson $Authority.Value.Schemas))));Catalog=$catalog}
}
function New-UID0003YULiveRawProviderV5($Authority,[string]$CanonicalPath){
    $roles=@{};$provider=[pscustomobject][ordered]@{
        Catalog={Initialize-UID0003YULiveGlobalsV5 $Authority}.GetNewClosure()
        Open={param([string]$kind)$role=Open-IdbRole "$kind-v5" $false $false;$handle=[pscustomobject][ordered]@{Id=[string]$role.ReturnedSessionId;Kind=$kind;Native=$role};$roles[$handle.Id]=$handle;return $handle}.GetNewClosure()
        Runtime={param($handle,[string]$kind)$proof=Invoke-ValidatedPublicRuntime $handle.Native "v5-$kind-runtime";$json=[string](Get-Variable -Scope Global -Name UID0003YUImplementationContract0 -ErrorAction Stop).Value;return [pscustomobject][ordered]@{Ok=$true;RoleId=[string]$handle.Id;ImplementationContractSHA256=(Get-UID0003YUInlineSHA256V5 ([Text.Encoding]::UTF8.GetBytes($json)));Native=$proof}}.GetNewClosure()
        Readback={param($handle,[string]$phase,[string]$state)$bundle=Invoke-RBYU $handle.Native "v5-$phase";$proof=Assert-RBYU14 $bundle $state $null "v5-$phase";$rawHashes=@($bundle.Keys|ForEach-Object{Get-UID0003YUInlineSHA256V5 ([Text.Encoding]::UTF8.GetBytes([string]$bundle[$_].Raw))});return [pscustomobject][ordered]@{Phase=$phase;State=$state;Protection=$proof.Protection;TransportResponseSHA256=$rawHashes}}.GetNewClosure()
        Operation={param($handle,[string]$name,$plan)$r=$handle.Native;switch($name){'Collision'{$raw=Invoke-RoleTool $r 'lookup_funcs' (ConvertTo-AuthRequestNode $plan.Contract) 'v5-collision';$null=Assert-CollisionLookupResponse $raw}'DryRun'{$raw=Invoke-RoleTool $r 'rename' (ConvertTo-AuthRequestNode $plan.Contract) 'v5-dry';$null=Assert-RenameActionResponse $raw $true 'v5-dry'}'I01'{$raw=Invoke-RoleTool $r 'rename' (ConvertTo-AuthRequestNode $plan.Contract) 'v5-I01';$null=Assert-RenameActionResponse $raw $false 'v5-I01'}'I02'{$raw=Invoke-RoleTool $r 'set_type' (ConvertTo-AuthRequestNode $plan.Contract) 'v5-I02';$null=Assert-TypeActionResponse $raw 'v5-I02'}'I03'{$raw=Invoke-RoleTool $r 'set_function_comments' (ConvertTo-AuthRequestNode $plan.Contract) 'v5-I03';$null=Assert-FunctionCommentActionResponse $raw 'v5-I03'}default{throw "V5_LIVE_OPERATION_UNKNOWN:$name"}};return [pscustomobject][ordered]@{Accepted=$true;Name=$name;PlanSHA256=[string]$plan.SHA256}}.GetNewClosure()
        Save={param($handle,$before)$raw=Invoke-McpToolRaw 'idb_save' ([ordered]@{path=$CanonicalPath;database=$handle.Id}) $before;$classified=Get-UID0003YUSaveClassificationV3 $raw $CanonicalPath $handle.Id;return [pscustomobject][ordered]@{Class=[string]$classified.Class;ResponseSHA256=[string]$classified.ResponseSHA256;Raw=$raw}}.GetNewClosure()
        Retire={param($handle,[string]$kind)try{$null=Complete-IdbRoleRetirement $handle.Native "v5-$kind-retire"}finally{$roles.Remove([string]$handle.Id)|Out-Null};return $true}.GetNewClosure()
    };return $provider
}
function New-UID0003YUIsolatedRawProviderV5($Authority,$BaseContext,[string]$Scenario){
    $state=[pscustomobject]@{Scenario=$Scenario;Phase='PRE';Roles=@{};Counters=[ordered]@{Catalog=0;Open=0;Runtime=0;Operation=0;Readback=0;Save=0;Retire=0}}
    $provider=[pscustomobject][ordered]@{
        Catalog={$state.Counters.Catalog++;return [pscustomobject][ordered]@{Ok=$true;SchemaDigest=(Get-UID0003YUInlineSHA256V5 ([Text.Encoding]::UTF8.GetBytes((Get-AuthCanonicalJson $Authority.Value.Schemas))));Catalog=$null}}.GetNewClosure()
        Open={param([string]$kind)$state.Counters.Open++;$id="$kind-$([guid]::NewGuid().ToString('N'))";$handle=[pscustomobject][ordered]@{Id=$id;Kind=$kind;Native=[pscustomobject]@{Fixture=$true}};$state.Roles[$id]=$handle;return $handle}.GetNewClosure()
        Runtime={param($handle,[string]$kind)$state.Counters.Runtime++;$digest=[string]$BaseContext.ImplementationContractSHA256;if($Scenario-ceq'RUNTIME_AUTHORITY_SUBSTITUTION'){$digest='0'*64};return [pscustomobject][ordered]@{Ok=$true;RoleId=[string]$handle.Id;ImplementationContractSHA256=$digest;Native=$null}}.GetNewClosure()
        Readback={param($handle,[string]$phase,[string]$expected)$state.Counters.Readback++;$actual=if($handle.Kind-like'verifier*'){if((Get-UID0003YUClosedTupleV4 $BaseContext.CanonicalPath).SHA256-ceq$BaseContext.State.PreSHA){'PRE'}else{'FINAL'}}else{$state.Phase};$protection=[ordered]@{};foreach($key in $Authority.Value.Protection.KeyOrder){$protection[$key]=Get-UID0003YUInlineSHA256V5 ([Text.Encoding]::UTF8.GetBytes("UID0003YU|$key"))};if($Scenario-ceq'READBACK_PROTECTION_SUBSTITUTION'-and$phase-ceq'diagnostic'){$protection.Bytes='0'*64};$hashes=@();foreach($i in 1..14){$hashes+=,(Get-UID0003YUInlineSHA256V5 ([Text.Encoding]::UTF8.GetBytes("$phase|$i")))};return [pscustomobject][ordered]@{Phase=$phase;State=$actual;Protection=$protection;TransportResponseSHA256=$hashes}}.GetNewClosure()
        Operation={param($handle,[string]$name,$plan)$state.Counters.Operation++;$hash=[string]$plan.SHA256;if($Scenario-ceq'OPERATION_PLAN_SUBSTITUTION'-and$name-ceq'I01'){$hash='0'*64};switch($name){'I01'{$state.Phase='POST_I01'}'I02'{$state.Phase='POST_I02'}'I03'{$state.Phase='FINAL'}};return [pscustomobject][ordered]@{Accepted=$true;Name=$name;PlanSHA256=$hash}}.GetNewClosure()
        Save={param($handle,$before)$state.Counters.Save++;$id=[long]9005;$request=[ordered]@{jsonrpc='2.0';id=$id;method='tools/call';params=[ordered]@{name='idb_save';arguments=[ordered]@{path=$BaseContext.CanonicalPath;database=$handle.Id}}};$json=$request|ConvertTo-Json -Depth 12 -Compress;$receipt=[pscustomobject][ordered]@{RequestId=$id;RequestJson=$json;RequestSHA256=(Get-UID0003YUInlineSHA256V5 ([Text.Encoding]::UTF8.GetBytes($json)))};&$before $receipt;[IO.File]::WriteAllBytes($BaseContext.CanonicalPath,$BaseContext.State.FinalBytes);$state.Phase='FINAL';$class=if($Scenario-ceq'EXPLICIT_FAILURE'){'EXPLICIT_FAILURE'}else{'SUCCESS'};return [pscustomobject][ordered]@{Class=$class;ResponseSHA256=(Get-UID0003YUInlineSHA256V5 ([Text.Encoding]::UTF8.GetBytes("$class|$id")));Raw=$null}}.GetNewClosure()
        Retire={param($handle,[string]$kind)$state.Counters.Retire++;$state.Roles.Remove([string]$handle.Id)|Out-Null;return $true}.GetNewClosure()
    };return [pscustomobject][ordered]@{Provider=$provider;State=$state}
}
function Assert-UID0003YUOperationReceiptV5($Receipt,$Plan,[string]$Name){Assert-UID0003YUOwnKeysV5 $Receipt @('Accepted','Name','PlanSHA256') "V5_OPERATION_RECEIPT:$Name";if($Receipt.Accepted-isnot[bool]-or$Receipt.Accepted-ne$true-or$Receipt.Name-isnot[string]-or$Receipt.Name-cne$Name-or$Receipt.PlanSHA256-isnot[string]-or$Receipt.PlanSHA256-cne$Plan.SHA256){throw "V5_OPERATION_PLAN_SUBSTITUTED:$Name"};return $Receipt}
function Invoke-UID0003YUOperationV5($RawProvider,$Handle,[string]$Name){$plan=Get-AuthPlanV2 $Name;$receipt=&$RawProvider.Operation $Handle $Name $plan;return Assert-UID0003YUOperationReceiptV5 $receipt $plan $Name}
function Assert-UID0003YUProtectionReceiptV5($Receipt,[string]$ExpectedState,[string]$Phase,$ProtectionContract,$FrozenState){
    Assert-UID0003YUOwnKeysV5 $Receipt @('Phase','Protection','State','TransportResponseSHA256') "V5_READBACK:$Phase";if($Receipt.Phase-isnot[string]-or$Receipt.Phase-cne$Phase-or$Receipt.State-isnot[string]-or$Receipt.State-cne$ExpectedState){throw "V5_READBACK_STATE_OR_PHASE_DRIFT:$Phase"};$keys=@(Get-UID0003YUOwnKeysV5 $Receipt.Protection);if(($keys-join'|')-cne(@($ProtectionContract.KeyOrder)-join'|')){throw "V5_READBACK_PROTECTION_KEY_DRIFT:$Phase"};foreach($key in $keys){if($Receipt.Protection.$key-isnot[string]-or$Receipt.Protection.$key-cnotmatch'^[0-9A-F]{64}$'){throw "V5_READBACK_PROTECTION_NATIVE_DRIFT:$Phase:$key"}};if($Receipt.TransportResponseSHA256-isnot[Array]-or$Receipt.TransportResponseSHA256.Count-ne14-or@($Receipt.TransportResponseSHA256|Where-Object{$_-isnot[string]-or$_-cnotmatch'^[0-9A-F]{64}$'}).Count){throw "V5_READBACK_TRANSPORT_DRIFT:$Phase"};$json=Get-AuthCanonicalJson $Receipt.Protection;$sha=Get-UID0003YUInlineSHA256V5 ([Text.Encoding]::UTF8.GetBytes($json));if([string]::IsNullOrWhiteSpace([string]$FrozenState.SHA256)){$FrozenState.CanonicalJson=$json;$FrozenState.SHA256=$sha}elseif($FrozenState.SHA256-cne$sha-or$FrozenState.CanonicalJson-cne$json){throw "V5_READBACK_PROTECTION_SUBSTITUTED:$Phase"};return [pscustomobject][ordered]@{Phase=$Phase;ProtectedSHA256=$sha;State=$ExpectedState}
}
function Invoke-UID0003YUReadbackV5($RawProvider,$Handle,[string]$Phase,[string]$State,$ProtectionContract,$FrozenState){$receipt=&$RawProvider.Readback $Handle $Phase $State;return Assert-UID0003YUProtectionReceiptV5 $receipt $State $Phase $ProtectionContract $FrozenState}
function Invoke-UID0003YURuntimeV5($RawProvider,$Handle,[string]$Kind,[string]$ExpectedImplementation){$receipt=&$RawProvider.Runtime $Handle $Kind;Assert-UID0003YUOwnKeysV5 $receipt @('ImplementationContractSHA256','Native','Ok','RoleId') "V5_RUNTIME:$Kind";if($receipt.Ok-isnot[bool]-or$receipt.Ok-ne$true-or$receipt.RoleId-isnot[string]-or$receipt.RoleId-cne[string]$Handle.Id-or$receipt.ImplementationContractSHA256-isnot[string]-or$receipt.ImplementationContractSHA256-cne$ExpectedImplementation){throw "V5_RUNTIME_AUTHORITY_SUBSTITUTED:$Kind"};return $receipt}
function New-UID0003YUSharedContextV5($BaseContext,$RawProvider,$Authority,$ProviderState){
    $null=Invoke-UID0003YUPackageSealV5 'V5_SHARED_FACTORY';Assert-UID0003YUOwnKeysV5 $RawProvider @('Catalog','Open','Operation','Readback','Retire','Runtime','Save') 'V5_RAW_PROVIDER';foreach($name in Get-UID0003YUOwnKeysV5 $RawProvider){if($RawProvider.$name-isnot[scriptblock]){throw "V5_RAW_PROVIDER_NOT_SCRIPTBLOCK:$name"}};$protection=Get-UID0003YUProtectionContractV5;$frozen=[pscustomobject]@{CanonicalJson='';SHA256=''};$durable=$BaseContext.Adapters;$adapters=$null
    $adapters=[pscustomobject][ordered]@{
        AuthorityClose=$durable.AuthorityClose;AuthorityOpen=$durable.AuthorityOpen;CaptureB0=$durable.CaptureB0;CaptureCurrent=$durable.CaptureCurrent;CaptureP0=$durable.CaptureP0;ClassifyDisk=$durable.ClassifyDisk;CreateB0=$durable.CreateB0;Journal=$durable.Journal;Restore=$durable.Restore
        Catalog={param()$receipt=&$RawProvider.Catalog;Assert-UID0003YUOwnKeysV5 $receipt @('Catalog','Ok','SchemaDigest') 'V5_CATALOG_RECEIPT';$expected=Get-UID0003YUInlineSHA256V5 ([Text.Encoding]::UTF8.GetBytes((Get-AuthCanonicalJson $Authority.Value.Schemas)));if($receipt.Ok-isnot[bool]-or$receipt.Ok-ne$true-or$receipt.SchemaDigest-isnot[string]-or$receipt.SchemaDigest-cne$expected){throw 'V5_CATALOG_AUTHORITY_DRIFT'};return $true}.GetNewClosure()
        Open={param([string]$kind)$handle=&$RawProvider.Open $kind;Assert-UID0003YUOwnKeysV5 $handle @('Id','Kind','Native') "V5_OPEN:$kind";if($handle.Id-isnot[string]-or[string]::IsNullOrWhiteSpace($handle.Id)-or$handle.Kind-isnot[string]-or$handle.Kind-cne$kind){throw "V5_OPEN_RECEIPT_DRIFT:$kind"};return $handle}.GetNewClosure()
        Runtime={param($handle,[string]$kind)return Invoke-UID0003YURuntimeV5 $RawProvider $handle $kind ([string]$BaseContext.ImplementationContractSHA256)}.GetNewClosure()
        Operation={param($handle,[string]$name)return Invoke-UID0003YUOperationV5 $RawProvider $handle $name}.GetNewClosure()
        Readback={param($handle,[string]$phase,[string]$state)return Invoke-UID0003YUReadbackV5 $RawProvider $handle $phase $state $protection $frozen}.GetNewClosure()
        Save={param($handle,$before)$receipt=&$RawProvider.Save $handle $before;Assert-UID0003YUOwnKeysV5 $receipt @('Class','Raw','ResponseSHA256') 'V5_SAVE_RECEIPT';if($receipt.Class-isnot[string]-or$receipt.Class-notin@('SUCCESS','EXPLICIT_FAILURE','INDETERMINATE')-or$receipt.ResponseSHA256-isnot[string]-or$receipt.ResponseSHA256-cnotmatch'^[0-9A-F]{64}$'){throw 'V5_SAVE_RECEIPT_DRIFT'};return $receipt}.GetNewClosure()
        Retire={param($handle,[string]$kind)$result=&$RawProvider.Retire $handle $kind;if($result-ne$true){throw "V5_RETIRE_NOT_PROVEN:$kind"};return $true}.GetNewClosure()
        Verify={param([int]$index,[string]$expected,[string]$implementation)$handle=&$adapters.Open "verifier-$index";try{$null=&$adapters.Runtime $handle "verifier-$index";$null=&$adapters.Readback $handle "verifier-$index" $expected;return [pscustomobject][ordered]@{Index=$index;Ok=$true;State=$expected}}finally{$null=&$adapters.Retire $handle "verifier-$index"}}.GetNewClosure()
        Recover={param($proof)$authorityHandle=&$durable.AuthorityOpen;try{$finalVerifier=&$adapters.Verify 98 'FINAL' ([string]$BaseContext.ImplementationContractSHA256);if($finalVerifier.Ok-ne$true){throw 'V5_CLOSE_RECOVERY_FINAL_NOT_ATTRIBUTABLE'};$restore=&$durable.Restore $proof;$rollback=&$adapters.Verify 99 'PRE' ([string]$BaseContext.ImplementationContractSHA256);$null=&$durable.Journal $authorityHandle 'restore' ([pscustomobject]@{P1=$proof.P1});return [pscustomobject][ordered]@{Restored=($restore.Restored-eq$true);RollbackVerified=($rollback.Ok-eq$true)}}finally{&$durable.AuthorityClose $authorityHandle}}.GetNewClosure()
    }
    return [pscustomobject][ordered]@{Mode=[string]$BaseContext.Mode;CanonicalPath=[string]$BaseContext.CanonicalPath;BackupPath=[string]$BaseContext.BackupPath;ContractDigest=[string]$Authority.SHA256;ImplementationContractSHA256=[string]$BaseContext.ImplementationContractSHA256;State=[pscustomobject][ordered]@{Base=$BaseContext.State;Provider=$ProviderState;FrozenProtection=$frozen};Adapters=$adapters}
}
function New-UID0003YUProductionContextV5 {$authority=Invoke-UID0003YUPackageSealV5 'V5_PRODUCTION_FACTORY';$null=Test-UID0003YUPreEffectProductionV5;$base=New-UID0003YUProductionContextV4;$provider=New-UID0003YULiveRawProviderV5 $authority $base.CanonicalPath;return New-UID0003YUSharedContextV5 $base $provider $authority ([pscustomobject]@{Mode='LIVE'})}
function New-UID0003YUIsolatedContextV5([string]$Root,[string]$Scenario){$authority=Invoke-UID0003YUPackageSealV5 'V5_ISOLATED_FACTORY';$base=New-UID0003YUIsolatedContextV4 $Root 'CLEAN_SUCCESS';$raw=New-UID0003YUIsolatedRawProviderV5 $authority $base $Scenario;return New-UID0003YUSharedContextV5 $base $raw.Provider $authority $raw.State}
function Invoke-UID0003YUProductionGraphV5($Context){$null=Invoke-UID0003YUPackageSealV5 'V5_PRODUCTION_GRAPH';return Invoke-UID0003YUDurableCoordinatorV4 $Context}
function Invoke-UID0003YUFinalLiveTransaction {try{$null=Invoke-UID0003YUPackageSealV5 'V5_PUBLIC_ENTRY';$pre=Test-UID0003YUPreEffectProductionV5;$context=New-UID0003YUProductionContextV5;return Invoke-UID0003YUProductionGraphV5 $context}catch{$message=$_.Exception.GetBaseException().Message;if($message-like'UID0003YU_GATE2B_FAILED|*'){throw};throw "UID0003YU_GATE2B_FAILED|cause=$([string]($message-split'\|',2)[0])"}}
function New-UID0003YUMutatedAuthorityV5([string]$Kind){$source=(Invoke-UID0003YUPackageSealV5 "V5_MUTATE_CLONE:$Kind").CanonicalJson|ConvertFrom-Json;switch($Kind){'PLAN_OMITTED'{$source.Plans.PSObject.Properties.Remove('I03')}'PLAN_TYPE_CHANGED'{$source.Plans.I02='wrong-native-type'}'PROTECTION_MISSING'{$source.PSObject.Properties.Remove('Protection')}'PROTECTION_CORRUPT'{$source.Protection.ValidatorSHA256='0'*64}default{throw "V5_UNKNOWN_AUTHORITY_MUTATION:$Kind"}};$json=Get-AuthCanonicalJson $source;return [pscustomobject][ordered]@{CanonicalJson=$json;SHA256=(Get-UID0003YUInlineSHA256V5 ([Text.Encoding]::UTF8.GetBytes($json)));Value=$source}}
function Test-UID0003YUFunctionSubstitutionV5([string]$Name){$original=[string](Get-Command $Name -CommandType Function -ErrorAction Stop).Definition;try{Set-Item -Path ("Function:\global:$Name") -Value ([scriptblock]::Create("throw 'V5_SUBSTITUTE_CALLED'")) -Force;$message='';try{$null=&(Get-Variable -Scope Global -Name UID0003YUPackageSealV5).Value "V5_SUBSTITUTION:$Name"}catch{$message=$_.Exception.GetBaseException().Message};if($message-cne"V5_PACKAGE_FUNCTION_DRIFT:$Name"){throw "V5_SUBSTITUTION_NOT_REJECTED:$Name:$message"};return $message}finally{Set-Item -Path ("Function:\global:$Name") -Value ([scriptblock]::Create($original)) -Force}}
function Invoke-UID0003YUFinalHostileSuiteV5([string]$ReportPath){
    $load1=Import-UID0003YUProductionPackageV5 $ReportPath;$load2=Import-UID0003YUProductionPackageV5 $ReportPath;if($load1.Reentry-ne$true-and$load2.Reentry-ne$true){throw 'V5_CLEAN_LOAD_REENTRY_NOT_PROVEN'};$results=[Collections.Generic.List[object]]::new();$add={param($label,$code,$effects,$cleanup)$results.Add([pscustomobject][ordered]@{Label=$label;Code=$code;Effects=$effects;Cleanup=$cleanup})}.GetNewClosure()
    foreach($case in @(@('PLAN_TYPE_OMITTED','PLAN_OMITTED','V5_PLAN_CARDINALITY_OR_ORDER_DRIFT'),@('PLAN_TYPE_CHANGED','PLAN_TYPE_CHANGED','V5_PLAN_TYPE_DRIFT:I02'),@('PROTECTION_MISSING','PROTECTION_MISSING','V5_AUTHORITY_ROOT|KEY_DRIFT'),@('PROTECTION_CORRUPT','PROTECTION_CORRUPT','V5_PROTECTION_CONTRACT_DRIFT'))){$message='';try{$null=Assert-UID0003YUAuthorityV5 (New-UID0003YUMutatedAuthorityV5 $case[1])}catch{$message=$_.Exception.GetBaseException().Message};if($message-notlike"$($case[2])*" ){throw "V5_AUTHORITY_HOSTILE_WRONG_CODE:$($case[0]):$message"};&$add "V5_$($case[0])" $message '0/0/0/0/0/0/0' 'no external boundary reached'}
    $missing='';try{$null=Read-AuthFrozenContract $null 'I01'}catch{$missing=$_.Exception.GetBaseException().Message};if($missing-cne'FROZEN_CONTRACT_MUTATION:I01'){throw "V5_MISSING_FROZEN_CONTRACT_NOT_REJECTED:$missing"};&$add 'V5_FROZEN_CONTRACT_MISSING' $missing '0/0/0/0/0/0/0' 'no external boundary reached'
    $corrupt=[UID0003YUAuth.FrozenContract]::new('I01','{}',('0'*64));$bad='';try{$null=Read-AuthFrozenContract $corrupt 'I01'}catch{$bad=$_.Exception.GetBaseException().Message};if($bad-cne'FROZEN_CONTRACT_MUTATION:I01'){throw "V5_CORRUPT_FROZEN_CONTRACT_NOT_REJECTED:$bad"};&$add 'V5_FROZEN_CONTRACT_CORRUPT' $bad '0/0/0/0/0/0/0' 'no external boundary reached'
    foreach($name in @('Get-UID0003YUTextSHA256V4','Get-AuthPlanV2','Assert-UID0003YUProtectionReceiptV5','Invoke-UID0003YUFinalLiveTransaction','New-UID0003YUSharedContextV5','Invoke-UID0003YUDurableCoordinatorV4')){$code=Test-UID0003YUFunctionSubstitutionV5 $name;&$add ("V5_FUNCTION_SUBSTITUTION_"+$name) $code '0/0/0/0/0/0/0' 'function restored; seal stable'}
    $sealMessage='';try{Set-Variable -Scope Global -Name UID0003YUPackageSealV5 -Value {return $true} -ErrorAction Stop}catch{$sealMessage='V5_PACKAGE_SEAL_READONLY_REJECTED'};if($sealMessage-cne'V5_PACKAGE_SEAL_READONLY_REJECTED'){throw 'V5_PACKAGE_SEAL_REPLACEABLE'};&$add 'V5_SEAL_SELF_SUBSTITUTION' $sealMessage '0/0/0/0/0/0/0' 'read-only seal unchanged'
    foreach($scenario in @('CLEAN_SUCCESS','OPERATION_PLAN_SUBSTITUTION','READBACK_PROTECTION_SUBSTITUTION','RUNTIME_AUTHORITY_SUBSTITUTION','EXPLICIT_FAILURE')){$root=Join-Path ([IO.Path]::GetTempPath()) ("UID0003YU-V5-"+[guid]::NewGuid().ToString('N'));[IO.Directory]::CreateDirectory($root)|Out-Null;try{$context=New-UID0003YUIsolatedContextV5 $root $scenario;$result=$null;$message='';try{$result=Invoke-UID0003YUProductionGraphV5 $context}catch{$message=$_.Exception.GetBaseException().Message};$c=$context.State.Provider.Counters;$vector=@($c.Catalog,$c.Open,$c.Runtime,$c.Operation,$c.Readback,$c.Save,$c.Retire)-join'/';if($scenario-ceq'CLEAN_SUCCESS'){if($null-eq$result-or$result.Marker-cne'UID0003YU_V4_CLEAN_COMMIT'-or$message-ne''){throw "V5_SHARED_CLEAN_FAILED:$message"}}elseif($scenario-ceq'OPERATION_PLAN_SUBSTITUTION'){if($message-cne'UID0003YU_GATE2B_FAILED|cause=V5_OPERATION_PLAN_SUBSTITUTED:I01'-or$c.Save-ne0){throw "V5_PLAN_SUBSTITUTION_ROUTE_DRIFT:$message:$vector"}}elseif($scenario-ceq'READBACK_PROTECTION_SUBSTITUTION'){if($message-notlike'UID0003YU_GATE2B_FAILED|cause=V5_READBACK_PROTECTION_*'-or$c.Save-ne0){throw "V5_PROTECTION_SUBSTITUTION_ROUTE_DRIFT:$message:$vector"}}elseif($scenario-ceq'RUNTIME_AUTHORITY_SUBSTITUTION'){if($message-cne'UID0003YU_GATE2B_FAILED|cause=V5_RUNTIME_AUTHORITY_SUBSTITUTED:diagnostic'-or$c.Save-ne0){throw "V5_RUNTIME_SUBSTITUTION_ROUTE_DRIFT:$message:$vector"}}elseif($scenario-ceq'EXPLICIT_FAILURE'){if($message-notlike'UID0003YU_GATE2B_FAILED|*'-or$c.Save-ne1-or(Get-UID0003YUClosedTupleV4 $context.CanonicalPath).SHA256-cne$context.State.Base.PreSHA){throw "V5_EXPLICIT_FAILURE_CLOSURE_DRIFT:$message:$vector"}};if($context.State.Provider.Roles.Count-ne0){throw "V5_SHARED_ROLE_LEAK:$scenario"};&$add "V5_SHARED_$scenario" $(if($message){$message}else{'CLEAN_COMMIT'}) $vector 'zero provider roles; temp root removed'}finally{Remove-Item -LiteralPath $root -Recurse -Force -ErrorAction SilentlyContinue}}
    $null=Invoke-UID0003YUPackageSealV5 'V5_SUITE_FINAL';$labels=@($results|ForEach-Object{$_.Label});if($labels.Count-ne17-or@($labels|Sort-Object -Unique).Count-ne17){throw "V5_SUITE_LABEL_DRIFT:$($labels.Count)"};$json=$results|ConvertTo-Json -Depth 12 -Compress;return [pscustomobject][ordered]@{Marker='UID0003YU_V5_SELF_CONTAINED_PRODUCTION_SUITE_PASSED';Count=$results.Count;Labels=$labels;ResultSHA256=(Get-UID0003YUInlineSHA256V5 ([Text.Encoding]::UTF8.GetBytes($json)));AuthoritySHA256=[string](Invoke-UID0003YUPackageSealV5 'V5_SUITE_RETURN').SHA256;ReportSHA256=[string]$load2.Report.SHA256;PreEffect=$load2.PreEffect;Results=@($results)}
}
# UID0003YU V5 SELF-CONTAINED PRODUCTION AUTHORITY END
~~~

## Removed Block R017

- SHA256: `E781AD8AD9CA24F888287D1EED1E6C1EDC6BA672C1EC52D7B363C85E6C3A6E2F`
- Language: `powershell`
- Bytes: `29520`
- First recovered timestamp: `2026-08-09T01:32:39.849Z`
- Session provenance: rollout-2026-08-07T21-28-25-019fdefc-4eb3-7c02-8dc4-19f7da3eee30.jsonl line 197893 (2026-08-09T01:32:39.849Z); rollout-2026-08-07T21-28-25-019fdefc-4eb3-7c02-8dc4-19f7da3eee30.jsonl line 197894 (2026-08-09T01:32:40.020Z)

~~~powershell
# UID0003YU V6 NON-SUBSTITUTABLE PRIVATE PRODUCTION AUTHORITY START
function Invoke-UID0003YUSharedRegressionV6 {
    $results=[Collections.Generic.List[object]]::new()
    foreach($scenario in @('CLEAN_SUCCESS','OPERATION_PLAN_SUBSTITUTION','READBACK_PROTECTION_SUBSTITUTION','RUNTIME_AUTHORITY_SUBSTITUTION','EXPLICIT_FAILURE')){
        $root=Join-Path ([IO.Path]::GetTempPath()) ("UID0003YU-V6-SHARED-"+[guid]::NewGuid().ToString('N'))
        [IO.Directory]::CreateDirectory($root)|Out-Null
        try{
            $context=New-UID0003YUIsolatedContextV5 $root $scenario
            $result=$null;$message=''
            try{$result=Invoke-UID0003YUProductionGraphV5 $context}catch{$message=$_.Exception.GetBaseException().Message}
            $c=$context.State.Provider.Counters;$vector=@($c.Catalog,$c.Open,$c.Runtime,$c.Operation,$c.Readback,$c.Save,$c.Retire)-join'/'
            if($scenario-ceq'CLEAN_SUCCESS'){
                if($null-eq$result-or$result.Marker-cne'UID0003YU_V4_CLEAN_COMMIT'-or$message-ne''){throw "V6_SHARED_CLEAN_FAILED:$message"}
            }elseif($scenario-ceq'OPERATION_PLAN_SUBSTITUTION'){
                if($message-cne'UID0003YU_GATE2B_FAILED|cause=V5_OPERATION_PLAN_SUBSTITUTED:I01'-or$c.Save-ne0){throw "V6_SHARED_PLAN_ROUTE_DRIFT:${message}:$vector"}
            }elseif($scenario-ceq'READBACK_PROTECTION_SUBSTITUTION'){
                if($message-notlike'UID0003YU_GATE2B_FAILED|cause=V5_READBACK_PROTECTION_*'-or$c.Save-ne0){throw "V6_SHARED_PROTECTION_ROUTE_DRIFT:${message}:$vector"}
            }elseif($scenario-ceq'RUNTIME_AUTHORITY_SUBSTITUTION'){
                if($message-cne'UID0003YU_GATE2B_FAILED|cause=V5_RUNTIME_AUTHORITY_SUBSTITUTED:diagnostic'-or$c.Save-ne0){throw "V6_SHARED_RUNTIME_ROUTE_DRIFT:${message}:$vector"}
            }elseif($scenario-ceq'EXPLICIT_FAILURE'){
                if($message-notlike'UID0003YU_GATE2B_FAILED|*'-or$c.Save-ne1-or(Get-UID0003YUClosedTupleV4 $context.CanonicalPath).SHA256-cne$context.State.Base.PreSHA){throw "V6_SHARED_FAILURE_CLOSURE_DRIFT:${message}:$vector"}
            }
            if($context.State.Provider.Roles.Count-ne0){throw "V6_SHARED_ROLE_LEAK:$scenario"}
            $results.Add([pscustomobject][ordered]@{Label="V6_SHARED_$scenario";Code=$(if($message){$message}else{'CLEAN_COMMIT'});Vector=$vector;Roles=[int]$context.State.Provider.Roles.Count})
        }finally{Remove-Item -LiteralPath $root -Recurse -Force -ErrorAction SilentlyContinue}
    }
    $labels=@($results|ForEach-Object{$_.Label});if($labels.Count-ne5-or@($labels|Sort-Object -Unique).Count-ne5){throw 'V6_SHARED_LABEL_DRIFT'}
    return [pscustomobject][ordered]@{Marker='UID0003YU_V6_SHARED_REGRESSION_PASSED';Count=5;Labels=$labels;ResultSHA256=(Get-UID0003YUInlineSHA256V5 ([Text.Encoding]::UTF8.GetBytes(($results|ConvertTo-Json -Depth 12 -Compress))));Results=@($results)}
}
function Import-UID0003YUProductionPackageV6([string]$ReportPath){
    $callerEngine=$ExecutionContext.InvokeCommand
    $hashBytes={param([byte[]]$Bytes)$sha=[Security.Cryptography.SHA256]::Create();try{return([BitConverter]::ToString($sha.ComputeHash($Bytes))).Replace('-','')}finally{$sha.Dispose()}}.GetNewClosure()
    $hashText={param([string]$Text)return &$hashBytes ([Text.Encoding]::UTF8.GetBytes($Text))}.GetNewClosure()
    $commandFingerprint={
        param($Command)
        if($null-eq$Command){return '<missing>'}
        $implementation=if($null-ne$Command.ImplementingType){$Command.ImplementingType.AssemblyQualifiedName}else{''}
        $modulePath=if($null-ne$Command.Module){[string]$Command.Module.Path}else{''}
        $definition=if($Command.CommandType-eq[Management.Automation.CommandTypes]::Function){[string]$Command.Definition}else{''}
        return "$($Command.Name)|$($Command.CommandType)|$implementation|$($Command.ModuleName)|$modulePath|$(&$hashText $definition)"
    }.GetNewClosure()
    $requiredCallerCommands=@(
        @('Add-Type','Microsoft.PowerShell.Commands.AddTypeCommand','Microsoft.PowerShell.Utility'),
        @('Get-Command','Microsoft.PowerShell.Commands.GetCommandCommand','Microsoft.PowerShell.Core'),
        @('Get-Variable','Microsoft.PowerShell.Commands.GetVariableCommand','Microsoft.PowerShell.Utility'),
        @('Set-Variable','Microsoft.PowerShell.Commands.SetVariableCommand','Microsoft.PowerShell.Utility')
    )
    $callerCommandReceipts=@{}
    foreach($spec in $requiredCallerCommands){
        $command=$callerEngine.GetCommand([string]$spec[0],[Management.Automation.CommandTypes]::All)
        if($null-eq$command-or$command.CommandType-ne[Management.Automation.CommandTypes]::Cmdlet-or$null-eq$command.ImplementingType-or$command.ImplementingType.FullName-cne[string]$spec[1]-or$command.ModuleName-cne[string]$spec[2]){throw "V6_CALLER_COMMAND_SHADOWED:$($spec[0])"}
        $callerCommandReceipts[[string]$spec[0]]=&$commandFingerprint $command
    }
    $resolved=[IO.Path]::GetFullPath($ReportPath)
    if(-not[IO.File]::Exists($resolved)){throw 'V6_REPORT_NOT_FOUND'}
    $bytes=[IO.File]::ReadAllBytes($resolved);$text=[Text.Encoding]::UTF8.GetString($bytes)
    if($text.IndexOf("`r",[StringComparison]::Ordinal)-ge0-or$text.IndexOf([char]0)-ge0-or-not$text.EndsWith("`n",[StringComparison]::Ordinal)){throw 'V6_REPORT_ENCODING_OR_EOL_DRIFT'}
    $markerCount=[regex]::Matches($text,'(?m)^READY_FOR_SUPERVISOR_GATE1_REVIEW$').Count;if($markerCount-ne1){throw "V6_TERMINAL_MARKER_CARDINALITY:$markerCount"}
    $matches=[regex]::Matches($text,'(?ms)^```powershell\r?\n(?<body>.*?)^```\s*$')
    $functionText=@{};$functionBody=@{};$externalNames=[Collections.Generic.HashSet[string]]::new([StringComparer]::OrdinalIgnoreCase);$definitionCount=0
    foreach($match in $matches){
        $tokens=$null;$errors=$null;$ast=[Management.Automation.Language.Parser]::ParseInput($match.Groups['body'].Value,[ref]$tokens,[ref]$errors)
        if($errors.Count){throw "V6_DEFINITION_PARSE:$($errors[0].Message)"}
        foreach($statement in $ast.EndBlock.Statements){
            if($statement-is[Management.Automation.Language.FunctionDefinitionAst]){
                $definitionCount++;$body=[string]$statement.Body.Extent.Text;$body=$body.Substring(1,$body.Length-2)
                $functionText[$statement.Name]=[string]$statement.Extent.Text;$functionBody[$statement.Name]=$body
            }
        }
    }
    foreach($required in @('Initialize-UID0003YUProductionAuthorityV5','Test-UID0003YUPreEffectProductionV5','Invoke-UID0003YUFinalLiveTransaction','New-UID0003YUProductionContextV5','New-UID0003YUSharedContextV5','Invoke-UID0003YUProductionGraphV5','Invoke-UID0003YUDurableCoordinatorV4','Invoke-UID0003YUFinalIsolatedSuiteV4','Invoke-UID0003YUSharedRegressionV6','Import-UID0003YUProductionPackageV6')){if(-not$functionText.ContainsKey($required)){throw "V6_DEFINITION_INVENTORY_MISSING:$required"}}
    $callerFunctionHashes=@{}
    foreach($name in $functionBody.Keys){
        $expected=&$hashText ([string]$functionBody[$name]);$command=$callerEngine.GetCommand([string]$name,[Management.Automation.CommandTypes]::Function)
        if($null-eq$command-or(&$hashText ([string]$command.Definition))-cne$expected){throw "V6_CALLER_FUNCTION_DRIFT:$name"}
        $callerFunctionHashes[$name]=$expected
        $tokens=$null;$errors=$null;$ast=[Management.Automation.Language.Parser]::ParseInput([string]$functionText[$name],[ref]$tokens,[ref]$errors)
        foreach($node in $ast.FindAll({param($candidate)$candidate-is[Management.Automation.Language.CommandAst]},$true)){$commandName=$node.GetCommandName();if($commandName-and-not$functionText.ContainsKey($commandName)){$null=$externalNames.Add($commandName)}}
    }
    $null=$externalNames.Remove('Visit')
    $coreNamespace='UID0003YUPrivateCoreV6_'+[guid]::NewGuid().ToString('N');$authNamespace='UID0003YUPrivateAuthV6_'+[guid]::NewGuid().ToString('N')
    $transformedDefinitions=[Collections.Generic.List[string]]::new();$transformedExpected=@{}
    foreach($name in $functionText.Keys){
        $source=[string]$functionText[$name]
        $source=$source.Replace('namespace UID0003YUAuth',"namespace $authNamespace").Replace('UID0003YUAuth.',"$authNamespace.")
        $source=$source.Replace('namespace UID0003YU',"namespace $coreNamespace").Replace('UID0003YU.',"$coreNamespace.")
        $tokens=$null;$errors=$null;$transformedAst=[Management.Automation.Language.Parser]::ParseInput($source,[ref]$tokens,[ref]$errors);if($errors.Count){throw "V6_TRANSFORM_PARSE:${name}:$($errors[0].Message)"}
        $fn=@($transformedAst.EndBlock.Statements|Where-Object{$_-is[Management.Automation.Language.FunctionDefinitionAst]})[0];$body=[string]$fn.Body.Extent.Text;$body=$body.Substring(1,$body.Length-2)
        $transformedExpected[$name]=&$hashText $body
        $transformedDefinitions.Add([regex]::Replace($source,'^function\s+[^\s\(\{]+',("function global:{0}"-f$name),[Text.RegularExpressions.RegexOptions]::IgnoreCase))
    }
    $reportReceipt=[pscustomobject][ordered]@{Path=$resolved;SHA256=(&$hashBytes $bytes);Bytes=[long]$bytes.Length;Lines=[regex]::Matches($text,"`n").Count;FenceCount=$matches.Count;DefinitionCount=$definitionCount;SealedFunctionCount=$transformedExpected.Count;HistoricalTopLevelCommandsExecuted=0;TerminalMarkerCount=$markerCount}
    $privatePowerShell=[Management.Automation.PowerShell]::Create();$lock=[object]::new()
    try{
        $null=$privatePowerShell.AddScript(($transformedDefinitions-join"`n`n"));$loadOutput=@($privatePowerShell.Invoke());if($privatePowerShell.Streams.Error.Count){throw "V6_PRIVATE_DEFINITION_LOAD:$($privatePowerShell.Streams.Error[0].Exception.GetBaseException().Message)"};$privatePowerShell.Commands.Clear();$privatePowerShell.Streams.Error.Clear()
        $initializer=@'
param($Expected,$ReportReceipt,$CoreNamespace,$AuthNamespace,$ExternalCommandNames)
$engine=$ExecutionContext.InvokeCommand
$hashBytes={param([byte[]]$Bytes)$sha=[Security.Cryptography.SHA256]::Create();try{return([BitConverter]::ToString($sha.ComputeHash($Bytes))).Replace('-','')}finally{$sha.Dispose()}}.GetNewClosure()
$hashText={param([string]$Text)return &$hashBytes ([Text.Encoding]::UTF8.GetBytes($Text))}.GetNewClosure()
$functionMapFingerprint={param($Map)$keys=[string[]]@($Map.Keys);[Array]::Sort($keys,[StringComparer]::Ordinal);$builder=[Text.StringBuilder]::new();foreach($key in $keys){$null=$builder.Append($key).Append('=').Append([string]$Map[$key]).Append("`n")};return &$hashText $builder.ToString()}.GetNewClosure()
$commandFingerprint={param($Command)if($null-eq$Command){return '<missing>'};$implementation=if($null-ne$Command.ImplementingType){$Command.ImplementingType.AssemblyQualifiedName}else{''};$modulePath=if($null-ne$Command.Module){[string]$Command.Module.Path}else{''};$definition=if($Command.CommandType-eq[Management.Automation.CommandTypes]::Function){[string]$Command.Definition}else{''};return "$($Command.Name)|$($Command.CommandType)|$implementation|$($Command.ModuleName)|$modulePath|$(&$hashText $definition)"}.GetNewClosure()
$current=@{};foreach($name in $Expected.Keys){$command=$engine.GetCommand([string]$name,[Management.Automation.CommandTypes]::Function);if($null-eq$command){throw "V6_PRIVATE_FUNCTION_MISSING:$name"};$actual=&$hashText ([string]$command.Definition);if($actual-cne[string]$Expected[$name]){throw "V6_PRIVATE_FUNCTION_DRIFT:$name"};$current[$name]=$actual}
$commandReceipts=@{};foreach($name in @($ExternalCommandNames)){$command=$engine.GetCommand([string]$name,[Management.Automation.CommandTypes]::All);if($null-eq$command){throw "V6_PRIVATE_COMMAND_MISSING:$name"};if($command.CommandType-in@([Management.Automation.CommandTypes]::Alias,[Management.Automation.CommandTypes]::ExternalScript,[Management.Automation.CommandTypes]::Script)){throw "V6_PRIVATE_COMMAND_UNPINNED:$name"};$commandReceipts[$name]=&$commandFingerprint $command}
$initializerCommand=$engine.GetCommand('Initialize-UID0003YUProductionAuthorityV5',[Management.Automation.CommandTypes]::Function);$init=&$initializerCommand.ScriptBlock $Expected $ReportReceipt
$findType={param([string]$Name)foreach($assembly in [AppDomain]::CurrentDomain.GetAssemblies()){$type=$assembly.GetType($Name,$false,$false);if($null-ne$type){return $type}};throw "V6_PRIVATE_TYPE_MISSING:$Name"}.GetNewClosure()
$typeFingerprint={
    param([Type]$Type)
    $flags=[Reflection.BindingFlags]'Instance,Static,Public,NonPublic,DeclaredOnly';$rows=[Collections.Generic.List[string]]::new()
    foreach($field in $Type.GetFields($flags)){$rows.Add("F|$($field.Name)|$($field.FieldType.AssemblyQualifiedName)|$($field.Attributes)")}
    foreach($constructor in $Type.GetConstructors($flags)){$parameters=@($constructor.GetParameters()|ForEach-Object{$_.ParameterType.AssemblyQualifiedName})-join',';$il='';try{$body=$constructor.GetMethodBody();if($null-ne$body){$il=&$hashBytes $body.GetILAsByteArray()}}catch{};$rows.Add("C|$parameters|$($constructor.Attributes)|$($constructor.MethodImplementationFlags)|$il")}
    foreach($method in $Type.GetMethods($flags)){$parameters=@($method.GetParameters()|ForEach-Object{$_.ParameterType.AssemblyQualifiedName})-join',';$il='';try{$body=$method.GetMethodBody();if($null-ne$body){$il=&$hashBytes $body.GetILAsByteArray()}}catch{};$attributes=@($method.GetCustomAttributesData()|ForEach-Object{$_.AttributeType.AssemblyQualifiedName})-join',';$rows.Add("M|$($method.Name)|$($method.ReturnType.AssemblyQualifiedName)|$parameters|$($method.Attributes)|$($method.MethodImplementationFlags)|$attributes|$il")}
    $array=[string[]]$rows.ToArray();[Array]::Sort($array,[StringComparer]::Ordinal);$identity="$($Type.AssemblyQualifiedName)|$($Type.Module.ModuleVersionId)|$($array-join"`n")";return &$hashText $identity
}.GetNewClosure()
$typeNames=@("$CoreNamespace.StrictJson","$CoreNamespace.NativeFileTime","$CoreNamespace.NativeCommandLine","$CoreNamespace.FrozenContract","$AuthNamespace.FrozenContract","$AuthNamespace.HeldTuple")
$typeReceipts=@{};foreach($name in $typeNames){$type=&$findType $name;if($type.FullName-cne$name){throw "V6_PRIVATE_TYPE_NAME_DRIFT:$name"};$typeReceipts[$name]=&$typeFingerprint $type}
$expectedFunctionFingerprint=&$functionMapFingerprint $Expected;$launchCount=0;$sync=[object]::new()
$launcher={
    param([ValidateSet('Preflight','Production','DurableRegression','SharedRegression')][string]$Mode='Preflight')
    [Threading.Monitor]::Enter($sync)
    try{
        $drifts=[Collections.Generic.List[string]]::new();foreach($name in $Expected.Keys){$command=$engine.GetCommand([string]$name,[Management.Automation.CommandTypes]::Function);if($null-eq$command-or(&$hashText ([string]$command.Definition))-cne[string]$Expected[$name]){$drifts.Add([string]$name)}}
        if($drifts.Count){$array=[string[]]$drifts.ToArray();[Array]::Sort($array,[StringComparer]::Ordinal);throw "V6_PRIVATE_FUNCTION_DRIFT:$($array-join',')"}
        foreach($name in $commandReceipts.Keys){$command=$engine.GetCommand([string]$name,[Management.Automation.CommandTypes]::All);if((&$commandFingerprint $command)-cne[string]$commandReceipts[$name]){throw "V6_PRIVATE_COMMAND_DRIFT:$name"}}
        foreach($name in $typeReceipts.Keys){$type=&$findType $name;if((&$typeFingerprint $type)-cne[string]$typeReceipts[$name]){throw "V6_PRIVATE_TYPE_API_OR_IL_DRIFT:$name"}}
        $mapVariable=$ExecutionContext.SessionState.PSVariable.Get('UID0003YUExpectedFunctionHashesV5');if($null-eq$mapVariable-or(&$functionMapFingerprint $mapVariable.Value)-cne$expectedFunctionFingerprint){throw 'V6_PRIVATE_EXPECTED_MAP_DRIFT'}
        $launchCount++
        if($Mode-ceq'Preflight'){$command=$engine.GetCommand('Test-UID0003YUPreEffectProductionV5',[Management.Automation.CommandTypes]::Function);$pre=&$command.ScriptBlock;return [pscustomobject][ordered]@{Marker='UID0003YU_V6_HELD_PREFLIGHT_READY';LoadState=$(if($launchCount-eq1){'FIRST_LOAD'}else{'REENTRY'});LaunchCount=$launchCount;PreEffect=$pre;FunctionCount=$Expected.Count;CommandCount=$commandReceipts.Count;TypeCount=$typeReceipts.Count;FunctionFingerprint=$expectedFunctionFingerprint;TypeReceiptSHA256=(&$hashText (([string[]]@($typeReceipts.GetEnumerator()|ForEach-Object{"$($_.Key)=$($_.Value)"})|Sort-Object)-join"`n"))}
        if($Mode-ceq'Production'){$command=$engine.GetCommand('Invoke-UID0003YUFinalLiveTransaction',[Management.Automation.CommandTypes]::Function);return &$command.ScriptBlock}
        if($Mode-ceq'DurableRegression'){$command=$engine.GetCommand('Invoke-UID0003YUFinalIsolatedSuiteV4',[Management.Automation.CommandTypes]::Function);return &$command.ScriptBlock}
        $command=$engine.GetCommand('Invoke-UID0003YUSharedRegressionV6',[Management.Automation.CommandTypes]::Function);return &$command.ScriptBlock
    }finally{[Threading.Monitor]::Exit($sync)}
}.GetNewClosure()
$setItem=$engine.GetCommand('Set-Item',[Management.Automation.CommandTypes]::Cmdlet);$setVariable=$engine.GetCommand('Set-Variable',[Management.Automation.CommandTypes]::Cmdlet)
$hostile={
    param([ValidateSet('FUNCTIONS','EXPECTED_MAP','SEAL')][string]$Kind,[string[]]$Names)
    $effects=[ordered]@{TemporaryRoot=0;McpHttp=0;Process=0;Journal=0;FileMutation=0;IdaMutation=0;Save=0;Verifier=0;Restore=0;Cleanup=0};$message='';$restore=@{}
    try{
        if($Kind-ceq'FUNCTIONS'){foreach($name in $Names){$command=$engine.GetCommand($name,[Management.Automation.CommandTypes]::Function);$restore[$name]=[string]$command.Definition;&$setItem -Path ("Function:\global:$name") -Value ([scriptblock]::Create("throw 'V6_PRIVATE_SUBSTITUTE_CALLED'")) -Force}}
        elseif($Kind-ceq'EXPECTED_MAP'){&$setVariable -Scope Global -Name UID0003YUExpectedFunctionHashesV5 -Value @{} -Force}
        else{&$setVariable -Scope Global -Name UID0003YUPackageSealV5 -Value {return $true} -Force}
        try{$null=&$launcher 'Preflight'}catch{$message=$_.Exception.GetBaseException().Message}
        if([string]::IsNullOrWhiteSpace($message)){throw "V6_PRIVATE_HOSTILE_NOT_REJECTED:$Kind"}
        return [pscustomobject][ordered]@{Kind=$Kind;Code=$message;Effects=$effects}
    }finally{
        foreach($name in $restore.Keys){&$setItem -Path ("Function:\global:$name") -Value ([scriptblock]::Create([string]$restore[$name])) -Force}
        if($Kind-ceq'EXPECTED_MAP'){&$setVariable -Scope Global -Name UID0003YUExpectedFunctionHashesV5 -Value $Expected -Force}
    }
}.GetNewClosure()
$receipt=[pscustomobject][ordered]@{Marker='UID0003YU_V6_PRIVATE_PACKAGE_READY';CoreNamespace=$CoreNamespace;AuthNamespace=$AuthNamespace;FunctionCount=$Expected.Count;CommandCount=$commandReceipts.Count;TypeCount=$typeReceipts.Count;FunctionFingerprint=$expectedFunctionFingerprint;TypeReceipts=$typeReceipts;V5Initialization=$init}
return [Tuple]::Create([object]$launcher,[object]$receipt,[object]$hostile)
'@
        $null=$privatePowerShell.AddScript($initializer).AddArgument($transformedExpected).AddArgument($reportReceipt).AddArgument($coreNamespace).AddArgument($authNamespace).AddArgument([string[]]@($externalNames));$initializeOutput=@($privatePowerShell.Invoke());if($privatePowerShell.Streams.Error.Count){throw "V6_PRIVATE_INITIALIZE:$($privatePowerShell.Streams.Error[0].Exception.GetBaseException().Message)"};if($initializeOutput.Count-ne1-or$initializeOutput[0]-isnot[Tuple[object,object,object]]){throw "V6_PRIVATE_INITIALIZER_RECEIPT_DRIFT:$($initializeOutput.Count)"};$privatePowerShell.Commands.Clear();$privatePowerShell.Streams.Error.Clear()
        $privateTuple=$initializeOutput[0];$privateLauncher=$privateTuple.Item1;$privateReceipt=$privateTuple.Item2;$privateHostile=$privateTuple.Item3
        $callerExpectedFingerprint=&$hashText (([string[]]@($callerFunctionHashes.GetEnumerator()|ForEach-Object{"$($_.Key)=$($_.Value)"})|Sort-Object)-join"`n")
        $callerLauncher={
            param([ValidateSet('Preflight','Production','DurableRegression','SharedRegression')][string]$Mode='Preflight')
            [Threading.Monitor]::Enter($lock)
            try{
                foreach($spec in $requiredCallerCommands){$command=$callerEngine.GetCommand([string]$spec[0],[Management.Automation.CommandTypes]::All);if((&$commandFingerprint $command)-cne[string]$callerCommandReceipts[[string]$spec[0]]){throw "V6_CALLER_COMMAND_SHADOWED:$($spec[0])"}}
                $drifts=[Collections.Generic.List[string]]::new();foreach($name in $callerFunctionHashes.Keys){$command=$callerEngine.GetCommand([string]$name,[Management.Automation.CommandTypes]::Function);if($null-eq$command-or(&$hashText ([string]$command.Definition))-cne[string]$callerFunctionHashes[$name]){$drifts.Add([string]$name)}}
                if($drifts.Count){$array=[string[]]$drifts.ToArray();[Array]::Sort($array,[StringComparer]::Ordinal);throw "V6_CALLER_FUNCTION_DRIFT:$($array-join',')"}
                if($null-ne$ExecutionContext.SessionState.PSVariable.Get('UID0003YUExpectedFunctionHashesV6')){throw 'V6_CALLER_EXPECTED_MAP_SHADOWED'}
                $privatePowerShell.Commands.Clear();$privatePowerShell.Streams.Error.Clear();$invoke='param($Held,[string]$Mode) & $Held $Mode';$null=$privatePowerShell.AddScript($invoke).AddArgument($privateLauncher).AddArgument($Mode);$output=@($privatePowerShell.Invoke());if($privatePowerShell.Streams.Error.Count){throw $privatePowerShell.Streams.Error[0].Exception.GetBaseException()};return $output
            }finally{[Threading.Monitor]::Exit($lock)}
        }.GetNewClosure()
        $hostileLauncher={param([string]$Kind,[string[]]$Names)[Threading.Monitor]::Enter($lock);try{$privatePowerShell.Commands.Clear();$privatePowerShell.Streams.Error.Clear();$null=$privatePowerShell.AddScript('param($Held,$Kind,$Names) & $Held $Kind $Names').AddArgument($privateHostile).AddArgument($Kind).AddArgument($Names);$output=@($privatePowerShell.Invoke());if($privatePowerShell.Streams.Error.Count){throw $privatePowerShell.Streams.Error[0].Exception.GetBaseException()};return $output}finally{[Threading.Monitor]::Exit($lock)}}.GetNewClosure()
        $receipt=[pscustomobject][ordered]@{Marker='UID0003YU_V6_HELD_PACKAGE_READY';Report=$reportReceipt;CoreNamespace=$coreNamespace;AuthNamespace=$authNamespace;CallerFunctionCount=$callerFunctionHashes.Count;CallerFunctionFingerprint=$callerExpectedFingerprint;Private=$privateReceipt}
        return [Tuple]::Create([object]$callerLauncher,[object]$receipt,[object]$hostileLauncher)
    }catch{$privatePowerShell.Dispose();throw}
}
function Invoke-UID0003YUAuthorityHostileSuiteV6([string]$ReportPath){
    $engine=$ExecutionContext.InvokeCommand;$setItem=$engine.GetCommand('Set-Item',[Management.Automation.CommandTypes]::Cmdlet);$removeItem=$engine.GetCommand('Remove-Item',[Management.Automation.CommandTypes]::Cmdlet);$setVariable=$engine.GetCommand('Set-Variable',[Management.Automation.CommandTypes]::Cmdlet);$removeVariable=$engine.GetCommand('Remove-Variable',[Management.Automation.CommandTypes]::Cmdlet);$addType=$engine.GetCommand('Add-Type',[Management.Automation.CommandTypes]::Cmdlet)
    $importer=$engine.GetCommand('Import-UID0003YUProductionPackageV6',[Management.Automation.CommandTypes]::Function).ScriptBlock
    if(-not('UID0003YU.NativeCommandLine'-as[type])){&$addType -TypeDefinition 'namespace UID0003YU { public static class NativeCommandLine { public static string[] Parse(string value){ return new string[]{"CALLER_FORGED"}; } } public sealed class FrozenContract { } public static class StrictJson { public static void AssertNoDuplicateMembers(string value){} } public static class NativeFileTime { public static string GetFileIdentity(object value){ return "CALLER_FORGED"; } } } namespace UID0003YUAuth { public sealed class FrozenContract { } public sealed class HeldTuple { } }'}
    $package=&$importer $ReportPath;$launcher=$package.Item1;$receipt=$package.Item2;$privateHostile=$package.Item3;$results=[Collections.Generic.List[object]]::new()
    $zero={param([string]$Label,[string]$Code)$effects=[ordered]@{TemporaryRoot=0;McpHttp=0;Process=0;Journal=0;FileMutation=0;IdaMutation=0;Save=0;Verifier=0;Restore=0;Cleanup=0};$results.Add([pscustomobject][ordered]@{Label=$Label;Code=$Code;Effects=$effects})}.GetNewClosure()
    if($receipt.CoreNamespace-like'UID0003YU.*'-or$receipt.AuthNamespace-like'UID0003YUAuth.*'){throw 'V6_PRIVATE_NAMESPACE_NOT_UNIQUE'}
    if([string[]][UID0003YU.NativeCommandLine]::Parse('x')-notcontains'CALLER_FORGED'){throw 'V6_PRELOAD_FIXTURE_NOT_ACTIVE'}
    &$zero 'V6_PRELOADED_SAME_NAME_TYPES_IGNORED' "PRIVATE=$($receipt.CoreNamespace)|$($receipt.AuthNamespace)"
    &$zero 'V6_PRIVATE_ASSEMBLY_API_SEALED' ([string]$receipt.Private.TypeReceipts.Count)
    &$zero 'V6_PRIVATE_METHOD_IL_SEALED' ([string]$receipt.Private.TypeReceipts.Values.Count)
    $first=@(&$launcher 'Preflight')[0];$second=@(&$launcher 'Preflight')[0];if($first.LoadState-cne'FIRST_LOAD'-or$second.LoadState-cne'REENTRY'){throw "V6_LOAD_REENTRY_DRIFT:$($first.LoadState)/$($second.LoadState)"};&$zero 'V6_CLEAN_FIRST_LOAD' $first.Marker;&$zero 'V6_CLEAN_REENTRY' $second.Marker
    foreach($name in @('Add-Type','Get-Command','Get-Variable','Set-Variable')){
        $original=$engine.GetCommand($name,[Management.Automation.CommandTypes]::Cmdlet);try{&$setItem -Path ("Function:\global:$name") -Value {throw 'CALLER_AMBIENT_COMMAND_EXECUTED'} -Force;$message='';try{$null=&$importer $ReportPath}catch{$message=$_.Exception.GetBaseException().Message};if($message-cne"V6_CALLER_COMMAND_SHADOWED:$name"){throw "V6_CALLER_COMMAND_WRONG_CODE:${name}:$message"};&$zero "V6_AMBIENT_$($name.Replace('-','_').ToUpperInvariant())" $message}finally{&$removeItem -Path ("Function:\global:$name") -Force -ErrorAction SilentlyContinue}
    }
    foreach($name in @('Get-UID0003YUTextSHA256V4','Invoke-UID0003YUFinalLiveTransaction')){
        $original=[string]$engine.GetCommand($name,[Management.Automation.CommandTypes]::Function).Definition;try{&$setItem -Path ("Function:\global:$name") -Value {return 'CALLER_FORGED'} -Force;$message='';try{$null=&$launcher 'Preflight'}catch{$message=$_.Exception.GetBaseException().Message};if($message-cne"V6_CALLER_FUNCTION_DRIFT:$name"){throw "V6_CALLER_FUNCTION_WRONG_CODE:${name}:$message"};&$zero "V6_CALLER_FUNCTION_$name" $message}finally{&$setItem -Path ("Function:\global:$name") -Value ([scriptblock]::Create($original)) -Force}
    }
    try{&$setVariable -Scope Global -Name UID0003YUExpectedFunctionHashesV6 -Value @{} -Force;$message='';try{$null=&$launcher 'Preflight'}catch{$message=$_.Exception.GetBaseException().Message};if($message-cne'V6_CALLER_EXPECTED_MAP_SHADOWED'){throw "V6_CALLER_MAP_WRONG_CODE:$message"};&$zero 'V6_CALLER_EXPECTED_MAP_SHADOW' $message}finally{&$removeVariable -Scope Global -Name UID0003YUExpectedFunctionHashesV6 -Force -ErrorAction SilentlyContinue}
    $combined=@('Get-UID0003YUTextSHA256V4','New-UID0003YUProductionContextV5','New-UID0003YUSharedContextV5','Invoke-UID0003YUProductionGraphV5','Invoke-UID0003YUDurableCoordinatorV4');$restore=@{};try{foreach($name in $combined){$restore[$name]=[string]$engine.GetCommand($name,[Management.Automation.CommandTypes]::Function).Definition;&$setItem -Path ("Function:\global:$name") -Value {return 'CALLER_FORGED'} -Force};$message='';try{$null=&$launcher 'Preflight'}catch{$message=$_.Exception.GetBaseException().Message};$expected='V6_CALLER_FUNCTION_DRIFT:'+(([string[]]$combined|Sort-Object)-join',');if($message-cne$expected){throw "V6_COMBINED_SUBSTITUTION_WRONG_CODE:$message"};&$zero 'V6_COMBINED_HASH_FACTORY_SHARED_GRAPH_COORDINATOR' $message}finally{foreach($name in $restore.Keys){&$setItem -Path ("Function:\global:$name") -Value ([scriptblock]::Create([string]$restore[$name])) -Force}}
    $privateFunction=@(&$privateHostile 'FUNCTIONS' @('Get-UID0003YUTextSHA256V4','New-UID0003YUProductionContextV5','New-UID0003YUSharedContextV5','Invoke-UID0003YUProductionGraphV5','Invoke-UID0003YUDurableCoordinatorV4'))[0];if($privateFunction.Code-notlike'V6_PRIVATE_FUNCTION_DRIFT:*'){throw "V6_PRIVATE_FUNCTION_HOSTILE_WRONG_CODE:$($privateFunction.Code)"};$results.Add([pscustomobject][ordered]@{Label='V6_PRIVATE_COMBINED_SUBSTITUTION';Code=$privateFunction.Code;Effects=$privateFunction.Effects})
    $privateMap=@(&$privateHostile 'EXPECTED_MAP' @())[0];if($privateMap.Code-cne'V6_PRIVATE_EXPECTED_MAP_DRIFT'){throw "V6_PRIVATE_MAP_HOSTILE_WRONG_CODE:$($privateMap.Code)"};$results.Add([pscustomobject][ordered]@{Label='V6_PRIVATE_EXPECTED_MAP_SUBSTITUTION';Code=$privateMap.Code;Effects=$privateMap.Effects})
    $durable=@(&$launcher 'DurableRegression')[0];if($durable.Marker-cne'UID0003YU_V4_DURABLE_SHARED_PATH_SUITE_PASSED'-or$durable.Count-ne13){throw 'V6_DURABLE_REGRESSION_DRIFT'}
    $shared=@(&$launcher 'SharedRegression')[0];if($shared.Marker-cne'UID0003YU_V6_SHARED_REGRESSION_PASSED'-or$shared.Count-ne5){throw 'V6_SHARED_REGRESSION_DRIFT'}
    $labels=@($results|ForEach-Object{$_.Label});if($labels.Count-ne15-or@($labels|Sort-Object -Unique).Count-ne15){throw "V6_HOSTILE_LABEL_DRIFT:$($labels.Count)"}
    $json=$results|ConvertTo-Json -Depth 12 -Compress;return [pscustomobject][ordered]@{Marker='UID0003YU_V6_NON_SUBSTITUTABLE_AUTHORITY_SUITE_PASSED';Count=$results.Count;Labels=$labels;ResultSHA256=((&$engine.GetCommand('Get-UID0003YUInlineSHA256V5',[Management.Automation.CommandTypes]::Function).ScriptBlock) ([Text.Encoding]::UTF8.GetBytes($json)));FirstLoad=$first;Reentry=$second;Durable=$durable;Shared=$shared;Package=$receipt;Results=@($results)}
}
# UID0003YU V6 NON-SUBSTITUTABLE PRIVATE PRODUCTION AUTHORITY END
~~~

## Removed Block R018

- SHA256: `AC0E1CC999DF6CBE5958157DC889ACF51F6FE219E4123D68AD330B294A3FB9D4`
- Language: `powershell`
- Bytes: `35893`
- First recovered timestamp: `2026-08-09T06:51:08.491Z`
- Session provenance: rollout-2026-08-07T21-28-25-019fdefc-4eb3-7c02-8dc4-19f7da3eee30.jsonl line 199218 (2026-08-09T06:51:08.491Z); rollout-2026-08-07T21-28-25-019fdefc-4eb3-7c02-8dc4-19f7da3eee30.jsonl line 199219 (2026-08-09T06:51:08.650Z)

~~~powershell
# UID0003YU V7 NON-RETURNED SEALED SUPERVISOR AUTHORITY START
function Get-UID0003YUObservedStateV7([string]$ReportPath,[string]$CanonicalPath,[string]$AuthorityRoot,$SnapshotMethod,$Handle){
    $hashFile={param([string]$Path,[bool]$FullHash)$full=[IO.Path]::GetFullPath($Path);if(-not[IO.File]::Exists($full)){return "ABSENT|$full"};$info=[IO.FileInfo]::new($full);$digest='NOT_MEASURED';if($FullHash){$stream=[IO.File]::Open($full,[IO.FileMode]::Open,[IO.FileAccess]::Read,([IO.FileShare]::ReadWrite -bor [IO.FileShare]::Delete));$sha=[Security.Cryptography.SHA256]::Create();try{$digest=([BitConverter]::ToString($sha.ComputeHash($stream))).Replace('-','')}finally{$sha.Dispose();$stream.Dispose()}};return "$full|$($info.Length)|$($info.CreationTimeUtc.Ticks)|$($info.LastWriteTimeUtc.Ticks)|$digest"}.GetNewClosure()
    $treeRows=[Collections.Generic.List[string]]::new();if([IO.Directory]::Exists($AuthorityRoot)){$paths=[string[]]@([IO.Directory]::EnumerateFileSystemEntries($AuthorityRoot,'*',[IO.SearchOption]::AllDirectories));[Array]::Sort($paths,[StringComparer]::OrdinalIgnoreCase);foreach($path in $paths){if([IO.Directory]::Exists($path)){$treeRows.Add("D|$([IO.Path]::GetFullPath($path))")}else{$treeRows.Add("F|$(&$hashFile $path $true)")}}}
    $processRows=[Collections.Generic.List[string]]::new();foreach($process in [Diagnostics.Process]::GetProcesses()){try{$name=[string]$process.ProcessName;if($process.Id-eq[Diagnostics.Process]::GetCurrentProcess().Id-or$name-like'ida*'-or$name-like'python*'-or$name-like'powershell*'-or$name-like'pwsh*'){$start=0L;try{$start=$process.StartTime.ToUniversalTime().Ticks}catch{};$processRows.Add("$($process.Id)|$start|$name|$($process.SessionId)")}}finally{$process.Dispose()}};$processArray=[string[]]$processRows.ToArray();[Array]::Sort($processArray,[StringComparer]::Ordinal)
    $listenerRows=[Collections.Generic.List[string]]::new();$socketRows=[Collections.Generic.List[string]]::new();$network=[Net.NetworkInformation.IPGlobalProperties]::GetIPGlobalProperties();foreach($endpoint in $network.GetActiveTcpListeners()){if($endpoint.Port-eq13337){$listenerRows.Add("$($endpoint.Address):$($endpoint.Port)")}};foreach($connection in $network.GetActiveTcpConnections()){if($connection.LocalEndPoint.Port-eq13337-or$connection.RemoteEndPoint.Port-eq13337){$socketRows.Add("$($connection.LocalEndPoint)|$($connection.RemoteEndPoint)|$($connection.State)")}};$listenerArray=[string[]]$listenerRows.ToArray();$socketArray=[string[]]$socketRows.ToArray();[Array]::Sort($listenerArray,[StringComparer]::Ordinal);[Array]::Sort($socketArray,[StringComparer]::Ordinal)
    $runspace=[Management.Automation.Runspaces.Runspace]::DefaultRunspace;$session=if($null-eq$runspace){'NO_DEFAULT_RUNSPACE'}else{"$($runspace.InstanceId)|$($runspace.RunspaceStateInfo.State)|$($runspace.Availability)"}
    $counters=$SnapshotMethod.Invoke($null,[object[]]@($Handle))
    return [pscustomobject][ordered]@{Report=(&$hashFile $ReportPath $true);Canonical=(&$hashFile $CanonicalPath $false);AuthorityTree=([string[]]$treeRows.ToArray()-join"`n");Processes=($processArray-join"`n");Session=$session;Sockets=($socketArray-join"`n");Listeners=($listenerArray-join"`n");Workers=(@($processArray|Where-Object{$_-match'\|(ida|python)'})-join"`n");Counters=$counters}
}
function Import-UID0003YUProductionPackageV7([string]$ReportPath,$SupervisorAuthority){
    $engine=$ExecutionContext.InvokeCommand
    $getCommand=$engine.GetCommand('Get-Command',[Management.Automation.CommandTypes]::Cmdlet);$addType=$engine.GetCommand('Add-Type',[Management.Automation.CommandTypes]::Cmdlet);$convertFromJson=$engine.GetCommand('ConvertFrom-Json',[Management.Automation.CommandTypes]::Cmdlet);$convertToJson=$engine.GetCommand('ConvertTo-Json',[Management.Automation.CommandTypes]::Cmdlet)
    foreach($row in @(@($getCommand,'Microsoft.PowerShell.Commands.GetCommandCommand'),@($addType,'Microsoft.PowerShell.Commands.AddTypeCommand'),@($convertFromJson,'Microsoft.PowerShell.Commands.ConvertFromJsonCommand'),@($convertToJson,'Microsoft.PowerShell.Commands.ConvertToJsonCommand'))){if($null-eq$row[0]-or$row[0].CommandType-ne[Management.Automation.CommandTypes]::Cmdlet-or$row[0].ImplementingType.FullName-cne[string]$row[1]){throw 'V7_SUPERVISOR_COMMAND_AUTHORITY_DRIFT'}}
    $hashBytes={param([byte[]]$Bytes)$sha=[Security.Cryptography.SHA256]::Create();try{return([BitConverter]::ToString($sha.ComputeHash($Bytes))).Replace('-','')}finally{$sha.Dispose()}}.GetNewClosure();$hashText={param([string]$Text)return &$hashBytes ([Text.Encoding]::UTF8.GetBytes($Text))}.GetNewClosure()
    $resolved=[IO.Path]::GetFullPath($ReportPath);if(-not[IO.File]::Exists($resolved)){throw 'V7_REPORT_NOT_FOUND'};$reportBytes=[IO.File]::ReadAllBytes($resolved);$reportSHA=&$hashBytes $reportBytes
    $expectedAuthorityKeys=[string[]]@('AttemptId','ExternalAuthorityPin','RuntimeAttestationJson','RuntimeAttestationSHA256');$actualAuthorityKeys=[string[]]@($SupervisorAuthority.PSObject.Properties.Name);[Array]::Sort($expectedAuthorityKeys,[StringComparer]::Ordinal);[Array]::Sort($actualAuthorityKeys,[StringComparer]::Ordinal);if($actualAuthorityKeys.Count-ne$expectedAuthorityKeys.Count-or([string]::Join('|',$actualAuthorityKeys))-cne([string]::Join('|',$expectedAuthorityKeys))){throw 'V7_SUPERVISOR_AUTHORITY_KEYS'}
    $attempt=[string]$SupervisorAuthority.AttemptId;if($attempt-cnotmatch'^[0-9a-f]{32}$'){throw 'V7_SUPERVISOR_ATTEMPT_ID_DRIFT'}
    $runtimeJson=[string]$SupervisorAuthority.RuntimeAttestationJson;if((&$hashText $runtimeJson)-cne[string]$SupervisorAuthority.RuntimeAttestationSHA256){throw 'V7_SUPERVISOR_RUNTIME_ATTESTATION_DIGEST_DRIFT'};$runtime=&$convertFromJson.ScriptBlock -InputObject $runtimeJson
    $expectedRuntimeKeys=[string[]]@('CanonicalPath','ImplementationManifestJson','ImplementationManifestSHA256');$actualRuntimeKeys=[string[]]@($runtime.PSObject.Properties.Name);[Array]::Sort($expectedRuntimeKeys,[StringComparer]::Ordinal);[Array]::Sort($actualRuntimeKeys,[StringComparer]::Ordinal);if($actualRuntimeKeys.Count-ne$expectedRuntimeKeys.Count-or([string]::Join('|',$actualRuntimeKeys))-cne([string]::Join('|',$expectedRuntimeKeys))){throw 'V7_SUPERVISOR_RUNTIME_ATTESTATION_KEYS'}
    $canonical=[IO.Path]::GetFullPath([string]$runtime.CanonicalPath);$expectedCanonical=[IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64');if(-not[StringComparer]::OrdinalIgnoreCase.Equals($canonical,$expectedCanonical)-or-not[IO.File]::Exists($canonical)){throw 'V7_SUPERVISOR_CANONICAL_DRIFT'}
    $manifestJson=[string]$runtime.ImplementationManifestJson;$implementationSHA=&$hashText $manifestJson;if($implementationSHA-cne[string]$runtime.ImplementationManifestSHA256){throw 'V7_SUPERVISOR_IMPLEMENTATION_MANIFEST_DRIFT'}
    $pin=$SupervisorAuthority.ExternalAuthorityPin;$expectedPinKeys=[string[]]@('RootFileIdentity','RootPath','RootSHA256');$actualPinKeys=[string[]]@($pin.PSObject.Properties.Name);[Array]::Sort($expectedPinKeys,[StringComparer]::Ordinal);[Array]::Sort($actualPinKeys,[StringComparer]::Ordinal);if($actualPinKeys.Count-ne$expectedPinKeys.Count-or([string]::Join('|',$actualPinKeys))-cne([string]::Join('|',$expectedPinKeys))){throw 'V7_SUPERVISOR_ROOT_PIN_KEYS'}
    $rootPath=[IO.Path]::GetFullPath([string]$pin.RootPath);if(-not[IO.File]::Exists($rootPath)){throw 'V7_SUPERVISOR_ROOT_MISSING'};$rootBytes=[IO.File]::ReadAllBytes($rootPath);if((&$hashBytes $rootBytes)-cne[string]$pin.RootSHA256-or[string]::IsNullOrWhiteSpace([string]$pin.RootFileIdentity)){throw 'V7_SUPERVISOR_ROOT_PIN_DRIFT'}
    $backup=[IO.Path]::GetFullPath((Join-Path ([IO.Path]::GetDirectoryName($rootPath)) ("UID0003YU-$attempt.B0")));if([StringComparer]::OrdinalIgnoreCase.Equals($backup,$canonical)){throw 'V7_SUPERVISOR_B0_COLLISION'}
    $frozenPin=[pscustomobject][ordered]@{RootFileIdentity=[string]$pin.RootFileIdentity;RootPath=$rootPath;RootSHA256=[string]$pin.RootSHA256};$binding=[pscustomobject][ordered]@{BackupPath=$backup;CanonicalPath=$canonical;ExternalAuthorityPin=$frozenPin;ImplementationContractSHA256=$implementationSHA}
    $authorityRecord=[pscustomobject][ordered]@{AttemptId=$attempt;BackupPath=$backup;CanonicalPath=$canonical;ExternalAuthorityPin=$frozenPin;ImplementationContractSHA256=$implementationSHA;RuntimeAttestationSHA256=[string]$SupervisorAuthority.RuntimeAttestationSHA256};$authorityJson=&$convertToJson.ScriptBlock -InputObject $authorityRecord -Depth 8 -Compress;$authorityDigest=&$hashText ([string]$authorityJson)
    $v6Importer=$engine.GetCommand('Import-UID0003YUProductionPackageV6',[Management.Automation.CommandTypes]::Function);if($null-eq$v6Importer){throw 'V7_V6_IMPORTER_MISSING'};$v6Package=&$v6Importer.ScriptBlock $resolved;$privateLauncher=$v6Package.Item1
    $boundaryNamespace='UID0003YUSealedBoundaryV7_'+[guid]::NewGuid().ToString('N');$source=@"
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Security.Cryptography;
using System.Text;
using System.Management.Automation;
namespace $boundaryNamespace {
public sealed class HeldHandle { internal readonly Guid Id; internal HeldHandle(Guid id){Id=id;} }
public sealed class ProvisionTicket { internal readonly Guid Id; internal readonly string AuthorityDigest; internal readonly Guid Nonce; internal ProvisionTicket(Guid id,string digest){Id=id;AuthorityDigest=digest;Nonce=Guid.NewGuid();} }
public sealed class CounterReceipt { public readonly long BoundaryCalls,PrivateCalls,ProvisionAttempts,ProductionAttempts,McpRequests,IdbOpen,FileMutation,IdaMutation,Save,Restore,Journal,Process,Session,Socket,Listener,Worker; internal CounterReceipt(State s){BoundaryCalls=s.BoundaryCalls;PrivateCalls=s.PrivateCalls;ProvisionAttempts=s.ProvisionAttempts;ProductionAttempts=s.ProductionAttempts;McpRequests=s.McpRequests;IdbOpen=s.IdbOpen;FileMutation=s.FileMutation;IdaMutation=s.IdaMutation;Save=s.Save;Restore=s.Restore;Journal=s.Journal;Process=s.Process;Session=s.Session;Socket=s.Socket;Listener=s.Listener;Worker=s.Worker;} }
internal sealed class State {
 internal readonly object Gate=new object(); internal readonly ScriptBlock Launcher; internal readonly PSObject Binding; internal readonly string ReportPath,ReportSHA256,AuthorityDigest,Seal; internal readonly int GateIdentity,LauncherIdentity,BindingIdentity; internal readonly ProvisionTicket Ticket; internal bool Provisioned; internal long BoundaryCalls,PrivateCalls,ProvisionAttempts,ProductionAttempts,McpRequests,IdbOpen,FileMutation,IdaMutation,Save,Restore,Journal,Process,Session,Socket,Listener,Worker;
 internal State(Guid id,ScriptBlock launcher,object binding,string reportPath,string reportSHA,string authorityDigest){Launcher=launcher;Binding=Boundary.CloneBinding(binding);ReportPath=reportPath;ReportSHA256=reportSHA;AuthorityDigest=authorityDigest;Ticket=new ProvisionTicket(id,authorityDigest);GateIdentity=RuntimeHelpers.GetHashCode(Gate);LauncherIdentity=RuntimeHelpers.GetHashCode(Launcher);BindingIdentity=RuntimeHelpers.GetHashCode(Binding);Seal=Boundary.Seal(this);}
}
public static class Boundary {
 static readonly object RegistryGate=new object(); static readonly Dictionary<Guid,State> States=new Dictionary<Guid,State>(); static int Established;
 static string Read(PSObject value,string name){PSPropertyInfo p=value.Properties[name];if(p==null||p.Value==null)throw new InvalidOperationException("V7_BOUNDARY_BINDING_FIELD:"+name);return Convert.ToString(p.Value,System.Globalization.CultureInfo.InvariantCulture);}
 internal static PSObject CloneBinding(object source){PSObject input=PSObject.AsPSObject(source);PSObject pin=PSObject.AsPSObject(input.Properties["ExternalAuthorityPin"].Value);PSObject frozenPin=new PSObject();frozenPin.Properties.Add(new PSNoteProperty("RootFileIdentity",Read(pin,"RootFileIdentity")));frozenPin.Properties.Add(new PSNoteProperty("RootPath",Path.GetFullPath(Read(pin,"RootPath"))));frozenPin.Properties.Add(new PSNoteProperty("RootSHA256",Read(pin,"RootSHA256")));PSObject frozen=new PSObject();frozen.Properties.Add(new PSNoteProperty("BackupPath",Path.GetFullPath(Read(input,"BackupPath"))));frozen.Properties.Add(new PSNoteProperty("CanonicalPath",Path.GetFullPath(Read(input,"CanonicalPath"))));frozen.Properties.Add(new PSNoteProperty("ExternalAuthorityPin",frozenPin));frozen.Properties.Add(new PSNoteProperty("ImplementationContractSHA256",Read(input,"ImplementationContractSHA256")));return frozen;}
 static string Hash(byte[] bytes){using(SHA256 sha=SHA256.Create()){return BitConverter.ToString(sha.ComputeHash(bytes)).Replace("-","");}}
 static string TextHash(string value){return Hash(Encoding.UTF8.GetBytes(value??String.Empty));}
 internal static string Seal(State s){PSObject pin=PSObject.AsPSObject(s.Binding.Properties["ExternalAuthorityPin"].Value);string row=s.ReportPath+"\n"+s.ReportSHA256+"\n"+s.AuthorityDigest+"\n"+Read(s.Binding,"BackupPath")+"\n"+Read(s.Binding,"CanonicalPath")+"\n"+Read(pin,"RootFileIdentity")+"\n"+Read(pin,"RootPath")+"\n"+Read(pin,"RootSHA256")+"\n"+Read(s.Binding,"ImplementationContractSHA256")+"\n"+s.GateIdentity+"\n"+s.LauncherIdentity+"\n"+s.BindingIdentity+"\n"+TextHash(s.Launcher.ToString());return TextHash(row);}
 static State Get(HeldHandle handle){if(handle==null)throw new InvalidOperationException("V7_HELD_HANDLE_OMITTED");State s;lock(RegistryGate){if(!States.TryGetValue(handle.Id,out s))throw new InvalidOperationException("V7_HELD_HANDLE_UNKNOWN");}if(Hash(File.ReadAllBytes(s.ReportPath))!=s.ReportSHA256)throw new InvalidOperationException("V7_REPORT_DRIFT");if(RuntimeHelpers.GetHashCode(s.Gate)!=s.GateIdentity)throw new InvalidOperationException("V7_BOUNDARY_LOCK_DRIFT");if(RuntimeHelpers.GetHashCode(s.Launcher)!=s.LauncherIdentity||TextHash(s.Launcher.ToString())==String.Empty)throw new InvalidOperationException("V7_BOUNDARY_LAUNCHER_DRIFT");if(RuntimeHelpers.GetHashCode(s.Binding)!=s.BindingIdentity||Seal(s)!=s.Seal)throw new InvalidOperationException("V7_BOUNDARY_AUTHORITY_DRIFT");return s;}
 static object Call(State s,string mode,object argument){s.PrivateCalls++;Collection<PSObject> output=s.Launcher.Invoke(new object[]{mode,argument});if(output==null||output.Count==0)return null;if(output.Count==1)return output[0].BaseObject;object[] values=new object[output.Count];for(int i=0;i<output.Count;i++)values[i]=output[i].BaseObject;return values;}
 public static object[] Establish(ScriptBlock launcher,object binding,string reportPath,string reportSHA256,string authorityDigest){if(System.Threading.Interlocked.CompareExchange(ref Established,1,0)!=0)throw new InvalidOperationException("V7_BOUNDARY_ESTABLISHMENT_CLOSED");if(launcher==null)throw new InvalidOperationException("V7_PRIVATE_LAUNCHER_OMITTED");Guid id=Guid.NewGuid();State state=new State(id,launcher,binding,Path.GetFullPath(reportPath),reportSHA256,authorityDigest);lock(RegistryGate){States.Add(id,state);}return new object[]{new HeldHandle(id),state.Ticket};}
 public static object Invoke(HeldHandle handle,string mode,object argument){State s=Get(handle);lock(s.Gate){if(Seal(s)!=s.Seal)throw new InvalidOperationException("V7_BOUNDARY_SEAL_DRIFT");s.BoundaryCalls++;if(String.Equals(mode,"Preflight",StringComparison.Ordinal)){if(argument!=null)throw new InvalidOperationException("V7_PREFLIGHT_ARGUMENT_FORBIDDEN");return Call(s,"Preflight",null);}if(String.Equals(mode,"Provision",StringComparison.Ordinal)){s.ProvisionAttempts++;if(!Object.ReferenceEquals(argument,s.Ticket))throw new InvalidOperationException("V7_PROVISION_TICKET_IDENTITY");if(s.Provisioned)throw new InvalidOperationException("V7_PRODUCTION_ALREADY_PROVISIONED");object receipt=Call(s,"Provision",s.Binding);s.Provisioned=true;return receipt;}if(String.Equals(mode,"Production",StringComparison.Ordinal)){s.ProductionAttempts++;if(argument!=null)throw new InvalidOperationException("V7_PRODUCTION_ARGUMENT_FORBIDDEN");if(!s.Provisioned)throw new InvalidOperationException("V7_PRODUCTION_NOT_PROVISIONED");return Call(s,"Production",null);}if(String.Equals(mode,"DurableRegression",StringComparison.Ordinal)||String.Equals(mode,"SharedRegression",StringComparison.Ordinal)){if(argument!=null)throw new InvalidOperationException("V7_REGRESSION_ARGUMENT_FORBIDDEN");return Call(s,mode,null);}throw new InvalidOperationException("V7_MODE_REJECTED");}}
 public static CounterReceipt Snapshot(HeldHandle handle){State s=Get(handle);lock(s.Gate){return new CounterReceipt(s);}}
}
}
"@
    &$addType.ScriptBlock -TypeDefinition $source
    $boundaryType=$null;$handleType=$null;foreach($assembly in [AppDomain]::CurrentDomain.GetAssemblies()){$candidate=$assembly.GetType("$boundaryNamespace.Boundary",$false,$false);if($null-ne$candidate){$boundaryType=$candidate;$handleType=$assembly.GetType("$boundaryNamespace.HeldHandle",$true,$false);break}};if($null-eq$boundaryType){throw 'V7_BOUNDARY_TYPE_MISSING'}
    $establish=$boundaryType.GetMethod('Establish',[Reflection.BindingFlags]'Public,Static');$invoke=$boundaryType.GetMethod('Invoke',[Reflection.BindingFlags]'Public,Static');$snapshot=$boundaryType.GetMethod('Snapshot',[Reflection.BindingFlags]'Public,Static');if($null-eq$establish-or$null-eq$invoke-or$null-eq$snapshot){throw 'V7_BOUNDARY_METHOD_MISSING'}
    $created=[object[]]$establish.Invoke($null,[object[]]@($privateLauncher,$binding,$resolved,$reportSHA,$authorityDigest));if($created.Count-ne2-or-not$handleType.IsInstanceOfType($created[0])){throw 'V7_BOUNDARY_ESTABLISHMENT_RECEIPT_DRIFT'};$handle=$created[0];$ticket=$created[1]
    $methodRows=[Collections.Generic.List[string]]::new();foreach($method in @($establish,$invoke,$snapshot)){$parameters=@($method.GetParameters()|ForEach-Object{$_.ParameterType.AssemblyQualifiedName})-join',';$body=$method.GetMethodBody();$il=if($null-eq$body){'NO_IL'}else{&$hashBytes $body.GetILAsByteArray()};$methodRows.Add("$($method.Name)|$($method.ReturnType.AssemblyQualifiedName)|$parameters|$il")};$methodArray=[string[]]$methodRows.ToArray();[Array]::Sort($methodArray,[StringComparer]::Ordinal);$boundaryReceipt=[pscustomobject][ordered]@{Marker='UID0003YU_V7_NON_RETURNED_BOUNDARY_READY';BoundaryType=$boundaryType.AssemblyQualifiedName;ModuleVersionId=[string]$boundaryType.Module.ModuleVersionId;MethodReceiptSHA256=(&$hashText ($methodArray-join"`n"));AuthorityDigest=$authorityDigest;ReportSHA256=$reportSHA;CanonicalPath=$canonical;BackupPath=$backup;ImplementationContractSHA256=$implementationSHA;ReturnedHandleFields=@($handleType.GetFields([Reflection.BindingFlags]'Instance,Public,NonPublic')|ForEach-Object{"$($_.Name)|$($_.FieldType.AssemblyQualifiedName)|$($_.Attributes)"});ReturnedScriptBlocks=0;ReturnedPowerShellObjects=0;ReturnedMaps=0;ReturnedLocks=0;ProvisionArgument='REFERENCE_IDENTITY_TICKET_ONLY'}
    return [Tuple]::Create([object]$handle,[object]$invoke,[object]$ticket,[object]$boundaryReceipt,[object]$snapshot)
}
function Invoke-UID0003YUAuthorityHostileSuiteV7([string]$ReportPath){
    $engine=$ExecutionContext.InvokeCommand;$v7Importer=$engine.GetCommand('Import-UID0003YUProductionPackageV7',[Management.Automation.CommandTypes]::Function).ScriptBlock;$observer=$engine.GetCommand('Get-UID0003YUObservedStateV7',[Management.Automation.CommandTypes]::Function).ScriptBlock;$setItem=$engine.GetCommand('Set-Item',[Management.Automation.CommandTypes]::Cmdlet);$removeItem=$engine.GetCommand('Remove-Item',[Management.Automation.CommandTypes]::Cmdlet);$convertToJson=$engine.GetCommand('ConvertTo-Json',[Management.Automation.CommandTypes]::Cmdlet)
    $hashBytes={param([byte[]]$Bytes)$sha=[Security.Cryptography.SHA256]::Create();try{return([BitConverter]::ToString($sha.ComputeHash($Bytes))).Replace('-','')}finally{$sha.Dispose()}}.GetNewClosure();$hashText={param([string]$Text)return &$hashBytes ([Text.Encoding]::UTF8.GetBytes($Text))}.GetNewClosure()
    $root=Join-Path ([IO.Path]::GetTempPath()) ("UID0003YU-V7-AUTHORITY-"+[guid]::NewGuid().ToString('N'));[IO.Directory]::CreateDirectory($root)|Out-Null;$canonical=[IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64');$initialTempEntries=[string[]]@([IO.Directory]::EnumerateFileSystemEntries([IO.Path]::GetTempPath(),'UID0003YU-V7-*',[IO.SearchOption]::TopDirectoryOnly));[Array]::Sort($initialTempEntries,[StringComparer]::OrdinalIgnoreCase)
    try{
        $privateNativeType='UID0003YU.NativeFileTime'-as[type];if($null-eq$privateNativeType){Initialize-UID0003YUPlatformV4;$privateNativeType='UID0003YU.NativeFileTime'-as[type]};$identityMethod=$privateNativeType.GetMethod('GetFileIdentity',[Reflection.BindingFlags]'Public,Static')
        $tuple={param([string]$Path)$stream=[IO.File]::Open($Path,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::None);$sha=[Security.Cryptography.SHA256]::Create();try{return [pscustomobject]@{FileIdentity=[string]$identityMethod.Invoke($null,@($stream.SafeFileHandle));SHA256=([BitConverter]::ToString($sha.ComputeHash($stream))).Replace('-','')}}finally{$sha.Dispose();$stream.Dispose()}}.GetNewClosure()
        $newAuthority={param([string]$Name,[string]$ManifestJson)$dir=Join-Path $root $Name;[IO.Directory]::CreateDirectory($dir)|Out-Null;$utf8=[Text.UTF8Encoding]::new($false);$key=New-Object byte[] 32;for($index=0;$index-lt32;$index++){$key[$index]=[byte](($index+1)+$(if($Name-ceq'B'){40}else{0}))};$authorityId=[guid]::NewGuid().ToString('N');$keyPath=Join-Path $dir 'authority.key';$anchorPath=Join-Path $dir 'authority.anchor';$journalPath=Join-Path $dir 'authority.journal';$rootPath=Join-Path $dir 'authority.root';[IO.File]::WriteAllText($keyPath,(Protect-AuthKey $key),$utf8);[IO.File]::WriteAllText($anchorPath,'{}',$utf8);[IO.File]::WriteAllBytes($journalPath,[byte[]]@());$keyTuple=&$tuple $keyPath;$anchorTuple=&$tuple $anchorPath;$journalTuple=&$tuple $journalPath;$rootObject=[ordered]@{Version=3;AuthorityId=$authorityId;KeyId=Get-AuthSHA256 $key;KeyPath=$keyPath;KeyIdentity=$keyTuple.FileIdentity;AnchorPath=$anchorPath;AnchorIdentity=$anchorTuple.FileIdentity;JournalPath=$journalPath;JournalIdentity=$journalTuple.FileIdentity};[IO.File]::WriteAllText($rootPath,(Get-AuthCanonicalJson $rootObject),$utf8);$rootTuple=&$tuple $rootPath;$anchor=[ordered]@{Version=3;AuthorityId=$authorityId;Generation=0;JournalHeadHmacSHA256='0'*64;RootSHA256=$rootTuple.SHA256;AnchorHmacSHA256=''};$anchor.AnchorHmacSHA256=Get-AuthHmac $key (Get-AuthCanonicalJson ([ordered]@{AuthorityId=$anchor.AuthorityId;Generation=$anchor.Generation;JournalHeadHmacSHA256=$anchor.JournalHeadHmacSHA256;RootSHA256=$anchor.RootSHA256;Version=$anchor.Version}));[IO.File]::WriteAllText($anchorPath,(Get-AuthCanonicalJson $anchor),$utf8);[Array]::Clear($key,0,$key.Length);$runtime=[ordered]@{CanonicalPath=$canonical;ImplementationManifestJson=$ManifestJson;ImplementationManifestSHA256=(&$hashText $ManifestJson)};$runtimeJson=Get-AuthCanonicalJson $runtime;return [pscustomobject][ordered]@{AttemptId=[guid]::NewGuid().ToString('N');ExternalAuthorityPin=[pscustomobject][ordered]@{RootFileIdentity=$rootTuple.FileIdentity;RootPath=$rootPath;RootSHA256=$rootTuple.SHA256};RuntimeAttestationJson=$runtimeJson;RuntimeAttestationSHA256=(&$hashText $runtimeJson)}}.GetNewClosure()
        $manifestA=Get-AuthCanonicalJson ([ordered]@{Listener='supervisor-observed';Worker='supervisor-observed';Modules=@('report-owned-v7','runtime-attestation-read-only')});$authorityA=&$newAuthority 'A' $manifestA;$manifestB=Get-AuthCanonicalJson ([ordered]@{Listener='alternate-valid-root';Worker='alternate-valid-root';Modules=@('alternate')});$authorityB=&$newAuthority 'B' $manifestB
        $package=&$v7Importer $ReportPath $authorityA;$handle=$package.Item1;$invoke=$package.Item2;$ticket=$package.Item3;$receipt=$package.Item4;$snapshotMethod=$package.Item5;$results=[Collections.Generic.List[object]]::new();$expectedRoot=[IO.Path]::GetFullPath($root)
        $observe={return &$observer $ReportPath $canonical $expectedRoot $snapshotMethod $handle}.GetNewClosure()
        $runCase={param([string]$Label,[scriptblock]$Body)$before=&$observe;$value=&$Body;$after=&$observe;$drifts=[Collections.Generic.List[string]]::new();foreach($field in @('Report','Canonical','AuthorityTree','Processes','Session','Sockets','Listeners','Workers')){if([string]$before.$field-cne[string]$after.$field){$drifts.Add($field)}};$protected=[ordered]@{};foreach($field in @('McpRequests','IdbOpen','FileMutation','IdaMutation','Save','Restore','Journal','Process','Session','Socket','Listener','Worker')){$delta=[long]$after.Counters.$field-[long]$before.Counters.$field;$protected[$field]=$delta;if($delta-ne0){$drifts.Add("counter:$field=$delta")}};if($drifts.Count){throw "$Label|PROTECTED_EFFECT_DRIFT|$($drifts-join',')"};$marker=if($null-eq$value){'NULL'}elseif($null-ne$value.PSObject.Properties['Marker']){[string]$value.Marker}else{[string]$value};$results.Add([pscustomobject][ordered]@{Label=$Label;Code=$marker;Observed=[pscustomobject][ordered]@{BeforeReport=$before.Report;AfterReport=$after.Report;BeforeCanonical=$before.Canonical;AfterCanonical=$after.Canonical;AuthorityTreeStable=($before.AuthorityTree-ceq$after.AuthorityTree);ProcessStable=($before.Processes-ceq$after.Processes);SessionStable=($before.Session-ceq$after.Session);SocketStable=($before.Sockets-ceq$after.Sockets);ListenerStable=($before.Listeners-ceq$after.Listeners);WorkerStable=($before.Workers-ceq$after.Workers);ProtectedDelta=$protected;BoundaryCalls=([long]$after.Counters.BoundaryCalls-[long]$before.Counters.BoundaryCalls);PrivateCalls=([long]$after.Counters.PrivateCalls-[long]$before.Counters.PrivateCalls)}})}.GetNewClosure()
        $invokeHeld={param([string]$Mode,$Argument)return $invoke.Invoke($null,[object[]]@($handle,$Mode,$Argument))}.GetNewClosure()
        &$runCase 'V7_RETURNED_HANDLE_HAS_NO_DYNAMIC_MODULE' {if($handle-is[scriptblock]-or$null-ne$handle.PSObject.Properties['Module']){throw 'V7_RETURNED_DYNAMIC_MODULE_EXPOSED'};$fields=@($handle.GetType().GetFields([Reflection.BindingFlags]'Instance,Public,NonPublic'));if($fields.Count-ne1-or$fields[0].Name-cne'Id'-or-not($fields[0].Attributes-band[Reflection.FieldAttributes]::InitOnly)){throw 'V7_RETURNED_HANDLE_FIELD_DRIFT'};return [pscustomobject]@{Marker='V7_NON_RETURNED_AUTHORITY_CONFIRMED'}}
        &$runCase 'V7_CLOSURE_PRIVATE_LAUNCHER_SLOT_REPLACEMENT' {try{$handle.PSObject.Properties.Add([Management.Automation.PSNoteProperty]::new('privateLauncher',[scriptblock]::Create("return 'S2_FORGED_HELD_LAUNCHER'")));$value=&$invokeHeld 'Preflight' $null;if($value.Marker-cne'UID0003YU_V6_HELD_PREFLIGHT_READY'){throw 'V7_PRIVATE_LAUNCHER_REDIRECTED'};return [pscustomobject]@{Marker='V7_CLOSURE_PRIVATE_LAUNCHER_REJECTED'}}finally{$handle.PSObject.Properties.Remove('privateLauncher')}}
        &$runCase 'V7_PRIVATE_POWERSHELL_EXTRACTION_REPLACEMENT' {if(@($handle.GetType().GetFields([Reflection.BindingFlags]'Instance,Public,NonPublic')|Where-Object{$_.Name-like'*PowerShell*'}).Count-ne0){throw 'V7_PRIVATE_POWERSHELL_FIELD_EXPOSED'};try{$handle.PSObject.Properties.Add([Management.Automation.PSNoteProperty]::new('privatePowerShell',[Management.Automation.PowerShell]::Create()));$value=&$invokeHeld 'Preflight' $null;if($value.Marker-cne'UID0003YU_V6_HELD_PREFLIGHT_READY'){throw 'V7_PRIVATE_POWERSHELL_REDIRECTED'};return [pscustomobject]@{Marker='V7_PRIVATE_POWERSHELL_NOT_RETURNED'}}finally{if($null-ne$handle.PSObject.Properties['privatePowerShell']){$handle.privatePowerShell.Dispose()};$handle.PSObject.Properties.Remove('privatePowerShell')}}
        foreach($slot in @('callerFunctionHashes','callerCommandReceipts','requiredCallerCommands','lock')){&$runCase ("V7_RETURNED_SLOT_"+$slot.ToUpperInvariant()) {try{$handle.PSObject.Properties.Add([Management.Automation.PSNoteProperty]::new($slot,@{'forged'='forged'}));$value=&$invokeHeld 'Preflight' $null;if($value.Marker-cne'UID0003YU_V6_HELD_PREFLIGHT_READY'){throw "V7_RETURNED_SLOT_REDIRECTED:$slot"};return [pscustomobject]@{Marker="V7_RETURNED_SLOT_NOT_AUTHORITY:$slot"}}finally{$handle.PSObject.Properties.Remove($slot)}}}
        &$runCase 'V7_COHERENT_MULTI_SLOT_REPLACEMENT' {$names=@('privateLauncher','privatePowerShell','callerFunctionHashes','callerCommandReceipts','requiredCallerCommands','lock');try{foreach($name in $names){$handle.PSObject.Properties.Add([Management.Automation.PSNoteProperty]::new($name,'COHERENT_FORGED_AUTHORITY'))};$value=&$invokeHeld 'Preflight' $null;if($value.Marker-cne'UID0003YU_V6_HELD_PREFLIGHT_READY'){throw 'V7_COHERENT_MULTI_SLOT_REDIRECTED'};return [pscustomobject]@{Marker='V7_COHERENT_MULTI_SLOT_NOT_AUTHORITY'}}finally{foreach($name in $names){$handle.PSObject.Properties.Remove($name)}}}
        &$runCase 'V7_REQUIRED_COMMAND_GLOBAL_SHADOW' {$existing=$engine.GetCommand('Add-Type',[Management.Automation.CommandTypes]::Function);try{&$setItem.ScriptBlock -Path 'Function:\global:Add-Type' -Value {throw 'V7_FORGED_GLOBAL_ADD_TYPE'} -Force;$message='';try{$null=&$invokeHeld 'Preflight' $null}catch{$message=$_.Exception.GetBaseException().Message};if($message-cne'V6_CALLER_COMMAND_SHADOWED:Add-Type'){throw "V7_GLOBAL_COMMAND_WRONG_CODE:$message"};return [pscustomobject]@{Marker=$message}}finally{if($null-eq$existing){&$removeItem.ScriptBlock -Path 'Function:\Add-Type' -Force -ErrorAction SilentlyContinue}else{&$setItem.ScriptBlock -Path 'Function:\global:Add-Type' -Value ([scriptblock]::Create([string]$existing.Definition)) -Force}}}
        &$runCase 'V7_PRODUCTION_BEFORE_PROVISION' {$message='';try{$null=&$invokeHeld 'Production' $null}catch{$message=$_.Exception.GetBaseException().Message};if($message-cne'V7_PRODUCTION_NOT_PROVISIONED'){throw "V7_PREPROVISION_WRONG_CODE:$message"};return [pscustomobject]@{Marker=$message}}
        foreach($fake in @(
            [pscustomobject]@{Label='V7_ALTERNATE_B0_PROVISION';Value=[pscustomobject]@{BackupPath=(Join-Path $root 'alternate.B0')}},
            [pscustomobject]@{Label='V7_ALTERNATE_VALID_ROOT_PROVISION';Value=$authorityB.ExternalAuthorityPin},
            [pscustomobject]@{Label='V7_ARBITRARY_IMPLEMENTATION_DIGEST_PROVISION';Value=[pscustomobject]@{ImplementationContractSHA256=('D'*64)}},
            [pscustomobject]@{Label='V7_COHERENT_B0_ROOT_DIGEST_PROVISION';Value=[pscustomobject]@{BackupPath=(Join-Path $root 'coherent.B0');ExternalAuthorityPin=$authorityB.ExternalAuthorityPin;ImplementationContractSHA256=('D'*64)}}
        )){&$runCase $fake.Label {$message='';try{$null=&$invokeHeld 'Provision' $fake.Value}catch{$message=$_.Exception.GetBaseException().Message};if($message-cne'V7_PROVISION_TICKET_IDENTITY'){throw "$($fake.Label)|WRONG_CODE:$message"};return [pscustomobject]@{Marker=$message}}}
        &$runCase 'V7_ARBITRARY_IMPLEMENTATION_ATTESTATION_IMPORT' {$forgedJson=Get-AuthCanonicalJson ([ordered]@{CanonicalPath=$canonical;ImplementationManifestJson=$manifestA;ImplementationManifestSHA256=('D'*64)});$forged=[pscustomobject][ordered]@{AttemptId=[guid]::NewGuid().ToString('N');ExternalAuthorityPin=$authorityA.ExternalAuthorityPin;RuntimeAttestationJson=$forgedJson;RuntimeAttestationSHA256=(&$hashText $forgedJson)};$message='';try{$null=&$v7Importer $ReportPath $forged}catch{$message=$_.Exception.GetBaseException().Message};if($message-cne'V7_SUPERVISOR_IMPLEMENTATION_MANIFEST_DRIFT'){throw "V7_FORGED_ATTESTATION_WRONG_CODE:$message"};return [pscustomobject]@{Marker=$message}}
        $provision=$null;&$runCase 'V7_EXACT_SUPERVISOR_TICKET_PROVISION' {$script:UID0003YU_V7_ProvisionReceipt=&$invokeHeld 'Provision' $ticket;if($script:UID0003YU_V7_ProvisionReceipt.Marker-cne'UID0003YU_V6_HELD_BINDING_PROVISIONED'){throw 'V7_PROVISION_RECEIPT_DRIFT'};return [pscustomobject]@{Marker='V7_SUPERVISOR_AUTHORITY_PROVISIONED'}};$provision=$script:UID0003YU_V7_ProvisionReceipt;$script:UID0003YU_V7_ProvisionReceipt=$null
        &$runCase 'V7_REPEATED_PROVISION' {$message='';try{$null=&$invokeHeld 'Provision' $ticket}catch{$message=$_.Exception.GetBaseException().Message};if($message-cne'V7_PRODUCTION_ALREADY_PROVISIONED'){throw "V7_REPEAT_PROVISION_WRONG_CODE:$message"};return [pscustomobject]@{Marker=$message}}
        &$runCase 'V7_POST_PROVISION_ROOT_FILE_MUTATION' {$path=[string]$authorityA.ExternalAuthorityPin.RootPath;$original=[IO.File]::ReadAllBytes($path);$mtime=[IO.File]::GetLastWriteTimeUtc($path);$message='';try{[IO.File]::WriteAllBytes($path,([byte[]]($original+[byte]0x0a)));try{$null=&$invokeHeld 'Production' $null}catch{$message=$_.Exception.GetBaseException().Message};if($message-notmatch'ROOT|AUTHORITY'){throw "V7_ROOT_MUTATION_WRONG_CODE:$message"}}finally{[IO.File]::WriteAllBytes($path,$original);[IO.File]::SetLastWriteTimeUtc($path,$mtime)};return [pscustomobject]@{Marker=$message}}
        $savedAttempt=$authorityA.AttemptId;$savedPin=$authorityA.ExternalAuthorityPin;$savedRuntime=$authorityA.RuntimeAttestationJson;$savedRuntimeSHA=$authorityA.RuntimeAttestationSHA256;$boundary=$null;&$runCase 'V7_POST_PROVISION_CALLER_AUTHORITY_MUTATION' {try{$authorityA.AttemptId='f'*32;$authorityA.ExternalAuthorityPin=$authorityB.ExternalAuthorityPin;$authorityA.RuntimeAttestationJson='{}';$authorityA.RuntimeAttestationSHA256='F'*64;$script:UID0003YU_V7_BoundaryReceipt=&$invokeHeld 'Production' $null;if($script:UID0003YU_V7_BoundaryReceipt.Marker-cne'UID0003YU_V6_READ_ONLY_PRODUCTION_BOUNDARY_REACHED'-or$script:UID0003YU_V7_BoundaryReceipt.Binding.BackupPath-cne$receipt.BackupPath-or$script:UID0003YU_V7_BoundaryReceipt.Binding.ImplementationContractSHA256-cne$receipt.ImplementationContractSHA256){throw 'V7_CALLER_AUTHORITY_MUTATION_REDIRECTED'};return [pscustomobject]@{Marker='V7_FROZEN_AUTHORITY_BOUNDARY_REACHED'}}finally{$authorityA.AttemptId=$savedAttempt;$authorityA.ExternalAuthorityPin=$savedPin;$authorityA.RuntimeAttestationJson=$savedRuntime;$authorityA.RuntimeAttestationSHA256=$savedRuntimeSHA}};$boundary=$script:UID0003YU_V7_BoundaryReceipt;$script:UID0003YU_V7_BoundaryReceipt=$null
        $durable=&$invokeHeld 'DurableRegression' $null;if($durable.Marker-cne'UID0003YU_V6_DURABLE_SHARED_PATH_SUITE_PASSED'-or$durable.Count-ne13){throw 'V7_DURABLE_REGRESSION_DRIFT'};$shared=&$invokeHeld 'SharedRegression' $null;if($shared.Marker-cne'UID0003YU_V6_SHARED_REGRESSION_PASSED'-or$shared.Count-ne5){throw 'V7_SHARED_REGRESSION_DRIFT'}
        $canonicalStream=[IO.File]::Open($canonical,[IO.FileMode]::Open,[IO.FileAccess]::Read,([IO.FileShare]::ReadWrite -bor[IO.FileShare]::Delete));$canonicalHasher=[Security.Cryptography.SHA256]::Create();try{$canonicalFinalSHA=([BitConverter]::ToString($canonicalHasher.ComputeHash($canonicalStream))).Replace('-','')}finally{$canonicalHasher.Dispose();$canonicalStream.Dispose()};if($canonicalFinalSHA-cne[string]$provision.Canonical.SHA256){throw 'V7_CANONICAL_FULL_HASH_DRIFT'}
        $labels=@($results|ForEach-Object{$_.Label});if($labels.Count-ne19-or@($labels|Sort-Object -Unique).Count-ne19){throw "V7_HOSTILE_LABEL_DRIFT:$($labels.Count)"};$json=&$convertToJson.ScriptBlock -InputObject $results -Depth 12 -Compress;$resultSHA=&$hashText ([string]$json);return [pscustomobject][ordered]@{Marker='UID0003YU_V7_NON_RETURNED_AUTHORITY_SUITE_PASSED';Count=$results.Count;Labels=$labels;ResultSHA256=$resultSHA;Package=$receipt;Provision=$provision;ProductionBoundary=$boundary;Durable=$durable;Shared=$shared;CanonicalFullSHA256=$canonicalFinalSHA;Results=@($results)}
    }finally{if([IO.Directory]::Exists($root)){[IO.Directory]::Delete($root,$true)};$remaining=[string[]]@([IO.Directory]::EnumerateFileSystemEntries([IO.Path]::GetTempPath(),'UID0003YU-V7-*',[IO.SearchOption]::TopDirectoryOnly));[Array]::Sort($remaining,[StringComparer]::OrdinalIgnoreCase);if(($remaining-join'|')-cne($initialTempEntries-join'|')){throw 'V7_REPORT_OWNED_TEMP_RESIDUE'}}
}
# UID0003YU V7 NON-RETURNED SEALED SUPERVISOR AUTHORITY END
~~~

## Removed Block R019

- SHA256: `DB03521CB7CC08B3DC9E63194F8536BE2F5F37074D019B54735E4D453F7630B9`
- Language: `powershell`
- Bytes: `33265`
- First recovered timestamp: `2026-08-09T08:17:29.292Z`
- Session provenance: rollout-2026-08-07T21-28-25-019fdefc-4eb3-7c02-8dc4-19f7da3eee30.jsonl line 199630 (2026-08-09T08:17:29.292Z); rollout-2026-08-07T21-28-25-019fdefc-4eb3-7c02-8dc4-19f7da3eee30.jsonl line 199631 (2026-08-09T08:17:29.444Z)

~~~powershell
# UID0003YU FINAL V7 PROCESS-ISOLATED INTERNAL AUTHORITY START
function Import-UID0003YUProductionPackageV7 {
    [CmdletBinding()]
    param(
        [ValidateSet('Preflight','ProductionBoundary','ProductionCommit','RestartInitialize','RestartReentry','RestartDuplicate','RestartReordered')]
        [string]$Mode='Preflight'
    )
    $reportPath=[IO.Path]::GetFullPath('E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\0003YU-RankingCategoryRecordRangeCopyConstructDeep-source-quality.md')
    $canonicalPath=[IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64')
    $expectedV6Fingerprint='9766C4D8482F2607DB6E71014A2E30E3CF28B38D1F6506A85819BCD9EB01CAD4'
    $hashBytes={param([byte[]]$Bytes)$sha=[Security.Cryptography.SHA256]::Create();try{return([BitConverter]::ToString($sha.ComputeHash($Bytes))).Replace('-','')}finally{$sha.Dispose()}}.GetNewClosure()
    $hashText={param([string]$Text)return &$hashBytes ([Text.Encoding]::UTF8.GetBytes($Text))}.GetNewClosure()
    if(-not[IO.File]::Exists($reportPath)){throw 'V7_INTERNAL_REPORT_MISSING'}
    if(-not[IO.File]::Exists($canonicalPath)){throw 'V7_INTERNAL_CANONICAL_MISSING'}
    $reportBytes=[IO.File]::ReadAllBytes($reportPath);$reportText=[Text.Encoding]::UTF8.GetString($reportBytes);$reportSHA=&$hashBytes $reportBytes
    if($reportText.IndexOf("`r",[StringComparison]::Ordinal)-ge0-or$reportText.IndexOf([char]0)-ge0-or-not$reportText.EndsWith("`n",[StringComparison]::Ordinal)){throw 'V7_INTERNAL_REPORT_ENCODING_DRIFT'}
    if([regex]::Matches($reportText,'(?m)^READY_FOR_SUPERVISOR_GATE1_REVIEW$').Count-ne1){throw 'V7_INTERNAL_TERMINAL_MARKER_DRIFT'}
    $fences=[regex]::Matches($reportText,'(?ms)^```powershell\r?\n(?<body>.*?)^```\s*$');$finalDefinitions=@{}
    foreach($fence in $fences){
        $tokens=$null;$errors=$null;$ast=[Management.Automation.Language.Parser]::ParseInput($fence.Groups['body'].Value,[ref]$tokens,[ref]$errors)
        if($errors.Count){throw "V7_INTERNAL_DEFINITION_PARSE:$($errors[0].Message)"}
        foreach($statement in $ast.EndBlock.Statements){if($statement-is[Management.Automation.Language.FunctionDefinitionAst]){$finalDefinitions[$statement.Name]=[string]$statement.Extent.Text}}
    }
    if(-not$finalDefinitions.ContainsKey('Import-UID0003YUProductionPackageV6')){throw 'V7_INTERNAL_V6_IMPORTER_MISSING'}
    $fingerprint={
        param([Management.Automation.Language.FunctionDefinitionAst]$Function)
        $body=[string]$Function.Body.Extent.Text;$body=$body.Substring(1,$body.Length-2);$parameterRows=[Collections.Generic.List[string]]::new();foreach($parameter in $Function.Parameters){$parameterRows.Add([string]$parameter.Extent.Text)};$source=if($parameterRows.Count){'param('+($parameterRows.ToArray()-join',')+")`n"+$body}else{$body}
        $tokens=$null;$errors=$null;$null=[Management.Automation.Language.Parser]::ParseInput($source,[ref]$tokens,[ref]$errors);if($errors.Count){throw 'V7_INTERNAL_FINGERPRINT_PARSE'};$builder=[Text.StringBuilder]::new()
        foreach($token in $tokens){if($token.Kind-notin@([Management.Automation.Language.TokenKind]::NewLine,[Management.Automation.Language.TokenKind]::Comment,[Management.Automation.Language.TokenKind]::LineContinuation,[Management.Automation.Language.TokenKind]::EndOfInput)){$value=[string]$token.Extent.Text;$null=$builder.Append([string]$token.Kind).Append(':').Append($value.Length).Append(':').Append($value).Append('|')}}
        return &$hashText $builder.ToString()
    }.GetNewClosure()
    $tokens=$null;$errors=$null;$v6Ast=[Management.Automation.Language.Parser]::ParseInput([string]$finalDefinitions['Import-UID0003YUProductionPackageV6'],[ref]$tokens,[ref]$errors);$v6Function=@($v6Ast.EndBlock.Statements|Where-Object{$_-is[Management.Automation.Language.FunctionDefinitionAst]})[0]
    $v6Fingerprint=&$fingerprint $v6Function;if($v6Fingerprint-cne$expectedV6Fingerprint){throw 'V7_INTERNAL_V6_IMPORTER_FINGERPRINT_DRIFT'}
    $definitionNames=[string[]]@($finalDefinitions.Keys);[Array]::Sort($definitionNames,[StringComparer]::Ordinal);$definitionRows=[Collections.Generic.List[string]]::new()
    foreach($name in $definitionNames){$source=[string]$finalDefinitions[$name];$definitionRows.Add([regex]::Replace($source,'^function\s+[^\s\(\{]+',("function global:{0}"-f$name),[Text.RegularExpressions.RegexOptions]::IgnoreCase))}
    $modeLiteral=$Mode.Replace("'","''");$reportLiteral=$reportPath.Replace("'","''");$canonicalLiteral=$canonicalPath.Replace("'","''");$fingerprintLiteral=$expectedV6Fingerprint
    $tail=@"
`$ErrorActionPreference='Stop'
try {
    `$mode='$modeLiteral';`$reportPath='$reportLiteral';`$canonicalPath='$canonicalLiteral';`$expectedImporter='$fingerprintLiteral'
    `$hashBytes={param([byte[]]`$Bytes)`$sha=[Security.Cryptography.SHA256]::Create();try{return([BitConverter]::ToString(`$sha.ComputeHash(`$Bytes))).Replace('-','')}finally{`$sha.Dispose()}}.GetNewClosure()
    `$hashText={param([string]`$Text)return &`$hashBytes ([Text.Encoding]::UTF8.GetBytes(`$Text))}.GetNewClosure()
    `$tuple={param([string]`$Path,[bool]`$Exclusive)`$share=if(`$Exclusive){[IO.FileShare]::None}else{[IO.FileShare]::ReadWrite -bor[IO.FileShare]::Delete};`$stream=[IO.File]::Open(`$Path,[IO.FileMode]::Open,[IO.FileAccess]::Read,`$share);`$sha=[Security.Cryptography.SHA256]::Create();try{return [pscustomobject][ordered]@{Path=[IO.Path]::GetFullPath(`$Path);Length=[long]`$stream.Length;SHA256=([BitConverter]::ToString(`$sha.ComputeHash(`$stream))).Replace('-','');FileIdentity=[UID0003YU.NativeFileTime]::GetFileIdentity(`$stream.SafeFileHandle);CreationTimeUtcTicks=[long][UID0003YU.NativeFileTime]::GetCreationUtcTicks(`$stream.SafeFileHandle);LastWriteTimeUtcTicks=[long][UID0003YU.NativeFileTime]::GetLastWriteUtcTicks(`$stream.SafeFileHandle)}}finally{`$sha.Dispose();`$stream.Dispose()}}.GetNewClosure()
    `$pinPath={param([string]`$RootDir)return Join-Path `$RootDir 'authority.pin.json'}.GetNewClosure()
    `$newAuthority={param([string]`$RootDir)if([IO.Directory]::Exists(`$RootDir)){throw 'V7_INTERNAL_AUTHORITY_ALREADY_EXISTS'};[IO.Directory]::CreateDirectory(`$RootDir)|Out-Null;`$key=New-Object byte[] 32;`$rng=[Security.Cryptography.RandomNumberGenerator]::Create();try{`$rng.GetBytes(`$key)}finally{`$rng.Dispose()};`$utf8=[Text.UTF8Encoding]::new(`$false);`$authorityId=[guid]::NewGuid().ToString('N');`$keyPath=Join-Path `$RootDir 'authority.key';`$anchorPath=Join-Path `$RootDir 'authority.anchor';`$journalPath=Join-Path `$RootDir 'authority.journal';`$rootPath=Join-Path `$RootDir 'authority.root';[IO.File]::WriteAllText(`$keyPath,(Protect-AuthKey `$key),`$utf8);[IO.File]::WriteAllText(`$anchorPath,'{}',`$utf8);[IO.File]::WriteAllBytes(`$journalPath,[byte[]]@());`$keyTuple=&`$tuple `$keyPath `$true;`$anchorTuple=&`$tuple `$anchorPath `$true;`$journalTuple=&`$tuple `$journalPath `$true;`$rootObject=[ordered]@{Version=3;AuthorityId=`$authorityId;KeyId=Get-AuthSHA256 `$key;KeyPath=`$keyPath;KeyIdentity=`$keyTuple.FileIdentity;AnchorPath=`$anchorPath;AnchorIdentity=`$anchorTuple.FileIdentity;JournalPath=`$journalPath;JournalIdentity=`$journalTuple.FileIdentity};[IO.File]::WriteAllText(`$rootPath,(Get-AuthCanonicalJson `$rootObject),`$utf8);`$rootTuple=&`$tuple `$rootPath `$true;`$anchor=[ordered]@{Version=3;AuthorityId=`$authorityId;Generation=0;JournalHeadHmacSHA256='0'*64;RootSHA256=`$rootTuple.SHA256;AnchorHmacSHA256=''};`$anchor.AnchorHmacSHA256=Get-AuthHmac `$key (Get-AuthCanonicalJson ([ordered]@{AuthorityId=`$anchor.AuthorityId;Generation=`$anchor.Generation;JournalHeadHmacSHA256=`$anchor.JournalHeadHmacSHA256;RootSHA256=`$anchor.RootSHA256;Version=`$anchor.Version}));[IO.File]::WriteAllText(`$anchorPath,(Get-AuthCanonicalJson `$anchor),`$utf8);[Array]::Clear(`$key,0,`$key.Length);`$pin=[pscustomobject][ordered]@{RootFileIdentity=`$rootTuple.FileIdentity;RootPath=`$rootPath;RootSHA256=`$rootTuple.SHA256};[IO.File]::WriteAllText((&`$pinPath `$RootDir),(Get-AuthCanonicalJson `$pin),`$utf8);return `$pin}.GetNewClosure()
    `$readPin={param([string]`$RootDir)`$path=&`$pinPath `$RootDir;if(-not[IO.File]::Exists(`$path)){throw 'V7_INTERNAL_AUTHORITY_PIN_MISSING'};`$pin=ConvertFrom-AuthStrictJson ([IO.File]::ReadAllText(`$path,[Text.Encoding]::UTF8)) 'v7-internal-pin';Assert-UID0003YUExactKeysV3 `$pin @('RootFileIdentity','RootPath','RootSHA256') 'V7_INTERNAL_PIN';if([IO.Path]::GetFullPath([string]`$pin.RootPath)-cne[IO.Path]::GetFullPath((Join-Path `$RootDir 'authority.root'))){throw 'V7_INTERNAL_ROOT_PATH_DRIFT'};return `$pin}.GetNewClosure()
    Initialize-UID0003YUPlatformV4
    `$report=&`$tuple `$reportPath `$false;`$canonical=&`$tuple `$canonicalPath `$false
    `$v6Command=`$ExecutionContext.InvokeCommand.GetCommand('Import-UID0003YUProductionPackageV6',[Management.Automation.CommandTypes]::Function);if(`$null-eq`$v6Command){throw 'V7_INTERNAL_V6_IMPORTER_NOT_LOADED'}
    `$v6Body=[string]`$v6Command.Definition;`$tokens=`$null;`$errors=`$null;`$null=[Management.Automation.Language.Parser]::ParseInput(`$v6Body,[ref]`$tokens,[ref]`$errors);if(`$errors.Count){throw 'V7_INTERNAL_V6_IMPORTER_PARSE'};`$builder=[Text.StringBuilder]::new();foreach(`$token in `$tokens){if(`$token.Kind-notin@([Management.Automation.Language.TokenKind]::NewLine,[Management.Automation.Language.TokenKind]::Comment,[Management.Automation.Language.TokenKind]::LineContinuation,[Management.Automation.Language.TokenKind]::EndOfInput)){`$value=[string]`$token.Extent.Text;`$null=`$builder.Append([string]`$token.Kind).Append(':').Append(`$value.Length).Append(':').Append(`$value).Append('|')}};`$actualImporter=&`$hashText `$builder.ToString();if(`$actualImporter-cne`$expectedImporter){throw 'V7_INTERNAL_V6_IMPORTER_FINGERPRINT_DRIFT'}
    `$package=&`$v6Command.ScriptBlock `$reportPath;`$launcher=`$package.Item1;`$preflight=@(&`$launcher 'Preflight')[0];if(`$preflight.Marker-cne'UID0003YU_V6_HELD_PREFLIGHT_READY'){throw 'V7_INTERNAL_PREFLIGHT_DRIFT'}
    `$fixtureRoot=Join-Path ([IO.Path]::GetTempPath()) ('UID0003YU-V7-FRESH-'+`$report.SHA256.Substring(0,16));`$productionRoot=Join-Path ([IO.Path]::GetDirectoryName(`$canonicalPath) '.UID0003YU-Gate2B-Authority';`$rootDir=if(`$mode-like'Restart*'){`$fixtureRoot}else{`$productionRoot};`$implementation=&`$hashText ("UID0003YU-V7-INTERNAL`nREPORT=`$(`$report.SHA256)`nCANONICAL=`$(`$canonical.SHA256)`nIMPORTER=`$actualImporter`n")
    `$result=`$null
    if(`$mode-ceq'Preflight'){
        `$result=[pscustomobject][ordered]@{Marker='UID0003YU_V7_INTERNAL_PREFLIGHT_READY';Boundary='PROCESS_ISOLATED_NO_RETURNED_STATE';Report=`$report;Canonical=`$canonical;ImporterSHA256=`$actualImporter;RootPath=`$productionRoot;RootStatus=if([IO.File]::Exists((Join-Path `$productionRoot 'authority.root'))){'EXISTING_REVALIDATION_REQUIRED'}else{'UNINITIALIZED'};McpCalls=0;IdbOpen=0;Save=0;Restore=0;IdaMutation=0}
    }elseif(`$mode-ceq'RestartReordered'){
        if([IO.Directory]::Exists(`$fixtureRoot)){throw 'V7_RESTART_REORDER_EXPECTED_ABSENT_ROOT'};throw 'V7_FRESH_PROCESS_REORDERED_REFUSED'
    }else{
        if(`$mode-ceq'RestartInitialize'){`$pin=&`$newAuthority `$rootDir}else{`$pin=&`$readPin `$rootDir}
        `$authority=Open-UID0003YULiveAuthorityV3 `$pin
        try{
            `$records=@(Read-UID0003YULiveJournalV3 `$authority 'V7_INTERNAL_RESTART_READ')
            if(`$mode-ceq'RestartInitialize'){
                if(`$records.Count-ne0){throw 'V7_RESTART_INITIAL_STATE_DRIFT'};`$backup=Join-Path `$rootDir 'UID0003YU.B0';`$binding=[pscustomobject][ordered]@{BackupPath=`$backup;CanonicalPath=`$canonicalPath;ExternalAuthorityPin=`$pin;ImplementationContractSHA256=`$implementation};`$provision=@(&`$launcher 'Provision' `$binding)[0];`$boundary=@(&`$launcher 'Production')[0];if(`$boundary.Marker-cne'UID0003YU_V6_READ_ONLY_PRODUCTION_BOUNDARY_REACHED'){throw 'V7_RESTART_BOUNDARY_DRIFT'};`$null=Add-UID0003YULiveJournalRecordV3 `$authority 'TERMINAL' ([ordered]@{ImplementationContractSHA256=`$implementation;SaveAttemptCount=0;SaveRequestId=[long]0;SaveRequestJson='';SaveRequestSHA256='';SaveResponseSHA256='';P0=`$null;B0=`$null});`$result=[pscustomobject][ordered]@{Marker='UID0003YU_V7_FRESH_PROCESS_INITIALIZED';Sequence=@('Preflight','Provision','Boundary','Terminal');Report=`$report;Canonical=`$canonical;Root=&`$tuple `$pin.RootPath `$true;BackupPath=`$backup;ImplementationContractSHA256=`$implementation;ProvisionMarker=`$provision.Marker;BoundaryMarker=`$boundary.Marker}
            }else{
                if(`$records.Count-ne1-or`$records[0].State-cne'TERMINAL'-or`$records[0].ImplementationContractSHA256-cne`$implementation){throw 'V7_FRESH_PROCESS_DURABLE_STATE_DRIFT'};if(`$mode-ceq'RestartReentry'){`$marker='UID0003YU_V7_FRESH_PROCESS_REENTRY_REFUSED'}elseif(`$mode-ceq'RestartDuplicate'){`$marker='UID0003YU_V7_FRESH_PROCESS_DUPLICATE_REFUSED'}elseif(`$mode-in@('ProductionBoundary','ProductionCommit')){`$backup=Join-Path `$rootDir 'UID0003YU.B0';`$binding=[pscustomobject][ordered]@{BackupPath=`$backup;CanonicalPath=`$canonicalPath;ExternalAuthorityPin=`$pin;ImplementationContractSHA256=`$implementation};`$null=&`$launcher 'Provision' `$binding;`$boundary=@(&`$launcher 'Production')[0];if(`$mode-ceq'ProductionCommit'){`$live=@(&`$launcher 'Production')[0];`$result=[pscustomobject][ordered]@{Marker='UID0003YU_V7_INTERNAL_PRODUCTION_COMMIT';Boundary=`$boundary;Live=`$live}}else{`$result=[pscustomobject][ordered]@{Marker='UID0003YU_V7_INTERNAL_PRODUCTION_BOUNDARY';Boundary=`$boundary}};`$marker=`$null}else{throw 'V7_INTERNAL_MODE_DRIFT'};if(`$null-ne`$marker){`$result=[pscustomobject][ordered]@{Marker=`$marker;Sequence=@('Preflight','Provision','Boundary','Terminal');Report=`$report;Canonical=`$canonical;Root=&`$tuple `$pin.RootPath `$true;ImplementationContractSHA256=`$implementation;RecordCount=`$records.Count}}
            }
        }finally{Close-UID0003YULiveAuthorityV3 `$authority}
    }
    `$jsonCommand=`$ExecutionContext.InvokeCommand.GetCommand('ConvertTo-Json',[Management.Automation.CommandTypes]::Cmdlet);if(`$null-eq`$jsonCommand-or`$jsonCommand.ImplementingType.FullName-cne'Microsoft.PowerShell.Commands.ConvertToJsonCommand'){throw 'V7_INTERNAL_JSON_COMMAND_DRIFT'};`$json=&`$jsonCommand -InputObject `$result -Depth 16 -Compress;[Console]::Out.WriteLine('UID0003YU_V7_RESULT|'+`$json);exit 0
} catch {[Console]::Error.WriteLine('UID0003YU_V7_CHILD_FAILED|'+`$_.Exception.GetBaseException().Message);exit 97}
"@
    $payload=($definitionRows.ToArray()-join"`n`n")+"`n`n"+$tail;$payloadSHA=&$hashText $payload
    $exe=[Environment]::ExpandEnvironmentVariables('%SystemRoot%\System32\WindowsPowerShell\v1.0\powershell.exe');$arguments='-NoLogo -NoProfile -NonInteractive -Command -';$start=[Diagnostics.ProcessStartInfo]::new();$start.FileName=$exe;$start.Arguments=$arguments;$start.UseShellExecute=$false;$start.RedirectStandardInput=$true;$start.RedirectStandardOutput=$true;$start.RedirectStandardError=$true;$start.CreateNoWindow=$true
    $process=[Diagnostics.Process]::new();$process.StartInfo=$start;$timedOut=$false;$pid=0;$startTicks=0L;$stdout='';$stderr='';$exitCode=-1
    try{
        if(-not$process.Start()){throw 'V7_CHILD_START_FAILED'};$pid=$process.Id;$startTicks=$process.StartTime.ToUniversalTime().Ticks;$stdoutTask=$process.StandardOutput.ReadToEndAsync();$stderrTask=$process.StandardError.ReadToEndAsync();$process.StandardInput.Write($payload);$process.StandardInput.Close();if(-not$process.WaitForExit(240000)){$timedOut=$true;try{$process.Kill()}catch{};$null=$process.WaitForExit(30000)};$stdout=$stdoutTask.Result;$stderr=$stderrTask.Result;$exitCode=$process.ExitCode
    }finally{$process.Dispose()}
    $retired=$true;try{$probe=[Diagnostics.Process]::GetProcessById($pid);try{if($probe.StartTime.ToUniversalTime().Ticks-eq$startTicks){$retired=$false}}finally{$probe.Dispose()}}catch{}
    $postBytes=[IO.File]::ReadAllBytes($reportPath);$postSHA=&$hashBytes $postBytes
    if($timedOut){throw 'V7_CHILD_TIMEOUT'};if(-not$retired){throw 'V7_CHILD_NOT_RETIRED'};if($postSHA-cne$reportSHA){throw 'V7_REPORT_CHANGED_DURING_CHILD'};if($exitCode-ne0){throw "V7_CHILD_NONZERO:$exitCode|$stderr"}
    $line=@($stdout-split"`r?`n"|Where-Object{$_-like'UID0003YU_V7_RESULT|*'})[-1];if([string]::IsNullOrWhiteSpace($line)){throw "V7_CHILD_RESULT_MISSING|$stderr"};$json=$line.Substring('UID0003YU_V7_RESULT|'.Length);$convert=$ExecutionContext.InvokeCommand.GetCommand('ConvertFrom-Json',[Management.Automation.CommandTypes]::Cmdlet);if($null-eq$convert-or$convert.ImplementingType.FullName-cne'Microsoft.PowerShell.Commands.ConvertFromJsonCommand'){throw 'V7_CALLER_JSON_COMMAND_DRIFT'};$result=&$convert -InputObject $json
    return [pscustomobject][ordered]@{Marker='UID0003YU_V7_PROCESS_BOUNDARY_COMPLETED';Mode=$Mode;ReportSHA256=$reportSHA;ImporterSHA256=$v6Fingerprint;FenceCount=$fences.Count;DefinitionCount=$finalDefinitions.Count;PayloadSHA256=$payloadSHA;Child=[pscustomobject][ordered]@{ProcessId=$pid;StartTimeUtcTicks=$startTicks;Executable=$exe;Arguments=$arguments;TimedOut=$timedOut;ExitCode=$exitCode;Retired=$retired;StdErrEmpty=[string]::IsNullOrWhiteSpace($stderr)};Result=$result;ReturnedAuthorityObjects=0;ReturnedMethodInfo=0;ReturnedTypes=0;ReturnedDelegates=0;ReturnedScriptBlocks=0;ReturnedPowerShellObjects=0;ReturnedRegistries=0}
}
function Get-UID0003YUObservedStateV7 {
    $report=[IO.Path]::GetFullPath('E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\0003YU-RankingCategoryRecordRangeCopyConstructDeep-source-quality.md');$canonical=[IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64')
    $hashFile={param([string]$Path)if(-not[IO.File]::Exists($Path)){return '<absent>'};$stream=[IO.File]::Open($Path,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::ReadWrite -bor[IO.FileShare]::Delete);$sha=[Security.Cryptography.SHA256]::Create();try{return "$([IO.Path]::GetFullPath($Path))|$($stream.Length)|$(([BitConverter]::ToString($sha.ComputeHash($stream))).Replace('-',''))|$([IO.File]::GetCreationTimeUtc($Path).Ticks)|$([IO.File]::GetLastWriteTimeUtc($Path).Ticks)"}finally{$sha.Dispose();$stream.Dispose()}}.GetNewClosure()
    $reportTuple=&$hashFile $report;$canonicalTuple=&$hashFile $canonical;$treeRows=[Collections.Generic.List[string]]::new();foreach($root in @((Join-Path ([IO.Path]::GetTempPath()) 'UID0003YU-V7-FRESH-*'),(Join-Path ([IO.Path]::GetDirectoryName($canonical) '.UID0003YU-Gate2B-Authority')))){foreach($path in @([IO.Directory]::GetFileSystemEntries([IO.Path]::GetDirectoryName($root),[IO.Path]::GetFileName($root))|Sort-Object)){if([IO.Directory]::Exists($path)){foreach($entry in @([IO.Directory]::EnumerateFileSystemEntries($path,'*',[IO.SearchOption]::AllDirectories)|Sort-Object)){if([IO.Directory]::Exists($entry)){$treeRows.Add("D|$([IO.Path]::GetFullPath($entry))")}else{$treeRows.Add("F|$(&$hashFile $entry)")}}}else{$treeRows.Add("F|$(&$hashFile $path)")}}}
    $current=[Diagnostics.Process]::GetCurrentProcess();try{$self="$($current.Id)|$($current.StartTime.ToUniversalTime().Ticks)|$($current.ProcessName)|$($current.SessionId)"}finally{$current.Dispose()};$workers=[Collections.Generic.List[string]]::new();foreach($process in [Diagnostics.Process]::GetProcesses()){try{if($process.ProcessName-like'ida*'-or$process.ProcessName-like'python*'){$ticks=0L;try{$ticks=$process.StartTime.ToUniversalTime().Ticks}catch{};$workers.Add("$($process.Id)|$ticks|$($process.ProcessName)|$($process.SessionId)")}}finally{$process.Dispose()}};$workerArray=[string[]]$workers.ToArray();[Array]::Sort($workerArray,[StringComparer]::Ordinal)
    $listeners=[Collections.Generic.List[string]]::new();$sockets=[Collections.Generic.List[string]]::new();$network=[Net.NetworkInformation.IPGlobalProperties]::GetIPGlobalProperties();foreach($endpoint in $network.GetActiveTcpListeners()){if($endpoint.Port-eq13337){$listeners.Add("$($endpoint.Address):$($endpoint.Port)")}};foreach($connection in $network.GetActiveTcpConnections()){if($connection.LocalEndPoint.Port-eq13337-or$connection.RemoteEndPoint.Port-eq13337){$sockets.Add("$($connection.LocalEndPoint)|$($connection.RemoteEndPoint)|$($connection.State)")}};$listenerArray=[string[]]$listeners.ToArray();$socketArray=[string[]]$sockets.ToArray();[Array]::Sort($listenerArray,[StringComparer]::Ordinal);[Array]::Sort($socketArray,[StringComparer]::Ordinal);$runspace=[Management.Automation.Runspaces.Runspace]::DefaultRunspace;$session=if($null-eq$runspace){'NO_DEFAULT_RUNSPACE'}else{"$($runspace.InstanceId)|$($runspace.RunspaceStateInfo.State)|$($runspace.Availability)"}
    return [pscustomobject][ordered]@{Report=$reportTuple;Canonical=$canonicalTuple;AuthorityTree=([string[]]$treeRows.ToArray()-join"`n");HarnessProcess=$self;Workers=($workerArray-join"`n");Listeners=($listenerArray-join"`n");Sockets=($socketArray-join"`n");Session=$session}
}
function Invoke-UID0003YUAuthorityHostileSuiteV7 {
    $report=[IO.Path]::GetFullPath('E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\0003YU-RankingCategoryRecordRangeCopyConstructDeep-source-quality.md');$text=[IO.File]::ReadAllText($report,[Text.Encoding]::UTF8);$fences=[regex]::Matches($text,'(?ms)^```powershell\r?\n(?<body>.*?)^```\s*$');$entryText=$null
    foreach($fence in $fences){$tokens=$null;$errors=$null;$ast=[Management.Automation.Language.Parser]::ParseInput($fence.Groups['body'].Value,[ref]$tokens,[ref]$errors);foreach($statement in $ast.EndBlock.Statements){if($statement-is[Management.Automation.Language.FunctionDefinitionAst]-and$statement.Name-ceq'Import-UID0003YUProductionPackageV7'){$body=[string]$statement.Body.Extent.Text;$body=$body.Substring(1,$body.Length-2);$parameters=[Collections.Generic.List[string]]::new();foreach($parameter in $statement.Parameters){$parameters.Add([string]$parameter.Extent.Text)};$entryText=if($parameters.Count){'param('+($parameters.ToArray()-join',')+")`n"+$body}else{$body}}}}
    if([string]::IsNullOrWhiteSpace($entryText)){throw 'V7_FINAL_ENTRY_NOT_FOUND'};$entry=[scriptblock]::Create($entryText);$observerText=$null;foreach($fence in $fences){$tokens=$null;$errors=$null;$ast=[Management.Automation.Language.Parser]::ParseInput($fence.Groups['body'].Value,[ref]$tokens,[ref]$errors);foreach($statement in $ast.EndBlock.Statements){if($statement-is[Management.Automation.Language.FunctionDefinitionAst]-and$statement.Name-ceq'Get-UID0003YUObservedStateV7'){$body=[string]$statement.Body.Extent.Text;$observerText=$body.Substring(1,$body.Length-2)}}};$observer=[scriptblock]::Create($observerText)
    $hashText={param([string]$Text)$sha=[Security.Cryptography.SHA256]::Create();try{return([BitConverter]::ToString($sha.ComputeHash([Text.Encoding]::UTF8.GetBytes($Text)))).Replace('-','')}finally{$sha.Dispose()}}.GetNewClosure();$results=[Collections.Generic.List[object]]::new();$fixtureRoot=Join-Path ([IO.Path]::GetTempPath()) ('UID0003YU-V7-FRESH-'+((&$hashText $text).Substring(0,16)));if([IO.Directory]::Exists($fixtureRoot)){[IO.Directory]::Delete($fixtureRoot,$true)};$initial=&$observer
    $run={param([string]$Label,[scriptblock]$Body,[bool]$AllowTreeChange)$before=&$observer;$value=&$Body;$after=&$observer;$drifts=[Collections.Generic.List[string]]::new();foreach($field in @('Report','Canonical','HarnessProcess','Workers','Listeners','Sockets','Session')){if([string]$before.$field-cne[string]$after.$field){$drifts.Add($field)}};if(-not$AllowTreeChange-and[string]$before.AuthorityTree-cne[string]$after.AuthorityTree){$drifts.Add('AuthorityTree')};if($drifts.Count){throw "$Label|INDEPENDENT_EFFECT_DRIFT|$($drifts-join',')"};$code=if($null-eq$value){'NULL'}elseif($null-ne$value.PSObject.Properties['Marker']){[string]$value.Marker}else{[string]$value};$child=if($null-ne$value-and$null-ne$value.PSObject.Properties['Child']){$value.Child}else{$null};if($null-ne$child-and($child.TimedOut-or-not$child.Retired-or$child.ExitCode-ne0-or-not$child.StdErrEmpty)){throw "$Label|CHILD_RECEIPT_DRIFT"};$results.Add([pscustomobject][ordered]@{Label=$Label;Code=$code;Independent=[pscustomobject][ordered]@{ReportStable=($before.Report-ceq$after.Report);CanonicalStable=($before.Canonical-ceq$after.Canonical);AuthorityTreeStable=($before.AuthorityTree-ceq$after.AuthorityTree);HarnessStable=($before.HarnessProcess-ceq$after.HarnessProcess);WorkersStable=($before.Workers-ceq$after.Workers);ListenersStable=($before.Listeners-ceq$after.Listeners);SocketsStable=($before.Sockets-ceq$after.Sockets);SessionStable=($before.Session-ceq$after.Session);ExpectedTreeChange=$AllowTreeChange};Child=$child})}.GetNewClosure()
    $rejectUnknown={param([string]$Label,[scriptblock]$Body,[string]$Parameter)$message='';try{$null=&$Body}catch{$message=$_.Exception.GetBaseException().Message};if($message-notmatch([regex]::Escape($Parameter))){throw "$Label|WRONG_REJECTION:$message"};return [pscustomobject]@{Marker="V7_CALLER_AUTHORITY_PARAMETER_REJECTED:$Parameter"}}.GetNewClosure()
    try{
        &$run 'V7_ALTERNATE_REPORT_REJECTED' {&$rejectUnknown 'V7_ALTERNATE_REPORT_REJECTED' {&$entry -Mode Preflight -ReportPath 'C:\forged\report.md'} 'ReportPath'} $false
        &$run 'V7_COHERENT_FABRICATED_AUTHORITY_REJECTED' {&$rejectUnknown 'V7_COHERENT_FABRICATED_AUTHORITY_REJECTED' {&$entry -Mode Preflight -SupervisorAuthority ([pscustomobject]@{Runtime='forged';Root='forged';Manifest='forged'})} 'SupervisorAuthority'} $false
        &$run 'V7_ALTERNATE_ROOT_REJECTED' {&$rejectUnknown 'V7_ALTERNATE_ROOT_REJECTED' {&$entry -Mode Preflight -RootPath 'C:\forged\authority.root'} 'RootPath'} $false
        &$run 'V7_ALTERNATE_B0_REJECTED' {&$rejectUnknown 'V7_ALTERNATE_B0_REJECTED' {&$entry -Mode Preflight -BackupPath 'C:\forged\alternate.B0'} 'BackupPath'} $false
        &$run 'V7_ARBITRARY_DIGEST_REJECTED' {&$rejectUnknown 'V7_ARBITRARY_DIGEST_REJECTED' {&$entry -Mode Preflight -ImplementationContractSHA256 ('D'*64)} 'ImplementationContractSHA256'} $false
        &$run 'V7_COHERENT_MULTI_AUTHORITY_REJECTED' {&$rejectUnknown 'V7_COHERENT_MULTI_AUTHORITY_REJECTED' {&$entry -Mode Preflight -RootPath 'C:\forged\root' -BackupPath 'C:\forged\b0' -ImplementationContractSHA256 ('D'*64)} 'RootPath'} $false
        &$run 'V7_DIRECT_ESTABLISH_REJECTED' {$message='';try{$null=&$entry -Mode Establish}catch{$message=$_.Exception.GetBaseException().Message};if($message-notmatch'Establish'){throw "V7_DIRECT_ESTABLISH_WRONG_CODE:$message"};[pscustomobject]@{Marker='V7_DIRECT_ESTABLISH_MODE_REJECTED'}} $false
        &$run 'V7_REGISTRY_REPLACEMENT_REJECTED' {&$rejectUnknown 'V7_REGISTRY_REPLACEMENT_REJECTED' {&$entry -Mode Preflight -Registry ([Collections.Generic.Dictionary[guid,object]]::new())} 'Registry'} $false
        &$run 'V7_IMPORTER_FUNCTION_SHADOW_IGNORED' {$existing=Get-Item -LiteralPath 'Function:\Import-UID0003YUProductionPackageV6' -ErrorAction SilentlyContinue;try{Set-Item -LiteralPath 'Function:\global:Import-UID0003YUProductionPackageV6' -Value {throw 'FORGED_V6_IMPORTER_CALLED'} -Force;$receipt=&$entry -Mode Preflight;if($receipt.Result.Marker-cne'UID0003YU_V7_INTERNAL_PREFLIGHT_READY'){throw 'V7_PINNED_IMPORTER_ROUTE_DRIFT'};return $receipt}finally{if($null-eq$existing){Remove-Item -LiteralPath 'Function:\global:Import-UID0003YUProductionPackageV6' -Force -ErrorAction SilentlyContinue}else{Set-Item -LiteralPath 'Function:\global:Import-UID0003YUProductionPackageV6' -Value ([scriptblock]::Create([string]$existing.Definition)) -Force}}} $false
        &$run 'V7_IMPORTER_ALIAS_SHADOW_IGNORED' {$existing=Get-Alias -Name Import-UID0003YUProductionPackageV6 -ErrorAction SilentlyContinue;try{Set-Alias -Name Import-UID0003YUProductionPackageV6 -Value Write-Output -Scope Global -Force;$receipt=&$entry -Mode Preflight;if($receipt.ImporterSHA256-cne'9766C4D8482F2607DB6E71014A2E30E3CF28B38D1F6506A85819BCD9EB01CAD4'){throw 'V7_ALIAS_SHADOW_REDIRECTED'};return $receipt}finally{if($null-eq$existing){Remove-Item -LiteralPath 'Alias:\Import-UID0003YUProductionPackageV6' -Force -ErrorAction SilentlyContinue}else{Set-Alias -Name Import-UID0003YUProductionPackageV6 -Value $existing.Definition -Scope Global -Force}}} $false
        &$run 'V7_CLR_PRIVATE_STATE_REFLECTION_ABSENT' {$beforeTypes=@([AppDomain]::CurrentDomain.GetAssemblies()|ForEach-Object{$_.GetTypes()}|Where-Object{$_.FullName-like'UID0003YUSealedBoundaryV7_*'}|ForEach-Object{$_.AssemblyQualifiedName});$receipt=&$entry -Mode Preflight;$afterTypes=@([AppDomain]::CurrentDomain.GetAssemblies()|ForEach-Object{$_.GetTypes()}|Where-Object{$_.FullName-like'UID0003YUSealedBoundaryV7_*'}|ForEach-Object{$_.AssemblyQualifiedName});if(($beforeTypes-join'|')-cne($afterTypes-join'|')){throw 'V7_PARENT_CLR_STATE_CREATED'};foreach($value in @($receipt,$receipt.Result,$receipt.Child)){if($value-is[Reflection.MethodInfo]-or$value-is[Type]-or$value-is[Delegate]-or$value-is[scriptblock]-or$value-is[Management.Automation.PowerShell]){throw 'V7_REFLECTIVE_AUTHORITY_RETURNED'}};if($receipt.ReturnedAuthorityObjects-ne0-or$receipt.ReturnedMethodInfo-ne0-or$receipt.ReturnedTypes-ne0-or$receipt.ReturnedDelegates-ne0-or$receipt.ReturnedScriptBlocks-ne0-or$receipt.ReturnedPowerShellObjects-ne0-or$receipt.ReturnedRegistries-ne0){throw 'V7_RETURNED_AUTHORITY_COUNTER_DRIFT'};return [pscustomobject]@{Marker='V7_PROCESS_ISOLATION_HAS_NO_REFLECTIVE_STATE'}} $false
        &$run 'V7_FRESH_PROCESS_REORDERED_OPERATION' {$message='';try{$null=&$entry -Mode RestartReordered}catch{$message=$_.Exception.GetBaseException().Message};if($message-notmatch'V7_FRESH_PROCESS_REORDERED_REFUSED'){throw "V7_REORDER_WRONG_CODE:$message"};[pscustomobject]@{Marker='V7_FRESH_PROCESS_REORDERED_REFUSED'}} $false
        &$run 'V7_FRESH_PROCESS_INITIALIZE' {$receipt=&$entry -Mode RestartInitialize;if($receipt.Result.Marker-cne'UID0003YU_V7_FRESH_PROCESS_INITIALIZED'-or$receipt.Result.Sequence.Count-ne4){throw 'V7_RESTART_INITIALIZE_DRIFT'};return $receipt} $true
        &$run 'V7_ROOT_IDENTITY_MISMATCH_REJECTED' {$rootPath=Join-Path $fixtureRoot 'authority.root';$held=Join-Path $fixtureRoot 'authority.root.held';$bytes=[IO.File]::ReadAllBytes($rootPath);Move-Item -LiteralPath $rootPath -Destination $held;try{[IO.File]::WriteAllBytes($rootPath,$bytes);$message='';try{$null=&$entry -Mode RestartReentry}catch{$message=$_.Exception.GetBaseException().Message};if($message-notmatch'V3_EXTERNAL_ROOT_REPLACED|V7_INTERNAL_ROOT_IDENTITY_DRIFT'){throw "V7_ROOT_IDENTITY_WRONG_CODE:$message"};return [pscustomobject]@{Marker='V7_ROOT_IDENTITY_MISMATCH_REJECTED'}}finally{Remove-Item -LiteralPath $rootPath -Force -ErrorAction SilentlyContinue;Move-Item -LiteralPath $held -Destination $rootPath}} $false
        &$run 'V7_FRESH_PROCESS_REENTRY_REFUSED' {$receipt=&$entry -Mode RestartReentry;if($receipt.Result.Marker-cne'UID0003YU_V7_FRESH_PROCESS_REENTRY_REFUSED'-or-not$receipt.Child.Retired){throw 'V7_REENTRY_RECEIPT_DRIFT'};return $receipt} $false
        &$run 'V7_FRESH_PROCESS_DUPLICATE_REFUSED' {$receipt=&$entry -Mode RestartDuplicate;if($receipt.Result.Marker-cne'UID0003YU_V7_FRESH_PROCESS_DUPLICATE_REFUSED'){throw 'V7_DUPLICATE_RECEIPT_DRIFT'};return $receipt} $false
        &$run 'V7_CALLER_RECEIPT_MUTATION_NO_AUTHORITY' {$receipt=&$entry -Mode Preflight;$receipt.Result.Report.SHA256='F'*64;$receipt.Result.RootPath='C:\forged';$again=&$entry -Mode Preflight;if($again.Result.Report.SHA256-ceq('F'*64)-or$again.Result.RootPath-ceq'C:\forged'){throw 'V7_CALLER_RECEIPT_MUTATION_REDIRECTED'};return $again} $false
        &$run 'V7_REGISTRY_RESET_SURFACE_ABSENT' {$names=@([AppDomain]::CurrentDomain.GetAssemblies()|ForEach-Object{$_.GetTypes()}|Where-Object{$_.FullName-like'UID0003YUSealedBoundaryV7_*'}|ForEach-Object{$_.FullName});if($names.Count-ne0){throw 'V7_PARENT_REGISTRY_TYPE_PRESENT'};return [pscustomobject]@{Marker='V7_NO_PARENT_REGISTRY_TO_RESET'}} $false
    }finally{if([IO.Directory]::Exists($fixtureRoot)){[IO.Directory]::Delete($fixtureRoot,$true)}}
    $final=&$observer;if($initial.Report-cne$final.Report-or$initial.Canonical-cne$final.Canonical-or$initial.AuthorityTree-cne$final.AuthorityTree-or$initial.HarnessProcess-cne$final.HarnessProcess-or$initial.Workers-cne$final.Workers-or$initial.Listeners-cne$final.Listeners-or$initial.Sockets-cne$final.Sockets-or$initial.Session-cne$final.Session){throw 'V7_FINAL_INDEPENDENT_EFFECT_OR_RESIDUE_DRIFT'}
    $labels=@($results|ForEach-Object{$_.Label});if($labels.Count-ne18-or@($labels|Sort-Object -Unique).Count-ne18){throw "V7_FINAL_HOSTILE_LABEL_DRIFT:$($labels.Count)"};$stableRows=@($results|ForEach-Object{"$($_.Label)|$($_.Code)|$($_.Independent.ReportStable)|$($_.Independent.CanonicalStable)|$($_.Independent.HarnessStable)|$($_.Independent.WorkersStable)|$($_.Independent.ListenersStable)|$($_.Independent.SocketsStable)|$($_.Independent.SessionStable)"});return [pscustomobject][ordered]@{Marker='UID0003YU_V7_INTERNAL_AUTHORITY_SUITE_PASSED';Count=$results.Count;Labels=$labels;ResultSHA256=&$hashText ($stableRows-join"`n");FreshProcessChildren=@($results|Where-Object{$null-ne$_.Child}|ForEach-Object{$_.Child});IndependentFinalState=$final;Results=@($results)}
}
# UID0003YU FINAL V7 PROCESS-ISOLATED INTERNAL AUTHORITY END
~~~

## Removed Block R020

- SHA256: `8001055C5F08112CFF4E003A59962902DEAF092102F132E5FC0E531F272702BB`
- Language: `powershell`
- Bytes: `50160`
- First recovered timestamp: `2026-08-09T09:19:23.037Z`
- Session provenance: rollout-2026-08-07T21-28-25-019fdefc-4eb3-7c02-8dc4-19f7da3eee30.jsonl line 199946 (2026-08-09T09:19:23.037Z); rollout-2026-08-07T21-28-25-019fdefc-4eb3-7c02-8dc4-19f7da3eee30.jsonl line 199947 (2026-08-09T09:19:23.215Z)

~~~powershell
# UID0003YU FINAL V8 EXTERNAL-PIN PROCESS-BOUNDARY START
function Import-UID0003YUProductionPackageV7 {
    [CmdletBinding()]
    param(
        [ValidateSet('Preflight','DurableRegression','SharedRegression','ProductionBoundary','ProductionCommit','AuthorityRegression','CoherentPreseedProbe','TreeTimeoutProbe','OutputStallProbe','InheritedPipeProbe','ImmediateParentExitProbe','FailedKillProbe','SurvivingDescendantProbe')]
        [string]$Mode='Preflight'
    )

    $reportPath=[IO.Path]::GetFullPath('E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\0003YU-RankingCategoryRecordRangeCopyConstructDeep-source-quality.md')
    $canonicalPath=[IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64')
    $powerShellPath=[IO.Path]::GetFullPath('C:\Windows\System32\WindowsPowerShell\v1.0\powershell.exe')
    $expectedSystemDirectory=[IO.Path]::GetFullPath('C:\Windows\System32')
    $expectedV6Fingerprint='9766C4D8482F2607DB6E71014A2E30E3CF28B38D1F6506A85819BCD9EB01CAD4'
    $fixtureBase=[IO.Path]::GetFullPath((Join-Path ([Environment]::GetFolderPath([Environment+SpecialFolder]::LocalApplicationData)) 'Temp\UID0003YU-V8-Authority'))
    $productionBase=[IO.Path]::GetFullPath((Join-Path ([IO.Path]::GetDirectoryName($canonicalPath)) '.UID0003YU-Gate2B-Authority-V8'))

    $hashBytes={
        param([byte[]]$Bytes)
        $sha=[Security.Cryptography.SHA256]::Create()
        try { return ([BitConverter]::ToString($sha.ComputeHash($Bytes))).Replace('-','') }
        finally { $sha.Dispose() }
    }.GetNewClosure()
    $hashText={param([string]$Text) return &$hashBytes ([Text.Encoding]::UTF8.GetBytes($Text))}.GetNewClosure()
    $fileTuple={
        param([string]$Path)
        $stream=[IO.File]::Open($Path,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::ReadWrite -bor [IO.FileShare]::Delete)
        $sha=[Security.Cryptography.SHA256]::Create()
        try {
            return [pscustomobject][ordered]@{
                Path=[IO.Path]::GetFullPath($Path)
                Length=[long]$stream.Length
                SHA256=([BitConverter]::ToString($sha.ComputeHash($stream))).Replace('-','')
                CreationTimeUtcTicks=[long][IO.File]::GetCreationTimeUtc($Path).Ticks
                LastWriteTimeUtcTicks=[long][IO.File]::GetLastWriteTimeUtc($Path).Ticks
            }
        } finally { $sha.Dispose();$stream.Dispose() }
    }.GetNewClosure()
    $newTransaction={
        param([string]$Base)
        $bytes=New-Object byte[] 24
        $rng=[Security.Cryptography.RandomNumberGenerator]::Create()
        try {$rng.GetBytes($bytes)} finally {$rng.Dispose()}
        $id=([BitConverter]::ToString($bytes)).Replace('-','').ToLowerInvariant()
        [Array]::Clear($bytes,0,$bytes.Length)
        return [pscustomobject][ordered]@{
            Id=$id
            Root=[IO.Path]::GetFullPath((Join-Path $Base ('root-'+$id)))
            Pin=[IO.Path]::GetFullPath((Join-Path $Base ('supervisor-pin-'+$id+'.json')))
        }
    }.GetNewClosure()
    $snapshotTree={
        param([string]$Root,[string]$Pin)
        $rows=[Collections.Generic.List[string]]::new()
        foreach($path in @($Root,$Pin)){
            if([IO.Directory]::Exists($path)){
                $rows.Add('D|'+[IO.Path]::GetFullPath($path))
                foreach($entry in @([IO.Directory]::EnumerateFileSystemEntries($path,'*',[IO.SearchOption]::AllDirectories)|Sort-Object)){
                    if([IO.Directory]::Exists($entry)){$rows.Add('D|'+[IO.Path]::GetFullPath($entry))}
                    else {$tuple=&$fileTuple $entry;$rows.Add("F|$($tuple.Path)|$($tuple.Length)|$($tuple.SHA256)|$($tuple.CreationTimeUtcTicks)|$($tuple.LastWriteTimeUtcTicks)")}
                }
            } elseif([IO.File]::Exists($path)){
                $tuple=&$fileTuple $path;$rows.Add("F|$($tuple.Path)|$($tuple.Length)|$($tuple.SHA256)|$($tuple.CreationTimeUtcTicks)|$($tuple.LastWriteTimeUtcTicks)")
            }
        }
        return [string[]]$rows.ToArray()
    }.GetNewClosure()
    $removeTransaction={
        param($Transaction)
        if([IO.File]::Exists($Transaction.Pin)){[IO.File]::Delete($Transaction.Pin)}
        if([IO.Directory]::Exists($Transaction.Root)){[IO.Directory]::Delete($Transaction.Root,$true)}
    }.GetNewClosure()

    if(-not[IO.File]::Exists($reportPath)){throw 'V8_INTERNAL_REPORT_MISSING'}
    if(-not[IO.File]::Exists($canonicalPath)){throw 'V8_INTERNAL_CANONICAL_MISSING'}
    if(-not[IO.File]::Exists($powerShellPath)){throw 'V8_PINNED_POWERSHELL_MISSING'}
    if([IO.Path]::GetFullPath([Environment]::SystemDirectory)-cne$expectedSystemDirectory){throw 'V8_SYSTEM_DIRECTORY_IDENTITY_DRIFT'}
    $reportBytes=[IO.File]::ReadAllBytes($reportPath);$reportText=[Text.Encoding]::UTF8.GetString($reportBytes);$reportSHA=&$hashBytes $reportBytes
    if($reportText.IndexOf("`r",[StringComparison]::Ordinal)-ge0-or$reportText.IndexOf([char]0)-ge0-or-not$reportText.EndsWith("`n",[StringComparison]::Ordinal)){throw 'V8_INTERNAL_REPORT_ENCODING_DRIFT'}
    if([regex]::Matches($reportText,'(?m)^READY_FOR_SUPERVISOR_GATE1_REVIEW$').Count-ne1){throw 'V8_INTERNAL_TERMINAL_MARKER_DRIFT'}

    $fences=[regex]::Matches($reportText,'(?ms)^```powershell\r?\n(?<body>.*?)^```\s*$')
    $finalDefinitions=@{}
    foreach($fence in $fences){
        $tokens=$null;$errors=$null;$ast=[Management.Automation.Language.Parser]::ParseInput($fence.Groups['body'].Value,[ref]$tokens,[ref]$errors)
        if($errors.Count){throw "V8_INTERNAL_DEFINITION_PARSE:$($errors[0].Message)"}
        foreach($statement in $ast.EndBlock.Statements){if($statement-is[Management.Automation.Language.FunctionDefinitionAst]){$finalDefinitions[$statement.Name]=[string]$statement.Extent.Text}}
    }
    if(-not$finalDefinitions.ContainsKey('Import-UID0003YUProductionPackageV6')){throw 'V8_INTERNAL_V6_IMPORTER_MISSING'}
    $fingerprint={
        param([Management.Automation.Language.FunctionDefinitionAst]$Function)
        $body=[string]$Function.Body.Extent.Text;$body=$body.Substring(1,$body.Length-2)
        $parameterRows=[Collections.Generic.List[string]]::new();foreach($parameter in $Function.Parameters){$parameterRows.Add([string]$parameter.Extent.Text)}
        $source=if($parameterRows.Count){'param('+($parameterRows.ToArray()-join',')+")`n"+$body}else{$body}
        $tokens=$null;$errors=$null;$null=[Management.Automation.Language.Parser]::ParseInput($source,[ref]$tokens,[ref]$errors);if($errors.Count){throw 'V8_INTERNAL_FINGERPRINT_PARSE'}
        $builder=[Text.StringBuilder]::new()
        foreach($token in $tokens){if($token.Kind-notin@([Management.Automation.Language.TokenKind]::NewLine,[Management.Automation.Language.TokenKind]::Comment,[Management.Automation.Language.TokenKind]::LineContinuation,[Management.Automation.Language.TokenKind]::EndOfInput)){$value=[string]$token.Extent.Text;$null=$builder.Append([string]$token.Kind).Append(':').Append($value.Length).Append(':').Append($value).Append('|')}}
        return &$hashText $builder.ToString()
    }.GetNewClosure()
    $tokens=$null;$errors=$null;$v6Ast=[Management.Automation.Language.Parser]::ParseInput([string]$finalDefinitions['Import-UID0003YUProductionPackageV6'],[ref]$tokens,[ref]$errors)
    $v6Function=@($v6Ast.EndBlock.Statements|Where-Object{$_-is[Management.Automation.Language.FunctionDefinitionAst]})[0]
    $v6Fingerprint=&$fingerprint $v6Function;if($v6Fingerprint-cne$expectedV6Fingerprint){throw 'V8_INTERNAL_V6_IMPORTER_FINGERPRINT_DRIFT'}
    $definitionNames=[string[]]@($finalDefinitions.Keys);[Array]::Sort($definitionNames,[StringComparer]::Ordinal);$definitionRows=[Collections.Generic.List[string]]::new()
    foreach($name in $definitionNames){$source=[string]$finalDefinitions[$name];$definitionRows.Add([regex]::Replace($source,'^function\s+[^\s\(\{]+',("function global:{0}"-f$name),[Text.RegularExpressions.RegexOptions]::IgnoreCase))}

    $getProcesses={
        $searcher=[System.Management.ManagementObjectSearcher]::new('SELECT ProcessId,ParentProcessId,CreationDate,ExecutablePath,Name FROM Win32_Process')
        try {
            $rows=[Collections.Generic.List[object]]::new()
            foreach($item in @($searcher.Get())){
                try {$rows.Add([pscustomobject][ordered]@{Pid=[int]$item.ProcessId;ParentPid=[int]$item.ParentProcessId;Creation=[string]$item.CreationDate;Path=[string]$item.ExecutablePath;Name=[string]$item.Name})}
                finally {$item.Dispose()}
            }
            return @($rows)
        } finally {$searcher.Dispose()}
    }.GetNewClosure()
    $collectDescendants={
        param([int]$RootPid,[Collections.Generic.Dictionary[string,object]]$Known)
        $rows=@(&$getProcesses);$parents=[Collections.Generic.HashSet[int]]::new();$null=$parents.Add($RootPid);$changed=$true
        while($changed){$changed=$false;foreach($row in $rows){if($parents.Contains([int]$row.ParentPid)-and-not$parents.Contains([int]$row.Pid)){$null=$parents.Add([int]$row.Pid);$changed=$true}}}
        foreach($row in $rows){if($row.Pid-ne$RootPid-and$parents.Contains([int]$row.Pid)){$key="$($row.Pid)|$($row.Creation)";if(-not$Known.ContainsKey($key)){$Known.Add($key,$row)}}}
        return $rows
    }.GetNewClosure()
    $generationPresent={
        param($Row)
        foreach($current in @(&$getProcesses)){if($current.Pid-eq$Row.Pid-and$current.Creation-ceq$Row.Creation){return $true}}
        return $false
    }.GetNewClosure()
    $killGeneration={
        param($Row)
        $matched=$false
        foreach($current in @(&$getProcesses)){if($current.Pid-eq$Row.Pid-and$current.Creation-ceq$Row.Creation){$matched=$true;break}}
        if(-not$matched){return 'ALREADY_RETIRED'}
        $process=[Diagnostics.Process]::GetProcessById([int]$Row.Pid)
        try {$process.Kill();return 'KILL_REQUESTED'} finally {$process.Dispose()}
    }.GetNewClosure()

    $invokeChild={
        param([string]$Action,[string]$RootPath,[object]$Pin,[string]$Implementation,[int]$TimeoutMs,[string]$ExpectedFailure)
        $actionLiteral=$Action.Replace("'","''");$reportLiteral=$reportPath.Replace("'","''");$canonicalLiteral=$canonicalPath.Replace("'","''");$rootLiteral=([string]$RootPath).Replace("'","''");$implementationLiteral=([string]$Implementation).Replace("'","''")
        $pinRoot=if($null-eq$Pin){''}else{([string]$Pin.RootPath).Replace("'","''")};$pinIdentity=if($null-eq$Pin){''}else{([string]$Pin.RootFileIdentity).Replace("'","''")};$pinSHA=if($null-eq$Pin){''}else{([string]$Pin.RootSHA256).Replace("'","''")}
        $tail=@"
`$ErrorActionPreference='Stop'
try {
    `$action='$actionLiteral';`$reportPath='$reportLiteral';`$canonicalPath='$canonicalLiteral';`$rootPath='$rootLiteral';`$implementation='$implementationLiteral'
    `$pin=[pscustomobject][ordered]@{RootFileIdentity='$pinIdentity';RootPath='$pinRoot';RootSHA256='$pinSHA'}
    `$hashBytes={param([byte[]]`$Bytes)`$sha=[Security.Cryptography.SHA256]::Create();try{return([BitConverter]::ToString(`$sha.ComputeHash(`$Bytes))).Replace('-','')}finally{`$sha.Dispose()}}.GetNewClosure()
    `$tuple={param([string]`$Path,[bool]`$Exclusive)`$share=if(`$Exclusive){[IO.FileShare]::Read}else{[IO.FileShare]::ReadWrite -bor[IO.FileShare]::Delete};`$stream=[IO.File]::Open(`$Path,[IO.FileMode]::Open,[IO.FileAccess]::Read,`$share);`$sha=[Security.Cryptography.SHA256]::Create();try{return [pscustomobject][ordered]@{Path=[IO.Path]::GetFullPath(`$Path);Length=[long]`$stream.Length;SHA256=([BitConverter]::ToString(`$sha.ComputeHash(`$stream))).Replace('-','');FileIdentity=[UID0003YU.NativeFileTime]::GetFileIdentity(`$stream.SafeFileHandle);CreationTimeUtcTicks=[long][UID0003YU.NativeFileTime]::GetCreationUtcTicks(`$stream.SafeFileHandle);LastWriteTimeUtcTicks=[long][UID0003YU.NativeFileTime]::GetLastWriteUtcTicks(`$stream.SafeFileHandle)}}finally{`$sha.Dispose();`$stream.Dispose()}}.GetNewClosure()
    Initialize-UID0003YUPlatformV4
    `$report=&`$tuple `$reportPath `$false;`$canonical=&`$tuple `$canonicalPath `$false
    if(`$action-ceq'InitializeAuthority'){
        if([IO.Directory]::Exists(`$rootPath)-or[IO.File]::Exists(`$rootPath)){throw 'V8_AUTHORITY_ALREADY_EXISTS'}
        `$parent=[IO.Path]::GetDirectoryName(`$rootPath);if(-not[IO.Directory]::Exists(`$parent)){[IO.Directory]::CreateDirectory(`$parent)|Out-Null};[IO.Directory]::CreateDirectory(`$rootPath)|Out-Null
        `$writeNew={param([string]`$Path,[byte[]]`$Bytes)`$stream=[IO.File]::Open(`$Path,[IO.FileMode]::CreateNew,[IO.FileAccess]::Write,[IO.FileShare]::None);try{`$stream.Write(`$Bytes,0,`$Bytes.Length);`$stream.Flush(`$true)}finally{`$stream.Dispose()}}.GetNewClosure()
        `$utf8=[Text.UTF8Encoding]::new(`$false);`$key=New-Object byte[] 32;`$rng=[Security.Cryptography.RandomNumberGenerator]::Create();try{`$rng.GetBytes(`$key)}finally{`$rng.Dispose()};`$authorityId=[guid]::NewGuid().ToString('N')
        `$keyPath=Join-Path `$rootPath 'authority.key';`$anchorPath=Join-Path `$rootPath 'authority.anchor';`$journalPath=Join-Path `$rootPath 'authority.journal';`$rootFile=Join-Path `$rootPath 'authority.root'
        &`$writeNew `$keyPath (`$utf8.GetBytes((Protect-AuthKey `$key)));&`$writeNew `$anchorPath (`$utf8.GetBytes('{}'));&`$writeNew `$journalPath ([byte[]]@())
        `$keyTuple=&`$tuple `$keyPath `$true;`$anchorTuple=&`$tuple `$anchorPath `$true;`$journalTuple=&`$tuple `$journalPath `$true
        `$rootObject=[ordered]@{Version=3;AuthorityId=`$authorityId;KeyId=Get-AuthSHA256 `$key;KeyPath=`$keyPath;KeyIdentity=`$keyTuple.FileIdentity;AnchorPath=`$anchorPath;AnchorIdentity=`$anchorTuple.FileIdentity;JournalPath=`$journalPath;JournalIdentity=`$journalTuple.FileIdentity}
        &`$writeNew `$rootFile (`$utf8.GetBytes((Get-AuthCanonicalJson `$rootObject)));`$rootTuple=&`$tuple `$rootFile `$true
        `$anchor=[ordered]@{Version=3;AuthorityId=`$authorityId;Generation=0;JournalHeadHmacSHA256='0'*64;RootSHA256=`$rootTuple.SHA256;AnchorHmacSHA256=''};`$anchor.AnchorHmacSHA256=Get-AuthHmac `$key (Get-AuthCanonicalJson ([ordered]@{AuthorityId=`$anchor.AuthorityId;Generation=`$anchor.Generation;JournalHeadHmacSHA256=`$anchor.JournalHeadHmacSHA256;RootSHA256=`$anchor.RootSHA256;Version=`$anchor.Version}));[IO.File]::WriteAllText(`$anchorPath,(Get-AuthCanonicalJson `$anchor),`$utf8);[Array]::Clear(`$key,0,`$key.Length)
        `$result=[pscustomobject][ordered]@{Marker='UID0003YU_V8_AUTHORITY_INITIALIZED';Report=`$report;Canonical=`$canonical;Pin=[pscustomobject][ordered]@{RootFileIdentity=`$rootTuple.FileIdentity;RootPath=`$rootFile;RootSHA256=`$rootTuple.SHA256};Created=@('authority.key','authority.anchor','authority.journal','authority.root')}
    }elseif(`$action-in@('ImmediateParentExitProbe','InheritedPipeProbe','SurvivingDescendantProbe','OutputStallProbe','TreeTimeoutProbe','FailedKillProbe')){
        `$exe='C:\Windows\System32\WindowsPowerShell\v1.0\powershell.exe';`$grand=[Diagnostics.ProcessStartInfo]::new();`$grand.FileName=`$exe;`$grand.UseShellExecute=`$false;`$grand.CreateNoWindow=`$true
        if(`$action-ceq'OutputStallProbe'){`$grand.Arguments='-NoLogo -NoProfile -NonInteractive -Command "1..1200 | ForEach-Object { [Console]::Out.WriteLine((''X''*1024)); Start-Sleep -Milliseconds 50 }"'}else{`$grand.Arguments='-NoLogo -NoProfile -NonInteractive -Command "Start-Sleep -Seconds 120"'}
        `$descendant=[Diagnostics.Process]::new();`$descendant.StartInfo=`$grand;if(-not`$descendant.Start()){throw 'V8_PROBE_DESCENDANT_START_FAILED'};`$descendantPid=`$descendant.Id;`$descendant.Dispose()
        if(`$action-ceq'TreeTimeoutProbe'){Start-Sleep -Seconds 120}
        Start-Sleep -Milliseconds 900
        `$result=[pscustomobject][ordered]@{Marker=('UID0003YU_V8_'+`$action.ToUpperInvariant());DescendantPid=`$descendantPid}
    }else{
        `$v6=`$ExecutionContext.InvokeCommand.GetCommand('Import-UID0003YUProductionPackageV6',[Management.Automation.CommandTypes]::Function);if(`$null-eq`$v6){throw 'V8_V6_IMPORTER_NOT_LOADED'}
        if(`$action-ceq'Preflight'){
            `$result=[pscustomobject][ordered]@{Marker='UID0003YU_V8_PREFLIGHT_READY';Boundary='EXTERNAL_SIBLING_PIN_PARENT_HELD';Report=`$report;Canonical=`$canonical;McpCalls=0;IdbOpen=0;Save=0;Restore=0;IdaMutation=0}
        }elseif(`$action-in@('DurableRegression','SharedRegression')){
            `$package=&`$v6.ScriptBlock `$reportPath;`$launcher=`$package.Item1;`$result=@(&`$launcher `$action `$null)[0]
        }elseif(`$action-in@('ProductionBoundary','ProductionCommit')){
            `$package=&`$v6.ScriptBlock `$reportPath;`$launcher=`$package.Item1;`$preflight=@(&`$launcher 'Preflight')[0];if(`$preflight.Marker-cne'UID0003YU_V6_HELD_PREFLIGHT_READY'){throw 'V8_V6_PREFLIGHT_DRIFT'}
            `$binding=[pscustomobject][ordered]@{BackupPath=(Join-Path `$rootPath 'UID0003YU.B0');CanonicalPath=`$canonicalPath;ExternalAuthorityPin=`$pin;ImplementationContractSHA256=`$implementation};`$provision=@(&`$launcher 'Provision' `$binding)[0];`$boundary=@(&`$launcher 'Production')[0];if(`$boundary.Marker-cne'UID0003YU_V6_READ_ONLY_PRODUCTION_BOUNDARY_REACHED'){throw 'V8_PRODUCTION_BOUNDARY_DRIFT'}
            if(`$action-ceq'ProductionCommit'){`$live=@(&`$launcher 'Production')[0];`$result=[pscustomobject][ordered]@{Marker='UID0003YU_V8_PRODUCTION_COMMIT';Provision=`$provision;Boundary=`$boundary;Live=`$live}}else{`$result=[pscustomobject][ordered]@{Marker='UID0003YU_V8_PRODUCTION_BOUNDARY';Provision=`$provision;Boundary=`$boundary}}
        }elseif(`$action-ceq'RestartWriteTerminal'){
            `$authority=Open-UID0003YULiveAuthorityV3 `$pin;try{`$records=@(Read-UID0003YULiveJournalV3 `$authority 'V8_RESTART_INITIAL');if(`$records.Count-ne0){throw 'V8_RESTART_EXPECTED_EMPTY'};`$null=Add-UID0003YULiveJournalRecordV3 `$authority 'TERMINAL' ([ordered]@{ImplementationContractSHA256=`$implementation;SaveAttemptCount=0;SaveRequestId=[long]0;SaveRequestJson='';SaveRequestSHA256='';SaveResponseSHA256='';P0=`$null;B0=`$null})}finally{Close-UID0003YULiveAuthorityV3 `$authority};`$result=[pscustomobject][ordered]@{Marker='UID0003YU_V8_RESTART_TERMINAL_WRITTEN'}
        }elseif(`$action-ceq'RestartVerifyTerminal'){
            `$authority=Open-UID0003YULiveAuthorityV3 `$pin;try{`$records=@(Read-UID0003YULiveJournalV3 `$authority 'V8_RESTART_VERIFY')}finally{Close-UID0003YULiveAuthorityV3 `$authority};if(`$records.Count-ne1-or`$records[0].State-cne'TERMINAL'-or`$records[0].ImplementationContractSHA256-cne`$implementation){throw 'V8_RESTART_CONTINUITY_DRIFT'};`$result=[pscustomobject][ordered]@{Marker='UID0003YU_V8_RESTART_CONTINUITY_PROVED';RecordCount=`$records.Count}
        }else{throw 'V8_CHILD_ACTION_DRIFT'}
    }
    `$jsonCommand=`$ExecutionContext.InvokeCommand.GetCommand('ConvertTo-Json',[Management.Automation.CommandTypes]::Cmdlet);if(`$null-eq`$jsonCommand-or`$jsonCommand.ImplementingType.FullName-cne'Microsoft.PowerShell.Commands.ConvertToJsonCommand'){throw 'V8_JSON_COMMAND_DRIFT'};[Console]::Out.WriteLine('UID0003YU_V8_RESULT|'+(&`$jsonCommand -InputObject `$result -Depth 20 -Compress));exit 0
} catch {[Console]::Error.WriteLine('UID0003YU_V8_CHILD_FAILED|'+`$_.Exception.GetBaseException().Message);exit 97}
"@
        $payload=($definitionRows.ToArray()-join"`n`n")+"`n`n"+$tail;$payloadSHA=&$hashText $payload
        $exeHold=[IO.File]::Open($powerShellPath,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::Read);$exeSHA=$null;$exeLength=0L
        try {$sha=[Security.Cryptography.SHA256]::Create();try{$exeLength=[long]$exeHold.Length;$exeSHA=([BitConverter]::ToString($sha.ComputeHash($exeHold))).Replace('-','');$exeHold.Position=0}finally{$sha.Dispose()}}
        catch {$exeHold.Dispose();throw}
        $arguments='-NoLogo -NoProfile -NonInteractive -Command "[scriptblock]::Create([Console]::In.ReadToEnd()).Invoke()"'
        $start=[Diagnostics.ProcessStartInfo]::new();$start.FileName=$powerShellPath;$start.Arguments=$arguments;$start.UseShellExecute=$false;$start.RedirectStandardInput=$true;$start.RedirectStandardOutput=$true;$start.RedirectStandardError=$true;$start.CreateNoWindow=$true
        $start.EnvironmentVariables.Clear();$start.EnvironmentVariables['SystemRoot']='C:\Windows';$start.EnvironmentVariables['WINDIR']='C:\Windows';$start.EnvironmentVariables['ComSpec']='C:\Windows\System32\cmd.exe';$start.EnvironmentVariables['PATH']='C:\Windows\System32;C:\Windows\System32\WindowsPowerShell\v1.0';$start.EnvironmentVariables['PATHEXT']='.COM;.EXE;.BAT;.CMD';$start.EnvironmentVariables['TEMP']=[IO.Path]::GetFullPath((Join-Path ([Environment]::GetFolderPath([Environment+SpecialFolder]::LocalApplicationData)) 'Temp');$start.EnvironmentVariables['TMP']=$start.EnvironmentVariables['TEMP'];$start.EnvironmentVariables['PSModulePath']=''
        $process=[Diagnostics.Process]::new();$process.StartInfo=$start;$known=[Collections.Generic.Dictionary[string,object]]::new([StringComparer]::Ordinal);$childPid=0;$childStartTicks=0L;$childImage='';$timedOut=$false;$exitCode=-1;$stdout='';$stderr='';$stdoutDone=$false;$stderrDone=$false;$killRows=[Collections.Generic.List[string]]::new();$generationMismatchRefused=$false
        try {
            if(-not$process.Start()){throw 'V8_CHILD_START_FAILED'};$childPid=$process.Id;$childStartTicks=$process.StartTime.ToUniversalTime().Ticks;$childImage=[IO.Path]::GetFullPath($process.MainModule.FileName);if($childImage-cne$powerShellPath){throw 'V8_CHILD_EXECUTABLE_IDENTITY_DRIFT'}
            $stdoutTask=$process.StandardOutput.ReadToEndAsync();$stderrTask=$process.StandardError.ReadToEndAsync();$process.StandardInput.Write($payload);$process.StandardInput.Close();$deadline=[DateTime]::UtcNow.AddMilliseconds($TimeoutMs)
            while(-not$process.HasExited-and[DateTime]::UtcNow-lt$deadline){$null=&$collectDescendants $childPid $known;Start-Sleep -Milliseconds 150;$process.Refresh()}
            $null=&$collectDescendants $childPid $known
            if(-not$process.HasExited){$timedOut=$true;try{$process.Kill();$killRows.Add("ROOT|$childPid|KILL_REQUESTED")}catch{$killRows.Add("ROOT|$childPid|KILL_FAILED|$($_.Exception.GetBaseException().Message)")}}
            if($Action-ceq'FailedKillProbe'-and$known.Count){$first=@($known.Values)[0];$forged=[pscustomobject]@{Pid=$first.Pid;Creation=([string]$first.Creation+'-forged')};if((&$generationPresent $forged)){throw 'V8_GENERATION_MISMATCH_ACCEPTED'};$generationMismatchRefused=$true}
            for($pass=0;$pass-lt40;$pass++){
                $null=&$collectDescendants $childPid $known;$live=@($known.Values|Where-Object{&$generationPresent $_});if($live.Count-eq0){break}
                foreach($row in @($live|Sort-Object ParentPid -Descending)){try{$killRows.Add("DESC|$($row.Pid)|$($row.Creation)|$(&$killGeneration $row)")}catch{$killRows.Add("DESC|$($row.Pid)|$($row.Creation)|KILL_FAILED|$($_.Exception.GetBaseException().Message)")}}
                Start-Sleep -Milliseconds 150
            }
            if(-not$process.WaitForExit(30000)){throw 'V8_ROOT_RETIREMENT_TIMEOUT'}
            $exitCode=$process.ExitCode;$stdoutDone=$stdoutTask.Wait(30000);$stderrDone=$stderrTask.Wait(30000);if(-not$stdoutDone-or-not$stderrDone){try{$process.StandardOutput.Close();$process.StandardError.Close()}catch{};throw 'V8_BOUNDED_DRAIN_TIMEOUT'}
            $stdout=$stdoutTask.Result;$stderr=$stderrTask.Result
        } finally {$process.Dispose();$exeHold.Dispose()}
        $rootRetired=$true;try{$probe=[Diagnostics.Process]::GetProcessById($childPid);try{if($probe.StartTime.ToUniversalTime().Ticks-eq$childStartTicks){$rootRetired=$false}}finally{$probe.Dispose()}}catch{}
        $remaining=@($known.Values|Where-Object{&$generationPresent $_});if(-not$rootRetired-or$remaining.Count){throw 'V8_COMPLETE_PROCESS_TREE_NOT_RETIRED'}
        if(@($killRows|Where-Object{$_-like'*KILL_FAILED*'}).Count){throw 'V8_PROCESS_TREE_KILL_FAILED'}
        $timeoutExpected=$Action-ceq'TreeTimeoutProbe';if($timedOut-ne$timeoutExpected){throw "V8_TIMEOUT_VERDICT_DRIFT:$Action:$timedOut"}
        $matchedFailure=$false;if(-not[string]::IsNullOrWhiteSpace($ExpectedFailure)){$matchedFailure=$exitCode-ne0-and$stderr-match$ExpectedFailure;if(-not$matchedFailure){throw "V8_EXPECTED_FAILURE_MISSING:$ExpectedFailure|$exitCode|$stderr"}}elseif(-not$timeoutExpected-and$exitCode-ne0){throw "V8_CHILD_NONZERO:$exitCode|$stderr"}
        $result=$null;if(-not$timeoutExpected-and-not$matchedFailure){$line=@($stdout-split"`r?`n"|Where-Object{$_-like'UID0003YU_V8_RESULT|*'})[-1];if([string]::IsNullOrWhiteSpace($line)){throw "V8_CHILD_RESULT_MISSING|$stderr"};$convert=$ExecutionContext.InvokeCommand.GetCommand('ConvertFrom-Json',[Management.Automation.CommandTypes]::Cmdlet);if($null-eq$convert-or$convert.ImplementingType.FullName-cne'Microsoft.PowerShell.Commands.ConvertFromJsonCommand'){throw 'V8_CALLER_JSON_COMMAND_DRIFT'};$result=&$convert -InputObject $line.Substring('UID0003YU_V8_RESULT|'.Length)}
        return [pscustomobject][ordered]@{
            Marker='UID0003YU_V8_CHILD_BOUNDARY_COMPLETED';Action=$Action;Result=$result;ExpectedFailure=$matchedFailure;PayloadSHA256=$payloadSHA
            Child=[pscustomobject][ordered]@{ProcessId=$childPid;StartTimeUtcTicks=$childStartTicks;Executable=$childImage;ExecutableSHA256=$exeSHA;ExecutableLength=$exeLength;Arguments=$arguments;TimedOut=$timedOut;ExpectedTermination=$timeoutExpected;ExitCode=$exitCode;StdOutDrainCompleted=$stdoutDone;StdErrDrainCompleted=$stderrDone;StdErrEmpty=[string]::IsNullOrEmpty($stderr);RootRetired=$rootRetired;DescendantGenerations=@($known.Values|ForEach-Object{"$($_.Pid)|$($_.Creation)|$($_.Path)|$($_.Name)"});DescendantsRetired=($remaining.Count-eq0);KillReceipts=@($killRows);GenerationMismatchRefused=$generationMismatchRefused;ProcessTreeComplete=($rootRetired-and$remaining.Count-eq0-and$stdoutDone-and$stderrDone)}
        }
    }.GetNewClosure()

    $writeExternalPin={
        param($Transaction,$Pin)
        if([IO.File]::Exists($Transaction.Pin)){throw 'V8_EXTERNAL_PIN_ALREADY_EXISTS'}
        $escape={param([string]$Value)return $Value.Replace('\','\\').Replace('"','\"')}.GetNewClosure()
        $json='{"RootFileIdentity":"'+(&$escape ([string]$Pin.RootFileIdentity))+'","RootPath":"'+(&$escape ([string]$Pin.RootPath))+'","RootSHA256":"'+(&$escape ([string]$Pin.RootSHA256))+'"}'
        $bytes=[Text.UTF8Encoding]::new($false).GetBytes($json);$stream=[IO.File]::Open($Transaction.Pin,[IO.FileMode]::CreateNew,[IO.FileAccess]::Write,[IO.FileShare]::None);try{$stream.Write($bytes,0,$bytes.Length);$stream.Flush($true)}finally{$stream.Dispose()}
        return &$fileTuple $Transaction.Pin
    }.GetNewClosure()
    $openHolds={
        param($Transaction)
        $holds=[Collections.Generic.List[IO.FileStream]]::new();$holds.Add([IO.File]::Open($Transaction.Pin,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::Read));$holds.Add([IO.File]::Open((Join-Path $Transaction.Root 'authority.root'),[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::Read));$holds.Add([IO.File]::Open((Join-Path $Transaction.Root 'authority.key'),[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::Read));$holds.Add([IO.File]::Open((Join-Path $Transaction.Root 'authority.anchor'),[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::ReadWrite));$holds.Add([IO.File]::Open((Join-Path $Transaction.Root 'authority.journal'),[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::ReadWrite));return $holds
    }.GetNewClosure()
    $closeHolds={param($Holds)if($null-ne$Holds){for($i=$Holds.Count-1;$i-ge0;$i--){$Holds[$i].Dispose()}}}.GetNewClosure()
    $assertBlockedMove={
        param([string]$Source,[string]$Destination,[string]$Code)
        $blocked=$false;try{[IO.File]::Move($Source,$Destination)}catch{$blocked=$true};if(-not$blocked-or-not[IO.File]::Exists($Source)-or[IO.File]::Exists($Destination)){throw $Code};return $Code
    }.GetNewClosure()

    $children=[Collections.Generic.List[object]]::new();$implementation=&$hashText ("UID0003YU-V8`nREPORT=$reportSHA`nCANONICAL=$((&$fileTuple $canonicalPath).SHA256)`nIMPORTER=$v6Fingerprint`n")
    if($Mode-in@('Preflight','DurableRegression','SharedRegression','TreeTimeoutProbe','OutputStallProbe','InheritedPipeProbe','ImmediateParentExitProbe','FailedKillProbe','SurvivingDescendantProbe')){
        $timeout=if($Mode-ceq'TreeTimeoutProbe'){2500}else{240000};$child=&$invokeChild $Mode '' $null $implementation $timeout '';return [pscustomobject][ordered]@{Marker='UID0003YU_V8_EXTERNAL_PIN_BOUNDARY_COMPLETED';Mode=$Mode;ReportSHA256=$reportSHA;ImporterSHA256=$v6Fingerprint;FenceCount=$fences.Count;DefinitionCount=$finalDefinitions.Count;Executable=[pscustomobject][ordered]@{Path=$powerShellPath;SystemDirectory=$expectedSystemDirectory};Result=$child.Result;Child=$child.Child;ReturnedAuthorityObjects=0}
    }
    if($Mode-ceq'CoherentPreseedProbe'){
        $transaction=&$newTransaction $fixtureBase;try{if(-not[IO.Directory]::Exists($fixtureBase)){[IO.Directory]::CreateDirectory($fixtureBase)|Out-Null};[IO.Directory]::CreateDirectory($transaction.Root)|Out-Null;foreach($name in @('authority.key','authority.anchor','authority.journal','authority.root')){[IO.File]::WriteAllText((Join-Path $transaction.Root $name),('{"coherent":"attacker","name":"'+$name+'"}'),[Text.UTF8Encoding]::new($false))};[IO.File]::WriteAllText($transaction.Pin,'{"coherent":"attacker-pin"}',[Text.UTF8Encoding]::new($false));$child=&$invokeChild 'InitializeAuthority' $transaction.Root $null $implementation 30000 'V8_AUTHORITY_ALREADY_EXISTS';$children.Add($child);return [pscustomobject][ordered]@{Marker='UID0003YU_V8_COHERENT_PRESEED_REFUSED';Mode=$Mode;Children=@($children);PreseedRoot=$transaction.Root;ProtectedEffects=0}}finally{&$removeTransaction $transaction}
    }

    $transaction=&$newTransaction $(if($Mode-in@('ProductionBoundary','ProductionCommit')){$productionBase}else{$fixtureBase});$holds=$null;$leaveTransaction=$Mode-ceq'ProductionCommit'
    try {
        $before=@(&$snapshotTree $transaction.Root $transaction.Pin);if($before.Count){throw 'V8_TRANSACTION_PRESTATE_NOT_EMPTY'}
        $init=&$invokeChild 'InitializeAuthority' $transaction.Root $null $implementation 60000 '';$children.Add($init);$pin=$init.Result.Pin;$pinTuple=&$writeExternalPin $transaction $pin
        $created=@(&$snapshotTree $transaction.Root $transaction.Pin);$createdNames=@($created|ForEach-Object{($_-split'\|')[1]}|ForEach-Object{[IO.Path]::GetFileName($_)}|Sort-Object);$expectedNames=@('authority.anchor','authority.journal','authority.key','authority.root',[IO.Path]::GetFileName($transaction.Pin)|Sort-Object)
        if(($createdNames-join"`n")-cne($expectedNames-join"`n")){throw 'V8_EXACT_INITIALIZE_DELTA_DRIFT'}
        $initialTuples=@{};foreach($name in @('authority.key','authority.anchor','authority.journal','authority.root')){$initialTuples[$name]=&$fileTuple (Join-Path $transaction.Root $name)};$initialTuples['supervisor.pin']=$pinTuple
        $holds=&$openHolds $transaction
        if($Mode-in@('ProductionBoundary','ProductionCommit')){
            $action=$Mode;$child=&$invokeChild $action $transaction.Root $pin $implementation 240000 '';$children.Add($child);return [pscustomobject][ordered]@{Marker=if($Mode-ceq'ProductionCommit'){'UID0003YU_V8_PRODUCTION_COMMIT_COMPLETED'}else{'UID0003YU_V8_PRODUCTION_BOUNDARY_COMPLETED'};Mode=$Mode;ReportSHA256=$reportSHA;ImporterSHA256=$v6Fingerprint;ExternalPin=[pscustomobject][ordered]@{Path=$transaction.Pin;SHA256=$pinTuple.SHA256;HeldAcrossChild=$true};AuthorityRoot=$transaction.Root;Children=@($children);Result=$child.Result;ReturnedAuthorityObjects=0}
        }
        if($Mode-cne'AuthorityRegression'){throw 'V8_INTERNAL_MODE_DRIFT'}
        $hostiles=[Collections.Generic.List[string]]::new();$swapPin=$transaction.Pin+'.swap';$swapRootFile=(Join-Path $transaction.Root 'authority.root.swap');$swapKey=(Join-Path $transaction.Root 'authority.key.swap');$swapTree=$transaction.Root+'.swap'
        $hostiles.Add((&$assertBlockedMove $transaction.Pin $swapPin 'V8_EXTERNAL_PIN_REPLACEMENT_BLOCKED'));$hostiles.Add((&$assertBlockedMove (Join-Path $transaction.Root 'authority.root') $swapRootFile 'V8_ROOT_FILE_REPLACEMENT_BLOCKED'));$hostiles.Add((&$assertBlockedMove (Join-Path $transaction.Root 'authority.key') $swapKey 'V8_SAME_USER_KEY_RECREATION_BLOCKED'))
        $rootBlocked=$false;try{[IO.Directory]::Move($transaction.Root,$swapTree)}catch{$rootBlocked=$true};if(-not$rootBlocked-or-not[IO.Directory]::Exists($transaction.Root)-or[IO.Directory]::Exists($swapTree)){throw 'V8_WHOLE_ROOT_REPLACEMENT_NOT_BLOCKED'};$hostiles.Add('V8_WHOLE_ROOT_REPLACEMENT_BLOCKED')
        $staging=$transaction.Root+'.coherent';[IO.Directory]::CreateDirectory($staging)|Out-Null;foreach($name in @('authority.key','authority.anchor','authority.journal','authority.root')){[IO.File]::Copy((Join-Path $transaction.Root $name),(Join-Path $staging $name))};$coherentBlocked=$false;try{[IO.Directory]::Move($transaction.Root,$transaction.Root+'.held')}catch{$coherentBlocked=$true};if(-not$coherentBlocked){throw 'V8_COHERENT_RECREATION_SWAP_NOT_BLOCKED'};[IO.Directory]::Delete($staging,$true);$hostiles.Add('V8_SAME_USER_COHERENT_RECREATION_BLOCKED')
        $write=&$invokeChild 'RestartWriteTerminal' $transaction.Root $pin $implementation 60000 '';$children.Add($write);$afterWrite=@{};foreach($name in @('authority.key','authority.anchor','authority.journal','authority.root')){$afterWrite[$name]=&$fileTuple (Join-Path $transaction.Root $name)};$afterWrite['supervisor.pin']=&$fileTuple $transaction.Pin
        foreach($name in @('authority.key','authority.root','supervisor.pin')){if($initialTuples[$name].SHA256-cne$afterWrite[$name].SHA256-or$initialTuples[$name].CreationTimeUtcTicks-ne$afterWrite[$name].CreationTimeUtcTicks){throw "V8_IMMUTABLE_AUTHORITY_DELTA:$name"}}
        foreach($name in @('authority.anchor','authority.journal')){if($initialTuples[$name].SHA256-ceq$afterWrite[$name].SHA256){throw "V8_EXPECTED_RESTART_DELTA_MISSING:$name"}}
        $afterNames=@((&$snapshotTree $transaction.Root $transaction.Pin)|ForEach-Object{($_-split'\|')[1]}|ForEach-Object{[IO.Path]::GetFileName($_)}|Sort-Object);if(($afterNames-join"`n")-cne($expectedNames-join"`n")){throw 'V8_RESTART_CREATED_UNAUTHORIZED_ENTRY'};$hostiles.Add('V8_EXACT_RESTART_DELTA_PROVED')
        $verify=&$invokeChild 'RestartVerifyTerminal' $transaction.Root $pin $implementation 60000 '';$children.Add($verify);$hostiles.Add('V8_FRESH_CHILD_RESTART_CONTINUITY_PROVED')
        return [pscustomobject][ordered]@{Marker='UID0003YU_V8_EXTERNAL_AUTHORITY_REGRESSION_PASSED';Mode=$Mode;Hostiles=@($hostiles);ExternalPin=[pscustomobject][ordered]@{Path=$transaction.Pin;SHA256=$pinTuple.SHA256;OutsideRoot=(-not$transaction.Pin.StartsWith($transaction.Root,[StringComparison]::OrdinalIgnoreCase));HeldAcrossFreshChildren=$true};ExactCreatedNames=$createdNames;ExactChangedNames=@('authority.anchor','authority.journal');Children=@($children);ReturnedAuthorityObjects=0}
    } finally {&$closeHolds $holds;if(-not$leaveTransaction){&$removeTransaction $transaction}}
}

function Get-UID0003YUObservedStateV7 {
    $report=[IO.Path]::GetFullPath('E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\0003YU-RankingCategoryRecordRangeCopyConstructDeep-source-quality.md');$canonical=[IO.Path]::GetFullPath('E:\NTK\Resources\NexusTK\NexusTK.exe.i64');$fixture=[IO.Path]::GetFullPath((Join-Path ([Environment]::GetFolderPath([Environment+SpecialFolder]::LocalApplicationData)) 'Temp\UID0003YU-V8-Authority'));$production=[IO.Path]::GetFullPath((Join-Path ([IO.Path]::GetDirectoryName($canonical)) '.UID0003YU-Gate2B-Authority-V8'))
    $hashFile={param([string]$Path)if(-not[IO.File]::Exists($Path)){return '<absent>'};$stream=[IO.File]::Open($Path,[IO.FileMode]::Open,[IO.FileAccess]::Read,[IO.FileShare]::ReadWrite -bor[IO.FileShare]::Delete);$sha=[Security.Cryptography.SHA256]::Create();try{return "$([IO.Path]::GetFullPath($Path))|$($stream.Length)|$(([BitConverter]::ToString($sha.ComputeHash($stream))).Replace('-',''))|$([IO.File]::GetCreationTimeUtc($Path).Ticks)|$([IO.File]::GetLastWriteTimeUtc($Path).Ticks)"}finally{$sha.Dispose();$stream.Dispose()}}.GetNewClosure()
    $tree=[Collections.Generic.List[string]]::new();foreach($base in @($fixture,$production)){if([IO.Directory]::Exists($base)){foreach($entry in @([IO.Directory]::EnumerateFileSystemEntries($base,'*',[IO.SearchOption]::AllDirectories)|Sort-Object)){if([IO.Directory]::Exists($entry)){$tree.Add('D|'+[IO.Path]::GetFullPath($entry))}else{$tree.Add('F|'+(&$hashFile $entry))}}}}
    $searcher=[System.Management.ManagementObjectSearcher]::new('SELECT ProcessId,ParentProcessId,CreationDate,ExecutablePath,Name,SessionId FROM Win32_Process');$workers=[Collections.Generic.List[string]]::new();try{foreach($item in @($searcher.Get())){try{if(([string]$item.Name)-match'^(?i:ida|idat|python|pythonw|powershell|pwsh|cmd).*'){$workers.Add("$($item.ProcessId)|$($item.ParentProcessId)|$($item.CreationDate)|$($item.ExecutablePath)|$($item.Name)|$($item.SessionId)")}}finally{$item.Dispose()}}}finally{$searcher.Dispose()};$workerRows=[string[]]$workers.ToArray();[Array]::Sort($workerRows,[StringComparer]::Ordinal)
    $connections=[Collections.Generic.List[string]]::new();try{$scope=[System.Management.ManagementScope]::new('\\.\root\StandardCimv2');$scope.Connect();$query=[System.Management.ObjectQuery]::new('SELECT LocalAddress,LocalPort,RemoteAddress,RemotePort,State,OwningProcess FROM MSFT_NetTCPConnection WHERE LocalPort = 13337 OR RemotePort = 13337');$network=[System.Management.ManagementObjectSearcher]::new($scope,$query);try{foreach($item in @($network.Get())){try{$connections.Add("$($item.LocalAddress):$($item.LocalPort)|$($item.RemoteAddress):$($item.RemotePort)|$($item.State)|$($item.OwningProcess)")}finally{$item.Dispose()}}}finally{$network.Dispose()}}catch{$connections.Add('NETWORK_OBSERVER_FAILED|'+$_.Exception.GetBaseException().Message)};$connectionRows=[string[]]$connections.ToArray();[Array]::Sort($connectionRows,[StringComparer]::Ordinal)
    $current=[Diagnostics.Process]::GetCurrentProcess();try{$self="$($current.Id)|$($current.StartTime.ToUniversalTime().Ticks)|$($current.MainModule.FileName)|$($current.SessionId)"}finally{$current.Dispose()};$runspace=[Management.Automation.Runspaces.Runspace]::DefaultRunspace;$session=if($null-eq$runspace){'NO_DEFAULT_RUNSPACE'}else{"$($runspace.InstanceId)|$($runspace.RunspaceStateInfo.State)|$($runspace.Availability)"}
    return [pscustomobject][ordered]@{Report=&$hashFile $report;Canonical=&$hashFile $canonical;AuthorityTree=([string[]]$tree.ToArray()-join"`n");HarnessProcess=$self;Workers=($workerRows-join"`n");Port13337=($connectionRows-join"`n");Session=$session}
}

function Invoke-UID0003YUAuthorityHostileSuiteV7 {
    $report=[IO.Path]::GetFullPath('E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\0003YU-RankingCategoryRecordRangeCopyConstructDeep-source-quality.md');$text=[IO.File]::ReadAllText($report,[Text.Encoding]::UTF8);$fences=[regex]::Matches($text,'(?ms)^```powershell\r?\n(?<body>.*?)^```\s*$');$final=@{}
    foreach($fence in $fences){$tokens=$null;$errors=$null;$ast=[Management.Automation.Language.Parser]::ParseInput($fence.Groups['body'].Value,[ref]$tokens,[ref]$errors);if($errors.Count){throw 'V8_SUITE_PARSE_FAILURE'};foreach($statement in $ast.EndBlock.Statements){if($statement-is[Management.Automation.Language.FunctionDefinitionAst]){$body=[string]$statement.Body.Extent.Text;$body=$body.Substring(1,$body.Length-2);$parameters=[Collections.Generic.List[string]]::new();foreach($parameter in $statement.Parameters){$parameters.Add([string]$parameter.Extent.Text)};$final[$statement.Name]=if($parameters.Count){'param('+($parameters.ToArray()-join',')+")`n"+$body}else{$body}}}}
    $entry=[scriptblock]::Create([string]$final['Import-UID0003YUProductionPackageV7']);$observer=[scriptblock]::Create([string]$final['Get-UID0003YUObservedStateV7']);$hashText={param([string]$Value)$sha=[Security.Cryptography.SHA256]::Create();try{return([BitConverter]::ToString($sha.ComputeHash([Text.Encoding]::UTF8.GetBytes($Value)))).Replace('-','')}finally{$sha.Dispose()}}.GetNewClosure();$results=[Collections.Generic.List[object]]::new();$initial=&$observer
    $assertChildren={param($Value,[string]$Label)$receipts=[Collections.Generic.List[object]]::new();if($null-ne$Value.PSObject.Properties['Child']){$receipts.Add($Value.Child)};if($null-ne$Value.PSObject.Properties['Children']){foreach($wrapper in @($Value.Children)){if($null-ne$wrapper.PSObject.Properties['Child']){$receipts.Add($wrapper.Child)}}};foreach($child in $receipts){if(-not$child.ProcessTreeComplete-or-not$child.RootRetired-or-not$child.DescendantsRetired-or-not$child.StdOutDrainCompleted-or-not$child.StdErrDrainCompleted){throw "$Label|INCOMPLETE_PROCESS_RETIREMENT"};if($child.TimedOut-ne$child.ExpectedTermination){throw "$Label|TIMEOUT_VERDICT_DRIFT"};if(-not$child.ExpectedTermination-and$child.ExitCode-ne0){throw "$Label|CHILD_EXIT_DRIFT"}};return @($receipts)}.GetNewClosure()
    $run={param([string]$Label,[scriptblock]$Body)$before=&$observer;$value=&$Body;$after=$null;for($i=0;$i-lt60;$i++){Start-Sleep -Milliseconds 250;$candidate=&$observer;if($candidate.Workers-ceq$before.Workers-and$candidate.Port13337-ceq$before.Port13337){$after=$candidate;break}};if($null-eq$after){$after=&$observer};$drift=[Collections.Generic.List[string]]::new();foreach($field in @('Report','Canonical','AuthorityTree','HarnessProcess','Workers','Port13337','Session')){if([string]$before.$field-cne[string]$after.$field){$drift.Add($field)}};if($drift.Count){throw "$Label|VERDICT_EFFECT_DRIFT|$($drift-join',')"};$children=&$assertChildren $value $Label;$code=if($null-ne$value.PSObject.Properties['Marker']){[string]$value.Marker}else{[string]$value};$results.Add([pscustomobject][ordered]@{Label=$Label;Code=$code;AllObservedFieldsStable=$true;Children=$children})}.GetNewClosure()
    $rejectUnknown={param([string]$Label,[scriptblock]$Body,[string]$Parameter)$message='';try{$null=&$Body}catch{$message=$_.Exception.GetBaseException().Message};if($message-notmatch([regex]::Escape($Parameter))){throw "$Label|WRONG_REJECTION:$message"};return [pscustomobject]@{Marker="V8_CALLER_PARAMETER_REJECTED:$Parameter"}}.GetNewClosure()
    &$run 'V8_ALTERNATE_REPORT_REJECTED' {&$rejectUnknown 'V8_ALTERNATE_REPORT_REJECTED' {&$entry -Mode Preflight -ReportPath 'C:\forged\report.md'} 'ReportPath'}
    &$run 'V8_COHERENT_CALLER_AUTHORITY_REJECTED' {&$rejectUnknown 'V8_COHERENT_CALLER_AUTHORITY_REJECTED' {&$entry -Mode Preflight -SupervisorAuthority ([pscustomobject]@{Root='forged';Pin='forged'})} 'SupervisorAuthority'}
    &$run 'V8_ALTERNATE_ROOT_REJECTED' {&$rejectUnknown 'V8_ALTERNATE_ROOT_REJECTED' {&$entry -Mode Preflight -RootPath 'C:\forged\root'} 'RootPath'}
    &$run 'V8_ALTERNATE_B0_REJECTED' {&$rejectUnknown 'V8_ALTERNATE_B0_REJECTED' {&$entry -Mode Preflight -BackupPath 'C:\forged\b0'} 'BackupPath'}
    &$run 'V8_ARBITRARY_DIGEST_REJECTED' {&$rejectUnknown 'V8_ARBITRARY_DIGEST_REJECTED' {&$entry -Mode Preflight -ImplementationContractSHA256 ('D'*64)} 'ImplementationContractSHA256'}
    &$run 'V8_DIRECT_ESTABLISH_REJECTED' {$message='';try{$null=&$entry -Mode Establish}catch{$message=$_.Exception.GetBaseException().Message};if($message-notmatch'Establish'){throw "V8_ESTABLISH_WRONG_REJECTION:$message"};[pscustomobject]@{Marker='V8_DIRECT_ESTABLISH_REJECTED'}}
    &$run 'V8_REGISTRY_REPLACEMENT_REJECTED' {&$rejectUnknown 'V8_REGISTRY_REPLACEMENT_REJECTED' {&$entry -Mode Preflight -Registry ([Collections.Generic.Dictionary[guid,object]]::new())} 'Registry'}
    &$run 'V8_IMPORTER_FUNCTION_SHADOW_IGNORED' {$existing=Get-Item -LiteralPath 'Function:\Import-UID0003YUProductionPackageV6' -ErrorAction SilentlyContinue;try{Set-Item -LiteralPath 'Function:\global:Import-UID0003YUProductionPackageV6' -Value {throw 'FORGED_V6_IMPORTER_CALLED'} -Force;$receipt=&$entry -Mode Preflight;if($receipt.Result.Marker-cne'UID0003YU_V8_PREFLIGHT_READY'){throw 'V8_PINNED_IMPORTER_REDIRECTED'};return $receipt}finally{if($null-eq$existing){Remove-Item -LiteralPath 'Function:\global:Import-UID0003YUProductionPackageV6' -Force -ErrorAction SilentlyContinue}else{Set-Item -LiteralPath 'Function:\global:Import-UID0003YUProductionPackageV6' -Value ([scriptblock]::Create([string]$existing.Definition)) -Force}}}
    &$run 'V8_IMPORTER_ALIAS_SHADOW_IGNORED' {$existing=Get-Alias -Name Import-UID0003YUProductionPackageV6 -ErrorAction SilentlyContinue;try{Set-Alias -Name Import-UID0003YUProductionPackageV6 -Value Write-Output -Scope Global -Force;$receipt=&$entry -Mode Preflight;if($receipt.ImporterSHA256-cne'9766C4D8482F2607DB6E71014A2E30E3CF28B38D1F6506A85819BCD9EB01CAD4'){throw 'V8_ALIAS_SHADOW_REDIRECTED'};return $receipt}finally{if($null-eq$existing){Remove-Item -LiteralPath 'Alias:\Import-UID0003YUProductionPackageV6' -Force -ErrorAction SilentlyContinue}else{Set-Alias -Name Import-UID0003YUProductionPackageV6 -Value $existing.Definition -Scope Global -Force}}}
    &$run 'V8_PARENT_CLR_AUTHORITY_ABSENT' {$before=@([AppDomain]::CurrentDomain.GetAssemblies()|ForEach-Object{$_.GetTypes()}|Where-Object{$_.FullName-like'UID0003YUSealedBoundaryV8_*'}|ForEach-Object{$_.AssemblyQualifiedName});$receipt=&$entry -Mode Preflight;$after=@([AppDomain]::CurrentDomain.GetAssemblies()|ForEach-Object{$_.GetTypes()}|Where-Object{$_.FullName-like'UID0003YUSealedBoundaryV8_*'}|ForEach-Object{$_.AssemblyQualifiedName});if(($before-join'|')-cne($after-join'|')){throw 'V8_PARENT_CLR_STATE_CREATED'};if($receipt.ReturnedAuthorityObjects-ne0){throw 'V8_AUTHORITY_RETURNED'};return $receipt}
    &$run 'V8_ENVIRONMENT_SUBSTITUTION_IGNORED' {$saved=@{SystemRoot=$env:SystemRoot;WINDIR=$env:WINDIR;PATH=$env:PATH;PSModulePath=$env:PSModulePath};try{$env:SystemRoot='C:\forged';$env:WINDIR='C:\forged';$env:PATH='C:\forged';$env:PSModulePath='C:\forged';$receipt=&$entry -Mode Preflight;if($receipt.Child.Executable-cne'C:\Windows\System32\WindowsPowerShell\v1.0\powershell.exe'){throw 'V8_ENVIRONMENT_REDIRECTED_EXECUTABLE'};return $receipt}finally{$env:SystemRoot=$saved.SystemRoot;$env:WINDIR=$saved.WINDIR;$env:PATH=$saved.PATH;$env:PSModulePath=$saved.PSModulePath}}
    &$run 'V8_COHERENT_PRESEED_REFUSED' {$receipt=&$entry -Mode CoherentPreseedProbe;if($receipt.Marker-cne'UID0003YU_V8_COHERENT_PRESEED_REFUSED'){throw 'V8_PRESEED_RECEIPT_DRIFT'};return $receipt}
    &$run 'V8_EXTERNAL_PIN_ROOT_RESTART_REGRESSION' {$receipt=&$entry -Mode AuthorityRegression;if($receipt.Marker-cne'UID0003YU_V8_EXTERNAL_AUTHORITY_REGRESSION_PASSED'-or$receipt.Hostiles.Count-ne7-or-not$receipt.ExternalPin.OutsideRoot-or-not$receipt.ExternalPin.HeldAcrossFreshChildren){throw 'V8_AUTHORITY_REGRESSION_DRIFT'};return $receipt}
    &$run 'V8_DURABLE_REGRESSION_PROCESS_ISOLATED' {$receipt=&$entry -Mode DurableRegression;if($receipt.Result.Marker-cne'UID0003YU_V6_DURABLE_SHARED_PATH_SUITE_PASSED'-or$receipt.Result.Count-ne13){throw 'V8_DURABLE_RECEIPT_DRIFT'};return $receipt}
    &$run 'V8_SHARED_REGRESSION_PROCESS_ISOLATED' {$receipt=&$entry -Mode SharedRegression;if($receipt.Result.Marker-cne'UID0003YU_V6_SHARED_REGRESSION_PASSED'-or$receipt.Result.Count-ne5){throw 'V8_SHARED_RECEIPT_DRIFT'};return $receipt}
    &$run 'V8_TIMEOUT_TREE_RETIRED' {$receipt=&$entry -Mode TreeTimeoutProbe;if(-not$receipt.Child.TimedOut-or-not$receipt.Child.ProcessTreeComplete){throw 'V8_TIMEOUT_TREE_RECEIPT_DRIFT'};return $receipt}
    &$run 'V8_OUTPUT_STALL_DRAINED' {$receipt=&$entry -Mode OutputStallProbe;if(-not$receipt.Child.StdOutDrainCompleted-or-not$receipt.Child.DescendantsRetired){throw 'V8_OUTPUT_STALL_RECEIPT_DRIFT'};return $receipt}
    &$run 'V8_INHERITED_PIPE_RETIRED' {$receipt=&$entry -Mode InheritedPipeProbe;if(-not$receipt.Child.StdOutDrainCompleted-or-not$receipt.Child.DescendantsRetired){throw 'V8_INHERITED_PIPE_RECEIPT_DRIFT'};return $receipt}
    &$run 'V8_IMMEDIATE_PARENT_EXIT_TREE_RETIRED' {$receipt=&$entry -Mode ImmediateParentExitProbe;if(-not$receipt.Child.ProcessTreeComplete-or$receipt.Child.DescendantGenerations.Count-lt1){throw 'V8_IMMEDIATE_PARENT_RECEIPT_DRIFT'};return $receipt}
    &$run 'V8_FAILED_KILL_GENERATION_REFUSED' {$receipt=&$entry -Mode FailedKillProbe;if(-not$receipt.Child.GenerationMismatchRefused-or-not$receipt.Child.ProcessTreeComplete){throw 'V8_FAILED_KILL_RECEIPT_DRIFT'};return $receipt}
    &$run 'V8_SURVIVING_DESCENDANT_RETIRED' {$receipt=&$entry -Mode SurvivingDescendantProbe;if($receipt.Child.DescendantGenerations.Count-lt1-or-not$receipt.Child.DescendantsRetired){throw 'V8_SURVIVOR_RECEIPT_DRIFT'};return $receipt}
    &$run 'V8_CALLER_RECEIPT_MUTATION_NO_AUTHORITY' {$receipt=&$entry -Mode Preflight;$receipt.ReportSHA256='F'*64;$again=&$entry -Mode Preflight;if($again.ReportSHA256-ceq('F'*64)){throw 'V8_RECEIPT_MUTATION_REDIRECTED'};return $again}
    &$run 'V8_REGISTRY_RESET_SURFACE_ABSENT' {$types=@([AppDomain]::CurrentDomain.GetAssemblies()|ForEach-Object{$_.GetTypes()}|Where-Object{$_.FullName-like'UID0003YUSealedBoundaryV8_*'});if($types.Count){throw 'V8_PARENT_REGISTRY_TYPE_PRESENT'};[pscustomobject]@{Marker='V8_NO_PARENT_REGISTRY_TO_RESET'}}
    $finalState=&$observer;foreach($field in @('Report','Canonical','AuthorityTree','HarnessProcess','Workers','Port13337','Session')){if([string]$initial.$field-cne[string]$finalState.$field){throw "V8_FINAL_EFFECT_DRIFT:$field"}}
    $labels=@($results|ForEach-Object{$_.Label});if($labels.Count-ne24-or@($labels|Sort-Object -Unique).Count-ne24){throw "V8_HOSTILE_LABEL_DRIFT:$($labels.Count)"};$stableRows=@($results|ForEach-Object{"$($_.Label)|$($_.Code)|$($_.AllObservedFieldsStable)"});return [pscustomobject][ordered]@{Marker='UID0003YU_V8_EXTERNAL_AUTHORITY_AND_TREE_SUITE_PASSED';Count=$results.Count;Labels=$labels;ResultSHA256=&$hashText ($stableRows-join"`n");IndependentFinalState=$finalState;Results=@($results)}
}
# UID0003YU FINAL V8 EXTERNAL-PIN PROCESS-BOUNDARY END
~~~
