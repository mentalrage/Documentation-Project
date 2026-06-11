*** UID:0000OH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# TargetSelectionInputPanes

## Status

- Confidence: strong for pane behavior, code boundaries, shared saved-target globals, and direct `ui/dialogs/` placement; medium-high for the final original `.cpp` split.
- Candidate file: `ui/dialogs/TargetSelectionInputPanes.cpp`
- Alternative placement: private target-input code split across [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md), spell input panes, and a small protocol helper source.
- Current generated sources: `source-3/simroot_v2/class_SpellWhoInputPane.cpp`, `class_ItemWhoInputPane.cpp`, `class_SelectObjectWithKeyboardPane.cpp`, `class_TargetObjectWithKeyboardPane.cpp`, `class_ItemWhoInputPaneState.cpp`, and `class_SpellInputPaneState.cpp`.
- Primary memory docs: [UID:0001L8][0x005af390-0x005b050d.TargetSelectionInputPanes](by-memory/0x005af390-0x005b050d.TargetSelectionInputPanes.md), [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md), and [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md).

## File Role

This module candidate covers the target-selection line-input panes that let the player choose a map object with the keyboard, mouse, or typed name before sending a target-dependent item/spell/action packet.

The code shares the same visible shape:

- [UID:000077][LineInputPane](by-class/LineInputPane.md) base construction with prompt text.
- `MapPane` lookup by object id or screen point.
- `LivingObjectPane` highlight/selection toggles.
- module-scope current-target globals [UID:0002AB][0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals](by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md), covering `dword_69BF20`, `dword_69BF24`, `dword_69BF28`, `dword_69BF2C`, and the prior/alternate target slot `dword_69BF30`.
- singleton pointers for the active selection panes [UID:0002A2][0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots](by-memory/0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots.md) at `dword_69BF60` and `dword_69BF64`.

## Proposed Contents

