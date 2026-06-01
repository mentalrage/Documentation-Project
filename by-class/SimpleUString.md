*** UID:0000D9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:62 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SimpleUString

## Summary

`SimpleUString` is shared UTF-16 string infrastructure. Current recovery shows two related surfaces under the same canonical class:

- an early SSO-7 counted wide-string layout at the exact endpoint helpers `0x00421310-0x00421362` and `0x00421590-0x004216cb`;
- a pointer-backed formatted-string family around `0x00583210`, `0x00583280`, and `0x005845b0`.

The relationship between those two representations still needs a layout pass. Both are currently documented under `SimpleUString` because Wave2/Wave3 metadata and caller evidence point there, but source migration should preserve the distinction. The pointer-backed family now has a preferred neighboring owner candidate in [UID:0000OA][StringBase](by-file/StringBase.md), because callback-template metadata preserves `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>`.

## Likely Original Placement

- Source: [UID:0000OB][StringUtil](by-file/StringUtil.md)
- Proposed path: `util/StringUtil.cpp`, with pointer-backed helpers possibly in `util/StringBase.cpp`
- Confidence: medium

## Method Families

| Range | Role |
| --- | --- |
| [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md) | `Clear`: frees heap storage when present and resets the SSO-7 wide string to empty. |
| [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md) | counted wide-source constructor/copy helper with SSO-7 growth logic. |
| [UID:0002LJ][0x00583210-0x00583272.StringBaseAnsiFormatCtor](by-memory/0x00583210-0x00583272.StringBaseAnsiFormatCtor.md) | ANSI varargs initializer wrapper, forwards to the ANSI formatting worker. |
| [UID:0002LK][0x00583280-0x005832e2.StringBaseWideFormatCtor](by-memory/0x00583280-0x005832e2.StringBaseWideFormatCtor.md) | Wide varargs initializer wrapper, forwards to the wide formatting worker. |
| [UID:0002LL][0x00583720-0x00583831.StringBaseAnsiVFormatWorker](by-memory/0x00583720-0x00583831.StringBaseAnsiVFormatWorker.md) | ANSI `va_list` formatting worker for the pointer-backed ref-counted buffer. |
| [UID:0002LM][0x00583840-0x00583967.StringBaseWideVFormatWorker](by-memory/0x00583840-0x00583967.StringBaseWideVFormatWorker.md) | UTF-16 `va_list` formatting worker for the pointer-backed ref-counted buffer. |
| [UID:0002LN][0x005840f0-0x00584159.WideRangeCompare](by-memory/0x005840f0-0x00584159.WideRangeCompare.md) | Lexicographic UTF-16 range comparator. |
| [UID:0002LO][0x005845b0-0x005845eb.StringBaseCompareWideLiteral](by-memory/0x005845b0-0x005845eb.StringBaseCompareWideLiteral.md) | Compares a stored wide string against a NUL-terminated wide literal. |

## Evidence

- `0x00421590` has broad constructor/copy-style caller fan-in from startup, UI/resource helpers, collection dialogs, and other systems.
- The historical [UID:0000WT][0x00421310-0x004216cb.SimpleUStringSso7](by-memory/0x00421310-0x004216cb.SimpleUStringSso7.md) page is now an aggregate only. IDA MCP confirms the middle functions are pane/fitting-room/checkbox/runtime helpers, not `SimpleUString` code.
- `0x00583280` has broad caller fan-in from `Application`, startup, patch, browser, sound, virus-checker, and UI helper paths.
- `0x00583210` is used by SoundManager-style track-name formatting paths to build `%08d.MP3` names.
- `0x005845b0` callers include SelfSaveOKPane and WorldMapPane-style compare paths.
- IDA MCP decompilation confirms the pointer-backed formatting workers use the 12-byte ref-counted header described by [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md), including `refCount`, `length`, and `capacity` fields immediately before the data pointer.
- Generated metadata explicitly notes the SSO-7 wide-string subcluster and warns that nearby SSO-15 byte-string helpers remain intentionally separate.

## Open Questions

- Whether the early SSO-7 layout and the pointer-backed `StringBase` layout were separate original template instantiations sharing the `SimpleUString` name, or whether current metadata is collapsing adjacent string classes.
- Final ownership of the full `0x00582b70-0x005851d9` string helper neighborhood.
- Names for formatting workers at `0x00583720` and `0x00583840`.
- Whether the release/format/mutation continuation at `0x005832f0-0x00584d7e` belongs under this class name or a neighboring string-base type.

## Cross-References

- File: [UID:0000OB][StringUtil](by-file/StringUtil.md)
- File: [UID:0000OA][StringBase](by-file/StringBase.md)
- Memory: [UID:0000WT][0x00421310-0x004216cb.SimpleUStringSso7](by-memory/0x00421310-0x004216cb.SimpleUStringSso7.md), [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md), [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md), [UID:0001J2][0x00583210-0x005845eb.SimpleUStringPointerBacked](by-memory/0x00583210-0x005845eb.SimpleUStringPointerBacked.md), [UID:0001J3][0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation.md), [UID:0002LJ][0x00583210-0x00583272.StringBaseAnsiFormatCtor](by-memory/0x00583210-0x00583272.StringBaseAnsiFormatCtor.md), [UID:0002LK][0x00583280-0x005832e2.StringBaseWideFormatCtor](by-memory/0x00583280-0x005832e2.StringBaseWideFormatCtor.md), [UID:0002LL][0x00583720-0x00583831.StringBaseAnsiVFormatWorker](by-memory/0x00583720-0x00583831.StringBaseAnsiVFormatWorker.md), [UID:0002LM][0x00583840-0x00583967.StringBaseWideVFormatWorker](by-memory/0x00583840-0x00583967.StringBaseWideVFormatWorker.md), [UID:0002LN][0x005840f0-0x00584159.WideRangeCompare](by-memory/0x005840f0-0x00584159.WideRangeCompare.md), [UID:0002LO][0x005845b0-0x005845eb.StringBaseCompareWideLiteral](by-memory/0x005845b0-0x005845eb.StringBaseCompareWideLiteral.md)
- Related classes: [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md), [UID:0000E7][StringIter](by-class/StringIter.md)
- Layouts: [UID:0001W5][SimpleUStringSso7Layout](by-type/by-struct/SimpleUStringSso7Layout.md), [UID:0001W4][SimpleUStringPointerBackedLayout](by-type/by-struct/SimpleUStringPointerBackedLayout.md), [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md)

## Changes

- 2026-05-30: Existing class summary treated `0x00421310-0x004216cb` as one early `SimpleUString` helper neighborhood. Changed this to endpoint-only `SimpleUString` ownership and linked the exact child pages, while retaining the historical aggregate as a mixed-island map. Evidence: IDA MCP function inventory/decompilation/byte audit for `0x00421310-0x004216cb`; `simroot_v2/class_SimpleUString.cpp` emits only the `0x00421310` and `0x00421590` helpers from that island.

- 2026-05-31: The pointer-backed family now links exact IDA-confirmed child pages for the formatting constructors/workers and wide compare helpers.
  - Before: the class page listed only raw address rows for the pointer-backed family and left reconstructable metadata blank.
  - After: marked the class reconstructable, linked exact split memory pages, and raised scores modestly to reflect verified boundaries and behavior.
  - Evidence: IDA MCP `lookup_funcs`, `decompile`, `callers`, `callees`, sentinel `xrefs_to`, and byte checks for `0x00583210`, `0x00583280`, `0x00583720`, `0x00583840`, `0x005840f0`, and `0x005845b0`.
