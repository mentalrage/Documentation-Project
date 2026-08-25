** TARGET-REPORT-UID:0003RB **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003RB SelfLookPane2 OnPaint Source-Quality Research

## Finalized Report / Current Recommendation
- B002 callback work is complete. [UID:0003RB] is a complete `93/94` source emitter for `void SelfLookPane2::OnPaint()` with exact range `[0x00570fc0,0x00571c05)`, owner/emitter UID0000CV, `RECONSTRUCTABLE:TRUE`, blank optional position, and `Nested:0` preserved.
- The exact 3,141-byte body is ordinary handwritten paint logic. It initializes one EPF tile context, paints a mode-selected `SELFLOOK.EPF` background through `SELFLOOK.PAL`, renders mode-0 human/monster/equipment content and five optional item layers, draws navigation/toggle buttons, renders mode-1 labels and three status values, and preserves the observed mode-0 stats-button lookup-without-render quirk.
- Helper children UID0003RF and UID0003RG now emit the exact accepted `void DrawStatText(const wchar_t *, int, int, bool)` at `92/93` and `void GetButtonRect(short, RectBounds *) const` at `92/94`; both remain class-owned with blank optional positions.
- UID0000CV is `94/94` with `void OnPaint`, both corrected helper declarations, `ObjectStatusBlob m_objectStatus`, both B002 enums, and all six executed B004 packet-update declarations merged without loss. No new type or alias was introduced.
- SelfLookPane file/parent/vtable/resource documentation is synchronized. The executed B004 UID00039M five-child split, UID0003RE `OnPacketEvent`, UID00039N `DispatchSpelledText`, packet behavior, and source order remain intact. Compiler-generated vtable, RTTI, security-cookie, and switch-table bytes remain non-handwritten output; exact source literals remain at use sites with no invented standalone global.
- Confidence is very strong for behavior, layout offsets, resource values, vtable route, helper signatures, callers, geometry, and source placement. Exact original private member/helper/enum spellings and the historical physical filename remain bounded lexical inferences.

## Supporting Research
- Evidence was collected on 2026-07-14 through streamable MCP endpoint `http://127.0.0.1:13337/mcp`. A fresh MCP initialization returned HTTP session `1c306ef9-1df8-4d5d-bc1d-ff8261a9e544`; fresh `idb_list` returned one active adopted NexusTK database session `4836cd9f`; `server_health(database=4836cd9f)` returned `status:ok`, image base `0x00400000`, auto-analysis ready, Hex-Rays ready, and a ready 2,067-entry string cache. Final report audit session `2db03ce8-691d-4de4-b253-ba068e54c421` independently repeated `idb_list`, `server_health`, UID0003RG decompilation, and the target callee inventory against database `4836cd9f` successfully. These are evidence-collection-time observations, not an assertion of future availability.
- Every evidence-collection IDB-backed call named `database:'4836cd9f'`. Bounded lookup, bytes, decompilation, disassembly, function analysis, xref, caller, callee, resource, vtable, and helper checks returned real NexusTK IDB data.
- Exact old-report search terms were: `UID0003RB`, `0003RB`, `0x00570fc0`, `0x00571c05`, `SelfLookPane2OnPaint`, `SelfLookPane2::OnPaint`, `sub_570FC0`, `DrawStatText`, `GetButtonRect`, `SELFLOOK.EPF`, `SELFLOOK.PAL`, `STATBUT.EPF`, `UID0001HK`, `UID0003RF`, and `UID0003RG`.
- Central executed root searched: `source-3/project-documentation/executed-b-agent-research`. Relevant matching artifacts opened:
  - `B001/0001HK-selflookpane2-source-split-audit.md`: exact child boundaries, parent non-emission, vtable refs, helper callers, and alignment baseline; it intentionally left target/helper bodies and source names unresolved.
  - `B001/0002V2-LookGroupCollectionResourceStringData.md`: physical resource-island split and cross-owner pooled-literal evidence.
  - `B002/0003F4-SharedStatButtonEpfResourceString-current-goal2-pass.md` and `B002/0003F4-SharedStatButtonEpfResourceString-current-no-owner-multi-emitter-recheck.md`: exact `STATBUT.EPF` bytes, ten xrefs, and accepted no-owner/two-emitter use-site disposition.
  - `B003/0003F4-SharedStatButtonEpfResourceString-advanced-scan.md`, `current-no-owner-research.md`, and `fresh-no-owner-pass.md`: independent pooled-literal confirmation; no standalone target source body.
  - `B003/0003QZ-SelfLookPane2OnDraw-source-quality.md`: accepted primary `+0x48` reclassification to `OnActivate`, full `0xd90` field map, and current class declaration baseline.
  - `B003/0003R8-SelfLookPane2ShowDefaultView-source-quality.md`, `0003R9-SelfLookPane2ShowSpelledView-source-quality.md`, `0003RA-SelfLookPane2ShowLegendView-source-quality.md`, and `0003RC-SelfLookPane2HandleKeyEvent-source-quality.md`: exact neighboring source methods, source ordering, view-mode semantics, blank-position convention, and vtable support.
  - `B003/00041R-ItemObjImageLibDrawItemImage-by-memory-source-quality.md`: item-image signature and palette-byte route.
  - `B011/0000NL-SelfLookPane-empty-emitter-family-source-quality.md`: file/class emission baseline; it did not implement UID0003RB/RF/RG.
- Historical overlap snapshot: the active B004 path `tools/leaser/Agents/Agent-B004/research/00039M-SelfLookPane2LookUpdateRawHelpers-source-quality.md` and accepted baseline SHA256 `D57991D1F3B2E8DC9F2FBDBF8DBD5AE59C2E2C7113E032506C95579E17CDC9D8` governed the report-only coordination phase. That mutable path/hash is retained only as evidence-time provenance.
- Executed overlap baseline verified before B002 edits: `executed-b-agent-research/B004/00039M-SelfLookPane2LookUpdateRawHelpers-source-quality.md`, SHA256 `0D4E676FAC6E6AF9DC1BC51AF766E0F772F6BAECD8E729D5881C738122C6EB2A`. Direct ordinary/generated readback confirmed real children UID0004Q0 through UID0004Q4, UID0003RE `OnPacketEvent`, UID00039N `DispatchSpelledText`, all six declarations, exact `ObjectStatusBlob m_objectStatus`, packet behavior/source order, compiler tables/padding, and shared UID0000CV/UID0003QZ/UID0000NL closure. B002 merged additively on that completed state.
- Other central matches (`B003/0003P9`, B005 `0002RJ`/`0003RK`, and B007 `0003V6`) were opened or classified as pooled-resource, sibling-consumer, or unrelated term matches; none is an exact UID0003RB report.
- Legacy executed roots searched: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/executed` through `Agent-B015/research/executed`; none of those directories currently exists, so there is no legacy-executed direct artifact.
- Archived roots searched: `source-3/project-documentation/tools/leaser/Agents/Older-Research` returned no matching report; `source-3/project-documentation/archived` is absent; `source-3/project-documentation/tools/leaser/Agents/SpecialReports` returned no direct target report.
- Evidence-time active roots searched: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research` through `Agent-B015/research`; no active report matched the exact UID0003RB range/target terms. The then-active B004 UID00039M artifact was overlapping shared-class/file/QZ work, not a competing direct target report; its ordered no-loss prerequisite was later satisfied by the executed artifact verified above.
- Conclusion from historical search: no executed, legacy, archived, special, or active exact UID0003RB source-quality report exists. Prior parent/sibling/resource reports are support evidence, while the executed B004 UID00039M support contract is preserved in the merged callback state.

