<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\0001NY-WaitableTimerRawStartStop-empty-emitter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

## Removed Block CLEANUP-20260813-0001NY-SECTION21

Source: [0001NY-WaitableTimerRawStartStop-empty-emitter-source-quality.md](0001NY-WaitableTimerRawStartStop-empty-emitter-source-quality.md)

This archive is non-authoritative and must never be executed. It preserves the exact report text removed during supervisor cleanup.

<!-- BEGIN CLEANUP-20260813-0001NY-SECTION21 -->
## IDA Rename / Type / Comment Recommendations

All actions below are supervisor-only Gate 2B work. B005 performed read-only queries only.

### Exact action/prestate table

| ID | Address/entity | Literal current prestate at evidence snapshot | Proposed action | Expected semantic readback |
| --- | --- | --- | --- | --- |
| T1 | named type `WaitableTimer` | absent, or already present with the exact source declaration and deterministic physical layout below | if absent, declare the exact 0x2c source UDT using `unsigned char _padding21[3]`; if already exact after IDA normalization, preserve without mutation; if different, stop unsaved | seven members at +00/+04/+08/+20/+21/+24/+28 with 0x2c total; source spelling remains `unsigned char _padding21[3]`, while exact physical readback requires `_padding21 | 0x21 | 3 | unsigned __int8[3]`; branch choice and no-op/declare result recorded |
| F1 | `0x005c1120-0x005c116a` | no function; no physical frame; entry code item unnamed; comments regular/repeatable blank | no mutation; preserve raw no-function/no-frame state | `lookup_funcs.fn:null`; `stack_frame.vars:null`, exact no-function error; all bytes/items/comments unchanged |
| F2 | `0x005c1170-0x005c11b5` | no function; no physical frame; entry code item unnamed; comments regular/repeatable blank | no mutation; preserve raw no-function/no-frame state | `lookup_funcs.fn:null`; `stack_frame.vars:null`, exact no-function error; all bytes/items/comments unchanged |
| F3 | `0x005c11c0-0x005c120e` | `sub_5C11C0`; `void __stdcall(int,int,int,int,int)`; four comment channels blank; exact three-row frame; exact 78-byte body SHA256 `8670FFC552C57F7AF2BED4D593F6BCD2BF8F5E6678AEA9713EEF9403AFAAE083` | rename and apply `F3-COMMENT`; do not set type or edit frame | `WaitableTimerCallback`; generic prototype, exact same three physical rows, exact body hash, and decompiled behavior invariant unchanged; only `F3-COMMENT` populated in function-regular channel |
| D1 | logical storage head `0x0069be3c`, protected byte span `[0x0069be3c,0x0069be40)`; physical `inspect_items` prestate `[0x0069be3c,0x0069be3d)`, size `1`, `is_code:false`, `is_data:false`; bytes `00 00 00 00`; `unk_69BE3C`; `int (__stdcall *)(_DWORD,_DWORD,_DWORD,_DWORD)`; regular/repeatable blank; 12 exact data xrefs | data rename, unchanged auto-detected `type_apply_batch` type edit with no `kind`, apply `D1-REPEATABLE-COMMENT` | physical item deterministically becomes head/range `[0x0069be3c,0x0069be40)`, size `4`, `is_code:false`, `is_data:true`; `g_pfnCreateEventW`; exact CreateEventW pointer type; exact bytes/hash and 12 xrefs unchanged; regular blank; only `D1-REPEATABLE-COMMENT` populated |

Exact action-row comment keys:

- `F3-COMMENT`: `WinMM timer callback for WaitableTimer; userData is the object pointer. It clears running, waits on and closes the callback gate, clears transient timer state, signals completion, and leaves the critical section.`
- `D1-REPEATABLE-COMMENT`: `Runtime-resolved CreateEventW dispatch slot used by WaitableTimer and other wide-API consumers.`

### Literal D1 prestate and authorized poststate

