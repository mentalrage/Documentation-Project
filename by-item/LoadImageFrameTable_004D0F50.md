*** UID:0000UY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000K1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LoadImageFrameTable 0x004D0F50

## Status

- Confidence: strong for behavior, medium for exact original function/type names.
- Entity kind: shared global helper.
- Likely source module: [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- Exact range: `0x004d0f50-0x004d15c5`
- Canonical memory page: [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md)
- Current IDA name: `sub_4D0F50`
- Autogen parent: [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md); final C++ remains blank because table/header/record type names and allocator wrappers are still below the 95/95 source gate.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 82 | Live IDA now confirms the exact boundary, adjacent function split, direct/merge paths, prefix literals, caller grouping, callee family, output table/header layout, and source owner attachment. |
| Confidence | 86 | The behavior and owner are strongly supported by decompilation, xrefs, and `.rdata` string reads. Confidence remains below final-source level because original type names, exact field names, and cleanup/error wrapper spelling are still unresolved. |

## Behavior

`LoadImageFrameTable_4D0F50` loads frame metadata from a DAT-backed EPF/EPD resource. It supports two modes:

- `mergeMode == 0`: open the supplied resource path as one `DATFile` entry.
- `mergeMode != 0`: map the mode to a fixed archive prefix and merge numbered shards such as `HEAD0.EPF`, `HEAD1.EPF`, and so on until [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) fails.

Observed merge prefixes include `HEAD`, `HEADSP`, `BODY`, `SWORD`, `SPEAR`, `BOW`, `FAN`, `SHIELD`, `ARROW`, `FACE`, `HAIR`, `ACE1`, `ACE2`, `HELMET`, `MANTLE`, `NECLACE`, `SHOES`, and `COAT`.

For each source archive, the helper reads an 8-byte table header, reads a 4-byte record-table offset, gets the mapped payload base through `DATFile::GetDataPointer`, seeks to the record table, and reads 16-byte raw records into 24-byte in-memory records with absolute payload offsets. It appends a terminal zero-bounds sentinel.

## Live IDA Evidence

IDA MCP on 2026-06-03 confirms:

- `lookup_funcs` resolves `0x004d0f50` to `sub_4D0F50`, size `0x675`, ending half-open at `0x004d15c5`; `0x004d15c5` is not a function, while the adjacent helpers start at `0x004d15d0` and `0x004d1600`.
- `decompile 0x004d0f50` shows direct mode opening the supplied path, allocating a 12-byte table header, reading `(count + 1) * 24` frame records, rebasing the two payload fields by the DAT data pointer, and appending the terminal sentinel.
- The nonzero mode switch accepts mode values `1..18`, copies a fixed prefix, probes up to 100 numbered names using `"%s%d.EPF"` and [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), then opens all present shards and merges their records into one output table.
- IDA `.rdata` reads resolve the prefix strings directly: `HEAD`, `HEADSP`, `BODY`, `SWORD`, `SPEAR`, `BOW`, `FAN`, `SHIELD`, `ARROW`, `FACE`, `HAIR`, `ACE1`, `ACE2`, `HELMET`, `MANTLE`, `NECLACE`, `SHOES`, and `COAT`. The `NECLACE` spelling is the observed binary string at `0x0061b828`.
- `callees 0x004d0f50` reports DAT file lifecycle/read/seek/data-pointer helpers, the DAT entry probe at `0x0049c700`, wide formatting/copy helper `0x0041b9b0`, rectangle initialization `0x004b7c50`, allocation/free helpers, and the security-cookie check.

## Caller Evidence

IDA MCP `xrefs_to 0x004d0f50` on 2026-06-03 reports 25 direct code refs grouped across eight modeled functions:

- Eighteen calls inside [UID:0002TO][0x004d2720-0x004d4aca.HumanImageLibConstructor](by-memory/0x004d2720-0x004d4aca.HumanImageLibConstructor.md), covering the old human/equipment family load path.
- `0x004dc707` in [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md) constructor code.
- `0x004dd109` in [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) constructor code.
- `0x004ff859` in [UID:00019Y][0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore](by-memory/0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore.md).
- `0x0055a694`, `0x0055a849`, `0x0055ab76`, and `0x0055b704` in overlay/filter effecter constructors.

The companion [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md) helper shares the same source owner but has a broader draw-side xref profile, including many raw references in IDA-unmodeled code islands. Together they support `ImageFrameTable` as a shared render-resource helper rather than ownership by any one image-library class.

## Ownership Decision

This helper should be grouped with [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md), not with the raw DAT archive module. The exact memory child [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md) is already attached to that parent, and this by-item index is now assigned there for autogen coverage tracking.

## Cross-References

- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- [UID:000176][0x004d0f50-0x004d165d.ImageFrameTable](by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md)
- [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md)
- [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md)
- [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md)

## Changes

- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `50/65` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented frame-table loading behavior, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now tracks it as rebuild-relevant code while staying conservative because record/type names and final source shape remain incomplete.
  - Evidence: IDA MCP confirms the exact function range, 25 direct call sites, and DATFile/HasDATEntry/allocation/rectangle helper callees.

- 2026-06-01: Completion/confidence changed from `50/65` to `70/82`.
  - Before: the page relied on the broad aggregate memory range for canonical details.
  - After: the page points to exact memory documentation for `0x004d0f50-0x004d15c5`.
  - Evidence: [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md) records IDA MCP function boundary, caller/callee inventory, direct and merge mode behavior, table layout observations, and remaining type-name questions.

- 2026-06-03: Completion/confidence changed from `70/82` to `82/86`; `AUTOGEN_PARENT_UID` changed from blank to [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md).
  - Before: the by-item page still contained stale staging/provenance wording and was unassigned even though the exact by-memory child was already attached to `ImageFrameTable`.
  - After: the page records current live IDA boundary, decompile, prefix-string, caller, callee, ownership, and score rationale evidence; final C++ remains blank below the 95/95 bar.
  - Evidence: IDA MCP `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, and `py_eval` string reads on 2026-06-03 confirm `sub_4D0F50`, the adjacent function split, 25 direct call sites, the `1..18` merge-mode prefix table, direct-mode table loading, merge-mode shard scan/merge behavior, and the observed `NECLACE` string in `.rdata`.
