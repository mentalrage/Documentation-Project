** TARGET-REPORT-UID:000126 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID000126 ScrollableControlPaneScalarDeletingDestructor Ownership / Split Research


## Finalized Report / Current Recommendation

- Applied recommendation: [UID:000126] is exact, non-reconstructable, non-emitting MSVC scalar-deleting-destructor ABI evidence. Its semantic class remains `ScrollableControlPane`, but it owns and emits no handwritten source.
- Final target disposition: UID000126 is `92/94`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, with blank emitter, position, and formal C++ fields and `Nested:-8`.
- Complete source resolution: UID00011G is the exact non-emitting split index for the constructor/core range; 15 exact source-bearing method children UID0004KC through UID0004KQ cover every human body in `0x004985a0-0x004988cd`; compiler-only UID0004KR covers `0x0049afd7-0x0049afed`; and UID0002PE is renamed to its machine-proven `HitTestPart(int, int)` role. No core source body is deferred.
- Class source resolution: UID0000CE contains the complete compilable `ScrollableControlPane : public ControlPane` declaration, all emitted method declarations, the owned `ScrollablePane *m_scrollablePane` member, and `[[CHILDREN]]`.
- Source route: UID0000CE owns the class declaration and all 16 human method pages, emitted through UID0000NE in positions `10` through `170`. UID000126, UID00011G, and UID0004KR emit nothing.
- Confidence: very strong. Evidence-time MCP database `328356ab`, exact bytes, vtable slots, xrefs, all 26 constructor callers, raw method bodies, sibling implementations, and current project contracts independently agree.
- Current artifact state: the accepted implementation callback is complete. B001 applied every C126-001 through C126-045 disposition, released every lease, completed all scoped validations and waited generated verification, and has no remaining implementation work. Report validation, execution, count, path transition, move, and archive state are external supervisor/validator-owned; B001 ran no execute_report, lifecycle, move, or archive command.

## Supporting Research

- Fresh streamable-MCP discovery returned exactly one adopted NexusTK database, `328356ab`, for `NexusTK.exe.i64`; evidence-time `server_health` was `ok` with auto-analysis, Hex-Rays, and strings ready.
- All IDB-backed calls used `database:'328356ab'`. Fresh lookup, disassembly, decompile, byte, xref, vtable, caller, and neighboring-boundary checks succeeded. One broad whole-text search exceeded its 60-second client limit; immediate health and focused calls succeeded, so no binary conclusion relies on that oversized query.
- Current project docs and generated source were re-read. The historical B002 UID00011G work was used only as a lead; its unresolved field names, old three-accessor interpretation, and aggregate source deferral were independently retested and corrected.
- Historical pre-callback generated `NexusTK/ui/controls/ScrollableControlPane.cpp` had validator command `000000009301`, refresh timestamp `2026-07-13T05:41:02-04:00`, and four Empty Emitter Markers for UID0000CE, UID00011G, UID000126, and UID0002PE.
- Callback-generated `NexusTK/ui/controls/ScrollableControlPane.cpp` now records validator command `000000009346`, refresh timestamp `2026-07-13T06:35:17-04:00`, and filesystem write time `2026-07-13T06:35:27.5247800-04:00`. The class and all 16 source bodies occur once; stale markers and compiler-only bodies occur zero times.
- The assignment's pre-report queue count was a historical dispatch fact only. Any report count, validation, execution, path transition, move, or archive state is external supervisor/validator-owned and is not asserted by this artifact.
- No Wave2/Wave3 artifact was used as proof. Stale generated/export summaries were ignored where current IDA and by-* evidence existed.

## Target

- Target UID: `000126`.
- Target path: `by-memory/0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor.md`.
- Exact range: `0x0049b4f0-0x0049b557`, size `0x67`.
- Assignment trigger: reconstructable, uncovered, and an Empty Emitter Marker in generated `ScrollableControlPane.cpp` at assignment time.
- Historical pre-callback target state: `86/90`, owner/emitter UID0000CE, reconstructable true, blank position, and blank formal C++.
- Related source blockers resolved by this report: complete class declaration, all UID00011G source bodies, exact ordinary destructor, exact adjustors, and UID0002PE's AL-sized/two-argument source signature.

## Current Target State

- Historical target metadata incorrectly routed compiler ABI output to `ScrollableControlPane`, creating a generated Empty Emitter Marker.
- Historical target prose preserved substantial scalar-wrapper evidence but mixed source-authored destructor semantics with compiler-generated deleting flags, vptr stores, base teardown, deallocation, and adjustor routes; the callback historicalized that wording.
- The exact human destructor body exists separately at raw range `0x00498660-0x00498695`: it deletes the owned child once. UID000126 repeats that cleanup inside compiler-generated scalar-deleting machinery and is not the source destination.
- The owned field at object offset `+0x108` is a separately allocated polymorphic `ScrollablePane *`, source-facing name `m_scrollablePane`; it is not an embedded control.
- The base teardown target `0x00544580` is `Pane::~Pane()` ordinary teardown reached implicitly through the `ControlPane` base. It is not a TextButtonEx base and must not be explicitly called in human source.
- UID00011G now indexes constructor, forwarding, event, state, layer, and paint children at the corrected half-open end `0x004988cd`; it is deliberately non-emitting and produces no aggregate marker.
- UID0002PE now names `ScrollableControlPaneHitTestPart`; direct `mov al,0x12; retn 8`, shared vtable slot `+0x60`, sibling bodies, and a caller prove `unsigned char HitTestPart(int x, int y)`.
- B001 research, implementation, scoped validation, and generated verification are complete. External lifecycle state is not claimed here.

## Executive Recommendation

- Source ownership remains under UID0000CE `ScrollableControlPane`, emitted through UID0000NE `NexusTK/ui/controls/ScrollableControlPane.cpp`.
- UID0000CE is `92/94`, retains owner/emitter UID0000NE and reconstructable true, uses position `10`, and contains the complete managed class declaration.
- Validator-aware rename preserved UID00011G at `by-memory/0x004985a0-0x004988cd.ScrollableControlPaneCore.md`; it is `92/94`, owner NONE, reconstructable false, with blank emitter/position/formal C++ and `Nested:0`, and is a split index rather than an aggregate source emitter.
- Fifteen source children were validator-registered serially as UID0004KC through UID0004KQ. All are owner/emitter UID0000CE, reconstructable true, `Nested:0`, with their accepted positions and managed blocks.
- UID0004KR is the validator-registered `by-memory/0x0049afd7-0x0049afed.ScrollableControlPaneAdjustorThunks.md` at `90/94`, owner NONE, reconstructable false, blank emitter/position/formal C++, and `Nested:-8`.
- UID000126 is `92/94`, owner NONE, reconstructable false, with blank emitter/position/formal C++ and `Nested:-8`.
- Validator-aware rename preserved UID0002PE at `by-memory/0x0049b900-0x0049b905.ScrollableControlPaneHitTestPart.md`; it is `92/94`, retains owner/emitter UID0000CE and reconstructable true, uses position `170`, and contains the exact two-argument byte-return body.
- UID0000NE is `91/93` and documents the complete source order. ScrollablePane support has the exact additive evidence without ownership/emission changes.
- No owner, source, split, signature, score, C++, validation, generated-output, or lease blocker remains.

## Supervisor Active Recheck

- Gate 1 defect 1 is closed: UID0000CE now has a complete class declaration, not a route comment. It declares the base, constructor, virtual destructor, all source children, `HitTestPart(int, int)`, and `m_scrollablePane`, followed by `[[CHILDREN]]`.
- Gate 1 defect 2 is closed: every source-bearing body in UID00011G has an exact range, disposition, destination filename, score, owner/emitter state, source position, and formal managed block. UID00011G itself is a non-emitting split index. Nothing is deferred to broader future splitting.
- Gate 1 defect 3 is closed: UID0002PE is mapped from `AL` plus `retn 8` to `unsigned char HitTestPart(int x, int y)`, corroborated by the same `+0x60` slot in ControlPane/SliderControlPane and a caller that passes two coordinates and consumes `AL`.
- Preserved accepted-in-isolation evidence: UID000126 compiler disposition, ordinary destructor body, adjustor ranges, owned child, delete symmetry, Pane teardown, vtables, xrefs, caller breadth, size, padding, neighboring fences, and negative evidence.
- The callback registered each new page one at a time and captured real UIDs UID0004KC through UID0004KR before inserting links; no UID was fabricated.

## Inference Research Guidance Check

