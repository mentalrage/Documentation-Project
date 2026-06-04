*** UID:0000KV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# LObject

## Status

- Proposed module: `util/LObject.cpp`
- Proposed header: `util/LObject.h`
- Confidence: strong for the tiny runtime/base-object source and `NexusTK/util/` placement; medium-high for the neighboring [UID:0000OA][StringBase](by-file/StringBase.md) source-file split.
- Primary class: [UID:00007D][LObject](by-class/LObject.md)
- Evidence basis: live IDA MCP boundary, vtable, runtime-class, xref, and caller checks through 2026-06-04.

## File Role

Historical recovered ownership is not a clean original-source unit. Current IDA evidence separates three implementation families that were previously grouped under the `LObject` owner:

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
| string-buffer helpers | `0x00582500-0x00584d7d` | ANSI/wide constructors, assign, release, format, append, find, splice, and substring helpers formerly grouped under `LObject`; preferred source owner is [UID:0000OA][StringBase](by-file/StringBase.md). |
| empty string and pool globals | `0x00670278`, `0x00670290`, `0x0069bacc-0x0069bbe4` | Shared sentinels and bucket allocators for the ref-counted string implementation. |

## Source-Structure Decision

Use `util/LObject.cpp` only as the home for the base-object/runtime-class surface. Do not bulk-migrate the broader recovered owner as-is: the string-family and FolderTreePane evidence have stronger owners elsewhere.

The current working model is:

- `util/LObject.cpp`: real base `LObject` constructor/runtime/destructor shell.
- `util/StringBase.cpp`: preferred owner for the ref-counted ANSI/UTF-16 string implementation and shared string-buffer globals.
- `util/PoolAllocator.cpp`: fixed-size block pool mechanics used by the small string-buffer buckets.
- `ui/controls/FolderTreePane.cpp`: tree traversal callbacks and helper cluster currently misattributed to `LObject`.

## Owner-Split Caveats

- The string methods use the first field as a data pointer, not a vtable, even though older recovered names describe it as `vftptr_0x0` or `m_vtable`.
- Methods at `0x004b3400`, `0x004b3650`, `0x004b3850`, and `0x004b3af0` are FolderTreePane traversal/search callbacks by caller evidence.
- 2026-06-01 IDA MCP disassembly of `0x004f4b20` and [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md) confirms a runtime-class membership shim/helper relationship, but final source declaration placement remains open because the `LObject` page still has polluted string ownership.

## Live IDA Evidence

- 2026-06-04 IDA MCP reports exact base/runtime functions at `0x004f4a80-0x004f4a89`, `0x004f4a90-0x004f4a97`, `0x004f4b10-0x004f4b16`, and `0x004f4b90-0x004f4c0d`, plus the exact [UID:0000WM][0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual](by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md) at `0x0041b6c0-0x0041b6c3`.
- The `LObject` vtable at `0x0061cf68` contains the scalar deleting destructor, runtime-class accessor, and default no-op virtual. Its only xrefs are the constructor store, destructor-body store, and scalar deleting destructor reset inside the runtime shell.
- The runtime-class record at `0x0061cf44` is returned only by `0x004f4b10`; its first dword points at the `LObject` string and its size dword is `4`, matching the one-vptr base shell.
- The raw runtime-class shim `0x004f4b20-0x004f4b30` is not an IDA function object; disassembly shows it calls vtable slot `+4` and tail-jumps to the [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md) at `0x005568e0`.
- IDA function/xref checks keep `0x00582500+` string routines with [UID:0000OA][StringBase](by-file/StringBase.md): representative functions include `0x00582500-0x00582552`, `0x00582d80-0x00582e2c`, `0x00583210-0x00583273`, `0x00583280-0x005832e3`, `0x00583720-0x00583832`, `0x00583840-0x00583968`, and `0x005845b0-0x005845ec`.
- IDA function/xref checks keep `0x004b3400`, `0x004b3650`, `0x004b3850`, and `0x004b3af0` with the local FolderTreePane helper cluster rather than `LObject`.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 84 | The file page now records a projected `NexusTK/util/` path, exact runtime shell contents, vtable/runtime-class data, raw membership helper relationship, string-family exclusion, and FolderTreePane exclusion. Completion remains capped because final runtime-class helper declarations and string/source split details are not final. |
| Confidence | 84 | Live IDA confirms the tiny `LObject` file role directly: one-vptr runtime-class data, vtable stores limited to the base shell, data-only vtable/default-slot refs, and separate caller patterns for string and FolderTreePane families. Confidence remains below final-audit level because the source-facing helper names and string utility boundaries still need final reconstruction work. |

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
  - Summary/evidence: true base-object shell, polluted string-buffer helpers, folder-tree false ownership, source-structure decision, owner-split caveats, and cross-references are documented; confidence is capped by unresolved final split between `LObject`, `StringBase`, `StringUtil`, and pool/string helper ownership.
- 2026-06-01 runtime-class helper update:
  - What existed before: the file contents named `GetRuntimeClass` but did not include the raw membership/callback helper island reached from the runtime shell.
  - Changed to: added the `0x004f4b20` shim and [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md) as likely runtime-class support with final declaration owner still open.
  - Evidence: IDA MCP disassembly shows the shim calls vtable slot `+4` and tail-jumps to a helper that walks a `+0x0c` base chain; the sibling raw helper invokes an optional pointer at `+0x8`.
- 2026-06-04 live IDA refinement:
  - What existed before: `COMPLETION:80`, `CONFIDENCE:76`, blank projected path, and confidence held down by recovered-owner pollution.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:84`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`.
  - Summary/evidence: live IDA now verifies the exact base/runtime shell, `0x0061cf68` vtable contents and limited xrefs, `0x0061cf44` runtime-class record, raw membership shim/helper behavior, and separate caller patterns for the string and FolderTreePane families. The score increase reflects a stronger `LObject.cpp` source boundary, while final C++ remains blank under the 95+ gate.
