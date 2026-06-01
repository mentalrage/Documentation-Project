*** UID:0001YF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PatchPane Vtable Family

## Status

- Confidence: strong for addresses, slot boundaries, and thunk ownership.
- Source owner: [UID:0000MH][PatchPane](by-file/PatchPane.md)
- Classes covered: [UID:0000A9][PatchPane](by-class/PatchPane.md), [UID:0000AA][PatchPane2](by-class/PatchPane2.md), [UID:0000AC][PatchPane__PatchFileSlice](by-class/PatchPane__PatchFileSlice.md), [UID:0000AB][PatchPane__PatchFileData](by-class/PatchPane__PatchFileData.md)
- Exact vtable-data ranges: [UID:0002OI][0x00621db8-0x00621e64.PatchPaneVtableData](by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md) and [UID:0002OJ][0x00621f40-0x00621fd8.PatchPane2VtableData](by-memory/0x00621f40-0x00621fd8.PatchPane2VtableData.md)

## Vtable Inventory

| Class / subobject | Vtable address | Slots | Key slots |
| --- | --- | --- | --- |
| `PatchPane::PatchFileSlice` | `0x00621dbc` | `+0x00` only | `+0x00` -> `0x00548430` vector/scalar deleting destructor. |
| `PatchPane::PatchFileData` | `0x00621dc4` | `+0x00` only | `+0x00` -> `0x00548500` scalar deleting destructor. |
| `PatchPane` primary | `0x00621dcc` | `+0x00-0x58` | `+0x00` -> `0x00548560` scalar deleting destructor; `+0x48` -> `0x00547950` patch status handler. |
| `PatchPane` secondary `+0xa0` subobject | `0x00621e2c` | `+0x00-0x28` | `+0x00` -> `0x005484db` adjustor thunk; `+0x10` -> `0x005474f0` packet response handler. |
| `PatchPane` tertiary `+0xa4` subobject | `0x00621e5c` | `+0x00-0x04` | `+0x00` -> `0x005484e6` adjustor thunk; `+0x04` -> `0x00547860` patch action/timer handler. |
| `PatchPane2` primary | `0x00621f40` | `+0x00-0x58` | `+0x00` -> `0x00549370` scalar deleting destructor. |
| `PatchPane2` secondary `+0xa0` subobject | `0x00621fa0` | `+0x00-0x28` | `+0x00` -> `0x0054934b` adjustor thunk; `+0x14` -> `0x00548f30` work-event predicate; `+0x18` -> `0x00548a80` main work-event loop. |
| `PatchPane2` tertiary `+0xa4` subobject | `0x00621fd0` | `+0x00-0x04` | `+0x00` -> `0x00549356` adjustor thunk; `+0x04` -> inherited handler `0x00544e90`. |

The short tertiary tables stop before adjacent string/data storage. For example, `0x00621e64` begins the UTF-16 `Auto Patch` string and `0x00621fd8` begins the UTF-16 `Patcher.exe.new` string, not additional vtable slots.

## IDA Evidence

- IDA names the vtable symbols from `0x00621dbc` through `0x00621fd0`.
- IDA xrefs show constructor/destructor stores into the primary, secondary, and tertiary `PatchPane` / `PatchPane2` vtable pointers.
- IDA xrefs from vtable data slots confirm `0x005474f0`, `0x00547860`, `0x00548a80`, and `0x00548f30` are virtual callback bodies despite active generated-output omissions.
- IDA decompilation confirms the adjustor thunks subtract `0xa0` or `0xa4` from `this` and tail-call the matching scalar deleting destructor.
- IDA MCP `py_eval` on 2026-06-01 confirms `PatchPane` vtable data starts at the `PatchFileSlice` RTTI locator pointer at `0x00621db8`, ends before `Auto Patch` string data at `0x00621e64`, and `PatchPane2` vtable data ends before patcher executable string/storage at `0x00621fd8`.

## Generated-Data Caveat

Current `simroot_v2` metadata reports `vtable_count: 0` for `PatchPane`, `PatchPane2`, `PatchPane::PatchFileSlice`, and related generated classes even though IDA has concrete vtable symbols and data xrefs. Do not use the generated vtable inventory as evidence that these classes are non-polymorphic.

## Cross-References

- [UID:0002OI][0x00621db8-0x00621e64.PatchPaneVtableData](by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md)
- [UID:0002OJ][0x00621f40-0x00621fd8.PatchPane2VtableData](by-memory/0x00621f40-0x00621fd8.PatchPane2VtableData.md)
- [UID:0000MH][PatchPane](by-file/PatchPane.md)
- [UID:0000A9][PatchPane](by-class/PatchPane.md)
- [UID:0000AA][PatchPane2](by-class/PatchPane2.md)
- [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md)
- [UID:0001EU][0x005484db-0x005484f0.PatchPaneAdjustorThunks](by-memory/0x005484db-0x005484f0.PatchPaneAdjustorThunks.md)
- [UID:0001F0][0x0054934b-0x00549360.PatchPane2AdjustorThunks](by-memory/0x0054934b-0x00549360.PatchPane2AdjustorThunks.md)
- [UID:0001VJ][PatchPane2Layout](by-type/by-struct/PatchPane2Layout.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-06-01:
  - What existed before: this vtable-family page had strong table/slot evidence, but the validator-tracked completion/confidence header remained `0/0`, there were no exact `by-memory` child pages for the two separated vtable-data islands, and the parent read-only-data aggregate started at the first `PatchFileSlice` vtable slot instead of its RTTI pointer.
  - Changed to: scored the page as a strong but non-final vtable inventory, marked it reconstructable, and linked exact child ranges [UID:0002OI][0x00621db8-0x00621e64.PatchPaneVtableData](by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md) and [UID:0002OJ][0x00621f40-0x00621fd8.PatchPane2VtableData](by-memory/0x00621f40-0x00621fd8.PatchPane2VtableData.md).
  - Summary/evidence: IDA MCP `py_eval` on 2026-06-01 read the RTTI/vtable dwords, confirmed constructor/destructor data xrefs to the vtable bases, confirmed adjustor thunk/function extents, and verified the string boundaries at `0x00621e64` and `0x00621fd8`.
