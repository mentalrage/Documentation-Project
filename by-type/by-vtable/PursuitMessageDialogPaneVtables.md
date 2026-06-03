*** UID:0001YI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PursuitMessageDialogPane Vtables

## Status

- Entity kind: vtable cluster.
- Covered class: [UID:0000BE][PursuitMessageDialogPane](by-class/PursuitMessageDialogPane.md).
- Likely source file: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md).
- Autogen parent: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), as source-declared/generated-binary class-layout evidence.
- Exact vtable-data range: [UID:0002OM][0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData](by-memory/0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData.md).
- Confidence: strong for vtable bases and raw-constructor stores; medium for final source-level naming of the shared action virtual.

## Vtable Bases

| Class view | Base | Constructor store | Object offset | Notes |
| --- | --- | --- | --- | --- |
| primary | `0x00622428` | `0x0054cac8` | `+0x00` | Primary `DialogPane` view. |
| secondary | `0x00622488` | `0x0054cad0` | `+0xa0` | Input/action view with the shared message-dialog response virtual. |
| tertiary | `0x006224b8` | `0x0054cada` | `+0xa4` | Event/update-handler view. |

The raw constructor at `0x0054cab0-0x0054cae9` is the only direct code xref to these three table bases in the current IDA database. IDA still does not model that constructor start as a function.

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| primary `0x00622428` | `+0x00` | `0x00520b70` | Shared default scalar deleting destructor, not uniquely owned by this class. |
| primary `0x00622428` | `+0x44` | `0x0049f090` | Inherited dialog focus/selection drawing virtual. |
| primary `0x00622428` | `+0x48` | `0x0041b6c0` | Base no-op/default slot. |
| primary `0x00622428` | `+0x4c` | `0x0041b6a0` | Guard/no-op slot. |
| primary `0x00622428` | `+0x50` | `0x0049f1d0` | Inherited dialog content drawing virtual. |
| primary `0x00622428` | `+0x54` | `0x0049f2e0` | Inherited dialog border/background drawing virtual. |
| primary `0x00622428` | `+0x58` | `0x0049fc00` | Inherited dialog hover/update virtual. |
| secondary `0x00622488` | `+0x00` | `0x00520aa5` | Shared adjustor thunk into `0x00520b70` with `this - 0xa0`. |
| secondary `0x00622488` | `+0x10` | `0x0054caf0` | [UID:0001FF][0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual](by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md). |
| tertiary `0x006224b8` | `+0x00` | `0x00520ab0` | Shared adjustor thunk into `0x00520b70` with `this - 0xa4`. |
| tertiary `0x006224b8` | `+0x04` | `0x00544e90` | Base/default event-update slot. |

Do not read primary `+0x5c` as a `PursuitMessageDialogPane` virtual: it is RTTI metadata for the secondary table. Secondary `+0x2c` is RTTI metadata for the tertiary table, and tertiary `+0x08` is RTTI for the following `MessageDialog` table cluster.

## IDA MCP Evidence

- `list_globals *PursuitMessageDialogPane*` reports vtables at `0x00622428`, `0x00622488`, and `0x006224b8`, plus RTTI records at `0x0064e360`, `0x0064e3c0`, and `0x0064e3d4`.
- IDA MCP `py_eval` on 2026-06-01 confirms the exact [UID:0002OM][0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData](by-memory/0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData.md) child range: previous `PrimeNumberGenerator` data ends at `0x00622424`, primary/secondary/tertiary `PursuitMessageDialogPane` RTTI and vtable views occupy `0x00622424-0x006224c0`, and `0x006224c0` starts `MessageDialog` RTTI.
- Raw constructor disassembly at `0x0054cab0-0x0054cae9` calls `DialogPane::DialogPane(L"", 1, 1)`, then stores the three table bases at `0x0054cac8`, `0x0054cad0`, and `0x0054cada`.
- `xrefs_to` the three table bases reports only those constructor stores.
- `lookup_funcs` confirms `0x00520aa5`, `0x00520ab0`, `0x00520b70`, and `0x0054caf0` as modeled functions, while `0x0054cab0` remains `Not a function`.
- `xrefs_to 0x0054caf0` reports vtable data refs at `0x00622498`, `0x00622534`, `0x006225d0`, `0x0062266c`, `0x00622708`, `0x0062292c`, `0x006229c8`, and `0x00622cc8`, showing the handler is shared by the message/menu dialog family.
- Current `class_PursuitMessageDialogPane.meta_wave3` reports `vtable_count: 0` even though active source placeholders name `PursuitMessageDialogPane_vtable`, `PursuitMessageDialogPane_vtable2`, and `PursuitMessageDialogPane_vtable3`.

## Reconstruction Notes

Model `PursuitMessageDialogPane` as a tiny `DialogPane`-derived message-dialog base/companion with three vtable views at `+0x00`, `+0xa0`, and `+0xa4`. Keep the shared destructor glue neutral and excluded from handwritten source reconstruction. Keep `0x0054caf0` with [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) as shared project behavior rather than assigning it exclusively to this tiny base class.

## Cross-References

- [UID:0000BE][PursuitMessageDialogPane](by-class/PursuitMessageDialogPane.md)
- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:0002OM][0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData](by-memory/0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData.md)
- [UID:0001FE][0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor](by-memory/0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor.md)
- [UID:0001FF][0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual](by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md)
- [UID:0001BW][0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks](by-memory/0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks.md)
- [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md)
- [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)

## Changes

- 2026-06-01: Grading changed from validator-header `0/0` to `82/88`, and `RECONSTRUCTABLE` was set to `TRUE`.
  - Before: the page had useful vtable notes, but no exact by-memory vtable-data child and no validator-visible score.
  - After: [UID:0002OM][0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData](by-memory/0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData.md) records the exact primary/secondary/tertiary RTTI/vtable-data range while this page remains the type-level inventory.
  - Evidence: IDA MCP `py_eval` on 2026-06-01 verified the dword layout, neighboring `PrimeNumberGenerator`/`MessageDialog` boundaries, raw constructor vptr-store xrefs, shared response handler refs, and key slot function boundaries. Completion/confidence remain below `95` because the raw constructor has no IDA function object and final source-level shared virtual names are not audited to final-source confidence.
- 2026-06-03 autogen attachment pass:
  - Before: the vtable inventory was reconstructable at `82/88` but unparented.
  - Changed to: `AUTOGEN_PARENT_UID:0000LA`.
  - Evidence: the parent [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) is `88/80` and already owns the `PursuitMessageDialogPane` constructor, the exact [UID:0002OM][0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData](by-memory/0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData.md) child, and the shared message-dialog response virtual.
