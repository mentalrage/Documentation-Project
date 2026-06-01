*** UID:0000I7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# CheckBoxControlPane

## Status

- Confidence: strong for class behavior; medium for standalone original file.
- Proposed module: `ui/controls/CheckBoxControlPane.cpp`, or folded into [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md).
- Current recovered source: `source-3/simroot_v2/class_CheckBoxControlPane.cpp`
- Exact core memory: [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md)
- Type/layout docs: [UID:0001TX][CheckBoxControlPaneLayout](by-type/by-struct/CheckBoxControlPaneLayout.md), [UID:0001X8][CheckBoxControlPaneVtables](by-type/by-vtable/CheckBoxControlPaneVtables.md)
- Exact vtable data: [UID:0002M9][0x006184d8-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d8-0x00618578.CheckBoxControlPaneVtableData.md)

## File Role

`CheckBoxControlPane.cpp` should own the toggleable checkbox control if final reconstruction splits common choice controls into smaller files. It stores checked state, toggles on mouse hit, notifies the owner, paints checked/unchecked frames from a tile/palette pair, and reports control type id `20`.

Confirmed consumers are cross-feature: [UID:0000LE][MiniMap](by-file/MiniMap.md) constructs NPC and portal toggle checkboxes and seeds their state from config bytes, while [UID:000096][NewMailDialog](by-class/NewMailDialog.md) constructs the "Keep a copy" checkbox and reads it while serializing outgoing mail.

## Boundary Notes

Current source-structure evidence favors [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) as the grouped generic button/choice-control module. Keep this page as the explicit split candidate so the proposed tree's `CheckBoxControlPane.cpp` name is not mistaken for an undocumented gap.

Current generated source caveats:

- `source-3/simroot_v2/class_CheckBoxControlPane.cpp` names the second copied string `labelName`, but IDA/caller evidence shows it is a palette/resource name such as `BUTTON.PAL`.
- The primary vtable references `0x00499ec0`, a real virtual state/type helper that active generated output omits from the class file.
- The exact vtable data child [UID:0002M9][0x006184d8-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d8-0x00618578.CheckBoxControlPaneVtableData.md) confirms all three table views, their constructor/destructor stores, and the next-class boundary at `0x00618578`.
- The disabled companion omits `0x0049af27` and only emits `0x0049af32`, but IDA confirms both as 0xb-byte compiler adjustor thunks into scalar deleting destructor `0x0049b110`. They are documented as [UID:00011Z][0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks](by-memory/0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks.md) and should not be migrated as handwritten source.
- The generated file declares `g_pEPFLib` locally because the paint path consumes it. Global ownership remains with [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / [UID:0000K2][ImageLib](by-file/ImageLib.md).

## Cross-References

- [UID:000021][CheckBoxControlPane](by-class/CheckBoxControlPane.md)
- [UID:0001TX][CheckBoxControlPaneLayout](by-type/by-struct/CheckBoxControlPaneLayout.md)
- [UID:0001X8][CheckBoxControlPaneVtables](by-type/by-vtable/CheckBoxControlPaneVtables.md)
- [UID:0002M9][0x006184d8-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d8-0x00618578.CheckBoxControlPaneVtableData.md)
- [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md)
- [UID:0000U7][CheckBoxControlPaneStateTypeHelper_00499EC0](by-item/CheckBoxControlPaneStateTypeHelper_00499EC0.md)
- [UID:00011Z][0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks](by-memory/0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks.md)
- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:78`.
  - Summary/evidence: checkbox behavior, consumers, memory/type/vtable anchors, resource/global caveats, and adjustor-thunk exclusions are documented; confidence is capped by the unresolved standalone-file versus `ButtonControlPane.cpp` grouping.

- 2026-05-31: Grading changed from `82/78` to `84/82`, and `PROPOSED_RECONSTRUCTION_PATH` was set to `NexusTK/ui/controls/`.
  - Before: the page named `ui/controls/CheckBoxControlPane.cpp` in prose but the validator-managed projected path was blank, and exact vtable storage was not split into its own by-memory child.
  - After: the page stages the split-candidate source path under `NexusTK/ui/controls/` and links [UID:0002M9][0x006184d8-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d8-0x00618578.CheckBoxControlPaneVtableData.md).
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `CheckBoxControlPane.cpp` under `ui/controls`, while noting the possible fold into `ButtonControlPane.cpp`; IDA MCP checks on 2026-05-31 verify the exact vtable data and generated-source omissions.
