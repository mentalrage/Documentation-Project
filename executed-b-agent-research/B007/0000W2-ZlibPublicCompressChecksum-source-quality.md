** TARGET-REPORT-UID:0000W2 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# Agent-B007 Report: [UID:0000W2] ZlibPublicCompressChecksum Source Quality

Assignment source: `source-3/project-documentation/tools/leaser/Agents/Agent-B007/goal.md`  
Assignment id: `B007-report-0000W2-zlib-public-compress-checksum-source-quality-20260626`  
Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/0000W2-ZlibPublicCompressChecksum-source-quality.md`  
Target: `by-memory/0x004142c0-0x00414565.ZlibPublicCompressChecksum.md`  
Mode: report-only research first. No by-* docs, generated reports, project-level files, or `-coverage-report.md` files were edited.

## Current Target State

Current metadata:

- `COMPLETION:86`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000PC`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000PC`
- `EMITTER_POSITION_OPTIONAL:` blank
- formal `RECONSTRUCTION_CPP CODE` block blank
- `Item Summary: zlib 1.1.4 source identity and source-file split.`
- `Nested:4`

Current page content is directionally correct: the range is bundled zlib 1.1.4, owner/emitter [UID:0000PC][Zlib](by-file/Zlib.md), parent [UID:0000W3][0x004142c0-0x00419e56.ZlibCore](by-memory/0x004142c0-0x00419e56.ZlibCore.md), with `compress2`, `compress`, `uncompress`, and `crc32` mapped to stock `compress.c`, `uncompr.c`, and `crc32.c`.

Current source-quality gaps:

- The generated research tracker row is stale and still lists `0000W2` as `80/85`; the current target page is `86/90`.
- The page records older 2026-06-15 MCP evidence, but not this assignment's live MCP session/schema, call IDs, xref counts, boundary bytes, staged source hashes, or current source-line anchors.
- The blank formal C++ block is still explained partly by old "below 95/95" wording in the Changes history. Current policy needs a target-specific third-party static-embed/no-code proof.
- The page is a mixed public zlib source-map page spanning `compress.c`, `uncompr.c`, and `crc32.c`, so a single formal static-embed marker would be less precise than exact source-file children. It should remain blank unless split later.

## MCP Session Status

Live IDA MCP was available and used. This report is not fallback-only work.

- Endpoint: `http://127.0.0.1:13337/mcp`
- Active database/session: `80de0a67`
- IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Health probe timestamp: 2026-06-26T22:30 EDT
- `server_health(database='80de0a67')`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- `tools/list` returned 65 tools. Current schema uses `database` on every tool call; `decompile`/`disasm` take single `addr`; `xrefs_to`/`callees` take `addrs`.

Request-shape caveat: JSON-RPC ids `201-212` failed because a PowerShell helper parameter was named `$args`, triggering the documented automatic-variable trap and dropping the tool arguments. Retried ids `221-235` used `$toolArgs` and succeeded. These failures are call-shape noise, not MCP unavailability.

## Evidence Checked

Docs and generated inputs checked:

- Target [UID:0000W2][0x004142c0-0x00414565.ZlibPublicCompressChecksum](by-memory/0x004142c0-0x00414565.ZlibPublicCompressChecksum.md)
- Parent [UID:0000W3][0x004142c0-0x00419e56.ZlibCore](by-memory/0x004142c0-0x00419e56.ZlibCore.md)
- Source owner [UID:0000PC][Zlib](by-file/Zlib.md)
- Siblings [UID:0000W4][0x00414820-0x004158aa.ZlibDeflateWorkers](by-memory/0x00414820-0x004158aa.ZlibDeflateWorkers.md), [UID:0000W5][0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler](by-memory/0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler.md), [UID:00041N][0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers](by-memory/0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md), and [UID:0000W6][0x00417ba0-0x00419e56.ZlibInflateInternals](by-memory/0x00417ba0-0x00419e56.ZlibInflateInternals.md)
- [UID:0001QE][client_libraries](by-meta/client_libraries.md)
- [UID:0001QX][Obtained Third-Party Files README](by-meta/obtained_thirdparty_files/README.md)
- `by-project-structure/proposed-source-tree.md`
- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `auto-generated/NexusTK/third_party/zlib/Zlib.cpp`
- Executed report `executed-b-agent-research/B002/0000W4-ZlibDeflateAndTrees-source-quality.md`
- Staged zlib source under `source-3/third_party_embeds/zlib/`
- Static evidence copy under `source-3/project-documentation/by-meta/obtained_thirdparty_files/static_embeds/zlib-1.1.4/`

