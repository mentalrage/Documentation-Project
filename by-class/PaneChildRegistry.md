*** UID:0000A3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PaneChildRegistry

## Status

- Confidence: stale generated class name.
- Likely corrected source file: [UID:0000HR][BlackHole](by-file/BlackHole.md)
- Address range: [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md), inside [UID:0000Z0][0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue](by-memory/0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md)
- Current recovered state: no standalone `class_PaneChildRegistry.cpp` is emitted in `simroot_v2`; stale owner context still appears inside `class_BlackHole.meta_wave3`.

## Class Purpose

The generated `PaneChildRegistry` class was a staging owner for `0x00469180`. Current IDA evidence and active `class_BlackHole.cpp` support keeping this function on [UID:00000W][BlackHole](by-class/BlackHole.md) as a pane-specific deferred deletion helper.

The function removes a pane from its layer, unregisters event handling, removes queued timer events, checks whether the pane is already queued, and appends it to the [UID:00000W][BlackHole](by-class/BlackHole.md) singleton cleanup list.

## Evidence Notes

- Wave3 sidecar data says this was restored from missing-ref class `cls_0x469180`, but current active source is already emitted under `BlackHole`.
- IDA MCP reports broad direct caller fan-in across dialogs, panes, and replacement/close paths.
- IDA decompilation calls pane vtable slots `+0x38` and `+0x40`, which map to `Pane::RemoveFromLayer` and `Pane::UnregisterEventHandler`.
- The function appends to `dword_67A74C`, which is built by `BlackHole::BlackHole` and drained by `BlackHole::ReleaseQueuedOwnedObjects`.

## Cross-References

- [UID:0000HR][BlackHole](by-file/BlackHole.md)
- [UID:00000W][BlackHole](by-class/BlackHole.md)
- [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md)
- [UID:0000MD][PaneChildRegistry](by-file/PaneChildRegistry.md)
- [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md)
- [UID:0000A2][Pane](by-class/Pane.md)

## Changes

- 2026-06-05: Changed autogen reconstructability from blank to `FALSE`.
  - Before: the page was scored `-1/-1` as a stale generated owner but remained unclassified in `-ag-class-coverage.md`.
  - After: the alias is explicitly non-reconstructable as a class; the code remains [UID:00000W][BlackHole](by-class/BlackHole.md) deferred deletion behavior.
  - Evidence: live IDA MCP on 2026-06-05 confirms `sub_469180` at `0x00469180` (`0x7a` bytes) with broad pane/dialog caller fan-in, matching the existing BlackHole queue ownership rather than a standalone class.
- Before: completion/confidence metadata were `0/0`, leaving this stale generated owner in the active score queue.
- Changed to: `COMPLETION:-1` and `CONFIDENCE:-1`.
- Evidence: the page states `PaneChildRegistry` is a stale generated class name for [UID:00000W][BlackHole](by-class/BlackHole.md) deferred deletion behavior; active source and memory ownership point to `BlackHole`, not a standalone original class.
