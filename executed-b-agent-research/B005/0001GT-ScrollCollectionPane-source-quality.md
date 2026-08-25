** TARGET-REPORT-UID:0001GT **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0001GT ScrollCollectionPane Ownership / Split Research


## Finalized Report / Current Recommendation

- Current recommendation: retain [UID:0000CG] `ScrollCollectionPane` as the direct canonical owner and emitter for [UID:0001GT], resolve the source route to dedicated `NexusTK/ui/core/ScrollCollectionPane.{h,cpp}`, split every uncovered method body into an exact by-memory child, centralize the class declaration and shared enum/layout in the class H block, and let exact by-memory children own method definitions.
- Final disposition: reconstructable source-authored class aggregate. The broad page should emit only an aggregate covered-by comment; it must not duplicate child bodies. The class page should own the source/header shell and `[[CHILDREN]]` insertion points.
- Implemented callback action: thirteen exact child pages were created, two stale existing child bodies were repaired, class and aggregate CPP/H topology was populated, class/file/layout/vtable support documentation was updated, and every changed ordinary document was serially validated. The complete supervisor-owned IDA handoff and manual coverage rows remain pending for Gate 2B/supervisor handling.
- Confidence: very strong for behavior, class ownership, range boundaries, field layout, vtable facets, child split, and dedicated source placement; strong for human source-facing names and first-draft declarations because original PDB/source symbols are unavailable.

## Supporting Research

- This is the same report artifact for the current assignment. Historical revision SHA256 `DAA4804127E67776E762FA406F555EA1EB0419903D5B64318373F27B9FA9C491` failed the supervisor's exact-artifact Gate 1 audit dated `2026-07-26T00:15:00-04:00`; SHA256 `88A5C96B3A7BDC7A112E9CDD53AF1F109E00990EAE77E6AB06F6E44E75B5850A` then passed `B005 UID0001GT Exact-Artifact Gate 1 Reaudit - 2026-07-26T00:24:43-04:00`. The accepted ordinary/support implementation callback is now applied and serially validated while preserving the original prestate and research. No IDA mutation, manual coverage edit, report lifecycle command, or manual generated-file edit was performed by B005.
- Live read-only IDA MCP database session `f085b224` returned `status:ok`, the expected NexusTK IDB, Hex-Rays readiness, and successful bounded lookup/decompile/xref/data queries. `auto_analysis_ready:false` was recorded as runtime context under the supervisor's explicit override; it did not prevent valid live IDB-backed reads.
- Prior child reports and current documentation were rechecked as evidence rather than accepted as authority. Useful behavior findings were retained; stale no-code, source-placement, helper-name, and EventHandler-slot assumptions are explicitly superseded below.
- Historical Wave2/Wave3 mentions found in older documentation were ignored as stale workflow material.

## Target

- Target UID: `0001GT`.
- Additional target UIDs: none. Related class/file/type/child pages are support destinations, not additional report-coverage declarations.
- Declared-target inventory: [UID:0001GT] `by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md`, a class-range aggregate covering the complete `ScrollCollectionPane` implementation before `ScrollInventoryPane`.
- Target path: `by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`, with zero direct/additional/total B-report coverage at assignment time.
- Assignment-time supervisor classification: reconstructable not-covered by-memory aggregate requiring split completion, source-quality closure, formal class/header topology, and IDA handoff. The ordinary/support split, source-quality, and formal class/header work is now applied; only supervisor-owned IDA/manual-coverage/Gate 2/lifecycle work remains.
- Assignment-time scores and parent state: `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000CG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CG`, blank formal CPP/H.

## Current Target State

- Assignment-time metadata: `87/90`, direct class owner/emitter [UID:0000CG], reconstructable true, no emitter position, blank formal C++.
- Current applied metadata: [UID:0001GT] is `93/93`, remains directly owned/emitted by [UID:0000CG], remains reconstructable, and now carries the accepted aggregate covered-by CPP with blank H. Support state is [UID:0000CG] `93/93`, [UID:0000NG] `91/92`, [UID:0001VZ] `92/93`, [UID:0001YP] `92/94`, and [UID:0003CN] retained `86/90`.
- Pre-callback owner/emitter/reconstructable state: class ownership was correct and the class routed to [UID:0000NG] `by-file/ScrollCollectionPane.md`, but the file page still preserved an obsolete standalone-versus-`ScrollBar.cpp` caveat. Current applied state resolves that caveat: the accepted deterministic route is dedicated `NexusTK/ui/core/ScrollCollectionPane.{h,cpp}`, while `CollectionPane.cpp` and generic `ScrollBar.cpp` remain rejected historical alternatives.
- Assignment-time C++/emitter state: exact children [UID:0001GU], [UID:0003MX], [UID:0003MY], [UID:0001GW], [UID:0001GX], and [UID:0001GY] emitted six bodies into generated `NexusTK/ui/core/ScrollCollectionPane.cpp`; the class, aggregate, layout, and vtable emitters were empty.
- Current applied C++/emitter state: [UID:0000CG] owns the class CPP/H shell, [UID:0001GT] emits only its aggregate covered-by comment, and nineteen exact method children emit one definition each in deterministic positions `5,10,12,14,16,18,20,22,24,26,28,30,40,45,50,60,70,80,90`. The generated CPP/H is current, nonempty, ordered, nonduplicating, human-shaped, and free of empty target markers.
- Pre-callback open questions and stale assumptions, now resolved by the accepted callback: the aggregate incorrectly called `0x00561e51-0x00561ec0` padding plus a setter/stub instead of recognizing two exact raw setters; omitted raw `Disable` and `CanScroll`; called `0x005621a0` a generic Boolean virtual or `CanScroll`; left dedicated source placement unresolved; treated raw no-static-route evidence as a reason to defer C++; left `+0xfa` unresolved; preserved `GetOwnerPane()` in one child; and passed a raw `char` to an enum-typed helper in another child.
- Current applied question state: exact children and formal C++ resolve every listed method/split/range/source-placement/field/callback/enum blocker. Remaining uncertainty is limited to original spelling/access/inlining, seven unrecovered static routes, original source/PDB, and rebuilt-binary comparison; none is an active ownership, source-route, split, score, or first-draft-C++ blocker.
- Related target/support docs checked: [UID:0000CG] class page, [UID:0000NG] file page, [UID:0001VZ] layout, [UID:0001YP] vtables, [UID:0003CN] exact vtable data, CollectionPane class/file/method documentation, Event/EventHandler/TimerHandler/Pane support, ScrollNewGroup and FittingRoom scrollbar siblings, all six existing exact child pages, the broad [UID:0001GV] split index, generated `ScrollCollectionPane.cpp`, manual coverage rows, and matching archived/executed child reports.
- Current artifact/lifecycle status: the exact SHA256 `88A5C96B3A7BDC7A112E9CDD53AF1F109E00990EAE77E6AB06F6E44E75B5850A` revision passed Gate 1 and received the accepted ordinary/support implementation callback. That callback is complete and serially validated. Supervisor Gate 2A/2B verification, supervisor-owned IDA mutation/readback, manual coverage updates, `execute_report`, and archival remain pending.

## Executive Recommendation

- Keep [UID:0000CG] as the direct owner/emitter. No broader file or sibling scrollbar class explains the constructor vtable stores, complete-object offsets, or mutually recursive helper graph better.
- Resolve source placement to dedicated `NexusTK/ui/core/ScrollCollectionPane.h` and `.cpp`. `CollectionPane` constructs and consumes this class but does not own its implementation; `ScrollBar.cpp` is a generic source-family alternative contradicted by the dedicated by-file page, class identity, complete range, and project source-tree convention.
- Create thirteen exact by-memory method children for the currently unsplit functions/raw bodies. Do not create child pages for padding. Do not extend this aggregate into successor `0x00563260`.
- Populate [UID:0000CG] with the class header/source shell and [UID:0001GT] with a formal covered-by comment. Existing and new exact children own all method definitions.
- Raise the aggregate to `93/93`, class to `93/93`, file to `91/92`, layout to `92/93`, and vtable support to `92/94` after implementation and validation. Keep final-audit scores below 95 until rebuilt-binary comparison and final source audit exist.

## Supervisor Active Recheck

- Supervisor instruction rechecked: reconstruct the complete UID0001GT class aggregate, resolve blockers during research, use healthy live IDA MCP read-only evidence, and produce an exhaustive report before any ordinary-document edit.
- Exact failed audit rechecked: `B005 UID0001GT Exact-Artifact Gate 1 Audit - 2026-07-26T00:15:00-04:00`; this revision adds the required per-action IDA prestates/collision proof, removes the unsupported source-size typedef, supplies exact type-coverage payloads, and reconciles report-only checklist state.
- Split repair is mandatory before this aggregate can be considered complete. Seven raw starts and six modeled functions lack exact children; all thirteen have exact boundaries and defensible source roles now.
- Every source-bearing subrange is either an existing exact child, a proposed exact child, or alignment padding. No executable subrange is left as an unexplained future-research item.
- Raw no-route methods remain source-reconstructable because their complete bodies, object-relative fields, neighboring method family, call graph, and exact non-overlapping boundaries are known. Static-route absence affects confidence/original-symbol proof, not source ownership or eligibility.

## Inference Research Guidance Check

- The evidence discipline treats IDA bytes/functions/xrefs/vtable slots as direct facts, current by-* pages as documentation evidence subject to recheck, and names/source layout as explicit inference.
- Existing assumptions treated as uncertain and revalidated: standalone source placement, `+0xfa`, `0x005621a0`, raw-body liveness, class member names, part enum spelling, callback owner API, and whether the broad aggregate should duplicate child C++.
- Direct facts: exact starts/ends/padding, object offsets, vtable stores/slots, caller sets, decompiled control flow, resource strings, global table values, and next-function boundary.
- Documentation evidence: accepted sibling scrollbar source forms, current Pane/Event/CollectionPane APIs, project emitter topology, and existing exact child behavior.
- Inference: `SetSkinIndex`, `SetScrollStyle`, `CanScroll`, `HandlePointerOrMouseEvent`, `HandleKeyOrTextEvent`, field/member spellings, dedicated source filename, and enum constant spellings. Each is chosen from behavior plus current project naming rather than copied from compiler labels.
- Wave2/Wave3 material was encountered in older provenance and ignored.

## Heuristic / Inference Reanalysis And Validation

| Issue | Best defensible resolution | Evidence | Classification / status |
| --- | --- | --- | --- |
| `sub_561DB0` | `ScrollCollectionPane` constructor | `Pane(1)` base call, three class vtable stores, exact 0x110 layout initialization, direct call from CollectionPane constructor | Descriptive source inference; resolved |
| Raw `0x00561e60` | `SetSkinIndex(unsigned short)` | complete isolated body, `this+0xf8` word compare/store, invalidation shape, same field indexes extent table | Descriptive source inference; resolved |
| Raw `0x00561e90` | `SetScrollStyle(unsigned char)` | complete isolated body, `this+0xfa` byte compare/store, invalidation shape, accepted sibling field/setter convention | Descriptive source inference; resolved |
| `+0xfa` | `unsigned char m_scrollStyle` | exact byte setter and sibling ScrollNewGroup/FittingRoom scrollbar layouts | Strong inferred type/name; old padding claim rejected |
| Raw `0x00561f70` | `Disable()` | exact inverse of modeled Enable: state transition to false plus invalidation | Strong source-family inference; resolved |
| Raw `0x00561f90` | `CanScroll() const` | returns `m_scrollEnabled && m_scrollRange > 0`; separate from vtable false stub | Strong behavioral inference; resolved |
| `0x005621a0` | `HandleKeyOrTextEvent(Event *)` returning false | exact EventHandler secondary-vtable slot `+8`, facet at complete-object `+0xa0`, current EventHandler contract | Slot-supported source inference; old `CanScroll`/generic-stub claim rejected |
| `0x005621b0` | `OnTimer(int,int,int)` | TimerHandler facet at `+0xa4`, timer id 0, active-part gate, 30 ms reschedule | Direct behavior plus established API; resolved |
| Input method | `HandlePointerOrMouseEvent(Event *)` | EventHandler-adjusted `this`, event types 0/1/3, mouse capture/release, timer and part helper calls | Strong source-facing inference; resolved |
| Raw helper liveness | retained class methods, exact function creation recommended | complete non-overlapping bodies and internal class-field/callee behavior; no VA/RVA/xref routes | Source ownership resolved; route confidence remains capped |
| `dword_624144` | `const int kScrollPanePartExtentBySkin[3] = {38,38,38}` | exact type/bytes, 22 scroll-family xrefs, use indexed by skin word | Strong contextual name/type inference; resolved |
| Resource string labels | human resource constants | exact wide strings and paint-family use | Safe descriptive rename; resolved |
| Source file | dedicated `ui/core/ScrollCollectionPane.{h,cpp}` | complete self-contained class range, by-file source tree, generic CollectionPane dependency, sibling dedicated control files | High-probability placement; stale merge caveat rejected |
| Existing callback spelling | `static_cast<CollectionPane *>(GetParentPane())->OnScrollPositionChanged(...)` | accepted inherited Pane API and analogous FittingRoom source; current generated `GetOwnerPane()` is unsupported | Source correction; resolved |
| Existing reset local | enum-typed `ScrollCollectionPart oldPart` | field is signed byte holding enum values; `GetPartRect` takes enum | Type correction; resolved |
| Class layout | natural 0x110 C++ layout without explicit source padding | Pane 0xf8 plus typed fields and compiler alignment produces observed offsets | Strong inferred declaration; resolved |
| Aggregate formal C++ | covered-by comment only | exact child ownership prevents body duplication; class owns shell | Emitter-topology resolution |

