** TARGET-REPORT-UID:00041Y **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 00041Y MapPane ScreenToMapCoords Source-Quality Research


## Finalized Report / Current Recommendation
- Current implemented disposition: keep [UID:00041Y][0x00505170-0x005051bb.MapPaneScreenToMapCoords](../../../by-memory/0x00505170-0x005051bb.MapPaneScreenToMapCoords.md) as a `MapPane` instance method owned and emitted by [UID:00007Q][MapPane](../../../by-class/MapPane.md), routed through [UID:0000L3][MapPane](../../../by-file/MapPane.md).
- Implementation callback result: target metadata is now `COMPLETION:88`, `CONFIDENCE:92`; `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, and blank `EMITTER_POSITION_OPTIONAL` were preserved; the existing formal C++ body was preserved exactly.
- Support disposition: MapPane class/file/aggregate/global support docs were inspected and were already present at same-or-greater ownership/source-route detail, so no support by-* edits were required.
- Confidence: high. MCP session `60724697` confirms the exact function, one caller, no callees, exact arithmetic, clean padding, and generated output presence. The main caveat is a separate duplicate-UID documentation defect in the FittingRoom user-image pages that uses the same `UID00041Y` for a different by-memory path; that collision is excluded/deferred by supervisor instruction and does not change the MapPane behavior.

## Supporting Research
- Original assignment: Agent-B007 report-only research for UID00041Y at `by-memory/0x00505170-0x005051bb.MapPaneScreenToMapCoords.md`.
- Implementation callback history: after supervisor Gate 1 acceptance, B007 edited only the target by-memory page and this report, then ran one scoped target validator. No support by-* pages required edits. No generated files, coverage reports, validator state, lifecycle/archive files, supervisor ledgers, or FittingRoom duplicate-UID pages were manually edited. No `execute_report`, lifecycle, archive, registry, dry-run/probing execute, or MCP process-management command was run.
- MCP provenance: supervisor restored IDA MCP and directed B007 to use live session `60724697`. B007 used read-only `idb_list`, `server_health`, `lookup_funcs`, `decompile`, `disasm`, `xrefs_to`, `xref_query`, `get_bytes`, `get_int`, `get_global_value`, `insn_query`, `callees`, and `analyze_function` calls only.
- Current live session facts: `idb_list` returned one active `NexusTK.exe.i64` session `60724697`; `server_health` returned `status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, `imagebase:"0x400000"`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.
- Prior MCP pause history is not final evidence for this report. The earlier zero-session state was superseded by the supervisor-restored session above.