- `by-structure.md` discipline was applied by separating semantic class context, exact human source methods, compiler wrappers, adjustors, and padding.
- Existing assumptions treated as uncertain and retested: embedded child, generic scroll-control type, old three-accessor names, no-argument type id, TextButtonEx base identity, source-authored scalar wrapper, and aggregate core emission.
- Direct IDA facts control ranges, calling convention, return width, vtable slots, xrefs, tail-call argument preservation, field offsets, and padding.
- Current documentation contracts control source names where binary behavior is exact but symbols are stripped: `SetScrollTargetValue`, `SetScrollCurrentValue`, `GetScrollMax`, `GetScrollPosition`, EventHandler method names, `Pane::AddToLayer`, and `HitTestPart`.
- Inference is limited to descriptive private member/field spelling and original header formatting. Every runtime behavior, signature ABI, source placement, and compiler disposition is resolved.
- Wave2/Wave3 material was not used.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis | Evidence | Result |
| --- | --- | --- | --- |
| `+0x108` type/name | Constructor callers pass differently sized `ScrollablePane` derivatives; all forwarding enters canonical ScrollablePane methods. | constructor, 44 refs/26 callers, child vtables, UID0000CF/UID0001GL | `ScrollablePane *m_scrollablePane` |
| Ownership | Constructor stores an externally allocated child; ordinary and scalar destruction invoke child vslot 0 with deleting flag 1. | caller allocations, ctor store, raw destructor, scalar wrapper | exclusive ownership transfer and one source `delete` |
| Constructor arguments | All 44 calls pass argument 4 and 5 as zero; the last is usually zero but sometimes 13 or 10. ScrollablePane `+0x100/+0x104/+0x108` uses prove horizontal offset, vertical offset, and common inset. | all 26 caller decompiles; `0x0055e660`, `0x0055ec00`, `0x0055ee10`, `0x0055f250` | descriptive names `horizontalScrollBarOffset`, `verticalScrollBarOffset`, `scrollBarInset` |
| Ordinary destructor | Raw body restores class vptrs, virtually deletes `+0x108`, and tail-jumps to Pane teardown. | bytes `0x00498660-0x00498695`, exact fences, scalar parity | exact source destructor child |
| Zero raw-start xref | No xref reaches the ordinary body or four tiny delegates, but each range is complete, source-shaped, correctly fenced, and coherent with the class family. | xrefs, bytes, wrapper targets, sibling routes | retain as exact human source children; preserve zero-route confidence cap |
| Base name | `0x00544580` installs Pane vtables and performs Pane teardown; ControlPane adds no separate nontrivial cleanup. | decompile, 303 family xrefs, UID0001EA | implicit base destruction; no explicit source call |
| Scalar target | Vptr stores, child delete, base call, deleting flags, deallocator, guarded size, return-this ABI, and adjustor routes are compiler output. | UID000126 disasm/decompile, Rectangle comparator | owner NONE, false, no emitter |
| Adjustors | Bodies are only `sub ecx,0xa0/0xa4` and tail jumps to UID000126. | bytes, disasm, one vtable ref each | exact non-emitting compiler child |
| Four raw delegates | Each loads `[ecx+0x108]` and tail-jumps to one ScrollablePane helper while preserving caller stack arguments. | `0x004986a0-0x004986df`, helper disassembly/docs | four exact delegating source methods, not aggregate comments |
| Update region | Base call receives `bounds`; tail jump to child vslot `+0x0c` retains the same stack argument that Hex-Rays omitted. | `0x004986e0-0x004986fb` disassembly | base then child `UpdateRenderRegion(bounds)` |
| Three old accessors | Entries use the secondary EventHandler subobject and child secondary-vtable slots `+4`, `+8`, `+0x10`; they forward an `Event *`, not scroll metrics. | complete-object adjustment, tables `0x006180c4+`, EventHandler contract | pointer/mouse, key/text, and packet event delegates |
| Enable/Disable | Each toggles inherited `m_controlVisible` only when changed and invalidates `m_bounds`. Incidental Hex-Rays return is not source. | disassembly plus ControlPane contract | two exact `void` virtual bodies |
| AddToLayer | Calls Pane base, normalizes a local bounds copy, updates base/child render regions, resets the copy, then adds child at order zero after `this`. | full `0x004987a0-0x0049885c` disassembly; accepted helper contracts | exact source body with duplicate local reset preserved |
| RemoveFromLayer | Child removal precedes Pane base removal. Incidental Hex-Rays byte return is not source. | `0x00498860-0x00498876` | exact `void` source body |
| OnPaint | Returns without drawing when EPF assets are selected; otherwise fills, then frames only when visible and active. | `0x00498880-0x004988cd`, global and GrafPort contracts | exact source body, no decompiler return |
| UID0002PE return/args | `mov al,12h` proves byte return; `retn 8` proves two four-byte stack args. Same primary slot `+0x60` in ControlPane/Slider and caller coordinate flow prove hit testing. | direct bytes, vtables, `0x0041d690`, `0x00496800`, caller `0x00497c60` | `unsigned char HitTestPart(int x, int y)` returning 18 |
| Class emitter | A route comment cannot compile emitted method definitions. | current generated marker and source dependencies | complete class declaration managed block |
| Core emitter | An aggregate comment neither reconstructs methods nor removes blockers. | complete function inventory | UID00011G becomes blank non-emitting split index |
| Core endpoint | Final OnPaint source ends at `0x004988cd`; `0x004988cd-0x004988d0` is padding and TextEdit starts at `0x004988d0`. | bytes and next raw constructor | validator-aware filename end correction to `0x004988cd` |
| Original private spelling | Symbols do not survive, but selected names describe independently proven roles and avoid the distinct `ScrollPane` class. | all uses and project naming | confidence cap only, not blocker |

Rejected alternatives:

- `ScrollPane *m_scrollPane`, `Pane *m_childPane`, or an embedded object: rejected by polymorphic caller allocations, canonical ScrollablePane destinations, pointer storage, and virtual deletion.
- Source-authored scalar deleting wrapper or adjustors: rejected because their unique operations are MSVC ABI mechanics.
- Comment-only class/core routes: rejected because they leave generated source uncompilable and source bodies unresolved.
- Treat four raw delegates as compiler adjustors: rejected because they preserve declared source arguments, call distinct semantic helpers, and do not adjust a base-subobject `this` into another implementation.
- Preserve the old three-accessor interpretation at `0x00498700/20/40`: rejected by secondary EventHandler vtable slots and the preserved `Event *` argument.
- Emit no-argument `int GetControlType()`: rejected by both return width and callee-popped argument bytes.
- Explicitly write vptr stores, deleting flags, Pane destructor calls, deallocation, or guard logic: rejected as compiler/runtime mechanics.
- Create a separate translation unit or a new vtable child: rejected because UID0000NE and the existing read-only aggregate already provide the correct routes.

No source, score, signature, owner, emitter, range, split, or compiler/source blocker remains unresolved.

## Evidence Standards Used

- Evidence types: fresh MCP discovery/health, `lookup_funcs`, `decompile`, `disasm`, `xrefs_to`, `get_bytes`, globals/vtables, exhaustive constructor callers, sibling slot implementations, current by-* docs, generated source, and negative xref/boundary checks.
- Evidence ladder: direct machine facts control ABI and ranges; repeated vtable/caller contracts control source signatures; current accepted project names control human spelling; decompiler output never overrides stack cleanup or byte-return facts.
- Strength: constructor, destructor, wrapper, vtable, caller, and source-family evidence converge independently. Only original private spelling is not symbol-proven.
- Tool limitations: raw bodies without IDA function objects were analyzed from exact bytes, disassembly, control flow, boundaries, and destinations. One oversized text query timed out, but all focused evidence calls and immediate health checks succeeded.

## Evidence Checked

- IDA MCP checks:
  - fresh `idb_list` and `server_health` for database `328356ab`;
  - lookup/disassembly/decompile/bytes for `0x004985a0-0x004988d0`, `0x0049afd7-0x0049afed`, UID000126, UID0002PE, Pane teardown, ScrollablePane helper destinations, sibling slot implementations, and caller `0x00497c60`;
  - xrefs to constructor, raw ordinary destructor, all four raw delegates, vtable-routed methods, adjustors, scalar wrapper, UID0002PE, and Pane teardown;
  - exact bytes for every internal alignment span and target fences;
  - decorated globals and exact vtable island `0x00618058-0x006180fc`.
- Constructor/caller checks:
  - 44 constructor refs from 26 unique caller functions;
  - wrapper allocation size `0x10c` and polymorphic child allocations of multiple sizes/types;
  - every call's three trailing integer values, including the only nonzero 13/10 inset values.
- Source-contract checks:
  - UID0000CF/UID0001GL ScrollablePane behavior and helper names;
  - UID000038/UID0001EA Pane/ControlPane inheritance and teardown;
  - EventHandler method names and secondary slot order;
  - accepted Pane/GrafPort/RectBounds helper signatures;
  - SliderControlPane `HitTestPart` and the shared `+0x60` slot ABI;
  - operator delete and immediate Rectangle/PopupMenu destructor precedents.
- Negative checks:
  - zero xrefs to raw ordinary start and four raw delegate starts;
  - no ordinary direct caller to UID000126 beyond two adjustor jumps and primary-vtable data;
  - no source-specific scalar behavior beyond member deletion;
  - no EventHandler `HandleImeEvent` override in the UID00011G range;
  - no neighboring Rectangle, TextEdit, or SimpleHelp code included;
  - at research time, no exact child pages existed for the then-proposed splits.
