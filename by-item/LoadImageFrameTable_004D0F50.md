*** UID:0000UY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# LoadImageFrameTable 0x004D0F50

## Status

- Confidence: strong for behavior, medium for exact original function/type names.
- Entity kind: non-emitting by-item index/support page for the exact loader.
- Likely source module: [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- Exact range: `0x004d0f50-0x004d15c5`
- Canonical memory page: [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md)
- Current IDA name: `sub_4D0F50`
- Owner/source route: [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md). This by-item page is `RECONSTRUCTABLE:FALSE` and non-emitting because the exact loader source-quality disposition belongs to [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md); emitting here would duplicate the exact by-memory output.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 87 | Live IDA confirms the exact boundary, adjacent function split, direct/merge paths, prefix literals, caller grouping, callee family, output table/header layout, ImageFrameTable source route, refreshed record/sentinel behavior, exact support-page alignment with [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md), and the duplicate-emitter decision. |
| Confidence | 91 | The behavior and owner are strongly supported by current decompilation, xrefs, callees, byte-padding checks, and raw string reads. This page is non-emitting by design; the exact first-draft formal body now lives on [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md). |

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

2026-06-14 live IDA MCP session `a001_goal2_class_batch` reconfirmed:

- `lookup_funcs` resolves `0x004d0f50` to `sub_4D0F50` size `0x675`; `0x004d15c5` is still not a function, and adjacent helpers remain `0x004d15d0` size `0x2c` and `0x004d1600` size `0x5d`.
- `analyze_function 0x004d0f50` reports size `1653`, eight containing caller functions, and 18 callees; `xrefs_to 0x004d0f50` still reports 25 direct code refs.
- Targeted decompilation reconfirmed the merge shard loop cap `100 == 0x64` (verified with `int_convert.py`), candidate formatting with `"%s%d.EPF"`, DAT-entry probing through `0x0049c700`, frame-record allocation as `24 * (count + 1)` where `24 == 0x18` (verified with `int_convert.py`), and terminal zero-rectangle sentinel setup through `0x004b7c50`.

2026-06-16 live IDA MCP session `b001_selflookpane_0001H7_20260616` reconfirmed:

- `lookup_funcs` still resolves `0x004d0f50` to `sub_4D0F50` size `0x675`; `0x004d15c5` is not a function; `0x004d15d0` remains size `0x2c`; and `0x004d1600` remains size `0x5d`.
- `xrefs_to 0x004d0f50` again reports 25 code refs: 18 inside `0x004d2720`, plus `0x004dc707`, `0x004dd109`, `0x004ff859`, `0x0055a694`, `0x0055a849`, `0x0055ab76`, and `0x0055b704`.
- `analyze_function 0x004d0f50` reports size `1653`, 89 basic blocks, complexity 40, eight caller functions, and 18 callees including DATFile open/read/seek/close/data-pointer helpers, [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), `sub_4B7C50`, allocation/free helpers, and the security-cookie check.
- Targeted decompilation reconfirmed the direct path allocating a 12-byte header, reading an 8-byte metadata header and 4-byte record-table offset, allocating `24 * (count + 1)` records, converting four 16-bit bounds values through `sub_4B7C50`, rebasing the two payload fields by the DAT data pointer, and writing the terminal zero-bounds sentinel with both payload fields set to `dataBase + recordTableOffset`.
- `get_bytes` reconfirmed `0x004d15c5-0x004d15d0` and `0x004d15fc-0x004d1600` as `0xcc` alignment padding, so the exact loader range still stops before `DestroyOwnedImageBlock`.

## Caller Evidence

IDA MCP `xrefs_to 0x004d0f50` on 2026-06-03 reports 25 direct code refs grouped across eight modeled functions:

- Eighteen calls inside [UID:0002TO][0x004d2720-0x004d4aca.HumanImageLibConstructor](by-memory/0x004d2720-0x004d4aca.HumanImageLibConstructor.md), covering the old human/equipment family load path.
- `0x004dc707` in [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md) constructor code.
- `0x004dd109` in [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) constructor code.
- `0x004ff859` in [UID:00019Y][0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore](by-memory/0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore.md).
- `0x0055a694`, `0x0055a849`, `0x0055ab76`, and `0x0055b704` in overlay/filter effecter constructors.

The companion [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md) helper shares the same source owner but has a broader draw-side xref profile, including many raw references in IDA-unmodeled code islands. Together they support `ImageFrameTable` as a shared render-resource helper rather than ownership by any one image-library class.

B010 2026-07-03 caller disassembly clarifies the source-facing target signature. Some callers load `ecx = dword_67A744` / `g_pEPFLib` before the call, but the call sites pass only two stack arguments and [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md) does not consume `ecx`. The target-facing signature is `LoadImageFrameTable(const wchar_t *resourcePath, int mergeMode)`.

## 2026-06-16 Blocker Investigation

- Owner/source placement: current xrefs remain spread across HumanImageLib, RidingImageLib, StaticObjImageLib, scrolled-picture UI, and screen effecters. No single consumer dominates; the direct owner/emitter remains [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md), with DATFile/DATFileMgr and image libraries documented as dependencies/consumers.
- Range/split: live `lookup_funcs` and byte reads keep `0x004d0f50-0x004d15c5` as the exact loader, with `0x004d15c5-0x004d15d0` padding before the cleanup helper. No merge with [UID:0002P5][0x004d15d0-0x004d15fc.DestroyOwnedImageBlock](by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md) is supported.
- Field/type/helper names: the loader's 12-byte header, 24-byte record stride, raw 16-byte record read, and sentinel are code-confirmed. The exact page [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md) now carries first-draft formal C++: inferred table/record names are supplied by [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md), and MemoryMan/HasDATEntry/format/RectBounds support plus current sibling formal bodies resolve the old hard body blocker for first draft.
- Prefix spelling: existing `.rdata` reads and decompile references keep the observed `NECLACE` binary spelling. Current string-cache regex found related lowercase resource/table strings but did not produce a stronger source-name signal for the uppercase merge-prefix table.

## 2026-06-29 B006 Duplicate-Emitter Resolution, Updated By B010

This by-item page is a name/index page over the exact loader. The source-quality and formal C++ decision belongs to [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md), which keeps `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md), and now carries first-draft `LoadImageFrameTable(const wchar_t *resourcePath, int mergeMode)` source after B010's 2026-07-03 callback. This by-item page is therefore `RECONSTRUCTABLE:FALSE`, has blank `EMITTER_UIDS`, and must keep its formal C++ block blank.

The duplicate-emitter decision still stands without losing evidence: the exact range, 25 direct xrefs, eight caller functions, 18-callee family, direct/merge behavior, prefix table, and B010's two-stack-argument signature proof are all preserved on [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md). Historical B006 no-code wording is superseded for the exact target by current sibling formal bodies and support docs.

## Ownership Decision

This helper should be grouped with [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md), not with the raw DAT archive module. The exact memory child [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md) is attached to that parent and owns the formal first-draft source output. This by-item index stays non-emitting to avoid duplicate generated source.

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

- 2026-06-03: Completion/confidence changed from `70/82` to `82/86`; generated-output ownership/routing was attached to [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md).
  - Before: the by-item page still contained stale staging/provenance wording and was unassigned even though the exact by-memory child was already attached to `ImageFrameTable`.
  - After at that time: the page recorded current live IDA boundary, decompile, prefix-string, caller, callee, ownership, and score rationale evidence, while final C++ stayed blank below source-quality evidence. Superseded by B006 2026-06-29: this by-item page is a non-emitting index and [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md) owns the formal no-code proof.
  - Evidence: IDA MCP `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, and `py_eval` string reads on 2026-06-03 confirm `sub_4D0F50`, the adjacent function split, 25 direct call sites, the `1..18` merge-mode prefix table, direct-mode table loading, merge-mode shard scan/merge behavior, and the observed `NECLACE` string in `.rdata`.
- 2026-06-14 A001: Raised completion/confidence from `82/86` to `85/88`.
  - Before: the page had strong 2026-06-03 evidence but still used old autogen-parent/final-code wording and lacked a current validation of the adjacent function split and record allocation constants.
  - After: added a 2026-06-14 live IDA MCP refresh, updated score rationale, and replaced final-code wording with the active source-quality gate.
  - Evidence: `lookup_funcs`, `analyze_function`, `xrefs_to`, and targeted decompile checks reconfirm the exact boundary, no-function endpoint, adjacent helpers, 25 direct code refs, merge shard cap, candidate formatter, DAT probe, 24-byte output records, and sentinel rectangle setup.
- 2026-06-16 A002: Raised completion/confidence from `85/88` to `86/90`.
  - Before: the item cleared the gate, but the exact memory support page still lagged at `82/88` and the remaining source-quality blockers were not rechecked in the current IDA session.
  - After at that time: added current IDA lookup/xref/analyze/decompile/byte evidence, recorded the exact range split against the cleanup helper, and documented why final source/type names were still unsafe. Superseded by B006 2026-06-29 dependency audit, which narrows the remaining blocker to DATFile declarations and merge-mode object-array/EH source shape on [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md).
  - Evidence: live IDA MCP session `b001_selflookpane_0001H7_20260616` reconfirmed the 25-callsite caller set, 18-callee family, direct/merge record allocation and sentinel behavior, padding after the loader, and ImageFrameTable owner/emitter route.
