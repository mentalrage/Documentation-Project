** TARGET-REPORT-UID:0000K1 **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000K1 ImageFrameTable Empty-Emitter Family Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: accept [UID:0000K1] `by-file/ImageFrameTable.md` as the correct generated source root, but do not blindly fill all eight empty emitters with duplicate bodies.
- Final disposition: mixed. Emit source declarations for [UID:0000UN], emit first-draft C++ for the small exact helper pages [UID:0002P5], [UID:0002P6], [UID:00031T], and [UID:00031U], reclassify the two by-item function aliases [UID:0000UX] and [UID:0000UY] as non-emitting index pages, and keep [UID:0002P4] `LoadImageFrameTable` intentionally no-code/comment-only after the dependency-specific audit below. The 0002P4 blocker is now specific: exact DATFile method declarations, merge-mode prefix naming, and MSVC temporary-array/EH cleanup shape were checked and remain the source-safety limiters.
- Implementation callback status: target/support by-* docs were updated in place, scoped validators were run, and generated `ImageFrameTable.cpp` now emits the declarations, no-code comment, and helper bodies without the prior empty-marker family or by-item duplicate emitters.
- Confidence: high for source ownership/range/route decisions and for the small helpers; medium-high for the declaration names; medium for the large loader C++ deferral because the behavior is well proven but full source shape still depends on accepted DATFile method declarations and merge-mode object-array/EH cleanup spelling.

## Target

- Target UID: `0000K1`
- Target path: `by-file/ImageFrameTable.md`
- Generated output: `auto-generated/NexusTK/render/ImageFrameTable.cpp`
- Pre-callback queue row: `auto-generated/-ag-research-tracker.md` -> `Files With Empty Emitters`, row [UID:0000K1], `Total=8`, `Filled=0`, `Empty=8`, `0.0%`.
- Pre-callback generated file header: `validator-command-id: 000000001170`, `validator-refreshed-at: 2026-06-29T20:20:23-04:00`; all eight in-scope entries were `Empty Emitter Marker`.
- Post-callback generated file header: `validator-command-id: 000000001256`, `validator-refreshed-at: 2026-06-29T21:40:04-04:00`, `validator-refresh-source: foreground-generated-refresh`; no `Empty Emitter Marker` remains for the ImageFrameTable family, [UID:0000UX]/[UID:0000UY] are absent as non-emitting by-item indexes, and [UID:0000UN], [UID:0002P4], [UID:0002P5], [UID:0002P6], [UID:00031T], and [UID:00031U] are present.
- Post-callback by-file metadata: `COMPLETION:90`, `CONFIDENCE:88`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`.

## Current Target State

The file page already establishes the right source family: `LoadImageFrameTable`, `DestroyOwnedImageBlock`, `LoadFrameDrawRecord`, the two adjacent raw frame-record helpers, and the shared EPF archive metadata structure all route through `render/ImageFrameTable.cpp`. The stale part is the generated-output state. The generated file is zero-filled because every child has a blank formal C++ block, even though the entries are not all the same kind of source unit.

The current family has three categories:

- Source declarations: [UID:0000UN] `EPFArchiveMetadataTable`.
- Exact code bodies: [UID:0002P5], [UID:0002P6], [UID:00031T], [UID:00031U], and the larger [UID:0002P4].
- Index/alias pages: [UID:0000UX] and [UID:0000UY], which duplicate exact by-memory pages and should not emit separate bodies.

## Evidence Checked

MCP-backed evidence:

- MCP `initialize` and `tools/list` succeeded against `http://127.0.0.1:13337/mcp`.
- Revision session audit: initial `idb_list` returned no active sessions, so `idb_open` was called for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` with `mode=prefer_headless`, `build_caches=true`, `init_hexrays=true`, `run_auto_analysis=false`, and `preferred_session_id=B006_ImageFrameTable`. MCP returned the existing named database/session `B005_00049P_20260629`; this is the database handle used for the 0002P4 revision evidence.
- `server_health(database=B005_00049P_20260629)`: status `ok`, module `NexusTK.exe`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`.
- `lookup_funcs` for `0x004d0f50`, `0x004d15c5`, `0x004d15d0`, `0x004d15fc`, `0x004d1600`, `0x004d165d`, `0x004d1660`, `0x004d1704`, `0x004d1710`, `0x004d172d`, and `0x004d1730`.
- `analyze_function` for `0x004d0f50`, `0x004d15d0`, and `0x004d1600`.
- Revision-specific 0002P4 checks: full `decompile 0x004d0f50`, `callees 0x004d0f50`, `xref_query to 0x004d0f50 code include_fn`, `lookup_funcs` and `decompile`/`analyze_component` for `0x0041b9b0`, `0x004b7c50`, DATFile methods `0x0049c130`, `0x0049c160`, `0x0049c180`, `0x0049c240`, `0x0049c260`, `0x0049c310`, `0x0049c550`, `0x0049c700`, MemoryMan helpers `0x00516030`, `0x00516050`, `0x00516170`, `0x00516220`, project operator wrapper `0x004f4aa0`, and CRT/runtime thunks `0x005c74f6`, `0x005c7526`, `0x005c7790`, `0x005c7799`.
- Revision-specific string/evidence checks: raw UTF-16 `get_bytes` for merge prefixes at `0x0061b778`, `0x0061b784`, `0x0061b794`, `0x0061b7a0`, `0x0061b7ac`, `0x0061b7b8`, `0x0061b7c0`, `0x00618818`, `0x0061b7d8`, `0x0061b7e4`, `0x0061b7f0`, `0x0061b7fc`, `0x0061b808`, `0x0061b818`, `0x0061b828`, and `0x0061b844`; `find_regex` was tried for `HEADSP`, `NECLACE`, `SHIELD`, `SHOES`, and `%s%d.EPF` but string-cache hits were weaker than raw-byte proof.
- `disasm` for raw addresses `0x004d1660` and `0x004d1710`.
- `xrefs_to` for raw helper starts/ends `0x004d1660`, `0x004d1704`, `0x004d1710`, and `0x004d172d`.
- `entity_query` for functions in `0x004d0f40-0x004d1780`.
- `get_bytes` for `0x004d15c5` and `0x004d165d` neighborhoods.
- `int_convert` for `0x675`, `0x2c`, `0x5d`, `0xa4`, `0x1d`, `0x18`, `0x28`, `0x0c`, `0x64`, `25`, `44`, `81`, `93`, and `1653`.

Documentation/generated evidence:

- Primary: `by-file/ImageFrameTable.md`.
- In-scope emitters: `by-item/EPFArchiveMetadataTable.md`, `by-item/LoadFrameDrawRecord_004D1600.md`, `by-item/LoadImageFrameTable_004D0F50.md`, `by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md`, `by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md`, `by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md`, `by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md`, and `by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md`.
- Support/container: `by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md`.
- Support dependencies read for the 0002P4 rejection audit: `by-file/DATFile.md`, `by-class/DATFile.md`, `by-type/by-struct/DATFileLayout.md`, `by-memory/0x0049c130-0x0049d2cc.DATFile.md`, `by-memory/0x0049c700-0x0049c71d.HasDATEntry.md`, `by-global/HasDATEntry_49C700.md`, MemoryMan pages for `GetMemoryMan`, `AllocateBufferMemory`, `FreeBufferMemory`, and `MemmoveWrapper`, operator wrapper pages, and `RectBounds` class/struct pages.
- Generated state: `auto-generated/NexusTK/render/ImageFrameTable.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-file-coverage.md`, `by-file/-coverage-report.md`, `by-item/-coverage-report.md`, and `by-memory/-coverage-report.md`.
- Prior executed reports opened or searched as relevant leads: B002 `00016A-GrafPortDrawTiledBackground-source-quality.md`, B015 `000177-MapTileImageLibLocalMethodCluster-source-quality.md`, B015 `00009X-OverlayFrameImageEffecter-source-quality.md`, B004 `00006A-HumanImageLib-class-source-quality.md`, and A002 notes around the 2026-06-16 [UID:0002P4] update.
- Targeted old-report search terms used: `0000K1`, `ImageFrameTable`, `LoadImageFrameTable`, `LoadFrameDrawRecord`, `DestroyOwnedImageBlock`, `FrameRecordPayloadCopy`, `FrameRecordRectCopy`, `EPFArchiveMetadataTable`, `004d0f50`, `004d1600`, `004d1710`, `0002P4`, `HEADSP`, `NECLACE`, `merge-mode`, and `DATFile wrapper`.

