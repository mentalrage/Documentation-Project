** TARGET-REPORT-UID:0002PF **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 0002PF SoftwareRenderCompatPixelCallback Source-Quality Research


## Finalized Report / Current Recommendation

- Current post-callback state: the supervisor accepted this report for implementation, and B011 applied the accepted target/support changes to the by-* docs listed below. The artifact is now ready for supervisor Gate 2 verification and supervisor-only `execute_report`.
- Final disposition applied: [UID:0002PF] `by-memory/0x004bb8d0-0x004bb9a5.SoftwareRenderCompatPixelCallback.md` is source-ready/emitting through Surface with `COMPLETION:88`, `CONFIDENCE:91`, preserved `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, and blank `EMITTER_POSITION_OPTIONAL`.
- Accepted support synchronization was applied to `by-file/Surface.md`, `by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md`, `by-global/SurfaceRenderCallbackTable.md`, and `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`. No owner route was moved to `RankingEventListPane`, `GrafPort`, `SurfaceRenderCallbackTable`, `SoftwareBlend16`, or no-owner.
- Confidence remains high for function bounds, dispatch slot, receiver fields, exact behavior, and Surface ownership; medium-high for exact original function/typedef spelling. Exact spelling remains a score cap, not a C++ blocker for this small body.

## Supporting Research

Historical report-only pass: this began as the resumed Medium report-only assignment from `tools/leaser/Agents/Agent-B011/goal.md` for UID0002PF. That pass gathered current MCP-backed evidence after the supervisor restored MCP and did not edit by-* docs, generated files, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers.

Current post-callback artifact: after supervisor Gate 1 approval, B011 edited the accepted by-* target/support docs under short leases, ran scoped validators for each changed by-* file, released all leases, and updated this report. Generated output refreshed through validator-managed deferred generation; B011 did not manually edit generated files, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers.

The target was originally an empty emitter because the formal `RECONSTRUCTION_CPP CODE` block was blank, not because the Surface output route failed. The implementation inserted the accepted formal C++ into the target, and generated `auto-generated/NexusTK/render/Surface.cpp` now shows `SoftwareRenderCompatPixelCallback` at validator command `000000006186` / `2026-07-04T06:08:31-04:00` instead of a UID0002PF empty marker.

Existing documentation that remains useful was preserved and incorporated: exact range `0x004bb8d0-0x004bb9a5`, slot `dword_69B3E0`, no direct normal callers, table/initializer data xrefs, callee set, draw-enabled guard, mode byte behavior, destination address formula, and Surface assignment. The stale "leave C++ blank because field names, callback signature, and palette/color helper names are not final-source quality" conclusion is now historicalized in the target/support docs as superseded by the current MCP/source-quality pass.

## Target

- Target UID: `0002PF`.
- Target path: `by-memory/0x004bb8d0-0x004bb9a5.SoftwareRenderCompatPixelCallback.md`.
- Source queue: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Current supervisor classification: post-Gate-1 implementation callback completed; awaiting supervisor Gate 2 verification and supervisor-only execution.
- Current scores and parent state after implementation: target is `COMPLETION:88`, `CONFIDENCE:91`; `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank `EMITTER_POSITION_OPTIONAL`; direct source route is [UID:0000OC] `Surface` / `NexusTK/render/Surface.cpp`.

## Current Target State

