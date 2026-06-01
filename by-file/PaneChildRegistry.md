*** UID:0000MD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# PaneChildRegistry

## Status

- Confidence: stale name; strong that `0x00469180` is project code.
- Current generated state: no standalone `class_PaneChildRegistry.cpp` is emitted in `simroot_v2`; stale owner context still appears inside `class_BlackHole.meta_wave3`.
- Corrected owner candidate: [UID:0000HR][BlackHole](by-file/BlackHole.md)
- Corrected address doc: [UID:0000Z0][0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue](by-memory/0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md)

## File Role

`PaneChildRegistry` is a stale generated owner/name for `0x00469180`. The function is real project code, but the best current interpretation is not child registration. IDA shows it is a [UID:0000HR][BlackHole](by-file/BlackHole.md) helper that prepares a pane for deferred deletion: remove it from its layer, unregister its event handler, cancel timer events, deduplicate the pointer, and append it to the global cleanup queue.

Keep this page only as an alias/warning until the remaining generated metadata owner context is corrected.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `BlackHole::QueuePaneForDeferredDeletion` | `0x00469180-0x004691fa` | Pane detach/event unregister/timer cancel path before deferred deletion. |

## Boundary Notes

- IDA confirms `0x00469180-0x004691fa` as an exact function and reports broad direct caller fan-in across pane/dialog close and replacement paths.
- The first two virtual calls through the pane object are `Pane::RemoveFromLayer` and `Pane::UnregisterEventHandler`, not setup hooks.
- The timer-manager call removes pending timer events for the pane timer-handler subobject.
- The object is appended into `dword_67A74C`, the [UID:0000HR][BlackHole](by-file/BlackHole.md) singleton queue drained by idle work.

## Cross-References

- [UID:0000A3][PaneChildRegistry](by-class/PaneChildRegistry.md)
- [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md)
- [UID:0000HR][BlackHole](by-file/BlackHole.md)
- [UID:00000W][BlackHole](by-class/BlackHole.md)
- [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `80`, confidence `86`.
- Summary/evidence: the page clearly documents the stale generated alias, corrected BlackHole ownership, function role, boundary notes, and cross-references; completion is lower because the page is intentionally an alias/warning rather than a real final source module.