Negative checks:

- No function at `0x004d15c5`, `0x004d15fc`, `0x004d165d`, `0x004d1660`, `0x004d1704`, `0x004d1710`, or `0x004d172d`.
- No xrefs to raw helper starts/ends `0x004d1660`, `0x004d1704`, `0x004d1710`, or `0x004d172d`.
- `entity_query` over `0x004d0f40-0x004d1780` reports modeled functions only at `0x004d0f50`, `0x004d15d0`, `0x004d1600`, `0x004d1730`, and `0x004d1780`.
- The broad aggregate [UID:000176] is already correctly `RECONSTRUCTABLE:FALSE`; no aggregate body should be emitted.
- No evidence supports moving the family to `ResourceLayoutTable`, `MapTileImageLib`, `StaticObjImageLib`, `EffectObjImageLib`, `HumanImageLib`, `Effects`, `ScrolledPictureControlPane`, `DATFile`, or `Surface`.

## IDA MCP Facts

Function and boundary facts:

| Address | MCP result | Meaning |
| --- | --- | --- |
| `0x004d0f50` | `sub_4D0F50`, size `0x675` / decimal `1653` (Verified with `int_convert`) | Large DAT-backed EPF/EPD frame-table loader. |
| `0x004d15c5` | not a function | Loader half-open endpoint; followed by padding. |
| `0x004d15d0` | `sub_4D15D0`, size `0x2c` / decimal `44` (Verified with `int_convert`) | Two-level destroy helper for blocks returned by the loader. |
| `0x004d15fc` | not a function | Destroy helper endpoint; followed by padding. |
| `0x004d1600` | `sub_4D1600`, size `0x5d` / decimal `93` (Verified with `int_convert`) | Frame-record projection helper. |
| `0x004d165d` | not a function | Projection helper endpoint; followed by padding. |
| `0x004d1660` | not a function | Raw source-looking payload-copy helper start. |
| `0x004d1710` | not a function | Raw source-looking rectangle-copy helper start. |
| `0x004d1730` | `sub_4D1730`, size `0x43` | Next modeled ResourceLayout accessor. |

Modeled function facts:

- `analyze_function 0x004d0f50`: prototype `_DWORD *__stdcall(wchar_t *ArgList, int)`, size `1653`, 89 basic blocks, complexity `40`, eight caller functions, 18 callees, 25 direct xrefs. Decompile confirms mode switch, 12-byte header allocation (`0x0c`, Verified with `int_convert`), `0x64` / 100 shard cap (Verified with `int_convert`), DATFile lifecycle/read/seek/data-pointer helpers, `HasDATEntry`, rectangle initialization, allocation/free helpers, and security cookie.
- `analyze_function 0x004d15d0`: prototype `int __stdcall(void **Block)`, size `44`, three basic blocks, complexity `2`, callees `sub_516030` and `sub_516170`, callers `sub_4FF970`, `sub_502AB0`, `sub_55A6F0`, `sub_55A8E0`, `sub_55AC50`, `sub_55BC90`, `sub_55BE10`, and `sub_55BEF0`. The body frees `Block[2]` if non-null and always frees `Block`.
- `analyze_function 0x004d1600`: prototype `int __stdcall(unsigned __int16 *, int, int)`, size `93`, four basic blocks, complexity `2`, no callees, ten modeled caller functions, and 81 xrefs (`0x51`, Verified with `int_convert`). The body selects `records + 24 * frameIndex`, writes output offsets `+0x04`, `+0x0c`, `+0x10`, `+0x20`, and `+0x24`, and computes span from next record `+0x10` minus current record `+0x14`.

Raw helper facts:

- `disasm 0x004d1660`: `<no function>` but source-looking body with standard prologue, `ret 0x0c`, bounds check against table `+0x00`, record pointer at table `+0x08`, `24`-byte stride (`0x18`, Verified with `int_convert`), two span allocations through `sub_516050`, two copies through `sub_516220`, and output writes at `+0x04`, `+0x0c`, `+0x10`, `+0x20`, and `+0x24`.
- `disasm 0x004d1710`: `<no function>` but source-looking 29-byte (`0x1d`, Verified with `int_convert`) body with standard prologue, `index * 24` calculation, table record-base read from `+0x08`, one 16-byte `movups` copy to caller output, and `ret 0x0c`.
- `get_bytes 0x004d165d` confirms three `0xcc` bytes before `0x004d1660`, raw bytes through both helper bodies, twelve `0xcc` bytes at `0x004d1704-0x004d1710`, and the `0x004d1710-0x004d172d` helper body.

## Function / Child Inventory

| UID / path | Role | Current state | Recommendation |
| --- | --- | --- | --- |
| [UID:0000UN] `by-item/EPFArchiveMetadataTable.md` | Shared declarations for table/record/draw-record structs | `85/90`, reconstructable, emitted, blank C++ | Keep owner/emitter; raise to `88/91`; add formal declaration block with inferred names. |
| [UID:0000UX] `by-item/LoadFrameDrawRecord_004D1600.md` | Name/index page for exact helper | `85/90`, reconstructable, emitted, blank C++ | Reclassify as non-emitting index page or emit only a formal coverage comment; exact source belongs to [UID:0002P6]. Recommended metadata: `RECONSTRUCTABLE:FALSE`, clear emitter/code, score `86/91`. |
| [UID:0000UY] `by-item/LoadImageFrameTable_004D0F50.md` | Name/index page for exact loader | `86/90`, reconstructable, emitted, blank C++ | Reclassify as non-emitting index page or emit only a formal coverage comment; exact source/no-code proof belongs to [UID:0002P4]. Recommended metadata: `RECONSTRUCTABLE:FALSE`, clear emitter/code, score `87/91`. |
| [UID:0002P4] `by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md` | Large frame table loader | `85/89`, reconstructable, emitted, blank C++ | Keep metadata/route; add target-specific no-code proof/formal comment. Do not emit a body in this family pass. |
| [UID:0002P5] `by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md` | Two-level destroy helper | `85/90`, reconstructable, emitted, blank C++ | Raise to `88/92`; add formal first-draft C++ for `DestroyOwnedImageBlock`. |
| [UID:0002P6] `by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md` | Frame draw record projection | `86/90`, reconstructable, emitted, blank C++ | Raise to `88/92`; add formal first-draft C++ using `ArchiveMetadataTable`, `PackedArchiveRecord`, and `FrameDrawRecord`. |
| [UID:00031T] `by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md` | Raw payload-copy helper | `85/88`, reconstructable, emitted, blank C++ | Raise to `86/89`; add formal first-draft C++ despite no xrefs, preserving no-xref caveat. |
| [UID:00031U] `by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md` | Raw rectangle-copy helper | `85/88`, reconstructable, emitted, blank C++ | Raise to `86/89`; add formal first-draft C++ despite no xrefs, preserving no-xref caveat. |

## Heuristic / Inference Reanalysis And Validation

### Duplicate by-item emitters

[UID:0000UX] and [UID:0000UY] are useful name/index pages, but emitting source from them would duplicate exact by-memory bodies. The exact by-memory pages have the address ranges, bytes, xrefs, and body evidence needed for source ownership. The by-item pages should become non-emitting index/support docs, or at most carry a formal comment that the exact source/no-code decision is covered by [UID:0002P6] or [UID:0002P4].

Recommendation: metadata reclassification is cleaner than comment emission. Set both by-item pages to `RECONSTRUCTABLE:FALSE`, clear `EMITTER_UIDS`, and keep formal C++ blank. This removes two false empty emitters without losing documentation.

### Shared type names

The best current source-facing names are:

