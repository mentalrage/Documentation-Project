*** UID:0001YF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

## 2026-06-07 Live IDA Refresh

- IDA MCP `py_eval` reconfirmed every dword in the exact [UID:0002OI][0x00621db8-0x00621e64.PatchPaneVtableData](by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md) child range. The sequence is `PatchFileSlice` RTTI/vtable, `PatchFileData` RTTI/vtable, `PatchPane` primary RTTI/vtable, `PatchPane` secondary RTTI/vtable, and `PatchPane` tertiary RTTI/vtable.
- PatchPane table-base store xrefs remain complete: `0x00621dbc` from `0x005483a0`, `0x00548413`, and `0x005484a2`; `0x00621dc4` from `0x00547119`, `0x00547493`, `0x005483c9`, `0x0054850c`, and `0x0054860a`; `0x00621dcc` from `0x005470fd`, `0x0054741e`, and `0x00548598`; `0x00621e2c` from `0x00547105`, `0x00547427`, and `0x0054859e`; and `0x00621e5c` from `0x0054710f`, `0x00547431`, and `0x005485a8`.
- The same pass reconfirmed every dword in the exact [UID:0002OJ][0x00621f40-0x00621fd8.PatchPane2VtableData](by-memory/0x00621f40-0x00621fd8.PatchPane2VtableData.md) child range: primary table `0x00621f40-0x00621f9c`, secondary RTTI/table `0x00621f9c-0x00621fcc`, and tertiary RTTI/table `0x00621fcc-0x00621fd8`.
- PatchPane2 table-base store xrefs remain complete: `0x00621f40` from `0x00548709`, `0x00548a19`, and `0x0054937c`; `0x00621fa0` from `0x0054870f`, `0x00548a1f`, and `0x00549382`; and `0x00621fd0` from `0x00548719`, `0x00548a29`, and `0x0054938c`.
- Function-boundary checks resolve the key owned slot targets: `PatchPane` scalar deleting destructor `0x00548560-0x00548685`, PatchPane thunks `0x005484db-0x005484e6` and `0x005484e6-0x005484f1`, packet callback `0x005474f0-0x00547850`, action/timer callback `0x00547860-0x00547947`, `PatchPane2` scalar deleting destructor `0x00549370-0x0054940f`, PatchPane2 thunks `0x0054934b-0x00549356` and `0x00549356-0x00549361`, work-event predicate `0x00548f30-0x00548f41`, and main work-event loop `0x00548a80-0x00548f1a`.
- Boundary bytes still prove the vtable islands stop before adjacent source literals: `0x00621e64` is `aAutoPatch` with string xref `0x005470ed`, and `0x00621fd8` is `Patcher.exe.new` storage with data xref `0x005489d3`.

## 2026-06-08 Batch133 Live IDA Recheck

