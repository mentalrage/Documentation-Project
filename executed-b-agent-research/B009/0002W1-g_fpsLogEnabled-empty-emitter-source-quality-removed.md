<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B009\0002W1-g_fpsLogEnabled-empty-emitter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002W1-g_fpsLogEnabled-empty-emitter-source-quality.md](0002W1-g_fpsLogEnabled-empty-emitter-source-quality.md)
- Source report SHA256 before cleanup: `913FE81512F24441A74ED4779833ECE771C0A7F1745FB6AC9E4B16048DE4A9BB`
- Cleanup generated: `2026-08-11T12:47:14Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `409-419`
- Original language: `powershell`
- Block SHA256: `0A0C140697D554E00DD008377E5499A5CB99E60358B67D437D97BABE4298F315`

```powershell
$canonical = 'E:\NTK\Resources\NexusTK\NexusTK.exe.i64'
$stamp = Get-Date -Format 'yyyyMMdd-HHmmss'
$backup = "$canonical.bak-UID0002W1-prestate-$stamp"
Copy-Item -LiteralPath $canonical -Destination $backup -ErrorAction Stop
$canonicalItem = Get-Item -LiteralPath $canonical
$backupItem = Get-Item -LiteralPath $backup
$canonicalHash = (Get-FileHash -LiteralPath $canonical -Algorithm SHA256).Hash
$backupHash = (Get-FileHash -LiteralPath $backup -Algorithm SHA256).Hash
if (($canonicalItem.Length -ne $backupItem.Length) -or ($canonicalHash -cne $backupHash)) { throw 'UID0002W1 prestate backup mismatch; abort before IDA mutation.' }
```

## Removed Block R002

- Original source lines: `473-481`
- Original language: `powershell`
- Block SHA256: `F68A6F05E2B2D8570E920589763673C896A5930419C5E3F1D7AF293A8870A246`

```powershell
$workerPid = [int]'<gate2b-worker-pid>'
Stop-Process -Id $workerPid -Force -ErrorAction Stop
for ($i = 0; $i -lt 50 -and (Get-Process -Id $workerPid -ErrorAction SilentlyContinue); $i++) { Start-Sleep -Milliseconds 100 }
if (Get-Process -Id $workerPid -ErrorAction SilentlyContinue) { throw 'UID0002W1 dirty worker did not stop; halt without save.' }
$currentItem = Get-Item -LiteralPath $canonical
$currentHash = (Get-FileHash -LiteralPath $canonical -Algorithm SHA256).Hash
if (($currentItem.Length -ne $canonicalItem.Length) -or ($currentHash -cne $canonicalHash)) { throw 'UID0002W1 no-save rollback disk identity drifted; halt.' }
```

## Removed Block R003

- Original source lines: `485-494`
- Original language: `powershell`
- Block SHA256: `9284C5E1D581622117F9A28E44A089A82008853EAB11B280D348850C750C69A5`

```powershell
$persistWorkerPid = [int]'<persist-worker-pid>'
Stop-Process -Id $persistWorkerPid -Force -ErrorAction Stop
for ($i = 0; $i -lt 50 -and (Get-Process -Id $persistWorkerPid -ErrorAction SilentlyContinue); $i++) { Start-Sleep -Milliseconds 100 }
if (Get-Process -Id $persistWorkerPid -ErrorAction SilentlyContinue) { throw 'UID0002W1 persistence worker did not stop; halt before restore.' }
Copy-Item -LiteralPath '<backup-path>' -Destination $canonical -Force -ErrorAction Stop
$restoredItem = Get-Item -LiteralPath $canonical
$restoredHash = (Get-FileHash -LiteralPath $canonical -Algorithm SHA256).Hash
if (($restoredItem.Length -ne $backupItem.Length) -or ($restoredHash -cne $backupHash) -or ($restoredHash -cne $canonicalHash)) { throw 'UID0002W1 saved rollback identity mismatch; halt.' }
```

## Removed operational snapshot from D61584079C02B32C26D63DACA3F837175473141ADB7C2FFC8B448F0A650E2C2B

> Source: [0002W1-g_fpsLogEnabled-empty-emitter-source-quality.md](./0002W1-g_fpsLogEnabled-empty-emitter-source-quality.md)
> NON-AUTHORITATIVE ARCHIVE. Retained only for evidentiary no-loss review.
> NEVER EXECUTE, ADAPT, OR TREAT THE CONTENT BELOW AS A CURRENT REQUEST, PROCEDURE, MUTATION AUTHORITY, OR LIFECYCLE INSTRUCTION.

`````text
## IDA Rename / Type / Comment Recommendations