- `ArchiveMetadataTable`: 12-byte header with 16-bit frame count, two 16-bit max/header fields, a reserved 16-bit field, and a pointer to records.
- `PackedArchiveRecord`: 24-byte in-memory record with a `RectBounds` first 16 bytes and two payload boundary pointers.
- `FrameDrawRecord`: caller-facing output record consumed by `GrafPort::DrawTiledBackground` and produced by `LoadFrameDrawRecord`.

These names are inferred, not original-symbol proof. They are stronger than `FrameRecordTable_4D1600`, raw `this[ ]`, or `TileData_...` names because related accepted reports already use `FrameDrawRecord`, the table is not tile-only, and the loader/projector serve broad UI/effect/human/riding/static-object consumers.

### Large loader C++ readiness and no-improvement proof

[UID:0002P4] clears the numeric code-entry gate, but the revised audit still rejects a formal body. This is a target-specific no-improvement proof, not a placeholder: the named blockers from the supervisor rejection were checked one by one against current docs, old reports, and MCP decompile/callee/string evidence.

Behavior now proven:

- Direct mode (`mode == 0`) constructs a stack `DATFile`, allocates a 12-byte table header through `MemoryMan::AllocateBufferMemory`, opens the requested DAT entry, reads the 8-byte metadata header and 4-byte record-table offset, obtains the data base with `DATFile::GetDataPointer`, seeks to the record table, allocates `24 * (frameCount + 1)` records, reads per-record bounds and two payload offsets, rebases both payload pointers by the DAT data base, appends a sentinel record, closes the DATFile, destroys the stack object, and returns the table.
- Merge mode (`mode` 1 through 18) maps the mode to an EPF prefix, scans up to 100 shard names with `%s%d.EPF`, probes each with `HasDATEntry`, allocates temporary header and `DATFile` object arrays, opens each shard, accumulates frame counts and max dimensions, allocates the merged record table, reads/rebases every shard record, appends a sentinel from the final shard state, closes and destroys all shard DATFiles, frees temporary arrays, destroys the stack object, and returns the merged table.
- Raw UTF-16 bytes confirm the observed prefix/order table: `HEAD`, `HEADSP`, `BODY`, `SWORD`, `SPEAR`, `BOW`, `FAN`, `SHIELD`, `ARROW`, `FACE`, `HAIR`, `ACE1`, `ACE2`, `HELMET`, `MANTLE`, `NECLACE`, `SHOES`, `COAT`. The binary spelling `NECLACE` must stay exact when quoting resource strings.

Dependency audit:

| Dependency / range | Current evidence checked | Result for 0002P4 body |
| --- | --- | --- |
| `0x00516030` `GetMemoryMan` | Exact by-memory page is `90/92` with formal C++; MCP confirms 6-byte global accessor. | Solved; not a body blocker. |
| `0x00516050` `MemoryMan::AllocateBufferMemory` | Exact by-memory page is `90/91` with formal `malloc`/throw wrapper; MCP confirms loader calls it for output header/records. | Solved; use as dependency in prose. |
| `0x00516170` `MemoryMan::FreeBufferMemory` and `0x00516220` `MemmoveWrapper` | Exact pages have formal C++; relevant to cleanup helpers and raw copy helpers. | Solved; not a 0002P4 blocker. |
| DATFile `0x0049c130`, `0x0049c160`, `0x0049c180`, `0x0049c240`, `0x0049c260`, `0x0049c310`, `0x0049c550` | `by-file/DATFile.md`, `by-class/DATFile.md`, `DATFileLayout`, and aggregate DATFile memory page document constructor/destructor/open/close/seek/read/data-pointer roles and 20-byte layout, but formal method C++ and final field/member declaration names remain blank/provisional. MCP confirms all seven calls are present in 0002P4. | Still a body blocker. Emitting `DATFile file; file.Open(...); file.Read(...);` is readable but would invent unaccepted method declarations and source-visible field/lifetime shape. |
| `0x0049c700` `HasDATEntry` | Exact memory page has formal `bool HasDATEntry(const wchar_t *entryName)`; global alias page remains stale/blank. MCP confirms merge-mode shard probing calls this helper. | Source-facing name is usable, but callback should prefer exact memory page and optionally sync the stale global alias only if support scope is expanded. Not enough to unblock full body by itself. |
| `0x0041b9b0` wide format wrapper | MCP decompile shows a thin `__stdio_common_vswprintf_s` wrapper; used for prefix copy and `%s%d.EPF` formatting. | Use source-facing `swprintf_s`/bounded wide formatting in prose; no project helper body needed. |
| `0x004b7c50` rectangle edge writer | MCP decompile writes `left/top/right/bottom`; `RectBounds` docs support the layout. | Solved as `InitRectBounds` or equivalent inline assignment; not a blocker. |
| `0x004f4aa0` MemoryMan-backed operator-new wrapper | Operator wrapper page documents MemoryMan-backed allocation but formal C++ remains blank pending global operator declaration style. Merge mode uses this for constructed shard DATFile objects. | Still a body blocker for merge-mode object construction/lifetime; a formal 0002P4 body would need source-correct new/delete spelling. |
| `0x005c74f6`, `0x005c7790`, `0x005c7526`, `0x005c7799` CRT/runtime thunks | MCP identifies runtime operator-new/free thunks and scalar/free paths; decompile uses them for temporary pointer/header arrays and cleanup. | Still a body blocker. Current evidence does not prove whether original source used `new[]`, scalar `new`, helper arrays, or compiler-lowered temporaries. |
| Security cookie / EH cleanup | Full decompile includes cookie and partial-construction cleanup states around DATFile construction/open loops. | Compiler-generated details should not emit, but the source shape that caused them is not proven. |

Best source-facing names/types inferred but not finalized:

- Use `ArchiveMetadataTable`, `PackedArchiveRecord`, and `FrameDrawRecord` for the shared structures as recommended in [UID:0000UN].
- The loader's return value is best described as `ArchiveMetadataTable *`; the first parameter remains the DAT entry/resource name used by direct mode, while merge mode is driven by the second argument.
- The merge-mode/prefix concept can be documented as a resource-family or image-frame merge mode, but no accepted original enum name exists. Do not emit a new public enum name solely from the binary switch.
- Preserve binary resource strings exactly, especially `HEADSP`, `ACE1`, `ACE2`, and `NECLACE`; B004 HumanImageLib evidence agrees these strings should remain exact when quoted.

Rejected formal-body alternatives:

- **Full decompiler-shaped body:** rejected because it would encode compiler temporaries, exception-state locals, and manual array cleanup rather than source.
- **Direct-mode-only body:** rejected because [UID:0002P4] is one exact function covering both direct and merge modes; partial body emission would misrepresent the range.
- **RAII/`std::vector` rewrite:** rejected because it changes allocation order, cleanup order, and the observed operator-new/free behavior.
- **Plain `new[]`/`delete[]` temporary arrays:** rejected because the MCP evidence shows scalar/runtime allocation/free thunks and constructed `DATFile` objects, but does not prove the original source spelling.
- **Owner/split change:** rejected because the exact range has 25 direct xrefs across eight caller functions and remains ImageFrameTable-owned; DATFile is a dependency, not the owner.
- **Support-doc rewrite inside this pass:** rejected by assignment scope. The report can recommend support edits or exact no-edit proof, but must not edit target/support by-* docs during this revision.

Score/C++ impact: keep [UID:0002P4] at `85/89`, keep owner/emitter [UID:0000K1], and add the exact no-code/comment proof to the target docs. Do not raise the score in this report because the formal body is still blank and the blocker is source declaration/lifetime shape, not missing binary behavior. Generated `ImageFrameTable.cpp` should contain only the formal 0002P4 comment, while the smaller helpers and shared declarations can be emitted now.

### Small helper readiness

[UID:0002P5], [UID:0002P6], [UID:00031T], and [UID:00031U] are ready for first-draft source because their bodies are compact, exact ranges/padding are known, owner/emitter route is stable, and the shared declarations above are enough to avoid raw decompiler names. The raw helper pages keep lower confidence because there are no modeled functions or xrefs, but their source-looking prologues, `ret 0x0c`, 24-byte stride, and adjacency support emission as file-local helpers.