## Target
- Target UID: `00041Y`.
- Target path: `by-memory/0x00505170-0x005051bb.MapPaneScreenToMapCoords.md`.
- Historical source queue/report row before this callback: `auto-generated/-ag-research-tracker.md` line 1574 listed this target at `86/88`, average `87.0`, reconstructable `true`, report count `0`.
- Supervisor classification history: Medium B-agent source-quality target from the reconstructable not-covered queue; the accepted callback has now applied the target/source-quality update.
- Current scores and parent state after implementation: target page is `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank emitter position, and a populated formal C++ block.

## Current Target State
- Current metadata: `88/92`, direct owner/emitter [UID:00007Q][MapPane](../../../by-class/MapPane.md), reconstructable true, blank `EMITTER_POSITION_OPTIONAL`.
- Current C++/emitter state: formal block emits `void MapPane::ScreenToMapCoords(MapPoint *point) const`, and generated `auto-generated/NexusTK/map/MapPane.cpp` line 336 contains the UID00041Y body with `Completion:88 | Confidence:92`. It is not an Empty Emitter Marker.
- Current target prose: includes the accepted MCP session `60724697` evidence, exact current bytes, caller context, callee absence, generated header state, rejected alternatives, and duplicate-UID caveat found during this pass.
- Related docs checked: `by-class/MapPane.md`, `by-file/MapPane.md`, `by-global/MapTilePixelDimensions.md`, `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`, sibling coordinate pages UID00041X/UID00041Z, `by-memory/-ignored.md`, generated `MapPane.cpp`, generated tracker/coverage rows, and the executed B009 UID0001AP report.
- Duplicate UID state: `by-memory/0x00424550-0x0042456a.FittingRoomUserImageControlPaneAdvanceFacingDirection.md` also currently has `*** UID:00041Y ***`, and FittingRoom support docs still point that UID at the MapPane path while describing the FittingRoom method. This is not a MapPane ownership contradiction, but it is an implementation/lifecycle risk that requires supervisor/validator UID guidance if addressed.

## Executive Recommendation
- Best direct owner: [UID:00007Q][MapPane](../../../by-class/MapPane.md), because the function uses the `MapPane` receiver fields at `+0x3fc/+0x400`, belongs to the coordinate conversion helper family, and is called from MapPane input handling.
- Source file route: [UID:00007Q] emits through [UID:0000L3][MapPane](../../../by-file/MapPane.md) to `NexusTK/map/MapPane.cpp`.
- Implemented metadata: target documentation is now `COMPLETION:88`, `CONFIDENCE:92`; owner/emitter/reconstructable fields were not changed.
- Code recommendation: keep the existing formal C++ block unchanged. The body is already the most plausible source representation: an in-place `MapPoint` conversion using `g_mapTilePixelWidth`, `g_mapTilePixelHeight`, `m_tileOriginX`, and `m_tileOriginY`.
- Condition before broader UID cleanup: the duplicate FittingRoom UID must not be fixed by ad hoc B007 edits during this callback because the supervisor marked that collision out of scope. It needs supervisor/validator-mediated UID/path disposition because two by-memory files currently claim the same UID.

## Supervisor Active Recheck
- Triggering instruction: supervisor restored MCP session `60724697` and directed B007 to resume UID00041Y with narrow, paged, schema-current MCP calls and no fallback-only evidence.
- Split repair needed: no. The target is a single modeled function `0x00505170-0x005051bb` with clean padding before and after.
- Source-bearing child handling: UID00041Y itself is the source-bearing child. Parent aggregate [UID:0001AP] is already an emitting aggregate marker over exact child pages, not a monolithic function body.

## Inference Research Guidance Check
- IDA facts were separated from documentation evidence and inference. Direct IDA facts include function range/size, disassembly/decompilation, bytes, caller xref, callee absence, and global values from MCP session `60724697`.
- Documentation evidence includes B009 accepted 0001AP report, MapPane class/file support pages, MapTilePixelDimensions, sibling coordinate pages, generated MapPane output, and tracker/coverage rows.
- Inference is limited to source-facing names and layout roles already accepted by support docs: `MapPoint`, `row`, `column`, `g_mapTilePixelWidth`, `g_mapTilePixelHeight`, `m_tileOriginX`, and `m_tileOriginY`.
- Wave2/Wave3 stale output was treated as a lead only. No Wave2/Wave3 source claim is needed to accept the current body because current MCP and current by-* docs are sufficient.

## Heuristic / Inference Reanalysis And Validation
- Function shape: `sub_505170` is a 75-byte, one-basic-block `__thiscall` helper. The decompiler's `_DWORD *this, int *a2` shape is raw ABI output; source shape is a `MapPane` method taking an in-place `MapPoint *`.
- Field names: `this[255]` and `this[256]` are offsets `+0x3fc` and `+0x400`. `by-class/MapPane.md` records these as high-confidence `m_tileOriginX` and `m_tileOriginY`, with UID00041X subtracting them and UID00041Y adding them.
- Pair order: the binary loads `*a2` first, divides by `word_66DAA0`, stores that result back to `*a2` after adding Y origin, and independently divides `a2[1]` by `word_66DA9C` before adding X origin. The accepted row/column convention keeps element 0 as row/Y-like and element 1 as column/X-like.
- Global names: `word_66DA9C` and `word_66DAA0` are already documented by [UID:0000T7][MapTilePixelDimensions](../../../by-global/MapTilePixelDimensions.md) as `g_mapTilePixelWidth` and `g_mapTilePixelHeight`, both signed-short globals initialized to `48`.
- Caller/reachability: current xrefs show one direct caller at `0x00507a43` inside `sub_507150`. The caller copies event coordinates to `this+0x84c/+0x850`, pushes that address, sets `ecx` to the MapPane subobject with `lea ecx, [edi-0A0h]`, and calls `sub_505170`.
- Rejected alternatives: do not rename this to raw `sub_505170`; do not leave it no-owner/non-emitting; do not merge it into UID0001AP aggregate C++; do not route it to MapTilePixelDimensions just because it consumes globals; do not route it to the input-handler caller as a standalone command helper; and do not let the unrelated FittingRoom duplicate UID alter the MapPane source body.

## Evidence Standards Used
- Direct MCP evidence: `idb_list`, `server_health`, exact `lookup_funcs`, bounded `decompile`, bounded `disasm`, `analyze_function`, `callees`, `xrefs_to`, `xref_query`, scoped `insn_query`, `get_bytes`, `get_int`, and `get_global_value`.
- Documentation evidence: current target/support by-* docs, generated MapPane output, generated tracker/coverage rows, and the accepted executed B009 report.
- Negative evidence: no callees, no split/padding ambiguity, no generated empty marker, no support contradiction in MapPane class/file/global docs, and no owner evidence for MapTilePixelDimensions/caller/FittingRoom/no-owner alternatives.
- Confidence cap: below 95 because final project-wide `MapPoint` header declaration and exact original spelling of row/column fields are inferred from accepted docs rather than original symbols. The behavior and source route support the implemented `88/92` state.

## Evidence Checked
- IDA MCP checks performed on session `60724697`: `idb_list`, `server_health`, `lookup_funcs` for `0x00505170`, `0x005051bb`, `0x005051bc`, `0x00507150`, adjacent functions, and globals; `decompile` and `disasm` for `0x00505170`; `analyze_function` for `0x00505170`; `callees` for `0x00505170`; `xrefs_to` and `xref_query` for `0x00505170`; `get_bytes` for `0x00505160`, `0x00505170`, and `0x005051bb`; `get_int`/`get_global_value` for `0x0066da9c` and `0x0066daa0`; `insn_query` and bounded caller `disasm`/`decompile` for `0x00507150`.
- by-* docs checked: target page, MapPane class/file pages, MapTilePixelDimensions, parent aggregate UID0001AP, sibling UID00041X/UID00041Z pages, and by-memory ignored padding ledger.
- Generated/tracker docs checked: `auto-generated/NexusTK/map/MapPane.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, and `auto-generated/-ag-coverage-report-by-memory.md`.
- Old reports searched/opened: `rg` terms included `00041Y`, `0x00505170`, `MapPaneScreenToMapCoords`, `ScreenToMapCoords`, `MapToScreenCoords`, `MapTilePixelDimensions`, and `0001AP`; opened executed B009 `0001AP-MapPaneWeatherCoordinateObjectCore-source-quality.md`.
- Failed or skipped checks during the MCP evidence pass: `make_signature_for_range` with an `algorithms` parameter was rejected by schema; no signature is needed because exact bytes and function analysis already prove the range. No broad callgraph, unbounded search, or IDB management commands were used. The implementation validator is recorded separately under `Validator Results`.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-00041Y-01 | UID00041Y MapPane target should be `88/92` while keeping owner `00007Q`, reconstructable true, emitter `00007Q`, and blank emitter position. | High | Pre-callback target was `86/88`; MCP `60724697` proves exact function/body/caller; validator command `000000006214` applied target `88/92`, and command `000000006219` revalidated the final target text. | Target metadata and score rationale in `by-memory/0x00505170-0x005051bb.MapPaneScreenToMapCoords.md`. | incorporate | applied |
| C-00041Y-02 | Existing formal C++ body is correct and should be preserved unchanged. | High | Decompile/disasm match the accepted row/column block; generated `MapPane.cpp` lines 336-343 contain the same body after refresh command `000000006219`. | Target `RECONSTRUCTION_CPP CODE` block. | already-present | already-present |
| C-00041Y-03 | Function range is exact `0x00505170-0x005051bb`, size `0x4b` / 75 bytes, one basic block, no split. | High | `lookup_funcs`, `analyze_function`, disasm, exact bytes, and predecessor/successor padding from MCP `60724697`. | Target `## Evidence`. | incorporate | applied |
| C-00041Y-04 | Target has one direct code caller at `0x00507a43` inside `sub_507150`; caller passes an in-place point and MapPane receiver. | High | `xrefs_to`, `xref_query`, `insn_query`, bounded caller disasm/decompile. | Target `## Evidence`. | incorporate | applied |
| C-00041Y-05 | Target has no callees; global dimension reads are data dependencies, not helper calls. | High | MCP `callees` returned `[]`; disasm contains no call instructions and direct refs to `word_66DAA0/word_66DA9C`. | Target `## Evidence`. | incorporate | applied |
| C-00041Y-06 | `word_66DA9C` and `word_66DAA0` are `g_mapTilePixelWidth` and `g_mapTilePixelHeight`, both currently 48. | High | `get_int` and `get_global_value` returned `48` / `0x30`; [UID:0000T7] records the source names and emitted declarations. | Target dependency evidence; `by-global/MapTilePixelDimensions.md` support. | already-present | applied in target; support already-present |
| C-00041Y-07 | MapPane class/file support already carries `m_tileOriginX/m_tileOriginY` and coordinate-family placement; no required support edit for ownership. | High | `by-class/MapPane.md` field glossary and helper split; `by-file/MapPane.md` coordinate conversion table; parent aggregate row. | `by-class/MapPane.md`, `by-file/MapPane.md`, `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`. | already-present | already-present |
| C-00041Y-08 | Generated output contains UID00041Y body, not an empty marker, and refreshed to the implemented score. | High | `auto-generated/NexusTK/map/MapPane.cpp` header command `000000006219`, refreshed `2026-07-04T11:45:49-04:00`, lines 336-343 show `Completion:88 | Confidence:92`. | Target/generated-output evidence and validator results. | incorporate | applied |
| C-00041Y-09 | Reject MapTilePixelDimensions, input-handler caller, UID0001AP aggregate, raw `sub_505170`, no-owner/non-emitting, and FittingRoom ownership alternatives for this MapPane target. | High | Receiver fields, class/file support docs, direct caller context, generated output route, and unrelated duplicate UID evidence. | Target `## Evidence`; report negative evidence and final recommendation. | incorporate | applied |
| C-00041Y-10 | Duplicate `UID00041Y` in FittingRoom user-image by-memory/support docs is a separate documentation/validator risk, not evidence against the MapPane target body. | High | `by-memory/0x00424550-0x0042456a...` header also says `UID:00041Y`; FittingRoom support rows describe `AdvanceFacingDirection` while linking to MapPane path; supervisor callback said duplicate UID/FittingRoom collision is out of scope. | Report blocker/follow-up; no FittingRoom edits in this callback. | historicalize | excluded-with-reason: supervisor marked duplicate UID/FittingRoom collision out of scope |