- Failed/unavailable checks: no required check failed. The one broad search timeout was replaced by successful focused calls and does not affect evidence completeness.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C126-001 | Evidence-time IDB `328356ab` was healthy with analysis/Hex-Rays/strings ready. | very strong | idb_list, server_health | report; target Evidence | record | applied and verified |
| C126-002 | UID000126 is exact `0x0049b4f0-0x0049b557`, size `0x67`, fenced by 11/9-byte pads. | very strong | lookup, bytes | target; ignored | correct/incorporate | applied; target and ignored scoped-validated |
| C126-003 | ScrollableControlPane has primary/secondary/tertiary vtables at `0x0061805c`, `0x006180c4`, `0x006180f4`. | very strong | globals, bytes, stores | target/class/core/read-only aggregate | incorporate | applied; all four destinations scoped-validated |
| C126-004 | UID000126 has only two adjustor code refs and one primary-vtable data ref. | very strong | xrefs count 3 | target/adjustor/index | incorporate | applied; UID000126, UID0004KR, and UID00011Y scoped-validated |
| C126-005 | Object `+0x108` is owned `ScrollablePane *m_scrollablePane`. | strong | ctor/callers/delegates/destructors | class/core/file/source children | replace provisional wording | applied across class, core, file, and children |
| C126-006 | Ownership transfers into the constructor and source destruction deletes the child exactly once. | very strong | caller allocations, ctor store, raw/scalar cleanup | target/class/file/destructor | incorporate | applied; generated destructor occurs once |
| C126-007 | Complete wrapper size is `0x10c`. | very strong | allocations, flag-4 size path | target/class/core/file | incorporate | applied and scoped-validated |
| C126-008 | Ordinary destructor is exact `0x00498660-0x00498695`, source-shaped, and fenced. | very strong | bytes/control flow | UID0004KD/core/target | split/incorporate | applied; UID0004KD registered and validated |
| C126-009 | Ordinary human body is only `delete m_scrollablePane`; base teardown is implicit. | very strong | raw body, Pane chain | UID0004KD/class/target | emit once | applied; generated body occurs once |
| C126-010 | `0x00544580` is Pane ordinary teardown, not TextButtonEx. | very strong | vptrs/decompile/family xrefs | target/class/core/destructor | correct stale text | applied and historicalized |
| C126-011 | UID000126 is MSVC scalar-deleting compiler output and must emit no source. | very strong | flags/vptrs/deallocator/size/adjustors | target/index/generated expectations | reclassify | applied; generated scalar count zero |
| C126-012 | Adjustors are exact `0x0049afd7-0x0049afed`, compiler-only, and non-emitting. | very strong | bytes/disasm/xrefs | UID0004KR/index/ignored | create/reclassify | applied; UID0004KR registered and validated |
| C126-013 | Target and adjustor use `Nested:-8`; all source children and core index use `Nested:0`. | strong | local nesting convention | metadata | apply | applied and scoped-validated |
| C126-014 | Vtable island is exact `0x00618058-0x006180fc`, with 25/11/2 slots and TextEdit successor. | very strong | globals/bytes | read-only aggregate/class/target | incorporate | applied and scoped-validated |
| C126-015 | Constructor has 44 refs from 26 unique callers and broad generic-wrapper use. | very strong | xrefs/caller decompiles | core/class/file | incorporate | applied and scoped-validated |
| C126-016 | All ctor calls pass zero for horizontal/vertical offsets; final inset is zero except supported 13/10 cases. | very strong | all caller decompiles | UID0004KC/core/ScrollablePane support | incorporate | applied and scoped-validated |
| C126-017 | ScrollablePane `+0x100/+0x104/+0x108` are horizontal offset, vertical offset, and common inset. | strong | helper/layout uses | ScrollablePane class/core; ctor | add support | applied without support score/route changes |
| C126-018 | UID0000CE must be a complete compilable class declaration at `92/94`, position 10. | very strong | generated dependency and full inventory | UID0000CE | replace comment-only block | applied; scoped-validated and generated once |
| C126-019 | UID00011G must preserve UID, rename to exact end `0x004988cd`, become `92/94`, NONE/false/blank, and index every child. | very strong | exact range/inventory | UID00011G and reverse refs | rename/reclassify/index | applied; validator path update preserved UID and links |
| C126-020 | Constructor child is exact `0x004985a0-0x00498656`, `92/94`, position 20, with exact source. | very strong | decompile/callers/fields | UID0004KC | create/register/emit | applied; registered and generated once |
| C126-021 | Destructor child is exact `0x00498660-0x00498695`, `91/94`, position 30. | very strong | bytes/source cause | UID0004KD | create/register/emit | applied; registered and generated once |
| C126-022 | Four raw delegates at `0x004986a0-0x004986df` are exact source children at positions 40/50/60/70. | strong | bytes/tail destinations/args | UID0004KE/4KF/4KG/4KH | create/register/emit | applied; all registered, validated, and generated once |
| C126-023 | UpdateRenderRegion is exact `0x004986e0-0x004986fb`, `92/94`, position 80, base then child with same bounds. | very strong | disasm/stack preservation | UID0004KI | create/register/emit | applied; registered and generated once |
| C126-024 | `0x00498700`, `0x00498720`, and `0x00498740` are EventHandler delegates, not scroll accessors. | very strong | secondary vtable slots/Event* flow | UID0004KJ/4KK/4KL; core/class | correct/split/emit | applied; all registered, validated, and generated once |
| C126-025 | Enable/Disable are exact source children at positions 120/130. | very strong | disasm/base fields | UID0004KM/4KN | create/register/emit | applied; both registered, validated, and generated once |
| C126-026 | AddToLayer is exact `0x004987a0-0x0049885c`, position 140, preserving base call, two local resets, render updates, and child insertion. | very strong | full disasm/helper contracts | UID0004KO | create/register/emit | applied; registered and generated once |
| C126-027 | RemoveFromLayer is exact `0x00498860-0x00498876`, position 150, child first then base. | very strong | disasm | UID0004KP | create/register/emit | applied; registered and generated once |
| C126-028 | OnPaint is exact `0x00498880-0x004988cd`, position 160, with EPF suppression, fill, and visible-active frame. | very strong | disasm/global/helper contracts | UID0004KQ | create/register/emit | applied; registered and generated once |
| C126-029 | UID0002PE is `unsigned char HitTestPart(int x, int y)`, not no-arg `int GetControlType`. | very strong | `mov al,12h; retn8`, same slot/caller | UID0002PE/class/core/file | rename/correct/emit | applied; old generated name count zero |
| C126-030 | UID0002PE becomes `92/94`, position 170, retaining UID0000CE owner/emitter/true. | strong | complete signature/body/route | UID0002PE | apply metadata | applied; scoped-validated and generated once |
| C126-031 | UID0000NE becomes `91/93` and records exact 17-block source order. | strong | complete source plan | UID0000NE | update | applied; scoped-validated and waited refresh complete |
| C126-032 | UID00011Y links the real adjustor/target/ordinary relations after UID registration without score inflation. | strong | compiler-family index | UID00011Y | update links/evidence | applied; UID0004KR/UID0004KD links validated |
| C126-033 | Register 15 exact internal core pads, two target pads, and the adjustor range in `-ignored`. | very strong | exact byte reads | `by-memory/-ignored.md` | add exact rows | applied with real UIDs; scoped-validated |
| C126-034 | Read-only aggregate records Scrollable vtable range/slots/HitTest slot/adjustors without a new data child. | very strong | globals/bytes | UID000252 | add evidence only | applied without metadata change; scoped-validated |
| C126-035 | ScrollablePane support records three field roles and four helper contracts without ownership/emitter/score changes. | strong | helper bodies/current docs | UID0000CF/UID0001GL | add support only | applied without ownership/emitter/score changes |
| C126-036 | Current EventHandler, Pane, ControlPane, GrafPort, RectBounds, Surface, and operator-delete support is already same-or-greater. | strong | current docs | no-edit support set | preserve | verified same-or-greater; no edits made |
| C126-037 | Whole-report source insertion count is exactly 17 managed blocks: class plus 15 core children plus UID0002PE. | mandatory | complete source inventory | report/all destinations | apply exactly | applied; report and destination counts remain exactly 17 |
| C126-038 | UID000126, UID00011G, and adjustor child have blank formal C++ and create no Empty Emitter Marker. | very strong | compiler/index dispositions | target/core/adjustor/generated | enforce no-code | applied; generated marker/scalar/adjustor counts zero |
| C126-039 | Generated output must contain class and every source body once, with no aggregate/scalar/adjustor duplicate and no old GetControlType body. | strong | emitter architecture | final generated verification | wait/inspect | complete under command 000000009346; every required count verified |
| C126-040 | Zero raw-start xrefs remain explicit negative evidence and cap confidence; they do not defer source resolution. | very strong | xrefs plus exact bodies | core/raw children | preserve | applied on core and affected children |
| C126-041 | Create/register all 16 new pages serially and capture each real validator UID before inserting links. | mandatory | workflow | callback sequence/checklist | serialize | complete; UID0004KC through UID0004KR captured serially |
| C126-042 | No original UIDs are fabricated or changed; validator-aware renames preserve UID00011G and UID0002PE. | mandatory | workflow | callback sequence | preserve | complete; both path updates preserved original UIDs |
| C126-043 | Scores move only where complete blockers are closed; shared support pages remain unchanged unless exact additions are listed. | strong | score audit | all named docs | scoped application | applied; unrelated scores/metadata preserved |
| C126-044 | Historical embedded/provisional/TextButtonEx/three-accessor/GetControlType/aggregate-marker claims are retained only as superseded history. | very strong | direct contradiction | affected docs/history | historicalize | applied across target/class/core/file/children/support |
| C126-045 | Historical report-only repair performed no leases, by-* edits, validators, generated edits, or lifecycle commands; the accepted callback retained the no-lifecycle boundary. | mandatory | assignment and callback | report/checklist | preserve boundary | complete; callback used only authorized leases/validators and no lifecycle command |

## Positive Evidence Summary

- UID000126 reads final object dword `+0x108`, restores all three class vtables, virtually deletes the child, invokes Pane teardown, applies deleting flags, and uses complete size `0x10c` on the guarded path.
- Raw ordinary body performs the same class-specific cleanup without allocation flags or storage free, proving the only handwritten destructor statement.
- Constructor writes exactly one derived member at `+0x108` after the `0x108`-byte base layout; broad callers allocate a `0x10c` wrapper around multiple differently sized polymorphic child classes.
- Four raw delegates load the same child and enter four canonical ScrollablePane helpers with preserved caller arguments.
- Three formerly mislabeled methods enter through the secondary EventHandler vtable and dispatch the child's corresponding EventHandler facet with the same `Event *`.
- Layer and paint bodies have complete, bounded source behavior with accepted project helpers and no compiler-only operations.
- UID0002PE's direct byte return and stack cleanup align exactly with the shared hit-test slot and coordinate caller.
- Pane teardown vtables and ControlPane scalar parity eliminate the stale TextButtonEx base claim.

## IDA MCP Facts

- Function/range facts:
  - constructor `0x004985a0-0x00498656`, size `0xb6`;
  - raw ordinary destructor `0x00498660-0x00498695`;
  - raw delegates `0x004986a0-0x004986af`, `0x004986b0-0x004986bf`, `0x004986c0-0x004986cf`, `0x004986d0-0x004986df`;
  - UpdateRenderRegion `0x004986e0-0x004986fb`;
  - event delegates `0x00498700-0x00498718`, `0x00498720-0x00498738`, `0x00498740-0x00498758`;
  - Enable `0x00498760-0x0049877a`, Disable `0x00498780-0x0049879a`;
  - AddToLayer `0x004987a0-0x0049885c`, RemoveFromLayer `0x00498860-0x00498876`, OnPaint `0x00498880-0x004988cd`;
  - next TextEdit constructor begins at `0x004988d0`;
  - adjustors `0x0049afd7-0x0049afed` as two `0x0b` functions;
  - UID000126 `0x0049b4f0-0x0049b557`, size `0x67`;
  - UID0002PE `0x0049b900-0x0049b905`, bytes semantically `mov al,0x12; retn 8`;
  - Pane teardown `0x00544580`, size `0x107`.
- Scalar-wrapper facts:
  - UID000126 has 35 instructions across its exact `0x67` bytes;
  - it installs all three ScrollableControlPane vptrs, invokes the child virtual destructor with deleting flag 1, calls Pane teardown `0x00544580`, tests deleting bits 1 and 4, reaches operator-delete wrapper `0x004f4ac0`, and uses guard helper `0x0041b6a0` with complete size `0x10c`;
  - its return-this, deleting-flag, deallocation, and guarded-size paths are compiler ABI behavior, not extra source statements.
