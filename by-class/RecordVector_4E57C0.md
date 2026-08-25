*** UID:0000BS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RecordVector_4E57C0

## Status

- Disposition: non-reconstructable, non-emitting historical generated-name index. `RecordVector_4E57C0` is not a recovered source class.
- Metadata policy: owner `NONE`, reconstructable false, blank emitter, blank position, and intentionally empty formal C++ block. No class declaration, object, method body, or Empty Emitter Marker belongs here.
- Exact indexed compiler-support ranges: [UID:00017U][0x004e57c0-0x004e5989.RecordVectorInsert](by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md) and [UID:0004DO][0x004e6ff0-0x004e7026.FrameDrawRecordUninitializedCopyCompilerSupport](by-memory/0x004e6ff0-0x004e7026.FrameDrawRecordUninitializedCopyCompilerSupport.md).
- Direct source route for both exact children: [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md), because `NewHumanImageLib::RenderComposition` owns the typed local `std::vector<FrameDrawRecord>` append that regenerates both compiler lowerings.

## Class Purpose

`RecordVector_4E57C0` is a synthetic documentation label historically used to group two compiler-generated operations over a fixed 40-byte record vector. No class object, declaration, constructor, destructor, vtable, storage, or independent source body exists. The runtime behavior belongs to a compiler-era MSVC `std::vector<FrameDrawRecord>` instantiation generated from one local append in `NewHumanImageLib::RenderComposition`.

The index remains useful because it links the full-capacity grow/insert lowering and its private uninitialized prefix/suffix copy, while preventing either operation from being mistaken for a handwritten product class. Exact children remain reconstructable and carry their own formal marker dispositions through UID0000LR.

## Method

| Address | Method | Role |
| --- | --- | --- |
| `[0x004e57c0,0x004e598a)` | UID00017U FrameDrawRecord vector grow/insert compiler support | Full-capacity growth, inserted-record copy, prefix/suffix relocation, checked old-storage free, and vector-triplet update. |
| `[0x004e6ff0,0x004e7026)` | UID0004DO FrameDrawRecord uninitialized-copy compiler support | Private forward shallow copy of 40-byte prefix/suffix ranges into replacement storage. |

## Ownership Notes

UID00017U has one direct product call at `0x004e4c14` inside `NewHumanImageLib::RenderComposition`; UID0004DO has exactly two xrefs, both private calls inside UID00017U. The caller appends one local `FrameDrawRecord`, performs the no-capacity path inline, and invokes UID00017U only at capacity. This source shape rejects a separately designed project class.

[UID:0000P3][VectorHelpers](by-file/VectorHelpers.md), [UID:0001QA][client_containers](by-meta/client_containers.md), and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) preserve historical reusable-template context. Their former direct ownership classification is superseded for these one-feature NewHuman lowerings. UID0000LR is the exact file owner/emitter; this page is semantic history only.

## Evidence Notes

- [UID:00017U][0x004e57c0-0x004e5989.RecordVectorInsert](by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md) records the exact function range, `0x28`-byte element size, vector-growth behavior, and single caller at `0x004e4c14`.
- [UID:00017R][0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster](by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md) and [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) identify the caller as `RenderComposition`, not a standalone feature class.
- [UID:0004DO][0x004e6ff0-0x004e7026.FrameDrawRecordUninitializedCopyCompilerSupport](by-memory/0x004e6ff0-0x004e7026.FrameDrawRecordUninitializedCopyCompilerSupport.md) records the exact `CopyRecordVector40Range` body at `0x004e6ff0-0x004e7026`, called twice by this insert helper; [UID:00022R][0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers](by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md) is now only the split/index parent.
- 2026-06-14 live IDA MCP reconfirms `0x004e57c0-0x004e598a` as `sub_4E57C0`, one caller from `sub_4E4280` at `0x004e4c14`, `0x28`-byte record arithmetic, growth by capacity plus half, aligned large allocation, two calls to `sub_4E6FF0`, and old-storage free through `sub_5C7526`.
- 2026-06-14 live IDA MCP reconfirms `sub_4E6FF0` as a `0x36`-byte record copy helper called only by this insert function and copying two 16-byte chunks plus an 8-byte tail per `0x28`-byte record.
- 2026-06-25 B008 implementation recheck used live IDA MCP database `80de0a67` (`NexusTK.exe.i64`), healthy worker PID `26892`, module `NexusTK.exe`, imagebase `0x400000`, and ready auto-analysis/Hex-Rays/string cache state. `lookup_funcs` reconfirmed the insert helper as size `0x1ca`, the caller `sub_4E4280` as size `0xaf9`, and the copy helper as size `0x36`.
- 2026-06-25 `analyze_function` on `0x004e57c0` reported `26` basic blocks, no strings, caller `sub_4E4280`, and callees `sub_421500`, `operator new(uint)`, `sub_5C7526`, `sub_4E6FF0`, and `__invalid_parameter_noinfo_noreturn`; `search_text` and `xrefs_to` confirmed the sole call at `0x004e4c14` and the two copy-helper calls at `0x004e58fa`/`0x004e590e`.