## Ranked Ownership Analysis

### 1. [UID:0000K1] ImageFrameTable

- Evidence for: source root already emits `auto-generated/NexusTK/render/ImageFrameTable.cpp`; exact helpers share EPF/EPD frame-table layout; caller spread crosses HumanImageLib, RidingImageLib, StaticObjImageLib, UI/effecters, and WaterFilter; raw helpers are physically adjacent to the projection helper and use the same 24-byte record model.
- Evidence against: final original file name and type names remain inferred; [UID:0002P4] is behavior-complete but still blocked for formal body code by exact DATFile declaration and merge-mode object-array/EH source-shape limits.
- Decision: keep as direct file owner/emitter for declarations and exact helper pages.

### 2. Asset-specific image-library owners

- Evidence for: consumers include HumanImageLib, RidingImageLib, StaticObjImageLib, MapTileImageLib, EffectObjImageLib, NewHumanImageLib, and effecter/UI classes.
- Evidence against: consumer spread proves shared utility use, not ownership; accepted B015 MapTile report explicitly rejects routing tile-specific loader [UID:0002J1] to ImageFrameTable but preserves shared declarations here.
- Decision: reject for this family. Keep as consumers or sibling helper owners only.

### 3. ResourceLayoutTable / EPFImageResources

- Evidence for: adjacent modeled function at `0x004d1730` and related EPF table record shape.
- Evidence against: raw helpers operate on the ImageFrameTable `ArchiveMetadataTable` record pointer and precede ResourceLayout accessors only by address adjacency; no xrefs to raw helper starts; file page already distinguishes `ResourceLayoutEntry` from ImageFrameTable records.
- Decision: reject as direct owner.

### 4. DATFile / DATArchive

- Evidence for: the loader depends heavily on DATFile lifecycle and DAT data-pointer helpers.
- Evidence against: DATFile is a dependency for reading resource payloads; the output table, record projection, and destroy helpers are render-resource semantics.
- Decision: reject as owner; keep as dependency.

## Source Placement

Recommended source placement remains `NexusTK/render/ImageFrameTable.cpp` with private declarations near the top of the file. The likely final source shape is:

- private `struct PackedArchiveRecord`;
- private or shared `struct ArchiveMetadataTable`;
- private or shared `struct FrameDrawRecord`;
- `LoadImageFrameTable` declaration/body later;
- `DestroyOwnedImageBlock`;
- `LoadFrameDrawRecord`;
- two file-local raw helpers equivalent to payload-copy and rect-copy helpers.

`ImageFrameTable.h` remains possible if these structures become shared declarations used across multiple source files, but current generated route is a `.cpp` file. This report recommends `.cpp`-local declarations first and a support-doc caveat that a later header split may move declarations without changing ownership.

## Range / Split / Padding / Reclassification Analysis

No new split is needed.

- [UID:000176] is already a reviewed non-emitting index/container and should remain `RECONSTRUCTABLE:FALSE`.
- The exact modeled functions are split as `0x004d0f50-0x004d15c5`, `0x004d15d0-0x004d15fc`, and `0x004d1600-0x004d165d`.
- The raw helpers already have exact pages at `0x004d1660-0x004d1704` and `0x004d1710-0x004d172d`.
- Padding is confirmed between children: `0x004d15c5-0x004d15d0`, `0x004d15fc-0x004d1600`, `0x004d165d-0x004d1660`, `0x004d1704-0x004d1710`, and `0x004d172d-0x004d1730`.

Recommended reclassification applies only to by-item aliases [UID:0000UX] and [UID:0000UY], not to exact by-memory code pages.

## First-Draft C++ / No-Code Disposition

### [UID:0000UN] EPFArchiveMetadataTable

Eligible for draft C++: yes, as declarations.

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
struct PackedArchiveRecord
{
    RectBounds bounds;
    unsigned char *payloadStart;
    unsigned char *payloadEnd;
};

struct ArchiveMetadataTable
{
    unsigned short frameCount;
    unsigned short maxWidth;
    unsigned short maxHeight;
    unsigned short reserved;
    PackedArchiveRecord *records;
};

struct FrameDrawRecord
{
    int reserved0;
    unsigned char *payloadStart;
    int reserved8;
    int width;
    RectBounds sourceRect;
    int payloadSpan;
    unsigned char *payloadEnd;
};
```

### [UID:0000UX] LoadFrameDrawRecord by-item alias

Eligible for draft C++: no, because this is an index/alias page whose exact source body belongs to [UID:0002P6].

Recommended metadata/source action: set `RECONSTRUCTABLE:FALSE`, clear `EMITTER_UIDS`, keep formal C++ blank, and add prose that the exact source body is covered by [UID:0002P6].

### [UID:0000UY] LoadImageFrameTable by-item alias

Eligible for draft C++: no, because this is an index/alias page whose exact source/no-code disposition belongs to [UID:0002P4].

Recommended metadata/source action: set `RECONSTRUCTABLE:FALSE`, clear `EMITTER_UIDS`, keep formal C++ blank, and add prose that the exact loader page carries the binary/source-readiness decision.

### [UID:0002P4] LoadImageFrameTable exact memory page

Eligible for full body draft C++ now: no.

Exact formal no-code/comment insertion recommended:

```cpp
// Source body for LoadImageFrameTable remains intentionally blank.
// Direct and merge-mode behavior at 0x004d0f50-0x004d15c5 is documented,
// including DATFile lifecycle, the 18 EPF prefix families, payload rebasing,
// sentinel setup, and cleanup. A formal body is not source-safe until the
// DATFile method declarations and merge-mode object-array/EH cleanup shape
// are stabilized; emitting decompiler-shaped arrays here would be misleading.
```

Reason code should remain blank/comment-only: the loader is behavior-understood but not source-safe for this family pass. The revision audited every named blocker:

- DATFile constructor/destructor/open/close/seek/read/data-pointer calls are identified and documented, but their accepted source declarations/formal bodies remain provisional or blank.
- MemoryMan allocation/free/memmove helpers are source-ready and are not the remaining blocker.
- `HasDATEntry`, bounded wide formatting, and `InitRectBounds` are resolved enough for prose, but they do not prove the original merge-mode object-array source form.
- Merge prefixes and mode order are verified from raw bytes, including `NECLACE`; no accepted enum/source name exists.
- CRT/runtime operator-new/free thunks and EH cleanup states still make scalar array/object lifetime unsafe to hand-port as formal C++.

The body should therefore stay comment-only at `85/89`. The implementation callback should update [UID:0002P4] with the exact proof above, not with a pseudo-body or vague deferral note.

### [UID:0002P5] DestroyOwnedImageBlock

Eligible for draft C++: yes.

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
void DestroyOwnedImageBlock(ArchiveMetadataTable *block)
{
    GetMemoryMan();

    if (block->records != NULL) {
        FreeBufferMemory(block->records);
    }

    FreeBufferMemory(block);
}
```

### [UID:0002P6] LoadFrameDrawRecord

