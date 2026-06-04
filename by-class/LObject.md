*** UID:00007D | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LObject

## Status

- Likely original source: [UID:0000KV][LObject](by-file/LObject.md)
- Confidence: strong for runtime/base-object identity and source file placement; medium-high for the neighboring string-method split into [UID:0000OA][StringBase](by-file/StringBase.md).
- Autogen handling: attached to [UID:0000KV][LObject](by-file/LObject.md); C++ remains blank because the declaration, runtime-class type names, and helper ownership are still below the 95+ final-source gate.
- Import source file: `LObject.cpp`

## Responsibility

`LObject` is the tiny runtime/base-object shell: a no-op virtual slot, a constructor that installs the vtable, a runtime-class accessor, and a scalar-deleting destructor.

Historical recovered ownership also grouped a large reference-counted string implementation under `LObject`. That string code has real behavior and real IDA-confirmed boundaries, but its first field is used as a character-buffer pointer, not as the same vtable field used by the base-object shell. Treat the string methods as [UID:0000OA][StringBase](by-file/StringBase.md) / string-utility code until layout reconciliation is complete.

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

The string-buffer docs include empty sentinels (`g_emptyAnsiBuffer`, `g_emptyAnsiString`, `g_emptyWideBuffer`, `g_emptyWideString`) and fixed-size pool allocators for 64/128/256/512 byte or character capacities. See [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md) and [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md).

## Open Questions

- Whether the original project used a separate `StringBase.cpp` source file or kept `mystr::StringBase` inline/near `StringUtil.cpp`.
- Whether `SimpleUString` is a typedef/facade over `mystr::StringBase<wchar_t>` or a separate sibling string type.
- Exact declaration ownership for the empty string sentinels and pool globals; current docs place them with string utilities, not the base-object shell.
- Exact declaration owner/name for the runtime-class callback and membership helper island at [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md).

## Live IDA Evidence

- 2026-06-04 IDA MCP reports exact runtime-shell functions at `0x004f4a80-0x004f4a89`, `0x004f4a90-0x004f4a97`, `0x004f4b10-0x004f4b16`, and `0x004f4b90-0x004f4c0d`; the `0x004f4b20-0x004f4b30` membership shim remains raw bytes, not an IDA function object.
- The constructor and destructor-body stores at `0x004f4a80` and `0x004f4a90`, plus the scalar deleting destructor store at `0x004f4bb8`, are the only IDA xrefs to the `LObject` vtable address `0x0061cf68`.
- The `0x0061cf68` vtable entries are `0x004f4b90` (scalar deleting destructor), `0x004f4b10` (runtime-class accessor), and [UID:0000WM][0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual](by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md) (default no-op virtual), followed by the next class's RTTI pointer at `0x0061cf74`.
- The runtime-class record at `0x0061cf44` points to the wide string `LObject`, records size `4`, and is referenced only by the `0x004f4b10` accessor.
- The raw `0x004f4b20` membership shim calls vtable slot `+4` and tail-jumps to [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md), whose live disassembly walks the runtime-class base chain through offset `+0x0c`; the sibling `0x005568d0` helper jumps through optional callback pointer `+0x8`.
- IDA xrefs for the string helpers (`0x00582500`, `0x00582d80`, `0x00583210`, `0x00583280`, `0x005832f0`, `0x00583720`, `0x00583840`, `0x005845b0`) are ordinary string/format/copy-on-write callers and do not use the `LObject` vtable/runtime-class shell.
- IDA xrefs for `0x004b3400`, `0x004b3650`, `0x004b3850`, and `0x004b3af0` all come from the local FolderTreePane helper cluster, supporting their exclusion from `LObject`.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 82 | The class page now records the exact runtime shell, default no-op virtual, runtime-class shim/helper island, vtable/runtime-class data, string-family split, FolderTreePane false ownership, and file-parent attachment. Completion remains capped because final C++ and exact runtime-class helper declarations are still unresolved. |
| Confidence | 84 | Live IDA gives strong evidence for the base-object identity and `LObject.cpp` file placement: only the constructor/destructor shell writes the `LObject` vtable, the runtime-class accessor is data-table backed, and the non-`LObject` helper families have separate caller patterns. Confidence remains below final-audit level because the string utility split and helper declarations still need source-quality names. |
| Reconstructable | true | This is source-authored base-object code, but the reconstruction block stays blank until the 95+ code gate is met. |

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

- Completion/confidence score update: existed before as `0/0`; changed to `78/76`. Summary: the page had enough detail to remove it from unevaluated work, with strong base-object and string-buffer family mapping but capped confidence because recovered ownership was still polluted. Evidence: documented runtime shell, no-op virtual, string construction/COW ranges, string mutation range, buffer header layout, sentinel/pool globals, and FolderTreePane misattribution.
- 2026-06-01: Added runtime-class callback/membership helper evidence from the low-score by-memory pass.
  - Evidence: IDA MCP disassembly shows the `0x004f4b20` shim calls vtable slot `+4` and tail-jumps to [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md), where raw helpers call a create/callback pointer at `+0x8` and walk a base-list chain through `+0x0c`.
- 2026-06-04 live IDA refinement:
  - What existed before: `COMPLETION:78`, `CONFIDENCE:76`, reconstructability/parent fields blank, and the confidence cap was described in terms of recovered-owner pollution.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000KV`, while keeping C++ blank.
  - Summary/evidence: live IDA MCP now records exact runtime-shell functions, the raw membership shim and helper island, the `0x0061cf68` vtable entries/xrefs, the `0x0061cf44` runtime-class record, separate string-helper caller patterns, and FolderTreePane-only false-owner xrefs. The score rises because the source file placement and class identity are now current IDA-backed, but it remains capped by unresolved final declarations and string utility split details.