- Rejected alternative: leave raw starts unsplit because no xrefs exist. This confuses binary static reachability with source ownership and would knowingly omit complete class methods.
- Rejected alternative: emit all methods from the aggregate. This duplicates existing child ownership and destroys exact range-to-source accounting.
- Rejected alternative: route through `CollectionPane.cpp`. The caller/consumer relationship is not ownership, and the target has its own complete class/vtable/layout/source page.
- Rejected alternative: merge with generic `ScrollBar.cpp`. Current dedicated file/class docs and exact ScrollCollection identity are stronger than a broad family resemblance.
- Rejected alternative: preserve `sub_`, `dword_`, and short string labels in final source. Human names are sufficiently inferable and decompiler labels violate source-quality requirements.
- Remaining uncertainty is limited to original spelling/capitalization, exact access specifiers, and whether a few helper calls were inline/member utilities in original source. It does not block a behavior-equivalent human first draft.

## Evidence Standards Used

- IDA MCP evidence: server health, function lookup, entity/type/global/comment state, decompilation, disassembly/raw bytes, xrefs, callers/callees, vtable data refs, and bounded pointer-pattern searches.
- Binary structure evidence: exact function ends, `0xcc` alignment runs, complete raw prologue/epilogue bodies, object offsets, vtable facet offsets, next modeled constructor, and global/string storage.
- Documentation evidence: current by-memory/class/file/type pages, generated C++, current project APIs, and prior child reports rechecked against live IDA.
- Comparative inference: ScrollNewGroup, FittingRoom, and ranking scrollbar implementations establish repeated human source shapes while target bytes control target-specific behavior.
- Negative evidence: no function object, incoming xref, direct branch, or VA/RVA/raw-offset pointer route for seven raw starts; no original symbols/PDB; no evidence for CollectionPane or generic ScrollBar ownership.
- Evidence is strong enough for ownership, split, first-draft source, and low-90 scores. Missing original source/PDB and rebuilt-binary comparison prevent 95+ final-audit scores.

## Evidence Checked

- IDA MCP/manual checks: health on database `f085b224`; lookup/decompile of every modeled start; raw bytes/instruction boundaries for seven unmodeled starts; exact padding between all bodies; xrefs/callers/callees; constructor vtable stores; vtable slot references; UDT prestate; global/table/string names/types/comments/bytes; raw-start VA/RVA/pointer route scans; and successor `0x00563260`.
- Documentation checked: UID0001GT, UID0000CG, UID0000NG, UID0001VZ, UID0001YP, UID0003CN, all existing exact children, broad split index UID0001GV, CollectionPane, Pane/Event/TimerHandler, sibling scroll classes, generated `ScrollCollectionPane.cpp`, manual coverage files, and matching older reports.
- Negative checks: zero incoming xrefs and zero little-endian VA/RVA/raw-offset pointer hits for `0x00561e60`, `0x00561e90`, `0x00561f70`, `0x00561f90`, `0x00562e80`, `0x00562ef0`, and `0x00563200`; no executable continuation through any padding; no cross-owner method after `0x0056325c`.
- Failed/unavailable checks: original source/PDB and rebuilt-object comparison do not exist. They are final-audit evidence, not prerequisites for current reconstruction. No MCP query required for this report repeatedly failed.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C1GT-01 | 0001GT | Exact aggregate range is `[0x00561db0,0x0056325c)` and successor starts at `0x00563260` | very strong | function/raw boundaries and four-byte final padding | target Boundary/Inventory | replace stale range narrative | applied and scoped-validator verified in UID0001GT |
| C1GT-02 | 0001GT | Four previously hidden raw methods exist at e60/e90/f70/f90 | strong | complete raw bodies, field effects, padding isolation | target Covered Functions/Boundary | add exact rows and children | applied and scoped-validator verified in UID0001GT and UIDs 0004X4/0004X6/0004XA/0004XB |
| C1GT-03 | 0001GT | Thirteen currently unsplit bodies need exact children | very strong | complete function map | target, class, new child docs | create children with validator-assigned UIDs | applied as UIDs 0004X3, 0004X4, 0004X6-0004XB, and 0004XL-0004XP; each scoped-validator verified |
| C1GT-04 | 0001GT | Direct owner/emitter remains UID0000CG | very strong | vtables, object layout, helper graph | target metadata/status | retain | applied and scoped-validator verified |
| C1GT-05 | 0001GT | Dedicated source route is `NexusTK/ui/core/ScrollCollectionPane.{h,cpp}` | strong | by-file route and class cohesion | UID0000NG source placement | resolve old caveat | applied and scoped-validator verified in UID0000NG |
| C1GT-06 | 0001GT | Aggregate CPP is covered-by comment; class CPP/H owns shell | very strong | emitter hierarchy | target/class formal blocks | populate | applied and generated CPP/H verified |
| C1GT-07 | 0001GT | `+0xfa` is `m_scrollStyle`, not padding | strong | raw setter and siblings | target/class/layout | document/type | applied and scoped-validator verified in UID0001GT/0000CG/0001VZ/0004X6 |
| C1GT-08 | 0001GT | `0x005621a0` is EventHandler key/text false method, not `CanScroll` | very strong | vtable slot and facet | target/class/vtable/new child | correct | applied and scoped-validator verified in UID0001GT/0000CG/0001YP/0003CN/0004XM |
| C1GT-09 | 0001GT | `0x00561f90` is the real `CanScroll() const` | strong | exact predicate body | target/class/new child | document/emit | applied and scoped-validator verified in UID0004XB and support docs |
| C1GT-10 | 0001GT | Existing UpdatePosition body must use `GetParentPane()` and signed `short` | strong | Pane API, CollectionPane callback, binary field width | UID0001GX CPP/docs | repair | applied, scoped-validator verified, and generated source verified |
| C1GT-11 | 0001GT | Existing Reset body needs enum-typed local/casts | strong | field/helper contract | UID0001GY CPP/docs | repair | applied, scoped-validator verified, and generated source verified |
| C1GT-12 | 0001GT | Global extent table is const 3-entry skin table | very strong | bytes/type/xrefs | layout/class/IDA | rename/type/document | ordinary documentation applied and validated; supervisor-owned IDA action/readback pending |
| C1GT-13 | 0001GT | Paint resources have human wide-string identities | very strong | exact strings/xrefs | paint child/class/IDA | rename/comment | ordinary documentation applied and validated; supervisor-owned IDA action/readback pending |
| C1GT-14 | 0001GT | Class natural layout is exactly 0x110 | very strong | offsets and Pane size 0xf8 | UID0001VZ/class H | populate fields/assertion | applied and scoped-validator/generated-header verified without SizeMustBe typedef |
| C1GT-15 | 0001GT | Raw no-route evidence caps confidence but does not justify no-code | strong | negative route scan plus complete bodies | target/history/score | preserve correctly | applied and retained in aggregate/raw children/history sections |
| C1GT-16 | 0001GT | Scores can move to low 90s after split/source/IDA closure | strong | blockers resolved and exact payloads ready | all support metadata/coverage | apply after validation | ordinary-document scores applied and validated; supervisor-owned manual coverage rows pending |

## Positive Evidence Summary

- The constructor is directly called from CollectionPane and stores all three ScrollCollectionPane vtables before initializing a coherent 0x110 object.
- Every body in the aggregate reads/writes the same field cluster and participates in one closed hit-test, geometry, highlight, active-part, drag, timer, paint, and owner-callback graph.
- Exact modeled callers exist for constructor, range/position/enable setters, virtual handlers, vtable entries, and internal helpers.
- Seven raw starts are complete function-shaped bodies bounded by alignment and class-local behavior, not random bytes or mixed data.
- The extent table, resource strings, accepted sibling scrollbar code, and current project APIs resolve the remaining human source vocabulary without retaining IDA labels.
- Dedicated class/file/layout/vtable docs already exist, so source placement and emitter topology have a coherent project destination.

## IDA MCP Facts