## Target
- Target UID: `0003RB`.
- Current target path: `by-memory/0x00570fc0-0x00571c05.SelfLookPane2OnPaint.md`.
- Required report path: `tools/leaser/Agents/Agent-B002/research/0003RB-SelfLookPane2OnPaint-source-quality.md`.
- Exact modeled range: `[0x00570fc0,0x00571c05)`, `0xc45` / 3,141 bytes.
- Evidence-time metadata: `86/90`, `CANONICAL_OWNER:0000CV`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CV`, blank optional position, blank managed C++, `Nested:0`.
- Applied metadata: `93/94`; owner, emitter, reconstructable state, blank optional position, exact range, filename, and nesting are preserved, and the accepted complete managed C++ is installed.

## Current Target State
- Current applied target: UID0003RB is `93/94` with the exact accepted complete managed body and report-level range/hash/instruction/CFG/vtable/caller/callee/mode/resource/field/geometry/text/negative/compiler evidence. Scoped validator `000000012107` passed, and waited command `000000012123` emits the definition exactly once with no UID0003RB Empty Emitter Marker.
- At the read-only repair snapshot taken `2026-07-14T18:30:49-04:00`, the ordinary pages were still pre-merge: UID0000CV contained the superseded 68-byte type/field pair recorded below, stale paint/helper signatures, and no six B004 packet-update declarations; UID0003QZ still used that superseded field token; UID0000NL listed broad helper groups without the accepted five-child/UID0003RE/UID00039N closure. These are evidence-time/pre-callback facts, not an assertion of later mutable callback state and not recommended source.
- A read-only generated observation at `2026-07-14T18:30:49-04:00` (SHA256 `E92F1B1FBD4559D81278D76A0989E5996729933472D3539392C3A676AE037EBF`) showed the concurrent B004 callback in progress: first registered child UID0004Q0 emitted, while the shared SelfLookPane2 class/QZ field remained stale and UID0003RB/UID00039M Empty Emitter Markers remained. This transient snapshot is historical evidence only; it neither proves B004 completion nor defines final output.
- Current applied union: UID0000CV is `94/94` and contains `ObjectStatusBlob m_objectStatus`, all six B004 packet-update declarations, corrected void paint/stat/geometry declarations, both B002 enums, and every unrelated existing member without layout-size or field-order change. UID0003RF is `92/93`; UID0003RG is `92/94`; UID0001HK is the `91/94` non-emitting child index; UID0000NL is `92/94` prose-only source routing; UID0003QZ already matched the accepted rebased formal block and remained unchanged.

Explicitly superseded history (preserved provenance only):
- Evidence-time UID0000CV and UID0003QZ used `LivingSpriteConfig m_spriteConfig`. That pair is rejected as stale after the accepted B004 ObjectStatusBlob reconstruction. It must not occur in recommended prose, formal C++, manual coverage text, generated assertions, or callback checklist text.
- UID0001HK remains correctly non-reconstructable/non-emitting as a semantic method index. Exact children alone emit source.
- Evidence-time UID00038N/UID00038M omitted primary `+0x44 -> 0x00570fc0`; both are now `91/95` with that exact `void OnPaint` slot/source cause and their compiler comment-only blocks preserved.
- Evidence-time UID0003F3 misclassified exact UTF-16 `SELFLOOK.PAL` as adjacent fragments and UID0003F5 withheld the two exact labels. UID0003F3 is now UID-preserving renamed to `SelfLookPane2PaletteResourceString` at `90/92`; UID0003F5 is `90/92` with both exact literals/use sites; UID0003F4 retains the correct `89/92` no-owner/two-emitter pooled disposition with applied UID0003RB use-site synchronization.

## Executive Recommendation
- Applied source route: one complete `SelfLookPane2::OnPaint` definition emits from UID0003RB, followed in address/source order by complete UID0003RF and UID0003RG helper definitions through class owner UID0000CV and file route UID0000NL.
- Preserve blank optional positions. Existing SelfLookPane2 children already use address/source ordering, and introducing only partial numeric positions would risk reordering accepted siblings.
- Use `ObjectStatusBlob m_objectStatus` at `+0x108..+0x14b`. This exact 68-byte type/name pair is accepted by B004 and is used by the image-library, activation, and packet-update families. The former pair is retained only in the explicitly superseded-history subsection above, not as a second declaration or recommended token.
- Use `virtual void OnPaint()`. The target has no arguments, no meaningful return contract, one primary-vtable data route, and sibling paint APIs are void; decompiler EAX values are incidental final-call propagation.
- Use `short` for `GetButtonRect` button id and `void` for both helpers. Binary `movsx word ptr [ebp+8]`, `ret 8`, ignored EAX, and all 13 calls establish this signature.
- Keep `g_pfnBlitSprite` and `g_pfnFillRect` direct callback calls where the binary does so. Keep `RenderTileFrame` for the accepted shared palette-name wrapper calls.
- Preserve the mode-0 stats button's enabled path exactly: load frame 9 or 4, then return without `RenderTileFrame`. This oddity is observed behavior, not an omission to normalize.
- Collision-safe callback order completed: executed B004 artifact SHA `0D4E676FAC6E6AF9DC1BC51AF766E0F772F6BAECD8E729D5881C738122C6EB2A` supplied the five UID00039M children, UID0003RE, UID00039N, and shared UID0000CV/UID0003QZ/UID0000NL closure first. B002 re-read that union and applied only the accepted OnPaint/DrawStatText/GetButtonRect merge; no B004 source or evidence was overwritten or compressed.

## Supervisor Active Recheck
- Supervisor Gate 1 accepted exact report SHA `462625CBCDD5937FAB7A3E6707335B9812075BD0BB3C62E6FBAECD6A45E59095`; the authorized B002 callback, ordinary validators, lease releases, and waited generated verification are complete.
- The selected source route is supported by binary evidence, applied ordinary docs, executed B004 union, and generated readback. C01-C30 and Destinations 1-14 are terminally reconciled below.
- Current/future report path, validation count, Gate 2, manual coverage application, execution, move, and archive state are external supervisor/validator-owned and are not asserted by this callback artifact.

## Inference Research Guidance Check
- Physical bytes, function boundaries, vtable cells, calls, branches, field offsets, literal bytes, and return instructions are treated as direct evidence.
- Source names, access labels, enum labels, and historical filename are treated as strongest-current inferences and are confidence capped.
- Semantic ownership is separated from source emission: UID0003RB/RF/RG belong to class UID0000CV; file UID0000NL routes their source; UID0001HK remains a non-emitting range index; UID00038N/M remain compiler-generated ABI support.
- Pooled/source-local string policy is preserved: source literals appear in the consuming method; physical string pages do not emit invented standalone globals.
- Current accepted support types and helper names are preferred over decompiler labels. No `sub_`, `unk_`, `dword_`, `word_`, `off_`, or raw-offset identifier appears in recommended C++.

## Heuristic / Inference Reanalysis And Validation
- Function liveness: UID0003RB is a modeled 3,141-byte function with one vtable data xref and no direct code callers. This is the normal route for a virtual paint override, not evidence of dead code.
- ABI: the function receives only `this` in ECX and ends in plain `ret`. Different branches leave unrelated final-call values in EAX. Because callers dispatch through a paint slot and ignore EAX, source return is `void`, not `bool` or `int`.
- Background branch: `EPFTileContext::Initialize`, `PaletteLib::GetPaletteByName(L"SELFLOOK.PAL")`, mode-specific `SELFLOOK.EPF` frame lookup for modes 0/1/2, and one direct sprite callback are all exact. Unsupported modes deliberately pass the initialized, unpopulated context to the callback and then return after the blit.
- Human branch: kind 0 calls NewHuman bounds and overlay-bounds helpers with facing/render selector `2`, computes the exact destination around baseline 171/x 80, applies overlay/image deltas, and calls NewHuman draw with the same zero/one option sequence.
- Monster branch: kind 1 computes bounds with selector 7, centers width across x 93..117, offsets y by 140, and calls monster draw. Other status kinds skip the base sprite but still process optional item layers.
- Item layers: five independent nonzero-id branches call `GetItemGlyphBounds`, center the full glyph, and call `DrawItemImage` with the matching palette byte. Centers are head `(92,44)`, left accessory `(153,139)`, right accessory `(31,139)`, left sub-accessory `(31,202)`, and right sub-accessory `(84,202)`.
- Navigation buttons: frame A uses `5*m_buttonFrameA`, button id 4; frame B uses `5*m_buttonFrameB+1`, button id 3. Both use `STATBUT.EPF`, `BUTTON.PAL`, render mode 0, and null options.
- Mode-0 toggle states: disabled byte `0xff` sets draw color 143, sets inherited `m_drawMode` at `+0x70` to zero, and calls `g_pfnFillRect`. Enabled look uses frame 7/2; equipment uses 8/3; stats loads 9/4 but does not render it. No invalidation, null guard, or cleanup occurs.
- Mode-1 labels: set text color 128 and `m_textDrawMode=1`; copy exact UTF-16 labels to the existing 256-wide buffers; draw each three times at exact shadow/highlight coordinates and colors 128/37/37.
- Mode-1 stats: exact rectangles are `(26,58,56,70)`, `(83,58,113,70)`, and `(140,58,170,70)`. Each draw is gated independently by inherited `m_exposedRegion.IntersectsRect`, formats an unsigned percent value with `L"%u"`, centers using 10 pixels per digit, and calls `DrawStatText(..., true)`.
- UID0003RF: each glyph cell is 9x11 with row stride 9 and a 99-byte frame. Space and slash skip blitting but still advance x by 9. Frame offset is `99 * (codeUnit + 10*alternateSet - 47)`. Binary EAX is the final NUL code unit and is ignored, so source return is void.
- UID0003RG: switch input is sign-extended from 16 bits. Invalid rectangles are all `-1`. Button/mode matrix is fully closed and source return is void because every caller supplies an output pointer and ignores `InitRectBounds` EAX propagation.
- Resource typing: exact `SELFLOOK.PAL` and `SELFLOOK.EPF` each occupy 28-byte physical spans containing a 26-byte UTF-16 string plus one extra UTF-16 NUL/alignment word. IDA's split `SE`/`L`/`LOOK.*` labels are analysis artifacts, not source fragments.
- Text labels: raw UTF-16 bytes decode to `L"\ub3cc\uc544\uc628\ud6c4\ub808\uc2dc\ub9e8\ub274"` and `L"\ud3c9\ud654\uc758\uc218\ud638\uc790"`. Escaped source preserves exact code units without relying on report encoding.
- Compiler exclusions: stack cookie checks, alignment bytes, vtable/RTTI arrays, the UID0003RG jump table at `0x00572888-0x0057289f`, and decompiler stack-slot reuse are generated output. No manual source child or raw table is warranted.
- Source/type blocker closure: use accepted `ObjectStatusBlob m_objectStatus`, preserve B004's six packet-update declarations and seven source methods, and document the file-level ObjectStatusBlob header dependency. Adding a second 68-byte type, restoring the superseded field token, using a raw 68-byte array, adding a typedef duplicate, or inventing an image-library-local descriptor is rejected.
- Remaining uncertainty is lexical only. It does not block behavior-identical human-shaped source or the recommended score movement.

## Evidence Standards Used
- Primary evidence: fresh live IDA MCP function profiles, exact bytes and SHA256 values, decompilation, disassembly totals, CFG counts, vtable data, callers/xrefs/callees, literal bytes, and adjacent ranges.
- Secondary evidence: current by-memory/by-class/by-file/by-vtable/by-global/by-struct documentation, current read-only generated output, and exact executed sibling/support reports.
- Direct binary behavior outranks old prose and decompiler pseudo-types. Current accepted project declarations outrank historical unresolved aliases.
- A source draft is accepted only where every visible branch and call can be represented without inventing behavior. Compiler-only bytes receive explicit no-code dispositions.
- Score movement reflects resolved source shape, types, names, complete bodies, and integration route; it does not claim original lexical certainty.

## Evidence Checked
- MCP health/session checks: fresh `idb_list`; `server_health(database=4836cd9f)`; bounded real lookup and bytes for target, helpers, vtable, and resources.
- Target checks: `lookup_funcs(0x00570fc0)`, `analyze_function`, full `decompile`, total-instruction `disasm`, `xrefs_to`, `callees`, predecessor/successor lookup, and exact bytes/hash.
- Helper checks: `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, exact bytes/hash, and adjacent table/padding reads for `0x005726a0` and `0x00572780`.
- Resource checks: raw bytes and string probes at `0x006247b8`, `0x006247c0`, `0x00624b74`, `0x00624b78`, `0x00624b90`, `0x00624ba8`, and `0x00624bbc`; target xrefs at `0x00571005`, `0x00571579..0x00571bb5`, `0x005717ab`, and `0x00571868`.
- Vtable checks: bytes around primary base `0x006246f8`; exact target cell `0x0062473c`; existing activation cell `0x00624740`; current memory/type pages; constructor/destructor/scalar stores.
- Callee/support checks: EPFTileContext, PaletteLib, EPFLib, Surface callback table, GrafPort, RectBounds/Region, NewHumanImageLib, MonsterImageLib, ItemObjImageLib, UserStatusPane, ObjectStatusBlob, and all accepted globals.
- Current docs checked: UID0003RB, UID0003RF, UID0003RG, UID0001HK, UID0000CV, UID0000NL, UID0003QZ, UID00038N, UID00038M, UID0003F3, UID0003F4, UID0003F5, UID0002V2, UID00009S, UID0000M6, neighboring UID0003RA/UID0003RC/UID0003RD/UID0003RE/UID0003RH, UID00039M/UID00039N, the accepted B004 artifact SHA above, and verify-only rendering/image/status support.
- Current generated output checked read only: `auto-generated/NexusTK/ui/panels/SelfLookPane.cpp`.
- Manual coverage checked read only: `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, and `by-type/by-vtable/-coverage-report.md` for every affected destination and direct type dependency.
- Historical roots and exact terms are recorded under `## Supporting Research`; no direct target report exists.
- Negative checks: no direct code caller; no target interior entry; no EH catch/throw/cleanup source path; no null guards; no explicit EPFTileContext release; no invalidation; no mode 3 paint branch; no third stats-button render; no manual vtable or switch table; no source reason to retain the superseded 68-byte type alias recorded in Current Target State.
- Non-evidence tool errors: one local PowerShell `Invoke-WebRequest` omitted `-UseBasicParsing` and failed client-side before useful evidence. Initial schema-mismatched `analyze_function`, `get_bytes`, and `decompile` calls returned parameter errors, and one wrapper accidentally omitted `database`; all were discarded and rerun successfully with fresh schemas and `database:'4836cd9f'`. A final four-address convenience request exceeded its 30-second client timeout without returning evidence; an immediate bounded `server_health` remained `status:ok`, and the relevant addresses were rerun individually. MCP remained available.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Preserve UID0003RB range/owner/emitter/reconstructable/blank position/Nested 0 and raise only score to `93/94`. | very strong | Function/vtable/current metadata | Applied target metadata; validator `000000012107` | incorporate | applied |
| C02 | Exact target bytes are 3,141 bytes, SHA256 `CC267264CF264CC59CB83085165B0144DDD5780B2A0FA530B5687F437557C13E`. | very strong | MCP `get_bytes` and local SHA256 | Applied Destination 1 range/hash evidence; validator `000000012107` | incorporate | applied |
| C03 | Target is 918 instructions, 68 basic blocks, cyclomatic complexity 29, 28 callees, zero code callers, one vtable data xref. | very strong | MCP analysis/disassembly/xrefs/callees | Applied Destination 1 analysis/caller/vtable evidence | incorporate | applied |
| C04 | Source ABI is `virtual void OnPaint()`, not bool/int. | very strong | Vtable route, no args, ignored EAX, sibling paint contract | Applied Destinations 1-2/12-13; generated declaration/body unique | reject-stale | applied |
| C05 | Preserve exact mode-selected background lookup and direct palette-backed blit, including unsupported-mode behavior. | very strong | Full decompile/disassembly | Applied exact Destination 1 formal body; generated line 992 definition | incorporate | applied |
| C06 | Preserve complete human branch geometry/call order/options. | strong | Target calls/offset arithmetic | Applied Destination 1 formal body/evidence | incorporate | applied |
| C07 | Preserve complete monster branch geometry/call order/options. | strong | Target calls/offset arithmetic | Applied Destination 1 formal body/evidence | incorporate | applied |
| C08 | Preserve five optional item layers, IDs, palette bytes, centers, and no-id skips. | very strong | Five repeated target blocks | Applied Destination 1 formal body/evidence | incorporate | applied |
| C09 | Preserve navigation frames and all three toggle-button state branches. | very strong | Exact `STATBUT.EPF` calls and helper calls | Applied Destination 1 plus UID0003F4 synchronization | incorporate | applied |
| C10 | Preserve disabled fill state and enabled stats lookup-without-render quirk. | very strong | Exact branch tails at `0x571710-0x571780` | Applied Destination 1 body/evidence and generated readback | incorporate | applied |
| C11 | Preserve mode-1 text colors, positions, three draws per label, and exact literals. | very strong | Decompile, bytes, literal xrefs | Applied Destinations 1/9; validators `000000012107`/`000000012118` | incorporate | applied |
| C12 | Preserve three independently clipped percent-stat rectangles, formatting, centering, and helper calls. | very strong | Region/getter/formatter/helper sequence | Applied Destination 1 body/evidence | incorporate | applied |
| C13 | UID0003RF becomes exact void five-parameter member at `92/93`. | very strong | 209 bytes/hash/ret16/three calls | Applied Destinations 2-3; validators `000000012114`/`000000012112` | incorporate | applied |
| C14 | UID0003RF skips space/slash but always advances 9 pixels and uses exact 99-byte formula. | very strong | Helper CFG/decompile | Applied Destination 3 body/evidence; generated unique definition | incorporate | applied |
| C15 | UID0003RG becomes exact void `short`-id const member at `92/94`. | very strong | movsx word, ret8, 13 callers, ignored EAX | Applied Destinations 2/4; validators `000000012114`/`000000012113` | incorporate | applied |
| C16 | UID0003RG preserves exact five-id/three-mode rectangle matrix and invalid `-1` rectangle. | very strong | Switch decompile and table xref | Applied Destination 4 body/evidence; generated unique definition | incorporate | applied |
| C17 | UID0003RG local jump table remains compiler-generated, not a source child/table. | very strong | Bytes/xref at `0x572888` | Applied Destinations 4-5 compiler exclusion; no generated table body | reject-invalid | applied |
| C18 | UID0000CV uses accepted `ObjectStatusBlob m_objectStatus` at `+0x108`, preserves exact size/order, merges all six B004 packet-update declarations, and retains both B002 enums plus corrected paint/helper declarations. | very strong | 68-byte field span/current ObjectStatus support/executed B004 SHA | Applied merged Destination 2; validator `000000012114`; generated union unique | reject-stale | applied |
| C19 | UID0001HK retains semantic owner UID0000CV, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal C++, and updates its child/source-ready inventory to `91/94`; exact children alone emit source. | very strong | Exact split and child route | Applied Destination 5; validator `000000012115`; no parent source body | incorporate | applied |
| C20 | UID0000NL remains `NexusTK/ui/panels/SelfLookPane.cpp`, gains the paint/helper/resource/type route at `92/94`, and preserves B004's five packet-update children plus UID0003RE/UID00039N source. | very strong | Class/file/sibling/source evidence and executed B004 SHA | Applied prose-only Destination 6; validator `000000012116`; no by-file block | incorporate | applied |
| C21 | UID0003QZ receives the exact Destination 7 formal block with `m_objectStatus`/`ObjectStatusBlob`; every other accepted body/detail remains byte-for-byte and score/metadata stay unchanged. | very strong | Current body plus executed B004 token/type contract | Direct readback matched Destination 7 byte-for-byte; unchanged `92/94` | reject-stale | already-present |
| C22 | UID0003F3 is exact `SELFLOOK.PAL`, UID-preserving renamed at `90/92`; standalone C++ stays blank. | very strong | Exact 28 bytes/hash and sole target xref | Applied UID-preserving Destination 8 rename; validator `000000012117`; old path absent | reject-stale | applied |
| C23 | UID0003F5 records exact two label values and use-site emission at `90/92`; standalone C++ stays blank. | very strong | Exact 40 bytes/hash and two target xrefs | Applied Destination 9; validator `000000012118`; blank direct C++ retained | incorporate | applied |
| C24 | UID0003F4 retains `89/92`, no canonical owner, emitters `0000NL,0000P0`, blank direct C++; target now supplies one proven use route. | very strong | Existing reports, ten xrefs, source shape | Applied bounded Destination 10 prose; validator `000000012119`; metadata unchanged | already-present | applied |
| C25 | UID0002V2 remains `88/92` non-emitting/no-owner and records exact `SELFLOOK.EPF/PAL` and label child use. | strong | Physical island and source-use evidence | Applied Destination 11 prose; validator `000000012120`; blank aggregate retained | incorporate | applied |
| C26 | UID00038N/UID00038M add primary `+0x44 -> UID0003RB`, retain comment-only no-manual-array blocks, and move to `91/95`. | very strong | Exact vtable bytes/data xref | Applied Destinations 12-13; validators `000000012121`/`000000012122` | incorporate | applied |
| C27 | GrafPort/EPFTileContext/RectBounds/Region/image-library/status/global pages remain verify-only; executed B004 UID00039M children, UID0003RE, and UID00039N are preserved overlap source, not B002 edit targets. | strong | Current formal APIs and executed B004 SHA | Destination 14 readback found same-or-greater support; all pages unchanged | already-present | already-present |
| C28 | No target split, new paint child, duplicate packet body, standalone resource global, manual ABI array, or compiler support source is warranted. | very strong | Range/CFG/xrefs/source-shape and B004 split analysis | Excluded with exact reasons in range/negative/source sections; generated proves no duplicate/ABI body | reject-invalid | excluded-with-reason |
| C29 | Exact supervisor-owned manual coverage replacements/additions must merge the B002 paint/helper rows with B004's five-child/UID0003RE/UID00039N inventory; B002 must not edit coverage. | very strong | Read-only row comparison and executed B004 coverage contract | Exact merged text retained below; manual coverage remained read only | incorporate | applied |
| C30 | Callback requires B004-first/B002-second coordination, serial one-file leases, one scoped validator per B002 ordinary edit, one final waited refresh, exact combined generated counts/order, and report reconciliation. | very strong | Project workflow, emission route, executed overlap | Completed: 12 scoped ordinary validators, waited `000000012123`, zero leases, report reconciled | incorporate | applied |

