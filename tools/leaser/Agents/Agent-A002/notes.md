# Agent A002 Notes

## Standing A-Agent Source-Quality Policy (2026-06-15)

- Investigate source-quality blockers during normal documentation work regardless of current score. Do not stop at 85/85 if field/type/global/protocol/helper-name, caller/reachability, ownership, source-placement, split/merge/range, or final-C++ blockers remain.
- For each blocker you mention, either resolve it with supported documentation, metadata, IDA, or Wave2/Wave3 changes; record the exact evidence checked and why it cannot be safely resolved yet; or keep/lower the score if the unresolved issue limits behavior, ownership, source placement, or confidence.
- Do not defer an issue to "final C++" just because C++ has not yet been written. These issues must be investigated before C++ emission and throughout the score/evidence pass.

## Metadata Terminology Note (2026-06-13)

- Older entries in this log may use pre-migration `AUTOGEN_PARENT_UID`, `AUTOGEN_PARENT_POSITION`, `parent`, `parent blank`, `parentless`, or `unassigned` wording.
- Current validator metadata uses `CANONICAL_OWNER` for semantic/documentation ownership and `EMITTER_UIDS` plus `EMITTER_POSITION_OPTIONAL` for generated-output routing.
- Interpret old `AUTOGEN_PARENT_UID` entries as legacy combined owner/emitter context; do not copy them into new edits without mapping them to the current fields.
- Current generated report terms are `no-owner`, `emits`, `non-emits`, `multiple-emitters`, and `dead-ends`.

Lease report symlink:
`E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-A002\current_leases.md`

Do not edit `current_leases.md`; read it for live lease status before editing.

## 2026-06-16 Checkpoint - A002-goal2-screenpane-browser-notification-0002VO-20260616-69

- Changed files:
  - `by-memory/0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler.md`
  - Validator-owned/generated state refreshed by scoped validator: `project-level/-auto-completion-stats.md` and `tools/validator.ini`; autogen reports/C++ were no-op.
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score/routing:
  - [UID:0002VO] `ScreenPaneBrowserNotificationHandler`: `82/86 -> 85/88`.
  - `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000CB] `ScreenPane`; route remains [UID:0000NB] `ScreenPane` / `auto-generated/NexusTK/ui/core/ScreenPane.cpp` because the handler is reached through ScreenPane vtable data and mutates ScreenPane state. Browser owns the producer/type evidence only.
  - Final C++ remains blank despite numeric route/score eligibility because exact source method name, ScreenPane `+0x511` member name, notification state enum/field names, AlertPane formal parameter names, and the source representation of the unsupported-state fallback remain unsafe.
- Evidence checked:
  - Live IDA MCP unavailable in this pass: `tools/list` first timed out and then the endpoint refused connection. No live IDA reads or writes were used for the current refresh.
  - Prior IDA-backed docs plus static `C:\Users\admin\Desktop\Clone\NexusTK\ida_export.md.old` corroborate `sub_556F70` size `0x100`, sole vtable xref `0x00623150`, and neighboring ScreenPane functions at `0x00556d50` and `0x00557070`.
  - Raw PE bytes from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` confirm `0xcc` padding before `0x00556f70`, next-function boundary at `0x00557070`, vtable slot bytes at `0x00623150`, no direct rel32 code callers, `Bros` immediates at two producer/consumer sites, `browser::Notification` vtable pointer use sites, `+0x511` writes, and the fallback `8a 45 0b` return load.
  - Checked `by-class/ScreenPane.md`, `by-file/ScreenPane.md`, `by-class/browser__Notification.md`, `PostBrowserNotification`, Browser notification destructor, ScreenPane aggregate/vtable/read-only data, AlertPane core, Browser singleton globals, `g_pBackPane`, `DialogOkButtonString`, `auto-generated/NexusTK/ui/core/ScreenPane.cpp`, `auto-generated/NexusTK/browser/Browser.cpp`, `simroot_v2/class_ScreenPane.cpp`, `simroot_v2/recovered/PostBrowserNotification_00470F20.cpp`, `simroot_v2/class_browser__Notification.cpp`, and `simroot_v2/class_AlertPane.cpp`.
  - Current generated output confirms a routing omission: validator routes the page to `auto-generated/NexusTK/ui/core/ScreenPane.cpp`, but that root is empty; `simroot_v2/class_ScreenPane.cpp` also omits `0x00556f70` between adjacent ScreenPane methods.
- Source-quality blocker decisions:
  - Method/source name remains unresolved; only `sub_556F70` and the descriptive documentation label are evidenced.
  - Payload type/layout is resolved to the 12-byte `browser::Notification` shape, but producer field names and state enum names remain generated hints rather than source-quality names.
  - ScreenPane `+0x511` behavior is resolved as the browser-notification state byte; the member name remains unresolved after local docs, simroot, and raw-byte checks.
  - `Bros` ownership/source split is resolved: Browser owns the notification producer and payload type, while ScreenPane owns this virtual consumer.
  - Non-0/non-1 return behavior is binary-resolved as the high byte of the stack argument pointer; source intent remains unresolved because checked producers emit only states `0` and `1`.
  - AlertPane constructor roles are resolved as payload text, `g_pBackPane` layout/reference context, shared `OK` primary label, and null secondary label; formal parameter names remain unresolved.
  - Class/file routing and vtable reachability are resolved; final C++ remains unsafe because naming/source-intent blockers remain.
- Validation:
  - `python .\tools\validator.py --mode file --file by-memory\0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`; validator reported registry rebuild, projected stats update, and `autogen_cpp_noop 0000NB auto-generated/NexusTK/ui/core/ScreenPane.cpp no assembled code for root`.
- Leases:
  - A002 leased the target and notes for the target edit/validation pass; those leases later expired. A002 re-leased this notes file before writing this checkpoint.
- IDA DB changes: none. No comments, renames, prototypes, type edits, function creation, patches, saves, or other IDA writes were made.
- Pending supervisor-owned `by-memory/-coverage-report.md` row replacement:
  - Placement: under [UID:0001G5] `0x00556910-0x00557132.ScreenPane`, replace the existing [UID:0002VO] child row after padding `0x00556f61-0x00556f70` and before the child row beginning `0x00557070-0x00557132` with:
    `        - [UID:0002VO][0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler](by-memory/0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler.md) 0x00556f70-0x00557070 | method | ScreenPaneBrowserNotificationHandler : reconstructable : 85% : strong : A002 2026-06-16 source-quality refresh clears 85/88 with owner/emitter [UID:0000CB][ScreenPane](by-class/ScreenPane.md), using prior IDA-backed docs, static ida_export.md.old, raw PE bytes, simroot, and autogen evidence to confirm exact 0x100 bounds, vtable-only reachability from 0x00623150, no direct rel32 callers, Bros producer/consumer immediates, browser::Notification 12-byte payload layout, state 0/1 +0x511 writes, legacy browser-dialog close path, optional AlertPane construction with payload text/g_pBackPane/OK/null secondary, binary fallback return from [ebp+0x0b], empty generated ScreenPane.cpp and simroot omission, while final C++ remains blank because source method name, +0x511 member name, notification state names, AlertPane formal names, and fallback-return source representation remain unresolved.`

## 2026-06-16 Checkpoint - A002-goal2-lowcompletion-screenpane-browser-notification-handler-20260616

- Changed files:
  - `by-memory/0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler.md`
  - Validator-owned/generated state refreshed by scoped validator: `project-level/-auto-completion-stats.md` and `tools/validator.ini`; autogen reports/C++ were no-op.
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score/routing:
  - [UID:0002VO] `ScreenPaneBrowserNotificationHandler`: `82/86 -> 85/88`.
  - `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000CB] `ScreenPane`; direct route is justified by ScreenPane vtable slot `0x00623150` and mutation of ScreenPane state. Browser owns the payload producer/type only.
  - Final C++ remains blank despite numeric eligibility because the source virtual method name, ScreenPane `+0x511` field name, browser-notification state enum names, formal AlertPane parameter names, and source intent for the unsupported-state fallback are not recovered.
- Evidence checked:
  - Read active A002 `goal.md`, `Supervisor.md`, `Supervisor_notes.md`, A002 `notes.md`, `current_leases.md`, `by-structure.md`, `by-memory/-guidance.md`, proposed source tree, B001 inference research guidance, target page, ScreenPane class/file/aggregate/vtable docs, Browser file, `browser::Notification`, `PostBrowserNotification`, Browser notification destructor, AlertPane class/core/layout docs, browser singleton/global docs, `g_pBackPane`, and `DialogOkButtonString`.
  - Live read-only IDA MCP session `a001_goal2_00023O` on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; `server_health` reported Hex-Rays and strings cache ready. No IDA DB writes were made.
  - `lookup_funcs` reconfirmed `sub_556F70` size `0x100`, neighboring ScreenPane functions, browser producer/helper, AlertPane constructor, string helpers, allocator, and notification post helper.
  - `decompile`/`disasm` of `0x00556f70` reconfirmed `Bros` channel compare, `Block+0x08`/`Block+0x0c`, payload state at `+0x04`, state `0` setting `this+0x511`, state `1` clearing it, `dword_67AB90` close via vtable arg `1`, payload string empty test/accessor, `0x270` AlertPane allocation, and fallback `0x00557029 mov al, byte ptr [ebp+Block+3]`.
  - `decompile 0x00470f20` confirmed `browser::Notification` helper allocation/layout/post for state argument; `decompile 0x0046f810` confirmed inline state `0` producer and helper state `1` producer; `decompile 0x0049feb0` confirmed AlertPane argument roles: text, layout/reference context, primary label, secondary label.
  - Scoped IDA `search_text` over `0x00556910-0x00559b8b` found only this handler's two `511h` ScreenPane-offset writes. A wider text search was unstable, so the target documents the bounded result rather than a whole-binary absence.
  - Current docs/Wave2 trace notes were checked only under project-documentation per A002 goal rule; no external Wave2/Wave3 source data or tool internals were used.
- Source-quality blocker decisions:
  - Method/source name: unresolved after ScreenPane class/file/aggregate/vtable docs and IDA names; only `sub_556F70` and the descriptive docs label are available.
  - Payload type/layout: resolved to `browser::Notification` with 12-byte layout; enum names for states `0` and `1` remain unresolved.
  - `+0x511`: behaviorally resolved as the ScreenPane browser-notification state byte; field name unresolved because the checked ScreenPane range has only these two writes and no independent read/name evidence.
  - Alert constructor parameters: role order resolved; original formal names unresolved.
  - Fallback return: binary behavior resolved; source intent unresolved because documented producers emit only states `0` and `1`.
  - No B-agent escalation is recommended for this bounded pass: ownership/source route is local, there are no missing/overbroad child pages, and remaining blockers are final naming/source-intent quality.
- Validation:
  - `python .\tools\validator.py --mode file --file by-memory\0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`; validator reported completion/confidence updates, reference index add, Low_Completion/Low_Both/by-memory stats row removals, registry rebuild, and projected stats update.
- Leases:
  - A002 held leases for `by-memory/0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler.md` and this notes file before editing; leases auto-renewed during the pass.
- IDA DB changes: none. No comments, renames, prototypes, type edits, function creation, patches, saves, or other IDA writes were made.
- Pending supervisor-owned `by-memory/-coverage-report.md` row replacement:
  - Placement: under [UID:0001G5] `0x00556910-0x00557132.ScreenPane`, replace the existing [UID:0002VO] child row immediately after the [UID:0001G5] aggregate row and before padding row `0x00557132-0x00557140` with:
    `        - [UID:0002VO][0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler](by-memory/0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler.md) 0x00556f70-0x00557070 | method | ScreenPaneBrowserNotificationHandler : reconstructable : 85% : strong : A002 2026-06-16 source-quality refresh keeps owner/emitter [UID:0000CB][ScreenPane](by-class/ScreenPane.md), confirms exact 0x100 body, ScreenPane vtable slot 0x00623150, Bros channel block/payload offsets, browser::Notification producer/layout, state 0 inline producer and state 1 helper producer, +0x511 writes scoped to this ScreenPane method in the checked ScreenPane range, legacy browser close through dword_67AB90, optional AlertPane call using payload text/g_pBackPane/OK/null secondary, binary fallback mov al from [ebp+Block+3], no direct code callers, and blank final C++ while the source method name, +0x511 field name, state enum names, formal alert parameter names, and fallback source intent remain unresolved.`

## 2026-06-16 Checkpoint - A002-goal2-lowcompletion-queue-source-quality-20260616-68

- Changed files:
  - `by-memory/0x005539e0-0x00553a5c.QueueConstructor.md`
  - `by-memory/0x005539e0-0x00553c07.Queue.md`
  - `by-memory/0x00553a60-0x00553ab9.QueueDestructor.md`
  - `by-memory/0x00553ac0-0x00553b05.QueueWriteSlotRaw.md`
  - `by-memory/0x00553b10-0x00553b55.QueueReadSlotRaw.md`
  - `by-memory/0x00553b60-0x00553b6a.QueueIsEmptyRaw.md`
  - `by-memory/0x00553b70-0x00553c07.QueueScalarDeletingDestructor.md`
  - `by-memory/0x00622d24-0x00622d30.QueueVtableData.md`
  - `by-class/Queue.md`
  - `by-file/Queue.md`
  - Validator-owned/generated state refreshed by scoped validators: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, and `tools/validator.ini`.
  - `tools/leaser/Agents/Agent-A002/notes.md`
  - `by-memory/-coverage-report.md` already had shared working-tree modifications from the corrected C001 collision; A002 did not edit it and records exact pending rows below.
- Collision handling:
  - Reviewed the pre-existing Queue edits from the corrected C001 collision as shared workspace state. Kept valid IDA/source-quality evidence and direct class routing, corrected stale/unverified IDA-comment claims, corrected final-code gate wording to the active source-quality decision, fixed the Queue class page's stale aggregate score, and retained the corrected Queue vtable slots.
  - No unrelated class files were edited in this assignment.
- Score changes and owner/emitter decisions:
  - [UID:0001FM] `QueueConstructor`: `82/86 -> 85/89`; `CANONICAL_OWNER` and `EMITTER_UIDS` are [UID:0000BF] `Queue`, position `10`.
  - [UID:0001FN] `Queue` aggregate: `82/86 -> 85/88`; `CANONICAL_OWNER` and `EMITTER_UIDS` are [UID:0000BF] `Queue`, position `5`.
  - [UID:0001FO] `QueueDestructor`: `82/86 -> 85/89`; `CANONICAL_OWNER` and `EMITTER_UIDS` are [UID:0000BF] `Queue`, position `20`.
  - Support raw helpers [UID:0001FP]/[UID:0001FQ]/[UID:0001FR] stay `85/88`; A002 reviewed/accepted the current direct class owner/emitter route from the collision edit because the class/file route clears `85/85`.
  - [UID:0001FS] `QueueScalarDeletingDestructor`: `84/90 -> 85/91`; direct class owner/emitter [UID:0000BF], position `60`; documented as compiler-generated binary output from the source-level virtual destructor.
  - [UID:0003CS] `QueueVtableData`: `86/92 -> 87/93`; direct class owner/emitter [UID:0000BF]. It is source-declared/generated-binary data, not hand-authored final C++.
  - [UID:0000BF] `Queue` remains `86/86`, owner/emitter [UID:0000MW] `Queue`; [UID:0000MW] `Queue` remains `86/85`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`.
- Source-quality evidence checked:
  - Live/current IDA evidence from session `a002_goal65_20260616` was reviewed: modeled functions at `0x005539e0` size `0x7c`, `0x00553a60` size `0x59`, and `0x00553b70` size `0x97`; raw starts `0x00553ac0`, `0x00553b10`, and `0x00553b60` remain not functions.
  - `xrefs_to`/caller checks show zero direct refs to the constructor, ordinary destructor, and raw helper starts; scalar deleting destructor has the single vtable data xref at `0x00622d24`.
  - VA/RVA pointer-byte scans found no stored references for constructor, ordinary destructor, or raw helper starts; the scalar deleting destructor VA pointer is present only in the Queue vtable slot.
  - Byte checks confirm all internal `0xcc` padding spans, the raw write/read `retn 4` endpoints, and the compact empty predicate bytes.
  - Queue vtable data is now documented as slots `0x00553b70`, `0x004f4b10`, and `0x0041b6c0`; stale `0x00554b00` was rejected as a Region vtable slot.
  - IDA type/struct queries did not recover a local `Queue` UDT. Current validator-generated `auto-generated/NexusTK/util/Queue.cpp` is a zero-byte root; `simroot_v2/class_Queue.cpp` still omits the ordinary destructor and raw helpers.
  - Current IDA comment review found only generic size/block/stack-cookie annotations for these functions. A002 made no IDA DB edits and the docs no longer rely on unverified source-quality IDA comments.
  - Final C++ remains blank despite numeric emitter eligibility because active-use proof, raw helper reachability/source representation, original method names/signatures, and final `Queue.h`/`Queue.cpp` declaration shape remain unresolved. No B-agent escalation is recommended for this bounded pass because ownership/source placement is local and the remaining blockers are final names/reachability, not broad source-structure inference.
- Validation:
  - All commands below exited `0` with `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x005539e0-0x00553a5c.QueueConstructor.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-memory\0x005539e0-0x00553c07.Queue.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-memory\0x00553a60-0x00553ab9.QueueDestructor.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-memory\0x00553ac0-0x00553b05.QueueWriteSlotRaw.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-memory\0x00553b10-0x00553b55.QueueReadSlotRaw.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-memory\0x00553b60-0x00553b6a.QueueIsEmptyRaw.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-memory\0x00553b70-0x00553c07.QueueScalarDeletingDestructor.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-memory\0x00622d24-0x00622d30.QueueVtableData.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-class\Queue.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-file\Queue.md --apply --queue-timeout 240`
- Leases:
  - C001 Queue leases had expired/cleared before A002 editing; A002 leased all Queue target/support docs and this notes file before edits.
  - The first A002 lease window expired during validation; A002 reacquired the same leases before writing notes.
- IDA DB changes: none by A002. No comments, renames, prototypes, types, function creation, patches, or saves were made.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows:
  - Placement: replace the existing Queue cluster rows under the Queue executable cluster after padding row `0x005539d9-0x005539e0` and before padding row `0x00553ab9-0x00553ac0` / surrounding raw-helper padding rows with:
    `    - [UID:0001FN][0x005539e0-0x00553c07.Queue](by-memory/0x005539e0-0x00553c07.Queue.md) 0x005539e0-0x00553c07 | class aggregate | Queue : reconstructable : 85% : strong : A002 2026-06-16 source-quality review of pre-existing C001 collision edits keeps direct owner/emitter [UID:0000BF][Queue](by-class/Queue.md), confirms exact child inventory, corrected +0x04 slot-size/+0x08 slot-count layout, modeled constructor/destructor/scalar boundaries, raw write/read/empty not-a-function boundaries, zero direct xrefs for constructor/ordinary destructor/raw starts, no VA/RVA pointer-byte hits for non-vtable starts, scalar vtable-only xref, corrected vtable slots, internal padding, zero-byte generated Queue.cpp, no local Queue UDT, compiler-wrapper scalar handling, and blank final C++ while active-use proof and final Queue header/method names remain unresolved.`
    `    - [UID:0001FM][0x005539e0-0x00553a5c.QueueConstructor](by-memory/0x005539e0-0x00553a5c.QueueConstructor.md) 0x005539e0-0x00553a5c | constructor | QueueConstructor : reconstructable : 85% : strong : A002 2026-06-16 source-quality review keeps direct owner/emitter [UID:0000BF][Queue](by-class/Queue.md), confirms exact modeled 0x7c constructor, LObject base call, Queue vtable store, +0x04 slot-size/+0x08 slot-count stores, slotSize*slotCount zero-allocation through sub_5160D0, read/write index initialization, raw-helper layout corroboration, no direct xrefs/callers or VA/RVA pointer-byte hits for the start, zero-byte generated Queue.cpp, no verified source-quality IDA comment reliance, and blank final C++ while original constructor signature/header names and active construction-site proof remain unresolved.`
    `    - [UID:0001FO][0x00553a60-0x00553ab9.QueueDestructor](by-memory/0x00553a60-0x00553ab9.QueueDestructor.md) 0x00553a60-0x00553ab9 | destructor | QueueDestructor : reconstructable : 85% : strong : A002 2026-06-16 source-quality review keeps direct owner/emitter [UID:0000BF][Queue](by-class/Queue.md), confirms exact modeled 0x59 ordinary destructor, Queue vtable restore, +0x0c backing-buffer free/clear through GetMemoryMan/FreeBufferMemory, LObject cleanup, scalar-destructor cleanup parity, no direct xrefs/callers or VA/RVA pointer-byte hits for the start, generated-output omission, no verified source-quality IDA comment reliance, and blank final C++ while final destructor declaration/header spelling and active non-deleting destructor reachability remain unresolved.`
  - Placement: replace the existing [UID:0001FP], [UID:0001FQ], and [UID:0001FR] rows between padding rows `0x00553ab9-0x00553ac0`, `0x00553b05-0x00553b10`, `0x00553b55-0x00553b60`, and `0x00553b6a-0x00553b70` with:
    `    - [UID:0001FP][0x00553ac0-0x00553b05.QueueWriteSlotRaw](by-memory/0x00553ac0-0x00553b05.QueueWriteSlotRaw.md) 0x00553ac0-0x00553b05 | raw helper | QueueWriteSlotRaw : reconstructable : 85% : strong : A002 2026-06-16 source-quality review keeps direct owner/emitter [UID:0000BF][Queue](by-class/Queue.md), confirms raw not-a-function status, no xrefs/callers, no VA/RVA pointer-byte hits, exact c2 04 00 endpoint, GetMemoryMan/Memmove copy path, +0x04 slot-size/+0x08 wrap-limit layout, +0x14 write-index wrap, adjacent 0xcc padding, generated-output omission, read-only IDA decision, and blank final C++ while original method spelling and raw-helper reachability remain unresolved.`
    `    - [UID:0001FQ][0x00553b10-0x00553b55.QueueReadSlotRaw](by-memory/0x00553b10-0x00553b55.QueueReadSlotRaw.md) 0x00553b10-0x00553b55 | raw helper | QueueReadSlotRaw : reconstructable : 85% : strong : A002 2026-06-16 source-quality review keeps direct owner/emitter [UID:0000BF][Queue](by-class/Queue.md), confirms raw not-a-function status, no xrefs/callers, no VA/RVA pointer-byte hits, exact c2 04 00 endpoint, GetMemoryMan/Memmove copy path, +0x04 slot-size/+0x08 wrap-limit layout, +0x10 read-index wrap, adjacent 0xcc padding, generated-output omission, read-only IDA decision, and blank final C++ while original method spelling and raw-helper reachability remain unresolved.`
    `    - [UID:0001FR][0x00553b60-0x00553b6a.QueueIsEmptyRaw](by-memory/0x00553b60-0x00553b6a.QueueIsEmptyRaw.md) 0x00553b60-0x00553b6a | raw helper | QueueIsEmptyRaw : reconstructable : 85% : strong : A002 2026-06-16 source-quality review keeps direct owner/emitter [UID:0000BF][Queue](by-class/Queue.md), confirms raw not-a-function status, no xrefs/callers/callees, no VA/RVA pointer-byte hits, exact ten-byte readIndex==writeIndex predicate, adjacent 0xcc padding, generated-output omission, read-only IDA decision, and blank final C++ while original method spelling and raw-helper reachability remain unresolved.`
  - Placement: replace the existing [UID:0001FS] row after padding `0x00553b6a-0x00553b70` and before padding `0x00553c07-0x00553c10` with:
    `    - [UID:0001FS][0x00553b70-0x00553c07.QueueScalarDeletingDestructor](by-memory/0x00553b70-0x00553c07.QueueScalarDeletingDestructor.md) 0x00553b70-0x00553c07 | scalar deleting destructor | QueueScalarDeletingDestructor : reconstructable : 85% : strong : A002 2026-06-16 source-quality correction keeps direct owner/emitter [UID:0000BF][Queue](by-class/Queue.md), confirms exact modeled 0x97 scalar deleting destructor, sole vtable data xref at 0x00622d24, Queue vtable restore, +0x0c MemoryMan free/clear, LObject cleanup, scalar delete and guarded bit-4 branches, no direct code callers, expected VA pointer bytes only at the vtable slot, compiler-wrapper source treatment, and blank final C++ because the wrapper should be regenerated from the source-level virtual destructor and final Queue declarations remain unresolved.`
  - Placement: insert this child row immediately under [UID:000269] `0x00622d24-0x00622f54.QueueReconnectCopyReadOnlyData`, before [UID:00026A] `0x00622f54-0x006230c8.RegionMenuPaneReadOnlyData`:
    `        - [UID:0003CS][0x00622d24-0x00622d30.QueueVtableData](by-memory/0x00622d24-0x00622d30.QueueVtableData.md) 0x00622d24-0x00622d30 | vtable-data | QueueVtableData : reconstructable : 87% : very-strong : A002 2026-06-16 source-quality review/correction keeps owner/emitter [UID:0000BF][Queue](by-class/Queue.md), confirms exact Queue vtable slots 0x00553b70, 0x004f4b10, and 0x0041b6c0, vtable-store xrefs from constructor/ordinary destructor/scalar destructor, successor boundary at the ConnectionClosedDialog RTTI locator pointer/vtable start, rejects stale 0x00554b00 Region slot claim, and leaves final C++ blank because the vtable bytes are source-declared/generated-binary output from the Queue class declaration.`

## 2026-06-16 Checkpoint - A002-goal2-lowcompletion-registry-commandline-parsers-20260616-67

- Changed files:
  - `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`
  - Validator-owned/projected state refreshed by scoped validator: `project-level/-auto-completion-stats.md` and `tools/validator.ini`
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score/routing:
  - [UID:000220] `RegistryCommandLineParsers`: `82/86 -> 86/89`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000N4] `RegistryConfig`.
  - All twelve exact parser children were checked and already clear at least `85/86`, with direct RegistryConfig file routing. The aggregate is now above the 85/85 attachment gate as an evidence/index parent, not as a separate callable routine.
  - Final C++ remains blank despite numeric eligibility because the dispatcher/caller edge, source-facing helper names, synthetic startup-state offsets/fields, payload/session fields, and COM/interface names are not source-quality.
- Evidence checked:
  - Read active `goal.md`, active supervisor overrides in `tools/leaser/Agents/Supervisor.md`, `by-structure.md`, `by-memory/-guidance.md`, `by-project-structure/proposed-source-tree.md`, B001 `inference_research.md`, target page, RegistryConfig file/class pages, all twelve parser-child headers/evidence summaries, support string-data pages [UID:0003FV]/[UID:0003FX], and runtime helper page [UID:000221].
  - Live IDA MCP session `a002_goal65_20260616` was used read-only against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64` / `NexusTK.exe`; no comments, renames, type edits, function promotions, patches, or saves were made.
  - `server_health` showed Hex-Rays and strings cache ready. `lookup_funcs` reconfirmed only `0x0048fca0`, `0x00490b10`, and `0x004918e0` are modeled parser functions; the nine other parser starts remain raw non-functions, and successor `0x00491b30` is modeled.
  - `xrefs_to` reconfirmed zero direct xrefs to all twelve parser starts; successor `0x00491b30` had the expected RegistryConfig vtable data ref from `0x00612620`.
  - `get_bytes` reconfirmed the predecessor, all internal, and successor `0xcc` padding gaps around `0x0048f400-0x00491b28`.
  - `find_bytes` searched little-endian VA and RVA encodings for all twelve parser starts and found zero matches, so no simple stored pointer-table/VA/RVA dispatch route was recovered.
  - Support data pages [UID:0003FV] and [UID:0003FX] cover the launcher/session and `/host:`/`/portno:`/`/id:` literal clusters. [UID:000221] covers the adjacent COM/CRT helper island as non-reconstructable runtime/helper support, so no parser-child/source split or helper reclassification was needed.
  - Generated output checked: `auto-generated/NexusTK/config/RegistryConfig.cpp` and `auto-generated/NexusTK/config/Config.cpp` are both zero-byte roots; the validator also reported no assembled code for both roots.
  - Wave2 history checked: stable `RegistryConfig` methods exist before and after the island, but parser starts have no live Wave2 resolution and are classified there as unresolved free launcher/bootstrap helpers, not direct class methods.
  - Wave3 issue history checked: `0x0048f400-0x00491b28` remains a generated-output/raw-helper omission follow-up between RegistryConfig defaults and persistence.
  - No B-agent escalation is recommended for this bounded pass: there are no missing or overbroad children, ownership/source route is supported through `RegistryConfig`, and the remaining blockers are source-quality names/dispatch rather than broad source-layout inference.
- Validation:
  - `python .\tools\validator.py --mode file --file by-memory\0x0048f400-0x00491b28.RegistryCommandLineParsers.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`; validator reported `autogen_emitter_has_no_code: 1`, `autogen_registry_rebuild: 1`, and `projected_stats_update: 1`.
- Leases:
  - Leased `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md` and this notes file before editing.
  - Release after validation/checkpointing returned `Rejected[No active lease]` for both paths because the renewed 300-second leases had already expired. Final `current_leases.md` showed no active A002 entries.
- IDA DB changes: none. All IDA activity was read-only.
- Pending supervisor-owned `by-memory/-coverage-report.md` row replacement:
  - Placement: under [UID:000110] `ConfigAndRegistryDefaults`, replace the existing [UID:000220] row after the padding row `0x0048f3f1-0x0048f400` and before child [UID:0002BG] with:
    `    - [UID:000220][0x0048f400-0x00491b28.RegistryCommandLineParsers](by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md) 0x0048f400-0x00491b28 | function cluster | RegistryCommandLineParsers : reconstructable : 86% : strong : A002 2026-06-16 source-quality refresh raises the aggregate after all twelve exact parser children clear 85/86+, keeping owner/emitter [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md), with live IDA session a002_goal65_20260616 confirming modeled/raw starts, zero direct xrefs and zero VA/RVA pointer-encoding hits for all child starts, exact 0xcc boundary/gap padding, support string-data pages, COM/CRT helper exclusion, Wave2 no-resolution/free-helper classification, Wave3/generated-output omission status, and blank final C++ while dispatcher reachability, original helper names/signatures, startup-state fields, provider/interface names, and generated bodies remain unresolved.`
- Next useful follow-up:
  - A later source-quality pass should recover the hidden launcher dispatch/caller route and name the shared startup-state structure/fields before any parser child emits final C++. A generated stats rescore is recommended after enough similar single-file rows drop from the low-score lists.

Supervisor integration update (2026-06-16): supervisor accepted `A002-goal2-lowcompletion-registry-commandline-parsers-20260616-67` after verifying the source-quality research, owner/emitter route, target score, and stale shared-report row. The exact [UID:000220] `by-memory/-coverage-report.md` replacement row was applied, and scoped validators for the target plus the shared report exited `0` with `ok:1`. No A002 supervisor-owned memory coverage rows remain pending for this batch.

## 2026-06-16 Checkpoint - A002-goal2-class-completion-clan-spell-20260616-26 continuation audit

- Changed files:
  - `by-class/ClanEnlistListPane.md`
  - `by-class/ClanJoinListPane.md`
  - `by-class/ClientSpellMenuDialog.md`
  - Validator-owned/projected state refreshed by scoped validators: `project-level/-auto-completion-stats.md` and `tools/validator.ini`
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score/routing:
  - [UID:00002C] `ClanEnlistListPane`: unchanged at `86/90`; owner/emitter remain [UID:0000I8] `Clan`.
  - [UID:00002H] `ClanJoinListPane`: unchanged at `86/90`; owner/emitter remain [UID:0000I8] `Clan`.
  - [UID:00002R] `ClientSpellMenuDialog`: unchanged at `86/90`; owner/emitter remain [UID:0000O2] `SpellMenuDialogs`.
  - No final C++ was added. The generated roots `auto-generated/NexusTK/social/Clan.cpp` and `auto-generated/NexusTK/ui/dialogs/SpellMenuDialogs.cpp` remain zero-byte/no-assembled-code roots.
- Source-quality evidence checked:
  - Read current assignment context in `goal.md`, A002 notes, `Supervisor.md`, `Supervisor_notes.md`, `by-structure.md`, `by-project-structure/proposed-source-tree.md`, B001 `inference_research.md`, by-class guidance, the three target class pages, `by-file/Clan.md`, `by-file/SpellMenuDialogs.md`, class coverage rows, generated class/file coverage rows, and support pages for clan constructor/list renderer/join action/list handlers/subtype-6 helpers/vtable data/join packet helper plus spell aggregate/list/vtable/action-state/player-data/chat-color pages.
  - Live IDA MCP session `a002_goal65_20260616` was used read-only against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; no comments, renames, prototypes, type edits, function creation, patches, or database saves were made.
  - IDA `server_health` reported `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, strings cache ready, and analysis not active.
  - ClanEnlistListPane: `lookup_funcs` reconfirmed `sub_484030` size `0x1f2`, shared draw `0x004887d0` size `0xf1`, selected-row action `0x00488970` size `0x21`, key/event handler `0x004889a0` size `0x19d`, and subtype-6 helpers `0x00485960` size `0x69` / `0x004859d0` size `0xee`. `xrefs_to` reconfirmed vtable-only refs at `0x006158b4`, `0x006158b0`, and `0x00615898`, plus exactly two subtype-helper callers for each helper. Decompilation reconfirmed selected index `+0x134`, selected text through `0x004f3dc0`, Enter through action `1`, key `0x84` inline `{0x4b,6,3}` serialization, `g_packetSender`, and follow-up helper `0x00485960`. `get_bytes` reconfirmed `0xcc` padding around the handlers.
  - ClanJoinListPane: `lookup_funcs` reconfirmed selected-row action `0x004888d0` size `0x21`, key/event handler `0x00488900` size `0x68`, shared draw `0x004887d0` size `0xf1`, and join helper `0x00485590` size `0xf2`. `xrefs_to` reconfirmed vtable-only refs at `0x006157ec`, `0x006157d4`, and `0x006157f0`; helper `0x00485590` has only the two join-list callers `0x004888ea` and `0x00488951`. Decompilation reconfirmed Enter-gated subtype `2`, action `1` packet send, selected index `+0x134`, and selected text through `0x004f3dc0`. Padding around `0x004888c1`, `0x004888f1`, and `0x00488968` remains `0xcc`.
  - ClientSpellMenuDialog: `lookup_funcs` reconfirmed constructor `0x0051db40` size `0x993`, command handler `0x0051e4e0` size `0x112`, updater `0x0051e600` size `0x3d`, `ClientSpellMenuItemList` constructor `0x0051e640` size `0x6c`, activation `0x0051e880` size `0x0b`, and renderer `0x0051e890` size `0x108`. `xrefs_to` reconfirmed constructor refs from dispatcher/wrapper `0x0051770b` and `0x00517c07`, vtable-only command/update refs `0x0061f310` and `0x0061f314`, exactly two list-constructor refs from the spell constructor, renderer vtable ref `0x0061f3e4`, and only two chat-color constructor refs `0x00482837/0x0048295d` for `0x00482fb0`. Decompilation reconfirmed command `1` opcode `0x39` send, child slots `1` and `6`, list storage `+0x108`, context offsets `+0x14c/+0x150/+0x154/+0x158`, renderer text at `entry + 4`, and constructor reads through `dword_67A748`. Padding around `0x0051e63d` and `0x0051e998` remains `0xcc`.
- Blockers investigated:
  - Clan final class declarations, common `ListPane` virtual slot names, selected-entry helper name, source-facing packet subtype/action enum names, and key `0x84` semantics remain unresolved after checking IDA function/vtable/caller/decompile evidence, support docs, file/source-tree docs, and generated roots. The available evidence exposes offsets, vtable slots, packet bytes, and synthetic helper names but not original declarations, so scores remain conservative and final C++ stays blank.
  - ClientSpellMenuDialog final row/action enum names, row payload struct, local-player spell-table field names, child-slot constants, and packet context field names remain unresolved after checking IDA decompilation/xrefs, g_pCollectionData/player-data support docs, ClientSpellMenuItemList evidence, and generated `SpellMenuDialogs.cpp`. The stale `ChattingColorListPane*` local type is rejected by negative constructor xrefs and spell-list constructor/renderer evidence.
  - No B-agent escalation is recommended for this bounded continuation: there are no missing/overbroad children or heavy source-layout inference gaps. The remaining blockers are source-quality names/declarations for already-bounded class methods.
- Validation:
  - `python .\tools\validator.py --mode file --file by-class\ClanEnlistListPane.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`; generated class/file/function/global/item/memory/type reports unchanged.
  - `python .\tools\validator.py --mode file --file by-class\ClanJoinListPane.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`; generated class/file/function/global/item/memory/type reports unchanged.
  - `python .\tools\validator.py --mode file --file by-class\ClientSpellMenuDialog.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`; generated class/file/function/global/item/memory/type reports unchanged.
- Leases:
  - Leased the three target class pages and this notes file before editing. No target lease conflict was present; concurrent C001 leases were unrelated MessageDialogs files.
- IDA DB changes: none. All IDA activity was read-only.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: none. No by-memory docs or memory coverage rows were edited or required.
- Next useful follow-up:
  - A future final-C++ pass should name the common `ListPane` virtual slots and selected-entry helper across non-clan list subclasses, then reconcile Clan packet subtype/action enum names and the client-local spell row/player-data layout before adding class methods to generated source.

## 2026-06-16 Checkpoint - A002-goal2-lowcompletion-helper-source-quality-20260616-66

- Changed files:
  - `by-memory/0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper.md`
  - `by-memory/0x0049d780-0x0049d7b0.DescPaneSetSourceAndIndexRaw.md`
  - `by-memory/0x004d1a20-0x004d1b72.MapTileImageLibDrawTile.md`
  - `by-memory/0x00546440-0x005464ac.ParcelPaneDestructor.md`
  - Validator-owned/projected state refreshed by scoped validators: `project-level/-auto-completion-stats.md` and `tools/validator.ini`; autogen reports/roots were checked by validator and remained no-op/no-code.
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score changes and owner/emitter decisions:
  - [UID:0002EN] `CheatDetectorTimeSnapshotHelper`: `82/86 -> 85/88`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:000020] `CheatDetector`. Final C++ remains blank because the raw helper has no caller/xref, no pointer encoding to the start, no recovered source-facing helper name, and no source-quality field names.
  - [UID:00012N] `DescPaneSetSourceAndIndexRaw`: `82/86 -> 85/89`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:00003Q] `DescPane`. Final C++ remains blank because the provider/interface name, setter name, and inherited invalidation slot name remain unresolved.
  - [UID:0002J0] `MapTileImageLibDrawTile`: `82/86 -> 86/89`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:00007T] `MapTileImageLib`. Final C++ remains blank because parameter names, palette helper names, render callback typedefs, and final member names are not source-quality.
  - [UID:0001EK] `ParcelPaneDestructor`: `82/86 -> 85/89`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000A6] `ParcelPane`. Final C++ remains blank because shared Pane cleanup/helper names, final class declarations, and parcel field names remain unresolved.
- Source-quality evidence checked:
  - Live IDA MCP session `a002_goal65_20260616` was used read-only; no comments, renames, type edits, function promotions, patches, or database saves were made.
  - Raw/no-xref reachability was investigated for `0x00483f90`, `0x0049d780`, and `0x00546440` with `lookup_funcs`, `xref_query`, `get_bytes`, and raw-start VA/RVA `find_bytes` scans. CheatDetector and DescPane remain raw non-functions with no xrefs or direct pointer encodings. ParcelPane destructor is a modeled function but has no direct xrefs or pointer encodings; vtable/scalar-wrapper parity proves destructor-family placement.
  - CheatDetector evidence now includes exact padding-bounded bytes, `GetSystemTimeAsFileTime`, `g_pTimerMgr+0x18`, constructor/base context through `TimerHandler`, no embedded source filenames, and empty generated root `auto-generated/NexusTK/security/CheatDetector.cpp`.
  - DescPane evidence now includes corrected post-body padding, `+0xf8/+0xfc` provider/index setter fields, invalidation through inherited slot `+0x20`, refresh consumer/provider slot `+0x24`, no local DescPane/provider UDT, no embedded source filenames, and empty generated root `auto-generated/NexusTK/ui/controls/DescPane.cpp`.
  - MapTile evidence now includes exact `sub_4D1A20` size `0x152`, four call sites (`FittingRoomUserImageControlPane::OnPaint`, raw MapPane helper `0x0050c3d7`, MapPane tile renderer, PhotoPane constructor/render setup), legacy `TILE.TBD` clamp, EPFTileContext setup, metadata pointer `+0x04`, record pointer `+0x08`, palette-filter gate, `TILE.PAL` slot `0`, SurfaceRenderCallbackTable fallback/blit dispatch, no preserved callback/MapTile UDT, and empty generated root `auto-generated/NexusTK/render/MapTileImageLib.cpp`.
  - ParcelPane evidence now includes exact `sub_546440` size `0x6c`, vtable restores `0x00621c3c/0x00621c90/0x00621cc0`, shared cleanup calls `sub_544CE0`, `sub_544D70`, `sub_544580`, `g_pParcelPane` clear, scalar destructor parity at `0x00547000`, broad shared-helper refs for `0x00544c50` and `0x00544580`, no local ParcelPane/Pane UDT, no embedded source filenames, and empty generated root `auto-generated/NexusTK/ui/panels/ParcelPane.cpp`.
  - No B-agent escalation is recommended for this batch. Ownership/source placement is bounded and supported; remaining blockers are final names/types/caller reachability rather than broad ownership inference.
- Validation:
  - `python .\tools\validator.py --mode file --file by-memory\0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`; completion/confidence updates recorded and [UID:0002EN] removed from generated low-completion/low-both stats.
  - `python .\tools\validator.py --mode file --file by-memory\0x0049d780-0x0049d7b0.DescPaneSetSourceAndIndexRaw.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`; completion/confidence updates recorded and [UID:00012N] removed from generated low-completion/low-both stats.
  - `python .\tools\validator.py --mode file --file by-memory\0x004d1a20-0x004d1b72.MapTileImageLibDrawTile.md --apply --queue-timeout 240` -> first exit `0`, `ok: 1`, with a validator UID correction exposing a bad `0000FW` link; after fixing to [UID:000056] `FittingRoomUserImageControlPane`, rerun exited `0`, `ok: 1`, removed stale `0000FW` reference index entry, added `000056`, and confirmed [UID:0002J0] was no longer in generated low-completion stats.
  - `python .\tools\validator.py --mode file --file by-memory\0x00546440-0x005464ac.ParcelPaneDestructor.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`; completion/confidence updates recorded and [UID:0001EK] removed from generated low-completion/low-both stats.
- Leases:
  - Leased the four by-memory target pages and this notes file before editing. The initial lease window expired during evidence/diff work, so the same five paths were re-leased before validation.
  - The four by-memory target leases were released successfully after validation. The notes lease was released successfully after the checkpoint, then briefly re-leased to record this final lease status.
- IDA DB changes: none. All IDA activity was read-only.
- Pending supervisor-owned `by-memory/-coverage-report.md` row replacements:
  - Placement: under the CheatDetector aggregate, replace existing [UID:0002EN] row after padding `0x00483f86-0x00483f90` and before [UID:000109] `CheatDetectorAlwaysTrueVirtual` with:
    `      - [UID:0002EN][0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper](by-memory/0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper.md) 0x00483f90-0x00483fd9 | unmodeled helper body | CheatDetectorTimeSnapshotHelper : reconstructable : 85% : strong : A002 2026-06-16 source-quality refresh reconfirms no IDA function, zero xrefs, no VA/RVA pointer encodings for the raw start, exact padding-bounded bytes, GetSystemTimeAsFileTime import use, g_pTimerMgr+0x18 sampling, CheatDetector constructor/base context, empty generated CheatDetector.cpp, and blank final C++ while caller/reachability, original helper name, and field names remain unresolved.`
  - Placement: under the DescPane aggregate, replace existing [UID:00012N] row with:
    `    - [UID:00012N][0x0049d780-0x0049d7b0.DescPaneSetSourceAndIndexRaw](by-memory/0x0049d780-0x0049d7b0.DescPaneSetSourceAndIndexRaw.md) 0x0049d780-0x0049d7b0 | raw method body | DescPaneSetSourceAndIndexRaw : reconstructable : 85% : strong : A002 2026-06-16 source-quality refresh confirms raw non-function/no-xref status, no VA/RVA pointer encodings for the start, exact padding-bounded setter bytes, +0xf8/+0xfc provider/index updates, inherited vtable-slot +0x20 invalidation, RefreshDescription provider-slot +0x24 behavior, no local DescPane/provider UDT, empty generated DescPane.cpp, and blank final C++ while provider-interface and source-facing setter names remain unresolved.`
  - Placement: under the MapTileImageLib local method cluster, replace existing [UID:0002J0] row with:
    `        - [UID:0002J0][0x004d1a20-0x004d1b72.MapTileImageLibDrawTile](by-memory/0x004d1a20-0x004d1b72.MapTileImageLibDrawTile.md) 0x004d1a20-0x004d1b72 | method | MapTileImageLib::DrawTile : reconstructable : 86% : strong : A002 2026-06-16 source-quality refresh reconfirms the exact 0x152 function, padding before LoadTileEpfMetadata, four call sites including raw MapPane helper 0x0050c3d7, legacy TILE.TBD clamp, EPFTileContext setup, metadata pointer +0x04, MapTileRecord pointer +0x08, palette-filter gate, TILE.PAL slot 0 lookup, SurfaceRenderCallbackTable fallback/blit dispatch, empty generated MapTileImageLib.cpp, and blank final C++ while final parameter, palette-helper, callback typedef, and member names remain unresolved.`
  - Placement: under the ParcelNotificationPanes aggregate, replace existing [UID:0001EK] row with:
    `    - [UID:0001EK][0x00546440-0x005464ac.ParcelPaneDestructor](by-memory/0x00546440-0x005464ac.ParcelPaneDestructor.md) 0x00546440-0x005464ac | destructor | ParcelPaneDestructor : reconstructable : 85% : strong : A002 2026-06-16 source-quality refresh reconfirms exact sub_546440 size 0x6c, no direct xrefs, no VA/RVA pointer encodings for the start, vtable restores 0x00621c3c/0x00621c90/0x00621cc0, shared Pane cleanup/layer-helper callees, g_pParcelPane clear, padding before SetParcelSlotData, scalar-destructor parity, empty generated ParcelPane.cpp, and blank final C++ while base cleanup/helper and parcel field names remain unresolved.`

## 2026-06-16 Supervisor Integration - A002-goal2-lowcompletion-helper-source-quality-20260616-66

- Supervisor accepted the helper/source-quality batch after direct review. [UID:0002EN] clears the gate at `85/88`, [UID:00012N] clears at `85/89`, [UID:0002J0] clears at `86/89`, and [UID:0001EK] clears at `85/89`; all owner/emitter routes stayed unchanged.
- The required blocker investigation was present: raw no-xref reachability, VA/RVA pointer-encoding scans, helper/method/source-placement names, provider/interface names, MapTile parameter/callback/palette names, ParcelPane cleanup/helper names, generated-output omissions, and final-C++ eligibility were checked and documented.
- Supervisor applied the four exact [UID:0002EN], [UID:00012N], [UID:0002J0], and [UID:0001EK] shared `by-memory/-coverage-report.md` replacement rows, then reran scoped validators for the shared report and the four target pages; all exited `0` with `ok:1`. No A002 supervisor-owned memory rows remain pending for this batch.

## 2026-06-16 Supervisor Integration - A002-goal2-decoder-keyspeed-baramapp-support-20260616

- Supervisor accepted the returned low-completion support batch after direct review. [UID:00013T] `DecoderNoopVirtual`, [UID:00013U] `DecoderScalarDeletingDestructor`, [UID:0002IS] `KeySpeedMgrApplyKeyboardRepeatSettingsRaw`, and [UID:0002Q2] `BaramAppScalarDeletingDestructor` all clear the gate at `85/90`.
- Source-quality/compiler-generated-name work was sufficient for this stage: Decoder virtual/destructor support, KeySpeedMgr raw keyboard-repeat helper evidence, and BaramApp scalar-deleting destructor routes were investigated; final C++ remains blank only where original declarations/source split remain unproven.
- Supervisor applied the four exact pending `by-memory/-coverage-report.md` replacement rows and reran scoped validators for the shared report and four target docs; all exited `0` with `ok:1`. No A002 supervisor-owned memory coverage rows remain pending for this batch.

## 2026-06-16 Supervisor Integration - A002-goal2-type-confidence-browser-human-desc-layouts-20260616-62

- Supervisor accepted the batch as complete after A002 raised [UID:0001SK] `BrowserInitFlags` `85/87 -> 86/88`, [UID:0001SM] `BrowserOverlayStyle` `85/88 -> 86/89`, [UID:0001UR] `HumanImageLibLayout` `85/87 -> 87/89`, and [UID:0001U3] `DescPaneLayout` `85/88 -> 86/89`.
- Owner/emitter decisions stayed unchanged; no IDA DB edits were made; no supervisor-owned `by-memory/-coverage-report.md` rows were pending.
- Scoped validators for the four type pages and both by-type coverage reports exited `0` with `ok:1`.

## 2026-06-16 Supervisor Integration - A002-goal2-type-confidence-effect-employee-layouts-20260616-63

- Supervisor accepted the batch as complete after A002 raised [UID:0001U7] `EffectFrameRecord` `85/88 -> 86/89`, [UID:0001U8] `EffectInfo` `85/88 -> 86/89`, [UID:0001U9] `EffectObjImageLibLayout` `85/88 -> 86/89`, and [UID:0001UD] `EmployeeRecord` `85/88 -> 86/89`.
- Owner/emitter routes stayed unchanged; support `EffectObjImageLib` file/class caveats were refreshed without score changes; final member/header/source blockers were investigated with live IDA/support evidence; no IDA DB edits were made.
- Scoped validators for all touched by-* files exited `0` with `ok:1`, and no supervisor-owned `by-memory/-coverage-report.md` rows were pending.

## 2026-06-16 Assignment - A002-goal2-type-confidence-fitting-foldertree-fps-linkedlist-20260616-64

- Assigned targets: [UID:0001UH] `by-type/by-struct/FittingEquipmentStateLayout.md`; [UID:0001UJ] `by-type/by-struct/FolderTreePane__TreeElem.md`; [UID:0001UO] `by-type/by-struct/FpsPaneLayout.md`; [UID:0001UZ] `by-type/by-struct/LinkedListState.md`.
- This is a bounded by-type confidence batch from refreshed `project-level/-auto-completion-stats.md`. Targets have known owner/emitter routes or direct support anchors; this is not a heavy unknown-owner inference assignment unless evidence proves otherwise.
- Improve evidence/confidence and investigate final field/member/source-header names, source placement, generated omissions, layout size/order assumptions, direct consumers, owner placement, and final-C++ blockers. Resolve supported issues or record the exact evidence checked; do not merely repeat unresolved names.
- Do not directly edit `by-memory/-coverage-report.md`; record exact supervisor-owned rows if support memory docs change.
- Execution status: queued/pending. Replacement worker `019ed0b4-f775-7152-a9b1-8658a8bc78c4` failed immediately with revoked refresh-token authentication, so no A002 work has started for this assignment yet.

### Checkpoint - A002-goal2-type-confidence-fitting-foldertree-fps-linkedlist-20260616-64

- Changed files:
  - `by-type/by-struct/FittingEquipmentStateLayout.md`
  - `by-type/by-struct/FolderTreePane__TreeElem.md`
  - `by-type/by-struct/FpsPaneLayout.md`
  - `by-type/by-struct/LinkedListState.md`
  - `by-type/by-struct/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score changes and routing:
  - [UID:0001UH] `FittingEquipmentStateLayout`: `85/88 -> 86/89`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:000051] `FittingRoomDialogItemState`.
  - [UID:0001UJ] `FolderTreePane__TreeElem`: `85/88 -> 86/89`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:00005A] `FolderTreePane`.
  - [UID:0001UO] `FpsPaneLayout`: `85/88 -> 86/89`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:00005F] `FpsPane`.
  - [UID:0001UZ] `LinkedListState`: `85/88 -> 86/89`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000KR] `LinkedList`.
  - `by-type/by-struct/-coverage-report.md` rows were updated to match refreshed evidence/scores; `FpsPaneLayout` row also corrected stale `82%` coverage text.
- Source-quality investigations:
  - `FittingEquipmentStateLayout`: live IDA MCP session `b001_0001KM_20260616` checked `lookup_funcs`, `analyze_batch`, `type_query`, and `search_structs` for reset/constructor/destructor/category-boundary/vector helper evidence. IDA reconfirmed `this[144..146]`, `0xb4` entry stride, and no preserved FittingRoom item/equipment UDT. Generated `class_FittingRoomDialogItemState.cpp` was checked; its local overlays do not safely resolve the equipment-entry type or trailing-buffer field names.
  - `FolderTreePane__TreeElem`: live IDA checked helper starts/sizes and no preserved `FolderTreePane::TreeElem` UDT. Generated `class_FolderTreePane.cpp`, `class_TreeStorage_struct_FolderTreePane__TreeElem_.cpp`, and `class_TreeItor_struct_FolderTreePane__TreeElem_.cpp` were checked; they support nested ownership and 36-byte storage but still disagree/use generated names for several link fields.
  - `FpsPaneLayout`: live IDA checked modeled/raw boundary split, zero xrefs to raw starts `0x004b6410`, `0x004b64a0`, `0x004b69b0`, `0x004b6ae0`, raw disassembly for constructor/session/start/summary ranges, no preserved `FpsPane` UDT, and generated `class_FpsPane.cpp` synthetic field-name leads. Raw boundaries and final field names remain blockers to emitted C++.
  - `LinkedListState`: live IDA checked helper starts/sizes, cleanup decompilation, node allocation and payload-copy behavior, six cleanup xrefs across unrelated consumers, and no preserved `LinkedListState`/`ListNode` UDT. Generated recovered helpers agree on `ListNode` next/prev/value fields but do not resolve the original state/header declaration.
- Validation:
  - `python .\tools\validator.py --mode file --file by-type\by-struct\FittingEquipmentStateLayout.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-type\by-struct\FolderTreePane__TreeElem.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-type\by-struct\FpsPaneLayout.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-type\by-struct\LinkedListState.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-type\by-struct\-coverage-report.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
- Leases:
  - Leased the four target type pages, `by-type/by-struct/-coverage-report.md`, and this notes file before editing.
- IDA DB changes: none. No IDA comments, renames, type edits, function promotions, patches, or saves were made.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: none. No by-memory documentation file was edited.

## 2026-06-11 Batch149 report

Leases used by A002:

- `by-type/by-vtable/FileStreamVtables.md`
- `by-type/by-vtable/ScreenEffecterVtableFamily.md`
- `by-type/by-vtable/-coverage-report.md`
- `by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md`
- `by-memory/0x00623480-0x00623d58.ScreenEffecterReadOnlyData.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Changed files:

- `by-type/by-vtable/FileStreamVtables.md`
- `by-type/by-vtable/ScreenEffecterVtableFamily.md`
- `by-type/by-vtable/-coverage-report.md`
- Validator-owned generated/index outputs were refreshed by scoped validator file scans, including `auto-generated/-ag-type-coverage.md` and validator/project stats state. No manual edits were made to generated/project-level/tool-state files.

Score changes:

- [UID:0001XK] `FileStreamVtables`: `78/88` -> `86/91`.
  Evidence added: live IDA MCP dword/value-name/xref refresh for `File`, `DATFile`, and `StdioFile` vtable records; exact backing memory children; slot target sizes; strict mixed-owner no-assignment rationale.
- [UID:0001YO] `ScreenEffecterVtableFamily`: `86/90` -> `88/92`.
  Evidence added: live IDA MCP dword/value-name/xref refresh, representative ScreenEffecter/PixelEffecter slot inventory, overlay/filter/water/lake xrefs, tiny/default slot target sizes, and boundary proof against `CAUST.EPF`/`ScrollPane`.

Assignment/blocker decisions:

- `FileStreamVtables` remains unassigned. It clears `85/85`, but it is a mixed aggregate spanning abstract `File`, archive `DATFile`, and util `StdioFile`; no single direct parent owns all three records under by-structure rules.
- `ScreenEffecterVtableFamily` was initially left unassigned because direct source parent candidate [UID:0000IZ] `Effects` was `88/80`, below the strict parent confidence gate. The 2026-06-11 continuation below refreshed `Effects` to `89/85` and assigned this vtable-family page to `0000IZ`.

Validation commands/results:

- `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-type\by-vtable\FileStreamVtables.md --apply`
  Result: `ok: 1`; completion/confidence updated to `86/91`; reference index added `00026L`, `0002UT`, `0002UV`; autogen reports no-op.
- `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-type\by-vtable\ScreenEffecterVtableFamily.md --apply`
  Result: `ok: 1`; completion/confidence updated to `88/92`; autogen reports no-op.
- `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-type\by-vtable\-coverage-report.md --apply`
  Result: `ok: 1`; by-vtable coverage rows validated; `auto-generated/-ag-type-coverage.md` updated by validator-owned autogen report refresh.

Supervisor-applied by-memory coverage-report rows:

- The supervisor applied and validated the Batch 216 `by-memory/-coverage-report.md` rows for [UID:00025J], [UID:00025K], [UID:0003BR], [UID:0003BS], [UID:0003BT], [UID:00025L], [UID:0003BU], [UID:0003BV], [UID:0003BW], and [UID:0003BX] on 2026-06-11.
- No Batch 216 by-memory coverage-report rows remain pending.text
    - [UID:00025J][0x0061c360-0x0061c5a0.IMEPaneReadOnlyData](by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md) 0x0061c360-0x0061c5a0 | vtable/string-data | IMEPaneReadOnlyData : reconstructable : 86% : strong : A002 Batch216 live IDA refresh reconfirmed 15 named items, four IME pane vtable families, constructor/destructor/scalar-delete store xrefs, decoded `Closed`/`IME`/`ENG` literals, and the `InputMan` successor boundary; assigned to [UID:0000K5][IMEPanes](by-file/IMEPanes.md) after child `86/91` and direct parent `89/86` cleared the strict gate.
    - [UID:00025K][0x0061c5a0-0x0061c7a4.InterfaceEfxReadOnlyData](by-memory/0x0061c5a0-0x0061c7a4.InterfaceEfxReadOnlyData.md) 0x0061c5a0-0x0061c7a4 | mixed-rdata index | InterfaceEfxReadOnlyData : ignored : 86% : strong : A002 Batch216 reclassified this as a non-emitting mixed map over `InputMan`, `InterfaceEfx`, `InterfaceEfxMgr`, and effect resource strings; live IDA confirmed locator/vtable boundaries, decoded `INTEFX.PAD`/effect EPD literals, representative store xrefs, and exact child routing.
        - [UID:0003BR][0x0061c5a0-0x0061c5b0.InputManVtableData](by-memory/0x0061c5a0-0x0061c5b0.InputManVtableData.md) 0x0061c5a0-0x0061c5b0 | vtable-data | InputManVtableData : reconstructable : 85% : strong : Exact `InputMan` RTTI locator plus three-slot primary vtable assigned to [UID:0000K6][InputMan](by-file/InputMan.md); live IDA confirms `0x0061c5a0 -> ??_R4InputMan@@6B@`, first slot `0x004e9660`, constructor/destructor/scalar-delete store xrefs, and the `InterfaceEfx` successor locator.
        - [UID:0003BS][0x0061c5b0-0x0061c6c0.InterfaceEfxVtableData](by-memory/0x0061c5b0-0x0061c6c0.InterfaceEfxVtableData.md) 0x0061c5b0-0x0061c6c0 | vtable-data | InterfaceEfxVtableData : reconstructable : 86% : strong : Exact `InterfaceEfx`/`InterfaceEfxMgr` locator and vtable island assigned to [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md); live IDA confirms all six table bases, locator cells, first-slot targets, constructor/destructor/EH store xrefs, and boundary before `INTEFX.PAD`.
        - [UID:0003BT][0x0061c6c0-0x0061c7a4.InterfaceEfxResourceStrings](by-memory/0x0061c6c0-0x0061c7a4.InterfaceEfxResourceStrings.md) 0x0061c6c0-0x0061c7a4 | string-data | InterfaceEfxResourceStrings : reconstructable : 85% : strong : Exact interface-effect resource literals assigned to [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md); live IDA decodes `INTEFX.PAD`, `CHREFX.EPD`, `MAGEFX.EPD`, `ITEMEFX.EPD`, `FRMLEFX.EPD`, and `FRMREFX.EPD`, with manager/spawner/resource-loader xrefs and the `InventoryPane` successor locator.
    - [UID:00025L][0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData](by-memory/0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData.md) 0x0061c7a4-0x0061c9c4 | mixed-rdata index | InventoryPaneReadOnlyData : ignored : 86% : strong : A002 Batch216 reclassified this as a non-emitting mixed map over legacy `InventoryPane`, `NewInventoryPane`, `InventoryPane2`, and mixed resource strings; live IDA confirmed locator-backed split starts, vtable store xrefs, decoded string start at `0x0061c8f8`, and the `KeySpeedMgr` successor boundary.
        - [UID:0003BU][0x0061c7a4-0x0061c7e0.InventoryPaneVtableData](by-memory/0x0061c7a4-0x0061c7e0.InventoryPaneVtableData.md) 0x0061c7a4-0x0061c7e0 | vtable-data | InventoryPaneVtableData : reconstructable : 86% : strong : Exact legacy `InventoryPane` RTTI/vtable data assigned to [UID:00006R][InventoryPane](by-class/InventoryPane.md); live IDA confirms primary/secondary locator cells, vtable bases, store/restore xrefs, and boundary before `NewInventoryPane`.
        - [UID:0003BV][0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData](by-memory/0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData.md) 0x0061c7e0-0x0061c86c | vtable-data | NewInventoryPaneVtableData : reconstructable : 86% : strong : Exact `NewInventoryPane` RTTI/vtable island assigned to [UID:000093][NewInventoryPane](by-class/NewInventoryPane.md); live IDA confirms locator cells, three table bases, store/restore xrefs, representative method anchors, one-caller scrollbar construction, and boundary before `InventoryPane2`.
        - [UID:0003BW][0x0061c86c-0x0061c8f8.InventoryPane2VtableData](by-memory/0x0061c86c-0x0061c8f8.InventoryPane2VtableData.md) 0x0061c86c-0x0061c8f8 | vtable-data | InventoryPane2VtableData : reconstructable : 85% : strong : Exact `InventoryPane2` RTTI/vtable island assigned to [UID:00006S][InventoryPane2](by-class/InventoryPane2.md); live IDA confirms raw-constructor vtable stores, setup/destructor store refs, modeled method anchors, and boundary before `ITEMINV.EPD`.
        - [UID:0003BX][0x0061c8f8-0x0061c9c4.InventoryResourceStrings](by-memory/0x0061c8f8-0x0061c9c4.InventoryResourceStrings.md) 0x0061c8f8-0x0061c9c4 | string-data | InventoryResourceStrings : ignored : 85% : strong : Mixed non-emitting inventory resource-string map; live IDA decodes `ITEMINV.EPD`, `INV.EPD`, `NPAL6.PAL`, `%c: `, `SPELLBUT.EPD`, `ITEMINV.EPF`, `ITEMINV.PAL`, `ITEMINVE.EPF`, `...(%d)`, and `INVENBUT.EPF`, with cross-class/resource-loader refs and no single direct parent.
```

Pending non-memory coverage-report rows:

- None. `by-file/-coverage-report.md` and `by-class/-coverage-report.md` were leased, updated directly for the four changed parent/class rows, and validated.

## 2026-06-11 Batch 222 - Patch/Power/PrettyButton/Prime/Pursuit read-only data

Assigned targets:

- [UID:000264] `by-memory/0x00621db8-0x00622034.PatchPaneReadOnlyData.md`
- [UID:000266] `by-memory/0x00622158-0x006222d8.PowerPaneReadOnlyData.md`
- [UID:000267] `by-memory/0x006222d8-0x006224c0.ButtonPrimePursuitReadOnlyData.md`

Leases used by A002:

- Assigned target docs, related predecessor/successor child docs, supporting file/class parents, `by-memory/-ignored.md`, `by-file/-coverage-report.md`, `by-class/-coverage-report.md`, and this `notes.md`.
- Created child pages after leasing the containing Power aggregate, then leased those new files before validator UID/header writes: [UID:0003CF], [UID:0003CG], and [UID:0003CH].

Changed files:

- `by-memory/0x00621db8-0x00622034.PatchPaneReadOnlyData.md`
- Renamed/updated `by-memory/0x00622034-0x00622158.PhotoPictureReadOnlyData.md` -> `by-memory/0x00622034-0x00622154.PhotoPictureReadOnlyData.md`
- Renamed/updated `by-memory/0x00622158-0x006222d8.PowerPaneReadOnlyData.md` -> `by-memory/0x00622154-0x006222d4.PowerPaneReadOnlyData.md`
- Created `by-memory/0x00622154-0x006221f0.PowerDialogPaneVtableData.md`
- Created `by-memory/0x006221f0-0x006222b4.PowerListPaneVtableData.md`
- Created `by-memory/0x006222b4-0x006222d4.PowerDialogResourceStrings.md`
- Renamed/updated `by-memory/0x006222d8-0x006224c0.ButtonPrimePursuitReadOnlyData.md` -> `by-memory/0x006222d4-0x006224c0.ButtonPrimePursuitReadOnlyData.md`
- Renamed/updated `by-memory/0x006222d8-0x00622378.PrettyButtonControlPaneVtableData.md` -> `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md`
- `by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md`
- `by-memory/0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData.md`
- `by-file/PowerDialogPane.md`
- `by-file/PrettyButtonControlPane.md`
- `by-class/PowerDialogPane.md`
- `by-class/PrettyButtonControlPane.md`
- `by-class/PrettyButtonControlPane2.md`
- `by-class/PursuitMessageDialogPane.md`
- `by-memory/-ignored.md`
- `by-file/-coverage-report.md`
- `by-class/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned generated/bookkeeping outputs were refreshed during scoped validation. No manual edits were made to `by-memory/-coverage-report.md`.

Score/parent/routing decisions:

- [UID:000264] `PatchPaneReadOnlyData`: stayed `86/92`, parent blank -> [UID:0000MH][PatchPane](by-file/PatchPane.md).
- [UID:000265] `PhotoPictureReadOnlyData`: stayed `82/88`, range corrected to `0x00622034-0x00622154` so it excludes the `PowerDialogPane` primary RTTI locator.
- [UID:000266] `PowerPaneReadOnlyData`: `80/88`, reconstructable true -> `86/91`, reconstructable false, parent blank. Reclassified as a non-emitting mixed map with exact children.
- [UID:0003CF] `PowerDialogPaneVtableData`: new child, `85/91`, parent [UID:0000AP][PowerDialogPane](by-class/PowerDialogPane.md).
- [UID:0003CG] `PowerListPaneVtableData`: new child, `85/91`, parent [UID:0000AQ][PowerListPane](by-class/PowerListPane.md).
- [UID:0003CH] `PowerDialogResourceStrings`: new child, `85/90`, parent [UID:0000AP][PowerDialogPane](by-class/PowerDialogPane.md).
- [UID:000267] `ButtonPrimePursuitReadOnlyData`: `82/90`, reconstructable true -> `86/91`, reconstructable false, parent blank. Range corrected to start at `0x006222d4` and reclassified as a non-emitting mixed map.
- [UID:0002UW] `PrettyButtonControlPaneVtableData`: range corrected to `0x006222d4-0x00622378`, parent [UID:0000MP] -> [UID:0000AR].
- [UID:0002UX] `PrettyButtonControlPane2VtableData`: parent [UID:0000MP] -> [UID:0000AS].
- [UID:0002OM] `PursuitMessageDialogPaneVtableData`: `84/89` -> `85/90`, parent [UID:0000LA] -> [UID:0000BE].
- [UID:0000MO] `PowerDialogPane` file: `88/80` -> `89/85`.
- [UID:0000AP] `PowerDialogPane` class: `86/82` -> `86/86`.
- [UID:0000AR] `PrettyButtonControlPane`: `76/84` -> `85/86`.
- [UID:0000AS] `PrettyButtonControlPane2`: `76/84` -> `85/86`.
- [UID:0000BE] `PursuitMessageDialogPane`: `80/82`, parent blank -> `85/86`, parent [UID:0000LA].

Evidence:

- Live IDA MCP confirmed the `.rdata` dword/name/xref layout from `0x00622150` through `0x006224c4`.
- Boundary repairs: `0x00622150` remains the last `PictureViewPane` slot, `0x00622154 -> ??_R4PowerDialogPane@@6B@`, `0x006222d4 -> ??_R4PrettyButtonControlPane@@6B@`, and `0x006224c0 -> ??_R4MessageDialog@@6B@`.
- Power data: live IDA confirmed PowerDialogPane table bases `0x00622158`, `0x006221b8`, `0x006221e8`; PowerListPane table bases `0x006221f4`, `0x0062227c`, `0x006222ac`; store xrefs to each base; and string xrefs for `Power` and `POWER.EPF`.
- Button/Prime/Pursuit data: live IDA confirmed PrettyButton, PrettyButton2, PrimeNumberGenerator, and PursuitMessageDialogPane RTTI/vtable boundaries, store xrefs, and the MessageDialog successor boundary.

Validation commands/results:

- `python source-3/project-documentation/tools/validator.py --mode file --file <new child> --apply` was run for the three new Power children to allocate UIDs [UID:0003CF]-[UID:0003CH], then again after metadata edits. Result: exit `0`, `ok: 1`.
- `python source-3/project-documentation/tools/validator.py --mode file --file <changed file> --apply` was run for every changed target, renamed predecessor/child, parent file/class doc, ignored ledger, and non-memory coverage report. Result: exit `0`, each scoped validation reported `ok: 1`.
- Known validation warnings after renames are from supervisor-owned `by-memory/-coverage-report.md` rows still referencing old paths until the pending block below is applied; unrelated stale missing-ref warnings for other batches also appeared and were not touched.

Supervisor-applied by-memory coverage-report rows:

- The supervisor applied and validated the Batch 222 `by-memory/-coverage-report.md` replacement block for [UID:000264], [UID:000265], [UID:000266], [UID:0003CF], [UID:0003CG], [UID:0003CH], [UID:000267], [UID:0002UW], [UID:0002UX], and [UID:0002OM] on 2026-06-11.
- No Batch 222 by-memory coverage-report rows remain pending.

Pending non-memory coverage-report rows:

- None. `by-file/-coverage-report.md` and `by-class/-coverage-report.md` were leased, updated directly for Batch222 parent rows, and validated.

## 2026-06-11 Batch 227 - UniAPI/UserList/UserPane read-only data

Assigned targets:

- [UID:00026S] `by-memory/0x0062e57c-0x0062e624.UniApiUrlAlertReadOnlyData.md`
- [UID:00026U] `by-memory/0x0062e8fc-0x0062eccc.UserListReadOnlyData.md`
- [UID:0002OX] `by-memory/0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData.md`
- [UID:00026W] `by-memory/0x0062ef0c-0x006307ec.UserPaneInputVtables.md`

Leases used by A002:

- Assigned target docs, exact child docs, newly created child docs, supporting class parents, `by-memory/-ignored.md`, `by-class/-coverage-report.md`, and this `notes.md`.
- Created child pages after leasing the containing aggregate parents, then leased those new files before validator UID/header writes: [UID:0003E5], [UID:0003E6], [UID:0003E7], [UID:0003E8], and [UID:0003E9].

Changed files:

- `by-memory/0x0062e57c-0x0062e624.UniApiUrlAlertReadOnlyData.md`
- `by-memory/0x0062e57c-0x0062e580.UniAPIInitVtableData.md`
- `by-memory/0x0062e580-0x0062e624.UrlAlertPaneVtableData.md`
- `by-memory/0x0062e8fc-0x0062eccc.UserListReadOnlyData.md`
- `by-memory/0x0062e8fc-0x0062e998.UserListDialogPaneVtableData.md`
- `by-memory/0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData.md`
- `by-memory/0x0062ea3c-0x0062eadc.PartySearchEditPaneVtableData.md`
- `by-memory/0x0062eadc-0x0062eb9c.UserListPaneVtableData.md`
- `by-memory/0x0062eb9c-0x0062eccc.UserListResourceStrings.md`
- `by-memory/0x0062ef0c-0x006307ec.UserPaneInputVtables.md`
- `by-memory/-ignored.md`
- `by-class/UniAPIInit.md`
- `by-class/UserListDialogPane.md`
- `by-class/PartySearchEditPane.md`
- `by-class/UserListPane.md`
- `by-class/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/parent/routing decisions:

- [UID:00026S] `UniApiUrlAlertReadOnlyData`: `85/92`, reconstructable true -> `86/92`, reconstructable false, parent blank. Reclassified as non-emitting mixed map.
- [UID:0003E5] `UniAPIInitVtableData`: new child, `85/91`, parent [UID:0000FE].
- [UID:0002P0] `UrlAlertPaneVtableData`: `84/90` -> `85/91`, parent remains [UID:0000FF].
- [UID:00026U] `UserListReadOnlyData`: `86/92`, reconstructable true -> `88/92`, reconstructable false, parent blank. Reclassified as non-emitting mixed map with exact children for all subranges.
- [UID:0003E6] `UserListDialogPaneVtableLeadInData`: new child, `85/90`, parent [UID:0000FN].
- [UID:0002OX] `CheckBoxTextControlPaneVtableData`: `85/91`, parent blank -> `86/92`, parent [UID:000022].
- [UID:0003E7] `PartySearchEditPaneVtableData`: new child, `85/91`, parent [UID:0000A7].
- [UID:0003E8] `UserListPaneVtableData`: new child, `85/90`, parent [UID:0000FO].
- [UID:0003E9] `UserListResourceStrings`: new child, `85/90`, parent [UID:0000OZ].
- [UID:00026W] `UserPaneInputVtables`: `87/91`, reconstructable true -> `88/92`, reconstructable false, parent blank. Reclassified as non-emitting mixed vtable map; exact child split remains incomplete for spell/social/item/equipment prompt clusters.
- [UID:0000FE] `UniAPIInit`: `88/82` -> `88/85`.
- [UID:0000FN] `UserListDialogPane`: `84/84` -> `85/85`.
- [UID:0000A7] `PartySearchEditPane`: `84/88` -> `85/89`.
- [UID:0000FO] `UserListPane`: `84/86` -> `85/87`.

Validation commands/results:

- `python source-3/project-documentation/tools/validator.py --mode file --file <new child> --apply` was run for the five new child files to allocate UIDs [UID:0003E5]-[UID:0003E9].
- `python source-3/project-documentation/tools/validator.py --mode file --file <changed file> --apply` was run for every changed target, child, class parent, ignored ledger, and by-class coverage report. Result: each scoped validation reported `ok: 1`.
- Validator-owned generated/bookkeeping outputs were refreshed during scoped validation. No manual edits were made to `by-memory/-coverage-report.md`.

Supervisor-applied `by-memory/-coverage-report.md` rows:

- The supervisor applied and validated the Batch 227 `by-memory/-coverage-report.md` replacement/insert rows for [UID:00026S], [UID:0003E5], [UID:0002P0], [UID:00026U], [UID:0003E6], [UID:0002OX], [UID:0003E7], [UID:0003E8], [UID:0003E9], and [UID:00026W] on 2026-06-11.
- No Batch 227 by-memory coverage-report rows remain pending.

## 2026-06-11 Batch 233 - Object-pane pool/static-storage documentation

Assigned targets:

- [UID:0002WL] `by-memory/0x0069b894-0x0069b8bc.LivingObjectPanePoolStaticStorage.md`
- [UID:0002WM] `by-memory/0x0069b8bc-0x0069b8e4.StaticObjectPanePoolStaticStorage.md`
- [UID:0002WN] `by-memory/0x0069b8e4-0x0069b90c.SoundObjectPanePoolStaticStorage.md`
- [UID:0002WO] `by-memory/0x0069b90c-0x0069b934.EffectObjectPanePoolStaticStorage.md`
- [UID:0002WP] `by-memory/0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage.md`
- [UID:0002WQ] `by-memory/0x0069b95c-0x0069b984.DamageNumberObjectPanePoolStaticStorage.md`

Leases used by A002:

- Six assigned pool/static-storage target docs, [UID:000049] `EffectObjectPane`, [UID:000382] `EffectObjectPaneScalarDeletingDestructor`, [UID:000351] `EffectObjectPaneVtableData`, [UID:000260] `ObjectPaneReadOnlyData`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, and this `notes.md`.

Changed files:

- `by-memory/0x0069b894-0x0069b8bc.LivingObjectPanePoolStaticStorage.md`
- `by-memory/0x0069b8bc-0x0069b8e4.StaticObjectPanePoolStaticStorage.md`
- `by-memory/0x0069b8e4-0x0069b90c.SoundObjectPanePoolStaticStorage.md`
- `by-memory/0x0069b90c-0x0069b934.EffectObjectPanePoolStaticStorage.md`
- `by-memory/0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage.md`
- `by-memory/0x0069b95c-0x0069b984.DamageNumberObjectPanePoolStaticStorage.md`
- `by-class/EffectObjectPane.md`
- `by-memory/0x0053d100-0x0053d197.EffectObjectPaneScalarDeletingDestructor.md`
- `by-memory/0x006205f8-0x006206ac.EffectObjectPaneVtableData.md`
- `by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md`
- `by-class/-coverage-report.md`
- `by-file/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/parent/routing decisions:

- [UID:0002WL] `LivingObjectPanePoolStaticStorage`: `82/90`, parent blank -> `85/91`, parent [UID:00007B].
- [UID:0002WM] `StaticObjectPanePoolStaticStorage`: `82/90`, parent blank -> `85/91`, parent [UID:0000E1].
- [UID:0002WN] `SoundObjectPanePoolStaticStorage`: `82/90`, parent blank -> `85/91`, parent [UID:0000DH].
- [UID:0002WO] `EffectObjectPanePoolStaticStorage`: `82/90`, parent blank -> `85/91`, parent [UID:000049].
- [UID:0002WP] `HitBarObjectPanePoolStaticStorage`: `82/90`, parent blank -> `85/91`, parent [UID:000067].
- [UID:0002WQ] `DamageNumberObjectPanePoolStaticStorage`: `82/90`, parent blank -> `85/91`, parent [UID:00003F].
- [UID:000049] `EffectObjectPane`: `80/84` -> `85/86`, parent remains [UID:0000IZ]. This repaired the direct-parent gate for Effect pool/vtable/destructor children.
- [UID:000382] `EffectObjectPaneScalarDeletingDestructor`: stayed `88/92`, parent blank -> [UID:000049].
- [UID:000351] `EffectObjectPaneVtableData`: stayed `85/88`, parent blank -> [UID:000049].
- `by-class/-coverage-report.md`: repaired stale rows for `EffectObjectPane`, `SoundObjectPane`, and `StaticObjectPane`.
- `by-file/-coverage-report.md`: repaired stale rows for `SoundObjectPane` and `StaticObjectPane`.

Evidence:

- Live IDA MCP `py_eval` reconfirmed all six pool storage blocks as exact `0x28` / `40` byte static items with all bytes initialized as `0xff`, the expected constructor and cleanup wrapper bounds, and direct startup/allocation/unwind/destructor/cleanup xrefs.
- `int_convert.py` verified all added size, block-size, and chunk-count base conversions.
- The same IDA pass reconfirmed the `EffectObjectPane` constructor, non-deleting destructor, timer helper, virtual methods, scalar deleting destructor, adjustor thunks, vtable xref triples, and static pool xrefs used to raise the class parent to `85/86`.

Validation commands/results:

- `python source-3/project-documentation/tools/validator.py --mode file --file <changed by-* file> --apply` was run for every changed by-memory/by-class/by-file doc listed above. Result: exit `0`; each scoped validation reported `ok: 1`.
- Validator-owned generated/autogen/bookkeeping outputs were refreshed during scoped validation. No manual edits were made to `by-memory/-coverage-report.md`.

Supervisor-applied `by-memory/-coverage-report.md` rows:

- The supervisor applied and validated the Batch 233 `by-memory/-coverage-report.md` replacement rows for [UID:000382], [UID:000351], and [UID:0002WL]-[UID:0002WQ] on 2026-06-11.
- No Batch 233 by-memory coverage-report rows remain pending.

## 2026-06-11 Batch 238 - reviewed-no-85 follow-up

Assigned targets:

- [UID:000086] `by-class/MessageDialogLarger.md`
- [UID:00026C] `by-memory/0x00623480-0x00623d58.ScreenEffecterReadOnlyData.md`

Leases used by A002:

- `by-class/MessageDialogLarger.md`
- `by-memory/0x00623480-0x00623d58.ScreenEffecterReadOnlyData.md`
- Created after leasing the containing aggregate, then leased before validator UID/header writes: [UID:0003EF] `by-memory/0x00623480-0x00623508.ScreenDimmerVtableData.md`, [UID:0003EG] `by-memory/0x00623508-0x006235a0.ScreenFadeOutVtableData.md`, and [UID:0003EH] `by-memory/0x00623d18-0x00623d58.ScreenEffecterResourceStringsAndConstants.md`.
- `tools/leaser/Agents/Agent-A002/notes.md`

Changed files:

- `by-class/MessageDialogLarger.md`
- `by-memory/0x00623480-0x00623d58.ScreenEffecterReadOnlyData.md`
- `by-memory/0x00623480-0x00623508.ScreenDimmerVtableData.md`
- `by-memory/0x00623508-0x006235a0.ScreenFadeOutVtableData.md`
- `by-memory/0x00623d18-0x00623d58.ScreenEffecterResourceStringsAndConstants.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/parent/routing decisions:

- [UID:000086] `MessageDialogLarger`: stayed `82/85`, parent blank. Batch 238 added exact remaining blockers: class still lacks a method-level constructor/action pass for packet field offsets, large-layout controls/resources, vtable-store details in the class page, and command-id semantics. Direct parent [UID:0000LA] is `89/85`, and exact vtable child [UID:0003D2] is `86/91`, but the child class itself still fails the completion side of the strict gate.
- [UID:00026C] `ScreenEffecterReadOnlyData`: `82/90`, reconstructable true -> `87/92`, reconstructable false, parent blank. Reclassified as non-emitting mixed `.rdata` index over exact children.
- [UID:0003EF] `ScreenDimmerVtableData`: new exact child, `85/91`, parent [UID:0000C8].
- [UID:0003EG] `ScreenFadeOutVtableData`: new exact child, `85/91`, parent [UID:0000CA].
- [UID:0003EH] `ScreenEffecterResourceStringsAndConstants`: new exact child, `85/90`, parent [UID:0000IZ].

Validation commands/results:

- `python source-3/project-documentation/tools/validator.py --mode file --file <new child> --apply` was run for the three new child pages to allocate UIDs [UID:0003EF]-[UID:0003EH].
- `python source-3/project-documentation/tools/validator.py --mode file --file <changed by-* file> --apply` was run for `MessageDialogLarger`, the three new children, and the broad `ScreenEffecterReadOnlyData` aggregate. Filtered rerun result: each file reported `ok: 1`.
- Validator-owned generated/autogen/bookkeeping outputs were refreshed during scoped validation. No manual edits were made to `by-memory/-coverage-report.md`.

Supervisor-applied `by-memory/-coverage-report.md` rows:

- The supervisor applied and validated the Batch 238 `by-memory/-coverage-report.md` replacement block for [UID:00026C], [UID:0003EF], [UID:0003EG], [UID:0002OR], and [UID:0003EH] on 2026-06-11.
- No Batch 238 by-memory coverage-report rows remain pending.

## 2026-06-12 Batch 241 - Shared helpers and Surface paint helpers

Assigned targets:

- [UID:000342] `by-memory/0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper.md`
- [UID:00034G] `by-memory/0x004b5760-0x004b57dd.SharedSimpleStringEntryVectorDestructor.md`
- [UID:000165] `by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md`
- [UID:00035C] `by-memory/0x004b99c0-0x004b99ee.SurfacePaletteCallbackForwarderRaw.md`

Leases used by A002:

- Four assigned target docs and this `notes.md`.

Changed files:

- `by-memory/0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper.md`
- `by-memory/0x004b5760-0x004b57dd.SharedSimpleStringEntryVectorDestructor.md`
- `by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md`
- `by-memory/0x004b99c0-0x004b99ee.SurfacePaletteCallbackForwarderRaw.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated refreshes from scoped validation: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, and `tools/validator.ini`.

Score/parent/routing decisions:

- [UID:000342] `SharedReturnTrueVirtualHelper`: `85/87` -> `86/88`, parent remains blank. Live IDA confirms a `0x5`-byte `mov al, 1; retn 4` helper and seven vtable/data refs across ExchangeMoneyEditControlPane, MapRefreshDimmer, ScreenDimmer, and InputBlockerPane; ControlPane is still below gate and Pane is too broad without slot proof.
- [UID:00034G] `SharedSimpleStringEntryVectorDestructor`: `86/88` -> `87/89`, parent remains blank. Live IDA confirms exact `0x7d` body, 12-byte record stride, two entry refs (`0x0057382c` ordinary SpelledPane-side call and `0x005fea1d` FolderTree EH cleanup jump), and no pointer-literal matches. VectorHelpers, StringUtil, and FolderTreePaneVectorSupportHelpers were checked but not accepted as direct parents.
- [UID:000165] `SurfacePaintHelpers`: `84/86`, parent blank -> `86/88`, parent [UID:0000OC][Surface]. Child and direct file parent now clear `85/85`; live IDA confirms modeled helper sizes, broad caller counts, callback dispatches, and caller-biased feature labels.
- [UID:00035C] `SurfacePaletteCallbackForwarderRaw`: `82/86`, parent blank -> `85/88`, parent [UID:0000OC][Surface]. Live IDA confirms no modeled function and no direct entry refs, but exact raw code, neighboring padding, `dword_67A7E0`/`sub_543D70` palette lookup, and `dword_69B3EC` callback-table dispatch support Surface ownership. Raw-entry liveness remains the final-name/C++ blocker.

Validation commands/results:

- `python source-3/project-documentation/tools/validator.py --mode file --file <target> --apply` was run for all four changed by-memory files. Result: loop exited `0`; scoped validator output reported `ok: 1` for each file and updated target scores/parents. Validator-owned generated/bookkeeping outputs were refreshed. No manual edits were made to `by-memory/-coverage-report.md`.

Supervisor-applied `by-memory/-coverage-report.md` rows:

- The supervisor applied and validated the Batch 241 insert/replacement rows for [UID:000342], [UID:00034G], [UID:000165], and [UID:00035C].
- No Batch 241 coverage-report rows remain pending.

Blockers/follow-up:

- `SharedReturnTrueVirtualHelper` still needs a broader pane/control vtable-slot pass before it can be assigned.
- `SharedSimpleStringEntryVectorDestructor` needs a proven 12-byte shared string-entry vector parent or a refreshed nearby vector-support parent before assignment.

## 2026-06-12 Batch 246 - SelfLookPane raw helper follow-up

Assigned targets:

- [UID:0002RA] `by-memory/0x0056a380-0x0056a4f4.SelfLookPanePacketSendRawHelpers.md`
- [UID:0002RB] `by-memory/0x0056a500-0x0056a63e.SelfLookPaneRectUpdateRawHelpers.md`
- [UID:0002RD] `by-memory/0x0056b5c0-0x0056b7c0.SelfLookPaneClearSlotSwitchRaw.md`
- [UID:0002RG] `by-memory/0x0056b9f0-0x0056ba99.SelfLookPaneViewToggleRaw.md`

Leases used by A002:

- Four assigned target docs and this `notes.md`.

Changed files:

- `by-memory/0x0056a380-0x0056a4f4.SelfLookPanePacketSendRawHelpers.md`
- `by-memory/0x0056a500-0x0056a63e.SelfLookPaneRectUpdateRawHelpers.md`
- `by-memory/0x0056b5c0-0x0056b7c0.SelfLookPaneClearSlotSwitchRaw.md`
- `by-memory/0x0056b9f0-0x0056ba99.SelfLookPaneViewToggleRaw.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated refreshes from scoped validation: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, and `tools/validator.ini`.

Score/parent/routing decisions:

- [UID:0002RA] `SelfLookPanePacketSendRawHelpers`: `82/88`, parent blank -> `85/89`, parent [UID:0000CU][SelfLookPane].
- [UID:0002RB] `SelfLookPaneRectUpdateRawHelpers`: `82/88`, parent blank -> `85/89`, parent [UID:0000CU][SelfLookPane].
- [UID:0002RD] `SelfLookPaneClearSlotSwitchRaw`: `84/88`, parent blank -> `85/89`, parent [UID:0000CU][SelfLookPane].
- [UID:0002RG] `SelfLookPaneViewToggleRaw`: `84/88`, parent blank -> `85/89`, parent [UID:0000CU][SelfLookPane].
- Direct parent gate: [UID:0000CU][SelfLookPane] is currently `85/88`, and [UID:0000NL][SelfLookPane] is `85/89`, so the four child assignments satisfy the strict child/direct-parent `85/85` gate.
- Structure decision: no split/rename needed. All four ranges are exact raw helper children in the existing `0x0056a380-0x0056ba99` helper island; unresolved direct raw-start liveness remains documented as a naming/final-C++ blocker, not an ownership blocker.

Evidence:

- Live IDA MCP `lookup_funcs`/`py_eval` reconfirmed no modeled functions and no direct raw-start xrefs for `0x0056a380`, `0x0056a400`, `0x0056a480`, `0x0056a500`, `0x0056a5c0`, `0x0056b5c0`, and `0x0056b9f0`.
- Packet-send raw helpers now include same-family confirmation from modeled/raw `SelfLookPane` toggle/input code: `0x00567000` sends subtype `0x02`, `0x00566f40` sends subtype `0x08`, raw `0x005670c0` sends subtype `0x0b`, and `0x00568cb0` emits the `0x02`/`0x08` variants from the mouse handler.
- Rect-update and clear-slot raw helpers now include modeled `0x005693d0` packet/event handler mirrors for packet cases `0x33`, `0x1d`, and `0x38`, confirming packet offsets, `dword_67A748+0xfc`, decoder choices, slot-field writes, and redraw virtual calls.
- View-toggle raw helper now includes nearby view-method corroboration: `0x00567200`, `0x00567280`, and `0x00567380` write `this+0x2328` modes `0`, `1`, and `2` and refresh the same `SpelledPane`/`LegendPane` children and `dword_69B368` layer context used by the raw helper.

Validation commands/results:

- `python source-3/project-documentation/tools/validator.py --mode file --file <target> --apply` was run for all four changed by-memory files. Result: loop exited `0`; scoped validator output reported `ok: 1`, updated completion/confidence, updated `AUTOGEN_PARENT_UID` to `0000CU`, and refreshed validator-owned generated/bookkeeping outputs. No manual edits were made to `by-memory/-coverage-report.md`.

Supervisor-applied `by-memory/-coverage-report.md` rows:

- The supervisor applied and validated the Batch 246 replacement rows for [UID:0002RA], [UID:0002RB], [UID:0002RD], and [UID:0002RG] on 2026-06-12.
- No Batch 246 by-memory coverage-report rows remain pending.

Blockers/follow-up:

- Raw-start callback/liveness proof remains unresolved for all four helpers; future work should search callback tables or indirect registration paths if final source names are needed.
- The broader [UID:00023V] helper-island aggregate remains below `85/85` and could be refreshed after the remaining children [UID:0002RC], [UID:0002RE], and [UID:0002RF] are improved.

## 2026-06-12 Batch 251 - CheckBoxTextControlPane executable split

Assigned target:

- [UID:0001KJ] `by-memory/0x0059ded0-0x0059f0a4.CheckBoxTextControlPane.md`

Leases used by A002:

- Existing/containing docs: `by-memory/0x0059ded0-0x0059f0a4.CheckBoxTextControlPane.md` before rename, `by-memory/0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap.md` after rename, `by-class/CheckBoxTextControlPane.md`, `by-file/SpecializedButtonPanes.md`, `by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md`, `by-memory/-ignored.md`, and this `notes.md`.
- Created child pages after leasing the containing/parent map, then leased the new children before validator UID/header writes: [UID:0003FE]-[UID:0003FJ].

Changed files:

- Renamed/updated `by-memory/0x0059ded0-0x0059f0a4.CheckBoxTextControlPane.md` -> `by-memory/0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap.md`
- Created `by-memory/0x0059ded0-0x0059df27.CheckBoxTextControlPaneConstructorRaw.md`
- Created `by-memory/0x0059df30-0x0059df4f.CheckBoxTextControlPaneTeardownHelper.md`
- Created `by-memory/0x0059df50-0x0059e0ac.CheckBoxTextControlPaneOnPaint.md`
- Created `by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md`
- Created `by-memory/0x0059e0c0-0x0059e0c7.CheckBoxTextControlPaneGetChecked.md`
- Created `by-memory/0x0059f050-0x0059f0a5.CheckBoxTextControlPaneScalarDeletingDestructor.md`
- `by-class/CheckBoxTextControlPane.md`
- `by-file/SpecializedButtonPanes.md`
- `by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md`
- `by-memory/-ignored.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated refreshes from scoped validation: `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-class-coverage.md`, `project-level/-auto-completion-stats.md`, and validator registry/bookkeeping. Validator also normalized reverse UID path annotations for [UID:0001KJ].

Score/parent/routing decisions:

- [UID:0001KJ] broad target: `78/82`, reconstructable true, old path `0x0059ded0-0x0059f0a4.CheckBoxTextControlPane.md`, parent blank -> `88/89`, reconstructable false, renamed to `0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap.md`, parent blank. Reclassified as non-emitting sparse map because the range crosses checkbox, party-search, user-list, singleton-clear helper, compiler thunk, and padding ownership.
- [UID:0003FE] `CheckBoxTextControlPaneConstructorRaw`: new exact child, `85/88`, parent [UID:000022][CheckBoxTextControlPane].
- [UID:0003FF] `CheckBoxTextControlPaneTeardownHelper`: new exact child, `86/90`, parent [UID:000022][CheckBoxTextControlPane].
- [UID:0003FG] `CheckBoxTextControlPaneOnPaint`: new exact child, `87/91`, parent [UID:000022][CheckBoxTextControlPane].
- [UID:0003FH] `CheckBoxTextControlPaneSetCheckedRaw`: new exact child, `85/86`, parent [UID:000022][CheckBoxTextControlPane].
- [UID:0003FI] `CheckBoxTextControlPaneGetChecked`: new exact child, `86/88`, parent [UID:000022][CheckBoxTextControlPane].
- [UID:0003FJ] `CheckBoxTextControlPaneScalarDeletingDestructor`: new exact child, `87/91`, parent [UID:000022][CheckBoxTextControlPane].
- Direct parent gate: [UID:000022][CheckBoxTextControlPane] is `85/87` and [UID:0000NY][SpecializedButtonPanes] is `85/86`, so all six exact children clear the strict child/direct-parent `85/85` gate. The broad map remains parentless by by-structure.

Evidence:

- Live IDA MCP `lookup_funcs`/`decompile`/`py_eval` verified the real modeled starts at `0x0059df30`, `0x0059df50`, `0x0059e0c0`, `0x0059efeb`, `0x0059eff6`, `0x0059f001`, `0x0059f050`, and `0x0059e0d0`; `0x0059ded0` and `0x0059e0b0` remain raw/non-modeled starts.
- Corrected boundaries: raw constructor ends at `0x0059df27` because `retn 0Ch` at `0x0059df24` is three bytes; old target end corrected to `0x0059f0a5` to include the full scalar deleting destructor.
- Newly recognized child: `0x0059e0b0-0x0059e0c0` is a raw checked-state setter, not padding; it writes `this+0x108` and returns with `retn 4`.
- Ownership: constructor, teardown helper, paint, setter/getter, and scalar deleting destructor all tie to `CheckBoxTextControlPane` via field offsets, vtable stores/slots, PartySearch inline setup, and [UID:0002OX] vtable data. Middle PartySearch/UserList spans and `sub_59EFE0` remain social/user-list neighborhood code.

Validation commands/results:

- `python source-3/project-documentation/tools/validator.py --mode file --file <new child> --apply` was run for the six new children to allocate UIDs [UID:0003FE]-[UID:0003FJ].
- `python source-3/project-documentation/tools/validator.py --mode file --file by-memory/0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap.md --apply` updated [UID:0001KJ] path metadata from the old nonexistent file to the corrected map path and changed reconstructable true -> false. Result: `ok: 1`.
- `python source-3/project-documentation/tools/validator.py --mode file --file <changed by-* file> --apply` was run for all six children, the class page, file page, surrounding aggregate, and ignored ledger. Result: each scoped validation reported `ok: 1`.

Supervisor-applied `by-memory/-coverage-report.md` replacement:

- The supervisor applied and validated the Batch 251 replacement block for [UID:0001KJ], exact children [UID:0003FE]-[UID:0003FJ], and the compiler-thunk ignored row on 2026-06-12.
- No Batch 251 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

Blockers/follow-up:

- No Batch251 blocker remains for exact checkbox children. Future work can split/document the foreign `0x0059e0d0-0x0059efe0` and `0x0059f001-0x0059f050` subspans into exact social/user-list children if assigned.
- Final C++ remains blank for all Batch251 pages because raw-entry liveness, inherited layout names, render helper names, and class declarations are below the 95/95 reconstruction-code gate.

## 2026-06-12 Batch 257 - NexonclubRegistrationDialog read-only data

Assigned target:

- [UID:0003C7] `by-memory/0x006200a8-0x0062018c.NexonclubRegistrationVtableData.md`

Leases used by A002:

- `by-memory/0x006200a8-0x0062018c.NexonclubRegistrationVtableData.md` before rename.
- `by-memory/0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData.md` after rename.
- `by-class/NexonclubRegistrationDialog.md`
- `by-file/NexonclubRegistrationDialog.md`
- `by-memory/0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Changed files:

- Renamed/updated `by-memory/0x006200a8-0x0062018c.NexonclubRegistrationVtableData.md` -> `by-memory/0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData.md`
- `by-class/NexonclubRegistrationDialog.md`
- `by-file/NexonclubRegistrationDialog.md`
- `by-memory/0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated refreshes from scoped validation included `auto-generated/-ag-*`, `project-level/-auto-completion-stats.md`, validator registry/bookkeeping, and UID path normalization in `by-memory/-coverage-report.md`.

Score/parent/routing decisions:

- [UID:0003C7] target: `86/90`, unassigned, stale path/range `0x006200a8-0x0062018c.NexonclubRegistrationVtableData` -> `88/92`, parent [UID:00009I][NexonclubRegistrationDialog](by-class/NexonclubRegistrationDialog.md), corrected path/range `0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData`.
- [UID:00009I] class parent: `82/80` -> `86/86`, parent remains [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md).
- [UID:0000M0] file parent: `86/80` -> `87/86`, projected path remains `NexusTK/ui/dialogs/`.
- [UID:00025Z] containing aggregate remains `86/91`, `RECONSTRUCTABLE:FALSE`, parent blank because the aggregate crosses create-user, registration, NumberInput, callback, resource, and URL ownership.
- Gate decision: [UID:0003C7] and its direct class parent [UID:00009I] both clear strict `85/85`; the class and its direct file parent [UID:0000M0] also clear strict `85/85`, so routing to the class is justified.

Evidence:

- Live IDA MCP `lookup_funcs` on 2026-06-12 reconfirmed the registration executable island: constructor `0x0052f950-0x0052ff9b`, destructor `0x0052ffa0-0x00530015`, command handler `0x00530060-0x0053022b`, response handler `0x00530230-0x005303ef`, status helper `0x00530410-0x005304b4`, adjustor thunks `0x00530565-0x00530570` and `0x00530570-0x0053057b`, scalar deleting destructor `0x00530580-0x00530636`, and `NumberInputDialog` successor at `0x00530640`.
- Live IDA MCP `xrefs_to` confirmed primary/secondary/tertiary vtable base refs from the constructor, destructor, and scalar deleting destructor; `OnCommand` callback-object vtable ref at `0x00530189`; member-function pointer assignment to `0x00530020` at `0x0053018f`; URL literal ref at `0x005300a4`; and constructor refs to `DLGNC.PAL`, `DLGNC.EPF`, and `DLGNC.EPD`.
- Live IDA MCP `py_eval` showed the old `0x0062018c` endpoint was too short: the `PlainMemberFunctionObject` vtable includes entries at `0x00620184`, `0x00620188`, `0x0062018c`, `0x00620190`, and `0x00620194`; the URL literal begins at `0x00620198`.

Validation commands/results:

- `python source-3/project-documentation/tools/validator.py --mode file --file <edited by-* file> --apply` was run for the corrected target, class parent, file parent, and containing aggregate.
- Result: loop exited `0`; scoped validator output reported `ok: 1` for each validation. For [UID:0003C7], validator reported `path_update`, `completion_update 88`, `confidence_update 92`, and `autogen_registry_update -> 00009I`.
- No manual edits were made to `by-memory/-coverage-report.md`; validator normalized the UID path there, but the row text remains stale and needs supervisor replacement below.

Supervisor-applied report rows:

- The supervisor applied and validated the Batch 257 `by-memory/-coverage-report.md` replacement rows for [UID:00025Z] and [UID:0003C7] on 2026-06-12.
- The supervisor applied and validated the Batch 257 `by-class/-coverage-report.md` row for [UID:00009I] on 2026-06-12.
- The supervisor applied and validated the Batch 257 `by-file/-coverage-report.md` row for [UID:0000M0] on 2026-06-12.
- No Batch 257 supervisor-owned report rows remain pending.

Blockers/follow-up:

- No blocker remains for [UID:0003C7]. It now routes to the class parent under the strict `85/85` gate.
- Related [UID:0003C8] `NumberInputDialogVtableData` was repaired separately by A004 Batch 258 and no longer blocks this aggregate wording.

## 2026-06-12 Batch 263 - Reconnect/Terminal/Copy string-tail split

Assigned target:

- [UID:0003CW] `by-memory/0x00622f1c-0x00622f54.ReconnectCopyWindowStrings.md`

Leases used by A002:

- Existing files leased before edits: `by-memory/0x00622f1c-0x00622f54.ReconnectCopyWindowStrings.md`, `by-memory/0x00622d24-0x00622f54.QueueReconnectCopyReadOnlyData.md`, `by-class/CopyWindow.md`, `by-file/TerminalPane.md`, `by-class/TerminalPane.md`, and this `notes.md`.
- New files created after leasing the existing containing item, then leased before validator header writes: [UID:0003G3]-[UID:0003G7].
- The first A002 leases expired before final notes were written; current active notes lease was reacquired for this report.

Changed files:

- Renamed/updated `by-memory/0x00622f1c-0x00622f54.ReconnectCopyWindowStrings.md` -> `by-memory/0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap.md`
- Created `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md`
- Created `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md`
- Created `by-memory/0x00622f3c-0x00622f44.CopyWindowNoButtonWideString.md`
- Created `by-memory/0x00622f44-0x00622f4c.CopyWindowYesButtonWideString.md`
- Created `by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md`
- `by-memory/0x00622d24-0x00622f54.QueueReconnectCopyReadOnlyData.md`
- `by-class/CopyWindow.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated outputs were refreshed during scoped validation, including `auto-generated/-ag-memory-coverage.md`. No manual edit was made to `by-memory/-coverage-report.md`; validator reference cleanup normalized the UID path for [UID:0003CW], but the row text remains supervisor-owned and stale until the pending block below is applied.

Score/parent/routing decisions:

- [UID:0003CW] target: `86/91`, `RECONSTRUCTABLE:TRUE`, parent blank, stale name `ReconnectCopyWindowStrings` -> `89/93`, `RECONSTRUCTABLE:FALSE`, parent blank, renamed `ReconnectTerminalCopyStringTailMap`.
- [UID:0003G3] `SharedLeaveWideString`: new exact child, `86/91`, parent blank. `Leave` is shared by reconnect/connection-closed dialog constructors, `ReconnectDialog::OnButtonClick`, and `TerminalPane::OnDisconnect`.
- [UID:0003G4] `SharedReconnectWideString`: new exact child, `86/91`, parent blank. `Reconnect` is shared by the same reconnect-dialog and TerminalPane use sites.
- [UID:0003G5] `CopyWindowNoButtonWideString`: new exact child, `86/91`, parent [UID:000039][CopyWindow](by-class/CopyWindow.md). The child and direct class parent `85/86` clear the strict gate.
- [UID:0003G6] `CopyWindowYesButtonWideString`: new exact child, `86/91`, parent [UID:000039][CopyWindow](by-class/CopyWindow.md). The child and direct class parent `85/86` clear the strict gate.
- [UID:0003G7] `SharedBaramPacketLiteral`: new exact child, `86/91`, parent blank. `baram` is shared by `ReconnectDialog::OnButtonClick` and the `TerminalPane` stream parser.
- [UID:000269] containing aggregate: `87/93` -> `88/94`, parent blank, still non-emitting. The final string tail now has exact children and corrected TerminalPane wording.
- [UID:000039] `CopyWindow` class: score unchanged at `85/86`; added exact button-label child references to support [UID:0003G5]/[UID:0003G6].
- Checked [UID:0000OI]/[UID:0000EG] `TerminalPane`; no parent repair was needed because the shared reconnect/terminal strings remain parentless due mixed ownership, not only because TerminalPane file/class docs are below 85 confidence.

Evidence:

- Live IDA MCP byte/xref pass on `0x00622f1c-0x00622f54` decoded UTF-16LE `Leave`, UTF-16LE `Reconnect`, UTF-16LE `No`, UTF-16LE `Yes`, and ANSI `baram`; `off_622F1C`, `off_622F28`, and `off_622F44` are false pointer interpretations of UTF-16 bytes.
- `Leave`/`Reconnect` refs: `0x00553c3f/0x00553c44`, `0x00553cef/0x00553cf4`, `0x00554359/0x0055435e`, and `0x0058b5ac/0x0058b5b1`.
- `No`/`Yes` refs: `0x00553ebb/0x00553ec0` inside the reconnect helper's inline `CopyWindow` construction and `0x005544c5/0x005544ca` inside the raw `CopyWindow` constructor.
- `baram` refs: `0x00554276` inside `ReconnectDialog::OnButtonClick` and `0x0058b3fc` inside [UID:0001JC][0x0058b130-0x0058b44b.TerminalPaneStreamParser](by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md).
- The older "startup-window" wording was corrected: lookup/local docs identify `0x0058b130` and `0x0058b470` as `TerminalPane` functions, not `StartupWindow`.
- `int_convert.py` verified sizes `0x0c` / 12, `0x14` / 20, `0x08` / 8, `0x10` / 16, and `0x38` / 56 where documented.

Validation commands/results:

- Initial UID/header allocation: `python source-3/project-documentation/tools/validator.py --mode file --file <new-child> --apply` for the five new child files. Result: exit `0`; assigned [UID:0003G3]-[UID:0003G7].
- Scoped validation after edits: `python source-3/project-documentation/tools/validator.py --mode file --file <edited-file> --apply` for all five children, the renamed [UID:0003CW] map, [UID:000269] aggregate, and [UID:000039] CopyWindow class. Result: exit `0`; each reported `ok: 1`.
- The first child validation pass reported stale [UID:0003CW] path refs because the parent map had not yet been validated under its new filename. After validating [UID:0003CW], a child rerun reported `ok: 1` for each child with no `missing_ref_target` lines.

Supervisor-applied `by-memory/-coverage-report.md` replacement:

- The supervisor applied and validated the Batch 263 replacement block for [UID:000269], [UID:0003CW], and new children [UID:0003G3]-[UID:0003G7] on 2026-06-12.
- No Batch 263 supervisor-owned coverage-report rows remain pending.

Blockers/follow-up:

- No blocker remains for the exact CopyWindow `No`/`Yes` children.
- The shared `Leave`, `Reconnect`, and `baram` children remain intentionally parentless. A future owner-inference pass could decide whether these should become a documented shared network/login literal owner, but current by-structure does not support assigning them to either `ReconnectDialog` or `TerminalPane` alone.

## 2026-06-12 Batch 269 - SystemMessagePane vtable boundary and parent gate

Assigned target:

- [UID:0003DI] `by-memory/0x0062d5fc-0x0062d6ac.SystemMessagePaneVtableData.md`

Leases used by A002:

- Existing files leased before edits: `by-memory/0x0062d5fc-0x0062d6ac.SystemMessagePaneVtableData.md`, `by-class/SystemMessagePane.md`, `by-memory/0x0062d5fc-0x0062da10.SystemMessageReadOnlyData.md`, `by-class/-coverage-report.md`, and this `notes.md`.
- Boundary repair leases: `by-memory/0x0062d5ac-0x0062d5fc.StdioFileStringIterReadOnlyData.md` and `by-memory/0x0062d6ac-0x0062d718.SystemMessageEntryVtableData.md`.
- After renaming, new-path leases were also taken for `by-memory/0x0062d5ac-0x0062d5f8.StdioFileStringIterReadOnlyData.md`, `by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md`, `by-memory/0x0062d5f8-0x0062d6a8.SystemMessagePaneVtableData.md`, and `by-memory/0x0062d6a8-0x0062d718.SystemMessageEntryVtableData.md`.

Changed files:

- Renamed/updated `by-memory/0x0062d5ac-0x0062d5fc.StdioFileStringIterReadOnlyData.md` -> `by-memory/0x0062d5ac-0x0062d5f8.StdioFileStringIterReadOnlyData.md`
- Renamed/updated `by-memory/0x0062d5fc-0x0062da10.SystemMessageReadOnlyData.md` -> `by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md`
- Renamed/updated `by-memory/0x0062d5fc-0x0062d6ac.SystemMessagePaneVtableData.md` -> `by-memory/0x0062d5f8-0x0062d6a8.SystemMessagePaneVtableData.md`
- Renamed/updated `by-memory/0x0062d6ac-0x0062d718.SystemMessageEntryVtableData.md` -> `by-memory/0x0062d6a8-0x0062d718.SystemMessageEntryVtableData.md`
- `by-class/SystemMessagePane.md`
- `by-class/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated outputs were refreshed by scoped validation, including UID path annotations and autogen reports. No manual edit was made to `by-memory/-coverage-report.md`.

Score/parent/routing decisions:

- [UID:0003DI] target: `85/91`, parent blank, old range `0x0062d5fc-0x0062d6ac` -> `87/92`, parent [UID:0000EA][SystemMessagePane](by-class/SystemMessagePane.md), corrected range `0x0062d5f8-0x0062d6a8`.
- [UID:0000EA] `SystemMessagePane` class: `84/82` -> `86/87`, parent remains [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md). This clears the strict direct-parent gate for [UID:0003DI].
- [UID:00026M] containing aggregate: `89/92` -> `90/93`, parent blank, corrected range `0x0062d5f8-0x0062da10`, still `RECONSTRUCTABLE:FALSE` because it is a mixed non-emitting `.rdata` index.
- [UID:00026L] predecessor map: score unchanged `89/92`, corrected range `0x0062d5ac-0x0062d5f8`, parent blank.
- [UID:0003DJ] entry vtable child: `85/91` -> `86/92`, corrected range `0x0062d6a8-0x0062d718`, parent blank because it still spans HeaderSystemMessage, FooterSystemMessage, and ColorStringSystemMessage.

Evidence:

- Live IDA MCP `py_eval` confirmed the old [UID:0003DI] range was shifted by one RTTI-adjacent dword: `0x0062d5f8 -> ??_R4SystemMessagePane@@6B@`, `0x0062d5fc -> ??_7SystemMessagePane@@6B@`, and `0x0062d6a8 -> ??_R4HeaderSystemMessage@@6B@`.
- Live xrefs to the three `SystemMessagePane` vtable bases are constructor/destructor stores at `0x00584f08`/`0x0058520d`, `0x00584f0e`/`0x00585213`, and `0x00584f18`/`0x0058521d`.
- Live IDA MCP decompilation confirmed constructor publication of `dword_67adc4`, three vtable stores, ten normal-layout resource/tile contexts, message-list creation, destructor teardown/list deletion/context cleanup, `?` help shortcut behavior, packet/message cases `0x0a`/`0x0f`/`0x10`/`0x17`, paint iteration, and content-height accumulation.
- `int_convert.py` verified the corrected [UID:0003DI] byte size `0xb0` / 176.

Validation commands/results:

- `python source-3/project-documentation/tools/validator.py --mode file --file <changed-file> --apply` was run for the four renamed by-memory files, `by-class/SystemMessagePane.md`, and `by-class/-coverage-report.md`. Result: loop exited `0`; scoped validator output reported `ok: 1` for each file and recorded path updates for the renamed UIDs.
- Final target check: `python source-3/project-documentation/tools/validator.py --mode file --file by-memory/0x0062d5f8-0x0062d6a8.SystemMessagePaneVtableData.md --apply`. Result: exit `0`, `ok: 1`, no `missing_ref_target` lines.

Supervisor-applied `by-memory/-coverage-report.md` replacement:

- The supervisor applied and validated the Batch 269 replacement rows for [UID:00026L], [UID:00026M], [UID:0003DI], and [UID:0003DJ] on 2026-06-12.
- No Batch 269 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

Blockers/follow-up:

- No blocker remains for [UID:0003DI]; it now routes to the direct class parent under the strict `85/85` gate.
- Related exact entry vtable child [UID:0003DJ] remains intentionally parentless due mixed entry-class ownership.
- Final C++ remains blank for the vtable/data pages and class page because inherited slot names, field names, and class declarations remain below the `95/95` reconstruction-code gate.

## 2026-06-12 Batch 275 - ForcedInformMessageDialog vtable boundary and parent gate

Assigned target:

- [UID:0003DK] `by-memory/0x0062d718-0x0062d7b4.ForcedInformMessageDialogVtableData.md`

Leases used by A002:

- Existing/corrected memory pages: `by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md`, `by-memory/0x0062d5f8-0x0062d6a8.SystemMessagePaneVtableData.md`, `by-memory/0x0062d6a8-0x0062d714.SystemMessageEntryVtableData.md`, `by-memory/0x0062d714-0x0062d7b0.ForcedInformMessageDialogVtableData.md`, `by-memory/0x0062d7b0-0x0062d8c4.NewSystemMessagePaneVtableData.md`, `by-memory/0x0062d8c4-0x0062d974.OldSystemMessagePaneVtableData.md`, and `by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md`.
- Parent/report pages: `by-class/ForcedInformMessageDialog.md`, `by-file/ForcedInformMessageDialog.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, and this `notes.md`.

Changed files:

- Renamed/updated `by-memory/0x0062d718-0x0062d7b4.ForcedInformMessageDialogVtableData.md` -> `by-memory/0x0062d714-0x0062d7b0.ForcedInformMessageDialogVtableData.md`
- Renamed/updated `by-memory/0x0062d6a8-0x0062d718.SystemMessageEntryVtableData.md` -> `by-memory/0x0062d6a8-0x0062d714.SystemMessageEntryVtableData.md`
- Renamed/updated `by-memory/0x0062d7b4-0x0062d8c8.NewSystemMessagePaneVtableData.md` -> `by-memory/0x0062d7b0-0x0062d8c4.NewSystemMessagePaneVtableData.md`
- Renamed/updated `by-memory/0x0062d8c8-0x0062d974.OldSystemMessagePaneVtableData.md` -> `by-memory/0x0062d8c4-0x0062d974.OldSystemMessagePaneVtableData.md`
- `by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md`
- `by-memory/0x0062d5f8-0x0062d6a8.SystemMessagePaneVtableData.md`
- `by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md`
- `by-class/ForcedInformMessageDialog.md`
- `by-file/ForcedInformMessageDialog.md`
- `by-class/-coverage-report.md`
- `by-file/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated outputs were refreshed during scoped validation, including UID path annotations and autogen reports. No manual edit was made to `by-memory/-coverage-report.md`; validator normalized some UID link paths there, but the row text remains supervisor-owned and stale until the pending block below is applied.

Score/parent/routing decisions:

- [UID:0003DK] target: `85/91`, parent blank, old range `0x0062d718-0x0062d7b4` -> `87/93`, parent [UID:00005E][ForcedInformMessageDialog](by-class/ForcedInformMessageDialog.md), corrected range `0x0062d714-0x0062d7b0`.
- [UID:00005E] `ForcedInformMessageDialog` class: `86/84` -> `87/87`, parent remains [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md).
- [UID:0000JJ] `ForcedInformMessageDialog` file: `84/80` -> `87/86`, projected path remains `NexusTK/login/`.
- [UID:0003DJ] `SystemMessageEntryVtableData`: range `0x0062d6a8-0x0062d718` -> `0x0062d6a8-0x0062d714`, parent blank; score unchanged at `86/92`.
- [UID:0003DL] `NewSystemMessagePaneVtableData`: `85/91` -> `86/92`, range `0x0062d7b4-0x0062d8c8` -> `0x0062d7b0-0x0062d8c4`, parent blank.
- [UID:0003DM] `OldSystemMessagePaneVtableData`: `85/91` -> `86/92`, range `0x0062d8c8-0x0062d974` -> `0x0062d8c4-0x0062d974`, parent blank.
- [UID:00026M] containing aggregate remains `90/93`, `RECONSTRUCTABLE:FALSE`, parent blank because it is a mixed non-emitting `.rdata` index; exact child boundaries/routing were refreshed.
- Direct parent gate: [UID:0003DK] `87/93` and direct class parent [UID:00005E] `87/87` clear the strict `85/85` gate. The class parent also routes to file parent [UID:0000JJ] `87/86`.

Evidence:

- Live IDA MCP session `a001-b276` on 2026-06-12 confirmed function sizes for `0x00587bb0` (`0x4c3`), `0x00588080` (`0x81`), `0x00588110` (`0x4d`), `0x00588160` (`0x8d`), `0x0058aa90` (`0xb`), `0x0058aadb` (`0xb`), `0x0058aae6` (`0xb`), and `0x0058abf0` (`0xc2`).
- Live IDA MCP `get_int`/`entity_query` confirmed the forced-inform locator-inclusive range starts before the primary vtable at `0x0062d718`, has adjusted vtables at `0x0062d778` and `0x0062d7a8`, and ends before the `NewSystemMessageModifyHeightPane` vtable head at `0x0062d7b4`.
- Live IDA MCP `xrefs_to` confirmed forced-inform vtable store refs at `0x00587c28`/`0x005880a5`/`0x0058ac15`, `0x00587c31`/`0x005880ab`/`0x0058ac1b`, and `0x00587c3b`/`0x005880b5`/`0x0058ac25`.
- Live IDA MCP `xrefs_to` confirmed `g_pForcedInformMessageDialog` refs at `0x004f69ec`, `0x00587c17`, `0x00587c1e`, `0x005880e2`, `0x0058aa90`, and `0x0058ac59`, plus destructor calls to `0x004f8b30` at `0x005880db` and `0x0058ac52`.
- Live IDA MCP `xrefs_to` confirmed `DLGSTAFF.PAL`, `DLGSTAFF.EPF`, and `DLGSTAFF.EPD` constructor refs at `0x0062d9a0`, `0x0062d9bc`, and `0x0062d9d8`.
- `int_convert` verified sizes `0x9c` / 156, `0x114` / 276, and `0xb0` / 176 where documented.

Validation commands/results:

- `python source-3/project-documentation/tools/validator.py --mode file --file <changed-file> --apply --queue-timeout 240` was run for the four renamed by-memory files, the aggregate, supporting core/vtable pages, the class/file parent pages, and `by-class/-coverage-report.md` / `by-file/-coverage-report.md`. Result: loop exited `0`; scoped validator output reported `ok: 1` for each file and recorded path updates for [UID:0003DJ], [UID:0003DK], [UID:0003DL], and [UID:0003DM].
- Initial validator passes reported stale `by-memory/-coverage-report.md` row bodies/paths for [UID:0003DK]-[UID:0003DM] until the renamed targets were scanned. The report row text remains pending supervisor replacement below.

Supervisor-applied `by-memory/-coverage-report.md` replacement:

- The supervisor applied the Batch 275 replacement block for [UID:00026M], [UID:0003DI], [UID:0003DJ], [UID:0003DK], [UID:0003DL], and [UID:0003DM] on 2026-06-12.

Blockers/follow-up:

- No Batch 275 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.
- No blocker remains for [UID:0003DK]; it now routes to the direct class parent under the strict `85/85` gate.
- Final C++ remains blank for these vtable/data pages and class/file pages because inherited slot names, field names, class declarations, and surrounding source are below the `95/95` reconstruction-code gate.

## 2026-06-12 Batch 282 - HeadSelectDialog vtable and parent gate

Assigned target:

- [UID:0003DA] `by-memory/0x006228b8-0x00622954.HeadSelectDialogVtableData.md`

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

- The supervisor applied and validated the Batch 282 `by-memory/-coverage-report.md` replacement rows for [UID:0003DA], [UID:0003DG], [UID:00027Z], and [UID:000281] on 2026-06-12.

Supervisor-applied `by-class/-coverage-report.md` replacement row:

- The supervisor applied and validated the Batch 282 `by-class/-coverage-report.md` replacement row for [UID:000062][HeadSelectDialog](../../../by-class/HeadSelectDialog.md) on 2026-06-12.

## 2026-06-12 Batch 286 - NewSystemMessagePane vtable split and ownership repair

Assigned target:

- [UID:0003DL] `by-memory/0x0062d7b0-0x0062d8c4.NewSystemMessagePaneVtableData.md`

Supervisor-applied `by-memory/-coverage-report.md` replacement:

- The supervisor applied and validated the Batch 286 replacement block for [UID:0003DL] plus new exact children [UID:0003GM] and [UID:0003GN] on 2026-06-12.

## 2026-06-12 Batch 288 - TerminalSetupPane vtable routing and parent repair

Assigned target:

- [UID:0003DP] `by-memory/0x0062daac-0x0062db48.TerminalSetupPaneVtableData.md`

Supervisor-applied shared updates:

- The supervisor applied and validated the Batch 288 `by-class/-coverage-report.md` row for [UID:0000EH][TerminalSetupPane](../../../by-class/TerminalSetupPane.md) on 2026-06-12.
- The supervisor applied and validated the Batch 288 `by-memory/-coverage-report.md` rows for [UID:0001JB] and [UID:0003DP] on 2026-06-12.
- The supervisor applied and validated the Batch 288 stale-prose replacement in [UID:00026N][TerminalPhoneReadOnlyData](../../../by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md) on 2026-06-12.
- No Batch 288 supervisor-owned shared-file rows remain pending.

## 2026-06-12 Batch 292 - Terminal/Phone resource-string tail split

Assigned target:

- [UID:0003DU] `by-memory/0x0062dddc-0x0062df94.TerminalPhoneResourceStringsAndCallbackData.md`

Supervisor-applied coverage sync:

- The supervisor applied and validated the Batch 292 `by-memory/-coverage-report.md` replacement/insert block for [UID:00026N], [UID:0003DU], and new child rows [UID:0003GT] through [UID:0003GX] on 2026-06-12.
- No Batch 292 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

Score/parent/routing decisions:

- [UID:0003DU] target: `85/90`, `RECONSTRUCTABLE:TRUE`, parent blank -> `88/93`, `RECONSTRUCTABLE:FALSE`, parent blank, now a non-emitting mixed split index.
- New [UID:0003GT] `TerminalPaneModemCallbackAndParserData`: `0/0` -> `87/92`, parent [UID:0000EG][TerminalPane](../../../by-class/TerminalPane.md).
- New [UID:0003GU] `TerminalSetupPaneResourceStrings`: `0/0` -> `87/92`, parent [UID:0000EH][TerminalSetupPane](../../../by-class/TerminalSetupPane.md).
- New [UID:0003GV] `PhoneBookDialogResourceStrings`: `0/0` -> `86/91`, parent [UID:0000AD][PhoneBookDialog](../../../by-class/PhoneBookDialog.md).
- New [UID:0003GW] `PhoneEntryDialogResourceStrings`: `0/0` -> `86/90`, parent blank because [UID:0000AF][PhoneEntryDialog](../../../by-class/PhoneEntryDialog.md) is `80/86` and was leased by another agent during the batch.
- New [UID:0003GX] `DialDialogResourceAndModemStrings`: `0/0` -> `87/91`, parent [UID:00003R][DialDialog](../../../by-class/DialDialog.md).
- [UID:00026N] aggregate remains `86/91`, `RECONSTRUCTABLE:FALSE`, parent blank; child table/source mapping updated for the split.

Evidence:

- Live IDA MCP session `a001-b276` on 2026-06-12 confirmed names and boundaries from `0x0062dddc` through the `TextEditPane` successor at `0x0062df94`.
- Live IDA `xrefs_to` tied the owner split to `sub_58B470`/`sub_58B130` for TerminalPane, `sub_58B650` for TerminalSetupPane, `sub_58C350`/`sub_58CE30` for PhoneBookDialog, `sub_58D270` for PhoneEntryDialog, and `sub_58D750` for DialDialog.
- Live IDA `analyze_function` for `0x0058b470`, `0x0058b130`, `0x0058b650`, `0x0058c350`, `0x0058d270`, and `0x0058d750` corroborated the string/callback uses documented in the new child pages.

Validation commands/results:

- Created new child pages, then ran `python source-3/project-documentation/tools/validator.py --mode file --file <new-child> --apply --queue-timeout 240` to allocate UIDs [UID:0003GT] through [UID:0003GX].
- Ran scoped validator file-mode passes with `--apply --queue-timeout 240` for all five new child pages plus [UID:0003DU] and [UID:00026N]. Result: command exited `0`; validator reported `ok: 1` for each final scoped pass and updated autogen metadata/references.
- No manual edit was made to `by-memory/-coverage-report.md`; the supervisor later applied and validated the exact row text.

## 2026-06-12 Batch 293 - OpenCreateUserDialog retained launcher routing

Assigned target:

- [UID:0000TB] `by-global/OpenCreateUserDialog_4F8FA0.md`

Changed files:

- `by-global/OpenCreateUserDialog_4F8FA0.md`
- `by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md`
- `by-file/MainMenuPane.md`
- `by-global/-coverage-report.md`
- `by-file/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned metadata was refreshed during scoped validation, including `tools/validator.ini`, `project-level/-auto-completion-stats.md`, UID reference annotations, and unchanged autogen report checks.

Leases:

- Used leases for `by-global/OpenCreateUserDialog_4F8FA0.md`, `by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md`, `by-file/MainMenuPane.md`, `by-global/-coverage-report.md`, `by-file/-coverage-report.md`, and `tools/leaser/Agents/Agent-A002/notes.md`.

Score/parent/routing decisions:

- [UID:0000TB] target: `84/88`, parent blank -> `86/90`, parent [UID:0000L0][MainMenuPane](../../../by-file/MainMenuPane.md).
- [UID:0000L0] `MainMenuPane` file parent: `88/82` -> `89/86`, parent remains project-structure owned through the existing class/file routing.
- [UID:00019P] `by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md`: `84/86` -> `85/88`, parent remains [UID:0000L0][MainMenuPane](../../../by-file/MainMenuPane.md).
- Parent routing was set only after both direct sides cleared the strict gate: [UID:0000TB] at `86/90` and [UID:0000L0] at `89/86`.
- Final C++ remains blank because the retained launcher and file parent remain below the `95/95` reconstruction-code gate.

Evidence:

- Live IDA MCP session `b001_nexustk` on 2026-06-12 identified `sub_4F8FA0` at `0x004f8fa0` with size `0xb5` / 181 bytes and no direct callers; the next retained launcher starts at `0x004f9060`.
- Live IDA `analyze_function 0x004f8fa0` confirmed the `byte_66DA97 == 1` branch, optional close of `dword_69B484` through `sub_49DAD0`, `0x280` / 640-byte allocations, constructor targets `sub_52DD30` and `sub_52A540`, and sound call `sub_579E30(0, 100, 1)`.
- Live IDA `analyze_function 0x004f7a10` confirmed `MainMenuPane::ActivateMenuItem` duplicates the same create-user branch in menu case 0, including the same modal-close, allocation, constructor, and sound-call sequence.
- Live IDA `xrefs_to` confirmed constructor/sound references from both the retained launcher and the active menu branch: `sub_52DD30` at `0x4f7a82`/`0x4f8ff8`, `sub_52A540` at `0x4f7ad0`/`0x4f9041`, and `sub_579E30` at `0x4f7a9a`/`0x4f9010`.
- `int_convert.py` verified `0xb5` / 181 and `0x280` / 640 where documented.

Validation commands/results:

- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-global/OpenCreateUserDialog_4F8FA0.md --apply --queue-timeout 240`: exited `0`; validator reported `ok: 1`, `completion_update 0000TB ... 86`, `confidence_update 0000TB ... 90`, and parent update to [UID:0000L0].
- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md --apply --queue-timeout 240`: exited `0`; validator reported `ok: 1`, `completion_update 00019P ... 85`, and `confidence_update 00019P ... 88`.
- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-file/MainMenuPane.md --apply --queue-timeout 240`: exited `0`; validator reported `ok: 1`, `completion_update 0000L0 ... 89`, and `confidence_update 0000L0 ... 86`.
- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-global/-coverage-report.md --apply --queue-timeout 240`: exited `0`; validator reported `ok: 1`.
- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-file/-coverage-report.md --apply --queue-timeout 240`: exited `0`; validator reported `ok: 1`.

Supervisor-applied `by-memory/-coverage-report.md` replacement row:

- The supervisor applied and validated the Batch 293 `by-memory/-coverage-report.md` replacement row for [UID:00019P] on 2026-06-12.

Blockers/follow-up:

- No blocker remains for [UID:0000TB]; it now routes to the direct `MainMenuPane` file parent under the strict `85/85` gate.
- No Batch 293 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-12 Batch 301 - OpenStoryViewingPane retained launcher split/routing

Assigned target:

- [UID:0000TE] `by-global/OpenStoryViewingPane_4F90C0.md`

Changed files:

- `by-global/OpenStoryViewingPane_4F90C0.md`
- `by-global/OpenHistoryViewingPane_4F9140.md`
- `by-global/-coverage-report.md`
- `by-memory/0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md`
- New `by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md`
- New `by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned metadata/generated reports were refreshed by scoped validation, including UID mappings and `auto-generated/-ag-global-coverage.md` / `auto-generated/-ag-memory-coverage.md`.

Leases:

- Used leases for `by-global/OpenStoryViewingPane_4F90C0.md`, `by-global/OpenHistoryViewingPane_4F9140.md`, `by-memory/0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md`, `by-global/-coverage-report.md`, `tools/leaser/Agents/Agent-A002/notes.md`, and the two new exact child pages after creation.

Score/parent/routing decisions:

- [UID:0000TE] target: `84/88`, parent blank -> `86/90`, parent [UID:0000L0][MainMenuPane](../../../by-file/MainMenuPane.md).
- [UID:0000TC] sibling helper: `84/88` -> `86/90`, parent remains [UID:0000L0][MainMenuPane](../../../by-file/MainMenuPane.md); stale strict-gate caveat removed.
- [UID:00019R] aggregate: `80/86`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000L0][MainMenuPane](../../../by-file/MainMenuPane.md) -> `86/90`, `RECONSTRUCTABLE:FALSE`, parent blank; now a non-emitting split index.
- New [UID:0003H6] `0x004f90c0-0x004f913f.OpenStoryViewingPane`: `0/0` -> `86/90`, parent [UID:0000L0][MainMenuPane](../../../by-file/MainMenuPane.md).
- New [UID:0003H7] `0x004f9140-0x004f91bf.OpenHistoryViewingPane`: `0/0` -> `86/90`, parent [UID:0000L0][MainMenuPane](../../../by-file/MainMenuPane.md).
- Direct route gate: [UID:0000TE] and exact child [UID:0003H6] clear at `86/90`; actual direct parent [UID:0000L0][MainMenuPane](../../../by-file/MainMenuPane.md) remains `89/86`, so assignment is justified.
- Final C++ remains blank for all edited reconstructable pages because retained-helper reachability/callback reason and final source shape are below the `95/95` reconstruction-code gate.

Evidence:

- Live IDA MCP session `b001_nexustk` on 2026-06-12 reconfirmed `sub_4F90C0` at `0x004f90c0` and `sub_4F9140` at `0x004f9140`, both with size `0x7f` / 127 bytes (Verified with `int_convert.py`), non-function end boundaries at `0x004f913f` and `0x004f91bf`, and successor `sub_4F91C0` at `0x004f91c0`.
- Live IDA `analyze_function` reconfirmed both helpers use `byte_66DA97` / `g_useEpfAssets`, `0x108` / 264-byte allocations (Verified with `int_convert.py`), null checks, and `HistoryViewingPane` constructor calls through `sub_4FFD80`.
- Live IDA `xrefs_to` reconfirmed zero helper-entry xrefs for `0x004f90c0` and `0x004f9140`.
- Live IDA `xrefs_to 0x004ffd80` reported active menu story/history call sites at `0x004f7b8d`, `0x004f7bc3`, `0x004f7c07`, and `0x004f7c3d`, plus retained helper calls at `0x004f912b` and `0x004f91ab`.
- Live IDA `xrefs_to` reconfirmed `STORY.EPF` / `STORY.EPD` active/helper sites and `HISTORY.EPF` / `HISTORY.EPD` active/helper sites.
- Live IDA `analyze_function 0x004f7a10` reconfirmed `MainMenuPane::ActivateMenuItem` cases `3` and `4` directly duplicate the retained helper allocation/resource/constructor behavior.

Validation commands/results:

- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md --apply --queue-timeout 240`: exited `0`; validator inserted [UID:0003H6], recorded `completion_update ... 86`, `confidence_update ... 90`, and parent [UID:0000L0].
- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md --apply --queue-timeout 240`: exited `0`; validator inserted [UID:0003H7], recorded `completion_update ... 86`, `confidence_update ... 90`, and parent [UID:0000L0].
- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md --apply --queue-timeout 240`: exited `0`; validator reported `ok: 1`, `completion_update 00019R ... 86`, `confidence_update 00019R ... 90`, `true -> false`, and parent cleared.
- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-global/OpenStoryViewingPane_4F90C0.md --apply --queue-timeout 240`: exited `0`; validator reported `ok: 1`, target `0000TE` at `86/90`, and parent [UID:0000L0].
- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-global/OpenHistoryViewingPane_4F9140.md --apply --queue-timeout 240`: exited `0`; validator reported `ok: 1`, sibling `0000TC` at `86/90`, and parent [UID:0000L0].
- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-global/-coverage-report.md --apply --queue-timeout 240`: exited `0`; validator reported `ok: 1`.

Supervisor-applied `by-memory/-coverage-report.md` replacement block:

- The supervisor applied and validated the Batch 301 `by-memory/-coverage-report.md` replacement block for [UID:00019R], [UID:0003H6], and [UID:0003H7] on 2026-06-12.

Blockers/follow-up:

- No blocker remains for [UID:0000TE]; it is assigned to the direct `MainMenuPane` file parent under the strict `85/85` gate.
- No Batch 301 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-12 Batch 306 - OpenTerminalPane retained launcher routing

Assigned target:

- [UID:0000TF] `by-global/OpenTerminalPane_4F91C0.md`

Changed files:

- `by-global/OpenTerminalPane_4F91C0.md`
- `by-memory/0x004f91c0-0x004f927d.OpenTerminalPane.md`
- `by-global/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Leases used:

- `by-global/OpenTerminalPane_4F91C0.md`
- `by-memory/0x004f91c0-0x004f927d.OpenTerminalPane.md`
- `by-global/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/parent/routing decisions:

- [UID:0000TF] target: `84/88`, parent blank -> `86/90`, parent [UID:0000L0][MainMenuPane](../../../by-file/MainMenuPane.md).
- [UID:00019S] exact memory page: `84/86` -> `86/90`, parent remains [UID:0000L0][MainMenuPane](../../../by-file/MainMenuPane.md).
- Direct route gate: [UID:0000TF] clears `86/90`; actual direct parent [UID:0000L0][MainMenuPane](../../../by-file/MainMenuPane.md) already clears `89/86`, so assignment is justified.
- Final C++ remains blank because retained-helper live reachability and final source shape remain below the `95/95` reconstruction-code gate.

Evidence:

- Live IDA MCP session `b001_nexustk` on 2026-06-12 reconfirmed `sub_4F91C0` at `0x004f91c0`, exact `0x004f91c0-0x004f927d` boundary, IDA size `0xbd` / 189 bytes (Verified with int_convert.py), no function start at `0x004f927d`, and successor `sub_4F9280` at `0x004f9280`.
- Live IDA `analyze_function 0x004f91c0` reconfirmed cleanup/reset/login-close/BlackHole/exit-or-terminal/sound flow, `0x270` / 624-byte allocation (Verified with int_convert.py), `0x2916ca` / 2692810 state-byte offset (Verified with int_convert.py), and `0x192` / 402 sound id (Verified with int_convert.py).
- Live IDA `xrefs_to 0x004f91c0` returned no helper-entry references; `xrefs_to 0x0058af50` confirmed `TerminalPane` constructor call sites at `0x004f7cbb` in `MainMenuPane::ActivateMenuItem` and `0x004f924f` in the retained helper.
- Live IDA `analyze_function 0x004f7a10` reconfirmed active menu case `5` duplicates the retained terminal-launch flow.

Validation commands/results:

- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-global/OpenTerminalPane_4F91C0.md --apply --queue-timeout 240`: exited `0`; validator reported `ok: 1`, `completion_update 0000TF ... 86`, `confidence_update 0000TF ... 90`, and parent update to [UID:0000L0].
- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x004f91c0-0x004f927d.OpenTerminalPane.md --apply --queue-timeout 240`: exited `0`; validator reported `ok: 1`, `completion_update 00019S ... 86`, and `confidence_update 00019S ... 90`.
- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-global/-coverage-report.md --apply --queue-timeout 240`: exited `0`; validator reported `ok: 1`.
- Validator-owned generated/bookkeeping outputs were refreshed during scoped validation, including `validator.ini`, projected stats, and unchanged autogen report checks. No manual edits were made to `by-memory/-coverage-report.md`.

Supervisor-applied `by-memory/-coverage-report.md` replacement row:

- The supervisor applied and validated the Batch 306 `by-memory/-coverage-report.md` replacement row for [UID:00019S] on 2026-06-12.
- No Batch 306 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-12 Batch 309 - PoolAllocatorStaticInstances by-structure repair

Assigned target:

- [UID:0000TI] `by-global/PoolAllocatorStaticInstances.md`

Changed files:

- `by-global/PoolAllocatorStaticInstances.md`
- `by-global/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Leases used:

- `by-global/PoolAllocatorStaticInstances.md`
- `by-global/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/parent/routing decisions:

- [UID:0000TI] target: `87/89`, `RECONSTRUCTABLE:TRUE`, parent blank -> `89/92`, `RECONSTRUCTABLE:FALSE`, parent blank.
- Routing decision: no parent assigned. [UID:0000MM][PoolAllocator](../../../by-file/PoolAllocator.md) clears `86/85`, but it owns allocator mechanics only, not every concrete static declaration in this mixed inventory.
- By-structure repair: exact by-memory children already carry the real source declarations, including object-pane pool children under [UID:0002B4][0x0069b894-0x0069ba24.ObjectPanePoolStaticStorage](../../../by-memory/0x0069b894-0x0069ba24.ObjectPanePoolStaticStorage.md), [UID:0002AN][0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage](../../../by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md), and [UID:0002AC][0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage](../../../by-memory/0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage.md). The by-global aggregate is now a reviewed non-emitting index.

Evidence:

- Live IDA MCP session `b001_nexustk` on 2026-06-12 reconfirmed representative object-pane xrefs: `0x0069b894` through constructor `0x0041a100`, owner allocation `0x00505e00`, unwind free `0x00514c60`, scalar destructor `0x0053d430`, and cleanup `0x0060c380`; `0x0069b9fc` through constructor `0x0041a040`, owner/allocation paths `0x00468f80`, `0x0050e100`, `0x00511710`, unwind free `0x00514ae0`, and cleanup `0x0060c320`.
- Live IDA reconfirmed string-pool xrefs: wide pool `0x0069bacc` through constructor `0x0041a260`, allocation `0x00582e30`, release `0x005833a0`, and cleanup `0x0060c430`; ANSI pool `0x0069bb6c` through constructor `0x0041a240`, allocation `0x00582d80`, release `0x005832f0`, and cleanup `0x0060c420`.
- Live IDA reconfirmed UserPane pool `0x0069bf34` through constructor `0x0041a4b0`, allocation sites in `0x004f7d10`, unwind free `0x00502420`, scalar destructor return `0x005b8230`, and cleanup `0x0060c450`.
- Live IDA `xrefs_to` reconfirmed allocator-mechanics fanout: nineteen static constructor callers to `0x004b13d0`, 33 allocation callers to `0x004b1400`, 30 free callers to `0x004b14c0`, and nineteen cleanup callers to `0x004b1520`.
- `int_convert.py` reconfirmed `0x28` / 40-byte storage records, `0x20c` / 524-byte LivingObjectPane blocks, `0x1e0` / 480-byte BalloonObjectPane blocks, `0x8e` / 142-byte wide string-pool blocks, `0x4d` / 77-byte ANSI string-pool blocks, and 1305476 / `0x13eb84` for the large UserPane block size.

Validation commands/results:

- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-global/PoolAllocatorStaticInstances.md --apply --queue-timeout 240`: exited `0`; validator reported `ok: 1`, `completion_update 0000TI ... 89`, `confidence_update 0000TI ... 92`, and `autogen_registry_update 0000TI ... true -> false`.
- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-global/-coverage-report.md --apply --queue-timeout 240`: exited `0`; validator reported `ok: 1`.
- Generated global coverage now reports [UID:0000TI] as `not_reconstructable` instead of `unassigned`.
- Validator-owned generated/bookkeeping outputs were refreshed during scoped validation. No manual edits were made to generated/project-level/tool-state files.

Supervisor-owned pending rows:

- None expected. This batch did not edit by-memory docs or require direct `by-memory/-coverage-report.md` replacement rows.

## 2026-06-12 Batch 312 - SystemMessageMarker scalar deleting destructor by-structure repair

Assigned target:

- [UID:0001B5] `by-memory/0x00514e60-0x00514e98.SystemMessageMarkerScalarDeletingDestructor.md`

Changed files:

- `by-memory/0x00514e60-0x00514e98.SystemMessageMarkerScalarDeletingDestructor.md`
- `by-memory/-ignored.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Leases used:

- `by-memory/0x00514e60-0x00514e98.SystemMessageMarkerScalarDeletingDestructor.md`
- `by-memory/-ignored.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/parent/routing decisions:

- [UID:0001B5] target: `88/92`, `RECONSTRUCTABLE:TRUE`, parent blank -> `90/93`, `RECONSTRUCTABLE:FALSE`, parent blank.
- Routing decision: no parent assigned. The page clears `85/85`, and related [UID:0000OE][SystemMessagePanes](../../../by-file/SystemMessagePanes.md), [UID:00007D][LObject](../../../by-class/LObject.md), and [UID:0002SS][0x0061e8dc-0x0061e8fc.DialogCreatorVtableData](../../../by-memory/0x0061e8dc-0x0061e8fc.DialogCreatorVtableData.md) all clear their numeric gates, but no single one is the direct source parent. The exact body is shared by two system-message marker vtables and two dialog-creator vtables and has no class-specific teardown.
- By-structure repair: reclassified the body as ignored/non-emitting compiler-generated scalar deleting-destructor wrapper. Source reconstruction should declare the owning classes and destructor/vtable relationships, not hand-author this standalone wrapper.

Evidence:

- Live IDA MCP session `b001_nexustk` on 2026-06-12 reported `sub_514E60` at `0x00514e60`, size `0x38` / 56 bytes (Verified with `int_convert.py`), no function at `0x00514e98`, and successor `sub_514EA0` at `0x00514ea0`.
- Live IDA `analyze_function 0x00514e60` confirmed only inherited `LObject` cleanup `0x004f4a90`, scalar-delete flag tests, optional delete wrapper `0x004f4ac0`, and guarded no-delete path `0x0041b6a0`.
- Live IDA confirmed no ordinary direct callers, exactly four vtable-slot data refs at `0x0061e8e0`, `0x0061e8f0`, `0x0062d6ac`, and `0x0062d6d0`, and all four slot dwords resolving to decimal `5328480` / `0x514e60` (Verified with `int_convert.py`).
- Live IDA `get_bytes` confirmed five leading `0xcc` bytes before the prolog, the exact 56-byte body, and eight trailing `0xcc` bytes before the next function.

Validation commands/results:

- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x00514e60-0x00514e98.SystemMessageMarkerScalarDeletingDestructor.md --apply --queue-timeout 240`: exited `0`; validator reported `ok: 1`, `completion_update 0001B5 ... 90`, `confidence_update 0001B5 ... 93`, and `autogen_registry_update 0001B5 ... true -> false`.
- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/-ignored.md --apply --queue-timeout 240`: exited `0`; validator reported `ok: 1` and reference-index additions for the ignored-ledger owner links.
- Generated `auto-generated/-ag-memory-coverage.md` now reports [UID:0001B5] as `not_reconstructable`.

Supervisor-applied `by-memory/-coverage-report.md` replacement row:

- The supervisor applied and validated the Batch 312 replacement row for [UID:0001B5] on 2026-06-12.
- No Batch 312 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-12 Batch 315 - Item/Flying object pane executable split

Assigned target:

- [UID:0001D7] `by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md`

Changed files:

- `by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md`
- New `by-memory/0x00537b40-0x00537b91.ItemObjectPaneConstructor.md`
- New `by-memory/0x00537ba0-0x00537bbf.ItemObjectPaneNonDeletingDestructor.md`
- New `by-memory/0x00537bc0-0x00537be9.ItemObjectPaneRecordStateUpdate.md`
- New `by-memory/0x00537bf0-0x00537c65.ItemObjectPaneBuildCenteredItemRect.md`
- New `by-memory/0x00537c70-0x00537ca2.ItemObjectPaneProcessItemAction.md`
- New `by-memory/0x00537cb0-0x00537d60.FlyingObjectPaneConstructor.md`
- New `by-memory/0x00537d60-0x00537d7f.FlyingObjectPaneNonDeletingDestructor.md`
- New `by-memory/0x00537d80-0x00537f1d.FlyingObjectPaneGetBoundingRect.md`
- New `by-memory/0x00537f20-0x005380af.FlyingObjectPaneOnAnimationTick.md`
- `by-memory/-ignored.md`
- `by-class/ItemObjectPane.md`
- `by-class/FlyingObjectPane.md`
- `by-class/LivingObjectPane.md`
- `by-file/ItemObjectPane.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/parent/routing decisions:

- [UID:0001D7] aggregate: `85/89`, `RECONSTRUCTABLE:TRUE`, parent blank -> `89/92`, `RECONSTRUCTABLE:FALSE`, parent blank. It is now a non-emitting split index.
- [UID:0003HQ] `ItemObjectPaneConstructor`: new child, `86/90`, parent [UID:00006V].
- [UID:0003HR] `ItemObjectPaneNonDeletingDestructor`: new child, `85/90`, parent [UID:00006V].
- [UID:0003HS] `ItemObjectPaneRecordStateUpdate`: new child, `86/90`, parent [UID:00006V]. A002 corrected stale LivingObjectPane wording after live caller decompilation showed the helper is invoked from the non-living `object+0xf8 == 0` branch and writes ItemObjectPane item-state fields.
- [UID:0003HT] `ItemObjectPaneBuildCenteredItemRect`: new child, `86/90`, parent [UID:00006V].
- [UID:0003HU] `ItemObjectPaneProcessItemAction`: new child, `85/90`, parent [UID:00006V].
- [UID:0003HV] `FlyingObjectPaneConstructor`: new child, `86/90`, parent [UID:000057].
- [UID:0003HW] `FlyingObjectPaneNonDeletingDestructor`: new child, `85/90`, parent [UID:000057].
- [UID:0003HX] `FlyingObjectPaneGetBoundingRect`: new child, `86/91`, parent [UID:000057].
- [UID:0003HY] `FlyingObjectPaneOnAnimationTick`: new child, `86/91`, parent [UID:000057].
- Direct parent gate: [UID:00006V][ItemObjectPane] is `86/89`, [UID:000057][FlyingObjectPane] is `85/88`, and file parent [UID:0000KG][ItemObjectPane] is `85/86`, so all child routing decisions clear the strict `85/85` gate.

Validation commands/results:

- `python source-3/project-documentation/tools/validator.py --mode file --file <new child> --apply --queue-timeout 240`: run for nine new child pages to allocate [UID:0003HQ]-[UID:0003HY]; each exited `0`.
- `python source-3/project-documentation/tools/validator.py --mode file --file <changed file> --apply --queue-timeout 240`: run for all nine child pages, [UID:0001D7] aggregate, `by-memory/-ignored.md`, `by-class/ItemObjectPane.md`, `by-class/FlyingObjectPane.md`, `by-class/LivingObjectPane.md`, and `by-file/ItemObjectPane.md`; command loop exited `0`. Visible validator summaries included expected completion/confidence/autogen parent updates and `ok: 1`.

Supervisor-applied `by-memory/-coverage-report.md` replacement block:

- The supervisor applied and validated the Batch 315 replacement block for [UID:0001D7] and child rows [UID:0003HQ]-[UID:0003HY] on 2026-06-12.
- No Batch 315 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-12 Batch 321 - DecoderReadOnlyData split into BinaryCodec/DAT/Error children

Assigned target:

- [UID:000257] `by-memory/0x006192c6-0x00619344.DecoderReadOnlyData.md`

Supervisor-applied follow-up:

- The supervisor renamed [UID:000258] to `by-memory/0x00619340-0x006196c0.ErrorEventReadOnlyData.md`, updated its start-boundary text to include the `0x00619340 -> ??_R4Error@@6B@` RTTI prelude now owned by [UID:0002ND], removed the old [UID:000257] caveat, and validated the file on 2026-06-12.

Changed files:

- Renamed `by-memory/0x006192c6-0x00619344.DecoderReadOnlyData.md` -> `by-memory/0x006192c6-0x00619340.BinaryCodecDatReadOnlyData.md`
- New `by-memory/0x006192c6-0x006192c8.PostAddEmployeeAlertPadding.md`
- New `by-memory/0x006192c8-0x006192d4.EncoderVtableData.md`
- New `by-memory/0x006192d4-0x006192e0.DecoderVtableData.md`
- New `by-memory/0x006192e0-0x00619340.ParseEntriesConstantTable.md`
- Renamed `by-memory/0x00619344-0x00619448.ErrorHierarchyVtableData.md` -> `by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md`
- `by-global/ParseEntries_004A5E60.md`
- `by-type/by-vtable/ErrorHierarchyVtables.md`
- `by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md`
- `by-memory/0x006125a8-0x006125bc.PasswordErrorVtableData.md`
- `by-memory/-ignored.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/parent/routing decisions:

- [UID:000257] target: `85/91`, `RECONSTRUCTABLE:TRUE`, parent blank -> `88/92`, `RECONSTRUCTABLE:FALSE`, parent blank. It is now a non-emitting mixed BinaryCodec/DAT container ending before Error RTTI.
- [UID:0003I9] padding child: new `94/94`, `RECONSTRUCTABLE:FALSE`, parent blank.
- [UID:0003IA] Encoder vtable child: new `88/91`, `RECONSTRUCTABLE:TRUE`, parent blank because direct [UID:00004F][Encoder] is `82/86`, below the strict completion gate.
- [UID:0003IB] Decoder vtable child: new `88/91`, `RECONSTRUCTABLE:TRUE`, parent blank because direct [UID:00003M][Decoder] is `80/82`, below the strict gate.
- [UID:0003IC] ParseEntries constant child: new `89/92`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000TH]. Direct parent [UID:0000TH] is now `87/91`, so the child/direct-parent gate clears.
- [UID:0002ND] Error hierarchy vtable child: `84/90 -> 87/91`, parent remains [UID:0000J5]. Direct parent [UID:0000J5] is `87/85`, so the child/direct-parent gate clears.
- [UID:0000TH] ParseEntries global helper: `86/90 -> 87/91`, parent unchanged [UID:0000IN].
- [UID:0001XI] ErrorHierarchyVtables: score unchanged `86/90`; references updated to the corrected exact child range.

Validation commands/results:

- New-child UID allocation loop: `python .../validator.py --mode file --file <new child> --apply --queue-timeout 240`; exited `0`, allocated [UID:0003I9]-[UID:0003IC].
- Main validation loop over [UID:000257], [UID:0003I9], [UID:0003IA], [UID:0003IB], [UID:0003IC], [UID:0002ND], [UID:0000TH], [UID:0001XI], and `by-memory/-ignored.md`: exited `0`. Visible results included `path_update` for [UID:000257] and [UID:0002ND], `tmp_ref_replace` for all new children, completion/confidence/autogen updates, and `autogen_report_noop` for generated reports after the final pass.
- Reference cleanup validation for `0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md` and `0x006125a8-0x006125bc.PasswordErrorVtableData.md`: exited `0`, each with `ok: 1`.
- Final stale-reference scan at batch close: remaining matches for old ranges were only `by-memory/-coverage-report.md` rows later resolved by the supervisor plus intentional historical change-log wording in [UID:000257] and [UID:0002ND].
- The supervisor merged this with A003 Batch 322, applied and validated the `by-memory/-coverage-report.md` replacement block for [UID:000257], [UID:000258], [UID:0002ND], and new children [UID:0003I4]-[UID:0003IC] on 2026-06-12.
- No Batch 321 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-12 Batch 325 - MapName/MiniMap resource string split

Changed files:

- `by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md`
- `by-memory/0x0061e5b4-0x0061e704.MapNameMiniMapButtonReadOnlyData.md`
- New `by-memory/0x0061e6c0-0x0061e6d8.MapNamePaneEpfResourceString.md`
- New `by-memory/0x0061e6d8-0x0061e6f0.MiniMapButtonPaneEpfResourceString.md`
- New `by-memory/0x0061e6f0-0x0061e6f8.MapPaneCmapSignatureString.md`
- New `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md`
- `by-class/MapNamePane.md`
- `by-class/MiniMapButtonPane.md`
- `by-class/MapPane.md`
- `by-memory/0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/parent/routing decisions:

- [UID:0003C1] `MapNameMiniMapResourceStrings`: `88/93`, `RECONSTRUCTABLE:TRUE`, parent blank -> `90/94`, `RECONSTRUCTABLE:FALSE`, parent blank. It is now a non-emitting split index over exact string children.
- [UID:0003IL] `MapNamePaneEpfResourceString`: new child, `86/92`, parent [UID:00007P]. Direct parent [UID:00007P][MapNamePane] is `86/88`, so the strict `85/85` gate clears.
- [UID:0003IM] `MiniMapButtonPaneEpfResourceString`: new child, `86/92`, parent [UID:00008B]. Direct parent [UID:00008B][MiniMapButtonPane] is `85/86`, so the strict `85/85` gate clears.
- [UID:0003IN] `MapPaneCmapSignatureString`: new child, `86/92`, parent [UID:0000L3] using the same MapPane file fallback as the pointer anchor [UID:0002ZN]. Direct parent [UID:0000L3][MapPane] is `89/85`; semantic class anchor [UID:00007Q][MapPane] is `85/85`.
- [UID:0003IO] `SharedGmWideString`: new child, `86/91`, parent blank. The child clears `85/85`, but live xrefs span MapPane, LivingObjectPane, and ObjectList consumers; no single direct source parent is proven.
- [UID:00025R] aggregate score unchanged at `88/93`, parent blank.
- [UID:00007P], [UID:00008B], [UID:00007Q], and [UID:0002ZN] scores unchanged; references updated only.

Validation commands/results:

- New child UID allocation loop: `python source-3/project-documentation/tools/validator.py --mode file --file <new child> --apply --queue-timeout 240`; exited `0`, allocated [UID:0003IL]-[UID:0003IO].
- Main validation loop over [UID:0003C1], [UID:00025R], [UID:00007P], [UID:00008B], [UID:00007Q], and [UID:0002ZN]: exited `0`. Visible results included `completion_update 0003C1 ... 90`, `confidence_update 0003C1 ... 94`, `autogen_registry_update 0003C1 ... true -> false`, reference-index additions for [UID:0003IL]-[UID:0003IO], and `ok: 1` for scoped file validations.
- Validator-owned generated/bookkeeping outputs were refreshed during scoped validation, including `auto-generated/-ag-memory-coverage.md`. No manual edits were made to `by-memory/-coverage-report.md`.

Supervisor-applied shared-file updates:

- The supervisor applied and validated the Batch 325 `by-memory/-ignored.md` entry for [UID:0003C1] on 2026-06-12.
- The supervisor applied and validated the Batch 325 `by-memory/-coverage-report.md` replacement block for [UID:00025R], [UID:0003C1], and children [UID:0003IL]-[UID:0003IO] on 2026-06-12.
- No Batch 325 supervisor-owned shared-file updates remain pending.

## 2026-06-12 Batch 328 - Shared Leave wide string

Changed files:

- `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md`
- `by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/parent/routing decisions:

- [UID:0003G3] `SharedLeaveWideString`: `86/91 -> 88/93`, `RECONSTRUCTABLE:TRUE`, parent remains blank. Live IDA confirmed the exact `Leave` bytes, four direct consumers, and paired `Leave`/`Reconnect` alert construction in ConnectionClosedDialog, ReconnectDialog, and TerminalPane paths. [UID:0000N0] and [UID:0000OI] both clear `85/85`, but neither is the sole direct owner of the pooled literal.
- [UID:0001JD] `TerminalPaneReconnectLeaveCallback`: `84/90 -> 85/91`, parent remains [UID:0000OI]. Current direct parent [UID:0000OI] is `87/85`, so the callback's existing routing now clears the strict `85/85` gate; update only fixed stale gate text and added the exact prompt-construction evidence.
- A003 held the containing string map [UID:0003CW] and sibling [UID:0003G4] while this batch ran, so those files were read as context but not edited.

Validation commands/results:

- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md --apply --queue-timeout 240`: exited `0`; visible results included `completion_update 0003G3 ... 88`, `confidence_update 0003G3 ... 93`, reference-index additions for [UID:000036], [UID:0000BR], and [UID:0003G4], and generated report no-ops.
- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md --apply --queue-timeout 240`: exited `0`; queue was clear afterward with `queued jobs: 0`, `processing jobs: 0`.

Supervisor-applied shared-file updates:

- The supervisor applied and validated the Batch 328 `by-memory/-coverage-report.md` replacement rows for [UID:0001JD] and [UID:0003G3] on 2026-06-12.
- No Batch 328 supervisor-owned shared-file updates remain pending.

## 2026-06-12 Batch 333 - PhoneEntryDialog resource string routing

Changed files:

- `by-memory/0x0062df34-0x0062df4c.PhoneEntryDialogResourceStrings.md`
- `by-memory/0x0062dddc-0x0062df94.TerminalPhoneResourceStringsAndCallbackData.md`
- `by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md`
- `by-class/PhoneEntryDialog.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/parent/routing decisions:

- [UID:0003GW] `PhoneEntryDialogResourceStrings`: `86/90 -> 88/93`, `RECONSTRUCTABLE:TRUE`, parent blank -> [UID:0000AF]. Live IDA recheck confirmed exact UTF-16 `DLGTEL2.EPD` bytes, `sub_58D270`-only xrefs at `0x0058d314` and `0x0058d499`, and the `DLGDIAL.EPD` successor boundary at `0x0062df4c`. Direct parent [UID:0000AF][PhoneEntryDialog] is now `85/88`, so child and parent clear the strict `85/85` gate.
- [UID:0003DU] and [UID:00026N] scores unchanged; stale child-routing notes were updated to reflect [UID:0003GW] assignment.
- [UID:0000AF] score unchanged `85/88`; added [UID:0003GW] as its direct resource-string child.

Validation commands/results:

- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x0062df34-0x0062df4c.PhoneEntryDialogResourceStrings.md --apply --queue-timeout 240`: exited `0`; visible results included `completion_update 0003GW ... 88`, `confidence_update 0003GW ... 93`, and `autogen_registry_update 0003GW ... -> 0000AF`.
- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x0062dddc-0x0062df94.TerminalPhoneResourceStringsAndCallbackData.md --apply --queue-timeout 240`: exited `0`.
- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md --apply --queue-timeout 240`: exited `0`.
- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-class/PhoneEntryDialog.md --apply --queue-timeout 240`: exited `0`.
- Queue check afterward: `queued jobs: 0`, `processing jobs: 0`.

Supervisor-applied shared-file updates:

- The supervisor applied and validated the Batch 333 `by-memory/-coverage-report.md` replacement row for [UID:0003GW] on 2026-06-12.
- No Batch 333 supervisor-owned shared-file updates remain pending.

## 2026-06-12 Batch 335 - UserPane drop/target prompt string split

Changed files:

- `by-memory/0x00630a90-0x00630bd8.UserPaneDropTargetPromptStrings.md`
- `by-memory/0x00630a90-0x00630af0.DropItemConfirmationPromptString.md`
- `by-memory/0x00630af0-0x00630b10.ItemWhoTargetPromptString.md`
- `by-memory/0x00630b10-0x00630b78.SelectObjectKeyboardPromptString.md`
- `by-memory/0x00630b78-0x00630bd8.TargetObjectKeyboardPromptString.md`
- `by-memory/0x006307ec-0x00630bd8.UserPaneInputStrings.md`
- `by-class/ItemWhoInputPane.md`
- `by-class/SelectObjectWithKeyboardPane.md`
- `by-class/TargetObjectWithKeyboardPane.md`
- `by-file/ItemActionInputPanes.md`
- `by-file/TargetSelectionInputPanes.md`
- `by-class/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/parent/routing decisions:

- [UID:0002YX] `UserPaneDropTargetPromptStrings`: `87/92`, `RECONSTRUCTABLE:TRUE`, parent blank -> `90/94`, `RECONSTRUCTABLE:FALSE`, parent blank. It is now a non-emitting split index.
- [UID:0003J4] `DropItemConfirmationPromptString`: new child, `86/92`, parent [UID:0000KC]. The literal is pooled between `DropAllInputPane` and `DropInputPane`, so the item-action file is the narrowest common direct owner; parent [UID:0000KC] is `90/85`.
- [UID:0003J5] `ItemWhoTargetPromptString`: new child, `86/92`, parent [UID:00006X]. Live IDA shows inline/out-of-line `ItemWhoInputPane` construction; direct class parent improved from `84/86` to `85/87`.
- [UID:0003J6] `SelectObjectKeyboardPromptString`: new child, `86/92`, parent [UID:0000CT]. Direct class parent improved from `84/80` to `85/85`.
- [UID:0003J7] `TargetObjectKeyboardPromptString`: new child, `86/92`, parent [UID:0000ED]. Direct class parent already cleared at `86/85`; score unchanged.
- [UID:00026X] `UserPaneInputStrings`: `89/93` -> `90/94`, still `RECONSTRUCTABLE:FALSE`, parent blank after synchronizing A003's option/social split and A002's prompt split.
- [UID:0000KC] and [UID:0000OH] scores unchanged; inventories now reference the exact prompt children.

Evidence:

- Live IDA MCP `b001_nexustk` on 2026-06-12 reconfirmed xrefs for `0x00630a90`, `0x00630af0`, `0x00630b10`, `0x00630b78`, and `0x00630bd8`.
- Decompilation confirmed `0x00630a90` is used only by `sub_5B45F0` / `DropAllInputPane::OnConfirmInput` and `sub_5B4920` / `DropInputPane::OnSubmit`.
- Decompilation confirmed `0x00630af0` is the `ItemWhoInputPane` prompt used by inline construction in [UID:0001KN] and out-of-line construction in [UID:0001L4].
- Decompilation confirmed `0x00630b10` and `0x00630b78` are single-constructor prompt literals for `SelectObjectWithKeyboardPane` and `TargetObjectWithKeyboardPane`.
- `get_bytes 0x00630a90 size 328` confirmed the full UTF-16LE prompt window through the `0x00630bd8` successor boundary; sizes `0x148`, `0x60`, `0x20`, `0x68`, and `0x108` were verified with `int_convert.py`.

Validation commands/results:

- New child allocation loop: `python source-3/project-documentation/tools/validator.py --mode file --file <new child> --apply --queue-timeout 240`; exited `0`, allocated [UID:0003J4]-[UID:0003J7].
- Main validation loop over the four new children, [UID:0002YX], [UID:00026X], [UID:00006X], [UID:0000CT], [UID:0000ED], [UID:0000KC], and [UID:0000OH]: exited `0`; visible output reported expected completion/confidence/autogen parent updates and `ok: 1`.
- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-class/-coverage-report.md --apply --queue-timeout 240`: exited `0`, `ok: 1`.
- Queue check after validation: `queued jobs: 0`, `processing jobs: 0`.
- Validator also resolved an unrelated stale TMP reference for [UID:0003AW] `DialogPaneVtableData` during the queued validation; no manual edits were made to that area.

Supervisor-applied `by-memory/-coverage-report.md` replacement:

- The supervisor applied and validated the Batch 335 replacement block for [UID:00026X] through [UID:0002YX], including [UID:0003J4]-[UID:0003J7], on 2026-06-12.
- No Batch 335 supervisor-owned shared-file updates remain pending.

## 2026-06-12 Batch 338 - HeadSelectDialog secondary layout table routing

Changed files:

- `by-memory/0x0066eea0-0x0066fce4.HeadSelectDialogLayoutTableSecondary.md`
- `by-class/HeadSelectDialog.md`
- `by-file/HeadSelectDialog.md`
- `by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/parent/routing decisions:

- [UID:000281] `HeadSelectDialogLayoutTableSecondary`: `72/88 -> 86/91`, `RECONSTRUCTABLE:TRUE`, parent blank -> [UID:000062]. Direct parent [UID:000062][HeadSelectDialog] is `86/87`, and file parent [UID:0000JT][HeadSelectDialog] is `87/86`, so the strict child/direct-parent gate clears.
- [UID:000062], [UID:0000JT], and [UID:0001FI] scores unchanged; wording now records the secondary table as assigned and high-resolution.
- No split was made. Live xrefs and byte review support one high-resolution signed-offset table with 900 static dwords plus thirteen constructor-patched tail dwords, bounded by padding before/after.

Evidence:

- IDA MCP session `b001_nexustk` on 2026-06-12 reconfirmed `0x0066eea0` xrefs from `0x00551093`, `0x005513ee`, and `0x0055168b` inside `HeadSelectDialogCore`.
- IDA MCP decompilation showed the table is selected when `byte_66DA97 == 1`; `RefreshHeadPreview` and `PopulateHeadButtons` use `dword_66EEA0[index]`, and the constructor computes `this[178]` from the same table.
- IDA MCP xrefs confirmed constructor writes to tail slots `0x0066fcb0` through `0x0066fce0`; written values are `-5, -8, -2, -7, -8, -9, -3, -2, -9, -2, -10, -3, -3`.
- IDA MCP `get_bytes` decoded `0x0066eea0-0x0066fce4` as `0xe44` / 3652 bytes and `0x391` / 913 dwords, with `0x384` / 900 static entries, `0xd` / 13 zero-in-image tail slots, `0x192` / 402 nonzero bytes, and `0x69` / 105 nonzero static dwords; conversions verified with `int_convert.py`.

Validation commands/results:

- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x0066eea0-0x0066fce4.HeadSelectDialogLayoutTableSecondary.md --apply --queue-timeout 240`: exited `0`; visible results included `completion_update 000281 ... 86`, `confidence_update 000281 ... 91`, `autogen_registry_update 000281 ... -> 000062`, and `ok: 1`.
- Same scoped validator loop also validated `by-class/HeadSelectDialog.md`, `by-file/HeadSelectDialog.md`, and `by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md`; command exited `0`.

Supervisor-applied `by-memory/-coverage-report.md` replacement:

- The supervisor applied and validated the Batch 338 replacement row for [UID:000281] `HeadSelectDialogLayoutTableSecondary` on 2026-06-12.
- No Batch 338 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-12 Batch 343 - Encoder vtable-data child routing

Changed files:

- `by-memory/0x006192c8-0x006192d4.EncoderVtableData.md`
- `by-class/Encoder.md`
- `by-file/Encoder.md`
- `by-class/-coverage-report.md`
- `by-file/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/parent/routing decisions:

- [UID:0003IA] `EncoderVtableData`: `88/91 -> 89/92`, `RECONSTRUCTABLE:TRUE`, parent blank -> [UID:00004F]. Direct parent [UID:00004F][Encoder] now clears at `86/90`, so by-structure assignment to the true class owner is justified.
- [UID:00004F] `Encoder`: `82/86 -> 86/90`, parent remains [UID:0000J1].
- [UID:0000J1] `Encoder` file: `83/84 -> 85/86`, route unchanged; this supports the existing class-to-file route while retaining the Encoder/Decoder split caveat.

Evidence:

- IDA MCP session `b001_nexustk` on 2026-06-12 confirmed bytes `2c 6b 64 00 30 5e 4a 00 30 56 4a 00` for `0x006192c8-0x006192d4`, two-byte padding at `0x006192c6`, and Decoder RTTI successor bytes beginning at `0x006192d4`.
- IDA MCP confirmed `xrefs_to 0x006192cc` from `0x004a4e70`, `0x004a4ea0`, and `0x004a5e3a`; no ordinary code xrefs to `0x006192d0`; data refs from `0x006192cc` to `0x004a5e30` and from `0x006192d0` to `0x004a5630`.
- IDA MCP method lookup confirmed stable Encoder family starts/sizes including constructor `0x004a4e70`, destructor `0x004a4ea0`, writer methods `0x004a4ec0`, `0x004a4f00`, `0x004a4ff0`, `0x004a5480`, initialize/finalize `0x004a55c0`/`0x004a55e0`, no-op virtual `0x004a5630`, and scalar deleting destructor `0x004a5e30`.
- IDA MCP xrefs showed the active writer/finalize method callers remain in [UID:0000UM] `EncodeTextEditState_0058E490`, so `TextEditPane` is only a consumer and not the source owner.
- IDA MCP decompilation reconfirmed the constructor stores `off_6192CC`, clears buffer/capacity/cursor, writes flags word `0x0101`, and `Finalize` appends a zero byte, optionally reports the cursor, clears buffer/capacity/cursor, restores the valid flag, and returns the saved valid state.

Supervisor-applied `by-memory/-coverage-report.md` insertion:

- The supervisor applied and validated the Batch 343 [UID:0003IA] child-row insertion under [UID:000257] on 2026-06-12.
- No Batch 343 supervisor-owned shared-file updates remain pending.

## 2026-06-12 Batch 346 - MapPane runtime config / SelfSaveOKPane spacer split

Changed files:

- `by-memory/0x0061ea70-0x0061eaa8.MapPaneRuntimeConfigWhitespaceStrings.md`
- `by-memory/0x0061ea70-0x0061ea8c.MapPaneMscfgDllPathFormatString.md`
- `by-memory/0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString.md`
- `by-memory/0x0061e908-0x0061eadc.MapPaneResourceStrings.md`
- `by-memory/0x0061e704-0x0061eb08.MapPaneGameServerReadOnlyData.md`
- `by-file/MapPane.md`
- `by-class/SelfSaveOKPane.md`
- `by-file/SelfSaveOKPane.md`
- `by-file/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/parent/routing decisions:

- [UID:0003IY] `MapPaneRuntimeConfigWhitespaceStrings`: `86/90 -> 90/94`, `RECONSTRUCTABLE:FALSE`, parent remains blank. The original range is a non-emitting split index because it spans two true direct owners.
- New [UID:0003JK] `MapPaneMscfgDllPathFormatString`: `88/93`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000L3][MapPane]. Direct parent [UID:0000L3] clears at `89/85`.
- New [UID:0003JL] `SelfSaveOKPaneSpacerString`: `88/93`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000CX][SelfSaveOKPane]. Direct parent [UID:0000CX] clears at `88/86`.
- [UID:0000NN] `SelfSaveOKPane` file: `86/80 -> 87/85` to support the existing class/file route with exact spacer evidence.

Evidence:

- IDA MCP session `a002_batch346` confirmed `0x0061ea70-0x0061eaa8` is `0x38` / 56 bytes: UTF-16 `%s\Mscfg.dll`, a zero/alignment word, UTF-16 twelve-space spacer, a zero/alignment word, then successor `vector<bool> too long` at `0x0061eaa8`.
- `int_convert.py` confirmed each child is `0x1c` / 28 bytes.
- IDA MCP `xrefs_to` confirmed `%s\Mscfg.dll` references at `0x00508a42` inside `sub_507C90` and a raw duplicate at `0x005142ba`; decompilation shows the MapPane dispatcher formatting `L"%s\\Mscfg.dll"` into a runtime/config path buffer.
- IDA MCP `xrefs_to` confirmed the twelve-space spacer is used at `0x00508550` and `0x00508593` in `sub_507C90`, `0x00513866` and `0x005138a9` in `sub_513800`, and `0x0051481b` and `0x00514861` in `sub_5147D0`.
- IDA MCP decompilation of `sub_513800` and `sub_5147D0` shows the spacer passed to the text helper around localized string id `61`, matching SelfSaveOKPane construction/factory/inline MapPane packet-case ownership.

Validation commands/results:

- New child allocation loop: `python source-3/project-documentation/tools/validator.py --mode file --file <new child> --apply --queue-timeout 240`; exited `0`, allocated [UID:0003JK] and [UID:0003JL].
- Main validation loop over the two new children, [UID:0003IY], [UID:0002ST], [UID:00025S], [UID:0000L3], [UID:0000CX], [UID:0000NN], and `by-file/-coverage-report.md`: exited `0`; visible output showed expected completion/confidence/autogen registry updates and `ok: 1`.
- Registry/header checks after validation confirmed [UID:0003JK] assigned to [UID:0000L3], [UID:0003JL] assigned to [UID:0000CX], and [UID:0003IY] left parentless/non-reconstructable.

Supervisor-applied `by-memory/-coverage-report.md` changes:

- The supervisor applied and validated the Batch 346 replacement/insert rows for [UID:00025S], [UID:0002ST], [UID:0003IY], [UID:0003JK], and [UID:0003JL] on 2026-06-12.
- No Batch 346 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-12 Goal2 - StartupLogoBinkPlaybackLoop split repair

Changed files:

- `by-memory/0x004f5710-0x004f5ac7.StartupLogoBinkPlaybackLoop.md`
- `by-memory/0x004f5710-0x004f59c6.PlayStartupLogoBinkFile.md`
- `by-memory/0x004f59d0-0x004f5ac7.StartupLogoBinkWndProc.md`
- `by-file/StartupLogoPanes.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/parent/routing decisions:

- [UID:00022T] `StartupLogoBinkPlaybackLoop`: `72/88 -> 90/93`, `RECONSTRUCTABLE:TRUE -> FALSE`, parent [UID:0000O4] -> blank. The page is now a non-emitting split index over exact source children.
- New [UID:0003K6] `PlayStartupLogoBinkFile`: `87/92`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000O4][StartupLogoPanes]. Direct parent clears at `88/85`.
- New [UID:0003K7] `StartupLogoBinkWndProc`: `86/92`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000O4][StartupLogoPanes]. Direct parent clears at `88/85`.
- [UID:0000O4] `StartupLogoPanes`: score unchanged at `88/85`; content now records the exact child split and routing.

Evidence:

- IDA MCP session `a002_batch346` on 2026-06-12 confirmed `sub_4F5710` at `0x004f5710` size `0x2b6` / 694 bytes, `sub_4F59D0` at `0x004f59d0` size `0xf7` / 247 bytes, next modeled `sub_4F5AD0` at `0x004f5ad0`, and child helper `sub_4F5AE0` at `0x004f5ae0` size `0x3e`.
- IDA MCP `get_bytes` confirmed four `0xcc` bytes at `0x004f570c-0x004f5710`, ten `0xcc` bytes at `0x004f59c6-0x004f59d0`, and nine `0xcc` bytes at `0x004f5ac7-0x004f5ad0`; conversions were verified with `int_convert.py`.
- IDA MCP `xrefs_to` confirmed the playback helper has one direct code xref from application startup at `0x004f63b5`, the WndProc has one install xref from `0x004f585d`, and the WndProc calls the midpoint/restart helper at `0x004f5aaf`.
- IDA MCP decompilation confirmed the playback helper selects `LOGO.PAK`/`LOGO.PAD`, reads a segmented `_AUTOBUF<unsigned char>` payload, opens Bink with flags `0x04080000`, opens a Bink buffer, installs/restores the WndProc, pumps messages/frames, closes Bink, and invokes optional callback state.
- IDA MCP decompilation confirmed the WndProc signature and message behavior: paint black, suppress erase background, consume close/destroy/input messages, call the midpoint/restart helper for `WM_KEYDOWN` and `WM_LBUTTONDOWN`, and forward unrelated messages to `DefWindowProcW`.

Validation commands/results:

- Child allocation loop: `python source-3/project-documentation/tools/validator.py --mode file --file <new child> --apply --lock-timeout 240`; exited `0`, allocated [UID:0003K6] and [UID:0003K7].
- Main validation loop over [UID:0003K6], [UID:0003K7], [UID:00022T], and [UID:0000O4]: exited `0`; visible output showed expected score/autogen updates and `ok: 1`.
- Follow-up validator run on [UID:00022T] after correcting the `ApplicationStartup` UID reference exited `0`; visible output removed stale reference to [UID:00019F] and added [UID:0002H7].

Supervisor-applied `by-memory/-coverage-report.md` changes:

- The supervisor applied and validated the Goal2 [UID:00022T], [UID:0003K6], [UID:0003K7], and adjacent padding replacement block on 2026-06-12.
- No Goal2 StartupLogoBinkPlaybackLoop supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-12 Goal2 - StartupLogoBinkMidpointRestart supervisor-applied rows

- The supervisor applied and validated the Goal2 [UID:00022U][0x004f5ae0-0x004f5b1e.StartupLogoBinkMidpointRestart](../../../by-memory/0x004f5ae0-0x004f5b1e.StartupLogoBinkMidpointRestart.md) and [UID:00029G][0x0069b45c-0x0069b480.StartupLogoBinkPlaybackGlobals](../../../by-memory/0x0069b45c-0x0069b480.StartupLogoBinkPlaybackGlobals.md) `by-memory/-coverage-report.md` replacement rows on 2026-06-12.
- Validation command: `python .\source-3\project-documentation\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240`.
- No Goal2 StartupLogoBinkMidpointRestart supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-12 Goal2 - DecoderPrimitiveReaders split repair

Changed files:

- `by-memory/0x004a5680-0x004a568d.DecoderSetByteOrder.md`
- `by-memory/0x004a5690-0x004a56b8.DecoderReadByte.md`
- `by-memory/0x004a56c0-0x004a570f.DecoderReadShort.md`
- `by-memory/0x004a5710-0x004a576f.DecoderReadTriByte.md`
- `by-memory/0x004a5770-0x004a57dc.DecoderReadInt.md`
- `by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md`
- `by-memory/0x004a5680-0x004a5dce.DecoderRawReaderFamily.md`
- `by-class/Decoder.md`
- `by-file/Decoder.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/parent/routing decisions:

- [UID:00013P] `DecoderPrimitiveReaders`: `74/84 -> 90/92`, `RECONSTRUCTABLE:TRUE -> FALSE`, parent [UID:00013Q] position 10 -> blank. The page is now a non-emitting split index over exact raw primitive reader children.
- New [UID:0003K8] `DecoderSetByteOrder`: `87/91`, `RECONSTRUCTABLE:TRUE`, parent [UID:00003M][Decoder], position 30.
- New [UID:0003K9] `DecoderReadByte`: `87/91`, `RECONSTRUCTABLE:TRUE`, parent [UID:00003M][Decoder], position 40.
- New [UID:0003KA] `DecoderReadShort`: `86/90`, `RECONSTRUCTABLE:TRUE`, parent [UID:00003M][Decoder], position 50.
- New [UID:0003KB] `DecoderReadTriByte`: `86/90`, `RECONSTRUCTABLE:TRUE`, parent [UID:00003M][Decoder], position 60.
- New [UID:0003KC] `DecoderReadInt`: `86/90`, `RECONSTRUCTABLE:TRUE`, parent [UID:00003M][Decoder], position 70.
- [UID:00013Q] `DecoderRawReaderFamily`: `76/84 -> 85/88`, parent remains [UID:00003M], position 30. It is a reader-family index retaining [UID:00013R] as its lower-completion string/blob aggregate for later work.
- [UID:00003M] `Decoder` class and [UID:0000IQ] `Decoder` file remain `85/86`; both were updated to reference the exact primitive reader children.

Evidence:

- IDA MCP `lookup_funcs` reports no function object at `0x004a5680`, `0x004a5690`, `0x004a56c0`, `0x004a5710`, `0x004a5770`, or successor `0x004a57e0`, so the original target was a packed raw island rather than a single function.
- IDA MCP `insn_query 0x004a5680-0x004a57e0` decoded all five bodies and returned no owning `fn` metadata for the primitive instructions.
- IDA MCP `get_bytes` confirmed exact body and padding boundaries: `0x004a5680-0x004a568d`, three `0xcc`; `0x004a5690-0x004a56b8`, eight `0xcc`; `0x004a56c0-0x004a570f`, one `0xcc`; `0x004a5710-0x004a576f`, one `0xcc`; `0x004a5770-0x004a57dc`, four `0xcc`.
- Decoded behavior: `SetByteOrder` stores the byte argument at Decoder offset `+0x10`; `ReadByte` checks valid flag `+0x11`, bounds against limit `+0x08`, reads from base `+0x04` plus cursor `+0x0c`, advances one byte, and clears valid on underflow; the 2/3/4-byte readers repeat the same valid/cursor/limit pattern and branch on byte-order flag `+0x10`.
- Existing Decoder parent docs support direct routing: [UID:00003M] is `85/86` and models the constructor/destructor/vtable plus storage layout used by these readers.

Validation commands/results:

- UID allocation loop: `python source-3/project-documentation/tools/validate_docs.py --strict --path <new child>` for each new child; exited `0` and allocated [UID:0003K8] through [UID:0003KC].
- Main validation loop: `python source-3/project-documentation/tools/validate_docs.py --strict --path <file>` over the five new children, [UID:00013P], [UID:00013Q], `by-class/Decoder.md`, and `by-file/Decoder.md`; all exited `0` with `ok: 1`.
- Generated side effects from validation: [UID:00013P] was removed from project low-completion/low-both stats and from reconstructable by-memory coverage because it is now non-reconstructable; exact children were added to generated memory coverage under [UID:00003M].

Supervisor-applied `by-memory/-coverage-report.md` update:

- The supervisor applied and validated the Goal2 DecoderPrimitiveReaders replacement/insert block for [UID:00013Q], [UID:00013P], [UID:00013R], child rows [UID:0003K8]-[UID:0003KC], and adjacent padding rows on 2026-06-12.
- Validation command: `python .\source-3\project-documentation\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240`.
- No Goal2 DecoderPrimitiveReaders supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-12 Goal2 - DecoderStringAndBlobReaders split repair

Changed files:

- `by-memory/0x004a57e0-0x004a5861.DecoderReadWideString8.md`
- `by-memory/0x004a5870-0x004a5925.DecoderReadWideString16.md`
- `by-memory/0x004a5930-0x004a5a3a.DecoderReadAnsiString8.md`
- `by-memory/0x004a5a40-0x004a5ba7.DecoderReadAnsiString16.md`
- `by-memory/0x004a5bb0-0x004a5c7e.DecoderReadCString.md`
- `by-memory/0x004a5c80-0x004a5cc4.DecoderReadBytes.md`
- `by-memory/0x004a5cd0-0x004a5d79.DecoderReadCompressedBytes.md`
- `by-memory/0x004a5d80-0x004a5da6.DecoderSkipBytes.md`
- `by-memory/0x004a5db0-0x004a5dce.DecoderInitialize.md`
- `by-memory/0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders.md`
- `by-memory/0x004a5680-0x004a5dce.DecoderRawReaderFamily.md`
- `by-class/Decoder.md`
- `by-file/Decoder.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/parent/routing decisions:

- [UID:00013R] `DecoderStringAndBlobReaders`: `74/84 -> 90/92`, `RECONSTRUCTABLE:TRUE -> FALSE`, parent [UID:00013Q] position 20 -> blank. The page is now a non-emitting split index.
- [UID:00013Q] `DecoderRawReaderFamily`: `85/88 -> 90/92`, `RECONSTRUCTABLE:TRUE -> FALSE`, parent [UID:00003M] position 30 -> blank. It is now a non-emitting raw-reader family index because both subranges have exact children.
- New [UID:0003L6] `DecoderReadWideString8`: `87/90`, parent [UID:00003M][Decoder], position 71.
- New [UID:0003L7] `DecoderReadWideString16`: `87/90`, parent [UID:00003M][Decoder], position 72.
- New [UID:0003L8] `DecoderReadAnsiString8`: `86/89`, parent [UID:00003M][Decoder], position 73.
- New [UID:0003L9] `DecoderReadAnsiString16`: `86/89`, parent [UID:00003M][Decoder], position 74.
- New [UID:0003LA] `DecoderReadCString`: `86/89`, parent [UID:00003M][Decoder], position 75.
- New [UID:0003LB] `DecoderReadBytes`: `87/91`, parent [UID:00003M][Decoder], position 76.
- New [UID:0003LC] `DecoderReadCompressedBytes`: `86/88`, parent [UID:00003M][Decoder], position 77.
- New [UID:0003LD] `DecoderSkipBytes`: `88/91`, parent [UID:00003M][Decoder], position 78.
- New [UID:0003LE] `DecoderInitialize`: `88/91`, parent [UID:00003M][Decoder], position 79.
- [UID:00003M] `Decoder` class: `85/86 -> 87/88`.
- [UID:0000IQ] `Decoder` file: `85/86 -> 86/87`.

Evidence:

- Live IDA MCP session `a002_batch346` on 2026-06-12 reports every string/blob raw start `0x004a57e0`, `0x004a5870`, `0x004a5930`, `0x004a5a40`, `0x004a5bb0`, `0x004a5c80`, `0x004a5cd0`, `0x004a5d80`, and `0x004a5db0` as `Not a function`, with zero direct code/data xrefs.
- Live IDA MCP `insn_query` decoded each exact child body with no owning `fn`, and `get_bytes` confirmed every body plus `0xcc` padding span through the next modeled function at `0x004a5dd0`.
- `tools/int_convert.py` verified child and padding sizes: body sizes `0x81`/129, `0xb5`/181, `0x10a`/266, `0x167`/359, `0xce`/206, `0x44`/68, `0xa9`/169, `0x26`/38, `0x1e`/30 bytes; padding sizes `0x0f`/15, `0x0b`/11, `0x06`/6, `0x09`/9, `0x02`/2, `0x0c`/12, `0x07`/7, `0x0a`/10, `0x02`/2 bytes.
- The renamed compressed reader is justified by `lookup_funcs 0x00414390`, existing zlib docs [UID:0000W2], and the call setup matching `uncompress(out, &producedSize, source, compressedLength)`.

Validation commands/results:

- UID allocation loop: `python tools\validator.py --mode file --file <new child> --apply --queue-timeout 240`; exited `0`, allocated [UID:0003L6] through [UID:0003LE].
- Main validation loop: `python tools\validator.py --mode file --file <file> --apply --queue-timeout 240` over the nine new children, [UID:00013R], [UID:00013Q], `by-class/Decoder.md`, and `by-file/Decoder.md`; exited `0` for every file with visible `ok: 1`.
- Generated side effects from validation: [UID:0003L6]-[UID:0003LE] appear assigned under [UID:00003M] in `auto-generated/-ag-memory-coverage.md`; [UID:00013Q] and [UID:00013R] moved to `not_reconstructable`; [UID:00013R] no longer appears in `project-level/-auto-completion-stats.md`.

Supervisor-applied `by-memory/-coverage-report.md` update:

- The supervisor applied and validated the Goal 2 DecoderStringAndBlobReaders replacement/insert block for [UID:00013Q], [UID:00013R], and exact child rows [UID:0003L6]-[UID:0003LE] on 2026-06-12.
- Validation command: `python .\source-3\project-documentation\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240`.
- No Goal 2 DecoderStringAndBlobReaders supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-12 Goal2 - ParcelPaneOnPaint live refresh

Changed files:

- `by-memory/0x00546890-0x0054696f.ParcelPaneOnPaint.md`
- `by-class/ParcelPane.md`
- `by-class/-coverage-report.md`
- `by-memory/-ignored.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/parent/routing decisions:

- [UID:0002KG] `ParcelPaneOnPaint`: `74/84 -> 87/90`; `RECONSTRUCTABLE:TRUE`; parent remains [UID:0000A6][ParcelPane], position `70`. The child now clears 85/85 with exact IDA evidence.
- [UID:0000A6] `ParcelPane` class: `84/80 -> 86/86`; parent remains [UID:0000MF][ParcelPane] file, position `10`. The direct parent now clears 85/85, so the existing method assignment is justified under the corrected gate.
- `by-class/-coverage-report.md` row for [UID:0000A6] was updated directly under lease.
- Added `0x0054696f-0x00546970` to `by-memory/-ignored.md` as one confirmed `0xcc` alignment byte between `ParcelPaneOnPaint` and `ParcelPaneUpdateAnimationCounter`.

Evidence:

- IDA MCP session `a002_batch346` on 2026-06-12 reports `sub_546890` at `0x00546890` size `0xdf` / 223 bytes (Verified with int_convert.py), no function at `0x0054696f`, and next function `sub_546970` at `0x00546970`.
- IDA MCP `get_bytes` confirms the full paint body and single successor byte `0xcc` at `0x0054696f`.
- IDA MCP `xrefs_to 0x00546890` reports the only direct xref at `0x00621c80`, matching the `ParcelPane` primary paint vtable slot.
- IDA MCP `analyze_function`, `disasm`, and `callees` show a straight-line 78-instruction body calling `0x00457a60`, `0x004b9660`, indirect `dword_69B3FC`, `0x004d02f0`, `0x004b9980`, and the security-cookie check.
- IDA MCP resource-string xrefs confirm `ALERTBTN.EPF` at `0x00621d50` is referenced by this method at `0x005468e7` and `0x00546937`; `ALERTBTN.PAL` at `0x00621d6c` is referenced at `0x005468f3` and `0x00546943`.
- IDA MCP `analyze_component` over the main `ParcelPane` method cluster reconfirmed constructor/destructor/vtable shared globals at `0x00621c3c`, `0x00621c90`, and `0x00621cc0`.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-memory/0x00546890-0x0054696f.ParcelPaneOnPaint.md --apply --queue-timeout 240`: exited `0`; visible output included `completion_update 0002KG ... 87`, `confidence_update 0002KG ... 90`, UID link insertions, and removal of [UID:0002KG] from low-completion/low-both/by-memory completion stats.
- Scoped validation loop also ran the same validator command for `by-class/ParcelPane.md`, `by-memory/-ignored.md`, and `by-class/-coverage-report.md`; loop exited `0`.
- Generated checks after validation: `auto-generated/-ag-memory-coverage.md` still lists [UID:0002KG] assigned to [UID:0000A6] at position `70`; `project-level/-auto-completion-stats.md` no longer lists [UID:0002KG].

Supervisor-applied `by-memory/-coverage-report.md` update:

- The supervisor applied and validated the Goal 2 ParcelPaneOnPaint replacement row for [UID:0002KG] and the new `0x0054696f-0x00546970` padding row on 2026-06-12.
- Validation command: `python .\source-3\project-documentation\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240`.
- No Goal 2 ParcelPaneOnPaint supervisor-owned shared-file rows remain pending.

## 2026-06-12 Goal2 - FlyingParcelPaneConstructor live refresh

Changed files:

- `by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md`
- `by-class/FlyingParcelPane.md`
- `by-class/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/parent/routing decisions:

- [UID:0002KJ] `FlyingParcelPaneConstructor`: `74/84 -> 87/90`; `RECONSTRUCTABLE:TRUE`; parent remains [UID:000058][FlyingParcelPane], position `10`.
- [UID:000058] `FlyingParcelPane`: `82/84 -> 85/86`; parent remains [UID:0000MF][ParcelPane], position `30`.
- [UID:0000MF] `ParcelPane` was read as the direct file parent and remains `86/85`, so the class-to-file route and constructor-to-class route both clear the strict 85/85 gate. Final C++ remains blank below the 95/95 gate.

Evidence:

- Live IDA MCP session `a002_batch346` on 2026-06-12 reports `sub_546AC0` at `0x00546ac0`, size `0xb4` / 180 bytes, and no function at `0x00546b74` or `0x00546b80`.
- `tools/int_convert.py` verified `0xb4` / 180 bytes, `0xc` / 12 bytes of successor padding, `0x8` / 8-byte helper allocation, and `0x104` / 260-byte offset conversion.
- Live IDA MCP decompile/disassembly shows base Pane construction with flag `1`, vtable writes at `+0x00/+0xa0/+0xa4` to `0x00621ccc/0x00621d18/0x00621d48`, payload clears at `+0xf8/+0xfc`, helper allocation through `0x004f4aa0`, helper setup through `0x004f0480`, and storage at `+0x100`.
- Live IDA MCP `get_bytes` confirms the constructor body and twelve `0xcc` bytes at `0x00546b74-0x00546b80`; the existing ignored padding row remains correct.
- Live IDA MCP `xrefs_to` confirms `FlyingParcelPane` constructor, raw cleanup, and scalar destructor write the same three vtable bases, tying the target to the direct class owner.

Validation commands/results:

- Scoped validation loop exited `0`: `python .\tools\validator.py --mode file --file <edited by-* file> --apply --queue-timeout 240` for `by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md`, `by-class/FlyingParcelPane.md`, and `by-class/-coverage-report.md`.
- Visible validator output for the target included `completion_update 0002KJ ... 87`, `confidence_update 0002KJ ... 90`, `ok: 1`, and removal of [UID:0002KJ] from project low-completion/low-both/by-memory completion stats.
- Post-validation checks: `auto-generated/-ag-memory-coverage.md` still lists [UID:0002KJ] assigned to parent `000058` at position `10`; `project-level/-auto-completion-stats.md` no longer lists `0002KJ` or `FlyingParcelPaneConstructor`; `by-class/-coverage-report.md` row [UID:000058] now reports `85% : strong`.

Supervisor-applied `by-memory/-coverage-report.md` update:

- The supervisor applied and validated the Goal 2 FlyingParcelPaneConstructor replacement row for [UID:0002KJ] on 2026-06-12.
- Validation command: `python .\source-3\project-documentation\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240`.
- No Goal 2 FlyingParcelPaneConstructor supervisor-owned shared-file rows remain pending.

## 2026-06-12 Goal2 - FlyingParcelPaneDrawParcelOrLetter live refresh

Changed files:

- `by-memory/0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md`
- `by-memory/-ignored.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Read but not edited:

- `by-class/FlyingParcelPane.md` was read as the direct parent. It already clears the gate at `85/86`; no parent update was needed.
- `by-class/-coverage-report.md` was not edited because the direct class parent score did not change.
- `by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md` was read for adjacent-boundary context only; A004 was assigned the adjacent [UID:0002KK] work, so no changes were made there.

Score/parent/routing decisions:

- [UID:0002KL] `FlyingParcelPaneDrawParcelOrLetter`: `74/84 -> 88/91`; `RECONSTRUCTABLE:TRUE`; parent remains [UID:000058][FlyingParcelPane](../../../by-class/FlyingParcelPane.md), position `50`.
- [UID:000058] `FlyingParcelPane` remains `85/86`; parent remains [UID:0000MF][ParcelPane](../../../by-file/ParcelPane.md), position `30`.
- The route is justified because the child now clears 85/85, the direct class parent already clears 85/85, and [UID:0002OH][ParcelNotificationVtableData](../../../by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md) proves the `FlyingParcelPane` primary draw slot at `0x00621d10 -> 0x00546df0`.
- No split was required: IDA models one exact function body at `0x00546df0-0x00546e6b`; adjacent byte gaps are `0xcc` alignment padding now recorded in `by-memory/-ignored.md`.
- Final C++ remains blank because the page is below the 95/95 final-code gate.

Evidence:

- Live IDA MCP session `a002_batch346` on 2026-06-12 reports `sub_546DF0` at `0x00546df0`, size `0x7b` / 123 bytes, ending at `0x00546e6b`; `tools/int_convert.py` verified the size conversion.
- Live IDA MCP `lookup_funcs` reports no function at `0x00546e6b` and the next modeled function [UID:0002KM][ClearParcelIconPaneSingleton](../../../by-memory/0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton.md) at `0x00546e70`.
- Live IDA MCP `get_bytes` confirms the full function body plus two predecessor padding bytes at `0x00546dee-0x00546df0`, five successor padding bytes at `0x00546e6b-0x00546e70`, and five more padding bytes at `0x00546e7b-0x00546e80`.
- Live IDA MCP `xrefs_to 0x00546df0` reports one data xref from `0x00621d10`, matching the `FlyingParcelPane` primary vtable draw slot.
- Live IDA MCP decompile/disassembly shows the method initializes an EPF tile context, branches on `this+0xfc`, uses `g_pEPFLib` with `ResourceLayoutTableLookupLayoutEntry`, chooses `ALERTBTN.EPF` frame `5` plus `ALERTBTN.PAL` for parcel mode or `LETTER.EPF` frame `0` plus `LETTER.PAL` for letter mode, then renders through `0x004b9980` into `this+0x44`.
- `tools/int_convert.py` verified recorded conversions for `0x7b` / 123 bytes, `0x7e` / 126 bytes, `0x44` / 68, `0xfc` / 252, `0x5` / 5, and `0x2` / 2.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-memory/0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md --apply --queue-timeout 240`: exited `0`; visible output included `completion_update 0002KL ... 88`, `confidence_update 0002KL ... 91`, `ok: 1`, and removal of [UID:0002KL] from Low_Completion, Low_Both, and by-memory project stats.
- `python .\tools\validator.py --mode file --file by-memory/-ignored.md --apply --queue-timeout 240`: exited `0`; visible output included `ok: 1` and reference index additions for [UID:0002KK], [UID:0002KL], and [UID:0002KM].
- Post-validation checks: `auto-generated/-ag-memory-coverage.md` still lists [UID:0002KL] assigned to parent `000058` at position `50`; `project-level/-auto-completion-stats.md` no longer lists `0002KL` or `FlyingParcelPaneDrawParcelOrLetter`; `by-memory/-ignored.md` contains the new `0x00546dee-0x00546df0`, `0x00546e6b-0x00546e70`, and `0x00546e7b-0x00546e80` padding entry.

Supervisor-applied `by-memory/-coverage-report.md` update:

- The supervisor applied and validated the Goal 2 [UID:0002KL] replacement row and adjacent padding rows on 2026-06-12.
- The supervisor preserved A004's already-validated [UID:0002KK] `87% : very-strong` row while applying this batch's placement changes.
- No Goal 2 [UID:0002KL] supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-12 Goal2 - SelfLookPaneSummaryStatUpdate live refresh

Changed files:

- `by-memory/0x0056b7c0-0x0056b946.SelfLookPaneSummaryStatUpdate.md`
- `by-memory/-ignored.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Validator-owned/generated side effects:

- `auto-generated/-ag-memory-coverage.md`
- `project-level/-auto-completion-stats.md`
- `tools/validator.ini`

Score/parent/routing decisions:

- [UID:0002RE] `SelfLookPaneSummaryStatUpdate`: `74/84 -> 86/90`; `RECONSTRUCTABLE:TRUE`; parent [UID:0000NL][SelfLookPane](../../../by-file/SelfLookPane.md) position `25` -> [UID:0000CU][SelfLookPane](../../../by-class/SelfLookPane.md), optional position blank.
- [UID:0000CU] `SelfLookPane` direct class parent was read as `85/88`; [UID:0000NL] file parent was read as `85/89`. The reroute is justified because the child and true direct class parent both clear the strict 85/85 gate.
- No split was required. Live IDA models one exact function at `0x0056b7c0-0x0056b946`; the successor gap `0x0056b946-0x0056b950` is confirmed `0xcc` padding and was added to `by-memory/-ignored.md`.
- Final C++ remains blank below the 95/95 final-code gate.

Evidence:

- Live IDA MCP session `a002_batch346` on 2026-06-12 reports `sub_56B7C0` at `0x0056b7c0`, size `0x186` / 390 bytes, no function at `0x0056b946`, and next modeled [UID:0002RF][SelfLookPaneSpelledTextDispatch](../../../by-memory/0x0056b950-0x0056b9ef.SelfLookPaneSpelledTextDispatch.md) at `0x0056b950`, size `0x9f` / 159 bytes.
- Live IDA MCP `xrefs_to 0x0056b7c0` reports one code xref from `0x0056972f` in the modeled `SelfLookPane` packet/event handler; `xrefs_to 0x0056b946` and `xrefs_to 0x0056b950` report no direct xrefs.
- Live IDA MCP decompile/disassembly shows event-handler case `8` calling the helper with packet pointer and adjusted `SelfLookPane` instance (`this - 0xa0`), packet mask byte at `packet+1`, bit-controlled cursor arithmetic for `0x40/0x20/0x10/0x08/0x01`, packet dword reads through `0x005754c0`, dirty checks against `this+0x1f0c/+0x1f10`, writes to `this+0x1f14/+0x1f15/+0x1f16/+0x1f18` only on change, and redraw through `[vtable+0x20]` with `this+0x44`.
- The stale `this+0x1f1c` claim was removed; live evidence shows no `+0x1f1c` access in this helper.
- `tools/int_convert.py` verified all recorded decimal/hex conversions, including `0x186`/390, `0x9f`/159, `0xa0`/160, `0xa`/10, `0x20`/32, `0x44`/68, and offsets `0x1f0c`, `0x1f10`, `0x1f14`, `0x1f15`, `0x1f16`, and `0x1f18`.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-memory/0x0056b7c0-0x0056b946.SelfLookPaneSummaryStatUpdate.md --apply --queue-timeout 240`: exited `0`; visible output included `completion_update 0002RE ... 86`, `confidence_update 0002RE ... 90`, `autogen_registry_update 0002RE ... 0000NL -> 0000CU`, position `25 ->`, `ok: 1`, and removal of [UID:0002RE] from Low_Both and by-memory project stats.
- `python .\tools\validator.py --mode file --file by-memory/-ignored.md --apply --queue-timeout 240`: exited `0`; visible output included `ok: 1`, reference index additions for [UID:0002RE] and [UID:0002RF], and pre-existing missing-ref/autogen-stale warnings for old image-library paths unrelated to this batch.
- Post-validation checks: `auto-generated/-ag-memory-coverage.md` now lists [UID:0002RE] assigned to parent `0000CU` with blank position; `project-level/-auto-completion-stats.md` no longer lists `0002RE` or `SelfLookPaneSummaryStatUpdate`; `by-memory/-ignored.md` contains the new `0x0056b946-0x0056b950` padding entry.

Supervisor-applied `by-memory/-coverage-report.md` update:

- The supervisor applied and validated the Goal 2 [UID:0002RE] replacement row and the `0x0056b946-0x0056b950` padding row on 2026-06-12.
- No Goal 2 [UID:0002RE] supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-12 Goal2 - SelfLookPaneSpelledTextDispatch live refresh

Changed files:

- `by-memory/0x0056b950-0x0056b9ef.SelfLookPaneSpelledTextDispatch.md`
- `by-memory/0x0056a380-0x0056ba99.SelfLookPanePacketUpdateHelpers.md`
- `by-memory/-ignored.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Supervisor-applied `by-memory/-coverage-report.md` update:

- Supervisor applied and validated the pending [UID:0002RF] replacement row and `0x0056b9ef-0x0056b9f0` padding row on 2026-06-12. No pending supervisor-owned rows remain for this item.

## 2026-06-12 Goal2 - ClearGlobalTimerMgr live refresh

Changed files:

- `by-memory/0x00597fd0-0x00597fdb.ClearGlobalTimerMgr.md` (renamed from `by-memory/0x00597fd0-0x00597fda.ClearGlobalTimerMgr.md`)
- `by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md`
- `by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md`
- `by-memory/-ignored.md`
- `by-global/g_pTimerMgr.md` (validator UID-link refresh only)
- `tools/leaser/Agents/Agent-A002/notes.md`

Validator-owned/generated side effects:

- `auto-generated/-ag-memory-coverage.md`
- `project-level/-auto-completion-stats.md`
- `tools/validator.ini`
- `by-memory/-coverage-report.md` link annotation was refreshed by validator during the target rename scan, but the row content remains supervisor-owned and stale pending the exact replacement below.

Score/parent/routing decisions:

- [UID:0002L2] `ClearGlobalTimerMgr`: `74/84 -> 86/90`; range repaired from stale `0x00597fd0-0x00597fda` to exact half-open `0x00597fd0-0x00597fdb`; `RECONSTRUCTABLE:TRUE`; parent remains [UID:0000OT][TimerMgr](../../../by-file/TimerMgr.md), optional position blank.
- [UID:0000OT] direct file parent was read as `90/86`, so the existing route satisfies the strict child/direct-parent gate after this refresh.
- No class reroute was made. The helper has no receiver use or independent method body; the only observed code xref is a TimerMgr constructor EH cleanup funclet at `0x00609b5e`, so the direct source owner remains the file-level TimerMgr module rather than the `TimerMgr` class page or the `g_pTimerMgr` global page.
- No split was required. IDA models one 11-byte function at `0x00597fd0`; `0x00597fdb-0x00597fe0` remains padding before the queue destructor at `0x00597fe0`.
- Final C++ remains blank below the 95/95 final-code gate.

Evidence:

- Live IDA MCP session `a002_batch_clear_timer` on 2026-06-12 reports `sub_597FD0` at `0x00597fd0`, size `0x0b` / 11 bytes, with `0x00597fda` still inside the function and `0x00597fdb` not a function.
- Live IDA MCP decompile/disassembly shows a single `unk_67AB80 = 0` write and `retn` at `0x00597fda`.
- Live IDA MCP `get_bytes` at `0x00597fd0` returns `c7 05 80 ab 67 00 00 00 00 00 c3 cc cc cc cc cc`, proving the `retn` byte and five successor `0xcc` padding bytes.
- Live IDA MCP `lookup_funcs` reports the next modeled function [UID:0002L3][0x00597fe0-0x00598083.TimerMgrTimerQueueDestructor](../../../by-memory/0x00597fe0-0x00598083.TimerMgrTimerQueueDestructor.md) at `0x00597fe0`, size `0xa3` / 163 bytes.
- Live IDA MCP `xrefs_to 0x00597fd0` reports one code xref at `0x00609b5e`; disassembly of `sub_5976C0` shows this is the constructor EH cleanup funclet (`mov ecx, [ebp+var_10]`, `add ecx, 4`, `jmp sub_597FD0`).
- Live IDA MCP `callees 0x00597fd0` reports no callees; `find_bytes` found no little-endian address literals for `0x00597fd0`, `0x00597fda`, `0x00597fdb`, or `0x00597fe0`.
- `tools/int_convert.py` verified recorded conversions for `0x0b` / 11, `0xa3` / 163, `0xc0` / 192, `0x5` / 5, `0x4` / 4, `0x20` / 32, and `0x18` / 24.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-memory\0x00597fd0-0x00597fdb.ClearGlobalTimerMgr.md --apply --queue-timeout 240`: exited `0`; visible output included `path_update 0002L2 ... 0x00597fda... -> 0x00597fdb...`, `completion_update 0002L2 ... 86`, `confidence_update 0002L2 ... 90`, `stats_row_remove 0002L2 ... Low_Both`, `stats_row_remove 0002L2 ... by-memory`, and `ok: 1`.
- Scoped validation loop exited `0`: `python .\tools\validator.py --mode file --file <changed related file> --apply --queue-timeout 240` for `by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md`, `by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md`, `by-memory/-ignored.md`, and `by-global/g_pTimerMgr.md`; each visible run included `ok: 1`.
- Post-validation checks: `auto-generated/-ag-memory-coverage.md` now lists [UID:0002L2] at `by-memory/0x00597fd0-0x00597fdb.ClearGlobalTimerMgr.md`; `project-level/-auto-completion-stats.md` no longer lists [UID:0002L2] or `ClearGlobalTimerMgr`; by-* docs no longer contain stale old-path UID annotations except historical prose documenting the repaired stale range.

Supervisor-applied `by-memory/-coverage-report.md` replacement:

- Applied by supervisor on 2026-06-12 between the `0x00597fc9-0x00597fd0` padding row and the `0x00597fdb-0x00597fe0` padding row; validator passed with `ok: 1`. No supervisor-owned `by-memory/-coverage-report.md` rows remain pending for this item. Applied row text is retained below for audit only:

```text
        - [UID:0002L2][0x00597fd0-0x00597fdb.ClearGlobalTimerMgr](by-memory/0x00597fd0-0x00597fdb.ClearGlobalTimerMgr.md) 0x00597fd0-0x00597fdb | function | ClearGlobalTimerMgr : reconstructable : 86% : very-strong : A002 live IDA MCP on 2026-06-12 corrected the half-open range; exact `0x0b` / 11-byte helper writes `0` to [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md) at `0x0067ab80`, includes the `retn` at `0x00597fda`, has no callees or address-literal hits, has one constructor EH cleanup jump from `0x00609b5e` in `sub_5976C0`, remains assigned to [UID:0000OT][TimerMgr](by-file/TimerMgr.md) after child `86/90` and parent `90/86` clear the strict gate, and final C++ remains blank below the 95/95 gate.
```

Score/parent/routing decisions:

- [UID:0002RF] `SelfLookPaneSpelledTextDispatch`: `74/84 -> 86/90`; `RECONSTRUCTABLE:TRUE`; parent [UID:0000NL][SelfLookPane](../../../by-file/SelfLookPane.md) position `26` -> [UID:0000CU][SelfLookPane](../../../by-class/SelfLookPane.md), optional position blank.
- [UID:0000CU] direct class parent was read as `85/88`; [UID:0000NL] file parent was read as `85/89`. The reroute is justified because the child and true direct class parent both clear the strict 85/85 gate.
- No split was required. Live IDA models one exact `0x0056b950-0x0056b9ef` function and one successor `0xcc` padding byte `0x0056b9ef-0x0056b9f0`, now recorded in `by-memory/-ignored.md`.
- [UID:00023V] aggregate helper-island metadata was not changed because the broad aggregate remains below the strict gate; only stale evidence text was corrected.

Evidence:

- Live IDA MCP session `a002_batch346` on 2026-06-12 reports `sub_56B950` at `0x0056b950`, size `0x9f` / 159 bytes, no function at `0x0056b9ef`, and no function at successor raw start `0x0056b9f0`.
- Live IDA MCP `xrefs_to` reports no direct refs to `0x0056b950`, `0x0056b9ef`, or `0x0056b9f0`; `find_bytes` found no little-endian address literals for those three addresses.
- Live IDA MCP `callees` reports `0x00575a10`, `0x00575790`, `0x00584540`, `0x0056be20`, `0x0056bca0`, and `0x00582b70`.
- Live IDA MCP `analyze_function`/`disasm` shows packet cursor `1`, text read, optional value read, branch to `SpelledPane` remove or add/update through `this+0xfc`, temporary cleanup, and return `0`.
- Live IDA MCP `insn_query` over `0x005696e0-0x005697b5` shows `SelfLookPane` event-handler case `0x00569747-0x005697b2` implements the same inline dispatch shape through the child pointer at `[esi+0x5c]`, supporting `SelfLookPane` ownership despite no standalone start xref.
- `tools/int_convert.py` verified recorded conversions: `0x9f` / 159, `0x1` / 1, `0xfc` / 252, `0x3e5` / 997, `0x71` / 113, `0x38` / 56, `0x177` / 375, `0x80` / 128, `0x3` / 3, and `0x36` / 54.

Validation commands/results:

- Scoped validation loop exited `0`: `python .\tools\validator.py --mode file --file <changed by-memory file> --apply --queue-timeout 240` for `by-memory/0x0056b950-0x0056b9ef.SelfLookPaneSpelledTextDispatch.md`, `by-memory/0x0056a380-0x0056ba99.SelfLookPanePacketUpdateHelpers.md`, and `by-memory/-ignored.md`.
- Visible validator output for [UID:0002RF] included `completion_update 0002RF ... 86`, `confidence_update 0002RF ... 90`, `autogen_registry_update 0002RF ... 0000NL -> 0000CU`, optional position `26 ->`, `ok: 1`, and removal of [UID:0002RF] from Low_Both and by-memory project stats.
- Post-validation checks: `auto-generated/-ag-memory-coverage.md` now lists [UID:0002RF] assigned to parent `0000CU` with blank position; `project-level/-auto-completion-stats.md` no longer lists [UID:0002RF] or `SelfLookPaneSpelledTextDispatch`; `by-memory/-coverage-report.md` still has the old [UID:0002RF] row because the supervisor-owned replacement block above is pending.

## Current pending supervisor-owned rows

- None. Supervisor applied and validated the [UID:0002L2] `ClearGlobalTimerMgr` replacement row on 2026-06-12 after the A002 batch completion.
- Any older [UID:0002RF] pending statement above is stale; supervisor already applied and validated that row before the ClearGlobalTimerMgr assignment.

## 2026-06-13 Goal2 - TextBoxPane/TextEdit support-object barrier repair

Changed files:

- `by-memory/0x00591300-0x005954b3.TextBoxPaneNoncontiguousAuditMap.md` (renamed from `by-memory/0x00591300-0x005954b3.TextBoxPane.md`)
- `by-memory/0x00591300-0x005913f9.TextBoxPaneCursorInvalidationOverrides.md`
- `by-memory/0x00595390-0x005954b3.TextBoxPaneConstructor.md`
- `by-file/TextBoxPane.md`
- `by-class/TextBoxPane.md`
- `by-file/TextEditPane.md`
- `by-memory/0x00594e60-0x00595760.TextEditSupportObjects.md`
- `by-memory/0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md`
- `by-memory/0x00594e60-0x00595389.TextEditSupportObjectsBeforeTextBoxPane.md` (new, validator UID [UID:0003M7])
- `by-memory/0x005954c0-0x00595760.TextEditSupportObjectsAfterTextBoxPane.md` (new, validator UID [UID:0003M8])
- `by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md` (stale UID link refresh only)
- `by-memory/0x0062e048-0x0062e05c.TextEditObjectVtableData.md`
- `by-memory/0x0062e05c-0x0062e06c.TextEditScrapVtableData.md`
- Validator-owned/generated side effects: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, and validator registry state.
- `by-memory/-coverage-report.md` was not manually edited by A002; the supervisor applied and validated the exact replacement blocks below on 2026-06-13.

Score/parent/routing decisions:

- [UID:0001JO] `TextBoxPane` broad page: `74/84`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000OJ] -> `86/90`, renamed `TextBoxPaneNoncontiguousAuditMap`, `RECONSTRUCTABLE:FALSE`, parent blank. This is a by-structure repair: the page is a noncontiguous audit map over exact `TextBoxPane` children and intervening/overlapping `TextEditPane` support-object ownership, not a direct child of any source parent.
- [UID:0002XX] `TextEditSupportObjects`: `86/89`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000ON] -> `87/91`, `RECONSTRUCTABLE:FALSE`, parent blank. The historical `0x00594e60-0x00595760` range crosses [UID:0002RV] `TextBoxPaneConstructor`.
- [UID:0003M7] `TextEditSupportObjectsBeforeTextBoxPane`: new exact child, `85/87`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000ON][TextEditPane](../../../by-file/TextEditPane.md). Child and direct parent `89/86` clear the strict gate.
- [UID:0003M8] `TextEditSupportObjectsAfterTextBoxPane`: new exact child, `86/88`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000ON][TextEditPane](../../../by-file/TextEditPane.md). Child and direct parent `89/86` clear the strict gate.
- [UID:0001JT] `TextEditSupportObjectsAndFilter`: `86/90 -> 88/92`; remains `RECONSTRUCTABLE:FALSE`, parent blank; now explicitly records the support-object split around [UID:0002RV] plus [UID:0001JU] `TextFilterAndSanitizer`.
- [UID:0002RU] and [UID:0002RV] stayed `78/86`; no parent reroute was made because each remains below the current strict 85 completion gate. Their stale audit-map links were updated and the local padding evidence was refreshed.
- [UID:0000OJ], [UID:0000EI], [UID:0000ON], [UID:0003GA], [UID:0003GB], and [UID:0001B0] scores/parents stayed unchanged; edits were cross-reference/evidence alignment only.

Evidence:

- Live IDA MCP session `a002_batch_clear_timer` on 2026-06-13 reports `sub_591300` at `0x00591300-0x0059136a`, `sub_591370` at `0x00591370-0x005913f9`, and `sub_595390` at `0x00595390-0x005954b3`.
- Live IDA MCP byte reads confirm `0x0059136a-0x00591370`, `0x005913f9-0x00591400`, `0x00595389-0x00595390`, `0x005954b3-0x005954c0`, `0x0059559b-0x005955a0`, `0x00595622-0x00595630`, `0x0059566e-0x00595670`, `0x005956ae-0x005956b0`, and `0x00595759-0x00595760` are `0xcc` alignment.
- Live IDA MCP `xrefs_to` confirms five xrefs to `0x00591300`, six xrefs to `0x00591370`, eight constructor xrefs to `0x00595390`, ten code xrefs to `0x00594f30`, three constructor xrefs to `0x005954c0`, and vtable data refs to `0x005955a0`, `0x00595630`, `0x00595670`, and `0x005956b0`.
- Live IDA MCP decompilation confirms `0x005954c0` initializes `EPFTextEditObject` and loads `SYMBOLS.EPF`/`SYMBOLS.EPD`, `0x00595590` restores the `TextEditObject` vtable and calls base cleanup, `0x005955a0` dispatches an EPF virtual draw/update helper through the global render callback table, and destructor helpers restore the appropriate support-object vtables.
- `auto-generated/by-memory-tool-report.md` now shows the former TextBoxPane/support-object crossings as `[Not-Reconstructable]`, confirming the reconstructable barrier cause was removed. The report remains tool-owned/generated; no manual edits were made.

Validation commands/results:

- New UID allocation: `python tools/validator.py --mode file --file by-memory\0x00594e60-0x00595389.TextEditSupportObjectsBeforeTextBoxPane.md --apply` exited `0` and assigned [UID:0003M7]; `python tools/validator.py --mode file --file by-memory\0x005954c0-0x00595760.TextEditSupportObjectsAfterTextBoxPane.md --apply` exited `0` and assigned [UID:0003M8].
- Scoped validation loop exited `0` for all changed by-* docs: `python tools/validator.py --mode file --file <changed-file> --apply` for [UID:0001JO], [UID:0002RU], [UID:0002RV], [UID:0000OJ], [UID:0000EI], [UID:0002XX], [UID:0001JT], [UID:0000ON], [UID:0003M7], [UID:0003M8], [UID:0001B0], [UID:0003GA], and [UID:0003GB]. Each run reported `ok: 1`.
- Visible validator updates included [UID:0001JO] `path_update`, `completion_update 86`, `confidence_update 90`, `true -> false`, parent `0000OJ ->`; [UID:0002XX] `completion_update 87`, `confidence_update 91`, `true -> false`, parent `0000ON ->`; [UID:0001JT] `completion_update 88`, `confidence_update 92`; [UID:0003M7] `completion_update 85`, `confidence_update 87`, parent `-> 0000ON`; and [UID:0003M8] `completion_update 86`, `confidence_update 88`, parent `-> 0000ON`.
- Post-validation generated checks: `auto-generated/-ag-memory-coverage.md` lists [UID:0003M7] and [UID:0003M8] assigned to parent `0000ON`; [UID:0001JO] and [UID:0002XX] are listed as `not_reconstructable` with blank parents. `project-level/-auto-completion-stats.md` no longer lists [UID:0001JO].

Supervisor-applied `by-memory/-coverage-report.md` rows:

- The supervisor applied and validated the Goal 2 TextBoxPane/TextEdit support-object replacement blocks for [UID:0001JO], [UID:0002RU], [UID:0002RV], [UID:0001JT], [UID:0002XX], [UID:0003M7], [UID:0003M8], and [UID:0001JU] on 2026-06-13.
- The supervisor also updated the `by-memory/-coverage-report.md` summary from `1241` ignored rows to `1243` ignored rows, with reconstructable row count unchanged.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240`; result `ok: 1`.
- No A002 Goal 2 TextBoxPane/TextEdit support-object supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-13 Goal2 - RectAnchorTransformHelpers boundary and support refresh

Changed files:

- `by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md` (renamed from `by-memory/0x004b7f90-0x004b8198.RectAnchorTransformHelpers.md`)
- `by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md`
- `by-file/RectBounds.md`
- `by-class/RectBounds.md`
- `by-type/by-struct/RectBoundsLayout.md`
- `by-memory/-ignored.md`
- `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`
- `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md`
- Validator-owned/generated side effects: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, `auto-generated/by-memory-tool-report.md`, and validator registry state.
- `by-memory/-coverage-report.md` was not manually edited by A002. The supervisor applied and validated the exact replacement rows below on 2026-06-13.

Score/parent/routing decisions:

- [UID:00022I] `RectAnchorTransformHelpers`: `76/82 -> 86/88`, `RECONSTRUCTABLE:TRUE`, parent remains [UID:0000N2][RectBounds](../../../by-file/RectBounds.md) at position `45`. The half-open range was corrected from stale `0x004b7f90-0x004b8198` to `0x004b7f90-0x004b8194`; child and direct/support docs now clear the strict gate.
- [UID:00022L] `RectAnchorAxisAdjustHelper`: `78/86 -> 86/88`, `RECONSTRUCTABLE:TRUE`, parent remains [UID:0000N2][RectBounds](../../../by-file/RectBounds.md) at position `46`.
- [UID:0000N2] `RectBounds` by-file confidence `82 -> 85`; completion remains `90`; parent stays unchanged. This clears the direct parent/support confidence gate for [UID:00022I] and [UID:00022L].
- [UID:0000B6] `RectBounds` by-class confidence `84 -> 85`; completion remains `88`.
- [UID:0003GC] `RectBoundsLayout` completion `84 -> 85`; confidence remains `88`.
- [UID:0000VN] `-ignored` padding rows were corrected from stale `0x004b8005-0x004b8010` and `0x004b8198-0x004b81a0` to `0x004b8004-0x004b8010` and `0x004b8194-0x004b81a0`.
- [UID:00022F] `RectGeometryHelpers` and [UID:00022K] `WideStringHashHelper` received stale neighbor-boundary/link refreshes only; scores/parents unchanged.

Evidence:

- Live IDA MCP session `a002_batch_clear_timer` on 2026-06-13 reports no functions at raw helper starts `0x004b7f90`, `0x004b8010`, `0x004b80d0`, `0x004b8198`, `0x004b83ae`, or `0x004b83c5`.
- Live IDA MCP byte reads confirm `0x004b8004-0x004b8010`, `0x004b8194-0x004b81a0`, and `0x004b83c5-0x004b83d0` are `0xcc` alignment padding.
- Raw helper decode identifies `0x004b7f90-0x004b8004` as a 3x3 anchor transpose switch/table mapping `[0,1,2,3,4,5,6,7,8]` to `[0,3,6,1,4,7,2,5,8]`.
- Raw helper decode identifies `0x004b8010-0x004b80d0` as the zero-offset anchored rectangle transform and `0x004b80d0-0x004b8194` as the offset-output variant. Both copy two 16-byte rect records, call the axis adjust helper for horizontal edges, remap the anchor, then call the axis adjust helper for vertical edges.
- Live IDA MCP `lookup_funcs` reports `sub_4B8290` at `0x004b8290`, size `0x11e`; decompilation shows the six-argument axis adjust routine computes first/second span deltas and applies anchor-column offsets for cases `0/3/6`, `1/4/7`, and `2/5/8`.
- Live IDA MCP `callees` reports no callees from `0x004b8290`.
- Live IDA MCP `xrefs_to 0x004b8290` reports exactly four callers, all inside [UID:00022I]: `0x004b803e`, `0x004b809f`, `0x004b80ff`, and `0x004b8161`.
- Live IDA MCP `xrefs_to` reports no direct external xrefs to raw starts `0x004b7f90`, `0x004b8010`, or `0x004b80d0`; ownership is inferred from local helper shape, contiguous call flow, and its exclusive calls into [UID:00022L].

Validation commands/results:

- Scoped validation loop exited `0`: `python .\tools\validator.py --mode file --file <changed by-* file> --apply --queue-timeout 240` for `by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md`, `by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md`, `by-file/RectBounds.md`, `by-class/RectBounds.md`, `by-type/by-struct/RectBoundsLayout.md`, `by-memory/-ignored.md`, `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`, and `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md`.
- Visible validator updates included [UID:00022I] `path_update`, `completion_update 86`, `confidence_update 88`, removal from `project-level/-auto-completion-stats.md` Low_Confidence, and [UID:00022L] score refresh to `86/88`; every run reported `ok: 1`.
- Post-validation checks: `auto-generated/-ag-memory-coverage.md` lists [UID:00022I] at `by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md` assigned to parent `0000N2` position `45`, and [UID:00022L] assigned to parent `0000N2` position `46`. `project-level/-auto-completion-stats.md` no longer lists [UID:00022I] or `RectAnchorTransformHelpers`.
- Memory range report was run because the target range changed: `python .\tools\memory_ranges.py report` wrote `auto-generated/by-memory-tool-report.md`. No target-range errors appeared for [UID:00022I]; visible remaining errors were unrelated pre-existing report findings.

## Current pending supervisor-owned rows

- None. The supervisor applied and validated the Goal 2 RectAnchorTransformHelpers `by-memory/-coverage-report.md` replacement rows for [UID:00022I], the `0x004b8004-0x004b8010` and `0x004b8194-0x004b81a0` padding rows, and [UID:00022L] on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240`; result `ok: 1`.

## 2026-06-13 Goal2 - ChangeItemSlotInputPane raw constructor direct-owner refresh

Changed files:

- `by-memory/0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor.md`
- `by-class/ChangeItemSlotInputPane.md`
- `by-class/-coverage-report.md`
- Validator-owned/generated side effects: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, validator registry state, and projected-path stats refresh.
- `by-memory/-coverage-report.md` was not manually edited by A002; exact supervisor replacement row is pending below.

Score/parent/routing decisions:

- [UID:0001M5] `ChangeItemSlotInputPaneRawConstructor`: `74/84 -> 86/89`; `AUTOGEN_PARENT_UID` rerouted from [UID:0000KC][ItemActionInputPanes](../../../by-file/ItemActionInputPanes.md) to direct class parent [UID:00001J][ChangeItemSlotInputPane](../../../by-class/ChangeItemSlotInputPane.md). `RECONSTRUCTABLE:TRUE`; C++ remains blank below the 95/95 final-source gate.
- [UID:00001J] `ChangeItemSlotInputPane` class: `82/86 -> 85/88`, parent remains [UID:0000KC][ItemActionInputPanes](../../../by-file/ItemActionInputPanes.md). This clears the direct-parent gate for [UID:0001M5].
- [UID:0000KC] file parent was read as `90/85`, so the class-to-file route also clears `85/85`.
- [UID:0001M6] `ChangeItemSlotInputPane` method cluster was not rerouted. It remains `78/84`, below the child assignment gate, and should be refreshed separately before changing its parent from the file fallback.

Evidence:

- Live IDA MCP session `a002_batch_clear_timer` on 2026-06-13 reports `0x005b2fd0`, `0x005b2fcb`, and `0x005b3196` as `Not a function`; `sub_5B3010` at `0x005b3010` size `0x6c`; and `sub_5B3080` at `0x005b3080` size `0x116`.
- `get_bytes 0x005b2fd0 size 64` returns the complete raw constructor body ending `5e 8b e5 5d c3`; `tools/int_convert.py` verified `0x40` / 64.
- `get_bytes 0x005b2fcb size 69` returns five leading `0xcc` bytes followed by the same constructor bytes, confirming the predecessor padding and raw-start boundary.
- `insn_query 0x005b2fd0-0x005b3010` decodes 20 instructions: thiscall prologue, `dword_67A750` localized prompt lookup with id `0x2e`, `sub_4F0350`, `sub_4F2A60`, vtable stores to `this+0`, `this+0xa0`, and `this+0xa4`, then `retn`.
- `xrefs_to 0x005b2fd0` reports no direct xrefs. `xrefs_to` the three vtable bases reports raw stores here plus dispatcher/factory stores at `0x005a617d/0x005a6185/0x005a618f` and `0x005a9406/0x005a940c/0x005a9416`.
- `get_global_value` confirms vtable anchors: `0x0062fa40 -> 0x00652c5c`, `0x0062fa44 -> 0x005b7940`, `0x0062fa8c -> 0x005b3080`, `0x0062fa94 -> 0x005b77c8`, `0x0062fa9c -> 0x005b3010`, `0x0062fac4 -> 0x005b77d3`, and `0x0062fac8 -> 0x00544e90`.
- `decompile 0x005a93b0` shows the equivalent factory path allocates `0x108` / 264 bytes, looks up prompt id `46`, calls `sub_4F2A60`, and writes the same three `ChangeItemSlotInputPane` vtables.
- `tools/int_convert.py` verified conversions used in the docs: `0x2e` / 46, `0x40` / 64, `0xa0` / 160, `0xa4` / 164, `0x108` / 264, and `0xcc` / 204.

Validation commands/results:

- `python tools\validator.py --mode file --file by-memory\0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor.md --apply --queue-timeout 240`: exited `0`; visible output included `completion_update 0001M5 ... 86`, `confidence_update 0001M5 ... 89`, `autogen_registry_update 0001M5 ... 0000KC -> 00001J`, removal of [UID:0001M5] from `Low_Completion`, `Low_Both`, and `by-memory` project stats, and `ok: 1`.
- `python tools\validator.py --mode file --file by-class\ChangeItemSlotInputPane.md --apply --queue-timeout 240`: exited `0`; visible output included `completion_update 00001J ... 85`, `confidence_update 00001J ... 88`, new reference index entries for [UID:00001O] and [UID:000367], and `ok: 1`.
- `python tools\validator.py --mode file --file by-class\-coverage-report.md --apply --queue-timeout 240`: exited `0`; result `ok: 1`.
- Post-validation checks: `auto-generated/-ag-memory-coverage.md` lists [UID:0001M5] assigned to parent `00001J`; `project-level/-auto-completion-stats.md` no longer lists [UID:0001M5].

## Current pending supervisor-owned rows

- None. The supervisor applied and validated the Goal 2 [UID:0001M5] `ChangeItemSlotInputPaneRawConstructor` `by-memory/-coverage-report.md` replacement row on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.

## 2026-06-13 Goal2 - ChangeSpellSlotInputPane raw constructor direct-owner refresh

Changed files:

- `by-memory/0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor.md`
- Validator-owned/generated side effects: `project-level/-auto-completion-stats.md` and validator registry/reference state were refreshed by scoped validation. `auto-generated/-ag-memory-coverage.md` was checked and reported unchanged.
- `by-memory/-coverage-report.md` was not manually edited by A002; exact supervisor replacement row is pending below.

Score/parent/routing decisions:

- [UID:0001M7] `ChangeSpellSlotInputPaneRawConstructor`: `74/84 -> 86/89`; parent remains direct class parent [UID:00001M][ChangeSpellSlotInputPane](../../../by-class/ChangeSpellSlotInputPane.md). `RECONSTRUCTABLE:TRUE`; C++ remains blank below the 95/95 final-source gate.
- [UID:00001M] direct class parent was read as `86/86`; [UID:0000O0] file parent was read as `88/85`. The child-to-class and class-to-file routes both clear the strict 85/85 gate.

Evidence:

- Live IDA MCP session `a002_batch_clear_timer` on 2026-06-13 reports `0x005b3220` and `0x005b325f` as `Not a function`; `sub_5B3260` is the next modeled function at `0x005b3260`, size `0x6c`.
- `get_bytes 0x005b3220 size 64` returns the complete raw constructor body ending `5e 8b e5 5d c3`; `tools/int_convert.py` verified `0x40` / 64.
- `get_bytes 0x005b3210 size 80` shows a prior `retn 8` ending at `0x005b3214`, eleven `0xcc` bytes through `0x005b321f`, and the constructor prologue at `0x005b3220`.
- `insn_query 0x005b3220-0x005b3260` decodes 20 instructions: thiscall prologue, `dword_67A750` localized prompt lookup with id `0x2d`, `sub_4F0350`, `sub_4F2A60`, vtable stores to `this+0`, `this+0xa0`, and `this+0xa4`, then `retn`.
- `xrefs_to 0x005b3220` reports no direct xrefs. `xrefs_to` the three vtable bases reports raw stores here plus dispatcher/factory stores at `0x005a61d7/0x005a61df/0x005a61e9` and `0x005a9486/0x005a948c/0x005a9496`.
- `get_global_value` confirms vtable anchors: `0x0062fb18 -> 0x005b32d0`, `0x0062fb20 -> 0x005b77c8`, `0x0062fb28 -> 0x005b3260`, `0x0062fb50 -> 0x005b77d3`, and `0x0062fb54 -> 0x00544e90`.
- `decompile 0x005a9430` shows the equivalent factory path allocates `0x108` / 264 bytes, looks up prompt id `45`, calls `sub_4F2A60`, and writes the same three `ChangeSpellSlotInputPane` vtables.
- `tools/int_convert.py` verified conversions used in the docs: `0x40` / 64, `0x2d` / 45, `0xa0` / 160, `0xa4` / 164, `0x108` / 264, and `0x88` / 136.

Validation commands/results:

- `python tools\validator.py --mode file --file by-memory\0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor.md --apply --queue-timeout 240`: exited `0`; visible output included `completion_update 0001M7 ... 86`, `confidence_update 0001M7 ... 89`, `reference_index_add` for [UID:0000RC], [UID:0002N5], and [UID:0003HJ], removal of [UID:0001M7] from `Low_Completion`, `Low_Both`, and `by-memory` project stats, and `ok: 1`.
- `memory_ranges` was not run because no memory range changed.

Supervisor-applied `by-memory/-coverage-report.md` replacement row:

- The supervisor applied and validated the Goal 2 [UID:0001M7] `ChangeSpellSlotInputPaneRawConstructor` `by-memory/-coverage-report.md` replacement row on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 [UID:0001M7] supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-13 Goal2 - ChatInputPane raw constructor exact-range refresh

Changed files:

- Renamed/updated `by-memory/0x005b38e0-0x005b3940.ChatInputPaneRawConstructor.md` -> `by-memory/0x005b38e0-0x005b3935.ChatInputPaneRawConstructor.md`
- `by-class/ChatInputPane.md`
- `by-memory/0x005b3940-0x005b3bba.ChatInputPane.md`
- `by-file/Chatting.md`
- `by-global/g_pChatInputPane.md`
- `by-memory/0x0069bf68-0x0069bf6c.g_pChatInputPane.md`
- `by-memory/0x00630a14-0x00630a18.SharedChevronPromptString.md`
- `by-memory/-ignored.md`
- `by-class/-coverage-report.md`
- Validator/tool-owned side effects: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, `auto-generated/by-memory-tool-report.md`, and validator registry/reference state.
- `by-memory/-coverage-report.md` was not manually edited by A002. The validator updated the UID link annotation as a rename side effect, but the row's range/score/description still need the supervisor replacement below.

Score/parent/routing decisions:

- [UID:0002S9] `ChatInputPaneRawConstructor`: `74/84 -> 86/89`; range corrected from `0x005b38e0-0x005b3940` to exact executable body `0x005b38e0-0x005b3935`; parent remains direct class parent [UID:00001Q][ChatInputPane](../../../by-class/ChatInputPane.md). `RECONSTRUCTABLE:TRUE`; C++ remains blank below the 95/95 final-source gate.
- [UID:00001Q] `ChatInputPane` class: `82/84 -> 85/86`, parent remains [UID:0000I5][Chatting](../../../by-file/Chatting.md). This clears the direct-parent gate for [UID:0002S9].
- [UID:0000I5] `Chatting` file parent was already `85/88`; no score change.
- [UID:0001MC] `ChatInputPane` method cluster remains `78/84`; it received corrected constructor links only and should be refreshed separately before any score/range reassessment.

Evidence:

- Live IDA MCP session `a002_batch_clear_timer` on 2026-06-13 reports `0x005b38d5`, `0x005b38e0`, `0x005b3934`, and `0x005b3935` as `Not a function`; `sub_5B3940` starts at `0x005b3940` with `0x100` / 256-byte size (Verified with int_convert.py).
- `get_bytes 0x005b38e0 size 0x60` returns the complete raw constructor body followed by eleven `0xcc` bytes; `tools/int_convert.py` verified `0x55` / 85 body bytes, the former `0x60` / 96 mixed range, and the `0x0b` / 11-byte padding tail.
- `insn_query 0x005b38e0-0x005b3935 include_disasm=true` decodes 25 raw instructions ending in `retn` at `0x005b3934`; `insn_query 0x005b3935-0x005b3940` returns `align 10h`.
- `xrefs_to 0x005b38e0` and `xrefs_to 0x005b3935` report no direct xrefs. `xrefs_to` the three vtable bases reports raw stores at `0x005b3916/0x005b391c/0x005b3926` plus equivalent construction/open stores in `0x005a5bd0` and `0x005a95e0`.
- `xrefs_to 0x0069bf68` reports eight refs across `sub_5A5BD0`, `sub_5A95E0`, this raw constructor write at `0x005b3908`, and scalar deleting destructor clear at `0x005b7986`; `xrefs_to 0x00630a14` reports the shared `">"` prompt refs at `0x005a5d37`, `0x005a962a`, and `0x005b38e7`.
- `get_global_value` confirms the relevant vtable anchors, including `0x0062fbe8 -> 0x005b7980`, `0x0062fc30 -> 0x005b3a40`, `0x0062fc38 -> 0x005b77de`, `0x0062fc40 -> 0x005b3940`, `0x0062fc68 -> 0x005b77e9`, and `0x0062fc6c -> 0x00544e90`.
- `decompile 0x005a95e0` shows the equivalent open path allocates `0x10c` / 268 bytes, calls `sub_4F2C90(L">")`, writes `g_pChatInputPane`, installs the same three vtables, and sets the `this+0x108` / 264 history cursor sentinel (Verified with int_convert.py).

Validation commands/results:

- Scoped validation loop: `python tools\validator.py --mode file --file <changed-file> --apply --queue-timeout 240` for the renamed target, `by-class\ChatInputPane.md`, `by-memory\0x005b3940-0x005b3bba.ChatInputPane.md`, `by-file\Chatting.md`, `by-global\g_pChatInputPane.md`, `by-memory\0x0069bf68-0x0069bf6c.g_pChatInputPane.md`, `by-memory\0x00630a14-0x00630a18.SharedChevronPromptString.md`, and `by-memory\-ignored.md`: exited `0`; each run reported `ok: 1`.
- Visible target validation updates included `path_update 0002S9 ... 0x005b3935 ... was ... 0x005b3940`, `completion_update 0002S9 ... 86`, `confidence_update 0002S9 ... 89`, and removal from `Low_Completion`, `Low_Both`, and `by-memory` project stats.
- `python tools\validator.py --mode file --file by-class\-coverage-report.md --apply --queue-timeout 240`: exited `0`; result `ok: 1`.
- `python tools\memory_ranges.py report`: exited `0`; wrote `auto-generated/by-memory-tool-report.md`.
- Post-validation checks: `auto-generated/-ag-memory-coverage.md` lists [UID:0002S9] at `by-memory/0x005b38e0-0x005b3935.ChatInputPaneRawConstructor.md` assigned to parent `00001Q`; `project-level/-auto-completion-stats.md` no longer lists [UID:0002S9].

## Current pending supervisor-owned rows

- None. The supervisor applied and validated the Goal 2 [UID:0002S9] `ChatInputPaneRawConstructor` `by-memory/-coverage-report.md` replacement row on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.

## 2026-06-13 Goal2 - EmployeeQuantityInputDialogPaneConstructor low-score repair

Changed files:

- `by-memory/0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated side effects: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, validator registry/reference state, and projected-path stats refresh.
- `by-memory/-coverage-report.md` was not manually edited by A002; exact supervisor replacement row is pending below.

Score/parent/routing decisions:

- [UID:0002HH] `EmployeeQuantityInputDialogPaneConstructor`: `74/86 -> 86/89`; `AUTOGEN_PARENT_UID` rerouted from broad memory aggregate [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](../../../by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md) to direct class parent [UID:00004E][EmployeeQuantityInputDialogPane](../../../by-class/EmployeeQuantityInputDialogPane.md). `RECONSTRUCTABLE:TRUE`; C++ remains blank below the 95/95 final-source gate.
- Direct parent [UID:00004E] was read as `85/88`; file parent [UID:0000J0][EmployeeDialogPane](../../../by-file/EmployeeDialogPane.md) was read as `88/85`. The target-to-class and class-to-file routes both clear the strict `85/85` gate.

Evidence:

- Live IDA MCP session `a002_batch_clear_timer` on 2026-06-13 reports `0x004a4770` as `sub_4A4770`, size `0x2b5` / 693 bytes; `0x004a4a25` as not a function; and next modeled method `0x004a4a30` as `sub_4A4A30`.
- `analyze_function 0x004a4770` and `trace_data_flow 0x004a4770 backward depth 1` report exactly three code callers at `0x004a24f2`, `0x004a32b6`, and `0x004a4c5e`.
- Live caller decompilation ties those calls to [UID:0003KT] `EmployeeInventoryItemCommandHelper`, [UID:0003KY] `EmployeeDialogPaneOnButtonAction`, and [UID:00013A] `AddEmployeeItemDialog`, with `0x274` / 628-byte allocation before construction.
- Live constructor disassembly/decompilation confirms title/base setup, vtable stores at `0x004a47cc`/`0x004a47d2`/`0x004a47dc`, owner/index writes at `+0x26c/+0x270`, focus of control id `4`, return at `0x004a4a22` with `retn 0Ch`, and no modeled function at `0x004a4a25`.
- `trace_data_flow` on vtable bases `0x00619038`, `0x00619098`, and `0x006190c8` ties each table to the constructor stores at `0x004a47cc`, `0x004a47d2`, and `0x004a47dc`.
- `tools/int_convert.py` verified the conversions written into the page: `0x2b5` / 693, `0x274` / 628, `0x26c` / 620, `0x270` / 624, `0xa0` / 160, `0xa4` / 164, `0x14c` / 332, `0x114` / 276, `0x13` / 19.

Validation commands/results:

- `python tools\validator.py --mode file --file by-memory\0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor.md --apply --queue-timeout 240`: exited `0`; visible output included `completion_update 0002HH ... 86`, `confidence_update 0002HH ... 89`, `autogen_registry_update 0002HH ... 000138 -> 00004E`, four new reference-index entries, removal from `Low_Completion`, `Low_Both`, and by-memory project stats, and `ok: 1`.
- Post-validation check: `auto-generated/-ag-memory-coverage.md` lists [UID:0002HH] assigned to parent `00004E`; `project-level/-auto-completion-stats.md` no longer lists [UID:0002HH].
- `memory_ranges.py --advanced-scan report` was not run because no address range changed.

## Current pending supervisor-owned rows

- None. The supervisor applied and validated the Goal 2 [UID:0002HH] `EmployeeQuantityInputDialogPaneConstructor` `by-memory/-coverage-report.md` replacement row on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.

## 2026-06-13 Goal2 - UserShapeSelectControlPaneCore direct-owner refresh

Changed files:

- `by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md`
- `by-class/UserShapeSelectControlPane.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated side effects: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, validator registry/reference state, and projected-path stats refreshed during scoped validation.
- `by-memory/-coverage-report.md` was not manually edited by A002 per supervisor override; the supervisor later applied and validated the exact replacement row.
- `by-class/-coverage-report.md` was not edited by A002; the supervisor later applied and validated the exact replacement row after the lease conflict no longer mattered.

Score/parent/routing decisions:

- [UID:0002Q8] `UserShapeSelectControlPaneCore`: `74/86 -> 86/90`; `AUTOGEN_PARENT_UID` rerouted from file fallback [UID:0000OX][UserCreateAppearanceControls](../../../by-file/UserCreateAppearanceControls.md) to direct class parent [UID:0000FR][UserShapeSelectControlPane](../../../by-class/UserShapeSelectControlPane.md). `RECONSTRUCTABLE:TRUE`; C++ remains blank below the 95/95 final-source gate.
- [UID:0000FR] `UserShapeSelectControlPane` class: `84/82 -> 86/88`, parent remains [UID:0000OX][UserCreateAppearanceControls](../../../by-file/UserCreateAppearanceControls.md). This clears the direct-parent gate for [UID:0002Q8].
- [UID:0000OX] file parent was read as `87/85`, so the class-to-file route also clears `85/85`.

Evidence:

- Live IDA MCP session `a002_batch_clear_timer` on 2026-06-13 reports all modeled functions in [UID:0002Q8]: `0x004fce80` size `0x135` / 309, `0x004fcfc0` `0x6a` / 106, `0x004fd030` `0x13` / 19, `0x004fd050` `0x16` / 22, `0x004fd070` `0x59` / 89, `0x004fd0d0` `0x56` / 86, `0x004fd140` `0x24` / 36, `0x004fd170` `0x6e` / 110, `0x004fd1e0` `0x48` / 72, and `0x004fd230` `0x2f0` / 752.
- `get_bytes 0x004fcfb0 size 32` shows the constructor epilogue, eleven `0xcc` bytes through `0x004fcfbf`, and the `0x004fcfc0` prologue; `lookup_funcs 0x004fcfb5` reports `Not a function`.
- `get_bytes 0x004fd510 size 32` shows `0x004fd230` ending at `0x004fd520`, immediately followed by the next constructor prologue at [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](../../../by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md).
- `trace_data_flow 0x004fce80 backward depth 1` reports eight constructor callers: four inside [UID:0002Q7][0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers](../../../by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md) and four inside `0x0052a540` / `NewUserDialogPane2`.
- `analyze_function` evidence confirms helper caller fanout from `0x004fc010`, `0x004fc5f0`, `0x0052b090`, `0x0052b1d0`, `0x0052b470`, `0x0052b530`, and `0x0052bdd0`.
- `get_global_value` confirms representative vtable anchors: `0x0061d564 -> 0x00502dd0`, `0x0061d568 -> 0x004f4b10`, `0x0061d5cc -> 0x005025ea`, `0x0061d5d0 -> 0x004fd1e0`, `0x0061d5fc -> 0x005025f5`, `0x0061d600 -> 0x004fd170`, and `0x0061d5a8 -> 0x004fd230`.
- `analyze_function 0x004fd230` confirms paint branches on [UID:0000SW][g_useEpfAssets](../../../by-global/g_useEpfAssets.md) / `byte_66DA97`, calls `sub_4FCFC0`, `sub_4E09E0`, and `sub_4E06A0`, and reads [UID:0000RT][g_pNewHumanImageLib](../../../by-global/g_pNewHumanImageLib.md) / `dword_67A760` at `0x004fd33b`, `0x004fd468`, and `0x004fd4fe`.
- `tools/int_convert.py` verified conversions written into the docs: `0x135` / 309, `0x2f0` / 752, `0x13c` / 316, `0xa4` / 164, `0xa0` / 160, `0x20` / 32, `0xcc` / 204, `0x13` / 19, `0x16` / 22, `0x59` / 89, `0x56` / 86, `0x24` / 36, `0x6e` / 110, `0x48` / 72, `0xff` / 255, `0x108` / 264, `0x10e` / 270, `0x110` / 272, `0x112` / 274, `0x116` / 278, `0x11a` / 282, `0xc8` / 200, `0x6c` / 108, `0x70` / 112, `0x88` / 136, `0xb07` / 2823, and `0x99f` / 2463.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-memory\0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md --apply --queue-timeout 240`: exited `0`; visible output included `completion_update 0002Q8 ... 86`, `confidence_update 0002Q8 ... 90`, `autogen_registry_update 0002Q8 ... 0000OX -> 0000FR`, `stats_row_remove 0002Q8` from `Low_Completion`, `Low_Both`, and `by-memory`, five reference-index additions, `auto-generated/-ag-memory-coverage.md` update, and `ok: 1`.
- `python .\tools\validator.py --mode file --file by-class\UserShapeSelectControlPane.md --apply --queue-timeout 240`: first pass exited `0`; visible output included `completion_update 0000FR ... 86`, `confidence_update 0000FR ... 88`, reference-index additions, and `ok: 1`. The pass exposed one stale `0000R5` reference display, which A002 corrected to [UID:0000RT][g_pNewHumanImageLib](../../../by-global/g_pNewHumanImageLib.md).
- `python .\tools\validator.py --mode file --file by-class\UserShapeSelectControlPane.md --apply --queue-timeout 240`: second pass exited `0`; visible output included `reference_index_remove 0000R5 ... source no longer references target`, `stats_incremental_noop 0000FR`, and `ok: 1`.
- Post-validation checks: `project-level/-auto-completion-stats.md` no longer lists [UID:0002Q8]; `auto-generated/-ag-memory-coverage.md` lists [UID:0002Q8] assigned to parent `0000FR`.

## Current pending supervisor-owned rows

- None. The supervisor applied and validated the Goal 2 [UID:0002Q8] `UserShapeSelectControlPaneCore` `by-memory/-coverage-report.md` replacement row and [UID:0000FR] `UserShapeSelectControlPane` `by-class/-coverage-report.md` replacement row on 2026-06-13.
- Validation commands: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1` and `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --lock-timeout -1`; both returned `ok: 1`.

## 2026-06-13 Goal2 - SystemMessagePanes aggregate helper coverage refresh

Changed files:

- `by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated side effects: `project-level/-auto-completion-stats.md` and validator registry/reference state were refreshed by scoped validation.
- `by-memory/-coverage-report.md` was not manually edited by A002 per supervisor override; exact supervisor replacement row is pending below.

Score/parent/routing decisions:

- [UID:0001J6] `SystemMessagePanes`: `74/86 -> 86/89`; `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains direct file parent [UID:0000OE][SystemMessagePanes](../../../by-file/SystemMessagePanes.md) at `89/86`.
- Direct class parents checked during this pass already clear the strict gate: [UID:0000EA] `SystemMessagePane` is `86/87`; [UID:000030] `ColorStringSystemMessage` is `85/88`; [UID:000061] `HeaderSystemMessage` is `85/88`; [UID:00005D] `FooterSystemMessage` is `85/88`; [UID:00009B] `NewSystemMessageModifyHeightPane` is `85/87`; [UID:00009C] `NewSystemMessagePane` is `85/86`; [UID:00009T] `OldSystemMessagePane` is `85/88`.
- Structure decision: the continuous memory window remains a reconstructable source-family aggregate for `social/SystemMessagePanes.cpp`, but it explicitly excludes ForcedInform islands that are already exact children of [UID:0000JJ][ForcedInformMessageDialog](../../../by-file/ForcedInformMessageDialog.md). Final C++ remains blank because this aggregate is not one emitted function body and exact method/field names remain below the 95/95 final-source gate.

Evidence:

- Live IDA MCP session `a002_batch_clear_timer` on 2026-06-13 `entity_query` over `0x00584ea0-0x0058af40` reported 92 modeled functions, including the successor helper [UID:000246] `0x0058af40-0x0058af48.HeaderFooterSystemMessageDefaultTrueVirtual`.
- The live function inventory exposed previously missing helper bands now documented in the target page: `0x00585360-0x005856e9`, `0x00586440-0x0058783e`, `0x00588c10-0x00588e25`, `0x00589180-0x005898f3`, and `0x00589d30-0x0058aa3e`.
- `analyze_component` on representative helpers tied system-message resource/text helpers to `HeaderSystemMessage`, `FooterSystemMessage`, and `ColorStringSystemMessage` vtables, plus resource/string backing at `word_60DB20`, `off_62D98C`, and `dword_67A750`.
- Live decompilation confirmed singleton clear helpers: `0x0058aaa0 -> g_pHeightModifyPane`, `0x0058aab0 -> g_pNewSystemMessagePane`, `0x0058aac0 -> g_pOldSystemMessagePane`, `0x0058aad0 -> g_pChattingViewport`, and `0x0058aa90 -> g_pForcedInformMessageDialog` as a non-owned ForcedInform helper.
- Live decompilation confirmed destructor adjustor routing: `0x0058aaf1/0x0058aafc -> 0x0058acc0`, `0x0058ab07/0x0058ab12 -> 0x0058ad20`, `0x0058ab1d/0x0058ab28 -> 0x0058adb0`, and `0x0058ab33/0x0058ab3e -> 0x0058af00`.

Validation commands/results:

- `python tools\validator.py --mode file --file by-memory\0x00584ea0-0x0058af3b.SystemMessagePanes.md --apply --queue-timeout 240`: exited `0`; visible output included `completion_update 0001J6 ... 86`, `confidence_update 0001J6 ... 89`, five reference-index additions, removal from `Low_Completion`, `Low_Both`, and by-memory project stats, `autogen_report_noop` for all ag reports, and `ok: 1`.
- Post-validation checks: `project-level/-auto-completion-stats.md` no longer lists [UID:0001J6]; `auto-generated/-ag-memory-coverage.md` still lists [UID:0001J6] assigned to parent `0000OE`.

## Current pending supervisor-owned rows

- None. The supervisor applied and validated the Goal 2 [UID:0001J6] `SystemMessagePanes` `by-memory/-coverage-report.md` replacement row on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.

## 2026-06-13 Goal2 - CollectionPane2 false virtual stub direct-owner refresh

Changed files:

- `by-memory/0x0056fe70-0x0056fe75.CollectionPane2FalseStub.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated side effects: `project-level/-auto-completion-stats.md`, validator registry/reference state, and projected-path stats refresh.
- `by-memory/-coverage-report.md` was not manually edited by A002 per supervisor override; the supervisor-applied row is recorded below.

Score/parent/routing decisions:

- [UID:0001HJ] `CollectionPane2FalseStub`: `74/90 -> 86/91`; `AUTOGEN_PARENT_UID` rerouted from file parent [UID:0000IC][CollectionPane](../../../by-file/CollectionPane.md) to direct class parent [UID:00002Y][CollectionPane2](../../../by-class/CollectionPane2.md). `RECONSTRUCTABLE:TRUE`; C++ remains blank below the 95/95 final-source gate because the virtual method name is still unproven.
- Direct parent [UID:00002Y] was read as `87/90`; file parent [UID:0000IC] was read as `89/88`. The target-to-class and class-to-file routes both clear the strict `85/85` gate.

Evidence:

- Legacy `wave2.py` status ran successfully, but `wave2.py method/decomp/xrefs 0x56fe70` do not own the target (`Method not found` / `Global not found`), matching the source-3 doc caveat that this stub is omitted from active generated output.
- Live IDA MCP session `a001_goal2_collectionpane2_thunk` on 2026-06-13 reports `sub_56FE70` at `0x0056fe70` with size `0x5` / 5 decimal (Verified with `tools/int_convert.py`), `0x0056fe75` as not a function, and next modeled function `sub_56FE80`.
- Live decompilation returns a zero-return body; disassembly is exactly `xor al, al; retn 4`, with `0x04` / 4 decimal stack cleanup verified by `tools/int_convert.py`.
- `analyze_function 0x0056fe70` reports one basic block, no callees, no code callers, no strings, no constants, and one data xref from `0x006246cc`.
- `trace_data_flow 0x006246cc forward` reports `dd offset sub_56FE70` reaching only the target; the adjacent `0x006246c8` slot was checked separately and points to `0x00544dd0`, so the target is a separate false virtual slot rather than the third cell in a contiguous false-gate run.
- `make_signature_for_range 0x0056fe70-0x0056fe75` returns raw bytes `32 C0 C2 04 00`; `make_signature_for_range 0x0056fe75-0x0056fe80` returns eleven `CC` padding bytes, with `0x0b` / 11 decimal verified by `tools/int_convert.py`.

Validation commands/results:

- `python .\tools\validator.py --mode file --file .\by-memory\0x0056fe70-0x0056fe75.CollectionPane2FalseStub.md --apply --queue-timeout 240`: exited `0`; visible output included `completion_update 0001HJ ... 86`, `confidence_update 0001HJ ... 91`, `autogen_registry_update 0001HJ ... 0000IC -> 00002Y`, `stats_row_remove 0001HJ ... Low_Completion`, and `ok: 1`.
- Post-validation check: `project-level/-auto-completion-stats.md` no longer lists [UID:0001HJ].

## Current pending supervisor-owned rows

- None. The supervisor applied and validated the Goal 2 [UID:0001HJ] `CollectionPane2FalseStub` `by-memory/-coverage-report.md` replacement row on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.

## 2026-06-13 Goal2 - StaticDestructorWrappersBeforePoolAllocators compiler-glue refresh

Changed files:

- `by-memory/0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated side effects: `project-level/-auto-completion-stats.md`, validator registry/reference state, and projected-path stats refresh.
- `by-memory/-coverage-report.md` was not manually edited by A002 per supervisor override; supervisor applied and validated the replacement row after review.

Score/parent/routing decisions:

- [UID:00024G] `StaticDestructorWrappersBeforePoolAllocators`: `75/85 -> 86/91`; `RECONSTRUCTABLE:FALSE`; `AUTOGEN_PARENT_UID` remains blank. This remains ignored compiler/static-lifetime glue rather than a source-owned child, so no assignment is appropriate.

Evidence:

- Live IDA MCP session `a003_goal2_rtti_type_descriptors` on 2026-06-13 confirmed function starts at `0x0060c270`, `0x0060c280`, `0x0060c290`, `0x0060c2a0`, `0x0060c300`, and `0x0060c310`, plus successor `0x0060c320` for the pool-allocator destructor strip.
- `lookup_funcs` confirmed non-function padding starts at `0x0060c26a`, `0x0060c27a`, `0x0060c28a`, `0x0060c29a`, `0x0060c2fd`, `0x0060c30a`, and `0x0060c311`.
- `make_signature_for_range 0x0060c26a-0x0060c320` returned a unique exact byte signature for the full `0xb6` / 182-byte range; local `tools/int_convert.py` verified the numeric conversions written into the page.
- Live decompilation/disassembly confirmed the tail-jump wrappers, the inline `SimpleUString` cleanup body at `0x0060c2a0`, and single-`retn` `nullsub_14`.
- Backward data-flow confirmed one startup registration xref per wrapper: `0x00419f9a`, `0x00419fba`, `0x00419fda`, `0x0041a001`, `0x0041a01a`, and `0x0041a030`.
- Startup decompilation confirmed the paired constructor/setup calls, and the stale `dword_69B424` uncertainty was replaced by [UID:00029K][0x0069b424-0x0069b430.ImageLibraryFallbackRecord](../../../by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md).

Validation commands/results:

- `python .\tools\validator.py --mode file --file .\by-memory\0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators.md --apply --queue-timeout 240`: exited `0`; visible output included `completion_update 00024G ... 86`, `confidence_update 00024G ... 91`, one reference-index addition for `00029K`, removal from `Low_Completion`, `Low_Both`, and by-memory project stats, and `ok: 1`.

## Current pending supervisor-owned rows

- None. The supervisor applied and validated the Goal 2 [UID:00024G] `StaticDestructorWrappersBeforePoolAllocators` `by-memory/-coverage-report.md` replacement row on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.

## 2026-06-13 Goal2 - ConfirmDeleteMailAlert constructor/action parent repair

Changed files:

- `by-memory/0x0047e4b0-0x0047e508.ConfirmDeleteMailAlertRawConstructor.md`
- `by-class/ConfirmDeleteMailAlert.md`
- `by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md`
- `by-file/BulletinReplyAlerts.md`
- `by-file/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Supervisor-applied `by-memory/-coverage-report.md` replacement/insert rows:

- The supervisor applied and validated the [UID:0000ZM] `BulletinMailAlertCompanions` replacement row and inserted the [UID:0003MZ] `ConfirmDeleteMailAlertRawConstructor` child row on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal2 ConfirmDeleteMailAlert supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

Supervisor-applied `by-class/-coverage-report.md` replacement row:

- The supervisor applied and validated the [UID:000034] `ConfirmDeleteMailAlert` `by-class/-coverage-report.md` replacement row on 2026-06-13 after the class coverage lease was released.
- Validation command: `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal2 ConfirmDeleteMailAlert supervisor-owned coverage-report rows remain pending.

## 2026-06-13 Goal2 - DialogPaneSlideAnimation class-parent refresh

Changed files:

- `by-memory/0x0049eac0-0x0049f07e.DialogPaneSlideAnimation.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated side effects: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, validator registry/reference state, and projected-path stats refresh.
- `by-memory/-coverage-report.md` was not manually edited by A002 per supervisor override; supervisor applied and validated the replacement row after review.

Score/parent/routing decisions:

- [UID:00012U] `DialogPaneSlideAnimation`: `76/84 -> 86/90`; `AUTOGEN_PARENT_UID` rerouted from file parent [UID:0000IT][DialogPane](../../../by-file/DialogPane.md) to direct class parent [UID:00003T][DialogPane](../../../by-class/DialogPane.md). `RECONSTRUCTABLE:TRUE`; C++ remains blank below the final-source gate because `0x0049ee50` and `0x0049ef60` are raw helper bodies and final helper names remain unproven.
- Direct parent [UID:00003T] was read as `85/86`; file route [UID:0000IT] was read as `86/85`; containing aggregate [UID:00012R] was read as `86/88`. The target-to-class and class-to-file routes clear the strict `85/85` gate.

Evidence:

- Live IDA MCP session `a001_goal2_0002UM` on 2026-06-13 confirms modeled helper starts/sizes: `0x0049eac0` size `0xcd` / 205, `0x0049eb90` size `0xe2` / 226, `0x0049ec80` size `0xd8` / 216, and `0x0049ed60` size `0xe2` / 226. Conversions were verified with `tools/int_convert.py`.
- `lookup_funcs` reports `0x0049ee50`, `0x0049ef60`, `0x0049f07e`, and `0x0049f080` as not functions, with next modeled function `0x0049f090`.
- `xref_query` reports code xref totals / unique caller functions: `0x0049eac0` `48/45`, `0x0049eb90` `74/61`, `0x0049ec80` `4/4`, and `0x0049ed60` `6/5`; no direct xrefs were found to `0x0049ee50` or `0x0049ef60`.
- Raw disassembly confirms the two unmodeled helper bodies load [UID:0000S7][g_pScreenPane](../../../by-global/g_pScreenPane.md) / `dword_67A7CC`, call `sub_544710`, `0x004b7e10`, virtual slot `+0x2c`, `sub_5549D0`, `sub_557140`, and `@__security_check_cookie@4`, with `0x0049ef59 retn 4` and `0x0049f07e retn 4`.
- `get_bytes 0x0049f07e size 18` returned `c2 04 00` followed by `0xcc` padding; `make_signature_for_range 0x0049ee50-0x0049ef59` and `0x0049ef60-0x0049f07e` returned unique signatures.

Validation commands/results:

- `python .\tools\validator.py --mode file --file .\by-memory\0x0049eac0-0x0049f07e.DialogPaneSlideAnimation.md --apply --queue-timeout 240`: exited `0`; visible output included `completion_update 00012U ... 86`, `confidence_update 00012U ... 90`, `autogen_registry_update 00012U ... 0000IT -> 00003T`, four reference-index additions, removal from `Low_Completion`, `Low_Both`, and by-memory project stats, `auto-generated/-ag-memory-coverage.md` update, and `ok: 1`.
- Validator also reported unrelated `autogen_registry_stale 00012Y ... registered file is missing` while A003 had active leases for the VersatileAlertPane target area; A002 did not touch that leased work.

## Current pending supervisor-owned rows

- None. The supervisor applied and validated the Goal 2 [UID:00012U] `DialogPaneSlideAnimation` `by-memory/-coverage-report.md` replacement row on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. The validator also reported the unrelated C001-owned [UID:0001NP] MenuVariety path while that barrier repair was active.

## 2026-06-13 Goal2 - FolderSelectDialog class-parent refresh

Changed files:

- `by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated side effects: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, validator registry/reference state, and projected-path stats refresh.
- `by-memory/-coverage-report.md` was not manually edited by A002 per supervisor override; exact replacement row is pending below.

Score/parent/routing decisions:

- [UID:000154] `FolderSelectDialog`: `76/84 -> 86/90`; `AUTOGEN_PARENT_UID` rerouted from file parent [UID:0000JF][FolderSelectDialog](../../../by-file/FolderSelectDialog.md) to direct class parent [UID:000059][FolderSelectDialog](../../../by-class/FolderSelectDialog.md). `RECONSTRUCTABLE:TRUE`; C++ remains blank below the 95/95 final-source gate because final callback type, field/helper names, and the standalone `0x004b1a00` source reachability are still open.
- Direct parent [UID:000059] was read as `85/86`; file route [UID:0000JF] was read as `86/88`. The target-to-class and class-to-file routes both clear the strict `85/85` gate, so no support parent edits were needed.

Evidence:

- Live IDA MCP database `a001_goal2_0002UM` on 2026-06-13 `lookup_funcs` reconfirmed island function starts/sizes: `0x004b1590` size `0x346`, `0x004b1920` size `0xe0`, `0x004b1a00` size `0x105`, `0x004b1b05` size `0x0b`, `0x004b1b10` size `0x0b`, and `0x004b1b20` size `0x67`; `0x004b18d6` and `0x004b1b87` are not function starts.
- `analyze_component` listed shared globals as the three `FolderSelectDialog` vtable bases, `asc_66DA88`, and the compiler security cookie; it reported `0x004b1590` as the interface function and the other island functions as internal-only.
- Backward data flow confirmed the only direct constructor caller at `0x0052986d` inside `sub_529790`, a vtable slot reference to `OnCommand` at `0x0061a4a4`, and no direct caller for the standalone drive-list helper `0x004b1a00`.
- Backward data flow confirmed vtable stores for `0x0061a45c`, `0x0061a4bc`, and `0x0061a4ec` from constructor, cleanup, and destructor code; `0x0061a4f4` has the constructor read; `0x0066da88` has only four refs from the constructor and drive-list helper.
- Live decompilation confirmed constructor vtable/callback/tree/drive-list behavior, `OnCommand` OK/cancel callback dispatch and drive-root reset, standalone helper drive enumeration, and destructor callback cleanup plus scalar-delete behavior.

Validation commands/results:

- `python .\tools\validator.py --mode file --file .\by-memory\0x004b1590-0x004b1b87.FolderSelectDialog.md --apply --queue-timeout 240`: exited `0`; visible output included `completion_update 000154 ... 86`, `confidence_update 000154 ... 90`, `autogen_registry_update 000154 ... 0000JF -> 000059`, three reference-index additions, removal from `Low_Completion`, `Low_Both`, and by-memory project stats, `auto-generated/-ag-memory-coverage.md` update, and `ok: 1`.
- Validator also reported unrelated `autogen_registry_stale 000163 by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md registered file is missing`; A002 did not touch that target.
- Post-validation checks: `project-level/-auto-completion-stats.md` no longer lists [UID:000154]; `auto-generated/-ag-memory-coverage.md` lists [UID:000154] assigned to parent `000059`.

## Supervisor-applied shared-file rows

- The supervisor applied and validated the [UID:000154] `FolderSelectDialog` `by-memory/-coverage-report.md` replacement row on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 [UID:000154] supervisor-owned `by-memory/-coverage-report.md` row remains pending.

## 2026-06-13 Goal2 - IconsPane OnPaint method refresh

Changed files:

- `by-memory/0x004cf300-0x004cf3d3.IconsPaneOnPaint.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated side effects: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, validator registry/reference state, and projected-path stats refresh.
- `by-memory/-coverage-report.md` was not manually edited by A002 per supervisor override; exact replacement row is pending below.

Score/parent/routing decisions:

- [UID:0002T1] `IconsPaneOnPaint`: `76/84 -> 86/90`; `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains direct class parent [UID:00006B] `IconsPane`; `AUTOGEN_PARENT_POSITION_OPTIONAL` remains `60`.
- Direct parent [UID:00006B] `IconsPane` was read at `85/85`; source-file parent [UID:0000JZ] `IconsPane` was read at `86/85`. The target and direct parent clear the strict `85/85` gate, so no routing change was needed.
- Final C++ remains blank because the shared render/helper callees `sub_4D02F0`, `sub_4B9980`, `sub_457A60`, and `unk_69B3FC` still need final cross-page names/signatures before the `95+` source gate can be met.

Evidence:

- Live IDA MCP session `a001_goal2_0002UM` on 2026-06-13 `lookup_funcs` confirmed `sub_4CF300` at `0x004cf300` with size `0xd3` / 211 decimal (Verified with int_convert.py), no function at `0x004cf3d3`, and successor `sub_4CF3E0` at `0x004cf3e0`.
- `analyze_function`, `decompile`, and `disasm` confirmed the virtual paint body, seven basic blocks, no direct code callers, one data xref from vtable slot `0x0061b48c`, field reads/writes at `this + 0x70`, `+0xf8`, `+0xfc`, and `+0x100`, and the helper call sequence.
- `get_bytes` confirmed UTF-16 `ICONS.EPD` bytes at `0x0061b554` and UTF-16 `NPAL7.PAL` bytes at `0x006152ec`; `xref_query` confirmed `0x0061b554` is referenced by this paint method and `0x006152ec` is the palette argument used at `0x004cf385`.
- `make_signature_for_range 0x004cf300-0x004cf3d3` returned a unique full-range byte signature.
- Numeric constants `0xd3`, `0xa0`, `0x14`, `0xe`, `0x8`, `0x6`, and `0x13` were checked with `tools/int_convert.py`.

Validation commands/results:

- `python .\tools\validator.py --mode file --file .\by-memory\0x004cf300-0x004cf3d3.IconsPaneOnPaint.md --apply --queue-timeout 240`: exited `0`; visible output included `completion_update 0002T1 ... 86`, `confidence_update 0002T1 ... 90`, removal from `Low_Completion`, `Low_Both`, and by-memory project stats, `autogen_report_update` for `auto-generated/-ag-memory-coverage.md`, and `ok: 1`.
- Validator also reported unrelated `autogen_registry_stale 0001JM by-memory/0x0058dce0-0x005917c9.TextEditPaneCore.md registered file is missing`; A002 did not touch that target.

## Supervisor-applied rows

- Supervisor applied and validated the [UID:0002T1] `IconsPaneOnPaint` `by-memory/-coverage-report.md` replacement row on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 [UID:0002T1] supervisor-owned `by-memory/-coverage-report.md` row remains pending.

## 2026-06-13 Goal2 - IconsPane HitTestIcon method refresh

Changed files:

- `by-memory/0x004cf7d0-0x004cf862.IconsPaneHitTestIcon.md`
- `by-memory/-ignored.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated side effects: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, validator registry/reference state, and projected-path stats refresh.
- `by-memory/-coverage-report.md` was not manually edited by A002 per supervisor override; exact replacement/insert rows are pending below.

Score/parent/routing decisions:

- [UID:0002T3] `IconsPaneHitTestIcon`: `76/84 -> 86/90`; `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains direct class parent [UID:00006B] `IconsPane`; `AUTOGEN_PARENT_POSITION_OPTIONAL` remains `80`.
- Direct parent [UID:00006B] `IconsPane` was read at `85/85`; source-file parent [UID:0000JZ] `IconsPane` was read at `86/85`. The target and direct parent clear the strict `85/85` gate, so no routing change was needed.
- The adjacent `0x004cf862-0x004cf870` bytes were added to [UID:0000VN] `by-memory/-ignored.md` as verified alignment padding between `IconsPaneHitTestIcon` and `IconsPaneSetIconHighlight`.
- Final C++ remains blank because `sub_4B7E80` and final event/field names still need cross-page naming before the `95+` source gate can be met.

Evidence:

- Live IDA MCP session `a001_goal2_0002UM` on 2026-06-13 `lookup_funcs` confirmed `sub_4CF7D0` at `0x004cf7d0` with size `0x92` / 146 decimal (Verified with int_convert.py), no function at `0x004cf862`, and successor `sub_4CF870` at `0x004cf870`.
- `analyze_function`, `decompile`, and `disasm` confirmed a `thiscall` two-coordinate helper with five basic blocks, callee `sub_4B7E80`, stack rectangle construction, `this + 0xf8` reduced/full-mode flag, slot stride `0x14` / 20 decimal, right edge `0x13` / 19 decimal, bottom edge `0x0e` / 14 decimal, stop limit `0xa0` / 160 decimal, and miss sentinel `-1`.
- `xref_query` found the four direct `OnMouseEvent` call sites at `0x004cf44e`, `0x004cf4a2`, `0x004cf667`, and `0x004cf6b0`; live `OnMouseEvent` decompilation showed the helper receives `Block[2]` and `Block[3]` coordinate fields.
- `get_bytes 0x004cf862 size 14` returned fourteen `0xcc` bytes, confirming the ignored padding gap.
- `make_signature_for_range 0x004cf7d0-0x004cf862` returned a unique full-range byte signature.

Validation commands/results:

- `python .\tools\validator.py --mode file --file .\by-memory\0x004cf7d0-0x004cf862.IconsPaneHitTestIcon.md --apply --queue-timeout 240`: exited `0`; visible output included `completion_update 0002T3 ... 86`, `confidence_update 0002T3 ... 90`, reference-index update for [UID:0000VN], removal from `Low_Completion`, `Low_Both`, and by-memory project stats, `autogen_report_update` for `auto-generated/-ag-memory-coverage.md`, and `ok: 1`.
- `python .\tools\validator.py --mode file --file .\by-memory\-ignored.md --apply --queue-timeout 240`: exited `0`; visible output included reference-index additions for [UID:0002T3] and [UID:0002T4], `stats_incremental_noop 0000VN`, `autogen_report_noop 7`, and `ok: 1`.
- No unrelated stale warnings appeared in these two validation runs.

## Current pending supervisor-owned rows

- None. The supervisor applied and validated the Goal 2 [UID:0002T3] `IconsPaneHitTestIcon` `by-memory/-coverage-report.md` replacement row and the adjacent [UID:0000VN] padding row on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.

## 2026-06-13 Goal2 - IconsPane SetIconHighlight method refresh

Changed files:

- `by-memory/0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated side effects: `project-level/-auto-completion-stats.md`, validator registry/reference state, and projected-path stats refresh. `auto-generated/-ag-memory-coverage.md` already listed [UID:0002T4] as assigned and was unchanged by this scoped validation run.
- `by-memory/-coverage-report.md` was not manually edited by A002 per supervisor override; exact replacement row is pending below.

Score/parent/routing decisions:

- [UID:0002T4] `IconsPaneSetIconHighlight`: `76/84 -> 86/90`; `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains direct class parent [UID:00006B] `IconsPane`; `AUTOGEN_PARENT_POSITION_OPTIONAL` remains `90`.
- Direct parent [UID:00006B] `IconsPane` was read at `85/85`; source-file parent [UID:0000JZ] `IconsPane` was read at `86/85`. The target and direct parent clear the strict `85/85` gate, so no routing change was needed.
- Existing [UID:0000VN] `by-memory/-ignored.md` already records `0x004cf8d5-0x004cf8e0` as alignment padding after this helper; no support-doc edit was required.
- Final C++ remains blank because the base pane invalidation virtual and final field/event names still need cross-page naming before the `95+` source gate can be met.

Evidence:

- Live IDA MCP session `a001_goal2_0002UM` on 2026-06-13 `lookup_funcs` confirmed `sub_4CF870` at `0x004cf870` with size `0x65` / 101 decimal (Verified with int_convert.py), no function at `0x004cf8d5`, and no IDA function object at the adjacent raw action-dispatch start `0x004cf8e0`.
- `analyze_function`, `decompile`, and `disasm` confirmed a `thiscall` helper with three basic blocks, a state-change guard comparing requested state against `this + 0x100`, selected icon read from `this + 0xfc`, rectangle construction with slot stride `0x14` / 20 decimal, right edge `0x13` / 19 decimal, bottom edge `0x0e` / 14 decimal, virtual invalidation call through vtable slot `0x20` / 32 decimal, and writeback to `this + 0x100`.
- `xref_query` found the four direct `OnMouseEvent` call sites at `0x004cf473`, `0x004cf678`, `0x004cf686`, and `0x004cf71b`; live `OnMouseEvent` decompilation showed requested state `1` on mouse-down/inside-drag and `0` on outside-drag/mouse-up release.
- `get_bytes 0x004cf8d5 size 11` returned eleven `0xcc` bytes, confirming the existing ignored padding gap before the raw action-dispatch bytes.
- `make_signature_for_range 0x004cf870-0x004cf8d5` returned a unique full-range byte signature.

Validation commands/results:

- `python .\tools\validator.py --mode file --file .\by-memory\0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight.md --apply --queue-timeout 240`: exited `0`; visible output included `completion_update 0002T4 ... 86`, `confidence_update 0002T4 ... 90`, reference-index addition for [UID:0002T3], removal from `Low_Completion`, `Low_Both`, and by-memory project stats, `projected_stats_update`, `autogen_report_noop 7`, and `ok: 1`.
- Validator also emitted `stats_rescore_recommended 0002T4`; this is an occasional full/documented/rescore recommendation after enough low-score rows drop, not a target-specific failure.
- No unrelated stale warnings appeared in this validation run.

## Current pending supervisor-owned rows

- None. The supervisor applied and validated the Goal 2 [UID:0002T4] `IconsPaneSetIconHighlight` `by-memory/-coverage-report.md` replacement row on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.

## 2026-06-13 Goal2 - EffectObjectPane StartIdleTimer method refresh

Changed files:

- `by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md`
- `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated side effects: `project-level/-auto-completion-stats.md`, `auto-generated/-ag-memory-coverage.md`, validator registry/reference state, and projected-path stats refresh.
- `by-memory/-coverage-report.md` was not manually edited by A002 per supervisor override; exact [UID:0001DA] replacement row is pending below.

Score/parent/routing decisions:

- [UID:0001DA] `EffectObjectPaneStartIdleTimer`: `76/84 -> 86/90`; `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains direct class parent [UID:000049] `EffectObjectPane`; `AUTOGEN_PARENT_POSITION_OPTIONAL` remains blank.
- Direct parent [UID:000049] `EffectObjectPane` was read at `85/86`; source-file parent [UID:0000IZ] `Effects` was read at `89/85`. The target and direct parent clear the strict `85/85` gate, so no routing change was needed.
- Support dependency [UID:0001K8] `TimerHandlerScheduleRemoveWrappers`: `86/84 -> 86/86`; parent remains [UID:0000OT] `TimerMgr`. This refresh keeps the generic schedule-wrapper evidence above the `85/85` support gate used by the target.
- Final C++ remains blank for both docs because timer-subobject/member names and final TimerHandler wrapper method names are still below the `95+` source gate.

Evidence:

- Live IDA MCP session `a001_goal2_0002UM` on 2026-06-13 `lookup_funcs` confirmed `sub_5388A0` at `0x005388a0` with size `0x14` / 20 decimal (Verified with int_convert.py), no function at `0x005388b4`, and successor `sub_5388C0` at `0x005388c0`.
- `analyze_function`, `decompile`, and disassembly confirmed the target is a one-basic-block shim that pushes `0`, `0`, `0`, `1`, adjusts `ecx` by `+0xa4` / 164 decimal (Verified with int_convert.py), and calls `sub_5975E0`.
- `xref_query 0x005388a0` found the sole direct code caller at `0x0050eb14` inside `sub_50EA30`; live caller decompilation showed allocation from [UID:0002WO] `EffectObjectPanePoolStaticStorage`, construction through `sub_5387B0`, object/list insertion, this timer-start call, and optional later scheduling through `sub_597910` on the same object pointer plus `0xa4`.
- `get_bytes` confirmed `0x0053889f-0x005388a0` as one `0xcc` byte, exact body bytes at `0x005388a0-0x005388b4`, and `0x005388b4-0x005388c0` as twelve `0xcc` bytes.
- `make_signature_for_range 0x005388a0-0x005388b4` returned a unique full-range byte signature.
- Support `analyze_function 0x005975e0` reconfirmed the TimerHandler schedule wrapper as a `0x1f` / 31 decimal byte (Verified with int_convert.py) one-block `g_pTimerMgr` forwarder to `sub_597910`, with `163` direct code references including the target call site at `0x005388ae`.

Validation commands/results:

- `python .\tools\validator.py --mode file --file .\by-memory\0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md --apply --queue-timeout 240`: exited `0`; visible output included `stats_incremental_noop 0001K8 ... file is not present in generated stats lists`, `projected_stats_update`, `autogen_report_noop 7`, and `ok: 1`.
- `python .\tools\validator.py --mode file --file .\by-memory\0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md --apply --queue-timeout 240`: exited `0`; visible output included `stats_incremental_noop 0001DA ... file is not present in generated stats lists`, `projected_stats_update`, `autogen_report_noop 7`, and `ok: 1`.
- No unrelated stale warnings appeared in these two validation runs.
- Post-validation check: `project-level/-auto-completion-stats.md` no longer lists [UID:0001DA].

## Current pending supervisor-owned rows

- None. The supervisor applied and validated the Goal 2 [UID:0001DA] `EffectObjectPaneStartIdleTimer` `by-memory/-coverage-report.md` replacement row on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.

## 2026-06-13 Goal2 type-quality - ScrollVolumePaneVtables

Changed files:

- `by-type/by-vtable/ScrollVolumePaneVtables.md`
- `by-type/by-vtable/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated side effects: `project-level/-auto-completion-stats.md`, `auto-generated/-ag-type-coverage.md`, validator registry/reference state, and projected-path stats refresh.
- No `by-memory/-coverage-report.md` edit or pending row was needed.

Score/parent/routing decisions:

- [UID:0001YT] `ScrollVolumePaneVtables`: `74/86 -> 86/89`; `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains direct class parent [UID:0000CO] `ScrollVolumePane`.
- Direct parent [UID:0000CO] `ScrollVolumePane` was read at `87/85`; source-file parent [UID:0000NK] `ScrollVolumePane` was read at `88/85`; support layout [UID:0001W2] `ScrollVolumePaneLayout` was read at `87/88`. The target and direct parent clear the strict `85/85` gate, so no routing change was needed.
- Corrected the target's stale slot wording: live dword reads show `0x0062412c` is the tertiary complete-object-locator pointer and `0x00624130` is the tertiary table start, so `0x00624134` is tertiary `+0x04`, not secondary `+0x34`.
- Final C++ remains blank because this is compiler-emitted vtable/type data and final inherited pane-interface declarations are still below the `95+` source gate.

Evidence:

- Live IDA MCP session `a001_goal2_0002UM` on 2026-06-13 `lookup_funcs` confirmed constructor `0x00564710` size `0xa1`, mouse handler `0x00564910` size `0x1e1`, false-return virtual `0x00564b00` size `0x5`, focus/commit helper `0x00564b10` size `0x33`, paint `0x00564b50` size `0x2d1`, and adjacent tail functions `0x005654ec`, `0x005654f7`, and `0x00565510`.
- Constructor disassembly confirmed vtable stores at `0x00564761`, `0x00564767`, and `0x00564771` to object offsets `+0`, `+0xa0`, and `+0xa4`.
- `get_int` across `0x006240b0-0x00624138` confirmed complete-object-locator dwords at `0x006240b0`, `0x006240fc`, and `0x0062412c`, with primary, secondary, and tertiary function-pointer spans `0x006240b4-0x006240fc`, `0x00624100-0x0062412c`, and `0x00624130-0x00624138`.
- `xrefs_to` confirmed one constructor-store data xref to each vtable base and table-dword data xrefs from `0x006240f8`, `0x00624104`, `0x00624108`, and `0x00624134` to paint/mouse/false/focus targets.
- Tail exclusion remains stable: `0x005654ec` is data-referenced by `0x00623e58` and subtracts `0xa0`; `0x005654f7` is data-referenced by `0x00623e88` and subtracts `0xa4`; both jump to `0x00565510`, which has its own `ScrollablePane` table ref at `0x00623de4`.
- Verified with `tools/int_convert.py`: `0x4c` / 76 bytes, `0x30` / 48 bytes, `0x44` / 68 bytes, `0xa0` / 160 bytes, `0xa4` / 164 bytes, `0x88` / 136 bytes, and `0x110` / 272 bytes.

Validation commands/results:

- `python .\tools\validator.py --mode file --file .\by-type\by-vtable\ScrollVolumePaneVtables.md --apply --queue-timeout 240`: exited `0`; visible output included `completion_update 0001YT ... 86`, `confidence_update 0001YT ... 89`, `reference_index_add 0003CP`, removal from `Low_Completion`, `Low_Both`, and by-type stats, `stats_rescore_recommended 0001YT`, and `ok: 1`.
- `python .\tools\validator.py --mode file --file .\by-type\by-vtable\ScrollVolumePaneVtables.md --apply --queue-timeout 240`: rerun after coverage-row sync exited `0`; visible output included `stats_incremental_noop 0001YT ... file is not present in generated stats lists` and `ok: 1`.
- `python .\tools\validator.py --mode file --file .\by-type\by-vtable\-coverage-report.md --apply --queue-timeout 240`: exited `0`; visible output included `stats_incremental_noop 0001WW ... file is not present in generated stats lists` and `ok: 1`.
- No unrelated stale warnings appeared in these validation runs.

## Current pending supervisor-owned rows

- None. The by-vtable coverage-report row for [UID:0001YT] was applied under an A002 lease and validated; no `by-memory/-coverage-report.md` rows were needed.

## 2026-06-13 Goal2 global-quality - g_pItemHelpPane

Changed files:

- `by-global/g_pItemHelpPane.md`
- `by-global/-coverage-report.md`
- `by-memory/0x0069ae04-0x0069ae08.g_pItemHelpPane.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated side effects: `project-level/-auto-completion-stats.md`, `auto-generated/-ag-global-coverage.md`, validator registry/reference state, and projected-path stats refresh.
- The supervisor applied and validated the exact [UID:0001PD] `by-memory/-coverage-report.md` replacement row on 2026-06-13.

Score/parent/routing decisions:

- [UID:0000R9] `g_pItemHelpPane`: `82/85 -> 86/88`; `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains direct file parent [UID:0000JU] `HelpPanes`.
- Direct parent [UID:0000JU] `HelpPanes` was read at `90/86`; the target and direct parent clear the strict `85/85` gate. No parent change was needed.
- Exact storage [UID:0001PD] `0x0069ae04-0x0069ae08.g_pItemHelpPane` remains `86/90` under [UID:0000JU] `HelpPanes`; evidence was corrected from stale `ff ff ff ff` / `0xffffffff` wording to current IDB bytes `00 00 00 00` / `0`.
- Support class [UID:00006U] `ItemHelpPane` was read at `86/82`; it is supporting behavior evidence, not the direct parent, because the final original-source split between `HelpPanes.cpp` and possible `ItemHelpPane.cpp` remains open.
- Final C++ remains blank because this global and storage page are below the `95/95` source gate.

Evidence:

- Live IDA MCP session `a001_goal2_0002UM` on 2026-06-13 `get_bytes` and `get_int` at `0x0069ae04` returned current bytes `00 00 00 00` and dword value `0`.
- `xrefs_to 0x0069ae04` reconfirmed all 20 direct data xrefs, including constructor publish/fallback clear at `0x004c832e`/`0x004c8335`, destructor/helper/deleting-destructor clears at `0x004c8ba1`, `0x004ce310`, and `0x004ce4b2`, `DismissItemHelp` at `0x004ccc80`, and item/inventory/tooltip UI reader clusters.
- Constructor disassembly at `0x004c82d0` publishes the object pointer before the three `ItemHelpPane` vtable installs, and the non-deleting/scalar-deleting destructors clear the singleton during teardown.
- `DismissItemHelp` at `0x004ccc80` is a `0x15` / 21 decimal byte singleton close helper (Verified with `tools/int_convert.py`) that loads the global, null-checks, pushes `1`, and calls virtual slot `0`.
- Additional size/offset conversions were verified with `tools/int_convert.py`: four-byte storage, `0x843` / 2115 byte constructor, `0xa2` / 162 byte non-deleting destructor, `0xb` / 11 byte clear helper, `0xcb` / 203 byte scalar deleting destructor, and `0x630` / 1584 bytes for the stat-buffer member boundary.

Validation commands/results:

- `python .\tools\validator.py --mode file --file .\by-global\g_pItemHelpPane.md --apply --queue-timeout 240`: exited `0`; visible output included `completion_update 0000R9 ... 86`, `confidence_update 0000R9 ... 88`, `stats_row_remove 0000R9 project-level/-auto-completion-stats.md by-global`, `stats_rescore_recommended 0000R9`, `projected_stats_update`, `autogen_report_noop 7`, and `ok: 1`.
- `python .\tools\validator.py --mode file --file .\by-memory\0x0069ae04-0x0069ae08.g_pItemHelpPane.md --apply --queue-timeout 240`: exited `0`; visible output included `stats_incremental_noop 0001PD ... file is not present in generated stats lists`, `projected_stats_update`, `autogen_report_noop 7`, and `ok: 1`.
- `python .\tools\validator.py --mode file --file .\by-global\-coverage-report.md --apply --queue-timeout 240`: exited `0`; visible output included `stats_incremental_noop 0000PD ... file is not present in generated stats lists`, `projected_stats_update`, `autogen_report_noop 7`, and `ok: 1`.
- No unrelated stale warnings appeared beyond routine validator no-op/rescore messages.

## Current pending supervisor-owned rows

- None. The supervisor applied and validated the [UID:0001PD] row on 2026-06-13.

## 2026-06-13 Goal2 global-quality - g_selfLookLastHoverEquipmentSlotId

Changed files:

- `by-global/g_selfLookLastHoverEquipmentSlotId.md`
- `by-memory/0x0066fe40-0x0066fe44.SelfLookPaneLastHoverEquipmentSlotId.md`
- `by-global/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated side effects: `project-level/-auto-completion-stats.md`, validator registry/reference state, and projected-path stats refresh.
- `by-memory/-coverage-report.md` was not manually edited by A002 per supervisor override; exact [UID:000283] replacement row is pending below.

Score/parent/routing decisions:

- [UID:0002CG] `g_selfLookLastHoverEquipmentSlotId`: `82/86 -> 86/89`; `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains direct file parent [UID:0000NL] `SelfLookPane`.
- Direct parent [UID:0000NL] `SelfLookPane` was read at `85/89`; support class [UID:0000CU] `SelfLookPane` was read at `85/88`; exact storage [UID:000283] `0x0066fe40-0x0066fe44.SelfLookPaneLastHoverEquipmentSlotId` was raised from `82/86 -> 86/89`. The target and direct parent clear the strict `85/85` gate, so no parent/routing change was needed.
- Final C++ remains blank for the global/storage docs because the original declaration spelling and surrounding timer/slot-state field names remain below the `95/95` final-source gate.

Evidence:

- Live IDA MCP session `a001_goal2_0002UM` on 2026-06-13 `get_bytes` at `0x0066fe40` returned `ff ff 00 00 20 00 09 00 00 00 00 00 00 00 00 00`; `get_int` returned first word `65535` (`0xffff`) and following alignment word `0`.
- `xrefs_to 0x0066fe40` returned exactly two data xrefs, compare `0x005692c7` and write `0x00569310`, both inside `sub_568CB0`.
- `lookup_funcs` reconfirmed `sub_568CB0` at `0x00568cb0` size `0x69a`, `HitTestSlot` at `0x0056a300` size `0x73`, schedule wrapper `0x005975e0` size `0x1f`, and remove wrapper `0x00597600` size `0x0d`.
- Disassembly/decompilation reconfirmed the hover branch: `0x005692aa` calls `sub_56A300`, `0x005692b8` rejects `0xffff`, `0x005692be-0x005692c5` accepts `(slotId - 7) <= 0x0d` (`7..20`), `0x005692c7` compares the cached word, changed slots call `0x00597600` and then `0x005975e0` with `1000` ms, `0x00569310` writes the accepted slot, and `0x0056931a` writes the state byte at `this + 0x1655 + slotId` before redraw.
- Verified with IDA `int_convert`: `0x69a` / 1690 bytes, `0x73` / 115 bytes, `0x1f` / 31 bytes, `0x0d` / 13 bytes, `0x3e8` / 1000, `0x1655` / 5717, `20` / `0x14`, and `7` / `0x7`.

Validation commands/results:

- `python .\tools\validator.py --mode file --file .\by-global\g_selfLookLastHoverEquipmentSlotId.md --apply --queue-timeout 240`: exited `0`; visible output included `completion_update 0002CG ... 86`, `confidence_update 0002CG ... 89`, `stats_row_remove 0002CG project-level/-auto-completion-stats.md by-global`, `stats_rescore_recommended 0002CG`, `projected_stats_update`, `autogen_report_noop 7`, and `ok: 1`.
- `python .\tools\validator.py --mode file --file .\by-memory\0x0066fe40-0x0066fe44.SelfLookPaneLastHoverEquipmentSlotId.md --apply --queue-timeout 240`: exited `0`; visible output included `completion_update 000283 ... 86`, `confidence_update 000283 ... 89`, `stats_incremental_noop 000283 ... file is not present in generated stats lists`, `projected_stats_update`, `autogen_report_noop 7`, and `ok: 1`.
- `python .\tools\validator.py --mode file --file .\by-global\-coverage-report.md --apply --queue-timeout 240`: exited `0`; visible output included `stats_incremental_noop 0000PD ... file is not present in generated stats lists`, `projected_stats_update`, `autogen_report_noop 7`, and `ok: 1`.
- No unrelated stale warnings appeared beyond routine validator no-op/rescore messages.

## Current pending supervisor-owned rows

- Supervisor applied and validated the [UID:000283] `by-memory/-coverage-report.md` replacement row on 2026-06-13. No supervisor-owned rows remain pending for this item.

## 2026-06-13 Goal2 global-quality - g_pHeightModifyPane

Changed files:

- `by-global/g_pHeightModifyPane.md`
- `by-memory/0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md`
- `by-global/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated side effects: `project-level/-auto-completion-stats.md`, `auto-generated/-ag-global-coverage.md`, validator registry/reference state, and projected-path stats refresh.
- `by-memory/-coverage-report.md` was not manually edited by A002 per supervisor override; exact [UID:0002AO] replacement row is pending below.

Score/parent/routing decisions:

- [UID:0000R2] `g_pHeightModifyPane`: `84/84 -> 86/89`; `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains direct file parent [UID:0000OE] `SystemMessagePanes`.
- Direct parent [UID:0000OE] `SystemMessagePanes` was read at `89/86`; support class [UID:00009B] `NewSystemMessageModifyHeightPane` was read at `85/87`.
- Exact storage [UID:0002AO] `0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots`: confidence `88 -> 89`, completion remains `86`; parent remains [UID:0000OE] `SystemMessagePanes`.
- The target, direct parent, primary class, and storage support page clear the strict `85/85` gate. No parent/routing change was needed.
- Final C++ remains blank for the global/storage docs because the original declaration spelling and surrounding field/helper names remain below the `95/95` final-source gate.

Evidence:

- Live IDA MCP session `a001_goal2_0002UM` on 2026-06-13 `get_bytes` at `0x0069bc0c` returned twelve zero bytes; `get_int` returned `0` at `0x0069bc0c`, `0x0069bc10`, and `0x0069bc14`, correcting the older all-`0xff` support-page wording.
- `xrefs_to 0x0069bc0c` returned exactly seven data xrefs: constructor publish/fallback null writes `0x00588239`/`0x00588240`, cleanup clear `0x005882da`, nested `NewSystemMessagePane` child-construction publish/fallback null writes `0x00588620`/`0x00588627`, clear helper `0x0058aaa0`, and scalar deleting destructor clear `0x0058ace0`.
- `xrefs_to 0x0069bc10` returned six refs for the adjacent `g_pNewSystemMessagePane` slot, and `xrefs_to 0x0069bc14` returned none, preserving the third dword as reviewed reserved/filler.
- Decompilation confirms standalone constructor `0x005881f0` stores `this` or `0` to `unk_69BC0C`, cleanup `0x005882c0`, helper `0x0058aaa0`, and scalar deleting destructor `0x0058acc0` clear it, and `NewSystemMessagePane` constructor `0x00588560` allocates `0x114` / 276 bytes for the owned height-modify child and publishes that child to the same singleton slot.
- `lookup_funcs` reconfirmed constructor `0x005881f0` size `0xc5`, cleanup `0x005882c0` size `0x29`, drag handler `0x005882f0` size `0x1bc`, nested owner constructor `0x00588560` size `0x238`, clear helper `0x0058aaa0` size `0x0b`, height scalar deleting destructor `0x0058acc0` size `0x5f`, and new-pane scalar deleting destructor `0x0058ad20` size `0x8b`.
- Verified with IDA `int_convert`: `0x114` / 276 bytes, `0x304` / 772 bytes, `0x0c` / 12 bytes, seven refs, and six refs.

Validation commands/results:

- `python .\tools\validator.py --mode file --file .\by-global\g_pHeightModifyPane.md --apply --queue-timeout 240`: exited `0`; visible output included `completion_update 0000R2 ... 86`, `confidence_update 0000R2 ... 89`, `reference_index_add 0002AO`, `stats_row_remove 0000R2 project-level/-auto-completion-stats.md by-global`, `stats_rescore_recommended 0000R2`, `projected_stats_update`, `autogen_report_noop 7`, and `ok: 1`.
- `python .\tools\validator.py --mode file --file .\by-memory\0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md --apply --queue-timeout 240`: exited `0`; visible output included `confidence_update 0002AO ... 89`, `stats_incremental_noop 0002AO ... file is not present in generated stats lists`, `projected_stats_update`, `autogen_report_noop 7`, and `ok: 1`.
- `python .\tools\validator.py --mode file --file .\by-global\-coverage-report.md --apply --queue-timeout 240`: exited `0`; visible output included `stats_incremental_noop 0000PD ... file is not present in generated stats lists`, `projected_stats_update`, `autogen_report_noop 7`, and `ok: 1`.
- No unrelated stale warnings appeared beyond routine validator no-op/rescore messages.

## Current pending supervisor-owned rows

- Supervisor applied and validated the [UID:0002AO] `by-memory/-coverage-report.md` replacement row on 2026-06-13. No supervisor-owned rows remain pending for this item.

## 2026-06-13 Goal2 global-quality - g_pEffectObjImageLib

Changed files:

- `by-global/g_pEffectObjImageLib.md`
- `by-global/-coverage-report.md`
- `by-class/EffectObjImageLib.md`
- `by-class/-coverage-report.md`
- `by-memory/0x0069b44c-0x0069b450.g_pEffectObjImageLib.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated side effects: `project-level/-auto-completion-stats.md`, `auto-generated/-ag-global-coverage.md`, validator registry/reference state, and projected-path stats refresh.
- `by-memory/-coverage-report.md` was not manually edited by A002 per supervisor override; exact [UID:0001PQ] replacement row is pending below.

Score/parent/routing decisions:

- [UID:0000QT] `g_pEffectObjImageLib`: `86/82 -> 86/89`; `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains direct file parent [UID:0000IY] `EffectObjImageLib`.
- Direct parent [UID:0000IY] `EffectObjImageLib` was read at `89/86`; support class [UID:00004A] `EffectObjImageLib` was raised `82/84 -> 85/87`; exact storage [UID:0001PQ] remains `86/90` with corrected live zero-byte evidence.
- The target, direct parent, support class, and storage page clear the strict `85/85` gate. No parent/routing change was needed.
- Consumers `MapPane`, `LivingObjectPane`, and `EffectObjectPane` remain documented as runtime users, not owners; source ownership stays with `EffectObjImageLib`.
- Final C++ remains blank because final declaration spelling, member names, and class/method source are below the `95/95` source gate.

Evidence:

- Live IDA MCP session `a001_goal2_0002UM` on 2026-06-13 `get_bytes` and `get_int` at `0x0069b44c` returned current bytes `00 00 00 00` and `u32le` value `0`, correcting stale `ff ff ff ff` / `0xffffffff` wording.
- `xrefs_to 0x0069b44c` returned exactly 12 direct data xrefs: lifecycle writes/clears at `0x004ddf9f`, `0x004ddfa6`, `0x004de167`, `0x004e5b70`, and `0x004e640e`; reads at `0x004f65d2`, `0x0050e331`, `0x0050e893`, `0x005388fa`, `0x00538982`, `0x00538b97`, and `0x005a2ee5`.
- Function lookup confirmed constructor `0x004ddf60` size `0xee`, destructor `0x004de050` size `0x13a`, clear helper `0x004e5b70` size `0x0b`, scalar deleting destructor `0x004e62f0` size `0x166`, shutdown reader `0x004f6490` size `0x215`, map readers `0x0050e320`/`0x0050e850`, effect-object readers `0x005388c0`/`0x00538960`/`0x00538af0`, and living/effect path `0x005a2e00` size `0x8de`.
- Decimal conversions were verified with IDA MCP `int_convert` / `tools/int_convert.py` wording in the target page: `0xee` / 238, `0x13a` / 314, `0x0b` / 11, `0x166` / 358, `0x215` / 533, `0x196` / 406, `0x1e0` / 480, `0x96` / 150, `0x69` / 105, `0xba` / 186, `0x8de` / 2270.

Validation commands/results:

- `python .\tools\validator.py --mode file --file .\by-global\g_pEffectObjImageLib.md --apply --queue-timeout 240`: exited `0`; visible output included `confidence_update 0000QT ... 89`, `stats_row_remove 0000QT project-level/-auto-completion-stats.md by-global`, `stats_rescore_recommended 0000QT`, `projected_stats_update`, `autogen_report_noop 7`, and `ok: 1`.
- `python .\tools\validator.py --mode file --file .\by-class\EffectObjImageLib.md --apply --queue-timeout 240`: exited `0`; visible output included `completion_update 00004A ... 85`, `confidence_update 00004A ... 87`, `stats_incremental_noop 00004A`, `projected_stats_update`, `autogen_report_noop 7`, and `ok: 1`.
- `python .\tools\validator.py --mode file --file .\by-memory\0x0069b44c-0x0069b450.g_pEffectObjImageLib.md --apply --queue-timeout 240`: exited `0`; visible output included `stats_incremental_noop 0001PQ`, `projected_stats_update`, `autogen_report_noop 7`, and `ok: 1`.
- `python .\tools\validator.py --mode file --file .\by-global\-coverage-report.md --apply --queue-timeout 240`: exited `0`; visible output included `stats_incremental_noop 0000PD`, `projected_stats_update`, `autogen_report_noop 7`, and `ok: 1`.
- `python .\tools\validator.py --mode file --file .\by-class\-coverage-report.md --apply --queue-timeout 240`: exited `0`; visible output included `stats_incremental_noop 000001`, `projected_stats_update`, `autogen_report_noop 7`, and `ok: 1`.
- No unrelated stale warnings appeared beyond routine validator no-op/rescore messages.

## Current pending supervisor-owned rows

Supervisor applied and validated the [UID:0001PQ] `by-memory/-coverage-report.md` replacement row on 2026-06-13. No supervisor-owned rows remain pending for this item.

## 2026-06-13 Goal2 StringBase batch - supervisor-applied coverage rows

- Supervisor applied and validated the `by-memory/-coverage-report.md` rows for [UID:0002RN], [UID:0001J3], [UID:0002RQ], [UID:0003NT], [UID:0002RR], [UID:0003NL], [UID:0001J4], and [UID:0003NM] on 2026-06-13.
- Score/owner summary: [UID:0002RN] `76/84 -> 86/89`; [UID:0002RQ] `76/84 -> 86/89`; [UID:0002RR] `76/84 -> 86/90` and `RECONSTRUCTABLE:FALSE`; [UID:0001J3] `84/88 -> 86/90`; new children [UID:0003NL] `86/89`, [UID:0003NM] `86/89`, and [UID:0003NT] `85/88`.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 StringBase supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Goal2 SpellInventory/ItemAction/BlockListen supervisor-applied coverage rows

- Supervisor applied and validated the `by-memory/-coverage-report.md` rows for [UID:0002RI], [UID:0002RL], [UID:0001ML], new nested children [UID:0003NX]-[UID:0003NZ], and [UID:0002RY] on 2026-06-13.
- Score/owner summary: [UID:0002RI] `76/84 -> 85/87`; [UID:0002RL] `76/84 -> 86/88` and `RECONSTRUCTABLE:FALSE`; [UID:0001ML] `76/84 -> 86/88`; new children [UID:0003NX], [UID:0003NY], and [UID:0003NZ] each `85/88`; [UID:0002RY] `76/84 -> 85/87`.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 SpellInventory/ItemAction/BlockListen supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Goal2 refreshed by-memory batch - LanguageMan/ArgumentedMenu/PaletteLib/SharedBoolean

Changed files:

- `by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md`
- `by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md`
- `by-class/ArgumentedMenuMenuDialog.md`
- `by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md`
- `by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md`
- `by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md`
- Validator/link-state side effects: `by-file/SystemMessagePanes.md`, `by-class/ColorStringSystemMessage.md`, `by-class/FooterSystemMessage.md`, `by-class/HeaderSystemMessage.md`, `by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md`, `tools/validator.ini`, `project-level/-auto-completion-stats.md`, `auto-generated/-ag-class-coverage.md`, `auto-generated/-ag-file-coverage.md`, `auto-generated/-ag-item-coverage.md`, `auto-generated/-ag-memory-coverage.md`.
- `by-memory/-coverage-report.md` was not manually edited by A002. The validator updated the UID link annotation for [UID:0001GG] during live target validation, but the row text/score/name still require the supervisor-owned replacement below.

Score/parent/routing decisions:

- [UID:00018R] `LanguageManLocalization`: `76/86 -> 86/89`; direct owner/emitter remains [UID:0000KK] `LanguageMan`. Live IDA evidence now covers all modeled functions, singleton/global/vtable refs, the cleanup/lookup/copy/clear helpers, padding, and [UID:00018T] as a file-level adjacent zero-initializer rather than a class method.
- [UID:0002TW] `ArgumentedMenuMenuDialog`: `76/86 -> 86/89`; direct owner/emitter repaired from broad [UID:0001BS] to [UID:00000H] `ArgumentedMenuMenuDialog`. Parent support [UID:00000H] was raised `82/84 -> 85/87`, and constructor size was corrected to `0x796`.
- [UID:0001E9] `PaletteLibPaletteFilterHelpers`: `76/86 -> 86/90`; direct owner/emitter repaired from [UID:0000MA] `Palette` to [UID:0000A1] `PaletteLib` with setter/updater callers, `g_pPaletteLib` refs, `0x0069b408` callback refs, `+0x758/+0x75c` behavior, and transformed-table rebuild evidence.
- [UID:0001GG] `SharedBooleanVirtualStubs`: `76/86 -> 86/89`; live file/range repaired to `by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md`. `CANONICAL_OWNER` is now `NONE` and `EMITTER_UIDS` is blank because the true/false virtual bodies are folded across system-message and effecter vtables, so no single by-file owner is justified.
- Final C++ remains blank for all four targets because none reached the active `90/90+` code-entry gate with final source-quality names.

Evidence:

- IDA MCP session `b001_0003gy` reconfirmed `00018R` function sizes at `0x004f0010`, `0x004f0290`, `0x004f0310`, `0x004f0350`, `0x004f0380`, `0x004f03c0`, and `0x004f03d0`; 351 lookup refs to `0x004f0350`; three refs to vtable `0x0061c9e0`; 192 refs to `g_pLanguageMan`; and exact `0xcc` padding.
- For `0002TW`, IDA reconfirmed constructor `0x0051e9a0` size `0x796`, raw `0x0051f140` as not a function/no xrefs, command/update functions at `0x0051f160`/`0x0051f250`, constructor callers `0x00517750` and `0x00517c97`, vtable stores to `0x0061f428`/`0x0061f488`/`0x0061f4b8`, `DLGMERC3.EPF` refs, and prompt refs at `0x0061f930`.
- For `0001E9`, IDA reconfirmed setter `0x00543f60` size `0x10`, updater `0x00543f80` size `0x170`, raw getter/successor as not functions, four setter callers, two updater callers, 83 refs to `g_pPaletteLib`, and filter-table behavior that skips slot `11`.
- For `0001GG`, IDA reconfirmed true stub `0x0055c1b0` and false stub `0x0055c1c0` as three-byte functions, successor `0x0055c1d0` size `0x2f`, 25 true-stub refs, 32 false-stub refs, named system-message vtable refs at `0x0062d6a0`/`0x0062d6ac`/`0x0062d6d0`/`0x0062d6f4`, effecter refs, and exact predecessor/stub/padding bytes.

Validation commands/results:

- `python .\tools\validator.py --mode file --file .\by-memory\0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md --apply --queue-timeout 240`: exited `0`; visible output included `path_update 0001GG`, `completion_update 0001GG 86`, `confidence_update 0001GG 89`, `canonical_owner_update 0001GG ... NONE`, `reference_source_path_update` entries, link annotation updates, and `ok: 1`.
- A validator loop then ran `python .\tools\validator.py --mode file --file <file> --apply --queue-timeout 240` for the four assigned targets, `by-class/ArgumentedMenuMenuDialog.md`, `by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md`, and the SystemMessage support docs touched by the `0001GG` link repair. The loop exited `0`; every file completed with `ok: 1`.
- The first target validation output included `completion_update 00018R 86`, `confidence_update 00018R 89`, `stats_row_remove 00018R` from Low_Completion/Low_Both/by-memory, `projected_stats_update`, and `autogen_report_update`.
- The stale-reference scan after validation found no stale live by-memory target docs for [UID:0001GG]. Remaining stale hits are supervisor/generated/read-only contexts: `by-memory/-coverage-report.md`, `project-level/-unresolved.md`, `by-project-structure/proposed-source-tree.md`, `tools/tmp-corrupt-by-memory-coverage-report-20260612-140047.md`, and old agent/supervisor notes. The target page's own "Before:" changelog intentionally mentions the stale range as history.

Lease state:

- A002 held active leases for all edited/validated live files during edits and validation. A003 held `by-class/-coverage-report.md`, so A002 did not edit that shared report and records the exact pending row below.

## Supervisor-applied shared-report rows

- Supervisor applied and validated the `by-memory/-coverage-report.md` replacement rows for [UID:00018R], [UID:0002TW], [UID:0001E9], and [UID:0001GG] on 2026-06-14.
- Supervisor applied and validated the `by-class/-coverage-report.md` replacement row for [UID:00000H] `ArgumentedMenuMenuDialog` on 2026-06-14.
- Validation commands:
  - `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No current supervisor/shared-report rows remain pending from this batch.

Read-only follow-ups:

- `by-project-structure/proposed-source-tree.md` still mentions `0x0055c1b0-0x0055c1c2` in the SystemMessagePanes rationale. The A002 goal file marks this non-`by-*` structure file read-only for this workflow, so a supervisor/tool-owned update should change the range to `0x0055c1b0-0x0055c1c3` and the helper name to `SharedBooleanVirtualStubs` when structure docs are next synchronized.
- `project-level/-unresolved.md` still has stale path snippets for the old [UID:0001GG] filename. That file is generated/read-only for A002 and should be regenerated after the supervisor report update.
- `tools/validator.ini` now records [UID:0001GG] as `by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md` with `86/89`, `CANONICAL_OWNER:NONE`, and blank emitters.

## 2026-06-14 Goal2 by-file low-score batch - AttachedObjectPaneHelper/DescPane/RainingLayerPane

Changed files:

- `by-file/AttachedObjectPaneHelper_53AEC0.md`
- `by-file/DescPane.md`
- `by-file/RainingLayerPane.md`
- `by-file/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated side effects: `project-level/-auto-completion-stats.md`, validator registry/reference state, and projected/autogen report refreshes. No manual edits were made to generated/project-level files.

Score/routing decisions:

- [UID:0000HK] `AttachedObjectPaneHelper_53AEC0`: `80/88 -> 85/89`; kept `PROPOSED_RECONSTRUCTION_PATH:"NONE"` and `CANONICAL_OWNER:NONE`. The page remains an ignored/non-standalone quarantine for the rejected one-method source split.
- [UID:0000IS] `DescPane`: `84/84 -> 86/87`; kept `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/"` and `CANONICAL_OWNER:FILE`.
- [UID:0000MY] `RainingLayerPane`: `84/84 -> 86/87`; kept `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"` and `CANONICAL_OWNER:FILE`.

Evidence:

- IDA MCP session `a001_goal2_class_batch` reported `NexusTK.exe` ready at image base `0x400000`.
- `AttachedObjectPaneHelper_53AEC0`: live `lookup_funcs`, `analyze_component`, and `xrefs_to` reconfirmed `0x0053aec0` as a 338-byte internal-only helper with exactly one destructor caller at `0x005382b0` inside `sub_538100`, no ordinary callees, and no standalone source-file evidence. Supporting registry layout offsets from [UID:0001TR] remain the direct evidence for the helper fields.
- `DescPane`: live IDA reconfirmed raw non-function starts at `0x0049d6f0` and `0x0049d780`, modeled lifecycle/getter/refresh/scalar-delete methods, four singleton xrefs to `0x0069adf8`, three-view vtable stores at `0x006189dc`, `0x00618a28`, and `0x00618a58`, and reusable-control isolation from feature-dialog code.
- `RainingLayerPane`: live IDA reconfirmed weather base/rain/MapPane function sizes, the `MapPane -> RainingLayerPane -> WeatherLayerPane` call path, `g_activeMapPane + 0x3f0` weather-state checks, six rain-table anchors and exclusive users, and the remaining dedicated-file versus weather-family split caveat.

Validation commands/results:

- `python .\tools\validator.py --mode file --file .\by-file\AttachedObjectPaneHelper_53AEC0.md --apply --queue-timeout 240`: first run updated `0000HK` to `85/89`, removed it from generated stats, refreshed projected stats/autogen registry; rerun exited `0` with `ok: 1`.
- `python .\tools\validator.py --mode file --file .\by-file\DescPane.md --apply --queue-timeout 240`: first run updated `0000IS` to `86/87`; rerun exited `0` with `ok: 1`.
- `python .\tools\validator.py --mode file --file .\by-file\RainingLayerPane.md --apply --queue-timeout 240`: first run updated `0000MY` to `86/87`; rerun exited `0` with `ok: 1`.
- `python .\tools\validator.py --mode file --file .\by-file\-coverage-report.md --apply --queue-timeout 240`: exited `0` with `ok: 1`.

Leases used:

- `by-file/AttachedObjectPaneHelper_53AEC0.md`
- `by-file/DescPane.md`
- `by-file/RainingLayerPane.md`
- `by-file/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Supervisor-owned rows/blockers:

- No `by-memory/-coverage-report.md` rows are needed for this by-file-only batch.
- No blockers.

## 2026-06-14 Goal2 startup/application low-completion batch - WinMain/ApplicationStartup/ApplicationConstructor

Changed files:

- `by-memory/0x004f5c80-0x004f5f17.WinMain.md`
- `by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md`
- `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/routing decisions:

- [UID:00019G] `WinMain`: `76/88 -> 86/90`; owner/emitter remains [UID:0000PA] `WinMain`; final C++ remains blank because helper splits, stack-object local names, and startup-window return semantics are not final-source quality.
- [UID:0002H7] `ApplicationStartup`: `76/88 -> 86/90`; owner/emitter remains [UID:00000D] `Application`; final C++ remains blank because UI-manager helper names, callback-wrapper spelling, and singleton constructor source names remain provisional.
- [UID:0002GY] `ApplicationConstructor`: `76/89 -> 86/91`; owner/emitter remains [UID:00000D] `Application`; final C++ remains blank because Application field names, string wrapper type, base/subobject names, DAT-manager construction spelling, and duplicated path/registry helper shape still need final naming.

Evidence:

- Live IDA MCP session `a001_goal2_class_batch` on 2026-06-14 reconfirmed `_WinMain@16` at `0x004f5c80` size `0x297`, `Application::Startup` at `0x004f5fb0` size `0x4e0`, `Application__Constructor` at `0x00463310` size `0x65e`, `0x004f5f17`/`0x004f5f20`/`0x0046396e` as non-functions, and successors at `0x004f5fb0`, `0x004f6490`, and `0x00463970`.
- `analyze_component` grouped the three functions, classified `_WinMain@16` as the only interface function and the constructor/startup as internal functions, and recorded `dword_67A7CC` as shared by WinMain and Startup.
- `WinMain` `analyze_function` reported prototype `int __stdcall(HINSTANCE,HINSTANCE,LPSTR,int)`, 663 bytes, 29 basic blocks, complexity 7, sole caller `?__scrt_common_main_seh@@YAHXZ`, updater branch, normal lifecycle calls, early-exit DAT cleanup, and final tail disassembly with `g_pKeySpeedMgr` restore/delete and `MessageBoxW`.
- `ApplicationStartup` decompile/disassembly confirmed singleton/image-library allocation sizes, `dword_67A7CC` UI/runtime use, six 8-byte main UI slot allocations and ordered registrations, callback wrapper allocation size `0x18`, vtable `0x0061d238`, target `0x004f5f50`, captured `this`, `off_61d24c` branch, LogoPane `0x354` allocation, TerminalPane `0x270` fallback, and compiler-generated allocation-unwind fragments.
- `ApplicationConstructor` decompile/disassembly confirmed two code xrefs, 68 basic blocks, complexity 20, 33 direct callees, early `g_pApplication`/vtable/subobject/string/timing/layout writes, OS-label formatting, path and registry blocks, fatal `DATA/BARAMST.DAT` handling, range-check exits, stack-frame buffers, and constructor-unwind fragments.

Validation commands/results:

- `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004f5c80-0x004f5f17.WinMain.md --apply --queue-timeout 240`: exited `0`; first run updated `00019G` completion `86`, confidence `90`, added references `0000RB` and `00032A`, removed it from generated low-completion stats, and reported `ok: 1`; rerun reported `ok: 1` and stats incremental no-op.
- `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004f5fb0-0x004f6490.ApplicationStartup.md --apply --queue-timeout 240`: exited `0`; first run updated `0002H7` completion `86`, confidence `90`, removed it from generated low-completion stats, and reported `ok: 1`; rerun reported `ok: 1` and stats incremental no-op.
- `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00463310-0x0046396e.ApplicationConstructor.md --apply --queue-timeout 240`: exited `0`; first run updated `0002GY` completion `86`, confidence `91`, removed it from generated low-completion stats, and reported `ok: 1`; rerun reported `ok: 1` and stats incremental no-op.

Leases used:

- `by-memory/0x004f5c80-0x004f5f17.WinMain.md`
- `by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md`
- `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## Supervisor-applied shared-report rows

- Supervisor applied and validated the Goal 2 startup/application `by-memory/-coverage-report.md` replacement rows for [UID:0002GY], [UID:00019G], and [UID:0002H7] on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 startup/application supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Goal2 low-confidence memory batch - ShoutInputPane/BlockListen raw packet helpers

Changed files:

- `by-memory/0x005b4260-0x005b43bc.ShoutInputPane.md`
- `by-memory/0x005b7010-0x005b70f7.SendAddBlockListenPacket.md`
- `by-memory/0x005b7360-0x005b7447.SendDeleteBlockListenPacket.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated side effects: `project-level/-auto-completion-stats.md`, validator registry/reference state, and projected/autogen report refreshes. No manual edits were made to generated/project-level files.

Score/routing decisions:

- [UID:0001MF] `ShoutInputPane`: `78/84 -> 86/89`; owner/emitter remains [UID:0000D5] `ShoutInputPane`. C++ remains blank because base input methods, player-state gate, packet helpers, sender global, and line-input normalization names are not final-source quality.
- [UID:0002S0] `SendAddBlockListenPacket`: `78/84 -> 85/87`; owner/emitter remains [UID:0000HS] `BlockListenInputPanes`. C++ remains blank because the raw helper is still unmodeled/unreferenced and the duplication relationship with the modeled add-submit handler is unresolved.
- [UID:0002RZ] `SendDeleteBlockListenPacket`: `78/84 -> 85/87`; owner/emitter remains [UID:0000HS] `BlockListenInputPanes`. C++ remains blank because the raw helper is still unmodeled/unreferenced and the duplication relationship with the modeled delete-confirm handler is unresolved.

Evidence:

- Live IDA MCP session `a001_goal2_class_batch` reported `NexusTK.exe` ready, image base `0x400000`, auto-analysis ready, and Hex-Rays ready.
- `ShoutInputPane`: live `lookup_funcs`, `xrefs_to`, `analyze_function`, and boundary byte reads reconfirmed `sub_5B4260` size `0x15c`, sole inbound vtable xref `0x0062fd48`, state gate at `dword_67A748 + 1261826`, text read/guard/sanitizer calls, opcode `0x0e` subtype `1`, `WideCharToMultiByte`, payload copy/send via `dword_67A7EC`, range-check failure at `0x005b43b7`, and `0xcc` padding before the next prologue.
- `SendAddBlockListenPacket`: live `lookup_funcs` and `xrefs_to` reconfirmed `0x005b7010` remains not an IDA function and has no inbound xrefs. Instruction query over `0x005b7010-0x005b7100` confirmed opcode `0x0d`, subcommand `0x02`, `WideCharToMultiByte`, payload length write, `sub_516220` copy, `sub_574BB0` send at `0x005b70dd`, return at `0x005b70ef`, range-check failure at `0x005b70f2`, and surrounding padding.
- `SendDeleteBlockListenPacket`: live `lookup_funcs` and `xrefs_to` reconfirmed `0x005b7360` remains not an IDA function and has no inbound xrefs. Instruction query over `0x005b7360-0x005b7450` confirmed opcode `0x0d`, subcommand `0x03`, `WideCharToMultiByte`, payload length write, `sub_516220` copy, `sub_574BB0` send at `0x005b742d`, return at `0x005b743f`, range-check failure at `0x005b7442`, and surrounding padding.

Validation commands/results:

- `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005b4260-0x005b43bc.ShoutInputPane.md --apply --queue-timeout 240`: exited `0`; visible output included completion `86`, confidence `89`, stats row removal for Low_Confidence/Low_Both/by-memory, autogen report no-op, and `ok: 1`.
- `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005b7010-0x005b70f7.SendAddBlockListenPacket.md --apply --queue-timeout 240`: exited `0`; target header now records `85/87` and the file scan completed with `ok: 1`.
- `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005b7360-0x005b7447.SendDeleteBlockListenPacket.md --apply --queue-timeout 240`: exited `0`; target header now records `85/87` and the file scan completed with `ok: 1`.
- Post-validation `project-level/-auto-completion-stats.md` search found no remaining `0001MF`, `0002S0`, or `0002RZ` rows.

Leases used:

- `by-memory/0x005b4260-0x005b43bc.ShoutInputPane.md`
- `by-memory/0x005b7010-0x005b70f7.SendAddBlockListenPacket.md`
- `by-memory/0x005b7360-0x005b7447.SendDeleteBlockListenPacket.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## Supervisor-applied shared-report rows

- Supervisor applied and validated the Goal 2 ShoutInputPane/BlockListen raw packet helper `by-memory/-coverage-report.md` replacement rows for [UID:0001MF], [UID:0002S0], and [UID:0002RZ] on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 ShoutInputPane/BlockListen raw packet helper supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Goal2 low-score by-class batch - RingBuffer/ServerItemMenuDialog/UserCreateAppearanceControls

Changed files:

- `by-class/RingBuffer.md`
- `by-class/ServerItemMenuDialog.md`
- `by-class/UserFaceColorSelectListPane.md`
- `by-class/UserHairColorSelectListPane.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated side effects: `project-level/-auto-completion-stats.md`, `tools/validator.ini`, projected/autogen registry state, and `auto-generated/-ag-memory-coverage.md`. No manual edits were made to generated/project-level files.

Score/routing decisions:

- [UID:0000C1] `RingBuffer`: `82/84 -> 85/87`; owner/emitter remains [UID:0000N8] `RingBuffer`; final C++ remains blank because raw helper starts, final helper names, and public iterator/API exposure are not source-quality.
- [UID:0000CZ] `ServerItemMenuDialog`: `82/84 -> 85/87`; owner/emitter remains [UID:0000KF] `ItemMenuDialogs`; final C++ remains blank because field/helper names and raw `ServerItemMenuItemList` successor code remain below the final-source gate.
- [UID:0000FI] `UserFaceColorSelectListPane`: `82/84 -> 85/88`; owner/emitter remains [UID:0000OX] `UserCreateAppearanceControls`; final C++ remains blank because class field/declaration shape and source-facing helper names remain provisional.
- [UID:0000FK] `UserHairColorSelectListPane`: `82/84 -> 85/88`; owner/emitter remains [UID:0000OX] `UserCreateAppearanceControls`; final C++ remains blank because class field/declaration shape and source-facing helper names remain provisional.

Evidence:

- Live IDA MCP session `a001_goal2_class_batch` reported `NexusTK.exe` ready, image base `0x400000`, auto-analysis ready, and Hex-Rays ready.
- `RingBuffer`: live `lookup_funcs`, `xrefs_to`, and `analyze_component` reconfirmed modeled starts at `0x005563d0`, `0x005564e0`, `0x00556580`, `0x005565f0`, `0x00556660`, `0x00556680`, `0x00556690`, and `0x005567b0`; raw no-function starts at `0x00556670`, `0x005566a0`, and `0x005566b0`; Thread constructor/enqueue/dequeue/empty-test xrefs; shared `??_7RingBuffer@@6B@` vtable access; and the companion `RingBufferIterator` relationship.
- `ServerItemMenuDialog`: live `lookup_funcs`, `xrefs_to`, `analyze_component`, and selected-action decompile reconfirmed constructor/action/update starts at `0x0051a520`, `0x0051acb0`, and `0x0051ae50`; raw `0x0051ae90` successor; factory callers in `sub_517450` and `sub_5179E0`; vtable stores at `0x0061eea8`, `0x0061ef08`, and `0x0061ef38`; virtual slot refs for action/update; inline private list construction; opcode `0x39` selected-action packet send; and availability-toggle flow.
- `UserFaceColorSelectListPane`: live `lookup_funcs`, `xrefs_to`, `analyze_component`, and constructor decompile reconfirmed constructor/paint/selection starts at `0x005020d0`, `0x005021f0`, and `0x00502350`; the `CreateUserDialogPane` constructor caller; face vtable slot refs at `0x0061e0ac` and `0x0061e0a4`; shared 16-entry color-order table refs at `0x0061e570`/`0x0061e580`/`0x0061e590`/`0x0061e5a0`; and exact `SetFaceColorIndex` callback refs from constructor and selection.
- `UserHairColorSelectListPane`: live `lookup_funcs`, `xrefs_to`, `analyze_component`, and constructor decompile reconfirmed constructor/draw/selection starts at `0x00501e10`, `0x00501f30`, and `0x00502090`; the `CreateUserDialogPane` constructor caller; hair vtable slot refs at `0x0061dfe8` and `0x0061dfe0`; shared 16-entry color-order table refs at `0x0061e570`/`0x0061e580`/`0x0061e590`/`0x0061e5a0`; and exact `SetHairColorIndex` callback refs from constructor and selection.

Validation commands/results:

- `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-class\RingBuffer.md --apply --queue-timeout 240`: exited `0`; visible output included completion `85`, confidence `87`, stats row removal for `0000C1`, projected stats update, and `ok: 1`.
- `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-class\ServerItemMenuDialog.md --apply --queue-timeout 240`: exited `0`; visible output included completion `85`, confidence `87`, stats row removal for `0000CZ`, projected stats update, and `ok: 1`.
- `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-class\UserFaceColorSelectListPane.md --apply --queue-timeout 240`: exited `0`; visible output included completion `85`, confidence `88`, stats row removal for `0000FI`, projected stats update, and `ok: 1`.
- `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-class\UserHairColorSelectListPane.md --apply --queue-timeout 240`: exited `0`; visible output included completion `85`, confidence `88`, stats row removal for `0000FK`, projected stats update, validator-owned `auto-generated/-ag-memory-coverage.md` update, and `ok: 1`.
- Post-validation `project-level/-auto-completion-stats.md` search found no remaining `0000C1`, `0000CZ`, `0000FI`, or `0000FK` rows.

Leases used:

- `by-class/RingBuffer.md`
- `by-class/ServerItemMenuDialog.md`
- `by-class/UserFaceColorSelectListPane.md`
- `by-class/UserHairColorSelectListPane.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## Supervisor-applied shared-report rows

- Supervisor applied and validated the Goal 2 low-score by-class `by-class/-coverage-report.md` replacement rows for [UID:0000C1], [UID:0000CZ], [UID:0000FI], and [UID:0000FK] on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-class/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 low-score by-class supervisor-owned shared-report rows remain pending.

## 2026-06-14 Goal2 by-resource score batch 2 - WebBoard/ForcedInform/str.res/Alert resources

Changed files:

- `by-resource/webboard-dialog-resources.md`
- `by-resource/forced-inform-message-resources.md`
- `by-resource/str-res-localized-strings.md`
- `by-resource/alert-dialog-resources.md`
- `by-resource/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## 2026-06-15 - A002-goal2-render-geometry-memory-20260615-1

Changed target docs:

- `by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md`
- `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`
- `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`
- `by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md`
- Validator-owned side effects: `project-level/-auto-completion-stats.md`, `tools/validator.ini`.

Score/routing decisions:

- [UID:00015Q] RectBoundsMethods: `78/86 -> 86/89`; `CANONICAL_OWNER:0000N2`, `EMITTER_UIDS:0000N2`, and `auto-generated/NexusTK/ui/core/RectBounds.cpp` unchanged.
- [UID:00015S] RectGeometryHelpers: `78/86 -> 86/89`; `CANONICAL_OWNER:0000N2`, `EMITTER_UIDS:0000N2`, and `auto-generated/NexusTK/ui/core/RectBounds.cpp` unchanged.
- [UID:000162] GrafPortDrawStateAccessors: `78/86 -> 86/89`; `CANONICAL_OWNER:0000JR`, `EMITTER_UIDS:0000JR`, and `auto-generated/NexusTK/render/GrafPort.cpp` unchanged.
- [UID:00016H] LineClipHelpers: `78/86 -> 86/89`; `CANONICAL_OWNER:0000OC`, `EMITTER_UIDS:0000OC`, and `auto-generated/NexusTK/render/Surface.cpp` unchanged.

IDA/local evidence added:

- Live IDA lookup reconfirmed target starts/sizes, adjacent boundaries, unique signatures, caller fan-in, and representative callee/decompile behavior for all four ranges.
- RectBoundsMethods evidence now records five modeled method starts, unique range signature, broad `SetLTRB`/`Offset` fan-in, three `RectBoundsInset` refs, 33 `UnionWith` refs, two `ClampWithin` refs, and no-callee four-int layout behavior.
- RectGeometryHelpers evidence now records twelve shared helper starts, the `0x004b7f90` not-a-function boundary, unique range signature, broad `InitRectBounds`/`PointInRect` fan-in, four `RectArea` refs, and no-callee intersection behavior.
- GrafPortDrawStateAccessors evidence now records seven accessor starts, the adjacent `0x004b96a0` boundary, unique range signature, no-callee cursor/color setters over `+0x68/+0x6c/+0x74`, and mixed narrow/broad caller fan-in.
- LineClipHelpers evidence now records `sub_4BB2E0` and `sub_4BB520` sizes, unique range signature, the two software line-callback callers, `PointInRect` plus Liang-Barsky parameter-test callees, callback-table route through Surface render setup, and separation from the unmodeled `0x004bb5b0` byte island / `GrafPortDrawGlyph`.

Supervisor-applied `by-memory/-coverage-report.md` replacements:

Supervisor applied the exact replacement rows for [UID:00015Q], [UID:00015S], [UID:000162], and [UID:00016H] on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.

Validation commands/results:

- From `project-documentation/tools`: `python .\validator.py --mode file --file "..\by-memory\0x004b78d0-0x004b7ae8.RectBoundsMethods.md" --apply --queue-timeout 300`: exited `0`, `ok: 1`; completion/confidence updated and low stats rows removed.
- From `project-documentation/tools`: `python .\validator.py --mode file --file "..\by-memory\0x004b7c30-0x004b7f87.RectGeometryHelpers.md" --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- From `project-documentation/tools`: `python .\validator.py --mode file --file "..\by-memory\0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md" --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- From `project-documentation/tools`: `python .\validator.py --mode file --file "..\by-memory\0x004bb2e0-0x004bb5a5.LineClipHelpers.md" --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- Follow-up `Select-String` on `project-level/-auto-completion-stats.md` for `00015Q|00015S|000162|00016H` returned no matches.

Remaining blockers:

- Final C++ intentionally remains blank for all four rows; current evidence supports documentation score raises but not source-quality reconstruction.
- Remaining provenance blockers are final source names/declaration splits for RectBounds/RectGeometry helpers, final GrafPort API and field names, and the unmodeled `0x004bb5b0` byte island between LineClipHelpers and `GrafPortDrawGlyph`.
- No IDA DB changes were made; existing DB labels/functions were adequate for evidence capture, and no safe public rename/type correction was strong enough to apply.

Leases used:

- `by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md`
- `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`
- `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`
- `by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## 2026-06-15 A002-goal2-parser-config-error-memory-20260615-1

Changed files:

- `by-memory/0x00490b10-0x004910c0.ComBackedLauncherAuthenticationParser.md`
- `by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md`
- `by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md`
- `by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md`
- `by-class/FileError.md`
- `by-class/MyError.md`
- `by-class/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## 2026-06-15 - A002-goal2-ranking-adjustor-thunks-memory-20260615-9

Changed files:

- `by-memory/0x0045981b-0x00459830.RankingDialogAdjustorThunks.md`
- `by-memory/0x0045bddd-0x0045bdf2.RankingEventListPaneAdjustorThunks.md`
- `by-memory/0x0045f0a8-0x0045f0bd.RankingRewardInfoDialogAdjustorThunks.md`
- `by-memory/0x0045f97d-0x0045f992.RankingUserListPaneAdjustorThunks.md`
- `project-level/-auto-completion-stats.md` via validator generated updates only
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/routing decisions:

- [UID:0000Y1] `RankingDialogAdjustorThunks`: `80/85 -> 88/92`; `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank final C++ unchanged. Context remains [UID:0000BM] `RankingDialog` and [UID:0001YJ] `RankingDialogVtableFamily`; this page is compiler/linker-generated thunk bytes only.
- [UID:0000Y8] `RankingEventListPaneAdjustorThunks`: `80/85 -> 88/92`; routing unchanged as ignored/non-emitting compiler/linker-generated thunk bytes. Context remains [UID:0000BN] `RankingEventListPane` and [UID:0001YJ].
- [UID:0000YB] `RankingRewardInfoDialogAdjustorThunks`: `80/85 -> 88/92`; routing unchanged as ignored/non-emitting compiler/linker-generated thunk bytes. Context remains [UID:0000BP] `RankingRewardInfoDialog` and [UID:0001YJ].
- [UID:0000YC] `RankingUserListPaneAdjustorThunks`: `80/85 -> 88/92`; routing unchanged as ignored/non-emitting compiler/linker-generated thunk bytes. Context remains [UID:0000BQ] `RankingUserListPane` and [UID:0001YJ].

IDA/local evidence:

- Live IDA MCP session `a003_objectlist_dispatch_20260615` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; health returned `ok`, imagebase `0x400000`, Hex-Rays ready.
- `lookup_funcs` reconfirmed all eight thunk starts as `0x0b`-byte functions: `0x0045981b`, `0x00459826`, `0x0045bddd`, `0x0045bde8`, `0x0045f0a8`, `0x0045f0b3`, `0x0045f97d`, and `0x0045f988`; querying each half-open end resolves inside the second thunk, and scalar deleting destructor targets at `0x00459840`, `0x0045be00`, `0x0045f0c0`, and `0x0045f9a0` were reconfirmed.
- `disasm` showed each thunk is exactly two instructions: secondary thunks `sub ecx, 0A0h; jmp <scalar deleting destructor>` and tertiary thunks `sub ecx, 0A4h; jmp <scalar deleting destructor>`.
- `analyze_function` matched decompiler forms `this - 160` and `this - 164`, with no strings, no independent callees, no ordinary callers, and two basic blocks per thunk.
- `xrefs_to` found exactly one data xref to each thunk from the corresponding secondary/tertiary vtable slot: `0x006109e4`, `0x00610a14`, `0x00610b3c`, `0x00610b6c`, `0x00610c24`, `0x00610c54`, `0x00610d38`, and `0x00610d68`.
- `xrefs_to` for those vtable cells reconfirmed constructor/destructor/scalar-destructor vtable-store context for each class family; scalar deleting destructors have the two thunk code refs plus their primary vtable slot refs.
- `make_signature_for_range` recorded exact non-wildcard byte signatures for all four two-thunk islands.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-memory\0x0045981b-0x00459830.RankingDialogAdjustorThunks.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `88/92`; generated low-completion stats row removed for [UID:0000Y1].
- `python .\tools\validator.py --mode file --file by-memory\0x0045bddd-0x0045bdf2.RankingEventListPaneAdjustorThunks.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `88/92`; generated low-completion stats row removed for [UID:0000Y8].
- `python .\tools\validator.py --mode file --file by-memory\0x0045f0a8-0x0045f0bd.RankingRewardInfoDialogAdjustorThunks.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `88/92`; generated low-completion stats row removed for [UID:0000YB].
- `python .\tools\validator.py --mode file --file by-memory\0x0045f97d-0x0045f992.RankingUserListPaneAdjustorThunks.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `88/92`; generated low-completion stats row removed for [UID:0000YC].
- Follow-up check confirmed `project-level/-auto-completion-stats.md` no longer contains `0000Y1`, `0000Y8`, `0000YB`, or `0000YC`.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

Supervisor applied the exact [UID:0000Y1], [UID:0000Y8], [UID:0000YB], and [UID:0000YC] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A002 Goal 2 Ranking adjustor-thunk supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

Remaining blockers:

- No by-memory coverage report edits were made directly. Pending shared rows above require supervisor application.
- No IDA DB changes were made. Evidence supports documentation and score/routing updates only; permanent names/types should remain part of a broader Ranking class/vtable final-source audit.
- The final source declarations for the owning Ranking classes/vtables remain in the class/vtable pages; these thunk pages should stay ignored/non-emitting.

Leases used:

- `by-memory/0x0045981b-0x00459830.RankingDialogAdjustorThunks.md`
- `by-memory/0x0045bddd-0x0045bdf2.RankingEventListPaneAdjustorThunks.md`
- `by-memory/0x0045f0a8-0x0045f0bd.RankingRewardInfoDialogAdjustorThunks.md`
- `by-memory/0x0045f97d-0x0045f992.RankingUserListPaneAdjustorThunks.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## 2026-06-15 - A002-goal2-jsoncpp-core-memory-20260615-8

Changed files:

- `by-memory/0x00424630-0x00428b4b.JsonCppValueCore.md`
- `by-memory/0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds.md`
- `by-memory/0x0042ae90-0x0042e850.JsonCppReaderAndBuilderPreludeIsland.md`
- `by-memory/0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland.md`
- `project-level/-auto-completion-stats.md` via validator generated updates only
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/routing decisions:

- [UID:0000WY] `JsonCppValueCore`: `80/85 -> 87/90`; `CANONICAL_OWNER:0000KI`, `EMITTER_UIDS:0000KI`, and `RECONSTRUCTABLE:TRUE` unchanged. Coverage-report classification should remain `ignored` for NexusTK product-source purposes while the page documents rebuild through vendored `third_party/jsoncpp/`; reconstruction C++ remains blank.
- [UID:0000X0] `JsonCppDocumentParseFrontEnds`: `80/85 -> 85/88`; `CANONICAL_OWNER:0000KI`, `EMITTER_UIDS:0000KI`, and `RECONSTRUCTABLE:TRUE` unchanged. Product callers remain consumers only, not owner evidence; reconstruction C++ remains blank.
- [UID:0000X2] `JsonCppReaderAndBuilderPreludeIsland`: `80/85 -> 87/90`; `CANONICAL_OWNER:0000KI`, `EMITTER_UIDS:0000KI`, and `RECONSTRUCTABLE:TRUE` unchanged. The `0x0042e850` sibling boundary remains unchanged; reconstruction C++ remains blank.
- [UID:0000X3] `JsonCppStreamWriterBuilderIsland`: `80/85 -> 87/90`; `CANONICAL_OWNER:0000KI`, `EMITTER_UIDS:0000KI`, and `RECONSTRUCTABLE:TRUE` unchanged. Writer-builder function cluster and source route remain under vendored JsonCpp; reconstruction C++ remains blank.

IDA/local evidence:

- Live IDA MCP session `a003_objectlist_dispatch_20260615` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; health returned `ok`, imagebase `0x400000`, Hex-Rays ready.
- `JsonCppValueCore`: `lookup_funcs` reconfirmed representative starts and sizes at `0x00424630`, `0x00424850`, `0x00424c90`, `0x00425a10`, `0x00427020`, `0x004280f0`, and `0x00428940`; `analyze_function 0x00424850` confirmed thread-safe static-object `nullSingleton()` behavior with `atexit`; `analyze_function 0x00424c90` confirmed `Value(ValueType)` switch and null string payload discriminator.
- `JsonCppDocumentParseFrontEnds`: `lookup_funcs` reconfirmed the front-end/support starts at `0x004298f0`, `0x00429b30`, `0x00429c40`, `0x0042a770`, `0x0042aaf0`, and `0x0042ab40`; `xrefs_to` reconfirmed only the two product caller sites for `0x004298f0` and `0x00429b30`; `analyze_function 0x00429b30` confirmed the parse-front-end wrapper handing off to `0x00429c40`.
- `JsonCppReaderAndBuilderPreludeIsland`: `lookup_funcs` reconfirmed parser/builder starts through `0x0042e7b0`; `analyze_function 0x0042ae90` confirmed reader diagnostics and object/array parser calls; `find_regex` found `Unable to parse token length`, `collectComments`, and `allowDroppedNullPlaceholders` and did not return `reader error` in that search.
- `JsonCppStreamWriterBuilderIsland`: `lookup_funcs` reconfirmed `0x0042e850`, `0x0042ee10`, `0x0042f110`, `0x0042f1b0`, and successor `0x0042f3f0`; `xrefs_to` reconfirmed writer-builder caller/data refs; `analyze_function 0x0042e850` confirmed writer setting reads and `All`/`None` handling; `analyze_function 0x0042f1b0` confirmed default writes for `commentStyle`, `indentation`, boolean writer settings, and `precision = 17`.
- Local `rg` against `source-3/third_party_embeds/jsoncpp` and `by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802` confirmed matching `json_value.cpp`, `json_reader.cpp`, `json_writer.cpp`, and `include/json/version.h` source discriminators. The evidence supports the current best commit snapshot route, not an exact final release-tag claim.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-memory\0x00424630-0x00428b4b.JsonCppValueCore.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; completion/confidence updated to `87/90`; generated low-completion stats row removed for [UID:0000WY].
- `python .\tools\validator.py --mode file --file by-memory\0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; completion/confidence updated to `85/88`; generated low-completion stats row removed for [UID:0000X0].
- `python .\tools\validator.py --mode file --file by-memory\0x0042ae90-0x0042e850.JsonCppReaderAndBuilderPreludeIsland.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; completion/confidence updated to `87/90`; generated low-completion stats row removed for [UID:0000X2].
- `python .\tools\validator.py --mode file --file by-memory\0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; completion/confidence updated to `87/90`; generated low-completion stats row removed for [UID:0000X3].
- Follow-up check confirmed `project-level/-auto-completion-stats.md` no longer contains `0000WY`, `0000X0`, `0000X2`, or `0000X3`.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

Supervisor applied the exact [UID:0000WY], [UID:0000X0], [UID:0000X2], and [UID:0000X3] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A002 Goal 2 JsonCpp core supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

Remaining blockers:

- Do not claim an exact final upstream release tag; current evidence supports the staged `b299d3581f4dc670734f1fe1a34fce1282337802` snapshot route with `JSONCPP_VERSION_STRING "1.7.4"` still present.
- Exact function-by-function upstream names across the larger value, reader, writer, CRT, and STL helper islands remain incomplete.
- No IDA DB changes were made; documentation evidence was sufficient for score/routing updates, but safe permanent names/types should wait for a broader JsonCpp symbol/import pass.

Leases used:

- `by-memory/0x00424630-0x00428b4b.JsonCppValueCore.md`
- `by-memory/0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds.md`
- `by-memory/0x0042ae90-0x0042e850.JsonCppReaderAndBuilderPreludeIsland.md`
- `by-memory/0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## A002-goal2-candidate-encoder-collection-memory-20260615-6

Score/routing decisions:

- [UID:0002MT] `CandidateStringQueueReserveAdditional`: `78/89 -> 85/91`; `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and blank emitters unchanged. This remains ignored MSVC/Dinkumware `std::deque<std::wstring>` map-growth support; source-facing behavior belongs in IME/InputMan container use, not a handwritten helper.
- [UID:00013L] `EncoderNoopVirtual`: `78/90 -> 85/91`; owner/emitter remain [UID:00004F] `Encoder`. Final C++ remains blank because the original virtual declaration name is still unrecovered.
- [UID:00013V] `EncoderScalarDeletingDestructor`: `78/90 -> 85/91`; owner/emitter remain [UID:00004F] `Encoder`. Final C++ remains blank because this is compiler-generated scalar deleting destructor/vtable glue.
- [UID:0001HH] `CollectionPane2Destructor`: `78/90 -> 85/91`; owner/emitter remain [UID:0000IC] `CollectionPane`, through [UID:00002Y] `CollectionPane2`. Final C++ remains blank because surrounding class/interface names are still provisional.

IDA/local evidence:

- Live IDA MCP session `a003_objectlist_dispatch_20260615` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; health returned `ok`, imagebase `0x400000`, Hex-Rays ready.
- `CandidateStringQueueReserveAdditional`: `lookup_funcs` reconfirmed `sub_4E8860` size `0x192`; `analyze_function` confirmed assign/append-only callers (`sub_4E8450`, `sub_4E9710`), deque capacity doubling until requested additional slots and minimum eight slots, `operator new`, `memmove`, `memset`, `sub_43F190`, and `sub_5C7526` callees.
- `EncoderNoopVirtual`: `lookup_funcs` reconfirmed `nullsub_27` size `0x1`; `analyze_function include_asm=true` confirmed a single `retn`, empty decompilation, no callers/callees, and sole vtable data xref `0x006192d0`.
- `EncoderScalarDeletingDestructor`: `lookup_funcs` reconfirmed `sub_4A5E30` size `0x24`; `analyze_function include_asm=true` confirmed `off_6192CC` vtable restore, scalar-delete flag test, conditional `sub_5C7526(this)` free, no ordinary callers, and vtable data xref `0x006192cc`.
- `CollectionPane2Destructor`: `lookup_funcs` reconfirmed `sub_56FDA0` size `0x1f`; `analyze_function include_asm=true` confirmed three `CollectionPane2` vtable stores at offsets `0x00`, `0xa0`, and `0xa4`, tail jump to `sub_5450D0`, and primary vtable data route `0x0062466c`.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-memory\0x004e8860-0x004e89f2.CandidateStringQueueReserveAdditional.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; completion/confidence updated to `85/91`; generated low-completion stats row removed for [UID:0002MT].
- `python .\tools\validator.py --mode file --file by-memory\0x004a5630-0x004a5631.EncoderNoopVirtual.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; completion/confidence updated to `85/91`; generated low-completion stats row removed for [UID:00013L].
- `python .\tools\validator.py --mode file --file by-memory\0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; completion/confidence updated to `85/91`; generated low-completion stats row removed for [UID:00013V].
- `python .\tools\validator.py --mode file --file by-memory\0x0056fda0-0x0056fdbf.CollectionPane2Destructor.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; completion/confidence updated to `85/91`; generated low-completion stats row removed for [UID:0001HH].

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows

Supervisor applied the exact [UID:00013L], [UID:00013V], [UID:0002MT], and [UID:0001HH] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A002 Goal 2 Candidate/Encoder/Collection supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

Supervisor-owned rows/blockers:

- No `by-memory/-coverage-report.md` rows remain pending for this batch. A002 did not edit `by-memory/-coverage-report.md` directly.
- Remaining blockers: original source typedef/member spelling for the candidate string deque; exact source declaration name for the Encoder no-op virtual; final class destructor/vtable shape for the Encoder scalar deleting destructor; final CollectionPane2 interface/field names around the non-deleting destructor.
- IDA DB changes: skipped. Evidence supported documentation score/routing updates but no safe rename/type change was necessary.

Leases used:

- `by-memory/0x004e8860-0x004e89f2.CandidateStringQueueReserveAdditional.md`
- `by-memory/0x004a5630-0x004a5631.EncoderNoopVirtual.md`
- `by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md`
- `by-memory/0x0056fda0-0x0056fdbf.CollectionPane2Destructor.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Validator-owned side effects observed:

- `project-level/-auto-completion-stats.md`
- `tools/validator.ini`
- autogen coverage reported no-op/unchanged for generated coverage outputs during the scoped runs.

Score/routing decisions:

- [UID:0002BN] `ComBackedLauncherAuthenticationParser`: `78/85 -> 85/88`; `CANONICAL_OWNER` and `EMITTER_UIDS` unchanged at [UID:0000N4] `RegistryConfig`; emitted path remains `auto-generated/NexusTK/config/RegistryConfig.cpp`.
- [UID:00021Z] `ConfigRawTableHelpers`: `78/86 -> 85/88`; `CANONICAL_OWNER` and `EMITTER_UIDS` unchanged at [UID:0000IE] `Config`; emitted path remains `auto-generated/NexusTK/config/Config.cpp`.
- [UID:0002HL] `FileErrorConstructor`: `78/86 -> 86/89`; `CANONICAL_OWNER` and `EMITTER_UIDS` unchanged at [UID:00004X] `FileError`; emitted path remains `auto-generated/NexusTK/util/Error.cpp`.
- [UID:0002HO] `MyErrorConstructor`: `78/86 -> 86/89`; `CANONICAL_OWNER` and `EMITTER_UIDS` unchanged at [UID:00008V] `MyError`; emitted path remains `auto-generated/NexusTK/util/Error.cpp`.
- Support [UID:00004X] `FileError`: `82/88 -> 85/89`; owner/emitter unchanged at [UID:0000J5] `Error`.
- Support [UID:00008V] `MyError`: `82/86 -> 85/88`; owner/emitter unchanged at [UID:0000J5] `Error`.

IDA/local evidence added:

- `0x00490b10`: live IDA MCP `analyze_function` decompiles `sub_490B10` as a 0x5b0 function with 90 basic blocks and command-line, COM, host-resolution, localized failure, and SEH cleanup behavior; `make_signature_for_range 0x00490b10-0x004910c0` returned a unique signature; `xrefs_to 0x00494000` reported the runtime COM null-check helper's sole direct xref from `0x00490f41` inside this parser.
- `0x0048e310-0x0048e479`: live IDA MCP reconfirmed no function object at `0x0048e310` or `0x0048e410`, no direct xrefs to either raw start, neighbor functions at `0x0048e2b0` and `0x0048e480`, and a unique signature for the full raw helper island.
- `0x004a6430`: live IDA MCP decompiles the 0x3f constructor, confirms a unique signature, `sub_4F4A80` base setup, `FileError::vftable` store, `sub_471110` formatting into the inline wide buffer at `+0x04`, four constructor code refs, and the `0x006193d4` vtable data xref at `0x004a6445`.
- `0x004a67a0`: live IDA MCP decompiles the 0x9d constructor, confirms a unique signature, `sub_4F4A80` base setup, `MyError::vftable` store, `wcslen`, allocator call, `wcsncpy_s`, owned pointer storage at `+0x04`, five constructor code refs, and `0x00619434` constructor/destructor-family vtable xrefs.

Remaining blockers:

- [UID:0002BN]: startup-state field names, COM interface/source names, and selector/use-site route remain provisional; C++ stays blank.
- [UID:00021Z]: raw bytes are well bounded, but direct caller/use-site provenance and original helper/table field names remain unresolved; C++ stays blank.
- [UID:0002HL]/[UID:00004X]: original constructor signature, inline buffer declaration, base-error field names, and hierarchy destructor policy remain unresolved.
- [UID:0002HO]/[UID:00008V]: allocator wrapper naming, aggregate-only `0x004a6860` destructor body, exact `PasswordError` split, and final hierarchy declaration remain unresolved.

Supervisor-applied `by-memory/-coverage-report.md` replacements:

Supervisor applied the exact replacement rows for [UID:00021Z], [UID:0002BN], [UID:0002HL], and [UID:0002HO] on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.

Validation commands/results:

- `python .\validator.py --mode file --file ..\by-memory\0x00490b10-0x004910c0.ComBackedLauncherAuthenticationParser.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; reported [UID:0002BN] completion/confidence updates and removal from generated low-score stats rows.
- `python .\validator.py --mode file --file ..\by-memory\0x0048e310-0x0048e479.ConfigRawTableHelpers.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- `python .\validator.py --mode file --file ..\by-memory\0x004a6430-0x004a646f.FileErrorConstructor.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- `python .\validator.py --mode file --file ..\by-memory\0x004a67a0-0x004a683d.MyErrorConstructor.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- `python .\validator.py --mode file --file ..\by-class\FileError.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- `python .\validator.py --mode file --file ..\by-class\MyError.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- `python .\validator.py --mode file --file ..\by-class\-coverage-report.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- Final post-wording rerun `python .\validator.py --mode file --file ..\by-memory\0x00490b10-0x004910c0.ComBackedLauncherAuthenticationParser.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; stats incremental no-op because [UID:0002BN] is no longer present in generated stats lists.

Leases used:

- `by-memory/0x00490b10-0x004910c0.ComBackedLauncherAuthenticationParser.md`
- `by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md`
- `by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md`
- `by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md`
- `by-class/FileError.md`
- `by-class/MyError.md`
- `by-class/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## A002-goal2-resource-provenance-20260614-7

Changed target files:

- `by-resource/main-menu-history-resources.md`
- `by-resource/main-menu-story-resources.md`
- `by-resource/startup-logo-media.md`
- `by-resource/alert-dialog-resources.md`
- `by-resource/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/routing decisions:

- [UID:0001RF] `main-menu-history-resources`: `87/90 -> 90/93`; `CANONICAL_OWNER:NONE` unchanged; no emitter/path fields apply to by-resource pages.
- [UID:0001RG] `main-menu-story-resources`: `87/90 -> 89/92`; `CANONICAL_OWNER:NONE` unchanged; no emitter/path fields apply.
- [UID:0001RN] `startup-logo-media`: `86/92 -> 86/93`; `CANONICAL_OWNER:NONE` unchanged; completion did not move because the media payloads are still absent.
- [UID:0001R5] `alert-dialog-resources`: `87/91 -> 88/92`; `CANONICAL_OWNER:0000HE` unchanged; no emitter/path fields apply.

Package/raw-scan evidence:

- Corrected DAT parsing uses each entry's stored start offset and the next entry's start as the size boundary.
- History resources: `HISTORY.EPF` is `bint2.dat` entry `0`, offset `2,214`, size `6,353,036`, EPF header `(8, 1024, 768)`; `HISTORYN.EPF` is `bint2.dat` entry `1`, offset `6,355,250`, size `794,140`, EPF header `(1, 1024, 768)`; `HISTORYN.PAL` is entry `2`, offset `7,149,390`, size `1,056`, `DLPalette`; `NPAL4.PAL` is entry `46`, offset `9,157,711`, size `1,056`, `DLPalette`; `MADEBY` is `baram.dat` entry `8`, offset `11,267,987`, size `997`. `HISTORY.EPD` was not found as a DAT entry or loose file and appears only as executable UTF-16 literal offset `2,214,760`.
- Story resources: `STORY.EPF` is `bint2.dat` entry `89`, offset `10,397,029`, size `3,970,652`, EPF header `(5, 1024, 768)`; `STORY.PAL` is entry `90`, offset `14,367,681`, size `1,056`, `DLPalette`; `PAL01.PAL` is entry `56`, offset `9,276,430`, size `1,056`, `DLPalette`; `NPAL8.PAL` is entry `50`, offset `9,161,935`, size `1,056`, `DLPalette`; `BACKTALE` is `baram.dat` entry `0`, offset `191`, size `522`. `STORY.EPD` was not found as a DAT entry or loose file and appears only as executable UTF-16 literals at offsets `2,214,716` and `2,214,764`.
- Startup logo media: corrected DAT parsing, loose search across `E:\2026\Resources`, and raw executable scan reconfirmed no `NEXON.LGO`, `LOGO.PAK`, or `LOGO.PAD` DAT/loose payloads. The names appear only as UTF-16 executable literals at offsets `2,210,892`, `2,210,500`, and `2,210,520`.
- Alert resources: no `BDFRAME.EPF` DAT/loose payload found. Corrected parsing found nearby non-substitute resources: `DLGFRAME.epf` in `bint1.dat` entry `24`, offset `2,132,439`, size `2,178`, EPF header `(9, 14, 14)`; `frame.epf` entry `78`, offset `7,716,660`, size `794,928`, EPF header `(1, 1024, 768)`; `frame.pal` entry `79`, offset `8,511,588`, size `1,056`, `DLPalette`; `TOTFRAME.EPF` in `bint2.dat` entry `109`, offset `16,205,352`, size `224,716`, EPF header `(4, 192, 288)`. `BDFRAME.EPF` appears only as executable UTF-16 literal offset `2,215,764`.

Supervisor-owned rows/blockers:

- No `by-memory/-coverage-report.md` rows are needed. No by-memory docs were edited.
- Remaining blockers: legacy `HISTORY.EPD`/`STORY.EPD`, startup `NEXON.LGO`/`LOGO.PAK`/`LOGO.PAD` media, and alert `BDFRAME.EPF` are still missing from the audited current package/loose resource tree. Further progress needs another distribution, installer-era loose media/resources, or deeper version provenance.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-resource\main-menu-history-resources.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; reported [UID:0001RF] completion/confidence updates and removed the generated low-score stats row.
- `python .\tools\validator.py --mode file --file by-resource\main-menu-story-resources.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; reported [UID:0001RG] completion/confidence updates and removed the generated low-score stats row.
- `python .\tools\validator.py --mode file --file by-resource\startup-logo-media.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; reported [UID:0001RN] confidence update and removed the generated low-score stats row.
- `python .\tools\validator.py --mode file --file by-resource\alert-dialog-resources.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; reported [UID:0001R5] completion/confidence updates and removed the generated low-score stats row.
- `python .\tools\validator.py --mode file --file by-resource\-coverage-report.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- Follow-up dry validator checks for all four target docs and `by-resource\-coverage-report.md` returned `ok: 1`; `project-level/-auto-completion-stats.md` no longer contains `0001RF`, `0001RG`, `0001RN`, or `0001R5`.
- Validator-owned side effects: `project-level/-auto-completion-stats.md` and `tools/validator.ini`.

Leases used:

- `by-resource/main-menu-history-resources.md`
- `by-resource/main-menu-story-resources.md`
- `by-resource/startup-logo-media.md`
- `by-resource/alert-dialog-resources.md`
- `by-resource/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## 2026-06-14 Goal2 resource-payload provenance batch - Meta/NewHuman/SOBJ/Staff

Changed files:

- `by-resource/meta-dat-metadata-cache.md`
- `by-resource/new-human-motion-tables.md`
- `by-resource/sobj-tbl.md`
- `by-resource/staff-dialog-resources.md`
- `by-resource/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Validator-owned side effects:

- `project-level/-auto-completion-stats.md`
- `tools/validator.ini`

Score/routing decisions:

- [UID:0001RH] `meta-dat-metadata-cache`: `85/89 -> 89/92`; `CANONICAL_OWNER:NONE` unchanged; no emitter/path fields apply to by-resource pages. The generated low-score stats row dropped after validation.
- [UID:0001RI] `new-human-motion-tables`: `85/91 -> 88/93`; `CANONICAL_OWNER:NONE` unchanged; no emitter/path fields apply. The generated low-score stats row dropped after validation.
- [UID:0001RL] `sobj-tbl`: `85/89 -> 87/91`; `CANONICAL_OWNER:NONE` unchanged; no emitter/path fields apply. The generated low-score stats row remains at `87/91`.
- [UID:0001RM] `staff-dialog-resources`: `85/90 -> 86/91`; `CANONICAL_OWNER:NONE` unchanged; no emitter/path fields apply. The generated low-score stats row remains at `86/91`.

Package/payload evidence:

- `Meta.dat`: no packed DAT entry named `Meta.dat` was found under `Data`; the audited tree contains loose `E:\2026\Resources\Read_Only\NexusTK\Meta.dat`, size `243,932`. Header has table count `32`, header byte count `1,048`, payload start offset `1,056`, 32 UTF-16 table names, 8 secondary bytes per record, big-endian compressed sizes summing to the remaining `242,876` bytes, and zlib payload blocks that decompress successfully.
- NewHuman tables: `char.dat` contains `acc2drw.tbl` entry `0` size `2,580`, `haircol.tbl` entry `30` size `400`, `Layer.tbl` entry `37` size `467`, `Motion.tbl` entry `41` size `24,109`, and `Part.tbl` entry `44` size `635`. `Motion.tbl` header begins `MotionStandard` with count `68`; `Layer.tbl` begins `LayerInformation` with count `13`; `Part.tbl` begins `PartInformation` with count `19`; `acc2drw.tbl` and `haircol.tbl` are CRLF text payloads.
- `SOBJ.TBL`: `tile.dat` contains `SObj.tbl` entry `0`, offset `106`, size `276,147`; first dword count is `19,551` and the following two-byte header/version word is `0x0001`.
- Staff dialog: `NPAL8.PAL` is present in `bint2.dat` entry `50`, offset `9,161,935`, size `1,056`, with a `DLPalette` header. `STAFF.EPF`, `STAFFS`, and `STAFFS2` were not found as DAT entries or loose files in the audited current tree; raw search only found their UTF-16 literals in the executable. `DLGSTAFF.*` entries found in `bint1.dat` belong to forced-inform resources, not this page.

Supervisor-owned rows/blockers:

- No `by-memory/-coverage-report.md` rows are needed. No by-memory docs were edited.
- Remaining provenance blockers: `STAFF.EPF`, `STAFFS`, and `STAFFS2` payload/source archive remain absent from the audited current tree; Meta.dat secondary header field names and malformed-cache behavior remain open; NewHuman per-part descriptor semantics/resolved EPF archive mapping remain open; `SOBJ.TBL` record-zero/header/field-name semantics remain open.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-resource\meta-dat-metadata-cache.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; reported [UID:0001RH] completion/confidence updates and removed the generated low-score stats row.
- `python .\tools\validator.py --mode file --file by-resource\new-human-motion-tables.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-resource\sobj-tbl.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-resource\staff-dialog-resources.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-resource\-coverage-report.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- Follow-up dry validator checks for all four target docs and `by-resource\-coverage-report.md` returned `ok: 1`.

Leases used:

- `by-resource/meta-dat-metadata-cache.md`
- `by-resource/new-human-motion-tables.md`
- `by-resource/sobj-tbl.md`
- `by-resource/staff-dialog-resources.md`
- `by-resource/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator-owned/generated side effects: `project-level/-auto-completion-stats.md`, `tools/validator.ini`, projected/autogen registry state, and autogen coverage reports. No manual edits were made to generated/project-level files.

Score/routing decisions:

- [UID:0001RT] `webboard-dialog-resources`: `85/91 -> 86/92`; `CANONICAL_OWNER:NONE -> 0000P9`; no emitter/path fields apply to by-resource pages.
- [UID:0001RB] `forced-inform-message-resources`: `85/90 -> 86/91`; `CANONICAL_OWNER:NONE -> 0000JJ`; no emitter/path fields apply to by-resource pages.
- [UID:0001RP] `str-res-localized-strings`: `85/91 -> 86/92`; `CANONICAL_OWNER:NONE -> 0000KK`; no emitter/path fields apply to by-resource pages.
- [UID:0001R5] `alert-dialog-resources`: `86/90 -> 87/91`; `CANONICAL_OWNER:NONE -> 0000HE`; no emitter/path fields apply to by-resource pages.

Evidence:

- Live IDA MCP session `a001_goal2_class_batch` reported `NexusTK.exe` ready, image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- `webboard-dialog-resources`: live `lookup_funcs`, `xrefs_to`, and decompile refs reconfirmed `sub_46E640` size `0x27e`, old response handler `sub_46EAA0` size `0x3da`, one `WEBBOARD.PAD` xref at `0x0046e718`, and two `WEBBOARD.EPD` xrefs at `0x0046e725`/`0x0046e803`, all constructor-local and distinct from RankingDialog `WEBBOARD.EPF`/`.PAL`.
- `forced-inform-message-resources`: live function/xref refresh reconfirmed `sub_587BB0` size `0x4c3`, destructor/button/key/scalar-delete helper bounds, one `DLGSTAFF.PAL` xref, two `DLGSTAFF.EPF` xrefs, two `DLGSTAFF.EPD` xrefs, and the shared `NPAL8.PAL` caveat.
- `str-res-localized-strings`: live decompile/xref refresh reconfirmed `sub_4F0010` size `0x27c`, lookup/copy/destructor helper bounds, one `str.res` constructor xref, `Invalid String ID` at `0x0061ca20` with two xrefs, CR/LF handling, `0x11` to CR remap, ANSI-code-page conversion, and 1024-record cap.
- `alert-dialog-resources`: live function/xref/decompile refresh reconfirmed `BlueAlertPane` constructor/content/border helper bounds, nine `BDFRAME.EPF` xrefs split across content fill and border drawing, 88 shared `OK` xrefs, and one AddEmployee warning xref.

Validation commands/results:

- `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file <target by-resource doc> --apply --queue-timeout 240` was run for all four target docs; each exited `0` with `ok: 1`, and the visible validator output included the expected completion/confidence/canonical-owner updates.
- `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-resource\-coverage-report.md --apply --queue-timeout 240`: exited `0` with `ok: 1`; a rerun after minor wording cleanup also exited `0` with `ok: 1`.
- Post-validation `project-level/-auto-completion-stats.md` rows show [UID:0001RB] `86/91`, [UID:0001RP] `86/92`, [UID:0001RT] `86/92`, and [UID:0001R5] `87/91`.

Leases used:

- `by-resource/webboard-dialog-resources.md`
- `by-resource/forced-inform-message-resources.md`
- `by-resource/str-res-localized-strings.md`
- `by-resource/alert-dialog-resources.md`
- `by-resource/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Supervisor-owned rows/blockers:

- No `by-memory/-coverage-report.md` rows are needed for this by-resource-only batch.
- `by-resource/-coverage-report.md` was initially leased by Agent-A003, so target docs were validated first; after the lease cleared, A002 leased, updated, and validated the report directly.
- No blockers remain.

Next useful follow-up:

- DAT/archive payload provenance remains open for `WEBBOARD.*`, `DLGSTAFF.*`, `BDFRAME.EPF`, and `str.res`; future work should map actual DAT package entries and shared palette/string-table packaging rather than raising these resource pages further from code xrefs alone.

## 2026-06-14 Goal2 resource-payload provenance batch - startup/WebBoard/ForcedInform/str.res/Alert

Changed files:

- `by-resource/application-startup-dat-archives.md`
- `by-resource/webboard-dialog-resources.md`
- `by-resource/forced-inform-message-resources.md`
- `by-resource/str-res-localized-strings.md`
- `by-resource/alert-dialog-resources.md`
- `by-resource/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/routing decisions:

- [UID:0001R6] `application-startup-dat-archives`: `88/90 -> 90/92`; `CANONICAL_OWNER:NONE -> 0000HG`; no emitter/path fields apply to by-resource pages.
- [UID:0001RT] `webboard-dialog-resources`: `86/92 -> 87/92`; owner remains `0000P9`; no emitter/path fields apply.
- [UID:0001RB] `forced-inform-message-resources`: `86/91 -> 87/92`; owner remains `0000JJ`; no emitter/path fields apply.
- [UID:0001RP] `str-res-localized-strings`: `86/92 -> 88/94`; owner remains `0000KK`; no emitter/path fields apply.
- [UID:0001R5] `alert-dialog-resources`: remains `87/91`; owner remains `0000HE`; package audit added but no score raise because `BDFRAME.EPF` was not found.

Package/payload evidence:

- Startup archive inventory from `E:\2026\Resources\Read_Only\NexusTK\Data`: all fixed constructor/initializer archives present (`baramst`, `misc`, `char`, `tile`, `mon`, `efx`, `mnm`, `snd`, `baram`, `bint0`, `bint1`, `bint2`, `wm`); numbered families are gapless for the documented startup prefixes (`FaceDec0`, `Emotion0`, `HairDec0-6`, `Neck0-1`, `body0-14`, `sword0-3`, `spear0-1`, `fan0`, `shield0`, `tile0-23`, `tilec0-26`, `efx0-38`, `bow0-1`, `hair0-3`, `face0`, `helmet0-3`, `mantle0-4`, `shoes0-1`, `coat0-13`, `mon0-67`); `mus000.dat` through `mus006.dat` are present and no `muh###.dat` files were found.
- DAT table parsing found `STR.RES` in `baram.dat`, entry index `9`, offset `11,268,984`, size `7,058`; extracted payload has 248 CR/LF-delimited lines.
- DAT table parsing found `DLGSTAFF.epf` and `DLGSTAFF.pal` in `bint1.dat`, and `NPAL8.PAL` in `bint2.dat`; no `DLGSTAFF.EPD` DAT entry or loose file was found in the audited tree.
- DAT table parsing found `webboard.epf`, `webboard.pal`, `wboardbk.epf`, and `wboardbk.pal` in `bint2.dat`; no `WEBBOARD.EPD` or `WEBBOARD.PAD` DAT entry or loose file was found in the audited tree.
- No `BDFRAME.EPF` DAT entry or loose file was found in the audited tree. Closest frame-like entries were `DLGFRAME.epf` and `frame.epf` in `bint1.dat`, and `TOTFRAME.EPF` in `bint2.dat`; these do not match the BlueAlertPane operand.

Supervisor-owned rows/blockers:

- No `by-memory/-coverage-report.md` rows are needed. No by-memory docs were edited.
- Remaining provenance blockers: legacy `WEBBOARD.EPD`/`WEBBOARD.PAD`, legacy `DLGSTAFF.EPD`, and alert `BDFRAME.EPF` payloads are referenced by IDA evidence but absent from the audited current package. Further raises should use another distribution, loose resource source, or deeper package/version evidence.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-resource\application-startup-dat-archives.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; reported completion/confidence/owner updates and removed [UID:0001R6] from generated by-resource low-score stats.
- `python .\tools\validator.py --mode file --file by-resource\webboard-dialog-resources.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-resource\forced-inform-message-resources.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-resource\str-res-localized-strings.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-resource\alert-dialog-resources.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-resource\-coverage-report.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- Follow-up dry validator check for `by-resource\-coverage-report.md` also returned `ok: 1`.

Leases used:

- `by-resource/application-startup-dat-archives.md`
- `by-resource/webboard-dialog-resources.md`
- `by-resource/forced-inform-message-resources.md`
- `by-resource/str-res-localized-strings.md`
- `by-resource/alert-dialog-resources.md`
- `by-resource/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Lease closeout:

- A002 had no active target-doc leases by final unlease attempt because the initial 300-second leases had already expired after validation; a fresh notes-only lease was taken for this validation/closeout append and then released.

## 2026-06-14 Goal2 resource-payload provenance batch - ranking/hour/icons/interface effects

Changed files:

- `by-resource/ranking-ui-resources.md`
- `by-resource/hourpane-time-resources.md`
- `by-resource/iconspane-icon-resources.md`
- `by-resource/interface-efx-resources.md`
- `by-resource/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## 2026-06-15 - A002-goal2-mixed-lowcompletion-memory-20260615-1

Changed target docs:

- `by-memory/0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper.md`
- `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md`
- `by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md`
- `by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md`
- Validator-owned side effects: `project-level/-auto-completion-stats.md`, `tools/validator.ini`.

Score/routing decisions:

- [UID:00022D] PatchPane2DownloadPathJoinHelper: `78/86 -> 86/89`; `CANONICAL_OWNER:0000AA`, `EMITTER_UIDS:0000AA`, and `auto-generated/NexusTK/patch/PatchPane.cpp` unchanged.
- [UID:00016C] GrafPortTextRunHelpers: `78/86 -> 86/89`; `CANONICAL_OWNER:0000JR`, `EMITTER_UIDS:0000JR`, and `auto-generated/NexusTK/render/GrafPort.cpp` unchanged.
- [UID:00017S] NewHumanImageLibDestructor: `78/86 -> 86/89`; `CANONICAL_OWNER:0000LR`, `EMITTER_UIDS:0000LR`, and `auto-generated/NexusTK/render/NewHumanImageLib.cpp` unchanged.
- [UID:000192] ListNonDeletingDestructor: `78/86 -> 86/89`; `CANONICAL_OWNER:0000KS`, `EMITTER_UIDS:0000KS`, and `auto-generated/NexusTK/util/List.cpp` unchanged.

IDA/local evidence added:

- Live IDA lookup reconfirmed exact modeled starts/sizes, adjacent non-function/next-function boundaries, and unique range signatures for all four targets.
- PatchPane2 helper: one code xref from `sub_549220` at `0x0054928d`; callees limited to shared string copy/length/append helpers `sub_582A90`, `sub_584CF0`, and `sub_584320`.
- GrafPort text helpers: seven modeled starts/sizes, next helper at `0x004bad70`, broad xref breadth (`0x004ba9a0` and `0x004bab70` at least 100 refs each, `0x004baa70` 64, `0x004baaa0` 67, `0x004baad0` 4, `0x004bab20` 3, `0x004bacd0` 31), and internal graph `0x004baa70 -> 0x004ba9a0`, `0x004bab70 -> 0x004ba9a0`, `0x004bacd0 -> 0x004bab70`.
- NewHumanImageLib destructor: one scalar-deleting-destructor caller at `0x004e6876`, vtable refs at `0x004dfd78`/`0x004e027e`, 52 singleton refs at `0x0067a760`, and cleanup/helper callee set.
- List non-deleting destructor: 13 xrefs including EH/unwind refs, List vtable refs across List/SortedList construction/destruction, and callee set limited to backing-buffer free and `LObject` teardown helpers.

Supervisor-applied `by-memory/-coverage-report.md` replacements:

Supervisor applied the exact replacement rows for [UID:00022D], [UID:00016C], [UID:00017S], and [UID:000192] on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.

Validation commands/results:

- From `project-documentation/tools`: `python .\validator.py --mode file --file "..\by-memory\0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper.md" --apply --queue-timeout 300`: exited `0`, `ok: 1`; completion/confidence updated and low stats rows removed.
- From `project-documentation/tools`: `python .\validator.py --mode file --file "..\by-memory\0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md" --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- From `project-documentation/tools`: `python .\validator.py --mode file --file "..\by-memory\0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md" --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- From `project-documentation/tools`: `python .\validator.py --mode file --file "..\by-memory\0x004f30e0-0x004f3139.ListNonDeletingDestructor.md" --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- Follow-up `Select-String` on `project-level/-auto-completion-stats.md` for `00022D|00016C|00017S|000192` returned no matches.

Remaining blockers:

- Final C++ intentionally remains blank for all four targets.
- Remaining blockers: PatchPane2 helper original name/string API spelling; GrafPort field, FontImageLib helper, and invalidation/callback API names; NewHumanImageLib part/layer/motion descriptor field/helper names; List destructor declaration/source split with SortedList.
- No IDA DB changes were made; current function boundaries/labels were adequate, and no safe rename/type change was strongly enough proven for DB mutation.

Leases used:

- `by-memory/0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper.md`
- `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md`
- `by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md`
- `by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## 2026-06-15 - A002-goal2-byclass-patch-clanbank-20260615-1

Changed docs:

- `by-class/PatchPane__PatchFileSlice.md`
- `by-class/ClanBankItemListPane.md`
- `by-class/ClanBankPane.md`
- `by-class/ClanDepItemDialog.md`
- `by-class/-coverage-report.md`
- Validator-owned side effects: `project-level/-auto-completion-stats.md`, `tools/validator.ini`.

Score/routing decisions:

- [UID:0000AC] `PatchPane__PatchFileSlice`: `80/88 -> 86/89`; `CANONICAL_OWNER:0000MH`, `EMITTER_UIDS:0000MH`, and `auto-generated/NexusTK/patch/PatchPane.cpp` unchanged.
- [UID:000025] `ClanBankItemListPane`: `82/86 -> 86/89`; `CANONICAL_OWNER:0000I9`, `EMITTER_UIDS:0000I9`, and `auto-generated/NexusTK/social/ClanBank.cpp` unchanged.
- [UID:000026] `ClanBankPane`: `82/86 -> 86/89`; `CANONICAL_OWNER:0000I9`, `EMITTER_UIDS:0000I9`, and `auto-generated/NexusTK/social/ClanBank.cpp` unchanged.
- [UID:000029] `ClanDepItemDialog`: `82/86 -> 86/89`; `CANONICAL_OWNER:0000I9`, `EMITTER_UIDS:0000I9`, and `auto-generated/NexusTK/social/ClanBank.cpp` unchanged.

IDA/local evidence added:

- PatchFileSlice: live IDA reconfirmed constructor/destructor/vector-deleting destructor sizes, unique `0x005483a0-0x005484db` cluster signature, packet-handler iterator refs, vtable refs from all three bodies, destructor `free_base` callee, and vector-delete/free callees.
- ClanBankItemListPane: live IDA reconfirmed constructor/parser, draw, destructor sizes, unique `0x0048b8c0-0x0048c251` signature, only constructor caller from ClanBankPane, draw/destructor vtable anchors, packet cases `10/15/16`, text fitting, and parser/draw callee sets.
- ClanBankPane: live IDA reconfirmed constructor/action/vtable-reset/destructor sizes, raw packet helper starts `0x0048b7e0`/`0x0048b870` as non-functions, unique `0x0048b1c0-0x0048b7dc` signature, two constructor callers, action-handler vtable anchor, singleton refs, child list construction edge, and shared close-helper fan-in.
- ClanDepItemDialog: live IDA reconfirmed constructor/vtable-reset/button/send sizes, slide-helper sizes, unique `0x0048a1c0-0x0048a805` signature, two constructor callers, button/send vtable anchors, MyItemListPane dependency, and packet-send callee shape.

Coverage/report notes:

- Updated `by-class/-coverage-report.md` rows for [UID:0000AC], [UID:000025], [UID:000026], and [UID:000029] to `86%` with current evidence summaries.
- No `by-memory/-coverage-report.md` rows are needed. No by-memory docs were edited.

Validation commands/results:

- From `project-documentation/tools`: `python .\validator.py --mode file --file "..\by-class\PatchPane__PatchFileSlice.md" --apply --queue-timeout 300`: exited `0`, `ok: 1`; completion/confidence updated and generated by-class low-score row removed.
- From `project-documentation/tools`: `python .\validator.py --mode file --file "..\by-class\ClanBankItemListPane.md" --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- From `project-documentation/tools`: `python .\validator.py --mode file --file "..\by-class\ClanBankPane.md" --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- From `project-documentation/tools`: `python .\validator.py --mode file --file "..\by-class\ClanDepItemDialog.md" --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- From `project-documentation/tools`: `python .\validator.py --mode file --file "..\by-class\-coverage-report.md" --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- Follow-up `Select-String` on `project-level/-auto-completion-stats.md` for `0000AC|000025|000026|000029` returned no matches.

Remaining blockers:

- Final C++ remains blank for all four classes. Current class scores are below the active class reconstruction-code gate and final member/control/virtual names remain provisional.
- PatchFileSlice blockers: final member names and full source-layout semantics.
- ClanBankItemListPane blockers: entry-record field names, local names, and exact virtual method names.
- ClanBankPane blockers: widget member names, original virtual names, and shared slide-helper placement.
- ClanDepItemDialog blockers: inherited fields, exact control/member names, virtual slot names, and shared slide-helper placement.
- No IDA DB changes were made; current function/data identities were adequate, and no safe rename/type mutation was strongly enough proven.

Leases used:

- `by-class/PatchPane__PatchFileSlice.md`
- `by-class/ClanBankItemListPane.md`
- `by-class/ClanBankPane.md`
- `by-class/ClanDepItemDialog.md`
- `by-class/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## A002-goal2-score-byglobal-20260614-8

Changed files:

- `by-global/AesBlockCipherStateAndTables.md`
- `by-global/FindBlockListEntry_5B74E0.md`
- `by-global/FrameChromeSlots.md`
- `by-global/g_pFpsPane.md`
- `by-global/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Validator-owned side effects:

- `project-level/-auto-completion-stats.md`
- `auto-generated/-ag-global-coverage.md`
- `tools/validator.ini`

Score/routing outcomes:

- [UID:00020K] `AesBlockCipherStateAndTables`: `84/92 -> 86/93`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:00020J] `AesBlockCipher`.
- [UID:0000PM] `FindBlockListEntry_5B74E0`: `84/90 -> 86/92`; owner/emitter remain [UID:0000HS] `BlockListenInputPanes`.
- [UID:0000PN] `FrameChromeSlots`: `86/89 -> 87/90`; owner/emitter remain [UID:0000JL] `FrameChrome`.
- [UID:0000QZ] `g_pFpsPane`: `84/88 -> 86/90`; owner/emitter remain [UID:0000JK] `FpsPane`.
- No owner/emitter route changes were justified; all four routes remain non-dead-ended in `auto-generated/-ag-global-coverage.md`.

Evidence added:

- AES: live IDA MCP refreshed the S-box/inverse/Rcon and mutable-state xrefs; corrected local PE section mapping distinguishes loader-zeroed virtual `.data` tail storage from IDA `FF` placeholder/signature rendering, so the coverage row no longer says `0xff`-initialized scratch state.
- Block-list helper: live IDA MCP `analyze_function 0x005b74e0` reconfirmed `0x73` size, callers `sub_5B6CC0`/`sub_5B7140`, callees `sub_584540`/`sub_582950`/`sub_582B70`, SEH/security-cookie wrapper, and loop/output/cleanup behavior.
- Frame chrome slots: live xrefs reconfirmed AboveFrame slot starts, `0x0067a844` no-xref spacer, FramePartPane slot refs, separate high-fanout `g_pGeneralPurposePanel` boundary, component function sizes, and unresolved no-static-caller state for `BuildFramePartPanes`.
- FPS singleton: live xrefs reconfirmed the three `g_pFpsPane` direct refs at `0x004b6434`, `0x004b648a`, and `0x004b6c70`; component analysis tied destructor paths to the three FpsPane vtable views; exact storage child [UID:0002W0] is now cited in the global page.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-global\AesBlockCipherStateAndTables.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; reported completion/confidence updates for [UID:00020K].
- `python .\tools\validator.py --mode file --file by-global\FindBlockListEntry_5B74E0.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; reported completion/confidence updates for [UID:0000PM].
- `python .\tools\validator.py --mode file --file by-global\FrameChromeSlots.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; reported completion/confidence updates for [UID:0000PN].
- `python .\tools\validator.py --mode file --file by-global\g_pFpsPane.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; reported completion/confidence updates for [UID:0000QZ].
- `python .\tools\validator.py --mode file --file by-global\-coverage-report.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- Follow-up dry validator checks for all four targets and `by-global\-coverage-report.md` returned `ok: 1`.
- `project-level/-auto-completion-stats.md` no longer contains `00020K`, `0000PM`, `0000PN`, or `0000QZ`.

Supervisor-owned rows/blockers:

- No `by-memory/-coverage-report.md` row changes are needed from this by-global pass.
- Useful follow-up: a future support-doc pass can reconcile wording in by-memory children that still describe IDA `FF` bytes as initialization for late `.data` pointer slots, distinguishing IDA database placeholder/signature rendering from PE loader-zeroed BSS/static storage. I did not edit by-memory docs in this batch.

Leases used:

- `by-global/AesBlockCipherStateAndTables.md`
- `by-global/FindBlockListEntry_5B74E0.md`
- `by-global/FrameChromeSlots.md`
- `by-global/g_pFpsPane.md`
- `by-global/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## A002-goal2-resource-blocker-provenance-20260614-6

Changed target files:

- `by-resource/hourpane-time-resources.md`
- `by-resource/iconspane-icon-resources.md`
- `by-resource/interface-efx-resources.md`
- `by-resource/staff-dialog-resources.md`
- `by-resource/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/routing decisions:

- [UID:0001RC] `hourpane-time-resources`: `86/90 -> 87/91`; `CANONICAL_OWNER:NONE` unchanged; no emitter/path fields apply to by-resource pages.
- [UID:0001RD] `iconspane-icon-resources`: `86/90 -> 87/91`; `CANONICAL_OWNER:NONE` unchanged; no emitter/path fields apply.
- [UID:0001RE] `interface-efx-resources`: `86/90 -> 87/91`; `CANONICAL_OWNER:NONE` unchanged; no emitter/path fields apply.
- [UID:0001RM] `staff-dialog-resources`: `86/91 -> 87/92`; `CANONICAL_OWNER:NONE` unchanged; no emitter/path fields apply.

Package/raw-scan evidence:

- Corrected DAT parsing uses each entry's stored start offset and the next entry's start as the size boundary. The previous current-package EPF/PAL entries remain valid under that parser.
- HourPane: `Time.epf` remains present in `bint2.dat` entry `100`, offset `15,291,224`, size `10,464`, EPF header `(12, 55, 15)`; `Time.pal` remains entry `101`, offset `15,301,688`, size `1,056`, `DLPalette`. Exact `TIME.EPD` is absent from DAT entry names and loose resources; raw scan found only UTF-16 executable literals in `NexusTK.exe`, `NexusTK2.exe`, and `NexusTK_local.exe` at raw offset `2,203,184`.
- IconsPane: `ICONS.EPF` remains present in `bint2.dat` entry `4`, offset `7,153,461`, size `4,972`, EPF header `(16, 19, 14)`; `NPAL7.PAL` remains entry `49`, offset `9,160,879`, size `1,056`, `DLPalette`. Nearby `ICON.EPF` is a distinct `16`-frame `12x12` entry at index `3`, not this strip. Exact `ICONS.EPD` is absent from DAT entry names and loose resources; raw scan found only UTF-16 executable literals at raw offset `2,203,476`.
- InterfaceEfx: exact `CHREFX.EPD`, `MAGEFX.EPD`, `ITEMEFX.EPD`, `FRMLEFX.EPD`, `FRMREFX.EPD`, and `INTEFX.PAD` are absent from DAT entry names and loose resources. Current `efx.dat` same-basename variants remain `CHREFX.EPF`, `FRMLEFX.EPF`, `FRMREFX.EPF`, `INTEFX.PAL`, `ITEMEFX.EPF`, and `MAGEFX.EPF`. Raw scan found only UTF-16 executable literals at offsets `2,207,936` (`INTEFX.PAD`), `2,207,960` (`CHREFX.EPD`), `2,207,984` (`MAGEFX.EPD`), `2,208,008` (`ITEMEFX.EPD`), `2,208,032` (`FRMLEFX.EPD`), and `2,208,056` (`FRMREFX.EPD`).
- Staff dialog: `NPAL8.PAL` remains present in `bint2.dat` entry `50`, offset `9,161,935`, size `1,056`, `DLPalette`. Exact `STAFF.EPF`, `STAFFS`, and `STAFFS2` are absent from DAT entry names and loose resources. Raw scan found only UTF-16 executable literals at offsets `2,215,556` and `2,278,338` (`STAFF.EPF`), `2,215,576` (`STAFFS2`), and `2,215,592` (`STAFFS`). `DLGSTAFF.epf` / `.pal` in `bint1.dat` are confirmed separate forced-inform resources, not substitutes for this page.

Supervisor-owned rows/blockers:

- No `by-memory/-coverage-report.md` rows are needed. No by-memory docs were edited.
- Remaining blockers: exact old-layout `TIME.EPD`, `ICONS.EPD`, interface-effect `.EPD`/`INTEFX.PAD`, and staff `STAFF.EPF`/`STAFFS`/`STAFFS2` payloads are still missing from the audited current package/loose resource tree. Future progress needs another distribution, installer-era loose resource source, or deeper version provenance rather than more code-xref-only work.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-resource\hourpane-time-resources.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; reported [UID:0001RC] completion/confidence updates and generated stats row update to `87/91`.
- `python .\tools\validator.py --mode file --file by-resource\iconspane-icon-resources.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; reported [UID:0001RD] completion/confidence updates and generated stats row update to `87/91`.
- `python .\tools\validator.py --mode file --file by-resource\interface-efx-resources.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; reported [UID:0001RE] completion/confidence updates and generated stats row update to `87/91`.
- `python .\tools\validator.py --mode file --file by-resource\staff-dialog-resources.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; reported [UID:0001RM] completion/confidence updates and removed the generated low-score stats row.
- `python .\tools\validator.py --mode file --file by-resource\-coverage-report.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- Follow-up dry validator checks for all four target docs and `by-resource\-coverage-report.md` returned `ok: 1`.
- Generated side effects: `project-level/-auto-completion-stats.md` and `tools/validator.ini` changed during validation.

Leases used:

- `by-resource/hourpane-time-resources.md`
- `by-resource/iconspane-icon-resources.md`
- `by-resource/interface-efx-resources.md`
- `by-resource/staff-dialog-resources.md`
- `by-resource/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## A002-goal2-resource-payload-provenance-20260614-5

Changed target files:

- `by-resource/collection-ui-resources.md`
- `by-resource/exchange-dialog-resources.md`
- `by-resource/startup-logo-media.md`
- `by-resource/startup-update-notice-resources.md`
- `by-resource/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/routing decisions:

- [UID:0001R8] `collection-ui-resources`: `85/90 -> 89/93`; `CANONICAL_OWNER:NONE` unchanged; no emitter/path fields apply to by-resource pages.
- [UID:0001RA] `exchange-dialog-resources`: `85/92 -> 88/94`; `CANONICAL_OWNER:NONE` unchanged; no emitter/path fields apply.
- [UID:0001RN] `startup-logo-media`: `85/91 -> 86/92`; `CANONICAL_OWNER:NONE` unchanged; no emitter/path fields apply. This is a limited raise because the package audit found absent media payloads rather than recovered payload bytes.
- [UID:0001RO] `startup-update-notice-resources`: `85/90 -> 88/92`; `CANONICAL_OWNER:NONE` unchanged; no emitter/path fields apply.

Package/payload evidence:

- Collection resources are present across current packages: `9X11FONT.BIN`, `CLTBAR.*`, `CLTENTRY.*`, `CLTICON.*`, `CLTINV.EPF`, `CLTLIST.*`, `CLTNAME.*`, and `CLTVOL0` through `CLTVOL6` in `bint0.dat`; `DLGCLT.*` and `FONTSYMB.*` in `bint1.dat`; `ITEMINV.EPF`/`.PAL` in `bint2.dat`. EPF headers provide frame counts/dimensions and PAL payloads have `DLPalette` headers. `ITEMINV.EPD` was not found as a DAT entry or loose file.
- Exchange resources are present in `bint1.dat`: `DLGEXC1.EPF` entry `20`, offset `1,838,194`, size `167,560`, EPF header `(1, 449, 369)`; `DLGEXC1.PAL` entry `21`, offset `2,005,754`, size `1,056`, `DLPalette` header. No loose duplicates found.
- Startup logo media `NEXON.LGO`, `LOGO.PAK`, and `LOGO.PAD` were not found as exact DAT entries or loose files in the audited read-only package tree. Narrow raw-name scan found only UTF-16 literals in `NexusTK.exe`, `NexusTK2.exe`, and `NexusTK_local.exe` at raw offsets `2,210,892` (`NEXON.LGO`), `2,210,500` (`LOGO.PAK`), and `2,210,520` (`LOGO.PAD`).
- Startup update notice PCX files are present in `baramst.dat`: `brm_ex_a.pcx` index `0`, offset `191`, size `1,538`; `brm_ex_b.pcx` index `1`, offset `1,729`, size `1,546`; `brm_main.pcx` index `2`, offset `3,275`, size `262,537`; `brm_st_a.pcx` index `7`, offset `275,604`, size `8,821`; `brm_st_b.pcx` index `8`, offset `284,425`, size `8,602`; `brm_st_c.pcx` index `9`, offset `293,027`, size `8,505`. Payloads have PCX-like `0a 05 01 08` headers; no loose duplicates found. Adjacent `brm_n_a/b` and `brm_o_a/b` entries remain unpromoted because current WndProc evidence only proves the six documented loads.

Supervisor-owned rows/blockers:

- No `by-memory/-coverage-report.md` rows are needed. No by-memory docs were edited.
- Remaining provenance blockers: `ITEMINV.EPD` is still absent from the audited current package/loose tree; startup logo media payloads are absent from the current audited package and need original installer/loose-media provenance; startup update notice raw helper button rectangles and adjacent `baramst.dat` state-art ownership still need a future helper-state audit; exchange source declaration-table ownership remains unresolved.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-resource\collection-ui-resources.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; reported [UID:0001R8] completion/confidence updates and removed the generated low-score stats row.
- `python .\tools\validator.py --mode file --file by-resource\exchange-dialog-resources.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; reported [UID:0001RA] completion/confidence updates and removed the generated low-score stats row.
- `python .\tools\validator.py --mode file --file by-resource\startup-logo-media.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; reported [UID:0001RN] completion/confidence updates and retained the generated low-score stats row at `86/92`.
- `python .\tools\validator.py --mode file --file by-resource\startup-update-notice-resources.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; reported [UID:0001RO] completion/confidence updates and removed the generated low-score stats row.
- `python .\tools\validator.py --mode file --file by-resource\-coverage-report.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- Follow-up dry validator checks for all four target docs and `by-resource\-coverage-report.md` returned `ok: 1`.
- Generated side effects: `project-level/-auto-completion-stats.md` and `tools/validator.ini` changed during validation.

Leases used:

- `by-resource/collection-ui-resources.md`
- `by-resource/exchange-dialog-resources.md`
- `by-resource/startup-logo-media.md`
- `by-resource/startup-update-notice-resources.md`
- `by-resource/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## 2026-06-14 Goal2 resource-payload provenance batch - BackPane/Employee/NumberInput/TimerPane

Changed files:

- `by-resource/backpane-background-resources.md`
- `by-resource/employee-dialog-resources.md`
- `by-resource/number-input-dialog-resources.md`
- `by-resource/timerpane-number-resources.md`
- `by-resource/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Validator-owned side effects:

- `project-level/-auto-completion-stats.md`
- `tools/validator.ini`

Score/routing decisions:

- [UID:0001R7] `backpane-background-resources`: `85/90 -> 87/91`; `CANONICAL_OWNER:NONE` unchanged; no emitter/path fields apply to by-resource pages. The generated low-score stats row remains at `87/91`.
- [UID:0001R9] `employee-dialog-resources`: `85/91 -> 88/93`; `CANONICAL_OWNER:NONE` unchanged; no emitter/path fields apply. The generated low-score stats row dropped after validation.
- [UID:0001RJ] `number-input-dialog-resources`: `85/91 -> 88/93`; `CANONICAL_OWNER:NONE` unchanged; no emitter/path fields apply. The generated low-score stats row dropped after validation.
- [UID:0001RQ] `timerpane-number-resources`: `85/91 -> 87/92`; `CANONICAL_OWNER:NONE` unchanged; no emitter/path fields apply. The generated low-score stats row dropped after validation.

Package/payload evidence:

- BackPane: `FRAME.EPF` and `FRAME.PAL` are present in `bint1.dat` entries `78` and `79`; `FRAME.EPF` starts with a one-frame `1024x768` EPF header and `FRAME.PAL` has a `DLPalette` header. `NPAL5.PAL` is present in `bint2.dat` entry `47` with a `DLPalette` header. `FRAME.EPD` was not found as a DAT entry or loose file in the audited current tree.
- Employee dialog: `SELLER.EPF`/`.PAL` and `SELLITEM.EPF`/`.PAL` are present in `bint2.dat` entries `78` through `81`; the palette payloads have `DLPalette` headers and the EPF headers match one-frame seller/item art roles. Shared `DLGEXC3.EPF` is present in `bint1.dat` entry `23`. `baram.dat` `STR.RES` entry `9` is 7,058 bytes / 248 lines and resolves localized string id `247` to `Add how many?`.
- NumberInputDialog: shared `DLGEXC3.EPF` is present in `bint1.dat` entry `23`; `PAL01.PAL` and `NPAL8.PAL` are present in `bint2.dat` entries `56` and `50`, both with `DLPalette` headers. `baram.dat` `STR.RES` resolves localized string id `217` to `You have entered an incorrect number.` `DLGEXC3.EPD` was not found as a DAT entry or loose file.
- TimerPane: `NUMBER.EPF` is present in `bint2.dat` entry `52`, offset `9,204,859`, size `13,964`; its EPF header reports 11 `72x72` frames, matching digits `0..9` plus colon frame `10`. `NUMBER.EPD` was not found as a DAT entry or loose file.

Supervisor-owned rows/blockers:

- No `by-memory/-coverage-report.md` rows are needed. No by-memory docs were edited.
- Remaining provenance blockers: current package/loose tree lacks `FRAME.EPD`, `DLGEXC3.EPD`, and `NUMBER.EPD`; visual per-frame glyph/semantics audits remain open for the large `FRAME.EPF` payload and `NUMBER.EPF` glyph identities; employee mixed tail string typing and exact per-string child splits remain open.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-resource\backpane-background-resources.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; reported [UID:0001R7] completion/confidence updates and a generated stats-row update.
- `python .\tools\validator.py --mode file --file by-resource\employee-dialog-resources.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-resource\number-input-dialog-resources.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-resource\timerpane-number-resources.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-resource\-coverage-report.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- Follow-up dry validator checks for all four target docs and `by-resource\-coverage-report.md` returned `ok: 1`.

Leases used:

- `by-resource/backpane-background-resources.md`
- `by-resource/employee-dialog-resources.md`
- `by-resource/number-input-dialog-resources.md`
- `by-resource/timerpane-number-resources.md`
- `by-resource/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/routing decisions:

- [UID:0001RK] `ranking-ui-resources`: `85/88 -> 88/91`; `CANONICAL_OWNER:NONE` unchanged; no emitter/path fields apply to by-resource pages. The generated low-score stats row dropped after validation because the row no longer qualifies for that report.
- [UID:0001RC] `hourpane-time-resources`: `85/89 -> 86/90`; `CANONICAL_OWNER:NONE` unchanged; no emitter/path fields apply.
- [UID:0001RD] `iconspane-icon-resources`: `85/89 -> 86/90`; `CANONICAL_OWNER:NONE` unchanged; no emitter/path fields apply.
- [UID:0001RE] `interface-efx-resources`: `85/89 -> 86/90`; `CANONICAL_OWNER:NONE` unchanged; no emitter/path fields apply.

Package/payload evidence:

- Ranking resource payloads are present in current DAT packages: `WBOARDBK.EPF`/`.PAL`, `WEBBOARD.EPF`/`.PAL`, `SUBWIN.EPF`/`.PAL`, `SLIDEBG.EPF`/`.PAL`, and `SCRBUTT.EPF` in `bint2.dat`; `BUTTON.PAL` in `bint0.dat`; `SYMBOLS.EPF` in `misc.dat`. EPF headers provide frame counts (`WBOARDBK` 1, `WEBBOARD` 8, `SUBWIN` 9, `SLIDEBG` 12, `SCRBUTT` 2, `SYMBOLS` 224) and palette payloads have `DLPalette` headers.
- HourPane current-package payloads are present as `Time.epf` and `Time.pal` in `bint2.dat`; `Time.epf` has a 12-frame EPF header and `Time.pal` has a `DLPalette` header. `TIME.EPD` was not found as a DAT entry or loose file in the audited current tree.
- IconsPane current-package payloads are present as `ICONS.EPF` and `NPAL7.PAL` in `bint2.dat`; `ICONS.EPF` has a 16-frame EPF header and `NPAL7.PAL` has a `DLPalette` header. `ICONS.EPD` was not found as a DAT entry or loose file in the audited current tree.
- Interface effect current-package same-basename payload variants are present in `efx.dat`: `CHREFX.EPF`, `MAGEFX.EPF`, `ITEMEFX.EPF`, `FRMLEFX.EPF`, `FRMREFX.EPF`, and `INTEFX.PAL`. The IDA-referenced `.EPD` operands and `INTEFX.PAD` were not found as DAT entries or loose files in the audited current tree.

Supervisor-owned rows/blockers:

- No `by-memory/-coverage-report.md` rows are needed. No by-memory docs were edited.
- Remaining provenance blockers: `TIME.EPD`, `ICONS.EPD`, `CHREFX.EPD`, `MAGEFX.EPD`, `ITEMEFX.EPD`, `FRMLEFX.EPD`, `FRMREFX.EPD`, and `INTEFX.PAD` remain IDA-referenced but absent from the audited current package/loose resource tree.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-resource\ranking-ui-resources.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; reported [UID:0001RK] completion/confidence updates and removed the generated low-score stats row.
- `python .\tools\validator.py --mode file --file by-resource\hourpane-time-resources.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-resource\iconspane-icon-resources.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-resource\interface-efx-resources.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-resource\-coverage-report.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- Follow-up dry validator checks for all four target docs and `by-resource\-coverage-report.md` returned `ok: 1`.

Leases used:

- `by-resource/ranking-ui-resources.md`
- `by-resource/hourpane-time-resources.md`
- `by-resource/iconspane-icon-resources.md`
- `by-resource/interface-efx-resources.md`
- `by-resource/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## A002-goal2-byclass-clan-effecter-20260615-2

Changed files:

- `by-class/ClanItemListPane.md`
- `by-class/ClanWidItemDialog.md`
- `by-class/CloudFilterEffecter.md`
- `by-class/CollectionBarControlPane.md`
- `by-class/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/routing decisions:

- [UID:00002G] `ClanItemListPane`: `82/86 -> 86/89`; `CANONICAL_OWNER:0000I9` and `EMITTER_UIDS:0000I9` unchanged. C++ remains blank because final field names, raw helper reachability, and shared text-helper source ownership are not source-quality.
- [UID:00002N] `ClanWidItemDialog`: `82/86 -> 86/89`; `CANONICAL_OWNER:0000I9` and `EMITTER_UIDS:0000I9` unchanged. C++ remains blank because inherited dialog fields, control IDs, virtual slot names, and shared slide-helper ownership are not source-quality.
- [UID:00002T] `CloudFilterEffecter`: `82/86 -> 85/88`; `CANONICAL_OWNER:0000IZ` and `EMITTER_UIDS:0000IZ` unchanged. Coverage row was stale at `72%` and is now synchronized to `85%`. C++ remains blank because `0x0055b000` is still a raw non-function island with no direct xrefs.
- [UID:00002U] `CollectionBarControlPane`: `82/86 -> 86/89`; `CANONICAL_OWNER:0000IB` and `EMITTER_UIDS:0000IB` unchanged. C++ remains blank because exact member names and original control declaration are not source-quality.

IDA/local evidence:

- Live IDA MCP session `a003_objectlist_dispatch_20260615` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; health returned `ok`, imagebase `0x400000`, Hex-Rays ready.
- `ClanItemListPane`: lookup confirmed `sub_48AE70` size `0x21c`, `sub_48B0A0` size `0x111`, `sub_48C2FF`/`sub_48C30A` size `0xb`, `sub_48C510` size `0x3b`, and `0x0048b090` still not a function. Xrefs confirm one constructor caller `0x0048ab68`, draw vtable cell `0x0061623c`, destructor thunk callers plus vtable cell `0x006161bc`, component split, and unique range signature for `0x0048ae70-0x0048b1b1`.
- `ClanWidItemDialog`: lookup confirmed `sub_48A810` size `0x4d5`, `sub_48ACF0` size `0x1f`, `sub_48AD10` size `0xd9`, and `sub_48ADF0` size `0x75`. Xrefs confirm constructor callers `0x004853fa` and `0x0048857b`, vtable-only action/send anchors `0x00616164` and `0x00616178`, component shape, and unique range signature for `0x0048a810-0x0048ae65`.
- `CloudFilterEffecter`: lookup confirmed `0x0055b000` still not a function, `sub_55AD00` size `0xbb`, and `nullsub_50` at `0x0055b040` size `0x3`. Xrefs confirm no direct refs to `0x0055b000`, sibling/base calls into `sub_55AD00`, four one-xref cloud vtable stores at `0x0055b00f`, `0x0055b017`, `0x0055b01e`, and `0x0055b028`, plus unique raw range signature for `0x0055b000-0x0055b037`.
- `CollectionBarControlPane`: lookup confirmed `sub_48DC30` size `0xb0`, `sub_48DCE0` size `0x73`, `sub_48DD60` size `0x28c`, `sub_48DFF0` size `0x143`, and `sub_48E190` size `0xb4`. Xrefs confirm two dialog constructor call sites `0x0048c98a` and `0x0048cd8a`, virtual paint slot `0x00616678`, direct paint-to-label call `0x0048dfd7`, component vtable state, collection-data consumer boundary, and unique range signature for `0x0048dc30-0x0048e243`.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-class\ClanItemListPane.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; generated stats row removed for [UID:00002G].
- `python .\tools\validator.py --mode file --file by-class\ClanWidItemDialog.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; generated stats row removed for [UID:00002N].
- `python .\tools\validator.py --mode file --file by-class\CloudFilterEffecter.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; generated stats row removed for [UID:00002T].
- `python .\tools\validator.py --mode file --file by-class\CollectionBarControlPane.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; generated stats row removed for [UID:00002U].
- `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- Follow-up filtered validation for all four targets and `by-class\-coverage-report.md` returned `ok: 1`. `project-level/-auto-completion-stats.md` no longer contains `00002G`, `00002N`, `00002T`, or `00002U`.

Supervisor-owned rows/blockers:

- No `by-memory/-coverage-report.md` rows are needed. No by-memory docs were edited.
- Remaining blockers: source-quality reconstruction still needs exact class/member/control names for the clan and collection controls; `CloudFilterEffecter` still needs constructor reachability/source declaration proof beyond the current raw-island/vtable-store evidence.
- IDA DB changes: skipped. Evidence was sufficient for documentation score/routing updates, and no safe rename/type change was necessary.

Leases used:

- `by-class/ClanItemListPane.md`
- `by-class/ClanWidItemDialog.md`
- `by-class/CloudFilterEffecter.md`
- `by-class/CollectionBarControlPane.md`
- `by-class/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## A002-goal2-byclass-dat-error-20260615-3

Changed files:

- `by-class/DATFileResolver.md`
- `by-class/DIError.md`
- `by-class/DSError.md`
- `by-class/Error.md`
- `by-class/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/routing decisions:

- [UID:00003J] `DATFileResolver`: `82/86 -> 85/88`; `CANONICAL_OWNER:0000IO` and `EMITTER_UIDS:0000IO` unchanged. C++ remains blank because standalone-class status, constructor/source spelling, and final field names are unresolved.
- [UID:00003W] `DIError`: `82/86 -> 85/88`; `CANONICAL_OWNER:0000J5` and `EMITTER_UIDS:0000J5` unchanged. C++ remains blank because the constructor is still raw/non-modeled with no xrefs and final declaration/member names are not source-quality.
- [UID:000045] `DSError`: `82/86 -> 85/88`; `CANONICAL_OWNER:0000J5` and `EMITTER_UIDS:0000J5` unchanged. C++ remains blank because the constructor is still raw/non-modeled with no xrefs and final declaration/member names are not source-quality.
- [UID:00004J] `Error`: `82/86 -> 86/89`; `CANONICAL_OWNER:0000J5` and `EMITTER_UIDS:0000J5` unchanged. C++ remains blank because final virtual names, declaration spelling, and several constructor-shaped raw records are still unresolved.

IDA/local evidence:

- Live IDA MCP session `a003_objectlist_dispatch_20260615` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; health returned `ok`, imagebase `0x400000`, Hex-Rays ready.
- `DATFileResolver`: lookup confirmed `sub_49D190` size `0xdc`, raw `_DATFileMgr` destructor start `0x0049c750` still not a function, `_DATFileMgr::DeletingDestructor` `sub_49D3D0` size `0xb8`, and resolver context functions `sub_49C800`, `sub_49CAD0`, `sub_49CE50`, and `sub_49D5E0`. Xrefs confirm cleanup callers `0x0049c7e8` and `0x0049d462`, `_DATFileMgr` vtable-store refs at `0x0049bda1`, `0x0049c755`, and `0x0049d3dd`, resolver context call graph, and unique destroy-method signature.
- `DIError`: lookup confirmed `0x004a61b0` remains `Not a function`, formatter `sub_4A61E0` size `0x7b`, status-wrapper destructor `sub_4A68A0` size `0x3e`, and name helper `sub_4A6A70` size `0x6`. Xrefs confirm no constructor-start refs, formatter vtable anchor `0x00619380`, constructor vtable store `0x004a61c7 -> 0x00619374`, five-class status-wrapper destructor fanout, and unique raw-constructor/formatter signature.
- `DSError`: lookup confirmed `0x004a6330` remains `Not a function`, formatter `sub_4A6360` size `0x7b`, status-wrapper destructor `sub_4A68A0` size `0x3e`, and name helper `sub_4A6A70` size `0x6`. Xrefs confirm no constructor-start refs, formatter vtable anchor `0x006193b0`, constructor vtable store `0x004a6347 -> 0x006193a4`, five-class status-wrapper destructor fanout, and unique raw-constructor/formatter signature.
- `Error`: lookup confirmed base cleanup helper `sub_4A6400` size `0xb`, status-code wrapper destructor `sub_4A68A0` size `0x3e`, base `Error` destructor `sub_4A68E0` size `0x3e`, and common name helper `sub_4A6A70` size `0x6`. Xrefs confirm base-only destructor cell `0x00619344`, five status-wrapper destructor cells, 11 common descriptor/name-helper cells, shared base-vtable restore pattern, destructor-family component evidence, and unique destructor/name-helper cluster signature.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-class\DATFileResolver.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; generated stats row removed for [UID:00003J].
- `python .\tools\validator.py --mode file --file by-class\DIError.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; generated stats row removed for [UID:00003W].
- `python .\tools\validator.py --mode file --file by-class\DSError.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; generated stats row removed for [UID:000045].
- `python .\tools\validator.py --mode file --file by-class\Error.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; generated stats row removed for [UID:00004J].
- `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- Follow-up checks confirmed `project-level/-auto-completion-stats.md` no longer contains `00003J`, `00003W`, `000045`, or `00004J`.

Supervisor-owned rows/blockers:

- No `by-memory/-coverage-report.md` rows are needed. No by-memory docs were edited.
- Remaining blockers: `DATFileResolver` still needs proof of standalone source declaration versus embedded `_DATFileMgr` member; `DIError` and `DSError` raw constructor starts still lack IDA function records/xrefs; `Error` still needs final virtual names and declaration shape before source-quality C++.
- IDA DB changes: skipped. Evidence supported documentation score/routing updates, but no safe rename/type change was necessary.

Leases used:

- `by-class/DATFileResolver.md`
- `by-class/DIError.md`
- `by-class/DSError.md`
- `by-class/Error.md`
- `by-class/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## A002-goal2-byclass-error-field-input-20260615-4

Changed files:

- `by-class/ErrorMessage.md`
- `by-class/ExceptionHandler.md`
- `by-class/FieldMapPane.md`
- `by-class/InputMan.md`
- `by-class/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## A002-goal2-shared-collection-look-thunks-memory-20260615-12

Changed files:

- `by-memory/0x005539c3-0x005539d9.SharedDialogDefaultDestructorThunksLate.md`
- `by-memory/0x00573247-0x00573273.CollectionPaneAdjustorThunks.md`
- `by-memory/0x00573273-0x005732b5.GroupPaneAdjustorThunks.md`
- `by-memory/0x005732b5-0x00573302.LookPaneAdjustorThunks.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Generated stats touched by validator: `project-level/-auto-completion-stats.md`

Score/routing decisions:

- [UID:00023N] `SharedDialogDefaultDestructorThunksLate`: `80/85 -> 88/92`; `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, `RECONSTRUCTABLE:FALSE`, and blank final C++ remain unchanged.
- [UID:00023Y] `CollectionPaneAdjustorThunks`: `80/85 -> 88/92`; `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, `RECONSTRUCTABLE:FALSE`, and blank final C++ remain unchanged.
- [UID:0001HM] `GroupPaneAdjustorThunks`: `80/85 -> 88/92`; `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, `RECONSTRUCTABLE:FALSE`, and blank final C++ remain unchanged. Per-thunk table rows were normalized to half-open ranges.
- [UID:0001HN] `LookPaneAdjustorThunks`: `80/85 -> 88/92`; `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, `RECONSTRUCTABLE:FALSE`, and blank final C++ remain unchanged. Per-thunk table rows were normalized to half-open ranges.

IDA/local evidence:

- Live IDA MCP session `a003_objectlist_dispatch_20260615` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- [UID:00023N]: `lookup_funcs`/`analyze_function` confirmed exact `0x005539c3` and `0x005539ce` 0x0b-byte bodies, `this` adjustments `0xa0`/`0xa4`, tail-jump target `0x00520b70`, vtable refs `0x00622cb8`/`0x00622ce8`, setup refs from `sub_553610`, non-function half-open end `0x005539d9`, broad shared-default destructor refs, and unique signature `81 E9 A0 00 00 00 E9 A2 D1 FC FF 81 E9 A4 00 00 00 E9 97 D1 FC FF`.
- [UID:00023Y]: live IDA confirmed exact starts `0x00573247`, `0x00573252`, `0x0057325d`, and `0x00573268`; target destructors `0x00573310` and `0x00573370`; vtable cells `0x006246bc`, `0x006246ec`, `0x00624630`, and `0x00624660`; adjacent next island at `0x00573273`; and unique signature `81 E9 A0 00 00 00 E9 BE 00 00 00 81 E9 A4 00 00 00 E9 B3 00 00 00 81 E9 A0 00 00 00 E9 08 01 00 00 81 E9 A4 00 00 00 E9 FD 00 00 00`.
- [UID:0001HM]: live IDA confirmed six exact 0x0b-byte starts from `0x00573273` through `0x005732aa`; targets `0x005733e0`, `0x00573490`, and `0x00573570`; vtable cells `0x00624518`, `0x00624548`, `0x0062448c`, `0x006244bc`, `0x006245a4`, and `0x006245d4`; next island at `0x005732b5`; and unique signature `81 E9 A0 00 00 00 E9 62 01 00 00 81 E9 A4 00 00 00 E9 57 01 00 00 81 E9 A0 00 00 00 E9 FC 01 00 00 81 E9 A4 00 00 00 E9 F1 01 00 00 81 E9 A0 00 00 00 E9 C6 02 00 00 81 E9 A4 00 00 00 E9 BB 02 00 00`.
- [UID:0001HN]: live IDA confirmed seven exact 0x0b-byte starts from `0x005732b5` through `0x005732f7`; targets `0x00573640`, `0x00573730`, and `0x00573820`; vtable cells `0x00624748`, `0x00624778`, `0x006241d8`, `0x00624208`, `0x0062437c`, `0x00624340`, and `0x00624370`; `0x00573302` as non-function padding before `0x00573310`; and unique signature `81 E9 A0 00 00 00 E9 80 03 00 00 81 E9 A4 00 00 00 E9 75 03 00 00 81 E9 A0 00 00 00 E9 5A 04 00 00 81 E9 A4 00 00 00 E9 4F 04 00 00 81 E9 74 01 00 00 E9 34 05 00 00 81 E9 A0 00 00 00 E9 29 05 00 00 81 E9 A4 00 00 00 E9 1E 05 00 00`.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-memory\0x005539c3-0x005539d9.SharedDialogDefaultDestructorThunksLate.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `88/92`; generated low-score stats rows removed for [UID:00023N].
- `python .\tools\validator.py --mode file --file by-memory\0x00573247-0x00573273.CollectionPaneAdjustorThunks.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `88/92`; generated low-score stats rows removed for [UID:00023Y].
- `python .\tools\validator.py --mode file --file by-memory\0x00573273-0x005732b5.GroupPaneAdjustorThunks.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `88/92`; generated low-score stats rows removed for [UID:0001HM].
- `python .\tools\validator.py --mode file --file by-memory\0x005732b5-0x00573302.LookPaneAdjustorThunks.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `88/92`; generated low-score stats rows removed for [UID:0001HN].
- Follow-up check confirmed `project-level/-auto-completion-stats.md` no longer contains `00023N`, `00023Y`, `0001HM`, or `0001HN`.
- Validator also reported unrelated stale registered paths for [UID:0001EU] `PatchPaneAdjustorThunks` and [UID:0001F0] `PatchPane2AdjustorThunks`; those are outside this A002 batch and were not edited.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

Supervisor applied and validated these replacement rows in the shared coverage report on 2026-06-15 (`ok: 1`). They are retained below for audit only and are no longer pending.

- Placement context: replace [UID:00023N] between [UID:0000VN] `HeadSelectDialog` adjustor-thunk ignore ledger row and [UID:0000VN] `0x005539d9-0x005539e0` padding row.
    - [UID:00023N][0x005539c3-0x005539d9.SharedDialogDefaultDestructorThunksLate](by-memory/0x005539c3-0x005539d9.SharedDialogDefaultDestructorThunksLate.md) 0x005539c3-0x005539d9 | compiler adjustor thunks | SharedDialogDefaultDestructorThunksLate : ignored : 88% : strong : Compiler-generated late shared dialog default destructor adjustor thunks; live 2026-06-15 IDA MCP reconfirms two exact 0xb-byte bodies, `this` adjustments `0xa0`/`0xa4`, tail-jump target `0x00520b70`, vtable refs `0x00622cb8`/`0x00622ce8`, setup refs from `sub_553610`, non-function half-open end `0x005539d9`, broad shared-default destructor refs, and unique byte signature; source reconstruction should express real dialog inheritance/destructor declarations, not handwritten thunk functions.
- Placement context: replace [UID:00023Y], [UID:0001HM], and [UID:0001HN] between [UID:0001HL] `LineIteratorDestructor` and [UID:0000VN] `0x00573302-0x00573310` padding row.
    - [UID:00023Y][0x00573247-0x00573273.CollectionPaneAdjustorThunks](by-memory/0x00573247-0x00573273.CollectionPaneAdjustorThunks.md) 0x00573247-0x00573273 | compiler thunk strip | CollectionPaneAdjustorThunks : ignored : 88% : strong : Compiler-generated CollectionPane2 and CollectionPane secondary/tertiary destructor adjustor thunks; live 2026-06-15 IDA MCP reconfirms four exact 0xb-byte bodies, `this` adjustments `0xa0`/`0xa4`, tail-jump targets `0x00573310` and `0x00573370`, vtable refs `0x006246bc`, `0x006246ec`, `0x00624630`, and `0x00624660`, adjacent next island at `0x00573273`, and unique byte signature; source reconstruction should use normal CollectionPane/CollectionPane2 inheritance/destructor declarations, not handwritten thunk functions.
    - [UID:0001HM][0x00573273-0x005732b5.GroupPaneAdjustorThunks](by-memory/0x00573273-0x005732b5.GroupPaneAdjustorThunks.md) 0x00573273-0x005732b5 | compiler thunk strip | GroupPaneAdjustorThunks : ignored : 88% : strong : Compiler-generated GroupPane2, GroupPane, and NewGroupPane secondary/tertiary destructor adjustor thunks; live 2026-06-15 IDA MCP reconfirms six exact 0xb-byte bodies, `this` adjustments `0xa0`/`0xa4`, tail-jump targets `0x005733e0`, `0x00573490`, and `0x00573570`, vtable refs `0x00624518`, `0x00624548`, `0x0062448c`, `0x006244bc`, `0x006245a4`, and `0x006245d4`, adjacent next island at `0x005732b5`, and unique byte signature; source reconstruction should use normal group-pane inheritance/destructor declarations, not handwritten thunk functions.
    - [UID:0001HN][0x005732b5-0x00573302.LookPaneAdjustorThunks](by-memory/0x005732b5-0x00573302.LookPaneAdjustorThunks.md) 0x005732b5-0x00573302 | compiler thunk strip | LookPaneAdjustorThunks : ignored : 88% : strong : Compiler-generated SelfLookPane2, SelfLookPane, and SpelledPane destructor adjustor thunks; live 2026-06-15 IDA MCP reconfirms seven exact 0xb-byte bodies, `this` adjustments `0xa0`, `0xa4`, and `0x174`, tail-jump targets `0x00573640`, `0x00573730`, and `0x00573820`, vtable refs `0x00624748`, `0x00624778`, `0x006241d8`, `0x00624208`, `0x0062437c`, `0x00624340`, and `0x00624370`, `0x00573302` as non-function padding before `0x00573310`, and unique byte signature; source reconstruction should use normal look-pane/spelled-pane inheritance/destructor declarations, not handwritten thunk functions.

Supervisor application notes:

- `by-memory/-coverage-report.md` application is complete for this batch; A002 did not edit it directly.
- Remaining blocker: no source C++ should be emitted for these compiler-generated adjustor thunks. Source-facing semantics belong to the related class, vtable, and scalar destructor pages.
- IDA DB changes: skipped. Evidence supported documentation score/routing updates, but no safe rename/type change was necessary.

Leases used:

- `by-memory/0x005539c3-0x005539d9.SharedDialogDefaultDestructorThunksLate.md`
- `by-memory/0x00573247-0x00573273.CollectionPaneAdjustorThunks.md`
- `by-memory/0x00573273-0x005732b5.GroupPaneAdjustorThunks.md`
- `by-memory/0x005732b5-0x00573302.LookPaneAdjustorThunks.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## A002-goal2-message-motion-thunks-memory-20260615-11

Changed files:

- `by-memory/0x00520b13-0x00520b29.ServerItemMenuItemListDestructorThunks.md`
- `by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md`
- `by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md`
- `by-memory/0x0053ce50-0x0053ce8e.MotionPoolFreeUnwindWrapper.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Generated stats touched by validator: `project-level/-auto-completion-stats.md`

Score/routing decisions:

- [UID:0001BZ] `ServerItemMenuItemListDestructorThunks`: `80/85 -> 88/92`; `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, `RECONSTRUCTABLE:FALSE`, and blank final C++ remain unchanged.
- [UID:0001C5] `MessageShowPaneClearSingletonEH`: `80/85 -> 88/92`; `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, `RECONSTRUCTABLE:FALSE`, and blank final C++ remain unchanged.
- [UID:0001C6] `MessageShowPaneAdjustorThunks`: `80/85 -> 88/92`; `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, `RECONSTRUCTABLE:FALSE`, and blank final C++ remain unchanged.
- [UID:0001DK] `MotionPoolFreeUnwindWrapper`: `80/85 -> 88/92`; `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, `RECONSTRUCTABLE:FALSE`, and blank final C++ remain unchanged.

IDA/local evidence:

- Live IDA MCP session `a003_objectlist_dispatch_20260615` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- [UID:0001BZ]: `lookup_funcs`/`disasm`/`analyze_function` confirmed exact `0x00520b13` and `0x00520b1e` 0x0b-byte bodies, `this` adjustments `0xa0`/`0xa4`, tail-jump target `0x00520ce0`, vtable refs `0x0061efcc`/`0x0061effc`, primary destructor vtable ref `0x0061ef44`, successor thunk at `0x00520b29`, and repeated adjustor signature `81 E9 A0 00 00 00 E9 C2 01 00 00 81 E9 A4 00 00 00 E9 B7 01 00 00`.
- [UID:0001C5]: live IDA confirmed `sub_5226F0` as a 0x0b-byte singleton clear body `mov dword_69B4F4, 0; retn`, constructor EH xref `0x00603e07` from `sub_521DA0`, global lifecycle refs to `0x0069b4f4`, adjacent thunk start at `0x005226fb`, and unique signature `C7 05 F4 B4 69 00 00 00 00 00 C3`.
- [UID:0001C6]: live IDA confirmed exact `0x005226fb` and `0x00522706` 0x0b-byte bodies, `this` adjustments `0xa0`/`0xa4`, tail-jump target `0x00522720`, secondary/tertiary vtable refs `0x0061fa98`/`0x0061fac8`, primary scalar destructor vtable ref `0x0061fa4c`, padding/non-function boundary at `0x00522711`, scalar destructor start at `0x00522720`, and repeated adjustor signature `81 E9 A0 00 00 00 E9 1A 00 00 00 81 E9 A4 00 00 00 E9 0F 00 00 00`.
- [UID:0001DK]: live IDA confirmed `sub_53CE50` as a `0x3e`-byte EH/security-cookie wrapper, unrelated preceding boost exception jump at `0x0053ce40`, padding at `0x0053ce45-0x0053ce50`, successor function at `0x0053ce8e`, call to `0x004b14c0` at `0x0053ce7a`, Motion pool ref `0x0069b984`, EH xref/caller relationship from `sub_53B3D0` at `0x00605374`, and unique signature `55 8B EC 6A FF 68 F0 92 5F 00 64 A1 00 00 00 00 50 A1 24 2F 67 00 33 C5 50 8D 45 F4 64 A3 00 00 00 00 FF 75 08 B9 84 B9 69 00 E8 41 46 F7 FF 8B 4D F4 64 89 0D 00 00 00 00 59 8B E5 5D C3`.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-memory\0x00520b13-0x00520b29.ServerItemMenuItemListDestructorThunks.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `88/92`; generated low-score stats rows removed for [UID:0001BZ].
- `python .\tools\validator.py --mode file --file by-memory\0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `88/92`; generated low-score stats rows removed for [UID:0001C5].
- `python .\tools\validator.py --mode file --file by-memory\0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `88/92`; generated low-score stats rows removed for [UID:0001C6].
- `python .\tools\validator.py --mode file --file by-memory\0x0053ce50-0x0053ce8e.MotionPoolFreeUnwindWrapper.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `88/92`; generated low-score stats rows removed for [UID:0001DK].
- Follow-up check confirmed `project-level/-auto-completion-stats.md` no longer contains `0001BZ`, `0001C5`, `0001C6`, or `0001DK`.

Supervisor application status for `by-memory/-coverage-report.md`:

Supervisor applied and validated these replacement rows in the shared coverage report. They are retained below for audit only and are no longer pending.

- Placement context: replace [UID:0001BZ] between [UID:0000VN] ignored range `0x00520b13-0x00520b6b` and [UID:0001C0] `SharedDialogDefaultScalarDestructor`.
    - [UID:0001BZ][0x00520b13-0x00520b29.ServerItemMenuItemListDestructorThunks](by-memory/0x00520b13-0x00520b29.ServerItemMenuItemListDestructorThunks.md) 0x00520b13-0x00520b29 | compiler thunk pair | ServerItemMenuItemListDestructorThunks : ignored : 88% : strong : Compiler-generated ServerItemMenuItemList secondary/tertiary destructor adjustor thunks; live 2026-06-15 IDA MCP reconfirms two exact 0xb-byte bodies, `this` adjustments `0xa0`/`0xa4`, tail-jump target `0x00520ce0`, secondary/tertiary vtable refs `0x0061efcc`/`0x0061effc`, primary destructor vtable ref `0x0061ef44`, successor thunk at `0x00520b29`, and repeated adjustor byte signature; source reconstruction should use normal ServerItemMenuItemList inheritance/destructor declarations, not handwritten thunk functions.
- Placement context: replace nested [UID:0001C5] and [UID:0001C6] under [UID:0001C3] `MessageAndMessageShowPane`, between [UID:0001C4] `MessageShowPaneSetWrappedText` and [UID:0001C7] `MessageShowPaneScalarDeletingDestructor`.
        - [UID:0001C5][0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH](by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md) 0x005226f0-0x005226fb | compiler EH cleanup | MessageShowPaneClearSingletonEH : ignored : 88% : strong : Compiler-generated MessageShowPane constructor-unwind singleton-clear helper; live 2026-06-15 IDA MCP reconfirms the exact 0xb-byte `mov dword_69B4F4, 0; retn` body, constructor EH xref at `0x00603e07`, global lifecycle refs for `0x0069b4f4`, adjacent thunk start at `0x005226fb`, and unique byte signature; source reconstruction should model normal MessageShowPane constructor/destructor singleton ownership, not a handwritten standalone helper.
        - [UID:0001C6][0x005226fb-0x00522711.MessageShowPaneAdjustorThunks](by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md) 0x005226fb-0x00522711 | compiler thunk pair | MessageShowPaneAdjustorThunks : ignored : 88% : strong : Compiler-generated MessageShowPane secondary/tertiary destructor adjustor thunks; live 2026-06-15 IDA MCP reconfirms two exact 0xb-byte bodies, `this` adjustments `0xa0`/`0xa4`, tail-jump target `0x00522720`, vtable refs `0x0061fa98`/`0x0061fac8`, primary scalar destructor vtable ref `0x0061fa4c`, `0x00522711` padding before scalar destructor start `0x00522720`, and repeated adjustor byte signature; source reconstruction should use normal MessageShowPane inheritance/destructor declarations, not handwritten thunk functions.
- Placement context: replace [UID:0001DK] between [UID:0001DJ] `SoundObjectPaneCore` and [UID:0001DL] `ObjectPaneCompanionDestructors`.
    - [UID:0001DK][0x0053ce50-0x0053ce8e.MotionPoolFreeUnwindWrapper](by-memory/0x0053ce50-0x0053ce8e.MotionPoolFreeUnwindWrapper.md) 0x0053ce50-0x0053ce8e | compiler EH cleanup | MotionPoolFreeUnwindWrapper : ignored : 88% : strong : Compiler-generated Motion constructor-failure pool-free wrapper; live 2026-06-15 IDA MCP reconfirms exact `0x3e` bounds, preceding unrelated boost exception jump plus padding, successor function at `0x0053ce8e`, EH/security-cookie frame setup, pool ref `0x0069b984`, call to `0x004b14c0` at `0x0053ce7a`, EH xref from `sub_53B3D0` at `0x00605374`, and unique byte signature; source reconstruction should express Motion pool allocation/destruction policy and let compiler EH generation recreate this wrapper.

Supervisor application notes:

- `by-memory/-coverage-report.md` application is complete for this batch; A002 did not edit it directly.
- Remaining blocker: no source C++ should be emitted for these compiler-generated destructor adjustor/EH cleanup wrappers. Source-facing semantics belong to the relevant class, scalar destructor, singleton, or pool policy pages.
- IDA DB changes: skipped. Evidence supported documentation score/routing updates, but no safe rename/type change was necessary.

Leases used:

- `by-memory/0x00520b13-0x00520b29.ServerItemMenuItemListDestructorThunks.md`
- `by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md`
- `by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md`
- `by-memory/0x0053ce50-0x0053ce8e.MotionPoolFreeUnwindWrapper.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## A002-goal2-controlpane-adjustor-thunks-memory-20260615-10

Changed files:

- `by-memory/0x0049af3d-0x0049af52.ControlPaneAdjustorThunks.md`
- `by-memory/0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks.md`
- `by-memory/0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks.md`
- `by-memory/0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Generated stats touched by validator: `project-level/-auto-completion-stats.md`

Score/routing decisions:

- [UID:000120] `ControlPaneAdjustorThunks`: `80/85 -> 88/92`; `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, `RECONSTRUCTABLE:FALSE`, and blank final C++ remain unchanged.
- [UID:000121] `NumericStringControlPaneAdjustorThunks`: `80/85 -> 88/92`; `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, `RECONSTRUCTABLE:FALSE`, and blank final C++ remain unchanged.
- [UID:000122] `RectangleControlPaneAdjustorThunks`: `80/85 -> 88/92`; `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, `RECONSTRUCTABLE:FALSE`, and blank final C++ remain unchanged.
- [UID:00012P] `DescPaneDestructorAdjustorThunks`: `80/85 -> 88/92`; `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, `RECONSTRUCTABLE:FALSE`, and blank final C++ remain unchanged.

IDA/local evidence:

- Live IDA MCP session `a003_objectlist_dispatch_20260615` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; imagebase `0x400000`, Hex-Rays ready.
- [UID:000120]: `lookup_funcs`/`disasm`/`analyze_function` confirmed two 0x0b-byte wrappers at `0x0049af3d` and `0x0049af48`, exact `sub ecx, 0A0h` / `sub ecx, 0A4h` plus tail jumps to `0x0049b170`, no strings/ordinary callers, vtable refs `0x00617af8`/`0x00617b28` plus reuse cells `0x00617b9c`/`0x00617bcc`, successor thunk at `0x0049af53`, and unique signature `81 E9 A0 00 00 00 E9 28 02 00 00 81 E9 A4 00 00 00 E9 1D 02 00 00`.
- [UID:000121]: live IDA confirmed wrappers at `0x0049af7f` and `0x0049af8a`, tail jumps to `0x0049b2f0`, vtable refs `0x006183f8`/`0x00618428`, successor thunk at `0x0049af95`, and unique signature `81 E9 A0 00 00 00 E9 66 03 00 00 81 E9 A4 00 00 00 E9 5B 03 00 00`.
- [UID:000122]: live IDA confirmed wrappers at `0x0049afc1` and `0x0049afcc`, tail jumps to `0x0049b490`, vtable refs `0x0061849c`/`0x006184cc`, successor thunk at `0x0049afd7`, and unique signature `81 E9 A0 00 00 00 E9 C4 04 00 00 81 E9 A4 00 00 00 E9 B9 04 00 00`.
- [UID:00012P]: live IDA confirmed wrappers at `0x0049d81e` and `0x0049d829`, tail jumps to `0x0049d840`, vtable refs `0x00618a28`/`0x00618a58`, `0x0049d834` as non-function padding before `sub_49D840`, and non-unique repeated thunk signature `81 E9 A0 00 00 00 E9 17 00 00 00 81 E9 A4 00 00 00 E9 0C 00 00 00`.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-memory\0x0049af3d-0x0049af52.ControlPaneAdjustorThunks.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `88/92`; generated low-score stats rows removed for [UID:000120].
- `python .\tools\validator.py --mode file --file by-memory\0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `88/92`; generated low-score stats rows removed for [UID:000121].
- `python .\tools\validator.py --mode file --file by-memory\0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `88/92`; generated low-score stats rows removed for [UID:000122].
- `python .\tools\validator.py --mode file --file by-memory\0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `88/92`; generated low-score stats rows removed for [UID:00012P].

Supervisor applied the exact [UID:000120], [UID:000121], [UID:000122], and [UID:00012P] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A002 Goal 2 control-pane adjustor thunk supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

Supervisor-owned rows/blockers:

- `by-memory/-coverage-report.md` remains pending for supervisor application only; A002 did not edit it directly.
- Remaining blocker: no source C++ should be emitted for these compiler-generated destructor adjustor thunks. The source-facing declaration/reconstruction work belongs in the class/file/vtable pages and scalar destructor children.
- IDA DB changes: skipped. Evidence supported documentation score/routing updates, but no safe rename/type change was necessary.

Leases used:

- `by-memory/0x0049af3d-0x0049af52.ControlPaneAdjustorThunks.md`
- `by-memory/0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks.md`
- `by-memory/0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks.md`
- `by-memory/0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## A002-goal2-static-init-wrappers-memory-20260615-7

Score/routing decisions:

- [UID:0000W7] `StaticInitializerWrappersPreOle`: `80/85 -> 85/91`; `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, and blank C++ unchanged. This is compiler/static-initializer glue; source reconstruction belongs to the underlying static objects.
- [UID:0000W9] `StaticInitializerWrappersAfterOle`: `80/85 -> 85/91`; routing unchanged as ignored/non-emitting compiler/static-initializer glue.
- [UID:0000WB] `StaticInitializerWrappersBeforePoolAllocators`: `80/85 -> 86/91`; routing unchanged as ignored/non-emitting compiler/static-initializer glue.
- [UID:0000WC] `PoolAllocatorStaticConstructorWrappers`: `80/85 -> 86/92`; routing unchanged as ignored/non-emitting compiler-generated `PoolAllocator` static-constructor wrappers. Exact static pool declarations remain distributed through the concrete pool-storage/global docs, not this wrapper strip.

IDA/local evidence:

- Live IDA MCP session `a003_objectlist_dispatch_20260615` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; health returned `ok`, imagebase `0x400000`, Hex-Rays ready.
- `StaticInitializerWrappersPreOle`: `lookup_funcs` reconfirmed `sub_419E60`/`sub_419E70` size `0xb`, `sub_419E80` size `0x34`, and `sub_419EC0` size `0x16`; `xrefs_to` returned one startup-table data xref per wrapper at `0x0060d694`, `0x0060d698`, `0x0060d69c`, and `0x0060d6a0`; `analyze_component` confirmed single-block wrapper shapes calling `sub_424850`, `sub_4F4A80`, `sub_49BCB0`, and `_atexit` where applicable.
- `StaticInitializerWrappersAfterOle`: `lookup_funcs` reconfirmed `sub_419F00` size `0x15`, `sub_419F20` size `0x1d`, `sub_419F40` size `0xc`, and `sub_419F50` size `0x16`; `xrefs_to` returned one startup-table data xref per wrapper at `0x0060d6a8`, `0x0060d6ac`, `0x0060d6b0`, and `0x0060d6bc`; `analyze_component` confirmed clear/setup/atexit wrapper bodies.
- `StaticInitializerWrappersBeforePoolAllocators`: `lookup_funcs` reconfirmed six wrappers from `0x00419f90` through `0x0041a030` with sizes `0x16`, `0x16`, `0x16`, `0x1d`, `0x16`, and `0xc`; `xrefs_to` returned one startup-table data xref per wrapper at `0x0060d6b8`, `0x0060d6c0`, `0x0060d6c4`, `0x0060d6c8`, `0x0060d6cc`, and `0x0060d6d0`; `analyze_component` confirmed independent single-block setup/atexit wrappers with no internal call graph edges.
- `PoolAllocatorStaticConstructorWrappers`: `lookup_funcs` reconfirmed all eighteen wrappers from `0x0041a040` through `0x0041a260`; sixteen are size `0x1d`, and the two short-form wrappers at `0x0041a120`/`0x0041a240` are size `0x1a`; `xrefs_to` returned one startup-table data xref per wrapper and no ordinary code callers; `analyze_component` confirmed each wrapper calls `sub_4B13D0` and `_atexit`.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-memory\0x00419e56-0x00419ee0.StaticInitializerWrappersPreOle.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; completion/confidence updated to `85/91`; generated low-completion, low-both, and by-memory stats rows removed for [UID:0000W7].
- `python .\tools\validator.py --mode file --file by-memory\0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; completion/confidence updated to `85/91`; generated low-completion, low-both, and by-memory stats rows removed for [UID:0000W9].
- `python .\tools\validator.py --mode file --file by-memory\0x00419f86-0x0041a040.StaticInitializerWrappersBeforePoolAllocators.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; completion/confidence updated to `86/91`; generated low-completion, low-both, and by-memory stats rows removed for [UID:0000WB].
- `python .\tools\validator.py --mode file --file by-memory\0x0041a040-0x0041a27d.PoolAllocatorStaticConstructorWrappers.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; completion/confidence updated to `86/92`; generated low-completion, low-both, and by-memory stats rows removed for [UID:0000WC].

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

Supervisor applied the exact [UID:0000W7], [UID:0000W9], [UID:0000WB], and [UID:0000WC] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A002 Goal 2 static-initializer wrapper supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

Supervisor-owned rows/blockers:

- Pending shared rows: none. A002 did not edit `by-memory/-coverage-report.md` directly.
- Remaining blockers: final source-facing owner names for several initialized statics are handled by underlying static-storage/global pages; no owner/emitter route should be forced onto these wrapper islands.
- IDA DB changes: skipped. Evidence supported documentation score/routing updates but no safe rename/type change was necessary.

Leases used:

- `by-memory/0x00419e56-0x00419ee0.StaticInitializerWrappersPreOle.md`
- `by-memory/0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle.md`
- `by-memory/0x00419f86-0x0041a040.StaticInitializerWrappersBeforePoolAllocators.md`
- `by-memory/0x0041a040-0x0041a27d.PoolAllocatorStaticConstructorWrappers.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## A002-goal2-field-hierlist-imagelib-memory-20260615-5

Changed files:

- Renamed `by-memory/0x004b11a0-0x004b1241.FieldMapRequestHelper.md` -> `by-memory/0x004b11a0-0x004b1242.FieldMapRequestHelper.md`
- `by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md`
- `by-memory/0x004ce9b0-0x004ceafc.HierListInsertAfter.md`
- `by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md`
- `by-file/FieldMapPane.md`
- `by-class/FieldMapPane.md`
- `by-class/FittingRoomDownloadControlPane.md`
- `by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md`
- `by-memory/0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/routing decisions:

- [UID:000151] `FieldMapRequestHelper`: `78/88 -> 85/90`; range/path corrected from `0x004b11a0-0x004b1241` to half-open `0x004b11a0-0x004b1242`; `CANONICAL_OWNER:0000JA` and `EMITTER_UIDS:0000JA` unchanged. C++ remains blank because packet-buffer helper names and final FieldMap entry/member names are not source-quality.
- [UID:0002IC] `HierListInsertBefore`: `78/88 -> 85/90`; `CANONICAL_OWNER:000065` and `EMITTER_UIDS:000065` unchanged. C++ remains blank because overload/API shape and parameter names are not source-quality.
- [UID:0002ID] `HierListInsertAfter`: `78/88 -> 85/90`; `CANONICAL_OWNER:000065` and `EMITTER_UIDS:000065` unchanged. C++ remains blank because overload/API shape and parameter names are not source-quality.
- [UID:0002IN] `ImageLibConstructor`: `78/88 -> 85/90`; `CANONICAL_OWNER:00006E` and `EMITTER_UIDS:00006E` unchanged. C++ remains blank because the second constructor parameter, private field names, and the `ImageLib`/`ResourceLayoutTable` API split are unresolved.
- Support docs were changed only to update stale UID path annotations for [UID:000151] after the range rename; their scores/routing were unchanged.

IDA/local evidence:

- Live IDA MCP session `a003_objectlist_dispatch_20260615` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; health returned `ok`, imagebase `0x400000`, Hex-Rays ready.
- `FieldMapRequestHelper`: `lookup_funcs` confirmed `sub_4B11A0` size `0xa2`, `0x004b1241` still inside that function, and next function `sub_4B1242` size `0xb`; `analyze_function` confirmed three FieldMap xrefs, packet helper callees, opcode `0x3f`, `0x94`-stride selected entry flow, seven-byte send, request-flag write, and unique corrected-range signature.
- `HierListInsertBefore`: `lookup_funcs` confirmed `sub_4CE860` size `0x14d` and `0x004ce9ad` as non-function alignment; `analyze_function` confirmed four xrefs, allocation/copy/child-list/lookup/virtual-insert/free callees, 18 basic blocks, complexity 4, and unique range signature.
- `HierListInsertAfter`: `lookup_funcs` confirmed `sub_4CE9B0` size `0x14c` and `0x004ceafc` as non-function alignment; `analyze_function` confirmed the Layer caller xref, zeroed allocation/copy/child-list/default-append/lookup/virtual-insert/free callees, 18 basic blocks, complexity 4, and unique range signature.
- `ImageLibConstructor`: `lookup_funcs` confirmed `sub_4CFFB0` size `0xbf`, `0x004d006f` as non-function padding, and `sub_4D0070` as the successor destructor; `analyze_function` confirmed sole startup caller `sub_4639D0`, callees `sub_4F4A80`, `sub_4F4AA0`, `sub_4F3060`, singleton/vtable/list initialization behavior, and unique range signature.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-memory\0x004b11a0-0x004b1242.FieldMapRequestHelper.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; path update recorded from old `0x004b11a0-0x004b1241` path; completion/confidence updated to `85/90`; generated low-completion stats row removed for [UID:000151].
- `python .\tools\validator.py --mode file --file by-memory\0x004ce860-0x004ce9ad.HierListInsertBefore.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; completion/confidence updated to `85/90`; generated low-completion stats row removed for [UID:0002IC].
- `python .\tools\validator.py --mode file --file by-memory\0x004ce9b0-0x004ceafc.HierListInsertAfter.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; completion/confidence updated to `85/90`; generated low-completion stats row removed for [UID:0002ID].
- `python .\tools\validator.py --mode file --file by-memory\0x004cffb0-0x004d006f.ImageLibConstructor.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; completion/confidence updated to `85/90`; generated low-completion stats row removed for [UID:0002IN].
- `python .\tools\validator.py --mode file --file by-file\FieldMapPane.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-class\FieldMapPane.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-class\FittingRoomDownloadControlPane.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-memory\0x004b0bb0-0x004b129b.FieldMapPane.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-memory\0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- Follow-up checks confirmed `project-level/-auto-completion-stats.md` no longer contains `000151`, `0002IC`, `0002ID`, or `0002IN`.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows

Supervisor applied the exact [UID:000151], [UID:0002IC], [UID:0002ID], and [UID:0002IN] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A002 Goal 2 Field/HierList/ImageLib supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

Supervisor-owned rows/blockers:

- No `by-memory/-coverage-report.md` rows remain pending for this batch.
- Remaining blockers: FieldMap packet-buffer helper names and entry-field names; HierList source overload/API declaration shape and parameter names; ImageLib second constructor parameter, private field names, and ImageLib/ResourceLayoutTable source split.
- IDA DB changes: skipped. Evidence supported documentation score/routing updates and one docs filename/range repair, but no safe IDA rename/type change was necessary.

Leases used:

- `by-memory/0x004b11a0-0x004b1241.FieldMapRequestHelper.md` for the pre-rename target
- `by-memory/0x004b11a0-0x004b1242.FieldMapRequestHelper.md` after rename
- `by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md`
- `by-memory/0x004ce9b0-0x004ceafc.HierListInsertAfter.md`
- `by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md`
- `by-file/FieldMapPane.md`
- `by-class/FieldMapPane.md`
- `by-class/FittingRoomDownloadControlPane.md`
- `by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md`
- `by-memory/0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/routing decisions:

- [UID:00004K] `ErrorMessage`: `82/86 -> 85/88`; `CANONICAL_OWNER:0000J5` and `EMITTER_UIDS:0000J5` unchanged. C++ remains blank because constructor reachability and final declaration/member names are not source-quality.
- [UID:00004P] `ExceptionHandler`: `82/86 -> 86/89`; `CANONICAL_OWNER:0000J8` and `EMITTER_UIDS:0000J8` unchanged. Coverage row was stale at `76%` and is now synchronized to `86%`. C++ remains blank because helper names, field names, and source declarations are not source-quality.
- [UID:00004U] `FieldMapPane`: `82/86 -> 86/89`; `CANONICAL_OWNER:0000JA` and `EMITTER_UIDS:0000JA` unchanged. C++ remains blank because raw-helper reachability and final field/helper names are unresolved.
- [UID:00006J] `InputMan`: `82/86 -> 86/89`; `CANONICAL_OWNER:0000K6` and `EMITTER_UIDS:0000K6` unchanged. C++ remains blank because event-helper names, platform function-pointer globals, the raw `0x004e8cc0` stub, and final field names are unresolved.

IDA/local evidence:

- Live IDA MCP session `a003_objectlist_dispatch_20260615` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; health returned `ok`, imagebase `0x400000`, Hex-Rays ready.
- `ErrorMessage`: lookup reconfirmed `0x004a63e0` is not a function, `sub_4A6400` size `0xb`, `sub_4A6410` size `0x19`, `sub_4A6920` size `0x41`, and `sub_4A6A70` size `0x6`; xrefs confirm no raw-constructor refs, copy/destructor vtable anchors, raw constructor vtable store, base-vtable restore evidence, and unique raw constructor/helper signature.
- `ExceptionHandler`: lookup reconfirmed constructor/filter/report/helper/destructor sizes, raw ordinary destructor/reset body status, constructor caller `0x00463e3a`, filter callback pointer ref `0x004ab49e`, filter-to-report call `0x004ab858`, `g_pCrashTarget` lifecycle refs, crash-report helper graph, shared crash/ImageHlp strings, and unique class-span signature.
- `FieldMapPane`: lookup reconfirmed modeled method/helper sizes, `0x004b1130` raw no-function status, request-helper callers `0x004b0dfe`/`0x004b0ea7`/`0x004b0f0e`, constructor-only path-helper caller `0x004b0c0d`, vtable-backed render/mouse/key slots, component graph, and unique class-span signature.
- `InputMan`: lookup reconfirmed method/helper sizes, `0x004e8cc0` raw no-function status, corrected aggregate boundary, vtable lifecycle ties, interface island membership, IMM API behavior, and unique class-span signature.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-class\ErrorMessage.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; completion/confidence updated to `85/88`; generated low-score stats row removed for [UID:00004K].
- `python .\tools\validator.py --mode file --file by-class\ExceptionHandler.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; completion/confidence updated to `86/89`; generated low-score stats row removed for [UID:00004P].
- `python .\tools\validator.py --mode file --file by-class\FieldMapPane.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; completion/confidence updated to `86/89`; generated low-score stats row removed for [UID:00004U].
- `python .\tools\validator.py --mode file --file by-class\InputMan.md --apply --queue-timeout 300`: exited `0`, `ok: 1`; completion/confidence updated to `86/89`; generated low-score stats row removed for [UID:00006J].
- `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --queue-timeout 300`: exited `0`, `ok: 1`.
- Follow-up check confirmed `project-level/-auto-completion-stats.md` no longer contains `00004K`, `00004P`, `00004U`, or `00006J`.

Supervisor-owned rows/blockers:

- No `by-memory/-coverage-report.md` rows are needed. No by-memory docs were edited.
- Remaining blockers: `ErrorMessage` raw constructor remains non-modeled/no-xref; `ExceptionHandler` still lacks source-quality helper/field/declaration names; `FieldMapPane` raw rectangle helper remains non-modeled/no-ref; `InputMan` still needs event-helper naming, platform function-pointer typing, raw keyboard-layout stub handling, and final field names.
- IDA DB changes: skipped. Evidence supported documentation score/routing updates, but no safe rename/type change was necessary.

Leases used:

- `by-class/ErrorMessage.md`
- `by-class/ExceptionHandler.md`
- `by-class/FieldMapPane.md`
- `by-class/InputMan.md`
- `by-class/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## A002-goal2-terminal-user-input-thunks-memory-20260615-13

Changed files:

- Renamed `by-memory/0x0058dc01-0x0058dc16.TerminalPaneAdjustorThunks.md` -> `by-memory/0x0058dc01-0x0058dc17.TerminalPaneAdjustorThunks.md`
- `by-memory/0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks.md`
- `by-memory/0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks.md`
- `by-memory/0x005b7836-0x005b784c.QuitInputPaneDestructorThunks.md`
- `by-memory/-ignored.md`
- `by-class/TerminalPane.md`
- `by-file/TerminalPane.md`
- `by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md`
- `by-memory/0x0058d750-0x0058dc5b.DialDialog.md`
- `by-memory/0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- Validator updated generated/project files as part of file-mode validation; A002 did not directly edit generated/project-level files or manually edit `by-memory/-coverage-report.md`.

Score/routing decisions:

- [UID:0001JK] `TerminalPaneAdjustorThunks`: `80/85 -> 88/92`; range/path corrected from stale `0x0058dc01-0x0058dc16` to half-open `0x0058dc01-0x0058dc17`; `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, `RECONSTRUCTABLE:FALSE`, and blank final C++ remain unchanged.
- [UID:0001KH] `UserInfoDialogPaneAdjustorThunks`: `80/85 -> 88/91`; routing unchanged as ignored/non-emitting compiler destructor adjustor thunks.
- [UID:0001N6] `SharedInputPaneAdjustorThunks`: `80/85 -> 88/92`; routing unchanged as ignored/non-emitting shared input-pane compiler adjustor thunks.
- [UID:0001N7] `QuitInputPaneDestructorThunks`: `80/85 -> 88/92`; routing unchanged as ignored/non-emitting compiler destructor adjustor thunks.

IDA/local evidence:

- Live IDA MCP session `a003_objectlist_dispatch_20260615` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; health returned `ok`, imagebase `0x400000`, Hex-Rays ready.
- [UID:0001JK]: `lookup_funcs` reconfirmed `sub_58DC01` and `sub_58DC0C` as two exact `0xb` functions. This corrects the half-open end to `0x0058dc17`; `0x0058dc17` is not a function and the next modeled function starts at `0x0058dc20`. `disasm` shows `this` adjustments `0xa0`/`0xa4` and tail jumps to `0x0058dc60`; xrefs tie starts to vtable cells `0x0062da70`/`0x0062daa0`, those cells to `sub_58AF50`, and the target destructor to code refs `0x0058dc07`/`0x0058dc12` plus vtable cell `0x0062da10`. Range signature is unique: `81 E9 A0 00 00 00 E9 54 00 00 00 81 E9 A4 00 00 00 E9 49 00 00 00`.
- [UID:0001KH]: `lookup_funcs` reconfirmed `sub_59BC2D`/`sub_59BC38` as two exact `0xb` functions, `0x0059bc43-0x0059bc4f` as non-functions, and `sub_59BC50` as the next destructor function. `disasm` shows `this` adjustments `0xa0`/`0xa4` and tail jumps to `0x0059bc50`; xrefs tie starts to vtable cells `0x0062e688`/`0x0062e6b8`, those cells to the `0x00599cc0` aggregate at `0x00599d26`/`0x00599d30`, and the target destructor to code refs `0x0059bc33`/`0x0059bc3e` plus vtable cell `0x0062e628`. Exact two-thunk bytes were recorded, but the raw range signature was not globally unique.
- [UID:0001N6]: `lookup_funcs` reconfirmed `sub_5B77C8`/`sub_5B77D3` as two exact `0xb` functions and `0x005b77de` as the next modeled thunk. `disasm` shows `this` adjustments `0xa0`/`0xa4` and tail jumps to `0x005b7940`; xrefs report 23 vtable/data refs per thunk spanning `0x0062f97c` through `0x006307e4`, plus broad primary destructor-slot refs to `0x005b7940`. Range signature is unique: `81 E9 A0 00 00 00 E9 6D 01 00 00 81 E9 A4 00 00 00 E9 62 01 00 00`.
- [UID:0001N7]: `lookup_funcs` reconfirmed `sub_5B7836`/`sub_5B7841` as two exact `0xb` functions and `0x005b784c` as the next modeled thunk. `disasm` shows `this` adjustments `0xa0`/`0xa4` and tail jumps to `0x005b7b30`; xrefs tie starts to vtable cells `0x0062f0a4`/`0x0062f0d4`, those cells to `sub_5A94B0` and data refs `0x005adcff`/`0x005add09`, and the target destructor to code refs `0x005b783c`/`0x005b7847` plus vtable cell `0x0062f054`. Range signature is unique: `81 E9 A0 00 00 00 E9 EF 02 00 00 81 E9 A4 00 00 00 E9 E4 02 00 00`.
- `analyze_component` reports all eight assigned thunk entry points as two-instruction, complexity-1 bodies with no strings, no callees, and no internal call graph.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-memory\0x0058dc01-0x0058dc17.TerminalPaneAdjustorThunks.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; path update recorded from old `0x0058dc01-0x0058dc16` path; completion/confidence updated to `88/92`; generated low-score stats rows removed for [UID:0001JK].
- `python .\tools\validator.py --mode file --file by-memory\0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `88/91`; generated low-score stats rows removed for [UID:0001KH].
- `python .\tools\validator.py --mode file --file by-memory\0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `88/92`; generated low-score stats rows removed for [UID:0001N6].
- `python .\tools\validator.py --mode file --file by-memory\0x005b7836-0x005b784c.QuitInputPaneDestructorThunks.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `88/92`; generated low-score stats rows removed for [UID:0001N7].
- `python .\tools\validator.py --mode file --file by-memory\-ignored.md --apply --queue-timeout 240`: exited `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-class\TerminalPane.md --apply --queue-timeout 240`: exited `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-file\TerminalPane.md --apply --queue-timeout 240`: exited `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-memory\0x0058af50-0x0058c350.TerminalPaneAndSetup.md --apply --queue-timeout 240`: exited `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-memory\0x0058d750-0x0058dc5b.DialDialog.md --apply --queue-timeout 240`: exited `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-memory\0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor.md --apply --queue-timeout 240`: exited `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --queue-timeout 240`: exited `0`, dry-run/non-apply, `ok: 1`; shared report still needs supervisor row replacement because A002 did not apply coverage-report edits.
- Follow-up check confirmed `project-level/-auto-completion-stats.md` no longer contains `0001JK`, `0001KH`, `0001N6`, or `0001N7`.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

- Note: validator file-mode validation auto-updated [UID:0001JK]'s link path in `by-memory/-coverage-report.md`, and the supervisor later applied the stale `80%` row body replacements. A002 did not directly edit the shared report.
- Supervisor application: applied exact rows to `by-memory/-coverage-report.md` on 2026-06-15; validation command `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1` returned `ok: 1`. No A002 terminal/user-input thunk supervisor-owned rows remain pending.
- Placement context: replace [UID:0001JK] between [UID:0001JJ] `DialDialogAdjustorThunks` and the [UID:0000VN] `0x0058dc5b-0x0058dc60` padding row.
    - [UID:0001JK][0x0058dc01-0x0058dc17.TerminalPaneAdjustorThunks](by-memory/0x0058dc01-0x0058dc17.TerminalPaneAdjustorThunks.md) 0x0058dc01-0x0058dc17 | compiler adjustor thunks | TerminalPaneAdjustorThunks : ignored : 88% : very-strong : Compiler-generated TerminalPane secondary/tertiary destructor adjustor thunks. Live 2026-06-15 IDA MCP reconfirms two exact 0xb-byte bodies at `0x0058dc01`/`0x0058dc0c`, corrected half-open end `0x0058dc17`, `this` adjustments `0xa0`/`0xa4`, tail-jump target `0x0058dc60`, vtable refs `0x0062da70`/`0x0062daa0`, target refs at `0x0058dc07`/`0x0058dc12` plus `0x0062da10`, and a unique byte signature; source reconstruction should model normal TerminalPane inheritance/destructor declarations, not handwritten thunk functions.
- Placement context: replace [UID:0001KH] between [UID:0001KG] `UserInfoDialogPane` and the [UID:0000VN] `0x0059bc8b-0x0059bc90` padding row.
    - [UID:0001KH][0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks](by-memory/0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks.md) 0x0059bc2d-0x0059bc43 | compiler adjustor thunks | UserInfoDialogPaneAdjustorThunks : ignored : 88% : strong : Compiler-generated UserInfoDialogPane secondary/tertiary destructor adjustor thunks. Live 2026-06-15 IDA MCP reconfirms two exact 0xb-byte bodies at `0x0059bc2d`/`0x0059bc38`, non-function padding through `0x0059bc4f`, `this` adjustments `0xa0`/`0xa4`, tail-jump target `0x0059bc50`, vtable refs `0x0062e688`/`0x0062e6b8`, target refs at `0x0059bc33`/`0x0059bc3e` plus `0x0062e628`, and exact two-thunk bytes; source reconstruction should model normal UserInfoDialogPane inheritance/destructor declarations, not handwritten thunk functions.
- Placement context: replace [UID:0001N6] and [UID:0001N7] between [UID:0001N5] `UserPaneDoubleParamCallback` and [UID:0001N8] `SelectObjectWithKeyboardPaneAdjustorThunks`, preserving the intervening [UID:0000VN] `0x005b780a-0x005b7820` ignored row.
    - [UID:0001N6][0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks](by-memory/0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks.md) 0x005b77c8-0x005b77de | compiler adjustor thunks | SharedInputPaneAdjustorThunks : ignored : 88% : very-strong : Compiler-generated shared input-pane secondary/tertiary destructor adjustor thunks. Live 2026-06-15 IDA MCP reconfirms two exact 0xb-byte bodies at `0x005b77c8`/`0x005b77d3`, `0x005b77de` as the next modeled thunk, `this` adjustments `0xa0`/`0xa4`, tail-jump target `0x005b7940`, 23 vtable/data refs per thunk across the item/command/spell/target input-pane vtable family, broad primary destructor-slot refs to `0x005b7940`, and a unique byte signature; source reconstruction should model the shared input-pane inheritance/destructor declarations, not handwritten thunk functions.
    - [UID:0001N7][0x005b7836-0x005b784c.QuitInputPaneDestructorThunks](by-memory/0x005b7836-0x005b784c.QuitInputPaneDestructorThunks.md) 0x005b7836-0x005b784c | compiler adjustor thunks | QuitInputPaneDestructorThunks : ignored : 88% : very-strong : Compiler-generated QuitInputPane secondary/tertiary destructor adjustor thunks. Live 2026-06-15 IDA MCP reconfirms two exact 0xb-byte bodies at `0x005b7836`/`0x005b7841`, `0x005b784c` as the next modeled thunk, `this` adjustments `0xa0`/`0xa4`, tail-jump target `0x005b7b30`, vtable refs `0x0062f0a4`/`0x0062f0d4`, setup/data refs through `sub_5A94B0` and `0x005adcff`/`0x005add09`, target refs at `0x005b783c`/`0x005b7847` plus `0x0062f054`, and a unique byte signature; source reconstruction should model normal QuitInputPane inheritance/destructor declarations, not handwritten thunk functions.

Read-only/generated follow-up:

- `by-project-structure/proposed-source-tree.md` still has a stale prose reference to `0x0058dc01-0x0058dc16` in the Terminal/phone rationale. A002 did not edit this read-only planning file; suggested replacement is `0x0058dc01-0x0058dc17`.

Continuation/path-correction verification:

- On the resumed path-correction request for this same assignment, A002 rechecked [UID:0001JK] with live IDA MCP. `lookup_funcs` again reports `0x0058dc01` and `0x0058dc0c` as exact `0xb` functions, `0x0058dc16` as inside `sub_58DC0C`, `0x0058dc17` as not a function, and `0x0058dc20` as the next modeled function. `disasm 0x0058dc0c` again shows `sub ecx, 0A4h; jmp sub_58DC60`; `make_signature_for_range 0x0058dc01-0x0058dc17` remains unique.
- Revalidated the four target docs after the path correction: `by-memory\0x0058dc01-0x0058dc17.TerminalPaneAdjustorThunks.md`, `by-memory\0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks.md`, `by-memory\0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks.md`, and `by-memory\0x005b7836-0x005b784c.QuitInputPaneDestructorThunks.md`; all exited `0` with `ok: 1`. `by-memory\-coverage-report.md` dry-run validation also exited `0` with `ok: 1`.

Remaining blockers:

- No final C++ should be emitted for these compiler-generated thunks. Source-facing work belongs to the owning class/file/vtable and scalar destructor pages.
- [UID:0001KH] has exact live IDA body/ref evidence but the raw two-thunk byte signature is not globally unique by itself, so confidence was kept at `91` instead of matching the unique-signature pages at `92`.
- IDA DB changes: skipped. Evidence supported documentation score/routing updates and one docs filename/range repair, but no safe rename/type change was necessary in IDA.

Leases used:

- `by-memory/0x0058dc01-0x0058dc16.TerminalPaneAdjustorThunks.md` for the pre-rename target
- `by-memory/0x0058dc01-0x0058dc17.TerminalPaneAdjustorThunks.md` after rename
- `by-memory/0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks.md`
- `by-memory/0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks.md`
- `by-memory/0x005b7836-0x005b784c.QuitInputPaneDestructorThunks.md`
- `by-memory/-ignored.md`
- `by-class/TerminalPane.md`
- `by-file/TerminalPane.md`
- `by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md`
- `by-memory/0x0058d750-0x0058dc5b.DialDialog.md`
- `by-memory/0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## 2026-06-15 - A002-goal2-launcher-parser-memory-20260615-14

Changed files:

- `by-memory/0x0048f4d0-0x0048f6cb.StartupHostPortCommandLineParser.md`
- `by-memory/0x00490200-0x0049050a.LgInternetSessionLauncherParser.md`
- `by-memory/0x00490510-0x00490809.LauncherHostPortPayloadParser.md`
- `by-memory/0x00490810-0x00490b01.MihosoftLauncherParser.md`
- `project-level/-auto-completion-stats.md` was updated by validator file-mode validation.
- `tools/leaser/Agents/Agent-A002/notes.md`
- A002 did not directly edit `by-memory/-coverage-report.md`.

Score/routing decisions:

- [UID:0002BH] `StartupHostPortCommandLineParser`: `80/86 -> 85/88`; semantic owner/emitter route unchanged as `RegistryConfig`/[UID:0000N4], reconstructable, blank final C++ retained.
- [UID:0002BK] `LgInternetSessionLauncherParser`: `80/86 -> 85/88`; semantic owner/emitter route unchanged as `RegistryConfig`/[UID:0000N4], reconstructable, blank final C++ retained.
- [UID:0002BL] `LauncherHostPortPayloadParser`: `80/86 -> 85/88`; semantic owner/emitter route unchanged as `RegistryConfig`/[UID:0000N4], reconstructable, blank final C++ retained.
- [UID:0002BM] `MihosoftLauncherParser`: `80/86 -> 85/88`; semantic owner/emitter route unchanged as `RegistryConfig`/[UID:0000N4], reconstructable, blank final C++ retained.
- Validator normalized legacy parent metadata headers to current owner/emitter metadata syntax in the four target docs.

IDA/local evidence:

- Live IDA MCP session `a003_objectlist_dispatch_20260615` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; health returned `ok`, imagebase `0x400000`, Hex-Rays ready.
- `lookup_funcs` reconfirmed the four raw assigned entries/endpoints are not IDA-modeled functions: `0x0048f4d0`, `0x0048f6cb`, `0x00490200`, `0x0049050a`, `0x00490510`, `0x00490809`, `0x00490810`, and `0x00490b01`. Neighbor anchors remain `sub_48EED0`, `sub_48FCA0`, and `sub_490B10`.
- `xrefs_to` returned zero entry/successor xrefs for the raw starts and raw successor starts checked in this batch, preserving the unresolved launcher-dispatch caveat.
- [UID:0002BH] string/data refs reconfirmed `"IP"` at `0x00616970` from `0x0048f4ff`, `"PO"` at `0x00616978` from `0x0048f52f`, and the `Unitel Relay` lookup-failure format at `0x00616980` from `0x0048f65a`; full-range signature was unique.
- [UID:0002BK] string/data refs reconfirmed `/lgi` at `0x00616ec4` from `0x00490269`, `/lgi ` at `0x00616ed0` from `0x0049029a`, `chigamec.dll` at `0x00616f1c` from `0x004902b0`, `WaitForSessionParameter` at `0x00616f38` from `0x004902bb`, and the Channel i DLL error format at `0x00616f50` from `0x00490462`; full-range signature was unique.
- [UID:0002BL] string/data refs reconfirmed the CP949 host-input error format at `0x00617024` from `0x004907c0`; full-range signature was unique.
- [UID:0002BM] string/data refs reconfirmed `Mihosoft` at `0x00617048` from `0x004908e4`, general UTF-16 dedicated-client input-error text at `0x00617060` from `0x00490a50`, and the host-specific UTF-16 failure format at `0x006170b8` from `0x00490aaf`; full-range signature was unique.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-memory\0x0048f4d0-0x0048f6cb.StartupHostPortCommandLineParser.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `85/88`; generated low-score stats rows removed for [UID:0002BH].
- `python .\tools\validator.py --mode file --file by-memory\0x00490200-0x0049050a.LgInternetSessionLauncherParser.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `85/88`; generated low-score stats rows removed for [UID:0002BK].
- `python .\tools\validator.py --mode file --file by-memory\0x00490510-0x00490809.LauncherHostPortPayloadParser.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `85/88`; generated low-score stats rows removed for [UID:0002BL].
- `python .\tools\validator.py --mode file --file by-memory\0x00490810-0x00490b01.MihosoftLauncherParser.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `85/88`; generated low-score stats rows removed for [UID:0002BM].
- Follow-up check confirmed `project-level/-auto-completion-stats.md` no longer contains `0002BH`, `0002BK`, `0002BL`, or `0002BM`.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows retained for audit:

- Placement context: replace [UID:0002BH] between [UID:0002BG] `CommandLineArgumentCounter` and [UID:0002BI] `NetsgoStartupAuthenticationParser`.
    - [UID:0002BH][0x0048f4d0-0x0048f6cb.StartupHostPortCommandLineParser](by-memory/0x0048f4d0-0x0048f6cb.StartupHostPortCommandLineParser.md) 0x0048f4d0-0x0048f6cb | raw unmodeled function | StartupHostPortCommandLineParser : reconstructable : 85% : strong : Assigned to `RegistryConfig`; live 2026-06-15 IDA MCP reconfirms the raw unmodeled entry/end/successor, zero entry/successor xrefs, `IP`/`PO` marker refs, `Unitel Relay` lookup-failure format ref, DNS resolution path, endpoint/port/state writes, localized failure branches, exact padding from prior byte review, and a unique full-range byte signature; final C++ remains blank pending dispatcher, source-quality helper name, and startup-state field names.
- Placement context: replace [UID:0002BK] between [UID:0002BJ] `ThrunetStartupAuthFileParser` and [UID:0002BL] `LauncherHostPortPayloadParser`.
    - [UID:0002BK][0x00490200-0x0049050a.LgInternetSessionLauncherParser](by-memory/0x00490200-0x0049050a.LgInternetSessionLauncherParser.md) 0x00490200-0x0049050a | raw unmodeled function | LgInternetSessionLauncherParser : reconstructable : 85% : strong : Assigned to `RegistryConfig`; live 2026-06-15 IDA MCP reconfirms the raw unmodeled entry/end/successor, zero entry/successor xrefs, `/lgi` and `/lgi ` operand refs, `chigamec.dll`/`WaitForSessionParameter` dynamic session-loader refs, Channel i DLL error format ref, host/IP handling, session string and port/state writes, exact padding from prior byte review, and a unique full-range byte signature; final C++ remains blank pending dispatcher, source-quality session wrapper, and startup-state field names.
- Placement context: replace [UID:0002BL] between [UID:0002BK] `LgInternetSessionLauncherParser` and [UID:0002BM] `MihosoftLauncherParser`.
    - [UID:0002BL][0x00490510-0x00490809.LauncherHostPortPayloadParser](by-memory/0x00490510-0x00490809.LauncherHostPortPayloadParser.md) 0x00490510-0x00490809 | raw unmodeled function | LauncherHostPortPayloadParser : reconstructable : 85% : strong : Assigned to `RegistryConfig`; live 2026-06-15 IDA MCP reconfirms the raw unmodeled entry/end/successor, zero entry/successor xrefs, five-token launcher selector/host/port/payload parser behavior, numeric IPv4 and DNS host paths, success writes to endpoint/port/state and payload slots, CP949 host-input failure format ref, exact padding from prior byte review, and a unique full-range byte signature; final C++ remains blank pending dispatcher, source-quality helper/payload names, and startup-state field names.
- Placement context: replace [UID:0002BM] between [UID:0002BL] `LauncherHostPortPayloadParser` and [UID:0002BN] `ComBackedLauncherAuthenticationParser`.
    - [UID:0002BM][0x00490810-0x00490b01.MihosoftLauncherParser](by-memory/0x00490810-0x00490b01.MihosoftLauncherParser.md) 0x00490810-0x00490b01 | raw unmodeled function | MihosoftLauncherParser : reconstructable : 85% : strong : Assigned to `RegistryConfig`; live 2026-06-15 IDA MCP reconfirms the raw unmodeled entry/end, modeled successor `sub_490B10`, zero entry/successor xrefs, `Mihosoft` selector ref, general and host-specific UTF-16 dedicated-client failure refs, numeric IPv4 and DNS host paths, endpoint/port/state writes, exact padding from prior byte review, and a unique full-range byte signature; final C++ remains blank pending dispatcher, source-quality helper name, and startup-state field names.

Supervisor applied and validated the four replacement rows above on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A002 launcher/parser supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

Remaining blockers:

- No safe final C++ emission yet: dispatcher/mode selector recovery, source-quality helper/session wrapper names, startup-state field names, and payload-string consumer names remain unresolved.
- These raw entries remain unmodeled in IDA and have no recovered inbound dispatch/pointer xrefs.
- IDA DB changes: skipped. Evidence supported docs score/routing updates but no safe rename/type change was necessary.

Leases used:

- `by-memory/0x0048f4d0-0x0048f6cb.StartupHostPortCommandLineParser.md`
- `by-memory/0x00490200-0x0049050a.LgInternetSessionLauncherParser.md`
- `by-memory/0x00490510-0x00490809.LauncherHostPortPayloadParser.md`
- `by-memory/0x00490810-0x00490b01.MihosoftLauncherParser.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## 2026-06-15 - A002-goal2-folder-rect-help-memory-20260615-15

Changed files:

- `by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md`
- `by-memory/0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods.md`
- `by-memory/0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate.md`
- `by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md`
- `project-level/-auto-completion-stats.md` was updated by validator file-mode validation.
- `tools/leaser/Agents/Agent-A002/notes.md`
- A002 did not directly edit `by-memory/-coverage-report.md`.

Score/routing decisions:

- [UID:000155] `FolderTreePaneCore`: `80/86 -> 85/88`; semantic owner/emitter route unchanged as `FolderTreePane`/[UID:0000JG], reconstructable, blank final C++ retained.
- [UID:00022G] `RectBoundsPredicateAndCombinationMethods`: `80/86 -> 85/88`; semantic owner/emitter route unchanged as `RectBounds`/[UID:0000N2], reconstructable, blank final C++ retained.
- [UID:00022N] `HelpPaneFadeStateUpdate`: `80/86 -> 85/87`; semantic owner/emitter route unchanged as `HelpPanes`/[UID:0000JU], reconstructable, blank final C++ retained. Confidence kept below the other three targets because the raw body still has no external entry xref and its current full-range signature is not unique.
- [UID:00016S] `SimpleHelpPanes`: `80/86 -> 85/88`; semantic owner/emitter route unchanged as `HelpPanes`/[UID:0000JU], reconstructable, blank final C++ retained.

IDA/local evidence:

- Live IDA MCP session `a003_objectlist_dispatch_20260615` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; health returned `ok`, imagebase `0x400000`, Hex-Rays ready.
- [UID:000155]: `lookup_funcs` reconfirmed all documented modeled starts and `0x004b32c9` as the non-function exclusive end; current xrefs reconfirmed constructor call `0x004b178b`, selected-path call `0x004b197f`, selection helper callers `0x004b296a/0x004b2d70/0x004b2f2f`, vtable refs `0x0061a518/0x0061a58c/0x0061a5bc`, `TREEICON.EPF` refs at `0x004b1c51/0x004b1c89/0x004b2618`, internal call graph through folder expansion/selection, and unique full-range signature.
- [UID:00022G]: `lookup_funcs` reconfirmed modeled `sub_4B7670` and `sub_4B76D0`, raw unmodeled starts at `0x004b7690/0x004b7700/0x004b7780/0x004b7830`, non-function exclusive end `0x004b78c8`, and successor `sub_4B78D0`; current xrefs reconfirmed callers for the two modeled predicates and zero direct refs to the four raw starts; modeled helper component summary reports no callees/globals; full-range signature is unique.
- [UID:00022N]: `lookup_funcs` reconfirmed no function object at `0x004c6eb0` or `0x004c6f89`, with `sub_4C6F90` as successor; `xrefs_to 0x004c6eb0` remains empty; `xrefs_to 0x005446b0` reconfirmed this raw body's four `PaneSetMode` call sites at `0x004c6ed7/0x004c6ef0/0x004c6f4e/0x004c6f62`; full-range signature is not unique.
- [UID:00016S]: `lookup_funcs` reconfirmed all documented modeled starts through `0x004c7670` and successor `sub_4C7680`; current xrefs reconfirmed 18 direct calls to `SimpleHelpPane::SimpleHelpPane`, vtable/data refs for `SimpleHelpPane2` event methods at `0x0061acec/0x0061acbc/0x0061acc0`, singleton refs for `g_pSimpleHelpPane` and `g_pSimpleHelpPane2`, component shared vtables/timer/rectangle dependencies, and unique full-range signature.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-memory\0x004b1b90-0x004b32c9.FolderTreePaneCore.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `85/88`; generated low-score stats rows removed for [UID:000155].
- `python .\tools\validator.py --mode file --file by-memory\0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `85/88`; generated low-score stats rows removed for [UID:00022G].
- `python .\tools\validator.py --mode file --file by-memory\0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `85/87`; generated low-score stats rows removed for [UID:00022N].
- `python .\tools\validator.py --mode file --file by-memory\0x004c6f90-0x004c7680.SimpleHelpPanes.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `85/88`; generated low-score stats rows removed for [UID:00016S].
- Follow-up check confirmed `project-level/-auto-completion-stats.md` no longer contains `000155`, `00022G`, `00022N`, or `00016S`.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows retained for audit:

- Placement context: replace [UID:000155] between the [UID:0000VN] `0x004b1b87-0x004b1b90` padding row and [UID:000156] `FolderTreePaneSetSelection`.
    - [UID:000155][0x004b1b90-0x004b32c9.FolderTreePaneCore](by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md) 0x004b1b90-0x004b32c9 | class-method-cluster | FolderTreePaneCore : reconstructable : 85% : strong : Source-authored filesystem tree-control core. Live 2026-06-15 IDA MCP reconfirms exact modeled method starts, non-function exclusive end, constructor call from `FolderSelectDialog`, selected-path call, selection helper fan-in, three `FolderTreePane` vtable refs, `TREEICON.EPF` refs, directory expansion through `FindFirstFileA`/`FindNextFileA`, internal expansion/selection call graph, and a unique full-range byte signature; final C++ remains blank pending source-quality helper names, field names, and template/source factoring.
- Placement context: replace [UID:00022G] between the [UID:0000VN] `0x004b7661-0x004b7670` padding row and the internal RectBounds padding rows.
    - [UID:00022G][0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods.md) 0x004b7670-0x004b78c8 | class-method-cluster | RectBoundsPredicateAndCombinationMethods : reconstructable : 85% : strong : RectBounds empty/size/point/contain/intersect/union method cluster. Live 2026-06-15 IDA MCP reconfirms modeled starts at `0x004b7670` and `0x004b76d0`, raw helper-shaped starts at `0x004b7690`/`0x004b7700`/`0x004b7780`/`0x004b7830`, non-function exclusive end `0x004b78c8`, successor `sub_4B78D0`, direct callers for the two modeled predicates, zero direct xrefs for the raw starts, no callees/globals in modeled value-object helpers, and a unique full-range byte signature; final C++ remains blank pending original raw-helper names and exact declaration shape.
- Placement context: replace [UID:00022N] between the [UID:0000VN] `0x004c6ea9-0x004c6eb0` padding row and the [UID:0000VN] `0x004c6f89-0x004c6f90` padding row.
    - [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate](by-memory/0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate.md) 0x004c6eb0-0x004c6f89 | raw-function | HelpPaneFadeStateUpdate : reconstructable : 85% : strong : Raw help-pane fade/mode updater. Live 2026-06-15 IDA MCP reconfirms no function object at the raw start/end, no direct entry xrefs, successor `sub_4C6F90`, four `PaneSetMode` call-site refs at `0x004c6ed7`/`0x004c6ef0`/`0x004c6f4e`/`0x004c6f62`, constructor/paint-backed style fields, embedded child opacity propagation, HelpPanes parent, and non-unique full-range signature; final C++ remains blank pending live entry path, original helper name, and final field names.
- Placement context: replace [UID:00016S] between the [UID:0000VN] `0x004c6f89-0x004c6f90` padding row and [UID:00016T] `SimpleHelpPane2Factory`.
    - [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md) 0x004c6f90-0x004c7680 | class-method-cluster | SimpleHelpPanes : reconstructable : 85% : strong : `SimpleHelpPane` and `SimpleHelpPane2` constructors, ordinary teardown, paint/event methods, singleton writes, vtable-linked handlers, timer/anchor behavior, and padding boundaries under HelpPanes ownership. Live 2026-06-15 IDA MCP reconfirms all modeled method starts, successor `sub_4C7680`, 18 direct `SimpleHelpPane` constructor callers, `SimpleHelpPane2` event vtable/data refs, `g_pSimpleHelpPane` and `g_pSimpleHelpPane2` singleton writes/clears, component shared vtables/timer/rectangle dependencies, and a unique full-range byte signature; final C++ remains blank pending field names, event enum names, and final HelpPane/SimpleHelpPane2/factory source split.

Supervisor applied and validated the four replacement rows above on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A002 folder/rect/help supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

Remaining blockers:

- Final C++ remains blank for all four targets because source-quality field names, helper names, event enum names, template/source factoring, and final source split details are not yet complete.
- [UID:00022G] still has four unmodeled raw helper starts with no direct xrefs; behavior is well documented but original names are not recovered.
- [UID:00022N] still has no recovered live entry path and its current full-range signature is not unique.
- [UID:00016S] still lacks direct code xrefs for `SimpleHelpPane2::SimpleHelpPane2` and ordinary teardown, despite vtable/singleton/factory evidence supporting placement.
- IDA DB changes: skipped. Evidence supported documentation score/routing updates but no safe rename/type change was necessary.

Leases used:

- `by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md`
- `by-memory/0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods.md`
- `by-memory/0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate.md`
- `by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## 2026-06-15 - A002-goal2-icons-change-map-patch-memory-20260615-16

Changed files:

- `by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md`
- `by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md`
- `by-memory/0x00532530-0x0053272e.MapPaneSpatialIndex.md`
- `by-memory/0x005474f0-0x00547850.PatchPanePacketResponseHandler.md`
- `project-level/-auto-completion-stats.md` was updated by validator file-mode validation.
- `tools/leaser/Agents/Agent-A002/notes.md`
- A002 did not directly edit `by-memory/-coverage-report.md`.

Score/routing decisions:

- [UID:00022Q] `IconsPaneActionDispatchRawBody`: `80/86 -> 85/88`; owner/emitter unchanged as [UID:0000JZ] `IconsPane`, reconstructable, blank final C++ retained. The raw helper remains source-owned project code evidence but is not promoted to final source C++ because no live caller/address-taken use was recovered.
- [UID:00019Q] `OpenChangePasswordDialog`: `80/86 -> 85/88`; owner/emitter unchanged as [UID:0000L0] `MainMenuPane`, reconstructable, blank final C++ retained. Current IDA name remains misleading runtime-like metadata; behavior is the password-dialog allocation wrapper.
- [UID:0001D2] `MapPaneSpatialIndex`: `80/86 -> 85/88`; owner/emitter unchanged as [UID:0000M4] `ObjectList`, reconstructable, blank final C++ retained. `MapPaneSpatialIndex` remains a compatibility alias over ObjectList accessor methods.
- [UID:0001ER] `PatchPanePacketResponseHandler`: `80/86 -> 86/88`; owner/emitter unchanged as [UID:0000A9] `PatchPane`, reconstructable, blank final C++ retained. Score is slightly higher because live IDA reconfirmed a full vtable-backed packet handler body with packet semantics and unique signature.

IDA/local evidence:

- Live IDA MCP session `a003_objectlist_dispatch_20260615` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- [UID:00022Q]: `lookup_funcs` reconfirmed no function object at `0x004cf8e0`, `0x004cf8ff`, `0x004cf952`, `0x004cf954`, or `0x004cf974`; `disasm` showed the `dword_67A764 + 0x3f0` gate, `0..7` switch, local jump table at `0x004cf954`, eight dispatch targets `0x005a4db0`, `0x005a4e40`, `0x005a4f70`, `0x005a5010`, `0x005a50a0`, `0x005a5110`, `0x005a5340`, and `0x005a5a80`, zero entrypoint xrefs, only the local jump-table data reference, and a unique full-range signature.
- [UID:00019Q]: `lookup_funcs` reconfirmed `0x004f9060` size `0x54` and successor `sub_4F90C0` at `0x004f90c0`; `analyze_function` showed `sub_4F4AA0(620)` followed by `sub_4FDD40` on success; xrefs to the helper entry remain zero; xrefs to constructor `0x004fdd40` remain the active duplicate call at `0x004f7b49` plus this helper's call at `0x004f90a0`; full-range signature is unique.
- [UID:0001D2]: `lookup_funcs` reconfirmed all accessor starts from `0x00532530` through `0x005326d0`, non-function endpoint `0x0053272e`, and successor `sub_532730`; current xrefs show use from ObjectList/MapPane/FpsPane-adjacent paths such as `sub_5094B0`, `sub_50E850`, `sub_4B68B0`, `sub_5062F0`, `sub_50B2B0`, and `sub_50C470`; representative row-bucket decompilation reconfirmed `sub_4B7C50` padded bounds and row-table indexing; full-range signature is unique.
- [UID:0001ER]: `lookup_funcs` reconfirmed `sub_5474F0` size `0x360`, no function at `0x00547850`, and successor `sub_547860` at `0x00547860`; `xrefs_to 0x005474f0` reports the single vtable/data ref at `0x00621e3c`; decompilation reconfirmed `@`/`0x40` packet gating, subtype handling, `MultiByteToWideChar`, `wcscmp`, slice allocation/copy, progress updates, `0x00547b70` request continuation, `0x00547980` failure helper, vector callback refs `0x005483a0`/`0x00548410`, and a unique full-range signature.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-memory\0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `85/88`; generated low-score stats rows removed for [UID:00022Q].
- `python .\tools\validator.py --mode file --file by-memory\0x004f9060-0x004f90b4.OpenChangePasswordDialog.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `85/88`; generated low-score stats rows removed for [UID:00019Q].
- `python .\tools\validator.py --mode file --file by-memory\0x00532530-0x0053272e.MapPaneSpatialIndex.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `85/88`; generated low-score stats rows removed for [UID:0001D2].
- `python .\tools\validator.py --mode file --file by-memory\0x005474f0-0x00547850.PatchPanePacketResponseHandler.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `86/88`; generated low-score stats rows removed for [UID:0001ER].
- Follow-up check confirmed `project-level/-auto-completion-stats.md` no longer contains `00022Q`, `00019Q`, `0001D2`, or `0001ER`; `by-memory/-coverage-report.md` still contains stale 80% rows because A002 is banned from direct edits.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows retained for audit:

- Placement context: replace [UID:00022Q] between the [UID:0000VN] `0x004cf8d5-0x004cf8e0` padding row and the [UID:0000VN] `0x004cf974-0x004cf980` padding row.
    - [UID:00022Q][0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody](by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md) 0x004cf8e0-0x004cf974 | retained raw old-HUD action dispatcher | IconsPaneActionDispatchRawBody : reconstructable : 85% : strong : Retained raw eight-case old-HUD action dispatcher under IconsPane ownership. Live 2026-06-15 IDA MCP reconfirms no function object at the entry/table/end, raw `dword_67A764 + 0x3f0` gate, local switch table at `0x004cf954`, dispatch targets `0x005a4db0`/`0x005a4e40`/`0x005a4f70`/`0x005a5010`/`0x005a50a0`/`0x005a5110`/`0x005a5340`/`0x005a5a80`, zero entrypoint xrefs, only local jump-table data ref, matching IconsPane/TabPane downstream helper context, and a unique full-range signature; final C++ remains blank pending recovered caller/address-taken use or source-retention reason.
- Placement context: replace [UID:00019Q] between the [UID:0000VN] `0x004f9055-0x004f9060` padding row and the [UID:0000VN] `0x004f90b4-0x004f90c0` padding row.
    - [UID:00019Q][0x004f9060-0x004f90b4.OpenChangePasswordDialog](by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md) 0x004f9060-0x004f90b4 | retained duplicate launcher | OpenChangePasswordDialog : reconstructable : 85% : strong : Retained MainMenuPane password-dialog launcher with exact `0x54` / 84-byte body, misleading current IDA runtime-like name, allocator size `620`, constructor target `sub_4FDD40`, zero entrypoint xrefs, constructor xrefs from active duplicate menu path `0x004f7b49` and this helper `0x004f90a0`, successor boundary before `sub_4F90C0`, and a unique full-range signature; final C++ remains blank pending recovered caller/table or final source grouping.
- Placement context: replace [UID:0001D2] immediately after [UID:0001D3] `0x00532530-0x00532f67.ObjectListAccessorsAndSweeps` and before the [UID:0000VN] `0x00532f67-0x00532f70` padding row.
    - [UID:0001D2][0x00532530-0x0053272e.MapPaneSpatialIndex](by-memory/0x00532530-0x0053272e.MapPaneSpatialIndex.md) 0x00532530-0x0053272e | compatibility alias subset | MapPaneSpatialIndex : reconstructable : 85% : strong : Compatibility alias subset over ObjectList accessor methods with current 2026-06-15 live IDA-confirmed starts from `0x00532530` through `0x005326d0`, non-function endpoint `0x0053272e`, successor `sub_532730`, ObjectList/MapPane/FpsPane-adjacent caller fan-in, representative row-bucket decompilation through `sub_4B7C50` and row-table fields, parent ObjectListAccessorsAndSweeps relationship, and a unique full-range signature; final accessor names and alias cleanup remain unresolved.
- Placement context: replace [UID:0001ER] between the [UID:0000VN] `0x005474e6-0x005474f0` padding row and the [UID:0000VN] `0x00547850-0x00547860` padding row.
    - [UID:0001ER][0x005474f0-0x00547850.PatchPanePacketResponseHandler](by-memory/0x005474f0-0x00547850.PatchPanePacketResponseHandler.md) 0x005474f0-0x00547850 | virtual packet-response handler | PatchPanePacketResponseHandler : reconstructable : 86% : strong : PatchPane vtable-backed packet response handler with exact `0x360` / 864-byte body, single vtable/data ref at `0x00621e3c`, no direct code callers, `@`/`0x40` packet gate, subtype handling, bounded `MultiByteToWideChar`, `wcscmp` patch-name validation, slice allocation/copy, completion scan, progress update through `0x00494b50`, request continuation through `0x00547b70`, failure helper `0x00547980`, vector callback refs `0x005483a0`/`0x00548410`, successor boundary before `sub_547860`, and a unique full-range signature; final C++ remains blank pending source-quality field/helper/method names.

Shared-report status: supervisor applied and validated the four replacement rows above on 2026-06-15 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A002 icons/change/map/patch supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

Remaining blockers:

- [UID:00022Q] still lacks a recovered live caller/address-taken use and IDA still does not model it as a function.
- [UID:00019Q] remains a retained duplicate with no recovered caller/table; final grouping between MainMenuPane wrapper style and dialog-local helper style is unresolved.
- [UID:0001D2] still needs final source-facing ObjectList accessor names and cleanup/retention decision for the compatibility `MapPaneSpatialIndex` alias.
- [UID:0001ER] still needs source-quality PatchPane field names, helper names, and final method name before C++ emission.
- IDA DB changes: skipped. Evidence supported documentation score/routing updates but no safe rename/type change was necessary.

Leases used:

- `by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md`
- `by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md`
- `by-memory/0x00532530-0x0053272e.MapPaneSpatialIndex.md`
- `by-memory/0x005474f0-0x00547850.PatchPanePacketResponseHandler.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## 2026-06-15 - A002-goal2-patch-object-effect-memory-20260615-17

Changed files:

- `by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md`
- `by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md`
- `by-memory/0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers.md`
- `by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md`
- `project-level/-auto-completion-stats.md` was updated by validator file-mode validation.
- `tools/leaser/Agents/Agent-A002/notes.md`
- A002 did not directly edit `by-memory/-coverage-report.md`.

Score/routing decisions:

- [UID:0001EV] `PatchPane2MainLoop`: `80/86 -> 86/88`; owner/emitter unchanged as [UID:0000AA] `PatchPane2`, reconstructable, blank final C++ retained.
- [UID:0002R7] `PatchPane2AdvanceDownloadIndexRaw`: `80/86 -> 85/88`; owner/emitter unchanged as [UID:0000AA] `PatchPane2`, reconstructable, blank final C++ retained.
- [UID:0002BB] `ObjectListTypeSpecificEncodedKeyLookupHelpers`: `82/84 -> 85/88`; owner/emitter unchanged as [UID:0000M4] `ObjectList`, reconstructable, blank final C++ retained.
- [UID:0001D9] `EffectObjectPaneCore`: `82/84 -> 86/88`; owner/emitter unchanged as [UID:000049] `EffectObjectPane`, reconstructable, blank final C++ retained.

Wave2 workflow and IDA/local evidence:

- Used `wave2-method-analysis` skill. Ran `wave2.py method/decomp/xrefs` where records existed, plus `wave2.py struct` and `wave2.py filter --class ... --all-methods` for PatchPane2, ObjectList, and EffectObjectPane context.
- [UID:0001EV]: `wave2.py method 0x00548a80` reports `Method not found`; live IDA MCP `lookup_funcs` reconfirmed `sub_548A80` size `0x49a`, no function at `0x00548f1a/0x00548f1c`, successor `sub_548F30`, vtable/data xref at `0x00621fb8`, internal switch-table xref from `0x00548ad9` to `0x00548f1c`, no direct callers, `runas`/`patcher.exe` strings, PatchPane2 helper fan-in, and a unique full-range signature.
- [UID:0002R7]: Wave2 reports effective name/signature `PatchPane2::AdvancePatchStep()` with zero callers and callees `0x004f0350` and `0x00548f80`; `struct PatchPane2` confirms the vector/index/pass fields. Live IDA reconfirmed no function at `0x00549020` or `0x0054907f`, neighboring helpers `sub_548F80` and `sub_549080`, zero entry xrefs, outgoing `FinishAndExit` call at `0x00549079`, and a unique full-range signature.
- [UID:0002BB]: Wave2 has no individual method records for `0x00535df0`/`0x00535ec0`, but `struct ObjectList` confirms the 68-byte field layout. Live IDA reconfirmed all nine modeled starts, the `0x00536270` handoff, xrefs from both type-specific dispatch surfaces (`sub_5322D0` and raw switch helper around `0x00532450`), representative row-list/direct-list helper decompilation, and a unique full-range signature.
- [UID:0001D9]: Wave2 reports the constructor signature, caller `0x0050eacf`, callee `0x005372d0`, and sibling method set (`GetEffectBounds`, `GetFrameBounds`, `UpdateEffectAnimation`, `RenderEffect`, scalar deleting destructor). Live IDA reconfirmed every aggregate function boundary, constructor/timer callers, vtable/data refs, representative constructor/update/render behavior, `g_pEffectObjImageLib` users inside the range, and a unique full-range signature.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-memory\0x00548a80-0x00548f1a.PatchPane2MainLoop.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `86/88`; generated low-score stats rows removed for [UID:0001EV].
- `python .\tools\validator.py --mode file --file by-memory\0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `85/88`; generated low-score stats rows removed for [UID:0002R7].
- `python .\tools\validator.py --mode file --file by-memory\0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `85/88`; generated low-score stats rows removed for [UID:0002BB].
- `python .\tools\validator.py --mode file --file by-memory\0x005387b0-0x00538baa.EffectObjectPaneCore.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `86/88`; generated low-score stats rows removed for [UID:0001D9].
- Validator also reported unrelated stale registry warning: `autogen_registry_stale 00023W by-memory/0x0056c4a0-0x0056c4b5.GroupPaneFalseVirtualStubs.md registered file is missing`. A002 did not touch that active A003 target.
- Follow-up check before supervisor application confirmed `project-level/-auto-completion-stats.md` no longer contains `0001EV`, `0002R7`, `0002BB`, or `0001D9`. Supervisor applied and validated the four `by-memory/-coverage-report.md` replacement rows below on 2026-06-15 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A002 patch/object/effect supervisor-owned rows remain pending.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows retained for audit:

- Placement context: replace [UID:0002BB] under [UID:00023F] between [UID:0002BA] `ObjectListEncodedKeyAndRectHelpers` and [UID:0002BC] `ObjectListTierInsertRemoveHelpers`.
    - [UID:0002BB][0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers](by-memory/0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers.md) 0x00535df0-0x00536270 | helper-family | ObjectListTypeSpecificEncodedKeyLookupHelpers : reconstructable : 85% : strong : ObjectList type-specific encoded-key lookup helper family with nine live 2026-06-15 IDA-confirmed modeled functions, padding spans, ObjectList field offsets `+0x14/+0x18/+0x1c/+0x20/+0x24/+0x28/+0x2c/+0x30/+0x34`, packed row/global key forms, xrefs from both type dispatch surfaces (`sub_5322D0` and raw switch helper around `0x00532450`), representative row-list/direct-list decompilation, parent aggregate/adjacent child boundary agreement, Wave2 ObjectList layout support, and a unique full-range signature; final type/list names and source deduplication style remain provisional.
- Placement context: replace [UID:0001D9] between the [UID:0000VN] `0x005387a3-0x005387b0` padding row and its nested child rows beginning with [UID:0000VN] `0x0053887c-0x00538880`.
    - [UID:0001D9][0x005387b0-0x00538baa.EffectObjectPaneCore](by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md) 0x005387b0-0x00538baa | class-method aggregate | EffectObjectPaneCore : reconstructable : 86% : strong : EffectObjectPane core aggregate with live 2026-06-15 IDA-confirmed constructor/destructor/timer/bounds/update/render boundaries, child helper pages, MapPane constructor/timer callers, vtable/data refs, constructor/update/render behavior, `g_pEffectObjImageLib` usage, Wave2 constructor/sibling method support, touched state and padding evidence, and a unique full-range signature; final C++ remains blank pending frame descriptor field names, timer-subobject naming, render-context ownership, and final source-module split.
- Placement context: replace [UID:0001EV] between the [UID:0000VN] `0x00548a7d-0x00548a80` padding row and the [UID:0000VN] `0x00548f1a-0x00548f30` generated-data row.
    - [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md) 0x00548a80-0x00548f1a | virtual work-event handler | PatchPane2MainLoop : reconstructable : 86% : strong : PatchPane2 work-thread main loop with exact live 2026-06-15 IDA-confirmed `0x49a` function body, vtable/data ref at `0x00621fb8`, internal switch-table ref to `0x00548f1c`, no direct callers, `runas`/`patcher.exe` strings, subtype file-open/write/close/rename/launch/error behavior, helper fan-in to `FinishAndExit`/`SendDownloadRequest`/`ReportWriteError`, Wave2 method-record omission context, and a unique full-range signature; final C++ remains blank pending source-quality event/helper names and final PatchPane2 source split.
- Placement context: replace [UID:0002R7] between the [UID:0000VN] `0x0054901f-0x00549020` padding row and [UID:0001EX] `PatchPane2CloseAndRenameDownloadedFile`.
    - [UID:0002R7][0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw](by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md) 0x00549020-0x00549080 | raw helper body | PatchPane2AdvanceDownloadIndexRaw : reconstructable : 85% : strong : Raw PatchPane2 advance helper with live 2026-06-15 IDA-confirmed non-function status at `0x00549020`, neighboring modeled helpers `sub_548F80` and `sub_549080`, zero entry xrefs, vector current-index/pass-counter logic, outgoing localized language id `157` lookup and `FinishAndExit` call, Wave2 effective `PatchPane2::AdvancePatchStep()` name/signature support, PatchPane2 layout field support, and a unique full-range signature; final C++ remains blank pending recovered reachability and original helper emission/name.

Remaining blockers:

- [UID:0001EV] has no Wave2 method record and still needs source-quality work-event/helper names and final PatchPane2 source split before C++ emission.
- [UID:0002R7] still has no recovered IDA entry xref and is not an IDA function, despite Wave2 naming support and unique raw body bytes.
- [UID:0002BB] still needs final ObjectList type/list names and original source deduplication style.
- [UID:0001D9] still needs final frame descriptor field names, timer-subobject naming, render-context ownership, and source-module split.
- IDA DB changes: skipped. Evidence supported documentation score/routing updates but no safe rename/type change was necessary.

Leases used:

- `by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md`
- `by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md`
- `by-memory/0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers.md`
- `by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## 2026-06-15 - A002-goal2-chatting-handle-clan-memory-20260615-18

Changed files:

- `by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md`
- `by-memory/0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md`
- `by-memory/0x00482300-0x0048230a.ChattingHandlePaneRefreshForwarder.md`
- `by-memory/0x00485cc0-0x0048632e.ClanNameActionPacketHelpers.md`
- `project-level/-auto-completion-stats.md` was updated by validator file-mode validation.
- `tools/leaser/Agents/Agent-A002/notes.md`
- A002 did not directly edit `by-memory/-coverage-report.md`.

Score/routing decisions:

- [UID:0002FT] `ChattingHandlePaneOnMouseEvent`: `80/88 -> 86/90`; owner/emitter unchanged as [UID:00001V] `ChattingHandlePane`, reconstructable, blank final C++ retained.
- [UID:0002FU] `ChattingHandlePaneOnPaint`: `80/88 -> 86/90`; owner/emitter unchanged as [UID:00001V] `ChattingHandlePane`, reconstructable, blank final C++ retained.
- [UID:0002FV] `ChattingHandlePaneRefreshForwarder`: `80/88 -> 86/90`; `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and empty emitter list preserved as compiler-generated/non-emitting forwarder treatment.
- [UID:00021L] `ClanNameActionPacketHelpers`: `80/88 -> 85/89`; owner/emitter unchanged as [UID:0000I8] `Clan`, reconstructable, blank final C++ retained.

Wave2 workflow and IDA/local evidence:

- Used `wave2-method-analysis` skill. Ran `wave2.py method/decomp/xrefs` for `0x00481d60`, `0x00482150`, `0x00482300`, and `0x00485cc0`; ran `wave2.py struct ChattingHandlePane`, `wave2.py filter --class ChattingHandlePane --all-methods`, and attempted `Clan` class context. Wave2 has no `0x00485cc0` method/global record and no `Clan` class container, matching raw file-local Clan helper-strip treatment.
- [UID:0002FT]: Wave2 reports included `ChattingHandlePane::OnMouseEvent`, size `0x3ef`, with helper callees `0x00482400`, `0x004b7c50`, `0x004b7e80`, `0x0055c3a0`, `0x0055c3c0`, and `0x005a5110`. Live IDA reconfirmed `sub_481D60`, vtable data xref `0x00615010`, no ordinary code callers, `GetChatButtonAtPoint` call sites `0x00481dca`/`0x00481ec9`, and a unique wildcarded full-range signature.
- [UID:0002FU]: Wave2 reports included `ChattingHandlePane::OnPaint`, size `0x1a6`, effective name `OnPaint`, and the `CHATBUTT.EPF`/`CHATBUTT.PAL` draw pattern. Live IDA reconfirmed `sub_482150`, vtable data xref `0x00615000`, three draw regions, snapshot writes, and a unique wildcarded full-range signature.
- [UID:0002FV]: Wave2 reports `effective_included:false`, `Excluded_Override:true`, size `0x0a`, and the slot `+0x20` call on `this + 0x44`. Live IDA reconfirmed `sub_482300`, vtable data xref `0x00615004`, no code callers/callees, exact indirect-call body, and a non-unique 10-byte signature as expected for compiler forwarder glue.
- [UID:00021L]: Live IDA reconfirmed all raw helper starts are not function objects and have zero inbound xrefs; adjacent modeled helpers `sub_485AC0` and `sub_486330` are both size `0x1fe` and have live callers `sub_489FC0`/`sub_48A030`. Raw disassembly reconfirmed short helpers at `0x00485db0`, `0x00485f10`, `0x00486070`, and `0x004861d0`, string helpers at `0x00485cc0`, `0x00485e20`, `0x00485f80`, `0x004860e0`, and `0x00486240`, and a unique wildcarded full-range signature for `0x00485cc0-0x0048632e`.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-memory\0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `86/90`; generated low-score stats row removed for [UID:0002FT].
- `python .\tools\validator.py --mode file --file by-memory\0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `86/90`; generated low-score stats row removed for [UID:0002FU].
- `python .\tools\validator.py --mode file --file by-memory\0x00482300-0x0048230a.ChattingHandlePaneRefreshForwarder.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `86/90`; generated low-score stats row removed for [UID:0002FV].
- `python .\tools\validator.py --mode file --file by-memory\0x00485cc0-0x0048632e.ClanNameActionPacketHelpers.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `85/89`; generated low-score stats row removed for [UID:00021L].
- Follow-up check confirmed `project-level/-auto-completion-stats.md` no longer contains `0002FT`, `0002FU`, `0002FV`, or `00021L`. `by-memory/-coverage-report.md` still contains the old 80% rows and requires supervisor application of the replacement rows below.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows retained for audit:

Supervisor applied and validated the four replacement rows below on 2026-06-15 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A002 chatting-handle/clan-name supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

- Placement context: replace [UID:0002FT] between [UID:0000VN] `0x00481d59-0x00481d60` padding and [UID:0000VN] `0x0048214f-0x00482150` padding.
        - [UID:0002FT][0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent](by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md) 0x00481d60-0x0048214f | class method | ChattingHandlePaneOnMouseEvent : reconstructable : 86% : strong : ChattingHandlePane mouse dispatcher with current Wave2 included-method support, live IDA-confirmed `0x3ef` boundary, vtable data xref `0x00615010`, `GetChatButtonAtPoint` calls at `0x00481dca`/`0x00481ec9`, hover/press/release option-state handling, config writes, repaint snapshot comparison, helper hit-test confirmation, and a unique full-range signature; final C++ remains blank pending source-quality field and option names.
- Placement context: replace [UID:0002FU] between [UID:0000VN] `0x0048214f-0x00482150` padding and [UID:0000VN] `0x004822f6-0x00482300` padding.
        - [UID:0002FU][0x00482150-0x004822f6.ChattingHandlePaneOnPaint](by-memory/0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md) 0x00482150-0x004822f6 | class method | ChattingHandlePaneOnPaint : reconstructable : 86% : strong : ChattingHandlePane paint method with current Wave2 included-method support, live IDA-confirmed `0x1a6` boundary, vtable data xref `0x00615000`, `CHATBUTT.EPF`/`CHATBUTT.PAL` draw calls for the three visible handle regions, state-derived frame index logic, rendered-state snapshot writes, and a unique full-range signature; final C++ remains blank pending source-quality field and graphics helper names.
- Placement context: replace [UID:0002FV] between [UID:0000VN] `0x004822f6-0x00482300` padding and the following `0x0048230a-0x00482310` padding/rectangle-helper neighborhood.
        - [UID:0002FV][0x00482300-0x0048230a.ChattingHandlePaneRefreshForwarder](by-memory/0x00482300-0x0048230a.ChattingHandlePaneRefreshForwarder.md) 0x00482300-0x0048230a | tiny virtual forwarder | ChattingHandlePaneRefreshForwarder : ignored : 86% : strong : Compiler-generated secondary-subobject forwarder with current Wave2 `effective_included:false`/`Excluded_Override:true` support, live IDA-confirmed `0x0a` boundary, vtable data xref `0x00615004`, exact slot `+0x20` dispatch on `this + 0x44`, no code callers/callees, and expected non-unique tiny signature; keep non-emitting/ignored because source class/vtable layout should regenerate this glue.
- Placement context: replace [UID:00021L] between [UID:0000VN] `0x00485cbe-0x00485cc0` padding and [UID:00010F] `0x00486330-0x0048652d.SubmitClanChangeHelper`.
    - [UID:00021L][0x00485cc0-0x0048632e.ClanNameActionPacketHelpers](by-memory/0x00485cc0-0x0048632e.ClanNameActionPacketHelpers.md) 0x00485cc0-0x0048632e | packet helper cluster | ClanNameActionPacketHelpers : reconstructable : 85% : strong : Clan opcode `0x4b` raw helper strip with live IDA-confirmed no-function/no-xref status at all helper starts, adjacent modeled-helper boundaries at `sub_485AC0` and `sub_486330`, subtype `6` action `3` and subtype `7-10` action `0`/`1` short/string packet layouts, packet-buffer/send dependencies, mirrored dialog submitter context, Wave2 no-record context, and a unique full-range signature; final C++ remains blank because live reachability and duplicate-helper semantics remain unresolved.

Remaining blockers:

- [UID:0002FT] and [UID:0002FU] still need final source-quality field/option/resource helper names before C++ emission.
- [UID:0002FV] is intentionally non-emitting compiler glue; no handwritten NexusTK source body should be invented.
- [UID:00021L] still has no recovered live inbound xrefs to raw helper starts and needs final duplicate-helper semantics versus the later vtable-backed Clan name-dialog submitters.
- IDA DB changes: skipped. Evidence supported documentation score/routing updates but no safe rename/type change was necessary.

Leases used:

- `by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md`
- `by-memory/0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md`
- `by-memory/0x00482300-0x0048230a.ChattingHandlePaneRefreshForwarder.md`
- `by-memory/0x00485cc0-0x0048632e.ClanNameActionPacketHelpers.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## 2026-06-15 - A002-goal2-chatting-handle-clan-memory-20260615-18 source-quality continuation

Changed files:

- `by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md`
- `by-memory/0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md`
- `by-memory/0x00482300-0x0048230a.ChattingHandlePaneRefreshForwarder.md`
- `by-memory/0x00485cc0-0x0048632e.ClanNameActionPacketHelpers.md`
- `tools/leaser/Agents/Agent-A002/notes.md`
- A002 did not directly edit `by-memory/-coverage-report.md`.

Score/routing decisions:

- [UID:0002FT] `ChattingHandlePaneOnMouseEvent`: kept `86/90`; owner/emitter remain [UID:00001V] `ChattingHandlePane`; final C++ blank.
- [UID:0002FU] `ChattingHandlePaneOnPaint`: kept `86/90`; owner/emitter remain [UID:00001V] `ChattingHandlePane`; final C++ blank.
- [UID:0002FV] `ChattingHandlePaneRefreshForwarder`: kept `86/90`; `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, empty emitters retained; compiler-generated/non-emitting decision now closed for this memory page.
- [UID:00021L] `ClanNameActionPacketHelpers`: kept `85/89`; owner/emitter remain [UID:0000I8] `Clan`; final C++ blank.

Evidence checked and blocker outcomes:

- [UID:0002FT]/[UID:0002FU]: Wave2 struct still has only `mbr_0x...` generated field names; live IDA `analyze_function(0x00481c10/0x00481d60/0x00482150)` maps the field roles across constructor/mouse/paint: config offsets `g_pConfigData + 2678396/+2678400/+2678401`, full-object fields `+0x110..+0x124`, secondary-adjusted mouse-handler fields `+0x70..+0x84`, snapshot fields `+0x0f8..+0x10c`, and `sub_55C3A0/sub_55C3C0` secondary chat-widget enable/disable. This resolves roles but not final source names; generated names such as `m_btn1Hover`, `m_chatBubbleEnabled`, and `CONFIG_CHAT_*` conflict with persistence/widget-toggle evidence, so no safe Wave2/IDA rename or final C++ was entered.
- [UID:0002FU]: live IDA `analyze_function(0x00482150)` confirmed exact `CHATBUTT.EPF` frame-index formulae and snapshot writes. Helper roles are clear (`sub_4D02F0` loads an EPF frame, `sub_4B9980` draws with `CHATBUTT.PAL`), but existing generated helper names are owner-polluted and not safe final identifiers.
- [UID:0002FV]: live IDA `analyze_function(0x00482300, include_asm=true)` shows exactly `mov edx,[ecx]`, `lea eax,[ecx+44h]`, `push eax`, `call [edx+20h]`, `retn`; `xrefs_to(0x00482300)` has only vtable data xref `0x00615004`; `xrefs_to(0x00615004)` has zero refs. Local disabled simroot companion and generated metadata share the same `VFunc` alias pattern with other tiny forwarders (`0x004ee6d0`, `0x00551fa0`, `0x0056fdc0`, `0x0057eac0`). This supports compiler-generated ABI glue, not handwritten source.
- [UID:00021L]: live `lookup_funcs` reports every raw helper start `0x00485cc0`, `0x00485db0`, `0x00485e20`, `0x00485f10`, `0x00485f80`, `0x00486070`, `0x004860e0`, `0x004861d0`, and `0x00486240` is still not an IDA function. Live `xref_query(direction=to)` reports zero xrefs to all raw starts. Later modal submitters `0x00489180`, `0x004892b0`, `0x004893e0`, and `0x00489510` are modeled size-`0xee` functions with one vtable data xref each (`0x00615b34`, `0x00615bd4`, `0x00615c74`, `0x00615d14`); `decompile(0x00489180)` confirms the same subtype `7` action `1` name-packet shape as the raw duplicate; `analyze_component` confirms no internal calls and shared `dword_67A7EC`/packet helper use. A scoped `search_text` attempt for raw address/immediate forms timed out at the MCP worker's 60-second limit and yielded no usable evidence. Reachability and duplicate-helper semantics remain unresolved, so score stays conservative and final C++ remains blank.

B-agent handoff:

- Target [UID:0002FT]/[UID:0002FU]: determine final original-source field/config/helper names for `ChattingHandlePane` state. Evidence already checked: Wave2 method/decomp/xrefs and struct/filter for `ChattingHandlePane`; live IDA constructor/mouse/paint analysis; local generated history with conflicting `m_btn*`, `m_chat*`, and `CONFIG_CHAT_*` names; related `GetChatButtonAtPoint` and `ChatButtonRectHelperRaw` docs. Remaining inference: decide original names for persisted left toggle, three-state mode, secondary widget toggle, pressed latches, paint-state indices, snapshot fields, and EPF/palette helper calls using broader Chatting source-style patterns.
- Target [UID:00021L]: decide whether raw `0x00485cc0-0x0048632e` Clan helper strip is obsolete duplicate code, request/open companion helpers, or unrecovered raw-call targets. Evidence already checked: live no-function/no-xref results for all raw starts; adjacent `sub_485AC0`/`sub_486330` modeled helper boundaries; later name-dialog submitter vtable xrefs; representative `0x00489180` decompile matching raw subtype `7` action `1`; Wave2 no-record context; unique full-range signature. Remaining inference: inspect broader Clan row-action/dialog construction/source-layout evidence, raw pointer/immediate reference possibilities beyond IDA xrefs, and decide whether to keep as source-owned non-emitting/dead duplicate, split/merge, or leave as reconstructable Clan helper cluster.

Pending shared-file rows:

- None. Scores and coverage row text are unchanged, and the supervisor already applied the previous `by-memory/-coverage-report.md` rows for this batch.

## 2026-06-15 - A002-goal2-clan-attr-item-raw-constructors-20260615-20

Changed files:

- `by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md`
- `by-memory/0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md`
- `by-memory/0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor.md`
- `by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md`
- `by-class/ClanEnlistInputDialog.md`
- `by-class/ClanChangeInputDialog.md`
- `by-class/ClanLeaveConfirmDialog.md`
- `by-class/ClanItemDialog.md`
- `by-class/-coverage-report.md`
- `project-level/-auto-completion-stats.md` was updated by validator file-mode validation.
- `tools/leaser/Agents/Agent-A002/notes.md`
- A002 did not directly edit `by-memory/-coverage-report.md`.

Score/routing decisions:

- [UID:00021W] `ClanEnlistInputDialogRawConstructor`: `80/88 -> 85/90`; owner/emitter remains [UID:00002B] `ClanEnlistInputDialog`; reconstructable raw constructor, blank final C++ retained.
- [UID:0002O4] `ClanChangeInputDialogRawConstructor`: `80/88 -> 85/90`; owner/emitter remains [UID:000027] `ClanChangeInputDialog`; reconstructable raw constructor, blank final C++ retained.
- [UID:0002O6] `ClanLeaveConfirmDialogRawConstructor`: `80/88 -> 85/90`; owner/emitter remains [UID:00002I] `ClanLeaveConfirmDialog`; reconstructable raw constructor, blank final C++ retained.
- [UID:00021X] `ClanItemDialogRawConstructor`: `80/88 -> 85/90`; owner/emitter remains [UID:00002F] `ClanItemDialog`; reconstructable raw constructor, blank final C++ retained.
- [UID:00002B] `ClanEnlistInputDialog`: `82/88 -> 85/89`; owner/emitter remains [UID:0000I8] `Clan`; blank final C++ retained.
- [UID:000027] `ClanChangeInputDialog`: `82/88 -> 85/89`; owner/emitter remains [UID:0000I8] `Clan`; blank final C++ retained.
- [UID:00002I] `ClanLeaveConfirmDialog`: `82/88 -> 85/89`; owner/emitter remains [UID:0000I8] `Clan`; blank final C++ retained.
- [UID:00002F] `ClanItemDialog`: `82/88 -> 85/89`; owner/emitter remains [UID:0000I9] `ClanBank`; blank final C++ retained.
- Disposition remains reconstructable/raw constructor for all four memory pages. Reclassification was checked and rejected for now: Wave2 and IDA support constructor behavior and class ownership, but no direct live reachability was recovered.

Wave2 workflow and IDA/local evidence:

- Used `wave2-method-analysis` skill. Ran `wave2.py method`, `decomp`, and `xrefs` for `0x00489f80`, `0x00489ff0`, `0x0048a060`, and `0x0048a0c0`; ran `wave2.py filter --class ... --all-methods` and `wave2.py struct ...` for `ClanEnlistInputDialog`, `ClanChangeInputDialog`, `ClanLeaveConfirmDialog`, and `ClanItemDialog`.
- [UID:00021W]: Wave2 reports included `ClanEnlistInputDialog::ClanEnlistInputDialog(int dialogType)`, size `0x35`, zero callers, callee `0x00489600`, no data refs, grade `95.5`. Live IDA reports no function object at `0x00489f80`/`0x00489fb5`, zero xrefs to `0x00489f80`, exact bytes ending in `retn 4`, base call to `0x00489600`, and vtable stores to `0x00615df8`, `0x00615e5c`, and `0x00615e8c`. Vtable refs also tie the adjacent submitter slot at `0x00615e54` to `0x00489fc0`.
- [UID:0002O4]: Wave2 reports included `ClanChangeInputDialog::ClanChangeInputDialog(int dialogType)`, size `0x35`, zero callers, callee `0x00489600`, no data refs, grade `100`. Live IDA reports no function object at `0x00489ff0`/`0x0048a025`, zero xrefs to `0x00489ff0`, exact bytes ending in `retn 4`, base call to `0x00489600`, and vtable stores to `0x00615e98`, `0x00615efc`, and `0x00615f2c`. The adjacent submitter `0x0048a030` has the expected vtable ref at `0x00615ef4`.
- [UID:0002O6]: Wave2 reports included `ClanLeaveConfirmDialog` constructor, size `0x3e`, zero callers, callee `0x0049feb0`, no data refs, grade `93.5`. Live IDA reports no function object at `0x0048a060`/`0x0048a09e`, zero xrefs to `0x0048a060`, exact constructor bytes ending in `retn 10h`, `AlertPane` base call to `0x0049feb0`, vtable stores to `0x00615f38`, `0x00615fa0`, and `0x00615fd0`, and neighboring confirm/cancel callback slots at `0x0048a0a0`/`0x0048a0b0`.
- [UID:00021X]: Wave2 reports included `ClanItemDialog::ClanItemDialog()`, size `0x3b`, zero callers, callee `0x0049d8a0`, no data refs, grade `97.5`. Live IDA reports no function object at `0x0048a0c0`/`0x0048a0fb`, zero xrefs to `0x0048a0c0`, exact constructor bytes ending in `retn 4`, `DialogPane` base call to `0x0049d8a0`, vtable stores to `0x00615fdc`, `0x00616040`, and `0x00616070`, reset/destructor refs at `0x0048a100`, `0x0048c476`, `0x0048c47c`, and `0x0048c486`, and adjacent validation method separation at `0x0048a120`.
- Live IDA `find_bytes` found zero little-endian pointer-byte matches for `0x00489f80`, `0x00489ff0`, `0x0048a060`, and `0x0048a0c0`. A broader IDA `insn_query` immediate scan over `.text` timed out/truncated, so it was not treated as dispositive.
- Local read-only PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` parsed imagebase `0x400000` and `.text` VA `0x1000`, then checked VA bytes, RVA bytes, rel32 call/jmp/jcc targets, and rel8 branch targets for all four raw starts. It found zero VA/RVA pointer matches and zero relative branch/call hits for `0x00489f80`, `0x00489ff0`, `0x0048a060`, and `0x0048a0c0`.
- Wave2 `filter --class ClanEnlistInputDialog --all-methods` still includes stale `ParseClanAttributePacket`/`HideAllControls` ownership under that class, but current docs and IDA evidence route those helpers through `ClanStatusPane`/dispatcher context. That stale ownership is now documented as a caveat instead of promoted into final class ownership.

Validation commands/results:

- Initial full pass: `python .\tools\validator.py --mode file --file <each changed by-memory/by-class doc> --apply --queue-timeout 240` exited `0` for all eight changed by-* docs with `ok: 1`; it updated completions/confidences and removed generated low-score stats rows for the eight target/class UIDs. A follow-up filtered validation rerun captured `exit=0` and `ok: 1` for each file; the filtered rerun harmlessly repeated `by-memory\0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md` once.
- `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --queue-timeout 240`: exited `0`, `ok: 1`.
- Follow-up `rg` check confirmed `project-level/-auto-completion-stats.md` no longer contains `00021W`, `0002O4`, `0002O6`, `00021X`, `000027`, `00002B`, `00002F`, or `00002I`.

Shared-row status:

- `by-class/-coverage-report.md`: A002 leased, updated, and validated four rows for [UID:000027], [UID:00002B], [UID:00002F], and [UID:00002I].
- `by-memory/-coverage-report.md`: supervisor applied and validated the four replacement rows below on 2026-06-15 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A002 clan attr/item raw-constructor supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows retained for audit:

- Placement context: replace [UID:00021W] under/near `0x00489f80` after [UID:00010L] `ClanAttrInputDialogCore` and before adjacent padding/submitter rows.
    - [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md) 0x00489f80-0x00489fb5 | raw constructor | ClanEnlistInputDialogRawConstructor : reconstructable : 85% : very strong : A002 2026-06-15 refresh raises to 85/90 and refreshes parent [UID:00002B] to 85/89: Wave2 confirms an included zero-caller `ClanEnlistInputDialog` constructor record with base call `0x00489600`; live IDA reconfirms raw no-function start/end, zero raw-start xrefs, exact bytes, vtable stores, and submitter vtable neighbor; local PE scans find no VA/RVA pointer or relative branch/call target to `0x00489f80`; final C++ remains blank because live constructor reachability and source-quality constructor emission remain unresolved.
- Placement context: replace [UID:0002O4] inside/under [UID:00010M] `ClanEnlistChangeLeaveSubmitters` in address order.
        - [UID:0002O4][0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor](by-memory/0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md) 0x00489ff0-0x0048a025 | raw constructor | ClanChangeInputDialogRawConstructor : reconstructable : 85% : very strong : A002 2026-06-15 refresh raises to 85/90 and refreshes parent [UID:000027] to 85/89: Wave2 confirms an included zero-caller `ClanChangeInputDialog` constructor record with base call `0x00489600`; live IDA reconfirms raw no-function start/end, zero raw-start xrefs, exact bytes, vtable stores, and submitter vtable neighbor; local PE scans find no VA/RVA pointer or relative branch/call target to `0x00489ff0`; final C++ remains blank because live constructor reachability and source-quality constructor emission remain unresolved.
- Placement context: replace [UID:0002O6] inside/under [UID:00010M] `ClanEnlistChangeLeaveSubmitters` in address order before the confirm/cancel callback rows.
        - [UID:0002O6][0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor](by-memory/0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor.md) 0x0048a060-0x0048a09e | raw constructor | ClanLeaveConfirmDialogRawConstructor : reconstructable : 85% : very strong : A002 2026-06-15 refresh raises to 85/90 and refreshes parent [UID:00002I] to 85/89: Wave2 confirms an included zero-caller `ClanLeaveConfirmDialog` constructor record with `AlertPane` base call `0x0049feb0`; live IDA reconfirms raw no-function start/end, zero raw-start xrefs, exact constructor/callback bytes, vtable stores, and confirm/cancel vtable neighbors; local PE scans find no VA/RVA pointer or relative branch/call target to `0x0048a060`; final C++ remains blank because live constructor reachability and source-quality constructor emission remain unresolved.
- Placement context: replace [UID:00021X] after [UID:00010M] / padding `0x0048a0be-0x0048a0c0` and before [UID:00010N] `ClanItemDialogCore`.
    - [UID:00021X][0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor](by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md) 0x0048a0c0-0x0048a0fb | raw constructor | ClanItemDialogRawConstructor : reconstructable : 85% : very strong : A002 2026-06-15 refresh raises to 85/90 and refreshes parent [UID:00002F] to 85/89: Wave2 confirms an included zero-caller `ClanItemDialog` constructor record with `DialogPane` base call `0x0049d8a0`; live IDA reconfirms raw no-function start/end, zero raw-start xrefs, exact constructor bytes, vtable stores, reset/destructor sibling refs, and adjacent method separation; local PE scans find no VA/RVA pointer or relative branch/call target to `0x0048a0c0`; final C++ remains blank because live constructor reachability and source-quality constructor emission remain unresolved.

B-agent handoff:

- None opened. The remaining blocker is not an uninvestigated evidence gap from this pass; it is a source-quality/reachability gap after Wave2 zero-caller records, live IDA no-function/no-xref checks, pointer-byte checks, and local PE VA/RVA/relative-branch scans. If supervisor wants a separate B-agent thread, the narrow question is whether broader allocator/dialog-factory reconstruction can prove live construction of these four raw starts or justify dead/duplicate-code treatment.

Remaining blockers:

- All four constructor pages still lack direct IDA function objects, direct xrefs, raw-start pointer matches, or relative branch/call hits in the local PE scan.
- Original source constructor emission and exact source-facing constructor placement remain unresolved, so final C++ stays blank.
- No IDA DB changes were made. Evidence supported documentation score/routing updates but no safe rename/type change was necessary.

## 2026-06-16 - A002-goal2-lowconfidence-dialog-parser-20260615-22

Changed files:

- `by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md`
- `by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md`
- `by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md`
- `project-level/-auto-completion-stats.md` was updated by validator file-mode validation.
- `tools/leaser/Agents/Agent-A002/notes.md`
- A002 did not directly edit `by-memory/-coverage-report.md`.

Score/routing decisions:

- [UID:0001J7] `ForcedInformMessageDialogCore`: `82/84 -> 86/88`; owner/emitter remain [UID:0000JJ] `ForcedInformMessageDialog`; reconstructable remains true; final C++ blank.
- [UID:0001JC] `TerminalPaneStreamParser`: `82/84 -> 86/88`; owner/emitter remain [UID:0000OI] `TerminalPane`; reconstructable remains true; final C++ blank.
- [UID:0001JH] `DialDialogModemResponseParser`: `82/84 -> 86/88`; owner/emitter remain [UID:0000MJ] `PhoneBookDialog`; reconstructable remains true; final C++ blank.

Wave2 workflow and IDA/local evidence:

- Used `wave2-session-guide` and `wave2-method-analysis` instructions. Ran `wave2.py status --format json`, `missing-ref-classes --limit 10 --format json` (timed out after printing zero actionable missing targets), `get-next-classes 5`, and method/struct/filter/xref commands for `ForcedInformMessageDialog`, `TerminalPane`, and `DialDialog`.
- Wave2 confirms [UID:0001J7] constructor/method-family import for `ForcedInformMessageDialog`, but exposed helper names remain generated/owner-polluted. Wave2 `method/xrefs` for `0x0058b130` and `0x0058da20` returned no method/global record, and class filters omit both parser callbacks.
- Live IDA MCP session `c001_midiplayer_rdata_20260615` (`E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`) confirmed [UID:0001J7] function records: `0x00587bb0` size `0x4c3`, `0x00588080` size `0x81`, `0x00588110` size `0x4d`, `0x00588160` size `0x8d`, and no function at `0x005881ed`.
- [UID:0001J7] live `analyze_function` confirmed constructor vtable stores at `0x00587c28`/`0x00587c31`/`0x00587c3b`, singleton publish/clear through `unk_69B4A0`, EPF/EPD resources, text insertion, button IDs `14`/`22`, button handler slot `0x0062d760`, key handler slot `0x0062d780`, `A`/`D` accept/decline key handling, and secondary-subobject adjustment.
- [UID:0001JC] live `analyze_function 0x0058b130` confirmed size `0x31c`, no direct callers, data xref `0x0062da80`, packet buffer pointer/length fields at `a2 + 0x0c/+0x10`, parser state `this[115]` / full-object `+0x1cc`, terminal/telnet strings `%I\n</RunRegistry=`, `%c%c%c%c%c%c`, `dumb%c%c`, `%c%c%c`, and `baram`, plus modem/packet/close callees.
- [UID:0001JH] live `analyze_function 0x0058da20` confirmed size `0x175`, no direct callers, data xref `0x0062ddb4`, incoming buffer fields at `a3 + 0x0c/+0x10`, length cap `100`, callback-view state `this[147]`, CONNECT/BUSY byte recognizers, and full-dialog adjustment by `this - 0xa0` before slide/close calls.
- Live `entity_query 0x0062d714-0x0062df94` confirmed [UID:0001J7] vtable heads `0x0062d718`/`0x0062d778`/`0x0062d7a8`, [UID:0001JC] slot placement inside `TerminalPane` vtables at `0x0062da10`/`0x0062da70`/`0x0062daa0`, and [UID:0001JH] slot placement inside `DialDialog` vtables at `0x0062dd44`/`0x0062dda4`/`0x0062ddd4`.
- Live `make_signature_for_function` produced unique entry signatures: [UID:0001J7] `55 8B EC 6A FF 68 82 8F 60 00`, [UID:0001JC] `55 8B EC 6A FF 68 79 92 60 00`, and [UID:0001JH] `55 8B EC 51 8B 45 ? 56 57 8B F9`.

Validation commands/results:

- `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `86/88`; low-score stats rows removed for [UID:0001J7].
- `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0058b130-0x0058b44b.TerminalPaneStreamParser.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `86/88`; low-score stats rows removed for [UID:0001JC].
- `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0058da20-0x0058db94.DialDialogModemResponseParser.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `86/88`; low-score stats rows removed for [UID:0001JH].
- Follow-up filtered validation pass for all three changed target files exited `0` with `ok: 1` for each file.
- Follow-up `rg` check confirmed `project-level/-auto-completion-stats.md` no longer contains `0001J7`, `0001JC`, or `0001JH`.

Remaining blockers:

- [UID:0001J7] still has no direct constructor caller in live IDA. Helper/global names such as `sub_49DC10`, `sub_49DB60`, `sub_49EAC0`, `byte_66DA97`, and `unk_69AE08` remain behaviorally understood but not source-quality names.
- [UID:0001JC] still lacks a source-quality callback prototype, vtable-slot name, parser-state member name, and source-quality modem helper names for the `sub_574Cxx` family.
- [UID:0001JH] still lacks a source-quality callback prototype, vtable-slot name, parser-state member name, and final names for slide/close helpers `0x0049eb90`/`0x0049dad0`.
- IDA DB changes: skipped. Evidence supported documentation score/routing updates but no safe rename/type change was necessary.

Supervisor-applied supervisor-owned rows retained for audit:

- Supervisor applied and validated the three `by-memory/-coverage-report.md` replacement rows below on 2026-06-15 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A002 dialog/parser supervisor-owned rows remain pending.
- Placement context: replace [UID:0001J7] under [UID:0001J6] `SystemMessagePanes`, between the parent row and [UID:0001J8] `ForcedInformMessageDialogSingletonClear`.
    - [UID:0001J7][0x00587bb0-0x005881ed.ForcedInformMessageDialogCore](by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md) 0x00587bb0-0x005881ed | class-method cluster | ForcedInformMessageDialogCore : reconstructable : 86% : strong : A002 2026-06-16 refresh raises to 86/88 and keeps owner/emitter [UID:0000JJ]: live IDA reconfirms constructor/destructor/button/key function bounds, `0x005881ed` exclusive end, forced-inform vtable heads, constructor singleton/resource/text/button behavior, button/key vtable slots `0x0062d760`/`0x0062d780`, secondary key-handler adjustment, no direct constructor callers, and a unique entry signature; final C++ remains blank pending direct construction reachability and source-quality helper/global names.
- Placement context: replace [UID:0001JC] under [UID:0001JB] `TerminalPaneAndSetup`, between the parent row and [UID:0001JD] `TerminalPaneReconnectLeaveCallback`.
    - [UID:0001JC][0x0058b130-0x0058b44b.TerminalPaneStreamParser](by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md) 0x0058b130-0x0058b44b | vtable-backed parser callback | TerminalPaneStreamParser : reconstructable : 86% : strong : A002 2026-06-16 refresh raises to 86/88 and keeps owner/emitter [UID:0000OI]: live IDA reconfirms exact `0x31c` function boundary, single data/vtable xref `0x0062da80`, no direct callers, packet buffer pointer/length use, parser state at full-object `+0x1cc`, terminal/telnet string set including `%I\n</RunRegistry=`, `dumb%c%c`, and `baram`, modem/packet/close callees, TerminalPane vtable-island placement, Wave2 missing-method status, and a unique entry signature; final C++ remains blank pending source-quality callback prototype, slot name, parser-state member name, and modem helper names.
- Placement context: replace [UID:0001JH] under [UID:0001JG] `DialDialog`, between the parent row and the `0x0058dbe0-0x0058dbeb` ignored singleton-clear row.
    - [UID:0001JH][0x0058da20-0x0058db94.DialDialogModemResponseParser](by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md) 0x0058da20-0x0058db94 | vtable-backed parser callback | DialDialogModemResponseParser : reconstructable : 86% : strong : A002 2026-06-16 refresh raises to 86/88 and keeps owner/emitter [UID:0000MJ]: live IDA reconfirms exact `0x175` function boundary, single data/vtable xref `0x0062ddb4`, no direct callers, incoming buffer pointer/length use, length cap `100`, CONNECT/BUSY byte-state parser, callback-subobject adjustment back to the full dialog, slide/close callees, DialDialog vtable-island placement, Wave2 missing-method status, and a unique entry signature; final C++ remains blank pending source-quality callback prototype, slot name, parser-state member name, and helper names.

## 2026-06-16 - A002-goal2-lowboth-musiccontrol-helpers-20260615-23

Changed files:

- `by-memory/0x0052a1f0-0x0052a225.MusicControlDialogRefreshFolderPathControl.md`
- `by-memory/0x0052a230-0x0052a271.MusicControlDialogNextTrackHelper.md`
- `by-memory/0x0052a280-0x0052a2cb.MusicControlDialogPreviousTrackHelper.md`
- `project-level/-auto-completion-stats.md` was updated by validator file-mode validation.
- `tools/leaser/Agents/Agent-A002/notes.md`
- A002 did not directly edit `by-memory/-coverage-report.md`.

Score/routing decisions:

- [UID:0003MM] `MusicControlDialogRefreshFolderPathControl`: `82/85 -> 85/88`; owner/emitter remain [UID:00008U] `MusicControlDialog`; reconstructable remains true; final C++ blank.
- [UID:0003MN] `MusicControlDialogNextTrackHelper`: `82/85 -> 85/88`; owner/emitter remain [UID:00008U] `MusicControlDialog`; reconstructable remains true; final C++ blank.
- [UID:0003MO] `MusicControlDialogPreviousTrackHelper`: `82/85 -> 85/88`; owner/emitter remain [UID:00008U] `MusicControlDialog`; reconstructable remains true; final C++ blank.

IDA/local evidence and blocker outcomes:

- Used live IDA MCP session `c001_midiplayer_rdata_20260615` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; no Wave2/Wave3 source data was used.
- [UID:0003MM]: `lookup_funcs(0x0052a1f0)` still reports not a function; `insn_query` decodes exact `0x0052a1f0-0x0052a225` prologue/body/`retn 4`; `analyze_function(0x0058f2a0)` corrects `sub_58F2A0` to a TextEditPane selection-range helper, not local music scanning; `xref_query(to)` reports zero entry xrefs; `find_bytes` finds zero VA/RVA pointer hits; `make_signature_for_range` is unique.
- [UID:0003MN]: `lookup_funcs(0x0052a230)` still reports not a function; `insn_query` decodes exact `0x0052a230-0x0052a271` body; command-handler switch table maps control id `13` to inline case `0x005299c3`, not the raw start; raw body calls SoundManager stream/local next `0x0057a510` or Redbook advance `0x0057b240`, and tail-jumps to `TogglePauseState` at `0x0052a26a` when paused; zero entry xrefs, zero VA/RVA pointer hits, unique range signature.
- [UID:0003MO]: `lookup_funcs(0x0052a280)` still reports not a function; `insn_query` decodes exact `0x0052a280-0x0052a2cb` body; command-handler switch table maps control id `11` to inline case `0x00529a07`, not the raw start; raw body calls Redbook rewind `0x0057b2c0` or stream/local `PlayTrackByIndex(index - 1, 100, 1)` at `0x00579e30`, and tail-jumps to `TogglePauseState` at `0x0052a2c4` when paused; zero entry xrefs, zero VA/RVA pointer hits, unique range signature.
- Function-object/boundary status: none of the three raw helper starts has a recovered vtable/data slot, member-function pointer, direct call, switch-table target, VA pointer, or RVA pointer. Each has source-shaped code, unique bytes, and clean alignment boundaries inside the verified MusicControlDialog executable island.
- IDA DB changes: skipped. It would be byte-safe to define neutral function ranges/comments for `0x0052a1f0-0x0052a225`, `0x0052a230-0x0052a271`, and `0x0052a280-0x0052a2cb`, but A002 did not mutate IDA because project guidance says to avoid IDA-side changes and the source-quality helper names/entry paths remain provisional.

Validation commands/results:

- `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0052a1f0-0x0052a225.MusicControlDialogRefreshFolderPathControl.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `85/88`; low-score stats rows removed for [UID:0003MM].
- `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0052a230-0x0052a271.MusicControlDialogNextTrackHelper.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `85/88`; low-score stats rows removed for [UID:0003MN].
- `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0052a280-0x0052a2cb.MusicControlDialogPreviousTrackHelper.md --apply --queue-timeout 240`: exited `0`, `ok: 1`; completion/confidence updated to `85/88`; low-score stats rows removed for [UID:0003MO].
- Follow-up filtered validation pass for all three changed target files exited `0` with `ok: 1` for each file.
- Follow-up `rg` check confirmed `project-level/-auto-completion-stats.md` no longer contains `0003MM`, `0003MN`, or `0003MO`.

Remaining blockers:

- All three pages still lack a recovered entry path. This is not an uninvestigated blocker: direct xrefs, command-handler switch targets, vtable/function-object evidence, and VA/RVA pointer-byte hits were checked.
- [UID:0003MM] final source shape remains open between a private UI text-refresh helper, duplicate body, or unrecovered indirect callback; final source-quality helper/control names are still provisional.
- [UID:0003MN] and [UID:0003MO] final source shape remains open because the visible previous/next command cases are inline inside `HandleControlCommand`; the raw helper bodies mirror those cases but are not proven direct command targets.

Supervisor-applied supervisor-owned `by-memory/-coverage-report.md` replacement rows:

- Supervisor applied and validated the three `by-memory/-coverage-report.md` replacement rows below on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; no A002 MusicControl helper supervisor-owned rows remain pending.
- Placement context: replace [UID:0003MM], [UID:0003MN], and [UID:0003MO] under [UID:0001CP] `MusicControlDialog`, between [UID:0003ML] `MusicControlDialogTogglePauseState` and [UID:0003MP] `MusicControlDialogApplySoundEffectEnabled`.
        - [UID:0003MM][0x0052a1f0-0x0052a225.MusicControlDialogRefreshFolderPathControl](by-memory/0x0052a1f0-0x0052a225.MusicControlDialogRefreshFolderPathControl.md) 0x0052a1f0-0x0052a225 | raw helper body | MusicControlDialogRefreshFolderPathControl : reconstructable : 85% : strong : A002 2026-06-16 refresh raises to 85/88 and keeps owner/emitter [UID:00008U]: IDA-unpromoted MusicControlDialog control-id 6 text/control refresh body with exact prologue/retn4, corrected TextEditPane selection reset through `0x0058f2a0` instead of local music scan, zero entry xrefs, zero VA/RVA pointer hits, duplicate subset relationship to the folder-selected callback, unique range signature, and safe-but-skipped IDA function/comment candidate; final C++ remains blank pending recovered entry path/source shape and final helper/control names.
        - [UID:0003MN][0x0052a230-0x0052a271.MusicControlDialogNextTrackHelper](by-memory/0x0052a230-0x0052a271.MusicControlDialogNextTrackHelper.md) 0x0052a230-0x0052a271 | raw helper body | MusicControlDialogNextTrackHelper : reconstructable : 85% : strong : A002 2026-06-16 refresh raises to 85/88 and keeps owner/emitter [UID:00008U]: IDA-unpromoted next-track raw body with exact boundary, SoundManager stream/local next `0x0057a510` or Redbook advance `0x0057b240` dispatch, pause-tail jump to `0x0052a180`, command-handler control-id 13 inline duplicate at `0x005299c3` instead of direct raw-start wiring, zero entry xrefs, zero VA/RVA pointer hits, unique range signature, and safe-but-skipped IDA function/comment candidate; final C++ remains blank pending recovered entry path/source shape and final helper names.
        - [UID:0003MO][0x0052a280-0x0052a2cb.MusicControlDialogPreviousTrackHelper](by-memory/0x0052a280-0x0052a2cb.MusicControlDialogPreviousTrackHelper.md) 0x0052a280-0x0052a2cb | raw helper body | MusicControlDialogPreviousTrackHelper : reconstructable : 85% : strong : A002 2026-06-16 refresh raises to 85/88 and keeps owner/emitter [UID:00008U]: IDA-unpromoted previous-track raw body with exact boundary, Redbook rewind `0x0057b2c0` or stream/local `PlayTrackByIndex(index - 1, 100, 1)` dispatch through `0x00579e30`, pause-tail jump to `0x0052a180`, command-handler control-id 11 inline duplicate at `0x00529a07` instead of direct raw-start wiring, zero entry xrefs, zero VA/RVA pointer hits, unique range signature, and safe-but-skipped IDA function/comment candidate; final C++ remains blank pending recovered entry path/source shape and final helper names.

Leases used:

- `by-memory/0x0052a1f0-0x0052a225.MusicControlDialogRefreshFolderPathControl.md`
- `by-memory/0x0052a230-0x0052a271.MusicControlDialogNextTrackHelper.md`
- `by-memory/0x0052a280-0x0052a2cb.MusicControlDialogPreviousTrackHelper.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

## 2026-06-16 - A002-goal2-lowconfidence-dial-threadman-20260616-24

Changed files:

- `by-memory/0x0058d750-0x0058dc5b.DialDialog.md`
- `by-memory/0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md`
- `by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md`
- `by-memory/0x00597100-0x005971ad.ThreadManWorkerEntry.md`
- `by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md`
- `by-file/Socket.md`
- `by-file/Thread.md`
- `by-class/Socket.md`
- `by-class/Thread.md`
- `by-memory/0x005747e0-0x00574ad8.SocketLifecycle.md`
- `by-memory/0x00575d90-0x005797ae.SocketTransportCore.md`
- `by-memory/0x00577610-0x0057779e.SocketOpenSerialTransportRaw.md`
- `by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md`
- `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md`
- `project-level/-auto-completion-stats.md` was updated by validator file-mode validation.
- `by-memory/-coverage-report.md` was not directly edited by A002. Validator reference refresh changed the [UID:0001JZ] link target from the stale `SocketThreadEvent` path to `ThreadAddWaitHandleHelper`; supervisor applied and validated the score/text replacement rows plus the raw-cluster insert below on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/routing decisions:

- [UID:0001JG] `DialDialog`: `84/84 -> 86/88`; owner/emitter remain [UID:0000MJ] `PhoneBookDialog`; reconstructable remains true; final C++ blank.
- [UID:0001JZ] `ThreadAddWaitHandleHelper`: `86/84 -> 88/88`; owner/emitter remain [UID:0000OR] `Thread`; stale `SocketThreadEvent` path/name retired to historical alias only; final C++ blank.
- [UID:0001K1] `ThreadManRawMessageWrappers`: `86/84 -> 88/86`; owner/emitter remain [UID:0000OR] `Thread`; reconstructable raw helper island remains true; final C++ blank.
- [UID:0001K3] `ThreadManWorkerEntry`: `86/84 -> 88/87`; owner/emitter remain [UID:0000OR] `Thread`; reconstructable thread-entry callback remains true; final C++ blank.
- [UID:0001JY] `CashShopRequestWaitDispatch`, [UID:0001K4] `ThreadAndThreadMan`, Socket/Thread class/file docs, and Socket support memory pages were refreshed only as directly related support/evidence pages; their scores/routing were not intentionally changed.

IDA/local evidence and blocker outcomes:

- Used live IDA MCP session `c001_midiplayer_rdata_20260615` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; no Wave2/Wave3 source data was used.
- [UID:0001JG]: live IDA reconfirmed constructor `0x0058d750` size `0x293`, action `0x0058d9f0` size `0x2f`, parser `0x0058da20` size `0x175`, singleton cleanup `0x0058dbe0` size `0x0b`, DialDialog adjustors `0x0058dbeb`/`0x0058dbf6`, TerminalPane adjustor `0x0058dc01`, scalar destructor `0x0058dc20` size `0x3b`, and no function at `0x0058dc5b`; constructor has sole code caller `0x0058cc17` inside `0x0058cb60`; action/parser/destructor vtable slots resolve through `0x0062dd8c`, `0x0062ddb4`, and destructor refs; vtable writes at `0x0058d7a6`, `0x0058d7ae`, and `0x0058d7b8` target `0x0062dd44/0x0062dda4/0x0062ddd4`.
- [UID:0001JG]: action sends `"\r"` through `0x00574c40` and uses slide/close helpers `0x0049eb90` and `0x0049dad0`; parser reads packet fields at `a3+0x0c/+0x10`, caps length at `100`, uses callback-view state `this[147]`, recognizes CONNECT/BUSY, and adjusts `this - 40`; unique signatures recorded. Remaining blockers are exact source-quality field names, callback prototype/slot name, and slide/close/modem helper names.
- [UID:0001JZ]: live IDA reconfirmed modeled `sub_5967D0` size `0x15`, no callees, no function at padding boundaries `0x005967c7`/`0x005967e5`, exact bytes/padding, unique signature `55 8B EC 0F BE 51 ? 8B 45 ? 89 44 91 ? FE 41 ? 5D C2 04 00`, and no VA/RVA pointer-byte matches for `0x005967d0`.
- [UID:0001JZ]: `xref_query` reports exactly two code xrefs, `0x005764cc` inside modeled Socket transport setup `0x00576290` and raw Socket serial-open call `0x0057773f`; decompilation is the inherited Thread wait-handle append helper. This resolves owner to base `Thread`; Socket is a consumer, not owner. Remaining blockers are exact original member name and wait-count/array field spelling.
- [UID:0001K1]: live IDA reports raw starts `0x00596d20`, `0x00596d70`, `0x00596d90`, `0x00596db0`, `0x00596dd0`, and `0x00596df0` are not functions, with next modeled function at `0x00596e10`; `xref_query(to)` and VA/RVA pointer-byte scans found zero hits for all six starts. `insn_query 0x00596d13-0x00596e10` decodes the complete destructor/`PostThreadMessageW` wrapper island, including `TerminateThread`, `CloseHandle`, watch-list virtual delete, `g_pThreadMan` clear, `LObject` jump, wrapper ids `0x0464-0x0468`, vtable/global refs, `PostThreadMessageW` import `0x0060d378`, and a unique full-island signature.
- [UID:0001K1]: direct reachability remains a real blocker after no-function/no-xref/no-pointer checks, so the page is above gate but still conservative and final C++ stays blank pending raw-entry reachability and final wrapper names.
- [UID:0001K3]: live IDA reconfirmed `sub_597100` size `0xad`; no function starts at `0x005971ad` or `0x005971b0`; only incoming ref is constructor data xref `0x00596cb0`, matching the `CreateThread` entry pointer; normal path calls worker loop `0x00597140`.
- [UID:0001K3]: exception continuation uses virtual method `vtable+0x0c` to fill a wide buffer up to `0x800`, calls `MessageBoxW(0, Text, L"Error", 0)`, then app-exit helper `0x00464e40` and deleting cleanup flag `1`; UTF-16 `L"Error"` bytes are at `0x00612598`; unique signature `55 8B EC 6A FF 68 04 9B 60 00` recorded.
- [UID:0001K3]: boundary review found `0x005971ad-0x005971b0` padding followed by raw helper-shaped bytes at `0x005971b0`, `0x005971f0`, and `0x00597230` through the watch-list/dead-thread helper region; IDA reports zero xrefs and no VA/RVA pointer-byte hits for those candidate starts. Remaining blockers are exact exception/helper names and future split of neighboring raw helper cluster.
- IDA DB changes: skipped. Evidence supported documentation, stale path/name correction, and score/routing updates, but no safe IDA-side rename/type/comment/function promotion was necessary.

Validation commands/results:

- `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file <changed target/support doc> --apply --queue-timeout 240` was run for all 14 changed by-* docs listed above. Compact rerun on 2026-06-16 exited `0` with `ok: 1` for every file.
- Explicit compact rerun results: `DialDialog.md`, `ThreadAddWaitHandleHelper.md`, `ThreadManRawMessageWrappers.md`, `ThreadManWorkerEntry.md`, `ThreadDefaultNoOpVirtual.md`, `by-file/Socket.md`, `by-file/Thread.md`, `by-class/Socket.md`, `by-class/Thread.md`, `SocketLifecycle.md`, `SocketTransportCore.md`, `SocketOpenSerialTransportRaw.md`, `CashShopRequestWaitDispatch.md`, and `ThreadAndThreadMan.md` all reported `exit=0 ok=1`.
- Follow-up `rg` check confirmed `project-level/-auto-completion-stats.md` no longer contains `0001JG`, `0001JZ`, `0001K1`, or `0001K3`.
- Follow-up `rg` check on active docs found no remaining generated-link references to `0x005967d0-0x005967e5.SocketThreadEvent`; stale `SocketThreadEvent` wording remains only as historical alias/context where intentionally documented.

Leases used:

- `by-memory/0x0058d750-0x0058dc5b.DialDialog.md`
- `by-memory/0x005967d0-0x005967e5.SocketThreadEvent.md` before rename
- `by-memory/0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md` after rename
- `by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md`
- `by-memory/0x00597100-0x005971ad.ThreadManWorkerEntry.md`
- `by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md`
- `by-file/Socket.md`
- `by-file/Thread.md`
- `by-class/Socket.md`
- `by-class/Thread.md`
- `by-memory/0x005747e0-0x00574ad8.SocketLifecycle.md`
- `by-memory/0x00575d90-0x005797ae.SocketTransportCore.md`
- `by-memory/0x00577610-0x0057779e.SocketOpenSerialTransportRaw.md`
- `by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md`
- `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Supervisor-applied supervisor-owned `by-memory/-coverage-report.md` rows retained for audit:

- Placement context: replace [UID:0001JG] under [UID:0001JE] `PhoneBookDialogs`, after padding `0x0058d74c-0x0058d750` and before [UID:0001JH] `DialDialogModemResponseParser`.
    - [UID:0001JG][0x0058d750-0x0058dc5b.DialDialog](by-memory/0x0058d750-0x0058dc5b.DialDialog.md) 0x0058d750-0x0058dc5b | class-method cluster | DialDialog : reconstructable : 86% : strong : A002 2026-06-16 refresh raises to 86/88 and keeps owner/emitter [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md): live IDA reconfirms constructor/action/parser/destructor bounds, sole constructor caller, DialDialog vtable writes/slots, action/parser behavior, callback-subobject adjustment, TerminalPane thunk exclusion, and unique signatures; final C++ remains blank pending source-quality field names, parser callback prototype/slot name, and slide/close/modem helper names.
- Placement context: replace [UID:0001JZ] under [UID:0001JY] `ThreadMessageDispatchHelpers`, after [UID:0001JY] and before [UID:0001K0]. The path must be `by-memory/0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md`, not the stale `SocketThreadEvent` path.
    - [UID:0001JZ][0x005967d0-0x005967e5.ThreadAddWaitHandleHelper](by-memory/0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md) 0x005967d0-0x005967e5 | method | ThreadAddWaitHandleHelper : reconstructable : 88% : strong : A002 2026-06-16 refresh raises to 88/88 and retires stale SocketThreadEvent path/name: live IDA reconfirms exact 0x15 body, no callees, two Socket-side code xrefs as consumers only, exact bytes/padding, unique range signature, and no VA/RVA pointer-byte matches; owner/emitter remain [UID:0000OR][Thread](by-file/Thread.md); final C++ remains blank pending exact original member and wait-handle field spelling.
- Placement context: replace [UID:0001K1] under [UID:0001JY] `ThreadMessageDispatchHelpers`, after [UID:0001K0] and before [UID:0001K2].
    - [UID:0001K1][0x00596d20-0x00596e0b.ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md) 0x00596d20-0x00596e0b | raw helpers | ThreadManRawMessageWrappers : reconstructable : 88% : strong : A002 2026-06-16 refresh raises to 88/86 and keeps owner/emitter [UID:0000OR][Thread](by-file/Thread.md): live IDA reconfirms all raw starts are not functions, zero xrefs and zero VA/RVA pointer-byte hits for the entries, exact aligned destructor/PostThreadMessageW wrapper disassembly, ThreadMan vtable and g_pThreadMan refs, PostThreadMessageW import use, and unique full-island signature; final C++ remains blank because raw reachability and final wrapper names remain unresolved.
- Placement context: replace [UID:0001K3] under [UID:0001JY] `ThreadMessageDispatchHelpers`, after [UID:0001K2] and before [UID:0001K4].
    - [UID:0001K3][0x00597100-0x005971ad.ThreadManWorkerEntry](by-memory/0x00597100-0x005971ad.ThreadManWorkerEntry.md) 0x00597100-0x005971ad | thread entry callback | ThreadManWorkerEntry : reconstructable : 88% : strong : A002 2026-06-16 refresh raises to 88/87 and keeps owner/emitter [UID:0000OR][Thread](by-file/Thread.md): live IDA reconfirms exact 0xad CreateThread entry range, sole constructor data xref, worker-loop call, exception continuation through virtual formatter, MessageBoxW UTF-16 L"Error" title bytes, application-exit/deleting-cleanup path, unique entry signature, and corrected successor boundary before raw 0x005971b0-0x005974e0 helper bytes; final C++ remains blank pending exact exception syntax/helper names and neighboring raw-helper split.
- Placement context: insert after [UID:0001K3] and before [UID:0001K4] under [UID:0001JY] `ThreadMessageDispatchHelpers`.
    - 0x005971ad-0x005974e0 | raw ThreadMan/watch-list helper cluster : unknown : 25% : medium : A002 2026-06-16 support refresh found three-byte padding at 0x005971ad-0x005971b0 followed by raw helper-shaped ThreadMan/watch-list bytes at 0x005971b0, 0x005971f0, and 0x00597230 before modeled singleton clear 0x005974e0. IDA reports no function records, no xrefs to candidate starts, and no VA/RVA pointer-byte hits; needs an exact child page/split pass before final ThreadMan source migration.

Remaining blockers:

- [UID:0001JG]: exact source field names, parser callback prototype/slot name, and slide/close/modem helper names are still unresolved after constructor/caller/vtable/parser evidence review.
- [UID:0001JZ]: exact final original member spelling and inherited wait-count/wait-array field names remain unresolved; stale Socket ownership is resolved and should not be restored.
- [UID:0001K1]: raw wrapper entry reachability remains unresolved after no-function/no-xref/no-pointer-byte checks; final wrapper names remain provisional.
- [UID:0001K3]: exact exception syntax/helper names remain unresolved; raw successor helper cluster `0x005971ad-0x005974e0` needs a future split/child-page pass.

## 2026-06-16 - A002-goal2-lowconfidence-transfer-server-dialog-20260616-25

Changed files:

- `by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md`
- `by-file/TransferServerDialogPane.md`
- `by-class/TransferServerDialogPane.md`
- `by-memory/0x0062e480-0x0062e57c.TransferServerReadOnlyData.md`
- `by-item/TransferServerDialogPaneThunks_599220_5993e0.md`
- `by-file/-coverage-report.md`
- `by-class/-coverage-report.md`
- `by-item/-coverage-report.md`
- `project-level/-auto-completion-stats.md` was updated by validator file-mode validation.
- A002 did not directly edit `by-memory/-coverage-report.md`; supervisor applied and validated the exact replacement rows retained below.
- `tools/leaser/Agents/Agent-A002/notes.md`

Score/routing decisions:

- [UID:0001KD] `TransferServerDialogPane`: `86/84 -> 88/88`; owner/emitter remain [UID:0000OW] `TransferServerDialogPane`; reconstructable remains true; final C++ blank.
- [UID:0000OW] `TransferServerDialogPane` by-file page: `87/86 -> 88/88`; source root remains `NexusTK/ui/dialogs/`; `CANONICAL_OWNER:FILE` retained.
- [UID:0000F7] `TransferServerDialogPane` class page: `85/86 -> 87/88`; owner/emitter remain [UID:0000OW]; final C++ blank.
- [UID:00026R] `TransferServerReadOnlyData`: `84/88 -> 86/90`; owner/emitter remain [UID:0000OW]; reconstructable source-declared/generated-binary data with blank C++ retained.
- [UID:0000VJ] `TransferServerDialogPaneThunks_599220_5993e0`: `84/90 -> 86/91`; owner/emitter remain [UID:0000OW]; final C++ blank.
- `by-file/-coverage-report.md`, `by-class/-coverage-report.md`, and `by-item/-coverage-report.md` were leased, updated directly, and validated. `by-memory/-coverage-report.md` remains supervisor-owned.

IDA/local evidence and blocker outcomes:

- Used live IDA MCP session `c001_midiplayer_rdata_20260615` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; no Wave2/Wave3 source data was used.
- `server_health` reported `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, and strings cache ready.
- `lookup_funcs` reconfirmed all executable subranges and sizes: constructor `0x00598ed0` size `0x350`; non-deleting destructor/helper `0x00599220` size `0x29`; reset helper `0x00599250` size `0x12`; timer handler `0x00599270` size `0x79`; paint handler `0x005992f0` size `0xb6`; singleton clear helper `0x005993b0` size `0x0b`; adjustor thunks `0x005993bb` and `0x005993c6` size `0x0b`; scalar deleting destructor `0x005993e0` size `0x5f`.
- Boundary probes at `0x00598ecf`, `0x00599249`, `0x00599262`, `0x005992e9`, `0x005993a6`, `0x005993d1`, and `0x0059943f` are not function starts. `get_bytes` reconfirmed those gaps as `0xcc` padding.
- `analyze_component` and `entity_query` reconfirmed shared data: vtables at `0x0062e480`, `0x0062e4cc`, `0x0062e4fc`; `TRANSSVR.EPF` at `0x0062e504`; `TRANSSVR.EPD` at `0x0062e520`; `TRANSSVR.PAL` at `0x0062e53c`; `TRANSSVR.PAD` at `0x0062e558`; timer decrement constant bytes at `0x0062e574`; successor `UniAPIInit` boundary at `0x0062e57c`.
- `xref_query` reconfirmed nine constructor calls at `0x004f748b`, `0x004f8f7d`, `0x00507d63`, `0x00507dc5`, `0x0050ff65`, `0x0050ffce`, `0x0051012e`, `0x00510299`, and `0x005102fb`, collapsing to caller functions `0x004f6d80`, `0x004f8f10`, `0x00507c90`, `0x0050feb0`, and `0x00510230`.
- `xref_query` reconfirmed two reset-helper callers from `0x005aac80`, data-only timer/paint/adjustor/scalar-destructor reachability via vtable slots, one constructor-unwind code xref to `0x005993b0`, zero direct refs to `0x00599220`, and 20 direct refs to singleton slot `0x0069b4b0`.
- Constructor tail disassembly resolves the timer subobject to primary object offset `+0x0a4`: both timer schedule calls set `ecx = this + 0x0a4`, event `0` uses interval `0x64`, and optional event `1` uses interval `0x1388`. Timer event `1` subtracts `0x0a4` back to the primary pane before calling close/remove helper `0x00544690`.
- Timer disassembly resolves field roles: callback-relative fade/opacity at `-0x14`, current-frame at `+0x54`, and frame-count at `+0x58`, mapping to primary object offsets `+0x90`, `+0x0f8`, and `+0x0fc`. Roles are resolved; original source field names are not.
- `find_bytes` for VA/RVA pointer-byte forms found only expected vtable-table entries for timer, paint, adjustor thunks, and scalar deleting destructor. It found no VA/RVA pointer-byte hits for the constructor `0x00598ed0`, non-deleting helper `0x00599220`, reset helper `0x00599250`, or singleton clear helper `0x005993b0`.
- `get_bytes` over `.rdata` decoded the three vtable slices followed by UTF-16 `TRANSSVR.EPF`, `TRANSSVR.EPD`, `TRANSSVR.PAL`, `TRANSSVR.PAD`, then timer constant bytes before the `UniAPIInit` successor. Resource xrefs match constructor/paint use.
- Unique function signatures recorded include constructor `55 8B EC 6A FF 68 16 9C 60 00`, timer handler `55 8B EC 8B 45 ? 56 8B F1 83 E8 00 74 ? 83 E8 01 75 ? 8D 8E`, paint handler `55 8B EC 83 EC 3C A1 ? ? ? ? 33 C5 89 45 ? 56 57`, and scalar deleting destructor `55 8B EC 56 8B F1 C7 06 80 E4 62 00`.
- IDA DB changes: skipped. Evidence supported documentation score/evidence updates, but no safe IDA-side rename/type/comment/function promotion was necessary.

Validation commands/results:

- `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file <changed doc/report> --apply --queue-timeout 240` was run for all eight changed by-* docs/reports listed above.
- Compact validation results: every changed doc/report exited `0` with `ok: 1`.
- Follow-up `rg` check confirmed `project-level/-auto-completion-stats.md` no longer contains `0001KD`, `00026R`, `0000OW`, `0000F7`, or `0000VJ`.

Leases used:

- `by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md`
- `by-file/TransferServerDialogPane.md`
- `by-class/TransferServerDialogPane.md`
- `by-memory/0x0062e480-0x0062e57c.TransferServerReadOnlyData.md`
- `by-item/TransferServerDialogPaneThunks_599220_5993e0.md`
- `by-file/-coverage-report.md`
- `by-class/-coverage-report.md`
- `by-item/-coverage-report.md`
- `tools/leaser/Agents/Agent-A002/notes.md`

Supervisor-applied supervisor-owned `by-memory/-coverage-report.md` rows retained for audit:

- Supervisor applied and validated these two replacement rows on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A002 TransferServerDialogPane supervisor-owned rows remain pending.

- Placement context: replace [UID:0001KD] after padding row `0x00598ecf-0x00598ed0` and before padding row `0x0059943f-0x00599440` under the surrounding executable coverage section.
    - [UID:0001KD][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md) 0x00598ed0-0x0059943f | class/method cluster | TransferServerDialogPane : reconstructable : 88% : strong : A002 2026-06-16 refresh raises to 88/88 and keeps owner/emitter [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md): live IDA reconfirms every constructor/reset/timer/paint/destructor-helper boundary, all padding gaps, nine constructor call sites, two reset-helper callers, vtable-only timer/paint/thunk/destructor reachability, 20 singleton refs, timer subobject offset `+0x0a4`, primary field roles at `+0x90/+0x0f8/+0x0fc`, TRANSSVR resource bytes, and unique signatures; final C++ remains blank pending source-quality field/timer/helper names and destructor/thunk representation.
- Placement context: replace [UID:00026R] after [UID:00026Q] `TimerTotemReadOnlyData` and before [UID:00026S] `UniApiUrlAlertReadOnlyData` in the `.rdata`/read-only coverage region.
    - [UID:00026R][0x0062e480-0x0062e57c.TransferServerReadOnlyData](by-memory/0x0062e480-0x0062e57c.TransferServerReadOnlyData.md) 0x0062e480-0x0062e57c | vtable/string-data | TransferServerReadOnlyData : reconstructable : 86% : strong : A002 2026-06-16 support refresh raises to 86/90 and keeps owner/emitter [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md): live IDA reconfirms three TransferServerDialogPane vtable bases/slot bytes, constructor/destructor vtable writes, timer/paint/adjustor/scalar-destructor slot refs, UTF-16 `TRANSSVR.EPF`/`.EPD`/`.PAL`/`.PAD` bytes and constructor/paint xrefs, timer decrement constant at `0x0062e574`, and the `UniAPIInit` successor boundary; final C++ remains blank because this page is vtable/literal data emitted through the owning class/file declarations.

Remaining blockers:

- [UID:0001KD]/[UID:0000F7]: source-quality field names for fade/opacity, current frame, frame count, and the `+0x0a4` timer subobject remain unresolved after live disassembly resolved their offsets and roles.
- [UID:0001KD]/[UID:0000VJ]: final source representation for `0x00599220`, `0x005993b0`, adjustor thunks, and scalar deleting destructor remains unresolved. Evidence checked: direct xrefs, vtable data refs, constructor-unwind ref, hidden VA/RVA pointer-byte hits, decompilation, and padding; unresolved status is real and not a skipped search.
- [UID:0001KD]: base helper/source names such as base pane construction/teardown, update/attach, resource-load helpers, render callback, and close/remove helper remain behaviorally understood but not source-quality names, so final C++ remains blank.

## 2026-06-16 - A002-goal2-class-completion-clan-spell-20260616-26

Assignment targets:

- [UID:00002C] `by-class/ClanEnlistListPane.md` (`82/88` before).
- [UID:00002H] `by-class/ClanJoinListPane.md` (`82/88` before).
- [UID:00002R] `by-class/ClientSpellMenuDialog.md` (`82/88` before).

Leases acquired:

- `python tools\leaser\leaser.py Agent-A002 lease by-class\ClanEnlistListPane.md by-class\ClanJoinListPane.md by-class\ClientSpellMenuDialog.md tools\leaser\Agents\Agent-A002\notes.md`
- Result: all four files `Success`.
- `by-class/-coverage-report.md` was not edited at initial class-page edit time because Agent-A001 held an active lease until `2026-06-16T02:32:39Z`.

Live IDA MCP evidence checked:

- Session: `c001_midiplayer_rdata_20260615`, `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready.
- Clan lookup/function evidence: `sub_484030` size `0x1f2`, shared draw `0x004887d0` size `0xf1`, join action `0x004888d0` size `0x21`, join input `0x00488900` size `0x68`, enlist action `0x00488970` size `0x21`, enlist input `0x004889a0` size `0x19d`, join packet helper `0x00485590` size `0xf2`, subtype `6` helpers `0x00485960` size `0x69` and `0x004859d0` size `0xee`.
- Clan vtable/xref evidence: shared draw xrefs `0x0061572c`, `0x006157f0`, `0x006158b4`; join action `0x006157ec`; join input `0x006157d4`; enlist action `0x006158b0`; enlist input `0x00615898`; constructor primary vtable stores `0x0048416f -> 0x00615770` and `0x004841d5 -> 0x00615834`.
- Clan packet/callee evidence: `0x00485590` callers at `0x004888ea` and `0x00488951`; `0x004859d0` callers at `0x0048898a` and `0x00488b09`; `0x00485960` callers at `0x004876b6` and `0x00488aec`. Decompilation confirms join `{0x4b,2,1,len,payload}`, enlist `{0x4b,6,1,len,payload}`, and inline enlist key `0x84` path `{0x4b,6,3,len,payload}` followed by `0x00485960`.
- Clan padding checked: `0x004888c1-0x004888d0`, `0x004888f1-0x00488900`, `0x00488968-0x00488970`, `0x00488991-0x004889a0`, and `0x00488b3d-0x00488b40` are `0xcc` padding.
- Spell lookup/function evidence: `ClientSpellMenuDialog` constructor `0x0051db40` size `0x993`, `HandleMenuCommand` `0x0051e4e0` size `0x112`, `UpdateActionButtonState` `0x0051e600` size `0x3d`, `ClientSpellMenuItemList` constructor `0x0051e640` size `0x6c`, activation `0x0051e880` size `0x0b`, renderer `0x0051e890` size `0x108`, real `ChattingColorListPane` constructor `0x00482fb0` size `0x256`.
- Spell xrefs/vtables: constructor code refs `0x0051770b` and `0x00517c07`; `HandleMenuCommand` vtable-only ref `0x0061f310`; `UpdateActionButtonState` vtable-only ref `0x0061f314`; client dialog vtable stores `0x0051dba9 -> 0x0061f2c8`, `0x0051dbaf -> 0x0061f328`, `0x0051dbb9 -> 0x0061f358`; client list vtable stores `0x0051e68b -> 0x0061f364`, `0x0051e691 -> 0x0061f3ec`, `0x0051e69b -> 0x0061f41c`.
- Spell decompile evidence: constructor reads local-player/player-data pointer `dword_67A748`, calls `0x0051e640` twice, and populates spell rows from player-data offsets including `slotTerm + 0x13a834` and display text at `slotTerm + 0x13a83c`; command `1` reads child slot `6`, selected index `+0x134`, selected row through `0x004f3dc0`, then sends opcode `0x39` plus list offsets `+0x14c/+0x150/+0x154` and selected spell code; update helper fetches child slot `1` action button and slot `6` spell list, counts enabled entries through list storage `+0x108`, and tail-dispatches button enable/disable virtuals `+0x4c/+0x50`.
- Spell local-type blocker checked: xrefs to real `ChattingColorListPane` constructor `0x00482fb0` are only `0x00482837` and `0x0048295d` inside `sub_4824E0`; no spell-menu refs. `ClientSpellMenuItemList::DrawListItem` copies row display text from `entry + 4`, supporting spell row ownership over the stale generated chat-list local type.

Edits made so far:

- `by-class/ClanEnlistListPane.md`: raised to `86/90`; owner/emitter unchanged [UID:0000I8][Clan]; added current constructor/vtable/handler/packet/padding evidence and blocker investigation. Remaining blockers: final class declaration, common `ListPane` virtual names, source-facing helper names, and semantic meaning of event key `0x84`.
- `by-class/ClanJoinListPane.md`: raised to `86/90`; owner/emitter unchanged [UID:0000I8][Clan]; added current constructor/vtable/handler/packet/padding evidence and blocker investigation. Remaining blockers: final class declaration, common `ListPane` virtual names, selected-entry helper source name, and packet subtype/action enum names.
- `by-class/ClientSpellMenuDialog.md`: raised to `86/90`; owner/emitter unchanged [UID:0000O2][SpellMenuDialogs]; removed stale recovered-file reliance, added current dispatcher/vtable/list/player-data/packet/chat-negative evidence and blocker investigation. Remaining blockers: final row/action enum names, player spell-table field names, packet context field names, and final class declaration details.

IDA DB changes:

- None. No names/comments/types were applied; this was a read-only MCP evidence pass.

Supervisor-owned `by-memory/-coverage-report.md` rows:

- None for this batch. No by-memory docs were edited, and no memory coverage row change is required.

Final coverage/report edits:

- `by-class/-coverage-report.md` leased after C001's report lease expired.
- Replaced rows for [UID:00002C], [UID:00002H], and [UID:00002R] with `86% : very strong` summaries matching the target pages.
- `project-level/-auto-completion-stats.md` was updated by validator file-mode validation; `rg` confirmed target UIDs `00002C`, `00002H`, and `00002R` no longer appear there.

Validation commands/results:

- `python .\tools\validator.py --mode file --file by-class\ClanEnlistListPane.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-class\ClanJoinListPane.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-class\ClientSpellMenuDialog.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
- `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
- Validator normalized `g_packetSender` links in changed class pages to [UID:0001P0][0x0067a7ec-0x0067a7f0.g_packetSender](../../../by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md) and updated projected stats.

Final changed files for this batch:

- `by-class/ClanEnlistListPane.md`
- `by-class/ClanJoinListPane.md`
- `by-class/ClientSpellMenuDialog.md`
- `by-class/-coverage-report.md`
- `project-level/-auto-completion-stats.md` (validator-applied stats update)
- `tools/leaser/Agents/Agent-A002/notes.md`

## 2026-06-16 - A002-goal2-file-completion-encoder-framemgr-friendlist-20260616-29

Assignment targets:

- [UID:0000J1] `by-file/Encoder.md` (`85/86` before).
- [UID:0000JM] `by-file/FrameMgr.md` (`85/86` before).
- [UID:0000JN] `by-file/FriendListDialog.md` (`85/86` before).

Instructions:

- Read and follow `Agent-A002/goal.md`, current supervisor notes, lease rules, by-structure rules, validator requirements, and the temporary `by-memory/-coverage-report.md` edit ban.
- Improve documentation, completion, confidence, evidence quality, parent/support pages, and non-banned coverage reports where justified. These by-file targets are not done merely because they already meet 85/85; actively investigate remaining source-quality blockers before reporting completion.
- For every field/type/global/helper/protocol, ownership, source-placement, range/split, reachability, or final-C++ blocker mentioned in the final report, either resolve it, document exactly what evidence was checked and why it cannot currently be resolved safely, or keep/lower the score if it materially limits behavior, ownership, placement, or confidence.
- Do not directly edit `by-memory/-coverage-report.md`. If by-memory support rows need updates, record exact replacement/insert/delete text and placement context here for supervisor application.
- Report changed files, leases used, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA changes if any, and any exact pending supervisor-owned coverage rows.

Batch checkpoint:

- Changed files:
  - `by-file/Encoder.md`
  - `by-file/FrameMgr.md`
  - `by-file/FriendListDialog.md`
  - `by-class/FrameHandler.md`
  - `by-file/-coverage-report.md`
  - `project-level/-auto-completion-stats.md` was updated by validator file-mode validation.
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score/routing decisions:
  - [UID:0000J1] `Encoder`: `85/86 -> 86/88`; `CANONICAL_OWNER:FILE` unchanged; projected path remains `NexusTK/util/`.
  - [UID:0000JM] `FrameMgr`: `85/86 -> 86/88`; `CANONICAL_OWNER:FILE` unchanged; projected path remains `NexusTK/ui/core/`.
  - [UID:0000JN] `FriendListDialog`: `85/86 -> 86/88`; `CANONICAL_OWNER:FILE` unchanged; projected path remains `NexusTK/social/`.
  - Support [UID:00005G] `FrameHandler`: `84/90 -> 85/91`; owner/emitter remain [UID:0000JM] `FrameMgr`.
- Live IDA evidence checked:
  - Active MCP session `c001_midiplayer_rdata_20260615`, `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready.
  - `Encoder`: `lookup_funcs` reconfirmed constructor/destructor/writer/initialize/finalize/no-op/scalar-destructor starts and no function at `0x004a5621`; `xrefs_to` reconfirmed all behavioral writer calls are inside `EncodeTextEditState_0058E490`, vtable refs at `0x006192cc`, and vtable-only no-op reachability; decompilation checked constructor flags and finalize detach/NUL behavior; `get_bytes` reconfirmed `0x004a5621-0x004a5630` padding.
  - `FrameMgr`: `lookup_funcs` reconfirmed all `FrameHandler`/`FrameMgr` method starts and no function at `0x004b7112`; `xrefs_to` reconfirmed 13 `g_frameRegistry` refs, 6 `FrameHandler` vtable refs, and 3 `FrameMgr` vtable refs; decompilation checked next-frame/delayed-frame wrappers and dispatch behavior; component analysis reconfirmed LinkedList helper dependency; padding checked at `0x004b6caf` and `0x004b7112`.
  - `FriendListDialog`: `lookup_funcs` reconfirmed constructor/destructor/OK/focus/thunk/scalar-destructor starts and adjacent `ProfileDialog` start; `xrefs_to` reconfirmed constructor callers, vtable refs, sync helper callers, and sync flag refs; decompilation checked the two-column 20-slot config-backed layout and OK writeback/send path; UTF-16 bytes confirmed `Friend List`, `FRIEND.PAL`, `FRIEND.EPF`, `FRIEND.EPD`, and `NPAL8.PAL`; padding checked around every local split.
- Blocker outcomes:
  - `Encoder`: separate `NexusTK/util/Encoder.cpp` remains stronger than folding into `BinaryCodec.cpp`; only text-edit serializer calls writer methods; final original method/member names and no-op virtual declaration name remain unresolved after xref/vtable/decompile checks.
  - `FrameMgr`/`FrameHandler`: source placement remains `NexusTK/ui/core/FrameMgr.cpp`; broad wrapper callers reject feature ownership by ScreenPane/WorldMap/GroupList; final field names, callback-record type name, callback prototype, and every embedding-owner member name remain unresolved after xref/decompile/vtable checks.
  - `FriendListDialog`: `NexusTK/social/FriendListDialog.cpp` remains strongest; `ui/dialogs/` remains only an unproven folder alternative; `BuildAndSendFriendNameListSync` remains Socket-owned support after MapPane/raw/dialog caller and Socket queue evidence; final text-control field names, child-index constants, and DialogPane helper names remain unresolved.
- Validation commands/results:
  - `python .\tools\validator.py --mode file --file by-file\Encoder.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-file\FrameMgr.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-file\FriendListDialog.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-class\FrameHandler.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-file\-coverage-report.md --apply --queue-timeout 240`
  - The validation loop exited `0`; each command reported `ok: 1`. Follow-up `rg` confirmed `project-level/-auto-completion-stats.md` no longer lists `0000J1`, `0000JM`, `0000JN`, or `00005G`.
- Leases used:
  - `by-file/Encoder.md`
  - `by-file/FrameMgr.md`
  - `by-file/FriendListDialog.md`
  - `by-class/FrameHandler.md`
  - `by-file/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A002/notes.md`
- IDA DB changes: none. The evidence supported documentation/source-root updates but no safe IDA-side rename/type/comment edits.
- Supervisor-owned `by-memory/-coverage-report.md` pending rows: none. No by-memory docs were edited in this batch.

Supervisor-applied shared report updates for `by-class/-coverage-report.md`:

Supervisor applied and validated these rows on 2026-06-16 with `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --queue-timeout 240`; result `ok: 1`. No A002 pending class coverage rows remain for this batch.

- Placement context: replace [UID:00005G] between [UID:00005F] `FpsPane` and [UID:00005H] `FrameMgr`.
  - [UID:00005G][FrameHandler](by-class/FrameHandler.md) : reconstructable : 85% : very strong : A002 2026-06-16 support refresh reconfirms direct [UID:0000JM][FrameMgr](by-file/FrameMgr.md) source placement, exact destructor/schedule/remove/delayed-schedule/scalar-destructor boundaries, generic wrapper caller spread, FrameHandler vtable stores from scheduler destructors and embedding constructors, rejected Boost IDA label, `g_frameRegistry` forwarding behavior, and remaining method-spelling/callback-prototype/embedding-layout blockers.
- Placement context: replace [UID:00005J] between [UID:00005I] `FramePartPane` and [UID:00005K] `FunctionObject`. This row is stale from a prior batch and directly supports the refreshed [UID:0000JN] file target.
  - [UID:00005J][FriendListDialog](by-class/FriendListDialog.md) : reconstructable : 85% : very strong : Friend-list editor dialog class with live IDA-confirmed constructor, non-deleting destructor helper, OK handler, focus helper, adjustor thunks, scalar deleting destructor, three constructor callers, vtable refs, 20-slot config-backed editor layout, opcode `0x77` friend-name sync path through Socket-owned helper support, feature asset strings, and direct [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md) source parent.

## 2026-06-16 - A002-goal2-file-completion-general-inventory-itemobject-20260616-30

Assignment targets:

- [UID:0000JQ] `by-file/GeneralPurposePanel.md` (`85/86` before).
- [UID:0000KA] `by-file/InventoryPane.md` (`85/86` before).
- [UID:0000KG] `by-file/ItemObjectPane.md` (`85/86` before).

Instructions:

- Read and follow `Agent-A002/goal.md`, current supervisor notes, lease rules, by-structure rules, validator requirements, and the temporary `by-memory/-coverage-report.md` edit ban.
- Improve documentation, completion, confidence, evidence quality, parent/support pages, and non-banned coverage reports where justified. These by-file targets are not done merely because they already meet 85/85; actively investigate remaining source-quality blockers before reporting completion.
- For every field/type/global/helper/protocol, ownership, source-placement, range/split, reachability, or final-C++ blocker mentioned in the final report, either resolve it, document exactly what evidence was checked and why it cannot currently be resolved safely, or keep/lower the score if it materially limits behavior, ownership, placement, or confidence.
- Supervisor quick-peek classified these as routine file/source-root evidence targets rather than B-agent heavy heuristic ownership work. If live evidence reveals an ownership-unknown or broad inferential split problem that cannot be resolved in the normal A workflow, document the checked evidence and recommend B-agent escalation.
- Do not directly edit `by-memory/-coverage-report.md`. If by-memory support rows need updates, record exact replacement/insert/delete text and placement context here for supervisor application.
- Report changed files, leases used/release status, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA changes if any, and any exact pending supervisor-owned coverage rows.

Batch checkpoint:

- Changed files:
  - `by-file/GeneralPurposePanel.md`
  - `by-file/InventoryPane.md`
  - `by-file/ItemObjectPane.md`
  - `by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md`
  - `by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md`
  - `by-file/-coverage-report.md`
  - `project-level/-auto-completion-stats.md` was updated by validator file-mode validation.
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score/routing decisions:
  - [UID:0000JQ] `GeneralPurposePanel`: `85/86 -> 86/88`; `CANONICAL_OWNER:FILE` unchanged; projected path remains `NexusTK/ui/panels/`.
  - [UID:0000KA] `InventoryPane`: `85/86 -> 86/88`; `CANONICAL_OWNER:FILE` unchanged; projected path remains `NexusTK/ui/inventory/`.
  - [UID:0000KG] `ItemObjectPane`: `85/86 -> 86/88`; `CANONICAL_OWNER:FILE` unchanged; projected path remains `NexusTK/map/`.
  - Support [UID:00015W] `GeneralPurposePanelChildAccessors`: `84/90 -> 85/91`; owner/emitter remain [UID:00005Q] `GeneralPurposePanel`.
  - Support [UID:00015X] `GeneralPurposePanelSwitchActiveTab`: `84/90 -> 85/91`; owner/emitter remain [UID:00005Q] `GeneralPurposePanel`.
- Live IDA evidence checked:
  - Active MCP session `c001_midiplayer_rdata_20260615`, `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready.
  - `GeneralPurposePanel`: `lookup_funcs` reconfirmed constructor/destructor/accessor/switch/alternate-panel/singleton-clear starts from `0x004b83d0` through `0x004b8b40`; `xrefs_to` reconfirmed primary constructor callers at `0x004f7ff7/0x004f8835`, alternate constructor caller at `0x004f8020`, child lookup broad fan-in, active-child refs, `0x004b8650` 35-entry side-panel caller fan-in, one caller to `0x004b89a0`, singleton-clear cleanup refs, and vtable refs at `0x0061a888/0x0061a898`; decompilation reconfirmed child-array/active-index behavior, EPF/legacy tab limits, frame-refresh/InterfaceEfx dependencies, and no spell-input local state.
  - `InventoryPane`: `lookup_funcs` reconfirmed legacy, NewInventoryPane, InventoryPane2, ScrollInventoryPane, and destructor anchors; IDA still reports no function at `0x004ee650`, `0x004ef720`, `0x004ef7a0`, or `0x005646b0`; `xrefs_to 0x004ee650` and `0x005646b0` remain empty; bytes reconfirmed `0x004ee650-0x004ee6a7` constructor body and padding plus `0x005646b0-0x0056470c` reset-shaped bytes; vtable refs reconfirmed NewInventoryPane, InventoryPane2, and ScrollInventoryPane routes; `xrefs_to 0x00563260` remains the single `0x004eb4e4` NewInventoryPane constructor call.
  - `ItemObjectPane`: `lookup_funcs` reconfirmed every item/flying anchor and scalar destructor, `xrefs_to` reconfirmed MapPane construction/update callers at `0x00505e8f`, `0x00513665`, `0x0050e09b`, and `0x00512ebe`, data refs reconfirmed item/flying vtables and pool storage, decompilation reconfirmed `0x00537bc0` as ground-item record update and `0x00537f20` as flying-item tick/drop/removal behavior, and bytes reconfirmed padding before AttachedObjectPane.
- Blocker outcomes:
  - `GeneralPurposePanel`: stale `SpellOneArgInputPane` helper ownership for `0x004b85f0-0x004b8822` is resolved as generated-owner pollution. Remaining blockers are final public helper names, child-array/active-index member names, and source names for shared pane layout/show/totem cleanup helpers; frame-refresh and InterfaceEfx helper ownership stays external.
  - `InventoryPane`: raw constructor/reset starts and raw tail helpers remain real IDA function-table/caller blockers after lookup, xref, and byte checks. Current file/source decisions stay unchanged: legacy/alternate item inventory routes through [UID:0000KA], NewInventoryPane routes through [UID:0000LS], and ScrollInventoryPane routes through [UID:0000KB] with a possible private fold into NewInventoryPane.cpp. No B-agent escalation is indicated.
  - `ItemObjectPane`: no split/merge/range change is justified. Exact child pages, scalar destructor island, vtable data, pool data, and MapPane caller evidence still support [UID:0000KG] as the source root for both item-object companions. Remaining blockers are source-quality field/helper names for item state, motion/timer/drop helpers, and final method spellings.
- Validation commands/results:
  - `python .\tools\validator.py --mode file --file by-file\GeneralPurposePanel.md --apply --queue-timeout 240` -> `ok: 1`; first pass updated score and removed [UID:0000JQ] from project-level stats.
  - `python .\tools\validator.py --mode file --file by-file\InventoryPane.md --apply --queue-timeout 240` -> `ok: 1`; first pass updated score and removed [UID:0000KA] from project-level stats.
  - `python .\tools\validator.py --mode file --file by-file\ItemObjectPane.md --apply --queue-timeout 240` -> `ok: 1`; first pass updated score and removed [UID:0000KG] from project-level stats.
  - `python .\tools\validator.py --mode file --file by-memory\0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md --apply --queue-timeout 240` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md --apply --queue-timeout 240` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\-coverage-report.md --apply --queue-timeout 240` -> `ok: 1`.
  - Validator repeatedly reported pre-existing stale registry entries for missing [UID:00026H] and [UID:00026I]; unrelated to this batch.
- Leases used:
  - `by-file/GeneralPurposePanel.md`
  - `by-file/InventoryPane.md`
  - `by-file/ItemObjectPane.md`
  - `by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md`
  - `by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md`
  - `by-file/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A002/notes.md`
  - `by-file/-coverage-report.md` was initially leased by A001 and was updated after that lease cleared.
- IDA DB changes: none. The evidence supported documentation/source-root updates but no safe IDA-side rename/type/comment edits.
- Release status: no active A002 leases remain. The post-checkpoint unlease command reported A002 had no active leases on the edited files, and a follow-up `current_leases.md` read showed only A001/C001 leases.

Supervisor-applied supervisor-owned `by-memory/-coverage-report.md` rows retained for audit:

Supervisor applied the two rows below on 2026-06-16 and validated `by-memory/-coverage-report.md` with `ok:1`. The current report uses normalized range/type/name fields for both rows.

- Placement context: replace [UID:00015W] and [UID:00015X] after [UID:00015V] `0x004b83d0-0x004b8bd3.GeneralPurposePanel` and before [UID:00015Y] `0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild` in the executable coverage section.
    - [UID:00015W][0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md) 0x004b85f0-0x004b8643 | class-method-cluster | GeneralPurposePanelChildAccessors : reconstructable : 85% : very strong : A002 2026-06-16 support refresh raises to 85/91 and keeps owner/emitter [UID:00005Q][GeneralPurposePanel](by-class/GeneralPurposePanel.md): live IDA reconfirms the three child accessor helper sizes, EPF/legacy child-count logic, active index at `this[8]`, child-array reads at `this[index + 1]`, virtual refresh dispatch for the third helper, focused active-child caller refs, broad side-panel lookup fan-in, stale SpellOneArgInputPane generated ownership rejected, and remaining final member/virtual-name blockers.
    - [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md) 0x004b8650-0x004b8822 | class-method-cluster | GeneralPurposePanelSwitchActiveTab : reconstructable : 85% : very strong : A002 2026-06-16 support refresh raises to 85/91 and keeps owner/emitter [UID:00005Q][GeneralPurposePanel](by-class/GeneralPurposePanel.md): live IDA reconfirms exact `0x004b8650-0x004b8822` bounds, padding before `GeneralPurposePanel2`, EPF/legacy tab limits and rectangles, child-array/active-index layout, 35-entry side-panel caller fan-in, totem-frame cleanup, old-child hide/collapse, frame-refresh and legacy-effect dependencies, stale SpellOneArgInputPane generated ownership rejected, and remaining source-quality helper/member-name blockers.

## 2026-06-16 - A002-goal2-file-completion-newcreate-newinventory-panelpane-20260616-32

Assignment targets:

- [UID:0000LP] `by-file/NewCreateUserDialogPane.md` (`85/86` before).
- [UID:0000LS] `by-file/NewInventoryPane.md` (`85/86` before).
- [UID:0000ME] `by-file/PanelPane.md` (`85/86` before).

Batch checkpoint:

- Changed files:
  - `by-file/NewCreateUserDialogPane.md`
  - `by-file/NewInventoryPane.md`
  - `by-file/PanelPane.md`
  - `by-class/PanelPane.md`
  - `by-memory/0x00545090-0x00545165.PanelPane.md`
  - `by-memory/0x0061fda0-0x0061fe30.NewCreateUserDialogPaneVtableData.md`
  - `project-level/-auto-completion-stats.md` was updated by validator file-mode validation.
  - `tools/validator.ini` was updated by validator metadata rebuild.
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score/routing decisions:
  - [UID:0000LP] `NewCreateUserDialogPane`: `85/86 -> 86/88`; `CANONICAL_OWNER:FILE` unchanged; projected path remains `NexusTK/login/`.
  - [UID:0000LS] `NewInventoryPane`: `85/86 -> 86/88`; `CANONICAL_OWNER:FILE` unchanged; projected path remains `NexusTK/ui/inventory/`.
  - [UID:0000ME] `PanelPane`: `85/86 -> 86/88`; `CANONICAL_OWNER:FILE` unchanged; projected path remains `NexusTK/ui/core/`.
  - Support [UID:0002SJ] `NewCreateUserDialogPaneVtableData`: `84/90 -> 85/90`; owner/emitter remain [UID:0000LP] `NewCreateUserDialogPane`.
  - Support [UID:0000A4] `PanelPane` class: `85/86 -> 86/88`; owner/emitter remain [UID:0000ME] `PanelPane`.
  - Support [UID:0001EC] `PanelPane` executable island: `85/88 -> 86/89`; owner/emitter remain [UID:0000A4] `PanelPane` class.
- Live IDA evidence checked:
  - Active MCP session `c001_midiplayer_rdata_20260615`, `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready.
  - `NewCreateUserDialogPane`: `lookup_funcs` reconfirmed constructor/selector/handler/submit/packet/payload/reply/destructor starts; `xrefs_to 0x0052c360` remained empty; `xrefs_to 0x0069b4a8` reconfirmed six singleton lifecycle refs; `xrefs_to 0x0061fda0`, `0x0061fe00`, and `0x0061fe30` reconfirmed three refs to each vtable base; `callees` reconfirmed shape-control construction plus command/submit/packet/reply edges. Local PE scan found zero absolute-VA pointer, zero RVA pointer, and zero direct `E8`/`E9` branch/call hits to `0x0052c360`.
  - `NewInventoryPane`: `lookup_funcs` reconfirmed constructor, paint, input, helper, destructor, `ScrollInventoryPane`, and raw scrollbar helper statuses; `xrefs_to 0x004eb420` showed the external constructor caller at `0x004b84a1`; `xrefs_to 0x00563260` still showed the single `0x004eb4e4` caller inside the constructor; vtable refs to `0x0061c7e4`, `0x0061c834`, and `0x0061c864` remain three each; `0x005646b0` remains a raw no-function/no-xref reset helper; `0x004efbb7-0x004efbc0` is nine `0xcc` bytes.
  - `PanelPane`: `lookup_funcs` reconfirmed constructor/destructor/thunk/scalar-destructor, `Pane` constructor/teardown, and `EditablePaperPane` successor; `xrefs_to 0x00545090` now reports sixteen constructor xrefs. The three raw/no-function constructor sites are [UID:00031V] `InventoryPane2RawConstructor` at `0x004ee65a`, [UID:0001HG] `CollectionPane2RawConstructor` at `0x0056fd7a`, and [UID:0002RK] `SpellInventoryPane2CoreAndHelpers` at `0x0057ea6a`. Vtable store triads and thunk/vtable-only scalar destructor dispatch were reconfirmed; boundary bytes at `0x00545086` and `0x00545165` remain `0xcc` alignment.
- Blocker outcomes:
  - `NewCreateUserDialogPane`: direct-constructor reachability remains a real blocker after IDA xrefs and PE pointer/branch scans. Owner/emitter route and login placement are strong; final field/helper names and final source treatment as live versus retained/alternate code remain unresolved.
  - `NewInventoryPane`: `ui/inventory/NewInventoryPane.cpp` remains the source root. `InventoryScrollPane` is still a private companion/fold candidate after one-caller evidence; raw scrollbar helper starts and exact child method splits remain real source-shape blockers after lookup/xref/byte checks. No B-agent escalation indicated.
  - `PanelPane`: reusable UI-core ownership is stronger after the sixteen-xref review. The three raw constructor xrefs were resolved to already documented alternate-pane constructor bodies, not to new modeled PanelPane-owned code. Remaining blocker is final source grouping, standalone `PanelPane.cpp` versus adjacent `Pane.cpp`, plus inherited virtual/field names for final C++.
- Validation commands/results:
  - `python .\tools\validator.py --mode file --file by-file\NewCreateUserDialogPane.md --apply --queue-timeout 240` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x0061fda0-0x0061fe30.NewCreateUserDialogPaneVtableData.md --apply --queue-timeout 240` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\NewInventoryPane.md --apply --queue-timeout 240` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\PanelPane.md --apply --queue-timeout 240` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\PanelPane.md --apply --queue-timeout 240` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00545090-0x00545165.PanelPane.md --apply --queue-timeout 240` -> `ok: 1`.
  - The validation loop exited `0`; follow-up `rg` confirmed `project-level/-auto-completion-stats.md` no longer lists `0000LP`, `0000LS`, or `0000ME`.
- Leases used:
  - `by-file/NewCreateUserDialogPane.md`
  - `by-file/NewInventoryPane.md`
  - `by-file/PanelPane.md`
  - `by-class/PanelPane.md`
  - `by-memory/0x00545090-0x00545165.PanelPane.md`
  - `by-memory/0x0061fda0-0x0061fe30.NewCreateUserDialogPaneVtableData.md`
  - `tools/leaser/Agents/Agent-A002/notes.md`
  - `by-file/-coverage-report.md` and `by-class/-coverage-report.md` lease attempts were rejected because Agent-A001 held active leases; neither report was edited by A002.
- IDA DB changes: none. Evidence supported documentation/source-root updates but no safe IDA-side rename/type/comment edits.
- Release status: all listed A002 leases are to be released immediately after this checkpoint note is written.

Supervisor-applied coverage-report rows retained for audit:

Supervisor applied the `by-file/-coverage-report.md`, `by-class/-coverage-report.md`, and `by-memory/-coverage-report.md` rows below on 2026-06-16 and validated the touched coverage reports with `ok: 1`. No A002 pending report rows remain for this batch.

- `by-file/-coverage-report.md` was not edited because A002 could not acquire the lease. Placement context: replace these rows in-place at the current [UID:0000LP], [UID:0000LS], and [UID:0000ME] rows.
  - [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md) : reconstructable : 86% : strong : A002 2026-06-16 live IDA/PE refresh keeps `login/NewCreateUserDialogPane.cpp` as the owner, reconfirming the full method map, singleton lifecycle refs, vtable child [UID:0002SJ] now at `85/90`, command/submit/packet/reply edges, shape-control construction, zero constructor xrefs, zero PE absolute/RVA/direct-branch references to `0x0052c360`, and retained live-construction/field-name blockers.
  - [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md) : reconstructable : 86% : strong : A002 2026-06-16 live IDA refresh keeps `ui/inventory/NewInventoryPane.cpp` as the newer item-inventory source root, reconfirming constructor/paint/input/helper/destructor ranges, external constructor xref `0x004b84a1`, the one-caller `ScrollInventoryPane` relationship at `0x004eb4e4`, `NewInventoryPane` vtable refs, raw scrollbar reset no-function/no-xref status, trailing padding, private scrollbar fold caveat, and unresolved final field/helper names.
  - [UID:0000ME][PanelPane](by-file/PanelPane.md) : reconstructable : 86% : strong : A002 2026-06-16 UI-core panel-base refresh reconfirms constructor/destructor/thunk/scalar-destructor bounds, `Pane` constructor/teardown edges, sixteen constructor xrefs including raw `InventoryPane2`, `CollectionPane2`, and `SpellInventoryPane2` constructor bodies, broad cleanup/destructor callers, thunk/vtable-only scalar destructor dispatch, complete vtable-store triads, alignment boundaries, and remaining standalone-`PanelPane.cpp` versus `Pane.cpp` source-grouping blocker.
- `by-class/-coverage-report.md` was not edited because A002 could not acquire the lease. Placement context: replace [UID:0000A4] `PanelPane` row in-place.
  - [UID:0000A4][PanelPane](by-class/PanelPane.md) : reconstructable : 86% : strong : A002 2026-06-16 refresh keeps PanelPane attached to UI-core [UID:0000ME][PanelPane](by-file/PanelPane.md), reconfirming constructor/destructor/scalar-deleting destructor sizes, sixteen constructor xrefs with three raw alternate-pane constructor sites, broad cleanup callers, vtable/thunk-only scalar destructor dispatch, three object vptr offsets, complete table-store xrefs, `Pane` teardown, delete-flag/vector-delete behavior, exact vtable/memory child routing, and remaining source-split/final C++ blockers.
- Supervisor-owned `by-memory/-coverage-report.md` rows applied by supervisor. Placement context: replace [UID:0001EC] in the PanelPane executable section and [UID:0002SJ] in the create-user read-only/vtable section.
  - [UID:0001EC][0x00545090-0x00545165.PanelPane](by-memory/0x00545090-0x00545165.PanelPane.md) 0x00545090-0x00545165 | class | PanelPane : reconstructable : 86% : strong : A002 2026-06-16 refresh keeps direct owner/emitter [UID:0000A4][PanelPane](by-class/PanelPane.md): live IDA reconfirms constructor/destructor/scalar-wrapper bounds, sixteen constructor xrefs including raw InventoryPane2/CollectionPane2/SpellInventoryPane2 constructor bodies, destructor caller set, scalar destructor thunk/vtable-only dispatch, callees, three vptr stores, `Pane` teardown, normal free/guard-delete behavior, exact alignment boundaries, and final-C++/source-split caveats.
  - [UID:0002SJ][0x0061fda0-0x0061fe30.NewCreateUserDialogPaneVtableData](by-memory/0x0061fda0-0x0061fe30.NewCreateUserDialogPaneVtableData.md) 0x0061fda0-0x0061fe30 | vtable-data | NewCreateUserDialogPaneVtableData : reconstructable : 85% : strong : A002 2026-06-16 vtable completion refresh keeps owner/emitter [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md), reconfirming constructor, fallback/cleanup, and scalar-deleting-destructor refs to all three table bases, representative primary/secondary/tertiary table bytes, local command/event handler slots, the adjacent successor boundary, and the final class-declaration/inherited-interface naming blocker.

## 2026-06-16 - A002-goal2-file-completion-rightbutton-specialized-spellinventory-20260616-34

Assignment targets:

- [UID:0000N7] `by-file/RightButtonMenuPane.md` (`85/86` before from the current file-completion batch).
- [UID:0000NY] `by-file/SpecializedButtonPanes.md` (`85/86` before from the current file-completion batch).
- [UID:0000O1] `by-file/SpellInventoryPane.md` (`85/86` before from the current file-completion batch).

Batch checkpoint:

- Changed files:
  - `by-file/RightButtonMenuPane.md`
  - `by-file/SpecializedButtonPanes.md`
  - `by-file/SpellInventoryPane.md`
  - `by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md`
  - `by-memory/0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor.md`
  - `by-class/RightButtonMenuPane.md`
  - `by-class/SpellInventoryPane.md`
  - `by-file/-coverage-report.md`
  - `by-class/-coverage-report.md`
  - `project-level/-auto-completion-stats.md` was updated by validator file-mode validation.
  - `tools/validator.ini` was updated by validator metadata rebuild.
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score/routing decisions:
  - [UID:0000N7] `RightButtonMenuPane`: `85/86 -> 86/88`; `CANONICAL_OWNER:FILE` unchanged; projected path remains `NexusTK/ui/menu/`.
  - [UID:0000NY] `SpecializedButtonPanes`: `85/86 -> 86/88`; `CANONICAL_OWNER:FILE` unchanged; projected source family remains provisional `NexusTK/ui/controls/`.
  - [UID:0000O1] `SpellInventoryPane`: `85/86 -> 86/88`; `CANONICAL_OWNER:FILE` unchanged; projected path remains `NexusTK/ui/inventory/`.
  - Support [UID:0001FX] `RightButtonMenuPaneCore`: `82/86 -> 85/88`; owner/emitter corrected from file shortcut [UID:0000N7] to direct class [UID:0000C0] `RightButtonMenuPane`.
  - Support [UID:0001G2] `RightButtonMenuPaneScalarDeletingDestructor`: `82/90 -> 85/90`; owner/emitter corrected from file shortcut [UID:0000N7] to direct class [UID:0000C0] `RightButtonMenuPane`.
  - Support [UID:0000C0] `RightButtonMenuPane`: `85/88 -> 86/89`; owner/emitter remain [UID:0000N7] `RightButtonMenuPane`.
  - Support [UID:0000DN] `SpellInventoryPane`: `84/86 -> 85/88`; owner/emitter remain [UID:0000O1] `SpellInventoryPane`.
- Live IDA evidence checked:
  - Active MCP session `b001_attached_object_0001DF_20260616`, `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready.
  - `RightButtonMenuPane`: `lookup_funcs` and `entity_query` reconfirmed the core functions at `0x00554b40`, `0x00554ba0`, `0x00554c40`, `0x00554f90`, `0x00554fc0`, `0x005552f0`, `0x00555370`, `0x005556a0`, `0x005556f0`, thunks at `0x00556212` and `0x0055621d`, scalar destructor at `0x00556240`, and newly documented helpers `0x005552a0` and `0x005552c0`. `0x005552a0` has caller `0x00555a3d`, closes `unk_69BA38` and `this` through `sub_544690`; `0x005552c0` has caller `0x00507707`, writes `this+0xfc`, and copies a 0x21-wide-character target string to `this+0x100`. Vtable store refs to `0x00622f68`, `0x00622fbc`, and `0x00622fec`, singleton refs to `0x0069b4f0`, and helper caller refs to `0x005556f0` were reconfirmed. Raw packet-helper addresses `0x00555780` and `0x005557e0` remain no-function/no-xref/no-pointer-hit starts.
  - `SpecializedButtonPanes`: `lookup_funcs`, `xrefs_to`, `find_bytes`, and byte reads reconfirmed raw constructor-shaped starts at `0x00500640`, `0x005007a0`, and `0x0059ded0` with no direct xrefs or pointer hits; modeled virtuals/destructors at `0x005006d0`, `0x00500700`, `0x005007f0`, `0x00500820`, `0x0059df50`, and destructors at `0x005026a0`, `0x00502700`, `0x0059f050` have vtable/thunk evidence. `entity_query` around `0x0059ded0-0x0059f0b0` showed a sparse mixed map, so checkbox/source-family split remains provisional. Callees reconfirm state setters through `sub_494B80` and paint/resource/text helper families.
  - `SpellInventoryPane`: `lookup_funcs` reconfirmed legacy constructor/destructor/reset/draw/key/mouse/message/dispatcher/helper methods, new constructor and helper family, alternate SpellInventoryPane2/destructor functions, and scrollbar constructor/raw-helper statuses. `xrefs_to 0x0057c2d0` and pointer scans remained empty; `xrefs_to 0x0057cf70` showed one caller at `0x004b84cb`; dispatcher `0x0057c9b0` has callers at `0x0057c84f` and `0x0057c934` and reads spell records from `dword_67A748 + 0x13a82c + 328 * spellId`. Vtable refs to `0x0062cfdc`, `0x0062d02c`, `0x0062d0f4`, `0x0062d144`, and `0x0062d174` reconfirmed constructor/reset/destructor relationships. Raw `0x0057ea60` and scrollbar raw `0x005608a0` remain no-function/no-xref/pointer-blocked boundaries.
- Blocker outcomes:
  - `RightButtonMenuPane`: the previously omitted `0x005552a0` and `0x005552c0` support helpers were resolved and documented. Core/scalar wrapper direct owner routing was corrected to the class. The packet helpers at `0x00555780` and `0x005557e0` remain real blockers after function lookup, xref lookup, pointer-pattern search, and local map review; no final source-facing helper names are safe yet.
  - `SpecializedButtonPanes`: raw constructor starts were rechecked and remain real source-shape blockers, not safe to promote to modeled functions in this pass. Direction/gender/checkbox ownership stays in one provisional controls file because vtable/type evidence is strong but source layout is sparse and mixed; object-image pane evidence remains excluded to [UID:0000M3].
  - `SpellInventoryPane`: legacy constructor liveness remains blocked after xref and pointer checks; NewSpellInventoryPane has one external constructor caller; SpellInventoryPane2 raw constructor/reset evidence remains byte/vtable based rather than function-modeled. Final old/new/source-split, field names, input-helper names, and scrollbar helper naming remain the limiting source-quality blockers.
- Validation commands/results:
  - `python .\tools\validator.py --mode file --file by-file\RightButtonMenuPane.md --apply --queue-timeout 240` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\SpecializedButtonPanes.md --apply --queue-timeout 240` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\SpellInventoryPane.md --apply --queue-timeout 240` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00554b40-0x0055577b.RightButtonMenuPaneCore.md --apply --queue-timeout 240` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor.md --apply --queue-timeout 240` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\RightButtonMenuPane.md --apply --queue-timeout 240` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\SpellInventoryPane.md --apply --queue-timeout 240` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\-coverage-report.md --apply --queue-timeout 240` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --queue-timeout 240` -> `ok: 1`.
  - The validation loop exited `0`; a follow-up coverage/stats scan confirmed the refreshed file/class coverage rows for `0000N7`, `0000NY`, `0000O1`, `0000C0`, and `0000DN`.
- Leases used:
  - `by-file/RightButtonMenuPane.md`
  - `by-file/SpecializedButtonPanes.md`
  - `by-file/SpellInventoryPane.md`
  - `by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md`
  - `by-memory/0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor.md`
  - `by-class/RightButtonMenuPane.md`
  - `by-class/SpellInventoryPane.md`
  - `by-file/-coverage-report.md`
  - `by-class/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A002/notes.md`
- IDA DB changes: none. The evidence supported documentation, routing, and score changes but no safe IDA-side rename/type/comment edits.
- Release status: all listed A002 leases are to be released immediately after this checkpoint note is written.

Supervisor-applied `by-memory/-coverage-report.md` rows retained for audit:

- Supervisor applied and validated the two replacement rows below on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A002 pending `by-memory/-coverage-report.md` rows remain for this batch. Placement context: replaced [UID:0001FX] in-place after the padding row for `0x00554b38-0x00554b40` and before the padding row for `0x0055577b-0x00555780`; replaced [UID:0001G2] in-place after the padding row for `0x0055623e-0x00556240` and before the padding row for `0x00556314-0x00556320`.
  - [UID:0001FX][0x00554b40-0x0055577b.RightButtonMenuPaneCore](by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md) 0x00554b40-0x0055577b | class method cluster | RightButtonMenuPaneCore : reconstructable : 85% : strong : A002 2026-06-16 refresh keeps direct owner/emitter [UID:0000C0][RightButtonMenuPane](by-class/RightButtonMenuPane.md), adds the previously omitted `0x005552a0` close/dismiss helper and `0x005552c0` target-name/id setter, reconfirms eleven core function starts, helper callers at `0x00555a3d` and `0x00507707`, padding bytes, hit-test caller locality, singleton/vtable refs, adjacent raw packet-helper separation, and remaining final field/action/helper-name blockers.
  - [UID:0001G2][0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor](by-memory/0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor.md) 0x00556240-0x00556314 | scalar deleting destructor | RightButtonMenuPaneScalarDeletingDestructor : reconstructable : 85% : very strong : A002 2026-06-16 refresh corrects direct owner/emitter to [UID:0000C0][RightButtonMenuPane](by-class/RightButtonMenuPane.md), reconfirming exact `0xd4` function size, adjustor-thunk-only code xrefs, primary vtable slot ref, vtable restores, highlighted-target cleanup, pane cleanup helpers, singleton clear, scalar-delete and guarded-delete paths, padding boundaries, and remaining final destructor/helper-name blockers.

## 2026-06-16 Assignment - A002-goal2-file-item-completion-staff-alpha-textedit-20260616-35

Assigned targets:

- [UID:0000O3] `by-file/StaffsDialogPane.md`
- [UID:0000UH] `by-item/DrawEncodedAlphaFrame_00462F20.md`
- [UID:0000UM] `by-item/EncodeTextEditState_0058E490.md`

Instructions:

- Read and follow `Agent-A002/goal.md`, current supervisor notes, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven completion/confidence pass from `project-level/-auto-completion-stats.md`. Raise each target where evidence supports it, including support docs and coverage rows, without inflating scores beyond the evidence.
- Investigate every listed blocker instead of merely repeating it. Resolve it where supported; otherwise record the exact IDA/docs/metadata evidence checked and why it remains unsafe. Do not defer unresolved names/reachability/source-placement issues to final C++ without investigating.
- If any assigned target cannot be brought to or kept at `85/85+`, do additional research before returning; if it still cannot clear the gate, report the evidence and why the score must stay lower.
- Prefer routine evidence refresh and support-doc repair. If the target becomes mainly source-structure inference or broad original-layout guessing, document the checked evidence and recommend B-agent escalation rather than forcing a route.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply. Non-memory coverage reports may be edited directly only under normal lease rules.
- Report changed files, leases, validations, before/after scores, owner/emitter decisions, blocker investigations, IDA DB changes if any, and any exact pending supervisor-owned report rows.

Batch checkpoint:

- Changed files:
  - `by-file/StaffsDialogPane.md`
  - `by-item/DrawEncodedAlphaFrame_00462F20.md`
  - `by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md`
  - `by-item/EncodeTextEditState_0058E490.md`
  - `by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md`
  - `by-file/TextEditPane.md`
  - `by-file/-coverage-report.md`
  - `by-item/-coverage-report.md`
  - `project-level/-auto-completion-stats.md` was updated by validator file-mode validation.
  - `tools/validator.ini` was updated by validator metadata rebuild.
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score/routing decisions:
  - [UID:0000O3] `StaffsDialogPane`: `85/86 -> 86/88`; `CANONICAL_OWNER:FILE` unchanged; projected path remains `NexusTK/login/`.
  - [UID:0000UH] `DrawEncodedAlphaFrame_00462F20`: `84/88 -> 85/89`; owner/emitter remain [UID:0000HF] `AlphaMaskSurface`.
  - Support [UID:0000YO] `0x00462f20-0x00463252.DrawEncodedAlphaFrame`: `82/88 -> 85/89`; owner/emitter remain [UID:0000HF] `AlphaMaskSurface`.
  - [UID:0000UM] `EncodeTextEditState_0058E490`: `84/88 -> 85/89`; owner/emitter remain [UID:0000ON] `TextEditPane`.
  - Support [UID:0001JN] `0x0058e490-0x0058e691.TextEditPaneSerialization`: `84/88 -> 85/89`; owner/emitter remain [UID:0000ON] `TextEditPane`.
  - Support [UID:0000ON] `TextEditPane`: score unchanged at `89/86`; stale proposed-contents endpoint for `EncodeTextEditState` corrected from `0x0058e490-0x0058e690` to `0x0058e490-0x0058e691`.
- Live IDA evidence checked:
  - Active MCP session `b001_maildialogs_0000ZO_20260616`, `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready.
  - `StaffsDialogPane`: `lookup_funcs` reconfirmed `StaffsDialogPane_Constructor` at `0x004ffaa0` size `0x27d`, `StaffsDialogPane_OnDialogAction` at `0x004ffd20` size `0x1d`, `StaffsDialogPane_ClearSingletonHelper` at `0x00502410` size `0xb`, destructor thunks at `0x00502592`/`0x0050259d` size `0xb` each, and `StaffsDialogPane_ScalarDeletingDestructor` at `0x00502cc0` size `0x45`. `xrefs_to` reconfirmed zero constructor xrefs, action vtable ref `0x0061d97c`, destructor thunk/vtable refs `0x00502598`, `0x005025a3`, and `0x0061d934`, four `g_pStaffsDialog` lifecycle refs, five `STAFF.EPF` pointer refs through `0x0066db44`, and direct `STAFFS2`/`STAFFS` refs at `0x004ffc4b` and `0x004ffc72`. Decompilation reconfirmed singleton publication, three vtable stores, `STAFF.EPF`/`NPAL8.PAL` setup, close button id `14`, event-flag bit `0x02` text selection, main-menu show, and action id `1` close behavior.
  - `DrawEncodedAlphaFrame`: `lookup_funcs` reconfirmed `sub_462F20` at `0x00462f20` size `0x332`; `xrefs_to` reported nine code xrefs. Six are modeled image-library callers (`0x004db3b0`, `0x004dd2c0`, `0x004de190`, `0x004dee50`, `0x004defc0`, `0x004e2fe0`), and three remain raw no-containing-function callsites (`0x004d5ea6`, `0x004d6b16`, `0x004dcca5`). Compact analysis reconfirmed callees `sub_4B7CC0`, `_memset`, and security-cookie check, plus signed-run row decoding, target pixel/stride reads from the alpha surface, vertical alpha-ramp math, and replace/add/subtract modes.
  - `EncodeTextEditState`: `lookup_funcs` reconfirmed `sub_58E490` at `0x0058e490` size `0x201`; `xrefs_to` found exactly one raw jump at `0x00498c4a`; `lookup_funcs 0x00498c40` still reports no function. `make_signature_for_range 0x00498c40-0x00498c4f` returned unique bytes `55 8B EC 8B 89 0C 01 00 00 5D E9 41 58 0F 00`, matching a wrapper that loads the embedded editor from `+0x10c` and jumps to `0x0058e490`. Decompilation reconfirmed table/list offsets `+0x134`, `+0x138`, `+0x13c`, `+0x140`, stack Encoder setup over a 32766-byte window, delimiter byte `0`, marker `0x6b6f6e67`, finalization, exact heap allocation/copy, output-size store, and Encoder cleanup.
- Blocker outcomes:
  - `StaffsDialogPane`: C001's safe IDA function renames were confirmed present; no new IDA DB edit was needed. Constructor reachability remains a real blocker after current `xrefs_to`/analysis still reports zero constructor refs; resource/singleton/vtable evidence supports login placement but cannot prove the menu entry path.
  - `DrawEncodedAlphaFrame`: exact helper ownership remains with `AlphaMaskSurface`; the three raw image-library callsites and final encoded-frame type names remain real blockers after current xref/function-containment and decompilation checks. The unresolved callsites do not justify B-agent escalation in this pass because they are source-boundary recovery issues for known image-library neighborhoods, not owner-unknown evidence.
  - `EncodeTextEditState`: owner/emitter route stays TextEditPane, not BinaryCodec or TextEditControlPane, because current decompilation reads TextEditPane table/list state while the only inbound wrapper loads `+0x10c` then tail-jumps. The wrapper start remains not modeled as a function and the four private table/list member names remain descriptive rather than final, so final C++ stays blank.
- Validation commands/results:
  - `python .\tools\validator.py --mode file --file by-file\StaffsDialogPane.md --apply --queue-timeout 240` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-item\DrawEncodedAlphaFrame_00462F20.md --apply --queue-timeout 240` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00462f20-0x00463252.DrawEncodedAlphaFrame.md --apply --queue-timeout 240` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-item\EncodeTextEditState_0058E490.md --apply --queue-timeout 240` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x0058e490-0x0058e691.TextEditPaneSerialization.md --apply --queue-timeout 240` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\TextEditPane.md --apply --queue-timeout 240` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\-coverage-report.md --apply --queue-timeout 240` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-item\-coverage-report.md --apply --queue-timeout 240` -> `ok: 1`.
  - The validation loop exited `0`. Follow-up `rg` confirmed the refreshed by-file/by-item coverage rows and generated item/file routes; `project-level/-auto-completion-stats.md` no longer lists [UID:0000O3], while [UID:0000UH] and [UID:0000UM] remain visible at exactly `85/89` because their completion is intentionally held at `85` by unresolved source-quality blockers.
- Leases used:
  - `by-file/StaffsDialogPane.md`
  - `by-item/DrawEncodedAlphaFrame_00462F20.md`
  - `by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md`
  - `by-item/EncodeTextEditState_0058E490.md`
  - `by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md`
  - `by-file/TextEditPane.md`
  - `by-file/-coverage-report.md`
  - `by-item/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A002/notes.md`
- IDA DB changes: none. C001's existing StaffsDialogPane function names were observed, but this pass made no IDA rename/type/comment/save changes.
- Release status: all listed A002 leases are to be released immediately after this checkpoint note is written.

Supervisor-applied `by-memory/-coverage-report.md` rows retained for audit:

- Supervisor applied and validated the two replacement rows below on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A002 pending `by-memory/-coverage-report.md` rows remain for this batch. Placement context: replaced [UID:0000YO] in-place under the AlphaMaskSurface aggregate after padding row `0x00462f1e-0x00462f20` and before padding row `0x00463252-0x00463260`; replaced [UID:0001JN] in-place inside the TextEditPane core/support area after [UID:00030E] `0x00590de0-0x00591180.TextEditPaneOnMouseEvent` and before [UID:0001JO] `0x00591300-0x005954b3.TextBoxPaneNoncontiguousAuditMap`.
  - [UID:0000YO][0x00462f20-0x00463252.DrawEncodedAlphaFrame](by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md) 0x00462f20-0x00463252 | render helper function | DrawEncodedAlphaFrame : reconstructable : 85% : strong : A002 2026-06-16 refresh raises to 85/89 and keeps owner/emitter [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md): live IDA reconfirms exact `0x332` size, nine xrefs, six modeled image-library callers, three raw no-containing-function callsites, compact callee set, signed-run row decoding, vertical alpha-ramp math, replace/add/subtract modes, and remaining encoded-frame type/raw-caller boundary blockers.
  - [UID:0001JN][0x0058e490-0x0058e691.TextEditPaneSerialization](by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md) 0x0058e490-0x0058e691 | function | TextEditPaneSerialization : reconstructable : 85% : strong : A002 2026-06-16 refresh raises to 85/89 and keeps owner/emitter [UID:0000ON][TextEditPane](by-file/TextEditPane.md): live IDA reconfirms exact `0x201` size, one raw wrapper jump at `0x00498c4a`, no modeled function at `0x00498c40`, unique wrapper bytes loading `+0x10c`, Encoder/allocation callees, table/list offsets `+0x134`/`+0x138`/`+0x13c`/`+0x140`, delimiter and `"kong"` marker writes, exact output allocation/copy, and remaining final field/wrapper-method naming blockers.

## 2026-06-16 Assignment - A002-goal2-file-item-completion-ranking-startup-predefined-20260616-37

Assigned targets:

- [UID:0000MZ] `by-file/RankingDialog.md`
- [UID:0000UA] `by-item/CurlWriteCallback_00581B80.md`
- [UID:0000UE] `by-item/DeserializePredefinedFormArticleEntries_478650.md`

Instructions:

- Read and follow `Agent-A002/goal.md`, current supervisor notes, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven completion/confidence pass from the refreshed `project-level/-auto-completion-stats.md` by-folder queue. Raise each target where evidence supports it, including support docs and coverage rows, without inflating scores beyond the evidence.
- Investigate every listed blocker instead of merely repeating it. Resolve it where supported; otherwise record the exact IDA/docs/metadata evidence checked and why it remains unsafe. Do not defer unresolved names/reachability/source-placement issues to final C++ without investigating.
- If any assigned target cannot be brought to or kept at `85/85+`, do additional research before returning; if it still cannot clear the gate, report the evidence and why the score must stay lower.
- `RankingDialog` is a known-owner feature-file refresh target, not a license to guess the original source tree. If the work becomes broad source-layout inference beyond routine evidence refresh, document the evidence checked and recommend B-agent escalation rather than forcing a route.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply. Non-memory coverage reports may be edited directly only under normal lease rules.
- Report changed files, leases, validations, before/after scores, owner/emitter decisions, blocker investigations, IDA DB changes if any, and any exact pending supervisor-owned report rows.

Batch checkpoint:

- Changed files:
  - `by-file/RankingDialog.md`
  - `by-memory/0x00458610-0x0045f9f5.RankingDialog.md`
  - `by-item/CurlWriteCallback_00581B80.md`
  - `by-item/DeserializePredefinedFormArticleEntries_478650.md`
  - `by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md`
  - `by-file/NewPredefinedFormArticleDialog.md`
  - `by-file/-coverage-report.md`
  - `by-item/-coverage-report.md`
  - `project-level/-auto-completion-stats.md` was refreshed by validator file-mode validation; the three target UIDs no longer appear in the refreshed low-score lists.
  - `tools/validator.ini` was refreshed by validator metadata rebuild.
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score/routing decisions:
  - [UID:0000MZ] `RankingDialog`: `85/86 -> 86/88`; `CANONICAL_OWNER:FILE` unchanged; projected path remains `NexusTK/ui/dialogs/`.
  - Support [UID:0000XZ] `0x00458610-0x0045f9f5.RankingDialog`: `82/86 -> 85/88`; owner/emitter remain [UID:0000MZ] `RankingDialog`.
  - [UID:0000UA] `CurlWriteCallback_00581B80`: `85/88 -> 86/89`; owner/emitter remain [UID:0000O5] `StartupWindow`.
  - [UID:0000UE] `DeserializePredefinedFormArticleEntries_478650`: `85/88 -> 86/89`; owner/emitter remain [UID:0000LT] `NewPredefinedFormArticleDialog`.
  - Support [UID:0002UP] `0x00478650-0x00478933.DeserializePredefinedFormArticleEntries`: `82/88 -> 85/89`; owner/emitter remain [UID:0000LT] `NewPredefinedFormArticleDialog`.
  - Support [UID:0000LT] `NewPredefinedFormArticleDialog`: score unchanged at `88/85`; parser endpoint wording corrected from terminal-byte `0x00478932` to exact half-open `0x00478650-0x00478933`.
- Live IDA evidence checked:
  - Active MCP session `b001_selflookpane_0001H7_20260616`, `NexusTK.exe.i64`, image base `0x00400000`, Hex-Rays ready.
  - `RankingDialog`: `lookup_funcs` reconfirmed the core method map from `0x00458610` through `0x00459840`, with current IDA names `RankingDialog_HandleRankingPacket`, `RankingDialog_ClearSingletonHelper`, and `RankingDialog_ScalarDeletingDestructor`. `xrefs_to 0x00458610` shows the single command-dispatch constructor call at `0x005bd2ab`; `xrefs_to 0x00459210` shows the secondary-vtable slot `0x006109f4`; `xrefs_to 0x0067a7e4` shows all 17 singleton refs. `analyze_function 0x00459210` reconfirmed opcode `0x7d` subcommands `1`, `2`, `3`, and `6`. `lookup_funcs`/`xrefs_to` kept raw `RankingEventScrollPane` starts `0x004598b0`, `0x0045a990`, and `0x0045add0` as no-function/no-inbound-xref bodies; byte check around `0x004598a0` confirmed padding before the raw scroll constructor.
  - `CurlWriteCallback`: `lookup_funcs` reconfirmed `sub_581B80` at `0x00581b80`, size `0x166`; `xrefs_to` showed exactly two data refs at `0x00580c6f` and `0x00580efb` from `StartupWindow::RunUpdateCheck`; `analyze_function` reported prototype `int __cdecl(const char *Src, int, int, void **)`, 20 blocks, complexity 6, no direct callers, and append/growth/free callees. Adjacent helpers `0x00581cf0`, `0x00581e40`, and `0x00581f50` still have only `RunUpdateCheck` callers; bytes around `0x00581b70` reconfirmed padding before callback entry.
  - `DeserializePredefinedFormArticleEntries`: `lookup_funcs` reconfirmed `sub_478650` at `0x00478650`, size `0x2e3`, half-open end `0x00478933`; `xrefs_to` showed exactly two constructor call sites at `0x00477848` and `0x00477d0c`; `analyze_function`/decompilation showed 15 blocks, `0x40c` entry stride writes, `L"empty"` body handling, visible-row count calculation/stores, `sub_516030`, `sub_516220`, `_wcscpy_s`, and security-cookie calls. Bytes around `0x00478640` reconfirmed padding before the parser prologue.
- Blocker outcomes:
  - `RankingDialog`: source root remains `NexusTK/ui/dialogs/RankingDialog.cpp`. The file no longer has a low support aggregate blocker because [UID:0000XZ] is refreshed to `85/88`. Remaining blockers are real after live checks: final original filename versus compact ranking feature split, private member/helper names, raw scroll helper source shape, and generated-output pollution cleanup for WebBoard/popup/dialog-animation/render helpers. No B-agent escalation is needed because ownership/routing are known and the remaining work is source-quality cleanup.
  - `CurlWriteCallback`: ownership remains StartupWindow-local because the callback and adjacent parse helpers only reference `RunUpdateCheck`. Final C++ remains blank because the source callback typedef, 24-byte ANSI small-string type name, allocator helper names, and neighboring startup string helper names are not recovered original names; no broader shared string utility route is supported by xrefs.
  - `DeserializePredefinedFormArticleEntries`: ownership remains NewPredefinedFormArticleDialog-local because the parser still has only two constructor xrefs. The exact half-open endpoint is resolved to `0x00478933`; final C++ remains blank because the source-quality `PredefinedFormArticleEntry` declaration, field/member names, and conversion helper names are not fully recovered.
- Validation commands/results:
  - `python .\tools\validator.py --mode file --file by-file\RankingDialog.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00458610-0x0045f9f5.RankingDialog.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-item\CurlWriteCallback_00581B80.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-item\DeserializePredefinedFormArticleEntries_478650.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\NewPredefinedFormArticleDialog.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\-coverage-report.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-item\-coverage-report.md --apply --lock-timeout -1` -> `ok: 1`.
- Leases used:
  - `by-file/RankingDialog.md`
  - `by-memory/0x00458610-0x0045f9f5.RankingDialog.md`
  - `by-item/CurlWriteCallback_00581B80.md`
  - `by-item/DeserializePredefinedFormArticleEntries_478650.md`
  - `by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md`
  - `by-file/NewPredefinedFormArticleDialog.md`
  - `by-file/-coverage-report.md`
  - `by-item/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A002/notes.md`
- IDA DB changes: none. Rename candidates `sub_458610`, `sub_581B80`, and `sub_478650` were documented but not applied because the active MCP session is currently B001's SelfLookPane database and the remaining names still depend on broader class-layout/helper/type source-quality work. Existing safe C001 names for `RankingDialog_HandleRankingPacket`, `RankingDialog_ClearSingletonHelper`, `RankingDialog_ScalarDeletingDestructor`, and `g_pRankingDialog` were observed.
- Release status: all listed A002 leases are to be released immediately after this checkpoint note is written.

Supervisor-applied `by-memory/-coverage-report.md` replacements:

- Supervisor applied and validated the two replacement rows below on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A002 pending `by-memory/-coverage-report.md` rows remain for this batch.

- Placement context: replace the current [UID:0000XZ] row in-place after [UID:000201] `0x00458590-0x00458610.EPFTileContextPixelRangeTest` and before [UID:0000Y0] `0x00459810-0x0045981a.RankingDialogClearSingletonHelper`.
  - [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md) 0x00458610-0x0045f9f5 | class aggregate | RankingDialog : reconstructable : 85% : strong : A002 2026-06-16 refresh raises aggregate to 85/88 and keeps owner/emitter [UID:0000MZ][RankingDialog](by-file/RankingDialog.md): live IDA reconfirms core method map, dispatcher constructor xref, secondary-vtable packet handler, all 17 `g_pRankingDialog` refs, opcode `0x7d` subcommand dispatch callees, raw event-scroll helper no-function/no-xref status, padding before raw constructor, and remaining final member/helper-name/source-output-pollution blockers.
- Placement context: replace the current [UID:0002UP] row in-place after the padding row `0x0047864c-0x00478650 | OnPaint/parser alignment` and before the padding row `0x00478933-0x00478940 | parser/transfer reply handler alignment`.
  - [UID:0002UP][0x00478650-0x00478933.DeserializePredefinedFormArticleEntries](by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md) 0x00478650-0x00478933 | parser helper | DeserializePredefinedFormArticleEntries : reconstructable : 85% : strong : A002 2026-06-16 refresh raises to 85/89 and keeps owner/emitter [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md): live IDA reconfirms exact half-open range, `0x2e3` size, two constructor-only xrefs, clean padding before parser, 15-block field parser, `0x40c` entry stride writes, `L"empty"` handling, visible-row count stores, and remaining final struct/member/helper-name blockers.
## 2026-06-16 Assignment - A002-goal2-item-completion-dat-friend-frame-20260616-39

Assigned targets:
- [UID:0000UC] `by-item/DATEntryRecord.md`
- [UID:0000UP] `by-item/FriendNameListSyncOpcodes.md`
- [UID:0000UY] `by-item/LoadImageFrameTable_004D0F50.md`

Instructions:
- Read and follow `Agent-A002/goal.md`, current supervisor notes, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven by-item completion pass from refreshed `project-level/-auto-completion-stats.md`. Raise each target and directly supporting page where evidence supports it, including support docs and coverage rows, without inflating scores beyond the evidence.
- Investigate every listed blocker instead of repeating it. Resolve field/type/global/protocol/helper-name, caller/reachability, ownership, source-placement, split/merge/range, and final-C++ blockers where supported; otherwise record the exact IDA/docs/metadata evidence checked and why the issue remains unsafe.
- Do not defer source-quality blockers to final C++ without investigating them during this evidence pass.
- If any assigned target cannot be brought to or kept at `85/85+`, do additional research before returning; if it still cannot clear the gate, report the evidence and why the score must stay lower.
- `DATEntryRecord` and `LoadImageFrameTable` are known-owner item pages. `FriendNameListSyncOpcodes` is a reviewed non-emitting protocol item; keep `RECONSTRUCTABLE:FALSE` unless stronger evidence justifies a source-emitting owner. If any target becomes heavy source-structure inference or broad original-layout guessing, document the checked evidence and recommend B-agent escalation rather than forcing a route.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply. Non-memory coverage reports may be edited directly only under normal lease rules.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and any exact pending supervisor-owned report rows.

Batch checkpoint:

- Changed files:
  - `by-item/ServerSelectHelpers_574510_5745b0.md`
  - `by-item/SpellMenuActionButtonState_51d6c0_51e600.md`
  - `by-item/VectorGrowArchiveIndex_004E5990.md`
  - `by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md`
  - `by-item/-coverage-report.md`
  - Validator-owned updates: `project-level/-auto-completion-stats.md`, `tools/validator.ini`, `auto-generated/-ag-item-coverage.md`
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score/routing decisions:
  - [UID:0000VG] `ServerSelectHelpers_574510_5745b0`: `84/90 -> 86/91`; owner/emitter remain [UID:0000NO] `ServerSelectPane`.
  - [UID:0000VH] `SpellMenuActionButtonState_51d6c0_51e600`: `84/90 -> 86/91`; owner/emitter remain [UID:0000O2] `SpellMenuDialogs`.
  - [UID:0000VK] `VectorGrowArchiveIndex_004E5990`: `84/90 -> 86/91`; owner/emitter remain [UID:0000LJ] `MonsterImageLib`.
  - Support [UID:0002VF] `0x004e5990-0x004e5a62.VectorGrowArchiveIndex`: `84/90 -> 86/91`; owner/emitter remain [UID:0000LJ] `MonsterImageLib`.
- Live IDA evidence checked:
  - Active MCP session `b001_selflookpane_0001H7_20260616`, `NexusTK.exe`, image base `0x00400000`, Hex-Rays ready.
  - ServerSelect helpers: `lookup_funcs` reconfirmed modeled `0x00574510` size `0x3e` and `0x005745b0` size `0xae`; raw starts `0x00574500`, `0x00574550`, `0x00574570`, and `0x00574580` remain non-functions. `xrefs_to` found only the two action-handler calls to `0x00574510` and the two refs to `0x005745b0` at `0x00574546`/raw `0x005745a1`. `xrefs_to` found no refs to raw starts, and `find_bytes` found no direct 32-bit pointer-byte hits for raw helper starts. Disassembly of `0x00574570` confirmed the raw wrapper body, `sub_41B9B0` name-copy call, `0x005745a1` call to `0x005745b0`, `retn 4`, and `0xcc` alignment. Decompilation/disassembly confirmed `g_pConfig` offsets `0x2916d0`, `0x28d9d8`, `0x28d9dd`, `0x291230`, and `0x2912b0` with int_convert verification, plus packet byte `0x57`.
  - Spell action-button state: `lookup_funcs` reconfirmed exact 61-byte helpers at `0x0051d6c0` and `0x0051e600`. `xrefs_to` found vtable-only refs at `0x0061f1b4` and `0x0061f314`, no ordinary code callers, client list constructor refs at `0x0051dce7`/`0x0051e189`, client renderer vtable ref at `0x0061f3e4`, and negative `ChattingColorListPane` constructor refs only at `0x00482837`/`0x0048295d`. Decompilation reconfirmed child slot `1`, child slot `6`, list storage `+0x108` / decimal `264` (Verified with int_convert.py), shared `sub_4F3E20` enabled-entry count, and action-button virtual dispatch through `+0x4c/+0x50`. `xrefs_to 0x004f3e20` showed 14 broad UI callers, so it remains a shared helper.
  - VectorGrowArchiveIndex: `lookup_funcs` reconfirmed `sub_4DBC60` size `0x19b`, `sub_4E5990` size `0xd2`, and `sub_4E6DF0` size `0x59`; `0x004e5a62` remains not a function. `xrefs_to 0x004e5990` found one caller at `0x004dbd8f`; `xrefs_to 0x004dbc60` found constructor reachability at `0x004daff5`; `xrefs_to 0x004e6df0` found only the grow-helper call. Decompilation of `LoadMonsterArchives` showed vector state at `this + 0x10/+0x14/+0x18`, fast append versus slow grow call, and new 32-bit archive-index value handling. Decompilation of `0x004e5990` and `0x004e6df0` confirmed the three-pointer vector grow/insert and storage replacement behavior. Boundary bytes reconfirmed `0xcc` padding before `0x004e5990` and at `0x004e5a62-0x004e5a70`.
- Blocker outcomes:
  - ServerSelect raw wrapper boundary was resolved to `0x00574570-0x005745a9`, but no IDA function metadata was changed because no function object, no direct raw-start refs, and no pointer-byte reachability were found. `g_pConfig` is now used for the config singleton, but selected-server entry fields and raw display/session buffer names remain behavior-backed.
  - Spell action-button helper ownership and chat-list rejection are resolved. Remaining blockers are source names for child constants, list-storage member, shared enabled-count helper, and action-button enable/disable virtuals.
  - VectorGrowArchiveIndex owner/source placement is resolved for this pass as `MonsterImageLib.cpp`; no B-agent escalation is needed. Remaining blockers are final archive-index vector field names, allocation/free helper names, and source shape as local helper versus template-like instantiation.
- Validation commands/results:
  - `python .\tools\validator.py --mode file --file by-item\ServerSelectHelpers_574510_5745b0.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-item\SpellMenuActionButtonState_51d6c0_51e600.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-item\VectorGrowArchiveIndex_004E5990.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-item\-coverage-report.md --apply --lock-timeout -1` -> `ok: 1`.
- Leases used:
  - `by-item/ServerSelectHelpers_574510_5745b0.md`
  - `by-item/SpellMenuActionButtonState_51d6c0_51e600.md`
  - `by-item/VectorGrowArchiveIndex_004E5990.md`
  - `by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md`
  - `by-item/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A002/notes.md`
- IDA DB changes: none. This pass used read-only lookup/xref/decompile/disasm/byte searches only; rename/type/function-definition candidates remain blocked by source-quality names or raw reachability.
- Release status: all listed A002 leases are to be released immediately after this checkpoint note is written.

Supervisor-applied `by-memory/-coverage-report.md` replacement:

Supervisor applied and validated the [UID:0002VF] replacement row on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A002 pending `by-memory/-coverage-report.md` rows remain for `A002-goal2-item-completion-server-spell-vector-20260616-42`.

- Placement context: replace the current [UID:0002VF] row in-place under [UID:00017C][0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster](../../../by-memory/0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster.md), after the [UID:0002JN] `0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables` row and before the [UID:00017D] `0x004db010-0x004db0f7.MonsterImageLibDestructor` row.
  - [UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md) 0x004e5990-0x004e5a62 | vector grow helper | VectorGrowArchiveIndex : reconstructable : 86% : very strong : Exact MonsterImageLib archive-index vector grow helper; A002 2026-06-16 live IDA refresh reconfirms one `LoadMonsterArchives` caller at `0x004dbd8f`, constructor reachability through `0x004daff5`, caller fast/slow append split, vector state at `this + 0x10/+0x14/+0x18`, one-caller storage-replacement helper `0x004e6df0`, allocation/memmove/error callees, boundary padding, owner/emitter route, and remaining final field/helper-name blockers.

## 2026-06-16 Assignment - A002-goal2-resource-completion-icons-interface-sobj-20260616-46

Assigned targets:
- [UID:0001RD] `by-resource/iconspane-icon-resources.md`
- [UID:0001RE] `by-resource/interface-efx-resources.md`
- [UID:0001RL] `by-resource/sobj-tbl.md`

Batch checkpoint:

- Changed files: `by-resource/iconspane-icon-resources.md`, `by-resource/interface-efx-resources.md`, `by-resource/sobj-tbl.md`, `by-resource/-coverage-report.md`, support docs `by-global/g_objectNationMap.md` and `by-global/g_objectRecordCount.md`, validator-owned `project-level/-auto-completion-stats.md`, `tools/validator.ini`, generated autogen coverage metadata, and this notes file.
- Score/routing decisions: [UID:0001RD] `iconspane-icon-resources` `87/91 -> 89/92`, `CANONICAL_OWNER:NONE` unchanged; [UID:0001RE] `interface-efx-resources` `87/91 -> 88/92`, `CANONICAL_OWNER:NONE` unchanged; [UID:0001RL] `sobj-tbl` `87/91 -> 90/93`, `CANONICAL_OWNER:NONE` unchanged. Support globals [UID:0000Q3] `g_objectNationMap` and [UID:0000Q4] `g_objectRecordCount` stayed `88/89`; only their SOBJ sample/index caveats were synced.
- Live IDA/package evidence checked: active MCP database `b001_selflookpane_0001H7_20260616` on `NexusTK.exe`. `lookup_funcs` reconfirmed `sub_4CF300` size `0xd3`, `sub_4E9D00` size `0x178`, `sub_4E9F40` size `0x11e`, `sub_4EA130` size `0xd2`, `sub_57C2D0` size `0xcf`, `sub_4DCF60` size `0x278`, `sub_4DDE10` size `0x14e`, and `MapPaneInitialize` size `0x411`. `xrefs_to` reconfirmed one `ICONS.EPD` xref, ten `NPAL7.PAL` xrefs, seven `INTEFX.PAD` xrefs, exact EPD xref counts for `CHREFX`/`MAGEFX`/`ITEMEFX`/`FRMLEFX`/`FRMREFX`, and three `SOBJ.TBL` xrefs. Decompilation reconfirmed IconsPane full/reduced and pressed-frame math, InterfaceEfxMgr persistent offsets `+0xf8/+0xfc/+0x100`, randomized frame-effect interval `rand() % 180000 + 120000`, InventoryPane and SpellInventoryPane non-manager effect consumers, and the two SOBJ parser views.
- Package evidence checked: table-only scan across `E:\2026\Resources\Read_Only\NexusTK\Data` found current icon variants `ICON.EPF`, `ICONS.EPF`, `NPAL7.PAL`; current interface-effect variants `CHREFX.EPF`, `MAGEFX.EPF`, `ITEMEFX.EPF`, `FRMLEFX.EPF`, `FRMREFX.EPF`, `INTEFX.PAL`; and one `tile.dat` `SOBJ.TBL`. No exact legacy `ICONS.EPD`, interface-effect `.EPD`, or `INTEFX.PAD` DAT entries were found. Loose exact-name search under `E:\2026\Resources` found no legacy payload duplicates. Aligned UTF-16 executable scans found the missing legacy operands only as executable literals at the recorded raw offsets. Direct `SOBJ.TBL` payload parsing consumed all `276,147` bytes into `19,551` records, found `485` leading `0xffffffff` records, first non-sentinel object id at index `485`, and word-count range `0..12`.
- Blocker outcomes: `ICONS.EPD` payload remains missing from the audited package, but `NPAL7.PAL` unknown-consumer scope is resolved to six consumer functions and ten ref sites; final icon frame names and click-action/source names remain unsafe. Interface-effect exact `.EPD`/`INTEFX.PAD` payloads remain missing, but current EPF/PAL successor headers and both non-manager consumers are now documented; PAD-vs-PAL structure and final trigger labels remain unsafe. `SOBJ.TBL` record-zero ambiguity is narrowed to a concrete leading sentinel/reserved block; exact one-byte field names, sentinel-block semantics, and the `0x0001` header meaning remain unresolved. No B-agent escalation is needed for this batch.
- Validation commands/results: `python .\tools\validator.py --mode file --file by-resource\iconspane-icon-resources.md --apply --lock-timeout -1` -> `ok: 1`; `python .\tools\validator.py --mode file --file by-resource\interface-efx-resources.md --apply --lock-timeout -1` -> `ok: 1`; `python .\tools\validator.py --mode file --file by-resource\sobj-tbl.md --apply --lock-timeout -1` -> `ok: 1`; `python .\tools\validator.py --mode file --file by-resource\-coverage-report.md --apply --lock-timeout -1` -> `ok: 1`; `python .\tools\validator.py --mode file --file by-global\g_objectNationMap.md --apply --lock-timeout -1` -> `ok: 1`; `python .\tools\validator.py --mode file --file by-global\g_objectRecordCount.md --apply --lock-timeout -1` -> `ok: 1`.
- Leases used/release status: leased the three target resource pages, `by-resource/-coverage-report.md`, `by-global/g_objectNationMap.md`, `by-global/g_objectRecordCount.md`, and this notes file. All A002 leases are to be released immediately after this checkpoint note is written.
- IDA DB changes: none. This pass used read-only lookup/xref/decompile/package/string scans only; no rename/type/comment/save was safe because remaining names depend on unrecovered source/resource terminology or absent legacy payloads.
- Supervisor-owned `by-memory/-coverage-report.md`: no changes needed; no by-memory files were edited in this batch.

## 2026-06-16 Assignment - A002-goal2-resource-completion-icons-interface-sobj-20260616-46

Assigned targets:
- [UID:0001RD] `by-resource/iconspane-icon-resources.md`
- [UID:0001RE] `by-resource/interface-efx-resources.md`
- [UID:0001RL] `by-resource/sobj-tbl.md`

Instructions:
- Read and follow `Agent-A002/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven resource provenance pass from refreshed `project-level/-auto-completion-stats.md`. Improve completion/confidence where evidence supports it, including supporting file/class/resource docs and coverage reports, without inflating scores beyond the evidence.
- Investigate every listed blocker instead of repeating it. Resolve package availability, old-layout/current-package variant status, source/resource boundary, consumer ownership, filename/payload provenance, field/record semantics, and final-C++/source-resource blockers where supported; otherwise record the exact package/IDA/docs evidence checked and why the issue remains unsafe.
- These resource pages intentionally keep `CANONICAL_OWNER:NONE` unless a real source-owned declaration is proven. Do not invent an owner just to route a resource page.
- If any target becomes heavy source-structure inference, broad original-layout guessing, or ambiguous shared-owner routing, document the checked evidence and recommend B-agent escalation rather than forcing a route.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply. Non-memory coverage reports may be edited directly only under normal lease rules.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and any exact pending supervisor-owned report rows.

## 2026-06-16 Assignment - A002-goal2-item-resource-completion-textedit-backpane-hour-20260616-44

Assigned targets:
- [UID:0000UM] `by-item/EncodeTextEditState_0058E490.md`
- [UID:0001R7] `by-resource/backpane-background-resources.md`
- [UID:0001RC] `by-resource/hourpane-time-resources.md`

Batch checkpoint:

- Changed files: `by-item/EncodeTextEditState_0058E490.md`, `by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md`, `by-resource/backpane-background-resources.md`, `by-resource/hourpane-time-resources.md`, `by-resource/-coverage-report.md`, `by-item/-coverage-report.md`, validator-owned `project-level/-auto-completion-stats.md`, `tools/validator.ini`, generated coverage metadata, and this notes file.
- Score/routing decisions: [UID:0000UM] `EncodeTextEditState_0058E490` `85/89 -> 86/90`, owner/emitter remain [UID:0000ON] `TextEditPane`; support [UID:0001JN] `TextEditPaneSerialization` `85/89 -> 86/90`, owner/emitter remain [UID:0000ON] `TextEditPane`; [UID:0001R7] `backpane-background-resources` `87/91 -> 88/92`, `CANONICAL_OWNER:NONE` unchanged; [UID:0001RC] `hourpane-time-resources` `87/91 -> 89/92`, `CANONICAL_OWNER:NONE` unchanged.
- Live IDA/package evidence checked: active MCP session `b001_selflookpane_0001H7_20260616`, `NexusTK.exe`, image base `0x00400000`, Hex-Rays ready. TextEdit checks covered `sub_58E490` size `0x201`, exact one raw wrapper jump at `0x00498c4a`, no modeled function or xrefs at `0x00498c40`, unique wrapper bytes `55 8B EC 8B 89 0C 01 00 00 5D E9 41 58 0F 00`, current decompiler prototype, Encoder/allocation callees, `"kong"` marker, delimiter writes, and output allocation/copy. BackPane resource checks parsed `E:\2026\Resources\Read_Only\NexusTK\Data\bint1.dat` and `bint2.dat`: `frame.epf` index 78 offset `7716660` size `794928`, `frame.pal` index 79 offset `8511588` size `1056`, and `NPAL5.PAL` index 47 offset `9158767` size `1056`; full all-DAT scan found no `FRAME.EPD`, loose resource search under `E:\2026\Resources` found no standalone `FRAME.*` or `NPAL5.PAL`, executable UTF-16 scan found `FRAME.EPD` literals only in the shipped executable variants, and IDA xrefs tied `FRAME.EPF`/`FRAME.EPD` to `sub_4F7D10` while BackPane paint branches on `byte_66DA97` between `FRAME.PAL` and `NPAL5.PAL`. HourPane resource checks parsed `Time.epf` index 100 offset `15291224` size `10464` and `Time.pal` index 101 offset `15301688` size `1056`; full all-DAT and loose scans found no `TIME.EPD`, executable UTF-16 scan found `TIME.EPD` literals only in executable variants, and IDA xrefs tied `TIME.EPF`/`TIME.PAL`/`TIME.EPD` plus `g_hourFrameTable` to `sub_4CF010`.
- Blocker outcomes: TextEdit `+0x134` is now resolved as the serialized wide-text storage slot using constructor allocation, destructor release, copy helper, and serialization xrefs; `+0x138`, `+0x13c`, `+0x140`, the raw wrapper source method name, and final C++ remain unsafe after checking constructor/destructor/copy, class, file, memory, wrapper, and caller evidence. BackPane resource ownership stays `NONE` because package and IDA evidence prove resource use/provenance but not a source-emitting owner; `FRAME.EPD` payload availability, historical EPF/EPD packaging order, and `NPAL5.PAL` cross-consumer visual semantics remain unresolved. HourPane `g_hourFrameTable` dependency is resolved as HourPane-owned source data with 12 entries `10,11,0..9`; `TIME.EPD` payload availability, visual frame semantics, original table declaration spelling, and EPF/EPD packaging history remain unresolved.
- Validation commands/results: `python .\tools\validator.py --mode file --file by-item\EncodeTextEditState_0058E490.md --apply --lock-timeout -1` -> `ok: 1`; `python .\tools\validator.py --mode file --file by-memory\0x0058e490-0x0058e691.TextEditPaneSerialization.md --apply --lock-timeout -1` -> `ok: 1`; `python .\tools\validator.py --mode file --file by-resource\backpane-background-resources.md --apply --lock-timeout -1` -> `ok: 1`; `python .\tools\validator.py --mode file --file by-resource\hourpane-time-resources.md --apply --lock-timeout -1` -> `ok: 1`; `python .\tools\validator.py --mode file --file by-resource\-coverage-report.md --apply --lock-timeout -1` -> `ok: 1`; `python .\tools\validator.py --mode file --file by-item\-coverage-report.md --apply --lock-timeout -1` -> `ok: 1`.
- Leases used/release status: leased `by-item/EncodeTextEditState_0058E490.md`, `by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md`, `by-resource/backpane-background-resources.md`, `by-resource/hourpane-time-resources.md`, `by-resource/-coverage-report.md`, `by-item/-coverage-report.md`, and this notes file. All A002 leases are to be released immediately after this checkpoint note is written.
- IDA DB changes: none. This pass used read-only lookup/xref/decompile/byte/package/string evidence only; no rename/type/comment/save was safe because remaining names depend on unrecovered source spelling or absent payload evidence.

Supervisor-applied `by-memory/-coverage-report.md` replacement:

Supervisor applied and validated the [UID:0001JN] replacement row on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A002 pending `by-memory/-coverage-report.md` rows remain for `A002-goal2-item-resource-completion-textedit-backpane-hour-20260616-44`.

- Placement context: replace the [UID:0001JN] row in-place inside the TextEditPane core/support area, after the [UID:00030E] `0x00590de0-0x00591180.TextEditPaneOnMouseEvent` row and before the [UID:0001JO] `0x00591300-0x005954b3.TextBoxPaneNoncontiguousAuditMap` row.
- Exact replacement row:
  - [UID:0001JN][0x0058e490-0x0058e691.TextEditPaneSerialization](by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md) 0x0058e490-0x0058e691 | function | TextEditPaneSerialization : reconstructable : 86% : very strong : A002 2026-06-16 item/resource refresh raises to 86/90 and keeps owner/emitter [UID:0000ON][TextEditPane](by-file/TextEditPane.md): active IDA reconfirms exact `0x201` size, one raw wrapper jump at `0x00498c4a`, no modeled function or xrefs at `0x00498c40`, unique wrapper bytes loading `+0x10c`, current decompiler prototype, Encoder/allocation callees, table/list offsets `+0x134`/`+0x138`/`+0x13c`/`+0x140`, proven `+0x134` text-storage role from constructor/destructor/copy support docs, delimiter and `"kong"` marker writes, exact output allocation/copy, and remaining `+0x138`/`+0x13c`/`+0x140` final field-name plus wrapper-method blockers.

## 2026-06-16 Assignment - A002-goal2-item-resource-completion-textedit-backpane-hour-20260616-44

Assigned targets:
- [UID:0000UM] `by-item/EncodeTextEditState_0058E490.md`
- [UID:0001R7] `by-resource/backpane-background-resources.md`
- [UID:0001RC] `by-resource/hourpane-time-resources.md`

Instructions:
- Read and follow `Agent-A002/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven item/resource completion pass from refreshed `project-level/-auto-completion-stats.md`. Raise each target and directly supporting page where evidence supports it, including support docs and coverage rows, without inflating scores beyond the evidence.
- Investigate every listed blocker instead of repeating it. Resolve field/type/global/protocol/helper-name, caller/reachability, ownership, source-placement, split/merge/range, resource provenance, package availability, and final-C++/source-resource blockers where supported; otherwise record the exact IDA/docs/package evidence checked and why the issue remains unsafe.
- Do not defer source-quality blockers to final C++ without investigating them during this evidence pass. The 85/85 gate is a minimum, not a stopping point.
- [UID:0000UM] is a known-owner TextEditPane item. [UID:0001R7] and [UID:0001RC] are resource boundary/provenance pages with `CANONICAL_OWNER:NONE`; do not force ownership unless source/resource packaging evidence supports it. If any target becomes heavy source-structure inference, broad original-layout guessing, or ambiguous owner routing, document the checked evidence and recommend B-agent escalation rather than forcing a route.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply. Non-memory coverage reports may be edited directly only under normal lease rules.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and any exact pending supervisor-owned report rows.

Batch checkpoint:

- Changed files:
  - `by-item/DATEntryRecord.md`
  - `by-item/FriendNameListSyncOpcodes.md`
  - `by-item/LoadImageFrameTable_004D0F50.md`
  - `by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md`
  - `by-item/-coverage-report.md`
  - `by-file/-coverage-report.md`
  - `project-level/-auto-completion-stats.md` was refreshed by validator file-mode validation; the three target item UIDs no longer appear in the low-score stats scan.
  - `tools/validator.ini` was refreshed by validator metadata rebuild.
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score/routing decisions:
  - [UID:0000UC] `DATEntryRecord`: `85/88 -> 86/89`; owner/emitter remain [UID:0000IN] `DATFile`.
  - [UID:0000UP] `FriendNameListSyncOpcodes`: `85/88 -> 86/89`; `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, and blank emitters remain correct for this reviewed protocol/routing item.
  - [UID:0000UY] `LoadImageFrameTable_004D0F50`: `85/88 -> 86/90`; owner/emitter remain [UID:0000K1] `ImageFrameTable`.
  - Support [UID:0002P4] `0x004d0f50-0x004d15c5.LoadImageFrameTable`: `82/88 -> 85/89`; owner/emitter remain [UID:0000K1] `ImageFrameTable`.
  - Support [UID:0000K1] `ImageFrameTable` score unchanged at `89/86`; by-file coverage row corrected stale wording so [UID:0002P5] `DestroyOwnedImageBlock` is no longer described as unresolved cleanup-owner work.
- Live IDA evidence checked:
  - Active MCP session `b001_selflookpane_0001H7_20260616`, `NexusTK.exe`, image base `0x00400000`, Hex-Rays ready.
  - DAT record layout: `lookup_funcs` reconfirmed `0x0049be80` size `0x249`, `0x0049c180` size `0xbb`, `0x0049c720` size `0x2b`, and `0x0049c800` size `0x2c4`. Decompilation reconfirmed `DATFileContainer` stores the mapped count, `mappedView + 4` table pointer, and final-boundary dword from `(entryCount - 1) * 17`; `DATFile::Open`/`OpenByIndex` compute size from `record + 17`; `_DATFileMgr::LoadDATFileIndex` walks all rows, reads names at `record + 4`, skips empty names, and advances by `17`. `rg --files -g '*.DAT' -g '*.dat' E:\NTK\GhidraBridge` found no local DAT archives for physical terminal-row inspection.
  - Friend sync: `lookup_funcs` reconfirmed `sub_507C90` size `0x1176`, raw `0x00514380` as not a function, successor `0x005143c0` size `0xbc`, `sub_53F830` size `0xf1`, and `sub_574E50` size `0x51b`. `xrefs_to` reconfirmed exactly three sender refs (`0x00508b14`, raw `0x005143ad`, `0x0053f8ed`) and three flag refs (`0x00508aff`, raw `0x0051439c`, `0x0053f8dc`). Raw bytes at `0x00514380` reconfirmed the duplicate body and six `0xcc` bytes before `0x005143c0`; sender decompile reconfirmed opcode `119`, base config offset `2691552`, 20 slots, 13-byte records with marker `12`, send-disabled field `this + 240206`, and queue command `8`.
  - ImageFrameTable loader: `lookup_funcs` reconfirmed `0x004d0f50` size `0x675`, no function at `0x004d15c5`, `0x004d15d0` size `0x2c`, and `0x004d1600` size `0x5d`. `xrefs_to 0x004d0f50` reconfirmed 25 direct code refs across eight caller functions. `analyze_function` reported 89 blocks, complexity 40, and 18 callees in the DAT/format/allocation family. Targeted decompilation reconfirmed direct-mode 12-byte header allocation, 8-byte header read, 4-byte record-table offset read, `24 * (count + 1)` record allocation, payload rebasing by `DATFile::GetDataPointer`, and terminal sentinel setup. Byte reads reconfirmed `0x004d15c5-0x004d15d0` and `0x004d15fc-0x004d1600` padding.
- Blocker outcomes:
  - `DATEntryRecord`: field/type name remains documentation-level; no original source spelling or local DAT archive sample proves final declaration name, 13-byte null-termination guarantees, or universal empty-name sentinel use. Code evidence supports the layout and final-boundary cache but not stronger on-disk claims.
  - `FriendNameListSyncOpcodes`: kept non-emitting because the item documents a relationship, while code-bearing behavior remains in MapPane, FriendListDialog, Socket send helper, and the exact global flag. Raw `0x00514380` remains unmodeled/unreferenced; original protocol names for opcode `0x6a` and outbound `0x77` remain unrecovered.
  - `LoadImageFrameTable`: exact range and owner are resolved; no merge with `DestroyOwnedImageBlock` is supported. Final C++ remains blank because table/record type names, field names, prefix/mode names, allocator wrappers, and DAT wrapper source names are still not source-quality. Existing `.rdata` evidence keeps the observed `NECLACE` spelling, but current string-cache search did not recover a stronger source-name signal.
- Validation commands/results:
  - `python .\tools\validator.py --mode file --file by-item\DATEntryRecord.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-item\FriendNameListSyncOpcodes.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-item\LoadImageFrameTable_004D0F50.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x004d0f50-0x004d15c5.LoadImageFrameTable.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-item\-coverage-report.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\-coverage-report.md --apply --lock-timeout -1` -> `ok: 1`.
- Leases used:
  - `by-item/DATEntryRecord.md`
  - `by-item/FriendNameListSyncOpcodes.md`
  - `by-item/LoadImageFrameTable_004D0F50.md`
  - `by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md`
  - `by-item/-coverage-report.md`
  - `by-file/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A002/notes.md`
- IDA DB changes: none. This pass used read-only lookup/xref/decompile/byte/string queries; no rename/type/comment/save was safe because the remaining names depend on broader final source-type and helper-name recovery.
- Release status: all listed A002 leases are to be released immediately after this checkpoint note is written.

Supervisor-applied `by-memory/-coverage-report.md` replacement:

- Supervisor applied and validated the [UID:0002P4] replacement row on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No A002 pending `by-memory/-coverage-report.md` rows remain for `A002-goal2-item-completion-dat-friend-frame-20260616-39`.

## 2026-06-16 Assignment - A002-goal2-item-completion-server-spell-vector-20260616-42

Assigned targets:
- [UID:0000VG] `by-item/ServerSelectHelpers_574510_5745b0.md`
- [UID:0000VH] `by-item/SpellMenuActionButtonState_51d6c0_51e600.md`
- [UID:0000VK] `by-item/VectorGrowArchiveIndex_004E5990.md`

Instructions:
- Read and follow `Agent-A002/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven by-item completion pass from refreshed `project-level/-auto-completion-stats.md`. Raise each target and directly supporting page where evidence supports it, including support docs and coverage rows, without inflating scores beyond the evidence.
- Investigate every listed blocker instead of repeating it. Resolve field/type/global/protocol/helper-name, caller/reachability, ownership, source-placement, split/merge/range, and final-C++ blockers where supported; otherwise record the exact IDA/docs/metadata evidence checked and why the issue remains unsafe.
- Do not defer source-quality blockers to final C++ without investigating them during this evidence pass. The 85/85 gate is a minimum, not a stopping point.
- If any assigned target cannot be brought to or kept at `85/85+`, do additional research before returning; if it still cannot clear the gate, report the evidence and why the score must stay lower.
- These are known-owner item pages: [UID:0000VG] routes to [UID:0000NO][ServerSelectPane](../../../by-file/ServerSelectPane.md), [UID:0000VH] routes to [UID:0000O2][SpellMenuDialogs](../../../by-file/SpellMenuDialogs.md), and [UID:0000VK] routes to [UID:0000LJ][MonsterImageLib](../../../by-file/MonsterImageLib.md). If any target becomes heavy source-structure inference, broad original-layout guessing, or ambiguous shared-owner routing, document the checked evidence and recommend B-agent escalation rather than forcing a route.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply. Non-memory coverage reports may be edited directly only under normal lease rules.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and any exact pending supervisor-owned report rows.

Batch checkpoint:

- Changed files: `by-item/ServerSelectHelpers_574510_5745b0.md`, `by-item/SpellMenuActionButtonState_51d6c0_51e600.md`, `by-item/VectorGrowArchiveIndex_004E5990.md`, `by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md`, `by-item/-coverage-report.md`, validator-owned `project-level/-auto-completion-stats.md`, `tools/validator.ini`, `auto-generated/-ag-item-coverage.md`, and `tools/leaser/Agents/Agent-A002/notes.md`.
- Score/routing decisions: [UID:0000VG] `84/90 -> 86/91` with owner/emitter [UID:0000NO] `ServerSelectPane`; [UID:0000VH] `84/90 -> 86/91` with owner/emitter [UID:0000O2] `SpellMenuDialogs`; [UID:0000VK] `84/90 -> 86/91` with owner/emitter [UID:0000LJ] `MonsterImageLib`; support [UID:0002VF] `84/90 -> 86/91` with owner/emitter [UID:0000LJ] `MonsterImageLib`.
- Live IDA evidence checked: active MCP session `b001_selflookpane_0001H7_20260616`, `NexusTK.exe`, image base `0x00400000`, Hex-Rays ready. ServerSelect checks covered modeled helper sizes, raw non-function starts, action/helper xrefs, raw wrapper disassembly, no raw-start xrefs, no pointer-byte hits, `g_pConfig` offsets verified with `int_convert.py`, and packet byte `0x57`. Spell checks covered exact 61-byte helpers, vtable-only refs, child slot `1` action button, child slot `6` spell list, `+0x108` storage, shared `sub_4F3E20` xrefs, client-list constructor/renderer refs, and negative `ChattingColorListPane` constructor refs. Vector checks covered single `LoadMonsterArchives` caller, constructor reachability, caller fast/slow append split, vector state at `this + 0x10/+0x14/+0x18`, one-caller `0x004e6df0`, helper decompilation, and boundary padding.
- Blocker outcomes: ServerSelect raw wrapper boundary is resolved but not promoted to IDA function metadata because current evidence has no function object, no direct raw-start refs, and no pointer-byte reachability; selected-entry and session/display field names remain behavior-backed. Spell ownership and chat-list rejection are resolved; child constants, list member, shared enabled-count helper, and button virtual names remain source-name blockers. Vector ownership/source placement is resolved as `MonsterImageLib.cpp`; final vector field names, allocation/free helper names, and local-helper versus template-like source shape remain unresolved. No B-agent escalation is needed for this batch.
- Validation commands/results: `python .\tools\validator.py --mode file --file by-item\ServerSelectHelpers_574510_5745b0.md --apply --lock-timeout -1` -> `ok: 1`; `python .\tools\validator.py --mode file --file by-item\SpellMenuActionButtonState_51d6c0_51e600.md --apply --lock-timeout -1` -> `ok: 1`; `python .\tools\validator.py --mode file --file by-item\VectorGrowArchiveIndex_004E5990.md --apply --lock-timeout -1` -> `ok: 1`; `python .\tools\validator.py --mode file --file by-memory\0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md --apply --lock-timeout -1` -> `ok: 1`; `python .\tools\validator.py --mode file --file by-item\-coverage-report.md --apply --lock-timeout -1` -> `ok: 1`.
- Leases used/release status: leased `by-item/ServerSelectHelpers_574510_5745b0.md`, `by-item/SpellMenuActionButtonState_51d6c0_51e600.md`, `by-item/VectorGrowArchiveIndex_004E5990.md`, `by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md`, `by-item/-coverage-report.md`, and this notes file. All A002 leases were released once; this notes-only lease is to be released immediately after this bottom checkpoint is written.
- IDA DB changes: none; this pass used read-only lookup/xref/decompile/disasm/byte searches only.

Supervisor-applied `by-memory/-coverage-report.md` replacement:

Supervisor applied and validated this duplicate [UID:0002VF] replacement row on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. This duplicate pending marker is stale/cleared.

- Placement context: replace the current [UID:0002VF] row in-place under [UID:00017C][0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster](../../../by-memory/0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster.md), after the [UID:0002JN] `0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables` row and before the [UID:00017D] `0x004db010-0x004db0f7.MonsterImageLibDestructor` row.
  - [UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md) 0x004e5990-0x004e5a62 | vector grow helper | VectorGrowArchiveIndex : reconstructable : 86% : very strong : Exact MonsterImageLib archive-index vector grow helper; A002 2026-06-16 live IDA refresh reconfirms one `LoadMonsterArchives` caller at `0x004dbd8f`, constructor reachability through `0x004daff5`, caller fast/slow append split, vector state at `this + 0x10/+0x14/+0x18`, one-caller storage-replacement helper `0x004e6df0`, allocation/memmove/error callees, boundary padding, owner/emitter route, and remaining final field/helper-name blockers.

## 2026-06-16 Assignment - A002-goal2-resource-provenance-userstatus-startuplogo-forcedinform-20260616-48

Assigned targets:
- [UID:0001RS] `by-resource/user-status-resources.md`
- [UID:0001RN] `by-resource/startup-logo-media.md`
- [UID:0001RB] `by-resource/forced-inform-message-resources.md`

Instructions:
- Read and follow `Agent-A002/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 resource provenance/source-resource boundary pass from refreshed `project-level/-auto-completion-stats.md`. Raise each target and directly supporting page where evidence supports it, including support docs and coverage rows, without inflating scores beyond the evidence.
- Refresh package/resource evidence, consumer xrefs, source/resource boundaries, shared-palette/helper ownership caveats, missing payload status, frame/layout semantics, and final source-resource blockers instead of repeating existing blockers.
- If any target becomes heavy original-source ownership/source-structure inference rather than resource evidence refresh, document the checked evidence and recommend B-agent escalation rather than forcing a conclusion.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and exact pending supervisor-owned report rows.

Placement note: the following class-confidence checkpoint was inserted under this older resource assignment by mistake during the 2026-06-16 notes update. The same checkpoint is re-recorded under the correct `A002-goal2-class-confidence-hour-icons-maptile-message-20260616-58` section below.

Batch checkpoint:

- Changed files:
  - `by-class/HourPane.md`
  - `by-class/IconsPane.md`
  - `by-class/MapTileImageLib.md`
  - `by-class/MessageShowPane.md`
  - `by-class/-coverage-report.md`
  - Validator-owned/projected support: `project-level/-auto-completion-stats.md` and `tools/validator.ini` refreshed during scoped validator passes.
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score/routing decisions:
  - [UID:000068] `HourPane`: `85/85 -> 86/88`; owner/emitter remains [UID:0000JX] `HourPane`.
  - [UID:00006B] `IconsPane`: `85/85 -> 86/88`; owner/emitter remains [UID:0000JZ] `IconsPane`; stale by-class coverage row corrected from `82%` to `86%`.
  - [UID:00007T] `MapTileImageLib`: `85/85 -> 86/88`; owner/emitter remains [UID:0000L5] `MapTileImageLib`.
  - [UID:000087] `MessageShowPane`: `85/85 -> 86/88`; owner/emitter remains [UID:0000LB] `MessageShowPane`.
- Evidence checked:
  - Active IDA MCP session `b001_mappane_0001AW_20260616`, `NexusTK.exe`, Hex-Rays ready. Used read-only `idb_list`, `lookup_funcs`, `xrefs_to`, `analyze_function`, `callees`, `insn_query`, and `get_bytes`.
  - `HourPane`: reconfirmed exact method starts, four `g_pHourPane` refs, three vtable-store triads, server-hour update slot behavior, `TIME.EPF`/`TIME.PAL` versus `TIME.EPD` paint branch, and `word_66DB04` / `g_hourFrameTable` frame lookup.
  - `IconsPane`: reconfirmed exact method/destructor starts, six `g_pIconsPane` refs, three vtable-store triads, OnMouseEvent helper calls, and raw dispatch bytes at `0x004cf8e0-0x004cf974` padded by `0xcc` before/after.
  - `MapTileImageLib`: reconfirmed constructor/destructor/draw/helper/singleton-clear/scalar-destructor function objects, startup-only constructor caller, constructor-only metadata helper caller, vtable-only scalar destructor reference, ten `g_pMapTileImageLib` refs, and four `DrawTile` code xrefs including one raw/no-function caller at `0x0050c3d7`.
  - `MessageShowPane`: reconfirmed exact constructor/destructor/text-builder/wrapped-text/EH-clear/thunk/scalar-destructor starts, eight `g_pMessageShowPane` refs, packet-handler constructor and wrapped-text callers, and MessageShowPane vtable store refs through `0x0061fa4c`, `0x0061fa98`, and `0x0061fac8`.
  - Direct support docs checked but not edited: the four by-file parents, target singleton globals, HourPane/Icon resource pages, MapTile layout/vtable/record pages, MessageShow read-only/vtable data pages, and the action-helper/global support around `0x005a4db0`-`0x005a5a80`.
- Blocker outcomes:
  - Resolved current low-confidence evidence gaps for method boundaries, singleton refs, vtable refs, resource/data links, and support coverage-row stale text.
  - `HourPane` remaining blockers are real: current IDA/docs do not prove the inherited pane cleanup source name, the packet/interface name for the update virtual, or final field names for `+0x44` draw-region state and `+0xf8` current hour.
  - `IconsPane` remaining blockers are real: action helper callees are shared across IconsPane/TabPane/UserPane/MapPane contexts, and the raw dispatch body is executable/switch-shaped but still has no IDA function object, direct caller, or pointer-byte evidence.
  - `MapTileImageLib` remaining blockers are real: IDA proves behavior/layout but not final source-quality names for metadata/record fields, record flag semantics, helper declarations, or exact original folder.
  - `MessageShowPane` remaining blockers are real: current evidence proves class/vtable/singleton/packet reachability but not standalone `MessageShowPane.cpp` versus compact `MessageDialogs.cpp`, inherited base/interface names, or the final text-builder helper name.
- Validation commands/results:
  - `python .\tools\validator.py --mode file --file by-class\HourPane.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\IconsPane.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\MapTileImageLib.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\MessageShowPane.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --lock-timeout -1` -> `ok: 1`.
  - A compact rerun of the same five validators also returned `ok: 1` for each file.
- Leases used/release status:
  - Leased `by-class/HourPane.md`, `by-class/IconsPane.md`, `by-class/MapTileImageLib.md`, `by-class/MessageShowPane.md`, `by-class/-coverage-report.md`, and `tools/leaser/Agents/Agent-A002/notes.md`.
  - Release command for the five by-class paths reported `Rejected[No active lease]` for each path because the short leases had already expired during validation/checkpointing.
  - Follow-up `current_leases.md` showed no active A002 leases for the edited by-class files. Temporary notes-only placement-correction leases were acquired and released successfully after recording this status.
- IDA DB changes: none. No IDA renames, comments, type changes, function promotions, or saves were made.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: none. No by-memory documentation page was changed in this batch, so no shared memory coverage replacement/insert/delete rows are pending.

Batch checkpoint:

- Note: this detailed checkpoint belongs to `A002-goal2-memory-completion-midi-source-core-20260616-54`. It was accidentally inserted above the source-core assignment header; the correct-placement marker under the source-core assignment below points back to this block for the exact pending rows and validation details.
- Changed files:
  - `by-memory/0x00526ce0-0x00526d9a.MidiTrackBufferRefill.md`
  - `by-memory/0x00526da0-0x00526f09.MidiTrackBufferPrimeReset.md`
  - `by-memory/0x00526f10-0x00526f57.MidiSourceOpenHelper.md`
  - `by-memory/0x00526f60-0x00526f97.MidiSourceCloseHelper.md`
  - `by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md`
  - `by-file/MidiPlayer.md`
  - `by-file/-coverage-report.md`
  - `by-global/WideApiDispatchTable.md`
  - Validator-owned `project-level/-auto-completion-stats.md` and `tools/validator.ini` were refreshed by scoped validator file-mode passes.
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score/routing decisions:
  - [UID:0002BX] `MidiTrackBufferRefill`: `80/88 -> 85/90`; owner/emitter remains [UID:0000LD] `MidiPlayer`. C++ remains blank because this is still a raw non-function with no entry xrefs and no source-quality track/context type.
  - [UID:0002BY] `MidiTrackBufferPrimeReset`: `80/88 -> 86/90`; owner/emitter remains [UID:0000LD] `MidiPlayer`. C++ remains blank pending final helper/context and 40-byte track-record declarations.
  - [UID:0002BZ] `MidiSourceOpenHelper`: `80/88 -> 85/90`; owner/emitter remains [UID:0000LD] `MidiPlayer`. The `dword_69BE34` role is resolved to the wide API dispatch table's startup-installed `CreateFileW` slot, but the raw helper declaration and adapter/context types remain provisional.
  - [UID:0002C0] `MidiSourceCloseHelper`: `80/88 -> 85/90`; owner/emitter remains [UID:0000LD] `MidiPlayer`. C++ remains blank because this is still a raw non-function and adapter validation/close slot names are not source-quality.
  - Direct support [UID:00023B] `MidiFileReaderAndSMFParserHelpers`: `86/91 -> 87/91`; owner/emitter remains [UID:0000LD] `MidiPlayer`.
  - Direct support [UID:0000LD] `MidiPlayer`: `86/89 -> 87/89`; `NexusTK/audio/` placement and `SoundManager` exclusion remain unchanged.
  - Direct support [UID:0000TQ] `WideApiDispatchTable`: score unchanged `90/86`; added exact `0x0069be34`/`CreateFileW` slot row and initializer evidence.
- Evidence checked:
  - Active IDA MCP session `b001_mappane_0001AW_20260616`, `NexusTK.exe.i64`, image base `0x00400000`, Hex-Rays ready; used `server_health`, `lookup_funcs`, `xrefs_to`, `func_profile`, `callees`, `insn_query`, `get_bytes`, `decompile`, `type_query`, `search_structs`, and `get_global_value` read-only.
  - `lookup_funcs` reconfirmed `0x00526ce0`, `0x00526f10`, and `0x00526f60` are not function objects; `0x00526da0` is modeled as `sub_526DA0`, size `0x169`; `0x00527000`, `0x005271b0`, and `0x005273a0` remain modeled neighbors.
  - `xrefs_to` found no entry xrefs for `0x00526ce0`, `0x00526f10`, or `0x00526f60`; [UID:0002BY] has one direct caller at `0x005271fc` inside [UID:0002C6] `MidiStreamBufferFillHelper`.
  - `insn_query` and `get_bytes` reconfirmed full raw bodies and `0xcc` padding for `0x00526ce0-0x00526d9a`, `0x00526f10-0x00526f57`, and `0x00526f60-0x00526f97`, plus padding around `0x00526da0-0x00526f09`.
  - Current `sub_526DA0` decompilation confirms `this+0x0c` track count, `this+0x10` track table, 40-byte track entries, `min(trackLength, 0x400)` initial read, field reset/update map, empty-track flagging, first-delta VLQ decode through `0x00526bb0`, and seek-back to `trackStart + trackLength`. The raw refill helper matches the same field roles for buffer base/cursor/count/source offset/remaining bytes.
  - Raw and decompiled bodies confirm `this+0x14` adapter-active flag, adapter/source subobject `this+0x18`, Win32 handle `this+0x2c`, adapter virtual seek/tell/read/open/close slots, and Win32 `SetFilePointer`/`ReadFile`/`CloseHandle` fallback.
  - `xrefs_to 0x0069be34` reports the initializer write at `0x0041a2f8`, MIDI source-open read at `0x00526f49`, SMF document-loader read at `0x00527400`, and broader file-open consumers. `insn_query 0x0041a2d0-0x0041a320` shows `0x0041a2f3: mov eax, ds:CreateFileW` followed by `0x0041a2f8: mov dword ptr unk_69BE34, eax`; `get_global_value 0x0069be34` reads `0x0` in the static image, consistent with startup-installed dispatch storage.
  - `xrefs_to 0x0049c540` reports this raw close helper, the raw size/ready helper, `MidiDocumentRelease`, and the SMF document loader. `func_profile 0x0049c540` shows an 8-byte helper with this MIDI source/document caller set in the current check; role is supported, but final name is not.
  - IDA `type_query`/`search_structs` for `Midi`, `MIDI`, `SMF`, and `Track`, plus docs searches through `by-type`, found no project-defined MIDI document, source adapter, SMF, or 40-byte track-record type. Only WinMM `midihdr_tag` and unrelated Win32 `tagTRACKMOUSEEVENT` matched. No source-path evidence proves `MidiPlayer.cpp` versus an adjacent private MIDI document/parser source.
- Blocker outcomes:
  - Resolved current function/no-function status, exact bounds, callers/xrefs, raw disassembly/decompilation, padding, adapter/Win32 paths, track-record behavior, `CreateFileW` dispatch-slot role, and direct owner/emitter route through [UID:0000LD] `MidiPlayer`.
  - Remaining blockers are real and documented: three raw starts still have no IDA function objects or entry xrefs; source adapter/context type, MIDI document type, 40-byte track-record declaration/field names, adapter-validation helper name, raw helper declarations, and original source-file split have no recovered source/type evidence. No B-agent escalation needed yet because owner/source family is clear; a future B pass would only be useful for final source-layout/type reconstruction.
- Validation commands/results:
  - `python .\tools\validator.py --mode file --file by-memory\0x00526ce0-0x00526d9a.MidiTrackBufferRefill.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00526da0-0x00526f09.MidiTrackBufferPrimeReset.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00526f10-0x00526f57.MidiSourceOpenHelper.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00526f60-0x00526f97.MidiSourceCloseHelper.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\MidiPlayer.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\-coverage-report.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-global\WideApiDispatchTable.md --apply --lock-timeout -1` -> `ok: 1`.
- Leases used/release status:
  - Leased `by-memory/0x00526ce0-0x00526d9a.MidiTrackBufferRefill.md`, `by-memory/0x00526da0-0x00526f09.MidiTrackBufferPrimeReset.md`, `by-memory/0x00526f10-0x00526f57.MidiSourceOpenHelper.md`, `by-memory/0x00526f60-0x00526f97.MidiSourceCloseHelper.md`, `by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md`, `by-file/MidiPlayer.md`, `by-file/-coverage-report.md`, `by-global/WideApiDispatchTable.md`, and `tools/leaser/Agents/Agent-A002/notes.md`.
  - These short leases expired during validation; follow-up `current_leases.md` showed no active A002 leases. A notes-only lease was acquired for the corrected bottom checkpoint and released successfully after this update.
- IDA DB changes: none. No IDA renames, comments, type declarations, or saves were made because the remaining names/source splits are not source-quality yet.
- Pending supervisor-owned `by-memory/-coverage-report.md` replacements:
  - Placement context: replace the existing [UID:00023B] aggregate row under the `0x0052664b-0x00526650` padding row. Replace the existing [UID:0002BX], [UID:0002BY], [UID:0002BZ], and [UID:0002C0] child rows under that aggregate. Keep sibling rows unchanged.
  - Replacement row for [UID:00023B]:
    `    - [UID:00023B][0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers](by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md) 0x00526650-0x005270d5 | helper island | MidiFileReaderAndSMFParserHelpers : reconstructable : 87% : strong : MIDI file/adapter read, SMF track parsing, and WinMM stream-event encoding helper island split into exact child range pages and attached to `MidiPlayer.cpp`; 2026-06-16 live IDA reconfirms reader/source-core boundaries, call sites, decompilation/raw disassembly, 0x400-byte track buffering, VLQ/track-prime behavior, CreateFileW dispatch-table slot, adapter validation, component-internal grouping, and padding, while raw starts and final reader/document/track/source-adapter names remain open.`
  - Replacement row for [UID:0002BX]:
    `        - [UID:0002BX][0x00526ce0-0x00526d9a.MidiTrackBufferRefill](by-memory/0x00526ce0-0x00526d9a.MidiTrackBufferRefill.md) 0x00526ce0-0x00526d9a | raw function-shaped body | MidiTrackBufferRefill : reconstructable : 85% : strong : Raw MIDI track-buffer refill helper; current IDA confirms exact raw body/padding, no function object or entry xrefs, adapter-backed and Win32 SetFilePointer/ReadFile paths, 0x400-byte refill clamp, track record cursor/count/remaining updates, and binary success/failure returns.`
  - Replacement row for [UID:0002BY]:
    `        - [UID:0002BY][0x00526da0-0x00526f09.MidiTrackBufferPrimeReset](by-memory/0x00526da0-0x00526f09.MidiTrackBufferPrimeReset.md) 0x00526da0-0x00526f09 | function | MidiTrackBufferPrimeReset : reconstructable : 86% : strong : Track-buffer prime/reset function with one stream-fill caller at 0x005271fc; current decompilation confirms 40-byte track iteration, adapter/Win32 seek-read paths, 0x400 initial read clamp, field resets, empty-track flagging, first-delta VLQ decode, seek-back behavior, and padding.`
  - Replacement row for [UID:0002BZ]:
    `        - [UID:0002BZ][0x00526f10-0x00526f57.MidiSourceOpenHelper](by-memory/0x00526f10-0x00526f57.MidiSourceOpenHelper.md) 0x00526f10-0x00526f57 | raw function-shaped body | MidiSourceOpenHelper : reconstructable : 85% : strong : Raw MIDI source open helper; current IDA confirms exact raw bytes/padding, no function object or entry xrefs, adapter virtual open slot +0x0c, Win32 CreateFileW dispatch-table slot at 0x0069be34/dword_69BE34, open argument order, and handle sentinel storage.`
  - Replacement row for [UID:0002C0]:
    `        - [UID:0002C0][0x00526f60-0x00526f97.MidiSourceCloseHelper](by-memory/0x00526f60-0x00526f97.MidiSourceCloseHelper.md) 0x00526f60-0x00526f97 | raw function-shaped body | MidiSourceCloseHelper : reconstructable : 85% : strong : Raw MIDI source close helper; current IDA confirms exact raw bytes/padding, no function object or entry xrefs, adapter validation through sub_49C540 and virtual close slot +0x10, Win32 CloseHandle path, and handle reset to -1.`

Batch checkpoint:

- Changed files:
  - `by-memory/0x00526ce0-0x00526d9a.MidiTrackBufferRefill.md`
  - `by-memory/0x00526da0-0x00526f09.MidiTrackBufferPrimeReset.md`
  - `by-memory/0x00526f10-0x00526f57.MidiSourceOpenHelper.md`
  - `by-memory/0x00526f60-0x00526f97.MidiSourceCloseHelper.md`
  - `by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md`
  - `by-file/MidiPlayer.md`
  - `by-file/-coverage-report.md`
  - `by-global/WideApiDispatchTable.md`
  - Validator-owned `project-level/-auto-completion-stats.md` and `tools/validator.ini` were refreshed by scoped validator file-mode passes.
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score/routing decisions:
  - [UID:0002BX] `MidiTrackBufferRefill`: `80/88 -> 85/90`; owner/emitter remains [UID:0000LD] `MidiPlayer`. C++ remains blank because this is still a raw non-function with no entry xrefs and no source-quality track/context type.
  - [UID:0002BY] `MidiTrackBufferPrimeReset`: `80/88 -> 86/90`; owner/emitter remains [UID:0000LD] `MidiPlayer`. C++ remains blank pending final helper/context and 40-byte track-record declarations.
  - [UID:0002BZ] `MidiSourceOpenHelper`: `80/88 -> 85/90`; owner/emitter remains [UID:0000LD] `MidiPlayer`. The `dword_69BE34` role is resolved to the wide API dispatch table's startup-installed `CreateFileW` slot, but the raw helper declaration and adapter/context types remain provisional.
  - [UID:0002C0] `MidiSourceCloseHelper`: `80/88 -> 85/90`; owner/emitter remains [UID:0000LD] `MidiPlayer`. C++ remains blank because this is still a raw non-function and adapter validation/close slot names are not source-quality.
  - Direct support [UID:00023B] `MidiFileReaderAndSMFParserHelpers`: `86/91 -> 87/91`; owner/emitter remains [UID:0000LD] `MidiPlayer`.
  - Direct support [UID:0000LD] `MidiPlayer`: `86/89 -> 87/89`; `NexusTK/audio/` placement and `SoundManager` exclusion remain unchanged.
  - Direct support [UID:0000TQ] `WideApiDispatchTable`: score unchanged `90/86`; added exact `0x0069be34`/`CreateFileW` slot row and initializer evidence.
- Evidence checked:
  - Active IDA MCP session `b001_mappane_0001AW_20260616`, `NexusTK.exe.i64`, image base `0x00400000`, Hex-Rays ready; used `server_health`, `lookup_funcs`, `xrefs_to`, `func_profile`, `callees`, `insn_query`, `get_bytes`, `decompile`, `type_query`, `search_structs`, and `get_global_value` read-only.
  - Function/raw status: `lookup_funcs` reconfirmed `0x00526ce0`, `0x00526f10`, and `0x00526f60` are not function objects; `0x00526da0` is modeled as `sub_526DA0`, size `0x169`; `0x00527000`, `0x005271b0`, and `0x005273a0` remain modeled neighbors.
  - Reachability: `xrefs_to` found no entry xrefs for `0x00526ce0`, `0x00526f10`, or `0x00526f60`; [UID:0002BY] has one direct caller at `0x005271fc` inside [UID:0002C6] `MidiStreamBufferFillHelper`.
  - Raw disassembly/bytes: `insn_query` and `get_bytes` reconfirmed full raw bodies and `0xcc` padding for `0x00526ce0-0x00526d9a`, `0x00526f10-0x00526f57`, and `0x00526f60-0x00526f97`, plus padding around `0x00526da0-0x00526f09`.
  - Track behavior: current `sub_526DA0` decompilation confirms `this+0x0c` track count, `this+0x10` track table, 40-byte track entries, `min(trackLength, 0x400)` initial read, field reset/update map, empty-track flagging, first-delta VLQ decode through `0x00526bb0`, and seek-back to `trackStart + trackLength`. The raw refill helper matches the same field roles for buffer base/cursor/count/source offset/remaining bytes.
  - Source/adapter paths: raw and decompiled bodies confirm `this+0x14` adapter-active flag, adapter/source subobject `this+0x18`, Win32 handle `this+0x2c`, adapter virtual seek/tell/read/open/close slots, and Win32 `SetFilePointer`/`ReadFile`/`CloseHandle` fallback.
  - Win32 wrapper/global blocker: `xrefs_to 0x0069be34` reports the initializer write at `0x0041a2f8`, MIDI source-open read at `0x00526f49`, SMF document-loader read at `0x00527400`, and broader file-open consumers. `insn_query 0x0041a2d0-0x0041a320` shows `0x0041a2f3: mov eax, ds:CreateFileW` followed by `0x0041a2f8: mov dword ptr unk_69BE34, eax`; `get_global_value 0x0069be34` reads `0x0` in the static image, consistent with startup-installed dispatch storage.
  - Adapter validation blocker: `xrefs_to 0x0049c540` reports this raw close helper, the raw size/ready helper, `MidiDocumentRelease`, and the SMF document loader. `func_profile 0x0049c540` shows an 8-byte helper with this MIDI source/document caller set in the current check; role is supported, but final name is not.
  - Type/name/source split checks: IDA `type_query`/`search_structs` for `Midi`, `MIDI`, `SMF`, and `Track`, plus docs searches through `by-type`, found no project-defined MIDI document, source adapter, SMF, or 40-byte track-record type. Only WinMM `midihdr_tag` and unrelated Win32 `tagTRACKMOUSEEVENT` matched. No source-path evidence proves `MidiPlayer.cpp` versus an adjacent private MIDI document/parser source.
- Blocker outcomes:
  - Resolved current function/no-function status, exact bounds, callers/xrefs, raw disassembly/decompilation, padding, adapter/Win32 paths, track-record behavior, `CreateFileW` dispatch-slot role, and direct owner/emitter route through [UID:0000LD] `MidiPlayer`.
  - Remaining blockers are real and documented: three raw starts still have no IDA function objects or entry xrefs; source adapter/context type, MIDI document type, 40-byte track-record declaration/field names, adapter-validation helper name, raw helper declarations, and original source-file split have no recovered source/type evidence. No B-agent escalation needed yet because owner/source family is clear; a future B pass would only be useful for final source-layout/type reconstruction.
- Validation commands/results:
  - `python .\tools\validator.py --mode file --file by-memory\0x00526ce0-0x00526d9a.MidiTrackBufferRefill.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00526da0-0x00526f09.MidiTrackBufferPrimeReset.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00526f10-0x00526f57.MidiSourceOpenHelper.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00526f60-0x00526f97.MidiSourceCloseHelper.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\MidiPlayer.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\-coverage-report.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-global\WideApiDispatchTable.md --apply --lock-timeout -1` -> `ok: 1`.
- Leases used/release status:
  - Leased `by-memory/0x00526ce0-0x00526d9a.MidiTrackBufferRefill.md`, `by-memory/0x00526da0-0x00526f09.MidiTrackBufferPrimeReset.md`, `by-memory/0x00526f10-0x00526f57.MidiSourceOpenHelper.md`, `by-memory/0x00526f60-0x00526f97.MidiSourceCloseHelper.md`, `by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md`, `by-file/MidiPlayer.md`, `by-file/-coverage-report.md`, `by-global/WideApiDispatchTable.md`, and `tools/leaser/Agents/Agent-A002/notes.md`.
  - These short leases expired during validation; follow-up `current_leases.md` showed no active A002 leases. A notes-only lease was acquired for this checkpoint entry and released successfully after the final note update.
- IDA DB changes: none. No IDA renames, comments, type declarations, or saves were made because the remaining names/source splits are not source-quality yet.
- Pending supervisor-owned `by-memory/-coverage-report.md` replacements:
  - Placement context: replace the existing [UID:00023B] aggregate row under the `0x0052664b-0x00526650` padding row. Replace the existing [UID:0002BX], [UID:0002BY], [UID:0002BZ], and [UID:0002C0] child rows under that aggregate. Keep sibling rows unchanged.
  - Replacement row for [UID:00023B]:
    `    - [UID:00023B][0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers](by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md) 0x00526650-0x005270d5 | helper island | MidiFileReaderAndSMFParserHelpers : reconstructable : 87% : strong : MIDI file/adapter read, SMF track parsing, and WinMM stream-event encoding helper island split into exact child range pages and attached to `MidiPlayer.cpp`; 2026-06-16 live IDA reconfirms reader/source-core boundaries, call sites, decompilation/raw disassembly, 0x400-byte track buffering, VLQ/track-prime behavior, CreateFileW dispatch-table slot, adapter validation, component-internal grouping, and padding, while raw starts and final reader/document/track/source-adapter names remain open.`
  - Replacement row for [UID:0002BX]:
    `        - [UID:0002BX][0x00526ce0-0x00526d9a.MidiTrackBufferRefill](by-memory/0x00526ce0-0x00526d9a.MidiTrackBufferRefill.md) 0x00526ce0-0x00526d9a | raw function-shaped body | MidiTrackBufferRefill : reconstructable : 85% : strong : Raw MIDI track-buffer refill helper; current IDA confirms exact raw body/padding, no function object or entry xrefs, adapter-backed and Win32 SetFilePointer/ReadFile paths, 0x400-byte refill clamp, track record cursor/count/remaining updates, and binary success/failure returns.`
  - Replacement row for [UID:0002BY]:
    `        - [UID:0002BY][0x00526da0-0x00526f09.MidiTrackBufferPrimeReset](by-memory/0x00526da0-0x00526f09.MidiTrackBufferPrimeReset.md) 0x00526da0-0x00526f09 | function | MidiTrackBufferPrimeReset : reconstructable : 86% : strong : Track-buffer prime/reset function with one stream-fill caller at 0x005271fc; current decompilation confirms 40-byte track iteration, adapter/Win32 seek-read paths, 0x400 initial read clamp, field resets, empty-track flagging, first-delta VLQ decode, seek-back behavior, and padding.`
  - Replacement row for [UID:0002BZ]:
    `        - [UID:0002BZ][0x00526f10-0x00526f57.MidiSourceOpenHelper](by-memory/0x00526f10-0x00526f57.MidiSourceOpenHelper.md) 0x00526f10-0x00526f57 | raw function-shaped body | MidiSourceOpenHelper : reconstructable : 85% : strong : Raw MIDI source open helper; current IDA confirms exact raw bytes/padding, no function object or entry xrefs, adapter virtual open slot +0x0c, Win32 CreateFileW dispatch-table slot at 0x0069be34/dword_69BE34, open argument order, and handle sentinel storage.`
  - Replacement row for [UID:0002C0]:
    `        - [UID:0002C0][0x00526f60-0x00526f97.MidiSourceCloseHelper](by-memory/0x00526f60-0x00526f97.MidiSourceCloseHelper.md) 0x00526f60-0x00526f97 | raw function-shaped body | MidiSourceCloseHelper : reconstructable : 85% : strong : Raw MIDI source close helper; current IDA confirms exact raw bytes/padding, no function object or entry xrefs, adapter validation through sub_49C540 and virtual close slot +0x10, Win32 CloseHandle path, and handle reset to -1.`

Batch checkpoint:

- Changed files:
  - `by-resource/user-status-resources.md`
  - `by-resource/startup-logo-media.md`
  - `by-resource/forced-inform-message-resources.md`
  - `by-resource/-coverage-report.md` (including the summary date refresh to `2026-06-16`)
  - Validator-owned `project-level/-auto-completion-stats.md` and `tools/validator.ini` were refreshed by scoped validator file-mode passes.
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score/routing decisions:
  - [UID:0001RS] `user-status-resources`: `88/90 -> 90/92`; `CANONICAL_OWNER:NONE` remains correct because the page documents a shared resource family consumed by UserStatusPane variants plus shared helper/palette paths, not a single source-owned declaration.
  - [UID:0001RN] `startup-logo-media`: `86/93 -> 87/94`; `CANONICAL_OWNER:NONE` remains correct because the page documents optional loose/media payload contracts shared by StartupLogoPanes and VideoPlayerPane support, and no source-owned asset declaration or package owner is proven.
  - [UID:0001RB] `forced-inform-message-resources`: `87/92 -> 88/93`; `CANONICAL_OWNER:0000JJ` remains correct because all `DLGSTAFF.*` xrefs are constructor-local to ForcedInformMessageDialog, while `NPAL8.PAL` remains shared.
  - No by-memory coverage rows are pending for this batch; `by-memory/-coverage-report.md` was not edited.
- Evidence checked:
  - Active IDA MCP session `b001_mappane_0001AW_20260616`, `NexusTK.exe`, image base current worker. `lookup_funcs` reconfirmed UserStatusPane constructors/paint paths (`0x005b83b0`, `0x005b8c70`, `0x005bab00`, `0x005baf80`, `0x005bda40`, `0x005be520`), BAR helper families (`0x0041ba40`, `0x0056ce50`), startup-logo functions (`0x004f4c10`, `0x004f53b0`, `0x004f5710`, `0x004f59d0`, `0x004f5ae0`, `0x004f5fb0`, `0x005c0110`), and forced-inform functions (`0x00587bb0`, `0x00588080`, `0x00588110`, `0x00588160`, `0x0058abf0`).
  - IDA `xrefs_to` reconfirmed the user-status string fanout: `9X11FONT.BIN` 9 refs; `USERSTAT.EPF` 1; `USERSTAT.EPD`/`NATION.EPD`/`TOTEM.EPD`/`CLASS.EPD` 2 each; `BAR.EPD` 8; `NPAL7.PAL` 10; `NPAL5.PAL` 4; `ITEMINV.PAL` 12; `COMMA.EPF` 3; `COMMA.PAL` 7; `BAR.EPF`/`BAR.PAL` 21 each across compact status and two helper families.
  - IDA `xrefs_to` reconfirmed startup-logo literals: `NEXON.LGO` only in `sub_4F5FB0`, `LOGO.PAK` and `LOGO.PAD` only in `sub_4F5710`; filtered decompilation reconfirmed path-existence gating, `_AUTOBUF` payload read, first segment pointer math, and memory-backed Bink open.
  - IDA `xrefs_to` reconfirmed forced-inform literals: `DLGSTAFF.PAL` one constructor ref, `DLGSTAFF.EPF` two constructor refs, `DLGSTAFF.EPD` two constructor refs, and `NPAL8.PAL` 60 total refs with one forced-inform constructor hit.
  - Fixed DAT table parsing across `E:\2026\Resources\Read_Only\NexusTK\Data` found current payloads for user-status `9X11FONT.BIN`, `USERSTAT.EPF`, `BAR.EPF`/`.PAL`, `COMMA.EPF`/`.PAL`, `ITEMINV.PAL`, `NPAL5.PAL`, `NPAL7.PAL`; forced-inform `DLGSTAFF.EPF`/`.PAL` and `NPAL8.PAL`; and found no DAT entries for startup `NEXON.LGO`, `LOGO.PAK`, `LOGO.PAD`, user-status legacy `.EPD` assets, or `DLGSTAFF.EPD`.
  - Exact loose-file search under `E:\2026\Resources` found no matching loose files for the audited target names. UTF-16 executable scans of `NexusTK.exe`, `NexusTK2.exe`, and `NexusTK_local.exe` reconfirmed executable-literal-only status for missing payload operands, including startup media and legacy `.EPD` resources.
- Blocker outcomes:
  - User-status: resolved current package locations and source-visible frame roles for packaged EPF/PAL/BIN resources and several frame indices. Remaining blockers are real: legacy `.EPD` payloads are absent from the audited package, `BAR.EPF`/`.PAL` remain shared with helper families, and visual frame/palette-slot identity still needs asset rendering or another package source.
  - Startup-logo: current IDA and package checks strengthen the runtime contract and missing-payload classification. Remaining blocker is real: no current DAT entry, loose file, or installer payload was found for `NEXON.LGO`, `LOGO.PAK`, or `LOGO.PAD`, so source-resource provenance cannot be completed safely.
  - Forced-inform: current constructor/xref/package checks resolve EPF/palette provenance and keep ForcedInformMessageDialog as owner for the `DLGSTAFF.*` source literals. Remaining blockers are real: `DLGSTAFF.EPD` payload is absent from current package/loose tree, the EPF/EPD selector still lacks a source-quality field/global name, and `NPAL8.PAL` ownership remains shared.
- Validation commands/results:
  - `python .\tools\validator.py --mode file --file by-resource\user-status-resources.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-resource\startup-logo-media.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-resource\forced-inform-message-resources.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-resource\-coverage-report.md --apply --lock-timeout -1` -> `ok: 1`.
  - Summary-date follow-up: `python .\tools\validator.py --mode file --file by-resource\-coverage-report.md --apply --lock-timeout -1` -> `ok: 1`.
- Leases used/release status:
  - `by-resource/user-status-resources.md`
  - `by-resource/startup-logo-media.md`
  - `by-resource/forced-inform-message-resources.md`
  - `by-resource/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A002/notes.md`
  - Release check after checkpoint: the first unlease attempt reported `Rejected[No active lease]` for each listed lease because the short leases had already expired; `current_leases.md` then showed no active leases.
- IDA DB changes: none. This pass used read-only lookup/xref/decompile/package/file-system evidence only; no IDA renames, comments, type changes, or saves were safe because the remaining names are source-resource/package blockers rather than IDA-local metadata fixes.

## 2026-06-16 Assignment - A002-goal2-file-completion-stdio-textfilter-datarchive-20260616-49

Assigned targets:
- [UID:0000O9] `by-file/StdioFile.md`
- [UID:0000OO] `by-file/TextFilter.md`
- [UID:0000IM] `by-file/DATArchive.md`

Instructions:
- Read and follow `Agent-A002/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven file/source-boundary completion pass from refreshed `project-level/-auto-completion-stats.md`. Raise each target and directly supporting page where evidence supports it, including support docs and coverage rows, without inflating scores beyond the evidence.
- Refresh source-root/folder evidence, exact method/global/type links, owner/emitter and source-boundary decisions, helper/source placement, final declaration/helper-name blockers, and support docs/reports.
- Investigate every listed blocker instead of repeating it. Resolve blockers where supported; otherwise record exact IDA/docs/metadata evidence checked and why the issue remains unsafe.
- If any target becomes heavy original-source structure inference beyond file-boundary evidence refresh, recommend B-agent escalation rather than forcing a conclusion.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and exact pending supervisor-owned report rows.

Batch checkpoint:

- Changed files:
  - `by-class/HourPane.md`
  - `by-class/IconsPane.md`
  - `by-class/MapTileImageLib.md`
  - `by-class/MessageShowPane.md`
  - `by-class/-coverage-report.md`
  - Validator-owned/projected support: `project-level/-auto-completion-stats.md` and `tools/validator.ini` refreshed during scoped validator passes.
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score/routing decisions:
  - [UID:000068] `HourPane`: `85/85 -> 86/88`; owner/emitter remains [UID:0000JX] `HourPane`.
  - [UID:00006B] `IconsPane`: `85/85 -> 86/88`; owner/emitter remains [UID:0000JZ] `IconsPane`; stale by-class coverage row corrected from `82%` to `86%`.
  - [UID:00007T] `MapTileImageLib`: `85/85 -> 86/88`; owner/emitter remains [UID:0000L5] `MapTileImageLib`.
  - [UID:000087] `MessageShowPane`: `85/85 -> 86/88`; owner/emitter remains [UID:0000LB] `MessageShowPane`.
- Evidence checked:
  - Active IDA MCP session `b001_mappane_0001AW_20260616`, `NexusTK.exe`, Hex-Rays ready. Used read-only `idb_list`, `lookup_funcs`, `xrefs_to`, `analyze_function`, `callees`, `insn_query`, and `get_bytes`.
  - `HourPane`: exact method starts, four `g_pHourPane` refs, three vtable-store triads, server-hour update slot behavior, `TIME.EPF`/`TIME.PAL` versus `TIME.EPD` paint branch, and `word_66DB04` / `g_hourFrameTable` frame lookup.
  - `IconsPane`: exact method/destructor starts, six `g_pIconsPane` refs, three vtable-store triads, OnMouseEvent helper calls, and raw dispatch bytes at `0x004cf8e0-0x004cf974` padded by `0xcc` before/after.
  - `MapTileImageLib`: constructor/destructor/draw/helper/singleton-clear/scalar-destructor function objects, startup-only constructor caller, constructor-only metadata helper caller, vtable-only scalar destructor reference, ten `g_pMapTileImageLib` refs, and four `DrawTile` code xrefs including one raw/no-function caller at `0x0050c3d7`.
  - `MessageShowPane`: exact constructor/destructor/text-builder/wrapped-text/EH-clear/thunk/scalar-destructor starts, eight `g_pMessageShowPane` refs, packet-handler constructor and wrapped-text callers, and MessageShowPane vtable store refs through `0x0061fa4c`, `0x0061fa98`, and `0x0061fac8`.
  - Direct support docs checked but not edited: the four by-file parents, target singleton globals, HourPane/Icon resource pages, MapTile layout/vtable/record pages, MessageShow read-only/vtable data pages, and the action-helper/global support around `0x005a4db0`-`0x005a5a80`.
- Blocker outcomes:
  - Resolved current low-confidence evidence gaps for method boundaries, singleton refs, vtable refs, resource/data links, and support coverage-row stale text.
  - `HourPane` remaining blockers are real: current IDA/docs do not prove the inherited pane cleanup source name, packet/interface name for the update virtual, or final field names for `+0x44` draw-region state and `+0xf8` current hour.
  - `IconsPane` remaining blockers are real: action helper callees are shared across IconsPane/TabPane/UserPane/MapPane contexts, and the raw dispatch body is executable/switch-shaped but still has no IDA function object, direct caller, or pointer-byte evidence.
  - `MapTileImageLib` remaining blockers are real: IDA proves behavior/layout but not final source-quality names for metadata/record fields, record flag semantics, helper declarations, or exact original folder.
  - `MessageShowPane` remaining blockers are real: current evidence proves class/vtable/singleton/packet reachability but not standalone `MessageShowPane.cpp` versus compact `MessageDialogs.cpp`, inherited base/interface names, or final text-builder helper name.
- Validation commands/results:
  - `python .\tools\validator.py --mode file --file by-class\HourPane.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\IconsPane.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\MapTileImageLib.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\MessageShowPane.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --lock-timeout -1` -> `ok: 1`.
  - A compact rerun of the same five validators also returned `ok: 1` for each file.
- Leases used/release status:
  - Leased `by-class/HourPane.md`, `by-class/IconsPane.md`, `by-class/MapTileImageLib.md`, `by-class/MessageShowPane.md`, `by-class/-coverage-report.md`, and `tools/leaser/Agents/Agent-A002/notes.md`.
  - Release command for the five by-class paths reported `Rejected[No active lease]` for each path because the short leases had already expired during validation/checkpointing.
  - Follow-up `current_leases.md` showed no active A002 leases for the edited by-class files. Temporary notes-only placement-correction leases were acquired and released successfully after recording this status.
- IDA DB changes: none. No IDA renames, comments, type changes, function promotions, or saves were made.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: none. No by-memory documentation page was changed in this batch, so no shared memory coverage replacement/insert/delete rows are pending.

Batch checkpoint:

- Changed files:
  - `by-file/StdioFile.md`
  - `by-file/TextFilter.md`
  - `by-file/DATArchive.md`
  - `by-file/-coverage-report.md`
  - `by-item/DATEntryRecord.md`
  - `by-item/-coverage-report.md`
  - `by-meta/client_dat_specifications.md`
  - `by-meta/-coverage-report.md`
  - Validator-owned `project-level/-auto-completion-stats.md` and `tools/validator.ini` were refreshed by scoped validator passes.
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score/routing decisions:
  - [UID:0000O9] `StdioFile`: `85/86 -> 86/88`; owner remains `CANONICAL_OWNER:FILE` with source root `NexusTK/util/`, concrete module `StdioFile.cpp` or compact `FileIO.cpp` still open.
  - [UID:0000OO] `TextFilter`: `85/86 -> 86/88`; owner remains `CANONICAL_OWNER:FILE` with source root `NexusTK/ui/controls/`, sanitizer retained with the TextFilter source root and not moved to `TextEditPane`.
  - [UID:0000IM] `DATArchive`: `88/84 -> 89/87`; owner remains `CANONICAL_OWNER:FILE` only as an archive umbrella. Concrete source ownership stays with [UID:0000IN] `DATFile`, [UID:0000IO] `DATFileMgr`, and [UID:0000IP] `DATIndexVector`.
  - Direct support [UID:0000UC] `DATEntryRecord`: `86/89 -> 88/91`; owner/emitter remains [UID:0000IN] `DATFile`, with [UID:0000IO] `DATFileMgr` documented as mapping/index behavior support.
  - Direct support [UID:0001QC] `client_dat_specifications` coverage row changed from `50% : medium` to `55% : medium`; page metadata remains `-1/-1` by existing meta-page convention.
- Evidence checked:
  - Active IDA MCP session `b001_mappane_0001AW_20260616`, `NexusTK.exe`, image base `0x00400000`, Hex-Rays ready. `server_health`, `lookup_funcs`, `func_profile`, `xrefs_to`, and targeted `decompile` were read-only only.
  - `StdioFile`: function map reconfirmed constructor `0x00582070` size `0x2a`, `Open` `0x005820d0` size `0xf9`, close/tell/seek/read/line helpers through `0x00582410`, `PathExistsViaStat` at `0x00582460`, deleting destructor `0x005824a0`, and non-contiguous `GetSize` at `0x004f5ad0`. Caller refresh reconfirmed startup logo/video, main-menu art, map `.cmp`, and Miles callback contexts; support docs checked were `StdioFile`, `File`, `FileIO`, and PathUtil boundary docs.
  - `TextFilter`: lookup/xref refresh reconfirmed constructor `0x00595760` size `0x35`, non-deleting body `0x005957a0` size `0x11`, sanitizer `0x005957c0` size `0x10a`, scalar deleting destructor `0x005958d0` size `0x2e`, 19 `g_pTextFilter` data refs, four `0x0062e188` vtable refs, one startup constructor caller, and 14 sanitizer call sites across 12 functions. Support docs checked were `TextFilter`, `g_pTextFilter`, `SanitizeWideTextForChat`, exact memory aggregate, and `TextEditPane`.
  - `DATArchive`: lookup/profile/decompile refresh reconfirmed `DATFileContainer`, `DATFile::Open`, `HasDATEntry`, `_DATFileMgr::LoadDATFileIndex`, `_DATFileMgr::FindEntryByName`, `ParseEntries`, `LoadDatFileBuffer`, and shared `DATIndexVector` caller fanout. The DAT package audit scanned 250 files under `E:\2026\Resources\Read_Only\NexusTK\Data`: all parsed cleanly, all offsets were monotonic and within bounds, row counts ranged `2..260`, all 1,038 non-empty exposed names were null-terminated, and three final boundary rows (`baramst.dat`, `head0.dat`, `mus004.dat`) had nonzero name-area bytes.
- Blocker outcomes:
  - `StdioFile`: source-root ownership/reachability is resolved. Remaining blocker is original file granularity (`StdioFile.cpp` versus compact `FileIO.cpp` with `File`/PathUtil); checked IDA boundaries/callers and support docs, but no source-path/symbol evidence proves one layout.
  - `TextFilter`: TextEditPane exclusion is resolved and sanitizer stays with TextFilter for now. Remaining blockers are final helper spelling and exact `ui/controls` versus utility source folder; checked caller fanout, singleton/vtable/global refs, and support docs, but no recovered symbol/path proves the final folder.
  - `DATArchive`: final-row empty-sentinel blocker is resolved for current-package semantics: the row is a payload-boundary row, and its name bytes are not reliable. Remaining blockers are original DAT type/field names, possible older-package variants, and broad render/resource source split; no B-agent escalation is needed because concrete archive ownership is clear and only umbrella/source-layout questions remain.
  - `DATEntryRecord`: current package proves exposed-name null termination and final boundary-row behavior; final C++ remains blank because original struct/type spelling and boundary-row declaration style are not source-quality.
- Validation commands/results:
  - `python .\tools\validator.py --mode file --file by-file\StdioFile.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\TextFilter.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\DATArchive.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\-coverage-report.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-item\DATEntryRecord.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-item\-coverage-report.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-meta\client_dat_specifications.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-meta\-coverage-report.md --apply --lock-timeout -1` -> `ok: 1`.
- Leases used/release status:
  - Leased `by-file/StdioFile.md`, `by-file/TextFilter.md`, `by-file/DATArchive.md`, `by-file/-coverage-report.md`, `by-item/DATEntryRecord.md`, `by-item/-coverage-report.md`, `by-meta/client_dat_specifications.md`, `by-meta/-coverage-report.md`, and `tools/leaser/Agents/Agent-A002/notes.md`.
  - Release command `python .\leaser.py Agent-A002 unlease` reported `Agent-A002: No active leases` because the short leases had already expired after validation/checkpointing; follow-up `current_leases.md` showed no A002 leases remaining. A temporary notes-only correction lease was then acquired and released successfully.
- IDA DB changes: none. No IDA renames, comments, type declarations, or saves were made because remaining names/source splits are still source-quality blockers rather than safe IDA-local metadata changes.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: none. The supervisor-owned memory coverage report was not edited.

## 2026-06-16 Assignment - A002-goal2-memory-completion-midi-reader-core-20260616-52

Assigned targets:
- [UID:0002BS] `by-memory/0x00526650-0x005266a1.MidiExactReadHelper.md`
- [UID:0002BT] `by-memory/0x005266b0-0x00526784.MidiTrackBufferedByteReader.md`
- [UID:0002BW] `by-memory/0x00526bb0-0x00526cd9.MidiVariableLengthQuantityReader.md`

Instructions:
- Read and follow `Agent-A002/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven exact Midi reader helper completion pass from refreshed `project-level/-auto-completion-stats.md`. Targets are exact modeled helpers at `80/88` with known owner/emitter [UID:0000LD] `MidiPlayer` and support through [UID:00023B] `MidiFileReaderAndSMFParserHelpers`.
- Refresh function bounds, callers, callees, decompilation, padding, source-family evidence, track/document field maps, adapter/Win32 read paths, VLQ behavior, final helper/type/name blockers, and directly supporting MidiPlayer docs/reports.
- Investigate every listed blocker instead of repeating it. Resolve blockers where supported; otherwise record exact IDA/docs/metadata/PE evidence checked and why the issue remains unsafe.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and exact pending supervisor-owned report rows.

Batch checkpoint:

- Changed files:
  - `by-memory/0x00526650-0x005266a1.MidiExactReadHelper.md`
  - `by-memory/0x005266b0-0x00526784.MidiTrackBufferedByteReader.md`
  - `by-memory/0x00526bb0-0x00526cd9.MidiVariableLengthQuantityReader.md`
  - `by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md`
  - `by-file/MidiPlayer.md`
  - `by-file/-coverage-report.md`
  - Validator-owned `project-level/-auto-completion-stats.md` and `tools/validator.ini` were refreshed by scoped validator file-mode passes.
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score/routing decisions:
  - [UID:0002BS] `MidiExactReadHelper`: `80/88 -> 86/90`; owner/emitter remains [UID:0000LD] `MidiPlayer`.
  - [UID:0002BT] `MidiTrackBufferedByteReader`: `80/88 -> 86/90`; owner/emitter remains [UID:0000LD] `MidiPlayer`.
  - [UID:0002BW] `MidiVariableLengthQuantityReader`: `80/88 -> 86/90`; owner/emitter remains [UID:0000LD] `MidiPlayer`.
  - Direct support [UID:00023B] `MidiFileReaderAndSMFParserHelpers`: `85/90 -> 86/91`; owner/emitter remains [UID:0000LD] `MidiPlayer`.
  - Direct support [UID:0000LD] `MidiPlayer`: `85/88 -> 86/89`; `NexusTK/audio/` placement and `SoundManager` exclusion remain unchanged.
- Evidence checked:
  - Active IDA MCP session `b001_mappane_0001AW_20260616`, `NexusTK.exe.i64`, image base `0x00400000`, Hex-Rays ready; used `server_health`, `lookup_funcs`, `func_profile`, `xrefs_to`, `callees`, `decompile`, `analyze_component`, `get_bytes`, `search_structs`, and `type_query` read-only.
  - `lookup_funcs` reconfirmed exact modeled starts/sizes for `0x00526650` size `0x51`, `0x005266b0` size `0xd4`, `0x00526790` size `0x25a`, `0x00526bb0` size `0x129`, `0x00526da0` size `0x169`, `0x00527000` size `0x39`, `0x005270c0` size `0x15`, and `0x005273a0` size `0x41b`; `0x00526ce0` still is not a function object.
  - `xrefs_to` reconfirmed [UID:0002BS] call sites `0x005274aa`, `0x005274f0`, `0x00527597`, `0x005275b9`; [UID:0002BT] call sites `0x005267be`, `0x0052681b`, `0x0052686a`, `0x00526884`, `0x005268d1`, `0x0052692e`, `0x005269a2`; and [UID:0002BW] call sites `0x005268e5`, `0x0052695f`, `0x005269cc`, `0x00526eb3`, `0x005276bf`.
  - Decompilation reconfirmed exact-read adapter slot `+0x20` / `ReadFile` paths and failure-on-short-read return; byte-reader 40-byte track field map, adapter/Win32 seek-read paths, 0x400 clamp, byte output, and binary success/failure return; and VLQ track flag, inline refill, `(value << 7) | (byte & 0x7f)` accumulation, decoded output, and failure behavior.
  - `analyze_component` kept the three target helpers internal to the MIDI reader/parser component, reached through event-reader, track-prime, parse-wrapper, and stream-fill paths, not a separate unrelated subsystem.
  - `get_bytes` reconfirmed all-`0xcc` padding at `0x005266a1-0x005266b0`, `0x00526784-0x00526790`, `0x00526ba8-0x00526bb0`, `0x00526cd9-0x00526ce0`, and `0x005277bb-0x005277c0`.
  - Final type/name checks: by-type docs have no MIDI track/document struct page; IDA `search_structs`/`type_query` for `Midi`, `MIDI`, `SMF`, and `Track` found only Win32 `midihdr_tag` and unrelated `tagTRACKMOUSEEVENT`. Therefore helper/type names and the possible `MidiPlayer.cpp` versus adjacent private SMF parser source split remain real blockers.
- Blocker outcomes:
  - Resolved current function bounds, callers, callees/imports, padding, adapter/Win32 paths, track field map, VLQ behavior, and source-family ownership.
  - Remaining blockers are real: final MIDI document reader type, source adapter interface, 40-byte track-record type/field names, helper declarations, and original helper-file split have no recovered source/type evidence. Final C++ remains blank despite scores clearing 85/85.
- Validation commands/results:
  - `python .\tools\validator.py --mode file --file by-memory\0x00526650-0x005266a1.MidiExactReadHelper.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x005266b0-0x00526784.MidiTrackBufferedByteReader.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00526bb0-0x00526cd9.MidiVariableLengthQuantityReader.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\MidiPlayer.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\-coverage-report.md --apply --lock-timeout -1` -> `ok: 1`.
- Leases used/release status:
  - Leased `by-memory/0x00526650-0x005266a1.MidiExactReadHelper.md`, `by-memory/0x005266b0-0x00526784.MidiTrackBufferedByteReader.md`, `by-memory/0x00526bb0-0x00526cd9.MidiVariableLengthQuantityReader.md`, `by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md`, `by-file/MidiPlayer.md`, `by-file/-coverage-report.md`, and `tools/leaser/Agents/Agent-A002/notes.md`.
  - Release command for those seven paths reported `Rejected[No active lease]` for each path because the short leases had expired after validation/checkpointing; follow-up `current_leases.md` showed no active A002 leases. A temporary notes-only correction lease was then acquired and released successfully for this release-status update.
- IDA DB changes: none. No IDA renames, comments, types, or saves were made; remaining names are source-quality/type evidence blockers, not safe IDA-local metadata repairs.
- Pending supervisor-owned `by-memory/-coverage-report.md` replacements:
  - Placement context: replace the existing rows in `by-memory/-coverage-report.md` under the `0x0052664b-0x00526650` padding row and before the unchanged [UID:0002BU] event-reader sibling. Replace [UID:00023B], [UID:0002BS], [UID:0002BT], and [UID:0002BW] rows only; keep sibling rows unchanged.
  - Replacement row for [UID:00023B]:
    `    - [UID:00023B][0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers](by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md) 0x00526650-0x005270d5 | helper island | MidiFileReaderAndSMFParserHelpers : reconstructable : 86% : strong : MIDI file/adapter read, SMF track parsing, and WinMM stream-event encoding helper island split into exact child range pages and attached to `MidiPlayer.cpp`; 2026-06-16 live IDA reconfirms exact reader-core boundaries, call sites, decompilation, 0x400-byte track buffering, VLQ behavior, component-internal grouping, and padding, while raw starts and final reader/document/track/source-adapter names remain open.`
  - Replacement row for [UID:0002BS]:
    `        - [UID:0002BS][0x00526650-0x005266a1.MidiExactReadHelper](by-memory/0x00526650-0x005266a1.MidiExactReadHelper.md) 0x00526650-0x005266a1 | function | MidiExactReadHelper : reconstructable : 86% : strong : Exact-count adapter/File API read helper with four SMF-loader call sites; current decompilation confirms adapter slot +0x20 / ReadFile paths and failure-on-short-read semantics.`
  - Replacement row for [UID:0002BT]:
    `        - [UID:0002BT][0x005266b0-0x00526784.MidiTrackBufferedByteReader](by-memory/0x005266b0-0x00526784.MidiTrackBufferedByteReader.md) 0x005266b0-0x00526784 | function | MidiTrackBufferedByteReader : reconstructable : 86% : strong : Buffered track byte reader with seven event-reader call sites; current decompilation confirms the 40-byte track-record field map, adapter/Win32 seek-read refill, 0x400 clamp, byte output, and binary success/failure return.`
  - Placement context for [UID:0002BW]: replace the existing [UID:0002BW] row between unchanged [UID:0002BV] `MidiStreamEventEncoder` and unchanged [UID:0002BX] `MidiTrackBufferRefill`.
  - Replacement row for [UID:0002BW]:
    `        - [UID:0002BW][0x00526bb0-0x00526cd9.MidiVariableLengthQuantityReader](by-memory/0x00526bb0-0x00526cd9.MidiVariableLengthQuantityReader.md) 0x00526bb0-0x00526cd9 | function | MidiVariableLengthQuantityReader : reconstructable : 86% : strong : VLQ reader with event-reader, track-prime, and SMF-loader callers; current decompilation confirms track error flag handling, inline 0x400-byte refill, `(value << 7) | (byte & 0x7f)` accumulation, decoded output, and padding.`

Supervisor integration update (2026-06-16): supervisor applied the exact [UID:00023B], [UID:0002BS], [UID:0002BT], and [UID:0002BW] `by-memory/-coverage-report.md` replacement rows, then validated the shared report and the four related memory docs with scoped `validator.py --mode file --apply --queue-timeout 240`; all passes exited `0` with `ok:1`. No A002 supervisor-owned memory rows remain pending for `A002-goal2-memory-completion-midi-reader-core-20260616-52`.

## 2026-06-16 Assignment - A002-goal2-memory-completion-midi-source-core-20260616-54

Assigned targets:
- [UID:0002BX] `by-memory/0x00526ce0-0x00526d9a.MidiTrackBufferRefill.md`
- [UID:0002BY] `by-memory/0x00526da0-0x00526f09.MidiTrackBufferPrimeReset.md`
- [UID:0002BZ] `by-memory/0x00526f10-0x00526f57.MidiSourceOpenHelper.md`
- [UID:0002C0] `by-memory/0x00526f60-0x00526f97.MidiSourceCloseHelper.md`

Instructions:
- Read and follow `Agent-A002/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven continuation of the MIDI reader/source helper island after the reader-core batch. Quick-peek shows all four targets at `80/88`, known [UID:0000LD] `MidiPlayer` owner/emitter, and support through [UID:00023B] `MidiFileReaderAndSMFParserHelpers`.
- Refresh current IDA function/no-function status, exact bounds, callers/xrefs, decompilation or raw disassembly, adapter/source offsets, Win32 handle/API-wrapper usage, 40-byte track-record behavior, padding, and source-family evidence.
- Refresh directly supporting docs/reports where needed, especially [UID:00023B] `MidiFileReaderAndSMFParserHelpers`, [UID:0000LD] `MidiPlayer`, and coverage rows.
- Investigate final source-quality blockers now: source adapter type, MIDI document/track-record type and field names, helper declarations, raw-start reachability, Win32 wrapper/global naming, and `MidiPlayer.cpp` versus private helper-source split. Do not merely list blockers without checking evidence.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and exact pending supervisor-owned report rows.

Batch checkpoint:

- Completed. Detailed changed-files, score/routing, evidence, blocker, validation, lease, IDA-change, and exact pending supervisor-owned `by-memory/-coverage-report.md` replacement-row text for `A002-goal2-memory-completion-midi-source-core-20260616-54` is recorded in the detailed checkpoint block above that begins: `Note: this detailed checkpoint belongs to A002-goal2-memory-completion-midi-source-core-20260616-54`.
- All A002 leases are released; `current_leases.md` reports no active leases.

Supervisor integration update (2026-06-16): supervisor applied the exact [UID:00023B], [UID:0002BX], [UID:0002BY], [UID:0002BZ], and [UID:0002C0] `by-memory/-coverage-report.md` replacement rows from the source-core checkpoint, then validated the shared report and the touched target/support docs with scoped `validator.py --mode file --apply --queue-timeout 240`; all passes exited `0` with `ok:1`. No A002 supervisor-owned memory rows remain pending for `A002-goal2-memory-completion-midi-source-core-20260616-54`.

## 2026-06-16 Assignment - A002-goal2-memory-completion-baramapp-startup-callbacks-20260616-56

Assigned targets:
- [UID:0002PZ] `by-memory/0x004f5f20-0x004f5f4e.BaramAppConstructorRaw.md`
- [UID:0002Q0] `by-memory/0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory.md`

Instructions:
- Read and follow `Agent-A002/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven exact BaramApp/Application startup pass from refreshed `project-level/-auto-completion-stats.md`. Quick-peek shows both targets at `80/88`, with known [UID:00000V] `BaramApp` owner/emitter and support through [UID:00019H] `BaramAppAndApplicationStartup`.
- Refresh current IDA function/no-function status, exact bytes/bounds, padding, callers/xrefs, vtable/callback wrapper evidence, `Application::Startup` store behavior, `TerminalPane` construction path, and BaramApp/Application source placement.
- Refresh directly supporting docs/reports where needed, especially [UID:00019H] `BaramAppAndApplicationStartup`, [UID:00000V] `BaramApp`, [UID:0000HG] `Application`, [UID:00025P] `BaramAppReadOnlyData`, [UID:0002H7] `ApplicationStartup`, and [UID:0001JB] `TerminalPaneAndSetup`.
- Investigate final source-quality blockers now: raw constructor reachability/function-object status, constructor signature, callback member name, wrapper layout/type names, BaramApp/Application source split, vtable/callback data names, and final-C++ eligibility. Do not merely list blockers without checking evidence.
- If this turns into heavy original-source structure inference beyond the bounded startup/callback evidence, document the checked evidence and recommend B-agent escalation rather than forcing a conclusion.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and exact pending supervisor-owned report rows.

Batch checkpoint:

- Changed files:
  - `by-memory/0x004f5f20-0x004f5f4e.BaramAppConstructorRaw.md`
  - `by-memory/0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory.md`
  - `by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md`
  - `by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md`
  - `by-class/BaramApp.md`
  - `by-class/-coverage-report.md`
  - Validator-owned `project-level/-auto-completion-stats.md` and `tools/validator.ini` were refreshed by scoped validator file-mode passes.
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score/routing decisions:
  - [UID:0002PZ] `BaramAppConstructorRaw`: `80/88 -> 85/90`; owner/emitter remains [UID:00000V] `BaramApp` through [UID:0000HG] `Application`.
  - [UID:0002Q0] `BaramAppTerminalPaneCallbackFactory`: `80/88 -> 86/90`; owner/emitter remains [UID:00000V] `BaramApp` through [UID:0000HG] `Application`.
  - Direct support [UID:00019H] `BaramAppAndApplicationStartup`: `85/88 -> 86/90`; owner/emitter remains [UID:0000HG] `Application`.
  - Direct support [UID:0002H7] `ApplicationStartup`: `86/90 -> 86/90`; owner/emitter remains [UID:00000D] `Application`.
  - Direct support [UID:00000V] `BaramApp`: `85/90 -> 86/90`; owner/emitter remains [UID:0000HG] `Application`.
  - [UID:0000HG] `Application` and [UID:0000OI] `TerminalPane` support pages were checked but not edited; their current evidence was sufficient for this bounded callback/constructor pass.
- Evidence checked:
  - Active IDA MCP session `b001_mappane_0001AW_20260616`, `NexusTK.exe.i64`, image base `0x00400000`, Hex-Rays ready; used `server_health`, `lookup_funcs`, `get_bytes`, `insn_query`, `xrefs_to`, `callees`, `decompile`, and `analyze_function` read-only.
  - `lookup_funcs` reconfirmed no function object at `0x004f5f20`, `0x004f5f33`, or `0x004f5f4e`; `sub_4F5F50` remains an exact function object at `0x004f5f50-0x004f5faf`; `Application::Startup` remains `0x004f5fb0-0x004f6490`; `Application::Shutdown` remains `0x004f6490-0x004f66a5`; and the deleting-destructor thunks remain at `0x004f66b5` and `0x004f66c0`.
  - `get_bytes` reconfirmed 9 bytes of `0xcc` before `0x004f5f20`, the 46-byte raw constructor-shaped body, 2 bytes of `0xcc` padding at `0x004f5f4e`, the 95-byte callback function body, and `0xcc` padding at `0x004f5faf`.
  - Raw constructor disassembly reconfirmed Application constructor forwarding, primary BaramApp vtable store at `0x0061d118`, secondary vtable store at `0x0061d138`, `this` return, `retn 0Ch`, and no promoted function metadata.
  - `xrefs_to 0x004f5f20` returned no start references; `xrefs_to 0x0061d118` and `0x0061d138` reported `_WinMain@16` and raw-constructor references; this keeps the raw constructor reachability/function-object blocker real.
  - Callback decompilation/analyze reconfirmed `ShowCursor(TRUE)` through [UID:0000S7] `g_pScreenPane`, `operator new(0x270)` / 624 bytes, `TerminalPane::TerminalPane`, and null-on-allocation-failure behavior.
  - `insn_query 0x004f63c0-0x004f6400` reconfirmed the `PlainMemberFunctionObject0<BaramApp>` wrapper allocation size `0x18` / 24 bytes, base-shell constructor call, vtable store at `0x0061d238`, callback target slot `+8`, zero auxiliary slot `+0x0c`, and captured BaramApp pointer at slot `+0x10`.
  - `xrefs_to 0x004f5f50` reported exactly one reference, the callback-target data store at `0x004f63ec`; no ordinary direct callers were found.
  - Support docs checked: [UID:00025P] `BaramAppReadOnlyData`, [UID:0002Q2] `BaramAppCallbackVtableData`, [UID:0002Q1] `BaramAppVtableData`, [UID:0001JB] `TerminalPaneAndSetup`, [UID:000196] `OperatorNewWrapper`, [UID:0001G7] `ScreenCursorHelpers`, [UID:0001G5] `ScreenPane`, [UID:0000S7] `g_pScreenPane`, [UID:0000HG] `Application`, and [UID:00000D] `Application`.
- Blocker outcomes:
  - Resolved current boundaries, padding, BaramApp vtable stores, wrapper layout, callback reachability, cursor/allocation/TerminalPane callee names, and `Application::Startup` callback-store evidence.
  - Remaining blocker is real for [UID:0002PZ]: IDA has no function object or direct start xrefs for `0x004f5f20`, so promoting it to a callable constructor or emitting final C++ would overstate evidence.
  - Remaining blocker is real for [UID:0002Q0]: the callback target is reached only through a `PlainMemberFunctionObject0<BaramApp>` wrapper store; no original member callback name was found in IDA/docs/metadata, so the docs name remains descriptive and final C++ stays blank.
  - Remaining source split blockers are real: `BaramApp` remains attached under the Application source root, but the exact BaramApp/Application source-file split, constructor declaration spelling, callback member name, and final field names are not proven.
  - Broader `ApplicationStartup` helper labels were investigated. `g_pScreenPane`, `ScreenPane::SetLayerFrame`, `ScreenPane` present/timer helper, `ShowCursor(TRUE)`, `operator new`, and `TerminalPane::TerminalPane` were resolved where support pages proved them; surface/minimap initializer and cursor-resource-loader source names remain provisional and were not promoted.
- Validation commands/results:
  - `python .\tools\validator.py --mode file --file by-memory\0x004f5f20-0x004f5f4e.BaramAppConstructorRaw.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x004f5fb0-0x004f6490.ApplicationStartup.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\BaramApp.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --lock-timeout -1` -> `ok: 1`.
- Leases used/release status:
  - Leased `by-memory/0x004f5f20-0x004f5f4e.BaramAppConstructorRaw.md`, `by-memory/0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory.md`, `by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md`, `by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md`, `by-class/BaramApp.md`, `by-class/-coverage-report.md`, and `tools/leaser/Agents/Agent-A002/notes.md`.
  - Release command for those seven paths reported `Rejected[No active lease]` for each path because the short leases had already expired after validation/checkpointing; follow-up lease ledgers showed no active A002 leases. A temporary notes-only correction lease was then acquired to move this checkpoint under the correct assignment and released successfully.
- IDA DB changes: none. No IDA renames, comments, type declarations, or saves were made because remaining names/source splits are source-quality blockers, and promoting the raw constructor to a function object would overstate reachability evidence.
- Pending supervisor-owned `by-memory/-coverage-report.md` replacements:
  - Placement context: replace the existing [UID:00019H] aggregate row and its [UID:0002PZ], [UID:0002Q0], and [UID:0002H7] child/support rows in `by-memory/-coverage-report.md` at the BaramApp/Application startup cluster, currently between the `0x004f5f17-0x004f5f20` padding row and the following post-cluster padding/next rows. Do not edit unrelated rows.
  - Replacement row for [UID:00019H]:
    `- [UID:00019H][0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup](by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md) 0x004f5f20-0x004f66fb | class-method-cluster | BaramAppAndApplicationStartup : reconstructable : 86% : strong : App startup/shutdown cluster; 2026-06-16 A002 live IDA refresh reconfirms raw no-xref BaramApp constructor-shaped body at 0x004f5f20, callback factory at 0x004f5f50, Application::Startup and Application::Shutdown sizes, secondary deleting-destructor thunk, scalar deleting destructor through 0x004f66fb, WinMain/vtable refs, callback wrapper store, resolved ShowCursor/operator-new/TerminalPane callee roles, padding boundaries, and Application owner-emitter route. Final C++ remains blank because this is a mixed aggregate across classes/thunks/padding.`
  - Replacement row for [UID:0002PZ]:
    `    - [UID:0002PZ][0x004f5f20-0x004f5f4e.BaramAppConstructorRaw](by-memory/0x004f5f20-0x004f5f4e.BaramAppConstructorRaw.md) 0x004f5f20-0x004f5f4e | raw-method | BaramAppConstructorRaw : reconstructable : 85% : strong : Parent-attached raw BaramApp constructor-shaped body; 2026-06-16 live IDA confirms exact bytes, Application constructor forwarding, primary/secondary BaramApp vtable writes, no promoted function object, no direct start xrefs, and padding boundaries; final C++ stays blank until function-object/source split and layout names clear the final-source gate.`
  - Replacement row for [UID:0002Q0]:
    `    - [UID:0002Q0][0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory](by-memory/0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory.md) 0x004f5f50-0x004f5faf | callback-function | BaramAppTerminalPaneCallbackFactory : reconstructable : 86% : strong : Parent-attached startup callback target; 2026-06-16 live IDA confirms the PlainMemberFunctionObject0<BaramApp> wrapper store, target slot, captured object pointer, ShowCursor(TRUE) restore through g_pScreenPane, operator-new allocation, TerminalPane construction, and no ordinary direct callers; final C++ stays blank until the member-callback source name is resolved.`
  - Replacement row for [UID:0002H7]:
    `    - [UID:0002H7][0x004f5fb0-0x004f6490.ApplicationStartup](by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md) 0x004f5fb0-0x004f6490 | class method | ApplicationStartup : reconstructable : 86% : strong : A002 Goal2 live IDA refresh confirms exact bounds, _WinMain@16 caller, vtable slot, internal-only classification, singleton/image-library allocation block, g_pScreenPane UI/runtime use, six main UI slot allocations and ordered ScreenPane::SetLayerFrame registrations, callback wrapper vtable/target/captured-this fields, LogoPane versus TerminalPane branch with resolved ShowCursor(TRUE)/TerminalPane fallback, allocation-unwind exclusions, and blank final C++ pending source-quality names.`

Supervisor integration update (2026-06-16): supervisor applied the exact [UID:00019H], [UID:0002PZ], [UID:0002Q0], and [UID:0002H7] `by-memory/-coverage-report.md` replacement rows from this BaramApp/startup callback checkpoint, then validated the shared report plus the four related memory docs with scoped `validator.py --mode file --apply --queue-timeout 240`; all passes exited `0` with `ok:1`. No A002 supervisor-owned memory rows remain pending for `A002-goal2-memory-completion-baramapp-startup-callbacks-20260616-56`.

## 2026-06-16 Assignment - A002-goal2-memory-completion-mappane-effect-list-20260616-57

Assigned targets:
- [UID:0002I3] `by-memory/0x00503ed0-0x00503eef.MapPaneResetEffectListFields.md`
- [UID:0002I4] `by-memory/0x00503ef0-0x0050408d.MapPaneConfigureEffectList.md`
- [UID:0002I5] `by-memory/0x00504090-0x00504093.MapPaneNullCallback40.md`

Instructions:
- Read and follow `Agent-A002/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 low-completion memory batch from refreshed `project-level/-auto-completion-stats.md`. Supervisor quick-peek shows these are exact MapPane effect-list helper/no-op ranges at `80/88`, with known MapPane ownership or ignored/non-emitting status; they are bounded enough for A-agent work.
- Refresh current IDA function/no-function status, exact bounds, bytes/padding, callers/xrefs, decompilation or raw disassembly, effect-list field triplet behavior, allocation/object setup paths, sibling relationships, and parent aggregate context.
- Review direct support pages as needed: [UID:0002I1], [UID:0002I2], [UID:0002I6], [UID:0001AO], [UID:0001AP], [UID:00007Q] `MapPane`, [UID:0000L3] `MapPane`, and relevant effect/object pages.
- Investigate final source-quality blockers now: effect-list field names, mode names, constructed object types, caller/reachability evidence, no-op stub table/pointer use, source placement, and final-C++ eligibility. Do not merely list blockers; resolve supported items or record exact evidence checked.
- If the work expands into broad MapPane source-split inference beyond these exact helpers, document the evidence and recommend B-agent escalation rather than forcing a conclusion. The broader [UID:0001AW] MapPanePacketHandlers split remains active with B001.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and exact pending supervisor-owned report rows.

Batch checkpoint:

- Changed files:
  - `by-memory/0x00503ed0-0x00503eef.MapPaneResetEffectListFields.md`
  - `by-memory/0x00503ef0-0x0050408d.MapPaneConfigureEffectList.md`
  - `by-memory/0x00504090-0x00504093.MapPaneNullCallback40.md`
  - Direct support: `by-memory/0x005040a0-0x00504102.MapPaneClearEffectList.md`
  - Direct support: `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`
  - Validator-owned/projected stats: `project-level/-auto-completion-stats.md` and `tools/validator.ini`
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score/routing decisions:
  - [UID:0002I3] `MapPaneResetEffectListFields`: `80/88 -> 86/90`; owner/emitter remains [UID:00007Q] `MapPane`; C++ remains blank.
  - [UID:0002I4] `MapPaneConfigureEffectList`: `80/88 -> 87/90`; owner/emitter remains [UID:00007Q] `MapPane`; constructed effect classes resolved, but C++ remains blank.
  - [UID:0002I5] `MapPaneNullCallback40`: `80/88 -> 86/90`; `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and blank emitters remain correct.
  - Direct support [UID:0002I6] `MapPaneClearEffectList`: `82/88 -> 85/90`; owner/emitter remains [UID:00007Q] `MapPane`; stored object family resolved to screen-effecter classes, final cleanup/source names still open.
  - Direct support [UID:0001AP] `MapPaneWeatherCoordinateObjectCore`: `85/88 -> 86/89`; owner/emitter remains [UID:00007Q] `MapPane`.
- Evidence checked:
  - Active IDA MCP session `b001_mappane_0001AW_20260616`, `NexusTK.exe`, Hex-Rays ready.
  - `lookup_funcs` reconfirmed modeled starts and exact sizes: `0x00503ed0` size `0x1f`, `0x00503ef0` size `0x19d`, `0x00504090` size `0x03`, and `0x005040a0` size `0x62`; endpoint addresses are not function starts.
  - `analyze_function` reconfirmed [UID:0002I3] zero writes to `MapPane +0x100/+0x0f8/+0x0fc`, no callees/callers, and one-block behavior.
  - `analyze_function` reconfirmed [UID:0002I4] clear-first call at `0x00503f15`, mode `2` one-entry list with `WaterFilterEffecter`, and mode `1` two-entry list with `XWaveEffecter` plus `SolidColorFilterEffecter`.
  - `xrefs_to` for `0x0055b6a0`, `0x0055b2a0`, and `0x0055ae00` found configure-helper constructor call sites at `0x00503f6e`, `0x0050401f`, and `0x00504067`, plus MapPane paint-lighting call sites at `0x0050a5f5`, `0x0050a68c`, and `0x0050a6d4`. This supports keeping effect-class ownership in [UID:0000IZ] `Effects` while MapPane owns only list setup/teardown.
  - `analyze_function` reconfirmed [UID:0002I5] as `nullsub_40`, a one-instruction `retn 4` body with no callers, callees, or xrefs.
  - `analyze_function` reconfirmed [UID:0002I6] count guard, pointer-array iteration, vtable `+0x18` cleanup call with flag `1`, free through `0x005c7526`, final field clears, seven modeled callers, and one extra unmodeled code edge at `0x00541137`.
  - `xrefs_to` found no inbound references to `0x00503ed0`, `0x00503ef0`, or `0x00504090`. `find_bytes` found no loaded-segment pointer-byte hits for `d0 3e 50 00`, `f0 3e 50 00`, or `90 40 50 00`.
  - `get_bytes` reconfirmed local padding and exact bytes: `0x00503ecd-0x00503ed0` three `0xcc`, `0x00503eef-0x00503ef0` one `0xcc`, `0x0050408d-0x00504090` three `0xcc`, `0x00504090` bytes `c2 04 00`, and `0x00504093-0x005040a0` thirteen `0xcc`.
  - `int_convert` verified decimal sizes/constants used in docs: `0x1f`/31, `0x19d`/413, `0x03`/3, `0x28`/40, `0x0a`/10, `0x11c`/284, `0x10`/16, `0x110`/272, `0x1d4c`/7500, `0xf8`/248, `0xfc`/252, and `0x100`/256.
  - Support docs checked: [UID:0000IZ] `Effects`, [UID:0000FZ] `WaterFilterEffecter`, [UID:0000GC] `XWaveEffecter`, [UID:0000DE] `SolidColorFilterEffecter`, [UID:0000C9] `ScreenEffecter`, [UID:0001GE] `ScreenEffecterRuntimeCluster`, [UID:0002OR] `ScreenEffecterVtableData`, [UID:0000T7] `MapTilePixelDimensions`, [UID:0000T8] `MemoryAllocationHelpers`, [UID:000196] `OperatorNewWrapper`, [UID:0001AO] `GameServerNationAndMapInit`, [UID:0001AP] `MapPaneWeatherCoordinateObjectCore`, [UID:00037W] `MapPanePaintLightingCore`, [UID:00007Q] `MapPane`, and [UID:0000L3] `MapPane`.
- Blocker outcomes:
  - Resolved: constructed object types for [UID:0002I4] are `WaterFilterEffecter`, `XWaveEffecter`, and `SolidColorFilterEffecter`; [UID:0002I6] stored-object family is screen-effecter/effecter code, not an unknown object list.
  - Resolved: source ownership remains [UID:00007Q] `MapPane` for the list helpers and [UID:0000IZ] `Effects` for effect classes; [UID:0002I5] remains ignored/non-emitting with no owner.
  - Resolved: [UID:0002I5] no-op table/pointer-use question was rechecked with `xrefs_to` and `find_bytes`; no current table/caller evidence exists.
  - Remaining blocker is real for [UID:0002I3] and [UID:0002I4]: current IDA still has no direct callers/xrefs and no loaded pointer bytes for the helper starts, so final caller route and helper source names cannot be promoted.
  - Remaining blocker is real for the effect-list fields: offsets `+0x0f8/+0x0fc/+0x100` are strongly mapped as count/capacity/pointer-array state, but no recovered type/header names prove final field names.
  - Remaining blocker is real for final C++: mode names, direct caller provenance, source helper declarations, and final field names remain unresolved. This stayed bounded to exact helpers; no broad MapPane source-split work was forced, and the broader MapPane packet split remains B-agent territory.
- Validation commands/results:
  - `python .\tools\validator.py --mode file --file by-memory\0x00503ed0-0x00503eef.MapPaneResetEffectListFields.md --apply --lock-timeout -1` -> `ok: 1`; removed [UID:0002I3] from `Low_Completion`, `Low_Both`, and by-memory stats queues.
  - `python .\tools\validator.py --mode file --file by-memory\0x00503ef0-0x0050408d.MapPaneConfigureEffectList.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00504090-0x00504093.MapPaneNullCallback40.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x005040a0-0x00504102.MapPaneClearEffectList.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md --apply --lock-timeout -1` -> `ok: 1`.
- Leases used/release status:
  - Leased `by-memory/0x00503ed0-0x00503eef.MapPaneResetEffectListFields.md`, `by-memory/0x00503ef0-0x0050408d.MapPaneConfigureEffectList.md`, `by-memory/0x00504090-0x00504093.MapPaneNullCallback40.md`, `by-memory/0x005040a0-0x00504102.MapPaneClearEffectList.md`, `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`, and `tools/leaser/Agents/Agent-A002/notes.md`.
  - Release command after checkpointing reported `Agent-A002: No active leases` because the short leases had already expired during validation/checkpointing. Follow-up `current_leases.md` showed no active A002 entries. A temporary notes-only lease was acquired to record this release status and will be released immediately after this correction.
- IDA DB changes: none. No IDA renames, comments, type declarations, function promotions, or saves were made. Existing `SolidColorFilterEffecter_Constructor` metadata was observed, but remaining mode/field/helper names are source-quality blockers and were not safe to force into IDA metadata.
- Pending supervisor-owned `by-memory/-coverage-report.md` replacements:
  - Placement context: replace the existing [UID:0002I3], [UID:0002I4], [UID:0002I5], and [UID:0002I6] rows in `by-memory/-coverage-report.md` under [UID:0001AO] `GameServerNationAndMapInit`, currently around lines 2259-2265 between the unchanged `0x00503ecd-0x00503ed0` padding row and the unchanged `0x00504102-0x00504110` padding row. Keep the padding rows unchanged.
  - Replacement row for [UID:0002I3]:
    `        - [UID:0002I3][0x00503ed0-0x00503eef.MapPaneResetEffectListFields](by-memory/0x00503ed0-0x00503eef.MapPaneResetEffectListFields.md) 0x00503ed0-0x00503eef | method | MapPaneResetEffectListFields : reconstructable : 86% : strong : A002 2026-06-16 live IDA reconfirmed the exact reset-helper boundary, zero writes to MapPane effect-list pointer/count/capacity fields at +0x100/+0x0f8/+0x0fc, no callers/callees/xrefs, no loaded pointer-byte hits for the helper start, and padding on both sides; final caller route and field/helper source names remain open.`
  - Replacement row for [UID:0002I4]:
    `        - [UID:0002I4][0x00503ef0-0x0050408d.MapPaneConfigureEffectList](by-memory/0x00503ef0-0x0050408d.MapPaneConfigureEffectList.md) 0x00503ef0-0x0050408d | method | MapPaneConfigureEffectList : reconstructable : 87% : strong : A002 2026-06-16 live IDA reconfirmed the exact configure-helper boundary, clear-first call, mode 1/2 branches, pointer-array allocation, field writes, tile-dimension inputs, no start xrefs or pointer-byte hits, and padding; support pages identify the stored objects as WaterFilterEffecter, XWaveEffecter, and SolidColorFilterEffecter while mode names and caller route remain open.`
  - Replacement row for [UID:0002I5]:
    `        - [UID:0002I5][0x00504090-0x00504093.MapPaneNullCallback40](by-memory/0x00504090-0x00504093.MapPaneNullCallback40.md) 0x00504090-0x00504093 | no-op/dead-stub | MapPaneNullCallback40 : ignored : 86% : strong : A002 2026-06-16 live IDA reconfirmed the isolated one-instruction retn 4 body, empty caller/callee/xref sets, no loaded pointer-byte hits for 0x00504090, and padding before/after; keep ignored/non-emitting unless future table or caller evidence appears.`
  - Replacement row for [UID:0002I6]:
    `        - [UID:0002I6][0x005040a0-0x00504102.MapPaneClearEffectList](by-memory/0x005040a0-0x00504102.MapPaneClearEffectList.md) 0x005040a0-0x00504102 | method | MapPaneClearEffectList : reconstructable : 85% : strong : A002 2026-06-16 live IDA reconfirmed the exact clear-helper boundary, effect-list count guard, pointer-array loop, vtable +0x18 cleanup call with flag 1, pointer-array free, final field clears, seven modeled callers plus one unmodeled code xref, and adjacent padding; stored object family is now tied to WaterFilterEffecter/XWaveEffecter/SolidColorFilterEffecter, while final virtual/field names remain open.`
  - Placement context: replace the existing [UID:0001AP] row in `by-memory/-coverage-report.md` immediately after the [UID:0001AO] child rows, currently around line 2268.
  - Replacement row for [UID:0001AP]:
    `    - [UID:0001AP][0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore](by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md) 0x00503ef0-0x0050637a | class aggregate | MapPaneWeatherCoordinateObjectCore : reconstructable : 86% : strong : MapPane class aggregate over weather/effect, lifecycle, map-cache, coordinate, scroll, and object core; C001 2026-06-13 live IDA reconfirmed the modeled-function inventory and crossing disposition, and A002 2026-06-16 refreshed the first effect-list children, ignored no-op distinction, no-ref/no-pointer evidence, and WaterFilterEffecter/XWaveEffecter/SolidColorFilterEffecter constructor support. Crossing with [UID:0001AO][0x005039f0-0x00504521.GameServerNationAndMapInit](by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md) remains intentional mixed-index overlap.`

Supervisor integration update (2026-06-16): supervisor accepted `A002-goal2-memory-completion-mappane-effect-list-20260616-57` as complete. Scores cleared the gate at [UID:0002I3] `86/90`, [UID:0002I4] `87/90`, [UID:0002I5] `86/90` ignored/non-emitting, support [UID:0002I6] `85/90`, and support [UID:0001AP] `86/89`; owner/emitter routes remain unchanged. Supervisor applied the exact [UID:0002I3], [UID:0002I4], [UID:0002I5], [UID:0002I6], and [UID:0001AP] `by-memory/-coverage-report.md` replacement rows and validated the shared report plus changed support memory pages (`ok:1`). No A002 supervisor-owned memory rows remain pending for this batch.

## 2026-06-16 Assignment - A002-goal2-class-confidence-hour-icons-maptile-message-20260616-58

Assigned targets:
- [UID:000068] `by-class/HourPane.md`
- [UID:00006B] `by-class/IconsPane.md`
- [UID:00007T] `by-class/MapTileImageLib.md`
- [UID:000087] `by-class/MessageShowPane.md`

Instructions:
- Read and follow `Agent-A002/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 low-confidence class batch from refreshed `project-level/-auto-completion-stats.md`. Supervisor quick-peek shows compact, already routed class pages at `85/85` with direct by-file parents and support pages: HourPane HUD clock, IconsPane old-layout icon strip, MapTileImageLib terrain-tile image library, and MessageShowPane floating message overlay.
- Improve documentation, evidence quality, completion, and confidence where justified. Review direct by-file, by-memory, by-global, by-type/by-vtable, by-resource, and caller/support pages when the class evidence depends on them.
- Investigate final source-quality blockers now: inherited base names, click/action helper names, raw dispatch/liveness questions, final field/layout names, helper/source-file grouping, singleton/global declarations, and final-C++ eligibility. Do not merely repeat blocker lists; resolve supported items, document exact evidence checked for unresolved blockers, or keep/lower scores if unresolved issues materially limit confidence.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and exact pending supervisor-owned report rows.

Batch checkpoint:

- Changed files:
  - `by-class/HourPane.md`
  - `by-class/IconsPane.md`
  - `by-class/MapTileImageLib.md`
  - `by-class/MessageShowPane.md`
  - `by-class/-coverage-report.md`
  - Validator-owned/projected support: `project-level/-auto-completion-stats.md` and `tools/validator.ini` refreshed during scoped validator passes.
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score/routing decisions:
  - [UID:000068] `HourPane`: `85/85 -> 86/88`; owner/emitter remains [UID:0000JX] `HourPane`.
  - [UID:00006B] `IconsPane`: `85/85 -> 86/88`; owner/emitter remains [UID:0000JZ] `IconsPane`; stale by-class coverage row corrected from `82%` to `86%`.
  - [UID:00007T] `MapTileImageLib`: `85/85 -> 86/88`; owner/emitter remains [UID:0000L5] `MapTileImageLib`.
  - [UID:000087] `MessageShowPane`: `85/85 -> 86/88`; owner/emitter remains [UID:0000LB] `MessageShowPane`.
- Evidence checked:
  - Active IDA MCP session `b001_mappane_0001AW_20260616`, `NexusTK.exe`, Hex-Rays ready. Used read-only `idb_list`, `lookup_funcs`, `xrefs_to`, `analyze_function`, `callees`, `insn_query`, and `get_bytes`.
  - `HourPane`: exact method starts, four `g_pHourPane` refs, three vtable-store triads, server-hour update slot behavior, `TIME.EPF`/`TIME.PAL` versus `TIME.EPD` paint branch, and `word_66DB04` / `g_hourFrameTable` frame lookup.
  - `IconsPane`: exact method/destructor starts, six `g_pIconsPane` refs, three vtable-store triads, OnMouseEvent helper calls, and raw dispatch bytes at `0x004cf8e0-0x004cf974` padded by `0xcc` before/after.
  - `MapTileImageLib`: constructor/destructor/draw/helper/singleton-clear/scalar-destructor function objects, startup-only constructor caller, constructor-only metadata helper caller, vtable-only scalar destructor reference, ten `g_pMapTileImageLib` refs, and four `DrawTile` code xrefs including one raw/no-function caller at `0x0050c3d7`.
  - `MessageShowPane`: exact constructor/destructor/text-builder/wrapped-text/EH-clear/thunk/scalar-destructor starts, eight `g_pMessageShowPane` refs, packet-handler constructor and wrapped-text callers, and MessageShowPane vtable store refs through `0x0061fa4c`, `0x0061fa98`, and `0x0061fac8`.
  - Direct support docs checked but not edited: the four by-file parents, target singleton globals, HourPane/Icon resource pages, MapTile layout/vtable/record pages, MessageShow read-only/vtable data pages, and the action-helper/global support around `0x005a4db0`-`0x005a5a80`.
- Blocker outcomes:
  - Resolved current low-confidence evidence gaps for method boundaries, singleton refs, vtable refs, resource/data links, and support coverage-row stale text.
  - `HourPane` remaining blockers are real: current IDA/docs do not prove the inherited pane cleanup source name, packet/interface name for the update virtual, or final field names for `+0x44` draw-region state and `+0xf8` current hour.
  - `IconsPane` remaining blockers are real: action helper callees are shared across IconsPane/TabPane/UserPane/MapPane contexts, and the raw dispatch body is executable/switch-shaped but still has no IDA function object, direct caller, or pointer-byte evidence.
  - `MapTileImageLib` remaining blockers are real: IDA proves behavior/layout but not final source-quality names for metadata/record fields, record flag semantics, helper declarations, or exact original folder.
  - `MessageShowPane` remaining blockers are real: current evidence proves class/vtable/singleton/packet reachability but not standalone `MessageShowPane.cpp` versus compact `MessageDialogs.cpp`, inherited base/interface names, or final text-builder helper name.
- Validation commands/results:
  - `python .\tools\validator.py --mode file --file by-class\HourPane.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\IconsPane.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\MapTileImageLib.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\MessageShowPane.md --apply --lock-timeout -1` -> `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --lock-timeout -1` -> `ok: 1`.
  - A compact rerun of the same five validators also returned `ok: 1` for each file.
- Leases used/release status:
  - Leased `by-class/HourPane.md`, `by-class/IconsPane.md`, `by-class/MapTileImageLib.md`, `by-class/MessageShowPane.md`, `by-class/-coverage-report.md`, and `tools/leaser/Agents/Agent-A002/notes.md`.
  - Release command for the five by-class paths reported `Rejected[No active lease]` for each path because the short leases had already expired during validation/checkpointing.
  - Follow-up `current_leases.md` showed no active A002 leases for the edited by-class files. Temporary notes-only placement-correction leases were acquired and released successfully after recording this status.
- IDA DB changes: none. No IDA renames, comments, type changes, function promotions, or saves were made.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: none. No by-memory documentation page was changed in this batch, so no shared memory coverage replacement/insert/delete rows are pending.

Supervisor integration update (2026-06-16): supervisor accepted `A002-goal2-class-confidence-hour-icons-maptile-message-20260616-58` as complete. Scores cleared the gate at [UID:000068] `86/88`, [UID:00006B] `86/88`, [UID:00007T] `86/88`, and [UID:000087] `86/88`; owner/emitter routes remain unchanged. Supervisor revalidated the four class pages and `by-class/-coverage-report.md` with scoped validator passes (`ok:1`). No A002 supervisor-owned memory rows remain pending for this batch.

## 2026-06-16 Assignment - A002-goal2-class-confidence-prime-queue-textbutton-timerqueue-20260616-59

Assigned targets:
- [UID:0000AT] `by-class/PrimeNumberGenerator.md`
- [UID:0000BF] `by-class/Queue.md`
- [UID:0000EJ] `by-class/TextButtonControlPane.md`
- [UID:0000F2] `by-class/TimerMgrTimerQueue.md`

Instructions:
- Read and follow `Agent-A002/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 low-confidence class batch from refreshed `project-level/-auto-completion-stats.md`. Supervisor quick-peek shows compact, already routed class pages at `85/85` with direct by-file parents and support pages: PrimeNumberGenerator utility, Queue fixed-slot container, TextButtonControlPane UI button, and TimerMgrTimerQueue embedded scheduler queue.
- Improve documentation, evidence quality, completion, and confidence where justified. Review direct by-file, by-memory, by-type, by-vtable, by-meta, and caller/support pages when the class evidence depends on them.
- Investigate final source-quality blockers now: active runtime use, raw helper reachability, generated-output omissions, helper/member/signature names, header/source placement, embedded versus standalone ownership, and final-C++ eligibility. Do not merely repeat blocker lists; resolve supported items, document exact evidence checked for unresolved blockers, or keep/lower scores if unresolved issues materially limit confidence.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and exact pending supervisor-owned report rows.

### Checkpoint - A002-goal2-class-confidence-prime-queue-textbutton-timerqueue-20260616-59

- Changed files:
  - `by-class/PrimeNumberGenerator.md`
  - `by-class/Queue.md`
  - `by-class/TextButtonControlPane.md`
  - `by-class/TimerMgrTimerQueue.md`
  - `by-class/-coverage-report.md`
  - Validator-owned/projected state refreshed by scoped validators: `project-level/-auto-completion-stats.md` and `tools/validator.ini`
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score changes and routing:
  - [UID:0000AT] `PrimeNumberGenerator`: `85/85 -> 86/87`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000MQ] `PrimeNumberGenerator`.
  - [UID:0000BF] `Queue`: `85/85 -> 86/86`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000MW] `Queue`.
  - [UID:0000EJ] `TextButtonControlPane`: `85/85 -> 86/88`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000OK] `TextButtonControlPane`.
  - [UID:0000F2] `TimerMgrTimerQueue`: `85/85 -> 86/88`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000OT] `TimerMgr`.
  - `by-class/-coverage-report.md` target rows updated to match the refreshed evidence and current scores.
- Blocker investigation:
  - `PrimeNumberGenerator`: live IDA MCP `lookup_funcs`, `xrefs_to`, and `callees` checked raw accessor `0x0054bcc0`, constructor `0x0054bcf0`, Deque helper `0x0054c0c0`, destructor `0x0054c110`, and vtable slot `0x00622420`. The raw accessor remains not a function, constructor/accessor still have zero direct refs, the Deque helper only has the raw accessor caller at `0x0054bce1`, and the vtable writes remain constructor/destructor-family only. Active runtime construction and final raw/helper names remain real blockers.
  - `Queue`: live IDA MCP checked constructor/destructor/scalar destructor and raw write/read/empty starts. Raw helpers remain not functions with zero direct refs; constructor and raw helper active-use evidence is still absent; vtable writes at `0x00553a15`, `0x00553a88`, and `0x00553b9f` confirm class identity. Final enqueue/dequeue/empty names and direct runtime use remain real blockers.
  - `TextButtonControlPane`: live IDA MCP checked method sizes, constructor/destructor/vtable refs, adjustor thunks, scalar deleting destructor, stale `0x004964e0`, and `DrawTextInRect` fanout. The stale `0x004964e0` row remains not a function with zero refs and stays excluded; `DrawTextInRect` returned a paged 100-ref result with `more:true`, including `OnPaint` as one dependency, so shared text-render ownership is not forced into this class.
  - `TimerMgrTimerQueue`: live IDA MCP checked helper sizes, xrefs, and callees for reverse/rotate/destructor/ensure-capacity/splice/insert. Active reachability is confirmed through `TimerMgr::ScheduleTimer`, removal helpers, and destructor paths; remaining blockers are source-quality helper/member/signature names and private helper declaration placement, not ownership or reachability.
- Validation:
  - `python .\tools\validator.py --mode file --file by-class\PrimeNumberGenerator.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\Queue.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\TextButtonControlPane.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\TimerMgrTimerQueue.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
- Leases:
  - Initial leases acquired successfully for the four target class pages, `by-class/-coverage-report.md`, and this notes file.
  - Release command for the five by-class/report paths returned `Rejected[No active lease]` because the 300-second leases expired during validation/checkpoint review; follow-up `current_leases.md` showed no active A002 entries.
  - A fresh notes-only lease was acquired to write this checkpoint; it was released successfully after the notes update, and final `current_leases.md` showed no active A002 entries.
- IDA DB changes: none. No IDA renames, comments, type changes, function promotions, or saves were made; the remaining names/source shapes were not safe to force into database metadata.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: none. No by-memory documentation file was edited in this batch, so no memory coverage replacement/insert/delete text is pending.

Supervisor integration update (2026-06-16): supervisor accepted `A002-goal2-class-confidence-newoption-scrollcollection-scrollspell-selectkeyboard-20260616-61` as complete. Scores cleared the gate at [UID:000097] `85/85 -> 86/87`, [UID:0000CG] `85/85 -> 86/88`, [UID:0000CN] `85/85 -> 86/88`, and [UID:0000CT] `85/85 -> 86/87`; owner/emitter routes remain unchanged. Supervisor revalidated the four class pages, support [UID:0001VZ] `ScrollCollectionPaneLayout`, support [UID:0001YP] `ScrollCollectionPaneVtables`, and `by-class/-coverage-report.md` with scoped validator passes (`ok:1`). No A002 supervisor-owned memory rows remain pending for this batch.

## 2026-06-16 Assignment - A002-goal2-type-confidence-browser-human-desc-layouts-20260616-62

Assigned targets:
- [UID:0001SK] `by-type/by-enum/BrowserInitFlags.md`
- [UID:0001UR] `by-type/by-struct/HumanImageLibLayout.md`
- [UID:0001SM] `by-type/by-enum/BrowserOverlayStyle.md`
- [UID:0001U3] `by-type/by-struct/DescPaneLayout.md`

Instructions:
- Read and follow `Agent-A002/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 bounded by-type confidence batch from refreshed `project-level/-auto-completion-stats.md`. Supervisor quick-peek shows known owner/emitter routes and direct support evidence: Browser private initializer/overlay constants, HumanImageLib object layout, and DescPane object/provider layout.
- Improve documentation, evidence quality, completion, and confidence where justified. Review direct owner class/file pages, by-memory support pages, by-global singleton pages, by-vtable pages, generated metadata, and caller/support pages when the type evidence depends on them.
- Investigate final source-quality blockers now: enum-vs-constant classification, final field/member/interface names, declaration/header placement, layout extent/order, provider/helper ownership, generated-output omissions, and final-C++ eligibility. Do not merely repeat blocker lists; resolve supported items, document exact evidence checked for unresolved blockers, or keep/lower scores if unresolved issues materially limit confidence.
- If any target expands into broad source-structure inference beyond the bounded type evidence, document the evidence and recommend B-agent escalation instead of forcing a conclusion.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and exact pending supervisor-owned report rows.

Supervisor integration update (2026-06-16): supervisor accepted `A002-goal2-class-confidence-miscwork-monster-motion-newhuman-20260616-60` as complete. Scores cleared the gate at [UID:00008I] `85/85 -> 86/87`, [UID:00008N] `85/85 -> 86/88`, [UID:00008R] `85/85 -> 86/87`, and [UID:000092] `85/85 -> 86/88`; owner/emitter routes remain unchanged. Supervisor revalidated the four class pages and `by-class/-coverage-report.md` with scoped validator passes (`ok:1`). No A002 supervisor-owned memory rows remain pending for this batch.

## 2026-06-16 Assignment - A002-goal2-class-confidence-newoption-scrollcollection-scrollspell-selectkeyboard-20260616-61

Assigned targets:
- [UID:000097] `by-class/NewOptionPane.md`
- [UID:0000CG] `by-class/ScrollCollectionPane.md`
- [UID:0000CN] `by-class/ScrollSpellInventoryPane.md`
- [UID:0000CT] `by-class/SelectObjectWithKeyboardPane.md`

Instructions:
- Read and follow `Agent-A002/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 low-confidence class batch from refreshed `project-level/-auto-completion-stats.md`. Supervisor quick-peek shows known-owned class pages at `85/85` with direct by-file parents and support evidence, not broad unknown-owner split status. `MapPane`, `LivingObjectPane`, and [UID:000194] `ListPane` memory work are being held for B-agent/heavy-heuristic routing.
- Improve documentation, evidence quality, completion, and confidence where justified. Review direct by-file, by-memory, by-global, by-type/by-vtable, by-resource, and caller/support pages when the class evidence depends on them.
- Investigate final source-quality blockers now: standalone-vs-folded source placement, raw helper reachability, generated-output omissions, vtable/layout anchors, final helper/type/member names, active caller routes, and final-C++ eligibility. Do not merely repeat blocker lists; resolve supported items, document exact evidence checked for unresolved blockers, or keep/lower scores if unresolved issues materially limit confidence.
- If any target expands into broad source-structure inference beyond the bounded class evidence, document the evidence and recommend B-agent escalation instead of forcing a conclusion.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and exact pending supervisor-owned report rows.

Supervisor integration update (2026-06-16): supervisor accepted `A002-goal2-class-confidence-prime-queue-textbutton-timerqueue-20260616-59` as complete. Scores cleared the gate at [UID:0000AT] `85/85 -> 86/87`, [UID:0000BF] `85/85 -> 86/86`, [UID:0000EJ] `85/85 -> 86/88`, and [UID:0000F2] `85/85 -> 86/88`; owner/emitter routes remain unchanged. Supervisor revalidated the four class pages and `by-class/-coverage-report.md` with scoped validator passes (`ok:1`). No A002 supervisor-owned memory rows remain pending for this batch.

### Checkpoint - A002-goal2-class-confidence-newoption-scrollcollection-scrollspell-selectkeyboard-20260616-61

- Changed files:
  - `by-class/NewOptionPane.md`
  - `by-class/ScrollCollectionPane.md`
  - `by-class/ScrollSpellInventoryPane.md`
  - `by-class/SelectObjectWithKeyboardPane.md`
  - `by-type/by-struct/ScrollCollectionPaneLayout.md`
  - `by-type/by-vtable/ScrollCollectionPaneVtables.md`
  - `by-class/-coverage-report.md`
  - Validator-owned/projected state refreshed by scoped validators: `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and generated autogen metadata/reports as no-op/autogen-refresh side effects.
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score changes and routing:
  - [UID:000097] `NewOptionPane`: `85/85 -> 86/87`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000M7] `OptionPane`.
  - [UID:0000CG] `ScrollCollectionPane`: `85/85 -> 86/88`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000NG] `ScrollCollectionPane`.
  - [UID:0000CN] `ScrollSpellInventoryPane`: `85/85 -> 86/88`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000NJ] `ScrollSpellInventoryPane`.
  - [UID:0000CT] `SelectObjectWithKeyboardPane`: `85/85 -> 86/87`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000OH] `TargetSelectionInputPanes`.
  - Support docs [UID:0001VZ] `ScrollCollectionPaneLayout` and [UID:0001YP] `ScrollCollectionPaneVtables` kept scores/routes unchanged; stale parent-gate text was updated after the class/file parents reached `86/88` and `86/85`.
  - `by-class/-coverage-report.md` target rows updated to match refreshed evidence and completion scores.
- Blocker investigation:
  - `NewOptionPane`: live IDA MCP session `b001_mappane_0001AW_20260616` confirmed method map and scalar destructor sizes, constructor/vtable/destructor refs, option-only paint helper caller sets, and `SendOptionPacket11B` caller split. `0x00540ea0` remains `Not a function` with zero xrefs; promoted helpers `0x00540ef0`, `0x00540f50`, and `0x00540ff0` still have zero xrefs. Remaining blockers are final option-entry field names, no-xref helper source visibility, and config/packet helper declarations.
  - `ScrollCollectionPane`: live IDA confirmed modeled helper sizes, sole constructor caller `0x0056e9b6`, range/current/enable callers, raw starts `0x00562e80`, `0x00562ef0`, and `0x00563200` as non-functions with zero xrefs, vtable stores, raw prologue bytes, and clear-helper tail/padding. Remaining blockers are standalone `ScrollCollectionPane.cpp` versus `ScrollBar.cpp`, raw helper declaration names, and final field/member names.
  - `ScrollSpellInventoryPane`: live IDA confirmed method inventory, sole `NewSpellInventoryPane` constructor caller `0x0057d013`, range/current/activate caller routes, raw hover/reset non-function starts, zero xrefs to raw reset `0x005608a0`, vtable stores, and reset-helper padding. Remaining blockers are standalone file versus private fold into `NewSpellInventoryPane.cpp`, raw helper declaration names, and final scrollbar field names.
  - `SelectObjectWithKeyboardPane`: live IDA confirmed method/thunk function objects, constructor callers `0x005a5f75` and `0x005ad4e9`, prompt xref `0x005af648`, vtable stores, object-list vtable-only route, clear/forward helper callers, singleton slot refs, and saved-target refs. Remaining blockers are final target-state global/member names and exact target-selection source/header split.
- Validation:
  - `python .\tools\validator.py --mode file --file by-class\NewOptionPane.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\ScrollCollectionPane.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\ScrollSpellInventoryPane.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\SelectObjectWithKeyboardPane.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-type\by-struct\ScrollCollectionPaneLayout.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-type\by-vtable\ScrollCollectionPaneVtables.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
- Leases:
  - Leased the four target class pages, `by-class/-coverage-report.md`, `by-type/by-struct/ScrollCollectionPaneLayout.md`, `by-type/by-vtable/ScrollCollectionPaneVtables.md`, and this notes file before editing.
  - Release command after validation/checkpointing returned `Rejected[No active lease]` for each edited path because the short leases had already expired; final `current_leases.md` check showed no active A002 entries, only unrelated C001 leases.
- IDA DB changes: none. No IDA renames, comments, type changes, function promotions, or saves were made; remaining helper/member/source names were not safe to force into database metadata from the class-level pass.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: none. No by-memory documentation file was edited in this batch, so no memory coverage replacement/insert/delete text is pending.

## 2026-06-16 Assignment - A002-goal2-class-confidence-miscwork-monster-motion-newhuman-20260616-60

Assigned targets:
- [UID:00008I] `by-class/MiscWorkThread.md`
- [UID:00008N] `by-class/MonsterImageLib.md`
- [UID:00008R] `by-class/Motion.md`
- [UID:000092] `by-class/NewHumanImageLib.md`

Instructions:
- Read and follow `Agent-A002/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 low-confidence class batch from refreshed `project-level/-auto-completion-stats.md`. Supervisor quick-peek shows known-owned class pages at `85/85` with direct by-file parents and support evidence, not broad unknown-owner split status.
- Improve documentation, evidence quality, completion, and confidence where justified. Review direct by-file, by-memory, by-global, by-type/by-vtable, by-resource, and caller/support pages when the class evidence depends on them.
- Investigate final source-quality blockers now: singleton/vtable/layout/resource/table/helper/source-file placement, active reachability, generated-output omissions, final field/member/type names, and final-C++ eligibility. Do not merely repeat blocker lists; resolve supported items, document exact evidence checked for unresolved blockers, or keep/lower scores if unresolved issues materially limit confidence.
- If any target expands into broad source-structure inference beyond the bounded class evidence, document the evidence and recommend B-agent escalation instead of forcing a conclusion.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and exact pending supervisor-owned report rows.

### Checkpoint - A002-goal2-class-confidence-miscwork-monster-motion-newhuman-20260616-60

- Changed files:
  - `by-class/MiscWorkThread.md`
  - `by-class/MonsterImageLib.md`
  - `by-class/Motion.md`
  - `by-class/NewHumanImageLib.md`
  - `by-class/-coverage-report.md`
  - Validator-owned/projected state refreshed by scoped validators: `project-level/-auto-completion-stats.md` and `tools/validator.ini`
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score changes and routing:
  - [UID:00008I] `MiscWorkThread`: `85/85 -> 86/87`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000LG] `MiscWorkThread`.
  - [UID:00008N] `MonsterImageLib`: `85/85 -> 86/88`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000LJ] `MonsterImageLib`.
  - [UID:00008R] `Motion`: `85/85 -> 86/87`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000LL] `Motion`.
  - [UID:000092] `NewHumanImageLib`: `85/85 -> 86/88`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000LR] `NewHumanImageLib`.
  - `by-class/-coverage-report.md` target rows updated to match refreshed evidence and scores.
- Blocker investigation:
  - `MiscWorkThread`: live IDA MCP checked function status, xrefs, and callees for worker helpers `0x005277c0` through `0x00528560`, singleton `0x0067ab50`, and vtable `0x0061fb74`. Constructor caller, vtable-backed `ProcessWorkItem`, modeled HTTP/NCA producer callers, singleton/vtable refs, and `Thread` queue helper dispatch are confirmed. Raw browse-directory `0x005283b0` remains `Not a function` with zero refs, so wrapper promotion/name/source placement remains a real blocker.
  - `MonsterImageLib`: live IDA MCP checked local method/helper sizes, constructor caller, vtable writes, 22 singleton refs, singleton-clear cleanup-table ref, `VectorGrowArchiveIndex` single caller from `LoadMonsterArchives`, fallback-record refs, and constructor/destructor/cache-loader callees. Remaining blockers are table/cache field names, shared table-helper declarations, archive-bounds member names, and exact fallback-storage source placement.
  - `Motion`: live IDA MCP checked exact animation function sizes, primary constructor reachability, alternate constructor zero-ref status, timer/destructor vtable refs, static pool refs, and constructor/timer/destructor callees. Region, MessageDialogs, NewHumanImageLib, and LObject exclusions remain supported. Remaining blockers are alternate-constructor declaration, final field/member names, and exact original source-file name.
  - `NewHumanImageLib`: live IDA MCP checked main method/helper sizes, startup constructor caller, singleton/vtable refs, cleanup-table helper ref, 52 singleton refs, `VectorGrowMotion` and `DestroyMotionVector` caller sets, constructor/render/bounds callees, and exact scalar-deleting destructor page availability. Remaining blockers are table/vector field names, row-layout type names, helper declaration placement, and disabled owner-relevant helper source names.
- Validation:
  - `python .\tools\validator.py --mode file --file by-class\MiscWorkThread.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\MonsterImageLib.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\Motion.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\NewHumanImageLib.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
- Leases:
  - Initial leases acquired successfully for the four target class pages, `by-class/-coverage-report.md`, and this notes file.
  - Released `by-class/MiscWorkThread.md`, `by-class/MonsterImageLib.md`, `by-class/Motion.md`, `by-class/NewHumanImageLib.md`, and `by-class/-coverage-report.md` successfully after validation.
  - Notes lease will be released immediately after this checkpoint update; final lease check should show no active A002 entries.
- IDA DB changes: none. No IDA renames, comments, type edits, function promotions, or saves were made; remaining helper/member/source names are not safe to force into database metadata from class-level evidence.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: none. No by-memory documentation file was edited in this batch, so no memory coverage replacement/insert/delete text is pending.

### Checkpoint - A002-goal2-type-confidence-browser-human-desc-layouts-20260616-62

- Changed files:
  - `by-type/by-enum/BrowserInitFlags.md`
  - `by-type/by-enum/BrowserOverlayStyle.md`
  - `by-type/by-struct/HumanImageLibLayout.md`
  - `by-type/by-struct/DescPaneLayout.md`
  - `by-type/by-enum/-coverage-report.md`
  - `by-type/by-struct/-coverage-report.md`
  - Validator-owned/projected state refreshed by scoped validators: `project-level/-auto-completion-stats.md`, `auto-generated/-ag-type-coverage.md`, and `tools/validator.ini`
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score changes and routing:
  - [UID:0001SK] `BrowserInitFlags`: `85/87 -> 86/88`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000HV] `Browser`.
  - [UID:0001SM] `BrowserOverlayStyle`: `85/88 -> 86/89`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000HV] `Browser`.
  - [UID:0001UR] `HumanImageLibLayout`: `85/87 -> 87/89`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:00006A] `HumanImageLib`.
  - [UID:0001U3] `DescPaneLayout`: `85/88 -> 86/89`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:00003Q] `DescPane`.
  - By-type enum/struct coverage rows were updated to match refreshed completion and evidence.
- Blocker investigation:
  - `BrowserInitFlags`: live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed constructor `0x0046ff50` size `0x209`, caller `0x0046936e`, Browser vtable stores, nearby member clears, exact `0x0101` write at Browser offset `+0x22c`, and `+0x230` member construction. `type_query`/`search_structs` found no Browser/BrowserInit local type, so enum-vs-bitmask and final field-name blockers remain real.
  - `BrowserOverlayStyle`: live IDA reconfirmed `DrawBrowserStatusOverlay` at `0x0046f220` size `0xef`, vtable-only xref `0x006137c4`, overlay gate at `this+0x110 -> +0x222`, localized id `236`, style argument `128`, and final draw call. `xrefs_to` hit the requested cap with at least 120 refs each to `0x004b9680` and `0x004f0350`; `type_query Overlay` only found DirectDraw SDK types and `type_query Browser` found no Browser enum, so final enum-vs-constant/helper-owner blockers remain real.
  - `HumanImageLibLayout`: live IDA reconfirmed constructor/destructor/helper/scalar-wrapper function status, no direct constructor caller, vtable/singleton support, and destructor handle/cached-pointer cleanup. Constructor string xrefs resolved the six `WeaponInfo` arrays: `sword/spear/bow/fan/shield/arrow` map to `+0x80/+0xa0/+0xc0/+0xe0/+0x100/+0x120`. `type_query`/`search_structs HumanImageLib` found no local UDT, so exact original member names and declaration order remain real blockers.
  - `DescPaneLayout`: live IDA reconfirmed raw constructor/setter starts `0x0049d6f0` and `0x0049d780` remain non-functions, modeled methods through `0x0049d840`, raw constructor writes to `+0xf8/+0xfc` and `g_pDescPane`, raw setter comparisons/stores plus vtable-slot dispatch, exact singleton/vtable xref sets, and `RefreshDescription` vtable-only route. No local DescPane/provider UDT was found, so provider-interface and raw-helper source names remain real blockers.
- Validation:
  - `python .\tools\validator.py --mode file --file by-type\by-enum\BrowserInitFlags.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-type\by-enum\BrowserOverlayStyle.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-type\by-struct\HumanImageLibLayout.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-type\by-struct\DescPaneLayout.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-type\by-enum\-coverage-report.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-type\by-struct\-coverage-report.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
- Leases:
  - Leased the four target type pages, `by-type/by-enum/-coverage-report.md`, `by-type/by-struct/-coverage-report.md`, and this notes file before editing.
  - Release command after validation/checkpointing returned `Rejected[No active lease]` for the target/report paths and notes because the 300-second leases had expired; follow-up `current_leases.md` showed no active A002 entries.
  - A fresh notes-only lease was acquired to correct this release-status note and was released successfully; final `current_leases.md` showed no active A002 entries.
- IDA DB changes: none. No IDA renames, comments, type changes, function promotions, or saves were made because the remaining names/types are not safe to force from current evidence.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: none. No by-memory documentation file was edited in this batch, so no replacement/insert/delete text is pending.

### Checkpoint - A002-goal2-type-confidence-effect-employee-layouts-20260616-63

- Changed files:
  - `by-type/by-struct/EffectFrameRecord.md`
  - `by-type/by-struct/EffectInfo.md`
  - `by-type/by-struct/EffectObjImageLibLayout.md`
  - `by-type/by-struct/EmployeeRecord.md`
  - `by-type/by-struct/-coverage-report.md`
  - Direct support sync: `by-file/EffectObjImageLib.md`, `by-class/EffectObjImageLib.md`
  - Validator-owned/projected state refreshed by scoped validators: `project-level/-auto-completion-stats.md` and `tools/validator.ini` (autogen reports were checked by validator; no manual edits)
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score changes and routing:
  - [UID:0001U7] `EffectFrameRecord`: `85/88 -> 86/89`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000IY] `EffectObjImageLib` file.
  - [UID:0001U8] `EffectInfo`: `85/88 -> 86/89`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000IY] `EffectObjImageLib` file.
  - [UID:0001U9] `EffectObjImageLibLayout`: `85/88 -> 86/89`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:00004A] `EffectObjImageLib` class.
  - [UID:0001UD] `EmployeeRecord`: `85/88 -> 86/89`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:00004C] `EmployeeDialogPane` class.
  - `by-type/by-struct/-coverage-report.md` rows updated to match refreshed scores/evidence.
  - Support pages `by-file/EffectObjImageLib.md` and `by-class/EffectObjImageLib.md` had stale generated-output caveats corrected but no score changes.
- Source-quality blocker investigation:
  - Effect layout/records: live IDA MCP session `b001_mappane_0001AW_20260616` checked `lookup_funcs`, `analyze_function`, and xrefs for `0x004de190`, `0x004de3e0`, `0x004de7d0`, `0x005387b0`, `0x005389d0`, `0x00538af0`, `0x0061b724`, and `0x0069b44c`. The current evidence confirms `0x34` `EffectInfo` copies, two 24-byte sequence headers, `0x10` `EffectFrameRecord` stride, render/update consumers, three vtable-store refs, and 12 singleton refs. Active `class_EffectObjImageLib.cpp` and `.meta_wave3` were checked: no disabled companion and `vtable_count: 1`, but `RenderEffectFrame` remains incomplete/effective-excluded and generated member/helper names are still not source-quality. Final field/member names remain a real blocker; no B-agent escalation needed because ownership/layout evidence is bounded.
  - Employee record: live IDA MCP checked parser/load/update function status and callers at `0x004a34d0`, `0x004a3a90`, `0x004a3e10`, parser xrefs `0x004a300d/0x004a3bb1/raw 0x004a3c05`, and raw helper starts `0x004a3650`, `0x004a37a0`, `0x004a3830`, `0x004a38d0`, `0x004a3960`, `0x004a39d0`, `0x004a3a30`, `0x004a3be0`, and `0x004a3ca0`. Raw starts still have no xrefs/function objects; disassembly confirms `0x004a3be0` uses a stack `0x420` record and `0x41c` copy stride, and `0x004a3ca0` removes/rebuilds/repaints. Active generated EmployeeDialog/EmployeeItemProperty files were checked and provide useful hints (`spriteId`, `paletteId`, `priceValue`, `editValue`) but use inconsistent local overlays, so final `EmployeeRecord` member names remain unsafe.
- Validation:
  - `python .\tools\validator.py --mode file --file by-type/by-struct/EffectFrameRecord.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`; completion/confidence updates recorded.
  - `python .\tools\validator.py --mode file --file by-type/by-struct/EffectInfo.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`; completion/confidence updates recorded.
  - `python .\tools\validator.py --mode file --file by-type/by-struct/EffectObjImageLibLayout.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`; completion/confidence updates recorded.
  - `python .\tools\validator.py --mode file --file by-type/by-struct/EmployeeRecord.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`; completion/confidence updates recorded.
  - `python .\tools\validator.py --mode file --file by-type/by-struct/-coverage-report.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file/EffectObjImageLib.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class/EffectObjImageLib.md --apply --lock-timeout -1` -> exit `0`, `ok: 1`.
- Leases:
  - Initial leases acquired successfully for the four target pages, `by-type/by-struct/-coverage-report.md`, `by-file/EffectObjImageLib.md`, `by-class/EffectObjImageLib.md`, and this notes file.
  - Target/report/support release attempt after validation returned `Rejected[No active lease]` for those seven paths because the 300-second leases had expired during validation/checkpointing.
  - A fresh notes-only lease was acquired before writing this checkpoint and will be released immediately after this update; final lease check should show no active A002 entries.
- IDA DB changes: none. No IDA comments, renames, type edits, function promotions, or database saves were made; generated/source-quality names are still not safe to force into the IDA DB.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: none. No by-memory documentation file was edited, so no replacement/insert/delete text is pending.

## 2026-06-16 Checkpoint - A002-goal2-generated-support-completion-batch-20260616-65

- Changed files:
  - `by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md`
  - Renamed `by-memory/0x0061fe3c-0x0061fecc.CreateUserDialogPaneVtableData.md` -> `by-memory/0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData.md`
  - `by-memory/0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData.md`
  - Direct support reference sync: `by-class/CreateUserDialogPane.md`, `by-file/CreateUserDialogPane.md`
  - Validator-owned/projected state refreshed by scoped validators: `project-level/-auto-completion-stats.md`, `auto-generated/-ag-*`, and `tools/validator.ini`
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score changes and routing:
  - [UID:0001CS] `FunctionObjectTConstStringDestructors`: `80/88 -> 85/90`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000JO] `FunctionObjects`; final C++ remains blank because the page is source-declared/generated-binary template destructor support.
  - [UID:0002SI] `CreateUserDialogPaneVtableData`: `80/88 -> 86/90`; range corrected to `0x0061fe3c-0x0061fed8`; owner/emitter changed from umbrella [UID:0000IK] `CreateUserDialogs` to direct class [UID:00003B] `CreateUserDialogPane`, which emits through [UID:0000IJ] `CreateUserDialogPane`; final C++ remains blank because this vtable data should be compiler-emitted from class declarations.
  - Support aggregate [UID:00025Z] `CreateUserRegistrationReadOnlyData` kept `86/91` and `RECONSTRUCTABLE:FALSE`, but its child inventory now records the corrected [UID:0002SI] range and direct class route.
- Source-quality/blocker investigation:
  - FunctionObject const-string destructors: live IDA MCP session `a002_goal65_20260616` checked `lookup_funcs`, `xrefs_to`, `callees`, `entity_query`, and `decompile` for `0x0052f780`, `0x0052f7c0`, endpoint probes, and vtable bases `0x0061ff58`, `0x0061ff70`, `0x0062004c`, `0x00620094`, and `0x00622cf4`. IDA reconfirmed both exact `0x3e` destructor bodies, no endpoint functions, vtable-only refs, shared `sub_4F4A90`/`sub_4F4AC0` cleanup/delete callees, decorated concrete `PlainMemberFunctionObjectT<...StringBase... const&>` names, and create-user/Nexonclub consumer construction-site refs. Exact original template/header spelling and emitted-instantiation consolidation remain unresolved, so no final C++ was entered.
  - CreateUserDialogPane vtable data: live IDA checked names, raw bytes, `lookup_funcs`, and `xrefs_to` around `0x0061fe20-0x0061fee8`. IDA confirmed table bases `0x0061fe3c`, `0x0061fe9c`, and `0x0061fecc`; successor callback table base `0x0061fed8`; constructor stores at `0x0052dda2/0x0052dda8/0x0052ddb2`; fallback/cleanup stores at `0x0052e6f9/0x0052e6ff/0x0052e709`; destructor stores at `0x0052f80c/0x0052f812/0x0052f81c`; representative slots `0x0052f800`, `0x0052f73b`, and `0x0052f746`; and `0x0061fed8` refs only from `NewUserDialogPane2` callback construction. Inherited interface names and final class declaration spelling remain the source-quality blockers.
- Validation:
  - `python .\tools\validator.py --mode file --file by-memory\0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\CreateUserDialogPane.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\CreateUserDialogPane.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
- Leases:
  - Leased both target docs, the renamed target path after the move, support docs `by-memory/0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData.md`, `by-class/CreateUserDialogPane.md`, `by-file/CreateUserDialogPane.md`, and this notes file before editing.
- IDA DB changes: none. No IDA comments, renames, type edits, function promotions, patches, or saves were made.
- Pending supervisor-owned `by-memory/-coverage-report.md` row replacements:
  - Replace existing [UID:0001CS] row with:
    `    - [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md) 0x0052f780-0x0052f7fe | template destructor | FunctionObjectTConstStringDestructors : reconstructable : 85% : strong : A002 2026-06-16 generated-support refresh keeps owner/emitter [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), reconfirming exact 0x3e destructor bodies, endpoint non-functions, vtable-only refs, cleanup/delete callees, decorated const-StringBase callback vtable names, create-user/Nexonclub consumer separation, source-declared/generated-binary handling, and blank final C++ while final template/header spelling remains open.`
  - Replace existing [UID:0002SI] row with:
    `        - [UID:0002SI][0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData](by-memory/0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData.md) 0x0061fe3c-0x0061fed8 | vtable-data | CreateUserDialogPaneVtableData : reconstructable : 86% : strong : A002 2026-06-16 generated-support refresh corrects the range through tertiary table base 0x0061fecc and successor callback boundary 0x0061fed8, routes owner/emitter to direct class [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md), and records live IDA named table bases, constructor/fallback/destructor refs, representative slot dwords, source-declared/generated-binary handling, and blank final C++ while inherited-interface/class declaration spelling remains open.`

## 2026-06-16 Checkpoint - A002-goal2-decoder-keyspeed-baramapp-support-20260616

- Changed files:
  - `by-memory/0x004a5df0-0x004a5df1.DecoderNoopVirtual.md`
  - `by-memory/0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor.md`
  - `by-memory/0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw.md`
  - `by-memory/0x004f66c0-0x004f66fb.BaramAppScalarDeletingDestructor.md`
  - Validator-owned/projected state refreshed by scoped validators: `project-level/-auto-completion-stats.md`, `auto-generated/-ag-*`, and `tools/validator.ini`
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score changes and routing:
  - [UID:00013T] `DecoderNoopVirtual`: `80/90 -> 85/90`; owner/emitter remain [UID:00004F] `Decoder`; final C++ remains blank because this is compiler/vtable support and the original virtual declaration name is unresolved.
  - [UID:00013U] `DecoderScalarDeletingDestructor`: `80/90 -> 85/90`; owner/emitter remain [UID:00004F] `Decoder`; final C++ remains blank because this is compiler-generated scalar deleting destructor support and final class/destructor declaration spelling is unresolved.
  - [UID:0002IS] `KeySpeedMgrApplyKeyboardRepeatSettingsRaw`: `80/90 -> 85/90`; owner/emitter remain [UID:0000HJ] `KeySpeedMgr`; final C++ remains blank because the raw island still has no function object, no xrefs/caller, no source-retention reason, and no recovered original helper name.
  - [UID:0002Q2] `BaramAppScalarDeletingDestructor`: `80/90 -> 85/90`; owner/emitter remain [UID:0000H8] `Application`; final C++ remains blank because this is compiler-generated destructor wrapper support and BaramApp/Application source split/layout names are still unresolved.
- Evidence searched:
  - Decoder docs/read-only data: `by-class/Decoder.md`, `by-file/Decoder.md`, `by-file/BinaryCodec.md`, `by-type/by-vtable/BinaryCodecVtables.md`, `by-memory/0x006192d4-0x006192e0.DecoderVtableData.md`, `by-memory/0x006192c6-0x00619340.BinaryCodecDatReadOnlyData.md`, `by-memory/0x004a5670-0x004a5677.DecoderDestructor.md`, `by-memory/0x004a5640-0x004a5664.DecoderConstructor.md`, and `by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md`.
  - KeySpeedMgr docs/layout/vtable/helpers: `by-file/KeySpeedMgr.md`, `by-class/KeySpeedMgr.md`, `by-type/by-struct/KeySpeedMgrLayout.md`, `by-type/by-vtable/KeySpeedMgrVtable.md`, `by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md`, constructor/destructor/load/restore/fast-repeat/scalar helper pages, `by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md`, `by-global/g_pKeySpeedMgr.md`, `by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md`, and `by-memory/0x0061c9c4-0x0061c9dc.KeySpeedMgrVtableData.md`.
  - BaramApp/Application support: `by-class/BaramApp.md`, `by-class/Application.md`, `by-file/Application.md`, `by-memory/0x00463970-0x004639c4.ApplicationDestructor.md`, `by-memory/0x004f66b5-0x004f66bd.BaramAppDeletingDestructorThunk.md`, `by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md`, `by-memory/0x0061d118-0x0061d264.BaramAppReadOnlyData.md`, BaramApp rdata children, BaramApp raw constructor/startup/shutdown pages, and `by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md`.
  - Generated sources checked: `auto-generated/NexusTK/util/Decoder.cpp` is empty, `auto-generated/NexusTK/input/KeySpeedMgr.cpp` is empty, and `auto-generated/NexusTK/app/Application.cpp` only emits `Application::CopyWorldName` and `Application::CopyPlayerName` with no BaramApp scalar-destructor body.
- Source-quality blockers and resolutions:
  - [UID:00013T] `DecoderNoopVirtual`: resolved as one-byte `ret` vtable support, vtable-only reference at `0x006192dc`, and Decoder/BinaryCodec ownership. The original source-level virtual method/declaration name remains unresolved after checking class/file/vtable docs and empty generated `Decoder.cpp`, so no final C++ was entered.
  - [UID:00013U] `DecoderScalarDeletingDestructor`: resolved as the vtable scalar deleting destructor wrapper at `0x006192d8`, paired with ordinary `Decoder::~Decoder` at `0x004a5670` and delete-on-flag behavior. Final destructor/class declaration spelling and whether the wrapper should appear in handwritten source remain unresolved after checking Decoder/BinaryCodec support and empty generated `Decoder.cpp`, so no final C++ was entered.
  - [UID:0002IS] `KeySpeedMgrApplyKeyboardRepeatSettingsRaw`: resolved stack roles and constants (`SPI_SETKEYBOARDDELAY` `0x17`, `SPI_SETKEYBOARDSPEED` `0x0b`, `SPIF_UPDATEINIFILE`), `KeySpeedMgr` file-local placement, and sibling consistency with restore/fast-repeat helpers. The raw start still has no IDA function object, no callers/xrefs, no retention proof, and only a descriptive helper label rather than original source spelling after checking class/file/layout/vtable/global/destructor paths and empty generated `KeySpeedMgr.cpp`, so no final C++ was entered.
  - [UID:0002Q2] `BaramAppScalarDeletingDestructor`: resolved primary vtable reachability at `0x0061d118`, secondary thunk route `0x0061d138 -> 0x004f66b5 -> 0x004f66c0`, `ApplicationDestructor` delegation, delete-flag branches, and `OperatorDeleteWrapper` linkage. BaramApp/Application class layout, secondary-base spelling, and source split remain unresolved after checking class/file/read-only/startup aggregate docs and generated `Application.cpp`, so no final C++ was entered.
- Validation:
  - `python .\tools\validator.py --mode file --file by-memory\0x004a5df0-0x004a5df1.DecoderNoopVirtual.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`; completion update [UID:00013T] `85`, `Low_Completion` stats removal, reference index update, registry rebuild, autogen no-op.
  - `python .\tools\validator.py --mode file --file by-memory\0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`; completion update [UID:00013U] `85`, `Low_Completion` stats removal, reference index update, registry rebuild, autogen no-op.
  - `python .\tools\validator.py --mode file --file by-memory\0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`; completion update [UID:0002IS] `85`, `Low_Completion` stats removal, registry rebuild, autogen no-op.
  - `python .\tools\validator.py --mode file --file by-memory\0x004f66c0-0x004f66fb.BaramAppScalarDeletingDestructor.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`; completion update [UID:0002Q2] `85`, `Low_Completion` stats removal, reference index update, registry rebuild, autogen no-op.
- Leases:
  - Initial leases were acquired for the four by-memory target pages and this notes file before editing.
  - After validation/checkpoint prep, `current_leases.md` showed no active leases because the initial 300-second leases had expired; a fresh notes-only lease was acquired before writing this checkpoint and will be released immediately after this update.
- IDA DB changes: none. No IDA comments, renames, type edits, function promotions, patches, or database saves were made.
- Pending supervisor-owned `by-memory/-coverage-report.md` row replacements:
  - Placement: under `0x004a5630-0x004a5e54 DecoderAndCodecVtableGlue`, replace existing [UID:00013T] and [UID:00013U] rows immediately after [UID:00013S] `DecoderFinalize` and before [UID:00013V] `EncoderScalarDeletingDestructor` with:
    `    - [UID:00013T][0x004a5df0-0x004a5df1.DecoderNoopVirtual](by-memory/0x004a5df0-0x004a5df1.DecoderNoopVirtual.md) 0x004a5df0-0x004a5df1 | vtable support | DecoderNoopVirtual : reconstructable : 85% : strong : A002 2026-06-16 source-quality audit proves the one-byte Decoder no-op virtual support slot, vtable-only ref at 0x006192dc, owner/source-root chain through Decoder/BinaryCodec support docs, empty generated Decoder.cpp, and compiler/vtable-source treatment; final C++ remains blank while the original virtual declaration name remains unresolved.`
    `    - [UID:00013U][0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor](by-memory/0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor.md) 0x004a5e00-0x004a5e24 | scalar deleting destructor | DecoderScalarDeletingDestructor : reconstructable : 85% : strong : A002 2026-06-16 source-quality audit proves the Decoder scalar deleting destructor vtable slot at 0x006192d8, ordinary destructor pairing, compiler-wrapper source treatment, owner/source-root chain, and empty generated Decoder.cpp; final C++ remains blank while final Decoder destructor/class declaration and raw-reader source quality remain unresolved.`
  - Placement: under the KeySpeedMgr aggregate, replace existing [UID:0002IS] row after padding `0x004eff5d-0x004eff60` and before padding `0x004eff91-0x004effa0` with:
    `        - [UID:0002IS][0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw](by-memory/0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw.md) 0x004eff60-0x004eff91 | raw-helper | KeySpeedMgr apply keyboard repeat settings : reconstructable : 85% : strong : A002 2026-06-16 source-quality audit keeps this as a file-local KeySpeedMgr helper, resolving stack delay/speed roles, SPI_SETKEYBOARDDELAY/SPEED constants 0x17/0x0b, SPIF_UPDATEINIFILE, sibling restore/fast-repeat consistency, generated KeySpeedMgr.cpp emptiness, and no-this placement; final C++ remains blank because the raw start still has no IDA function object, no xrefs/caller, no source-retention reason, and no recovered original helper name.`
  - Placement: under the BaramAppAndApplicationStartup aggregate, replace existing [UID:0002Q2] row after [UID:0002Q1] thunk and before padding `0x004f66fb-0x004f6700` with:
    `        - [UID:0002Q2][0x004f66c0-0x004f66fb.BaramAppScalarDeletingDestructor](by-memory/0x004f66c0-0x004f66fb.BaramAppScalarDeletingDestructor.md) 0x004f66c0-0x004f66fb | class method | BaramAppScalarDeletingDestructor : reconstructable : 85% : strong : A002 2026-06-16 source-quality audit proves primary vtable reachability 0x0061d118, secondary thunk route 0x0061d138 -> 0x004f66b5 -> 0x004f66c0, ApplicationDestructor delegation, delete-flag branches, MemoryMan delete-wrapper role, generated Application.cpp absence for BaramApp, and compiler-wrapper source treatment; final C++ remains blank while BaramApp/Application class layout, secondary-base spelling, and source split remain unresolved.`

## 2026-06-16 Checkpoint - A002-goal2-spell-input-pane-batch-20260616

- Changed files:
  - `by-memory/0x005b0780-0x005b080d.SpellFourArgsInputPaneConstructor.md`
  - `by-memory/0x005b08a0-0x005b0a02.SpellFourArgsInputPaneConfirmInput.md`
  - `by-memory/0x005b0ac0-0x005b0b4d.SpellThreeArgsInputPaneConstructor.md`
  - `by-memory/0x005b0be0-0x005b0cfd.SpellThreeArgsInputPaneConfirmInput.md`
  - Validator-owned/projected state refreshed by scoped validators: `project-level/-auto-completion-stats.md` and `tools/validator.ini`; validator reported an unrelated stale registry notice for missing [UID:0003VS] `TextDialogRawStringReplyPacketHelper.md` but returned success.
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score changes and routing:
  - [UID:0001LM] `SpellFourArgsInputPaneConstructor`: `82/86 -> 86/90`; `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000DL] `SpellFourArgsInputPane`; source root remains [UID:0000O0] `SpellInputPanes`.
  - [UID:0001LO] `SpellFourArgsInputPaneConfirmInput`: `82/86 -> 86/89`; owner/emitter remain [UID:0000DL] `SpellFourArgsInputPane`; source root remains [UID:0000O0] `SpellInputPanes`.
  - [UID:0001LP] `SpellThreeArgsInputPaneConstructor`: `82/86 -> 86/90`; owner/emitter remain [UID:0000DV] `SpellThreeArgsInputPane`; source root remains [UID:0000O0] `SpellInputPanes`.
  - [UID:0001LQ] `SpellThreeArgsInputPaneConfirmInput`: `82/86 -> 86/89`; owner/emitter remain [UID:0000DV] `SpellThreeArgsInputPane`; source root remains [UID:0000O0] `SpellInputPanes`.
  - All four pages remain `RECONSTRUCTABLE: TRUE` and `EMITS: TRUE`; final C++ stays blank because final member/helper names and raw-helper split policy are not source-quality safe.
- Evidence checked:
  - Read agent instructions, current supervisor policy, notes, `by-memory/-guidance.md`, proposed source tree, and spell input support pages: `by-file/SpellInputPanes.md`, both class pages, aggregate [UID:0001LN], `LineInputPaneSetPromptText`, packet-buffer/send helpers, `g_packetSender`, `g_pCollectionData`, string/two/one-argument sibling pages, and dispatcher [UID:0001FE].
  - Live read-only IDA MCP session `a001_goal2_00023O` checked `lookup_funcs`, `decompile`, `disasm`, `entity_query`, `xrefs_to`, `callees`, `get_bytes`, and `find_bytes` for `0x005b0780`, `0x005b08a0`, `0x005b0ac0`, `0x005b0be0`, neighboring destructor starts, inline factory `0x005a4530`, raw helper starts `0x005b0a10` and `0x005b0d00`, and relevant vtable roots.
  - `int_convert.py` verified byte/decimal conversions for `0x148`/328, `0x108`/264, `0x10c`/268, `0x13a794`/1288084, `0x98`/152, `0x8d`/141, `0x162`/354, `0x11d`/285, `0x33c`/828, and `0x334`/820.
- Resolved body-level blockers:
  - Constructors: exact modeled ranges are `0x005b0780-0x005b080d` and `0x005b0ac0-0x005b0b4d`; each calls `NumberArgsInputPane` construction with `0`, writes three class vtable pointers at `this+0`, `this+0xa0`, and `this+0xa4`, looks up the prompt with `dword_67A748 + 0x13a794 + 0x148 * signed(spellIndex)`, calls `LineInputPaneSetPromptText`, and stores the original spell-index byte at `this+0x108`.
  - Four-argument constructor vtables are `0x0062f440`, `0x0062f490`, and `0x0062f4c0`; three-argument constructor vtables are `0x0062f4cc`, `0x0062f51c`, and `0x0062f54c`.
  - Direct constructor callers are the spell-inventory families at `0x0057cb12/0x0057e43a/0x0057f13d` for four-arg and `0x0057cb46/0x0057e47c/0x0057f171` for three-arg. Inline construction in `0x005a4530` also allocates `0x10c`, writes the same vtables, runs the same prompt lookup, and stores the same `this+0x108` byte.
  - Four-argument confirm is vtable-reached at primary slot dword `0x0062f488`; three-argument confirm is vtable-reached at primary slot dword `0x0062f514`. `xrefs_to` found no modeled direct callers for either handler.
  - Four-argument confirm requires positive input length and three comma separators, copies up to 255 wide chars, uses CRT `__wtol` wrapper calls for four values, writes opcode `0x0f` at packet offset `+0`, stored `this+0x108` byte at `+1`, four big-endian 16-bit values at `+2/+4/+6/+8`, writes an unsent zero terminator at `+10`, and calls `QueueAndSendPacket(..., 10)`.
  - Three-argument confirm requires positive input length and two comma separators, copies up to 255 wide chars, uses CRT `__wtol` wrapper calls for three values, writes opcode `0x0f` at packet offset `+0`, stored `this+0x108` byte at `+1`, three big-endian 16-bit values at `+2/+4/+6`, writes an unsent zero terminator at `+8`, and calls `QueueAndSendPacket(..., 8)`.
  - Stack/local packet layouts were checked in IDA stack-frame/disassembly form: four-arg uses frame size `0x33c` with packet bytes at `Src` through `Src+0xa`; three-arg uses frame size `0x334` with packet bytes at `Src` through `Src+0x8`.
  - Neighbor boundaries were checked: `0x005b080d-0x005b0810`, `0x005b0b4d-0x005b0b50`, `0x005b0a02-0x005b0a10`, and `0x005b0cfd-0x005b0d00` are `0xcc` padding; direct destructors start at `0x005b0810` and `0x005b0b50`.
- Remaining source-quality blockers:
  - `unknown_libname_24` is confidently a CRT `__wtol` wrapper by support docs/pattern, but the original source spelling is still compiler/library-facing.
  - The shared prompt helper, packet byte/word helper, and sender wrappers are still documented by recovered helper-page names, not original source names.
  - The spell prompt/member names remain descriptive (`spellIndex`, prompt text under `g_pCollectionData + 0x13a794 + 0x148 * index`) because no source-quality spell-record type/member declaration was found.
  - Adjacent raw helpers at `0x005b0a10-0x005b0abb` and `0x005b0d00-0x005b0d9a` are function-shaped packet helpers, but `lookup_funcs` reports no function object, `xrefs_to` reports zero refs, and raw pointer-value scans `10 0A 5B 00` / `00 0D 5B 00` found no matches. They were documented as adjacent generated-output/coverage omissions, not absorbed into the assigned exact handler pages.
- Validation:
  - `python .\tools\validator.py --mode file --file by-memory\0x005b0780-0x005b080d.SpellFourArgsInputPaneConstructor.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`; completion/confidence updates recorded as `86/90`.
  - `python .\tools\validator.py --mode file --file by-memory\0x005b08a0-0x005b0a02.SpellFourArgsInputPaneConfirmInput.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`; completion/confidence updates recorded as `86/89`.
  - `python .\tools\validator.py --mode file --file by-memory\0x005b0ac0-0x005b0b4d.SpellThreeArgsInputPaneConstructor.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`; completion/confidence updates recorded as `86/90`.
  - `python .\tools\validator.py --mode file --file by-memory\0x005b0be0-0x005b0cfd.SpellThreeArgsInputPaneConfirmInput.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`; completion/confidence updates recorded as `86/89`.
- Leases:
  - Leased the four target pages and this notes file before editing. By the final note write, the earlier target leases had expired and no A002 leases remained; a fresh notes-only lease was acquired to write this checkpoint and will be released immediately after this update.
  - Active lease check before notes update showed only supervisor-owned rows, including `by-memory/-coverage-report.md`; A002 did not edit that file.
- IDA DB changes: none. No IDA comments, names, prototypes, function promotions, patches, or database saves were made.
- Pending supervisor-owned `by-memory/-coverage-report.md` row replacements:
  - Placement: under [UID:0001LN] `0x005b0780-0x005b14e6.SpellArgumentInputPanes`, replace existing [UID:0001LM], [UID:0001LO], [UID:0001LP], and [UID:0001LQ] child rows with:
```text
    - [UID:0001LM][0x005b0780-0x005b080d.SpellFourArgsInputPaneConstructor](by-memory/0x005b0780-0x005b080d.SpellFourArgsInputPaneConstructor.md) 0x005b0780-0x005b080d | constructor | SpellFourArgsInputPaneConstructor : reconstructable : 86% : very strong : A002 2026-06-16 body-level refresh confirms exact 0x8d/141-byte boundary, NumberArgsInputPane base call, vtable stores to 0x0062f440/0x0062f490/0x0062f4c0 at this+0/+0xa0/+0xa4, spell-record prompt lookup through dword_67A748+0x13a794+0x148*signed spellIndex, this+0x108 spell-index byte storage, three direct spell-inventory constructor calls, inline construction in 0x005a4530, callee set, adjacent direct destructor and padding, and blank final C++ pending final spell-record/member/source construction names.
    - [UID:0001LO][0x005b08a0-0x005b0a02.SpellFourArgsInputPaneConfirmInput](by-memory/0x005b08a0-0x005b0a02.SpellFourArgsInputPaneConfirmInput.md) 0x005b08a0-0x005b0a02 | virtual input submit handler | SpellFourArgsInputPaneConfirmInput : reconstructable : 86% : strong : A002 2026-06-16 body-level refresh confirms exact 0x162/354-byte boundary, vtable slot 0x0062f488 and no direct modeled callers, positive-text and three-comma parse gates, CRT __wtol conversions, opcode 0x0f + stored this+0x108 byte + four big-endian 16-bit arguments at packet offsets +2/+4/+6/+8, explicit unsent terminator at +10, QueueAndSendPacket length 10, callee set, and adjacent no-xref raw direct-argument helper at 0x005b0a10-0x005b0abb documented as a coverage omission; final C++ blank pending helper/member names and raw-helper policy.
    - [UID:0001LP][0x005b0ac0-0x005b0b4d.SpellThreeArgsInputPaneConstructor](by-memory/0x005b0ac0-0x005b0b4d.SpellThreeArgsInputPaneConstructor.md) 0x005b0ac0-0x005b0b4d | constructor | SpellThreeArgsInputPaneConstructor : reconstructable : 86% : very strong : A002 2026-06-16 body-level refresh confirms exact 0x8d/141-byte boundary, NumberArgsInputPane base call, vtable stores to 0x0062f4cc/0x0062f51c/0x0062f54c at this+0/+0xa0/+0xa4, spell-record prompt lookup through dword_67A748+0x13a794+0x148*signed spellIndex, this+0x108 spell-index byte storage, three direct spell-inventory constructor calls, inline construction in 0x005a4530, callee set, adjacent direct destructor and padding, and blank final C++ pending final spell-record/member/source construction names.
    - [UID:0001LQ][0x005b0be0-0x005b0cfd.SpellThreeArgsInputPaneConfirmInput](by-memory/0x005b0be0-0x005b0cfd.SpellThreeArgsInputPaneConfirmInput.md) 0x005b0be0-0x005b0cfd | virtual input submit handler | SpellThreeArgsInputPaneConfirmInput : reconstructable : 86% : strong : A002 2026-06-16 body-level refresh confirms exact 0x11d/285-byte boundary, vtable slot 0x0062f514 and no direct modeled callers, positive-text and two-comma parse gates, CRT __wtol conversions, opcode 0x0f + stored this+0x108 byte + three big-endian 16-bit arguments at packet offsets +2/+4/+6, explicit unsent terminator at +8, QueueAndSendPacket length 8, callee set, and adjacent no-xref raw direct-argument helper at 0x005b0d00-0x005b0d9a documented as a coverage omission; final C++ blank pending helper/member names and raw-helper policy.
```
- Pending supervisor split/coverage action:
  - `0x005b0a10-0x005b0abb` and `0x005b0d00-0x005b0d9a` need supervisor-owned UID/page/split decisions before exact coverage rows can be safely supplied. Placement would be inside [UID:0001LN] after [UID:0001LO] and after [UID:0001LQ] respectively. Evidence checked: IDA `lookup_funcs` finds no modeled function starts, `xrefs_to` finds no xrefs, `find_bytes` finds no pointer literals, but raw disassembly shows prologue-shaped direct-argument opcode `0x0f` packet helpers ending in `retn 0x10` and `retn 0x0c`.

## 2026-06-16 Supervisor follow-up - SpellInputPane raw helper split executed

- Supervisor applied the four exact [UID:0001LM], [UID:0001LO], [UID:0001LP], and [UID:0001LQ] `by-memory/-coverage-report.md` rows from this checkpoint and validated the shared report plus the four target pages with `ok:1`.
- Supervisor resolved the pending split/coverage action by creating exact no-route/non-emitting child pages:
  - [UID:0003VT] `by-memory/0x005b0a10-0x005b0abb.SpellFourArgsDirectArgumentPacketRaw.md` at `85/86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`.
  - [UID:0003VU] `by-memory/0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw.md` at `85/86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`.
- Supervisor also updated [UID:0001LN] `SpellArgumentInputPanes` from `84/86` to `85/87`, linked the new children from the two confirm-handler pages, recorded surrounding padding in `by-memory/-ignored.md`, inserted exact shared coverage rows for the padding/raw children, and validated all changed docs with `ok:1`.
- No pending supervisor-owned `by-memory/-coverage-report.md` rows remain for the four/three-argument SpellInputPane batch.

## 2026-06-16 Checkpoint - A002-goal2-spell-input-pane-two-one-slot-0001LR-0001LX-20260616

- Changed files:
  - `by-memory/0x005b0da0-0x005b0e2d.SpellTwoArgsInputPaneConstructor.md`
  - `by-memory/0x005b0ec0-0x005b0f9e.SpellTwoArgsInputPaneConfirmInput.md`
  - `by-memory/0x005b1030-0x005b10bd.SpellOneArgInputPaneConstructor.md`
  - `by-memory/0x005b1150-0x005b11f5.SpellOneArgInputPaneSubmitInput.md`
  - `by-memory/0x005b1280-0x005b130d.SpellSlotInputPaneConstructor.md`
  - `by-memory/0x005b13a0-0x005b140c.SpellSlotInputPaneKeyInput.md`
  - `by-memory/0x005b1410-0x005b14e6.SpellSlotInputPaneSubmitSpellSlot.md`
  - Validator-owned/generated state refreshed by scoped validators: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, and `tools/validator.ini`.
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score changes and routing:
  - [UID:0001LR] `SpellTwoArgsInputPaneConstructor`: `82/86 -> 86/90`; owner/emitter remain [UID:0000DW] `SpellTwoArgsInputPane`, source root [UID:0000O0] `SpellInputPanes`.
  - [UID:0001LS] `SpellTwoArgsInputPaneConfirmInput`: `82/86 -> 86/89`; owner/emitter remain [UID:0000DW] `SpellTwoArgsInputPane`, source root [UID:0000O0] `SpellInputPanes`.
  - [UID:0001LT] `SpellOneArgInputPaneConstructor`: `82/86 -> 86/90`; owner/emitter remain [UID:0000DR] `SpellOneArgInputPane`, source root [UID:0000O0] `SpellInputPanes`.
  - [UID:0001LU] `SpellOneArgInputPaneSubmitInput`: `82/86 -> 86/89`; owner/emitter remain [UID:0000DR] `SpellOneArgInputPane`, source root [UID:0000O0] `SpellInputPanes`.
  - [UID:0001LV] `SpellSlotInputPaneConstructor`: `82/86 -> 86/90`; owner/emitter remain [UID:0000DS] `SpellSlotInputPane`, source root [UID:0000O0] `SpellInputPanes`.
  - [UID:0001LW] `SpellSlotInputPaneKeyInput`: `82/86 -> 86/89`; owner/emitter remain [UID:0000DS] `SpellSlotInputPane`, source root [UID:0000O0] `SpellInputPanes`.
  - [UID:0001LX] `SpellSlotInputPaneSubmitSpellSlot`: `82/86 -> 86/89`; owner/emitter remain [UID:0000DS] `SpellSlotInputPane`, source root [UID:0000O0] `SpellInputPanes`.
  - All seven pages remain `RECONSTRUCTABLE: TRUE`, `EMITS: TRUE`, and blank final C++. Numeric score/route eligibility is met, but final source stays blank because final spell-record/member/event/status-field/helper names and raw-helper source treatment are not source-quality.
- Evidence checked:
  - Read active A002 goal/instructions, Supervisor docs, assignment context, by-structure/source-tree guidance, the seven targets, sibling four/three-argument pages, [UID:0001LN] `SpellArgumentInputPanes`, `SpellInputPanes` file/class pages, `NumberArgsInputPane`, `CharInputPane`, `LineInputPaneSetPromptText`, packet helpers, `g_packetSender`, `QueueAndSendPacket`, `g_pCollectionData`, `g_activeUserStatusPane`, `g_pGeneralPurposePanel`, `g_pSoundManager`, and `ChangeSpellSlotInputPaneKeyInput`.
  - Live read-only IDA MCP session `701e9f0c` on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; used `lookup_funcs`, `decompile`, `disasm`, `xrefs_to`, `callees`, `get_bytes`, and pointer-byte `find_bytes` scans. No IDA writes were made.
  - `int_convert.py` verified decimal conversions used in the docs, including `0x8d`/141, `0xde`/222, `0xa5`/165, `0x6c`/108, `0xd6`/214, `0x148`/328, `0x10c`/268, `0x108`/264, `0x13a794`/1288084, `0x330`/816, `0x134`/308, `0x284`/644, `0x198`/408, and the slot-letter constants.
- Resolved body-level blockers:
  - Constructors at `0x005b0da0`, `0x005b1030`, and `0x005b1280` are exact `0x8d` bodies. Two/one call `NumberArgsInputPane` base construction; slot calls `CharInputPane` base construction. All three compute prompt text from `dword_67A748 + 0x13a794 + 0x148 * signed(spellIndex)`, call `LineInputPaneSetPromptText`, store the original byte at `this+0x108`, and are also inline-constructed by [UID:0003UC] `LivingObjectPaneUseCommandSlotDispatch` cases 6/7/8 with matching vtable stores.
  - Two-argument constructor vtables are `0x0062f558/0x0062f5a8/0x0062f5d8`; one-argument constructor vtables are `0x0062f5e4/0x0062f634/0x0062f664`; slot constructor vtables are `0x0062f670/0x0062f6c0/0x0062f6f0`.
  - Direct constructor callers were confirmed at `0x0057cbbe/0x0057e4a8/0x0057f1e9`, `0x0057cbeb/0x0057e4ea/0x0057f216`, and `0x0057cc18/0x0057e52c/0x0057f243`.
  - Two-argument confirm is vtable-reached at `0x0062f5a0`; it requires positive text and one comma, copies up to 255 wide chars, uses CRT `__wtol`, then writes opcode `0x0f`, stored `this+0x108`, two big-endian 16-bit args at packet offsets `+2/+4`, an unsent terminator at `+6`, and sends length `6`.
  - One-argument submit is vtable-reached at `0x0062f62c`; it requires positive text, copies up to 255 wide chars, uses CRT `__wtol`, then writes opcode `0x0f`, stored `this+0x108`, one big-endian 16-bit arg at packet offset `+2`, an unsent terminator at `+4`, and sends length `4`.
  - Slot key input is vtable-reached at `0x0062f6c8`; it classifies `std::ctype<char>::do_narrow` as runtime support, resolves the shortcut branch as `?` plus bytes `+0x10a == 4` and `+0x04 == 8`, switches `g_pGeneralPurposePanel` to child/tab `3`, calls sound/effect `0x198`/`100` through `g_pSoundManager`, returns handled, and otherwise delegates to `CharInputPane` key handling.
  - Slot submit is vtable-reached at `0x0062f6b8`; it requires one character, maps `a-z` to slots `1..26`, maps `A-Z` to `27..52`, validates against `g_activeUserStatusPane + 0x284`, then writes opcode `0x0f`, stored `this+0x108`, selected-slot byte at packet `+2`, an unsent terminator at `+3`, and sends length `3`.
  - Neighbor boundaries checked: `0x005b0e2d-0x005b0e30`, `0x005b0f9e-0x005b0fa0`, `0x005b10bd-0x005b10c0`, `0x005b11f5-0x005b1200`, `0x005b130d-0x005b1310`, `0x005b1393-0x005b13a0`, `0x005b140c-0x005b1410`, and `0x005b14e6-0x005b14f0` are `0xcc` padding spans as documented.
- Source-quality decisions and remaining blockers:
  - `unknown_libname_24` is resolved as the CRT `__wtol` wrapper by current docs and call pattern; it remains runtime/library support, not spell pane ownership.
  - `std::ctype<char>::do_narrow` is compiler/runtime support. [UID:00015X] `GeneralPurposePanelSwitchActiveTab` and [UID:00028R] `g_pSoundManager` are resolved as support dependencies, not spell pane methods.
  - `dword_67A754` remains an unresolved shared key/ctype runtime global after docs search; it is not safe to name beyond that descriptive role.
  - `g_activeUserStatusPane + 0x284` is resolved to the active status pane inventory/max-slot byte per current global docs; generated `g_pLocalPlayer` aliases were rejected as pollution.
  - Final method/member/source names for `this+0x108`, the spell-record prompt/name field, the packet byte/word helper functions, `sub_57A5C0`, and the event bytes in the slot key handler remain unresolved after target docs, sibling pages, support docs, and IDA body evidence. Scores stay below near-final for those names.
  - Adjacent raw helpers `0x005b0fa0-0x005b1029`, `0x005b1200-0x005b1278`, and `0x005b14f0-0x005b1568` are function-shaped direct-argument/direct-slot packet helpers, but `lookup_funcs` reports no function object, `xrefs_to` reports zero refs, and pointer-byte scans `A0 0F 5B 00`, `00 12 5B 00`, and `F0 14 5B 00` found no stored pointer hits. They were documented as adjacent generated-output/coverage omissions, not absorbed into the assigned exact pages.
- Validation:
  - A PowerShell loop ran `python .\tools\validator.py --mode file --file <target> --apply --queue-timeout 240` for all seven target pages; the loop exited `0`.
  - Each target validator run reported `ok: 1`. Completion/confidence updates were recorded as `86/90`, `86/89`, `86/90`, `86/89`, `86/90`, `86/89`, and `86/89`.
- Leases:
  - A002 leased the seven target pages and this notes file before editing.
  - The first lease window expired during validation; A002 reacquired this notes file before writing this checkpoint. A002 did not edit `by-memory/-coverage-report.md`, which was supervisor-leased during part of the pass.
- IDA DB changes: none. No comments, renames, prototypes, type edits, function creation, patches, saves, or other IDA writes were made.
- Pending supervisor-owned `by-memory/-coverage-report.md` row replacements:
  - Placement: under [UID:0001LN] `0x005b0780-0x005b14e6.SpellArgumentInputPanes`, replace existing rows [UID:0001LR] through [UID:0001LX] immediately after padding row `0x005b0d9a-0x005b0da0` and before [UID:0001LY] `0x005b1570-0x005b2562.SayTargetMessageInputPanes` with:
```text
    - [UID:0001LR][0x005b0da0-0x005b0e2d.SpellTwoArgsInputPaneConstructor](by-memory/0x005b0da0-0x005b0e2d.SpellTwoArgsInputPaneConstructor.md) 0x005b0da0-0x005b0e2d | constructor | SpellTwoArgsInputPaneConstructor : reconstructable : 86% : very strong : A002 2026-06-16 body-level refresh confirms exact 0x8d/141-byte boundary, NumberArgsInputPane base call, vtable stores to 0x0062f558/0x0062f5a8/0x0062f5d8 at this+0/+0xa0/+0xa4, spell-record prompt lookup through dword_67A748+0x13a794+0x148*signed spellIndex, this+0x108 spell-index byte storage, three direct spell-inventory constructor calls, inline construction in 0x005a4530 case 6, callee set, adjacent direct destructor and padding, and blank final C++ pending final spell-record/member/source construction names.
    - [UID:0001LS][0x005b0ec0-0x005b0f9e.SpellTwoArgsInputPaneConfirmInput](by-memory/0x005b0ec0-0x005b0f9e.SpellTwoArgsInputPaneConfirmInput.md) 0x005b0ec0-0x005b0f9e | virtual input submit handler | SpellTwoArgsInputPaneConfirmInput : reconstructable : 86% : strong : A002 2026-06-16 body-level refresh confirms exact 0xde/222-byte boundary, vtable slot 0x0062f5a0 and no direct modeled callers, positive-text and one-comma parse gates, CRT __wtol conversions, opcode 0x0f + stored this+0x108 byte + two big-endian 16-bit arguments at packet offsets +2/+4, explicit unsent terminator at +6, QueueAndSendPacket length 6, callee set, and adjacent no-xref raw direct-argument helper at 0x005b0fa0-0x005b1029 documented as a coverage omission; final C++ blank pending helper/member names and raw-helper policy.
    - [UID:0001LT][0x005b1030-0x005b10bd.SpellOneArgInputPaneConstructor](by-memory/0x005b1030-0x005b10bd.SpellOneArgInputPaneConstructor.md) 0x005b1030-0x005b10bd | constructor | SpellOneArgInputPaneConstructor : reconstructable : 86% : very strong : A002 2026-06-16 body-level refresh confirms exact 0x8d/141-byte boundary, NumberArgsInputPane base call, vtable stores to 0x0062f5e4/0x0062f634/0x0062f664 at this+0/+0xa0/+0xa4, spell-record prompt lookup through dword_67A748+0x13a794+0x148*signed spellIndex, this+0x108 spell-index byte storage, three direct spell-inventory constructor calls, inline construction in 0x005a4530 case 7, callee set, source-owner exclusions, adjacent direct destructor and padding, and blank final C++ pending final spell-record/member/source construction names.
    - [UID:0001LU][0x005b1150-0x005b11f5.SpellOneArgInputPaneSubmitInput](by-memory/0x005b1150-0x005b11f5.SpellOneArgInputPaneSubmitInput.md) 0x005b1150-0x005b11f5 | virtual input submit handler | SpellOneArgInputPaneSubmitInput : reconstructable : 86% : strong : A002 2026-06-16 body-level refresh confirms exact 0xa5/165-byte boundary, vtable slot 0x0062f62c and no direct modeled callers, positive-text parse gate, CRT __wtol conversion, opcode 0x0f + stored this+0x108 byte + one big-endian 16-bit argument at packet offset +2, explicit unsent terminator at +4, QueueAndSendPacket length 4, callee set, and adjacent no-xref raw direct-argument helper at 0x005b1200-0x005b1278 documented as a coverage omission; final C++ blank pending helper/member names and raw-helper policy.
    - [UID:0001LV][0x005b1280-0x005b130d.SpellSlotInputPaneConstructor](by-memory/0x005b1280-0x005b130d.SpellSlotInputPaneConstructor.md) 0x005b1280-0x005b130d | constructor | SpellSlotInputPaneConstructor : reconstructable : 86% : very strong : A002 2026-06-16 body-level refresh confirms exact 0x8d/141-byte boundary, CharInputPane base call, vtable stores to 0x0062f670/0x0062f6c0/0x0062f6f0 at this+0/+0xa0/+0xa4, spell-record prompt lookup through dword_67A748+0x13a794+0x148*signed spellIndex, this+0x108 spell-index byte storage, three direct spell-inventory constructor calls, inline construction in 0x005a4530 case 8, callee set, adjacent direct destructor and padding, and blank final C++ pending final spell-record/member/source construction names.
    - [UID:0001LW][0x005b13a0-0x005b140c.SpellSlotInputPaneKeyInput](by-memory/0x005b13a0-0x005b140c.SpellSlotInputPaneKeyInput.md) 0x005b13a0-0x005b140c | virtual key input handler | SpellSlotInputPaneKeyInput : reconstructable : 86% : strong : A002 2026-06-16 body-level refresh confirms exact 0x6c/108-byte boundary, vtable slot 0x0062f6c8 and no direct modeled callers, runtime std::ctype<char>::do_narrow through dword_67A754, shortcut predicates '?' plus byte +0x10a == 4 and byte +0x04 == 8, g_pGeneralPurposePanel tab/child 3 switch, g_pSoundManager sound/effect 0x198/100 call, CharInputPane fallback, callee set, and padding before submit; final C++ blank pending event/global/helper source names.
    - [UID:0001LX][0x005b1410-0x005b14e6.SpellSlotInputPaneSubmitSpellSlot](by-memory/0x005b1410-0x005b14e6.SpellSlotInputPaneSubmitSpellSlot.md) 0x005b1410-0x005b14e6 | virtual input submit handler | SpellSlotInputPaneSubmitSpellSlot : reconstructable : 86% : strong : A002 2026-06-16 body-level refresh confirms exact 0xd6/214-byte boundary, vtable slot 0x0062f6b8 and no direct modeled callers, one-character gate, a-z/A-Z slot mapping to 1..52, g_activeUserStatusPane+0x284 max-slot validation, opcode 0x0f + stored this+0x108 byte + selected-slot byte at packet offset +2, explicit unsent terminator at +3, QueueAndSendPacket length 3, callee set, and adjacent no-xref raw direct-slot helper at 0x005b14f0-0x005b1568 documented as a coverage omission; final C++ blank pending helper/member/status-field names and raw-helper policy.
```
- Pending supervisor split/coverage action:
  - `0x005b0fa0-0x005b1029`, `0x005b1200-0x005b1278`, and `0x005b14f0-0x005b1568` need supervisor-owned UID/page/split decisions before exact non-target coverage rows can be safely supplied. Suggested placement: after [UID:0001LS], after [UID:0001LU], and after [UID:0001LX] respectively, with padding rows for `0x005b0f9e-0x005b0fa0`, `0x005b1029-0x005b1030`, `0x005b11f5-0x005b1200`, `0x005b1278-0x005b1280`, `0x005b14e6-0x005b14f0`, and `0x005b1568-0x005b1570`.
  - Evidence checked for all three: no IDA function object, zero xrefs, zero pointer-literal hits, raw prologue-shaped opcode `0x0f` packet helpers, and no safe owner/emitter route. This is bounded raw-helper split/policy work; recommend supervisor/B-agent handling rather than forcing these helpers into the assigned class-owned pages.

## 2026-06-16 Checkpoint - A002-goal2-destructor-support-refresh-headselect-forcedinform-terminal-0001FL-0001JA-000247-20260616

- Changed files:
  - `by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md`
  - `by-memory/0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor.md`
  - `by-memory/0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor.md`
  - Validator-owned/generated state refreshed by scoped validator: `project-level/-auto-completion-stats.md` and `tools/validator.ini`; `auto-generated/-ag-memory-coverage.md` remained reported as autogen report no-op during the final validation rerun but is already dirty in the shared workspace.
  - `tools/leaser/Agents/Agent-A002/notes.md`
  - `by-memory/-coverage-report.md` is dirty in the shared workspace, but A002 did not edit it directly; exact pending rows are recorded below for supervisor application.
- Score changes and owner/emitter decisions:
  - [UID:0001FL] `HeadSelectDialogDestructorThunks`: `82/87 -> 86/91`; owner/emitter remain [UID:000062] `HeadSelectDialog`. Final C++ stays blank because the source should declare the class destructor/layout and regenerate the adjustor thunks/scalar wrapper.
  - [UID:0001JA] `ForcedInformMessageDialogDestructor`: `82/87 -> 86/90`; owner/emitter remain [UID:0000JJ] `ForcedInformMessageDialog` source file route, with class evidence from [UID:00005E]. Final C++ stays blank because this exact body is the compiler scalar deleting wrapper and final source helper/global expression names remain provisional.
  - [UID:000247] `TerminalPaneScalarDeletingDestructor`: `82/87 -> 86/90`; owner/emitter remain [UID:0000OI] `TerminalPane` source file route, with class evidence from [UID:0000EG]. Final C++ stays blank because this exact body is compiler deleting-destructor support.
- Evidence checked:
  - Live read-only IDA MCP session `701e9f0c` on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; used function lookup, decompilation, xrefs/callees, byte checks, signatures, and current support docs. No IDA writes were made.
  - HeadSelect: confirmed `sub_5538FE` and `sub_553909` as `0xb` adjustor thunks subtracting `0xa0`/`0xa4` (160/164) into `0x00553920`; confirmed `sub_553920` size `0xa3`/163, primary/secondary/tertiary refs `0x006228bc`/`0x0062291c`/`0x0062294c`, twelve-byte internal padding, successor boundary `0x005539c3`, non-deleting destructor parity at `0x00551f30`, `DialogPane` cleanup at `0x0049d9f0`, and MemoryMan operator delete at `0x004f4ac0`.
  - ForcedInform: confirmed `sub_58ABF0` size `0xc2`/194, padding `0x0058abe7-0x0058abf0` and `0x0058acb2-0x0058acc0`, vtable stores at `0x0058ac15`/`0x0058ac1b`/`0x0058ac25`, primary and thunk refs `0x0062d718`/`0x0058aae1`/`0x0058aaec`, accepted EPF restore condition through `g_useEpfAssets`, `m_bAccepted`, and `g_pMainUiGraph`, singleton clear at `0x0058ac59`, and non-deleting destructor parity at `0x00588080`.
  - TerminalPane: confirmed `sub_58DC60` size `0x45`/69, padding `0x0058dc5b-0x0058dc60` and `0x0058dca5-0x0058dcb0`, DialDialog predecessor exclusion at `0x0058dc20-0x0058dc5b`, PhoneBook successor start `0x0058dcb0`, vtable refs `0x0062da10` plus adjustor thunk refs `0x0058dc07`/`0x0058dc12`, `g_pTerminalPane` clear at `0x0058dc66`, shared `DialogPane` cleanup, and MemoryMan operator delete.
- Source-quality and compiler/generated decisions:
  - The stale `boost::exception` label on `0x0049d9f0` is rejected for all three targets; current `DialogPane` docs/decompilation identify it as shared dialog cleanup.
  - `0x004f4ac0` is resolved to [UID:000197] `OperatorDeleteWrapper`, a MemoryMan-backed global delete wrapper, not a class-owned source helper.
  - HeadSelect `sub_49E1C0`/`sub_49E210` roles are bounded to `DialogPane` destroy/hide/control-release support, but exact original source names remain unresolved.
  - ForcedInform generated `g_cursorVisibleFlag` for `0x0067aba4` is rejected; current docs resolve the storage to [UID:0000RF]/[UID:0002AF] `g_pMainUiGraph`.
  - ForcedInform `EnsureLoginDialogPane_4F8B30` remains owned by LoginDialogPane support; this destructor is only a caller.
  - TerminalPane `0x0058dc01`/`0x0058dc0c` and HeadSelect/ForcedInform adjustor thunks are compiler-generated thunks, not source-authored methods or unresolved feature logic.
  - Remaining blockers are final source spelling only: original destructor/helper/member names and exact source declaration shape. They do not materially block behavior/range/owner confidence, so all three targets clear the 85/85 gate but remain below final-C++ readiness.
- Validation:
  - Final rerun used a PowerShell loop over the three targets, invoking `python .\tools\validator.py --mode file --file <target> --apply --queue-timeout 240`.
  - The loop exited `0`; each target validator run reported `ok: 1`.
  - The HeadSelect rerun reported `reference_index_remove` for stale wrong links `0003BV` and `0001AK`, `reference_index_add` for `0003DA`, registry rebuild, projected stats update, and autogen report no-op.
- Leases:
  - A002 leased all three target pages and this notes file before editing.
  - The first lease window expired during validation; A002 reacquired the same three target leases and this notes lease before this checkpoint note.
- IDA DB changes: none. No comments, renames, prototypes, type edits, function creation, patches, saves, or other IDA writes were made.
- Pending supervisor-owned `by-memory/-coverage-report.md` row replacements:
  - Placement: under the executable cluster around `0x005538fd-0x005539c3`, replace the existing [UID:0001FL] row after padding row `0x005538fd-0x005538fe` and before the existing ignored thunk-only row / successor [UID:00023N] row with:
```text
    - [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md) 0x005538fe-0x005539c3 | destructor thunk/scalar-wrapper cluster | HeadSelectDialogDestructorThunks : reconstructable : 86% : very strong : A002 2026-06-16 live IDA refresh confirms exact 0xb/0xb/0xa3 child functions, secondary/tertiary adjustor thunks subtracting 0xa0/0xa4 (160/164) and jumping to 0x00553920, primary/secondary/tertiary vtable refs at 0x006228bc/0x0062291c/0x0062294c, scalar wrapper vtable resets, DialogPane destroy/hide/base-cleanup callees, MemoryMan-backed operator delete, pre/internal padding, successor shared default destructor thunk boundary at 0x005539c3, generated-output missing/low-quality thunk omissions, and blank final C++ because the source should declare the HeadSelectDialog destructor/class layout while MSVC regenerates this support.
```
  - Placement: under the executable cluster around `0x0058aadb-0x0058acc0`, replace the existing [UID:0001JA] row after [UID:0001J9] `ForcedInformMessageDialogDestructorThunks` and before the successor `0x0058acc0` new-system-message rows with:
```text
    - [UID:0001JA][0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor](by-memory/0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor.md) 0x0058abf0-0x0058acb2 | destructor | ForcedInformMessageDialogDestructor : reconstructable : 86% : strong : A002 2026-06-16 live IDA refresh confirms exact 0xc2/194-byte scalar deleting destructor, vtable resets at 0x0058ac15/0x0058ac1b/0x0058ac25, primary vtable ref 0x0062d718 plus thunk code refs 0x0058aae1/0x0058aaec, accepted EPF/main-UI-graph-present login restoration through EnsureLoginDialogPane_4F8B30, singleton clear at 0x0058ac59, shared DialogPane base cleanup despite polluted boost::exception label, MemoryMan-backed operator delete, predecessor SystemMessagePanes interleaving and 0xcc padding boundaries, generated-output thunk/base-label pollution, and blank final C++ pending source-quality destructor/helper/global names.
```
  - Placement: under the executable cluster around `0x0058dc5b-0x0058dcb0`, replace the existing [UID:000247] row after padding row `0x0058dc5b-0x0058dc60` and before padding row `0x0058dca5-0x0058dcb0` with:
```text
    - [UID:000247][0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor](by-memory/0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor.md) 0x0058dc60-0x0058dca5 | destructor | TerminalPaneScalarDeletingDestructor : reconstructable : 86% : strong : A002 2026-06-16 live IDA refresh confirms exact 0x45/69-byte scalar deleting destructor, vtable-only reachability through TerminalPane primary slot 0x0062da10 and adjustor thunks at 0x0058dc07/0x0058dc12, singleton clear of g_pTerminalPane at 0x0058dc66 among the nine known singleton refs, shared DialogPane base cleanup despite polluted boost::exception label, MemoryMan-backed operator delete, DialDialog predecessor and PhoneBook helper successor padding boundaries, generated-output missing/low-quality thunk omissions, and blank final C++ because source should model the TerminalPane destructor/class layout while compiler emits the deleting wrapper.
```
- Supervisor applied these three pending `by-memory/-coverage-report.md` rows on 2026-06-16, validated the shared report plus [UID:0001FL], [UID:0001JA], and [UID:000247] with scoped `validator.py --mode file --apply --queue-timeout 240` passes (`ok:1`), regenerated `auto-generated/by-memory-tool-report.md` at `2026-06-16 16:06:26`, and regenerated stats at `2026-06-16 16:06:22`. No pending supervisor-owned memory coverage rows remain for this destructor/thunk batch.

## 2026-06-16 Checkpoint - A002-goal2-fittingroom-scroll-state-source-quality-0000WS-0002D6-0002D8-20260616

- Changed files:
  - `by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md`
  - `by-memory/0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw.md`
  - `by-memory/0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart.md`
  - Validator-owned/generated state refreshed by scoped validators: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, and `tools/validator.ini`.
  - `tools/leaser/Agents/Agent-A002/notes.md`
- Score changes and routing:
  - [UID:0000WS] `FittingEquipmentStateResetEntries`: `82/88 -> 86/90`; owner/emitter changed from [UID:0000JE] `FittingRoom` to [UID:00004Z] `FittingEquipmentState`, with source module [UID:0000JE] and embedded support-view parent [UID:000051] `FittingRoomDialogItemState`. Final C++ remains blank.
  - [UID:0002D6] `FittingRoomScrollPaneOnDraw`: `82/88 -> 86/89`; owner/emitter remain [UID:000054] `FittingRoomScrollPane`; source module [UID:0000JE] `FittingRoom`; final C++ remains blank.
  - [UID:0002D8] `FittingRoomScrollPaneHitTestPart`: `82/88 -> 86/89`; owner/emitter remain [UID:000054] `FittingRoomScrollPane`; source module [UID:0000JE] `FittingRoom`; final C++ remains blank.
- Evidence checked:
  - Live read-only IDA MCP session `701e9f0c` on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; used function lookup, decompilation, xrefs/callees, byte checks, type/struct searches, support docs, generated-output review, and resource literal byte reads. No IDA writes were made.
  - [UID:0000WS] exact `0x92` / 146-byte helper, caller `0x0041c404`, `0xb4` / 180 entry stride, entry-local buffer triplet at `+0xa8/+0xac/+0xb0`, MSVC large-allocation guard, `sub_5C7526` free, surrounding `0xcc` padding, item-state lifecycle anchors, and no preserved `FittingEquipmentState` / `FittingRoomDialogItemState` UDTs.
  - [UID:0002D6] exact `0x716` / 1814-byte vtable-only draw handler at slot `0x0060dccc`, no direct code callers, pre/post `0xcc` padding, orientation/current/range/hot/drag fields, `dword_60DC78` fixed-size-table xrefs, UTF-16 resource literals `SLIDEBG.EPF`, `SLIDEBG.PAL`, `SCRBUTT.EPF`, `BUTTON.PAL`, shared resource xref counts, and EPFTileContext/ResourceLayout/GrafPort/RectGeometry/Surface helper-role support docs.
  - [UID:0002D8] exact `0x31d` / 797-byte helper, two code callers at `0x0041d951` and `0x0041e91f`, pre/post `0xcc` padding, successor `GetPartRect` boundary, part loop `0..4`, fallback return `0xff`, cursor-to-pane-local sentinel handling, inline horizontal/vertical rectangle construction, RectGeometry point tests, `dword_60DC78` fixed-size-table xrefs, and no preserved scroll-part UDT/enum metadata.
  - Current `auto-generated/NexusTK/cashshop/FittingRoom.cpp` is zero bytes and does not resolve final field/type/enum/helper names or the fitting-room-local versus generic-scrollbar source split.
- Source-quality decisions and remaining blockers:
  - [UID:0000WS] now routes to the direct support-view class [UID:00004Z] rather than file-only [UID:0000JE], but the exact original nested entry type, vector field names, and entry-local buffer meaning remain unresolved after type searches, layout docs, lifecycle anchors, and generated-output review.
  - [UID:0002D6] resource string names are resolved, but the resource art is shared across other scrollbar/control paths; this supports exact literals but not a fitting-room-private source split. `0x004a9090` / `0x005447c0` remain descriptive viewport/pane-local helper roles, not final source names.
  - [UID:0002D8] the helper computes candidate rectangles inline; it should not be final-reconstructed as a trivial `GetPartRect` wrapper. Scroll part enum names, field names, and the `dword_60DC78` source name remain unresolved after UDT/enum searches and sibling docs.
  - Final C++ remains blank for all three pages because current evidence supports behavior/range/routing over 85/85 but not final source spelling or source placement.
- Validation:
  - A PowerShell loop ran `python .\tools\validator.py --mode file --file <target> --apply --queue-timeout 240` for all three target pages from `source-3/project-documentation`.
  - The loop exited `0`; each scoped validator pass reported `ok: 1`. The validator rebuilt `tools/validator.ini`, updated projected completion stats, and refreshed `auto-generated/-ag-memory-coverage.md`.
- Leases:
  - A002 leased all three target pages and this notes file before editing; the first lease window was released and reacquired because it was about to expire before remaining edits.
- IDA DB changes: none. No comments, renames, prototypes, type edits, function creation, patches, saves, or other IDA writes were made.
- Pending supervisor-owned `by-memory/-coverage-report.md` row replacements:
  - Placement: under [UID:0000WR] `0x0041ba40-0x004245f5.FittingRoomUiCore`, replace the existing [UID:0000WS] row after padding row `0x0041d5d5-0x0041d5e0` and before [UID:0002D2] `FittingRoomScrollPaneOnMouseEvent`; replace the existing [UID:0002D6] row after padding row `0x0041daa3-0x0041dab0` and before padding row `0x0041e1c6-0x0041e1d0`; replace the existing [UID:0002D8] row after padding row `0x0041e1c6-0x0041e1d0` and before padding row `0x0041e4ed-0x0041e4f0` with:
```text
        - [UID:0000WS][0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries](by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md) 0x0041d5e0-0x0041d671 | method | FittingEquipmentStateResetEntries : reconstructable : 86% : very strong : A002 2026-06-16 source-quality refresh confirms exact 0x92/146-byte modeled helper, one OnCommand caller at 0x0041c404, entry stride 0xb4/180, entry-local buffer triple at +0xa8/+0xac/+0xb0, MSVC large-allocation guard and sub_5C7526 free path, surrounding 0xcc padding, item-state constructor/destructor/vector-destroy anchors, direct support-view owner/emitter [UID:00004Z], zero-byte generated FittingRoom.cpp state, and blank final C++ because original nested entry/buffer/source names are not preserved.
        - [UID:0002D6][0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw](by-memory/0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw.md) 0x0041dab0-0x0041e1c6 | method | FittingRoomScrollPaneOnDraw : reconstructable : 86% : strong : A002 2026-06-16 source-quality refresh confirms exact 0x716/1814-byte vtable-only draw handler at slot 0x0060dccc, no direct code callers, pre/post 0xcc padding, shared SLIDEBG.EPF/SLIDEBG.PAL/SCRBUTT.EPF/BUTTON.PAL resource literals and xref counts, EPFTileContext/ResourceLayout/GrafPort/RectGeometry/Surface render helper roles, orientation/current/range/hot/active/drag fields, fixed-size table dword_60DC78 evidence, generated-output zero-byte state, and blank final C++ pending final field/helper/source-split names.
        - [UID:0002D8][0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart](by-memory/0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart.md) 0x0041e1d0-0x0041e4ed | helper method | FittingRoomScrollPaneHitTestPart : reconstructable : 86% : strong : A002 2026-06-16 source-quality refresh confirms exact 0x31d/797-byte modeled helper, two code callers at 0x0041d951 and 0x0041e91f, pre/post 0xcc padding, cursor-to-pane-local sentinel handling, inline horizontal/vertical rectangle construction for parts 0..4, half-open point-in-rect testing through RectGeometry, orientation/current/range/enabled/drag/hot/active fields, dword_60DC78 fixed-size table use, no preserved scroll-part enum/type metadata, generated-output zero-byte state, and blank final C++ pending final field/enum/source-split names.
```
- Supervisor applied these three pending `by-memory/-coverage-report.md` rows on 2026-06-16, validated the shared report plus [UID:0000WS], [UID:0002D6], and [UID:0002D8] with scoped `validator.py --mode file --apply --queue-timeout 240 --lock-timeout -1` passes (`ok:1`), regenerated `auto-generated/by-memory-tool-report.md` at `2026-06-16 16:32:23`, and regenerated stats at `2026-06-16 16:32:19`. No pending supervisor-owned memory coverage rows remain for this FittingRoom scroll/state batch.
