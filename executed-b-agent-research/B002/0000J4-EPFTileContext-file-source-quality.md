# 0000J4 EPFTileContext Whole-File Source-Quality Research
** TARGET-REPORT-UID:0000J4 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


## Finalized Report / Current Recommendation

- Current recommendation: preserve the implemented `NexusTK/render/EPFTileContext.cpp` as one coherent source unit. UID0000XY now supplies all eleven aggregate definitions, UID000200/UID000201 retain their accepted exact-child definitions, and UID00004I owns the complete header and dependency preamble.
- Final disposition: UID0000J4 remains the sole file owner at `NexusTK/render/`; UID00004I remains the class owner/emitter; UID0000XY remains the aggregate body emitter. The three zero-xref bodies are retained authored helpers, not dead padding. `0x00457a60` is the default constructor, not an ordinary `Initialize()` method. No authored destructor exists.
- Ordinary callback result: the Section 22 aggregate/class/support payloads were applied, all 94 stale explicit `.Initialize()` calls were removed from the 64 exact consumers, deterministic `0/10/20` source order was applied, all changed ordinary pages were scoped-validated, and final waited command `000000025741` was physically read back. IDA C026-C028 and manual coverage C100-C105 remain supervisor-owned.
- Confidence: very high for boundaries, behavior, constructor identity, layout, ownership, routing, and complete inventory; high for descriptive private-helper spellings. Exact original lexical names are unavailable and cap confidence below final-symbol proof.

## Supporting Research

- Dated 2026-08-17 evidence: report SHA256 `620616E25BF5216B9C52F7B064EC2B3E30495CD6A45EEA27BC81799929FF3FF8` passed that cycle's Gate 1, and that implementation cycle read `tools/leaser/Agents/Agent-B002/goal.md` at historical SHA256 `0C6FA9A9FB53CB072353FA056576D7C538B2D2F2E22A5B6033C65A091516D618`. That hash is dated history only. Current assignment authority comes from the current `tools/leaser/Agents/Agent-B002/goal.md` path and direct supervisor callback; lifecycle state remains authoritative only from the artifact's current path and validator-owned status/history metadata.
- Queue evidence: `auto-generated/-ag-research-tracker.md` listed UID0000J4 as uncovered with zero direct/additional report coverage when assigned. Exact searches for `0000J4`, `EPFTileContext`, `0x00457a60`, `0x00457f30`, and `0x00458260` found no active competing report or lease.
- Historical predecessor evidence was used only as a lead and independently revalidated: executed B004 UID00004I report SHA256 `D7A26009151DACD0306EB0CC1928957F90B5C9972B83CB4AD2FAA30B1B903AC0`; executed B005 UID000200 SHA256 `3B0A04BE6D0AB92F74D4FC06A23D19453CF5E3C78F881CC7DB8A5DDF1772C926`; executed B005 UID000201 SHA256 `2F859351ECA798784B2691A75C51690797E8E33F5A7BA54B16DDDAB1BF52BB26`.
- B004 correctly preserved three zero-xref bodies but left their retained-source policy open. Live body correspondence now closes that blocker: `0x00457f30` is the out-of-line RGB16 specialization duplicated in `CopyTo`, while `0x00458260` is the out-of-line RGB16 specialization duplicated in `CreateHalfScaleCopy`. Their zero direct references are consistent with compiler inlining, not with padding or foreign code.
- B004's "12 bodies" wording is numerically stale. The exact unit has twelve modeled IDA functions plus one code-typed raw body, for thirteen authored bodies total.
- Report execution/archive state is supervisor-owned and authoritative only from this artifact's current path and validator-owned status/history metadata. Ordinary report prose makes no current execution/archive claim.

## Target

- Target UID: `0000J4`.
- Additional target UIDs: none. UID00004I, UID0000XY, UID000200, UID000201, UID00015T, UID0003ZP, UID00029U, and all consumer UIDs are support/dependency destinations only and receive no report coverage.
- Declared-target inventory: UID0000J4 is the sole primary target, covering `by-file/EPFTileContext.md` as a whole inferred compilation unit.
- Target path: `by-file/EPFTileContext.md`; proposed source path remains `NexusTK/render/EPFTileContext.cpp` with required sibling `EPFTileContext.h`.
- Source queue/report row: dated tracker selection recorded UID0000J4 with `0/0/0` direct/additional/total report coverage; exact report-header search found no earlier direct or additional UID0000J4 declaration.
- Current supervisor lifecycle classification is not asserted by ordinary prose; artifact path plus validator-owned status/history metadata are authoritative. The ordinary callback allocation is 102 checked and nine supervisor-owned unchecked claims.
- Current scores and parent state: UID0000J4 `94/94`, path `NexusTK/render/`, owner `FILE`. UID00004I is `94/94`, owner/emitter UID0000J4, reconstructable true, position `0`. UID0000XY is `94/94`, owner/emitter UID00004I, reconstructable true, position `0`. UID000200 remains `92/94` at position `10`, and UID000201 remains `89/92` at position `20`.
- Inferred compilation-unit boundary: primary authored text `[0x00457a60,0x00458610)`, with two compiler-associated EH chunks at `[0x005fa0c0,0x005fa0f9)` and `[0x005fa0f9,0x005fa123)` plus four EH data records at `0x006588f4`, `0x006588fc`, `0x0065890c`, and `0x00658930`. The predecessor ends at `0x00457a5d`, three `cc` bytes lead to the constructor, and successor RankingDialog code starts at `0x00458610`.

## Current Target State

- Current target snapshot: `by-file/EPFTileContext.md` SHA256 `757B56A7F6CDFC0668AF98A2973F87FAAB1E9826CC4F1BF2A30882AAC0C8D4D8`, `25033` bytes, `209` lines.
- Current class snapshot: `by-class/EPFTileContext.md` SHA256 `0D3A5C0B666E32CC5706CDA71CC7D5150DB534DCE84767BC3F4B6A11ABC4A5F3`, `30749` bytes, `284` lines.
- Current aggregate snapshot: `by-memory/0x00457a60-0x00458610.EPFTileContext.md` SHA256 `22D4DBB4FBA815A34B43C6E59A885EB4645CA70AAFDE9BB1AE37997DF47121B6`, `39566` bytes, `577` lines.
- Current owner/emitter/reconstructable state remains structurally correct. The body-completion policy, 13-body count, constructor identity, source order, generated completeness, and accepted scores are now incorporated.
- Current class CPP is the exact five-include preamble plus `[[CHILDREN]]`. Current class H has the exact 0x28 storage layout, default constructor, public API, three private helpers, and no destructor.
- Current aggregate CPP contains the exact eleven Section 22 definitions; its H remains blank because UID00004I owns the complete declaration. The two accepted children retain their bodies and blank H channels.
- Dated pre-callback generated command `000000025538` produced the defective `691FE75D...` CPP and `66103CD3...` H snapshots described by this report. Dated final callback command `000000025741` physically produced CPP SHA256 `EB24CFD8B1E95416652B6E0AC57209F16E623D947835D0EAAB10C067DB91D2A5`, `12215` bytes/`390` lines, and H SHA256 `3BE1B3469A6A10B260FFFAAD2A68A5A2F8696E3453A659E4B73B33B977809F6E`, `1400` bytes/`46` lines.
- Current generated dependency declarations physically include `RectArea` in `RectBounds.h`, `ConvertRgb565ToRgb555Pixels` in `SoftwareBlend16.h`, and only `extern bool g_surfaceUsesRgb565Pixels;` in `Surface.h`. `Palette.h` retains complete `DLPaletteRange`/`DLPalette` friendship and `MemoryMan.h` retains the required allocator API.
- Complete inventory status: 13 authored bodies; 12 internal alignment intervals; 2 compiler EH code chunks; 4 EH data records; 1 struct; 1 enum; 5 required header dependencies; zero file-owned globals/statics/constants/strings/tables/vtables/RTTI/resources/import objects; 64 formal consumer pages audited and all 94 stale explicit constructor calls removed; zero unresolved membership candidates.
- Physical callback readback found zero generated empty marker, missing definition, incomplete class declaration, missing dependency declaration, stale consumer call, duplicate body, stub, TODO, or placeholder.

## Executive Recommendation

Keep the direct source hierarchy UID0000J4 -> UID00004I -> UID0000XY/UID000200/UID000201. Emit the eleven missing definitions from UID0000XY in binary order, with UID000200 and UID000201 immediately afterward. Rename source identity `0x00457a60` to `EPFTileContext::EPFTileContext()` and remove the stale public `Initialize` method/calls. Keep `ReleaseBuffers` explicit and omit a destructor because automatic scope exits for borrowed contexts do not call `0x00458500`.

The exact source order is constructor, generic mask builder, RGB16 mask helper, generic copy, retained RGB16 copy helper, generic half-scale copy, retained RGB16 half-scale helper, three allocation methods, release, normalize child, range-query child. Compiler EH chunks/data and all alignment bytes emit no source.

## Supervisor Active Recheck

- Dated 2026-08-17 research and accepted implementation callback authority cover UID0000J4.
- No split repair or new UID is required: UID0000XY is already the correct aggregate body container and the two accepted exact tail children remain valid.
- Every source-bearing body has a formal definition or exact compiler-covered disposition. Every dependency/header defect and every formal consumer made invalid by constructor correction has an exact implementation destination.
- The accepted ordinary callback changed exactly eleven target/core-support pages and 64 consumer pages. B002 did not directly edit manual coverage, generated files, tracker, audit, lifecycle state, or IDA; generated/index/stat/tracker side effects in Section 31 are validator-owned.

## Inference Research Guidance Check

- `by-structure.md` ownership rules favor the semantic class/file chain over caller-biased pane ownership. EPFTileContext is a non-polymorphic render value type shared by image loaders and panes; no individual consumer owns it.
- Existing assumptions treated as uncertain: the twelve-body count, `Initialize` spelling, three retained-helper blockers, lack of a half-scale API, aggregate blank-source policy, and header completeness.
- IDA facts are ranges, bytes, control flow, types, xrefs, frames, and EH associations. Documentation facts are current routes/scores/formal channels. Source names `BuildEncodedMask16`, `CopyRgb16To`, `CreateHalfScaleCopy`, and `CreateHalfScaleRgb16Copy` are descriptive inference.
- No current Wave2/Wave3 authority was used. Any legacy mentions encountered in old docs were ignored.

## Heuristic / Inference Reanalysis And Validation

| Issue | Resolution | Evidence / classification |
| --- | --- | --- |
| `0x457a60` identity | Default constructor `EPFTileContext::EPFTileContext()`, not `Initialize()` | Returns `this` in EAX, initializes all fields, appears at automatic/member construction sites, and is protected by new-expression cleanup metadata when invoked after `operator new`; inferred with very high confidence. |
| Destructor | No authored destructor | No paired call at automatic borrowed-context scope exits; `ReleaseBuffers` has only explicit ownership-sensitive calls; negative original-proof. |
| Mask signedness | Tokens are unsigned storage bytes; high bit marks nonzero/draw runs, low 7 bits length, zero terminates each row | Two exact builders and signed consumer semantics; original-proof behavior. |
| Mask bound | Fixed 100000-byte automatic scratch, no bounds guard | Exact `0x186c0` frame; original-proof quirk preserved. |
| Copy specialization | `0x457f30` is retained `CopyRgb16To` | Exact deep-copy correspondence to RGB16 branch, same release/40-byte header/word-plane/mask flow; descriptive name, source liveness inferred from inlining. |
| Half-scale specializations | `0x457ff0` generic and `0x458260` retained RGB16 helper | Exact byte/word decimation correspondence and distinct out-of-line body; descriptive names. |
| Half-scale pixel format | Returned context remains constructor-default Indexed8 even for the RGB16 word path | Both machine paths initialize to enum 1 and never rewrite field 0; original-proof compatibility quirk, not "fixed." |
| Dimension arithmetic | Signed C++ division by two, truncating toward zero; no clamp/overflow/null checks | Exact idiv-equivalent lowering and allocation expressions; original-proof. |
| Allocation return type | Source methods are `void` despite EAX residue | Existing call sites ignore EAX and class API is mutating; source-shape inference. |
| Range query type | `const DLPalette *` and private inclusive `DLPaletteRange` records | Two callers pass `PaletteLib::GetSlotPalette` result; current generated Palette.h friendship; accepted B005 and live recheck. |
| IDA DLPalette mismatch | Preserve current IDA UDT; use source header truth only | IDA lacks `DLPaletteRange` and retains `m_entryMoves`; no UDT mutation is needed for this target. |
| Source placement | `render/EPFTileContext.cpp/.h` | Class/file metadata, render callers, Palette/Surface/SoftwareBlend dependencies; very high confidence. |

Rejected alternatives:

- Retaining `Initialize()` is rejected by constructor return convention, automatic/member construction call sites, and new-expression EH cleanup.
- Adding a destructor that calls `ReleaseBuffers` is rejected because borrowed resource contexts leave scope without the call and would free non-owned data.
- Dropping the three zero-xref bodies is rejected by full source-shaped prologs/epilogs and exact branch-specialization correspondence.
- Emitting EH chunks or EH data as authored helpers/tables is rejected; they are compiler exception cleanup and `__CxxFrameHandler3` metadata.
- Moving the unit under EPFImageControlPane, ResourceLayoutTable, Palette, Surface, or an image decoder is rejected by broad cross-subsystem use and existing direct ownership.
- Modern RAII, vectors, smart pointers, `size_t` hardening, mask bounds checks, null checks, clamping, and format correction are rejected because they change observed behavior and era shape.

Unresolved original symbol spelling is limited to private helper lexical names and does not block safe descriptive reconstruction. Unresolved item count is zero.

## Evidence Standards Used

- Primary evidence: live read-only IDA MCP runtime attestation, bounded item/function/type/frame/comment/xref/callee/decompile/byte/instruction queries, plus raw SHA256 body receipts.
- Secondary evidence: current by-* metadata and formal blocks, exact generated CPP/H physical readback, manual coverage rows, queue state, and matching executed reports used as dated leads.
- Negative evidence: no direct references to three retained starts, no globals/strings/vtable/RTTI/resources in the primary range, no destructor call route, no extra body after `0x458590`, and no code overlap in any padding interval.
- The evidence ladder reaches binary behavior and source-shape correspondence. Only original lexical spellings remain inferential.

## Evidence Checked