- Function/range facts: modeled starts and exact exclusive ends are ctor `561db0-561e51`, SetMax `561ec0-561f1b`, SetPosition `561f20-561f47`, Enable `561f50-561f6a`, input `561fb0-562191`, false EventHandler slot `5621a0-5621a5`, timer `5621b0-5621e3`, paint `5621f0-5628d0`, HitTest `5628d0-562bed`, GetPartRect `562bf0-562e77`, UpdateDrag `562fb0-563070`, and UpdatePosition `563070-5631fd`. Raw starts are `561e60-561e87`, `561e90-561eb4`, `561f70-561f8a`, `561f90-561faa`, `562e80-562ef0`, `562ef0-562fb0`, and `563200-56325c`.
- Data/table/padding facts: all inter-body gaps are `0xcc` alignment; final `56325c-563260` is four `0xcc` bytes. `0x00624144` is current `int[3]` bytes `{38,38,38}`. Wide resource strings are exact at `0x0060ddb0`, `0x0060ddc8`, `0x0060dde0`, and `0x0060ddf8`.
- Xref facts: ctor caller `0x0056e9b6`; SetMax caller `0x0056ed36`; SetPosition callers `0x0056eda2`, `0x0056f72a`, `0x0056faac`; Enable caller `0x0056e9cb`; primary/EventHandler/TimerHandler vtable refs at `0x00623fe8`, `0x00623ff4/ff8`, and `0x00624024`; HitTest callers `0x00562091`, `0x0056301f`; GetPartRect has thirteen internal refs.
- Vtable/global/type facts: constructor stores decorated vtables at `0x00623fa4`, `0x00623ff0`, and `0x00624020` into offsets `0`, `0xa0`, and `0xa4`. Existing `Pane` UDT size is `0xf8`; `Point` is size 8 with y@0/x@4; `RectBounds` is size 16; Event payload pointer coordinates are y@8/x@c.
- Negative IDA facts: no current `ScrollCollectionPane` or `ScrollCollectionPart` UDT; no modeled functions or incoming xrefs/pointer routes for the seven raw starts; no original symbols; current modeled function comments are empty.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `561db0-561e51` | UID0004X3 `ScrollCollectionPaneConstructor.md` | constructor | yes | 0000CG | 92/94 | created and validated |
| `561e60-561e87` | UID0004X4 `ScrollCollectionPaneSetSkinIndexRaw.md` | skin setter | yes | 0000CG | 89/92 | created and validated |
| `561e90-561eb4` | UID0004X6 `ScrollCollectionPaneSetScrollStyleRaw.md` | style setter | yes | 0000CG | 89/92 | created and validated |
| `561ec0-561f1b` | UID0004X7 `ScrollCollectionPaneSetMaxRange.md` | clamp/store/invalidate | yes | 0000CG | 92/94 | created and validated |
| `561f20-561f47` | UID0004X8 `ScrollCollectionPaneSetScrollPosition.md` | position setter | yes | 0000CG | 91/94 | created and validated |
| `561f50-561f6a` | UID0004X9 `ScrollCollectionPaneEnable.md` | enable | yes | 0000CG | 91/94 | created and validated |
| `561f70-561f8a` | UID0004XA `ScrollCollectionPaneDisableRaw.md` | disable | yes | 0000CG | 89/92 | created and validated |
| `561f90-561faa` | UID0004XB `ScrollCollectionPaneCanScrollRaw.md` | enabled/range predicate | yes | 0000CG | 90/93 | created and validated |
| `561fb0-562191` | UID0004XL `ScrollCollectionPaneHandlePointerOrMouseEvent.md` | mouse interaction | yes | 0000CG | 92/94 | created and validated |
| `5621a0-5621a5` | UID0004XM `ScrollCollectionPaneHandleKeyOrTextEvent.md` | false EventHandler slot | yes | 0000CG | 91/94 | created and validated |
| `5621b0-5621e3` | UID0004XN `ScrollCollectionPaneOnTimer.md` | repeat timer | yes | 0000CG | 91/94 | created and validated |
| `5621f0-5628d0` | UID0004XO `ScrollCollectionPaneOnPaint.md` | track/thumb render | yes | 0000CG | 92/94 | created and validated |
| `5628d0-562bed` | UID0001GU | hit test | yes | 0000CG | 91/91 | support synchronized and validated |
| `562bf0-562e77` | UID0004XP `ScrollCollectionPaneGetPartRect.md` | geometry | yes | 0000CG | 92/94 | created and validated |
| `562e80-562ef0` | UID0003MX | highlight transition | yes | 0000CG | 90/91 | support synchronized and validated |
| `562ef0-562fb0` | UID0003MY | begin interaction | yes | 0000CG | 90/91 | support synchronized and validated |
| `562fb0-563070` | UID0001GW | update active drag | yes | 0000CG | 91/91 | support synchronized and validated |
| `563070-5631fd` | UID0001GX | cursor-to-position | yes | 0000CG | 92/91 | callback/type repaired and validated |
| `563200-56325c` | UID0001GY | reset interaction | yes | 0000CG | 90/90 | enum typing repaired and validated |
| alignment gaps | no page | compiler padding | no source body | none | n/a | preserve as boundary evidence only |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00561db0` | caller `0x0056e9b6` | CollectionPane constructs the scroll child |
| `0x00561ec0` | caller `0x0056ed36` | owner updates maximum range |
| `0x00561f20` | callers `0x0056eda2`, `0x0056f72a`, `0x0056faac` | owner/layout and callback paths set current position |
| `0x00561f50` | caller `0x0056e9cb` | CollectionPane enables initialized child |
| `0x00561fb0` | vtable ref `0x00623ff4` | EventHandler pointer/mouse facet method |
| `0x005621a0` | vtable ref `0x00623ff8` | EventHandler key/text facet method |
| `0x005621b0` | vtable ref `0x00624024` | TimerHandler callback |
| `0x005621f0` | vtable ref `0x00623fe8` | primary paint virtual |
| `0x005628d0` | callers `0x00562091`, `0x0056301f` | input and drag logic hit-test parts |
| `0x00562bf0` | thirteen target-internal refs | common geometry service for paint and interaction |
| `0x00562fb0` | input, timer, raw begin-interaction callers | repeated press/drag update hub |
| `0x00563070` | two calls from UpdateDragScroll | converts pointer position to owner callback |
| raw starts | no incoming xrefs/pointer hits | original/static route unavailable; bounded source roles still established |

## Documentation Evidence And IDA Status

- Existing docs supporting the conclusion: class, file, layout, vtable, exact children, CollectionPane construction/callback pages, and sibling scrollbar pages consistently identify one 0x110 themed scroll control.
- Existing docs stale/incomplete: target/class/file score rationales preserve resolved source-placement and raw-name blockers; target inventory omits four raw methods; target labels the key/text virtual generically; layout leaves `+0xfa` weak; generated class shell is empty; two child first drafts contain API/type defects.
- Generated/coverage state: `auto-generated/NexusTK/ui/core/ScrollCollectionPane.cpp` contains six child bodies followed by empty class/aggregate/layout/vtable markers. Manual by-memory row uses stale exclusive end `0x0056325b` and 78%; class/file rows are 82% and preserve obsolete no-final-C++ wording.
- Current IDA status: modeled functions remain compiler labels; seven safe function objects are absent; class enum/UDT are absent; global/string labels are compiler-generated; decorated vtable names are present and must be protected.

## Ranked Ownership Analysis

### 1. UID0000CG ScrollCollectionPane

- Evidence for: exact class vtables, coherent 0x110 layout, complete method cluster, constructor caller, field graph, and dedicated class/file/type documents.
- Evidence against: original source symbols are absent and seven raw methods have no static entry route.
- Decision: selected direct owner/emitter. Negative route evidence does not outweigh complete class identity.

### 2. UID0000NG dedicated ScrollCollectionPane source file

- Evidence for: existing by-file page, current proposed `ui/core` path, complete self-contained class range, and project source-tree convention.
- Evidence against: source filename is inferred rather than symbol-proven.
- Decision: selected source module/container; class remains direct semantic owner.

### 3. CollectionPane.cpp or generic ScrollBar.cpp

- Evidence for: CollectionPane constructs/uses the control; other scrollbar implementations share substantial source shape.
- Evidence against: consumer calls do not establish implementation ownership; generic siblings have independent vtables/ranges/classes; a dedicated ScrollCollectionPane file page and exact class identity already exist.
- Decision: rejected.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: existing [UID:0000NG], emitted as `NexusTK/ui/core/ScrollCollectionPane.cpp` and `.h`.
- Likely full contents: includes, `ScrollCollectionPart` enum, `ScrollCollectionPane` declaration/layout, shared extent-table declaration, and all exact child method definitions.
- Candidate related items that belong: UID0000CG class shell, UID0001GT covered-by aggregate, UID0001VZ layout declaration, UID0001YP/UID0003CN vtable documentation support, existing exact children, and thirteen new method children.
- Candidate related items rejected: CollectionPane implementation, ScrollNewGroup/FittingRoom/Ranking sibling methods, and successor ScrollInventoryPane.
- Source-file inference: dedicated narrow class implementation in generic UI core.

## Source Placement

- Recommended placement: `NexusTK/ui/core/ScrollCollectionPane.h` and `.cpp` under existing file owner UID0000NG.
- This placement fits the generic UI dependency direction: CollectionPane owns/uses a ScrollCollectionPane child, while the control itself depends on Pane, Event, TimerHandler behavior, EPF rendering resources, and CollectionPane only for the position-change callback.
- `CollectionPane.cpp` is rejected because it would make a reusable control implementation private to a consumer. `ScrollBar.cpp` is rejected because current project docs already model distinct classes/files and no binary evidence merges them.
- Remaining uncertainty: the original project might have used a nearby filename spelling, but not a different semantic owner. The current dedicated path is the highest-probability human source reconstruction.

## Range / Split / Padding / Reclassification Analysis

- Exact range: source-bearing aggregate `[0x00561db0,0x0056325c)`. `0x0056325c-0x00563260` is alignment; `0x00563260` begins ScrollInventoryPane.
- Exact alignment gaps: `561e51-561e60` 15 bytes, `561e87-561e90` 9, `561eb4-561ec0` 12, `561f1b-561f20` 5, `561f47-561f50` 9, `561f6a-561f70` 6, `561f8a-561f90` 6, `561faa-561fb0` 6, `562191-5621a0` 15, `5621a5-5621b0` 11, `5621e3-5621f0` 13, `562bed-562bf0` 3, `562e77-562e80` 9, `5631fd-563200` 3, `56325c-563260` 4.
- Children to create: exact pages for the thirteen rows marked proposed in the inventory. New pages must receive validator-assigned UIDs; this report does not guess identifiers.
- Existing children to retain: UID0001GU, UID0003MX, UID0003MY, UID0001GW, UID0001GX, UID0001GY. UID0001GV remains a non-emitting split index over UID0003MX/MY.
- Reclassification: none of the seven raw methods should be non-reconstructable. They are exact source-authored bodies with missing IDA function objects/static route, not compiler-only thunks or data.
- Parent/container impact: class UID0000CG owns declarations and child insertion; aggregate UID0001GT becomes a non-duplicating covered-by emitter marker with improved documentation.

## Negative Evidence Summary

- No original PDB, map, headers, or source symbols prove exact spelling.
- Seven raw starts have no modeled function, incoming xref, direct branch/call route, or VA/RVA/raw-offset pointer hit.
- Those negatives do not show data or compiler glue: each raw range is isolated by alignment, has a complete return path, operates on ScrollCollectionPane fields, and mirrors established class/sibling methods.
- Nearby ScrollNewGroup/FittingRoom/Ranking methods prove source-family plausibility, not byte identity or ownership; target IDA facts remain controlling.
- CollectionPane callsites prove construction/consumption, not ownership of the control's implementation.
- Decorated vtable symbols are compiler-derived but valuable exact class evidence; they must not be replaced with speculative source-global names.

## IDA Rename / Type / Comment Recommendations

The supervisor should apply these actions only after Gate 1 acceptance and record exact readback. Comment-channel abbreviations below are `AR` (address regular), `AP` (address repeatable), `FR` (function regular), and `FP` (function repeatable). Literal `""` means the live channel is present and empty; `n/a` means the entity is not currently a modeled function, so no function-comment channel exists.

Live name-index/collision precheck on database `f085b224`: address lookups resolve every modeled current `sub_*` name at the exact start below; all seven raw starts have no current name/function; exact lookup of all nineteen proposed `ScrollCollectionPane__*` names returned `Not found`; exact name-index regex for the five proposed `k*` data/string names returned zero rows; `type_inspect` reports both proposed type names absent. Current data/string/vtable names resolve only at the listed action addresses. Therefore each rename/create name below has no current collision, while I26-I28 deliberately keep their existing decorated names.

| Action | Exact current item/range, size, width, name-index and type pre-state | Four literal comment channels | Proposed action and expected readback | Evidence/confidence |
| --- | --- | --- | --- | --- |
| I1 | modeled function `[0x00561db0,0x00561e51)`, `0xa1`/161 bytes; name `sub_561DB0` resolves at start; type `int __thiscall(int this, char orientation)` with 32-bit return/this and 8-bit argument; proposed name collision none | `AR=""`; `AP=""`; `FR=""`; `FP=""` | rename `ScrollCollectionPane__Constructor`; type `ScrollCollectionPane *__thiscall(ScrollCollectionPane *this, unsigned char orientation)`; AP `Constructs a 0x110-byte ScrollCollectionPane and installs primary, EventHandler, and TimerHandler vtables.`; read back same range and 32-bit pointer return | ctor/vtables/layout/caller; very strong |
| I2 | raw code `[0x00561e60,0x00561e87)`, `0x27`/39 bytes; current function/name/type absent; proposed name collision none; observed 32-bit `this`, 16-bit argument, void tail-jump behavior | `AR=""`; `AP=""`; `FR=n/a`; `FP=n/a` | create only this exact function; rename `ScrollCollectionPane__SetSkinIndex`; type `void __thiscall(ScrollCollectionPane *this, unsigned short skinIndex)`; AP `Updates the skin-index word at +0xf8 and invalidates on change; no static entry route is currently known.`; read back end `0x00561e87` without padding | exact body/field; strong |
| I3 | raw code `[0x00561e90,0x00561eb4)`, `0x24`/36 bytes; function/name/type absent; proposed name collision none; 32-bit `this`, 8-bit argument, void tail-jump behavior | `AR=""`; `AP=""`; `FR=n/a`; `FP=n/a` | create exact function; rename `ScrollCollectionPane__SetScrollStyle`; type `void __thiscall(ScrollCollectionPane *this, unsigned char scrollStyle)`; AP `Updates the scroll-style byte at +0xfa and invalidates on change; no static entry route is currently known.`; read back exact end `0x00561eb4` | exact body/+fa/siblings; strong |
| I4 | modeled `[0x00561ec0,0x00561f1b)`, `0x5b`/91 bytes; `sub_561EC0` resolves at start; `int __thiscall(_WORD *this, __int16 maxRange)`, 32-bit return/this and 16-bit argument; proposed collision none | `AR=""`; `AP=""`; `FR=""`; `FP=""` | rename `ScrollCollectionPane__SetMaxRange`; type `void __thiscall(ScrollCollectionPane *this, short maxRange)`; AP `Clamps range to 0..30000, clamps current position through its setter, stores the range, and invalidates.`; read back same range and void return | direct decompile/caller; very strong |
| I5 | modeled `[0x00561f20,0x00561f47)`, `0x27`/39 bytes; `sub_561F20`; `__int16 __thiscall(_WORD *this, __int16 position)`, 16-bit return/arg and 32-bit this; proposed collision none | `AR=""`; `AP=""`; `FR=""`; `FP=""` | rename `ScrollCollectionPane__SetScrollPosition`; type `void __thiscall(ScrollCollectionPane *this, short position)`; AP `Stores the signed scroll position at +0xfe and invalidates the pane bounds.`; read back same range/void | direct body/callers; very strong |
| I6 | modeled `[0x00561f50,0x00561f6a)`, `0x1a`/26 bytes; `sub_561F50`; `int __thiscall(_BYTE *this)`, 32-bit return/this; proposed collision none | `AR=""`; `AP=""`; `FR=""`; `FP=""` | rename `ScrollCollectionPane__Enable`; type `void __thiscall(ScrollCollectionPane *this)`; AP `Sets +0x102 true and invalidates only on a false-to-true transition.`; read back same range/void | body/caller; very strong |
| I7 | raw `[0x00561f70,0x00561f8a)`, `0x1a`/26 bytes; function/name/type absent; 32-bit this/void; proposed collision none | `AR=""`; `AP=""`; `FR=n/a`; `FP=n/a` | create exact function; rename `ScrollCollectionPane__Disable`; type `void __thiscall(ScrollCollectionPane *this)`; AP `Sets +0x102 false and invalidates only on a true-to-false transition; no static entry route is currently known.`; read back exact end | inverse state body; strong |
| I8 | raw `[0x00561f90,0x00561faa)`, `0x1a`/26 bytes; function/name/type absent; 32-bit const this, 8-bit bool return; proposed collision none | `AR=""`; `AP=""`; `FR=n/a`; `FP=n/a` | create exact function; rename `ScrollCollectionPane__CanScroll`; type `bool __thiscall ScrollCollectionPane__CanScroll(const ScrollCollectionPane *this)`; AP `Returns enabled && signed range > 0; no static entry route is currently known.`; read back exact predicate and end | exact predicate; strong |
| I9 | modeled `[0x00561fb0,0x00562191)`, `0x1e1`/481 bytes; `sub_561FB0`; `char __thiscall(int this, int event)`, 8-bit return and 32-bit values; proposed collision none | `AR=""`; `AP=""`; `FR=""`; `FP=""` | rename `ScrollCollectionPane__HandlePointerOrMouseEvent`; type `bool __thiscall(EventHandler *this, Event *event)`; AP `EventHandler-adjusted this is complete object +0xa0; handles pointer move/down/up, capture, drag, and repeat timer.`; read back same range/bool/pointers | vtable/decompile; very strong |
| I10 | modeled `[0x005621a0,0x005621a5)`, `0x5`/5 bytes; `sub_5621A0`; `char __stdcall(int event)`, 8-bit return/32-bit stack argument because unused this was not recovered; proposed collision none | `AR=""`; `AP=""`; `FR=""`; `FP=""` | rename `ScrollCollectionPane__HandleKeyOrTextEvent`; type `bool __thiscall(EventHandler *this, Event *event)`; AP `EventHandler secondary slot +8; returns false.`; read back same five bytes and EventHandler facet contract | exact vtable slot; very strong |
| I11 | modeled `[0x005621b0,0x005621e3)`, `0x33`/51 bytes; `sub_5621B0`; `char __thiscall(TimerHandler *this,int timerId,int arg0,int arg1)`, 8-bit return and 32-bit pointer/arguments; proposed collision none | `AR=""`; `AP=""`; `FR=""`; `FP=""` | rename `ScrollCollectionPane__OnTimer`; type `bool __thiscall(TimerHandler *this, int timerId, int arg0, int arg1)`; AP `TimerHandler-adjusted this is complete object +0xa4; timer 0 updates the active part and reschedules after 30 ms.`; read back same range | vtable/decompile; very strong |
| I12 | modeled `[0x005621f0,0x005628d0)`, `0x6e0`/1760 bytes; `sub_5621F0`; `void __thiscall(int this)`, 32-bit this; proposed collision none | `AR=""`; `AP=""`; `FR=""`; `FP=""` | rename `ScrollCollectionPane__OnPaint`; type `void __thiscall(ScrollCollectionPane *this)`; AP `Paints enabled scrollbar track portions and highlighted thumb from SLIDEBG/SCRBUTT resources.`; read back same range/void | vtable/decompile/resources; very strong |
| I13 | modeled `[0x005628d0,0x00562bed)`, `0x31d`/797 bytes; `sub_5628D0`; `char __thiscall(int this,int localY,int localX)`, 8-bit current return and 32-bit this/arguments; proposed collision none | `AR=""`; `AP=""`; `FR=""`; `FP=""` | rename `ScrollCollectionPane__HitTestScrollRegion`; type `ScrollCollectionPart __thiscall(ScrollCollectionPane *this, int localY, int localX)`; AP `Returns the first of five scrollbar parts containing the local point, or none.`; read back same range/32-bit enum return | two callers/full body; very strong |
| I14 | modeled `[0x00562bf0,0x00562e77)`, `0x287`/647 bytes; `sub_562BF0`; `void __thiscall(int this,char part,RectBounds *bounds)`, 32-bit this/out pointer and 8-bit current part; proposed collision none | `AR=""`; `AP=""`; `FR=""`; `FP=""` | rename `ScrollCollectionPane__GetPartRect`; type `void __thiscall(ScrollCollectionPane *this, ScrollCollectionPart part, RectBounds *bounds)`; AP `Computes leading/page/thumb/trailing geometry for the current orientation and drag state.`; read back same range/enum argument | thirteen refs/full body; very strong |
| I15 | raw `[0x00562e80,0x00562ef0)`, `0x70`/112 bytes; function/name/type absent; 32-bit this, 32-bit source enum argument, void; proposed collision none | `AR=""`; `AP=""`; `FR=n/a`; `FP=n/a` | create exact function; rename `ScrollCollectionPane__SetHighlightedPart`; type `void __thiscall(ScrollCollectionPane *this, ScrollCollectionPart part)`; AP `Invalidates old/new non-none part rectangles and stores the highlighted part; no static entry route is known.`; read back exact end | accepted child/live bytes; strong |
| I16 | raw `[0x00562ef0,0x00562fb0)`, `0xc0`/192 bytes; function/name/type absent; 32-bit this/enum/mouseY/mouseX, void; proposed collision none | `AR=""`; `AP=""`; `FR=n/a`; `FP=n/a` | create exact function; rename `ScrollCollectionPane__BeginPartInteraction`; type `void __thiscall(ScrollCollectionPane *this, ScrollCollectionPart part, int mouseY, int mouseX)`; AP `Initializes thumb drag offset, active/highlight state, immediate update, and repeat timer; no static entry route is known.`; read back exact end | accepted child/live bytes; strong |
| I17 | modeled `[0x00562fb0,0x00563070)`, `0xc0`/192 bytes; `sub_562FB0`; `char __thiscall(int this)`, 8-bit return/32-bit this; proposed collision none | `AR=""`; `AP=""`; `FR=""`; `FP=""` | rename `ScrollCollectionPane__UpdateDragScroll`; type `void __thiscall(ScrollCollectionPane *this)`; AP `Processes thumb drag or repeated page/edge action and clears stale highlight.`; read back same range/void | caller/callee graph; very strong |
| I18 | modeled `[0x00563070,0x005631fd)`, `0x18d`/397 bytes; `sub_563070`; `int __thiscall(int this,int localY,int localX)`, 32-bit return/this/arguments; proposed collision none | `AR=""`; `AP=""`; `FR=""`; `FP=""` | rename `ScrollCollectionPane__UpdatePositionFromCursor`; type `void __thiscall(ScrollCollectionPane *this, int localY, int localX)`; AP `Converts cursor position to signed scroll position and notifies parent CollectionPane on change.`; read back same range/void | exact body/callers; very strong |
| I19 | raw `[0x00563200,0x0056325c)`, `0x5c`/92 bytes; function/name/type absent; 32-bit this/void; proposed collision none | `AR=""`; `AP=""`; `FR=n/a`; `FP=n/a` | create exact function; rename `ScrollCollectionPane__ResetScrollState`; type `void __thiscall(ScrollCollectionPane *this)`; AP `Removes pending timers, clears active/highlight parts, and invalidates the old highlighted rectangle; no static entry route is known.`; read back end `0x0056325c` | complete body/padding; strong |
| I20 | data `[0x00624144,0x00624150)`, `0xc`/12 bytes, three 32-bit elements; current name `dword_624144` resolves here; type text `int[3]`; bytes `{38,38,38}`; proposed data-name collision none | `AR=""`; `AP=""`; `FR=n/a`; `FP=n/a` | rename `kScrollPanePartExtentBySkin`; type `const int[3]`; AP `Scrollbar fixed part/thumb extent indexed by skin.`; read back unchanged 12 bytes/three elements | 22 xrefs/values; very strong |
| I21 | UTF-16LE string `[0x0060ddb0,0x0060ddc8)`, `0x18`/24 bytes, twelve 16-bit elements including NUL; current name `aSl_1`; current type text `const wchar_t[]`; bytes spell `L"SLIDEBG.EPF"`; proposed collision none | `AR=""`; `AP=""`; `FR=n/a`; `FP=n/a` | rename `kScrollBackgroundImageName`; retain 16-bit const wide-string type; AP `Scrollbar track EPF resource name.`; read back same range/bytes | exact string/paint refs; very strong |
| I22 | UTF-16LE string `[0x0060ddc8,0x0060dde0)`, `0x18`/24 bytes, twelve 16-bit elements including NUL; `aSl_2`; `const wchar_t[]`; `L"SLIDEBG.PAL"`; proposed collision none | `AR=""`; `AP=""`; `FR=n/a`; `FP=n/a` | rename `kScrollBackgroundPaletteName`; retain type; AP `Scrollbar track palette resource name.`; unchanged range/bytes | exact string/paint refs; very strong |
| I23 | UTF-16LE string `[0x0060dde0,0x0060ddf8)`, `0x18`/24 bytes, twelve 16-bit elements including NUL; `aSc_0`; `const wchar_t[]`; `L"SCRBUTT.EPF"`; proposed collision none | `AR=""`; `AP=""`; `FR=n/a`; `FP=n/a` | rename `kScrollButtonImageName`; retain type; AP `Scrollbar thumb EPF resource name.`; unchanged range/bytes | exact string/paint refs; very strong |
| I24 | UTF-16LE string `[0x0060ddf8,0x0060de0e)`, `0x16`/22 bytes, eleven 16-bit elements including NUL; `aBu`; `const wchar_t[]`; `L"BUTTON.PAL"`; proposed collision none | `AR=""`; `AP=""`; `FR=n/a`; `FP=n/a` | rename `kButtonPaletteName`; retain type; AP `Button palette resource name used by scrollbar thumb rendering.`; unchanged range/bytes | exact string/paint refs; very strong |
| I25 | type-index entities: `ScrollCollectionPane` absent and `ScrollCollectionPart` absent with no type-name collision. Protected dependencies: `Pane` UDT size `0xf8`, one member `_paneBase` at `0x0`, size `0xf8`, type `unsigned __int8[248]`; `Point` UDT size 8, `int y@0`, `int x@4`; `RectBounds` size `0x10`, `int left@0`, `top@4`, `right@8`, `bottom@c`; `Event` size `0x110`, `void *vftable@0`, `EventType m_type@4` (size 4), `EventPayload m_payload@8` (size `0x108`); `EventPointerPayload` size `0x14`, `int m_y@0`, `m_x@4`, byte modifiers/padding and 32-bit detail/time; `EventHandler` exists as current 4-byte pointer-type declaration with no members; `TimerHandler` UDT size 4 with protected `void *vftable@0`; `CollectionPane` type absent | `AR=n/a`; `AP=n/a`; `FR=n/a`; `FP=n/a` | create enum values `0..4,-1`; create only new 0x110 `ScrollCollectionPane` UDT with protected Pane base bytes `[0,f8)`, members `unsigned short@f8`, `unsigned char@fa`, `bool@fb`, `unsigned char@fc`, natural pad `fd`, `short@fe`, `short@100`, `bool@102`, `signed char@103`, `signed char@104`, natural pad `105-107`, protected existing `Point@108`; do not alter/redeclare any dependency; read back exact size/member offsets | exact offsets/type-index checks; very strong |
| I26 | named data item `[0x00623fa4,0x00623fa8)`, 4-byte pointer width, inside protected primary facet span `[0x00623fa4,0x00623ff0)` size `0x4c`; current unique name `??_7ScrollCollectionPane@@6B@` resolves at start; type absent; no rename proposed | `AR=""`; `AP=""`; `FR=n/a`; `FP=n/a` | keep decorated name/type state; set AP `Primary ScrollCollectionPane vtable installed at complete-object +0.`; read back exact name/address/comment and unchanged pointer bytes | ctor store/slots; very strong |
| I27 | named data item `[0x00623ff0,0x00623ff4)`, 4-byte pointer width, inside EventHandler facet span `[0x00623ff0,0x00624020)` size `0x30`; unique `??_7ScrollCollectionPane@@6B@_0` resolves here; type absent; no rename | `AR=""`; `AP=""`; `FR=n/a`; `FP=n/a` | keep name/type; set AP `EventHandler facet vtable installed at complete-object +0xa0.`; exact readback | ctor store/slots; very strong |
| I28 | named data item `[0x00624020,0x00624024)`, 4-byte pointer width, inside TimerHandler facet span `[0x00624020,0x00624028)` size 8; unique `??_7ScrollCollectionPane@@6B@_1` resolves here; type absent; no rename | `AR=""`; `AP=""`; `FR=n/a`; `FP=n/a` | keep name/type; set AP `TimerHandler facet vtable installed at complete-object +0xa4.`; exact readback | ctor store/slots; very strong |

- Required supporting type invariants: `sizeof(ScrollCollectionPane)==0x110`; Pane base size `0xf8`; Point y@0/x@4 size 8; RectBounds 16 bytes; enum storage in fields remains signed byte while method parameter/return uses enum.
- Negative constraints: do not create functions across any listed `0xcc` gap; do not include successor `0x00563260`; do not rename decorated vtables; do not invent source vptr fields; do not change raw bytes; do not force unrelated sibling globals into this class; do not retain `sub_`/`dword_` names after accepted actions.
- Supervisor action classification: I1-I25 and vtable comments I26-I28 are `apply` after Gate 1; decorated vtable names are `already present/protected`; no B-agent mutation is permitted.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. Exact behavior, source class, field layout, and child boundaries are sufficiently resolved.
- Aggregate UID0001GT CPP block disposition:

```cpp
// Emitted code for this aggregate is covered by [UID:0000CG];
// exact by-memory children own each ScrollCollectionPane method body.
```

- Aggregate UID0001GT H block disposition: blank because the class emitter [UID:0000CG] owns the declaration.
- Class UID0000CG CPP block insertion text:

```cpp
#include "ScrollCollectionPane.h"

