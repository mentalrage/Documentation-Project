*** UID:000559 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00000F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00000F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ArgumentedItemConfirmInputDialogPane's layout is expressed by its class declaration;
// no standalone source object is emitted for this evidence-only layout page.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ArgumentedItemConfirmInputDialogPane Layout

## Status

- Entity: exact source-level class layout for [UID:00000F][ArgumentedItemConfirmInputDialogPane](by-class/ArgumentedItemConfirmInputDialogPane.md).
- Direct owner/emitter: UID00000F. Reconstructable evidence page; formal declaration remains on the class H channel.
- Score: `92/94`.

## Exact Layout

| Offset | Size | Source field/view | Evidence |
| --- | ---: | --- | --- |
| `+0x000` | `0x26c` | inherited `DialogPane` object | current IDA base type size and constructor/base teardown. |
| `+0x000` | `4` | primary derived vptr | constructor store to table `0x0061f624`. |
| `+0x0a0` | `4` | secondary/EventHandler view | constructor store to `0x0061f684`; PMD `+0xa0`. |
| `+0x0a4` | `4` | tertiary/TimerHandler view | constructor store to `0x0061f6b4`; PMD `+0xa4`. |
| `+0x26c` | `4` | `ArgumentedMenuMenuItemList *m_menuContext` | exact copied-list allocation/result and action reads. |
| `+0x270` | `4` | `unsigned int m_maxQuantity` | constructor store and `<= 1` action branch. |
| `+0x274` | `4` | `unsigned int m_expectedPrice` | constructor store and dword price comparison. |
| `+0x278` | `4` | `unsigned int m_argumentId` | constructor store and packet/new-quantity argument. |
| total | `0x27c` | natural class size | exact allocation and shared scalar wrapper. |

## Inheritance And Compiler Coverage

- The three vptrs, vtables, RTTI, implicit destructor, scalar deleting wrapper, and adjustor thunks are compiler-generated from the declaration.
- Source declares only the four tail fields. No explicit padding, raw ABI array, or manual wrapper is emitted.
- The implicit destructor intentionally performs no `m_menuContext` cleanup because the binary does not read/delete that field during teardown.

## Evidence And Consumers

- [UID:000557][0x005200d0-0x005203be.ArgumentedItemConfirmInputDialogPaneConstructor](by-memory/0x005200d0-0x005203be.ArgumentedItemConfirmInputDialogPaneConstructor.md) establishes all stores and allocation.
- [UID:000558][0x005203c0-0x00520539.ArgumentedItemConfirmInputDialogPaneOnControlCommand](by-memory/0x005203c0-0x00520539.ArgumentedItemConfirmInputDialogPaneOnControlCommand.md) reads every tail field.
- Confirm vtables are `[0x0061f624,0x0061f680)`, `[0x0061f684,0x0061f6b0)`, and `[0x0061f6b4,0x0061f6bc)`.
- Folded wrappers `0x004b0a20`, `0x004b08e3`, and `0x004b08ee` corroborate exact size/view offsets without transferring source ownership.

## Rejected Alternatives

- Rejected signed/byte narrowing for the three dword fields: constructor stores and comparisons/calls consume full dwords.
- Rejected source destructor cleanup and modern ownership wrappers because they would change runtime behavior.
- Rejected raw `_DWORD` and offset fields because role evidence resolves human source types/names.

## Cross-References

- [UID:00000F][ArgumentedItemConfirmInputDialogPane](by-class/ArgumentedItemConfirmInputDialogPane.md)
- [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md)
- [UID:00055C][ArgumentedItemInputDialogVtables](by-type/by-vtable/ArgumentedItemInputDialogVtables.md)