## Reconstruction Notes

- Rebuild handling is historical index only: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/position, and empty formal block.
- UID00017U and UID0004DO remain reconstructable because they are exact executable compiler-support ranges. Each emits a precise covered-by marker through UID0000LR; neither emits a handwritten private-STL body.
- Final behavior is expressed by the local typed `FrameDrawRecord` vector append in `RenderComposition`. Direct generic VectorHelpers ownership, a standalone `RecordVector_4E57C0::Insert` body, product-domain class promotion, runtime/MSVC ownership, and an Empty Emitter Marker for this index are rejected.
- Historical direct VectorHelpers/class-owner statements above remain provenance for the old model, not current source placement.

## Score Rationale

`92/93` reflects a complete disposition audit: exact child inventory, caller/source operation, absence of every class identity signal, child owner/emitter routes, no-code policy, negative evidence, and historical classification are resolved. Confidence is capped because the synthetic generated label has no original source symbol.

## Cross-References

- [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md)
- [UID:00017U][0x004e57c0-0x004e5989.RecordVectorInsert](by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md)
- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:00017R][0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster](by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md)
- [UID:0004DO][0x004e6ff0-0x004e7026.FrameDrawRecordUninitializedCopyCompilerSupport](by-memory/0x004e6ff0-0x004e7026.FrameDrawRecordUninitializedCopyCompilerSupport.md)
- [UID:00022R][0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers](by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `68/76`.
  - Before: The page was unevaluated despite identifying the fixed-record vector insert helper, record size, growth behavior, and only known caller.
  - After: Scored as moderate completion with medium-high confidence because the helper behavior is understood but the final source artifact remains compiler/vector support rather than a true product class.
  - Evidence: Existing purpose, method, ownership notes, and memory/file cross-references establish helper behavior and migration ownership caveats.
- 2026-06-02: Raised to `80/84`, set `RECONSTRUCTABLE:TRUE`, and attached parent [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md).
  - Evidence: the parent file now has `82` confidence and a `NexusTK/util/` projection; exact memory docs identify the single `RenderComposition` caller, fixed `0x28` record insert behavior, and copy helper dependencies. Historical C++ note superseded by the 2026-06-25 child marker disposition.
- 2026-06-14 Agent-A001 Goal 2 low-score repair:
  - Changed scores from `80/84` to `85/86`.
  - Added live IDA MCP confirmation of the insert boundary, single `RenderComposition` caller, growth/allocation/free behavior, and copy-helper dependency. The exact child [UID:00017U][0x004e57c0-0x004e5989.RecordVectorInsert](by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md) now clears `85/88`.
  - Superseded C++ note: the old `90/90+` final-source gate no longer blocks the accepted child marker route.
- 2026-06-25 Agent-B008 implementation callback for accepted [UID:00017U][0x004e57c0-0x004e5989.RecordVectorInsert](by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md) source-quality report:
  - Metadata unchanged at `85/86`, `CANONICAL_OWNER:0000P3`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000P3`.
  - Updated support prose to record that [UID:00017U][0x004e57c0-0x004e5989.RecordVectorInsert](by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md) now emits the formal source-disposition marker because the executable body is compiler/vector grow slow-path support for `RenderComposition` local records.
  - Preserved the source-route decision: this remains a [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md) helper bucket, while [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) owns the composition/render semantics. Standalone helper-body C++, product-domain class promotion, runtime/MSVC ownership, NewHumanImageLib method ownership for the helper body, and non-emitter reclassification were rejected.
- 2026-07-13 B002 UID0004DO source-quality callback:
  - Reclassified this synthetic page from `85/86`, UID0000P3-owned reconstructable emitter to `92/93`, owner NONE, reconstructable false, blank emitter/position, and exact empty formal block.
  - Preserved the page as a complete historical index for UID00017U and renamed UID0004DO, while routing both exact reconstructable marker children through UID0000LR and labeling the former VectorHelpers/class model superseded.