| Entity | Address evidence | Current generated file | Role |
| --- | --- | --- | --- |
| [UID:0000DX][SpellWhoInputPane](by-class/SpellWhoInputPane.md) | [UID:0001KY][0x005ae2a0-0x005aeb1f.SpellWhoInputPane](by-memory/0x005ae2a0-0x005aeb1f.SpellWhoInputPane.md), [UID:0001NA][0x005b78fc-0x005b7912.SpellWhoInputPaneAdjustorThunks](by-memory/0x005b78fc-0x005b7912.SpellWhoInputPaneAdjustorThunks.md), [UID:0001NK][0x005b8100-0x005b81c4.SpellWhoInputPaneScalarDeletingDestructor](by-memory/0x005b8100-0x005b81c4.SpellWhoInputPaneScalarDeletingDestructor.md) | `class_SpellWhoInputPane.cpp`, plus recovered `DeactivateSavedSpellWhoTarget_005AEB00.cpp` | Spell-target prompt that accepts keyboard/mouse selected living-object targets. |
| [UID:00006X][ItemWhoInputPane](by-class/ItemWhoInputPane.md) | [UID:0001L4][0x005aec60-0x005af2e7.ItemWhoInputPane](by-memory/0x005aec60-0x005af2e7.ItemWhoInputPane.md), [UID:0002S1][0x005aec60-0x005aed3d.ItemWhoInputPaneConstructor](by-memory/0x005aec60-0x005aed3d.ItemWhoInputPaneConstructor.md), [UID:0002S2][0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput](by-memory/0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput.md), [UID:0002S3][0x005af050-0x005af2e7.ItemWhoInputPaneMouseInput](by-memory/0x005af050-0x005af2e7.ItemWhoInputPaneMouseInput.md), and [UID:0002S4][0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor](by-memory/0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor.md) | `class_ItemWhoInputPane.cpp` plus missing active helper owners | Use-on-target prompt that accepts typed or mouse-selected targets. |
| saved target globals | [UID:0002AB][0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals](by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md) | static data | Five contiguous dwords storing saved spell/item/select/target object ids plus the prior/alternate target-dispatch id. |
| keyboard selector singleton globals | [UID:0002A2][0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots](by-memory/0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots.md) | static data | Two contiguous dwords storing the active `SelectObjectWithKeyboardPane` and `TargetObjectWithKeyboardPane` singleton pointers maintained by their constructors, destructors, clear helpers, and scalar deleting destructors. |
| `ItemWhoInputPane` non-deleting destructor | [UID:0001L5][0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor](by-memory/0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor.md) | missing active owner | Restores target-input state and calls base cleanup. |
| `ItemWhoInputPane` object-list virtual | [UID:0001L6][0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual](by-memory/0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual.md) | missing active owner | Handles underscore-prefixed object-list payloads for saved item target state. |
| `ClearItemWhoTarget` | [UID:0001L7][0x005af390-0x005af3af.ClearItemWhoTarget](by-memory/0x005af390-0x005af3af.ClearItemWhoTarget.md) | generated as `DeactivateSavedItemWhoTarget_005AF390.cpp` | Clears highlight for the saved item target id `dword_69BF24`; direct callers are `ItemWhoInputPane` key/mouse handlers. |
| `ItemWhoTargetNavigationRawHelpers` | [UID:0002S5][0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers](by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md) | missing active owner | Three source-authored raw helper bodies that update saved item-target state, traverse map objects, and retarget to the local player. |
| `SendTargetedActionPacket` | [UID:0001L9][0x005af4f0-0x005af57b.SendTargetedActionPacket](by-memory/0x005af4f0-0x005af57b.SendTargetedActionPacket.md) | no stable class owner | Builds and sends opcode `0x0f` with action byte, object id, and two short arguments. |
| `SendObjectActionPacket` | [UID:0001LA][0x005af580-0x005af5ea.SendObjectActionPacket](by-memory/0x005af580-0x005af5ea.SendObjectActionPacket.md) | no stable class owner | Builds and sends opcode `0x1c` with action byte and object id. |
| shared MapPane hit test | [UID:0001AU][0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane](by-memory/0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md) | generated under `class_BackPane.cpp` | Shared point-to-map-object helper used by spell/item/object target mouse handlers; caller evidence points away from BackPane. |
| [UID:0000CT][SelectObjectWithKeyboardPane](by-class/SelectObjectWithKeyboardPane.md) | [UID:0001L8][0x005af390-0x005b050d.TargetSelectionInputPanes](by-memory/0x005af390-0x005b050d.TargetSelectionInputPanes.md), destructor island [UID:0001N8][0x005b7862-0x005b7878.SelectObjectWithKeyboardPaneAdjustorThunks](by-memory/0x005b7862-0x005b7878.SelectObjectWithKeyboardPaneAdjustorThunks.md) | `class_SelectObjectWithKeyboardPane.cpp` | Generic keyboard/mouse object selector; Enter interacts with the selected object. |
| [UID:0000ED][TargetObjectWithKeyboardPane](by-class/TargetObjectWithKeyboardPane.md) | [UID:0001L8][0x005af390-0x005b050d.TargetSelectionInputPanes](by-memory/0x005af390-0x005b050d.TargetSelectionInputPanes.md), pending helper suffix `0x005b0510-0x005b077a`, destructor island [UID:0001NB][0x005b7912-0x005b7928.TargetObjectWithKeyboardPaneAdjustorThunks](by-memory/0x005b7912-0x005b7928.TargetObjectWithKeyboardPaneAdjustorThunks.md) | `class_TargetObjectWithKeyboardPane.cpp` | Target-selection pane that confirms with `v`, tracks the target-dispatch saved object id, owns clear/list/navigation/forward helpers after the mouse method, and feeds the target dispatch/overlay flow. |
| [UID:0000DM][SpellInputPaneState](by-class/SpellInputPaneState.md) | `0x0057c430-0x0057c43f` | `class_SpellInputPaneState.cpp` | Small shared state helper that writes an input-mode flag at offset `+0xfa`. |
| [UID:00006Y][ItemWhoInputPaneState](by-class/ItemWhoInputPaneState.md) | `0x0057d0a0-0x0057d0af` | `class_ItemWhoInputPaneState.cpp` | Item-target equivalent of the state flag helper. |

## Boundary Notes