## Positive Evidence Summary
- Exact target/helper boundaries, bytes, hashes, returns, CFGs, calls, and vtable cells are current MCP facts.
- The target's 28-callee inventory maps fully to accepted source-facing render, geometry, text, image, status, and resource APIs.
- Every target field offset maps into the current complete `0xd90` SelfLookPane2 declaration or inherited GrafPort/Pane state.
- Resource bytes resolve every target filename and label; no decompiler fragment label remains in source.
- UID0003RF and UID0003RG have complete caller inventories and exact formulas/matrices.
- Current sibling reports prove source order, view-mode names, class/file owner, and blank optional-position convention.
- Current ObjectStatusBlob declaration plus accepted B004 field/method contract closes the compile-visible 68-byte member and packet-helper blockers without a speculative new type.

## IDA MCP Facts
- Target: `sub_570FC0`, `[0x00570fc0,0x00571c05)`, size `0xc45`, 918 instructions, 68 blocks, complexity 29, 28 callees.
- Target SHA256: `CC267264CF264CC59CB83085165B0144DDD5780B2A0FA530B5687F437557C13E`.
- Target head: `55 8B EC 81 EC 74 01 00`; tail: `2E 5B 05 00 8B E5 5D C3`.
- Pre-padding `[0x00570fb3,0x00570fc0)`: 13 `cc`, SHA256 `0D0BB866505BC0E2D4276FCDEE1AFDC8887662D04CCE9E4BBB4C10FBA6D0F1CE`.
- Post-padding `[0x00571c05,0x00571c10)`: 11 `cc`, SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`.
- Sole target xref: data cell `0x0062473c`, primary base `0x006246f8 + 0x44`.
- UID0003RF: `[0x005726a0,0x00572771)`, size `0xd1`/209, SHA256 `226C614F852461919D89BF938CED994BDF00ADEADA36FEA01A149822E4EEA902`, 7 blocks, complexity 5, calls at `0x005719c6`, `0x00571a7f`, `0x00571b3f`, final `ret 0x10`.
- RF/RG alignment `[0x00572771,0x00572780)`: 15 `cc`, SHA256 `54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C`.
- UID0003RG: `[0x00572780,0x00572885)`, size `0x105`/261, SHA256 `ABB0BB946EB970E6776DCD1A47AD603E8752A37282FB057A41DC2FE3025F0A08`, 82 instructions, 14 blocks, complexity 10, 13 code xrefs, final `ret 8`.
- RG source-generated table/alignment: `0x00572885-0x00572888` three-byte NOP followed by six-dword switch table `0x00572888-0x005728a0`; target xref from switch at `0x00572794`; next function UID0003RH starts `0x005728a0`.
- Resource spans/hashes: `SELFLOOK.EPF` at `0x006247b8`, 28 bytes, SHA256 `2FD0DAEDA63BF81E57AEA8A8703143F3A913FE280462CE9D12015686C55AAF9E`; `SELFLOOK.PAL` at `0x00624b74`, 28 bytes, SHA256 `42245B5ADE52F5D07F39797A42358C7648F2E1F1B1A485E4A7F67EAB95265E0D`; `STATBUT.EPF` at `0x00624b90`, 24 bytes, SHA256 `58AA9C1E0AD191E1A7574C16112A05DC31537D3AE826F88130B1E3058FBC7B4B`; labels at `0x00624ba8`, 40 bytes, SHA256 `AECECC1BC48CA808E2C68994F0C5AF2F5D0247EEC46CA6CBDC77EC592971909B`.

## Function / Child Inventory
| UID | Range | Evidence-time disposition | Applied/current disposition |
| --- | --- | --- | --- |
| 0003RA | `0x00570ef0-0x00570fb3` | source-ready `ShowLegendView`, `91/94` | read only; exact predecessor |
| 0003RB | `0x00570fc0-0x00571c05` | blank `OnPaint`, `86/90` | applied complete `void OnPaint()`, `93/94`; validator 000000012107 |
| 0003RC | `0x00571c10-0x00571cb2` | source-ready key/text override | read only; exact successor |
| 0003RD | `0x00571cc0-0x005720ff` | separate pointer/input handler | verify-only caller of UID0003RG |
| 0003RF | `0x005726a0-0x00572771` | blank stat helper, `85/89` | applied complete void helper, `92/93`; validator 000000012112 |
| 0003RG | `0x00572780-0x00572885` | blank rect helper, `86/90` | applied complete void short-id helper, `92/94`; validator 000000012113 |
| 0003RH | `0x005728a0-0x005729c3` | separate hit-test helper | verify-only successor/caller context |
| 0003RE | `0x00572120-0x005725ed` | B004-owned blank packet virtual at evidence time | externally applied complete `OnPacketEvent`, `91/94`; preserved read only |
| 00039M | `0x00572b60-0x00572f25` | B004-owned broad raw-helper aggregate | externally applied non-emitting five-child split, `92/94`; preserved read only |
| 0004Q0 | `0x00572b60-0x00572c1e` | B004 registered child | externally applied `ApplySelfLookRectRecord`, `91/93`; preserved read only |
| 0004Q1 | `0x00572c20-0x00572ca0` | B004 registered child | externally applied `ApplySelfLookRectStateRecord`, `91/93`; preserved read only |
| 0004Q2 | `0x00572ca0-0x00572da4` | B004 registered child | externally applied `ApplyEquipmentSlotRecord`, `92/94`; preserved read only |
| 0004Q3 | `0x00572dd0-0x00572e88` | B004 registered child | externally applied `ClearEquipmentSlotRecord`, `92/94`; preserved read only |
| 0004Q4 | `0x00572ec0-0x00572f25` | B004 registered child | externally applied `ApplySelfLookSummaryRecord`, `91/93`; preserved read only |
| 00039N | `0x00572f30-0x00572fcf` | B004-owned blank Spelled helper at evidence time | externally applied complete `DispatchSpelledText`, `90/93`; preserved read only |
| 0001HK | `0x0056fe80-0x005729c3` | non-emitting method index, `90/93` | applied `91/94` complete inventory; non-emission retained; validator 000000012115 |

## Direct Xref / Caller Inventory
- UID0003RB: no direct code callers; one data pointer at primary cell `0x0062473c`. This is the complete virtual-call route.
- UID0003RB has exactly 28 distinct direct callee destinations. The complete address-to-source mapping is: `0x00457a60` `EPFTileContext::Initialize`; `0x00543d70` `PaletteLib::GetPaletteByName`; `0x004d02f0` `EPFLib::LookupLayoutEntry`; `0x0069b3e8` `g_pfnBlitSprite`; `0x004e09e0` `NewHumanImageLib::CalculateBounds`; `0x004e0b90` `NewHumanImageLib::ComputeOverlayBounds`; `0x004b78f0` `OffsetRect`; `0x004e06a0` `NewHumanImageLib::Draw`; `0x004db5c0` `MonsterImageLib::ComputeRenderBounds`; `0x004db3b0` `MonsterImageLib::RenderMonsterImage`; `0x004df460` `GetItemGlyphBounds`; `0x004dee50` `ItemObjImageLib::DrawItemImage`; `0x00572780` `SelfLookPane2::GetButtonRect`; `0x004b9980` `GrafPort::RenderTileFrame`; `0x004b9660` `GrafPort::SetDrawColor`; `0x0069b3fc` `g_pfnFillRect`; `0x005c772f` compiler security-cookie check; `0x004b9680` `GrafPort::SetTextColor`; `0x005cd657` `_wcscpy_s`; `0x004b9600` `GrafPort::MoveTo`; `0x004bab70` `GrafPort::DrawWideText`; `0x004b7c50` `InitRectBounds`; `0x00554a00` `Region::IntersectsRect`; `0x005b85f0` `UserStatusPane::GetPercentStatA`; `0x0041b9b0` secure wide unsigned formatting; `0x005726a0` `SelfLookPane2::DrawStatText`; `0x005b8600` `UserStatusPane::GetPercentStatB`; and `0x005b8610` `UserStatusPane::GetPercentStatC`. Repeated call sites collapse to these 28 destinations; source-level wide-string length expressions lower inline and therefore add no callee. Every source-authored destination appears in the formal body, while the security-cookie destination is explicitly compiler-only.
- UID0003RF: exactly three calls, all from target mode-1 stat draws at `0x005719c6`, `0x00571a7f`, and `0x00571b3f`.
- UID0003RG: raw toggles call at `0x005709dc`, `0x00570a9c`, `0x00570b5c`; UID0003RB calls seven times at `0x0057158e`, `0x005715e1`, `0x00571616`, `0x00571693`, `0x00571710`, `0x00571b77`, `0x00571bca`; UID0003RD calls three times at `0x00571ecd`, `0x00572045`, `0x00572055`.
- No target/helper interior address has a separate function/data route. No duplicate source helper is justified.

## Documentation Evidence And IDA Status
- Evidence-time target/class docs established range, owner, file, layout, and helper relationships but retained blank paint/helper C++, stale names/types, and pre-B004 packet-helper declarations. Applied UID0003RB/UID0003RF/UID0003RG/UID0000CV pages now carry the complete accepted bodies/declarations and exact report-level evidence under validators 000000012107/000000012112/000000012113/000000012114.
- Evidence-time UID0003F3 was stale because exact bytes form one `SELFLOOK.PAL` literal, not source fragments; it is now UID-preserving renamed and validated by 000000012117. UID0003F5 now carries exact labels/use sites under validator 000000012118. UID0003F4 retains its intentional no-owner/multi-emitter state and now records applied UID0003RB use sites under validator 000000012119.
- Evidence-time vtable docs omitted the `+0x44` paint cell immediately before `+0x48` activation. UID00038N and UID00038M now carry exact `0x0062473c -> UID0003RB`, void-source cause, and preserved comment-only compiler disposition at `91/95` under validators 000000012121 and 000000012122.
- Current EPFTileContext uses `void *pixelData`, `int rowStridePixels`, and `RectBounds bounds`; target/helper formal code uses only accepted fields and performs no void-pointer arithmetic.
- Current GrafPort support names inherited state as `m_exposedRegion`, `m_drawMode`, and `m_textDrawMode`, and exposes accepted `SetDrawColor`, `SetTextColor`, `MoveTo`, `DrawWideText`, and `RenderTileFrame` routes.
- Current ObjectStatusBlob is a complete exact 68-byte class at `92/93`; the SelfLookPane2 member span is exactly the same size and is populated through `GetSpriteConfig(ObjectStatusBlob *)` plus accepted B004 packet parsers. The merged source-facing field is `m_objectStatus`.
- Executed B004 artifact `executed-b-agent-research/B004/00039M-SelfLookPane2LookUpdateRawHelpers-source-quality.md`, verified implementation SHA `0D4E676FAC6E6AF9DC1BC51AF766E0F772F6BAECD8E729D5881C738122C6EB2A`, is the completed overlap baseline for UID00039M's five child methods, UID0003RE, UID00039N, all six declarations, and shared UID0000CV/QZ/NL synchronization. B002 direct readback preserved that complete union; the older active path/hash and partial generated snapshots remain historical only.

## Ranked Ownership Analysis
1. Accepted: class UID0000CV `SelfLookPane2`, emitted through file UID0000NL `NexusTK/ui/panels/SelfLookPane.cpp`. The receiver layout, vtable cell, sibling methods, helper calls, and existing class/file route all agree.
2. Rejected: UID0001HK as source emitter. It is a heterogeneous method-span index; exact children already prevent duplicate source.
3. Rejected: GrafPort/Surface ownership. The target consumes inherited draw state and shared callbacks but operates extensively on SelfLookPane2 fields, modes, child resources, and equipment.
4. Rejected: NewHumanImageLib, MonsterImageLib, ItemObjImageLib, EPFLib, PaletteLib, UserStatusPane, or ObjectStatusBlob ownership. They are independent callees/types/globals, not the receiver or source root.
5. Rejected: resource-data page ownership. Physical pooled/local strings explain literals only; the behavior lives at the SelfLookPane2 use site.
6. Rejected: compiler/no-code disposition. The target and both helpers are source-authored control/data flow with normal member-call ABIs.

## Source Placement
- Header/class placement: UID0000CV in the SelfLookPane module. The source/header route must make the complete `ObjectStatusBlob` declaration visible before `SelfLookPane2`; the class declaration must include `m_objectStatus`, B004's six packet-update declarations, B002's enums, and the corrected paint/helper declarations. File prose should record the `NexusTK/map/ObjectStatusBlob` dependency.
- Implementation placement: externally completed B004-owned UID00039M children, UID0003RE, and UID00039N remain their accepted out-of-class definitions in `NexusTK/ui/panels/SelfLookPane.cpp`; applied UID0003RB, UID0003RF, and UID0003RG join the same file in exact address/source order. Neither callback duplicates or removes the other's bodies.
- Parent placement: UID0001HK remains a non-emitting index. It documents the children but contributes no body.
- Resource placement: `L"SELFLOOK.EPF"`, `L"SELFLOOK.PAL"`, `L"STATBUT.EPF"`, `L"BUTTON.PAL"`, `L"%u"`, and both labels remain expressions inside `OnPaint`; no synthetic resource constants file is introduced.
- ABI placement: UID00038N/M retain comment-only formal blocks because the compiler emits table storage from the corrected virtual declaration.

## Range / Split / Padding / Reclassification Analysis
- UID0003RB range is exact and homogeneous. Thirteen pre-bytes and eleven post-bytes are parent-only `cc` alignment and remain excluded.
- The target contains no independently callable interior function, local static data owner, catch handler, cleanup funclet, or library-only contiguous subrange requiring a child split.
- Security-cookie instructions are compiler lowering around a 128-wide local stat buffer. They do not justify source wrappers.
- UID0003RF ends exactly at `0x00572771`; fifteen `cc` bytes remain parent-only before UID0003RG.
- UID0003RG ends at `0x00572885`; the three-byte NOP and six-dword switch table through `0x005728a0` are compiler-generated from its source switch. Keep them documented with UID0003RG/parent inventory, but do not expand the function body range or create a source child.
- UID0003F3 received the accepted UID-preserving path/title rename; its physical range and UID stayed exact. No split or merge occurred.

## Negative Evidence Summary
- No direct target code caller, second vtable cell, duplicate pointer, raw-call route, or interior entry exists.
- No meaningful bool/int return is consumed.
- No mode-3/Profile paint body exists; unsupported modes only perform the initialized-context blit then return.
- No target null check covers palette, image libraries, user status, item library, context, or output pointers.
- No EPFTileContext release/cleanup call appears in target or helper.
- No target invalidation or dirty-region mutation appears; Region is only queried for three stat rectangles.
- No item clipping, scaling, overlay mask, or alternate strength path appears.
- No third enabled stats-button render call exists after the final frame lookup.
- No handwritten vptr store, RTTI/vtable array, security cookie, stack unwind, or switch table is source-authored.
- No evidence supports a distinct second 68-byte declaration or continued use of the superseded field alias after the accepted ObjectStatusBlob/B004 reconstruction.

## IDA Rename / Type / Comment Recommendations
- `sub_570FC0` -> `SelfLookPane2::OnPaint` with source prototype `void __thiscall SelfLookPane2::OnPaint()`.
- `sub_5726A0` -> `SelfLookPane2::DrawStatText` with source prototype `void __thiscall SelfLookPane2::DrawStatText(const wchar_t *text, int x, int y, bool alternateSet)`.
- `sub_572780` -> `SelfLookPane2::GetButtonRect` with source prototype `void __thiscall SelfLookPane2::GetButtonRect(short buttonId, RectBounds *bounds) const`.
- `this+0x108` -> `ObjectStatusBlob m_objectStatus`; the former pair recorded in the explicitly superseded-history subsection must not remain in recommended source.
- `this+0xf8` -> `unsigned char *m_statDigitFrames`; `this+0xd7c` -> `ViewMode m_viewMode`; accepted class field names otherwise remain.
- `0x0062473c` comment -> `SelfLookPane2 primary vtable +0x44: OnPaint`.
- `0x00624b74` source comment -> `UTF-16 L"SELFLOOK.PAL"`; `0x006247b8` -> `UTF-16 L"SELFLOOK.EPF"`; labels receive exact escaped values.
- These remain source-facing naming/type/comment conclusions. No IDA mutation occurred during the callback.

## First-Draft C++ Recommendation

### Destination 1 - UID0003RB target exact managed block

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void SelfLookPane2::OnPaint()
{
    EPFTileContext tileContext;
    RectBounds imageBounds;
    RectBounds overlayBounds;
    RectBounds destinationBounds;
    RectBounds buttonBounds;
    RectBounds statBounds;
    wchar_t statText[128];

    tileContext.Initialize();
    DLPalette *palette = g_pPaletteLib->GetPaletteByName(L"SELFLOOK.PAL");

    if (m_viewMode == ViewMode_Default ||
        m_viewMode == ViewMode_Spelled ||
        m_viewMode == ViewMode_Legend)
    {
        g_pEPFLib->LookupLayoutEntry(L"SELFLOOK.EPF",
                                     m_viewMode,
                                     &tileContext);
    }

    g_pfnBlitSprite(this,
                     &tileContext,
                     &tileContext.bounds,
                     &m_bounds,
                     0,
                     palette,
                     NULL);

    if (m_viewMode == ViewMode_Default)
    {
        if (m_objectStatus.m_statusKind == ObjectStatusBlob::HumanObject)
        {
            g_pNewHumanImageLib->CalculateBounds(&m_objectStatus,
                                                 2,
                                                 0,
                                                 0,
                                                 &imageBounds,
                                                 0,
                                                 0,
                                                 1,
                                                 0);
            g_pNewHumanImageLib->ComputeOverlayBounds(&m_objectStatus,
                                                      2,
                                                      0,
                                                      0,
                                                      &overlayBounds,
                                                      0,
                                                      1);

            destinationBounds.bottom = 171;
            destinationBounds.top =
                171 - (imageBounds.bottom - imageBounds.top);
            destinationBounds.left = 80;
            destinationBounds.right =
                80 + (imageBounds.right - imageBounds.left);
            OffsetRect(&destinationBounds, overlayBounds.left, 0);
            destinationBounds.left +=
                imageBounds.left - overlayBounds.left;
            destinationBounds.right +=
                imageBounds.right - overlayBounds.right;

            g_pNewHumanImageLib->Draw(this,
                                      &destinationBounds,
                                      &m_objectStatus,
                                      2,
                                      0,
                                      0,
                                      0,
                                      0,
                                      0,
                                      0.0f,
                                      0,
                                      1,
                                      0);
        }
        else if (m_objectStatus.m_statusKind ==
                 ObjectStatusBlob::MonsterObject)
        {
            g_pMonsterImageLib->ComputeRenderBounds(&m_objectStatus,
                                                    7,
                                                    0,
                                                    &imageBounds,
                                                    NULL);

            const int width = imageBounds.right - imageBounds.left;
            const int halfWidthOffset = width / -2;
            destinationBounds.left = 93 + halfWidthOffset;
            destinationBounds.right = 117 + width + halfWidthOffset;
            destinationBounds.top = imageBounds.top + 140;
            destinationBounds.bottom = imageBounds.bottom + 140;

            g_pMonsterImageLib->RenderMonsterImage(this,
                                                   &destinationBounds,
                                                   &m_objectStatus,
                                                   7,
                                                   0,
                                                   0,
                                                   0,
                                                   NULL,
                                                   0.0f);
        }

        if (m_headId != 0)
        {
            GetItemGlyphBounds(m_headId, &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 92 + halfWidth;
            destinationBounds.right =
                92 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 44 + halfHeight;
            destinationBounds.bottom =
                44 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(this,
                                              &destinationBounds,
                                              static_cast<short>(m_headId),
                                              m_headPalette,
                                              NULL,
                                              0.0f);
        }

        if (m_leftAccessoryId != 0)
        {
            GetItemGlyphBounds(m_leftAccessoryId, &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 153 + halfWidth;
            destinationBounds.right =
                153 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 139 + halfHeight;
            destinationBounds.bottom =
                139 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(
                this,
                &destinationBounds,
                static_cast<short>(m_leftAccessoryId),
                m_leftAccessoryPalette,
                NULL,
                0.0f);
        }

        if (m_rightAccessoryId != 0)
        {
            GetItemGlyphBounds(m_rightAccessoryId, &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 31 + halfWidth;
            destinationBounds.right =
                31 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 139 + halfHeight;
            destinationBounds.bottom =
                139 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(
                this,
                &destinationBounds,
                static_cast<short>(m_rightAccessoryId),
                m_rightAccessoryPalette,
                NULL,
                0.0f);
        }

        if (m_leftSubAccessoryId != 0)
        {
            GetItemGlyphBounds(m_leftSubAccessoryId, &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 31 + halfWidth;
            destinationBounds.right =
                31 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 202 + halfHeight;
            destinationBounds.bottom =
                202 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(
                this,
                &destinationBounds,
                static_cast<short>(m_leftSubAccessoryId),
                m_leftSubAccessoryPalette,
                NULL,
                0.0f);
        }

        if (m_rightSubAccessoryId != 0)
        {
            GetItemGlyphBounds(m_rightSubAccessoryId, &imageBounds);
            const int halfWidth =
                (imageBounds.right - imageBounds.left) / -2;
            const int halfHeight =
                (imageBounds.bottom - imageBounds.top) / -2;
            destinationBounds.left = 84 + halfWidth;
            destinationBounds.right =
                84 + (imageBounds.right - imageBounds.left) + halfWidth;
            destinationBounds.top = 202 + halfHeight;
            destinationBounds.bottom =
                202 + (imageBounds.bottom - imageBounds.top) + halfHeight;
            g_pItemObjImageLib->DrawItemImage(
                this,
                &destinationBounds,
                static_cast<short>(m_rightSubAccessoryId),
                m_rightSubAccessoryPalette,
                NULL,
                0.0f);
        }

        g_pEPFLib->LookupLayoutEntry(L"STATBUT.EPF",
                                     5 * m_buttonFrameA,
                                     &tileContext);
        GetButtonRect(ButtonId_Next, &buttonBounds);
        RenderTileFrame(&tileContext,
                        &tileContext.bounds,
                        &buttonBounds,
                        0,
                        L"BUTTON.PAL",
                        NULL);

        g_pEPFLib->LookupLayoutEntry(L"STATBUT.EPF",
                                     5 * m_buttonFrameB + 1,
                                     &tileContext);
        GetButtonRect(ButtonId_Previous, &buttonBounds);
        RenderTileFrame(&tileContext,
                        &tileContext.bounds,
                        &buttonBounds,
                        0,
                        L"BUTTON.PAL",
                        NULL);

        GetButtonRect(ButtonId_Look, &buttonBounds);
        if (m_lookToggleState == ButtonVisualState_Disabled)
        {
            SetDrawColor(143);
            m_drawMode = 0;
            g_pfnFillRect(this, &buttonBounds);
        }
        else
        {
            g_pEPFLib->LookupLayoutEntry(L"STATBUT.EPF",
                                         m_lookToggleState ? 7 : 2,
                                         &tileContext);
            RenderTileFrame(&tileContext,
                            &tileContext.bounds,
                            &buttonBounds,
                            0,
                            L"BUTTON.PAL",
                            NULL);
        }

        GetButtonRect(ButtonId_Equipment, &buttonBounds);
        if (m_equipmentToggleState == ButtonVisualState_Disabled)
        {
            SetDrawColor(143);
            m_drawMode = 0;
            g_pfnFillRect(this, &buttonBounds);
        }
        else
        {
            g_pEPFLib->LookupLayoutEntry(L"STATBUT.EPF",
                                         m_equipmentToggleState ? 8 : 3,
                                         &tileContext);
            RenderTileFrame(&tileContext,
                            &tileContext.bounds,
                            &buttonBounds,
                            0,
                            L"BUTTON.PAL",
                            NULL);
        }

        GetButtonRect(ButtonId_Stats, &buttonBounds);
        if (m_statsToggleState == ButtonVisualState_Disabled)
        {
            SetDrawColor(143);
            m_drawMode = 0;
            g_pfnFillRect(this, &buttonBounds);
            return;
        }

        g_pEPFLib->LookupLayoutEntry(L"STATBUT.EPF",
                                     m_statsToggleState ? 9 : 4,
                                     &tileContext);
        return;
    }

    if (m_viewMode == ViewMode_Spelled)
    {
        SetTextColor(128);
        m_textDrawMode = 1;

        wcscpy_s(m_identityLine1,
                 256,
                 L"\ub3cc\uc544\uc628\ud6c4\ub808\uc2dc\ub9e8\ub274");
        MoveTo(59, 28);
        SetTextColor(128);
        DrawWideText(m_identityLine1,
                     static_cast<int>(wcslen(m_identityLine1)));
        MoveTo(58, 27);
        SetTextColor(37);
        DrawWideText(m_identityLine1,
                     static_cast<int>(wcslen(m_identityLine1)));
        MoveTo(57, 27);
        DrawWideText(m_identityLine1,
                     static_cast<int>(wcslen(m_identityLine1)));

        wcscpy_s(m_identityLine2,
                 256,
                 L"\ud3c9\ud654\uc758\uc218\ud638\uc790");
        MoveTo(59, 48);
        SetTextColor(128);
        DrawWideText(m_identityLine2,
                     static_cast<int>(wcslen(m_identityLine2)));
        MoveTo(58, 47);
        SetTextColor(37);
        DrawWideText(m_identityLine2,
                     static_cast<int>(wcslen(m_identityLine2)));
        MoveTo(57, 47);
        DrawWideText(m_identityLine2,
                     static_cast<int>(wcslen(m_identityLine2)));

        InitRectBounds(&statBounds, 26, 58, 56, 70);
        if (m_exposedRegion.IntersectsRect(&statBounds))
        {
            swprintf_s(statText,
                       128,
                       L"%u",
                       static_cast<unsigned int>(
                           g_activeUserStatusPane->GetPercentStatA()));
            OffsetRect(&statBounds,
                       (statBounds.right -
                        static_cast<int>(10 * wcslen(statText)) -
                        statBounds.left) /
                           2,
                       0);
            DrawStatText(statText, statBounds.left, statBounds.top, true);
        }

        InitRectBounds(&statBounds, 83, 58, 113, 70);
        if (m_exposedRegion.IntersectsRect(&statBounds))
        {
            swprintf_s(statText,
                       128,
                       L"%u",
                       static_cast<unsigned int>(
                           g_activeUserStatusPane->GetPercentStatB()));
            OffsetRect(&statBounds,
                       (statBounds.right -
                        static_cast<int>(10 * wcslen(statText)) -
                        statBounds.left) /
                           2,
                       0);
            DrawStatText(statText, statBounds.left, statBounds.top, true);
        }

        InitRectBounds(&statBounds, 140, 58, 170, 70);
        if (m_exposedRegion.IntersectsRect(&statBounds))
        {
            swprintf_s(statText,
                       128,
                       L"%u",
                       static_cast<unsigned int>(
                           g_activeUserStatusPane->GetPercentStatC()));
            OffsetRect(&statBounds,
                       (statBounds.right -
                        static_cast<int>(10 * wcslen(statText)) -
                        statBounds.left) /
                           2,
                       0);
            DrawStatText(statText, statBounds.left, statBounds.top, true);
        }
    }
    else if (m_viewMode != ViewMode_Legend)
    {
        return;
    }

    g_pEPFLib->LookupLayoutEntry(L"STATBUT.EPF",
                                 5 * m_buttonFrameA,
                                 &tileContext);
    GetButtonRect(ButtonId_Next, &buttonBounds);
    RenderTileFrame(&tileContext,
                    &tileContext.bounds,
                    &buttonBounds,
                    0,
                    L"BUTTON.PAL",
                    NULL);

    g_pEPFLib->LookupLayoutEntry(L"STATBUT.EPF",
                                 5 * m_buttonFrameB + 1,
                                 &tileContext);
    GetButtonRect(ButtonId_Previous, &buttonBounds);
    RenderTileFrame(&tileContext,
                    &tileContext.bounds,
                    &buttonBounds,
                    0,
                    L"BUTTON.PAL",
                    NULL);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 2 - UID0000CV class exact managed block

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SelfLookPane2 : public PanelPane
{
public:
    enum ViewMode
    {
        ViewMode_Default = 0,
        ViewMode_Spelled = 1,
        ViewMode_Legend = 2
    };

    enum ButtonId
    {
        ButtonId_Look = 0,
        ButtonId_Equipment = 1,
        ButtonId_Stats = 2,
        ButtonId_Previous = 3,
        ButtonId_Next = 4
    };

    enum ButtonVisualState
    {
        ButtonVisualState_Disabled = 0xff
    };

    SelfLookPane2();
    virtual ~SelfLookPane2();

    virtual void OnActivate(const unsigned char *packetData);
    virtual void OnPaint();
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandleEvent(const PanelMouseEvent *event);
    virtual bool OnPacketEvent(const PanelPacketEvent *event);

    void ShowDefaultView();
    void ShowSpelledView();
    void ShowProfileView();
    void ShowLegendView();
    void DrawStatText(const wchar_t *text,
                      int x,
                      int y,
                      bool alternateSet);
    void GetButtonRect(short buttonId, RectBounds *bounds) const;
    unsigned short HitTestButton(int x, int y) const;

    bool ApplySelfLookRectRecord(const unsigned char *packet);
    bool ApplySelfLookRectStateRecord(const unsigned char *packet);
    bool ApplyEquipmentSlotRecord(const unsigned char *packet);
    bool ClearEquipmentSlotRecord(const unsigned char *packet);
    bool ApplySelfLookSummaryRecord(const unsigned char *packet);
    bool DispatchSpelledText(const unsigned char *packet);

private:
    unsigned char *m_statDigitFrames;
    SpelledPane *m_spelledPane;
    ProfilePane *m_profilePane;
    LegendPane *m_legendPane;
    ObjectStatusBlob m_objectStatus;

    unsigned short m_headId;
    unsigned char m_headPalette;
    unsigned short m_leftAccessoryId;
    unsigned char m_leftAccessoryPalette;
    unsigned short m_rightAccessoryId;
    unsigned char m_rightAccessoryPalette;
    unsigned short m_leftSubAccessoryId;
    unsigned short m_rightSubAccessoryId;
    unsigned char m_leftSubAccessoryPalette;
    unsigned char m_rightSubAccessoryPalette;

    wchar_t m_identityLine1[256];
    wchar_t m_identityLine2[256];
    wchar_t m_statusLineA[256];
    wchar_t m_statusLineB[128];
    wchar_t m_statusName[128];
    unsigned int m_displayValueA;
    unsigned int m_displayValueB;
    unsigned char m_activationState0;
    unsigned char m_activationState1;
    unsigned char m_activationState2;
    unsigned int m_activationValue;
    unsigned int m_lastToggleTick;
    unsigned int m_toggleRepeatDelay;
    unsigned char m_equipmentToggleState;
    unsigned char m_lookToggleState;
    unsigned char m_statsToggleState;
    wchar_t m_auxiliaryText[256];
    wchar_t m_spelledSourceText[256];
    int m_viewMode;
    int m_profileState;
    int m_reservedViewState;
    int m_buttonFrameA;
    int m_buttonFrameB;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 3 - UID0003RF exact managed block

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void SelfLookPane2::DrawStatText(const wchar_t *text,
                                 int x,
                                 int y,
                                 bool alternateSet)
{
    EPFTileContext glyphContext;
    RectBounds sourceBounds;
    RectBounds destinationBounds;

    glyphContext.Initialize();
    glyphContext.rowStridePixels = 9;
    InitRectBounds(&sourceBounds, 0, 0, 9, 11);
    InitRectBounds(&destinationBounds, x, y, x + 9, y + 11);

    for (const wchar_t *current = text; *current != L'\0'; ++current)
    {
        if (*current != L' ' && *current != L'/')
        {
            glyphContext.pixelData =
                m_statDigitFrames +
                99 * (static_cast<unsigned short>(*current) +
                      10 * static_cast<int>(alternateSet) - 47);
            g_pfnBlitSprite(this,
                             &glyphContext,
                             &sourceBounds,
                             &destinationBounds,
                             1,
                             NULL,
                             NULL);
        }

        OffsetRect(&destinationBounds, 9, 0);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 4 - UID0003RG exact managed block

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void SelfLookPane2::GetButtonRect(short buttonId, RectBounds *bounds) const
{
    int left = -1;
    int top = -1;
    int right = -1;
    int bottom = -1;

    switch (buttonId)
    {
    case ButtonId_Look:
        if (m_viewMode == ViewMode_Default)
        {
            left = 57;
            top = 246;
            right = 93;
            bottom = 282;
        }
        break;

    case ButtonId_Equipment:
        if (m_viewMode == ViewMode_Default)
        {
            left = 93;
            top = 246;
            right = 129;
            bottom = 282;
        }
        break;

    case ButtonId_Stats:
        if (m_viewMode == ViewMode_Default)
        {
            left = 129;
            top = 246;
            right = 165;
            bottom = 282;
        }
        break;

    case ButtonId_Previous:
        if (m_viewMode == ViewMode_Spelled ||
            m_viewMode == ViewMode_Legend)
        {
            left = 4;
            top = 247;
            right = 40;
            bottom = 283;
        }
        break;

    case ButtonId_Next:
        if (m_viewMode == ViewMode_Default)
        {
            left = 4;
            top = 247;
            right = 40;
            bottom = 283;
        }
        else if (m_viewMode == ViewMode_Spelled)
        {
            left = 42;
            top = 247;
            right = 78;
            bottom = 283;
        }
        break;
    }

    InitRectBounds(bounds, left, top, right, bottom);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 5 - UID0001HK retained blank parent block

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

The parent retains semantic `CANONICAL_OWNER:0000CV`, `RECONSTRUCTABLE:FALSE`, and blank emitter/position/formal C++; exact children alone carry emitted source.

### Destination 7 - UID0003QZ exact rebased managed block

This is the complete recommended UID0003QZ formal block with exactly one source-facing correction from the field token recorded in explicitly superseded history to accepted `m_objectStatus`. Every other line remains the accepted UID0003QZ body:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace
{
static __forceinline unsigned char ReadSelfLookPane2Text(
    const unsigned char *packetData,
    int &offset,
    char *multibyteText,
    wchar_t *text,
    int capacity)
{
    const unsigned char byteCount = packetData[offset++];
    memmove(multibyteText, packetData + offset, byteCount);
    multibyteText[byteCount] = 0;
    const unsigned char length = static_cast<unsigned char>(
        MultiByteToWideChar(CP_ACP,
                            0,
                            multibyteText,
                            byteCount,
                            text,
                            capacity));
    text[length] = 0;
    offset += byteCount;
    return length;
}
}

void SelfLookPane2::OnActivate(const unsigned char *packetData)
{
    int offset = 1;
    wchar_t identityLine1[256];
    wchar_t statusLineA[256];
    wchar_t auxiliaryText[256];
    wchar_t statusLineB[256];
    wchar_t spelledText[256];
    wchar_t legendText[256];
    char multibyteText[256];

    m_activationState0 = packetData[offset++];
    m_activationState1 = packetData[offset++];
    m_activationState2 = packetData[offset++];

    ReadSelfLookPane2Text(packetData,
                          offset,
                          multibyteText,
                          identityLine1,
                          256);

    const unsigned char identityLine2ByteCount = packetData[offset++];
    const int identityLine2Length =
        MultiByteToWideChar(CP_ACP,
                            0,
                            reinterpret_cast<const char *>(packetData + offset),
                            identityLine2ByteCount,
                            m_identityLine2,
                            255);
    m_identityLine2[identityLine2Length] = 0;
    offset += identityLine2ByteCount;

    ReadSelfLookPane2Text(packetData,
                          offset,
                          multibyteText,
                          statusLineA,
                          256);
    g_activeUserStatusPane->SetDisplayLineA(statusLineA);

    ReadSelfLookPane2Text(packetData,
                          offset,
                          multibyteText,
                          auxiliaryText,
                          256);
    m_equipmentToggleState = packetData[offset++];

    m_activationValue = PacketBufferReadUInt32BE(packetData + offset);
    offset += 4;

    ReadSelfLookPane2Text(packetData,
                          offset,
                          multibyteText,
                          statusLineB,
                          256);
    g_activeUserStatusPane->SetDisplayLineB(statusLineB);

    const unsigned short headId = PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;
    const unsigned char headPalette = packetData[offset++];

    const unsigned short leftAccessoryId =
        PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;
    const unsigned char leftAccessoryPalette = packetData[offset++];

    const unsigned short rightAccessoryId =
        PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;
    const unsigned char rightAccessoryPalette = packetData[offset++];

    const unsigned short leftSubAccessoryId =
        PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;
    const unsigned short rightSubAccessoryId =
        PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;
    const unsigned char leftSubAccessoryPalette = packetData[offset++];
    const unsigned char rightSubAccessoryPalette = packetData[offset++];

    const unsigned char spelledLength =
        ReadSelfLookPane2Text(packetData,
                              offset,
                              multibyteText,
                              spelledText,
                              256);
    for (unsigned char index = 0; index < spelledLength; ++index)
    {
        if (spelledText[index] == L'\t')
            spelledText[index] = L'\n';
    }

    m_lookToggleState = packetData[offset++];
    m_statsToggleState = packetData[offset++];

    g_pLocalPlayer->GetSpriteConfig(&m_objectStatus);

    m_headId = headId;
    m_headPalette = headPalette;
    m_leftAccessoryId = leftAccessoryId;
    m_leftAccessoryPalette = leftAccessoryPalette;
    m_rightAccessoryId = rightAccessoryId;
    m_rightAccessoryPalette = rightAccessoryPalette;
    m_leftSubAccessoryId = leftSubAccessoryId;
    m_rightSubAccessoryId = rightSubAccessoryId;
    m_leftSubAccessoryPalette = leftSubAccessoryPalette;
    m_rightSubAccessoryPalette = rightSubAccessoryPalette;

    wcscpy_s(m_identityLine1, 256, identityLine1);
    wcscpy_s(m_statusLineA, 256, statusLineA);
    wcscpy_s(m_statusLineB, 128, statusLineB);
    g_activeUserStatusPane->CopyNameLineA(m_statusName, 128);
    m_displayValueA = g_activeUserStatusPane->GetDisplayValueA();
    m_displayValueB = g_activeUserStatusPane->GetDisplayValueB();
    wcscpy_s(m_auxiliaryText, 256, auxiliaryText);
    wcscpy_s(m_spelledSourceText, 256, spelledText);

    m_spelledPane->ParseAndLoadEntries(m_spelledSourceText,
                                       static_cast<int>(wcslen(m_spelledSourceText)));

    m_legendPane->ClearText();
    m_legendPane->SetEditActiveState(true, false);

    const unsigned short legendEntryCount =
        PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;
    short legendTextOffset = 0;

    for (unsigned short entry = 0; entry < legendEntryCount; ++entry)
    {
        const unsigned char symbolIndex = packetData[offset++];
        const unsigned char textColor = packetData[offset++];
        short legendLength =
            ReadSelfLookPane2Text(packetData,
                                  offset,
                                  multibyteText,
                                  legendText,
                                  256);
        legendText[legendLength++] = L'\r';
        legendText[legendLength] = 0;

        EPFTextEditObject *symbol =
            new EPFTextEditObject(m_legendPane, symbolIndex);
        m_legendPane->InsertText(L" ", 0);
        m_legendPane->InsertEmbeddedObject(symbol, 12, 12);

        const short textStart = static_cast<short>(legendTextOffset + 2);
        m_legendPane->SetText(legendText, legendLength, 0, 0);
        const short textEnd = static_cast<short>(textStart + legendLength);

        unsigned int formatData[3] = { 0, textColor, 0 };
        m_legendPane->SetSelectionRange(textStart, textEnd);
        m_legendPane->ApplySelectionFormat(2, formatData);
        m_legendPane->SetSelectionRange(textEnd, textEnd);
        legendTextOffset = textEnd;
    }

    m_legendPane->SetEditActiveState(false, false);
    m_profileState = 0;

    m_spelledPane->RemoveFromLayer();
    m_spelledPane->UnregisterEventHandler();
    m_legendPane->RemoveFromLayer();
    m_legendPane->UnregisterEventHandler();
    m_spelledPane->RefreshScrollState();

    if (m_viewMode == ViewMode_Spelled)
        ShowSpelledView();
    else if (m_viewMode == ViewMode_Legend)
        ShowLegendView();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 8 - UID0003F3 exact blank direct block

UID0003F3 receives exactly this managed block because its source representation is `L"SELFLOOK.PAL"` inside Destination 1, not a standalone declaration:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 9 - UID0003F5 exact blank direct block

UID0003F5 receives exactly this managed block because its two source representations are the exact escaped label literals inside Destination 1, not standalone declarations:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 10 - UID0003F4 exact blank direct block

UID0003F4 retains exactly this managed block because pooled `L"STATBUT.EPF"` emits at its accepted SelfLookPane2/UserLookPane use sites, not as a standalone declaration:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 11 - UID0002V2 exact blank aggregate block

UID0002V2 retains exactly this managed block because it is a non-emitting resource-island index whose exact literals emit only through their source-use children:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destinations 12-13 - vtable no-code blocks

UID00038N retains exactly:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-generated SelfLookPane2 RTTI and vtable data; no manual source array.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

UID00038M retains exactly:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-generated SelfLookPane and SelfLookPane2 RTTI and vtable data; no manual source arrays.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

## Final Recommendation
- C01-C30 and Destinations 1-14 are applied or verified exactly within the bounded callback. Every accepted ordinary edit carries full report-level evidence/prose, not only scores and code.
- The five complete source-bearing blocks are synchronized exactly: UID0003RB, merged UID0000CV, UID0003RF, UID0003RG, and already-matching rebased UID0003QZ. Blank parent/resource blocks and comment-only vtable blocks are preserved.
- Preserve every unrelated SelfLookPane/SelfLookPane2 sibling, raw helper, Profile caveat, child-pane route, compiler distinction, and historical provenance entry, including B004's accepted five UID00039M child methods, UID0003RE `OnPacketEvent`, UID00039N `DispatchSpelledText`, six declarations, and packet/compiler-data dispositions.
- Do not create new method children, a new 68-byte type, resource globals, or manual ABI source.
- Executed B004 work supplied the packet-update closure first. B002 then applied only the merged OnPaint/helper closure after direct readback; no field token, packet declaration/body, or richer B004 packet evidence was reset. Scoped validators, final waited combined generated verification, report reconciliation, and lease release are complete. Report validation/execution/move/archive remains supervisor-owned and is not asserted.

## Recommended Target Doc Changes
### Destination 1 - `by-memory/0x00570fc0-0x00571c05.SelfLookPane2OnPaint.md`
- Applied `COMPLETION:93`, `CONFIDENCE:94`; preserved all other metadata and exact path/range.
- Installed Destination 1 byte-for-byte in place of the blank managed block.
- Replaced the stale blocker with complete exact bytes/hash/instructions/CFG/vtable/callers/callees, modes, fields/types, resources/labels, geometry, status calculations, helpers, negative evidence, compiler exclusions, rejected alternatives, score rationale, and historical labels.
- Item Summary now identifies the complete primary `+0x44` `void OnPaint` body and exact quirks.

## Recommended Support Doc Changes
### Destination 2 - `by-class/SelfLookPane2.md`
- Applied `94/94` and exact Destination 2; preserved `CANONICAL_OWNER:0000NL`, emitter, reconstructable, blank position, class size/order, and all unrelated content.
- Synchronized method inventory, field table, vtable slots, paint/helper behavior, `ObjectStatusBlob m_objectStatus`, resources, compiler exclusions, and superseded history while preserving B004's five packet-update methods, UID0003RE, UID00039N, and all six declarations.

### Destination 3 - `by-memory/0x005726a0-0x00572771.SelfLookPane2DrawStatText.md`
- Applied `92/93`, preserved owner/emitter/reconstructable/blank position/Nested 0/range, and installed Destination 3 exactly with all listed evidence.

### Destination 4 - `by-memory/0x00572780-0x00572885.SelfLookPane2GetButtonRect.md`
- Applied `92/94`, preserved owner/emitter/reconstructable/blank position/Nested 0/range, and installed Destination 4 exactly with all listed evidence.

### Destination 5 - `by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md`
- Applied `91/94`; retained semantic `CANONICAL_OWNER:0000CV`, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal state, and exact child-only emission while updating the complete target/helper/padding/table/type inventory.

### Destination 6 - `by-file/SelfLookPane.md`
- Applied `92/94` prose only with no reconstruction metadata; added complete UID0003RB/RF/RG source order/behavior, type/resources/vtable/compiler/no-duplicate evidence while preserving the entire executed B004 and unrelated family union.

### Destination 7 - `by-memory/0x005700e0-0x0057092c.SelfLookPane2OnActivate.md`
- Direct readback found Destination 7 already exact at `92/94` with accepted `ObjectStatusBlob m_objectStatus` prose/body and every behavior/detail preserved; B002 left it unchanged and read only.

### Destination 8 - UID0003F3
- Applied the UID-preserving rename from historical `SelfLookPane2LookPalStringFragments.md` to `by-memory/0x00624b74-0x00624b90.SelfLookPane2PaletteResourceString.md`; old path is absent.
- Applied `90/92` and exact UTF-16 `SELFLOOK.PAL` evidence while preserving owner/emitter/reconstructable/blank position/Nested 0 and blank direct C++.

### Destination 9 - `by-memory/0x00624ba8-0x00624bd0.SelfLookPane2StatButtonLabelStrings.md`
- Applied `90/92` and all exact label/use-site evidence while preserving owner/emitter/reconstructable/blank position/Nested 0 and blank direct C++.

### Destination 10 - `by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md`
- Retained `89/92`, `CANONICAL_OWNER:NONE`, emitters `0000NL,0000P0`, blank position/direct C++, and all history; added only the applied UID0003RB `L"STATBUT.EPF"` use-site synchronization without changing the independent UserLookPane route.

### Destination 11 - `by-memory/0x00624788-0x00624c64.LookGroupCollectionResourceStringData.md`
- Retained `88/92`, NONE/FALSE, blank emitter/position/formal and applied prose-only exact resource/label/use-site synchronization without changing other mixed inventory.

### Destination 12 - `by-memory/0x006246f4-0x00624780.SelfLookPane2VtableData.md`
- Applied `91/95` and exact primary `+0x44` UID0003RB/source/adjacency proof while preserving compiler comment-only disposition and all table boundaries/stores.

### Destination 13 - `by-type/by-vtable/SelfLookPaneFamilyVtables.md`
- Applied `91/95`, exact `+0x44` row/source cause, and preserved owner/emitter/blank position/comment-only formal plus all family detail.

### Destination 14 - verify-only support
- Re-read all named ObjectStatusBlob/EPFTileContext/rendering/image/status/global/resource/sibling/B004 packet support and executed B004 implementation. No contradiction or drift existed; every Destination 14 page remained unchanged/read only.

## Score And Metadata Recommendation
| UID | Evidence-time | Applied/current | Metadata disposition | Rationale |
| --- | ---: | ---: | --- | --- |
| 0003RB | 86/90 | 93/94 | preserved owner/emitter/TRUE/blank position/Nested 0 | Complete 3,141-byte body, all branches/types/resources/helpers closed and validated |
| 0003RF | 85/89 | 92/93 | preserved owner/emitter/TRUE/blank position/Nested 0 | Exact body/signature/callers/formula/no-code exclusions applied |
| 0003RG | 86/90 | 92/94 | preserved owner/emitter/TRUE/blank position/Nested 0 | Exact matrix/signature/callers/table disposition applied |
| 0000CV | 93/94 | 94/94 | preserved owner/emitter/TRUE/blank position | Executed B004 packet surface plus B002 enums/paint/helper declarations/type merged |
| 0001HK | 90/93 | 91/94 | retained owner, FALSE, blank emitter/position/C++ | Child inventory complete; parent remains non-emitting |
| 0000NL | 91/93 | 92/94 | retained FILE/path and no reconstruction metadata | Complete packet plus paint/helper/type/resource/source route applied |
| 0003QZ | 92/94 | 92/94 | metadata/formal block already exact | Exact `m_objectStatus` source integration and behavior preserved read only |
| 0003F3 | 85/88 | 90/92 | preserved owner/emitter/TRUE/blank position; UID-preserving rename applied | Exact complete string/hash/xref/use-site resolved |
| 0003F4 | 89/92 | 89/92 | unchanged NONE/two emitters/blank direct C++ | Existing pooled-literal disposition retained; B002 use synchronized |
| 0003F5 | 85/88 | 90/92 | preserved owner/emitter/TRUE/blank position | Exact two literals/hash/xrefs/use-site applied |
| 0002V2 | 88/92 | 88/92 | unchanged NONE/FALSE/blank | Prose-only mixed-inventory synchronization applied |
| 00038N | 90/94 | 91/95 | preserved owner/emitter/TRUE/blank position/comment block | Exact omitted vtable cell now documented |
| 00038M | 90/94 | 91/95 | preserved owner/emitter/TRUE/blank position/comment block | Exact class/source cause now documented |

- Target improvement is material: every blocker named by the current page has been resolved into exact source, type, support, or compiler disposition.
- Scores remain below perfect because original lexical spellings/access and physical source filename are not symbol-proven. No remaining uncertainty blocks emission.

## Open Questions With Attempted Resolution
| Question | Checks | Resolution and impact |
| --- | --- | --- |
| Is target live without direct callers? | xrefs, vtable bytes, sibling slots | Yes; primary `+0x44` virtual route. No liveness blocker. |
| Is OnPaint bool/int? | ABI, return paths, sibling paint contracts | No; source is void. EAX is incidental. |
| Is the 68-byte member a distinct historical sprite-config type/field? | layout, ObjectStatusBlob, B004 packet methods, current LivingObjectPane correction, image consumers | No defensible distinct type; use `ObjectStatusBlob m_objectStatus`. Former type/field pair is historical only. |
| Are `SE`/`L`/`LOOK.*` separate source strings? | exact bytes and xrefs | No; IDA split labels divide complete `SELFLOOK.EPF/PAL` literals. |
| Do labels remain unknown Korean resources? | raw UTF-16 decode and xrefs | Closed to exact escaped values; use-site literals. |
| Should stats enabled path render frame 9/4? | decompile/disassembly branch tail | No; observed source-equivalent lookup then return must remain. |
| Does RF return int? | ret16, caller use, loop terminal EAX | No; void source, ignored final NUL EAX. |
| Does RG return RectBounds/int? | output pointer, short input, call use, ret8 | No; void source with output pointer. |
| Does RG table need a child? | bytes and xref | No; compiler switch data from the member switch. |
| Are optional positions required? | sibling/current emitter ordering | No; preserve blank address/source ordering. |
| Can B002 apply its older complete class block independently of B004? | executed B004 SHA, shared destinations, settled generated readback | No. B004 completed packet closure first; B002 installed only the merged Destination 2 after direct verification. The completed order removed collision/pruning risk. |
| Is any third-party import involved? | source family/dependencies | No. Native NexusTK C++; `third_party_embeds` is not applicable. |
| Are any investigable blockers deferred? | all evidence routes above | No. Only lexical confidence caps remain. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- B002 inspected every affected current manual row read only. B002 must not apply these changes; manual coverage/tracker ownership remains supervisor-only.
- Executed B004's by-memory coverage contract for UID00039M's five real-UID children, UID0003RE, UID00039N, UID00023X, and compiler/padding rows remains additive and authoritative. The B002 rows below are supervisor-owned additions/replacements alongside that block and must not replace or delete any B004 row.
- In particular, preserve/add the following exact B004 source-method rows at their accepted hierarchy/address positions; these are supervisor-owned coverage instructions and not B002 edit authorization:

```text
        - [UID:0003RE][0x00572120-0x005725ed.SelfLookPane2PacketEventHelper](by-memory/0x00572120-0x005725ed.SelfLookPane2PacketEventHelper.md) 0x00572120-0x005725ed | virtual method | SelfLookPane2OnPacketEvent : reconstructable : 91% : very-strong : Exact EventHandler-facet packet virtual with vtable cell 0x00624758, event payload at +0x0c, opcodes 0x08/0x1d/0x33/0x37/0x38/0x39/0x3a, five source-helper dispatches, OnActivate and Spelled routes, bool returns, complete formal C++, and compiler-only inline lowering excluded.
            - [UID:0004Q0][0x00572b60-0x00572c1e.SelfLookPane2ApplySelfLookRectRecord](by-memory/0x00572b60-0x00572c1e.SelfLookPane2ApplySelfLookRectRecord.md) 0x00572b60-0x00572c1e | retained source method | SelfLookPane2ApplySelfLookRectRecord : reconstructable : 91% : very-strong : Exact object-id-gated full/partial ObjectStatusBlob temporary parse, 68-byte member copy, invalidation, false return, raw no-xref retained-copy evidence, and complete formal C++.
            - [UID:0004Q1][0x00572c20-0x00572ca0.SelfLookPane2ApplySelfLookRectStateRecord](by-memory/0x00572c20-0x00572ca0.SelfLookPane2ApplySelfLookRectStateRecord.md) 0x00572c20-0x00572ca0 | retained source method | SelfLookPane2ApplySelfLookRectStateRecord : reconstructable : 91% : very-strong : Exact object-id-gated direct full/partial ObjectStatusBlob member parse, invalidation, false return, raw no-xref retained-copy evidence, and complete formal C++.
            - [UID:0004Q2][0x00572ca0-0x00572da4.SelfLookPane2ApplyEquipmentSlotRecord](by-memory/0x00572ca0-0x00572da4.SelfLookPane2ApplyEquipmentSlotRecord.md) 0x00572ca0-0x00572da4 | retained source method | SelfLookPane2ApplyEquipmentSlotRecord : reconstructable : 92% : very-strong : Exact selectors 4/7/8/20/21, BE16 item ids, palette writes, unconditional invalidation/true return, raw no-xref inline-copy liveness, and complete formal C++.
            - [UID:0004Q3][0x00572dd0-0x00572e88.SelfLookPane2ClearEquipmentSlotRecord](by-memory/0x00572dd0-0x00572e88.SelfLookPane2ClearEquipmentSlotRecord.md) 0x00572dd0-0x00572e88 | retained source method | SelfLookPane2ClearEquipmentSlotRecord : reconstructable : 92% : very-strong : Exact id-only clears for selectors 4/7/8/20/21, palettes retained, unconditional invalidation/true return, inline-copy liveness, and complete formal C++.
            - [UID:0004Q4][0x00572ec0-0x00572f25.SelfLookPane2ApplySelfLookSummaryRecord](by-memory/0x00572ec0-0x00572f25.SelfLookPane2ApplySelfLookSummaryRecord.md) 0x00572ec0-0x00572f25 | retained source method | SelfLookPane2ApplySelfLookSummaryRecord : reconstructable : 91% : very-strong : Exact mask-0x40 optional BE32 display-value compare, no member stores, conditional invalidation, false return, inline-copy liveness, and complete formal C++.
        - [UID:00039N][0x00572f30-0x00572fcf.SelfLookPane2SpelledEntryDispatch](by-memory/0x00572f30-0x00572fcf.SelfLookPane2SpelledEntryDispatch.md) 0x00572f30-0x00572fcf | source method | SelfLookPane2DispatchSpelledText : reconstructable : 90% : very-strong : Exact ANSI StringBase and cursor decode, BE32 value, SpelledPane remove/add-or-update dispatch, true return, compiler cleanup exclusion, and complete formal C++.
