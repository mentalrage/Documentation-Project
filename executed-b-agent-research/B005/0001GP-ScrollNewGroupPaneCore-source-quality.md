** TARGET-REPORT-UID:0001GP **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001GP ScrollNewGroupPaneCore Source-Quality / Split Research

## Finalized Report / Current Recommendation

- Current recommendation: convert [UID:0001GP] `by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md` from a code-emitting method-cluster page into a reviewed non-emitting split index, then create exact child by-memory pages for the constructor, two raw early setters, range/position/show helpers, mouse handler, false/default virtual, timer callback, and paint method.
- Final disposition: [UID:0001GP] itself should not emit C++ because it is an aggregate over multiple source methods plus alignment. The exact children should carry ownership, emitter routing, and first-draft C++ or target-specific no-code proofs.
- Required action: supervisor validation, then implementation callback to create/repair the child pages and synchronize [UID:0000CL] `ScrollNewGroupPane`, [UID:0000JS] `Group`, [UID:0002OS] vtable data, and [UID:0003CQ] scrollbar constants.
- Confidence: strong for the split/owner/source route; medium-high for the final spelling of the raw `+0xfa` setter and the full `OnPaint` formal C++ because those remain target-specific no-code cases after current evidence.

## Supporting Research

## Target

- Target UID: `0001GP`
- Target path: `by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md`
- Source queue/report row: supervisor-assigned B005 report-only pass for reconstructable by-memory research.
- Current supervisor classification: source-quality and first-draft-C++ readiness pass; current blank formal C++ and generic helper/source names are active blockers to investigate.
- Current scores and parent state: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000CL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CL`, `EMITTER_POSITION_OPTIONAL:40`, blank formal C++.
- Parent/support state: [UID:0000CL] `ScrollNewGroupPane` is `85/86` and routes to [UID:0000JS] `Group`, which is `89/85` with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/social/"`.

## Current Target State

- Existing metadata: target is currently a reconstructable emitter through the class at position `40`.
- Existing owner/emitter/reconstructable state: direct semantic owner [UID:0000CL] `ScrollNewGroupPane` is correct for the executable methods; the target-level emission is too broad because the page spans ten source-shaped bodies and padding.
- Existing C++/emitter state: formal C++ is blank. The existing reason says helper names and adjacent raw starts are not final-source quality.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims:
  - The target text says `0x005609a1-0x00560a10` contains padding plus two small setter bodies but does not split those bodies.
  - `0x005609b0` and `0x005609e0` are real raw method-shaped setters with no IDA function objects, no xrefs, and no VA/RVA pointer hits.
  - The field at `+0xfa` is not named in [UID:0000CL]'s shared alias table, while generic [UID:00042X] `ScrollPaneByteStateSetterRaw` and [UID:0001GM] `ScrollSpellInventoryPane` show the same family pattern as a style/state byte.
  - Existing `CanResize` and `OnSelectionChanged` names are misleading under current vtable evidence. The small false virtual matches the generic scrollbar `CanScroll(int)` slot shape, and the `0x00560d00` body is a TimerHandler-adjusted repeat callback.
  - `OnPaint` uses EPF resource/layout/render helpers and needs its own exact child page; parent-level C++ would be a monolithic method cluster.
- Related target/support docs checked:
  - [UID:0000CL] `by-class/ScrollNewGroupPane.md`
  - [UID:0000JS] `by-file/Group.md`
  - [UID:000090] `by-class/NewGroupPane.md`
  - [UID:0001GQ] `by-memory/0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart.md`
  - [UID:0001GR] `by-memory/0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md`
  - [UID:0001GS] `by-memory/0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md`
  - [UID:0002OS] `by-memory/0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData.md`
  - [UID:0003CQ] `by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md`
  - [UID:0000NF] `by-file/ScrollBar.md`
  - [UID:0001VP] `by-type/by-struct/RectBoundsLayout.md`
  - [UID:000165] / [UID:00016A] / [UID:0002KP] paint/resource helper context through current reports and class docs
  - Executed reports: B002 `0001GQ`, B005 `0001GR`, B008 `0001GS`, B004 `0001GH`, B002 `0001GM`.

## Executive Recommendation

[UID:0001GP] should become a non-emitting split index, matching the accepted treatment for [UID:0001GS] and the generic [UID:0001GH] input-core split precedent. The direct owner of the actual methods remains [UID:0000CL] `ScrollNewGroupPane`; the source-file route remains [UID:0000JS] `Group` / `NexusTK/social/Group.cpp`. The parent page should document the exact child map and no-code proof, while exact child pages should carry formal C++ or target-specific no-code proofs.

The split is not a deferral. It is the repair for the score/C++ blocker: the current page is too broad to receive valid formal C++. The missing C++ is solved by moving C++ eligibility to exact method children, not by leaving the broad parent blank under "future work."

## Supervisor Active Recheck

- Triggering instruction: B005 was assigned report-only research for [UID:0001GP] with mandatory IDA MCP evidence and no by-* edits before supervisor validation.
- Split repair needed before final source output: yes. The assigned item is a method cluster with internal raw functions and padding, not a single source function.
- Source-bearing child disposition: every executable body in `0x00560900-0x00561420` has an implementation-ready child recommendation below. Raw no-function starts have target-specific no-code proofs. Modeled small bodies have formal first-draft C++ insertion blocks. The large mouse and paint methods have exact child recommendations with target-specific no-code proofs.

## Inference Research Guidance Check

- IDA facts are separated from inference: function starts/sizes, xrefs, vtable data refs, disassembly, and pointer-search results are treated as facts; source-facing names such as `m_scrollStyleByte` and `OnScrollTimer` are marked as inferred/descriptive.
- Existing documentation assumptions treated as uncertain: the parent page's broad emitter route, the `CanResize` name, the `OnSelectionChanged` name, the lack of a `+0xfa` alias, and the idea that the two early raw setters can remain only a note inside the aggregate.
- Wave2/Wave3: old Wave2/Wave3/simroot mentions in support docs are ignored as stale ownership evidence. Current by-* docs, MCP, accepted reports, and by-structure rules are used instead.

## Heuristic / Inference Reanalysis And Validation

