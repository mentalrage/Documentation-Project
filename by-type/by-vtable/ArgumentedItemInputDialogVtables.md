*** UID:00055C | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Argumented-item input-dialog vtables and RTTI are compiler-generated from the
// class declarations; do not emit handwritten ABI arrays or wrapper bodies.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Argumented Item Input Dialog Vtables

## Status

- Entity kind: complete source-level vtable/RTTI contract for both argumented-item input-dialog classes.
- Canonical source owner/emitter: [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md).
- Exact memory authority: [UID:00055A][0x0061f584-0x0061f6bc.ArgumentedItemInputDialogVtableData](by-memory/0x0061f584-0x0061f6bc.ArgumentedItemInputDialogVtableData.md).
- Source disposition: reconstructable through ordinary class declarations only; the CPP channel emits only the explicit compiler-generated disposition above and H remains blank, preventing duplicate source or ABI arrays.
- Score: `92/95`; very strong.

## Six View Inventory

| Class/view | Object offset | Vtable range | Slots | Constructor store |
| --- | ---: | --- | ---: | --- |
| Quantity primary | `+0x00` | `[0x0061f588,0x0061f5e4)` | 23 | `0x0051fcec` |
| Quantity EventHandler | `+0xa0` | `[0x0061f5e8,0x0061f614)` | 11 | `0x0051fcf2` |
| Quantity TimerHandler | `+0xa4` | `[0x0061f618,0x0061f620)` | 2 | `0x0051fcfc` |
| Confirm primary | `+0x00` | `[0x0061f624,0x0061f680)` | 23 | `0x00520147` |
| Confirm EventHandler | `+0xa0` | `[0x0061f684,0x0061f6b0)` | 11 | `0x0052014d` |
| Confirm TimerHandler | `+0xa4` | `[0x0061f6b4,0x0061f6bc)` | 2 | `0x00520157` |

## Primary Slot Contract

Both 23-slot primary tables have the same inherited ordering. Only the deleting wrapper and `OnControlCommand` implementation differ by derived class.

| Offset | Source-level role |
| ---: | --- |
| `+0x00` | Compiler-generated scalar deleting destructor from the implicit virtual destructor. |
| `+0x04` | Runtime-class query. |
| `+0x08` | Default change-message handler. |
| `+0x0c` | UpdateRenderRegion. |
| `+0x10` | Three-argument extension hook. |
| `+0x14` | Show. |
| `+0x18` | Hide. |
| `+0x1c` | GetParentPane. |
| `+0x20` | InvalidateRect. |
| `+0x24` | GetDescription. |
| `+0x28` | GetScreenBounds. |
| `+0x2c` | SetBounds. |
| `+0x30` | OnCreate. |
| `+0x34` | InsertInLayer. |
| `+0x38` | OnDestroy. |
| `+0x3c` | OnShow. |
| `+0x40` | OnHide. |
| `+0x44` | OnPaint. |
| `+0x48` | Derived `OnControlCommand(int controlIndex, int notifyCode)`. |
| `+0x4c` | UpdateActionButton. |
| `+0x50` | DrawBackground. |
| `+0x54` | DrawBorder. |
| `+0x58` | SetHoverControl. |

## Secondary And Tertiary Slot Contract

| EventHandler offset | Source-level role |
| ---: | --- |
| `+0x00` | Compiler-generated destructor adjustor for the `+0xa0` view. |
| `+0x04` | HandlePointerOrMouseEvent. |
| `+0x08` | HandleKeyOrTextEvent. |
| `+0x0c` | HandleImeEvent. |
| `+0x10` | HandlePacketEvent. |
| `+0x14` | HandleSystemOrControlEvent. |
| `+0x18` | HandleType19Event. |
| `+0x1c` | ForwardHandlerOrder. |
| `+0x20` | GetLocalEventPair. |
| `+0x24` | GetScreenEventPair. |
| `+0x28` | ShouldAcceptEvent. |

| TimerHandler offset | Source-level role |
| ---: | --- |
| `+0x00` | Compiler-generated destructor adjustor for the `+0xa4` view. |
| `+0x04` | Inherited `OnTimer(int,int,int)`. |

## RTTI And Destructor Contract

- Quantity self descriptor `0x00677b70`, primary COL `0x0064bf18`, and CHD `0x0064bf2c` define a seven-base graph.
- Confirm self descriptor `0x00677ba4`, primary COL `0x0064bfa0`, and CHD `0x0064bfb4` define the parallel seven-base graph.
- The secondary and tertiary PMD offsets are exactly `+0xa0` and `+0xa4` for both classes.
- Quantity's primary/secondary/tertiary deleting routes fold through shared wrapper/adjustor bodies at `0x0047eaf0`, `0x0047e8d9`, and `0x0047e8e4`.
- Confirm's deleting routes fold with existing compiler artifacts around `0x004b08e3`, `0x004b08ee`, and `0x004b0a20-0x004b0a5b`.
- These are compiler consequences of the class declarations. They must not be authored as explicit wrapper functions, vtable arrays, or manual RTTI objects.

## Ownership And Boundaries

- [UID:000320][ArgumentedMenuDialogVtables](by-type/by-vtable/ArgumentedMenuDialogVtables.md) owns the predecessor argumented-menu tables and records quantity base `0x0061f588` as its exact successor.
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) remains a mixed-family index; it does not replace this owner-specific contract.
- ObjectImage vtable data begins after `0x0061f6bc` and is excluded.

## Reconstruction Notes

- UID00000G and UID00000F must declare their virtual `OnControlCommand` overrides in H and emit the source bodies through exact by-memory method children.
- The inherited Pane/DialogPane/EventHandler/TimerHandler declarations provide the remaining slot order.
- Exact implicit-destructor behavior preserves the observed copied-list pointer lifetime. Do not add ownership cleanup absent from the binary.
- The ABI tables, COLs, CHDs, base descriptors, scalar deleting wrappers, and adjustor thunks are compiler-generated evidence only.

## Historical Assumptions And Corrections

- Earlier mixed-family pages identified only the broad successor boundary. This page resolves all six views, all slot counts and roles, both RTTI graphs, constructor stores, and folding routes to UID0000HH.
- Shared wrapper reuse does not move source ownership to AlertPane, ExchangeDialog, or ItemExchange modules.

## Cross-References

- [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md)
- [UID:00000G][ArgumentedItemQuantityInputDialogPane](by-class/ArgumentedItemQuantityInputDialogPane.md)
- [UID:00000F][ArgumentedItemConfirmInputDialogPane](by-class/ArgumentedItemConfirmInputDialogPane.md)
- [UID:000320][ArgumentedMenuDialogVtables](by-type/by-vtable/ArgumentedMenuDialogVtables.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