#include "CollectionPane.h"
#include "Event.h"
#include "../../render/EPFTileContext.h"

const int kScrollPanePartExtentBySkin[3] = { 38, 38, 38 };

[[CHILDREN]]
```

- Class UID0000CG H block insertion text:

```cpp
#pragma once

#include "Pane.h"

class CollectionPane;
class Event;
struct RectBounds;

enum ScrollCollectionPart
{
    kScrollCollectionPartLeading = 0,
    kScrollCollectionPartPageBeforeThumb = 1,
    kScrollCollectionPartThumb = 2,
    kScrollCollectionPartPageAfterThumb = 3,
    kScrollCollectionPartTrailing = 4,
    kScrollCollectionPartNone = -1
};

extern const int kScrollPanePartExtentBySkin[3];

class ScrollCollectionPane : public Pane
{
public:
    explicit ScrollCollectionPane(unsigned char orientation);

    void SetSkinIndex(unsigned short skinIndex);
    void SetScrollStyle(unsigned char scrollStyle);
    void SetMaxRange(short maxRange);
    void SetScrollPosition(short position);
    void Enable();
    void Disable();
    bool CanScroll() const;

protected:
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual void OnPaint();

private:
    ScrollCollectionPart HitTestScrollRegion(int localY, int localX);
    void GetPartRect(ScrollCollectionPart part, RectBounds *bounds);
    void SetHighlightedPart(ScrollCollectionPart part);
    void BeginPartInteraction(ScrollCollectionPart part,
                              int mouseY,
                              int mouseX);
    void UpdateDragScroll();
    void UpdatePositionFromCursor(int localY, int localX);
    void ResetScrollState();

