*** UID:0000VA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ResolveSpritePartPath 0x004E19D0

## Status

- Confidence: strong for behavior, medium for final type names.
- Entity kind: shared global helper.
- Current Wave3 owner file: `source-3/simroot_v2/recovered/ResolveSpritePartPath_004E19D0.cpp`
- Likely source module: [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) or shared EPF image-frame metadata support.
- Exact range: `0x004e19d0-0x004e1f26`
- Rebuild handling: `source-authored` sprite/archive metadata helper. It should be rebuilt, but final parent attachment and C++ are blank until the helper's internal record/table types and all dependencies are near-final.

## Behavior

`ResolveSpritePartPath` builds an `ArchiveMetadataTable` for a new-human sprite part name. It first probes for numbered archives using `<baseName>0.EPF`; if numbered archives exist, it scans `<baseName>%d.EPF` up to 100 shards, reads all headers, merges frame records into one metadata table, and appends a sentinel record. If no numbered archive exists, it loads the single `<baseName>.EPF` archive.

Each record stores normalized bounds plus absolute payload start/end offsets based on the DAT file's mapped payload base.

## Evidence

- Wave3 metadata reports canonical name `ResolveSpritePartPath`, signature `ArchiveMetadataTable* ResolveSpritePartPath(const wchar_t* baseName)`, range `0x004e19d0-0x004e1f26`, and effective grade `88`.
- IDA MCP on 2026-05-22 reports callers from `NewHumanImageLib` constructor at `0x004e00f0` and a related wrapper path at `0x004e12fe`.
- Callees include [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), `DATFile`, `DATFile::GetDataPointer`/payload-base access, allocation helpers, and rect normalization.
- IDA MCP recheck on 2026-05-31 reports function `sub_4E19D0` with exclusive end `0x004e1f27` (documented inclusive end `0x004e1f26`) and code references from `0x004e00f0` and `0x004e12fe`. Callees include formatting/path helpers, `HasDATEntry` at `0x0049c700`, DATFile access helpers, allocation/free helpers, and rectangle normalization at `0x004b7c50`. Data refs include the `%s%d.EPF` and `%s.EPF` format strings.

## Ownership Decision

This helper is too specific to new-human part archives to live in raw DAT archive code. Keep it with [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) or a shared render/image metadata file used by new-human part loaders.

## Cross-References

- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)

## Changes

- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with moderate completion and strong confidence, while parent attachment and C++ remain blank.
- Summary and evidence: IDA MCP verification on 2026-05-31 confirmed the exact function boundary, two caller sites, DAT/archive helper callees, and EPF filename-format strings. The score remains below 95 because final source ownership and internal `ArchiveMetadataTable` field naming still require a full audit.
