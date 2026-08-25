*** UID:0001TN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000006 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000006 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0001TN] AddEmployeeItemDialog layout evidence marker.
// The derived owner pointer and vtable views are represented through the class and exact child pages; no standalone layout body is emitted here.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AddEmployeeItemDialog Layout

## Status

- Entity kind: derived dialog layout.
- Covered class: [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md).
- Likely owner source: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), with base picker layout inherited from [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md).
- Confidence: strong for derived vtable views, object size, employee-owner pointer, inline construction, and the raw constructor exclusion.
- Reconstructable: yes, as source-level class/layout information. Do not emit C++ from this type page until the real constructor boundary and `AddItemDialog` base declaration are fully resolved.
- Autogen parent: [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md). Batch 170 attaches this layout to the direct class owner after the layout reached `85/89` and the class page reached `85/89`; the owning file [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md) is `88/85`.

## Layout Hypothesis

`AddEmployeeItemDialog` is an employee-specific `AddItemDialog` variant. The base item-picker object occupies the first `0x270` bytes; the derived class adds one owner pointer at `+0x270`. Live [UID:0000TT][AddEmployeeItemDialogInlineConstruction_004A339F](by-item/AddEmployeeItemDialogInlineConstruction_004A339F.md) allocates `0x274` bytes.

| Offset | Size | Observed field | Evidence |
| --- | --- | --- | --- |
| `+0x00` | 4 | primary vtable | Raw constructor-shaped bytes store `0x006190d4`; live `EmployeeDialogPane::OnButtonAction` stores the same table at `0x004a33a4`. |
| `+0xa0` | 4 | secondary dialog/input vtable view | Raw bytes store `0x00619134`; live construction stores it at `0x004a33aa`. |
| `+0xa4` | 4 | tertiary event/update vtable view | Raw bytes store `0x00619164`; live construction stores it at `0x004a33b4`. |
| `+0x270` | 4 | `EmployeeDialogPane* owner` | Raw bytes store the constructor argument at `0x004a4af6`; live construction stores the current `EmployeeDialogPane` pointer at `0x004a33be`; `OnButtonClick` reads it at `0x004a4be6`. |

## IDA MCP Evidence

- `lookup_funcs` confirms `0x004a4b20` as a real `0x191`-byte method and `0x004a3240` as the live employee dialog button/action handler. It reports `0x004a4ae0` as `Not a function`.
- `xrefs_to` the three vtable bases reports live stores in `EmployeeDialogPane::OnButtonAction` at `0x004a33a4`, `0x004a33aa`, and `0x004a33b4`, plus raw non-function stores at `0x004a4afe`, `0x004a4b04`, and `0x004a4b0e`.
- Raw disassembly from `0x004a4ae0-0x004a4b1f` calls `AddItemDialog` at `0x004ae4c0`, stores `[esi+0x270] = [ebp+8]`, installs the three `AddEmployeeItemDialog` vtables, and returns with `retn 4`.
- IDA decompilation of `0x004a3240` shows the live path allocating `0x274` bytes, calling `AddItemDialog(0,0)`, patching the same three vtables, and storing the current `EmployeeDialogPane` pointer at dword index `156` (`+0x270`).
- IDA decompilation of `0x004a4b20` reads `*(this + 0x270)` before clearing owner field `+0x420`, opening `EmployeeQuantityInputDialogPane`, or sending employee command `5`.
- 2026-05-31 IDA MCP recheck confirms `0x004a4ae0` is still not an IDA function, but raw disassembly from `0x004a4ae0-0x004a4b1f` performs the constructor-shaped sequence: calls `0x004ae4c0`, writes `[esi+0x270] = [ebp+8]`, installs vtables at `+0x00`, `+0xa0`, and `+0xa4`, then returns with `retn 4`.
- 2026-05-31 IDA MCP recheck of `0x004a3240` confirms live allocation size `0x274`, base `AddItemDialog` construction through `0x004ae4c0`, and `0x274`-byte derived object setup in the employee dialog action path.
- 2026-05-31 IDA MCP recheck of `0x004a4b20` confirms constants `0x270`, `0x1ec`, and `0x1e8` are used in the selected-item/owner-driven button path.
- The same method uses the selected item record's byte flag at `+0x1ec` to choose the quantity dialog path and the dword at `+0x1e8` as the direct-dispatch count/value when no quantity prompt is required. These item-record offsets are owned by the inventory/item metadata, not by `AddEmployeeItemDialog`.
- Current Wave3 metadata reports `vtable_count: 0` for `AddEmployeeItemDialog`, so the generated class inventory omits the real table bases even though active source names placeholder vtables.
- 2026-06-11 A003 live IDA MCP recheck against `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` reconfirmed `EmployeeDialogPane::OnButtonAction` at `0x004a3240-0x004a33d8`, no IDA function at `0x004a4ae0`, `OnButtonClick` at `0x004a4b20-0x004a4cb1`, AddEmployee adjustor thunks at `0x004a4cb1-0x004a4cc7`, and scalar deleting destructor at `0x004a4d00-0x004a4d3b`. The same pass reconfirmed vtable-store xrefs from the live inline construction (`0x004a33a4`, `0x004a33aa`, `0x004a33b4`) and raw byte island (`0x004a4afe`, `0x004a4b04`, `0x004a4b0e`), no xrefs to `0x004a4ae0`, the primary action slot data ref at `0x0061911c`, and destructor refs from the two adjustor thunks plus the primary table. Raw bytes at `0x004a4ae0` still show the constructor-shaped sequence that calls `AddItemDialog`, stores `[this+0x270]`, installs the three AddEmployee tables, and returns with `retn 4`.

