*** UID:0000P2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# UserStatusPane

## Status

- Confidence: strong for class grouping and UI role, medium for final split between one source file and small companion files.
- Proposed module: `ui/panels/UserStatusPane.cpp`
- Proposed header: `ui/panels/UserStatusPane.h`
- Current recovered sources: `source-3/simroot_v2/class_UserStatusPane.cpp`, `class_UserStatusPane2.cpp`, and `class_OldUserStatusPane.cpp`.

## File Role

`UserStatusPane.cpp` should own the local player status HUD panes. The code supports both the newer/high-resolution layout and the older compact/legacy layout selected through the global layout mode (`byte_66DA97` in IDA, emitted in some generated code as `g_uiLayoutMode`).

The strongest source-layout evidence is `InitializeMainUiGraph` at `0x004f7d10`: in the newer layout it constructs both `UserStatusPane` and `UserStatusPane2`; in the older layout it constructs `OldUserStatusPane`. All three load the same `9X11FONT.BIN` numeric glyph table and share status-field update patterns, icon ids, resource families, and destructor thunk layout.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md) | [UID:0001NM][0x005b83b0-0x005baafe.UserStatusPane](by-memory/0x005b83b0-0x005baafe.UserStatusPane.md) plus shared tail helpers | Newer status summary pane: name/title text, nation/totem/class icons, status numbers, bars, tooltips, and status-packet application. |
| [UID:0000FT][UserStatusPane2](by-class/UserStatusPane2.md) | [UID:0001NO][0x005bab00-0x005bc60c.UserStatusPane2](by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md) plus shared tail helpers | Compact meter pane with `BAR.EPF` bars, large numbers, comma separators, and packet-applied value updates. |
| [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md) | [UID:0001NR][0x005bda40-0x005bfbc1.OldUserStatusPane](by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md) plus shared tail helpers | Legacy status panel: `USERSTAT.EPD`, old hover help zones, old icon/bars, and status-packet application. |
| [UID:0001WF][UserStatusPaneSummaryFields](by-type/by-struct/UserStatusPaneSummaryFields.md) | [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md) accessors | Field-layout slice currently emitted as generated [UID:0000I4][CharacterSummaryRecord](by-file/CharacterSummaryRecord.md); fold into `UserStatusPane`, not a separate source file. |
| [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) | [UID:0001PE][0x0069ae0c-0x0069ae10.g_activeUserStatusPane](by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md) | Newer status-pane singleton; also read by local inventory/user-pane consumers for fields such as the inventory slot count at pointee offset `+0x284`. |
| [UID:0000SN][g_pUserStatusPane2](by-global/g_pUserStatusPane2.md) | `0x0069b4e4` | Compact status-meter singleton. |
| [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md) | `0x0069b4ec` | Legacy status-pane singleton. |
| [UID:0001RS][user-status-resources](by-resource/user-status-resources.md) | resource strings in paint/load paths | `USERSTAT`, `NATION`, `TOTEM`, `CLASS`, `BAR`, `COMMA`, palette, and font assets. |

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Main UI construction | `0x004f837a`, `0x004f83ea`, `0x004f8951` | `InitializeMainUiGraph` constructs the new pair or the old pane depending on layout mode. |
| Newer status pane | `0x005b83b0`, `0x005b8700`, `0x005ba4a0` | Construction, packet routing, field updates, and totem-frame invalidation/creation. |
| Compact meter pane | `0x005bab00`, `0x005bac80`, `0x005bc420` | Construction, movement/packet handling, and compact bar/value updates. |
| Legacy status pane | `0x005bda40`, `0x005bdcb0`, `0x005bf7c0` | Construction, legacy packet routing, field updates, and totem-frame invalidation/creation. |
| Destructor/adjustor tail | [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md) | Shared compiler-generated tail containing singleton clear helpers, adjustor thunks, scalar deleting destructors, and one reusable vector helper. |

## Source-Layout Notes

- Keep [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md) separate. It is address-adjacent between `UserStatusPane2` and `OldUserStatusPane`, but it owns the in-game menu button and selector, not local status rendering.
- The shared destructor/thunk tail starts with `0x005bfbd0`, now resolved as [UID:0000RJ][g_pMenuVarietySelectPane](by-global/g_pMenuVarietySelectPane.md) cleanup. Do not assign that first clear helper to status-pane code.
- Keep [UID:0000OV][TotemFrame](by-file/TotemFrame.md) adjacent or private to this feature area. `UserStatusPane` and `OldUserStatusPane` update handlers create or invalidate `g_pTotemFrame`, while `TotemFrame::OnPaint` asks `OldUserStatusPane::GetSpiritId` for the frame index.
- A plausible original layout is one `UserStatusPane.cpp` containing all three variants plus small static helpers, with `TotemFrame.cpp` either adjacent or folded in after final source grouping review.

## Data Caveats

- Active generated output omits important IDA-confirmed functions in all three classes, especially packet/update helpers and destructor clear/thunk helpers.
- Active generated output also emits `source-3/simroot_v2/class_CharacterSummaryRecord.cpp` as a standalone recovered class. Treat that file as a generated split of `UserStatusPane` accessors over `g_activeUserStatusPane`, not as an original source module.
- Generated destructor bodies label the pane base cleanup as `TextButtonExControlPane::~Pane`; IDA behavior indicates shared pane-base cleanup, so treat that generated base name as suspect.
- `class_OldUserStatusPane.cpp` currently contains literal `` `n`n`` text in the generated constructor body. This is a generated-data problem, not source evidence.
- Some item/inventory generated output still aliases `0x0069ae0c` as `g_pEffectObjImageLib`, `g_pLocalPlayer`, or raw `DAT_0069ae0c`. IDA evidence keeps the storage with [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md); consumer docs should describe the accessed field rather than adopting the wrong global owner.
- A 2026-05-27 IDA xref audit counted 67 direct xrefs to `dword_69AE0C` across 44 containing-function buckets. This breadth is expected because the active status-pane object exposes local player/status fields, including the inventory slot count at `+0x284`, to multiple UI and item-command subsystems.

## Cross-References

- [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md)
- [UID:0000FT][UserStatusPane2](by-class/UserStatusPane2.md)
- [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md)
- [UID:0000I4][CharacterSummaryRecord](by-file/CharacterSummaryRecord.md)
- [UID:0001WF][UserStatusPaneSummaryFields](by-type/by-struct/UserStatusPaneSummaryFields.md)
- [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md)
- [UID:0001RS][user-status-resources](by-resource/user-status-resources.md)
- [UID:0000OV][TotemFrame](by-file/TotemFrame.md)
- [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/80`. Summary/evidence: the page documents the status-HUD source family, likely classes, resources, globals, memory refs, and source-boundary notes, with remaining uncertainty around exact split and some generated global names.
- 2026-05-31: Assigned validator reconstruction path.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - After: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/"`.
  - Evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `UserStatusPane.cpp` under `ui/panels`; IDA evidence ties `UserStatusPane`, `UserStatusPane2`, and `OldUserStatusPane` to the status HUD family.