Staged source hash evidence:

| File | SHA256 |
| --- | --- |
| `source-3/third_party_embeds/zlib/compress.c` | `33DC3E2AE63B27E605A741EFF245A9F01358A77593BAE6C46502CCBFF2F968A3` |
| `source-3/third_party_embeds/zlib/uncompr.c` | `31D19AE0F3284924D97D770525C0F2B9E5D4384F0D3EF90AA56A618A1FE7B565` |
| `source-3/third_party_embeds/zlib/crc32.c` | `9522F5B68C3C87BBDC55B5639B75015CB3DD4066097F81093BEE724ECE6FE2BC` |
| `source-3/third_party_embeds/zlib/zlib.h` | `7388AEB8CC550DCBC158FD43DC90EE900F5FC6A3D055CEAF4C83AA441E6D387F` |

The same four hashes match the `by-meta/obtained_thirdparty_files/static_embeds/zlib-1.1.4/` copies, confirming the staged rebuild source matches the documented third-party evidence copy. Source-line anchors in `source-3/third_party_embeds/zlib/` are `compress2` at `compress.c:21`, `compress` at `compress.c:61`, `uncompress` at `uncompr.c:25`, `get_crc_table` at `crc32.c:127`, `crc32` at `crc32.c:142`, and `ZLIB_VERSION "1.1.4"` at `zlib.h:40`.

## Live MCP Function And Boundary Evidence

MCP evidence batch timestamp: `2026-06-26T22:36:22.3434168-04:00`.

JSON-RPC id `221` `lookup_funcs`:

| Query | MCP result | Source identity |
| --- | --- | --- |
| `0x004142c0` | `sub_4142C0`, size `0xa9` | `compress.c:compress2` |
| `0x00414370` | `sub_414370`, size `0x1f` | `compress.c:compress` |
| `0x00414390` | `sub_414390`, size `0x9c` | `uncompr.c:uncompress` |
| `0x00414430` | `sub_414430`, size `0x135` | `crc32.c:crc32` |
| `0x00414565` | not a function | exact target endpoint after `crc32` return |
| `0x00414570` | `sub_414570`, size `0x25` | successor zlib `deflateInit_` wrapper |
| `0x0063211c` | not a function | zlib `crc_table[256]` data |
| `0x00671a74` | not a function | zlib `1.1.4` string/data |

JSON-RPC id `224` `get_bytes`:

- `0x004142b0` shows `e9 db ff ff ff` then eleven `0x90` bytes before the `compress2` prologue at `0x004142c0`.
- `0x00414360` shows the `compress2` epilogue/return at `0x00414368`, seven `0x90` bytes at `0x00414369-0x00414370`, then `compress`.
- `0x00414388` shows the tail of `compress`, return at `0x0041438e`, one `0x90` byte at `0x0041438f`, then `uncompress`.
- `0x00414420` shows the `uncompress` epilogue/return at `0x0041442b`, four `0x90` bytes at `0x0041442c-0x00414430`, then `crc32`.
- `0x00414558` shows the `crc32` tail and return at `0x00414564`, eleven `0x90` bytes at `0x00414565-0x00414570`, then the `deflateInit_` wrapper prologue.
- `0x0063211c` starts with bytes for the stock CRC table: `00 00 00 00 96 30 07 77 2c 61 0e ee ba 51 09 99 ...`.
- `0x00671a74` is `31 2e 31 2e 34 00 00 00 74 1a 67 00 ...`, the zlib `1.1.4` string and adjacent version pointer.

