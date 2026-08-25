*** UID:0004P8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# UserCreateAppearanceControlVtables

## Status And Disposition

- Compiler-generated ABI/type support for five source-declared classes in [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md).
- Exact data range: `[0x0061dd78,0x0061e0ec)`, 884 bytes, SHA256 `6E4C40229D1673B70B3A66A4673A6BE796FE041FFDC858139D2C6A0AD61F1B9F`.
- Source disposition: `RECONSTRUCTABLE:FALSE`, blank emitter, blank position, and blank formal C++. Ordinary class declarations/virtual methods generate RTTI, vtables, adjustor thunks, and deleting wrappers; no handwritten arrays or ABI bodies belong in source.
- Direct source owner is the dedicated appearance-controls file, while the exact bytes are indexed by the paired by-memory vtable-data page.

## Family Inventory

| Class | Exact evidence | Source-visible virtual contract |
| --- | --- | --- |
| [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md) | Primary `0x0061dd7c`, EventHandler secondary `0x0061dde4`, tertiary `0x0061de14`; paint slot `0x0061ddc0 -> 0x00501360`, mouse slot `0x0061dde8 -> 0x005012b0`. | Virtual destructor, `OnMouseEvent`, `OnPaintFrame`; nonvirtual selection and gender setters. |
| [UID:0000FJ][UserFaceSelectControlPane](by-class/UserFaceSelectControlPane.md) | Contiguous successor family; paint slot `0x0061de64 -> 0x00501840`, mouse slot `0x0061de8c -> 0x00501790`. | Virtual destructor, `OnMouseEvent`, `OnPaintFrame`; nonvirtual selection and gender setters. |
| [UID:0000FH][UserCreatePreviewControlPane](by-class/UserCreatePreviewControlPane.md) | Contiguous successor family; paint slot `0x0061df08 -> 0x00501c60`. | Virtual destructor and `OnPaint`; descriptor/direction/update methods remain nonvirtual. |
| [UID:0000FK][UserHairColorSelectListPane](by-class/UserHairColorSelectListPane.md) | Contiguous ListPane-derived family; selection slot `0x0061dfe0 -> 0x00502090`, draw slot `0x0061dfe8 -> 0x00501f30`. | Virtual destructor, `DrawItem`, `OnItemSelected`; retained getter is nonvirtual. |
| [UID:0000FI][UserFaceColorSelectListPane](by-class/UserFaceColorSelectListPane.md) | Final family before `0x0061e0ec`; selection slot `0x0061e0a4 -> 0x00502350`, draw slot `0x0061e0ac -> 0x005021f0`. | Virtual destructor, `DrawItem`, `OnItemSelected`; retained getter is nonvirtual. |

## ABI And Constructor Evidence

- Constructors install complete-object and inherited EventHandler/TimerHandler/ListPane views according to the MSVC multiple-inheritance ABI. Those writes prove class identity and subobject role but are not source statements.
- Hair selector deleting-destructor and adjustor anchors include `0x00502d90`, `0x005025d4`, and `0x005025df`; the neighboring classes follow the same accepted compiler-support family documented by [UID:00022X][0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors](by-memory/0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors.md) and [UID:0001AF][0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks](by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md).
- The event entries use adjusted receivers in machine code. Source declarations stay ordinary virtual overrides; no `this - 0xa0`, thunk prototype, vptr field, or explicit vtable initialization is emitted.
- Normal virtual destructor declarations on all five class pages are sufficient to regenerate deleting destructors and vtable slots.

## Range And Boundary Evidence

- `0x0061dd78` begins the UserHairSelectControlPane RTTI-adjacent word immediately after exact BlueAlertPane vtable-data child [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md).
- `0x0061e0ec` is the exclusive end before the following main-menu/new-user resource data. The 884-byte hash covers all five contiguous class families and no resource strings or color-table words.
- The broad [UID:00025Q][0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData](by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md) remains a mixed-owner index and must not emit the exact child bytes.
- Slot xrefs to all virtual source methods, constructor vptr stores, RTTI ordering, scalar-deleting wrappers, and adjustor thunks jointly prove the family split.

## Ownership And Source Placement

- The five direct class pages own the source-visible declarations and virtual bodies. This type page owns only the cross-class ABI map.
- File ownership terminates at [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md), consistent with contiguous method families, contiguous vtables, the shared color table, and common destructor support.
- CreateUserDialogPane is the allocator/coordinator, not vtable owner. ControlPane/ListPane are bases. GrafPort, NewHumanImageLib, PaletteLib, EPFLib, Surface, and resource tables are downstream services.

## Negative And Historical Evidence

- No source semantics exist in raw RTTI locators, vtable pointer arrays, adjustor thunk entries, deleting-wrapper pointers, or compiler cookies.
- No evidence supports a handcrafted vtable struct, global pointer table, inline assembly, explicit vptr store, or duplicate per-class ABI body.
- Historical broad read-only-data documentation stopped at a mixed appearance/control span; the exact child hash and class/slot mapping resolve the boundary while preserving that broad page as non-emitting.
- No authentic source/PDB survives. Exact addresses, table entries, stores, and slot targets are direct facts; descriptive class/method spellings are bounded source inference already carried by the source pages.
- The blank formal block is intentional exhaustive no-code disposition, not an unresolved emitter marker.

## Score Rationale

- Completion 91 records the exact range/hash/boundaries, five-family map, virtual slots, constructor/adjustor/destructor ABI, owner, source-placement route, and exhaustive non-emitting disposition.
- Confidence 94 reflects direct data/xref/constructor evidence with no need for handwritten C++; original compiler/linker ordering and unsymbolized spellings keep it below final-symbol certainty.

