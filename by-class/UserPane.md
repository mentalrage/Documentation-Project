*** UID:0000FQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# UserPane

## Status

- Confidence: strong for class purpose; medium for generated method ownership around social/history helpers.
- Likely source file: [UID:0000P1][UserPane](by-file/UserPane.md)
- Address range: [UID:0001KL][0x005a2530-0x005b8395.UserPane](by-memory/0x005a2530-0x005b8395.UserPane.md)
- Current recovered file: `source-3/simroot_v2/class_UserPane.cpp`

## Class Purpose

`UserPane` is the local player/user display pane. It constructs the main local-user pane object, stores large per-user state arrays, routes key and server-message input, updates animation and clipping, tracks visible slot labels, and manages the floating local name label.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x005a2530-0x005a2c5b` | Constructs the pane, installs `UserPane` vtables, sets the global active user pane pointer, initializes large state arrays, resources, and child panes. |
| non-deleting destructor | `0x005a2c60-0x005a2d74` | IDA-confirmed cleanup body; currently unknown to Wave3. |
| selected/user name helper | `0x005a2d80-0x005a2d97` | Copies a wide string into global `word_69BEE0`; currently unknown to Wave3. |
| `BuildInventorySlotLabelString` | `0x005a40d0-0x005a430c` | Builds compact inventory slot label/range strings. |
| `BuildSpellSlotLabelString` | `0x005a4310-0x005a4523` | Builds compact spell slot label/range strings. |
| chat/history helpers | `0x005a4930-0x005a4c8b` | Currently owned by `UserPane` in Wave3, but behavior/callers tie them to chat/say-input history; source ownership is under review. |
| `OnBoundsChanged` | `0x005a5b80-0x005a5bc7` | Updates cached bounds and invalidates child geometry. |
| `OnKeyEvent` | `0x005a5bd0-0x005a7422` | Handles local-player keyboard commands and dispatches related panes/packets. |
| `OnServerMessage` | `0x005a76c0-0x005a82bd` | Parses server payloads routed to the local user pane. |
| `OnAnimationStep` | `0x005a83b0-0x005a87ad` | Handles animation/update ticks. |
| `OnClipBounds` | `0x005a8840-0x005a88cf` | Applies local clipping behavior. |
| `ShowNameLabel` | `0x005a8e70-0x005a8f5a` | Shows and positions the floating name-label pane. |
| `HideNameLabel` | `0x005a8f60-0x005a8f8c` | Hides the floating name-label pane and removes pending timers from [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md) through the BowGauge helper at [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md). |
| scalar deleting destructor | `0x005b8230-0x005b8395` | Full destructor body plus conditional delete. |
| virtual dword `+0x1340f8` accessor | `0x005b83a0-0x005b83a7` | Tiny vtable accessor; semantic field name still provisional. |

## Evidence Notes

- Wave3 reports `UserPane` grade `95.3` and zero missing refs.
- IDA confirms constructor xrefs from `0x004f84e2` and `0x004f8a49`.
- IDA confirms the destructor helper at `0x005a2c60`; Wave3 currently reports this address as unknown.
- IDA MCP on 2026-05-26 shows the non-deleting destructor, `HideNameLabel`, and scalar deleting destructor call [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md) through [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md). The generated `BulletinSession::RemoveFromUpdateScheduler` label for `0x00538c40` is owner pollution.
- IDA MCP on 2026-05-28 confirms the adjacent `0x005b83a0-0x005b83a7` body is a `UserPane` vtable slot that returns the dword at `this + 0x1340f8`; surrounding bytes are `0xcc` padding.
- IDA shows many nearby functions owned by `LivingObjectPane` or social input features, so the broad address neighborhood should not be treated as one `UserPane` source file without exclusions.

## Cross-References

- [UID:0000P1][UserPane](by-file/UserPane.md)
- [UID:0001KL][0x005a2530-0x005b8395.UserPane](by-memory/0x005a2530-0x005b8395.UserPane.md)
- [UID:0000FP][UserLookPane](by-class/UserLookPane.md)
- [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md)
- [UID:000011][BowGaugeObjectPane](by-class/BowGaugeObjectPane.md)
- [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md)
- [UID:00024A][0x005b83a0-0x005b83a7.UserPaneVirtualDword1340F8Accessor](by-memory/0x005b83a0-0x005b83a7.UserPaneVirtualDword1340F8Accessor.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:76`.
  - Summary/evidence: scored from the broad method map, constructor/destructor evidence, local-user input/message/animation/name-label roles, BowGauge owner-pollution correction, and accessor boundary note; confidence is capped because the broad address neighborhood still contains LivingObjectPane/social-helper ownership caveats and some generated names remain provisional.
