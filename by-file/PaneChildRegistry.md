*** UID:0000MD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:97 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# PaneChildRegistry

## Status

- Confidence: original-proof that the name is a stale alias and that `0x00469180` is BlackHole project code.
- Historical recovery state: `PaneChildRegistry` survives only as a stale generated owner label for the `0x00469180` helper. Authoritative by-* ownership places the real code under [UID:0000HR][BlackHole](by-file/BlackHole.md).
- Canonical real owner: [UID:0000HR][BlackHole](by-file/BlackHole.md)
- Corrected address doc: [UID:0000Z0][0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue](by-memory/0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md)

## File Role

`PaneChildRegistry` is a stale generated owner/name for `0x00469180`. The function is real project code, but the best current interpretation is not child registration. IDA shows it is a [UID:0000HR][BlackHole](by-file/BlackHole.md) helper that prepares a pane for deferred deletion: remove it from its layer, unregister its event handler, cancel timer events, deduplicate the pointer, and append it to the global cleanup queue.

Keep this page as a non-emitting compatibility warning. It deliberately has reconstruction path `NONE`, canonical owner `NONE`, and no PaneChildRegistry CPP or H.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `BlackHole::QueuePaneForDeferredDeletion` | `0x00469180-0x004691fa` | Pane detach/event unregister/timer cancel path before deferred deletion. |

## Boundary Notes

- IDA confirms `0x00469180-0x004691fa` as an exact function and reports broad direct caller fan-in across pane/dialog close and replacement paths.
- The first two virtual calls through the pane object are `Pane::RemoveFromLayer` and `Pane::UnregisterEventHandler`, not setup hooks.
- The timer-manager call removes pending timer events for the pane timer-handler subobject.
- The object is appended into `dword_67A74C`, the [UID:0000HR][BlackHole](by-file/BlackHole.md) singleton queue drained by idle work.

## Whole-File Disposition

- Complete negative proof found no PaneChildRegistry-owned function, global, local type, UDT, RTTI, vtable, resource, string, static, by-item entity, proposed-source-tree file, or generated CPP/H.
- The real source family is exactly six BlackHole functions: constructor `[0x004690b0,0x004690f6)`, ordinary destructor `[0x00469100,0x00469115)`, generic enqueue `[0x00469120,0x00469171)`, pane queue `[0x00469180,0x004691fa)`, drain `[0x00469200,0x00469233)`, and compiler-generated scalar deleting destructor `[0x00469240,0x00469288)`.
- The family also preserves six exact `0xcc` pads: `[0x004690f6,0x00469100)`, `[0x00469115,0x00469120)`, `[0x00469171,0x00469180)`, `[0x004691fa,0x00469200)`, `[0x00469233,0x00469240)`, and `[0x00469288,0x00469290)`. The successor function begins at `0x00469290` and is not BlackHole.
- Binary identity closes through the ten-slot BlackHole vtable `[0x00613118,0x00613140)`, BlackHole/Singleton RTTI, singleton storage at `0x0067a74c`, and the `0x14`-byte List-primary-base layout.
- The queue helper has 83 exact incoming calls. Forty-nine modeled caller functions and the three unmodeled call sites `0x0046e28d`, `0x0053dd9f`, and `0x00545dd7` are consumers, not owners.
- Dated generated snapshot command `000000024682` at `2026-08-16T01:45:46-04:00` observed `BlackHole.cpp` present, `BlackHole.h` absent, and PaneChildRegistry CPP/H absent. That snapshot is historical evidence; generated artifacts are validator-owned and must be reread after an owning-route refresh.

## Cross-References

- [UID:0000A3][PaneChildRegistry](by-class/PaneChildRegistry.md)
- [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md)
- [UID:0000HR][BlackHole](by-file/BlackHole.md)
- [UID:00000W][BlackHole](by-class/BlackHole.md)
- [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)

## Changes

- 2026-08-16 B009 UID0000MD accepted ordinary implementation:
  - What changed: raised the score from `86/88` to `94/97`, made the alias/no-source disposition explicit, historicalized generated-state wording, and added the complete BlackHole family, padding, caller, type, vtable, global, and negative-inventory closure.
  - Source disposition: no PaneChildRegistry CPP or H is emitted. The only real body is [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md) under [UID:0000HR][BlackHole](by-file/BlackHole.md).

- 2026-06-14 A001 non-standalone refresh:
  - Before: score `80/86`; the page identified the stale alias but still described the old generated state as if it were current evidence, and the manual by-file coverage row still marked the page reconstructable.
  - Changed to: score `86/88`; `PROPOSED_RECONSTRUCTION_PATH:"NONE"` and `CANONICAL_OWNER:NONE` stay unchanged because this is a completed alias/warning page, not a source root.
  - Summary/evidence: live IDA MCP session `b001_0003gy` reconfirmed `sub_469180` at `0x00469180-0x004691fa`, 83 code xrefs across 49 caller functions, pane virtual calls at slots `+0x38/+0x40`, timer cleanup through `sub_597A10`, inherited `List` dedup/append behavior, and `0xcc` padding at `0x00469171-0x00469180` and `0x004691fa-0x00469200`. The authoritative source owner remains [UID:0000HR][BlackHole](by-file/BlackHole.md).
- 2026-06-05: Marked the projected reconstruction path as `NONE`.
  - Before: the path was blank, leaving a documented stale alias in by-file generated-root error state.
  - After: the page is explicitly non-standalone; the real code remains owned by [UID:0000HR][BlackHole](by-file/BlackHole.md) as deferred pane deletion queue behavior.
  - Evidence: live IDA MCP `lookup_funcs` confirms `sub_469180` at `0x00469180` (`0x7a` bytes), and `callers` shows broad pane/dialog close fan-in, matching the documented queue helper role rather than an independent `PaneChildRegistry.cpp`.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `80`, confidence `86`.
- Summary/evidence: the page clearly documents the stale generated alias, corrected BlackHole ownership, function role, boundary notes, and cross-references; completion is lower because the page is intentionally an alias/warning rather than a real final source module.
