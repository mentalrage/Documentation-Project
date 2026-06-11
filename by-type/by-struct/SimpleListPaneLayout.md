*** UID:0001W3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000D8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SimpleListPane Layout

## Status

- Confidence: strong for `SimpleListPane` vptrs and inherited `ListPane` tail fields; final source names for copied-text helpers remain provisional.
- Direct owner: [UID:0000D8][SimpleListPane](by-class/SimpleListPane.md).
- Evidence basis: IDA raw constructor, destructor/deleting-destructor decompilation, vtable xrefs, `ListPane` base layout, and split copied-text helper pages.

## Layout Summary

`SimpleListPane` is a thin `ListPane`-derived object with no confirmed local fields beyond the inherited `ListPane` state. The constructor installs one primary and two secondary/adjusted `SimpleListPane` vtables after the `ListPane` base constructor returns. The scalar deleting destructor's sized-delete path passes `0x14c`, confirming the inherited object extent.

| Offset | Size | Evidence | Meaning |
| --- | ---: | --- | --- |
| `+0x00` | 4 | constructor writes `0x00624c64`; destructor restores same value | Primary `SimpleListPane` vtable pointer. |
| `+0xa0` | 4 | constructor writes `0x00624cec`; thunk at `0x00573c38` subtracts `0xa0` | Secondary-base vtable pointer for inherited pane/list subobject. |
| `+0xa4` | 4 | constructor writes `0x00624d1c`; thunk at `0x00573c43` subtracts `0xa4` | Tertiary/secondary-base vtable pointer for inherited pane/list subobject. |
| `+0x130` | 4 | `ListPane` constructor writes primary list pointer; `SimpleListPane` destructors read it | Primary list-entry state pointer used for copied-text buffer cleanup. |
| `+0x134` | 4 | inherited from `ListPane` | Selected index; not a `SimpleListPane` local field. |
| `+0x138` | 4 | inherited from `ListPane` | Parallel selection/list state pointer; not a `SimpleListPane` local field. |
| `+0x13c` | 1 | inherited from `ListPane` | Selection-mode byte; not a `SimpleListPane` local field. |
| `+0x140` | 2 | base constructor receives fixed `4` | List cell/column width-style field inherited from `ListPane`. |
| `+0x144` | 2 | base constructor receives fixed `10` | List cell/row height-style field inherited from `ListPane`. |
| `+0x149` | 1 | inherited from `ListPane` | Drag/input state byte; not a `SimpleListPane` local field. |
| `0x14c` | object extent | scalar deleting destructor uses sized-delete size `0x14c` | End of inherited `ListPane` object storage. |

## Field Evidence

| Region | Evidence | Layout decision |
| --- | --- | --- |
| `+0x00`, `+0xa0`, `+0xa4` vptrs | [UID:0001HP][0x005739a0-0x005739f6.SimpleListPaneConstructor](by-memory/0x005739a0-0x005739f6.SimpleListPaneConstructor.md) records constructor writes to `0x00624c64`, `0x00624cec`, and `0x00624d1c`; [UID:0001HQ][0x00573c38-0x00573d15.SimpleListPaneDestructorThunks](by-memory/0x00573c38-0x00573d15.SimpleListPaneDestructorThunks.md) records adjustors subtracting `0xa0` and `0xa4`. | Three-view `ListPane`-derived object with no extra local vptr-bearing subobject beyond inherited pane/list facets. |
| `+0x130` list state pointer | [UID:000241][0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers](by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md) and [UID:0001HQ][0x00573c38-0x00573d15.SimpleListPaneDestructorThunks](by-memory/0x00573c38-0x00573d15.SimpleListPaneDestructorThunks.md) both use the inherited list state to fetch entry slots before freeing copied-text buffers. | Inherited `ListPane` primary list storage, not a new `SimpleListPane` local field. |
| `+0x134` through `+0x149` inherited tail fields | [UID:00007A][ListPane](by-class/ListPane.md) documents selection/list tail fields and broad list-control ownership; `SimpleListPane` helpers call shared `ListPane` insert/remove/selected-entry helpers rather than accessing new local state. | Keep names inherited from `ListPane`; this page should not invent duplicate `SimpleListPane` fields. |
| `0x14c` extent | [UID:0001HQ][0x00573c38-0x00573d15.SimpleListPaneDestructorThunks](by-memory/0x00573c38-0x00573d15.SimpleListPaneDestructorThunks.md) records the sized-delete path using `0x14c`. | Confirms no recovered local storage beyond inherited `ListPane` object extent. |

