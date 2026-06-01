*** UID:0001YQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrollInventoryPane Vtables

## Status

- Entity kind: vtable cluster.
- Covered class: [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md).
- Likely source file: [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md), or final fold into [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md).
- Confidence: strong for vtable bases and installed slots.

## Vtable Bases

| Class view | Base | Constructor store | Notes |
| --- | --- | --- | --- |
| primary | `0x0062402c` | `0x005632b1` | Installed at object offset `+0x00`. |
| secondary `+0xa0` | `0x00624078` | `0x005632b7` | Input/event view installed at object offset `+0xa0`. |
| tertiary `+0xa4` | `0x006240a8` | `0x005632c1` | Timer/update-handler view installed at object offset `+0xa4`. |

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| primary `0x0062402c` | `+0x44` | `0x005636a0` | `OnPaint`, drawing `SLIDEBG`/`SCRBUTT` scrollbar resources. |
| secondary `0x00624078` | `+0x04` | `0x00563460` | Mouse input handler. |
| secondary `0x00624078` | `+0x08` | `0x00563650` | Small false-return virtual adjacent to input/timer handlers. |
| secondary `0x00624078` | `+0x34` | `0x00563660` | Timer/auto-repeat handler. |
| tertiary `0x006240a8` | `+0x04` | `0x00563660` | Same timer/auto-repeat handler exposed through the tertiary view. |

Do not read past `tertiary +0x04` as `ScrollInventoryPane` slots. The next dword at `0x006240b0` is RTTI metadata for the neighboring [UID:0001YT][ScrollVolumePaneVtables](by-type/by-vtable/ScrollVolumePaneVtables.md), not another item-scrollbar virtual.

## IDA MCP Evidence

- Constructor disassembly at `0x005632b1`, `0x005632b7`, and `0x005632c1` installs `0x0062402c`, `0x00624078`, and `0x006240a8`.
- `xrefs_to` each vtable base reports the matching constructor store as the direct data reference.
- IDA vtable dumping maps the primary paint slot to `0x005636a0`, the secondary mouse slot to `0x00563460`, and the secondary/tertiary timer slots to `0x00563660`.
- Current Wave3 metadata reports `vtable_count: 0`, so generated vtable inventory is incomplete despite the confirmed IDA symbols.

## Reconstruction Notes

Model this as the item-inventory instance of the custom inventory scrollbar control. The table layout matches the spell and volume scrollbar siblings, but constructor caller evidence still keeps this source private to [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md) until reuse is proven.

## Changes

- 2026-05-31: Raised completion/confidence from `0/0` to `70/86` and marked the vtable cluster reconstructable.
  - Before: The page contained useful slot notes but was still scored unevaluated.
  - Changed to: Scored as strong-confidence vtable evidence while keeping completion below final audit because inherited pane-interface slot names and final source placement still need broader review.
  - Evidence: IDA MCP `xrefs_to` confirms direct constructor stores to `0x0062402c`, `0x00624078`, and `0x006240a8`; IDA slot mapping ties the class-specific paint, mouse, and timer callbacks to the listed function addresses.

## Cross-References

- [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md)
- [UID:0001W0][ScrollInventoryPaneLayout](by-type/by-struct/ScrollInventoryPaneLayout.md)
- [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md)
- [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md)
- [UID:0001YS][ScrollSpellInventoryPaneVtables](by-type/by-vtable/ScrollSpellInventoryPaneVtables.md)
- [UID:0001YT][ScrollVolumePaneVtables](by-type/by-vtable/ScrollVolumePaneVtables.md)
