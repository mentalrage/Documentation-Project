*** UID:00005X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GroupListPane

## Status

- Confidence: strong for raw constructor bytes, vtable identity, and `Group.cpp` source placement; medium-high for final source declaration shape because the standalone constructor is not an IDA auto-function and the same setup is also inlined into parent constructors.
- Likely source file: [UID:0000JS][Group](by-file/Group.md)
- Memory evidence: [UID:0001H8][0x0056baa0-0x0056bb00.GroupListPaneRawConstructor](by-memory/0x0056baa0-0x0056bb00.GroupListPaneRawConstructor.md), [UID:0001H9][0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs](by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md), exact vtable data [UID:0002NI][0x00624210-0x006242c4.GroupListPaneVtableData](by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md), and [UID:0001XP][GroupPaneFamilyVtables](by-type/by-vtable/GroupPaneFamilyVtables.md); nearby [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md) constructor is not clean group ownership.
- Generated recovery hint: `source-3/simroot_v2/class_GroupListPane.cpp`; use as a lead only because IDA has no auto-function at the projected constructor start.

## Class Purpose

`GroupListPane` is the list/text child used by the older `GroupPane` and `GroupPane2` shells. The raw constructor at `0x0056baa0` initializes a text-edit style pane and installs `GroupListPane` vtables at offsets `0`, `0xa0`, and `0xa4`. IDA does not auto-model this start as a function, but the bytes form a normal constructor island and the same setup is inlined inside both parent pane constructors.

