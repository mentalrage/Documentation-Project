<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\0003YS-RankingCategoryRecordRangeDestroyUserEntries-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003YS-RankingCategoryRecordRangeDestroyUserEntries-source-quality.md](0003YS-RankingCategoryRecordRangeDestroyUserEntries-source-quality.md)
- Cleanup reason: executable PowerShell is prohibited in B-agent research reports; valid research and reconstructed C++ remain in the original report.
- Preservation: every removed block below is copied verbatim, with its original language and start line recorded.
- Authority: this file is not a B-agent research report, claims no target coverage, and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original start line: `302`
- Language: `powershell`
- Preserved body SHA256: `E9486B94D20A8CC970943B0CA61047C5819754C2C9658C467038434BF6AEF017`
- Original fenced-block characters: `3055`

~~~~powershell
function Get-UID0003YSWorkerIdentity([int]$WorkerPid) {
    $p = Get-CimInstance Win32_Process -Filter "ProcessId = $WorkerPid"
    if ($null -eq $p) { return $null }
    [pscustomobject]@{
        Pid = [int]$p.ProcessId
        CreationDate = [string]$p.CreationDate
        ExecutablePath = [string]$p.ExecutablePath
        CommandLine = [string]$p.CommandLine
    }
}

function Test-UID0003YSSameWorker($Left, $Right) {
    return ($null -ne $Left -and $null -ne $Right -and
        $Left.Pid -eq $Right.Pid -and
        $Left.CreationDate -ceq $Right.CreationDate -and
        $Left.ExecutablePath -ceq $Right.ExecutablePath -and
        $Left.CommandLine -ceq $Right.CommandLine)
}

function Get-UID0003YSExclusiveReadIdentity([string]$Path) {
    $stream = [System.IO.File]::Open(
        $Path,
        [System.IO.FileMode]::Open,
        [System.IO.FileAccess]::Read,
        [System.IO.FileShare]::None)
    try {
        $sha = [System.Security.Cryptography.SHA256]::Create()
        try {
            $stream.Position = 0
            $digest = [BitConverter]::ToString($sha.ComputeHash($stream)).Replace('-', '')
            [pscustomobject]@{ Length = $stream.Length; SHA256 = $digest }
        } finally {
            $sha.Dispose()
        }
    } finally {
        $stream.Dispose()
    }
}

# Values captured immediately after this exact worker opened.
$expectedWorker = Get-UID0003YSWorkerIdentity -WorkerPid $workerPid
if ($null -eq $expectedWorker -or [string]::IsNullOrWhiteSpace($expectedWorker.CreationDate) -or
    [string]::IsNullOrWhiteSpace($expectedWorker.ExecutablePath) -or
    [string]::IsNullOrWhiteSpace($expectedWorker.CommandLine)) {
    throw 'UID0003YS worker identity is incomplete; stop.'
}
$recordedEndpoints = @(Get-NetTCPConnection -State Listen -OwningProcess $workerPid -ErrorAction SilentlyContinue |
    Select-Object LocalAddress, LocalPort)

# WD0: no save call occurs here.
$currentWorker = Get-UID0003YSWorkerIdentity -WorkerPid $workerPid
if (Test-UID0003YSSameWorker $expectedWorker $currentWorker) {
    Stop-Process -Id $workerPid -Force -ErrorAction Stop
    Wait-Process -Id $workerPid -Timeout 30 -ErrorAction SilentlyContinue
} elseif ($null -ne $currentWorker) {
    $pidReuseProven = -not (Test-UID0003YSSameWorker $expectedWorker $currentWorker)
    if (-not $pidReuseProven) { throw 'UID0003YS PID identity is ambiguous; stop.' }
    # Never terminate a different process that reused the PID.
}
Start-Sleep -Milliseconds 500
$afterWorker = Get-UID0003YSWorkerIdentity -WorkerPid $workerPid
if (Test-UID0003YSSameWorker $expectedWorker $afterWorker) {
    throw 'UID0003YS exact worker process is still alive; stop.'
}
foreach ($endpoint in $recordedEndpoints) {
    $liveEndpoint = Get-NetTCPConnection -State Listen -ErrorAction SilentlyContinue |
        Where-Object { $_.LocalAddress -eq $endpoint.LocalAddress -and $_.LocalPort -eq $endpoint.LocalPort }
    if ($liveEndpoint) { throw 'UID0003YS recorded worker endpoint is still live or has ambiguous reuse; stop.' }
}
~~~~

## Removed Block CLEANUP-20260813-0003YS-OUTSIDE21-RUNBOOK

Source: [0003YS-RankingCategoryRecordRangeDestroyUserEntries-source-quality.md](0003YS-RankingCategoryRecordRangeDestroyUserEntries-source-quality.md)

This archive is non-authoritative and must never be executed. It preserves the exact report lines removed during supervisor cleanup.

<!-- BEGIN CLEANUP-20260813-0003YS-OUTSIDE21-RUNBOOK -->
59: 7. The candidate Gate 2B package requires mandatory no-save disposal of a disposable preflight worker before closed-disk P0/B0 capture, then opens a separate fresh exact-P0 transaction worker. A stale inactive registry row is permitted only when `is_active:false`, the exact recorded worker PID is proven exited or safely PID-reused by process identity, every recorded worker endpoint is gone, no unexpected canonical worker is live, and a read-only exclusive `FileShare.None` identity probe succeeds. Its frozen worker excludes every analysis-producing `analyze_function`, `func_profile`, `decompile`, and `force_recompile` call, version-locks the current rename/comment implementation, uses `pure:true` for I01 so no `/vibe/` link or decompiler refresh can occur, uses the specialized non-pure stack path for I02/I03 with exact frame-only poststates, uses the regular-function-only comment endpoint for I05, and otherwise relies on inspection-only RB-S and exact S0-S13 deltas. Non-P0 D1 classification still requires complete transaction attribution, identity-gated restore, and disposed-verifier exclusive persistence rehash before any credit.
66: - Ordinary callback readback and independent Gate 2A are complete at `22/22`. Primary-supervisor work remains bounded by the literal C3YS-023 through C3YS-033 actor contracts: dynamically bind current IDA authority and prestates for Gate2B, submit the repaired inactive-row-tolerant worker-disposal/P0-B0/fresh-transaction package for fresh Gate 1 before C3YS-025 through C3YS-030 may run, and reread current manual/generated rows to avoid clobbering the independent UID0003YR lane.
138: | C3YS-025 | 0003YS | Rename `sub_45D5C0` to the descriptive database name with collision-safe dry-run, literal `pure:true`, no `/vibe/` or decompiler-refresh side effects, and exact readback. | very high | exact live prestate/collision absence plus current endpoint implementation | IDA I01 | primary supervisor Gate2B | incorporate | proposed |
143: | C3YS-030 | 0003YS | Enforce P1-P11 through endpoint-schema/source identity lock, pure function rename, specialized bounded stack renames, channel-specific comment handling, no-save disposal of every worker using inactive-row/live-process/endpoint/PID-identity checks plus exclusive `FileShare.None` probes, closed-disk P0/B0 proof, separate fresh exact-P0 transaction, inspection-only RB-S/S0-S13, one save, attribution-gated D1, identity-gated restore, and disposed-verifier persistence rehash. | certain | repaired current-schema transaction, exact installed implementation, and dated no-save rollback below | IDA transaction/protections | primary supervisor Gate2B | incorporate | proposed |
350: - Is the supervisor IDA package accepted after the failed preflight, close-schema rejection, and rename-side-effect audit? Not yet. The repaired candidate requires a current tools/source identity lock; mandatory preflight S0; `WD0` no-save disposal with expected row absent or inactive, exact worker/PID-reuse/process/endpoint proof and exclusive `FileShare.None` identity; closed-disk P0 and nonexistent byte-identical B0; a separate fresh exact-P0 transaction worker that repeats S0; `pure:true` function rename with no `/vibe/`/refresh result; specialized frame-bounded stack renames with `pure:false`; channel-specific function-comment handling; inspection-only frozen RB-S; complete A1-A7 attribution before any non-P0 observation can be D1; and verifier `WD0` plus exact exclusive D1 rehash before credit. Any schema/source drift, unexpected side effect, active row, live/ambiguous PID or endpoint, unexpected canonical worker, probe failure, or disk drift stops/waits. Fresh Gate 1 must validate this literal ordering; C3YS-025 through C3YS-030 remain externally uncredited.
463: - [ ] C3YS-025 Rename `sub_45D5C0` to the descriptive database name with collision-safe dry-run, literal `pure:true`, no `/vibe/` or decompiler-refresh side effects, and exact readback.
473: - [ ] C3YS-030 Enforce P1-P11 through endpoint-schema/source identity lock, pure function rename, specialized bounded stack renames, channel-specific comment handling, no-save disposal of every worker using inactive-row/live-process/endpoint/PID-identity checks plus exclusive `FileShare.None` probes, closed-disk P0/B0 proof, separate fresh exact-P0 transaction, inspection-only RB-S/S0-S13, one save, attribution-gated D1, identity-gated restore, and disposed-verifier persistence rehash.
<!-- END CLEANUP-20260813-0003YS-OUTSIDE21-RUNBOOK -->