- IDA MCP `idb_meta` rechecked `NexusTK.exe` `sha256 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- A focused `py_eval` read reconfirmed the PatchPane dword chain from `0x00621db8` through `0x00621e64`: `PatchFileSlice` locator/table, `PatchFileData` locator/table, `PatchPane` primary locator/table, `PatchPane` secondary locator/table, tertiary locator/table, then `aAutoPatch`.
- The same pass reconfirmed the PatchPane2 table starts at `0x00621f40`, secondary locator/table at `0x00621f9c/0x00621fa0`, tertiary locator/table at `0x00621fcc/0x00621fd0`, and `off_621FD8` UTF-16 storage at `0x00621fd8`.
- Function metadata remained stable for the key slot targets: `0x005474f0-0x00547850`, `0x00547860-0x00547947`, `0x005484db-0x005484f1`, `0x00548560-0x00548685`, `0x00548a80-0x00548f1a`, `0x00548f30-0x00548f41`, `0x0054934b-0x00549361`, and `0x00549370-0x0054940f`.

## Assignment Gate

- `AUTOGEN_PARENT_UID` now points to [UID:0000MH][PatchPane](by-file/PatchPane.md). This type page is scored `86/92`, the direct source-file parent is scored `88/85`, and the source-file page owns the combined `PatchPane`, `PatchPane2`, `PatchPane::PatchFileData`, and `PatchPane::PatchFileSlice` declarations that emit this vtable family.
- The exact vtable-data memory children [UID:0002OI][0x00621db8-0x00621e64.PatchPaneVtableData](by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md) and [UID:0002OJ][0x00621f40-0x00621fd8.PatchPane2VtableData](by-memory/0x00621f40-0x00621fd8.PatchPane2VtableData.md) keep this page as their type/layout evidence anchor. Their autogen parent is the direct source-file owner rather than this type page because the corrected source parent now clears `85/85` and the prior by-vtable memory-parent path produced generated coverage errors.
- This page is not used as the parent for the mixed [UID:000264][0x00621db8-0x00622034.PatchPaneReadOnlyData](by-memory/0x00621db8-0x00622034.PatchPaneReadOnlyData.md) aggregate because that aggregate also owns patcher string literals outside the vtable-family type layout.

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

- 2026-06-08 A005 Batch133:
  - What existed before: this page was scored `86/92` but had a blank `AUTOGEN_PARENT_UID`, leaving the type page itself unassigned even though [UID:0000MH][PatchPane](by-file/PatchPane.md) had since been refreshed to `88/85`.
  - Changed to: set `AUTOGEN_PARENT_UID:0000MH`, added a fresh live IDA recheck, and rewrote the assignment gate to use the direct source-file parent while preserving this page as the evidence anchor for the exact vtable-data children.
  - Summary/evidence: live IDA MCP reconfirmed the PatchPane/PatchPane2 dword boundaries, table-base xrefs, key slot target function bounds, and the two string boundaries. The child `86/92` and direct parent `88/85` satisfy the corrected gate; no score change was needed.
- 2026-06-07 A002 Batch 062 coverage-error repair:
  - What changed: updated the assignment-gate wording to say this page remains the PatchPane/PatchPane2 vtable-family evidence anchor, but is not currently retained as `AUTOGEN_PARENT_UID` for the exact memory children.
  - Summary/evidence: validator file-mode sees `0001YF`, but generated autogen memory coverage reports `0002OI -> 0001YF` and `0002OJ -> 0001YF` as `autogen_parent_unknown`. The memory children now keep this page as a cross-reference and stay unassigned until by-vtable autogen parenting is supported or direct source owners clear the strict 85/85 gate.
- 2026-06-01:
  - What existed before: this vtable-family page had strong table/slot evidence, but the validator-tracked completion/confidence header remained `0/0`, there were no exact `by-memory` child pages for the two separated vtable-data islands, and the parent read-only-data aggregate started at the first `PatchFileSlice` vtable slot instead of its RTTI pointer.
  - Changed to: scored the page as a strong but non-final vtable inventory, marked it reconstructable, and linked exact child ranges [UID:0002OI][0x00621db8-0x00621e64.PatchPaneVtableData](by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md) and [UID:0002OJ][0x00621f40-0x00621fd8.PatchPane2VtableData](by-memory/0x00621f40-0x00621fd8.PatchPane2VtableData.md).
  - Summary/evidence: IDA MCP `py_eval` on 2026-06-01 read the RTTI/vtable dwords, confirmed constructor/destructor data xrefs to the vtable bases, confirmed adjustor thunk/function extents, and verified the string boundaries at `0x00621e64` and `0x00621fd8`.
- 2026-06-07 A007 Batch012 associated-parent refresh:
  - What existed before: `COMPLETION:84`, `CONFIDENCE:90`, and the page was just below the corrected 85/85 parent gate for assigning the exact vtable-data child pages.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:92`, live IDA refresh evidence, and an explicit assignment-gate note for the two exact vtable child ranges.
  - Summary/evidence: live IDA MCP reconfirmed every dword in both exact child vtable-data ranges, all table-base xref sets, key destructor/thunk/callback function extents, and the string boundaries at `0x00621e64` and `0x00621fd8`. The mixed read-only-data aggregate remains unassigned to this type page because it includes patcher string literals outside the vtable-family layout.
