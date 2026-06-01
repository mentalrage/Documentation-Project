*** UID:00007D | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LObject

## Status

- Likely original source: [UID:0000KV][LObject](by-file/LObject.md)
- Confidence: strong for runtime/base-object identity; medium for the generated string-method split into [UID:0000OA][StringBase](by-file/StringBase.md).
- Current generated file: `source-3/simroot_v2/class_LObject.cpp`
- Import source file: `LObject.cpp`

## Responsibility

`LObject` is currently a polluted recovered owner. The reliable base-object surface is tiny: a no-op virtual slot, a constructor that installs the vtable, a runtime-class accessor, and a scalar-deleting destructor.

The same generated class also owns a large reference-counted string implementation. That string code has real behavior and real IDA-confirmed boundaries, but its first field is used as a character-buffer pointer, not as the same vtable field used by the base-object shell. Treat the string methods as [UID:0000OA][StringBase](by-file/StringBase.md) / string-utility code until layout reconciliation is complete.

## Method Families

| Range | Current names | Assessment |
| --- | --- | --- |
| [UID:0000WM][0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual](by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md) | `VirtualNoop` | Real no-op virtual function. |
| `0x004f4a80-0x004f4c0d` | constructor, `GetRuntimeClass`, runtime-class membership shim, scalar deleting destructor | Real base/runtime shell immediately before `LogoPane`. |
| [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md) | runtime-class callback and membership helpers | Raw helper island reached by the `0x004f4b20` tail-jump shim; final declaration owner still open. |
| `0x00582500-0x00583206` | ANSI/wide construction, conversion, assignment, allocation, COW, suffix checks | Ref-counted string implementation prefix. |
| `0x005832f0-0x00584d7e` | release, length/capacity, format, trim, append, find, splice, substring | Later string implementation family; see [UID:0001J3][0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation.md). |
| `0x004b3400-0x004b3d41` | tree traversal/layout/search helpers | Misattributed; belongs with [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md). |

## Layout Notes

The string-buffer family uses a shared 12-byte header before the character data:

- `refCount` at data pointer minus `0x0c`;
- `length` at data pointer minus `0x08`;
- `capacity` at data pointer minus `0x04`;
- ANSI buffers terminate with one byte; wide buffers terminate with one UTF-16 element.

Generated globals include empty sentinels (`g_emptyAnsiBuffer`, `g_emptyAnsiString`, `g_emptyWideBuffer`, `g_emptyWideString`) and fixed-size pool allocators for 64/128/256/512 byte or character capacities. See [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md) and [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md).

## Open Questions

- Whether the original project used a separate `StringBase.cpp` source file or kept `mystr::StringBase` inline/near `StringUtil.cpp`.
- Whether `SimpleUString` is a typedef/facade over `mystr::StringBase<wchar_t>` or a separate sibling string type.
- Exact declaration ownership for the empty string sentinels and pool globals; current docs place them with string utilities, not the base-object shell.
- Exact declaration owner/name for the runtime-class callback and membership helper island at [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md).

## Cross-References

- [UID:0000KV][LObject](by-file/LObject.md)
- [UID:0000OB][StringUtil](by-file/StringUtil.md)
- [UID:0000OA][StringBase](by-file/StringBase.md)
- [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md)
- [UID:0001QS][client_string_handling](by-meta/client_string_handling.md)
- [UID:000195][0x004f4a80-0x004f4c0d.LObjectRuntimeShell](by-memory/0x004f4a80-0x004f4c0d.LObjectRuntimeShell.md)
- [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md)
- [UID:0000WM][0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual](by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md)
- [UID:0001J1][0x00582500-0x00583206.LObjectStringConstructionAndCow](by-memory/0x00582500-0x00583206.LObjectStringConstructionAndCow.md)
- [UID:0001J3][0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation.md)
- [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md)
- [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `78/76`. Summary: the page now has enough detail to remove it from unevaluated work, with strong base-object and string-buffer family mapping but capped confidence because generated ownership is still polluted. Evidence: documented runtime shell, no-op virtual, string construction/COW ranges, string mutation range, buffer header layout, sentinel/pool globals, and FolderTreePane misattribution.
- 2026-06-01: Added runtime-class callback/membership helper evidence from the low-score by-memory pass.
  - Evidence: IDA MCP disassembly shows the `0x004f4b20` shim calls vtable slot `+4` and tail-jumps to [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md), where raw helpers call a create/callback pointer at `+0x8` and walk a base-list chain through `+0x0c`.