- IDA MCP confirms `0x005af390`, `0x005af4f0`, `0x005af580`, `0x005af5f0`, `0x005af6e0`, `0x005af710`, `0x005afa10`, `0x005afc90`, `0x005afd30`, `0x005afe70`, `0x005afef0`, `0x005affe0`, `0x005b0010`, and `0x005b0290` as real functions. Exact end-exclusive boundaries are recorded in the linked `by-memory` pages.
- IDA MCP also confirms the spell-side target functions at `0x005ae2a0`, `0x005ae380`, `0x005ae410`, `0x005ae730`, `0x005aea60`, and `0x005aeb00`.
- IDA MCP recheck on 2026-05-26 confirms ItemWho target helpers `0x005aed40` and `0x005af2f0`; `0x005af2f0` is reached through a vtable data xref rather than direct callers.
- `0x005af3b0`, `0x005af430`, and `0x005af4b0` are not currently IDA functions, but 2026-06-02 raw-byte disassembly confirms source-authored target-navigation helpers in [UID:0002S5][0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers](by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md). Keep the `0x005af390` clear helper as an exact small helper, not a broad range extending through this raw island.
- `0x005ae690` is not currently an IDA function; keep the `SpellWhoInputPane` key and pointer handlers separate.
- `0x005af4f0` has callers in spell, item, and living-object target flows. `0x005af580` has callers in item/object target flows. They should stay near this module but may eventually move to a `ClientCommandPackets.cpp`-style protocol helper if packet helpers are centralized.
- `0x00506ce0` has callers at `0x005ae8b2`, `0x005af1b5`, `0x005afb51`, and `0x005b03d1`, covering spell, item, select-object, and target-object mouse selection. Keep it visible to this module even though current generated output names it `BackPane::HitTestMapPane`.
- `0x005af6e0` and `0x005affe0` are non-deleting destructors that reset the corresponding singleton globals and call the shared `LineInputPane` cleanup helper. Generated active output currently omits them.
- `0x005afc90` is a `SelectObjectWithKeyboardPane` vtable helper that parses underscore-prefixed object lists and falls back to the local player if the current target disappears from the list.
- 2026-06-06 A007 IDA MCP refresh confirms `TargetObjectWithKeyboardPane` has an analogous post-mouse helper suffix at `0x005b0510-0x005b077a`: object-list helper `sub_5B0510`, clear-current-target helper `sub_5B05B0`, target-dispatch forward helper `sub_5B06F0`, and an unmodeled raw navigation island at `0x005b05d0-0x005b06ef`.
- The raw target-object helper island contains three source-authored bodies that traverse previous/up via `sub_506AE0`, traverse next/down via `sub_506B30`, or retarget to the local player, updating `dword_69BF2C` and target highlights. IDA does not currently model starts at `0x005b05d0`, `0x005b0640`, or `0x005b06b0`.
- 2026-06-07 Batch 058 confirms [UID:0002AB][0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals](by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md) as an exact five-dword static-data child. The first four slots map to the four target-selection pane classes, and `dword_69BF30` is copied/reset by target-dispatch navigation helpers at `0x005ad500`, `0x005ad660`, and `0x005b06f0`.
- 2026-06-07 A005 Batch 059 confirms [UID:0002A2][0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots](by-memory/0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots.md) as the exact two-dword singleton child at `0x0069bf60-0x0069bf68`. `dword_69BF60` belongs to the active `SelectObjectWithKeyboardPane`, `dword_69BF64` belongs to the active `TargetObjectWithKeyboardPane`, and the range remains one file-owned static-data child because the shared source module directly owns both declarations.
- Keep the existing [UID:0001L8][0x005af390-0x005b050d.TargetSelectionInputPanes](by-memory/0x005af390-0x005b050d.TargetSelectionInputPanes.md) aggregate boundary unchanged until exact by-memory pages are created for `0x005b0510-0x005b077a`; the pending suffix should not be silently folded into the older aggregate without validator/coverage updates.
- Disabled generated rows for `0x005b786d` and `0x005b791d` say "missing code", but IDA decompiles both as real adjustor thunks to the scalar deleting destructors. The full thunk ranges `0x005b7862-0x005b7878` and `0x005b7912-0x005b7928` are tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).
- 2026-05-26 IDA MCP recheck confirmed `lookup_funcs`, `decompile`, `xrefs_to`, and empty ordinary caller lists for those two thunk pairs. Keep the scalar deleting destructors reconstructable and exclude only the `this`-adjusting wrappers.
- Disabled generated row `0x005b7907` says "missing code", but IDA decompiles it as the second `SpellWhoInputPane` adjustor thunk to `0x005b8100`. The full thunk range `0x005b78fc-0x005b7912` is tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).

## Placement Notes

The strongest source-layout hypothesis is a small target-selection module adjacent to the item and spell input panes:

```text
ui/dialogs/TargetSelectionInputPanes.cpp
ui/dialogs/TargetSelectionInputPanes.h
```

If final reconstruction prefers fewer input sources, this code can fold into a broader `CommandInputPanes.cpp` or split spell-specific target input into a spell input source, but it should not remain as one generated file per class. The shared target-id globals, common map-object traversal, and packet helpers make the classes a coherent input family.