Recommended target range text should keep the current half-open body map:

| Range | Meaning |
| --- | --- |
| `0x004142c0-0x00414369` | `compress2` body |
| `0x00414369-0x00414370` | seven-byte alignment between `compress2` and `compress` |
| `0x00414370-0x0041438f` | `compress` body |
| `0x0041438f-0x00414390` | one-byte alignment between `compress` and `uncompress` |
| `0x00414390-0x0041442c` | `uncompress` body |
| `0x0041442c-0x00414430` | four-byte alignment between `uncompress` and `crc32` |
| `0x00414430-0x00414565` | `crc32` body |
| `0x00414565-0x00414570` | eleven-byte alignment before `deflateInit_`; outside the current target filename range |

## Behavior And Source Mapping

JSON-RPC ids `225-228` decompiled the four target functions.

`0x004142c0` matches stock `compress2`:

- builds a 56-byte `z_stream` local;
- assigns `next_in`, `avail_in`, `next_out`, and `avail_out`;
- zeros allocator/free/opaque slots;
- calls `deflateInit_` (`0x00414570`) with version string `1.1.4` at `0x00671a74` and stream size `56`;
- calls `deflate` (`0x00414820`) with flush mode `4` / `Z_FINISH`;
- on `Z_STREAM_END` writes `stream.total_out` back to `*destLen`;
- always calls `deflateEnd` (`0x00414b80`) after successful init;
- returns `Z_BUF_ERROR` (`-5`) when `deflate` returns `Z_OK`, otherwise the zlib status.

`0x00414370` matches stock `compress`:

- pushes level `-1` / `Z_DEFAULT_COMPRESSION`;
- tail-calls the local `compress2` entry at `0x004142c0`.

`0x00414390` matches stock `uncompress`:

- builds the same 56-byte `z_stream` local shape;
- assigns input/output pointers and lengths;
- zeros allocator/free callbacks;
- calls `inflateInit_` (`0x00415a60`) with version string `1.1.4` and stream size `56`;
- calls `inflate` (`0x00415a80`) with flush mode `4` / `Z_FINISH`;
- on `Z_STREAM_END` writes `stream.total_out` back to `*destLen`;
- calls `inflateEnd` (`0x00415900`) after successful init;
- returns `Z_BUF_ERROR` (`-5`) for a non-ending `Z_OK` result, otherwise the zlib status.

`0x00414430` matches stock `crc32`:

- returns zero when `buf == Z_NULL`;
- inverts the incoming CRC at entry and exit;
- uses an unrolled eight-byte loop plus tail loop;
- indexes `dword_63211C` / `crc_table[256]` at `0x0063211c`;
- does not call other functions.

JSON-RPC ids `229-232` disassembled the four functions and confirmed instruction counts: `55` for `compress2`, `12` for `compress`, `52` for `uncompress`, and `109` for `crc32`.

## Xref And Callee Evidence

JSON-RPC id `223` `callees`:

- `0x004142c0` calls `0x00414570`, `0x00414820`, and `0x00414b80`.
- `0x00414370` calls `0x004142c0`.
- `0x00414390` calls `0x00415a60`, `0x00415a80`, and `0x00415900`.
- `0x00414430` has no direct callees.

JSON-RPC id `222` `xrefs_to`:

- `compress2` at `0x004142c0` has one code xref from local `compress` at `0x00414386`.
- `compress` at `0x00414370` has two product/code xrefs: one unresolved raw call near `0x004a5510` and one from `0x00504e00`/`MapPaneSaveCompressedMapFile` at `0x00504fea`.
- `uncompress` at `0x00414390` has eight product/code xrefs, including known consumers [UID:0002TJ][DecodeZpfFpfToTileContext](by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md), `LogoPane`/startup-logo paths, `MapPaneLoadCompressedMapFile`, `MetaTable::DecompressAndValidateData`, and `DLPalette::LoadFromBitmapPalette`.
- `crc32` at `0x00414430` has one code xref from `0x00524730` / `MetaTable::DecompressAndValidateData`.
- `crc_table` at `0x0063211c` has nine data refs, all inside `0x00414430`.
- zlib version string `0x00671a74` has refs from `compress2`, `uncompress`, `inflateInit2_`, and the version-pointer slot at `0x00671a7c`.