Eligible for draft C++: yes.

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
void LoadFrameDrawRecord(const ArchiveMetadataTable *table,
                         int frameIndex,
                         FrameDrawRecord *outRecord)
{
    if (frameIndex < 0 || frameIndex >= table->frameCount) {
        outRecord->payloadStart = NULL;
        outRecord->payloadEnd = NULL;
        return;
    }

    const PackedArchiveRecord *record = &table->records[frameIndex];

    outRecord->payloadStart = record->payloadStart;
    outRecord->width = record->bounds.right - record->bounds.left;
    outRecord->sourceRect = record->bounds;
    outRecord->payloadEnd = record->payloadEnd;
    outRecord->payloadSpan = (int)(record[1].payloadStart - record->payloadEnd);
}
```

`void` is preferred over IDA's inferred `int` because current docs and caller evidence do not prove callers consume the residual return value; the `eax` value is compatible with compiler residue from assignments. If a future caller audit proves return consumption, change the signature to return the span while preserving the same output writes.

### [UID:00031T] FrameRecordPayloadCopyHelper

Eligible for draft C++: yes, as a file-local helper with no-xref caveat.

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
void CopyFrameRecordPayloads(const ArchiveMetadataTable *table,
                             int frameIndex,
                             FrameDrawRecord *outRecord)
{
    GetMemoryMan();

    if (frameIndex < 0 || frameIndex >= table->frameCount) {
        outRecord->payloadStart = NULL;
        outRecord->payloadEnd = NULL;
        return;
    }

    const PackedArchiveRecord *record = &table->records[frameIndex];
    const int firstSpan = (int)(record->payloadEnd - record->payloadStart);
    const int secondSpan = (int)(record[1].payloadStart - record->payloadEnd);

    outRecord->payloadStart = (unsigned char *)AllocateBufferMemory(firstSpan);
    MemmoveWrapper(outRecord->payloadStart, record->payloadStart, firstSpan);

    outRecord->width = record->bounds.right - record->bounds.left;
    outRecord->sourceRect = record->bounds;

    outRecord->payloadEnd = (unsigned char *)AllocateBufferMemory(secondSpan);
    MemmoveWrapper(outRecord->payloadEnd, record->payloadEnd, secondSpan);
    outRecord->payloadSpan = secondSpan;
}
```

### [UID:00031U] FrameRecordRectCopyHelper