## Notes

- The exact base-class field names should be inherited from the reviewed [UID:0000KT][ListPane](by-file/ListPane.md) layout rather than invented here.
- Active generated output's `ClientItemMenuItemList` naming is not reliable for this layout. The offsets and destructor behavior point to shared list control infrastructure.
- `0x00573a00` and `0x00573c50` both read `this + 0x130`, loop `*(list + 0x0c)`, fetch each slot through [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md) helper `0x004f3dc0`, and free copied text buffers.
- Raw copied-text helpers at `0x00573aa0`, `0x00573b10`, `0x00573b70`, and `0x00573bb0` use the inherited `ListPane` insert/remove/selected-entry helpers rather than new local `SimpleListPane` fields.
- The `SimpleListPane` vtable cluster is in [UID:00026F][0x00624c64-0x00624f20.SimpleServerSelectReadOnlyData](by-memory/0x00624c64-0x00624f20.SimpleServerSelectReadOnlyData.md), with primary `0x00624c64`, secondary `0x00624cec`, and tertiary `0x00624d1c`.
- 2026-06-08 A002 Batch129 live IDA MCP rechecked the constructor/destructor evidence used by this layout: `0x005739a0` is still `Not a function`, `0x00573a00` is size `0x98`, `0x00573c38` and `0x00573c43` are `0xb` thunks, and `0x00573c50` is size `0xc5`. `callees` for the destructor bodies still route through shared `ListPane` selected-entry/base cleanup helpers and copied-text allocation/free helpers.

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000D8][SimpleListPane](by-class/SimpleListPane.md). The child layout is now `85/88`; the direct class parent was refreshed to `85/85`, and its direct source file [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md) was refreshed to `86/85`. This layout belongs to the class, while [UID:0000KT][ListPane](by-file/ListPane.md) and [UID:00007A][ListPane](by-class/ListPane.md) remain base-layout context rather than direct owners.

## Cross-References

- [UID:0000D8][SimpleListPane](by-class/SimpleListPane.md)
- [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md)
- [UID:0001HP][0x005739a0-0x005739f6.SimpleListPaneConstructor](by-memory/0x005739a0-0x005739f6.SimpleListPaneConstructor.md)
- [UID:000241][0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers](by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md)
- [UID:0001HQ][0x00573c38-0x00573d15.SimpleListPaneDestructorThunks](by-memory/0x00573c38-0x00573d15.SimpleListPaneDestructorThunks.md)
- [UID:00007A][ListPane](by-class/ListPane.md)
- [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md)
- [UID:00026F][0x00624c64-0x00624f20.SimpleServerSelectReadOnlyData](by-memory/0x00624c64-0x00624f20.SimpleServerSelectReadOnlyData.md)

## Changes

- 2026-05-31: Changed completion/confidence from `0/0` to `76/84` and marked the layout reconstructable.
  - Before: The page listed only the main vptrs and `+0x130` in broad terms, with no scored metadata.
  - After: The page records exact vtable addresses, inherited `ListPane` tail fields, object extent `0x14c`, and the split destructor/text-entry helper evidence.
  - Evidence: IDA MCP raw constructor disassembly, decompilation of `0x00573a00` and `0x00573c50`, sized-delete instruction at `0x00573cf1`, vtable xrefs, and `ListPane` layout documentation.
- 2026-06-08 A002 Batch129:
  - Before: `COMPLETION:76`, `CONFIDENCE:84`, `AUTOGEN_PARENT_UID` blank.
  - After: `COMPLETION:85`, `CONFIDENCE:88`, `AUTOGEN_PARENT_UID:0000D8`.
  - Evidence: added field/region evidence, live IDA MCP recheck details, and the strict assignment-gate rationale. The direct class parent [UID:0000D8][SimpleListPane](by-class/SimpleListPane.md) was improved to `85/85`, and file parent [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md) was improved to `86/85`; final C++ remains blank below the 95/95 gate.
