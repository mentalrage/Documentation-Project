*** UID:0000M3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ObjectImageControlPane

## Status

- Confidence: strong for `ObjectImageControlPane` behavior and strong that `ObjectImageButtonPane` belongs in this source family.
- Proposed module: `ui/controls/ObjectImageControlPane.cpp`
- Current recovered sources: `source-3/simroot_v2/class_ObjectImageControlPane.cpp` and sibling `source-3/simroot_v2/class_ObjectImageButtonPane.cpp`

## File Role

`ObjectImageControlPane` is the reusable centered object-image preview control used by packet/menu/dialog UI. It stores a 68-byte image descriptor and paints one of three image families:

- type `0`: human images through `NewHumanImageLib`.
- type `1`: monster images through `MonsterImageLib`.
- type `2`: item/NPC EPF frames through the EPF resource library.

`ObjectImageButtonPane` derives from this display behavior and adds button activation, a pane type id, and a highlight/overlay flag. The constructor adjacency, direct base-constructor call, and shared destructor thunk neighborhood make this the preferred original source family for the button variant; [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) should keep only a cross-reference.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `ObjectImageControlPane` | `0x00520540-0x00520816`, thunks `0x00520afd`/`0x00520b08`, destructor `0x00520ca0-0x00520cda` | Centered non-interactive image preview control for human, monster, and EPF-backed object images. |
| `ObjectImageButtonPane` | `0x00520820-0x00520a8f`, thunks `0x00520ae7`/`0x00520af2`, destructor `0x00520c60-0x00520c9a` | Button subclass that reuses object-image rendering, handles Enter/Space activation, and stores an overlay/highlight byte. |

## Evidence Notes

- IDA MCP confirms `ObjectImageControlPane::ObjectImageControlPane` at `0x00520540-0x005205b4`, `OnPaint` at `0x005205c0-0x00520816`, adjustor thunks at `0x00520afd-0x00520b12`, and scalar deleting destructor at `0x00520ca0-0x00520cda`.
- IDA MCP reports many constructor xrefs for `0x00520540`, including text-menu constructors, argumented-menu construction at `0x0051e9a0`, message/menu-question dialogs, head-selection UI, client/server item menu dialogs, and the `ObjectImageButtonPane` constructor at `0x00520820`.
- Generated source call sites include `ArgumentedMenuMenuDialog`, `ClientItemMenuDialog`, `ClientSpellMenuDialog`, [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md), `MenuQuestionDialog`, `MessageDialog`, `ServerItemMenuDialog`, `ServerSpellMenuDialog`, [UID:0000OL][TextDialog](by-file/TextDialog.md), and `TextInputMenuDialog`.
- IDA MCP decompiles both object-image deleting destructors as calls to shared pane-base teardown helper `0x00544580` followed by conditional delete helper `0x004f4ac0`; current generated `TextButtonExControlPane`/`Pane` labels are owner-name pollution, not inheritance proof.
- `ObjectImageButtonPane::SetButtonHighlight` at `0x00520a80` is called by [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md) paths at `0x0055149a`, `0x0055209a`, and `0x005520c3`.

## Placement Notes

Prefer `ui/controls/ObjectImageControlPane.cpp` over a feature-dialog file because the control has broad dialog reuse and no single owning feature. Move `ObjectImageButtonPane` into this object-image control module or a directly adjacent `ObjectImageButtonPane.cpp`; do not keep it in the generic specialized-button bucket unless later source-file evidence outweighs the inheritance/locality evidence.

## Cross-References

- [UID:00009O][ObjectImageControlPane](by-class/ObjectImageControlPane.md)
- [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md)
- [UID:00009N][ObjectImageButtonPane](by-class/ObjectImageButtonPane.md)
- [UID:0001BV][0x00520820-0x00520c9a.ObjectImageButtonPane](by-memory/0x00520820-0x00520c9a.ObjectImageButtonPane.md)
- [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md)
- [UID:0000OL][TextDialog](by-file/TextDialog.md)
- [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)
- [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `86`, confidence `84`.
- Summary/evidence: the page documents the reusable preview/button control family, proposed contents, broad constructor caller evidence, destructor-owner pollution, placement notes, and cross-references; confidence is strong because behavior and sibling ownership are well supported.
- 2026-06-01: Set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/ui/controls/` so reviewed object-image child pages can attach without autogen path errors.