## Positive Evidence Summary
- Direct facts supporting recommendation: MCP session `60724697` identifies `sub_505170` at `0x00505170`, size `0x4b`, with one basic block, no callees, one direct caller, and exact arithmetic matching the current formal C++ block.
- Corroborating docs: B009 accepted 0001AP split created UID00041Y as `MapPane::ScreenToMapCoords`; MapPane class/file pages carry the source route and field names; MapTilePixelDimensions carries the global names and values; generated `MapPane.cpp` emits the target body.
- Strongest inference chain: receiver field offsets `+0x3fc/+0x400` plus global tile dimensions plus the paired inverse UID00041X conversion prove this is the ordinary `MapPane::ScreenToMapCoords(MapPoint *) const` source method.

## IDA MCP Facts
- Function/range facts: `lookup_funcs(0x00505170)` returned `sub_505170`, size `0x4b`; `lookup_funcs(0x005051bb)` and `0x005051bc` returned not-a-function; `analyze_function(0x00505170)` returned prototype `int __thiscall(_DWORD *this, int *)`, size `75`, one basic block, cyclomatic complexity `1`.
- Byte facts: bytes at `0x00505170` are `55 8b ec 51 53 8b 5d 08 56 0f bf 35 a0 da 66 00 57 8b 03 99 f7 fe 0f bf 35 9c da 66 00 8b f8 89 4d fc 8b 43 04 99 f7 fe 8b 89 fc 03 00 00 49 03 c8 89 4b 04 8b 4d fc 8b 81 00 04 00 00 48 03 c7 5f 5e 89 03 5b 8b e5 5d c2 04 00`.
- Padding facts: preceding read at `0x00505160` ends with `... c2 04 00 cc cc cc cc cc cc`, proving `0x0050516a-0x00505170` padding; successor read at `0x005051bb` is `cc cc cc cc cc 55 8b ec`, proving `0x005051bb-0x005051c0` padding before successor `sub_5051C0`.
- Xref facts: `xrefs_to(0x00505170)` returned one code xref at `0x00507a43` inside `sub_507150`; `insn_query` scoped to `sub_507150` found exactly `call sub_505170`.
- Caller facts: bounded caller disasm around `0x00507a2b-0x00507a43` copies `[esi+8]` and `[esi+0Ch]` into `[edi+84Ch]` and `[edi+850h]`, pushes that address, sets `ecx` to `[edi-0A0h]`, then calls `sub_505170`.
- Global/type facts: `get_int` returned `48` for both `0x0066da9c` and `0x0066daa0` as `i16le` and `u16le`; `get_global_value` returned `0x30` for both.
- Negative IDA facts: `callees(0x00505170)` returned an empty list; the function contains no calls and no internal control-flow split.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00505130-0x0050516a` | [UID:00041X][MapPaneMapToScreenCoords](../../../by-memory/0x00505130-0x0050516a.MapPaneMapToScreenCoords.md) | inverse/sibling map-to-screen conversion | TRUE | [UID:00007Q] | `86/88` | already emitted |
| `0x0050516a-0x00505170` | by-memory ignored padding | alignment before UID00041Y | FALSE | [UID:0001AP] context | n/a | already ignored |
| `0x00505170-0x005051bb` | [UID:00041Y][MapPaneScreenToMapCoords](../../../by-memory/0x00505170-0x005051bb.MapPaneScreenToMapCoords.md) | assigned screen-to-map conversion | TRUE | [UID:00007Q] | `88/92` implemented | source-ready emitting |
| `0x005051bb-0x005051c0` | by-memory ignored padding | alignment after UID00041Y | FALSE | [UID:0001AP] context | n/a | already ignored |
| `0x005051c0-0x00505228` | [UID:0001AR][DrawVisibleTilesHelper](../../../by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md) | successor visible-tile redraw helper | TRUE | [UID:00007Q] | `88/90` | emitted sibling |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00507a43` | code xref/call from `sub_507150` | MapPane input/interaction path converts stored screen coordinates to map coordinates when config/state gates allow it. |
| `0x0066daa0` | data ref from target | `g_mapTilePixelHeight`, read as signed word before row/Y division. |
| `0x0066da9c` | data ref from target | `g_mapTilePixelWidth`, read as signed word before column/X division. |
| none | no callees | Arithmetic-only conversion; dependencies are data globals and MapPane fields. |