This is a literal primary-supervisor-only Gate 2B transaction. B009 performed no mutation, save, backup, process control, or UID0002W2 rename. The active `tools/list` schema was reread before this repair. It exposes `make_data`, `set_type`, `rename` with `dry_run`, `set_repeatable_comments`, `set_comments`, `inspect_items`, `get_int`, `get_bytes`, `get_comments`, `xrefs_to`, `xref_query`, `insn_query`, `entity_query`, `idb_save`, and `idb_open`; it exposes no `idb_close`/discard call. Therefore worker teardown in rollback/persistence steps is an explicit primary-supervisor process-control boundary, never a B-agent action.

Runtime placeholders are narrow: `<gate2b-database>` is selected from a fresh `idb_list` only after its `server_health.idb_path` and canonical disk identity match; `<gate2b-worker-pid>` is that selected session's fresh worker PID; `<backup-path>` is the timestamp-expanded backup below; `<persist-database>` and `<persist-worker-pid>` come from the fresh post-save reopen. No dated session/PID is durable authority. Every MCP request below contains at most ten queried addresses/entities/regions.

### Literal one-row-per-action/protection prestate and poststate contract

The fresh dated supervisor premutation prestate is a transaction snapshot, not permission to skip Gate 2B rereads. Blank comment fields mean both regular and repeatable channels are absent. At the target, `inspect_items.name` already renders synthetic `unk_69B338` on the raw untyped/non-data byte while exact-name `entity_query` enumerates zero user-defined hits for both `unk_69B338` and `g_fpsLogEnabled`. The post-B002 read-only recheck reconfirmed this distinction and every I2W1/P2W1 row under canonical disk SHA256 `CE0222E87E1A569A73EB43DD72BF53412B103DD9281A535EEC2BCC01DE0932FA`; that session/hash is still only a dated snapshot. Gate 2B must require the two-channel distinction again before backup/mutation. The older report-time blank-then-synthetic inspection sequence remains historical evidence only and is no longer a literal current preflight requirement.

