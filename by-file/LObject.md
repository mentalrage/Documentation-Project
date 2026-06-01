*** UID:0000KV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# LObject

## Status

- Proposed module: `util/LObject.cpp`
- Proposed header: `util/LObject.h`
- Confidence: strong for the tiny runtime/base-object source; medium for the neighboring [UID:0000OA][StringBase](by-file/StringBase.md) source-file split.
- Current recovered source: `source-3/simroot_v2/class_LObject.cpp`
- Primary class: [UID:00007D][LObject](by-class/LObject.md)
- Evidence basis: active generated source/metadata from `simroot_v2`, plus IDA MCP boundary and caller checks on 2026-05-24.

## File Role

`class_LObject.cpp` is not a clean original-source unit. Current evidence shows three different implementation families under the generated `LObject` owner:

- a small virtual/runtime shell around `0x004f4a80-0x004f4c0d`;
- a reference-counted ANSI/UTF-16 copy-on-write string buffer implementation starting at `0x00582500`;
- folder-tree traversal callbacks at `0x004b3400-0x004b3d41` that are already documented as [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) helpers.

For source reconstruction, keep `util/LObject.cpp` as the owner candidate for the true base/runtime shell only. The string-buffer family should move to the [UID:0000OA][StringBase](by-file/StringBase.md) / [UID:0000OB][StringUtil](by-file/StringUtil.md) utility-string family. The folder-tree helpers should not migrate with `LObject.cpp`.

## Likely Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `LObject::VirtualNoop` | [UID:0000WM][0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual](by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md) | Null virtual slot used as a base no-op. |
| `LObject::LObject` | `0x004f4a80-0x004f4a89` | Sets the `LObject` vtable. |
| `LObject::GetRuntimeClass` | `0x004f4b10-0x004f4b16` | Returns `g_LObjectRuntimeClassName`. |
| runtime-class membership shim/helpers | `0x004f4b20-0x004f4b30`, [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md) | Calls vtable slot `+4`, checks runtime-class base-chain membership through offset `+0x0c`, and invokes an optional callback/create pointer at `+0x8`; final declaration owner/name remains open. |
| `LObject::ScalarDeletingDestructor` | `0x004f4b90-0x004f4c0d` | Restores vtable and optionally frees the object. |
| string-buffer helpers | `0x00582500-0x00584d7d` | ANSI/wide constructors, assign, release, format, append, find, splice, and substring helpers currently owned by generated `LObject`; preferred source owner is [UID:0000OA][StringBase](by-file/StringBase.md). |
| empty string and pool globals | `0x00670278`, `0x00670290`, `0x0069bacc-0x0069bbe4` | Shared sentinels and bucket allocators for the ref-counted string implementation. |

## Source-Structure Decision

Use `util/LObject.cpp` only as a provisional home for the base-object/runtime-class surface. Do not bulk-migrate the generated file as-is. The active generated file contains good string evidence, but it also contains owner pollution and mixed method naming such as `SimpleString::GrowAnsiBuffer`, `SimpleUString::CopyInitWide`, and `SimpleUString::FindWide` inside `class_LObject.cpp`.

The current working model is:

- `util/LObject.cpp`: real base `LObject` constructor/runtime/destructor shell.
- `util/StringBase.cpp`: preferred owner for the ref-counted ANSI/UTF-16 string implementation and shared string-buffer globals.
- `util/PoolAllocator.cpp`: fixed-size block pool mechanics used by the small string-buffer buckets.
- `ui/controls/FolderTreePane.cpp`: tree traversal callbacks and helper cluster currently misattributed to `LObject`.

## Generated Output Caveats

- `class_LObject.meta_wave3` explicitly notes that Ghidra/Wave3 merged a true virtual base class with a reference-counted string class.
- The string methods use the first field as a data pointer, not a vtable, even though older generated names describe it as `vftptr_0x0` or `m_vtable`.
- Methods at `0x004b3400`, `0x004b3650`, `0x004b3850`, and `0x004b3af0` are FolderTreePane traversal/search callbacks by caller evidence.
- Metadata history contains control-character method names such as `LObject\r`; do not trust historical generated names without rechecking current active output and IDA.
- 2026-06-01 IDA MCP disassembly of `0x004f4b20` and [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md) confirms a runtime-class membership shim/helper relationship, but final source declaration placement remains open because the `LObject` page still has polluted generated string ownership.

## Cross-References

- [UID:00007D][LObject](by-class/LObject.md)
- [UID:0000WM][0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual](by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md)
- [UID:000195][0x004f4a80-0x004f4c0d.LObjectRuntimeShell](by-memory/0x004f4a80-0x004f4c0d.LObjectRuntimeShell.md)
- [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md)
- [UID:0001J1][0x00582500-0x00583206.LObjectStringConstructionAndCow](by-memory/0x00582500-0x00583206.LObjectStringConstructionAndCow.md)
- [UID:0001J3][0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation.md)
- [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md)
- [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md)
- [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md)
- [UID:0000OB][StringUtil](by-file/StringUtil.md)
- [UID:0000OA][StringBase](by-file/StringBase.md)
- [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md)
- [UID:0001QS][client_string_handling](by-meta/client_string_handling.md)
- [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:76`.
  - Summary/evidence: true base-object shell, polluted string-buffer helpers, folder-tree false ownership, source-structure decision, generated caveats, and cross-references are documented; confidence is capped by unresolved final split between `LObject`, `StringBase`, `StringUtil`, and pool/string helper ownership.
- 2026-06-01 runtime-class helper update:
  - What existed before: the file contents named `GetRuntimeClass` but did not include the raw membership/callback helper island reached from the runtime shell.
  - Changed to: added the `0x004f4b20` shim and [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md) as likely runtime-class support with final declaration owner still open.
  - Evidence: IDA MCP disassembly shows the shim calls vtable slot `+4` and tail-jumps to a helper that walks a `+0x0c` base chain; the sibling raw helper invokes an optional pointer at `+0x8`.