- Mandatory MCP session: `supervisor_uid0000od_rollbackverify_20260817`, canonical IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. Runtime attestation succeeded at `2026-08-17T19:45:28.220985+00:00` against input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`. Server status was `ok`, Hex-Rays and strings were ready; `auto_analysis_ready:false` was recorded as context while all bounded IDB-backed queries succeeded.
- Queried all 13 starts, 12 gaps, both EH chunks, all four EH records, predecessor/successor boundaries, exact frames/comments/xrefs/callees, EPFTileContext/enum/RectBounds/DLPalette types, and raw body bytes.
- Read target/class/aggregate/two exact children, three declaration dependencies, their file parents, generated EPFTileContext CPP/H and dependency headers, manual by-file/by-class/by-memory rows, tracker, and all matching B reports.
- Searched all ordinary by-* formal CPP channels for `EPFTileContext` plus `.Initialize()`; found exactly 64 files and 94 calls listed in Section 25.
- Repeated the exact manifest-bound formal scan after callback validation; all 64 files remain present and the 94 listed explicit default-constructor calls now have zero formal occurrences. Directly dependent duplicate/prose occurrences in C035, C063, C064, C068, C069, C072, and C088 were corrected to default-constructor wording without altering unrelated source.
- Searched the unit for globals/statics/constants/strings/tables/vtables/RTTI/resources/import objects and found none owned by this file.
- Dated callback validators and physical generated readback are recorded in Section 31. No IDA mutation endpoint, MCP process action, manual coverage edit, lifecycle command, or execute command was invoked by B002.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C001 | 0000J4 | Record the exact whole-file inventory: 13 authored bodies, 12 internal all-cc padding intervals, six compiler-only EH items, two owned types, five dependency groups, three excluded boundary items, and no owned global/string/table/vtable/RTTI/resource/import item. | very-high | bounded IDA entities, bytes, boundaries, xrefs, types, generated/source routing | `by-file/EPFTileContext.md inventory` | incorporate | applied |
| C002 | 0000J4 | Record every authored range, size, current IDA identity/type, exact SHA256, frame, comment-channel disposition, and inbound/outbound xref route. | very-high | live read-only MCP body inventory and exact raw-byte hashes | `by-file/EPFTileContext.md evidence` | incorporate | applied |
| C003 | 0000J4 | Classify all twelve internal gaps as exact all-cc alignment and exclude predecessor 0x457960, boundary padding 0x457a5d, and successor 0x458610. | very-high | bounded bytes and neighboring function ranges | `by-file/EPFTileContext.md boundaries` | incorporate | applied |
| C004 | 0000J4 | Correct 0x457a60 from ordinary Initialize to the default EPFTileContext constructor and record EAX=this, 337 construction xrefs, automatic/member sites, and new-expression cleanup evidence. | very-high | decompile, disassembly, exact xref set, EH routes | `target/class/aggregate constructor sections` | reject-stale | applied |
| C005 | 0000J4 | Record that no destructor body exists and EPFTileContext__ReleaseBuffers is explicit ownership cleanup with 71 call xrefs, not an implicit destructor. | very-high | scope-exit routes, 71-xref set, release body | `target/class/aggregate lifetime sections` | reject-stale | applied |
| C006 | 0000J4 | Reconstruct indexed and RGB16 encoded-mask behavior including fixed 100000-byte scratch, 127-byte run cap, zero row terminators, conditional count reset, byte/word transparency tests, and exact allocation/move flow. | high | 0x457ab0 and 0x457c60 decompile/disassembly correspondence | `aggregate formal CPP and behavior` | incorporate | applied |
| C007 | 0000J4 | Reconstruct generic deep copy and retained RGB16 deep-copy specialization; preserve pixel/alpha byte-count distinctions, mask copy, and explicit destination release. | high | 0x457e00 branch family and raw 0x457f30 body | `aggregate formal CPP and liveness` | incorporate | applied |
| C008 | 0000J4 | Reconstruct generic and retained RGB16 half-scale decimation, exact RectArea allocation, EH cleanup, and the observed constructor-default Indexed8 format quirk in RGB16 results. | high | 0x457ff0/0x458260 bodies, EH chunks, allocations | `aggregate formal CPP and behavior` | incorporate | applied |
| C009 | 0000J4 | Reconstruct the three allocation methods and explicit ReleaseBuffers with exact MemoryMan ownership, area/stride fields, and pointer resets. | high | 0x4583d0-0x458557 bodies and caller routes | `aggregate formal CPP and lifetime` | incorporate | applied |
| C010 | 000200 | Preserve the accepted normalization body and record its exact RGB565 flag and conversion-helper dependency; add no duplicate source. | very-high | current child source and 0x458560 read/call route | `UID000200 source/dependency prose` | already-present | already-present |
| C011 | 000201 | Preserve the accepted indexed-range query body and Palette friendship/type route; add no duplicate source. | very-high | current child source and 0x458590 behavior | `UID000201 source/dependency prose` | already-present | already-present |
| C012 | 0000J4 | Classify both EH code chunks and four EH data records as compiler-covered no-code with exact ranges, widths, hashes, associations, absent comments, and no authored emission. | very-high | bounded MCP bytes/entities/xrefs | `target/aggregate compiler inventory` | not-applicable | excluded-with-reason |
| C013 | 0000J4 | Record the exhaustive negative inventory for file-owned globals, statics, constants, strings, tables, vtables, RTTI, resources, and imports. | high | bounded entity/string/type/generated searches | `by-file/EPFTileContext.md negative evidence` | incorporate | applied |
| C014 | 0000J4 | Preserve file owner UID0000J4, class emitter UID00004I, aggregate UID0000XY, and exact children UID000200/UID000201; reject new-owner and split-unit alternatives. | very-high | current routing plus contiguous behavior family | `target/class/aggregate ownership` | already-present | already-present |
| C015 | 0000XY | Set deterministic source order: aggregate position 0, UID000200 position 10, UID000201 position 20; private helpers remain inside aggregate source. | high | address order and existing child emission model | `aggregate and child metadata` | incorporate | applied |
| C016 | 0000J4 | Replace the current empty generated CPP route with the complete 13-definition source topology and require no empty marker, duplicate body, stub, TODO, or placeholder. | high | dated generated CPP hash/physical read and Section 22 source | `target/class/aggregate formal CPP` | reject-stale | applied |
| C017 | 00004I | Replace the incomplete generated H route with the exact 0x28 class API and required RectBounds, Palette, SoftwareBlend16, Surface, and MemoryMan dependencies. | high | dated generated H hash, type layout, call graph | `class formal H and dependency topology` | reject-stale | applied |
| C018 | 00004I | Set formal class CPP to exact includes plus [[CHILDREN]] in Section 22. | high | source topology and complete-type requirements | `by-class/EPFTileContext.md formal CPP` | incorporate | applied |
| C019 | 00004I | Set formal class H to the complete Section 22 enum/class declaration with constructor, no destructor, public API, private helpers, and exact seven-field layout. | high | IDA UDT, body accesses, caller behavior | `by-class/EPFTileContext.md formal H` | incorporate | applied |
| C020 | 0000XY | Set formal aggregate CPP to the exact eleven authored definitions in Section 22, leaving the two accepted tail children to child emission. | high | all 13 bodies and existing child split | `by-memory/0x00457a60-0x00458610.EPFTileContext.md formal CPP` | incorporate | applied |
| C021 | 000200 | Preserve the accepted UID000200 child CPP body exactly and keep its formal H channel blank. | very-high | physical current child doc and generated topology | `UID000200 formal channels` | already-present | already-present |
| C022 | 0000J4 | Record exact include/declaration topology and complete-type dependencies for RectBounds, Palette, SoftwareBlend16, Surface, and MemoryMan. | high | formal source compile dependencies and current headers | `target/class/aggregate documentation` | incorporate | applied |
| C023 | 00015T | Add exact H declaration int RectArea(const RectBounds *bounds); and record the two EPFTileContext half-scale callers. | high | 0x4b7ca0 type/body plus 0x457ff0/0x458260 calls | `by-memory/0x004b7ca0-0x004b7cb6.RectArea.md formal H` | incorporate | applied |
| C024 | 0003ZP | Add exact H declaration void ConvertRgb565ToRgb555Pixels(unsigned short *pixels, int pixelCount); and preserve the exact 0x7ff0 conversion quirk. | high | 0x4bb0e0 type/body and 0x458560 call | `by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md formal H` | incorporate | applied |
| C025 | 00029U | Add only extern bool g_surfaceUsesRgb565Pixels; to formal H; retain g_surfaceUses32BitPresentation as file-static. | high | data xrefs, generated Surface source, cross-TU 0x458560 read | `by-memory/0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags.md formal H` | incorporate | applied |
| C026 | 0000J4 | Apply only staged A01-A04 pure function renames after literal prestates, then require each exact new persisted IDB name and unchanged persisted TInfo, each exact new public `inspect_items` symbol and row-specific public type, and each exact cached pre-rename immediate Hex-Rays function-name/prototype; at A03 permit only the enumerated public presentation convergence to `MemoryMan *`, and hard-stop every other delta. | high | Section 21 exact ranges, hashes, separated persisted/public/decompiler channels, frames, comments, xrefs, protections | `IDA A01-A04` | incorporate | proposed |
| C027 | 0000J4 | Verify A05's exact no-change disposition for raw 0x457f30 across persisted-TInfo, Hex-Rays, and public-presentation channels, invoke no A06 endpoint, then apply A07-A13 pure renames in dependency order with each exact new persisted/public symbol, unchanged persisted/public type, exact cached pre-rename immediate Hex-Rays function-name/prototype, and item-specific hard stops; A07's structural callee identity protects 0x457a60 as post-A01 EPFTileContext__EPFTileContext. | high | raw bytes and Section 21 literal no-change/action/separated presentation stages | `IDA A05/A06/A07-A13` | incorporate | proposed |
| C028 | 0000J4 | Enforce P01-P05 no-delta protections for ReleaseBuffers, EH items, UDTs/dependencies, padding/neighbors, bytes/xrefs, and every non-owned field. | very-high | literal Section 21 protection rows | `IDA P01-P05` | incorporate | proposed |
| C029 | 0000J4 | Update target source-quality prose and score from 89/86 to 94/94 while preserving path NexusTK/render, FILE ownership, and lifecycle-neutral dated generated receipts. | high | complete blocker closure and exact current metadata | `by-file/EPFTileContext.md` | incorporate | applied |
| C030 | 0002DL | Remove the stale explicit default-constructor call expressions boardFrame.Initialize(), itemScratch.Initialize(), glyphScratch.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 9C34E222A55134C3E116D86FB5E58C884D572831884FBB9A04BE6E1184A723FA | `by-memory\0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md` | reject-stale | applied |
| C031 | 00006R | Remove the stale explicit default-constructor call expressions background.Initialize(), buttonFrame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 0018E7DC596593AA3C76F55EF2817ABBD2799E5E277DAC533057627D077E1BB9 | `by-class\InventoryPane.md` | reject-stale | applied |
| C032 | 0004IA | Remove the stale explicit default-constructor call expressions frame.Initialize(), frame.Initialize(), frame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 4F856550821F9ABD325751A9406EA413AA0D7AF70F17B0422A8438C50D69FEAC | `by-memory\0x0045df90-0x0045ea13.RankingRewardInfoDialogOnPaint.md` | reject-stale | applied |
| C033 | 00030L | Remove the stale explicit default-constructor call expressions m_backgroundTileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 284CB50669A32422C4570B4C8769DF5C81B520CFAA9185A8A406D493F8008748 | `by-memory\0x00467510-0x0046782f.BackGroundPaneCoreMethods.md` | reject-stale | applied |
| C034 | 0002F9 | Remove the stale explicit default-constructor call expressions tile.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 1900E872D38A15C05704690AC52764C2ED9C08B4FF3B5CEE249CE3E912A47B89 | `by-memory\0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md` | reject-stale | applied |
| C035 | 0002FD | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 074982DE1F769DC4F45245AB4420CEE5AE4869D51F5D5861CF689E696843FB43 | `by-memory\0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint.md` | reject-stale | applied |
| C036 | 0002FO | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 08AABDEFF9B390ED50B8187479C550CA3CE7432713902CD15FFA73D751CC803C | `by-memory\0x00481750-0x00481a72.ChattingVarietySelectPaneDrawBorder.md` | reject-stale | applied |
| C037 | 0002FN | Remove the stale explicit default-constructor call expressions tile.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 115CD0B6CAEC0A01AB86BF0D88F112B2F6865D01C2430AB24B4EFD200825093C | `by-memory\0x004816d0-0x00481741.ChattingVarietySelectPaneSetupBackground.md` | reject-stale | applied |
| C038 | 0002FU | Remove the stale explicit default-constructor call expressions tile.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 693BD5DE28A21C59D107CEC328AFE16D75E321F458A864EB2A9122EA4F6BC5C6 | `by-memory\0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md` | reject-stale | applied |
| C039 | 0002GH | Remove the stale explicit default-constructor call expressions unusedContext.Initialize(), background.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 32D1551F40A60EC5CCBB53A94A2939DF45CCA37CF52132D50FD9281A4E300AE3 | `by-memory\0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables.md` | reject-stale | applied |
| C040 | 0004IU | Remove the stale explicit default-constructor call expressions leftTile.Initialize(), centerTile.Initialize(), rightTile.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 B291D91FBC3970D94ED0FA238538B426929038BC64ABE87E7177BDB39B5ECAAB | `by-memory\0x00498270-0x004984bc.PopupMenuControlPaneOnDraw.md` | reject-stale | applied |
| C041 | 0004JW | Remove the stale explicit default-constructor call expressions frame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 CB43626DC5AC538E830C3A08150EE1DE7D6CC954A4D5BDA58328AD0B847A242D | `by-memory\0x00499310-0x004993a5.EPFImageControlPaneOnPaint.md` | reject-stale | applied |
| C042 | 00011O | Remove the stale explicit default-constructor call expressions glyphContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 83DDCF926880B5B3C9B3B5B9234ADD0027B6CBC300B3D03BDBD1CB0EDB1F6B9B | `by-memory\0x00499a50-0x00499be7.NumericStringControlPaneRenderNumericString.md` | reject-stale | applied |
| C043 | 00011S | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 6516DB23190B4E528A426F34571B4FA906B781FFE2E779D6D5CA96CC91BC2E06 | `by-memory\0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md` | reject-stale | applied |
| C044 | 0003KG | Remove the stale explicit default-constructor call expressions sourceContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 1E926142248B605C4841805EEC732DB6B573AC1EC92D8CC87A4BC5E1EF10AF5C | `by-memory\0x0049db60-0x0049dc05.DialogPaneSetBackgroundResource.md` | reject-stale | applied |
| C045 | 0004SW | Remove the stale explicit default-constructor call expressions frame.Initialize(), frame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 3E6F1714585A6551B4397DD1F9A3E58B3FCEAB1B961F7CB2230B83E0AA0FE975 | `by-memory\0x0049f1d0-0x0049f2d4.DialogPaneDrawBackground.md` | reject-stale | applied |
| C046 | 0004SX | Remove the stale explicit default-constructor call expressions frame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 10540A622191EFCFD9D89094D5A8B139E36B7922CDE34445258E0FF922C2A623 | `by-memory\0x0049f2e0-0x0049f912.DialogPaneDrawBorder.md` | reject-stale | applied |
| C047 | 0002HF | Remove the stale explicit default-constructor call expressions sellItemTile.Initialize(), itemGlyphContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 509D2664270081CE5D6D56BB29A99FE45ACF991094154D1F438F9B495254B4AC | `by-memory\0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md` | reject-stale | applied |
| C048 | 0004A0 | Remove the stale explicit default-constructor call expressions itemContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 EC50AEEEE4088D7A78326DAB8523B9201C82E23A4A85D9CAD619FCF7755A92FE | `by-memory\0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md` | reject-stale | applied |
| C049 | 0002JQ | Remove the stale explicit default-constructor call expressions tileContext.Initialize(), tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 2FDF5B9026ECA3A2248BBD0AE6DA7DA1624E7293DF4B422ABA625A379291C26F | `by-memory\0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md` | reject-stale | applied |
| C050 | 00016I | Remove the stale explicit default-constructor call expressions glyphContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 F2EA95FB5625FC0B68E7D43775F17196747CAC3F4C4C9BD70023C3CA58E573F1 | `by-memory\0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md` | reject-stale | applied |
| C051 | 0002T1 | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 E0250EA5AA55C61F5CF54C770B4E2DD17F8A272A23A26C01E8D9B8C4DE5A63A6 | `by-memory\0x004cf300-0x004cf3d3.IconsPaneOnPaint.md` | reject-stale | applied |
| C052 | 0002KR | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 4623FAE460485A5AFA65AB0CCD86B3A5570A38C591B439E619C3628B65DBB876 | `by-memory\0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md` | reject-stale | applied |
| C053 | 0002Y1 | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 0416F08C76A96252D553BA2B253B465A01C42F9243F514F01F9EC3DA7C1799FA | `by-memory\0x004dc7e0-0x004dca14.RidingImageLibRenderRiding.md` | reject-stale | applied |
| C054 | 00041S | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 528C3C7626FF8BDDA180DC9FAF0E66A1B66A66CA7BD36B368C201A20E3912D45 | `by-memory\0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot.md` | reject-stale | applied |
| C055 | 0003ND | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 2F43FBC0660ECE840AAC3B8517CDF72389128AAD9C65F37014AB5ACEB2DE5B21 | `by-memory\0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability.md` | reject-stale | applied |
| C056 | 00053Y | Remove the stale explicit default-constructor call expressions background.Initialize(), button.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 1686FBF6213A18AA3C78FF3C33A5F0836CA426C02E2276F6B1720954E6BABD89 | `by-memory\0x004ebb20-0x004ec913.NewInventoryPaneOnPaint.md` | reject-stale | applied |
| C057 | 00048S | Remove the stale explicit default-constructor call expressions frame.Initialize(), buttonFrame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 D589954CB4AB1A0025B9A7DFBA3956D78256AF59388B19B38696220B391A2441 | `by-memory\0x004ee6f0-0x004eee5c.InventoryPane2OnPaint.md` | reject-stale | applied |
| C058 | 0002PL | Remove the stale explicit default-constructor call expressions m_logoTileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 1C1C411C9CC06E9B50096EA5A7F4F262384836716DDE233F75F23FB39DE79BE2 | `by-memory\0x004f4c10-0x004f4eac.LogoPaneConstructor.md` | reject-stale | applied |
| C059 | 0002Q8 | Remove the stale explicit default-constructor call expressions frameContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 20E9D4044DCA14C9E8E0844F5CA14FA1EE432C293B8B16945189FE7E3BF29A09 | `by-memory\0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md` | reject-stale | applied |
| C060 | 0002Q9 | Remove the stale explicit default-constructor call expressions frameContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 D6D637AAEEDA35D1EE82991B444B668C278EE4FFBCD9FBF81030B3C4FC7C592D | `by-memory\0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md` | reject-stale | applied |
| C061 | 0004MA | Remove the stale explicit default-constructor call expressions m_renderedText.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 72E604DFF65526F22A1D86AD8E550AE339E5752378891717A19015D9A6D68302 | `by-memory\0x004ff400-0x004ff644.ScrolledTextControlPaneForMadeByConstructor.md` | reject-stale | applied |
| C062 | 0001A1 | Remove the stale explicit default-constructor call expressions frame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 922ACA728F316E833F94555C9BF1E33A91FB937EA98D4DD9408ED5EC55FC5066 | `by-memory\0x004ffd80-0x0050008b.HistoryViewingPaneCore.md` | reject-stale | applied |
| C063 | 0004ZZ | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 A8CC5E19F9549E0C097E4ACED8E29279F0016A7D63166DF7F1E4C657A2730288 | `by-memory\0x00500700-0x00500797.GenderButtonControlPaneOnPaint.md` | reject-stale | applied |
| C064 | 00050I | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 B0B50DAE9FFDC199FCB9C502EA4FA5FABA9901150B3DC12A4DC9CA20BCA775B6 | `by-memory\0x00500820-0x005008b9.DirectionButtonControlPaneOnPaint.md` | reject-stale | applied |
| C065 | 0004OI | Remove the stale explicit default-constructor call expressions selectionFrame.Initialize(), partFrame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 DF514FE77451BDE20E1E5FB161DDC35A8FF7BBC8F68447B4849F21F929527C4F | `by-memory\0x00501360-0x0050158a.UserHairSelectControlPaneOnPaintFrame.md` | reject-stale | applied |
| C066 | 0004OO | Remove the stale explicit default-constructor call expressions selectionFrame.Initialize(), partFrame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 9F3F4A2B7259E869991C142F1F849F213B469CFCDBAC4511D71F0717B88C7480 | `by-memory\0x00501840-0x00501a6a.UserFaceSelectControlPaneOnPaintFrame.md` | reject-stale | applied |
| C067 | 0002BF | Remove the stale explicit default-constructor call expressions glyphContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 09924E122B131C4686D8E422DE0A5AD5F74282C2E6D4529F38E58014BA93F4CC | `by-memory\0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md` | reject-stale | applied |
| C068 | 0003XG | Remove the stale explicit default-constructor call expressions m_mapNameImage.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 3C92960E0BF09C49E4901E054C423E9C283DEE41E2F74236E21937FB8A567F9D | `by-memory\0x005031f0-0x005032c3.MapNamePaneConstructor.md` | reject-stale | applied |
| C069 | 0004VP | Remove the stale explicit default-constructor call expressions frame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 BEF7EFCD076EBF7CF75176FA8A9D2D71B231F0B2F73C62463206652CE8AFD8CA | `by-memory\0x00538c50-0x00538cfa.BowGaugeObjectPaneOnPaint.md` | reject-stale | applied |
| C070 | 0001EE | Remove the stale explicit default-constructor call expressions frames[index].Initialize(), frame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 808EEEC60B66098CEFA6B5861B69B08B317B425F6797B704626EC7F561B9CD2D | `by-memory\0x00545170-0x00545e3b.EditablePaperPane.md` | reject-stale | applied |
| C071 | 0002KG | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 1E36BA904DA48DB9B8ECB3D7E533291AF88CC3422257912A718A38E64878A7C1 | `by-memory\0x00546890-0x0054696f.ParcelPaneOnPaint.md` | reject-stale | applied |
| C072 | 0002KL | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 F2A5D26A5AB2D280B20654EDDE76759F30E25C81993418F5781C60E2133F4D6F | `by-memory\0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md` | reject-stale | applied |
| C073 | 0004FF | Remove the stale explicit default-constructor call expressions tile.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 828DD1FAE2428C6F7E69BF2707FCD4FD974598082B204D6914E74045259D8440 | `by-memory\0x005552f0-0x00555361.RightButtonMenuPaneDrawSubwinBackground.md` | reject-stale | applied |
| C074 | 0004FG | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 696D18011201C051FEE65FB0902E5A46C3B21A6495CD76380CB02B605135FD07 | `by-memory\0x00555370-0x00555692.RightButtonMenuPaneDrawSubwinBorder.md` | reject-stale | applied |
| C075 | 0002LV | Remove the stale explicit default-constructor call expressions tile.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 7CEDFB40DAC165F17231A751A16C9D8E9EC1DEFD07D6DB62E215D715136F9E3B | `by-memory\0x00555c70-0x00555ce1.VoteMenuPaneDrawBackground.md` | reject-stale | applied |
| C076 | 0002LW | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 AC35BD9A2F24DB83FE9B7DD81A836B5A568B50D6E32016E88FD763AE8939E001 | `by-memory\0x00555cf0-0x00556012.VoteMenuPaneDrawBorder.md` | reject-stale | applied |
| C077 | 00053J | Remove the stale explicit default-constructor call expressions tile.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 E7A3FFFCDC78B232BBA8B0C2F1A16C50D9C34707CF474E4581CCBE4A08B75981 | `by-memory\0x0055f890-0x0055ff70.ScrollSpellInventoryPaneOnPaint.md` | reject-stale | applied |
| C078 | 00051O | Remove the stale explicit default-constructor call expressions tile.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 CFBB107A045FCA174995D1E5CE3696310F28EE9732D2E22E86A10896ED78A977 | `by-memory\0x005636a0-0x00563d80.ScrollInventoryPaneOnPaint.md` | reject-stale | applied |
| C079 | 0003QN | Remove the stale explicit default-constructor call expressions tileContext.Initialize(), commaContext.Initialize(), offButtonContext.Initialize(), onButtonContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 D78CE67E370CFC46F2989E63071A98124493D682705B647CD19AD716A5258176 | `by-memory\0x00567480-0x00568bd0.SelfLookPaneOnPaint.md` | reject-stale | applied |
| C080 | 0003QU | Remove the stale explicit default-constructor call expressions glyphContext.Initialize(), symbolContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 5606B7D7865FE3CCF21FC262056C3D994B4497DCF309F3899B99E0AE8A533462 | `by-memory\0x00569d80-0x00569ec1.SelfLookPaneDrawNumberString.md` | reject-stale | applied |
| C081 | 0004Z5 | Remove the stale explicit default-constructor call expressions tileContext.Initialize(), commaFrame.Initialize(), barLeftCap.Initialize(), barRightCap.Initialize(), barFill.Initialize(), scratchContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 3E1F4113FD85CCB2F560A7556859E74D8D6118F14FCA845B498F98B41AA3E873 | `by-memory\0x0056ce50-0x0056da03.NewGroupPaneOnPaint.md` | reject-stale | applied |
| C082 | 0003Y6 | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 F8CC434023308050EA88CBC016980936F93C03FEC507B31794925F71D87A8AE6 | `by-memory\0x0056edc0-0x0056f655.CollectionPaneOnPaint.md` | reject-stale | applied |
| C083 | 0003YG | Remove the stale explicit default-constructor call expressions context.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 2F4B438E39C4737074B76B85F925FDA4CD3EE79978617BD32C025660EB2145F4 | `by-memory\0x0056fdd0-0x0056fe41.CollectionPane2OnPaint.md` | reject-stale | applied |
| C084 | 0003RB | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 21EEE4635413F37782FD2C76E0C3B8CDC71262EE87B7053B8D4F0A7126E58D13 | `by-memory\0x00570fc0-0x00571c05.SelfLookPane2OnPaint.md` | reject-stale | applied |
| C085 | 0003RF | Remove the stale explicit default-constructor call expressions glyphContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 E8579633C4FBB93A761C7DD4CA5EF9BD1BF24D154094709435C28037AFD13B88 | `by-memory\0x005726a0-0x00572771.SelfLookPane2DrawStatText.md` | reject-stale | applied |
| C086 | 00052O | Remove the stale explicit default-constructor call expressions background.Initialize(), button.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 E11DD7E3A6561399AFBF853ED309105FECB3EEAE9A8245750B4B4D8DADB4BD22 | `by-memory\0x0057d430-0x0057d8c4.NewSpellInventoryPaneOnPaint.md` | reject-stale | applied |
| C087 | 0001KC | Remove the stale explicit default-constructor call expressions tile.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 DC416151BE118B3B6DA76BC2320C95CDCEAC84F1CA7406FFC91AA974A92E09C1 | `by-memory\0x00598cc0-0x00598ecf.TotemFrame.md` | reject-stale | applied |
| C088 | 0004MZ | Remove the stale explicit default-constructor call expressions frame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 86EAC1E11C4F0FE1CE7ACD0DB52F1042B7452318DBC84D7D91F9B84D621B92DC | `by-memory\0x005992f0-0x005993a5.TransferServerDialogPaneOnPaint.md` | reject-stale | applied |
| C089 | 0003FG | Remove the stale explicit default-constructor call expressions uncheckedFrame.Initialize(), checkedFrame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 5213EB819786064C5057E3CF14762BC3CD6592F58E8372C8C873C3856B69EBF9 | `by-memory\0x0059df50-0x0059e0ac.CheckBoxTextControlPaneOnPaint.md` | reject-stale | applied |
| C090 | 00047H | Remove the stale explicit default-constructor call expressions m_statusIconFrames[index].Initialize(), m_badgeIconFrames[index].Initialize(), m_huntersListIconFrame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 D06A6B5838BE6F33EC3F42C8F30016C1FD84378E12340E36EAAB8B7506DF9D12 | `by-memory\0x0059e710-0x0059e899.UserListPaneConstructor.md` | reject-stale | applied |
| C091 | 0003RI | Remove the stale explicit default-constructor call expressions m_portraitImage.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 FF99F1C4B62FBFEDBD037C6A9060071BE6027AE4E9562D719FF5DCC0D871477D | `by-memory\0x0059f260-0x0059f4fd.UserLookPaneConstructor.md` | reject-stale | applied |
| C092 | 0003RM | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 A5012F0F15F1C55DDEE842CE6CEEFFB9BF278C54D8BFCF15EFF62027E93BB1DC | `by-memory\0x005a0640-0x005a157d.UserLookPaneOnDraw.md` | reject-stale | applied |
| C093 | 00054K | Remove the stale explicit default-constructor call expressions m_swallowFrames[0].Initialize(), m_swallowFrames[1].Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 CAF96D16960D41D5B00F58C0EEF869C5E3C187037775B3D5442D87FAFBFB250E | `by-memory\0x005c2230-0x005c2340.SwallowLayerPaneConstructor.md` | reject-stale | applied |
| C094 | 00004I | Rescore EPFTileContext class 88/90 to 94/94 after complete CPP/H, API, layout, lifetime, helper, and ordering closure. | high | complete class formal source and binary inventory | `by-class/EPFTileContext.md metadata` | incorporate | applied |
| C095 | 0000XY | Rescore EPFTileContext aggregate 88/91 to 94/94 after eleven definitions, 13-body inventory, retained/raw closure, and EH/padding proof. | high | whole-range reconstruction and split closure | `aggregate metadata` | incorporate | applied |
| C096 | 00015T | Rescore RectArea 86/90 to 88/92 after exact H declaration and EPFTileContext caller closure. | high | exact body/type and four-caller context | `RectArea metadata` | incorporate | applied |
| C097 | 0003ZP | Rescore ConvertRgb565ToRgb555Pixels 92/94 to 93/95 after exact H declaration and sole generated consumer dependency closure. | high | exact conversion body and call route | `conversion-helper metadata` | incorporate | applied |
| C098 | 00029U | Rescore SurfacePixelFormatFlags 88/93 to 90/94 after exact external-versus-static H disposition. | high | exact data xrefs and source ownership | `SurfacePixelFormatFlags metadata` | incorporate | applied |
| C099 | 0000J4 | Preserve UID000200/UID000201 scores and all owner/emitter/reconstructable/range/path fields not explicitly changed. | very-high | current metadata and accepted source | `target and support metadata` | already-present | already-present |
| C100 | 0000J4 | Apply the exact UID0000J4 manual by-file coverage replacement from Section 28. | high | completed target recommendation | `by-file/-coverage-report.md` | incorporate | proposed |
| C101 | 00004I | Apply the exact UID00004I manual by-class coverage replacement from Section 28. | high | completed class recommendation | `by-class/-coverage-report.md` | incorporate | proposed |
| C102 | 0000XY | Apply the exact UID0000XY manual by-memory coverage replacement from Section 28. | high | completed aggregate recommendation | `by-memory/-coverage-report.md` | incorporate | proposed |
| C103 | 00015T | Apply the exact UID00015T manual by-memory coverage replacement from Section 28. | high | completed RectArea recommendation | `by-memory/-coverage-report.md` | incorporate | proposed |
| C104 | 0003ZP | Apply the exact UID0003ZP manual by-memory coverage replacement from Section 28. | high | completed conversion-helper recommendation | `by-memory/-coverage-report.md` | incorporate | proposed |
| C105 | 00029U | Apply the exact UID00029U manual by-memory coverage replacement from Section 28. | high | completed Surface-flag recommendation | `by-memory/-coverage-report.md` | incorporate | proposed |
| C106 | 0000J4 | Run the exact path-bound scoped validator for each changed target/core-support by-* document from the stated cwd. | very-high | Section 31 exact command rows | `callback validator receipts` | incorporate | applied |
| C107 | 0000J4 | Run the exact path-bound scoped validators for RectBounds.md, SoftwareBlend16.md, Surface.md, and all changed dependency pages required by the UID0000J4 whole-file implementation. | very-high | Section 31 exact command rows | `callback validator receipts` | incorporate | applied |
| C108 | 0000J4 | Run one exact path-bound scoped validator for every changed constructor-consumer page required by the UID0000J4 constructor correction. | very-high | 64 Section 31 exact command rows | `callback validator receipts` | incorporate | applied |
| C109 | 0000J4 | Run the literal final UID0000J4 validator command with --wait-generated, then physically reread and hash generated EPFTileContext.cpp/.h against Section 22 and the defect checklist. | very-high | Section 31 final command and readback contract | `callback final generated readback` | incorporate | applied |
| C110 | 0000J4 | Record third-party source-import directive as not applicable; no identified external library source owns this unit. | very-high | ownership search and binary/source family | `report third-party disposition` | not-applicable | excluded-with-reason |
| C111 | 000201 | Preserve the accepted UID000201 child CPP body exactly and keep its formal H channel blank. | very-high | physical current child doc and generated topology | `UID000201 formal channels` | already-present | already-present |

## Positive Evidence Summary

- The primary range is contiguous, internally separated only by twelve all-`cc` intervals, and ends exactly before RankingDialog at `0x458610`.
- Every body reads/writes the exact 0x28 EPFTileContext layout. The body family shares MemoryMan, RectBounds, Surface-format, palette-range, and image-loader semantics.
- The constructor identity explains 337 inbound construction references, embedded/member ordering, EAX=`this`, and both new-expression EH cleanup families.
- The retained helpers are byte-for-byte behavior families, not merely nearby code: fixed-word copy mirrors generic CopyTo's RGB16 branch; fixed-word decimation mirrors generic half-scale RGB16 branch.
- Existing class/file ownership and exact tail children are already correct, so completion requires source/topology repair rather than a new owner or split.

## IDA MCP Facts

### Authored body facts

| Range | Current IDA name/type | Size / SHA256 | Frame summary | AR / AP / FR / FP |
| --- | --- | --- | --- | --- |
| `[0x457a60,0x457aa4)` | `EPFTileContext_Initialize` / `void __thiscall(EPFTileContext *this)` | `0x44` / `F690BAD0AC3912C12EB46F00785CD5B95C33C5CEB1BDA4F0163674FF436F3A41` | `__return_address +0x4/4/_UNKNOWN *` | absent / absent / absent / absent |
| `[0x457ab0,0x457c53)` | `sub_457AB0` / `void *__thiscall(_DWORD *this)` | `0x1a3` / `5FBE7BA516ABC1E9994570D6688BD78BF730B1CE06D7BCD19D0565E9ADD00454` | exact 11-row mask frame in Section 21 | absent / absent / absent / absent |
| `[0x457c60,0x457df2)` | `sub_457C60` / `MemoryMan *__thiscall(_DWORD *this)` | `0x192` / `DBCD785D79AABF84234A64E9893B035EE3AB2444774E8738CCD6AEA38E9E9763` | same exact 11-row mask frame | absent / absent / absent / absent |
| `[0x457e00,0x457f2b)` | `sub_457E00` / `void *__thiscall(void *this, EPFTileContext *)` | `0x12b` / `AA747F57756F4AF01294F6BEF84F0958C06F5CB77B914E1A00FE51586FBA1DBD` | four rows: `var_4 +0xc/4/MemoryMan *`, saved `+0x10`, return `+0x14`, `arg_0 +0x18/4/EPFTileContext *` | absent / absent / absent / absent |
| `[0x457f30,0x457fe9)` | no function; code item; name/type absent | `0xb9` / `C78A1FC8014DA9B8C0C5B9BC4388E78A7DEAAD4EE57F549C3525BAD3BC739613` | no function/frame | absent / absent / absent / absent |
| `[0x457ff0,0x458253)` | `sub_457FF0` / `struct RectBounds *__thiscall(_DWORD *this)` | `0x263` / `CC2074204509B0394CC032EE61A8FAD6F327253E18B2D580725A9E131ABE575C` | exact 8-row EH frame in Section 21 | absent / absent / absent / absent |
| `[0x458260,0x4583c8)` | `sub_458260` / `struct RectBounds *__thiscall(_DWORD *this)` | `0x168` / `8A6ACF0AE27C224DC5EC074F046CD8EEFD902CDC8D82963CD7A5C333EA1AC0C0` | same exact 8-row EH frame | absent / absent / absent / absent |
| `[0x4583d0,0x458423)` | `sub_4583D0` / `void *__thiscall(EPFTileContext *this,int,int)` | `0x53` / `E0AE18244D060264808E5E4AB089B168BAF4397C206F39DF8093F77A19B30871` | saved `+0xc`, return `+0x10`, `arg_0 +0x14/4/_DWORD`, `arg_4 +0x18/4/_DWORD` | absent / absent / absent / absent |
| `[0x458430,0x458485)` | `sub_458430` / `void *__thiscall(EPFTileContext *this,int,int)` | `0x55` / `86A23FA30DCA5D4F5BC07E5EAFE337E96056F4D7688D9DEEBA91ED15225FE428` | same four-row allocation frame | absent / absent / absent / absent |
| `[0x458490,0x4584fa)` | `sub_458490` / `unsigned __int16 *__thiscall(EPFTileContext *this,int,int)` | `0x6a` / `45906CB674812FDF7DB1FC15FD5A746B0335D1949C869086061E798DF3B8A382` | `var_4 +0xc`, saved `+0x10`, return `+0x14`, args `+0x18/+0x1c` | absent / absent / absent / absent |
| `[0x458500,0x458557)` | `EPFTileContext__ReleaseBuffers` / `void *__thiscall(EPFTileContext *this)` | `0x57` / `D9E6BBB2C4B27E099244C52ABA980D8C165018FEC4E91028CCDDF96C5950C5FF` | return `+0x8/4/_UNKNOWN *` | absent / absent / exact current regular comment retained / absent |
| `[0x458560,0x458585)` | `sub_458560` / `void __thiscall(int this)` | `0x25` / `82FE00C34B29A32321FDF197E2BE5B34A8AC504AC1EDD203D62B930DF873C0C2` | return `+0x0/4/_UNKNOWN *` | absent / absent / absent / absent |
| `[0x458590,0x458610)` | `sub_458590` / `char __thiscall(_DWORD *this,int)` | `0x80` / `AFEBBA908F921BB7AE1E9AB155307238634D69811A237B138CAB1E01CAC48431` | `var_8 +0xc`, `var_4 +0x10`, saved `+0x14`, return `+0x18`, `arg_0 +0x1c` | absent / absent / absent / absent |

Fresh read-only type-channel evidence was collected under runtime-attested canonical session `supervisor_uid0002ox_persistverify_20260817` at listener attestation `2026-08-18T02:34:58.857809+00:00`. Structural persisted-TInfo projections came from public `disasm` (`ida_nalt.get_tinfo` plus function details), rendered signatures came from public `decompile`, and public type presentation came from `inspect_items` (`idc.get_type`). Two complete `inspect_items` passes surrounding the decompiler reads were identical.

| Action / address | Persisted IDB name / TInfo prestate -> exact poststate | Public `inspect_items` symbol / type prestate -> exact poststate | Exact immediate Hex-Rays prestate -> post-rename presentation |
| --- | --- | --- | --- |
| A01 / `0x457a60` | `EPFTileContext_Initialize`; return `void`, `{this:EPFTileContext *}` -> `EPFTileContext__EPFTileContext`; same TInfo | `EPFTileContext_Initialize` / `void __thiscall(EPFTileContext *this)` -> `EPFTileContext__EPFTileContext` / same type | `void __thiscall EPFTileContext_Initialize(EPFTileContext *this)` -> exact same cached header |
| A02 / `0x457ab0` | `sub_457AB0`; return `void *`, `{this:_DWORD *}` -> `EPFTileContext__BuildEncodedMask`; same TInfo | `sub_457AB0` / `void *__thiscall(_DWORD *this)` -> `EPFTileContext__BuildEncodedMask` / same type | `void *__thiscall sub_457AB0(_DWORD *this)` -> exact same cached header |
| A03 / `0x457c60` | `sub_457C60`; return `MemoryMan *`, `{this:_DWORD *}` -> `EPFTileContext__BuildEncodedMask16`; same TInfo | `sub_457C60` / branch P0 `void *__thiscall(_DWORD *this)` or P1 `MemoryMan *__thiscall(_DWORD *this)` -> `EPFTileContext__BuildEncodedMask16` / exact `MemoryMan *__thiscall(_DWORD *this)` | `MemoryMan *__thiscall sub_457C60(_DWORD *this)` -> exact same cached header |
| A04 / `0x457e00` | `sub_457E00`; return `void *`, `{this:void *,arg1:EPFTileContext *}` -> `EPFTileContext__CopyTo`; same TInfo | `sub_457E00` / `void *__thiscall(void *this, EPFTileContext *)` -> `EPFTileContext__CopyTo` / same type | `void *__thiscall sub_457E00(void *this, EPFTileContext *a2)` -> exact same cached header |
| A05 / `0x457f30` | absent: no function -> absent | absent: no function -> absent | absent: no function -> absent; no endpoint |
| A07 / `0x457ff0` | `sub_457FF0`; return `struct RectBounds *`, `{this:_DWORD *}` -> `EPFTileContext__CreateHalfScaleCopy`; same TInfo | `sub_457FF0` / `struct RectBounds *__thiscall(_DWORD *this)` -> `EPFTileContext__CreateHalfScaleCopy` / same type | `struct RectBounds *__thiscall sub_457FF0(_DWORD *this)` -> exact same cached header |
| A08 / `0x458260` | `sub_458260`; return `struct RectBounds *`, `{this:_DWORD *}` -> `EPFTileContext__CreateHalfScaleRgb16Copy`; same TInfo | `sub_458260` / `struct RectBounds *__thiscall(_DWORD *this)` -> `EPFTileContext__CreateHalfScaleRgb16Copy` / same type | `struct RectBounds *__thiscall sub_458260(_DWORD *this)` -> exact same cached header |
| A09 / `0x4583d0` | `sub_4583D0`; return `void *`, `{this:EPFTileContext *,arg1:int,arg2:int}` -> `EPFTileContext__AllocateIndexed8Pixels`; same TInfo | `sub_4583D0` / `void *__thiscall(EPFTileContext *this, int, int)` -> `EPFTileContext__AllocateIndexed8Pixels` / same type | `void *__thiscall sub_4583D0(EPFTileContext *this, int a2, int a3)` -> exact same cached header |
| A10 / `0x458430` | `sub_458430`; return `void *`, `{this:EPFTileContext *,arg1:int,arg2:int}` -> `EPFTileContext__AllocateRgb16Pixels`; same TInfo | `sub_458430` / `void *__thiscall(EPFTileContext *this, int, int)` -> `EPFTileContext__AllocateRgb16Pixels` / same type | `void *__thiscall sub_458430(EPFTileContext *this, int a2, int a3)` -> exact same cached header |
| A11 / `0x458490` | `sub_458490`; return `unsigned __int16 *`, `{this:EPFTileContext *,arg1:int,arg2:int}` -> `EPFTileContext__AllocateRgb16PixelsWithAlpha`; same TInfo | `sub_458490` / `unsigned __int16 *__thiscall(EPFTileContext *this, int, int)` -> `EPFTileContext__AllocateRgb16PixelsWithAlpha` / same type | `unsigned __int16 *__thiscall sub_458490(EPFTileContext *this, int a2, int a3)` -> exact same cached header |
| A12 / `0x458560` | `sub_458560`; return `void`, `{this:int}` -> `EPFTileContext__NormalizePostDecodePixels`; same TInfo | `sub_458560` / `void __thiscall(int this)` -> `EPFTileContext__NormalizePostDecodePixels` / same type | `void __thiscall sub_458560(int this)` -> exact same cached header |
| A13 / `0x458590` | `sub_458590`; return `char`, `{this:_DWORD *,arg1:int}` -> `EPFTileContext__ContainsIndexedPixelInRanges`; same TInfo | `sub_458590` / `char __thiscall(_DWORD *this, int)` -> `EPFTileContext__ContainsIndexedPixelInRanges` / same type | `char __thiscall sub_458590(_DWORD *this, int a2)` -> exact same cached header |
### Type and compiler facts

- IDA `EPFTileContext` exists, size `40`, with seven exact members: enum +0, `void *` +4, `unsigned __int16 *` +8, `int` +0xc, `RectBounds` +0x10/16, `int` +0x20, `unsigned __int8 *` +0x24.
- `EPFTilePixelFormat` exists as a four-byte enum. `RectBounds` exists as four signed ints/16 bytes. No vtable/RTTI applies.
- IDA `DLPalette` exists at 556 bytes with stale `m_entryMoves`/`m_entryMoveCount` presentation; `DLPaletteRange` is literal absent. Source header truth is already complete and no IDA type mutation is recommended here.
- EH chunk hashes: `[0x5fa0c0,0x5fa0f9)` `D54CA7B9F05FBD8C63C6FBD643B1A7CD8C2F747CA62A860E6CD3C0AF7E44FD63`; `[0x5fa0f9,0x5fa123)` `EFA719E782BB9489BD7748EE2DCDF28722ABB30DC1405283BB4FEE5024B28993`.
- EH data hashes: `stru_6588F4` 8 bytes `BC8B2E447709C97A840CBAE0E85EB8C3BC1F4F03DA63459D06390BC04BD43231`; `stru_6588FC` 8 bytes `60B6758C2F8BF70EC251A58060ABACACA1C76E1B39982AD2E4EA30C91A9C9D1A`; `stru_65890C` 36 bytes `DF2190CD95860A9C3E4EF7B0D5DD136ECD076E34BF53C9C37A437A6093832B5B`; `stru_658930` 36 bytes `6B33444714C0E044F72813218314EF58ACB1F628955C08827140997091331D3E`. Every comment channel is absent.

## Function / Child Inventory

### Source and compiler inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x457a60-0x457aa4` | UID0000XY | default constructor | yes | UID00004I | aggregate `94/94` | constructor CPP and H identity applied |
| `0x457ab0-0x457c53` | UID0000XY | indexed-mask builder | yes | UID00004I | aggregate | CPP applied |
| `0x457c60-0x457df2` | UID0000XY | RGB16 mask helper | yes | UID00004I | aggregate | private CPP/H applied |
| `0x457e00-0x457f2b` | UID0000XY | generic deep copy | yes | UID00004I | aggregate | CPP applied |
| `0x457f30-0x457fe9` | UID0000XY | retained RGB16 deep-copy helper | yes | UID00004I | aggregate | raw/no-function IDA prestate retained; private CPP/H applied |
| `0x457ff0-0x458253` | UID0000XY | generic half-scale copy | yes | UID00004I | aggregate | public CPP/H applied |
| `0x458260-0x4583c8` | UID0000XY | retained RGB16 half-scale helper | yes | UID00004I | aggregate | private CPP/H applied |
| `0x4583d0-0x458423` | UID0000XY | indexed allocation | yes | UID00004I | aggregate | CPP applied |
| `0x458430-0x458485` | UID0000XY | RGB16 allocation | yes | UID00004I | aggregate | CPP applied |
| `0x458490-0x4584fa` | UID0000XY | RGB16+alpha allocation | yes | UID00004I | aggregate | CPP applied |
| `0x458500-0x458557` | UID0000XY | explicit buffer release; not destructor | yes | UID00004I | aggregate | CPP applied |
| `0x458560-0x458585` | UID000200 | post-decode normalization | yes | UID00004I | `92/94` | exact child CPP preserved at position `10` |
| `0x458590-0x458610` | UID000201 | indexed range query | yes | UID00004I | `89/92` | exact child CPP preserved at position `20` |
| `0x5fa0c0-0x5fa0f9` | compiler-covered | two new-expression cleanup pads + handler tail for generic half-scale | no authored emission | `0x457ff0` | n/a | no-code |
| `0x5fa0f9-0x5fa123` | compiler-covered | new-expression cleanup + handler tail for RGB16 helper | no authored emission | `0x458260` | n/a | no-code |
| `0x6588f4-0x6588fc` | compiler-covered | EH pointer record for `0x458260` | no authored emission | compiler | n/a | no-code |
| `0x6588fc-0x658904` | compiler-covered | EH pointer record for `0x457ff0` | no authored emission | compiler | n/a | no-code |
| `0x65890c-0x658930` | compiler-covered | EH metadata for `0x458260` | no authored emission | compiler | n/a | no-code |
| `0x658930-0x658954` | compiler-covered | EH metadata for `0x457ff0` | no authored emission | compiler | n/a | no-code |
| `EPFTileContext` | UID00004I | exact 0x28 struct/header | yes | UID0000J4 | `94/94` | complete layout/API and CPP/H topology |
| `EPFTilePixelFormat` | UID00004I | two-value four-byte enum | yes | UID0000J4 | class | already represented |
| `RectBounds/RectArea` | UID0000BU/UID00015T | by-value bounds and allocation area helper | dependency | UID0000N2 | `91/90`, `88/92` | exact RectArea H declaration applied |
| `MemoryMan/GetMemoryMan` | UID00007U/UID0001BC | allocation/free/memmove | dependency | UID0000L7 | current | complete H |
| `DLPalette/DLPaletteRange` | UID00003Z | indexed range records | dependency | UID0000MA | `92/94` | complete H/friendship |
| `ConvertRgb565ToRgb555Pixels` | UID0003ZP | normalization helper | dependency | UID0000NT | `93/95` | exact H declaration applied |
| `g_surfaceUsesRgb565Pixels` | UID00029U | active Surface format flag | dependency | UID0000OC | `90/94` | exact H extern applied; 32-bit peer remains file-static |