| ID | Entity and exact dated prestate | Exact action or protection | Required immediate/final poststate |
| --- | --- | --- | --- |
| I2W1-01 | Target `0x69b338-0x69b339`: head `0x69b338`, end `0x69b339`, width `1`; type blank; raw `is_code:false,is_data:false`; synthetic `inspect_items.name:"unk_69B338"`; exact-name `entity_query` totals `0` for both `^unk_69B338$` and `^g_fpsLogEnabled$`, proving no enumerated user-defined source/destination collision; `u8=0`; bytes `00`; comments blank; four data xrefs from `0x4b653f,0x4b6645,0x4b6a17,0x4b6ae4`; all four instructions render `cmp byte ptr unk_69B338, 0`. | After complete preflight and backup, repeat the exact dry run with actual old-name input `unk_69B338`, apply the data `rename` to desired name `g_fpsLogEnabled`, create exactly one one-byte data item with `make_data`, and type it with `set_type`; literal calls are below. | Head/end/width remain exactly `0x69b338/0x69b339/1`; `is_code:false,is_data:true`; stored/display name and the sole exact-name enumerated hit are exactly `g_fpsLogEnabled`, with zero remaining exact `unk_69B338` hits; type exactly one-byte `bool`; `u8=0`, byte `00`; comments unchanged until I2W1-02; exactly the same four data xrefs; all four instructions change only their operand name to `g_fpsLogEnabled`; no byte, instruction, item, xref, or neighbor delta otherwise. If `bool` does not read back with width one and the same item range, do not save and narrow the accepted transaction to no target data mutation. |
| I2W1-02 | Target comment prestate: regular blank, repeatable blank; all I2W1-01 physical/xref facts above. | `set_repeatable_comments` at `0x69b338` with the literal text below. | Regular remains blank; repeatable is exactly `Default-off FpsPane log-output gate; source definition belongs to FpsPane.cpp and all four static references are reads.`; every I2W1-01 and P2W1 protection remains exact. |
| I2W1-03 | Use head/end `0x4b653f/0x4b6546`, width `7`, `is_code:true,is_data:false`, stored name/type blank, containing-function metadata null, bytes `80 3d 38 b3 69 00 00`, instruction `cmp byte ptr unk_69B338, 0`, comments blank; inbound code xref `0x4b6539`; outbound code `0x4b6546` and data `0x69b338`. | Regular comment `Gate new FPS log-file creation on g_fpsLogEnabled.` | Item/range/bytes/code/data flags/type/name and all three xref edges unchanged; repeatable remains blank; regular matches exactly; operand name changes only through I2W1-01. |
| I2W1-04 | Use head/end `0x4b6645/0x4b664c`, width `7`, `is_code:true,is_data:false`, stored name `loc_4B6645`, type blank, containing-function metadata null, bytes `80 3d 38 b3 69 00 00`, same compare, comments blank; inbound code xrefs `0x4b64ca,0x4b64d9`; outbound code `0x4b664c` and data `0x69b338`. | Regular comment `Gate FPS log finalization/summary output on g_fpsLogEnabled.` | Item/range/bytes/code/data flags/name/type and all four xref edges unchanged; repeatable remains blank; regular matches exactly; operand name changes only through I2W1-01. |
| I2W1-05 | Use head/end `0x4b6a17/0x4b6a1e`, width `7`, `is_code:true,is_data:false`, stored name/type blank, containing-function metadata null, bytes `80 3d 38 b3 69 00 00`, same compare, comments blank; inbound code xref `0x4b6a11`; outbound code `0x4b6a1e` and data `0x69b338`. | Regular comment `Gate retained StartLogSession file output on g_fpsLogEnabled.` | Item/range/bytes/code/data flags/type/name and all three xref edges unchanged; repeatable remains blank; regular matches exactly; operand name changes only through I2W1-01. |
| I2W1-06 | Use head/end `0x4b6ae4/0x4b6aeb`, width `7`, `is_code:true,is_data:false`, stored name/type blank, containing-function metadata null, bytes `80 3d 38 b3 69 00 00`, same compare, comments blank; inbound code xref `0x4b6ae3`; outbound code `0x4b6aeb` and data `0x69b338`. | Regular comment `Return from retained WriteLogSummary when FPS logging is disabled.` | Item/range/bytes/code/data flags/type/name and all three xref edges unchanged; repeatable remains blank; regular matches exactly; operand name changes only through I2W1-01. |
| P2W1-01 | Predecessor `0x69b334-0x69b338`: four independent one-byte raw heads (`334`,`335`,`336`,`337`), each stored name/type blank, code/data false, bytes/value zero, comments blank; only `0x69b334` has three data xrefs (`0x4b6434,0x4b648a,0x4b6c70`), interior bytes have none. | Protected no-change predecessor entity; no define/type/rename/comment call may target it. | Every head/end/width/name/type/flag/byte/value/comment/xref remains exact; target creation must begin at `0x69b338` and consume one byte only. |
| P2W1-02 | UID0002W2 byte `0x69b339-0x69b33a`: independent one-byte raw head; blank name/type/comments; code/data false; value/byte zero; zero xrefs. | Protected no-change; specifically no UID0002W2 IDA rename, type, comment, merge, or data definition. | Exact prestate remains; it is not consumed by I2W1-01. |
| P2W1-03 | UID0002W2 byte `0x69b33a-0x69b33b`: independent one-byte raw head; blank name/type/comments; code/data false; value/byte zero; zero xrefs. | Protected no-change; no UID0002W2 mutation. | Exact prestate remains. |
| P2W1-04 | UID0002W2 byte `0x69b33b-0x69b33c`: independent one-byte raw head; blank name/type/comments; code/data false; value/byte zero; zero xrefs. | Protected no-change; no UID0002W2 mutation. | Exact prestate remains and successor starts at `0x69b33c`. |
| P2W1-05 | Successor `0x69b33c-0x69b340`: four independent one-byte raw heads (`33c`..`33f`), each width one with blank name/type/comments, `is_code:false,is_data:false`, value/byte zero; only `0x69b33c` has four data xrefs (`0x4b719b,0x4b7320,0x4b7330,0x4b73cb`), while `33d`..`33f` have none. | Protected no-change successor entity; no action may target or aggregate it. | Every listed physical head/range/width/flag/name/type/byte/value/comment/xref remains exact. |
| P2W1-06 | Exclusive boundary witness `0x69b340-0x69b341`: separate one-byte raw zero head, width one, blank name/type/comments, `is_code:false,is_data:false`, with four data xrefs (`0x4b71f1,0x4b733a,0x4b734a,0x4b73d5`). | Protected no-change boundary entity; no action may target or aggregate it. | Exact head/end/width/flags/name/type/byte/value/comments/four xrefs remain. |