## Documentation Evidence And IDA Status
- Existing docs supporting conclusion: target page already identifies `MapPane::ScreenToMapCoords`; `by-class/MapPane.md` records `m_tileOriginX/m_tileOriginY` and the coordinate family; `by-file/MapPane.md` routes coordinate conversion children through `NexusTK/map/MapPane.cpp`; `MapTilePixelDimensions.md` emits the tile size globals; UID0001AP aggregate lists UID00041Y as the inverse conversion.
- Target doc implementation state: target now includes current `60724697` MCP details and score `88/92`. FittingRoom user-image docs have a duplicate `UID00041Y` conflict; this remains tracked separately from MapPane source evidence and was excluded from this callback by supervisor instruction.
- Generated/coverage state: `auto-generated/-ag-memory-coverage.md` listed UID00041Y as `coded`, owner/emitter `00007Q`, output `auto-generated/NexusTK/map/MapPane.cpp`; `auto-generated/-ag-coverage-report-by-memory.md` listed `emits_code:true`; generated `MapPane.cpp` contains the body at current header command `000000006219`.

## Ranked Ownership Analysis

### 1. [UID:00007Q] MapPane
- Evidence for: receiver fields at `+0x3fc/+0x400`, class field glossary, coordinate helper family, source route through MapPane file, generated output body, and direct caller using a MapPane subobject receiver.
- Evidence against: final original `MapPoint` declaration spelling is inferred rather than symbol-proven.
- Decision: accepted direct owner and emitter. Keep unchanged.

