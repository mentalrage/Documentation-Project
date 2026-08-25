# Agent C001 Notes

## Standing C-Agent Source-Quality Policy (2026-06-15)

- Investigate source-quality blockers during normal documentation work regardless of current score. Do not stop at 85/85 if field/type/global/protocol/helper-name, caller/reachability, ownership, source-placement, split/merge/range, or final-C++ blockers remain.
- For each blocker you mention, either resolve it with supported documentation, metadata, IDA, or Wave2/Wave3 changes; record the exact evidence checked and why it cannot be safely resolved yet; or keep/lower the score if the unresolved issue limits behavior, ownership, source placement, or confidence.
- C-agent IDA work must include a safe improvement pass where evidence supports low-risk names, comments, prototypes, or type/member repairs. If no IDA database change is safe, document the exact reason instead of treating that as a final-C++ deferral.
- Do not defer an issue to "final C++" just because C++ has not yet been written. These issues must be investigated before C++ emission and throughout the score/evidence pass.

## Metadata Terminology Note (2026-06-13)

- Older entries in this log may use pre-migration `AUTOGEN_PARENT_UID`, `AUTOGEN_PARENT_POSITION`, `parent`, `parent blank`, `parentless`, or `unassigned` wording.
- Current validator metadata uses `CANONICAL_OWNER` for semantic/documentation ownership and `EMITTER_UIDS` plus `EMITTER_POSITION_OPTIONAL` for generated-output routing.
- Interpret old `AUTOGEN_PARENT_UID` entries as legacy combined owner/emitter context; do not copy them into new edits without mapping them to the current fields.
- Current generated report terms are `no-owner`, `emits`, `non-emits`, `multiple-emitters`, and `dead-ends`.

Lease report symlink: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-C001\current_leases.md`
Do not edit `current_leases.md`; read it for current lease status.

Keep this file under 100 lines except for exact pending edits blocked by leases or supervisor-owned shared files. Track only C001 work, blocked follow-ups, and exact shared-file updates that still need supervisor action.

Copied legacy A-agent history/backlog entries were removed from this file on 2026-06-12.

## 2026-06-16 - C001-goal2-direct-ida-header-footer-system-message-000246 closeout

Assignment: [UID:000246] `by-memory/0x0058af40-0x0058af48.HeaderFooterSystemMessageDefaultTrueVirtual.md`.

Changed docs and score:
- `by-memory/0x0058af40-0x0058af48.HeaderFooterSystemMessageDefaultTrueVirtual.md`: `82/86 -> 86/90`; owner/emitter retained [UID:0000OE] `SystemMessagePanes` because this is a shared Header/Footer marker-entry vtable slot inside that source family, not a single class-specific owner; final C++ remains blank.
- Validator side effects from scoped `--apply`: `project-level/-auto-completion-stats.md` and `tools/validator.ini` refreshed; autogen coverage reports were unchanged. `by-memory/-coverage-report.md` was not edited by C001.

IDA DB changes:
- Used live MCP session `a001_goal2_00023O` on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; health was `ok`, Hex-Rays ready, strings cache ready, `auto_analysis_ready:false`.
- Appended safe comments at `0x0058af40`, `0x0062d6c4`, and `0x0062d6e8`; `idb_save` returned `ok:true`.
- Skipped renames, prototypes, structs/member edits, locals/stack names, and final C++ because original virtual method spelling, declaration placement, and inherited-default versus identical-folded-override treatment are not safely recoverable.

Evidence/blockers checked:
- Exact bounds/bytes: `lookup_funcs` confirms `sub_58AF40` size `0x8`; predecessor `sub_58AF00` ends at `0x0058af3b`, successor `sub_58AF50` starts at `0x0058af50`; bytes show five `0xcc` before, `b8 01 00 00 00 c2 08 00`, then eight `0xcc`.
- Vtable/read-only data: `xrefs_to 0x0058af40` reports exactly `0x0062d6c4` and `0x0062d6e8`; raw vtable bytes at `0x0062d6a8-0x0062d6f0` confirm those dwords; `entity_query` confirms `HeaderSystemMessage`, `FooterSystemMessage`, and `ColorStringSystemMessage` vtable heads plus header/footer RTTI locators.
- Reachability/pointers: no callees and no direct code callers; `find_bytes` finds absolute pointer `40 AF 58 00` only at the two vtable cells and no RVA `40 AF 18 00` hits; no inbound xrefs to the slot cells themselves.
- Slot semantics: `ColorStringSystemMessage` vtable `+0x18` target `0x00587ae0` is the text line-count helper. Local indirect-call search found 16 `+18h` uses in system-message code; total-height and paint/layout paths pass the owning pane/context plus width-like constants `160`/`184`. Therefore [UID:000246] is behaviorally a constant one-line-count marker virtual, not a boolean "true" slot. Final method and argument names remain unresolved.

Validation and leases:
- Ran `python .\tools\validator.py --mode file --file by-memory\0x0058af40-0x0058af48.HeaderFooterSystemMessageDefaultTrueVirtual.md --apply --queue-timeout 240` from `source-3/project-documentation`; exit `0`, `ok:1`.
- Leases used: `by-memory/0x0058af40-0x0058af48.HeaderFooterSystemMessageDefaultTrueVirtual.md` and this notes file. Supervisor held `by-memory/-coverage-report.md`, and C001 is banned from editing it regardless, so the exact pending row is below.

Supervisor-owned `by-memory/-coverage-report.md` row:
- Do not edit `by-memory/-coverage-report.md` directly. Placement context: replace the existing [UID:000246] row under the system-message cluster around current line 2779, preserving the adjacent padding rows `0x0058af3b-0x0058af40` immediately before and `0x0058af48-0x0058af50` immediately after.
- Replace existing [UID:000246] row with:
```text
    - [UID:000246][0x0058af40-0x0058af48.HeaderFooterSystemMessageDefaultTrueVirtual](by-memory/0x0058af40-0x0058af48.HeaderFooterSystemMessageDefaultTrueVirtual.md) 0x0058af40-0x0058af48 | virtual helper | HeaderFooterSystemMessageConstantLineCountVirtual : reconstructable : 86% : very-strong : C001 live IDA refresh confirms exact `sub_58AF40` `0x8` boundary, raw bytes `b8 01 00 00 00 c2 08 00`, five-byte pre-padding and eight-byte post-padding, only two data refs from `HeaderSystemMessage`/`FooterSystemMessage` vtable `+0x18` cells at `0x0062d6c4`/`0x0062d6e8`, absolute pointer hits only at those cells with zero RVA hits, no callees or direct code callers, `ColorStringSystemMessage` `+0x18` line-count comparator, 16 local indirect `+18h` uses passing pane/context plus width-like arguments, retained [UID:0000OE] owner/emitter route, saved IDA comments, and final C++ blank pending original virtual method spelling, declaration placement, and inherited-default versus folded-override treatment.
```

Supervisor correction (2026-06-16): C001 was reassigned to the same file because `memory_ranges.py report` still flagged `HeaderFooterSystemMessageDefaultTrueVirtual` as missing from the document body after the closeout. Supervisor applied the mechanical filename-label sentence while preserving C001's corrected line-count semantics, then applied the reviewed coverage row. Future C001 closeouts from memory-tool advanced-scan targets must run `memory_ranges.py report` and verify their own filename-text issue is cleared before reporting complete.

## 2026-06-16 - C001-goal2-direct-ida-scrollvolume-commit-0001H4 closeout

Assignment: [UID:0001H4] `by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md`.

Changed docs and score:
- `by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md`: `82/86 -> 85/89`; owner/emitter retained [UID:0001H2] `ScrollVolumePane` aggregate, which routes through [UID:0000CO] `ScrollVolumePane` and [UID:0000NK] `ScrollVolumePane.cpp`; final C++ remains blank.
- Validator side effects from scoped `--apply`: `project-level/-auto-completion-stats.md` and `tools/validator.ini` refreshed; autogen coverage reports were unchanged. `by-memory/-coverage-report.md` was not edited by C001.

IDA DB changes:
- Used live MCP session `a001_goal2_00023O` on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; health was `ok`, Hex-Rays ready, `auto_analysis_ready:false`.
- Appended safe comments at `0x005652a0`, raw call site `0x00565272`, value helper `0x00565360`, EventMan cursor getter `0x004a9090`, and pane-origin helper `0x005447c0`; `idb_save` returned `ok:true`.
- Skipped renames, prototypes, structs/member edits, local/stack edits, raw function creation, and final C++ because original helper/member/source names and raw helper function representation remain unresolved.

Evidence/blockers checked:
- Function/xref: `lookup_funcs` confirms `0x005652a0` as `sub_5652A0` size `0xc0`; raw starts `0x00565170`, `0x005651e0`, and `0x00565490` remain not functions. `xrefs_to 0x005652a0` gives modeled calls at `0x00564a83`/`0x00564b28` plus raw call `0x00565272`; `xrefs_to` the raw starts remains zero.
- Raw reachability: disassembly of `0x005651e0-0x005652a0` shows `mov [esi+104h], bl` at `0x0056526c`, call `0x005652a0` at `0x00565272`, timer scheduling at `0x00565288`, `retn 0Ch` at `0x0056529c`, and one `0xcc` before the modeled helper.
- Pointer/search: VA/RVA little-endian byte searches found zero pointer hits for `0x005652a0`, `0x005651e0`, `0x00565360`, and `0x00565010`.
- Names/fields: `+0x103` and `+0x104` are behaviorally resolved as highlighted part and active interaction part, but not final member names. `EventMan::GetCursorPosition` is supported by EventMan docs and live decompilation; `0x005447c0` remains only a pane origin/coordinate helper with unresolved final source name. Stale generated `TextEditPane::HandleScrollbarMouseF` is rejected by current caller/field evidence but not repaired in Wave3/simroot.

Validation and leases:
- Ran `python .\tools\validator.py --mode file --file by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md --apply --queue-timeout 240` twice from `source-3/project-documentation`: first pass updated score/reference state and exposed a mistaken root-doc UID reference, second pass after fixing it exited `0` with `ok:1`.
- Leases used: `by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md`, `by-memory/0x00564710-0x005654ec.ScrollVolumePane.md` (read/lease support; no edit), and this notes file. Supervisor held `by-memory/-coverage-report.md`, so the exact pending row is below.

Supervisor-owned `by-memory/-coverage-report.md` row:
- Do not edit `by-memory/-coverage-report.md` directly. Placement context: replace the existing [UID:0001H4] row under [UID:0001H2] `0x00564710-0x005654ec.ScrollVolumePane`, around current line 2611, preserving sibling rows.
- Replace existing [UID:0001H4] row with:
```text
        - [UID:0001H4][0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction](by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md) 0x005652a0-0x00565360 | method | ScrollVolumePaneCommitInteraction : reconstructable : 85% : very-strong : C001 live IDA refresh confirms `sub_5652A0` exact `0xc0` range, modeled mouse/focus callers at `0x00564a83`/`0x00564b28`, raw begin-interaction call at `0x00565272`, zero xrefs to raw helper starts, zero VA/RVA pointer hits for commit/raw/notify/rect helper starts, current callees/decompilation for cursor-origin conversion, thumb/matching-part notify paths, `+0x103` highlighted-part clear, `+0x104` active-part compare, saved IDA comments, rejected stale `TextEditPane::HandleScrollbarMouseF` ownership, and final C++ blank pending final helper/member names, raw-helper representation, pane-origin helper name, and declaration shape.
```

## 2026-06-16 - C001-goal2-direct-ida-queue-refresh-20260616 closeout

Assignment: [UID:0001FM] `by-memory/0x005539e0-0x00553a5c.QueueConstructor.md`, [UID:0001FN] `by-memory/0x005539e0-0x00553c07.Queue.md`, [UID:0001FO] `by-memory/0x00553a60-0x00553ab9.QueueDestructor.md`.

Changed docs and scores:
- `by-memory/0x005539e0-0x00553a5c.QueueConstructor.md`: `82/86 -> 85/89`; owner/emitter changed from [UID:0000MW] `Queue.cpp` to direct [UID:0000BF] `Queue`, emitter position `10`; final C++ blank.
- `by-memory/0x005539e0-0x00553c07.Queue.md`: `82/86 -> 85/88`; owner/emitter changed from [UID:0000MW] to direct [UID:0000BF], position `5`; final C++ blank.
- `by-memory/0x00553a60-0x00553ab9.QueueDestructor.md`: `82/86 -> 85/89`; owner/emitter changed from [UID:0000MW] to direct [UID:0000BF], position `20`; final C++ blank.
- Support docs: raw write/read/empty helpers stayed `85/88` but owner/emitter changed from [UID:0000MW] to direct [UID:0000BF] at positions `30/40/50`; scalar deleting destructor `84/90 -> 85/91`, owner/emitter [UID:0000BF] position `60`; `QueueVtableData` `86/92 -> 87/93` with corrected slots.
- Validator side effects from scoped file validation: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, and `tools/validator.ini` refreshed. `by-memory/-coverage-report.md` was not manually edited by C001; exact pending row text is below.

IDA DB changes:
- Used live MCP session `a002_goal65_20260616` on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Appended safe comments at `0x005539e0`, `0x00553a60`, raw starts `0x00553ac0`, `0x00553b10`, `0x00553b60`, scalar deleting destructor `0x00553b70`, and vtable base `0x00622d24`; `idb_save` returned `ok:true`.
- Skipped IDA renames, prototypes, type/member declarations, stack/local edits, and `define_func` for raw helper starts because exact original API names and direct raw-start reachability are still unproven.

Evidence/blocker investigation:
- Constructor/destructor: live `lookup_funcs`, `decompile`, `callees`, `xrefs_to`, `analyze_function`, `get_bytes`, and VA/RVA pointer-byte searches confirm modeled constructor size `0x7c`, ordinary destructor size `0x59`, scalar wrapper size `0x97`, no direct constructor/destructor callers or pointer hits, and the expected MemoryMan/LObject callees.
- Layout/member names: constructor and raw helpers confirm `+0x04` is slot byte size/copy stride, `+0x08` is slot count/wrap limit, `+0x0c` is backing buffer, `+0x10` read index, and `+0x14` write index.
- Helper/API split: raw write/read/empty starts remain not functions, have no xrefs/callers/callees from function-query tools, and have zero absolute/RVA pointer-byte hits. Role names remain documented, but final source spellings such as `Write`/`Push`/`Enqueue`, `Read`/`Pop`/`Dequeue`, and `IsEmpty` are not safely recoverable yet.
- Vtable/source ownership: raw bytes at `0x00622d20-0x00622d40` correct Queue slots to `0x00553b70`, `0x004f4b10`, `0x0041b6c0`; `0x00554b00` was rejected as a Queue slot because current refs tie it to `Region` vtable cell `0x00622f58`. Direct semantic owner is now [UID:0000BF] `Queue`, with emitter route through [UID:0000MW] `Queue.cpp`.
- Final-C++ blockers remain real after investigation: no active construction/raw-helper reachability, no original helper method spelling, final `Queue.h`/`Queue.cpp` declaration shape not audited, raw helper representation unresolved, and scalar deleting destructor should be compiler-regenerated rather than handwritten.

Validation and leases:
- Ran `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240` for all eight changed Queue by-memory docs from `source-3/project-documentation`; loop exited `0`. Validator output reported `ok:1` per scoped file and updated generated owner/emitter registry rows for the Queue children.
- Lease handling: C001 initially leased and edited Queue docs, then paused when `current_leases.md` showed an overlapping Agent-A002 Queue lease window `2026-06-16T17:37:40Z-17:42:40Z`. After that expired, C001 reacquired the eight Queue doc leases (`17:43:33Z-17:48:33Z`) and notes lease (`17:45:52Z-17:50:52Z`) before validation/notes.

Supervisor-owned `by-memory/-coverage-report.md` rows:
- Do not edit `by-memory/-coverage-report.md` directly. Placement context: replace the existing Queue rows around current lines 2457-2467, preserving adjacent padding rows. Insert the vtable child row under [UID:000269] around current line 3220, before [UID:00026A].
- Replace existing [UID:0001FN] row with:
```text
    - [UID:0001FN][0x005539e0-0x00553c07.Queue](by-memory/0x005539e0-0x00553c07.Queue.md) 0x005539e0-0x00553c07 | class aggregate | Queue : reconstructable : 85% : very-strong : C001 live IDA refresh confirms exact Queue method cluster, modeled constructor/destructor/scalar-wrapper bounds, raw write/read/empty non-function starts, class owner/emitter route through [UID:0000BF], corrected slot layout at `+0x04/+0x08/+0x0c/+0x10/+0x14`, internal `0xcc` alignment, no constructor/destructor/raw direct xrefs or pointer hits, vtable-only scalar-wrapper reference, corrected Queue vtable slots `0x00553b70`/`0x004f4b10`/`0x0041b6c0`, saved IDA comments, generated-output omissions, and final C++ blank pending raw-helper API names, reachability, and final header/source shape.
```
- Replace existing [UID:0001FM] row with:
```text
    - [UID:0001FM][0x005539e0-0x00553a5c.QueueConstructor](by-memory/0x005539e0-0x00553a5c.QueueConstructor.md) 0x005539e0-0x00553a5c | constructor | QueueConstructor : reconstructable : 85% : very-strong : C001 live IDA refresh confirms exact `0x7c` modeled constructor, `LObject` base construction, Queue vtable install, `slotSize` store at `+0x04`, `slotCount` store at `+0x08`, `slotSize * slotCount` allocation through `sub_5160D0`, read/write index zeroing, no direct callers/xrefs or VA/RVA pointer hits, direct class owner/emitter [UID:0000BF] position `10`, saved IDA comment, and final C++ blank pending construction reachability plus final parameter/header names.
```
- Replace existing [UID:0001FO] row with:
```text
    - [UID:0001FO][0x00553a60-0x00553ab9.QueueDestructor](by-memory/0x00553a60-0x00553ab9.QueueDestructor.md) 0x00553a60-0x00553ab9 | destructor | QueueDestructor : reconstructable : 85% : very-strong : C001 live IDA refresh confirms exact `0x59` modeled ordinary destructor, Queue vtable restore, `+0x0c` backing-buffer free/clear through `sub_516030`/`sub_516170`, `LObject` cleanup through `sub_4F4A90`, scalar-wrapper corroboration, no direct callers/xrefs or VA/RVA pointer hits, direct class owner/emitter [UID:0000BF] position `20`, saved IDA comment, and final C++ blank pending non-deleting destructor reachability plus final declaration shape.
```
- Replace existing [UID:0001FP] row with:
```text
    - [UID:0001FP][0x00553ac0-0x00553b05.QueueWriteSlotRaw](by-memory/0x00553ac0-0x00553b05.QueueWriteSlotRaw.md) 0x00553ac0-0x00553b05 | raw helper | QueueWriteSlotRaw : reconstructable : 85% : very-strong : Raw Queue write-slot helper with direct class owner/emitter [UID:0000BF] position `30`; C001/A001 live IDA evidence confirms no function object, no xrefs/callers, no VA/RVA pointer-byte hits, exact seven-byte pre-padding, complete `0x45`/69-byte body through `retn 4`, eleven-byte post-padding, MemoryMan getter/copy-helper calls, `slotSize`/`writeIndex`/wrap behavior, saved IDA line comment, and final C++ blank pending original method spelling and raw-helper reachability representation.
```
- Replace existing [UID:0001FQ] row with:
```text
    - [UID:0001FQ][0x00553b10-0x00553b55.QueueReadSlotRaw](by-memory/0x00553b10-0x00553b55.QueueReadSlotRaw.md) 0x00553b10-0x00553b55 | raw helper | QueueReadSlotRaw : reconstructable : 85% : very-strong : Raw Queue read-slot helper with direct class owner/emitter [UID:0000BF] position `40`; C001/A001 live IDA evidence confirms no function object, no xrefs/callers, no VA/RVA pointer-byte hits, exact eleven-byte pre-padding, complete `0x45`/69-byte body through `retn 4`, eleven-byte post-padding, MemoryMan getter/copy-helper calls, `slotSize`/`readIndex`/wrap behavior, saved IDA line comment, and final C++ blank pending original method spelling and raw-helper reachability representation.
```
- Replace existing [UID:0001FR] row with:
```text
    - [UID:0001FR][0x00553b60-0x00553b6a.QueueIsEmptyRaw](by-memory/0x00553b60-0x00553b6a.QueueIsEmptyRaw.md) 0x00553b60-0x00553b6a | raw helper | QueueIsEmptyRaw : reconstructable : 85% : very-strong : Raw Queue empty predicate with direct class owner/emitter [UID:0000BF] position `50`; C001/A001 live IDA evidence confirms no function object, no xrefs/callers/callees, no VA/RVA pointer-byte hits, exact ten-byte body comparing read/write indices at `+0x10/+0x14`, eleven-byte pre-padding, six-byte post-padding before the scalar wrapper, saved IDA line comment, and final C++ blank pending original method spelling and raw-helper reachability representation.
```
- Replace existing [UID:0001FS] row with:
```text
    - [UID:0001FS][0x00553b70-0x00553c07.QueueScalarDeletingDestructor](by-memory/0x00553b70-0x00553c07.QueueScalarDeletingDestructor.md) 0x00553b70-0x00553c07 | scalar deleting destructor | QueueScalarDeletingDestructor : reconstructable : 85% : very-strong : C001 live IDA refresh confirms exact `0x97` modeled scalar deleting destructor wrapper, single vtable data xref from `0x00622d24`, no direct callers, Queue vtable restore, `+0x0c` buffer cleanup through `sub_516030`/`sub_516170`, `LObject` teardown, optional `sub_4F4AC0` delete path, guard-check bit-4 branch, direct class owner/emitter [UID:0000BF] position `60`, saved IDA comment, and final C++ blank because this wrapper should be compiler-regenerated from the source-level virtual destructor.
```
- Insert this [UID:0003CS] row under [UID:000269] `QueueReconnectCopyReadOnlyData`, before [UID:00026A]:
```text
        - [UID:0003CS][0x00622d24-0x00622d30.QueueVtableData](by-memory/0x00622d24-0x00622d30.QueueVtableData.md) 0x00622d24-0x00622d30 | vtable-data | QueueVtableData : reconstructable : 87% : very-strong : Exact Queue vtable slice owned/emitted by [UID:0000BF]; C001 live IDA raw bytes correct slots to `0x00553b70`, inherited `LObject` runtime-class accessor `0x004f4b10`, and inherited no-op virtual `0x0041b6c0`, confirm constructor/destructor/scalar vptr-store xrefs at `0x00553a15`, `0x00553a88`, and `0x00553b9f`, reject stale `0x00554b00` as the Region vtable target at `0x00622f58`, preserve next `ConnectionClosedDialog` locator boundary at `0x00622d30`, and record the saved IDA vtable-base comment.
```

## 2026-06-16 - C001-goal2-direct-ida-message-dialog-refresh-20260616-36 closeout

Changed target docs and scores:
- `by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md`: `82/86 -> 85/90`; owner/emitter retained [UID:0000LA] `MessageDialogs`; final C++ remains blank.
- `by-memory/0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor.md`: `82/86 -> 85/90`; owner/emitter retained [UID:0000LA] `MessageDialogs`, with direct class role documented through [UID:0000BE] `PursuitMessageDialogPane`; final C++ remains blank.
- `by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md`: `82/86 -> 85/90`; owner/emitter retained [UID:0000LA] `MessageDialogs` because the implementation is vtable-shared across sibling dialog classes; final C++ remains blank.
- Support docs `by-file/MessageDialogs.md` and `by-class/PursuitMessageDialogPane.md` were reviewed and validated; no additional support-page edits were made by this pass after the MessageDialog assignment resumed.
- Validator side effects: `auto-generated/-ag-memory-coverage.md` and `project-level/-auto-completion-stats.md` refreshed. `by-memory/-coverage-report.md` was not left modified; a validator side-effect diff was restored and the exact supervisor-owned replacement rows are below.

IDA DB changes:
- Used live MCP session `a002_goal65_20260616` on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; `server_health` reported status `ok`, Hex-Rays ready, strings cache ready, and `auto_analysis_ready:false`, so checks were targeted.
- Appended safe evidence comments at `0x0054c200`, wrapper starts `0x0054c570`, `0x0054c5d0`, `0x0054c630`, `0x0054c690`, `0x0054c6f0`, `0x0054c750`, `0x0054c7b0`, `0x0054c810`, `0x0054c870`, `0x0054c8d0`, `0x0054c930`, `0x0054c990`, `0x0054c9f0`, `0x0054ca50`, raw constructor start `0x0054cab0`, and `0x0054caf0`; `idb_save` returned `ok:true`.
- Existing prior safe rename `0x0054caf0 -> MessageDialogObjectResponseVirtual` was already present. No new IDA renames were applied. Skipped prototypes, locals, stack declarations, type/member edits, raw function creation, source-facing wrapper/constructor names, and final C++.

Evidence/blocker investigation:
- Dispatcher/wrappers: live `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, and `get_bytes` reconfirmed dispatcher callers `0x00507e2e`/`0x0051287f`, wrapper sizes, `0x278` versus `0x304` allocation sizes, constructor callee map, polluted `___std_parallel_algorithms_hw_threads` labels, and `0x0054c511-0x0054c570` as dispatcher target-table bytes plus trailing `0xcc`.
- Raw constructor: live disassembly reconfirmed `DialogPane(L"", 1, 1)`, vtable stores to `0x00622428`, `0x00622488`, and `0x006224b8`; `lookup_funcs` still reports `0x0054cab0` not a function, `xrefs_to 0x0054cab0` returned zero, and VA/RVA pointer scans for `B0 CA 54 00` / `B0 CA 14 00` returned zero.
- Shared response virtual: live decompilation reconfirmed payload `0x2f` handled and `0x30` object-response behavior, object-status parse at `payload+8`, opcode `0x3a`, and send through `dword_67A7EC`/`0x00574bb0`; pointer scans/xrefs reconfirmed exactly eight vtable refs to `0x0054caf0`.
- Final-C++ blockers remain real after investigation: packet structure names, dialog wrapper/constructor source names, SEH allocation cleanup representation, raw constructor reachability/function modeling, final class/base declaration shape, action payload/object-status result types, packet sender interface, and generated-output omissions.

Validation:
- Ran `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240` for the three target by-memory docs plus support `by-file/MessageDialogs.md` and `by-class/PursuitMessageDialogPane.md` from `source-3/project-documentation`.
- Sequential validation loop exited `0`; each scoped file validation reported `ok:1`. Target validations recorded completion/confidence updates for [UID:00023M], [UID:0001FE], and [UID:0001FF] and removed those rows from generated low-score stats.

Leases and Queue collision:
- C001 held scoped leases for the three target by-memory docs, `by-file/MessageDialogs.md`, `by-class/PursuitMessageDialogPane.md`, and this notes file.
- Earlier in the turn C001 also had Queue-related leases/working-tree changes visible. After supervisor correction, C001 released the eight named Queue leases and made no further Queue edits or validations. Queue remains out of scope for this closeout.

Supervisor-owned `by-memory/-coverage-report.md` rows:
- Do not edit `by-memory/-coverage-report.md` directly. Placement context: replace the existing [UID:00023M], [UID:0001FE], and [UID:0001FF] rows around current lines 2437, 2439, and 2441, preserving the adjacent padding rows.
- Replace existing [UID:00023M] row with:
```text
    - [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) 0x0054c200-0x0054caa9 | packet helper function cluster | MessageDialogPacketDispatcherAndWrappers : reconstructable : 85% : very strong : Direct C001 IDA refresh reconfirms dispatcher callers `0x00507e2e`/`0x0051287f`, modeled wrapper sizes, wrapper callee/allocation map, polluted wrapper labels handled with saved comments rather than unsafe renames, switch target-table bytes at `0x0054c511-0x0054c570`, boundary/inter-wrapper padding, generated Motion ownership pollution, MessageDialogs owner/emitter route, and final C++ blank pending packet structure, wrapper/constructor names, and SEH allocation cleanup source shape.
```
- Replace existing [UID:0001FE] row with:
```text
    - [UID:0001FE][0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor](by-memory/0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor.md) 0x0054cab0-0x0054cae9 | raw constructor | PursuitMessageDialogPaneConstructor : reconstructable : 85% : very strong : Direct C001 IDA refresh reconfirms raw non-function status, exact `DialogPane(L"",1,1)` constructor-shaped disassembly, vtable stores/xrefs to `0x00622428`, `0x00622488`, and `0x006224b8`, zero constructor-start xrefs, zero VA/RVA pointer hits, adjacent seven-byte `0xcc` padding, saved raw-start comment, MessageDialogs owner/emitter route with class role through [UID:0000BE], and final C++ blank pending raw reachability/function modeling plus final class/constructor declaration shape.
```
- Replace existing [UID:0001FF] row with:
```text
    - [UID:0001FF][0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual](by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md) 0x0054caf0-0x0054cc2f | virtual handler | MessageDialogObjectResponseVirtual : reconstructable : 85% : very strong : Direct C001 IDA refresh reconfirms modeled function name/size, exact eight vtable pointer refs at `0x00622498`, `0x00622534`, `0x006225d0`, `0x0062266c`, `0x00622708`, `0x0062292c`, `0x006229c8`, and `0x00622cc8`, payload `0x2f`/`0x30` behavior, ObjectStatusBlob parse dependency, opcode `0x3a` send through `dword_67A7EC`/`0x00574bb0`, generated-output omission, saved function comment, MessageDialogs owner/emitter route rather than exclusive class ownership, and final C++ blank pending payload struct, parser/result type, packet sender interface, and source-facing virtual name.
```

Supervisor integration update (2026-06-16): supervisor accepted `C001-goal2-direct-ida-message-dialog-refresh-20260616-36` after reviewing the target/support docs, IDA-safe comment scope, and source-quality blocker investigations. The exact [UID:00023M], [UID:0001FE], and [UID:0001FF] `by-memory/-coverage-report.md` rows were applied, and scoped validators for all three targets, [UID:0000LA] `MessageDialogs`, [UID:0000BE] `PursuitMessageDialogPane`, and the shared report exited `0` with `ok:1`. No C001 supervisor-owned memory coverage rows remain pending for this batch. Queue collision note accepted: Queue files were left to A002 after C001 released those leases.

## 2026-06-16 - C001-goal2-direct-ida-new-predefined-form-article-dialog-20260616-35 closeout

Changed docs and scores:
- `by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md`: `82/86 -> 85/90`; owner/emitter retained [UID:0000LT] `NewPredefinedFormArticleDialog`; final C++ remains blank.
- `by-memory/0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl.md`: `82/88 -> 85/90`; owner/emitter changed from [UID:0000LT] file root to direct [UID:000098] `NewPredefinedFormArticleDialog`; final C++ remains blank.
- `by-memory/0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md`: score unchanged `87/88`; owner/emitter changed from [UID:0000LT] file root to direct [UID:000098] class.
- `by-memory/0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert.md`: score unchanged `86/88`; owner/emitter changed from [UID:0000LT] file root to direct [UID:000098] class.
- `by-memory/0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle.md`: score unchanged `86/87`; owner/emitter changed from [UID:0000LT] file root to direct [UID:000098] class.

IDA DB changes:
- Used live MCP session `a002_goal65_20260616` on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Appended safe evidence comments at `0x004777a0`, raw `0x004781f0`, `0x00478370`, `0x00478940`, `0x00478aa0`, `0x00478be0`, and `0x0047ec30`; saved IDB successfully (`idb_save ok:true`).
- Skipped unsafe IDA edits: function renames, prototypes, locals, stack declarations, struct/member/type edits, raw function creation at `0x004781f0`/`0x00478f90`/`0x00479050`, and final reconstruction C++.

Evidence/blocker investigation:
- Live IDA reconfirmed modeled function sizes for `0x004777a0`, `0x00478240`, `0x004782b0`, `0x00478370`, `0x00478380`, `0x00478650`, `0x00478940`, `0x00478aa0`, and `0x00478be0`, and confirmed raw/non-function status for `0x004781f0`, `0x00478f90`, and `0x00479050`.
- Xrefs reconfirmed constructor caller `0x00471d4a`, parser edges `0x00477848`/`0x00477d0c`, submit edge `0x0047827e`, NewPredefined vtable slots `0x00614094`, `0x00614098`, `0x006140a8`, `0x006140ac`, and `0x006140e8`, plus destructor/thunk companion refs.
- Byte audit reconfirmed every inter-child gap is `0xcc` padding. Raw VA/RVA pointer-pattern searches for `0x004781f0`, `0x00478aa0`, `0x00478f90`, and `0x00479050` returned zero hits.
- Parser remains file-local under [UID:0000LT]. Vtable-backed methods and submit helper now route through direct class [UID:000098]. Retained-helper policy for `0x00478aa0` and final source names for constructor controls, parser record members, packet wrappers, DialogSession/alert helpers, and hover helper remain blockers; B escalation is useful only if final retained-helper emission/source-shape must be decided now.

Validation:
- Ran `python .\tools\validator.py --mode file --file <changed-by-memory-file> --apply --queue-timeout 240` for the five changed by-memory files from `source-3/project-documentation`; loop exited `0` and each file scan reported `ok: 1`.
- Validator side effects included autogen registry/report refresh and generated `project-level/-auto-completion-stats.md` row removal for [UID:0000ZL]; `by-memory/-coverage-report.md` was not edited by C001.

Leases:
- Acquired C001 leases for all five changed by-memory docs and this notes file before editing. Release attempt after validation returned `Rejected[No active lease]` for the assignment-scoped files because the leases had expired naturally; a notes-only lease was reacquired to record this correction and released successfully. Final lease report showed no active C001 leases.

Supervisor-owned `by-memory/-coverage-report.md` rows:
- Do not edit `by-memory/-coverage-report.md` directly. Placement context: replace existing [UID:0000ZL] row around current line 688, [UID:0002UK] around line 693, [UID:0002UN] around line 697, [UID:0002UQ] around line 703, and [UID:0002UL] around line 707, preserving indentation.
- Replace existing [UID:0000ZL] row with:
```text
    - [UID:0000ZL][0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog](by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md) 0x004777a0-0x00478f8e | class/function cluster parent | NewPredefinedFormArticleDialog : reconstructable : 85% : very strong : Direct C001 IDA refresh reconfirms exact aggregate range, modeled child sizes, raw helper non-function status, constructor/parser/submit edges, NewPredefined vtable slots, destructor/thunk companions, all inter-child `0xcc` padding, zero VA/RVA pointer hits for retained/raw helpers, saved IDA comments, file owner/emitter route, class-method child routing through [UID:000098], and final C++ blank pending dynamic-control, parser-record, packet/helper, and retained-helper emission source-quality blockers.
```
- Replace existing [UID:0002UK] row with:
```text
      - [UID:0002UK][0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick](by-memory/0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md) 0x00478240-0x004782a2 | virtual button handler | NewPredefinedFormArticleDialogHandleButtonClick : reconstructable : 87% : strong : Direct class-parented predefined article button handler; live IDA confirms exact `0x62`-byte bounds, vtable slot `0x00614098`, OK path selected-board read at `this+0x270`/`session+0x102`, sole submit edge `0x0047827e -> 0x00478be0`, `dword_67A748+0x214` restore, cancel path through `sub_4A10E0(0)`, complete callee list, owner/emitter [UID:000098], and final C++ blank pending source-final session/control/helper names.
```
- Replace existing [UID:0002UN] row with:
```text
      - [UID:0002UN][0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl](by-memory/0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl.md) 0x00478370-0x00478379 | hover forwarder | NewPredefinedFormArticleDialogSetHoverControl : reconstructable : 85% : very strong : Tiny direct class-parented vtable hover-control forwarder with live IDA-confirmed exact `0x9` range, four-instruction body `push ebp; mov ebp, esp; pop ebp; jmp sub_49FC00`, single inbound data edge `0x006140a8 -> 0x00478370`, adjacent aggregate padding, saved IDA comment, owner/emitter [UID:000098], and final C++ blank pending source-facing virtual/helper names.
```
- Replace existing [UID:0002UQ] row with:
```text
      - [UID:0002UQ][0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert](by-memory/0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert.md) 0x00478940-0x00478a93 | transfer reply handler | NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert : reconstructable : 86% : strong : Direct class-parented predefined transfer-reply handler; live IDA confirms exact `0x153`-byte bounds, vtable slot `0x006140ac`, packet subcommand `0x06` at `packet+1`, mode/message length/message bytes at `+2/+3/+4`, `MultiByteToWideChar`, `0x274`-byte alert allocation, predefined-alert vtable stores `0x00614194`/`0x006141fc`/`0x0061422c`, reply-mode store at alert `+0x270`, complete callee list, owner/emitter [UID:000098], and final C++ blank pending packet/helper/alert names plus retained-helper emission policy.
```
- Replace existing [UID:0002UL] row with:
```text
      - [UID:0002UL][0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle](by-memory/0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle.md) 0x00478be0-0x00478f8e | submit helper | NewPredefinedFormArticleDialogSubmitArticle : reconstructable : 86% : strong : Direct class-parented submit helper; live IDA confirms exact `0x3ae`-byte bounds, sole caller `0x0047827e`, subject control id `3`, free-text control id `4` versus parsed-row label/value controls, row count `this+0x274`, `0x40c` row stride, row fields `+0x47a`/`+0x680`, opcode `0x3b` subcommand `4` packet serialization, `dword_67A7EC` queue call, `sub_5975E0` timeout `0x3a98`, complete callee/range-check inventory, owner/emitter [UID:000098], and final C++ blank pending source-final control, packet-buffer, row-record, and network-helper declarations.
```

Supervisor integration update (2026-06-16): supervisor accepted `C001-goal2-direct-ida-new-predefined-form-article-dialog-20260616-35` after verifying target docs, safe IDA comment evidence, owner/emitter route changes, and source-quality blockers. The exact [UID:0000ZL], [UID:0002UK], [UID:0002UN], [UID:0002UQ], and [UID:0002UL] `by-memory/-coverage-report.md` replacement rows were applied, and scoped validators for all five targets plus the shared report exited `0` with `ok:1`. No C001 supervisor-owned memory coverage rows remain pending for this batch.

## 2026-06-16 Supervisor Integration - C001-goal2-direct-ida-clan-menuitem-refresh-20260616

- Supervisor accepted the direct-IDA Clan/MenuItem batch after verifying target docs and shared rows. [UID:0002OC] `ClanItemDialogVtableResetDestructorTail`, [UID:0002J4] `MenuItemStateFlag0Accessor`, [UID:0002JJ] `MenuItemCopyBoundsRect`, and [UID:0002JK] `MenuItemSetBoundsRect` all clear the gate at `85/91`.
- C001 investigated source-quality blockers for the destructor-tail/base-cleanup name, MenuItem state-byte semantics, raw bounds-copy/set helper reachability, and source-authored-vs-inline status. IDA DB comments were saved; unsafe renames, prototypes, raw function creation, member/type edits, and final C++ were correctly skipped.
- Supervisor confirmed the four exact `by-memory/-coverage-report.md` replacement rows are present and reran scoped validators for the shared report and four target docs; all exited `0` with `ok:1`. No C001 supervisor-owned memory coverage rows remain pending for this batch.

## 2026-06-16 - C001-goal2-direct-ida-clanbank-pane-family-refresh-20260616-34 closeout

Changed files and scores:
- `by-memory/0x0048a1c0-0x0048a805.ClanDepItemDialog.md`: `82/86 -> 85/90`; owner/emitter retained [UID:0000I9] `ClanBank`; final C++ remains blank.
- `by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md`: `82/86 -> 85/90`; owner/emitter retained [UID:0000I9] `ClanBank`; final C++ remains blank.
- `by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md`: `82/86 -> 85/90`; owner/emitter retained [UID:0000I9] `ClanBank`; final C++ remains blank.
- `by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md`: `82/86 -> 85/90`; owner/emitter retained [UID:0000I9] `ClanBank`; final C++ remains blank.
- Required validator `--apply` rebuilt derived metadata/stats (`tools/validator.ini`, `project-level/-auto-completion-stats.md`); `by-memory/-coverage-report.md` was not edited.

IDA DB changes:
- Live session `a002_goal65_20260616` on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64` was used for names/bounds/xrefs/decompilation/disassembly, vtable/resource/singleton refs, byte padding, pointer scans, and comments.
- Appended evidence comments at functions `0x0048a1c0`, `0x0048a690`, `0x0048a6b0`, `0x0048a790`, `0x0048a810`, `0x0048acf0`, `0x0048ad10`, `0x0048adf0`, `0x0048b1c0`, `0x0048b600`, `0x0048b630`, `0x0048b8c0`, `0x0048c040`, and support destructor `0x0048c3d0`, plus line comments at raw non-functions `0x0048b7e0` and `0x0048b870`.
- Save result: `idb_save ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Skipped unsafe edits: renames, prototypes, locals, stack declarations, struct/member/type edits, raw function creation for `0x0048b7e0`/`0x0048b870`, source-facing packet/widget/helper names, and final reconstruction C++.

Source-quality investigation:
- Deposit/withdraw dialogs: constructor caller sets, vtable-only action/send anchors, resource bytes, packet opcodes/subtypes, item-list dependencies, and reset-helper disassembly were checked. Final C++ is blocked by inherited `ClanItemDialog` field names, control IDs, exact virtual names, shared slide-helper placement, and IDA's misleading base-cleanup type on reset helpers.
- ClanBankPane: singleton lifecycle refs, constructor callers, vtable stores, resource/format xrefs, child list construction, close/submit packet bytes, and raw helper starts were checked. Final C++ is blocked by widget/member names, raw helper source callability/name evidence, and shared slide-helper placement.
- ClanBankItemListPane: constructor/parser cases `10/15/16`, sole parent caller, draw vtable anchor, support destructor refs, row formatting, text fit/image helpers, and resource bytes were checked. Final C++ is blocked by entry-record field names, local names, exact virtual names, and final helper declarations.

Validation commands/results:
- Ran `python .\tools\validator.py --mode file --file <target> --apply --queue-timeout 240` from `source-3/project-documentation` for all four touched by-memory target docs.
- Each validator exited `0` with `ok: 1`: [UID:00010O], [UID:00010P], [UID:00010R], and [UID:00010S].

Leases:
- Acquired C001 leases for the four target by-memory docs and this notes file before editing. Release will be attempted immediately after this note update.

Supervisor-owned `by-memory/-coverage-report.md` rows:
- Do not edit `by-memory/-coverage-report.md` directly. Placement context: replace existing [UID:00010O] row around current line 1032, [UID:00010P] row around current line 1034, [UID:00010R] row around current line 1038, and [UID:00010S] row around current line 1042, preserving indentation.
- Replace existing [UID:00010O] row with:
```text
    - [UID:00010O][0x0048a1c0-0x0048a805.ClanDepItemDialog](by-memory/0x0048a1c0-0x0048a805.ClanDepItemDialog.md) 0x0048a1c0-0x0048a805 | class methods | ClanDepItemDialog : reconstructable : 85% : very strong : Direct IDA refresh reconfirms deposit item dialog constructor/reset/action/send ranges, two constructor callers, vtable-only action/send anchors, MyItemListPane dependency, opcode 0x4b subtype 5 packet bytes, pointer-hit scan limited to vtable entries, unique range signature, DLGCLAN3.EPF byte-backed resource evidence, saved IDA comments, ClanBank owner/emitter route, and final C++ blank pending field/control/virtual names plus shared slide-helper placement.
```
- Replace existing [UID:00010P] row with:
```text
    - [UID:00010P][0x0048a810-0x0048ae65.ClanWidItemDialog](by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md) 0x0048a810-0x0048ae65 | class methods | ClanWidItemDialog : reconstructable : 85% : very strong : Direct IDA refresh reconfirms withdraw item dialog constructor/reset/action/send ranges, two constructor callers, vtable-only action/send anchors, ClanItemListPane dependency, opcode 0x4b subtype 12 packet bytes, pointer-hit scan limited to vtable entries, unique range signature, DLGCLAN3.EPF byte-backed resource evidence, saved IDA comments, ClanBank owner/emitter route, and final C++ blank pending field/control/virtual names plus shared slide-helper placement.
```
- Replace existing [UID:00010R] row with:
```text
    - [UID:00010R][0x0048b1c0-0x0048b7dc.ClanBankPane](by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md) 0x0048b1c0-0x0048b7dc | class methods | ClanBankPane : reconstructable : 85% : very strong : Direct IDA refresh reconfirms ClanBankPane constructor/reset/action ranges, constructor callers, singleton writes/clears/reads for g_pClanBankPane, vtable-only action dispatch, CLANBAN resource/format xrefs, child ClanBankItemListPane construction, close/submit opcode 0x36 packet flow, raw bank helper non-function/no-pointer status, unique range signature, saved IDA comments, ClanBank owner/emitter route, and final C++ blank pending widget/member names, raw helper callability, and shared slide-helper placement.
```
- Replace existing [UID:00010S] row with:
```text
    - [UID:00010S][0x0048b8c0-0x0048c251.ClanBankItemListPane](by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md) 0x0048b8c0-0x0048c251 | class methods | ClanBankItemListPane : reconstructable : 85% : very strong : Direct IDA refresh reconfirms bank inventory list constructor/parser and draw ranges, sole constructor caller from ClanBankPane, vtable-only draw anchor, destructor support refs, packet cases 10/15/16, sorting/rebuild behavior, %s (%d) row text and ellipsis fitting, pointer-hit scan limited to vtable/destructor entries, unique range signature, saved IDA comments, ClanBank owner/emitter route, and final C++ blank pending entry-field/local/virtual names plus helper declaration placement.
```

## 2026-06-16 Supervisor Integration - C001-goal2-direct-ida-clanbank-pane-family-refresh-20260616-34

- Supervisor accepted the ClanBank pane-family direct-IDA batch after direct review. [UID:00010O], [UID:00010P], [UID:00010R], and [UID:00010S] all clear the gate at `85/90`; owner/emitter routing remains [UID:0000I9] `ClanBank`.
- C001 investigated the required source-quality blockers: helper/base/interface names, packet/callback behavior, constructors/destructors/vtable/layout evidence, raw helper reachability, saved safe comments, and final-C++ eligibility. Unsafe renames/prototypes/locals/types/raw function creation were correctly skipped.
- Supervisor applied the four exact shared `by-memory/-coverage-report.md` replacement rows and reran scoped validators for the shared report and the four target pages; all exited `0` with `ok:1`. No C001 supervisor-owned memory rows remain pending for this batch.

## 2026-06-16 Supervisor Integration - C001-goal2-item-ida-refresh-checkbox-popup-ail-tilec-20260616-29

- Supervisor accepted the batch as complete after C001 raised [UID:0000U7] `CheckBoxControlPaneStateTypeHelper` `85/89 -> 86/90`, [UID:0000V8] `PopupMenuSelectionCallback` `85/89 -> 86/90`, [UID:0000TU] `AILFileOpenCallback` `86/88 -> 87/91`, and [UID:0000U6] `BuildTilecArchiveTable` `86/88 -> 87/90`.
- Support scores were also accepted: [UID:00011S] `85/88 -> 86/89`, [UID:00011X] `85/89 -> 86/90`, [UID:0001IC] `85/88 -> 87/90`, and [UID:00017H] `85/90 -> 86/91`; [UID:00017H] remains non-emitting.
- C001 saved seven evidence-backed IDA labels; unsafe prototype/type/member/local/raw-function edits were skipped. Supervisor applied the exact [UID:00011S]/[UID:00011X]/[UID:00017H]/[UID:0001IC] `by-memory/-coverage-report.md` replacement rows and validated the four support memory pages plus the shared report (`ok:1`).

## 2026-06-16 Supervisor Integration - C001-goal2-item-ida-refresh-loadpcx-blend-alpha-20260616-30

- Supervisor accepted the batch as complete after C001 raised [UID:0000UZ] `LoadPcxImage` `86/88 -> 87/90`, [UID:0000TW] `AlphaBlendSpan16Blocks` `85/90 -> 86/91`, [UID:0000TZ] `BlendRgb555` `85/90 -> 86/91`, and [UID:0000U3] `BuildClippedAlphaSurfaceView` `85/90 -> 86/91`.
- Support scores were also accepted: [UID:000314] `86/88 -> 87/90`, [UID:0000YF] `84/90 -> 86/91`, and [UID:0000YL] `82/90 -> 85/91`; owner/emitter routes stayed unchanged.
- C001 saved four evidence-backed IDA labels, investigated helper/signature/source-placement blockers, and supervisor applied/validated the exact [UID:0000YF]/[UID:0000YL]/[UID:000314] `by-memory/-coverage-report.md` rows plus support pages (`ok:1`). No C001 supervisor-owned memory rows remain pending.

## 2026-06-16 Assignment - C001-goal2-direct-ida-app-blackhole-refresh-20260616-32

- Changed docs/scores: [UID:0002H8] `80/89 -> 86/91`; [UID:0002GJ] `80/90 -> 86/91`; [UID:0002GK] `80/90 -> 86/91`; [UID:0002M0] `80/90 -> 86/92`; [UID:0002M1] `80/90 -> 86/92`; support [UID:00000V] `BaramApp` child matrix refreshed, class score unchanged `86/90`.
- IDA DB changes saved in session `a002_goal65_20260616`: `sub_4F6490 -> ApplicationShutdown`, `sub_4669C0 -> BaramAppOnActivate`, `sub_466A70 -> BaramAppOnDeactivate`, `sub_4690B0 -> BlackHole_Constructor`, and `sub_469100 -> BlackHole_Destructor`; `idb_save ok:true` to `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Skipped unsafe IDA edits: prototypes, locals, stack declarations, data/global names, type/member/struct edits, raw function creation, and final C++ emission. Remaining source-quality blockers are BaramApp field/global/audio-tail names, BlackHole final List/singleton/source-shape names, and ApplicationShutdown indirect destructor/source declaration details.
- Validation: scoped `python .\tools\validator.py --mode file --file <target> --apply --queue-timeout 240` returned `ok: 1` for all six by-* edits. Target detail: [UID:0002H8] completion/confidence `86/91`; [UID:0002GJ] `86/91`; [UID:0002GK] `86/91`; [UID:0002M0] `86/92`; [UID:0002M1] `86/92`; `by-class/BaramApp.md` `ok: 1` with `stats_incremental_noop` because it is not in generated stats lists. The same validator rejected `tools/leaser/Agents/Agent-C001/notes.md` as outside direct by-* folders, so the notes file has no scoped validator.
- `by-memory/-coverage-report.md` was not edited by C001; exact supervisor-owned replacement rows are below.

Pending supervisor-owned `by-memory/-coverage-report.md` rows. Do not edit `by-memory/-coverage-report.md` directly. Placement context: replace existing [UID:0002GJ] row around current line 539, [UID:0002GK] around line 540, [UID:0002M0] around line 577, [UID:0002M1] around line 579, and [UID:0002H8] around line 2117, preserving indentation.

```text
        - [UID:0002GJ][0x004669c0-0x00466a69.BaramAppOnActivate](by-memory/0x004669c0-0x00466a69.BaramAppOnActivate.md) 0x004669c0-0x00466a69 | class method | BaramAppOnActivate : reconstructable : 86% : very strong : Parent-attached activation handler with saved `BaramAppOnActivate` IDA label, exact `0xa9` range, virtual-only data refs `0x006125f8`/`0x0061d12c`, transition guard, event/timer resume, map-pane `ShowWindow(..., 9)` path, background/key helper, contiguous callee set, `0x00466a62 -> 0x0057a480` audio-tail caveat, BaramApp owner/emitter route, and blank final C++ pending field/global/audio-tail source-quality blockers.
        - [UID:0002GK][0x00466a70-0x00466b23.BaramAppOnDeactivate](by-memory/0x00466a70-0x00466b23.BaramAppOnDeactivate.md) 0x00466a70-0x00466b23 | class method | BaramAppOnDeactivate : reconstructable : 86% : very strong : Parent-attached deactivation handler with saved `BaramAppOnDeactivate` IDA label, exact `0xb3` range, virtual-only data refs `0x006125fc`/`0x0061d130`, transition guard, active-byte clear, map-pane `ShowWindow(..., 6)` path, event/background/input pause, parcel-walk cleanup, contiguous callee set, `0x00466b1c -> 0x0057a450` audio-tail caveat, BaramApp owner/emitter route, and blank final C++ pending field/global/audio-tail source-quality blockers.
        - [UID:0002M0][0x004690b0-0x004690f6.BlackHoleConstructor](by-memory/0x004690b0-0x004690f6.BlackHoleConstructor.md) 0x004690b0-0x004690f6 | constructor | BlackHoleConstructor : reconstructable : 86% : very strong : BlackHole constructor with saved `BlackHole_Constructor` IDA label, exact `0x46` range, Application initialization caller `0x00464549`, inherited `List(4, 1024)` setup through `sub_4F3060`, `dword_67A74C` singleton writes, BlackHole vtable stores at `0x00613118`, adjacent `0xcc` padding, BlackHole class/file/vtable/layout support, parent attachment, and blank final C++ pending final List API, singleton accessor, and constructor-unwind source shape.
        - [UID:0002M1][0x00469100-0x00469115.BlackHoleDestructor](by-memory/0x00469100-0x00469115.BlackHoleDestructor.md) 0x00469100-0x00469115 | destructor | BlackHoleDestructor : reconstructable : 86% : very strong : BlackHole non-deleting destructor with saved `BlackHole_Destructor` IDA label, exact `0x15` range, no direct callers, vtable restore, `dword_67A74C` singleton clear, tail call to shared [UID:000192][0x004f30e0-0x004f3139.ListNonDeletingDestructor](by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md), adjacent `0xcc` padding, BlackHole class/file/vtable/layout support, parent attachment, and blank final C++ pending final List destructor declaration/source split and singleton accessor style.
        - [UID:0002H8][0x004f6490-0x004f66a5.ApplicationShutdown](by-memory/0x004f6490-0x004f66a5.ApplicationShutdown.md) 0x004f6490-0x004f66a5 | class method | ApplicationShutdown : reconstructable : 86% : very strong : Exact second-stage shutdown method with saved `ApplicationShutdown` IDA label, live IDA-confirmed bounds/caller/vtable slot, phase-4 write, event/IME teardown, six main-UI slot detach/destroy order, image-library singleton teardown, UID-linked IdleWatcher/TextFilter/MetaMan cleanup, resolved [UID:0001P0][g_packetSender](by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md) / Socket shutdown ownership at `0x004f6662-0x004f667b`, CleanupResources tail call, and blank final C++ pending indirect destructor/source-declaration blockers.
```

## 2026-06-16 Assignment - C001-goal2-item-ida-refresh-mainui-frame-effect-pcx-20260616-31

- Assigned targets: [UID:0000UV] `by-item/InitializeMainUiGraph_004F7D10.md`; [UID:0000U2] `by-item/BuildAboveFrameBorder_00461310.md`; [UID:0000U4] `by-item/BuildEffectArchiveTable_004DE420.md`; [UID:0000U9] `by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md`.
- This is a bounded by-item safe IDA-refresh batch from refreshed `project-level/-auto-completion-stats.md`. `StartupWindowUnmodeledNoticeHelpers` remains skipped because its raw/no-xref source-shape issue is B-preferred.
- Refresh current IDA names, bounds, xrefs, decompilation/bytes, callers/callees, support file/memory/type pages, generated-output implications, and current owner/emitter route evidence. Apply only evidence-backed low-risk IDA labels/comments/type repairs; skip speculative prototypes, fields, locals, raw function creation, and source-facing names without proof.
- Investigate final source-quality blockers now: global/helper/source/header names, image/archive table ownership, PCX buffer type names, raw caller/source placement, generated-output omissions, and final-C++ eligibility. Record exact supervisor-owned `by-memory/-coverage-report.md` rows if support memory docs change.
- Execution status: queued/pending. Replacement worker `019ed0b4-f7ee-7cf1-9fba-62484da5d03d` failed immediately with revoked refresh-token authentication, so no C001 work has started for this assignment yet.

## 2026-06-16 - C001-goal2-item-ida-refresh-mainui-frame-effect-pcx-20260616-31 closeout

Changed docs and scores:
- `by-item/InitializeMainUiGraph_004F7D10.md`: `86/88 -> 87/89`; owner/emitter retained [UID:0000L1] `MainUiGraph`.
- `by-item/BuildAboveFrameBorder_00461310.md`: `85/90 -> 86/91`; owner/emitter retained [UID:0000JL] `FrameChrome`.
- `by-item/BuildEffectArchiveTable_004DE420.md`: `85/90 -> 86/91`; owner/emitter retained [UID:0000IY] `EffectObjImageLib`.
- `by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md`: `85/90 -> 86/91`; owner/emitter retained [UID:0000K3] `ImageLoaders`.
- `by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md`: `86/88 -> 87/89`; owner/emitter retained [UID:0000L1].
- `by-memory/0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer.md`: `86/88 -> 87/90`; owner/emitter retained [UID:0000K3].
- `by-memory/0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster.md`: `85/89 -> 86/90`; remains `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, no emitters.
- `by-item/-coverage-report.md`: synced rows for [UID:0000U2], [UID:0000U4], [UID:0000U9], and [UID:0000UV].

IDA changes:
- Saved four low-risk function labels after dry-run accepted all candidates: `InitializeMainUiGraph`, `BuildAboveFrameBorder`, `BuildEffectArchiveTable`, and `CreateDIBitmapFromPcxBuffer`.
- Save result: `idb_save ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`. Post-save `lookup_funcs` verified all four labels and sizes.
- Skipped unsafe edits: prototypes, local variables, stack declarations, global/field/member names, type declarations, exact by-memory promotion/splitting, raw function creation, and final reconstruction C++.

Source-quality investigation:
- Main UI bootstrap: current caller/decompile/callee review proves the entry label and owner route, but broad unresolved helper/type/global names still block source-quality C++.
- Frame chrome factory: current decompile proves the frame-border factory label and FrameChrome route; slot names, signature, and `dword_67A874 + 0x20` source meaning remain unproven.
- Effect archive table: current xrefs/decompile prove the effect archive-table label and EffectObjImageLib route; table type spelling, exact helper signature, and by-memory promotion remain unresolved.
- PCX-to-DIB factory: current decompile proves the entry label and ImageLoaders route; DIBitmap private fields, PCX decoder result type, and exact source signature remain unresolved.
- Prompt path mismatch: the requested by-class paths `FrameSkipController.md`, `EffectTable.md`, `PcxHeader.md`, and `MainUI.md` do not exist; the supplied UIDs resolve to the four by-item pages above, so C001 worked the UID-resolved pages and direct support docs.

Validation status:
- `python .\tools\validator.py --mode file --file <changed-by-star-file> --apply --queue-timeout 240` returned `ok: 1` for `by-item/InitializeMainUiGraph_004F7D10.md`, `by-item/BuildAboveFrameBorder_00461310.md`, `by-item/BuildEffectArchiveTable_004DE420.md`, `by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md`, `by-item/-coverage-report.md`, `by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md`, `by-memory/0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer.md`, and `by-memory/0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster.md`.

Supervisor-owned `by-memory/-coverage-report.md` rows:
- Do not edit `by-memory/-coverage-report.md` directly. Placement context: replace existing [UID:000315] row around current line 1289, [UID:00017K] row around current line 1813, and [UID:00019K] row around current line 2124, preserving indentation.
- Replace existing [UID:000315] row with:
```text
        - [UID:000315][0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer](by-memory/0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer.md) : reconstructable : 87% : very strong : Exact PCX-to-DIB factory child with saved `CreateDIBitmapFromPcxBuffer` IDA label, one `LoadPcxImage` caller, PCX decoder call at `0x00549410`, decode/dimension/null-buffer failure checks, 60-byte DIBitmap allocation, 16-bit top-down DIB-section setup, clipped row-copy loop, decoded-buffer cleanup, direct parent [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md), and final C++ blank pending source signature, DIBitmap fields, and PCX decoder output type.
```
- Replace existing [UID:00017K] row with:
```text
    - [UID:00017K][0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster](by-memory/0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster.md) 0x004ddf60-0x004dec30 | class-method-cluster | EffectObjImageLibLocalMethodCluster : ignored/non-emitting : 86% : very strong : Non-emitting contiguous EffectObjImageLib local cluster with corrected exact-child inventory, saved `BuildEffectArchiveTable` IDA label for [UID:0000U4], constructor/destructor/render/query/helper/loader source children tracked separately, old broad-range crossing of ItemObjImageLib/LightObjImageLib/NewHumanImageLib/scalar-destructor neighborhoods resolved, and no final C++ because this page is an index rather than a source body.
```
- Replace existing [UID:00019K] row with:
```text
    - [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) : reconstructable : 87% : very strong : Exact MainUiGraph bootstrap range with saved `InitializeMainUiGraph` IDA label, `0xe1b` size, padding before start and before successor `0x004f8b30`, sole login-success caller `0x004fac9b`, caller handoff through `g_pMainUiGraph`, new/old layout branch callee families, layer-slot refs, common profile/BlackHole/input/timer/ready tail, owner/emitter route through [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md), and final C++ blocked on graph layout plus source-quality callee/type/global names.
```

## 2026-06-15 Agent-C001 Goal 2 BlackHole/Browser/Alert Memory C001-goal2-blackhole-browser-alert-memory-20260615-5

- Changed docs: [UID:0002M3][0x00469120-0x00469171.BlackHoleEnqueueIfMissing](../../../../by-memory/0x00469120-0x00469171.BlackHoleEnqueueIfMissing.md), [UID:00020W][0x0046a760-0x0046a855.BrowserRawWindowProcClone](../../../../by-memory/0x0046a760-0x0046a855.BrowserRawWindowProcClone.md), [UID:0002SE][0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest](../../../../by-memory/0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest.md), [UID:0002SF][0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest](../../../../by-memory/0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest.md), support [UID:00000W][BlackHole](../../../../by-class/BlackHole.md), [by-class/-coverage-report.md](../../../../by-class/-coverage-report.md), validator-owned generated files, and this notes file.
- Score/routing changes: [UID:0002M3] `80/88 -> 85/90`; [UID:00020W] `80/88 -> 85/90`; [UID:0002SE] `80/88 -> 85/90`; [UID:0002SF] `80/88 -> 85/90`; support [UID:00000W] `84/92 -> 85/92`. Owner/emitter routes remain unchanged: [UID:0002M3] through [UID:00000W], [UID:00020W] through [UID:0000HV], [UID:0002SE] through [UID:000033], and [UID:0002SF] through [UID:000034]. Final C++ remains blank for all four memory targets.
- Evidence summary: Wave2 method-analysis reported `BlackHole::EnqueueIfMissing(void*)` grade `96.5`, no Wave2 method/global for raw `0x0046a760`, and `ConfirmDeleteAlert::SendDeleteRequest()` / `ConfirmDeleteMailAlert::SendDeleteRequest()` grade `100`. Live IDA MCP session `a003_objectlist_dispatch_20260615` reconfirmed exact bounds, xrefs, callees, byte/padding boundaries, raw Browser clone no-function/no-xref/no-pointer status, registered Browser sibling `0x0046a630` constructor pointer evidence, alert vtable refs `0x006145dc`/`0x00614724`, and delete packet opcode/subopcode `0x3b/0x05` flows.
- IDA DB changes: none. Skipped candidates: no names, comments, prototypes, function creation for the raw Browser clone, vtable edits, type/member edits, or IDB save were applied because the evidence supports documentation/routing scores but not a necessary low-risk database mutation. Browser clone function creation was explicitly skipped because current xref/pointer evidence proves only retained raw bytes, not live registration.
- Validation: scoped validator loop `python .\tools\validator.py --mode file --file <target> --apply --lock-timeout 60` exited `0` for [UID:00000W], [UID:0002M3], [UID:00020W], [UID:0002SE], and [UID:0002SF]; each run reached `ok: 1`. `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --lock-timeout 60` exited `0` with `ok: 1`.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows retained for audit

Supervisor applied and validated the four replacement rows below on 2026-06-15 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No C001 BlackHole/Browser/Alert supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

Placement context: replaced these four existing child rows in place. Under [UID:0000Z0], replaced [UID:0002M3]. Under [UID:0001Z5], replaced [UID:00020W] in place. Under [UID:0000ZM], replaced [UID:0002SE] and [UID:0002SF] in place.

```text
        - [UID:0002M3][0x00469120-0x00469171.BlackHoleEnqueueIfMissing](by-memory/0x00469120-0x00469171.BlackHoleEnqueueIfMissing.md) 0x00469120-0x00469171 | class method | BlackHoleEnqueueIfMissing : reconstructable : 85% : strong : C001 Wave2/live IDA refresh confirms exact BlackHole EnqueueIfMissing bounds, effective signature `void BlackHole::EnqueueIfMissing(void*)`, caller `0x0053a0bc`, null guard, inherited List count scan, virtual lookup slot `+0x10`, duplicate suppression, append through slot `+0x18`, no direct static callees, adjacent `0xcc` padding, direct owner [UID:00000W][BlackHole](by-class/BlackHole.md) now gate-valid at `85/92`, and final C++ remains blank pending source-quality List API/object-pointer names.
    - [UID:00020W][0x0046a760-0x0046a855.BrowserRawWindowProcClone](by-memory/0x0046a760-0x0046a855.BrowserRawWindowProcClone.md) 0x0046a760-0x0046a855 | retained raw WndProc clone | BrowserRawWindowProcClone : reconstructable : 85% : strong : C001 Wave2/live IDA refresh confirms no Wave2 method/global, no function record, no xrefs/pointer hits at `0x0046a760`, registered sibling `0x0046a630` constructor xref/pointer hit at `0x00469758/0x0046975e`, complete raw WndProc-shaped body, local jump table targets `0x0046a7d9`/`0x0046a7a6`, 97-byte selector table with zero commands `0xf000`/`0xf100`/`0xf200`/`0xf300`/`0xf600`, `0x0046a855-0x0046a860` `0xcc` alignment, Browser parent, and final C++ remains blank because live registration/original retention path is still unproven.
      - [UID:0002SE][0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest](by-memory/0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest.md) 0x0047e160-0x0047e2e4 | virtual alert action | ConfirmDeleteAlertSendDeleteRequest : reconstructable : 85% : strong : C001 Wave2/live IDA refresh confirms `ConfirmDeleteAlert::SendDeleteRequest()` grade `100`, exact function bounds, vtable xref `0x006145dc`, callees `sub_4F3E80`/`sub_4F3DC0`/packet writers/sender/queue helper, board/article single and multi-delete packet paths with opcode `0x3b` and subcommand `0x05`, player-context update, successor padding, owner/emitter route through [UID:000033][ConfirmDeleteAlert](by-class/ConfirmDeleteAlert.md), and final C++ remains blank pending source-quality context/list field names and helper prototypes.
      - [UID:0002SF][0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest](by-memory/0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest.md) 0x0047e510-0x0047e694 | virtual alert action | ConfirmDeleteMailAlertSendDeleteRequest : reconstructable : 85% : strong : C001 Wave2/live IDA refresh confirms `ConfirmDeleteMailAlert::SendDeleteRequest()` grade `100`, exact function bounds, vtable xref `0x00614724`, callees `sub_4F3E80`/`sub_4F3DC0`/packet writers/sender/queue helper, mail single and multi-delete packet paths with opcode `0x3b` and subcommand `0x05`, player mail-context update, successor padding, owner/emitter route through [UID:000034][ConfirmDeleteMailAlert](by-class/ConfirmDeleteMailAlert.md), and final C++ remains blank pending source-quality context/list field names and helper prototypes.
```

## 2026-06-15 Agent-C001 Goal 2 Section Container Follow-up C001-goal2-section-container-followup-20260615-1 Clan Raw-Constructor Slice

Placement context: replace the top-level [UID:0001Z5] row. Under [UID:0001Z5], replace the existing [UID:00021V], [UID:0002NT], [UID:0002NV], and [UID:0002NZ] raw-constructor child rows in place. Do not edit `by-memory/-coverage-report.md` directly.

- Changed docs: [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](../../../../by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md), [UID:0002NT][0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor](../../../../by-memory/0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor.md), [UID:0002NV][0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor](../../../../by-memory/0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor.md), [UID:0002NZ][0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor](../../../../by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md), [UID:0001Z5][0x00401000-0x0060d000.MasterCodeTextSection](../../../../by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md), validator-owned generated files, and this notes file.
- Score changes: [UID:00021V] `80/88 -> 85/90`; [UID:0002NT] `80/88 -> 85/90`; [UID:0002NV] `80/88 -> 85/90`; [UID:0002NZ] `80/88 -> 85/90`; [UID:0001Z5] `84/89 -> 85/89`. [UID:0001Z7] was not edited in this slice and remains at the last accepted `83/90`; this pass stayed on the `.text` raw-constructor queue because no fresh low-risk `.rdata` C-agent DB mutation was identified during the available evidence window.
- Owner/emitter decisions: raw-constructor owner/emitter routes now use canonical owner/emitter metadata through [UID:00002A][ClanDepMoneyInputDialog](../../../../by-class/ClanDepMoneyInputDialog.md), [UID:00002O][ClanWidMoneyInputDialog](../../../../by-class/ClanWidMoneyInputDialog.md), [UID:00002D][ClanExpelNameInputDialog](../../../../by-class/ClanExpelNameInputDialog.md), and [UID:000023][ClanAppearNameInputDialog](../../../../by-class/ClanAppearNameInputDialog.md). Final C++ remains blank on all four raw-constructor pages because true raw-constructor reachability is still unproven.
- Section-container decision: [UID:0001Z5] remains `CANONICAL_OWNER:NONE`, blank emitters, and `RECONSTRUCTABLE:FALSE`. The score now reaches the minimum map gate only; no section-container ownership, section-level source file, or section-level final C++ was forced.
- Evidence summary: fresh live IDA MCP session `c001_clan_raw_ctor_20260615` opened `NexusTK.exe.i64`, image base `0x00400000`, Hex-Rays ready, strings cache ready. `lookup_funcs`, `xrefs_to`, `find_bytes`, `disasm`, and `get_bytes` reconfirmed no function objects at the four raw constructor starts/ends, no start xrefs, zero little-endian pointer-byte matches for all four starts, exact base-constructor calls at `0x00488fad`/`0x0048907d`/`0x0048914d`/`0x004893ad`, derived vtable stores, `retn 4` boundaries, and eleven-byte padding runs before the adjacent submitters. This MCP build did not expose the older `search` tool, so the fresh pass does not add new immediate/data-reference claims beyond the earlier documented 2026-06-05 results.
- IDA DB changes: applied four low-risk function renames on adjacent modeled submitters and saved the IDB: `sub_488FE0 -> ClanDepMoneyInputDialog_SubmitDepositMoney`, `sub_4890B0 -> ClanWidMoneyInputDialog_SubmitWithdrawMoney`, `sub_489180 -> ClanExpelNameInputDialog_SubmitName`, and `sub_4893E0 -> ClanAppearNameInputDialog_SubmitName`.
- Skipped IDA candidates: no raw constructor function creation, prototypes, comments, type/member repairs, vtable edits, or global renames were applied. Creating functions at the raw constructor starts would improve display but overstate reachability because IDA still has no function objects, no start xrefs, and no pointer-byte matches for the starts.
- Source-quality/B-agent handoff: a future B-agent pass should decide, using broader source/build heuristics, whether these unreferenced constructor-shaped raw fragments are retained historical constructors, dead COMDAT-like leftovers, or should be excluded from final source beyond the current blank-C++ no-reachability rationale. C001 did not infer that ownership from the section container.
- BlackHole/Browser/Alert priority note: this pass did not touch the recently completed BlackHole/Browser/Alert batch, so no listed source-quality blockers from that batch were deferred by edits here.
- Validation: scoped validator runs exited `0` and reached `ok: 1` for [UID:00021V], [UID:0002NT], [UID:0002NV], [UID:0002NZ], and [UID:0001Z5]. The four child runs removed those UIDs from `Low_Completion` stats; the [UID:0001Z5] run updated completion to `85` and added reference-index entries for the four refreshed children.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows retained for audit

Supervisor applied and validated the five replacement rows below on 2026-06-15 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No C001 clan raw-constructor supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

```text
- [UID:0001Z5][0x00401000-0x0060d000.MasterCodeTextSection](by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md) 0x00401000-0x0060d000 | section-container | MasterCodeTextSection : ignored : 85% : strong : IDA `.text` executable segment container, not a standalone source object; current report has 1781 immediate children, 817 nested children, no immediate/nested unknown rows, current endpoint/name inventory, and C001 2026-06-15 child follow-ups raising JsonCpp number-token helper, WideApi dispatch initializer, zlib source-provenance family, libjpeg static-library child pages, fitting-room progress/action helpers, CashShop/FileDownloader scalar deleting destructor wrappers, FileDownloader constructor/destructor/message dispatcher pages, FileDownloader submit-helper pages, late static runtime cleanup-wrapper island, and clan raw-constructor child pages while other broad child/source-neighborhood audits remain below final source quality.
    - [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md) 0x00488fa0-0x00488fd5 | raw constructor | ClanDepMoneyInputDialogRawConstructor : reconstructable : 85% : strong : C001 live IDA refresh reconfirmed no function object, no start xrefs, zero little-endian pointer-byte matches for `0x00488fa0`, base-constructor call at `0x00488fad`, three `ClanDepMoneyInputDialog` vtable stores at `0x00488fb2`/`0x00488fba`/`0x00488fc4`, eleven-byte padding before the adjacent submitter, owner/emitter route through [UID:00002A][ClanDepMoneyInputDialog](by-class/ClanDepMoneyInputDialog.md), IDA rename of the adjacent submitter to `ClanDepMoneyInputDialog_SubmitDepositMoney`, and blank final C++ pending true raw-constructor reachability.
        - [UID:0002NT][0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor](by-memory/0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor.md) 0x00489070-0x004890a5 | raw constructor | ClanWidMoneyInputDialogRawConstructor : reconstructable : 85% : strong : C001 live IDA refresh reconfirmed no function object, no start xrefs, zero little-endian pointer-byte matches for `0x00489070`, base-constructor call at `0x0048907d`, three `ClanWidMoneyInputDialog` vtable stores at `0x00489082`/`0x0048908a`/`0x00489094`, eleven-byte padding before the adjacent submitter, owner/emitter route through [UID:00002O][ClanWidMoneyInputDialog](by-class/ClanWidMoneyInputDialog.md), IDA rename of the adjacent submitter to `ClanWidMoneyInputDialog_SubmitWithdrawMoney`, and blank final C++ pending true raw-constructor reachability.
        - [UID:0002NV][0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor](by-memory/0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor.md) 0x00489140-0x00489175 | raw constructor | ClanExpelNameInputDialogRawConstructor : reconstructable : 85% : strong : C001 live IDA refresh reconfirmed no function object, no start xrefs, zero little-endian pointer-byte matches for `0x00489140`, base-constructor call at `0x0048914d`, three `ClanExpelNameInputDialog` vtable stores at `0x00489152`/`0x0048915a`/`0x00489164`, eleven-byte padding before the adjacent submitter, owner/emitter route through [UID:00002D][ClanExpelNameInputDialog](by-class/ClanExpelNameInputDialog.md), IDA rename of the adjacent submitter to `ClanExpelNameInputDialog_SubmitName`, and blank final C++ pending true raw-constructor reachability.
        - [UID:0002NZ][0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor](by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md) 0x004893a0-0x004893d5 | raw constructor | ClanAppearNameInputDialogRawConstructor : reconstructable : 85% : strong : C001 live IDA refresh reconfirmed no function object, no start xrefs, zero little-endian pointer-byte matches for `0x004893a0`, base-constructor call at `0x004893ad`, three `ClanAppearNameInputDialog` vtable stores at `0x004893b2`/`0x004893ba`/`0x004893c4`, eleven-byte padding before the adjacent submitter, owner/emitter route through [UID:000023][ClanAppearNameInputDialog](by-class/ClanAppearNameInputDialog.md), IDA rename of the adjacent submitter to `ClanAppearNameInputDialog_SubmitName`, and blank final C++ pending true raw-constructor reachability.
```

## 2026-06-15 Agent-C001 Goal 2 MSVC Runtime RData Tail Memory C001-goal2-msvc-runtime-rdata-tail-memory-20260615-3

- Changed docs: new [UID:0003P7][0x00633050-0x00633080.ZlibInflateVersionString](../../../../by-memory/0x00633050-0x00633080.ZlibInflateVersionString.md), [UID:000273][0x00632560-0x0066d000.MsvcRuntimeReadOnlyDataTail](../../../../by-memory/0x00632560-0x0066d000.MsvcRuntimeReadOnlyDataTail.md), [UID:0001Z7][0x0060d670-0x0066d000.ReadOnlyDataSection](../../../../by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md), validator-owned generated files, and this notes file.
- Score/routing changes: [UID:0003P7] created at `86/90`, owner/emitter [UID:0000PC][Zlib](../../../../by-file/Zlib.md), `RECONSTRUCTABLE:TRUE`, blank final C++; [UID:000273] `80/85 -> 85/90`, still `CANONICAL_OWNER:NONE`, blank emitters, `RECONSTRUCTABLE:FALSE`; [UID:0001Z7] `81/90 -> 82/90`, still ignored/non-emitting section container.
- Evidence summary: live IDA MCP session `a003_objectlist_dispatch_20260615` reported active `NexusTK.exe.i64`, image base `0x00400000`, Hex-Rays ready, and strings cache ready. Bounded tail inventory found 4299 named heads and 777 strings across runtime metadata, STL/CRT exception and locale data, API/system-error strings, 2896 RTTI records, EH/import descriptors, import-name strings, and zero-tail sampling. Live bytes at `0x00633040+0x60` proved exact `0x00633050-0x00633080` boundaries for the zlib inflate copyright/version literal, and local staged `by-meta/obtained_thirdparty_files/static_embeds/zlib-1.1.4/inftrees.c` provides source provenance.
- Owner/emitter decisions: [UID:0003P7] routes through zlib because the literal is source-backed third-party static data. [UID:000273] remains a non-emitting compiler/runtime/linker/import tail; no broad section-container ownership was forced. [UID:0001Z7] remains a section index below the final gate.
- IDA DB changes: none. Skipped candidates: no names, comments, prototypes, data retyping, import-table edits, RTTI/EH typing, or IDB save were applied because the evidence supports documentation/split routing only.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x00633050-0x00633080.ZlibInflateVersionString.md --apply --lock-timeout 60` exited `0` with `ok: 1` after assigning [UID:0003P7]. `python .\tools\validator.py --mode file --file by-memory\0x00632560-0x0066d000.MsvcRuntimeReadOnlyDataTail.md --apply --lock-timeout 60` exited `0` with `ok: 1` and removed [UID:000273] from low-completion generated stats. `python .\tools\validator.py --mode file --file by-memory\0x0060d670-0x0066d000.ReadOnlyDataSection.md --apply --lock-timeout 60` exited `0` with `ok: 1`.
- Lease notes: target [UID:000273], support [UID:0001Z7], new child [UID:0003P7] after creation, and this notes file were leased by Agent-C001. Pre-create lease for the new child path was rejected by leaser because the file did not exist yet.

### Supervisor-applied `by-memory/-coverage-report.md` rows retained for audit

Placement context: replace the top-level [UID:0001Z7] row in place. Under [UID:0001Z7], replace [UID:000273] in place and insert [UID:0003P7] immediately under [UID:000273] in address order.

```text
- [UID:0001Z7][0x0060d670-0x0066d000.ReadOnlyDataSection](by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md) 0x0060d670-0x0066d000 | section-container | ReadOnlyDataSection : ignored : 82% : strong : IDA `.rdata` section container, not a standalone source object; current report has 98 immediate children, 95+ nested children after C001 exact child splits, no immediate unknown/uncovered rows, current bounded IDA name/string inventory, and C001 2026-06-15 child follow-ups splitting AboveFrame/locale tails, employee alert text, the BaramApp/MainMenu boundary, two MSVC STL runtime-data children, and the MSVC runtime-tail zlib inflate-string child while many broad vtable/string/runtime rows still require child-level audits.
    - [UID:000273][0x00632560-0x0066d000.MsvcRuntimeReadOnlyDataTail](by-memory/0x00632560-0x0066d000.MsvcRuntimeReadOnlyDataTail.md) 0x00632560-0x0066d000 | runtime/compiler-data | MsvcRuntimeReadOnlyDataTail : ignored : 85% : strong : Broad `.rdata` compiler/runtime/linker/import tail; C001 live IDA refresh inventoried 4299 names and 777 strings across runtime function metadata, STL/CRT exception/locale/system-error/API-set/math tables, 2896 RTTI records, EH/import descriptors, import-name strings, and zero-tail sampling; exact zlib `inflate_copyright` child split at `0x00633050-0x00633080` while the parent remains ignored/non-emitting compiler/runtime/linker data.
        - [UID:0003P7][0x00633050-0x00633080.ZlibInflateVersionString](by-memory/0x00633050-0x00633080.ZlibInflateVersionString.md) 0x00633050-0x00633080 | third-party rdata | ZlibInflateVersionString : reconstructable : 86% : strong : Exact zlib 1.1.4 inflate copyright/version literal from `inftrees.c`; live IDA bytes/string and staged zlib source match the literal at `0x00633050`, no direct xrefs/data-flow in current IDB, and owner/emitter route is [UID:0000PC][Zlib](by-file/Zlib.md).
```

## 2026-06-15 Agent-C001 Goal 2 FieldMap/Message `.rdata` Memory Batch C001-goal2-fieldmap-message-rdata-memory-20260615-4

### Supervisor-applied `by-memory/-coverage-report.md` replacement/insert rows retained for audit

Placement context: replace the top-level [UID:0001Z7] row in place. Under [UID:0001Z7], replace the existing [UID:00025B] and [UID:00025V] rows in place. Insert the [UID:0003P8]-[UID:0003PA] child rows immediately below [UID:00025B]. Insert the [UID:0003PB]-[UID:0003PF] child rows immediately below [UID:00025V]. Do not change unrelated rows.

- Changed docs: [UID:00025B][0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData](../../../../by-memory/0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData.md), [UID:00025V][0x0061fa3c-0x0061fafc.MessageShowReadOnlyData](../../../../by-memory/0x0061fa3c-0x0061fafc.MessageShowReadOnlyData.md), [UID:0001Z7][0x0060d670-0x0066d000.ReadOnlyDataSection](../../../../by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md), new child docs [UID:0003P8]-[UID:0003PF], validator-owned generated files, and this notes file.
- Score changes: [UID:00025B] `80/86 -> 86/91`; [UID:00025V] `80/86 -> 86/90`; [UID:0001Z7] `82/90 -> 83/90`. New children: [UID:0003P8] `86/91`, [UID:0003P9] `85/90`, [UID:0003PA] `86/91`, [UID:0003PB] `86/90`, [UID:0003PC] `86/90`, [UID:0003PD] `86/90`, [UID:0003PE] `86/90`, [UID:0003PF] `84/90`.
- Owner/emitter decisions: [UID:00025B] and [UID:00025V] are now non-emitting mixed maps with `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and blank emitters. [UID:0003P8] routes through [UID:00004U][FieldMapPane](../../../../by-class/FieldMapPane.md); [UID:0003PA] routes through [UID:000059][FolderSelectDialog](../../../../by-class/FolderSelectDialog.md); [UID:0003PB] routes through [UID:000084][Message](../../../../by-class/Message.md); [UID:0003PC] routes through [UID:000087][MessageShowPane](../../../../by-class/MessageShowPane.md); [UID:0003PD] routes through [UID:0000LC][MetaMan](../../../../by-file/MetaMan.md); [UID:0003PE] routes through [UID:000089][MetaTable](../../../../by-class/MetaTable.md). [UID:0003P9] remains ownerless because `.EPF` has multiple consumers. [UID:0003PF] remains ownerless because [UID:00008A][MidiPlayer](../../../../by-class/MidiPlayer.md) is still below the strict 85 completion gate.
- Evidence summary: live IDA MCP session `a003_objectlist_dispatch_20260615` reported active `NexusTK.exe`, image base `0x00400000`, Hex-Rays ready, and strings cache ready. `entity_query`, `get_bytes`, `get_string`, `lookup_funcs`, and `xrefs_to` proved exact FieldMapPane vtable, shared `.EPF` suffix, FolderSelectDialog COL pointer, Message vtable, MessageShowPane vtables, `Meta.dat` literal, MetaTable vtable cells, and MidiPlayer COL pointer boundaries and consumers.
- IDA DB changes: none. Skipped candidates: no names, comments, prototypes, type/member edits, string retyping, data retyping, vtable edits, or IDB save were applied because the live evidence supports documentation splits/routes but not a necessary low-risk database mutation.
- Validation: scoped validator loop `python .\tools\validator.py --mode file --file <child> --apply --lock-timeout 60` exited `0` and reached `ok: 1` for [UID:0003P8], [UID:0003P9], [UID:0003PA], [UID:0003PB], [UID:0003PC], [UID:0003PD], [UID:0003PE], and [UID:0003PF]. Scoped validator loop `python .\tools\validator.py --mode file --file <target> --apply --lock-timeout 60` exited `0` and reached `ok: 1` for [UID:00025B], [UID:00025V], and [UID:0001Z7].

Applied exact rows:

```text
- [UID:0001Z7][0x0060d670-0x0066d000.ReadOnlyDataSection](by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md) 0x0060d670-0x0066d000 | section-container | ReadOnlyDataSection : ignored : 83% : strong : IDA `.rdata` section container, not a standalone source object; current report has 98 immediate children, 95+ nested children before this pending batch, no immediate unknown/uncovered rows, current endpoint/name inventory, and C001 2026-06-15 child follow-ups splitting runtime/locale tails, employee alert text, BaramApp/MainMenu boundaries, runtime-tail/zlib data, and the FieldMapPane/FolderSelect plus Message/MessageShow/Meta/MidiPlayer mixed `.rdata` boundary rows while other broad vtable/string/type audits remain below final quality.
    - [UID:00025B][0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData](by-memory/0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData.md) 0x0061a3c4-0x0061a45c | mixed-rdata index | FieldMapPaneReadOnlyData : ignored : 86% : very strong : C001 live IDA refresh reclassified this historical FieldMapPane-owned aggregate as a non-emitting mixed map: exact child [UID:0003P8][0x0061a3c4-0x0061a44c.FieldMapPaneVtableData](by-memory/0x0061a3c4-0x0061a44c.FieldMapPaneVtableData.md) carries FieldMapPane vtable ownership, [UID:0003P9][0x0061a44c-0x0061a458.SharedEpfSuffixString](by-memory/0x0061a44c-0x0061a458.SharedEpfSuffixString.md) carries the shared `.EPF` suffix literal without a canonical owner, and [UID:0003PA][0x0061a458-0x0061a45c.FolderSelectDialogRttiLocatorPointer](by-memory/0x0061a458-0x0061a45c.FolderSelectDialogRttiLocatorPointer.md) carries the FolderSelectDialog primary COL pointer before successor vtable [UID:00025C][0x0061a45c-0x0061a5c4.FolderSelectTreeReadOnlyData](by-memory/0x0061a45c-0x0061a5c4.FolderSelectTreeReadOnlyData.md).
        - [UID:0003P8][0x0061a3c4-0x0061a44c.FieldMapPaneVtableData](by-memory/0x0061a3c4-0x0061a44c.FieldMapPaneVtableData.md) 0x0061a3c4-0x0061a44c | vtable-data | FieldMapPaneVtableData : reconstructable : 86% : very strong : Exact FieldMapPane COL/primary/secondary/tertiary vtable child; live IDA names, raw bytes, constructor-store xrefs, and slot values prove the range and owner/emitter route through [UID:00004U][FieldMapPane](by-class/FieldMapPane.md).
        - [UID:0003P9][0x0061a44c-0x0061a458.SharedEpfSuffixString](by-memory/0x0061a44c-0x0061a458.SharedEpfSuffixString.md) 0x0061a44c-0x0061a458 | string-data | SharedEpfSuffixString : reconstructable : 85% : strong : Exact UTF-16 `.EPF` suffix literal child; live bytes and `xrefs_to 0x0061a44c` prove consumers at `0x004b0c12`, `0x00510b2f`, `0x00511019`, and `0x005c2df4`, so the literal is reconstructable but remains without a canonical owner/emitter pending a focused shared-literal placement audit.
        - [UID:0003PA][0x0061a458-0x0061a45c.FolderSelectDialogRttiLocatorPointer](by-memory/0x0061a458-0x0061a45c.FolderSelectDialogRttiLocatorPointer.md) 0x0061a458-0x0061a45c | RTTI locator pointer | FolderSelectDialogRttiLocatorPointer : reconstructable : 86% : very strong : Exact FolderSelectDialog primary `vftable[-1]` COL pointer; live bytes show `0x0061a458 -> 0x0064780c`, the RTTI target is named `??_R4FolderSelectDialog@@6B@`, and successor vtable refs prove owner/emitter route through [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md).
    - [UID:00025V][0x0061fa3c-0x0061fafc.MessageShowReadOnlyData](by-memory/0x0061fa3c-0x0061fafc.MessageShowReadOnlyData.md) 0x0061fa3c-0x0061fafc | mixed-rdata index | MessageShowReadOnlyData : ignored : 86% : strong : C001 live IDA refresh reclassified this historical MessageShowPane-owned aggregate as a non-emitting mixed map: exact children carry Message vtable, MessageShowPane vtable, MetaMan `Meta.dat` literal, MetaTable vtable, and MidiPlayer COL-pointer evidence, with the final MidiPlayer child left ownerless until the direct MidiPlayer class clears the strict completion gate.
        - [UID:0003PB][0x0061fa3c-0x0061fa4c.MessageVtableData](by-memory/0x0061fa3c-0x0061fa4c.MessageVtableData.md) 0x0061fa3c-0x0061fa4c | vtable-data | MessageVtableData : reconstructable : 86% : strong : Exact Message primary vtable child; live IDA bytes and constructor/destructor/scalar-deleting-destructor xrefs at `0x00520e6a`, `0x00520ed6`, and `0x00521d49` prove the range and owner/emitter route through [UID:000084][Message](by-class/Message.md).
        - [UID:0003PC][0x0061fa4c-0x0061fadc.MessageShowPaneVtableData](by-memory/0x0061fa4c-0x0061fadc.MessageShowPaneVtableData.md) 0x0061fa4c-0x0061fadc | vtable-data | MessageShowPaneVtableData : reconstructable : 86% : strong : Exact MessageShowPane primary/secondary/tertiary vtable child; live IDA bytes and vtable-store xrefs at `0x00521e1d`, `0x00521e23`, `0x00521e2d`, `0x00521fe5`, `0x00521feb`, `0x00521ff5`, `0x0052274c`, `0x00522752`, and `0x0052275c` prove the range and owner/emitter route through [UID:000087][MessageShowPane](by-class/MessageShowPane.md).
        - [UID:0003PD][0x0061fadc-0x0061faf0.MetaDatFilenameString](by-memory/0x0061fadc-0x0061faf0.MetaDatFilenameString.md) 0x0061fadc-0x0061faf0 | string-data | MetaDatFilenameString : reconstructable : 86% : strong : Exact UTF-16 `Meta.dat` filename literal child; live bytes and MetaMan load/save xrefs at `0x005234ae` and `0x005237fa` prove owner/emitter route through [UID:0000LC][MetaMan](by-file/MetaMan.md).
        - [UID:0003PE][0x0061faf0-0x0061faf8.MetaTableVtableData](by-memory/0x0061faf0-0x0061faf8.MetaTableVtableData.md) 0x0061faf0-0x0061faf8 | vtable-data | MetaTableVtableData : reconstructable : 86% : strong : Exact MetaTable COL/vtable cells; live bytes show `0x0061faf0 -> 0x0064c2fc` and `0x0061faf4 -> 0x00525780`, RTTI inventory names `??_R4MetaTable@@6B@`, and lifecycle xrefs at `0x00524643`, `0x005246b9`, and `0x005257aa` prove owner/emitter route through [UID:000089][MetaTable](by-class/MetaTable.md).
        - [UID:0003PF][0x0061faf8-0x0061fafc.MidiPlayerRttiLocatorPointer](by-memory/0x0061faf8-0x0061fafc.MidiPlayerRttiLocatorPointer.md) 0x0061faf8-0x0061fafc | RTTI locator pointer | MidiPlayerRttiLocatorPointer : reconstructable : 84% : strong : Exact MidiPlayer primary `vftable[-1]` COL pointer; live bytes show `0x0061faf8 -> 0x0064c344`, RTTI inventory names `??_R4MidiPlayer@@6B@`, and successor vtable refs at `0x00525e10`, `0x00525ed5`, and `0x005265a5` prove the boundary, but canonical owner/emitter remains blank because direct owner [UID:00008A][MidiPlayer](by-class/MidiPlayer.md) is still below the strict 85 completion gate.
```

Supervisor applied and validated the replacement/insertion block above on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No C001 FieldMap/Message `.rdata` supervisor-owned `by-memory/-coverage-report.md` rows remain pending for this slice.

## 2026-06-15 Agent-C001 Goal 2 Static/Import/Runtime Data Memory C001-goal2-static-import-runtime-data-memory-20260615-2

- Changed docs: [UID:00024J][0x0060c45a-0x0060c4ac.StaticRuntimeCleanupWrappersAfterUserPanePool](../../../../by-memory/0x0060c45a-0x0060c4ac.StaticRuntimeCleanupWrappersAfterUserPanePool.md), [UID:0001Z6][0x0060d000-0x0060d670.ImportDataSection](../../../../by-memory/0x0060d000-0x0060d670.ImportDataSection.md), [UID:00024N][0x0060e174-0x0060e2b0.MsvcStlLocaleIostreamRdata](../../../../by-memory/0x0060e174-0x0060e2b0.MsvcStlLocaleIostreamRdata.md), [UID:00024P][0x0060f038-0x0060f4c0.MsvcStlNumericRdata](../../../../by-memory/0x0060f038-0x0060f4c0.MsvcStlNumericRdata.md), [UID:0001Z5][0x00401000-0x0060d000.MasterCodeTextSection](../../../../by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md), [UID:0001Z7][0x0060d670-0x0066d000.ReadOnlyDataSection](../../../../by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md), validator-owned generated files, and this notes file.
- Score/routing changes: [UID:00024J] `80/85 -> 85/90`; [UID:0001Z6] `80/85 -> 85/90`; [UID:00024N] `80/85 -> 85/90`; [UID:00024P] `80/85 -> 85/90`; [UID:0001Z5] `83/89 -> 84/89`; [UID:0001Z7] `80/90 -> 81/90`. All six changed docs keep `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, `RECONSTRUCTABLE:FALSE`, and blank final C++ because the target data is compiler/runtime/import/section-container material rather than source-authored NexusTK output.
- Evidence summary: live IDA MCP session `a003_objectlist_dispatch_20260615` reported `NexusTK.exe.i64`, image base `0x00400000`, Hex-Rays ready, and strings cache ready. `lookup_funcs`, `analyze_component`, `xrefs_to`, and `get_bytes` reconfirmed the seven cleanup wrappers, one paired startup-registration xref per wrapper, ten-byte `0xcc` padding, and final `VariantClear` wrapper for [UID:00024J]. `imports offset=0 count=0` reconfirmed 395 IAT entries across 17 modules for [UID:0001Z6], first `ADVAPI32!RegSetValueExW` at `0x0060d000` and last `ole32!OleInitialize` at `0x0060d668`. `entity_query`, `xrefs_to`, and `get_bytes` reconfirmed [UID:00024N]/[UID:00024P] as MSVC STL/Dinkumware runtime `.rdata`, including exact named heads, strings, runtime consumers, and JsonCpp/LodePNG successor boundaries.
- IDA DB changes: none. Skipped candidates: no names, comments, prototypes, import renames, data retyping, segment edits, or IDB save were applied because the evidence supports documentation/routing scores only and all targets are generated/runtime/linker data.
- Validation: scoped loop `python .\tools\validator.py --mode file --file <target> --apply --lock-timeout 60` exited `0` for [UID:00024J], [UID:0001Z6], [UID:00024N], [UID:00024P], [UID:0001Z5], and [UID:0001Z7]; each run reached `ok: 1`.

### Supervisor-applied `by-memory/-coverage-report.md` replacements retained for audit

Placement context: replace the top-level [UID:0001Z5], [UID:0001Z6], and [UID:0001Z7] rows in place. Under [UID:0001Z5], replace [UID:00024J] in place. Under [UID:0001Z7], replace [UID:00024N] and [UID:00024P] in place.

```text
- [UID:0001Z5][0x00401000-0x0060d000.MasterCodeTextSection](by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md) 0x00401000-0x0060d000 | section-container | MasterCodeTextSection : ignored : 84% : strong : IDA `.text` executable segment container, not a standalone source object; current report has 1781 immediate children, 817 nested children, no immediate/nested unknown rows, current endpoint/name inventory, and C001 2026-06-15 child follow-ups raising JsonCpp number-token helper, WideApi dispatch initializer, zlib source-provenance family, libjpeg static-library child pages, fitting-room progress/action helpers, CashShop/FileDownloader scalar deleting destructor wrappers, FileDownloader constructor/destructor/message dispatcher pages, FileDownloader submit-helper pages, and the late static runtime cleanup-wrapper island while other broad child/source-neighborhood audits remain below final quality.
    - [UID:00024J][0x0060c45a-0x0060c4ac.StaticRuntimeCleanupWrappersAfterUserPanePool](by-memory/0x0060c45a-0x0060c4ac.StaticRuntimeCleanupWrappersAfterUserPanePool.md) 0x0060c45a-0x0060c4ac | runtime static cleanup | StaticRuntimeCleanupWrappersAfterUserPanePool : ignored : 85% : strong : STL/CRT/COM/runtime static cleanup wrappers paired with the `0x0041a4cd-0x0041a550` startup island; C001 live IDA refresh reconfirmed seven wrapper function boundaries, one paired startup-registration xref per wrapper, raw bytes, the ten-byte `0xcc` padding run, and the final `VariantClear` wrapper, so this clears as ignored compiler/runtime cleanup data rather than source-authored NexusTK code.
- [UID:0001Z6][0x0060d000-0x0060d670.ImportDataSection](by-memory/0x0060d000-0x0060d670.ImportDataSection.md) 0x0060d000-0x0060d670 | import-data | ImportDataSection : ignored : 85% : strong : Section-level PE `.idata` import data; C001 live IDA refresh reconfirmed 395 IAT entries across 17 modules, first entry `0x0060d000 ADVAPI32!RegSetValueExW`, last entry `0x0060d668 ole32!OleInitialize`, and rebuild handling through linker/import dependencies rather than handwritten source bytes.
- [UID:0001Z7][0x0060d670-0x0066d000.ReadOnlyDataSection](by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md) 0x0060d670-0x0066d000 | section-container | ReadOnlyDataSection : ignored : 81% : strong : IDA `.rdata` section container, not a standalone source object; current report has 98 immediate children, 95+ nested children after C001 exact child splits, no immediate unknown/uncovered rows, current bounded IDA name/string inventory, and C001 2026-06-15 child follow-ups splitting AboveFrame/locale tails, employee alert text, the BaramApp/MainMenu boundary, and refreshing two MSVC STL runtime-data children while many broad vtable/string/runtime rows still require child-level audits.
    - [UID:00024N][0x0060e174-0x0060e2b0.MsvcStlLocaleIostreamRdata](by-memory/0x0060e174-0x0060e2b0.MsvcStlLocaleIostreamRdata.md) 0x0060e174-0x0060e2b0 | runtime | MsvcStlLocaleIostreamRdata : ignored : 85% : strong : MSVC STL/Dinkumware exception, locale, facet, system-error, iostream, and ios-base read-only data; C001 live IDA refresh reconfirmed 17 runtime/STL named heads, eight diagnostic strings, key runtime xrefs, raw bytes, and the JsonCpp successor boundary at `0x0060e2b0`.
    - [UID:00024P][0x0060f038-0x0060f4c0.MsvcStlNumericRdata](by-memory/0x0060f038-0x0060f4c0.MsvcStlNumericRdata.md) 0x0060f038-0x0060f4c0 | runtime | MsvcStlNumericRdata : ignored : 85% : strong : MSVC STL numeric facet vtables, stream formatting constants, and container/string diagnostics; C001 live IDA refresh reconfirmed 12 runtime named heads, numeric/container strings, key runtime xrefs, raw byte constants/tables, and the LodePNG successor boundary at `0x0060f4c0`.
```

Supervisor applied and validated the six replacement rows above on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No C001 static/import/runtime-data supervisor-owned `by-memory/-coverage-report.md` rows remain pending for this slice.

## 2026-06-15 Agent-C001 Goal 2 Section Container RData Tail C001-goal2-section-container-rdata-tail-20260615-2

- Changed docs: [UID:0001OE][0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText](../../../../by-memory/0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText.md), [UID:000304][0x0069be06-0x0069be08.TextEditSelectionScratchPadding](../../../../by-memory/0x0069be06-0x0069be08.TextEditSelectionScratchPadding.md), [UID:0001Z7][0x0060d670-0x0066d000.ReadOnlyDataSection](../../../../by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md), validator-owned generated/projected files, and this notes file. [UID:0001Z5][0x00401000-0x0060d000.MasterCodeTextSection](../../../../by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md) was leased/read but not changed because this slice did not produce `.text` child evidence.
- Score/routing changes: [UID:0001OE] `78/90 -> 85/92`, owner/emitter remains [UID:0000J0][EmployeeDialogPane](../../../../by-file/EmployeeDialogPane.md), final C++ blank; [UID:000304] `80/84 -> 86/90`, still ignored/non-reconstructable padding with no owner/emitter; [UID:0001Z7] `78/90 -> 79/90`, still `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitters; [UID:0001Z5] unchanged `79/89`.
- Evidence summary: live IDA MCP session `a003_objectlist_dispatch_20260615` confirmed `NexusTK.exe.i64`, image base `0x00400000`, Hex-Rays ready, and strings cache ready. `get_bytes 0x00619290+0x48` decoded the employee warning as UTF-16LE `한번에 여러개를 추가할 수 없습니다.`, bounded by predecessor `DLGEXC3.EPF` and the `0x006192c8` Encoder vtable successor; `xrefs_to` found exactly one xref at `0x004a4bc1`; `analyze_function 0x004a4b20` showed `sub_49FEB0(&unk_61929C, this, &off_613A18, 0)` on the multi-select branch. `get_bytes 0x0069bdf8+0x20` returned zero bytes and `xrefs_to` proved `0x0069be04` has eight TextEdit mouse-handler refs, `0x0069be06` has zero refs, and `0x0069be08` has five ThreadMan/TimerMgr refs.
- IDA DB changes: none. Skipped candidates: no names, comments, prototypes, string retyping, data retyping, structure edits, or IDA save were applied because the evidence supports documentation score/routing only.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText.md --apply --lock-timeout 60`, `python .\tools\validator.py --mode file --file by-memory\0x0069be06-0x0069be08.TextEditSelectionScratchPadding.md --apply --lock-timeout 60`, and `python .\tools\validator.py --mode file --file by-memory\0x0060d670-0x0066d000.ReadOnlyDataSection.md --apply --lock-timeout 60` each exited `0` with `ok: 1`.

### Supervisor-applied `by-memory/-coverage-report.md` replacements/insertion

Supervisor applied the exact replacement rows for [UID:0001Z7] and [UID:0001OE] and inserted [UID:000304] under [UID:0002AQ] on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No C001 section-container `.rdata` tail supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 Agent-C001 Goal 2 Section Container Follow-up Locale/Literal Tail C001-goal2-section-container-followup-20260615-1

- Changed docs: new [UID:0003OZ][0x006112fc-0x00612574.MsvcStlLocaleNameData](../../../../by-memory/0x006112fc-0x00612574.MsvcStlLocaleNameData.md), new [UID:0003P0][0x00612580-0x006125a4.SharedShortLiteralTail](../../../../by-memory/0x00612580-0x006125a4.SharedShortLiteralTail.md), new [UID:0003P1][0x006125a4-0x006125a8.PasswordErrorRttiLocatorPointer](../../../../by-memory/0x006125a4-0x006125a8.PasswordErrorRttiLocatorPointer.md), [UID:00024S][0x00610ed8-0x006125a8.AboveFrameAndLocaleReadOnlyData](../../../../by-memory/0x00610ed8-0x006125a8.AboveFrameAndLocaleReadOnlyData.md), [UID:0001Z7][0x0060d670-0x0066d000.ReadOnlyDataSection](../../../../by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md), validator-owned generated files, and this notes file.
- Score/routing changes: [UID:0003OZ] new `86/90`, ignored runtime/STL data; [UID:0003P0] new `86/91`, ignored non-emitting mixed literal tail; [UID:0003P1] new `86/91`, owner [UID:0000A8][PasswordError](../../../../by-class/PasswordError.md), emitter [UID:0000J5][Error](../../../../by-file/Error.md), final C++ blank; [UID:00024S] `85/91 -> 87/92`; [UID:0001Z7] `77/90 -> 78/90`.
- Evidence summary: live IDA MCP session `a003_objectlist_dispatch_20260615` confirmed `NexusTK.exe.i64`, image base `0x00400000`, Hex-Rays ready, and strings cache ready. `get_bytes`/`entity_query`/`trace_data_flow` proved `0x006112fc-0x00612574` is runtime locale-name data with 46 locale labels and only a runtime-tail table xref at `0x0063422c`. `xrefs_to` and disassembly proved `0x00612580-0x006125a4` is mixed `S`/`B`/`Delete`/`Error` literal data with separate consumers. `get_bytes` proved `0x006125a4` is the `0x00641fa4` `PasswordError` RTTI locator pointer immediately before [UID:0002NE][PasswordErrorVtableData](../../../../by-memory/0x006125a8-0x006125bc.PasswordErrorVtableData.md).
- Owner/emitter decisions: [UID:00024S] and [UID:0001Z7] remain `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitters. [UID:0003OZ] is ignored as runtime/STL data. [UID:0003P0] is ignored as a non-emitting mixed literal index because no single direct owner covers all four literal heads. [UID:0003P1] routes through direct class [UID:0000A8] and emitter [UID:0000J5], but final C++ remains blank because the RTTI pointer is compiler-emitted generated-binary data.
- IDA DB changes: none. Skipped candidates: no names, comments, prototypes, type/member edits, data retyping, RTTI structure edits, or IDA save were applied; evidence supports documentation splits only.
- Validation: `python .\tools\validator.py --mode file --file by-memory/<target> --apply --lock-timeout 60` exited `0` for [UID:0003OZ], [UID:0003P0], [UID:0003P1], [UID:00024S], and [UID:0001Z7]; visible summaries reached `ok: 1` for parent/section, and the new-child validator run assigned UIDs `0003OZ`, `0003P0`, and `0003P1`.

### Supervisor-applied `by-memory/-coverage-report.md` replacements/inserts

Supervisor applied the exact replacement row for [UID:0001Z7], replaced [UID:00024S], and inserted new child rows [UID:0003OZ], [UID:0003P0], and [UID:0003P1] under [UID:00024S] on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No C001 locale/literal-tail supervisor-owned rows remain pending.

## 2026-06-15 Agent-C001 Goal 2 Section Container Follow-up Continuation C001-goal2-section-container-followup-20260615-1

- Changed docs: [UID:0003OY][0x00612574-0x00612580.ApplicationErrorStateVtableData](../../../../by-memory/0x00612574-0x00612580.ApplicationErrorStateVtableData.md) new child, [UID:00024S][0x00610ed8-0x006125a8.AboveFrameAndLocaleReadOnlyData](../../../../by-memory/0x00610ed8-0x006125a8.AboveFrameAndLocaleReadOnlyData.md), [UID:0001Z7][0x0060d670-0x0066d000.ReadOnlyDataSection](../../../../by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md), [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](../../../../by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md), [UID:0001Z5][0x00401000-0x0060d000.MasterCodeTextSection](../../../../by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md), validator-owned generated files, and this notes file.
- Score/routing changes: new [UID:0003OY] `0/0 -> 86/91`, owner/emitter [UID:0000HG][Application](../../../../by-file/Application.md); [UID:00024S] `84/90 -> 85/91`; [UID:0001Z7] `76/90 -> 77/90`; [UID:0000WD] `82/88 -> 85/90`, route remains [UID:0000ML][PlatformApi](../../../../by-file/PlatformApi.md); [UID:0001Z5] `75/89 -> 76/89`.
- Evidence summary: live IDA MCP session `a003_objectlist_dispatch_20260615` verified `0x00612574-0x00612580` as the three-slot application error-state vtable (`0x004632c0`, `0x004f4b10`, `0x0041b6c0`), with static initializer, destructor, and atexit cleanup refs, and a clean successor literal boundary at `0x00612580`. The same session refreshed [UID:0000WD] with exact `0x228` function extent, startup-table xref `0x0060d71c`, NT wide API slot assignment sequence, representative consumer xrefs, and `0x0041a4a8`/`0x0041a4b0` successor-boundary checks.
- Owner/emitter decisions: [UID:0003OY] routes through [UID:0000HG] because Application already clears `86/90` and documents the same application error-state object. [UID:00024S], [UID:0001Z7], and [UID:0001Z5] remain non-reconstructable section/aggregate maps with blank owners/emitters. [UID:0000WD] remains reconstructable and routed through PlatformApi, but final C++ stays blank because source-quality dispatch typedef/table declarations and the generated `UniAPIInit` boundary are not proven.
- IDA DB changes: none. Skipped candidates: no names, comments, prototypes, type/member edits, vtable/data retyping, or IDA save were applied; evidence supports documentation splits/scores, not a low-risk database mutation.
- Validation: `python .\tools\validator.py --mode file --file by-memory/0x00612574-0x00612580.ApplicationErrorStateVtableData.md --apply --lock-timeout 60` assigned [UID:0003OY] and exited `0` with `ok: 1`; scoped validator loop over [UID:00024S], [UID:0001Z7], [UID:0000WD], [UID:0001Z5], and [UID:0003OY] exited `0` and each run reached `ok: 1`.

### Supervisor-applied `by-memory/-coverage-report.md` rows

Supervisor applied the exact replacement rows for [UID:0001Z5], [UID:0000WD], [UID:0001Z7], and [UID:00024S], plus inserted child row [UID:0003OY] under [UID:00024S], on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.

## 2026-06-15 Agent-C001 Goal 2 Section Container Follow-up Remaining LibJPEG Children C001-goal2-section-container-followup-20260615-1

- Changed docs: [UID:0000VR][0x00401b00-0x004038c7.LibJpegMarkerReader](../../../../by-memory/0x00401b00-0x004038c7.LibJpegMarkerReader.md), [UID:0000VT][0x004048f0-0x004049bb.LibJpegCompressRawDataApi](../../../../by-memory/0x004048f0-0x004049bb.LibJpegCompressRawDataApi.md), [UID:0000VU][0x004049c0-0x00404a5c.LibJpegCommonApi](../../../../by-memory/0x004049c0-0x00404a5c.LibJpegCommonApi.md), [UID:0000VV][0x00404a60-0x0040505b.LibJpegInputController](../../../../by-memory/0x00404a60-0x0040505b.LibJpegInputController.md), [UID:0000VX][0x00405c80-0x004063c8.LibJpegDecompressMaster](../../../../by-memory/0x00405c80-0x004063c8.LibJpegDecompressMaster.md), [UID:0000VZ][0x004064a0-0x00406d8c.LibJpegMarkerWriter](../../../../by-memory/0x004064a0-0x00406d8c.LibJpegMarkerWriter.md), [UID:0000W0][0x00406d90-0x00406e46.LibJpegCompressMasterInit](../../../../by-memory/0x00406d90-0x00406e46.LibJpegCompressMasterInit.md), [UID:0000VP][0x00401000-0x00414283.LibJpeg6bCore](../../../../by-memory/0x00401000-0x00414283.LibJpeg6bCore.md), [UID:0001Z5][0x00401000-0x0060d000.MasterCodeTextSection](../../../../by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md), and this notes file.
- Score/routing changes: [UID:0000VR] `80/85 -> 86/90`; [UID:0000VT] `80/85 -> 86/90`; [UID:0000VU] `80/85 -> 86/90`; [UID:0000VV] `80/85 -> 86/90`; [UID:0000VX] `80/85 -> 86/90`; [UID:0000VZ] `80/85 -> 86/90`; [UID:0000W0] `80/85 -> 86/90`; [UID:0000VP] `84/88 -> 85/89`; [UID:0001Z5] `78/89 -> 79/89`. [UID:0001Z7] was not changed in this libjpeg-focused slice and remains `77/90`.
- Owner/emitter decisions: all seven exact libjpeg children remain `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000KN`, `EMITTER_UIDS:0000KN`, final C++ blank. [UID:0000VP] remains a third-party static-library aggregate routed through [UID:0000KN][LibJPEG](../../../../by-file/LibJPEG.md), but score is held at the threshold because high-address Huffman/color/sampling/coefficient/quantizer/DCT helper clusters remain broad aggregate evidence rather than exact source-file child pages. [UID:0001Z5] remains `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitters.
- Evidence summary: live IDA MCP session `a003_objectlist_dispatch_20260615` reconfirmed healthy `NexusTK.exe.i64`, image base `0x00400000`, Hex-Rays ready, and strings cache ready. C001 refreshed boundary lookups and representative decompilation for marker-reader restart/marker-switch paths, raw-data compression state and row-group behavior, common abort/destroy/table allocation helpers, input-controller setup/scan geometry/marker consumption/reset paths, decompression master allocation/fanout/output-pass setup, marker-writer callback/SOS/SOI/EOI paths, and compression master initializer fanout.
- IDA DB changes: none. Skipped candidates: no names, comments, prototypes, type/member edits, source-file labels, function boundary edits, or data retyping were applied because the documentation score/route evidence is strong enough, while final third-party symbol naming and compile-configuration details remain below the safe DB-edit threshold.
- Validation: scoped loop `python .\tools\validator.py --mode file --file <target> --apply --lock-timeout 60` exited `0` for [UID:0000VR], [UID:0000VT], [UID:0000VU], [UID:0000VV], [UID:0000VX], [UID:0000VZ], [UID:0000W0], [UID:0000VP], and [UID:0001Z5]; each run reached `ok: 1`. Validator removed the seven libjpeg children from `project-level/-auto-completion-stats.md`; [UID:0001Z7] remains listed at `77/90`. `by-memory/-coverage-report.md` remains supervisor-owned and was not edited by C001.

### Supervisor-applied `by-memory/-coverage-report.md` replacements

Supervisor applied the exact replacement rows for [UID:0001Z5], [UID:0000VP], [UID:0000VR], [UID:0000VT], [UID:0000VU], [UID:0000VV], [UID:0000VX], [UID:0000VZ], and [UID:0000W0] on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No C001 libjpeg remaining-children supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 Agent-C001 Goal 2 Section Container Follow-up Zlib Continuation C001-goal2-section-container-followup-20260615-1

- Changed docs: [UID:0000W3][0x004142c0-0x00419e56.ZlibCore](../../../../by-memory/0x004142c0-0x00419e56.ZlibCore.md), [UID:0000W2][0x004142c0-0x00414565.ZlibPublicCompressChecksum](../../../../by-memory/0x004142c0-0x00414565.ZlibPublicCompressChecksum.md), [UID:0000W4][0x00414820-0x00417b97.ZlibDeflateAndTrees](../../../../by-memory/0x00414820-0x00417b97.ZlibDeflateAndTrees.md), [UID:0000W5][0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler](../../../../by-memory/0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler.md), [UID:0000W6][0x00417ba0-0x00419e56.ZlibInflateInternals](../../../../by-memory/0x00417ba0-0x00419e56.ZlibInflateInternals.md), [UID:0001Z5][0x00401000-0x0060d000.MasterCodeTextSection](../../../../by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md), validator-owned generated files, and this notes file.
- Score/routing changes: [UID:0000W3] `80/85 -> 86/90`; [UID:0000W2] `80/85 -> 86/90`; [UID:0000W4] `80/85 -> 85/88`; [UID:0000W5] `80/85 -> 86/90`; [UID:0000W6] `80/85 -> 86/90`; [UID:0001Z5] `76/89 -> 77/89`. Zlib owner/emitter route remains [UID:0000PC][Zlib](../../../../by-file/Zlib.md); [UID:0001Z5] remains `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitters.
- Evidence summary: live IDA MCP session `a003_objectlist_dispatch_20260615` reported `NexusTK.exe.i64`, image base `0x00400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. C001 reconfirmed the zlib island starts at `0x004142c0`, predecessor `0x00414290-0x004142b5` is Miles shutdown glue/not a function at the tail, `0x00419e56` is not a function, and the next modeled function is `0x00419e80`; string search found `deflate 1.1.4`, `inflate 1.1.4`, and version literal `1.1.4`. Live decompilation refreshed `compress2`/`uncompress`, CRC table loop, deflate state machine, `inflateInit2_`, public inflate diagnostics, `inflate_blocks`, and `inflate_fast` anchors against the staged official zlib 1.1.4 source tree.
- IDA DB changes: none. Skipped safe candidates: no function/data renames, comments, prototypes, type/member edits, source-file classifications, or IDA comments were applied because the docs now have enough evidence for score/routing, while exact optimized helper names/prototypes and compile options remain below the C-agent DB-edit threshold.
- Validation: scoped loop `python .\tools\validator.py --mode file --file <target> --apply --lock-timeout 60` exited `0` for [UID:0000W3], [UID:0000W2], [UID:0000W4], [UID:0000W5], [UID:0000W6], and [UID:0001Z5]; each run reached `ok: 1`. Validator recorded score updates for the zlib pages and [UID:0001Z5]; `auto-generated/-ag-memory-coverage.md` still shows zlib rows emitting through [UID:0000PC].

### Supervisor-applied `by-memory/-coverage-report.md` replacements

Supervisor applied the exact replacement row for [UID:0001Z5] plus the [UID:0000W3] zlib block and child rows [UID:0000W2], [UID:0000W4], [UID:0000W5], and [UID:0000W6] on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. The section-container assignment remains open because [UID:0001Z5] and [UID:0001Z7] are still below 85 completion; no C001 zlib supervisor-owned rows remain pending.

## 2026-06-12 Agent-C001 Batch C001-002

- Changed docs: `by-memory/0x00630c08-0x00630c24.UserStatusInvalidNameLiteral.md` and this notes file. No IDA database edits were applied.
- Score changes: [UID:0003EA] `87/92 -> 88/93`; parent remains [UID:00000A][AddToBlockListenInputPane](../../../../by-class/AddToBlockListenInputPane.md), whose direct file parent [UID:0000HS][BlockListenInputPanes](../../../../by-file/BlockListenInputPanes.md) already clears the strict routing gate.
- Supervisor applied the Batch C001-002 `by-memory/-coverage-report.md` replacement row for [UID:0003EA][UserStatusInvalidNameLiteral](../../../../by-memory/0x00630c08-0x00630c24.UserStatusInvalidNameLiteral.md) on 2026-06-12.
- C001 pre-task cleanup: interrupted C001 leases for the prior `0003DJ` assignment were released before work on `0003EA`; no `0003DJ` documentation edits were made by C001 in this resumed turn.

## 2026-06-12 Agent-C001 Batch C001-003

- Changed docs: `by-memory/0x0062d6a8-0x0062d714.SystemMessageEntryVtableData.md`, new exact child pages `by-memory/0x0062d6a8-0x0062d6cc.HeaderSystemMessageVtableData.md`, `by-memory/0x0062d6cc-0x0062d6f0.FooterSystemMessageVtableData.md`, `by-memory/0x0062d6f0-0x0062d714.ColorStringSystemMessageVtableData.md`, `by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md`, `by-class/HeaderSystemMessage.md`, `by-class/FooterSystemMessage.md`, `by-class/ColorStringSystemMessage.md`, `by-class/-coverage-report.md`, and this notes file. No IDA database edits were applied.
- Score changes: [UID:0003DJ] `86/92 -> 90/93`, `RECONSTRUCTABLE:TRUE -> FALSE`; new [UID:0003GD] `0/0 -> 88/93`, parent [UID:000061]; new [UID:0003GE] `0/0 -> 88/93`, parent [UID:00005D]; new [UID:0003GF] `0/0 -> 88/93`, parent [UID:000030]; [UID:000061] `82/86 -> 85/88`; [UID:00005D] `82/86 -> 85/88`; [UID:000030] remains `85/88`.
- Supervisor applied and validated the Batch C001-003 `by-memory/-coverage-report.md` replacement block for [UID:0003DJ] and new child rows [UID:0003GD], [UID:0003GE], and [UID:0003GF] on 2026-06-12.

## 2026-06-12 Agent-C001 Batch C001-004

- Changed docs: `by-memory/0x0062d8c4-0x0062d974.OldSystemMessagePaneVtableData.md`, `by-class/OldSystemMessagePane.md`, and this notes file. No IDA database edits were applied.
- Score changes: [UID:0003DM] `86/92 -> 88/93`, parent blank -> [UID:00009T][OldSystemMessagePane](../../../../by-class/OldSystemMessagePane.md); [UID:00009T] `82/84 -> 85/88`.
- Evidence summary: C001 live IDA verified the exact `OldSystemMessagePane` RTTI/vtable run, three constructor/reset/destructor refs for each vtable head, the `0x0062d974` resource-string successor boundary, constructor singleton/tile/message setup, and destructor message/tile/singleton/base cleanup. The child and actual direct parent now both clear the strict `85/85` gate.

## 2026-06-12 Agent-C001 Batch C001-005

- Changed docs: `by-memory/0x0062da10-0x0062daac.TerminalPaneVtableData.md`, `by-memory/0x0062da0c-0x0062da10.TerminalPaneRttiLocatorPointer.md`, `by-memory/0x0062d974-0x0062da10.SystemMessageResourceStrings.md`, `by-class/TerminalPane.md`, `by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md`, `by-class/-coverage-report.md`, and this notes file. No IDA database edits were applied.
- Score changes: [UID:0003DO] `85/91 -> 87/93`, parent blank -> [UID:0000EG][TerminalPane](../../../../by-class/TerminalPane.md); [UID:0003GS] parent blank -> [UID:0000EG][TerminalPane](../../../../by-class/TerminalPane.md), score unchanged `85/90`; [UID:0000EG] `86/84 -> 87/88`.
- Evidence summary: C001 live IDA verified the three `TerminalPane` vtable heads, the separate [UID:0003GS] locator pointer immediately before them, RTTI locator records, constructor vtable stores, representative virtual slot targets, singleton lifecycle at `0x0069bdf8`, reconnect/leave callback construction, destructor singleton clear, and the `TerminalSetupPane` successor boundary.

## Supervisor-Applied Shared-File Updates

- The supervisor applied and validated the Batch C001-005 `by-memory/-coverage-report.md` row for [UID:0003DO] and the merged [UID:0003GS] row inside A004's [UID:0003DN] split block on 2026-06-12.
- No Batch C001-005 supervisor-owned shared-file rows remain pending.

## 2026-06-12 Agent-C001 Batch C001-006

- Changed docs: `by-memory/0x0062dd44-0x0062dddc.DialDialogVtableData.md`, `by-class/DialDialog.md`, `by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md`, `by-class/-coverage-report.md`, and this notes file. No IDA database edits were applied.
- Score changes: [UID:0003DT] `85/91 -> 87/93`, parent blank -> [UID:00003R][DialDialog](../../../../by-class/DialDialog.md); [UID:00003R] `84/86 -> 86/88`.
- Evidence summary: C001 session-based IDA MCP verified the three `DialDialog` vtable labels, constructor writes at `0x0058d7a6`/`0x0058d7ae`/`0x0058d7b8`, action/parser/destructor slot references, `ATZ` successor boundary, and separate `ATX3DT` constructor literal reference.

## Supervisor-Applied Shared-File Updates

- The supervisor applied and validated the C001-006 `by-memory/-coverage-report.md` row for [UID:0003DT] on 2026-06-12.
- No C001-006 supervisor-owned shared-file rows remain pending.

## 2026-06-12 Agent-C001 Batch C001-007

- Changed docs: `by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md`, `by-file/FolderSelectDialog.md`, `by-file/-coverage-report.md`, `by-class/-coverage-report.md`, and this notes file. No IDA database edits were applied.
- Score changes: [UID:00027D] `86/90 -> 87/92`, parent blank -> [UID:0000JF][FolderSelectDialog](../../../../by-file/FolderSelectDialog.md); [UID:0000JF] `85/86 -> 86/88`; class coverage row for [UID:000059][FolderSelectDialog](../../../../by-class/FolderSelectDialog.md) synchronized to its existing `85` completion.
- Evidence summary: C001 session-based IDA MCP reconfirmed all four `asc_66DA88` refs at `0x004b183f`, `0x004b185b`, `0x004b1a8b`, and `0x004b1aaa`, the FolderSelectDialog island function starts/sizes, constructor caller `0x0052986d`, and `analyze_component` shared-global ownership by only `sub_4B1590` and `sub_4B1A00`.

## Supervisor-Applied Shared-File Updates

- The supervisor applied and validated the Batch C001-007 `by-memory/-coverage-report.md` replacement row for [UID:00027D][FolderSelectDriveRootBuffer](../../../../by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md) on 2026-06-12.
- No Batch C001-007 supervisor-owned shared-file updates remain pending.

## 2026-06-12 Agent-C001 Batch C001-008

- Changed docs: `by-memory/0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogUnreferencedTransferReplyHelper.md`, `by-class/NewPredefinedFormArticleDialog.md`, `by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md`, and this notes file. No IDA database edits were applied.
- Score changes: [UID:0002UR] `85/90 -> 87/92`, parent blank -> [UID:000098][NewPredefinedFormArticleDialog](../../../../by-class/NewPredefinedFormArticleDialog.md). [UID:000098] remains `85/86`; [UID:0000LT][NewPredefinedFormArticleDialog](../../../../by-file/NewPredefinedFormArticleDialog.md) remains `88/85`.
- Evidence summary: C001 session-based IDA MCP reconfirmed `0x00478aa0` has no inbound edge, while live sibling slots point `0x006140ac -> 0x00478940`, `0x006140e8 -> 0x004782b0`, and `0x006141f0 -> 0x004790a0`; the earlier `NewArticleDialog` pair repeats the pattern with `0x0061400c -> 0x004772f0` and no inbound edge for `0x00477450`. `analyze_component` reconfirmed identical alert-construction callees and `TransferReplyPredefinedAlert` vtable writes.

## Supervisor-Applied Shared-File Updates

- The supervisor applied and validated the Batch C001-008 `by-memory/-coverage-report.md` replacement row for [UID:0002UR][NewPredefinedFormArticleDialogUnreferencedTransferReplyHelper](../../../../by-memory/0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogUnreferencedTransferReplyHelper.md) on 2026-06-12.
- No Batch C001-008 supervisor-owned shared-file updates remain pending.

## 2026-06-12 Agent-C001 Batch C001-009

- Changed docs: `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md`, `by-file/StringUtil.md`, and this notes file.
- IDA database update: applied safe IDA 9.1 fix `define_func 0x004b81a0-0x004b81eb`, renamed `sub_4B81A0` to `WideStringHashHelper`, verified Hex-Rays decompilation, and saved `NexusTK.exe.i64`.
- Score changes: [UID:00022J] `85/88 -> 88/92`; parent remains blank because no caller, xref, raw VA/RVA pointer, table reference, or source-family artifact proves a direct owner. [UID:0000OB][StringUtil](../../../../by-file/StringUtil.md) remains `87/88`.

## Supervisor-Applied Shared-File Updates

- The supervisor applied and validated the Batch C001-009 `by-memory/-coverage-report.md` replacement row for [UID:00022J][WideStringHashHelper](../../../../by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) on 2026-06-12.
- No Batch C001-009 supervisor-owned shared-file updates remain pending.

## 2026-06-12 Agent-C001 Batch C001-010

- Changed docs: `by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md` and this notes file. No IDA database edits were applied.
- Score changes: [UID:000176] `85/89 -> 88/92`, `RECONSTRUCTABLE:TRUE -> FALSE`; parent remains blank by design because this is a non-emitting helper-neighborhood/index map and exact children carry ownership.
- Evidence summary: C001 live IDA MCP reconfirmed modeled children `0x004d0f50-0x004d15c5`, `0x004d15d0-0x004d15fc`, and `0x004d1600-0x004d165d`, padding/no-function gaps at `0x004d15c5`, `0x004d15fc`, and `0x004d165d`, no aggregate function, no modeled functions/xrefs at adjacent raw-helper starts `0x004d1660`/`0x004d1710`, and the successor modeled function at `0x004d1730`.

## Supervisor-Applied Shared-File Updates

- The supervisor applied and validated the Batch C001-010 `by-memory/-coverage-report.md` replacement row for [UID:000176][ImageFrameTable](../../../../by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md) on 2026-06-12.
- No Batch C001-010 supervisor-owned shared-file updates remain pending.

## 2026-06-12 Agent-C001 Batch C001-011

- Changed docs: `by-memory/0x00500640-0x00502755.SpecializedButtonPanes.md`, `by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md`, `by-class/BlueAlertPane.md`, `by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md`, `by-file/UserCreateAppearanceControls.md`, new exact helper pages `by-memory/0x00502390-0x0050239b.BackStoryDialogPaneSingletonClear.md` and `by-memory/0x005023a0-0x005023ab.ChangePasswordDialogPaneSingletonClear.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, and this notes file. No IDA database edits were applied.
- Score changes: [UID:0001A4] `85/87 -> 88/91`, `RECONSTRUCTABLE:TRUE -> FALSE`, parent remains blank by design because the span is a mixed-owner executable index; [UID:0001A5] `82/88 -> 85/88`, parent remains [UID:00000Y][BlueAlertPane](../../../../by-class/BlueAlertPane.md); [UID:00000Y] `82/86 -> 85/87`, parent remains [UID:0000HE][AlertPanes](../../../../by-file/AlertPanes.md); [UID:0001A6] `84/88 -> 85/89`, parent remains [UID:0000OX][UserCreateAppearanceControls](../../../../by-file/UserCreateAppearanceControls.md); [UID:0000OX] `86/80 -> 87/85`; new [UID:0003HH] and [UID:0003HG] recorded as `84/90`, `RECONSTRUCTABLE:FALSE`, parent blank.
- Evidence summary: C001 live IDA MCP reconfirmed raw gender/direction constructor starts, BlueAlertPane and create-user appearance successor boundaries, `0x00501150` constructor/callback xref at `0x0052e0af`, singleton-clear helper bodies and constructor-context xrefs at `0x00601ee5`/`0x00601b66`, and the `0x005026a0`/`0x00502700` destructor entries. The broad target is documented as a non-emitting container; exact source-bearing children retain or clear their own direct parents.

## Supervisor-Applied Shared-File Updates

- The supervisor applied and validated the Batch C001-011 `by-memory/-coverage-report.md` replacement/insert block for [UID:0001A4], [UID:0001A5], [UID:0001A6], new helper rows [UID:0003HH]/[UID:0003HG], and the inserted padding rows on 2026-06-12.
- The supervisor applied and validated the Batch C001-011 `by-memory/-ignored.md` entries for `0x00502390-0x0050239b` and `0x005023a0-0x005023ab` on 2026-06-12.
- No Batch C001-011 supervisor-owned shared-file rows remain pending.

## 2026-06-12 Agent-C001 Batch C001-012

- Changed docs: `by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md`, `by-file/ScreenDimmer.md`, and this notes file. No IDA database edits were applied.
- Score changes: [UID:0001GA] `85/92 -> 88/93`, `RECONSTRUCTABLE:TRUE -> FALSE`, parent remains blank by design as a non-emitting mixed index; [UID:0000NA][ScreenDimmer](../../../../by-file/ScreenDimmer.md) score unchanged at `87/86`.
- Evidence summary: C001 live IDA MCP on session `b001_nexustk` reconfirmed the fourteen `ScreenDimmer` constructor xrefs, zero direct `ScreenFadeOut` constructor xrefs, exact helper/thunk/deleting-destructor starts, `0x0055a252` non-function endpoint, and `0x0055a260` `ScreenEffecter` successor. This supports exact-child ownership rather than a single aggregate parent.

## Supervisor-Applied Shared-File Updates

- The supervisor applied and validated the Batch C001-012 `by-memory/-coverage-report.md` replacement row for [UID:0001GA][ScreenDimmerAndFadeOut](../../../../by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md) on 2026-06-12.
- No Batch C001-012 supervisor-owned shared-file rows remain pending.

## 2026-06-12 Agent-C001 Batch C001-013

- Changed docs: `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md`, `by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md`, and this notes file. No IDA database edits were applied.
- Score changes: [UID:0003FY] `86/92 -> 88/93`, parent remains blank because C001 live IDA reconfirmed refs from three FileDownloader helpers, MiniMapDownloader, and a raw MiniMap-side helper body. [UID:0000XO] score unchanged at `85/86`; it now records the raw `0x00454e30-0x00455040` WinINet helper as a support caveat.
- Evidence summary: C001 live IDA MCP on session `b001_nexustk` reconfirmed `xrefs_to 0x0060d7e0` at `0x0041a773`, `0x0041aa3b`, `0x0041ae5b`, `0x00453ac3`, and raw `0x00454e52`; confirmed no refs to `0x0060d7e4`/`0x0060d7f2`; confirmed `0x0060d7f4` successor refs are only the two minimap download helpers; and resolved raw `0x00454e52` as `push offset szAgent` inside unmodeled helper body `0x00454e30-0x00455040`.

## Supervisor-Applied Shared-File Updates

- The supervisor applied and validated the Batch C001-013 `by-memory/-coverage-report.md` replacement row for [UID:0003FY][SharedDownloaderUserAgentWideString](../../../../by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md) on 2026-06-12.
- No Batch C001-013 supervisor-owned shared-file rows remain pending.

## 2026-06-12 Agent-C001 Batch C001-014

- Changed docs: `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md` and this notes file. No IDA database edits were applied.
- Score changes: [UID:0003G1] `87/92 -> 88/93`, parent remains blank. Candidate owners [UID:0000JC][FileDownloader](../../../../by-file/FileDownloader.md), [UID:000051][FittingRoomDialogItemState](../../../../by-class/FittingRoomDialogItemState.md), [UID:0000JE][FittingRoom](../../../../by-file/FittingRoom.md), and [UID:0000O5][StartupWindow](../../../../by-file/StartupWindow.md) clear `85/85`, but the literal is genuinely shared across those source families.
- Evidence summary: C001 live IDA MCP on session `b001_nexustk` reconfirmed exactly three `xrefs_to 0x0060d94c`: `0x0041ad2e` in `sub_41AA00`, `0x004227c6` in `sub_422740`, and `0x00580cab` in `sub_580870`; confirmed no refs to `0x0060d954`; confirmed `0x0060d958` is the successor `itemshop.json` URL with separate ref `0x0041ae84`; and `analyze_component` reported shared `aVersion` use by all three consumer functions.

## Supervisor-Applied Shared-File Updates

- The supervisor applied and validated the Batch C001-014 `by-memory/-coverage-report.md` replacement row for [UID:0003G1][SharedVersionJsonKey](../../../../by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) on 2026-06-12.
- No Batch C001-014 supervisor-owned shared-file updates remain pending.

## 2026-06-12 Agent-C001 Batch C001-015

- Changed docs: `by-memory/0x00619d2c-0x0061a3c8.ExchangeItemReadOnlyData.md`, renamed `by-memory/0x0061a260-0x0061a310.ExchangeMoneyEditControlPaneVtableData.md` to `by-memory/0x0061a260-0x0061a304.ExchangeMoneyEditControlPaneVtableData.md`, `by-class/ExchangeMoneyEditControlPane.md`, `by-resource/exchange-dialog-resources.md`, `by-resource/-coverage-report.md`, and this notes file.
- Score changes: [UID:00025A] `85/90 -> 87/92`, parent remains blank; [UID:0003BK] `85/90 -> 86/92`, parent remains [UID:00004T][ExchangeMoneyEditControlPane](../../../../by-class/ExchangeMoneyEditControlPane.md), range corrected `0x0061a260-0x0061a310 -> 0x0061a260-0x0061a304`; [UID:0001RA][exchange-dialog-resources](../../../../by-resource/exchange-dialog-resources.md) `78/88 -> 80/90`; [UID:00004T] unchanged `85/88`.
- Evidence summary: C001 live IDA MCP on session `b001_nexustk` used `entity_query(kind=names)`, `xrefs_to`, `get_bytes`, and `get_string` to reconfirm the ExchangeDialog/ExchangeItemListPane/AddItemDialog/MyItemListPane/AddItemWithCountDialog/MixItemDialog/AddMixingItemDialog/ExchangeAlertPane/ExchangeMoneyEditControlPane/callback-table sequence through `0x0061a3b0` and the `FieldMapPane` successor at `0x0061a3c8`. `get_bytes 0x0061a2f0 size 0x40` proved `DLGEXC1.PAL` begins at `0x0061a304`, so [UID:0003BK] ends after the tertiary vtable slot at `0x0061a300`; the apparent `XITEM.*` labels are interior substrings of byte-backed `MIXITEM.PAL`/`MIXITEM.EPF`.
- IDA database updates: none. I deliberately skipped IDA retyping/renaming for the stale interior `aXitemPal`/`aXitemEpf` labels because correcting string heads with `make_data`/undefine is broader than a low-risk naming-only fix.
- Validation: `python tools/validator.py --queue-timeout 120 --mode file --file by-memory/0x0061a260-0x0061a304.ExchangeMoneyEditControlPaneVtableData.md --apply` exited 0 with `ok: 1`, path update for UID `0003BK`, score updates, and UID-link rewrites; the same file-mode validator command exited 0 for `by-memory/0x00619d2c-0x0061a3c8.ExchangeItemReadOnlyData.md`, `by-class/ExchangeMoneyEditControlPane.md`, `by-resource/exchange-dialog-resources.md`, and `by-resource/-coverage-report.md`. Existing unrelated missing-ref warnings for UID `000257`/`0002ND` in `by-memory/-coverage-report.md` remained.

## Supervisor-Applied Shared-File Updates

- The supervisor applied and validated the Batch C001-015 `by-memory/-coverage-report.md` replacement rows for [UID:00025A][ExchangeItemReadOnlyData](../../../../by-memory/0x00619d2c-0x0061a3c8.ExchangeItemReadOnlyData.md) and [UID:0003BK][ExchangeMoneyEditControlPaneVtableData](../../../../by-memory/0x0061a260-0x0061a304.ExchangeMoneyEditControlPaneVtableData.md) on 2026-06-12.
- No Batch C001-015 supervisor-owned shared-file updates remain pending.

## 2026-06-12 Agent-C001 Batch C001-016

- Changed docs: `by-memory/0x0061aad4-0x0061b340.HelpItemHelpReadOnlyData.md`, `by-file/HelpPanes.md`, `by-file/-coverage-report.md`, and this notes file. No IDA database edits were applied.
- Score changes: [UID:00025G] `86/88 -> 88/91`, parent set to [UID:0000JU][HelpPanes](../../../../by-file/HelpPanes.md); [UID:0000JU][HelpPanes](../../../../by-file/HelpPanes.md) `90/80 -> 90/86`, clearing the strict direct-parent gate.
- Evidence summary: C001 live IDA MCP on session `b001_nexustk` used `entity_query(kind=names)`, `xrefs_to`, and `get_bytes` to reconfirm the HelpPane, SimpleHelpPane, SimpleHelpPane2, WillBeChangedItemPane, WillBeChangedSpellPane, and ItemHelpPane vtable sequence, all 21 vtable-head refs into HelpPanes-family executable clusters, byte-backed item-help literal heads and representative consumers, and the HierList successor boundary at `0x0061b340`/`0x0061b344`.
- IDA database updates: none. I deliberately skipped renaming/retyping the polluted `0x004c8b20` function label because the affected helper naming is outside this read-only-data target and is not a very safe C-agent IDA-only fix without a fuller method-level pass.
- Validation: `python tools/validator.py --queue-timeout 120 --mode file --file by-memory/0x0061aad4-0x0061b340.HelpItemHelpReadOnlyData.md --apply` exited 0 with `ok: 1`, score updates to `88/91`, `autogen_registry_update 00025G ... -> 0000JU`, and `autogen_report_update: 1`; the same file-mode validator command exited 0 for `by-file/HelpPanes.md` and `by-file/-coverage-report.md`.

## Supervisor-Applied Shared-File Updates

- The supervisor applied and validated the Batch C001-016 `by-memory/-coverage-report.md` replacement row for [UID:00025G][HelpItemHelpReadOnlyData](../../../../by-memory/0x0061aad4-0x0061b340.HelpItemHelpReadOnlyData.md) on 2026-06-12.
- No Batch C001-016 supervisor-owned shared-file updates remain pending.

## 2026-06-12 Agent-C001 Batch C001-017

- Changed docs: `by-memory/0x0061e8dc-0x0061e8fc.DialogCreatorVtableData.md`, new `by-memory/0x0061e8dc-0x0061e8ec.MerchantDialogCreatorVtableData.md`, new `by-memory/0x0061e8ec-0x0061e8fc.PursuitMessageDialogCreatorVtableData.md`, `by-file/TextMenuDialogs.md`, `by-file/MessageDialogs.md`, and this notes file. No IDA database edits were applied.
- Score/parent changes: [UID:0002SS] `89/92 -> 90/93`, `RECONSTRUCTABLE:TRUE -> FALSE`, parent remains blank as a split index; new [UID:0003IP][MerchantDialogCreatorVtableData](../../../../by-memory/0x0061e8dc-0x0061e8ec.MerchantDialogCreatorVtableData.md) is `88/93`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000OP][TextMenuDialogs](../../../../by-file/TextMenuDialogs.md); new [UID:0003IQ][PursuitMessageDialogCreatorVtableData](../../../../by-memory/0x0061e8ec-0x0061e8fc.PursuitMessageDialogCreatorVtableData.md) is `88/93`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000LA][MessageDialogs](../../../../by-file/MessageDialogs.md). [UID:0000OP] remains `90/86`; [UID:0000LA] remains `89/85`.
- Evidence summary: C001 live IDA MCP on session `b001_nexustk` used `entity_query`, `get_bytes`, `xrefs_to`, `decompile`, `disasm`, and `analyze_component` to verify the exact two vtable records. `MerchantDialogCreator` has refs at `0x00507ddc` and `0x0051034b`, and `sub_510320` calls `0x00517450`; `PursuitMessageDialogCreator` has refs at `0x00507e16` and `0x0051286b`, and `sub_512840` calls `0x0054c200`.
- IDA database updates: none. Existing decorated names were already correct, and no low-risk IDA-only naming/type fix was needed.
- Validation: `python tools/validator.py --queue-timeout 120 --mode file --file by-memory/0x0061e8dc-0x0061e8ec.MerchantDialogCreatorVtableData.md --apply` exited 0 and assigned UID `0003IP`; the same command exited 0 for `by-memory/0x0061e8ec-0x0061e8fc.PursuitMessageDialogCreatorVtableData.md`, `by-memory/0x0061e8dc-0x0061e8fc.DialogCreatorVtableData.md`, `by-file/TextMenuDialogs.md`, and `by-file/MessageDialogs.md`, resolving all TMP references.

## Supervisor-Applied Shared-File Updates

- The supervisor applied and validated the Batch C001-017 `by-memory/-coverage-report.md` replacement block for [UID:0002SS][DialogCreatorVtableData](../../../../by-memory/0x0061e8dc-0x0061e8fc.DialogCreatorVtableData.md) and child rows [UID:0003IP]/[UID:0003IQ] on 2026-06-12.
- No Batch C001-017 supervisor-owned shared-file updates remain pending.

## 2026-06-12 Agent-C001 Batch C001-018

- Changed docs: `by-memory/0x0061e908-0x0061eadc.MapPaneResourceStrings.md`, new exact children `by-memory/0x0061e908-0x0061e924.GameServerConfigNeighborhoodString.md`, `by-memory/0x0061e924-0x0061e964.MapPaneCachePathStringsAndSelectionMarker.md`, `by-memory/0x0061e964-0x0061e9fc.ProfileSidecarImageStrings.md`, `by-memory/0x0061e9fc-0x0061ea24.MapPaneUserFaceAssetPathStrings.md`, `by-memory/0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings.md`, `by-memory/0x0061ea70-0x0061eaa8.MapPaneRuntimeConfigWhitespaceStrings.md`, `by-memory/0x0061eaa8-0x0061eac0.VectorBoolTooLongRuntimeString.md`, `by-memory/0x0061eac0-0x0061ead4.MapPaneNumericConstants.md`, `by-memory/0x0061ead4-0x0061eadc.Md5HexFormatString.md`, `by-memory/0x0061e704-0x0061eb08.MapPaneGameServerReadOnlyData.md`, `by-file/GameServerConfig.md`, `by-class/GameServerConfig.md`, `by-file/MapPane.md`, `by-class/MapPane.md`, `by-file/ProfileStorage.md`, `by-file/MD5.md`, and this notes file. No IDA database edits were applied.
- Score/parent changes: [UID:0002ST] `87/91 -> 90/93`, `RECONSTRUCTABLE:TRUE -> FALSE`, parent remains blank as a split index; new [UID:0003IS] `88/93`, parent [UID:00005O][GameServerConfig](../../../../by-class/GameServerConfig.md); new [UID:0003IU] `88/92`, parent [UID:0000L3][MapPane](../../../../by-file/MapPane.md); new [UID:0003IV] `87/92`, parent [UID:0000MS][ProfileStorage](../../../../by-file/ProfileStorage.md); new [UID:0003IW] `86/91`, parent [UID:0000L3][MapPane](../../../../by-file/MapPane.md); new [UID:0003IX] `86/91`, parent blank; new [UID:0003IY] `86/90`, parent blank; new [UID:0003IZ] `88/92`, `RECONSTRUCTABLE:FALSE`; new [UID:0003J0] `86/90`, parent [UID:0000L3][MapPane](../../../../by-file/MapPane.md); new [UID:0003J1] `87/93`, parent [UID:0000L6][MD5](../../../../by-file/MD5.md). Parent docs kept existing scores.
- Evidence summary: C001 live IDA MCP on session `b001_nexustk` reconfirmed bytes and xrefs for the full `0x0061e908-0x0061eadc` span, separated `Neighborhood` to `GameServerConfig`, map-cache path and constants to `MapPane`, sidecar image literals to `ProfileStorage`, `/users/` `.epf` `.face` to raw MapPane-side path-building disassembly at `0x0050f620`, `%02x` to `Md5DigestToHexString`, and left shared Map/WorldMap plus runtime/config fragments parentless.
- IDA database updates: none. Existing labels were not changed; no C-agent low-risk IDA database fix was necessary.
- Validation: file-mode validator with `--queue-timeout 120 --apply` exited 0 for all nine new child pages, then for `by-memory/0x0061e908-0x0061eadc.MapPaneResourceStrings.md`, `by-memory/0x0061e704-0x0061eb08.MapPaneGameServerReadOnlyData.md`, `by-file/GameServerConfig.md`, `by-class/GameServerConfig.md`, `by-file/MapPane.md`, `by-class/MapPane.md`, `by-file/ProfileStorage.md`, and `by-file/MD5.md`. The target validation resolved 12 TMP references and updated [UID:0002ST] to non-reconstructable.

## Supervisor-Applied Shared-File Updates

- The supervisor applied and validated the Batch C001-018 `by-memory/-coverage-report.md` replacement block for [UID:0002ST][MapPaneResourceStrings](../../../../by-memory/0x0061e908-0x0061eadc.MapPaneResourceStrings.md) and child rows [UID:0003IS]-[UID:0003J1] on 2026-06-12.
- No Batch C001-018 supervisor-owned shared-file updates remain pending.

## 2026-06-12 Agent-C001 Batch C001-019

- Changed docs: `by-memory/0x00630edc-0x0063104c.UserStatusMenuResourceStrings.md`, new exact children `by-memory/0x00630edc-0x00630f8c.UserStatusPaneResourceStrings.md` and `by-memory/0x00630f8c-0x0063104c.MenuVarietyResourceAndLabelStrings.md`, `by-memory/0x00630c06-0x0063104c.UserStatusMenuReadOnlyData.md`, `by-file/UserStatusPane.md`, `by-file/MenuVarietyPanes.md`, and this notes file.
- Score/parent changes: [UID:0002Z4] `87/91 -> 90/93`, `RECONSTRUCTABLE:TRUE -> FALSE`, parent remains blank as a split index; new [UID:0003JC] `88/93`, parent [UID:0000P2][UserStatusPane](../../../../by-file/UserStatusPane.md); new [UID:0003JD] `88/93`, parent [UID:0000L8][MenuVarietyPanes](../../../../by-file/MenuVarietyPanes.md); [UID:00026Y] confidence `92 -> 93`, completion remains `90`; file parents kept existing scores.
- Evidence summary: C001 live IDA MCP on session `b001_nexustk` used `get_bytes`, `xrefs_to`, and decompilation to verify the full UTF-16 literal run from `USERSTAT.EPF` through `Quit`, the `0x00630f8c` owner switch, status-only xrefs into `0x005b8c70`/`0x005baf80`/`0x005be520`, menu-only xrefs into `0x005bc800`/`0x005bc970`, and the `0x0063104c` `VideoPlayerPane` successor.
- IDA database updates: none. Existing labels were sufficient, and no C-agent low-risk IDA database fix was necessary.
- Validation: file-mode validator with `--queue-timeout 120 --apply` exited 0 for both new child pages, then for `by-memory/0x00630edc-0x0063104c.UserStatusMenuResourceStrings.md`, `by-memory/0x00630c06-0x0063104c.UserStatusMenuReadOnlyData.md`, `by-file/UserStatusPane.md`, `by-file/MenuVarietyPanes.md`, and both child pages again. The target validation replaced four TMP refs and updated [UID:0002Z4] to non-reconstructable. Validator reported unrelated stale registry entries for missing Exchange/ExceptionHandler memory files; C001 did not touch them.

## Supervisor-Applied Shared-File Updates

- The supervisor applied and validated the Batch C001-019 `by-memory/-coverage-report.md` replacement block for [UID:00026Y] through [UID:0002Z4] on 2026-06-12.
- No Batch C001-019 supervisor-owned shared-file updates remain pending.

## 2026-06-12 Agent-C001 Batch C001-020

- Changed docs: `by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md`, exact child pages `by-memory/0x0069b4a4-0x0069b4a8.g_pNewUserDialogPane2.md`, `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md`, `by-memory/0x0069b4ac-0x0069b4b0.g_pServerSelectPane.md`, `by-memory/0x0069b4b0-0x0069b4b4.g_pTransferServerDialog.md`, global parent pages `by-global/g_pNewUserDialogPane2.md`, `by-global/g_pNewCreateUserDialogPane.md`, `by-global/g_pServerSelectPane.md`, `by-global/g_pTransferServerDialog.md`, `by-global/-coverage-report.md`, and this notes file.
- Score/parent changes: [UID:00029W] `89/92 -> 90/93`, `RECONSTRUCTABLE:TRUE -> FALSE`, parent remains blank as a non-emitting mixed-owner index. [UID:0002X4], [UID:0002X8], and [UID:0002XN] each moved `86/88 -> 87/90`; [UID:0002XO] moved `86/89 -> 87/90`. Global parents [UID:0002X3], [UID:0002X7], [UID:0000S8], and [UID:0000SL] each moved `86/88 -> 87/90`; routing remains unchanged.
- Evidence summary: C001 live IDA MCP on session `b001_nexustk` used `get_bytes` to verify all-zero bytes over `0x0069b4a0-0x0069b4c8`, correcting stale `0xffffffff` notes for this neighborhood. `xrefs_to` reconfirmed predecessor count 6, target slot counts `6/6/7/20`, and successor count 6. Decompilation/xref evidence still ties each exact slot to its existing direct global owner, while the aggregate spans create-user, server-select, and transfer-server modules and should not emit source.
- IDA database updates: none. Existing IDA labels remain adequate; no C-agent low-risk database fix was needed.
- Validation: file-mode validator with `--lock-timeout 120 --apply` exited 0 for the aggregate, four exact child pages, four global parent pages, and `by-global/-coverage-report.md`. The aggregate validation updated [UID:00029W] to non-reconstructable in generated metadata.

## Supervisor-Applied Shared-File Updates

- The supervisor applied and validated the Batch C001-020 `by-memory/-coverage-report.md` replacement block for [UID:00029W] and children [UID:0002X4], [UID:0002X8], [UID:0002XN], and [UID:0002XO] on 2026-06-12.
- No Batch C001-020 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-12 Agent-C001 Batch C001-021

- Changed docs: `by-memory/0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings.md`, new exact child pages `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md`, `by-memory/0x0061ea30-0x0061ea48.MapPaneWorldMapNameComparisonStrings.md`, `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md`, `by-memory/0x0061ea50-0x0061ea70.MapPaneWorldMapNameThreeFourStrings.md`, parent/context pages `by-memory/0x0061e908-0x0061eadc.MapPaneResourceStrings.md`, `by-memory/0x0061e704-0x0061eb08.MapPaneGameServerReadOnlyData.md`, `by-file/MapPane.md`, `by-class/MapPane.md`, and this notes file. No IDA database edits were applied.
- Score/parent changes: [UID:0003IX] `86/91 -> 90/93`, `RECONSTRUCTABLE:TRUE -> FALSE`, parent remains blank as a non-emitting split index; new [UID:0003JG] `87/93`, parent blank; new [UID:0003JH] `88/93`, parent [UID:0000L3][MapPane](../../../../by-file/MapPane.md); new [UID:0003JI] `87/93`, parent blank; new [UID:0003JJ] `88/93`, parent [UID:0000L3][MapPane](../../../../by-file/MapPane.md). Parent/context scores unchanged.
- Evidence summary: C001 live IDA MCP on session `b001_nexustk` reconfirmed exact bytes and decoded UTF-16 strings from `.PAL` through `WM4`; `xrefs_to` showed `.PAL` shared by MapPane `sub_510960` and WorldMapPane constructor-family `sub_5C2AC0`, `WM2` shared by MapPane `sub_511DB0` and WorldMapPane helper `sub_5C5200`, and the remaining `wm`/`WM`/`wm2`/`wm3`/`WM3`/`wm4`/`WM4` strings referenced only by MapPane `sub_511DB0`.
- IDA database updates: none. Existing IDA labels were adequate and no C-agent low-risk database fix was necessary.
- Validation: file-mode validator with `--lock-timeout 120 --apply` exited 0 for the target, four exact child pages, both by-memory parent/context pages, `by-file/MapPane.md`, and `by-class/MapPane.md`. Validator updated [UID:0003IX] generated metadata to non-reconstructable and accepted child UID references.

## Supervisor-Applied Shared-File Updates

- The supervisor applied and validated the Batch C001-021 `by-memory/-coverage-report.md` replacement rows for [UID:00025S][MapPaneGameServerReadOnlyData](../../../../by-memory/0x0061e704-0x0061eb08.MapPaneGameServerReadOnlyData.md), [UID:0002ST][MapPaneResourceStrings](../../../../by-memory/0x0061e908-0x0061eadc.MapPaneResourceStrings.md), [UID:0003IX][MapWorldPaletteResourceStrings](../../../../by-memory/0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings.md), and nested child rows [UID:0003JG]-[UID:0003JJ] on 2026-06-12.
- No Batch C001-021 supervisor-owned shared-file updates remain pending.

## 2026-06-12 Agent-C001 Goal 2 JsonCpp Barrier Crossing

- Changed docs: renamed `by-memory/0x0042ae90-0x0042edeb.JsonCppReaderBuilderIsland.md` to `by-memory/0x0042ae90-0x0042e850.JsonCppReaderAndBuilderPreludeIsland.md`, updated `by-memory/0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland.md`, and updated `by-memory/-ignored.md`. No IDA database edits were applied.
- Evidence summary: C001 live IDA MCP on session `a002_batch346` confirmed `sub_42E7B0` at `0x0042e7b0` size `0x78`, `sub_42E850` at `0x0042e850` size `0x59b`, `sub_42EE10` at `0x0042ee10` size `0x2d5`, `sub_42F110` at `0x0042f110` size `0x9a`, `sub_42F1B0` at `0x0042f1b0` size `0x240`, and `sub_42F3F0` at `0x0042f3f0` size `0x7`. `analyze_function 0x0042e7b0` showed the `Json::StreamWriterBuilder::vftable` store and call to `0x0042f1b0`; `make_signature_for_range 0x0042e828-0x0042e850` showed padding plus a short raw writer-builder vtable body before `sub_42E850`.
- Validation/report results: validator file mode with `--queue-timeout 180 --apply` succeeded for [UID:0000X2], [UID:0000X3], and `by-memory/-ignored.md`; the [UID:0000X2] pass updated the UID path and propagated active UID-link annotations, including `by-project-structure/proposed-source-tree.md`. `python tools/memory_ranges.py report` regenerated `auto-generated/by-memory-tool-report.md`; the JsonCpp `0x0042ae90-0x0042edeb` vs `0x0042e850-0x0042f3f0` barrier crossing is gone.

Supervisor-applied `by-memory/-coverage-report.md` update:

- The supervisor applied and validated the JsonCpp [UID:0000VN], [UID:0000X2], and [UID:0000X3] replacement rows on 2026-06-12.
- `memory_ranges.py report` was regenerated after the shared report edit; the stale `0x0042ae90-0x0042edeb` / `0x0042e850-0x0042f3f0` barrier crossing remains gone.
- No JsonCpp barrier-crossing supervisor-owned shared-file rows remain pending.

## 2026-06-12 Agent-C001 Goal 2 ApplicationLifecycle/BackPane Barrier Crossing

- Changed docs: renamed `by-memory/0x00463310-0x004679bf.ApplicationLifecycle.md` to `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`; updated `by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md`, `by-memory/0x00467960-0x004679bf.ApplicationSendShutdownMessage.md`, `by-memory/0x00467410-0x004674ed.LoadIndexedDATSeries.md`, `by-memory/-ignored.md`, `by-file/Application.md`, and `by-class/Application.md`. Validator propagated UID `0000YR` link updates across docs and refreshed validator-owned generated coverage files.
- Score/routing/range changes: [UID:0000YR] range changed `0x00463310-0x004679bf -> 0x00463310-0x004674ed`, score remains `85/88`, parent remains [UID:0000HG][Application](../../../../by-file/Application.md); [UID:0002GX][ApplicationSendShutdownMessage](../../../../by-memory/0x00467960-0x004679bf.ApplicationSendShutdownMessage.md) moved `76/84 -> 85/88`, remains directly under [UID:00000D][Application](../../../../by-class/Application.md), and is documented as physically interleaved inside the non-emitting BackPane mixed index rather than contained by [UID:0000YR]; [UID:0000YY] remains `86/89`, `RECONSTRUCTABLE:FALSE`, parent blank as the mixed BackPane/BackGroundPane index; [UID:0000YX] remains `90/94`; [UID:0000VN] gained ignored range evidence for `0x004674ed-0x00467510`.
- Evidence summary: C001 live IDA MCP on session `a002_batch346` reconfirmed `sub_467410` at `0x00467410`, size `0xdd`, exclusive end `0x004674ed`; bytes `0x004674ed-0x004674f0` are `cc cc cc`; `sub_4674F0` at `0x004674f0-0x00467501` decompiles to `InitializeCriticalSectionAndSpinCount(lpCriticalSection, dwSpinCount)` and has only runtime/STL caller `0x005c8b9d`; bytes `0x00467501-0x00467510` are `0xcc`; `sub_467510` starts BackGroundPane code; `sub_467830` is BackPane construction/destruction; `sub_467960` is the exact Application shutdown-message helper called from `0x00504a7e`; and `sub_4679C0` resumes BackPane code. The original report pair was a true range/structure error, not defensible containment.
- IDA database updates: none. I made no IDA names/types/comments changes.
- Validation/report results: `python tools/validator.py --mode file --file by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md --apply` exited 0 with `ok: 1`, `path_update` for UID `0000YR`, `reference_source_path_update: 63`, and `uid_link_update: 85`. File-mode validator with `--apply` also exited 0 for `by-memory/-ignored.md`, `by-memory/0x00467410-0x004674ed.LoadIndexedDATSeries.md`, `by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md`, `by-memory/0x00467960-0x004679bf.ApplicationSendShutdownMessage.md`, `by-file/Application.md`, and `by-class/Application.md`. `python tools/memory_ranges.py report` regenerated `auto-generated/by-memory-tool-report.md`; the `0x00463310-0x004679bf.ApplicationLifecycle` / `0x00467510-0x00467b2d.BackPaneAndBackGroundPane` barrier crossing is gone.

Supervisor-applied `by-memory/-coverage-report.md` update:

- The supervisor applied and validated the ApplicationLifecycle/BackPane replacement rows for [UID:0000YR], [UID:0000VN], [UID:0000YY], and nested [UID:0002GX] on 2026-06-12.
- Validation command: `python .\source-3\project-documentation\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240`.
- `python tools\memory_ranges.py report` was regenerated after the shared report edit; the stale `0x00463310-0x004679bf.ApplicationLifecycle` / `0x00467510-0x00467b2d.BackPaneAndBackGroundPane` barrier crossing remains gone.
- No ApplicationLifecycle/BackPane supervisor-owned shared-file rows remain pending.

## 2026-06-12 Agent-C001 Goal 2 ControlPane/ButtonChoice Barrier Crossing

- Changed docs: renamed `by-memory/0x004949e0-0x00494bf7.ControlPane.md` to `by-memory/0x004949e0-0x00494b50.ControlPaneAndProgressBarPrelude.md`; renamed `by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md` to `by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md`; updated `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`, `by-memory/-ignored.md`, `by-file/ButtonControlPane.md`, `by-class/RadioGroupControlPane.md`, `by-class/SliderControlPane.md`, and this notes file.
- Score/routing/range changes: [UID:000114] range changed `0x004949e0-0x00494bf7 -> 0x004949e0-0x00494b50`, score `82/86 -> 84/88`, remains non-reconstructable with parent blank as a physical prelude/index; [UID:000118] range changed `0x00494b50-0x00499e30 -> 0x00494eb0-0x0049803a`, score `76/86 -> 84/88`, parent cleared under the strict 85/85 gate; [UID:0002PD] score `74/86 -> 84/89`, parent cleared because the helper band is below the child 85 gate and still mixed-owner; [UID:0000VN] gained endpoint padding `0x0049803a-0x00498040`.
- Evidence summary: C001 live IDA MCP on session `a002_batch346` confirmed `sub_4949E0` at `0x004949e0-0x00494a81`, raw ProgressBar helpers at `0x00494a90`/`0x00494af0`, state helper starts at `0x00494b50` with exact ControlPane accessor `0x00494bf0-0x00494bf7` inside that band, ProgressBar constructor at `0x00494c80`, ButtonControlPane core start at `0x00494eb0`, Slider tail through `sub_498000` ending `0x0049803a`, six `0xcc` bytes at `0x0049803a-0x00498040`, and `PopupMenuControlPane` constructor start at `0x00498040`. `analyze_function 0x00498170` and `0x00498180` decompiled as tiny MenuPane forwarders, rejecting the stale RadioGroup later-helper claim.
- IDA database updates: none. I made no IDA names/types/comments changes.
- Validation/report results: file-mode validator with `--queue-timeout 180 --apply` exited 0 for `by-memory/0x004949e0-0x00494b50.ControlPaneAndProgressBarPrelude.md`, `by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md`, `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`, `by-class/RadioGroupControlPane.md`, `by-class/SliderControlPane.md`, `by-file/ButtonControlPane.md`, and `by-memory/-ignored.md`. The validators propagated UID path updates from retired filenames. `python tools/memory_ranges.py report` regenerated `auto-generated/by-memory-tool-report.md`; the target ControlPane/ButtonChoice crossings are gone. Remaining barrier crossings in the refreshed report begin at `0x00498040` PopupMenu/StaticText and are outside this root range issue.

Supervisor-applied `by-memory/-coverage-report.md` update:

- The supervisor applied and validated the Goal 2 ControlPane/ButtonChoice replacement/move/insert rows for [UID:000114], [UID:000118], [UID:0002PD], and the [UID:0000VN] `0x0049803a-0x00498040` padding row on 2026-06-12.
- Validation command: `python .\source-3\project-documentation\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240`.
- `python tools\memory_ranges.py report` was regenerated after the shared report edit; the stale ControlPane/ButtonChoice barrier crossing remains gone.
- No ControlPane/ButtonChoice supervisor-owned shared-file rows remain pending.

## 2026-06-12 Agent-C001 Goal 2 Popup/EPF/Numeric/Rectangle Barrier Crossing

- Changed docs: renamed [UID:00011F] to `by-memory/0x00498040-0x00498599.PopupMenuControlPaneCore.md`, [UID:00011J] to `by-memory/0x004991f0-0x004993a5.EPFImageControlPaneCore.md`, [UID:000123] to `by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md`, [UID:00011M] to `by-memory/0x00499910-0x00499be7.NumericStringControlPaneCore.md`, and [UID:00011Q] to `by-memory/0x00499c60-0x00499d37.RectangleControlPaneCore.md`. Created exact children [UID:0003LM][PopupMenuControlPaneTypeId](../../../../by-memory/0x0049b8e0-0x0049b8e5.PopupMenuControlPaneTypeId.md), [UID:0003LN][EPFImageControlPaneAdjustorThunks](../../../../by-memory/0x0049af53-0x0049af69.EPFImageControlPaneAdjustorThunks.md), [UID:0003LO][EPFImageControlPaneScalarDeletingDestructor](../../../../by-memory/0x0049b1b0-0x0049b24f.EPFImageControlPaneScalarDeletingDestructor.md), and [UID:0003LP][FunctionObjectScalarDeletingDestructor](../../../../by-memory/0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor.md). Updated related class/file/type/meta/index docs and `by-memory/-ignored.md`.
- Score/routing/range changes: [UID:00011F] `82/88 -> 86/90`, range `0x00498040-0x0049b8e5 -> 0x00498040-0x00498599`, parent remains [UID:0000AN]; [UID:00011J] `84/88 -> 86/90`, range `0x004991f0-0x0049b24f -> 0x004991f0-0x004993a5`, parent remains [UID:00004G]; [UID:00004G] `84/86 -> 85/87`; [UID:0000J2] `84/84 -> 85/85`; [UID:000123] `80/86 -> 84/88`, range `0x0049b090-0x0049b28e -> 0x0049b090-0x0049b0ce`, parent cleared under strict gate; [UID:00011M] endpoint `0x00499be6 -> 0x00499be7`, score unchanged `86/90`; [UID:00011Q] endpoint `0x00499d36 -> 0x00499d37`, score `82/88 -> 85/90`.
- Evidence summary: C001 IDA MCP evidence from session `a002_batch346` confirmed Popup core successor `0x004985a0`, EPF core successor `0x004993b0`, exact EPF destructor support `0x0049af53-0x0049af69`/`0x0049b1b0-0x0049b24f`, FunctionObject exact bodies `0x0049b090-0x0049b0ce` and `0x0049b250-0x0049b28e`, NumericString/Rectangle old endpoints inside their render/paint functions, and padding spans `0x00498599-0x004985a0`, `0x004993a5-0x004993b0`, `0x00499be7-0x00499bf0`, `0x00499d37-0x00499d40`, and `0x0049b8e5-0x0049b8f0`.
- IDA database updates: none. I made no IDA names/types/comments changes.
- Validation/report results: targeted file-mode validator with `--apply` exited 0 for the changed by-memory files, assigned UIDs `0003LM`-`0003LP`, and a second targeted pass validated 32 affected reference docs. `python tools/memory_ranges.py report` regenerated `auto-generated/by-memory-tool-report.md`; the PopupMenu/StaticText2, EPF/StaticText2, EPF/ButtonChoice, EPF/FunctionObject, NumericString, and Rectangle barrier crossings are gone. The refreshed first remaining barrier is the separate `TextEditControlPaneCore` / `StaticTextControlPane` crossing.

Supervisor-applied shared-file updates:

- The supervisor applied and validated the Goal 2 Popup/EPF/Numeric/Rectangle `by-memory/-coverage-report.md` replacement/insert block for [UID:00011F], [UID:00011J], [UID:00011M], [UID:00011Q], [UID:000123], new child rows [UID:0003LM]-[UID:0003LP], and padding rows on 2026-06-12.
- Validation command: `python .\source-3\project-documentation\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240`.
- `python tools\memory_ranges.py report` was regenerated after the shared report edit; the PopupMenu/StaticText2, EPF/StaticText2, EPF/ButtonChoice, EPF/FunctionObject, NumericString, and Rectangle barrier crossings remain gone.
- No Goal 2 Popup/EPF/Numeric/Rectangle supervisor-owned shared-file rows remain pending.

## 2026-06-12 Agent-C001 Goal 2 TextEdit/StaticText Barrier Crossing

- Changed docs: renamed [UID:00011H] to `by-memory/0x004988d0-0x00498dd0.TextEditControlPaneCore.md`; renamed [UID:00011I] to `by-memory/0x00499030-0x004991ec.StaticTextControlPaneConstructor.md`; created [UID:0003LQ][TextControlSharedStateAndBorderHelpers](../../../../by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md); updated `by-memory/-ignored.md`, `by-class/TextEditControlPane.md`, `by-file/TextEditControlPane.md`, `by-class/StaticTextControlPane.md`, `by-file/StaticTextControlPane.md`, `by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder.md`, `by-memory/0x0049b6c0-0x0049b731.TextEditControlPaneDestructor.md`, `by-memory/0x0049b920-0x0049b925.StaticTextControlPaneTypeId.md`, `by-item/EncodeTextEditState_0058E490.md`, `by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md`, and this notes file.
- Score/routing/range changes: [UID:00011H] range `0x004988d0-0x00499020 -> 0x004988d0-0x00498dd0`, score `84/90 -> 86/90`, parent remains [UID:0000EM][TextEditControlPane](../../../../by-class/TextEditControlPane.md); new [UID:0003LQ] `85/89`, `RECONSTRUCTABLE:TRUE`, parent blank by design because the helper band is shared by TextEdit, StaticText, and ExchangeMoneyEdit vtables; [UID:00011I] range `0x00498dd0-0x004991ec -> 0x00499030-0x004991ec`, score `85/86 -> 86/88`, parent changed from file [UID:0000O8] to direct class [UID:0000E3]; [UID:0000E3][StaticTextControlPane](../../../../by-class/StaticTextControlPane.md) `82/84 -> 85/86`, parent remains [UID:0000O8].
- Evidence summary: C001 live IDA MCP on session `a002_batch346` confirmed TextEdit-local function boundaries through `0x00498dc8`, shared helper functions at `0x00498dd0`, `0x00498e10`, `0x00498e60`, `0x00498ed0`, and `0x00498f50`, StaticText constructor `sub_499030` at `0x00499030` size `0x1bc`, vtable names for TextEdit (`0x00618100`/`0x00618168`/`0x00618198`), StaticText (`0x006181a4`/`0x0061820c`/`0x0061823c`), and ExchangeMoneyEdit (`0x0061a264`/`0x0061a2cc`), shared helper data refs at `0x00618144-0x00618200` and `0x0061a2a8-0x0061a2bc`, and padding bytes `0x00498dc8-0x00498dd0` and `0x00499021-0x00499030`.
- IDA database updates: none. Existing IDA labels remain adequate; no C-agent low-risk database fix was necessary.
- Validation/report results: `python tools/validator.py --queue-timeout 180 --mode file --file by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md --apply` assigned UID `0003LQ` and exited 0; targeted file-mode validation with `--apply` exited 0 for both renamed memory pages, related class/file/reference pages, and `by-memory/-ignored.md`; final revalidation of [UID:0003LQ] exited 0 with `ok: 1` and no missing-ref/TMP warnings. `python tools/memory_ranges.py report` regenerated `auto-generated/by-memory-tool-report.md`; the stale `0x004988d0-0x00499020.TextEditControlPaneCore` / `0x00498dd0-0x004991ec.StaticTextControlPane` barrier crossing is gone, and the first remaining barrier is now EventObjects/EventMan.

Supervisor-applied `by-memory/-coverage-report.md` update:

- The supervisor applied and validated the Goal 2 TextEdit/StaticText replacement block for [UID:00011H], [UID:0003LQ], padding rows, and [UID:00011I] on 2026-06-12.
- Validation command: `python .\source-3\project-documentation\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240`.
- No Goal 2 TextEdit/StaticText supervisor-owned shared-file rows remain pending.

## 2026-06-12 Agent-C001 Goal 2 EventObjects/EventMan Barrier Crossing

- Changed docs: renamed [UID:00014B] to `by-memory/0x004a8a90-0x004a8abf.EventBaseConstructorDestructor.md`; renamed [UID:00014C] to `by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md`; created [UID:0003LU][EventScalarDeletingDestructor](../../../../by-memory/0x004ab3f0-0x004ab435.EventScalarDeletingDestructor.md) and [UID:0003LV][EventManScalarDeletingDestructor](../../../../by-memory/0x004ab440-0x004ab476.EventManScalarDeletingDestructor.md); updated `by-memory/-ignored.md`, `by-class/Event.md`, `by-class/EventMan.md`, `by-file/Event.md`, `by-file/EventDispatcher.md`, `by-class/Pane.md`, `by-memory/0x004a8970-0x004a8a84.EventHandlerBase.md`, `by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md`, `by-memory/0x006196a0-0x006196b0.EventVtableData.md`, `by-memory/0x006196b0-0x006196bc.EventManVtableData.md`, `by-memory/0x0066d888-0x0066da88.EventManKeyTranslationTables.md`, `by-memory/0x0067a754-0x0067a758.g_pEventMan.md`, and `by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md`.
- Score/routing/range changes: [UID:00014B] range `0x004a8a90-0x004ab434 -> 0x004a8a90-0x004a8abf`, score `84/88 -> 86/90`, parent changed from [UID:0000J6][Event](../../../../by-file/Event.md) to direct [UID:00004L][Event](../../../../by-class/Event.md); [UID:00014C] range `0x004a8b40-0x004ab476 -> 0x004a8ac0-0x004ab3eb`, score remains `86/88`, parent remains [UID:0000J6][Event](../../../../by-file/Event.md) because the island is mixed Event.cpp source-module code; new [UID:0003LU] `86/90`, parent [UID:00004L][Event](../../../../by-class/Event.md); new [UID:0003LV] `86/90`, parent [UID:00004O][EventMan](../../../../by-class/EventMan.md); [UID:0000VN] gained padding entries for `0x004a8abf-0x004a8ac0`, `0x004ab3eb-0x004ab3f0`, and `0x004ab435-0x004ab440`, and label updates for the adjacent padding rows.
- Evidence summary: C001 live IDA MCP on session `a002_batch346` confirmed `0x004a8a90` size `0x20`, `0x004a8ab0` size `0x0f`, helper starts from `0x004a8ac0` through `0x004a8b20`, EventMan constructor `0x004a8b40-0x004a8f13`, the mixed EventMan/free-helper/event-record island through `0x004ab3e0-0x004ab3eb`, Event scalar deleting destructor `0x004ab3f0-0x004ab435`, and EventMan scalar deleting destructor `0x004ab440-0x004ab476`. `xrefs_to` confirmed `0x004ab3f0` from Event vtable slot `0x006196a4` and `0x004ab440` from EventMan vtable slot `0x006196b4`; raw signatures confirmed padding bytes at `0x004a8abf-0x004a8ac0`, `0x004ab3eb-0x004ab3f0`, `0x004ab435-0x004ab440`, and `0x004ab476-0x004ab480`. The reported overlap was a true range/structure problem, not defensible containment.
- IDA database updates: none. I made no IDA names/types/comments changes.
- Validation/report results: targeted file-mode validator with `--queue-timeout 180 --apply` exited 0 for the renamed memory pages, new destructor pages, related class/file/reference pages, and `by-memory/-ignored.md`; it assigned [UID:0003LU] and [UID:0003LV] and updated the validator UID paths for [UID:00014B]/[UID:00014C]. `python tools/memory_ranges.py report` regenerated `auto-generated/by-memory-tool-report.md`; the stale EventObjects/EventMan barrier crossing is gone, and the first remaining barrier is now the ImageLib family cluster beginning with `0x004cffb0-0x004e6572.ImageLib.md`.

Supervisor-applied `by-memory/-coverage-report.md` update:

- The supervisor applied and validated the Goal 2 EventObjects/EventMan replacement block for [UID:00014B], [UID:00014C], [UID:0003LU], [UID:0003LV], and adjacent padding rows on 2026-06-12.
- Validation command: `python .\source-3\project-documentation\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240`.
- No Goal 2 EventObjects/EventMan supervisor-owned shared-file rows remain pending.

## 2026-06-12 Agent-C001 Goal 2 ImageLib Barrier Cluster

- Changed docs: renamed [UID:000172] to `by-memory/0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md`; [UID:000177] to `by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md`; [UID:00017A] to `by-memory/0x004d2720-0x004dac40.HumanImageLibLocalMethodCluster.md`; [UID:00017C] to `by-memory/0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster.md`; [UID:00017H] to `by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md`; [UID:00017K] to `by-memory/0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster.md`; [UID:00017N] to `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md`; [UID:00017P] to `by-memory/0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster.md`; and [UID:00017R] to `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`. Created [UID:0003LZ][LightInfoTableLoader](../../../../by-memory/0x004df500-0x004df668.LightInfoTableLoader.md), [UID:0003M0][HumanImageLibScalarDeletingDestructor](../../../../by-memory/0x004e6460-0x004e649b.HumanImageLibScalarDeletingDestructor.md), [UID:0003M1][MonsterImageLibScalarDeletingDestructor](../../../../by-memory/0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor.md), and [UID:0003M2][StaticObjImageLibScalarDeletingDestructor](../../../../by-memory/0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor.md). Updated the nine corresponding by-file pages and nine by-class pages.
- Score/routing/range changes: the nine broad ImageLib-family aggregate pages are now `RECONSTRUCTABLE:FALSE`, parent blank, and narrowed to contiguous local ranges. Scores are [UID:000172] `80/88`, [UID:000177] `83/89`, [UID:00017A] `78/88`, [UID:00017C] `84/90`, [UID:00017H] `85/90`, [UID:00017K] `85/89`, [UID:00017N] `78/88`, [UID:00017P] `83/89`, and [UID:00017R] `78/88`. New exact pages are [UID:0003LZ] `76/86`, [UID:0003M0] `82/90`, [UID:0003M1] `82/90`, and [UID:0003M2] `82/90`, all parent blank under the strict gate or compiler-wrapper ownership caveat.
- Evidence summary: C001 live IDA MCP on session `a002_batch346` showed the original broad ranges were true mixed-range errors, not defensible containment: ImageLib local lifecycle ends at `0x004d011b`; MapTile local methods end before ObjectStatusBlob at `0x004d1f30`; Human local code ends at Monster start `0x004dac40`; Monster local code ends at Riding start `0x004dc420`; Static/Effect/Item/Light/NewHuman local neighborhoods have separate starts and ends; `0x004df500-0x004df668` is an independent LightInfo table-loader function; and scalar deleting destructors at `0x004e6460-0x004e649b`, `0x004e6750-0x004e6860`, and `0x004e6990-0x004e6aa6` are exact standalone vtable-referenced compiler wrappers.
- IDA database updates: none. Existing IDA evidence was sufficient; no names/types/comments were changed.
- Validation/report results: targeted file-mode validator with `--queue-timeout 180 --apply` exited 0 for the 13 by-memory pages and the 18 related by-file/by-class pages; validator assigned [UID:0003LZ], [UID:0003M0], [UID:0003M1], and [UID:0003M2] and updated moved UID paths. `python tools/memory_ranges.py report` regenerated `auto-generated/by-memory-tool-report.md`; the ImageLib barrier cluster beginning at `0x004cffb0-0x004e6572.ImageLib.md` crossing `0x004d1860-0x004e6748.MapTileImageLib.md` is gone. The only ImageLib-family mention remaining in that report is a Largest-Ranges advisory for non-emitting [UID:00017A], not a barrier crossing.

Supervisor-applied `by-memory/-coverage-report.md` update:

Applied by supervisor on 2026-06-12 in the ImageLib-family section; validator passed with `ok: 1`. The stale top-level rows for [UID:000172], [UID:000177], [UID:00017A], [UID:00017C], [UID:00017H], [UID:00017K], [UID:00017N], [UID:00017P], and [UID:00017R] were replaced, scalar-deleting rows were moved out from under the old broad aggregate rows and kept top-level in address order, and new exact rows [UID:0003LZ], [UID:0003M0], [UID:0003M1], and [UID:0003M2] were inserted. No supervisor-owned `by-memory/-coverage-report.md` rows remain pending for this item. Applied row text is retained below for audit only.

`    - [UID:000172][0x004cffb0-0x004d011b.ImageLibLifecycleCluster](by-memory/0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md) 0x004cffb0-0x004d011b | class-method-cluster | ImageLibLifecycleCluster : ignored/non-emitting : 80% : strong : Non-emitting local lifecycle cluster for ImageLib constructor/destructor code only; live IDA proved the previous broad range crossed MapTile/Human/Monster/Static/Item/Light/NewHuman sibling owners, so exact child pages carry reconstructable bodies and scalar deleting destructor is tracked separately.`

`    - [UID:000177][0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster](by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md) 0x004d1860-0x004d1f30 | class-method-cluster | MapTileImageLibLocalMethodCluster : ignored/non-emitting : 83% : strong : Non-emitting local MapTileImageLib cluster for constructor/destructor/draw/metadata helper neighborhood; live IDA proved the previous broad range crossed ObjectStatusBlob parsers and later image-library owners, so the scalar deleting destructor remains a separate exact page.`

`    - [UID:00017A][0x004d2720-0x004dac40.HumanImageLibLocalMethodCluster](by-memory/0x004d2720-0x004dac40.HumanImageLibLocalMethodCluster.md) 0x004d2720-0x004dac40 | class-method-cluster | HumanImageLibLocalMethodCluster : ignored/non-emitting : 78% : strong : Non-emitting old-human local method cluster ending at the MonsterImageLib boundary; exact constructor/destructor pages remain reconstructable, while raw composition islands still need later exact child audit before any source-level emission.`

`    - [UID:00017C][0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster](by-memory/0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster.md) 0x004dac40-0x004dc420 | class-method-cluster | MonsterImageLibLocalMethodCluster : ignored/non-emitting : 84% : strong : Non-emitting contiguous MonsterImageLib local cluster ending before RidingImageLib; live IDA proved the old broad range crossed StaticObjImageLib and NewHumanImageLib sibling owners, with the scalar deleting destructor now a separate exact page.`

`    - [UID:00017H][0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster](by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md) 0x004dcf60-0x004ddf60 | class-method-cluster | StaticObjImageLibLocalMethodCluster : ignored/non-emitting : 85% : strong : Non-emitting contiguous StaticObjImageLib local cluster; live IDA proved the old broad range crossed EffectObjImageLib, ItemObjImageLib, LightObjImageLib, and NewHumanImageLib, while the scalar deleting destructor is an exact standalone page.`

`    - [UID:00017K][0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster](by-memory/0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster.md) 0x004ddf60-0x004dec30 | class-method-cluster | EffectObjImageLibLocalMethodCluster : ignored/non-emitting : 85% : strong : Non-emitting contiguous EffectObjImageLib local cluster; exact child pages carry constructor/destructor/render/helper bodies, and the old broad range crossed ItemObjImageLib, LightObjImageLib, NewHumanImageLib, and scalar-destructor neighborhoods.`

`    - [UID:00017N][0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster](by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md) 0x004dec30-0x004df500 | class-method-cluster | ItemObjImageLibLocalMethodCluster : ignored/non-emitting : 78% : strong : Non-emitting contiguous ItemObjImageLib local cluster; live IDA split the independent 0x004df500 LightInfo table loader out instead of forcing it under Item or Light before direct ownership clears the strict gate.`

`    - [UID:0003LZ][0x004df500-0x004df668.LightInfoTableLoader](by-memory/0x004df500-0x004df668.LightInfoTableLoader.md) 0x004df500-0x004df668 | helper function | LightInfoTableLoader : reconstructable : 76% : strong : Exact IDA function sub_4DF500, size 0x168, loading a variable-count 0x14-byte image-library table into this+0x0c; no direct xrefs, likely LightObjImageLib context, parent blank until direct ownership clears the strict gate.`

`    - [UID:00017P][0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster](by-memory/0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster.md) 0x004df7e0-0x004dfd0a | class-method-cluster | LightObjImageLibLocalMethodCluster : ignored/non-emitting : 83% : strong : Non-emitting contiguous LightObjImageLib local cluster for constructor/destructor/bounds/draw methods; live IDA proved the old broad range crossed NewHumanImageLib and scalar-destructor neighborhoods.`

`    - [UID:00017R][0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster](by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md) 0x004dfd10-0x004e4d79 | class-method-cluster | NewHumanImageLibLocalMethodCluster : ignored/non-emitting : 78% : strong : Non-emitting contiguous NewHumanImageLib lower local cluster; later callback/vector/list/template/singleton/scalar helper neighborhoods are separate pages rather than part of a single reconstructable aggregate.`

`    - [UID:0003M0][0x004e6460-0x004e649b.HumanImageLibScalarDeletingDestructor](by-memory/0x004e6460-0x004e649b.HumanImageLibScalarDeletingDestructor.md) 0x004e6460-0x004e649b | scalar-deleting-destructor | HumanImageLibScalarDeletingDestructor : reconstructable : 82% : strong : Exact compiler-emitted HumanImageLib scalar deleting destructor; IDA confirms sub_4E6460 size 0x3b, ordinary-destructor call, optional delete path, and vtable slot xref at 0x0061b6d4.`

`    - [UID:0002IO][0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor](by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md) 0x004e64a0-0x004e6572 | scalar-deleting-destructor | ImageLib::ScalarDeletingDestructor : reconstructable : 78% : strong : Destructor cleanup plus compiler scalar-delete flag handling.`

`    - [UID:0002VC][0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor](by-memory/0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor.md) 0x004e6580-0x004e65dc | scalar-deleting-destructor | ItemObjImageLibScalarDeletingDestructor : reconstructable : 76% : strong : Live IDA confirms the vtable slot, protected-array entry free, singleton clear, base cleanup, delete flags, and trailing padding.`

`    - [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md) 0x004e65e0-0x004e669d | deleting destructor | LightObjImageLib scalar deleting destructor : reconstructable : 82% : strong : Virtual deleting wrapper over generated-frame cleanup; live IDA confirms exact 0xbd body, vtable-only ref at 0x0061b754, no direct callers, base/free/delete/guard callees, delete-flag branch, singleton clear, and three-byte cc padding.`

`    - [UID:0002J2][0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor](by-memory/0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md) 0x004e66a0-0x004e6748 | scalar-deleting-destructor | MapTileImageLib scalar deleting destructor : reconstructable : 82% : strong : Live IDA reconfirms the 0xa8 scalar deleting wrapper, vtable-slot-only xref, no direct callers, metadata/table/tile-record cleanup, g_pMapTileImageLib clear, LObject cleanup, deleting flag branches, class parent attachment, and source-declared/generated-binary rebuild handling.`

`    - [UID:0003M1][0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor](by-memory/0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor.md) 0x004e6750-0x004e6860 | scalar-deleting-destructor | MonsterImageLibScalarDeletingDestructor : reconstructable : 82% : strong : Exact compiler-emitted MonsterImageLib scalar deleting destructor; IDA confirms sub_4E6750 size 0x110, ordinary-destructor cleanup path, optional delete path, and vtable slot xref at 0x0061b6e4.`

`    - [UID:0002VN][0x004e6870-0x004e68a8.NewHumanImageLibScalarDeletingDestructor](by-memory/0x004e6870-0x004e68a8.NewHumanImageLibScalarDeletingDestructor.md) 0x004e6870-0x004e68a8 | scalar-deleting-destructor | NewHumanImageLib scalar deleting destructor : reconstructable : 82% : strong : Existing IDA-backed NewHumanImageLib docs confirm exact scalar-wrapper bounds, first vtable-slot reachability, ordinary-destructor call, optional delete through OperatorDeleteWrapper, guard-check branch, eight-byte post-wrapper padding, class/file ownership, class parent attachment, source-declared/generated-binary rebuild handling, and blank final C++ below the source gate.`

`    - [UID:0002Y4][0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor](by-memory/0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor.md) 0x004e68b0-0x004e6981 | scalar-deleting-destructor | RidingImageLib scalar deleting destructor : reconstructable : 85% : strong : Exact vtable-referenced deleting wrapper for RidingImageLib; split out of the old broad Riding range with ordinary-destructor call, protected-array cleanup, singleton clear, optional delete, and class parent attachment documented.`

`    - [UID:0003M2][0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor](by-memory/0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor.md) 0x004e6990-0x004e6aa6 | scalar-deleting-destructor | StaticObjImageLibScalarDeletingDestructor : reconstructable : 82% : strong : Exact compiler-emitted StaticObjImageLib scalar deleting destructor; IDA confirms sub_4E6990 size 0x116, cleanup/delete path, and vtable slot xref at 0x0061b704.`

## 2026-06-12 Agent-C001 Goal 2 MapPane/MapRefreshDimmer Barrier Crossing

- Completed docs: C001 split [UID:0001AW] to `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`, split [UID:0001B1] to `by-memory/0x00514920-0x00514a0d.MapRefreshDimmerMethods.md`, created exact destructor-glue pages [UID:0003M3], [UID:0003M4], [UID:0003M5], and [UID:0003M6], and updated the related MapPane/MapRefreshDimmer class/file/vtable docs plus `by-memory/-ignored.md`. No IDA database edits were applied.
- Supervisor applied the pending `by-memory/-coverage-report.md` MapPane/MapRefreshDimmer replacement block on 2026-06-13 and validated it with `python tools/validator.py --mode file --file by-memory/-coverage-report.md --apply --queue-timeout 240`; validator returned `ok: 1`.
- `python tools/memory_ranges.py report` was run after the split; the old `MapPanePacketHandlersAndDelete` / `MapRefreshDimmer` barrier crossing is gone. No supervisor-owned shared-file rows remain pending for this item.

## 2026-06-13 Agent-C001 Goal 2 MapPane/GameServer Crossing

- Changed docs: `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`, `by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md`, and this notes file. No IDA database edits were applied.
- Score/parent changes: [UID:0001AP] `76/82 -> 85/88`, parent [UID:0000L3][MapPane](../../../../by-file/MapPane.md) -> [UID:00007Q][MapPane](../../../../by-class/MapPane.md). [UID:0001AO] remains `88/92`, `RECONSTRUCTABLE:FALSE`, parent blank.
- Evidence summary: session-based IDA MCP on `a002_batch_clear_timer` reconfirmed raw/non-modeled GameServerConfig starts at `0x005039f0`, `0x00503a50`, and `0x00503b60`; modeled MapPane functions from `0x00503e80` onward; the `0x00503ef0-0x0050637a` MapPane aggregate interior; and the `0x00506380` successor boundary. The `memory_ranges.py` crossing is now documented as intentional overlap between a non-emitting mixed-owner index and a reconstructable MapPane class aggregate, not a range/split error.
- Validation: `python .\tools\validator.py --queue-timeout 180 --mode file --file by-memory\0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md --apply` exited `0`, `ok: 1`; initial run recorded completion/confidence updates, Low_Confidence stats row removal, and parent update `0000L3 -> 00007Q`. `python .\tools\validator.py --queue-timeout 180 --mode file --file by-memory\0x005039f0-0x00504521.GameServerNationAndMapInit.md --apply` exited `0`, `ok: 1`.
- `memory_ranges.py report` was not run because no memory ranges or filenames were changed.

Supervisor-applied `by-memory/-coverage-report.md` update:

- The supervisor applied and validated the Goal 2 MapPane/GameServer replacement rows for [UID:0001AO] and [UID:0001AP] on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240`; result `ok: 1`.
- The validator also reported a transient missing-ref warning for [UID:00022I] while Agent-A002's RectBounds task was actively renaming that file; no C001 rows remain pending.

## 2026-06-13 Agent-C001 Goal 2 MetaTable Barrier Crossing

- Changed docs: renamed [UID:0001CB] to `by-memory/0x00524630-0x00525914.MetaTable.md`; updated [UID:0001CD][MetaTableRowTreeHelpers](../../../../by-memory/0x00524d10-0x00525914.MetaTableRowTreeHelpers.md), [UID:000089][MetaTable](../../../../by-class/MetaTable.md), [UID:0000LC][MetaMan](../../../../by-file/MetaMan.md), and validator-refreshed UID annotations in related MetaMan/resource/padding support docs. No IDA database edits were applied.
- Score/routing/range changes: [UID:0001CB] range `0x00524630-0x005258f1 -> 0x00524630-0x00525914`, score `82/86 -> 85/88`, parent [UID:0000LC] -> [UID:000089]. [UID:0001CD] score `78/89 -> 85/90`, parent [UID:0000LC] -> [UID:000089]. [UID:000089] `85/86 -> 86/88`. [UID:0000LC] `88/85 -> 88/86`.
- Evidence summary: C001 live read-only IDA MCP on session `a002_batch_clear_timer` confirmed this was an intentional MetaTable aggregate/container relationship with a stale parent end range, not mixed ownership. `lookup_funcs`/`entity_query` showed all MetaTable functions/helpers through `sub_525900` at `0x00525900-0x00525914` and the next separate function at `0x00525920`; `xrefs_to` constrained helper entries to the MetaTable constructor/materializer/cleanup paths; `callees` confirmed materializer and cleanup dependencies; `get_bytes` confirmed `0x005258f1-0x00525900` and `0x00525914-0x00525920` are `0xcc`; `disasm` confirmed `sub_525830` initializes a 0x34-byte tree header and `sub_525900` ends with `retn 4`.
- Validation: `python .\tools\validator.py --queue-timeout 180 --mode file --file by-memory\0x00524630-0x00525914.MetaTable.md --apply` exited `0`, `ok: 1`, with path update for UID `0001CB`, completion/confidence updates, parent update `0000LC -> 000089`, and UID reference rewrites. A first child validation request timed out while queued; after the worker drained, the retry loop with `--queue-timeout 300` exited `0` and returned `ok: 1` for `by-memory\0x00524d10-0x00525914.MetaTableRowTreeHelpers.md`, `by-class\MetaTable.md`, `by-file\MetaMan.md`, `by-memory\0x005227d0-0x00524581.MetaMan.md`, `by-memory\0x00524590-0x005245b1.MetaManNodeDestroyHelper.md`, `by-memory\-ignored.md`, and `by-resource\meta-dat-metadata-cache.md`.
- Memory ranges: `python .\tools\memory_ranges.py report` exited `0` and rewrote `auto-generated/by-memory-tool-report.md`; the old [UID:0001CB]/[UID:0001CD] crossing is gone. The first remaining barrier crossing is now the existing [UID:0001AO]/[UID:0001AP] MapPane/GameServer intentional overlap, followed by unrelated Motion/Palette/etc. entries.
- Supervisor-applied `by-memory/-coverage-report.md` update:
  - The supervisor applied and validated the MetaTable replacement block for [UID:0001CB], [UID:0001CD], and the `0x00525914-0x00525920` padding row on 2026-06-13.
  - Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
  - No Goal 2 MetaTable supervisor-owned shared-file rows remain pending.

## 2026-06-13 Agent-C001 Goal 2 Motion/LivingObjectPane Barrier Crossing

- Changed docs: renamed [UID:0001DD] from `by-memory/0x00539bc0-0x0053d614.MotionAnimation.md` to `by-memory/0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster.md`; updated `by-class/Motion.md`, `by-file/Motion.md`, `by-file/Region.md`, exact Motion child/support pages `0x00539bc0-0x00539d43`, `0x00539de0-0x00539f52`, `0x00539fe0-0x0053a10c`, `0x0053d590-0x0053d614`, `0x0053ce50-0x0053ce8e`, `0x00620950-0x0062096c`, `0x0069b984-0x0069b9ac`, `by-memory/-ignored.md`, and this notes file.
- Score/routing/range changes: [UID:0001DD] range `0x00539bc0-0x0053d614 -> 0x00539bc0-0x0053a10c`, score `85/88 -> 86/90`, `RECONSTRUCTABLE:FALSE`, parent remains blank. Exact scalar destructor [UID:0002QZ] remains `88/92`, reconstructable, parent [UID:00008R][Motion](../../../../by-class/Motion.md). [UID:0001DE][LivingObjectPaneCore](../../../../by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md) and [UID:0001DL][ObjectPaneCompanionDestructors](../../../../by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md) were reviewed as aggregate/container overlaps and were not changed.
- Evidence summary: active read-only IDA MCP on session `a002_batch_clear_timer` confirmed the old Motion/Living crossing was a true range/structure error: `lookup_funcs` shows the contiguous Motion constructor/timer functions at `0x00539bc0-0x00539d43`, `0x00539de0-0x00539f52`, and `0x00539fe0-0x0053a10c`; `entity_query functions 0x00539bc0-0x0053d820` returned 98 modeled functions with dense non-Motion starts beginning at `0x0053a110`; `xrefs_to` reconfirmed Motion constructor/timer/destructor refs; and `get_bytes` confirmed `0xcc` padding at `0x0053a10c-0x0053a110`, `0x0053d589-0x0053d590`, `0x0053d614-0x0053d620`, `0x0053d65b-0x0053d660`, and `0x0053d818-0x0053d820`.
- IDA database updates: none. The evidence supported a documentation range repair, not a safe/extreme-confidence IDA rename/type/comment change.
- Validation: targeted file-mode validator with `--queue-timeout 300 --apply` exited `0`, `ok: 1` for the renamed [UID:0001DD] page, Motion class/file, Region file, exact Motion child/support pages, and `by-memory/-ignored.md`. The first scan recorded `path_update 0001DD`, completion/confidence updates, and UID reference refreshes.
- Memory ranges: `python .\tools\memory_ranges.py report` exited `0` and rewrote `auto-generated/by-memory-tool-report.md`; both prior Motion crossings are gone. The remaining first barrier is now the already-reviewed MapPane/GameServer pair, followed by unrelated Palette/Parcel/TextEdit/etc. entries.

Supervisor-applied `by-memory/-coverage-report.md` update:

- The supervisor applied and validated the Goal 2 Motion/LivingObjectPane replacement row for [UID:0001DD] on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- The validator reported a transient missing-ref warning for [UID:0002U7] while Agent-A003's DATIndexVector task was actively renaming that file; no C001 rows remain pending.

## 2026-06-13 Agent-C001 Goal 2 DLPalette/PaletteLib Barrier Crossing

- Changed docs: renamed [UID:0001E4] to `by-memory/0x00542ac0-0x00543149.DLPaletteMethodCluster.md`; renamed [UID:0001E6] to `by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md`; created [UID:0003MT] `by-memory/0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw.md`, [UID:0003MU] `by-memory/0x005443b0-0x00544411.DLPaletteScalarDeletingDestructor.md`, and [UID:0003MV] `by-memory/0x00544420-0x0054445b.PaletteLibScalarDeletingDestructor.md`; updated `by-class/DLPalette.md`, `by-class/PaletteLib.md`, `by-class/-coverage-report.md`, `by-file/Palette.md`, `by-file/PaletteLib.md`, `by-file/DATArchive.md`, `by-global/g_pPaletteLib.md`, `by-memory/-ignored.md`, and Palette/PaletteLib support pages that referenced the old broad ranges.
- Score/routing/range changes: [UID:0001E4] range `0x00542ac0-0x00544411 -> 0x00542ac0-0x00543149`, score `78/86 -> 86/89`, parent remains [UID:0000MA][Palette](../../../../by-file/Palette.md). [UID:0001E6] range `0x005431c0-0x0054445b -> 0x005431c0-0x005443ab`, score `82/86 -> 86/89`, parent [UID:0000MB][PaletteLib](../../../../by-file/PaletteLib.md) -> [UID:0000A1][PaletteLib](../../../../by-class/PaletteLib.md). New [UID:0003MT] is `85/88`, parent [UID:0000A1]. New [UID:0003MU] is `85/91`, parent [UID:00003Z][DLPalette](../../../../by-class/DLPalette.md). New [UID:0003MV] is `85/90`, parent [UID:0000A1]. [UID:00003Z] `82/86 -> 85/88`; [UID:0000A1] `84/82 -> 86/86`.
- Evidence summary: live read-only IDA MCP on session `a002_batch_clear_timer` confirmed a true stale range/structure error, not intentional aggregate overlap. `lookup_funcs` showed the contiguous DLPalette cluster ending at `sub_5430A0`/`0x00543149`, the modeled PaletteLib cluster from `0x005431c0` through constructor-unwind clear `0x005443a0-0x005443ab`, `sub_5443B0` as exact `DLPalette::ScalarDeletingDestructor` `0x005443b0-0x00544411`, and `sub_544420` as exact `PaletteLib::ScalarDeletingDestructor` `0x00544420-0x0054445b`. `get_bytes` confirmed padding at `0x00543149-0x00543150`, `0x005431b9-0x005431c0`, `0x005443ab-0x005443b0`, `0x00544411-0x00544420`, and `0x0054445b-0x00544460`. `disasm 0x00543150` revealed an unmodeled raw PaletteLib wide-name finder body ending at `0x005431b9`, correcting the prior assumption that `0x00543149-0x005431c0` was all padding.
- IDA database updates: none. The modeled destructor/function evidence was sufficient for documentation splits, but the raw `0x00543150-0x005431b9` helper has no current IDA function object or xrefs, so C001 did not make risky IDA function creation or rename/type updates.
- Validation: targeted `python .\tools\validator.py --queue-timeout 300 --mode file --file <path> --apply` scans exited `0`, `ok: 1` for all changed docs listed above. Key validator updates included `path_update` for [UID:0001E4] and [UID:0001E6], UID assignment for [UID:0003MT]/[UID:0003MU]/[UID:0003MV], parent update `0000MB -> 0000A1` for [UID:0001E6], and completion/confidence refreshes for [UID:00003Z] and [UID:0000A1]. `by-class/-coverage-report.md` validated with `ok: 1`. Validator still reports unrelated `autogen_registry_stale 0001MM by-memory/0x005b5b30-0x005b5b80.ThrowReallyInputPaneRawConstructor.md registered file is missing`.
- Memory ranges: `python .\tools\memory_ranges.py report` exited `0` and rewrote `auto-generated/by-memory-tool-report.md`; the DLPalette/PaletteLib crossing is gone. The first remaining barrier crossing in the regenerated report is the previously reviewed MapPane/GameServer pair.
- Stale-reference check: `rg` for the old DLPalette and PaletteLib filenames plus `TMP:` across `by-memory by-class by-file by-global by-item by-meta by-resource` returned no hits.

Supervisor-applied `by-memory/-coverage-report.md` update:

- The supervisor applied and validated the Goal 2 DLPalette/PaletteLib replacement block for [UID:0001E4], [UID:0003MT], [UID:0001E6], [UID:0003MU], [UID:0003MV], and associated padding rows on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 DLPalette/PaletteLib supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-13 Agent-C001 Goal 2 ScrollCollectionPane Barrier Crossing

- Changed docs: renamed [UID:0001GT] from `by-memory/0x00561db0-0x0056325b.ScrollCollectionPane.md` to `by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md`; updated [UID:0001GY][ScrollCollectionPaneClearHighlightRaw](../../../../by-memory/0x00563200-0x0056325c.ScrollCollectionPaneClearHighlightRaw.md), [UID:0000CG][ScrollCollectionPane](../../../../by-class/ScrollCollectionPane.md), [UID:0000NG][ScrollCollectionPane](../../../../by-file/ScrollCollectionPane.md), [UID:0000IC][CollectionPane](../../../../by-file/CollectionPane.md), related ScrollCollectionPane type docs, neighboring scrollbar memory docs, and this notes file.
- Score/routing/range changes: [UID:0001GT] range `0x00561db0-0x0056325b -> 0x00561db0-0x0056325c`, score `78/86 -> 85/88`, parent [UID:0000NG][ScrollCollectionPane file](../../../../by-file/ScrollCollectionPane.md) -> [UID:0000CG][ScrollCollectionPane class](../../../../by-class/ScrollCollectionPane.md). [UID:0001GY] score `74/86 -> 85/88`, parent [UID:0000NG] -> [UID:0000CG]. [UID:0000CG] remains `85/85` and satisfies the direct-parent gate.
- Evidence summary: live read-only IDA MCP on session `a002_batch_clear_timer` confirmed the crossing was a stale exclusive-end parent range, not mixed ownership. `lookup_funcs` showed no function at `0x00563200`, `0x0056325b`, or `0x0056325c`, and `sub_563260` at `0x00563260`; `get_bytes` showed `0x005631fd-0x00563200` padding, the 92-byte raw helper body, and `c3 cc cc cc cc` at `0x0056325b`; `insn_query` showed the raw helper's final `retn` at `0x0056325b`; xrefs/callee/decompile checks tied the helper to the class-local highlight/geometry/drag-scroll cluster.
- IDA database updates: none. The evidence supported documentation range/routing repair only; no safe IDA rename/type/function creation was applied.
- Validation: targeted `python .\tools\validator.py --queue-timeout 180 --mode file --file <path> --apply` scans returned `ok: 1` for the renamed parent, raw child, class/file parents, type docs, and related memory docs. `python .\tools\validator.py --queue-timeout 300 --mode documented --remove-missing --apply` returned `ok: 4707`.
- Memory ranges: `python .\tools\memory_ranges.py --advanced-scan report` exited `0` and rewrote `auto-generated/by-memory-tool-report.md`; the old [UID:0001GT]/[UID:0001GY] crossing is gone. The first remaining barrier entries are unrelated MapPane/GameServer and Parcel/TextEdit/Socket/etc. items.

Supervisor-applied `by-memory/-coverage-report.md` update:

- The supervisor applied and validated the Goal 2 ScrollCollectionPane replacement rows for [UID:0001GT] and [UID:0001GY] on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- `python .\tools\memory_ranges.py --advanced-scan report` was rerun after the supervisor row sync, and the old [UID:0001GT]/[UID:0001GY] crossing remains gone.
- No Goal 2 ScrollCollectionPane supervisor-owned shared-file rows remain pending.

## 2026-06-13 Agent-C001 Goal 2 Parcel Barrier Crossing

- The supervisor applied and validated the Goal 2 Parcel replacement rows for [UID:0001EH] and [UID:0001EP] on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- `python .\tools\memory_ranges.py --advanced-scan report` was rerun after the supervisor row sync; the Parcel crossing remains gone.
- No Goal 2 Parcel supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-13 Agent-C001 Goal 2 TextEditPaneScrollbarVariants/ScrollVolumePane Barrier Crossing

- Changed docs: renamed [UID:0001GJ] from `by-memory/0x0055d960-0x00565488.TextEditPaneScrollbarVariants.md` to `by-memory/0x0055d960-0x005654ec.TextEditPaneScrollbarVariants.md`; updated [UID:0001H2][ScrollVolumePane](../../../../by-memory/0x00564710-0x005654ec.ScrollVolumePane.md), [UID:0000ON][TextEditPane](../../../../by-file/TextEditPane.md), [UID:0000EO][TextEditPane](../../../../by-class/TextEditPane.md), `by-memory/-ignored.md`, and validator-refreshed UID annotations in related `ScrollPaneInputGeometryHelpers`, `ScrollPaneGetScrollPartRect`, `ScrollablePaneCore`, and `TextEditPaneInputNavigationAndWrap` pages. No IDA database edits were applied.
- Score/routing/range changes: [UID:0001GJ] range `0x0055d960-0x00565488 -> 0x0055d960-0x005654ec`, score `88/90 -> 89/91`, `RECONSTRUCTABLE:FALSE`, parent remains blank. [UID:0001H2] score `85/88 -> 86/89`, range/parent/reconstructable status unchanged: parent [UID:0000CO][ScrollVolumePane](../../../../by-class/ScrollVolumePane.md), `RECONSTRUCTABLE:TRUE`.
- Evidence summary: live read-only IDA MCP on session `a002_batch_clear_timer` confirmed this was a stale non-emitting parent-map endpoint, not wrong `ScrollVolumePane` ownership. `lookup_funcs` showed `sub_565360` at `0x00565360-0x00565488`, no function at `0x00565488` or `0x00565490`, and neighboring `ScrollablePane` thunks at `0x005654ec`/`0x005654f7`; `entity_query` found the 13 modeled `ScrollVolumePane` functions through `0x00565488`; `get_bytes` confirmed eight `0xcc` bytes at `0x00565488-0x00565490`, the exact 92-byte raw reset helper at `0x00565490-0x005654ec`, and thunk bytes beginning at `0x005654ec`; `xrefs_to` confirmed no xrefs to raw `0x00565490` and vtable data refs to the successor thunks.
- Validation: `python .\tools\validator.py --queue-timeout 300 --mode file --file by-memory\0x0055d960-0x005654ec.TextEditPaneScrollbarVariants.md --apply` exited `0`, `ok: 1`, with `path_update 0001GJ`, completion/confidence updates, and UID-link rewrites. Targeted validator runs also exited `0`, `ok: 1` for `by-memory\0x00564710-0x005654ec.ScrollVolumePane.md`, `by-file\TextEditPane.md`, `by-class\TextEditPane.md`, `by-memory\-ignored.md`, `by-memory\0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md`, `by-memory\0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md`, `by-memory\0x0055e660-0x0055f242.ScrollablePaneCore.md`, and `by-memory\0x00594040-0x00594e11.TextEditPaneInputNavigationAndWrap.md`.
- Memory ranges: `python .\tools\memory_ranges.py --advanced-scan report` exited `0` and rewrote `auto-generated/by-memory-tool-report.md`; the old [UID:0001GJ]/[UID:0001H2] barrier crossing is gone. The first remaining barrier is the already-reviewed MapPane/GameServer pair, followed by unrelated Socket/Sound/TextEditSupport/etc. entries.

Supervisor-applied `by-memory/-coverage-report.md` update:

- The supervisor applied and validated the Goal 2 TextEdit/ScrollVolume replacement rows for [UID:0001GJ] and [UID:0001H2] on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- `python .\tools\memory_ranges.py --advanced-scan report` was rerun after the supervisor row sync; the TextEditPaneScrollbarVariants/ScrollVolumePane crossing remains gone.
- No Goal 2 TextEdit/ScrollVolume supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-13 Agent-C001 Goal 2 Socket/STL Barrier Crossing

- Changed docs: renamed [UID:0001I1] from `by-memory/0x00575d90-0x005796c7.SocketTransportCore.md` to `by-memory/0x00575d90-0x005797ae.SocketTransportCore.md`; updated [UID:000245][StlTreeStringMapSupport](../../../../by-memory/0x00578f70-0x005797ae.StlTreeStringMapSupport.md), `by-memory/-ignored.md`, validator-refreshed UID annotations in related Socket/PacketTransform support docs, regenerated `auto-generated/by-memory-tool-report.md`, and this notes file.
- Classification/range changes: stale endpoint on a reviewed non-emitting aggregate/container. [UID:0001I1] range `0x00575d90-0x005796c7 -> 0x00575d90-0x005797ae`; score remains `88/92`; `RECONSTRUCTABLE:FALSE`, parent blank, no C++ unchanged. [UID:000245] range/score/status unchanged at `0x00578f70-0x005797ae`, `84/88`, `RECONSTRUCTABLE:FALSE`, parent blank.
- Evidence summary: read-only IDA MCP on session `a001_goal2_collectionpane2_thunk` confirmed no function at `0x005796c7`, STL/helper functions at `0x005796d0`, `0x005796f0`, `0x00579710`, `0x00579760`, and `0x00579780`, no function at `0x005797ae`, and the next function at `0x005797b0`. `make_signature_for_range` confirmed `0x005796c7-0x005796d0` is nine `CC` bytes and `0x005797ae-0x005797b0` is `CC CC`; `disasm 0x00579780` showed `sub_579780` returns at `0x005797ad`.
- IDA database updates: none. The evidence supported a documentation endpoint repair only; no safe/extreme-confidence IDA rename/type/comment change was needed.
- Validation: `python .\tools\validator.py --queue-timeout 300 --mode file --file by-memory\0x00575d90-0x005797ae.SocketTransportCore.md --apply` exited `0`, `ok: 1`, with `path_update 0001I1` and UID-link refreshes. The same command exited `0`, `ok: 1` for `by-memory\0x00578f70-0x005797ae.StlTreeStringMapSupport.md` and `by-memory\-ignored.md`.
- Memory ranges: `python .\tools\memory_ranges.py --advanced-scan report` exited `0` and rewrote `auto-generated/by-memory-tool-report.md`; the old Socket/STL barrier crossing is gone. The first remaining barrier is the previously reviewed MapPane/GameServer pair, followed by unrelated Sound/TextEdit/etc. entries.

Supervisor-applied `by-memory/-coverage-report.md` update:
- The supervisor applied and validated the Goal 2 [UID:0001I1] `SocketTransportCore` replacement row on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- `python .\tools\memory_ranges.py --advanced-scan report` was rerun after the supervisor row sync; the old Socket/STL barrier crossing remains gone.
- No Goal 2 Socket/STL supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-13 Agent-C001 Goal 2 SoundManager/SoundPathVector Barrier Crossing

- Changed docs: renamed [UID:0001I8] from `by-memory/0x005797b0-0x0057bc58.SoundManager.md` to `by-memory/0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster.md`; renamed [UID:0001IC] from `by-memory/0x0057b490-0x0057bc58.SoundManagerDriverAndDestructor.md` to `by-memory/0x0057b490-0x0057bf6e.SoundManagerDriverDestructorAndPathHelpers.md`; updated [UID:0001ID][SoundPathVector](../../../../by-memory/0x0057b860-0x0057bf6e.SoundPathVector.md), [UID:0000NV][SoundManager](../../../../by-file/SoundManager.md), [UID:0000DG][SoundManager](../../../../by-class/SoundManager.md), [UID:0000DI][SoundPathVector](../../../../by-class/SoundPathVector.md), validator-refreshed UID annotations in related docs, regenerated `auto-generated/by-memory-tool-report.md`, and this notes file.
- Score/routing/range changes: [UID:0001I8] range `0x005797b0-0x0057bc58 -> 0x005797b0-0x0057bf6e`, score `78/86 -> 85/88`, parent remains [UID:0000NV][SoundManager](../../../../by-file/SoundManager.md). [UID:0001IC] range `0x0057b490-0x0057bc58 -> 0x0057b490-0x0057bf6e`, score `82/86 -> 85/88`, parent remains [UID:0000NV]. [UID:0001ID] score `82/86 -> 85/88`, parent [UID:0000NV] -> [UID:0000DI][SoundPathVector](../../../../by-class/SoundPathVector.md). [UID:0000NV] remains `90/85`; [UID:0000DI] remains `85/86`; [UID:0000DG] remains `86/80`.
- Evidence summary: live read-only IDA MCP on session `a003_goal2_rtti_type_descriptors` confirmed this was a stale aggregate endpoint/parenting issue, not a true sibling crossing. `lookup_funcs`/`entity_query` show driver/callback helpers through `0x0057b853`, SoundPathVector/helper starts at `0x0057b860`, `0x0057b9a0`, `0x0057b9e0`, `0x0057bab0`, `0x0057bac0`, SoundManager deleting destructor `0x0057bb30-0x0057bc59`, and string/path/vector helper starts at `0x0057bc60`, `0x0057bce0`, `0x0057bd60`, `0x0057bd90`, `0x0057be60`, `0x0057bed0`, and `0x0057bf40`. Byte signatures confirmed padding at `0x0057b853-0x0057b860`, `0x0057b99a-0x0057b9a0`, `0x0057baa3-0x0057bab0`, `0x0057bab5-0x0057bac0`, `0x0057bb2a-0x0057bb30`, `0x0057bc59-0x0057bc60`, and `0x0057bf6e-0x0057bf70`.
- IDA database updates: none. The evidence supported documentation range/routing repair only; no safe/extreme-confidence IDA rename/type/function creation was needed.
- Validation: targeted `python .\tools\validator.py --queue-timeout 300 --mode file --file <path> --apply` scans exited `0`, `ok: 1` for the renamed aggregate pages, SoundPathVector memory page, SoundManager file/class pages, and SoundPathVector class page. Key validator updates included `path_update 0001I8`, `path_update 0001IC`, completion/confidence updates, and parent update for [UID:0001ID]. A final focused validation of [UID:0001IC] exited `0`, `ok: 1`.
- Memory ranges: `python .\tools\memory_ranges.py --advanced-scan report` exited `0` and rewrote `auto-generated/by-memory-tool-report.md`; the SoundManager/SoundPathVector barrier entries are gone. The remaining first barrier entries are unrelated GameServer/MapPane, SimpleUString/LObject, TextEdit, and MenuVariety items.

Supervisor-applied shared-file updates:

- The supervisor applied and validated the Goal 2 SoundManager/SoundPathVector replacement rows for [UID:0001I8], [UID:0001IC], and [UID:0001ID] on 2026-06-13.
- The supervisor also synced [UID:0000DI] `SoundPathVector` in `by-class/-coverage-report.md` from the class page's current `85/86` state.
- Validation commands:
  - `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 SoundManager/SoundPathVector supervisor-owned shared-file rows remain pending.

## 2026-06-13 Agent-C001 Goal 2 SimpleUString/LObject/StringBase Barrier Cluster

- Changed docs: renamed [UID:0001J2] from `by-memory/0x00583210-0x005845eb.SimpleUStringPointerBacked.md` to `by-memory/0x00583210-0x005832f0.StringBaseFormatConstructors.md`; renamed [UID:0001J3] from `by-memory/0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation.md` to `by-memory/0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md`; updated [UID:0002LO][StringBaseCompareWideLiteral](../../../../by-memory/0x005845b0-0x005845ec.StringBaseCompareWideLiteral.md), [UID:0000OA][StringBase](../../../../by-file/StringBase.md), [UID:0000D9][SimpleUString](../../../../by-class/SimpleUString.md), and [UID:0001J1][LObjectStringConstructionAndCow](../../../../by-memory/0x00582500-0x00583206.LObjectStringConstructionAndCow.md).
- Classification/range/score changes: [UID:0001J2] range `0x00583210-0x005845eb -> 0x00583210-0x005832f0`, score `80/86 -> 86/90`, `RECONSTRUCTABLE:TRUE -> FALSE`, parent `0000OA -> blank`; it is now a reviewed non-emitting aggregate over exact constructor children [UID:0002LJ] and [UID:0002LK]. [UID:0001J3] name/label changed from LObject to StringBase, score `82/84 -> 84/88`, `RECONSTRUCTABLE:TRUE -> FALSE`, parent `0000OA -> blank`; it is now a reviewed non-emitting aggregate/container whose exact child pages carry source ownership. [UID:0002LO], [UID:0000OA], [UID:0000D9], and [UID:0001J1] had cross-reference/evidence text updates only.
- Evidence summary: live read-only IDA MCP on session `a003_goal2_rtti_type_descriptors` confirmed `sub_583210` at `0x00583210-0x00583273`, `sub_583280` at `0x00583280-0x005832e3`, successor `sub_5832F0` at `0x005832f0`, compare child `sub_5845B0` at `0x005845b0-0x005845ec`, search/splice successor `sub_5845F0`, substring `sub_584D00` ending at `0x00584d7e`, and next `StringIter` function at `0x00584d80`. `entity_query` over `0x00583210-0x00584d80` listed the contiguous StringBase helper-family function inventory and showed the old [UID:0001J2] endpoint was stale aggregate metadata, not intentional crossing ownership.
- IDA database updates: none. The evidence supported documentation/range/classification cleanup only; no safe IDA rename/type/function edit was needed.
- Validation: targeted `python .\tools\validator.py --queue-timeout 600 --mode file --file <path> --apply` scans exited `0`, `ok: 1` for the two renamed memory pages, `StringBaseCompareWideLiteral`, `StringBase.md`, `SimpleUString.md`, and `LObjectStringConstructionAndCow`. `python .\tools\validator.py --queue-timeout 600 --mode documented --remove-missing --apply` also exited `0`.
- Memory ranges: `python .\tools\memory_ranges.py --advanced-scan report` exited `0` and rewrote `auto-generated/by-memory-tool-report.md`; the assigned `SimpleUStringPointerBacked` / `LObjectStringReleaseFormatAndMutation` / `StringBaseCompareWideLiteral` barrier entries are gone. The first remaining barriers are unrelated GameServer/MapPane, TextEdit/TextBox, MenuVariety, etc.

Supervisor-applied `by-memory/-coverage-report.md` replacement:

- The supervisor applied and validated the [UID:0001J2]/[UID:0001J3] replacement block in `by-memory/-coverage-report.md` on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- `python .\tools\memory_ranges.py --advanced-scan report` was rerun afterward; the SimpleUString/LObject/StringBase barrier entries are gone.
- No Goal 2 SimpleUString/LObject/StringBase supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

Applied row text retained for audit:

```text
    - [UID:0001J2][0x00583210-0x005832f0.StringBaseFormatConstructors](by-memory/0x00583210-0x005832f0.StringBaseFormatConstructors.md) 0x00583210-0x005832f0 | aggregate-container | StringBaseFormatConstructors : ignored : 86% : strong : Reviewed non-emitting aggregate/container for the two pointer-backed StringBase varargs constructor wrappers plus internal alignment padding; live IDA MCP on 2026-06-13 confirmed `sub_583210` at `0x00583210-0x00583273`, `sub_583280` at `0x00583280-0x005832e3`, and successor `sub_5832F0` at `0x005832f0`. Exact children carry reconstruction ownership.
        - [UID:0002LJ][0x00583210-0x00583273.StringBaseAnsiFormatCtor](by-memory/0x00583210-0x00583273.StringBaseAnsiFormatCtor.md) 0x00583210-0x00583273 | function | StringBaseAnsiFormatCtor : reconstructable : 86% : strong : Assigned to [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md); live IDA reconfirmed exact ANSI varargs wrapper range, callers at 0x005798c6/0x00579f6c/0x00579fab, sole callee 0x00583720, ANSI sentinel xref at 0x0058323e, and thirteen 0xcc bytes before the wide-format sibling. Direct parent [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md) is 86/90 and source root [UID:0000OA][StringBase](by-file/StringBase.md) is 88/86.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00583273-0x00583280 | padding | StringBase ANSI format constructor to wide format constructor alignment : ignored : 100% : strong : IDA MCP/raw-byte checks recorded on the child page show thirteen `0xcc` alignment bytes.
        - [UID:0002LK][0x00583280-0x005832e3.StringBaseWideFormatCtor](by-memory/0x00583280-0x005832e3.StringBaseWideFormatCtor.md) 0x00583280-0x005832e3 | function | StringBaseWideFormatCtor : reconstructable : 85% : strong : Assigned to [UID:0000OA][StringBase](by-file/StringBase.md) after 2026-06-11 A003 live IDA refresh; UTF-16 varargs initializer with exact half-open range, 33 start xrefs from 15 caller functions, wide sentinel store at 0x005832ae, single call to StringBaseWideVFormatWorker, and 13-byte 0xcc padding before the release/capacity continuation.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005832e3-0x005832f0 | padding | StringBase wide format constructor to release/mutation alignment : ignored : 100% : strong : IDA MCP/raw-byte checks recorded on the child page show thirteen `0xcc` alignment bytes before `sub_5832F0`.
    - [UID:0001J3][0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md) 0x005832f0-0x00584d7e | aggregate-container | StringBaseReleaseFormatAndMutation : ignored : 84% : strong : Reviewed non-emitting StringBase release/format/mutation aggregate; renamed from stale LObject ownership after live IDA MCP confirmed these helpers operate on the ref-counted string data/header model. Exact child pages carry source ownership and parent routing.
        - [UID:0002RT][0x005832f0-0x00583714.StringBaseReleaseAndCapacity](by-memory/0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md) 0x005832f0-0x00583714 | method/helper-group | StringBaseReleaseAndCapacity : reconstructable : 87% : strong : Assigned to [UID:0000OA][StringBase](by-file/StringBase.md) after A003 Goal 2 live IDA MCP refresh; exact eight-function helper group with ANSI/wide release, header-prefix access, wide copy/share, ANSI/wide set-length detach paths, `MakeExclusiveWide`, and a tiny wide varargs forwarder to [UID:0002LM][0x00583840-0x00583968.StringBaseWideVFormatWorker](by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md). Child is 87/90, direct parent is 88/86, all substantive helpers manipulate [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md) plus [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md), and C++ remains blank below the final-source gate.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00583714-0x00583720 | padding | StringBase release/capacity to ANSI format worker alignment : ignored : 100% : strong : IDA MCP/raw-byte check shows twelve `0xcc` alignment bytes.
        - [UID:0002LL][0x00583720-0x00583832.StringBaseAnsiVFormatWorker](by-memory/0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md) 0x00583720-0x00583832 | function | StringBaseAnsiVFormatWorker : reconstructable : 82% : strong : ANSI `va_list` formatting worker using the ref-counted buffer header, grow/retry, detach-on-share behavior, sentinel check, caller audit, and corrected function-end/padding evidence.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00583832-0x00583840 | padding | StringBase ANSI to wide format worker alignment : ignored : 100% : strong : IDA MCP/raw-byte check shows fourteen `0xcc` alignment bytes.
        - [UID:0002LM][0x00583840-0x00583968.StringBaseWideVFormatWorker](by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md) 0x00583840-0x00583968 | function | StringBaseWideVFormatWorker : reconstructable : 82% : strong : UTF-16 `va_list` formatting worker using the ref-counted buffer header, grow/retry, detach-on-share behavior, sentinel check, caller audit, and corrected function-end/padding evidence.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00583968-0x00583970 | padding | StringBase wide format worker to replace/trim helpers alignment : ignored : 100% : strong : IDA MCP/raw-byte check shows eight `0xcc` alignment bytes.
        - [UID:0002RQ][0x00583970-0x00584052.StringBaseReplaceTrimAndLocks](by-memory/0x00583970-0x00584052.StringBaseReplaceTrimAndLocks.md) | method/helper-group | StringBaseReplaceTrimAndLocks : reconstructable : 76% : strong : UTF-16 mid/replace/trim and writable-buffer lock helpers over ref-counted string storage.
        - [UID:0002LN][0x005840f0-0x0058415a.WideRangeCompare](by-memory/0x005840f0-0x0058415a.WideRangeCompare.md) 0x005840f0-0x0058415a | function | WideRangeCompare : reconstructable : 87% : strong : Assigned to [UID:0000OA][StringBase](by-file/StringBase.md) after 2026-06-11 A003 live IDA refresh; lexicographic UTF-16 range comparator with exact half-open range, 29 start xrefs from 14 caller functions, no modeled callees, word-compare loop, length tie-break, and normalized `-1/0/1` return behavior.
        - [UID:0002RS][0x00584160-0x005845af.StringBaseAppendAndFind](by-memory/0x00584160-0x005845af.StringBaseAppendAndFind.md) 0x00584160-0x005845af | method/helper-group | StringBaseAppendAndFind : reconstructable : 86% : strong : Assigned to [UID:0000OA][StringBase](by-file/StringBase.md) after 2026-06-12 A003 live IDA refresh; ANSI/UTF-16 append, fill, data-pointer accessor, and bounded wide-compare helpers with exact function inventory, per-helper behavior, caller/callee counts, ref-counted header usage, internal `0xcc` padding, and one-byte successor padding caveat.
        - [0x005845af-0x005845b0 | EMPTY (1 byte)] : ignored : 100% : strong : IDA MCP get_bytes on 2026-06-12 returned one `0xcc` alignment byte between [UID:0002RS][0x00584160-0x005845af.StringBaseAppendAndFind](by-memory/0x00584160-0x005845af.StringBaseAppendAndFind.md) and [UID:0002LO][0x005845b0-0x005845ec.StringBaseCompareWideLiteral](by-memory/0x005845b0-0x005845ec.StringBaseCompareWideLiteral.md).
        - [UID:0002LO][0x005845b0-0x005845ec.StringBaseCompareWideLiteral](by-memory/0x005845b0-0x005845ec.StringBaseCompareWideLiteral.md) 0x005845b0-0x005845ec | function | StringBaseCompareWideLiteral : reconstructable : 85% : strong : Assigned to [UID:0000OA][StringBase](by-file/StringBase.md) after 2026-06-11 A003 live IDA refresh; pointer-backed UTF-16 literal compare wrapper with exact range, three start xrefs from two caller functions, header length read at data[-2], literal end scan through wcslen, sole call to WideRangeCompare, and four-byte 0xcc padding before the search/splice continuation.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005845ec-0x005845f0 | padding | StringBase wide literal compare to search/splice continuation alignment : ignored : 100% : strong : Existing child evidence records four `0xcc` bytes before `sub_5845F0`.
        - [UID:0002RR][0x005845f0-0x00584d7e.StringBaseSearchSpliceAndSubstring](by-memory/0x005845f0-0x00584d7e.StringBaseSearchSpliceAndSubstring.md) | method/helper-group | StringBaseSearchSpliceAndSubstring : reconstructable : 76% : strong : UTF-16 search, remove, splice, grow, and substring helpers ending at the verified `0x00584d7e-0x00584d80` padding.
```

## 2026-06-15 Agent-C001 Goal 2 Section Container Follow-up LibJPEG Continuation C001-goal2-section-container-followup-20260615-1

- Changed docs: [UID:0001Z5][0x00401000-0x0060d000.MasterCodeTextSection](../../../../by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md), [UID:0000VP][0x00401000-0x00414283.LibJpeg6bCore](../../../../by-memory/0x00401000-0x00414283.LibJpeg6bCore.md), [UID:0000VQ][0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd](../../../../by-memory/0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd.md), [UID:0000VS][0x00403920-0x004048e2.LibJpegCompressApiFrontEnd](../../../../by-memory/0x00403920-0x004048e2.LibJpegCompressApiFrontEnd.md), [UID:0000VW][0x00405060-0x00405c77.LibJpegMemoryManager](../../../../by-memory/0x00405060-0x00405c77.LibJpegMemoryManager.md), [UID:0000VY][0x004063d0-0x0040649b.LibJpegUtilityHelpers](../../../../by-memory/0x004063d0-0x0040649b.LibJpegUtilityHelpers.md), [UID:0000W1][0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend](../../../../by-memory/0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend.md), [UID:0000KN][LibJPEG](../../../../by-file/LibJPEG.md), `by-file/-coverage-report.md`, and this notes file.
- Score changes: [UID:0001Z5] `77/89 -> 78/89`; [UID:0000VP] `80/85 -> 84/88`; [UID:0000VQ] `80/85 -> 86/89`; [UID:0000VS] `80/85 -> 86/89`; [UID:0000VW] `80/85 -> 86/90`; [UID:0000VY] `80/85 -> 86/90`; [UID:0000W1] `80/85 -> 87/91`; [UID:0000KN] `90/84 -> 90/86`.
- Owner/emitter decisions: [UID:0001Z5] remains `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitters as a mixed `.text` section container. [UID:0000VP] remains an ignored third-party static-library aggregate routed through [UID:0000KN][LibJPEG](../../../../by-file/LibJPEG.md) but stays below `85` because several Huffman/DCT/color/quantizer/internal helper clusters are still not locally audited. The five exact child pages remain reconstructable with owner/emitter [UID:0000KN]. Final C++ remains blank on all changed libjpeg memory docs because source-quality declaration placement was not proven or needed for this static third-party documentation pass.
- Evidence summary: live IDA MCP session `a003_objectlist_dispatch_20260615` reconfirmed `NexusTK.exe.i64`, image base `0x00400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. C001 refreshed the IJG libjpeg 6b version/copyright/diagnostic strings, message-table and `JPEGMEM` xrefs, product decode/write wrapper callers, source-file child heads/endpoints, final-helper padding, Miles shutdown exclusion, zlib successor boundary, `jpeg_CreateDecompress`/`jpeg_CreateCompress` setup behavior, `jmemmgr.c` callback/string parsing, `jutils.c` helper fanout, and `jmemnobs.c` direct `malloc(Size)` backend behavior.
- IDA DB changes: none. Skipped candidates: no IDA names, comments, prototypes, type/member edits, function boundary edits, vtable edits, or data retyping were applied. Current evidence supports documentation score/route updates, while final third-party symbol naming and static-library compile-configuration details remain below the safe DB-edit threshold.
- Validation: scoped loop `python .\tools\validator.py --mode file --file <target> --apply --lock-timeout 60` exited `0` for [UID:0000KN], `by-file/-coverage-report.md`, [UID:0000VP], [UID:0000VQ], [UID:0000VS], [UID:0000VW], [UID:0000VY], [UID:0000W1], and [UID:0001Z5]; each run reached `ok: 1`. Validator refreshed generated registry/autogen metadata and `project-level/-auto-completion-stats.md`; `by-memory/-coverage-report.md` remains supervisor-owned and was not edited by C001.

### Supervisor-applied `by-memory/-coverage-report.md` replacements

Supervisor applied the exact [UID:0001Z5], [UID:0000VP], [UID:0000VQ], [UID:0000VS], [UID:0000VW], [UID:0000VY], and [UID:0000W1] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No C001 libjpeg-continuation supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 Agent-C001 Goal 2 Section Container Follow-up C001-goal2-section-container-followup-20260615-1

- Changed docs: [UID:0001Z5][0x00401000-0x0060d000.MasterCodeTextSection](../../../../by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md), [UID:0000X9][0x004345f0-0x00434887.JsonCppNumberTokenParseHelper](../../../../by-memory/0x004345f0-0x00434887.JsonCppNumberTokenParseHelper.md), [UID:0001Z7][0x0060d670-0x0066d000.ReadOnlyDataSection](../../../../by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md), [UID:00024S][0x00610ed8-0x006125a8.AboveFrameAndLocaleReadOnlyData](../../../../by-memory/0x00610ed8-0x006125a8.AboveFrameAndLocaleReadOnlyData.md), new [UID:0003OX][0x006112e8-0x006112fc.IntAlphaSurfaceVtableData](../../../../by-memory/0x006112e8-0x006112fc.IntAlphaSurfaceVtableData.md), validator-owned generated files, and this notes file.
- Score changes: [UID:0001Z5] `74/89 -> 75/89`; [UID:0000X9] `80/85 -> 85/88`; [UID:0001Z7] `75/90 -> 76/90`; [UID:00024S] `80/88 -> 84/90`; new [UID:0003OX] `0/0 -> 87/91`.
- Owner/emitter decisions: section containers [UID:0001Z5]/[UID:0001Z7] remain `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitters. [UID:00024S] remains a non-emitting mixed `.rdata` map. [UID:0000X9] keeps owner/emitter [UID:0000KI][JsonCpp](../../../../by-file/JsonCpp.md). [UID:0003OX] routes through [UID:00006K][IntAlphaSurface](../../../../by-class/IntAlphaSurface.md); final C++ is blank because it is compiler-emitted vtable/RTTI data.
- Evidence summary: live IDA MCP session `a003_objectlist_dispatch_20260615` was healthy on `NexusTK.exe.i64`. For [UID:0000X9], `analyze_function 0x004345f0` confirmed size `663`/`0x297`, callers `sub_433D20`/`sub_434430`, JsonCpp diagnostic strings, short/long number-token parse paths, success assignment helpers, and parse-error reporting. For [UID:00024S], byte/int/string/xref passes proved `0x006112e8-0x006112fc` is the `IntAlphaSurface` RTTI/vtable child, `0x006112fc-0x00612574` remains runtime/locale data, and `0x00612574-0x006125a8` is mixed application error-state vtable/literal boundary data rather than a clean PasswordError-owned span.
- IDA DB changes: none. Skipped candidates: no IDA renames, comments, prototypes, type/member edits, vtable edits, or data retyping were applied; evidence supported documentation and one exact child split, not low-risk DB mutation.
- Validation: scoped loop `python .\tools\validator.py --mode file --file <target> --apply --lock-timeout 60` exited `0` for [UID:0003OX], [UID:00024S], [UID:0001Z7], [UID:0000X9], and [UID:0001Z5]; each run reached `ok: 1`. Earlier UID/path setup for [UID:0003OX] inserted UID `0003OX`, then path-updated after the exact range correction from `0x00611300` to `0x006112fc`.

### Supervisor-applied `by-memory/-coverage-report.md` replacements/inserts

Supervisor applied the exact replacement rows for [UID:0001Z5], [UID:0000X9], [UID:0001Z7], and [UID:00024S], plus inserted child row [UID:0003OX] under [UID:00024S], on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.

## 2026-06-14 Agent-C001 Goal 2 RData Aggregate Score Batch C001-goal2-rdata-aggregate-score-20260614-5

- Changed docs: [UID:000265][0x00622034-0x00622154.PhotoPictureReadOnlyData](../../../../by-memory/0x00622034-0x00622154.PhotoPictureReadOnlyData.md), new [UID:0003OU][0x00622034-0x006220b8.PhotoPaneVtableData](../../../../by-memory/0x00622034-0x006220b8.PhotoPaneVtableData.md), new [UID:0003OV][0x006220b8-0x006220cc.PhotoPaneMapFilenameFormatString](../../../../by-memory/0x006220b8-0x006220cc.PhotoPaneMapFilenameFormatString.md), new [UID:0003OW][0x006220cc-0x00622154.PictureViewPaneVtableData](../../../../by-memory/0x006220cc-0x00622154.PictureViewPaneVtableData.md), [UID:0000VN][by-memory/-ignored](../../../../by-memory/-ignored.md), validator-owned generated files, and this notes file.
- Score changes: [UID:000265] `82/88 -> 86/92`, `RECONSTRUCTABLE:TRUE -> FALSE`, `CANONICAL_OWNER:0000MK -> NONE`, `EMITTER_UIDS:0000MK -> blank`; new [UID:0003OU] `0/0 -> 86/91`; new [UID:0003OV] `0/0 -> 86/91`; new [UID:0003OW] `0/0 -> 86/91`. [UID:000266], [UID:000267], and [UID:000268] were not edited; their local docs already contain the reviewed non-emitting aggregate state, but the banned shared memory coverage report still has stale rows.
- Owner/emitter decisions: [UID:000265] is now a reviewed non-emitting mixed map. [UID:0003OU] and [UID:0003OV] route through [UID:0000AG][PhotoPane](../../../../by-class/PhotoPane.md); [UID:0003OW] routes through [UID:0000AH][PictureViewPane](../../../../by-class/PictureViewPane.md). Final C++ remains blank because these are vtable/literal data pages and source-quality declaration/local spelling belongs in the owning class/file work.
- Evidence summary: live IDA MCP session `a001_goal2_class_batch` was healthy and reconfirmed names, dwords, bytes, xrefs, and function boundaries across `0x00622034-0x00622154`: three `PhotoPane` vtable bases at `0x00622034`, `0x00622080`, `0x006220b0`; UTF-16LE `C%04d.MAP` at `0x006220b8-0x006220cc` with the sole constructor xref `0x00549696`; `PictureViewPane` locator/vtable data starting at `0x006220cc` with vtable bases `0x006220d0`, `0x0062211c`, `0x0062214c`; final local slot `0x00622150 -> 0x00544e90`; and successor `PowerDialogPane` metadata at `0x00622154`.
- IDA DB changes: none. Skipped candidates: no IDA names, comments, prototypes, type/member edits, vtable edits, string retyping, or data retyping were applied.
- Validation: scoped validator loop `python .\tools\validator.py --mode file --file <target> --apply --lock-timeout 60` exited `0` for new children [UID:0003OU], [UID:0003OV], [UID:0003OW], the aggregate [UID:000265], and `by-memory/-ignored.md`; results included `ok: 1` for each child, `ok: 10` for the aggregate with `tmp_ref_replace: 9`, and `ok: 4` for `by-memory/-ignored.md` with `tmp_ref_replace: 3`.

### Supervisor-applied `by-memory/-coverage-report.md` replacement block

Supervisor applied the exact stale-block replacement for [UID:000265] through [UID:000268] on 2026-06-15, including new child rows [UID:0003OU], [UID:0003OV], and [UID:0003OW]. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.

## 2026-06-13 Agent-C001 Goal 2 TextEdit/TextBox Barrier Crossing

- Changed docs: renamed [UID:0001JM] from `by-memory/0x0058dce0-0x005917c9.TextEditPaneCore.md` to `by-memory/0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane.md`; created [UID:0003N0] `by-memory/0x00591400-0x005917c9.TextEditPaneCoreAfterTextBoxPane.md`; updated [UID:0001JO] `by-memory/0x00591300-0x005954b3.TextBoxPaneNoncontiguousAuditMap.md`; refreshed/validated target audit pages [UID:0002XX] and [UID:0001JT].
- Range/score/routing changes: [UID:0001JM] range `0x0058dce0-0x005917c9 -> 0x0058dce0-0x00591300`, score `85/90 -> 86/90`, parent remains [UID:0000EO][TextEditPane](../../../../by-class/TextEditPane.md). New [UID:0003N0] is `85/88`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000EO]. [UID:0001JO], [UID:0002XX], and [UID:0001JT] keep their existing scores and non-emitting audit-map classification.
- Evidence summary: live IDA MCP on session `a001_goal2_0002UM` confirmed the former [UID:0001JM] range crossed real `TextBoxPane` code: `sub_591300` is `0x00591300-0x0059136a`, `sub_591370` is `0x00591370-0x005913f9`, and `0x005913f9-0x00591400` is seven `0xcc` bytes. The narrowed front ends cleanly after `sub_5912B0` at `0x005912fe` plus two `0xcc` bytes to `0x00591300`. The new tail contains modeled TextEditPane helpers `0x00591400-0x005914c4`, `0x00591520-0x00591639`, and exact child [UID:00030D] `0x00591740-0x005917c9`, with raw code-shaped pockets at `0x005914d0` and `0x00591640`.
- IDA database updates: none. The evidence supported documentation range/split repair only.
- Validation: targeted `python .\tools\validator.py --queue-timeout 300 --mode file --file <path> --apply` scans exited `0`, `ok: 1` for [UID:0001JM], [UID:0003N0], [UID:0001JO], [UID:0002XX], and [UID:0001JT]. The first [UID:0003N0] validation assigned the new UID; the [UID:0001JM] validation recorded `path_update 0001JM`, `completion_update 0001JM 86`, `completion_update 0003N0 85`, `confidence_update 0003N0 88`, `autogen_registry_update 0003N0 blank -> true`, `autogen_registry_update 0003N0 -> 0000EO`, and resolved five TMP references to [UID:0003N0].
- Memory ranges: `python .\tools\memory_ranges.py --advanced-scan report` exited `0` and rewrote `auto-generated/by-memory-tool-report.md`. The active TextEdit/TextBox barrier entries are gone from `Barrier Crossings Errors`; the two reviewed support-object audit-map overlaps were marked with `memory_ranges.py mark-as-ignored` and now appear under `Ignored-Crossings` with reasons. The only remaining active barrier is the unrelated GameServer/MapPane pair.
- Tool data update: `tools/memory_ranges.data` was changed only through `python .\tools\memory_ranges.py mark-as-ignored` for `0x00591300-0x005954b3 -> 0x00594e60-0x00595760` and `0x00591300-0x005954b3 -> 0x00594e60-0x005958fe`.

Supervisor-applied `by-memory/-coverage-report.md` replacement/insert rows:

- The supervisor applied and validated the TextEdit/TextBox replacement block for [UID:0001JM], [UID:0001JO], inserted [UID:0003N0], and moved nested [UID:00030D] on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 TextEdit/TextBox supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-13 Agent-C001 Goal 2 MenuVariety/UiPaneDestructor Barrier Crossing supervisor-applied row

- Changed docs: renamed [UID:0001NP] from `by-memory/0x005bc610-0x005bfd98.MenuVarietyPanes.md` to `by-memory/0x005bc610-0x005c0034.MenuVarietyPanes.md`; updated stale UID annotations in [UID:000081][MenuVarietyPane](../../../../by-class/MenuVarietyPane.md), [UID:000082][MenuVarietySelectPane](../../../../by-class/MenuVarietySelectPane.md), [UID:0000L8][MenuVarietyPanes](../../../../by-file/MenuVarietyPanes.md), [UID:0000RI][g_pMenuVarietyPane](../../../../by-global/g_pMenuVarietyPane.md), [UID:0000RJ][g_pMenuVarietySelectPane](../../../../by-global/g_pMenuVarietySelectPane.md), [UID:0003AH], [UID:0003AI], [UID:0001NQ], [UID:00026Y], [UID:0002Z2], [UID:0002Z1], [UID:0002Z7], and `by-memory/-ignored.md`.
- Classification/range/score changes: [UID:0001NP] range `0x005bc610-0x005bfd98 -> 0x005bc610-0x005c0034`; score `86/90 -> 87/91`; `RECONSTRUCTABLE:FALSE`, blank parent, and blank final C++ remain unchanged. This is a containment/range-map repair only, not a new direct source-owner assignment.
- Evidence summary: current IDA 9.1 MCP session `a001_goal2_0002UM` confirms the shared tail after the old endpoint has modeled functions at `0x005bfda0`, `0x005bfe60`, `0x005bff20`, and `0x005bffe0`, no function at `0x005c0034`, and `VideoPlayerPane` starts at `0x005c0040`. `make_signature_for_range` confirms `0x005bfd98-0x005bfda0`, `0x005bfe5e-0x005bfe60`, `0x005bff1e-0x005bff20`, `0x005bffde-0x005bffe0`, and `0x005c0034-0x005c0040` are all `0xcc` padding. `analyze_function 0x005bffe0` confirms the label-vector helper has direct xrefs from selector construction at `0x005bceef` and `0x005bcf2d`; status scalar deleting destructors remain non-emitting destructor-wrapper material already documented by [UID:0001NS].
- IDA database updates: none. The evidence supported documentation range/coverage repair only; no safe IDA rename/type/function change was needed.
- Validation: `python tools/validator.py --mode file --file <path> --apply` exited `0`, `ok: 1` for all changed by-* docs. The first target validation recorded `path_update 0001NP`, completion `87`, confidence `91`, and reference path updates.
- Memory ranges: `python .\tools\memory_ranges.py --advanced-scan report` exited `0` and rewrote `auto-generated/by-memory-tool-report.md`; the assigned `MenuVarietyPanes` / `UiPaneDestructorThunksAndVectorHelper` barrier entry is gone. The first remaining barrier is the unrelated `GameServerNationAndMapInit` / `MapPaneWeatherCoordinateObjectCore` pair.

- The supervisor applied and validated the [UID:0001NP] `MenuVarietyPanes` `by-memory/-coverage-report.md` replacement row on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 MenuVariety/UiPaneDestructor supervisor-owned `by-memory/-coverage-report.md` row remains pending.

## 2026-06-13 Agent-C001 Goal 2 GameServer/MapPane Barrier Crossing

- Changed docs: none. Existing [UID:0001AO][0x005039f0-0x00504521.GameServerNationAndMapInit](../../../../by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md) and [UID:0001AP][0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore](../../../../by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md) already documented the crossing as an intentional non-emitting mixed-owner boundary/index overlap.
- Score/range/routing decisions: no changes. [UID:0001AO] remains `88/92`, `RECONSTRUCTABLE:FALSE`, parent blank; [UID:0001AP] remains `85/88`, `RECONSTRUCTABLE:TRUE`, parent [UID:00007Q]. This matches by-structure: the mixed GameServerConfig/MapPane index is not a source-emitting parent, while exact MapPane children and the MapPane aggregate carry ownership.
- Evidence summary: read current docs, active supervisor notes, and by-structure guidance. Live IDA 9.1 MCP session `a001_goal2_0002UM` `lookup_funcs` reconfirmed raw starts `0x005039f0`, `0x00503a50`, and `0x00503b60` are still not modeled functions; `0x00503ef0` is `sub_503EF0` size `0x19d`, `0x00504110` is `sub_504110` size `0x411`, successor `0x00504530` is `sub_504530`, and successor `0x00506380` is `sub_506380`.
- IDA database updates: none. The evidence supported report suppression only; no safe IDA rename/type/function edit was needed.
- Memory ranges: ran `python .\tools\memory_ranges.py mark-as-ignored 0x005039f0-0x00504521 0x00503ef0-0x0050637a "Reviewed intentional non-emitting mixed-owner boundary-index overlap: GameServerNationAndMapInit records the GameServerConfig-to-MapPane transition while the MapPane aggregate carries source ownership."`, then `python .\tools\memory_ranges.py --advanced-scan report`. The active `Barrier Crossings Errors` section now reports `None`; this crossing appears under `Ignored-Crossings` with the recorded reason.
- Validation: no by-* docs were changed, so no validator run was needed for this pass.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none required; no by-memory document range, score, reconstructable flag, or parent metadata changed.

## 2026-06-13 Agent-C001 Goal 2 NewUserShapeSelectControlPaneCore Low Completion/Low Both

- Changed docs: [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](../../../../by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md), [UID:00009G][NewUserShapeSelectControlPane](../../../../by-class/NewUserShapeSelectControlPane.md), [UID:0000LY][NewUserShapeSelectControlPane](../../../../by-file/NewUserShapeSelectControlPane.md), `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, and this notes file.
- Score/routing changes: [UID:0002Q9] `76/84 -> 86/88`, parent [UID:0000LY] -> direct class parent [UID:00009G]; [UID:00009G] `80/84 -> 85/88`, parent remains [UID:0000LY]; [UID:0000LY] `82/84 -> 85/87`. Reconstructable flags and ranges unchanged.
- Evidence summary: live IDA 9.1 MCP session `a001_goal2_0002UM` reconfirmed modeled starts/sizes, tail chunks at `0x004fd680`/`0x004fd6a0`, unmodeled raw page-step helpers at `0x004fd6c0-0x004fd72c` and `0x004fd730-0x004fd786`, constructor/helper/vtable/destructor xrefs, major method decompilation, callee dependencies, and `0x004fdd33-0x004fdd40` padding before `ChangePasswordDialogPane`.
- IDA database updates: none. The evidence supported documentation/routing only; no safe IDA rename/type/function edit was needed.
- Validation: `python .\tools\validator.py --queue-timeout 300 --mode file --file <path> --apply` exited `0`, `ok: 1` for all five changed by-* docs. The first [UID:0002Q9] validation recorded completion `86`, confidence `88`, `autogen_registry_update 0002Q9 0000LY -> 00009G`, and removal from Low_Completion/Low_Both stats rows. Filtered reruns for all changed docs also exited `0`, `ok: 1`, with generated autogen reports unchanged.
- Memory ranges: not rerun because no filename range, manual range, barrier ignore, or overlap handling changed.

Supervisor-owned `by-memory/-coverage-report.md` replacement row:

- None. Supervisor applied and validated the [UID:0002Q9] `NewUserShapeSelectControlPaneCore` replacement row on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.

## 2026-06-13 Agent-C001 Goal 2 FittingRoomCategoryLookupFinalize Advanced-Scan Repair

- Changed docs: [UID:0002U8][0x00423470-0x0042365d.FittingRoomCategoryLookupFinalize](../../../../by-memory/0x00423470-0x0042365d.FittingRoomCategoryLookupFinalize.md) and this notes file. `auto-generated/by-memory-tool-report.md` was regenerated by `memory_ranges.py`.
- Warning disposition: real documentation-label mismatch, not a range/name error. The filename label `FittingRoomCategoryLookupFinalize` was valid, but the page title/body used only `FittingRoom Category Lookup Insert/Rehash`, so the advanced scanner could not find the label in document text.
- Score/routing changes: none. [UID:0002U8] remains `85/88`, `RECONSTRUCTABLE:TRUE`, parent [UID:000051][FittingRoomDialogItemState](../../../../by-class/FittingRoomDialogItemState.md), range `0x00423470-0x0042365d`.
- Evidence summary: live IDA 9.1 MCP session `a001_goal2_0002UM` reconfirmed `sub_423470` at `0x00423470`, size `0x1ed`; `0x00423610` and `0x00423634` are inside the function, `0x0042365d` is not a function, and `0x00423660` starts successor `sub_423660`. `xrefs_to` reports caller `0x00422dd3` and recursive rehash call `0x00423610`; `callees` reports `0x00423a90`, `0x00423b00`, recursive `0x00423470`, `0x00423c40`, `0x00423660`, and `__CxxThrowException@8`.
- IDA database updates: none. The evidence supported documentation text only; no safe IDA rename/type/function edit was needed.
- Validation: `python .\tools\validator.py --queue-timeout 300 --mode file --file by-memory/0x00423470-0x0042365d.FittingRoomCategoryLookupFinalize.md --apply` exited `0`, `ok: 1`; no metadata changes were reported.
- Memory ranges: `python .\tools\memory_ranges.py --advanced-scan report` exited `0`; `FittingRoomCategoryLookupFinalize` is no longer listed in `Advanced-Error-Scan`.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none required; no row metadata/range/score/parent changed.

## 2026-06-13 Agent-C001 Goal 2 SelectionControlPaneSelectedValue Type-Quality Pass

- Changed docs: [UID:0001SV][SelectionControlPaneSelectedValue_0x10c](../../../../by-type/by-field/SelectionControlPaneSelectedValue_0x10c.md), [UID:0000CR][SelectionControlPane](../../../../by-class/SelectionControlPane.md), [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](../../../../by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md), `by-type/by-field/-coverage-report.md`, `by-class/-coverage-report.md`, and this notes file.
- Score/routing changes: [UID:0001SV] `76/86 -> 86/90`, parent remains [UID:0000CR]; [UID:0000CR] `80/84 -> 85/87`, parent remains [UID:0000HY]; [UID:00011D] `82/88 -> 85/90`, parent remains [UID:0000CR]. [UID:0000HY][ButtonControlPane](../../../../by-file/ButtonControlPane.md) was already `86/88`.
- Evidence summary: live IDA 9.1 MCP session `a001_goal2_0002UM` reconfirmed `sub_495CB0` at `0x00495cb0`, size `0x19`, no function at `0x00495ca5`, successor `sub_495CD0` at `0x00495cd0`, exact one-basic-block setter body `this[67] = a2` / `mov [ecx+10Ch], eax`, zero normal callees, sole caller `sub_52A180`, caller-side control id `12`, `0x25`/`0x30` selected values, and padding bytes around the helper. `int_convert.py` verified `0x25 == 37`, `0x30 == 48`, and `0x10c == 268`.
- Parent/routing decision: direct parent remains [UID:0000CR][SelectionControlPane](../../../../by-class/SelectionControlPane.md), not [UID:0000HY][ButtonControlPane](../../../../by-file/ButtonControlPane.md), because the field and method are scoped to the tiny SelectionControlPane helper while the class routes through the broader button/choice-control source module. C++ remains blank below the final-source gate.
- IDA database updates: none. Existing IDA names remain `sub_495CB0`/`sub_52A180`; documentation names are behaviorally supported but the final original class/field/vtable-slot names remain below the safe IDA rename threshold.
- Validation: `python .\tools\validator.py --queue-timeout 300 --mode file --file <path> --apply` exited `0`, `ok: 1` for [UID:0001SV], [UID:0000CR], [UID:00011D], `by-type/by-field/-coverage-report.md`, and `by-class/-coverage-report.md`. The first target validation recorded [UID:0001SV] completion/confidence updates and removed it from the generated by-type low-score stats list; final reruns were no-op except projected stats refreshes.

Supervisor-owned `by-memory/-coverage-report.md` rows:

- None. The supervisor applied and validated the [UID:00011D] replacement row on 2026-06-13.

## 2026-06-13 Agent-C001 Goal 2 GenericStringAppendHelper Advanced-Scan Repair

- Changed docs: [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](../../../../by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md) and this notes file. `auto-generated/by-memory-tool-report.md` was regenerated by `memory_ranges.py`.
- Warning disposition: real documentation-label mismatch, not a range/name error. The filename label `GenericStringAppendHelper` remains valid as the canonical report/filename label, but the page body used the stronger JsonCpp `StyledWriter::pushValue` identity and omitted the filename label from the scanned document text.
- Score/routing changes: none. [UID:0000X5] remains `86/89`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000KI][JsonCpp](../../../../by-file/JsonCpp.md), range `0x00430040-0x00430092`.
- Evidence summary: live IDA 9.1 MCP session `a001_goal2_0002UM` reconfirmed `sub_430040` at `0x00430040`, size `0x52`; `0x00430041` and `0x00430058` resolve inside the same function; `0x00430092` is not a function start; `xrefs_to 0x00430040` reports five code callsites at `0x0042f8e5`, `0x0042f916`, `0x0042f9ac`, `0x0042fa0c`, and `0x0042fa6e`, all from `sub_42F870`; `xrefs_to 0x00430058` reports only the internal code ref from `0x00430056` plus stale data interpretations.
- IDA database updates: none. The evidence supported documentation text only; no safe IDA rename/type/function edit was needed.
- Validation: `python .\tools\validator.py --queue-timeout 300 --mode file --file by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md --apply` exited `0`, `ok: 1`; no target metadata changes were reported.
- Memory ranges: `python .\tools\memory_ranges.py --advanced-scan report` exited `0`; `GenericStringAppendHelper` is no longer listed in `Advanced-Error-Scan`.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none required; no row metadata/range/score/parent changed.

## 2026-06-13 Agent-C001 Goal 2 ScrollSpellInventoryPaneVtables Type-Quality/IDA Refresh

- Changed docs: [UID:0001YS][ScrollSpellInventoryPaneVtables](../../../../by-type/by-vtable/ScrollSpellInventoryPaneVtables.md) and this notes file. `project-level/-auto-completion-stats.md` was updated by validator.
- Score/routing changes: [UID:0001YS] `74/86 -> 85/90`; `RECONSTRUCTABLE:TRUE`, parent [UID:0000CN][ScrollSpellInventoryPane](../../../../by-class/ScrollSpellInventoryPane.md), and blank C++ remain unchanged.
- Parent/support decision: direct class parent [UID:0000CN] is already `85/85`; file parent [UID:0000NJ][ScrollSpellInventoryPane](../../../../by-file/ScrollSpellInventoryPane.md) is already `85/85`; exact vtable-data child [UID:0003CM][0x00623e90-0x00623f18.ScrollSpellInventoryPaneVtableData](../../../../by-memory/0x00623e90-0x00623f18.ScrollSpellInventoryPaneVtableData.md) is `86/90`. No support-doc edits were needed.
- Evidence summary: live IDA 9.1 MCP session `a001_goal2_0002UM` reconfirmed named vtables `??_7ScrollSpellInventoryPane@@6B@`, `_0`, and `_1` at `0x00623e94`, `0x00623ee0`, and `0x00623f10`; constructor stores at `0x0055f4a1`, `0x0055f4a7`, and `0x0055f4b1`; slot-function bounds/refs for `0x0055f890`, `0x0055f650`, `0x0055f840`, and `0x0055f850`; sole constructor caller `0x0057d013` from `sub_57CF70`; and the next `ScrollNewGroupPane` vtable boundary at `0x00623f18/0x00623f1c`.
- IDA database updates: none. Existing IDA names already matched the documentation, and no safe naming correction was needed.
- Validation: `python .\tools\validator.py --queue-timeout 300 --mode file --file by-type/by-vtable/ScrollSpellInventoryPaneVtables.md --apply` exited `0`, `ok: 1`; it recorded completion/confidence updates and removed [UID:0001YS] from Low_Completion, Low_Both, and by-type stats rows.
- Generated/type coverage: validator reported `auto-generated/-ag-type-coverage.md unchanged`; no generated reports were edited directly.

- Coverage report: updated [UID:0001YS] row in `by-type/by-vtable/-coverage-report.md` after the earlier Agent-A001 lease cleared.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none required.

## 2026-06-13 Agent-C001 Goal 2 Rgb555565BlitHelpers Advanced-Scan Repair

- Changed docs: [UID:0000YD][0x0045fa00-0x004604f4.Rgb555565BlitHelpers](../../../../by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md) and this notes file. `auto-generated/by-memory-tool-report.md` was regenerated by `memory_ranges.py`.
- Warning disposition: real documentation-label mismatch, not a range/name/ownership error. The filename label `Rgb555565BlitHelpers` is valid, but the page title/body used only expanded `RGB555/RGB565 Blit Helpers` wording.
- Score/routing changes: none. [UID:0000YD] remains `86/90`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000NT][SoftwareBlend16](../../../../by-file/SoftwareBlend16.md), range `0x0045fa00-0x004604f4`; the current parent is `86/88`.
- Evidence summary: live IDA 9.1 MCP session `a001_goal2_0002UM` reconfirmed real functions at `0x0045fa00`, `0x0045faa0`, `0x0045fb80`, `0x0045fe40`, `0x0045ff60`, `0x0045fff0`, `0x00460120`, `0x00460230`, `0x004602b0`, `0x00460370`, and `0x00460410`; `0x004604f4` is not a function and `0x00460500` starts `AlphaBlendSpan16`. Xrefs show calls from compat/RGB555 callbacks `0x004bc090` and `0x004bdf40`, and RGB565 callbacks `0x004c0f80` and `0x004c3cf0`. Raw bytes show `0xc3` at `0x004604f3`, then `0xcc` padding through `0x00460500`.
- IDA database updates: none. Existing IDA state still uses `sub_` names and the documented helper names are provisional, so no safe high-confidence rename was applied.
- Validation: `python .\tools\validator.py --queue-timeout 300 --mode file --file by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md --apply` exited `0`, `ok: 1`; no target metadata changes were reported.
- Memory ranges: `python .\tools\memory_ranges.py --advanced-scan report` exited `0`; `Rgb555565BlitHelpers` is no longer listed in `Advanced-Error-Scan`.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none required; no row metadata/range/score/parent changed.

## 2026-06-13 Agent-C001 Goal 2 RankingEventScrollPaneRawCtorAndSetters Advanced-Scan Repair

- Changed docs: [UID:0000Y2][0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters](../../../../by-memory/0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters.md) and this notes file. `auto-generated/by-memory-tool-report.md` was regenerated by `memory_ranges.py`.
- Warning disposition: real documentation-label mismatch, not a range/name/ownership error. The filename label `RankingEventScrollPaneRawCtorAndSetters` is valid, but the page title/body used only expanded `RankingEventScrollPane Raw Constructor And Setters` wording.
- Score/routing changes: none. [UID:0000Y2] remains `86/90`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000BO][RankingEventScrollPane](../../../../by-class/RankingEventScrollPane.md), range `0x004598b0-0x00459a59`.
- Evidence summary: live IDA 9.1 MCP session `a001_goal2_0002UM` reconfirmed no function objects at raw starts `0x004598b0`, `0x00459910`, `0x00459940`, `0x00459970`, `0x004599d0`, `0x00459a00`, `0x00459a20`, or `0x00459a40`; `0x00459a59` is not a function and successor `0x00459a60` is `sub_459A60`, size `0x26e`. `xrefs_to` reconfirmed no incoming xrefs to the raw starts and the expected vtable-base refs at `0x004598c3`/`0x0045aeb2`, `0x004598e2`/`0x0045aeb8`, and `0x004598ec`/`0x0045aec2`; `make_signature_for_range 0x004598b0-0x00459a60` returned a unique signature for the full raw island and padding.
- IDA database updates: none. Existing IDA raw/function boundaries already match the documentation, and no safe naming/type/function edit was needed.
- Validation: `python .\tools\validator.py --queue-timeout 300 --mode file --file by-memory/0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters.md --apply` exited `0`, `ok: 1`; no target metadata changes were reported.
- Memory ranges: `python .\tools\memory_ranges.py --advanced-scan report` exited `0`; `RankingEventScrollPaneRawCtorAndSetters` is no longer listed in `Advanced-Error-Scan`.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none required; no row metadata/range/score/parent changed.

## 2026-06-13 Agent-C001 Goal 2 RankingEventScrollPaneRawHoverDragHelpers Advanced-Scan Repair

- Changed docs: [UID:0000Y5][0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers](../../../../by-memory/0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers.md) and this notes file. `auto-generated/by-memory-tool-report.md` was regenerated by `memory_ranges.py`.
- Warning disposition: real documentation-label mismatch, not a range/name/ownership error. The filename label `RankingEventScrollPaneRawHoverDragHelpers` is valid, but the page title/body used only expanded `RankingEventScrollPane Raw Hover And Drag Helpers` wording.
- Score/routing changes: none. [UID:0000Y5] remains `86/90`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000BO][RankingEventScrollPane](../../../../by-class/RankingEventScrollPane.md), range `0x0045a990-0x0045ac0f`.
- Evidence summary: live IDA 9.1 MCP session `a001_goal2_0002UM` reconfirmed no function objects at raw starts `0x0045a990`, `0x0045aa00`, or `0x0045ab50`; `0x0045ac0f` is not a function and successor `0x0045ac10` is `sub_45AC10`, size `0x1b4`. `xrefs_to` reconfirmed no incoming xrefs to the raw starts, local `0x0045ac10` refs from modeled mouse handler sites `0x00459c1c`/`0x00459c38`, and raw-island calls at `0x0045aad8`, `0x0045aaf4`, `0x0045abab`, and `0x0045abd4`; `make_signature_for_range 0x0045a990-0x0045ac10` returned a unique signature for the full raw island.
- IDA database updates: none. Existing IDA raw/function boundaries already match the documentation, and no safe naming/type/function edit was needed.
- Validation: `python .\tools\validator.py --queue-timeout 300 --mode file --file by-memory/0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers.md --apply` exited `0`, `ok: 1`; no target metadata changes were reported.
- Memory ranges: `python .\tools\memory_ranges.py --advanced-scan report` exited `0`; `RankingEventScrollPaneRawHoverDragHelpers` is no longer listed in `Advanced-Error-Scan`.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none required; no row metadata/range/score/parent changed.

## 2026-06-13 Agent-C001 Goal 2 BlitTransparentShadow565MmxBlocks Advanced-Scan Repair

- Changed docs: [UID:000208][0x00460940-0x004609d3.BlitTransparentShadow565MmxBlocks](../../../../by-memory/0x00460940-0x004609d3.BlitTransparentShadow565MmxBlocks.md) and this notes file. `auto-generated/by-memory-tool-report.md` was regenerated by `memory_ranges.py`.
- Warning disposition: real documentation-label mismatch, not a range/name/ownership error. The filename label `BlitTransparentShadow565MmxBlocks` is valid compact spelling for the RGB565 transparent-shadow MMX block helper, but the page title/body used only expanded `RGB565`/`MMX` wording.
- Score/routing changes: [UID:000208] `82/90 -> 85/90`, `RECONSTRUCTABLE:TRUE` unchanged, parent remains [UID:0000NT][SoftwareBlend16](../../../../by-file/SoftwareBlend16.md), range remains `0x00460940-0x004609d3`. The parent already clears the gate at `86/88`; support constants [UID:0002OO] are already `86/90`.
- Evidence summary: live IDA 9.1 MCP session `a001_goal2_0002UM` reconfirmed `sub_460940` at `0x00460940`, size `0x93`; `0x004609d3` is not a function and successor `0x004609e0` starts `sub_4609E0`. `xrefs_to` reconfirmed the sole call from `0x00460399` inside `sub_460370`, and `callees` reconfirmed this helper has no callees. `get_bytes` reconfirmed `0x004609d3-0x004609e0` as thirteen `0xcc` bytes and decoded constants at `0x00610e88`/`0x00610e90`; data refs remain only `0x00460951`/`0x0046095b`. `make_signature_for_range 0x00460940-0x004609e0` returned a unique signature for the full helper plus padding.
- IDA database updates: none. Existing IDA function boundaries and generic `sub_` names match the current evidence standard; the original function/signature spelling remains below the safe rename threshold.
- Validation: `python .\tools\validator.py --queue-timeout 300 --mode file --file by-memory/0x00460940-0x004609d3.BlitTransparentShadow565MmxBlocks.md --apply` exited `0`, `ok: 1`; validator recorded `completion_update 000208 ... 85`.
- Memory ranges: `python .\tools\memory_ranges.py --advanced-scan report` exited `0`; `BlitTransparentShadow565MmxBlocks` is no longer listed in `Advanced-Error-Scan`.

Supervisor-owned `by-memory/-coverage-report.md` replacement row:

- Supervisor applied and validated the [UID:000208] replacement row on 2026-06-13. No supervisor-owned rows remain pending for this item.

## 2026-06-13 Agent-C001 Goal 2 ByteSpanFill8Blocks Advanced-Scan Repair

- Changed docs: [UID:00020F][0x00460fa0-0x00460ffe.ByteSpanFill8Blocks](../../../../by-memory/0x00460fa0-0x00460ffe.ByteSpanFill8Blocks.md) and this notes file. `auto-generated/by-memory-tool-report.md` was regenerated by `memory_ranges.py`.
- Warning disposition: real documentation-label mismatch, not a range/name/ownership error. The filename label `ByteSpanFill8Blocks` is valid compact spelling for the byte-span eight-byte fill helper, but the page title/body used only expanded `Byte Span Fill 8-Byte Blocks` wording.
- Score/routing changes: [UID:00020F] `82/90 -> 85/90`, `RECONSTRUCTABLE:TRUE` unchanged, parent remains [UID:0000NT][SoftwareBlend16](../../../../by-file/SoftwareBlend16.md), range remains `0x00460fa0-0x00460ffe`. The parent already clears the gate at `86/88`; direct row-helper caller [UID:00020B] remains below gate but is support evidence, not the source parent.
- Evidence summary: live IDA 9.1 MCP session `a001_goal2_0002UM` reconfirmed no function object at raw caller/body sites `0x00460d60` or `0x00460d8e`; `sub_460FA0` at `0x00460fa0`, size `0x5e`; `0x00460ffe` is not a function and successor `0x00461000` is `sub_461000`, size `0x4b`. `xrefs_to` reconfirmed exactly one xref to `0x00460fa0`, the raw `0x00460d8e` call from `ByteSpanFillRows`; `callees` reconfirmed `0x00460fa0` has no callees. `get_bytes` reconfirmed seven `0xcc` bytes before the helper, the exact `0x5e`-byte body, and two `0xcc` bytes after it. `make_signature_for_range 0x00460f99-0x00461000` returned a unique signature for padding plus the full helper body.
- IDA database updates: none. Existing IDA function boundary is correct, and the original helper/signature spelling remains below the safe rename threshold.
- Validation: `python .\tools\validator.py --queue-timeout 300 --mode file --file by-memory/0x00460fa0-0x00460ffe.ByteSpanFill8Blocks.md --apply` exited `0`, `ok: 1`; validator recorded `completion_update 00020F ... 85`.
- Memory ranges: `python .\tools\memory_ranges.py --advanced-scan report` exited `0`; `ByteSpanFill8Blocks` is no longer listed in `Advanced-Error-Scan`.

Supervisor-owned `by-memory/-coverage-report.md` replacement row:

- Supervisor applied and validated the [UID:00020F] replacement row on 2026-06-13. No supervisor-owned rows remain pending for this item.

## 2026-06-13 Agent-C001 Goal 2 ByteSpanCopy8Blocks Advanced-Scan Repair

- Changed docs: [UID:00020G][0x00461000-0x0046104b.ByteSpanCopy8Blocks](../../../../by-memory/0x00461000-0x0046104b.ByteSpanCopy8Blocks.md) and this notes file. `auto-generated/by-memory-tool-report.md` was regenerated by `memory_ranges.py`.
- Warning disposition: real documentation-label mismatch, not a range/name/ownership error. The filename label `ByteSpanCopy8Blocks` is valid compact spelling for the byte-span eight-byte copy helper, but the page title/body used only expanded `Byte Span Copy 8-Byte Blocks` wording.
- Score/routing changes: [UID:00020G] `82/90 -> 85/90`, `RECONSTRUCTABLE:TRUE` unchanged, parent remains [UID:0000NT][SoftwareBlend16](../../../../by-file/SoftwareBlend16.md), range remains `0x00461000-0x0046104b`. The parent already clears the gate at `86/88`; direct row-helper caller [UID:00020C] remains below gate but is support evidence, not the source parent.
- Evidence summary: live IDA 9.1 MCP session `a001_goal2_0002UM` reconfirmed pre-rename `sub_461000` at `0x00461000`, size `0x4b`, with 36 decoded instructions, 7 basic blocks, cyclomatic complexity 3, exactly one incoming code xref from `0x00460e1f`, and no callees. `ByteSpanCopyRows` disassembly reconfirmed the caller stack contract before `call 0x00461000` and the post-call `blocks * 8` source/destination advancement. `get_bytes` reconfirmed two `0xcc` bytes before the helper, the exact `0x4b`-byte body, and five `0xcc` bytes after it. `make_signature_for_range 0x00460ffe-0x00461050` returned a unique signature for the padding plus full helper body.
- IDA database updates: safe function rename applied. `rename` dry-run found no `ByteSpanCopy8Blocks` collision; live IDA renamed `sub_461000` to `ByteSpanCopy8Blocks`, `lookup_funcs` verified the new name at `0x00461000`, and `idb_save` succeeded to `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`. No prototype/type/local/structure changes were made.
- Validation: `python .\tools\validator.py --queue-timeout 300 --mode file --file by-memory/0x00461000-0x0046104b.ByteSpanCopy8Blocks.md --apply` exited `0`, `ok: 1`; validator recorded `completion_update 00020G ... 85`.
- Memory ranges: `python .\tools\memory_ranges.py --advanced-scan report` exited `0`; `ByteSpanCopy8Blocks` is no longer listed in `Advanced-Error-Scan`.

Supervisor-owned `by-memory/-coverage-report.md` replacement row:

- Supervisor applied and validated the [UID:00020G] replacement row on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No supervisor-owned rows remain pending for this item.

## 2026-06-13 Agent-C001 C001-ERR-0002LL-0002LM StringBase VFormat Worker Parent Repair

- Changed docs: [UID:0002LL][0x00583720-0x00583832.StringBaseAnsiVFormatWorker](../../../../by-memory/0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md), [UID:0002LM][0x00583840-0x00583968.StringBaseWideVFormatWorker](../../../../by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md), and this notes file.
- Structural decision: [UID:0001J2][0x00583210-0x005832f0.StringBaseFormatConstructors](../../../../by-memory/0x00583210-0x005832f0.StringBaseFormatConstructors.md) remains `RECONSTRUCTABLE:FALSE` as a non-emitting constructor-wrapper aggregate. The two vformat workers should not attach to it. Both workers now attach to direct template/type parent [UID:0001WS][StringBaseTemplate](../../../../by-type/by-template/StringBaseTemplate.md), which is `86/90` and routes to [UID:0000OA][StringBase](../../../../by-file/StringBase.md), currently `88/86`.
- Score/routing changes: [UID:0002LL] `82/88 -> 85/90`, parent `0001J2 -> 0001WS`; [UID:0002LM] `82/88 -> 85/90`, parent `0001J2 -> 0001WS`. Both remain `RECONSTRUCTABLE:TRUE`; C++ remains blank below the final-source gate.
- Evidence summary: live IDA MCP session `a001_goal2_0002UM` reconfirmed `sub_583720` at `0x00583720`, size `0x112`, sole caller `sub_583210`, callees `sub_41B9A0`, `sub_582D80`, `___stdio_common_vsnprintf_s`, `sub_5832F0`, and `_memmove`; it also reconfirmed `sub_583840` at `0x00583840`, size `0x128`, callers `sub_583280` and `sub_583700`, callees `sub_41B9A0`, `___stdio_common_vsnwprintf_s`, `sub_582E30`, `_memmove`, and `sub_5833A0`. Both have 21 basic blocks/cyclomatic complexity 5 and decompile as `__thiscall` workers over `void **this`, format pointer, and `va_list`, manipulating the ref-counted string header and sentinel/detach paths. Nearby `entity_query` shows the workers belong to the StringBase release/format/mutation family after the narrowed `0001J2` constructor aggregate.
- IDA database updates: none.
- Validation: `python .\tools\validator.py --queue-timeout 300 --mode file --file by-memory\0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md --apply` exited `0`, `ok: 1`; validator recorded completion/confidence updates, parent `0001J2 -> 0001WS`, and `autogen_error_clear` for [UID:0002LL]. `python .\tools\validator.py --queue-timeout 300 --mode file --file by-memory\0x00583840-0x00583968.StringBaseWideVFormatWorker.md --apply` exited `0`, `ok: 1`; validator recorded completion/confidence updates and parent `0001J2 -> 0001WS` for [UID:0002LM]. `auto-generated/-ag-memory-coverage.md` now lists both rows as `assigned` to `0001WS` and no `autogen_parent_ineligible` rows remain for this assignment.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

- Supervisor applied and validated the [UID:0002LL] and [UID:0002LM] replacement rows on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No C001-ERR-0002LL-0002LM supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-13 Agent-C001 Goal 2 ByteSpanAdd8Blocks Advanced-Scan Repair

- Changed docs: [UID:00020H][0x00461050-0x0046109e.ByteSpanAdd8Blocks](../../../../by-memory/0x00461050-0x0046109e.ByteSpanAdd8Blocks.md) and this notes file. `auto-generated/by-memory-tool-report.md` was regenerated by `memory_ranges.py`.
- Warning disposition: real documentation-label mismatch, not a range/name/ownership error. The filename label `ByteSpanAdd8Blocks` is valid compact spelling for the byte-span eight-byte add helper, but the page title/body used only expanded `Byte Span Add 8-Byte Blocks` wording.
- Score/routing changes: [UID:00020H] `82/90 -> 85/90`, `RECONSTRUCTABLE:TRUE` unchanged, parent/emitter remain [UID:0000NT][SoftwareBlend16](../../../../by-file/SoftwareBlend16.md), range remains `0x00461050-0x0046109e`. The parent already clears the gate at `86/88`; direct row-helper caller [UID:00020D] remains support evidence, not the source parent.
- Evidence summary: live session-aware IDA 9.1 MCP session `b001_0003lq` reconfirmed `sub_461050` at `0x00461050`, size `0x4e`, with 37 decoded instructions; `0x0046109e` is not a function and successor `0x004610a0` is `sub_4610A0`. `analyze_function` reports prototype `__m64 *__cdecl(__m64 *, int, __m64 *, int, int, int)`, no callees, caller `sub_460E80`, one inbound code xref at `0x00460eaf`, seven basic blocks, and cyclomatic complexity `3`. `ByteSpanAddRows` disassembly reconfirmed the caller stack contract before `call sub_461050` and the post-call `blocks * 8` source/destination advancement.
- IDA database updates: none. Existing IDA function boundary is correct, and the documentation label/original helper prototype remains below the safe rename threshold.
- Validation: `python .\tools\validator.py --queue-timeout 300 --mode file --file by-memory/0x00461050-0x0046109e.ByteSpanAdd8Blocks.md --apply` exited `0`, `ok: 1`; validator recorded `completion_update 00020H ... 85`.
- Memory ranges: `python .\tools\memory_ranges.py report -advanced-scan` exited `0` and rewrote `auto-generated/by-memory-tool-report.md`; `0x00461050-0x0046109e.ByteSpanAdd8Blocks.md` is no longer listed in `Advanced-Error-Scan`.

Supervisor-applied `by-memory/-coverage-report.md` replacement row:

- Supervisor applied and validated the [UID:00020H] replacement row on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --queue-timeout -1`; result `ok: 1`.
- No supervisor-owned rows remain pending for this item.

## 2026-06-13 Agent-C001 Goal 2 ByteSpanSubtract8Blocks Advanced-Scan Repair

- Changed docs: [UID:00020I][0x004610a0-0x004610ee.ByteSpanSubtract8Blocks](../../../../by-memory/0x004610a0-0x004610ee.ByteSpanSubtract8Blocks.md) and this notes file. `auto-generated/by-memory-tool-report.md` was regenerated by `memory_ranges.py`.
- Warning disposition: real documentation-label mismatch, not a range/name/ownership error. The filename label `ByteSpanSubtract8Blocks` is valid compact spelling for the byte-span eight-byte subtract helper, but the page title/body used only expanded `Byte Span Subtract 8-Byte Blocks` wording.
- Score/routing changes: [UID:00020I] `82/90 -> 85/90`, `RECONSTRUCTABLE:TRUE` unchanged, parent/emitter remain [UID:0000NT][SoftwareBlend16](../../../../by-file/SoftwareBlend16.md), range remains `0x004610a0-0x004610ee`. The parent already clears the gate at `86/88`; direct row-helper caller [UID:00020E] remains support evidence, not the source parent.
- Evidence summary: live session-aware IDA 9.1 MCP session `b001_0003lq` reconfirmed `sub_4610A0` at `0x004610a0`, size `0x4e`, with 37 decoded instructions; `0x004610ee` is not a function and successor `0x004610f0` is `sub_4610F0`. `analyze_function` reports no callees, caller `sub_460F10`, one inbound code xref at `0x00460f3f`, seven basic blocks, and cyclomatic complexity `3`; Hex-Rays decompiles the body as six-argument `__m64 *` row/pitch/block work using `_m_psubb`. `ByteSpanSubtractRows` disassembly reconfirmed the caller stack contract before `call sub_4610A0` and the post-call `blocks * 8` source/destination advancement. `get_bytes` for `0x0046109e` size `82` shows two leading `0xcc` bytes, the exact helper body, and two trailing `0xcc` bytes; `make_signature_for_range 0x0046109e-0x004610f0` returned a unique signature.
- IDA database updates: none. Existing IDA function boundary is correct, and the documentation label/original helper prototype remains below the safe rename threshold.
- Validation: `python .\tools\validator.py --queue-timeout 300 --mode file --file by-memory/0x004610a0-0x004610ee.ByteSpanSubtract8Blocks.md --apply` exited `0`, `ok: 1`; validator recorded `completion_update 00020I ... 85`.
- Memory ranges: `python .\tools\memory_ranges.py report -advanced-scan` exited `0` and rewrote `auto-generated/by-memory-tool-report.md`; `0x004610a0-0x004610ee.ByteSpanSubtract8Blocks.md` is no longer listed in `Advanced-Error-Scan`.

Supervisor-applied `by-memory/-coverage-report.md` replacement row:

- Supervisor applied and validated the [UID:00020I] replacement row on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --queue-timeout -1`; result `ok: 1`.
- No supervisor-owned rows remain pending for this item.

## 2026-06-14 Agent-C001 Goal 2 RData Label Advanced-Scan Repair

- Changed docs: [UID:00024R][0x006104f4-0x00610ed8.MiniMapRankingReadOnlyData](../../../../by-memory/0x006104f4-0x00610ed8.MiniMapRankingReadOnlyData.md), [UID:000255][0x00618e50-0x00618efc.DirectXBitmapReadOnlyData](../../../../by-memory/0x00618e50-0x00618efc.DirectXBitmapReadOnlyData.md), [UID:000257][0x006192c6-0x00619340.BinaryCodecDatReadOnlyData](../../../../by-memory/0x006192c6-0x00619340.BinaryCodecDatReadOnlyData.md), [UID:00025C][0x0061a45c-0x0061a5c4.FolderSelectTreeReadOnlyData](../../../../by-memory/0x0061a45c-0x0061a5c4.FolderSelectTreeReadOnlyData.md), and this notes file.
- Warning disposition: all four assigned advanced-scan entries were scanner-visible compressed-label/provenance issues only. No page range, filename, canonical owner, emitter routing, reconstructable flag, or by-structure split changed. No IDA database edits were applied.
- IDA evidence summary: live IDA MCP `entity_query` rechecked the `.rdata` names around each span. MiniMap/Ranking still splits across MiniMap/MiniMapVersionManager, Ranking, SoftwareBlend16 constants, and `AboveFrame` successor data; DirectX/DIBitmap still ends before `EmployeeDialogPane`; BinaryCodec/DAT still ends before the `Error` vtable run; FolderSelect/FolderTree still ends before `TREEICON.EPF` successor data.

Supervisor-applied `by-memory/-coverage-report.md` replacements:

- Supervisor applied and validated the [UID:000255] `DirectXBitmapReadOnlyData` and [UID:00025C] `FolderSelectTreeReadOnlyData` replacement rows on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 RData Label Advanced-Scan Repair supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Agent-C001 Goal 2 Refreshed Low-Confidence Class/File Batch

- Changed docs: [UID:0000LM][MSGHandler](../../../../by-file/MSGHandler.md), [UID:00008S][MSGHandler](../../../../by-class/MSGHandler.md), [UID:00006U][ItemHelpPane](../../../../by-class/ItemHelpPane.md), [UID:0000A9][PatchPane](../../../../by-class/PatchPane.md), [UID:0000FP][UserLookPane](../../../../by-class/UserLookPane.md), `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, and this notes file.
- Score changes: [UID:0000LM] `84/82 -> 86/85`; support [UID:00008S] `82/86 -> 85/87`; [UID:00006U] `86/82 -> 86/86`; [UID:0000A9] `86/82 -> 86/85`; [UID:0000FP] `86/82 -> 86/86`.
- Evidence summary: live IDA MCP session `b001_0003gy` reconfirmed MSGHandler method/vtable/app-exchange anchors; ItemHelpPane method sizes, helper edges, four constructor callers, 20 singleton xrefs, vtable heads, and literal-table boundary; PatchPane method island, single app-startup constructor caller, secondary-vtable packet callback, action-helper graph, script/launch strings, and vtable refs; UserLookPane method/stub boundaries, single GeneralPurposePanel constructor caller, parse/render/input vtable refs, child vtables, MoreInfo slot, JPF decode call, and rdata successor boundary.
- IDA database updates: none. Rejected IDA candidates: no generic `sub_` method/helper names, prototypes, class layouts, vtables, or field names were changed because the remaining source names/layout details are not low-risk enough for C-agent IDA edits.
- Validation: the sequential loop `python .\tools\validator.py --queue-timeout 300 --mode file --file <file> --apply` for the seven touched by-* docs exited `0`; each file scan completed with `ok: 1` because the loop exited on first nonzero status. The MSGHandler file scan recorded `completion_update 0000LM ... 86` and `confidence_update 0000LM ... 85`; the subsequent scans completed successfully and refreshed UID/autogen state.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none required. No by-memory rows, ranges, owners, emitters, or reconstructable flags changed in this batch, and the temporary supervisor rule was respected.

## 2026-06-14 Agent-C001 Goal 2 Refreshed Low-Confidence File Batch 0000IA-0000NM

- Changed docs: [UID:0000IA][ClanDialogs](../../../../by-file/ClanDialogs.md), [UID:0000IL][CursorManager](../../../../by-file/CursorManager.md), [UID:0000IX][EditablePaperPane](../../../../by-file/EditablePaperPane.md), [UID:0000NM][SelfSaveInputPane](../../../../by-file/SelfSaveInputPane.md), `by-file/-coverage-report.md`, and this notes file.
- Score changes: [UID:0000IA] `86/82 -> 86/85`; [UID:0000IL] `86/82 -> 86/85`; [UID:0000IX] `86/82 -> 86/85`; [UID:0000NM] `86/82 -> 86/85`.
- Evidence summary: live IDA MCP session `b001_0003gy` reconfirmed ClanDialogs modeled submitter/core functions, zero exact raw-constructor xrefs, contiguous clan-dialog vtable sequence, and representative vtable stores; CursorManager helper sizes/callees, `SetCursor`/`ShowCursor` behavior, broad `g_pScreenPane` use, and no function/xrefs at `0x00559080`; EditablePaperPane method sizes, direct MapPane construction refs, adjustor/destructor/vtable boundaries, `LINE001.EPD` successor data, false LodePNG ownership, and uncalled wrapper starts; SelfSaveInputPane raw non-function starts, modeled handler/factory sizes, vtable-only handler reachability, paired factory/raw constructor vtable stores, `BlockListenInputPane` successor boundary, and shared packet-sender caveat.
- IDA database updates: none. Rejected IDA candidates: no generic `sub_` function names, wrapper names, globals, vtables, class layouts, prototypes, calling conventions, or field names were changed because final source names/layout details remain below the C-agent safe-edit threshold.
- Validation: sequential loop `python .\tools\validator.py --queue-timeout 300 --mode file --file <file> --apply` for `by-file/ClanDialogs.md`, `by-file/CursorManager.md`, `by-file/EditablePaperPane.md`, `by-file/SelfSaveInputPane.md`, and `by-file/-coverage-report.md` exited `0`; each file scan reached `ok: 1`. The first scan recorded `confidence_update 0000IA ... 85`; the loop exited on first nonzero status, so all five scans completed successfully.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none required. No by-memory docs, rows, ranges, owners, emitters, or reconstructable flags changed in this batch, and the temporary supervisor rule was respected.

## 2026-06-14 Agent-C001 Goal 2 0003NO NewOptionPane Raw Packet Helper

- Changed docs: [UID:0003NO][0x00540ea0-0x00540ee8.NewOptionPaneSendOptionPacket11BSubcommand63](../../../../by-memory/0x00540ea0-0x00540ee8.NewOptionPaneSendOptionPacket11BSubcommand63.md) and this notes file.
- Score changes: [UID:0003NO] `80/82 -> 86/88`, combined `81.0 -> 87.0`; `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000M7`, `EMITTER_UIDS:0000M7`, filename, and blank C++ block unchanged.
- Evidence summary: live session-aware IDA MCP session `b001_0002bd` reconfirmed active `NexusTK.exe.i64`, raw non-function status at `0x00540ea0`, neighboring modeled functions at `0x00540db0`, `0x00540e50`, and `0x00541040`, stack-cookie packet writes for opcode `0x011b`, subcommand `0x63`, two caller low bytes, local unsent zero terminator, `dword_67A7EC`, queue/send call `0x00540ed6 -> 0x00574bb0`, no inbound xrefs or operand refs to the raw start, static-zero packet-sender storage, and `0xcc` alignment before/after the raw body. `int_convert.py` verified the opcode/subcommand decimal values.
- IDA database updates: none. I skipped `define_func`, renames, comments, prototypes, and global/type/member changes because the helper still has no inbound call path and the source-visible method/helper name remains below the C-agent safe-edit threshold.
- Validation: `python .\tools\validator.py --queue-timeout 300 --mode file --file by-memory\0x00540ea0-0x00540ee8.NewOptionPaneSendOptionPacket11BSubcommand63.md --apply` exited `0`, `ok: 1`; validator recorded `completion_update 0003NO ... 86`, `confidence_update 0003NO ... 88`, removed [UID:0003NO] from `project-level/-auto-completion-stats.md` Low_Confidence, and recommended occasional stats rescore after enough rows drop.

Supervisor-applied `by-memory/-coverage-report.md` replacement row:

- Supervisor applied and validated the [UID:0003NO] replacement row on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No supervisor-owned rows remain pending for this item.

## 2026-06-14 Agent-C001 Goal 2 0000OY UserInfoDialogPane

- Changed docs: [UID:0000OY][UserInfoDialogPane](../../../../by-file/UserInfoDialogPane.md), [UID:0001KG][0x00599cc0-0x0059bc8b.UserInfoDialogPane](../../../../by-memory/0x00599cc0-0x0059bc8b.UserInfoDialogPane.md), `by-file/-coverage-report.md`, and this notes file.
- Score changes: [UID:0000OY] `86/82 -> 88/86`, combined `84.0 -> 87.0`; [UID:0001KG] `86/84 -> 88/86`; by-file coverage row synchronized to `88% : strong`. Ownership, projected path, reconstructable flags, emitters, and blank C++ blocks unchanged.
- Evidence summary: live session-aware IDA MCP session `b001_0002bd` reconfirmed active `NexusTK.exe.i64`, all UserInfoDialogPane method starts/sizes, no function at `0x0059bc8b`, successor `UserListDialogPane` function at `0x0059bc90`, command-handler calls to validation and send helpers, adjustor thunk jumps to the scalar deleting destructor, constructor vtable refs into [UID:00026T], no direct constructor xref, no constructor operand reference in the main login/account range `0x004f6700-0x004fb62a`, and byte-level padding/vtable lead-in. `int_convert.py`/IDA MCP conversions verified `0x53`, subtype `1`, `0x80`, `0x1330`, and `0x66c`.
- IDA database updates: none. I skipped safe-looking names/comments because the remaining source-visible helper names, field names, and constructor launch path are still not high-confidence enough for C-agent IDA edits.
- Validation: sequential loop `python .\tools\validator.py --queue-timeout 300 --mode file --file <file> --apply` for `by-file\UserInfoDialogPane.md`, `by-memory\0x00599cc0-0x0059bc8b.UserInfoDialogPane.md`, and `by-file\-coverage-report.md` exited `0`; each validator job reached `ok: 1`. The first scan recorded `completion_update 0000OY ... 88`, `confidence_update 0000OY ... 86`, and removed [UID:0000OY] from `project-level/-auto-completion-stats.md` Low_Confidence and by-file rows.

Supervisor-applied `by-memory/-coverage-report.md` replacement row:

- Supervisor applied and validated the [UID:0001KG] replacement row on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No supervisor-owned rows remain pending for this item.

## 2026-06-14 Agent-C001 Goal 2 0000IK CreateUserDialogs

- Changed docs: [UID:0000IK][CreateUserDialogs](../../../../by-file/CreateUserDialogs.md), `by-file/-coverage-report.md`, and this notes file. No by-memory docs changed.
- Score changes: [UID:0000IK] `88/82 -> 89/86`, combined `85.0 -> 87.5`; by-file coverage row synchronized to `89% : strong`.
- Evidence summary: live session-aware IDA MCP session `b001_0002bd` reconfirmed active `NexusTK.exe.i64`, create-user variant starts/sizes, launcher xrefs to `0x0052a540` and `0x0052dd30`, no direct xref to `0x0052c360`, `0x004f8fa0` branch behavior, shared submit/packet/reply component shape, vtable/singleton xrefs, `NewUserShapeSelectControlPane` and `NewUserMiscDialogPane` constructor edges, and boundary/padding bytes through `0x0052f94c-0x0052f950`.
- IDA database updates: none. No names/comments/prototypes/types were changed because the remaining source-visible helper/field names and final folded-vs-standalone split are not safe enough for C-agent IDA edits.
- Validation: sequential loop `python .\tools\validator.py --queue-timeout 300 --mode file --file <file> --apply` for `by-file\CreateUserDialogs.md` and `by-file\-coverage-report.md` exited `0`; each scan reached `ok: 1`. The target scan recorded `completion_update 0000IK ... 89`, `confidence_update 0000IK ... 86`, and removed [UID:0000IK] from `project-level/-auto-completion-stats.md` Low_Confidence.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none required because no by-memory page, range, owner, emitter, or score changed.

## 2026-06-14 Agent-C001 Goal 2 0000J3 EPFImageResources

- Changed docs: [UID:0000J3][EPFImageResources](../../../../by-file/EPFImageResources.md), [UID:0000QU][g_pEPFLib](../../../../by-global/g_pEPFLib.md), `by-file/-coverage-report.md`, `by-global/-coverage-report.md`, and this notes file. No by-memory docs changed.
- Score changes: [UID:0000J3] `88/82 -> 89/86`, combined `85.0 -> 87.5`; [UID:0000QU] `88/82 -> 89/86`; by-file and by-global coverage rows synchronized to `89% : strong`.
- Evidence summary: live session-aware IDA MCP session `b001_0002bd` reconfirmed active `NexusTK.exe.i64`, `g_pEPFLib` storage at `0x0067a744`, zero-initialized storage neighborhood, ImageLib lifecycle writes/clears, ImageLib vtable refs limited to constructor/destructor-family code, broad consumer reads, ResourceLayout public API starts and lazy-load edges, frame-table/raw-helper boundaries, and `int_convert.py` conversions for key constants.
- IDA database updates: none. I skipped names/comments/prototypes/types because exact original filenames and the final ImageLib-vs-ResourceLayout declaration/facet boundary remain below the C-agent safe-edit threshold.
- Validation: sequential loop `python .\tools\validator.py --queue-timeout 300 --mode file --file <file> --apply` for `by-file\EPFImageResources.md`, `by-global\g_pEPFLib.md`, `by-file\-coverage-report.md`, and `by-global\-coverage-report.md` exited `0`; each scan reached `ok: 1`. The target scan recorded `completion_update 0000J3 ... 89`, `confidence_update 0000J3 ... 86`, and removed [UID:0000J3] from `project-level/-auto-completion-stats.md` Low_Confidence.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none required because no by-memory page, range, owner, emitter, reconstructable flag, or score changed.

## 2026-06-14 Agent-C001 Goal 2 Low-Score By-Resource Batch 0001RF-0001RS

- Changed docs: [UID:0001RF][main-menu-history-resources](../../../../by-resource/main-menu-history-resources.md), [UID:0001RG][main-menu-story-resources](../../../../by-resource/main-menu-story-resources.md), [UID:0001RS][user-status-resources](../../../../by-resource/user-status-resources.md), `by-resource/-coverage-report.md`, and this notes file. No by-memory/by-file/by-class/by-global docs changed.
- Score changes: [UID:0001RF] `78/85 -> 85/88`; [UID:0001RG] `78/85 -> 85/88`; [UID:0001RS] `78/86 -> 86/88`. `CANONICAL_OWNER:NONE` remains unchanged for all three because the history/story pages are intentionally multi-owner resource sets and user-status resources still include shared palette/BAR caveats.
- Evidence summary: active IDA session `a001_goal2_class_batch` was enumerated with `idb_list`; live IDA MCP reconfirmed owner function bounds, literal xrefs, and UTF-16 bytes for `STORY.*`, `HISTORY.*`, `HISTORYN.*`, `MADEBY`, `BACKTALE`, `PAL01.PAL`, `NPAL8.PAL`, `NPAL4.PAL`, `USERSTAT.*`, `NATION.EPD`, `TOTEM.EPD`, `CLASS.EPD`, `BAR.EPD`, `BAR.EPF`, `BAR.PAL`, `COMMA.*`, `9X11FONT.BIN`, `NPAL7.PAL`, `NPAL5.PAL`, and `ITEMINV.PAL`. `int_convert.py` verified all newly documented function-size decimal conversions.
- IDA database updates: none. Skipped candidates: no string/function names or comments were changed because resource literal names are already explicit in `.rdata`, and helper/source ownership for shared palettes and BAR resources remains below the C-agent safe-edit threshold.
- Validation: sequential loop `python .\tools\validator.py --queue-timeout 300 --mode file --file <file> --apply` for the three target resource docs and `by-resource/-coverage-report.md` exited `0`; each scan reached `ok: 1`. The first scan recorded `completion_update 0001RF ... 85`, `confidence_update 0001RF ... 88`, and refreshed projected stats; follow-up `Select-String` confirmed `project-level/-auto-completion-stats.md` now lists [UID:0001RF] at `85/88`, [UID:0001RG] at `85/88`, and [UID:0001RS] at `86/88`.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none required because no by-memory page, range, owner, emitter, reconstructable flag, or score changed.

## 2026-06-14 Agent-C001 Goal 2 Low-Score By-Item Batch 0000UK-0000UV

- Changed docs: [UID:0000UK][DrawTextRunCallback_00593DB0](../../../../by-item/DrawTextRunCallback_00593DB0.md), [UID:0000UP][FriendNameListSyncOpcodes](../../../../by-item/FriendNameListSyncOpcodes.md), [UID:0000UV][InitializeMainUiGraph_004F7D10](../../../../by-item/InitializeMainUiGraph_004F7D10.md), [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](../../../../by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md), [UID:0000PG][byte_66DEE0](../../../../by-global/byte_66DEE0.md), `by-item/-coverage-report.md`, `by-global/-coverage-report.md`, and this notes file.
- Score changes: [UID:0000UK] `78/86 -> 85/88`; [UID:0000UP] `78/86 -> 85/88`; [UID:0000UV] `78/86 -> 86/88`; supporting [UID:00019K] `78/86 -> 86/88`; supporting [UID:0000PG] `86/84 -> 87/87`. Ownership, emitter routing, reconstructable flags, and blank final C++ blocks are unchanged, except the [UID:0000UP] coverage row now correctly identifies the page as protocol routing because the page itself is `RECONSTRUCTABLE:FALSE`.
- Evidence summary: live IDA MCP session `b001_0002bd` reconfirmed active `NexusTK.exe.i64`; `DrawTextRunCallback` exact size, two address-taking xrefs, callee family, no-function successor checks, and byte tail/padding; friend name-list sync primary/raw inbound flag writes, sender-helper refs, flag initialization byte, outbound helper size/callees, and verified opcode/config offsets; `InitializeMainUiGraph` exact size, padding at both boundaries, sole login-success caller, `g_pMainUiGraph` handoff, layer-slot refs, callee family, and decompiler new/old branch plus common tail; and `g_friendNameListSyncEnabled` exact xrefs/initialized byte evidence.
- IDA database updates: none. Skipped candidates: no callback/global/function renames, comments, prototypes, or type edits because final source-facing callback signatures, graph/helper names, friend-sync linkage spelling, and broader structure layouts remain below the C-agent safe-edit threshold.
- Validation: sequential loop `python .\tools\validator.py --queue-timeout 300 --mode file --file <file> --apply` for the three item docs, supporting MainUiGraph memory page, supporting friend-sync global, `by-item/-coverage-report.md`, and `by-global/-coverage-report.md` exited `0`; each scan reached `ok: 1`. The first scan recorded [UID:0000UK] completion/confidence updates and stats removal, and follow-up `Select-String` found no `0000UK`, `0000UP`, `0000UV`, `00019K`, or `0000PG` rows in `project-level/-auto-completion-stats.md`.
- Supervisor applied and validated the [UID:00019K] `by-memory/-coverage-report.md` replacement row on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 Low-Score By-Item Batch 0000UK-0000UV supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Agent-C001 Goal 2 0000L7 MemoryMan

- Changed docs: [UID:0000L7][MemoryMan](../../../../by-file/MemoryMan.md), `by-file/-coverage-report.md`, and this notes file. No supporting by-memory/by-global/by-class/by-type docs changed.
- Score changes: [UID:0000L7] `88/82 -> 89/86`, combined `85.0 -> 87.5`; by-file coverage row synchronized to `89% : strong`.
- Evidence summary: live session-aware IDA MCP session `b001_0002bd` reconfirmed active `NexusTK.exe.i64`, all MemoryMan/operator/helper starts, no function at local `0x00516040` or island end `0x0051628e`, successor function at `0x00516290`, static object refs for `0x0069b3a8`, singleton refs for `0x0069b4fc`, vtable refs for `0x0061eb08`, operator wrapper call edges, allocation failure throw path through `Win32Error` typeinfo, and copy-wrapper memmove callees.
- IDA database updates: none. I skipped names/comments/prototypes/types because final global operator placement, copy-wrapper ownership, and exact header/API spelling remain below the C-agent safe-edit threshold.
- Validation: sequential loop `python .\tools\validator.py --queue-timeout 300 --mode file --file <file> --apply` for `by-file\MemoryMan.md` and `by-file\-coverage-report.md` exited `0`; both scans reached `ok: 1`. The target scan recorded `completion_update 0000L7 ... 89`, `confidence_update 0000L7 ... 86`, and removed [UID:0000L7] from `project-level/-auto-completion-stats.md` Low_Confidence.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none required because no by-memory page, range, owner, emitter, reconstructable flag, or score changed.

## 2026-06-14 Agent-C001 Goal 2 Low-Confidence Global Batch 0000PR-0000R5

- Changed docs: [UID:0000PR][g_activeMapPane](../../../../by-global/g_activeMapPane.md), [UID:0000QI][g_pChangeMan](../../../../by-global/g_pChangeMan.md), [UID:0000QX][g_pFontImageLib](../../../../by-global/g_pFontImageLib.md), [UID:0000R5][g_pHumanImageLib](../../../../by-global/g_pHumanImageLib.md), `by-global/-coverage-report.md`, and this notes file. No by-memory docs changed.
- Score changes: [UID:0000PR] `88/82 -> 89/86`; [UID:0000QI] `88/82 -> 89/86`; [UID:0000QX] `88/82 -> 89/86`; [UID:0000R5] `88/82 -> 89/86`. Each target moved from combined `85.0` to `87.5`; global coverage rows synchronized to `89% : strong`.
- Evidence summary: live session-aware IDA MCP session `b001_0002bd` reconfirmed active `NexusTK.exe.i64`, storage non-function status for all four globals, `g_activeMapPane` MapPane constructor/teardown/clear/application-transition refs and vtable sharing, `g_pChangeMan` exact 11-ref lifecycle/consumer set and Application wrapper forwarding, `g_pFontImageLib` exact 52-ref lifecycle/consumer set and FontImageLib vtable context, and `g_pHumanImageLib` exact four-ref lifecycle set plus old-human resource table/vtable/layout context. `int_convert.py` verified `0x3f0` as decimal 1008 for the active-map field offset.
- IDA database updates: none. I skipped global renames/comments/prototypes/types because final source spelling/linkage remains provisional for the singletons, and broader type/prototype edits are outside the C-agent safe-edit threshold.
- Validation: sequential loop `python .\tools\validator.py --queue-timeout 300 --mode file --file <file> --apply` for the four global docs and `by-global\-coverage-report.md` exited `0`; each scan reached `ok: 1`. The first target scan recorded `completion_update 0000PR ... 89`, `confidence_update 0000PR ... 86`, and removed [UID:0000PR] from `project-level/-auto-completion-stats.md` Low_Confidence/by-global; subsequent scans completed successfully for [UID:0000QI], [UID:0000QX], [UID:0000R5], and the coverage report.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none required because no by-memory page, range, owner, emitter, reconstructable flag, or score changed.

## 2026-06-14 Agent-C001 Goal 2 Low-Confidence / Low-Both By-Memory Batch 0002BG-0002HG

- Changed docs: [UID:0002BG][0x0048f400-0x0048f4cf.CommandLineArgumentCounter](../../../../by-memory/0x0048f400-0x0048f4cf.CommandLineArgumentCounter.md), [UID:0002BI][0x0048f6d0-0x0048fc96.NetsgoStartupAuthenticationParser](../../../../by-memory/0x0048f6d0-0x0048fc96.NetsgoStartupAuthenticationParser.md), [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](../../../../by-memory/0x0049bd30-0x0049d6ed.DATManagers.md), [UID:0002HG][0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand](../../../../by-memory/0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md), and this notes file.
- Score changes: [UID:0002BG] `78/84 -> 85/86`; [UID:0002BI] `78/84 -> 85/86`; [UID:00012B] `78/84 -> 86/88`; [UID:0002HG] `78/84 -> 85/88`. Validator also normalized legacy reconstruction metadata headers on these pages to current `CANONICAL_OWNER`/`EMITTER_UIDS` fields; owners, emitters, ranges, reconstructable flags, and blank final C++ blocks are unchanged semantically.
- Evidence summary: live IDA MCP session `b001_0002bd` reconfirmed active `NexusTK.exe.i64`, raw no-function/no-direct-xref status and byte boundaries for the two RegistryConfig command-line parser starts, token/count/offset evidence through `get_bytes` and `int_convert`, DAT manager/container/resolver modeled function map and decompilation/xref/endpoint evidence, and EmployeeItemPropertyDialogPane command-handler decompilation, vtable-slot xref, callees, boundary bytes, and verified field-offset conversions.
- IDA database updates: none. Skipped candidates: no `define_func`/rename/comment/prototype/type changes for the two raw parser starts because no inbound path/source-visible name is proven; no DAT names/types because field names/raw destructor/forwarder splits remain open; no Employee command-handler rename/prototype/field names because final source-visible control and pending-field names remain provisional.
- Validation: sequential loop `python .\tools\validator.py --queue-timeout 300 --mode file --file <file> --apply` for the four changed by-memory docs exited `0`; each scan reached `ok: 1`. The first scan recorded `completion_update 0002BG ... 85`, `confidence_update 0002BG ... 86`, and removed [UID:0002BG] from Low_Confidence, Low_Both, and by-memory stats rows; subsequent scans completed successfully for [UID:0002BI], [UID:00012B], and [UID:0002HG].

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

- Supervisor applied and validated the [UID:0002BG], [UID:0002BI], [UID:00012B], and [UID:0002HG] replacement rows on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 Low-Confidence / Low-Both By-Memory Batch 0002BG-0002HG supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Agent-C001 Goal 2 Low-Confidence By-Memory Batch 00015D-0002V8

- Changed docs: [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](../../../../by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md), [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](../../../../by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md), [UID:0002V8][0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds](../../../../by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md), [UID:00017R][0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster](../../../../by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md), [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](../../../../by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md), [UID:000092][NewHumanImageLib](../../../../by-class/NewHumanImageLib.md), [UID:0000LR][NewHumanImageLib](../../../../by-file/NewHumanImageLib.md), [UID:0000N5][ResourceLayoutTable](../../../../by-file/ResourceLayoutTable.md), [UID:000174][0x004d0120-0x004d182f.ResourceLayoutTable](../../../../by-memory/0x004d0120-0x004d182f.ResourceLayoutTable.md), [UID:000172][0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex](../../../../by-memory/0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex.md), [UID:0002KU][0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex](../../../../by-memory/0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex.md), `project-level/-auto-completion-stats.md`, `tools/validator.ini`, `auto-generated/-ag-memory-coverage.md`, and this notes file. The old [UID:0002V8] file path `by-memory/0x004e31f0-0x004e3a2d.NewHumanImageLibCalculateCompositionBounds.md` was renamed to the corrected half-open end `0x004e3a2e`.
- Score changes: [UID:00015D] `78/84 -> 85/86`, combined `81.0 -> 85.5`; [UID:00022H] `78/84 -> 85/86`, combined `81.0 -> 85.5`; [UID:0002V8] `78/84 -> 86/87`, combined `81.0 -> 86.5`. Ownership, emitters, reconstructable flags, and blank final C++ blocks remain unchanged. [UID:0002V8] range/title/path changed from `0x004e31f0-0x004e3a2d` to `0x004e31f0-0x004e3a2e` to match IDA's `0x83e` function size.
- Evidence summary: live IDA MCP session `b001_0002bd` reconfirmed active `NexusTK.exe.i64`. For [UID:00015D], IDA reconfirmed modeled/unmodeled FpsPane starts, predecessor/successor boundaries, vtable/global refs, raw logging/session callsites, ObjectList/timer stats dependencies, and scalar-deleting destructor thunk flow. For [UID:00022H], IDA reconfirmed adjacent modeled functions, exact `0xcc` padding, `retn 4` endpoints, local `0.25f`/`0.5f` instruction sites, and no direct xrefs to either raw helper start. For [UID:0002V8], IDA reconfirmed `sub_4E31F0` size `0x83e` / 2110 bytes, two direct callers, callee set, 42 internal calls, two `0x004d05a0` overlay-rectangle callsites, `retn 1Ch` ending at `0x004e3a2e`, and the separate orphan composition gap before `0x004e4140`.
- IDA database updates: none. Skipped candidates: no `define_func`/rename/comment/prototype/type changes for the FpsPane raw starts or RectBounds raw helpers because direct caller/liveness/source-visible name evidence remains incomplete; no NewHuman helper/field/prototype changes because final avatar-state fields, helper names, and the adjacent orphan composition code remain below the C-agent safe-edit threshold.
- Validation: initial report-only sequential scan `python .\tools\validator.py --queue-timeout 120 --mode file --file <file>` for all eleven changed by-* docs exited `0`. Applied scans then ran for the three target docs: `python .\tools\validator.py --queue-timeout 120 --mode file --file by-memory\0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md --apply` exited `0` with `ok: 1`, `path_update 0002V8`, `completion_update 0002V8 ... 86`, `confidence_update 0002V8 ... 87`, and Low_Confidence removal; sequential applied scans for `by-memory\0x004b6410-0x004b6caf.FpsPaneDiagnostics.md` and `by-memory\0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md` exited `0` and removed [UID:00015D]/[UID:00022H] from Low_Confidence, Low_Both, and by-memory stats rows. `project-level/-auto-completion-stats.md` now reports `_No scored files._` under Low_Confidence.
- Coverage-report note: the [UID:0002V8] applied validator scan automatically updated only the UID link text/path in `by-memory/-coverage-report.md`. I did not manually edit that supervisor-owned report; the three rows below remain pending for supervisor application because scores/ranges/summaries are still stale there.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

- Supervisor applied and validated the [UID:00015D], [UID:00022H], and [UID:0002V8] replacement rows on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 Low-Confidence By-Memory Batch 00015D-0002V8 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Agent-C001 Goal 2 Low-Completion By-Memory Batch 0002JN-00010M

- Changed docs: [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](../../../../by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md), [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](../../../../by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md), [UID:00010M][0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters](../../../../by-memory/0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters.md), validator-owned `project-level/-auto-completion-stats.md`, and this notes file.
- Score changes: [UID:0002JN] `76/87 -> 86/88`, combined `81.5 -> 87.0`; [UID:00010K] `76/88 -> 85/89`, combined `82.0 -> 87.0`; [UID:00010M] `76/88 -> 85/89`, combined `82.0 -> 87.0`. Ownership, emitter routing, reconstructable flags, and blank final C++ blocks are unchanged.
- Evidence summary: live IDA MCP session `b001_0002bd` reconfirmed active `NexusTK.exe.i64`. For [UID:0002JN], IDA reconfirmed `sub_4DAC40` size `0x27d` / 637 bytes, constructor-only direct caller `0x004dafee`, constructor-to-loader component edge, DAT-reader/vector/nested-table callees, 24-block loader complexity, and epilogue/padding before constructor successor `0x004daec0`; local `int_convert.py` verified the key size/count constants. For [UID:00010K], IDA reconfirmed the six vtable-backed clan name/money submitters, `0x82` / 130 and `0xee` / 238 byte sizes, no xrefs to constructor-shaped raw starts, packet-building callee families, shared `dword_67A7EC` sender context, and representative pre/post padding bytes. For [UID:00010M], IDA reconfirmed the enlist/change/leave vtable-backed callbacks, `0x29` / 41 and `0x0e` / 14 byte sizes, helper-call targets, no xrefs to raw constructor starts, and byte-level padding/constructor-shaped raw bodies.
- IDA database updates: none. Skipped candidates: no MonsterImageLib helper/type/field names because nested table and source-visible field names remain provisional; no Clan raw constructor function definitions, names, prototypes, or comments because the raw starts still lack direct xrefs/reachability proof and final source form; no callback renames because docs carry the current evidence without needing low-confidence IDA database edits.
- Validation: sequential applied loop `python .\tools\validator.py --queue-timeout 120 --mode file --file <file> --apply` for the three changed by-memory docs exited `0`. The [UID:0002JN] scan showed `ok: 1`, `completion_update 0002JN ... 86`, `confidence_update 0002JN ... 88`, and Low_Completion removal; the loop completed successfully for [UID:00010K] and [UID:00010M] as well. Follow-up `rg -n "0002JN|00010K|00010M" project-level/-auto-completion-stats.md` returned no matches.
- Supervisor applied and validated the [UID:00010K], [UID:00010M], and [UID:0002JN] `by-memory/-coverage-report.md` replacement rows on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 Low-Completion By-Memory Batch 0002JN-00010M supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Agent-C001 Goal 2 Low-Completion HierList Support Batch 0002IA-0002IB

- Changed docs: [UID:0002IA][0x004ce7e0-0x004ce839.HierListTailInsertWrapper](../../../../by-memory/0x004ce7e0-0x004ce839.HierListTailInsertWrapper.md), [UID:0002IB][0x004ce840-0x004ce854.HierListDefaultInsertWrapper](../../../../by-memory/0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md), [UID:0000JV][HierList](../../../../by-file/HierList.md), `by-file/-coverage-report.md`, validator-owned `project-level/-auto-completion-stats.md`, validator-owned `auto-generated/-ag-file-coverage.md`, validator-owned `auto-generated/-ag-memory-coverage.md`, validator state, and this notes file.
- Score changes: [UID:0002IA] `76/88 -> 85/89`, combined `82.0 -> 87.0`; [UID:0002IB] `76/88 -> 85/89`, combined `82.0 -> 87.0`; [UID:0000JV] `82/85 -> 85/87`, combined `83.5 -> 86.0`. [UID:0002IA] direct owner/emitter route corrected from [UID:0000JV] file-level routing to direct [UID:000065][HierList](../../../../by-class/HierList.md) class routing after the class parent already cleared `86/90`; [UID:0002IB] routing was already through [UID:000065].
- Evidence summary: live IDA MCP session `b001_0002bd` reconfirmed active `NexusTK.exe.i64`. `lookup_funcs` reconfirmed no IDA function objects at raw wrapper starts/endpoints `0x004ce7e0`, `0x004ce839`, `0x004ce840`, and `0x004ce854`, while surrounding modeled HierList functions remain stable. `xrefs_to` reconfirmed zero direct xrefs to both raw starts, raw calls to `InsertBefore` at `0x004ce802`, `0x004ce82e`, and `0x004ce84b`, Layer call `0x004f0a3b`, and recursive lookup fan-in through insert/remove/self calls. `get_bytes` reconfirmed the `0xcc` padding boundaries, raw wrapper bodies, `retn 8` tails, and modeled insert-core prologue at `0x004ce860`. `analyze_component` reconfirmed the class-local component, shared HierList vtable `0x0061b344`, internal edges into `FindNodeByData`, and modeled method sizes. Local `int_convert.py` verified all documented decimal conversions for `0x59`, `0x14`, `0x30`, `0x71`, `0x14d`, `0x14c`, `0x45`, `0xdf`, `0x94`, `0xa2`, `0x0c`, `0x08`, and `0x20`.
- IDA database updates: none. Skipped candidates: no `define_func`, rename, comment, prototype, or type edits for the raw wrappers because IDA still has no direct start xrefs and final overload/source-name form is unresolved; no broader HierList type/prototype edits because wrapper/destructor source form and header API spelling remain below the C-agent safe-edit threshold.
- Validation: sequential applied loop `python .\tools\validator.py --queue-timeout 120 --mode file --file <file> --apply` for `by-memory\0x004ce7e0-0x004ce839.HierListTailInsertWrapper.md`, `by-memory\0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md`, `by-file\HierList.md`, and `by-file\-coverage-report.md` exited `0`. The first scan showed `ok: 1`, `completion_update 0002IA ... 85`, `confidence_update 0002IA ... 89`, `canonical_owner_update 0002IA ... 0000JV -> 000065`, `autogen_registry_update 0002IA ... 0000JV -> 000065`, and Low_Completion removal. Follow-up `rg -n "0002IA|0002IB|0000JV" project-level/-auto-completion-stats.md` returned no matches.
- Supervisor applied and validated the [UID:0002IA] and [UID:0002IB] `by-memory/-coverage-report.md` replacement rows on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 Low-Completion HierList Support Batch 0002IA-0002IB supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Agent-C001 Goal 2 Low-Score By-Item Batch 0000VI-0000U7

- Changed docs: [UID:0000VI][StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f](../../../../by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md), [UID:0000U6][BuildTilecArchiveTable_004DDA60](../../../../by-item/BuildTilecArchiveTable_004DDA60.md), [UID:0000U7][CheckBoxControlPaneStateTypeHelper_00499EC0](../../../../by-item/CheckBoxControlPaneStateTypeHelper_00499EC0.md), `by-item/-coverage-report.md`, validator-owned project/generated state, and this notes file.
- Score changes: [UID:0000VI] `79/84 -> 85/87`; [UID:0000U6] `78/86 -> 86/88`; [UID:0000U7] `78/86 -> 85/89`. Ownership, emitters, reconstructable flags, and blank final C++ blocks are unchanged.
- Evidence summary: live IDA MCP session `b001_0002bd` reconfirmed active `NexusTK.exe.i64`; StartupWindow raw helper starts still have no function objects or direct xrefs but have byte-verified prologues/padding plus WndProc/callback refs; `BuildTilecArchiveTable` has one StaticObjImageLib constructor caller, stable `0x3a2` size, padding boundaries, shard-scan/metadata/sentinel cleanup behavior, and DAT/archive-reader callees; `CheckBoxControlPaneStateTypeHelper` has one vtable slot xref, no direct callees, stable `0x4e` size/end, byte boundaries, and decompiled state-byte/type-refresh behavior.
- IDA database updates: none. Skipped candidates: no raw StartupWindow function definitions/names because direct xrefs and source-quality boundaries remain unresolved; no TILEC helper/table/type rename because final helper and table-field names remain provisional; no checkbox helper/prototype/name changes because the inherited refresh-slot name and original source grouping remain open.
- Validation: sequential applied loop `python .\tools\validator.py --queue-timeout 300 --mode file --file <file> --apply` for the three item docs and `by-item/-coverage-report.md` exited `0`; each scan reached `ok: 1`. The first scan removed [UID:0000VI] from `project-level/-auto-completion-stats.md`; follow-up `rg` found no `0000VI`, `0000U6`, or `0000U7` rows in the stats report.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none required because no by-memory page, range, owner, emitter, reconstructable flag, or score changed.

## 2026-06-14 Agent-C001 Goal 2 Low-Completion Memory Batch 0002IE-0002VC

- Changed docs: [UID:0002IE][0x004ceb00-0x004ceb45.HierListRemoveNode](../../../../by-memory/0x004ceb00-0x004ceb45.HierListRemoveNode.md), [UID:0002IM][0x004cedb0-0x004cee52.HierListScalarDeletingDestructor](../../../../by-memory/0x004cedb0-0x004cee52.HierListScalarDeletingDestructor.md), [UID:0002VC][0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor](../../../../by-memory/0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor.md), validator-owned project/generated state, and this notes file.
- Score changes: [UID:0002IE] `76/88 -> 85/89`; [UID:0002IM] `76/88 -> 85/89`; [UID:0002VC] `76/88 -> 85/89`. Ownership, emitter routing, reconstructable flags, ranges, and blank final C++ blocks are unchanged.
- Evidence summary: live IDA MCP session `a001_goal2_class_batch` reconfirmed active `NexusTK.exe.i64`, exact modeled sizes `0x45` / 69, `0xa2` / 162, and `0x5c` / 92, endpoint/no-function checks, Layer caller `0x004f0b25`, HierList vtable-only scalar destructor xref `0x0061b344`, ItemObjImageLib vtable-only scalar destructor xref `0x0061b73c`, relevant vtable/global lifecycle refs, callees, decompiler behavior, component summaries, and byte-level padding.
- IDA database updates: none. Skipped candidates: no function/class/prototype/type/comment edits because the existing IDA names are compiler/decompiler-shaped and final source API names, destructor declaration form, and ABI wrapper representation remain below the C-agent safe-edit threshold.
- Validation: sequential applied loop `python .\tools\validator.py --queue-timeout 300 --mode file --file <file> --apply` for the three changed by-memory docs exited `0`; each scan reached `ok: 1`. The first scan logged `completion_update 0002IE ... 85`, `confidence_update 0002IE ... 89`, and Low_Completion removal. Follow-up `Select-String` found no `0002IE`, `0002IM`, or `0002VC` rows in `project-level/-auto-completion-stats.md`.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

- Supervisor applied and validated the [UID:0002IE], [UID:0002IM], and [UID:0002VC] replacement rows on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 Low-Completion Memory Batch 0002IE-0002VC supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Agent-C001 Supervisor Goal 2 Batch 00019E-0001FW Shared Rows

- Supervisor applied and validated the `by-memory/-coverage-report.md` replacement rows for [UID:00019E], [UID:0001FW], [UID:0002R9], and [UID:0001H9] on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No supervisor-owned `by-memory/-coverage-report.md` rows remain pending from this batch.

## 2026-06-14 Agent-C001 Goal 2 Low-Confidence LivingObjectPane Memory Batch 0002R0-0002R1

- Changed docs: [UID:0002R0][0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup](../../../../by-memory/0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup.md), [UID:0002R1][0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer](../../../../by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md), [UID:0001DE][0x0053a110-0x0053d818.LivingObjectPaneCore](../../../../by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md), [UID:0000KU][LivingObjectPane](../../../../by-file/LivingObjectPane.md), validator-owned generated state, and this notes file.
- Score changes: [UID:0002R0] `78/84 -> 86/88`, combined `81.0 -> 87.0`; [UID:0002R1] `78/84 -> 86/88`, combined `81.0 -> 87.0`; [UID:0001DE] `82/84 -> 85/85`, combined `83.0 -> 85.0`. [UID:0000KU] stayed `88/85`; it only received a stale scattered-accessor cleanup.
- Routing changes: [UID:0002R0] and [UID:0002R1] now route directly through [UID:00007B][LivingObjectPane](../../../../by-class/LivingObjectPane.md) (`85/85`) instead of directly to file [UID:0000KU][LivingObjectPane](../../../../by-file/LivingObjectPane.md) (`88/85`). The generated memory registry now surfaces both through `auto-generated/NexusTK/map/LivingObjectPane.cpp` with no dead end.
- Evidence summary: live IDA MCP session `a001_goal2_class_batch` reconfirmed `NexusTK.exe.i64`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. IDA reconfirmed exact modeled starts/ends for constructors, destructor, animation wrappers, and timer handler; xrefs from MapPane/UserPane/local-player/vtable slots; component callee sets; decompiled vtable stores, construction/destruction behavior, `BoxRotator` at object `+0x1f0`, timer-handler subobject owner math at object `+0xa4`, and raw `0xcc` padding/lowered-data bytes. Local `tools/int_convert.py` verified the five timer message IDs as 4-byte values.
- Structural cleanup: removed stale `0x00537bc0` LivingObjectPane scattered-accessor wording from [UID:0001DE] and [UID:0000KU]. The exact child [UID:0003HS][0x00537bc0-0x00537be9.ItemObjectPaneRecordStateUpdate](../../../../by-memory/0x00537bc0-0x00537be9.ItemObjectPaneRecordStateUpdate.md) remains assigned to [UID:00006V][ItemObjectPane](../../../../by-class/ItemObjectPane.md).
- IDA database updates: none. Skipped candidate function renames/prototypes/comments/field names because constructor signatures, timer-message source names, wrapper declarations, and object fields are not final-source quality; existing IDA vtable names already provide the safe class evidence.
- Validation: sequential applied loop `python .\tools\validator.py --queue-timeout 300 --mode file --file <file> --apply` for the four changed by-* docs exited `0`. The first scan logged `completion_update 0002R0 ... 86`, `confidence_update 0002R0 ... 88`, `canonical_owner_update 0002R0 ... 0000KU -> 00007B`, `autogen_registry_update 0002R0 ... 0000KU -> 00007B`, and removal from Low_Completion, Low_Confidence, Low_Both, and by-memory stats. Follow-up `rg -n "0002R0|0002R1|0001DE" project-level/-auto-completion-stats.md` returned no matches.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

- Supervisor applied and validated the [UID:0001DE], [UID:0002R0], and [UID:0002R1] replacement rows on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 Low-Confidence LivingObjectPane Memory Batch 0002R0-0002R1 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Agent-C001 Goal 2 Refreshed Low-Score Memory Batch 0002QR-00023I

- Changed docs: [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](../../../../by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md), [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](../../../../by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md), [UID:00009E][NewUserDialogPane2](../../../../by-class/NewUserDialogPane2.md), [UID:0002BC][0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers](../../../../by-memory/0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers.md), [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](../../../../by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md), [UID:00023I][0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers](../../../../by-memory/0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers.md), validator-owned generated/autogen state, and this notes file.
- Score changes: [UID:0002QR] `78/84 -> 86/87`; support [UID:00009E] `82/84 -> 85/86`; support [UID:0001CR] `82/84 -> 85/86`; [UID:0002BC] `78/84 -> 85/85`; support [UID:00023F] `80/86 -> 85/86`; [UID:00023I] `78/84 -> 85/86`.
- Owner/emitter changes: [UID:0002QR] now routes through direct class owner/emitter [UID:00009E][NewUserDialogPane2](../../../../by-class/NewUserDialogPane2.md) instead of umbrella file [UID:0000IK][CreateUserDialogs](../../../../by-file/CreateUserDialogs.md); [UID:0002BC] and [UID:00023F] now route through direct class owner/emitter [UID:00009Q][ObjectList](../../../../by-class/ObjectList.md) instead of direct file [UID:0000M4][ObjectList](../../../../by-file/ObjectList.md). [UID:00023I] stays at file owner/emitter [UID:0000M7][OptionPane](../../../../by-file/OptionPane.md) because the island mixes a likely file-local packet sender and a class receiver helper.
- Evidence summary: live IDA MCP session `a001_goal2_class_batch` reconfirmed `NexusTK.exe.i64`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. For [UID:0002QR]/[UID:0001CR], IDA reconfirmed create-user variant starts/sizes, constructor/internal xrefs, vtable/singleton xref groups, and child boundary bytes. For [UID:0002BC]/[UID:00023F], IDA reconfirmed modeled/raw start status, ObjectList helper xrefs, raw prologue/tail bytes, list virtual-slot calls, row/bounds helper calls, and `0x0053728e-0x00537290` padding. For [UID:00023I], IDA reconfirmed raw/non-function status at both starts, no direct raw-start xrefs, predecessor/successor functions, `0xcc` padding, `0x011b`/`0x63` packet sender bytes, five `this+0x26c..0x270` stores, and five child-control state-update calls.
- IDA database updates: none. Skipped candidates: no `define_func`, rename, comment, prototype, type, vtable, or field edits because raw-start reachability, source-visible helper names, packet helper ownership, and field names remain below the C-agent safe-edit threshold.
- Validation: sequential applied loop `python .\tools\validator.py --mode file --file <file> --apply --lock-timeout 60` for the six changed by-* docs exited `0`; each scan reached `ok: 1`. The validator converted current autogen headers to `CANONICAL_OWNER`/`EMITTER_UIDS`, refreshed validator registry/autogen reports, removed matching rows from `project-level/-auto-completion-stats.md`, and `rg -n "0002QR|0002BC|00023I|0001CR|00023F|00009E" project-level/-auto-completion-stats.md` returned no matches.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

- Supervisor applied and validated the [UID:0001CR], [UID:0002QR], [UID:00023F], [UID:0002BC], and [UID:00023I] replacement rows on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 Refreshed Low-Score Memory Batch 0002QR-00023I supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Agent-C001 Goal 2 Low-Score Memory Batch 0001DW-0001KE

- Changed docs: [UID:0001DW][0x0053ff90-0x00541b2b.NewOptionPane](../../../../by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md), [UID:0001HR][0x00573d20-0x005747df.ServerSelectPane](../../../../by-memory/0x00573d20-0x005747df.ServerSelectPane.md), [UID:0001KE][0x005995b0-0x00599a34.UniAPIInit](../../../../by-memory/0x005995b0-0x00599a34.UniAPIInit.md), validator-owned `project-level/-auto-completion-stats.md`, validator-owned `auto-generated/-ag-memory-coverage.md`, validator registry state, and this notes file.
- Score changes: [UID:0001DW] `78/84 -> 86/86`, combined `81.0 -> 86.0`; [UID:0001HR] `78/84 -> 85/86`, combined `81.0 -> 85.5`; [UID:0001KE] `78/84 -> 85/86`, combined `81.0 -> 85.5`.
- Owner/emitter changes: [UID:0001DW] now routes through direct class owner/emitter [UID:000097][NewOptionPane](../../../../by-class/NewOptionPane.md) instead of direct file [UID:0000M7][OptionPane](../../../../by-file/OptionPane.md). [UID:0001HR] stays file-level [UID:0000NO][ServerSelectPane](../../../../by-file/ServerSelectPane.md) because the range crosses `ServerSelectPane`, `ServerSelectMenuItemList`, raw wrappers, and helper code. [UID:0001KE] stays file-level [UID:0000ML][PlatformApi](../../../../by-file/PlatformApi.md) because the range remains a static-object/generated-boundary audit rather than an exact class-only method page.
- Evidence summary: live IDA MCP session `a001_goal2_class_batch` reconfirmed active `NexusTK.exe.i64`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. For [UID:0001DW], IDA reconfirmed the NewOptionPane modeled method map, constructor/vtable/helper xrefs, OnPaint helper-only callers, OnMouseClick option/packet behavior, component edges, and byte boundaries. For [UID:0001HR], IDA reconfirmed pane/list/helper/destructor modeled starts, raw wrapper byte bodies, singleton lifecycle refs, selected-server helper decompilation, and component relationships. For [UID:0001KE], IDA reconfirmed the real dispatch initializer at `0x0041a280`, `0x005995b0` non-function/no-xref status, fallback-reader refs, vtable reset helper, scalar deleting destructor, static cleanup wrapper, and raw initializer-shaped instruction sites.
- IDA database updates: none. Skipped candidates: no NewOptionPane method/helper/prototype/field renames because option-entry/session/config names and raw helper promotion remain below final-source quality; no ServerSelect raw function definitions or helper/type names because raw wrapper reachability and selected-server entry/session fields are still provisional; no UniAPI function definitions, names, comments, prototypes, or type changes because `0x005995b0`/`0x005997e7` remain raw generated-boundary spans and the static-object declaration shape is unresolved.
- Validation: sequential applied runs exited `0` for all three changed by-memory docs. Commands were `python .\tools\validator.py --mode file --file by-memory\0x0053ff90-0x00541b2b.NewOptionPane.md --apply --lock-timeout 60`, `python .\tools\validator.py --mode file --file by-memory\0x00573d20-0x005747df.ServerSelectPane.md --apply --lock-timeout 60`, and `python .\tools\validator.py --mode file --file by-memory\0x005995b0-0x00599a34.UniAPIInit.md --apply --lock-timeout 60`; each reported `ok: 1`. The first run logged `canonical_owner_update 0001DW ... 0000M7 -> 000097` and `autogen_registry_update 0001DW ... 0000M7 -> 000097`. The three runs removed [UID:0001DW], [UID:0001HR], and [UID:0001KE] from Low_Completion, Low_Confidence, Low_Both, and by-memory stats rows. Follow-up `rg -n "0001DW|0001HR|0001KE" project-level\-auto-completion-stats.md` returned no matches. `auto-generated/-ag-memory-coverage.md` now shows [UID:0001DW] emitting through `000097` to `auto-generated/NexusTK/ui/dialogs/OptionPane.cpp`, [UID:0001HR] through `0000NO` to `auto-generated/NexusTK/login/ServerSelectPane.cpp`, and [UID:0001KE] through `0000ML` to `auto-generated/NexusTK/platform/PlatformApi.cpp`.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

- Supervisor applied and validated the [UID:0001DW], [UID:0001HR], and [UID:0001KE] replacement rows on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 Low-Score Memory Batch 0001DW-0001KE supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Agent-C001 Goal 2 Low-Confidence Memory Batch 0001KQ-0001M3

- Changed docs: [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](../../../../by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md), [UID:0001M1][0x005b2720-0x005b296b.TakeOffInputPane](../../../../by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md), [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](../../../../by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md), validator-owned `project-level/-auto-completion-stats.md`, validator-owned `auto-generated/-ag-memory-coverage.md`, validator registry state, and this notes file.
- Score changes: [UID:0001KQ] `78/84 -> 85/86`, combined `81.0 -> 85.5`; [UID:0001M1] `78/84 -> 86/86`, combined `81.0 -> 86.0`; [UID:0001M3] `78/84 -> 86/87`, combined `81.0 -> 86.5`.
- Owner/emitter changes: [UID:0001KQ] remains file-level [UID:0000NM][SelfSaveInputPane](../../../../by-file/SelfSaveInputPane.md) because no direct caller/source-form proof justifies forcing the factory under the class. [UID:0001M1] now routes through direct class owner/emitter [UID:0000EC][TakeOffInputPane](../../../../by-class/TakeOffInputPane.md) instead of direct file [UID:0000KC][ItemActionInputPanes](../../../../by-file/ItemActionInputPanes.md); the exact shared [UID:0001M2][SendTakeOffPacket](../../../../by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md) child remains file-level because `SelfLookPane` also calls it. [UID:0001M3] now routes through direct class owner/emitter [UID:00004B][EmotionInputPane](../../../../by-class/EmotionInputPane.md) instead of direct file [UID:0000ID][CommandInputPanes](../../../../by-file/CommandInputPanes.md).
- Evidence summary: live IDA MCP session `a001_goal2_class_batch` reconfirmed active read-only `NexusTK.exe.i64`, image base `0x400000`, auto-analysis ready, and Hex-Rays ready. For [UID:0001KQ], IDA reconfirmed `sub_5AA140` size `0x80`, no direct xrefs/callers, allocation/localized prompt/base-constructor behavior, three SelfSave vtable stores, matching raw-constructor stores, and successor prologue at `0x005aa1c0`. For [UID:0001M1], IDA reconfirmed modeled starts/ends, raw constructor non-function status, vtable-only shortcut/command handler refs, opcode `0x2d` shortcut path, `A` all-equipment branch, 28 shared helper callsites split across `SelfLookPane` and `TakeOffInputPane`, equipment key table use, active-dialog gate, and `0xcc` padding. For [UID:0001M3], IDA reconfirmed constructor/handler/helper starts and ends, constructor callers, vtable stores, virtual handler slot, helper-only caller set, letter/menu behavior, and padding before/after the helper.
- IDA database updates: none. Skipped candidates: no function renames, comments, prototypes, type/field edits, or raw-start definitions because helper/source-visible names, event/menu object fields, raw constructor reachability, and final source declaration placement are still not final-source quality. Existing decorated vtable names already provide the safe class evidence.
- Validation: sequential applied runs exited `0` for all three changed by-memory docs. Commands were `python .\tools\validator.py --mode file --file by-memory\0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md --apply --lock-timeout 60`, `python .\tools\validator.py --mode file --file by-memory\0x005b2720-0x005b296b.TakeOffInputPane.md --apply --lock-timeout 60`, and `python .\tools\validator.py --mode file --file by-memory\0x005b29c0-0x005b2f68.EmotionInputPane.md --apply --lock-timeout 60`; each reported `ok: 1` on the filtered recheck. The first applied pass logged [UID:0001KQ] score updates and removed it from Low_Confidence, Low_Both, and by-memory stats; subsequent filtered rechecks showed [UID:0001KQ], [UID:0001M1], and [UID:0001M3] absent from generated stats lists. Follow-up `rg -n "0001KQ|0001M1|0001M3" project-level\-auto-completion-stats.md` returned no matches. `auto-generated/-ag-memory-coverage.md` now shows [UID:0001KQ] emitting through `0000NM` to `auto-generated/NexusTK/ui/dialogs/SelfSaveInputPane.cpp`, [UID:0001M1] through `0000EC` to `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp`, and [UID:0001M3] through `00004B` to `auto-generated/NexusTK/ui/dialogs/CommandInputPanes.cpp`.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

- Supervisor applied and validated the [UID:0001KQ], [UID:0001M1], and [UID:0001M3] replacement rows on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 Low-Confidence Memory Batch 0001KQ-0001M3 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Agent-C001 Goal 2 Low-Score By-Class Batch 00001X-00008L

- Changed docs: [UID:00001X][ChattingPane](../../../../by-class/ChattingPane.md), [UID:00003L][DDError](../../../../by-class/DDError.md), [UID:00003O][DeleteReplyAlert](../../../../by-class/DeleteReplyAlert.md), [UID:00008L][Monitor](../../../../by-class/Monitor.md), `by-class/-coverage-report.md`, validator-owned `project-level/-auto-completion-stats.md`, validator registry state, and this notes file.
- Score changes: [UID:00001X] `80/86 -> 86/88`, combined `83.0 -> 87.0`; [UID:00003L] `80/86 -> 86/88`, combined `83.0 -> 87.0`; [UID:00003O] `80/86 -> 85/88`, combined `83.0 -> 86.5`; [UID:00008L] `80/86 -> 86/88`, combined `83.0 -> 87.0`.
- Owner/emitter changes: none. Existing routes remain [UID:00001X] -> [UID:0000I5][Chatting](../../../../by-file/Chatting.md), [UID:00003L] -> [UID:0000J5][Error](../../../../by-file/Error.md), [UID:00003O] -> [UID:0000HW][BulletinReplyAlerts](../../../../by-file/BulletinReplyAlerts.md), and [UID:00008L] -> [UID:0000LI][Monitor](../../../../by-file/Monitor.md). Follow-up `rg -n "00001X|00003L|00003O|00008L" auto-generated/-ag-class-coverage.md` confirms all four still surface to generated output files with no dead-end.
- Evidence summary: live IDA MCP session `a001_goal2_class_batch` reconfirmed active `NexusTK.exe.i64`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. ChattingPane lookup/xref/decompile/raw-byte checks reconfirmed modeled display-pane method starts, two `SetVisibleRowCount` callers, six local `GetLineCount` callers, `g_pChattingDisplayPane` refs, 783/408 wrap widths, and raw reset-helper no-function/padded-byte status. DDError checks reconfirmed constructor/formatter/destructor/name-helper starts, 14 constructor callers, vtable store/slot refs, formatter DirectDraw-message/fallback behavior, and constructor-to-formatter padding. DeleteReplyAlert checks reconfirmed modeled method starts, four constructor callers, singleton refs, three vtable groups, scalar destructor refs through adjustor thunks, and confirm-handler branch behavior. Monitor checks reconfirmed constructor/lock/unlock/scalar-destructor starts, raw destructor no-function bytes, vtable refs, RingBuffer/Thread caller sets, and WaitForSingleObject/ReleaseMutex-or-semaphore helper behavior.
- IDA database updates: none. Skipped candidates: no function renames, prototypes, comments, type/field edits, or raw function definitions because final field names, helper/source-visible method names, raw helper exposure, formatter/header declaration shape, and alert owner-dialog/list field names remain below the C-agent safe-edit threshold. Existing decorated vtable names already provided the safe class evidence.
- Validation: sequential applied loop `python .\tools\validator.py --mode file --file <file> --apply --lock-timeout 60` for the four class docs plus `by-class/-coverage-report.md` exited `0`. The first scan logged [UID:00001X] `completion_update`/`confidence_update` and low-score stats removal; subsequent scans completed successfully for [UID:00003L], [UID:00003O], [UID:00008L], and the coverage report. Follow-up `rg -n "00001X|00003L|00003O|00008L" project-level/-auto-completion-stats.md` returned no matches.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none required because no by-memory docs, ranges, owners, emitters, reconstructable flags, or scores changed.

## 2026-06-14 Agent-C001 Goal 2 Low-Score By-Class Batch 00008M-00000T

- Changed docs: [UID:00008M][MonitorCondition](../../../../by-class/MonitorCondition.md), [UID:0000AB][PatchPane__PatchFileData](../../../../by-class/PatchPane__PatchFileData.md), [UID:0000AL][PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6](../../../../by-class/PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6.md), [UID:00000T][BackStoryDialogPane](../../../../by-class/BackStoryDialogPane.md), [UID:0003OC][0x00548500-0x00548555.PatchFileDataScalarDeletingDestructor](../../../../by-memory/0x00548500-0x00548555.PatchFileDataScalarDeletingDestructor.md), [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](../../../../by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md), [UID:0000VN][-ignored](../../../../by-memory/-ignored.md), [UID:0000MH][PatchPane](../../../../by-file/PatchPane.md), `by-class/-coverage-report.md`, validator-owned `project-level/-auto-completion-stats.md`, validator-owned `auto-generated/-ag-class-coverage.md`, validator-owned `auto-generated/-ag-memory-coverage.md`, validator registry state, and this notes file.
- Score changes: [UID:00008M] `80/86 -> 86/88`, combined `83.0 -> 87.0`; [UID:0000AB] `80/86 -> 85/88`, combined `83.0 -> 86.5`; [UID:0000AL] `80/86 -> 86/88`, combined `83.0 -> 87.0`; [UID:00000T] `82/84 -> 86/86`, combined `83.0 -> 86.0`; new exact child [UID:0003OC] `0/0 -> 85/88`. Support [UID:0001EQ] stayed `82/88`, [UID:0000MH] stayed `88/85`, and [UID:0000VN] stayed ignored.
- Owner/emitter changes: existing assigned class targets kept their current routes: [UID:00008M] -> [UID:0000LI][Monitor](../../../../by-file/Monitor.md), [UID:0000AB] -> [UID:0000MH][PatchPane](../../../../by-file/PatchPane.md), [UID:0000AL] -> [UID:0000JO][FunctionObjects](../../../../by-file/FunctionObjects.md), and [UID:00000T] -> [UID:0000HP][BackStoryDialogPane](../../../../by-file/BackStoryDialogPane.md). New [UID:0003OC] routes through direct class owner/emitter [UID:0000AB][PatchPane__PatchFileData](../../../../by-class/PatchPane__PatchFileData.md), surfacing to `auto-generated/NexusTK/patch/PatchPane.cpp` with no dead end. Validator metadata migration added/retained current `CANONICAL_OWNER`/`EMITTER_UIDS` headers for touched support pages without changing their logical routes.
- Evidence summary: live IDA MCP session `a001_goal2_class_batch` reconfirmed active `NexusTK.exe.i64`, image base `0x400000`, auto-analysis ready, and Hex-Rays ready. MonitorCondition checks reconfirmed constructor/wait/signal/scalar-destructor sizes, raw non-deleting destructor bytes, vtable refs, and RingBuffer construction/use xrefs. PatchFileData checks created exact child [UID:0003OC], correcting `0x00548500-0x00548554` last-byte wording to half-open `0x00548500-0x00548555`, with vtable slot `0x00621dc4`, `+0x208` backing-store cleanup, optional delete, and boundary bytes. Music callback checks reconfirmed invoke/destructor/adjustor/neighbor sizes, vtable refs, construction-site stores, and bound `MusicControlDialog` target. BackStoryDialogPane checks reconfirmed constructor/handler/clear-helper/thunk/destructor sizes, singleton/vtable xrefs, byte boundaries, and no direct constructor xrefs.
- Structural cleanup: added exact memory child [UID:0003OC] for the nested `PatchFileData` scalar deleting destructor, corrected the PatchPane aggregate/file summaries to use the project half-open endpoint, and added ignored padding entries for `0x005484f0-0x00548500` and `0x00548555-0x00548560`.
- IDA database updates: none. Skipped candidates: no function renames, comments, prototypes, field/type edits, or raw function definitions because public/private Monitor method names, PatchFileData producer/allocation and field names, FunctionObjects template/header spelling, BackStoryDialogPane live construction path, and final source declarations are not final-source quality. Existing decorated vtable names already provide the safe class evidence.
- Validation: sequential applied loop `python .\tools\validator.py --mode file --file <file> --apply --lock-timeout 60` for [UID:0003OC], [UID:00008M], [UID:0000AB], [UID:0001EQ], [UID:0000MH], [UID:0000AL], [UID:00000T], and `by-class/-coverage-report.md` exited `0`; each scan reached `ok: 1`. The first run logged [UID:0003OC] score updates, `canonical_owner_update 0003OC ... NONE -> 0000AB`, and `autogen_registry_update 0003OC ... -> 0000AB`. Follow-up `python .\tools\validator.py --mode file --file by-memory\-ignored.md --apply --lock-timeout 60` also exited `0` with `ok: 1` and reference-index additions for [UID:0000AB] and [UID:0003OC]. Follow-up `rg -n "00008M|0000AB|0000AL|00000T" project-level\-auto-completion-stats.md` returned no matches; `auto-generated/-ag-class-coverage.md` and `auto-generated/-ag-memory-coverage.md` show all target routes surfacing to generated output.

Supervisor-applied `by-memory/-coverage-report.md` replacement/insert rows:

- Supervisor applied and validated the [UID:0001EQ], ignored padding `0x005484f0-0x00548500`, [UID:0003OC], and ignored padding `0x00548555-0x00548560` rows on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 Low-Score By-Class Batch 00008M-00000T supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Agent-C001 Goal 2 Low-Score By-Class Batch C001-goal2-low-score-byclass-20260614-4

- Changed docs: [UID:00005M][FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____](../../../../by-class/FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____.md), [UID:00002Q][ClientItemMenuItemList](../../../../by-class/ClientItemMenuItemList.md), [UID:00008O][MonsterImageLibTable_5289D0](../../../../by-class/MonsterImageLibTable_5289D0.md), [UID:00008P][MonsterImageLibTable_528BE0](../../../../by-class/MonsterImageLibTable_528BE0.md), support [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](../../../../by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md), support [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](../../../../by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md), `by-class/-coverage-report.md`, validator-owned `project-level/-auto-completion-stats.md`, validator-owned `auto-generated/-ag-class-coverage.md`, validator-owned `auto-generated/-ag-memory-coverage.md`, validator registry state, and this notes file.
- Score changes: [UID:00005M] `80/86 -> 86/88`, combined `83.0 -> 87.0`; [UID:00002Q] `82/84 -> 86/86`, combined `83.0 -> 86.0`; [UID:00008O] `82/84 -> 86/86`, combined `83.0 -> 86.0`; [UID:00008P] `82/84 -> 86/86`, combined `83.0 -> 86.0`; support [UID:0001BQ] `82/84 -> 86/86`; support [UID:0001CM] `82/88 -> 85/88`.
- Owner/emitter changes: none. Existing routes remain [UID:00005M] -> [UID:0000JO][FunctionObjects](../../../../by-file/FunctionObjects.md), [UID:00002Q] -> [UID:0000KF][ItemMenuDialogs](../../../../by-file/ItemMenuDialogs.md), and [UID:00008O]/[UID:00008P] -> [UID:0000LK][MonsterImageLibTables](../../../../by-file/MonsterImageLibTables.md). Support routes remain [UID:0001BQ] -> [UID:0000KF] and [UID:0001CM] -> [UID:0000LK]. Follow-up `rg -n "00005M|00002Q|00008O|00008P|0001BQ|0001CM" auto-generated/-ag-class-coverage.md auto-generated/-ag-memory-coverage.md` confirms all target/support routes still surface to generated output with no dead end.
- Evidence summary: live IDA MCP session `a001_goal2_class_batch` reconfirmed active `NexusTK.exe.i64`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. [UID:00005M] checks reconfirmed `sub_52A460` size `0x3e`, no direct callers, vtable/data ref `0x0061fcd4 -> 0x0052a460`, base cleanup/delete callees, scalar-deleting flag behavior, and padding before the neighboring callback wrapper. [UID:00002Q]/[UID:0001BQ] checks reconfirmed constructor/activation/draw/destructor-support sizes, raw helper non-function/no-xref status, constructor callers from `ClientItemMenuDialog`, context fields at `+0x14c/+0x150/+0x154/+0x158`, vtable stores/slots, shared client/spell list destructor refs, and padding at both ends. [UID:00008O]/[UID:00008P]/[UID:0001CM] checks reconfirmed all thirteen monster/riding helper starts and sizes, successor boundary at `0x00528d60`, parser/allocation xrefs, constructor/destructor callback wiring, fallback refs to [UID:00027U][0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord](../../../../by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md), and internal `0xcc` alignment bytes.
- IDA database updates: none. Skipped candidates: no function renames, comments, prototypes, raw-function definitions, type/field edits, or vtable edits because template/header spelling, raw helper reachability, row/packet field names, neutral monster/riding helper type names, and final source declarations are not source-quality enough for the C-agent safe-edit threshold. Existing IDA function starts and decorated vtable evidence were sufficient for documentation only.
- Validation: sequential applied loop `python .\tools\validator.py --mode file --file <file> --apply --lock-timeout 60` for the four assigned class docs, two support memory docs, and `by-class/-coverage-report.md` exited `0`. The first scan logged [UID:00005M] score updates and low-score stats removal; the subsequent scans completed successfully for [UID:00002Q], [UID:00008O], [UID:00008P], [UID:0001BQ], [UID:0001CM], and the class coverage report. Follow-up stale-gate scan returned no matches, and `rg -n "00005M|00002Q|00008O|00008P|0001BQ|0001CM" project-level\-auto-completion-stats.md` returned no matches.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

- Supervisor applied and validated the [UID:0001BQ] and [UID:0001CM] replacement rows on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 Low-Score By-Class Batch C001-goal2-low-score-byclass-20260614-4 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Agent-C001 Goal 2 Score By-File Batch C001-goal2-score-byfile-20260614-1

- Changed docs: [UID:0000HH][ArgumentedItemInputDialogs](../../../../by-file/ArgumentedItemInputDialogs.md), [UID:0000KD][ItemCatalog](../../../../by-file/ItemCatalog.md), [UID:0000MV][ProtocolSend](../../../../by-file/ProtocolSend.md), [UID:0000JA][FieldMapPane](../../../../by-file/FieldMapPane.md), `by-file/-coverage-report.md`, validator-owned `project-level/-auto-completion-stats.md`, validator-owned `auto-generated/-ag-file-coverage.md`, validator registry state, and this notes file.
- Score changes: [UID:0000HH] `82/88 -> 86/89`, combined `85.0 -> 87.5`; [UID:0000KD] `84/86 -> 86/88`, combined `85.0 -> 87.0`; [UID:0000MV] `84/86 -> 87/88`, combined `85.0 -> 87.5`; [UID:0000JA] `86/84 -> 88/88`, combined `85.0 -> 88.0`.
- Owner/emitter changes: none. [UID:0000HH] remains `FILE` at `NexusTK/ui/dialogs/`; [UID:0000KD] remains `FILE` at `NexusTK/cashshop/`; [UID:0000JA] remains `FILE` at `NexusTK/map/`; [UID:0000MV] remains `CANONICAL_OWNER:NONE` and `PROPOSED_RECONSTRUCTION_PATH:"NONE"` as a reviewed non-standalone placeholder. Follow-up `rg -n "0000HH|0000KD|0000MV|0000JA" auto-generated/-ag-file-coverage.md` confirms the three file roots still emit and ProtocolSend remains not_reconstructable/NONE with no generated root.
- Evidence summary: live IDA MCP session `a001_goal2_class_batch` reported `NexusTK.exe.i64`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. ArgumentedItemInputDialogs checks reconfirmed helper/dialog sizes, internal purchase-flow edges, constructor/packet xrefs, opcode `0x39`/14-byte packet behavior, and verified opcode/count conversions. ItemCatalog checks reconfirmed lookup/parser/helper sizes, fitting-room-only caller refs, parser-to-category-loader edge, and decompiled sentinel/vector behavior. ProtocolSend checks reconfirmed no `ProtocolSend` string/name signal, request-sender function inventory, raw `0x00574d00` no-function/no-ref status, generic `0x00596960` queue post, and Socket final transport ownership. FieldMapPane checks reconfirmed method/helper sizes, request/path helper caller sets, raw `0x004b1130` no-function/no-ref status, opcode `0x3f`/7-byte request behavior, and verified numeric conversions.
- IDA database updates: none. Skipped candidates: no IDA function renames, comments, prototypes, raw function definitions, file/source names, or type/field edits because final source-facing helper names, class signatures, raw helper reachability, FieldMap field names, and ProtocolSend promotion remain below the C-agent safe-edit threshold.
- Validation: sequential applied loop `python .\tools\validator.py --mode file --file <file> --apply --lock-timeout 60` for the four target by-file docs plus `by-file/-coverage-report.md` exited `0`; each scan reached `ok: 1`. The first scan logged [UID:0000HH] `completion_update 86`, `confidence_update 89`, and low-score stats removal; follow-up `rg -n "0000HH|0000KD|0000MV|0000JA" project-level\-auto-completion-stats.md` returned no matches.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none required because no by-memory documentation, memory ranges, memory scores, memory owners, or memory emitters changed in this batch.

## 2026-06-14 Agent-C001 Goal 2 Score By-File Batch C001-goal2-score-byfile-20260614-2

- Changed docs: [UID:0000IF][ConnStatusPane](../../../../by-file/ConnStatusPane.md), [UID:0000IJ][CreateUserDialogPane](../../../../by-file/CreateUserDialogPane.md), [UID:0000J2][EPFImageControlPane](../../../../by-file/EPFImageControlPane.md), [UID:0000JY][HumanImageLib](../../../../by-file/HumanImageLib.md), `by-file/-coverage-report.md`, validator-owned `project-level/-auto-completion-stats.md`, validator-owned `auto-generated/-ag-file-coverage.md`, validator registry state, and this notes file.
- Score changes: [UID:0000IF] `85/85 -> 87/88`, combined `85.0 -> 87.5`; [UID:0000IJ] `85/85 -> 87/87`, combined `85.0 -> 87.0`; [UID:0000J2] `85/85 -> 87/88`, combined `85.0 -> 87.5`; [UID:0000JY] `85/85 -> 87/88`, combined `85.0 -> 87.5`.
- Owner/emitter changes: none. Routes remain [UID:0000IF] -> `auto-generated/NexusTK/network/ConnStatusPane.cpp`, [UID:0000IJ] -> `auto-generated/NexusTK/login/CreateUserDialogPane.cpp`, [UID:0000J2] -> `auto-generated/NexusTK/ui/controls/EPFImageControlPane.cpp`, and [UID:0000JY] -> `auto-generated/NexusTK/render/HumanImageLib.cpp`.
- Evidence summary: live IDA MCP session `a001_goal2_class_batch` reported active `NexusTK.exe.i64`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. ConnStatusPane checks reconfirmed exact local sizes, constructor/singleton/vtable xrefs, component interface/internal split, message-to-frame-update edge, RTTI strings, and latency thresholds verified with `tools/int_convert.py`. CreateUserDialogPane checks reconfirmed method sizes, constructor callers, submit/packet/reply internal edges, vtable/singleton xrefs, create-user RTTI strings, and old appearance-control coupling. EPFImageControlPane checks reconfirmed compact core and non-contiguous destructor support sizes, vtable xrefs, render slot, component split, RTTI string, and exact child UIDs. HumanImageLib checks reconfirmed constructor/destructor/clear/scalar-wrapper sizes, scalar-to-ordinary destructor edge, vtable/singleton xrefs, RTTI strings, old-human table strings, and shared `ProtectedArray<...Info>` vtable touches.
- IDA database updates: none. Skipped candidates: no function renames, comments, prototypes, raw function definitions, type/field edits, vtable edits, or IDA comments because final source placement for ConnStatusPane, CreateUser appearance-control split, EPF callback/member names, and HumanImageLib constructor fields/table declarations remain below the C-agent safe-edit threshold.
- Validation: sequential applied loop `python .\tools\validator.py --mode file --file <file> --apply --lock-timeout 60` for the four target by-file docs plus `by-file/-coverage-report.md` exited `0`; each scan reached `ok: 1`. The first scan logged [UID:0000IF] `completion_update 87`, `confidence_update 88`, and low-score stats removal. Follow-up `rg -n "0000IF|0000IJ|0000J2|0000JY" project-level\-auto-completion-stats.md` returned no matches, while `auto-generated/-ag-file-coverage.md` still shows all four as emitting `FILE` roots.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none required because no by-memory documentation, memory ranges, memory scores, memory owners, or memory emitters changed in this batch.

## 2026-06-14 Agent-C001 Goal 2 Score By-File Batch C001-goal2-score-byfile-20260614-3

- Changed docs: [UID:0000KB][InventoryScrollPane](../../../../by-file/InventoryScrollPane.md), [UID:0000KR][LinkedList](../../../../by-file/LinkedList.md), [UID:0000LB][MessageShowPane](../../../../by-file/MessageShowPane.md), [UID:0000LK][MonsterImageLibTables](../../../../by-file/MonsterImageLibTables.md), `by-file/-coverage-report.md`, validator-owned `project-level/-auto-completion-stats.md`, validator-owned autogen reports as no-op refreshes, validator registry state, and this notes file.
- Score changes: [UID:0000KB] `85/85 -> 86/88`, combined `85.0 -> 87.0`; [UID:0000KR] `85/85 -> 87/88`, combined `85.0 -> 87.5`; [UID:0000LB] `85/85 -> 86/87`, combined `85.0 -> 86.5`; [UID:0000LK] `85/85 -> 87/88`, combined `85.0 -> 87.5`.
- Owner/emitter changes: none. All four remain by-file generated roots: [UID:0000KB] -> `auto-generated/NexusTK/ui/inventory/InventoryScrollPane.cpp`, [UID:0000KR] -> `auto-generated/NexusTK/util/LinkedList.cpp`, [UID:0000LB] -> `auto-generated/NexusTK/ui/dialogs/MessageShowPane.cpp`, and [UID:0000LK] -> `auto-generated/NexusTK/render/MonsterImageLibTables.cpp`.
- Evidence summary: live IDA MCP session `a001_goal2_class_batch` reconfirmed active `NexusTK.exe.i64`. InventoryScrollPane checks reconfirmed modeled scrollbar starts/sizes, raw non-function helper starts, one `NewInventoryPane` constructor caller, three vtable-base stores, and the `0x110`/272-byte object size verified with `tools/int_convert.py`. LinkedList checks reconfirmed helper starts/sizes, xref spread for payload-node creation, raw node allocation, and list cleanup, plus separation from DATIndexVector-specific `0x00457310`. MessageShowPane checks reconfirmed constructor/destructor/update/thunk/scalar-destructor/packet-handler boundaries, the single `SetWrappedText` packet-handler caller, scalar-destructor thunk/vtable refs, and eight `g_pMessageShowPane` lifecycle/packet/UI cleanup refs. MonsterImageLibTables checks reconfirmed all shared helper starts, successor boundary, parser/allocation xrefs, fallback-frame refs, concrete monster/riding default-table refs, and `21`/`0x15` default-group conversions verified with `tools/int_convert.py`.
- IDA database updates: none. Skipped candidates: no function/data renames, comments, prototypes, type/field edits, or raw function definitions because final source names, helper/type declarations, field names, raw helper provenance, and standalone-versus-private source placement are still below the C-agent safe-edit threshold.
- Validation: sequential applied loop `python .\tools\validator.py --mode file --file <file> --apply --lock-timeout 60` for the four target by-file docs plus `by-file/-coverage-report.md` exited `0`; each scan reached `ok: 1`. The first scan logged [UID:0000KB] `completion_update 86`, `confidence_update 88`, and low-score stats removal. Follow-up `rg -n "0000KB|0000KR|0000LB|0000LK" project-level\-auto-completion-stats.md auto-generated\-ag-file-coverage.md by-file\-coverage-report.md` returned no project-level stats rows, still showed all four generated file roots, and showed the updated by-file coverage rows.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none required because no by-memory documentation, memory ranges, memory scores, memory owners, or memory emitters changed in this batch.

## 2026-06-14 Agent-C001 Goal 2 Score By-File Batch C001-goal2-score-byfile-20260614-4

- Changed docs: [UID:0000MQ][PrimeNumberGenerator](../../../../by-file/PrimeNumberGenerator.md), [UID:0000MU][ProtectedArray](../../../../by-file/ProtectedArray.md), [UID:0000N6][RidingImageLib](../../../../by-file/RidingImageLib.md), [UID:0000NJ][ScrollSpellInventoryPane](../../../../by-file/ScrollSpellInventoryPane.md), `by-file/-coverage-report.md`, validator-owned `project-level/-auto-completion-stats.md`, validator-owned `auto-generated/-ag-file-coverage.md`, validator registry state, and this notes file.
- Score changes: [UID:0000MQ] `85/85 -> 86/87`, combined `85.0 -> 86.5`; [UID:0000MU] `85/85 -> 87/89`, combined `85.0 -> 88.0`; [UID:0000N6] `85/85 -> 87/88`, combined `85.0 -> 87.5`; [UID:0000NJ] `85/85 -> 86/88`, combined `85.0 -> 87.0`.
- Owner/emitter changes: none. All four remain by-file generated roots: [UID:0000MQ] -> `auto-generated/NexusTK/util/PrimeNumberGenerator.cpp`, [UID:0000MU] -> `auto-generated/NexusTK/util/ProtectedArray.cpp`, [UID:0000N6] -> `auto-generated/NexusTK/render/RidingImageLib.cpp`, and [UID:0000NJ] -> `auto-generated/NexusTK/ui/inventory/ScrollSpellInventoryPane.cpp`.
- Evidence summary: live IDA MCP session `a001_goal2_class_batch` reconfirmed active read-only `NexusTK.exe`, auto-analysis idle. PrimeNumberGenerator checks reconfirmed raw accessor non-function status, constructor/destructor/Deque helper sizes, zero direct refs to constructor/accessor, DequeClear refs from constructor/destructor/raw cleanup fragments, one-slot vtable refs, and callee sets. ProtectedArray checks reconfirmed raw ordinary-destructor starts inside broad image-library functions, modeled accessor/destructor/resize sizes, broad accessor fan-in, vtable-data refs, no-callee accessor bodies, cleanup/resize callees, and the `0x0c`/12-byte unresolved accessor stride. RidingImageLib checks reconfirmed parser/constructor/destructor/scalar-destructor/helper boundaries, raw draw helper non-function/no-xrefs cap, constructor-only parser reachability, startup constructor callsite, singleton/vtable/global-table xref counts, and shared monster-table helper calls. ScrollSpellInventoryPane checks reconfirmed modeled method run, raw reset-helper non-function/no-xrefs cap, sole `NewSpellInventoryPane` constructor callsite, vtable-base refs, `0x110`/272-byte allocation, returned scrollbar storage at `this + 0x100`, and activation call.
- IDA database updates: none. Skipped candidates: no function/data renames, comments, prototypes, raw function definitions, type/field edits, or vtable edits because active Prime construction, exact ProtectedArray header/member spellings, RidingImageLib field/helper names, and ScrollSpell standalone-versus-folded source placement remain below the C-agent safe-edit threshold. Existing decorated vtable names and current IDA function boundaries were sufficient for documentation.
- Validation: sequential applied loop `python .\tools\validator.py --mode file --file <file> --apply` for the four target by-file docs plus `by-file/-coverage-report.md` exited `0`; each run reached `ok: 1`. The first scan logged [UID:0000MQ] score updates and low-score stats removal; later scans completed successfully for [UID:0000MU], [UID:0000N6], [UID:0000NJ], and the coverage report. Follow-up `rg -n "0000MQ|0000MU|0000N6|0000NJ" project-level\-auto-completion-stats.md auto-generated\-ag-file-coverage.md by-file\-coverage-report.md` returned no project-level stats rows, still showed all four generated file roots, and showed the updated by-file coverage rows.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none required because no by-memory documentation, memory ranges, memory scores, memory owners, or memory emitters changed in this batch.

## 2026-06-14 Agent-C001 Goal 2 Score By-File Batch C001-goal2-score-byfile-20260614-5

- Changed docs: [UID:0000OJ][TextBoxPane](../../../../by-file/TextBoxPane.md), [UID:0000OK][TextButtonControlPane](../../../../by-file/TextButtonControlPane.md), [UID:0000OQ][TextPad](../../../../by-file/TextPad.md), [UID:0000OV][TotemFrame](../../../../by-file/TotemFrame.md), `by-file/-coverage-report.md`, validator-owned `project-level/-auto-completion-stats.md`, validator-owned `auto-generated/-ag-file-coverage.md`, validator registry state, and this notes file.
- Score changes: [UID:0000OJ] `85/85 -> 86/88`, combined `85.0 -> 87.0`; [UID:0000OK] `85/85 -> 86/87`, combined `85.0 -> 86.5`; [UID:0000OQ] `85/85 -> 86/87`, combined `85.0 -> 86.5`; [UID:0000OV] `85/85 -> 87/88`, combined `85.0 -> 87.5`.
- Owner/emitter changes: none. All four remain by-file generated roots: [UID:0000OJ] -> `auto-generated/NexusTK/ui/controls/TextBoxPane.cpp`, [UID:0000OK] -> `auto-generated/NexusTK/ui/controls/TextButtonControlPane.cpp`, [UID:0000OQ] -> `auto-generated/NexusTK/ui/dialogs/TextPad.cpp`, and [UID:0000OV] -> `auto-generated/NexusTK/ui/panels/TotemFrame.cpp`.
- Evidence summary: live IDA MCP session `a001_goal2_class_batch` reconfirmed active read-only `NexusTK.exe`, auto-analysis idle. TextBoxPane checks reconfirmed exact constructor/override sizes, eight constructor callsites, constructor calls to both override helpers, vtable-store refs, and the `0x005954b3` boundary; `0x123`/291 was verified with `tools/int_convert.py`. TextButtonControlPane checks reconfirmed method sizes, constructor/setup fan-in, exact adjustor/scalar destructor and vtable-cell refs, stale `0x004964e0` non-function/no-xref status, and 130-call shared `DrawTextInRect` fanout. TextPad checks reconfirmed constructor/handler/helper sizes, no direct constructor refs, the single private command-helper caller, no inbound refs to standalone helpers, command-string bytes for `Open `, `Save `, `SetFont `, and `SetColor `, vtable-slot refs, and file/text-formatting callee sets. TotemFrame checks reconfirmed exact function boundaries, two constructor callers, `g_pTotemFrame` and `g_pOldUserStatusPane` xref counts, `TOTFRAME.EPD` one-xref ownership, shared `NPAL7.PAL` fanout, successor boundary, and paint callee path through `OldUserStatusPane::GetSpiritId`; `0xde`/222, `0x6b`/107, `0xc0`/192, and `0x120`/288 were verified with `tools/int_convert.py`.
- IDA database updates: none. Skipped candidates: no function/data renames, comments, prototypes, raw function definitions, type/field edits, vtable edits, or resource-string renames because TextBox member names/source fold, TextButton field names and shared text-render ownership, TextPad activation/standalone-helper reachability, and TotemFrame final old-status/totem source grouping remain below the C-agent safe-edit threshold. Existing IDA names and current function/data boundaries were sufficient for documentation only.
- Validation: sequential applied loop `python .\tools\validator.py --mode file --file <file> --apply` for the four target by-file docs plus `by-file/-coverage-report.md` exited `0`; each run reached `ok: 1`. The first scan logged [UID:0000OJ] score updates and low-score stats removal; later scans completed successfully for [UID:0000OK], [UID:0000OQ], [UID:0000OV], and the coverage report. Follow-up `rg -n "0000OJ|0000OK|0000OQ|0000OV" project-level\-auto-completion-stats.md auto-generated\-ag-file-coverage.md by-file\-coverage-report.md` returned no project-level stats rows, still showed all four generated file roots, and showed the updated by-file coverage rows.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none required because no by-memory documentation, memory ranges, memory scores, memory owners, or memory emitters changed in this batch.
## 2026-06-14 Agent-C001 Goal 2 Score By-File Batch C001-goal2-score-byfile-20260614-6

- Changed by-file docs: `NewHistoryDialogPane.md` `86/84 -> 87/87`, `AlphaMaskSurface.md` `82/89 -> 84/90`, `AttachmentAnchorResolver.md` `85/86 -> 86/88`, `BackStoryDialogPane.md` `85/86 -> 86/87`.
- Changed shared by-file report rows for `0000LQ`, `0000HF`, `0000HL`, and `0000HP` to match the new completion percentages and evidence summaries.
- Owner/emitter/path changes: none. Existing generated roots remain `NexusTK/login/NewHistoryDialogPane.cpp`, `NexusTK/render/AlphaMaskSurface.cpp`, `NexusTK/map/AttachmentAnchorResolver.cpp`, and `NexusTK/login/BackStoryDialogPane.cpp`.
- IDA DB changes: none. C001 used live IDA MCP session `a001_goal2_class_batch` for function sizes, xrefs, and callees, but skipped DB renames/prototypes/comments/types because final helper names, field names, source split, and constructor reachability are not extreme-confidence source-quality.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none required because no by-memory documentation, memory ranges, memory scores, memory owners, or memory emitters changed in this batch.
## 2026-06-14 Agent-C001 Goal 2 Score File/Memory Batch C001-goal2-score-file-memory-20260614-1

- Changed docs: `by-file/BoardDialogs.md` `85/86 -> 86/87`, `by-memory/0x006125a8-0x00612f3c.ApplicationStartupReadOnlyData.md` `77/88 -> 82/90`, `by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md` `72/88 -> 73/89`, and `by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md` `72/89 -> 74/90`.
- Changed non-memory coverage row: `by-file/-coverage-report.md` row for [UID:0000HT] updated to 86% with C001 IDA refresh summary.
- Owner/emitter/path changes: none. BoardDialogs remains `NexusTK/ui/dialogs/BoardDialogs.cpp`; ApplicationStartupReadOnlyData remains routed through [UID:0000HG] `Application`; the `.text` and `.rdata` section containers remain `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitters.
- IDA DB changes: none. Live IDA MCP session `a001_goal2_class_batch` supplied function boundary, xref, entity inventory, and component evidence, but no IDA names/prototypes/comments/types were safe enough for C-agent mutation.

Supervisor applied the three `by-memory/-coverage-report.md` replacement rows for [UID:0001Z5], [UID:0001Z7], and [UID:00024T] on 2026-06-14, then validated with `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1` (`ok: 1`). No pending supervisor-owned coverage-report rows remain for this batch.

## 2026-06-14 Agent-C001 Goal 2 Score File/Memory Follow-up C001-goal2-score-file-memory-20260614-1

- Changed docs: `by-memory/0x006125a8-0x00612f3c.ApplicationStartupReadOnlyData.md`, new `by-memory/0x006125e4-0x0061260c.ApplicationVtableData.md`, new `by-memory/0x0061262c-0x00612640.FunctionObject0VtableData.md`, new `by-memory/0x00612e40-0x00612e54.PlainMemberFunctionObject0ApplicationVtableData.md`, `by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md`, `by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md`, validator-owned `auto-generated/-ag-memory-coverage.md`, validator registry state, and this notes file.
- Score changes: [UID:00024T] `82/90 -> 85/91`; new [UID:0003OD] `0/0 -> 86/91`; new [UID:0003OE] `0/0 -> 88/92`; new [UID:0003OF] `0/0 -> 88/92`; [UID:0001Z5] `73/89 -> 74/89`; [UID:0001Z7] `74/90 -> 75/90`.
- Owner/emitter changes: [UID:00024T] remains [UID:0000HG] `Application`; [UID:0003OD] routes through [UID:0000HG] `Application`; [UID:0003OE] and [UID:0003OF] route through [UID:0000JO] `FunctionObjects`; section containers [UID:0001Z5]/[UID:0001Z7] remain `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitters.
- Evidence summary: live IDA MCP session `a001_goal2_class_batch` reconfirmed active `NexusTK.exe.i64`, exact named heads `0x006125e4`, `0x00612604`, `0x0061262c`, and `0x00612e40`, vtable-head xrefs to Application constructor/destructor/scalar destructor, FunctionObject0 destructor variants, and `Application::RequestExit`, and byte/int slot values. `tools/int_convert.py` verified recorded slot target conversions. C001 also documented why `.text` and `.rdata` section containers cannot honestly clear `85/85` yet: current coverage rows still include many 78-84 child audits and broad mixed/third-party/runtime children.
- IDA DB changes: none. Skipped candidates: no IDA renames/prototypes/comments/types were applied; the vtable/string evidence was sufficient for documentation, but final source-level declarations and mixed transition ownership remain below C-agent DB mutation threshold.
- Validation: sequential `python .\tools\validator.py --mode file --file <file> --apply --lock-timeout 60` for the three new child pages, [UID:00024T], [UID:0001Z5], and [UID:0001Z7] exited `0`; visible validator summaries reached `ok: 1` and updated autogen memory coverage for [UID:0003OD]/[UID:0003OE]/[UID:0003OF].

## Supervisor-Applied `by-memory/-coverage-report.md` Updates

- Supervisor applied and validated the [UID:0001Z5], [UID:0001Z7], [UID:00024T], [UID:0003OD], [UID:0003OE], and [UID:0003OF] `by-memory/-coverage-report.md` row changes on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No C001 Goal 2 Score File/Memory Follow-up supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

Applied exact row changes:

Replace the current [UID:0001Z5] row with:

```text
- [UID:0001Z5][0x00401000-0x0060d000.MasterCodeTextSection](by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md) 0x00401000-0x0060d000 | section-container | MasterCodeTextSection : ignored : 74% : strong : IDA `.text` executable segment container, not a standalone source object; current report has 1781 immediate children, 817 nested children, no immediate/nested unknown rows, current endpoint/name inventory, and a C001 follow-up explaining why the section cannot honestly clear 85/85 while many child audits remain at 80-84 completion.
```

## 2026-06-14 Agent-C001 Goal 2 RData Child Score Batch C001-goal2-rdata-child-score-20260614-1

- Changed docs: [UID:00025J][0x0061c360-0x0061c5a0.IMEPaneReadOnlyData](../../../../by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md), [UID:00025L][0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData](../../../../by-memory/0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData.md), [UID:00025Q][0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData](../../../../by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md), [UID:000272][0x00631570-0x00632560.BrowserComGuidReadOnlyData](../../../../by-memory/0x00631570-0x00632560.BrowserComGuidReadOnlyData.md), new [UID:0003OG][0x00631570-0x00631580.DirectDrawGuidConstant](../../../../by-memory/0x00631570-0x00631580.DirectDrawGuidConstant.md), new [UID:0003OH][0x00631580-0x00631660.BrowserComGuidConstants](../../../../by-memory/0x00631580-0x00631660.BrowserComGuidConstants.md), new [UID:0003OI][0x00631660-0x00631850.LibJpeg6bMessagePointerTable](../../../../by-memory/0x00631660-0x00631850.LibJpeg6bMessagePointerTable.md), new [UID:0003OJ][0x00631850-0x00632560.Zlib114ReadOnlyConstantsAndStrings](../../../../by-memory/0x00631850-0x00632560.Zlib114ReadOnlyConstantsAndStrings.md), validator-owned `auto-generated/-ag-memory-coverage.md`, validator registry state, and this notes file.
- Score changes: [UID:00025J] `86/91 -> 87/92`; [UID:00025L] `86/91 -> 87/92`; [UID:00025Q] `85/91 -> 86/92`; [UID:000272] `86/90 -> 88/92`; new [UID:0003OG] `0/0 -> 88/91`; new [UID:0003OH] `0/0 -> 89/92`; new [UID:0003OI] `0/0 -> 88/91`; new [UID:0003OJ] `0/0 -> 86/90`.
- Owner/emitter decisions: [UID:00025J] remains reconstructable through [UID:0000K5][IMEPanes](../../../../by-file/IMEPanes.md). [UID:00025L] and [UID:00025Q] remain `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitters as non-emitting mixed maps. [UID:000272] was corrected from Browser-owned reconstructable data to `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitters because the range is DirectDraw SDK + Browser COM/MSHTML + libjpeg + zlib mixed data. New [UID:0003OG] is non-reconstructable/ignored SDK DirectDraw GUID data. New [UID:0003OH] routes through [UID:0000HV][Browser](../../../../by-file/Browser.md). New [UID:0003OI] routes through [UID:0000KN][LibJPEG](../../../../by-file/LibJPEG.md). New [UID:0003OJ] routes through [UID:0000PC][Zlib](../../../../by-file/Zlib.md).
- Evidence summary: live IDA MCP session `a001_goal2_class_batch` reported active read-only `NexusTK.exe.i64`, image base `0x00400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. IME refresh reconfirmed 15 named heads, four vtable-family xref sets, UTF-16 `IME`/`ENG` bytes, and the `InputMan` successor. Inventory refresh reconfirmed 18 named heads, the existing exact child boundaries, resource xrefs, and the `KeySpeedMgr` successor. MainMenu refresh reconfirmed the 119-label inventory, boundary bytes, existing exact child anchors, representative resource xrefs, and the `MapName/MiniMap` successor; no new split was safe because remaining subfamilies still need exact child audits. Browser mixed-range correction proved `0x00631570` is `IID_IDirectDraw`, `0x00631580-0x00631660` is the Browser COM/MSHTML GUID band ending in `IID_IHTMLDocument2`, `0x00631660-0x00631850` is the IJG libjpeg message pointer table installed by `sub_401000`, and `0x00631850-0x00632560` is zlib 1.1.4 read-only data including `crc_table` and the deflate version string.
- IDA DB changes: none. Skipped candidates: no IDA renames, comments, prototypes, type edits, or data retyping were applied. The Browser aggregate correction is documentation-backed, but IDA global names/types for DirectDraw/MSHTML/libjpeg/zlib constants should wait for a coordinated SDK/third-party data naming pass.
- Validation: sequential `python .\tools\validator.py --mode file --file <file> --apply --lock-timeout 60` for the four new child pages and four assigned target pages exited `0`. The first run inserted [UID:0003OG] and [UID:0003OH], later runs inserted [UID:0003OI] and [UID:0003OJ], resolved TMP links, updated [UID:000272] autogen metadata from Browser-emitting to non-reconstructable, and updated generated memory coverage for the new exact children.

## Supervisor-Applied `by-memory/-coverage-report.md` Updates

- Supervisor applied and validated the [UID:00025J], [UID:00025L], [UID:00025Q], [UID:000272], [UID:0003OG], [UID:0003OH], [UID:0003OI], and [UID:0003OJ] `by-memory/-coverage-report.md` row changes on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No C001 Goal 2 RData Child Score Batch supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

Applied exact row changes:

```text
    - [UID:00025J][0x0061c360-0x0061c5a0.IMEPaneReadOnlyData](by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md) 0x0061c360-0x0061c5a0 | vtable/string-data | IMEPaneReadOnlyData : reconstructable : 87% : strong : C001 live IDA refresh reconfirmed 15 named heads, four IME pane vtable triplets, vtable/store xrefs, UTF-16 `Closed`/`IME`/`ENG` label bytes, the `0x0061c5a0` InputMan successor, and source-file ownership through [UID:0000K5][IMEPanes](by-file/IMEPanes.md); no extra split was created because the full island is a coherent IMEPanes read-only aggregate.
    - [UID:00025L][0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData](by-memory/0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData.md) 0x0061c7a4-0x0061c9c4 | mixed-rdata index | InventoryPaneReadOnlyData : ignored : 87% : strong : C001 live IDA refresh reconfirmed 18 named heads, InventoryPane/NewInventoryPane/InventoryPane2 locator and vtable xrefs, resource-string xrefs, `ITEMINV.EPD` byte boundary, and `KeySpeedMgr` successor; this is a reviewed non-emitting mixed map with exact children [UID:0003BU][0x0061c7a4-0x0061c7e0.InventoryPaneVtableData](by-memory/0x0061c7a4-0x0061c7e0.InventoryPaneVtableData.md), [UID:0003BV][0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData](by-memory/0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData.md), [UID:0003BW][0x0061c86c-0x0061c8f8.InventoryPane2VtableData](by-memory/0x0061c86c-0x0061c8f8.InventoryPane2VtableData.md), and [UID:0003BX][0x0061c8f8-0x0061c9c4.InventoryResourceStrings](by-memory/0x0061c8f8-0x0061c9c4.InventoryResourceStrings.md) carrying direct ownership.
    - [UID:00025Q][0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData](by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md) 0x0061d264-0x0061e5b4 | mixed-rdata index | MainMenuNewUserReadOnlyData : ignored : 86% : strong : C001 live IDA refresh reconfirmed the 119-label main-menu/new-user/login/scrolled/staff/history/resource inventory, boundary bytes from `0x0061d264` through the `0x0061e5b4` MapName/MiniMap handoff, existing exact child anchors [UID:0003BY][0x0061d264-0x0061d2ec.MainMenuPaneVtableData](by-memory/0x0061d264-0x0061d2ec.MainMenuPaneVtableData.md), [UID:0002OV][0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData](by-memory/0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData.md), [UID:0002OW][0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData](by-memory/0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData.md), and [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md), and representative resource xrefs; aggregate remains non-emitting because no single direct parent owns the whole span.
    - [UID:000272][0x00631570-0x00632560.BrowserComGuidReadOnlyData](by-memory/0x00631570-0x00632560.BrowserComGuidReadOnlyData.md) 0x00631570-0x00632560 | mixed-rdata-map | BrowserComGuidReadOnlyData : ignored : 88% : strong : C001 corrected this historical Browser-only range to a non-emitting mixed map: live IDA and SDK evidence split DirectDraw `IID_IDirectDraw`, Browser COM/MSHTML GUIDs, IJG libjpeg 6b message table, zlib 1.1.4 read-only constants/strings, and the `0x00632560` MSVC runtime successor; exact children carry the real owners.
        - [UID:0003OG][0x00631570-0x00631580.DirectDrawGuidConstant](by-memory/0x00631570-0x00631580.DirectDrawGuidConstant.md) 0x00631570-0x00631580 | SDK GUID | DirectDrawGuidConstant : ignored : 88% : strong : Exact `IID_IDirectDraw` GUID `6c14db80-a733-11ce-a521-0020af0be560`; live bytes, one graphics-path xref at `0x004a1bd8`, and local Windows SDK `ddraw.h`/`uuids.h` evidence prove this is not Browser data.
        - [UID:0003OH][0x00631580-0x00631660.BrowserComGuidConstants](by-memory/0x00631580-0x00631660.BrowserComGuidConstants.md) 0x00631580-0x00631660 | guid-data | BrowserComGuidConstants : reconstructable : 89% : strong : Exact Browser COM/OLE/WebBrowser/MSHTML GUID band from `IID_IUnknown` through `IID_IHTMLDocument2`; live xrefs tie representative GUIDs to Browser OLE setup/query/advise code, and owner/emitter route through [UID:0000HV][Browser](by-file/Browser.md).
        - [UID:0003OI][0x00631660-0x00631850.LibJpeg6bMessagePointerTable](by-memory/0x00631660-0x00631850.LibJpeg6bMessagePointerTable.md) 0x00631660-0x00631850 | third-party pointer-table | LibJpeg6bMessagePointerTable : reconstructable : 88% : strong : Exact IJG libjpeg 6b message pointer table installed by `sub_401000` at `0x00401031`; live bytes point into [UID:00028D][0x006707d4-0x00671a74.LibJpeg6bDataMessagesAndMemoryStrings](by-memory/0x006707d4-0x00671a74.LibJpeg6bDataMessagesAndMemoryStrings.md), with owner/emitter [UID:0000KN][LibJPEG](by-file/LibJPEG.md).
        - [UID:0003OJ][0x00631850-0x00632560.Zlib114ReadOnlyConstantsAndStrings](by-memory/0x00631850-0x00632560.Zlib114ReadOnlyConstantsAndStrings.md) 0x00631850-0x00632560 | third-party rdata | Zlib114ReadOnlyConstantsAndStrings : reconstructable : 86% : strong : Exact zlib 1.1.4 read-only constants/string child after the libjpeg table; live xrefs tie `0x0063211c` to `Crc32`, bytes decode the deflate 1.1.4 copyright/version string, and owner/emitter route through [UID:0000PC][Zlib](by-file/Zlib.md).
```

## 2026-06-14 Agent-C001 Goal 2 RData Child Score Batch C001-goal2-rdata-child-score-20260614-2

- Changed docs: [UID:00025N][0x0061ca44-0x0061cf68.LayerInputListReadOnlyData](../../../../by-memory/0x0061ca44-0x0061cf68.LayerInputListReadOnlyData.md), [UID:00025O][0x0061cf68-0x0061d118.LObjectLogoReadOnlyData](../../../../by-memory/0x0061cf68-0x0061d118.LObjectLogoReadOnlyData.md), [UID:00025P][0x0061d118-0x0061d264.BaramAppReadOnlyData](../../../../by-memory/0x0061d118-0x0061d264.BaramAppReadOnlyData.md), [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](../../../../by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md), new [UID:0003OK][0x0061ca44-0x0061ca54.LayerVtableData](../../../../by-memory/0x0061ca44-0x0061ca54.LayerVtableData.md), new [UID:0003OL][0x0061ce28-0x0061ce84.ListSortedListVtableData](../../../../by-memory/0x0061ce28-0x0061ce84.ListSortedListVtableData.md), new [UID:0003OM][0x0061ce84-0x0061cf44.ListPaneVtableData](../../../../by-memory/0x0061ce84-0x0061cf44.ListPaneVtableData.md), new [UID:0003ON][0x0061cf44-0x0061cf68.LObjectTypeNameData](../../../../by-memory/0x0061cf44-0x0061cf68.LObjectTypeNameData.md), new [UID:0003OO][0x0061cf68-0x0061cf78.LObjectVtableData](../../../../by-memory/0x0061cf68-0x0061cf78.LObjectVtableData.md), new [UID:0003OP][0x0061cf78-0x0061d000.LogoPaneVtableData](../../../../by-memory/0x0061cf78-0x0061d000.LogoPaneVtableData.md), new [UID:0003OQ][0x0061d000-0x0061d018.LogoPaneCallbackVtableData](../../../../by-memory/0x0061d000-0x0061d018.LogoPaneCallbackVtableData.md), new [UID:0003OR][0x0061d018-0x0061d0a8.LogoPlayerPaneVtableData](../../../../by-memory/0x0061d018-0x0061d0a8.LogoPlayerPaneVtableData.md), new [UID:0003OS][0x0061d0a8-0x0061d0f0.StartupLogoResourceStrings](../../../../by-memory/0x0061d0a8-0x0061d0f0.StartupLogoResourceStrings.md), new [UID:0003OT][0x0061d0f0-0x0061d118.MapiLookupStrings](../../../../by-memory/0x0061d0f0-0x0061d118.MapiLookupStrings.md), [UID:00000V][BaramApp](../../../../by-class/BaramApp.md), `by-class/-coverage-report.md`, validator-owned `auto-generated/-ag-memory-coverage.md`, validator/project stats, validator registry state, and this notes file.
- Score changes: [UID:00025N] `83/92 -> 86/92`; [UID:00025O] `82/91 -> 86/92`; [UID:00025P] `80/90 -> 82/91`; [UID:0002M6] `82/90 -> 86/92`; [UID:00000V] `84/90 -> 85/90`; new [UID:0003OK] `0/0 -> 86/91`; [UID:0003OL] `0/0 -> 86/91`; [UID:0003OM] `0/0 -> 85/90`; [UID:0003ON] `0/0 -> 86/91`; [UID:0003OO] `0/0 -> 86/91`; [UID:0003OP] `0/0 -> 86/91`; [UID:0003OQ] `0/0 -> 86/90`; [UID:0003OR] `0/0 -> 86/91`; [UID:0003OS] `0/0 -> 86/91`; [UID:0003OT] `0/0 -> 86/91`.
- Owner/emitter decisions: [UID:00025N] and [UID:00025O] remain `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitters as non-emitting mixed maps whose exact children carry ownership. [UID:0003OK] routes through [UID:0000KL] `Layer`; [UID:0003OL] routes through [UID:0000KS] `List`; [UID:0003OM] is reconstructable but intentionally ownerless/non-emitting because the direct [UID:0000KT] `ListPane` support page remains `88/84`; [UID:0003ON]/[UID:0003OO] route through [UID:00007D] `LObject`; [UID:0003OP] routes through [UID:00007G] `LogoPane`; [UID:0003OQ] routes through [UID:0000JO] `FunctionObjects`; [UID:0003OR] routes through [UID:00007H] `LogoPlayerPane`; [UID:0003OS] routes through [UID:0000O4] `StartupLogoPanes`; [UID:0003OT] routes through [UID:0000ML] `PlatformApi`. [UID:00025P] remains routed through [UID:00000V] `BaramApp` after the support class was refreshed to clear `85/85`. [UID:0002M6] remains routed through [UID:00000Y] `BlueAlertPane`.
- Evidence summary: live IDA MCP session `a001_goal2_class_batch` reconfirmed active read-only `NexusTK.exe.i64`, image base `0x00400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. C001 refreshed named inventories, xrefs, and byte boundaries for the Layer/List/LObject/Logo/BaramApp/BlueAlert ranges; exact children were created only where the mixed subrange boundaries and owner gates were supported. No IDA database edits were applied.
- Validation: sequential `python .\tools\validator.py --mode file --file <file> --apply --lock-timeout 60` for the ten new child pages, the four assigned target pages, [UID:00000V] `BaramApp`, and `by-class/-coverage-report.md` exited `0`; each visible validator summary reached `ok: 1` after UID insertion and reference normalization.
- IDA DB changes: none. Skipped candidates: no IDA names, comments, prototypes, type/member edits, vtable edits, string retyping, or data retyping were applied because current documentation evidence is sufficient for score/routing updates, while final source declarations, callback-template spelling, ListPane support gating, and string/data typing remain below the C-agent safe-edit threshold.

## Supervisor-Applied `by-memory/-coverage-report.md` Updates

- Supervisor applied and validated [UID:00025N], [UID:00025O], [UID:00025P], [UID:0002M6], and new [UID:0003OK] through [UID:0003OT] row changes on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result: `ok: 1`.
- No C001 Goal 2 RData Child Score Batch `00025N/00025O/00025P/0002M6` supervisor-owned rows remain pending.
- Applied exact row changes:

```text
    - [UID:00025N][0x0061ca44-0x0061cf68.LayerInputListReadOnlyData](by-memory/0x0061ca44-0x0061cf68.LayerInputListReadOnlyData.md) 0x0061ca44-0x0061cf68 | mixed-rdata index | LayerInputListReadOnlyData : ignored : 86% : strong : C001 live IDA refresh reconfirmed the Layer/input-pane/List/SortedList/ListPane/LObject-tail named inventory, xrefs, byte boundaries, and exact child split; this is a reviewed non-emitting mixed map, with [UID:0003OM][0x0061ce84-0x0061cf44.ListPaneVtableData](by-memory/0x0061ce84-0x0061cf44.ListPaneVtableData.md) left ownerless until [UID:0000KT][ListPane](by-file/ListPane.md) clears `85/85`.
        - [UID:0003OK][0x0061ca44-0x0061ca54.LayerVtableData](by-memory/0x0061ca44-0x0061ca54.LayerVtableData.md) 0x0061ca44-0x0061ca54 | vtable-data | LayerVtableData : reconstructable : 86% : strong : Exact Layer COL/vtable child; live IDA names/xrefs/bytes confirm the `0x0061ca44` locator, `0x0061ca48` vtable, `0x0061ca54` LineInputPane successor, and owner/emitter route through [UID:0000KL][Layer](by-file/Layer.md).
        - [UID:000389][0x0061ca54-0x0061ce28.InputPaneBaseVtableData](by-memory/0x0061ca54-0x0061ce28.InputPaneBaseVtableData.md) 0x0061ca54-0x0061ce28 | vtable-data | InputPaneBaseVtableData : reconstructable : 86% : strong : Existing exact input-pane vtable child for seven input-pane classes, owned by [UID:0000K7][InputPanes](by-file/InputPanes.md).
        - [UID:0003OL][0x0061ce28-0x0061ce84.ListSortedListVtableData](by-memory/0x0061ce28-0x0061ce84.ListSortedListVtableData.md) 0x0061ce28-0x0061ce84 | vtable-data | ListSortedListVtableData : reconstructable : 86% : strong : Exact List and SortedList COL/vtable child; live IDA names/xrefs/bytes confirm the `List`, `SortedList`, and `ListPane` successor boundaries and owner/emitter route through [UID:0000KS][List](by-file/List.md).
        - [UID:0003OM][0x0061ce84-0x0061cf44.ListPaneVtableData](by-memory/0x0061ce84-0x0061cf44.ListPaneVtableData.md) 0x0061ce84-0x0061cf44 | vtable-data | ListPaneVtableData : reconstructable : 85% : strong : Exact ListPane primary/secondary/tertiary vtable child; live IDA confirms table heads, constructor/destructor-store refs, and `0x0061cf44` LObject-tail boundary, but owner/emitter route is intentionally blank because [UID:0000KT][ListPane](by-file/ListPane.md) remains `88/84`.
        - [UID:0003ON][0x0061cf44-0x0061cf68.LObjectTypeNameData](by-memory/0x0061cf44-0x0061cf68.LObjectTypeNameData.md) 0x0061cf44-0x0061cf68 | runtime-class string-data | LObjectTypeNameData : reconstructable : 86% : strong : Exact LObject runtime type-name pointer/string tail before the LObject vtable; live IDA confirms `off_61CF44 -> aLobject`, xrefs from `sub_4F4B10`, bytes, and owner/emitter route through [UID:00007D][LObject](by-class/LObject.md).
    - [UID:00025O][0x0061cf68-0x0061d118.LObjectLogoReadOnlyData](by-memory/0x0061cf68-0x0061d118.LObjectLogoReadOnlyData.md) 0x0061cf68-0x0061d118 | mixed-rdata index | LObjectLogoReadOnlyData : ignored : 86% : strong : C001 live IDA refresh reconfirmed the LObject/LogoPane/LogoPane-callback/LogoPlayerPane/startup-logo/MAPI named inventory, xrefs, decoded bytes, BaramApp successor boundary, and exact child split; aggregate remains non-emitting because no single direct parent owns the whole span.
        - [UID:0003OO][0x0061cf68-0x0061cf78.LObjectVtableData](by-memory/0x0061cf68-0x0061cf78.LObjectVtableData.md) 0x0061cf68-0x0061cf78 | vtable-data | LObjectVtableData : reconstructable : 86% : strong : Exact LObject vtable child; live IDA confirms the table head, runtime-shell xrefs, `LogoPane` successor boundary, and owner/emitter route through [UID:00007D][LObject](by-class/LObject.md).
        - [UID:0003OP][0x0061cf78-0x0061d000.LogoPaneVtableData](by-memory/0x0061cf78-0x0061d000.LogoPaneVtableData.md) 0x0061cf78-0x0061d000 | vtable-data | LogoPaneVtableData : reconstructable : 86% : strong : Exact LogoPane primary/secondary/tertiary vtable child; live IDA confirms table heads, constructor/cleanup/destructor refs, callback successor boundary, and owner/emitter route through [UID:00007G][LogoPane](by-class/LogoPane.md).
        - [UID:0003OQ][0x0061d000-0x0061d018.LogoPaneCallbackVtableData](by-memory/0x0061d000-0x0061d018.LogoPaneCallbackVtableData.md) 0x0061d000-0x0061d018 | callback vtable-data | LogoPaneCallbackVtableData : reconstructable : 86% : strong : Exact `PlainMemberFunctionObject0<LogoPane>` callback vtable child; live IDA confirms the concrete callback table, construction xrefs at `0x004f4e61`/`0x004f529f`, and owner/emitter route through [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md).
        - [UID:0003OR][0x0061d018-0x0061d0a8.LogoPlayerPaneVtableData](by-memory/0x0061d018-0x0061d0a8.LogoPlayerPaneVtableData.md) 0x0061d018-0x0061d0a8 | vtable-data | LogoPlayerPaneVtableData : reconstructable : 86% : strong : Exact LogoPlayerPane primary/secondary/tertiary vtable child; live IDA confirms table heads, constructor/cleanup/destructor refs, startup-logo string successor boundary, and owner/emitter route through [UID:00007H][LogoPlayerPane](by-class/LogoPlayerPane.md).
        - [UID:0003OS][0x0061d0a8-0x0061d0f0.StartupLogoResourceStrings](by-memory/0x0061d0a8-0x0061d0f0.StartupLogoResourceStrings.md) 0x0061d0a8-0x0061d0f0 | string-data | StartupLogoResourceStrings : reconstructable : 86% : strong : Exact startup-logo/Bink strings (`%s corrupted`, `LOGO.PAK`, `LOGO.PAD`, `Bink Error`); live IDA labels and byte decoding tie the range to [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md).
        - [UID:0003OT][0x0061d0f0-0x0061d118.MapiLookupStrings](by-memory/0x0061d0f0-0x0061d118.MapiLookupStrings.md) 0x0061d0f0-0x0061d118 | string-data | MapiLookupStrings : reconstructable : 86% : strong : Exact dynamic MAPI lookup strings `MAPI32.DLL` and `MAPISendMail`; live IDA confirms labels, `0x004f5b3d` helper ref, BaramApp successor boundary, and owner/emitter route through [UID:0000ML][PlatformApi](by-file/PlatformApi.md).
    - [UID:00025P][0x0061d118-0x0061d264.BaramAppReadOnlyData](by-memory/0x0061d118-0x0061d264.BaramAppReadOnlyData.md) 0x0061d118-0x0061d264 | vtable/string-data | BaramAppReadOnlyData : reconstructable : 82% : strong : C001 live IDA refresh reconfirmed BaramApp primary/secondary vtable slots, `PlainMemberFunctionObject0<BaramApp>` callback vtable slots, startup/update/updater/logo literals, `_WinMain@16`/`Application::Startup` xrefs, and the `MainMenuPane` successor boundary; route through [UID:00000V][BaramApp](by-class/BaramApp.md) is now gate-valid after support class refresh to `85/90`.
        - [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md) 0x0061dcd8-0x0061dd78 | vtable-data | BlueAlertPaneVtableData : reconstructable : 86% : strong : C001 live IDA refresh reconfirmed the exact primary/secondary/tertiary BlueAlertPane vtable heads, constructor-store refs, slot map, no endpoint ref at `0x0061dd78`, and `UserHairSelectControlPane` successor boundary; route remains through [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md).
```

## 2026-06-14 Agent-C001 Goal 2 ListPane Support Route Batch C001-goal2-listpane-support-route-20260614-1

- Changed docs: [UID:0000KT][ListPane](../../../../by-file/ListPane.md), [UID:0003OM][0x0061ce84-0x0061cf44.ListPaneVtableData](../../../../by-memory/0x0061ce84-0x0061cf44.ListPaneVtableData.md), [UID:00025N][0x0061ca44-0x0061cf68.LayerInputListReadOnlyData](../../../../by-memory/0x0061ca44-0x0061cf68.LayerInputListReadOnlyData.md), [UID:0000KT] row in `by-file/-coverage-report.md`, validator-owned generated files, and this notes file.
- Score changes: [UID:0000KT] `88/84 -> 88/85`; [UID:0003OM] stays `85/90`; [UID:00025N] stays `86/92`.
- Owner/emitter decisions: [UID:0003OM] changed from `CANONICAL_OWNER:NONE`, blank emitters to `CANONICAL_OWNER:0000KT`, `EMITTER_UIDS:0000KT`. [UID:00025N] remains `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitters as a non-emitting mixed map whose exact children carry ownership. [UID:0000KT] remains the direct file owner/emitter support page.
- Evidence summary: live IDA MCP session `a001_goal2_class_batch` reconfirmed the ListPane modeled function family, all three `ListPane` vtable table heads at `0x0061ce84`, `0x0061cf0c`, and `0x0061cf3c`, constructor/destructor/scalar-destructor store refs at `0x004f3a50`, `0x004f3b60`, and `0x004f4a00`, the `0x0061cf44` `LObject` successor boundary, and broad cross-feature helper fanout for core `ListPane` methods. Raw `0x004f4820` and `0x004f4910` islands remain documented caveats, so confidence was raised only to the gate.
- IDA DB changes: none. Skipped candidates: no names, comments, prototypes, type/member edits, vtable edits, string retyping, or data retyping were applied.
- Validation: sequential scoped validator runs exited `0` with `ok: 1` for `by-file/ListPane.md`, `by-memory/0x0061ce84-0x0061cf44.ListPaneVtableData.md`, `by-memory/0x0061ca44-0x0061cf68.LayerInputListReadOnlyData.md`, and `by-file/-coverage-report.md`. Validator normalized [UID:0003OM] link labels, updated [UID:0000KT] confidence, and registered [UID:0003OM] owner route through [UID:0000KT].

### Supervisor-applied `by-memory/-coverage-report.md` replacements

Supervisor applied and validated the [UID:00025N] row and its [UID:0003OM] child row on 2026-06-14 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result: `ok: 1`.

Applied replacements:

```text
    - [UID:00025N][0x0061ca44-0x0061cf68.LayerInputListReadOnlyData](by-memory/0x0061ca44-0x0061cf68.LayerInputListReadOnlyData.md) 0x0061ca44-0x0061cf68 | mixed-rdata index | LayerInputListReadOnlyData : ignored : 86% : strong : C001 live IDA refresh reconfirmed the Layer/input-pane/List/SortedList/ListPane/LObject-tail named inventory, xrefs, byte boundaries, and exact child split; this is a reviewed non-emitting mixed map, with [UID:0003OM][0x0061ce84-0x0061cf44.ListPaneVtableData](by-memory/0x0061ce84-0x0061cf44.ListPaneVtableData.md) now routed through [UID:0000KT][ListPane](by-file/ListPane.md) after the support page cleared `88/85`.
        - [UID:0003OM][0x0061ce84-0x0061cf44.ListPaneVtableData](by-memory/0x0061ce84-0x0061cf44.ListPaneVtableData.md) 0x0061ce84-0x0061cf44 | vtable-data | ListPaneVtableData : reconstructable : 85% : strong : Exact ListPane primary/secondary/tertiary vtable child; live IDA confirms table heads, constructor/destructor-store refs, and `0x0061cf44` LObject-tail boundary, with owner/emitter route through [UID:0000KT][ListPane](by-file/ListPane.md) after the support page reached `88/85`.
```

## 2026-06-14 Agent-C001 Goal 2 RData Vtable Score Batch C001-goal2-rdata-vtable-score-20260614-3

- Changed docs: [UID:0002N5][0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData](../../../../by-memory/0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData.md), [UID:0002N6][0x006300d4-0x006301e8.GroupPostInputPaneVtableData](../../../../by-memory/0x006300d4-0x006301e8.GroupPostInputPaneVtableData.md), [UID:0002N7][0x0063041c-0x006304a4.SpellSpellInputPaneVtableData](../../../../by-memory/0x0063041c-0x006304a4.SpellSpellInputPaneVtableData.md), [UID:0002N8][0x006305c0-0x00630648.SelfSaveInputPaneVtableData](../../../../by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md), validator-owned generated files, and this notes file.
- Score changes: [UID:0002N5] `86/90 -> 87/91`; [UID:0002N6] `86/90 -> 87/91`; [UID:0002N7] `85/90 -> 86/91`; [UID:0002N8] `85/89 -> 86/90`.
- Owner/emitter decisions: routes remain unchanged. [UID:0002N5] routes through [UID:00001M][ChangeSpellSlotInputPane](../../../../by-class/ChangeSpellSlotInputPane.md); [UID:0002N6] routes through [UID:0000ID][CommandInputPanes](../../../../by-file/CommandInputPanes.md); [UID:0002N7] routes through [UID:0000DT][SpellSpellInputPane](../../../../by-class/SpellSpellInputPane.md); [UID:0002N8] routes through [UID:0000CW][SelfSaveInputPane](../../../../by-class/SelfSaveInputPane.md). Final C++ remains blank on all four because the ranges are source-declared/generated-binary vtable data and raw constructor/source declaration caveats remain.
- Evidence summary: live IDA MCP session `a001_goal2_class_batch` reported healthy active `NexusTK.exe.i64`, image base `0x00400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. C001 refreshed named table heads, key slot dwords, locator/successor dwords, xrefs, and modeled/raw function boundaries for all four vtable children. The pass reconfirmed raw constructor caveats for `ChangeSpellSlotInputPane`, `GroupInputPane`, and `SelfSaveInputPane`, modeled constructor/method functions for `PostInputPane` and `SpellSpellInputPane`, and exact successor boundaries before `SayInputPane`, `ThrowInputPane`, `WieldInputPane`, and `BlockListenInputPane`.
- IDA DB changes: none. Skipped candidates: no IDA names, comments, prototypes, type/member edits, vtable edits, or data retyping were applied because current evidence supports documentation scores/routes but not DB mutation.
- Validation: scoped loop `python .\tools\validator.py --mode file --file <target> --apply --lock-timeout 60` exited `0` for all four changed target docs; each run reached `ok: 1`. Validator recorded [UID:0002N5] `completion_update 87`/`confidence_update 91`, and the later target runs completed successfully for [UID:0002N6], [UID:0002N7], and [UID:0002N8]. `auto-generated/-ag-memory-coverage.md` still shows all four target rows emitting through their existing owners.

### Supervisor-applied `by-memory/-coverage-report.md` replacements

Supervisor applied and validated the [UID:0002N5] through [UID:0002N8] rows on 2026-06-14 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result: `ok: 1`.

Applied replacements:

```text
        - [UID:0002N5][0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData](by-memory/0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData.md) 0x0062fad0-0x0062fb58 | vtable-data | ChangeSpellSlotInputPaneVtableData : reconstructable : 87% : strong : Exact three-view `ChangeSpellSlotInputPane` vtable child; C001 live IDA refresh reconfirmed named table heads, submit/key/adjustor slots, locator dwords, dispatcher/open/raw-constructor xrefs, `SayInputPane` successor boundary, and owner/emitter route through [UID:00001M][ChangeSpellSlotInputPane](by-class/ChangeSpellSlotInputPane.md), with final C++ blank because the vtable is compiler-emitted and the constructor start remains raw/non-function.
        - [UID:0002N6][0x006300d4-0x006301e8.GroupPostInputPaneVtableData](by-memory/0x006300d4-0x006301e8.GroupPostInputPaneVtableData.md) 0x006300d4-0x006301e8 | vtable-data | GroupPostInputPaneVtableData : reconstructable : 87% : strong : Exact combined `GroupInputPane`/`PostInputPane` vtable child; C001 live IDA refresh reconfirmed all six table heads, Group submit slot, Post confirm/key slots, locator dwords, dispatcher/open/constructor xrefs, `ThrowInputPane` successor boundary, and owner/emitter route through [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md), with final C++ blank because the vtable bytes are compiler-emitted and the Group constructor path remains raw/non-function.
        - [UID:0002N7][0x0063041c-0x006304a4.SpellSpellInputPaneVtableData](by-memory/0x0063041c-0x006304a4.SpellSpellInputPaneVtableData.md) 0x0063041c-0x006304a4 | vtable-data | SpellSpellInputPaneVtableData : reconstructable : 86% : strong : Exact three-view `SpellSpellInputPane` vtable child; C001 live IDA refresh reconfirmed named table heads, accept/key/adjustor slots, locator dwords, dispatcher/open/constructor xrefs, modeled method boundaries, `WieldInputPane` successor boundary, and owner/emitter route through [UID:0000DT][SpellSpellInputPane](by-class/SpellSpellInputPane.md); final C++ stays blank because this is compiler-emitted vtable data.
        - [UID:0002N8][0x006305c0-0x00630648.SelfSaveInputPaneVtableData](by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md) 0x006305c0-0x00630648 | vtable-data | SelfSaveInputPaneVtableData : reconstructable : 86% : strong : Exact three-view `SelfSaveInputPane` vtable child; C001 live IDA refresh reconfirmed named table heads, confirmation/adjustor slots, locator dwords, factory/raw-constructor xrefs, `BlockListenInputPane` successor boundary, and owner/emitter route through [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md), with final C++ blank because the vtable is compiler-emitted and constructor/helper source placement remains caveated.
```

## 2026-06-14 Agent-C001 Goal 2 RData Vtable/String Score Batch C001-goal2-rdata-vtable-string-score-20260614-4

- Changed docs: [UID:0002N9][0x0063064c-0x006307ec.BlockListenInputPaneVtableData](../../../../by-memory/0x0063064c-0x006307ec.BlockListenInputPaneVtableData.md), [UID:0001OF][0x00630bd8-0x00630c06.g_equipmentSlotKeys](../../../../by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md), [UID:0002OZ][0x0062e184-0x0062e18c.TextFilterVtableData](../../../../by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md), [UID:0002OM][0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData](../../../../by-memory/0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData.md), validator-owned generated files, and this notes file.
- Score changes: [UID:0002N9] `86/90 -> 87/91`; [UID:0001OF] `84/89 -> 86/91`; [UID:0002OZ] `86/90 -> 87/91`; [UID:0002OM] `85/90 -> 86/91`.
- Owner/emitter decisions: routes remain unchanged. [UID:0002N9] routes through [UID:0000HS][BlockListenInputPanes](../../../../by-file/BlockListenInputPanes.md); [UID:0001OF] routes through [UID:0000PX][g_equipmentSlotKeys](../../../../by-global/g_equipmentSlotKeys.md) and now clears the child side of the gate; [UID:0002OZ] routes through [UID:0001YY][TextFilterVtable](../../../../by-type/by-vtable/TextFilterVtable.md); [UID:0002OM] routes through [UID:0000BE][PursuitMessageDialogPane](../../../../by-class/PursuitMessageDialogPane.md). Final C++ remains blank on all four because the ranges are compiler-emitted vtable data or source-declared lookup data whose final declaration spelling/source placement is not proven.
- Evidence summary: live IDA MCP session `a001_goal2_class_batch` reported healthy active `NexusTK.exe.i64`, image base `0x00400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. C001 refreshed named table heads, representative dword cells, xrefs, function boundaries, and successor boundaries for the three vtable targets. For [UID:0001OF], C001 refreshed the exact `0x2e` table bytes, single `0x005b28f0` xref inside `sub_5B2830`, and decompiler evidence for the 23-entry scan, uppercase `A` all-equipment branch, and selector `index + 1` send behavior.
- IDA DB changes: none. Skipped candidates: no IDA names, comments, prototypes, type/member edits, vtable edits, or data retyping were applied because current evidence supports documentation scores/routes but not DB mutation.
- Validation: scoped loop `python .\tools\validator.py --mode file --file <target> --apply --lock-timeout 60` exited `0` for all four changed target docs; each run reached `ok: 1`. Validator recorded [UID:0002N9] `completion_update 87`/`confidence_update 91`, and the later target runs completed successfully for [UID:0001OF], [UID:0002OZ], and [UID:0002OM]. `auto-generated/-ag-memory-coverage.md` still shows all four target rows emitting through their existing owners.

### Supervisor-applied `by-memory/-coverage-report.md` replacements

Supervisor applied and validated the [UID:0002OM], [UID:0002OZ], [UID:0002N9], and [UID:0001OF] rows on 2026-06-14 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result: `ok: 1`.

Applied replacements:

```text
        - [UID:0002OM][0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData](by-memory/0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData.md) 0x00622424-0x006224c0 | vtable-data | PursuitMessageDialogPaneVtableData : reconstructable : 86% : strong : Exact primary/secondary/tertiary `PursuitMessageDialogPane` RTTI/vtable child; C001 live IDA refresh reconfirmed three table heads, representative dword cells, raw constructor store refs, shared response/thunk/destructor function boundaries, `MessageDialog` successor boundary, and owner/emitter route through [UID:0000BE][PursuitMessageDialogPane](by-class/PursuitMessageDialogPane.md), with final C++ blank because the vtable is compiler-emitted and the raw constructor/shared response naming remains caveated.
        - [UID:0002OZ][0x0062e184-0x0062e18c.TextFilterVtableData](by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md) 0x0062e184-0x0062e18c | vtable-data | TextFilterVtableData : reconstructable : 87% : strong : Exact one-slot `TextFilter` RTTI-adjacent vtable-data child; C001 live IDA refresh reconfirmed the `MBOLS.EPD` predecessor, COL/vtable dwords, scalar deleting destructor slot, four constructor/destructor xrefs, `TextPad` successor boundary, and owner/emitter route through [UID:0001YY][TextFilterVtable](by-type/by-vtable/TextFilterVtable.md), with final C++ blank pending final TextFilter source placement.
        - [UID:0002N9][0x0063064c-0x006307ec.BlockListenInputPaneVtableData](by-memory/0x0063064c-0x006307ec.BlockListenInputPaneVtableData.md) 0x0063064c-0x006307ec | vtable-data | BlockListenInputPaneVtableData : reconstructable : 87% : strong : Exact block-list show/add/delete prompt vtable child; C001 live IDA refresh reconfirmed all nine table heads, representative slots, dispatch/open/raw-constructor xrefs, modeled handler boundaries, raw constructor caveats, the `0x006307ec` UTF-16 string successor, and owner/emitter route through [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md), with final C++ blank because the vtable is compiler-emitted.
    - [UID:0001OF][0x00630bd8-0x00630c06.g_equipmentSlotKeys](by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md) 0x00630bd8-0x00630c06 | fixed UTF-16 lookup table | g_equipmentSlotKeys : reconstructable : 86% : strong : Exact 23-entry non-terminated equipment-slot key lookup; C001 live IDA refresh reconfirmed the 46 bytes for `wash#nlr####fm#c###[]12`, the single `0x005b28f0` xref inside `TakeOffInputPane::ProcessUnequipCommand`, the 23-entry scan, uppercase `A` all-equipment branch, selector `index + 1` send behavior, predecessor/successor boundaries, and owner/emitter route through [UID:0000PX][g_equipmentSlotKeys](by-global/g_equipmentSlotKeys.md), with final C++ blank pending original declaration spelling/source placement.
```

## 2026-06-15 Agent-C001 Goal 2 Section Container Follow-up C001-goal2-section-container-followup-20260615-1

- Changed docs: [UID:0000WG][0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers](../../../../by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md), [UID:0002CT][0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction](../../../../by-memory/0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction.md), [UID:0001Z5][0x00401000-0x0060d000.MasterCodeTextSection](../../../../by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md), validator-owned `project-level/-auto-completion-stats.md`, validator registry state, and this notes file.
- Score changes: [UID:0000WG] `82/90 -> 85/91`; [UID:0002CT] `84/90 -> 85/91`; [UID:0001Z5] `79/89 -> 80/89`. [UID:0001Z7] was not edited in this slice and remains `79/90`.
- Owner/emitter decisions: [UID:0000WG] and [UID:0002CT] keep owner/emitter route through [UID:0000JE][FittingRoom](../../../../by-file/FittingRoom.md), with final C++ blank because the helper island/action handler still need source-quality declaration and placement proof. [UID:0001Z5] remains `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitters as a non-emitting `.text` section container; this edit only records concrete child progress.
- Evidence summary: live IDA MCP session `a003_objectlist_dispatch_20260615` reported healthy `NexusTK.exe`, image base `0x00400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. Raw bytes at `0x0041a550+0x90` prove reset/no-op/percent/reset/no-op helper records and the `0x0041a5c1` padding/successor gap. `lookup_funcs`, `xrefs_to`, and `analyze_function` reconfirm no direct xrefs to reset/no-op helpers, exactly one direct xref to the percent helper at `0x0041cbbc` inside [UID:0002CT], duplicate reset bodies clearing byte `+0x00` and dwords `+0x04/+0x08`, and percent calculation `100 * current / total` gated by total. `analyze_function 0x0041cb70` reconfirmed exact `0x1c8` bounds, vtable-only xref at `0x0060dafc`, no direct callers, child id `7`, request progress state at request `+0x04`, child progress byte update at `+0x108`, invalidation through vtable `+0x20`, terminal `>=100` behavior, request active byte `+0x04`, request buffer offset `+0x10`, catalog-submit path, timer path, and current callee set.
- IDA DB changes: none. Skipped candidates: no IDA names, comments, prototypes, type/member edits, helper retyping, or IDB save were applied because the documentation evidence supports score/routing updates but not a low-risk database mutation.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md --apply --lock-timeout 60` exited `0` with `ok: 1`, [UID:0000WG] completion/confidence updated to `85/91`, and validator inserted the [UID:0002CT] link. `python .\tools\validator.py --mode file --file by-memory\0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction.md --apply --lock-timeout 60` exited `0` with `ok: 1`, [UID:0002CT] completion/confidence updated to `85/91`, and validator normalized [UID:0000WG] links. `python .\tools\validator.py --mode file --file by-memory\0x00401000-0x0060d000.MasterCodeTextSection.md --apply --lock-timeout 60` exited `0` with `ok: 1`, [UID:0001Z5] completion updated to `80`, and validator removed [UID:0001Z5] from generated low-completion stats.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows

Supervisor applied the exact [UID:0001Z5], [UID:0000WG], and [UID:0002CT] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No C001 Goal 2 Section Container/FittingRoom follow-up supervisor-owned `by-memory/-coverage-report.md` rows remain pending for this slice.

### Supervisor-applied `by-memory/-coverage-report.md` replacement/insert rows

Supervisor applied the exact [UID:0001Z7] and [UID:00025P] replacement rows plus inserted child rows [UID:0003P2] through [UID:0003P6] on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No C001 BaramApp/MainMenu boundary supervisor-owned `by-memory/-coverage-report.md` rows remain pending for this slice.

Placement context: under [UID:0001Z7][0x0060d670-0x0066d000.ReadOnlyDataSection](../../../../by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md), replace the existing [UID:0001Z7] row and the existing [UID:00025P] row; insert the five new child rows immediately under [UID:00025P] in address order.

- Changed docs: [UID:00025P][0x0061d118-0x0061d264.BaramAppReadOnlyData](../../../../by-memory/0x0061d118-0x0061d264.BaramAppReadOnlyData.md), new [UID:0003P2][0x0061d118-0x0061d140.BaramAppVtableData](../../../../by-memory/0x0061d118-0x0061d140.BaramAppVtableData.md), new [UID:0003P3][0x0061d140-0x0061d234.BaramAppStartupUpdateStrings](../../../../by-memory/0x0061d140-0x0061d234.BaramAppStartupUpdateStrings.md), new [UID:0003P4][0x0061d234-0x0061d24c.BaramAppCallbackVtableData](../../../../by-memory/0x0061d234-0x0061d24c.BaramAppCallbackVtableData.md), new [UID:0003P5][0x0061d24c-0x0061d260.BaramAppLogoResourceString](../../../../by-memory/0x0061d24c-0x0061d260.BaramAppLogoResourceString.md), new [UID:0003P6][0x0061d260-0x0061d264.MainMenuPaneRttiLocatorPointer](../../../../by-memory/0x0061d260-0x0061d264.MainMenuPaneRttiLocatorPointer.md), [UID:0001Z7][0x0060d670-0x0066d000.ReadOnlyDataSection](../../../../by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md), [UID:00000V][BaramApp](../../../../by-class/BaramApp.md), [UID:0003BY][0x0061d264-0x0061d2ec.MainMenuPaneVtableData](../../../../by-memory/0x0061d264-0x0061d2ec.MainMenuPaneVtableData.md), validator-owned generated files, and this notes file.
- Score changes: [UID:00025P] `82/91 -> 86/92`; [UID:00025P] changed from BaramApp-owned reconstructable data to `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitters as a reviewed non-emitting mixed map. New children: [UID:0003P2] `86/92`, [UID:0003P3] `86/91`, [UID:0003P4] `86/91`, [UID:0003P5] `86/91`, [UID:0003P6] `86/92`. [UID:0001Z7] `79/90 -> 80/90`. [UID:00000V] and [UID:0003BY] remain unchanged at `85/90`.
- Owner/emitter decisions: BaramApp exact children [UID:0003P2], [UID:0003P3], [UID:0003P4], and [UID:0003P5] route through [UID:00000V][BaramApp](../../../../by-class/BaramApp.md). [UID:0003P6] routes through [UID:00007O][MainMenuPane](../../../../by-class/MainMenuPane.md). [UID:00025P] is only a mixed index now and must not emit as BaramApp.
- Evidence summary: live IDA MCP session `a003_objectlist_dispatch_20260615` reported healthy `NexusTK.exe`, image base `0x00400000`, Hex-Rays ready, and strings cache ready. `entity_query names` over `0x0061d118-0x0061d2f0` named BaramApp vtables, startup/update strings, `PlainMemberFunctionObject0<BaramApp>` callback vtable, `NEXON.LGO`, and the MainMenuPane successor vtables. `get_bytes` over `0x0061d118-0x0061d268` confirmed the exact vtable dwords, UTF-16/narrow literals, callback table, `NEXON.LGO`, and `0x0061d260 -> 0x0064a078`. `entity_query names 0x0064a060-0x0064a090` named `0x0064a078` as `??_R4MainMenuPane@@6B@`; `xrefs_to 0x0064a078` showed the sole data xref from `0x0061d260`. `xrefs_to` confirmed BaramApp constructor/startup refs for the BaramApp-owned children and MainMenuPane constructor/destructor refs beginning at `0x0061d264`.
- IDA DB changes: none. Skipped candidates: no names, comments, prototypes, type/member edits, vtable edits, string retyping, data retyping, or IDB save were applied because the live evidence supports documentation splits/routes but not a necessary low-risk database mutation.
- Validation: scoped validator loop `python .\tools\validator.py --mode file --file <child> --apply --lock-timeout 60` exited `0` for all five new child docs and assigned [UID:0003P2] through [UID:0003P6]. Scoped validator loop `python .\tools\validator.py --mode file --file <support> --apply --lock-timeout 60` exited `0` for [UID:00025P], [UID:00000V], [UID:0003BY], and [UID:0001Z7]; each run reached `ok: 1`.

Applied exact rows retained for audit:

```text
- [UID:0001Z7][0x0060d670-0x0066d000.ReadOnlyDataSection](by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md) 0x0060d670-0x0066d000 | section-container | ReadOnlyDataSection : ignored : 80% : strong : IDA `.rdata` section container, not a standalone source object; current report has 98 immediate children, 95+ nested children after C001 exact child splits, no immediate unknown/uncovered rows, current bounded IDA name/string inventory, and C001 2026-06-15 child follow-ups splitting AboveFrame/locale tails, employee alert text, and the BaramApp/MainMenu boundary while many broad vtable/string/runtime rows still require child-level audits.
    - [UID:00025P][0x0061d118-0x0061d264.BaramAppReadOnlyData](by-memory/0x0061d118-0x0061d264.BaramAppReadOnlyData.md) 0x0061d118-0x0061d264 | mixed-rdata index | BaramAppReadOnlyData : ignored : 86% : strong : C001 live IDA refresh reclassified this historical BaramApp-owned aggregate as a non-emitting mixed map: exact children [UID:0003P2][0x0061d118-0x0061d140.BaramAppVtableData](by-memory/0x0061d118-0x0061d140.BaramAppVtableData.md), [UID:0003P3][0x0061d140-0x0061d234.BaramAppStartupUpdateStrings](by-memory/0x0061d140-0x0061d234.BaramAppStartupUpdateStrings.md), [UID:0003P4][0x0061d234-0x0061d24c.BaramAppCallbackVtableData](by-memory/0x0061d234-0x0061d24c.BaramAppCallbackVtableData.md), and [UID:0003P5][0x0061d24c-0x0061d260.BaramAppLogoResourceString](by-memory/0x0061d24c-0x0061d260.BaramAppLogoResourceString.md) carry BaramApp ownership, while [UID:0003P6][0x0061d260-0x0061d264.MainMenuPaneRttiLocatorPointer](by-memory/0x0061d260-0x0061d264.MainMenuPaneRttiLocatorPointer.md) carries the MainMenuPane primary COL pointer.
        - [UID:0003P2][0x0061d118-0x0061d140.BaramAppVtableData](by-memory/0x0061d118-0x0061d140.BaramAppVtableData.md) 0x0061d118-0x0061d140 | vtable-data | BaramAppVtableData : reconstructable : 86% : strong : Exact BaramApp primary/secondary vtable child; live IDA names, bytes, and xrefs confirm `??_7BaramApp@@6B@`, `??_7BaramApp@@6B@_0`, slot targets, `_WinMain@16` and raw-constructor stores, `0x0061d140` string successor, and owner/emitter route through [UID:00000V][BaramApp](by-class/BaramApp.md).
        - [UID:0003P3][0x0061d140-0x0061d234.BaramAppStartupUpdateStrings](by-memory/0x0061d140-0x0061d234.BaramAppStartupUpdateStrings.md) 0x0061d140-0x0061d234 | string-data | BaramAppStartupUpdateStrings : reconstructable : 86% : strong : Exact startup/update string child; live IDA bytes decode `NexusTK`, `Nexon`, `Nexus TK update needed`, the newer-version prompt, and `NexusUpdater.exe`, with `_WinMain@16` refs and owner/emitter route through [UID:00000V][BaramApp](by-class/BaramApp.md).
        - [UID:0003P4][0x0061d234-0x0061d24c.BaramAppCallbackVtableData](by-memory/0x0061d234-0x0061d24c.BaramAppCallbackVtableData.md) 0x0061d234-0x0061d24c | callback vtable-data | BaramAppCallbackVtableData : reconstructable : 86% : strong : Exact `PlainMemberFunctionObject0<BaramApp>` callback COL/vtable child; live IDA names, bytes, and the single `ApplicationStartup` store at `0x004f63e6` confirm the range and owner/emitter route through [UID:00000V][BaramApp](by-class/BaramApp.md).
        - [UID:0003P5][0x0061d24c-0x0061d260.BaramAppLogoResourceString](by-memory/0x0061d24c-0x0061d260.BaramAppLogoResourceString.md) 0x0061d24c-0x0061d260 | string-data | BaramAppLogoResourceString : reconstructable : 86% : strong : Exact UTF-16 `NEXON.LGO` startup-logo literal child; live IDA bytes, split-string label `aNLgo`, and two `ApplicationStartup` xrefs at `0x004f6401`/`0x004f6435` confirm owner/emitter route through [UID:00000V][BaramApp](by-class/BaramApp.md).
        - [UID:0003P6][0x0061d260-0x0061d264.MainMenuPaneRttiLocatorPointer](by-memory/0x0061d260-0x0061d264.MainMenuPaneRttiLocatorPointer.md) 0x0061d260-0x0061d264 | RTTI locator pointer | MainMenuPaneRttiLocatorPointer : reconstructable : 86% : strong : Exact primary MainMenuPane `vftable[-1]` COL pointer; live IDA bytes show `0x0061d260 -> 0x0064a078`, `entity_query` names the target `??_R4MainMenuPane@@6B@`, `xrefs_to 0x0064a078` reports the sole data xref from this cell, and owner/emitter route through [UID:00007O][MainMenuPane](by-class/MainMenuPane.md).
```

### Supervisor application status

Supervisor applied and validated the `by-memory/-coverage-report.md` rows for this batch. The top-level [UID:0001Z5] row and the existing [UID:0002CM], [UID:0002CN], and [UID:0002CO] child rows under [UID:0000WI][0x0041a670-0x0041b69f.FileDownloaderDispatch](../../../../by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md) are no longer pending.

- Changed docs: [UID:0002CM][0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor](../../../../by-memory/0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor.md), [UID:0002CN][0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor](../../../../by-memory/0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor.md), [UID:0002CO][0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor](../../../../by-memory/0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor.md), [UID:0001Z5][0x00401000-0x0060d000.MasterCodeTextSection](../../../../by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md), validator-owned generated files, and this notes file.
- Score changes: [UID:0002CM] `84/88 -> 85/90`; [UID:0002CN] `80/88 -> 85/90`; [UID:0002CO] `84/88 -> 85/90`; [UID:0001Z5] `80/89 -> 81/89`.
- Owner/emitter decisions: routes remain unchanged. [UID:0002CM] routes through [UID:00001H][CashShopRequest](../../../../by-class/CashShopRequest.md), [UID:0002CN] routes through [UID:00001I][CashShopVersionRequest](../../../../by-class/CashShopVersionRequest.md), and [UID:0002CO] routes through [UID:0000JC][FileDownloader](../../../../by-file/FileDownloader.md). Final C++ stays blank on all three because the observed bodies are compiler scalar deleting wrappers and should be regenerated from source destructor declarations.
- Evidence summary: live IDA MCP session `a003_objectlist_dispatch_20260615` reported active `NexusTK.exe`, image base `0x00400000`, Hex-Rays ready, and strings cache ready. `lookup_funcs`, `decompile`, `analyze_function`, `callees`, `xrefs_to`, `entity_query`, and `get_bytes` reconfirmed exact wrapper bounds, vtable-only function xrefs, vtable-cell refs, decompiled behavior, callee sets, `0x0067a738` singleton writes/uses, `.rdata` vtable sequence bytes, and neighboring `0xcc` padding for the CashShopRequest/CashShopVersionRequest/FileDownloader scalar deleting destructor cluster.
- IDA DB changes: none. Skipped candidates: no IDA names, comments, prototypes, type/member edits, vtable edits, function definitions, or IDB save were applied because current evidence supports documentation/routing scores but final helper names, request payload layout, Thread cleanup names, and singleton type/name remain below C-agent DB mutation threshold.
- Validation: scoped validator loop `python .\tools\validator.py --mode file --file <target> --apply --lock-timeout 60` exited `0` for [UID:0002CM], [UID:0002CN], [UID:0002CO], and [UID:0001Z5]; each run reached `ok: 1`. Supervisor validation of the shared coverage report also returned `ok: 1`.

Applied exact rows retained for audit:

```text
- [UID:0001Z5][0x00401000-0x0060d000.MasterCodeTextSection](by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md) 0x00401000-0x0060d000 | section-container | MasterCodeTextSection : ignored : 81% : strong : IDA `.text` executable segment container, not a standalone source object; current report has 1781 immediate children, 817 nested children, no immediate/nested unknown rows, current endpoint/name inventory, and C001 2026-06-15 child follow-ups raising JsonCpp number-token helper, WideApi dispatch initializer, zlib source-provenance family, libjpeg static-library child pages, fitting-room progress/action helpers, and CashShop/FileDownloader scalar deleting destructor wrappers while other broad child/source-neighborhood audits remain below final quality.
        - [UID:0002CM][0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor](by-memory/0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor.md) 0x0041b570-0x0041b5db | scalar deleting destructor | CashShopRequestScalarDeletingDestructor : reconstructable : 85% : strong : Physical child of the mixed [UID:0000WI][0x0041a670-0x0041b69f.FileDownloaderDispatch](by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md) inventory but direct owner/emitter child of [UID:00001H][CashShopRequest](by-class/CashShopRequest.md); C001 live IDA refresh reconfirmed exact `0x6b` bounds, data-only vtable reachability from `0x0060d7a0`, no direct code callers, constructor/destructor/payload vtable-cell refs, `sub_5C7526` and invalid-parameter callees, MSVC string cleanup/reset behavior, and the padding boundary before [UID:0002CN][0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor](by-memory/0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor.md).
        - [UID:0002CN][0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor](by-memory/0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor.md) 0x0041b5e0-0x0041b604 | scalar deleting destructor | CashShopVersionRequestScalarDeletingDestructor : reconstructable : 85% : strong : Tiny CashShopVersionRequest scalar deleting wrapper; C001 live IDA refresh reconfirmed exact `0x24` bounds, vtable-only reachability from `0x0060d798`, payload-setup/destructor vtable-cell xrefs, sole `sub_5C7526` delete-helper callee, empty-source-destructor semantics, `.rdata` vtable sequence bytes, and padding before/after the wrapper, with owner/emitter route through [UID:00001I][CashShopVersionRequest](by-class/CashShopVersionRequest.md).
        - [UID:0002CO][0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor](by-memory/0x0041b610-0x0041b69f.FileDownloaderScalarDeletingDestructor.md) 0x0041b610-0x0041b69f | scalar deleting destructor | FileDownloaderScalarDeletingDestructor : reconstructable : 85% : strong : FileDownloader scalar deleting wrapper; C001 live IDA refresh reconfirmed exact `0x8f` bounds, no direct code callers, vtable-only reachability from `0x0060d7a8`, constructor/destructor sibling refs, singleton clear at `0x0067a738`, stop/cleanup/delete callees, scalar/vector delete flag behavior, and padding boundaries around the wrapper, with owner/emitter route through [UID:0000JC][FileDownloader](by-file/FileDownloader.md).
```

## 2026-06-15 Agent-C001 Goal 2 Section Container Follow-up C001-goal2-section-container-followup-20260615-1 FileDownloader Constructor/Dispatcher Slice

### Supervisor application status

Supervisor applied and validated the `by-memory/-coverage-report.md` rows for this batch. The top-level [UID:0001Z5] row and the existing [UID:0002TP], [UID:0002TQ], and [UID:0002TU] child rows under [UID:0000WI][0x0041a670-0x0041b69f.FileDownloaderDispatch](../../../../by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md) are no longer pending.

- Changed docs: [UID:0002TP][0x0041a670-0x0041a6e5.FileDownloaderConstructor](../../../../by-memory/0x0041a670-0x0041a6e5.FileDownloaderConstructor.md), [UID:0002TQ][0x0041a6f0-0x0041a741.FileDownloaderDestructor](../../../../by-memory/0x0041a6f0-0x0041a741.FileDownloaderDestructor.md), [UID:0002TU][0x0041b110-0x0041b180.FileDownloaderOnMessage](../../../../by-memory/0x0041b110-0x0041b180.FileDownloaderOnMessage.md), [UID:0001Z5][0x00401000-0x0060d000.MasterCodeTextSection](../../../../by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md), validator-owned generated files, and this notes file.
- Score changes: [UID:0002TP] `82/88 -> 85/90`; [UID:0002TQ] `82/88 -> 85/90`; [UID:0002TU] `82/86 -> 85/89`; [UID:0001Z5] `81/89 -> 82/89`. [UID:0001Z7] was not edited in this slice and remains at the last accepted `80/90`.
- Owner/emitter decisions: routes remain unchanged through [UID:0000JC][FileDownloader](../../../../by-file/FileDownloader.md). Final C++ stays blank because Thread helper names, singleton type/name, and Thread message parameter names remain provisional.
- Evidence summary: live IDA MCP session `a003_objectlist_dispatch_20260615` reported active `NexusTK.exe`, image base `0x00400000`, Hex-Rays ready, and strings cache ready. `lookup_funcs`, `decompile`, `analyze_function`, `xrefs_to`, `callees`, and `get_bytes` reconfirmed exact constructor/destructor/dispatcher bounds, the constructor caller at `0x00464767`, FileDownloader vtable refs at `0x0060d7a8`/`0x0060d7d4`, singleton lifetime refs at `0x0067a738`, worker start/stop/base cleanup calls, message cases `10000`/`10001`/`10002`, default Thread fallback through `sub_596920`, and padding/successor boundaries.
- IDA DB changes: none. Skipped candidates: no IDA names, comments, prototypes, type/member edits, vtable edits, function definitions, or IDB save were applied because current evidence supports documentation/routing scores but not final helper names, message payload types, or singleton type/name.
- Validation: scoped validator loop `python .\tools\validator.py --mode file --file <target> --apply --lock-timeout 60` exited `0` for [UID:0002TP], [UID:0002TQ], [UID:0002TU], and [UID:0001Z5]; each run reached `ok: 1`. Supervisor validation of the shared coverage report also returned `ok: 1`.

Applied exact rows retained for audit:

```text
- [UID:0001Z5][0x00401000-0x0060d000.MasterCodeTextSection](by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md) 0x00401000-0x0060d000 | section-container | MasterCodeTextSection : ignored : 82% : strong : IDA `.text` executable segment container, not a standalone source object; current report has 1781 immediate children, 817 nested children, no immediate/nested unknown rows, current endpoint/name inventory, and C001 2026-06-15 child follow-ups raising JsonCpp number-token helper, WideApi dispatch initializer, zlib source-provenance family, libjpeg static-library child pages, fitting-room progress/action helpers, CashShop/FileDownloader scalar deleting destructor wrappers, and FileDownloader constructor/destructor/message dispatcher pages while other broad child/source-neighborhood audits remain below final quality.
        - [UID:0002TP][0x0041a670-0x0041a6e5.FileDownloaderConstructor](by-memory/0x0041a670-0x0041a6e5.FileDownloaderConstructor.md) 0x0041a670-0x0041a6e5 | constructor | FileDownloaderConstructor : reconstructable : 85% : strong : C001 live IDA refresh reconfirmed exact `0x75` constructor bounds, the single startup caller at `0x00464767`, base `Thread(5)` construction through `sub_596250`, `dword_67A738` normal/unwind writes, FileDownloader vtable install at `0x0060d7a8`, worker launch through `sub_5965E0`, sibling constructor/destructor/scalar-destructor vtable refs, singleton lifetime refs, padding before [UID:0002TQ][0x0041a6f0-0x0041a741.FileDownloaderDestructor](by-memory/0x0041a6f0-0x0041a741.FileDownloaderDestructor.md), and owner/emitter route through [UID:0000JC][FileDownloader](by-file/FileDownloader.md).
        - [UID:0002TQ][0x0041a6f0-0x0041a741.FileDownloaderDestructor](by-memory/0x0041a6f0-0x0041a741.FileDownloaderDestructor.md) 0x0041a6f0-0x0041a741 | destructor | FileDownloaderDestructor : reconstructable : 85% : strong : C001 live IDA refresh reconfirmed exact `0x51` destructor bounds, no direct code callers, FileDownloader vtable restore at `0x0060d7a8`, worker stop through `sub_596540`, `dword_67A738` clear, base-thread cleanup through `sub_596400`, constructor/scalar-destructor vtable sibling refs, singleton lifetime refs, padding before [UID:0002TR][0x0041a750-0x0041a9fe.DownloadMinimapFile](by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md), and owner/emitter route through [UID:0000JC][FileDownloader](by-file/FileDownloader.md).
        - [UID:0002TU][0x0041b110-0x0041b180.FileDownloaderOnMessage](by-memory/0x0041b110-0x0041b180.FileDownloaderOnMessage.md) 0x0041b110-0x0041b180 | virtual message dispatcher | FileDownloaderOnMessage : reconstructable : 85% : strong : C001 live IDA refresh reconfirmed exact `0x70` dispatcher bounds, FileDownloader vtable data xref from `0x0060d7d4`, message cases `10000`/`10001`/`10002`, minimap/catalog/version helper calls, minimap raw-payload free, version virtual destroy with flag `1`, default Thread fallback through `sub_596920`, `retn 0x0c` boundary before [UID:0002CJ][0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest](by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md), owner/emitter route through [UID:0000JC][FileDownloader](by-file/FileDownloader.md), and a documented confidence caveat that Hex-Rays prints `__stdcall` because the implicit `this` register is unused.
```

## 2026-06-15 Agent-C001 Goal 2 Section Container Follow-up C001-goal2-section-container-followup-20260615-1 FileDownloader Submit-Helper Slice

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows

Placement context: replace the top-level [UID:0001Z5] row. Under [UID:0001Z5], replace the existing [UID:0000WI] aggregate row in place. Under [UID:0000WI][0x0041a670-0x0041b69f.FileDownloaderDispatch](../../../../by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md), replace the existing [UID:0002CJ], [UID:0002CK], and [UID:0002CL] child rows in place.

- Changed docs: [UID:0002CJ][0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest](../../../../by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md), [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](../../../../by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md), [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](../../../../by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md), [UID:0000WI][0x0041a670-0x0041b69f.FileDownloaderDispatch](../../../../by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md), [UID:0001Z5][0x00401000-0x0060d000.MasterCodeTextSection](../../../../by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md), validator-owned generated files, and this notes file.
- Score changes: [UID:0002CJ] `82/86 -> 85/90`; [UID:0002CK] `82/86 -> 85/90`; [UID:0002CL] `82/86 -> 85/90`; [UID:0000WI] stays `88/90`; [UID:0001Z5] `82/89 -> 83/89`. [UID:0001Z7] was not edited in this slice and remains at the last accepted `80/90`.
- Owner/emitter decisions: [UID:0002CJ], [UID:0002CK], and [UID:0002CL] keep owner/emitter route through [UID:0000JC][FileDownloader](../../../../by-file/FileDownloader.md). [UID:0000WI] remains a non-emitting mixed inventory with `CANONICAL_OWNER:NONE`, blank emitters, and `RECONSTRUCTABLE:FALSE`. [UID:0001Z5] remains a non-emitting section container. Final C++ stays blank on the submit-helper pages because source-facing helper names, payload type names, and request-factory placement remain provisional.
- Evidence summary: live IDA MCP session `a003_objectlist_dispatch_20260615` reported active `NexusTK.exe.i64`, image base `0x00400000`, Hex-Rays ready, and strings cache ready. `lookup_funcs`, `decompile`, `analyze_function`, `xrefs_to`, `callees`, `get_bytes`, and caller disassembly reconfirmed exact helper bounds, payload initialization, `sub_596960` queue dispatch for messages `10000`, `10001`, and `10002`, the `dword_67A738` receiver at callsites `0x00451d18`, `0x0041cd0f`, and `0x0041c21b`, `dword_67A73C + 0x7a8` fitting-room handoff for catalog requests, null-allocation fallback for version requests, singleton xref sets, and neighboring padding.
- IDA DB changes: none. Skipped candidates: no IDA names, comments, prototypes, type/member edits, vtable edits, function definitions, or IDB save were applied because current evidence supports documentation/routing scores but not final helper names, payload type names, or source placement.
- Validation: scoped validator loop `python .\tools\validator.py --mode file --file <target> --apply --lock-timeout 60` exited `0` for [UID:0002CJ], [UID:0002CK], [UID:0002CL], [UID:0000WI], and [UID:0001Z5]; each run reached `ok: 1`.
- Supervisor application: applied exact rows to `by-memory/-coverage-report.md` on 2026-06-15; validation command `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1` returned `ok: 1`. No FileDownloader submit-helper supervisor-owned rows remain pending.

Supervisor-applied exact rows retained for audit:

```text
- [UID:0001Z5][0x00401000-0x0060d000.MasterCodeTextSection](by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md) 0x00401000-0x0060d000 | section-container | MasterCodeTextSection : ignored : 83% : strong : IDA `.text` executable segment container, not a standalone source object; current report has 1781 immediate children, 817 nested children, no immediate/nested unknown rows, current endpoint/name inventory, and C001 2026-06-15 child follow-ups raising JsonCpp number-token helper, WideApi dispatch initializer, zlib source-provenance family, libjpeg static-library child pages, fitting-room progress/action helpers, CashShop/FileDownloader scalar deleting destructor wrappers, FileDownloader constructor/destructor/message dispatcher pages, and FileDownloader submit-helper pages while other broad child/source-neighborhood audits remain below final quality.
    - [UID:0000WI][0x0041a670-0x0041b69f.FileDownloaderDispatch](by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md) 0x0041a670-0x0041b69f | aggregate | FileDownloaderDispatchAndSupportInventory : ignored : 88% : strong : Reviewed non-emitting mixed address inventory for FileDownloader dispatch plus adjacent Thread-wrapper, MSVC string-support, JsonCpp reader destructor, and CashShop request destructor spans; exact children carry source/runtime ownership, and C001 live IDA refreshed the submit-helper trio to gate-valid FileDownloader routes while preserving final source-name/type caveats.
            - [UID:0002CJ][0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest](by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md) 0x0041b180-0x0041b1f5 | downloader submit helper | FileDownloaderSubmitMinimapRequest : reconstructable : 85% : strong : C001 live IDA refresh reconfirmed exact `0x75` bounds, sole caller `sub_451C90` at `0x00451d18`, caller route `dword_67A738` in `ecx`, allocation of a `0x238` payload, zeroed state dwords, integer storage at `+0x0c`, `_wcscpy_s` copies to `(payload + 0x218, 0x10)` and `(payload + 0x10, 0x104)`, queue post `sub_596960(this, 10000, payload, 0)`, singleton xref set, padding before [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md), and owner/emitter route through [UID:0000JC][FileDownloader](by-file/FileDownloader.md).
            - [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md) 0x0041b200-0x0041b26d | downloader submit helper | FileDownloaderSubmitCashShopCatalogRequest : reconstructable : 85% : strong : C001 live IDA refresh reconfirmed exact `0x6d` bounds, sole caller [UID:0002CT][0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction](by-memory/0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction.md) at `0x0041cd0f`, caller route `dword_67A738` in `ecx`, allocation of a `0x28` `CashShopRequest` payload, vtable and small-string field initialization, queue post `sub_596960(this, 10001, payload, 0)`, optional fitting-room handoff at `dword_67A73C + 0x7a8`, fitting-room singleton xrefs, padding before [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md), and owner/emitter route through [UID:0000JC][FileDownloader](by-file/FileDownloader.md).
            - [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md) 0x0041b270-0x0041b2c9 | downloader submit helper | FileDownloaderSubmitCashShopVersionRequest : reconstructable : 85% : strong : C001 live IDA refresh reconfirmed exact `0x59` bounds, sole caller [UID:0002CP][0x0041bdd0-0x0041c250.FittingRoomDialogConstructor](by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md) at `0x0041c21b`, caller route `dword_67A738` in `ecx`, allocation of a `0x10` `CashShopVersionRequest` payload, vtable and state initialization, normal queue post `sub_596960(this, 10002, payload, 0)`, null-allocation fallback `sub_596960(this, 10002, 0, 0)`, singleton xref set, padding before [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md), and owner/emitter route through [UID:0000JC][FileDownloader](by-file/FileDownloader.md).
```

Latest C001 continuation note: the clan raw-constructor slice for `C001-goal2-section-container-followup-20260615-1` is recorded above under `## 2026-06-15 Agent-C001 Goal 2 Section Container Follow-up C001-goal2-section-container-followup-20260615-1 Clan Raw-Constructor Slice`, including before/after scores, IDA DB changes, skipped candidates, validation, and exact pending `by-memory/-coverage-report.md` rows.

## 2026-06-15 Agent-C001 Goal 2 NewOptionPane Low-Confidence Slice C001-goal2-newoptionpane-lowconfidence-20260615-20

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows retained for audit

Placement context: under [UID:0001DW][0x0053ff90-0x00541b2b.NewOptionPane](../../../../by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md), inside [UID:0001DX][0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers](../../../../by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md), replace the existing [UID:0003NP], [UID:0003NQ], and [UID:0003NR] child rows in place after [UID:0003NO] and before [UID:0003NS]. Do not change the [UID:0001DX] aggregate row in this supervisor application.

- Changed docs: [UID:0003NP][0x00540ef0-0x00540f4d.NewOptionPaneVisibleOptionHitTest](../../../../by-memory/0x00540ef0-0x00540f4d.NewOptionPaneVisibleOptionHitTest.md), [UID:0003NQ][0x00540f50-0x00540fdf.NewOptionPaneApplyServerOptions](../../../../by-memory/0x00540f50-0x00540fdf.NewOptionPaneApplyServerOptions.md), [UID:0003NR][0x00540ff0-0x0054103a.NewOptionPaneRefreshVolumeDisplay](../../../../by-memory/0x00540ff0-0x0054103a.NewOptionPaneRefreshVolumeDisplay.md), support pages [UID:0001DX], [UID:0001DW], [UID:000097][NewOptionPane](../../../../by-class/NewOptionPane.md), [UID:0000M7][OptionPane](../../../../by-file/OptionPane.md), validator-owned `project-level/-auto-completion-stats.md`, validator-owned generated metadata, and this notes file.
- Score changes: [UID:0003NP] `82/84 -> 85/88`; [UID:0003NQ] `82/84 -> 86/89`; [UID:0003NR] `82/84 -> 85/88`. Support pages kept existing scores.
- Owner/emitter decisions: target owner/emitter routes remain [UID:000097][NewOptionPane](../../../../by-class/NewOptionPane.md). [UID:0001DX] remains a non-emitting [UID:0000M7][OptionPane](../../../../by-file/OptionPane.md) container. Final C++ stays blank for all three targets because caller routes, source-visible helper names, option-entry field names, packet/config field names, and exact sound/music ordering remain below source-quality.
- Evidence summary: Wave2 has no records for [UID:0003NP] or [UID:0003NR]; [UID:0003NQ] has effective `ApplyServerOptions`, total grade `98.5`, no callers, and callees `0x00575470`/`0x005403b0`, while its prose summary conflicts with the code and was treated as stale. Live IDA MCP confirmed the target instruction ranges, no inbound xrefs, no raw VA pointer hits, `OnMouseClick` inline hit-test equivalent, `SetOptionEntry` option-entry offsets, `ApplyVolumeSettings` inverse volume/config path, and the `0x00541040` config-cluster relationship.
- IDA DB changes: defined neutral IDA function records `sub_540EF0` (`0x00540ef0-0x00540f50`, size `0x60`), `sub_540F50` (`0x00540f50-0x00540fe2`, size `0x92`), and `sub_540FF0` (`0x00540ff0-0x0054103b`, size `0x4b`); added short start comments to each; saved `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64` successfully. Skipped candidates: no source-like function renames, prototypes, local names, struct member names, config field names, or type changes were applied; `0x00540ea0` function creation was skipped because it was outside the target set and its page was already stronger than this low-confidence slice.
- Validation: scoped validator loop `python .\tools\validator.py --mode file --file <target> --apply --lock-timeout 60` exited `0` for [UID:0003NP], [UID:0003NQ], [UID:0003NR], [UID:0001DX], [UID:0001DW], [UID:000097], and [UID:0000M7]; each run reached `ok: 1`. The first target validation removed [UID:0003NP] from `Low_Confidence`, `Low_Both`, and the by-memory low list; subsequent target validations removed [UID:0003NQ] and [UID:0003NR] from those generated low-score lists as well.
- Shared-row status: supervisor applied and validated the three replacement rows below on 2026-06-15 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No C001 NewOptionPane supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

Supervisor-applied exact rows:

```text
        - [UID:0003NP][0x00540ef0-0x00540f4d.NewOptionPaneVisibleOptionHitTest](by-memory/0x00540ef0-0x00540f4d.NewOptionPaneVisibleOptionHitTest.md) 0x00540ef0-0x00540f4d | class helper | NewOptionPaneVisibleOptionHitTest : reconstructable : 85% : strong : C001-promoted IDA function `sub_540EF0` over `NewOptionPane` state; live IDA confirms the `0x1b` entry loop, stride `0x98`, active-page/`0xff` visibility filter, rectangle offset `+0x17c`, `0x004b7e80` hit-test call, hit-index/`-1` returns, no inbound xrefs or raw pointer hits, and unresolved source-visible helper/argument names.
        - [UID:0003NQ][0x00540f50-0x00540fdf.NewOptionPaneApplyServerOptions](by-memory/0x00540f50-0x00540fdf.NewOptionPaneApplyServerOptions.md) 0x00540f50-0x00540fdf | class helper | NewOptionPaneApplyServerOptions : reconstructable : 86% : strong : C001-promoted IDA function `sub_540F50`; Wave2 effective `ApplyServerOptions` record plus live IDA confirm five server payload byte stores to config offsets `0x28de73`, `0x28de72`, `0x28de70`, `0x28de75`, and `0x28de48`, followed by `0x005403b0` refresh and pane invalidation, with no inbound xrefs/raw pointer hits and provisional packet/config field names.
        - [UID:0003NR][0x00540ff0-0x0054103a.NewOptionPaneRefreshVolumeDisplay](by-memory/0x00540ff0-0x0054103a.NewOptionPaneRefreshVolumeDisplay.md) 0x00540ff0-0x0054103a | class helper | NewOptionPaneRefreshVolumeDisplay : reconstructable : 85% : strong : C001-promoted IDA function `sub_540FF0`; live IDA confirms config reads at `0x28de54`/`0x28de4c`, divide-by-five display derivation, stores to `this+0x12bc/+0x12c0`, `0x005403b0` refresh/inverse scaled-write relationship, pane invalidation, and no inbound xrefs/raw pointer hits while final volume/config field names and sound/music ordering remain unresolved.
```

## 2026-06-15 Agent-C001 Goal 2 ScrollVolumePane Low-Confidence Slice C001-goal2-scrollvolume-lowconfidence-20260615-21

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows retained for audit

Placement context: under [UID:0001H2][0x00564710-0x005654ec.ScrollVolumePane](../../../../by-memory/0x00564710-0x005654ec.ScrollVolumePane.md), replace the existing [UID:0001H3], [UID:0002LB], [UID:0002LC], and [UID:0002LD] child rows in place. Keep the existing sibling ordering: [UID:0001H3], [UID:0002LB], and [UID:0002LC] remain after [UID:00031O] and before [UID:0001H4]; [UID:0002LD] remains after [UID:0001H5] and before [UID:0001H6]. Do not edit `by-memory/-coverage-report.md` directly.

- Changed docs: [UID:0001H3][0x00564e30-0x00565006.ScrollVolumePaneHitTestPart](../../../../by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md), [UID:0002LB][0x00565170-0x005651e0.ScrollVolumePaneSetHighlightPartRaw](../../../../by-memory/0x00565170-0x005651e0.ScrollVolumePaneSetHighlightPartRaw.md), [UID:0002LC][0x005651e0-0x005652a0.ScrollVolumePaneBeginInteractionRaw](../../../../by-memory/0x005651e0-0x005652a0.ScrollVolumePaneBeginInteractionRaw.md), [UID:0002LD][0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw](../../../../by-memory/0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw.md), validator-owned `project-level/-auto-completion-stats.md`, validator-owned `tools/validator.ini`, and this notes file.
- Score changes: [UID:0001H3] `82/84 -> 85/86`; [UID:0002LB] `82/84 -> 85/85`; [UID:0002LC] `82/84 -> 85/85`; [UID:0002LD] `82/84 -> 85/85`.
- Evidence summary: Wave2 status/missing-ref checks showed no missing targets blocking this slice. Wave2 `method`/`xrefs` reconfirmed [UID:0001H3] as IDA `sub_564E30`, size `0x1d6`, with callers `0x005649f1` and `0x0056530f` and the known helper/cookie callees. Wave2 `method` confirms [UID:0002LB] as effective `ScrollVolumePane::SetHighlightPart(char)` and [UID:0002LD] as effective `ScrollVolumePane::ResetInteractionState()`, both high-grade included bodies but IDA-null at their raw starts. [UID:0002LC] still has stale Wave2 `TextEditPane`/`DrawScrollbarPartF` labels, which remain rejected; its body/callee set matches ScrollVolumePane begin-interaction behavior. Wave2 instruction-level IDA xrefs inside the raw spans tie `0x0056519c`/`0x005651b8`, `0x00565211`/`0x00565229`/`0x00565248`, and `0x005654c6` to `GetPartRect`; `0x00565272` to the commit helper; `0x00565262` to the point helper; `0x00565288` to high-grade `ScheduleTimer`; and `0x005654a9` to high-grade `InterfaceEfx::RemoveFromUpdateScheduler`.
- Blocker handling: the hit-test helper's function boundary and caller provenance are resolved; it remains below final C++ readiness only for source-quality part/helper/field names. The three raw helpers remain at the minimum gate because `xrefs` at raw starts `0x00565170`, `0x005651e0`, and `0x00565490` still show no incoming callers or IDA function object, so function creation and source-like names/prototypes remain unsafe. Timer/helper roles are now documented from high-grade Wave2 methods, but final source prototypes for the `this+0xa4` view calls remain unresolved.
- IDA DB changes: none. Skipped candidates: no IDA function creation, names, comments, prototypes, locals, struct members, vtable edits, or IDB save were applied. Current evidence supports documentation-score promotion and exact outgoing-edge notes but not raw function-start repair or source-like signatures.
- Validation: scoped validator loop `python .\tools\validator.py --mode file --file <target> --apply --lock-timeout 60` exited `0` for [UID:0001H3], [UID:0002LB], [UID:0002LC], and [UID:0002LD]; each run reached `ok: 1`. The first target run removed [UID:0001H3] from `Low_Confidence`, `Low_Both`, and the by-memory low list; subsequent runs removed [UID:0002LB], [UID:0002LC], and [UID:0002LD] from those generated low-score lists. A post-validation `rg` found no target UID entries in `project-level/-auto-completion-stats.md`.
- Shared-row status: supervisor applied and validated the four replacement rows below on 2026-06-15 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No C001 ScrollVolume supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

Supervisor-applied exact rows:

```text
        - [UID:0001H3][0x00564e30-0x00565006.ScrollVolumePaneHitTestPart](by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md) 0x00564e30-0x00565006 | method | ScrollVolumePaneHitTestPart : reconstructable : 85% : strong : C001 Wave2 refresh reconfirmed IDA `sub_564E30` size `0x1d6`, callers `0x005649f1`/`0x0056530f`, callee set `0x004a9090`/`0x005447c0`/`0x004b7c50`/`0x004b7e80`, five-part map `0..4` plus `0xff` sentinel, ScrollVolumePane tail-field structure, parent aggregate attachment, stale TextEditPane generated-signature caveat, and final C++ remains blank pending source-quality part/field/helper names.
        - [UID:0002LB][0x00565170-0x005651e0.ScrollVolumePaneSetHighlightPartRaw](by-memory/0x00565170-0x005651e0.ScrollVolumePaneSetHighlightPartRaw.md) 0x00565170-0x005651e0 | raw method-shaped helper | ScrollVolumePaneSetHighlightPartRaw : reconstructable : 85% : strong : C001 Wave2 refresh confirms effective `ScrollVolumePane::SetHighlightPart(char)` export and body; IDA instruction-level xrefs from `0x0056519c`/`0x005651b8` to `GetPartRect` prove outgoing edges, while raw-start function creation/incoming caller provenance remain unresolved with `xrefs 0x00565170` still callerless/IDA-null; final C++ stays blank pending raw call sites and source-quality names.
        - [UID:0002LC][0x005651e0-0x005652a0.ScrollVolumePaneBeginInteractionRaw](by-memory/0x005651e0-0x005652a0.ScrollVolumePaneBeginInteractionRaw.md) 0x005651e0-0x005652a0 | raw method-shaped helper | ScrollVolumePaneBeginInteractionRaw : reconstructable : 85% : strong : C001 rejected stale Wave2 `TextEditPane`/`DrawScrollbarPartF` labels but confirmed the raw body/callee set; IDA instruction-level xrefs inside the span reach `GetPartRect` at `0x00565211`/`0x00565229`/`0x00565248`, point helper `0x00565262`, commit `0x00565272`, and high-grade `ScheduleTimer` `0x00565288`; incoming raw-start caller/function status remain unresolved, so final C++ stays blank.
        - [UID:0002LD][0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw](by-memory/0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw.md) 0x00565490-0x005654ec | raw method-shaped helper | ScrollVolumePaneResetInteractionStateRaw : reconstructable : 85% : strong : C001 Wave2 refresh confirms effective `ScrollVolumePane::ResetInteractionState()` export and body; IDA instruction-level xrefs inside the span reach high-grade `RemoveFromUpdateScheduler` at `0x005654a9` and `GetPartRect` at `0x005654c6`, with exact boundary before `0x005654ec` ScrollablePane thunk retained; incoming raw-start caller/function status remain unresolved, so final C++ stays blank.
```

## 2026-06-15 Agent-C001 Goal 2 Section Container Follow-up C001-goal2-section-container-followup-20260615-1 MidiPlayer RData Slice

Placement context: replace the top-level [UID:0001Z7] row. Replace stale [UID:00025T] in place under `.rdata`. Under [UID:00025V][0x0061fa3c-0x0061fafc.MessageShowReadOnlyData](../../../../by-memory/0x0061fa3c-0x0061fafc.MessageShowReadOnlyData.md), replace existing [UID:0003PF] in place. Replace sibling [UID:00025W] immediately after [UID:00025V]/[UID:0003PF] and before [UID:00025X]. Do not edit `by-memory/-coverage-report.md` directly.

- Changed docs: [UID:00008A][MidiPlayer](../../../../by-class/MidiPlayer.md), [UID:0003PF][0x0061faf8-0x0061fafc.MidiPlayerRttiLocatorPointer](../../../../by-memory/0x0061faf8-0x0061fafc.MidiPlayerRttiLocatorPointer.md), [UID:00025W][0x0061fafc-0x0061fb74.MidiPlayerReadOnlyData](../../../../by-memory/0x0061fafc-0x0061fb74.MidiPlayerReadOnlyData.md), [UID:0001Z7][0x0060d670-0x0066d000.ReadOnlyDataSection](../../../../by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md), [by-class/-coverage-report.md](../../../../by-class/-coverage-report.md), validator-owned generated files, and this notes file.
- Score changes: [UID:00008A] `82/88 -> 85/89`; [UID:0003PF] `84/90 -> 86/91`; [UID:00025W] `82/88 -> 85/90`; [UID:0001Z7] `83/90 -> 84/90`. [UID:0001Z5] was already gate-valid at `85/89` and was not edited in this slice.
- Owner/emitter decisions: [UID:0003PF] now uses canonical owner/emitter [UID:00008A][MidiPlayer](../../../../by-class/MidiPlayer.md) because it is the exact primary `vftable[-1]` COL cell and the class owner now clears the gate. [UID:00025W] remains owner/emitter [UID:0000LD][MidiPlayer](../../../../by-file/MidiPlayer.md) because the span mixes the MidiPlayer vtable with adjacent UTF-16 literal/padding inventory. [UID:0001Z7] remains a non-emitting section container with `CANONICAL_OWNER:NONE`, blank emitters, and `RECONSTRUCTABLE:FALSE`; no section-level source file or final C++ was forced.
- Evidence summary: fresh live IDA MCP session `c001_midiplayer_rdata_20260615` opened `NexusTK.exe.i64`, image base `0x00400000`, Hex-Rays ready, and strings cache ready. `entity_query`, `xrefs_to`, `lookup_funcs`, `analyze_component`, `disasm`, and `get_bytes` reconfirmed `0x0061faf8 -> ??_R4MidiPlayer@@6B@` (`0x0064c344`), successor `0x0061fafc` `??_7MidiPlayer@@6B@`, constructor/destructor/scalar-deleting vtable refs at `0x00525e10`/`0x00525ed5`/`0x005265a5`, method cluster `0x00525dc0-0x00526580`, UTF-16 bytes for `Wait For Buffer Return`, `Midi\\%s`, and `%d.mid`, interior string-cluster refs at `0x0052619c -> 0x0061fb38` and `0x005261f0 -> 0x0061fb48`, no direct xrefs to `0x0061fb0c`/`0x0061fb4c`, and successor `0x0061fb74` `??_7MiscWorkThread@@6B@`.
- Additional research: stale shared-report row [UID:00025T][MemoryMenuReadOnlyData](../../../../by-memory/0x0061eb08-0x0061ec10.MemoryMenuReadOnlyData.md) was checked against its page; the page is already `COMPLETION:85`, `CONFIDENCE:92`, `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitters, so the pending supervisor row below updates the shared report without direct C001 edit. [UID:0001Z7] did not clear 85 because real remaining `.rdata` aggregate/child audits still include broad mixed vtable/string/type regions and unresolved owner/source-placement rows beyond this MidiPlayer slice; the section container itself must remain non-emitting.
- IDA DB changes: none. Skipped candidates: no IDA names, comments, prototypes, type/member edits, vtable edits, or IDB save were applied because current labels already capture the documented evidence, while source-facing helper/global names and final class/file-scope placement for literal clusters remain unresolved.
- Validation: scoped validator loop `python .\tools\validator.py --mode file --file <target> --apply --lock-timeout 60` exited `0` with `ok: 1` for [UID:00008A], [UID:0003PF], [UID:00025W], and [UID:0001Z7]. `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --lock-timeout 60` exited `0` with `ok: 1`.
- Shared-row status: supervisor applied and validated the four replacement rows below on 2026-06-15 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No C001 MidiPlayer `.rdata` supervisor-owned rows remain pending.

Supervisor-applied exact replacement rows retained for audit:

```text
- [UID:0001Z7][0x0060d670-0x0066d000.ReadOnlyDataSection](by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md) 0x0060d670-0x0066d000 | section-container | ReadOnlyDataSection : ignored : 84% : strong : IDA `.rdata` section container, not a standalone source object; current report has 98 immediate children, 95+ nested children before this pending batch, no immediate unknown/uncovered rows, current endpoint/name inventory, and C001 2026-06-15 child follow-ups splitting runtime/locale tails, employee alert text, BaramApp/MainMenu boundaries, runtime-tail/zlib data, FieldMapPane/FolderSelect plus Message/MessageShow/Meta/MidiPlayer mixed `.rdata` boundary rows, and the MidiPlayer RTTI/read-only-data owner-gate refresh while other broad vtable/string/type audits remain below final quality.
    - [UID:00025T][0x0061eb08-0x0061ec10.MemoryMenuReadOnlyData](by-memory/0x0061eb08-0x0061ec10.MemoryMenuReadOnlyData.md) 0x0061eb08-0x0061ec10 | vtable/string-data | MemoryMenuReadOnlyData : ignored : 85% : strong : Non-emitting mixed `.rdata` inventory over `MemoryMan`, `MenuPane`, `MenuItem`, `StringMenuItem`, `SeparatorMenuItem`, and `MENUBACK.EPF`; exact children [UID:0003C5][0x0061eb0c-0x0061eb94.MenuPaneVtableData](by-memory/0x0061eb0c-0x0061eb94.MenuPaneVtableData.md) and [UID:00036I][0x0061eb94-0x0061ebf0.MenuItemVtableData](by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md) carry popup/menu ownership, `MemoryMan` vtable ownership remains separate, and the broad aggregate stays `RECONSTRUCTABLE:FALSE`/non-emitting because no single source owner covers the whole span.
        - [UID:0003PF][0x0061faf8-0x0061fafc.MidiPlayerRttiLocatorPointer](by-memory/0x0061faf8-0x0061fafc.MidiPlayerRttiLocatorPointer.md) 0x0061faf8-0x0061fafc | RTTI locator pointer | MidiPlayerRttiLocatorPointer : reconstructable : 86% : strong : Exact MidiPlayer primary `vftable[-1]` COL pointer; live IDA C001 refresh shows `0x0061faf8 -> ??_R4MidiPlayer@@6B@` (`0x0064c344`) with sole data xref from this cell, successor `0x0061fafc` `??_7MidiPlayer@@6B@`, constructor/destructor/scalar-deleting vtable refs at `0x00525e10`/`0x00525ed5`/`0x005265a5`, [UID:00008A][MidiPlayer](by-class/MidiPlayer.md) now gate-valid at `85/89`, and owner/emitter route through that class.
    - [UID:00025W][0x0061fafc-0x0061fb74.MidiPlayerReadOnlyData](by-memory/0x0061fafc-0x0061fb74.MidiPlayerReadOnlyData.md) 0x0061fafc-0x0061fb74 | vtable/string-data | MidiPlayerReadOnlyData : reconstructable : 85% : strong : C001 live IDA refresh reconfirmed `0x0061fafc` `??_7MidiPlayer@@6B@`, vtable refs from constructor/destructor/scalar-deleting destructor paths, raw UTF-16 bytes for `Wait For Buffer Return`, `Midi\\%s`, and `%d.mid`, track-selection string-cluster refs at `0x0052619c -> 0x0061fb38` and `0x005261f0 -> 0x0061fb48`, no direct refs to `0x0061fb0c`/`0x0061fb4c`, successor `0x0061fb74` `??_7MiscWorkThread@@6B@`, and owner/emitter route through [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md).
```

## 2026-06-15 Agent-C001 Goal 2 Section Container Follow-up C001-goal2-section-container-followup-20260615-1 MusicControl RData Slice

Placement context: replace the top-level [UID:0001Z7] row. Under [UID:0001Z7], replace existing sibling [UID:00025Y] in place immediately after [UID:00025X][0x0061fb74-0x0061fc04.WorkThreadNotificationReadOnlyData](../../../../by-memory/0x0061fb74-0x0061fc04.WorkThreadNotificationReadOnlyData.md) and its child [UID:0002GL], and immediately before [UID:00025Z][0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData](../../../../by-memory/0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData.md). Do not edit `by-memory/-coverage-report.md` directly.

- Changed docs: [UID:00025Y][0x0061fc04-0x0061fd04.MusicControlDialogReadOnlyData](../../../../by-memory/0x0061fc04-0x0061fd04.MusicControlDialogReadOnlyData.md), [UID:0001Z7][0x0060d670-0x0066d000.ReadOnlyDataSection](../../../../by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md), validator-owned generated files, and this notes file.
- Score changes: [UID:00025Y] `82/86 -> 85/90`; [UID:0001Z7] `84/90 -> 85/90`. [UID:0001Z5] was already gate-valid at `85/89` and was not edited.
- Owner/emitter decisions: [UID:00025Y] keeps owner/emitter route through [UID:00008U][MusicControlDialog](../../../../by-class/MusicControlDialog.md); the generic callback-template declarations remain cross-owned by [UID:0000JO][FunctionObjects](../../../../by-file/FunctionObjects.md), but the physical `.rdata` span is the concrete MusicControlDialog use site. [UID:0001Z7] remains `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitters, and blank final C++; the section now clears only the minimum gate and does not get a source owner.
- Evidence summary: live IDA MCP session `c001_midiplayer_rdata_20260615` reported current IDB health, Hex-Rays ready, and strings cache ready. `entity_query` found the eight names from `0x0061fc04` `??_7MusicControlDialog@@6B@` through `0x0061fd04` `??_7NewUserDialogPane2@@6B@`. `xrefs_to` reconfirmed constructor/non-deleting-destructor/scalar-deleting-destructor refs for vtables `0x0061fc04`, `0x0061fc64`, and `0x0061fc94`; `PFLOOK.PAL` refs at `0x00528f0c`/`0x005a06e0`; `DLGSCNTL.EPF` refs at `0x00528f19`/`0x00528f37`; generic callback vtable refs at `0x0052a466`/`0x0052a4a6`; and concrete MusicControlDialog folder-callback vtable ref at `0x00529842`. `get_bytes` over `0x0061fc00-0x0061fd10` decoded the preceding COL boundary, three MusicControlDialog vtable clusters, uppercase UTF-16 resource literals, callback-template vtables, and successor create-user boundary. `analyze_component` reconfirmed shared vtable globals consumed by the MusicControlDialog executable island.
- IDA DB changes: none. Skipped candidates: no IDA names, comments, prototypes, type/member edits, vtable edits, function definitions, or IDB save were applied because current labels already capture the evidence and remaining issues are source-facing field/helper names plus declaration placement, not database identity.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x0061fc04-0x0061fd04.MusicControlDialogReadOnlyData.md --apply --lock-timeout 60` exited `0` with `ok: 1`; `python .\tools\validator.py --mode file --file by-memory\0x0060d670-0x0066d000.ReadOnlyDataSection.md --apply --lock-timeout 60` exited `0` with `ok: 1`.
- Shared-row status: supervisor applied and validated the two replacement rows below on 2026-06-15 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No C001 MusicControl `.rdata` supervisor-owned rows remain pending.

Supervisor-applied exact replacement rows retained for audit:

```text
- [UID:0001Z7][0x0060d670-0x0066d000.ReadOnlyDataSection](by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md) 0x0060d670-0x0066d000 | section-container | ReadOnlyDataSection : ignored : 85% : strong : IDA `.rdata` section container, not a standalone source object; current report has 98 immediate children, 95+ nested children, no immediate unknown/uncovered rows, current endpoint/name inventory, and C001 2026-06-15 child follow-ups splitting runtime/locale tails, employee alert text, BaramApp/MainMenu boundaries, runtime-tail/zlib data, FieldMapPane/FolderSelect plus Message/MessageShow/Meta/MidiPlayer mixed `.rdata` boundary rows, the MidiPlayer RTTI/read-only-data owner-gate refresh, and the MusicControlDialog read-only-data live IDA refresh while other broad vtable/string/type audits remain below final quality.
    - [UID:00025Y][0x0061fc04-0x0061fd04.MusicControlDialogReadOnlyData](by-memory/0x0061fc04-0x0061fd04.MusicControlDialogReadOnlyData.md) 0x0061fc04-0x0061fd04 | vtable/string-data | MusicControlDialogReadOnlyData : reconstructable : 85% : strong : C001 live IDA refresh reconfirmed the three `MusicControlDialog` vtable anchors at `0x0061fc04`/`0x0061fc64`/`0x0061fc94`, constructor/destructor/scalar-deleting vtable refs, uppercase UTF-16 `PFLOOK.PAL` and `DLGSCNTL.EPF` resource literals plus xrefs, generic `FunctionObjectT<String>` vtable refs at `0x0052a466`/`0x0052a4a6`, concrete `PlainMemberFunctionObjectT<MusicControlDialog, String>` folder-callback vtable ref at `0x00529842`, preceding `MusicControlDialog` COL boundary at `0x0061fc00`, successor `NewUserDialogPane2` boundary at `0x0061fd04`, and owner/emitter route through [UID:00008U][MusicControlDialog](by-class/MusicControlDialog.md).
```

## 2026-06-16 Agent-C001 Goal 2 Low-Both Message/Power Memory C001-goal2-lowboth-message-power-memory-20260616-2

Placement context: replace the existing [UID:0001C7] row in place under the MessageShowPane child cluster, after [UID:0001C6] and before the `0x005227c6-0x005227d0` padding row. Replace the existing [UID:0001F6] row in place after the `0x00549c18-0x00549c20` padding row; replace [UID:0001F5] immediately after [UID:0001F6] and before the `0x0054a472-0x0054a480` padding row, nested under [UID:0001F6] if the supervisor normalizes physical containment. Do not edit `by-memory/-coverage-report.md` directly.

- Changed docs: [UID:0001C7][0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor](../../../../by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md), [UID:0001F5][0x00549c20-0x0054a472.PowerDialogPaneConstructor](../../../../by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md), [UID:0001F6][0x00549c20-0x0054b5d5.PowerDialogPane](../../../../by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md), validator-owned generated/project stats, and this notes file.
- Leases used: [UID:0001C7], [UID:0001F5], [UID:0001F6], and `tools/leaser/Agents/Agent-C001/notes.md`; release after validation and note update.
- Score changes: [UID:0001C7] `82/85 -> 85/90`; [UID:0001F5] `82/85 -> 85/88`; [UID:0001F6] `82/85 -> 85/88`.
- Owner/emitter decisions: [UID:0001C7] keeps owner/emitter [UID:000087][MessageShowPane](../../../../by-class/MessageShowPane.md). [UID:0001F5] reroutes from the broad by-memory aggregate [UID:0001F6] to direct class owner/emitter [UID:0000AP][PowerDialogPane](../../../../by-class/PowerDialogPane.md), which is gate-valid at `86/86` and emits through [UID:0000MO][PowerDialogPane](../../../../by-file/PowerDialogPane.md). [UID:0001F6] remains file-owned through [UID:0000MO] because it is a mixed source-module aggregate spanning `PowerDialogPane`, private `PowerListPane`, singleton helpers, destructors, ignored thunks, and padding.
- Evidence summary: live IDA MCP session `c001_midiplayer_rdata_20260615` reported `NexusTK.exe.i64`, imagebase `0x00400000`, Hex-Rays ready, and strings cache ready. `lookup_funcs`, `analyze_function`, `xrefs_to`, `disasm`, and `get_bytes` reconfirmed [UID:0001C7] exact `0xa6` destructor, three `MessageShowPane` vtable restores, cleanup calls, `g_pMessageShowPane` clear, adjustor-thunk refs, primary vtable cell, and full singleton lifecycle xrefs. For Power, the same live pass reconfirmed `0x00549c20` size `0x852`, `PowerDialogPane` vtable writes, `g_pPowerDialog` xrefs, `g_pConfig` threshold reads, packet-row/list setup, `MapPane` caller, and the second caller wrapper at `0x00513b50`.
- Blockers investigated: the Power second caller is no longer an unreviewed blocker. `analyze_function 0x00513b93` shows wrapper `0x00513b50-0x00513bab` allocates `0x2e4` / 740 bytes (Verified with int_convert.py), calls the constructor, returns `1`, and has no callers; `xrefs_to 0x00513b50` reports no inbound refs. This supports documenting a retained/factory-shaped wrapper but not a second live source route or final wrapper name. Packet-reader locals, row-record names, four config-field names, helper/control names, and final C++ shape remain real source-quality blockers.
- Split/range decisions: no target rename, split, merge, or range-boundary change was supported. [UID:0001C7] stays separate from compiler thunks [UID:0001C6] and post-function padding. [UID:0001F5] stays contained in [UID:0001F6] physically but routes semantically to the class. [UID:0001F6] stays a source-module aggregate rather than being forced to one class because it also contains `PowerListPane` and mixed helper/thunk ranges.
- IDA DB changes: none. Skipped candidates: no IDA names, comments, prototypes, type/member edits, function creation, vtable edits, or IDB save were applied. Existing IDA labels already support the documented identity, while source-facing helper/field/row names and the unreferenced wrapper's original role remain below safe database-mutation confidence.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md --apply --lock-timeout 60`, `python .\tools\validator.py --mode file --file by-memory\0x00549c20-0x0054a472.PowerDialogPaneConstructor.md --apply --lock-timeout 60`, and `python .\tools\validator.py --mode file --file by-memory\0x00549c20-0x0054b5d5.PowerDialogPane.md --apply --lock-timeout 60` all exited `0` with `ok: 1`. A post-validation `Select-String` found no `0001C7`, `0001F5`, or `0001F6` rows remaining in `project-level/-auto-completion-stats.md`.

Supervisor-applied exact `by-memory/-coverage-report.md` replacement rows:

Supervisor applied and validated these rows on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; no C001 Message/Power supervisor-owned rows remain pending.

```text
        - [UID:0001C7][0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor](by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md) 0x00522720-0x005227c6 | scalar deleting destructor | MessageShowPaneScalarDeletingDestructor : reconstructable : 85% : strong : C001 live IDA refresh reconfirmed exact `0xa6` boundary, three `MessageShowPane` vtable restores, cleanup calls `sub_544CE0`/`sub_544580`, `g_pMessageShowPane` clear at `0x0052276d`, complete singleton lifecycle xrefs, adjustor-thunk refs at `0x00522701`/`0x0052270c`, primary vtable cell `0x0061fa4c`, raw bytes, owner/emitter route through [UID:000087][MessageShowPane](by-class/MessageShowPane.md), and blank final C++ pending source-quality helper/base names plus scalar-deleting-wrapper decomposition.
    - [UID:0001F6][0x00549c20-0x0054b5d5.PowerDialogPane](by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md) 0x00549c20-0x0054b5d5 | source-module aggregate | PowerDialogPane : reconstructable : 85% : strong : C001 live IDA refresh reconfirmed the modeled child functions, constructor boundary and `PowerDialogPane` vtable writes, `g_pPowerDialog` xrefs, `g_pConfig` threshold reads, packet/list setup, `MapPane` caller, reviewed unreferenced wrapper at `0x00513b50`, no supported split/range change, direct constructor child routing through [UID:0000AP][PowerDialogPane](by-class/PowerDialogPane.md), and aggregate owner/emitter route through [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md) because the physical range spans dialog, private list, helper, thunk, and padding material.
        - [UID:0001F5][0x00549c20-0x0054a472.PowerDialogPaneConstructor](by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md) 0x00549c20-0x0054a472 | constructor/packet-initializer | PowerDialogPaneConstructor : reconstructable : 85% : strong : C001 live IDA refresh reconfirmed exact `0x852` constructor boundary, corrected generated-owner split from `PowerListPane` to direct [UID:0000AP][PowerDialogPane](by-class/PowerDialogPane.md), `Power` caption, three `PowerDialogPane` vtable writes, `MapPane` packet-case caller, reviewed unreferenced `0x00513b50` wrapper allocating `0x2e4` / 740 bytes (Verified with int_convert.py), `g_pPowerDialog` publish and xrefs, `g_pConfig` threshold reads, packet-row parsing, embedded `PowerListPane` setup, direct owner/emitter route through the gate-valid class, and blank final C++ pending packet-reader/row-record/config/helper names plus wrapper reachability.
```

## 2026-06-16 Agent-C001 Goal 2 ScrollCollection/TimerHandler Memory C001-goal2-scrollcollection-timerhandler-memory-20260616-3

Placement context: replace the existing [UID:0001GU] row in place under the `ScrollCollectionPane` executable cluster, after [UID:0001GT]/draw-helper material and before the following geometry/helper rows. Replace the existing [UID:0001K7] row in place under [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](../../../../by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md), after the constructor row and before the default callback / [UID:0001K8] wrapper row. Replace the existing [UID:0001K9] row in place after [UID:0001K8] and before the scalar deleting destructor row. Do not edit `by-memory/-coverage-report.md` directly.

- Changed docs: [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](../../../../by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md), [UID:0001K7][0x00597580-0x005975c3.TimerHandlerDestructor](../../../../by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md), [UID:0001K9][0x00597610-0x00597645.TimerHandlerWrappers](../../../../by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md), validator-owned generated/project stats, and this notes file.
- Leases used: [UID:0001GU], [UID:0001K7], [UID:0001K9], and `tools/leaser/Agents/Agent-C001/notes.md`; the first release attempt after validation/notes returned `Rejected[No active lease]` for all four paths because the short leases had already expired/purged. `notes.md` was re-leased only to record this release outcome.
- Score changes: [UID:0001GU] `82/85 -> 85/88`; [UID:0001K7] `86/84 -> 86/88`; [UID:0001K9] `86/84 -> 86/88`.
- Owner/emitter decisions: [UID:0001GU] reroutes from file owner/emitter [UID:0000NG][ScrollCollectionPane](../../../../by-file/ScrollCollectionPane.md) to direct class owner/emitter [UID:0000CG][ScrollCollectionPane](../../../../by-class/ScrollCollectionPane.md), which emits through [UID:0000NG]. [UID:0001K7] and [UID:0001K9] reroute from broad file owner/emitter [UID:0000OT][TimerMgr](../../../../by-file/TimerMgr.md) to direct class owner/emitter [UID:0000F0][TimerHandler](../../../../by-class/TimerHandler.md), which emits through [UID:0000OT].
- Evidence summary: live IDA MCP session `c001_midiplayer_rdata_20260615` reported `NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x00400000`, Hex-Rays ready, and strings cache ready. `lookup_funcs`, `xrefs_to`, `analyze_component`, `decompile`, `disasm`, and `get_bytes` reconfirmed [UID:0001GU] exact `0x31d` boundary, two caller refs (`0x00562091`, `0x0056301f`), `0x00562bf0` geometry-helper boundary and thirteen callsites, component graph through update/drag helpers, and byte fence before the next helper. For TimerHandler, the same live pass reconfirmed [UID:0001K7] exact `0x43` boundary, fifteen direct caller refs, TimerHandler vtable refs at `0x00597570`/`0x005975a2`/`0x00597675`, destructor-to-`0x00597a10` unregister edge, [UID:0001K9] two `0x16` wrappers, 47/1 wrapper caller split, `g_pTimerMgr` forwarding disassembly, `0x00597b80` match and `0x00597ca0` except predicates, and shared `0x00598290` splice-helper use.
- Blockers investigated: ScrollCollection final C++ is still blocked by unsplit exact geometry-helper page `0x00562bf0-0x00562e77`, source-quality part-id names, cursor/point helper names, and field names from `+0xf8` through `+0x108`; the broader standalone `ScrollCollectionPane.cpp` vs `ScrollBar.cpp` source split remains documented. TimerHandler final C++ is still blocked by final public method names/signatures for `0x00597a10`, `0x00597b80`, `0x00597ca0`, and wrappers, plus the final `TimerHandler.cpp` vs `TimerMgr.cpp` source split. SoundManager/EventDispatcher/generated labels were rechecked and remain rejected as ownership.
- Split/range decisions: no range rename, split, merge, or new child page was supported in this pass. [UID:0001GU] remains exact and stops before the unsplit geometry helper. [UID:0001K7] remains the non-deleting destructor separate from constructor/default callback/scalar deleting destructor. [UID:0001K9] remains the two-wrapper page covering `0x00597610-0x00597626` and `0x00597630-0x00597646`; filename end remains the existing last-byte convention while the page documents modeled exclusive end `0x00597646`.
- IDA DB changes: renamed function `0x00597580` from stale `??1exception@boost@@MAE@XZ_4` to `TimerHandler_dtor` after a successful `rename` dry run; `lookup_funcs` after rename returned `TimerHandler_dtor`, size `0x43`; `idb_save` returned `ok:true` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`. Skipped candidates: no ScrollCollection helper renames, TimerHandler wrapper/helper renames, comments, prototypes, locals, struct members, vtable edits, or function definitions were applied because final helper/method/field names remain below source-quality confidence.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md --apply --lock-timeout 60`, `python .\tools\validator.py --mode file --file by-memory\0x00597580-0x005975c3.TimerHandlerDestructor.md --apply --lock-timeout 60`, and `python .\tools\validator.py --mode file --file by-memory\0x00597610-0x00597645.TimerHandlerWrappers.md --apply --lock-timeout 60` all exited `0` with `ok: 1`. A post-validation `rg` found no `0001GU`, `0001K7`, or `0001K9` rows remaining in `project-level/-auto-completion-stats.md`.
- Shared-report status: supervisor applied and validated the three `by-memory/-coverage-report.md` replacement rows below on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No C001 ScrollCollection/TimerHandler supervisor-owned rows remain pending.

Supervisor-applied exact `by-memory/-coverage-report.md` replacement rows retained for audit:

```text
        - [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md) 0x005628d0-0x00562bed | method | ScrollCollectionPaneHitTestScrollRegion : reconstructable : 85% : strong : C001 live IDA refresh reconfirmed exact `0x31d` hit-test boundary, two direct callers at `0x00562091` and `0x0056301f`, adjacent `0x00562bf0` geometry-helper boundary and thirteen rectangle-helper callsites, class-local update/drag helper graph, byte fence before `0x00562bf0`, direct owner/emitter route through [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md), and blank final C++ pending the exact geometry-helper child plus source-quality part/field/cursor-helper names.
        - [UID:0001K7][0x00597580-0x005975c3.TimerHandlerDestructor](by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md) 0x00597580-0x005975c3 | non-deleting destructor | TimerHandlerDestructor : reconstructable : 86% : strong : C001 live IDA refresh reconfirmed exact `0x43` non-deleting destructor boundary, `TimerHandler` vtable restore, fifteen direct cleanup/destructor callers, vtable refs at `0x00597570`/`0x005975a2`/`0x00597675`, unregister edge through `g_pTimerMgr` to `0x00597a10`, removal-helper-to-splice-helper graph, direct owner/emitter route through [UID:0000F0][TimerHandler](by-class/TimerHandler.md), and IDA stale-name repair from `??1exception@boost@@MAE@XZ_4` to `TimerHandler_dtor`; final C++ remains blank pending helper names/signatures and the `TimerHandler.cpp` vs `TimerMgr.cpp` split.
        - [UID:0001K9][0x00597610-0x00597645.TimerHandlerWrappers](by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md) 0x00597610-0x00597645 | timer-handler wrappers | TimerHandlerWrappers : reconstructable : 86% : strong : C001 live IDA refresh reconfirmed two exact `0x16` wrappers, `g_pTimerMgr` forwarding disassembly to `0x00597b80` and `0x00597ca0`, 47/1 direct caller split, removal-helper refs, shared `0x00598290` splice-helper refs, match-vs-except predicate difference between the two manager helpers, stale SoundManager/browser/audio ownership rejection, direct owner/emitter route through [UID:0000F0][TimerHandler](by-class/TimerHandler.md), and blank final C++ pending final public method names plus source split.
```

## 2026-06-16 Agent-C001 Goal 2 Class Completion Ranking/Effects/WillBeChanged C001-goal2-class-completion-ranking-effects-willbechanged-20260616-4

Placement context: `by-class/-coverage-report.md` was leased by Agent-A001 during this pass, so C001 did not edit it. Replace the existing [UID:0000BM], [UID:0000DE], and [UID:0000G5] rows in place. No `by-memory/-coverage-report.md` rows are pending for this class-only pass.

- Changed docs: [UID:0000BM][RankingDialog](../../../../by-class/RankingDialog.md), [UID:0000DE][SolidColorFilterEffecter](../../../../by-class/SolidColorFilterEffecter.md), [UID:0000G5][WillBeChangedItemPane](../../../../by-class/WillBeChangedItemPane.md), validator-owned generated/project stats, IDA database `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, and this notes file.
- Leases used: [UID:0000BM], [UID:0000DE], [UID:0000G5], and `tools/leaser/Agents/Agent-C001/notes.md`; `by-class/-coverage-report.md` was not leased by C001 because Agent-A001 held it.
- Score changes: [UID:0000BM] `82/86 -> 85/88`; [UID:0000DE] `82/86 -> 85/88`; [UID:0000G5] `82/86 -> 85/88`.
- Owner/emitter decisions: unchanged and now refreshed as gate-supported. [UID:0000BM] remains owner/emitter [UID:0000MZ][RankingDialog](../../../../by-file/RankingDialog.md). [UID:0000DE] remains owner/emitter [UID:0000IZ][Effects](../../../../by-file/Effects.md). [UID:0000G5] remains owner/emitter [UID:0000JU][HelpPanes](../../../../by-file/HelpPanes.md). Final C++ remains blank on all three because field/type/helper names and final source split/output cleanup are not final-source quality.
- Evidence summary: live IDA MCP session `c001_midiplayer_rdata_20260615` reported `NexusTK.exe.i64`, image base `0x00400000`, Hex-Rays ready, and strings cache ready. Ranking refresh reconfirmed exact method boundaries, opcode `0x7d` packet-handler behavior, `0x00610984`/`0x006109e4`/`0x00610a14` vtable-store refs, and 17 `g_pRankingDialog` xrefs. SolidColor refresh reconfirmed constructor/fill/destructor boundaries, constructor callers, four vtable-view store/reset refs, fill-buffer loop behavior, and broad `0x0069b364` UI-layer fan-out rejecting stale `g_pScreenEffecterList`. WillBeChanged refresh reconfirmed constructor/paint/event/key/destructor boundaries, constructor caller `0x004ed40f`, vtable-only method refs, three item-pane vtable views, five singleton xrefs, and scalar deleting destructor behavior.
- IDA DB changes: dry-run and apply succeeded for eight function renames and two data renames; `idb_save` returned `ok:true`. Function renames: `sub_459210 -> RankingDialog_HandleRankingPacket`, `sub_459810 -> RankingDialog_ClearSingletonHelper`, `sub_459840 -> RankingDialog_ScalarDeletingDestructor`, `sub_55AE00 -> SolidColorFilterEffecter_Constructor`, `sub_55AF60 -> SolidColorFilterEffecter_FillBuffer`, `sub_4C78E0 -> WillBeChangedItemPane_Constructor`, `sub_4C7BB0 -> WillBeChangedItemPane_OnPaint`, and `sub_4CE670 -> WillBeChangedItemPane_ScalarDeletingDestructor`. Data renames: `dword_67A7E4 -> g_pRankingDialog` and `unk_69B414 -> g_pWillBeChangedItemPane`.
- IDA skipped candidates: no rename for `0x0069b364` because [UID:0000S6][g_pScreenEffecterList](../../../../by-global/g_pScreenEffecterList.md) documents it as a broad UI layer/context slot with unresolved final source name. No prototypes, locals, member/type edits, vtable edits, or broader function-name sweeps were applied because packet wrappers, pane/control helper names, filter fields, item-slot structures, event/key enums, and exact final source splits remain provisional.
- Validation: first attempted validator command used a duplicated repo path from inside `project-documentation` and failed before scanning; corrected commands `python .\tools\validator.py --mode file --file by-class\RankingDialog.md --apply --lock-timeout 60`, `python .\tools\validator.py --mode file --file by-class\SolidColorFilterEffecter.md --apply --lock-timeout 60`, and `python .\tools\validator.py --mode file --file by-class\WillBeChangedItemPane.md --apply --lock-timeout 60` all exited `0` and reached `ok: 1`. Post-validation `rg` found no `0000BM`, `0000DE`, or `0000G5` rows remaining in `project-level/-auto-completion-stats.md`.

Supervisor-applied exact `by-class/-coverage-report.md` replacement rows retained for audit:

Supervisor applied and validated these rows on 2026-06-16 with `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No C001 Ranking/Effects/WillBeChanged class-report rows remain pending.

```text
- [UID:0000BM][RankingDialog](by-class/RankingDialog.md) : reconstructable : 85% : strong : C001 live IDA refresh reconfirmed RankingDialog method boundaries, opcode `0x7d` packet-handler behavior, primary/secondary/tertiary vtable-store refs, all 17 `g_pRankingDialog` xrefs, gate-valid owner/emitter route through [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), IDA names `RankingDialog_HandleRankingPacket` / `RankingDialog_ClearSingletonHelper` / `RankingDialog_ScalarDeletingDestructor` and `g_pRankingDialog`, and blank final C++ pending field/helper names plus generated-source pollution cleanup.
- [UID:0000DE][SolidColorFilterEffecter](by-class/SolidColorFilterEffecter.md) : reconstructable : 85% : strong : C001 live IDA refresh reconfirmed constructor/fill/destructor boundaries, two constructor callers, four SolidColor vtable views, fill-buffer loop writing cached RGB565 color, stale `g_pScreenEffecterList` rejection through the 35-xref `0x0069b364` UI-layer slot, owner/emitter route through [UID:0000IZ][Effects](by-file/Effects.md), IDA names `SolidColorFilterEffecter_Constructor` and `SolidColorFilterEffecter_FillBuffer`, and blank final C++ pending FilterEffecter field/helper/callback names.
- [UID:0000G5][WillBeChangedItemPane](by-class/WillBeChangedItemPane.md) : reconstructable : 85% : strong : C001 live IDA refresh reconfirmed constructor, paint, event, key, reset, adjustor, and scalar-deleting destructor boundaries, constructor caller `0x004ed40f`, vtable-only paint/event/key refs, three item-pane vtable views, five `g_pWillBeChangedItemPane` singleton xrefs, owner/emitter route through [UID:0000JU][HelpPanes](by-file/HelpPanes.md), IDA names `WillBeChangedItemPane_Constructor` / `WillBeChangedItemPane_OnPaint` / `WillBeChangedItemPane_ScalarDeletingDestructor` and `g_pWillBeChangedItemPane`, and blank final C++ pending item-slot/event/field names plus final `HelpPanes.cpp` versus `WillBeChangedPanes.cpp` split.
```

## 2026-06-16 Agent-C001 Goal 2 Class Completion Argumented/AutoInit C001-goal2-class-completion-argumented-autoinit-20260616-5

Placement context: `by-class/-coverage-report.md` was free during this pass, so C001 leased, edited, and validated the three class rows directly. C001 remains banned from directly editing `by-memory/-coverage-report.md`; replace the existing [UID:0001BT] row in place under the [UID:0001BS]/argumented menu-input dialog executable cluster, keeping the current indentation/nesting.

- Changed docs: [UID:00000F][ArgumentedItemConfirmInputDialogPane](../../../../by-class/ArgumentedItemConfirmInputDialogPane.md), [UID:00000G][ArgumentedItemQuantityInputDialogPane](../../../../by-class/ArgumentedItemQuantityInputDialogPane.md), [UID:00000Q][AutoInit](../../../../by-class/AutoInit.md), [UID:0001BT][0x0051fc90-0x00520539.ArgumentedItemInputDialogs](../../../../by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md), `by-class/-coverage-report.md`, validator-owned generated/project stats, IDA database `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, and this notes file.
- Leases used: [UID:00000F], [UID:00000G], [UID:00000Q], [UID:0001BT], `by-class/-coverage-report.md`, and `tools/leaser/Agents/Agent-C001/notes.md`.
- Score changes: [UID:00000F] `82/88 -> 86/90`; [UID:00000G] `82/88 -> 86/90`; [UID:00000Q] `82/88 -> 85/89`; support [UID:0001BT] `84/88 -> 85/89`.
- Owner/emitter decisions: unchanged and refreshed as gate-supported. [UID:00000F] and [UID:00000G] remain owner/emitter [UID:0000HH][ArgumentedItemInputDialogs](../../../../by-file/ArgumentedItemInputDialogs.md), which is `86/89`. [UID:00000Q] remains owner/emitter [UID:0000HN][AutoInit](../../../../by-file/AutoInit.md), which is `85/87`. [UID:0001BT] remains owner/emitter [UID:0000HH].
- Evidence summary: live IDA MCP session `c001_midiplayer_rdata_20260615` reported `NexusTK.exe.i64`, module `NexusTK.exe`, Hex-Rays ready, and strings cache ready; `server_health` returned status `ok` while `auto_analysis_ready` was `false`, so C001 kept the pass to targeted lookup/xref/decompile/name checks backed by existing docs. `lookup_funcs`, `analyze_component`, `xrefs_to`, and `entity_query` reconfirmed the argumented quantity/confirm constructor/action boundaries, vtable refs at `0x0061f5d0` and `0x0061f66c`, six decorated input-dialog vtable names through `0x0061f6b4`, successor `ObjectImageControlPane` vtable at `0x0061f6c0`, constructor callers, packet-helper calls, and internal dispatch through `SendArgumentedItemQuantityPacket`. For AutoInit, `lookup_funcs`, `analyze_component`, and `xrefs_to` reconfirmed `InitializeOleSupport`, ordinary/scalar destructors, static shutdown thunk, startup table `0x0060d6a4`, atexit pointer `0x00419ee8 -> 0x0060c0f0`, vtable `0x0061373c`, and static slot `0x0066d42c`.
- IDA DB changes: dry-run and apply succeeded for nine function renames; `lookup_funcs` after rename confirmed all new names, and `idb_save` returned `ok:true`. Function renames: `sub_51F640 -> SendArgumentedItemQuantityPacket`, `sub_51FC90 -> ArgumentedItemQuantityInputDialogPane_Constructor`, `sub_51FF70 -> ArgumentedItemQuantityInputDialogPane_OnDialogAction`, `sub_5200D0 -> ArgumentedItemConfirmInputDialogPane_Constructor`, `sub_5203C0 -> ArgumentedItemConfirmInputDialogPane_OnDialogAction`, `sub_419EE0 -> InitializeOleSupport`, `sub_46EFE0 -> AutoInit_NonDeletingDestructor`, `sub_470300 -> AutoInit_ScalarDeletingDestructor`, and `sub_60C0F0 -> AutoInit_StaticShutdownThunk`.
- IDA skipped candidates: no rename for helper starts `0x0051f450` or `0x0051f510` because `xrefs_to` still shows no direct start refs and final helper names remain provisional. No rename for AutoInit data slot `off_66D42C` because the static object storage role is proven but source-facing object spelling is still unresolved. No prototypes, locals, struct/member fields, vtable edits, or comments were applied because dialog context field names, packet-row fields, source-facing signatures, and final source splits remain below safe database-mutation confidence.
- Blockers investigated: argumented class final C++ is still blocked by exact class member names, source-facing helper signatures, and the standalone `ArgumentedItemInputDialogs.cpp` versus folded `ArgumentedMenuDialogs.cpp` source split. AutoInit final C++ is still blocked by source-facing object/class spelling and final `AutoInit.cpp` versus `PlatformApi.cpp` fold, not by behavior. B-agent handoff is not needed for these target gates; remaining work is a layout/rewrite/source-spelling pass rather than heavy heuristic ownership research.
- Validation: `python .\tools\validator.py --mode file --file by-class\ArgumentedItemConfirmInputDialogPane.md --apply --lock-timeout 60`, `python .\tools\validator.py --mode file --file by-class\ArgumentedItemQuantityInputDialogPane.md --apply --lock-timeout 60`, `python .\tools\validator.py --mode file --file by-class\AutoInit.md --apply --lock-timeout 60`, `python .\tools\validator.py --mode file --file by-memory\0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md --apply --lock-timeout 60`, and `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --lock-timeout 60` all exited `0` with `ok: 1`. Post-validation `rg` found no `00000F`, `00000G`, `00000Q`, or `0001BT` rows remaining in `project-level/-auto-completion-stats.md`.
- Shared-report status: `by-class/-coverage-report.md` was updated and validated directly by C001. Supervisor applied and validated the by-memory row below after normalizing it to include the standard range/type/name fields.
- Release status: final unlease returned `Success` for `by-class/-coverage-report.md`; the target/support/notes paths returned `Rejected[No active lease]` because the short leases had already expired/purged. A final `current_leases.md` check showed no active C001 leases.

Supervisor-applied exact `by-memory/-coverage-report.md` replacement row retained for audit:

- Supervisor applied and validated this replacement row on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No C001 Argumented/AutoInit supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

```text
    - [UID:0001BT][0x0051fc90-0x00520539.ArgumentedItemInputDialogs](by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md) 0x0051fc90-0x00520539 | class-method-cluster | ArgumentedItemInputDialogs : reconstructable : 85% : strong : Exact argumented item input-dialog method cluster with C001 live IDA-renamed quantity/confirm constructor/action handlers, `SendArgumentedItemQuantityPacket`, confirmed constructor/action boundaries, vtable anchors, direct callers, decorated `.rdata` vtable names through `0x0061f6b4`, successor `ObjectImageControlPane` boundary, validation/dispatch behavior, false-start exclusion, and owner/emitter route through [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md).
```

## 2026-06-16 Agent-C001 Goal 2 Collection/CheckBox IDA Refresh C001-goal2-collection-checkbox-ida-refresh-20260616-6

Placement context: C001 is banned from directly editing `by-memory/-coverage-report.md`. Replace the existing [UID:00010X] row in place under the collection dialog executable island; current report row is at the `0x0048c640-0x0048e305.CollectionDialogControls` entry and still shows `82%`.

- Changed docs/reports: [UID:00002V][CollectionDialogPane](../../../../by-class/CollectionDialogPane.md), [UID:0000IB][CollectionDialogPane](../../../../by-file/CollectionDialogPane.md), [UID:0000I7][CheckBoxControlPane](../../../../by-file/CheckBoxControlPane.md), [UID:00010X][0x0048c640-0x0048e305.CollectionDialogControls](../../../../by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md), [UID:0001TX][CheckBoxControlPaneLayout](../../../../by-type/by-struct/CheckBoxControlPaneLayout.md), `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, `by-type/by-struct/-coverage-report.md`, validator-owned generated/project stats, IDA database `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, and this notes file.
- Leases used: [UID:00002V], [UID:0000IB], [UID:0000I7], [UID:00010X], [UID:0001TX], `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, `by-type/by-struct/-coverage-report.md`, and `tools/leaser/Agents/Agent-C001/notes.md`.
- Score changes: [UID:00002V] `82/88 -> 86/90`; [UID:0000IB] `85/86 -> 86/88`; [UID:0000I7] `85/86 -> 86/88`; support [UID:00010X] `82/88 -> 85/89`; support [UID:0001TX] `82/90 -> 85/91`.
- Owner/emitter decisions: unchanged and now refreshed as gate-supported. CollectionDialogPane class and executable island remain owner/emitter [UID:0000IB][CollectionDialogPane](../../../../by-file/CollectionDialogPane.md). CheckBoxControlPane file remains validator-managed split-candidate root at `NexusTK/ui/controls/`, while [UID:0001TX] remains owner/emitter [UID:000021][CheckBoxControlPane](../../../../by-class/CheckBoxControlPane.md). Final C++ remains blank on the refreshed reconstructable docs because field names, source-facing helper signatures, inherited subobject names, page-step reachability, and final historical source grouping are not final-source quality.
- Evidence summary: live IDA MCP session `c001_midiplayer_rdata_20260615` reported active `NexusTK.exe.i64`, Hex-Rays ready, and strings cache ready earlier in the pass. Collection refresh reconfirmed exact modeled function boundaries, constructor callers `0x00508cf6`/`0x00514529`/`0x0056fd40`, vtable anchors `0x006164f4`/`0x00616554`/`0x00616584`, eight `g_pCollectionDialogPane` xrefs, page-step blocks `0x0048d1d0` and `0x0048d2d0` still not modeled as functions and with no direct start xrefs, internal private-control edges, `.rdata` resource/vtable boundary, and a unique `0x0048c640-0x0048e305` range signature. CheckBox refresh reconfirmed exact method sizes, constructor callers `0x00450f60`/`0x0045100d`/`0x0047d3b4`, setter callers from MiniMap, getter caller `0x0047dfd0`, vtable bases `0x006184d8`/`0x00618540`/`0x00618570`, and unique core range signature.
- Blockers investigated: Collection page-step blocks were checked for function-table entries and direct start xrefs and remain unsafe to promote/create as functions. Collection final C++ remains blocked by final field/helper names and source-facing page-step/source split. CheckBox split was rechecked against caller breadth and ButtonControlPane grouping; standalone `CheckBoxControlPane.cpp` remains a validator-managed split candidate, but the historical fold into [UID:0000HY][ButtonControlPane](../../../../by-file/ButtonControlPane.md) remains unresolved. CheckBox type/member edits were skipped because inherited subobject names and final source split remain provisional.
- IDA DB changes: first apply attempt used stale `ea` schema and failed before mutation. Corrected apply succeeded for 19 function renames and `idb_save` returned `ok:true`: `sub_48C640 -> CollectionDialogPane_Constructor`, `sub_48CFB0 -> CollectionDialogPane_OnButtonClick`, `sub_48D190 -> CollectionDialogPane_FindCategoryIndex`, `sub_48D3A0 -> CollectionEntryControlPane_Constructor`, `sub_48D4A0 -> CollectionEntryControlPane_OnDraw`, `sub_48D9E0 -> CollectionEntryControlPane_DrawWrappedText`, `sub_48DC30 -> CollectionBarControlPane_Constructor`, `sub_48DD60 -> CollectionBarControlPane_OnPaint`, `sub_48DFF0 -> CollectionBarControlPane_DrawProgressLabel`, `sub_48E140 -> ClearCollectionDialogPaneSingleton`, `sub_48E250 -> CollectionDialogPane_ScalarDeletingDestructor`, `sub_499D40 -> CheckBoxControlPane_Constructor`, `sub_499DC0 -> CheckBoxControlPane_SetChecked`, `sub_499DD0 -> CheckBoxControlPane_GetChecked`, `sub_499DE0 -> CheckBoxControlPane_OnMouse`, `sub_499E30 -> CheckBoxControlPane_OnPaint`, `sub_499EC0 -> CheckBoxControlPane_StateTypeHelper`, `sub_49B8D0 -> CheckBoxControlPane_GetControlTypeId`, and `sub_49B110 -> CheckBoxControlPane_ScalarDeletingDestructor`.
- IDA skipped candidates: no page-step function creation, destructor-family sweep beyond the documented safe names, data/global rename, prototype, comment, vtable edit, type/member edit, local rename, split/merge/range rename, or final C++ was applied. The skipped candidates still depend on reachability/source shape or final source-facing names rather than routine C-agent evidence.
- Validation: the required loop `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240` exited `0` for `by-class\CollectionDialogPane.md`, `by-file\CollectionDialogPane.md`, `by-file\CheckBoxControlPane.md`, `by-memory\0x0048c640-0x0048e305.CollectionDialogControls.md`, `by-type\by-struct\CheckBoxControlPaneLayout.md`, `by-class\-coverage-report.md`, `by-file\-coverage-report.md`, and `by-type\by-struct\-coverage-report.md`; each run reached `ok: 1`. A post-validation `rg` found no [UID:00002V], [UID:0000IB], [UID:0000I7], or [UID:0001TX] rows remaining in `project-level/-auto-completion-stats.md`.

Supervisor-applied supervisor-owned exact `by-memory/-coverage-report.md` replacement row retained for audit:

Supervisor applied and validated this normalized replacement row on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No C001 Collection/CheckBox supervisor-owned memory row remains pending.

```text
    - [UID:00010X][0x0048c640-0x0048e305.CollectionDialogControls](by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md) : reconstructable : 85% : strong : C001 live IDA refresh reconfirmed the collection dialog/private-control island, exact modeled function boundaries, three external dialog constructor callers, internal entry/bar constructor and draw-helper edges, page-step code-block no-function/no-start-xref caveat, dialog/private-control vtable anchors, eight `g_pCollectionDialogPane` xrefs, unique documented-range signature, saved IDA names for the documented dialog/control functions, unchanged owner/emitter route through [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md), and blank final C++ pending page-step reachability plus source-quality field/helper names.
```

## 2026-06-16 Goal 2 Type Layout / IDA Refresh MyItem/ObjectList/Ranking

Assignment: `C001-goal2-type-layout-ida-refresh-myitem-objectlist-ranking-20260616-7`.

Assigned targets:
- [UID:0001VE] `by-type/by-struct/MyItemListPaneEntryLayouts.md`
- [UID:0001VG] `by-type/by-struct/ObjectListLayout.md`
- [UID:0001VN] `by-type/by-struct/RankingCategoryRecordLayout.md`

Instructions:
- Read and follow `Agent-C001/goal.md`, current supervisor notes, lease rules, by-structure rules, validator requirements, and the temporary `by-memory/-coverage-report.md` edit ban.
- Use live IDA evidence plus existing by-class/by-file/by-memory/by-type documentation to improve struct/member layout confidence, source-facing names where safe, owner/emitter support, and related non-banned coverage reports.
- Safe IDA database work is allowed for source-quality function/type/member/global/comment improvements only when backed by current docs and live evidence. Skip and document provisional names rather than mutating IDA on weak evidence.
- A target at or above 85/85 is not done if unresolved field/type/global/helper/protocol, ownership, source-placement, range/split, reachability, or final-C++ blockers have not been investigated. Resolve them where supported; otherwise record the exact evidence checked and why the issue remains unsafe.
- Do not directly edit `by-memory/-coverage-report.md`. If by-memory support rows need updates, record exact replacement/insert/delete text and placement context here for supervisor application.
- Report changed files, leases used, validations, before/after score changes, owner/emitter decisions, IDA changes/saves, blocker investigations, and any exact pending supervisor-owned coverage rows.

Closeout:

- Changed docs/reports: [UID:0000RC][g_pLanguageMan](../../../../by-global/g_pLanguageMan.md), [UID:0000RO][g_pMiniMapDownloader](../../../../by-global/g_pMiniMapDownloader.md), [UID:0000RP][g_pMiniMapVersionManager](../../../../by-global/g_pMiniMapVersionManager.md), [UID:0000RQ][g_pMiscWorkThread](../../../../by-global/g_pMiscWorkThread.md), [UID:0001P8][0x0067ab50-0x0067ab54.g_pMiscWorkThread](../../../../by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md), `by-global/-coverage-report.md`, validator-owned generated/project stats, IDA database `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, and this notes file.
- Leases used: [UID:0000RC], [UID:0000RO], [UID:0000RP], [UID:0000RQ], [UID:0001P8], `by-global/-coverage-report.md`, and `tools/leaser/Agents/Agent-C001/notes.md`; most target/report leases expired naturally during validation/closeout, and notes was re-leased before recording this entry.
- Score changes: [UID:0000RC] `84/88 -> 85/90`; [UID:0000RO] `84/88 -> 85/90`; [UID:0000RP] `84/88 -> 85/90`; [UID:0000RQ] `84/88 -> 85/89`; support [UID:0001P8] remained `86/90` after correcting stale byte evidence.
- Owner/emitter decisions: unchanged and refreshed as gate-supported. [UID:0000RC] remains routed through [UID:0000KK][LanguageMan](../../../../by-file/LanguageMan.md). [UID:0000RO] remains routed through [UID:0000LE][MiniMap](../../../../by-file/MiniMap.md). [UID:0000RP] remains routed through [UID:0000LF][MiniMapVersionManager](../../../../by-file/MiniMapVersionManager.md). [UID:0000RQ] remains routed through [UID:0000LG][MiscWorkThread](../../../../by-file/MiscWorkThread.md). [UID:0001P8] remains a canonical memory child of [UID:0000RQ], then [UID:0000LG].
- Evidence summary: live IDA MCP session `c001_midiplayer_rdata_20260615` reported active `NexusTK.exe.i64`, module `NexusTK.exe`, image base `0x00400000`, Hex-Rays ready, and strings cache ready. `xrefs_to`/`get_bytes`/decompile review reconfirmed `g_pLanguageMan` at `0x0067a750` with zeroed singleton-adjacent bytes, broad localization fanout, constructor publish/fallback clear, cleanup clear, singleton clear helper, and scalar-deleting clear; `g_pMiniMapDownloader` at `0x0067a7d8` with exact five lifecycle refs; `g_pMiniMapVersionManager` at `0x0067a7dc` with exact twelve lifecycle/consumer refs; and `g_pMiscWorkThread` at `0x0067ab50` with exact eight lifecycle/consumer refs. The live byte read for `0x0067ab50` is zeroed and supersedes older docs/report text that called the slot `0xffffffff`.
- IDA DB changes: dry-run and apply succeeded for sixteen function renames plus four data renames; `idb_save` returned `ok:true`. Function renames: `sub_4F0010 -> LanguageMan_Constructor`, `??1exception@boost@@MAE@XZ_3 -> LanguageMan_CleanupDestructor`, `sub_4F03C0 -> LanguageMan_ClearSingletonHelper`, `sub_4F03D0 -> LanguageMan_ScalarDeletingDestructor`, `sub_453910 -> MiniMapDownloader_Constructor`, `sub_453990 -> MiniMapDownloader_Destructor`, `sub_453D50 -> MiniMapDownloader_ClearSingletonHelper`, `sub_453D60 -> MiniMapDownloader_ScalarDeletingDestructor`, `sub_4563C0 -> MiniMapVersionManager_Constructor`, `sub_456480 -> MiniMapVersionManager_Destructor`, `sub_4573C0 -> MiniMapVersionManager_ClearSingletonHelper`, `sub_457480 -> MiniMapVersionManager_ScalarDeletingDestructor`, `sub_5281B0 -> MiscWorkThread_Constructor`, `sub_528230 -> MiscWorkThread_Destructor`, `sub_5283E0 -> MiscWorkThread_ClearSingletonHelper`, and `sub_5283F0 -> MiscWorkThread_ScalarDeletingDestructor`. Data renames: `dword_67A750 -> g_pLanguageMan`, `dword_67A7D8 -> g_pMiniMapDownloader`, `dword_67A7DC -> g_pMiniMapVersionManager`, and `unk_67AB50 -> g_pMiscWorkThread`.
- IDA skipped candidates: no LanguageMan lookup/helper names were promoted because the `LanguageMan` versus `LanguageManager` source spelling and adjacent `0x004f0310` zero-initializer type shape remain unsettled. No MiniMap download/task wrapper names, MiniMapVersionManager cache/list helper names, MiscWorkThread request-wrapper names, browse helper name at `0x005283b0`, prototypes, comments, vtables, locals, or type/member edits were applied because those names still depend on final source split or struct layout evidence rather than routine singleton proof.
- Blockers investigated: final C++ remains blank for all four global pages. [UID:0000RC] is blocked by original file/class spelling and the `0x004f0310` zero-initializer field/type question after reviewing LanguageMan file/class/memory docs plus live lifecycle xrefs. [UID:0000RO] is blocked by task-block/base-thread names and `MiniMapDownloader.cpp` versus compact `MiniMap.cpp` placement after reviewing MiniMap file/class/memory docs and live five-ref lifecycle evidence. [UID:0000RP] is blocked by internal list/vector/cache field names, cache-body promotion, and source split after reviewing the direct class/file/memory docs and twelve-ref consumer set. [UID:0000RQ] is blocked by wrapper names, raw browse-helper shape, notification layout spelling, and source path after reviewing MiscWorkThread file/class/memory docs and eight direct refs. These are source-quality blockers, not ownership/storage blockers.
- Validation: from `source-3/project-documentation`, the required command shape `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240` exited `0` for `by-global\g_pLanguageMan.md`, `by-global\g_pMiniMapDownloader.md`, `by-global\g_pMiniMapVersionManager.md`, `by-global\g_pMiscWorkThread.md`, `by-memory\0x0067ab50-0x0067ab54.g_pMiscWorkThread.md`, and `by-global\-coverage-report.md`; the validator output reached `ok: 1` and post-validation `rg` found no `0000RC`, `0000RO`, `0000RP`, or `0000RQ` rows remaining in `project-level/-auto-completion-stats.md`.

Supervisor-applied supervisor-owned exact `by-memory/-coverage-report.md` replacement row retained for audit:

Supervisor applied the row below on 2026-06-16 and validated `by-memory/-coverage-report.md` with `ok:1`.

Placement context: C001 remains banned from directly editing `by-memory/-coverage-report.md`. Replace the existing [UID:0001P8] row in place under the `0x0067ab50-0x0067ab54.g_pMiscWorkThread` entry; the current row still says initialized to `0xffffffff`, which is stale against the 2026-06-16 live IDA byte reread and the corrected target doc.

```text
    - [UID:0001P8][0x0067ab50-0x0067ab54.g_pMiscWorkThread](by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md) 0x0067ab50-0x0067ab54 | global pointer | g_pMiscWorkThread : reconstructable : 86% : strong : Exact four-byte MiscWorkThread singleton slot with current C001 live IDA zeroed byte window, eight direct xrefs, constructor publish/fallback clear at `0x005281f1`/`0x005281f8`, destructor/helper/scalar-deleting clears at `0x00528262`, `0x005283e0`, and `0x00528429`, application startup/cleanup refs, registration/NCA and patch/download wrapper consumers, saved IDA name `g_pMiscWorkThread`, and file/global parent route through [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md) to [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md).
```

Closeout:

- Changed docs/reports: [UID:0001VE][MyItemListPaneEntryLayouts](../../../../by-type/by-struct/MyItemListPaneEntryLayouts.md), [UID:0001VG][ObjectListLayout](../../../../by-type/by-struct/ObjectListLayout.md), [UID:0001VN][RankingCategoryRecordLayout](../../../../by-type/by-struct/RankingCategoryRecordLayout.md), [UID:0000BL][RankingCategoryRecord](../../../../by-class/RankingCategoryRecord.md), [UID:0000Y9][0x0045bf60-0x0045c257.RankingCategoryRecord](../../../../by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md), [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](../../../../by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md), `by-type/by-struct/-coverage-report.md`, `by-class/-coverage-report.md`, validator-owned generated/project stats, IDA database `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, and this notes file.
- Leases used: [UID:0001VE], [UID:0001VG], [UID:0001VN], [UID:0000BL], [UID:0000Y9], [UID:0001D3], `by-type/by-struct/-coverage-report.md`, `by-class/-coverage-report.md`, and `tools/leaser/Agents/Agent-C001/notes.md`; notes was re-leased before closeout because the validator run exceeded the short lease window.
- Score changes: [UID:0001VE] `82/88 -> 85/90`; [UID:0001VG] `82/88 -> 85/90`; [UID:0001VN] `82/88 -> 85/90`; support [UID:0000BL] `84/88 -> 85/89`; support [UID:0000Y9] `84/88 -> 85/89`; support [UID:0001D3] `84/86 -> 85/88`.
- Owner/emitter decisions: [UID:0001VE] remains routed through [UID:00008W][MyItemListPane](../../../../by-class/MyItemListPane.md), which remains supported by [UID:0000LO][MyItemListPane](../../../../by-file/MyItemListPane.md). [UID:0001VG] remains routed through [UID:00009Q][ObjectList](../../../../by-class/ObjectList.md), and [UID:0001D3] was corrected from stale file ownership to direct owner/emitter [UID:00009Q]. [UID:0001VN], [UID:0000BL], and [UID:0000Y9] remain routed through [UID:0000MZ][RankingDialog](../../../../by-file/RankingDialog.md). Final C++ remains blank on these layout/container support pages because field/type/source-facing API names are still not final-source quality.
- Evidence summary: live IDA MCP session `c001_midiplayer_rdata_20260615` reported active `NexusTK.exe.i64`, module `NexusTK.exe`, image base `0x00400000`, Hex-Rays ready, and strings cache ready. MyItemListPane refresh reconfirmed constructor callers `0x0048a50d`, `0x004ae63e`, `0x004ae7f0`, and `0x004af7a7`, selected-slot callers `0x0048a733`/`0x0048b6ae`, constructor stack row payload fields at `+0x02` item id, `+0x04` category/style, and `+0x06` wide name, slot-count/global access through `unk_69AE0C + 644`, and draw-time consumers. ObjectList refresh reconfirmed constructor/destructor field symmetry, optional `+0x34` gate, constructor callers `0x0050bc55`/`0x005106e2`, scalar-destructor caller `0x00537296`, and trivial accessor offsets `+0x14`, `+0x18`, and `+0x2c..+0x40`. Ranking refresh reconfirmed eleven exact method starts, live xrefs, accessors at `+0x00`/`+0x04`/`+0x08`, date/time blocks at `+0x0c` and `+0x30`, title pointer at `+0x54`, user-entry vector at `+0x258`, reset field at `+0x268`, 76-byte append stride, and RankingUserListPane row rank/name/score consumers.
- IDA DB changes: dry-run and apply succeeded for sixteen function renames; `idb_save` returned `ok:true`. Function renames: `sub_4AEB30 -> MyItemListPane_Constructor`, `sub_4AEC80 -> MyItemListPane_GetSelectedSlotIndex`, `sub_4AEC90 -> MyItemListPane_DrawListEntry`, `sub_530EE0 -> ObjectList_Constructor`, `sub_531260 -> ObjectList_Destructor`, `sub_45BF60 -> RankingCategoryRecord_GetListIndex`, `sub_45BF70 -> RankingCategoryRecord_GetCategoryId`, `sub_45BF80 -> RankingCategoryRecord_GetStateCode`, `sub_45BF90 -> RankingCategoryRecord_CopyStartTimeParts`, `sub_45BFB0 -> RankingCategoryRecord_CopyEndTimeParts`, `sub_45BFD0 -> RankingCategoryRecord_GetTitleText`, `sub_45BFE0 -> RankingCategoryRecord_GetUserEntryAt`, `sub_45C050 -> RankingCategoryRecord_SetStartTimeFromPackedDateTime`, `sub_45C100 -> RankingCategoryRecord_SetEndTimeFromPackedDateTime`, `sub_45C1E0 -> RankingCategoryRecord_AppendUserEntry`, and `sub_45C240 -> RankingCategoryRecord_ResetUserEntries`.
- IDA skipped candidates: no ObjectList accessor/sweep/helper renames because current docs still mark row/global tier and call-layer names provisional. No type/member/prototype/comment/vtable edits were applied because final active-user inventory names, ListPane row API names, ObjectList tier/member names, date/time field type, user-entry prefix field, and final source-facing declarations remain unresolved.
- Blockers investigated: MyItemListPane final layout declarations remain blocked by final active-user inventory/slot record and ListPane row API names, not by offset evidence. ObjectList final declarations remain blocked by tier/accessor naming and `MapPaneSpatialIndex` alias cleanup; ownership/source routing is now refreshed, including the [UID:0001D3] reroute to [UID:00009Q]. RankingCategoryRecord final declarations remain blocked by source-facing date/time type, user-entry type/name, and unknown user-entry prefix bytes; behavior, offsets, stride, and caller ownership were rechecked and are gate-quality. No B-agent handoff is recommended for these target gates; remaining work is source-spelling/type-finalization rather than heavy heuristic ownership research.
- Validation: from `source-3/project-documentation`, the required command shape `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240` exited `0` for `by-type\by-struct\MyItemListPaneEntryLayouts.md`, `by-type\by-struct\ObjectListLayout.md`, `by-type\by-struct\RankingCategoryRecordLayout.md`, `by-class\RankingCategoryRecord.md`, `by-memory\0x0045bf60-0x0045c257.RankingCategoryRecord.md`, `by-memory\0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md`, `by-type\by-struct\-coverage-report.md`, and `by-class\-coverage-report.md`; each run reached `ok: 1`. Post-validation `rg` found no `0001VE`, `0001VG`, `0001VN`, or `0000BL` rows remaining in `project-level/-auto-completion-stats.md`.

Supervisor-applied exact `by-memory/-coverage-report.md` replacement rows retained for audit:

Supervisor applied and validated these rows on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No C001 MyItem/ObjectList/Ranking supervisor-owned memory rows remain pending.

```text
    - [UID:0000Y9][0x0045bf60-0x0045c257.RankingCategoryRecord](by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md) 0x0045bf60-0x0045c257 | class-container | RankingCategoryRecord : reconstructable : 85% : strong : C001 live IDA refresh reconfirmed source-authored fixed-record helper container with eleven exact child method starts/sizes, live ranking caller sets, accessor/copy offsets, start/end packed date-time setter blocks, 76-byte user-entry append/reset behavior, 688-byte category-record stride, RankingUserListPane row rank/name/score consumers, saved IDA names for all eleven `RankingCategoryRecord_*` helpers, unchanged owner/emitter route through [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md), and blank final C++ pending final date/time/user-row field/type names.
    - [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md) 0x00532530-0x00532f67 | class method cluster | ObjectListAccessorsAndSweeps : reconstructable : 85% : strong : C001 live IDA refresh reconfirmed ObjectList accessor/sweep island function inventory, direct xrefs, trivial field accessors for `+0x14`, `+0x18`, and `+0x2c..+0x40`, row-bucket calculations through padded bounds, caller sets for `ShiftAll`/`DetachAll`/`PruneMarked`/`FindObjectAt`, predecessor switch-table and successor extended-helper boundaries, reroute to direct owner/emitter [UID:00009Q][ObjectList](by-class/ObjectList.md), and blank final C++ pending final accessor/tier names plus `MapPaneSpatialIndex` alias cleanup.
```

## 2026-06-16 Goal 2 Global Singleton / IDA Refresh LanguageMan/MiniMap/MiscWorkThread

Assignment: `C001-goal2-global-ida-refresh-language-minimap-miscwork-20260616-8`.

Assigned targets:
- [UID:0000RC] `by-global/g_pLanguageMan.md`
- [UID:0000RO] `by-global/g_pMiniMapDownloader.md`
- [UID:0000RP] `by-global/g_pMiniMapVersionManager.md`
- [UID:0000RQ] `by-global/g_pMiscWorkThread.md`

Instructions:
- Read and follow `Agent-C001/goal.md`, current supervisor notes, lease rules, by-structure rules, validator requirements, and the temporary `by-memory/-coverage-report.md` edit ban.
- This is a Goal 2 stats-driven global singleton/source-quality pass. Raise each target above the current `84/88` completion plateau where evidence supports it, and sync `by-global/-coverage-report.md`.
- Use live IDA evidence plus existing by-file/by-class/by-memory documentation to recheck exact storage, xrefs, lifecycle writes/clears, consumer call paths, canonical owner/emitter routing, and final source-placement blockers.
- Safe IDA database work is allowed for source-quality global/function/type/member/comment improvements only when backed by current docs and live evidence. Skip and document provisional names rather than mutating IDA on weak evidence.
- A target at or above 85/85 is not done if unresolved global/type/helper/source-split or final-C++ blockers have not been investigated. Resolve them where supported; otherwise record the exact evidence checked and why the issue remains unsafe.
- Do not directly edit `by-memory/-coverage-report.md`. If by-memory support rows need updates, record exact replacement/insert/delete text and placement context here for supervisor application.
- Report changed files, leases used, validations, before/after score changes, owner/emitter decisions, IDA changes/saves, blocker investigations, and any exact pending supervisor-owned coverage rows.

## 2026-06-16 Goal 2 Global Singleton / IDA Refresh History/System/Power/Ranking

Assignment: `C001-goal2-global-ida-refresh-history-system-power-ranking-20260616-9`.

Assigned targets:
- [UID:0000RS] `by-global/g_pNewHistoryDialog.md`
- [UID:0000RU] `by-global/g_pNewSystemMessagePane.md`
- [UID:0000S0] `by-global/g_pPowerDialog.md`
- [UID:0000S2] `by-global/g_pRankingDialog.md`

Closeout:

- Changed docs/reports: [UID:0000RS][g_pNewHistoryDialog](../../../../by-global/g_pNewHistoryDialog.md), [UID:0000RU][g_pNewSystemMessagePane](../../../../by-global/g_pNewSystemMessagePane.md), [UID:0000S0][g_pPowerDialog](../../../../by-global/g_pPowerDialog.md), [UID:0000S2][g_pRankingDialog](../../../../by-global/g_pRankingDialog.md), [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](../../../../by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md), [UID:0002AO][0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots](../../../../by-memory/0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md), [UID:0001PZ][0x0069ba34-0x0069ba38.g_pPowerDialog](../../../../by-memory/0x0069ba34-0x0069ba38.g_pPowerDialog.md), [UID:00028U][0x0067a7e4-0x0067a7e8.g_pRankingDialog](../../../../by-memory/0x0067a7e4-0x0067a7e8.g_pRankingDialog.md), `by-global/-coverage-report.md`, validator-owned generated/project stats, IDA database `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, and this notes file.
- Leases used: [UID:0000RS], [UID:0000RU], [UID:0000S0], [UID:0000S2], [UID:0001PV], [UID:0002AO], [UID:0001PZ], [UID:00028U], `by-global/-coverage-report.md`, and `tools/leaser/Agents/Agent-C001/notes.md`.
- Score changes: [UID:0000RS] `84/88 -> 85/90`; [UID:0000RU] `84/88 -> 85/90`; [UID:0000S0] `84/88 -> 85/90`; [UID:0000S2] `84/88 -> 85/90`; support [UID:0001PV] stayed `86/90`; support [UID:0002AO] stayed `86/89`; support [UID:0001PZ] stayed `86/90`; support [UID:00028U] stayed `86/90`.
- Owner/emitter decisions: unchanged and refreshed as gate-supported. [UID:0000RS] remains owner/emitter [UID:0000LQ][NewHistoryDialogPane](../../../../by-file/NewHistoryDialogPane.md). [UID:0000RU] remains owner/emitter [UID:0000OE][SystemMessagePanes](../../../../by-file/SystemMessagePanes.md). [UID:0000S0] remains owner/emitter [UID:0000MO][PowerDialogPane](../../../../by-file/PowerDialogPane.md). [UID:0000S2] remains owner/emitter [UID:0000MZ][RankingDialog](../../../../by-file/RankingDialog.md). The four memory support rows remain routed through their existing global/file parents.
- Evidence summary: live MCP session `c001_midiplayer_rdata_20260615` reported `NexusTK.exe.i64`, module `NexusTK.exe`, image base `0x00400000`, Hex-Rays ready, and strings cache ready. `get_bytes` reconfirmed current zeroed singleton-adjacent windows around `0x0069b49c`, `0x0069ba34`, `0x0069bc10`, and `0x0067a7e4`. `xrefs_to` reconfirmed [UID:0000RS] five refs, [UID:0000RU] six refs, [UID:0000S0] five refs, and [UID:0000S2] seventeen refs. Reachability checks found no direct `0x00500410` constructor-start refs for NewHistoryDialogPane; `0x00588560` has the `0x004b88ae` `GeneralPurposePanel2` constructor caller; `0x00549c20` has `0x0050876a` plus retained wrapper `0x00513b93`, while wrapper start `0x00513b50` has no inbound refs; `0x00458610` has command-dispatch caller `0x005bd2ab`.
- IDA DB changes: a dry-run and apply succeeded for ten function renames, followed by `idb_save ok:true`. Function renames: `sub_500410 -> NewHistoryDialogPane_Constructor`, `sub_5023E0 -> NewHistoryDialogPane_ClearSingletonHelper`, `sub_502920 -> NewHistoryDialogPane_ScalarDeletingDestructor`, `sub_588560 -> NewSystemMessagePane_Constructor`, `sub_58AAB0 -> NewSystemMessagePane_ClearSingletonHelper`, `sub_58AD20 -> NewSystemMessagePane_ScalarDeletingDestructor`, `sub_549C20 -> PowerDialogPane_Constructor`, `sub_54A480 -> PowerDialogPane_ClearSingletonHelper`, `sub_54A4B0 -> PowerDialogPane_GetSingleton`, and `sub_54B520 -> PowerDialogPane_ScalarDeletingDestructor`.
- IDA skipped candidates: data-slot renames for `g_pNewHistoryDialog`, `g_pNewSystemMessagePane`, and `g_pPowerDialog` were skipped because the current MCP `rename` data path requires an existing global-name key and these addresses are not exposed in `entity_query names`/`list_globals`; no raw Python eval tool is available in this MCP instance. No RankingDialog constructor/paint/button/layout/request renames were applied because the previous class pass already saved the safe global/helper names and broader class-layout/helper/source-output cleanup remains provisional. No prototypes, comments, locals, vtables, types, or member names were edited.
- Blockers investigated: [UID:0000RS] final C++ remains blocked by missing direct menu/constructor reachability, final declaration spelling, and helper/field names; this was checked with `xrefs_to 0x00500410`, `xrefs_to 0x005023e0`, singleton xrefs, and existing file/class/resource docs. [UID:0000RU] remains blocked by final split from `social/Chatting.cpp`/`SystemMessagePanes.cpp`, tiny virtual helper names, and child-pane rebuild field/type names after checking constructor caller, singleton refs, and SystemMessagePanes class/file/memory support. [UID:0000S0] remains blocked by final declaration spelling, packet-row/config fields, private-list/control source split, and the retained wrapper source shape after checking constructor and wrapper xrefs plus PowerDialogPane support docs. [UID:0000S2] remains blocked by ranking field/helper names, unresolved child-pane read ownership for several singleton refs, and generated-source pollution cleanup after checking the 17 refs, dispatcher constructor edge, and current RankingDialog class/file support. These are source-quality blockers, not storage/ownership blockers.
- Validation: from `source-3/project-documentation`, the required command shape `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240` exited `0` for `by-global\g_pNewHistoryDialog.md`, `by-global\g_pNewSystemMessagePane.md`, `by-global\g_pPowerDialog.md`, `by-global\g_pRankingDialog.md`, `by-memory\0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md`, `by-memory\0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md`, `by-memory\0x0069ba34-0x0069ba38.g_pPowerDialog.md`, `by-memory\0x0067a7e4-0x0067a7e8.g_pRankingDialog.md`, and `by-global\-coverage-report.md`; each run reached `ok: 1`. Post-validation `rg` found no `0000RS`, `0000RU`, `0000S0`, or `0000S2` rows remaining in `project-level/-auto-completion-stats.md`.

Supervisor-applied exact `by-memory/-coverage-report.md` replacement rows retained for audit:

Supervisor applied and validated these rows on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. C001 remains banned from directly editing `by-memory/-coverage-report.md`. Placement context: rows were replaced in place under the writable data/global singleton section. [UID:00028U] was refreshed to include current IDA name and dispatcher constructor reachability. [UID:0001PV] and [UID:0001PZ] were replaced because the previous report still said initialized to `0xffffffff`, stale against the 2026-06-16 live byte rereads and corrected target docs. [UID:0002AO] was refreshed to include the saved NewSystemMessagePane lifecycle names. No C001 pending memory coverage rows remain for this batch.

```text
    - [UID:00028U][0x0067a7e4-0x0067a7e8.g_pRankingDialog](by-memory/0x0067a7e4-0x0067a7e8.g_pRankingDialog.md) 0x0067a7e4-0x0067a7e8 | global pointer | g_pRankingDialog : reconstructable : 86% : strong : RankingDialog singleton pointer with current IDA name `g_pRankingDialog`, zero storage, 17 xrefs, constructor publish/guard clear, constructor-adjacent unwind clear, clear-helper/deleting-destructor clears, command-dispatch constructor edge at `0x005bd2ab`, ranking child/reward/packet consumers, saved singleton-helper IDA names, and RankingDialog parent attachment through [UID:0000S2][g_pRankingDialog](by-global/g_pRankingDialog.md) to [UID:0000MZ][RankingDialog](by-file/RankingDialog.md).
    - [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md) 0x0069b49c-0x0069b4a0 | global pointer | g_pNewHistoryDialog : reconstructable : 86% : strong : Exact four-byte NewHistoryDialog singleton slot with current C001 live IDA zeroed byte window, five direct xrefs, constructor publish/fallback clear, clear-helper/destructor clears, made-by scrolled-text close read, no direct constructor-start refs, saved IDA lifecycle function names, and parent route through [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md) to [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md).
    - [UID:0001PZ][0x0069ba34-0x0069ba38.g_pPowerDialog](by-memory/0x0069ba34-0x0069ba38.g_pPowerDialog.md) 0x0069ba34-0x0069ba38 | global pointer | g_pPowerDialog : reconstructable : 86% : strong : Exact four-byte PowerDialogPane singleton slot with current C001 live IDA zeroed byte window, five direct xrefs, constructor publish, cleanup and scalar-destructor clears, accessor read, embedded list mouse-handler read, MapPane constructor caller plus retained no-inbound wrapper caveat, saved IDA lifecycle/accessor function names, and parent route through [UID:0000S0][g_pPowerDialog](by-global/g_pPowerDialog.md) to [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md).
    - [UID:0002AO][0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots](by-memory/0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md) 0x0069bc0c-0x0069bc18 | global-data pointer cluster | SystemMessagePaneSingletonSlots : reconstructable : 86% : strong : Exact NewSystemMessageModifyHeightPane/NewSystemMessagePane singleton slots plus reviewed reserved dword; live IDA confirms current all-zero bytes, seven `g_pHeightModifyPane` xrefs, six `g_pNewSystemMessagePane` refs, no `0x0069bc14` refs, constructor/nested-constructor publish and fallback-null writes, cleanup/helper/destructor clears, saved NewSystemMessagePane lifecycle function names, and assignment to [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md).
```
## 2026-06-16 - C001-goal2-global-ida-refresh-staff-surface-packet-riding-20260616-10 closeout

Assignment targets:
- [UID:0000SC] `by-global/g_pStaffsDialog.md`
- [UID:0000QW] `by-global/g_pfnLockSurface.md`
- [UID:0000TG] `by-global/PacketTransformGlobals.md`
- [UID:0000TJ] `by-global/RidingDefinitionGlobalTable.md`

Leases used:
- Acquired: `by-global/g_pStaffsDialog.md`, `by-global/g_pfnLockSurface.md`, `by-global/PacketTransformGlobals.md`, `by-global/RidingDefinitionGlobalTable.md`, `by-global/-coverage-report.md`, `tools/leaser/Agents/Agent-C001/notes.md`.
- Release status: released after validation.

Changed files and scores:
- `by-global/g_pStaffsDialog.md`: `84/88` -> `86/90`.
  - Owner/emitter decision: retained canonical owner/emitter [UID:0000O3] `StaffsDialogPane`; reconstructable stays `TRUE`; C++ stays blank.
  - Evidence checked: live IDA `trace_data_flow backward 0x0069b490` showed exactly constructor publish `0x004ffaf6`, constructor null clear `0x004ffafd`, clear helper `0x00502410`, destructor clear `0x00502cc6`; `lookup_funcs` reconfirmed constructor/action/clear/destructor boundaries. Direct constructor reachability and source declaration placement remain real blockers after existing class/file review.
- `by-global/g_pfnLockSurface.md`: `84/88` -> `86/88`.
  - Owner/emitter decision: retained `RECONSTRUCTABLE:FALSE`, canonical owner `NONE`; keep as ignored generated alias over [UID:0000TN] `SurfaceRenderCallbackTable`, not as standalone global.
  - Evidence checked: live IDA decompiled `0x00499310` as `unk_69B3FC(this, this + 68)`; disassembly of `0x00558840` reconfirmed callback-table assignments including slot `0x0069b3fc` to `sub_4BE680`; lookup reconfirmed `sub_558840` size `0x723`, `sub_4BE680` size `0x6e7`, `sub_4C4380` size `0x340`; backward trace showed broad UI/render fanout. Final slot source name/signature remain parent-table blockers.
- `by-global/PacketTransformGlobals.md`: `85/87` -> `86/88`.
  - Owner/emitter decision: retained canonical owner/emitter [UID:0000M9] `PacketTransform`; reconstructable stays `TRUE`; C++ stays blank.
  - Evidence checked: live IDA traces reconfirmed `0x0066fe50` reads from raw string-key setup, nonce initialization, frame transform, and encrypted-packet paths; `0x0066fe58` dword LUT writes at `0x0057615f` and raw `0x00576fee`; `0x0069ba40` handshake replication by `BuildHandshakeBlock`; `0x0069ba58` Socket lifetime write/read/free and PacketTransform consumption. Final C declarations, capacities, and original file spelling versus private Socket section remain blockers.
- `by-global/RidingDefinitionGlobalTable.md`: `86/86` -> `87/88`.
  - Owner/emitter decision: retained canonical owner/emitter [UID:0000N6] `RidingImageLib`; reconstructable stays `TRUE`; C++ stays blank.
  - Evidence checked: live IDA trace reconfirmed `0x0069b430` refs from static init, `RIDINGS.DNA` loader, fallback helper, render fallback sites, raw fallback-like sites, and static shutdown; `0x0069b438` had exactly four loader refs; decompilation reconfirmed default group allocation/seeding and fallback return behavior. Final helper type and source-facing global variable name remain blockers.
- `by-global/-coverage-report.md`: synced the four target rows to the updated global pages.
- `tools/leaser/Agents/Agent-C001/notes.md`: this closeout entry.

IDA DB changes:
- Live server: `http://127.0.0.1:59280/mcp`, IDB `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; `server_health` reported `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- Dry-run rename batch: 11/11 accepted.
- Applied and saved 11 function renames:
  - `sub_4FFAA0` -> `StaffsDialogPane_Constructor`
  - `sub_4FFD20` -> `StaffsDialogPane_OnDialogAction`
  - `sub_502410` -> `StaffsDialogPane_ClearSingletonHelper`
  - `sub_502CC0` -> `StaffsDialogPane_ScalarDeletingDestructor`
  - `sub_575C30` -> `PacketTransform_ExpandProcessArgKeyText`
  - `sub_575CB0` -> `InitializePacketNonce`
  - `sub_577030` -> `BuildHandshakeBlock`
  - `sub_578E00` -> `XorTransformBuffer`
  - `sub_4DC420` -> `RidingImageLib_LoadRidingDefinitions`
  - `sub_4DCA20` -> `RidingImageLib_GetDefinitionOrDefault`
  - `sub_60C290` -> `RidingDefinitionGlobalTable_StaticDestructor`
- Save result: `idb_save` returned `ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Skipped IDA edits: data/global slot renames, type/member changes, callback-slot names/signatures, and destructor thunk names. Reason: final declaration/type/signature shape is still provisional or belongs to a parent-table/helper-family pass.

Validation commands/results:
- `python .\tools\validator.py --mode file --file by-global/g_pStaffsDialog.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-global/g_pfnLockSurface.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-global/PacketTransformGlobals.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-global/RidingDefinitionGlobalTable.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-global/-coverage-report.md --apply --queue-timeout 240`
- Results: all returned `ok:1`.

Supervisor-owned by-memory coverage rows:
- None. This batch changed only by-global docs/report and notes. No direct edits to `by-memory/-coverage-report.md` were made, and no replacement/insert/delete rows are pending.

## 2026-06-16 Assignment - C001-goal2-type-layout-ida-refresh-pursuit-item-light-20260616-11

Assigned targets:
- [UID:0001YI] `by-type/by-vtable/PursuitMessageDialogPaneVtables.md`
- [UID:0001UU] `by-type/by-struct/ItemObjImageLibLayout.md`
- [UID:0001UX] `by-type/by-struct/LightObjImageLibLayout.md`

Instructions:
- Read and follow `Agent-C001/goal.md`, current supervisor notes, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven type/layout plus safe IDA refresh pass from `project-level/-auto-completion-stats.md`. Raise each target where evidence supports it, including support docs and `by-type/-coverage-report.md` if needed, without inflating scores beyond the evidence.
- Use live IDA evidence and current docs to recheck vtable/data/layout offsets, constructor/destructor/data xrefs, owner/emitter routes, source placement, and final declaration blockers.
- Perform safe IDA database improvements only when evidence-backed and low risk. If no rename/comment/type/member/prototype edit is safe, document the exact skipped candidate and reason.
- Investigate every listed blocker instead of merely repeating it. Resolve it where supported; otherwise record the exact IDA/docs/metadata evidence checked and why it remains unsafe. Do not defer unresolved names/reachability/source-placement issues to final C++ without investigating.
- If any assigned target cannot be brought to or kept at `85/85+`, do additional research before returning; if it still cannot clear the gate, report the evidence and why the score must stay lower.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply. Non-memory coverage reports may be edited directly only under normal lease rules.
- Report changed files, leases, validations, before/after scores, owner/emitter decisions, blocker investigations, IDA DB changes/saves, and any exact pending supervisor-owned report rows.

## 2026-06-16 - C001-goal2-type-layout-ida-refresh-pursuit-item-light-20260616-11 closeout

Changed files and scores:
- `by-type/by-vtable/PursuitMessageDialogPaneVtables.md`: `82/88` -> `86/90`.
  - Owner/emitter decision: retained canonical owner/emitter [UID:0000LA] `MessageDialogs`; reconstructable stays `TRUE`; C++ stays blank.
  - Evidence checked: live IDA session `b001_maildialogs_0000ZO_20260616`; `server_health` ok for `NexusTK.exe.i64`; `lookup_funcs` still reports `0x0054cab0` not a function and confirms `0x0054caf0` size `0x13f`; `xrefs_to 0x00622428/0x00622488/0x006224b8` returned only raw constructor stores `0x0054cac8/0x0054cad0/0x0054cada`; `xrefs_to 0x0054caf0` returned the eight message/menu-dialog vtable refs. Blockers investigated: raw constructor promotion remains unsafe because current IDA still has no function object or direct constructor-start caller; final class/virtual source spelling remains below final-source confidence.
- `by-type/by-struct/ItemObjImageLibLayout.md`: `84/86` -> `86/89`.
  - Owner/emitter decision: retained canonical owner/emitter [UID:00006W] `ItemObjImageLib`; reconstructable stays `TRUE`; C++ stays blank.
  - Evidence checked: live constructor decompilation confirmed class vtable at `+0x00`, `ProtectedArray<ItemInfo>` at `+0x04`, `+0x08/+0x0c/+0x10` header fields, fallback row at `+0x14`, and `20 * count` item-row allocation; table-loader and scalar destructor decompilation agreed on `this+0x08/+0x0c/+0x14`; xrefs reconfirmed `0x0061b73c`, `0x0061b734`, and 65 singleton refs to `0x0067a758`. Blockers investigated: final `ItemInfo` field names and header/source declaration spelling remain provisional, so no final C++ or type/member edits were made.
- `by-type/by-struct/LightObjImageLibLayout.md`: `84/86` -> `86/90`.
  - Owner/emitter decision: retained canonical owner/emitter [UID:000076] `LightObjImageLib`; reconstructable stays `TRUE`; C++ stays blank.
  - Evidence checked: live constructor decompilation confirmed class vtable at `+0x00`, `ProtectedArray<LightInfo>` at `+0x04`, `+0x08/+0x0c/+0x10` header fields, fallback constants copied to `+0x14`, and `28 * count` allocation; bounds/draw methods use `base + 28 * index` or `this+0x14`, generated-frame pointer at row `+0x18`, and blend modes `1`/`2`; xrefs reconfirmed `0x0061b754`, `0x0061b74c`, and 19 singleton refs to `0x0069b450`. Blockers investigated: final first-two `LightInfo` field names, helper names, and declaration spelling remain provisional, so no final C++ or type/member edits were made.
- `by-global/g_pItemObjImageLib.md`: `88/88` -> `88/89`.
  - Owner/emitter decision: retained canonical owner/emitter [UID:0000KH] `ItemObjImageLib`; reconstructable stays `TRUE`; C++ stays blank.
  - Evidence checked: 65-ref singleton map, constructor publish/guard clear, raw destructor clear, singleton clear helper, scalar destructor clear, startup/shutdown and broad UI consumers. IDA storage label now matches canonical name.
- `by-global/g_pLightObjImageLib.md`: `86/88` -> `87/89`.
  - Owner/emitter decision: retained canonical owner/emitter [UID:0000KP] `LightObjImageLib`; reconstructable stays `TRUE`; C++ stays blank.
  - Evidence checked: 19-ref singleton map, startup-only construction, raw ordinary-destructor clear, singleton clear helper, scalar destructor clear, Application shutdown read, attached-object/light render consumers, and raw non-function refs. IDA storage label now matches canonical name; Application alias and Wave3 global-data range omission remain real blockers.
- `by-type/by-vtable/-coverage-report.md`: synced the `PursuitMessageDialogPaneVtables` row.
- `by-type/by-struct/-coverage-report.md`: synced `ItemObjImageLibLayout` and `LightObjImageLibLayout` rows.
- `by-global/-coverage-report.md`: synced `g_pItemObjImageLib` and `g_pLightObjImageLib` rows.
- `tools/leaser/Agents/Agent-C001/notes.md`: this closeout entry.

Leases used:
- Acquired: `by-type/by-vtable/PursuitMessageDialogPaneVtables.md`, `by-type/by-struct/ItemObjImageLibLayout.md`, `by-type/by-struct/LightObjImageLibLayout.md`, `by-type/by-vtable/-coverage-report.md`, `by-type/by-struct/-coverage-report.md`, `by-global/g_pItemObjImageLib.md`, `by-global/g_pLightObjImageLib.md`, `by-global/-coverage-report.md`, and `tools/leaser/Agents/Agent-C001/notes.md`.
- Release status: target/report leases expired naturally during validation; release attempt after validation returned `Rejected[No active lease]` for those paths. Notes was re-leased briefly to record this final status, then released.

IDA DB changes:
- Dry-run rename batch: 11/11 accepted.
- Applied and saved 9 function renames:
  - `sub_54CAF0` -> `MessageDialogObjectResponseVirtual`
  - `sub_4DEC30` -> `ItemObjImageLibConstructor`
  - `sub_4DF500` -> `ItemObjImageLibLoadItemInfoTable`
  - `sub_4E6580` -> `ItemObjImageLibScalarDeletingDestructor`
  - `sub_4DF7E0` -> `LightObjImageLibConstructor`
  - `sub_4DFB40` -> `LightObjImageLibGetLightBounds`
  - `sub_4DFBB0` -> `LightObjImageLibDrawLightMode1`
  - `sub_4DFC60` -> `LightObjImageLibDrawLightMode2`
  - `sub_4E65E0` -> `LightObjImageLibScalarDeletingDestructor`
- Applied and saved 2 data renames:
  - `dword_67A758` -> `g_pItemObjImageLib`
  - `unk_69B450` -> `g_pLightObjImageLib`
- Save result: `idb_save` returned `ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Skipped IDA edits: raw constructor/destructor function creation at `0x0054cab0`, `0x004dee20`, `0x004df670`, and `0x004dfab0`; type/member layout edits; prototypes; inherited/shared slot `0x004f4b10`; final field names. Reason: current IDA still reports raw starts as non-functions or final declaration/source names remain provisional.

Validation commands/results:
- `python .\tools\validator.py --mode file --file by-type/by-vtable/PursuitMessageDialogPaneVtables.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-type/by-struct/ItemObjImageLibLayout.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-type/by-struct/LightObjImageLibLayout.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-global/g_pItemObjImageLib.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-global/g_pLightObjImageLib.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-type/by-vtable/-coverage-report.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-type/by-struct/-coverage-report.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-global/-coverage-report.md --apply --queue-timeout 240`
- Results: sequential validator loop exited `0`; each changed by-* target/report reached `ok: 1`. The first target validation recorded completion/confidence updates for [UID:0001YI] and removed it from the generated stats list; follow-up validations updated validator/autogen metadata and reports without blocking errors.

Supervisor-owned by-memory coverage rows:
- None. No direct edits were made to `by-memory/-coverage-report.md`, and this pass changed no by-memory docs or scores requiring supervisor-owned memory coverage replacement rows.

## 2026-06-16 - C001-goal2-global-ida-refresh-browser-fps-gameserver-20260616-15 final checkpoint

Changed files and scores:
- `by-global/g_activeBrowserControlPane.md`: `86/86` -> `88/90`; owner/emitter retained [UID:0000HV] `Browser`; C++ blank. Live IDA reconfirmed zero bytes, 24 xrefs, BrowserControlPane lifecycle writers, accelerator consumer, and application/presentation readers.
- `by-global/g_fpsDebugActive.md`: `86/86` -> `87/89`; owner/emitter retained [UID:0000JK] `FpsPane`; C++ blank. Live IDA reconfirmed initialized dword `01 00 00 00`, exactly four raw FpsPane refs, and raw helper no-function status.
- `by-global/g_fpsLogEnabled.md`: `86/86` -> `88/90`; owner/emitter retained [UID:0000JK] `FpsPane`; C++ blank. Live IDA reconfirmed exact byte neighborhood, exactly four raw FpsPane refs, start-session log gate, and summary early-exit gate.
- `by-global/g_gameServerNationTable.md`: `86/86` -> `88/89`; owner/emitter retained [UID:0000JP] `GameServerConfig`; C++ blank. Live IDA reconfirmed zero bytes, 18 xrefs, modeled lookup/request/map lifecycle/destructor helpers, and raw no-function constructor/destructor islands.
- Support docs updated without score changes: `by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md` (`86/89`), `by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md` (`86/88`), `by-memory/0x0069b338-0x0069b339.g_fpsLogEnabled.md` (`88/90`), and `by-memory/0x0069b4c4-0x0069b4c8.g_gameServerNationTable.md` (`86/86`).
- `by-global/-coverage-report.md`: synced the four global rows.

IDA DB changes:
- Applied/saved 10 function renames: `sub_46B520` -> `BrowserControlPaneConstructor`; `sub_46B990` -> `BrowserControlPaneDestructor`; `sub_46C550` -> `BrowserControlPaneTranslateAcceleratorMessage`; `sub_470210` -> `ClearActiveBrowserControlPane`; `sub_470410` -> `BrowserControlPaneScalarDeletingDestructor`; `sub_503A80` -> `GameServerConfigCopyNationEntryOrFallback`; `sub_503C70` -> `GameServerConfigRequestNationEntries`; `sub_504110` -> `MapPaneInitialize`; `sub_504530` -> `MapPaneCleanup`; `sub_514D80` -> `GameServerConfigScalarDeletingDestructor`.
- Applied/saved 4 data renames: `unk_67AB28` -> `g_activeBrowserControlPane`; `dword_66DA90` -> `g_fpsDebugActive`; `unk_69B338` -> `g_fpsLogEnabled`; `unk_69B4C4` -> `g_gameServerNationTable`.
- Save result: `idb_save` returned `ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Skipped unsafe IDA edits: raw function creation/renames at `0x004b64a0`, `0x004b69b0`, `0x004b6ae0`, `0x005039f0`, and `0x00503a50`; Browser presentation helper `0x0046bfd0`; type/member/prototype edits.

Validations:
- Ran `python .\tools\validator.py --mode file --file <changed-by-star-file> --apply --queue-timeout 240` for the four globals, four memory support pages, and `by-global/-coverage-report.md`; sequential loop exited `0`, each changed by-* file/report reached `ok: 1`.

Leases and pending rows:
- Leases acquired for the four globals, four support memory pages, `by-global/-coverage-report.md`, and C001 `notes.md`. Initial unlease attempt found the target/report leases already cleared (`Rejected[No active lease]`); final notes lease released successfully. Current lease report showed no active C001 leases.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none. No by-memory scores changed and the banned report was not edited.

## 2026-06-16 - C001-goal2-global-ida-refresh-browser-fps-gameserver-20260616-15 closeout

Changed files and scores:
- `by-global/g_activeBrowserControlPane.md`: `86/86` -> `88/90`.
  - Owner/emitter decision: retained canonical owner/emitter [UID:0000HV] `Browser`; reconstructable stays `TRUE`; C++ stays blank.
  - Evidence checked: live IDA MCP session `b001_selflookpane_0001H7_20260616`; `server_health` ok for `NexusTK.exe.i64`; `get_bytes 0x0067ab28` returned `00 00 00 00`; `xrefs_to 0x0067ab28` reconfirmed 24 refs across browser constructor/destructor, application guards, accelerator, and presentation consumers; decompilation verified constructor publish/null path, destructor/scalar destructor clears, one-line clear helper, and accelerator-message behavior. Remaining blocker: final exported declaration/accessor and `0x0046bfd0` presentation helper source-facing name.
- `by-global/g_fpsDebugActive.md`: `86/86` -> `87/89`.
  - Owner/emitter decision: retained canonical owner/emitter [UID:0000JK] `FpsPane`; reconstructable stays `TRUE`; C++ stays blank.
  - Evidence checked: live IDA bytes around `0x0066da88` reconfirmed initialized dword value `01 00 00 00`; `xrefs_to 0x0066da90` returned exactly four raw FpsPane refs at `0x004b64e5`, `0x004b65f5`, `0x004b69bd`, and `0x004b6acd`; `lookup_funcs`/disassembly reconfirmed `0x004b64a0`, `0x004b69b0`, and `0x004b6ae0` are still not modeled functions. Remaining blocker: raw helper liveness and exact source declaration type (`int` vs source `bool` stored as dword).
- `by-global/g_fpsLogEnabled.md`: `86/86` -> `88/90`.
  - Owner/emitter decision: retained canonical owner/emitter [UID:0000JK] `FpsPane`; reconstructable stays `TRUE`; C++ stays blank.
  - Evidence checked: live IDA bytes around `0x0069b334` reconfirmed the local zero byte neighborhood in the active IDB; `xrefs_to 0x0069b338` returned exactly four raw FpsPane refs at `0x004b653f`, `0x004b6645`, `0x004b6a17`, and `0x004b6ae4`; disassembly reconfirmed the start-session log gate and summary early-exit gate while raw helper starts remain non-functions. Remaining blocker: raw helper liveness and final declaration type.
- `by-global/g_gameServerNationTable.md`: `86/86` -> `88/89`.
  - Owner/emitter decision: retained canonical owner/emitter [UID:0000JP] `GameServerConfig`; reconstructable stays `TRUE`; C++ stays blank.
  - Evidence checked: live IDA `get_bytes 0x0069b4c4` returned `00 00 00 00`; `xrefs_to 0x0069b4c4` reconfirmed 18 refs across raw constructor/destructor writes, `MapPaneInitialize`, `MapPaneCleanup`, scalar destructor clear, and user/status/request/copy consumers; `lookup_funcs` reconfirmed raw no-function starts at `0x005039f0` and `0x00503a50`; decompilation verified lookup/fallback, request packet, map cleanup, and scalar destructor behavior. Remaining blocker: raw starts plus final `GameServerConfig.cpp` versus private `MapPane.cpp` source split/type spelling.
- Support docs updated without score changes: `by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md` (`86/89`), `by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md` (`86/88`), `by-memory/0x0069b338-0x0069b339.g_fpsLogEnabled.md` (`88/90`), and `by-memory/0x0069b4c4-0x0069b4c8.g_gameServerNationTable.md` (`86/86`) were refreshed to match saved IDA labels/current evidence.
- `by-global/-coverage-report.md`: synced the four changed global rows.
- Validator-applied generated side effects: projected stats/autogen coverage regenerated during `--apply`; these were not manually edited.
- `tools/leaser/Agents/Agent-C001/notes.md`: this closeout entry.

Leases used:
- Acquired: the four target globals, the four direct by-memory support pages, `by-global/-coverage-report.md`, and `tools/leaser/Agents/Agent-C001/notes.md`.
- Release status: post-validation unlease attempt returned `Rejected[No active lease]` for each C001 path; follow-up `current_leases.md` showed no active C001 leases, so the paths were already clear. Notes was re-leased only to record this status.

IDA DB changes:
- Dry-run rename batch accepted 14/14 candidates.
- Applied and saved 10 function renames:
  - `sub_46B520` -> `BrowserControlPaneConstructor`
  - `sub_46B990` -> `BrowserControlPaneDestructor`
  - `sub_46C550` -> `BrowserControlPaneTranslateAcceleratorMessage`
  - `sub_470210` -> `ClearActiveBrowserControlPane`
  - `sub_470410` -> `BrowserControlPaneScalarDeletingDestructor`
  - `sub_503A80` -> `GameServerConfigCopyNationEntryOrFallback`
  - `sub_503C70` -> `GameServerConfigRequestNationEntries`
  - `sub_504110` -> `MapPaneInitialize`
  - `sub_504530` -> `MapPaneCleanup`
  - `sub_514D80` -> `GameServerConfigScalarDeletingDestructor`
- Applied and saved 4 data renames:
  - `unk_67AB28` -> `g_activeBrowserControlPane`
  - `dword_66DA90` -> `g_fpsDebugActive`
  - `unk_69B338` -> `g_fpsLogEnabled`
  - `unk_69B4C4` -> `g_gameServerNationTable`
- Save result: `idb_save` returned `ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Skipped IDA edits: raw function creation/renames at `0x004b64a0`, `0x004b69b0`, `0x004b6ae0`, `0x005039f0`, and `0x00503a50`; Browser presentation helper `0x0046bfd0`; type/member/prototype edits. Reason: raw starts are still not modeled functions/no direct liveness proof, and the remaining helper/type/source-split names are still provisional.

Validation commands/results:
- `python .\tools\validator.py --mode file --file by-global/g_activeBrowserControlPane.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-global/g_fpsDebugActive.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-global/g_fpsLogEnabled.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-global/g_gameServerNationTable.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory/0x0069b338-0x0069b339.g_fpsLogEnabled.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory/0x0069b4c4-0x0069b4c8.g_gameServerNationTable.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-global/-coverage-report.md --apply --queue-timeout 240`
- Results: sequential validator loop exited `0`; each changed by-* target/support/report reached `ok: 1`.

Supervisor-owned by-memory coverage rows:
- None. No direct edit was made to `by-memory/-coverage-report.md`, and support by-memory score rows were not changed in this pass.

## 2026-06-16 Assignment - C001-goal2-global-ida-refresh-browser-fps-gameserver-20260616-15

Assigned targets:
- [UID:0000PO] `by-global/g_activeBrowserControlPane.md`
- [UID:0000PY] `by-global/g_fpsDebugActive.md`
- [UID:0000PZ] `by-global/g_fpsLogEnabled.md`
- [UID:0000Q1] `by-global/g_gameServerNationTable.md`

Instructions:
- Read and follow `Agent-C001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven global-storage plus safe IDA refresh pass from refreshed `project-level/-auto-completion-stats.md`.
- Recheck storage addresses, initial bytes, direct xrefs, constructor/destructor/lifecycle writes, consumer reads, owner/emitter routes, parent/support scores, source-placement, final declaration/type blockers, and stale generated-owner pollution. Raise each target and directly supporting page where evidence supports it, including support docs and coverage rows, without inflating scores beyond the evidence.
- Apply only evidence-backed low-risk IDA improvements, such as confirmed global labels or function renames already supported by documentation and xrefs. If no rename/comment/type/member/prototype edit is safe, document the exact skipped candidate and reason.
- Investigate every listed blocker instead of repeating it. Resolve field/type/global/helper-name, caller/reachability, ownership, source-placement, split/merge/range, and final-C++ blockers where supported; otherwise record the exact IDA/docs/metadata evidence checked and why the issue remains unsafe.
- Do not defer source-quality blockers to final C++ without investigating them during this evidence pass. The 85/85 gate is a minimum, not a stopping point.
- If any target becomes heavy source-structure inference or ambiguous original-source ownership rather than evidence-backed global/layout refresh, document the checked evidence and recommend B-agent escalation.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply. Non-memory coverage reports may be edited directly only under normal lease rules.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes/saves, and any exact pending supervisor-owned report rows.
## 2026-06-16 Assignment - C001-goal2-type-layout-ida-refresh-codec-cache-registry-20260616-12

Assigned targets:
- [UID:0001TS] `by-type/by-struct/BinaryCodecCursorLayout.md`
- [UID:0001TU] `by-type/by-struct/CachedHashTableLayout.md`
- [UID:0001VR] `by-type/by-struct/RegistryConfigUserProfileBlock.md`

Instructions:
- Read and follow `Agent-C001/goal.md`, current supervisor notes, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven type/layout plus safe IDA refresh pass from refreshed `project-level/-auto-completion-stats.md`.
- Recheck offsets, constructor/destructor/helper xrefs, owner/emitter routes, source placement, and final declaration blockers. Raise each target and directly supporting page where evidence supports it, including support docs and coverage rows, without inflating scores beyond the evidence.
- Apply only evidence-backed low-risk IDA improvements; if no rename/comment/type/member/prototype edit is safe, document the exact skipped candidate and reason.
- Investigate every listed blocker instead of repeating it. Resolve field/type/global/protocol/helper-name, caller/reachability, ownership, source-placement, split/merge/range, and final-C++ blockers where supported; otherwise record the exact IDA/docs/metadata evidence checked and why the issue remains unsafe.
- Do not defer source-quality blockers to final C++ without investigating them during this evidence pass.
- If any assigned target cannot be brought to or kept at `85/85+`, do additional research before returning; if it still cannot clear the gate, report the evidence and why the score must stay lower.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply. Non-memory coverage reports may be edited directly only under normal lease rules.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes/saves, and any exact pending supervisor-owned report rows.

## 2026-06-16 - C001-goal2-type-layout-ida-refresh-changeman-datindex-20260616-13 closeout

Changed files and scores:
- `by-type/by-struct/ChangeManEntry.md`: `82/90` -> `85/90`.
  - Owner/emitter decision: retained canonical owner/emitter [UID:00001K] `ChangeMan`; reconstructable stays `TRUE`; C++ stays blank.
  - Evidence checked: live IDA session `b001_selflookpane_0001H7_20260616`; `server_health` ok for `NexusTK.exe.i64`; `lookup_funcs` and decompilation reconfirmed `ChangeMan_Register`, `ChangeMan_UnregisterFiltered`, `ChangeMan_DispatchMessage`, and `CompareChangeEntries`; `xrefs_to` reconfirmed one Application wrapper caller for each register/unregister/dispatch path and one constructor data ref to the comparator. Blockers investigated: listener interface name, `scope` enum spelling, and `Message::m_type` final field name remain source-provisional, so no IDA type/member/prototype edit and no C++ were added.
- `by-type/by-struct/ChangeManLayout.md`: `82/90` -> `85/90`.
  - Owner/emitter decision: retained canonical owner/emitter [UID:00001K] `ChangeMan`; reconstructable stays `TRUE`; C++ stays blank.
  - Evidence checked: live IDA reconfirmed constructor/destructor/register/unregister/dispatch/broad unregister/comparator/singleton-clear helper sizes and the 11-ref `g_pChangeMan` lifecycle/consumer set. Constructor/decompilation verifies the 8-byte object, LObject/vtable base, `+0x04` `SortedList*`, `SortedList(16, CompareChangeEntries, 100)`, and destructor list/global cleanup. Blockers investigated: final `SortedList` declaration, listener API, public method signatures, and helper/header split remain below source-quality confidence.
- `by-type/by-struct/DATIndexVectorBucket.md`: `82/90` -> `85/90`.
  - Owner/emitter decision: retained canonical owner/emitter [UID:00003K] `DATIndexVector`; reconstructable stays `TRUE`; C++ stays blank.
  - Evidence checked: live IDA reconfirmed `DATIndexVectorInsertNode`, `DATIndexVectorRemoveNodeHelper`, `DATIndexVectorDestructor`, `DATIndexVectorFindNodeByKey`, and `DATIndexVectorResizeAndFill`; `xrefs_to` shows MiniMap, MonsterImageLib, self-rehash, and single cleanup-edge caller spread; decompilation reconfirmed bucket table at object `+0x0c`, 8-byte bucket stride, `first`/`last`, sentinel empty-state writes, removal first/last repairs, and lookup end from `last->next`. Blockers investigated: no current caller proves public header visibility or a more generic original type name, so type/member edits and final C++ remain unsafe.
- `by-class/ChangeMan.md`: `84/88` -> `85/89`.
  - Owner/emitter decision: retained canonical owner [UID:0000I2] `ChangeMan` file and emitter [UID:0000I2]; reconstructable stays `TRUE`; C++ stays blank.
  - Evidence checked: same live IDA pass as above plus file/class/memory/global support docs. The direct class parent now clears strict `85/85`, supporting the two ChangeMan struct pages' existing class-owner route.
- `by-type/by-struct/-coverage-report.md`: synced `ChangeManEntry`, `ChangeManLayout`, and `DATIndexVectorBucket` rows.
- `by-class/-coverage-report.md`: synced `ChangeMan` row.
- `project-level/-auto-completion-stats.md`: validator-applied generated side effect; [UID:0001TV], [UID:0001TW], and [UID:0001U0] no longer appear in the low-score stats after validation.
- `tools/leaser/Agents/Agent-C001/notes.md`: this closeout entry.

Leases used:
- Acquired: `by-type/by-struct/ChangeManEntry.md`, `by-type/by-struct/ChangeManLayout.md`, `by-type/by-struct/DATIndexVectorBucket.md`, `by-class/ChangeMan.md`, `by-type/by-struct/-coverage-report.md`, `by-class/-coverage-report.md`, and `tools/leaser/Agents/Agent-C001/notes.md`.
- Release status: all C001 leases released successfully after validation and notes update.

IDA DB changes:
- Dry-run rename batch accepted 18/18 candidates.
- Applied and saved 17 function renames:
  - `sub_47EC70` -> `ChangeMan_Constructor`
  - `sub_47ED50` -> `ChangeMan_Register`
  - `sub_47ED80` -> `ChangeMan_UnregisterFiltered`
  - `sub_47EE20` -> `ChangeMan_DispatchMessage`
  - `sub_47EEA0` -> `ChangeMan_UnregisterObject`
  - `sub_47EF20` -> `CompareChangeEntries`
  - `sub_47EF40` -> `ClearChangeManSingleton`
  - `sub_47EF50` -> `ChangeMan_ScalarDeletingDestructor`
  - `sub_4F4B30` -> `ApplicationRegisterChangeListener`
  - `sub_4F4B50` -> `ApplicationUnregisterChangeListener`
  - `sub_4F4B70` -> `ApplicationForwardMessage`
  - `sub_4233F0` -> `DATIndexVectorFillValueRangeHelper`
  - `sub_423B00` -> `DATIndexVectorResizeAndFill`
  - `sub_457100` -> `DATIndexVectorInsertNode`
  - `sub_457310` -> `DATIndexVectorRemoveNodeHelper`
  - `sub_4573D0` -> `DATIndexVectorDestructor`
  - `sub_457580` -> `DATIndexVectorFindNodeByKey`
- Applied and saved 1 data rename:
  - `unk_67AB2C` -> `g_pChangeMan`
- Save result: `idb_save` returned `ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Skipped IDA edits: struct/member declarations for `ChangeManEntry`, `ChangeManLayout`, and `DATIndexVectorBucket`; function prototypes; `SortedList` helper names; CRT/free helpers. Reason: final listener/message API, `scope` enum, `SortedList` declaration, DATIndexVector public/private header visibility, and generic-vs-DAT type spelling remain provisional.

Validation commands/results:
- `python .\tools\validator.py --mode file --file by-type/by-struct/ChangeManEntry.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-type/by-struct/ChangeManLayout.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-type/by-struct/DATIndexVectorBucket.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-class/ChangeMan.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-type/by-struct/-coverage-report.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-class/-coverage-report.md --apply --queue-timeout 240`
- Results: sequential validator loop exited `0`; each changed by-* target/support/report reached `ok: 1`. Validator `--apply` removed the three assigned type rows from low-score stats and reported generated coverage autogen noops/unchanged rows.

Supervisor-owned by-memory coverage rows:
- None. No direct edits were made to `by-memory/-coverage-report.md`, and this pass changed no by-memory docs or scores requiring supervisor-owned memory coverage replacement rows.

## 2026-06-16 - C001-goal2-type-layout-ida-refresh-codec-cache-registry-20260616-12 closeout

Changed files and scores:
- `by-type/by-struct/BinaryCodecCursorLayout.md`: `82/90` -> `85/90`.
  - Owner/emitter decision: retained canonical owner/emitter [UID:0000HQ] `BinaryCodec`; reconstructable stays `TRUE`; C++ stays blank.
  - Evidence checked: live IDA session `b001_selflookpane_0001H7_20260616`; `server_health` ok for `NexusTK.exe.i64`; `lookup_funcs` reconfirmed modeled Encoder lifecycle/writer/finalize functions and Decoder lifecycle/glue functions; all raw Decoder reader starts from `0x004a5680` through `0x004a5db0` remain `Not a function`; `xrefs_to` reconfirmed only vtable-store refs and direct `Encoder::Initialize` / `Finalize` calls from `EncodeTextEditState_0058E490`. Blockers investigated: raw Decoder promotion remains unsafe because there are still no IDA functions or direct xrefs; final `sizeof`/tail padding and shared-header vs separate-header split remain unproven.
- `by-type/by-struct/CachedHashTableLayout.md`: `82/90` -> `85/90`.
  - Owner/emitter decision: retained canonical owner/emitter [UID:0000HZ] `CachedHashTable`; reconstructable stays `TRUE`; C++ stays blank.
  - Evidence checked: live IDA confirmed constructor `0x004c6160` size `0xf9`, destructor `0x004c6260` size `0x6e`, count accessors `0x004c64b0/0x004c64c0` as exact `0x4`-byte functions, scalar deleting destructor `0x004c64f0`, raw helper starts `0x004c62d0/0x004c63d0/0x004c63f0/0x004c6420/0x004c6450/0x004c64d0` as non-functions, zero xrefs to constructor/destructor/raw helpers/accessors, and vtable-only refs through `0x0061aac4`. Blockers investigated: final field names, raw-helper splitting/inlining, public signatures, and live construction remain unresolved because caller recovery still finds no live constructor/helper callers.
- `by-type/by-struct/RegistryConfigUserProfileBlock.md`: `85/86` -> `87/88`.
  - Owner/emitter decision: retained canonical owner/emitter [UID:0000BW] `RegistryConfig`; reconstructable stays `TRUE`; C++ stays blank.
  - Evidence checked: live IDA reconfirmed `RegistryConfig_InitializeUserDataDefaults`, `LoadUserProfileData`, `SaveUserSettings`, `RefreshSelectedProfileData`, macro dialog/edit-control consumers, and `LivingObjectPane_ExecuteHotkeyAction`; existing [UID:0000HS] `BlockListenInputPanes` and [UID:0001MW] memory aggregate resolve the `+0x2918fc/+0x291900/+0x291904` dynamic vector role as block-listen names. Blockers investigated: exact source-facing names for fixed profile strings, small string slots, adjacent chat-color bytes, block-listen member spelling, and `0x005a4530`/`0x005a3e30` dispatch helper names remain below final-source confidence.
- `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`: score unchanged `86/90`.
  - Support update only: changed the current IDA-name wording to `g_pConfig` and logged the IDA rename. No by-memory coverage row change is required because the existing row already names `g_pConfig` and the score did not change.
- `by-type/by-struct/-coverage-report.md`: synced rows for `BinaryCodecCursorLayout`, `CachedHashTableLayout`, and `RegistryConfigUserProfileBlock`.
- `project-level/-auto-completion-stats.md`: validator-applied projected stats update; [UID:0001TS] dropped from the generated low-score list after clearing the gate.
- `tools/leaser/Agents/Agent-C001/notes.md`: this closeout entry.

Leases used:
- Acquired: `by-type/by-struct/BinaryCodecCursorLayout.md`, `by-type/by-struct/CachedHashTableLayout.md`, `by-type/by-struct/RegistryConfigUserProfileBlock.md`, `by-type/by-struct/-coverage-report.md`, `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`, and `tools/leaser/Agents/Agent-C001/notes.md`.
- Release status: released all target/report/support leases successfully after validation; notes was re-leased for this final status update and then released.

IDA DB changes:
- Dry-run rename batch: 28/28 function renames accepted; separate data dry-run for `dword_67A7C8 -> g_pConfig` accepted.
- Applied and saved 28 function renames:
  - `sub_4A4E70` -> `Encoder_Constructor`
  - `sub_4A4EA0` -> `Encoder_Destructor`
  - `sub_4A4EC0` -> `Encoder_WriteByte`
  - `sub_4A4F00` -> `Encoder_WriteShort`
  - `sub_4A4FF0` -> `Encoder_WriteInt`
  - `sub_4A5480` -> `Encoder_WriteBytes`
  - `sub_4A55C0` -> `Encoder_Initialize`
  - `sub_4A55E0` -> `Encoder_Finalize`
  - `sub_4A5640` -> `Decoder_Constructor`
  - `sub_4A5670` -> `Decoder_Destructor`
  - `sub_4A5DD0` -> `Decoder_Finalize`
  - `sub_4A5E00` -> `Decoder_ScalarDeletingDestructor`
  - `sub_4A5E30` -> `Encoder_ScalarDeletingDestructor`
  - `sub_4C6160` -> `CachedHashTable_Constructor`
  - `sub_4C6260` -> `CachedHashTable_Destructor`
  - `sub_4C64B0` -> `CachedHashTable_GetSlotCount`
  - `sub_4C64C0` -> `CachedHashTable_GetEntryCount`
  - `sub_4C64F0` -> `CachedHashTable_ScalarDeletingDestructor`
  - `sub_48EBC0` -> `RegistryConfig_InitializeUserDataDefaults`
  - `sub_4F9280` -> `ImportLegacyUserProfileData`
  - `sub_4F95B0` -> `LoadUserProfileData`
  - `sub_50ABA0` -> `SaveUserSettings`
  - `sub_5063E0` -> `RefreshSelectedProfileData`
  - `sub_5421F0` -> `IntegrateMacroDialog_RefreshMacroEditFields`
  - `sub_57FF60` -> `IntegrateMacroEditControlPane_SetMacroData`
  - `sub_580320` -> `IntegrateMacroEditControlPane_OnKeyEvent`
  - `sub_5805E0` -> `IntegrateMacroEditControlPane_SyncEditControl`
  - `sub_5A3AE0` -> `LivingObjectPane_ExecuteHotkeyAction`
- Applied and saved 1 data rename:
  - `dword_67A7C8` -> `g_pConfig`
- Save result: `idb_save` returned `ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Skipped IDA edits: raw Decoder reader function creation/renames, `CachedHashTable` raw helper function creation/renames, member/type/prototype declarations, and `0x005a4530`/`0x005a3e30` dispatch helper renames. Reason: current IDA still reports raw starts as non-functions or final helper/member names remain provisional/cross-owner.

Validation commands/results:
- `python .\tools\validator.py --mode file --file by-type/by-struct/BinaryCodecCursorLayout.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-type/by-struct/CachedHashTableLayout.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-type/by-struct/RegistryConfigUserProfileBlock.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-type/by-struct/-coverage-report.md --apply --queue-timeout 240`
- Results: sequential validator loop exited `0`; each changed by-* target/support/report reached `ok: 1`. Validator `--apply` updated canonical owner/emitter metadata on `g_pConfig`, removed [UID:0001TS] from the generated stats list after it cleared the low-score threshold, and regenerated/synced broader rows in `by-type/by-struct/-coverage-report.md` plus `project-level/-auto-completion-stats.md` projected stats metadata.

Supervisor-owned by-memory coverage rows:
- None. No direct edits were made to `by-memory/-coverage-report.md`; the only changed by-memory support doc kept score `86/90`, and the current memory coverage row already uses `g_pConfig`.
## 2026-06-16 Assignment - C001-goal2-type-layout-ida-refresh-changeman-datindex-20260616-13

Assigned targets:
- [UID:0001TV] `by-type/by-struct/ChangeManEntry.md`
- [UID:0001TW] `by-type/by-struct/ChangeManLayout.md`
- [UID:0001U0] `by-type/by-struct/DATIndexVectorBucket.md`

Instructions:
- Read and follow `Agent-C001/goal.md`, current supervisor notes, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven type/layout plus safe IDA refresh pass from refreshed `project-level/-auto-completion-stats.md`.
- Recheck field offsets, object sizes, constructor/destructor/helper xrefs, comparator behavior, bucket insert/remove/find behavior, sentinel handling, owner/emitter routes, parent/support scores, source placement, and final declaration blockers. Raise each target and directly supporting page where evidence supports it, including support docs and coverage rows, without inflating scores beyond the evidence.
- Apply only evidence-backed low-risk IDA improvements; if no rename/comment/type/member/prototype edit is safe, document the exact skipped candidate and reason.
- Investigate every listed blocker instead of repeating it. Resolve field/type/global/protocol/helper-name, caller/reachability, ownership, source-placement, split/merge/range, and final-C++ blockers where supported; otherwise record the exact IDA/docs/metadata evidence checked and why the issue remains unsafe.
- Do not defer source-quality blockers to final C++ without investigating them during this evidence pass.
- If any assigned target cannot be brought to or kept at `85/85+`, do additional research before returning; if it still cannot clear the gate, report the evidence and why the score must stay lower.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply. Non-memory coverage reports may be edited directly only under normal lease rules.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes/saves, and any exact pending supervisor-owned report rows.

## 2026-06-16 Assignment - C001-goal2-type-template-layout-ida-refresh-functionobject-autobuf-button-20260616-14

Assigned targets:
- [UID:0001WQ] `by-type/by-template/FunctionObjectTemplates.md`
- [UID:0001WN] `by-type/by-template/AUTOBUF_unsigned_char.md`
- [UID:0001W7] `by-type/by-struct/SpecializedButtonPaneLayouts.md`

Instructions:
- Read and follow `Agent-C001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven type/template/layout plus safe IDA refresh pass from refreshed `project-level/-auto-completion-stats.md`.
- Recheck template instantiation evidence, field offsets, vtable/helper xrefs, caller behavior, owner/emitter routes, parent/support scores, source placement, and final declaration blockers. Raise each target and directly supporting page where evidence supports it, including support docs and coverage rows, without inflating scores beyond the evidence.
- Apply only evidence-backed low-risk IDA improvements; if no rename/comment/type/member/prototype edit is safe, document the exact skipped candidate and reason.
- Investigate every listed blocker instead of repeating it. Resolve field/type/global/protocol/helper-name, caller/reachability, ownership, source-placement, split/merge/range, and final-C++ blockers where supported; otherwise record the exact IDA/docs/metadata evidence checked and why the issue remains unsafe.
- Do not defer source-quality blockers to final C++ without investigating them during this evidence pass. The 85/85 gate is a minimum, not a stopping point.
- If any assigned target cannot be brought to or kept at `85/85+`, do additional research before returning; if it still cannot clear the gate, report the evidence and why the score must stay lower.
- If original source template/header reconstruction becomes heavy heuristic work rather than evidence-backed type/layout refresh, document the checked evidence and recommend B-agent escalation.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply. Non-memory coverage reports may be edited directly only under normal lease rules.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes/saves, and any exact pending supervisor-owned report rows.

## 2026-06-16 - C001-goal2-type-template-layout-ida-refresh-functionobject-autobuf-button-20260616-14 closeout

Changed files and scores:
- `by-type/by-template/FunctionObjectTemplates.md`: `82/88` -> `85/89`.
  - Owner/emitter decision: retained canonical owner/emitter [UID:0000JO] `FunctionObjects`; reconstructable stays `TRUE`; C++ stays blank.
  - Evidence checked: live IDA session `b001_selflookpane_0001H7_20260616`; `server_health` ok for `NexusTK.exe.i64`; `lookup_funcs` reconfirmed representative callback/helper bodies at `0x0049af00`, `0x0049b090`, `0x0049b250`, `0x004671a0`, `0x004671f0`, `0x004672c0`, `0x004673f0`, `0x004b0880`, `0x0052a3e0`, `0x0052a4a0`, `0x0052a460`, `0x005b7450`, and `0x005b77b0`; `xrefs_to` reconfirmed vtable/data refs for invoke/destructor slots and four live `UserPane` factory callers; decompilation reconfirmed member-function pointer/object-adjustment/captured-byte callback layout. Blockers investigated: original template/header basename, exact template spelling, and emitted-destructor consolidation remain source-heuristic, so final C++/type/prototype edits were skipped; B-agent escalation is recommended only for final original template/header reconstruction.
- `by-type/by-template/AUTOBUF_unsigned_char.md`: `82/89` -> `85/90`.
  - Owner/emitter decision: retained canonical owner/emitter [UID:0000HM] `AUTOBUF`; reconstructable stays `TRUE`; C++ stays blank.
  - Evidence checked: live IDA reconfirmed `0x004e6ab0` size `0x27`, `0x004f5640` size `0x2a`, two `UserLookPane` resize callers, one `MapPane` constructor caller, and 21 vtable refs to `0x0061b868`; decompilation reconfirmed `+0x04/+0x08` pointer/count behavior and constructor vtable/field initialization. Blockers investigated: full source template declaration, allocator/destructor API contract, header basename/casing, and type/member/prototype edits remain unsafe.
- `by-type/by-struct/SpecializedButtonPaneLayouts.md`: `85/86` -> `86/88`.
  - Owner/emitter decision: retained canonical owner/emitter [UID:0000NY] `SpecializedButtonPanes`; reconstructable stays `TRUE`; C++ stays blank.
  - Evidence checked: live IDA reconfirmed `0x00500640`, `0x005007a0`, `0x0059ded0`, and `0x0059e0b0` are still non-functions with zero direct xrefs; decompilation reconfirmed gender/direction `+0x10c/+0x110`, checkbox checked byte `+0x108`, label buffer `+0x10a`, constant type helper `0x16`, and vtable reset behavior; `xrefs_to 0x0061db90/0x0061dc34/0x0062e99c` reconfirmed inline setup/destructor/teardown vtable stores. Blockers investigated: raw function creation, struct/member declarations, prototypes, inherited field names, and final source split remain unsafe.
- `by-type/by-template/-coverage-report.md`: synced `FunctionObjectTemplates` and `AUTOBUF_unsigned_char` rows.
- `by-type/by-struct/-coverage-report.md`: synced `SpecializedButtonPaneLayouts` row.
- Validator-applied generated side effects: `project-level/-auto-completion-stats.md` removed [UID:0001WQ] after it cleared the low-score row and updated projected stats; `auto-generated/-ag-type-coverage.md` regenerated. These files were not manually edited.
- `tools/leaser/Agents/Agent-C001/notes.md`: this closeout entry.

Leases used:
- Acquired: `by-type/by-template/FunctionObjectTemplates.md`, `by-type/by-template/AUTOBUF_unsigned_char.md`, `by-type/by-struct/SpecializedButtonPaneLayouts.md`, `by-type/by-template/-coverage-report.md`, `by-type/by-struct/-coverage-report.md`, and `tools/leaser/Agents/Agent-C001/notes.md`.
- Release status: first release attempt after validation returned `Success` for all target/report leases and `tools/leaser/Agents/Agent-C001/notes.md`; notes was then briefly re-leased to replace the provisional release-status line, and the final notes unlease returned `Success`.

IDA DB changes:
- Dry-run rename batch accepted 26/26 function renames.
- Applied and saved 13 FunctionObject-related function renames:
  - `sub_49AF00` -> `PopupMenuSelectionCallbackInvoke`
  - `sub_49B090` -> `FunctionObjectCallbackScalarDeletingDestructor`
  - `sub_49B250` -> `FunctionObjectScalarDeletingDestructor`
  - `sub_4671A0` -> `PlainMemberFunctionObject0ApplicationInvoke`
  - `sub_4671F0` -> `FunctionObject0ScalarDeletingDestructorVariant24`
  - `sub_4672C0` -> `FunctionObject0ScalarDeletingDestructorVariant4`
  - `sub_4673F0` -> `PlainMemberFunctionObject0ApplicationGetObjectSize`
  - `sub_4B0880` -> `MixItemDialogDoubleParamCallback`
  - `sub_52A3E0` -> `MusicControlDialogFolderCallbackInvoke`
  - `sub_52A4A0` -> `MusicControlDialogFolderCallbackDestructor`
  - `sub_52A460` -> `FunctionObjectTStringDestructor`
  - `sub_5B7450` -> `CreateUserPaneDoubleParamCallback`
  - `sub_5B77B0` -> `UserPaneDoubleParamCallback`
- Applied and saved 2 AUTOBUF helper renames:
  - `sub_4E6AB0` -> `AUTOBUFUnsignedCharResize`
  - `sub_4F5640` -> `AUTOBUFUnsignedCharConstructor`
- Applied and saved 11 specialized-button helper renames:
  - `sub_5006D0` -> `GenderButtonControlPaneSetState`
  - `sub_500700` -> `GenderButtonControlPaneOnPaint`
  - `sub_5007F0` -> `DirectionButtonControlPaneSetState`
  - `sub_500820` -> `DirectionButtonControlPaneOnPaint`
  - `sub_5026A0` -> `DirectionButtonControlPaneScalarDeletingDestructor`
  - `sub_502700` -> `GenderButtonControlPaneScalarDeletingDestructor`
  - `sub_4214C0` -> `CheckBoxTextControlPaneGetControlType`
  - `sub_59DF30` -> `CheckBoxTextControlPaneTeardownHelper`
  - `sub_59DF50` -> `CheckBoxTextControlPaneOnPaint`
  - `sub_59E0C0` -> `CheckBoxTextControlPaneGetChecked`
  - `sub_59F050` -> `CheckBoxTextControlPaneScalarDeletingDestructor`
- Save result: `idb_save` returned `ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Skipped IDA edits: raw function creation at `0x00500640`, `0x005007a0`, `0x0059ded0`, and `0x0059e0b0`; struct/member/type/prototype edits; ambiguous `0x0052f780/0x0052f7c0` const-string destructor variant names; final template/header declarations. Reason: current IDA still reports raw starts as non-functions/no-xref or final source names remain provisional.

Validation commands/results:
- `python .\tools\validator.py --mode file --file by-type/by-template/FunctionObjectTemplates.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-type/by-template/AUTOBUF_unsigned_char.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-type/by-struct/SpecializedButtonPaneLayouts.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-type/by-template/-coverage-report.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-type/by-struct/-coverage-report.md --apply --queue-timeout 240`
- Results: sequential validator loop exited `0`; each changed by-* target/report reached `ok: 1`. The first target validation removed [UID:0001WQ] from generated low-score stats; follow-up validations regenerated/synced type coverage metadata without blocking errors.

Supervisor-owned by-memory coverage rows:
- None. No direct edits were made to `by-memory/-coverage-report.md`, and this pass changed no by-memory docs or scores requiring supervisor-owned memory coverage replacement rows.

## 2026-06-16 - C001-goal2-global-ida-refresh-browser-fps-gameserver-20260616-15 final checkpoint

Changed files and scores:
- `by-global/g_activeBrowserControlPane.md`: `86/86` -> `88/90`; owner/emitter retained [UID:0000HV] `Browser`; C++ blank. Live IDA reconfirmed zero bytes, 24 xrefs, BrowserControlPane lifecycle writers, accelerator consumer, and application/presentation readers.
- `by-global/g_fpsDebugActive.md`: `86/86` -> `87/89`; owner/emitter retained [UID:0000JK] `FpsPane`; C++ blank. Live IDA reconfirmed initialized dword `01 00 00 00`, exactly four raw FpsPane refs, and raw helper no-function status.
- `by-global/g_fpsLogEnabled.md`: `86/86` -> `88/90`; owner/emitter retained [UID:0000JK] `FpsPane`; C++ blank. Live IDA reconfirmed exact byte neighborhood, exactly four raw FpsPane refs, start-session log gate, and summary early-exit gate.
- `by-global/g_gameServerNationTable.md`: `86/86` -> `88/89`; owner/emitter retained [UID:0000JP] `GameServerConfig`; C++ blank. Live IDA reconfirmed zero bytes, 18 xrefs, modeled lookup/request/map lifecycle/destructor helpers, and raw no-function constructor/destructor islands.
- Support docs updated without score changes: `by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md` (`86/89`), `by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md` (`86/88`), `by-memory/0x0069b338-0x0069b339.g_fpsLogEnabled.md` (`88/90`), and `by-memory/0x0069b4c4-0x0069b4c8.g_gameServerNationTable.md` (`86/86`).
- `by-global/-coverage-report.md`: synced the four global rows.

IDA DB changes:
- Applied/saved 10 function renames: `sub_46B520` -> `BrowserControlPaneConstructor`; `sub_46B990` -> `BrowserControlPaneDestructor`; `sub_46C550` -> `BrowserControlPaneTranslateAcceleratorMessage`; `sub_470210` -> `ClearActiveBrowserControlPane`; `sub_470410` -> `BrowserControlPaneScalarDeletingDestructor`; `sub_503A80` -> `GameServerConfigCopyNationEntryOrFallback`; `sub_503C70` -> `GameServerConfigRequestNationEntries`; `sub_504110` -> `MapPaneInitialize`; `sub_504530` -> `MapPaneCleanup`; `sub_514D80` -> `GameServerConfigScalarDeletingDestructor`.
- Applied/saved 4 data renames: `unk_67AB28` -> `g_activeBrowserControlPane`; `dword_66DA90` -> `g_fpsDebugActive`; `unk_69B338` -> `g_fpsLogEnabled`; `unk_69B4C4` -> `g_gameServerNationTable`.
- Save result: `idb_save` returned `ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Skipped unsafe IDA edits: raw function creation/renames at `0x004b64a0`, `0x004b69b0`, `0x004b6ae0`, `0x005039f0`, and `0x00503a50`; Browser presentation helper `0x0046bfd0`; type/member/prototype edits.

Validations:
- Ran `python .\tools\validator.py --mode file --file <changed-by-star-file> --apply --queue-timeout 240` for the four globals, four memory support pages, and `by-global/-coverage-report.md`; sequential loop exited `0`, each changed by-* file/report reached `ok: 1`.

Leases and pending rows:
- Leases acquired for the four globals, four support memory pages, `by-global/-coverage-report.md`, and C001 `notes.md`. Initial unlease attempt found the target/report leases already clear (`Rejected[No active lease]`); final notes lease released successfully. Current lease report showed no active C001 leases.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none. No by-memory scores changed and the banned report was not edited.

## 2026-06-16 Assignment - C001-goal2-global-ida-refresh-static-meta-object-20260616-16

Assigned targets:
- [UID:0003MS] `by-global/StaticSimpleUStringVector_69B39C.md`
- [UID:0000Q2] `by-global/g_metaAliasTableName.md`
- [UID:0000Q3] `by-global/g_objectNationMap.md`
- [UID:0000Q4] `by-global/g_objectRecordCount.md`

Instructions:
- Read and follow `Agent-C001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven global-storage plus safe IDA refresh batch. Raise target and direct support pages where evidence supports it, including coverage rows, without inflating scores beyond the evidence.
- Recheck storage bytes, xrefs, static-lifetime writers, consumer reads, owner/emitter route, final declaration/type/source-placement blockers, stale byte/name evidence, and support memory/global/file/type docs. Resolve blockers where evidence supports it or document exactly why they remain unsafe.
- Apply only evidence-backed low-risk IDA improvements. Do not create raw functions, force provisional type/member edits, or rename/comment speculative source names.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply. Non-memory coverage reports may be edited directly only under normal lease rules.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, saved IDA changes, and any exact pending supervisor-owned report rows.

## 2026-06-16 - C001-goal2-global-ida-refresh-static-meta-object-20260616-16 closeout

Changed files and scores:
- `by-global/StaticSimpleUStringVector_69B39C.md`: `86/86 -> 88/90`. Owner/emitter retained [UID:0000OB] `StringUtil`; reconstructable stays `TRUE`; descriptive C++ declaration kept. Live IDA reconfirmed zeroed three-pointer storage, cleanup-only `3/2/2` xref split, static-initializer-table reachability, and inline 24-byte `SimpleUString` cleanup. Original variable spelling and normal-use purpose remain unresolved.
- `by-global/g_metaAliasTableName.md`: `86/86 -> 88/89`. Owner/emitter retained [UID:0000LC] `MetaMan`; reconstructable stays `TRUE`; C++ remains blank. Live IDA reconfirmed 24-byte empty `SimpleUString` bytes, six base-object xrefs, length/capacity destructor refs, static initializer/cleanup lifetime, and alias-first `MetaManFindEntry` / `MetaManLoadStatValues` fallback behavior. Original alias key/source symbol spelling remains unresolved.
- `by-global/g_objectNationMap.md`: `86/86 -> 88/89`. Owner/emitter retained [UID:0000L3] `MapPane`; reconstructable stays `TRUE`; C++ remains blank. Live IDA reconfirmed zeroed storage, six xrefs, `MapPaneInitialize` SOBJ allocation/fill, `MapPaneCleanup` free/clear, and `0x00505430` direction-mask consumer behavior. Exact source spelling, consumer helper name, and SOBJ one-byte field semantics remain below final-source confidence.
- `by-global/g_objectRecordCount.md`: `86/86 -> 88/89`. Owner/emitter retained [UID:0000L3] `MapPane`; reconstructable stays `TRUE`; C++ remains blank. Live IDA reconfirmed zeroed storage, five xrefs, `MapPaneInitialize` count load/allocation/loop behavior, and `0x00505430` bounds-check consumer behavior. Exact source spelling and SOBJ record-to-index convention remain open.
- Support docs updated with no score changes: `by-memory/0x0069b39c-0x0069b3a8.StaticStringVectorStorage_69B39C.md` (`88/93`), `by-memory/0x0066de18-0x0066de30.g_metaAliasTableName.md` (`85/88`), `by-memory/0x0069b4c0-0x0069b4c4.g_objectNationMap.md` (`86/86`), and `by-memory/0x0069b4bc-0x0069b4c0.g_objectRecordCount.md` (`86/86`).
- `by-global/-coverage-report.md`: synced the four changed global rows.

IDA DB changes:
- Dry-run rename batch accepted 10/10 candidates.
- Applied and saved 6 function renames: `sub_419F40 -> RegisterStaticSimpleUStringVectorCleanup_69B39C`; `sub_60C160 -> StaticSimpleUStringVectorCleanup_69B39C`; `sub_419FF0 -> InitializeMetaAliasTableNameStatic`; `sub_60C2A0 -> MetaAliasTableNameCleanup`; `sub_523120 -> MetaManFindEntry`; `sub_5231F0 -> MetaManLoadStatValues`.
- Applied and saved 4 data renames: `unk_69B39C -> StaticSimpleUStringVector_69B39C`; `dword_66DE18 -> g_metaAliasTableName`; `unk_69B4BC -> g_objectRecordCount`; `unk_69B4C0 -> g_objectNationMap`.
- Save result: `idb_save` returned `ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Skipped unsafe IDA edits: `0x00505430` helper rename, `0x00523a70`/`0x00523b40` lower MetaMan helper renames, raw function creation, and type/member/prototype edits. Reason: final helper names, SOBJ record field names, record-zero convention, and source declarations remain provisional.

Validation commands/results:
- Ran `python .\tools\validator.py --mode file --file <changed-by-star-file> --apply --queue-timeout 240` for the four globals, four support memory pages, and `by-global/-coverage-report.md`.
- Result: sequential validator loop exited `0`; each changed by-* file/report reached `ok: 1`. Validator `--apply` updated projected stats/autogen metadata and removed [UID:0003MS] from the generated low-score stats after its score increase.

Leases and pending rows:
- Leases acquired for the four globals, four support memory pages, `by-global/-coverage-report.md`, and `tools/leaser/Agents/Agent-C001/notes.md`.
- Release status: final unlease attempt reported `Rejected[No active lease]` for the target/report/support leases because the original leases had already expired during validation/notes work; notes was then re-leased to record this final status and released successfully.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none. No by-memory scores changed, and `by-memory/-coverage-report.md` was not edited.

## 2026-06-16 Assignment - C001-goal2-global-ida-refresh-cheat-general-hour-icons-message-20260616-17

Assigned targets:
- [UID:0000QJ] `by-global/g_pCheatDetector.md`
- [UID:0000R1] `by-global/g_pGeneralPurposePanel2.md`
- [UID:0000R4] `by-global/g_pHourPane.md`
- [UID:0000R6] `by-global/g_pIconsPane.md`
- [UID:0000RK] `by-global/g_pMessageShowPane.md`

Instructions:
- Read and follow `Agent-C001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven global-storage plus safe IDA refresh batch. Raise target and direct support pages where evidence supports it, including coverage rows, without inflating scores beyond the evidence.
- Recheck storage bytes, xrefs, static lifetime writes, consumer reads, owner/emitter routes, stale alias/name evidence, support memory/global/file/type docs, and final declaration/type/source-placement blockers.
- Apply only evidence-backed low-risk IDA improvements. Do not create raw functions, force provisional type/member edits, or rename/comment speculative source names.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, saved IDA changes, and exact pending supervisor-owned report rows.

## 2026-06-16 - C001-goal2-item-ida-refresh-checkbox-popup-ail-tilec-20260616-29 closeout

Changed files and scores:
- `by-item/CheckBoxControlPaneStateTypeHelper_00499EC0.md`: `85/89 -> 86/90`; owner/emitter retained [UID:0000I7] `CheckBoxControlPane`.
- `by-item/PopupMenuSelectionCallback_0049AF00.md`: `85/89 -> 86/90`; owner/emitter retained [UID:0000AK] `PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_`, with [UID:0000JO] `FunctionObjects` as source route and [UID:0000MN] `PopupMenuControls` as feature consumer.
- `by-item/AILFileOpenCallback_0057B630.md`: `86/88 -> 87/91`; owner/emitter retained [UID:0000NV] `SoundManager`.
- `by-item/BuildTilecArchiveTable_004DDA60.md`: `86/88 -> 87/90`; owner/emitter retained [UID:0000O7] `StaticObjImageLib`.
- `by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md`: `85/88 -> 86/89`; owner/emitter retained [UID:000021] `CheckBoxControlPane`.
- `by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md`: `85/89 -> 86/90`; owner/emitter retained [UID:0000AK].
- `by-memory/0x0057b490-0x0057bf6e.SoundManagerDriverDestructorAndPathHelpers.md`: `85/88 -> 87/90`; owner/emitter retained [UID:0000NV] `SoundManager`.
- `by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md`: `85/90 -> 86/91`; intentionally remains `RECONSTRUCTABLE:FALSE`, owner `NONE`, and non-emitting because exact child/tail pages carry source ownership.
- `by-item/-coverage-report.md`: synced rows for [UID:0000TU], [UID:0000U6], [UID:0000U7], and [UID:0000V8].

Owner/emitter and blocker decisions:
- CheckBox state helper remains CheckBoxControlPane-owned. Live IDA now reports current saved label `CheckBoxControlPane_StateTypeHelper`; no new IDA edit was needed. Final C++ remains blank because the inherited virtual slot `+0x20`, exact field names for `+0x103/+0x14c`, and source split between `CheckBoxControlPane.cpp` and `ButtonControlPane.cpp` remain unresolved.
- Popup callback invoke remains FunctionObjects/template-owned, with PopupMenuControls only as feature-side construction/consumer. Live IDA reports saved label `PopupMenuSelectionCallbackInvoke`, unchanged seven data-only refs, no callees, and continued rejection of stale `0x004d0050` as an interior `ImageLib_Constructor` address. Final template/header spelling remains a source-structure blocker; B-agent escalation is appropriate only if original template reconstruction is required.
- AIL file callback remains SoundManager-owned because all callback xrefs are from `SoundManager_ReinitializeAudioDriver` registration. Final C++ remains blank because exact Miles callback typedef spelling, surrounding `File` class declarations, and source declaration placement remain provisional.
- Tilec archive-table helper remains StaticObjImageLib-owned because `xrefs_to 0x004dda60` still shows the single constructor call from `StaticObjImageLib_Constructor`. Final C++ remains blank because table/record field names and possible common EPF-loader consolidation are not source-quality.
- Support memory [UID:00017H] remains a non-emitting local cluster; score increased only for saved-label and boundary evidence, not for ownership/emission.

Evidence and IDA DB changes:
- Live IDA MCP session `b001_mappane_0001AW_20260616` (`NexusTK.exe.i64`) was used for lookup, xrefs, callees, decompilation, bytes, dry-run rename validation, applied renames, IDB save, and post-save lookup.
- Existing labels verified without mutation: `CheckBoxControlPane_StateTypeHelper` at `0x00499ec0` and `PopupMenuSelectionCallbackInvoke` at `0x0049af00`.
- Saved 7 labels after dry-run accepted all candidates: `SoundManager_ReinitializeAudioDriver` at `0x0057b490`, `AILFileOpenCallback` at `0x0057b630`, `AILFileCloseCallback` at `0x0057b730`, `AILFileSeekCallback` at `0x0057b750`, `AILFileReadCallback` at `0x0057b7a0`, `BuildTilecArchiveTable` at `0x004dda60`, and `StaticObjImageLib_Constructor` at `0x004dcf60`.
- Save result: `idb_save ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Skipped unsafe IDA edits: prototypes, struct/member names, locals, raw function creation, callback typedefs, `File` API signatures, Tilec table fields, CheckBox field names, and source-facing template/header declarations.

Validation commands/results:
- Ran `python .\tools\validator.py --mode file --file <changed-by-star-file> --apply --queue-timeout 240` from `source-3/project-documentation` for `by-item/CheckBoxControlPaneStateTypeHelper_00499EC0.md`, `by-item/PopupMenuSelectionCallback_0049AF00.md`, `by-item/AILFileOpenCallback_0057B630.md`, `by-item/BuildTilecArchiveTable_004DDA60.md`, `by-item/-coverage-report.md`, `by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md`, `by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md`, `by-memory/0x0057b490-0x0057bf6e.SoundManagerDriverDestructorAndPathHelpers.md`, and `by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md`.
- Result: sequential validator loop exited `0`; every changed by-* target/support/report reached `ok:1`. Validator `--apply` updated projected stats and removed the refreshed item rows from the current low-score stats lists as applicable.

Leases:
- Acquired C001 leases for the four target item docs, four direct support memory docs, `by-item/-coverage-report.md`, and this notes file before edits. Validation ran after edits. Current lease report showed no active leases after validation, so a short notes-only lease was reacquired for this closeout note and will be released after this update.

Supervisor-owned `by-memory/-coverage-report.md` rows:
- Do not edit `by-memory/-coverage-report.md` directly. Placement context: replace existing [UID:00011S] row around current line 1164, [UID:00011X] around current line 1169, [UID:00017H] around current line 1810, and [UID:0001IC] around current line 3279, preserving indentation.
- Replace existing [UID:00011S] row with:
```text
    - [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md) 0x00499d40-0x00499f0e | class method cluster | CheckBoxControlPaneCore : reconstructable : 86% : strong : CheckBoxControlPane core with all six exact functions, constructor/setter/getter callers, vtable-only virtual refs, current saved `CheckBoxControlPane_StateTypeHelper` label, constructor resource names, checked-state/state-type offsets, vtable-data child, padding gaps, qualifying class-parent assignment, and final source split/field-name/destructor routing blockers documented.
```
- Replace existing [UID:00011X] row with:
```text
    - [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md) 0x0049af00-0x0049af11 | callback-template invoke | PopupMenuSelectionCallbackInvoke : reconstructable : 86% : very strong : Exact popup-menu selection callback invoke attached to the FunctionObjects class wrapper; live IDA confirms current saved `PopupMenuSelectionCallbackInvoke` label, exact `0x11`-byte boundary, adjusted indirect member-function dispatch through offsets `+8/+12/+16`, seven data/vtable refs, no direct callers/callees, and stale `0x004d0050` as an interior `ImageLib_Constructor` address.
```
- Replace existing [UID:00017H] row with:
```text
    - [UID:00017H][0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster](by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md) 0x004dcf60-0x004ddf60 | class-method-cluster | StaticObjImageLibLocalMethodCluster : ignored/non-emitting : 86% : very strong : Non-emitting contiguous StaticObjImageLib local cluster with saved `StaticObjImageLib_Constructor` and `BuildTilecArchiveTable` labels, one constructor xref to the Tilec builder, unchanged successor loader boundary at `0x004dde10`, and prior proof that the old broad range crossed EffectObjImageLib, ItemObjImageLib, LightObjImageLib, and NewHumanImageLib; exact child/tail pages carry reconstructable ownership.
```
- Replace existing [UID:0001IC] row with:
```text
    - [UID:0001IC][0x0057b490-0x0057bf6e.SoundManagerDriverDestructorAndPathHelpers](by-memory/0x0057b490-0x0057bf6e.SoundManagerDriverDestructorAndPathHelpers.md) 0x0057b490-0x0057bf6e | method/helper aggregate | SoundManagerDriverDestructorAndPathHelpers : reconstructable : 87% : very strong : Corrected SoundManager driver/destructor/path-helper aggregate attached to SoundManager with saved `SoundManager_ReinitializeAudioDriver` and AIL open/close/seek/read callback labels, driver setup, callback registration xrefs, DAT/loose-file bridge, singleton helper, contained SoundPathVector/deque interleave, scalar deleting destructor `0x0057bb30-0x0057bc59`, string/path/vector helper starts through `0x0057bf40-0x0057bf6e`, padding boundaries, and final callback typedef/field/source-split blockers documented.
```

## 2026-06-16 - C001-goal2-global-ida-refresh-cheat-general-hour-icons-message-20260616-17 closeout

Changed files and scores:
- `by-global/g_pCheatDetector.md`: `86/86 -> 88/89`. Owner/emitter retained [UID:0000I6] `CheatDetector`; reconstructable stays `TRUE`; C++ stays blank. Live IDA session `b001_mappane_0001AW_20260616` reconfirmed current bytes `00 00 00 00`, five direct xrefs, constructor publish/null writes, clear helper, scalar-deleting destructor clear, and startup cleanup consumer. Blockers investigated: timer-handler base/member naming and raw time-snapshot helper reachability remain unresolved in support docs, so final declaration/C++ was skipped.
- `by-global/g_pGeneralPurposePanel2.md`: `86/86 -> 88/89`. Owner/emitter retained [UID:0000JQ] `GeneralPurposePanel`; reconstructable stays `TRUE`; C++ stays blank. Live IDA reconfirmed current bytes `00 00 00 00`, 14 direct xrefs, constructor publish/null writes, destructor/clear/scalar clear paths, UI teardown reads, and user/message consumer reads. Blockers investigated: public method/member spelling and shared layout/show helper names remain provisional, but singleton owner/source route is supported.
- `by-global/g_pHourPane.md`: `86/86 -> 88/89`. Owner/emitter retained [UID:0000JX] `HourPane`; reconstructable stays `TRUE`; C++ stays blank. Live IDA reconfirmed current bytes `00 00 00 00`, four direct xrefs, constructor store, cleanup/destructor clears, broad UI shutdown read, and adjacent `g_pIconsPane` separation. Blockers investigated: inherited-base/member names and exact declaration/header placement remain below final-source confidence.
- `by-global/g_pIconsPane.md`: `86/86 -> 88/89`. Owner/emitter retained [UID:0000JZ] `IconsPane`; reconstructable stays `TRUE`; C++ stays blank. Live IDA reconfirmed current bytes `00 00 00 00`, six direct xrefs, constructor store, cleanup/destructor clears, main UI shutdown read, and two option UI consumer reads. Blockers investigated: raw action-dispatch candidate and final source grouping with `TabPane` remain unresolved.
- `by-global/g_pMessageShowPane.md`: `86/86 -> 88/90`. Owner/emitter retained [UID:0000LB] `MessageShowPane`; reconstructable stays `TRUE`; C++ stays blank. Live IDA reconfirmed current bytes `00 00 00 00`, eight direct xrefs, constructor/destructor/EH/scalar-destructor writers, packet-handler update/create/delete reads, and broad UI cleanup removal. Blockers investigated: standalone `MessageShowPane.cpp` versus compact `MessageDialogs.cpp` split and exact declaration/header placement remain unresolved; broad UI cleanup `0x005047f0` was not renamed because it covers many unrelated teardown paths.
- Support docs updated with no score changes: `by-memory/0x0067ab3c-0x0067ab40.g_pCheatDetector.md` (`86/90`), `by-memory/0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage.md` (`86/90`), `by-memory/0x0069b418-0x0069b41c.g_pHourPane.md` (`89/91`), `by-memory/0x0069b41c-0x0069b420.g_pIconsPane.md` (`88/90`), and `by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md` (`86/92`). These pages now record the current live IDA zero-byte observations and saved data labels while retaining older `0xffffffff` observations as historical until a raw-file-byte reconciliation audit.
- `by-global/-coverage-report.md`: synced rows for the five changed globals.

IDA DB changes:
- Dry-run rename batch accepted 23/23 candidates.
- Applied and saved 18 function renames: `sub_483F00 -> CheatDetectorConstructor`; `sub_483FF0 -> ClearCheatDetectorSingleton`; `sub_484000 -> CheatDetectorScalarDeletingDestructor`; `sub_4B8830 -> GeneralPurposePanel2Constructor`; `sub_4B88F0 -> GeneralPurposePanel2Destructor`; `sub_4B8A80 -> ClearGeneralPurposePanel2Singleton`; `sub_4B8AA0 -> GeneralPurposePanel2ScalarDeletingDestructor`; `sub_4CEE60 -> HourPaneConstructor`; `sub_4CEEB0 -> HourPaneCleanupHelper`; `sub_4CF190 -> HourPaneScalarDeletingDestructor`; `sub_4CF1F0 -> IconsPaneConstructor`; `sub_4CF260 -> IconsPaneCleanupHelper`; `sub_4CFDA0 -> IconsPaneScalarDeletingDestructor`; `sub_521DA0 -> MessageShowPaneConstructor`; `sub_521FC0 -> MessageShowPaneDestructor`; `sub_5226F0 -> MessageShowPaneClearSingletonEH`; `sub_522720 -> MessageShowPaneScalarDeletingDestructor`; `sub_5AC070 -> HandleMessageShowPacket`.
- Applied and saved 5 data renames: `unk_67AB3C -> g_pCheatDetector`; `unk_69B358 -> g_pGeneralPurposePanel2`; `unk_69B418 -> g_pHourPane`; `unk_69B41C -> g_pIconsPane`; `unk_69B4F4 -> g_pMessageShowPane`.
- Save result: `idb_save` returned `ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Skipped unsafe IDA edits: broad UI teardown function `0x005047f0`, raw function creation, struct/member/prototype edits, inherited base/type edits, `GeneralPurposePanel` shared layout/show helper names, `IconsPane` raw action dispatch, and final singleton declaration/header edits. Reason: remaining names/source placement are still cross-owner or provisional.

Validation commands/results:
- `python .\tools\validator.py --mode file --file by-global/g_pCheatDetector.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-global/g_pGeneralPurposePanel2.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-global/g_pHourPane.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-global/g_pIconsPane.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-global/g_pMessageShowPane.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory/0x0067ab3c-0x0067ab40.g_pCheatDetector.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory/0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory/0x0069b418-0x0069b41c.g_pHourPane.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory/0x0069b41c-0x0069b420.g_pIconsPane.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-global/-coverage-report.md --apply --queue-timeout 240`
- Results: sequential validator loop exited `0`; each changed by-* target/support/report reached `ok: 1`. Validator `--apply` removed the five global rows from generated low-score stats and refreshed projected/autogen metadata.

Leases and pending rows:
- Leases acquired for the five target globals, five support memory pages, `by-global/-coverage-report.md`, and `tools/leaser/Agents/Agent-C001/notes.md`.
- Release status: final target/report/support/notes unlease returned `Rejected[No active lease]` for each path because the original leases had already expired after validation/notes work; notes was then re-leased to record this release status.
- Supervisor-owned `by-memory/-coverage-report.md` rows: none. No by-memory scores changed, and `by-memory/-coverage-report.md` was not edited.

## 2026-06-16 Assignment - C001-goal2-memory-ida-refresh-decoder-lifecycle-20260616-18

Assigned targets:
- [UID:00013N] `by-memory/0x004a5640-0x004a5664.DecoderConstructor.md`
- [UID:00013O] `by-memory/0x004a5670-0x004a5677.DecoderDestructor.md`
- [UID:00013S] `by-memory/0x004a5dd0-0x004a5ded.DecoderFinalize.md`

Instructions:
- Read and follow `Agent-C001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a low-completion exact-method plus safe IDA refresh batch from refreshed `project-level/-auto-completion-stats.md`. Raise each target and directly supporting page where evidence supports it, including support docs and coverage rows, without inflating scores beyond the evidence.
- Recheck function bounds, vtable refs, caller/reachability state, source placement, final method-name/signature blockers, support Decoder/BinaryCodec/raw-reader/vtable docs, and final-C++ blockers.
- Apply only evidence-backed low-risk IDA improvements. Do not create raw functions, force provisional type/member edits, or rename/comment speculative source names.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, saved IDA changes, and exact pending supervisor-owned report rows.

## 2026-06-16 - C001-goal2-memory-ida-refresh-decoder-lifecycle-20260616-18 closeout

Changed files and scores:
- `by-memory/0x004a5640-0x004a5664.DecoderConstructor.md`: `80/88 -> 85/90`. Owner/emitter retained [UID:00003M] `Decoder`; source route remains [UID:0000IQ] `Decoder` under [UID:0000HQ] `BinaryCodec`; final C++ remains blank.
- `by-memory/0x004a5670-0x004a5677.DecoderDestructor.md`: `80/88 -> 85/90`. Owner/emitter retained [UID:00003M] `Decoder`; source route remains [UID:0000IQ] `Decoder`; final C++ remains blank.
- `by-memory/0x004a5dd0-0x004a5ded.DecoderFinalize.md`: `80/88 -> 85/90`. Owner/emitter retained [UID:00003M] `Decoder`; source route remains [UID:0000IQ] `Decoder`; final C++ remains blank.
- Support doc updated without score change: `by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md` remained `85/89`, non-emitting BinaryCodec grouping index.
- Validator `--apply` also refreshed `project-level/-auto-completion-stats.md`; [UID:00013N], [UID:00013O], and [UID:00013S] were removed from the generated low-score lists.

Live evidence and blocker investigations:
- IDA MCP active session: `b001_mappane_0001AW_20260616`, `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, strings cache ready. `server_health` still reports `auto_analysis_ready:false`, but the active worker was not analyzing and returned stable targeted results.
- `analyze_component` reported current IDA names/bounds: `Decoder_Constructor` `0x004a5640` size `0x24`, `Decoder_Destructor` `0x004a5670` size `0x7`, `Decoder_Finalize` `0x004a5dd0` size `0x1d`, `nullsub_28` `0x004a5df0` size `0x1`, and `Decoder_ScalarDeletingDestructor` `0x004a5e00` size `0x24`.
- Decompilation confirmed constructor vtable install plus clears at `+0x04/+0x08/+0x0c` and flags word `0x0101` at `+0x10`; destructor only restores the Decoder vtable; finalize returns prior valid byte at `+0x11`, clears `+0x04/+0x08/+0x0c`, and writes valid byte `1`.
- Caller/reachability: `xrefs_to` reported zero direct xrefs to `0x004a5640`, `0x004a5670`, and `0x004a5dd0`; `0x006192d8` still has only the constructor/destructor/scalar-deleting-destructor refs at `0x004a5640`, `0x004a5670`, and `0x004a5e0a`.
- Raw-reader and split/range blockers investigated: raw Decoder starts `0x004a5680`, `0x004a5690`, `0x004a56c0`, `0x004a5710`, `0x004a5770`, `0x004a57e0`, `0x004a5870`, `0x004a5930`, `0x004a5a40`, `0x004a5bb0`, `0x004a5c80`, `0x004a5cd0`, `0x004a5d80`, and `0x004a5db0` still return `Not a function` and have zero direct xrefs. No raw functions were created.
- Source-quality blockers investigated: final source-facing field names, exact Decoder header/source split, `Decoder_Finalize` original method name, class type/prototype installation, and raw-reader method inventory remain unsafe because current evidence has no direct callers for the three assigned starts and no IDA function objects/xrefs for adjacent raw readers.

IDA DB changes:
- No IDA DB mutation was made in this batch. The safe target names were already present in the active IDB (`Decoder_Constructor`, `Decoder_Destructor`, `Decoder_Finalize`, `Decoder_ScalarDeletingDestructor`), while `nullsub_28` and raw-reader starts remain provisional or unsafe to mutate without stronger source/caller evidence.
- No IDB save was required.

Validation commands/results:
- `python .\tools\validator.py --mode file --file by-memory/0x004a5640-0x004a5664.DecoderConstructor.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory/0x004a5670-0x004a5677.DecoderDestructor.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory/0x004a5dd0-0x004a5ded.DecoderFinalize.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md --apply --queue-timeout 240`
- Result: sequential validator loop exited `0`; each changed by-memory target/support page reached `ok: 1`.

Leases:
- Acquired leases for the three assigned target pages, `by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md`, and `tools/leaser/Agents/Agent-C001/notes.md`.
- Release status: first unlease command returned `Success` for the three assigned target pages, `by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md`, and `tools/leaser/Agents/Agent-C001/notes.md`; notes was then re-leased only to record this status.
- Final release status: notes final unlease returned `Success`; `current_leases.md` then showed no active leases.

Supervisor-owned `by-memory/-coverage-report.md` rows:
- Supervisor applied and validated the four replacement rows below on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240`; result `ok: 1`. No C001 Decoder lifecycle supervisor-owned `by-memory/-coverage-report.md` rows remain pending.
- Do not edit `by-memory/-coverage-report.md` directly. Placement context: replace the existing rows in the Decoder/BinaryCodec neighborhood around current report lines 1331-1367, preserving the existing child indentation under the codec island.
- Replace existing [UID:00013M] row with:
```text
    - [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md) 0x004a5630-0x004a5e54 | split-index | DecoderAndCodecVtableGlue : ignored : 85% : strong : Non-emitting BinaryCodec glue index; 2026-06-16 live IDA reconfirms modeled Decoder lifecycle names/bounds, exact raw Decoder child split, unchanged raw no-function/no-xref caveats, compact Decoder vtable refs, and exact children carry source-owned routing.
```
- Replace existing [UID:00013N] row with:
```text
    - [UID:00013N][0x004a5640-0x004a5664.DecoderConstructor](by-memory/0x004a5640-0x004a5664.DecoderConstructor.md) 0x004a5640-0x004a5664 | constructor | DecoderConstructor : reconstructable : 85% : strong : `Decoder` constructor; 2026-06-16 IDA MCP confirms current `Decoder_Constructor` name, exact `0x24` range, decompiled vtable/field writes, zero direct function-start xrefs, and `0x006192d8` vtable refs; autogen-parented under Decoder class UID `00003M` position `10` with source root UID `0000IQ`.
```
- Replace existing [UID:00013O] row with:
```text
    - [UID:00013O][0x004a5670-0x004a5677.DecoderDestructor](by-memory/0x004a5670-0x004a5677.DecoderDestructor.md) 0x004a5670-0x004a5677 | destructor | DecoderDestructor : reconstructable : 85% : strong : Non-deleting `Decoder` destructor; 2026-06-16 IDA MCP confirms current `Decoder_Destructor` name, exact `0x7` range, decompiled one-store vtable restore, zero direct function-start xrefs, and destructor-family link through `0x006192d8`; autogen-parented under Decoder class UID `00003M` position `20` with source root UID `0000IQ`.
```
- Replace existing [UID:00013S] row with:
```text
    - [UID:00013S][0x004a5dd0-0x004a5ded.DecoderFinalize](by-memory/0x004a5dd0-0x004a5ded.DecoderFinalize.md) 0x004a5dd0-0x004a5ded | method | DecoderFinalize : reconstructable : 85% : strong : `Decoder` reset/finalize method; 2026-06-16 IDA MCP confirms current `Decoder_Finalize` name, exact `0x1d` boundary before `nullsub_28`, decompiled valid-flag return and cursor-state clear behavior, zero direct function-start xrefs, and unchanged adjacent raw-reader no-function/no-xref blockers; autogen-parented under Decoder class UID `00003M` position `80` with source root UID `0000IQ`.
```

## 2026-06-16 Assignment - C001-goal2-memory-ida-refresh-poolallocator-core-20260616-19

Assigned targets:
- [UID:000152] `by-memory/0x004b13d0-0x004b1585.PoolAllocatorCore.md`
- [UID:000153] `by-memory/0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront.md`
- [UID:0001VK] `by-type/by-struct/PoolAllocatorLayout.md`

Instructions:
- Read and follow `Agent-C001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a stats-driven memory/type plus safe IDA refresh batch. Quick-peek shows known owner/emitter routes through [UID:0000MM] `PoolAllocator` and [UID:0000AM] `PoolAllocator`, with target scores [UID:000152] `80/88`, [UID:000153] `80/88`, and [UID:0001VK] `84/88`.
- Refresh exact bounds, decompilation, xrefs, helper/caller inventories, allocator layout offsets, `ThreadSafeNodeList` alias evidence, static instance links, and support pages including `by-class/PoolAllocator.md`, `by-file/PoolAllocator.md`, [UID:0001F4] `PoolAllocatorChunkHelper`, [UID:00023L] `PoolAllocatorFreeChunkList`, and relevant globals if they directly affect the target evidence.
- Apply only evidence-backed low-risk IDA improvements. Do not force speculative type/member/prototype edits or rename ambiguous source-facing helper names.
- Investigate final source-quality blockers now: public/private method names, standalone file vs private string-module placement, alias cleanup, field/helper names, caller/reachability gaps, and whether any support page needs score/route correction. Do not merely list these blockers without checking evidence.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, saved IDA changes, and exact pending supervisor-owned report rows.

## 2026-06-16 - C001-goal2-memory-ida-refresh-poolallocator-core-20260616-19 closeout

Changed files and scores:
- `by-memory/0x004b13d0-0x004b1585.PoolAllocatorCore.md`: `80/88 -> 86/90`. Owner/emitter retained [UID:0000MM] `PoolAllocator`; class owner remains [UID:0000AM] `PoolAllocator`; final C++ stays blank.
- `by-memory/0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront.md`: `80/88 -> 85/90`. Owner/emitter retained [UID:0000MM] `PoolAllocator`; documented as PoolAllocator free-list return behavior with a `ThreadSafeNodeList` alias, not standalone ThreadSafeNodeList ownership.
- `by-memory/0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper.md`: `80/88 -> 85/90`. Support helper retained under [UID:0000MM] `PoolAllocator`.
- `by-memory/0x00549c00-0x00549c18.PoolAllocatorFreeChunkList.md`: `80/88 -> 85/90`. Support helper retained under [UID:0000MM] `PoolAllocator`.
- `by-type/by-struct/PoolAllocatorLayout.md`: `84/88 -> 86/90`. Owner/emitter retained [UID:0000AM] `PoolAllocator`; no IDA struct/member/prototype mutation was made because source-facing field names remain partly provisional.
- `by-class/PoolAllocator.md`: `86/82 -> 86/85`; destructor range corrected to half-open `0x004b1520-0x004b1585` and canonical owner/emitter metadata refreshed to [UID:0000MM] `PoolAllocator`.
- `by-file/PoolAllocator.md`: `86/80 -> 86/85`; destructor range corrected to half-open `0x004b1520-0x004b1585` and canonical file-owner metadata refreshed.
- `by-type/by-struct/-coverage-report.md`: synced [UID:0001VK] `PoolAllocatorLayout` row to `86%`.

Evidence and blocker investigations:
- Live IDA MCP session `b001_mappane_0001AW_20260616` confirmed exact function starts/bounds: constructor `0x004b13d0` size `0x30`, allocate `0x004b1400` size `0xb8`, free/push `0x004b14c0` size `0x2f`, destructor `0x004b1520` size `0x65`, chunk allocate `0x00549bd0` size `0x21`, and chunk free-list `0x00549c00` size `0x18`.
- Decompilation confirmed layout offsets: `+0x00 blockSize`, `+0x04 blocksPerChunk`, `+0x08 chunkList`, `+0x0c freeList`, and `+0x10 CRITICAL_SECTION`, object size `0x28`.
- Caller/reachability refreshed: 19 constructor wrappers, 33 allocation callers, 30 free callers, 19 cleanup wrappers, sole helper edge from allocate to chunk allocation, and destructor edge to chunk free-list. Representative static pools at `0x0069bacc`, `0x0069bb6c`, `0x0069bf34`, `0x0069b894`, and `0x0069b9fc` were checked and remain distributed through consumer modules rather than one global owner.
- Source-quality blockers investigated: public/private source names, standalone `PoolAllocator.cpp` versus private string/container module placement, `ThreadSafeNodeList` alias cleanup, helper visibility, field/member naming, static pool placement, caller reachability, range splits, and final-C++ eligibility. The allocator mechanics are now strong enough for 85+ scores, but final C++ remains withheld because original source-facing declarations and file placement are not fully proven.

IDA DB changes:
- Dry-run rename batch accepted 6/6 candidates.
- Applied and saved function renames: `sub_4B13D0 -> PoolAllocator_Constructor`; `sub_4B1400 -> PoolAllocator_Allocate`; `sub_4B14C0 -> PoolAllocator_Free`; `sub_4B1520 -> PoolAllocator_Destructor`; `sub_549BD0 -> PoolAllocator_AllocateChunk`; `sub_549C00 -> PoolAllocator_FreeChunkList`.
- Save result: `idb_save` returned `ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Skipped unsafe IDA edits: data/global renames for static pool instances, struct/member/prototype edits, and standalone `ThreadSafeNodeList` naming. Reason: source-facing field names, static instance ownership, and standalone alias evidence remain provisional.

Validation commands/results:
- Ran `python .\tools\validator.py --mode file --file <changed-by-star-file> --apply --queue-timeout 240` for `by-memory/0x004b13d0-0x004b1585.PoolAllocatorCore.md`, `by-memory/0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront.md`, `by-memory/0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper.md`, `by-memory/0x00549c00-0x00549c18.PoolAllocatorFreeChunkList.md`, `by-type/by-struct/PoolAllocatorLayout.md`, `by-class/PoolAllocator.md`, `by-file/PoolAllocator.md`, and `by-type/by-struct/-coverage-report.md`.
- Result: sequential validator loop exited `0`; each changed by-* target/support/report reached `ok: 1`. Validator `--apply` refreshed generated/projected stats.

Leases:
- Acquired: `by-memory/0x004b13d0-0x004b1585.PoolAllocatorCore.md`, `by-memory/0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront.md`, `by-memory/0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper.md`, `by-memory/0x00549c00-0x00549c18.PoolAllocatorFreeChunkList.md`, `by-type/by-struct/PoolAllocatorLayout.md`, `by-type/by-struct/-coverage-report.md`, `by-class/PoolAllocator.md`, `by-file/PoolAllocator.md`, and `tools/leaser/Agents/Agent-C001/notes.md`.
- Release status: final unlease attempt returned `Agent-C001: No active leases` because the original leases had already expired/purged during validation and closeout; follow-up `current_leases.md` showed no active C001 leases. Notes was then briefly re-leased to record this outcome and again to correct the support-page score bullets.

Supervisor-owned `by-memory/-coverage-report.md` rows:
- Supervisor applied and validated the four replacement rows below on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --queue-timeout 240`; result `ok: 1`. No C001 PoolAllocator supervisor-owned `by-memory/-coverage-report.md` rows remain pending.
- Placement context retained for audit: replaced existing rows [UID:000152] and [UID:000153] in the `0x004b13d0` / `0x004b1585` PoolAllocator neighborhood; replaced [UID:0001F4] and [UID:00023L] in the PoolAllocator helper neighborhood around `0x00549bd0` / `0x00549c18`, preserving the current indentation.
- Replace existing [UID:000152] row with:
```text
    - [UID:000152][0x004b13d0-0x004b1585.PoolAllocatorCore](by-memory/0x004b13d0-0x004b1585.PoolAllocatorCore.md) 0x004b13d0-0x004b1585 | class-method-island | PoolAllocatorCore : reconstructable : 86% : strong : PoolAllocator method island; 2026-06-16 IDA confirms constructor/allocate/free/destructor bounds, decompiled field transitions, 19 constructor wrappers, 33 allocation callers, 30 free callers, 19 cleanup wrappers, saved allocator mechanics names, helper edges to chunk allocate/free, and remaining final source-name/source-placement blockers.
```
- Replace existing [UID:000153] row with:
```text
    - [UID:000153][0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront](by-memory/0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront.md) 0x004b14c0-0x004b14ef | intrusive-list helper | ThreadSafeNodeListPushFront : reconstructable : 85% : strong : [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md)-owned free-list return helper / `ThreadSafeNodeList` behavior alias; 2026-06-16 IDA confirms `PoolAllocator_Free`, exact `0x2f` body, 30 allocator-shaped callers, critical-section-only callees, `this+0x0c` head plus `this+0x10` lock push, and no standalone ThreadSafeNodeList proof.
```
- Replace existing [UID:0001F4] row with:
```text
    - [UID:0001F4][0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper](by-memory/0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper.md) 0x00549bd0-0x00549bf1 | allocator-private helper | PoolAllocatorChunkHelper : reconstructable : 85% : strong : Attached to PoolAllocator file parent; 2026-06-16 IDA confirms saved `PoolAllocator_AllocateChunk` name, exact `0x21` body, sole caller from `PoolAllocator_Allocate`, `blocksPerChunk * blockSize + 4` allocation, chunk-list prepend, and remaining private helper spelling/source-visibility blocker.
```
- Replace existing [UID:00023L] row with:
```text
    - [UID:00023L][0x00549c00-0x00549c18.PoolAllocatorFreeChunkList](by-memory/0x00549c00-0x00549c18.PoolAllocatorFreeChunkList.md) 0x00549c00-0x00549c18 | allocator-private helper | PoolAllocatorFreeChunkList : reconstructable : 85% : strong : Attached to PoolAllocator file parent; 2026-06-16 IDA confirms saved `PoolAllocator_FreeChunkList` name, exact `0x18` loop, destructor caller at `0x004b1553`, chunk-header next traversal, CRT free call, and remaining private helper spelling/source-visibility blocker.
```

## 2026-06-16 Assignment - C001-goal2-memory-ida-refresh-loadframe-menuitem-state-20260616-20

Assigned targets:
- [UID:0002P6] `by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md`
- [UID:0002JH] `by-memory/0x00516f80-0x00516f8d.MenuItemSetStateFlag0.md`
- [UID:0002JI] `by-memory/0x00516fa0-0x00516fad.MenuItemSetStateFlag1.md`

Instructions:
- Read and follow `Agent-C001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is an exact low-completion memory plus safe IDA refresh batch from refreshed `project-level/-auto-completion-stats.md`. Quick-peek shows all three targets at `80/88` with known owner/emitter routes: [UID:0002P6] through [UID:0000K1] `ImageFrameTable`, and [UID:0002JH]/[UID:0002JI] through [UID:00007V] `MenuItem`.
- Refresh current IDA function names/bounds, raw-function/no-function state, callers/xrefs, decompilation or raw disassembly, byte padding, and support evidence. For [UID:0002P6], recheck adjacent raw helper evidence at `0x004d1660` and `0x004d1710`; create or recommend exact split pages only if current evidence and by-structure rules support it. For [UID:0002JH]/[UID:0002JI], recheck paired accessors, `MenuItemLayouts`, `MenuItem`, `PopupMenuControls`, and downstream flag semantics.
- Apply only evidence-backed low-risk IDA improvements. Do not create raw functions, force speculative prototypes/type/member edits, or rename source-facing names without enough evidence.
- Investigate final source-quality blockers now: helper/method names, output record and flag field names, caller/reachability gaps, source placement, raw-function split decisions, and final-C++ eligibility. Do not merely list blockers without checking evidence.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, saved IDA changes, and exact pending supervisor-owned report rows.

## 2026-06-16 - C001-goal2-memory-ida-refresh-loadframe-menuitem-state-20260616-20 closeout

Changed files and scores:
- `by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md`: `80/88 -> 86/90`. Owner/emitter retained [UID:0000K1] `ImageFrameTable`; exact range remains a reconstructable ImageFrameTable frame-table projection helper; final C++ remains blank.
- `by-memory/0x00516f80-0x00516f8d.MenuItemSetStateFlag0.md`: `80/88 -> 85/90`. Owner/emitter retained [UID:00007V] `MenuItem`; source-file root remains [UID:0000MN] `PopupMenuControls`; exact raw range stays a raw method page, not an IDA function.
- `by-memory/0x00516fa0-0x00516fad.MenuItemSetStateFlag1.md`: `80/88 -> 85/90`. Owner/emitter retained [UID:00007V] `MenuItem`; source-file root remains [UID:0000MN] `PopupMenuControls`; exact raw range stays a raw method page, not an IDA function.
- Support doc updated without score change: `by-file/ImageFrameTable.md` remained `89/86`.
- Validator `--apply` refreshed `project-level/-auto-completion-stats.md` projected path completion data.

Evidence and blocker investigations:
- Live IDA MCP session `b001_mappane_0001AW_20260616` (`NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready) was used for current names/bounds, bytes, disassembly, xrefs, pointer searches, and decompilation.
- `0x004d1600` was a modeled IDA function named `sub_4D1600`, size `0x5d`, with decompilation matching the existing frame-record projection behavior: index bounds check, invalid output clears at output `+4/+36`, valid stride-24 record selection, 16-byte rectangle/vector copy, output `+36`, and span calculation from next/current record fields.
- `analyze_function 0x004d1600` showed no callees, ten modeled caller functions (`sub_4D1A20`, `sub_4DD2C0`, `sub_4DE190`, `sub_4E0D70`, `sub_4E21D0`, `sub_4E2EB0`, `sub_4E4210`, `sub_4E4280`, `sub_4FF7D0`, `sub_55B5D0`), and `xrefs_to` showed 81 total xrefs including repeated raw/generated render-table sites.
- Adjacent helper split/range blockers were rechecked: `lookup_funcs` still reports no function objects at `0x004d1660` and `0x004d1710`; `get_bytes` confirmed padding and raw helper bytes through `0x004d172d`; `insn_query` reconfirmed the existing [UID:00031T] payload-copy and [UID:00031U] rect-copy helper bodies; `xrefs_to` and pointer-byte searches for `0x004d1660` and `0x004d1710` returned zero. No new split page was needed because both exact helper pages already exist.
- MenuItem state setter raw/no-function state was rechecked: `lookup_funcs` reports no function objects at `0x00516f80` or `0x00516fa0`; bytes and disassembly confirm exact setter bodies separated by `align 10h` padding, writing `[ecx+14h]` and `[ecx+15h]` respectively with `ret 4`.
- Paired accessor/support semantics were rechecked through `by-memory/0x00516f70-0x00516f74.MenuItemStateFlag0Accessor.md`, `by-memory/0x00516f90-0x00516f94.MenuItemStateFlag1Accessor.md`, `by-type/by-struct/MenuItemLayouts.md`, `by-class/MenuItem.md`, `by-file/PopupMenuControls.md`, and `by-memory/0x005170f0-0x005171a2.StringMenuItemDrawItem.md`. Current evidence supports `+0x14` as an enabled/interactable byte and `+0x15` as a selected/highlighted rendering byte, but not final source-facing flag or setter names.
- `xrefs_to` and little-endian pointer-byte searches for both setter starts and both accessor starts returned zero, so direct caller/reachability remains unresolved for the raw MenuItem methods. This limits final C++ and IDA function creation but no longer blocks 85+ documentation confidence.
- Source-quality blockers investigated and left unresolved only where evidence remains unsafe: final ImageFrameTable output-record/table field names, exact private helper source spellings, final MenuItem `+0x14/+0x15` flag names, raw setter caller routing, and final source signatures/prototypes.

IDA DB changes:
- Initial rename attempt for `0x004d1600` used the wrong current MCP rename schema and failed without changing the database; a save was accidentally invoked afterward but there was no mutation from that failed attempt.
- Correct dry-run rename accepted `sub_4D1600 -> LoadFrameDrawRecord`; the rename was applied and saved. `idb_save` returned `ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Post-save lookup confirmed both `0x004d1600` and `LoadFrameDrawRecord` resolve to IDA function `LoadFrameDrawRecord`, size `0x5d`.
- No raw functions were created at `0x004d1660`, `0x004d1710`, `0x00516f80`, or `0x00516fa0`. No MenuItem setter/accessor renames, prototypes, type, member, or global edits were made because final source-facing names remain provisional.

Validation commands/results:
- `python .\tools\validator.py --mode file --file by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory/0x00516f80-0x00516f8d.MenuItemSetStateFlag0.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory/0x00516fa0-0x00516fad.MenuItemSetStateFlag1.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-file/ImageFrameTable.md --apply --queue-timeout 240`
- Result: each validator command exited `0` and each changed by-* target/support page reached `ok: 1`.

Leases:
- Acquired leases for `by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md`, `by-memory/0x00516f80-0x00516f8d.MenuItemSetStateFlag0.md`, `by-memory/0x00516fa0-0x00516fad.MenuItemSetStateFlag1.md`, `by-file/ImageFrameTable.md`, and `tools/leaser/Agents/Agent-C001/notes.md`.
- Release status: target/support unlease returned `Rejected[No active lease]` for all four target/support paths because the original leases had already expired after validation and notes work; notes was then re-leased to record this release status, released successfully, briefly re-leased to correct this final release line, and is pending final unlease.

Supervisor-owned `by-memory/-coverage-report.md` rows:
- Do not edit `by-memory/-coverage-report.md` directly. Placement context: replace the existing [UID:0002P6] row in the [UID:000176] `ImageFrameTable` helper neighborhood around `0x004d1600`; replace the existing [UID:0002JH] and [UID:0002JI] rows in the [UID:0001BK] `MenuPaneAndItems` / `MenuItem` state-helper neighborhood around `0x00516f80` and `0x00516fa0`, preserving existing indentation.
- Replace existing [UID:0002P6] row with:
```text
        - [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md) 0x004d1600-0x004d165d | function | LoadFrameDrawRecord : reconstructable : 86% : strong : Pure ImageFrameTable frame-table projection helper; 2026-06-16 C001 IDA confirms exact `0x5d` modeled body, saved `LoadFrameDrawRecord` IDA name, no callees, ten modeled caller functions, 81 total xrefs including raw generated render-table sites, existing adjacent split helpers [UID:00031T]/[UID:00031U], and remaining final signature/type/field-name blockers.
```
- Replace existing [UID:0002JH] row with:
```text
        - [UID:0002JH][0x00516f80-0x00516f8d.MenuItemSetStateFlag0](by-memory/0x00516f80-0x00516f8d.MenuItemSetStateFlag0.md) 0x00516f80-0x00516f8d | raw method | MenuItemSetStateFlag0 : reconstructable : 85% : strong : Raw MenuItem low state-byte setter; 2026-06-16 C001 IDA confirms no function object at `0x00516f80`, exact `55 8b ec ... c2 04 00` body, `[ecx+14h]` byte write, no xrefs or little-endian pointer hits, isolated padding, paired accessor at `0x00516f70`, and support-chain enabled/interactable semantics through MenuItem/MenuItemLayouts/MenuPane scans while final source flag/method name remains unresolved.
```
- Replace existing [UID:0002JI] row with:
```text
        - [UID:0002JI][0x00516fa0-0x00516fad.MenuItemSetStateFlag1](by-memory/0x00516fa0-0x00516fad.MenuItemSetStateFlag1.md) 0x00516fa0-0x00516fad | raw method | MenuItemSetStateFlag1 : reconstructable : 85% : strong : Raw MenuItem high state-byte setter; 2026-06-16 C001 IDA confirms no function object at `0x00516fa0`, exact `55 8b ec ... c2 04 00` body, `[ecx+15h]` byte write, no xrefs or little-endian pointer hits, isolated padding, paired accessor at `0x00516f90`, and selected/highlighted rendering semantics through MenuItemLayouts/StringMenuItemDrawItem while final source flag/method name remains unresolved.
```

Supervisor integration update (2026-06-16): supervisor applied the exact [UID:0002P6], [UID:0002JH], and [UID:0002JI] `by-memory/-coverage-report.md` replacement rows, then validated the shared report and the three related memory docs with scoped `validator.py --mode file --apply --queue-timeout 240`; all passes exited `0` with `ok:1`. No C001 supervisor-owned memory rows remain pending for `C001-goal2-memory-ida-refresh-loadframe-menuitem-state-20260616-20`.

## 2026-06-16 Assignment - C001-goal2-memory-ida-refresh-password-change-replies-20260616-21

Assigned targets:
- [UID:0002QD] `by-memory/0x004febf0-0x004fee11.HandlePasswordChangeReply.md`
- [UID:0002QE] `by-memory/0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple.md`

Instructions:
- Read and follow `Agent-C001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, safe IDA-edit rules, and the active source-quality investigation policy.
- This is an exact low-completion memory plus safe IDA refresh batch from refreshed `project-level/-auto-completion-stats.md`. Quick-peek shows both targets at `80/88`, known owner/emitter [UID:0000I3] `ChangePasswordDialogPane`, and support through [UID:00022W] `ChangePasswordDialogPacketHelpers`.
- Refresh current IDA names/bounds, callers/xrefs, decompilation, local switch-table/padding boundaries, packet result/message semantics, alert/dimmer/close helper calls, and the `0x004fee40` RankingDialog-pollution exclusion.
- Apply only evidence-backed low-risk IDA improvements, such as function renames, when current IDA evidence supports them. Do not force speculative prototypes, type/member edits, raw-function creation, or source-facing method names without enough proof.
- Refresh direct support docs/reports where needed: [UID:00022W] `ChangePasswordDialogPacketHelpers`, [UID:0000I3] `ChangePasswordDialogPane`, class/file/ignored rows, and coverage rows.
- Investigate final source-quality blockers now: final handler names, packet opcode/result-code names, dialog field/control names, dispatcher reachability for the simple sibling, source placement, and final-C++ eligibility. Do not merely list blockers without checking evidence.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, saved IDA changes, and exact pending supervisor-owned report rows.

## 2026-06-16 - C001-goal2-memory-ida-refresh-password-change-replies-20260616-21 closeout

Changed files and scores:
- `by-memory/0x004febf0-0x004fee11.HandlePasswordChangeReply.md`: `80/88 -> 86/91`. Owner/emitter retained [UID:0000I3] `ChangePasswordDialogPane`; exact method/helper page now uses saved IDA name `ChangePasswordDialogPane_HandlePasswordChangeReply`; final C++ remains blank.
- `by-memory/0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple.md`: `80/88 -> 85/90`. Owner/emitter retained [UID:0000I3] `ChangePasswordDialogPane`; exact method/helper page now uses saved IDA name `ChangePasswordDialogPane_HandlePasswordChangeReplySimple`; final C++ remains blank because dispatcher registration is still unresolved.
- `by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md`: `85/86 -> 86/88`. Aggregate support remains owned/emitted by [UID:0000I3] `ChangePasswordDialogPane`.
- `by-class/ChangePasswordDialogPane.md`: evidence refreshed; score unchanged `85/89`.
- `by-file/ChangePasswordDialogPane.md`: evidence refreshed; score unchanged `85/88`.
- Validator `--apply` refreshed `project-level/-auto-completion-stats.md` projected path completion and generated metadata.

Owner/emitter decisions:
- [UID:0002QD], [UID:0002QE], and [UID:00022W] remain under canonical file owner/emitter [UID:0000I3] `ChangePasswordDialogPane`.
- [UID:0002QE] remains excluded from `RankingDialog` ownership; the observed RankingDialog connection is generated-source/reference pollution rather than ownership or source placement evidence.
- Class/file routing for `ChangePasswordDialogPane` remains unchanged; no new split page was needed.

Evidence and blocker investigations:
- Live IDA MCP session `b001_mappane_0001AW_20260616` (`NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready) was used for current names/bounds, bytes, xrefs, decompilation, switch-table references, pointer-byte searches, and save verification.
- Function boundaries were rechecked: `0x004febf0` exact IDA function size `0x221`/545 bytes; `0x004fee40` exact IDA function size `0x1ff`/511 bytes; `0x004ff040` is the next separate function; `0x004fee11`, `0x004fee14`, `0x004fee38`, and `0x004ff03f` are not functions.
- Padding/boundaries were checked with bytes around `0x004febe0` and `0x004ff030`: the primary reply starts after `int3` padding at `0x004febf0`, and the simple sibling ends at `0x004ff03f` padding before the unrelated `0x004ff040` function.
- Caller/reachability was rechecked: `xrefs_to 0x004febf0` found the packet-type dispatcher edge at `0x004fe551`; `xrefs_to 0x004fee40` found no direct start xrefs; little-endian pointer-byte searches for both handler starts returned zero.
- Local switch/data boundary was rechecked: `xrefs_to 0x004fee14` found the switch-support data reference from `0x004fec64`; `find_bytes` found the switch table pointer at `0x004fec67`.
- Decompilation confirmed packet semantics for both handlers: result byte from packet offset `+1`, message length from `+2`, message payload from `+3`, 256-byte stack buffer conversion through `MultiByteToWideChar`, optional alert allocation through `0x270`/624-byte helper construction, dimmer clear through `unk_69AE08`, vtable slot `+0x58`/88 focus-state updates, and close/dismiss helpers `sub_49EB90`/`sub_49DAD0` on success.
- Primary handler result-code groups were checked: `3,4,14,16,17,18,20,21` map to focus/state argument `3`; `5,6,7,8,9` map to argument `5`; `15` maps to argument `4`. Simple sibling result codes `3..8` map to focus/state argument `5`.
- Source-quality blockers investigated and left unresolved only where evidence remains unsafe: final packet opcode/result enum names, final dialog control/field names, final source name for vtable slot `+0x58`, exact close/dismiss helper names, direct dispatcher registration for the simple sibling, and whether the two reply handlers were original member functions or file-local packet callbacks.

IDA DB changes:
- Initial dry-run rename attempt used a rejected schema form; corrected batch dry-run accepted both names.
- Applied and saved function renames: `sub_4FEBF0 -> ChangePasswordDialogPane_HandlePasswordChangeReply`; `sub_4FEE40 -> ChangePasswordDialogPane_HandlePasswordChangeReplySimple`.
- Save result: `idb_save` returned `ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Post-save lookup confirmed both saved names and sizes. No raw functions were created. No prototypes, types, members, stack variables, globals, dispatcher functions, or sender/helper functions were renamed because source-facing names remain partly provisional.

Validation commands/results:
- `python .\tools\validator.py --mode file --file by-memory/0x004febf0-0x004fee11.HandlePasswordChangeReply.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory/0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-class/ChangePasswordDialogPane.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-file/ChangePasswordDialogPane.md --apply --queue-timeout 240`
- Result: each validator command exited `0` and each changed by-* target/support page reached `ok: 1`.

Leases:
- Acquired leases for `by-memory/0x004febf0-0x004fee11.HandlePasswordChangeReply.md`, `by-memory/0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple.md`, `by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md`, `by-class/ChangePasswordDialogPane.md`, `by-file/ChangePasswordDialogPane.md`, and `tools/leaser/Agents/Agent-C001/notes.md`.
- Release status: final target/support/notes unlease attempt returned `Rejected[No active lease]` because the target/support leases had already expired or been purged; follow-up `tools/leaser/Agents/current_leases.md` showed no active `Agent-C001` leases. Notes was briefly re-leased to record this final release outcome and is pending final notes unlease.

Supervisor-owned `by-memory/-coverage-report.md` rows:
- Do not edit `by-memory/-coverage-report.md` directly. Placement context: replace the existing [UID:00022W] row in the ChangePasswordDialog helper cluster around the current `0x004fe790-0x004ff03f` parent row; replace the existing [UID:0002QD] and [UID:0002QE] child rows under that parent around `0x004febf0` and `0x004fee40`, preserving the current child indentation.
- Replace existing [UID:00022W] row with:
```text
    - [UID:00022W][0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers](by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md) 0x004fe790-0x004ff03f | helper-cluster | ChangePasswordDialogPacketHelpers : reconstructable : 86% : strong : IDA-confirmed password-change packet send/reply helper cluster split into exact child pages; 2026-06-16 C001 refresh saves primary/simple reply-handler IDA labels, reconfirms dispatcher and switch-table xrefs, no pointer hits for handler starts, `0x004fee40` RankingDialog pollution exclusion, raw `0x004fe790` no-xref caveat, and final packet/control/source-placement blockers.
```
- Replace existing [UID:0002QD] row with:
```text
        - [UID:0002QD][0x004febf0-0x004fee11.HandlePasswordChangeReply](by-memory/0x004febf0-0x004fee11.HandlePasswordChangeReply.md) 0x004febf0-0x004fee11 | method/helper | HandlePasswordChangeReply : reconstructable : 86% : strong : Dispatcher-reached password-change reply handler; 2026-06-16 C001 IDA confirms exact `0x221`/545-byte body, saved `ChangePasswordDialogPane_HandlePasswordChangeReply` IDA name, packet type-2 dispatcher xref at `0x004fe551`, result-code switch groups, switch-table pointer at `0x004fec67`, message decode/alert path, success close path, and unresolved final packet enum/control/helper source names.
```
- Replace existing [UID:0002QE] row with:
```text
        - [UID:0002QE][0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple](by-memory/0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple.md) 0x004fee40-0x004ff03f | method/helper | HandlePasswordChangeReplySimple : reconstructable : 85% : strong : Password-change/account-dialog reply sibling; 2026-06-16 C001 IDA confirms exact `0x1ff`/511-byte body, saved `ChangePasswordDialogPane_HandlePasswordChangeReplySimple` IDA name, no direct start xrefs or pointer hits, packet `[1]/[2]/[3]` fields, result `3..8` focus update, message decode/alert path, success close/dismiss path, `0x004ff03f` padding boundary, and RankingDialog pollution exclusion while dispatch registration remains unresolved.
```

Supervisor integration update (2026-06-16): supervisor applied the exact [UID:00022W], [UID:0002QD], and [UID:0002QE] `by-memory/-coverage-report.md` replacement rows, then validated the shared report plus [UID:00022W], [UID:0002QD], [UID:0002QE], [UID:00001L] `ChangePasswordDialogPane`, and [UID:0000I3] `ChangePasswordDialogPane` with scoped `validator.py --mode file --apply --queue-timeout 240`; all passes exited `0` with `ok:1`. No C001 supervisor-owned memory rows remain pending for `C001-goal2-memory-ida-refresh-password-change-replies-20260616-21`.

## 2026-06-16 Assignment - C001-goal2-memory-ida-refresh-helptooltip-imagelib-lifecycle-20260616-22

Assigned targets:
- [UID:00022P] `by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md`
- [UID:000172] `by-memory/0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md`

Instructions:
- Read and follow `Agent-C001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, safe IDA-edit rules, and the active source-quality investigation policy.
- This is a Goal 2 low-completion memory plus safe IDA refresh batch from refreshed `project-level/-auto-completion-stats.md`. Quick-peek shows [UID:00022P] as a known [UID:0000JU] `HelpPanes` helper cluster at `80/88`, and [UID:000172] as a non-emitting [UID:00006E]/[UID:0000K2] `ImageLib` lifecycle split-index/support page at `80/88`.
- Refresh current IDA names/bounds, raw-function/no-function state, callers/xrefs, decompilation or raw disassembly, internal padding, and support evidence. For [UID:00022P], recheck the wide-string compare, vector-16 assign helper, singleton clear helpers, alignment spans, and whether any source-quality IDA names are safe. For [UID:000172], recheck constructor/destructor child links, scalar deleting destructor tail link, `g_pEPFLib`, vtable/layout anchors, and `ResourceLayoutTable` boundary.
- Apply only evidence-backed low-risk IDA improvements. Do not force speculative prototypes/type/member edits or source-facing names without enough proof.
- Investigate final source-quality blockers now: helper/method names, vector record type, field/layout names, source placement, split/merge/range decisions, non-emitting aggregate status, and final-C++ eligibility. Do not merely list blockers without checking evidence.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, saved IDA changes, and exact pending supervisor-owned report rows.

## 2026-06-16 - C001-goal2-memory-ida-refresh-helptooltip-imagelib-lifecycle-20260616-22 closeout

Changed files and scores:
- `by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md`: `80/88 -> 86/91`. Owner/emitter retained [UID:0000JU] `HelpPanes`; C++ remains blank because the first two helpers are compiler/STL-style support emitted from surrounding source expressions and the 16-byte vector record/source split is not final.
- `by-memory/0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md`: `80/88 -> 86/91`. Remains `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, and non-emitting split-index/container status; exact constructor/destructor/scalar-deleting child pages carry reconstructable ownership.
- `by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md`: evidence/name sync only; score unchanged `85/90`.
- `by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md`: evidence/name sync only; score unchanged `85/90`.
- `by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md`: evidence/name sync only; score unchanged `85/90`.
- `by-global/g_pEPFLib.md`: `89/86 -> 89/87`, plus `by-global/-coverage-report.md` row synced under normal lease.
- `by-type/by-vtable/ImageLibVtable.md`: evidence/name sync only; score unchanged `87/92`.
- `by-global/g_pItemHelpPane.md`: evidence/name sync only; score unchanged `86/88`.

Owner/emitter decisions:
- [UID:00022P] stays owned/emitted through [UID:0000JU] `HelpPanes`; it is mixed support for `HelpPane`, `ItemHelpPane`, `SimpleHelpPane*`, and `WillBeChangedItemPane` cleanup contexts rather than one narrower source-facing class.
- [UID:000172] stays a non-emitting ImageLib lifecycle split index. The exact child pages remain under [UID:00006E] `ImageLib` / [UID:0000K2] `ImageLib`, and [UID:000174] `ResourceLayoutTable` remains the successor boundary rather than part of the lifecycle cluster.
- [UID:0000QU] `g_pEPFLib` stays owned/emitted by [UID:0000K2] `ImageLib`; the final public type remains unresolved between `ImageLib*`, `ResourceLayoutTable*`, or a base/facet type.

Evidence and blocker investigations:
- Live IDA MCP session `b001_mappane_0001AW_20260616` (`NexusTK.exe`, Hex-Rays ready) was used for function names/bounds, xrefs, decompilation, byte padding, global/vtable labels, and post-save verification.
- HelpTooltip refresh rechecked: `0x004ce160` UTF-16 SSO inequality helper, `0x004ce1b0` 16-byte vector assign helper, four 11-byte singleton clear helpers, call sites at `0x004cd643` and `0x004c6a6e`, unwind metadata refs for the clear helpers, no callees for the clear helpers, vector helper callees, and all internal `0xcc` padding spans.
- ImageLib refresh rechecked: constructor `0x004cffb0` size `0xbf`, ordinary destructor `0x004d0070` size `0xab`, scalar deleting destructor `0x004e64a0` size `0xd2`, non-function/padding ends at `0x004d006f`, `0x004d011b`, and `0x004e6572`, constructor caller `0x004644f4`, no direct ordinary-destructor xrefs, scalar destructor vtable slot at `0x0061b654`, vptr refs at `0x004d0009`/`0x004d009a`/`0x004e64d1`, `g_pEPFLib` lifecycle writes/clears, and `ResourceLayoutTable` boundary at `0x004d0120`.
- Source-quality blockers investigated and retained only where unsafe: HelpPanes vector record type, whether the first two helpers should ever be hand-emitted, final source split among `HelpPanes.cpp`/`ItemHelpPane.cpp`/`WillBeChangedPanes.cpp`, ImageLib constructor second-argument meaning, private field names, inherited/shared vtable slot name, and final `ImageLib` versus `ResourceLayoutTable` source/API boundary.

IDA DB changes:
- Dry-run rename batch accepted 14/14 candidates.
- Applied and saved function labels: `sub_4CE160 -> HelpPanes_WideSsoStringNotEqual`; `sub_4CE1B0 -> HelpPanes_Vector16AssignRange`; `sub_4CE310 -> ClearItemHelpPaneSingleton`; `sub_4CE320 -> ClearSimpleHelpPane2Singleton`; `sub_4CE330 -> ClearSimpleHelpPaneSingleton`; `sub_4CE340 -> ClearWillBeChangedItemPaneSingleton`; `sub_4CFFB0 -> ImageLib_Constructor`; `sub_4D0070 -> ImageLib_Destructor`; `sub_4E64A0 -> ImageLib_ScalarDeletingDestructor`.
- Applied and saved data labels: `unk_69AE04 -> g_pItemHelpPane`; `dword_67A7D4 -> g_pSimpleHelpPane2`; `unk_69AE00 -> g_pSimpleHelpPane`; `dword_67A744 -> g_pEPFLib`; `off_61B654 -> ImageLib_vftable`.
- Save result: `idb_save` returned `ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`. Post-save `lookup_funcs`/`entity_query` confirmed the saved labels.
- Skipped unsafe IDA edits: prototypes, structure/member definitions, stack/local names, raw function creation, source-facing vector record type, inherited vtable slot name, and ResourceLayoutTable/ImageLib type merge.

Validation commands/results:
- Ran `python .\tools\validator.py --mode file --file <changed-by-star-file> --apply --queue-timeout 240` for the two assigned memory targets, three ImageLib child memory pages, `by-global/g_pEPFLib.md`, `by-type/by-vtable/ImageLibVtable.md`, `by-global/g_pItemHelpPane.md`, and `by-global/-coverage-report.md`.
- Result: validator loop exited `0`; each changed by-* target/support/report page reached `ok: 1`. The [UID:00022P] scan updated `86/91` and removed it from generated low-score lists; the [UID:000172] scan updated `86/91`; the [UID:0000QU] scan updated confidence to `87`; `by-global/-coverage-report.md` validated with `ok:1`.

Leases:
- Acquired leases for `by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md`, `by-memory/0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md`, `by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md`, `by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md`, `by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md`, `by-global/g_pEPFLib.md`, `by-type/by-vtable/ImageLibVtable.md`, `by-global/g_pItemHelpPane.md`, `by-global/-coverage-report.md`, and `tools/leaser/Agents/Agent-C001/notes.md`.
- Release status: final unlease returned `Rejected[No active lease]` for target/support/notes paths that had already expired or been purged, released `by-global/-coverage-report.md` successfully, and follow-up `tools/leaser/Agents/current_leases.md` showed no active leases. Notes was briefly re-leased to record this release status and is pending final notes unlease.

Supervisor-owned `by-memory/-coverage-report.md` rows:
- Do not edit `by-memory/-coverage-report.md` directly. Placement context: replace the existing [UID:00022P] row at the HelpPanes helper neighborhood around current line 1683; replace the existing [UID:000172] row in the ImageLib lifecycle neighborhood around current line 1742, preserving indentation.
- Replace existing [UID:00022P] row with:
```text
    - [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md) 0x004ce160-0x004ce34b | mixed-helper-cluster | HelpTooltipSupportHelpers : reconstructable : 86% : strong : HelpPanes support helper cluster; 2026-06-16 C001 live IDA confirms saved `HelpPanes_WideSsoStringNotEqual`, `HelpPanes_Vector16AssignRange`, and four singleton-clear helper labels, exact function starts/sizes, ItemHelpPane/HelpPane callers, unwind cleanup refs, clear-helper stores to named singleton globals, vector helper callees, internal `0xcc` padding, and remaining vector-record/source-split/final-C++ blockers.
```
- Replace existing [UID:000172] row with:
```text
    - [UID:000172][0x004cffb0-0x004d011b.ImageLibLifecycleCluster](by-memory/0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md) 0x004cffb0-0x004d011b | class-method-cluster | ImageLibLifecycleCluster : ignored/non-emitting : 86% : strong : Non-emitting local lifecycle split index for ImageLib constructor/destructor code only; 2026-06-16 C001 live IDA confirms saved `ImageLib_Constructor`, `ImageLib_Destructor`, `ImageLib_ScalarDeletingDestructor`, `g_pEPFLib`, and `ImageLib_vftable` labels, exact constructor/destructor bounds, scalar-deleting tail linkage, `ResourceLayoutTable` successor boundary, vtable/global xrefs, padding bytes, and unresolved constructor-parameter/private-field/source-API blockers.
```

Supervisor integration update (2026-06-16): supervisor applied the exact [UID:00022P] and [UID:000172] `by-memory/-coverage-report.md` replacement rows, then validated the shared report plus [UID:00022P], [UID:000172], the three ImageLib lifecycle child pages, [UID:0000QU] `g_pEPFLib`, [UID:0001M8] `ImageLibVtable`, [UID:0000QD] `g_pItemHelpPane`, and `by-global/-coverage-report.md` with scoped `validator.py --mode file --apply --queue-timeout 240`; all passes exited `0` with `ok:1`. No C001 supervisor-owned memory rows remain pending for `C001-goal2-memory-ida-refresh-helptooltip-imagelib-lifecycle-20260616-22`.

## 2026-06-16 Assignment - C001-goal2-global-ida-refresh-cashshop-weather-userstatus-20260616-23

Assigned targets:
- [UID:0000QH] `by-global/g_pCashShopRequest.md`
- [UID:0000TP] `by-global/WeatherLayerGlobals.md`
- [UID:0000PS] `by-global/g_activeUserStatusPane.md`

Instructions:
- Read and follow `Agent-C001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, safe IDA-edit rules, and the active source-quality investigation policy.
- This is a Goal 2 low-confidence global/IDA refresh batch from refreshed `project-level/-auto-completion-stats.md`. Supervisor quick-peek shows bounded global pages with existing owners/emitters and confidence `84`, not broad source-split targets.
- Refresh current IDA data names, address/size facts, writer/read xrefs, containing functions, relevant decompilation, neighboring-global boundaries, support memory/class/file/type pages, and generated-output implications.
- For [UID:0000QH], resolve or narrow the `g_pCashShopRequest` versus FileDownloader/download-dispatcher type/name conflict as far as evidence supports; recheck whether any IDA data rename is now safe.
- For [UID:0000TP], recheck rain/snow table starts, descriptor/guard storage, render callback dependency ownership, `g_activeMapPane`/weather-state aliasing, and one-file versus per-layer source-placement blockers.
- For [UID:0000PS], recheck the `UserStatusPane` singleton lifecycle, high fan-out readers, inventory/status aliases, and final canonical global/type/name blockers.
- Apply only evidence-backed low-risk IDA improvements. Do not force speculative prototypes/type/member edits, source-facing names, or ownership changes without enough proof.
- Investigate final source-quality blockers now; do not merely repeat them. Resolve supported items, document exact evidence checked for unresolved blockers, or keep/lower scores if unresolved issues materially limit confidence.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, saved IDA changes, and exact pending supervisor-owned report rows.

## 2026-06-16 - C001-goal2-global-ida-refresh-cashshop-weather-userstatus-20260616-23 closeout

Changed files and scores:
- `by-global/g_pCashShopRequest.md`: `88/84 -> 89/86`. Owner/emitter retained [UID:0000JC] `FileDownloader`; final public global type/name remains open, and C++ remains blank.
- `by-global/WeatherLayerGlobals.md`: `90/84 -> 91/87`. Owner/emitter retained [UID:0000P8] `WeatherLayerPane`; final table/callback names and one-file/per-layer source split remain open, and C++ remains blank.
- `by-global/g_activeUserStatusPane.md`: `90/84 -> 91/88`. Owner/emitter retained [UID:0000P2] `UserStatusPane`; saved IDA data label now supports the canonical doc name, and C++ remains blank pending field/declaration cleanup.
- `by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md`: `86/89 -> 87/90`. Owner/emitter retained [UID:0000JC] `FileDownloader`.
- `by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md`: `86/89 -> 87/91`. Owner/emitter retained [UID:0000P2] `UserStatusPane`.
- `by-global/-coverage-report.md`: synced the three changed global rows.

Evidence and blocker investigations:
- Live IDA MCP session `b001_mappane_0001AW_20260616` was used for current data names, bytes, xrefs, decompilation, function labels, and save verification.
- `g_pCashShopRequest`: checked `0x0067a730-0x0067a750` bytes, nine direct xrefs to `0x0067a738`, FileDownloader constructor/destructor/scalar-deleting/clear-helper decompilation, application cleanup, and submit helpers `0x0041b180/0x0041b200/0x0041b270`. Evidence still supports FileDownloader lifetime, but the original source-facing global name/type remains unresolved; skipped `dword_67A738 -> g_pFileDownloader` despite successful dry-run.
- `WeatherLayerGlobals`: checked rain table start xrefs, snow threshold/pattern starts, descriptor/guard storage, zero-filled descriptor bytes, weather method decompilation, callback dependency calls, and `dword_67A764 + 1008` aliasing. Skipped table/callback data renames because names and callback ownership remain provisional.
- `g_activeUserStatusPane`: checked neighboring names/bytes, 67 direct xrefs, lifecycle decompilation, MyItemList/ChangeSlot/Wield/Wear consumer decompilation for `+0x284`, alias pollution against `g_pEffectObjImageLib` and local-player names, and saved the canonical IDA data label.

IDA DB changes:
- Dry-run accepted and applied/saved 14 low-risk labels.
- Function labels saved: `sub_5B83B0 -> UserStatusPane_Constructor`; `sub_5B8530 -> UserStatusPane_CleanupBody`; `sub_5BFC00 -> ClearActiveUserStatusPane`; `sub_5BFF20 -> UserStatusPane_ScalarDeletingDestructor`; `sub_5C1460 -> RainingLayerPane_OnPaint`; `sub_5C1810 -> RainingLayerPane_DrawRainOnTarget`; `sub_5C1C80 -> SnowingLayerPane_UpdateAndRenderSnowParticles`; `sub_5C1F50 -> SnowingLayerPane_RandomizeSnowParticles`; `sub_5C20E0 -> SnowingLayerPane_RenderSnowParticles`; `sub_41A670 -> FileDownloader_Constructor`; `sub_41A6F0 -> FileDownloader_Destructor`; `sub_41B2F0 -> ClearFileDownloaderRequestGlobal`; `sub_41B610 -> FileDownloader_ScalarDeletingDestructor`.
- Data label saved: `unk_69AE0C -> g_activeUserStatusPane`.
- Save result: `idb_save ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`. Post-save lookup confirmed the function labels and `g_activeUserStatusPane` data label.
- Skipped unsafe IDA edits: `dword_67A738 -> g_pFileDownloader`, weather table data labels such as `word_6702C8 -> g_minimapRainStreaks`, render callback labels such as `unk_69B3E0 -> g_pfnDrawWeatherPixel`, prototypes, types, members, locals, and source-facing table/callback declarations.

Validation commands/results:
- `python .\tools\validator.py --mode file --file by-global/g_pCashShopRequest.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-global/WeatherLayerGlobals.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-global/g_activeUserStatusPane.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-global/-coverage-report.md --apply --queue-timeout 240`
- Result: each command exited `0`; each changed by-* target/support/report page reached `ok:1`. The first target scan removed [UID:0000QH] from the current low-confidence generated stats rows; later scans likewise refreshed the changed scores/metadata and autogen reports.

Leases:
- Acquired leases for `by-global/g_pCashShopRequest.md`, `by-global/WeatherLayerGlobals.md`, `by-global/g_activeUserStatusPane.md`, `by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md`, `by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md`, `by-global/-coverage-report.md`, and `tools/leaser/Agents/Agent-C001/notes.md`.
- Release status: explicit unlease after validation returned `Success` for all target/support/report/notes paths. Follow-up `tools/leaser/Agents/Agent-C001/current_leases.md` showed no active C001 leases; only Supervisor-held files remained, including `by-memory/-coverage-report.md`.

Supervisor-owned `by-memory/-coverage-report.md` rows:
- Do not edit `by-memory/-coverage-report.md` directly. Placement context: replace the existing [UID:0001OP] row around current line 4261 in the `0x0067a738` global pointer neighborhood; replace the existing [UID:0001PE] row around current line 4351 in the `0x0069ae0c` status-pane singleton neighborhood, preserving indentation.
- Replace existing [UID:0001OP] row with:
```text
    - [UID:0001OP][0x0067a738-0x0067a73c.g_pCashShopRequest](by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md) 0x0067a738-0x0067a73c | global pointer | g_pCashShopRequest : reconstructable : 87% : strong : FileDownloader/download-request dispatcher singleton pointer attached to FileDownloader; 2026-06-16 C001 live IDA confirms zero storage, exactly nine xrefs, saved FileDownloader lifecycle labels, constructor/destructor/application-cleanup behavior, fitting-room/item-shop consumer reads, alias-pollution caveat, neighboring pointer boundaries, skipped unsafe `g_pFileDownloader` data rename, and blank final C++ pending final downloader/request-dispatcher type/name.
```
- Replace existing [UID:0001PE] row with:
```text
    - [UID:0001PE][0x0069ae0c-0x0069ae10.g_activeUserStatusPane](by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md) 0x0069ae0c-0x0069ae10 | global pointer | g_activeUserStatusPane : reconstructable : 87% : strong : Active UserStatusPane singleton pointer with saved `g_activeUserStatusPane` IDA data label, current zero-initialized storage, neighboring boundaries, stable 67 xrefs, saved lifecycle function labels, representative item/status consumer decompilation for `+0x284`, alias caveats, UserStatusPane owner/emitter route, and blank final C++ while declaration linkage and high-fanout field naming remain unresolved.
```

Supervisor integration update (2026-06-16): supervisor applied the exact [UID:0001OP] and [UID:0001PE] `by-memory/-coverage-report.md` replacement rows from this global/IDA refresh checkpoint, then validated the shared report plus [UID:0001OP] and [UID:0001PE] with scoped `validator.py --mode file --apply --queue-timeout 240`; all passes exited `0` with `ok:1`. No C001 supervisor-owned memory rows remain pending for `C001-goal2-global-ida-refresh-cashshop-weather-userstatus-20260616-23`.

## 2026-06-16 Assignment - C001-goal2-global-ida-refresh-metaman-chat-screendimmer-20260616-24

Assigned targets:
- [UID:0000RL] `by-global/g_pMetaMan.md`
- [UID:0000SX] `by-global/GetChatButtonAtPoint.md`
- [UID:0000S5] `by-global/g_pScreenDimmer.md`

Instructions:
- Read and follow `Agent-C001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, safe IDA-edit rules, and the active source-quality investigation policy.
- This is a Goal 2 low-confidence/global completion plus safe IDA refresh batch from refreshed `project-level/-auto-completion-stats.md`. Supervisor quick-peek shows bounded global/helper pages with existing owners/emitters and direct memory/storage support.
- Refresh current IDA names, exact storage/function bounds, xrefs, decompilation or raw disassembly, neighboring boundaries, support memory/class/file/type pages, and generated-output implications.
- For [UID:0000RL], recheck `g_pMetaMan` lifecycle, `MetaMan` constructor/destructor/clear helper, metadata consumer families, adjacent global boundary, and whether a low-risk IDA data/function label refresh is justified.
- For [UID:0000SX], recheck `GetChatButtonAtPoint` function bounds, switch-table tail, caller coordinate signature, companion rectangle helper, private Chatting source placement, and whether a safe IDA function label is justified.
- For [UID:0000S5], recheck `g_pScreenDimmer` lifecycle writes/clears, tiny singleton-clear helper, factory path, broad consumer aliases, exact declaration/type blocker, and whether a low-risk IDA data/function label refresh is justified.
- Apply only evidence-backed low-risk IDA improvements. Do not force speculative prototypes/type/member edits, source-facing names, or ownership changes without enough proof.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, saved IDA changes, and exact pending supervisor-owned report rows.

## 2026-06-16 - C001-goal2-global-ida-refresh-metaman-chat-screendimmer-20260616-24 closeout

Changed files and scores:
- `by-global/g_pMetaMan.md`: `86/86 -> 88/88`; owner/emitter retained [UID:0000LC] `MetaMan`.
- `by-global/GetChatButtonAtPoint.md`: `84/90 -> 86/91`; owner/emitter retained [UID:0000I5] `Chatting`.
- `by-global/g_pScreenDimmer.md`: `85/88 -> 87/89`; owner/emitter retained [UID:0000NA] `ScreenDimmer`.
- `by-memory/0x0069b410-0x0069b414.g_pMetaMan.md`: `86/90 -> 87/91`; owner/emitter retained [UID:0000LC] `MetaMan`.
- `by-memory/0x00482400-0x004824e0.GetChatButtonAtPoint.md`: `82/90 -> 85/91`; owner/emitter retained [UID:0000SX] `GetChatButtonAtPoint`.
- `by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md`: `88/90 -> 89/91`; owner/emitter retained [UID:0000NA] `ScreenDimmer`.
- `by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md`: `82/90 -> 85/91`; owner/emitter retained [UID:0000NA] `ScreenDimmer`.
- `by-global/-coverage-report.md`: synced rows for [UID:0000RL], [UID:0000S5], and [UID:0000SX].

Evidence and blocker investigations:
- Live IDA MCP session `b001_mappane_0001AW_20260616` was used for current function names, storage bytes, xrefs, decompilation, jump-table bytes, and post-save verification.
- `g_pMetaMan`: checked zero-filled neighboring bytes at `0x0069b408`, exactly 24 xrefs to `0x0069b410`, lifecycle decompilation, consumer families, adjacent `g_pWillBeChangedItemPane` boundary, and final `g_pMetaManager` alias/spelling caveat. Explicit data label remains unresolved because the supported `rename` tool rejected both `dword_69B410` and `0x0069b410` as data keys, while `entity_query names` showed no explicit slot name.
- `GetChatButtonAtPoint`: checked `lookup_funcs`, two coordinate call sites, `xrefs_to 0x004824cc`, decompilation, tail bytes at `0x004824c0`, companion rectangle table bytes at `0x004823e0`, and successor boundary. Final helper spelling and the no-xref raw rectangle companion remain documented blockers.
- `g_pScreenDimmer`: checked zero-filled neighboring bytes at `0x0069ae00`, exactly 40 xrefs, constructor/destructor/clear/deleting-destructor/factory decompilation, consumer-only reads, neighboring names, and final declaration-type/header blocker. Explicit data label remains unresolved because the supported `rename` tool rejected both `dword_69AE08` and `0x0069ae08` as data keys, while `entity_query names` showed named neighbors but no explicit slot name.

IDA DB changes:
- Dry-run accepted and applied/saved 10 low-risk function labels: `sub_5227D0 -> MetaMan_Constructor`; `sub_522860 -> MetaMan_Destructor`; `sub_524460 -> ClearMetaManSingleton`; `sub_5244E0 -> MetaMan_ScalarDeletingDestructor`; `sub_482400 -> GetChatButtonAtPoint`; `sub_559B90 -> ScreenDimmer_Constructor`; `sub_559CF0 -> ScreenDimmer_Destructor`; `sub_55A030 -> ClearScreenDimmerSingleton`; `sub_55A070 -> ScreenDimmer_ScalarDeletingDestructor`; `sub_4A12B0 -> CreateScreenDimmerFactory`.
- Save result: `idb_save ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`. Post-save `lookup_funcs` confirmed all 10 function labels.
- Skipped unsafe/unsupported IDA edits: `g_pMetaMan` and `g_pScreenDimmer` data labels because the current supported rename tool only accepted existing data names and rejected these default/unnamed slots; no prototypes, types, members, locals, comments, or raw functions were changed.

Validation commands/results:
- From `source-3/project-documentation`, ran the required command shape `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240` for `by-global/g_pMetaMan.md`, `by-global/GetChatButtonAtPoint.md`, `by-global/g_pScreenDimmer.md`, `by-memory/0x0069b410-0x0069b414.g_pMetaMan.md`, `by-memory/0x00482400-0x004824e0.GetChatButtonAtPoint.md`, `by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md`, `by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md`, and `by-global/-coverage-report.md`.
- Result: sequential validator loop exited `0`; each changed by-* target/support/report reached `ok: 1`. Validator `--apply` updated projected stats/autogen metadata and removed [UID:0000RL] from generated low-score stats during the first target run.

Leases:
- Acquired leases for all changed target/support docs, `by-global/-coverage-report.md`, and this notes file. Release status is recorded in the final response.

Supervisor-owned `by-memory/-coverage-report.md` rows:
- Do not edit `by-memory/-coverage-report.md` directly. Placement context: replace existing [UID:000107] row around current line 842, [UID:0001GB] around current line 3010, [UID:00029D] around current line 4354, and [UID:0001PJ] around current line 4380, preserving indentation.
- Replace existing [UID:000107] row with:
```text
        - [UID:000107][0x00482400-0x004824e0.GetChatButtonAtPoint](by-memory/0x00482400-0x004824e0.GetChatButtonAtPoint.md) 0x00482400-0x004824e0 | file-local helper | GetChatButtonAtPoint : reconstructable : 85% : strong : 2026-06-16 C001 live IDA refresh saved the `GetChatButtonAtPoint` label and reconfirms exact modeled body `0x00482400-0x004824c9` plus helper-owned tail through `0x004824e0`, two ChattingHandlePane::OnMouseEvent coordinate call sites at `0x00481dca`/`0x00481ec9`, fixed four-rectangle switch hit-test, RectGeometry callees, alignment NOP at `0x004824c9-0x004824cc`, jump-table xref and dwords at `0x004824cc-0x004824e0`, companion rectangle table bytes, GetChatButtonAtPoint parent attachment, and final C++ remains blank pending file-local helper spelling and raw rectangle-helper origin.
```
- Replace existing [UID:0001GB] row with:
```text
        - [UID:0001GB][0x0055a030-0x0055a03b.ScreenDimmerSingletonClear](by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md) 0x0055a030-0x0055a03b | helper | ScreenDimmerSingletonClear : reconstructable : 85% : strong : ScreenDimmer singleton-clear helper attached to ScreenDimmer file; 2026-06-16 C001 live IDA refresh saved `ClearScreenDimmerSingleton`, confirms exact 11-byte direct store to the `g_pScreenDimmer` slot, no callees/ordinary callers, one cleanup/funclet jump xref, 40 global data refs, skipped unsupported explicit data-label mutation, and final C++ remains blank pending helper source spelling.
```
- Replace existing [UID:00029D] row with:
```text
    - [UID:00029D][0x0069ae08-0x0069ae0c.g_pScreenDimmer](by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md) 0x0069ae08-0x0069ae0c | global pointer | g_pScreenDimmer : reconstructable : 89% : strong : Exact four-byte .data ScreenDimmer singleton slot attached to ScreenDimmer; 2026-06-16 C001 live IDA confirms zero-filled neighboring storage, 40 xrefs, saved ScreenDimmer lifecycle/factory labels, constructor publish/null-clear, ordinary destructor clear, direct clear-helper store, scalar deleting destructor clear, source-declared/generated-binary handling, generic UI overlay ownership, skipped unsupported explicit data-label mutation, and final C++ blank pending exact header/source declaration spelling.
```
- Replace existing [UID:0001PJ] row with:
```text
    - [UID:0001PJ][0x0069b410-0x0069b414.g_pMetaMan](by-memory/0x0069b410-0x0069b414.g_pMetaMan.md) 0x0069b410-0x0069b414 | global pointer | g_pMetaMan : reconstructable : 87% : strong : Exact four-byte `.data` slot for MetaMan; 2026-06-16 C001 live IDA refresh confirms zero-filled neighboring storage, 24 xrefs, saved MetaMan lifecycle labels, constructor publish/null clear at `0x00522806`/`0x0052280d`, destructor/helper/deleting-destructor clears at `0x005228c8`, `0x00524460`, and `0x00524550`, item-help, resource/image, session/network, and CollectionPane consumers, parent `MetaMan`, skipped unsupported explicit data-label mutation, and final C++ blank pending final declaration/header placement.
```

Supervisor integration update (2026-06-16): supervisor accepted `C001-goal2-global-ida-refresh-metaman-chat-screendimmer-20260616-24` as complete. Scores cleared the gate at [UID:0000RL] `88/88`, [UID:0000SX] `86/91`, [UID:0000S5] `87/89`, support [UID:0001PJ] `87/91`, support [UID:000107] `85/91`, support [UID:00029D] `89/91`, and support [UID:0001GB] `85/91`; owner/emitter routes remain unchanged. Supervisor applied the exact [UID:000107], [UID:0001GB], [UID:00029D], and [UID:0001PJ] `by-memory/-coverage-report.md` replacement rows and validated the shared report plus changed support memory pages (`ok:1`). No C001 supervisor-owned memory rows remain pending for this batch.

## 2026-06-16 Assignment - C001-goal2-global-ida-refresh-option-keyspeed-midi-newhuman-20260616-25

Assigned targets:
- [UID:0000TL] `by-global/SendOptionPacket11B_540E50.md`
- [UID:0000RB] `by-global/g_pKeySpeedMgr.md`
- [UID:0000RM] `by-global/g_pMidiPlayer.md`
- [UID:0000RT] `by-global/g_pNewHumanImageLib.md`

Instructions:
- Read and follow `Agent-C001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, safe IDA-edit rules, and the active source-quality investigation policy.
- This is a Goal 2 low-confidence/global safe IDA-refresh batch from refreshed `project-level/-auto-completion-stats.md`. Supervisor quick-peek shows bounded global/helper pages with existing owner/emitter routes and direct memory/storage/function support: option packet helper caller split, KeySpeedMgr singleton lifecycle, MidiPlayer singleton lifecycle/consumers, and NewHumanImageLib singleton lifecycle/consumer clusters.
- Refresh current IDA names, exact storage/function bounds, xrefs, decompilation or raw disassembly, neighboring boundaries, support memory/class/file/type pages, and generated-output implications.
- Apply only evidence-backed low-risk IDA improvements. Do not force speculative prototypes, types, members, locals, source-facing helper names, or ownership changes without enough proof.
- Investigate final source-quality blockers now: helper declaration placement, duplicate packet helper relationship, final singleton declaration/header placement, disabled or raw helper reachability, consumer classification, layout/field names, and final-C++ eligibility. Do not merely repeat blockers; resolve supported items, document exact evidence checked for unresolved blockers, or keep/lower scores if unresolved issues materially limit confidence.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, saved IDA changes, and exact pending supervisor-owned report rows.

## 2026-06-16 - C001-goal2-global-ida-refresh-option-keyspeed-midi-newhuman-20260616-25 closeout

Changed files and scores:
- `by-global/SendOptionPacket11B_540E50.md`: `85/88 -> 87/90`. Owner/emitter retained [UID:0000M7] `OptionPane`; final C++ remains blank pending helper declaration/source placement and old/new helper sharing policy.
- `by-global/g_pKeySpeedMgr.md`: `85/88 -> 87/90`. Owner/emitter retained [UID:0000KJ] `KeySpeedMgr`; final C++ remains blank pending declaration/header placement and raw setter source shape.
- `by-global/g_pMidiPlayer.md`: `85/88 -> 87/90`. Owner/emitter retained [UID:0000LD] `MidiPlayer`; final C++ remains blank pending declaration/header placement, WinMM state names, and private helper source shape.
- `by-global/g_pNewHumanImageLib.md`: `85/88 -> 87/91`. Owner/emitter retained [UID:0000LR] `NewHumanImageLib`; final C++ remains blank pending full 52-xref consumer classification, original declaration spelling, and layout/field names.
- `by-memory/0x00540e50-0x00540e91.SendOptionPacket11B.md`: `85/88 -> 87/90`. Owner/emitter retained [UID:0000M7] `OptionPane`.
- `by-memory/0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B.md`: evidence/name sync only; score unchanged `85/88`.
- `by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md`: `86/90 -> 88/91`. Owner/emitter retained [UID:0000RB] `g_pKeySpeedMgr`.
- `by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md`: `85/88 -> 87/90`. Owner/emitter retained [UID:0000RM] `g_pMidiPlayer`.
- `by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md`: `85/87 -> 86/88`. Owner/emitter retained [UID:0000LD] `MidiPlayer`.
- `by-memory/0x0067a760-0x0067a764.g_pNewHumanImageLib.md`: `85/90 -> 87/92`. Owner/emitter retained [UID:0000RT] `g_pNewHumanImageLib`.
- `by-memory/0x004e5be0-0x004e5beb.NewHumanImageLibSingletonClearHelper.md`: evidence/name sync only; score unchanged `85/93`.
- `by-global/-coverage-report.md`: synced rows for [UID:0000TL], [UID:0000RB], [UID:0000RM], and [UID:0000RT].

Owner/emitter decisions:
- [UID:0000TL] and [UID:0001DY] stay file-level/shared option protocol helpers under [UID:0000M7] `OptionPane`; they are not `NewOptionPane` methods because the live caller set still includes two `SelfLookPane` neighborhood callers.
- [UID:0000RB]/[UID:0001P7] stay owned/emitted through [UID:0000KJ] `KeySpeedMgr`; [UID:00032A] `DestroyKeySpeedMgr` remains WinMain cleanup policy that consumes the singleton rather than direct KeySpeedMgr source ownership.
- [UID:0000RM]/[UID:00029A] stay owned/emitted through [UID:0000LD] `MidiPlayer`; SoundStatusPane/SoundManager/MainMenu/BaramApp remain consumers.
- [UID:0000RT]/[UID:0001OV] stay owned/emitted through [UID:0000LR] `NewHumanImageLib`; Application, look/profile, and render paths remain consumers.

Evidence and blocker investigations:
- Live IDA MCP session `b001_mappane_0001AW_20260616` (`NexusTK.exe.i64`, Hex-Rays ready) was used for current names, function bounds, data bytes, xrefs, decompilation, dry-run rename validation, applied renames, save, and post-save verification.
- Option packet helper: checked `SendOptionPacket11B` and duplicate old `OptionPaneSendOptionPacket11B` bounds, six/four caller sets, decompiled three-byte `0x011b` packet behavior, padding bytes, and `0x00540ea0` no-function state. Remaining blocker is final original helper declaration placement and whether the two physical helpers were shared in source or duplicated by codegen/inlining.
- KeySpeedMgr: checked zeroed current singleton window, ten xrefs, constructor/destructor/restore/fast-repeat/scalar-deleting/deletion-wrapper bounds, restore `SystemParametersInfoW` range checks, disabled restore-method generated-source caveat, and raw `0x004eff60` no-function/no-xref setter. Remaining blocker is final header/global declaration and source treatment of the raw setter.
- MidiPlayer: checked zeroed singleton window, 18 xrefs, constructor/destructor/clear/scalar-deleting helper bounds and decompilation, and representative consumer classification. Remaining blockers are final declaration/header placement, WinMM state/global names, and class-versus-file-scope helper names.
- NewHumanImageLib: checked zeroed singleton window, 52 xrefs, constructor/destructor/clear-helper/shutdown refs, adjacent boundary names, and current saved labels. Remaining blockers are all-consumer classification, original singleton spelling, field/layout names, and final declaration placement. `Application_Shutdown` was dry-run accepted but skipped because the final Application method source-facing name is outside this singleton refresh.

IDA DB changes:
- Dry-run accepted 19/19 labels. Applied and saved 18 direct labels, deliberately omitting `Application_Shutdown`.
- Function labels saved: `sub_540E50 -> SendOptionPacket11B`; `sub_53E380 -> OptionPaneSendOptionPacket11B`; `sub_4EFEA0 -> KeySpeedMgr_Constructor`; `sub_4EFEE0 -> KeySpeedMgr_Destructor`; `sub_4EFF30 -> KeySpeedMgr_RestoreSystemKeyboardSettings`; `sub_4EFFA0 -> ApplyFastKeyboardRepeatSettings`; `sub_4EFFC0 -> KeySpeedMgr_ScalarDeletingDestructor`; `sub_4673C0 -> DestroyKeySpeedMgr`; `sub_525DC0 -> MidiPlayer_Constructor`; `sub_525EB0 -> MidiPlayer_Destructor`; `sub_526570 -> ClearMidiPlayerSingleton`; `sub_526580 -> MidiPlayer_ScalarDeletingDestructor`; `sub_4DFD10 -> NewHumanImageLib_Constructor`; `sub_4E0250 -> NewHumanImageLib_Destructor`; `sub_4E5BE0 -> ClearNewHumanImageLibSingleton`.
- Data labels saved: `dword_67AB48 -> g_pKeySpeedMgr`; `unk_67AB4C -> g_pMidiPlayer`; `dword_67A760 -> g_pNewHumanImageLib`.
- Save result: `idb_save ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`. Post-save `lookup_funcs` and `entity_query names` confirmed the saved labels.
- Skipped unsafe/unsupported IDA edits: `Application_Shutdown` despite dry-run acceptance; raw function creation at `0x00540ea0` and `0x004eff60`; prototypes, types, members, stack/local names, and broad playback/render/helper renames.

Validation commands/results:
- Ran `python .\tools\validator.py --mode file --file <changed-by-star-file> --apply --queue-timeout 240` from `source-3/project-documentation` for: `by-global/SendOptionPacket11B_540E50.md`, `by-global/g_pKeySpeedMgr.md`, `by-global/g_pMidiPlayer.md`, `by-global/g_pNewHumanImageLib.md`, `by-memory/0x00540e50-0x00540e91.SendOptionPacket11B.md`, `by-memory/0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B.md`, `by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md`, `by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md`, `by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md`, `by-memory/0x0067a760-0x0067a764.g_pNewHumanImageLib.md`, `by-memory/0x004e5be0-0x004e5beb.NewHumanImageLibSingletonClearHelper.md`, and `by-global/-coverage-report.md`.
- Result: sequential validator loop exited `0`; each changed by-* target/support/report page reached `ok:1`. Validator `--apply` updated projected stats/autogen metadata and synced the non-banned by-global coverage report.

Leases:
- Acquired leases for all changed target/support docs, `by-global/-coverage-report.md`, and this notes file. The first lease command also passed an unsupported `--ttl 240` option, which the leaser rejected as extra paths after successfully leasing each real file; the active lease report confirmed the real C001 leases were held before editing.
- Target/support/report leases expired naturally during the long validator loop; follow-up `current_leases.md` showed no active C001 leases. A fresh notes lease was acquired to record this final validation/release status and will be released after this notes update.

Supervisor-owned `by-memory/-coverage-report.md` rows:
- Do not edit `by-memory/-coverage-report.md` directly. Placement context: replace existing [UID:000182] around current line 1850, [UID:0001CF] around line 2487, [UID:0001DQ] around line 2680, [UID:0001DY] around line 2696, [UID:0001OV] around line 4280, [UID:0001P7] around line 4319, and [UID:00029A] around line 4320, preserving indentation.
- Replace existing [UID:000182] row with:
```text
    - [UID:000182][0x004e5be0-0x004e5beb.NewHumanImageLibSingletonClearHelper](by-memory/0x004e5be0-0x004e5beb.NewHumanImageLibSingletonClearHelper.md) 0x004e5be0-0x004e5beb | static cleanup helper | NewHumanImageLib singleton clear helper : reconstructable : 85% : very-strong : Assigned to [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) after Batch121 raised the direct file parent to 87/85; live IDA reconfirmed the exact 0xb bytes/body, saved `ClearNewHumanImageLibSingleton` and `g_pNewHumanImageLib` labels, decompiled singleton zero store, single constructor cleanup-table xref at 0x00600230, 52 g_pNewHumanImageLib lifecycle/consumer xrefs, and neighboring singleton-helper boundaries.
```
- Replace existing [UID:0001CF] row with:
```text
    - [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md) 0x00525b10-0x0052664b | aggregate | MidiPlayerAndWinMMHelpers : reconstructable : 86% : strong : MidiPlayer WinMM helper aggregate attached to `MidiPlayer.cpp`; live IDA reconfirms function inventory, modeled starts/sizes, callback/reset/track-select call graph, WinMM/document callees, saved `MidiPlayer_Constructor`, `MidiPlayer_Destructor`, `ClearMidiPlayerSingleton`, `MidiPlayer_ScalarDeletingDestructor`, and `g_pMidiPlayer` labels, boundary padding, and raw-helper/WinMM-state naming caveats.
```
- Replace existing [UID:0001DQ] row with:
```text
    - [UID:0001DQ][0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B](by-memory/0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B.md) 0x0053e380-0x0053e3c1 | function | OptionPaneSendOptionPacket11B : reconstructable : 85% : strong : Old `OptionPane` local three-byte `0x011b` packet sender; live IDA reconfirms and saved `OptionPaneSendOptionPacket11B`, exact `0x41`-byte `__stdcall` body, four callers inside `OptionPane::OnOptionCommand` at `0x0053dfff`, `0x0053e033`, `0x0053e067`, and `0x0053e09b`, stack packet stores for opcode `0x011b` plus one option-code byte, [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / queue-send call `0x00574bb0` with length `3`, padding before/after, duplicate-but-separate sibling [UID:0001DY][0x00540e50-0x00540e91.SendOptionPacket11B](by-memory/0x00540e50-0x00540e91.SendOptionPacket11B.md), direct file-level owner/emitter [UID:0000M7][OptionPane](by-file/OptionPane.md), and final C++ remains blank pending source-facing helper placement/name review.
```
- Replace existing [UID:0001DY] row with:
```text
        - [UID:0001DY][0x00540e50-0x00540e91.SendOptionPacket11B](by-memory/0x00540e50-0x00540e91.SendOptionPacket11B.md) 0x00540e50-0x00540e91 | function | SendOptionPacket11B : reconstructable : 87% : strong : Shared option-packet helper with saved `SendOptionPacket11B` IDA label; sends opcode `0x011b`/decimal `283` with one option-code byte through `g_packetSender`; live IDA confirms the `0x41`-byte body, four `NewOptionPane::OnMouseClick` callers, two `SelfLookPane` callers, adjacent `0xcc` boundaries, duplicate old-OptionPane local sender label `OptionPaneSendOptionPacket11B`, raw `0x00540ea0` no-function successor caveat, and strict file-parent gate through [UID:0000M7][OptionPane](by-file/OptionPane.md).
```
- Replace existing [UID:0001OV] row with:
```text
    - [UID:0001OV][0x0067a760-0x0067a764.g_pNewHumanImageLib](by-memory/0x0067a760-0x0067a764.g_pNewHumanImageLib.md) 0x0067a760-0x0067a764 | global pointer | g_pNewHumanImageLib : reconstructable : 87% : strong : NewHumanImageLib singleton pointer with saved `g_pNewHumanImageLib`, `NewHumanImageLib_Constructor`, `NewHumanImageLib_Destructor`, and `ClearNewHumanImageLibSingleton` labels, zeroed 0x4/4-byte storage, 52 direct xrefs, constructor publish/guard-clear decompilation, destructor/helper clears, Application shutdown read, representative render/look/profile consumers, owner/emitter route through `g_pNewHumanImageLib` and `NewHumanImageLib`, and final C++ blank pending full consumer/source-declaration/layout naming.
```
- Replace existing [UID:0001P7] row with:
```text
    - [UID:0001P7][0x0067ab48-0x0067ab4c.g_pKeySpeedMgr](by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md) 0x0067ab48-0x0067ab4c | global pointer | g_pKeySpeedMgr : reconstructable : 88% : strong : Exact four-byte KeySpeedMgr singleton slot with saved `g_pKeySpeedMgr` data label, current zeroed storage bytes, ten live IDA xrefs including B001-014 cleanup read `0x004673c0`, saved constructor/destructor/restore/fast-repeat/deleting-destructor/DestroyKeySpeedMgr function labels, constructor write at `0x004efebd`, destructor clears at `0x004efee6` and `0x004effcc`, application initialization, restore/fast-repeat helper callers, cleanup/deactivation/error readers, raw `0x004eff60` setter no-function caveat, and parent `g_pKeySpeedMgr`.
```
- Replace existing [UID:00029A] row with:
```text
    - [UID:00029A][0x0067ab4c-0x0067ab50.g_pMidiPlayer](by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md) 0x0067ab4c-0x0067ab50 | global pointer | g_pMidiPlayer : reconstructable : 87% : strong : MidiPlayer singleton pointer with saved `g_pMidiPlayer`, `MidiPlayer_Constructor`, `MidiPlayer_Destructor`, `ClearMidiPlayerSingleton`, and `MidiPlayer_ScalarDeletingDestructor` labels, current zero-filled 0x4/4-byte storage, 18 direct xrefs, constructor publish/guard-clear decompilation, destructor stream/event cleanup clear, representative Application/main-menu/SoundStatusPane/playback-helper consumers, and g_pMidiPlayer/MidiPlayer owner-emitter route.
```

Supervisor integration update (2026-06-16): supervisor accepted `C001-goal2-global-ida-refresh-option-keyspeed-midi-newhuman-20260616-25` as complete. Scores cleared the gate at [UID:0000TL] `87/90`, [UID:0000RB] `87/90`, [UID:0000RM] `87/90`, [UID:0000RT] `87/91`, support [UID:0001DY] `87/90`, [UID:0001P7] `88/91`, [UID:00029A] `87/90`, [UID:0001CF] `86/88`, and [UID:0001OV] `87/92`; owner/emitter routes remain unchanged. Supervisor applied the exact [UID:000182], [UID:0001CF], [UID:0001DQ], [UID:0001DY], [UID:0001OV], [UID:0001P7], and [UID:00029A] `by-memory/-coverage-report.md` replacement rows, revalidated the shared report plus all changed target/support docs (`ok:1`), and reran `memory_ranges.py report`; the generated memory tool report is clean with Barrier/General/Filename/Advanced errors all `None`.

## 2026-06-16 Assignment - C001-goal2-global-ida-refresh-chatting-delete-simplehelp-browser-20260616-26

Assigned targets:
- [UID:0002XA] `by-global/g_pChattingVarietySelectPane.md`
- [UID:0002WV] `by-global/g_pChattingViewport.md`
- [UID:0002W3] `by-global/g_pDeleteReplyAlert.md`
- [UID:0000S9] `by-global/g_pSimpleHelpPane.md`

Instructions:
- Read and follow `Agent-C001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, safe IDA-edit rules, and the active source-quality investigation policy.
- This is a Goal 2 low-confidence/global safe IDA-refresh batch from refreshed `project-level/-auto-completion-stats.md`. Supervisor quick-peek shows bounded singleton/global pages with known owner/emitter routes and direct storage/lifecycle support: chat mode selector, chat/system-message viewport, delete-reply alert singleton, and simple-help popup singleton.
- Refresh current IDA names, exact storage/function bounds, xrefs, decompilation or raw disassembly, neighboring boundaries, support memory/class/file/type pages, and generated-output implications.
- Apply only evidence-backed low-risk IDA improvements. Do not force speculative prototypes, types, members, locals, source-facing helper names, or ownership changes without enough proof.
- Investigate final source-quality blockers now: singleton declaration/header placement, exact source split between shared alert wrappers and board/dialog helpers, chat/system-message ownership boundaries, helper declaration names, global aliases, and final-C++ eligibility. Do not merely repeat blockers; resolve supported items, document exact evidence checked for unresolved blockers, or keep/lower scores if unresolved issues materially limit confidence.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, saved IDA changes, and exact pending supervisor-owned report rows.

## 2026-06-16 - C001-goal2-global-ida-refresh-chatting-delete-simplehelp-browser-20260616-26 closeout

Changed files and scores:
- `by-global/g_pChattingVarietySelectPane.md`: `85/88 -> 86/90`; owner/emitter retained [UID:0000I5] `Chatting`.
- `by-global/g_pChattingViewport.md`: `85/88 -> 87/90`; owner/emitter retained [UID:0000OE] `SystemMessagePanes`.
- `by-global/g_pDeleteReplyAlert.md`: `85/88 -> 87/90`; owner/emitter retained [UID:0000HW] `BulletinReplyAlerts`.
- `by-global/g_pSimpleHelpPane.md`: `85/88 -> 87/90`; owner/emitter retained [UID:0000JU] `HelpPanes`.
- `by-memory/0x0067adb8-0x0067adbc.g_pDeleteReplyAlert.md`: `85/88 -> 87/90`; owner/emitter retained [UID:0002W3] `g_pDeleteReplyAlert`.
- `by-memory/0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons.md`: `85/88 -> 86/90`; owner/emitter remains blank, `RECONSTRUCTABLE:FALSE`, split-map only.
- `by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md`: `85/91 -> 86/92`; owner/emitter remains blank, `RECONSTRUCTABLE:FALSE`, split-map only.
- `by-memory/0x0067adc4-0x0067adc8.g_pChattingViewport.md`: `85/88 -> 87/90`; owner/emitter retained [UID:0002WV] `g_pChattingViewport`.
- `by-memory/0x0067addc-0x0067ade0.g_pChattingVarietySelectPane.md`: `85/88 -> 86/90`; owner/emitter retained [UID:0002XA] `g_pChattingVarietySelectPane`.
- `by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md`: `85/88 -> 87/90`; owner/emitter retained [UID:0000S9] `g_pSimpleHelpPane`.
- `by-global/-coverage-report.md`: synced rows for [UID:0002XA], [UID:0002WV], [UID:0002W3], and [UID:0000S9].

Owner/emitter and blocker decisions:
- `g_pChattingVarietySelectPane` stays under `Chatting`; direct storage/lifecycle evidence is strong, but final C++ remains blank because the selector constructor at `0x004810f0-0x00481146` is still raw/unmodeled and compact-button helper/source-split names remain unresolved.
- `g_pChattingViewport` stays under `SystemMessagePanes`; current storage/lifecycle evidence is direct, but the final declaration/header placement and `SystemMessagePanes.cpp` versus broader `Chatting.cpp` split remain unresolved.
- `g_pDeleteReplyAlert` stays under `BulletinReplyAlerts`; source-quality review checked `DeleteReplyAlert`, `BulletinReplyAlerts`, the adjacent mail singleton, and shared alert wrapper evidence. The blocker is the exact original shared-alert versus board-dialog-private source split and final owner-dialog/list field names.
- `g_pSimpleHelpPane` stays under `HelpPanes`; storage/lifecycle evidence is direct, but exact declaration/header placement and future `HelpPanes.cpp` versus narrower tooltip-source split remain unresolved.
- The two aggregate memory support pages stay non-emitting split maps. They were updated only for current bytes/names/evidence, not forced into aggregate source ownership.

Evidence and IDA DB changes:
- Live IDA MCP session `b001_mappane_0001AW_20260616` (`NexusTK.exe.i64`, Hex-Rays ready) was used for current storage bytes, xrefs, function bounds, decompilation, dry-run rename validation, applied renames, save, and post-save verification.
- Live `get_bytes` confirmed the `0x0067adb8-0x0067adeb` board/chat singleton neighborhood and `0x0069adf0-0x0069ae17` HelpPanes singleton neighborhood as zero-filled virtual `.data` in the current IDB, superseding stale `0xffffffff` wording for the changed rows.
- `xrefs_to` confirmed exact counts: `g_pDeleteReplyAlert` 6 refs, `g_pChattingViewport` 16 refs, `g_pChattingVarietySelectPane` 7 refs, and `g_pSimpleHelpPane` 23 refs.
- Dry-run accepted and applied/saved 16 low-risk labels: `sub_47E2F0 -> DeleteReplyAlert_Constructor`; `sub_47E350 -> DeleteReplyAlert_Destructor`; `sub_47E380 -> GetDeleteReplyAlertSingleton`; `sub_47EB30 -> DeleteReplyAlert_ScalarDeletingDestructor`; `sub_481150 -> ChattingVarietySelectPane_Destructor`; `sub_483DB0 -> ChattingVarietySelectPane_ScalarDeletingDestructor`; `sub_584EA0 -> SystemMessagePane_Constructor`; `sub_5851E0 -> SystemMessagePane_Destructor`; `sub_58AAD0 -> ClearChattingViewportSingleton`; `sub_4C6F90 -> SimpleHelpPane_Constructor`; `sub_4C7290 -> SimpleHelpPane_Destructor`; `sub_4CE560 -> SimpleHelpPane_ScalarDeletingDestructor`; `sub_4A0D60 -> CloseSimpleHelpPaneSingleton`; `unk_67ADB8 -> g_pDeleteReplyAlert`; `unk_67ADC4 -> g_pChattingViewport`; `unk_67ADDC -> g_pChattingVarietySelectPane`.
- Save result: `idb_save ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`. Post-save `lookup_funcs` and decompile refs confirmed the saved labels. `ClearSimpleHelpPaneSingleton` and `g_pSimpleHelpPane` already existed. No prototypes, types, members, locals, raw functions, or source-facing ambiguous helpers were changed.
- Skipped candidates: `0x00480cd0` selector-open path and `0x00480e80` compact chat-mode paint/helper path were reviewed but not renamed because source-facing method identity is still ambiguous; mail-side `dword_67ADBC` was not mutated because it was not an assigned target in this batch.

Validation commands/results:
- Ran `python .\tools\validator.py --mode file --file <changed-by-star-file> --apply --queue-timeout 240` from `source-3/project-documentation` for: `by-global/g_pChattingVarietySelectPane.md`, `by-global/g_pChattingViewport.md`, `by-global/g_pDeleteReplyAlert.md`, `by-global/g_pSimpleHelpPane.md`, `by-memory/0x0067adb8-0x0067adbc.g_pDeleteReplyAlert.md`, `by-memory/0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons.md`, `by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md`, `by-memory/0x0067adc4-0x0067adc8.g_pChattingViewport.md`, `by-memory/0x0067addc-0x0067ade0.g_pChattingVarietySelectPane.md`, `by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md`, and `by-global/-coverage-report.md`.
- Result: sequential validator loop exited `0`; each changed by-* target/support/report reached `ok:1`. Validator `--apply` updated projected stats/autogen metadata and synced the non-banned by-global coverage report.

Leases:
- Acquired C001 leases for all changed target/support docs, `by-global/-coverage-report.md`, and this notes file before edits. The by-* leases expired naturally during validation; current lease report showed no active leases before the final notes update. A fresh notes lease was acquired for this closeout and will be released after this update.

Supervisor-owned `by-memory/-coverage-report.md` rows:
- Do not edit `by-memory/-coverage-report.md` directly. Placement context: replace existing [UID:0002AI] and [UID:0002W4] rows around current lines 4341-4342, [UID:0002B5] and [UID:0002WW] around current lines 4346-4347, [UID:0002XB] around current line 4353, and [UID:0001PC] around current line 4363, preserving indentation.
- Replace existing [UID:0002AI] row with:
```text
    - [UID:0002AI][0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons](by-memory/0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons.md) 0x0067adb8-0x0067adc0 | global-data split map | BoardMailDeleteReplyAlertSingletons : not_reconstructable : 86% : strong : Split map for adjacent board/mail reply-delete alert singleton storage; 2026-06-16 C001 live IDA refresh confirms current zero-filled virtual `.data` bytes for the pair, saved first-child `g_pDeleteReplyAlert` and DeleteReplyAlert constructor/destructor/getter/scalar labels, exact children own [UID:0002W4][0x0067adb8-0x0067adbc.g_pDeleteReplyAlert](by-memory/0x0067adb8-0x0067adbc.g_pDeleteReplyAlert.md) and [UID:0002W6][0x0067adbc-0x0067adc0.g_pMailDeleteReplyAlert](by-memory/0x0067adbc-0x0067adc0.g_pMailDeleteReplyAlert.md), and no aggregate parent assignment is forced.
```
- Replace existing [UID:0002W4] row with:
```text
        - [UID:0002W4][0x0067adb8-0x0067adbc.g_pDeleteReplyAlert](by-memory/0x0067adb8-0x0067adbc.g_pDeleteReplyAlert.md) 0x0067adb8-0x0067adbc | global pointer | g_pDeleteReplyAlert : reconstructable : 87% : strong : Exact four-byte DeleteReplyAlert singleton storage with current zero-filled virtual `.data` bytes, saved `g_pDeleteReplyAlert`, `DeleteReplyAlert_Constructor`, `DeleteReplyAlert_Destructor`, `GetDeleteReplyAlertSingleton`, and `DeleteReplyAlert_ScalarDeletingDestructor` labels, 6 refs, getter/class evidence, parent [UID:0002W3][g_pDeleteReplyAlert](by-global/g_pDeleteReplyAlert.md), and aggregate split-map boundary from [UID:0002AI][0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons](by-memory/0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons.md).
```
- Replace existing [UID:0002B5] row with:
```text
    - [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md) 0x0067adc4-0x0067adec | global-data split map | UiChatClanSingletonSlots : not_reconstructable : 86% : strong : Split map for linker-adjacent system-message, TextFilter, chat, clan, and clan-bank singleton dwords; 2026-06-16 C001 live IDA refresh reconfirms current zero-filled virtual `.data`, saved `g_pChattingViewport` and `g_pChattingVarietySelectPane` data labels plus SystemMessagePane and ChattingVarietySelectPane lifecycle/clear/destructor labels, and no aggregate parent assignment because exact four-byte children carry reconstructable ownership.
```
- Replace existing [UID:0002WW] row with:
```text
        - [UID:0002WW][0x0067adc4-0x0067adc8.g_pChattingViewport](by-memory/0x0067adc4-0x0067adc8.g_pChattingViewport.md) 0x0067adc4-0x0067adc8 | global pointer | g_pChattingViewport : reconstructable : 87% : strong : Exact four-byte system-message/chat viewport singleton storage with current zero-filled virtual `.data` bytes, saved `g_pChattingViewport`, `SystemMessagePane_Constructor`, `SystemMessagePane_Destructor`, and `ClearChattingViewportSingleton` labels, 16 refs, SystemMessagePane lifecycle evidence, parent [UID:0002WV][g_pChattingViewport](by-global/g_pChattingViewport.md), and remaining system-message/chat source-split blocker.
```
- Replace existing [UID:0002XB] row with:
```text
        - [UID:0002XB][0x0067addc-0x0067ade0.g_pChattingVarietySelectPane](by-memory/0x0067addc-0x0067ade0.g_pChattingVarietySelectPane.md) 0x0067addc-0x0067ade0 | global pointer | g_pChattingVarietySelectPane : reconstructable : 86% : strong : Exact four-byte chat mode selector popup singleton storage with current zero-filled virtual `.data` bytes, saved `g_pChattingVarietySelectPane`, `ChattingVarietySelectPane_Destructor`, and `ChattingVarietySelectPane_ScalarDeletingDestructor` labels, 7 refs, selector lifecycle evidence, parent [UID:0002XA][g_pChattingVarietySelectPane](by-global/g_pChattingVarietySelectPane.md), and raw constructor/source-helper naming blocker.
```
- Replace existing [UID:0001PC] row with:
```text
    - [UID:0001PC][0x0069ae00-0x0069ae04.g_pSimpleHelpPane](by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md) 0x0069ae00-0x0069ae04 | global pointer | g_pSimpleHelpPane : reconstructable : 87% : strong : SimpleHelpPane singleton pointer with current zero-filled 0x4/4-byte storage, 23 direct refs, saved `SimpleHelpPane_Constructor`, `SimpleHelpPane_Destructor`, `SimpleHelpPane_ScalarDeletingDestructor`, and `CloseSimpleHelpPaneSingleton` labels, existing `ClearSimpleHelpPaneSingleton` label, constructor publish/guard-clear decompilation, ordinary/helper/scalar-destructor clears, close-helper read, tooltip feature consumers, g_pSimpleHelpPane/HelpPanes owner-emitter route, and remaining declaration/header/source-split blockers.
```

Supervisor integration update (2026-06-16): supervisor accepted `C001-goal2-global-ida-refresh-chatting-delete-simplehelp-browser-20260616-26` as complete. Scores cleared the gate at [UID:0002XA] `86/90`, [UID:0002WV] `87/90`, [UID:0002W3] `87/90`, [UID:0000S9] `87/90`, support [UID:0002W4] `87/90`, [UID:0002AI] `86/90`, [UID:0002B5] `86/92`, [UID:0002WW] `87/90`, [UID:0002XB] `86/90`, and [UID:0001PC] `87/90`; owner/emitter routes remain unchanged. Supervisor applied the exact [UID:0002AI], [UID:0002W4], [UID:0002B5], [UID:0002WW], [UID:0002XB], and [UID:0001PC] `by-memory/-coverage-report.md` replacement rows and validated the shared report plus changed support memory pages (`ok:1`). No C001 supervisor-owned memory rows remain pending for this batch.

## 2026-06-16 Assignment - C001-goal2-global-ida-refresh-browser-startup-history-20260616-27

Assigned targets:
- [UID:0000PP] `by-global/g_activeBrowserPane.md`
- [UID:0000QO] `by-global/g_pCurrentBrowserHost.md`
- [UID:0002ZQ] `by-global/g_startupWindowClassAtom.md`
- [UID:0000R3] `by-global/g_pHistoryViewingPane.md`

Instructions:
- Read and follow `Agent-C001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, safe IDA-edit rules, and the active source-quality investigation policy.
- This is a Goal 2 low-confidence/global safe IDA-refresh batch from refreshed `project-level/-auto-completion-stats.md`. Supervisor quick-peek shows bounded global/storage pages with known owner/emitter routes and direct lifecycle support across Browser, StartupWindow, and HistoryViewingPane.
- Refresh current IDA names, storage bytes, exact bounds, xrefs, decompilation or raw disassembly, neighboring boundaries, support memory/class/file/type pages, and generated-output implications.
- Apply only evidence-backed low-risk IDA improvements. Do not force speculative prototypes, types, members, locals, source-facing helper names, or ownership changes without enough proof.
- Investigate final source-quality blockers now: final declaration/type/linkage, lifetime clear paths, source-file placement, helper names, startup-window raw alternate setup reachability, HistoryViewingPane launcher reachability, and final-C++ eligibility. Do not merely repeat blockers; resolve supported items, document exact evidence checked for unresolved blockers, or keep/lower scores if unresolved issues materially limit confidence.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, saved IDA changes, and exact pending supervisor-owned report rows.

## 2026-06-16 - C001-goal2-global-ida-refresh-browser-startup-history-20260616-27 closeout

Changed files and scores:
- `by-global/g_activeBrowserPane.md`: `86/87 -> 87/89`; owner/emitter retained [UID:0000HV] `Browser`.
- `by-global/g_pCurrentBrowserHost.md`: `86/87 -> 87/90`; owner/emitter retained [UID:0000HV] `Browser`.
- `by-global/g_startupWindowClassAtom.md`: `86/87 -> 87/90`; owner/emitter retained [UID:0000O5] `StartupWindow`.
- `by-global/g_pHistoryViewingPane.md`: `87/86 -> 88/89`; owner/emitter retained [UID:0000JW] `HistoryViewingPane`.
- `by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md`: `85/86 -> 87/89`; owner/emitter retained [UID:0000HV] `Browser`.
- `by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md`: `86/89 -> 87/91`; owner/emitter retained [UID:0000HV] `Browser`.
- `by-memory/0x0069bac4-0x0069bac6.g_startupWindowClassAtom.md`: `86/88 -> 87/90`; owner/emitter retained [UID:0002ZQ] `g_startupWindowClassAtom`.
- `by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md`: `86/88 -> 87/89`; owner/emitter retained [UID:0000O5] `StartupWindow`.
- `by-memory/0x0069b494-0x0069b498.g_pHistoryViewingPane.md`: `86/90 -> 88/91`; owner/emitter retained [UID:0000R3] `g_pHistoryViewingPane`.
- `by-global/-coverage-report.md`: synced rows for [UID:0000PP], [UID:0000QO], [UID:0002ZQ], and [UID:0000R3].

Owner/emitter and blocker decisions:
- Browser globals remain Browser-owned source storage. `g_activeBrowserPane` still has no direct clear xref and exact pointer type/linkage is unresolved; `g_pCurrentBrowserHost` is proven as a temporary host-creation bridge but final host pointer type/declaration spelling remains unresolved.
- Startup atom remains StartupWindow file state. Raw alternate setup at `0x00581af4` is a real check/register/store path but still has no modeled function; no raw function creation was made.
- HistoryViewingPane singleton remains HistoryViewingPane-owned. Retained launch wrappers `0x004f90c0`/`0x004f9140` still have zero direct xrefs, but both decompile as real story/history viewer constructors; final source-history and singleton declaration spelling remain unresolved.
- Final C++ remained blank for all changed docs because exact declaration/type/source placement blockers are still real. No ownership changes were forced.

Evidence and IDA DB changes:
- Live IDA MCP session `b001_mappane_0001AW_20260616` (`NexusTK.exe.i64`, Hex-Rays ready) was used for current bytes, xrefs, lookup, decompilation/disassembly, dry-run rename validation, applied renames, save, and post-save verification.
- Saved 15 labels after dry-run accepted all candidates: `BrowserControlPane_HandleBrowserDispatchEvent`, `BrowserLegacyHostWndProc`, `BrowserThread_InitializeBrowserHost`, `StartupWindow_Constructor`, `StartupWindow_RunUpdateCheck`, `HistoryViewingPane_Constructor`, `ClearHistoryViewingPaneSingleton`, `HistoryViewingPane_ScalarDeletingDestructor`, `CloseMainMenuDialogSingletons`, `OpenStoryViewingPane`, `OpenHistoryViewingPane`, `g_activeBrowserPane`, `g_pCurrentBrowserHost`, `g_startupWindowClassAtom`, and `g_pHistoryViewingPane`.
- Save result: `idb_save ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`. Post-save `lookup_funcs` verified function labels; post-save decompile refs verified saved data labels.
- Skipped unsafe edits: prototypes, types, members, locals, raw function creation at startup raw setup, and final C++ declarations.

Validation commands/results:
- Ran `python .\tools\validator.py --mode file --file <changed-by-star-file> --apply --queue-timeout 240` from `source-3/project-documentation` for: `by-global/g_activeBrowserPane.md`, `by-global/g_pCurrentBrowserHost.md`, `by-global/g_startupWindowClassAtom.md`, `by-global/g_pHistoryViewingPane.md`, `by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md`, `by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md`, `by-memory/0x0069bac4-0x0069bac6.g_startupWindowClassAtom.md`, `by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md`, `by-memory/0x0069b494-0x0069b498.g_pHistoryViewingPane.md`, and `by-global/-coverage-report.md`.
- Result: sequential validator loop exited `0`; each changed by-* target/support/report reached `ok:1`. Validator `--apply` updated generated/projected stats, and [UID:0000PP] dropped from the generated low-score list during the first validation.

Leases:
- Acquired C001 leases for all changed target/support docs, `by-global/-coverage-report.md`, and this notes file before edits. The by-* leases expired naturally during the validator loop; current lease report showed no active C001 by-* leases before this closeout note. A fresh notes lease was acquired for this closeout and will be released after this update.

Supervisor-owned `by-memory/-coverage-report.md` rows:
- Do not edit `by-memory/-coverage-report.md` directly. Placement context: replace existing [UID:0001P9] and [UID:0002AD] rows around current lines 4348-4349, [UID:0001PU] around current line 4427, and [UID:0002AM]/[UID:0002ZR] around current lines 4481-4482, preserving indentation.
- Replace existing [UID:0001P9] row with:
```text
    - [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md) 0x0067ab84-0x0067ab88 | global-data | g_activeBrowserPane : reconstructable : 87% : strong : Browser active owner/callback pointer with saved `g_activeBrowserPane` and `BrowserControlPane_HandleBrowserDispatchEvent` labels, current zero-filled 0x4/4-byte storage, exactly 8 direct xrefs, BrowserControlPane constructor publication, accelerator/Escape and dispatch-event consumers, no direct clear xref found, Browser owner-emitter route, and final type/lifetime-clear blockers documented.
```
- Replace existing [UID:0002AD] row with:
```text
    - [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md) 0x0067ab88-0x0067ab90 | global-data pair | BrowserThreadHostGlobals : reconstructable : 87% : strong : Browser thread singleton and current browser-host bridge with zero-initialized pointer storage, 11 g_pBrowserThread xrefs, three saved-label `g_pCurrentBrowserHost` setup-bridge xrefs, saved `BrowserLegacyHostWndProc` and `BrowserThread_InitializeBrowserHost` labels, write-before-window-create/read-as-WndProc-fallback/clear-after-SetWindowLongA decompilation, Browser owner/emitter route, and final C++ blank pending declaration/linkage spelling.
```
- Replace existing [UID:0001PU] row with:
```text
    - [UID:0001PU][0x0069b494-0x0069b498.g_pHistoryViewingPane](by-memory/0x0069b494-0x0069b498.g_pHistoryViewingPane.md) 0x0069b494-0x0069b498 | global pointer | g_pHistoryViewingPane : reconstructable : 88% : strong : Exact four-byte HistoryViewingPane singleton slot with current zero-filled storage, saved `g_pHistoryViewingPane`, `HistoryViewingPane_Constructor`, `ClearHistoryViewingPaneSingleton`, `HistoryViewingPane_ScalarDeletingDestructor`, `CloseMainMenuDialogSingletons`, `OpenStoryViewingPane`, and `OpenHistoryViewingPane` labels, six live lifecycle refs, constructor publish/fallback clear, constructor-adjacent cleanup write, clear-helper/destructor clears, main-menu cleanup read, retained story/history wrapper decompilation with zero direct xrefs, and parent `g_pHistoryViewingPane`.
```
- Replace existing [UID:0002AM] row with:
```text
    - [UID:0002AM][0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals](by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md) 0x0069bac4-0x0069bacc | global-data cluster | StartupWindowUpdateStateGlobals : reconstructable : 87% : strong : StartupWindow atom/reserved/singleton cluster assigned to [UID:0000O5][StartupWindow](by-file/StartupWindow.md); split child rows cover the atom, reserved word, and pointer; 2026-06-16 C001 live IDA saved `g_startupWindowClassAtom`, `StartupWindow_Constructor`, and `StartupWindow_RunUpdateCheck`, reconfirmed zeroed bytes, four refs to `0x0069bac4`, zero refs to `0x0069bac6`, four refs to `0x0069bac8`, and raw alternate setup check/register/store behavior.
```
- Replace existing [UID:0002ZR] row with:
```text
        - [UID:0002ZR][0x0069bac4-0x0069bac6.g_startupWindowClassAtom](by-memory/0x0069bac4-0x0069bac6.g_startupWindowClassAtom.md) 0x0069bac4-0x0069bac6 | global word | g_startupWindowClassAtom : reconstructable : 87% : strong : Exact StartupWindow notice-class atom storage with saved `g_startupWindowClassAtom`, `StartupWindow_Constructor`, and `StartupWindow_RunUpdateCheck` labels, zeroed cluster bytes, four direct atom refs, RunUpdateCheck registration use, raw alternate setup `RegisterClassExA` check/store behavior at `0x00581af4-0x00581b08`, no modeled function at the raw setup address, and assignment to [UID:0002ZQ][g_startupWindowClassAtom](by-global/g_startupWindowClassAtom.md).
```

Supervisor integration update (2026-06-16): supervisor accepted `C001-goal2-global-ida-refresh-browser-startup-history-20260616-27` as complete. Scores cleared the gate at [UID:0000PP] `86/87 -> 87/89`, [UID:0000QO] `86/87 -> 87/90`, [UID:0002ZQ] `86/87 -> 87/90`, [UID:0000R3] `87/86 -> 88/89`, support [UID:0001P9] `85/86 -> 87/89`, [UID:0002AD] `86/89 -> 87/91`, [UID:0002ZR] `86/88 -> 87/90`, [UID:0002AM] `86/88 -> 87/89`, and [UID:0001PU] `86/90 -> 88/91`; owner/emitter routes remain unchanged. Supervisor applied the exact [UID:0001P9], [UID:0002AD], [UID:0001PU], [UID:0002AM], and [UID:0002ZR] `by-memory/-coverage-report.md` replacement rows and validated the shared report plus changed support memory pages (`ok:1`). No C001 supervisor-owned memory rows remain pending for this batch.

## 2026-06-16 Assignment - C001-goal2-global-ida-refresh-ranking-simplehelp-changepassword-chatback-20260616-28

Assigned targets:
- [UID:0000S3] `by-global/g_pRankingRewardInfoDialog.md`
- [UID:0000SA] `by-global/g_pSimpleHelpPane2.md`
- [UID:0000TA] `by-global/OpenChangePasswordDialog_4F9060.md`
- [UID:0002WZ] `by-global/g_pChattingBackPane.md`

Instructions:
- Read and follow `Agent-C001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, safe IDA-edit rules, and the active source-quality investigation policy.
- This is a Goal 2 low-confidence/global safe IDA-refresh batch from refreshed `project-level/-auto-completion-stats.md`. Supervisor quick-peek shows bounded global/helper pages with known owner/emitter routes and direct support: ranking reward dialog singleton, secondary SimpleHelpPane singleton, retained ChangePassword launcher helper, and ChattingBackPane singleton.
- Refresh current IDA names, storage bytes, exact bounds, xrefs, decompilation or raw disassembly, neighboring boundaries, support memory/class/file/type pages, and generated-output implications.
- Apply only evidence-backed low-risk IDA improvements. Do not force speculative prototypes, types, members, locals, raw function creation, source-facing helper names, or ownership changes without enough proof.
- Investigate final source-quality blockers now: final declaration/type/linkage, source-file placement, retained-helper reachability/grouping, singleton lifetime clear paths, raw/unmodeled clear sites, helper names, and final-C++ eligibility. Do not merely repeat blockers; resolve supported items, document exact evidence checked for unresolved blockers, or keep/lower scores if unresolved issues materially limit confidence.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, saved IDA changes, and exact pending supervisor-owned report rows.

## 2026-06-16 - C001-goal2-global-ida-refresh-ranking-simplehelp-changepassword-chatback-20260616-28 closeout

Changed files and scores:
- `by-global/g_pRankingRewardInfoDialog.md`: `84/90 -> 87/91`; owner/emitter retained [UID:0000MZ] `RankingDialog`.
- `by-global/g_pSimpleHelpPane2.md`: `84/90 -> 87/92`; owner/emitter retained [UID:0000JU] `HelpPanes`.
- `by-global/OpenChangePasswordDialog_4F9060.md`: `85/89 -> 86/90`; owner/emitter retained [UID:0000L0] `MainMenuPane`.
- `by-global/g_pChattingBackPane.md`: `85/89 -> 87/90`; owner/emitter retained [UID:0000I5] `Chatting`.
- `by-memory/0x0067a7e8-0x0067a7ec.g_pRankingRewardInfoDialog.md`: `86/90 -> 87/91`; owner/emitter retained [UID:0000S3] `g_pRankingRewardInfoDialog`.
- `by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md`: `86/91 -> 87/92`; owner/emitter retained [UID:0000SA] `g_pSimpleHelpPane2`.
- `by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md`: `85/88 -> 86/90`; owner/emitter retained [UID:0000L0] `MainMenuPane`.
- `by-memory/0x0067add0-0x0067add4.g_pChattingBackPane.md`: `85/89 -> 87/90`; owner/emitter retained [UID:0002WZ] `g_pChattingBackPane`.
- `by-global/-coverage-report.md`: synced rows for [UID:0002WZ], [UID:0000S3], [UID:0000SA], and [UID:0000TA].

Owner/emitter and blocker decisions:
- Ranking reward singleton remains RankingDialog-owned/emitted. Live xrefs prove guard/constructor/helper/destructor ownership; final C++ stays blank because the `0x0045dd8a` clear remains outside an IDA-modeled function and adjacent reward-packet/helper source placement is not final.
- SimpleHelpPane2 singleton remains HelpPanes-owned/emitted. Constructor/factory/destructor/support clear evidence is strong; final C++ stays blank because helper visibility, anchor-rectangle fields, timer helper signature, and declaration/header placement remain provisional.
- `OpenChangePasswordDialog` remains a retained MainMenuPane helper. Current live IDA still has zero xrefs to the wrapper entry and exactly two `ChangePasswordDialogPane` constructor call sites, so retained-helper grouping and final source placement remain unresolved.
- `g_pChattingBackPane` remains Chatting-owned/emitted. The old `0xffffffff` storage note was stale; live IDA confirms zero-filled virtual `.data`. Final C++ stays blank because declaration/header placement and private field/helper names are not settled.

Evidence and IDA DB changes:
- Live IDA MCP session `b001_mappane_0001AW_20260616` (`NexusTK.exe.i64`) was used for bytes, xrefs, function lookup, decompilation, dry-run rename validation, applied renames, save, and post-save lookup/decompile verification.
- Saved 13 labels after dry-run accepted all candidates: `RankingRewardInfoDialog_Constructor`, `ClearRankingRewardInfoDialogSingleton`, `RankingRewardInfoDialog_ScalarDeletingDestructor`, `SimpleHelpPane2_Constructor`, `SimpleHelpPane2Factory`, `SimpleHelpPane2_ScalarDeletingDestructor`, `OpenChangePasswordDialog`, `ChattingBackPane_Constructor`, `ChattingBackPane_Destructor`, `ChattingBackPane_ScalarDeletingDestructor`, `g_pRankingRewardInfoDialog`, `g_pSimpleHelpPane2`, and `g_pChattingBackPane`.
- Save result: `idb_save ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Skipped unsafe edits: prototypes, struct/member names, locals, raw function creation, source-facing helper signatures, and final reconstruction C++.

Validation commands/results:
- Ran `python .\tools\validator.py --mode file --file <changed-by-star-file> --apply --queue-timeout 240` from `source-3/project-documentation` for all changed by-* target/support/report files.
- Results: `ok:1` for `by-global/g_pRankingRewardInfoDialog.md`, `by-global/g_pSimpleHelpPane2.md`, `by-global/OpenChangePasswordDialog_4F9060.md`, `by-global/g_pChattingBackPane.md`, `by-memory/0x0067a7e8-0x0067a7ec.g_pRankingRewardInfoDialog.md`, `by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md`, `by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md`, `by-memory/0x0067add0-0x0067add4.g_pChattingBackPane.md`, and `by-global/-coverage-report.md`.

Leases:
- Acquired C001 leases for all changed target/support docs, `by-global/-coverage-report.md`, and this notes file before edits. The by-* leases expired naturally during validation/closeout; the explicit release command returned `Rejected[No active lease]` for the batch, so no active by-* lease remained. A short notes-only lease was reacquired to correct this release-status line and will be released immediately.

Supervisor-owned `by-memory/-coverage-report.md` rows:
- Do not edit `by-memory/-coverage-report.md` directly. Placement context: replace existing [UID:00019Q] row around current line 2127, [UID:0001OY] around current line 4309, [UID:00028V] around current line 4314, and [UID:0002X0] around current line 4364, preserving indentation.
- Replace existing [UID:00019Q] row with:
```text
    - [UID:00019Q][0x004f9060-0x004f90b4.OpenChangePasswordDialog](by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md) 0x004f9060-0x004f90b4 | retained duplicate launcher | OpenChangePasswordDialog : reconstructable : 86% : strong : Retained MainMenuPane password-dialog launcher with exact `0x54` / 84-byte body, saved `OpenChangePasswordDialog` label replacing the misleading runtime-like IDA name, allocator size `620`, constructor target `sub_4FDD40`, zero entrypoint xrefs, constructor xrefs from active duplicate menu path `0x004f7b49` and this helper `0x004f90a0`, successor boundary before `sub_4F90C0`, unique full-range signature evidence, and final C++ blank pending recovered caller/table or final source grouping.
```
- Replace existing [UID:0001OY] row with:
```text
    - [UID:0001OY][0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2](by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md) 0x0067a7d4-0x0067a7d8 | global pointer | g_pSimpleHelpPane2 : reconstructable : 87% : strong : SimpleHelpPane2 tooltip singleton with current IDA-confirmed zero storage, exact 9-reference set, saved `SimpleHelpPane2_Constructor`, `SimpleHelpPane2Factory`, and `SimpleHelpPane2_ScalarDeletingDestructor` labels, existing `ClearSimpleHelpPane2Singleton`, UI dismissal read, constructor/factory publish and guard clears, destructor/support/deleting-destructor clears, parent global/emitter route, and blank final C++ while helper visibility, private field names, and declaration placement remain provisional.
```
- Replace existing [UID:00028V] row with:
```text
    - [UID:00028V][0x0067a7e8-0x0067a7ec.g_pRankingRewardInfoDialog](by-memory/0x0067a7e8-0x0067a7ec.g_pRankingRewardInfoDialog.md) 0x0067a7e8-0x0067a7ec | global pointer | g_pRankingRewardInfoDialog : reconstructable : 87% : strong : RankingRewardInfoDialog singleton pointer with current zero storage, saved `g_pRankingRewardInfoDialog`, `RankingRewardInfoDialog_Constructor`, `ClearRankingRewardInfoDialogSingleton`, and `RankingRewardInfoDialog_ScalarDeletingDestructor` labels, exact six-xref lifecycle set, duplicate-modal guard, constructor publish/guard clear, constructor-adjacent unwind clear, helper/destructor clears, parent global attachment, and final C++ blank pending source declaration/placement and the unmodeled `0x0045dd8a` clear site.
```
- Replace existing [UID:0002X0] row with:
```text
        - [UID:0002X0][0x0067add0-0x0067add4.g_pChattingBackPane](by-memory/0x0067add0-0x0067add4.g_pChattingBackPane.md) 0x0067add0-0x0067add4 | global pointer | g_pChattingBackPane : reconstructable : 87% : strong : Exact four-byte chat background pane singleton storage with current zero-filled virtual `.data` bytes, saved `g_pChattingBackPane`, `ChattingBackPane_Constructor`, `ChattingBackPane_Destructor`, and `ChattingBackPane_ScalarDeletingDestructor` labels, exact 8 xrefs, constructor/destructor/scalar clear evidence, chat UI reader evidence, parent [UID:0002WZ][g_pChattingBackPane](by-global/g_pChattingBackPane.md), and final C++ blank pending declaration/header placement and private field/helper names.
```

Supervisor integration update (2026-06-16): supervisor accepted `C001-goal2-global-ida-refresh-ranking-simplehelp-changepassword-chatback-20260616-28` as complete. Scores cleared the gate at [UID:0000S3] `84/90 -> 87/91`, [UID:0000SA] `84/90 -> 87/92`, [UID:0000TA] `85/89 -> 86/90`, [UID:0002WZ] `85/89 -> 87/90`, support [UID:00028V] `86/90 -> 87/91`, [UID:0001OY] `86/91 -> 87/92`, [UID:00019Q] `85/88 -> 86/90`, and [UID:0002X0] `85/89 -> 87/90`; owner/emitter routes remain unchanged. Supervisor applied the exact [UID:00019Q], [UID:0001OY], [UID:00028V], and [UID:0002X0] `by-memory/-coverage-report.md` replacement rows and validated the shared report plus changed support memory pages (`ok:1`). No C001 supervisor-owned memory rows remain pending for this batch.

## 2026-06-16 Assignment - C001-goal2-item-ida-refresh-checkbox-popup-ail-tilec-20260616-29

Assigned targets:
- [UID:0000U7] `by-item/CheckBoxControlPaneStateTypeHelper_00499EC0.md`
- [UID:0000V8] `by-item/PopupMenuSelectionCallback_0049AF00.md`
- [UID:0000TU] `by-item/AILFileOpenCallback_0057B630.md`
- [UID:0000U6] `by-item/BuildTilecArchiveTable_004DDA60.md`

Instructions:
- Read and follow `Agent-C001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, safe IDA-edit rules, and the active source-quality investigation policy.
- This is a Goal 2 bounded by-item safe IDA-refresh batch from refreshed `project-level/-auto-completion-stats.md`. Supervisor quick-peek shows known owner/emitter routes and direct support evidence: CheckBoxControlPane vtable-only state helper, popup-menu member-function callback invoke thunk, SoundManager Miles AIL file-open callback, and StaticObjImageLib TILEC archive-table builder.
- Refresh current IDA names, exact bounds, xrefs, decompilation or raw disassembly, neighboring boundaries, support memory/class/file/type pages, generated-output implications, and current owner/emitter route evidence.
- Apply only evidence-backed low-risk IDA improvements. Do not force speculative prototypes, types, members, locals, raw function creation, source-facing helper names, or ownership changes without enough proof.
- Investigate final source-quality blockers now: exact callback/helper names, template/source-header spelling, callback typedefs, file/table field names, source placement, generated-output omissions, and final-C++ eligibility. Do not merely repeat blockers; resolve supported items, document exact evidence checked for unresolved blockers, or keep/lower scores if unresolved issues materially limit confidence.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, saved IDA changes, and exact pending supervisor-owned report rows.

## 2026-06-16 Assignment - C001-goal2-item-ida-refresh-loadpcx-blend-alpha-20260616-30

Assigned targets:
- [UID:0000UZ] `by-item/LoadPcxImage_004A17B0.md`
- [UID:0000TW] `by-item/AlphaBlendSpan16Blocks_00460B00.md`
- [UID:0000TZ] `by-item/BlendRgb555_004C0710.md`
- [UID:0000U3] `by-item/BuildClippedAlphaSurfaceView_00462320.md`

## 2026-06-16 - C001-goal2-item-ida-refresh-loadpcx-blend-alpha-20260616-30 closeout

Changed files and scores:
- `by-item/LoadPcxImage_004A17B0.md`: `86/88 -> 87/90`; owner/emitter retained [UID:0000K3] `ImageLoaders`.
- `by-item/AlphaBlendSpan16Blocks_00460B00.md`: `85/90 -> 86/91`; owner/emitter retained [UID:0000NT] `SoftwareBlend16`.
- `by-item/BlendRgb555_004C0710.md`: `85/90 -> 86/91`; owner/emitter retained [UID:0000NT] `SoftwareBlend16`.
- `by-item/BuildClippedAlphaSurfaceView_00462320.md`: `85/90 -> 86/91`; owner/emitter retained [UID:0000HF] `AlphaMaskSurface`.
- `by-memory/0x004a17b0-0x004a18a8.LoadPcxImage.md`: `86/88 -> 87/90`; owner/emitter retained [UID:0000K3] `ImageLoaders`.
- `by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md`: `84/90 -> 86/91`; owner/emitter retained [UID:0000NT] `SoftwareBlend16`.
- `by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md`: `82/90 -> 85/91`; owner/emitter retained [UID:0000HF] `AlphaMaskSurface`.
- `by-item/-coverage-report.md`: synced rows for [UID:0000TW], [UID:0000TZ], [UID:0000U3], and [UID:0000UZ].

Owner/emitter and blocker decisions:
- `LoadPcxImage` remains ImageLoaders-owned. StartupWindow owns the raw/modelled caller state, not this loader. Final C++ remains blank because DAT/file-buffer type names, string helper names, and raw startup notice helper source placement remain unresolved.
- `AlphaBlendSpan16Blocks` and `BlendRgb555` remain SoftwareBlend16-owned. The former is a confirmed RGB565 MMX weighted block helper; final source spelling still needs inline-assembly/intrinsics and exact signature evidence. The latter is a confirmed state-free RGB555 helper, but live xrefs remain limited to compatibility-render functions `0x004bb8d0`, `0x004bb9b0`, and `0x004bc090`, so runtime activation/source context is still not final.
- `BuildClippedAlphaSurfaceView` remains AlphaMaskSurface-owned despite a StaticObjImageLib caller. The support aggregate row was corrected to half-open `0x00462320-0x004623b5`; raw default-constructor/no-xref `InitAlphaSurfaceView`, `IntAlphaSurface` placement, encoded-frame source-type naming, and final helper signature remain unresolved after review.

Evidence and IDA DB changes:
- Live IDA MCP session `b001_mappane_0001AW_20260616` (`NexusTK.exe.i64`) was used for lookup, xrefs, decompilation/analyze evidence, raw `0x005818d0` disassembly evidence from the batch files, dry-run rename validation, applied renames, save, and post-save lookup verification.
- Dry-run accepted and saved four low-risk labels: `sub_4A17B0 -> LoadPcxImage`; `sub_460B00 -> AlphaBlendSpan16Blocks`; `sub_4C0710 -> BlendRgb555`; `sub_462320 -> BuildClippedAlphaSurfaceView`.
- Save result: `idb_save ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`. Post-save `lookup_funcs` verified all four labels and sizes: `0xf8`, `0x10a`, `0x5d`, and `0x95`.
- Skipped unsafe edits: prototypes, struct/member names, locals, raw function creation at `0x005818d0`, broader caller/source helper renames, DAT/file-buffer type edits, and final reconstruction C++.

Validation commands/results:
- Ran `python .\tools\validator.py --mode file --file <changed-by-star-file> --apply --queue-timeout 240` from `source-3/project-documentation` for: `by-item/LoadPcxImage_004A17B0.md`, `by-item/AlphaBlendSpan16Blocks_00460B00.md`, `by-item/BlendRgb555_004C0710.md`, `by-item/BuildClippedAlphaSurfaceView_00462320.md`, `by-memory/0x004a17b0-0x004a18a8.LoadPcxImage.md`, `by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md`, `by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md`, and `by-item/-coverage-report.md`.
- Result: sequential validator loop exited `0`; filtered rerun showed `ok:1` for each changed by-* file/report.

Leases:
- Acquired C001 leases for all changed target/support docs, `by-item/-coverage-report.md`, and this notes file before edits. The original by-* leases aged out during validation; a fresh notes lease was acquired for this closeout and will be released after this update.

Supervisor-owned `by-memory/-coverage-report.md` rows:
- Do not edit `by-memory/-coverage-report.md` directly. Placement context: replace existing [UID:0000YF] row around current line 457, [UID:0000YL] row around current line 497, and [UID:000314] row around current line 1288, preserving indentation.
- Replace existing [UID:0000YF] row with:
```text
    - [UID:0000YF][0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks](by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md) 0x00460b00-0x00460c0a | function | AlphaBlendSpan16Blocks : reconstructable : 86% : very strong : Weighted RGB565 four-pixel MMX block blender with saved `AlphaBlendSpan16Blocks` IDA label, exact `0x10a`/266-byte range, sole `AlphaBlendSpan16` caller at `0x004605fd`, source/inverse weight scratch qwords, RGB565 masks, four-pixel/eight-byte MMX loop, row-pitch advancement, `emms`, boundary padding, and final signature/inline-assembly spelling blockers documented.
```
- Replace existing [UID:0000YL] row with:
```text
    - [UID:0000YL][0x00462170-0x00462e03.AlphaMaskSurface](by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md) 0x00462170-0x00462e03 | class/helper family | AlphaMaskSurface : reconstructable : 85% : very strong : Alpha-mask surface methods plus adjacent view/blitter helpers with current live IDA function inventory, corrected clipped-view half-open row `0x00462320-0x004623b5`, saved `BuildClippedAlphaSurfaceView` label, one StaticObjImageLib caller, no-xref `InitAlphaSurfaceView` and raw default-constructor caveats, output buffer-view fields, encoded-alpha caller spread, vtable-write family, and final `IntAlphaSurface`/source-split blockers documented.
```
- Replace existing [UID:000314] row with:
```text
        - [UID:000314][0x004a17b0-0x004a18a8.LoadPcxImage](by-memory/0x004a17b0-0x004a18a8.LoadPcxImage.md) : reconstructable : 87% : very strong : Exact PCX path-loader child with saved `LoadPcxImage` IDA label, exact `0xf8`/248-byte range, path conversion, DAT/file-buffer lifecycle, `CreateDIBitmapFromPcxBuffer` handoff, twelve startup PCX xrefs split between modeled `0x00581100` and raw `0x005818d0` caller clusters, direct parent [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md), and final DAT/string-helper/source-placement blockers documented.
```

Supervisor integration update (2026-06-16): supervisor accepted `C001-goal2-item-ida-refresh-loadpcx-blend-alpha-20260616-30` as complete. Scores cleared the gate at [UID:0000UZ] `86/88 -> 87/90`, [UID:0000TW] `85/90 -> 86/91`, [UID:0000TZ] `85/90 -> 86/91`, [UID:0000U3] `85/90 -> 86/91`, support [UID:000314] `86/88 -> 87/90`, [UID:0000YF] `84/90 -> 86/91`, and [UID:0000YL] `82/90 -> 85/91`; owner/emitter routes remain unchanged. Supervisor applied the exact [UID:0000YF], [UID:0000YL], and [UID:000314] `by-memory/-coverage-report.md` replacement rows and validated the shared report plus changed support memory pages (`ok:1`). No C001 supervisor-owned memory rows remain pending for this batch.

## 2026-06-16 - C001-goal2-direct-ida-clan-menuitem-refresh-20260616 closeout

Changed files and scores:
- `by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md`: `80/90 -> 85/91`; owner/emitter retained [UID:00002F] `ClanItemDialog`; final C++ remains blank.
- `by-memory/0x00516f70-0x00516f74.MenuItemStateFlag0Accessor.md`: `80/90 -> 85/91`; owner/emitter retained [UID:00007V] `MenuItem`; final C++ remains blank.
- `by-memory/0x00516fb0-0x00516fc1.MenuItemCopyBoundsRect.md`: `80/90 -> 85/91`; owner/emitter retained [UID:00007V] `MenuItem`; final C++ remains blank.
- `by-memory/0x00516fd0-0x00516fe1.MenuItemSetBoundsRect.md`: `80/90 -> 85/91`; owner/emitter retained [UID:00007V] `MenuItem`; final C++ remains blank.
- Validator side effects from required `--apply`: `project-level/-auto-completion-stats.md` and `tools/validator.ini` were updated/rebuilt.

IDA DB changes:
- Live IDA MCP session `a002_goal65_20260616` on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64` was used for function lookup, decompilation/analyze evidence, disassembly, xrefs, raw pointer-byte searches, bytes, comments, and save.
- Appended four evidence comments: function comments at `0x0048a100` and `0x00516f70`, and line comments at raw starts `0x00516fb0` and `0x00516fd0`.
- Save result: `idb_save ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Skipped unsafe edits: function renames, prototypes, struct/member names, locals, raw function creation at `0x00516fb0`/`0x00516fd0`, source-facing flag/bounds names, and final reconstruction C++.

Evidence searched and blocker decisions:
- `ClanItemDialog` destructor tail: `lookup_funcs(0x0048a100)` still reports `sub_48A100` size `0x1f`; bounded disassembly is three `ClanItemDialog` vtable stores and a tail jump to `0x0049d9f0`; `xrefs_to` finds only EH/unwind refs at `0x005fc869` and `0x005fc90c`; `find_bytes("00 a1 48 00")` found no raw pointer hits. `func_profile(0x0049d9f0)` reports the current `boost::exception`-named cleanup target has 75 callers, so that base destructor name remains non-source-quality.
- `MenuItemStateFlag0Accessor`: `lookup_funcs(0x00516f70)` reports `sub_516F70` size `0x04`; bytes are `8a 41 14 c3`; decompile remains `return this[20]`; no direct xrefs or raw pointer hits. `MenuPane` previous/next-enabled raw scans compare `byte ptr [eax+14h], 0` at `0x00516c7e` and `0x00516cde`, supporting enabled/interactable semantics but not a final source-facing flag name.
- `MenuItemCopyBoundsRect` and `MenuItemSetBoundsRect`: `lookup_funcs` still reports `Not a function` at `0x00516fb0` and `0x00516fd0`; both have zero xrefs and zero raw pointer hits. `insn_query` reconfirmed exact 17-byte `movups` copy bodies, and `MenuPane` recompute writes the same `item+0x04` rectangle at `0x00516da9`. Source-authored versus inline/compiler-emitted helper status remains unresolved.

Validation commands/results:
- Ran `python .\tools\validator.py --mode file --file <target> --apply --queue-timeout 240` from `source-3/project-documentation` for all four touched by-memory target docs.
- Filtered rerun showed `ok:1` for each target: [UID:0002OC], [UID:0002J4], [UID:0002JJ], and [UID:0002JK].

Leases:
- Acquired C001 leases for the four target by-memory docs and this notes file before editing. The original leases aged out during the live IDA/edit pass, so fresh target leases were acquired before validation and a fresh notes lease was acquired before this closeout note. Release will be attempted immediately after this note update.

Supervisor-owned `by-memory/-coverage-report.md` rows:
- Do not edit `by-memory/-coverage-report.md` directly. Placement context: replace existing [UID:0002OC] row around current line 1020, [UID:0002J4] around current line 2433, [UID:0002JJ] around current line 2441, and [UID:0002JK] around current line 2443, preserving indentation.
- Replace existing [UID:0002OC] row with:
```text
        - [UID:0002OC][0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail](by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md) 0x0048a100-0x0048a11f | vtable-reset/destructor-tail function | ClanItemDialogVtableResetDestructorTail : reconstructable : 85% : very strong : Direct IDA reconfirms exact `0x1f` function range, three `ClanItemDialog` vtable stores, EH/unwind-only refs from deposit/withdraw constructors, no raw pointer hits to the helper start, matching raw-constructor/reset/scalar-destructor vtable write family, saved destructor-tail IDA comment, and unresolved shared `boost::exception`-named base cleanup target keeping final C++ blank.
```
- Replace existing [UID:0002J4] row with:
```text
        - [UID:0002J4][0x00516f70-0x00516f74.MenuItemStateFlag0Accessor](by-memory/0x00516f70-0x00516f74.MenuItemStateFlag0Accessor.md) 0x00516f70-0x00516f74 | method | MenuItemStateFlag0Accessor : reconstructable : 85% : very strong : Direct IDA reconfirms exact four-byte modeled accessor returning `MenuItem+0x14`, bytes `8a 41 14 c3`, `return this[20]` decompilation, no direct xrefs or raw pointer hits, paired setter/helper isolation, `MenuPane` enabled-scan consumers at `0x00516c7e` and `0x00516cde`, saved low-state-byte IDA comment, direct MenuItem parent, and unresolved final source-facing flag name keeping C++ blank.
```
- Replace existing [UID:0002JJ] row with:
```text
        - [UID:0002JJ][0x00516fb0-0x00516fc1.MenuItemCopyBoundsRect](by-memory/0x00516fb0-0x00516fc1.MenuItemCopyBoundsRect.md) 0x00516fb0-0x00516fc1 | raw method | MenuItemCopyBoundsRect : reconstructable : 85% : very strong : Direct IDA reconfirms exact 17-byte raw method-shaped bounds-copy body, no modeled or containing function object, no direct xrefs or raw pointer hits, `movups` copy from `MenuItem+0x04` to caller buffer, exact padding, `MenuPane`/`StringMenuItem` consumers of the same bounds field, saved raw-helper IDA line comment, direct MenuItem parent, and unresolved source-facing method name/source-authored-vs-inline status keeping C++ blank.
```
- Replace existing [UID:0002JK] row with:
```text
        - [UID:0002JK][0x00516fd0-0x00516fe1.MenuItemSetBoundsRect](by-memory/0x00516fd0-0x00516fe1.MenuItemSetBoundsRect.md) 0x00516fd0-0x00516fe1 | raw method | MenuItemSetBoundsRect : reconstructable : 85% : very strong : Direct IDA reconfirms exact 17-byte raw method-shaped bounds-set body, no modeled or containing function object, no direct xrefs or raw pointer hits, `movups` copy from caller rectangle into `MenuItem+0x04`, exact padding, `MenuPane`/`StringMenuItem` consumers of the same bounds field, saved raw-helper IDA line comment, direct MenuItem parent, and unresolved source-facing method name/source-authored-vs-inline status keeping C++ blank.
```

## 2026-06-16 - C001-goal2-direct-ida-scrollvolume-commit-0001H4-20260616-37 closeout

Changed files and scores:
- `by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md`: `82/86 -> 85/89`; owner/emitter retained [UID:0001H2] `0x00564710-0x005654ec.ScrollVolumePane`, emitter position corrected to `130`; final C++ remains blank.
- Direct support docs reviewed but not edited: `by-memory/0x00564710-0x005654ec.ScrollVolumePane.md`, `by-file/ScrollVolumePane.md`, `by-class/ScrollVolumePane.md`, `by-memory/0x005651e0-0x005652a0.ScrollVolumePaneBeginInteractionRaw.md`, `by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md`, `by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md`, and `by-type/by-struct/ScrollVolumePaneLayout.md`.

IDA DB changes:
- Used live IDA MCP session `a001_goal2_00023O` on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; `server_health` returned `status: ok`, Hex-Rays ready, strings ready, and `auto_analysis_ready:false`.
- Appended safe comments at `0x005652a0`, raw call site `0x00565272`, `0x00565360`, `0x004a9090`, and `0x005447c0`; `idb_save` returned `ok:true`.
- Skipped IDA rename/prototype/type/member/local edits. `ScrollVolumePaneCommitInteraction` is a useful documentation label, but original source method spelling and member names for `+0x103/+0x104` are still provisional.

Evidence/blocker investigation:
- Live `lookup_funcs`, `analyze_function`, `disasm`, `insn_query`, `xrefs_to`, `get_bytes`, `find_bytes`, and decompiles for `0x004a9090`/`0x005447c0` reconfirm the `0x005652a0-0x00565360` function boundary, cursor read, pane-origin local-coordinate conversion, `-1000/-1000` sentinel, `+0x104` active-part test, notify calls at `0x005652fb`/`0x00565324`, hit-test call at `0x0056530f`, stale-highlight invalidation/clear through `+0x103`, and vtable slot `+0x20`.
- Raw-caller caveat resolved precisely: `xrefs_to 0x005652a0` reports modeled callers `0x00564a83`/`0x00564b28` plus raw-span call `0x00565272`, while `lookup_funcs 0x005651e0` still reports `Not a function`; xrefs to raw starts `0x00565170`, `0x005651e0`, and `0x00565490` remain zero.
- Pointer-pattern scans found zero VA/RVA hits for commit, raw begin, notify, and rectangle helper starts; current reachability evidence is direct calls only, not hidden pointer tables.
- Owner/emitter decision: keep [UID:0001H4] owned/emitted through [UID:0001H2] and routed onward through [UID:0000CO]/[UID:0000NK] to `NexusTK/ui/controls/ScrollVolumePane.cpp`; reject stale `TextEditPane::HandleScrollbarMouseF` generated signature and OptionPane ownership. Final C++ stays blank despite the mechanical score/emitter gate because helper/member/source API names and raw sibling representation are not final-source safe.

Validation and leases:
- Ran `python .\tools\validator.py --mode file --file by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md --apply --queue-timeout 240` twice after edits; both runs exited `0` with `ok:1`. Final run updated/rebuilt validator registry state and left autogen reports unchanged.
- Lease handling: an earlier C001 target/notes lease expired during MCP verification; C001 reacquired leases for the target and this notes file before the final metadata edit and notes update.

Supervisor-owned `by-memory/-coverage-report.md` row:
- Do not edit `by-memory/-coverage-report.md` directly. Placement context: under [UID:0001H2] `0x00564710-0x005654ec.ScrollVolumePane`, replace the existing [UID:0001H4] row around current line 2611, preserving sibling order between [UID:0002LC] and [UID:0001H5].
- Replace existing [UID:0001H4] row with:
```text
        - [UID:0001H4][0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction](by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md) 0x005652a0-0x00565360 | method | ScrollVolumePaneCommitInteraction : reconstructable : 85% : very strong : C001 direct IDA refresh confirms exact `sub_5652A0` `0xc0` boundary, modeled mouse/focus callers `0x00564a83`/`0x00564b28`, raw begin-interaction call `0x00565272` with no modeled raw-start function, cursor read through `dword_67A754`/`0x004a9090`, pane-origin local-coordinate conversion through `0x005447c0`, `-1000/-1000` sentinel handling, active part `+0x104`, highlight clear `+0x103`, notify calls `0x005652fb`/`0x00565324`, hit-test/rectangle helpers, zero VA/RVA pointer hits, saved IDA comments, retained [UID:0001H2] owner/emitter position `130`, rejected stale `TextEditPane::HandleScrollbarMouseF` signature, generated-output omission, and final C++ blank pending source-quality helper/member names plus raw sibling representation.
```

## 2026-06-16 - C001-goal2-direct-ida-soundmanager-playback-scan-0001I9-0001IA-20260616 closeout

Changed files and scores:
- `by-memory/0x0057a260-0x0057a88e.SoundManagerPlaybackControls.md`: `82/86 -> 86/90`; owner/emitter retained [UID:0000NV] `SoundManager`; final C++ remains blank.
- `by-memory/0x0057a890-0x0057afcd.SoundManagerMusicDirectoryScan.md`: `82/86 -> 86/90`; owner/emitter retained [UID:0000NV] `SoundManager`; final C++ remains blank.
- `by-memory/0x0057b020-0x0057b48a.SoundManagerRedbookPlayback.md`: score unchanged `84/88`; support correction only for the Redbook timer-token evidence.
- Required validator/memory tool runs also updated generated/project-level reports through their normal `--apply`/report output; no generated report was hand-edited.

IDA DB changes:
- Used live IDA MCP session `701e9f0c` on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; `server_health` returned `status:ok`, `auto_analysis_ready:true`, Hex-Rays ready, and strings cache ready.
- Appended source-evidence comments at `0x0057a260`, raw chunks `0x0057a450`, `0x0057a480`, raw helper `0x0057a7b0`, modeled helpers `0x0057a780`/`0x0057a790`, timer vfunc `0x0057a800`, scanner `0x0057a890`, and successor raw bridge `0x0057afd0`.
- Save result: `idb_save ok:true`.
- Skipped unsafe edits: function renames, prototypes, struct/member names, locals, raw function creation, source-facing timer/field/helper names, and final reconstruction C++.

Evidence searched and blocker decisions:
- Playback boundaries: `lookup_funcs`/`entity_query` confirm modeled starts from `0x0057a260` through timer vfunc `0x0057a800`, next modeled function `0x0057a890`, and `cc cc` alignment at `0x0057a88e-0x0057a890`. `0x0057a450-0x0057a478` and `0x0057a480-0x0057a4d8` are tail-jump chunks from `BaramAppOnDeactivate`/`BaramAppOnActivate`, not standalone IDA SoundManager functions.
- Playback raw/helper coverage: `0x0057a7b0-0x0057a7d3` is a raw no-xref digital-master-volume helper ending `retn 4`; no raw function was created because current IDA has zero inbound xrefs and no source name evidence. `0x0057a780`/`0x0057a790` are app-focus SFX mute/restore helpers with direct activate/deactivate callers.
- Playback API and event evidence: current callees cover Miles stream/sample/DirectSound APIs, Redbook helper calls, and generic timer wrappers. Timer tokens were verified as `0x504e4354` (`1347306324`), `0x534d736d` (`1397584749`), and `0x534d7374` (`1397584756`) with `tools/int_convert.py`; these remain behavior labels, not final enum/source names.
- Field/table blockers investigated: verified offsets include `this+0x8/+0xc/+0x10/+0x14/+0x18/+0x41/+0x44/+0x48-0x87/+0x1028/+0x109c` families plus config offsets `g_pConfig+0x28de4c`, `+0x28de54`, and `+0x291913`. Evidence supports roles only; final member/global names remain unsafe.
- Scanner boundaries: live `lookup_funcs` confirms `sub_57A890` start `0x0057a890`, size `0x73e`, actual half-open end `0x0057afce`; the filename end `0x0057afcd` is preserved as the historical observed last byte. `0x0057afce-0x0057afd0` is alignment, followed by raw `0x0057afd0-0x0057b011` audio reinit/music-mode bridge before Redbook `0x0057b020`.
- Scanner behavior: decompilation/callees confirm `FindFirstFileA`/`FindNextFileA`, no current `FindClose` scanner xref, concrete string cells `0x0062cee0` `\*`, `0x0062cee4` `.mp3`, `0x0062ceec` `/`, recursion queue behavior, optional shuffle through `rand`, `SoundManager+0x1028` vector update, `SoundPathVector` insert/reallocate, and local cleanup helpers `0x0057b9e0`/`0x0057bac0`.
- Owner/emitter decision: retained [UID:0000NV] `SoundManager` for both targets because callers, constructor use, audio API dependencies, adjacent Redbook/SoundPathVector docs, and file/class support docs all route to SoundManager. No child/split page is needed for the scanner in this bounded pass; the raw successor bridge is documented as a boundary item rather than expanded.
- Final C++ decision: left blank because final source-quality field names, path-entry/local container type, timer event names, helper names, and raw chunk representation are not safe.
- Generated-output omissions: replaced stale current-session MCP timeout caveats in the target docs. `python .\tools\memory_ranges.py report` later reported no advanced-scan item for [UID:0001I9] or [UID:0001IA].

Validation and memory report:
- Ran `python .\tools\validator.py --mode file --file by-memory/0x0057a260-0x0057a88e.SoundManagerPlaybackControls.md --apply --queue-timeout 240`; validator exited `0`, reported `ok:1`, and applied [UID:0001I9] `completion_update 86` / `confidence_update 90`.
- Ran `python .\tools\validator.py --mode file --file by-memory/0x0057a890-0x0057afcd.SoundManagerMusicDirectoryScan.md --apply --queue-timeout 240`; validator exited `0` with `ok:1` for [UID:0001IA].
- Ran `python .\tools\validator.py --mode file --file by-memory/0x0057b020-0x0057b48a.SoundManagerRedbookPlayback.md --apply --queue-timeout 240`; validator exited `0` with `ok:1` for [UID:0001IB].
- Ran `python .\tools\memory_ranges.py report`; tool exited `0`, regenerated `auto-generated/by-memory-tool-report.md`, and showed no filename/advanced-scan errors for the SoundManager target pages.

Leases:
- Acquired C001 leases for `by-memory/0x0057a260-0x0057a88e.SoundManagerPlaybackControls.md`, `by-memory/0x0057a890-0x0057afcd.SoundManagerMusicDirectoryScan.md`, `by-memory/0x0057b020-0x0057b48a.SoundManagerRedbookPlayback.md`, and this notes file before the final notes closeout. Earlier target/notes leases had expired during the IDA/validation pass and were reacquired before this update.

Supervisor-owned `by-memory/-coverage-report.md` rows:
- Do not edit `by-memory/-coverage-report.md` directly. Placement context: under [UID:0001I8] `0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster`, replace existing [UID:0001I9], [UID:0001IA], and [UID:0001IB] rows around current lines 2716-2718, preserving sibling order between [UID:0001I7] and [UID:0001IC].
- Replace existing [UID:0001I9] row with:
```text
    - [UID:0001I9][0x0057a260-0x0057a88e.SoundManagerPlaybackControls](by-memory/0x0057a260-0x0057a88e.SoundManagerPlaybackControls.md) 0x0057a260-0x0057a88e | method-cluster | SoundManagerPlaybackControls : reconstructable : 86% : very strong : C001 live IDA refresh confirms current SoundManager playback-control function inventory through `0x0057a800`, missing modeled SFX app-focus helpers `0x0057a780`/`0x0057a790`, raw app deactivate/activate music chunks `0x0057a450-0x0057a478` and `0x0057a480-0x0057a4d8`, raw no-xref digital-master helper `0x0057a7b0-0x0057a7d3`, vtable-only timer dispatcher at `0x0062ce80`, broad sample-playback caller set, Miles stream/sample/DirectSound/Redbook API boundary, verified timer tokens `0x504e4354`/`0x534d736d`/`0x534d7374`, field/config offset roles, boundary bytes before scan, retained [UID:0000NV] owner/emitter, saved IDA comments, and final C++ blank pending source-quality member/helper/event names plus raw chunk representation.
```
- Replace existing [UID:0001IA] row with:
```text
    - [UID:0001IA][0x0057a890-0x0057afcd.SoundManagerMusicDirectoryScan](by-memory/0x0057a890-0x0057afcd.SoundManagerMusicDirectoryScan.md) 0x0057a890-0x0057afce | method | SoundManagerMusicDirectoryScan : reconstructable : 86% : very strong : C001 live IDA refresh confirms `sub_57A890` start `0x0057a890`, size `0x73e`, actual half-open end `0x0057afce` while preserving the historical last-byte filename `0x0057afcd`, constructor/music-control callers, `FindFirstFileA`/`FindNextFileA` use with no current `FindClose` callee/xref, concrete string cells `0x0062cee0` `\*`, `0x0062cee4` `.mp3`, `0x0062ceec` `/`, `SoundManager+0x1028` vector clear/insert/swap behavior, recursion queue, optional shuffle via `rand`, SoundPathVector insert/reallocate/destructor and deque cleanup callees, successor raw `0x0057afd0-0x0057b011` audio reinit/music-mode bridge before Redbook helpers, retained [UID:0000NV] owner/emitter, clean memory-range filename/advanced scan, saved IDA comments, and final C++ blank pending final global/helper names, path-entry type, and local deque/vector source shape.
```
- Replace existing [UID:0001IB] row with:
```text
    - [UID:0001IB][0x0057b020-0x0057b48a.SoundManagerRedbookPlayback](by-memory/0x0057b020-0x0057b48a.SoundManagerRedbookPlayback.md) 0x0057b020-0x0057b48a | method-cluster | SoundManagerRedbookPlayback : reconstructable : 84% : strong : Existing IDA-backed docs confirm seven modeled SoundManager Redbook/CD helpers, two raw unmodeled helper bodies, Miles Redbook API use, track-order table construction, shuffle/repeat/music-mode config offsets, music-control callers, adjacent padding evidence, parent SoundManager attachment, and blank final C++; C001 support correction verified modeled Redbook scheduling/cancel token decimal `1347306324` as `0x504e4354` with `tools/int_convert.py`, replacing stale `0x504d5244` text while leaving score unchanged.
```

## 2026-06-16 - C001-goal2-direct-ida-userstatus-video-refresh-0001NO-0001NT-20260616 closeout

Changed files and scores:
- `by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md`: `82/86 -> 86/90`; owner/emitter retained [UID:0000FT] `UserStatusPane2`; final C++ remains blank.
- `by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md`: `82/86 -> 86/90`; direct owner/emitter corrected from [UID:0000P4] `VideoPlayerPane` file to [UID:0000FV] `VideoPlayerPane` class, which emits through [UID:0000P4]; final C++ remains blank.
- Required validator/report runs also updated normal generated/project state (`project-level/-auto-completion-stats.md`, `tools/validator.ini`, and `auto-generated/by-memory-tool-report.md`) through tool output. No generated report was hand-edited.

IDA DB changes:
- Used live IDA MCP session `701e9f0c` on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; `server_health` returned `status:ok`, `auto_analysis_ready:true`, Hex-Rays ready, and strings cache ready.
- Appended safe evidence comments at UserStatusPane2 starts/raw bodies `0x005bab00`, `0x005bac80`, `0x005baf80`, `0x005bbe20`, `0x005bbe60`, `0x005bc0f0`, `0x005bc180`, `0x005bc2d0`, and `0x005bc420`.
- Appended safe evidence comments at VideoPlayerPane starts/raw bodies `0x005c0040`, `0x005c0090`, `0x005c0110`, `0x005c0180`, `0x005c01a0`, `0x005c01d0`, `0x005c02a0`, `0x005c0350`, `0x005c037b`, and `0x005c03a0`.
- Save result: `idb_save ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Skipped unsafe edits: function renames, prototypes, struct/member names, locals, raw function creation, speculative source-facing helper/member/packet names, support-page churn, and final reconstruction C++.

Evidence searched and blocker decisions:
- UserStatusPane2: live `entity_query`/`lookup_funcs` confirmed modeled starts `0x005bab00`, `0x005bac00`, `0x005bac80`, `0x005baf70`, `0x005baf80`, `0x005bbe60`, `0x005bc010`, and `0x005bc420`, with successor `MenuVarietyPane` boundary at `0x005bc610`. Constructor xref is `InitializeMainUiGraph+0x004f83ea`; vtable/data refs cover router/false/paint; glyph helper has ten paint callsites; payload applicator is reached from router `0x005baef2`.
- UserStatusPane2 raw/gap audit: byte/disassembly checks confirmed router switch/jump data at `0x005baf0a-0x005baf64`, raw no-route helper-shaped body `0x005bbe20-0x005bbe5b`, rectangle switch data before `0x005bc010`, raw helper-shaped bodies `0x005bc0f0-0x005bc175`, `0x005bc180-0x005bc2b9`, and `0x005bc2d0-0x005bc409`, plus local alignment. `xrefs_to` and VA/RVA `find_bytes` checks found no raw-start reachability, so no child pages, ignored rows, or forced IDA functions were added in this bounded pass.
- UserStatusPane2 behavior/type blockers: decompilation confirmed singleton/resource/vtable ties, packet opcodes `4`/`8`/`0x0b`/`0x26`, `g_pConfig+0x28de75`, map-bound checks `dword_67A764+0x3f4/+0x3f6`, `0x005bc420` flags `0x40`/`0x20`/`0x10`, field roles at `this+0xf8/+0xfc/+0x100/+0x104/+0x108/+0x10c/+0x110/+0x114/+0x118/+0x11c`, and `COMMA`/`BAR`/`9X11FONT.BIN` resource use. Source-facing status field names, packet struct names, and raw-helper source treatment remain unresolved after this evidence.
- VideoPlayerPane: live `entity_query`/`lookup_funcs` confirmed modeled starts `0x005c0040`, `0x005c0090`, `0x005c0110`, `0x005c01f0`, `0x005c0210`, `0x005c0260`, `0x005c02a0`, `0x005c0350`, `0x005c037b`, `0x005c0386`, and `0x005c03a0`, with successor `0x005c0460`. Xrefs confirm LogoPlayerPane constructor caller `0x004f53e3`, Logo cleanup/EH refs to `0x005c0090`, Logo-only direct callers `0x004f5476` and `0x004f55af` for `0x005c0110`, vtable/data refs for start/stop/message/idle/done, and adjustor-thunk refs.
- VideoPlayerPane raw/helper audit: `0x005c0180-0x005c019f`, `0x005c01a0-0x005c01c5`, and `0x005c01d0-0x005c01e8` remain IDA-unpromoted raw helper-shaped bodies; `xrefs_to` and VA/RVA pointer-pattern scans found no raw-start reachability. They stay under the base `VideoPlayerPane` aggregate because each works directly on `this+0xfc` Bink state and no evidence supports LogoPlayerPane ownership.
- VideoPlayerPane behavior/type blockers: decompilation confirmed base ctor/vtable setup, `term` unregister/Bink-close destructor behavior, DirectSound bridge and `BinkOpen(segmentData, 0x04080000)` open helper, active/playback fields `this+0xf5/+0xf8/+0xfc`, Bink field `+0x230`, `BinkWait`/`BinkDoFrame`/`BinkCopyToBuffer`/`BinkNextFrame`/`BinkService` idle path, `VisD` completion post/callback, and scalar destructor free logic. Final Bink field/type names, helper exposure/spelling, callback type, and raw-helper source treatment remain unresolved.
- Generated-output status: `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` and `auto-generated/NexusTK/ui/core/VideoPlayerPane.cpp` remain empty; `simroot_v2/class_UserStatusPane2.cpp` omits router/rect/payload/raw bodies; `simroot_v2/class_VideoPlayerPane.cpp` omits non-deleting destructor/open/raw helpers, while `simroot_v2/class_LogoPlayerPane.cpp` mis-emits Video teardown/open context because current direct callers are Logo-only.
- `tools/int_convert.py` verified `2678389 -> 0x28de75`, compact status offsets `248 -> 0xf8` through `284 -> 0x11c`, `1952805485 -> 0x7465726d`, `1449743172 -> 0x56695344`, `67633152 -> 0x04080000`, and `560 -> 0x230`.

Validation and memory report:
- Ran `python .\tools\validator.py --mode file --file by-memory\0x005bab00-0x005bc60c.UserStatusPane2.md --apply --queue-timeout 240`; validator exited `0` with `ok:1`.
- Ran `python .\tools\validator.py --mode file --file by-memory\0x005c0040-0x005c045b.VideoPlayerPane.md --apply --queue-timeout 240`; validator exited `0` with `ok:1`.
- Ran `python .\tools\memory_ranges.py report`; tool exited `0`, regenerated `auto-generated/by-memory-tool-report.md`, and the `Advanced-Error-Scan` section reported `None`, with no target filename/text issue for [UID:0001NO] or [UID:0001NT].

Leases:
- Acquired C001 leases for both target by-memory docs and this notes file before editing. Long validation/report runs consumed time, so C001 reacquired the same leases before this closeout note.

Supervisor-owned `by-memory/-coverage-report.md` rows:
- Do not edit `by-memory/-coverage-report.md` directly. Placement context: replace existing [UID:0001NO] row around current line 3072 and existing [UID:0001NT] row around current line 3079, preserving sibling order between the surrounding ignored padding rows.
- Replace existing [UID:0001NO] row with:
```text
    - [UID:0001NO][0x005bab00-0x005bc60c.UserStatusPane2](by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md) 0x005bab00-0x005bc60c | class method aggregate | UserStatusPane2 : reconstructable : 86% : very strong : C001 live IDA refresh confirms current compact UserStatusPane2 function inventory, constructor xref `0x004f83ea`, singleton/resource/vtable ties, successor `MenuVarietyPane` boundary at `0x005bc610`, router switch/jump data at `0x005baf0a-0x005baf64`, raw no-xref/no-pointer helper-shaped bodies `0x005bbe20-0x005bbe5b`, `0x005bc0f0-0x005bc175`, `0x005bc180-0x005bc2b9`, and `0x005bc2d0-0x005bc409`, packet opcodes/flags and field-offset roles through `this+0x11c`, generated-output omissions, retained [UID:0000FT] owner/emitter, saved IDA comments, and final C++ blank pending source-quality compact field/helper/packet names plus raw-helper source treatment.
```
- Replace existing [UID:0001NT] row with:
```text
    - [UID:0001NT][0x005c0040-0x005c045b.VideoPlayerPane](by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md) 0x005c0040-0x005c045b | class method aggregate | VideoPlayerPane : reconstructable : 86% : very strong : C001 live IDA refresh confirms current Bink VideoPlayerPane function inventory, non-deleting destructor `0x005c0090`, memory-backed open helper `0x005c0110` with LogoPlayerPane-only direct callers but base `VideoPlayerPane` field/API behavior, raw no-xref/no-pointer helper-shaped bodies `0x005c0180-0x005c019f`, `0x005c01a0-0x005c01c5`, and `0x005c01d0-0x005c01e8`, vtable-only start/stop/message/idle/done dispatch, compiler adjustor thunks `0x005c037b`/`0x005c0386`, successor `0x005c0460`, Bink API and event token roles `term`/`VisD`, generated-output and Logo mis-emission evidence, corrected direct owner/emitter to [UID:0000FV] with file route through [UID:0000P4], saved IDA comments, and final C++ blank pending final Bink field/type names, helper exposure, callback type, and raw-helper source treatment.
```
- Supervisor applied these two pending `by-memory/-coverage-report.md` rows on 2026-06-16, validated the shared report plus [UID:0001NO] and [UID:0001NT] with scoped `validator.py --mode file --apply --queue-timeout 240` passes (`ok:1`), regenerated `auto-generated/by-memory-tool-report.md` at `2026-06-16 16:06:26`, and regenerated stats at `2026-06-16 16:06:22`. No pending supervisor-owned memory coverage rows remain for this UserStatusPane2/VideoPlayerPane batch.

## 2026-06-16 - C001-goal2-direct-ida-fittingroom-list-scroll-refresh-0002DB-0002DC-0002DI-20260616 closeout

Changed files and scores:
- `by-memory/0x0041eb30-0x0041eb8c.FittingRoomScrollPaneResetScrollStateRaw.md`: `82/88 -> 86/89`; owner/emitter retained [UID:000054] `FittingRoomScrollPane`; final C++ remains blank.
- `by-memory/0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md`: `82/88 -> 86/90`; owner/emitter retained [UID:000053] `FittingRoomListPane`; final C++ remains blank.
- `by-memory/0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition.md`: `82/88 -> 86/90`; owner/emitter retained [UID:000053] `FittingRoomListPane`; final C++ remains blank.
- Tool output updated normal generated/project state through `validator.py --apply` and `memory_ranges.py report`; no generated report or shared coverage report was hand-edited.

IDA DB changes:
- Used live IDA MCP session `701e9f0c`; `server_health` returned `status:ok`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- Appended safe evidence comments at `0x0041eb30`, `0x0041eb90`, `0x0041ecc0`, and `0x0041f100`.
- Save result: `idb_save ok:true`, path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Skipped unsafe IDA edits: function renames, prototypes, structures, members, locals, raw function creation, source-facing method/field names, and final reconstruction C++.

Evidence searched and blocker decisions:
- [UID:0002DB] raw reset: `lookup_funcs`, `entity_query`, `get_bytes`, `disasm`, `xref_query`, and VA/RVA `find_bytes` reconfirmed `0x0041eb30-0x0041eb8c` as a raw no-function body with surrounding padding, no incoming xrefs, no pointer hits, timer removal through `sub_597600`/`0x00597600`, hot `+0x103` and active `+0x104` byte clears, `GetPartRect` invalidation, and virtual slot `+0x20` redraw. Kept raw start unpromoted because direct reachability remains unproven.
- [UID:0002DC] constructor: live IDA reconfirmed `sub_41EB90` size `0x12d`, sole direct dialog-constructor caller `0x0041c01a`, callees `0x004949e0`/`0x004f4aa0`/`0x00544460`, `0x110` scroll-child allocation, inline child vtable/state setup, and no hidden modeled helper before `OnResize`. `0x0041d6c0` still decompiles as no-function raw constructor-shaped scroll-pane code with no inbound xrefs/pointers, so no child constructor call/name was forced.
- [UID:0002DC] raw cleanup relationship: `get_bytes`/`disasm` confirm `0x0041ecc0-0x0041ecf5` restores list vtables, deletes child at `+0x11c`, and tail-jumps to `0x00544580`; `xref_query` and pointer scans found no inbound reachability, so it remains compiler cleanup evidence, not a standalone source method.
- [UID:0002DI] reset position: live IDA reconfirmed `sub_41F100` size `0x119`, sole dialog-command caller `0x0041c418`, callees `UpdateScrollBar` and vector throw helper, no VA/RVA pointer hit, category/vector loop with `0xb4` entry stride, `g_pFittingRoomDialog+0x49e/+0x744/+0x748/+0x784`, list `+0x108`, child pointer `+0x11c`, child current `+0xfe`, and virtual slot `+0x20` invalidations.
- `tools/int_convert.py` verified `272 -> 0x110`, `180 -> 0xb4`, `1182 -> 0x49e`, `1860 -> 0x744`, `1864 -> 0x748`, `1924 -> 0x784`, and `30000 -> 0x7530` while reviewing sibling scroll bounds.
- Generated-output omission: `auto-generated/-ag-memory-coverage.md` routes all three target UIDs to `auto-generated/NexusTK/cashshop/FittingRoom.cpp`, but that file is currently zero bytes because final reconstruction C++ remains blank. This is not an owner/emitter routing failure.
- Owner/emitter decisions: retained [UID:000054] for [UID:0002DB] and [UID:000053] for [UID:0002DC]/[UID:0002DI]. Support pages [UID:000054] `FittingRoomScrollPane`, [UID:000053] `FittingRoomListPane`, and [UID:0000JE] `FittingRoom` already clear `85/85`, and direct evidence supports the current routes.
- Final C++ decision: kept blank for all three. The score/emitter gate is met, but raw reachability, exact source method names, final list/scroll/dialog field names, virtual invalidate source identity, and compiler cleanup/raw helper treatment remain below source-quality.

Validation and memory report:
- Ran `python .\tools\validator.py --mode file --file .\by-memory\0x0041eb30-0x0041eb8c.FittingRoomScrollPaneResetScrollStateRaw.md --apply --queue-timeout 240`; validator exited `0` with `ok:1`, `completion_update 86`, `confidence_update 89`.
- Ran `python .\tools\validator.py --mode file --file .\by-memory\0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md --apply --queue-timeout 240`; validator exited `0` with `ok:1`, `completion_update 86`, `confidence_update 90`.
- Ran `python .\tools\validator.py --mode file --file .\by-memory\0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition.md --apply --queue-timeout 240`; validator exited `0` with `ok:1`, `completion_update 86`, `confidence_update 90`.
- Ran `python .\tools\memory_ranges.py report`; tool exited `0`, regenerated `auto-generated/by-memory-tool-report.md`, and Barrier, General, Filename, and Advanced error sections all report `None`.

Leases:
- C001 acquired leases for the three target pages and this notes file before editing. Earlier leases expired during the IDA/research pass; C001 reacquired the same target/notes leases before markdown edits.
- A final renewal attempt returned `Rejected[Already has lease]` for all four paths, confirming C001 still held the active leases while this note was written.

Supervisor-owned `by-memory/-coverage-report.md` rows:
- Do not edit `by-memory/-coverage-report.md` directly. Placement context: under [UID:0000WR] `0x0041ba40-0x004245f5.FittingRoomUiCore`, replace existing [UID:0002DB], [UID:0002DC], and [UID:0002DI] rows around current lines 178, 180, and 191, preserving sibling order between the surrounding ignored padding rows.
- Replace existing [UID:0002DB] row with:
```text
        - [UID:0002DB][0x0041eb30-0x0041eb8c.FittingRoomScrollPaneResetScrollStateRaw](by-memory/0x0041eb30-0x0041eb8c.FittingRoomScrollPaneResetScrollStateRaw.md) 0x0041eb30-0x0041eb8c | raw helper | FittingRoomScrollPaneResetScrollStateRaw : reconstructable : 86% : very strong : C001 live IDA refresh confirms raw reset-helper bounds, no modeled function, no incoming xrefs or VA/RVA pointer hits, the `0x00597600` timer-removal wrapper, hot/active part byte clears, old-hot rect invalidation through `GetPartRect` plus virtual slot `+0x20`, generated `FittingRoom.cpp` omission due blank final C++, retained [UID:000054] owner/emitter, saved IDA comment, and final C++ blank pending raw reachability plus source-quality method/field/virtual names.
```
- Replace existing [UID:0002DC] row with:
```text
        - [UID:0002DC][0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor](by-memory/0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md) 0x0041eb90-0x0041ecbd | constructor | FittingRoomListPaneConstructor : reconstructable : 86% : very strong : C001 live IDA refresh confirms exact `sub_41EB90` bounds, sole dialog-constructor caller `0x0041c01a`, base/control allocation/API split, `0x110` scroll-child allocation, inline scroll-pane vtable/state initialization, raw `0x0041d6c0` constructor-shaped support with no reachability, adjacent raw cleanup relationship at `0x0041ecc0`, generated `FittingRoom.cpp` omission due blank final C++, retained [UID:000053] owner/emitter, saved IDA comments, and final C++ blank pending source-quality layout plus constructor/destructor split names.
```
- Replace existing [UID:0002DI] row with:
```text
        - [UID:0002DI][0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition](by-memory/0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition.md) 0x0041f100-0x0041f219 | method | FittingRoomListPaneResetScrollPosition : reconstructable : 86% : very strong : C001 live IDA refresh confirms exact `sub_41F100` bounds, sole dialog-command caller `0x0041c418`, no VA/RVA pointer hit, category/vector loop with `0xb4` entry stride, `g_pFittingRoomDialog+0x49e/+0x744/+0x748/+0x784` behavior, list/child scroll clears at `+0x108/+0xfe`, `UpdateScrollBar` and vector-throw callees, virtual slot `+0x20` invalidations, generated `FittingRoom.cpp` omission due blank final C++, retained [UID:000053] owner/emitter, saved IDA comment, and final C++ blank pending source-quality field names plus virtual slot identity.
```
