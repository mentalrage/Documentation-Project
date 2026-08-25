*** UID:000556 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00000G | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00000G | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ArgumentedItemQuantityInputDialogPane's layout is expressed by its class declaration;
// no standalone source object is emitted for this evidence-only layout page.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ArgumentedItemQuantityInputDialogPane Layout

## Status

- Entity: exact source-level class layout for [UID:00000G][ArgumentedItemQuantityInputDialogPane](by-class/ArgumentedItemQuantityInputDialogPane.md).
- Direct owner/emitter: UID00000G. Reconstructable evidence page; formal declarations remain on the class H channel and are not duplicated here.
- Score: `92/94`.

## Exact Layout

| Offset | Size | Source field/view | Evidence |
| --- | ---: | --- | --- |
| `+0x000` | `0x26c` | inherited `DialogPane` object | IDA `DialogPane` type size `0x26c`; constructor invokes base and installs inherited three-view vptrs. |
| `+0x000` | `4` | primary derived vptr | constructor store to table `0x0061f588`. |
| `+0x0a0` | `4` | inherited secondary/EventHandler view | constructor store to table `0x0061f5e8`; PMD offset `+0xa0`. |
| `+0x0a4` | `4` | inherited tertiary/TimerHandler view | constructor store to table `0x0061f618`; PMD offset `+0xa4`. |
| `+0x26c` | `4` | `ArgumentedMenuMenuItemList *m_menuContext` | exact `0x15c` allocation/copy-constructor result stored here; both action and shared destructor evidence preserve a raw pointer with no derived cleanup. |
| `+0x270` | `4` | `unsigned int m_argumentId` | constructor dword store and packet-helper argument read. |
| total | `0x274` | natural class size | exact constructor allocation and shared scalar-deleting-wrapper size. |

## Inheritance And Compiler Coverage

- The three vtable views and seven-base RTTI graph are inherited-source/compiler effects, not explicit raw fields or arrays.
- The source declares only the two tail members. No padding member, manual vptr, RTTI object, scalar deleting destructor, or adjustor thunk is authored.
- The implicit derived destructor performs base teardown and intentionally does not delete `m_menuContext`, matching the binary.

## Evidence And Consumers

- [UID:000554][0x0051fc90-0x0051ff6c.ArgumentedItemQuantityInputDialogPaneConstructor](by-memory/0x0051fc90-0x0051ff6c.ArgumentedItemQuantityInputDialogPaneConstructor.md) establishes all stores and exact allocation.
- [UID:000555][0x0051ff70-0x005200c4.ArgumentedItemQuantityInputDialogPaneOnControlCommand](by-memory/0x0051ff70-0x005200c4.ArgumentedItemQuantityInputDialogPaneOnControlCommand.md) reads both tail fields.
- Quantity vtables are `[0x0061f588,0x0061f5e4)`, `[0x0061f5e8,0x0061f614)`, and `[0x0061f618,0x0061f620)`.
- Shared compiler wrappers at `0x0047eaf0`, `0x0047e8d9`, and `0x0047e8e4` corroborate exact object size and view offsets without becoming source owners.

## Rejected Alternatives

- Rejected owning-smart-pointer or destructor cleanup: no binary cleanup reads or deletes `+0x26c`.
- Rejected byte-array tail and explicit vptr members: natural C++ inheritance and the two typed members close the exact allocation.
- Rejected raw `_DWORD` names: copied list context and packet use determine realistic source types and names.

## Cross-References

- [UID:00000G][ArgumentedItemQuantityInputDialogPane](by-class/ArgumentedItemQuantityInputDialogPane.md)
- [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md)
- [UID:00055C][ArgumentedItemInputDialogVtables](by-type/by-vtable/ArgumentedItemInputDialogVtables.md)
