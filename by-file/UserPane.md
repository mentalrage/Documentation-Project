*** UID:0000P1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# UserPane

## Status

- Confidence: strong for `UserPane` class anchors, `ui/panels/` placement, local-player name-buffer ownership, and pool/singleton anchors; medium-high for final split from adjacent `LivingObjectPane` and social-input helpers.
- Proposed module: `NexusTK/ui/panels/UserPane.cpp`
- Main address doc: [UID:0001KL][0x005a2530-0x005b8395.UserPane](by-memory/0x005a2530-0x005b8395.UserPane.md)

## File Role

`UserPane.cpp` owns the local player/user display pane that sits in the in-game UI graph. It constructs the main user pane singleton, coordinates local-player display state, handles key input and server messages routed to the player pane, updates animation/clip bounds, shows or hides the floating name label, and tears down very large per-user child/state arrays.

This file should be treated as a user/player pane module, not as the owner of every helper physically near `0x005a2530-0x005a8f8c`. The same neighborhood contains `LivingObjectPane` movement/combat helpers and social/say-input helpers already documented elsewhere.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `UserPane` | constructor `0x005a2530-0x005a2c5b`, destructor `0x005b8230-0x005b8395` | Main local user pane, singleton [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / `dword_67A748`, child arrays, resources, input and server-message routing. |
| non-deleting destructor | `0x005a2c60-0x005a2d74` | IDA-confirmed cleanup body that should stay with the `UserPane` class despite being separate from the scalar deleting destructor. |
| selected/user name helper | `0x005a2d80-0x005a2d97`, [UID:0002AA][0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer](by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md) | Copies a wide string into the fixed `wchar_t[32]` local-player/user-label buffer. |
| slot label helpers | `0x005a40d0-0x005a4523` | Builds compact inventory/spell slot label strings for visible command rows. |
| `OnBoundsChanged` / `OnKeyEvent` | `0x005a5b80-0x005a7422` | Geometry update and key-driven local player commands. |
| `OnServerMessage` | `0x005a76c0-0x005a82bd` | Handles server message payloads routed to the local user pane. |
| `OnAnimationStep` / `OnClipBounds` | `0x005a83b0-0x005a88cf` | Animation update and clipping behavior. |
| name-label methods | `0x005a8e70-0x005a8f8c` | Shows/hides the local user's name label pane and coordinates the active [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md). |
| [UID:000040][DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528](by-class/DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528.md) | [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md), [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md) | Template callback support bound by drop/give input panes to a `UserPane` action target. |
| [UID:00024A][0x005b83a0-0x005b83a7.UserPaneVirtualDword1340F8Accessor](by-memory/0x005b83a0-0x005b83a7.UserPaneVirtualDword1340F8Accessor.md) | `0x005b83a0-0x005b83a7` | Tiny `UserPane` vtable accessor for the dword at `this + 0x1340f8`; field semantics remain unresolved. |
| [UID:0002AC][0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage](by-memory/0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage.md) | `0x0069bf34-0x0069bf5c` | Static pool storage for large `UserPane` allocations; constructor/static-wrapper/destructor xrefs prove this is a `UserPane.cpp` module-scope declaration, not a shared pool-inventory parent. |

## Boundaries

- Keep movement/combat/object logic such as `ProcessMovement`, `UseCommandSlot`, `WarpToPosition`, `UpdateScreenPosition`, and `SendMovementPacket` with `LivingObjectPane` or a future movement/object-pane file, even though they are physically interleaved with the `UserPane` neighborhood.
- Keep chat and say-input helpers such as `0x005a4930-0x005a5791` with [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) or [UID:0000I5][Chatting](by-file/Chatting.md), not with `UserPane`, unless final caller evidence proves the original source file intentionally combined them.
- Keep [UID:0000P0][UserLookPane](by-file/UserLookPane.md) and [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md) separate. `UserPane` is the local user display/event surface, while those modules own look/profile/status panel content.

## Evidence Notes

- Current IDA MCP lookup on 2026-06-02 confirms the primary `UserPane` anchors: constructor `0x005a2530` size `0x72b`, non-deleting destructor `0x005a2c60` size `0x114`, name-buffer setter `0x005a2d80` size `0x17`, slot label helpers at `0x005a40d0` size `0x23c` and `0x005a4310` size `0x213`, virtual handlers at `0x005a5b80`/`0x005a5bd0`/`0x005a76c0`/`0x005a83b0`/`0x005a8840`, name-label methods at `0x005a8e70`/`0x005a8f60`, and scalar deleting destructor `0x005b8230` size `0x165`.
- IDA confirms the constructor at `0x005a2530-0x005a2c5b`, with xrefs from UI initialization paths at `0x004f84e2` and `0x004f8a49`.
- Current IDA MCP caller checks on 2026-06-02 also confirm the local-player name-buffer setter at `0x005a2d80` is called from the same UI initialization function at `0x004f84ad` and `0x004f8a14`.
- IDA confirms the scalar deleting destructor at `0x005b8230-0x005b8395`, reached through vtable/destructor thunks around `0x005b792e` and `0x005b7939`.
- IDA confirms `0x005a2c60` as a real non-deleting destructor cleanup body matching the scalar deleting destructor without the conditional delete.
- IDA MCP on 2026-05-26 confirms the destructor and `HideNameLabel` paths read [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md) and call the BowGauge timer cleanup helper at [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md). This is not BulletinSession logic despite older labels.
- IDA MCP on 2026-05-26 identifies the large [UID:0000FQ][UserPane](by-class/UserPane.md) [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md) at `0x0069bf34`, constructed by `0x0041a4b0` with block size `1305476` and `2` blocks per chunk. The related constructor-failure cleanup wrapper is [UID:0001AA][0x00502420-0x0050245e.UserPanePoolFreeUnwindWrapper](by-memory/0x00502420-0x0050245e.UserPanePoolFreeUnwindWrapper.md).
- Current IDA MCP xrefs on 2026-06-02 tie `0x0069bf34` to the static constructor wrapper `0x0041a4b0`, UI allocation sites `0x004f84c5`/`0x004f8a2c`, unwind wrapper `0x00502420`, scalar destructor cleanup `0x005b834e`, and static destructor wrapper `0x0060c450`.
- 2026-06-07 A005 Batch 059 parent-gate recheck assigns [UID:0002AC][0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage](by-memory/0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage.md) to this file: the child is `90/88`, this file is `89/85`, all six live data xrefs are `UserPane` allocation/lifetime paths, and the exact pool-object range ends before the separate `g_pQuitInputPane` singleton at `0x0069bf5c`.
- Current IDA MCP xrefs on 2026-06-02 tie the local-player name buffer `0x0069bee0` to `0x005a2d80`, neighboring getter/conversion helpers `0x005a2da0`/`0x005a2dc0`, and block-list validation `0x005b6cc0`.
- 2026-06-07 Batch 058 confirms [UID:0002AA][0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer](by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md) is exactly 32 wide characters by the `_wcscpy_s(..., 0x20, ...)` bound, with no split needed and direct ownership by this file.
- IDA MCP on 2026-05-28 confirms the adjacent `0x005b83a0-0x005b83a7` function is a `UserPane` vtable accessor, not part of `UserStatusPane`; keep it with `UserPane.cpp` unless later field semantics tie it to a narrower helper.
- Current IDA MCP byte checks on 2026-06-02 confirm the neighboring `0x005a2523-0x005a2530`, `0x005b8395-0x005b83a0`, and `0x005b83a7-0x005b83b0` spans are all `0xcc` padding with no function starts.
- Several local helper starts and social/history helpers near the `UserPane` range still need source-owner separation; use the exclusion notes above before source migration.
- The drop/give confirmation callback support is [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) template support. Current IDA confirms [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md) constructs the callback object with [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / `dword_67A748` as the target, while [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md) is the vtable invoke body.

## Cross-References

- [UID:0000FQ][UserPane](by-class/UserPane.md)
- [UID:0001KL][0x005a2530-0x005b8395.UserPane](by-memory/0x005a2530-0x005b8395.UserPane.md)
- [UID:0002AA][0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer](by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md)
- [UID:0000P0][UserLookPane](by-file/UserLookPane.md)
- [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md)
- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md)
- [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md)
- [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md)
- [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md)
- [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md)
- [UID:0001AA][0x00502420-0x0050245e.UserPanePoolFreeUnwindWrapper](by-memory/0x00502420-0x0050245e.UserPanePoolFreeUnwindWrapper.md)
- [UID:00024A][0x005b83a0-0x005b83a7.UserPaneVirtualDword1340F8Accessor](by-memory/0x005b83a0-0x005b83a7.UserPaneVirtualDword1340F8Accessor.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)

## Changes

- 2026-06-07 A005 Batch 059 pool-child assignment:
  - Before: [UID:0002AC][0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage](by-memory/0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage.md) documented `0x0069bf34-0x0069bf5c` as `UserPane` pool storage but had no autogen parent.
  - After: [UID:0002AC][0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage](by-memory/0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage.md) is assigned to this file as the direct source owner. File scores remain `89/85`; this was a routing/evidence refresh, not a full file rescore.
  - Evidence: the pool range has only `UserPane` static construction, UI allocation, unwind/free, scalar destructor, and static cleanup xrefs, and the direct child/parent pair both meet the corrected `85/85` gate.
- 2026-06-07 Batch 058 parent-gate refresh:
  - Before: `COMPLETION:88`, `CONFIDENCE:82`.
  - After: `COMPLETION:89`, `CONFIDENCE:85`.
  - Evidence: attached the exact [UID:0002AA][0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer](by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md) child and recorded the `_wcscpy_s(..., 0x20, ...)` size proof, xref set, and no-split boundary. The remaining uncertainty is source split cleanup around adjacent `LivingObjectPane` and social-input helpers.
- 2026-06-07 A005 resolved-name cleanup:
  - Before: source-file ownership notes used only historical `dword_67A748` for the UserPane singleton/callback target.
  - After: the page records canonical `g_pCollectionData` beside the historical label and cross-links the global page.
  - Evidence: generated resolved-name report maps `dword_67A748` to `g_pCollectionData`; existing IDA-backed evidence already ties the address to UserPane construction and callback target storage.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/78`. Summary/evidence: the page covers local-player pane ownership, method families, global/layout links, and boundaries against `LivingObjectPane` and chat-input helpers; the large range and adjacent social/UI helpers keep final source split below high confidence.
- 2026-06-02 path and confidence update:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and confidence stayed below the parent-attachment threshold at `78`.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/"`, scores `88/82`, and stronger current IDA evidence for function sizes, caller sites, global xrefs, and padding boundaries.
  - Summary/evidence: current IDA MCP and raw IDA export checks confirm the UserPane anchors and surrounding exclusions, while `by-project-structure/proposed-source-tree.md` already places `UserPane.cpp` under `ui/panels/`.
- 2026-06-05 FunctionObjects callback refresh:
  - Before: the page still carried stale source-provenance wording and referenced the drop/give callback only by the invoke-wrapper range.
  - After: removed stale provenance wording and linked the exact [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md) helper with [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md).
  - Evidence: current IDA MCP confirms the helper stores `dword_67A748` / `g_pCollectionData` as the callback target and the invoke body dispatches through the stored `UserPane` member pointer.