### Literal Gate 2B transaction package

1. **Dynamic authority binding and delayed timestamped backup contract.** Run `idb_list {}`; select only a responsive session whose `server_health` reports `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; fail closed if zero or multiple unreconciled sessions are bound to that path. Record the selected session/PID as a transaction snapshot, then reread canonical path, size, last-write timestamp, and SHA256. Run the complete step-2 premutation preflight before creating any backup. The backup code below is the exact delayed backup action and must execute only after every step-2 target/name/neighbor invariant passes. This ordering preserves the `2026-08-04T14:47:00-04:00` fail-closed behavior, where a target-name prestate mismatch stopped the attempt before backup or mutation. After backup succeeds, immediately repeat `idb_list`, `server_health`, canonical disk identity, both exact-name queries, target `inspect_items`, and every protected prestate before entering step 3. Abort unless backup size/hash equals canonical prestate exactly and the repeated prestate still matches.

> Executable block R001 was removed from this report and preserved verbatim in [0002W1-g_fpsLogEnabled-empty-emitter-source-quality-removed.md](0002W1-g_fpsLogEnabled-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

2. **Complete bounded preflight and collision checks before backup.** Run every exact read-only request below against `<gate2b-database>`. Compare each result to I2W1-01..06/P2W1-01..06. Every query batch has ten or fewer entries. Before backup/mutation, the two exact-name queries must both return `total:0` with empty data/no error, while `inspect_items(0x69b338)` must independently render synthetic `name:"unk_69B338"` on the exact raw, untyped, non-data one-byte item. This combination proves an available synthetic rename input without a user-defined source/destination collision. Any enumerated hit for either spelling, different target rendering, missing/truncated result, error, other prestate drift, or disk/session drift aborts before backup/mutation. Only a complete pass authorizes the exact timestamped backup block in step 1; after that backup, repeat the stated authority/name/target/protection reads before the dry run.

```text
entity_query {"database":"<gate2b-database>","queries":[{"kind":"names","regex":"^g_fpsLogEnabled$","offset":0,"count":10,"sort_by":"addr","descending":false,"fields":["addr","name"]},{"kind":"names","regex":"^unk_69B338$","offset":0,"count":10,"sort_by":"addr","descending":false,"fields":["addr","name"]}]}
inspect_items {"database":"<gate2b-database>","addrs":["0x69b334","0x69b335","0x69b336","0x69b337","0x69b338","0x69b339","0x69b33a","0x69b33b","0x69b33c","0x69b33d"]}
inspect_items {"database":"<gate2b-database>","addrs":["0x69b33e","0x69b33f","0x69b340","0x4b653f","0x4b6645","0x4b6a17","0x4b6ae4"]}
get_bytes {"database":"<gate2b-database>","regions":[{"addr":"0x69b330","size":24},{"addr":"0x4b653f","size":7},{"addr":"0x4b6645","size":7},{"addr":"0x4b6a17","size":7},{"addr":"0x4b6ae4","size":7}]}
get_int {"database":"<gate2b-database>","queries":[{"addr":"0x69b334","ty":"u32le"},{"addr":"0x69b338","ty":"u8"},{"addr":"0x69b339","ty":"u8"},{"addr":"0x69b33a","ty":"u8"},{"addr":"0x69b33b","ty":"u8"},{"addr":"0x69b33c","ty":"u32le"}]}
get_comments {"database":"<gate2b-database>","addrs":["0x69b334","0x69b335","0x69b336","0x69b337","0x69b338","0x69b339","0x4b653f","0x4b6645","0x4b6a17","0x4b6ae4"]}
get_comments {"database":"<gate2b-database>","addrs":["0x69b33a","0x69b33b","0x69b33c","0x69b33d","0x69b33e","0x69b33f","0x69b340"]}
xrefs_to {"database":"<gate2b-database>","addrs":["0x69b334","0x69b335","0x69b336","0x69b337","0x69b338","0x69b339","0x69b33a","0x69b33b","0x69b33c","0x69b340"],"limit":50}
xrefs_to {"database":"<gate2b-database>","addrs":["0x69b33d","0x69b33e","0x69b33f"],"limit":50}
xref_query {"database":"<gate2b-database>","queries":[{"addr":"0x4b653f","direction":"both","xref_type":"any","offset":0,"count":50,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x4b6645","direction":"both","xref_type":"any","offset":0,"count":50,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x4b6a17","direction":"both","xref_type":"any","offset":0,"count":50,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x4b6ae4","direction":"both","xref_type":"any","offset":0,"count":50,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}]}
insn_query {"database":"<gate2b-database>","queries":[{"start":"0x4b653f","end":"0x4b6546","offset":0,"count":4,"max_scan_insns":4,"include_fn":true,"include_disasm":true},{"start":"0x4b6645","end":"0x4b664c","offset":0,"count":4,"max_scan_insns":4,"include_fn":true,"include_disasm":true},{"start":"0x4b6a17","end":"0x4b6a1e","offset":0,"count":4,"max_scan_insns":4,"include_fn":true,"include_disasm":true},{"start":"0x4b6ae4","end":"0x4b6aeb","offset":0,"count":4,"max_scan_insns":4,"include_fn":true,"include_disasm":true}]}
```

3. **Deterministic collision dry-run, rename, target definition, and type.** Before any mutation, run the exact validation-only rename call below with actual old-name input `unk_69B338`; the dated report-time dry run already returned one valid data rename with no final-name creation, but Gate 2B must repeat it under fresh authority after the synthetic-rendering/zero-index-hit preflight passes. It must report `total:1,ok:1,failed:0,dry_run:true`, no overwrite, and no physical/comment/xref/name-index delta: exact-name queries remain zero for both spellings and `inspect_items.name` remains synthetic `unk_69B338` after the dry run. Then apply only the three mutation calls below in order. After each non-dry-run call, immediately rerun the complete step-2 package with the action-appropriate poststate. After actual `rename`, permit only creation of the sole exact `g_fpsLogEnabled` name hit plus stored/display/operand name delta on the unchanged raw one-byte item and require zero exact `unk_69B338` hits; after `make_data`, permit only conversion of that exact byte into one `unsigned char` data item with the same final name; after `set_type`, permit only its type change to width-one `bool`. Any extra item/type/name/range/comment/xref/instruction/neighbor delta stops before the next action.

```text
rename {"database":"<gate2b-database>","batch":{"data":[{"old":"unk_69B338","new":"g_fpsLogEnabled"}],"stop_on_error":true,"dry_run":true,"allow_overwrite":false}}
rename {"database":"<gate2b-database>","batch":{"data":[{"old":"unk_69B338","new":"g_fpsLogEnabled"}],"stop_on_error":true,"dry_run":false,"allow_overwrite":false}}
make_data {"database":"<gate2b-database>","items":[{"addr":"0x69b338","type":"unsigned char g_fpsLogEnabled","name":"g_fpsLogEnabled","delete_existing":true}]}
set_type {"database":"<gate2b-database>","edits":[{"addr":"0x69b338","ty":"bool","name":"g_fpsLogEnabled","kind":"global"}]}
```

If current MCP/IDA cannot make `set_type` read back exactly one-byte `bool` on the unchanged `0x69b338-0x69b339` item, or if either rename result is nondeterministic, the primary supervisor must use the no-save rollback and narrow I2W1-01 to **no target data mutation** for this report. Do not substitute `_BOOL4`, `BOOL`, `int`, a dword, an aggregate, a neighboring-byte merge, an overwrite, or an unverified spelling.

4. **Exact comment calls with immediate complete readback.** Only after I2W1-01 passes, apply I2W1-02, rerun the full step-2 package, then apply I2W1-03..06 in the single four-item call and rerun the full package again. No other comment channel may change.

```text
set_repeatable_comments {"database":"<gate2b-database>","items":[{"addr":"0x69b338","comment":"Default-off FpsPane log-output gate; source definition belongs to FpsPane.cpp and all four static references are reads."}]}
set_comments {"database":"<gate2b-database>","items":[{"addr":"0x4b653f","comment":"Gate new FPS log-file creation on g_fpsLogEnabled."},{"addr":"0x4b6645","comment":"Gate FPS log finalization/summary output on g_fpsLogEnabled."},{"addr":"0x4b6a17","comment":"Gate retained StartLogSession file output on g_fpsLogEnabled."},{"addr":"0x4b6ae4","comment":"Return from retained WriteLogSummary when FPS logging is disabled."}]}
```

5. **Unsaved final closure.** Before save, repeat `idb_list`, selected-session `server_health`, canonical disk identity, and the complete step-2 package. The canonical disk hash/size/timestamp must still equal prestate because no save has occurred. Name queries must return exactly one `g_fpsLogEnabled` hit at `0x69b338` and no remaining `unk_69B338` enumerated hit. Require all I2W1 poststates, all P2W1 prestates, exactly four target xrefs, exact use-site bytes/control/data edges, exact comments, and no missing/truncated/error result. Any failure uses no-save rollback; no later manual/generated/lifecycle work may proceed.

6. **One save and fresh-reopen persistence proof.** Only after complete unsaved closure, call exactly once:

```text
idb_save {"database":"<gate2b-database>","path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64"}
```

Record save result and the new canonical disk size/SHA256/timestamp. The primary supervisor then stops only `<gate2b-worker-pid>` through its controlled worker teardown, proves the session/PID is gone while the MCP listener remains available, and calls:

```text
idb_open {"input_path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","mode":"prefer_headless","run_auto_analysis":false,"build_caches":true,"init_hexrays":true,"idle_ttl_sec":3600,"preferred_session_id":"b009-uid0002w1-persist-reopen"}
```

The returned `<persist-database>`/PID must be a fresh transaction snapshot. Run `server_health`, reread the just-saved disk identity, and rerun the entire step-2 package with the poststate name expectations. All I2W1 and P2W1 rows must persist exactly. Do not save after persistence verification, and never call that session/PID permanent authority.

7. **Exact unsaved rollback.** On any mismatch after the first mutation but before `idb_save`, record the failed call/result, never save, stop only `<gate2b-worker-pid>` through primary-supervisor process control, prove it is gone, and prove canonical disk path/size/SHA256 still equal the captured prestate. Then reopen with the same step-6 `idb_open` fields except `preferred_session_id:"b009-uid0002w1-nosave-rollback-verify"`. Rerun every step-2 prestate request and require the captured target prestate: synthetic `inspect_items.name:"unk_69B338"`, zero exact-name enumerated hits for both spellings, blank type, `is_code:false,is_data:false`, unchanged raw one-byte heads, zero values, blank comments, synthetic operands, exact xrefs, UID0002W2, and both neighbors. Do not save the rollback verifier. Because current MCP exposes no `idb_close`/discard call, failure to stop the dirty worker is a hard halt, not permission to improvise an inverse mutation.

> Executable block R002 was removed from this report and preserved verbatim in [0002W1-g_fpsLogEnabled-empty-emitter-source-quality-removed.md](0002W1-g_fpsLogEnabled-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

8. **Exact saved rollback.** If save succeeds but fresh-reopen persistence fails, record the failed invariant; stop `<persist-worker-pid>`; require fresh `idb_list` to show no session bound to canonical path; copy `<backup-path>` over canonical; require restored size/SHA256 exactly equal backup and recorded prestate; reopen with the step-6 fields except `preferred_session_id:"b009-uid0002w1-saved-rollback-verify"`; rerun every step-2 prestate request; and require the complete original I2W1/P2W1 prestate. Do not save the rollback verifier. A rollback mismatch halts the larger supervisor goal for investigation.

> Executable block R003 was removed from this report and preserved verbatim in [0002W1-g_fpsLogEnabled-empty-emitter-source-quality-removed.md](0002W1-g_fpsLogEnabled-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Negative transaction constraints: never rename/type/comment/define UID0002W2, never consume `0x69b339`, never aggregate any neighboring bytes, never patch bytes or instructions, never create a writer, never overwrite an existing name, never accept partial readback, and never save after any mismatch.

`````

## Additional removed operational lines: mirrored prose cleanup

The following source-report lines were removed during the same cleanup because they retained transaction orchestration outside Section 21. They are non-authoritative historical material and must never be executed.

`````text
The supervisor-only IDA recommendation is a literal fail-closed transaction rather than advisory prose: dynamic authority binding, exact-name collision checks, synthetic-auto-name-aware target prestate, hash-matched timestamped backup, one-row-per-entity prestates, bounded current-schema calls, immediate complete readbacks, protected UID0002W2/neighbors, one save, fresh reopen, and exact no-save/saved rollback. The `2026-08-04T14:47:00-04:00` supervisor attempt stopped before backup or mutation because the then-current `inspect_items` target rendering was already synthetic `unk_69B338`, not the report's former literal blank-name expectation, while both exact-name entity queries returned zero. This report repair reconciles that distinction and does not authorize B009 to perform any part of the transaction.

| CW1-044 | The post-B002 read-only recheck reconfirms synthetic target rendering `inspect_items.name:"unk_69B338"` together with zero exact-name user-defined hits/collisions for both spellings. The accepted supervisor-owned I2W1-01 recommendation is the literal dynamic-bind/preflight/backup and collision-safe dry-run/actual `rename` from actual old input `unk_69B338` to `g_fpsLogEnabled` -> `make_data` -> `set_type`, immediate full readback, save/reopen, and rollback transaction below; any nondeterministic poststate narrows to no mutation. | IDA Gate 2B handoff I2W1-01 | incorporate | proposed |

UID0002W1 is implemented in ordinary documentation as a reconstructable, file-owned physical storage child fully source-accounted through UID0000PZ rather than an empty or duplicate emitter. The covered-by comment, exact PE evidence, dated MCP facts, resolved `bool`/name/default/no-writer conclusions, scores, support corrections, and UID0002W2 reclassification are recorded in the accepted implementation evidence. The `2026-08-04T14:47:00-04:00` supervisor Gate 2B attempt correctly stopped before backup or mutation because the report demanded a blank target display name while fresh `inspect_items` already rendered synthetic `unk_69B338`; both exact-name indexes were empty and every neighbor was exact. The later post-B002 read-only recheck under canonical disk SHA256 `CE0222E87E1A569A73EB43DD72BF53412B103DD9281A535EEC2BCC01DE0932FA` reconfirmed that repaired distinction and every I2W1/P2W1 prestate, proving the unrelated B002 save was compatible. The stable Gate 2B recommendation is an apply-or-fail-closed literal transaction: dynamic session/disk binding, complete preflight before backup, hash-matched timestamped backup, exact staged one-byte rename from actual old input `unk_69B338` to desired `g_fpsLogEnabled`, one-byte definition/type, five exact comment actions, immediate full readbacks, protected UID0002W2 and neighbor items, one save/fresh reopen, and exact rollback. UID0002W2's ordinary-document rename does not authorize renaming, typing, commenting, aggregating, or otherwise mutating its three IDA bytes. Manual coverage disposition, independent generated/aggregate verification with dynamic tracker reread, and report lifecycle handling are supervisor-owned; whether those operations have occurred is determined only from current physical artifacts plus matching audit and validator history.

- [ ] CW1-044 B009 did not perform the supervisor-owned I2W1-01 transaction. The accepted recommendation dynamically binds authority, requires synthetic `inspect_items.name:"unk_69B338"` plus zero enumerated exact-name hits for both spellings, completes all prestates before backup, creates/hash-checks backup, repeats authority/name/target protections, and uses the literal dry-run/actual rename from old input `unk_69B338` to `g_fpsLogEnabled`, `make_data`, `set_type`, full immediate readbacks, save/reopen, and rollback contract. Nondeterministic one-byte `bool` narrows to no mutation.
`````