## Removed Block CLEANUP-20260813-0003YS-SECTION21

Source: [0003YS-RankingCategoryRecordRangeDestroyUserEntries-source-quality.md](0003YS-RankingCategoryRecordRangeDestroyUserEntries-source-quality.md)

This archive is non-authoritative and must never be executed. It preserves the exact report text removed during supervisor cleanup.

<!-- BEGIN CLEANUP-20260813-0003YS-SECTION21 -->
## IDA Rename / Type / Comment Recommendations

All actions are primary-supervisor-only. B005 performed read-only calls only. Every request below is a literal MCP `tool {complete-object}` request. Replace only the quoted database placeholder with the session ID returned by the immediately preceding `idb_list`; never substitute this report's dated session name, PID, or transport ID.

### Current endpoint schema and implementation feasibility lock

- The supervisor's controlled-restart live `tools/list` audit on `2026-08-06` confirmed that `rename` exposes batch option `pure:true` with the exact contract `change only the IDA name and skip function-directory and decompiler refresh side effects`, and that `set_address_comments` is available for regular disassembly/address comments without Hex-Rays. MCP health and the active worker are external dated capability evidence only; no UID0003YS action was performed.
- The corresponding installed implementation identities are `C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp\ida_mcp\api_modify.py`, SHA256 `161B314A14DAAA34C718176444292597BBB7498FA80158E25C358542BC16D1B8`, 51,759 bytes, and `utils.py`, SHA256 `5139910EA7496549A31EDD6F9EEE7B033DA16504E4F0D19C8052EC9ED1C62069`, 43,500 bytes. Before Gate 2B, the primary supervisor must reread `tools/list` and these exact files. A missing option/endpoint, schema drift, implementation-hash drift, or behavior mismatch stops before transaction-worker creation and returns this same report for repair.
- For function renames, `pure:true` still performs collision validation and `idaapi.set_name`, but the implementation cannot call `_place_func_in_vibe_dir` or `refresh_decompiler_ctext`; dry-run returns before `idaapi.set_name`. I01 therefore uses `pure:true`, and its response must contain no `dir` or `dir_error` field. This is the supported literal alternative to accepting `/vibe/` or decompiler side effects.
- Pure mode deliberately rejects stack members with `pure rename does not support stack members`. I02/I03 therefore use explicit `pure:false` and only the specialized stack path, which resolves the physical frame member and calls `ida_frame.define_stkvar`; that path has no explicit function-directory or decompiler-refresh call. Native frame normalization is not assumed harmless: every dry-run/rename is followed by RB-S and must match the exact R0-R4 frame transition, with every other name/type/row protected.
- I05 intends the regular function-comment channel, so it uses `set_function_comments`. The inspected implementation calls only `idc.set_func_cmt(function_start, comment, False)` and does not invoke Hex-Rays. `set_address_comments` calls only `idaapi.set_cmt(address, comment, False)` and is the required endpoint for any future regular address-comment set or clear, but no address-comment change is authorized in I01-I05. Address regular, address repeatable, and function repeatable remain protected and blank. Generic/decompiler comment endpoints are forbidden in the frozen transaction.
- Every literal `idb_open` in this package sets `run_auto_analysis:false`. No current-schema or source audit in this repair mutates, saves, starts, stops, or reuses the active IDB.

### Literal current target prestate