- Before callback: metadata was `COMPLETION:86`, `CONFIDENCE:88`; owner/emitter/reconstructable state was already valid; formal `RECONSTRUCTION_CPP CODE` was blank; generated `Surface.cpp` contained `// UID:0002PF ... Empty Emitter Marker`; and the target doc still framed field names, callback signature, and palette/color helpers as C++ blockers.
- Current implemented metadata: `COMPLETION:88`, `CONFIDENCE:91`; `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, and blank emitter position were preserved.
- Current implemented C++/emitter state: the exact formal `SoftwareRenderCompatPixelCallback` C++ block is present in the target formal block, and generated `auto-generated/NexusTK/render/Surface.cpp` refreshed at command `000000006186` with the UID0002PF body instead of an empty marker.
- Current source-quality state: the former open questions are resolved to source-facing descriptive names: `GrafPort *port` receiver, `x`, `y`, `colorIndex`, `m_drawEnabled`, `m_drawMode`, `m_surfaceContext.pixelData`, `rowStride`, `bounds`, `g_pPaletteLib->GetCurrentPalette()`, `DLPalette::MapColor`, `PointInRect`, and `BlendRgb555`. Exact original typedef/function spelling remains a score cap only.
- Related target/support docs checked: `by-file/Surface.md`, `by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md`, `by-global/SurfaceRenderCallbackTable.md`, `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`, `by-class/GrafPort.md`, `by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md`, `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`, `by-global/g_pPaletteLib.md`, `by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md`, `by-memory/0x00542ac0-0x00543149.DLPaletteMethodCluster.md`, `by-memory/0x004c0710-0x004c076d.BlendRgb555.md`, and peer `by-memory/0x004c0770-0x004c0845.SoftwareRenderRgb565PixelCallback.md`.
- Current artifact/lifecycle status: implementation callback complete; report and by-* docs are ready for supervisor Gate 2 review. B011 did not run `execute_report` or lifecycle/archive commands.

## Heuristic / Inference Reanalysis And Validation

The prior blank-C++ blocker was too broad. Each named blocker is now resolved or converted into a narrow score cap:

- Callback signature and ABI: MCP `func_profile` reports `void __thiscall(int this, int, int, unsigned int)`, no direct callers, and 84 instructions in 11 blocks. The `ret 0x0c` shape and function-pointer dispatch prove a receiver in `ecx` plus three explicit stack arguments. Current generated output and support docs already use `typedef int (__thiscall *SurfaceSpriteBlitProc)(...)` for Surface slot callbacks, so a source-facing `void __thiscall SoftwareRenderCompatPixelCallback(GrafPort *port, int x, int y, unsigned int colorIndex)` is defensible. The exact original typedef spelling remains open, but the body no longer needs raw `sub_4BB8D0` or decompiler temporaries.
- Receiver fields: `by-class/GrafPort.md`, `GrafPort::GetClipRect`, and `CompositePixels` support `m_surfaceContext.pixelData` at `+0x20`, `rowStride` at `+0x28`, `bounds.left` at `+0x2c`, `bounds.top` at `+0x30`, `m_drawMode` at `+0x70`, and `m_drawEnabled` at `+0x71`. The UID0002PF decompile uses the same offsets and formula.
- Clip and point test: callee `0x004b96c0` is accepted as `GrafPort::GetClipRect(RectBounds *outClipRect)`. Callee `0x004b7e80` is documented as `PointInRect(int y, int x, const RectBounds *bounds)` with half-open bounds. UID0002PF passes `a3, a2, &clipRect`, so source parameters should be `x` then `y`, with `PointInRect(y, x, &clipRect)`.
- Palette helpers: `g_pPaletteLib` is documented at `0x0067a7e0`, `0x00543d40` is `PaletteLib::GetCurrentPalette`, and `0x00542ac0` is `DLPalette::MapColor`. The callback maps the input color index before the mode switch, even though direct-write modes store only the low byte.
- Pixel write semantics: mode `0` writes `static_cast<unsigned char>(colorIndex)` unconditionally. Mode `1` writes that direct value only when `colorIndex != 0`. Mode `2` blends the existing destination pixel with the palette-mapped RGB555 value using `BlendRgb555(*pixel, mappedColor, 0x10)`. Mode `3` does the same blend only when `colorIndex != 0`. Default modes do nothing.
- Destination address: current decompile formula `base + 2 * (x + rowStride * (y - bounds.top) - bounds.left)` is equivalent to `static_cast<unsigned short *>(pixelData) + (y - bounds.top) * rowStride + (x - bounds.left)`. Existing `CompositePixels` formal C++ uses the same `m_surfaceContext` naming and row-stride convention.
- Ownership: target-address refs are data refs from raw setup and `sub_558840`, not Ranking UI callers. `Surface` owns the callback family and generated route. `GrafPort` supplies the receiver layout but is not the callback-table owner; `SurfaceRenderCallbackTable` owns storage semantics; `SoftwareBlend16` owns math helper `BlendRgb555`, not the installed callback body.
- Range/split: no split is needed. MCP confirms `0x004bb8d0` is a `0xd5` function, `0x004bb9a5` is not a function, and `0x004bb9a5-0x004bb9b0` is eleven `0xcc` bytes before `0x004bb9b0`.
- Rejected alternatives: raw `sub_4BB8D0`, generated `RankingEventListPane::PutPixel`, `GrafPort::PutPixel`, `SurfaceRenderCallbackTable::PutPixel`, `SoftwareBlend16::Blend...`, and no-code/blank-emitter disposition all lose material source facts or contradict xref ownership.

The remaining uncertainty is the exact public callback typedef/name and whether a future whole-family `SoftwareRenderCallbacks.cpp` source root should replace the current broad `Surface.cpp` bucket. That uncertainty justifies stopping below 95, not preserving an empty emitter.

## Evidence Standards Used

The report weights direct IDA MCP evidence highest for function boundaries, size, xrefs, callees, prototype shape, bytes, and decompiled control flow. Current by-* docs are used as support evidence only after checking their relevant target-specific claims. Generated C++ is used as route/status evidence only, not as authority for source naming. Negative evidence is explicit: no direct normal callers, no function at end, no xrefs to the end byte, no Ranking vtable/member route, no split/merge edge at `0x004bb9a5`, and no need to keep C++ blank solely because exact original typedef spelling is absent.

The evidence ladder used here is:

1. Current MCP session `73c77998` direct facts: session health, function lookup/profile, xrefs, callees, bytes, and decompile.
2. Current target/support by-* docs with accepted source-facing names and field/layout claims.
3. Generated output as read-only evidence of the current empty-marker consequence.
4. Existing executed reports searched by UID/address/name/source-family only as leads; no matching UID0002PF dedicated report was found.
5. Heuristic source-shape inference constrained by Visual C++ 6/7-era callback style and existing project `__thiscall` Surface callback typedefs.

## Evidence Checked

- IDA MCP availability/session checks: `idb_list` returned active session `73c77998` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active and not analyzing; `server_health` reported module `NexusTK.exe`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. Current MCP tool schema was rechecked; `lookup_funcs` uses `queries`, and there is no current `callers` tool, so caller absence is taken from `func_profile` plus `xrefs_to`.
- MCP call `#103 lookup_funcs` on `0x004bb8d0`, `0x004bb9a5`, `0x004bb9b0`, and `0x00558b80`: `0x004bb8d0` is `sub_4BB8D0`, size `0xd5`; `0x004bb9a5` is not a function; `0x004bb9b0` is `sub_4BB9B0`, size `0x6da`; `0x00558b80` is inside `sub_558840`, size `0x723`.
- MCP call `#104 func_profile 0x004bb8d0`: 84 instructions, 11 basic blocks, `caller_count:0`, `callee_count:7`, no string refs, prototype `void __thiscall(int this, int, int, unsigned int)`, constants `0`, `1`, `2`, `3`, and `0x10`.
- MCP call `#105 xrefs_to`: target `0x004bb8d0` has data xrefs at `0x00558745` and `0x00558b80`; end `0x004bb9a5` has no xrefs; slot storage `0x0069b3e0` has 15 refs including setup and later weather/render consumers.
- MCP call `#106 callees`: callees are `0x004b96c0`, `0x004b7e80`, `0x00543d40`, `0x00542ac0`, `0x005c772f`, and `0x004c0710`.
- MCP call `#107 get_bytes`: function start has normal prologue/security-cookie bytes; `0x004bb9a0` ends with `e5 5d c2 0c 00` (`pop ebp; retn 0x0c`) followed by eleven `0xcc` bytes before the next prologue at `0x004bb9b0`.
- MCP call `#108 decompile`: confirms draw-enabled guard at `+0x71`, `GetClipRect`, `PointInRect(y,x,clip)`, `g_pPaletteLib->GetCurrentPalette()`, `DLPalette::MapColor`, mode byte at `+0x70`, destination formula from `+0x20/+0x28/+0x2c/+0x30`, direct low-byte write in modes `0/1`, and `BlendRgb555(*dst, mappedColor, 0x10)` in modes `2/3`.
- MCP call `#109 search_text` bounded to `0x00558690-0x00558f63` for `4BB8D0`: hits at `0x00558745` and `0x00558b80`, matching target-address assignment.
- Local numeric conversions with `tools/int_convert.py`: `0xd5 = 213`, `0xb = 11`, `0x70 = 112`, `0x71 = 113`, `0x20 = 32`, `0x28 = 40`, `0x2c = 44`, `0x30 = 48`, `0x10 = 16`, `0xc = 12` (Verified with `int_convert.py`).
- Target/support docs read or searched during research and then updated during callback where accepted: target by-memory page; `by-file/Surface.md`; compat aggregate; Surface callback-table global and by-memory storage pages. Helper/support docs checked and left unchanged as sufficient: GrafPort class and `GetClipRect`; RectGeometryHelpers; `g_pPaletteLib`; PaletteLib method cluster; DLPalette method cluster; `BlendRgb555`; RGB565 peer pixel callback; SurfacePresentation; `SoftwareBlend16.md`; generated `auto-generated/NexusTK/render/Surface.cpp`.
- Old report search terms: `0002PF`, `0x004bb8d0`, `SoftwareRenderCompatPixelCallback`, `dword_69B3E0`, `PutPixel`, `RankingEventListPane::PutPixel`, and `sub_4BB8D0` across `executed-b-agent-research`, active/archived agent research, by-* docs, and generated `Surface.cpp`. No dedicated executed UID0002PF B-report was found. Matching support reports for `00016J`, `00016A`, `00016K`, `0002TD`, slot-2 callback repairs, and Surface family routing were treated as leads/support only.
- Negative checks performed: no current normal callers in `func_profile`; no xrefs to `0x004bb9a5`; no function at the end address; no target evidence for Ranking ownership; no need to merge into the line callback at `0x004bb9b0`. Support docs had narrow stale/insufficient UID0002PF source-ready wording, and that wording was repaired during the callback.
- Failed/skipped checks: a focused MCP `disasm` filter around setup returned no useful rows due address-filter mismatch; it was not needed because bounded `search_text`, `xrefs_to`, bytes, and decompile supplied the same target-assignment and boundary proof. Scoped validators were run after by-* implementation edits and are recorded below.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| 0002PF-C01 | UID0002PF is exactly `0x004bb8d0-0x004bb9a5`, `sub_4BB8D0`, size `0xd5` / 213 bytes. | high | MCP `lookup_funcs #103`, `func_profile #104`; int conversion for `0xd5`. | Target Address Range / IDA MCP Evidence | incorporate | applied |
| 0002PF-C02 | `0x004bb9a5` is not a function and the following eleven bytes are `0xcc` padding before `0x004bb9b0`. | high | MCP `lookup_funcs #103`, `get_bytes #107`; int conversion for `0xb`. | Target Address Range / Range/Split/Padding | incorporate | applied |
| 0002PF-C03 | The target has no normal direct code callers; it is reached through callback-table/initializer data refs. | high | MCP `func_profile #104 caller_count:0`, `xrefs_to #105` at `0x00558745` and `0x00558b80`. | Target IDA MCP Evidence / Ownership Notes | incorporate | applied |
| 0002PF-C04 | Slot `0x0069b3e0` / `dword_69B3E0` selects this compat callback and has 15 refs; this is slot 0 of the Surface render callback table. | high | MCP `xrefs_to #105`; `by-global/SurfaceRenderCallbackTable.md`; `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`. | Target Touched State; callback-table support docs | incorporate | applied |
| 0002PF-C05 | The binary ABI is receiver in `ecx` plus `x`, `y`, and `colorIndex` stack arguments; source-facing callback can use a `__thiscall` Surface pixel callback direction. | medium-high | MCP `func_profile #104` prototype, `retn 0x0c` bytes, existing generated `SurfaceSpriteBlitProc` `__thiscall` typedef precedent. | Target Reconstruction Notes / First-Draft C++ | incorporate | applied |
| 0002PF-C06 | The callback gates on `GrafPort::m_drawEnabled` at `+0x71`. | high | MCP decompile `#108`; `GrafPort.md` draw-state docs; int conversion for `0x71`. | Target Behavior / Touched State | incorporate | applied |
| 0002PF-C07 | The callback obtains clip bounds through `GrafPort::GetClipRect` and performs `PointInRect(y, x, &clipRect)` before writing. | high | MCP callee/decompile `#106/#108`; `GrafPortGetClipRect`; `RectGeometryHelpers`. | Target Behavior / C++ block | incorporate | applied |
| 0002PF-C08 | Destination pixel address uses `m_surfaceContext.pixelData`, `rowStride`, and `bounds.left/top` at `+0x20/+0x28/+0x2c/+0x30`. | high | MCP decompile `#108`; `GrafPort.md`; `CompositePixels` support; int conversions. | Target Touched State / C++ block | incorporate | applied |
| 0002PF-C09 | Palette mapping uses `g_pPaletteLib->GetCurrentPalette()` then `DLPalette::MapColor(colorIndex)`. | high | MCP callee/decompile `#106/#108`; `g_pPaletteLib.md`; PaletteLib and DLPalette clusters. | Target Behavior / C++ block | incorporate | applied |
| 0002PF-C10 | Mode `0/1/2/3` behavior is direct write, transparent direct write, blend, transparent blend; direct write stores low byte of `colorIndex`, blend uses `BlendRgb555` with weight `0x10`. | high | MCP `func_profile #104` constants; decompile `#108`; `BlendRgb555` support doc. | Target Behavior / C++ block | incorporate | applied |
| 0002PF-C11 | Surface / UID0000OC remains the correct canonical owner and emitter; RankingEventListPane is generated callsite pollution. | high | Target xrefs/caller absence, `Surface.md`, compat aggregate, callback table docs, `RankingDialog.md` generated pollution note. | Target Ownership Notes; Surface support | incorporate | applied |
| 0002PF-C12 | `GrafPort`, `SurfaceRenderCallbackTable`, and `SoftwareBlend16` are support/dependency owners only, not direct target owners. | high | Receiver field docs, callback-table storage role, `BlendRgb555` owner; no ordinary GrafPort method/vtable route. | Target Ownership Notes / Ranked Ownership Analysis | incorporate | applied |
| 0002PF-C13 | Formal C++ should be inserted now because reconstructable/emitter route and average score gate are already satisfied and blockers are resolved to score caps. | high | Target metadata `86/88`, by-structure code gate, current MCP/source-quality reanalysis. | Target RECONSTRUCTION_CPP CODE | incorporate | applied |
| 0002PF-C14 | Recommended target score is `COMPLETION:88`, `CONFIDENCE:91`; higher is capped by exact original typedef/function name and whole-family source-root uncertainty. | medium-high | Score blocker audit; direct evidence now resolves behavior/signature/field blockers. | Target metadata / Score Rationale | incorporate | applied |
| 0002PF-C15 | Generated `Surface.cpp` empty marker is caused by blank formal C++, not a dead owner/emitter route. | high | Generated `Surface.cpp` UID0002PF marker; target owner/emitter fields nonblank. | Target Reconstruction Notes / Changed Files | incorporate | applied |
| 0002PF-C16 | Compat aggregate remains non-emitting inventory; exact child UID0002PF carries source body. | high | Aggregate `RECONSTRUCTABLE:FALSE`; aggregate notes say code belongs on exact child pages. | Compat aggregate support | incorporate | applied |
| 0002PF-C17 | Surface file support should mark UID0002PF source-ready/emitting under `Surface.cpp` instead of leaving only stale generated `RankingEventListPane::PutPixel` wording. | medium-high | `Surface.md` current row and current target evidence. | `by-file/Surface.md` Proposed Contents / Evidence Chain | incorporate | applied |
| 0002PF-C18 | Callback-table support already maps slot 0 and only needs narrow wording that the typedef spelling remains a confidence cap, not a target C++ blocker. | medium-high | `SurfaceRenderCallbackTable.md` slot 0 row; MCP ABI evidence. | Callback-table global/by-memory support | incorporate | applied |