The source-level reconstruction should preserve a `GroupListPane` child type under [UID:0000JS][Group](by-file/Group.md), while keeping the nearby `SpelledPane` constructor at `0x0056bb20` outside the class. The current documentation is strong enough for parent attachment, but not for final C++ emission because the base text/list helper names and exact original virtual names are not final.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GroupListPane` | `0x0056baa0-0x0056bafd` | Raw constructor island; IDA reports no auto-function at the start. |
| trivial virtuals | `0x0056bb00`, `0x0056bb10` | IDA-confirmed small stubs returning zero. |
| nearby constructor-like function | `0x0056bb20-0x0056bbdb` | IDA-confirmed `SpelledPane`/text-edit construction called from other UI code; ownership is not settled. |

## Constructor And Inline Setup

[UID:0001H8][0x0056baa0-0x0056bb00.GroupListPaneRawConstructor](by-memory/0x0056baa0-0x0056bb00.GroupListPaneRawConstructor.md) records the standalone raw constructor-shaped body. It reads the shared context at `dword_67AB24`, calls `sub_4B60B0`, calls `sub_58DCE0` with fixed group-list dimensions `145 x 84`, installs the three `GroupListPane` vtable views, returns `this`, and ends at `0x0056bafd` followed by `0xcc` alignment.

The same memory page also records that `GroupPane` and `GroupPane2` inline the same child setup inside their constructors: both allocate a `0x174`-byte child, run the same `sub_4B60B0`/`sub_58DCE0` sequence, install the same three vtables, store the child at parent offset `+0xf8`, enable it, and position/update it. This makes `GroupListPane` a real source-level child type even though the standalone constructor start is a raw/manual boundary.

## Touched State And ABI Evidence

| State / data | Evidence | Class-level meaning |
| --- | --- | --- |
| `dword_67AB24` | Read by the raw constructor and by the inline child construction paths in `GroupPane` / `GroupPane2`. | Shared UI/resource context used to initialize the group-list child. |
| `sub_4B60B0` | Called by the raw and inline construction paths before the base setup call. | Produces the resource/context pointer consumed by the text/list initializer; final name still unresolved. |
| `sub_58DCE0` | Called with the same `145 x 84` and flag pattern in all three construction forms. | Text-edit/list base construction for the group-list child. |
| `0x00624214`, `0x0062428c`, `0x006242bc` | Exact vtable stores recorded in [UID:0001H8][0x0056baa0-0x0056bb00.GroupListPaneRawConstructor](by-memory/0x0056baa0-0x0056bb00.GroupListPaneRawConstructor.md) and exact data range [UID:0002NI][0x00624210-0x006242c4.GroupListPaneVtableData](by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md). | Primary, secondary, and tertiary `GroupListPane` vtable views. |
| `0x0056bb00`, `0x0056bb10` | [UID:0001H9][0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs](by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md) records two five-byte `return false` virtual stubs referenced only from vtable slots. | Confirms source-declared virtual overrides/default handlers, but original names remain open. |
| `0x0056bb20` | [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md) has non-group callers. | Keep the following text/spelled pane constructor out of `GroupListPane` ownership. |

## Evidence Notes

- IDA MCP reports no function at `0x0056baa0`, but raw disassembly from `0x0056baa0-0x0056bafd` shows a constructor prologue/body/epilogue and vtable installs.
- `xrefs_to` the `GroupListPane` vtables `0x00624214`, `0x0062428c`, and `0x006242bc` lands in the raw constructor and in the inline child construction inside `GroupPane` and `GroupPane2`.
- 2026-05-31 IDA MCP confirms the exact vtable-data child [UID:0002NI][0x00624210-0x006242c4.GroupListPaneVtableData](by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md): the range starts at the primary RTTI locator and ends before neighboring `SpelledPane` RTTI at `0x006242c4`.
- IDA MCP confirms real nearby functions at `0x0056bb00`, `0x0056bb10`, and `0x0056bb20`.
- IDA decompilation for `0x0056bb20` installs `SpelledPane` vtables and is called from non-group UI functions, so it should not be treated as a clean group-only constructor without more xref/type evidence.

## Autogen Handling

Attach this class to [UID:0000JS][Group](by-file/Group.md). The parent is `88/80`, and this class is now `80/84`; the class and source owner satisfy the parent-attachment gate. Keep `RECONSTRUCTION_CPP CODE` blank because the class hierarchy, base initializer names, virtual stub names, and source-ready constructor declaration remain below the 95/95 final-source gate.

## Score Rationale

Completion is raised to `80` because the class page now records raw constructor behavior, inline parent construction parity, vtable/stub ABI evidence, touched-state dependencies, SpelledPane exclusion, source-owner attachment, and final-C++ blockers. Confidence rises to `84` because the raw bytes, vtable stores, inline construction, and exact vtable-data child are IDA-backed in linked pages; it remains below final-audit confidence because the constructor is still a manual boundary and exact source declarations are unresolved.

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

- 2026-06-07: Raised `75/82` to `80/84` and attached `AUTOGEN_PARENT_UID:0000JS`. The page now records the raw constructor behavior, inline setup parity in `GroupPane` and `GroupPane2`, touched state, vtable/stub evidence, `SpelledPane` exclusion, parent-attachment rationale, and final-source blockers. Evidence comes from [UID:0001H8][0x0056baa0-0x0056bb00.GroupListPaneRawConstructor](by-memory/0x0056baa0-0x0056bb00.GroupListPaneRawConstructor.md), [UID:0001H9][0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs](by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md), [UID:0002NI][0x00624210-0x006242c4.GroupListPaneVtableData](by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md), and [UID:0000JS][Group](by-file/Group.md).
- Completion/confidence score update: existed before as `0/0`; changed to `70/68`. Summary: raw constructor island, vtable installs, parent inline construction, virtual stubs, and nearby SpelledPane ownership caveat are documented, but the class boundary is only medium-confidence. Evidence: raw constructor page `0x0056baa0-0x0056bb00`, virtual stub page, `GroupPaneFamilyVtables`, parent `GroupPanes` page, and explicit IDA no-function/nearby-function notes.
- 2026-05-31: Added exact vtable-data child and raised metadata from `70/68` to `75/82`.
  - Before: class confidence was capped partly because vtable data was only covered through the broad family page.
  - After: exact vtable-data bounds are linked and IDA-confirmed, while completion remains below final-source level because the raw constructor boundary and final source declaration still need more work.
  - Evidence: IDA MCP `py_eval` and `xrefs_to` checks on `0x00624210-0x006242c4` confirmed the RTTI boundaries and constructor/inline-construction stores.
