** TARGET-REPORT-UID:0003AX **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003AX DialogFrameResourceStrings Ownership / Split Research


## Finalized Report / Current Recommendation

- Implemented result: UID0003AX is a `92/94` non-reconstructable, non-emitting physical `.rdata` parent; its exact 76-byte span is split into registered non-emitting children UID0004ST/UID0004SU/UID0004SV; and exact source is emitted by UID0004SW `DialogPane::DrawBackground`, UID0004SX `DialogPane::DrawBorder`, and UID0003KG `DialogPane::SetBackgroundResource`.
- Final disposition: the three source strings are `L"DLGFRAME.EPF"`, `L"PAL01.PAL"`, and `L"DLGFRAME.EPD"`. IDA's `GFRAME.EPF`, `L01.PAL`, and `GFRAME.EPD` views are interior suffixes with zero xrefs, not source declarations or aliases.
- Implementation state: all six pages were registered serially as UID0004ST through UID0004SY; every accepted target/support destination was updated and scoped-validated; R0-R7 have exact destination parity; final waited command `000000014326` generated the complete DialogPane class and one definition each for R4-R6.
- Confidence: very strong for bytes, boundaries, xrefs, method behavior, owner/source placement, package role, pooling explanation, and no-code disposition; strong for reconstructed original member spellings and the legacy `.EPD` payload history.

## Supporting Research

