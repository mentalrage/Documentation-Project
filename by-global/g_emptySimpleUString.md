*** UID:0000PW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_emptySimpleUString

## Status

- Address range: `0x0066daec-0x0066db04`
- Entity kind: process-wide empty `SimpleUString` fallback.
- Direct autogen parent: [UID:0000OB][StringUtil](by-file/StringUtil.md); [UID:0000LC][MetaMan](by-file/MetaMan.md) is a consumer of the fallback, not the owner.
- Confidence: strong for storage shape, fallback role, and shared string-utility ownership; medium for exact fine-grained string source split.
- Evidence basis: IDA MCP `xrefs_to` on `0x0066daec`, `0x0066dafc`, and `0x0066db00` plus metadata lookup decompilation.

## Role

This global is a 24-byte empty `SimpleUString`-style object used as a stable fallback return value. Metadata lookup helpers return it when a table, row, or value index is missing.

The object is also referenced outside `MetaMan`, so the direct source-root owner is shared string support rather than `metadata/MetaMan.cpp`. Metadata docs should treat it as a dependency/fallback rather than a table-owned buffer.

## Observed Layout

```text
0x0066daec  inline-or-heap string storage / pointer field
0x0066dafc  length field
0x0066db00  capacity field
```

The range matches the 24-byte `SimpleUString` layout used by metadata rows. Live byte inspection on 2026-06-07 reads twenty leading zero bytes followed by `dword_66DB00 == 7`, matching an initialized empty small-string object whose inline capacity/sentinel is `7`.

## Evidence

- `MetaMan::FindEntry` and `MetaMan::LoadStatValues` return `0x0066daec` when a lookup fails.
- [UID:0001C9][0x00523a00-0x00523c99.MetaManLookupHelpers](by-memory/0x00523a00-0x00523c99.MetaManLookupHelpers.md) return the same object from lower direct lookup helpers.
- IDA xrefs also show non-metadata UI/help paths reading the same storage, which argues against treating it as a private `MetaMan` field.
- 2026-06-07 IDA MCP `py_eval` recheck confirms the exact object bytes at `0x0066daec-0x0066db04`, the startup initializer xref at `0x00419f27`, cleanup refs from `0x0060c100`, and field users at `0x0066daec`, `0x0066dafc`, and `0x0066db00`.
- The same recheck identifies representative non-metadata user families: [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md) population at `0x004ccca0`, [UID:00002X][CollectionPane](by-class/CollectionPane.md) drawing/setup at `0x0056edc0`, and a later UI/string helper at `0x005adad0`. These users treat the object as shared fallback storage, not as an owner-specific private buffer.
- 2026-06-07 A003 Batch 074 parent-chain repair routes this global to [UID:0000OB][StringUtil](by-file/StringUtil.md), which is `85/88` and documents the shared `SimpleUString`, `SimpleUStringVector`, `StringIter`, sentinel/pool, and wide-string utility infrastructure. [UID:0000OA][StringBase](by-file/StringBase.md) is only `88/80`, so it does not clear the corrected parent confidence gate, and [UID:0000LC][MetaMan](by-file/MetaMan.md) is a consumer-only fallback user.

## Confirmed Cleanup

The initialization/destruction pair for this object is now partially confirmed. [UID:0000W9][0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle](by-memory/0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle.md) records the `0x00419f20` startup wrapper that initializes `dword_66DAEC`, and [UID:00024F][0x0060c100-0x0060c260.StaticStringContainerCleanupThunks](by-memory/0x0060c100-0x0060c260.StaticStringContainerCleanupThunks.md) records the paired `0x0060c100` cleanup body.

## Parent Routing

`AUTOGEN_PARENT_UID` now points to [UID:0000OB][StringUtil](by-file/StringUtil.md). This global is `88/86`, the file parent is `85/88`, and the by-structure relationship is direct: `StringUtil` owns shared `SimpleUString` utility infrastructure, while this page owns the process-wide empty fallback object and the by-memory child owns the exact `.data` storage range. This repair resolves the generated memory coverage error for [UID:00027J][0x0066daec-0x0066db04.g_emptySimpleUString](by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md) without forcing final C++ or a metadata-local owner.

## Open Questions

- Exact fine-grained source split under shared string support: one broad `StringUtil.cpp` declaration versus a later dedicated `SimpleUString.cpp` helper file.
- The global identity, storage range, and source-root parent are now strong enough for generated routing, but final C++ remains blank until the fine-grained string source split is settled.

## Cross-References

- [UID:0001C9][0x00523a00-0x00523c99.MetaManLookupHelpers](by-memory/0x00523a00-0x00523c99.MetaManLookupHelpers.md)
- [UID:00027J][0x0066daec-0x0066db04.g_emptySimpleUString](by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md)
- [UID:0000LC][MetaMan](by-file/MetaMan.md)
- [UID:0000OB][StringUtil](by-file/StringUtil.md)
- [UID:0001V6][MetaTableDecodedPayload](by-type/by-struct/MetaTableDecodedPayload.md)
- [UID:0001QS][client_string_handling](by-meta/client_string_handling.md)
- [UID:00024F][0x0060c100-0x0060c260.StaticStringContainerCleanupThunks](by-memory/0x0060c100-0x0060c260.StaticStringContainerCleanupThunks.md)

## Changes

- 2026-06-07 A003 Batch 074 coverage-error repair:
  - Changed to: `AUTOGEN_PARENT_UID:0000OB`; scores unchanged at `88/86`.
  - Summary/evidence: generated memory coverage for [UID:00027J][0x0066daec-0x0066db04.g_emptySimpleUString](by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md) reported `autogen_parent_unknown` because this global parent had no source-root assignment. Routing to [UID:0000OB][StringUtil](by-file/StringUtil.md) is justified because the global is a shared `SimpleUString` fallback, `StringUtil` is `85/88`, [UID:0000OA][StringBase](by-file/StringBase.md) fails the confidence gate at `88/80`, and [UID:0000LC][MetaMan](by-file/MetaMan.md) is a consumer-only fallback user.

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/80`. Summary/evidence: the page documents range, empty `SimpleUString` fallback role, observed layout, metadata and non-metadata users, initializer/cleanup evidence, and open source-owner questions.

- Before: the page listed the `0x00419f20` and `0x0060c100` startup/cleanup pair as an open question.
- After: the page records that IDA/MCP evidence confirms the pair initializes and destroys `dword_66DAEC`, while final source ownership remains open.
- Evidence: [UID:00024F][0x0060c100-0x0060c260.StaticStringContainerCleanupThunks](by-memory/0x0060c100-0x0060c260.StaticStringContainerCleanupThunks.md) documents the `0x0060c100` cleanup body, and [UID:0000W9][0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle](by-memory/0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle.md) documents the `0x00419f20` initializer wrapper.
- 2026-06-05: Marked as reconstructable and intentionally left unassigned. Evidence: live IDA MCP xrefs show 33 references to `0x0066daec`, 12 to `0x0066dafc`, and 12 to `0x0066db00`; decompilation confirms `0x00419f20` initializes `dword_66DAEC` and registers `0x0060c100`, while `0x0060c100` resets the string layout. The object is recoverable, but source ownership remains split between metadata lookup helpers and broader string fallback users.
- 2026-06-07 A008 Batch 029 refresh:
  - Changed to: `COMPLETION:88`, `CONFIDENCE:86`.
  - Summary/evidence: live IDA MCP rechecked exact bytes, initializer/cleanup refs, field refs, and representative metadata plus non-metadata consumers. Confidence now clears the parent gate for exact storage parenting, while final source-file ownership remains open.