- Constructor facts:
  - calls `ControlPane(4, bounds)`;
  - stores `ScrollablePane *` at `+0x108`;
  - stores the three trailing integers to child `+0x100/+0x104/+0x108`;
  - calls child vslot `+0x2c`, accepted `SetBounds(bounds, 0)`;
  - writes inherited `m_controlActive=false` at `+0x102` and `m_controlFlags=1` at `+0xff`.
- ScrollablePane field facts:
  - constructor initializes child `+0x100/+0x104/+0x108` to zero;
  - `+0x100` and `+0x104` participate in horizontal/vertical child placement;
  - `+0x108` is subtracted from right/bottom dimensions when corresponding scrollbars are enabled;
  - caller values 13 and 10 match observed scrollbar extent/inset roles.
- Raw delegate destination facts:
  - `0x0055e8a0` consumes a `short` value and `char` axis, selects the horizontal `+0xf8` or vertical `+0xfc` child, and calls the selected ScrollWidget target-value setter;
  - `0x0055e8d0` consumes the same argument pair, updates the selected current-value word at child `+0xfe`, and invalidates;
  - `0x0055e910` returns the selected child maximum at `+0x100`, or zero when absent;
  - `0x0055e950` returns the selected child current position at `+0xfe`, or zero when absent.
- Vtable facts:
  - exact island `0x00618058-0x006180fc`;
  - primary table at `0x0061805c` has 25 slots;
  - secondary EventHandler table at `0x006180c4` has 11 slots;
  - tertiary table at `0x006180f4` has 2 slots;
  - complete object locators are at `0x00645cbc`, `0x00645d1c`, and `0x00645d30`; the class type descriptor is at `0x00675864`;
  - TextEdit primary table begins at `0x00618100`.
- Xref facts:
  - constructor: 44 code refs from 26 unique caller functions;
  - raw ordinary and four raw delegate starts: zero xrefs each;
  - vtable-routed core methods have the expected primary/secondary table data refs;
  - adjustors each have one secondary/tertiary vtable data ref;
  - UID000126 has two adjustor code refs and one primary-vtable data ref;
  - UID0002PE has one primary-vtable data ref at `0x006180bc`;
  - Pane teardown has 303 family refs, including both Scrollable destructor forms.
- Padding facts: all listed core/target spans are `0xcc`; no live code is hidden in them.
- Inherited layout facts: `m_controlFlags` is at `+0xff`, `m_controlVisible` at `+0x101`, and `m_controlActive` at `+0x102` in the accepted ControlPane layout.
- Layer helper facts: `0x00544c70` is the accepted Pane AddToLayer body and `0x004b7e10` is accepted `OffsetRect(RectBounds *, int, int)`; child vslots `+0x0c` and `+0x30` are UpdateRenderRegion and AddToLayer.

## Function / Child Inventory

| Range | Destination filename | Role | Score | Owner/emitter/reconstructable | Position / Nested | Status |
| --- | --- | --- | --- | --- | --- | --- |
| aggregate `0x004985a0-0x004988cd` | UID00011G `0x004985a0-0x004988cd.ScrollableControlPaneCore.md` | split index only | `92/94` | NONE / blank / false | blank / 0 | applied; UID preserved; no C++ |
| `0x004985a0-0x00498656` | UID0004KC `ScrollableControlPaneConstructor.md` | constructor | `92/94` | UID0000CE / UID0000CE / true | 20 / 0 | registered, validated, emitted |
| `0x00498660-0x00498695` | UID0004KD `ScrollableControlPaneDestructor.md` | ordinary destructor | `91/94` | UID0000CE / UID0000CE / true | 30 / 0 | registered, validated, emitted |
| `0x004986a0-0x004986af` | UID0004KE `ScrollableControlPaneSetScrollTargetValueRaw.md` | child delegate | `90/93` | UID0000CE / UID0000CE / true | 40 / 0 | registered, validated, emitted |
| `0x004986b0-0x004986bf` | UID0004KF `ScrollableControlPaneSetScrollCurrentValueRaw.md` | child delegate | `90/93` | UID0000CE / UID0000CE / true | 50 / 0 | registered, validated, emitted |
| `0x004986c0-0x004986cf` | UID0004KG `ScrollableControlPaneGetScrollMaxRaw.md` | child delegate | `90/93` | UID0000CE / UID0000CE / true | 60 / 0 | registered, validated, emitted |
| `0x004986d0-0x004986df` | UID0004KH `ScrollableControlPaneGetScrollPositionRaw.md` | child delegate | `90/93` | UID0000CE / UID0000CE / true | 70 / 0 | registered, validated, emitted |
| `0x004986e0-0x004986fb` | UID0004KI `ScrollableControlPaneUpdateRenderRegion.md` | base/child render update | `92/94` | UID0000CE / UID0000CE / true | 80 / 0 | registered, validated, emitted |
| `0x00498700-0x00498718` | UID0004KJ `ScrollableControlPaneHandlePointerOrMouseEvent.md` | EventHandler delegate | `92/94` | UID0000CE / UID0000CE / true | 90 / 0 | registered, validated, emitted |
| `0x00498720-0x00498738` | UID0004KK `ScrollableControlPaneHandleKeyOrTextEvent.md` | EventHandler delegate | `92/94` | UID0000CE / UID0000CE / true | 100 / 0 | registered, validated, emitted |
| `0x00498740-0x00498758` | UID0004KL `ScrollableControlPaneHandlePacketEvent.md` | EventHandler delegate | `92/94` | UID0000CE / UID0000CE / true | 110 / 0 | registered, validated, emitted |
| `0x00498760-0x0049877a` | UID0004KM `ScrollableControlPaneEnable.md` | visible-state setter | `91/93` | UID0000CE / UID0000CE / true | 120 / 0 | registered, validated, emitted |
| `0x00498780-0x0049879a` | UID0004KN `ScrollableControlPaneDisable.md` | visible-state setter | `91/93` | UID0000CE / UID0000CE / true | 130 / 0 | registered, validated, emitted |
| `0x004987a0-0x0049885c` | UID0004KO `ScrollableControlPaneAddToLayer.md` | layer insertion | `92/94` | UID0000CE / UID0000CE / true | 140 / 0 | registered, validated, emitted |
| `0x00498860-0x00498876` | UID0004KP `ScrollableControlPaneRemoveFromLayer.md` | layer removal | `92/94` | UID0000CE / UID0000CE / true | 150 / 0 | registered, validated, emitted |
| `0x00498880-0x004988cd` | UID0004KQ `ScrollableControlPaneOnPaint.md` | paint | `92/94` | UID0000CE / UID0000CE / true | 160 / 0 | registered, validated, emitted |
| `0x0049afd7-0x0049afed` | UID0004KR `ScrollableControlPaneAdjustorThunks.md` | compiler adjustor pair | `90/94` | NONE / blank / false | blank / -8 | registered and validated; no C++ |
| `0x0049b4f0-0x0049b557` | UID000126 current target | scalar deleting ABI wrapper | `92/94` | NONE / blank / false | blank / -8 | applied and validated; no C++ |
| `0x0049b900-0x0049b905` | UID0002PE `ScrollableControlPaneHitTestPart.md` | hit-test constant virtual | `92/94` | UID0000CE / UID0000CE / true | 170 / 0 | renamed preserving UID, validated, emitted |
| `0x00618058-0x006180fc` | existing UID000252 aggregate | vtables/RTTI | unchanged | aggregate evidence | unchanged | evidence only |

No validator-issued UID is guessed above. The callback created one page, validated it, captured its real UID, released the parent lease, and only then continued; the resulting serial UID range is UID0004KC through UID0004KR.

## Direct Xref / Caller Inventory

| Address / item | Xref / caller / callee | Meaning |
| --- | --- | --- |
| `0x004985a0` | 44 refs from 26 functions: `0x00472070`, `0x00472ca0`, `0x004753e0`, `0x00479110`, `0x0047b220`, `0x004824e0`, `0x0048a1c0`, `0x0048a810`, `0x0048b1c0`, `0x0049feb0`, `0x004ac8a0`, `0x004ae4c0`, `0x004af570`, `0x00517f30`, `0x0051a520`, `0x0051b880`, `0x0051ca40`, `0x0051db40`, `0x0051e9a0`, `0x0052dd30`, `0x00549c20`, `0x0054e920`, `0x0054fb30`, `0x00573d20`, `0x0058c350`, `0x0059bc90` | broad generic wrapper construction |
| constructor callers | wrapper allocations `0x10c`; child allocations include `0x14c`, `0x154`, `0x49c`, and other sizes | polymorphic owned pointer, not embedded object |
| `0x00498660` | zero xrefs | complete raw ordinary source body; preserve liveness uncertainty |
| four raw delegates | zero start xrefs; tail destinations `0x0055e8a0`, `0x0055e8d0`, `0x0055e910`, `0x0055e950` | four coherent source delegates with exact helper contracts |
| `0x004986e0` | primary table data ref `0x00618068` | UpdateRenderRegion override |
| `0x00498700/20/40` | secondary EventHandler table refs `0x006180c8`, `0x006180cc`, `0x006180d4` | three EventHandler delegates |
| `0x00498760/80` | primary table refs `0x006180a8`, `0x006180ac` | Enable/Disable overrides |
| `0x004987a0` | primary table ref `0x0061808c` | AddToLayer override |
| `0x00498860` | primary table ref `0x00618094` | RemoveFromLayer override |
| `0x00498880` | primary table ref `0x006180a0` | OnPaint override |
| `0x0049afd7/e2` | one secondary/tertiary vtable data ref each; jumps to UID000126 | compiler adjustors |
| UID000126 | code refs from both adjustors; primary data ref `0x0061805c` | vtable/adjustor-only scalar route |
| UID000126 callees | child vslot 0 flag 1, Pane teardown, operator delete, guard helper | owned delete plus compiler storage mechanics |
| UID0002PE | primary data ref `0x006180bc` | hit-test virtual at shared slot `+0x60` |
| caller `0x00497c60` | passes x/y to slot `+0x60`, consumes `AL` | direct two-argument byte-return contract |

## Documentation Evidence And IDA Status

