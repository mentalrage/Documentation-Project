<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0004HS-DLPaletteSetPackedColor-empty-emitter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0004HS-DLPaletteSetPackedColor-empty-emitter-source-quality.md](0004HS-DLPaletteSetPackedColor-empty-emitter-source-quality.md)
- Source report SHA256 before cleanup: `54DFB5C1CE208CF214E0F9EB972EA40FA6BA4390DC60417EFD92D07DB773B035`
- Cleanup generated: `2026-08-11T12:47:03Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `358-368`
- Original language: `powershell`
- Block SHA256: `626F180D31197BC3339C1A5AF3054D8CE1C09269BFBB40A808BDC231C56DF5FD`

```powershell
$canonical = 'E:\NTK\Resources\NexusTK\NexusTK.exe.i64'
$stamp = Get-Date -Format 'yyyyMMdd-HHmmss'
$backup = "$canonical.bak-UID0004HS-prestate-$stamp"
Copy-Item -LiteralPath $canonical -Destination $backup -ErrorAction Stop
$canonicalItem = Get-Item -LiteralPath $canonical
$backupItem = Get-Item -LiteralPath $backup
$canonicalHash = (Get-FileHash -LiteralPath $canonical -Algorithm SHA256).Hash
$backupHash = (Get-FileHash -LiteralPath $backup -Algorithm SHA256).Hash
if (($canonicalItem.Length -ne $backupItem.Length) -or ($canonicalHash -cne $backupHash)) { throw 'UID0004HS prestate backup mismatch; abort before IDA mutation.' }
```

## Removed Block CLEANUP-20260813-0004HS-SECTION21

Source report: [0004HS-DLPaletteSetPackedColor-empty-emitter-source-quality.md](0004HS-DLPaletteSetPackedColor-empty-emitter-source-quality.md)

This block is non-authoritative and must never be executed. It receives no Gate, coverage, score, IDA, validator, or lifecycle credit. The following material is preserved verbatim from source artifact SHA256 `38967DBF405AD0F117BADF029972E3E4C69D9EF534F4A42974181A298CD1210E`.

<!-- BEGIN CLEANUP-20260813-0004HS-SECTION21 -->
## IDA Rename / Type / Comment Recommendations

All rows and calls below were supervisor-owned. B002 performed no mutation, backup, process control, save, or reopen. Dated primary-supervisor evidence records the accepted fail-closed Gate 2B transaction and persistence proof; the literal package remains below as the exact historical transaction specification and protection contract. No dated session or PID is permanent authority.

The Gate-1-repair read-only snapshot at `2026-08-04T13:32:20.3867899-04:00` used session `b008-uid0003fs-rollback`, PID `24500`. It was the sole active session, `status:ok`, Hex-Rays ready, not analyzing, and bound to `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. Its 143,196,412-byte disk identity, last write `2026-08-04T03:55:56.0489608-04:00`, SHA256 `74720635DA2BED8F69DFFDBE8E7ED345C6F6ECB44F38FF03A8E8FACC9539FC46`, is dated pre-Gate2B evidence only.

Dated Gate 2B outcome evidence: mutation session `b007-uid0002k6-nosave-rollback-verify`, PID20504, used canonical prestate SHA256 `85582A483733EC1F54725DBC305E16219A4C6E86B0D948563AF87E59C035AF5D`, 143,196,420 bytes, and the exact same-hash/size backup `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.bak-UID0004HS-prestate-20260804-144925`. Only I001's rename, exact function type, and exact repeatable comment were applied. The complete frame became saved `+0x0`, return `+0x4`, `colorIndex +0x8 unsigned int`, and `packedColor +0xc unsigned __int16`; every I002-I005 protection passed. One save produced canonical SHA256 `CE0222E87E1A569A73EB43DD72BF53412B103DD9281A535EEC2BCC01DE0932FA`, 143,196,420 bytes, last write `2026-08-04T14:52:17-04:00`. PID20504 stopped while listener PID24636 remained up, and different fresh session `b002-uid0004hs-persist-reopen`, PID20412, passed complete persistence readback. No rollback occurred.