- Report-time live evidence used session `b005-uid0001ny-postsave-reopen`, PID `24380`, and canonical disk `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, 143,196,991 bytes, SHA256 `115491A99AE02621692E9F7AF4C9E3F011E77DD9678AF996A39A86AA02837695`. These are dated research snapshots, not permanent Gate 2B authority.
- Dated `2026-08-05T21:05:00-04:00` supervisor failure evidence used canonical SHA256 `29AA9F5B584D9C771DEB25D7C0B7B9A4B8641C0B19B8AAA860B0C66CD591028D`, size 143,197,232. The exact raw prestate below was present before the failed attempt and was independently restored in fresh session `supervisor-readonly-post-b005-gate2fail` after unsaved PID `20404` was discarded. Session/PID are dated transaction evidence only; every new Gate 2B must bind fresh authority.
- Function item `I01`: `[0x0045d5c0,0x0045d5eb)`, 43 bytes, code, name `sub_45D5C0`, type `void __stdcall(int, int)`, 18 instructions, four blocks, complexity three, body SHA256 `F0B538E7F49394DCC6AFEA6B6041D072FA9971DD4C711B8C61416B28F35574FC`.
- Physical frame `I02/I03/I04`: exactly `__saved_registers +0x8 size4 _DWORD`; `__return_address +0xc size4 _UNKNOWN *`; `arg_0 +0x10 size4 _DWORD`; `arg_4 +0x14 size4 _DWORD`; no other rows.
- Comment prestate `I05`: address regular absent, address repeatable absent, function regular absent, function repeatable absent.
- Xrefs/callees: one incoming code xref at `0x45d187`, no incoming data xrefs; one real external call at `0x45d5d6` to `RankingUserEntryVectorDestroy`.
- Collision prestate: lookup for `RankingCategoryRecordRangeDestroyUserEntries` returns not found.

### Literal mandatory disposable preflight, closed P0/B0, and fresh transaction-worker preconditions

Every attempt begins in a mandatory disposable preflight worker opened genuinely fresh from canonical path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. This worker establishes current health, path, PID/session identity, raw S0, collision absence, and any optional diagnostic evidence. It never becomes the transaction worker and never receives action credit.

~~~text
idb_open {"input_path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","mode":"force_headless","run_auto_analysis":false,"build_caches":true,"init_hexrays":true,"idle_ttl_sec":3600,"preferred_session_id":"b005-uid0003ys-preflight-<timestamp>"}
idb_list {}
server_health {"database":"<fresh-preflight-session-id-returned-by-idb_open-or-idb_list>"}
~~~

The preflight worker must be healthy, Hex-Rays ready, bound to the exact canonical path, and the sole canonical-bound worker. A bounded read may proceed with `auto_analysis_ready:false`, but any unavailable or malformed result stops. Run inspection-only RB-S below and require raw S0. If any optional analysis-producing diagnostic is necessary, run only the following requests in this same disposable preflight worker after the raw S0 capture:

~~~text
analyze_function {"addr":"0x0045d5c0","include_asm":false,"database":"<fresh-preflight-session-id>"}
func_profile {"queries":[{"addr":"0x0045d5c0","offset":0,"count":1,"sort_by":"addr","descending":false,"include_lists":true,"max_items":100,"include_prototype":true},{"addr":"0x0045cf50","offset":0,"count":1,"sort_by":"addr","descending":false,"include_lists":true,"max_items":500,"include_prototype":true},{"addr":"0x0045d5f0","offset":0,"count":1,"sort_by":"addr","descending":false,"include_lists":true,"max_items":100,"include_prototype":true}],"database":"<fresh-preflight-session-id>"}
decompile {"addr":"0x0045d5c0","include_addresses":true,"database":"<fresh-preflight-session-id>"}
decompile {"addr":"0x0045cf50","include_addresses":true,"database":"<fresh-preflight-session-id>"}
force_recompile {"items":{"addr":"0x0045d5c0"},"database":"<fresh-preflight-session-id>"}
~~~

Whether diagnostics run or not, dispose the exact preflight worker without save using literal worker-disposal contract `WD0` below. Current MCP exposes no session-close endpoint. `idb_list` may retain the exact session as an inactive stale registry row (`is_active:false`, including `owned:true` / `adopted:true`); row persistence is not a live worker and is not a failure. Closed-worker proof instead requires all of the following: the expected row is absent or exactly inactive; no canonical-bound row is `is_active:true`; the exact recorded worker PID/process identity is gone or an unambiguous different-process PID reuse is proven; no recorded worker listener endpoint remains; no unexpected canonical worker process is live; and the read-only exclusive `FileShare.None` identity probe succeeds. Any active row, same worker process still alive, ambiguous PID identity, surviving or ambiguously reused endpoint, unexpected canonical worker, probe failure, or disk drift stops/waits before P0/B0.

Immediately after each worker opens, record the worker PID plus non-null `CreationDate`, `ExecutablePath`, and `CommandLine` from `Win32_Process`, and record every listener endpoint owned by that PID. Missing or ambiguous identity fields stop before the worker may be used. `WD0` never calls `idb_save`; for the transaction worker it runs only after the report's single explicit save attempt.

> Removed executable PowerShell block R001; preserved verbatim in [0003YS-RankingCategoryRecordRangeDestroyUserEntries-source-quality-removed.md](0003YS-RankingCategoryRecordRangeDestroyUserEntries-source-quality-removed.md).

After `WD0`, issue the literal read-only registry query below. The expected row may be absent or remain only with `is_active:false`; `owned:true` / `adopted:true` do not change that disposition. Any `is_active:true` canonical row or any unexpected canonical worker row/process stops. Then call `Get-UID0003YSExclusiveReadIdentity` on the canonical IDB. Failure to acquire the exclusive read handle is a live-writer/ambiguous-lock condition and stops/waits; success is the closed-disk authority probe.

~~~text
idb_list {}
~~~

Only after `WD0`, the inactive-or-absent registry check, endpoint/process proof, and successful exclusive probe may the supervisor capture closed-disk authority P0 and create backup B0. The backup path must be nonexistent before copy, and B0 must be byte-identical to P0:

> Removed executable PowerShell block R002; preserved verbatim in [0003YS-RankingCategoryRecordRangeDestroyUserEntries-source-quality-removed.md](0003YS-RankingCategoryRecordRangeDestroyUserEntries-source-quality-removed.md).

Only after closed P0/B0 proof may the supervisor open a separate fresh transaction worker from the exact P0 path. Record its unique session/PID plus complete process identity and listener endpoints, require it to be the sole live canonical-bound worker, require current disk and B0 still equal exact P0, then repeat complete inspection-only RB-S and require S0 before any dry-run or mutation. The preflight registry row may remain only inactive; its exact process and endpoints must remain gone.

~~~text
idb_open {"input_path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","mode":"force_headless","run_auto_analysis":false,"build_caches":true,"init_hexrays":true,"idle_ttl_sec":3600,"preferred_session_id":"b005-uid0003ys-transaction-<timestamp>"}
idb_list {}
server_health {"database":"<fresh-transaction-session-id-returned-by-idb_open-or-idb_list>"}
~~~

> Removed executable PowerShell block R003; preserved verbatim in [0003YS-RankingCategoryRecordRangeDestroyUserEntries-source-quality-removed.md](0003YS-RankingCategoryRecordRangeDestroyUserEntries-source-quality-removed.md).

### Literal worker-disposal, disk-readback, and restore primitives

The transaction worker must be disposed under `WD0` without an additional save before any post-save authority hash, before opening a persistence verifier, and before any B0 restore. The stale registry row may persist only inactive; the exact process and recorded endpoints must be gone, no live or ambiguous PID/canonical worker may exist, and the exclusive read identity probe must succeed. No post-save authority hash or restore is valid while a canonical worker or writer may remain live. Closed P0 creation occurred before this worker opened; the S12 pre-save concurrency hash is the only disk hash permitted while it remains open and is not a post-save persistence claim.

Only after transaction-worker `WD0`, inactive-or-absent registry proof, PID/process/endpoint proof, successful exclusive probe, and confirmation that no competing canonical writer appeared may the supervisor read the immediate canonical post-save observation:

> Removed executable PowerShell block R004; preserved verbatim in [0003YS-RankingCategoryRecordRangeDestroyUserEntries-source-quality-removed.md](0003YS-RankingCategoryRecordRangeDestroyUserEntries-source-quality-removed.md).

The observed pair becomes transaction-attributable D1 only when all seven attribution facts are recorded: A1 the mandatory preflight worker received no save, `WD0` proved its exact process/endpoints gone or unambiguous PID reuse, its registry row absent or inactive, no live canonical worker, and a successful exclusive P0 probe before B0; A2 B0 was created at a nonexistent path and verified exact P0; A3 one separately opened fresh transaction worker was the sole live canonical-bound worker and opened over exact P0; A4 the immediate S12 pre-save concurrency hash was exact P0; A5 exactly one `idb_save` attempt occurred; A6 the exact transaction worker then underwent `WD0`, leaving only an absent/inactive row, no exact process/endpoint, no ambiguous PID or live canonical worker, and a successful exclusive disk probe; and A7 the exclusive closed-disk observation was captured immediately with no competing writer/session process. Only then assign `$d1Size = $closedObservedSize`, `$d1Sha = $closedObservedSha`, and `$d1AttributionComplete = $true`. If any attribution fact is absent, a non-P0 observation is U1, an unknown/third identity rather than D1, and restore is forbidden. An explicit save failure does not weaken this rule.

Restore is permitted only after the transaction worker and any failed persistence-verifier worker have undergone `WD0`, their rows are absent or inactive, their exact processes/endpoints are gone, no live/ambiguous PID or canonical worker exists, and an exclusive identity probe succeeds; A1-A7 must also prove D1 attribution. Immediately before restore, an exclusive canonical identity must equal exact P0 or exact attributed D1; U1, handle-probe failure, active/ambiguous worker state, or any third identity stops without restore. If current disk already equals P0, no copy is performed. B0 must still equal P0 before replacement. After any replacement, acquire a new exclusive identity and require exact P0 before a fresh raw-S0 reopen:

> Removed executable PowerShell block R005; preserved verbatim in [0003YS-RankingCategoryRecordRangeDestroyUserEntries-source-quality-removed.md](0003YS-RankingCategoryRecordRangeDestroyUserEntries-source-quality-removed.md).

### Literal candidate inspection-only frozen-state readback bundle RB-S

~~~text
lookup_funcs {"queries":["0x0045d5c0","RankingCategoryRecordRangeDestroyUserEntries","0x0045cf50","0x0045d5f0"],"database":"<active-session-id-from-current-idb_list>"}
disasm {"addr":"0x0045d5c0","max_instructions":100,"offset":0,"include_total":true,"database":"<active-session-id-from-current-idb_list>"}
disasm {"addr":"0x0045cf50","max_instructions":500,"offset":0,"include_total":true,"database":"<active-session-id-from-current-idb_list>"}
disasm {"addr":"0x0045d5f0","max_instructions":100,"offset":0,"include_total":true,"database":"<active-session-id-from-current-idb_list>"}
stack_frame {"addrs":["0x0045d5c0"],"database":"<active-session-id-from-current-idb_list>"}
get_comments {"addrs":["0x0045d5b5","0x0045d5c0","0x0045d5d6","0x0045d5eb","0x0045d5f0","0x0045cf50","0x0045d17e","0x0045d187","0x0045d195","0x0045d19e"],"database":"<active-session-id-from-current-idb_list>"}
inspect_items {"addrs":["0x0045d5b5","0x0045d5c0","0x0045d5d6","0x0045d5e8","0x0045d5eb","0x0045d5f0","0x0045d17e","0x0045d187","0x0045d195","0x0045d19e"],"database":"<active-session-id-from-current-idb_list>"}
get_bytes {"regions":[{"addr":"0x0045d5b5","size":11},{"addr":"0x0045d5c0","size":43},{"addr":"0x0045d5eb","size":5},{"addr":"0x0045cf50","size":605},{"addr":"0x0045d17e","size":32},{"addr":"0x0045d5f0","size":99}],"database":"<active-session-id-from-current-idb_list>"}
xref_query {"queries":[{"addr":"0x0045d5c0","direction":"to","xref_type":"code","offset":0,"count":5000,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x0045d5c0","direction":"to","xref_type":"data","offset":0,"count":5000,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x0045d5f0","direction":"to","xref_type":"code","offset":0,"count":5000,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x0045cf50","direction":"to","xref_type":"code","offset":0,"count":5000,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}],"database":"<active-session-id-from-current-idb_list>"}
find_bytes {"patterns":["C0 D5 45 00","C0 D5 05 00","C0 C9 05 00"],"limit":100,"database":"<active-session-id-from-current-idb_list>"}
type_inspect {"queries":[{"name":"RankingCategoryRecord","include_members":true,"max_members":100},{"name":"RankingUserEntry","include_members":true,"max_members":100},{"name":"RankingUserEntryVectorStorage","include_members":true,"max_members":100}],"database":"<active-session-id-from-current-idb_list>"}
~~~

RB-S is the only stateful readback bundle. It contains only inspection-only `lookup_funcs`, `disasm`, `stack_frame`, `get_comments`, `inspect_items`, `get_bytes`, `xref_query`, `find_bytes`, and `type_inspect`; it contains no `analyze_function`, `func_profile`, `decompile`, `force_recompile`, or other analysis-producing request. RB-S must run at S0, after every individual dry-run/mutation/type/comment call, once as the complete pre-save verification, and again after a genuinely fresh reopen. If any inspection call changes name, semantic type, frame, comments, bytes, items, xrefs, fences, UDTs, caller, or callee outside the stage table, stop without save and discard the worker. A truncated batch, missing entity, malformed result, or item-level failure also stops without save. Exact bytes/code items/disassembly/xrefs protect the historically measured block/complexity and decompile semantics without recomputing them in the frozen worker; the sole real external call remains the literal call item `0x45d5d6 -> 0x45d5f0`.

### Literal bounded MCP mutation calls and exact poststates

| ID | Literal request sequence | Exact authorized poststate |
| --- | --- | --- |
| I01 | `rename {"batch":{"func":{"addr":"0x0045d5c0","name":"RankingCategoryRecordRangeDestroyUserEntries"},"dry_run":true,"stop_on_error":true,"allow_overwrite":false,"pure":true},"database":"<active-session-id-from-current-idb_list>"}` then `rename {"batch":{"func":{"addr":"0x0045d5c0","name":"RankingCategoryRecordRangeDestroyUserEntries"},"dry_run":false,"stop_on_error":true,"allow_overwrite":false,"pure":true},"database":"<active-session-id-from-current-idb_list>"}`. | Dry-run reports summary `total:1`, `ok:1`, `failed:0`, `stopped:false`, `dry_run:true`, changes nothing, and returns no `dir`/`dir_error`. Actual reports one successful pure function rename, returns no `dir`/`dir_error`, and changes only the function name. The implementation lock proves no `/vibe/` creation/link and no decompiler refresh; range, bytes, metrics, frame, prototype, comments, xrefs, and callee remain prestate until their explicit rows. |
| I02 | `rename {"batch":{"stack":{"func_addr":"0x0045d5c0","old":"arg_0","new":"first"},"dry_run":true,"stop_on_error":true,"allow_overwrite":false,"pure":false},"database":"<active-session-id-from-current-idb_list>"}` then `rename {"batch":{"stack":{"func_addr":"0x0045d5c0","old":"arg_0","new":"first"},"dry_run":false,"stop_on_error":true,"allow_overwrite":false,"pure":false},"database":"<active-session-id-from-current-idb_list>"}` then `set_type {"edits":{"addr":"0x0045d5c0","kind":"stack","name":"first","ty":"RankingCategoryRecord *"},"database":"<active-session-id-from-current-idb_list>"}`. | Pure mode is intentionally not requested because the endpoint rejects stack members. Dry-run changes nothing. Specialized actual stack rename changes only physical `arg_0` to `first`; stack type then yields exactly `first +0x10 size4 RankingCategoryRecord *`. Every other frame row and all non-frame state remain exact after each separate RB-S. |
| I03 | `rename {"batch":{"stack":{"func_addr":"0x0045d5c0","old":"arg_4","new":"last"},"dry_run":true,"stop_on_error":true,"allow_overwrite":false,"pure":false},"database":"<active-session-id-from-current-idb_list>"}` then `rename {"batch":{"stack":{"func_addr":"0x0045d5c0","old":"arg_4","new":"last"},"dry_run":false,"stop_on_error":true,"allow_overwrite":false,"pure":false},"database":"<active-session-id-from-current-idb_list>"}` then `set_type {"edits":{"addr":"0x0045d5c0","kind":"stack","name":"last","ty":"RankingCategoryRecord *"},"database":"<active-session-id-from-current-idb_list>"}`. | Pure mode is intentionally not requested because the endpoint rejects stack members. Dry-run changes nothing. Specialized actual stack rename changes only physical `arg_4` to `last`; stack type then yields exactly `last +0x14 size4 RankingCategoryRecord *`. Final four-row frame is saved/return/first/last at unchanged offsets and widths; no row appears or disappears and all non-frame state remains exact. |
| I04 | `set_type {"edits":{"addr":"0x0045d5c0","kind":"function","signature":"void __stdcall RankingCategoryRecordRangeDestroyUserEntries(RankingCategoryRecord *first, RankingCategoryRecord *last)"},"database":"<active-session-id-from-current-idb_list>"}`. | Exact function prototype and final physical frame from I02/I03. Calling convention remains stdcall; `retn 8`, body, range, bytes/items/xrefs, literal call instruction, and all protected state remain exact under inspection-only RB-S. No `force_recompile` or decompile is allowed in the saved transaction. |
| I05 | `set_function_comments {"items":{"addr":"0x0045d5c0","comment":"Compiler-generated exception cleanup for a partially constructed RankingCategoryRecord range: destroys each record's m_userEntries vector over [first,last); source remains RankingCategoryCollection's std::vector<RankingCategoryRecord> growth operation."},"database":"<active-session-id-from-current-idb_list>"}`. | Function regular equals the exact literal. The implementation-locked endpoint writes only `idc.set_func_cmt(..., False)`; no address/decompiler comment endpoint is called. Address regular, address repeatable, and function repeatable remain absent. All I01-I04 state remains exact. |

### Exact candidate S0-S13 state contract

Frame inventories are literal and complete: `R0` is `__saved_registers +0x8 size4 _DWORD`; `__return_address +0xc size4 _UNKNOWN *`; `arg_0 +0x10 size4 _DWORD`; `arg_4 +0x14 size4 _DWORD`. `R1` changes only `arg_0` to `first`. `R2` changes only `first` type to `RankingCategoryRecord *`. `R3` additionally changes only `arg_4` to `last`. `R4` additionally changes only `last` type to `RankingCategoryRecord *`. `C0` means all four target address/function regular/repeatable comment channels are absent. `C1` means only function regular equals the exact I05 literal and the other three channels remain absent.

| Stage | Required trigger/readback point | Exact target name | Exact semantic type | Exact frame | Exact comments | Other required state |
| --- | --- | --- | --- | --- | --- | --- |
| S0 | Mandatory disposable preflight worker and, after its `WD0` disposal plus inactive-or-absent registry/process/endpoint/exclusive-P0/B0 proof, the separate fresh exact-P0 transaction worker before any action | `sub_45D5C0` | `void __stdcall(int, int)` | R0 | C0 | Each worker independently reads exact P1-P11 raw prestate and no final-name collision; only the second worker may proceed to I01 after repeating S0. A stale preflight row is allowed only inactive with the exact worker process/endpoints gone. |
| S1 | After I01 pure dry-run | `sub_45D5C0` | `void __stdcall(int, int)` | R0 | C0 | Dry-run summary is exactly one valid non-overwrite action (`total:1`, `ok:1`, `failed:0`, `stopped:false`, `dry_run:true`), returns no `dir`/`dir_error`, and changes nothing. |
| S2 | After I01 actual pure rename | `RankingCategoryRecordRangeDestroyUserEntries` | `void __stdcall(int, int)` | R0 | C0 | Only target function name changes; response has no `dir`/`dir_error`; implementation lock proves no `/vibe/` creation/link and no decompiler refresh. |
| S3 | After I02 stack-rename dry-run | `RankingCategoryRecordRangeDestroyUserEntries` | `void __stdcall(int, int)` | R0 | C0 | Dry-run changes nothing. |
| S4 | After I02 actual stack rename | `RankingCategoryRecordRangeDestroyUserEntries` | `void __stdcall(int, int)` | R1 | C0 | Only `arg_0` becomes `first`. |
| S5 | After I02 stack type | `RankingCategoryRecordRangeDestroyUserEntries` | `void __stdcall(int, int)` | R2 | C0 | Only `first` physical type changes. |
| S6 | After I03 stack-rename dry-run | `RankingCategoryRecordRangeDestroyUserEntries` | `void __stdcall(int, int)` | R2 | C0 | Dry-run changes nothing. |
| S7 | After I03 actual stack rename | `RankingCategoryRecordRangeDestroyUserEntries` | `void __stdcall(int, int)` | R3 | C0 | Only `arg_4` becomes `last`. |
| S8 | After I03 stack type | `RankingCategoryRecordRangeDestroyUserEntries` | `void __stdcall(int, int)` | R4 | C0 | Only `last` physical type changes. |
| S9 | After I04 function `set_type` | `RankingCategoryRecordRangeDestroyUserEntries` | `void __stdcall RankingCategoryRecordRangeDestroyUserEntries(RankingCategoryRecord *first, RankingCategoryRecord *last)` | R4 | C0 | Only the semantic function type changes. |
| S10 | Second inspection-only RB-S stability readback after S9, with no intervening action | `RankingCategoryRecordRangeDestroyUserEntries` | `void __stdcall RankingCategoryRecordRangeDestroyUserEntries(RankingCategoryRecord *first, RankingCategoryRecord *last)` | R4 | C0 | Exact bytes/items/disassembly/xrefs/call/frame/types/comments remain S9; no analysis or metadata delta occurs. |
| S11 | After I05 comment | `RankingCategoryRecordRangeDestroyUserEntries` | `void __stdcall RankingCategoryRecordRangeDestroyUserEntries(RankingCategoryRecord *first, RankingCategoryRecord *last)` | R4 | C1 | Only function regular changes. |
| S12 | Complete pre-save RB-S | `RankingCategoryRecordRangeDestroyUserEntries` | `void __stdcall RankingCategoryRecordRangeDestroyUserEntries(RankingCategoryRecord *first, RankingCategoryRecord *last)` | R4 | C1 | I01-I05 and P1-P11 exact; the pre-save canonical on-disk artifact still equals P0. |
| S13 | Genuinely fresh canonical reopen after transaction-worker `WD0` and exclusive D1 readback | `RankingCategoryRecordRangeDestroyUserEntries` | `void __stdcall RankingCategoryRecordRangeDestroyUserEntries(RankingCategoryRecord *first, RankingCategoryRecord *last)` | R4 | C1 | Old transaction row is absent or inactive; its exact process/endpoints are gone; fresh verifier is the sole live canonical worker; exact captured D1 differs from P0; persisted I01-I05 and P1-P11 are exact. Acceptance still requires verifier `WD0`, inactive-or-absent row plus process/endpoint proof, and an exclusive canonical rehash equal to exact D1. |

At every stage RB-S must preserve the P1 target bytes/items/range/metrics, P2/P3 fences, P4/P5 xrefs/call item, P6 caller, P7 callee, and P8 UDTs exactly. In particular, the inferred target type `void __stdcall(RankingUserEntryVectorStorage *, RankingUserEntryVectorStorage *)` is forbidden at S0-S13; if any read or action materializes it, stop without save and discard the worker.

### P1-P11 protections

- P1 target remains exact code range `[0x0045d5c0,0x0045d5eb)`, 43 bytes `55 8b ec 56 8b 75 08 57 8b 7d 0c 3b f7 74 16 90 8d 8e 58 02 00 00 e8 15 00 00 00 81 c6 b0 02 00 00 3b f7 75 eb 5f 5e 5d c2 08 00`, SHA256 `F0B538E7F49394DCC6AFEA6B6041D072FA9971DD4C711B8C61416B28F35574FC`, 18 instructions, four blocks, complexity three.
- P2 predecessor fence remains exact `[0x45d5b5,0x45d5c0)`, one unnamed/untyped non-code data item, eleven `cc` bytes, SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`, blank regular/repeatable comments, zero xrefs.
- P3 successor fence remains exact `[0x45d5eb,0x45d5f0)`, one unnamed/untyped non-code data item, five `cc` bytes, SHA256 `992CF51486F901AA1AA7D1F63E18C150C9156166E08E0B9E59CC3FAF98177329`, blank regular/repeatable comments, zero xrefs.
- P4 inbound routes remain exactly one target code xref from `0x45d187`, zero target data xrefs, and zero VA/RVA/raw-offset pattern hits.
- P5 call item `[0x45d5d6,0x45d5db)` remains code and targets exact `0x45d5f0`; no additional real external callee is permitted.
- P6 caller `sub_45CF50` remains `[0x45cf50,0x45d1ad)`, size `0x25d`, 227 instructions, 39 blocks, type `int __thiscall(int *this, int, int)`, body SHA256 `E9C576F6F580639E629E25C6636C5EBD5C2F22968191930D582B4090AE021B8B`, and incoming calls `0x45c502`/`0x45c7dc`. Exact `[0x45d17e,0x45d19e)` cleanup-prefix bytes retain SHA256 `2B74BEEB2F4D02D62B144DCB3F0FC0351D687E3036DD7CF04C9420A2204ECF35`; this prefix includes range arguments/call, free arguments/call, and two zero throw arguments. The immediately following call at `0x45d19e` must remain `__CxxThrowException@8`.
- P7 nested teardown remains `RankingUserEntryVectorDestroy`, `[0x45d5f0,0x45d653)`, size `0x63`, 35 instructions, seven blocks, type `void __thiscall(RankingUserEntryVectorStorage *this)`, body SHA256 `B0F287B431E3F2C1303FA0CD8B060188E4A7A263B79F5EFEFEB403A8862CD44D`, and function-repeatable comment exactly `Compiler-generated std::vector<RankingUserEntry> storage teardown: frees begin using MSVC large-allocation validation and clears begin/end/capacity; source declaration remains RankingCategoryRecord::m_userEntries.` Its incoming code-xref inventory remains exactly `0x45bf56`, `0x45c2e8`, `0x45c514`, `0x45c5b6`, `0x45c7ee`, `0x45d0f9`, `0x45d516`, `0x45d548`, and `0x45d5d6`, with no data route.
- P8 `RankingCategoryRecord` remains size 688 with exactly 15 members: `m_listIndex +0x0/2`, alignment `+0x2/2`, `m_categoryId +0x4/4`, `m_stateCode +0x8/4`, `m_startTime +0xc/36 tm`, `m_endTime +0x30/36 tm`, `m_title +0x54/512`, `m_totalRankCount +0x254/4`, user-entry begin/end/capacity `+0x258/+0x25c/+0x260`, loaded category `+0x264`, local rank `+0x268`, footer `+0x26c/64`, local score `+0x2ac/4`. `RankingUserEntry` remains size 76 and `RankingUserEntryVectorStorage` remains size 12 with begin/end/capacityEnd at `+0/+4/+8`. No type declaration is changed.
- P9 only the stage-table deltas are allowed. I01 must use implementation-locked `pure:true`; its result has no `dir`/`dir_error`, no `/vibe/` function-directory state may be created/linked, and no decompiler refresh may run. I02/I03 must use explicit `pure:false` because current schema rejects pure stack renames; the specialized path may change only the two named/typed physical arguments while saved-register/return rows and every offset/width remain exact. I04 alone changes the semantic target type from raw `void __stdcall(int, int)` to the exact final signature. No local/frame row is created or deleted, and no automatic `RankingUserEntryVectorStorage *` target signature is accepted.
- P10 only I05 function regular may change through implementation-locked `set_function_comments` / `idc.set_func_cmt(..., False)`. No `set_address_comments`, generic `set_comments`, repeatable-comment, or decompiler-comment endpoint is invoked. Target address regular/repeatable and function repeatable remain absent; pad/caller/callee comment channels remain their freshly captured RB-S values.
- P11 stdcall, two explicit four-byte arguments, `retn 8`, function start/end, chunks, item boundaries, and all unrelated names/types/comments remain exact; no byte patch, function create/delete/resize, data retype, UDT mutation, function-directory `/vibe/` change, decompiler cache refresh, action outside I01-I05, or analysis-producing `analyze_function`/`func_profile`/`decompile`/`force_recompile` call in the frozen stateful worker is permitted. The live `tools/list` schema and exact `api_modify.py`/`utils.py` identities must match the feasibility lock before I01; drift stops before transaction-worker creation. `idb_save` is issued at most once; an absent, truncated, timed-out, malformed, or item-level-uncertain response is indeterminate and must not be retried.

