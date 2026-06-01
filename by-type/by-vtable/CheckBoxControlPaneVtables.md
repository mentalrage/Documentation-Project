*** UID:0001X8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CheckBoxControlPane Vtables

## Status

- Entity kind: vtable layout
- Addresses: `0x006184d8`, `0x00618540`, `0x00618570`
- Exact vtable-data range: [UID:0002M9][0x006184d8-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d8-0x00618578.CheckBoxControlPaneVtableData.md)
- Proposed owner: [UID:0001TX][CheckBoxControlPaneLayout](by-type/by-struct/CheckBoxControlPaneLayout.md)
- Confidence: strong for installed vtable pointers, adjustor thunks, and the omitted `0x00499ec0` virtual slot; medium for inherited slot names.
- Evidence basis: IDA MCP disassembly/xref/decompile checks on 2026-05-25 plus active `simroot_v2` metadata.

## Constructor Writes

[UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md) writes three vtable pointers:

| Object offset | Vtable | Notes |
| --- | --- | --- |
| `+0x00` | `0x006184d8` | Primary `ControlPane`/paint/type-id surface. |
| `+0x0a0` | `0x00618540` | Secondary event/handler surface; deleting destructor adjustor subtracts `0xa0`. |
| `+0x0a4` | `0x00618570` | Tertiary inherited/helper surface; deleting destructor adjustor subtracts `0xa4`. |

The scalar deleting destructor at `0x0049b110` restores the same three vtable pointers before calling shared pane/control teardown.

## Primary Vtable Highlights

The primary vtable begins at `0x006184d8` and reaches RTTI at `0x0061853c`. Most slots are inherited from the generic control/pane surface. The checkbox-specific slots observed in IDA are:

| Slot address | Target | Meaning |
| --- | --- | --- |
| `0x006184d8` | `0x0049b110` | Scalar deleting destructor. |
| `0x0061851c` | `0x00499e30` | `OnPaint`, draws checked/unchecked tile frame. |
| `0x00618520` | [UID:0000U7][CheckBoxControlPaneStateTypeHelper_00499EC0](by-item/CheckBoxControlPaneStateTypeHelper_00499EC0.md) | Vtable-only virtual helper; active generated output currently omits this method. |
| `0x00618538` | `0x0049b8d0` | Returns control type id `20`. |

IDA decompiles `0x00499ec0` as a control-state helper that compares a byte at `+0x103`, handles requested type `20`, and invalidates/refreshes through virtual slot `+0x20` when the state changes. It has only the primary vtable data xref in the current database.

## Secondary And Tertiary Vtables

| Vtable | Extent | Checkbox-specific slots |
| --- | --- | --- |
| `0x00618540` | through RTTI at `0x0061856c` | `0x00618540 -> 0x0049af27` adjustor deleting destructor; `0x00618544 -> 0x00499de0` mouse toggle handler. |
| `0x00618570` | through adjacent RTTI at `0x00618578` | `0x00618570 -> 0x0049af32` adjustor deleting destructor; `0x00618574 -> 0x00544e90` inherited/helper slot. |

The IDA disassembly continues into adjacent class vtables after these RTTI records. Do not treat the later `SimpleHelpTextPartPane`, `StaticTextControlPane2`, or `FunctionObject` vtable data as part of `CheckBoxControlPane`.

## Exact Boundary Evidence

- IDA MCP `list_globals *CheckBoxControlPane*` on 2026-05-31 reports vtables at `0x006184d8`, `0x00618540`, and `0x00618570`.
- IDA MCP `py_eval` dword scan on 2026-05-31 confirms the exact child range [UID:0002M9][0x006184d8-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d8-0x00618578.CheckBoxControlPaneVtableData.md): `0x006184d4` is the primary RTTI pointer, `0x0061853c` and `0x0061856c` are the secondary/tertiary RTTI locator dwords, and `0x00618578` is the next class RTTI pointer for `SimpleHelpTextPartPane@StaticTextControlPane2`.
- IDA MCP `py_eval` xrefs on 2026-05-31 report constructor vptr stores to the three table bases at `0x00499d5d`, `0x00499d66`, and `0x00499d70`, plus scalar deleting destructor restores at `0x0049b116`, `0x0049b11c`, and `0x0049b126`.

## Generated Data Caveats

- Current `class_CheckBoxControlPane.meta_wave3` still reports `vtable_count: 0` even though IDA confirms all three table bases and constructor/destructor stores.
- Current active `class_CheckBoxControlPane.cpp` omits the primary virtual helper at `0x00499ec0`.
- Current disabled output omits the `0x0049af27` body and emits only the `0x0049af32` thunk body. Both are exact [UID:00011Z][0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks](by-memory/0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks.md) and should remain ignored compiler glue.

## Cross-References

- [UID:0001TX][CheckBoxControlPaneLayout](by-type/by-struct/CheckBoxControlPaneLayout.md)
- [UID:0002M9][0x006184d8-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d8-0x00618578.CheckBoxControlPaneVtableData.md)
- [UID:000021][CheckBoxControlPane](by-class/CheckBoxControlPane.md)
- [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md)
- [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md)
- [UID:0000U7][CheckBoxControlPaneStateTypeHelper_00499EC0](by-item/CheckBoxControlPaneStateTypeHelper_00499EC0.md)
- [UID:00011Z][0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks](by-memory/0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)

## Changes

- 2026-05-31: Grading changed from `0/0` to `84/91`, and `RECONSTRUCTABLE` was set to `TRUE`.
  - Before: the vtable page had useful slot notes but remained unevaluated and did not point to an exact by-memory data slice.
  - After: the page points to [UID:0002M9][0x006184d8-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d8-0x00618578.CheckBoxControlPaneVtableData.md) as the exact primary/secondary/tertiary vtable-data child range.
  - Evidence: IDA MCP `list_globals`, `lookup_funcs`, and `py_eval` on 2026-05-31 reconfirmed table bases, key slot targets, constructor/destructor stores, the vtable-only `0x00499ec0` helper slot, and the boundary before `SimpleHelpTextPartPane@StaticTextControlPane2`.
