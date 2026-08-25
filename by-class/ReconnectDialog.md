*** UID:0000BR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ReconnectDialog

## Status

- Confidence: strong
- Likely source file: [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md)
- Address range: [UID:0001FT][0x00553c10-0x00554635.ConnectionClosedReconnectDialogs](by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md)
- Parent attachment: [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md). This class is `88/92` and the source-file parent is `89/91`, satisfying the strict attachment gate. Final class C++ remains blank because the complete constructor/method/access/layout declaration is broader independent debt; an incomplete shell would be misleading.
- Current recovered file: `source-3/simroot_v2/class_ReconnectDialog.cpp`

## Class Purpose

`ReconnectDialog` is the active reconnect-in-progress alert. It directly inherits `Singleton<ReconnectDialog>`, publishes process-wide [UID:0004SP][g_pReconnectDialog](by-global/g_pReconnectDialog.md) through compiler-lowered base construction, sends reconnect requests, handles cancel/reconnect button actions, performs network cleanup, and falls back to `ConnectionClosedDialog` on timeout.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ReconnectDialog` | [UID:00038L][0x00553f40-0x005544b8.ReconnectDialogMethods](by-memory/0x00553f40-0x005544b8.ReconnectDialogMethods.md) | Constructors for default/parent-pane alert setup. |
| `InitiateReconnect` | [UID:00038L][0x00553f40-0x005544b8.ReconnectDialogMethods](by-memory/0x00553f40-0x005544b8.ReconnectDialogMethods.md) | Marks reconnecting state, sends connect request using saved address/port, and starts the reconnect timeout timer. |
| Reconnect parser/state helper | [UID:00038L][0x00553f40-0x005544b8.ReconnectDialogMethods](by-memory/0x00553f40-0x005544b8.ReconnectDialogMethods.md) | Handles reconnect-side command bytes, packet/update helpers, and short timer behavior around `0x00554110`. |
| `OnButtonClick` | [UID:00038L][0x00553f40-0x005544b8.ReconnectDialogMethods](by-memory/0x00553f40-0x005544b8.ReconnectDialogMethods.md) | Handles cancel and reconnect actions with packet cleanup/send behavior. Its call at `0x005543bb` is a consumer call to [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md) after it constructs a replacement `ConnectionClosedDialog`; this does not make the helper ReconnectDialog-owned. |
| `OnReconnectTimeout` | [UID:00038L][0x00553f40-0x005544b8.ReconnectDialogMethods](by-memory/0x00553f40-0x005544b8.ReconnectDialogMethods.md) | Cancels reconnect, disconnects, and recreates connection-closed dialog. |
| Destructor family | [UID:00038K][0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks](by-memory/0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks.md) | EH-only `Singleton<ReconnectDialog>` base-destructor support, two class adjustors, and the scalar deleting wrapper. Keep the compiler bytes non-emitting and regenerate them from the complete class declaration. |

## Direct Singleton Inheritance And Layout Evidence

- Best source shape: `ReconnectDialog : public AlertPane, public Singleton<ReconnectDialog>`.
- The primary class hierarchy contains nine RTTI entries and multiple-inheritance attribute `1`.
- Singleton BCD `0x0064eab8` names `Singleton<ReconnectDialog>` and uses PMD `mdisp=0x270`, `pdisp=-1`, `vdisp=0`, attributes `0x40`.
- Constructor/factory allocations are `0x274` / 628 bytes (Verified with `int_convert.py`).
- Empty-base optimization overlaps the direct Singleton base at `+0x270` with the derived reconnect-state byte used by `InitiateReconnect`; this is not a separate guard pointer or raw layout artifact.
- Constructor code derives `this+0x270`, tests the adjusted pointer, subtracts `0x270`, and stores the complete object into exact storage [UID:0004SR][0x0067ab58-0x0067ab5c.g_pReconnectDialog](by-memory/0x0067ab58-0x0067ab5c.g_pReconnectDialog.md). That pattern is compiler lowering of direct base construction, not a handwritten assignment.
- Constructor unwind through `0x00554560` and scalar wrapper clear at `0x005545f6` are the matching compiler-lowered Singleton base destruction paths.
- The sole human source definition is [UID:0004SP][g_pReconnectDialog](by-global/g_pReconnectDialog.md), emitted through ReconnectDialog.cpp. Application heartbeat is an external read-only consumer and does not own the class or global.

## Source And Compiler Boundary

- Preserve the direct `AlertPane` plus `Singleton<ReconnectDialog>` inheritance in the eventual complete class declaration.
- Do not add explicit `g_pReconnectDialog = this` or clear assignments, explicit base destructor calls, EH helpers, vptr stores, vtables/RTTI arrays, adjustor bodies, scalar flags, or delete-wrapper code.
- Do not add a partial formal class shell merely to expose the inheritance. Constructor signatures, parser/callback declarations, access control, and remaining member names must be resolved together before this page can safely emit a class declaration.
- The blank formal block is therefore a complete-class no-incomplete-shell decision, not unresolved ownership, type, source placement, or Singleton-lifetime debt.

## Evidence Notes

- IDA confirms all local method starts.
- Behavior couples directly to packet sender state, `g_pConfig` saved server address/port, and reconnect globals.
- IDA decompilation of `OnButtonClick` shows the cancel path can construct a replacement `ConnectionClosedDialog` inline and then call [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md) at `0x005543bb`; `OnButtonClick` is a caller/consumer of that helper, not its owner.
- IDA MCP callers on 2026-05-25 show `OnButtonClick` calls [UID:0001HW][0x00574d40-0x00574e44.QueueClientVersionStatusPacket](by-memory/0x00574d40-0x00574e44.QueueClientVersionStatusPacket.md), the queued 8-byte position/status upload helper in the request-sender cluster.
- 2026-05-26 IDA MCP recheck reconfirmed `0x005543bb` inside `OnButtonClick` as one of the three callers to the `0x00553e60` post-construction helper.
- 2026-06-11 live IDA MCP Batch178 refresh decompiled [UID:00038L][0x00553f40-0x005544b8.ReconnectDialogMethods](by-memory/0x00553f40-0x005544b8.ReconnectDialogMethods.md): both constructors contain compiler-inlined Singleton publication to exact storage UID0004SR, use alert text id `155`, install `ReconnectDialog` vtables, and call reconnect initiation; `0x005540a0` marks reconnect state, clears the derived byte overlapping the EBO base at `+0x270`, calls the saved server connect helper, and starts a 10000 ms timer; `0x00554210` handles cancel/reconnect packet cleanup, sends literal `"baram"` on the reconnect branch, calls `SendPositionUpdate`, and may recreate a connection-closed dialog; `0x00554410` times out to disconnect cleanup and a replacement `ConnectionClosedDialog`.
- The same refresh links compiler Singleton destruction and wrapper support through [UID:00038K][0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks](by-memory/0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks.md).

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `88` | The class page records source-file attachment, exact method child coverage, direct AlertPane plus Singleton inheritance, nine-entry RTTI, PMD `+0x270`, `0x274` allocation/EBO overlap, typed global/storage route, implicit publication/cleanup, packet/timer behavior, compiler-wrapper boundary, connection-closed fallback, and complete-class formal gate. |
| Confidence `92` | RTTI, allocation size, constructor adjustment/store sequence, EBO state-byte use, EH/scalar clears, exact global/storage pages, method child, and source-file route independently agree. Original parser/member spellings and complete header shape remain the confidence caps. |

## Cross-References

- [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md)
- [UID:000036][ConnectionClosedDialog](by-class/ConnectionClosedDialog.md)
- [UID:0001FT][0x00553c10-0x00554635.ConnectionClosedReconnectDialogs](by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md)
- [UID:00038L][0x00553f40-0x005544b8.ReconnectDialogMethods](by-memory/0x00553f40-0x005544b8.ReconnectDialogMethods.md)
- [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md)
- [UID:00038K][0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks](by-memory/0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks.md)
- [UID:0001HW][0x00574d40-0x00574e44.QueueClientVersionStatusPacket](by-memory/0x00574d40-0x00574e44.QueueClientVersionStatusPacket.md)
- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0004SP][g_pReconnectDialog](by-global/g_pReconnectDialog.md)
- [UID:0004SR][0x0067ab58-0x0067ab5c.g_pReconnectDialog](by-memory/0x0067ab58-0x0067ab5c.g_pReconnectDialog.md)

## Changes

- 2026-07-16 B003 UID0002VT implementation callback:
  - Raised `86/88 -> 88/92`, preserving owner/emitter UID0000N0, reconstructable true, blank position/formal, all method/helper links, packet/timer behavior, and unrelated class evidence.
  - Added exact direct `AlertPane, Singleton<ReconnectDialog>` source inheritance, nine-entry RTTI, PMD `+0x270`, `0x274` allocation, EBO overlap with the derived state byte, typed global UID0004SP, exact storage UID0004SR, implicit publication/cleanup, external-linkage route, compiler exclusions, and complete-class no-incomplete-shell proof.
  - Historical direct global-assignment and clear-helper descriptions are superseded by the direct Singleton base source cause while their exact binary sites remain documented.
- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and assigned parent `0000N0`.
  - Before: The reconnect alert class remained unclassified in autogen coverage even though the class and parent file both met the 80/80 attach gate.
  - After: The class contributes to `ReconnectDialog.cpp` as a reconstructable child without emitting final C++ yet.
  - Evidence: Live IDA MCP lookup confirms the reconnect constructor/handler/destructor starts at `0x00553f40`, `0x00553ff0`, `0x005540a0`, `0x00554210`, `0x00554410`, `0x00554581`, `0x0055458c`, and `0x005545f0`; parent [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) records the same connection/reconnect ownership.

- 2026-05-30:
  - Before: completion/confidence were `0/0` even though the page contained method roles, memory cross-references, caller/callee notes, and reconnect state evidence.
  - After: changed completion/confidence to `82/86`.
  - Evidence: existing method notes, IDA evidence notes, `ConnectionClosedDialog` relationship, packet sender dependency, and aggregate memory range cross-references support high-confidence class documentation.

- 2026-05-28:
  - Before: the class page only linked helper-level reconnect ranges.
  - After: added the corrected aggregate `0x00553c10-0x00554635` so the earlier `ConnectionClosedDialog` constructor variant is visible from the reconnect class family.
  - Evidence: IDA MCP confirms the aggregate now starts at `0x00553c10` and includes the constructor variant preceding the previously documented reconnect/connection-closed methods.
- 2026-06-11 A002 Batch178 split refresh:
  - Changed completion/confidence from `82/86` to `86/88`.
  - Added exact method child [UID:00038L][0x00553f40-0x005544b8.ReconnectDialogMethods](by-memory/0x00553f40-0x005544b8.ReconnectDialogMethods.md) and cleanup/destructor child [UID:00038K][0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks](by-memory/0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks.md).
  - Evidence: live IDA MCP confirms constructors, reconnect initiation, parser/state helper, button handler, timeout handler, packet/timer behavior, singleton publication/clearing, and destructor wrappers; parent [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) now clears the strict 85/85 gate.
- 2026-07-04 B013 helper implementation callback:
  - Recorded that the `0x005543bb` call inside `OnButtonClick` is to [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md) after replacement dialog construction.
  - Preserved `ReconnectDialog::OnButtonClick` as caller/consumer only; the helper's direct owner is [UID:000036][ConnectionClosedDialog](by-class/ConnectionClosedDialog.md) and emission remains through [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md).