### Exact fail-closed supervisor transaction

1. Before opening any worker, require current live `tools/list` and local implementation identities to match the endpoint feasibility lock exactly. Then open the mandatory disposable preflight worker genuinely fresh with `run_auto_analysis:false`, record its unique session/PID/path plus exact process identity and listener endpoints, require it to be the sole live canonical-bound worker, run full inspection-only RB-S, and require raw S0. If optional `analyze_function`, `func_profile`, `decompile`, or `force_recompile` evidence is needed, run it only in this disposable worker after S0; no diagnostic result is transaction state or action credit.
2. Dispose the exact preflight worker without save through `WD0`. Reread `idb_list`: the exact row may be absent or stale only with `is_active:false`; any active or unexpected canonical row stops. Prove the exact process/endpoints gone or an unambiguous different-process PID reuse, reject every live/ambiguous PID or endpoint, and require a successful exclusive `FileShare.None` canonical identity probe. Any unresolved worker identity, active row, endpoint, competing canonical worker, or probe failure stops before disk hashing or backup creation.
3. With the successful exclusive probe proving no canonical worker/writer, capture that identity as closed-disk P0, prove the timestamped B0 path nonexistent, copy P0 to B0, and verify B0 size/SHA exactly equal P0 through a separate exclusive read identity. No worker may be opened until this closed P0/B0 proof is complete.
4. Open a separate fresh transaction worker from the exact canonical P0 path. Record its unique session/PID plus exact process identity and listener endpoints, require it to be the sole live canonical-bound worker, rehash disk and B0 to exact P0, prove the preflight row remains absent/inactive and its exact process/endpoints remain gone, then repeat full inspection-only RB-S and require S0. Any mismatch invokes transaction-worker `WD0` without save and returns the same report for reconciliation.
5. Execute only the literal I01 `pure:true` dry-run, require its exact summary with no `dir`/`dir_error`, run RB-S, and require S1. Execute only the literal I01 `pure:true` actual rename, require one success with no `dir`/`dir_error`, run RB-S, and require S2. Any schema rejection, `/vibe/` result, decompiler-refresh indication, implementation-identity drift, or other delta stops unsaved.
6. Execute each I02 request separately with explicit `pure:false`, running RB-S after dry-run, specialized actual stack rename, and stack type and requiring S3, S4, then S5. Execute I03 the same way and require S6, S7, then S8. `pure:true` must not be sent for stack members; any pure-mode error, non-frame side effect, extra/missing frame row, or delta outside R0-R4 stops unsaved.
7. Execute only I04 `set_type`, run RB-S and require S9, then run a second inspection-only RB-S with no intervening action and require S10. Do not call `force_recompile`, `decompile`, `func_profile`, or `analyze_function`. Any automatic row addition/removal, inferred `RankingUserEntryVectorStorage *` target signature, type canonicalization outside the authorized target/argument deltas, or other change stops unsaved.
8. Execute only I05 through the implementation-locked regular-function-comment endpoint; do not invoke `set_address_comments` because no address-comment change is authorized. Run RB-S and require S11, including the other three target channels still blank. Run one more complete RB-S and require S12. Immediately before save, reread canonical disk and B0 and require both exact P0, re-prove this is the sole fresh P0 transaction worker, and record that no competing writer appeared. This is attribution fact A4 and the pre-save concurrency check; every post-save authority hash and restore remains prohibited until transaction-worker `WD0`, inactive-or-absent registry proof, process/endpoint proof, and exclusive-handle proof complete.
9. Invoke `idb_save` exactly once and record that single attempt as A5. Classify its response as exact success (`ok:true`), explicit failure (`ok:false` or explicit tool error), or indeterminate (timeout, transport loss, missing/truncated/malformed result, or no trustworthy item-level completion). Never retry any branch in this worker.

