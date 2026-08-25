<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0003X0-RankingCategoryRecordVectorInsertWithGrowth-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0003X0-RankingCategoryRecordVectorInsertWithGrowth-source-quality.md](0003X0-RankingCategoryRecordVectorInsertWithGrowth-source-quality.md)
- Source report SHA256 before cleanup: `C47C64A3CECA3785F9903B23AD29E88C9FDEFAD309839F298BE66943DFBFF001`
- Cleanup generated: `2026-08-11T12:47:03Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `375-379`
- Original language: `powershell`
- Block SHA256: `D1EA1F6A41707E917822F363BA6BA6936C481C1FF7D2FDF212A98B1CB7CD8AEB`

```powershell
$p = 'E:\NTK\Resources\NexusTK\NexusTK.exe.i64'
$fs = [System.IO.File]::Open($p,[System.IO.FileMode]::Open,[System.IO.FileAccess]::Read,[System.IO.FileShare]::None)
try { $sha=[System.Security.Cryptography.SHA256]::Create(); $hash=([BitConverter]::ToString($sha.ComputeHash($fs))).Replace('-',''); $length=$fs.Length; $mtime=[System.IO.File]::GetLastWriteTimeUtc($p); $mtimeTicks=$mtime.Ticks } finally { if($sha){$sha.Dispose()}; $fs.Dispose() }
```

## Removed Block CLEANUP-20260813-0003X0-OUTSIDE21-RUNBOOK

Source: [0003X0-RankingCategoryRecordVectorInsertWithGrowth-source-quality.md](0003X0-RankingCategoryRecordVectorInsertWithGrowth-source-quality.md)

This archive is non-authoritative and must never be executed. It preserves the exact report lines removed during supervisor cleanup.

<!-- BEGIN CLEANUP-20260813-0003X0-OUTSIDE21-RUNBOOK -->
49: - Gate 2B must preserve authoritative closed P0/B0 captured before transaction open. While the transaction worker is active, pre-save authority is complete in-memory RB-X0 only; any filesystem observation is explicitly nonexclusive/non-authoritative. The first new authoritative closed-disk tuple after transaction open is permitted only after exact transaction-worker retirement, generation-absence/no-active-canonical proof, and successful `FileShare.None`.
141: | C0003X0-032 | 0003X0 | Enforce the source/schema-locked wrapper-complete fail-closed one-save transaction: preserve authoritative pre-open P0/B0, use only RB-X0 plus optional non-authoritative/nonexclusive disk observation while the transaction worker is active, acquire the first new authoritative closed-disk tuple only after exact worker retirement/absence/FileShare.None, and preserve literal P05-P10, complete post-retirement classification, guarded rollback, deterministic P0-mtime restoration, and narrowed P11. | certain | transaction package | IDA transaction | primary supervisor Gate2B | incorporate | proposed |
313: - Gate 2B is executable only through the installed-source/schema-locked wrapper package: frozen authoritative P0/B0 before transaction open, complete in-memory RB-X0 and at most a labeled non-authoritative/nonexclusive disk observation before save, exact worker-generation retirement before the first new authoritative closed-disk tuple, five-field post-retirement classification, one-save/no-retry handling, and guarded deterministic rollback. Discovery, active-worker closed-disk authority, or shorthand substitution is forbidden.
405: - Primary supervisor: independently verify ordinary claims, rebind installed source/schema identities, execute the wrapper-complete Gate 2B package with frozen pre-open P0/B0, in-memory-only authoritative pre-save RB-X0, first post-open authoritative disk tuple only after exact worker retirement/absence/FileShare.None, literal P05-P10 and one-save/rollback protections, apply exact manual rows, run coherent generated refresh, verify generated semantics, then perform lifecycle and post-move audit under external authority.
513: | [ ] | C0003X0-032 | 0003X0 | Enforce the source/schema-locked wrapper-complete fail-closed one-save transaction: preserve authoritative pre-open P0/B0, use only RB-X0 plus optional non-authoritative/nonexclusive disk observation while the transaction worker is active, acquire the first new authoritative closed-disk tuple only after exact worker retirement/absence/FileShare.None, and preserve literal P05-P10, complete post-retirement classification, guarded rollback, deterministic P0-mtime restoration, and narrowed P11. | IDA transaction | primary supervisor Gate2B | incorporate | proposed |
<!-- END CLEANUP-20260813-0003X0-OUTSIDE21-RUNBOOK -->

## Removed Block CLEANUP-20260813-0003X0-SECTION21

Source: [0003X0-RankingCategoryRecordVectorInsertWithGrowth-source-quality.md](0003X0-RankingCategoryRecordVectorInsertWithGrowth-source-quality.md)

This archive is non-authoritative and must never be executed. It preserves the exact report text removed during supervisor cleanup.

<!-- BEGIN CLEANUP-20260813-0003X0-SECTION21 -->
## IDA Rename / Type / Comment Recommendations

All actions are primary-supervisor-only. B002 used read-only MCP only. Every future Gate 2B must dynamically bind the current canonical disk and a fresh session; the dated research session and hash above are evidence snapshots only.

### Installed endpoint and schema feasibility lock

The following installed-source identities were reread during this same-report repair. They are a dated feasibility snapshot, not permanent authority; immediately before Gate 2B the primary supervisor must rehash every file and reread `tools/list`. Any byte, schema, description, routing, or implementation drift stops before a diagnostic or transaction worker is opened and returns this same report for reconciliation.

| Installed source | Bytes | SHA256 | Bound behavior |
| --- | ---: | --- | --- |
| `C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp\idalib_supervisor.py` | 52468 | `2D7098B6BDB58D7DCF8CF4825BBE7584F5E7ACB256AD318B05482E9A0B9AF10A` | `idb_open`, worker routing, `idb_list`, and `idb_save` supervision |
| `C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp\ida_mcp\api_core.py` | 34004 | `90C59B3F64F26E170CC604000CE39B34B648352767059DD1C2DF1914E9CBD4A3` | function lookup and server/core inspection |
| `C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp\ida_mcp\api_analysis.py` | 79961 | `4C9B9122A7D2697CD464C1F473A227A580FD803515A1C885A1AA262259F1969F` | disassembly/xref inspection schemas |
| `C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp\ida_mcp\api_modify.py` | 51759 | `161B314A14DAAA34C718176444292597BBB7498FA80158E25C358542BC16D1B8` | pure rename and regular function-comment implementation |
| `C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp\ida_mcp\api_stack.py` | 5502 | `9E4B5898E875812E4C993597D44F0F6438430F92A8B2299DC5C62630D49AE1BB` | complete physical frame readback |
| `C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp\ida_mcp\api_types.py` | 37540 | `A3E7444BBAC0066B48EDF38E26F34E6ABEC823585CD50E43C6DA98C55B965ECF` | `type_inspect` and function `set_type` through `apply_tinfo` |
| `C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp\ida_mcp\api_memory.py` | 9583 | `A2D4E48921E2E7A8D3C4BD621658F645A9C17C7FB34E963E62AE864E452ABC93` | byte readback |
| `C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp\ida_mcp\utils.py` | 43500 | `5139910EA7496549A31EDD6F9EEE7B033DA16504E4F0D19C8052EC9ED1C62069` | `RenameBatch.pure` schema and helper semantics |

The accepted schemas are exact: `idb_open` takes `input_path`, `mode`, `run_auto_analysis`, `build_caches`, `init_hexrays`, `idle_ttl_sec`, and `preferred_session_id`; `idb_list` takes `{}`; worker calls carry a top-level `database`; `lookup_funcs` takes `queries`; `disasm` takes `addr`, `max_instructions`, `offset`, and `include_total`; `stack_frame`, `get_comments`, and `inspect_items` take `addrs`; `get_bytes` takes `regions[{addr,size}]`; `xrefs_to` takes `addrs` and `limit`; `xref_query` takes bounded `queries`; `type_inspect` takes `queries[{name,include_members,max_members}]`; `rename` takes `batch`; `set_type` takes `edits`; `set_function_comments` takes `items`; and `idb_save` takes `path`. The source lock additionally proves `rename` with `pure:true` skips `/vibe/` placement and `refresh_decompiler_ctext`, `set_type(kind=function)` uses type parsing plus `ida_typeinf.apply_tinfo`, and `set_function_comments` invokes only `idc.set_func_cmt(...,False)`.

Every session name below is role-specific and must receive one common UTC transaction suffix replacing `<UTCSTAMP>`; no name may already exist in `idb_list`. Every open is `force_headless`, disables auto analysis, and specifies cache/Hex-Rays policy explicitly. Only the disposable diagnostic worker enables process-local caches and Hex-Rays; every canonical transaction/verifier/rollback worker disables both.

```text
idb_open {"input_path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","mode":"force_headless","run_auto_analysis":false,"build_caches":true,"init_hexrays":true,"idle_ttl_sec":3600,"preferred_session_id":"b002-uid0003x0-diagnostic-<UTCSTAMP>"}
idb_open {"input_path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","mode":"force_headless","run_auto_analysis":false,"build_caches":false,"init_hexrays":false,"idle_ttl_sec":3600,"preferred_session_id":"b002-uid0003x0-transaction-<UTCSTAMP>"}
idb_open {"input_path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","mode":"force_headless","run_auto_analysis":false,"build_caches":false,"init_hexrays":false,"idle_ttl_sec":3600,"preferred_session_id":"b002-uid0003x0-verify-success-<UTCSTAMP>"}
idb_open {"input_path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","mode":"force_headless","run_auto_analysis":false,"build_caches":false,"init_hexrays":false,"idle_ttl_sec":3600,"preferred_session_id":"b002-uid0003x0-verify-save-failure-<UTCSTAMP>"}
idb_open {"input_path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","mode":"force_headless","run_auto_analysis":false,"build_caches":false,"init_hexrays":false,"idle_ttl_sec":3600,"preferred_session_id":"b002-uid0003x0-verify-indeterminate-<UTCSTAMP>"}
idb_open {"input_path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","mode":"force_headless","run_auto_analysis":false,"build_caches":false,"init_hexrays":false,"idle_ttl_sec":3600,"preferred_session_id":"b002-uid0003x0-rollback-verify-<UTCSTAMP>"}
```

### Literal target prestate

| ID | Entity | Exact current prestate | Proposed action | Exact required poststate |
| --- | --- | --- | --- | --- |
| I01 | function name at `0x0045cf50` | `sub_45CF50`; collision absence for the proposed name must be freshly checked | pure function rename to `RankingCategoryRecordVectorInsertWithGrowth` | only function name changes; no `/vibe/`, decompiler refresh, directory link, or other name changes |
| I02 | function type/frame at `0x0045cf50` | type `int __thiscall(int *this, int, int)` and exact 19-row frame listed in IDA MCP Facts | set function type to `RankingCategoryRecord *__thiscall RankingCategoryRecordVectorInsertWithGrowth(RankingCategoryRecordVectorStorage *this, RankingCategoryRecord *position, const RankingCategoryRecord *value)` | return/receiver/arguments match exact semantic type; only physical `arg_0` becomes `position` type `RankingCategoryRecord *` and `arg_4` becomes `value` type `const RankingCategoryRecord *`; all 17 other frame rows remain exact and no row is added/removed |
| I03 | function regular comment | address regular absent; address repeatable absent; function regular absent; function repeatable absent | set function-regular comment to `Compiler-generated std::vector<RankingCategoryRecord> growth/insert slow path for RankingCategoryCollection::m_records: allocates enlarged storage, deep-copies the inserted record and surrounding ranges, destroys and frees old storage, and rolls back partial construction on exception; no standalone source helper.` | function regular equals exact text; other three channels remain absent |

### Literal mutation calls

```text
rename {"batch":{"func":{"addr":"0x0045cf50","name":"RankingCategoryRecordVectorInsertWithGrowth"},"dry_run":true,"stop_on_error":true,"allow_overwrite":false,"pure":true},"database":"<fresh-transaction-session>"}
rename {"batch":{"func":{"addr":"0x0045cf50","name":"RankingCategoryRecordVectorInsertWithGrowth"},"dry_run":false,"stop_on_error":true,"allow_overwrite":false,"pure":true},"database":"<fresh-transaction-session>"}
set_type {"edits":{"addr":"0x0045cf50","kind":"function","signature":"RankingCategoryRecord *__thiscall RankingCategoryRecordVectorInsertWithGrowth(RankingCategoryRecordVectorStorage *this, RankingCategoryRecord *position, const RankingCategoryRecord *value)"},"database":"<fresh-transaction-session>"}
set_function_comments {"items":{"addr":"0x0045cf50","comment":"Compiler-generated std::vector<RankingCategoryRecord> growth/insert slow path for RankingCategoryCollection::m_records: allocates enlarged storage, deep-copies the inserted record and surrounding ranges, destroys and frees old storage, and rolls back partial construction on exception; no standalone source helper."},"database":"<fresh-transaction-session>"}
```

- `rename` must expose and honor `pure:true`; dry-run must return one valid action and no `dir`/`dir_error` field. Schema/implementation drift stops before a canonical transaction.
- `set_function_comments` is the regular-function-only endpoint. No address or repeatable comment endpoint is authorized.
- Every `idb_open` must use the exact wrapper above; an omitted mode, analysis, cache, Hex-Rays, TTL, or unique-session field is a hard stop.
- In the four preserved mutation calls, `<fresh-transaction-session>` is bound verbatim to the exact session ID returned by `b002-uid0003x0-transaction-<UTCSTAMP>`; it is not a second session or an unresolved runtime choice.
- No local/stack rename endpoint is needed. I02 must produce the complete deterministic physical frame directly; any additional renamed/retyped/added/removed row stops unsaved.

### Wrapper-complete collision, baseline, and readback package

`RB-X0` below is the sole inspection package permitted in the frozen canonical transaction, persistence verifier, save-failure verifier, indeterminate verifier, and rollback verifier. Replace `<RB-SESSION>` with the exact role-specific session returned by the corresponding literal `idb_open`; do not omit the top-level `database`. Run every line, require every item/result, and retain the complete JSON responses. A truncated batch, error item, missing entity, changed ordering, or unparseable response is a failed readback. The diagnostic worker may run additional analysis-producing calls only before its no-save retirement; none of those calls or results belongs to `RB-X0` or receives action credit.

```text
idb_list {}
server_health {"database":"<RB-SESSION>"}
lookup_funcs {"queries":["0x0045cf50","sub_45CF50","RankingCategoryRecordVectorInsertWithGrowth","0x0045c2a0","0x0045c560","0x0045d420","0x0045d5c0","0x0045d5f0","0x0045d660","0x0045d750","0x005c7526","0x005cd607","0x00421500","??2@YAPAXI@Z","__CxxThrowException@8"],"database":"<RB-SESSION>"}
disasm {"addr":"0x0045cf50","max_instructions":5000,"offset":0,"include_total":true,"database":"<RB-SESSION>"}
disasm {"addr":"0x0045c2a0","max_instructions":2000,"offset":0,"include_total":true,"database":"<RB-SESSION>"}
disasm {"addr":"0x0045c560","max_instructions":3000,"offset":0,"include_total":true,"database":"<RB-SESSION>"}
disasm {"addr":"0x0045d420","max_instructions":1000,"offset":0,"include_total":true,"database":"<RB-SESSION>"}
disasm {"addr":"0x0045d5c0","max_instructions":500,"offset":0,"include_total":true,"database":"<RB-SESSION>"}
disasm {"addr":"0x0045d5f0","max_instructions":500,"offset":0,"include_total":true,"database":"<RB-SESSION>"}
disasm {"addr":"0x0045d660","max_instructions":500,"offset":0,"include_total":true,"database":"<RB-SESSION>"}
disasm {"addr":"0x0045d750","max_instructions":500,"offset":0,"include_total":true,"database":"<RB-SESSION>"}
stack_frame {"addrs":["0x0045cf50","0x0045c2a0","0x0045c560","0x0045d420","0x0045d5c0","0x0045d5f0","0x0045d660","0x0045d750","0x005c7526","0x005cd607","0x00421500"],"database":"<RB-SESSION>"}
get_comments {"addrs":["0x0045cf44","0x0045cf50","0x0045c4f1","0x0045c502","0x0045c514","0x0045c7cb","0x0045c7dc","0x0045c7ee","0x0045d07b","0x0045d0a9","0x0045d0c8","0x0045d0d9","0x0045d0f9","0x0045d17e","0x0045d187","0x0045d195","0x0045d19e","0x0045d1ad","0x0045d420","0x0045d5c0","0x0045d5f0","0x0045d660","0x0045d750","0x005c7526","0x005cd607","0x00421500"],"database":"<RB-SESSION>"}
inspect_items {"addrs":["0x0045cf44","0x0045cf50","0x0045c4f1","0x0045c502","0x0045c514","0x0045c7cb","0x0045c7dc","0x0045c7ee","0x0045d07b","0x0045d0a9","0x0045d0c8","0x0045d0d9","0x0045d0f9","0x0045d17e","0x0045d187","0x0045d195","0x0045d19e","0x0045d1ad","0x0045d1b0","0x0045d420","0x0045d5c0","0x0045d5f0","0x0045d660","0x0045d750","0x005c7526","0x005cd607","0x00421500"],"database":"<RB-SESSION>"}
get_bytes {"regions":[{"addr":"0x0045cf44","size":12},{"addr":"0x0045cf50","size":605},{"addr":"0x0045d1ad","size":3},{"addr":"0x0045c4f1","size":5},{"addr":"0x0045c502","size":5},{"addr":"0x0045c514","size":5},{"addr":"0x0045c7cb","size":5},{"addr":"0x0045c7dc","size":5},{"addr":"0x0045c7ee","size":5},{"addr":"0x0045d07b","size":5},{"addr":"0x0045d0a9","size":5},{"addr":"0x0045d0c8","size":5},{"addr":"0x0045d0d9","size":5},{"addr":"0x0045d0f9","size":5},{"addr":"0x0045d17e","size":32},{"addr":"0x0045d187","size":5},{"addr":"0x0045d195","size":5},{"addr":"0x0045d19e","size":5},{"addr":"0x0045d420","size":216},{"addr":"0x0045d5c0","size":43},{"addr":"0x0045d5f0","size":99},{"addr":"0x0045d660","size":118},{"addr":"0x0045d750","size":58},{"addr":"0x005c7526","size":14},{"addr":"0x005cd607","size":29}],"database":"<RB-SESSION>"}
xrefs_to {"addrs":["0x0045cf50","0x0045d420","0x0045d5c0","0x0045d5f0","0x0045d660","0x0045d750","0x005c7526","0x005cd607","0x00421500"],"limit":1000,"database":"<RB-SESSION>"}
xref_query {"queries":[{"addr":"0x0045cf50","direction":"to","xref_type":"code","offset":0,"count":1000,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x0045cf50","direction":"to","xref_type":"data","offset":0,"count":1000,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x0045d420","direction":"to","xref_type":"code","offset":0,"count":1000,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x0045d5c0","direction":"to","xref_type":"code","offset":0,"count":1000,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x0045d5f0","direction":"to","xref_type":"code","offset":0,"count":1000,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x0045d660","direction":"to","xref_type":"code","offset":0,"count":1000,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x0045d750","direction":"to","xref_type":"code","offset":0,"count":1000,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}],"database":"<RB-SESSION>"}
type_inspect {"queries":[{"name":"RankingCategoryRecord","include_members":true,"max_members":32},{"name":"RankingCategoryRecordVectorStorage","include_members":true,"max_members":16},{"name":"RankingUserEntryVectorStorage","include_members":true,"max_members":16}],"database":"<RB-SESSION>"}
```

The collision package is the `lookup_funcs` line above plus the preserved pure dry-run call. It must show target address/name `sub_45CF50`, proposed-name absence, and exactly one valid dry-run action. The same `RB-X0` package is run at raw transaction baseline, immediately after each of the four mutation calls, as the complete pre-save readback, in the success/save-failure/indeterminate verifier selected by the save outcome, and in the rollback verifier after any authorized restore.

Literal wrapper binding is fixed: transaction S0/immediate/pre-save reads use `database:"b002-uid0003x0-transaction-<UTCSTAMP>"`; determinate-success reads use `database:"b002-uid0003x0-verify-success-<UTCSTAMP>"`; explicit-save-failure classification reads use `database:"b002-uid0003x0-verify-save-failure-<UTCSTAMP>"`; timeout/disconnect/missing-response classification reads use `database:"b002-uid0003x0-verify-indeterminate-<UTCSTAMP>"`; and restored-prestate reads use `database:"b002-uid0003x0-rollback-verify-<UTCSTAMP>"`. In each case `<RB-SESSION>` in every JSON line is replaced with exactly that one returned session ID before submission; cross-session or omitted-wrapper calls are forbidden.

### Complete protected state

- P01 target range/item/body: exact `[0x45cf50,0x45d1ad)`, 605 bytes, body SHA `E9C576F6F580639E629E25C6636C5EBD5C2F22968191930D582B4090AE021B8B`, 227 instructions, 39 blocks, complexity 13, and `retn 8`.
- P02 frame: the complete prestate is `var_40 +0x10/4/_DWORD`, `var_3C +0x14/4/_DWORD`, `var_38 +0x18/4/_DWORD`, `var_34 +0x1c/4/_DWORD`, `Block +0x20/4/void *`, `var_2C +0x24/4/_DWORD`, `var_28 +0x28/4/_DWORD`, `var_24 +0x2c/4/_DWORD`, `var_20 +0x30/4/_DWORD`, `var_1C +0x34/4/int`, `var_18 +0x38/4/_DWORD`, `var_14 +0x3c/4/_DWORD`, `var_10 +0x40/4/_DWORD`, `var_C +0x44/4/_DWORD`, `var_4 +0x4c/4/_DWORD`, `__saved_registers +0x50/4/_DWORD`, `__return_address +0x54/4/_UNKNOWN *`, `arg_0 +0x58/4/_DWORD`, and `arg_4 +0x5c/4/_DWORD`, with no other row. Permitted deltas are only the last two rows becoming `position +0x58/4/RankingCategoryRecord *` and `value +0x5c/4/const RankingCategoryRecord *`. All first 17 rows and every offset/width remain literal; no row may be added or removed.
- P03 comments: only function regular changes to I03. Address regular/repeatable and function repeatable remain absent.
- P04 xrefs: exactly two incoming code xrefs at `0x45c502` and `0x45c7dc`; no new data route.
- P05 caller items are literal: `sub_45C2A0 [0x45c2a0,0x45c556)` size `0x2b6` owns code calls `[0x45c4f1,0x45c4f6)` bytes `e8 2a 0f 00 00` -> `0x45d420`, `[0x45c502,0x45c507)` bytes `e8 49 0a 00 00` -> target, and `[0x45c514,0x45c519)` bytes `e8 d7 10 00 00` -> `0x45d5f0`. `sub_45C560 [0x45c560,0x45cb0a)` size `0x5aa` owns `[0x45c7cb,0x45c7d0)` bytes `e8 50 0c 00 00` -> `0x45d420`, `[0x45c7dc,0x45c7e1)` bytes `e8 6f 07 00 00` -> target, and `[0x45c7ee,0x45c7f3)` bytes `e8 fd 0d 00 00` -> `0x45d5f0`. Each is a five-byte code item, unnamed and untyped at the item head, with address regular/repeatable comments absent. The complete caller lookup/frame/disassembly responses are frozen at S0 and must compare exactly at every RB-X0 readback. Only rendered callee text at the two slow calls may reflect I01; bytes, item ranges, caller ownership, and xrefs may not change.
- P06 target call items/callees are literal: `[0x45d07b,0x45d080)` bytes `e8 a0 03 00 00` and `[0x45d0a9,0x45d0ae)` bytes `e8 72 03 00 00` call `sub_45D420 [0x45d420,0x45d4f8)` size `0xd8`; `[0x45d0c8,0x45d0cd)` bytes `e8 93 05 00 00` and `[0x45d0d9,0x45d0de)` bytes `e8 82 05 00 00` call `sub_45D660 [0x45d660,0x45d6d6)` size `0x76`; `[0x45d0f9,0x45d0fe)` bytes `e8 f2 04 00 00` calls `RankingUserEntryVectorDestroy [0x45d5f0,0x45d653)`; `[0x45d187,0x45d18c)` bytes `e8 34 04 00 00` calls `RankingCategoryRecordRangeDestroyUserEntries [0x45d5c0,0x45d5eb)`; `[0x45d195,0x45d19a)` bytes `e8 b6 05 00 00` calls `sub_45D750 [0x45d750,0x45d78a)`. The remaining exact outgoing set is `??2@YAPAXI@Z`, `sub_5C7526 [0x5c7526,0x5c7534)` type `void __cdecl sub_5C7526(void *Block)`, `sub_421500`, `__invalid_parameter_noinfo_noreturn [0x5cd607,0x5cd624)` type `void __cdecl __noreturn()`, and `__CxxThrowException@8`. Full target disassembly plus lookup/xrefs is compared as one ordered call-edge set; no missing, extra, retargeted, resized, retyped, renamed, or commented callee/item is accepted.
- P07 EH prefix `[0x45d17e,0x45d19e)` retains SHA256 `2B74BEEB2F4D02D62B144DCB3F0FC0351D687E3036DD7CF04C9420A2204ECF35`, and following call remains `__CxxThrowException@8`.
- P08 fences are literal: predecessor `[0x45cf44,0x45cf50)` is one unnamed, untyped, non-code data item, twelve `cc` bytes, SHA256 `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902`, both address comment channels absent, zero code/data xrefs; successor `[0x45d1ad,0x45d1b0)` is one unnamed, untyped, non-code data item, three `cc` bytes, SHA256 `E668F0A1B72560CED14C54488A25335D11336448950BB6485267EBC5EB3FECEE`, both address comment channels absent, zero xrefs, followed by function head `0x45d1b0`. Every item head/end/kind/name/type/comment/byte/xref fact is compared.
- P09 UDT readback is exhaustive. `RankingCategoryRecord` is size `0x2b0`/688 with exactly 15 members: `m_listIndex +0x0 size2 __int16`; `_idaAlignmentAfterListIndex +0x2 size2 char[2]`; `m_categoryId +0x4 size4 int`; `m_stateCode +0x8 size4 int`; `m_startTime +0xc size36 tm`; `m_endTime +0x30 size36 tm`; `m_title +0x54 size512 wchar_t[256]`; `m_totalRankCount +0x254 size4 int`; `m_userEntriesBegin +0x258 size4 RankingUserEntry *`; `m_userEntriesEnd +0x25c size4 RankingUserEntry *`; `m_userEntriesCapacityEnd +0x260 size4 RankingUserEntry *`; `m_loadedRowsCategoryId +0x264 size4 int`; `m_localPlayerRank +0x268 size4 int`; `m_reservedLocalPlayerFooter +0x26c size64 unsigned __int8[64]`; `m_localPlayerScore +0x2ac size4 int`. `RankingCategoryRecordVectorStorage` is size12 with `begin +0/4 RankingCategoryRecord *`, `end +4/4 RankingCategoryRecord *`, `capacityEnd +8/4 RankingCategoryRecord *`. `RankingUserEntryVectorStorage` is size12 with `begin +0/4 RankingUserEntry *`, `end +4/4 RankingUserEntry *`, `capacityEnd +8/4 RankingUserEntry *`. Exact names, order, offsets, widths, type spellings, counts, and sizes must match at every readback; no UDT edit is authorized.
- P10 helper/function prestates are itemized, not deferred discovery. UID0003X4 is `sub_45D420`, exact function `[0x45d420,0x45d4f8)` size `0xd8`, raw-body SHA `02E0572F07330D31B77690BD8BD7902EA80D564CB2A5B9305A0B1B57C51527E3`, per-record deep copy, with four exact target/fast-path calls listed in P05/P06. UID0003YU is `sub_45D660`, exact function `[0x45d660,0x45d6d6)` size `0x76`, raw-body SHA `95FC2BD32CC6853A9C43E12A2FA3C7EF95C9C496807F8793E3560A6AC366C564`, range deep copy, with two exact target calls. UID0003YS is `RankingCategoryRecordRangeDestroyUserEntries`, exact `[0x45d5c0,0x45d5eb)` size `0x2b`, body SHA `F0B538E7F49394DCC6AFEA6B6041D072FA9971DD4C711B8C61416B28F35574FC`, type `void __stdcall RankingCategoryRecordRangeDestroyUserEntries(RankingCategoryRecord *first, RankingCategoryRecord *last)`, frame `__saved_registers +0x8/4/_DWORD`, `__return_address +0xc/4/_UNKNOWN *`, `first +0x10/4/RankingCategoryRecord *`, `last +0x14/4/RankingCategoryRecord *`, function-regular comment exactly `Compiler-generated exception cleanup for a partially constructed RankingCategoryRecord range: destroys each record's m_userEntries vector over [first,last); source remains RankingCategoryCollection's std::vector<RankingCategoryRecord> growth operation.`, and its other three entry comment channels absent; its sole incoming code xref is `0x45d187`. UID0003YT is `RankingUserEntryVectorDestroy`, exact `[0x45d5f0,0x45d653)` size `0x63`, body SHA `B0F287B431E3F2C1303FA0CD8B060188E4A7A263B79F5EFEFEB403A8862CD44D`, type `void __thiscall RankingUserEntryVectorDestroy(RankingUserEntryVectorStorage *this)`, sole frame row `__return_address +0x8/4/_UNKNOWN *`, function-repeatable comment exactly `Compiler-generated std::vector<RankingUserEntry> storage teardown: frees begin using MSVC large-allocation validation and clears begin/end/capacity; source declaration remains RankingCategoryRecord::m_userEntries.`, other three entry channels absent, and nine incoming code xrefs `0x45bf56,0x45c2e8,0x45c514,0x45c5b6,0x45c7ee,0x45d0f9,0x45d516,0x45d548,0x45d5d6`. UID0001ZE is `sub_45D750`, exact `[0x45d750,0x45d78a)` size `0x3a`, raw-body SHA `0921D6FEADBC8333D7DA590E187A2061FBA375BDA274DFD28741F4BAF5EEC5F8`, 20 instructions, `retn 8`, sole incoming code xref `0x45d195`, exact callees `sub_5C7526` and `__invalid_parameter_noinfo_noreturn`. These raw hashes come from the same 2,679,296-byte NexusTK.exe image SHA `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632` already used for target/helper raw-byte evidence. For X4/YU/1ZE, whose reports do not authorize a semantic IDA type/comment change here, RB-X0 freezes and byte-compares their complete lookup/frame/comment/disassembly/get-bytes response at S0; no inferred type or comment is substituted. All helper bytes, items, names, displayed types, frames, comments, incoming/outgoing xrefs, and extents must repeat exactly after I01-I03 and reopen.
- P11 is deliberately narrow and mechanically testable. It does not claim process-local cache objects can never be allocated. The disposable diagnostic worker may build caches/initialize Hex-Rays but is discarded without save before P0. Canonical workers use `build_caches:false`, `init_hexrays:false`; their allowlist is only RB-X0, the four preserved mutation calls, and one `idb_save`. Source-hash lock proves pure rename performs no `/vibe/` placement or decompiler refresh, function `set_type` uses `apply_tinfo` without a decompile/refresh call, and `set_function_comments` writes only the regular function comment. Therefore the protected observable condition is: no `/vibe/` directory/link delta, no explicit decompile/cache-refresh/analysis call, no persisted Hex-Rays local/comment artifact, no auto-analysis request, and no change to bytes, items, functions, UDTs, xrefs, or any name/type/comment outside I01-I03. Ephemeral process-local cache allocation is outside P11 and receives no claim; any source/schema drift or observed persisted side effect stops unsaved.

### Complete disk/process wrapper and save packages

The supervisor records each worker generation as `(session_id, worker_pid, process StartTimeUtc, executable path, command line, worker endpoint set)`, identity-checks the process before retirement, and retires only that exact worker generation. A reused PID, missing start time/path/command line, listener PID confusion, or ambiguous endpoint ownership stops. Retirement proof requires: the exact PID generation no longer exists in `Get-Process` and `Win32_Process`; `idb_list {}` contains no `is_active:true` row for the canonical path or that worker; stale `is_active:false` rows are non-authoritative; and the following exclusive read succeeds. The supervisor computes each closed-disk tuple while holding a read-only `FileShare.None` handle, then disposes the handle:

> Executable blocks R001-R002 were removed from this report and preserved verbatim in [0003X0-RankingCategoryRecordVectorInsertWithGrowth-source-quality-removed.md](0003X0-RankingCategoryRecordVectorInsertWithGrowth-source-quality-removed.md). The archived blocks are non-authoritative and must not be executed.

`P0` is the complete closed-canonical tuple `(resolved absolute path, length, SHA256, LastWriteTimeUtc ISO-8601, LastWriteTimeUtc ticks)`. `B0` is `(proven-nonexistent timestamped backup absolute path, length, SHA256, LastWriteTimeUtc ISO-8601, ticks)` after one copy; its bytes/length/SHA must equal P0 before transaction open. These remain the frozen authoritative prestate throughout the active transaction. No authoritative closed-canonical tuple can be acquired while that worker holds the IDB. `S1` is the same five-field tuple captured only after transaction-worker retirement, generation-absence/no-active-canonical proof, and successful `FileShare.None`. Never compare only a hash.

The exact save request is:

```text
idb_save {"path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","database":"b002-uid0003x0-transaction-<UTCSTAMP>"}
```

For explicit success, explicit save failure, or timeout/disconnect/missing response, the worker is retired without another save, exact generation absence/no-active-canonical state and FileShare.None are proved, and only then is the first new authoritative closed-disk tuple after transaction open captured and classified before the corresponding unique verifier open shown above. No active-worker observation participates in P0/S1 persistence classification. Every verifier runs full `RB-X0` with its own returned session replacing `<RB-SESSION>`, is retired without save, and is followed by the same generation-absence/FileShare.None proof and an exact repeated tuple. A persisted success requires two identical S1 tuples around a complete poststate verifier. Explicit failure is never retried: exact P0 plus complete prestate is not persisted/no restore/no credit; an exact distinct repeatable transaction-attributable S1 plus complete poststate is failing-saved/no credit and enters only guarded restore; partial/mixed/both/neither/missing/unknown/third identity stops without restore. Timeout/disconnect/missing response follows the same classifier and never retries.

Guarded rollback is allowed only when the exact attributable S1 is closed, every worker generation is absent, no active canonical session exists, FileShare.None succeeds, B0 remains byte-identical to P0, and supervisor evidence proves no later accepted disk work can be overwritten. Copy B0 over the canonical path once, then use a supervisor-owned deterministic operation to restore the original UTC timestamp from the recorded P0 ticks. Before verifier open, exclusive rehash must reproduce all five P0 fields. Then use the literal rollback-verifier open above, run complete `RB-X0` and require exact I01-I03 prestate/P01-P11, retire it without save, prove generation absence and FileShare.None, and require a final all-five-field P0 tuple. Restore is forbidden for unknown attribution or any mismatch.

### Fail-closed supervisor transaction

1. Rehash the eight installed files, reread exact schemas/descriptions, and require the feasibility lock. Run no canonical transaction under drift.
2. Open only the literal disposable diagnostic session. Bind its worker generation, run baseline and any optional analysis-producing diagnostics there, retire it without save, and complete generation-absence/no-active-canonical/FileShare.None proof.
3. While fully closed, capture complete P0, prove the collision-free timestamped backup path nonexistent, copy once, and capture B0 byte-identical to P0.
4. Open the literal transaction session from exact P0 with caches/Hex-Rays disabled. Require its exact worker generation and execute full RB-X0 as S0. No analysis-producing call is allowed from this point through final verifier/rollback closure.
5. Require collision absence. Execute the preserved pure dry-run, RB-X0; pure actual rename, RB-X0; set_type, then two consecutive complete RB-X0 reads proving the deterministic 19-row postframe; set_function_comments, RB-X0. Any unlisted delta stops before save.
6. Run one complete pre-save in-memory RB-X0 and require every I/P poststate. Do not attempt `FileShare.None`, do not call any active-worker filesystem reading an authoritative closed-disk tuple, and do not rebind or replace frozen P0 while the transaction worker is active. If useful, one ordinary shared/nonexclusive path/length/mtime/hash observation may be recorded only as a labeled non-authoritative warning signal; it cannot prove no write, classify persistence, alter P0, authorize credit, or authorize restore. Independently rehash the separate B0 file and require its length/SHA still equal frozen P0, then issue the one literal `idb_save`. Never retry.
7. Apply the exact success, explicit-failure, or indeterminate classifier above. First retire the exact transaction-worker generation without another save; prove generation absence, no active canonical session, and FileShare.None; only then capture the first new authoritative closed-disk tuple after transaction open and classify it against frozen P0 or transaction-attributable S1. Every opened verifier uses its unique literal wrapper, complete RB-X0, exact generation retirement, FileShare.None, and repeated five-field disk tuple.
8. Grant IDA action credit only for explicit/recovered persisted S1 after complete verifier poststate and repeated S1. A save failure that nevertheless persisted receives no credit and enters guarded rollback; exact P0 receives no credit/no restore.
9. Use guarded rollback only under its exact attribution/absence/exclusivity/backup conditions, restore bytes and P0 UTC ticks deterministically, and require complete rollback-verifier prestate plus final exact P0 tuple.
10. Preserve the audit packet: source/schema hashes, every request/response, worker generations, process-retirement proof, exclusive probes, P0/B0/S1 tuples, save classification, verifier results, and rollback/no-rollback disposition.

Supervisor mutation count: three actions, I01-I03. Dry-runs, reads, backup, save, verification, and rollback safeguards are not mutations.
<!-- END CLEANUP-20260813-0003X0-SECTION21 -->

## Removed Block R002

- Original source line: `363`
- Original representation: inline PowerShell/.NET invocation
- Source report SHA256 before this cleanup: `8138DD8CB876AA68D88E77DB9C998832F93A1DE03365659C0B4DD9F5662D09E8`
- Block SHA256: `F93269504DBDD1B8C650C758FE842168868222A27A7FF91282CEB4904930BC50`

```powershell
[System.IO.File]::SetLastWriteTimeUtc($p,[DateTime]::new(<P0-UTC-TICKS>,[DateTimeKind]::Utc))
```