- `+0xf8`: strongly inferred as `m_scrollSkinIndex` / historical `m_scrollStyle`. Constructor writes the low word of `0x10000` to zero, `HitTestPart`, `GetPartRect`, and `OnPaint` index the shared `dword_624144` vertical extent table through this word. Use `m_scrollSkinIndex` in new support docs and note `m_scrollStyle` as a historical alias until sibling C++ blocks are reconciled.
- `+0xfa`: best current field name is `m_scrollStyleByte` or `m_scrollStateByte`, with `m_scrollStyleByte` preferred because generic [UID:00042X] and [UID:0001GM] establish the same raw setter family as a style/state byte. The current core/paint disassembly does not read the byte, so do not freeze a stronger semantic name. It is not padding: the raw setter compares/writes it and invalidates the bounds.
- `+0xfb`: `m_thumbDragActive`, confirmed by vertical thumb-drag math in `GetPartRect`, `HitTestPart`, and `OnPaint`.
- `+0xfc`: `m_orientation`, zero vertical and nonzero horizontal.
- `+0xfe/+0x100/+0x102`: `m_scrollPosition`, `m_scrollRange`, and `m_scrollEnabled`, confirmed by constructor initialization, range/position setters, enabled/range gates, and sibling geometry pages.
- `+0x103/+0x104`: `m_highlightPart` and `m_activePart`, confirmed by interaction children and vtable callback checks.
- `+0x108/+0x10c`: `m_thumbDragOffset`, project point order `y, x`.
- `0x00560cf0`: rename from `CanResize` to `CanScroll(int)` or `CanScroll`-style default false virtual. It has the same five-byte false-return `retn 4` shape and secondary vtable slot role as generic [UID:000434] `ScrollPaneCanScroll`.
- `0x00560d00`: rename from `OnSelectionChanged` to `OnScrollTimer` / `OnTimer`. It is referenced by the secondary `+0x34` slot and tertiary `+0x04` slot, checks timer id zero, calls `UpdateActiveInteraction`, and reschedules a 30ms timer while an active part is present.
- `OnPaint`: class-owned and source-authored, but formal C++ should be on a child page and remain blank for this pass under `NC-11` because exact EPF frame-layout/render helper declarations are not ready enough for copy/paste formal source.
- Rejected alternatives:
  - Keep [UID:0001GP] emitting one parent block: rejected because it would mix ten method bodies and padding in one by-memory C++ block.
  - Treat raw early setters as padding/dead bytes: rejected because disassembly shows complete compare/write/invalidate methods.
  - Route direct ownership to [UID:0000JS] `Group`: rejected because [UID:0000CL] is the direct class owner and clears the gate.
  - Route to generic [UID:0000NF] `ScrollBar`: rejected as pattern/support only; receiver fields, vtables, constructor caller, and callback route are `ScrollNewGroupPane`/`NewGroupPane`.
  - Use stale `TextEditPane` generated ownership: rejected by current caller/vtable/field route and accepted sibling reports.

## Evidence Standards Used

- IDA MCP functions used: `server_health`, `idb_list`, `lookup_funcs`, `xrefs_to`, `callees`, `disasm`, `analyze_function`, and `find_bytes`.
- Evidence types used: function boundaries, raw disassembly, xrefs, vtable data refs, constructor callers, direct callers, callee sets, resource/render helper operands, pointer-byte negative searches, accepted by-* docs, and accepted B-agent reports.
- Evidence ladder: direct MCP function/xref/disassembly facts first; accepted by-* docs and executed reports second; sibling scrollbar heuristics only after target-local evidence matched the pattern.
- Tool limitation: IDA MCP cannot recover original source names. The report therefore recommends plausible source-facing names and marks them inferred where original proof is absent.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `server_health` for session `80de0a67` returned `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
  - `lookup_funcs` for `0x00560900`, `0x005609b0`, `0x005609e0`, `0x00560a10`, `0x00560a70`, `0x00560aa0`, `0x00560b00`, `0x00560cf0`, `0x00560d00`, `0x00560d40`, and `0x00561420`.
  - `xrefs_to` for the same starts.
  - `find_bytes` for VA/RVA byte encodings of `0x005609b0` and `0x005609e0`: `B0 09 56 00`, `B0 09 16 00`, `E0 09 56 00`, and `E0 09 16 00`; all zero matches.
  - `disasm` for `0x005609b0`, `0x005609e0`, and filtered `0x00560d40` paint instructions.
  - Prior current-pass `analyze_function` facts for constructor, range setter, position setter, show helper, mouse method, false virtual, timer callback, and paint method.
- by-* docs, support docs, old reports, generated reports, and trackers checked: target, class, file, NewGroupPane, HitTestPart, GetPartRect, RawAndInteractionHelpers, vtable data, scrollbar constants, generic ScrollPane/ScrollWidget split precedent, ScrollSpellInventoryPane sibling precedent, and accepted executed reports listed above.
- Negative checks performed: zero xrefs to raw starts `0x005609b0` and `0x005609e0`; zero VA/RVA pointer-byte matches for both raw starts; no OnPaint disassembly read of `+0xfa`; generic/TextEditPane/file-owner alternatives checked and rejected.
- Failed, unavailable, or intentionally skipped checks and why: a broad `search_text` sweep for resource string names timed out inside MCP. The server stayed listening and recovered on health check after a brief wait. I did not use that timed-out search as evidence because paint disassembly, target docs, and accepted support pages already identify the resource-layout operands and helper family.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| [UID:0001GP] should be a split index, not an emitter | Strong | Multiple modeled functions, two raw setters, padding, by-structure aggregate rules, [UID:0001GS]/[UID:0001GH] precedents | Single parent C++ route, class-level C++ route | Child creation/validator run during implementation |
| Direct owner for child methods is [UID:0000CL] | Strong | constructor call from `NewGroupPane`, vtable slots, class fields, child pages, file route | direct file owner, generic ScrollBar, TextEditPane | None for current gate |
| `+0xfa` is a scrollbar style/state byte | Medium-high | raw setter body, constructor initializes it to `1`, generic ScrollPane and ScrollSpellInventoryPane precedent | no reads seen in core/paint; no original symbol | Keep inferred name and blank formal C++ for raw setter |
| `0x00560cf0` is `CanScroll`-style false virtual | Strong | five-byte false `retn 4`, secondary slot parity with generic ScrollPane | existing `CanResize` prose | Rename in support docs during implementation |
| `0x00560d00` is timer/repeat callback, not selection change | Strong | secondary and tertiary vtable refs, timer id check, `UpdateActiveInteraction`, `ScheduleTimer(0,30,0,0)` | old `OnSelectionChanged` name | Rename in support docs during implementation |
| `OnPaint` should have exact child page but blank formal C++ now | Strong | large `0x6e0` method, EPF/layout/render helper dependencies, filtered disassembly, helper docs not final | current page's blank C++ reason too vague | Future child-specific paint/helper signature pass |

## Positive Evidence Summary

- Direct facts supporting the chosen recommendation:
  - `lookup_funcs` reports real modeled methods at `0x00560900`, `0x00560a10`, `0x00560a70`, `0x00560aa0`, `0x00560b00`, `0x00560cf0`, `0x00560d00`, and `0x00560d40`.
  - `lookup_funcs` reports `0x005609b0` and `0x005609e0` are not IDA functions, but raw `disasm` shows complete setter bodies.
  - `xrefs_to` reports constructor call from `NewGroupPane` at `0x0056caae`, range setter caller `0x0056cda2`, position setter callers `0x0056ce39`, `0x0056dbbd`, and `0x0056df1c`, show caller `0x0056cac3`, and vtable/data refs for mouse/default/timer/paint slots.
  - [UID:0000CL] already documents the class route and exact child pages after this core range.
- Corroborating documentation/generated-report evidence:
  - [UID:0001GQ], [UID:0001GR], and [UID:0001GS] already use exact child pages for the later `ScrollNewGroupPane` methods.
  - [UID:0001GH] generic `ScrollPaneInputCore` was converted to a non-emitting split index under the same by-structure rule.
  - [UID:00042X] and [UID:0001GM] provide sibling evidence for the raw `+0xfa` style/state setter pattern and no-code proof.
- Strongest inference chain: target-local raw setter body plus generic sibling precedent supports a descriptive `m_scrollStyleByte` name, but the absence of reads/xrefs/pointer route keeps the raw child blank for formal C++.

## IDA MCP Facts

- Function/range facts:
  - `0x00560900`: `sub_560900`, size `0xa1`, constructor.
  - `0x005609b0`: not a function; raw setter over word `+0xf8`, ends at `0x005609d7`.
  - `0x005609e0`: not a function; raw setter over byte `+0xfa`, ends at `0x00560a04`.
  - `0x00560a10`: `sub_560A10`, size `0x5b`, range setter.
  - `0x00560a70`: `sub_560A70`, size `0x27`, position setter.
  - `0x00560aa0`: `sub_560AA0`, size `0x1a`, enable/show helper.
  - `0x00560b00`: `sub_560B00`, size `0x1e1`, mouse/input method.
  - `0x00560cf0`: `sub_560CF0`, size `0x5`, false virtual.
  - `0x00560d00`: `sub_560D00`, size `0x33`, timer/update callback.
  - `0x00560d40`: `sub_560D40`, size `0x6e0`, paint method.
  - `0x00561420`: successor `HitTestPart`, size `0x31d`.
- Data/table/padding facts:
  - raw `0x005609b0` setter updates `+0xf8` and invalidates `this+0x44` through primary vtable slot `+0x20`.
  - raw `0x005609e0` setter updates `+0xfa` and invalidates `this+0x44` through primary vtable slot `+0x20`.
  - `OnPaint` reads `+0xfc`, `+0xf8`, `+0xfb`, `+0xfe`, `+0x100`, and `+0x102`, and uses `dword_624144` / `0x00624144` vertical extent constants.
- Xref facts:
  - `0x005609b0` and `0x005609e0`: zero xrefs and zero VA/RVA pointer hits in current pass.
  - `0x00560b00`: data ref from `0x00623f6c`.
  - `0x00560cf0`: data ref from `0x00623f70`.
  - `0x00560d00`: data ref from `0x00623f9c`, and [UID:0002OS] also records the secondary slot route.
  - `0x00560d40`: data ref from `0x00623f60`.
- Vtable/global/type facts:
  - Constructor stores primary, secondary, and tertiary `ScrollNewGroupPane` table bases at `0x00560951`, `0x00560957`, and `0x00560961`.
  - [UID:0002OS] owns the exact vtable data range `0x00623f18-0x00623fa0`.
- Negative IDA facts:
  - No modeled functions at `0x005609b0` or `0x005609e0`.
  - No xrefs and no pointer-byte route to the raw starts.
  - Broad MCP string search timed out and is not used as proof.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00560900-0x005609a1` | new `ScrollNewGroupPaneConstructor` | constructor | TRUE | `0000CL` | `86/89` | create exact child with `CXX-01` |