~~~text
idb_save {"path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","database":"<active-session-id-from-current-idb_list>"}
~~~

10. Regardless of save-response branch, invoke `WD0` on the exact transaction worker without another save. Reread `idb_list`; allow its exact row only absent or inactive, reject any active/unexpected canonical row, prove the exact process/endpoints gone or unambiguous PID reuse, reject ambiguity, and require a successful exclusive canonical identity probe. These facts are A6. With no competing canonical worker/writer, immediately capture the same exclusive identity as A7. Classify it as D1 only if A1-A7 are all complete. If any attribution fact is missing and the observation is non-P0, classify it U1 unknown/third identity, stop without restore, and escalate for supervisor incident handling.
11. An explicit failure receives no action credit. If complete A1-A7 attribution leaves D1 equal to P0, open a fresh raw verifier, prove S0, dispose it through `WD0`, permit only an absent/inactive row, prove process/endpoints gone and no ambiguity, then require an exclusive rehash equal to P0. If complete attribution leaves D1 different from P0, the non-P0 identity is a transaction-attributable failing-save D1: while an exclusive probe still equals exact D1, run the identity-gated B0 restore, require P0, open a fresh raw verifier, prove S0, dispose it through `WD0`, and require an exclusive rehash equal to P0. Without complete attribution, no non-P0 restore is allowed.
12. For exact-success or indeterminate response with complete A1-A7 attribution and D1 different from P0, do not restore and do not infer persistence from D1 alone. Open canonical disk genuinely fresh under a unique timestamped session name, prove the transaction worker row remains absent/inactive and its exact process/endpoints remain gone, require the fresh verifier to be the sole live canonical worker, and bind the returned canonical session:

~~~text
idb_open {"input_path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","mode":"force_headless","run_auto_analysis":false,"build_caches":true,"init_hexrays":true,"idle_ttl_sec":3600,"preferred_session_id":"b005-uid0003ys-persist-verify-<timestamp>"}
idb_list {}
server_health {"database":"<fresh-session-id-returned-by-idb_open-or-idb_list>"}
~~~

13. Substitute only that fresh verifier session ID into inspection-only RB-S and require exact S13, I01-I05, and P1-P11. Then invoke verifier `WD0` without save, permit its exact row only absent/inactive, prove the exact process/endpoints gone or unambiguous PID reuse, reject every active/ambiguous worker state, and acquire an exclusive canonical identity. The final hash/size must equal exact attributed D1. Exact-success receives credit only after full S13 and this disposed-verifier exclusive D1 rehash pass. An indeterminate save may receive credit only under the same complete attribution and persistence proof. Partial or sampled verification is insufficient.
14. If exact-success or indeterminate response leaves attributed D1 equal to P0, treat it as no persisted save: open fresh, require raw S0, dispose that verifier under `WD0`, require absent/inactive row plus process/endpoint/PID-identity proof, exclusively rehash exact P0, record no action credit, and do not restore identical bytes. If S13 or the final disposed-verifier D1 rehash fails, run verifier `WD0` and the full inactive-row/process/endpoint/exclusive proof, then run the identity gate: current disk must equal P0 or exact attributed D1. U1, exclusive-probe failure, live/ambiguous worker, or any third identity stops without restore. If current equals attributed D1 and differs from P0, restore B0, require P0, open a second fresh canonical session, prove raw S0, dispose it under `WD0`, and exclusively rehash P0. Any failure before `idb_save` invokes unsaved transaction-worker `WD0` and then requires exclusive exact P0; a non-P0 observation before any save is unknown/third identity and must not be restored. Any disposal/probe failure, active row, live/ambiguous PID or endpoint, P0/B0 mismatch, attribution gap, unknown identity, reopen mismatch, or competing canonical worker stops without partial credit or another save.