JSON-RPC id `233` `lookup_funcs` on representative caller addresses confirmed:

- `0x004d068b` is inside [UID:0002TJ][DecodeZpfFpfToTileContext](by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md).
- `0x00504d99` is inside [UID:0002QJ][MapPaneLoadCompressedMapFile](by-memory/0x00504b90-0x00504df1.MapPaneLoadCompressedMapFile.md).
- `0x00504fea` is inside [UID:0002QK][MapPaneSaveCompressedMapFile](by-memory/0x00504e00-0x00505075.MapPaneSaveCompressedMapFile.md).
- `0x00524784` and `0x00524790` are inside the documented MetaTable decompression/checksum helper in [UID:0001CC][MetaTable](by-memory/0x00524630-0x00525914.MetaTable.md).
- `0x005430cb` is inside [UID:00041H][DLPaletteMethodCluster](by-memory/0x00542ac0-0x00543149.DLPaletteMethodCluster.md).

These product callers are consumers only. They do not move the zlib implementation into map, metadata, palette, logo, image-loader, or DAT modules.

## Ownership And Source Placement

Accepted owner/emitter remains [UID:0000PC][Zlib](by-file/Zlib.md).

Positive evidence:

- Active MCP confirms the exact wrapper/checksum function bodies, callees, xrefs, version-string refs, CRC-table refs, and boundary padding.
- Local staged source and documented static embed copies are hash-identical.
- `zlib.h` defines `ZLIB_VERSION "1.1.4"`, matching the version string used by `compress2` and `uncompress`.
- `compress.c` contains exactly the observed `compress2`/`compress` public wrapper pair.
- `uncompr.c` contains exactly the observed `uncompress` wrapper.
- `crc32.c` contains exactly the observed table-driven `crc32` body and stock static `crc_table`.
- Parent/sibling docs already place the successor `deflateInit_` at `0x00414570` and broader zlib code under the same by-file owner.

Rejected owners:

- `MetaTable`: rejected because it only consumes `Uncompress` and `Crc32` for metadata payload validation.
- `MapPane`: rejected because load/save map code only consumes public zlib wrappers for `.cmp` files.
- Image loaders / startup-logo / palette modules: rejected because they call `Uncompress` on assets but do not own zlib.
- DAT/resource modules: rejected because they may store compressed payloads but do not implement zlib.
- CRT/runtime/compiler ownership: rejected because these are stock third-party zlib source functions, not toolchain support.
- No-owner/non-emitting: rejected because owner/emitter route [UID:0000PC] is established and surfaces to `NexusTK/third_party/zlib/`.

## Split, Range, And Static-Embed Marker Decision

No mandatory new by-memory split is recommended for this implementation pass.

Reasoning:

- This target does not cross an unrelated owner or an already documented sibling the way the old broad [UID:0000W4] `deflate/trees` range did.
- The page is a compact public zlib source-map cluster at the head of [UID:0000W3].
- The page should explicitly document source-file boundaries inside the target, including internal alignment padding, rather than being forced into product ownership or decompiler C++.
- Exact source-file child pages could be created later if the supervisor wants every static-embed marker to be one source file per by-memory page, but that is not required to resolve `0000W2` ownership, emitter routing, behavior, or current score.

Formal C++ / static-embed decision:

- Keep [UID:0000W2]'s formal `RECONSTRUCTION_CPP CODE` block blank.
- Do not add `// Static embed: third_party_embeds/zlib/compress.c` to this mixed page alone, because it would cover only the first source file.
- Do not add a multi-line marker for `compress.c`, `uncompr.c`, and `crc32.c` to this mixed page, because current accepted static-embed marker style is strongest on exact source-file/source-bearing children. A mixed marker would be less precise and would obscure that `crc32.c:get_crc_table` is present in source at line 127 but not present as a modeled function in this binary range.
- Do not paste upstream zlib source or Hex-Rays-derived C into the page. The staged source is the source of record.