    unsigned short m_scrollSkinIndex;
    unsigned char m_scrollStyle;
    bool m_thumbDragActive;
    unsigned char m_orientation;
    short m_scrollPosition;
    short m_scrollRange;
    bool m_scrollEnabled;
    signed char m_highlightPart;
    signed char m_activePart;
    Point m_thumbDragOffset;
};

[[CHILDREN]]
```

- The previously proposed source-level `typedef char ...SizeMustBe272[...]` assertion is withdrawn. Live layout evidence still requires the declaration to naturally measure `0x110`, but no original/project source evidence proves that NexusTK developers authored that reverse-engineering-style size-check typedef. The size invariant belongs in layout documentation, IDA readback, and generated/build verification rather than invented human source.

- New constructor child CPP:

```cpp
ScrollCollectionPane::ScrollCollectionPane(unsigned char orientation)
    : Pane(1),
      m_scrollSkinIndex(0),
      m_scrollStyle(1),
      m_thumbDragActive(false),
      m_orientation(orientation),
      m_scrollPosition(0),
      m_scrollRange(0),
      m_scrollEnabled(true),
      m_highlightPart(kScrollCollectionPartNone),
      m_activePart(kScrollCollectionPartNone)
{
    InitPointPair(&m_thumbDragOffset, 0, 0);
}
```

- Setter/enable/predicate child CPP blocks:

```cpp
void ScrollCollectionPane::SetSkinIndex(unsigned short skinIndex)
{
    if (m_scrollSkinIndex != skinIndex) {
        m_scrollSkinIndex = skinIndex;
        InvalidateRect(&m_bounds);
    }
}
```

```cpp
void ScrollCollectionPane::SetScrollStyle(unsigned char scrollStyle)
{
    if (m_scrollStyle != scrollStyle) {
        m_scrollStyle = scrollStyle;
        InvalidateRect(&m_bounds);
    }
}
```

```cpp
void ScrollCollectionPane::SetMaxRange(short maxRange)
{
    if (maxRange < 0) {
        maxRange = 0;
    } else if (maxRange > 30000) {
        maxRange = 30000;
    }

    if (m_scrollPosition > maxRange) {
        SetScrollPosition(maxRange);
    }

    m_scrollRange = maxRange;
    InvalidateRect(&m_bounds);
}
```

```cpp
void ScrollCollectionPane::SetScrollPosition(short position)
{
    m_scrollPosition = position;
    InvalidateRect(&m_bounds);
}
```

```cpp
void ScrollCollectionPane::Enable()
{
    if (!m_scrollEnabled) {
        m_scrollEnabled = true;
        InvalidateRect(&m_bounds);
    }
}
```

```cpp
void ScrollCollectionPane::Disable()
{
    if (m_scrollEnabled) {
        m_scrollEnabled = false;
        InvalidateRect(&m_bounds);
    }
}
```

```cpp
bool ScrollCollectionPane::CanScroll() const
{
    return m_scrollEnabled && m_scrollRange > 0;
}
```

- EventHandler children:

```cpp
bool ScrollCollectionPane::HandlePointerOrMouseEvent(Event *event)
{
    bool handled = false;
    RectBounds partRect;
    const int mouseY = event->m_pointer.m_y;
    const int mouseX = event->m_pointer.m_x;

    switch (event->m_type) {
    case kEventPointerMove:
        if (m_activePart != kScrollCollectionPartNone) {
            InvalidateRect(&m_bounds);
            handled = true;
        }
        break;

    case kEventLeftButtonDown:
        if (!PointInRect(mouseY, mouseX, &m_bounds) || !CanScroll()) {
            return false;
        }

        if (m_activePart == kScrollCollectionPartNone) {
            const ScrollCollectionPart part =
                HitTestScrollRegion(mouseY, mouseX);
            if (part != kScrollCollectionPartNone) {
                CaptureMouse();
                BeginPartInteraction(part, mouseY, mouseX);
                InvalidateRect(&m_bounds);
            }
        }

        m_thumbDragActive = true;
        handled = true;
        break;

    case kEventLeftButtonUp:
        if (m_activePart != kScrollCollectionPartNone) {
            ReleaseMouseCapture();
            RemovePendingTimers();

            const ScrollCollectionPart oldPart =
                static_cast<ScrollCollectionPart>(m_highlightPart);
            m_activePart = kScrollCollectionPartNone;
            if (oldPart != kScrollCollectionPartNone) {
                GetPartRect(oldPart, &partRect);
                InvalidateRect(&partRect);
                m_highlightPart = kScrollCollectionPartNone;
            }
            handled = true;
        }

        m_thumbDragActive = false;
        InvalidateRect(&m_bounds);
        break;

    default:
        break;
    }

    return handled;
}
```

```cpp
bool ScrollCollectionPane::HandleKeyOrTextEvent(Event *)
{
    return false;
}
```

```cpp
bool ScrollCollectionPane::OnTimer(int timerId, int, int)
{
    if (timerId == 0 &&
        m_activePart != kScrollCollectionPartNone) {
        UpdateDragScroll();
        ScheduleTimer(0, 30, 0, 0);
    }
    return true;
}
```

- Paint child CPP:

```cpp
void ScrollCollectionPane::OnPaint()
{
    EPFTileContext tile;
    RectBounds clipRect;
    RectBounds partRect;
    RectBounds drawRect;
    RectBounds stripRect;

    EPFTileContext_Initialize(&tile);
    GetClipRect(&clipRect);
    if (!CanScroll()) {
        return;
    }

    const bool horizontal = (m_orientation != 0);
    for (int pass = 0; pass < 2; ++pass) {
        const ScrollCollectionPart part = pass == 0
            ? kScrollCollectionPartPageBeforeThumb
            : kScrollCollectionPartPageAfterThumb;
        GetPartRect(part, &partRect);
        if (!IntersectRects(&drawRect, &partRect, &clipRect)) {
            continue;
        }

        SetDrawColor(0);
        FillRect(&drawRect);
        SetDrawColor(128);

        const int fillFrame = horizontal ? 4 : 1;
        const int capFrame = horizontal
            ? (pass == 0 ? 3 : 5)
            : (pass == 0 ? 0 : 2);
        g_pEPFLib->LookupLayoutEntry(
            L"SLIDEBG.EPF", fillFrame, &tile);

        stripRect = drawRect;
        if (horizontal) {
            stripRect.right = stripRect.left + 1;
            while (stripRect.left < drawRect.right) {
                RenderTileFrame(this, &tile, &stripRect, L"SLIDEBG.PAL");
                OffsetRect(&stripRect, 1, 0);
            }
        } else {
            stripRect.bottom = stripRect.top + 1;
            while (stripRect.top < drawRect.bottom) {
                RenderTileFrame(this, &tile, &stripRect, L"SLIDEBG.PAL");
                OffsetRect(&stripRect, 0, 1);
            }
        }

        g_pEPFLib->LookupLayoutEntry(
            L"SLIDEBG.EPF", capFrame, &tile);
        RenderTileFrame(this, &tile, &drawRect, L"SLIDEBG.PAL");
    }

    GetPartRect(kScrollCollectionPartThumb, &partRect);
    if (IntersectRects(&drawRect, &partRect, &clipRect)) {
        SetDrawColor(0);
        FillRect(&drawRect);
        SetDrawColor(128);
        g_pEPFLib->LookupLayoutEntry(
            L"SCRBUTT.EPF",
            m_highlightPart == kScrollCollectionPartThumb ? 1 : 0,
            &tile);
        RenderTileFrame(this, &tile, &drawRect, L"BUTTON.PAL");
    }
}
```

- Geometry child CPP:

```cpp
void ScrollCollectionPane::GetPartRect(ScrollCollectionPart part,
                                       RectBounds *bounds)
{
    Point cursor;
    Point origin;

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    if (origin.x == -1000 && origin.y == -1000) {
        return;
    }
    cursor.x -= origin.x;
    cursor.y -= origin.y;

    *bounds = m_bounds;
    const bool horizontal = (m_orientation != 0);
    const int thumbSpan = horizontal
        ? m_bounds.bottom - m_bounds.top
        : kScrollPanePartExtentBySkin[m_scrollSkinIndex];

    if (part == kScrollCollectionPartLeading) {
        if (horizontal) {
            bounds->right = bounds->left;
        } else {
            bounds->bottom = bounds->top;
        }
        return;
    }
    if (part == kScrollCollectionPartTrailing) {
        if (horizontal) {
            bounds->left = bounds->right;
        } else {
            bounds->top = bounds->bottom;
        }
        return;
    }

    if (!CanScroll()) {
        if (part == kScrollCollectionPartThumb) {
            if (horizontal) {
                bounds->left += thumbSpan;
                bounds->right -= thumbSpan;
            } else {
                bounds->top += thumbSpan;
                bounds->bottom -= thumbSpan;
            }
        } else {
            InitRectBounds(bounds, 0, 0, 0, 0);
        }
        return;
    }

    if (horizontal) {
        const int trackStart = m_bounds.left;
        const int thumbLimit = m_bounds.right - thumbSpan;
        const int thumbStart = trackStart +
            (m_scrollPosition * (thumbLimit - trackStart)) /
                m_scrollRange;
        const int thumbEnd = thumbStart + thumbSpan;
        if (part == kScrollCollectionPartThumb) {
            bounds->left = thumbStart;
            bounds->right = thumbEnd;
        } else if (part == kScrollCollectionPartPageBeforeThumb) {
            bounds->right = thumbStart;
        } else if (part == kScrollCollectionPartPageAfterThumb) {
            bounds->left = thumbEnd;
        }
    } else {
        const int trackStart = m_bounds.top;
        const int thumbLimit = m_bounds.bottom - thumbSpan;
        int thumbStart;
        if (m_thumbDragActive) {
            thumbStart = m_bounds.top + cursor.y - m_thumbDragOffset.y;
            if (thumbStart < trackStart) {
                thumbStart = trackStart;
            }
            if (thumbStart > thumbLimit) {
                thumbStart = thumbLimit;
            }
        } else {
            thumbStart = trackStart +
                (m_scrollPosition * (thumbLimit - trackStart)) /
                    m_scrollRange;
        }
        const int thumbEnd = thumbStart + thumbSpan;
        if (part == kScrollCollectionPartThumb) {
            bounds->top = thumbStart;
            bounds->bottom = thumbEnd;
        } else if (part == kScrollCollectionPartPageBeforeThumb) {
            bounds->bottom = thumbStart;
        } else if (part == kScrollCollectionPartPageAfterThumb) {
            bounds->top = thumbEnd;
        }
    }
}
```

- Existing UID0001GX exact replacement formal CPP must preserve its current arithmetic but change `unsigned short oldPosition/newPosition` to `short`, and replace the tail with:

```cpp
    if (oldPosition != newPosition) {
        static_cast<CollectionPane *>(GetParentPane())
            ->OnScrollPositionChanged(m_orientation,
                                      oldPosition,
                                      newPosition);
    }