### Historical 2026-08-05 Gate 2B no-save failure and rollback proof

- The primary supervisor bound healthy session `supervisor-readonly-post-b002-gate2fail` to canonical SHA256 `29AA9F5B584D9C771DEB25D7C0B7B9A4B8641C0B19B8AAA860B0C66CD591028D`, size 143,197,232. Initial raw readback matched `sub_45D5C0`, `void __stdcall(int, int)`, R0, C0, and no final-name collision.
- The former mandatory RB0 then called `analyze_function` during the first prestate verification. Before any I01-I05 rename, stack edit, semantic type, comment, or save, it changed only the unsaved worker's target semantic type to `void __stdcall(RankingUserEntryVectorStorage *, RankingUserEntryVectorStorage *)`.
- The verifier failed closed immediately. Worker PID `20404` was identity-checked and terminated without save. Canonical disk remained exact at SHA256 `29AA9F5B584D9C771DEB25D7C0B7B9A4B8641C0B19B8AAA860B0C66CD591028D`, size 143,197,232.
- Fresh session `supervisor-readonly-post-b005-gate2fail` proved raw `sub_45D5C0`, `void __stdcall(int, int)`, exact R0, C0, and no final-name collision restored from canonical disk. Session/PID labels are dated evidence, not permanent authority.
- This failed attempt receives no C3YS-025 through C3YS-030 credit. Its negative evidence and rollback proof remain authoritative history.
- In the subsequent current-schema Gate 2B preflight, the primary supervisor rejected the package before any UID0003YS mutation or save because MCP has no session-close endpoint and `idb_list` retains inactive stale rows after exact unsaved worker termination. No IDA transaction/mutation/save was attempted in that run and no action credit exists. This is deterministic tool-behavior evidence, not a target-state change.
- The repaired package supersedes literal row-removal requirements with `WD0`: absent-or-inactive registry proof, exact process/PID-reuse identity, recorded-endpoint absence, rejection of every active/ambiguous canonical worker, and an exclusive `FileShare.None` identity probe. Closed P0/B0/fresh-transaction ordering, inspection-only RB-S, attribution-gated D1, identity-gated restore, and S0-S13 remain candidate supervisor work awaiting fresh Gate 1 and receive no action credit.
- The `2026-08-06` controlled-restart capability audit then established the supported no-side-effect function-rename route: live `tools/list` exposes `pure:true`, current source proves it skips `/vibe/` placement and decompiler refresh, stack renames remain specialized and reject pure mode, and channel-specific comment endpoints are available. This report repair only reconciles the future transaction contract; it performed no MCP action, IDA mutation/save, worker management, or target transaction and receives no C3YS-025 through C3YS-030 credit.