## Reconstruction Notes

In source, model this as a small derived class over `AddItemDialog` with one extra `EmployeeDialogPane*` member. The live construction evidence favors expressing creation inside `EmployeeDialogPane::OnButtonAction` as a normal derived allocation/constructor, while preserving the raw `0x004a4ae0` bytes as a projected constructor island until function-boundary metadata is reconciled.

The `+0x00`, `+0xa0`, and `+0xa4` vtable views are represented by [UID:0002MH][0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData](by-memory/0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData.md). B006 2026-06-28 resolves that exact `.rdata` child with a formal no-raw-vtable marker because the vtable/RTTI bytes are compiler-generated from this class layout, inherited `AddItemDialog` interface, and [UID:00013A][0x004a4b20-0x004a4d3b.AddEmployeeItemDialog](by-memory/0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md) virtual method/destructor shape, not a handwritten source array.

2026-06-18 B004 constructor/source-route closure: object size `0x274`, base `AddItemDialog` extent `0x270`, and derived owner field `+0x270` are validated by both the inline live construction path at `0x004a339f` and the retained raw constructor-shaped island at `0x004a4ae0`. No current local PE dword/rel32 route or existing IDA-backed xref evidence makes the raw island callable. Source placement is `EmployeeDialogPane` for the derived AddEmployee class behavior, while generic base `AddItemDialog` construction/fallback/destruction remains `ItemDialogs`.

The three destructor adjustor thunks at `0x004a4cb1` and `0x004a4cbc` are compiler glue. They should remain documented as ABI evidence, not handwritten source methods.

## Assignment Gate

This layout now clears the strict child/direct-parent gate. The type page is `85/89`, the direct class owner [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md) is `85/89`, and the file parent [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md) is `88/85`. The direct owner is the class rather than the file because the layout describes the derived object tail (`+0x270`) and vtable views for one `AddEmployeeItemDialog` class.

## Resolved And Reviewable Questions

- Current constructor-emission decision: the raw `0x004a4ae0` bytes are retained constructor-shaped layout evidence but should not emit standalone source C++ under current evidence. The live source construction route is the inline `EmployeeDialogPane::OnButtonAction` path.
- Reviewable future item: if a later pass finds a caller/table route or original-source proof for the raw island, revisit whether a standalone out-of-line constructor should be emitted.
- Source split decision for this layout: the derived `AddEmployeeItemDialog` owner pointer and behavior belong with `EmployeeDialogPane`; generic base picker layout and fallback remain `ItemDialogs` dependencies.

## Cross-References

- [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md)
- [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- [UID:0000TT][AddEmployeeItemDialogInlineConstruction_004A339F](by-item/AddEmployeeItemDialogInlineConstruction_004A339F.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md)
- [UID:00013A][0x004a4b20-0x004a4d3b.AddEmployeeItemDialog](by-memory/0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md)
- [UID:000139][0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor](by-memory/0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor.md)
- [UID:00013B][0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks](by-memory/0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks.md)
- [UID:0001R9][employee-dialog-resources](by-resource/employee-dialog-resources.md)

## Changes

- 2026-06-28 B006 vtable-data marker support sync:
  - Score unchanged at `85/89`.
  - Summary/evidence: added the [UID:0002MH][0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData](by-memory/0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData.md) support note linking the `+0x00`, `+0xa0`, and `+0xa4` vtable views to the accepted formal no-raw-vtable marker disposition. Current MCP reconfirmed the same live inline stores, raw no-function stores, object size `0x274`, and owner pointer `+0x270`; no layout metadata or C++ body changed.
- 2026-06-11 A003 supervisor-row pass:
  - Changed from: `76/86`, reconstructable, parent blank.
  - Changed to: `85/89`, parent [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md), C++ still blank.
  - Evidence: live IDA reconfirmed the inline allocation/setup path, raw no-function/no-xref constructor-shaped island, exact action/thunk/destructor bounds, owner pointer at `+0x270`, three vtable-store sets, primary action/destructor table refs, and the class/file parent chain clearing the strict gate.
- 2026-06-18 B004 source-route closure:
  - Changed to: retained score `85/89` and documented the current non-emitting raw-constructor decision.
  - Evidence: B004 local route scans found no dword/rel32 path to raw `0x004a4ae0`, while both the raw island and inline live path still validate object size `0x274`, base extent `0x270`, three vtable views, and owner field `+0x270`.
