*** UID:00031W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MerchantDialogPane Vtables

## Status

- Entity kind: compiler-generated MSVC vtable/COL evidence index.
- Canonical owner/emitter: `NONE`; this page is false/non-emitting because no source-authored table or wrapper belongs in generated C++.
- Source causes: [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md) declares the class and [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md) is its source root.
- Covered class: [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md).
- Mixed-family master: [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md).
- IDA evidence basis: B001-008 live IDA MCP `py_eval` on 2026-06-10 against `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`, refreshed by B006 accepted-report implementation against constructor child [UID:00041Q][0x00517d30-0x00517d74.MerchantDialogPaneConstructor](by-memory/0x00517d30-0x00517d74.MerchantDialogPaneConstructor.md).

## Binary Evidence

| View | Vtable base | Complete-object locator | Store/xref evidence |
| --- | --- | --- | --- |
| primary | `0x0061ec10` `??_7MerchantDialogPane@@6B@` | `0x0061ec0c -> 0x0064b774` `??_R4MerchantDialogPane@@6B@` | raw constructor-shaped code at `0x00517d53`. |
| secondary | `0x0061ec70` `??_7MerchantDialogPane@@6B@_0` | `0x0061ec6c -> 0x0064b7d4` `??_R4MerchantDialogPane@@6B@_0` | raw constructor-shaped code at `0x00517d59`. |
| tertiary | `0x0061eca0` `??_7MerchantDialogPane@@6B@_1` | `0x0061ec9c -> 0x0064b7e8` `??_R4MerchantDialogPane@@6B@_1` | raw constructor-shaped code at `0x00517d63`. |

The secondary EventHandler view slot `+0x10`, cell `0x0061ec80`, contains `0x00517d80`, the source method `MerchantDialogPane::HandlePacketEvent(Event*)`. IDA reports eight data refs to that function from the merchant/text/item/spell/argumented dialog-family secondary tables; the owner cell plus seven inherited derived cells describe one base source method.

## Canonical EventHandler Slot Order

The secondary table follows the established [UID:00004N][EventHandler](by-class/EventHandler.md) interface order:

| Secondary offset | Source contract | Merchant disposition |
| --- | --- | --- |
| `+0x00` | virtual destructor/deleting-wrapper slot | Compiler-generated adjusted destruction. |
| `+0x04` | `HandlePointerOrMouseEvent(Event*)` | Inherited/default event-family behavior. |
| `+0x08` | `HandleKeyOrTextEvent(Event*)` | Inherited/default event-family behavior. |
| `+0x0c` | `HandleImeEvent(Event*)` | Inherited/default event-family behavior. |
| `+0x10` | `HandlePacketEvent(Event*)` | Cell `0x0061ec80 -> 0x00517d80`, exact source child UID0001BM. |
| `+0x14` | `HandleSystemOrControlEvent(Event*)` | Inherited/default event-family behavior. |
| `+0x18` | `HandleType19Event(Event*)` | Inherited/default event-family behavior. |
| `+0x1c..+0x28` | forwarding, pair-output, and acceptance defaults | Inherited EventHandler support; no Merchant-specific source body. |

The complete object contains this secondary view at `+0xa0`; the timer-handler view begins at `+0xa4`. The raw machine entry receives the secondary facet in ECX and does not use it, while source declares the ordinary complete-class virtual without handwritten adjustment.

2026-06-16 A001 live IDA/PE refresh reconfirmed the raw constructor store refs at `0x00517d53`, `0x00517d59`, and `0x00517d63`, the eight vtable-only refs to `0x00517d80`, no direct xrefs or PE pointer/branch hits to the raw constructor start `0x00517d30`, and no direct branches to `0x00517d80`.

2026-06-25 B006 accepted-report implementation records the constructor-store refs on exact child [UID:00041Q][0x00517d30-0x00517d74.MerchantDialogPaneConstructor](by-memory/0x00517d30-0x00517d74.MerchantDialogPaneConstructor.md). The child owns the formal constructor source; this vtable page remains the owner-specific generated-binary layout support and must not hand-port vtable bytes into C++.

## Ownership Inference

The `MerchantDialogPane` class is the human source cause, not the full merchant menu vtable family or only the file root, but this grouped vtable/COL evidence has no separate source-authored semantic owner. IDA ties all three table writes to exact constructor child [UID:00041Q][0x00517d30-0x00517d74.MerchantDialogPaneConstructor](by-memory/0x00517d30-0x00517d74.MerchantDialogPaneConstructor.md), while the broad parent [UID:0001BL][0x00517d30-0x00517ebf.MerchantDialogPaneBase](by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md) is now only a non-emitting split container. The shared virtual at `0x00517d80` is documented as [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md). UID000083 and its exact children emit the class declaration and ordinary methods through [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md); UID00031W itself does not emit.