<!-- END CLEANUP-20260813-0003YS-SECTION21 -->

## Removed Block R002

- Original start line: `382`
- Language: `powershell`
- Preserved body SHA256: `B099B3F702000B7256F4376DA2D50AF7B707357CFA95957938CC74CD9D97FFFA`
- Original fenced-block characters: `645`

~~~~powershell
$idb = 'E:\NTK\Resources\NexusTK\NexusTK.exe.i64'
$p0Identity = Get-UID0003YSExclusiveReadIdentity -Path $idb
$p0Size = $p0Identity.Length
$p0Sha = $p0Identity.SHA256
$stamp = Get-Date -Format 'yyyyMMdd-HHmmss'
$b0 = "$idb.bak-UID0003YS-prestate-$stamp"
if (Test-Path -LiteralPath $b0) { throw 'UID0003YS B0 path collision; stop before transaction-worker open.' }
Copy-Item -LiteralPath $idb -Destination $b0 -ErrorAction Stop
$b0Identity = Get-UID0003YSExclusiveReadIdentity -Path $b0
if ($b0Identity.Length -ne $p0Size -or $b0Identity.SHA256 -ne $p0Sha) { throw 'UID0003YS B0 mismatch; stop before transaction-worker open.' }
~~~~

## Removed Block R003

- Original start line: `403`
- Language: `powershell`
- Preserved body SHA256: `0C5482B066D5D9C830D8C07CA82704B9CBD8FABB7311D780D66689DDD60A5FAC`
- Original fenced-block characters: `577`

~~~~powershell
$transactionOpenItem = Get-Item -LiteralPath $idb
$transactionOpenSha = (Get-FileHash -LiteralPath $idb -Algorithm SHA256).Hash
$b0Item = Get-Item -LiteralPath $b0
$b0Sha = (Get-FileHash -LiteralPath $b0 -Algorithm SHA256).Hash
if ($transactionOpenItem.Length -ne $p0Size -or $transactionOpenSha -ne $p0Sha) { throw 'UID0003YS transaction worker did not open over exact P0; dispose without save under WD0.' }
if ($b0Item.Length -ne $p0Size -or $b0Sha -ne $p0Sha) { throw 'UID0003YS B0 no longer equals P0; dispose transaction worker without save under WD0.' }
~~~~

## Removed Block R004

- Original start line: `418`
- Language: `powershell`
- Preserved body SHA256: `0D3D825A8713AE428FCD380A6A91207D5264023FC13BA82BD0DD49573D7148E8`
- Original fenced-block characters: `194`

~~~~powershell
$closedObservedIdentity = Get-UID0003YSExclusiveReadIdentity -Path $idb
$closedObservedSize = $closedObservedIdentity.Length
$closedObservedSha = $closedObservedIdentity.SHA256
~~~~

## Removed Block R005

- Original start line: `428`
- Language: `powershell`
- Preserved body SHA256: `5203DC651C3FC2B3E11DF42DDA057A1E893A9AFDB43BE20832F47D505954428F`
- Original fenced-block characters: `941`

~~~~powershell
$b0Identity = Get-UID0003YSExclusiveReadIdentity -Path $b0
if ($b0Identity.Length -ne $p0Size -or $b0Identity.SHA256 -ne $p0Sha) { throw 'UID0003YS B0 no longer equals P0; stop without restore.' }
$currentIdentity = Get-UID0003YSExclusiveReadIdentity -Path $idb
$currentIsP0 = ($currentIdentity.Length -eq $p0Size -and $currentIdentity.SHA256 -eq $p0Sha)
$currentIsAttributedD1 = ($d1AttributionComplete -and $currentIdentity.Length -eq $d1Size -and $currentIdentity.SHA256 -eq $d1Sha)
if (-not $currentIsP0 -and -not $currentIsAttributedD1) { throw 'UID0003YS unknown/third canonical identity detected; stop without restore.' }
if (-not $currentIsP0) { Copy-Item -LiteralPath $b0 -Destination $idb -Force -ErrorAction Stop }
$restoredIdentity = Get-UID0003YSExclusiveReadIdentity -Path $idb
if ($restoredIdentity.Length -ne $p0Size -or $restoredIdentity.SHA256 -ne $p0Sha) { throw 'UID0003YS canonical restore mismatch.' }
~~~~
