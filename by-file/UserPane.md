*** UID:0000P1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# UserPane

## Status

- Confidence: strong for `UserPane` class anchors and `ui/panels/` placement; medium-high for final split from adjacent `LivingObjectPane` and social-input helpers.
- Proposed module: `NexusTK/ui/panels/UserPane.cpp`
- Current recovered source: `class_UserPane.cpp`
- Main address doc: [UID:0001KL][0x005a2530-0x005b8395.UserPane](by-memory/0x005a2530-0x005b8395.UserPane.md)

## File Role

`UserPane.cpp` owns the local player/user display pane that sits in the in-game UI graph. It constructs the main user pane singleton, coordinates local-player display state, handles key input and server messages routed to the player pane, updates animation/clip bounds, shows or hides the floating name label, and tears down very large per-user child/state arrays.

This file should be treated as a user/player pane module, not as the owner of every helper physically near `0x005a2530-0x005a8f8c`. The same neighborhood contains `LivingObjectPane` movement/combat helpers and social/say-input helpers already documented elsewhere.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `UserPane` | constructor `0x005a2530-0x005a2c5b`, destructor `0x005b8230-0x005b8395` | Main local user pane, singleton `g_pUserPane`/`dword_67A748`, child arrays, resources, input and server-message routing. |
| non-deleting destructor | `0x005a2c60-0x005a2d74` | IDA-confirmed cleanup body; currently unknown to Wave3. |
| selected/user name helper | `0x005a2d80-0x005a2d97` | Copies a wide string into global `word_69BEE0`; likely user-name/label helper, currently unknown to Wave3. |
| slot label helpers | `0x005a40d0-0x005a4523` | Builds compact inventory/spell slot label strings for visible command rows. |
| `OnBoundsChanged` / `OnKeyEvent` | `0x005a5b80-0x005a7422` | Geometry update and key-driven local player commands. |
| `OnServerMessage` | `0x005a76c0-0x005a82bd` | Handles server message payloads routed to the local user pane. |
| `OnAnimationStep` / `OnClipBounds` | `0x005a83b0-0x005a88cf` | Animation update and clipping behavior. |
| name-label methods | `0x005a8e70-0x005a8f8c` | Shows/hides the local user's name label pane and coordinates the active [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md). |
| [UID:000040][DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528](by-class/DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528.md) | `0x005b77b0-0x005b77c8` | Template callback wrapper bound by drop/give input panes to a `UserPane` action target. |
| [UID:00024A][0x005b83a0-0x005b83a7.UserPaneVirtualDword1340F8Accessor](by-memory/0x005b83a0-0x005b83a7.UserPaneVirtualDword1340F8Accessor.md) | `0x005b83a0-0x005b83a7` | Tiny `UserPane` vtable accessor for the dword at `this + 0x1340f8`; field semantics remain unresolved. |

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
- IDA MCP on 2026-05-26 confirms the destructor and `HideNameLabel` paths read [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md) and call the BowGauge timer cleanup helper at [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md). This is not BulletinSession logic despite the generated label.
- IDA MCP on 2026-05-26 identifies the large [UID:0000FQ][UserPane](by-class/UserPane.md) [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md) at `0x0069bf34`, constructed by `0x0041a4b0` with block size `1305476` and `2` blocks per chunk. The related constructor-failure cleanup wrapper is [UID:0001AA][0x00502420-0x0050245e.UserPanePoolFreeUnwindWrapper](by-memory/0x00502420-0x0050245e.UserPanePoolFreeUnwindWrapper.md).
- Current IDA MCP xrefs on 2026-06-02 tie `0x0069bf34` to the static constructor wrapper `0x0041a4b0`, UI allocation sites `0x004f84c5`/`0x004f8a2c`, unwind wrapper `0x00502420`, scalar destructor cleanup `0x005b834e`, and static destructor wrapper `0x0060c450`.
- Current IDA MCP xrefs on 2026-06-02 tie the local-player name buffer `0x0069bee0` to `0x005a2d80`, neighboring getter/conversion helpers `0x005a2da0`/`0x005a2dc0`, and block-list validation `0x005b6cc0`.
- IDA MCP on 2026-05-28 confirms the adjacent `0x005b83a0-0x005b83a7` function is a `UserPane` vtable accessor, not part of `UserStatusPane`; keep it with `UserPane.cpp` unless later field semantics tie it to a narrower helper.
- Current IDA MCP byte checks on 2026-06-02 confirm the neighboring `0x005a2523-0x005a2530`, `0x005b8395-0x005b83a0`, and `0x005b83a7-0x005b83b0` spans are all `0xcc` padding with no function starts.
- Wave3 currently omits several IDA-confirmed local helper starts and still attaches some social/history helpers to `UserPane`; use the exclusion notes above before source migration.
- The drop/give confirmation callback wrapper is [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) template support. Keep its type declaration with the shared callback family while leaving `UserPane` as the target action owner.

## Cross-References

- [UID:0000FQ][UserPane](by-class/UserPane.md)
- [UID:0001KL][0x005a2530-0x005b8395.UserPane](by-memory/0x005a2530-0x005b8395.UserPane.md)
- [UID:0000P0][UserLookPane](by-file/UserLookPane.md)
- [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md)
- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md)
- [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md)
- [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md)
- [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md)
- [UID:0001AA][0x00502420-0x0050245e.UserPanePoolFreeUnwindWrapper](by-memory/0x00502420-0x0050245e.UserPanePoolFreeUnwindWrapper.md)
- [UID:00024A][0x005b83a0-0x005b83a7.UserPaneVirtualDword1340F8Accessor](by-memory/0x005b83a0-0x005b83a7.UserPaneVirtualDword1340F8Accessor.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/78`. Summary/evidence: the page covers local-player pane ownership, method families, global/layout links, and boundaries against `LivingObjectPane` and chat-input helpers; the large range and adjacent social/UI helpers keep final source split below high confidence.
- 2026-06-02 path and confidence update:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and confidence stayed below the parent-attachment threshold at `78`.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/"`, scores `88/82`, and stronger current IDA evidence for function sizes, caller sites, global xrefs, and padding boundaries.
  - Summary/evidence: current IDA MCP and raw IDA export checks confirm the UserPane anchors and surrounding exclusions, while `by-project-structure/proposed-source-tree.md` already places `UserPane.cpp` under `ui/panels/`.