If exact marker children are later created, the suggested split is:

| Candidate child | Source marker | Caveat |
| --- | --- | --- |
| `0x004142c0-0x0041438f.ZlibCompressApi` | `// Static embed: third_party_embeds/zlib/compress.c` | Full linked `compress.c` public wrapper pair, with seven bytes of intra-file alignment between functions. |
| `0x00414390-0x0041442c.ZlibUncompressApi` | `// Static embed: third_party_embeds/zlib/uncompr.c` | Full linked `uncompr.c` body. |
| `0x00414430-0x00414565.ZlibCrc32` | `// Static embed: third_party_embeds/zlib/crc32.c` | Only `crc32` is linked as executable code here; `crc_table[256]` is in [UID:0003OJ][Zlib114ReadOnlyConstantsAndStrings](by-memory/0x00631850-0x00632560.Zlib114ReadOnlyConstantsAndStrings.md), and `get_crc_table` is not present as a target function. |

This optional split is not a blocker for the current report's recommended metadata update.

## Heuristic / Inference Reanalysis

Compiler/generated names:

- Final source-facing names should be `compress2`, `compress`, `uncompress`, and `crc32`, not `sub_4142C0`, `sub_414370`, `sub_414390`, or `sub_414430`.
- The IDA data label `dword_63211C` should remain an evidence alias only. Source-facing name is zlib `crc_table[256]`.
- The version string label `a114` should remain an evidence alias only. Source-facing name is zlib `ZLIB_VERSION` / `"1.1.4"`.

Raw/no-function concerns:

- There are no raw starts inside the target. All four target bodies are modeled functions.
- The endpoint `0x00414565` is correctly not a function; bytes `0x00414565-0x00414570` are alignment before successor `deflateInit_`.

Source-route inference:

- The source route is direct/strong, not adjacency-only: function order, call sequences, constants, version string, CRC table bytes, source hashes, and current MCP data all match the staged official zlib 1.1.4 files.
- Product xrefs show consumers only; no product caller contains code that would make the zlib routines product-owned.

Final-C++ blocker:

- The remaining blocker is not behavior uncertainty. It is source-map granularity: this page spans multiple stock zlib files, so formal reconstruction should stay blank on this page unless it is split into exact source-file children.
- This blank block is an intentional static-third-party source route decision, not a score-gate failure.

## Score And Metadata Recommendation

Recommended target metadata after implementation:

- `COMPLETION:89`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:0000PC`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000PC`
- `EMITTER_POSITION_OPTIONAL:` blank
- formal `RECONSTRUCTION_CPP CODE`: blank
- `Item Summary:` `Mixed zlib 1.1.4 public source-map page for compress.c compress2/compress, uncompr.c uncompress, and crc32.c crc32; current MCP/source-hash evidence supports owner/emitter 0000PC and blank formal C++ because exact static-embed markers belong on source-file children.`
- `Nested:4` should stay unchanged unless implementation changes actual nesting.

Rationale:

- Completion can rise from `86` to `89` after adding current MCP ids `221-235`, boundary/padding bytes, xrefs, staged source hashes, line anchors, rejected alternatives, and current formal no-code proof.
- Confidence can rise from `90` to `92` because current live MCP, source hashes, parent/sibling docs, and source version evidence all agree.
- Completion should stay below `90+` unless the implementation either creates exact source-file children with formal markers or documents an even more complete source-file/compile-option audit.
- Confidence stays below final/95+ because exact original symbols/PDB names and build options are not recovered, and the current target remains a mixed source-map page.

## Recommended By-* Implementation Changes

Target doc `by-memory/0x004142c0-0x00414565.ZlibPublicCompressChecksum.md`:

