*** UID:0001YW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SpecializedButtonPane Vtables

## Status

- Confidence: strong for vtable addresses and class-specific slots, medium for inherited slot names.
- Likely owner: [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md)
- Related file doc: [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)
- Exact vtable-data children: [UID:0002OV][0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData](by-memory/0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData.md), [UID:0002OW][0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData](by-memory/0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData.md), and [UID:0002OX][0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData](by-memory/0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData.md).

## GenderButtonControlPane

| Vtable | Address | Key slots |
| --- | --- | --- |
| primary | `0x0061db90` | `+0x00 -> 0x00502700` scalar deleting destructor; `+0x44 -> 0x00500700` paint; `+0x48 -> 0x005006d0` state setter; `+0x68 -> 0x005024a0` secondary adjustor thunk. |
| secondary | `0x0061dbf8` | `+0x00 -> 0x005024a0` this-adjustor into scalar deleting destructor. |
| tertiary | `0x0061dc28` | `+0x00 -> 0x005024ab` this-adjustor into scalar deleting destructor. |

## DirectionButtonControlPane

| Vtable | Address | Key slots |
| --- | --- | --- |
| primary | `0x0061dc34` | `+0x00 -> 0x005026a0` scalar deleting destructor; `+0x44 -> 0x00500820` paint; `+0x48 -> 0x005007f0` state setter; `+0x68 -> 0x0050248a` secondary adjustor thunk. |
| secondary | `0x0061dc9c` | `+0x00 -> 0x0050248a` this-adjustor into scalar deleting destructor. |
| tertiary | `0x0061dccc` | `+0x00 -> 0x00502495` this-adjustor into scalar deleting destructor. |

## CheckBoxTextControlPane

| Vtable | Address | Key slots |
| --- | --- | --- |
| primary | `0x0062e99c` | `+0x00 -> 0x0059f050` scalar deleting destructor; `+0x44 -> 0x0059df50` paint; `+0x60 -> 0x004214c0` control-type helper; `+0x68 -> 0x0059efeb` secondary adjustor thunk. |
| secondary | `0x0062ea04` | `+0x00 -> 0x0059efeb` this-adjustor into scalar deleting destructor. |
| tertiary | `0x0062ea34` | `+0x00 -> 0x0059eff6` this-adjustor into scalar deleting destructor. |

## Evidence

- 2026-05-26 IDA MCP `py_eval` read the listed vtable dwords directly from the IDB.
- 2026-05-26 IDA MCP `xrefs_to` ties the primary vtables to inline constructor/setup writes in `NewUserMiscDialogPane` and `PartySearchEditPane`, plus scalar deleting destructor reset writes.
- 2026-05-26 IDA MCP `xrefs_to` confirms the adjustor thunk targets are vtable-only glue and code refs into the real scalar deleting destructors.
- 2026-06-01 IDA MCP `py_eval` confirms the exact `.rdata` child boundaries: `GenderButtonControlPane` occupies `0x0061db8c-0x0061dc30`, `DirectionButtonControlPane` occupies `0x0061dc30-0x0061dcd4`, and `CheckBoxTextControlPane` occupies `0x0062e998-0x0062ea3c`.

## Reconstruction Notes

The adjustor thunks are compiler-generated and are recorded in [UID:0000VN][-ignored](by-memory/-ignored.md). Final source should model normal multiple-inheritance vtable layout and scalar deleting destructors, not handwritten thunk functions.

## Cross-References

- [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md)
- [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)
- [UID:00005P][GenderButtonControlPane](by-class/GenderButtonControlPane.md)
- [UID:00003X][DirectionButtonControlPane](by-class/DirectionButtonControlPane.md)
- [UID:000022][CheckBoxTextControlPane](by-class/CheckBoxTextControlPane.md)
- [UID:0001A4][0x00500640-0x00502754.SpecializedButtonPanes](by-memory/0x00500640-0x00502754.SpecializedButtonPanes.md)
- [UID:0001KJ][0x0059ded0-0x0059f0a4.CheckBoxTextControlPane](by-memory/0x0059ded0-0x0059f0a4.CheckBoxTextControlPane.md)
- [UID:0002OV][0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData](by-memory/0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData.md)
- [UID:0002OW][0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData](by-memory/0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData.md)
- [UID:0002OX][0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData](by-memory/0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData.md)

## Changes

- What existed before: this page documented the specialized button/control-pane vtable addresses but remained scored as unevaluated and did not link exact by-memory child ranges for the concrete vtable-data clusters.
- What it was changed to: the page now marks the vtable set reconstructable, raises scores to reflect IDA-verified vtable/range evidence below the final-audit threshold, and links the exact `GenderButtonControlPane`, `DirectionButtonControlPane`, and `CheckBoxTextControlPane` child pages.
- Summary and evidence: 2026-06-01 IDA MCP `py_eval` verified the slot dwords, constructor/store xrefs, and neighboring RTTI-adjacent boundaries for all three child ranges.