### 2. [UID:0000L3] MapPane file root
- Evidence for: generated source route and broader source module ownership of coordinate helpers and globals.
- Evidence against: the target reads instance fields and is best modeled as a class method, so file root is route rather than direct owner.
- Decision: keep as eventual source file through [UID:00007Q], not direct target owner.

### 3. [UID:0000T7] MapTilePixelDimensions
- Evidence for: the function reads `g_mapTilePixelWidth` and `g_mapTilePixelHeight`.
- Evidence against: globals are dependencies; they do not own the receiver fields or method.
- Decision: rejected as owner; keep as dependency/support.

### 4. Input/caller `sub_507150`
- Evidence for: one direct call at `0x00507a43`.
- Evidence against: caller prepares a `MapPane` receiver and in-place point; the conversion is reusable coordinate behavior, not caller-owned command logic.
- Decision: rejected as owner; caller is reachability evidence only.

### 5. FittingRoom duplicate UID pages
- Evidence for: a separate by-memory file currently also claims `UID00041Y`.
- Evidence against: address, owner, behavior, generated file, and support route are completely different; this is a UID/documentation collision, not a MapPane source ownership signal.
- Decision: reject as target owner. Escalate duplicate UID cleanup as separate supervisor/validator disposition.

## Source Placement
- Recommended placement: `MapPane::ScreenToMapCoords(MapPoint *point) const` emitted through [UID:00007Q][MapPane](../../../by-class/MapPane.md) into `NexusTK/map/MapPane.cpp`.
- Why this placement fits: the method is a small coordinate conversion method using MapPane viewport origin fields and project-wide tile dimensions, paired with UID00041X `MapPane::MapToScreenCoords` and adjacent visible-bounds helpers.
- Rejected placements: by-global MapTilePixelDimensions, UID0001AP aggregate body, raw helper/free function `sub_505170`, input-handler caller, FittingRoom, and no-owner/non-emitting.
- Remaining uncertainty: exact original declaration of `MapPoint` and field names is inferred from accepted docs, but the row/column convention is consistent across the coordinate support pages and generated output.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: `0x00505170-0x005051bb`, 75 bytes, one basic block. The function ends with `c2 04 00` at `0x005051b8-0x005051ba`.
- Preceding padding: `0x0050516a-0x00505170` is six `0xcc` bytes after predecessor `sub_505130` ending at `0x0050516a`.
- Following padding: `0x005051bb-0x005051c0` is five `0xcc` bytes before successor `sub_5051C0`.
- Reclassification: no split, merge, or no-owner reclassification is recommended. Existing ignored-padding ledger already records the surrounding alignment spans.
- Parent/container impact: [UID:0001AP] remains an aggregate marker over exact children; no parent metadata change is required.