```

- Existing UID0001GY exact replacement local/state form:

```cpp
void ScrollCollectionPane::ResetScrollState()
{
    RectBounds rect;

    RemovePendingTimers();

    const ScrollCollectionPart oldPart =
        static_cast<ScrollCollectionPart>(m_highlightPart);
    m_activePart = static_cast<signed char>(kScrollCollectionPartNone);

    if (oldPart != kScrollCollectionPartNone) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
        m_highlightPart =
            static_cast<signed char>(kScrollCollectionPartNone);
    }
}
```

- H block disposition for every exact method child: blank because declarations are centralized in UID0000CG H. UID0001VZ should remain a documentation/layout support emitter rather than duplicate the class declaration.
- Third-party import directive: not applicable; this is first-party NexusTK UI code.
- Behavior preservation: bodies preserve exact range checks, state transitions, signed range/position widths, event values, capture/timer ordering, orientation formulas, resource/frame selection, invalidation, and owner callback semantics. Repeated compiler-inlined geometry in paint is expressed through the source-level `GetPartRect` helper, matching accepted sibling source shape.
- Human source shape: class members, enum, RAII/local objects, inherited APIs, and helper calls replace pointer arithmetic, adjusted-this subtraction, vtable-index calls, SIMD copies, and compiler labels.
- Naming style: current project PascalCase class/method names, `m_` members, `k` constants, and explicit enum constants. Execution fidelity and human source shape take precedence over stylistic consistency.

## Final Recommendation

- Accepted recommendation: retain target UID0001GT as reconstructable with direct owner/emitter UID0000CG, use a covered-by aggregate CPP with blank H, centralize the natural 0x110 class shell in UID0000CG, and route all nineteen exact method definitions through dedicated `NexusTK/ui/core/ScrollCollectionPane.{h,cpp}`.
- Completed callback allocation: thirteen new exact children were registered as UIDs 0004X3, 0004X4, 0004X6, 0004X7, 0004X8, 0004X9, 0004XA, 0004XB, 0004XL, 0004XM, 0004XN, 0004XO, and 0004XP with direct owner/emitter UID0000CG and deterministic positions `5,10,12,14,16,18,20,22,24,26,28,30,45`.
- Completed callback repairs: UID0001GX and UID0001GY formal C++ were corrected; UID0001GU, UID0003MX, UID0003MY, and UID0001GW were synchronized; target/class/file/layout/vtable/vtable-data evidence, metadata, routing, history, and no-route facts were applied without leaving a source-bearing range no-owner/non-emitting.
- Completed validation/generated result: every changed/created ordinary page passed serial scoped validation with exit `0` and `ok: 1`; synchronous command `000000017658` completed generated refresh, and generated ScrollCollectionPane CPP/H is ordered, nonduplicating, nonempty, human-shaped, and free of empty target markers.
- Remaining supervisor work: apply/read back the accepted IDA handoff, apply and validate the exact manual coverage payloads, complete Gate 2A/2B, and only then execute/archive this report. Rebuilt-binary comparison and original-symbol/source recovery remain future final-audit work rather than blockers to the current low-90 reconstruction.
- Historical pre-callback instructions, now completed or transferred to supervisor ownership, were to apply the exact split/class shell/child C++/support metadata after Gate 1, retain UID0001GT owner/emitter UID0000CG with covered-by CPP and blank H, create thirteen validator-assigned children without guessing UIDs, repair UID0001GX/UID0001GY while synchronizing the other four existing children, leave only alignment bytes without source emitters, and defer rebuilt-binary/original-source recovery to final audit.

## Recommended Target Doc Changes

- Accepted target recommendation: `by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md` should contain the complete function/raw/padding inventory, exact caller/vtable/global/resource evidence, resolved source placement, field/type map, positive/negative evidence, and historical corrections from this report without loss or summary compression.
- Current applied target identity: SHA256 `76FFB81827B07667785EC068AC4F9A1692F624278F6B62DA39942DBB8E771584`; metadata is `COMPLETION:93`, `CONFIDENCE:93`, `CANONICAL_OWNER:0000CG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CG`, blank position, covered-by CPP, and blank H.
- Current exact-child links: existing UIDs 0001GU, 0003MX, 0003MY, 0001GW, 0001GX, and 0001GY plus registered UIDs 0004X3, 0004X4, 0004X6, 0004X7, 0004X8, 0004X9, 0004XA, 0004XB, 0004XL, 0004XM, 0004XN, 0004XO, and 0004XP cover all nineteen source-bearing bodies in address/position order; alignment-only gaps remain documented without emitters.
- Current target result: the stale Covered Functions/Boundary material is replaced by exact rows, the obsolete source/split/type/callback assumptions are retained only as superseded history, scoped validators `000000017591` and `000000017653` each exited `0` with `ok: 1`, and final generated refresh `000000017658` completed successfully.
- Historical pre-callback target instructions, now completed, were to change `87/90` to `93/93`, retain owner/emitter `0000CG` and reconstructable true, populate covered-by CPP with blank H, replace stale function/boundary tables, register/link every exact child, and preserve corrected assumptions in an explicitly superseded section.

## Recommended Support Doc Changes

- `by-class/ScrollCollectionPane.md`: now `93/93` with exact class CPP/H, complete method/field/enum/vtable/source route, every exact child link, and raw no-route facts preserved as confidence limits rather than no-code blockers.
- `by-file/ScrollCollectionPane.md`: now `91/92` with resolved `NexusTK/ui/core/` placement, the standalone-versus-ScrollBar uncertainty closed, and complete class/header/source contents and children.
- `by-type/by-struct/ScrollCollectionPaneLayout.md`: now `92/93` with `+0xfa`, natural alignment, signed-byte part fields, Point offsets, and exact natural 0x110 declaration relationship resolved; formal C++ remains blank to avoid class duplication.
- `by-type/by-vtable/ScrollCollectionPaneVtables.md`: now `92/94` with the EventHandler key/text slot and TimerHandler facet resolved; compiler vtable data remains non-source-emitting.
- [UID:0003CN] exact vtable data: synchronize slot names/comments while retaining current `86/90`; this report does not recommend a UID0003CN score/manual-coverage change because its broader source-quality scoring was not independently re-audited here. Keep it non-source-emitting.
- Existing child pages: UID0001GX and UID0001GY formal bodies are repaired; UID0001GU/UID0003MX/UID0003MY/UID0001GW support links/names are synchronized.
- New exact child pages: created from the inventory with owner/emitter `0000CG`, reconstructable true, ordered positions `5,10,12,14,16,18,20,22,24,26,28,30,45`, blank H, and the corresponding formal CPP blocks.

## Score And Metadata Recommendation

- Assignment-time target: `87/90`, owner/emitter UID0000CG, reconstructable true, blank formal C++.
- Applied target: `93/93`, same owner/emitter/reconstructable, aggregate covered-by CPP, H blank.
- Score rationale: all code/padding boundaries, class ownership, field layout, vtable facets, behaviors, caller graph, human names, source route, split topology, class declaration, child code, and IDA handoff are now implementation-ready.
- Reason not higher: original symbols/PDB/source are absent; seven raw starts lack recovered static routes; exact original spelling/access/inlining cannot be proven; rebuilt-binary comparison has not occurred.
- Reason not lower: every source-bearing body is mapped, every prior blocker was actively researched, no open ownership/split/range issue remains, and all formal destination payloads are specified.
- Score-improvement attempts:
  - Raw helper blocker: performed exact byte/range/xref/pointer/body-family analysis; resolved as exact class methods and safe IDA function creations.
  - Source-placement blocker: compared class/file/consumer/sibling evidence; resolved to dedicated `ui/core` source.
  - `+0xfa` blocker: checked raw setter and sibling layouts; resolved `m_scrollStyle`.
  - Key/CanScroll blocker: checked vtable contract and separate predicate; resolved both methods.
  - Final C++ blocker: reconstructed class H/CPP and every missing child body; aggregate no longer needs to remain empty.
  - Callback/type blocker: checked Pane/CollectionPane APIs and field widths; supplied exact UID0001GX/UID0001GY repairs.
- Support metadata changes: class `93/93`, file `91/92`, layout `92/93`, vtables `92/94`, UID0003CN vtable data retained `86/90`, and new children as inventoried; no target ownership/reconstructable flip.

## Open Questions With Attempted Resolution

- Exact original class/member spelling: searched current symbols, docs, sibling source conventions, vtables, and behavior. No original symbols exist. Best-supported human names are supplied; no IDA/decompiler labels remain in proposed final source. This only caps final-audit confidence.
- Exact original file name: compared dedicated by-file/source-tree evidence against CollectionPane and generic ScrollBar alternatives. Dedicated `ScrollCollectionPane.{h,cpp}` is high probability and selected; no practical ownership uncertainty remains.
- Raw method reachability: exhaustive xref and pointer-route searches found none. Complete bounded bodies and class-local semantics establish source roles, but invocation may have been inlined/optimized/unreferenced in this build. This caps confidence but does not block code or exact child pages.
- Event constant spelling and a few render helper spellings: binary values and behavior are exact; current project Event/Pane/render APIs supply the highest-probability names. Final implementation should use the current emitted API spelling while preserving values/order.
- Whether original OnPaint explicitly called `GetPartRect` for both track portions: the target compiler inlines equivalent geometry, while accepted sibling source uses the helper. The helper-based human source is selected because it is behavior-equivalent and substantially more plausible than duplicated decompiler-shaped arithmetic.
- No question remains that requires deferring current split, ownership, source placement, metadata, class header/source, or first-draft method emission.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The current manual rows were inspected. They are stale and must be changed by the supervisor, never by B005.

- File/placement: `by-memory/-coverage-report.md`, replace UID0001GT row:

```markdown
    - [UID:0001GT][0x00561db0-0x0056325c.ScrollCollectionPane](by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md) 0x00561db0-0x0056325c | class range | ScrollCollectionPane : reconstructable : 93% : very-strong : Complete ScrollCollectionPane class aggregate with exact modeled/raw method and padding map, CollectionPane caller/callback route, three vtable facets, resolved 0x110 field layout, split-complete child ownership, dedicated ui/core source placement, formal class/header topology, source-ready behavior, and supervisor IDA handoff.
