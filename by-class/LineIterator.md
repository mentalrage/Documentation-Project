*** UID:000078 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LineIterator

## Status

- Confidence: medium for layout and local helper role.
- Likely source file or local helper: [UID:0000KQ][LineIterator](by-file/LineIterator.md)
- Current generated file: `source-3/simroot_v2/class_LineIterator.cpp`
- Type/layout docs: [UID:0001UY][LineIteratorLayout](by-type/by-struct/LineIteratorLayout.md), [UID:0001XZ][LineIterator_vtable](by-type/by-vtable/LineIterator_vtable.md)

## Class Purpose

`LineIterator` is a small helper used to read newline-delimited text from a memory buffer. The visible use is `SpelledPane::ParseAndLoadEntries`, where generated source and IDA decompilation initialize a 16-byte stack object:

```text
+0x00 vtable
+0x04 data pointer
+0x08 length in UTF-16 code units
+0x0c current offset in UTF-16 code units
```

and then repeatedly calls [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md).

## Methods

| Address | Method | Role |
| --- | --- | --- |
| `0x004f3020` | [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md) | Returns the next UTF-16 line slice and advances the source offset. |
| `0x00573240` | ordinary destructor | Resets the `LineIterator` vtable and returns. |
| `0x00573540` | scalar deleting destructor | Resets vtable, conditionally deletes 16-byte object, returns `this`. |

## Open Issues

`ReadNextLine` is not emitted as an active `LineIterator` method in current generated output, current Wave3 struct metadata only records a 4-byte vtable field, and the generated vtable/string neighborhood at `0x00624784` needs cleanup. Until then, use this page as an ownership note rather than a migration-ready standalone class definition.

2026-05-26 recheck confirms the issue remains current. `lookup_funcs` models `0x004f3020`, `0x00573240`, and `0x00573540`; `xrefs_to 0x00624784` still shows only the stack construction and destructor vtable stores, while `xrefs_to 0x00624788` points to self-look rendering code that uses the adjacent `LOOKEXT.EPF` string.

2026-05-31 IDA MCP recheck confirms the same shape: `sub_4F3020` is called only by `sub_56C0E0` at `0x0056c15b` and `0x0056c285`; `sub_56C0E0` constructs a four-dword stack object with the vtable, data pointer, length, and zero offset; `0x00624784` contains only the scalar deleting destructor slot before the adjacent `LOOKEXT.EPF` string. The class/local-helper construct is reconstructable, but parent attachment and C++ emission are intentionally blank until final placement and original declaration form clear the 95+ threshold.

## Cross-References

- [UID:0000KQ][LineIterator](by-file/LineIterator.md)
- [UID:0001UY][LineIteratorLayout](by-type/by-struct/LineIteratorLayout.md)
- [UID:0001XZ][LineIterator_vtable](by-type/by-vtable/LineIterator_vtable.md)
- [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md)
- [UID:0001HL][0x00573240-0x00573247.LineIteratorDestructor](by-memory/0x00573240-0x00573247.LineIteratorDestructor.md)
- [UID:0001HO][0x00573540-0x00573564.LineIteratorScalarDeletingDestructor](by-memory/0x00573540-0x00573564.LineIteratorScalarDeletingDestructor.md)
- [UID:0000DK][SpelledPane](by-class/SpelledPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `70/68`. Summary: the helper layout, read-next-line role, destructor addresses, vtable neighborhood, and owner caveats are documented, but this is still not a migration-ready standalone class definition. Evidence: stack-object layout in `SpelledPane::ParseAndLoadEntries`, linked read-line/destructor memory pages, and open Wave3/vtable metadata cleanup notes.
- 2026-05-31 scoring and reconstructable classification:
  - What existed before: `COMPLETION:70`, `CONFIDENCE:68`, and blank `RECONSTRUCTABLE`.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:82`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: current IDA MCP reverified the read-line callers, stack layout, vtable slot, destructor stores, and adjacent string boundary. Scores remain below 95 because final original source placement and declaration style are still unresolved.