## Positive Evidence Summary

- Direct IDA/MCP facts: current active MCP session `73c77998` confirms the exact function range, `0xd5` size, no direct callers, no function at `0x004bb9a5`, eleven-byte padding before `0x004bb9b0`, data xrefs from setup and `sub_558840`, slot-storage refs, callee set, and a decompile that fully matches a small clipped pixel write/blend callback.
- Corroborating docs: `Surface.md` already records UID0002PF as Surface-owned; the compat aggregate records this as slot `dword_69B3E0`; callback-table docs map compat `0x004bb8d0` and RGB565 `0x004c0770`; GrafPort docs accept the receiver fields used by the target; Palette and Blend docs accept the helper names used in the body.
- Strongest inference chain: table assignment plus no direct callers proves callback dispatch, not pane method ownership. Receiver layout plus accepted GrafPort docs gives names for fields. Palette/helper docs remove raw helper blocker. The body is small enough that the remaining original-spelling uncertainty does not make the C++ speculative.

## IDA MCP Facts

- Function/range facts: `lookup_funcs #103` reports `sub_4BB8D0` at `0x004bb8d0`, size `0xd5`; `0x004bb9a5` not a function; successor `0x004bb9b0` is `sub_4BB9B0`, size `0x6da`.
- Data/table/padding facts: `get_bytes #107` shows `retn 0x0c` tail ending at `0x004bb9a5` and eleven `0xcc` bytes at `0x004bb9a5-0x004bb9b0`.
- Xref facts: `xrefs_to #105` gives target-address refs at `0x00558745` and `0x00558b80`; `0x004bb9a5` has no xrefs; `0x0069b3e0` has 15 slot refs.
- Type/prototype facts: `func_profile #104` reports prototype `void __thiscall(int this, int, int, unsigned int)`, 84 instructions, 11 basic blocks, no string refs, and caller count zero.
- Callee facts: `callees #106` returns `0x004b96c0`, `0x004b7e80`, `0x00543d40`, `0x00542ac0`, `0x005c772f`, and `0x004c0710`.
- Negative IDA facts: no normal direct callers, no function at exclusive end, no xrefs to exclusive end, no string/resource ownership signal, no vtable-only object method route, and no split boundary inside the function body.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004bb8d0-0x004bb9a5` | [UID:0002PF] `by-memory/0x004bb8d0-0x004bb9a5.SoftwareRenderCompatPixelCallback.md` | Compat/RGB555 slot-0 pixel write/blend callback | TRUE | [UID:0000OC] Surface | current `86/88`, recommended `88/91` | Source-ready with formal C++ recommended |
| `0x004bb9a5-0x004bb9b0` | ignored padding | Eleven bytes of `0xcc` alignment | FALSE | none | n/a | Already padding; no split needed |
| `0x004bb9b0-0x004bc08a` | [UID:0002PG] Line callback | Successor compat line callback | TRUE | [UID:0000OC] Surface | `86/89` in generated marker | Out of scope except as boundary successor |
| `0x004bb8d0-0x004c069e` | [UID:00016J] compat aggregate | Non-emitting callback-family inventory | FALSE | none | `89/91` | Already sufficient as container; child carries code |
| `0x0069b3e0-0x0069b3e4` | [UID:0001PI] / [UID:0000TN] slot 0 | Global callback-table slot | TRUE as table data | Surface callback table / Surface | support scores above gate | Support route for callback selection |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004bb8d0` | no normal direct callers in `func_profile #104` | Function pointer target, not ordinary call target |
| `0x00558745` | data xref to target | Raw setup/initializer writes target address |
| `0x00558b80` | data xref inside `sub_558840` | Surface initializer selects compat target into slot/table |
| `0x0069b3e0` / `dword_69B3E0` | 15 refs | Shared slot-0 dispatch storage, not ownership by a consumer |
| `0x004b96c0` | callee | `GrafPort::GetClipRect` |
| `0x004b7e80` | callee | `PointInRect(y, x, bounds)` |
| `0x00543d40` | callee | `PaletteLib::GetCurrentPalette` |
| `0x00542ac0` | callee | `DLPalette::MapColor` |
| `0x004c0710` | callee | `BlendRgb555` |
| `0x005c772f` | callee | MSVC security-cookie check glue |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion: target page, `Surface.md`, compat aggregate, callback-table global/by-memory pages, `GrafPort.md`, `GrafPortGetClipRect`, `RectGeometryHelpers`, `g_pPaletteLib`, PaletteLib/DLPalette method clusters, and `BlendRgb555`.
- Pre-callback stale/incomplete docs repaired by implementation: target Reconstruction Notes said C++ should remain blank because field names/callback signature/palette helper names were not final-source quality; `Surface.md` row foregrounded `RankingEventListPane::PutPixel in generated output` rather than source-ready Surface callback status; callback-table docs said typedef spelling remained open without making clear that this is a score cap for UID0002PF, not a blank-C++ blocker.
- Current generated/coverage state: generated `Surface.cpp` previously had UID0002PF as an empty emitter marker under validator command `000000006120` / `2026-07-04T05:14:28-04:00`. After scoped validators, generated `Surface.cpp` refreshed to command `000000006186` / `2026-07-04T06:08:31-04:00` and now contains the formal `SoftwareRenderCompatPixelCallback` body. Generated files were not edited manually.