### Exact padding and boundary inventory

Each row is data-classified all-`cc` alignment with no authored emission: `[0x457aa4,0x457ab0)` 12; `[0x457c53,0x457c60)` 13; `[0x457df2,0x457e00)` 14; `[0x457f2b,0x457f30)` 5; `[0x457fe9,0x457ff0)` 7; `[0x458253,0x458260)` 13; `[0x4583c8,0x4583d0)` 8; `[0x458423,0x458430)` 13; `[0x458485,0x458490)` 11; `[0x4584fa,0x458500)` 6; `[0x458557,0x458560)` 9; `[0x458585,0x458590)` 11.

Excluded neighbors: `[0x457960,0x457a5d)` is predecessor `sub_457960`, `[0x457a5d,0x457a60)` is three-byte boundary padding, and `[0x458610,0x45894b)` is successor `sub_458610`/RankingDialog. None belongs to EPFTileContext.

Totals: 13 authored bodies, 12 internal padding intervals, 6 compiler-only EH items, 2 owned type entities, 5 required dependency groups, 3 excluded boundary items, no file-owned data/global/string/table/vtable/RTTI/resource/import item, and 64 affected consumer pages individually enumerated in Section 25. Every source-bearing row has a Section 22 CPP/H or no-code disposition.

## Direct Xref / Caller Inventory

| Address / item | Exact inbound xrefs | Exact callees / meaning |
| --- | --- | --- |
| `0x457a60` | `337` code xrefs; complete set below | `InitRectBounds@0x4b7c50`; constructor fan-in |
| `0x457ab0` | `6/{0x4562f3,0x499390,0x4f4e12,0x4f5207,0x4ff22d,0x4ff5ed}` | alloca, GetMemoryMan, RGB helper, cookie, free/allocate/memmove |
| `0x457c60` | `1/{0x457ade}` | alloca, GetMemoryMan, cookie, free/allocate/memmove |
| `0x457e00` | `3/{0x4d050a,0x4ff226,0x4ff5e6}` | GetMemoryMan, ReleaseBuffers, allocate, memmove |
| `0x457f30` | `0/{}` | calls at `0x457f39` GetMemoryMan, `0x457f48` ReleaseBuffers, allocate at `0x457f7b/0x457fa8/0x457fca`, memmove at `0x457f8d/0x457fba/0x457fdb` |
| `0x457ff0` | `0/{}` | GetMemoryMan, operator new, constructor, InitRectBounds, RectArea, allocate; EH chunk associated |
| `0x458260` | `0/{}` | GetMemoryMan, operator new, InitRectBounds, RectArea, allocate; constructor inlined; EH chunk associated |
| `0x4583d0` | `1/{0x4d0a16}` | ReleaseBuffers, GetMemoryMan, allocate |
| `0x458430` | `4/{0x4d06c8,0x4d076d,0x4d08ad,0x4d0b65}` | ReleaseBuffers, GetMemoryMan, allocate |
| `0x458490` | `2/{0x4d0c9e,0x4d0e34}` | ReleaseBuffers, GetMemoryMan, two allocations |
| `0x458500` | `71` code xrefs; complete set below | GetMemoryMan, FreeBufferMemory; explicit release fan-in |
| `0x458560` | `6/{0x4d06f2,0x4d079a,0x4d0991,0x4d0c42,0x4d0d7d,0x4d0f29}` plus data read from `0x69b3d5` | ConvertRgb565ToRgb555Pixels |
| `0x458590` | `2/{0x4df70c,0x4df7aa}` | no callees; two calls in one ItemObjImageLib method |

The exact 337-constructor set is:

`{0x41baf8,0x41bb03,0x41bb0e,0x41bc51,0x41bc5c,0x41bc64,0x41c615,0x41c7b7,0x41dad3,0x41f2eb,0x41f4b1,0x41f4c6,0x451291,0x453f66,0x455edf,0x458182,0x458b85,0x458d24,0x458e3c,0x459d03,0x45b2f8,0x45b67d,0x45b7e9,0x45bb3f,0x45dfb3,0x45e028,0x45e533,0x45f3d5,0x461153,0x46758b,0x4678a9,0x46b04f,0x46b0fa,0x46c3ea,0x46dd32,0x46debd,0x4783b4,0x4783bc,0x4783c4,0x4784f8,0x478500,0x478508,0x480bd8,0x480ea4,0x4816e6,0x48176d,0x482166,0x4836ce,0x48387d,0x484a7d,0x484a85,0x4887f4,0x48b0c4,0x48c06a,0x48d4c4,0x48dd83,0x48dd8e,0x48dd99,0x48dda4,0x48ddaf,0x48e00e,0x48e016,0x494637,0x495963,0x4959b0,0x495e07,0x496357,0x496500,0x49669a,0x498293,0x4982b3,0x4982d3,0x499327,0x49944b,0x499453,0x499b19,0x499e65,0x49d8fa,0x49db82,0x49f1f3,0x49f242,0x49f30a,0x49f602,0x4a2589,0x4a2864,0x4a458d,0x4a4595,0x4ae203,0x4ae35a,0x4aecd3,0x4aee87,0x4b0fca,0x4b1c29,0x4b7426,0x4b8c3b,0x4b8e5e,0x4bb206,0x4bb606,0x4cf03d,0x4cf0d4,0x4cf320,0x4d04ee,0x4d1a7a,0x4d4fc4,0x4d4fcf,0x4d4fda,0x4d4fe5,0x4d4ff0,0x4d4ffb,0x4d5006,0x4d5011,0x4d501c,0x4d5027,0x4d5032,0x4d503d,0x4d5048,0x4d5053,0x4d5fe1,0x4d5fec,0x4d5ff7,0x4d6002,0x4d600d,0x4d6018,0x4d6023,0x4d602e,0x4d6039,0x4d6044,0x4d604f,0x4d605a,0x4d6065,0x4d6070,0x4d6c3d,0x4d6ce0,0x4d6ceb,0x4d6cf6,0x4d6d01,0x4d6d09,0x4d6d14,0x4d6d1f,0x4d6d2a,0x4d6d35,0x4d6d40,0x4d6d4b,0x4d6d56,0x4d6d61,0x4db197,0x4db3f6,0x4dc878,0x4dcae6,0x4dd329,0x4dd8d1,0x4de1f1,0x4dee87,0x4df03d,0x4df207,0x4df32c,0x4df6b5,0x4df753,0x4e227a,0x4e249a,0x4e33ee,0x4e3bb1,0x4e417f,0x4e4357,0x4e437a,0x4e4382,0x4e9839,0x4ea2dc,0x4ea2e7,0x4ebb5a,0x4ebb67,0x4ee725,0x4ee730,0x4f4c74,0x4f6786,0x4f7701,0x4f7889,0x4fd25e,0x4fd38b,0x4fda4e,0x4ff0ae,0x4ff46e,0x4ff82e,0x500037,0x500717,0x500837,0x500d87,0x500e3d,0x50137b,0x501383,0x50185b,0x501863,0x501c79,0x50312e,0x503272,0x5035f6,0x5067dc,0x5167bf,0x518e50,0x518e58,0x518e60,0x518e6b,0x518e76,0x518e81,0x51b423,0x51b660,0x51c703,0x51c89e,0x51f876,0x5205d8,0x52092b,0x538c67,0x539051,0x5394f1,0x53ffe9,0x540002,0x540022,0x540042,0x540062,0x5459d3,0x5459db,0x5459e6,0x5459f1,0x5459fc,0x545a07,0x545a12,0x545a1d,0x545d6d,0x5468a6,0x546e07,0x54a70b,0x54b806,0x54baf7,0x555306,0x55538d,0x555c86,0x555d0d,0x55a508,0x55a684,0x55a838,0x55ab65,0x55b5e6,0x55c681,0x55cf18,0x55f8b3,0x560d63,0x562213,0x5636c3,0x564b6e,0x5674b8,0x5674c3,0x5674ce,0x5674d9,0x569d9e,0x569da6,0x56c6d8,0x56c988,0x56ce8b,0x56cedf,0x56ceea,0x56cef5,0x56cf00,0x56cf0b,0x56e6ee,0x56e6f6,0x56edfb,0x56fde8,0x570ffa,0x5726be,0x57c474,0x57d45e,0x57d474,0x57eb24,0x584f22,0x584f2d,0x584f38,0x584f43,0x584f4e,0x584f59,0x584f64,0x584f6f,0x584f7a,0x584f85,0x588516,0x588da8,0x588eb1,0x588ebc,0x588ec7,0x588ed2,0x588edd,0x588ee8,0x588ef3,0x588efe,0x588f09,0x588f14,0x59551d,0x598b64,0x598b75,0x598de7,0x599307,0x59df68,0x59df70,0x59e782,0x59e7a4,0x59e7be,0x59f2e7,0x5a0678,0x5b8caa,0x5b8cb5,0x5b8cc0,0x5b9100,0x5b910b,0x5b9116,0x5ba03e,0x5bafaa,0x5bafb5,0x5bafc0,0x5bafcb,0x5bafd6,0x5bafe1,0x5bc02e,0x5bc817,0x5bd5c6,0x5bd64d,0x5be550,0x5be55b,0x5be566,0x5bf3ce,0x5c1f23,0x5c2202,0x5c22ac,0x5c22b7,0x5c2b58,0x5c2b63,0x5c2b6e,0x5c2b79,0x5c2b84}`.

The exact 71-release set is:

`{0x45403b,0x456082,0x456359,0x457e27,0x457e8e,0x457f48,0x4583d8,0x458438,0x45849c,0x4992f2,0x49b1f9,0x49daad,0x49dba2,0x4b608f,0x4b8d97,0x4b8e7b,0x4bb85e,0x4d061d,0x4d0698,0x4d073a,0x4d09bc,0x4f4cce,0x4f4ef6,0x4f50c0,0x4f534d,0x4f6967,0x4ff2d5,0x4ff695,0x5028ae,0x502bac,0x502c5c,0x50689a,0x520800,0x5852cd,0x5852d8,0x5852e3,0x5852ee,0x5852f9,0x585304,0x58530f,0x58531a,0x585325,0x585330,0x589211,0x58921c,0x589227,0x589232,0x58923d,0x589248,0x589253,0x58925e,0x589269,0x589274,0x58ae4d,0x58ae58,0x58ae63,0x58ae6e,0x58ae79,0x58ae84,0x58ae8f,0x58ae9a,0x58aea5,0x58aeb0,0x59e8f2,0x59e912,0x59e925,0x59f1e5,0x59f202,0x59f215,0x59f5c4,0x5a24bb}`.

Compiler refs are exact: `0x6588fc -> 0x5fa0c0`, `0x6588f4 -> 0x5fa0f9`, `0x5fa0ef -> 0x658930`, `0x5fa119 -> 0x65890c`, `0x658930 -> 0x6588fc`, and `0x65890c -> 0x6588f4`. The two chunks call allocation cleanup `sub_5C7526`, security-cookie checking, and tail-jump `__CxxFrameHandler3`.

## Documentation Evidence And IDA Status

- Current docs establish render ownership, exact 0x28 layout, mask semantics, Palette friendship, normalization, range query, 13-body source, constructor identity, retained-helper policy, half-scale API, and complete dependency H.
- Dated pre-callback docs contained body count 12, `Initialize` method identity, three retained-helper blockers, blank aggregate source, absent half-scale API, incomplete dependency H, and statements that complete body C++ remained blocked; the accepted callback preserved that history while correcting current prose/formals.
- Generated command `000000025538` is dated defective evidence only. Final callback command `000000025741` physically confirms the accepted CPP/H route; gate-time generated authority remains subject to supervisor reread.
- IDA remains semantically stronger than source docs for constructor/EH identity but weaker than source headers for `DLPaletteRange`. This report keeps those evidence domains separate.

## Ranked Ownership Analysis

### 1. Existing UID0000J4 / UID00004I chain

- Evidence for: exact file/class metadata, coherent 13-body family, shared 0x28 receiver, render dependencies, broad image/UI use, current generated destination.
- Evidence against: none material; current body routing is incomplete, not misowned.
- Decision: retain and complete.

### 2. Split exact children for all eleven missing bodies

- Evidence for: could provide function-granular pages.
- Evidence against: UID0000XY already exists as the complete aggregate body container; splitting adds no behavioral clarity and would expand lifecycle/coverage churn.
- Decision: reject; retain two existing exact tail children only.

### 3. Consumer or dependency ownership

- Evidence for: EPFImageControlPane, ResourceLayoutTable, decoders, Palette, Surface, and many panes call individual methods.
- Evidence against: none covers the complete family; receiver storage and direct parent are EPFTileContext.
- Decision: reject caller-biased ownership.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: not applicable; existing `NexusTK/render/EPFTileContext.cpp/.h` is correct.
- Likely full contents: exact Section 22 source.
- Candidate related items rejected: predecessor image helper, successor RankingDialog, Surface globals, Palette storage, RectBounds implementation, MemoryMan implementation.
- Standalone/narrow/broad inference: narrow complete render value-type unit with external dependency declarations.

## Source Placement

- Recommended placement: UID00004I header and preamble under `NexusTK/render/EPFTileContext.h/.cpp`; UID0000XY definitions as first child block; UID000200 and UID000201 after it.
- This matches current path metadata, generated include topology, and dependency direction.
- Reject `ui/` placement because UI consumers do not own the type; reject Palette/Surface/SoftwareBlend16 because those supply dependencies only.
- Remaining placement uncertainty: none.

## Range / Split / Padding / Reclassification Analysis

- Exact authored primary boundary is `[0x00457a60,0x00458610)`. Thirteen bodies and twelve internal all-`cc` gaps account for every byte.
- Reclassify `0x00457a60` from ordinary `Initialize` to default constructor in source/docs/IDA recommendation.
- Retain raw code `[0x00457f30,0x00457fe9)` without an IDA function definition; no source split/child UID is required, and the behaviorally reconstructed private source method remains valid independently of the raw IDA item model.
- Retain UID000200/UID000201 exact children and set positions `10`/`20` after aggregate position `0`.
- EH chunks/data remain compiler-covered. Padding remains no-code/no-data-source.
- Parent/container ranges and ownership do not change.

## Negative Evidence Summary

- No body, data, or xref crosses the `0x457a60`/`0x458610` boundaries.
- No file-owned global/static/constant/string/table/vtable/RTTI/resource/import object exists.
- Zero direct start xrefs for `0x457f30`, `0x457ff0`, and `0x458260` do not prove dead source; exact inlined branch correspondence proves retained liveness.
- No automatic call to `ReleaseBuffers` at borrowed local scope exits supports a destructor.
- Current IDA `DLPaletteRange` absence does not invalidate current source header truth and is not permission to mutate DLPalette.
- Nearby RankingDialog, Surface callbacks, Palette records, and decoder functions are dependencies/consumers rather than this unit's members.

## IDA Rename / Type / Comment Recommendations

This is a read-only structured handoff. Dated evidence was re-attested on `supervisor_uid0000nn_gate2b_20260817` at `2026-08-17T20:10:03.109845+00:00` against backup `C:\FastStorage\NTK_Sources\source-3\project-documentation\tools\leaser\Agents\ida-backups\NexusTK.exe.uid0000NN-prechange-20260817_160930194.i64` after the earlier canonical session closed; bounded target bytes at `0x457a60`, `0x457f30`, and `0x458590` were byte-identical to the hashes above. All twelve researched source-facing names had collision count zero in that dated readback; after the A05 fail-closed disposition, eleven remain proposed IDA names and `EPFTileContext__CopyRgb16To` remains source-facing only. The fresh Gate 2B runtime-attested session ID must replace the evidence-time ID in endpoint calls.

