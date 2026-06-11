*** UID:0000DF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SortedList

## Status

- Confidence: strong for layout and core methods; medium for final file split.
- Likely source file: [UID:0000NU][SortedList](by-file/SortedList.md) or [UID:0000KS][List](by-file/List.md)
- Autogen parent: [UID:0000NU][SortedList](by-file/SortedList.md)
- Main memory range: [UID:000193][0x004f3600-0x004f3a43.SortedList](by-memory/0x004f3600-0x004f3a43.SortedList.md)
- Historical generated source candidate: `class_SortedList.cpp`; use only as search context, not as authority.

## Class Purpose

`SortedList` is a small sorted fixed-width array container derived from [UID:000079][List](by-class/List.md). It keeps the same base layout and adds a compare callback at `+0x14`. It is used where callers need sorted insertion and lookup rather than only append/index operations.

## Observed Layout

```text
+0x00  vtable
+0x04  int elementSize
+0x08  int pageSize
+0x0c  int count
+0x10  void* data
+0x14  int (__cdecl* compare)(const void*, const void*)
```

The generated `sortContext` name for `+0x14` is misleading. IDA decompilation of `0x004f3690` and `0x004f3780` calls it as a comparator function pointer.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x004f3600-0x004f3681` | `SortedList::SortedList` | Builds the base `List`, stores the comparator, then switches to the `SortedList` vtable. |
| `0x004f3690-0x004f377b` | likely `InsertSorted` | Finds the ordered insertion point with the comparator, grows the buffer, shifts trailing elements, inserts the new record, and returns its index. |
| `0x004f3780-0x004f3803` | likely `FindFirstEqual` | Uses `bsearch`, converts the hit pointer to an index, then scans backward to the first equal record. |
| `0x004f38b0-0x004f3947` | `SortedList::~SortedList` | Frees the backing buffer, destroys `LObject`, and optionally deletes `this`. |
| `0x004f3950-0x004f397a` | `SortedList::GetElementAt` | Same bounds/data behavior as `List::GetElementAt`. |
| `0x004f3980-0x004f398b` | `SortedList::Clear` | Removes all current elements through the virtual remove-range slot. |
| `0x004f3990-0x004f3a43` | `SortedList::RemoveRange` | Shifts elements down and shrinks chunk allocation when possible. |

## Ownership Notes

Older generated output omitted the non-virtual helper methods at `0x004f3690` and `0x004f3780`. IDA confirms both are real functions between the constructor and destructor. The known helper callers are [UID:0000I2][ChangeMan](by-file/ChangeMan.md) registration/dispatch wrappers at `0x0047ed50`, `0x0047ed80`, and `0x0047ee20`, which store and query `ChangeManEntry` records in a sorted list.

For reconstructed source, keep these helpers with `SortedList` even if older generated class files did not emit them.

## Cross-References

- [UID:0000NU][SortedList](by-file/SortedList.md)
- [UID:000193][0x004f3600-0x004f3a43.SortedList](by-memory/0x004f3600-0x004f3a43.SortedList.md)
- [UID:000079][List](by-class/List.md)
- [UID:00001K][ChangeMan](by-class/ChangeMan.md)
- [UID:0000ZX][0x0047ed50-0x0047ee18.ChangeManRegistrationMethods](by-memory/0x0047ed50-0x0047ee18.ChangeManRegistrationMethods.md)
- [UID:000084][Message](by-class/Message.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `82`.
- Evidence: the page documents layout, comparator field correction, method map, omitted helper ownership, caller evidence, and source-placement options; confidence remains capped by final file split uncertainty.
- 2026-06-05: Marked reconstructable and left unassigned.
- Evidence: live IDA MCP `lookup_funcs` confirms the constructor, sorted insert/search helpers, destructor, access, clear, and remove-range anchors at `0x004f3600`, `0x004f3690`, `0x004f3780`, `0x004f38b0`, `0x004f3950`, `0x004f3980`, and `0x004f3990`. The likely standalone parent [UID:0000NU][SortedList](by-file/SortedList.md) is only `80/78`, so the parent UID stays blank.
- 2026-06-06 parent attachment:
  - Before: confidence was `82`, generated-source wording was still present, and `AUTOGEN_PARENT_UID` stayed blank because the file parent was only `80/78`.
  - Changed to: confidence `84`, `AUTOGEN_PARENT_UID:0000NU`, and generated-source names demoted to search context only.
  - Evidence: [UID:0000NU][SortedList](by-file/SortedList.md) is now `84/84`, this class is `86/84`, and both clear the 80/80 parent gate. The exact source split from [UID:0000KS][List](by-file/List.md) remains a caveat, so C++ remains blank.