- Update Status to mention current MCP session/database `80de0a67`, current JSON-RPC ids `221-235`, and that this is a mixed public zlib source-map page.
- Replace old score-gate/no-C++ implication with an explicit static-third-party no-code proof.
- Add source provenance:
  - `source-3/third_party_embeds/zlib/compress.c` SHA256 `33DC3E2AE63B27E605A741EFF245A9F01358A77593BAE6C46502CCBFF2F968A3`
  - `source-3/third_party_embeds/zlib/uncompr.c` SHA256 `31D19AE0F3284924D97D770525C0F2B9E5D4384F0D3EF90AA56A618A1FE7B565`
  - `source-3/third_party_embeds/zlib/crc32.c` SHA256 `9522F5B68C3C87BBDC55B5639B75015CB3DD4066097F81093BEE724ECE6FE2BC`
  - `source-3/third_party_embeds/zlib/zlib.h` SHA256 `7388AEB8CC550DCBC158FD43DC90EE900F5FC6A3D055CEAF4C83AA441E6D387F`
  - Note that these match the `obtained_thirdparty_files/static_embeds/zlib-1.1.4/` copies.
- Expand the function map with padding rows listed in this report.
- Add current xref/callee summary from MCP ids `222` and `223`.
- Preserve product consumer notes but keep them explicitly under rejected owner/caller context.
- Update score to `89/92` and item summary as above.
- Keep formal `RECONSTRUCTION_CPP CODE` blank.

Support doc `by-memory/0x004142c0-0x00419e56.ZlibCore.md`:

- Add or adjust one sentence in Reconstruction / C++ Policy clarifying that [UID:0000W2] is a mixed source-map child that should keep a blank formal block unless exact source-file children are split later.
- No score change required.

Support doc `by-file/Zlib.md`:

- Add or adjust one sentence in Reconstruction / C++ Policy clarifying that broad/mixed zlib pages such as [UID:0000W2] and [UID:0000W3] stay blank, while exact source-file children may use accepted one-line static-embed markers.
- No score change required.

Support docs checked but no implementation edit required:

- `by-meta/client_libraries.md`: already says to preserve stock zlib source-file boundaries and not paste decompiler-derived zlib bodies.
- `by-meta/obtained_thirdparty_files/README.md`: already proves archive/static-embed provenance and mirror equivalence.
- `by-project-structure/proposed-source-tree.md`: already lists `third_party/zlib/`; it has stale display links for `00041N`/`00041O` in the excerpt read, but that is outside this target and should be handled by supervisor/project-structure maintenance if desired.
- `auto-generated/NexusTK/third_party/zlib/Zlib.cpp`: generated input only. Do not edit by hand.
- `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md`: generated inputs only. Do not edit by hand.
- Any `-coverage-report.md`: do not edit in this B-agent implementation by default.

## Expected Validators After Implementation

