*** UID:0001YT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrollVolumePane Vtables

## Status

- Entity kind: vtable cluster.
- Covered class: [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md).
- Likely source file: [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md).
- Confidence: strong for vtable bases and installed slots.

## Vtable Bases

| Class view | Base | Constructor evidence | Notes |
| --- | --- | --- | --- |
| primary | `0x006240b4` | `0x00564761` | Installed at object offset `+0x00`. |
| secondary `+0xa0` | `0x00624100` | `0x00564767` | Secondary pane/event view installed at object offset `+0xa0`. |
| tertiary `+0xa4` | `0x00624130` | `0x00564771` | Timer/update-handler style view installed at object offset `+0xa4`. |

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| primary `0x006240b4` | `+0x44` | `0x00564b50` | `OnPaint`, drawing the volume slider track/thumb. |
| secondary `0x00624100` | `+0x04` | `0x00564910` | Mouse input handler. |
| secondary `0x00624100` | `+0x08` | `0x00564b00` | False-return `IsScrollable` virtual. |
| secondary `0x00624100` | `+0x34` | `0x00564b10` | Focus-loss/commit helper exposed as an event/update slot. |
| tertiary `0x00624130` | `+0x04` | `0x00564b10` | Same focus-loss/commit helper through the tertiary view. |

Do not read past `tertiary +0x04` as `ScrollVolumePane` slots. The following dwords are unrelated data, not part of the vtable.

The adjacent `0x005654ec` and `0x005654f7` thunks are not evidence for a `ScrollVolumePane` destructor. Current memory docs keep those thunks with [UID:0001H6][0x005654ec-0x00565608.ScrollablePaneVirtualDefaults](by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md) because they forward into `ScrollablePane::ScalarDeletingDestructor` at `0x00565510`; the canonical `ScrollablePaneVirtualDefaults` range now starts at `0x005654ec`.

## Evidence Notes

- Constructor disassembly at `0x00564761`, `0x00564767`, and `0x00564771` installs `0x006240b4`, `0x00624100`, and `0x00624130`.
- `xrefs_to` each vtable base reports the matching constructor store as the direct data reference.
- IDA vtable dumping maps the primary paint slot to `0x00564b50`, the secondary mouse slot to `0x00564910`, and the secondary/tertiary commit slot to `0x00564b10`.
- Current Wave3 metadata reports `vtable_count: 0`, so generated vtable inventory is incomplete despite the confirmed IDA symbols.

## Reconstruction Notes

Model `ScrollVolumePane` as a `Pane`-derived control with primary, secondary, and tertiary views at `+0x00`, `+0xa0`, and `+0xa4`. Keep the source in `ui/controls/ScrollVolumePane.cpp`; the vtable cluster strengthens class layout evidence but does not move option-policy callbacks into the slider source.

## Cross-References

- [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md)
- [UID:0001W2][ScrollVolumePaneLayout](by-type/by-struct/ScrollVolumePaneLayout.md)
- [UID:0001H2][0x00564710-0x005654ec.ScrollVolumePane](by-memory/0x00564710-0x005654ec.ScrollVolumePane.md)
- [UID:0001H3][0x00564e30-0x00565006.ScrollVolumePaneHitTestPart](by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md)
- [UID:0002LB][0x00565170-0x005651e0.ScrollVolumePaneSetHighlightPartRaw](by-memory/0x00565170-0x005651e0.ScrollVolumePaneSetHighlightPartRaw.md)
- [UID:0002LC][0x005651e0-0x005652a0.ScrollVolumePaneBeginInteractionRaw](by-memory/0x005651e0-0x005652a0.ScrollVolumePaneBeginInteractionRaw.md)
- [UID:0001H4][0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction](by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md)
- [UID:0001H5][0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange](by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md)
- [UID:0002LD][0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw](by-memory/0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw.md)
- [UID:0001H6][0x005654ec-0x00565608.ScrollablePaneVirtualDefaults](by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md)
- [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md)

## Changes

- 2026-05-31: Changed completion/confidence from `0/0` to `70/86` and marked the vtable cluster reconstructable.
  - Before: The page had IDA vtable evidence but ungraded validator metadata and no links to the newly split raw helper pages.
  - After: The page records the verified vtable state as reconstructable type data while keeping source reconstruction code blank below the 95+ gate.
  - Evidence: Constructor stores at `0x00564761`, `0x00564767`, and `0x00564771`, xrefs to `0x006240b4`, `0x00624100`, and `0x00624130`, and the current split `ScrollVolumePane` memory pages.