| ID | Address/entity | Complete literal prestate | Only permitted action/delta | Complete required readback | Classification |
| --- | --- | --- | --- | --- | --- |
| I001 | function `[0x00542b50,0x00542b63)` | Name `sub_542B50`; type `int __thiscall(_WORD *this, int, __int16)`; address regular `""`; address repeatable `""`; function regular `""`; function repeatable `""`; physical frame is exactly `__saved_registers +0x0 size 0x4 _DWORD`, `__return_address +0x4 size 0x4 _UNKNOWN *`, `arg_0 +0x8 size 0x4 _DWORD`, `arg_4 +0xc size 0x2 _WORD`; no physical locals and no other frame rows; Hex-Rays parameters `_WORD *this`, `int a2`, `__int16 a3`, plus register local `int result` in EAX | Rename to `DLPalette_SetPackedColor`; set exact type `void __thiscall DLPalette_SetPackedColor(DLPalette *this, unsigned int colorIndex, unsigned __int16 packedColor)`; set function repeatable comment exactly `Stores packedColor directly in m_mappedColors[colorIndex] without a bounds check; all four observed callers ignore the incidental EAX value.` No address or function-regular comment write is permitted. | Exact name/type/function-repeatable comment; address regular/repeatable and function regular remain blank; complete frame is exactly the four-row poststate below; only `arg_0 -> colorIndex` plus `_DWORD -> unsigned int` and `arg_4 -> packedColor` plus `_WORD -> unsigned __int16` are permitted; no frame row is added/removed; decompile has `DLPalette *this`, named typed arguments, one mapped-color assignment, no explicit return, and may remove only the nonphysical EAX `result` local | apply, fail closed |
| I002 | target items/range/comments/bytes/xrefs | Function lookup is `sub_542B50`, start `0x542b50`, size `0x13`; first item `[0x542b50,0x542b51)` is one-byte code; terminal item containing `0x542b62` is `[0x542b60,0x542b63)` three-byte code and retains `retn 8`; predecessor `[0x542b4a,0x542b50)` is one six-byte data item of `CC`; successor `[0x542b63,0x542b70)` is one thirteen-byte data item of `CC`; `0x542b70` remains a one-byte code head outside any modeled target function; body SHA256 `233A68EDDB00577A6FE612B4571EF9BBE6EA7D22079D7A9A19034294B27317E6`; predecessor SHA256 `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722`; successor SHA256 `0D0BB866505BC0E2D4276FCDEE1AFDC8887662D04CCE9E4BBB4C10FBA6D0F1CE`; exactly four code xrefs `0x46820c,0x46821f,0x4837e5,0x4837f3`, zero data xrefs; all four entry/function comment channels blank | No item, byte, range, fence, xref, ABI, or companion-comment mutation. Only I001's identity/type/function-repeatable/frame-display/decompiler deltas are allowed. | Every literal item/range/hash/xref/ABI fact remains exact before save and after reopen; blank address regular/repeatable and function regular remain blank; function repeatable alone equals I001; complete frame protections below pass | protection |
| I003 | `DLPalette` UDT | Exact size `556` / `0x22c`, five members only: `vftable +0x0 size 4 void *`; `m_entryMoves +0x4 size 4 unsigned __int8 *`; `m_entryMoveCount +0x8 size 4 int`; `m_paletteHeader +0xc size 32 unsigned __int8[32]`; `m_mappedColors +0x2c size 512 unsigned __int16[256]` | No declaration, resize, rename, retype, member addition/removal, or relationship edit. | Exact size/member count and every member name/type/offset/width remain unchanged. | protection |
| I004 | sibling `[0x00542ac0,0x00542adc)` | Name `DLPalette_MapColor`; type `unsigned __int16 __thiscall(DLPalette *this, unsigned int colorIndex)`; size `0x1c`; body SHA256 `E7966C3483B35336ED88FE59443F52C37204BBD18AC118DDDAE39F96B5E38360`; address regular/repeatable blank; function regular exactly `Maps a palette color index to the current 16-bit packed color; indices above 255 map to zero.`; function repeatable blank; frame exactly `__saved_registers +0x0 size 4 _DWORD`, `__return_address +0x4 size 4 _UNKNOWN *`, `colorIndex +0x8 size 4 unsigned int`; 23 code xrefs exactly `0x467fa2,0x467fb5,0x483754,0x483764,0x4ba5ce,0x4bb920,0x4bba14,0x4bd514,0x4bd539,0x4be1ed,0x4be200,0x4be72e,0x4be741,0x4c07c0,0x4c08b4,0x4c3284,0x4c32a9,0x4c3fad,0x4c3fc0,0x4c442a,0x4c443b,0x54b3f2,0x54b405` | No mutation of any kind. | Exact identity/type/range/hash/comment channels/frame/xrefs remain unchanged before save and after reopen. | protection |
| I005 | sibling `[0x00542ae0,0x00542b4a)` | Name `sub_542AE0`; type `char __thiscall(_WORD *this, unsigned int, unsigned __int8, unsigned __int8, unsigned __int8)`; size `0x6a`; body SHA256 `C03185DB17DE8C375A8B9BCA8FE56102AD6697B4914C363E05A1649288E395C0`; all four entry/function comment channels blank; exact regular instruction comments `low` at `0x542b0e`, `middle` at `0x542b21`, `high` at `0x542b34`; frame exactly `__saved_registers +0x8 size 4 _DWORD`, `__return_address +0xc size 4 _UNKNOWN *`, `arg_0 +0x10 size 4 _DWORD`, `arg_4 +0x14 size 1 _BYTE`, `arg_8 +0x18 size 1 _BYTE`, `arg_C +0x1c size 1 _BYTE`; four code xrefs exactly `0x467ff1,0x468015,0x483785,0x4837a0` | No mutation of any kind. | Exact identity/type/range/hash/comment channels/instruction comments/frame/xrefs remain unchanged before save and after reopen. | protection |