Run scoped validators only after by-* implementation edits, from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0000W2-ZlibPublicCompressChecksum-source-quality-removed.md](0000W2-ZlibPublicCompressChecksum-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If generated `auto-generated/NexusTK/third_party/zlib/Zlib.cpp` freshness is inspected during implementation verification, rerun the relevant scoped validator with `--wait-generated` or inspect the deferred generated-refresh command id/timestamp returned by the validator. Expected generated behavior: `Zlib.cpp` remains an empty-marker/generated support artifact for mixed zlib pages unless exact marker children are created.

No validators were run during this report-only phase because no by-* files were edited.

## Remaining Blockers

No MCP blocker remains.

Evidence-backed unresolved items that cap the score:

- Exact original PDB/source symbols are unavailable; source-facing names are inferred from stock zlib 1.1.4 source and binary behavior.
- Exact local zlib compiler options are not fully recovered.
- The target is mixed across `compress.c`, `uncompr.c`, and `crc32.c`, and `crc32.c:get_crc_table` is present in source but not present as a modeled executable function in this range. This blocks a precise formal static-embed marker on the current aggregate page.
- Generated zlib output and tracker files are stale relative to current by-memory metadata, but they are validator-owned and should be refreshed by implementation validators/report execution, not edited by hand.

## Implementation Tracking Checklist

- [x] Update `by-memory/0x004142c0-0x00414565.ZlibPublicCompressChecksum.md` with current MCP session/schema/call evidence ids `221-235`, source hash/provenance evidence, function/padding map, current xref/callee summary, and product-caller-as-consumer wording. Proof: target now has Status/schema note for session `80de0a67` and ids `221-235`, Source Provenance hashes for `compress.c`/`uncompr.c`/`crc32.c`/`zlib.h`, Function And Padding Map rows through `0x00414565-0x00414570`, Evidence, and Xref And Callee Evidence sections; final validator `000000003617` passed `ok: 1`.
- [x] Change target score from `86/90` to `89/92`. Proof: target metadata is `COMPLETION:89` and `CONFIDENCE:92`; validator `000000003617` recorded `completion_update 0000W2 ... 89` and `confidence_update 0000W2 ... 92`.
- [x] Update target `Item Summary` to identify it as a mixed zlib 1.1.4 public source-map page and to explain blank formal C++/static-embed marker policy. Proof: target header now uses the accepted Item Summary text verbatim; validator `000000003617` passed.
- [x] Keep target `CANONICAL_OWNER:0000PC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000PC`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal `RECONSTRUCTION_CPP CODE`. Proof: target metadata preserves those values and the formal block remains empty between `BEGIN`/`END`; validator `000000003617` passed.
- [x] Add target no-code proof: no decompiler C++; no single or multi-line static-embed marker on this mixed page; staged zlib source is the source of record. Proof: target now has `Reconstruction / Static-Embed No-Code Policy` explaining the mixed-page marker rejection, exact-child-only marker policy, no pasted upstream/Hex-Rays C, and staged zlib source route.
- [x] Preserve rejected alternatives: MetaTable/MapPane/image/palette/startup/DAT/product ownership, CRT/runtime ownership, no-owner/non-emitting, and decompiler-derived source. Proof: target Ownership Decision now lists all rejected owner/source alternatives and keeps product callers as consumers only.
- [x] Update `by-memory/0x004142c0-0x00419e56.ZlibCore.md` with a brief support note that [UID:0000W2] is a mixed public source-map child that remains blank unless exact source-file children are split later. Proof: parent Reconstruction / C++ Policy and 2026-06-26 B007 Changes entry record this; validator `000000003618` passed `ok: 1`.
- [x] Update `by-file/Zlib.md` reconstruction/C++ policy with the same mixed-page versus exact-marker-child distinction. Proof: by-file Reconstruction / C++ Policy and 2026-06-26 B007 Changes entry record broad/mixed pages blank and exact source-file children as one-line marker candidates; validator `000000003619` passed `ok: 1`.
- [x] Do not edit `auto-generated/*`, project-level generated reports, `by-memory/-coverage-report.md`, or any other `-coverage-report.md`. Proof: no manual edits were made to generated or coverage files. Scoped validators performed tool-owned registry/projected-stats side effects and returned deferred generated-refresh states; no coverage report was edited by B007.
- [x] Run the scoped validators listed above and report command ids, command timestamps, exit codes, `ok` counts, warnings, and generated-refresh state. Proof: W2 initial scoped validator `000000003607` at `2026-06-26T22:52:30-04:00` exited `0`, `ok: 1`, generated refresh deferred, and exposed stale registry UID-link rewrites; W2 was corrected and final scoped validator `000000003617` at `2026-06-26T22:56:51-04:00` exited `0`, `ok: 1`, generated refresh deferred. Parent validator `000000003618` at `2026-06-26T22:56:58-04:00` exited `0`, `ok: 1`, generated refresh deferred. By-file validator `000000003619` at `2026-06-26T22:57:10-04:00` exited `0`, `ok: 1`, generated refresh deferred.
- [ ] After implementation validation, supervisor should execute this report with the validator so `auto-generated/-ag-research-tracker.md` records the accepted B007 report. Supervisor-owned follow-up remains intentionally unchecked; no accepted B007 implementation item is blocked.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0000W2-ZlibPublicCompressChecksum-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0000W2-ZlibPublicCompressChecksum-source-quality.md","timestamp":"2026-06-26T23:03:25","uid":"0000W2"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000W2-ZlibPublicCompressChecksum-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/0000W2-ZlibPublicCompressChecksum-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000W2"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