- Historical report-only phase: the Gate 1 artifact changed only this report and performed no ordinary edit or validator. The authorized callback subsequently changed the exact ordinary destinations listed under Changed Files through serial lease/edit/validate/release batches. B003 still made no manual coverage, generated, tracker, audit, supervisor, IDA, archive, or lifecycle edit.
- Mandatory MCP evidence was collected from fresh `idb_list` discovery of database `64c11373`, not inherited from an older session. Evidence-time `server_health` was `ok` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, with image base `0x00400000`, automatic analysis ready, Hex-Rays ready, strings cache ready, and 2,067 cached strings. Bounded target `get_bytes`, `lookup_funcs`, `xrefs_to`, `decompile`, `disasm`, `analyze_function`, and `int_convert` calls all succeeded.
- The current executable input named by MCP is `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, 2,679,296 bytes, PE32 x86.
- B004's executed UID0002NB report is support evidence only. It repaired UID0003AX's adjacent reverse link and recorded validator command `000000014171`; it did not research this string range's true starts, package roles, source literals, caller behavior, or code disposition.
- B015's executed ModelessDialogPane report proves only the predecessor vtable endpoint at `0x00618ce0`. It does not own or reconstruct this range.
- Historical report searches were run with `UID0003AX`, `0x00618ce0`, `DialogFrameResourceStrings`, `DLGFRAME.EPF`, and `DLGFRAME.EPD`:
  - `source-3/project-documentation/archived/**`: root is absent in the canonical tree.
  - `tools/leaser/Agents/Older-Research/**`: no match.
  - `tools/leaser/Agents/SpecialReports/**`: no match.
  - `executed-b-agent-research/**`: B004 UID0002NB contains only adjacent-link/current-page evidence; B015 UID00008K contains only predecessor-boundary evidence.
  - active B001-B005 `research/**`: no matching report.
- Current package evidence was independently parsed from `E:\NTK\Resources\NexusTK\Data\*.dat`; exact loose-file searches were also performed under `E:\NTK\Resources`.

## Target

- Target UID: `0003AX`.
- Target path: `by-memory/0x00618ce0-0x00618d2c.DialogFrameResourceStrings.md`.
- Historical queue/report row: `auto-generated/-ag-research-tracker.md`, by-memory not-covered reconstructable row `85/90`, direct report count zero before this report.
- Historical supervisor classification: reconstructable empty-emitter source-quality target requiring complete string/caller/source-form resolution.
- Implemented scores and parent state: `92/94`; owner none; reconstructable false; blank emitter/position/formal; `Nested:0`; physical parent UID000254.

## Current Target State

- Implemented target metadata: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional position and formal C++, `Nested:0`.
- UID0003AX now documents the exact physical/source ownership split and emits no marker or source. Registered children UID0004ST/UID0004SU/UID0004SV carry exact bytes, terminators, alignment, xrefs, package roles, pooling, and no-code proof.
- B003 waited command `000000014326` established the callback checkpoint. Read-only external validator-owned refreshes observed through command `000000014347` at `2026-07-16T16:09:49-04:00` preserve the same result: `DialogPane.cpp` contains zero UID0003AX/UID0004ST/UID0004SU/UID0004SV text or markers and one definition each for UID0003KG/UID0004SW/UID0004SX. Later unrelated validator epochs remain external and do not change the captured B003 callback proof.
- Historical stale assumptions were preserved and explicitly corrected:
  - `0x00618ce4 GFRAME.EPF`, `0x00618d00 L01.PAL`, and `0x00618d14 GFRAME.EPD` are listed as if they were separate strings.
  - `Nested:8` incorrectly advances the cumulative address-sorted hierarchy by eight levels instead of keeping UID0003AX beside its predecessor.
  - the whole physical span is treated as one DialogPane-owned source emitter even though `PAL01.PAL` is shared across sixteen containing functions in multiple source files.
  - `DialogBackgroundState` is used as an opaque class placeholder even though `EPFTileContext` already occupies `+0x23c..+0x263` and exact setup/draw behavior closes the overlap.
- Current artifact status: the implementation callback is complete, all C01-C20 claims and applicable checklist rows are terminal, all ordinary validators passed, no provisional token remains, and B003 holds zero leases.

## Executive Recommendation

- Applied UID0003AX as a non-emitting parent/index with no canonical owner, `92/94`, reconstructable false, blank emitter/position/formal, and `Nested:0`.
- Registered three exact physical children:
  - `UID0004ST` `by-memory/0x00618ce0-0x00618cfc.DialogFrameEpfResourceString.md`, `92/94`, owner UID0000IT, reconstructable false, blank emitter/position/formal, `Nested:4`.
  - `UID0004SU` `by-memory/0x00618cfc-0x00618d10.Pal01PaletteResourceString.md`, `92/94`, owner none, reconstructable false, blank emitter/position/formal, `Nested:0`.
  - `UID0004SV` `by-memory/0x00618d10-0x00618d2c.DialogFrameEpdResourceString.md`, `92/94`, owner UID0000IT, reconstructable false, blank emitter/position/formal, `Nested:0`.
- Changed successor UID0002NB only from `Nested:0` to `Nested:-4` and added the exact predecessor link; every score, range, owner, compiler-data fact, and formal was preserved.
- Registered source-emitting exact methods:
  - `UID0004SW` `by-memory/0x0049f1d0-0x0049f2d4.DialogPaneDrawBackground.md`, `92/94`, owner/emitter UID00003T, reconstructable true, blank position, `Nested:0`, formal R4.
  - `UID0004SX` `by-memory/0x0049f2e0-0x0049f912.DialogPaneDrawBorder.md`, `92/94`, owner/emitter UID00003T, reconstructable true, blank position, `Nested:0`, formal R5.
- Completed existing UID0003KG at `92/94` with formal R6.
- Registered UID0004SY `by-resource/dialog-frame-resources.md`, `92/94`, owner UID0000IT, with the exact asset-mode/frame-part/package/caller matrix.
- Applied full class R7 so `DialogPane` naturally declares the three methods and carries the exact non-overlapping `0x26c` tail.

## Supervisor Active Recheck

- Historical Gate 1 accepted exact repaired SHA `0824E836288A82062914F5E044BF13AC75F756D2E188FC19B59D009FB032C20A` before ordinary implementation.
- The split repair is now applied: the physical range contains three registered real-literal children with two ownership domains and three rejected zero-xref interior aliases.
- Every source-bearing item in scope has its completed destination: three physical no-code children, three exact method bodies, one complete class declaration, one file route, one layout page, and one resource page.

## Inference Research Guidance Check

- IDA facts, documentation evidence, package evidence, and source inference are separated throughout this report.
- Existing IDA names were treated as uncertain because IDA begins its UTF-16 strings at interior aligned suffixes.
- Current generated C++ was treated as lead/current-state evidence only, not binary authority.
- The recommendation follows by-structure one-definition rules: physical storage pages document bytes but do not duplicate source literals; exact methods emit the source expressions that regenerate pooled storage.
- A stale Wave3 link exists in UID0001U4. It was ignored as historical metadata and is not used as evidence.

## Heuristic / Inference Reanalysis And Validation

### String starts and aliases

- Direct bytes prove exactly three source strings, not six:
  - `0x00618ce0`: `DLGFRAME.EPF`.
  - `0x00618cfc`: `PAL01.PAL`.
  - `0x00618d10`: `DLGFRAME.EPD`.
- `0x00618ce4`, `0x00618d00`, and `0x00618d14` each start two UTF-16 code units inside a real string. They omit `DL`, `PA`, and `DL`, respectively.
- Every interior address has zero IDA xrefs, zero absolute-VA dword hits, and zero RVA dword hits. The interior spellings are rejected as source symbols, arrays, constants, pointer entries, or caller operands.

### Source representation

- `DLGFRAME.EPF` and `DLGFRAME.EPD` are ordinary inline wide literals in `DialogPane::DrawBackground` and `DialogPane::DrawBorder`. Each appears repeatedly in one translation unit and is emitted once through string-literal pooling.
- `PAL01.PAL` is also an ordinary inline wide literal. It has 23 direct code operands in sixteen containing functions across multiple dialog source families. Link-time/string pooling explains the single physical instance without requiring a shared exported pointer or file-local array.
- No data pointer table, address-taking storage, initializer, or accessor references any of the three literal addresses.
- File-local `static const wchar_t[]` alternatives are weaker: there is no separate data reference or symbol-use shape, and current source-family patterns pass inline literals directly.

### Resource roles

- `DLGFRAME.EPF` is a nine-frame, 14-by-14 dialog chrome atlas. Frame 8 is the tiled interior/background; frames 0,2,5,7 are corners; frames 1,6,3,4 are top, bottom, left, and right edges.
- `DLGFRAME.EPD` has the same nine-frame semantic layout but uses 16-by-16 tiles. Its payload is absent from the current package, so it is a retained legacy executable literal rather than proof that the branch is dead.
- `PAL01.PAL` is the current-layout palette paired with `DLGFRAME.EPF` and many other EPF dialog images. Its payload begins with `DLPalette`.
- `NPAL8.PAL`, outside the target range, is the exact legacy palette paired with `DLGFRAME.EPD`; IDA's `aNp` rendering is truncated and must not appear in source.

Exact current package provenance:

| Resource | Archive entry | Archive SHA256 | Payload SHA256 | Header/result |
| --- | --- | --- | --- | --- |
| `DLGFRAME.EPF` | `bint1.dat`, index 24, offset 2,132,439, size 2,178 | `3CB659CDA1F5F72A9551B16899C5D485D9E6A87CD15BBF54F2C76C2A55C81242` | `C99689CA4A5D1281A8A780F22F7BA2D788DC5F826CD1FE8EB1ADF0329C81917D` | starts `09 00 0E 00 0E 00`, proving 9 frames at 14x14 |
| `PAL01.PAL` | `bint2.dat`, index 56, offset 9,276,430, size 1,056 | `3434EC989A3D26790CD48A96DE150DC643B26DAAA2544FF033C0CD21C5072929` | `C7CFBF37537C0E6A5772799D6980FE53B1C77D50C02639749F164AB5FC69CA1A` | starts with ASCII `DLPalette` |
| `DLGFRAME.EPD` | no exact entry in any current DAT; no exact loose file under `E:\NTK\Resources` | not applicable | not applicable | executable-literal-only legacy operand in the audited package |

### Method/source roles

- `0x0049f1d0` is `virtual void DialogPane::DrawBackground()`, primary slot `+0x50`.
- `0x0049f2e0` is `virtual void DialogPane::DrawBorder()`, primary slot `+0x54`.
- `0x0049db60` is `void DialogPane::SetBackgroundResource(const wchar_t *, short)`, which copies only the resource row stride, bounds, encoded-mask byte count, and an owned encoded-mask buffer into the embedded context.
- `ResourceLayoutTable::LookupLayoutEntry` is the exact resource/frame loader.
- `GrafPort::DrawTiledBackground` tiles frame 8 into the content bounds.
- `GrafPort::RenderTileFrame` draws each edge/corner frame with the selected palette.
- `InitRectBounds` and `OffsetRect` construct and advance source/destination rectangles.
- `SetDrawColor`, `FillRect`, and surface callback `g_pfnFillRle` render a caller-provided custom encoded-mask background.

### Layout resolution

- Existing `EPFTileContext m_tileContext` begins at `+0x23c` and is exactly 0x28 bytes, covering through `+0x263`.
- Therefore `+0x240`, `+0x248`, `+0x24c`, `+0x25c`, and `+0x260` are fields inside that same context, not a second overlapping `DialogBackgroundState`.
- Accepted source-facing field name: `m_backgroundTileContext`.
- `+0x264` is a four-byte trailing background-image width/state field. Existing generated/history spelling `m_backgroundImageWidth` is retained as the best descriptive name.
- `+0x268` is a Boolean trailing custom-background-presence/state field. Existing generated/history spelling `m_hasCustomBackground` is retained as the best descriptive name.
- `+0x269..+0x26b` is natural tail padding, not a raw byte-array member that must be written explicitly in human source.

### Rejected alternatives

- One reconstructable string-array target: rejected because the span contains three independent pooled literals and no array/table semantics.
- Source constants for `GFRAME.EPF`, `L01.PAL`, or `GFRAME.EPD`: rejected by exact interior offsets and zero xrefs.
- Dedicated exported `g_dialogFrameResourceName` or `g_pal01PaletteName` globals: rejected by direct code operands and no address-taking/data-reference evidence.
- Handwritten raw `.rdata` byte arrays: rejected because normal wide literals reproduce the storage.
- `DialogBackgroundState` overlapping `EPFTileContext`: rejected by the exact 0x28-byte context layout and setup-helper writes.
- BrowserDialog ownership: rejected because BrowserDialog overrides the current-layout art but explicitly calls base DialogPane methods in legacy mode.
- ResourceLayoutTable, GrafPort, Surface, MemoryMan, palette library, or DAT package ownership of the methods: rejected because they are dependencies; vtable slots and receiver fields place behavior on DialogPane.

## Evidence Standards Used

- Direct binary evidence: target bytes, SHA256, PE mapping, relocation-directory state, exact function bytes/hashes, instruction counts, function bounds, decompilation, disassembly, code/data xrefs, vtable references, and adjacent ranges.
- Current documentation evidence: target, parent/successor, class, file, aggregate, layout, render helpers, resource pages, generated C++, generated coverage, manual coverage, and executed reports.
- Package evidence: exact DAT entry names, offsets, sizes, headers, archive hashes, payload hashes, and negative all-DAT/loose-file searches.
- Negative evidence: zero interior xrefs, zero pointer-table/address-taking references, zero relocations, no standalone constant accessor, no duplicate full terminated sequence, and no current `DLGFRAME.EPD` package entry.
- The evidence is strong enough for high scores because every byte, source use, method body, and current payload role is accounted for. Confidence remains below perfect only because original lexical member names and missing legacy payload history cannot be proved from a stripped binary.

## Evidence Checked

- IDA MCP/manual checks:
  - fresh `idb_list`, `server_health`, and bounded target `get_bytes`;
  - `lookup_funcs` for `0x0049f1d0`, `0x0049f2e0`, `0x0046b030`, `0x0046b0d0`, `0x0049db60`;
  - `xrefs_to` for all three true starts, all three interior starts, and all three methods;
  - full decompilation of base background/border methods and BrowserDialog overrides;
  - disassembly/instruction totals for base methods;
  - `analyze_function` on SetBackgroundResource and MemoryMan helpers;
  - `int_convert` for all reported hex sizes/offsets.
- Raw executable checks:
  - exact target SHA/range/bytes;
  - section/raw-offset mapping;
  - unique terminated UTF-16 scans;
  - absolute-VA and RVA dword scans;
  - function and padding hashes.
- Package checks:
  - every `E:\NTK\Resources\NexusTK\Data\*.dat`;
  - exact loose filename search under `E:\NTK\Resources`.
- Documentation checked:
  - UID0003AX, UID000254, UID0002NB, UID00036P, UID00012R, UID0003KG, UID00003T, UID0000IT, UID0001U4;
  - BrowserDialog virtual support;
  - EPFTileContext, ResourceLayoutTable, GrafPort, Surface callback, MemoryMan support;
  - alert, story, and number-input resource pages;
  - generated DialogPane.cpp and generated/manual coverage roots.
- Historical roots and search outcomes are listed under Supporting Research.
- No valid bounded MCP call failed. No fallback-only conclusion was used.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state | Implementation proof |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | Evidence-time IDB `64c11373` was healthy and every bounded target call succeeded. | exact | fresh idb_list/health/get_bytes | UID0003AX MCP evidence; all changed support evidence | incorporate | applied | Evidence-time health/request facts remain in report and were incorporated into UID0003AX plus exact children; target validators `14270/14325` passed. |
| C02 | Target is exact `.rdata` `[0x00618ce0,0x00618d2c)`, 0x4c/76 bytes, SHA256 `392309FA...D9300`, no relocation entries. | exact | bytes/PE/reloc scan | UID0003AX; UID000254 | incorporate | applied | UID0003AX and UID000254 contain exact range/size/hash/PE/relocation/boundary evidence; validators `14325` and `14301`, exit 0 / ok 1. |
| C03 | Exactly three real UTF-16LE strings occupy the range with exact terminator/alignment spans. | exact | direct bytes/subrange hashes | UID0003AX; UID0004ST/UID0004SU/UID0004SV | incorporate | applied | Registered UID0004ST/0004SU/0004SV via `14263/14264/14265`; target and parent carry exact child inventory. |
| C04 | `GFRAME.EPF`, `L01.PAL`, and `GFRAME.EPD` are zero-xref interior suffixes, not source aliases. | exact | xrefs and pointer scans | UID0003AX; three children; resource page | reject-invalid | applied | Target, each physical child, and UID0004SY explicitly reject all three suffixes; generated command `14326` has zero stale exact source expressions. |
| C05 | True-start xrefs are 9/23/9; PAL01's 23 uses occur in sixteen containing functions. | exact | MCP xrefs_to | UID0003AX; resource page; bounded resource support | incorporate | applied | UID0003AX/UID0004SY/UID0004SU and story/number supports contain the complete counts and consumer inventory; validators `14324/14309/14314`. |
| C06 | `DLGFRAME.EPF` is a nine-frame 14x14 dialog atlas in bint1.dat; frame roles are 8 background and 0-7 chrome. | exact/very strong | package header plus method behavior | UID0004ST; UID0004SW/UID0004SX; resource page | incorporate | applied | UID0004ST, UID0004SW, UID0004SX, and UID0004SY contain exact archive/payload hashes, header, frame roles, and source behavior; final child validators `14321/14323/14324`. |
| C07 | `DLGFRAME.EPD` is the legacy nine-role 16x16 atlas name; no current DAT/loose payload exists. | very strong | method behavior and negative package scan | UID0004SV; UID0004SW/UID0004SX; resource page | incorporate | applied | UID0004SV plus R4/R5/resource page preserve exact legacy branch, geometry, palette, and negative package evidence; validators `14265/14321/14323/14324`. |
| C08 | `PAL01.PAL` is a shared `DLPalette` payload in bint2.dat, not DialogPane-private storage. | exact | package header and 23 xrefs | UID0004SU; resource page; story/number support | incorporate | applied | UID0004SU/UID0004SY record package and no-owner pooling; UID0001RG/UID0001RJ link central authority without score change; validators `14264/14324/14309/14314`. |
| C09 | Strongest source representation is ordinary inline wide literals pooled by compiler/linker; no standalone constant source is needed. | very strong | direct operands, one storage, no data refs | target/children no-code; method R4/R5 | incorporate | applied | R0-R3 are blank exact parity; R4/R5 retain inline literals. Command `14326` emits no physical-page marker, raw string array, or raw address. |
| C10 | `DrawBackground` exact branch/custom-mask/frame-8/inset/palette behavior is source-ready as R4. | very strong | decompile/disasm/hash/vtable | UID0004SW; class/file/aggregate | incorporate | applied | UID0004SW registered by `14266`, final revalidated by `14321`; R4 parity passed and command `14326` emits one definition. |
| C11 | `DrawBorder` exact 14/16 tile, edge/corner index, do-while, rectangle, palette behavior is source-ready as R5. | very strong | decompile/disasm/hash/vtable | UID0004SX; class/file/aggregate | incorporate | applied | UID0004SX registered by `14267`, final revalidated by `14323`; R5 parity passed and command `14326` emits one definition. |
| C12 | BrowserDialog overrides current-layout art but calls base DrawBackground/DrawBorder in legacy mode. | exact | callers 0x46b030/0x46b0d0 | Browser support prose; DialogPane class/file | incorporate | applied | UID00020X now records exact calls `0x46b0af/0x46b49b`; validator `14320`; class/file/resource pages preserve owner boundary. |
| C13 | UID0003KG copies ResourceLayout row/mask data into one EPFTileContext and is source-ready as R6. | very strong | setup body, exact MemoryMan helper resolution | UID0003KG; UID0001U4; class/file/aggregate | incorporate | applied | UID0003KG registered into validator state by `14277`, stale MemoryMan UID corrected and final validator `14283`; R6 parity passed and command `14326` emits one definition. |
| C14 | Physical parent has no single owner; DLG literals are DialogPane-owned, PAL01 storage is shared, methods are class/file-owned. | very strong | xrefs/source-family split | UID0003AX/children; UID00003T/0000IT; resource page | incorporate | applied | Metadata and prose match exact owner split across UID0003AX/ST/SU/SV/SW/SX, UID00003T/UID0000IT, and UID0004SY. |
| C15 | Target Nested8 is wrong; parent 0, children 4/0/0, successor -4 preserves address-sorted cumulative level. | exact | current generated indentation and metadata | UID0003AX; UID0004ST/UID0004SU/UID0004SV; UID0002NB | incorporate | applied | Current headers are `0/+4/0/0/-4`; UID0002NB validator `14272` preserved every unrelated compiler fact. |
| C16 | UID0003AX is 92/94, false, no owner/emitter, blank formal; three physical children are 92/94 false no-code. | strong | full blocker closure | target and three children | incorporate | applied | Exact current metadata/formals verified; target `14325`, child registrations `14263-14265`; R0-R3 parity all true. |
| C17 | Two exact source method children exist at the proven ranges, 92/94, owner/emitter UID00003T, formals R4/R5. | exact/very strong | function bounds/hashes/vtable/xrefs | UID0004SW/UID0004SX | incorporate | applied | Real UIDs assigned in order, metadata and hashes current, validators `14321/14323`, generated definitions one each. |
| C18 | DialogPane class/layout must replace overlapping background placeholder with exact EPFTileContext plus trailing fields; full R7 preserves all other declarations. | very strong | exact 0x28 context and setup/draw offsets | UID00003T; UID0001U4 | incorporate | applied | Class validator `14304`, layout validator `14307`; R7 exact parity, class closes before children, one context plus int/bool/natural padding documented. |
| C19 | DialogPane file/aggregate and a new central dialog-frame resource page must carry full source/resource/caller/history detail; existing resource pages retain bounded PAL/DLG links. | strong | owner/module and package evidence | UID0000IT; UID00012R; UID0004SY; resource supports | incorporate | applied | UID0000IT `14306`, UID00012R `14293`, UID0004SY `14324`, supports `14308/14309/14314`; no unrelated content was removed. |
| C20 | Manual coverage needs exact new/replacement rows; scoped validators must cover every changed/new ordinary page and final waited DialogPane generation. | exact | current manual/generated snapshots | manual handoff/checklist only | incorporate | applied | Current manual files were reread read-only and exact real-UID handoff remains below; all 18 ordinary paths passed scoped validation; waited command `14326` completed with current generated proof. |

## Positive Evidence Summary

- The target bytes decode without ambiguity into three terminated UTF-16LE literals and complete the range exactly.
- All 41 true-start code operands resolve to known dialog rendering/resource construction functions.
- The base methods are primary DialogPane vtable slots with 113 data references each and one direct BrowserDialog fallback caller each.
- Package headers match the exact frame dimensions selected by code: 14 for EPF and 16 for legacy EPD.
- PAL01's `DLPalette` payload and broad xref family prove shared resource status.
- SetBackgroundResource writes exactly the EPFTileContext fields later read by DrawBackground/DrawBorder.
- Normal inline string literals explain the exact one-copy storage and avoid artificial globals/arrays.

## IDA MCP Facts

- Session: `64c11373`, evidence-time healthy.
- Target bytes at `0x00618ce0-0x00618d2c`: exact 76-byte sequence recorded under Range Analysis.
- DrawBackground: `0x0049f1d0-0x0049f2d4`, 0x104/260 bytes (Verified with MCP int_convert), 87 instructions, seven basic blocks, SHA256 `98B02BA428D57ED8E12FF7A8D522693C8030CE75F0AB0CACD600BAEF5E63B4B3`.
- DrawBorder: `0x0049f2e0-0x0049f912`, 0x632/1,586 bytes (Verified with MCP int_convert), 562 instructions, 23 basic blocks, SHA256 `364A8590D8488C78E24C350F9B52A61444C9530B0707B52D51E7D3ABE713FE86`.
- SetBackgroundResource: `0x0049db60-0x0049dc05`, 0xa5/165 bytes, one basic block, 93 direct code xrefs, SHA256 `D4161FA3F6BD8E9BC7E641D88BDD99D0A90A7A610E65EF7E9FE77703BBD770BC`.
- DrawBackground xrefs: 114 total, one direct code ref `0x0046b0af`, 113 data/vtable refs.
- DrawBorder xrefs: 114 total, one direct code ref `0x0046b49b`, 113 data/vtable refs.
- True string xrefs: DLGFRAME.EPF 9; PAL01.PAL 23; DLGFRAME.EPD 9.
- Exact `DLGFRAME.EPF` xrefs: `0x0049f20d`, `0x0049f35e`, `0x0049f3d2`, `0x0049f43a`, `0x0049f4a6`, `0x0049f4f6`, `0x0049f548`, `0x0049f596`, `0x0049f5ec`.
- Exact `PAL01.PAL` xrefs: `0x0049f21a`, `0x0049f372`, `0x0049f3e2`, `0x0049f446`, `0x0049f4b2`, `0x0049f506`, `0x0049f554`, `0x0049f5a2`, `0x0049f5f8`, `0x004a4803`, `0x004ae55d`, `0x004af0e8`, `0x00500150`, `0x005181b7`, `0x00519b1e`, `0x0051a935`, `0x0051bb34`, `0x0051cd38`, `0x0051dd8b`, `0x0051eddd`, `0x0051fd23`, `0x0052017e`, `0x00530704`.
- Exact `DLGFRAME.EPD` xrefs: `0x0049f2a5`, `0x0049f656`, `0x0049f6c2`, `0x0049f72a`, `0x0049f796`, `0x0049f7e6`, `0x0049f838`, `0x0049f886`, `0x0049f8dc`.
- Interior suffix xrefs: zero for all three.
- Full terminated executable scans find exactly one `DLGFRAME.EPF`, one `PAL01.PAL`, and one `DLGFRAME.EPD`; each suffix sequence also appears exactly once only because it is physically inside that one full string.
- Direct executable scans find zero RVA dword references for all six true/interior addresses and zero absolute-VA dword references for the three interiors. The true-start absolute operands correspond exactly to the code xrefs above; no data-address table exists.
- No target byte requires padding outside the stated terminator/alignment spans.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00618ce0-0x00618d2c` | UID0003AX current path | physical string container/index | false | UID000254 physical | 92/94 | implemented parent |
| `0x00618ce0-0x00618cfc` | UID0004ST DialogFrameEpfResourceString | pooled `L"DLGFRAME.EPF"` storage | false | UID0003AX | 92/94 | registered/implemented |
| `0x00618cfc-0x00618d10` | UID0004SU Pal01PaletteResourceString | pooled shared `L"PAL01.PAL"` storage | false | UID0003AX | 92/94 | registered/implemented |
| `0x00618d10-0x00618d2c` | UID0004SV DialogFrameEpdResourceString | pooled `L"DLGFRAME.EPD"` storage | false | UID0003AX | 92/94 | registered/implemented |
| `0x0049db60-0x0049dc05` | UID0003KG current path | SetBackgroundResource source method | true | UID00003T | 92/94 | implemented |
| `0x0049f1d0-0x0049f2d4` | UID0004SW DialogPaneDrawBackground | base dialog background method | true | UID00003T | 92/94 | registered/implemented |
| `0x0049f2e0-0x0049f912` | UID0004SX DialogPaneDrawBorder | base dialog frame/chrome method | true | UID00003T | 92/94 | registered/implemented |
| resource family | UID0004SY `by-resource/dialog-frame-resources.md` | package/caller/frame-role authority | n/a resource | UID0000IT | 92/94 | registered/implemented |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x49f20d` | DrawBackground -> `DLGFRAME.EPF`, frame 8 | current-layout tiled background |
| `0x49f21a` | DrawBackground -> `PAL01.PAL` | current-layout palette |
| `0x49f2a5` | DrawBackground -> `DLGFRAME.EPD`, frame 8 | legacy tiled background |
| `0x49f35e..0x49f5ec` | eight DrawBorder EPF-name operands | frames 1,6,3,4,0,2,5,7 |
| `0x49f372..0x49f5f8` | eight DrawBorder PAL01 operands | palette for every EPF edge/corner draw |
| `0x49f656..0x49f8dc` | eight DrawBorder EPD-name operands | legacy frames 1,6,3,4,0,2,5,7 |
| `0x46b0af` | BrowserDialog::DrawContentArea -> base DrawBackground | legacy-mode fallback |
| `0x46b49b` | BrowserDialog::DrawFrameChrome -> base DrawBorder | legacy-mode fallback |
| `0x4a4803` | EmployeeQuantityInputDialogPane constructor -> PAL01 | `DLGEXC3.EPF` background palette |
| `0x4ae55d` | AddItemDialog constructor -> PAL01 | `DLGEXC2.EPF` background palette |
| `0x4af0e8` | AddItemWithCountDialog constructor -> PAL01 | `DLGEXC3.EPF` background palette |
| `0x500150` | BackStoryDialogPane constructor -> PAL01 | `STORY.EPF` palette |
| `0x5181b7` | TextMenuDialog constructor -> PAL01 | `DLGMERC1.EPF` palette |
| `0x519b1e` | TextInputMenuDialog constructor -> PAL01 | `DLGMERC2.EPF` palette |
| `0x51a935` | ServerItemMenuDialog constructor -> PAL01 | `DLGMERC3.EPF` palette |
| `0x51bb34` | ClientItemMenuDialog constructor -> PAL01 | `DLGMERC1.EPF` palette |
| `0x51cd38` | ServerSpellMenuDialog constructor -> PAL01 | `DLGMERC1.EPF` palette |
| `0x51dd8b` | ClientSpellMenuDialog constructor -> PAL01 | `DLGMERC1.EPF` palette |
| `0x51eddd` | ArgumentedMenuMenuDialog constructor -> PAL01 | `DLGMERC3.EPF` palette |
| `0x51fd23` | ArgumentedItemQuantityInputDialogPane constructor -> PAL01 | `DLGEXC3.EPF` palette |
| `0x52017e` | ArgumentedItemConfirmInputDialogPane constructor -> PAL01 | `DLGEXC3.EPF` palette |
| `0x530704` | NumberInputDialog constructor -> PAL01 | `DLGEXC3.EPF` palette |

## Documentation Evidence And IDA Status

- UID0003AX now has exact outer endpoints, exact children, corrected true/interior strings, no owner/emitter, `92/94`, blank no-code formal, and `Nested:0`.
- UID000254 now carries the exact parent/three-child literal inventory while preserving unrelated compiler/vtable data.
- UID0003KG is `92/94` with exact R6, 93 callers, MemoryMan/EPFTileContext semantics, and registered path mapping.
- UID00012R is `92/94` with exact UID0003KG/UID0004SW/UID0004SX rows and blank nonduplicating aggregate formal.
- UID00003T contains exact R7 and closes before `[[CHILDREN]]`; the overlapping DialogBackgroundState placeholder is removed.
- UID0001U4 is `91/93` with one EPFTileContext, trailing int/bool, and natural tail padding.
- UID0000IT is `92/94` with exact source children, resource authority, pooling, Browser fallback, and no-raw-storage policy.
- Historical pre-callback generated checkpoint `000000014246`, SHA256 `5A961F70...C1802E02`, had the UID0003AX Empty Emitter Marker and zero accepted definitions.
- B003 waited generated checkpoint `000000014326`, refreshed `2026-07-16T15:59:15-04:00`, SHA256 `A31D5219BC2BDD8CD1D9DE05314B1C4BD5E09D5C4BBF7EB5AA93803FACBD127F`, 19,578 bytes / 580 lines, closed the class before children, emitted UID0003KG/UID0004SW/UID0004SX once each, and contained zero UID0003AX/UID0004ST/UID0004SU/UID0004SV text or marker.
- Final self-audit's read-only generated checkpoint is external validator-owned command `000000014347`, refreshed `2026-07-16T16:09:49-04:00`, SHA256 `75C1321021D0CAA60198872836ECB59BCD23F68A7FC73AFBCBFBEA4F02E7B01F`, 19,578 bytes / 580 lines. It retains the same B003-scope semantics: one complete class closing at line 88 before SetBackgroundResource at line 92, DrawBackground at line 337, and DrawBorder at line 381; one definition of each accepted method; zero physical target/child UIDs or markers; zero stale interior-suffix source literals; no raw physical string storage, vtable/RTTI arrays, relocation data, or duplicate target method. Its six Empty Emitter Markers belong only to unrelated UID00012R, UID0003KH, UID0001U4, UID0003JB, UID0000PQ, and UID0001PH. This is a time-scoped external checkpoint, not an assertion that unrelated later headers cannot advance.

Current ordinary destination snapshots after implementation and validation:

| Destination | SHA256 | Bytes / lines |
| --- | --- | --- |
| UID0003AX target | `911A3762CD8C14F9072FC5D1FC84A687E52E6FBF3E6EF9551136F7ABE23FA89D` | 10,239 / 105 |
| UID0004ST EPF child | `EF538675938C227A65DB657A3B01E14BA847B09951BA1A2F62CC085E57F95C9E` | 6,885 / 84 |
| UID0004SU PAL01 child | `F1160E399AAFD10EECC2509C8A42CF4F50AE740AC951E86F46A6244153463B26` | 7,386 / 100 |
| UID0004SV EPD child | `EA00135B9FBB2172AC1AF16E113246117CCCE0A893623E7744D477128E57071A` | 6,936 / 91 |
| UID0002NB successor | `92D3C03CC1885ED880AB4E2C5E164BF1694947D53CEAAA46CD5366C7F3D5C484` | 20,666 / 218 |
| UID0004SW DrawBackground | `7B9F3E543696746AF8CC533C7093FC5342226BC49DBDB84C50FE9514064CF0DF` | 7,733 / 130 |
| UID0004SX DrawBorder | `FA96FFEB5D93547F8C71085CFF1EC6B25D2F0D7DB75345290D9300783A3BDD6E` | 13,877 / 272 |
| UID0003KG setter | `3042F6CE2EA876D02610E682691262543899C3CF9E2547C8A654265AF4FD3C69` | 8,098 / 112 |
| UID00012R aggregate | `53689F4A40D3B3DD221F41B27A3212496F82B7B76FB1312B8C1A6B7BB8CCA338` | 32,803 / 188 |
| UID000254 parent | `140A4C50AF46CC64886B5A21BCDA3F165C5E673BDBB63125F69DC999211BE575` | 18,687 / 141 |
| UID00003T class | `7101A93A4EF53CFA1F11529AEF111AA94B13EBC76222ADE546D7B59D6D521DBE` | 38,969 / 333 |
| UID0000IT file | `D584F93EE7238EC989EFE820DEBE2595DE76D132EC0DB680936CF77BEE1E0CBD` | 28,345 / 163 |
| UID0001U4 layout | `A9A98E2CEA2B5E6BADEC1C629C68D65FCD1EF90AA79B33967C346251A5DC4D86` | 23,615 / 153 |
| UID0004SY resource page | `FC96153F26F56DB019204B6913C5E9667C055AEB46D7E4B36EB940DF57A264F8` | 9,985 / 116 |
| Browser support | `6F201B35A0A353FDD20F90A8435991106CF6417443406E34560ACD204268844F` | 21,745 / 122 |
| alert resource support | `B0E67DE05EA89ADA873767FAF155B5585855268BDAC438E98CEB4AC2C3F4C0FD` | 20,454 / 155 |
| story resource support | `42907576E520CD6E3652468D1F5B5163AD36D73F2CD8478D1C075A102131B661` | 15,209 / 129 |
| number resource support | `A8F6C57CD057B7CEF1BFE89D4F02861BE6BCB7B9DA9C1F5BF0DC8DF4B3FA6B54` | 12,857 / 118 |

## Ranked Ownership Analysis

### 1. DialogPane class/file owns DLGFRAME literals and all three methods

- Evidence for: exact primary vtable slots, receiver fields, method cluster, package role, file path, direct BrowserDialog fallback, and repeated DLGFRAME uses exclusively in the two DialogPane methods.
- Evidence against: the physical PAL01 string is shared and prevents assigning the entire storage span to DialogPane.
- Decision: UID00003T/UID0000IT own source methods and DLGFRAME semantic resource role, not the mixed physical parent.

### 2. Shared resource identity owns PAL01 semantics

- Evidence for: 23 operands in sixteen functions and `DLPalette` package payload.
- Evidence against: there is no source-level resource singleton or exported string constant at this address.
- Decision: use a no-owner physical child plus a central by-resource page; each consumer keeps its inline literal.

### 3. ResourceLayoutTable/GrafPort/Surface/MemoryMan

- Evidence for: these systems load, render, allocate, copy, or dispatch the data.
- Evidence against: they do not choose the DialogPane frame names, frame indices, geometry, or method override behavior.
- Decision: dependencies only; reject ownership.

### Proposed new file/grouping, if applicable

- Implemented owner/name/path: [UID:0004SY][dialog-frame-resources](by-resource/dialog-frame-resources.md), owner UID0000IT.
- Implemented full contents: DLGFRAME EPF/EPD mode matrix, frame-part indices, 14/16 tile geometry, PAL01/NPAL8 pairing, package provenance, missing legacy payload, all DialogPane direct xrefs, PAL01 full consumer list, source/payload boundary, and BrowserDialog override relationship.
- Related items that belong: UID0003AX and its three children, UID0004SW/UID0004SX, UID0003KG, UID00003T, UID0000IT, UID0001U4.
- Rejected: generic alert resources, browser resources, MemoryMan, ImageLib implementation, raw Surface tables, and feature-dialog ownership.
- Grouping result: narrow central resource authority, not a new C++ source file.

## Source Placement

- `DialogPane::SetBackgroundResource`, `DrawBackground`, and `DrawBorder` belong in `NexusTK/ui/core/DialogPane.cpp`.
- Their declarations and fields belong on UID00003T's DialogPane class declaration.
- Physical `.rdata` pages remain documentation-only and emit no source.
- The three source literals stay inline in R4/R5. No standalone `DialogFrameResources.cpp`, string global, static array, or pointer table is warranted.
- Resource package facts belong in `by-resource/dialog-frame-resources.md`; package loaders remain separate dependencies.

## Range / Split / Padding / Reclassification Analysis

- Exact target: `[0x00618ce0,0x00618d2c)`, 0x4c/76 bytes (Verified with MCP int_convert), raw file offset `0x2176e0`, `.rdata`.
- `.rdata` has RVA `0x0020d000`, virtual size `0x0005f0be`, raw file offset `0x0020ba00`, raw size `0x0005f200`, and characteristics `0x40000040`.
- PE base relocation directory has RVA/size zero. No target relocation exists.
- Exact bytes:
  - `44 00 4c 00 47 00 46 00 52 00 41 00 4d 00 45 00 2e 00 45 00 50 00 46 00 00 00 00 00`
  - `50 00 41 00 4c 00 30 00 31 00 2e 00 50 00 41 00 4c 00 00 00`
  - `44 00 4c 00 47 00 46 00 52 00 41 00 4d 00 45 00 2e 00 45 00 50 00 44 00 00 00 00 00`
- Subranges:
  - `0x00618ce0-0x00618cfc`, 0x1c/28 bytes: 12 UTF-16 code units, terminator `0x00618cf8-0x00618cfa`, two-byte zero alignment `0x00618cfa-0x00618cfc`, SHA256 `3908A4652C3EA6CD023675E1947478D8ED2ACBD44069119E0C116DF167189664`.
  - `0x00618cfc-0x00618d10`, 0x14/20 bytes: nine UTF-16 code units and terminator `0x00618d0e-0x00618d10`, SHA256 `82D8E4C7718078B9875FD580B76A9E32BD702E23DF425ED223D10B9E31D9C410`.
  - `0x00618d10-0x00618d2c`, 0x1c/28 bytes: 12 UTF-16 code units, terminator `0x00618d28-0x00618d2a`, two-byte zero alignment `0x00618d2a-0x00618d2c`, SHA256 `B1292112E754910898336C7E642861B962F06B0F7EEE54960A511BFE9313713D`.
- Predecessor UID00036P ends exactly at `0x00618ce0`; successor UID0002NB begins exactly at `0x00618d2c` with the DialogSession primary COL pointer `0x00646794`.
- No byte is unclassified. The two zero words are source-literal alignment inside the first and third child spans, not parent-only padding.
- Relative nesting proof:
  - UID00036P's current cumulative level is the physical-parent child level.
  - UID0003AX must use delta `0` to remain its sibling, replacing false `+8`.
  - first new child enters one level with `+4`; second and third remain at that level with `0`.
  - UID0002NB uses `-4` to return to the physical-parent child level.
- Method boundaries:
  - DrawBackground has fourteen `0xcc` bytes before and twelve after; both remain parent-only alignment.
  - DrawBorder ends at `0x0049f912`; `0x0049f912-0x0049fa60` remains parent-only alignment/raw gap with SHA256 `346CBE476DEFB5DE06640A54B7134FACD010733E5984EE56D7C90C612F1DADA1`.
  - SetBackgroundResource has three `0xcc` bytes before and eleven after.

## Negative Evidence Summary

- Zero xrefs to all three interior suffixes.
- Zero absolute/RVA pointer hits to interior suffixes.
- Zero evidence for a pointer table or constant accessor.
- No base relocations for the storage.
- No current DAT/loose `DLGFRAME.EPD` payload.
- No source need for raw bytes, compiler string aliases, manually pooled constants, or handwritten relocation/storage code.
- Consumer xrefs prove use, not ownership of the physical PAL01 storage.
- BrowserDialog direct calls prove inheritance/fallback, not ownership of base methods.

## IDA Rename / Type / Comment Recommendations

- Do not mutate IDA during this assignment.
- Source-facing names:
  - `sub_49F1D0` -> `DialogPane::DrawBackground`.
  - `sub_49F2E0` -> `DialogPane::DrawBorder`.
  - `sub_49DB60` -> `DialogPane::SetBackgroundResource`.
  - `off_618CE0` -> documentation alias `kDialogFrameEpfResourceName`, not a required emitted symbol.
  - `off_618CFC` -> documentation alias `kPal01PaletteResourceName`, not a required emitted symbol.
  - `off_618D10` -> documentation alias `kDialogFrameEpdResourceName`, not a required emitted symbol.
  - `aGframeEpf`, `aL01Pal`, `aGframeEpd` -> mark as interior suffix artifacts; do not promote.
- Types:
  - `const wchar_t *resourceName`, `short frameIndex`.
  - `EPFTileContext m_backgroundTileContext`.
  - `int m_backgroundImageWidth`, `bool m_hasCustomBackground`.
  - `RectBounds`, `ResourceLayoutTable`, `MemoryMan`, `SurfaceSpriteBlitOptions` remain existing support types.
- Recommended comments should record evidence and inferred names without writing raw offsets into formal C++.

## First-Draft C++ Recommendation

- Eligible for draft C++: UID0004SW, UID0004SX, UID0003KG, UID00003T.
- Physical UID0003AX and UID0004ST/UID0004SU/UID0004SV must remain blank under exact no-code proof.

### R0 - UID0003AX parent no-code block

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R1 - UID0004ST no-code block

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R2 - UID0004SU no-code block

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R3 - UID0004SV no-code block

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R4 - UID0004SW DialogPane::DrawBackground

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void DialogPane::DrawBackground()
{
    EPFTileContext frame;

    if (g_useEpfAssets)
    {
        frame.Initialize();

        if (m_backgroundTileContext.encodedMaskBytes == 0)
        {
            g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPF", 8, &frame);
            m_drawMode = 1;

            RectBounds backgroundBounds = m_bounds;
            backgroundBounds.Inset(1, 1);
            DrawTiledBackground(&backgroundBounds, &frame, L"PAL01.PAL");
            return;
        }
    }
    else
    {
        frame.Initialize();

        if (m_backgroundTileContext.encodedMaskBytes == 0)
        {
            g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPD", 8, &frame);
            m_drawMode = 0;
            DrawTiledBackground(&m_bounds, &frame, L"NPAL8.PAL");
            return;
        }
    }

    SetDrawColor(0);
    FillRect(&m_bounds);
    SetDrawColor(128);
    g_pfnFillRle(this,
                 &m_backgroundTileContext,
                 &m_backgroundTileContext.bounds,
                 &m_backgroundTileContext.bounds,
                 1,
                 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R5 - UID0004SX DialogPane::DrawBorder

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void DialogPane::DrawBorder()
{
    EPFTileContext frame;
    frame.Initialize();

    if (m_backgroundTileContext.encodedMaskBytes != 0)
        return;

    RectBounds sourceBounds;
    RectBounds originBounds;
    RectBounds destinationBounds;

    if (g_useEpfAssets)
    {
        InitRectBounds(&sourceBounds, 0, 0, 14, 14);
        InitRectBounds(&originBounds, 0, 0, 14, 14);

        destinationBounds = originBounds;
        OffsetRect(&destinationBounds, 14, 0);
        g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPF", 1, &frame);
        do
        {
            RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                            1, L"PAL01.PAL", 0);
            OffsetRect(&destinationBounds, 14, 0);
        }
        while (destinationBounds.right <
               originBounds.left + m_bounds.right - m_bounds.left);

        destinationBounds = originBounds;
        OffsetRect(&destinationBounds, 14,
                   m_bounds.bottom - m_bounds.top - 14);
        g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPF", 6, &frame);
        do
        {
            RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                            1, L"PAL01.PAL", 0);
            OffsetRect(&destinationBounds, 14, 0);
        }
        while (destinationBounds.right <
               originBounds.left + m_bounds.right - m_bounds.left);

        destinationBounds = originBounds;
        OffsetRect(&destinationBounds, 0, 14);
        g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPF", 3, &frame);
        do
        {
            RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                            1, L"PAL01.PAL", 0);
            OffsetRect(&destinationBounds, 0, 14);
        }
        while (destinationBounds.bottom <
               originBounds.top + m_bounds.bottom - m_bounds.top);

        destinationBounds = originBounds;
        OffsetRect(&destinationBounds,
                   m_bounds.right - m_bounds.left - 14, 14);
        g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPF", 4, &frame);
        do
        {
            RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                            1, L"PAL01.PAL", 0);
            OffsetRect(&destinationBounds, 0, 14);
        }
        while (destinationBounds.bottom <
               originBounds.top + m_bounds.bottom - m_bounds.top);

        destinationBounds = originBounds;
        g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPF", 0, &frame);
        RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                        1, L"PAL01.PAL", 0);

        destinationBounds = originBounds;
        OffsetRect(&destinationBounds,
                   m_bounds.right - m_bounds.left - 14, 0);
        g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPF", 2, &frame);
        RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                        1, L"PAL01.PAL", 0);

        destinationBounds = originBounds;
        OffsetRect(&destinationBounds, 0,
                   m_bounds.bottom - m_bounds.top - 14);
        g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPF", 5, &frame);
        RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                        1, L"PAL01.PAL", 0);

        destinationBounds = originBounds;
        OffsetRect(&destinationBounds,
                   m_bounds.right - m_bounds.left - 14,
                   m_bounds.bottom - m_bounds.top - 14);
        g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPF", 7, &frame);
        RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                        1, L"PAL01.PAL", 0);
        return;
    }

    InitRectBounds(&sourceBounds, 0, 0, 16, 16);
    InitRectBounds(&originBounds, 0, 0, 16, 16);

    destinationBounds = originBounds;
    OffsetRect(&destinationBounds, 16, 0);
    g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPD", 1, &frame);
    do
    {
        RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                        1, L"NPAL8.PAL", 0);
        OffsetRect(&destinationBounds, 16, 0);
    }
    while (destinationBounds.right <
           originBounds.left + m_bounds.right - m_bounds.left);

    destinationBounds = originBounds;
    OffsetRect(&destinationBounds, 16,
               m_bounds.bottom - m_bounds.top - 16);
    g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPD", 6, &frame);
    do
    {
        RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                        1, L"NPAL8.PAL", 0);
        OffsetRect(&destinationBounds, 16, 0);
    }
    while (destinationBounds.right <
           originBounds.left + m_bounds.right - m_bounds.left);

    destinationBounds = originBounds;
    OffsetRect(&destinationBounds, 0, 16);
    g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPD", 3, &frame);
    do
    {
        RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                        1, L"NPAL8.PAL", 0);
        OffsetRect(&destinationBounds, 0, 16);
    }
    while (destinationBounds.bottom <
           originBounds.top + m_bounds.bottom - m_bounds.top);

    destinationBounds = originBounds;
    OffsetRect(&destinationBounds,
               m_bounds.right - m_bounds.left - 16, 16);
    g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPD", 4, &frame);
    do
    {
        RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                        1, L"NPAL8.PAL", 0);
        OffsetRect(&destinationBounds, 0, 16);
    }
    while (destinationBounds.bottom <
           originBounds.top + m_bounds.bottom - m_bounds.top);

    destinationBounds = originBounds;
    g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPD", 0, &frame);
    RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                    1, L"NPAL8.PAL", 0);

    destinationBounds = originBounds;
    OffsetRect(&destinationBounds,
               m_bounds.right - m_bounds.left - 16, 0);
    g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPD", 2, &frame);
    RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                    1, L"NPAL8.PAL", 0);

    destinationBounds = originBounds;
    OffsetRect(&destinationBounds, 0,
               m_bounds.bottom - m_bounds.top - 16);
    g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPD", 5, &frame);
    RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                    1, L"NPAL8.PAL", 0);

    destinationBounds = originBounds;
    OffsetRect(&destinationBounds,
               m_bounds.right - m_bounds.left - 16,
               m_bounds.bottom - m_bounds.top - 16);
    g_pEPFLib->LookupLayoutEntry(L"DLGFRAME.EPD", 7, &frame);
    RenderTileFrame(&frame, &sourceBounds, &destinationBounds,
                    1, L"NPAL8.PAL", 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R6 - UID0003KG DialogPane::SetBackgroundResource

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void DialogPane::SetBackgroundResource(const wchar_t *resourceName,
                                       short frameIndex)
{
    MemoryMan *memoryMan = GetMemoryMan();
    EPFTileContext sourceContext;
    sourceContext.Initialize();

    g_pEPFLib->LookupLayoutEntry(resourceName, frameIndex, &sourceContext);

    m_backgroundTileContext.ReleaseBuffers();
    m_backgroundTileContext.pixelData = 0;
    m_backgroundTileContext.rowStridePixels = sourceContext.rowStridePixels;
    m_backgroundTileContext.bounds = sourceContext.bounds;
    m_backgroundTileContext.encodedMaskByteCount =
        sourceContext.encodedMaskByteCount;
    m_backgroundTileContext.encodedMaskBytes =
        static_cast<unsigned char *>(
            GetMemoryMan()->AllocateBufferMemory(
                m_backgroundTileContext.encodedMaskByteCount));

    memoryMan->MemmoveWrapper(
        m_backgroundTileContext.encodedMaskBytes,
        sourceContext.encodedMaskBytes,
        m_backgroundTileContext.encodedMaskByteCount);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R7 - UID00003T complete DialogPane declaration

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class DialogPane : public Pane
{
public:
    DialogPane(const wchar_t *title, unsigned short dialogConfigId, unsigned char paneMode);
    virtual ~DialogPane();

    virtual void OnCreate(const RectBounds *bounds, int zOrder, Pane *parentPane, Layer *layer);
    virtual void OnShow(Pane *afterPane, Pane *beforePane);
    virtual void OnDestroy();
    virtual void OnHide();
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandleImeEvent(Event *event);
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual void UpdateActionButton();
    int FindControlIndex(const ControlPane *control) const;
    void CloseDialog();

protected:
    void StoreClampRect(const RectBounds *bounds);
    void ClearClampRect();
    void SetTitleText(const wchar_t *title);
    void SetBackgroundResource(const wchar_t *resourceName, short frameIndex);
    void AddControl(unsigned char category, ControlPane *control);
    void AddControl(ControlPane *control);
    void RemoveControl(ControlPane *control);
    void RemoveControl(int controlIndex);
    int GetControlCount() const;
    ControlPane *GetChildControl(int controlIndex) const;

    template <class T>
    T *GetChild(int controlIndex) const
    {
        return static_cast<T *>(GetChildControl(controlIndex));
    }

    virtual void DrawBackground();
    virtual void DrawBorder();
    char HitTestControls(int mouseY, int mouseX, int *outControlId);
    void DispatchInputToControl(Event *event, int controlId);
    void SavePosition();
    void SetFocusedControl(int controlId);
    void SetPendingControl(int controlId);
    virtual void SetHoverControl(int controlId);
    void SetSelectionVisualState(int controlId, unsigned char state);
    void ActivateFocusedControl();
    void ActivatePendingControl();
    void RedrawSelectedControl();

    void SlideOpenVertical();
    void SlideCloseVertical();
    void SlideOpenHorizontal(unsigned char direction);
    void SlideCloseHorizontal(unsigned char direction);
    void SlideShrink(unsigned char direction);
    void SlideExpand(unsigned char direction);

    wchar_t m_title[128];
    unsigned short m_dialogConfigId;
    List *m_controlManager;
    int m_focusedControlId;
    int m_pendingControlId;
    unsigned char m_isTitleDragActive;
    unsigned char m_savedPaneMode;
    int m_dragOriginX;
    int m_dragOriginY;
    int m_activeControlId;
    unsigned char m_pressedControlActive;
    int m_pressedControlId;
    unsigned char m_pressedHitType;
    int m_selectedControlId;
    unsigned char m_selectionVisualState;
    unsigned char m_clampDragToBounds;
    int m_dragClampMinY;
    int m_dragClampMinX;
    int m_dragClampMaxY;
    int m_dragClampMaxX;
    EPFTileContext m_backgroundTileContext;
    int m_backgroundImageWidth;
    bool m_hasCustomBackground;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Behavior preservation: R4/R5 preserve exact asset-mode branches, frame 8, all eight border frame indices, do-while edge draws, 14/16 tile sizes, palettes, custom mask early-return behavior, draw-mode stores, inset geometry, colors, callback order, and no-change/return behavior.
- Source-shape preservation: no raw addresses, `sub_` labels, vtables, RTTI, relocations, interior aliases, or compiler string-storage arrays appear in source.
- Exact no-code proof for R0-R3: those pages represent compiler/linker storage for literals already expressed in R4/R5 and other consumers. Emitting code there would duplicate definitions or invent a raw table.

## Final Recommendation

- The six registered destinations and all accepted existing support changes are applied exactly.
- Keep physical range and subranges non-emitting.
- Emit methods only through UID00003T into UID0000IT.
- Keep PAL01 source expressions in each owning consumer; do not centralize them into a C++ global.
- Preserve legacy EPD behavior despite absent current payload.
- No future research blocker remains in this assignment. Original spelling uncertainty is documented and score-capped, not deferred.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00618ce0-0x00618d2c.DialogFrameResourceStrings.md`.
- Applied `92/94`, owner none, reconstructable false, blank emitter/position/formal, `Nested:0`.
- Item Summary: `Non-emitting 76-byte .rdata parent over exact pooled UTF-16 literals DLGFRAME.EPF, PAL01.PAL, and DLGFRAME.EPD; three false interior suffix labels have zero xrefs, exact children carry bytes/terminators/alignment, and source expressions live once in DialogPane draw methods or their owning consumer functions.`
- Exact target SHA, bytes, PE mapping, relocation negative, subrange hashes, true/interior xrefs, pooling explanation, ownership split, package role, predecessor/successor, and R0 no-code proof are applied.
- A003 creation history is preserved as historical and its false separate interior-string interpretation is explicitly corrected.

## Recommended Support Doc Changes

- UID000254 is `90/93` with unchanged none/false/blank route and exact parent/three-child inventory; unrelated vtable children and boundaries are preserved.
- UID0002NB changed only Nested `0 -> -4` plus predecessor link; `93/94`, owner UID0001XD, false/blank state, formal, and all compiler facts are preserved.
- UID00012R is `92/94` with UID0003KG/UID0004SW/UID0004SX exact rows; aggregate blank C++ and all unrelated inventory remain.
- UID0003KG is `92/94` with exact Item Summary, R6, hash, 93 callers, MemoryMan/type/layout, and no-compiler-artifact evidence.
- UID00003T retains `92/94`, owner/emitter UID0000IT, route and exact R7 with frame/resource/layout/caller evidence.
- UID0000IT is `92/94` with exact children, UID0004SY, pooling/source placement, Browser fallback, custom background, and no-raw-storage policy.
- UID0001U4 is `91/93` with exact EPFTileContext/trailing fields and preserved unrelated fields/history.
- UID0004SY is registered at `92/94`, owner UID0000IT.
- UID0001R5, UID0001RG, UID0001RJ, and UID00020X retain scores/formals and receive only accepted bounded links/prose.
- Verify-only dependencies were reread or preserved through current exact links; no contradiction required broadening.

## Score And Metadata Recommendation

| Destination | Historical | Implemented | Rationale |
| --- | --- | --- | --- |
| UID0003AX | 85/90 true owner/emitter 0000IT Nested8 | 92/94 false none/blank Nested0 | every byte/string/xref/source route closed; physical parent must not emit |
| UID0004ST/UID0004SU/UID0004SV | absent | 92/94 false, blank emitters | exact physical storage and no-code proof |
| UID0004SW/UID0004SX | absent | 92/94 true owner/emitter 00003T | exact ranges/hashes/vtable/callers/full source |
| UID0003KG | 86/89 | 92/94 | exact types, fields, alloc/copy helpers, 93 callers, R6 |
| UID000254 | 87/91 | 90/93 | target island becomes exact; broader aggregate still mixed |
| UID00012R | 90/93 | 92/94 | exact draw/setup children close major body/layout blockers |
| UID00003T | 92/94 | 92/94 | score already reflects complete class; replace placeholder tail without inflation |
| UID0000IT | 90/92 | 92/94 | exact methods/resource/source placement close background blockers |
| UID0001U4 | 86/90 | 91/93 | overlapping placeholder and background type blocker resolved |
| UID0004SY | absent | 92/94 | exact package, frame-role, source/payload, caller authority |

- Reason scores are not 95+: original lexical spellings for the three trailing class members and exact legacy EPD distribution history are not recoverable.
- Every named score blocker was actively checked: string starts, aliases, xrefs, package payloads, method signatures, helper types, field layout, owner/emitter, source placement, nesting, pooling, generated route, and manual rows.

## Open Questions With Attempted Resolution

- Was each string a constant or literal?
  - Checked direct operands, pointer refs, duplicate sequence count, source-family patterns, and storage pooling.
  - Resolution: ordinary inline literals; no standalone constant.
- Are interior suffixes meaningful aliases?
  - Checked all xrefs and pointer forms.
  - Resolution: no; analyzer artifacts.
- Does DLGFRAME.EPD exist?
  - Checked every current DAT and loose file.
  - Resolution: not in current package; preserve legacy literal/branch.
- What is the custom background type?
  - Checked EPFTileContext exact layout, SetBackgroundResource, DrawBackground, DrawBorder, constructor, and release behavior.
  - Resolution: one embedded EPFTileContext plus trailing int/bool, not overlapping DialogBackgroundState.
- Does BrowserDialog own base frame behavior?
  - Checked both overrides and vtable/source docs.
  - Resolution: no; it overrides EPF mode and calls base in legacy mode.
- No unresolved question blocks score, metadata, split, owner/emitter, or C++.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Current read-only snapshots at evidence time:

- `by-memory/-coverage-report.md`: SHA256 `1B2E05F2CBC154E4974CF4B7C968C7F0649BB829DDA24E064BAFD17821636F0B`, 1,783,953 bytes, 4,268 lines.
- `by-class/-coverage-report.md`: SHA256 `37519F59619A71953B1019D6175D96F19159B039CFA60763393B8DEBE918AE45`, 230,719 bytes, 622 lines.
- `by-file/-coverage-report.md`: SHA256 `D9ABC73FF0A58B75334A93EBD6B4052BA4CF9162E52C373C22071236C04BBBAD`, 132,358 bytes, 316 lines.
- `by-resource/-coverage-report.md`: SHA256 `4708C867E8F3DDC18BE7FEF33389EC5EF0A0A3FDADBFF937B70A21D54379C617`, 17,103 bytes, 49 lines.
- `by-type/-coverage-report.md`: SHA256 `FC82E0BA3F71F297BC40842249BB7C008991CB1DCEF41B27362D7FCA9D15A204`, 5,380 bytes, 34 lines.
- `by-type/by-struct/-coverage-report.md`: SHA256 `C1EF6744AC86BFE2A271E24F59541E4805FDDAF1C5D1106430221F74FB08BA0C`, 57,221 bytes, 137 lines.

The memory/class/file snapshots advanced externally during callback reconciliation. Final self-audit readback confirms UID00012R at line 1232, UID000254 at line 3746, UID0002NB at line 3750, UID00003T at line 162, and UID0000IT at line 74. The external drift is unrelated preserved concurrent content. At that readback the rows remained stale for this accepted callback: UID00012R was 90%, UID000254 was 87%, UID00003T lacked the new layout/source detail, UID0000IT was 90%, and UID0001U4 remained 86% in by-type and 87% in by-struct. UID0003AX, UID0003KG, UID0004ST/UID0004SU/UID0004SV, UID0004SW/UID0004SX, and UID0004SY were absent from their manual roots. Therefore the exact no-loss supervisor-owned replacement/insertion text below remains the handoff; B003 did not edit any manual coverage file. Later manual epochs are external supervisor-owned state.

Exact supervisor-owned replacement/insertion text:

### by-memory parent/method area

Replace UID00012R current row and insert UID0003KG/UID0004SW/UID0004SX as address-ordered children:

```text
    - [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md) 0x0049d8a0-0x0049feae | class-method aggregate | DialogPane : reconstructable : 92% : very-strong : Exact DialogPane base-method aggregate with complete lifecycle/control/animation inventory, exact SetBackgroundResource/DrawBackground/DrawBorder/SetHoverControl children, three-view class route, 0x26c layout, retained raw islands and padding, source-literal/resource roles, and blank nonduplicating aggregate C++.
        - [UID:0003KG][0x0049db60-0x0049dc05.DialogPaneSetBackgroundResource](by-memory/0x0049db60-0x0049dc05.DialogPaneSetBackgroundResource.md) 0x0049db60-0x0049dc05 | method | DialogPaneSetBackgroundResource : reconstructable : 92% : very-strong : Exact DialogPane background-resource setter; resolves a frame through ResourceLayoutTable, releases the embedded EPFTileContext, preserves mask-only custom-background semantics, allocates/copies encoded mask bytes through MemoryMan, and emits one human source body.
        - [UID:0004SW][0x0049f1d0-0x0049f2d4.DialogPaneDrawBackground](by-memory/0x0049f1d0-0x0049f2d4.DialogPaneDrawBackground.md) 0x0049f1d0-0x0049f2d4 | virtual method | DialogPaneDrawBackground : reconstructable : 92% : very-strong : Exact DialogPane DrawBackground method with EPF/EPD frame-8 selection, PAL01/NPAL8 palette split, 1-pixel EPF inset, draw-mode stores, custom encoded-mask fill path, BrowserDialog legacy fallback, and one managed source body.
        - [UID:0004SX][0x0049f2e0-0x0049f912.DialogPaneDrawBorder](by-memory/0x0049f2e0-0x0049f912.DialogPaneDrawBorder.md) 0x0049f2e0-0x0049f912 | virtual method | DialogPaneDrawBorder : reconstructable : 92% : very-strong : Exact DialogPane DrawBorder method with 14/16 tile modes, eight frame-part indices, do-while edge tiling, corner placement, PAL01/NPAL8 palettes, custom-background suppression, BrowserDialog legacy fallback, and one managed source body.
```

### by-memory read-only-data area

Replace UID000254 row and insert UID0003AX plus its three children before UID0002NB:

```text
    - [UID:000254][0x006189dc-0x00618e50.DialogCoreReadOnlyData](by-memory/0x006189dc-0x00618e50.DialogCoreReadOnlyData.md) 0x006189dc-0x00618e50 | mixed-rdata index | DialogCoreReadOnlyData : ignored : 90% : very-strong : Non-emitting dialog read-only-data index over exact DescPane/DialogPane/AlertPane/VersatileAlertPane/ModelessDialogPane vtable data, three exact dialog-frame/palette literal children, and DialogSession compiler data; every byte and boundary is classified without raw source emission.
        - [UID:0003AX][0x00618ce0-0x00618d2c.DialogFrameResourceStrings](by-memory/0x00618ce0-0x00618d2c.DialogFrameResourceStrings.md) 0x00618ce0-0x00618d2c | string-data parent | DialogFrameResourceStrings : ignored : 92% : very-strong : Non-emitting 76-byte .rdata parent over exact pooled UTF-16 literals DLGFRAME.EPF, PAL01.PAL, and DLGFRAME.EPD; three false interior suffix labels have zero xrefs, exact children carry bytes/terminators/alignment, and source expressions live in owning methods.
            - [UID:0004ST][0x00618ce0-0x00618cfc.DialogFrameEpfResourceString](by-memory/0x00618ce0-0x00618cfc.DialogFrameEpfResourceString.md) 0x00618ce0-0x00618cfc | pooled string storage | DialogFrameEpfResourceString : ignored : 92% : very-strong : Exact UTF-16 DLGFRAME.EPF literal, terminator and two-byte alignment; nine DialogPane frame refs, no interior GFRAME.EPF refs, bint1.dat nine-frame 14x14 payload, and source expression emitted only by DialogPane methods.
            - [UID:0004SU][0x00618cfc-0x00618d10.Pal01PaletteResourceString](by-memory/0x00618cfc-0x00618d10.Pal01PaletteResourceString.md) 0x00618cfc-0x00618d10 | pooled string storage | Pal01PaletteResourceString : ignored : 92% : very-strong : Exact UTF-16 PAL01.PAL literal and terminator; 23 refs in sixteen functions, no L01.PAL refs, bint2.dat DLPalette payload, shared no-owner storage, and inline source expressions in each owning consumer.
            - [UID:0004SV][0x00618d10-0x00618d2c.DialogFrameEpdResourceString](by-memory/0x00618d10-0x00618d2c.DialogFrameEpdResourceString.md) 0x00618d10-0x00618d2c | pooled string storage | DialogFrameEpdResourceString : ignored : 92% : very-strong : Exact UTF-16 DLGFRAME.EPD literal, terminator and two-byte alignment; nine DialogPane legacy-frame refs, no interior GFRAME.EPD refs, exact 16x16 frame-role behavior, missing current payload documented, and source expression emitted only by DialogPane methods.
```

UID0002NB current row text remains unchanged; only its ordinary page nesting metadata changes.

### by-class

Replace current UID00003T row:

```text
- [UID:00003T][DialogPane](by-class/DialogPane.md) : reconstructable : 92% : very-strong : Complete no-loss 0x26c DialogPane declaration with exact lifecycle/input/control/animation methods, source-ready SetBackgroundResource/DrawBackground/DrawBorder/SetHoverControl children, one non-overlapping EPFTileContext background field plus natural trailing int/bool state, exact frame/palette resource roles, compiler-vtable separation, and DialogPane.cpp ownership.
```

### by-file

Replace current UID0000IT row:

```text
- [UID:0000IT][DialogPane](by-file/DialogPane.md) : reconstructable : 92% : very-strong : Base dialog source module with complete 0x26c class declaration, exact SetBackgroundResource/DrawBackground/DrawBorder/SetHoverControl bodies, lifecycle/control/list/input/animation families, dialog-frame resource and pooling contract, BrowserDialog fallback boundary, derived consumers, active-dialog state, and compiler/source separation.
```

### by-type and by-struct

Replace UID0001U4 in both `by-type/-coverage-report.md` and `by-type/by-struct/-coverage-report.md`:

```text
- [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md) : reconstructable : 91% : very-strong : Exact 0x26c DialogPane inherited layout with title/config/List control state, drag/selection/clamp fields, one EPFTileContext background field at +0x23c..+0x263, trailing background width/state at +0x264, Boolean state at +0x268, natural tail padding, exact setup/draw consumers, and complete class-declaration route.
```

### by-resource

Insert new row after `collection-ui-resources`:

```text
- [UID:0004SY][dialog-frame-resources](by-resource/dialog-frame-resources.md) : reconstructable : 92% : very-strong : Shared base-dialog frame resources with exact DLGFRAME.EPF nine-frame 14x14 package payload, legacy DLGFRAME.EPD 16x16 executable-literal-only branch, frame-8 background and 0-7 border roles, PAL01/NPAL8 palette split, complete DialogPane draw/setup xrefs, full PAL01 sixteen-function consumer inventory, BrowserDialog override/fallback boundary, and source-literal versus pooled-storage contract.
```

Replace bounded support rows without changing their scores:

```text
- [UID:0001R5][alert-dialog-resources](by-resource/alert-dialog-resources.md) : reconstructable : 88% : strong : Shared alert resources and strings with canonical AlertPanes ownership; BDFRAME.EPF alert roles, OK label fanout, employee warning, source/resource boundaries, missing BDFRAME payload blocker, and an explicit non-owner link to the separate central DLGFRAME dialog-frame resource authority.
- [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md) : reconstructable : 89% : very-strong : BackStoryDialogPane and HistoryViewingPane story-resource boundary with current IDA/package evidence, retained/active split, BACKTALE text ownership, PAL01/NPAL8 versus NPAL4 roles, central PAL01 full-consumer authority, and missing STORY.EPD payload documented.
- [UID:0001RJ][number-input-dialog-resources](by-resource/number-input-dialog-resources.md) : reconstructable : 88% : very-strong : Number input dialog resources with exact DLGEXC3 EPF/EPD layout split, PAL01/NPAL8 palettes, control/action geometry, localized id 217, package provenance, central PAL01 full-consumer authority, and missing DLGEXC3.EPD payload documented.
```

- Reason B003 must not apply these rows directly: all listed files are supervisor-owned manual coverage artifacts.

## Follow-Up Actions

- Implementation, scoped validation, real-UID replacement, formal parity, and generated verification are complete; no B003 implementation item remains.
- Manual coverage application, exact report validation/execution/count/path, and move/archive state are external supervisor/validator-owned facts and are neither asserted nor directed by this artifact.
- UID0004ST through UID0004SY were registered serially, every provisional token was replaced before dependent validation, and all ordinary changes used one-file lease/validate/release discipline.
- No A-agent action is required.
- No additional B003 research action remains for UID0003AX unless current evidence directly contradicts this report.

## Confidence

- Recommendation confidence: 94/100.
- Score confidence: 93/100.
- Remaining uncertainty: original lexical names for `m_backgroundTileContext`, `m_backgroundImageWidth`, and `m_hasCustomBackground`; exact historical distribution of `DLGFRAME.EPD`. Neither uncertainty changes behavior, split, ownership, or formal source readiness.

## Validator Results

- Every command below ran from canonical `source-3/project-documentation` with `--apply --queue-timeout 240`; command `14326` additionally used `--wait-generated`. All returned process exit 0. Registration commands issued the listed real UIDs; every validator with an `ok` field returned `ok:1`.

| Command | Timestamp | Scoped destination / result | Side effects and warnings |
| --- | --- | --- | --- |
| `14263` | `2026-07-16T15:38:29-04:00` | registered UID0004ST | inserted UID/path/92/94/owner metadata and references; generated deferred; pre-existing missing UID00036P warning |
| `14264` | `2026-07-16T15:39:27-04:00` | registered UID0004SU | inserted UID/path/92/94/no-owner metadata and references; generated deferred |
| `14265` | `2026-07-16T15:40:13-04:00` | registered UID0004SV | inserted UID/path/92/94/owner metadata and references; generated deferred |
| `14266` | `2026-07-16T15:41:20-04:00` | registered UID0004SW | inserted source-child UID/path/metadata/formal registry; generated deferred |
| `14267` | `2026-07-16T15:42:39-04:00` | registered UID0004SX | inserted source-child UID/path/metadata/formal registry; generated deferred |
| `14268` | `2026-07-16T15:43:58-04:00` | registered UID0004SY | inserted resource UID/path/metadata/references; generated deferred |
| `14270` | `2026-07-16T15:45:50-04:00` | UID0003AX initial callback validation, `ok:1` | parent metadata/formal/reference refresh; generated deferred; pre-existing UID00036P warning |
| `14272` | `2026-07-16T15:46:24-04:00` | UID0002NB, `ok:1` | applied only Nested -4/predecessor documentation; preserved score/formal/compiler content |
| `14277` | `2026-07-16T15:47:28-04:00` | UID0003KG initial validation, `ok:1` | applied 92/94, R6, references; generated deferred |
| `14283` | `2026-07-16T15:48:00-04:00` | UID0003KG corrected validation, `ok:1` | replaced one stale MemoryMan UID link, retained R6/metadata; generated deferred |
| `14293` | `2026-07-16T15:49:30-04:00` | UID00012R, `ok:1` | applied 92/94, exact child links and summary; warnings only for pre-existing UID0003KD/UID0003KP/UID0003KO/UID0003KF references |
| `14301` | `2026-07-16T15:50:28-04:00` | UID000254, `ok:1` | applied 90/93 and exact physical child inventory; warnings only for pre-existing UID0003AW/UID00036P references |
| `14304` | `2026-07-16T15:52:03-04:00` | UID00003T, `ok:1` | applied exact R7/class layout/reference union; warnings only for pre-existing UID0003AW/UID0003KD/UID0003KP references |
| `14306` | `2026-07-16T15:53:13-04:00` | UID0000IT, `ok:1` | applied 92/94 source/resource union; warnings only for pre-existing UID0003KD/UID0003KP/UID0003AW references |
| `14307` | `2026-07-16T15:54:12-04:00` | UID0001U4, `ok:1` | applied 91/93 non-overlapping layout; warnings only for pre-existing UID0003KM/UID0003KP/UID0003KN/UID0003KD/UID0003KE references |
| `14308` | `2026-07-16T15:54:45-04:00` | UID0001R5, `ok:1` | bounded central-resource non-owner link; score/formal unchanged |
| `14309` | `2026-07-16T15:55:31-04:00` | UID0001RG, `ok:1` | bounded PAL01 authority link; score/formal unchanged |
| `14314` | `2026-07-16T15:56:18-04:00` | UID0001RJ, `ok:1` | bounded PAL01 authority link; score/formal unchanged |
| `14320` | `2026-07-16T15:57:03-04:00` | UID00020X, `ok:1` | exact base fallback calls added; score/formal unchanged |
| `14321` | `2026-07-16T15:57:45-04:00` | UID0004SW final scoped validation, `ok:1` | final R4/formal/reference registry parity; generated deferred |
| `14323` | `2026-07-16T15:58:02-04:00` | UID0004SX final scoped validation, `ok:1` | final R5/formal/reference registry parity; generated deferred |
| `14324` | `2026-07-16T15:58:28-04:00` | UID0004SY final scoped validation, `ok:1` | final resource-page metadata/reference parity; generated deferred |
| `14325` | `2026-07-16T15:58:47-04:00` | UID0003AX final scoped validation, `ok:1` | final 92/94/false/no-owner/Nested0/R0 parity; pre-existing UID00036P warning |
| `14326` | `2026-07-16T15:59:15-04:00` | UID0000IT waited refresh, `ok:1` | generated refresh completed; pre-existing UID0003KD/UID0003KP/UID0003AW warnings plus repository-wide informational autogen notices |

- Registration and changed-page validation coverage is complete for all 18 ordinary destinations. Repeated final validators on UID0003AX, UID0003KG, UID0004SW, UID0004SX, and UID0004SY verify the corrected terminal content rather than replacing another required page's scoped validation.
- R0-R3 are exact blank no-code parity; R4-R7 match their accepted destination blocks exactly after line-ending normalization.
- B003 command `14326` generated SHA256 `A31D5219BC2BDD8CD1D9DE05314B1C4BD5E09D5C4BBF7EB5AA93803FACBD127F`. Read-only external command `14347` generated SHA256 `75C1321021D0CAA60198872836ECB59BCD23F68A7FC73AFBCBFBEA4F02E7B01F` with the same B003-scope assertions: class closed before definitions; one R4, one R5, and one R6; zero physical target/child markers; zero stale suffix literals; no raw physical string arrays, handwritten vtable/RTTI/relocation data, or duplicate target method. The external checkpoint is evidence-time scoped.

## Changed Files

- Report: `tools/leaser/Agents/Agent-B003/research/0003AX-DialogFrameResourceStrings-source-quality.md`, created during report-only research and reconciled in place after callback.
- Registered ordinary files:
  - UID0004ST `by-memory/0x00618ce0-0x00618cfc.DialogFrameEpfResourceString.md`, SHA256 `EF538675938C227A65DB657A3B01E14BA847B09951BA1A2F62CC085E57F95C9E`, validator `14263`.
  - UID0004SU `by-memory/0x00618cfc-0x00618d10.Pal01PaletteResourceString.md`, SHA256 `F1160E399AAFD10EECC2509C8A42CF4F50AE740AC951E86F46A6244153463B26`, validator `14264`.
  - UID0004SV `by-memory/0x00618d10-0x00618d2c.DialogFrameEpdResourceString.md`, SHA256 `EA00135B9FBB2172AC1AF16E113246117CCCE0A893623E7744D477128E57071A`, validator `14265`.
  - UID0004SW `by-memory/0x0049f1d0-0x0049f2d4.DialogPaneDrawBackground.md`, SHA256 `7B9F3E543696746AF8CC533C7093FC5342226BC49DBDB84C50FE9514064CF0DF`, final validator `14321`.
  - UID0004SX `by-memory/0x0049f2e0-0x0049f912.DialogPaneDrawBorder.md`, SHA256 `FA96FFEB5D93547F8C71085CFF1EC6B25D2F0D7DB75345290D9300783A3BDD6E`, final validator `14323`.
  - UID0004SY `by-resource/dialog-frame-resources.md`, SHA256 `FC96153F26F56DB019204B6913C5E9667C055AEB46D7E4B36EB940DF57A264F8`, final validator `14324`.
- Modified ordinary files:
  - UID0003AX `by-memory/0x00618ce0-0x00618d2c.DialogFrameResourceStrings.md`, SHA256 `911A3762CD8C14F9072FC5D1FC84A687E52E6FBF3E6EF9551136F7ABE23FA89D`, final validator `14325`.
  - UID0002NB `by-memory/0x00618d2c-0x00618e50.DialogSessionVtableData.md`, SHA256 `92D3C03CC1885ED880AB4E2C5E164BF1694947D53CEAAA46CD5366C7F3D5C484`, validator `14272`.
  - UID0003KG `by-memory/0x0049db60-0x0049dc05.DialogPaneSetBackgroundResource.md`, SHA256 `3042F6CE2EA876D02610E682691262543899C3CF9E2547C8A654265AF4FD3C69`, final validator `14283`.
  - UID00012R `by-memory/0x0049d8a0-0x0049feae.DialogPane.md`, SHA256 `53689F4A40D3B3DD221F41B27A3212496F82B7B76FB1312B8C1A6B7BB8CCA338`, validator `14293`.
  - UID000254 `by-memory/0x006189dc-0x00618e50.DialogCoreReadOnlyData.md`, SHA256 `140A4C50AF46CC64886B5A21BCDA3F165C5E673BDBB63125F69DC999211BE575`, validator `14301`.
  - UID00003T `by-class/DialogPane.md`, SHA256 `7101A93A4EF53CFA1F11529AEF111AA94B13EBC76222ADE546D7B59D6D521DBE`, validator `14304`.
  - UID0000IT `by-file/DialogPane.md`, SHA256 `D584F93EE7238EC989EFE820DEBE2595DE76D132EC0DB680936CF77BEE1E0CBD`, validators `14306/14326`.
  - UID0001U4 `by-type/by-struct/DialogPaneLayout.md`, SHA256 `A9A98E2CEA2B5E6BADEC1C629C68D65FCD1EF90AA79B33967C346251A5DC4D86`, validator `14307`.
  - UID0001R5 `by-resource/alert-dialog-resources.md`, SHA256 `B0E67DE05EA89ADA873767FAF155B5585855268BDAC438E98CEB4AC2C3F4C0FD`, validator `14308`.
  - UID0001RG `by-resource/main-menu-story-resources.md`, SHA256 `42907576E520CD6E3652468D1F5B5163AD36D73F2CD8478D1C075A102131B661`, validator `14309`.
  - UID0001RJ `by-resource/number-input-dialog-resources.md`, SHA256 `A8F6C57CD057B7CEF1BFE89D4F02861BE6BCB7B9DA9C1F5BF0DC8DF4B3FA6B54`, validator `14314`.
  - UID00020X `by-memory/0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals.md`, SHA256 `6F201B35A0A353FDD20F90A8435991106CF6417443406E34560ACD204268844F`, validator `14320`.
- Renamed ordinary files: none.
- Restricted/read-only results: B003 did not edit manual coverage, generated output, tracker, audit/supervisor files, validator state, IDA, archive, or lifecycle files. Generated changes were validator-owned side effects of the authorized waited refresh.
- Leases: every ordinary lease was held only for its active edit/validation and released before the next. Final `current_leases.md` readback is SHA256 `EA2FA43FFE5ADAEE941CD801C5EA2E206A3D9B9D7FFC692F685134199392AAC4`, 166 bytes / 8 lines, with no active lease and zero B003 rows.
- Report execution/lifecycle: B003 performed no execute, probe, count, move, archive, revalidation, or lifecycle command.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 validation was recorded for the accepted implementation artifact.
- [x] Register UID0004ST `by-memory/0x00618ce0-0x00618cfc.DialogFrameEpfResourceString.md`.
- [x] Register UID0004SU `by-memory/0x00618cfc-0x00618d10.Pal01PaletteResourceString.md`.
- [x] Register UID0004SV `by-memory/0x00618d10-0x00618d2c.DialogFrameEpdResourceString.md`.
- [x] Register UID0004SW `by-memory/0x0049f1d0-0x0049f2d4.DialogPaneDrawBackground.md`.
- [x] Register UID0004SX `by-memory/0x0049f2e0-0x0049f912.DialogPaneDrawBorder.md`.
- [x] Register UID0004SY `by-resource/dialog-frame-resources.md`.
- [x] Replace every provisional registration token with UID0004ST through UID0004SY before dependent validation; final token count is zero.
- [x] Apply UID0003AX 92/94, false, no owner/emitter, blank position/formal, Nested0, exact Item Summary and exhaustive evidence.
- [x] Apply UID0004ST/UID0004SU/UID0004SV 92/94 false no-code metadata, exact bytes/terminators/alignment/xrefs/owner distinctions, and R1-R3.
- [x] Change UID0002NB only to Nested -4 plus predecessor link.
- [x] Apply UID0004SW/UID0004SX 92/94, owner/emitter UID00003T, true, blank position, Nested0, exact ranges/hashes/behavior and R4/R5.
- [x] Apply UID0003KG 92/94, exact Item Summary/evidence and R6.
- [x] Apply UID00012R 92/94 exact child links/rows while preserving aggregate blank C++ and unrelated inventory.
- [x] Apply UID000254 90/93 exact three-child inventory while preserving unrelated vtable data.
- [x] Apply UID00003T exact R7 and associated evidence without losing unrelated declarations.
- [x] Apply UID0000IT 92/94 exact source/resource/child route and preserve unrelated content.
- [x] Apply UID0001U4 91/93 exact non-overlapping background layout and preserve unrelated fields/history.
- [x] Apply UID0004SY full package/frame/caller/source contract.
- [x] Apply bounded UID0001R5/UID0001RG/UID0001RJ resource links with unchanged scores.
- [x] Apply bounded BrowserDialog base-fallback prose with unchanged score/formal.
- [x] Verify all named verify-only dependencies remain unchanged absent contradiction.
- [x] Preserve exact positive/negative evidence, rejected alternatives, history, package absence, compiler pooling, padding, and predecessor/successor facts.
- [x] Preserve the exact real-UID manual supervisor-owned coverage handoff without editing coverage.
- [x] Run one scoped validator for every changed/new ordinary page under short serial leases.
- [x] Run final authorized waited DialogPane refresh and verify all generated assertions.
- [x] Update C01-C20 with legal terminal states and exact destination/validator/generated proof.
- [x] Check callback items only after each is independently true.
- [x] Confirm zero B003 leases and no prohibited lifecycle/restricted-file action.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger terminalized with destination proof for C01-C20.
- [x] R0-R7 applied exactly or verified blank where required.
- [x] Metadata/score/owner/emitter/split/new-child changes applied exactly.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved without future-investigation placeholders.
- [x] Validators and final waited generated proof recorded.
- [x] Manual coverage remains supervisor-owned and exact.
- [x] No accepted implementation item remains blocked.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000014374","destination_path":"executed-b-agent-research/B003/0003AX-DialogFrameResourceStrings-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0003AX-DialogFrameResourceStrings-source-quality.md","timestamp":"2026-07-16T16:25:06-04:00","uid":"0003AX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