### Deterministic Physical Stack-Frame Contract

The complete target physical prestate and poststate are finite. No row may be omitted from Gate 2B readback.

| Row | Exact prestate | Exact poststate | Disposition |
| --- | --- | --- | --- |
| saved registers | `__saved_registers`, offset `+0x0`, size `0x4`, type `_DWORD` | identical | separately protected; no rename, retype, resize, move, addition, or removal |
| return address | `__return_address`, offset `+0x4`, size `0x4`, type `_UNKNOWN *` | identical | separately protected; no rename, retype, resize, move, addition, or removal |
| first explicit argument | `arg_0`, offset `+0x8`, size `0x4`, type `_DWORD` | `colorIndex`, offset `+0x8`, size `0x4`, type `unsigned int` | permitted delta: name and canonical IDA type only |
| second explicit argument | `arg_4`, offset `+0xc`, size `0x2`, type `_WORD` | `packedColor`, offset `+0xc`, size `0x2`, type `unsigned __int16` | permitted delta: name and canonical IDA type only |

There are no physical local rows before the action and none may appear afterward. The implicit `this` argument remains in ECX and must not become a physical stack row. No frame row addition, removal, merge, split, offset change, width change, saved-register change, return-address change, or physical local creation is permitted. Hex-Rays may change `_WORD *this -> DLPalette *this`, `int a2 -> unsigned int colorIndex`, and `__int16 a3 -> unsigned __int16 packedColor`, and may remove only the nonphysical register local `int result` because the source return becomes `void`. Any other local/argument presentation delta fails the transaction.

### Literal Gate 2B Transaction Package

The following package is preserved as the exact historical Gate 2B plan that governed the dated transaction. Runtime symbols were deliberately narrow: `<gate2b-database>` was the selected healthy session for the canonical disk identity; `<gate2b-worker-pid>` was that session's recorded worker PID; `<backup-path>` was the exact timestamped path; `<persist-database>` was the different fresh-reopen session returned after save. No other call field was discretionary, and every batched read contained ten or fewer queried addresses/entities/regions.