| `0x005609a1-0x005609b0` | padding | `0xcc`/alignment after constructor | FALSE | none | n/a | record as padding in parent |
| `0x005609b0-0x005609d7` | new `ScrollNewGroupPaneSkinIndexSetterRaw` | raw `+0xf8` setter/invalidate | TRUE | `0000CL` | `85/88` | create exact child with `NC-02`, blank C++ |
| `0x005609d7-0x005609e0` | padding | alignment before second raw setter | FALSE | none | n/a | record as padding in parent |
| `0x005609e0-0x00560a04` | new `ScrollNewGroupPaneStyleByteSetterRaw` | raw `+0xfa` setter/invalidate | TRUE | `0000CL` | `85/87` | create exact child with `NC-03`, blank C++ |
| `0x00560a04-0x00560a10` | padding | alignment before modeled range setter | FALSE | none | n/a | record as padding in parent |
| `0x00560a10-0x00560a6b` | new `ScrollNewGroupPaneSetMaxRange` | clamp range/current value | TRUE | `0000CL` | `87/89` | create exact child with `CXX-04` |
| `0x00560a6b-0x00560a70` | padding | alignment | FALSE | none | n/a | record as padding |
| `0x00560a70-0x00560a97` | new `ScrollNewGroupPaneSetScrollPosition` | set current position | TRUE | `0000CL` | `87/89` | create exact child with `CXX-05` |
| `0x00560a97-0x00560aa0` | padding | alignment | FALSE | none | n/a | record as padding |
| `0x00560aa0-0x00560aba` | new `ScrollNewGroupPaneShow` | enable scroll display | TRUE | `0000CL` | `86/89` | create exact child with `CXX-06` |
| `0x00560aba-0x00560b00` | padding | alignment before virtual mouse method | FALSE | none | n/a | record as padding |
| `0x00560b00-0x00560ce1` | new `ScrollNewGroupPaneHandleMouseEvent` | EventHandler-adjusted mouse/capture/drag path | TRUE | `0000CL` | `86/89` | create exact child with `NC-09`, blank C++ |
| `0x00560ce1-0x00560cf0` | padding | alignment before false virtual | FALSE | none | n/a | record as padding |
| `0x00560cf0-0x00560cf5` | new `ScrollNewGroupPaneCanScroll` | default false virtual | TRUE | `0000CL` | `85/89` | create exact child with `CXX-10` |
| `0x00560cf5-0x00560d00` | padding | alignment before timer callback | FALSE | none | n/a | record as padding |
| `0x00560d00-0x00560d33` | new `ScrollNewGroupPaneOnScrollTimer` | TimerHandler-adjusted repeat callback | TRUE | `0000CL` | `86/89` | create exact child with `CXX-11` |
| `0x00560d33-0x00560d40` | padding | alignment before paint | FALSE | none | n/a | record as padding |
| `0x00560d40-0x00561420` | new `ScrollNewGroupPaneOnPaint` | EPF track/thumb paint | TRUE | `0000CL` | `86/89` | create exact child with `NC-12`, blank C++ |
| `0x00561420` | existing [UID:0001GQ] | successor `HitTestPart` | TRUE | `0000CL` | `88/90` | already split/emitting |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00560900` | code xref `0x0056caae` in `NewGroupPane::NewGroupPane` | direct construction of custom scroll child |
| `0x005609b0` | no xrefs, no VA/RVA pointer hits | raw source-shaped body, no proven call route |
| `0x005609e0` | no xrefs, no VA/RVA pointer hits | raw source-shaped body, no proven call route |
| `0x00560a10` | code xref `0x0056cda2` | `NewGroupPane::UpdateScrollRange` applies range |
| `0x00560a70` | code xrefs `0x0056ce39`, `0x0056dbbd`, `0x0056df1c` | range update, mouse click, and owner callback set position |
| `0x00560aa0` | code xref `0x0056cac3` | constructor enables/shows child |
| `0x00560b00` | data ref `0x00623f6c` | secondary vtable mouse/event method |
| `0x00560cf0` | data ref `0x00623f70` | secondary vtable false/default method |
| `0x00560d00` | data ref `0x00623f9c` | tertiary/secondary timer callback |
| `0x00560d40` | data ref `0x00623f60` | primary paint slot |
| `0x00561420` | calls from `0x00560be1` and `0x00561b6f` | successor hit-test helper called by core mouse and interaction paths |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - [UID:0000CL] lists the class method family and already accepts child pages after this core range.
  - [UID:0001GS] is a non-emitting split index for the following interaction range.
  - [UID:0001GQ] and [UID:0001GR] already carry formal first-draft C++ for exact children after this range.
  - [UID:0002OS] proves the vtable slots and constructor-store route.
  - [UID:000090] proves the `NewGroupPane` construction/callback context.
- Existing docs that are stale, incomplete, or contradicted:
  - [UID:0001GP] should stop saying raw early setters are "delegated to later child splits" without actually creating/recommending those child splits.
  - [UID:0000CL] should add a `+0xfa` alias row and replace `CanResize`/`OnSelectionChanged` wording.
  - [UID:0003CQ] has a blank item summary and should record the `0x00624144` vertical extent slice consumed by this class.
- Generated/coverage report state: no generated/project-level files were edited. Report execution should refresh `auto-generated/-ag-research-tracker.md` through the supervisor-owned `execute_report` command.

## Ranked Ownership Analysis

### 1. [UID:0000CL] `ScrollNewGroupPane`

- Evidence for: constructor call from `NewGroupPane`, direct vtable slots, field offsets, class support page, sibling child pages, interaction callback into `NewGroupPane`, and matching `ScrollNewGroupPane` vtable data.
- Evidence against: generic scrollbar implementation patterns influence naming, and some helper names are still inferred.
- Decision: accepted direct semantic owner/emitter for exact executable child pages.

### 2. [UID:0000JS] `Group`

- Evidence for: feature file owns `NewGroupPane`, constructs the custom scroll child, and routes [UID:0000CL] to generated `NexusTK/social/Group.cpp`.
- Evidence against: it is a source-file route, not the narrowest semantic owner for class methods.
- Decision: keep as ancestor/source route only.

### 3. [UID:0000NF] `ScrollBar` / generic scrollbar family

- Evidence for: shared field layout, part IDs, raw setter pattern, `dword_624144` constants, and sibling generic ScrollPane precedent.
- Evidence against: no generic ScrollBar method owns this exact receiver. The receiver fields, vtables, and callers are `ScrollNewGroupPane`/`NewGroupPane`.
- Decision: reject as owner; use as naming/support evidence.

### 4. `TextEditPane` or generated simroot owners

- Evidence for: stale generated output polluted some later helper labels historically.
- Evidence against: current xrefs, vtables, fields, accepted reports, and callback route reject this.
- Decision: reject as stale generated ownership.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new source file. Exact child methods should emit through [UID:0000CL] into [UID:0000JS] `NexusTK/social/Group.cpp`.
- Likely full contents: the split children listed above plus existing `HitTestPart`, `GetPartRect`, and interaction children.
- Candidate related items rejected: generic ScrollBar ownership and `TextEditPane` helper ownership.
- Standalone, narrow, or broad source-file inference: narrow class-owned method children under a broader Group feature file.

## Source Placement

- Recommended source file/class/global/module placement: `ScrollNewGroupPane` class methods under `NexusTK/social/Group.cpp` through [UID:0000CL] -> [UID:0000JS].
- Why this placement fits source-tree and subsystem context: `NewGroupPane` creates, shows, ranges, and receives scroll-position callbacks from the object; the group feature file already owns `NewGroupPane` and the custom scroll child.
- Rejected placements and why:
  - `ScrollBar.cpp`: too generic for this class-specific child.
  - `TextEditPane.cpp`: stale generated route.
  - separate new `ScrollNewGroupPane.cpp`: possible final style choice but not supported as a separate by-file page now; current [UID:0000JS] route is already accepted.
- Remaining placement uncertainty: final class declaration/header split is still a whole-class question; exact method children can emit through [UID:0000CL] now.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: [UID:0001GP] spans `0x00560900-0x00561420` half-open, ending immediately before [UID:0001GQ] `HitTestPart`.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: create the exact child pages in the inventory table; keep padding rows inside the parent split index; no merge with [UID:0001GQ].
- Padding/table/data/code distinctions: raw setters are executable code, not padding; alignment/padding lies between child bodies.
- Parent/container impact: [UID:0001GP] should become `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, blank C++, and serve as a non-emitting audit/split index.