```

- In the same file, replace existing exact-child rows with current completion text after implementation:

```markdown
    - [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md) 0x005628d0-0x00562bed | function | ScrollCollectionPaneHitTestScrollRegion : reconstructable : 91% : very-strong : Exact five-part hit test with orientation geometry, drag-state thumb position, cursor/origin conversion, direct caller pair, class ownership, and formal C++.
    - [UID:0003MX][0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw](by-memory/0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw.md) 0x00562e80-0x00562ef0 | raw function | ScrollCollectionPaneSetHighlightedPart : reconstructable : 90% : very-strong : Exact bounded raw highlighted-part transition with old/new rectangle invalidation, enum state typing, class ownership, no-route evidence, and formal C++.
    - [UID:0003MY][0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw](by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md) 0x00562ef0-0x00562fb0 | raw function | ScrollCollectionPaneBeginPartInteraction : reconstructable : 90% : very-strong : Exact bounded raw press/drag setup with thumb offset, active/highlight state, immediate update, repeat timer, class ownership, no-route evidence, and formal C++.
    - [UID:0001GW][0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll](by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md) 0x00562fb0-0x00563070 | function | ScrollCollectionPaneUpdateDragScroll : reconstructable : 91% : very-strong : Exact active-part repeat/drag update with cursor conversion, hit test, highlight invalidation, caller graph, class ownership, and formal C++.
    - [UID:0001GX][0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor](by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md) 0x00563070-0x005631fd | function | ScrollCollectionPaneUpdatePositionFromCursor : reconstructable : 92% : very-strong : Exact orientation-specific cursor-to-position formulas, signed short state, clamp asymmetry, inherited GetParentPane CollectionPane callback, class ownership, and corrected formal C++.
    - [UID:0001GY][0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw](by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md) 0x00563200-0x0056325c | raw function | ScrollCollectionPaneResetScrollState : reconstructable : 90% : strong : Exact bounded reset body with timer removal, enum-typed active/highlight clearing, old-part invalidation, class ownership, no-static-route evidence, and corrected formal C++.
```

- Insert the following registered child rows after the aggregate in address order; the validator-assigned UIDs below are final:

```markdown
    - [UID:0004X3][0x00561db0-0x00561e51.ScrollCollectionPaneConstructor](by-memory/0x00561db0-0x00561e51.ScrollCollectionPaneConstructor.md) 0x00561db0-0x00561e51 | function | ScrollCollectionPaneConstructor : reconstructable : 92% : very-strong : Exact Pane-base construction, three vtable facets, complete 0x110 state initialization, CollectionPane caller, class owner, and formal constructor C++.
    - [UID:0004X4][0x00561e60-0x00561e87.ScrollCollectionPaneSetSkinIndexRaw](by-memory/0x00561e60-0x00561e87.ScrollCollectionPaneSetSkinIndexRaw.md) 0x00561e60-0x00561e87 | raw function | ScrollCollectionPaneSetSkinIndex : reconstructable : 89% : strong : Exact bounded skin-index setter with change invalidation, field/table use, no-static-route evidence, class ownership, and formal C++.
    - [UID:0004X6][0x00561e90-0x00561eb4.ScrollCollectionPaneSetScrollStyleRaw](by-memory/0x00561e90-0x00561eb4.ScrollCollectionPaneSetScrollStyleRaw.md) 0x00561e90-0x00561eb4 | raw function | ScrollCollectionPaneSetScrollStyle : reconstructable : 89% : strong : Exact bounded style-byte setter resolving layout +0xfa, no-static-route evidence, class ownership, and formal C++.
    - [UID:0004X7][0x00561ec0-0x00561f1b.ScrollCollectionPaneSetMaxRange](by-memory/0x00561ec0-0x00561f1b.ScrollCollectionPaneSetMaxRange.md) 0x00561ec0-0x00561f1b | function | ScrollCollectionPaneSetMaxRange : reconstructable : 92% : very-strong : Exact signed clamp to 0..30000, current-position clamp, invalidation order, owner caller, class ownership, and formal C++.
    - [UID:0004X8][0x00561f20-0x00561f47.ScrollCollectionPaneSetScrollPosition](by-memory/0x00561f20-0x00561f47.ScrollCollectionPaneSetScrollPosition.md) 0x00561f20-0x00561f47 | function | ScrollCollectionPaneSetScrollPosition : reconstructable : 91% : very-strong : Exact signed short position store/invalidation, three owner-side callers, class ownership, and formal C++.
    - [UID:0004X9][0x00561f50-0x00561f6a.ScrollCollectionPaneEnable](by-memory/0x00561f50-0x00561f6a.ScrollCollectionPaneEnable.md) 0x00561f50-0x00561f6a | function | ScrollCollectionPaneEnable : reconstructable : 91% : very-strong : Exact false-to-true transition, conditional invalidation, CollectionPane caller, class ownership, and formal C++.
    - [UID:0004XA][0x00561f70-0x00561f8a.ScrollCollectionPaneDisableRaw](by-memory/0x00561f70-0x00561f8a.ScrollCollectionPaneDisableRaw.md) 0x00561f70-0x00561f8a | raw function | ScrollCollectionPaneDisable : reconstructable : 89% : strong : Exact true-to-false transition, conditional invalidation, no-static-route evidence, class ownership, and formal C++.
    - [UID:0004XB][0x00561f90-0x00561faa.ScrollCollectionPaneCanScrollRaw](by-memory/0x00561f90-0x00561faa.ScrollCollectionPaneCanScrollRaw.md) 0x00561f90-0x00561faa | raw function | ScrollCollectionPaneCanScroll : reconstructable : 90% : strong : Exact enabled-and-positive-signed-range predicate, no-static-route evidence, class ownership, and formal C++.
    - [UID:0004XL][0x00561fb0-0x00562191.ScrollCollectionPaneHandlePointerOrMouseEvent](by-memory/0x00561fb0-0x00562191.ScrollCollectionPaneHandlePointerOrMouseEvent.md) 0x00561fb0-0x00562191 | function | ScrollCollectionPaneHandlePointerOrMouseEvent : reconstructable : 92% : very-strong : Exact EventHandler mouse move/down/up state machine with capture, geometry, drag, timer, invalidation, vtable route, and formal C++.
    - [UID:0004XM][0x005621a0-0x005621a5.ScrollCollectionPaneHandleKeyOrTextEvent](by-memory/0x005621a0-0x005621a5.ScrollCollectionPaneHandleKeyOrTextEvent.md) 0x005621a0-0x005621a5 | function | ScrollCollectionPaneHandleKeyOrTextEvent : reconstructable : 91% : very-strong : Exact EventHandler secondary key/text slot returning false, corrected against the stale CanScroll interpretation, and formal C++.
    - [UID:0004XN][0x005621b0-0x005621e3.ScrollCollectionPaneOnTimer](by-memory/0x005621b0-0x005621e3.ScrollCollectionPaneOnTimer.md) 0x005621b0-0x005621e3 | function | ScrollCollectionPaneOnTimer : reconstructable : 91% : very-strong : Exact TimerHandler facet callback with active-part gate, update call, 30 ms reschedule, vtable route, and formal C++.
    - [UID:0004XO][0x005621f0-0x005628d0.ScrollCollectionPaneOnPaint](by-memory/0x005621f0-0x005628d0.ScrollCollectionPaneOnPaint.md) 0x005621f0-0x005628d0 | function | ScrollCollectionPaneOnPaint : reconstructable : 92% : very-strong : Exact enabled/range paint path with clip intersection, orientation-specific SLIDEBG frames, tiled track strips, SCRBUTT thumb state, resource/global evidence, and human source C++.
    - [UID:0004XP][0x00562bf0-0x00562e77.ScrollCollectionPaneGetPartRect](by-memory/0x00562bf0-0x00562e77.ScrollCollectionPaneGetPartRect.md) 0x00562bf0-0x00562e77 | function | ScrollCollectionPaneGetPartRect : reconstructable : 92% : very-strong : Exact five-part orientation geometry with skin extent table, live drag thumb position, disabled-state behavior, thirteen internal refs, class ownership, and formal C++.