- Logical mutation/storage entity: head `0x0069be3c`, protected pointer-storage byte span `[0x0069be3c,0x0069be40)`, width `4`. Exact current physical `inspect_items` prestate is the unknown/non-code/non-data item `[0x0069be3c,0x0069be3d)`, size `1`, `is_code:false`, `is_data:false`. That one-byte item is the mandatory pre-action readback; only the authorized unchanged `type_apply_batch` operation may replace/materialize it.
- Current four protected bytes: `00 00 00 00`; SHA256 over exact `[0x0069be3c,0x0069be40)` is `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`.
- Current name/type: `unk_69BE3C`; `int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD)`.
- Current comment channels: regular `""`; repeatable `""`.
- Exact current inbound-xref inventory, all type `data`, count `12`: `0x0041a30c`, `0x00464498`, `0x00525e89`, `0x00525f4b`, `0x005764b9`, `0x0057772c`, `0x00596652`, `0x00596a31`, `0x00599645`, `0x0059987c`, `0x005c1026`, `0x005c1134`.
- Sole authorized physical poststate: `inspect_items` must expose one data item whose head and range are exactly `[0x0069be3c,0x0069be40)`, size `4`, `is_code:false`, `is_data:true`. Name must be `g_pfnCreateEventW`; type must be `HANDLE (__stdcall *)(LPSECURITY_ATTRIBUTES, BOOL, BOOL, LPCWSTR)`; regular comment must remain blank; repeatable comment must equal `D1-REPEATABLE-COMMENT`. The four protected bytes remain `00 00 00 00` with SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`, and the exact ordered 12-xref inventory/count remains unchanged. The one-byte unknown/non-data prestate is expected to be replaced by this exact four-byte data item. Any other item head/range/size/kind/flag, any additional item, or any byte/hash/xref/name/type/comment-channel delta outside this exact authorization is a stop/no-save condition.

### Literal F3 byte and decompile contract

- Exact F3 physical range is `[0x005c11c0,0x005c120e)`, length `78`, with SHA256 `8670FFC552C57F7AF2BED4D593F6BCD2BF8F5E6678AEA9713EEF9403AFAAE083` over the executable bytes `55 8b ec 56 8b 75 10 57 8d 7e 08 c6 46 20 00 57 ff 15 84 d1 60 00 6a ff ff 76 28 ff 15 bc d1 60 00 ff 76 28 ff 15 10 d1 60 00 ff 76 04 c7 46 28 00 00 00 00 c7 46 24 00 00 00 00 ff 15 48 d1 60 00 57 ff 15 88 d1 60 00 5f 5e 5d c2 14 00`.
- The bounded F3 `decompile` result must return non-null code with no error and preserve this exact behavior invariant: the third callback argument is the object pointer; the body clears byte `+0x20`, enters the critical section at `+0x08`, waits indefinitely on handle `+0x28`, closes that handle, clears `+0x28` and timer id `+0x24`, signals completion event `+0x04`, leaves the same critical section, and returns with five stdcall arguments popped. Function/name rendering may reflect the authorized rename, but any operation, offset, constant, call order, calling convention, or object-argument change is a stop/no-save condition.
- The exact byte identity and decompile invariant are mandatory at initial preflight, immediately after the applicable F3 rename/comment action before save, and after fresh reopen. They are also mandatory rollback proof; neither a successful outer MCP envelope nor an unchanged function profile substitutes for these two readbacks.

Exact T1 declaration:

```c
struct WaitableTimer
{
    void **vftable;
    HANDLE m_completionEvent;
    CRITICAL_SECTION m_criticalSection;
    bool m_isRunning;
    unsigned char _padding21[3];
    UINT m_timerId;
    HANDLE m_callbackGateEvent;
};
```

Required source invariants: 32-bit pointers/HANDLE/UINT, `CRITICAL_SECTION` size `0x18`, fields at `+0x00`, `+0x04`, `+0x08`, `+0x20`, source padding declaration `unsigned char _padding21[3]` at `+0x21`, and fields at `+0x24`, `+0x28`, total `0x2c`.

### Exact T1 source-to-IDA normalization contract

- The source declaration above is authoritative source syntax and must remain `unsigned char _padding21[3]`; it must not be rewritten to an IDA typedef spelling merely to imitate the database display.
- `type_inspect` must report total size `44` (`0x2c`) and exactly seven members with offsets and widths `vftable|0x00|4`, `m_completionEvent|0x04|4`, `m_criticalSection|0x08|24`, `m_isRunning|0x20|1`, `_padding21|0x21|3`, `m_timerId|0x24|4`, and `m_callbackGateEvent|0x28|4`, with no extra, missing, reordered, resized, or overlapping member.
- For the padding member only, IDA deterministically normalizes the physical type spelling. The one accepted physical row is exactly `_padding21 | 0x21 | 3 | unsigned __int8[3]`. The spelling `unsigned __int8[3]` is an IDA physical-display normalization, not a source declaration change and not a separate mutation.
- Every non-padding member type must retain the exact declaration/type contract already specified above. Any total-size, member-name, offset, width, non-padding type, or padding physical spelling other than exact `unsigned __int8[3]` is a stop/no-save condition. This is the complete accepted distinction between source syntax and physical IDA readback; it loosens no other T1 invariant.

### F1-F3 narrowing decision and rejected transaction history

- The pre-audit transaction proposed defining and typing F1/F2 and semantically retyping F3. That package was rejected because read-only MCP can prove the raw instruction boundaries but cannot prove the physical rows IDA would synthesize for newly defined F1/F2 or after a semantic F3 type replacement.
- F1 and F2 are therefore explicit no-action entities in IDA. Their human names, signatures, and formal source remain fully documented in UID0002L8/UID0002L9; IDA must preserve their exact raw code-item/no-function/no-frame state.
- F3 remains a modeled function. Rename plus function-regular comment is the complete safe source-quality subset. Its existing generic five-dword prototype is not final source spelling, but preserving it avoids an unprovable frame transformation. The human WinMM signature remains documented as source reconstruction evidence outside the IDB type action.
- This narrowing resolves the open physical-frame question. It is not permission to rediscover or expand F1-F3 actions during Gate 2B; any broader action requires a separately repaired report and fresh exact-artifact Gate 1.

### Dated failed D1 transaction and verified unsaved rollback

- Gate 2B attempt `2026-08-04T17:56:26-04:00` began from canonical SHA256 `2AD137124C2E8512C9FB8178CE1304C192655CD10E1C718653F2D4FC039F7346`, `143196536` bytes, after byte-identical backup `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.bak-UID0001NY-prestate-20260804_175434` was proven equal.
- In unsaved worker PID `8068`, T1 declared successfully, rename dry-run passed `2/2`, F3/D1 actual names changed, and the exact F3 function-regular and D1 repeatable comments were accepted. The literal D1 edit `{"addr":"0x0069be3c","kind":"data","ty":"HANDLE (__stdcall *)(LPSECURITY_ATTRIBUTES, BOOL, BOOL, LPCWSTR)"}` then returned per-edit error `Unknown kind: data` even though the JSON-RPC envelope itself was not an error.
- The supervisor failed closed before `idb_save`, discarded only unsaved worker PID `8068`, and reopened canonical disk as `supervisor-uid0001ny-rollback-reopen`. Fresh readback proved T1 absent; F1/F2 no-function/no-frame; F3 `sub_5C11C0` with generic prototype, exact three rows, and blank comments; D1 `unk_69BE3C` with its original generic type and blank comments; exact raw/vtable bytes unchanged; and canonical disk still SHA256 `2AD137...7346`.
- No action from that failed transaction receives credit. The old `set_type(kind:data)` request is historical negative evidence only and is superseded by the schema-valid command below.

### Dated failed T1-normalization transaction and verified unsaved rollback

- During the `2026-08-05` supervisor-only Gate 2B attempt, canonical disk prestate was `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, SHA256 `77F5EF16C3CD3D78D86B6AA15768830BC11E6B6DC3DB44EB9537D30509538127`, `143196656` bytes. `declare_type` accepted the exact source declaration containing `unsigned char _padding21[3]`.
- Immediate `type_inspect` returned total size `44` and the exact required member offsets and sizes, but normalized the physical padding row to `_padding21 | 0x21 | 3 | unsigned __int8[3]`. The prior contract incorrectly demanded source spelling `unsigned char[3]` in that physical row, so the verifier stopped immediately.
- No F3 or D1 rename, type, or comment action ran, and `idb_save` was never called. Unsaved worker PID `24648` was discarded. Canonical disk remained byte-identical at SHA256 `77F5EF16C3CD3D78D86B6AA15768830BC11E6B6DC3DB44EB9537D30509538127`, `143196656` bytes.
- Fresh rollback session `b005-uid0001ny-rollback-reopen` passed the complete original preflight: T1 was absent and every F1/F2/F3/D1 name, type, comment, byte, xref, and frame prestate was restored. This failed attempt receives no action credit. It is historical negative evidence superseded only by the repaired source-versus-physical T1 normalization contract; it does not weaken the source declaration, any other member contract, or P1-P11.

