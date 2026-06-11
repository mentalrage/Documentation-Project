*** UID:0000P2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# UserStatusPane

## Status

- Confidence: strong for class grouping, UI role, `ui/panels/` placement, and direct ownership of the newer `UserStatusPane` class; medium-high for the final split between one source file and small companion files.
- Proposed module: `ui/panels/UserStatusPane.cpp`
- Proposed header: `ui/panels/UserStatusPane.h`
- Current recovered sources: `source-3/simroot_v2/class_UserStatusPane.cpp`, `class_UserStatusPane2.cpp`, and `class_OldUserStatusPane.cpp`.

## File Role

`UserStatusPane.cpp` should own the local player status HUD panes. The code supports both the newer/high-resolution layout and the older compact/legacy layout selected through [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97`; some generated code emitted this same global as `g_uiLayoutMode`.

The strongest source-layout evidence is `InitializeMainUiGraph` at `0x004f7d10`: in the newer layout it constructs both `UserStatusPane` and `UserStatusPane2`; in the older layout it constructs `OldUserStatusPane`. All three load the same `9X11FONT.BIN` numeric glyph table and share status-field update patterns, icon ids, resource families, and destructor thunk layout.

For the corrected parent gate, this file is now strong enough to act as the direct parent for [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md): the class page is `88/88`, this file is `88/85`, and the class is one of the named top-level contents of this source module. This file confidence update does not by itself make every related child eligible; lower-scored children still need their own `85/85` checks.

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
- 2026-06-07 A005 Batch 059 parent-gate recheck used the already documented class and memory evidence to raise confidence from `80` to `85`: [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md) is `88/88`, [UID:0000FT][UserStatusPane2](by-class/UserStatusPane2.md) is `86/88`, [UID:0001NM][0x005b83b0-0x005baafe.UserStatusPane](by-memory/0x005b83b0-0x005baafe.UserStatusPane.md) independently records the 21-function newer status-pane inventory at `88` confidence, and the sibling class docs agree on the shared `InitializeMainUiGraph`, singleton, resource, and status-payload family evidence. Remaining uncertainty now caps final-source completeness, not the direct file ownership of the newer `UserStatusPane` class.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 88 | The page identifies the status-HUD source family, three pane variants, resource/global/type dependencies, method-family anchors, generated-output caveats, and source-boundary exclusions. It stays below 95 because several large methods and the final one-file-versus-companion split are not source-final. |
| Confidence | 85 | The direct `UserStatusPane.cpp` file ownership is now supported by class pages, memory aggregates, singleton/global docs, resource docs, and UI-construction evidence. Confidence remains at the threshold, not higher, because `OldUserStatusPane` still has lower confidence and some generated output remains incomplete or malformed. |

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
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)

## Changes

- 2026-06-07 A005 Batch 059 parent-gate repair:
  - Before: `COMPLETION:88`, `CONFIDENCE:80`.
  - After: `COMPLETION:88`, `CONFIDENCE:85`.
  - Evidence: rechecked the direct source-file ownership evidence for [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md), including the `88/88` class page, `88`-confidence executable aggregate, `InitializeMainUiGraph` construction sites, shared status resources, singleton globals, and sibling `UserStatusPane2` family documentation. This enables the `UserStatusPane` class parent route while leaving lower-scored children subject to their own gates.
- 2026-06-07 A008 alias cleanup: normalized the layout-mode `byte_66DA97` / `g_uiLayoutMode` wording to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), preserving `byte_66DA97` as the IDA lookup alias.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/80`. Summary/evidence: the page documents the status-HUD source family, likely classes, resources, globals, memory refs, and source-boundary notes, with remaining uncertainty around exact split and some generated global names.
- 2026-05-31: Assigned validator reconstruction path.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - After: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/"`.
  - Evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `UserStatusPane.cpp` under `ui/panels`; IDA evidence ties `UserStatusPane`, `UserStatusPane2`, and `OldUserStatusPane` to the status HUD family.