## Ranked Ownership Analysis

### 1. [UID:0000OC] Surface / `NexusTK/render/Surface.cpp`

- Evidence for: target is installed through Surface render callback setup/table refs, has no direct ordinary callers, sits inside the compat software-render callback family, and current by-file Surface already assigns exact callback children under the Surface route. Generated `Surface.cpp` is already the emitter route for UID0002PF.
- Evidence against: the receiver layout is `GrafPort` and the public original file might later split into a dedicated software-render callback source root. Those facts affect source placement confidence, not current target ownership under existing docs.
- Decision: keep and strengthen Surface owner/emitter. Do not create a new owner in this report.

### 2. [UID:00005V] GrafPort

- Evidence for: receiver in `ecx` uses accepted GrafPort fields and calls `GrafPort::GetClipRect`; source-level callback typedef carries a `GrafPort *` receiver.
- Evidence against: no direct GrafPort method/vtable route is observed; target is selected by process-wide callback table setup; Surface callback family docs already classify these installed targets as Surface/render-dispatch implementations. A simple GrafPort method assignment would obscure the compat/RGB555 versus RGB565 callback-family selection.
- Decision: support owner for fields/methods only; not direct canonical owner/emitter.

### 3. [UID:0000TN] / [UID:0001PI] SurfaceRenderCallbackTable