## Assignment Gate

| Candidate parent | Gate result | Reason |
| --- | --- | --- |
| [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md) | source cause only | The class page owns the declaration and ordinary methods that cause the compiler to regenerate these three vtable views; it is not an owner/emitter for the compiler-only grouped page. |
| [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md) | source root only | The file root receives UID000083 and exact method children, not UID00031W raw vtable output. |
| [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) | rejected | Mixed inventory over five source owners, not the direct source owner for this class. |
| [UID:00025U][0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData](by-memory/0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md) | rejected | Contiguous `.rdata` aggregate crosses menu, input, object-image, and string owners. |

## Reconstruction Notes

Reconstruct these vtables through the `MerchantDialogPane` class declaration, inheritance shape, constructor, implicit/virtual destruction, and `HandlePacketEvent(Event*)` declaration. Do not hand-port raw table bytes, RTTI, deleting wrappers, or secondary-this adjustment into C++. Both formal channels remain blank and UID00031W is false/non-emitting because UID000083 H declares the class and exact source children define ordinary methods.

The former generic action-string-virtual name and unresolved wrapper/type caveat are preserved as historical naming states. Canonical Event/EventHandler evidence now fixes the slot and source signature; it does not alter the exact three table bases, COL cells, constructor stores, no-direct-caller evidence, inherited data refs, or broad-family rejection.

## Score Rationale

- Completion `91`: exact owner-specific table bases/COL cells/store sites, complete-object offsets, canonical EventHandler order, packet slot identity, method child, eight inherited refs, compiler/source boundary, and owner/emitter route are documented.
- Confidence `94`: decorated RTTI/vtable evidence, constructor stores, EventHandler contract, and exact method body agree. Original lexical spellings outside the canonical interface and physical source packaging remain bounded inferences.

## Cross-References

- [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md)
- [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0001BL][0x00517d30-0x00517ebf.MerchantDialogPaneBase](by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md)
- [UID:00041Q][0x00517d30-0x00517d74.MerchantDialogPaneConstructor](by-memory/0x00517d30-0x00517d74.MerchantDialogPaneConstructor.md)
- [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md)

## Changes

- 2026-08-22 B002 UID0000OP Gate 2A empty-emitter closure:
  - Corrected UID00031W from class-routed reconstructable/empty CPP to `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and blank `EMITTER_UIDS`.
  - Preserved all three vtable/COL/store identities and the UID000083 source-cause relationship; no raw vtable, RTTI, deleting wrapper, or thunk body is emitted.
- 2026-07-26 B002 accepted UID0001BM implementation callback:
  - Raised `87/90 -> 91/94`; retained owner/emitter UID000083, reconstructable state, and blank formal blocks.
  - Identified secondary `+0x10`, cell `0x0061ec80`, as `MerchantDialogPane::HandlePacketEvent(Event*)`; added canonical EventHandler order, complete-object offsets, raw-facet ABI, and exact inherited-consumer interpretation.
  - Preserved all vtable/COL/store/range/broad-family evidence and historicalized only the superseded unknown action-wrapper naming.
- 2026-06-25 B006 accepted-report implementation:
  - Linked exact constructor child [UID:00041Q][0x00517d30-0x00517d74.MerchantDialogPaneConstructor](by-memory/0x00517d30-0x00517d74.MerchantDialogPaneConstructor.md) from the vtable-store evidence.
  - Preserved the three owner-specific vtable bases, broad-family rejection, compiler-generated vtable handling, and blank formal C++.
- 2026-06-16 A001 file-completion support refresh:
  - Changed `86/90 -> 87/90`.
  - Changed owner/emitter from direct file [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md) to direct class [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md), now that the class clears the current gate.
  - Evidence: live IDA and PE scans reconfirmed constructor-store refs, inherited shared-virtual slot refs, raw constructor no-reachability, and no direct branches to the vtable-only method.
- 2026-06-10 B001-008 split:
  - Created as the owner-specific `MerchantDialogPane` child of the mixed merchant-menu vtable family.
  - Evidence: live IDA MCP confirms decorated vtable names, complete-object-locator pointers, raw constructor store sites, and the inherited `0x00517d80` secondary slot.