Eligible for draft C++: yes, as a file-local helper with no-xref caveat.

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
void CopyFrameRecordBounds(const ArchiveMetadataTable *table,
                           int frameIndex,
                           RectBounds *outBounds)
{
    const PackedArchiveRecord *record = &table->records[frameIndex];
    *outBounds = record->bounds;
}
```

## Score And Metadata Recommendation

| UID | Current | Recommended | Rationale |
| --- | --- | --- | --- |
| `0000K1` | `89/86` | `90/88` | File-family report resolves generated empty-emitter classification and source/no-code disposition while preserving final filename/type caveats below 95. |
| `0000UN` | `85/90` | `88/91` | Declaration block and current MCP validation make the shared layout source-ready; exact original names remain inferred. |
| `0000UX` | `85/90`, `TRUE`, emitter `0000K1` | `86/91`, `FALSE`, no emitter | Corrects duplicate by-item emission; exact code is [UID:0002P6]. |
| `0000UY` | `86/90`, `TRUE`, emitter `0000K1` | `87/91`, `FALSE`, no emitter | Corrects duplicate by-item emission; exact source/no-code decision is [UID:0002P4]. |
| `0002P4` | `85/89` | `85/89` | Keep conservative; revised no-code/comment proof is audit-ready, but formal body emission remains unsafe because DATFile method declarations, merge-prefix enum/name policy, and MSVC object-array/EH cleanup source shape are not finalized. |
| `0002P5` | `85/90` | `88/92` | Tiny two-level cleanup helper is source-ready. |
| `0002P6` | `86/90` | `88/92` | Projection helper is source-ready with inferred declarations and accepted `FrameDrawRecord` type. |
| `00031T` | `85/88` | `86/89` | Source-ready raw helper, but no modeled function/xrefs caps confidence. |
| `00031U` | `85/88` | `86/89` | Source-ready raw helper, but no modeled function/xrefs caps confidence. |

No owner/emitter route change is recommended for exact by-memory pages. Only the duplicate by-item alias pages should become non-emitting.

## Recommended Target Doc Changes

Target path: `by-file/ImageFrameTable.md`

Incorporate:

- Current MCP database/session `B005_00049P_20260629` health, function lookup, analyze/disasm/xref/entity/byte facts, plus the 0002P4 dependency audit against DATFile, MemoryMan, HasDATEntry, operator wrapper, formatting, RectBounds, and raw prefix-string evidence.
- Generated-output classification: eight current empty markers split into declaration, duplicate index, source-ready helper, raw helper, and large-loader deferred categories.
- Score update to `90/88`.
- Note that [UID:0000UX] and [UID:0000UY] should be non-emitting index pages to avoid duplicate generated bodies.
- Note that [UID:0002P4] remains exact owner/source route but should receive only the audited no-code/comment proof: behavior is known, MemoryMan/HasDATEntry/format/RectBounds helpers are mostly solved, and the remaining body blockers are DATFile method declarations plus merge-mode object-array/EH cleanup source shape.
- Note that [UID:0002P5], [UID:0002P6], [UID:00031T], and [UID:00031U] are source-ready first-draft helper bodies.

## Recommended Support Doc Changes

Support paths and intended changes:

- `by-item/EPFArchiveMetadataTable.md`: raise to `88/91`, add declaration C++, preserve inferred-name caveat and relation to GrafPort/WaterFilter accepted `FrameDrawRecord` usage.
- `by-item/LoadFrameDrawRecord_004D1600.md`: reclassify as non-emitting index/support page; point exact source body to [UID:0002P6]; update score to `86/91`.
- `by-item/LoadImageFrameTable_004D0F50.md`: reclassify as non-emitting index/support page; point exact loader/no-code proof to [UID:0002P4]; update score to `87/91`.
- `by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md`: add current MCP facts, direct/merge-mode behavior summary, raw prefix table including `NECLACE`, dependency/callee audit, rejected body alternatives, exact formal no-code/comment proof, and explicit `85/89` no-score-change rationale.
- `by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md`: raise to `88/92`, replace stale item-summary text that still says unassigned/gate-blocked, add formal C++.
- `by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md`: raise to `88/92`, add current MCP facts and formal C++; preserve return-value caveat as resolved to source-level `void` unless future caller audit proves return use.
- `by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md`: raise to `86/89`, add current MCP disasm/xref/byte facts and formal C++; preserve no-function/no-xref caveat.
- `by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md`: raise to `86/89`, add current MCP disasm/xref/byte facts and formal C++; preserve no-function/no-xref caveat.
- `by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md`: update stale coverage-style wording that still says the aggregate is reconstructable or that DestroyOwnedImageBlock has an unresolved cleanup-owner question; keep metadata `RECONSTRUCTABLE:FALSE`, owner `NONE`, emitter blank.
- DATFile/MemoryMan/HasDATEntry support dependency docs: do not rewrite them during this callback unless supervisor explicitly expands scope. The current audit should cross-reference existing exact docs. Only optional dependency cleanup is to sync stale `by-global/HasDATEntry_49C700.md` with exact [UID:00012E] `by-memory/0x0049c700-0x0049c71d.HasDATEntry.md`; this is not required to unblock ImageFrameTable because the exact memory page already carries the source-ready body.

Manual `-coverage-report.md` edits are not recommended for the B-agent callback. The validator should refresh generated reports after the source docs validate. Existing manual coverage rows are stale, but this assignment forbids manual coverage edits; supervisor can decide whether to apply manual coverage text separately.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | [UID:0000K1] remains the correct source root for `auto-generated/NexusTK/render/ImageFrameTable.cpp`. | High | by-file target, generated file, MCP caller spread, support reports. | `by-file/ImageFrameTable.md`; all exact children. | incorporate | applied: by-file target updated to current ownership/source-placement and child disposition; validators `000000001236` and `000000001240`-`000000001244` proved generated output under `render/ImageFrameTable.cpp`. |
| C02 | Pre-callback generated file had eight empty markers under header `000000001170` / `2026-06-29T20:20:23-04:00`. | High | Generated output read. | Target generated-output notes; report checklist. | incorporate as historical baseline | applied: by-file/report now historicalize the empty state; post-callback generated header is `000000001256` / `2026-06-29T21:40:04-04:00` with no ImageFrameTable `Empty Emitter Marker`. |
| C03 | [UID:0000UN] should emit declarations for `PackedArchiveRecord`, `ArchiveMetadataTable`, and `FrameDrawRecord`. | Medium-high | EPFArchiveMetadataTable docs, LoadFrame/GrafPort reports, MCP offsets. | `by-item/EPFArchiveMetadataTable.md`; target file notes. | incorporate | applied: formal declaration C++ inserted; validator `000000001237` exit `0`, `ok: 1`; generated file contains [UID:0000UN]. |
| C04 | [UID:0000UX] is a duplicate index/alias and should not emit a separate body. | High | by-item points to exact [UID:0002P6]; generated duplicate risk. | `by-item/LoadFrameDrawRecord_004D1600.md`; target file notes. | incorporate | applied: by-item reclassified `RECONSTRUCTABLE:FALSE` with blank emitter/code; validator `000000001238` exit `0`, `ok: 1`; [UID:0000UX] absent from generated `ImageFrameTable.cpp`. |
| C05 | [UID:0000UY] is a duplicate index/alias and should not emit a separate body. | High | by-item points to exact [UID:0002P4]; generated duplicate risk. | `by-item/LoadImageFrameTable_004D0F50.md`; target file notes. | incorporate | applied: by-item reclassified `RECONSTRUCTABLE:FALSE` with blank emitter/code; validator `000000001239` exit `0`, `ok: 1`; [UID:0000UY] absent from generated `ImageFrameTable.cpp`. |
| C06 | [UID:0002P4] range is exact `0x004d0f50-0x004d15c5`, size `0x675` / 1653, with 25 direct xrefs and eight caller functions. | High | MCP lookup/analyze/xrefs/int_convert. | `by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md`; target file notes. | incorporate | applied: exact range/size/xref/caller facts added to [UID:0002P4] and by-file notes; validator `000000001240` exit `0`, `ok: 1`. |
| C07 | [UID:0002P4] should stay comment/no-code for this callback, not a full body, after dependency-specific audit of direct mode, merge mode, callee set, DATFile declarations, MemoryMan helpers, HasDATEntry, formatting, RectBounds, operator-new/free thunks, and EH cleanup. | High | Full MCP decompile/callee/xref analysis; support docs; raw prefix bytes; rejected-alternative proof. | [UID:0002P4] reconstruction notes/formal comment; target file notes. | incorporate | applied: exact formal no-code comment inserted and generated; [UID:0002P4] documents dependency audit and rejected alternatives; validator `000000001240` exit `0`, `ok: 1`. |
| C08 | [UID:0002P5] is source-ready two-level cleanup helper for ImageFrameTable blocks. | High | MCP decompile/disasm/callers; constructor/destructor support reports. | [UID:0002P5]; target file notes. | incorporate | applied: formal `DestroyOwnedImageBlock` body inserted; stale gate-blocker wording removed; validator `000000001241` exit `0`, `ok: 1`; generated file contains [UID:0002P5]. |
| C09 | [UID:0002P6] is source-ready frame-record projection helper; source signature should be `void` unless future caller audit proves return use. | Medium-high | MCP decompile/disasm/xrefs; GrafPort report. | [UID:0002P6]; [UID:0000UN]; target file notes. | incorporate | applied: formal `void LoadFrameDrawRecord` body and return rationale inserted; validator `000000001242` exit `0`, `ok: 1`; generated file contains [UID:0002P6]. |
| C10 | [UID:00031T] is source-looking raw helper at `0x004d1660-0x004d1704`, size `0xa4` / 164, with no modeled function/xrefs. | High | MCP lookup/disasm/xrefs/get_bytes/int_convert. | [UID:00031T]; target file notes; aggregate page. | incorporate | applied: disassembly/xref/byte proof, no-function/no-xref caveat, ownership rationale, and formal C++ inserted; validator `000000001243` exit `0`, `ok: 1`; generated file contains [UID:00031T]. |
| C11 | [UID:00031U] is source-looking raw helper at `0x004d1710-0x004d172d`, size `0x1d` / 29, with no modeled function/xrefs. | High | MCP lookup/disasm/xrefs/get_bytes/int_convert. | [UID:00031U]; target file notes; aggregate page. | incorporate | applied: disassembly/xref/byte proof, no-function/no-xref caveat, ownership rationale, and formal C++ inserted; validator `000000001244` exit `0`, `ok: 1`; generated file contains [UID:00031U]. |
| C12 | The raw helpers should stay ImageFrameTable-owned, not ResourceLayout-owned, despite adjacency to `0x004d1730`. | High | Record stride semantics, no xrefs, target docs, entity query. | [UID:00031T], [UID:00031U], target file notes. | incorporate | applied: by-file, raw-helper pages, and aggregate page document ImageFrameTable ownership and reject ResourceLayout ownership; validators `000000001236`, `000000001243`, `000000001244`, and `000000001245` exit `0`, `ok: 1`. |
| C13 | [UID:000176] remains a non-emitting index/container and should not emit aggregate C++. | High | Current aggregate doc, by-structure, MCP entity query. | `by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md`; target file notes. | incorporate | applied: aggregate page still `RECONSTRUCTABLE:FALSE`, owner `NONE`, blank emitter/code, and now points exact child output/no-code decisions to child pages; validator `000000001245` exit `0`, `ok: 1`. |
| C14 | Existing manual coverage rows are stale for this family, but B006 must not edit manual coverage reports in this phase/callback unless explicitly instructed. | High | coverage report reads; user restrictions. | Report only; optional supervisor note. | not-applicable | excluded from by-* edits: manual `-coverage-report.md` files were intentionally not edited under user restriction; validator-owned generated coverage/report refreshes are side effects only. |
| C15 | 0002P4 direct-mode behavior is behavior-complete: stack DATFile, 12-byte table header, 8-byte metadata read, 4-byte record offset read, data-base rebasing, `24 * (count + 1)` record allocation, sentinel append, close/destruct, and return. | High | Full `decompile 0x004d0f50`; DATFile/MemoryMan support docs. | [UID:0002P4] behavior notes. | incorporate | applied: [UID:0002P4] now records direct-mode behavior with exact sizes and lifecycle facts; validator `000000001240` exit `0`, `ok: 1`. |
| C16 | 0002P4 merge-mode behavior is behavior-complete: modes 1-18 map to EPF prefixes, scan up to 100 shards with `%s%d.EPF`, probe `HasDATEntry`, allocate shard header/DATFile arrays, accumulate counts/dimensions, merge/rebase records, append sentinel, close/destroy/free temporaries. | High | Full `decompile 0x004d0f50`; raw prefix bytes; `HasDATEntry` and DATFile support docs. | [UID:0002P4] behavior notes. | incorporate | applied: [UID:0002P4] now records merge-mode control flow, allocation/lifetime facts, and source-shape blocker; validator `000000001240` exit `0`, `ok: 1`. |
| C17 | The merge prefix table is verified as `HEAD`, `HEADSP`, `BODY`, `SWORD`, `SPEAR`, `BOW`, `FAN`, `SHIELD`, `ARROW`, `FACE`, `HAIR`, `ACE1`, `ACE2`, `HELMET`, `MANTLE`, `NECLACE`, `SHOES`, `COAT`; `NECLACE` must stay exact when quoted. | High | Raw UTF-16 `get_bytes`; B004 HumanImageLib prefix evidence. | [UID:0002P4] notes; target file source-name caveat. | incorporate | applied: [UID:0002P4] includes the raw prefix table and preserves exact `NECLACE`; by-file notes preserve the exact spelling; validator `000000001240` exit `0`, `ok: 1`. |
| C18 | DATFile method declarations remain the main source-safety blocker: method roles and 20-byte layout are documented, but accepted formal method C++/member declarations are still provisional/blank. | Medium-high | DATFile file/class/type/memory docs; MCP callee lookup/decompile. | [UID:0002P4] no-code proof; optional DATFile support note. | incorporate | applied: [UID:0002P4] names DATFile method declarations/source-visible field-lifetime shape as a specific blocker, not vague range/owner uncertainty; validator `000000001240` exit `0`, `ok: 1`. |
| C19 | MemoryMan helpers are not the remaining 0002P4 blocker because exact pages already provide source-ready `GetMemoryMan`, `AllocateBufferMemory`, `FreeBufferMemory`, and `MemmoveWrapper` bodies. | High | Exact MemoryMan by-memory pages; MCP lookup/decompile. | [UID:0002P4] no-code proof. | incorporate | applied: [UID:0002P4] explicitly documents MemoryMan helpers, `HasDATEntry`, formatting, and `RectBounds` as not the remaining blocker where evidence supports that; validator `000000001240` exit `0`, `ok: 1`. |
| C20 | Runtime operator-new/free thunks and merge-mode partial-construction/EH cleanup are still unsafe to hand-port because current evidence does not prove original source used arrays, helper containers, or compiler-lowered temporaries. | Medium-high | MCP `lookup_funcs`/decompile for `0x004f4aa0`, `0x005c74f6`, `0x005c7526`, `0x005c7790`, `0x005c7799`; full loader decompile. | [UID:0002P4] no-code proof. | incorporate | applied: [UID:0002P4] rejects decompiler-shaped arrays, direct-only body, RAII/vector rewrite, and guessed `new[]`/`delete[]` spelling; validator `000000001240` exit `0`, `ok: 1`. |
| C21 | No support dependency by-* edit is required in this report phase; DATFile, MemoryMan, HasDATEntry, and RectBounds docs were used as evidence, while optional stale global HasDATEntry alias sync should only happen if supervisor expands implementation scope. | High | Assignment scope; support-doc comparison. | Report support-doc recommendations only. | not-applicable | excluded from by-* edits: callback scope forbade rewriting DATFile/MemoryMan/HasDATEntry/RectBounds support docs unless contradiction blocked accepted edits; no contradiction blocked the callback, so support docs were left untouched. |

## Open Questions With Attempted Resolution

- Exact original type names: no symbols found. The report resolves this by recommending best source-facing inferred names and marking them inferred, not by leaving the family unaddressed.
- `LoadFrameDrawRecord` return value: IDA infers `int`, but current caller/docs do not prove return consumption and existing source-facing docs use a `void` helper shape. Resolve to `void` first-draft source, with a documented future condition for changing it.
- `LoadImageFrameTable` full body: resolved as audited no-code/comment-only for this family report. The exact range, direct behavior, merge behavior, prefix table, callee/dependency set, and rejected body alternatives are documented; the remaining blocker is source-safe DATFile/object-array/EH declaration shape, not missing binary behavior.
- Raw helper reachability: no xrefs to starts/ends. Resolved as source-looking file-local helpers retained in binary; emit first-draft helpers but keep scores below final-source confidence and preserve no-xref caveat.

## Validator And Generated-Output Expectations

Implementation callback validators were run from `source-3/project-documentation`.

| Doc | Exact command | command_id / command_timestamp | Exit / ok | Generated result |
| --- | --- | --- | --- | --- |
| `by-file\ImageFrameTable.md` | `python .\tools\validator.py --mode file --file by-file\ImageFrameTable.md --apply --queue-timeout 240 --wait-generated` | `000000001236` / `2026-06-29T21:33:05-04:00` | exit `0`, `ok: 1` | `generated_refresh: completed`; generated refresh command/timestamp match `000000001236` / `2026-06-29T21:33:05-04:00`. |
| `by-item\EPFArchiveMetadataTable.md` | `python .\tools\validator.py --mode file --file by-item\EPFArchiveMetadataTable.md --apply --queue-timeout 240 --wait-generated` | `000000001237` / `2026-06-29T21:33:24-04:00` | exit `0`, `ok: 1` | `generated_refresh: completed`; generated refresh command/timestamp match `000000001237` / `2026-06-29T21:33:24-04:00`. |
| `by-item\LoadFrameDrawRecord_004D1600.md` | `python .\tools\validator.py --mode file --file by-item\LoadFrameDrawRecord_004D1600.md --apply --queue-timeout 240` | `000000001238` / `2026-06-29T21:33:54-04:00` | exit `0`, `ok: 1` | `generated_refresh: deferred`; by-item became non-emitting, no generated entry. |
| `by-item\LoadImageFrameTable_004D0F50.md` | `python .\tools\validator.py --mode file --file by-item\LoadImageFrameTable_004D0F50.md --apply --queue-timeout 240` | `000000001239` / `2026-06-29T21:33:56-04:00` | exit `0`, `ok: 1` | `generated_refresh: deferred`; by-item became non-emitting, no generated entry. |
| `by-memory\0x004d0f50-0x004d15c5.LoadImageFrameTable.md` | `python .\tools\validator.py --mode file --file by-memory\0x004d0f50-0x004d15c5.LoadImageFrameTable.md --apply --queue-timeout 240` | `000000001240` / `2026-06-29T21:33:57-04:00` | exit `0`, `ok: 1` | `generated_refresh: deferred`; generated file contains [UID:0002P4] no-code comment. |
| `by-memory\0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md` | `python .\tools\validator.py --mode file --file by-memory\0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md --apply --queue-timeout 240` | `000000001241` / `2026-06-29T21:33:59-04:00` | exit `0`, `ok: 1` | `generated_refresh: deferred`; generated file contains [UID:0002P5] body. |
| `by-memory\0x004d1600-0x004d165d.LoadFrameDrawRecord.md` | `python .\tools\validator.py --mode file --file by-memory\0x004d1600-0x004d165d.LoadFrameDrawRecord.md --apply --queue-timeout 240` | `000000001242` / `2026-06-29T21:34:01-04:00` | exit `0`, `ok: 1` | `generated_refresh: deferred`; generated file contains [UID:0002P6] body. |
| `by-memory\0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md` | `python .\tools\validator.py --mode file --file by-memory\0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md --apply --queue-timeout 240` | `000000001243` / `2026-06-29T21:34:03-04:00` | exit `0`, `ok: 1` | `generated_refresh: deferred`; generated file contains [UID:00031T] body. |
| `by-memory\0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md` | `python .\tools\validator.py --mode file --file by-memory\0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md --apply --queue-timeout 240` | `000000001244` / `2026-06-29T21:34:04-04:00` | exit `0`, `ok: 1` | `generated_refresh: deferred`; generated file contains [UID:00031U] and was later observed under header `000000001256`. |
| `by-memory\0x004d0f50-0x004d165d.ImageFrameTable.md` | `python .\tools\validator.py --mode file --file by-memory\0x004d0f50-0x004d165d.ImageFrameTable.md --apply --queue-timeout 240` | `000000001245` / `2026-06-29T21:34:06-04:00` | exit `0`, `ok: 1` | `generated_refresh: deferred`; aggregate remained non-emitting and did not change `ImageFrameTable.cpp` content beyond [UID:00031U]. |

Validator warnings observed: non-fatal project-wide autogen noise remained during generated refresh, including `autogen_emitter_has_no_code`, `autogen_children_marker_missing`, and fallback child-marker warnings on unrelated docs. No scoped ImageFrameTable target validator failed, and every scoped command returned exit `0` with `ok: 1`.

Primary side effects:

- `000000001236`: `completion_update 0000K1 90`, `confidence_update 0000K1 88`, UID link insertions for referenced child/support UIDs, `autogen_cpp_update: 1`, `autogen_report_update: 1`, `memory_auto_coverage_update: 1`, `research_tracker_update: 1`, `projected_stats_update: 1`, `generated_metadata_refresh: 279`, foreground generated refresh completed.
- `000000001237`: `completion_update 0000UN 88`, `confidence_update 0000UN 91`, registry code block update, generated metadata refresh `281`, research tracker/projected stats updates, foreground generated refresh completed.
- `000000001238`: `completion_update 0000UX 86`, `confidence_update 0000UX 91`, `RECONSTRUCTABLE TRUE -> FALSE`, `EMITTER_UIDS 0000K1 ->`, UID link insertions, generated refresh deferred.
- `000000001239`: `completion_update 0000UY 87`, `confidence_update 0000UY 91`, `RECONSTRUCTABLE TRUE -> FALSE`, `EMITTER_UIDS 0000K1 ->`, UID link insertions, generated refresh deferred.
- `000000001240`: registry code block update for [UID:0002P4], UID link insertion to [UID:0000UN], generated refresh deferred.
- `000000001241`: `completion_update 0002P5 88`, `confidence_update 0002P5 92`, registry code block update, generated refresh deferred.
- `000000001242`: `completion_update 0002P6 88`, `confidence_update 0002P6 92`, registry code block update, UID link insertions to [UID:0000UN], generated refresh deferred.
- `000000001243`: `completion_update 00031T 86`, `confidence_update 00031T 89`, registry code block update, generated refresh deferred.
- `000000001244`: `completion_update 00031U 86`, `confidence_update 00031U 89`, registry code block update, generated refresh deferred.
- `000000001245`: UID link insertions for the aggregate index, generated refresh deferred; generated research/coverage files later refreshed under command `000000001245`.

Generated freshness:

- Queue status after final freshness check: `python .\tools\validator.py --queue-status` returned `command_id: 000000001260`, `command_timestamp: 2026-06-29T21:42:17-04:00`, `queued jobs: 0`, `processing jobs: 0`, `queued generated refresh jobs: 0`, `processing generated refresh jobs: 0`.
- Final observed `auto-generated/NexusTK/render/ImageFrameTable.cpp` header: `validator-command-id: 000000001256`, `validator-refreshed-at: 2026-06-29T21:40:04-04:00`, `validator-refresh-source: foreground-generated-refresh`.
- Generated content contains [UID:0000UN], [UID:0002P4], [UID:0002P5], [UID:0002P6], [UID:00031T], and [UID:00031U]; it contains no `Empty Emitter Marker`, no [UID:0000UX], and no [UID:0000UY].

## Changed Files

- Modified in place: `source-3/project-documentation/tools/leaser/Agents/Agent-B006/research/0000K1-ImageFrameTable-empty-emitter-family-source-quality.md`
- Modified target/support docs:
  - `by-file/ImageFrameTable.md`
  - `by-item/EPFArchiveMetadataTable.md`
  - `by-item/LoadFrameDrawRecord_004D1600.md`
  - `by-item/LoadImageFrameTable_004D0F50.md`
  - `by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md`
  - `by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md`
  - `by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md`
  - `by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md`
  - `by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md`
  - `by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md`
- Validator-owned generated side effects observed, not edited by hand: `auto-generated/NexusTK/render/ImageFrameTable.cpp`, generated coverage/research tracker files, generated metadata/state refresh files.
- Manual `-coverage-report.md` files, generated C++ under `auto-generated/`, project-level generated reports, validator state, and supervisor ledgers were not manually edited.
- Leases: acquired successfully for all ten target/support docs before editing. Release command after validation returned `Rejected[No active lease]` for each target because no `Agent-B006` active lease remained. `tools/leaser/Agents/current_leases.md` then showed no `Agent-B006` rows; only unrelated `B005` ExchangeDialog leases were active. `tools/leaser/Agents/Agent-B006/lease_status.md` does not exist.
- Report execution: not run, moved, archived, or executed; supervisor retains execution/archival control.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor accepted the revised report for implementation callback.
- [x] Target doc `by-file/ImageFrameTable.md`: update score to `90/88`; incorporate MCP database/session `B005_00049P_20260629` facts, generated-empty classification, ownership/source-placement decisions, and per-emitter C++/no-code disposition. Proof: validator `000000001236` exit `0`, `ok: 1`.
- [x] `by-item/EPFArchiveMetadataTable.md`: update score to `88/91`; insert exact declaration C++ for `PackedArchiveRecord`, `ArchiveMetadataTable`, and `FrameDrawRecord`; preserve inferred-name caveat. Proof: validator `000000001237` exit `0`, `ok: 1`.
- [x] `by-item/LoadFrameDrawRecord_004D1600.md`: reclassify as non-emitting index/support page with `RECONSTRUCTABLE:FALSE`, blank emitter/code, score `86/91`, and proof that exact body is [UID:0002P6]. Proof: validator `000000001238` exit `0`, `ok: 1`; [UID:0000UX] absent from generated output.
- [x] `by-item/LoadImageFrameTable_004D0F50.md`: reclassify as non-emitting index/support page with `RECONSTRUCTABLE:FALSE`, blank emitter/code, score `87/91`, and proof that exact loader/no-code decision is [UID:0002P4]. Proof: validator `000000001239` exit `0`, `ok: 1`; [UID:0000UY] absent from generated output.
- [x] `by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md`: keep score `85/89`; add current MCP evidence, direct/merge-mode behavior proof, raw prefix table with exact `NECLACE`, dependency/callee audit, rejected body alternatives, and formal no-code/comment proof; preserve blocker as DATFile method declaration plus merge-mode object-array/EH source shape, not owner/range uncertainty. Proof: validator `000000001240` exit `0`, `ok: 1`; generated [UID:0002P4] contains the formal no-code comment.
- [x] `by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md`: update score to `88/92`; replace stale unassigned/gate-blocker wording; insert exact formal C++. Proof: validator `000000001241` exit `0`, `ok: 1`; generated [UID:0002P5] contains the helper body.
- [x] `by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md`: update score to `88/92`; add current MCP evidence, `void` return rationale, and exact formal C++. Proof: validator `000000001242` exit `0`, `ok: 1`; generated [UID:0002P6] contains the helper body.
- [x] `by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md`: update score to `86/89`; add current MCP disassembly/xref/byte proof and exact formal C++. Proof: validator `000000001243` exit `0`, `ok: 1`; generated [UID:00031T] contains the helper body.
- [x] `by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md`: update score to `86/89`; add current MCP disassembly/xref/byte proof and exact formal C++. Proof: validator `000000001244` exit `0`, `ok: 1`; generated [UID:00031U] contains the helper body.
- [x] `by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md`: preserve `RECONSTRUCTABLE:FALSE`, owner `NONE`, blank emitter/code; refresh stale wording about DestroyOwnedImageBlock ownership and current child state. Proof: validator `000000001245` exit `0`, `ok: 1`.
- [x] Claim And Incorporation Ledger updated with callback verification state for C01-C21. Proof: ledger above marks C01-C13 and C15-C20 applied, C14/C21 explicitly excluded from by-* edits with reason.
- [x] Support dependency docs: do not rewrite DATFile/MemoryMan/HasDATEntry/RectBounds docs unless supervisor expands implementation scope; optional stale global HasDATEntry alias sync is non-blocking because exact memory page [UID:00012E] already has the source-ready body. Proof: support docs were not edited; [UID:0002P4] records support evidence and blocker scope.
- [x] Scoped validators run for every changed by-* file, including generated refresh for `ImageFrameTable.cpp`. Proof: validator table above records commands `000000001236`-`000000001245`.
- [x] Generated `auto-generated/NexusTK/render/ImageFrameTable.cpp` freshness checked after validators; report whether [UID:0000K1] still has empty markers and whether by-item duplicate emitters disappeared as expected. Proof: final header `000000001256` / `2026-06-29T21:40:04-04:00`; no empty markers; [UID:0000UX]/[UID:0000UY] absent.
- [x] Manual `-coverage-report.md` files remain unedited unless supervisor explicitly grants a callback override. Proof: no manual coverage files were edited; only validator-owned generated refreshes occurred.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: callback request explicitly accepted the revised report.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: all ten listed target/support docs were edited and validated.
- [x] Claim And Incorporation Ledger updated with callback verification state for every accepted claim. Proof: C01-C21 states are updated above.
- [x] Metadata/score/owner/emitter/reconstructable/C++ changes applied or explicitly not applied with reason. Proof: validators `000000001236`-`000000001245`; C14/C21 are marked excluded from by-* edits by scope.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target docs now distinguish pre-callback empty emitters, stale Wave/provenance assumptions, no-xref raw helper caveats, rejected 0002P4 body alternatives, and corrected child ownership.
- [x] Validators run and command IDs/timestamps/exit/ok counts recorded. Proof: validator table above.
- [x] Generated `ImageFrameTable.cpp` refresh state and empty-marker status recorded. Proof: final generated header and content status above.
- [x] Remaining unapplied accepted items listed with exact blocker, if any. Proof: no accepted target/support doc item remains unapplied; C14 and C21 are deliberate scope exclusions, not blockers.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0000K1-ImageFrameTable-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0000K1-ImageFrameTable-empty-emitter-family-source-quality.md","timestamp":"2026-06-29T21:45:08","uid":"0000K1"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