```
- `by-memory/-coverage-report.md`: UID0003RB/RF/RG/F3/F4/F5 rows are absent; UID0001HK, UID0003QZ, and UID00038N rows are stale for the recommended merged source/type/slot state. Under the existing SelfLookPane2/resource/vtable grouping, add or replace with exactly:

```text
- [UID:0001HK][0x0056fe80-0x005729c3.SelfLookPane2](by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md) 0x0056fe80-0x005729c3 | non-emitting class-method split index | SelfLookPane2 : not_reconstructable : 91% : very-strong : Exact SelfLookPane2 constructor/destructor/activation/view/paint/key-text/input/packet/stat/button/raw-helper inventory with complete 0xd90 layout, ObjectStatusBlob m_objectStatus, source-ready UID0003RB OnPaint, UID0003RF DrawStatText, UID0003RG GetButtonRect, UID0003RE OnPacketEvent, UID00039N DispatchSpelledText, five exact UID00039M packet-update children, ShowDefault/Spelled/Legend and HandleKeyOrTextEvent children, retained raw ShowProfileView, all internal padding and compiler switch data, compiler exclusions, and exact child-only source emission through SelfLookPane2.
- [UID:0003QZ][0x005700e0-0x0057092c.SelfLookPane2OnActivate](by-memory/0x005700e0-0x0057092c.SelfLookPane2OnActivate.md) 0x005700e0-0x0057092c | virtual method | SelfLookPane2OnActivate : reconstructable : 92% : very-strong : Exact primary +0x48 OnActivate override with 0x84c/2124-byte hash/bounds, packet text/state/equipment/status/toggle parsing, exact 68-byte ObjectStatusBlob m_objectStatus member, SpelledPane parser call, LegendPane rich-text rows, child lifecycle, mode restore, compiler exclusions, complete 0xd90 field mapping, and formal C++.
- [UID:0003RB][0x00570fc0-0x00571c05.SelfLookPane2OnPaint](by-memory/0x00570fc0-0x00571c05.SelfLookPane2OnPaint.md) 0x00570fc0-0x00571c05 | primary +0x44 virtual paint method | SelfLookPane2OnPaint : reconstructable : 93% : very-strong : Exact 3141-byte/hash/918-instruction/68-block void OnPaint with SELFLOOK background/palette, human/monster/five-item rendering, navigation/toggle states, Korean labels, clipped percent stats, mode quirks, complete formal C++, and compiler-only cookie exclusions.
- [UID:0003RF][0x005726a0-0x00572771.SelfLookPane2DrawStatText](by-memory/0x005726a0-0x00572771.SelfLookPane2DrawStatText.md) 0x005726a0-0x00572771 | member helper | SelfLookPane2DrawStatText : reconstructable : 92% : very-strong : Exact 209-byte/hash void text-glyph helper with three paint callers, 9x11 cells, stride 9, 99-byte frame formula, space/slash skip with unconditional advance, slot-2 blit, complete formal C++, and compiler-cookie exclusion.
- [UID:0003RG][0x00572780-0x00572885.SelfLookPane2GetButtonRect](by-memory/0x00572780-0x00572885.SelfLookPane2GetButtonRect.md) 0x00572780-0x00572885 | member geometry helper | SelfLookPane2GetButtonRect : reconstructable : 92% : very-strong : Exact 261-byte/hash void short-id helper with thirteen callers, complete five-button/three-mode rectangle matrix, invalid -1 bounds, complete formal C++, and compiler-generated local switch-table disposition.
- [UID:0003F3][0x00624b74-0x00624b90.SelfLookPane2PaletteResourceString](by-memory/0x00624b74-0x00624b90.SelfLookPane2PaletteResourceString.md) 0x00624b74-0x00624b90 | source-local UTF-16 resource literal | SelfLookPane2PaletteResourceString : reconstructable : 90% : very-strong : Exact 28-byte/hash SELFLOOK.PAL literal with sole UID0003RB use, IDA fragment-label rejection, SelfLookPane emitter route, and use-site-only blank direct C++ disposition.
- [UID:0003F4][0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString](by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md) 0x00624b90-0x00624ba8 | pooled UTF-16 resource filename literal | SharedStatButtonEpfResourceString : reconstructable : 89% : very-strong : Exact STATBUT.EPF bytes and ten direct source-use refs split between SelfLookPane2 and UserLookPane; CANONICAL_OWNER NONE, emitters 0000NL and 0000P0, blank direct C++, and use-site emission in UID0003RB/UserLook source.
- [UID:0003F5][0x00624ba8-0x00624bd0.SelfLookPane2StatButtonLabelStrings](by-memory/0x00624ba8-0x00624bd0.SelfLookPane2StatButtonLabelStrings.md) 0x00624ba8-0x00624bd0 | source-local UTF-16 label literals | SelfLookPane2StatButtonLabelStrings : reconstructable : 90% : very-strong : Exact 40-byte/hash two-label run with escaped Korean values, two UID0003RB refs, exact member buffers/draw positions/colors, SelfLookPane emitter route, and use-site-only blank direct C++ disposition.
- [UID:00038N][0x006246f4-0x00624780.SelfLookPane2VtableData](by-memory/0x006246f4-0x00624780.SelfLookPane2VtableData.md) 0x006246f4-0x00624780 | vtable-data | SelfLookPane2VtableData : reconstructable : 91% : very-strong : Exact SelfLookPane2 RTTI/COL and three-view vtable interval with constructor/cleanup/scalar stores, primary +0x44 UID0003RB void OnPaint, primary +0x48 UID0003QZ OnActivate, secondary +0x08 UID0003RC HandleKeyOrTextEvent, exact boundaries, compiler-generated no-manual-array disposition, and UID00038M route.
```

- `by-class/-coverage-report.md`: UID0000CV is stale and UID00009S is independently stale relative to its current accepted ordinary page. Replace exactly:

```text
- [UID:0000CV][SelfLookPane2](by-class/SelfLookPane2.md) : reconstructable : 94% : very-strong : Complete PanelPane-derived 0xd90 SelfLookPane2 declaration with exact natural layout, ObjectStatusBlob m_objectStatus, primary +0x44 void OnPaint, primary +0x48 OnActivate, EventHandler packet/key contracts, source-ready view/paint/stat/button methods, five exact packet-update methods, DispatchSpelledText, equipment/display/toggle/text/view fields, complete child/raw-helper inventory, class closure before child definitions, and compiler/raw-liveness/lexical confidence caps.
- [UID:00009S][ObjectStatusBlob](by-class/ObjectStatusBlob.md) : reconstructable : 92% : very-strong : Complete naturally aligned 68-byte ObjectStatusBlob class with exact kind/equipment/color/riding/padding layout, tagged/full/partial parser children, broad map/object/look/image consumers, size check, compiler exclusions, and NexusTK/map/ObjectStatusBlob.cpp route.
```

- `by-file/-coverage-report.md`: UID0000NL is stale and direct type dependency UID0000M6 remains independently stale relative to its current accepted ordinary page. Replace exactly:

```text
- [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md) : reconstructable : 92% : very-strong : NexusTK/ui/panels/SelfLookPane.cpp source grouping with complete SelfLookPane/SelfLookPane2 split inventories, ObjectStatusBlob m_objectStatus, source-ready UID0003RB OnPaint, UID0003RF DrawStatText, UID0003RG GetButtonRect, UID0003RE OnPacketEvent, UID00039N DispatchSpelledText, five exact UID00039M packet-update method children, activation/view/key children, SELFLOOK/STATBUT resources and labels, retained raw-source/compiler-table/padding distinctions, helper/destructor/raw-profile ownership, shared child panes, and lexical/physical-filename confidence caps.
- [UID:0000M6][ObjectStatusBlob](by-file/ObjectStatusBlob.md) : reconstructable : 90% : very-strong : NexusTK/map/ObjectStatusBlob.cpp source root with complete 68-byte class, tagged/full/partial parser children, exact layout/normalization/resource/global/caller evidence, broad map/object/look/image consumers, non-emitting parent split, and historical alias rejection.
```

- `by-type/by-vtable/-coverage-report.md`: UID00038M is stale for the omitted paint cell. Replace exactly:

```text
- [UID:00038M][SelfLookPaneFamilyVtables](by-type/by-vtable/SelfLookPaneFamilyVtables.md) : reconstructable : 91% : very-strong : Source-local SelfLookPane/SelfLookPane2 vtable layout with exact ranges/stores, SelfLookPane2 primary +0x44 UID0003RB void OnPaint, primary +0x48 UID0003QZ OnActivate, secondary +0x08 UID0003RC HandleKeyOrTextEvent, sibling contracts, compiler-generated no-manual-array formal disposition, and UID0000NL route.
```

- No manual tracker row should be edited by B002. Any tracker/direct-report count, coverage replacement, addition, or deletion is supervisor-owned after accepted implementation/lifecycle verification.

## Follow-Up Actions
- B002 implementation, validators, waited generated verification, report reconciliation, and lease release are complete; no B002 implementation action remains.
- The exact manual coverage text remains supervisor-owned and was not applied by B002. Current/future report path, count, validation, Gate 2, coverage, execution, move, archive, and tracker state are external validator/supervisor-owned and are not asserted.
- No separate target report is needed for UID0003RF, UID0003RG, UID0003F3, or UID0003F5; they are included support scope here.

## Confidence
- Range/bytes/hash/vtable/CFG/callers/callees/branch behavior: very strong.
- Field offsets/types/resource bytes/geometry/status computations: very strong.
- Class/file ownership and source ordering: very strong.
- Human-shaped source operation and helper signatures: strong to very strong.
- Exact original identifier spellings, enum labels, access labels, and physical filename: high but not symbol-proven; these cap scores below perfect.
- No technical or B002 implementation blocker remains. Lexical uncertainty is fully represented by the accepted confidence caps.

## Validator Results
- Historical report-only phase: before Gate 1, no ordinary validator, generated refresh, or lease was run. Callback validators used `python .\tools\validator.py --mode file --file <ordinary-relative-path> --apply --queue-timeout 240`; the final target rerun added `--wait-generated`. Every command exited `0`, scanned one ordinary page, and returned `ok:1`.

| Command | Timestamp | Scoped destination | Result | Warnings / validator-managed side effects |
| --- | --- | --- | --- | --- |
| `000000012107` | `2026-07-14T19:20:56-04:00` | UID0003RB target | exit 0, ok 1 | Applied 93/94/body/hash/reference metadata; transient missing UID0003RF/RG registry warnings preceded their later path registrations; generated deferred. |
| `000000012112` | `2026-07-14T19:21:40-04:00` | UID0003RF | exit 0, ok 1 | Registered/mapped UID0003RF, inserted validator header spacing, updated score/references/projected stats; generated deferred. |
| `000000012113` | `2026-07-14T19:22:46-04:00` | UID0003RG | exit 0, ok 1 | Registered/mapped UID0003RG and references; pre-existing missing old UID0003R1/R2/R3 warnings only; generated deferred. |
| `000000012114` | `2026-07-14T19:24:29-04:00` | UID0000CV class | exit 0, ok 1 | Refreshed class hash/references/projected stats; pre-existing old-UID reference warnings only; generated deferred. |
| `000000012115` | `2026-07-14T19:26:01-04:00` | UID0001HK parent | exit 0, ok 1 | Applied 91/94 child/padding/table/type inventory and references; pre-existing old-UID warnings only; generated deferred. |
| `000000012116` | `2026-07-14T19:27:09-04:00` | UID0000NL file | exit 0, ok 1 | Added merged prose references/projected stats; pre-existing old-UID warnings only; generated deferred. |
| `000000012117` | `2026-07-14T19:28:17-04:00` | renamed UID0003F3 | exit 0, ok 1 | Preserved UID, applied new path/title/90/92 registry mapping and references; generated deferred. |
| `000000012118` | `2026-07-14T19:31:09-04:00` | UID0003F5 | exit 0, ok 1 | Applied 90/92 and exact label/use-site references; validator normalized link text/header spacing; generated deferred. |
| `000000012119` | `2026-07-14T19:31:48-04:00` | UID0003F4 | exit 0, ok 1 | Preserved metadata/blank body, added target/predecessor references and projected stats; generated deferred. |
| `000000012120` | `2026-07-14T19:32:26-04:00` | UID0002V2 | exit 0, ok 1 | Preserved 88/92 NONE/FALSE/blank state and updated resource-child references; 14 pre-existing unregistered sibling-child UID warnings; generated deferred. |
| `000000012121` | `2026-07-14T19:33:22-04:00` | UID00038N | exit 0, ok 1 | Applied 91/95 and UID0003RB vtable reference; generated deferred. |
| `000000012122` | `2026-07-14T19:34:15-04:00` | UID00038M | exit 0, ok 1 | Applied 91/95 and UID0003RB type reference; generated deferred. |
| `000000012123` | `2026-07-14T19:34:31-04:00` | UID0003RB `--wait-generated` | exit 0, ok 1, refresh completed | Rebuilt 4,908-node/3,961-edge registry and generated metadata/source. Project-wide warnings were 176 emitter-no-code, 86 missing preferred children markers, and 14 fallback insertions; none is a UID0003RB callback failure. |

- Managed-block sync readback passed byte-for-byte for all five source-bearing report/destination pairs: UID0003RB, UID0000CV, UID0003RF, UID0003RG, and UID0003QZ. UID0003QZ was already exact and remained read only. Blank parent/resource blocks and both vtable comment-only blocks remain exact.
- Final validator-generated `auto-generated/NexusTK/ui/panels/SelfLookPane.cpp`: 62,304 bytes, 1,796 lines, SHA256 `726E139FEB80B086F6765B71D4A4ED63B832A9B7B9A2B3D233F6A3ACF6FEFBC1`, refreshed by command `000000012123`.
- Generated order/uniqueness: one `class SelfLookPane2` at line 588; one definition each for `OnActivate` 708, `ShowDefaultView` 880, `ShowSpelledView` 897, `ShowProfileView` 941, `ShowLegendView` 966, `OnPaint` 992, `HandleKeyOrTextEvent` 1397, `OnPacketEvent` 1441, `DrawStatText` 1475, `GetButtonRect` 1511, UID0004Q0 1583, UID0004Q1 1606, UID0004Q2 1624, UID0004Q3 1675, UID0004Q4 1717, and `DispatchSpelledText` 1738. The class has one constructor declaration, one destructor declaration, all six B004 packet declarations once, both B002 enums once, and one `ObjectStatusBlob m_objectStatus`.
- Generated negative/contract proof: zero `LivingSpriteConfig` or `m_lookStatus`; zero UID0003RB/RF/RG/39M Empty Emitter Markers; no duplicate source definition; no handwritten cookie, switch/selector table, vtable, RTTI, adjustor, or scalar-deleting ABI body. Exact use-site counts are one `SELFLOOK.EPF`, one `SELFLOOK.PAL`, seven `STATBUT.EPF`, six `BUTTON.PAL`, three `%u`, and one of each escaped label. UID0003F3/F4/F5 use-site-only empty markers remain intentional and are not source-bearing duplicate bodies.
- Final lease readback from both central and Agent-B002 `current_leases.md`: no active leases. No validator, report-lifecycle probe, `execute_report`, move, or archive command was run beyond the authorized ordinary validators and waited generated refresh.

## Changed Files
- Same callback report, modified additively: `tools/leaser/Agents/Agent-B002/research/0003RB-SelfLookPane2OnPaint-source-quality.md`.

| Changed ordinary destination | Final SHA256 | Scoped validator | Lease |
| --- | --- | --- | --- |
| `by-memory/0x00570fc0-0x00571c05.SelfLookPane2OnPaint.md` | `541F1536AF781F05A13BAE7AE1934CA106A98220235F3F01BF974712E8BD830B` | `000000012107` plus waited `000000012123` | acquired/released successfully |
| `by-class/SelfLookPane2.md` | `96166F44C2B20805F59D6403C2509027C6945D693FAF014D333D78E7C808913D` | `000000012114` | acquired/released successfully |
| `by-memory/0x005726a0-0x00572771.SelfLookPane2DrawStatText.md` | `46CD70E79B79061025D4821EB1327E8042B11AD8F98C7483239E7A9337C3A390` | `000000012112` | acquired/released successfully |
| `by-memory/0x00572780-0x00572885.SelfLookPane2GetButtonRect.md` | `CAEC789C0A43CE8120C468E4D544246866259FCE036A596DEF31F5E7190D8151` | `000000012113` | acquired/released successfully |
| `by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md` | `D735D859EB2B5A862ABB42A29FC242877CDC58A3B22F73AA78E3327BD009209F` | `000000012115` | acquired/released successfully |
| `by-file/SelfLookPane.md` | `D3104E0AA4B537F6F5D1B7367A0D737866EF49B6C83DB225DF20E817BD6DCBB9` | `000000012116` | acquired/released successfully |
| `by-memory/0x00624b74-0x00624b90.SelfLookPane2PaletteResourceString.md` | `C6B09DB030615C1A4CB2E9A8F3BE8EE08E844F190709FAF7641F3D73FA033E3C` | `000000012117` | old path leased; released after renamed-path validation |
| `by-memory/0x00624ba8-0x00624bd0.SelfLookPane2StatButtonLabelStrings.md` | `FBD5E3E74080C1F7D2FA4F813260CD736ED196268D13485155125B7BA3623D2A` | `000000012118` | acquired/released successfully |
| `by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md` | `3299C358688B362E85BF8D5139199272EBF2808FCDE4AD75073BA213720A0A82` | `000000012119` | acquired/released successfully |
| `by-memory/0x00624788-0x00624c64.LookGroupCollectionResourceStringData.md` | `A913D1B43FDB57FF5169974101FDCD34A2C6A1AEB18F21DAD73973FE92E64BF9` | `000000012120` | acquired/released successfully |
| `by-memory/0x006246f4-0x00624780.SelfLookPane2VtableData.md` | `91F1E511579CC55A8C379519A19B175225A32FA856886C5AEB793AD60FE37456` | `000000012121` | acquired/released successfully |
| `by-type/by-vtable/SelfLookPaneFamilyVtables.md` | `F74C950801BE9DBDACD9BA0778FE1329F7C917B0EAE8470F1B1E0DCC0D2F5DAA` | `000000012122` | acquired/released successfully |

- Read-only Destination 7: `by-memory/0x005700e0-0x0057092c.SelfLookPane2OnActivate.md`, SHA256 `9871E2113684187229DEFCA8D7B629787742CAE9867D8324121E3748B6EE44E3`; its accepted formal block already matched byte-for-byte.
- Read-only executed overlap and packet destinations: `executed-b-agent-research/B004/00039M-SelfLookPane2LookUpdateRawHelpers-source-quality.md` SHA256 `0D4E676FAC6E6AF9DC1BC51AF766E0F772F6BAECD8E729D5881C738122C6EB2A`; UID00039M, UID0003RE, UID00039N, and UID0004Q0-Q4 ordinary pages were not edited.
- Read-only Destination 14 support included ObjectStatusBlob/EPFTileContext/GrafPort/Region/RectBounds, PaletteLib/EPFLib, NewHumanImageLib/MonsterImageLib/ItemObjImageLib/UserStatusPane, Surface callback/global, `BUTTON.PAL`, and neighboring SelfLookPane2 pages. No concrete contradiction was found, so none was leased, edited, or validated by B002.
- The authorized validator refreshed generated/registry/projected-stat artifacts as command side effects. B002 did not manually edit any manual coverage, generated, tracker, audit, supervisor, validator-state, lifecycle, IDA, goal, shared note, or other-agent artifact.

## Implementation Tracking Checklist

Initial report-only and Gate 1 prerequisites:
- [x] Supervisor confirmed exact report SHA `462625CBCDD5937FAB7A3E6707335B9812075BD0BB3C62E6FBAECD6A45E59095` passed Gate 1 before any ordinary edit.
- [x] Confirm every C01-C30 Action uses the accepted enum vocabulary and every report-only Verification state was `proposed`; terminal states are now only `applied`, `already-present`, or `excluded-with-reason`.
- [x] Re-read executed B004 artifact SHA `0D4E676FAC6E6AF9DC1BC51AF766E0F772F6BAECD8E729D5881C738122C6EB2A`; confirm its five UID00039M child methods, UID0003RE, UID00039N, six declarations, `ObjectStatusBlob m_objectStatus`, and shared UID0000CV/QZ/NL closure before B002 shared-page edits.
- [x] Re-read every Destination 1-14 page immediately before callback work and preserve same-or-greater unrelated detail/history.
- [x] Confirm UID0003RB exact range/hash/vtable/call/CFG evidence and preserve owner/emitter/TRUE/blank position/Nested 0.
- [x] Confirm B004 completed/released shared UID0000CV/UID0003QZ/UID0000NL and no active conflicting lease owned each immediate destination before edit.

Implementation callback destinations:
- [x] Destination 1: target `93/94`, exact block/evidence/history applied; validator `000000012107`; lease released.
- [x] Destination 2: merged UID0000CV `94/94` complete class preserves executed B004 union and adds B002 enums/signatures; validator `000000012114`; lease released.
- [x] Destination 3: UID0003RF `92/93` exact block/evidence applied; validator `000000012112`; lease released.
- [x] Destination 4: UID0003RG `92/94` exact block/matrix/table evidence applied; validator `000000012113`; lease released.
- [x] Destination 5: UID0001HK `91/94` semantic index/non-emission and complete child/padding/table/type inventory applied; validator `000000012115`; lease released.
- [x] Destination 6: UID0000NL `92/94` prose-only merged source/type/resource/order/compiler integration applied with no reconstruction metadata; validator `000000012116`; lease released.
- [x] Destination 7: UID0003QZ direct readback already matched accepted `ObjectStatusBlob`/`m_objectStatus` block and metadata; left unchanged/read only.
- [x] Destination 8: UID0003F3 UID-preserving rename, `90/92`, literal evidence/blank body/history applied; validator `000000012117`; old path absent; lease released.
- [x] Destination 9: UID0003F5 `90/92` exact labels/use sites with blank direct C++ applied; validator `000000012118`; lease released.
- [x] Destination 10: UID0003F4 metadata/blank body retained and bounded UID0003RB use-site synchronization applied; validator `000000012119`; lease released.
- [x] Destination 11: UID0002V2 `88/92` NONE/FALSE/blank retained and exact resource-child synchronization applied; validator `000000012120`; lease released.
- [x] Destination 12: UID00038N `91/95`, comment-only block retained, exact `+0x44` slot/source proof applied; validator `000000012121`; lease released.
- [x] Destination 13: UID00038M `91/95`, comment-only block retained, exact `+0x44` type/source cause applied; validator `000000012122`; lease released.
- [x] Destination 14: all named support, neighboring, B004 child, UID0003RE/UID00039N, and executed report pages re-read; no contradiction found; all remained read only.

No-loss and verification obligations:
- [x] Preserve every accepted target/helper range, byte/hash, instruction/CFG, padding/table, vtable, xref/caller/callee, field/type, resource, geometry, branch, no-check, no-cleanup, source-order, compiler-exclusion, historical, negative, and rejected-alternative fact.
- [x] Preserve exact mode-0 enabled-stats frame lookup with no render call.
- [x] Preserve exact unsupported-mode initialized-context blit and return behavior.
- [x] Preserve all five independent item layers and exact centers/palette fields.
- [x] Preserve UID0001HK non-emission and prevent duplicate parent source.
- [x] Preserve UID0003F4 no-owner/two-emitter/use-site-only state and do not invent a standalone global.
- [x] Preserve all five B004 UID00039M child methods, UID0003RE `OnPacketEvent`, UID00039N `DispatchSpelledText`, exact packet behavior/source order, padding/table/history, and no duplicate/pruning.
- [x] Preserve compiler ownership of security cookies, RG switch table, vtable/RTTI, adjustors, and scalar deleting wrappers.
- [x] Confirm by-file pages gained no reconstruction metadata or managed block.
- [x] Confirm every changed ordinary file had exactly one scoped validator under its short lease and every lease was released immediately; final target wait was the authorized generated refresh.
- [x] Run final authorized UID0003RB `--wait-generated` refresh as command `000000012123` after ordinary validators.
- [x] Verify one complete SelfLookPane2 class, one constructor/destructor declaration, one definition for every accepted B002/B004 source-bearing method, and every retained source-bearing view/input method in exact generated order.
- [x] Verify one `ObjectStatusBlob m_objectStatus`, all six B004 packet-update declarations, both B002 enums, zero recommended stale tokens, zero UID0003RB/RF/RG/39M Empty Emitter Markers, no duplicates, and no handwritten ABI/compiler bodies.
- [x] Record command IDs, timestamps, exits, ok counts, warnings, side effects, generated path/hash/count/order proof, destination hashes, and zero-lease confirmation in this report.
- [x] Update every C01-C30 row to a legal final callback Verification state with detailed destination proof outside the state cell.
- [x] Check every callback checklist item after direct proof while keeping supervisor manual coverage/tracker/lifecycle actions external.
- [x] Preserve exact supervisor-owned coverage text in this report and do not edit any manual `-coverage-report.md` file.
- [x] Do not manually edit generated/tracker/audit/supervisor/validator-state/lifecycle files.
- [x] Do not run/probe `execute_report`, report count/validate/lifecycle, move, or archive commands.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000012153","destination_path":"executed-b-agent-research/B002/0003RB-SelfLookPane2OnPaint-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0003RB-SelfLookPane2OnPaint-source-quality.md","timestamp":"2026-07-14T20:09:27-04:00","uid":"0003RB"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