Do not run Wave3 migration commands for this module while `wave3-status.md` is marked `DEBUGGING`.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0000DX][SpellWhoInputPane](by-class/SpellWhoInputPane.md)
- [UID:00006X][ItemWhoInputPane](by-class/ItemWhoInputPane.md)
- [UID:0000CT][SelectObjectWithKeyboardPane](by-class/SelectObjectWithKeyboardPane.md)
- [UID:0000ED][TargetObjectWithKeyboardPane](by-class/TargetObjectWithKeyboardPane.md)
- [UID:0000DM][SpellInputPaneState](by-class/SpellInputPaneState.md)
- [UID:00006Y][ItemWhoInputPaneState](by-class/ItemWhoInputPaneState.md)
- [UID:0001KY][0x005ae2a0-0x005aeb1f.SpellWhoInputPane](by-memory/0x005ae2a0-0x005aeb1f.SpellWhoInputPane.md)
- [UID:0001L3][0x005aeb00-0x005aeb1f.DeactivateSavedSpellWhoTarget](by-memory/0x005aeb00-0x005aeb1f.DeactivateSavedSpellWhoTarget.md)
- [UID:0001L4][0x005aec60-0x005af2e7.ItemWhoInputPane](by-memory/0x005aec60-0x005af2e7.ItemWhoInputPane.md)
- [UID:0001L5][0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor](by-memory/0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor.md)
- [UID:0001L6][0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual](by-memory/0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual.md)
- [UID:0002AB][0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals](by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md)
- [UID:0002A2][0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots](by-memory/0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots.md)
- [UID:0001L8][0x005af390-0x005b050d.TargetSelectionInputPanes](by-memory/0x005af390-0x005b050d.TargetSelectionInputPanes.md)
- [UID:0002S5][0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers](by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md)
- [UID:0001AU][0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane](by-memory/0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md)
- [UID:0001L9][0x005af4f0-0x005af57b.SendTargetedActionPacket](by-memory/0x005af4f0-0x005af57b.SendTargetedActionPacket.md)
- [UID:0001LA][0x005af580-0x005af5ea.SendObjectActionPacket](by-memory/0x005af580-0x005af5ea.SendObjectActionPacket.md)

## Changes

- 2026-06-07 A005 Batch 059 singleton-child assignment:
  - Before: [UID:0002A2][0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots](by-memory/0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots.md) documented `0x0069bf60-0x0069bf68` as target-selection singleton slots but had no autogen parent.
  - After: [UID:0002A2][0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots](by-memory/0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots.md) is assigned to this file as a direct static-data child. File scores remain `89/85`; this was a routing/evidence refresh, not a full file rescore.
  - Evidence: IDA data xrefs tie `dword_69BF60` and `dword_69BF64` to the two keyboard target-selector constructors/destructors and helper clears, while this file already owns both classes and the adjacent saved-target globals under the corrected `85/85` gate.
- 2026-06-07 Batch 058 parent-gate refresh:
  - Before: `COMPLETION:88`, `CONFIDENCE:80`.
  - After: `COMPLETION:89`, `CONFIDENCE:85`.
  - Evidence: attached [UID:0002AB][0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals](by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md), covering all five saved-target dwords and the `dword_69BF30` target-dispatch navigation dataflow. The page still notes final `.cpp` split uncertainty, but the direct parent gate is now met for the shared static-data child.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `88` and confidence to `80`.
  - Evidence: document covers target-selection module role, shared globals, proposed contents across spell/item/object panes, packet helpers, MapPane hit-test dependency, IDA boundary notes, placement guidance, thunk handling, and cross-references; confidence remains capped by final `.cpp` split.
- 2026-06-06 A007 target-object helper suffix inventory:
  - Before: `TargetObjectWithKeyboardPane` file-level evidence only pointed at the older `0x005af390-0x005b050d` aggregate, method pages, and destructor islands.
  - After: recorded the verified `0x005b0510-0x005b077a` helper suffix, including modeled object-list/clear/forward helpers and the unmodeled navigation raw island, without creating new UIDs while validator/generated coverage files are leased.
  - Evidence: live IDA MCP `lookup_funcs`, `xrefs_to`, decompilation, bounded raw disassembly, and byte checks collected for the class page. Scores remain `88/80` until the exact split pages and generated reference updates are available.
