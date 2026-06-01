*** UID:0000PW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_emptySimpleUString

## Status

- Address range: `0x0066daec-0x0066db04`
- Entity kind: process-wide empty `SimpleUString` fallback.
- Proposed owner: shared string/metadata support; currently referenced from [UID:0000LC][MetaMan](by-file/MetaMan.md)
- Confidence: strong for storage shape and fallback role; medium for final original-source owner.
- Evidence basis: IDA MCP `xrefs_to` on `0x0066daec`, `0x0066dafc`, and `0x0066db00` on 2026-05-25 plus metadata lookup decompilation. `wave3.py` was not executed for this pass.

## Role

This global is a 24-byte empty `SimpleUString`-style object used as a stable fallback return value. Metadata lookup helpers return it when a table, row, or value index is missing.

The object is also referenced outside `MetaMan`, so the final source owner may be a shared string support unit rather than `metadata/MetaMan.cpp`. Until a broader string-global pass resolves that owner, metadata docs should treat it as a dependency/fallback rather than a table-owned buffer.

## Observed Layout

```text
0x0066daec  inline-or-heap string storage / pointer field
0x0066dafc  length field
0x0066db00  capacity field
```

The range matches the 24-byte `SimpleUString` layout used by metadata rows.

## Evidence

- `MetaMan::FindEntry` and `MetaMan::LoadStatValues` return `0x0066daec` when a lookup fails.
- [UID:0001C9][0x00523a00-0x00523c99.MetaManLookupHelpers](by-memory/0x00523a00-0x00523c99.MetaManLookupHelpers.md) return the same object from lower direct lookup helpers.
- IDA xrefs also show non-metadata UI/help paths reading the same storage, which argues against treating it as a private `MetaMan` field.

## Confirmed Cleanup

The initialization/destruction pair for this object is now partially confirmed. [UID:0000W9][0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle](by-memory/0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle.md) records the `0x00419f20` startup wrapper that initializes `dword_66DAEC`, and [UID:00024F][0x0060c100-0x0060c260.StaticStringContainerCleanupThunks](by-memory/0x0060c100-0x0060c260.StaticStringContainerCleanupThunks.md) records the paired `0x0060c100` cleanup body.

## Open Questions

- Final source owner: `StringUtil.cpp`, `SimpleUString` support, or metadata-local fallback.
- Whether the final owner of this object should be a shared string support module or a metadata/main-menu support module remains unresolved.

## Cross-References

- [UID:0001C9][0x00523a00-0x00523c99.MetaManLookupHelpers](by-memory/0x00523a00-0x00523c99.MetaManLookupHelpers.md)
- [UID:0000LC][MetaMan](by-file/MetaMan.md)
- [UID:0001V6][MetaTableDecodedPayload](by-type/by-struct/MetaTableDecodedPayload.md)
- [UID:0001QS][client_string_handling](by-meta/client_string_handling.md)
- [UID:00024F][0x0060c100-0x0060c260.StaticStringContainerCleanupThunks](by-memory/0x0060c100-0x0060c260.StaticStringContainerCleanupThunks.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/80`. Summary/evidence: the page documents range, empty `SimpleUString` fallback role, observed layout, metadata and non-metadata users, initializer/cleanup evidence, and open source-owner questions.

- Before: the page listed the `0x00419f20` and `0x0060c100` startup/cleanup pair as an open question.
- After: the page records that IDA/MCP evidence confirms the pair initializes and destroys `dword_66DAEC`, while final source ownership remains open.
- Evidence: [UID:00024F][0x0060c100-0x0060c260.StaticStringContainerCleanupThunks](by-memory/0x0060c100-0x0060c260.StaticStringContainerCleanupThunks.md) documents the `0x0060c100` cleanup body, and [UID:0000W9][0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle](by-memory/0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle.md) documents the `0x00419f20` initializer wrapper.