Fresh repair evidence: runtime attestation succeeded for canonical path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` and session `supervisor_uid0002ox_persistverify_20260817` at `2026-08-18T02:34:58.857809+00:00`; server health was `status:ok`, Hex-Rays ready, with `auto_analysis_ready:false` recorded as context. The attested worker loaded `ida_pro_mcp.ida_mcp.api_modify` SHA256 `E5618EE3A9E11EE9F67A46067146CD39EA35E44F0859EBDEAC2028A581EABAA1` (52,804 bytes; package `ida_pro_mcp 2.0.0`). Source inspection proves `inspect_items` returns `idc.get_type(head)`, while a pure function rename calls `idaapi.set_name` and skips both directory placement and `refresh_decompiler_ctext`; no type-write API is invoked.

Dated failed Gate 2B evidence: disposable session `supervisor_uid0000j4_gate2b_20260817_2220`, transaction `X:\NTK_IDA_Transactions\NexusTK.exe.uid0000J4-transaction-20260817_222050403.i64`, and backup `X:\NTK_IDA_Transactions\NexusTK.exe.uid0000J4-prechange-20260817_222050403.i64` were discarded without save. Canonical, backup, and transaction remained byte-identical SHA256 `83D734B1E8F429C178DE32335B395C0F03F41426E511CF905218086D7E817CA3`, 143,209,591 bytes. A01 and A02 passed. At A03, public `inspect_items` changed only its rendered type presentation from `void *__thiscall(_DWORD *this)` to `MemoryMan *__thiscall(_DWORD *this)`; name, F1, comments, inbound `1/{0x457ade}`, bytes/range/hash, and all other protected state passed. The absence of a type-write call plus unchanged structural state supports classifying this exact delta as public presentation/cache convergence, not an owned persisted-TInfo mutation.

Dated 2026-08-17 second Gate 2B fail-closed evidence: canonical session `supervisor_uid0002ox_persistverify_20260817` applied A01 after exact prestate verification. The persisted IDB symbol and public `inspect_items` symbol became `EPFTileContext__EPFTileContext`, and `inspect_items` retained type `void __thiscall(EPFTileContext *this)`, while immediate Hex-Rays pseudocode retained the exact cached header `void __thiscall EPFTileContext_Initialize(EPFTileContext *this)`. That result is consistent with the attested `pure:true` implementation skipping `refresh_decompiler_ctext`. Supervisor stopped before A02, rolled A01 back, verified the original symbol/type/size/comments, saved no failed mutation, and re-attested canonical on-disk SHA256 `7525449D0F3389BC5CB63FFD18574ACD27F381EB7D5367192204113374415E3F`, 143,210,606 bytes.

Type and comment disposition: source signatures are resolved in Section 22, but no `set_type` or comment mutation is recommended in this transaction. The public pure-rename implementation calls only `idaapi.set_name`; with `pure:true` it skips both function-directory placement and `refresh_decompiler_ctext`, and it invokes no type-write endpoint. Each apply row owns only one persisted/public function symbol. Persisted IDB TInfo is protected unchanged for every function. Because each literal prestate read populates the decompiler cache and the endpoint does not refresh it, immediate Hex-Rays readback must retain the exact row-specific cached pre-rename function-name/prototype. A refreshed new-name header or any other function-name/prototype at that immediate endpoint is a hard stop; later non-mutating cache refresh or session reload presentation is outside the action endpoint and is not a persisted-IDB delta. Public `inspect_items` must expose the exact new symbol and is type-protected unchanged except at A03, where only the enumerated P0 `void *` to `MemoryMan *` convergence is permitted; P1 remains stable. A05 owns no field and requires literal no change; A06 is retired and invokes no endpoint. AR, AP, FR, FP, frames, bytes, ranges, item models, and xrefs remain independently protected.

Frame literals used below:

- `F0` = `{__return_address +0x4/0x4/_UNKNOWN *}`.
- `F1` = `{var_186C0 +0x4/4/MemoryMan *, var_186BC +0x8/4/_DWORD, var_186B8 +0xc/4/_DWORD, var_186B4 +0x10/4/_DWORD, var_186B0 +0x14/4/_DWORD, var_186AC +0x18/4/_DWORD, var_186A8 +0x1c/4/_DWORD, Src +0x20/1/_BYTE, var_4 +0x186c0/4/_DWORD, __saved_registers +0x186c4/4/_DWORD, __return_address +0x186c8/4/_UNKNOWN *}`.
- `F2` = `{var_4 +0xc/4/MemoryMan *, __saved_registers +0x10/4/_DWORD, __return_address +0x14/4/_UNKNOWN *, arg_0 +0x18/4/EPFTileContext *}`.
- `F3` = `{var_18 +0x10/4/MemoryMan *, Block +0x14/4/void *, var_10 +0x18/4/_DWORD, var_C +0x1c/4/_DWORD, var_4 +0x24/4/_DWORD, __saved_registers +0x28/4/_DWORD, __return_address +0x2c/4/_UNKNOWN *, arg_4 +0x34/4/_DWORD}`.
- `F4` = `{__saved_registers +0xc/4/_DWORD, __return_address +0x10/4/_UNKNOWN *, arg_0 +0x14/4/_DWORD, arg_4 +0x18/4/_DWORD}`.
- `F5` = `{var_4 +0xc/4/_DWORD, __saved_registers +0x10/4/_DWORD, __return_address +0x14/4/_UNKNOWN *, arg_0 +0x18/4/_DWORD, arg_4 +0x1c/4/_DWORD}`.
- `F6` = `{__return_address +0x0/4/_UNKNOWN *}`.
- `F7` = `{var_8 +0xc/4/_DWORD, var_4 +0x10/4/_DWORD, __saved_registers +0x14/4/_DWORD, __return_address +0x18/4/_UNKNOWN *, arg_0 +0x1c/4/_DWORD}`.

For every row, "comments absent" means literal AR `absent`, AP `absent`, FR `absent`, FP `absent`. At A05, AR and AP are literally `absent`, while FR and FP are literally `absent because no function entry exists`.

| ID | Classification / dependency | Literal immediate prestate | Public endpoint and owned field | Exact expected readback / hard stop |
| --- | --- | --- | --- | --- |
| A01 | apply; first | `[0x457a60,0x457aa4)`, size `0x44`, SHA256 `F690BAD0AC3912C12EB46F00785CD5B95C33C5CEB1BDA4F0163674FF436F3A41`; persisted IDB name `EPFTileContext_Initialize`; public `inspect_items` symbol `EPFTileContext_Initialize`; persisted IDB TInfo return `void`, arguments `{this:EPFTileContext *}`; Hex-Rays signature `void __thiscall EPFTileContext_Initialize(EPFTileContext *this)`; public `inspect_items` presentation `void __thiscall(EPFTileContext *this)`; frame `F0`; comments absent; inbound `337` with literal set `{0x41baf8,0x41bb03,0x41bb0e,0x41bc51,0x41bc5c,0x41bc64,0x41c615,0x41c7b7,0x41dad3,0x41f2eb,0x41f4b1,0x41f4c6,0x451291,0x453f66,0x455edf,0x458182,0x458b85,0x458d24,0x458e3c,0x459d03,0x45b2f8,0x45b67d,0x45b7e9,0x45bb3f,0x45dfb3,0x45e028,0x45e533,0x45f3d5,0x461153,0x46758b,0x4678a9,0x46b04f,0x46b0fa,0x46c3ea,0x46dd32,0x46debd,0x4783b4,0x4783bc,0x4783c4,0x4784f8,0x478500,0x478508,0x480bd8,0x480ea4,0x4816e6,0x48176d,0x482166,0x4836ce,0x48387d,0x484a7d,0x484a85,0x4887f4,0x48b0c4,0x48c06a,0x48d4c4,0x48dd83,0x48dd8e,0x48dd99,0x48dda4,0x48ddaf,0x48e00e,0x48e016,0x494637,0x495963,0x4959b0,0x495e07,0x496357,0x496500,0x49669a,0x498293,0x4982b3,0x4982d3,0x499327,0x49944b,0x499453,0x499b19,0x499e65,0x49d8fa,0x49db82,0x49f1f3,0x49f242,0x49f30a,0x49f602,0x4a2589,0x4a2864,0x4a458d,0x4a4595,0x4ae203,0x4ae35a,0x4aecd3,0x4aee87,0x4b0fca,0x4b1c29,0x4b7426,0x4b8c3b,0x4b8e5e,0x4bb206,0x4bb606,0x4cf03d,0x4cf0d4,0x4cf320,0x4d04ee,0x4d1a7a,0x4d4fc4,0x4d4fcf,0x4d4fda,0x4d4fe5,0x4d4ff0,0x4d4ffb,0x4d5006,0x4d5011,0x4d501c,0x4d5027,0x4d5032,0x4d503d,0x4d5048,0x4d5053,0x4d5fe1,0x4d5fec,0x4d5ff7,0x4d6002,0x4d600d,0x4d6018,0x4d6023,0x4d602e,0x4d6039,0x4d6044,0x4d604f,0x4d605a,0x4d6065,0x4d6070,0x4d6c3d,0x4d6ce0,0x4d6ceb,0x4d6cf6,0x4d6d01,0x4d6d09,0x4d6d14,0x4d6d1f,0x4d6d2a,0x4d6d35,0x4d6d40,0x4d6d4b,0x4d6d56,0x4d6d61,0x4db197,0x4db3f6,0x4dc878,0x4dcae6,0x4dd329,0x4dd8d1,0x4de1f1,0x4dee87,0x4df03d,0x4df207,0x4df32c,0x4df6b5,0x4df753,0x4e227a,0x4e249a,0x4e33ee,0x4e3bb1,0x4e417f,0x4e4357,0x4e437a,0x4e4382,0x4e9839,0x4ea2dc,0x4ea2e7,0x4ebb5a,0x4ebb67,0x4ee725,0x4ee730,0x4f4c74,0x4f6786,0x4f7701,0x4f7889,0x4fd25e,0x4fd38b,0x4fda4e,0x4ff0ae,0x4ff46e,0x4ff82e,0x500037,0x500717,0x500837,0x500d87,0x500e3d,0x50137b,0x501383,0x50185b,0x501863,0x501c79,0x50312e,0x503272,0x5035f6,0x5067dc,0x5167bf,0x518e50,0x518e58,0x518e60,0x518e6b,0x518e76,0x518e81,0x51b423,0x51b660,0x51c703,0x51c89e,0x51f876,0x5205d8,0x52092b,0x538c67,0x539051,0x5394f1,0x53ffe9,0x540002,0x540022,0x540042,0x540062,0x5459d3,0x5459db,0x5459e6,0x5459f1,0x5459fc,0x545a07,0x545a12,0x545a1d,0x545d6d,0x5468a6,0x546e07,0x54a70b,0x54b806,0x54baf7,0x555306,0x55538d,0x555c86,0x555d0d,0x55a508,0x55a684,0x55a838,0x55ab65,0x55b5e6,0x55c681,0x55cf18,0x55f8b3,0x560d63,0x562213,0x5636c3,0x564b6e,0x5674b8,0x5674c3,0x5674ce,0x5674d9,0x569d9e,0x569da6,0x56c6d8,0x56c988,0x56ce8b,0x56cedf,0x56ceea,0x56cef5,0x56cf00,0x56cf0b,0x56e6ee,0x56e6f6,0x56edfb,0x56fde8,0x570ffa,0x5726be,0x57c474,0x57d45e,0x57d474,0x57eb24,0x584f22,0x584f2d,0x584f38,0x584f43,0x584f4e,0x584f59,0x584f64,0x584f6f,0x584f7a,0x584f85,0x588516,0x588da8,0x588eb1,0x588ebc,0x588ec7,0x588ed2,0x588edd,0x588ee8,0x588ef3,0x588efe,0x588f09,0x588f14,0x59551d,0x598b64,0x598b75,0x598de7,0x599307,0x59df68,0x59df70,0x59e782,0x59e7a4,0x59e7be,0x59f2e7,0x5a0678,0x5b8caa,0x5b8cb5,0x5b8cc0,0x5b9100,0x5b910b,0x5b9116,0x5ba03e,0x5bafaa,0x5bafb5,0x5bafc0,0x5bafcb,0x5bafd6,0x5bafe1,0x5bc02e,0x5bc817,0x5bd5c6,0x5bd64d,0x5be550,0x5be55b,0x5be566,0x5bf3ce,0x5c1f23,0x5c2202,0x5c22ac,0x5c22b7,0x5c2b58,0x5c2b63,0x5c2b6e,0x5c2b79,0x5c2b84}`.; outbound callee set `1/{0x4b7c50 InitRectBounds}` | Public `rename` request `{"database":"<fresh Gate 2B runtime-attested session_id>","batch":{"func":{"addr":"0x457a60","name":"EPFTileContext__EPFTileContext"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`; name only | Persisted IDB name must be `EPFTileContext__EPFTileContext`, and persisted IDB TInfo remains return `void`, arguments `{this:EPFTileContext *}`; public `inspect_items` must show symbol `EPFTileContext__EPFTileContext` and type `void __thiscall(EPFTileContext *this)`; immediate Hex-Rays pseudocode function-name/prototype must remain exact cached `void __thiscall EPFTileContext_Initialize(EPFTileContext *this)`. This exact stale header is the sole permitted immediate decompiler-name behavior; any refreshed new-name header or any other immediate Hex-Rays function-name/prototype hard-stops. Range/size/hash, F0, all four comment channels, literal inbound 337-set, and outbound one-set remain exact. Any persisted-TInfo or public-presentation delta, collision, or other non-owned delta hard-stops. |
| A02 | apply after A01 | `[0x457ab0,0x457c53)`, `0x1a3`, SHA256 `5FBE7BA516ABC1E9994570D6688BD78BF730B1CE06D7BCD19D0565E9ADD00454`; persisted IDB name `sub_457AB0`; public `inspect_items` symbol `sub_457AB0`; persisted IDB TInfo return `void *`, arguments `{this:_DWORD *}`; Hex-Rays signature `void *__thiscall sub_457AB0(_DWORD *this)`; public `inspect_items` presentation `void *__thiscall(_DWORD *this)`; frame `F1`; comments absent; inbound `6/{0x4562f3,0x499390,0x4f4e12,0x4f5207,0x4ff22d,0x4ff5ed}`; callee set `7/{0x5c7740 __alloca_probe,0x516030 GetMemoryMan,0x457c60 sub_457C60,0x5c772f @__security_check_cookie@4,0x516170 MemoryMan_FreeBufferMemory,0x516050 MemoryMan_AllocateBufferMemory,0x516220 MemoryMan_MemmoveWrapper}` | Public `rename` request `{"database":"<fresh Gate 2B runtime-attested session_id>","batch":{"func":{"addr":"0x457ab0","name":"EPFTileContext__BuildEncodedMask"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`; name only | Persisted IDB name must be `EPFTileContext__BuildEncodedMask`, and persisted IDB TInfo remains return `void *`, arguments `{this:_DWORD *}`; public `inspect_items` must show symbol `EPFTileContext__BuildEncodedMask` and type `void *__thiscall(_DWORD *this)`; immediate Hex-Rays pseudocode function-name/prototype must remain exact cached `void *__thiscall sub_457AB0(_DWORD *this)`. This exact stale header is the sole permitted immediate decompiler-name behavior; any refreshed new-name header or any other immediate Hex-Rays function-name/prototype hard-stops. Range/size/hash, F1, all four comment channels, inbound six-set, and callee seven-set remain literal exact. Any type-channel or other non-owned delta hard-stops. |
| A03 | apply after A02 | `[0x457c60,0x457df2)`, `0x192`, SHA256 `DBCD785D79AABF84234A64E9893B035EE3AB2444774E8738CCD6AEA38E9E9763`; persisted IDB name `sub_457C60`; public `inspect_items` symbol `sub_457C60`; persisted IDB TInfo return `MemoryMan *`, arguments `{this:_DWORD *}`; Hex-Rays signature `MemoryMan *__thiscall sub_457C60(_DWORD *this)`; public `inspect_items` immediate presentation is exact branch P0 `void *__thiscall(_DWORD *this)` as observed before A03 in the dated failed transaction, or exact branch P1 `MemoryMan *__thiscall(_DWORD *this)` as twice reread from the fresh canonical session; no third prestate is accepted; frame `F1`; comments absent; inbound `1/{0x457ade}` | Public `rename` request `{"database":"<fresh Gate 2B runtime-attested session_id>","batch":{"func":{"addr":"0x457c60","name":"EPFTileContext__BuildEncodedMask16"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`; name only | Persisted IDB name must be `EPFTileContext__BuildEncodedMask16`, and persisted IDB TInfo remains return `MemoryMan *`, arguments `{this:_DWORD *}`; public `inspect_items` must show symbol `EPFTileContext__BuildEncodedMask16` and type `MemoryMan *__thiscall(_DWORD *this)`; immediate Hex-Rays pseudocode function-name/prototype must remain exact cached `MemoryMan *__thiscall sub_457C60(_DWORD *this)`. This exact stale header is the sole permitted immediate decompiler-name behavior; any refreshed new-name header or any other immediate Hex-Rays function-name/prototype hard-stops. From P0, the sole permitted non-name delta is exact public presentation convergence `void *__thiscall(_DWORD *this)` -> `MemoryMan *__thiscall(_DWORD *this)`; from P1, no presentation delta is permitted. Full F1 frame, comments, xrefs, bytes/range/hash, and persisted TInfo remain unchanged. Any different presentation, any persisted-TInfo/frame delta, or any other non-owned delta hard-stops. |
| A04 | apply after A03 | `[0x457e00,0x457f2b)`, `0x12b`, SHA256 `AA747F57756F4AF01294F6BEF84F0958C06F5CB77B914E1A00FE51586FBA1DBD`; persisted IDB name `sub_457E00`; public `inspect_items` symbol `sub_457E00`; persisted IDB TInfo return `void *`, arguments `{this:void *,arg1:EPFTileContext *}`; Hex-Rays signature `void *__thiscall sub_457E00(void *this, EPFTileContext *a2)`; public `inspect_items` presentation `void *__thiscall(void *this, EPFTileContext *)`; frame `F2`; comments absent; inbound `3/{0x4d050a,0x4ff226,0x4ff5e6}`; callee set `4/{0x516030 GetMemoryMan,0x458500 EPFTileContext__ReleaseBuffers,0x516050 MemoryMan_AllocateBufferMemory,0x516220 MemoryMan_MemmoveWrapper}` | Public `rename` request `{"database":"<fresh Gate 2B runtime-attested session_id>","batch":{"func":{"addr":"0x457e00","name":"EPFTileContext__CopyTo"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`; name only | Persisted IDB name must be `EPFTileContext__CopyTo`, and persisted IDB TInfo remains return `void *`, arguments `{this:void *,arg1:EPFTileContext *}`; public `inspect_items` must show symbol `EPFTileContext__CopyTo` and type `void *__thiscall(void *this, EPFTileContext *)`; immediate Hex-Rays pseudocode function-name/prototype must remain exact cached `void *__thiscall sub_457E00(void *this, EPFTileContext *a2)`. This exact stale header is the sole permitted immediate decompiler-name behavior; any refreshed new-name header or any other immediate Hex-Rays function-name/prototype hard-stops. Preserve range/size/hash, F2, all four comment channels, inbound three-set, and callee four-set exactly. Any type-channel or other non-owned delta hard-stops. |
| A05 | no change recommended; verify after A04 and before A07 | Raw code-typed instruction sequence `[0x457f30,0x457fe9)`, size `0xb9`, SHA256 `C78A1FC8014DA9B8C0C5B9BC4388E78A7DEAAD4EE57F549C3525BAD3BC739613`; function `absent`; function range/size `absent`; name `absent`; item type `absent`; persisted IDB function TInfo `absent`; Hex-Rays function signature `absent`; public `inspect_items` function-type presentation `absent`; frame `absent`; AR `absent`; AP `absent`; FR `absent because no function entry exists`; FP `absent because no function entry exists`; inbound xrefs `0/{}`; outbound call-site set `8/{0x457f39 GetMemoryMan,0x457f48 EPFTileContext__ReleaseBuffers,0x457f7b allocate,0x457f8d memmove,0x457fa8 allocate,0x457fba memmove,0x457fca allocate,0x457fdb memmove}`. Immediate predecessor padding `[0x457f2b,0x457f30)` is size `0x5`, data-classified all-`cc`, with name/type/AR/AP/FR/FP absent; immediate successor padding `[0x457fe9,0x457ff0)` is size `0x7`, data-classified all-`cc`, with name/type/AR/AP/FR/FP absent. | No endpoint. Do not call `define_func`, `rename`, `set_type`, or any comment endpoint at `0x457f30`; owned fields none. The source-facing private name remains documentation/C++ only. | Exact unchanged readback required before A07: raw code-typed instruction sequence `[0x457f30,0x457fe9)`, size `0xb9`, SHA256 `C78A1FC8014DA9B8C0C5B9BC4388E78A7DEAAD4EE57F549C3525BAD3BC739613`; function `absent`; function range/size `absent`; name `absent`; item type `absent`; persisted IDB function TInfo `absent`; Hex-Rays function signature `absent`; public `inspect_items` function-type presentation `absent`; frame `absent`; AR `absent`; AP `absent`; FR `absent because no function entry exists`; FP `absent because no function entry exists`; inbound xrefs `0/{}`; outbound call-site set `8/{0x457f39 GetMemoryMan,0x457f48 EPFTileContext__ReleaseBuffers,0x457f7b allocate,0x457f8d memmove,0x457fa8 allocate,0x457fba memmove,0x457fca allocate,0x457fdb memmove}`; predecessor padding remains `[0x457f2b,0x457f30)`, size `0x5`, data-classified all-`cc`, name/type/AR/AP/FR/FP absent; successor padding remains `[0x457fe9,0x457ff0)`, size `0x7`, data-classified all-`cc`, name/type/AR/AP/FR/FP absent. Any function creation, function range/size, name, item type, persisted IDB function TInfo, Hex-Rays function signature, public `inspect_items` function-type presentation, frame, comment, item-model, xref/callee, byte/hash, or adjacent-padding delta hard-stops. |
| A07 | apply after exact A05 unchanged readback; A06 retired | `[0x457ff0,0x458253)`, `0x263`, SHA256 `CC2074204509B0394CC032EE61A8FAD6F327253E18B2D580725A9E131ABE575C`; persisted IDB name `sub_457FF0`; public `inspect_items` symbol `sub_457FF0`; persisted IDB TInfo return `struct RectBounds *`, arguments `{this:_DWORD *}`; Hex-Rays signature `struct RectBounds *__thiscall sub_457FF0(_DWORD *this)`; public `inspect_items` presentation `struct RectBounds *__thiscall(_DWORD *this)`; frame `F3`; comments absent; inbound `0/{}`; callee set `6/{0x516030 GetMemoryMan,0x5c74f6 ??2@YAPAXI@Z,0x4b7c50 InitRectBounds,0x4b7ca0 sub_4B7CA0,0x516050 MemoryMan_AllocateBufferMemory,0x457a60 EPFTileContext__EPFTileContext}`; associated EH set `3/{[0x5fa0c0,0x5fa0f9) SHA256 D54CA7B9F05FBD8C63C6FBD643B1A7CD8C2F747CA62A860E6CD3C0AF7E44FD63 with 0x6588fc->0x5fa0c0 and 0x5fa0ef->0x658930,[0x6588fc,0x658904) SHA256 60B6758C2F8BF70EC251A58060ABACACA1C76E1B39982AD2E4EA30C91A9C9D1A with 0x658930->0x6588fc and 0x6588fc->0x5fa0c0,[0x658930,0x658954) SHA256 6B33444714C0E044F72813218314EF58ACB1F628955C08827140997091331D3E with 0x5fa0ef->0x658930 and 0x658930->0x6588fc}` | Public `rename` request `{"database":"<fresh Gate 2B runtime-attested session_id>","batch":{"func":{"addr":"0x457ff0","name":"EPFTileContext__CreateHalfScaleCopy"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`; name only | Persisted IDB name must be `EPFTileContext__CreateHalfScaleCopy`, and persisted IDB TInfo remains return `struct RectBounds *`, arguments `{this:_DWORD *}`; public `inspect_items` must show symbol `EPFTileContext__CreateHalfScaleCopy` and type `struct RectBounds *__thiscall(_DWORD *this)`; immediate Hex-Rays pseudocode function-name/prototype must remain exact cached `struct RectBounds *__thiscall sub_457FF0(_DWORD *this)`. This exact stale header is the sole permitted immediate decompiler-name behavior; any refreshed new-name header or any other immediate Hex-Rays function-name/prototype hard-stops. Preserve primary range/size/hash, F3, all four comment channels, inbound zero-set, callee six-set including exact post-A01 pair `0x457a60 EPFTileContext__EPFTileContext`, and all three literal EH ranges/hashes/association edges exactly. Any type-channel or other non-owned delta hard-stops. |
| A08 | apply after A07 | `[0x458260,0x4583c8)`, `0x168`, SHA256 `8A6ACF0AE27C224DC5EC074F046CD8EEFD902CDC8D82963CD7A5C333EA1AC0C0`; persisted IDB name `sub_458260`; public `inspect_items` symbol `sub_458260`; persisted IDB TInfo return `struct RectBounds *`, arguments `{this:_DWORD *}`; Hex-Rays signature `struct RectBounds *__thiscall sub_458260(_DWORD *this)`; public `inspect_items` presentation `struct RectBounds *__thiscall(_DWORD *this)`; frame `F3`; comments absent; inbound `0/{}`; callee set `5/{0x516030 GetMemoryMan,0x5c74f6 ??2@YAPAXI@Z,0x4b7c50 InitRectBounds,0x4b7ca0 sub_4B7CA0,0x516050 MemoryMan_AllocateBufferMemory}`; associated EH set `3/{[0x5fa0f9,0x5fa123) SHA256 EFA719E782BB9489BD7748EE2DCDF28722ABB30DC1405283BB4FEE5024B28993 with 0x6588f4->0x5fa0f9 and 0x5fa119->0x65890c,[0x6588f4,0x6588fc) SHA256 BC8B2E447709C97A840CBAE0E85EB8C3BC1F4F03DA63459D06390BC04BD43231 with 0x65890c->0x6588f4 and 0x6588f4->0x5fa0f9,[0x65890c,0x658930) SHA256 DF2190CD95860A9C3E4EF7B0D5DD136ECD076E34BF53C9C37A437A6093832B5B with 0x5fa119->0x65890c and 0x65890c->0x6588f4}` | Public `rename` request `{"database":"<fresh Gate 2B runtime-attested session_id>","batch":{"func":{"addr":"0x458260","name":"EPFTileContext__CreateHalfScaleRgb16Copy"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`; name only | Persisted IDB name must be `EPFTileContext__CreateHalfScaleRgb16Copy`, and persisted IDB TInfo remains return `struct RectBounds *`, arguments `{this:_DWORD *}`; public `inspect_items` must show symbol `EPFTileContext__CreateHalfScaleRgb16Copy` and type `struct RectBounds *__thiscall(_DWORD *this)`; immediate Hex-Rays pseudocode function-name/prototype must remain exact cached `struct RectBounds *__thiscall sub_458260(_DWORD *this)`. This exact stale header is the sole permitted immediate decompiler-name behavior; any refreshed new-name header or any other immediate Hex-Rays function-name/prototype hard-stops. Preserve primary range/size/hash, F3, all four comment channels, inbound zero-set, callee five-set, and all three literal EH ranges/hashes/association edges exactly. Any type-channel or other non-owned delta hard-stops. |
| A09 | apply after A08 | `[0x4583d0,0x458423)`, `0x53`, SHA256 `E0AE18244D060264808E5E4AB089B168BAF4397C206F39DF8093F77A19B30871`; persisted IDB name `sub_4583D0`; public `inspect_items` symbol `sub_4583D0`; persisted IDB TInfo return `void *`, arguments `{this:EPFTileContext *,arg1:int,arg2:int}`; Hex-Rays signature `void *__thiscall sub_4583D0(EPFTileContext *this, int a2, int a3)`; public `inspect_items` presentation `void *__thiscall(EPFTileContext *this, int, int)`; frame `F4`; comments absent; inbound `1/{0x4d0a16}` | Public `rename` request `{"database":"<fresh Gate 2B runtime-attested session_id>","batch":{"func":{"addr":"0x4583d0","name":"EPFTileContext__AllocateIndexed8Pixels"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`; name only | Persisted IDB name must be `EPFTileContext__AllocateIndexed8Pixels`, and persisted IDB TInfo remains return `void *`, arguments `{this:EPFTileContext *,arg1:int,arg2:int}`; public `inspect_items` must show symbol `EPFTileContext__AllocateIndexed8Pixels` and type `void *__thiscall(EPFTileContext *this, int, int)`; immediate Hex-Rays pseudocode function-name/prototype must remain exact cached `void *__thiscall sub_4583D0(EPFTileContext *this, int a2, int a3)`. This exact stale header is the sole permitted immediate decompiler-name behavior; any refreshed new-name header or any other immediate Hex-Rays function-name/prototype hard-stops. F4, comments, inbound one-set, bytes/range/hash, and every other field remain exact; any type-channel or other non-owned delta hard-stops. |
| A10 | apply after A09 | `[0x458430,0x458485)`, `0x55`, SHA256 `86A23FA30DCA5D4F5BC07E5EAFE337E96056F4D7688D9DEEBA91ED15225FE428`; persisted IDB name `sub_458430`; public `inspect_items` symbol `sub_458430`; persisted IDB TInfo return `void *`, arguments `{this:EPFTileContext *,arg1:int,arg2:int}`; Hex-Rays signature `void *__thiscall sub_458430(EPFTileContext *this, int a2, int a3)`; public `inspect_items` presentation `void *__thiscall(EPFTileContext *this, int, int)`; frame `F4`; comments absent; inbound `4/{0x4d06c8,0x4d076d,0x4d08ad,0x4d0b65}` | Public `rename` request `{"database":"<fresh Gate 2B runtime-attested session_id>","batch":{"func":{"addr":"0x458430","name":"EPFTileContext__AllocateRgb16Pixels"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`; name only | Persisted IDB name must be `EPFTileContext__AllocateRgb16Pixels`, and persisted IDB TInfo remains return `void *`, arguments `{this:EPFTileContext *,arg1:int,arg2:int}`; public `inspect_items` must show symbol `EPFTileContext__AllocateRgb16Pixels` and type `void *__thiscall(EPFTileContext *this, int, int)`; immediate Hex-Rays pseudocode function-name/prototype must remain exact cached `void *__thiscall sub_458430(EPFTileContext *this, int a2, int a3)`. This exact stale header is the sole permitted immediate decompiler-name behavior; any refreshed new-name header or any other immediate Hex-Rays function-name/prototype hard-stops. F4, comments, inbound four-set, bytes/range/hash, and every other field remain exact; any type-channel or other non-owned delta hard-stops. |
| A11 | apply after A10 | `[0x458490,0x4584fa)`, `0x6a`, SHA256 `45906CB674812FDF7DB1FC15FD5A746B0335D1949C869086061E798DF3B8A382`; persisted IDB name `sub_458490`; public `inspect_items` symbol `sub_458490`; persisted IDB TInfo return `unsigned __int16 *`, arguments `{this:EPFTileContext *,arg1:int,arg2:int}`; Hex-Rays signature `unsigned __int16 *__thiscall sub_458490(EPFTileContext *this, int a2, int a3)`; public `inspect_items` presentation `unsigned __int16 *__thiscall(EPFTileContext *this, int, int)`; frame `F5`; comments absent; inbound `2/{0x4d0c9e,0x4d0e34}` | Public `rename` request `{"database":"<fresh Gate 2B runtime-attested session_id>","batch":{"func":{"addr":"0x458490","name":"EPFTileContext__AllocateRgb16PixelsWithAlpha"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`; name only | Persisted IDB name must be `EPFTileContext__AllocateRgb16PixelsWithAlpha`, and persisted IDB TInfo remains return `unsigned __int16 *`, arguments `{this:EPFTileContext *,arg1:int,arg2:int}`; public `inspect_items` must show symbol `EPFTileContext__AllocateRgb16PixelsWithAlpha` and type `unsigned __int16 *__thiscall(EPFTileContext *this, int, int)`; immediate Hex-Rays pseudocode function-name/prototype must remain exact cached `unsigned __int16 *__thiscall sub_458490(EPFTileContext *this, int a2, int a3)`. This exact stale header is the sole permitted immediate decompiler-name behavior; any refreshed new-name header or any other immediate Hex-Rays function-name/prototype hard-stops. F5, comments, inbound two-set, bytes/range/hash, and every other field remain exact; any type-channel or other non-owned delta hard-stops. |
| A12 | apply after A11 | `[0x458560,0x458585)`, `0x25`, SHA256 `82FE00C34B29A32321FDF197E2BE5B34A8AC504AC1EDD203D62B930DF873C0C2`; persisted IDB name `sub_458560`; public `inspect_items` symbol `sub_458560`; persisted IDB TInfo return `void`, arguments `{this:int}`; Hex-Rays signature `void __thiscall sub_458560(int this)`; public `inspect_items` presentation `void __thiscall(int this)`; frame `F6`; comments absent; inbound `6/{0x4d06f2,0x4d079a,0x4d0991,0x4d0c42,0x4d0d7d,0x4d0f29}`; one data read `0x69b3d5` | Public `rename` request `{"database":"<fresh Gate 2B runtime-attested session_id>","batch":{"func":{"addr":"0x458560","name":"EPFTileContext__NormalizePostDecodePixels"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`; name only | Persisted IDB name must be `EPFTileContext__NormalizePostDecodePixels`, and persisted IDB TInfo remains return `void`, arguments `{this:int}`; public `inspect_items` must show symbol `EPFTileContext__NormalizePostDecodePixels` and type `void __thiscall(int this)`; immediate Hex-Rays pseudocode function-name/prototype must remain exact cached `void __thiscall sub_458560(int this)`. This exact stale header is the sole permitted immediate decompiler-name behavior; any refreshed new-name header or any other immediate Hex-Rays function-name/prototype hard-stops. Preserve F6, comments, inbound six-set, data read `0x69b3d5`, code refs, bytes/range/hash, and every other field; any type-channel or other non-owned delta hard-stops. |
| A13 | apply after A12 | `[0x458590,0x458610)`, `0x80`, SHA256 `AFEBBA908F921BB7AE1E9AB155307238634D69811A237B138CAB1E01CAC48431`; persisted IDB name `sub_458590`; public `inspect_items` symbol `sub_458590`; persisted IDB TInfo return `char`, arguments `{this:_DWORD *,arg1:int}`; Hex-Rays signature `char __thiscall sub_458590(_DWORD *this, int a2)`; public `inspect_items` presentation `char __thiscall(_DWORD *this, int)`; frame `F7`; comments absent; inbound `2/{0x4df70c,0x4df7aa}`; callee set `0/{}` | Public `rename` request `{"database":"<fresh Gate 2B runtime-attested session_id>","batch":{"func":{"addr":"0x458590","name":"EPFTileContext__ContainsIndexedPixelInRanges"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`; name only | Persisted IDB name must be `EPFTileContext__ContainsIndexedPixelInRanges`, and persisted IDB TInfo remains return `char`, arguments `{this:_DWORD *,arg1:int}`; public `inspect_items` must show symbol `EPFTileContext__ContainsIndexedPixelInRanges` and type `char __thiscall(_DWORD *this, int)`; immediate Hex-Rays pseudocode function-name/prototype must remain exact cached `char __thiscall sub_458590(_DWORD *this, int a2)`. This exact stale header is the sole permitted immediate decompiler-name behavior; any refreshed new-name header or any other immediate Hex-Rays function-name/prototype hard-stops. Preserve F7, comments, inbound two-set, zero callee-set, bytes/range/hash, and every other field; any type-channel or other non-owned delta hard-stops. |

Every action row carries its complete SHA256 and literal prestate plus three separately enforceable poststates: persisted IDB symbol/TInfo, public `inspect_items` symbol/type, and immediate cached Hex-Rays function-name/prototype. Supervisor readback must compare every complete value before and after each endpoint; the exact stale immediate Hex-Rays header is permitted, but neither a refreshed new-name header nor any third presentation is accepted at that endpoint.

A06 is retired and absent from the action table. Because A05 deliberately preserves `0x457f30` as raw code with function/name/type/frame absent, no public function-rename endpoint is valid there. A06 has no mutation, owned field, or post-mutation discovery step; the complete literal A05 unchanged readback is the required state immediately before A07.

### Protection and no-operation rows

| ID | Classification | Literal current and expected unchanged state | Hard stop |
| --- | --- | --- | --- |
| P01 | no change recommended | `[0x458500,0x458557)`, size `0x57`, SHA256 `D9E6BBB2C4B27E099244C52ABA980D8C165018FEC4E91028CCDDF96C5950C5FF`; name `EPFTileContext__ReleaseBuffers`; type `void *__thiscall(EPFTileContext *this)`; frame `{__return_address +0x8/4/_UNKNOWN *}`; AR absent; AP absent; FR exact `Releases EPFTileContext pixel, alpha, and encoded-mask buffers and clears the associated pointers/count. Shared render-support method; not LogoPane-owned.`; FP absent; inbound `71` with literal set `{0x45403b,0x456082,0x456359,0x457e27,0x457e8e,0x457f48,0x4583d8,0x458438,0x45849c,0x4992f2,0x49b1f9,0x49daad,0x49dba2,0x4b608f,0x4b8d97,0x4b8e7b,0x4bb85e,0x4d061d,0x4d0698,0x4d073a,0x4d09bc,0x4f4cce,0x4f4ef6,0x4f50c0,0x4f534d,0x4f6967,0x4ff2d5,0x4ff695,0x5028ae,0x502bac,0x502c5c,0x50689a,0x520800,0x5852cd,0x5852d8,0x5852e3,0x5852ee,0x5852f9,0x585304,0x58530f,0x58531a,0x585325,0x585330,0x589211,0x58921c,0x589227,0x589232,0x58923d,0x589248,0x589253,0x58925e,0x589269,0x589274,0x58ae4d,0x58ae58,0x58ae63,0x58ae6e,0x58ae79,0x58ae84,0x58ae8f,0x58ae9a,0x58aea5,0x58aeb0,0x59e8f2,0x59e912,0x59e925,0x59f1e5,0x59f202,0x59f215,0x59f5c4,0x5a24bb}`.; callee set `2/{0x516030 GetMemoryMan,0x516170 MemoryMan_FreeBufferMemory}`. Permitted delta none. | Any field, body, comment, xref/callee, byte/hash, item, or boundary change. |
| P02 | no change recommended | Twelve exact data-classified all-`cc` items: `457aa4-ab0/12`, `457c53-c60/13`, `457df2-e00/14`, `457f2b-f30/5`, `457fe9-ff0/7`, `458253-260/13`, `4583c8-3d0/8`, `458423-430/13`, `458485-490/11`, `4584fa-500/6`, `458557-560/9`, `458585-590/11`; every name/type/comment channel absent and permitted delta none. | Any byte/item/boundary/name/type/comment change or action overlap. |
| P03 | no change recommended | Six literal EH items, each with AR/AP/FR/FP absent and permitted delta none: chunk `[0x5fa0c0,0x5fa0f9)`, size `0x39`, SHA256 `D54CA7B9F05FBD8C63C6FBD643B1A7CD8C2F747CA62A860E6CD3C0AF7E44FD63`, associated with `0x457ff0`, incoming `0x6588fc->0x5fa0c0`, calls `0x5fa0c6/0x5fa0d5->0x5c7526`, `0x5fa0ea->0x5c772f`, data `0x5fa0ef->0x658930`, tail `0x5fa0f4->0x5c956c`; chunk `[0x5fa0f9,0x5fa123)`, size `0x2a`, SHA256 `EFA719E782BB9489BD7748EE2DCDF28722ABB30DC1405283BB4FEE5024B28993`, associated with `0x458260`, incoming `0x6588f4->0x5fa0f9`, calls `0x5fa0ff->0x5c7526`, `0x5fa114->0x5c772f`, data `0x5fa119->0x65890c`, tail `0x5fa11e->0x5c956c`; record `stru_6588F4` `[0x6588f4,0x6588fc)`, size `0x8`, SHA256 `BC8B2E447709C97A840CBAE0E85EB8C3BC1F4F03DA63459D06390BC04BD43231`, edges `0x65890c->0x6588f4->0x5fa0f9`; record `stru_6588FC` `[0x6588fc,0x658904)`, size `0x8`, SHA256 `60B6758C2F8BF70EC251A58060ABACACA1C76E1B39982AD2E4EA30C91A9C9D1A`, edges `0x658930->0x6588fc->0x5fa0c0`; record `stru_65890C` `[0x65890c,0x658930)`, size `0x24`, SHA256 `DF2190CD95860A9C3E4EF7B0D5DD136ECD076E34BF53C9C37A437A6093832B5B`, edges `0x5fa119->0x65890c->0x6588f4`; record `stru_658930` `[0x658930,0x658954)`, size `0x24`, SHA256 `6B33444714C0E044F72813218314EF58ACB1F628955C08827140997091331D3E`, edges `0x5fa0ef->0x658930->0x6588fc`. | Any chunk association, byte/hash, xref, name, item, boundary, or comment delta. |
| P04 | no change recommended | `EPFTileContext` 40-byte seven-member layout, four-byte `EPFTilePixelFormat`, 16-byte `RectBounds`, 556-byte current IDA `DLPalette`, and literal absent `DLPaletteRange` remain exact. | No `declare_type`, `type_apply_batch`, member rename, fake range UDT, enum edit, or layout change. |
| P05 | no change recommended | Predecessor `[0x457960,0x457a5d)` `sub_457960`, type `void __thiscall(_DWORD *ArgList,int,int)`, size `0xfd`, SHA256 `0A174633BFE5BC1DB5A5045FA762452D076E2F6E98D481551FB365EE7F0176F3`, comments at entry absent, inbound `2/{0x4577e0,0x457936}`; boundary `[0x457a5d,0x457a60)` bytes `cc cc cc` hash `E668F0A1B72560CED14C54488A25335D11336448950BB6485267EBC5EB3FECEE` comments absent; successor `[0x458610,0x45894b)` `sub_458610`, type `DialogPane *__thiscall(DialogPane *this)`, size `0x33b`, SHA256 `25213C01BC5FBF1F77B109FACF197719CB5728AFFF7815D2097524E78E5063CD`, entry comments absent, inbound `1/{0x5bd2ab}`. Permitted delta none. | Any predecessor/padding/successor field, byte, range, xref, or comment delta. |

Ordered contract: attest a fresh session and exact prestate; verify P01-P05; populate and record each exact prestate decompiler header; apply/read A01-A04, comparing the new persisted/public symbol, protected persisted/public type, and exact cached pre-rename immediate Hex-Rays header after each name endpoint, including A03's exact P0/P1 public-type convergence rule; verify A05's complete literal unchanged raw-code state across all three absent channels; invoke no A06 endpoint; apply/read A07-A13 one at a time with the same separated symbol/type/decompiler checks. Reread every authored body, persisted TInfo, immediate Hex-Rays header, public `inspect_items` symbol/type, full frame where a function exists, complete xref set, P01-P05, all bytes/hashes, item models, and comments before any supervisor save decision. The only persisted IDB deltas are the eleven A01-A04/A07-A13 function names; public `inspect_items` must expose those names, each immediate Hex-Rays header must remain the literal cached old-name header in its row, and the sole additional permitted readback delta is A03 P0 public presentation convergence from `void *__thiscall(_DWORD *this)` to `MemoryMan *__thiscall(_DWORD *this)`. A07's callee set is the public structural identity set and therefore must contain `0x457a60 EPFTileContext__EPFTileContext`; any stale textual callee label inside cached pseudocode is presentation-only and cannot substitute for that structural readback.

## First-Draft C++ Recommendation

Eligible: all thirteen authored bodies. UID0000XY owns eleven definitions; UID000200/UID000201 keep their current exact definitions. Six EH items and twelve padding intervals are compiler-covered/no-code.

### UID00004I formal CPP

```cpp
#include "EPFTileContext.h"
#include "Palette.h"
#include "SoftwareBlend16.h"
#include "Surface.h"
#include "../util/MemoryMan.h"

[[CHILDREN]]
```

### UID0000XY formal CPP

```cpp
EPFTileContext::EPFTileContext()
{
    pixelFormat = kEPFTilePixelFormatIndexed8;
    pixelData = NULL;
    alphaData = NULL;
    rowStridePixels = 0;
    InitRectBounds(&bounds, 0, 0, 0, 0);
    encodedMaskByteCount = 0;
    encodedMaskBytes = NULL;
}

void EPFTileContext::BuildEncodedMask()
{
    if (pixelFormat == kEPFTilePixelFormatRgb16) {
        BuildEncodedMask16();
        return;
    }

    MemoryMan *memoryMan = GetMemoryMan();

    if (encodedMaskBytes != NULL) {
        encodedMaskByteCount = 0;
        encodedMaskBytes = static_cast<unsigned char *>(
            memoryMan->FreeBufferMemory(encodedMaskBytes));
    }

    unsigned char *rowPixels = static_cast<unsigned char *>(pixelData);
    if (rowPixels == NULL) {
        return;
    }

    unsigned char encodedMask[100000];
    unsigned char *output = encodedMask;
    const int width = bounds.right - bounds.left;

    for (int row = bounds.top; row < bounds.bottom; ++row) {
        unsigned char runLength = 1;
        bool transparent = rowPixels[0] == 0;

        for (int column = 1; column < width; ++column) {
            const bool nextTransparent = rowPixels[column] == 0;

            if (transparent == nextTransparent) {
                ++runLength;
                if (runLength != 127) {
                    continue;
                }
            }

            *output++ = static_cast<unsigned char>(
                runLength | (transparent ? 0 : 0x80));
            ++encodedMaskByteCount;
            runLength = 1;
            transparent = nextTransparent;
        }

        *output++ = static_cast<unsigned char>(
            runLength | (transparent ? 0 : 0x80));
        *output++ = 0;
        encodedMaskByteCount += 2;
        rowPixels += rowStridePixels;
    }

    encodedMaskBytes = static_cast<unsigned char *>(
        memoryMan->AllocateBufferMemory(encodedMaskByteCount));
    memoryMan->MemmoveWrapper(
        encodedMaskBytes, encodedMask, encodedMaskByteCount);
}

void EPFTileContext::BuildEncodedMask16()
{
    MemoryMan *memoryMan = GetMemoryMan();

    if (encodedMaskBytes != NULL) {
        encodedMaskByteCount = 0;
        encodedMaskBytes = static_cast<unsigned char *>(
            memoryMan->FreeBufferMemory(encodedMaskBytes));
    }

    unsigned short *rowPixels = static_cast<unsigned short *>(pixelData);
    if (rowPixels == NULL) {
        return;
    }

    unsigned char encodedMask[100000];
    unsigned char *output = encodedMask;
    const int width = bounds.right - bounds.left;

    for (int row = bounds.top; row < bounds.bottom; ++row) {
        unsigned char runLength = 1;
        bool transparent = rowPixels[0] == 0;

        for (int column = 1; column < width; ++column) {
            const bool nextTransparent = rowPixels[column] == 0;

            if (transparent == nextTransparent) {
                ++runLength;
                if (runLength != 127) {
                    continue;
                }
            }

            *output++ = static_cast<unsigned char>(
                runLength | (transparent ? 0 : 0x80));
            ++encodedMaskByteCount;
            runLength = 1;
            transparent = nextTransparent;
        }

        *output++ = static_cast<unsigned char>(
            runLength | (transparent ? 0 : 0x80));
        *output++ = 0;
        encodedMaskByteCount += 2;
        rowPixels += rowStridePixels;
    }

    encodedMaskBytes = static_cast<unsigned char *>(
        memoryMan->AllocateBufferMemory(encodedMaskByteCount));
    memoryMan->MemmoveWrapper(
        encodedMaskBytes, encodedMask, encodedMaskByteCount);
}

void EPFTileContext::CopyTo(EPFTileContext *destination) const
{
    if (pixelFormat == kEPFTilePixelFormatRgb16) {
        CopyRgb16To(destination);
        return;
    }

    MemoryMan *memoryMan = GetMemoryMan();
    destination->ReleaseBuffers();
    memoryMan->MemmoveWrapper(destination, this, sizeof(*this));

    const int byteCount =
        rowStridePixels * (bounds.bottom - bounds.top);

    if (pixelData != NULL) {
        destination->pixelData =
            memoryMan->AllocateBufferMemory(byteCount);
        memoryMan->MemmoveWrapper(
            destination->pixelData, pixelData, byteCount);
    }

    if (alphaData != NULL) {
        destination->alphaData = static_cast<unsigned short *>(
            memoryMan->AllocateBufferMemory(byteCount));
        memoryMan->MemmoveWrapper(
            destination->alphaData, alphaData, byteCount);
    }

    if (encodedMaskBytes != NULL) {
        destination->encodedMaskBytes = static_cast<unsigned char *>(
            memoryMan->AllocateBufferMemory(encodedMaskByteCount));
        memoryMan->MemmoveWrapper(
            destination->encodedMaskBytes,
            encodedMaskBytes,
            encodedMaskByteCount);
    }
}

void EPFTileContext::CopyRgb16To(EPFTileContext *destination) const
{
    MemoryMan *memoryMan = GetMemoryMan();
    destination->ReleaseBuffers();
    memoryMan->MemmoveWrapper(destination, this, sizeof(*this));

    const int byteCount =
        2 * rowStridePixels * (bounds.bottom - bounds.top);

    if (pixelData != NULL) {
        destination->pixelData =
            memoryMan->AllocateBufferMemory(byteCount);
        memoryMan->MemmoveWrapper(
            destination->pixelData, pixelData, byteCount);
    }

    if (alphaData != NULL) {
        destination->alphaData = static_cast<unsigned short *>(
            memoryMan->AllocateBufferMemory(byteCount));
        memoryMan->MemmoveWrapper(
            destination->alphaData, alphaData, byteCount);
    }

    if (encodedMaskBytes != NULL) {
        destination->encodedMaskBytes = static_cast<unsigned char *>(
            memoryMan->AllocateBufferMemory(encodedMaskByteCount));
        memoryMan->MemmoveWrapper(
            destination->encodedMaskBytes,
            encodedMaskBytes,
            encodedMaskByteCount);
    }
}

EPFTileContext *EPFTileContext::CreateHalfScaleCopy() const
{
    if (pixelFormat == kEPFTilePixelFormatRgb16) {
        return CreateHalfScaleRgb16Copy();
    }

    MemoryMan *memoryMan = GetMemoryMan();
    EPFTileContext *copy = new EPFTileContext;

    copy->bounds.left = bounds.left / 2;
    copy->bounds.top = bounds.top / 2;
    copy->bounds.right =
        copy->bounds.left + (bounds.right - bounds.left) / 2;
    copy->bounds.bottom =
        copy->bounds.top + (bounds.bottom - bounds.top) / 2;
    copy->rowStridePixels = copy->bounds.right - copy->bounds.left;
    copy->pixelData = memoryMan->AllocateBufferMemory(
        RectArea(&copy->bounds));

    const unsigned char *sourceRow =
        static_cast<const unsigned char *>(pixelData);
    unsigned char *destination =
        static_cast<unsigned char *>(copy->pixelData);

    for (int row = copy->bounds.top;
         row < copy->bounds.bottom;
         ++row) {
        const unsigned char *source = sourceRow;
        for (int column = copy->bounds.left;
             column < copy->bounds.right;
             ++column) {
            *destination++ = *source;
            source += 2;
        }
        sourceRow += 2 * rowStridePixels;
    }

    return copy;
}

EPFTileContext *EPFTileContext::CreateHalfScaleRgb16Copy() const
{
    MemoryMan *memoryMan = GetMemoryMan();
    EPFTileContext *copy = new EPFTileContext;

    copy->bounds.left = bounds.left / 2;
    copy->bounds.top = bounds.top / 2;
    copy->bounds.right =
        copy->bounds.left + (bounds.right - bounds.left) / 2;
    copy->bounds.bottom =
        copy->bounds.top + (bounds.bottom - bounds.top) / 2;
    copy->rowStridePixels = copy->bounds.right - copy->bounds.left;
    copy->pixelData = memoryMan->AllocateBufferMemory(
        2 * RectArea(&copy->bounds));

    const unsigned short *sourceRow =
        static_cast<const unsigned short *>(pixelData);
    unsigned short *destination =
        static_cast<unsigned short *>(copy->pixelData);

    for (int row = copy->bounds.top;
         row < copy->bounds.bottom;
         ++row) {
        const unsigned short *source = sourceRow;
        for (int column = copy->bounds.left;
             column < copy->bounds.right;
             ++column) {
            *destination++ = *source;
            source += 2;
        }
        sourceRow += 2 * rowStridePixels;
    }

    return copy;
}

void EPFTileContext::AllocateIndexed8Pixels(int width, int height)
{
    ReleaseBuffers();
    pixelFormat = kEPFTilePixelFormatIndexed8;
    pixelData = GetMemoryMan()->AllocateBufferMemory(width * height);
    bounds.left = 0;
    bounds.top = 0;
    bounds.right = width;
    bounds.bottom = height;
    rowStridePixels = width;
    alphaData = NULL;
}

void EPFTileContext::AllocateRgb16Pixels(int width, int height)
{
    ReleaseBuffers();
    pixelFormat = kEPFTilePixelFormatRgb16;
    pixelData = GetMemoryMan()->AllocateBufferMemory(
        2 * width * height);
    bounds.left = 0;
    bounds.top = 0;
    bounds.right = width;
    bounds.bottom = height;
    rowStridePixels = width;
    alphaData = NULL;
}

void EPFTileContext::AllocateRgb16PixelsWithAlpha(
    int width, int height)
{
    ReleaseBuffers();
    pixelFormat = kEPFTilePixelFormatRgb16;

    const int byteCount = 2 * width * height;
    pixelData = GetMemoryMan()->AllocateBufferMemory(byteCount);
    alphaData = static_cast<unsigned short *>(
        GetMemoryMan()->AllocateBufferMemory(byteCount));

    bounds.left = 0;
    bounds.top = 0;
    bounds.right = width;
    bounds.bottom = height;
    rowStridePixels = width;
}

void EPFTileContext::ReleaseBuffers()
{
    MemoryMan *memoryMan = GetMemoryMan();

    if (pixelData != NULL) {
        pixelData = memoryMan->FreeBufferMemory(pixelData);
    }

    if (alphaData != NULL) {
        alphaData = static_cast<unsigned short *>(
            memoryMan->FreeBufferMemory(alphaData));
    }

    if (encodedMaskBytes != NULL) {
        encodedMaskByteCount = 0;
        encodedMaskBytes = static_cast<unsigned char *>(
            memoryMan->FreeBufferMemory(encodedMaskBytes));
    }
}
```

### UID000200 formal CPP, preserved exact

```cpp
void EPFTileContext::NormalizePostDecodePixels()
{
    if (!g_surfaceUsesRgb565Pixels) {
        ConvertRgb565ToRgb555Pixels(
            static_cast<unsigned short*>(pixelData),
            (bounds.right - bounds.left) * (bounds.bottom - bounds.top));
    }
}
```

### UID000201 formal CPP, preserved exact

```cpp
bool EPFTileContext::ContainsIndexedPixelInRanges(const DLPalette *palette) const
{
    if (pixelFormat == kEPFTilePixelFormatRgb16) {
        return false;
    }

    const int rowCount = bounds.bottom - bounds.top;
    const int pixelsPerRow = rowStridePixels;
    const unsigned char *rowPixels = static_cast<const unsigned char *>(pixelData);
    const DLPaletteRange *ranges = palette->m_paletteRanges;
    const int rangeCount = palette->m_paletteRangeCount;

    for (int row = 0; row < rowCount; ++row) {
        for (int column = 0; column < pixelsPerRow; ++column) {
            const unsigned char pixel = rowPixels[column];

            for (int rangeIndex = 0; rangeIndex < rangeCount; ++rangeIndex) {
                const unsigned char rangeStart = ranges[rangeIndex].firstIndex;
                const unsigned char rangeEnd = ranges[rangeIndex].lastIndex;

                if (rangeStart <= pixel && pixel <= rangeEnd) {
                    return true;
                }
            }
        }

        rowPixels += pixelsPerRow;
    }

    return false;
}
```

### UID00004I formal H

```h
#pragma once

#include "../ui/core/RectBounds.h"

enum EPFTilePixelFormat
{
    kEPFTilePixelFormatRgb16 = 0,
    kEPFTilePixelFormatIndexed8 = 1
};

struct DLPalette;

struct EPFTileContext
{
    EPFTilePixelFormat pixelFormat;
    void *pixelData;
    unsigned short *alphaData;
    int rowStridePixels;
    RectBounds bounds;
    int encodedMaskByteCount;
    unsigned char *encodedMaskBytes;

    EPFTileContext();

    void ReleaseBuffers();
    void BuildEncodedMask();
    void CopyTo(EPFTileContext *destination) const;
    EPFTileContext *CreateHalfScaleCopy() const;
    void AllocateIndexed8Pixels(int width, int height);
    void AllocateRgb16Pixels(int width, int height);
    void AllocateRgb16PixelsWithAlpha(int width, int height);
    void NormalizePostDecodePixels();
    bool ContainsIndexedPixelInRanges(const DLPalette *palette) const;

private:
    void BuildEncodedMask16();
    void CopyRgb16To(EPFTileContext *destination) const;
    EPFTileContext *CreateHalfScaleRgb16Copy() const;
};
```

### UID00015T formal H

```h
int RectArea(const RectBounds *bounds);
```

### UID0003ZP formal H

```h
void ConvertRgb565ToRgb555Pixels(unsigned short* pixels, int pixelCount);
```

### UID00029U formal H

```h
extern bool g_surfaceUsesRgb565Pixels;
```

Behavior preservation: the source retains the fixed 100000-byte mask scratch, 127-byte run cap, zero row terminators, conditional count reset, 40-byte header copy, size/signed arithmetic, lack of guards, explicit ownership release, constructor-default format quirk in RGB16 half-scale copies, and exact normalization/range-query behavior. It uses plausible VC6-era classes, raw pointers, `NULL`, explicit MemoryMan calls, and descriptive names rather than decompiler temporaries.

## Final Recommendation

- Preserve the physically applied Section 22 class CPP/H, aggregate CPP, and three dependency H payloads.
- Preserve UID000200/UID000201 bodies byte-for-text and the implemented aggregate/child positions `0/10/20`.
- Preserve removal of the 94 stale `.Initialize()` calls and correction of only dependent prose in the 64 exact consumers; automatic/default/member construction supplies the observed constructor call.
- Retain existing owner/emitter/reconstructable paths and implemented scores; the exact tail child scores remain unchanged.
- Apply only the eleven staged pure IDA renames A01-A04/A07-A13 through their literal public `rename` requests, each with top-level `database` and exact `batch.func`, `pure:true`, `allow_overwrite:false`, `dry_run:false`, and `stop_on_error:true` fields. Preserve A05's raw/no-function state exactly and invoke no A06 endpoint. Read and enforce each row's exact new persisted/public symbol, unchanged persisted/public type, and exact cached old-name immediate Hex-Rays function header; A03 P0 alone may converge publicly from `void *` to `MemoryMan *`, while persisted TInfo remains unchanged. A refreshed immediate decompiler header, any different prototype, and every other type/non-owned delta hard-stop. Do not mutate function boundaries, item models, function types, comments, UDTs, EH items, padding, bytes, or neighbors.
- No item remains no-owner/non-emitting except compiler-covered EH/padding, which intentionally has no authored source.
- No future research blocker remains. Original private spellings are documented descriptive uncertainty rather than deferred work.

## Recommended Target Doc Changes

- Target path: `by-file/EPFTileContext.md`.
- Dated callback result: the twelve-body/retained-policy narrative was replaced with the 13-body inventory, constructor/no-destructor proof, three retained-helper liveness resolutions, exact source order, dependency/header topology, generated defect/readback contract, and score `94/94`.
- Preserve path `NexusTK/render/` and owner `FILE`.
- Useful historical B004/B005 evidence was preserved, while the old blank-aggregate and no-route blocker conclusions remain dated history.
- Pre-callback and post-callback hashes/command metadata are dated receipts; gate-time current generated truth remains subject to physical reread.

## Recommended Support Doc Changes

Core support destinations, with the snapshot column explicitly dated pre-callback and the exact change column physically applied during this callback:

| Path | Current snapshot / metadata | Exact change |
| --- | --- | --- |
| `by-class/EPFTileContext.md` | SHA256 `22900C0A31570AF51EF310C32D085D9A82806FC0DD849253C17B28C8DE67856F`; `88/90` | Exact Section 22 class CPP/H; `94/94`; constructor/no-destructor/helper/source-order/full-inventory prose. |
| `by-memory/0x00457a60-0x00458610.EPFTileContext.md` | `759B674505E1C022729AD03D7B5C958E0353D8239F526CA08236F6DB373E7232`; `88/91` | Exact aggregate CPP; position `0`; `94/94`; 13-body/hash/EH/padding/source-liveness details. |
| `by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md` | `48A9ECEF8D6C90F1F3DE37E98703C6D73F89F018828F7DEF588F671241D3EF36`; `92/94` | Preserve body/score; set position `10`; record dependency preamble. |
| `by-memory/0x00458590-0x00458610.EPFTileContextPixelRangeTest.md` | `4873030FA5AFAAEDF8AF4993B86622E1909304CFC0FD040C939A8C4B68022D55`; `89/92` | Preserve body/score; set position `20`; preserve Palette friendship. |
| `by-memory/0x004b7ca0-0x004b7cb6.RectArea.md` | `B9CB401947F061F650269750270A657108D25681FA61D0805DBBD7CDEAD9D693`; `86/90` | Add exact H declaration; `88/92`; add two EPFTileContext half-scale caller uses and header closure. |
| `by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md` | `F0C0EB0AC073AF0D9DE70BD9CB12F336FCE23DFA7E327BC668B963697430A798`; `92/94` | Add exact H declaration; `93/95`; preserve exact `0x7ff0` behavior. |
| `by-memory/0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags.md` | `8C38EE98CC1A9B6AC5B6C22BCE1989AC71CB6CCA6D9549628503474A4C0025C6`; `88/93` | Add only `extern bool g_surfaceUsesRgb565Pixels;` to H; `90/94`; keep 32-bit flag file-static. |
| `by-file/RectBounds.md` | `AA20CBBCF7969A5507C46378B2057522910C562B287A795254287A70D6E5C68C`; `90/85` | Record child H declaration and EPFTileContext dependency; score unchanged. |
| `by-file/SoftwareBlend16.md` | `CF8E195C7B7C6204A47484AD5B930336D2674B251248B660CCE0785BE75FB499`; `90/92` | Record child H declaration and EPFTileContext consumer; score unchanged. |
| `by-file/Surface.md` | `5EFC71B47B170DB5ACB121BFB0BA53F217C37164C4F2C1720BF416F82B74E5D0`; `90/89` | Record exported RGB565 flag declaration/consumer; score unchanged. |

Exact constructor-consumer manifest. For every row, remove every listed expression from formal CPP and correct nearby prose that calls `0x457a60` an ordinary explicit initialization method. Preserve all other code, scores, metadata, and research.

| Claim | UID | Exact path | Stale formal calls to remove | Pre-callback SHA256 |
| --- | --- | --- | --- | --- |
| C030 | 0002DL | `by-memory\0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md` | `boardFrame.Initialize(), itemScratch.Initialize(), glyphScratch.Initialize()` | `9C34E222A55134C3E116D86FB5E58C884D572831884FBB9A04BE6E1184A723FA` |
| C031 | 00006R | `by-class\InventoryPane.md` | `background.Initialize(), buttonFrame.Initialize()` | `0018E7DC596593AA3C76F55EF2817ABBD2799E5E277DAC533057627D077E1BB9` |
| C032 | 0004IA | `by-memory\0x0045df90-0x0045ea13.RankingRewardInfoDialogOnPaint.md` | `frame.Initialize(), frame.Initialize(), frame.Initialize()` | `4F856550821F9ABD325751A9406EA413AA0D7AF70F17B0422A8438C50D69FEAC` |
| C033 | 00030L | `by-memory\0x00467510-0x0046782f.BackGroundPaneCoreMethods.md` | `m_backgroundTileContext.Initialize()` | `284CB50669A32422C4570B4C8769DF5C81B520CFAA9185A8A406D493F8008748` |
| C034 | 0002F9 | `by-memory\0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md` | `tile.Initialize()` | `1900E872D38A15C05704690AC52764C2ED9C08B4FF3B5CEE249CE3E912A47B89` |
| C035 | 0002FD | `by-memory\0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint.md` | `tileContext.Initialize()` | `074982DE1F769DC4F45245AB4420CEE5AE4869D51F5D5861CF689E696843FB43` |
| C036 | 0002FO | `by-memory\0x00481750-0x00481a72.ChattingVarietySelectPaneDrawBorder.md` | `tileContext.Initialize()` | `08AABDEFF9B390ED50B8187479C550CA3CE7432713902CD15FFA73D751CC803C` |
| C037 | 0002FN | `by-memory\0x004816d0-0x00481741.ChattingVarietySelectPaneSetupBackground.md` | `tile.Initialize()` | `115CD0B6CAEC0A01AB86BF0D88F112B2F6865D01C2430AB24B4EFD200825093C` |
| C038 | 0002FU | `by-memory\0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md` | `tile.Initialize()` | `693BD5DE28A21C59D107CEC328AFE16D75E321F458A864EB2A9122EA4F6BC5C6` |
| C039 | 0002GH | `by-memory\0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables.md` | `unusedContext.Initialize(), background.Initialize()` | `32D1551F40A60EC5CCBB53A94A2939DF45CCA37CF52132D50FD9281A4E300AE3` |
| C040 | 0004IU | `by-memory\0x00498270-0x004984bc.PopupMenuControlPaneOnDraw.md` | `leftTile.Initialize(), centerTile.Initialize(), rightTile.Initialize()` | `B291D91FBC3970D94ED0FA238538B426929038BC64ABE87E7177BDB39B5ECAAB` |
| C041 | 0004JW | `by-memory\0x00499310-0x004993a5.EPFImageControlPaneOnPaint.md` | `frame.Initialize()` | `CB43626DC5AC538E830C3A08150EE1DE7D6CC954A4D5BDA58328AD0B847A242D` |
| C042 | 00011O | `by-memory\0x00499a50-0x00499be7.NumericStringControlPaneRenderNumericString.md` | `glyphContext.Initialize()` | `83DDCF926880B5B3C9B3B5B9234ADD0027B6CBC300B3D03BDBD1CB0EDB1F6B9B` |
| C043 | 00011S | `by-memory\0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md` | `tileContext.Initialize()` | `6516DB23190B4E528A426F34571B4FA906B781FFE2E779D6D5CA96CC91BC2E06` |
| C044 | 0003KG | `by-memory\0x0049db60-0x0049dc05.DialogPaneSetBackgroundResource.md` | `sourceContext.Initialize()` | `1E926142248B605C4841805EEC732DB6B573AC1EC92D8CC87A4BC5E1EF10AF5C` |
| C045 | 0004SW | `by-memory\0x0049f1d0-0x0049f2d4.DialogPaneDrawBackground.md` | `frame.Initialize(), frame.Initialize()` | `3E6F1714585A6551B4397DD1F9A3E58B3FCEAB1B961F7CB2230B83E0AA0FE975` |
| C046 | 0004SX | `by-memory\0x0049f2e0-0x0049f912.DialogPaneDrawBorder.md` | `frame.Initialize()` | `10540A622191EFCFD9D89094D5A8B139E36B7922CDE34445258E0FF922C2A623` |
| C047 | 0002HF | `by-memory\0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md` | `sellItemTile.Initialize(), itemGlyphContext.Initialize()` | `509D2664270081CE5D6D56BB29A99FE45ACF991094154D1F438F9B495254B4AC` |
| C048 | 0004A0 | `by-memory\0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md` | `itemContext.Initialize()` | `EC50AEEEE4088D7A78326DAB8523B9201C82E23A4A85D9CAD619FCF7755A92FE` |
| C049 | 0002JQ | `by-memory\0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md` | `tileContext.Initialize(), tileContext.Initialize()` | `2FDF5B9026ECA3A2248BBD0AE6DA7DA1624E7293DF4B422ABA625A379291C26F` |
| C050 | 00016I | `by-memory\0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md` | `glyphContext.Initialize()` | `F2EA95FB5625FC0B68E7D43775F17196747CAC3F4C4C9BD70023C3CA58E573F1` |
| C051 | 0002T1 | `by-memory\0x004cf300-0x004cf3d3.IconsPaneOnPaint.md` | `tileContext.Initialize()` | `E0250EA5AA55C61F5CF54C770B4E2DD17F8A272A23A26C01E8D9B8C4DE5A63A6` |
| C052 | 0002KR | `by-memory\0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md` | `tileContext.Initialize()` | `4623FAE460485A5AFA65AB0CCD86B3A5570A38C591B439E619C3628B65DBB876` |
| C053 | 0002Y1 | `by-memory\0x004dc7e0-0x004dca14.RidingImageLibRenderRiding.md` | `tileContext.Initialize()` | `0416F08C76A96252D553BA2B253B465A01C42F9243F514F01F9EC3DA7C1799FA` |
| C054 | 00041S | `by-memory\0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot.md` | `tileContext.Initialize()` | `528C3C7626FF8BDDA180DC9FAF0E66A1B66A66CA7BD36B368C201A20E3912D45` |
| C055 | 0003ND | `by-memory\0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability.md` | `tileContext.Initialize()` | `2F43FBC0660ECE840AAC3B8517CDF72389128AAD9C65F37014AB5ACEB2DE5B21` |
| C056 | 00053Y | `by-memory\0x004ebb20-0x004ec913.NewInventoryPaneOnPaint.md` | `background.Initialize(), button.Initialize()` | `1686FBF6213A18AA3C78FF3C33A5F0836CA426C02E2276F6B1720954E6BABD89` |
| C057 | 00048S | `by-memory\0x004ee6f0-0x004eee5c.InventoryPane2OnPaint.md` | `frame.Initialize(), buttonFrame.Initialize()` | `D589954CB4AB1A0025B9A7DFBA3956D78256AF59388B19B38696220B391A2441` |
| C058 | 0002PL | `by-memory\0x004f4c10-0x004f4eac.LogoPaneConstructor.md` | `m_logoTileContext.Initialize()` | `1C1C411C9CC06E9B50096EA5A7F4F262384836716DDE233F75F23FB39DE79BE2` |
| C059 | 0002Q8 | `by-memory\0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md` | `frameContext.Initialize()` | `20E9D4044DCA14C9E8E0844F5CA14FA1EE432C293B8B16945189FE7E3BF29A09` |
| C060 | 0002Q9 | `by-memory\0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md` | `frameContext.Initialize()` | `D6D637AAEEDA35D1EE82991B444B668C278EE4FFBCD9FBF81030B3C4FC7C592D` |
| C061 | 0004MA | `by-memory\0x004ff400-0x004ff644.ScrolledTextControlPaneForMadeByConstructor.md` | `m_renderedText.Initialize()` | `72E604DFF65526F22A1D86AD8E550AE339E5752378891717A19015D9A6D68302` |
| C062 | 0001A1 | `by-memory\0x004ffd80-0x0050008b.HistoryViewingPaneCore.md` | `frame.Initialize()` | `922ACA728F316E833F94555C9BF1E33A91FB937EA98D4DD9408ED5EC55FC5066` |
| C063 | 0004ZZ | `by-memory\0x00500700-0x00500797.GenderButtonControlPaneOnPaint.md` | `tileContext.Initialize()` | `A8CC5E19F9549E0C097E4ACED8E29279F0016A7D63166DF7F1E4C657A2730288` |
| C064 | 00050I | `by-memory\0x00500820-0x005008b9.DirectionButtonControlPaneOnPaint.md` | `tileContext.Initialize()` | `B0B50DAE9FFDC199FCB9C502EA4FA5FABA9901150B3DC12A4DC9CA20BCA775B6` |
| C065 | 0004OI | `by-memory\0x00501360-0x0050158a.UserHairSelectControlPaneOnPaintFrame.md` | `selectionFrame.Initialize(), partFrame.Initialize()` | `DF514FE77451BDE20E1E5FB161DDC35A8FF7BBC8F68447B4849F21F929527C4F` |
| C066 | 0004OO | `by-memory\0x00501840-0x00501a6a.UserFaceSelectControlPaneOnPaintFrame.md` | `selectionFrame.Initialize(), partFrame.Initialize()` | `9F3F4A2B7259E869991C142F1F849F213B469CFCDBAC4511D71F0717B88C7480` |
| C067 | 0002BF | `by-memory\0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md` | `glyphContext.Initialize()` | `09924E122B131C4686D8E422DE0A5AD5F74282C2E6D4529F38E58014BA93F4CC` |
| C068 | 0003XG | `by-memory\0x005031f0-0x005032c3.MapNamePaneConstructor.md` | `m_mapNameImage.Initialize()` | `3C92960E0BF09C49E4901E054C423E9C283DEE41E2F74236E21937FB8A567F9D` |
| C069 | 0004VP | `by-memory\0x00538c50-0x00538cfa.BowGaugeObjectPaneOnPaint.md` | `frame.Initialize()` | `BEF7EFCD076EBF7CF75176FA8A9D2D71B231F0B2F73C62463206652CE8AFD8CA` |
| C070 | 0001EE | `by-memory\0x00545170-0x00545e3b.EditablePaperPane.md` | `frames[index].Initialize(), frame.Initialize()` | `808EEEC60B66098CEFA6B5861B69B08B317B425F6797B704626EC7F561B9CD2D` |
| C071 | 0002KG | `by-memory\0x00546890-0x0054696f.ParcelPaneOnPaint.md` | `tileContext.Initialize()` | `1E36BA904DA48DB9B8ECB3D7E533291AF88CC3422257912A718A38E64878A7C1` |
| C072 | 0002KL | `by-memory\0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md` | `tileContext.Initialize()` | `F2A5D26A5AB2D280B20654EDDE76759F30E25C81993418F5781C60E2133F4D6F` |
| C073 | 0004FF | `by-memory\0x005552f0-0x00555361.RightButtonMenuPaneDrawSubwinBackground.md` | `tile.Initialize()` | `828DD1FAE2428C6F7E69BF2707FCD4FD974598082B204D6914E74045259D8440` |
| C074 | 0004FG | `by-memory\0x00555370-0x00555692.RightButtonMenuPaneDrawSubwinBorder.md` | `tileContext.Initialize()` | `696D18011201C051FEE65FB0902E5A46C3B21A6495CD76380CB02B605135FD07` |
| C075 | 0002LV | `by-memory\0x00555c70-0x00555ce1.VoteMenuPaneDrawBackground.md` | `tile.Initialize()` | `7CEDFB40DAC165F17231A751A16C9D8E9EC1DEFD07D6DB62E215D715136F9E3B` |
| C076 | 0002LW | `by-memory\0x00555cf0-0x00556012.VoteMenuPaneDrawBorder.md` | `tileContext.Initialize()` | `AC35BD9A2F24DB83FE9B7DD81A836B5A568B50D6E32016E88FD763AE8939E001` |
| C077 | 00053J | `by-memory\0x0055f890-0x0055ff70.ScrollSpellInventoryPaneOnPaint.md` | `tile.Initialize()` | `E7A3FFFCDC78B232BBA8B0C2F1A16C50D9C34707CF474E4581CCBE4A08B75981` |
| C078 | 00051O | `by-memory\0x005636a0-0x00563d80.ScrollInventoryPaneOnPaint.md` | `tile.Initialize()` | `CFBB107A045FCA174995D1E5CE3696310F28EE9732D2E22E86A10896ED78A977` |
| C079 | 0003QN | `by-memory\0x00567480-0x00568bd0.SelfLookPaneOnPaint.md` | `tileContext.Initialize(), commaContext.Initialize(), offButtonContext.Initialize(), onButtonContext.Initialize()` | `D78CE67E370CFC46F2989E63071A98124493D682705B647CD19AD716A5258176` |
| C080 | 0003QU | `by-memory\0x00569d80-0x00569ec1.SelfLookPaneDrawNumberString.md` | `glyphContext.Initialize(), symbolContext.Initialize()` | `5606B7D7865FE3CCF21FC262056C3D994B4497DCF309F3899B99E0AE8A533462` |
| C081 | 0004Z5 | `by-memory\0x0056ce50-0x0056da03.NewGroupPaneOnPaint.md` | `tileContext.Initialize(), commaFrame.Initialize(), barLeftCap.Initialize(), barRightCap.Initialize(), barFill.Initialize(), scratchContext.Initialize()` | `3E1F4113FD85CCB2F560A7556859E74D8D6118F14FCA845B498F98B41AA3E873` |
| C082 | 0003Y6 | `by-memory\0x0056edc0-0x0056f655.CollectionPaneOnPaint.md` | `tileContext.Initialize()` | `F8CC434023308050EA88CBC016980936F93C03FEC507B31794925F71D87A8AE6` |
| C083 | 0003YG | `by-memory\0x0056fdd0-0x0056fe41.CollectionPane2OnPaint.md` | `context.Initialize()` | `2F4B438E39C4737074B76B85F925FDA4CD3EE79978617BD32C025660EB2145F4` |
| C084 | 0003RB | `by-memory\0x00570fc0-0x00571c05.SelfLookPane2OnPaint.md` | `tileContext.Initialize()` | `21EEE4635413F37782FD2C76E0C3B8CDC71262EE87B7053B8D4F0A7126E58D13` |
| C085 | 0003RF | `by-memory\0x005726a0-0x00572771.SelfLookPane2DrawStatText.md` | `glyphContext.Initialize()` | `E8579633C4FBB93A761C7DD4CA5EF9BD1BF24D154094709435C28037AFD13B88` |
| C086 | 00052O | `by-memory\0x0057d430-0x0057d8c4.NewSpellInventoryPaneOnPaint.md` | `background.Initialize(), button.Initialize()` | `E11DD7E3A6561399AFBF853ED309105FECB3EEAE9A8245750B4B4D8DADB4BD22` |
| C087 | 0001KC | `by-memory\0x00598cc0-0x00598ecf.TotemFrame.md` | `tile.Initialize()` | `DC416151BE118B3B6DA76BC2320C95CDCEAC84F1CA7406FFC91AA974A92E09C1` |
| C088 | 0004MZ | `by-memory\0x005992f0-0x005993a5.TransferServerDialogPaneOnPaint.md` | `frame.Initialize()` | `86EAC1E11C4F0FE1CE7ACD0DB52F1042B7452318DBC84D7D91F9B84D621B92DC` |
| C089 | 0003FG | `by-memory\0x0059df50-0x0059e0ac.CheckBoxTextControlPaneOnPaint.md` | `uncheckedFrame.Initialize(), checkedFrame.Initialize()` | `5213EB819786064C5057E3CF14762BC3CD6592F58E8372C8C873C3856B69EBF9` |
| C090 | 00047H | `by-memory\0x0059e710-0x0059e899.UserListPaneConstructor.md` | `m_statusIconFrames[index].Initialize(), m_badgeIconFrames[index].Initialize(), m_huntersListIconFrame.Initialize()` | `D06A6B5838BE6F33EC3F42C8F30016C1FD84378E12340E36EAAB8B7506DF9D12` |
| C091 | 0003RI | `by-memory\0x0059f260-0x0059f4fd.UserLookPaneConstructor.md` | `m_portraitImage.Initialize()` | `FF99F1C4B62FBFEDBD037C6A9060071BE6027AE4E9562D719FF5DCC0D871477D` |
| C092 | 0003RM | `by-memory\0x005a0640-0x005a157d.UserLookPaneOnDraw.md` | `tileContext.Initialize()` | `A5012F0F15F1C55DDEE842CE6CEEFFB9BF278C54D8BFCF15EFF62027E93BB1DC` |
| C093 | 00054K | `by-memory\0x005c2230-0x005c2340.SwallowLayerPaneConstructor.md` | `m_swallowFrames[0].Initialize(), m_swallowFrames[1].Initialize()` | `CAF96D16960D41D5B00F58C0EEF869C5E3C187037775B3D5442D87FAFBFB250E` |

These 64 pages contain exactly 94 formal calls. Constructor correction does not authorize unrelated source repair in any consumer.

## Score And Metadata Recommendation

| UID | Dated pre-callback | Implemented | Rationale |
| --- | --- | --- | --- |
| 0000J4 | `89/86` | `94/94` | Complete unit inventory, source, routing, dependencies, consumers, and IDA handoff; exact private spellings cap confidence. |
| 00004I | `88/90` | `94/94` | Complete 0x28 H/API and coherent class CPP preamble; no destructor uncertainty remains. |
| 0000XY | `88/91` | `94/94` | Eleven exact definitions, 13-body inventory, raw/retained closure, EH/padding proof. |
| 000200 | `92/94` | unchanged | Body and behavior already source-complete; only order metadata changes. |
| 000201 | `89/92` | unchanged | Body/type/friendship already accepted; only order metadata changes. |
| 00015T | `86/90` | `88/92` | Missing H declaration and EPFTileContext call relationship close; exact name remains descriptive. |
| 0003ZP | `92/94` | `93/95` | Required H declaration closes its sole generated consumer dependency. |
| 00029U | `88/93` | `90/94` | Exact external-vs-static header disposition closes the cross-TU use. |

Score-improvement attempts resolved every former blocker: retained helpers through branch correspondence; constructor/destructor through EAX/EH/scope routes; layout/type through MCP; source order through address/emitter order; header dependencies through physical generated H; consumers through exhaustive formal search. No generic no-improvement exception is used.

Implemented metadata changes: aggregate position blank -> `0`; UID000200 blank -> `10`; UID000201 blank -> `20`. All owner/emitter/reconstructable/range/path fields remain unchanged.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Resolution |
| --- | --- | --- |
| Is `0x457a60` Initialize or constructor? | EAX return, 337 xrefs, member/automatic sites, new-expression cleanup chunks | Constructor, very high confidence. |
| Is ReleaseBuffers a destructor? | 71 explicit calls and absent calls at borrowed local exits | No; explicit ownership method. |
| Are zero-xref helpers safe to emit? | bytes, prologs, behavior correspondence, inline copies, EH | Yes; retained authored private helpers. |
| Does RGB16 half-scale preserve format? | both exact word paths | No; it leaves constructor-default Indexed8. Preserve the quirk. |
| Should DLPalette UDT be changed? | current IDA type and current generated Palette.h | No; source header only, protected IDA state. |
| Are additional globals/data/resources owned? | bounded entities, xrefs, strings, types, generated files | None. |
| What exact private names were original? | symbols absent, family conventions, behavior | Unrecoverable lexical detail; descriptive names are implementation-ready and do not affect behavior. |
| Can raw `0x457f30` be safely defined under this handoff? | Exact raw bytes/range/calls and the dated no-function prestate are known, but no read-only evidence fixes the public endpoint's generated function name, type, or frame before mutation. | No structural action is recommended. A05 requires complete literal no change, A06 is retired, and the behaviorally reconstructed private C++ remains valid without an IDA function item. |
| Are the remaining IDA renames deterministic and self-contained? | Public `rename` schema, literal ranges/hashes/types/frames/comments/xrefs/callees, collision evidence, EH associations, protected neighbors, the attested pure-rename implementation, and the dated A01 cached-header readback were reconciled row by row. | Yes. Eleven exact requests own only their persisted/public function-symbol field. Each action separately states the exact new persisted IDB name with unchanged TInfo, exact new public `inspect_items` symbol with row-specific type, and exact cached pre-rename immediate Hex-Rays function-name/prototype; a refreshed or otherwise different immediate decompiler header hard-stops. A03 alone permits exact P0 public type convergence from `void *` to `MemoryMan *` while persisted TInfo remains unchanged. A07's structural callee set uses A01's post-rename `0x457a60 EPFTileContext__EPFTileContext` identity; every omitted delta is a hard stop and no action depends on cross-section shorthand. |

Questions remaining unresolved: none that blocks score, ownership, placement, C++, or implementation. Unresolved-item count `0`.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Do not edit manual coverage during the callback. The supervisor applies these exact replacements after ordinary validation and generated readback.

File `by-file/-coverage-report.md`, replace UID0000J4 row:

`    - [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md) : reconstructable : 94% : very-strong : Complete 13-body EPFTileContext render unit with default-constructor identity, explicit non-destructor ReleaseBuffers ownership, indexed/RGB16 mask builders, deep-copy and retained RGB16 specialization, generic/retained half-scale decimation, three allocation methods, normalization and DLPalette range-query children, exact 0x28 layout, twelve padding intervals, compiler-only EH metadata, complete CPP/H dependency topology, and no remaining empty marker or retained-helper blocker.`

File `by-class/-coverage-report.md`, replace UID00004I row:

`    - [UID:00004I][EPFTileContext](by-class/EPFTileContext.md) : reconstructable : 94% : very-strong : Complete non-polymorphic 0x28 EPFTileContext declaration and render source route with default constructor, explicit buffer release and no destructor, mask/copy/half-scale/allocation/normalization/range APIs, private RGB16 specializations, exact RectBounds/Palette/Surface/SoftwareBlend16/MemoryMan dependencies, and aggregate-plus-two-child source order.`

File `by-memory/-coverage-report.md`, replace UID0000XY row:

`    - [UID:0000XY][0x00457a60-0x00458610.EPFTileContext](by-memory/0x00457a60-0x00458610.EPFTileContext.md) 0x00457a60-0x00458610 | class aggregate | EPFTileContext : reconstructable : 94% : very-strong : Exact 13-body EPFTileContext aggregate with constructor proof, explicit release/no-destructor disposition, byte/word mask builders, generic and retained RGB16 copy/half-scale helpers, allocation family, UID000200/UID000201 tail children, twelve all-cc gaps, six compiler-only EH items, complete formal source, and closed raw/zero-xref/source-order/header blockers.`

File `by-memory/-coverage-report.md`, replace UID00015T row:

`    - [UID:00015T][0x004b7ca0-0x004b7cb6.RectArea](by-memory/0x004b7ca0-0x004b7cb6.RectArea.md) 0x004b7ca0-0x004b7cb6 | class/helper method | RectArea : reconstructable : 88% : very-strong : Exact 0x16-byte free signed RectBounds area helper with four callers, no callees, unclamped 32-bit expression, complete CPP plus H declaration, and two EPFTileContext half-scale allocation routes; original helper spelling remains descriptive.`

File `by-memory/-coverage-report.md`, replace UID0003ZP row:

`    - [UID:0003ZP][0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels](by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md) 0x004bb0e0-0x004bb111 | function | ConvertRgb565ToRgb555Pixels : reconstructable : 93% : very-strong : Exact one-caller cdecl in-place RGB565-to-RGB555 compatibility transform with zero-count no-op, nonnegative signed-count contract, preserved 0x7ff0 OR-fold quirk, complete CPP/H, and explicit EPFTileContext normalization dependency.`

File `by-memory/-coverage-report.md`, replace UID00029U row:

`    - [UID:00029U][0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags](by-memory/0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags.md) 0x0069b3d4-0x0069b3d8 | render mode flags | SurfacePixelFormatFlags : reconstructable : 90% : very-strong : Surface-owned source globals g_surfaceUses32BitPresentation and externally declared g_surfaceUsesRgb565Pixels plus two alignment bytes; exact zero image bytes, D4 seven refs, D5 sixteen refs, initializer polarity, RGB565 mask test, compatibility consumers, CPP definitions, and cross-TU H disposition are complete.`

Current UID000200, UID000201, RectBounds file/class, SoftwareBlend16 file, and Surface file manual rows were inspected and need no text/score change. No tracker text is authored here; generated tracker state is validator-owned.

## Follow-Up Actions

- Supervisor gate authority: current Gate 1 and Gate 2A status is determined only from the current supervisor audit and current by-* readback against the 102 checked / nine unchecked allocation and Section 31 receipts; this report body asserts neither pending nor completed gate state.
- Ordinary implementation callback: completed under short leases with every exact path-bound validator and final target `--wait-generated` command; generated CPP/H were physically compared to Section 22.
- Supervisor Gate 2B: use the eleven literal public rename requests A01-A04/A07-A13 with P01-P05; verify every row's exact new persisted/public symbol, unchanged persisted/public type, and exact cached old-name immediate Hex-Rays function header; permit only A03's exact P0 public `void *` to `MemoryMan *` convergence with persisted TInfo unchanged; verify A05's complete literal unchanged raw-code/absent-type state, invoke no A06 endpoint, and fail closed on every refreshed/different immediate decompiler header or other non-owned delta.
- Supervisor manual coverage: apply the six Section 28 rows only after Gate 2A/Gate 2B evidence.
- A-agent actions: none.
- B002 future research actions: none; only accepted implementation/reconciliation work for this same report.

## Confidence

- Recommendation confidence: very high, including the eleven literal public rename schemas, the fresh canonical separated persisted/public/decompiler matrix, the dated A01 stale-cache proof, the exact A03 P0/P1 convergence contract, and self-contained protected readback sets.
- Score confidence: high.
- Remaining uncertainty: exact original private helper spellings and the endpoint-specific identity a prohibited `define_func` trial might synthesize at raw `0x457f30`. Neither affects ABI, behavior, boundaries, source ownership, or compile topology; the latter is removed from the handoff through A05 no-change/A06 retirement.

## Validator Results

- Callback working directory for every command: `E:\NTK\GhidraBridge\source-3\project-documentation`.
- Canonical leased callback receipts: all 75 exact Section 31 path-bound commands exited `0` with `ok: 1`. The ten fresh core/support receipts are `000000025731` through `000000025740`; all 64 consumer receipts are listed individually; the literal final owner command is `000000025741` with completed generated refresh.
- Lease-correction history: initial core/support commands `000000025647` through `000000025656` and initial waited owner command `000000025730` also exited `0` / `ok: 1`, but their batch lease timing was not retained as final proof. They are preserved in the preliminary receipt table below; the fresh leased commands supersede them without changing ordinary source semantics.
- Validator-owned side effects are recorded per command below. They are receipts, not B002-authored edits to generated, tracker, stats, registry, or index state.
- Physical post-refresh readback: `auto-generated/NexusTK/render/EPFTileContext.cpp` SHA256 `EB24CFD8B1E95416652B6E0AC57209F16E623D947835D0EAAB10C067DB91D2A5`, `12215` bytes, `390` lines; `EPFTileContext.h` SHA256 `3BE1B3469A6A10B260FFFAAD2A68A5A2F8696E3453A659E4B73B33B977809F6E`, `1400` bytes, `46` lines. Both carry command `000000025741` / `2026-08-17T18:36:18-04:00` metadata.
- Generated semantic readback: 13 unique `EPFTileContext::` definitions in accepted `0/10/20` order; five CPP includes; one complete seven-field class with constructor, ten method declarations, three private helpers, and no destructor; exact `RectArea`, `ConvertRgb565ToRgb555Pixels`, and `g_surfaceUsesRgb565Pixels` support declarations; zero raw IDA name, Empty Emitter Marker, stale `Initialize`, duplicate definition, stub, TODO, or placeholder.

Canonical leased receipts:

| Path | Exact cwd / single-line command | command_id / timestamp | Exit / ok | Command-specific warnings or errors | Generated refresh | Relevant validator-owned side effects | Final physical SHA256 / bytes / lines |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `by-class\EPFTileContext.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-class\EPFTileContext.md --apply --queue-timeout 240` | `000000025731`; `2026-08-17T18:34:09-04:00` | `0 / 1` | none | `deferred` | projected_stats_update=1; stats_incremental_noop=1 | `0D3A5C0B666E32CC5706CDA71CC7D5150DB534DCE84767BC3F4B6A11ABC4A5F3` / `30749` / `284` |
| `by-memory\0x00457a60-0x00458610.EPFTileContext.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00457a60-0x00458610.EPFTileContext.md --apply --queue-timeout 240` | `000000025732`; `2026-08-17T18:34:13-04:00` | `0 / 1` | none | `deferred` | projected_stats_update=1; stats_incremental_noop=1 | `22D4DBB4FBA815A34B43C6E59A885EB4645CA70AAFDE9BB1AE37997DF47121B6` / `39566` / `577` |
| `by-memory\0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md --apply --queue-timeout 240` | `000000025733`; `2026-08-17T18:34:23-04:00` | `0 / 1` | none | `deferred` | projected_stats_update=1; stats_incremental_noop=1 | `80D291E3F8EAA55EE652C560E539815A6190E37EB3C53BCA0AC78596092598F3` / `15051` / `165` |
| `by-memory\0x00458590-0x00458610.EPFTileContextPixelRangeTest.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00458590-0x00458610.EPFTileContextPixelRangeTest.md --apply --queue-timeout 240` | `000000025734`; `2026-08-17T18:34:38-04:00` | `0 / 1` | none | `deferred` | projected_stats_update=1; stats_incremental_noop=1 | `E9D93D9C2046F0EDF2328F43E7174C56AE7FE3F125980AECF5AE9E4022243B3F` / `17864` / `159` |
| `by-memory\0x004b7ca0-0x004b7cb6.RectArea.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x004b7ca0-0x004b7cb6.RectArea.md --apply --queue-timeout 240` | `000000025735`; `2026-08-17T18:34:52-04:00` | `0 / 1` | none | `deferred` | projected_stats_update=1; stats_incremental_noop=1 | `56CFDD094251F0DB679A3B8C85175949C78072818181499D39FE5DBF5A728E06` / `8002` / `81` |
| `by-memory\0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md --apply --queue-timeout 240` | `000000025736`; `2026-08-17T18:35:06-04:00` | `0 / 1` | none | `deferred` | projected_stats_update=1; stats_incremental_noop=1 | `0F6BCCF543E30D4015E3E4EC9D13EEE1BBAC561E72EDF8F95AF4704B4117ABED` / `16456` / `146` |
| `by-memory\0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags.md --apply --queue-timeout 240` | `000000025737`; `2026-08-17T18:35:20-04:00` | `0 / 1` | none | `deferred` | projected_stats_update=1; stats_incremental_noop=1 | `B3BFAB3BFF10C6C78AE9FD8520D8C331E7230BB256C27AB9836FB5366EEEA011` / `19985` / `144` |
| `by-file\RectBounds.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-file\RectBounds.md --apply --queue-timeout 240` | `000000025738`; `2026-08-17T18:35:34-04:00` | `0 / 1` | missing_ref_uid=4 (00040U) | `deferred` | projected_stats_update=1; stats_row_update=1 | `940F25AB900FE3BC48CCFF9F547B3EEB019A655FC2932B2736A3A9E82E1C2763` / `30320` / `161` |
| `by-file\SoftwareBlend16.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-file\SoftwareBlend16.md --apply --queue-timeout 240` | `000000025739`; `2026-08-17T18:35:48-04:00` | `0 / 1` | none | `deferred` | projected_stats_update=1; stats_incremental_noop=1 | `69B8B1AC9B4649A0806F4A4F3560EE91A50BC1392B0A6CCB878D24D3DF3A3207` / `46949` / `240` |
| `by-file\Surface.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-file\Surface.md --apply --queue-timeout 240` | `000000025740`; `2026-08-17T18:35:59-04:00` | `0 / 1` | missing_ref_uid=12 (00039R, 0003XE, ------) | `deferred` | projected_stats_update=1; stats_incremental_noop=1 | `933982A59172643F4431DCC87E213A64ADBBAC1A5E9C67E5D1EF5439EE2642CE` / `144336` / `625` |
| `by-memory\0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md --apply --queue-timeout 240` | `000000025659`; `2026-08-17T18:09:39-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `E3F2A0898CFD46CE5ED4EBD21AC71300392238DF47C2D7EA4D70C49AE678761B` / `36221` / `350` |
| `by-class\InventoryPane.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-class\InventoryPane.md --apply --queue-timeout 240` | `000000025660`; `2026-08-17T18:10:47-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `971F10A76A3EA2931AE491BCB10DAB13ECC721E8AE341AC5361E3D1E17F1743F` / `24866` / `495` |
| `by-memory\0x0045df90-0x0045ea13.RankingRewardInfoDialogOnPaint.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x0045df90-0x0045ea13.RankingRewardInfoDialogOnPaint.md --apply --queue-timeout 240` | `000000025661`; `2026-08-17T18:10:51-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `A0440B7E061A59E492EA5C5C1FD5FEDFC49A0D400E5BFBF04557B02CE04661E2` / `13950` / `281` |
| `by-memory\0x00467510-0x0046782f.BackGroundPaneCoreMethods.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00467510-0x0046782f.BackGroundPaneCoreMethods.md --apply --queue-timeout 240` | `000000025662`; `2026-08-17T18:11:02-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `5E5083DE7F28349FFD4D0F46DA68C544F7528D412EF31CE1B860A87E1A8E85DF` / `10286` / `170` |
| `by-memory\0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md --apply --queue-timeout 240` | `000000025663`; `2026-08-17T18:11:18-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `309136AC115E73A06F538E0837608431A60F46D8F22D172D4B5F7DDF5E1774A0` / `15923` / `135` |
| `by-memory\0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint.md --apply --queue-timeout 240` | `000000025664`; `2026-08-17T18:11:34-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `6D1A6B59A93367485B03601484DDA21384178ACBFA511C7C6F6C98127D702295` / `19519` / `228` |
| `by-memory\0x00481750-0x00481a72.ChattingVarietySelectPaneDrawBorder.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00481750-0x00481a72.ChattingVarietySelectPaneDrawBorder.md --apply --queue-timeout 240` | `000000025665`; `2026-08-17T18:11:50-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `48E7FBEEFF219EAAFC55ACA3A749FBCEC969A4440B4DFC86FF1BA8DD73E710DA` / `15335` / `203` |
| `by-memory\0x004816d0-0x00481741.ChattingVarietySelectPaneSetupBackground.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x004816d0-0x00481741.ChattingVarietySelectPaneSetupBackground.md --apply --queue-timeout 240` | `000000025666`; `2026-08-17T18:12:06-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `9B56AF4602193F75C5908164C16C4D82E7C7679E6814C9775CCF38F44E4444BA` / `13065` / `136` |
| `by-memory\0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md --apply --queue-timeout 240` | `000000025667`; `2026-08-17T18:12:22-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `2AF617C58C5C0A163B8309ED93A9E70F0C2B5CF35F7434B821BC9BC1651F1973` / `12115` / `147` |
| `by-memory\0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables.md --apply --queue-timeout 240` | `000000025668`; `2026-08-17T18:13:06-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `FF640F077177903D78D413344D741DDA3A4F5A6AE99850CAA8A5118BA903B633` / `20882` / `192` |
| `by-memory\0x00498270-0x004984bc.PopupMenuControlPaneOnDraw.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00498270-0x004984bc.PopupMenuControlPaneOnDraw.md --apply --queue-timeout 240` | `000000025669`; `2026-08-17T18:13:10-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `37CE2807BB7108BDCCA9ABB3F076215E576062BB77C922D704AE74A7221D4925` / `6610` / `106` |
| `by-memory\0x00499310-0x004993a5.EPFImageControlPaneOnPaint.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00499310-0x004993a5.EPFImageControlPaneOnPaint.md --apply --queue-timeout 240` | `000000025670`; `2026-08-17T18:13:26-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `44B05D042E53D4DA66432E8D9D8E35CB4E5EC37776E4D03BCC7C55D77302E5F6` / `9819` / `151` |
| `by-memory\0x00499a50-0x00499be7.NumericStringControlPaneRenderNumericString.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00499a50-0x00499be7.NumericStringControlPaneRenderNumericString.md --apply --queue-timeout 240` | `000000025671`; `2026-08-17T18:13:42-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `FCBB3D683E532B556794F03966F4DDE3B66C9E20F8177E30A544A128A4A7B34F` / `10201` / `146` |
| `by-memory\0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md --apply --queue-timeout 240` | `000000025672`; `2026-08-17T18:13:58-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `EDEECF5056A5A11114C2E231C2CD3EDC603516330B9C58404093E9CFE1F88E24` / `19778` / `214` |
| `by-memory\0x0049db60-0x0049dc05.DialogPaneSetBackgroundResource.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x0049db60-0x0049dc05.DialogPaneSetBackgroundResource.md --apply --queue-timeout 240` | `000000025673`; `2026-08-17T18:14:14-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `4361E588D62769DEAA4B6D6DA0E6A1CAD573B4CA809362D0E85D63309AC3C3AB` / `8206` / `113` |
| `by-memory\0x0049f1d0-0x0049f2d4.DialogPaneDrawBackground.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x0049f1d0-0x0049f2d4.DialogPaneDrawBackground.md --apply --queue-timeout 240` | `000000025674`; `2026-08-17T18:14:29-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `A5D0FF4392AC2775FABF2D0E33ECFBBCDCF441998E7DC58570C1F1DF64202C2E` / `7817` / `130` |
| `by-memory\0x0049f2e0-0x0049f912.DialogPaneDrawBorder.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x0049f2e0-0x0049f912.DialogPaneDrawBorder.md --apply --queue-timeout 240` | `000000025675`; `2026-08-17T18:14:46-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `0E63745DDEA6C9FBC4AE21B5A0B4C0869F75A668C64AA7CB8B6DC62B085E2172` / `13993` / `273` |
| `by-memory\0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md --apply --queue-timeout 240` | `000000025676`; `2026-08-17T18:15:27-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `5DC4F6CB92B581653716C23892545CA7C93730AC453CC3FDDC33D2F8F43E2ED8` / `23958` / `192` |
| `by-memory\0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md --apply --queue-timeout 240` | `000000025677`; `2026-08-17T18:15:31-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; reference_index_add=1; projected_stats_update=1; stats_incremental_noop=1 | `A107E283E5ED93884342F6BD54493AB7FA48832338E225EC7DFCC8230B216A17` / `14417` / `149` |
| `by-memory\0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md --apply --queue-timeout 240` | `000000025678`; `2026-08-17T18:15:47-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; reference_index_add=1; projected_stats_update=1; stats_incremental_noop=1 | `B2ACF7A42678F4D9A0DD111DD51AAE1A2B648C6A4DB678DB27A7254A918B0E55` / `16534` / `248` |
| `by-memory\0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md --apply --queue-timeout 240` | `000000025679`; `2026-08-17T18:16:03-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `D9E39BAB9022C026F33D4247872D5FC5BA9810BCFC8C7F140064493A2FAF132F` / `19729` / `205` |
| `by-memory\0x004cf300-0x004cf3d3.IconsPaneOnPaint.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x004cf300-0x004cf3d3.IconsPaneOnPaint.md --apply --queue-timeout 240` | `000000025681`; `2026-08-17T18:16:18-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `6433BCE386B4426DF071F73E906CC28A41E8FAA1897D81CC43DA39CAF4F8FB40` / `14447` / `163` |
| `by-memory\0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md --apply --queue-timeout 240` | `000000025682`; `2026-08-17T18:16:36-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `ACEA7AE46B88ECEEF73763C6C3C6EE7ACC59C6F690B2924841C25F2A5AA33D43` / `9528` / `104` |
| `by-memory\0x004dc7e0-0x004dca14.RidingImageLibRenderRiding.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x004dc7e0-0x004dca14.RidingImageLibRenderRiding.md --apply --queue-timeout 240` | `000000025683`; `2026-08-17T18:16:47-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `BE10CCCEA30C8D4C8610793B79930A8DADEC5D85E3F723EB99490361A19DF482` / `17232` / `262` |
| `by-memory\0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot.md --apply --queue-timeout 240` | `000000025685`; `2026-08-17T18:17:03-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `E97486AEC619E80022596FBA448EC54CF60F9B1DD398F34873A23D79F1E1C4D8` / `16266` / `235` |
| `by-memory\0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability.md --apply --queue-timeout 240` | `000000025686`; `2026-08-17T18:17:45-04:00` | `0 / 1` | missing_ref_uid=5 (0003LZ) | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `E303AE05EABFAF5BCE35D4279828B9339362CBE54AAFE56221CBB44C7D064C28` / `16299` / `147` |
| `by-memory\0x004ebb20-0x004ec913.NewInventoryPaneOnPaint.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x004ebb20-0x004ec913.NewInventoryPaneOnPaint.md --apply --queue-timeout 240` | `000000025687`; `2026-08-17T18:18:01-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `0CBDEA4032C4D743F61D07758128B5AFC630669BB99D1FDB323A5A3923A69F5E` / `6781` / `139` |
| `by-memory\0x004ee6f0-0x004eee5c.InventoryPane2OnPaint.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x004ee6f0-0x004eee5c.InventoryPane2OnPaint.md --apply --queue-timeout 240` | `000000025688`; `2026-08-17T18:18:17-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `C7A266B6F1986DE5DE18C60C4A45D79F46600D9C3F0755F7CF2CA32ABA506088` / `6290` / `124` |
| `by-memory\0x004f4c10-0x004f4eac.LogoPaneConstructor.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x004f4c10-0x004f4eac.LogoPaneConstructor.md --apply --queue-timeout 240` | `000000025689`; `2026-08-17T18:18:33-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `B8CF073AB18FE90C3CBC9F811E6D8D05BD5545F2BD988FD01F756573F3FF16CC` / `20457` / `189` |
| `by-memory\0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md --apply --queue-timeout 240` | `000000025690`; `2026-08-17T18:18:49-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `7D7D566E2070420D330DD9A7A8C87A3687023A5E9A2128A0260D1EB727FB8A0F` / `30882` / `379` |
| `by-memory\0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md --apply --queue-timeout 240` | `000000025691`; `2026-08-17T18:19:05-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `63239D23EC1198F3A695D37F0D083234C9116EF2BFB1CB45A619D1CD7B415C50` / `33544` / `430` |
| `by-memory\0x004ff400-0x004ff644.ScrolledTextControlPaneForMadeByConstructor.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x004ff400-0x004ff644.ScrolledTextControlPaneForMadeByConstructor.md --apply --queue-timeout 240` | `000000025692`; `2026-08-17T18:19:21-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `49767E0A7126A9DFB640E4FFD640FAE91226AFF3CB4146EF97B4F1C156886027` / `9135` / `130` |
| `by-memory\0x004ffd80-0x0050008b.HistoryViewingPaneCore.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x004ffd80-0x0050008b.HistoryViewingPaneCore.md --apply --queue-timeout 240` | `000000025693`; `2026-08-17T18:19:37-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `A1B065FC5A3332E1F7EDED2647EF00CC65A424CE23B5607545D2C0C4D8F8F245` / `25923` / `249` |
| `by-memory\0x00500700-0x00500797.GenderButtonControlPaneOnPaint.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00500700-0x00500797.GenderButtonControlPaneOnPaint.md --apply --queue-timeout 240` | `000000025694`; `2026-08-17T18:20:26-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; reference_index_add=1; projected_stats_update=1; stats_incremental_noop=1 | `B450A45017DC37F4A4EFC5DBD68FFA42F1011CE7E21BEED11A544846E3101858` / `7204` / `122` |
| `by-memory\0x00500820-0x005008b9.DirectionButtonControlPaneOnPaint.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00500820-0x005008b9.DirectionButtonControlPaneOnPaint.md --apply --queue-timeout 240` | `000000025695`; `2026-08-17T18:20:30-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `0A14B41A04E07B2E48D4748936DC5E6EDCA0F31499B45F681DA8FF1B24DF684A` / `8024` / `125` |
| `by-memory\0x00501360-0x0050158a.UserHairSelectControlPaneOnPaintFrame.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00501360-0x0050158a.UserHairSelectControlPaneOnPaintFrame.md --apply --queue-timeout 240` | `000000025696`; `2026-08-17T18:20:46-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `AC9F6CDD7D82CF865A91910A6EB93164EF82125CCD79032C13222955F938260D` / `8487` / `139` |
| `by-memory\0x00501840-0x00501a6a.UserFaceSelectControlPaneOnPaintFrame.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00501840-0x00501a6a.UserFaceSelectControlPaneOnPaintFrame.md --apply --queue-timeout 240` | `000000025697`; `2026-08-17T18:21:02-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `119EF92CAD9B91AD0D235035472E7394AD6B2DBA43780CC98C069FCD3A633895` / `8133` / `131` |
| `by-memory\0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md --apply --queue-timeout 240` | `000000025698`; `2026-08-17T18:21:18-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `3096D684865E60E9A5941C21DEFDE817930DAC6E56C1C1FA0BF1F0E79522B65C` / `20483` / `174` |
| `by-memory\0x005031f0-0x005032c3.MapNamePaneConstructor.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x005031f0-0x005032c3.MapNamePaneConstructor.md --apply --queue-timeout 240` | `000000025699`; `2026-08-17T18:21:34-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; reference_index_add=1; projected_stats_update=1; stats_incremental_noop=1 | `90DBB2078013EC883ED0090F8AD2E3F6CB7318FD0A430C80F5FAAD7F38B28B4D` / `6795` / `80` |
| `by-memory\0x00538c50-0x00538cfa.BowGaugeObjectPaneOnPaint.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00538c50-0x00538cfa.BowGaugeObjectPaneOnPaint.md --apply --queue-timeout 240` | `000000025700`; `2026-08-17T18:21:50-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `4DA9B06AE8BC1CBE1F8E3988F959D2770A3C0013A7B6379B5A55E9043EE368BF` / `6954` / `104` |
| `by-memory\0x00545170-0x00545e3b.EditablePaperPane.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00545170-0x00545e3b.EditablePaperPane.md --apply --queue-timeout 240` | `000000025701`; `2026-08-17T18:22:06-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `28E41276CA0EB2317BA2914622EDE3C7189228C986178A81368D70291377022E` / `26730` / `431` |
| `by-memory\0x00546890-0x0054696f.ParcelPaneOnPaint.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00546890-0x0054696f.ParcelPaneOnPaint.md --apply --queue-timeout 240` | `000000025702`; `2026-08-17T18:22:52-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `AB5E746678203828E831B788A91A6D49C6CC9717354EF222534822CE5E61418C` / `20637` / `170` |
| `by-memory\0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md --apply --queue-timeout 240` | `000000025703`; `2026-08-17T18:22:56-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `58026F0C677AD44DA09BC5D1548BA01265A3BD9B4A302C517B0D9000EEF2C425` / `18863` / `178` |
| `by-memory\0x005552f0-0x00555361.RightButtonMenuPaneDrawSubwinBackground.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x005552f0-0x00555361.RightButtonMenuPaneDrawSubwinBackground.md --apply --queue-timeout 240` | `000000025704`; `2026-08-17T18:23:12-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `7DE8E180D3C61EA99E9CDFBD9D168E50C0EADE497C48A56BF0A19FDDA04BFB06` / `4410` / `85` |
| `by-memory\0x00555370-0x00555692.RightButtonMenuPaneDrawSubwinBorder.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00555370-0x00555692.RightButtonMenuPaneDrawSubwinBorder.md --apply --queue-timeout 240` | `000000025706`; `2026-08-17T18:23:28-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `83FBAB0C5FFE59837DA411DB6A80ED0E549C76F1D61BB93A32E6176E0D43E1F8` / `7966` / `179` |
| `by-memory\0x00555c70-0x00555ce1.VoteMenuPaneDrawBackground.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00555c70-0x00555ce1.VoteMenuPaneDrawBackground.md --apply --queue-timeout 240` | `000000025707`; `2026-08-17T18:23:46-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `17C82E1DB6C3B1E5218167C7D626FC4C94C4E841A5B7814664968BEA9F4D8B03` / `9894` / `156` |
| `by-memory\0x00555cf0-0x00556012.VoteMenuPaneDrawBorder.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00555cf0-0x00556012.VoteMenuPaneDrawBorder.md --apply --queue-timeout 240` | `000000025708`; `2026-08-17T18:24:02-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `69B9E33A83D4B030D638BBEF2AB8DE2E597F032D5ACCB3851957C96F425C929D` / `16931` / `213` |
| `by-memory\0x0055f890-0x0055ff70.ScrollSpellInventoryPaneOnPaint.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x0055f890-0x0055ff70.ScrollSpellInventoryPaneOnPaint.md --apply --queue-timeout 240` | `000000025709`; `2026-08-17T18:24:18-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `38FA79BCCBF673AD0C5CCC58FD5BFA443F75953CDA00BB8ED9B2EB2D2DEBD5A8` / `8504` / `157` |
| `by-memory\0x005636a0-0x00563d80.ScrollInventoryPaneOnPaint.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x005636a0-0x00563d80.ScrollInventoryPaneOnPaint.md --apply --queue-timeout 240` | `000000025710`; `2026-08-17T18:24:33-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `BC435B0E6F65AA10BAC43A3269A0FD741C9F2C388D59540FF7BFF926AB2D8934` / `7263` / `132` |
| `by-memory\0x00567480-0x00568bd0.SelfLookPaneOnPaint.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00567480-0x00568bd0.SelfLookPaneOnPaint.md --apply --queue-timeout 240` | `000000025711`; `2026-08-17T18:25:14-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `B956FF46CF6684FFA13D6698671D53E5E82EE082D1F420AA03E049109CA98DC0` / `32185` / `640` |
| `by-memory\0x00569d80-0x00569ec1.SelfLookPaneDrawNumberString.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00569d80-0x00569ec1.SelfLookPaneDrawNumberString.md --apply --queue-timeout 240` | `000000025712`; `2026-08-17T18:25:18-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `4C79EFC9CBB3A5540E30CF68B4677EE95DD449B7EE8A192FE74471A3C65BB46F` / `6090` / `102` |
| `by-memory\0x0056ce50-0x0056da03.NewGroupPaneOnPaint.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x0056ce50-0x0056da03.NewGroupPaneOnPaint.md --apply --queue-timeout 240` | `000000025713`; `2026-08-17T18:25:34-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `6324728689B4F40363CB14E58B304DA9BE76C870D1C0823B3CC202947255BA08` / `24161` / `315` |
| `by-memory\0x0056edc0-0x0056f655.CollectionPaneOnPaint.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x0056edc0-0x0056f655.CollectionPaneOnPaint.md --apply --queue-timeout 240` | `000000025714`; `2026-08-17T18:25:50-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `320BE2A4B384F0AA89076750CB0193F94E951293EF1F966587F92E07E43E41BB` / `10961` / `178` |
| `by-memory\0x0056fdd0-0x0056fe41.CollectionPane2OnPaint.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x0056fdd0-0x0056fe41.CollectionPane2OnPaint.md --apply --queue-timeout 240` | `000000025715`; `2026-08-17T18:26:06-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `EDA79E73E44B5B728CA42AE40891BBB1DA9F6F5F1F8647D1F11F863CB1C40024` / `4078` / `57` |
| `by-memory\0x00570fc0-0x00571c05.SelfLookPane2OnPaint.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00570fc0-0x00571c05.SelfLookPane2OnPaint.md --apply --queue-timeout 240` | `000000025716`; `2026-08-17T18:26:21-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `854E29B4A42F31ED2B426AF173C58A8BF28F93C14C5F2B35BE9BA5F4830EA12F` / `24580` / `474` |
| `by-memory\0x005726a0-0x00572771.SelfLookPane2DrawStatText.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x005726a0-0x00572771.SelfLookPane2DrawStatText.md --apply --queue-timeout 240` | `000000025717`; `2026-08-17T18:26:37-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `ECD83E86225D80788592A83FD23BA33E6F424BD77EED1655B8E23FAAAE2AD29E` / `5852` / `93` |
| `by-memory\0x0057d430-0x0057d8c4.NewSpellInventoryPaneOnPaint.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x0057d430-0x0057d8c4.NewSpellInventoryPaneOnPaint.md --apply --queue-timeout 240` | `000000025718`; `2026-08-17T18:26:53-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `BC279B6DDDAE9CC0CB4FB2A398028E3DB65EA9AE747D09C309AC3147AC01DC6A` / `6137` / `137` |
| `by-memory\0x00598cc0-0x00598ecf.TotemFrame.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00598cc0-0x00598ecf.TotemFrame.md --apply --queue-timeout 240` | `000000025723`; `2026-08-17T18:27:37-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `EFACE727530F1E2B782E69F3FB370D47DF551CDF2370C0AF4AA97CAD6F0236F7` / `22396` / `187` |
| `by-memory\0x005992f0-0x005993a5.TransferServerDialogPaneOnPaint.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x005992f0-0x005993a5.TransferServerDialogPaneOnPaint.md --apply --queue-timeout 240` | `000000025724`; `2026-08-17T18:27:50-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `0AEF50B881F42017B739B427D82C377C22CFBA36AC18F0D42F13B2F7B428F859` / `4907` / `75` |
| `by-memory\0x0059df50-0x0059e0ac.CheckBoxTextControlPaneOnPaint.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x0059df50-0x0059e0ac.CheckBoxTextControlPaneOnPaint.md --apply --queue-timeout 240` | `000000025725`; `2026-08-17T18:28:07-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `DD5F50795F5425508057FFDD340882BC66447BD577DF5A5DF13DEB29682E543D` / `8847` / `124` |
| `by-memory\0x0059e710-0x0059e899.UserListPaneConstructor.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x0059e710-0x0059e899.UserListPaneConstructor.md --apply --queue-timeout 240` | `000000025726`; `2026-08-17T18:28:18-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `3A4C357295182752AC88AD0A0D868874CDE22D7E569783C6F056D568EEAFD893` / `10820` / `134` |
| `by-memory\0x0059f260-0x0059f4fd.UserLookPaneConstructor.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x0059f260-0x0059f4fd.UserLookPaneConstructor.md --apply --queue-timeout 240` | `000000025727`; `2026-08-17T18:28:33-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `7C692D1A8D3439DC7578EB21921E5FC849750258C59EE5F576F79642FAD3C8A6` / `13872` / `133` |
| `by-memory\0x005a0640-0x005a157d.UserLookPaneOnDraw.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x005a0640-0x005a157d.UserLookPaneOnDraw.md --apply --queue-timeout 240` | `000000025728`; `2026-08-17T18:28:49-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `77385683C9AAEE84916625A743EF3BDB247A8974B26D42D59439D2BABAE89BE5` / `38323` / `703` |
| `by-memory\0x005c2230-0x005c2340.SwallowLayerPaneConstructor.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x005c2230-0x005c2340.SwallowLayerPaneConstructor.md --apply --queue-timeout 240` | `000000025729`; `2026-08-17T18:29:05-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; projected_stats_update=1; stats_incremental_noop=1 | `9F3B2F5276CBF2DAE1C94F08983DF08B20F76C9CE90C5F5760DA3B7852B1AD28` / `4789` / `67` |
| `by-file\EPFTileContext.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-file\EPFTileContext.md --apply --queue-timeout 240 --wait-generated` | `000000025741`; `2026-08-17T18:36:18-04:00` | `0 / 1` | autogen_children_fallback_insert=6; autogen_children_marker_missing=72; autogen_emitter_has_no_code=59; autogen_header_children_marker_missing=2; autogen_header_emitter_has_no_code=1; autogen_header_noop=106 | `completed` | autogen_registry_rebuild=1; projected_stats_update=1; stats_incremental_noop=1; generated_metadata_refresh=275; autogen_header_metadata_refresh=160 | `757B56A7F6CDFC0668AF98A2973F87FAAB1E9826CC4F1BF2A30882AAC0C8D4D8` / `25033` / `209` |

Preliminary superseded receipts retained for no-loss history:

| Path | Exact cwd / single-line command | command_id / timestamp | Exit / ok | Command-specific warnings or errors | Generated refresh | Relevant validator-owned side effects | Final physical SHA256 / bytes / lines |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `by-class\EPFTileContext.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-class\EPFTileContext.md --apply --queue-timeout 240` | `000000025647`; `2026-08-17T18:07:00-04:00` | `0 / 1` | none | `deferred` | completion_update=1; confidence_update=1; autogen_registry_update=2; uid_link_update=1; projected_stats_update=1; stats_incremental_noop=1 | `0D3A5C0B666E32CC5706CDA71CC7D5150DB534DCE84767BC3F4B6A11ABC4A5F3` / `30749` / `284` |
| `by-memory\0x00457a60-0x00458610.EPFTileContext.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00457a60-0x00458610.EPFTileContext.md --apply --queue-timeout 240` | `000000025648`; `2026-08-17T18:07:02-04:00` | `0 / 1` | none | `deferred` | completion_update=1; confidence_update=1; autogen_registry_update=3; uid_link_update=2; projected_stats_update=1; stats_incremental_noop=1 | `22D4DBB4FBA815A34B43C6E59A885EB4645CA70AAFDE9BB1AE37997DF47121B6` / `39566` / `577` |
| `by-memory\0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md --apply --queue-timeout 240` | `000000025649`; `2026-08-17T18:07:05-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; uid_link_update=4; reference_index_add=1; projected_stats_update=1; stats_incremental_noop=1 | `80D291E3F8EAA55EE652C560E539815A6190E37EB3C53BCA0AC78596092598F3` / `15051` / `165` |
| `by-memory\0x00458590-0x00458610.EPFTileContextPixelRangeTest.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x00458590-0x00458610.EPFTileContextPixelRangeTest.md --apply --queue-timeout 240` | `000000025650`; `2026-08-17T18:07:08-04:00` | `0 / 1` | none | `deferred` | autogen_registry_update=1; uid_link_update=2; reference_index_add=1; projected_stats_update=1; stats_incremental_noop=1 | `E9D93D9C2046F0EDF2328F43E7174C56AE7FE3F125980AECF5AE9E4022243B3F` / `17864` / `159` |
| `by-memory\0x004b7ca0-0x004b7cb6.RectArea.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x004b7ca0-0x004b7cb6.RectArea.md --apply --queue-timeout 240` | `000000025651`; `2026-08-17T18:07:11-04:00` | `0 / 1` | none | `deferred` | completion_update=1; confidence_update=1; autogen_registry_update=2; projected_stats_update=1; stats_row_remove=1; stats_rescore_recommended=1 | `56CFDD094251F0DB679A3B8C85175949C78072818181499D39FE5DBF5A728E06` / `8002` / `81` |
| `by-memory\0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md --apply --queue-timeout 240` | `000000025652`; `2026-08-17T18:07:13-04:00` | `0 / 1` | none | `deferred` | completion_update=1; confidence_update=1; autogen_registry_update=2; projected_stats_update=1; stats_incremental_noop=1 | `0F6BCCF543E30D4015E3E4EC9D13EEE1BBAC561E72EDF8F95AF4704B4117ABED` / `16456` / `146` |
| `by-memory\0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory\0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags.md --apply --queue-timeout 240` | `000000025653`; `2026-08-17T18:07:16-04:00` | `0 / 1` | none | `deferred` | completion_update=1; confidence_update=1; autogen_registry_update=2; projected_stats_update=1; stats_incremental_noop=1 | `B3BFAB3BFF10C6C78AE9FD8520D8C331E7230BB256C27AB9836FB5366EEEA011` / `19985` / `144` |
| `by-file\RectBounds.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-file\RectBounds.md --apply --queue-timeout 240` | `000000025654`; `2026-08-17T18:07:19-04:00` | `0 / 1` | missing_ref_uid=4 (00040U) | `deferred` | uid_link_update=1; projected_stats_update=1; stats_row_update=1 | `940F25AB900FE3BC48CCFF9F547B3EEB019A655FC2932B2736A3A9E82E1C2763` / `30320` / `161` |
| `by-file\SoftwareBlend16.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-file\SoftwareBlend16.md --apply --queue-timeout 240` | `000000025655`; `2026-08-17T18:07:21-04:00` | `0 / 1` | none | `deferred` | uid_link_update=2; projected_stats_update=1; stats_incremental_noop=1 | `69B8B1AC9B4649A0806F4A4F3560EE91A50BC1392B0A6CCB878D24D3DF3A3207` / `46949` / `240` |
| `by-file\Surface.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-file\Surface.md --apply --queue-timeout 240` | `000000025656`; `2026-08-17T18:07:33-04:00` | `0 / 1` | missing_ref_uid=12 (00039R, 0003XE, ------) | `deferred` | uid_link_update=2; reference_index_add=1; projected_stats_update=1; stats_incremental_noop=1 | `933982A59172643F4431DCC87E213A64ADBBAC1A5E9C67E5D1EF5439EE2642CE` / `144336` / `625` |
| `by-file\EPFTileContext.md` | `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-file\EPFTileContext.md --apply --queue-timeout 240 --wait-generated` | `000000025730`; `2026-08-17T18:29:44-04:00` | `0 / 1` | autogen_children_fallback_insert=6; autogen_children_marker_missing=72; autogen_emitter_has_no_code=59; autogen_header_children_marker_missing=2; autogen_header_emitter_has_no_code=1; autogen_header_noop=106 | `completed` | completion_update=1; confidence_update=1; autogen_registry_rebuild=1; uid_link_update=7; reference_index_add=2; projected_stats_update=1; stats_incremental_noop=1; generated_metadata_refresh=274; autogen_header_metadata_refresh=160; research_tracker_update=1 | `757B56A7F6CDFC0668AF98A2973F87FAAB1E9826CC4F1BF2A30882AAC0C8D4D8` / `25033` / `209` |
## Changed Files

- Created: none.
- Modified: 76 exact paths: one ordinary target, ten ordinary core/support files, 64 ordinary constructor-consumer files, and this report. Current physical reread found all 75 ordinary paths and the report present; the complete self-contained inventory follows.

| Modified classification | Exact path |
| --- | --- |
| ordinary target | `by-file\EPFTileContext.md` |
| ordinary core/support | `by-class\EPFTileContext.md` |
| ordinary core/support | `by-memory\0x00457a60-0x00458610.EPFTileContext.md` |
| ordinary core/support | `by-memory\0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md` |
| ordinary core/support | `by-memory\0x00458590-0x00458610.EPFTileContextPixelRangeTest.md` |
| ordinary core/support | `by-memory\0x004b7ca0-0x004b7cb6.RectArea.md` |
| ordinary core/support | `by-memory\0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md` |
| ordinary core/support | `by-memory\0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags.md` |
| ordinary core/support | `by-file\RectBounds.md` |
| ordinary core/support | `by-file\SoftwareBlend16.md` |
| ordinary core/support | `by-file\Surface.md` |
| ordinary constructor consumer | `by-memory\0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md` |
| ordinary constructor consumer | `by-class\InventoryPane.md` |
| ordinary constructor consumer | `by-memory\0x0045df90-0x0045ea13.RankingRewardInfoDialogOnPaint.md` |
| ordinary constructor consumer | `by-memory\0x00467510-0x0046782f.BackGroundPaneCoreMethods.md` |
| ordinary constructor consumer | `by-memory\0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md` |
| ordinary constructor consumer | `by-memory\0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint.md` |
| ordinary constructor consumer | `by-memory\0x00481750-0x00481a72.ChattingVarietySelectPaneDrawBorder.md` |
| ordinary constructor consumer | `by-memory\0x004816d0-0x00481741.ChattingVarietySelectPaneSetupBackground.md` |
| ordinary constructor consumer | `by-memory\0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md` |
| ordinary constructor consumer | `by-memory\0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables.md` |
| ordinary constructor consumer | `by-memory\0x00498270-0x004984bc.PopupMenuControlPaneOnDraw.md` |
| ordinary constructor consumer | `by-memory\0x00499310-0x004993a5.EPFImageControlPaneOnPaint.md` |
| ordinary constructor consumer | `by-memory\0x00499a50-0x00499be7.NumericStringControlPaneRenderNumericString.md` |
| ordinary constructor consumer | `by-memory\0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md` |
| ordinary constructor consumer | `by-memory\0x0049db60-0x0049dc05.DialogPaneSetBackgroundResource.md` |
| ordinary constructor consumer | `by-memory\0x0049f1d0-0x0049f2d4.DialogPaneDrawBackground.md` |
| ordinary constructor consumer | `by-memory\0x0049f2e0-0x0049f912.DialogPaneDrawBorder.md` |
| ordinary constructor consumer | `by-memory\0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md` |
| ordinary constructor consumer | `by-memory\0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md` |
| ordinary constructor consumer | `by-memory\0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md` |
| ordinary constructor consumer | `by-memory\0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md` |
| ordinary constructor consumer | `by-memory\0x004cf300-0x004cf3d3.IconsPaneOnPaint.md` |
| ordinary constructor consumer | `by-memory\0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md` |
| ordinary constructor consumer | `by-memory\0x004dc7e0-0x004dca14.RidingImageLibRenderRiding.md` |
| ordinary constructor consumer | `by-memory\0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot.md` |
| ordinary constructor consumer | `by-memory\0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability.md` |
| ordinary constructor consumer | `by-memory\0x004ebb20-0x004ec913.NewInventoryPaneOnPaint.md` |
| ordinary constructor consumer | `by-memory\0x004ee6f0-0x004eee5c.InventoryPane2OnPaint.md` |
| ordinary constructor consumer | `by-memory\0x004f4c10-0x004f4eac.LogoPaneConstructor.md` |
| ordinary constructor consumer | `by-memory\0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md` |
| ordinary constructor consumer | `by-memory\0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md` |
| ordinary constructor consumer | `by-memory\0x004ff400-0x004ff644.ScrolledTextControlPaneForMadeByConstructor.md` |
| ordinary constructor consumer | `by-memory\0x004ffd80-0x0050008b.HistoryViewingPaneCore.md` |
| ordinary constructor consumer | `by-memory\0x00500700-0x00500797.GenderButtonControlPaneOnPaint.md` |
| ordinary constructor consumer | `by-memory\0x00500820-0x005008b9.DirectionButtonControlPaneOnPaint.md` |
| ordinary constructor consumer | `by-memory\0x00501360-0x0050158a.UserHairSelectControlPaneOnPaintFrame.md` |
| ordinary constructor consumer | `by-memory\0x00501840-0x00501a6a.UserFaceSelectControlPaneOnPaintFrame.md` |
| ordinary constructor consumer | `by-memory\0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md` |
| ordinary constructor consumer | `by-memory\0x005031f0-0x005032c3.MapNamePaneConstructor.md` |
| ordinary constructor consumer | `by-memory\0x00538c50-0x00538cfa.BowGaugeObjectPaneOnPaint.md` |
| ordinary constructor consumer | `by-memory\0x00545170-0x00545e3b.EditablePaperPane.md` |
| ordinary constructor consumer | `by-memory\0x00546890-0x0054696f.ParcelPaneOnPaint.md` |
| ordinary constructor consumer | `by-memory\0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md` |
| ordinary constructor consumer | `by-memory\0x005552f0-0x00555361.RightButtonMenuPaneDrawSubwinBackground.md` |
| ordinary constructor consumer | `by-memory\0x00555370-0x00555692.RightButtonMenuPaneDrawSubwinBorder.md` |
| ordinary constructor consumer | `by-memory\0x00555c70-0x00555ce1.VoteMenuPaneDrawBackground.md` |
| ordinary constructor consumer | `by-memory\0x00555cf0-0x00556012.VoteMenuPaneDrawBorder.md` |
| ordinary constructor consumer | `by-memory\0x0055f890-0x0055ff70.ScrollSpellInventoryPaneOnPaint.md` |
| ordinary constructor consumer | `by-memory\0x005636a0-0x00563d80.ScrollInventoryPaneOnPaint.md` |
| ordinary constructor consumer | `by-memory\0x00567480-0x00568bd0.SelfLookPaneOnPaint.md` |
| ordinary constructor consumer | `by-memory\0x00569d80-0x00569ec1.SelfLookPaneDrawNumberString.md` |
| ordinary constructor consumer | `by-memory\0x0056ce50-0x0056da03.NewGroupPaneOnPaint.md` |
| ordinary constructor consumer | `by-memory\0x0056edc0-0x0056f655.CollectionPaneOnPaint.md` |
| ordinary constructor consumer | `by-memory\0x0056fdd0-0x0056fe41.CollectionPane2OnPaint.md` |
| ordinary constructor consumer | `by-memory\0x00570fc0-0x00571c05.SelfLookPane2OnPaint.md` |
| ordinary constructor consumer | `by-memory\0x005726a0-0x00572771.SelfLookPane2DrawStatText.md` |
| ordinary constructor consumer | `by-memory\0x0057d430-0x0057d8c4.NewSpellInventoryPaneOnPaint.md` |
| ordinary constructor consumer | `by-memory\0x00598cc0-0x00598ecf.TotemFrame.md` |
| ordinary constructor consumer | `by-memory\0x005992f0-0x005993a5.TransferServerDialogPaneOnPaint.md` |
| ordinary constructor consumer | `by-memory\0x0059df50-0x0059e0ac.CheckBoxTextControlPaneOnPaint.md` |
| ordinary constructor consumer | `by-memory\0x0059e710-0x0059e899.UserListPaneConstructor.md` |
| ordinary constructor consumer | `by-memory\0x0059f260-0x0059f4fd.UserLookPaneConstructor.md` |
| ordinary constructor consumer | `by-memory\0x005a0640-0x005a157d.UserLookPaneOnDraw.md` |
| ordinary constructor consumer | `by-memory\0x005c2230-0x005c2340.SwallowLayerPaneConstructor.md` |
| report | `tools/leaser/Agents/Agent-B002/research/0000J4-EPFTileContext-file-source-quality.md` |

- Renamed: none.
- Dated 2026-08-17 same-report Gate 1 repair history: the earlier A05/A06/C027 cycle established the deterministic raw-body no-change disposition; the later report-only repair cycle normalized lifecycle authority, canonical claim values/single-UID rows, A10's current return type, literal protected sets, and all eleven public rename schemas in Sections 2/11/21/23/27/29/30/32/33. Ordinary implementation, formal source, coverage text, scores, generated readback, and validator receipts were preserved.
- Dated 2026-08-17 Gate 2B fail-closed and report-repair history: A01/A02 passed only in the discarded unsaved transaction; A03 exposed the exact public `inspect_items` `void *` to `MemoryMan *` presentation convergence. No IDB was saved. The same-report repair added fresh canonical persisted-TInfo/Hex-Rays/public-presentation evidence and literal row-specific poststates without changing ordinary documentation or formal source.
- Dated 2026-08-17 second Gate 2B fail-closed and report-repair history: in canonical session `supervisor_uid0002ox_persistverify_20260817`, A01 changed the persisted/public symbol and preserved the public type, but immediate Hex-Rays retained its cached old-name header because `pure:true` skipped decompiler refresh. Supervisor stopped before A02, rolled A01 back, saved no failed mutation, and verified canonical disk SHA256 `7525449D0F3389BC5CB63FFD18574ACD27F381EB7D5367192204113374415E3F`, 143,210,606 bytes. This report-only repair separated literal persisted-IDB, public-API, and immediate-decompiler poststates for all eleven renames; the 76-path Modified inventory and every prior Gate 2A receipt remain unchanged.
- Validator-owned generated side effects: already-present receipt effects, not direct B002 edits: `autogen_registry_update`, `autogen_registry_rebuild`, `generated_metadata_refresh`, and `autogen_header_metadata_refresh`; the physically reread outputs are `auto-generated/NexusTK/render/EPFTileContext.cpp` and `auto-generated/NexusTK/render/EPFTileContext.h`.
- Validator-owned index side effects: already-present receipt effects, not direct B002 edits: `uid_link_update` and `reference_index_add`.
- Validator-owned stat side effects: already-present receipt effects, not direct B002 edits: `projected_stats_update`, `stats_incremental_noop`, `stats_row_remove`, `stats_row_update`, and `stats_rescore_recommended`.
- Validator-owned tracker side effects: already-present receipt effect, not a direct B002 edit: `research_tracker_update`.
- Validator-owned ordinary-metadata receipt effects: `completion_update` and `confidence_update`; these dated validator effects are already reflected in current ordinary documentation and do not create or rename files.
- Direct B002 edits to generated/manual coverage/IDA/tracker/audit/catalog/lifecycle files: none. The actor for every generated/index/stat/tracker effect above was the validator under the dated Section 31 commands; this section records those historical side effects without asserting or changing current validator/lifecycle state.
- Report lifecycle boundary: current execution/archive status is supervisor-owned and authoritative only from the artifact's current path and validator-owned status/history metadata. This prose makes no current execution/archive assertion.
- Lease fact: short ordinary-file leases were used for the core/support and each consumer edit/validator batch. The ten core/support validators were freshly repeated under per-file leases after the initial batch lease expired; the final owner validator was repeated afterward. Every B002 lease was released immediately, and the final lease report contains no active B002 row.

## Implementation Tracking Checklist

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C001 | 0000J4 | Record the exact whole-file inventory: 13 authored bodies, 12 internal all-cc padding intervals, six compiler-only EH items, two owned types, five dependency groups, three excluded boundary items, and no owned global/string/table/vtable/RTTI/resource/import item. | very-high | bounded IDA entities, bytes, boundaries, xrefs, types, generated/source routing | `by-file/EPFTileContext.md inventory` | incorporate | applied |
| [x] | C002 | 0000J4 | Record every authored range, size, current IDA identity/type, exact SHA256, frame, comment-channel disposition, and inbound/outbound xref route. | very-high | live read-only MCP body inventory and exact raw-byte hashes | `by-file/EPFTileContext.md evidence` | incorporate | applied |
| [x] | C003 | 0000J4 | Classify all twelve internal gaps as exact all-cc alignment and exclude predecessor 0x457960, boundary padding 0x457a5d, and successor 0x458610. | very-high | bounded bytes and neighboring function ranges | `by-file/EPFTileContext.md boundaries` | incorporate | applied |
| [x] | C004 | 0000J4 | Correct 0x457a60 from ordinary Initialize to the default EPFTileContext constructor and record EAX=this, 337 construction xrefs, automatic/member sites, and new-expression cleanup evidence. | very-high | decompile, disassembly, exact xref set, EH routes | `target/class/aggregate constructor sections` | reject-stale | applied |
| [x] | C005 | 0000J4 | Record that no destructor body exists and EPFTileContext__ReleaseBuffers is explicit ownership cleanup with 71 call xrefs, not an implicit destructor. | very-high | scope-exit routes, 71-xref set, release body | `target/class/aggregate lifetime sections` | reject-stale | applied |
| [x] | C006 | 0000J4 | Reconstruct indexed and RGB16 encoded-mask behavior including fixed 100000-byte scratch, 127-byte run cap, zero row terminators, conditional count reset, byte/word transparency tests, and exact allocation/move flow. | high | 0x457ab0 and 0x457c60 decompile/disassembly correspondence | `aggregate formal CPP and behavior` | incorporate | applied |
| [x] | C007 | 0000J4 | Reconstruct generic deep copy and retained RGB16 deep-copy specialization; preserve pixel/alpha byte-count distinctions, mask copy, and explicit destination release. | high | 0x457e00 branch family and raw 0x457f30 body | `aggregate formal CPP and liveness` | incorporate | applied |
| [x] | C008 | 0000J4 | Reconstruct generic and retained RGB16 half-scale decimation, exact RectArea allocation, EH cleanup, and the observed constructor-default Indexed8 format quirk in RGB16 results. | high | 0x457ff0/0x458260 bodies, EH chunks, allocations | `aggregate formal CPP and behavior` | incorporate | applied |
| [x] | C009 | 0000J4 | Reconstruct the three allocation methods and explicit ReleaseBuffers with exact MemoryMan ownership, area/stride fields, and pointer resets. | high | 0x4583d0-0x458557 bodies and caller routes | `aggregate formal CPP and lifetime` | incorporate | applied |
| [x] | C010 | 000200 | Preserve the accepted normalization body and record its exact RGB565 flag and conversion-helper dependency; add no duplicate source. | very-high | current child source and 0x458560 read/call route | `UID000200 source/dependency prose` | already-present | already-present |
| [x] | C011 | 000201 | Preserve the accepted indexed-range query body and Palette friendship/type route; add no duplicate source. | very-high | current child source and 0x458590 behavior | `UID000201 source/dependency prose` | already-present | already-present |
| [x] | C012 | 0000J4 | Classify both EH code chunks and four EH data records as compiler-covered no-code with exact ranges, widths, hashes, associations, absent comments, and no authored emission. | very-high | bounded MCP bytes/entities/xrefs | `target/aggregate compiler inventory` | not-applicable | excluded-with-reason |
| [x] | C013 | 0000J4 | Record the exhaustive negative inventory for file-owned globals, statics, constants, strings, tables, vtables, RTTI, resources, and imports. | high | bounded entity/string/type/generated searches | `by-file/EPFTileContext.md negative evidence` | incorporate | applied |
| [x] | C014 | 0000J4 | Preserve file owner UID0000J4, class emitter UID00004I, aggregate UID0000XY, and exact children UID000200/UID000201; reject new-owner and split-unit alternatives. | very-high | current routing plus contiguous behavior family | `target/class/aggregate ownership` | already-present | already-present |
| [x] | C015 | 0000XY | Set deterministic source order: aggregate position 0, UID000200 position 10, UID000201 position 20; private helpers remain inside aggregate source. | high | address order and existing child emission model | `aggregate and child metadata` | incorporate | applied |
| [x] | C016 | 0000J4 | Replace the current empty generated CPP route with the complete 13-definition source topology and require no empty marker, duplicate body, stub, TODO, or placeholder. | high | dated generated CPP hash/physical read and Section 22 source | `target/class/aggregate formal CPP` | reject-stale | applied |
| [x] | C017 | 00004I | Replace the incomplete generated H route with the exact 0x28 class API and required RectBounds, Palette, SoftwareBlend16, Surface, and MemoryMan dependencies. | high | dated generated H hash, type layout, call graph | `class formal H and dependency topology` | reject-stale | applied |
| [x] | C018 | 00004I | Set formal class CPP to exact includes plus [[CHILDREN]] in Section 22. | high | source topology and complete-type requirements | `by-class/EPFTileContext.md formal CPP` | incorporate | applied |
| [x] | C019 | 00004I | Set formal class H to the complete Section 22 enum/class declaration with constructor, no destructor, public API, private helpers, and exact seven-field layout. | high | IDA UDT, body accesses, caller behavior | `by-class/EPFTileContext.md formal H` | incorporate | applied |
| [x] | C020 | 0000XY | Set formal aggregate CPP to the exact eleven authored definitions in Section 22, leaving the two accepted tail children to child emission. | high | all 13 bodies and existing child split | `by-memory/0x00457a60-0x00458610.EPFTileContext.md formal CPP` | incorporate | applied |
| [x] | C021 | 000200 | Preserve the accepted UID000200 child CPP body exactly and keep its formal H channel blank. | very-high | physical current child doc and generated topology | `UID000200 formal channels` | already-present | already-present |
| [x] | C022 | 0000J4 | Record exact include/declaration topology and complete-type dependencies for RectBounds, Palette, SoftwareBlend16, Surface, and MemoryMan. | high | formal source compile dependencies and current headers | `target/class/aggregate documentation` | incorporate | applied |
| [x] | C023 | 00015T | Add exact H declaration int RectArea(const RectBounds *bounds); and record the two EPFTileContext half-scale callers. | high | 0x4b7ca0 type/body plus 0x457ff0/0x458260 calls | `by-memory/0x004b7ca0-0x004b7cb6.RectArea.md formal H` | incorporate | applied |
| [x] | C024 | 0003ZP | Add exact H declaration void ConvertRgb565ToRgb555Pixels(unsigned short *pixels, int pixelCount); and preserve the exact 0x7ff0 conversion quirk. | high | 0x4bb0e0 type/body and 0x458560 call | `by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md formal H` | incorporate | applied |
| [x] | C025 | 00029U | Add only extern bool g_surfaceUsesRgb565Pixels; to formal H; retain g_surfaceUses32BitPresentation as file-static. | high | data xrefs, generated Surface source, cross-TU 0x458560 read | `by-memory/0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags.md formal H` | incorporate | applied |
| [ ] | C026 | 0000J4 | Apply only staged A01-A04 pure function renames after literal prestates, then require each exact new persisted IDB name and unchanged persisted TInfo, each exact new public `inspect_items` symbol and row-specific public type, and each exact cached pre-rename immediate Hex-Rays function-name/prototype; at A03 permit only the enumerated public presentation convergence to `MemoryMan *`, and hard-stop every other delta. | high | Section 21 exact ranges, hashes, separated persisted/public/decompiler channels, frames, comments, xrefs, protections | `IDA A01-A04` | incorporate | proposed |
| [ ] | C027 | 0000J4 | Verify A05's exact no-change disposition for raw 0x457f30 across persisted-TInfo, Hex-Rays, and public-presentation channels, invoke no A06 endpoint, then apply A07-A13 pure renames in dependency order with each exact new persisted/public symbol, unchanged persisted/public type, exact cached pre-rename immediate Hex-Rays function-name/prototype, and item-specific hard stops; A07's structural callee identity protects 0x457a60 as post-A01 EPFTileContext__EPFTileContext. | high | raw bytes and Section 21 literal no-change/action/separated presentation stages | `IDA A05/A06/A07-A13` | incorporate | proposed |
| [ ] | C028 | 0000J4 | Enforce P01-P05 no-delta protections for ReleaseBuffers, EH items, UDTs/dependencies, padding/neighbors, bytes/xrefs, and every non-owned field. | very-high | literal Section 21 protection rows | `IDA P01-P05` | incorporate | proposed |
| [x] | C029 | 0000J4 | Update target source-quality prose and score from 89/86 to 94/94 while preserving path NexusTK/render, FILE ownership, and lifecycle-neutral dated generated receipts. | high | complete blocker closure and exact current metadata | `by-file/EPFTileContext.md` | incorporate | applied |
| [x] | C030 | 0002DL | Remove the stale explicit default-constructor call expressions boardFrame.Initialize(), itemScratch.Initialize(), glyphScratch.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 9C34E222A55134C3E116D86FB5E58C884D572831884FBB9A04BE6E1184A723FA | `by-memory\0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md` | reject-stale | applied |
| [x] | C031 | 00006R | Remove the stale explicit default-constructor call expressions background.Initialize(), buttonFrame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 0018E7DC596593AA3C76F55EF2817ABBD2799E5E277DAC533057627D077E1BB9 | `by-class\InventoryPane.md` | reject-stale | applied |
| [x] | C032 | 0004IA | Remove the stale explicit default-constructor call expressions frame.Initialize(), frame.Initialize(), frame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 4F856550821F9ABD325751A9406EA413AA0D7AF70F17B0422A8438C50D69FEAC | `by-memory\0x0045df90-0x0045ea13.RankingRewardInfoDialogOnPaint.md` | reject-stale | applied |
| [x] | C033 | 00030L | Remove the stale explicit default-constructor call expressions m_backgroundTileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 284CB50669A32422C4570B4C8769DF5C81B520CFAA9185A8A406D493F8008748 | `by-memory\0x00467510-0x0046782f.BackGroundPaneCoreMethods.md` | reject-stale | applied |
| [x] | C034 | 0002F9 | Remove the stale explicit default-constructor call expressions tile.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 1900E872D38A15C05704690AC52764C2ED9C08B4FF3B5CEE249CE3E912A47B89 | `by-memory\0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md` | reject-stale | applied |
| [x] | C035 | 0002FD | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 074982DE1F769DC4F45245AB4420CEE5AE4869D51F5D5861CF689E696843FB43 | `by-memory\0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint.md` | reject-stale | applied |
| [x] | C036 | 0002FO | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 08AABDEFF9B390ED50B8187479C550CA3CE7432713902CD15FFA73D751CC803C | `by-memory\0x00481750-0x00481a72.ChattingVarietySelectPaneDrawBorder.md` | reject-stale | applied |
| [x] | C037 | 0002FN | Remove the stale explicit default-constructor call expressions tile.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 115CD0B6CAEC0A01AB86BF0D88F112B2F6865D01C2430AB24B4EFD200825093C | `by-memory\0x004816d0-0x00481741.ChattingVarietySelectPaneSetupBackground.md` | reject-stale | applied |
| [x] | C038 | 0002FU | Remove the stale explicit default-constructor call expressions tile.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 693BD5DE28A21C59D107CEC328AFE16D75E321F458A864EB2A9122EA4F6BC5C6 | `by-memory\0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md` | reject-stale | applied |
| [x] | C039 | 0002GH | Remove the stale explicit default-constructor call expressions unusedContext.Initialize(), background.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 32D1551F40A60EC5CCBB53A94A2939DF45CCA37CF52132D50FD9281A4E300AE3 | `by-memory\0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables.md` | reject-stale | applied |
| [x] | C040 | 0004IU | Remove the stale explicit default-constructor call expressions leftTile.Initialize(), centerTile.Initialize(), rightTile.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 B291D91FBC3970D94ED0FA238538B426929038BC64ABE87E7177BDB39B5ECAAB | `by-memory\0x00498270-0x004984bc.PopupMenuControlPaneOnDraw.md` | reject-stale | applied |
| [x] | C041 | 0004JW | Remove the stale explicit default-constructor call expressions frame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 CB43626DC5AC538E830C3A08150EE1DE7D6CC954A4D5BDA58328AD0B847A242D | `by-memory\0x00499310-0x004993a5.EPFImageControlPaneOnPaint.md` | reject-stale | applied |
| [x] | C042 | 00011O | Remove the stale explicit default-constructor call expressions glyphContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 83DDCF926880B5B3C9B3B5B9234ADD0027B6CBC300B3D03BDBD1CB0EDB1F6B9B | `by-memory\0x00499a50-0x00499be7.NumericStringControlPaneRenderNumericString.md` | reject-stale | applied |
| [x] | C043 | 00011S | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 6516DB23190B4E528A426F34571B4FA906B781FFE2E779D6D5CA96CC91BC2E06 | `by-memory\0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md` | reject-stale | applied |
| [x] | C044 | 0003KG | Remove the stale explicit default-constructor call expressions sourceContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 1E926142248B605C4841805EEC732DB6B573AC1EC92D8CC87A4BC5E1EF10AF5C | `by-memory\0x0049db60-0x0049dc05.DialogPaneSetBackgroundResource.md` | reject-stale | applied |
| [x] | C045 | 0004SW | Remove the stale explicit default-constructor call expressions frame.Initialize(), frame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 3E6F1714585A6551B4397DD1F9A3E58B3FCEAB1B961F7CB2230B83E0AA0FE975 | `by-memory\0x0049f1d0-0x0049f2d4.DialogPaneDrawBackground.md` | reject-stale | applied |
| [x] | C046 | 0004SX | Remove the stale explicit default-constructor call expressions frame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 10540A622191EFCFD9D89094D5A8B139E36B7922CDE34445258E0FF922C2A623 | `by-memory\0x0049f2e0-0x0049f912.DialogPaneDrawBorder.md` | reject-stale | applied |
| [x] | C047 | 0002HF | Remove the stale explicit default-constructor call expressions sellItemTile.Initialize(), itemGlyphContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 509D2664270081CE5D6D56BB29A99FE45ACF991094154D1F438F9B495254B4AC | `by-memory\0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md` | reject-stale | applied |
| [x] | C048 | 0004A0 | Remove the stale explicit default-constructor call expressions itemContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 EC50AEEEE4088D7A78326DAB8523B9201C82E23A4A85D9CAD619FCF7755A92FE | `by-memory\0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md` | reject-stale | applied |
| [x] | C049 | 0002JQ | Remove the stale explicit default-constructor call expressions tileContext.Initialize(), tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 2FDF5B9026ECA3A2248BBD0AE6DA7DA1624E7293DF4B422ABA625A379291C26F | `by-memory\0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md` | reject-stale | applied |
| [x] | C050 | 00016I | Remove the stale explicit default-constructor call expressions glyphContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 F2EA95FB5625FC0B68E7D43775F17196747CAC3F4C4C9BD70023C3CA58E573F1 | `by-memory\0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md` | reject-stale | applied |
| [x] | C051 | 0002T1 | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 E0250EA5AA55C61F5CF54C770B4E2DD17F8A272A23A26C01E8D9B8C4DE5A63A6 | `by-memory\0x004cf300-0x004cf3d3.IconsPaneOnPaint.md` | reject-stale | applied |
| [x] | C052 | 0002KR | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 4623FAE460485A5AFA65AB0CCD86B3A5570A38C591B439E619C3628B65DBB876 | `by-memory\0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md` | reject-stale | applied |
| [x] | C053 | 0002Y1 | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 0416F08C76A96252D553BA2B253B465A01C42F9243F514F01F9EC3DA7C1799FA | `by-memory\0x004dc7e0-0x004dca14.RidingImageLibRenderRiding.md` | reject-stale | applied |
| [x] | C054 | 00041S | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 528C3C7626FF8BDDA180DC9FAF0E66A1B66A66CA7BD36B368C201A20E3912D45 | `by-memory\0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot.md` | reject-stale | applied |
| [x] | C055 | 0003ND | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 2F43FBC0660ECE840AAC3B8517CDF72389128AAD9C65F37014AB5ACEB2DE5B21 | `by-memory\0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability.md` | reject-stale | applied |
| [x] | C056 | 00053Y | Remove the stale explicit default-constructor call expressions background.Initialize(), button.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 1686FBF6213A18AA3C78FF3C33A5F0836CA426C02E2276F6B1720954E6BABD89 | `by-memory\0x004ebb20-0x004ec913.NewInventoryPaneOnPaint.md` | reject-stale | applied |
| [x] | C057 | 00048S | Remove the stale explicit default-constructor call expressions frame.Initialize(), buttonFrame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 D589954CB4AB1A0025B9A7DFBA3956D78256AF59388B19B38696220B391A2441 | `by-memory\0x004ee6f0-0x004eee5c.InventoryPane2OnPaint.md` | reject-stale | applied |
| [x] | C058 | 0002PL | Remove the stale explicit default-constructor call expressions m_logoTileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 1C1C411C9CC06E9B50096EA5A7F4F262384836716DDE233F75F23FB39DE79BE2 | `by-memory\0x004f4c10-0x004f4eac.LogoPaneConstructor.md` | reject-stale | applied |
| [x] | C059 | 0002Q8 | Remove the stale explicit default-constructor call expressions frameContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 20E9D4044DCA14C9E8E0844F5CA14FA1EE432C293B8B16945189FE7E3BF29A09 | `by-memory\0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md` | reject-stale | applied |
| [x] | C060 | 0002Q9 | Remove the stale explicit default-constructor call expressions frameContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 D6D637AAEEDA35D1EE82991B444B668C278EE4FFBCD9FBF81030B3C4FC7C592D | `by-memory\0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md` | reject-stale | applied |
| [x] | C061 | 0004MA | Remove the stale explicit default-constructor call expressions m_renderedText.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 72E604DFF65526F22A1D86AD8E550AE339E5752378891717A19015D9A6D68302 | `by-memory\0x004ff400-0x004ff644.ScrolledTextControlPaneForMadeByConstructor.md` | reject-stale | applied |
| [x] | C062 | 0001A1 | Remove the stale explicit default-constructor call expressions frame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 922ACA728F316E833F94555C9BF1E33A91FB937EA98D4DD9408ED5EC55FC5066 | `by-memory\0x004ffd80-0x0050008b.HistoryViewingPaneCore.md` | reject-stale | applied |
| [x] | C063 | 0004ZZ | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 A8CC5E19F9549E0C097E4ACED8E29279F0016A7D63166DF7F1E4C657A2730288 | `by-memory\0x00500700-0x00500797.GenderButtonControlPaneOnPaint.md` | reject-stale | applied |
| [x] | C064 | 00050I | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 B0B50DAE9FFDC199FCB9C502EA4FA5FABA9901150B3DC12A4DC9CA20BCA775B6 | `by-memory\0x00500820-0x005008b9.DirectionButtonControlPaneOnPaint.md` | reject-stale | applied |
| [x] | C065 | 0004OI | Remove the stale explicit default-constructor call expressions selectionFrame.Initialize(), partFrame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 DF514FE77451BDE20E1E5FB161DDC35A8FF7BBC8F68447B4849F21F929527C4F | `by-memory\0x00501360-0x0050158a.UserHairSelectControlPaneOnPaintFrame.md` | reject-stale | applied |
| [x] | C066 | 0004OO | Remove the stale explicit default-constructor call expressions selectionFrame.Initialize(), partFrame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 9F3F4A2B7259E869991C142F1F849F213B469CFCDBAC4511D71F0717B88C7480 | `by-memory\0x00501840-0x00501a6a.UserFaceSelectControlPaneOnPaintFrame.md` | reject-stale | applied |
| [x] | C067 | 0002BF | Remove the stale explicit default-constructor call expressions glyphContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 09924E122B131C4686D8E422DE0A5AD5F74282C2E6D4529F38E58014BA93F4CC | `by-memory\0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md` | reject-stale | applied |
| [x] | C068 | 0003XG | Remove the stale explicit default-constructor call expressions m_mapNameImage.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 3C92960E0BF09C49E4901E054C423E9C283DEE41E2F74236E21937FB8A567F9D | `by-memory\0x005031f0-0x005032c3.MapNamePaneConstructor.md` | reject-stale | applied |
| [x] | C069 | 0004VP | Remove the stale explicit default-constructor call expressions frame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 BEF7EFCD076EBF7CF75176FA8A9D2D71B231F0B2F73C62463206652CE8AFD8CA | `by-memory\0x00538c50-0x00538cfa.BowGaugeObjectPaneOnPaint.md` | reject-stale | applied |
| [x] | C070 | 0001EE | Remove the stale explicit default-constructor call expressions frames[index].Initialize(), frame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 808EEEC60B66098CEFA6B5861B69B08B317B425F6797B704626EC7F561B9CD2D | `by-memory\0x00545170-0x00545e3b.EditablePaperPane.md` | reject-stale | applied |
| [x] | C071 | 0002KG | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 1E36BA904DA48DB9B8ECB3D7E533291AF88CC3422257912A718A38E64878A7C1 | `by-memory\0x00546890-0x0054696f.ParcelPaneOnPaint.md` | reject-stale | applied |
| [x] | C072 | 0002KL | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 F2A5D26A5AB2D280B20654EDDE76759F30E25C81993418F5781C60E2133F4D6F | `by-memory\0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md` | reject-stale | applied |
| [x] | C073 | 0004FF | Remove the stale explicit default-constructor call expressions tile.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 828DD1FAE2428C6F7E69BF2707FCD4FD974598082B204D6914E74045259D8440 | `by-memory\0x005552f0-0x00555361.RightButtonMenuPaneDrawSubwinBackground.md` | reject-stale | applied |
| [x] | C074 | 0004FG | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 696D18011201C051FEE65FB0902E5A46C3B21A6495CD76380CB02B605135FD07 | `by-memory\0x00555370-0x00555692.RightButtonMenuPaneDrawSubwinBorder.md` | reject-stale | applied |
| [x] | C075 | 0002LV | Remove the stale explicit default-constructor call expressions tile.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 7CEDFB40DAC165F17231A751A16C9D8E9EC1DEFD07D6DB62E215D715136F9E3B | `by-memory\0x00555c70-0x00555ce1.VoteMenuPaneDrawBackground.md` | reject-stale | applied |
| [x] | C076 | 0002LW | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 AC35BD9A2F24DB83FE9B7DD81A836B5A568B50D6E32016E88FD763AE8939E001 | `by-memory\0x00555cf0-0x00556012.VoteMenuPaneDrawBorder.md` | reject-stale | applied |
| [x] | C077 | 00053J | Remove the stale explicit default-constructor call expressions tile.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 E7A3FFFCDC78B232BBA8B0C2F1A16C50D9C34707CF474E4581CCBE4A08B75981 | `by-memory\0x0055f890-0x0055ff70.ScrollSpellInventoryPaneOnPaint.md` | reject-stale | applied |
| [x] | C078 | 00051O | Remove the stale explicit default-constructor call expressions tile.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 CFBB107A045FCA174995D1E5CE3696310F28EE9732D2E22E86A10896ED78A977 | `by-memory\0x005636a0-0x00563d80.ScrollInventoryPaneOnPaint.md` | reject-stale | applied |
| [x] | C079 | 0003QN | Remove the stale explicit default-constructor call expressions tileContext.Initialize(), commaContext.Initialize(), offButtonContext.Initialize(), onButtonContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 D78CE67E370CFC46F2989E63071A98124493D682705B647CD19AD716A5258176 | `by-memory\0x00567480-0x00568bd0.SelfLookPaneOnPaint.md` | reject-stale | applied |
| [x] | C080 | 0003QU | Remove the stale explicit default-constructor call expressions glyphContext.Initialize(), symbolContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 5606B7D7865FE3CCF21FC262056C3D994B4497DCF309F3899B99E0AE8A533462 | `by-memory\0x00569d80-0x00569ec1.SelfLookPaneDrawNumberString.md` | reject-stale | applied |
| [x] | C081 | 0004Z5 | Remove the stale explicit default-constructor call expressions tileContext.Initialize(), commaFrame.Initialize(), barLeftCap.Initialize(), barRightCap.Initialize(), barFill.Initialize(), scratchContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 3E1F4113FD85CCB2F560A7556859E74D8D6118F14FCA845B498F98B41AA3E873 | `by-memory\0x0056ce50-0x0056da03.NewGroupPaneOnPaint.md` | reject-stale | applied |
| [x] | C082 | 0003Y6 | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 F8CC434023308050EA88CBC016980936F93C03FEC507B31794925F71D87A8AE6 | `by-memory\0x0056edc0-0x0056f655.CollectionPaneOnPaint.md` | reject-stale | applied |
| [x] | C083 | 0003YG | Remove the stale explicit default-constructor call expressions context.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 2F4B438E39C4737074B76B85F925FDA4CD3EE79978617BD32C025660EB2145F4 | `by-memory\0x0056fdd0-0x0056fe41.CollectionPane2OnPaint.md` | reject-stale | applied |
| [x] | C084 | 0003RB | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 21EEE4635413F37782FD2C76E0C3B8CDC71262EE87B7053B8D4F0A7126E58D13 | `by-memory\0x00570fc0-0x00571c05.SelfLookPane2OnPaint.md` | reject-stale | applied |
| [x] | C085 | 0003RF | Remove the stale explicit default-constructor call expressions glyphContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 E8579633C4FBB93A761C7DD4CA5EF9BD1BF24D154094709435C28037AFD13B88 | `by-memory\0x005726a0-0x00572771.SelfLookPane2DrawStatText.md` | reject-stale | applied |
| [x] | C086 | 00052O | Remove the stale explicit default-constructor call expressions background.Initialize(), button.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 E11DD7E3A6561399AFBF853ED309105FECB3EEAE9A8245750B4B4D8DADB4BD22 | `by-memory\0x0057d430-0x0057d8c4.NewSpellInventoryPaneOnPaint.md` | reject-stale | applied |
| [x] | C087 | 0001KC | Remove the stale explicit default-constructor call expressions tile.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 DC416151BE118B3B6DA76BC2320C95CDCEAC84F1CA7406FFC91AA974A92E09C1 | `by-memory\0x00598cc0-0x00598ecf.TotemFrame.md` | reject-stale | applied |
| [x] | C088 | 0004MZ | Remove the stale explicit default-constructor call expressions frame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 86EAC1E11C4F0FE1CE7ACD0DB52F1042B7452318DBC84D7D91F9B84D621B92DC | `by-memory\0x005992f0-0x005993a5.TransferServerDialogPaneOnPaint.md` | reject-stale | applied |
| [x] | C089 | 0003FG | Remove the stale explicit default-constructor call expressions uncheckedFrame.Initialize(), checkedFrame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 5213EB819786064C5057E3CF14762BC3CD6592F58E8372C8C873C3856B69EBF9 | `by-memory\0x0059df50-0x0059e0ac.CheckBoxTextControlPaneOnPaint.md` | reject-stale | applied |
| [x] | C090 | 00047H | Remove the stale explicit default-constructor call expressions m_statusIconFrames[index].Initialize(), m_badgeIconFrames[index].Initialize(), m_huntersListIconFrame.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 D06A6B5838BE6F33EC3F42C8F30016C1FD84378E12340E36EAAB8B7506DF9D12 | `by-memory\0x0059e710-0x0059e899.UserListPaneConstructor.md` | reject-stale | applied |
| [x] | C091 | 0003RI | Remove the stale explicit default-constructor call expressions m_portraitImage.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 FF99F1C4B62FBFEDBD037C6A9060071BE6027AE4E9562D719FF5DCC0D871477D | `by-memory\0x0059f260-0x0059f4fd.UserLookPaneConstructor.md` | reject-stale | applied |
| [x] | C092 | 0003RM | Remove the stale explicit default-constructor call expressions tileContext.Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 A5012F0F15F1C55DDEE842CE6CEEFFB9BF278C54D8BFCF15EFF62027E93BB1DC | `by-memory\0x005a0640-0x005a157d.UserLookPaneOnDraw.md` | reject-stale | applied |
| [x] | C093 | 00054K | Remove the stale explicit default-constructor call expressions m_swallowFrames[0].Initialize(), m_swallowFrames[1].Initialize() from formal CPP and correct only dependent prose that presents 0x457a60 as an ordinary Initialize method; preserve all unrelated source and metadata. | very-high | constructor identity, exhaustive formal search, pre-callback SHA256 CAF96D16960D41D5B00F58C0EEF869C5E3C187037775B3D5442D87FAFBFB250E | `by-memory\0x005c2230-0x005c2340.SwallowLayerPaneConstructor.md` | reject-stale | applied |
| [x] | C094 | 00004I | Rescore EPFTileContext class 88/90 to 94/94 after complete CPP/H, API, layout, lifetime, helper, and ordering closure. | high | complete class formal source and binary inventory | `by-class/EPFTileContext.md metadata` | incorporate | applied |
| [x] | C095 | 0000XY | Rescore EPFTileContext aggregate 88/91 to 94/94 after eleven definitions, 13-body inventory, retained/raw closure, and EH/padding proof. | high | whole-range reconstruction and split closure | `aggregate metadata` | incorporate | applied |
| [x] | C096 | 00015T | Rescore RectArea 86/90 to 88/92 after exact H declaration and EPFTileContext caller closure. | high | exact body/type and four-caller context | `RectArea metadata` | incorporate | applied |
| [x] | C097 | 0003ZP | Rescore ConvertRgb565ToRgb555Pixels 92/94 to 93/95 after exact H declaration and sole generated consumer dependency closure. | high | exact conversion body and call route | `conversion-helper metadata` | incorporate | applied |
| [x] | C098 | 00029U | Rescore SurfacePixelFormatFlags 88/93 to 90/94 after exact external-versus-static H disposition. | high | exact data xrefs and source ownership | `SurfacePixelFormatFlags metadata` | incorporate | applied |
| [x] | C099 | 0000J4 | Preserve UID000200/UID000201 scores and all owner/emitter/reconstructable/range/path fields not explicitly changed. | very-high | current metadata and accepted source | `target and support metadata` | already-present | already-present |
| [ ] | C100 | 0000J4 | Apply the exact UID0000J4 manual by-file coverage replacement from Section 28. | high | completed target recommendation | `by-file/-coverage-report.md` | incorporate | proposed |
| [ ] | C101 | 00004I | Apply the exact UID00004I manual by-class coverage replacement from Section 28. | high | completed class recommendation | `by-class/-coverage-report.md` | incorporate | proposed |
| [ ] | C102 | 0000XY | Apply the exact UID0000XY manual by-memory coverage replacement from Section 28. | high | completed aggregate recommendation | `by-memory/-coverage-report.md` | incorporate | proposed |
| [ ] | C103 | 00015T | Apply the exact UID00015T manual by-memory coverage replacement from Section 28. | high | completed RectArea recommendation | `by-memory/-coverage-report.md` | incorporate | proposed |
| [ ] | C104 | 0003ZP | Apply the exact UID0003ZP manual by-memory coverage replacement from Section 28. | high | completed conversion-helper recommendation | `by-memory/-coverage-report.md` | incorporate | proposed |
| [ ] | C105 | 00029U | Apply the exact UID00029U manual by-memory coverage replacement from Section 28. | high | completed Surface-flag recommendation | `by-memory/-coverage-report.md` | incorporate | proposed |
| [x] | C106 | 0000J4 | Run the exact path-bound scoped validator for each changed target/core-support by-* document from the stated cwd. | very-high | Section 31 exact command rows | `callback validator receipts` | incorporate | applied |
| [x] | C107 | 0000J4 | Run the exact path-bound scoped validators for RectBounds.md, SoftwareBlend16.md, Surface.md, and all changed dependency pages required by the UID0000J4 whole-file implementation. | very-high | Section 31 exact command rows | `callback validator receipts` | incorporate | applied |
| [x] | C108 | 0000J4 | Run one exact path-bound scoped validator for every changed constructor-consumer page required by the UID0000J4 constructor correction. | very-high | 64 Section 31 exact command rows | `callback validator receipts` | incorporate | applied |
| [x] | C109 | 0000J4 | Run the literal final UID0000J4 validator command with --wait-generated, then physically reread and hash generated EPFTileContext.cpp/.h against Section 22 and the defect checklist. | very-high | Section 31 final command and readback contract | `callback final generated readback` | incorporate | applied |
| [x] | C110 | 0000J4 | Record third-party source-import directive as not applicable; no identified external library source owns this unit. | very-high | ownership search and binary/source family | `report third-party disposition` | not-applicable | excluded-with-reason |
| [x] | C111 | 000201 | Preserve the accepted UID000201 child CPP body exactly and keep its formal H channel blank. | very-high | physical current child doc and generated topology | `UID000201 formal channels` | already-present | already-present |
READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000025813","destination_path":"executed-b-agent-research/B002/0000J4-EPFTileContext-file-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0000J4-EPFTileContext-file-source-quality.md","timestamp":"2026-08-17T23:40:06-04:00","uid":"0000J4"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