- UID0000CF/UID0001GL identify `ScrollablePane` and the four destination helpers and now contain the accepted additive field-role/wrapper evidence without ownership or emitter changes.
- UID000038/UID0001EA and PaneCoreVtableFamily identify `0x00544580` as Pane ordinary teardown.
- Current EventHandler documentation provides exact secondary method names and slot order.
- Current Pane/GrafPort/RectBounds docs provide `SetBounds`, `UpdateRenderRegion`, `AddToLayer`, `RemoveFromLayer`, `OffsetRect`, `SetDrawColor`, `FillRect`, and `DrawRectFrame` contracts used by the formal bodies.
- SliderControlPane current source and direct body at `0x00496800` establish `HitTestPart(int, int)` in the shared primary slot. ControlPane's `0x0041d690` body also returns a byte and `retn 8`.
- UID000197 identifies the operator-delete wrapper; immediate Rectangle target/adjustor and PopupMenu raw destructor remain valid compiler/source precedents.
- The callback historicalized embedded/provisional child, TextButtonEx base, old three scroll accessors, no-argument GetControlType, source-authored scalar wrapper, and comment-only aggregate source routes.
- The current generated file is validator-owned evidence and was not manually edited. Waited refresh command `000000009346` removed all four historical markers and emitted each accepted source block exactly once.

## Ranked Ownership Analysis

### 1. UID0000CE class plus exact method children

- Evidence for: exact class vtables, constructor ownership, class source route, complete bounded human bodies, accepted helper contracts, broad caller use, and sibling virtual signatures.
- Evidence against: ordinary destructor and four tiny delegates have no raw-start xrefs; this caps confidence but does not change exact source semantics or placement.
- Decision: accepted source architecture. UID0000CE owns the full declaration; each exact human body emits from its own by-memory child.

### 2. UID00011G aggregate emitter

- Evidence for: it historically grouped the contiguous constructor/core range.
- Evidence against: one aggregate block cannot represent 15 distinct methods, exact padding, source order, and per-range evidence without duplication or unresolved markers.
- Decision: reject emission. Preserve UID00011G as a no-owner/non-reconstructable split index with complete child links and evidence.

### 3. UID000126 as class-owned source or covered-by marker

- Evidence for: it repeats the member cleanup and carries class vtables.
- Evidence against: every unique operation is compiler deleting-destructor ABI; the ordinary child owns the only human statement.
- Decision: no owner, no emitter, no covered-by marker, non-reconstructable.

### 4. UID0002PE as GetControlType

- Evidence for: it returns constant `0x12`, historically interpreted as a type id.
- Evidence against: `AL` return plus `retn 8`, shared slot, sibling source, and caller coordinate flow directly contradict a no-argument integer method.
- Decision: rename preserving UID and emit `HitTestPart(int, int)`.

### Applied file/grouping

- No new physical source file. Continue UID0000NE `NexusTK/ui/controls/ScrollableControlPane.cpp`.
- Exactly 15 source children UID0004KC through UID0004KQ now cover the corrected UID00011G range, and UID0004KR is the compiler-only adjustor child, using the exact filenames/ranges in the inventory.
- UID00011G indexes the full three-part structure: source children, internal padding, and historical aggregate evidence. UID00011Y indexes the compiler adjustor/scalar family.
- Rejected contents: no vtable data, neighboring Rectangle/TextEdit/SimpleHelp code, deleting flags, adjustor body, or aggregate duplicate enters source output.

## Source Placement

- Applied class/source: `ScrollableControlPane` in `NexusTK/ui/controls/ScrollableControlPane.cpp` through UID0000CE/UID0000NE.
- Source order: class declaration 10; constructor 20; ordinary destructor 30; four ScrollablePane delegates 40-70; UpdateRenderRegion 80; three EventHandler delegates 90-110; Enable/Disable 120/130; AddToLayer 140; RemoveFromLayer 150; OnPaint 160; HitTestPart 170.
- UID00011G is source-neutral after splitting. UID000126 and adjustors remain documentation-only compiler evidence.
- ScrollablePane remains a dependency/pointee under its existing route, not the wrapper translation-unit owner.
- Rejected placements: `ScrollBar.cpp`, `ControlPane.cpp`, `Pane.cpp`, UID00011Y aggregate output, a destructor-only file, or a new type-id source file.
- Remaining placement uncertainty: none affecting generated behavior or ordering.

## Range / Split / Padding / Reclassification Analysis

- UID00011G's stale path end was renamed from `0x004988cc` to exact half-open `0x004988cd`, preserving UID. Final OnPaint ends at `0x004988cd`; `0x004988cd-0x004988d0` is three-byte padding before TextEdit.
- The complete source range is split into the 15 exact child ranges listed in Function / Child Inventory. No live byte belongs to more than one child.
- Internal core padding registered in `by-memory/-ignored.md`:
  - `0x00498656-0x00498660` (10), `0x00498695-0x004986a0` (11);
  - `0x004986af-0x004986b0`, `0x004986bf-0x004986c0`, `0x004986cf-0x004986d0`, `0x004986df-0x004986e0` (1 each);
  - `0x004986fb-0x00498700` (5);
  - `0x00498718-0x00498720`, `0x00498738-0x00498740`, `0x00498758-0x00498760` (8 each);
  - `0x0049877a-0x00498780`, `0x0049879a-0x004987a0` (6 each);
  - `0x0049885c-0x00498860` (4), `0x00498876-0x00498880` (10), `0x004988cd-0x004988d0` (3).
- Registered target padding: `0x0049b4e5-0x0049b4f0` (11) and `0x0049b557-0x0049b560` (9).
- Registered/linked adjustor compiler range: `0x0049afd7-0x0049afed`, preserving both exact functions and real child UID0004KR.
- Adjustor fences: the Rectangle predecessor ends exactly at `0x0049afd7`; the SimpleHelp adjustor successor begins exactly at `0x0049afed`.
- UID000126 applied reclassification: exact compiler ABI evidence, NONE/false/blank, `Nested:-8`.
- UID00011G applied reclassification: exact split index, NONE/false/blank, `Nested:0`, no Empty Emitter Marker.
- UID0002PE applied rename/signature correction: same UID and exact range; source body and position changed, not range.
- `.rdata` remains in existing UID000252 aggregate; no separate vtable page is required.

## Negative Evidence Summary

- No direct xref reaches raw ordinary destructor start or any of the four raw delegate starts. This remains explicit and caps confidence; it is not used to defer or erase complete source-shaped bodies.
- UID000126 has no ordinary caller, feature behavior, resource use, or unique human cleanup beyond owned-child deletion.
- Each adjustor has one vtable data ref and only subtraction plus jump.
- No source body explicitly performs vptr transitions, deleting-flag tests, Pane destruction, operator delete, or guard-size calls.
- No body in UID00011G overrides EventHandler `HandleImeEvent`; inherited behavior remains untouched.
- Constructor callers do not pass one concrete child type/size, rejecting embedded or concrete `ScrollPane` ownership.
- Direct UID0002PE ABI rejects both a 32-bit return and zero arguments.
- No range extends into Rectangle predecessors, TextEdit successor at `0x004988d0`, SimpleHelp scalar successor at `0x0049b560`, or unrelated `.rdata`.
- No evidence requires source ownership changes to ScrollablePane, Pane, ControlPane, EventHandler, GrafPort, operator delete, UID00011Y, or UID000252.

## IDA Rename / Type / Comment Recommendations

- Documentation/source-facing class: `ScrollableControlPane : public ControlPane`.
- Field: `ScrollablePane *m_scrollablePane` at `+0x108`.
- ScrollablePane descriptive fields: `m_horizontalScrollBarOffset` at `+0x100`, `m_verticalScrollBarOffset` at `+0x104`, `m_scrollBarInset` at `+0x108`.
- Source methods: constructor, destructor, four scroll delegates, UpdateRenderRegion, three EventHandler delegates, Enable, Disable, AddToLayer, RemoveFromLayer, OnPaint, and `HitTestPart(int, int)`.
- Documentation comments identify raw ordinary destructor `0x00498660`, two adjustors `0x0049afd7/0x0049afe2`, scalar wrapper `0x0049b4f0`, and Pane teardown `0x00544580`.
- IDA database mutation remains excluded. No stripped function/global type is renamed in the live database.

## First-Draft C++ Recommendation

- Whole-report managed destination block count: exactly 17.
- Source destinations: UID0000CE class declaration, 15 exact core method children, and UID0002PE HitTestPart.
- No-code destinations: UID00011G split index, UID000126 scalar wrapper, and UID0004KR adjustor child retain blank formal C++.

Destination: `by-class/ScrollableControlPane.md` (UID0000CE), position `10`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class Layer;
class Pane;
class ScrollablePane;
struct RectBounds;

class ScrollableControlPane : public ControlPane
{
public:
    ScrollableControlPane(const RectBounds *bounds,
                          ScrollablePane *scrollablePane,
                          int horizontalScrollBarOffset,
                          int verticalScrollBarOffset,
                          int scrollBarInset);
    virtual ~ScrollableControlPane();

    void SetScrollTargetValue(short targetValue, char axis);
    void SetScrollCurrentValue(short currentValue, char axis);
    short GetScrollMax(char axis) const;
    short GetScrollPosition(char axis) const;