## Negative Evidence Summary

- Zero xrefs to raw starts `0x005609b0` and `0x005609e0`.
- Zero VA/RVA pointer-byte hits to raw starts.
- No current OnPaint/core disassembly read of `+0xfa`, so the field name remains descriptive rather than final.
- Generic scrollbar and ScrollSpellInventoryPane precedent support the raw setter pattern but do not prove original `ScrollNewGroupPane` names.
- Existing `CanResize` / `OnSelectionChanged` labels are not supported by the current vtable/callback evidence as strongly as `CanScroll` and `OnScrollTimer`.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names/types/comments:
  - `m_scrollSkinIndex` for `+0xf8`, with historical alias `m_scrollStyle`.
  - `m_scrollStyleByte` for `+0xfa`, marked inferred/descriptive.
  - `ScrollNewGroupPane::CanScroll(int)` for `0x00560cf0`.
  - `ScrollNewGroupPane::OnScrollTimer(int timerId, int, int)` for `0x00560d00`.
  - `ScrollNewGroupPane::Show()` for `0x00560aa0`, preserving current support wording; if later style prefers `Enable`, document the alias.
- Items intentionally left unchanged and why:
  - `OnMouseEvent` and `OnPaint` remain descriptive names because vtable roles are clear but exact event/render helper signatures are not formal-C++-ready.
  - Raw setters should be documented as source-shaped children but not renamed in IDA or emitted as callable methods without a proven route.