```

- `by-class/-coverage-report.md`, replace UID0000CG row:

```markdown
- [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md) : reconstructable : 93% : very-strong : Complete 0x110 themed scrollbar class with resolved enum/layout/vtable facets, exact method children, human class header/source shell, dedicated ui/core placement, shared extent/resource names, and no remaining ownership/split/final-C++ blocker.
```

- `by-file/-coverage-report.md`, replace UID0000NG row:

```markdown
- [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md) : reconstructable : 91% : very-strong : Dedicated NexusTK/ui/core ScrollCollectionPane source/header containing the complete class declaration, exact child method bodies, shared extent table, resource-backed paint path, and resolved source placement.
```

- `by-type/by-struct/-coverage-report.md`, replace the exact current UID0001VZ row at its existing position between the neighboring address/type-order rows:

```markdown
- [UID:0001VZ][ScrollCollectionPaneLayout](by-type/by-struct/ScrollCollectionPaneLayout.md) : reconstructable : 92% : very-strong : Exact natural 272-byte/0x110 ScrollCollectionPane layout with protected Pane base, resolved skin/style/drag/orientation/range/position/enabled/highlight/active fields, Point drag offset, compiler-only alignment gaps, direct class ownership, and centralized class-header declaration rather than duplicate layout emission.
```

- `by-type/by-vtable/-coverage-report.md`, replace the exact current UID0001YP row at its existing position between neighboring class-vtable rows:

```markdown
- [UID:0001YP][ScrollCollectionPaneVtables](by-type/by-vtable/ScrollCollectionPaneVtables.md) : reconstructable : 92% : very-strong : Exact primary, EventHandler +0xa0, and TimerHandler +0xa4 ScrollCollectionPane vtable facets with constructor stores, corrected pointer/mouse and key/text slots, timer/paint targets, exact UID0003CN backing range, protected decorated names, and compiler-generated non-source-emitting disposition.
```

- Read-only comparison proof: the current UID0001VZ manual row is in `by-type/by-struct/-coverage-report.md` and reports `85% : strong` with blank-final-C++ wording; the current UID0001YP row is in `by-type/by-vtable/-coverage-report.md` and reports `86% : strong` with the older parent-gate narrative. Both become stale if this report's accepted score/content changes land, so exact replacement rows are required. UID0003CN has no matching manual by-memory row and its score remains unchanged by this report.
- Reason B005 must not apply directly: all `-coverage-report.md` files are supervisor-owned collision points under the current skill.

## Implementation Callback Reconciliation

- Gate 1 acceptance: exact pre-callback SHA256 `88A5C96B3A7BDC7A112E9CDD53AF1F109E00990EAE77E6AB06F6E44E75B5850A` passed audit `B005 UID0001GT Exact-Artifact Gate 1 Reaudit - 2026-07-26T00:24:43-04:00` and received the accepted ordinary/support implementation callback.
- Aggregate/support state: [UID:0001GT] is `93/93`; [UID:0000CG] is `93/93`; [UID:0000NG] is `91/92`; [UID:0001VZ] is `92/93`; [UID:0001YP] is `92/94`; [UID:0003CN] remains `86/90`. Ownership/emission remains centered on [UID:0000CG], and the source route is resolved to `NexusTK/ui/core/ScrollCollectionPane.{h,cpp}`.
- New exact children: [UID:0004X3], [UID:0004X4], [UID:0004X6], [UID:0004X7], [UID:0004X8], [UID:0004X9], [UID:0004XA], [UID:0004XB], [UID:0004XL], [UID:0004XM], [UID:0004XN], [UID:0004XO], and [UID:0004XP] are registered, linked, populated, and scoped-validator verified.
- Existing children: [UID:0001GU], [UID:0003MX], [UID:0003MY], and [UID:0001GW] received the accepted support synchronization; [UID:0001GX] now uses signed `short` positions and inherited `GetParentPane()` for the CollectionPane callback; [UID:0001GY] now uses enum-typed state and signed-byte sentinel casts. All six are scoped-validator verified.
- Source shape: the natural class declaration reaches the documented 0x110 layout without the withdrawn `SizeMustBe` typedef. Aggregate, class, method, layout, vtable, event, timer, geometry, source-placement, resource, no-route, history, and rejected-alternative evidence is retained in the ordinary documentation.
- B005 did not mutate IDA, edit a `-coverage-report.md`, manually edit generated output, invoke `execute_report`, or move/archive this report. Supervisor-owned IDA actions/readbacks, manual coverage replacements/inserts, Gate 2A/2B verification, execution, and archival remain pending.

## Follow-Up Actions

- Supervisor: perform claim-by-claim Gate 2A verification, apply and read back the complete Gate 2B IDA handoff, apply the exact manual coverage rows above, validate those coverage files, and only then execute/archive this exact report.
- A-agent actions: none.
- B005 future research: none for current blockers. Any Gate 2 failure should return this same report/callback for incremental repair without discarding the accepted research or applied validation evidence.

## Confidence

- Recommendation confidence: 93/100.
- Score confidence: 92/100.
- Remaining uncertainty: exact original spelling/access/inlining and static routes for raw methods. These are documented final-audit limits, not unresolved current implementation questions.

## Validator Results

- Every validator below was run serially from `source-3/project-documentation` as `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`. Every command exited `0` with `ok: 1`.

| Command ID | UID / path | Result |
| --- | --- | --- |
| `000000017530` | 0004X3 `by-memory/0x00561db0-0x00561e51.ScrollCollectionPaneConstructor.md` | registered UID; ok |
| `000000017535` | 0004X4 `by-memory/0x00561e60-0x00561e87.ScrollCollectionPaneSetSkinIndexRaw.md` | registered UID; ok |
| `000000017539` | 0004X6 `by-memory/0x00561e90-0x00561eb4.ScrollCollectionPaneSetScrollStyleRaw.md` | registered UID; ok |
| `000000017547` | 0004X7 `by-memory/0x00561ec0-0x00561f1b.ScrollCollectionPaneSetMaxRange.md` | registered UID; ok |
| `000000017552` | 0004X8 `by-memory/0x00561f20-0x00561f47.ScrollCollectionPaneSetScrollPosition.md` | registered UID; ok |
| `000000017555` | 0004X9 `by-memory/0x00561f50-0x00561f6a.ScrollCollectionPaneEnable.md` | registered UID; ok |
| `000000017557` | 0004XA `by-memory/0x00561f70-0x00561f8a.ScrollCollectionPaneDisableRaw.md` | registered UID; ok |
| `000000017558` | 0004XB `by-memory/0x00561f90-0x00561faa.ScrollCollectionPaneCanScrollRaw.md` | registered UID; ok |
| `000000017571` | 0004XL `by-memory/0x00561fb0-0x00562191.ScrollCollectionPaneHandlePointerOrMouseEvent.md` | registered UID; ok |
| `000000017572` | 0004XM `by-memory/0x005621a0-0x005621a5.ScrollCollectionPaneHandleKeyOrTextEvent.md` | registered UID; ok |
| `000000017573` | 0004XN `by-memory/0x005621b0-0x005621e3.ScrollCollectionPaneOnTimer.md` | registered UID; ok |
| `000000017577` | 0004XO `by-memory/0x005621f0-0x005628d0.ScrollCollectionPaneOnPaint.md` | registered UID; ok |
| `000000017580` | 0004XP `by-memory/0x00562bf0-0x00562e77.ScrollCollectionPaneGetPartRect.md` | registered UID; ok |
| `000000017591` | 0001GT aggregate | ok |
| `000000017595` | 0000CG class, initial refresh | ok; generated CPP updated and H created |
| `000000017605` | 0000NG file, initial pass | ok; reported then-unregistered UID0003CN support link |
| `000000017616` | 0001VZ layout | ok |
| `000000017617` | 0001YP vtables, initial pass | ok; reported then-unregistered UID0003CN support link |
| `000000017620` | 0003CN exact vtable data | registered path; ok |
| `000000017621` | 0001GU existing child | ok |
| `000000017622` | 0003MX existing child | ok |
| `000000017624` | 0003MY existing child | ok |
| `000000017626` | 0001GW existing child | ok |
| `000000017627` | 0001GX existing child repair | ok |
| `000000017628` | 0001GY existing child repair | ok |
| `000000017632` | 0000CG final generated refresh | ok |
| `000000017634` | 0000NG clean revalidation after UID0003CN registration | ok; warning cleared |
| `000000017635` | 0001YP clean revalidation after UID0003CN registration | ok; warning cleared |
| `000000017636` | 0004XM clean revalidation after UID0003CN registration | ok; warning cleared |
| `000000017647` | 0001GX current score/source-route prose reconciliation | ok |
| `000000017648` | 0001GY current score/enum/IDA-handoff/source-route prose reconciliation | ok |
| `000000017649` | 0001GU geometry-child/current-route reconciliation | ok; validator inserted the missing UID0004XP link form |
| `000000017650` | 0000NG historical/current-state separation | ok |
| `000000017651` | 0000CG current generated/raw-body/source-route reconciliation | ok |
| `000000017652` | 0001GU final status/score reconciliation | ok |
| `000000017653` | 0001GT accepted dedicated-source status reconciliation | ok |
| `000000017654` | 0003MX accepted dedicated-source status reconciliation | ok |
| `000000017655` | 0003MY accepted dedicated-source status reconciliation | ok |
| `000000017656` | 0001GX accepted dedicated-source status reconciliation | ok |
| `000000017657` | 0001GY accepted dedicated-source status reconciliation | ok |
| `000000017658` | 0000CG synchronous final refresh with `--wait-generated` | ok; `generated_refresh: completed` |

- Generated verification: `auto-generated/NexusTK/ui/core/ScrollCollectionPane.cpp` and `.h` are current after synchronous command `000000017658`. The CPP contains exactly one definition for each of the nineteen methods in positions `5,10,12,14,16,18,20,22,24,26,28,30,40,45,50,60,70,80,90`; the aggregate contributes only its covered-by comment. CPP/H contain no `[[CHILDREN]]`, `sub_`, `dword_`, or `SizeMustBe`, no duplicate method definition, and no empty target marker. The class declaration is nonempty and natural 0x110 source. The CPP retains expected empty-emitter markers only for non-source-emitting support UIDs 0003CN, 0001VZ, and 0001YP.
- Unresolved target-specific validator warnings/errors: none. The temporary UID0003CN registration warnings from commands `000000017605` and `000000017617` were resolved by command `000000017620` and confirmed clean by commands `000000017634` and `000000017635`. Command `000000017658` also reported existing project-wide autogen advisory counters outside this target while completing with `ok: 1`; none invalidated ScrollCollectionPane output.

## Changed Files

- Created and validated exact children:
  - [UID:0004X3] `by-memory/0x00561db0-0x00561e51.ScrollCollectionPaneConstructor.md`
  - [UID:0004X4] `by-memory/0x00561e60-0x00561e87.ScrollCollectionPaneSetSkinIndexRaw.md`
  - [UID:0004X6] `by-memory/0x00561e90-0x00561eb4.ScrollCollectionPaneSetScrollStyleRaw.md`
  - [UID:0004X7] `by-memory/0x00561ec0-0x00561f1b.ScrollCollectionPaneSetMaxRange.md`
  - [UID:0004X8] `by-memory/0x00561f20-0x00561f47.ScrollCollectionPaneSetScrollPosition.md`
  - [UID:0004X9] `by-memory/0x00561f50-0x00561f6a.ScrollCollectionPaneEnable.md`
  - [UID:0004XA] `by-memory/0x00561f70-0x00561f8a.ScrollCollectionPaneDisableRaw.md`
  - [UID:0004XB] `by-memory/0x00561f90-0x00561faa.ScrollCollectionPaneCanScrollRaw.md`
  - [UID:0004XL] `by-memory/0x00561fb0-0x00562191.ScrollCollectionPaneHandlePointerOrMouseEvent.md`
  - [UID:0004XM] `by-memory/0x005621a0-0x005621a5.ScrollCollectionPaneHandleKeyOrTextEvent.md`
  - [UID:0004XN] `by-memory/0x005621b0-0x005621e3.ScrollCollectionPaneOnTimer.md`
  - [UID:0004XO] `by-memory/0x005621f0-0x005628d0.ScrollCollectionPaneOnPaint.md`
  - [UID:0004XP] `by-memory/0x00562bf0-0x00562e77.ScrollCollectionPaneGetPartRect.md`
- Modified and validated aggregate/support pages: `by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md`, `by-class/ScrollCollectionPane.md`, `by-file/ScrollCollectionPane.md`, `by-type/by-struct/ScrollCollectionPaneLayout.md`, `by-type/by-vtable/ScrollCollectionPaneVtables.md`, and `by-memory/0x00623fa0-0x00624028.ScrollCollectionPaneVtableData.md`.
- Modified and validated existing exact children: `by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md`, `by-memory/0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw.md`, `by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md`, `by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md`, `by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md`, and `by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md`.
- Validator-owned generated outputs observed and verified under completed refresh command `000000017658`, not manually edited: `auto-generated/NexusTK/ui/core/ScrollCollectionPane.cpp` and `auto-generated/NexusTK/ui/core/ScrollCollectionPane.h`.
- Reconciled report: `tools/leaser/Agents/Agent-B005/research/0001GT-ScrollCollectionPane-source-quality.md`.
- Renamed/moved: none. Report execution: not run. Manual coverage files: not edited.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation completed before implementation under `B005 UID0001GT Exact-Artifact Gate 1 Reaudit - 2026-07-26T00:24:43-04:00`.
- [x] Target/support docs updated: UID0001GT, UID0000CG, UID0000NG, UID0001VZ, UID0001YP, UID0003CN, six existing exact children, thirteen new child pages, and current-state support references.
- [x] Every declared additional UID has target-specific evidence, recommendation, ledger rows, destination docs, and planned validation: no additional report UID is declared, and the report explicitly distinguishes support destinations from report coverage.
- [x] Current target state and actual evidence checked recorded under the literal target/current-state/evidence headings, including live MCP session and negative-route checks.
- [x] Claim And Incorporation Ledger populated and reconciled with applied destinations and truthful verification/pending states.
- [x] Metadata/score changes applied: target 93/93, class 93/93, file 91/92, layout 92/93, vtables 92/94, and exact-child scores as inventoried.
- [x] Score-limiting blockers researched to resolution or implementation-ready split/repair: raw bodies, source route, +0xfa, EventHandler slot, final C++, callback API, and enum typing are closed in the report.
- [x] Owner/emitter/reconstructable state applied: UID0000CG ownership/emission and reconstructable true retained; direct class-owned children created.
- [x] Split/rename/new-child changes applied: thirteen exact children plus both existing-child C++ repairs.
- [x] Source placement, exact half-open ranges, padding, child split, reclassification, and complete read-only IDA rename/type/comment handoff are researched; ordinary-document changes are applied while supervisor IDA actions remain pending.
- [ ] Supervisor Gate 2B IDA handoff lists every exact address/entity, pre-state, proposed action, supporting type, safety constraint, and expected readback; leave this row unchecked for the supervisor.
- [x] First-draft CPP and H insertion text/no-header-code dispositions are applied for aggregate, class, new children, and repaired existing children.
- [x] Third-party import directive reviewed and confirmed not applicable because this is first-party NexusTK UI code.
- [x] Exact target/support documentation facts are incorporated at report-level detail in every accepted destination.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve are explicitly identified.
- [x] Wave2/Wave3 mentions encountered in old provenance were identified and ignored as stale.
- [x] Open questions were attempted and resolved to best-supported source decisions; remaining original-spelling/inlining uncertainty is bounded with exact score impact.
- [x] Scoped file validators ran serially for every changed/created by-* page after the required lease/edit/release flow.
- [x] Generated CPP/H refresh and verification completed; exact supervisor-owned manual coverage replacement/insert payloads remain pending and are specified above.

Implementation callback pass:
- [ ] Supervisor-owned IDA changes remain pending and were not applied by the B agent.
- [x] Report accepted by supervisor for implementation at exact SHA256 `88A5C96B3A7BDC7A112E9CDD53AF1F109E00990EAE77E6AB06F6E44E75B5850A`.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] The declared primary UID and every support destination were verified independently against the ledger and destination docs; no additional report UID was declared.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/CPP/H changes applied or explicitly left supervisor-owned with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed bounded final-audit uncertainty.
- [x] Validators run serially and command IDs/results recorded.
- [x] Generated CPP/H synchronously refreshed and verified under current command ID `000000017658`; exact manual supervisor-owned coverage text is supplied above and remains pending.
- [x] Remaining unapplied accepted items are limited to supervisor-owned IDA action/readback, manual coverage edits/validation, Gate 2A/2B sign-off, `execute_report`, and archival.
- [ ] Supervisor Gate 2A/2B verification complete.
- [ ] Supervisor manual coverage updates complete.
- [ ] Supervisor report execution and archival complete.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000017713","destination_path":"executed-b-agent-research/B005/0001GT-ScrollCollectionPane-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0001GT-ScrollCollectionPane-source-quality.md","timestamp":"2026-07-26T02:21:16-04:00","uid":"0001GT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