    virtual void UpdateRenderRegion(const RectBounds *bounds);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual void Enable();
    virtual void Disable();
    virtual void AddToLayer(const RectBounds *bounds,
                            int order,
                            Pane *previousPane,
                            Layer *layer);
    virtual void RemoveFromLayer();
    virtual void OnPaint();
    virtual unsigned char HitTestPart(int x, int y);

private:
    ScrollablePane *m_scrollablePane;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: `by-memory/0x004985a0-0x00498656.ScrollableControlPaneConstructor.md` (UID0004KC), position `20`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ScrollableControlPane::ScrollableControlPane(
    const RectBounds *bounds,
    ScrollablePane *scrollablePane,
    int horizontalScrollBarOffset,
    int verticalScrollBarOffset,
    int scrollBarInset)
    : ControlPane(4, bounds),
      m_scrollablePane(scrollablePane)
{
    m_scrollablePane->m_horizontalScrollBarOffset = horizontalScrollBarOffset;
    m_scrollablePane->m_verticalScrollBarOffset = verticalScrollBarOffset;
    m_scrollablePane->m_scrollBarInset = scrollBarInset;
    m_scrollablePane->SetBounds(bounds, 0);
    m_controlActive = false;
    m_controlFlags = 1;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: `by-memory/0x00498660-0x00498695.ScrollableControlPaneDestructor.md` (UID0004KD), position `30`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ScrollableControlPane::~ScrollableControlPane()
{
    delete m_scrollablePane;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: `by-memory/0x004986a0-0x004986af.ScrollableControlPaneSetScrollTargetValueRaw.md` (UID0004KE), position `40`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ScrollableControlPane::SetScrollTargetValue(short targetValue, char axis)
{
    m_scrollablePane->SetScrollTargetValue(targetValue, axis);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: `by-memory/0x004986b0-0x004986bf.ScrollableControlPaneSetScrollCurrentValueRaw.md` (UID0004KF), position `50`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ScrollableControlPane::SetScrollCurrentValue(short currentValue, char axis)
{
    m_scrollablePane->SetScrollCurrentValue(currentValue, axis);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: `by-memory/0x004986c0-0x004986cf.ScrollableControlPaneGetScrollMaxRaw.md` (UID0004KG), position `60`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
short ScrollableControlPane::GetScrollMax(char axis) const
{
    return m_scrollablePane->GetScrollMax(axis);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: `by-memory/0x004986d0-0x004986df.ScrollableControlPaneGetScrollPositionRaw.md` (UID0004KH), position `70`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
short ScrollableControlPane::GetScrollPosition(char axis) const
{
    return m_scrollablePane->GetScrollPosition(axis);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: `by-memory/0x004986e0-0x004986fb.ScrollableControlPaneUpdateRenderRegion.md` (UID0004KI), position `80`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ScrollableControlPane::UpdateRenderRegion(const RectBounds *bounds)
{
    GrafPort::UpdateRenderRegion(bounds);
    m_scrollablePane->UpdateRenderRegion(bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: `by-memory/0x00498700-0x00498718.ScrollableControlPaneHandlePointerOrMouseEvent.md` (UID0004KJ), position `90`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ScrollableControlPane::HandlePointerOrMouseEvent(Event *event)
{
    return m_scrollablePane->HandlePointerOrMouseEvent(event);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: `by-memory/0x00498720-0x00498738.ScrollableControlPaneHandleKeyOrTextEvent.md` (UID0004KK), position `100`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ScrollableControlPane::HandleKeyOrTextEvent(Event *event)
{
    return m_scrollablePane->HandleKeyOrTextEvent(event);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: `by-memory/0x00498740-0x00498758.ScrollableControlPaneHandlePacketEvent.md` (UID0004KL), position `110`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ScrollableControlPane::HandlePacketEvent(Event *event)
{
    return m_scrollablePane->HandlePacketEvent(event);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: `by-memory/0x00498760-0x0049877a.ScrollableControlPaneEnable.md` (UID0004KM), position `120`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ScrollableControlPane::Enable()
{
    if (!m_controlVisible)
    {
        m_controlVisible = true;
        InvalidateRect(&m_bounds);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: `by-memory/0x00498780-0x0049879a.ScrollableControlPaneDisable.md` (UID0004KN), position `130`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ScrollableControlPane::Disable()
{
    if (m_controlVisible)
    {
        m_controlVisible = false;
        InvalidateRect(&m_bounds);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: `by-memory/0x004987a0-0x0049885c.ScrollableControlPaneAddToLayer.md` (UID0004KO), position `140`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ScrollableControlPane::AddToLayer(const RectBounds *bounds,
                                       int order,
                                       Pane *previousPane,
                                       Layer *layer)
{
    Pane::AddToLayer(bounds, order, previousPane, layer);

    RectBounds childBounds = *bounds;
    OffsetRect(&childBounds, -childBounds.left, -childBounds.top);
    GrafPort::UpdateRenderRegion(&childBounds);
    m_scrollablePane->UpdateRenderRegion(&childBounds);

    childBounds = *bounds;
    OffsetRect(&childBounds, -childBounds.left, -childBounds.top);
    m_scrollablePane->AddToLayer(&childBounds, 0, this, layer);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: `by-memory/0x00498860-0x00498876.ScrollableControlPaneRemoveFromLayer.md` (UID0004KP), position `150`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ScrollableControlPane::RemoveFromLayer()
{
    m_scrollablePane->RemoveFromLayer();
    Pane::RemoveFromLayer();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: `by-memory/0x00498880-0x004988cd.ScrollableControlPaneOnPaint.md` (UID0004KQ), position `160`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ScrollableControlPane::OnPaint()
{
    if (g_useEpfAssets != 1)
    {
        SetDrawColor(0);
        FillRect(&m_bounds);

        if (m_controlVisible && m_controlActive)
        {
            SetDrawColor(128);
            m_drawMode = 0;
            DrawRectFrame(&m_bounds);
        }
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: `by-memory/0x0049b900-0x0049b905.ScrollableControlPaneHitTestPart.md` (UID0002PE), position `170`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
unsigned char ScrollableControlPane::HitTestPart(int x, int y)
{
    return 18;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Class compile shape: `ControlPane` is the complete included base; forward declarations cover pointer/reference-only `Event`, `Layer`, `Pane`, `ScrollablePane`, and `RectBounds` names. Every out-of-class definition has a matching declaration.
- Constructor mapping: direct field stores, `SetBounds(bounds, 0)`, and inherited flag writes preserve machine order. The descriptive child field names are present in ScrollablePane support, so this direct-access source route is declared.
- UID0002PE ABI mapping: `unsigned char` regenerates `AL`; two `int` parameters regenerate eight callee-popped bytes under the class's 32-bit member calling convention. Parameter values are intentionally unused because the body always returns part id 18.
- UID000126 no-code proof: vtable/adjustor-only reachability, deleting flags, return-this ABI, vptr stores, implicit base teardown, unsized delete, guarded size `0x10c`, and no independent source behavior.
- Adjustor no-code proof: both bodies only normalize secondary/tertiary `this` and jump to UID000126.
- UID00011G no-code proof: after exact child splitting it is a documentation index/range container, not a human function or covered source body.

## Final Recommendation

- C126-001 through C126-045 are applied at report-level detail and scoped-validated.
- UID000126 has the exact `92/94`, NONE/false/blank, `Nested:-8` compiler-wrapper disposition.
- UID0000CE has the complete class block at `92/94`, position 10.
- UID00011G is the exact `0x004985a0-0x004988cd` no-code split index; UID0004KC through UID0004KQ are its 15 serially registered source children.
- UID0004KR is the exact serially registered no-code adjustor child.
- UID0002PE retained its UID through rename, contains the two-argument byte-return HitTestPart block, and uses position 170.
- Exactly 17 managed blocks are applied. No other C++ or declaration/body change exists in this report.
- Class/file/core/ScrollablePane/compiler-index/ignored/read-only support contains the accepted detail with unrelated content and scores preserved.
- Waited generated verification proves complete, single-copy class/source output and absence of stale aggregate/compiler/type-id markers.

## Recommended Target Doc Changes

- Target path remains `by-memory/0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor.md`.
- Applied metadata is `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal body, and `Nested:-8`.
- Provisional source-wrapper wording is historicalized in favor of exact MSVC scalar-deleting-destructor classification.
- The page contains the exact 35-instruction body evidence, three vptr stores, owned child vslot-0 delete flag 1, Pane teardown, deleting flags bit 1/4, operator-delete wrapper `0x004f4ac0`, guard helper `0x0041b6a0`, guarded size `0x10c`, return-this ABI, exact xrefs, fences, and neighboring exclusions.
- UID0004KD is linked as the real ordinary destructor child, whose explicit member deletion is the sole human destructor body.
- UID00011G indexes all source methods and UID0002PE owns HitTestPart; neither relation makes UID000126 source-bearing.
- Embedded child, provisional type/name, TextButtonEx base, source-authored scalar wrapper, and blank-because-score-gate claims remain only as superseded history.

## Recommended Support Doc Changes

- UID0000CE `by-class/ScrollableControlPane.md` is `92/94`, retains UID0000NE owner/emitter/true, uses position 10, and contains the exact complete class block, size `0x10c`, ControlPane base, member at `+0x108`, ownership, constructor fields, complete method inventory, vtables, real child links, and superseded-history corrections.
- UID0000NE `by-file/ScrollableControlPane.md` is `91/93`, retains FILE and `NexusTK/ui/controls/`, and records exact order 10-170, no-code target/core/adjustor dispositions, layout/lifetime, callers, vtables, dependencies, and generated contract.
- UID00011G preserved its UID through validator-aware rename to `by-memory/0x004985a0-0x004988cd.ScrollableControlPaneCore.md`; it is `92/94`, owner NONE, false, blank emitter/position/formal C++, `Nested:0`, and now indexes every real child, source behavior/range, internal pad, zero-start-xref note, historical correction, and no-code rationale.
- Fifteen source children UID0004KC through UID0004KQ were created/registered serially in exact inventory order, with each validator UID captured before linking. Each has its exact score/owner/emitter/position/nesting/block and full raw/decompile, route, helper, boundary, negative, source-mapping, and historical evidence.
- UID0004KR `by-memory/0x0049afd7-0x0049afed.ScrollableControlPaneAdjustorThunks.md` is `90/94`, owner NONE, false, blank emitter/position/formal C++, `Nested:-8`, and documents both functions, bytes, vtable refs, target jumps, boundaries, and no-code rationale.
- UID0002PE preserved its UID through validator-aware rename to `by-memory/0x0049b900-0x0049b905.ScrollableControlPaneHitTestPart.md`; it is `92/94`, retains UID0000CE owner/emitter/true at position 170, and contains the exact body plus `AL`, `retn 8`, slot `+0x60`, sibling/caller, unused-coordinate, fence, and superseded GetControlType evidence.
- UID0000CF/UID0001GL ScrollablePane support preserves scores, owner, emitter, reconstructable state, and existing C++; it adds field roles at `+0x100/+0x104/+0x108`, constructor/layout evidence, four helper contracts, and the ScrollableControlPane wrapper relation.
- UID00011Y compiler family index preserves score/metadata and neighboring compiler families while linking UID0004KR, UID000126, UID0004KD, and the source/index relation.
- `by-memory/-ignored.md` preserves all prior rows and adds the 15 exact internal pads, two target pads, and adjustor range with real registered UIDs.
- UID000252 ControlPane read-only aggregate preserves score/metadata and adds the exact Scrollable `.rdata` range, 25/11/2 slot counts, three bases, EventHandler mapping, HitTest slot, adjustors, and TextEdit successor.
- Verified no-edit support:
  - EventHandler method declarations already match the three corrected delegates;
  - Pane, ControlPane, GrafPort, RectBounds, Surface, operator-delete, and vtable-family docs already contain same-or-greater support;
  - no unrelated score, emitter, C++, or metadata change is justified on those pages.

## Score And Metadata Recommendation

| Page | Historical pre-callback | Applied | Metadata disposition |
| --- | --- | --- | --- |
| UID000126 target | `86/90` | `92/94` | NONE, false, blank emitter/position/C++, Nested -8 |
| UID0000CE class | `86/89` | `92/94` | retain UID0000NE owner/emitter, true, position 10, complete declaration |
| UID0000NE file | `86/89` | `91/93` | retain FILE/path; exact source order |
| UID00011G core | `86/90` | `92/94` | preserve UID, rename exact end, NONE, false, blank emitter/position/C++, Nested 0 |
| UID0004KC constructor | absent | `92/94` | UID0000CE owner/emitter, true, position 20, Nested 0 |
| UID0004KD ordinary destructor | absent | `91/94` | UID0000CE owner/emitter, true, position 30, Nested 0 |
| UID0004KE-UID0004KH raw delegates | absent | `90/93` each | UID0000CE owner/emitter, true, positions 40-70, Nested 0 |
| UID0004KI UpdateRenderRegion | absent | `92/94` | UID0000CE owner/emitter, true, position 80, Nested 0 |
| UID0004KJ-UID0004KL EventHandler delegates | absent | `92/94` each | UID0000CE owner/emitter, true, positions 90-110, Nested 0 |
| UID0004KM/UID0004KN Enable/Disable | absent | `91/93` each | UID0000CE owner/emitter, true, positions 120/130, Nested 0 |
| UID0004KO AddToLayer | absent | `92/94` | UID0000CE owner/emitter, true, position 140, Nested 0 |
| UID0004KP RemoveFromLayer | absent | `92/94` | UID0000CE owner/emitter, true, position 150, Nested 0 |
| UID0004KQ OnPaint | absent | `92/94` | UID0000CE owner/emitter, true, position 160, Nested 0 |
| UID0004KR adjustors | absent | `90/94` | NONE, false, blank emitter/position/C++, Nested -8 |
| UID0002PE HitTestPart | `88/93` | `92/94` | preserve UID; UID0000CE owner/emitter, true, position 170 |
| UID0000CF/UID0001GL, UID00011Y, ignored, UID000252 | existing | unchanged | additive evidence/link changes only |

- Target score rationale: exact field type/name/ownership, ordinary source route, base teardown, compiler disposition, size, flags, adjustors, refs, fences, and neighboring exclusions are closed.
- Class/core score rationale: complete declaration and every source body/signature/range are now resolved; UID00011G's score describes complete index/evidence quality, not reconstructability.
- Raw delegate reason not higher: exact body and destination are strong, but all four starts currently have zero direct xrefs and original declaration spellings are stripped.
- Ordinary destructor reason not higher: exact source semantics are strong, but raw start lacks a function object/direct xref and private spelling is inferred.
- Reason no page is `95/95`: original private/header spelling is not symbol-proven, and several raw source-shaped ranges lack active direct refs. Neither uncertainty affects runtime behavior, range, owner, or emission.
- Score-improvement attempts close every named blocker: class compile shape, full core split, field roles, event-method correction, exact HitTest ABI, source order, no-code pages, generated expectations, and padding.

## Open Questions With Attempted Resolution

- What is `+0x108` in ScrollableControlPane?
  - Checked constructor, all callers, helper destinations, vtables, and destruction.
  - Resolution: exclusively owned `ScrollablePane *m_scrollablePane`.
- What are ScrollablePane child `+0x100/+0x104/+0x108`?
  - Checked initialization, layout/add-to-layer/render calculations, and every wrapper constructor call.
  - Resolution: horizontal offset, vertical offset, and common scrollbar inset; exact descriptive names selected.
- Is raw ordinary destructor source-authored?
  - Checked bytes, fences, vptr sequence, child delete, Pane tail, zero xrefs, and scalar/sibling parity.
  - Resolution: exact source-facing ordinary destructor child; zero-xref remains confidence evidence.
- Are four raw delegates source or compiler-only thunks?
  - Checked preserved arguments, distinct semantic destinations, complete fences, and class/helper contracts.
  - Resolution: four source-shaped delegating methods with exact formal bodies. They are not base-adjustor compiler glue.
- What are `0x00498700/20/40`?
  - Checked complete-object adjustment, secondary vtable slots, child secondary facet, and EventHandler contracts.
  - Resolution: pointer/mouse, key/text, and packet event delegates; old scroll-accessor labels are superseded.
- Does UID00011G need aggregate C++?
  - Checked full method/range inventory and generator architecture.
  - Resolution: no. It becomes a complete split index with blank formal C++; all 15 bodies emit from exact children.
- What is UID0002PE's source signature?
  - Checked `mov al,0x12; retn 8`, shared vtable slot, ControlPane/Slider bodies, and caller stack/AL use.
  - Resolution: `unsigned char HitTestPart(int x, int y)` returning 18.
- Is `0x00544580` TextButtonEx or explicit source teardown?
  - Checked vtables, full decompile, 303 xrefs, Pane docs, and ControlPane wrapper parity.
  - Resolution: implicit `Pane::~Pane()` base teardown; no explicit source call.
- Should UID000126 or adjustors emit covered-by markers?
  - Checked exact ordinary source body and immediate no-owner precedent.
  - Resolution: no. Both are blank non-reconstructable compiler evidence; generator must not emit them.
- Is a new vtable child or source file needed?
  - Checked current aggregate/source route and exact table boundaries.
  - Resolution: no. Update existing UID000252 and UID0000NE.
- Remaining unresolved questions: none affecting score, C++, declaration, signature, owner, emitter, split, padding, or generated output. Original spelling uncertainty is explicitly capped and behavior-neutral.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. No manual coverage, tracker, supervisor, or validator-owned row edit is required or authorized.
- Validator-owned coverage/generation derived from accepted by-* metadata and Item Summary content during callback validation.
- B001 did not manually edit generated, coverage, tracker, supervisor, validator-state, or lifecycle files.

## Follow-Up Actions

- B001 completed C126-001 through C126-045 without compression, registered all 16 new pages serially, preserved each real UID, used short one-file leases, validated each changed page, completed final waited generation, and updated this same report.
- No B001 implementation, lease, evidence, score, source, C++, or generated-verification work remains.
- Report validation, execution, count, path transition, move, and archive state remain external supervisor/validator-owned and are neither asserted nor directed by this artifact.
- No A-agent action or additional research assignment is required to close the source/score blockers documented here.

## Confidence

- Recommendation confidence: very strong (`94`).
- Source signature confidence: very strong for all virtual/event/layer/paint/HitTest methods; strong for stripped raw helper spelling.
- Score confidence: strong. Caps reflect zero raw-start refs and unsymbolized private/header names, not unresolved behavior.
- Remaining uncertainty: exact original private member/parameter spelling and header formatting only; no runtime, ownership, range, source, or emitter impact.

## Validator Results

- Working directory for every command: `source-3/project-documentation`.
- Scoped command shape: `python .\tools\validator.py --mode file --file '<path>' --apply --queue-timeout 240`.
- Final command shape: `python .\tools\validator.py --mode file --file 'by-file\ScrollableControlPane.md' --apply --queue-timeout 240 --wait-generated`.

| Scope | Command ID | Timestamp | Exit / scanned / ok | Direct side effect |
| --- | --- | --- | --- | --- |
| UID0004KC constructor | `000000009306` | `2026-07-13T06:15:02-04:00` | `0 / 1 / 1` | registered UID0004KC; generated refresh deferred |
| UID0004KD destructor | `000000009307` | `2026-07-13T06:16:47-04:00` | `0 / 1 / 1` | registered UID0004KD; generated refresh deferred |
| UID0004KE target-value delegate | `000000009308` | `2026-07-13T06:16:51-04:00` | `0 / 1 / 1` | registered UID0004KE; generated refresh deferred |
| UID0004KF current-value delegate | `000000009309` | `2026-07-13T06:17:03-04:00` | `0 / 1 / 1` | registered UID0004KF; generated refresh deferred |
| UID0004KG max delegate | `000000009310` | `2026-07-13T06:17:15-04:00` | `0 / 1 / 1` | registered UID0004KG; generated refresh deferred |
| UID0004KH position delegate | `000000009311` | `2026-07-13T06:18:52-04:00` | `0 / 1 / 1` | registered UID0004KH; generated refresh deferred |
| UID0004KI UpdateRenderRegion | `000000009312` | `2026-07-13T06:18:56-04:00` | `0 / 1 / 1` | registered UID0004KI; generated refresh deferred |
| UID0004KJ pointer/mouse event | `000000009313` | `2026-07-13T06:19:08-04:00` | `0 / 1 / 1` | registered UID0004KJ; generated refresh deferred |
| UID0004KK key/text event | `000000009314` | `2026-07-13T06:19:20-04:00` | `0 / 1 / 1` | registered UID0004KK; generated refresh deferred |
| UID0004KL packet event | `000000009315` | `2026-07-13T06:19:31-04:00` | `0 / 1 / 1` | registered UID0004KL; generated refresh deferred |
| UID0004KM Enable | `000000009316` | `2026-07-13T06:21:13-04:00` | `0 / 1 / 1` | registered UID0004KM; generated refresh deferred |
| UID0004KN Disable | `000000009317` | `2026-07-13T06:21:16-04:00` | `0 / 1 / 1` | registered UID0004KN; generated refresh deferred |
| UID0004KO AddToLayer | `000000009318` | `2026-07-13T06:21:28-04:00` | `0 / 1 / 1` | registered UID0004KO; generated refresh deferred |
| UID0004KP RemoveFromLayer | `000000009319` | `2026-07-13T06:21:40-04:00` | `0 / 1 / 1` | registered UID0004KP; generated refresh deferred |
| UID0004KQ OnPaint | `000000009320` | `2026-07-13T06:21:52-04:00` | `0 / 1 / 1` | registered UID0004KQ; generated refresh deferred |
| UID0004KR adjustors | `000000009321` | `2026-07-13T06:23:16-04:00` | `0 / 1 / 1` | registered UID0004KR; generated refresh deferred |
| UID00011G core rename/index | `000000009322` | `2026-07-13T06:24:57-04:00` | `0 / 1 / 1` | path update preserved UID00011G and propagated reverse refs; generated refresh deferred |
| UID0002PE HitTestPart rename | `000000009323` | `2026-07-13T06:25:45-04:00` | `0 / 1 / 1` | path update preserved UID0002PE and propagated reverse refs; generated refresh deferred |
| UID0000CE class | `000000009324` | `2026-07-13T06:26:58-04:00` | `0 / 1 / 1` | 31 UID links accepted; generated refresh deferred |
| UID0000NE file | `000000009325` | `2026-07-13T06:27:55-04:00` | `0 / 1 / 1` | exact source route accepted; generated refresh deferred |
| UID000126 scalar target | `000000009326` | `2026-07-13T06:28:50-04:00` | `0 / 1 / 1` | non-emitting metadata/evidence accepted; generated refresh deferred |
| UID0000CF ScrollablePane class | `000000009328` | `2026-07-13T06:30:00-04:00` | `0 / 1 / 1` | additive support accepted; generated refresh deferred |
| UID0001GL ScrollablePane core | `000000009331` | `2026-07-13T06:30:45-04:00` | `0 / 1 / 1` | additive support accepted; generated refresh deferred |
| UID00011Y compiler index | `000000009333` | `2026-07-13T06:31:30-04:00` | `0 / 1 / 1` | real child relations accepted; generated refresh deferred |
| UID0000VN ignored ranges | `000000009339` | `2026-07-13T06:32:48-04:00` | `0 / 1 / 1` | 18 accepted range rows added; generated refresh deferred |
| UID000252 read-only aggregate | `000000009341` | `2026-07-13T06:33:49-04:00` | `0 / 1 / 1` | vtable-island evidence accepted; generated refresh deferred |
| final UID0000NE waited refresh | `000000009346` | `2026-07-13T06:35:17-04:00` | `0 / 1 / 1` | `generated_refresh: completed` |

- Scoped command IDs are non-contiguous because other agents were validating unrelated files concurrently; every B001 command above exited zero with one scanned page and `ok:1`.
- Final global side-effect counters were `autogen_children_fallback_insert:15`, `autogen_children_marker_missing:83`, `autogen_cpp_update:1` (unrelated UID0000JQ), `autogen_emitter_has_no_code:209`, `autogen_registry_rebuild:1`, `generated_metadata_refresh:279`, `memory_auto_coverage_update:1`, and `projected_stats_update:1`. These were validator-owned effects; B001 manually edited none of their outputs.
- No validator warning or error line occurred. Informational preferred-marker and emitter-no-code rows were global project observations, not failures on the scoped pages.
- Freshness proof: generated `auto-generated/NexusTK/ui/controls/ScrollableControlPane.cpp` header has command `000000009346`, refresh timestamp `2026-07-13T06:35:17-04:00`, refresh source `foreground-generated-refresh`, and file write time `2026-07-13T06:35:27.5247800-04:00`.
- Exact generated counts: class declaration `1`; constructor `1`; ordinary destructor `1`; SetScrollTargetValue `1`; SetScrollCurrentValue `1`; GetScrollMax `1`; GetScrollPosition `1`; UpdateRenderRegion `1`; HandlePointerOrMouseEvent `1`; HandleKeyOrTextEvent `1`; HandlePacketEvent `1`; Enable `1`; Disable `1`; AddToLayer `1`; RemoveFromLayer `1`; OnPaint `1`; HitTestPart `1`.
- Exact prohibited counts: Empty Emitter Marker `0`; GetControlType `0`; scalar-deleting source `0`; adjustor source `0`; aggregate duplicate `0`.

## Changed Files

- Created and registered: `by-memory/0x004985a0-0x00498656.ScrollableControlPaneConstructor.md` (UID0004KC), `by-memory/0x00498660-0x00498695.ScrollableControlPaneDestructor.md` (UID0004KD), `by-memory/0x004986a0-0x004986af.ScrollableControlPaneSetScrollTargetValueRaw.md` (UID0004KE), `by-memory/0x004986b0-0x004986bf.ScrollableControlPaneSetScrollCurrentValueRaw.md` (UID0004KF), `by-memory/0x004986c0-0x004986cf.ScrollableControlPaneGetScrollMaxRaw.md` (UID0004KG), and `by-memory/0x004986d0-0x004986df.ScrollableControlPaneGetScrollPositionRaw.md` (UID0004KH).
- Created and registered: `by-memory/0x004986e0-0x004986fb.ScrollableControlPaneUpdateRenderRegion.md` (UID0004KI), `by-memory/0x00498700-0x00498718.ScrollableControlPaneHandlePointerOrMouseEvent.md` (UID0004KJ), `by-memory/0x00498720-0x00498738.ScrollableControlPaneHandleKeyOrTextEvent.md` (UID0004KK), `by-memory/0x00498740-0x00498758.ScrollableControlPaneHandlePacketEvent.md` (UID0004KL), `by-memory/0x00498760-0x0049877a.ScrollableControlPaneEnable.md` (UID0004KM), and `by-memory/0x00498780-0x0049879a.ScrollableControlPaneDisable.md` (UID0004KN).
- Created and registered: `by-memory/0x004987a0-0x0049885c.ScrollableControlPaneAddToLayer.md` (UID0004KO), `by-memory/0x00498860-0x00498876.ScrollableControlPaneRemoveFromLayer.md` (UID0004KP), `by-memory/0x00498880-0x004988cd.ScrollableControlPaneOnPaint.md` (UID0004KQ), and `by-memory/0x0049afd7-0x0049afed.ScrollableControlPaneAdjustorThunks.md` (UID0004KR).
- Validator-aware renamed while preserving UIDs: `by-memory/0x004985a0-0x004988cc.ScrollableControlPaneCore.md` to `by-memory/0x004985a0-0x004988cd.ScrollableControlPaneCore.md` (UID00011G), and `by-memory/0x0049b900-0x0049b905.ScrollableControlPaneTypeId.md` to `by-memory/0x0049b900-0x0049b905.ScrollableControlPaneHitTestPart.md` (UID0002PE).
- Modified: `by-class/ScrollableControlPane.md` (UID0000CE), `by-file/ScrollableControlPane.md` (UID0000NE), `by-memory/0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor.md` (UID000126), `by-class/ScrollablePane.md` (UID0000CF), `by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md` (UID0001GL), `by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md` (UID00011Y), `by-memory/-ignored.md` (UID0000VN), and `by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md` (UID000252).
- Modified last: this report, after all by-* validation and generated verification.
- Validator-owned generated/coverage/stats/registry outputs changed only through authorized validators and were not manually edited by B001.
- Every one-file lease was released immediately after its scoped validator; `current_leases.md` contains no Agent-B001 entry.
- B001 performed no execute_report, lifecycle, move, or archive command.

## Implementation Tracking Checklist

Initial report-only repair and acceptance phase:

- [x] Exact SHA `1053D9F71128BECE3E2E60D3D3F37A35E0B0A634F4E5C3DCE1B10AEBE1BDD704` was accepted before implementation.
- [x] Target/support set was exact: UID000126, UID0000CE, UID0000NE, UID00011G, 15 source children, one adjustor child, UID0002PE, UID0000CF, UID0001GL, UID00011Y, `by-memory/-ignored.md`, and UID000252.
- [x] Evidence-time database `328356ab`, complete ranges, bytes, xrefs, callers, vtables, helpers, sibling slots, historical generated state, and padding remain recorded.
- [x] C126-001 through C126-045 were retained and are individually applied/verified in the ledger.
- [x] UID0000CE received the exact complete class declaration at position 10.
- [x] UID00011G preserved its UID through exact-end rename and is NONE/false/blank with every real child linked.
- [x] Exactly 15 source children plus one adjustor child were created/registered serially; no UID was fabricated.
- [x] Exact score/metadata dispositions were applied without unrelated inflation.
- [x] Source positions 10 through 170 were applied in exact order.
- [x] Exactly 17 destination-specific managed blocks were applied; report block count remains 17.
- [x] UID00011G, UID000126, and UID0004KR remain blank and non-emitting with complete no-code evidence.
- [x] UID0002PE preserved its UID through rename and now has byte return, two `int` arguments, position 170, and superseded GetControlType history.
- [x] Fifteen internal core pads, two target pads, and the adjustor range were registered in ignored data.
- [x] ScrollablePane fields/helpers, compiler index links, vtable aggregate facts, and file order were added without unrelated score inflation.
- [x] Zero raw refs, compiler-only scalar/adjustors, superseded interpretations, and neighboring exclusions remain preserved.
- [x] Third-party import remains not applicable; no external source was used.
- [x] IDA rename/type/comment mutation remains not applicable; documentation recommendations only.
- [x] Every changed/new ordinary page received one scoped validator after its edit; serial UID capture preceded real links.
- [x] Generated output has all 16 human bodies plus class declaration once and zero stale/compiler/aggregate/type-id emissions.
- [x] No source, score, C++, validation, generated-output, or lease blocker remains; only documented spelling confidence caps remain.

Implementation callback pass:

- [x] Explicit callback authorization was received for the exact accepted SHA.
- [x] C126-001 through C126-045 target/support details were incorporated without compression.
- [x] All 16 new pages were registered serially as UID0004KC through UID0004KR before real links were inserted.
- [x] UID00011G and UID0002PE validator-aware renames preserved their real UIDs and propagated reverse references.
- [x] Every accepted metadata, score, owner, emitter, nesting, position, and C++ change was applied exactly.
- [x] Historical assumptions, rejected alternatives, negative evidence, and zero-route notes were preserved.
- [x] One-file leases were acquired only immediately before edits and released immediately after scoped validators; none remains.
- [x] All 27 command IDs, timestamps, exits, ok counts, and side effects are recorded above.
- [x] Final waited refresh `000000009346` and exact `ScrollableControlPane.cpp` body, marker, source-order, and freshness proof are recorded.
- [x] Remaining unapplied accepted items: none.
- [x] B001 ran no execute_report, lifecycle, move, or archive command.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000009391","destination_path":"executed-b-agent-research/B001/000126-ScrollableControlPaneScalarDeletingDestructor-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/000126-ScrollableControlPaneScalarDeletingDestructor-empty-emitter-source-quality.md","timestamp":"2026-07-13T06:57:05-04:00","uid":"000126"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