- Evidence for: `dword_69B3E0` is the slot storage and table docs map this exact target.
- Evidence against: table page owns source-declared function-pointer storage, not the body implementation for each target. The exact child page and Surface file carry the source body route.
- Decision: support doc only. Update narrow slot-0 typedef/body-readiness wording if stale.

### 4. [UID:0000NT] SoftwareBlend16

- Evidence for: target calls `BlendRgb555` and implements RGB555/compat pixel behavior.
- Evidence against: `SoftwareBlend16` owns stateless pixel math helpers; UID0002PF is stateful callback-table code that clips a GrafPort and writes a destination pixel. `BlendRgb555` is a callee, not the owner.
- Decision: reject direct owner; keep as dependency.

### 5. `RankingEventListPane` / generated `PutPixel`

- Evidence for: old generated output labeled this as `RankingEventListPane::PutPixel`.
- Evidence against: current MCP finds no ordinary callers and only table/initializer target refs; `Surface.md` and `RankingDialog.md` document this family as generated callsite pollution; the function touches only render/GrafPort/Palette state, not ranking list state.
- Decision: reject. Preserve as historical generated-name evidence only.

### 6. No-owner / non-emitting / blank C++

- Evidence for: exact original callback typedef/function spelling remains unproven.
- Evidence against: by-structure allows C++ above the combined-score/emitter gate when the owner/emitter route is valid and source-quality blockers are resolved to defensible names. Current evidence resolves behavior and source-facing names enough for formal C++.
- Decision: reject. Empty marker should be removed through target formal C++ insertion after callback.

## Source Placement

- Recommended source file/class/global/module placement: keep emitted source under [UID:0000OC] `Surface` / `NexusTK/render/Surface.cpp` as `SoftwareRenderCompatPixelCallback` or an equivalent slot-0 compat pixel callback name. Use a `GrafPort *` receiver parameter to express the `ecx` callback ABI.
- Why this placement fits source-tree and subsystem context: target is one of the installed software-render callback targets, selected by Surface setup based on pixel format. `Surface.cpp` already owns render callback families and table setup context. The body is not feature UI code.
- Rejected placements: `RankingEventListPane`, `GrafPort.cpp` as a normal method, `SurfaceRenderCallbackTable` as table-owned body, `SoftwareBlend16`, and no-owner/non-emitting.
- Remaining placement uncertainty: a future whole-family report might create a narrower `SoftwareRenderCallbacks.cpp` or similar owner for the complete compat/RGB565 callback families. This report should not create a one-off file for UID0002PF.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: current MCP says `0x004bb8d0` starts `sub_4BB8D0`, size `0xd5`; `0x004bb9a5` is the exclusive end and not a function; bytes at the tail show `pop ebp; retn 0x0c` followed by eleven `0xcc`; successor `0x004bb9b0` starts the line callback.
- Children/subranges: no child split is recommended. The function is one coherent clipped point write/blend callback. External callees already have their own docs.
- Padding/table/data/code distinction: `0x004bb9a5-0x004bb9b0` is padding; `0x0069b3e0` is callback-table storage; target refs from setup are data refs, not code callers.
- Parent/container impact: compat aggregate [UID:00016J] remains `RECONSTRUCTABLE:FALSE` and non-emitting; exact child UID0002PF carries source-authored C++.

## Negative Evidence Summary

- No direct ordinary callers were found in current `func_profile`; callback reachability is by pointer/table assignment.
- No function or xref exists at `0x004bb9a5`; merge/split at the end is unsupported.
- No Ranking-specific state, vtable slot, or caller route proves Ranking ownership. The generated `RankingEventListPane::PutPixel` name is rejected as caller-biased pollution.
- No evidence supports assigning the body to `SoftwareBlend16`; the only SoftwareBlend16 item is the `BlendRgb555` callee.
- No evidence supports making the callback table the canonical owner of the body; table docs own slot storage.
- No evidence supports keeping formal C++ blank after current helper names, fields, ABI shape, and body behavior were resolved.
- The support-doc stale wording found during callback was narrow and is now repaired: UID0002PF is documented as source-ready in the Surface route, compat aggregate, and callback-table support pages. Helper docs remained sufficient and were left unchanged.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing name: `SoftwareRenderCompatPixelCallback` for the by-memory target and formal body. Alternative original spellings such as `PutPixel`, `DrawPixel`, `SetPixel`, or a table-member naming style remain possible but less precise in current docs.
- Proposed type direction: `void __thiscall SoftwareRenderCompatPixelCallback(GrafPort *port, int x, int y, unsigned int colorIndex)`. This matches `ecx` receiver plus three stack args and the no-return-value body. Exact public typedef spelling can be documented as `SurfacePixelCallback` / `SurfacePixelProc` direction in callback-table support docs.
- Proposed helper names: `GrafPort::GetClipRect`, `PointInRect`, `PaletteLib::GetCurrentPalette`, `DLPalette::MapColor`, `BlendRgb555`.
- Proposed field names: `m_drawEnabled`, `m_drawMode`, `m_surfaceContext.pixelData`, `m_surfaceContext.rowStride`, `m_surfaceContext.bounds.left`, and `m_surfaceContext.bounds.top`.
- Items intentionally left unchanged: no IDA DB rename/type/comment edits were made or requested during research or callback. This report supplies documentation/source recommendations only.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. The target is reconstructable, has nonblank `EMITTER_UIDS:0000OC`, average score is already above the current C++ gate, and this pass resolved the stated blockers to source-facing names with current MCP support.