- Whether IDA DB edits are safe, unsafe, or not requested: no IDA DB edits requested in this report-only pass.

## First-Draft C++ Recommendation

- Eligible for draft C++: exact small/modeled child pages for constructor, range setter, position setter, show/enable helper, false default virtual, and timer callback.
- Parent [UID:0001GP] recommended code: blank.
- Parent exact no-code proof: [UID:0001GP] covers ten source-shaped methods plus padding. A single formal C++ block would either duplicate exact child bodies, omit covered bytes, or conflate constructor, raw setters, event handling, timer, and paint code into one non-source unit. By-structure says by-memory C++ must be limited to that page's own source shape; the correct source shape here is a split-index parent plus exact child emitters.
- Inferred source-facing names/types/fields used: `ScrollNewGroupPane`, `ScrollNewGroupPart`, `m_scrollSkinIndex`, `m_scrollStyleByte`, `m_thumbDragActive`, `m_orientation`, `m_scrollPosition`, `m_scrollRange`, `m_scrollEnabled`, `m_highlightPart`, `m_activePart`, `m_thumbDragOffset`, `InvalidateRect`, `ScheduleTimer`, and `UpdateActiveInteraction`.
- Naming/coding style convention used: existing project C++ style on [UID:0001GQ]/[UID:0001GR]/[UID:0001GO], with `m_` members, enum constants, and simple early returns.

Formal insertion text for child pages that should receive C++:

`CXX-01` for `by-memory/0x00560900-0x005609a1.ScrollNewGroupPaneConstructor.md`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ScrollNewGroupPane::ScrollNewGroupPane(bool horizontal)
    : Pane(true)
{
    m_scrollSkinIndex = 0;
    m_scrollStyleByte = 1;
    m_thumbDragActive = false;
    m_orientation = horizontal ? 1 : 0;
    m_scrollPosition = 0;
    m_scrollRange = 0;
    m_scrollEnabled = true;
    m_highlightPart = kScrollNewGroupPartNone;
    m_activePart = kScrollNewGroupPartNone;
    InitPointPair(&m_thumbDragOffset, 0, 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

`CXX-04` for `by-memory/0x00560a10-0x00560a6b.ScrollNewGroupPaneSetMaxRange.md`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ScrollNewGroupPane::SetMaxRange(short maxRange)
{
    if (maxRange < 0) {
        maxRange = 0;
    }
    if (maxRange > 30000) {
        maxRange = 30000;
    }

    if (m_scrollRange == maxRange) {
        return;
    }

    if (maxRange < m_scrollPosition) {
        m_scrollPosition = maxRange;
        InvalidateRect(&m_bounds);
    }

    m_scrollRange = maxRange;
    InvalidateRect(&m_bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

`CXX-05` for `by-memory/0x00560a70-0x00560a97.ScrollNewGroupPaneSetScrollPosition.md`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ScrollNewGroupPane::SetScrollPosition(short scrollPosition)
{
    if (m_scrollPosition == scrollPosition) {
        return;
    }

    m_scrollPosition = scrollPosition;
    InvalidateRect(&m_bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

`CXX-06` for `by-memory/0x00560aa0-0x00560aba.ScrollNewGroupPaneShow.md`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ScrollNewGroupPane::Show()
{
    if (m_scrollEnabled) {
        return;
    }

    m_scrollEnabled = true;
    InvalidateRect(&m_bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

`CXX-10` for `by-memory/0x00560cf0-0x00560cf5.ScrollNewGroupPaneCanScroll.md`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ScrollNewGroupPane::CanScroll(int)
{
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

`CXX-11` for `by-memory/0x00560d00-0x00560d33.ScrollNewGroupPaneOnScrollTimer.md`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ScrollNewGroupPane::OnScrollTimer(int timerId, int, int)
{
    if (timerId == 0 && m_activePart != kScrollNewGroupPartNone) {
        UpdateActiveInteraction();
        ScheduleTimer(0, 30, 0, 0);
    }

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Target-specific no-code proofs:

| Proof id | Proposed child | Current-pass evidence checked | Exact target-specific no-code proof |
| --- | --- | --- | --- |
| `NC-02` | `ScrollNewGroupPaneSkinIndexSetterRaw` | `lookup_funcs` not-a-function; `xrefs_to` zero; `find_bytes` zero VA/RVA hits; raw `disasm` proves compare/write of `+0xf8`, invalidate through vtable `+0x20`, and `retn 4`; [UID:0000CL], [UID:0001GQ], [UID:0001GR], [UID:00042X] checked. | The body is source-shaped and class-owned, and the field is strongly `m_scrollSkinIndex`, but no function object, direct caller, table route, or original method name is recoverable. Emitting a guessed callable setter would invent an unsupported API. |
| `NC-03` | `ScrollNewGroupPaneStyleByteSetterRaw` | `lookup_funcs` not-a-function; `xrefs_to` zero; `find_bytes` zero VA/RVA hits; raw `disasm` proves compare/write of `+0xfa`, invalidate through vtable `+0x20`, and `retn 4`; OnPaint/core disassembly checked for reads; generic/sibling docs checked. | The body is source-shaped and class-owned, and the best field direction is `m_scrollStyleByte`, but no current reads, caller route, or original name proves a formal source method. Keep reconstructable/owned, blank C++, and document the exact raw body. |
| `NC-09` | `ScrollNewGroupPaneHandleMouseEvent` | `analyze_function`/callee/xref evidence shows adjusted EventHandler method, event byte and coordinate reads, capture/release helpers, HitTestPart/GetPartRect calls, timer/update setup, highlight/active/drag state writes. | Owner and behavior are strong, but formal C++ would still require exact event struct/enums, capture/release helper signatures, and branch-level helper declarations. A broad first-draft body here would be decompiler-shaped rather than copy/paste formal source. |
| `NC-12` | `ScrollNewGroupPaneOnPaint` | `lookup_funcs` size `0x6e0`; filtered `disasm` shows gates on `+0x102/+0x100`, orientation branch, `dword_624144`, `m_thumbDragActive`, EPF/layout/render calls, `GetPartRect`, and helper/resource operands. | Owner and behavior are strong, but formal C++ requires exact source-facing signatures for EPF tile context/layout lookup, frame/tile rendering, palette/resource table wrappers, and inherited GrafPort draw-mode side effects. Those helper declarations are not ready enough for a formal insertion block in this pass. Create a child page and preserve the no-code proof. |

## Final Recommendation

- Exact changes recommended:
  - Convert [UID:0001GP] into a non-emitting split index with a full child inventory and parent no-code proof.
  - Create exact child pages for every source-bearing subrange listed above.
  - Apply formal C++ only to `CXX-01`, `CXX-04`, `CXX-05`, `CXX-06`, `CXX-10`, and `CXX-11`.
  - Keep raw setters, mouse handler, and paint child C++ blank under `NC-02`, `NC-03`, `NC-09`, and `NC-12`.
- Exact parent assignments recommended:
  - Parent [UID:0001GP]: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank C++.
  - Exact children: `CANONICAL_OWNER:0000CL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CL`, positions `40` through `49` before existing [UID:0001GQ] position `50`.
- Exact future work outside this assignment scope:
  - Whole-class declaration/header pass for [UID:0000CL].
  - Later `OnPaint` child-specific C++ pass after render/resource helper declarations are synchronized.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md`
- Exact report facts to incorporate:
  - Split-index disposition and parent no-code proof.
  - Full child inventory, including early raw setters and padding boundaries.
  - Current MCP session `80de0a67` evidence for function starts, raw non-function starts, xrefs, raw disassembly, pointer-byte negative checks, and OnPaint field/resource behavior.
  - Rename/correction rationale for `CanScroll` and `OnScrollTimer`.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - Recommended parent metadata after child creation: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank position, blank C++.
  - Recommended item summary: "Reviewed split index over ScrollNewGroupPane core methods and padding; exact child pages carry class ownership, C++ where ready, and no-code proofs for raw/no-route or large helper-dependent bodies."
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve:
  - Preserve old broad-emitter state as superseded.
  - Preserve no-xref/no-pointer evidence for raw starts.
  - Preserve rejected TextEditPane/generic ScrollBar owner routes.

## Recommended Support Doc Changes

- Support path: `by-class/ScrollNewGroupPane.md`
  - Exact report facts to incorporate: add exact core-child links once UIDs exist; add `+0xfa m_scrollStyleByte` inferred alias; update method table names from `CanResize` to `CanScroll` and from `OnSelectionChanged` to `OnScrollTimer`; state [UID:0001GP] is a non-emitting split index like [UID:0001GS].
  - Metadata/link/score/coverage/source-placement changes: keep current `85/86` unless implementation adds whole-class declaration-level evidence.
- Support path: `by-file/Group.md`
  - Exact report facts to incorporate: update `ScrollNewGroupPane` row to state core has been split into exact method children; keep source route to `NexusTK/social/Group.cpp`.
  - Metadata changes: none recommended.
- Support path: `by-memory/0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData.md`
  - Exact report facts to incorporate: rename slot prose to `CanScroll` and `OnScrollTimer` after child creation; add links to new child UIDs.
  - Metadata changes: none recommended.
- Support path: `by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md`
  - Exact report facts to incorporate: add concise item summary and note that `0x00624144` / `dword_624144` supplies the vertical fixed extent slice used by `ScrollNewGroupPane` `HitTestPart`, `GetPartRect`, and `OnPaint`.
  - Metadata changes: no score change required unless the implementation adds value bytes and xref detail beyond current support.

## Score And Metadata Recommendation

- Current score/metadata: [UID:0001GP] `85/88`, owner/emitter [UID:0000CL], reconstructable true, blank C++.
- Recommended score/metadata after accepted implementation: parent [UID:0001GP] `88/90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank C++.
- Score rationale and reason not higher/lower:
  - Higher than current because the report resolves the core score blocker by identifying exact children, raw setter bodies, padding, no-code proofs, and support-doc repairs.
  - Not higher than `88/90` because the parent remains an audit/split index, child UIDs will need validator registration, and `OnPaint` still lacks formal C++.
  - Not lower because MCP confirms function boundaries, xrefs, vtable slots, raw setter bodies, negative pointer evidence, and the class/file route.
- Score-improvement attempt:
  - Raw/no-function helper starts: investigated by `lookup_funcs`, `xrefs_to`, `find_bytes`, and raw `disasm`; resolved with exact child pages and no-code proofs.
  - Missing exact by-memory pages: resolved with implementation-ready child list.
  - Descriptive helper/source names: reanalyzed and replaced stale/weak names with stronger `CanScroll`, `OnScrollTimer`, `m_scrollStyleByte`, and explicit alias caveats.
  - Aggregate C++ risk: resolved by split-index conversion.
- Metadata fields to change or leave unchanged:
  - Parent becomes non-reconstructable split index.
  - Exact children inherit class owner/emitter route.

## Open Questions With Attempted Resolution

- Open question: Can parent [UID:0001GP] emit first-draft C++? Resolution: no. It is a multi-method aggregate with padding, not a source unit. Exact no-code proof provided.
- Open question: Are `0x005609b0` and `0x005609e0` real code or padding? Resolution: real raw method bodies. Disassembly proves compare/write/invalidate/return bodies; pointer/xref route is absent but that limits formal C++ only.
- Open question: What is `+0xfa`? Resolution: best current inference is `m_scrollStyleByte`, a class-local style/state byte initialized to `1` and changed by a raw invalidating setter. No current read was found, so formal child C++ remains blank and support docs should mark the name inferred.
- Open question: Should `0x00560cf0` be `CanResize`? Resolution: no; use `CanScroll`-style default false virtual because the slot/body matches the generic scrollbar false virtual.
- Open question: Should `0x00560d00` stay `OnSelectionChanged`? Resolution: no; use `OnScrollTimer`/`OnTimer` because the body checks timer id zero and reschedules the timer after `UpdateActiveInteraction`.
- Open question: Can `OnPaint` receive C++ now? Resolution: no for this report. It needs an exact child page and a render/resource helper signature pass; current report still records the field/resource/callee evidence and no-code proof rather than leaving it as uninvestigated.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. Do not edit manual `-coverage-report.md` files in this B-agent report-only phase.
- Do not write row text for validator-owned `auto-generated/-ag-*` reports. After supervisor implementation and validation, execute the report with the validator lifecycle command so `auto-generated/-ag-research-tracker.md` refreshes.

## Follow-Up Actions

- Supervisor actions: validate this report/checklist; if accepted, issue implementation callback to B005; after implementation, verify claim by claim and execute the report through validator.
- B005 implementation actions after callback: create/update target/support by-* docs under short leases, update this checklist, run scoped validators, and avoid coverage-report/generated/project-level edits.
- Future research actions: child-specific paint formal-C++ pass; whole-class declaration/header pass for `ScrollNewGroupPane`.

## Confidence

- Recommendation confidence: strong.
- Score confidence: strong for parent split-index score after implementation; medium-high for raw setter field-name spelling.
- Remaining uncertainty: exact original spelling of `+0xfa`, exact paint/helper declarations, and final whole-class header organization.

## Validator Results

- Commands run during implementation callback:

| File | Command | command_id | command_timestamp | Exit | ok |
| --- | --- | --- | --- | --- | --- |
| `by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md` | `python .\tools\validator.py --mode file --file by-memory\0x00560900-0x0056141f.ScrollNewGroupPaneCore.md --apply --queue-timeout 240` | `000000002929` | `2026-06-26T16:34:46-04:00` | `0` | `1` |
| `by-class/ScrollNewGroupPane.md` | `python .\tools\validator.py --mode file --file by-class\ScrollNewGroupPane.md --apply --queue-timeout 240` | `000000002930` | `2026-06-26T16:34:47-04:00` | `0` | `1` |
| `by-file/Group.md` | `python .\tools\validator.py --mode file --file by-file\Group.md --apply --queue-timeout 240` | `000000002931` | `2026-06-26T16:34:49-04:00` | `0` | `1` |
| `by-memory/0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData.md` | `python .\tools\validator.py --mode file --file by-memory\0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData.md --apply --queue-timeout 240` | `000000002932` | `2026-06-26T16:34:51-04:00` | `0` | `1` |
| `by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md` | `python .\tools\validator.py --mode file --file by-memory\0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md --apply --queue-timeout 240` | `000000002933` | `2026-06-26T16:34:52-04:00` | `0` | `1` |
| `by-memory/0x00560900-0x005609a1.ScrollNewGroupPaneConstructor.md` | same validator pattern | `000000002936` | `2026-06-26T16:36:40-04:00` | `0` | `1` |
| `by-memory/0x005609b0-0x005609d7.ScrollNewGroupPaneSkinIndexSetterRaw.md` | same validator pattern | `000000002937` | `2026-06-26T16:36:41-04:00` | `0` | `1` |
| `by-memory/0x005609e0-0x00560a04.ScrollNewGroupPaneStyleByteSetterRaw.md` | same validator pattern | `000000002938` | `2026-06-26T16:36:43-04:00` | `0` | `1` |
| `by-memory/0x00560a10-0x00560a6b.ScrollNewGroupPaneSetMaxRange.md` | same validator pattern | `000000002939` | `2026-06-26T16:36:54-04:00` | `0` | `1` |
| `by-memory/0x00560a70-0x00560a97.ScrollNewGroupPaneSetScrollPosition.md` | same validator pattern | `000000002940` | `2026-06-26T16:37:05-04:00` | `0` | `1` |
| `by-memory/0x00560aa0-0x00560aba.ScrollNewGroupPaneShow.md` | same validator pattern | `000000002941` | `2026-06-26T16:37:16-04:00` | `0` | `1` |
| `by-memory/0x00560b00-0x00560ce1.ScrollNewGroupPaneHandleMouseEvent.md` | same validator pattern | `000000002942` | `2026-06-26T16:37:27-04:00` | `0` | `1` |
| `by-memory/0x00560cf0-0x00560cf5.ScrollNewGroupPaneCanScroll.md` | same validator pattern | `000000002943` | `2026-06-26T16:37:38-04:00` | `0` | `1` |
| `by-memory/0x00560d00-0x00560d33.ScrollNewGroupPaneOnScrollTimer.md` | same validator pattern | `000000002944` | `2026-06-26T16:37:49-04:00` | `0` | `1` |
| `by-memory/0x00560d40-0x00561420.ScrollNewGroupPaneOnPaint.md` | same validator pattern | `000000002945` | `2026-06-26T16:38:00-04:00` | `0` | `1` |

- Initial child-page UID registration pass assigned [UID:00044X] through [UID:000456] with validator commands `000000002881`, `000000002883`, `000000002885` through `000000002888`, and `000000002891` through `000000002894`; the stable-UID revalidation table above is the final validator result set for the created files.
- Generated refresh state: file validators reported `generated_refresh: deferred`; queue status command `000000002949` at `2026-06-26T16:38:41-04:00` reported zero queued/processing generated refresh jobs. `auto-generated/NexusTK/social/Group.cpp` and `auto-generated/-ag-coverage-report-by-memory.md` both have `validator-command-id: 000000002945` / `validator-refreshed-at: 2026-06-26T16:38:00-04:00`, and generated `Group.cpp` contains emitted blocks for [UID:00044X], [UID:000450], [UID:000451], [UID:000452], [UID:000454], and [UID:000455].
- Any unresolved validator warnings/errors: `by-file/Group.md` validator command `000000002931` still reports pre-existing unrelated diagnostics for [UID:00023W] stale target path `by-memory/0x0056c4a0-0x0056c4b5.GroupPaneFalseVirtualStubs.md` and [UID:0003XA] not present in `validator.ini`. The actual current files exist as `by-memory/0x0056c4a0-0x0056c4b5.LegendPaneFalseVirtualStubs.md` and `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md`. No manual validator-state repair was attempted because those diagnostics are outside this accepted B005 callback.

## Changed Files

- Created:
  - `by-memory/0x00560900-0x005609a1.ScrollNewGroupPaneConstructor.md` ([UID:00044X])
  - `by-memory/0x005609b0-0x005609d7.ScrollNewGroupPaneSkinIndexSetterRaw.md` ([UID:00044Y])
  - `by-memory/0x005609e0-0x00560a04.ScrollNewGroupPaneStyleByteSetterRaw.md` ([UID:00044Z])
  - `by-memory/0x00560a10-0x00560a6b.ScrollNewGroupPaneSetMaxRange.md` ([UID:000450])
  - `by-memory/0x00560a70-0x00560a97.ScrollNewGroupPaneSetScrollPosition.md` ([UID:000451])
  - `by-memory/0x00560aa0-0x00560aba.ScrollNewGroupPaneShow.md` ([UID:000452])
  - `by-memory/0x00560b00-0x00560ce1.ScrollNewGroupPaneHandleMouseEvent.md` ([UID:000453])
  - `by-memory/0x00560cf0-0x00560cf5.ScrollNewGroupPaneCanScroll.md` ([UID:000454])
  - `by-memory/0x00560d00-0x00560d33.ScrollNewGroupPaneOnScrollTimer.md` ([UID:000455])
  - `by-memory/0x00560d40-0x00561420.ScrollNewGroupPaneOnPaint.md` ([UID:000456])
- Modified:
  - `by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md`
  - `by-class/ScrollNewGroupPane.md`
  - `by-file/Group.md`
  - `by-memory/0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData.md`
  - `by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md`
  - `tools/leaser/Agents/Agent-B005/research/0001GP-ScrollNewGroupPaneCore-source-quality.md`
- Validator-generated side effects: `tools/validator.ini`, `project-level/-auto-completion-stats.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/NexusTK/social/Group.cpp` were updated by validator/autogen, not by manual edits.
- Renamed: none.
- Report execution: leave blank during the B-agent pass. The supervisor runs `tools/validator.py execute_report ... --apply` after verification.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation. Proof: `goal.md` contains the supervisor-accepted implementation callback override for this report.
- [x] Target/support docs to update: `by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md`, `by-class/ScrollNewGroupPane.md`, `by-file/Group.md`, `by-memory/0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData.md`, and `by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md`. Proof: all five were updated and validated in commands `000000002929` through `000000002933`.
- [x] Current target state and actual evidence checked recorded: MCP session `80de0a67`, function inventory, raw setter disassembly, xrefs, pointer-byte searches, paint disassembly filter, support docs, and accepted reports. Proof: parent split index and child pages preserve these evidence facts; parent validated under command `000000002929`.
- [x] Metadata/score changes to apply: convert [UID:0001GP] to `88/90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/position/C++. Proof: parent metadata updated and validator command `000000002929` recorded completion/confidence, owner `NONE`, and autogen registry `true -> false` with blank emitter fields.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or exact evidence-backed no-improvement proof: raw starts, missing exact child pages, stale names, aggregate C++ risk, `+0xfa`, `CanResize`, `OnSelectionChanged`, and `OnPaint`. Proof: exact child pages [UID:00044X] through [UID:000456] now exist; class/vtable docs record `m_scrollStyleByte`, `CanScroll`, and `OnScrollTimer`; `OnPaint` child carries `NC-12`.
- [x] Owner/emitter/reconstructable changes to apply: exact children get [UID:0000CL] owner/emitter; parent becomes non-emitting split index. Proof: child validators `000000002936` through `000000002945` returned `ok:1` and children carry owner/emitter [UID:0000CL]; parent validator `000000002929` returned `ok:1` with parent non-emitting metadata.
- [x] Split/rename/new-child changes to apply: create exact child pages for constructor, raw setters, range setter, position setter, show helper, mouse method, false virtual, timer callback, and paint method. Proof: created [UID:00044X], [UID:00044Y], [UID:00044Z], [UID:000450], [UID:000451], [UID:000452], [UID:000453], [UID:000454], [UID:000455], and [UID:000456].
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: source route through [UID:0000CL] -> [UID:0000JS]; padding rows preserved; no IDA DB edits. Proof: parent split table preserves padding rows; class/file docs keep the [UID:0000CL] -> [UID:0000JS] route; no IDA DB edits were made.
- [x] First-draft C++ or no-code proof to apply: insert `CXX-01`, `CXX-04`, `CXX-05`, `CXX-06`, `CXX-10`, and `CXX-11` on exact children; apply `NC-02`, `NC-03`, `NC-09`, and `NC-12` blank-C++ proofs. Proof: [UID:00044X], [UID:000450], [UID:000451], [UID:000452], [UID:000454], and [UID:000455] contain formal C++; [UID:00044Y], [UID:00044Z], [UID:000453], and [UID:000456] contain no-code proofs with blank C++.
- [x] Exact target/support doc facts to incorporate at report-level detail: child inventory, disassembly facts, xrefs, field aliases, vtable slot names, owner/source-route reasoning, and rejected alternatives. Proof: parent, child pages, class page, `Group.md`, vtable data page, and constants page all updated with stable UID links and report-level facts.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: broad parent emitter state, stale `CanResize`/`OnSelectionChanged`, generated TextEditPane pollution, generic ScrollBar owner rejection, and raw no-route evidence. Proof: parent change log records the superseded broad-emitter state; class/vtable docs mark stale names as superseded; raw children preserve no-xref/no-pointer evidence; mouse/paint children reject generic owner routes.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: support docs mention recovered/simroot/generator ownership; treat as lead/stale where contradicted. Proof: class/file docs preserve generated `TextEditPane` pollution as data debt, not source ownership.
- [x] Open questions to close or document as evidence-backed unresolved: `+0xfa` name, OnPaint helper declarations, and whole-class header split. Proof: `+0xfa` documented as inferred `m_scrollStyleByte`; [UID:000456] carries the paint helper-signature no-code proof; class page keeps whole-class declaration/header audit as unresolved.
- [x] Validators to run after implementation: scoped file validation for every changed/created by-* page using `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`. Proof: all fifteen changed/created by-* docs validated with exit `0`; final child commands `000000002936` through `000000002945` and support commands `000000002929` through `000000002933` returned `ok:1`.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: no manual coverage text; execute-report/autogen refresh should update generated research tracker. Proof: no manual `-coverage-report.md` or generated report was edited by hand; generated refresh queue cleared at `000000002949`, and generated headers for `auto-generated/NexusTK/social/Group.cpp` and `auto-generated/-ag-coverage-report-by-memory.md` show command `000000002945`.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation. Proof: current `goal.md` supervisor callback override names this report and assignment id.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: parent, ten child pages, class page, Group file route, vtable data, and constants support page were updated; details are listed in `Changed Files` above.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason. Proof: parent became `88/90` non-emitting; children carry owner/emitter [UID:0000CL] and positions `40` through `49`; C++/no-code dispositions are applied on exact children.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: superseded broad parent emitter, stale `CanResize`/`OnSelectionChanged`, generated `TextEditPane` pollution, generic `ScrollBar` owner rejection, raw no-xref/no-pointer evidence, and paint no-code proof remain in target/support docs.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: `+0xfa` documented as inferred `m_scrollStyleByte`; `OnPaint` and `HandleMouseEvent` no-code proofs document helper/signature blockers; whole-class header split remains explicit future work.
- [x] Validators run and results recorded. Proof: `Validator Results` table above records command ids/timestamps/exits/ok counts.
- [x] Generated report refresh completed by validator or explicit manual supervisor-owned coverage/tracker text supplied/confirmed unchanged. Proof: queue status `000000002949` reported zero queued/processing generated refresh jobs; generated headers show command `000000002945`; no manual coverage/tracker text was required.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: no accepted item remains unapplied. The only reported residuals are unrelated pre-existing `Group.md` validator diagnostics for [UID:00023W]/[UID:0003XA], outside this callback and not edited by hand.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0001GP-ScrollNewGroupPaneCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0001GP-ScrollNewGroupPaneCore-source-quality.md","timestamp":"2026-06-26T16:43:19","uid":"0001GP"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