1. **Dynamic authority bind and timestamped backup.** Call `idb_list {}`; require one selected healthy session bound to `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; call `server_health` for it; reread canonical path, byte size, last-write timestamp, and SHA256 from disk; record all values. Before any mutation, the primary supervisor runs this exact PowerShell shape and records the expanded `<backup-path>`, its creation timestamp, size, and SHA256. Abort before mutation unless source and backup size/hash match exactly.

> Executable block R001 was removed from this report and preserved verbatim in [0004HS-DLPaletteSetPackedColor-empty-emitter-source-quality-removed.md](0004HS-DLPaletteSetPackedColor-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

2. **Complete bounded preflight and collision check.** Run these exact read-only call shapes against `<gate2b-database>` and compare every result with I001-I005 and the complete frame contract. The exact proposed-name query must return not found/zero hits. Any mismatch aborts before mutation.

```text
lookup_funcs {"database":"<gate2b-database>","queries":["0x00542b50","0x00542ac0","0x00542ae0","DLPalette_SetPackedColor"]}
entity_query {"database":"<gate2b-database>","queries":{"kind":"names","regex":"^DLPalette_SetPackedColor$","offset":0,"count":10,"sort_by":"addr","descending":false,"fields":["addr","name"]}}
stack_frame {"database":"<gate2b-database>","addrs":["0x00542b50","0x00542ac0","0x00542ae0"]}
get_comments {"database":"<gate2b-database>","addrs":["0x00542b50","0x00542ac0","0x00542ae0","0x00542b0e","0x00542b21","0x00542b34"]}
inspect_items {"database":"<gate2b-database>","addrs":["0x00542b4a","0x00542b50","0x00542b62","0x00542b63","0x00542b6f","0x00542b70"]}
xrefs_to {"database":"<gate2b-database>","addrs":["0x00542b50","0x00542ac0","0x00542ae0"],"limit":100}
get_bytes {"database":"<gate2b-database>","regions":[{"addr":"0x00542b4a","size":6},{"addr":"0x00542b50","size":19},{"addr":"0x00542b63","size":13},{"addr":"0x00542ac0","size":28},{"addr":"0x00542ae0","size":106}]}
type_inspect {"database":"<gate2b-database>","queries":{"name":"DLPalette","include_members":true,"max_members":10}}
decompile {"database":"<gate2b-database>","addr":"0x00542b50","include_addresses":true}
```

3. **Collision-safe dry run.** The supervisor must run the exact rename batch with `dry_run:true`. It must report success for one function rename, no overwrite, and no other planned rename. A dry-run error aborts before mutation.

```text
rename {"database":"<gate2b-database>","batch":{"func":[{"addr":"0x00542b50","name":"DLPalette_SetPackedColor"}],"stop_on_error":true,"dry_run":true,"allow_overwrite":false}}
```

4. **Exact mutation calls with immediate readback.** Apply only these three calls, in order. After the rename, rerun `lookup_funcs`, `stack_frame`, and `get_comments` for the target and require that only the name changed. After `set_type`, immediately rerun `lookup_funcs`, `stack_frame`, `decompile`, `inspect_items`, `get_bytes`, and `xrefs_to` for the target and require the complete poststate and only the enumerated frame/decompiler deltas. After the repeatable-comment write, rerun `get_comments` for all six comment addresses and require only target `function_repeatable` changed.

```text
rename {"database":"<gate2b-database>","batch":{"func":[{"addr":"0x00542b50","name":"DLPalette_SetPackedColor"}],"stop_on_error":true,"dry_run":false,"allow_overwrite":false}}
set_type {"database":"<gate2b-database>","edits":[{"addr":"0x00542b50","kind":"function","signature":"void __thiscall DLPalette_SetPackedColor(DLPalette *this, unsigned int colorIndex, unsigned __int16 packedColor)"}]}
set_repeatable_comments {"database":"<gate2b-database>","items":[{"addr":"0x00542b50","comment":"Stores packedColor directly in m_mappedColors[colorIndex] without a bounds check; all four observed callers ignore the incidental EAX value."}]}
```

5. **Unsaved final protection pass.** Before `idb_save`, rerun every bounded call in step 2, now querying both old and new names in `lookup_funcs`/`entity_query`. Require one unique new-name hit at `0x542b50`, no old-name function hit, exact I001 poststate, every I002-I005 protection, and exact complete frame poststate. If any check fails, do not save and use the no-save rollback below.

6. **Save and fresh-reopen persistence proof.** Only after all unsaved checks pass, call `idb_save {"database":"<gate2b-database>","path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64"}` once. Record returned status plus new canonical size, SHA256, and last-write time. The primary supervisor then stops only `<gate2b-worker-pid>` through its controlled worker-teardown path, confirms that PID/session is gone while the MCP server remains listening, and calls the following exact reopen shape. The returned `<persist-database>` and PID must differ from the mutation session. No save follows persistence verification.

```text
idb_open {"input_path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","mode":"prefer_headless","run_auto_analysis":false,"build_caches":true,"init_hexrays":true,"idle_ttl_sec":3600,"preferred_session_id":"b002-uid0004hs-persist-reopen"}
```

Against `<persist-database>`, rerun `server_health` and every bounded call in step 2 with the poststate name query, then require the complete I001 poststate, exact four-row frame, every I002-I005 protection, and the just-recorded saved disk identity. Session/PID identity is persistence evidence only and must not be treated as permanent later authority.

7. **Exact no-save rollback.** On any mismatch after the first mutation but before `idb_save`, record the failed call/readback, never call `idb_save`, stop only `<gate2b-worker-pid>`, verify canonical disk path/size/SHA256 still equal the captured prestate, and reopen with preferred session `b002-uid0004hs-nosave-rollback-verify` using the same `idb_open` arguments as step 6. Rerun all step-2 calls and require the complete original I001-I005 prestate, including `sub_542B50`, original type, four original frame rows, blank target comments, hashes, xrefs, UDT, and siblings. Do not save the rollback verifier.

> Executable block R002 was removed from this report and preserved verbatim in [0004HS-DLPaletteSetPackedColor-empty-emitter-source-quality-removed.md](0004HS-DLPaletteSetPackedColor-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Then call `idb_open` with `preferred_session_id:"b002-uid0004hs-nosave-rollback-verify"`; no other reopen field differs from step 6.

8. **Exact saved rollback.** If `idb_save` succeeds but the fresh persistence readback fails, record the failed invariant; stop the persistence worker; confirm no active session remains bound to the canonical path; copy `<backup-path>` over the canonical IDB; require restored size/SHA256 exactly equal the recorded prestate/backup; reopen with preferred session `b002-uid0004hs-saved-rollback-verify`; and rerun every step-2 prestate call. The complete original I001-I005 prestate must return. Do not save the rollback verifier. A rollback failure halts the larger supervisor goal for investigation.

> Executable block R003 was removed from this report and preserved verbatim in [0004HS-DLPaletteSetPackedColor-empty-emitter-source-quality-removed.md](0004HS-DLPaletteSetPackedColor-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Then call `idb_open` with `preferred_session_id:"b002-uid0004hs-saved-rollback-verify"`; no other reopen field differs from step 6. Before either rollback copy or reopen, a fresh `idb_list` must prove that no live session remains bound to the canonical path. These process-control and restore commands are primary-supervisor-only; B002 did not run them.

Required type dependency: the existing exact `DLPalette` UDT only. Do not declare a competing UDT or duplicate member names. Negative constraints: do not create a function at `0x00542b63` or `0x00542b70`, do not convert fence bytes to code, do not rename/type/comment siblings or callers, do not add a bounds-check comment that implies runtime validation, do not accept a partial frame normalization, and do not save after any unsaved mismatch.
<!-- END CLEANUP-20260813-0004HS-SECTION21 -->

## Removed Block R002

- Original source lines: `410-418`
- Original language: `powershell`
- Block SHA256: `8A8027A6021ABD6240CA6D0270A4183F3DB3E0C1CC3FE80C10EBB8AC6031CDC1`

```powershell
$workerPid = [int]'<gate2b-worker-pid>'
Stop-Process -Id $workerPid -Force -ErrorAction Stop
for ($i = 0; $i -lt 50 -and (Get-Process -Id $workerPid -ErrorAction SilentlyContinue); $i++) { Start-Sleep -Milliseconds 100 }
if (Get-Process -Id $workerPid -ErrorAction SilentlyContinue) { throw 'UID0004HS mutated worker did not stop; halt without save.' }
$currentItem = Get-Item -LiteralPath $canonical
$currentHash = (Get-FileHash -LiteralPath $canonical -Algorithm SHA256).Hash
if (($currentItem.Length -ne $canonicalItem.Length) -or ($currentHash -cne $canonicalHash)) { throw 'UID0004HS no-save rollback disk identity drifted; halt.' }
```

## Removed Block R003

- Original source lines: `424-433`
- Original language: `powershell`
- Block SHA256: `6EC5A4E8C312A34B762DC9DB5906A7EC63D4DF277EF2ABFC5547470CF5BDD38C`

```powershell
$persistWorkerPid = [int]'<persist-worker-pid>'
Stop-Process -Id $persistWorkerPid -Force -ErrorAction Stop
for ($i = 0; $i -lt 50 -and (Get-Process -Id $persistWorkerPid -ErrorAction SilentlyContinue); $i++) { Start-Sleep -Milliseconds 100 }
if (Get-Process -Id $persistWorkerPid -ErrorAction SilentlyContinue) { throw 'UID0004HS persistence worker did not stop; halt before disk restore.' }
Copy-Item -LiteralPath '<backup-path>' -Destination $canonical -Force -ErrorAction Stop
$restoredItem = Get-Item -LiteralPath $canonical
$restoredHash = (Get-FileHash -LiteralPath $canonical -Algorithm SHA256).Hash
if (($restoredItem.Length -ne $backupItem.Length) -or ($restoredHash -cne $backupHash) -or ($restoredHash -cne $canonicalHash)) { throw 'UID0004HS saved rollback restore identity mismatch; halt.' }
```

## BEGIN CLEANUP-20260813-0004HS-OUTSIDE21-RUNBOOK

- Source: [0004HS-DLPaletteSetPackedColor-empty-emitter-source-quality.md](0004HS-DLPaletteSetPackedColor-empty-emitter-source-quality.md)
- Status: **non-authoritative removed material**.
- Safety: **must never be executed**.
- Reason: historical orchestration and transaction sequencing outside Section 21 was replaced by declarative outcome and protection evidence.

### Removed source lines

```text
- Preserve the dated fail-closed Gate 2B evidence for `0x00542b50`: exact prestate/backup binding, collision and dry-run checks, only the literal rename/type/repeatable-comment mutations, complete physical-frame and bounded I002-I005 protections, one save, and a different fresh-reopen persistence session. No rollback was required.
| C0004HS-040 | 0004HS | Record the dated fail-closed IDA Gate 2B evidence. | exact | Literal supervisor transaction and rollback workflow below. | I001-I005 and dated IDB evidence | Primary supervisor | Record the full I001-I005 evidence: dynamic bind, exact backup, bounded preflight, dry-run, exact mutations/protections, one save, controlled reopen, and persistence readback. | Dated evidence records prestate/backup SHA85582A48...AF5D, mutation PID20504, saved SHACE0222E8...32FA, persistence session b002-uid0004hs-persist-reopen/PID20412, all protections passed, no rollback. | applied |
- [x] C0004HS-040 | Actor: Primary supervisor | Destination: I001-I005 and dated IDB evidence | Action: Record the full I001-I005 evidence: dynamic bind, exact backup, bounded preflight, dry-run, exact mutations/protections, one save, controlled reopen, and persistence readback. | Expected readback: Dated evidence records prestate/backup SHA85582A48...AF5D, mutation PID20504, saved SHACE0222E8...32FA, persistence session b002-uid0004hs-persist-reopen/PID20412, all protections passed, no rollback. | State: applied
```

## END CLEANUP-20260813-0004HS-OUTSIDE21-RUNBOOK