Applied exact formal `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
void __thiscall SoftwareRenderCompatPixelCallback(GrafPort *port,
                                                  int x,
                                                  int y,
                                                  unsigned int colorIndex)
{
    if (!port->m_drawEnabled) {
        return;
    }

    RectBounds clipRect;
    port->GetClipRect(&clipRect);
    if (!PointInRect(y, x, &clipRect)) {
        return;
    }

    DLPalette *palette = g_pPaletteLib->GetCurrentPalette();
    const unsigned short mappedColor = palette->MapColor(colorIndex);
    const unsigned short directColor =
        static_cast<unsigned short>(static_cast<unsigned char>(colorIndex));

    unsigned short *pixel =
        static_cast<unsigned short *>(port->m_surfaceContext.pixelData) +
        (y - port->m_surfaceContext.bounds.top) *
            port->m_surfaceContext.rowStride +
        (x - port->m_surfaceContext.bounds.left);

    switch (port->m_drawMode) {
    case 0:
        *pixel = directColor;
        break;

    case 1:
        if (colorIndex != 0) {
            *pixel = directColor;
        }
        break;

    case 2:
        *pixel = BlendRgb555(*pixel, mappedColor, 0x10);
        break;

    case 3:
        if (colorIndex != 0) {
            *pixel = BlendRgb555(*pixel, mappedColor, 0x10);
        }
        break;

    default:
        break;
    }
}
```

Reason it preserves exact behavior:

- The early returns match the draw-enabled guard and point-in-clip check.
- The palette lookup and `MapColor` call happen after clipping and before the mode switch, matching the decompile.
- Direct modes write the low byte of the input color index; transparent direct/blend modes test full `colorIndex != 0`.
- Blend modes call `BlendRgb555` with the destination pixel, mapped RGB555 color, and fixed weight `0x10`.
- The pixel pointer formula matches the decompile's base/stride/origin calculation.
- Default/unknown mode values perform no write.

Reason it matches plausible original source shape:

- A narrow static-style Surface callback target with `GrafPort *` receiver is consistent with the existing `__thiscall` Surface callback typedef pattern.
- It uses accepted project support names instead of `sub_`, `dword_`, `_DWORD`, or decompiler temporaries.
- It keeps the function small and direct rather than introducing a new class, table wrapper, or modern abstraction.

Third-party import directive: not applicable.

Exact no-code proof: not applicable because C++ is recommended.

## Final Recommendation

- Implemented: target UID0002PF is now source-ready/emitting at `COMPLETION:88`, `CONFIDENCE:91`; owner/emitter/reconstructable fields were preserved, and the formal C++ was inserted exactly as above.
- Implemented: detailed MCP facts were incorporated into the target/support docs, including session `73c77998`, range `0x004bb8d0-0x004bb9a5`, size `0xd5`, end non-function, eleven-byte padding, no direct callers, target data xrefs `0x00558745` and `0x00558b80`, slot `dword_69B3E0`, callee set, body behavior, mode behavior, destination formula, and generated empty-marker cause.
- Implemented: support docs were updated narrowly to remove stale blank-emitter/source-blocked framing and mark UID0002PF as source-ready under Surface. The target was not moved to another owner and no new file was created.
- Future work outside this completed callback: a whole-family Surface software-render callback source-root/typedef pass could later rename or move all compat/RGB565 callback targets together. The RGB565 peer UID0002PI should not inherit this C++ without its own current source-quality callback, because RGB565 uses a different blend helper and still has peer-specific open blockers.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004bb8d0-0x004bb9a5.SoftwareRenderCompatPixelCallback.md`.
- Applied metadata changes: set `COMPLETION:88`, `CONFIDENCE:91`; preserved `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, and blank `EMITTER_POSITION_OPTIONAL`.
- Applied formal C++ change: inserted the exact C++ block from `## First-Draft C++ Recommendation` into the target formal `RECONSTRUCTION_CPP CODE` block.
- Applied report facts: MCP session `73c77998`; function range/size/end; eleven-byte `0xcc` padding; no normal callers; target-address data refs; slot `dword_69B3E0`; 15 slot refs; callee set; draw-enabled guard at `+0x71`; `m_drawMode` at `+0x70`; destination formula from `+0x20/+0x28/+0x2c/+0x30`; `GetClipRect`; `PointInRect`; `g_pPaletteLib`; `GetCurrentPalette`; `DLPalette::MapColor`; direct low-byte write; transparent nonzero checks; `BlendRgb555` with `0x10`; generated empty-marker cause.
- Preserved historical/stale assumptions: generated `RankingEventListPane::PutPixel` is historical pollution, not current owner; previous blank-C++ reason is superseded by this source-quality pass; exact typedef/function original spelling remains a confidence cap.
- Preserved rejected alternatives: Ranking ownership, GrafPort normal-method ownership, callback-table body ownership, SoftwareBlend16 body ownership, no-owner/non-emitting, split/merge at `0x004bb9a5`, and leaving C++ blank.

## Recommended Support Doc Changes

- Applied to `by-file/Surface.md`: UID0002PF row/evidence now states source-ready `SoftwareRenderCompatPixelCallback` emission through the Surface source route, includes no direct code callers, setup refs `0x00558745`/`0x00558b80`, slot `dword_69B3E0`, `GrafPort` receiver fields, clip test, palette mapping, direct/blend modes, and `BlendRgb555`; `RankingEventListPane::PutPixel` is historical generated-output pollution.
- Applied to `by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md`: slot-0 row and notes now say UID0002PF carries formal child C++ while the aggregate remains `RECONSTRUCTABLE:FALSE` and non-emitting. No metadata change was made.
- Applied to `by-global/SurfaceRenderCallbackTable.md`: slot 0 now says UID0002PF proves the compat slot-0 source-facing callback direction as receiver-in-`ecx` / `GrafPort *`, `x`, `y`, `colorIndex`; exact public typedef spelling remains a confidence cap, not a UID0002PF C++ blocker.
- Applied to `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`: storage layout, initialization table, evidence, and reconstruction notes now mirror the slot-0 UID0002PF source-ready note. No C++/metadata change was made for the storage page.
- Already-present / unchanged: `by-class/GrafPort.md` was checked as sufficient for fields `m_surfaceContext`, `m_drawMode`, `m_drawEnabled`, `GetClipRect`, and accepted row-stride/bounds naming; no direct contradiction was found.
- Already-present / unchanged: `by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md`, `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`, `by-global/g_pPaletteLib.md`, `by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md`, `by-memory/0x00542ac0-0x00543149.DLPaletteMethodCluster.md`, and `by-memory/0x004c0710-0x004c076d.BlendRgb555.md` remained sufficient support docs.
- Excluded with reason: `by-memory/0x004c0770-0x004c0845.SoftwareRenderRgb565PixelCallback.md` peer remains separate and was not edited; UID0002PI requires its own source-quality pass because RGB565 uses a different blend helper and peer-specific open blockers.

## Score And Metadata Recommendation