## Negative Evidence Summary
- No callee ownership: the function has no callees.
- No global owner: tile dimension refs are data dependency reads, not ownership.
- No caller owner: one direct caller uses the method as a MapPane conversion helper.
- No aggregate body: UID0001AP already emits an aggregate marker; placing this method there would duplicate child output.
- No FittingRoom owner: the duplicate UID pages describe `0x00424550-0x0042456a`, not this range. They are a separate documentation defect.
- No no-owner/non-emitting path: target has a valid owner/emitter chain, strong behavior evidence, and generated output.

## IDA Rename / Type / Comment Recommendations
- No IDA DB edits are requested.
- Source-facing names to preserve in docs/source: `MapPane::ScreenToMapCoords`, `MapPoint`, `point`, `row`, `g_mapTilePixelWidth`, `g_mapTilePixelHeight`, `m_tileOriginX`, and `m_tileOriginY`.
- Raw names to keep only as evidence/search aliases: `sub_505170`, `word_66DA9C`, `word_66DAA0`.
- Type caveat: `MapPoint` row/column storage order is evidence-backed by sibling docs but not original-symbol proven; keep score below 95.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes. Target is reconstructable true, has nonblank emitter route through UID00007Q to UID0000L3, average score is already above 85, and current body is emitted.
- Implemented code disposition: preserve exactly this formal block in the target. Do not leave it as a report-only snippet.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void MapPane::ScreenToMapCoords(MapPoint *point) const
{
    const int row = point->row / g_mapTilePixelHeight;

    point->column = point->column / g_mapTilePixelWidth + m_tileOriginX - 1;
    point->row = row + m_tileOriginY - 1;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason it preserves behavior: matches the exact IDA decompile and disassembly: divide element 0 by height and add `+0x400 - 1`, divide element 1 by width and add `+0x3fc - 1`, then write results in place.
- Reason it matches plausible original source: small human-written coordinate conversion method with accepted MapPane field/global names; avoids decompiler temporaries, raw pointer indexing, ABI return, and `sub_` naming.
- Third-party import/no-code proof: not applicable.

## Final Recommendation
- Exact implemented target changes: set `COMPLETION:88`, `CONFIDENCE:92`; kept `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank `EMITTER_POSITION_OPTIONAL`; preserved the formal C++ block exactly as shown.
- Exact parent assignments retained: direct owner [UID:00007Q][MapPane](../../../by-class/MapPane.md) and source route [UID:0000L3][MapPane](../../../by-file/MapPane.md).
- Exact items left no-owner/non-emitting: none for UID00041Y. Surrounding padding remains ignored. Parent UID0001AP remains an aggregate marker, not a monolithic source body.
- Exact future work outside this UID00041Y source-quality decision: supervisor/validator should resolve the duplicate `UID00041Y` collision in the FittingRoom user-image pages under a separate UID/path repair instruction. Do not use that collision to change this MapPane target's C++.

## Recommended Target Doc Changes
- Target path: `by-memory/0x00505170-0x005051bb.MapPaneScreenToMapCoords.md`.
- Applied metadata/score changes: `COMPLETION:88`, `CONFIDENCE:92`; owner/emitter/reconstructable fields unchanged.
- Applied C++ disposition: no source body change; exact formal block from this report remains present in the target.
- Applied evidence: MCP session `60724697` health/provenance; exact range/size; one-basic-block/no-callee facts; bytes and predecessor/successor padding; decompile/disasm semantics; caller at `0x00507a43`; tile globals values `48`; generated `MapPane.cpp` body/header state; rejected alternatives; and confidence cap for inferred `MapPoint` declaration/field spelling.
- Historical/stale assumptions handled: B009 accepted split history preserved; duplicate UID collision recorded as a separate support-risk note and excluded/deferred by supervisor instruction.

## Recommended Support Doc Changes
- `by-class/MapPane.md`: already-present for UID00041Y placement, `m_tileOriginX/m_tileOriginY`, coordinate family, and MapPane source route; no support edit made.
- `by-file/MapPane.md`: already-present for UID00041Y in the coordinate conversion table and generated route through `NexusTK/map/MapPane.cpp`; no support edit made.
- `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`: already-present for UID00041Y row as `MapPane::ScreenToMapCoords`; no support edit made.
- `by-global/MapTilePixelDimensions.md` and width/height storage children: already-present for `g_mapTilePixelWidth`, `g_mapTilePixelHeight`, values `48`, and MapPane coordinate role; no support edit made.
- Duplicate UID support risk: `by-memory/0x00424550-0x0042456a.FittingRoomUserImageControlPaneAdvanceFacingDirection.md`, `by-class/FittingRoomUserImageControlPane.md`, and `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md` use the same `UID00041Y` for a different function or stale support rows. These FittingRoom paths were excluded/deferred because the supervisor explicitly marked the duplicate UID/FittingRoom collision out of scope for this callback.

## Score And Metadata Recommendation
- Current score/metadata after implementation: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank emitter position, formal C++ present.
- Implemented score/metadata: `COMPLETION:88`, `CONFIDENCE:92`, same owner/reconstructable/emitter fields.
- Score rationale: completion improves because current session evidence now covers exact bytes, caller, callee absence, padding, globals, generated output, support docs, and duplicate-UID caveat. Confidence improves because behavior is arithmetic-only and matches both IDA and generated C++.
- Reason not higher: `MapPoint` declaration and row/column field spelling remain inferred through accepted support docs, not original symbols; duplicate UID collision must be resolved outside this source-quality conclusion; broader MapPane class/file pages are not fully final-audit quality.
- Score-improvement attempt: checked owner route, emitter route, generated output, MCP function/caller/bytes, globals, sibling support pages, and old reports. No source-quality blocker remains for UID00041Y itself.
- Metadata fields changed or left unchanged: changed only scores; kept owner/emitter/reconstructable and C++ body.

## Open Questions With Attempted Resolution
- `MapPoint` exact original declaration: checked sibling coordinate docs, MapTilePixelDimensions naming notes, generated output, and B009 report. Best supported resolution is `MapPoint *point` with row/column fields; unresolved original spelling limits confidence below 95 but does not block emission.
- Width/height and row/column order: checked target decompile/disasm, UID00041X inverse body, and MapTilePixelDimensions. Best supported resolution is current code: row/Y divided by height, column/X divided by width.
- Duplicate UID conflict: checked the FittingRoom by-memory file and support refs. Best supported resolution is that this is a documentation/UID collision outside MapPane source semantics; requires supervisor/validator decision, not target code change.
- Need for support edits: checked MapPane class/file/global/aggregate docs. They are already sufficient for ownership/source route; target page is the only required source-quality update.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Not applicable. No manual `-coverage-report.md` or supervisor-owned tracker text was edited by B007.
- Validator-owned generated output refreshed through scoped file validation commands `000000006214` and `000000006219`; no manual generated/project-level edits were made.

## Follow-Up Actions
- Supervisor actions: lifecycle/execution handling for this report is supervisor-owned. Decide separately whether to include or defer duplicate UID collision cleanup for the FittingRoom user-image pages.
- A-agent actions: none requested.
- B007 future actions for this UID: none unless supervisor returns a specific repair or implementation follow-up.

## Confidence
- Recommendation confidence: high for MapPane owner, source route, current body, and score improvement.
- Score confidence: high for `88/92`; too high for 95+ because not all original type names and broader class/file declaration issues are final-audited.
- Remaining uncertainty: duplicate UID collision requires process/validator disposition; it does not alter target behavior.

## Validator Results
- Command run from `source-3/project-documentation`: `python .\tools\validator.py --mode file --file by-memory/0x00505170-0x005051bb.MapPaneScreenToMapCoords.md --apply --queue-timeout 240`.
- First command result: `command_id: 000000006214`, `command_timestamp: 2026-07-04T11:40:29-04:00`, exit code `0`, `ok: 1`, scanned markdown files `1`.
- First command updates: `completion_update 00041Y ... 88`, `confidence_update 00041Y ... 92`, `projected_stats_update`, `stats_row_remove`, and `stats_rescore_recommended` for project-level stats.
- Second command result: `command_id: 000000006219`, `command_timestamp: 2026-07-04T11:45:49-04:00`, exit code `0`, `ok: 1`, scanned markdown files `1`.
- Second command updates: `projected_stats_update` and `stats_incremental_noop` because UID00041Y was already absent from generated stats lists after the first validator.
- Warnings/errors: none reported by the scoped validator output. Duplicate `UID00041Y` FittingRoom collision remains excluded/deferred by supervisor instruction, not repaired in this callback.
- Generated refresh/freshness: both scoped validators reported `generated_refresh: deferred`; after the second validator, `auto-generated/NexusTK/map/MapPane.cpp` refreshed to header `validator-command-id: 000000006219`, `validator-refreshed-at: 2026-07-04T11:45:49-04:00`; UID00041Y line 336 shows `Completion:88 | Confidence:92` and still emits `MapPane::ScreenToMapCoords`.

## Changed Files
- Modified by B007: `by-memory/0x00505170-0x005051bb.MapPaneScreenToMapCoords.md` and `tools/leaser/Agents/Agent-B007/research/00041Y-MapPaneScreenToMapCoords-source-quality.md`.
- Support by-* docs inspected but not edited: `by-class/MapPane.md`, `by-file/MapPane.md`, `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`, and `by-global/MapTilePixelDimensions.md`.
- Validator-generated side effects observed: `auto-generated/NexusTK/map/MapPane.cpp` refreshed to command `000000006219`; validator output also reported projected stats updates, first-command stats row removal/recommendation, and second-command stats incremental noop for `project-level/-auto-completion-stats.md`.
- Renamed: none.
- Report execution: not run. B007 did not run `execute_report`, dry-run/probing variants, lifecycle/archive commands, registry commands, manual generated edits, coverage edits, supervisor-ledger edits, or report moves.

## Implementation Tracking Checklist

Report-only pass history:
- [x] Report-only research completed with MCP session `60724697` evidence and no by-* edits during the initial pass.
- [x] Supervisor Gate 1 accepted the report and authorized implementation callback.

Implementation callback pass:
- [x] Target doc updated: `by-memory/0x00505170-0x005051bb.MapPaneScreenToMapCoords.md`.
- [x] Target metadata applied: `COMPLETION:88`, `CONFIDENCE:92`; `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, and blank `EMITTER_POSITION_OPTIONAL` preserved.
- [x] Formal C++ confirmed already-present and unchanged: `void MapPane::ScreenToMapCoords(MapPoint *point) const` remains the target `RECONSTRUCTION_CPP CODE` body.
- [x] Exact target evidence incorporated: MCP session `60724697` health/provenance, `sub_505170` range `0x00505170-0x005051bb`, size `0x4b`, exact bytes, padding `0x0050516a-0x00505170` and `0x005051bb-0x005051c0`, one caller `0x00507a43`, no callees, tile globals `0x0066da9c/0x0066daa0 == 48`, generated output header/body state, rejected alternatives, and confidence caps.
- [x] Support docs inspected and marked already-present: `by-class/MapPane.md`, `by-file/MapPane.md`, `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`, and `by-global/MapTilePixelDimensions.md`.
- [x] Duplicate UID collision accounted for as excluded-with-reason: `by-memory/0x00424550-0x0042456a.FittingRoomUserImageControlPaneAdvanceFacingDirection.md` and related FittingRoom support docs were not edited because supervisor marked the duplicate UID/FittingRoom collision out of scope for this callback.
- [x] Claim And Incorporation Ledger updated: C-00041Y-01 through C-00041Y-10 are `applied`, `already-present`, or `excluded-with-reason` with destination proof.
- [x] Historical/stale assumptions and rejected alternatives preserved: B009 accepted split history; rejected raw `sub_505170`, UID0001AP aggregate body, MapTilePixelDimensions ownership, input-handler ownership, no-owner/non-emitting, and FittingRoom duplicate-UID ownership.
- [x] Open questions preserved as confidence caps: inferred `MapPoint` declaration/field spelling and duplicate UID collision process handling.
- [x] Lease used/released: B007 leased `by-memory/0x00505170-0x005051bb.MapPaneScreenToMapCoords.md` for two immediate edit/validator windows and released it after each validation.
- [x] Scoped validators run and recorded: first command `000000006214`, timestamp `2026-07-04T11:40:29-04:00`, exit `0`, `ok:1`; second command `000000006219`, timestamp `2026-07-04T11:45:49-04:00`, exit `0`, `ok:1`; no warnings/errors reported.
- [x] Generated refresh checked: `auto-generated/NexusTK/map/MapPane.cpp` header now matches command `000000006219` / `2026-07-04T11:45:49-04:00`; UID00041Y output remains the method body and is not an Empty Emitter Marker.
- [x] Remaining unapplied accepted items: none. The only deferred item is the supervisor-excluded duplicate UID/FittingRoom collision.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000006237","destination_path":"executed-b-agent-research/B007/00041Y-MapPaneScreenToMapCoords-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/00041Y-MapPaneScreenToMapCoords-source-quality.md","timestamp":"2026-07-04T11:58:23-04:00","uid":"00041Y"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
