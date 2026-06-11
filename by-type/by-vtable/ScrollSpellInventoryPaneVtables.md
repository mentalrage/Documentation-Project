*** UID:0001YS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000CN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrollSpellInventoryPane Vtables

## Status

- Entity kind: vtable cluster.
- Covered class: [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md).
- Likely source file: [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md), or final fold into [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md).
- Confidence: strong for vtable bases and installed slots.
- Autogen parent: [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md); final C++ stays blank because the page documents compiler-emitted vtable layout rather than source-ready declarations.

## Vtable Bases

| Class view | Base | Constructor store | Notes |
| --- | --- | --- | --- |
| primary | `0x00623e94` | `0x0055f4a1` | Installed at object offset `+0x00`. |
| secondary `+0xa0` | `0x00623ee0` | `0x0055f4a7` | Input/event view installed at object offset `+0xa0`. |
| tertiary `+0xa4` | `0x00623f10` | `0x0055f4b1` | Timer/update-handler view installed at object offset `+0xa4`. |

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| primary `0x00623e94` | `+0x44` | `0x0055f890` | `OnPaint`, drawing `SLIDEBG`/`SCRBUTT` scrollbar resources. |
| secondary `0x00623ee0` | `+0x04` | `0x0055f650` | Mouse input handler. |
| secondary `0x00623ee0` | `+0x08` | `0x0055f840` | Small false-return virtual adjacent to input/timer handlers. |
| secondary `0x00623ee0` | `+0x34` | `0x0055f850` | Timer/repeat handler. |
| tertiary `0x00623f10` | `+0x04` | `0x0055f850` | Same timer/repeat handler exposed through the tertiary view. |

Do not read past `tertiary +0x04` as `ScrollSpellInventoryPane` slots. The next dword at `0x00623f18` is RTTI metadata for the neighboring [UID:0001YR][ScrollNewGroupPaneVtables](by-type/by-vtable/ScrollNewGroupPaneVtables.md), not another spell-scrollbar virtual.

## Parent And Slot Rationale

[UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md) is the type parent because it is reconstructable, scored `80/80`, and already attached to [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md). The class page records the same constructor-installed primary, secondary, and tertiary views, the `0x110` object size, the spell-scrollbar method map, and the raw reset-helper caveat that caps final-source confidence.

This vtable page should not emit standalone C++. The source-level requirement is that the `ScrollSpellInventoryPane` class declaration and virtual method ordering regenerate these tables; exact C++ should wait for the broader spell-scrollbar versus `NewSpellInventoryPane` source split to settle.

## IDA MCP Evidence

- Constructor disassembly at `0x0055f4a1`, `0x0055f4a7`, and `0x0055f4b1` installs `0x00623e94`, `0x00623ee0`, and `0x00623f10`.
- `xrefs_to` each vtable base reports the matching constructor store as the direct data reference.
- IDA vtable dumping maps the primary paint slot to `0x0055f890`, the secondary mouse slot to `0x0055f650`, and the secondary/tertiary timer slots to `0x0055f850`.
- Current Wave3 metadata reports `vtable_count: 0`, so generated vtable inventory is incomplete despite the confirmed IDA symbols.

## Reconstruction Notes

Model this as the spell-inventory sibling of [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md). The layout is nearly identical, but caller evidence still keeps this source private to [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md) until reuse is proven.

## Changes

- 2026-05-31: Raised completion/confidence from `0/0` to `70/86` and marked the vtable cluster reconstructable.
  - Before: The page contained useful slot notes but was still scored unevaluated.
  - Changed to: Scored as strong-confidence vtable evidence while keeping completion below final audit because inherited pane-interface slot names and final source placement still need broader review.
  - Evidence: IDA MCP `xrefs_to` confirms direct constructor stores to `0x00623e94`, `0x00623ee0`, and `0x00623f10`; IDA slot mapping ties the class-specific paint, mouse, and timer callbacks to the listed function addresses.
- 2026-06-07: Raised completion from `70` to `74` and attached autogen parent [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md); confidence remains `86`.
  - Before: The page documented the vtable bases and slots but left `AUTOGEN_PARENT_UID` blank.
  - After: The page records the class parent, parent/slot rationale, and no-code policy for this compiler-emitted layout evidence.
  - Evidence: [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md) is reconstructable at `80/80`, attached to [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md), and records the same vtable bases, spell-scrollbar method map, raw reset-helper caveat, and possible fold into [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md).

## Cross-References

- [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md)
- [UID:0001W1][ScrollSpellInventoryPaneLayout](by-type/by-struct/ScrollSpellInventoryPaneLayout.md)
- [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md)
- [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md)
- [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md)
- [UID:0001YR][ScrollNewGroupPaneVtables](by-type/by-vtable/ScrollNewGroupPaneVtables.md)
