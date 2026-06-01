*** UID:00005X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:75 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GroupListPane

## Status

- Confidence: medium for the class boundary; strong that the constructor is a raw/manual boundary rather than an IDA auto-function.
- Likely source file: [UID:0000JS][Group](by-file/Group.md), pending boundary cleanup
- Memory evidence: [UID:0001H8][0x0056baa0-0x0056bb00.GroupListPaneRawConstructor](by-memory/0x0056baa0-0x0056bb00.GroupListPaneRawConstructor.md), [UID:0001H9][0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs](by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md), exact vtable data [UID:0002NI][0x00624210-0x006242c4.GroupListPaneVtableData](by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md), and [UID:0001XP][GroupPaneFamilyVtables](by-type/by-vtable/GroupPaneFamilyVtables.md); nearby [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md) constructor is not clean group ownership.
- Current recovered file: `source-3/simroot_v2/class_GroupListPane.cpp`

## Class Purpose

`GroupListPane` is the list/text child used by the older `GroupPane` and `GroupPane2` shells. The raw constructor at `0x0056baa0` initializes a text-edit style pane and installs `GroupListPane` vtables at offsets `0`, `0xa0`, and `0xa4`. IDA does not auto-model this start as a function, but the bytes form a normal constructor island and the same setup is inlined inside both parent pane constructors.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GroupListPane` | `0x0056baa0-0x0056bafd` | Raw constructor island; IDA reports no auto-function at the start. |
| trivial virtuals | `0x0056bb00`, `0x0056bb10` | IDA-confirmed small stubs returning zero. |
| nearby constructor-like function | `0x0056bb20-0x0056bbdb` | IDA-confirmed `SpelledPane`/text-edit construction called from other UI code; ownership is not settled. |

## Evidence Notes

- IDA MCP reports no function at `0x0056baa0`, but raw disassembly from `0x0056baa0-0x0056bafd` shows a constructor prologue/body/epilogue and vtable installs.
- `xrefs_to` the `GroupListPane` vtables `0x00624214`, `0x0062428c`, and `0x006242bc` lands in the raw constructor and in the inline child construction inside `GroupPane` and `GroupPane2`.
- 2026-05-31 IDA MCP confirms the exact vtable-data child [UID:0002NI][0x00624210-0x006242c4.GroupListPaneVtableData](by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md): the range starts at the primary RTTI locator and ends before neighboring `SpelledPane` RTTI at `0x006242c4`.
- IDA MCP confirms real nearby functions at `0x0056bb00`, `0x0056bb10`, and `0x0056bb20`.
- IDA decompilation for `0x0056bb20` installs `SpelledPane` vtables and is called from non-group UI functions, so it should not be treated as a clean group-only constructor without more xref/type evidence.

## Cross-References

- [UID:0000JS][Group](by-file/Group.md)
- [UID:0001H8][0x0056baa0-0x0056bb00.GroupListPaneRawConstructor](by-memory/0x0056baa0-0x0056bb00.GroupListPaneRawConstructor.md)
- [UID:0001H9][0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs](by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md)
- [UID:0002NI][0x00624210-0x006242c4.GroupListPaneVtableData](by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md)
- [UID:0001XP][GroupPaneFamilyVtables](by-type/by-vtable/GroupPaneFamilyVtables.md)
- [UID:0001HC][0x0056c4c0-0x0056e939.GroupPanes](by-memory/0x0056c4c0-0x0056e939.GroupPanes.md)
- [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md)
- [UID:00005Y][GroupPane](by-class/GroupPane.md)
- [UID:00005Z][GroupPane2](by-class/GroupPane2.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `70/68`. Summary: raw constructor island, vtable installs, parent inline construction, virtual stubs, and nearby SpelledPane ownership caveat are documented, but the class boundary is only medium-confidence. Evidence: raw constructor page `0x0056baa0-0x0056bb00`, virtual stub page, `GroupPaneFamilyVtables`, parent `GroupPanes` page, and explicit IDA no-function/nearby-function notes.
- 2026-05-31: Added exact vtable-data child and raised metadata from `70/68` to `75/82`.
  - Before: class confidence was capped partly because vtable data was only covered through the broad family page.
  - After: exact vtable-data bounds are linked and IDA-confirmed, while completion remains below final-source level because the raw constructor boundary and final source declaration still need more work.
  - Evidence: IDA MCP `py_eval` and `xrefs_to` checks on `0x00624210-0x006242c4` confirmed the RTTI boundaries and constructor/inline-construction stores.