- Before implementation score/metadata: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank emitter position, blank formal C++.
- Applied score/metadata: `COMPLETION:88`, `CONFIDENCE:91`, owner/emitter/reconstructable fields unchanged, formal C++ populated.
- Score rationale: completion improved because this pass added current MCP session facts, exact command-backed boundary/xref/callee/decompile evidence, formal C++ body, support-doc synchronization, generated empty-marker cause, and resolved naming/type/field/source blockers. Confidence improved because current MCP aligns with multiple support docs and rejects stale owners.
- Reason not higher: exact original callback typedef/function name remains inferred; `Surface.cpp` is still a broad source route rather than a proven exact original source unit; RGB565 peer/family-wide callback typedef work remains separate; some member/helper names are source-facing accepted names rather than recovered original symbols.
- Score-improvement attempt: all previously named blockers were investigated. Callback signature resolved to receiver-in-`ecx` `__thiscall` direction; fields resolved through GrafPort docs; palette helpers resolved through PaletteLib/DLPalette docs; callback route resolved through xrefs/table docs; source placement resolved to Surface; generated empty marker resolved as blank formal C++.
- Metadata fields changed or left unchanged: only `COMPLETION`, `CONFIDENCE`, and formal C++ changed. UID, owner, reconstructable, emitter, and emitter position were not altered.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Resolution / remaining impact |
| --- | --- | --- |
| What is the source-facing callback signature? | MCP prototype, `ret 0x0c` bytes, no direct callers, table xrefs, existing `SurfaceSpriteBlitProc` `__thiscall` typedef pattern. | Resolved for target as `void __thiscall SoftwareRenderCompatPixelCallback(GrafPort *port, int x, int y, unsigned int colorIndex)`. Exact public typedef name remains a confidence cap only. |
| Are `x` and `y` ordered safely? | Decompile passes `a3, a2` to `PointInRect`; RectGeometry docs define `PointInRect(y, x, bounds)`. | Resolved: source signature uses `x, y` and calls `PointInRect(y, x, &clipRect)`. |
| Are direct-write and blend colors both palette-mapped? | MCP decompile shows `mappedColor = MapColor(colorIndex)` before the switch but direct paths write `(unsigned char)colorIndex`. | Resolved: C++ preserves direct low-byte write and blend mapped color. |
| Does `colorIndex != 0` use full input or low byte? | Decompile checks `a4` for modes 1 and 3 before write/blend. | Resolved: C++ checks full `colorIndex != 0`. |
| Should the body be a GrafPort method? | Receiver field docs, no ordinary callers, table assignment refs, Surface callback family docs. | Rejected as direct owner. `GrafPort *` is the receiver type inside a Surface callback target. |
| Should C++ remain blank until the whole callback family is typed? | Target-local ABI, fields, helper names, and behavior are all resolved; combined-score/emitter gate clears. | Rejected. Whole-family typedef/source-root work remains future support but no longer blocks UID0002PF. |
| Should the RGB565 peer be updated now? | Peer docs and support docs checked; RGB565 uses different blend helper and has its own score/source blockers. | No. UID0002PI requires its own source-quality pass. |

No in-scope question remains unresolved in a way that blocks target C++ or metadata movement.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Not applicable for this post-callback artifact. Scoped validators refreshed validator-owned generated state as a side effect. B011 did not manually edit `auto-generated/-ag-*`, `by-memory/-coverage-report.md`, or other `-coverage-report.md` files.

## Follow-Up Actions

- Supervisor Gate 2: verify this report, changed by-* docs, validator outputs, generated freshness, and claim-by-claim checklist.
- Supervisor-only after Gate 2 verification: run `execute_report` only if Gate 2 passes. B011 did not run report execution, dry-run/probing execution, lifecycle, or archive commands.
- Future adjacent work: separate source-quality passes for UID0002PI and possibly a whole-family Surface software-render callback typedef/source-root report.

## Confidence

- Recommendation confidence: high. Current MCP and support docs align on range, xrefs, behavior, owner, emitter, and source body.
- Score confidence: medium-high for `88/91`; high enough to move above current state but intentionally below final-audit range.
- Remaining uncertainty: exact original callback typedef/function name and whole-family source-file split. These are documented score caps only.

## Validator Results

- `python .\tools\validator.py --mode file --file by-memory\0x004bb8d0-0x004bb9a5.SoftwareRenderCompatPixelCallback.md --apply --queue-timeout 240`
  - command_id `000000006175`; command_timestamp `2026-07-04T06:04:32-04:00`; exit code `0`; `ok: 1`.
  - Notable output: `completion_update 0002PF ... 88`, `confidence_update 0002PF ... 91`, two `autogen_registry_update` rows, UID link normalization for `BlendRgb555`, reference-index adds for `00005V`/`0000NT`, `stats_row_remove 0002PF`, `stats_rescore_recommended`, `projected_stats_update`, and `generated_refresh: deferred`.
- `python .\tools\validator.py --mode file --file by-memory\0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md --apply --queue-timeout 240`
  - command_id `000000006176`; command_timestamp `2026-07-04T06:04:43-04:00`; exit code `0`; `ok: 1`.
  - Notable output: `stats_incremental_noop 00016J`, `projected_stats_update`, and `generated_refresh: deferred`.
- `python .\tools\validator.py --mode file --file by-memory\0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md --apply --queue-timeout 240`
  - command_id `000000006177`; command_timestamp `2026-07-04T06:04:50-04:00`; exit code `0`; `ok: 1`.
  - Warnings/side effects: `missing_ref_uid: 8` for pre-existing missing UIDs `0003ZP`, `0003XE`, and `0003PN`; UID0002PF link normalization; reference-index add for UID0002PF; `stats_incremental_noop 0001PI`; `projected_stats_update`; `generated_refresh: deferred`.
- `python .\tools\validator.py --mode file --file by-file\Surface.md --apply --queue-timeout 240`
  - command_id `000000006185`; command_timestamp `2026-07-04T06:08:22-04:00`; exit code `0`; `ok: 1`.
  - Warnings/side effects: `missing_ref_uid: 30` on older Surface references, with visible examples `00039Z`, `00039R`, `00039P`, `00039T`, `00039V`, `0003A4`, and `0003XE` plus 20 suppressed rows; `stats_row_update 0000OC`; `projected_stats_update`; `generated_refresh: deferred`.
- `python .\tools\validator.py --mode file --file by-global\SurfaceRenderCallbackTable.md --apply --queue-timeout 240`
  - command_id `000000006186`; command_timestamp `2026-07-04T06:08:31-04:00`; exit code `0`; `ok: 1`.
  - Warnings/side effects: `missing_ref_uid: 9` for pre-existing missing UIDs `0003ZP`, `0003XE`, and `00039T`; UID0002PF link normalization; reference-index add for UID0002PF; two `stats_row_update 0000TN` rows; `projected_stats_update`; `generated_refresh: deferred`.