### Dated failed D1-materialization supervisor attempts and verified unsaved rollback

- Two `2026-08-05` supervisor-only Gate 2B attempts began from canonical prestate SHA256 `23B89BF35334D876FE63C04AE15C4F90AEF4DF41FAF9D79580F25D244A214283`, `143196749` bytes. Both were fail-closed attempts and neither reached `idb_save`.
- The first attempt reached exact actual F3/D1 comments and then stopped on a supervisor verifier variable-shadowing false negative. That verifier defect was external to the report transaction, but the unsaved worker was correctly discarded and no action receives credit.
- The second attempt applied the unchanged schema-valid D1 type request and read back deterministic physical materialization as head/range `[0x0069be3c,0x0069be40)`, size `4`, `is_code:false`, `is_data:true`. Name `g_pfnCreateEventW`, exact accepted CreateEventW pointer type, bytes `00 00 00 00`/SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`, all 12 xrefs, blank regular comment, and exact repeatable comment were correct. The old report contract incorrectly required the one-byte unknown/non-data prestate item to survive the type action, so the verifier stopped before save and the unsaved worker was discarded.
- After the attempts, fresh rollback session `b005-uid0001ny-d1-rollback-reopen` passed the complete original preflight: the physical D1 item returned to `[0x0069be3c,0x0069be3d)`, size `1`, `is_code:false`, `is_data:false`; all T1/F1/F2/F3/D1 names, types, comments, bytes, xrefs, and frames matched prestate; and canonical disk remained exact at SHA256 `23B89BF35334D876FE63C04AE15C4F90AEF4DF41FAF9D79580F25D244A214283`, `143196749` bytes. Neither attempt receives action or persistence credit. The deterministic four-byte data materialization supersedes only the false D1 physical-poststate requirement and does not loosen any other transaction or protection.

### Literal supervisor transaction

Use the current sole session returned by a fresh `idb_list`; never copy an evidence-time session ID:

`idb_list {}`

`server_health {"database":"<active-session-id-from-current-idb_list>"}`

`tools/list {}`

The fresh schema must expose `type_apply_batch.batch.edits`, optional `batch.stop_on_error`, and edit fields `addr`/`ty`, with `kind` documented as auto-detected. Stop before mutation if that schema differs; never restore the rejected literal `kind:"data"` or substitute an unreviewed kind value.

Before mutation, the supervisor must hash the canonical IDB, create a byte-identical backup named `NexusTK.exe.i64.bak-UID0001NY-prestate-<timestamp>`, and prove backup size/SHA equal the canonical prestate. Reread T1/F1/F2/F3/D1 and P1-P11 with the literal requests below. Resolve T1 into exactly one branch: absent; already present with the exact source declaration semantics and exact normalized physical layout; or present but different. The absent branch may declare T1 from the literal source declaration; the already-exact branch must not mutate or redeclare it; the different branch stops unsaved and requires same-report rebase. Exact normalized physical layout includes only the permitted padding display `_padding21 | 0x21 | 3 | unsigned __int8[3]`; it does not permit any other member/type/layout delta. Also stop without mutation if F1/F2 are functions or have frames, if F3 differs from its exact name/type/frame/comment/byte/decompile prestate, if D1 differs, or if any protection differs.

1. Read the complete prestate:

`type_inspect {"queries":{"name":"WaitableTimer","include_members":true,"max_members":16},"database":"<active-session-id-from-current-idb_list>"}`

`lookup_funcs {"queries":["0x005c0ff0","0x005c10a0","0x005c1120","0x005c1170","0x005c11c0","0x005c1210"],"database":"<active-session-id-from-current-idb_list>"}`

`func_profile {"queries":[{"addr":"0x005c0ff0","include_lists":true,"max_items":256,"include_prototype":true},{"addr":"0x005c10a0","include_lists":true,"max_items":256,"include_prototype":true},{"addr":"0x005c11c0","include_lists":true,"max_items":64,"include_prototype":true},{"addr":"0x005c1210","include_lists":true,"max_items":256,"include_prototype":true}],"database":"<active-session-id-from-current-idb_list>"}`

`decompile {"addr":"0x005c11c0","include_addresses":true,"database":"<active-session-id-from-current-idb_list>"}`

`stack_frame {"addrs":["0x005c1120","0x005c1170","0x005c11c0"],"database":"<active-session-id-from-current-idb_list>"}`

`get_comments {"addrs":["0x005c0ff0","0x005c10a0","0x005c1120","0x005c1170","0x005c11c0","0x005c1210","0x0069be3c"],"database":"<active-session-id-from-current-idb_list>"}`

`inspect_items {"addrs":["0x005c0ff0","0x005c10a0","0x005c1120","0x005c1167","0x005c116a","0x005c1170","0x005c11b4","0x005c11b5","0x005c11c0","0x005c1210","0x0069be3c"],"database":"<active-session-id-from-current-idb_list>"}`

`xrefs_to {"addrs":["0x005c1120","0x005c1170","0x005c11c0","0x005c1210","0x00631188","0x0069be3c"],"limit":100,"database":"<active-session-id-from-current-idb_list>"}`

`get_bytes {"regions":[{"addr":"0x005c1111","size":175},{"addr":"0x005c11c0","size":78},{"addr":"0x005c0ff0","size":172},{"addr":"0x005c10a0","size":113},{"addr":"0x005c1210","size":138},{"addr":"0x00631184","size":12},{"addr":"0x0069be3c","size":4}],"database":"<active-session-id-from-current-idb_list>"}`

2. Resolve T1 through the exact prestate branch. If `type_inspect` reports T1 absent, run the following source declaration. If it reports total size `44`, the exact seven names/offsets/widths, exact non-padding types, and the exact normalized padding row `_padding21 | 0x21 | 3 | unsigned __int8[3]`, record `already-present` and do not call `declare_type`. If it reports any other present declaration, padding spelling, or partial/conflicting layout, stop unsaved and require a same-report rebase:

`declare_type {"decls":["struct WaitableTimer { void **vftable; HANDLE m_completionEvent; CRITICAL_SECTION m_criticalSection; bool m_isRunning; unsigned char _padding21[3]; UINT m_timerId; HANDLE m_callbackGateEvent; };"],"database":"<active-session-id-from-current-idb_list>"}`

3. Read T1 immediately in both the just-declared and already-present branches. Stop unsaved unless total size is exactly `44`, all seven member names/offsets/widths and all non-padding types are exact, and the padding physical row is exactly `_padding21 | 0x21 | 3 | unsigned __int8[3]`. The source declaration remains `unsigned char _padding21[3]`; the physical `unsigned __int8[3]` rendering is accepted only as deterministic normalization. The already-present branch must also prove no T1 mutation occurred:

`type_inspect {"queries":{"name":"WaitableTimer","include_members":true,"max_members":16},"database":"<active-session-id-from-current-idb_list>"}`

4. Perform no F1/F2 mutation. Immediately reconfirm both exact no-function/no-frame poststates:

`lookup_funcs {"queries":["0x005c1120","0x005c1170"],"database":"<active-session-id-from-current-idb_list>"}`

`stack_frame {"addrs":["0x005c1120","0x005c1170"],"database":"<active-session-id-from-current-idb_list>"}`

The only accepted F1 result is `fn:null`, error `Not a function`, followed by `vars:null`, error `No function found at address 6033696`. The only accepted F2 result is `fn:null`, error `Not a function`, followed by `vars:null`, error `No function found at address 6033776`. Any function object, physical row, comment, name, item, byte, or fence change is a stop/no-save condition.

5. Rename only F3 and D1, first dry-run and then actual:

`rename {"batch":{"func":{"addr":"0x005c11c0","name":"WaitableTimerCallback"},"data":{"old":"unk_69BE3C","new":"g_pfnCreateEventW"},"stop_on_error":true,"dry_run":true,"allow_overwrite":false},"database":"<active-session-id-from-current-idb_list>"}`

`rename {"batch":{"func":{"addr":"0x005c11c0","name":"WaitableTimerCallback"},"data":{"old":"unk_69BE3C","new":"g_pfnCreateEventW"},"stop_on_error":true,"dry_run":false,"allow_overwrite":false},"database":"<active-session-id-from-current-idb_list>"}`

6. Apply only the D1 data type through the current schema's auto-detected batch path. The edit intentionally omits `kind`; do not call `set_type`, `force_recompile`, `define_func`, stack rename, or stack type actions for F1/F2/F3:

`type_apply_batch {"batch":{"edits":{"addr":"0x0069be3c","ty":"HANDLE (__stdcall *)(LPSECURITY_ATTRIBUTES, BOOL, BOOL, LPCWSTR)"},"stop_on_error":true},"database":"<active-session-id-from-current-idb_list>"}`

Inspect both the JSON-RPC/MCP envelope and every returned aggregate/item result before continuing. `isError:true`, aggregate failure, a false success flag, a nonzero failed-edit count, or any item-level nonempty `error` is a stop/no-save condition even if the outer envelope reports success. After a failure, apply no later action, do not save, discard the unsaved worker, reopen canonical disk fresh, and prove all T1/F1/F2/F3/D1/P1-P11 prestates and the canonical SHA/size are restored. A successful return receives no credit until `inspect_items` proves exact replacement of the one-byte unknown/non-data prestate by the sole authorized four-byte data item `[0x0069be3c,0x0069be40)`, size `4`, `is_code:false`, `is_data:true`, and comments, bytes/hash, xrefs, and fresh persistence independently prove every other exact D1 postcondition.

7. Apply the exact F3 function-regular comment:

`set_function_comments {"items":{"addr":"0x005c11c0","comment":"WinMM timer callback for WaitableTimer; userData is the object pointer. It clears running, waits on and closes the callback gate, clears transient timer state, signals completion, and leaves the critical section."},"database":"<active-session-id-from-current-idb_list>"}`

8. Apply the exact D1 repeatable data comment:

`set_repeatable_comments {"items":{"addr":"0x0069be3c","comment":"Runtime-resolved CreateEventW dispatch slot used by WaitableTimer and other wide-API consumers."},"database":"<active-session-id-from-current-idb_list>"}`

9. Repeat every applicable prestate/protection request and compare against the authorized poststates. F1/F2 must remain exact no-function/no-frame entities. F3 must read back name `WaitableTimerCallback`, size `0x4e`, prototype `void __stdcall(int, int, int, int, int)`, 24 instructions, one block, the exact three-row frame below, only the exact function-regular comment, blank entry-regular/entry-repeatable/function-repeatable channels, exact 78-byte hash, and the exact decompile behavior invariant. D1 must read back one physical item exactly `[0x0069be3c,0x0069be40)`, size `4`, `is_code:false`, `is_data:true`; name `g_pfnCreateEventW`; exact type `HANDLE (__stdcall *)(LPSECURITY_ATTRIBUTES, BOOL, BOOL, LPCWSTR)`; blank regular comment; exact repeatable comment; unchanged four bytes/hash; and the exact ordered 12-xref inventory. Repeat the full P1-P11 byte/item/xref/type/comment set before save, including this literal immediate F3 request:

`decompile {"addr":"0x005c11c0","include_addresses":true,"database":"<active-session-id-from-current-idb_list>"}`

Expected physical-frame contract:

- F1 has no physical frame. Its complete accepted poststate is `lookup_funcs.fn:null` plus `stack_frame.vars:null` and exact error `No function found at address 6033696`.
- F2 has no physical frame. Its complete accepted poststate is `lookup_funcs.fn:null` plus `stack_frame.vars:null` and exact error `No function found at address 6033776`.
- F3 has exactly three rows and no others: `__saved_registers`, offset `+0x08`, width `4`, type `_DWORD`; `__return_address`, offset `+0x0c`, width `4`, type `_UNKNOWN *`; `arg_8`, offset `+0x18`, width `4`, type `_DWORD`.
- No direct frame edit is permitted. Any F1/F2 function/frame materialization or any F3 row/name/offset/width/type delta is a stop/no-save condition.

### P1-P11 protection and persistence contract

- P1: two exact protected executable ranges are mandatory. P1a is `[0x005c1111,0x005c11c0)`, length `175`, SHA256 `A019DC18EB2C2E73616AE3F1B5AE43F0F6E6B9CB765DC52D96F074855A221024`. P1b is F3 `[0x005c11c0,0x005c120e)`, length `78`, SHA256 `8670FFC552C57F7AF2BED4D593F6BCD2BF8F5E6678AEA9713EEF9403AFAAE083`. Hash both complete ranges immediately before mutation, after all actions before save, and after fresh reopen; every readback must match its exact hash and length.
- P2: F1/F2 remain non-function raw bodies with exact byte extents `0x4a` and `0x45`; F3 remains the sole modeled function at size `0x4e`; fences remain data and adjacent functions remain unchanged.
- P3: F1/F2 inbound xref counts remain zero; F3 retains exactly one data xref from `0x005c1149`.
- P4: vtable bytes at `0x00631184` remain `a4 3f 65 00 10 12 5c 00 ec 3f 65 00`.
- P5: vtable xrefs remain exactly `0x005c1020`, `0x005c10a8`, `0x005c121b`; scalar destructor xref remains `0x00631188 -> 0x005c1210`.
- P6 is the following item-by-item literal protection table. Every field and byte hash must match pre-action, immediate post-action, and fresh-persistence readback:

| P6 item | Exact address/function range | Entry head/item kind | Current name | Function size / instruction count | Exact prototype | Current comment channels | Exact function-range byte identity |
| --- | --- | --- | --- | --- | --- | --- | --- |
| P6a constructor | address `0x005c0ff0`; range `[0x005c0ff0,0x005c109c)` | head `0x005c0ff0`; entry item `[0x005c0ff0,0x005c0ff1)`; code, `is_code:true`, `is_data:false` | `sub_5C0FF0` | `0xac` / `66` | `char *__thiscall(char *this)` | entry regular `""`, entry repeatable `""`, function regular `""`, function repeatable `""` | SHA256 `355482E94C33B801EAEC129BDADEA9020ED3F1E6B11D07E232104A9CB349E765` over exact 172 bytes |
| P6b cleanup | address `0x005c10a0`; range `[0x005c10a0,0x005c1111)` | head `0x005c10a0`; entry item `[0x005c10a0,0x005c10a1)`; code, `is_code:true`, `is_data:false` | `sub_5C10A0` | `0x71` / `37` | `int __thiscall(char *this)` | entry regular `""`, entry repeatable `""`, function regular `""`, function repeatable `""` | SHA256 `94F0372E8D7FD168DC1C2B2E3B524DC0F602C8375235C3B35B8375F2DBF9CC0B` over exact 113 bytes |
| P6c scalar destructor | address `0x005c1210`; range `[0x005c1210,0x005c129a)` | head `0x005c1210`; entry item `[0x005c1210,0x005c1211)`; code, `is_code:true`, `is_data:false` | `sub_5C1210` | `0x8a` / `47` | `char *__thiscall(char *Block, char)` | entry regular `""`, entry repeatable `""`, function regular `""`, function repeatable `""` | SHA256 `43EDF1012F758239C1A77FF919FA1FA31BC1AA8E98DB6D272656CB7D4C9BFD38` over exact 138 bytes |

Any P6 address/range/head/kind/name/size/instruction-count/prototype/comment-channel/byte-hash delta is a stop/no-save condition.
- P7: F1/F2 regular/repeatable address comments remain blank and no function comment channels are created; F3 receives only the exact function-regular comment; D1 receives only the exact repeatable data comment.
- P8: D1 preserves logical address `0x0069be3c`, protected four-byte storage span, exact zero bytes/hash, and the exact ordered 12-xref inventory. Its physical item is authorized to change only from prestate `[0x0069be3c,0x0069be3d)`, size `1`, `is_code:false`, `is_data:false` to poststate `[0x0069be3c,0x0069be40)`, size `4`, `is_code:false`, `is_data:true`, together with the accepted name/type/repeatable-comment changes and blank regular comment. The schema-valid `type_apply_batch` call must remain unchanged, have no envelope, aggregate, or item-level error, and be followed by this exact D1 readback before save. Any other materialization or delta stops without save.
- P9: T1 source declaration remains exactly `unsigned char _padding21[3]`; physical `type_inspect` must report size `44`, all seven exact names/offsets/widths and non-padding types, and exactly `_padding21 | 0x21 | 3 | unsigned __int8[3]` for the normalized padding row. Existing Windows SDK types must not be overwritten.
- P10: the byte-identical F1 raw inventory must preserve running-first, event creation, retry loop, timer-ID store, and SetEvent; the byte-identical F2 raw inventory must preserve exact no-guard order. The literal bounded F3 `decompile` request must succeed before mutation, immediately after action, and after fresh reopen and must preserve the exact object-argument, `+0x20` clear, `+0x08` critical-section enter/leave, `+0x28` infinite wait/close/clear, `+0x24` clear, `+0x04` completion signal, and five-argument stdcall-return invariant. Any mismatch stops without save or triggers backup restoration after a save.
- P11: only T1 declaration when the prestate branch is absent, F3 name/function-regular comment, and D1 name/type/repeatable comment plus the exact one-byte unknown/non-data to four-byte typed-data physical materialization may change. IDA's deterministic `unsigned char[3]` to `unsigned __int8[3]` physical display normalization is readback rendering, not an additional authorized mutation. F1/F2 and every entity outside T1/F3/D1 must remain exact.

Only after all immediate readbacks and P1-P11 pass:

`idb_save {"database":"<active-session-id-from-current-idb_list>"}`

The supervisor must hash the saved canonical IDB, stop the saved worker, reopen the canonical IDB fresh, and repeat every T1/F1/F2/F3/D1/P1-P11 readback, including `decompile {"addr":"0x005c11c0","include_addresses":true,"database":"<active-session-id-from-current-idb_list>"}`. F1/F2 must still have no function and no frame; F3 must still have exactly the three listed rows, its unchanged generic prototype, exact 78-byte hash, and exact decompile behavior invariant. D1 must persist as the exact four-byte data item `[0x0069be3c,0x0069be40)`, size `4`, `is_code:false`, `is_data:true`, with the accepted name/type/comments, exact unchanged bytes/hash, and exact 12-xref inventory. T1 must persist with total size `44`, exact seven-member names/offsets/widths/non-padding types, and exact physical padding row `_padding21 | 0x21 | 3 | unsigned __int8[3]`, while its source declaration remains `unsigned char _padding21[3]`, whether it was newly declared or already exact. Rollback must restore T1 absence when its prestate branch was absent or preserve the exact pre-existing normalized declaration when that branch was already present, and must restore D1's one-byte unknown/non-data physical prestate. Persistence must match immediate physical state exactly. Any envelope-level, aggregate, or item-level error prevents save. If any pre-save check fails, stop unsaved and reopen the canonical prestate. If save occurred and fresh persistence fails, stop the worker, restore the byte-identical backup, reopen fresh, and prove the canonical hash, the exact T1 branch prestate, original one-byte D1 prestate, both P1 range hashes, the F3 decompile invariant, and all other prestates are restored. The dated failed T1-normalization and D1-materialization attempts demonstrate these no-save rollback paths and receive no partial action credit.
<!-- END CLEANUP-20260813-0001NY-SECTION21 -->