- Generated freshness: `auto-generated/NexusTK/render/Surface.cpp` refreshed through deferred generation to validator-command-id `000000006186` / `2026-07-04T06:08:31-04:00`. UID0002PF now appears as `void __thiscall SoftwareRenderCompatPixelCallback(...)` at the generated file's UID0002PF block, and no UID0002PF empty marker remains. Other unrelated empty markers in `Surface.cpp` remain unchanged.

## Changed Files

- Modified target by-* doc: `by-memory/0x004bb8d0-0x004bb9a5.SoftwareRenderCompatPixelCallback.md`.
- Modified support by-* docs: `by-file/Surface.md`; `by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md`; `by-global/SurfaceRenderCallbackTable.md`; `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`.
- Modified report artifact: `tools/leaser/Agents/Agent-B011/research/0002PF-SoftwareRenderCompatPixelCallback-source-quality.md`.
- Validator-managed generated/registry side effects: `auto-generated/NexusTK/render/Surface.cpp` refreshed; `project-level/-auto-completion-stats.md` projected stats/rows updated; validator-managed autogen/reference registry updates were reported by scoped validators. B011 did not manually edit generated files, coverage reports, `tools/validator.ini`, queue/lock files, lifecycle/archive files, or supervisor ledgers.
- Leases used/released:
  - First lease command attempted target, Surface, compat aggregate, global table, and by-memory table. Success for target, compat aggregate, and by-memory table; Surface and global table were rejected as already leased by B010.
  - Shared lease report showed B010 held `by-file/Surface.md` and `by-global/SurfaceRenderCallbackTable.md` from `2026-07-04T10:00:47Z` to `2026-07-04T10:05:47Z`. B011 waited until expiration and retried.
  - First B011 lease batch released after validators `000000006175` through `000000006177`; release output returned `Success` for all three leased files.
  - Second B011 lease batch succeeded for `by-file/Surface.md` and `by-global/SurfaceRenderCallbackTable.md`; released after validators `000000006185` and `000000006186`; release output returned `Success` for both files.
  - Final shared lease report shows no active leases.
- Report execution: not run. B011 did not run `execute_report`, dry-run/probing execution, lifecycle/archive commands, or manual report moves.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation.
- [x] Target/support docs to update identified: target `by-memory/0x004bb8d0-0x004bb9a5.SoftwareRenderCompatPixelCallback.md`; support `by-file/Surface.md`; check/update if stale `by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md`, `by-global/SurfaceRenderCallbackTable.md`, and `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`; helper docs checked as already sufficient unless contradiction is found.
- [x] Current target state and actual evidence checked recorded, including MCP session `73c77998` and command-backed range/xref/callee/decompile facts.
- [x] Claim And Incorporation Ledger initially populated with destinations and report-only proposed states before callback; current callback states are applied in the ledger above.
- [x] Metadata/score changes to apply: `COMPLETION:88`, `CONFIDENCE:91`; preserve owner/emitter/reconstructable fields.
- [x] Score-limiting blockers researched to resolution: callback ABI/source signature, GrafPort fields, palette helpers, direct/blend mode behavior, owner/emitter route, range/padding, generated empty-marker cause.
- [x] Owner/emitter/reconstructable changes to apply: no owner/emitter/reconstructable changes; preserve `0000OC` / `TRUE` / `0000OC` and blank position.
- [x] Split/rename/new-child changes to apply: none; exact child remains one function and aggregate remains non-emitting.
- [x] Source-placement and range/padding decisions recorded: Surface route retained; no split at `0x004bb9a5`; eleven-byte padding recorded.
- [x] First-draft C++ to apply: exact formal block supplied under `## First-Draft C++ Recommendation`.
- [x] Third-party import directive: not applicable.
- [x] Exact target/support doc facts to incorporate at report-level detail listed.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve listed.
- [x] Wave2/Wave3 artifacts: no Wave2/Wave3 evidence used as authority; generated names treated as pollution/leads only.
- [x] Open questions closed or documented as score caps, not implementation blockers.
- [x] Validators to run after callback listed.
- [x] Generated refresh expected: `Surface.cpp` UID0002PF empty marker should be replaced after target formal C++ insertion and validation; generated file must not be manually edited.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Applied after Gate 1 callback authorization for UID0002PF.
- [x] Lease/edit target only when ready; release immediately after edit/validator batch. First batch leased target, compat aggregate, and by-memory table; second batch leased Surface and global table after B010's lease expired; both batches released successfully.
- [x] Insert formal C++ into target and update target metadata/evidence. Applied to `by-memory/0x004bb8d0-0x004bb9a5.SoftwareRenderCompatPixelCallback.md`; target is `88/91`, owner/emitter/reconstructable preserved, formal C++ inserted, and MCP/session/body/rejected-alternative detail added.
- [x] Update `by-file/Surface.md` with source-ready UID0002PF status. Applied after B010 lease expiry; Surface row/evidence/change log now mark UID0002PF as emitted `SoftwareRenderCompatPixelCallback` and historicalize `RankingEventListPane::PutPixel` as generated pollution.
- [x] Check/update compat aggregate and callback-table support docs only if stale or missing. Applied: compat aggregate now marks UID0002PF source-ready while preserving aggregate non-emitting status; global and memory callback-table pages now carry slot-0 source-facing callback direction and UID0002PF source-ready status without table C++.
- [x] Confirm helper docs (`GrafPort`, `GetClipRect`, RectGeometry, PaletteLib/DLPalette, `BlendRgb555`) are already sufficient or update only if a direct contradiction exists. Already-present: no direct contradiction found; helper docs were not edited.
- [x] Run scoped validators for every changed by-* doc and record command id, timestamp, exit, ok count, warnings, and generated refresh state. Applied: commands `000000006175`, `000000006176`, `000000006177`, `000000006185`, and `000000006186`, all exit `0` / `ok:1`, recorded above with warnings and generated freshness.
- [x] Update this ledger/checklist with `applied`, `already-present`, or `excluded-with-reason` for every accepted claim. Applied: claim ledger rows C01-C18 are `applied`; helper docs are `already-present`; RGB565 peer formal C++ is `excluded-with-reason` as a separate target.
- [x] Return to supervisor for Gate 2 / supervisor-only execution; do not run `execute_report`. Ready for supervisor review; B011 did not run `execute_report`, lifecycle/archive, dry-run/probing execution, or manual report move commands.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000006207","destination_path":"executed-b-agent-research/B011/0002PF-SoftwareRenderCompatPixelCallback-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/0002PF-SoftwareRenderCompatPixelCallback-source-quality.md","timestamp":"2026-07-04T06:24:19-04:00","uid":"0002PF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
