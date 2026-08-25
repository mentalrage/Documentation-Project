** TARGET-REPORT-UID:0002FH **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002FH / 0002FJ / 0002FK / 0002FL / 0002FN / 0002FO / 000106 ChattingVarietySelectPane Source-Quality Research

## Finalized Report / Current Recommendation
- Current recommendation: keep the selector family under [UID:00001Z][ChattingVarietySelectPane](../../../by-class/ChattingVarietySelectPane.md), emitted by [UID:0000I5][Chatting](../../../by-file/Chatting.md) under `social/Chatting.cpp`.
- Final disposition:
  - [UID:0002FH] raw constructor should improve from `82/90` to `84/91`, but must stay below 85 completion and keep formal C++ blank. Its body is constructor-shaped and source-equivalent to `ChattingVarietySelectPane::ChattingVarietySelectPane()`, but IDA still has no function entry, call xref, vtable callback route, or pointer-table route proving a standalone source declaration was emitted.
  - [UID:0002FJ], [UID:0002FK], [UID:0002FL], [UID:0002FN], [UID:0002FO], and [UID:000106] should move from `82/90` to `86/91`. They are exact selector-owned modeled methods/helpers with resolved behavior and source-facing names, but their formal method/helper C++ should remain blank for now because shared Pane event/refresh types, chat-command helpers, ChattingColorPane, and GrafPort/EPF helper declarations are not yet final enough for source-quality method bodies.
  - Support parent [UID:00001Z] should move from `84/88` to `87/91` and receive declaration-only class C++. This is needed because the direct parent should not stay below 85 while its exact children are raised above the gate.
- Required action: supervisor/A-agent should apply the target-doc notes, support-class declaration, score updates, and exact coverage rows below. No by-* docs or coverage reports were edited by B003.
- Confidence: high for ownership/source placement, method names, row semantics, field roles, range/padding, and generated-output rejection; medium for the original constructor declaration route and exact return type of the dismiss virtual.

## Supporting Research

## Target
- Target UIDs:
  - [UID:0002FH] `by-memory/0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md`
  - [UID:0002FJ] `by-memory/0x004811c0-0x00481461.ChattingVarietySelectPaneOnMouseEvent.md`
  - [UID:0002FK] `by-memory/0x00481470-0x0048148f.ChattingVarietySelectPaneOnDismiss.md`
  - [UID:0002FL] `by-memory/0x00481490-0x004816ce.ChattingVarietySelectPaneOnPaint.md`
  - [UID:0002FN] `by-memory/0x004816d0-0x00481741.ChattingVarietySelectPaneSetupBackground.md`
  - [UID:0002FO] `by-memory/0x00481750-0x00481a72.ChattingVarietySelectPaneDrawBorder.md`
  - [UID:000106] `by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md`
- Current scores: all primary targets started at `82/90`.
- Current parent/emitter: [UID:00001Z] `ChattingVarietySelectPane`, emitted through [UID:0000I5] `Chatting`.
- Output/source route: `social/Chatting.cpp`.
- Current assignment: `B003-goal2-chatting-variety-select-pane-source-quality-0002FH-0002FJ-0002FK-0002FL-0002FN-0002FO-000106-20260617`.

## Executive Recommendation
- Keep the family as an exact selector-child family. No split is required: the compact helpers [UID:0002FF]/[UID:0002FG] are already assigned to [UID:00001Y] `ChattingVarietyPane`, while this assignment covers the popup selector constructor/method/helper island from `0x004810f0` through `0x00481b5b`.
- Source-facing names:
  - `ChattingVarietySelectPane::ChattingVarietySelectPane()` for the raw body at `0x004810f0`.
  - `ChattingVarietySelectPane::OnMouseEvent(const PaneMouseEvent *event)` for `0x004811c0`.
  - `ChattingVarietySelectPane::OnDismiss()` for `0x00481470`.
  - `ChattingVarietySelectPane::OnPaint()` for `0x00481490`.
  - `ChattingVarietySelectPane::SetupBackground()` for `0x004816d0`.
  - `ChattingVarietySelectPane::DrawBorder()` for `0x00481750`.
  - `ChattingVarietySelectPane::HitTest(int x, int y)` for `0x00481ad0`.
- Field names:
  - `m_pressCaptured` at selector `+0xf8`: nonzero only while the selector has an active press inside the popup.
  - `m_hotRow` at selector `+0xf9`: signed row id `0..5`, with `-1`/`0xff` meaning no row.
  - `+0xfa..+0xfb`: padding/reserved bytes before the `0xfc` selector object end. No independent selector field is proven there.
- Row/action names:
  - row 0 `Talk`
  - row 1 `Shout`
  - row 2 `Whisper`
  - row 3 `Group`
  - row 4 `Clan`
  - row 5 `Color`
- Mode field: use the existing compact-pane conclusion that `dword_67A748 + 0x3eb4` is the current chat variety mode byte/field. The selector writes `0..4` for Talk/Shout/Whisper/Group/Clan and does not write it for Color.
- Parent gate repair: [UID:00001Z] should be raised to `87/91` and populated with declaration-only class C++; method bodies stay in exact child pages.

## Supervisor Active Recheck
- This is report-only B-agent work. B003 did not edit by-* docs, generated reports, generated source, source files, the IDA database, or `by-memory/-coverage-report.md`.
- Split exception does not apply. The assigned targets are already exact selector children or exact selector helpers. The only sub-85 target that remains below completion 85 is [UID:0002FH], and it has an evidence-backed no-85 result because no entry/caller/pointer route proves standalone source liveness.
- The direct parent [UID:00001Z] is currently `84/88`, which is not strong enough for above-gate children under the active parent-gate rule. The report therefore includes exact support-class metadata and declaration-only C++ recommendations.

## Inference Research Guidance Check
- `by-structure.md` and `Supervisor.md` require the target to be reconstructable, have a nonblank emitter route, and satisfy `(completion + confidence) / 2 > 85` before formal C++ is considered. That is only the minimum gate; weak method dependencies can still require blank C++.
- The active B-agent guidance requires field/type/helper/source-placement issues to be actively resolved or evidence-bound. This report does that for the raw constructor liveness, selector fields, event kinds, action dispatch, source ownership, generated names, range/padding, and final-C++ readiness.
- Existing by-* docs and prior B reports were treated as leads. The live IDA MCP recheck confirmed the core facts and corrected the risk posture: the class parent can safely emit a declaration, but individual selector method bodies should remain blank until shared event/render/helper declarations are stabilized.

## Heuristic / Inference Reanalysis And Validation

### Selector Ownership And Source Placement
- Evidence checked: [UID:0000I5] `Chatting` file row, [UID:00001Z] class page, [UID:00001Y] compact-pane class page, current `by-memory/-coverage-report.md`, live IDA function/xref data, vtable data [UID:0003AT], singleton globals [UID:0002XA]/[UID:0002XB], and generated `auto-generated/NexusTK/social/Chatting.cpp`.
- Best inference: the selector is a sibling class to `ChattingVarietyPane` in `social/Chatting.cpp`, not a separate `ChatColorDialog.cpp`, not `ChattingHandlePane`, and not a generic Pane/EPF helper.
- Evidence: the selector has its own vtable slice (`0x00614f2c` primary plus secondary/tertiary vtables), dedicated singleton at `0x0067addc`, constructor/destructor lifecycle, and row dispatch directly tied to chat-mode globals and the compact variety pane. The adjacent raw compact helpers are not selector methods because they use the compact `(0,0,62,24)` geometry, while selector methods use six rows with `y = row*16 + 6..22`.
- Rejected alternatives:
  - `ChattingVarietyPane` owner for the selector methods: rejected because these methods use the selector vtable slots, selector singleton, selector `+0xf8/+0xf9` state, selector popup rectangle, and destructor lifetime.
  - `ChattingColorPane` owner: rejected because Color is only row 5's callee path, with a separate allocation/constructor at `0x004824e0`.
  - `ChattingHandlePane` owner: rejected by B002's prior split and by field offsets; the handle-pane raw helpers use `+0x111/+0x114...` render state, while selector state is only `+0xf8/+0xf9`.
- Score/final-C++ impact: ownership/source placement is strong enough to raise the modeled selector methods and parent class above the gate. It does not make method bodies source-ready by itself.

### Raw Constructor Liveness And De-Duplication Of [UID:0002FC]
- Evidence checked: `lookup_funcs` shows no function at `0x004810f0`; `analyze_function 0x004810f0` fails with no function; `xrefs_to 0x004810f0` returns none; nearby functions start at `0x00481150` and later; `xrefs_to 0x0067addc` includes a raw constructor write at `0x00481115`; the compact [UID:0002FC] path inline-builds an equivalent selector allocation/constructor sequence.
- Best inference: `0x004810f0-0x00481146` is a retained/source-equivalent normal constructor body for `ChattingVarietySelectPane`, but its executable reachability is not proven as a callable function.
- De-dup decision: do not use this raw body alone to rewrite [UID:0002FC] as a clean `new ChattingVarietySelectPane()` call in formal C++. It is valid documentation evidence for the source shape, but not enough for a final C++ method body because the binary does not prove whether the source had an out-of-line constructor, an inlined constructor, or both after optimization/link layout.
- Rejected alternatives:
  - Dead data/compiler artifact: rejected because the bytes decode as a complete Pane-derived constructor, write the selector singleton, initialize selector fields, install selector vtables, and align exactly before the destructor.
  - Proven callable out-of-line constructor: rejected because there are no direct code/data xrefs to the entry, no IDA function, and no pointer-table route.
  - Callback/vtable entry: rejected because constructors are not vtable callbacks and the selector vtables point at destructor/method slots, not `0x004810f0`.
- Score/final-C++ impact: raise to `84/91` for stronger behavior and source-shape documentation, but completion must stay below 85. Formal C++ remains blank for [UID:0002FH].

### Event Type, Mouse Fields, And Selector State Fields
- Evidence checked: live decompile/callees for `0x004811c0`, current [UID:0002FJ], [UID:0002FC], [UID:00001Y], and local player/UserPane input-lock documentation.
- Best inference:
  - `event+4 == 0`: hover/update.
  - `event+4 == 1`: press/capture or outside dismiss.
  - `event+4 == 3`: release/commit.
  - `event+8` and `event+0xc`: mouse x/y.
  - `this+0xf8`: `m_pressCaptured`.
  - `this+0xf9`: `m_hotRow`.
- Evidence: `OnMouseEvent` gates on `dword_67A748 + 0x13eb1d`, tests points with [UID:000106], writes `this[89]` on hover, writes `this[88] = 1` on press inside, clears the word at `+0xf8/+0xf9` to `0xff00` before release dispatch, and treats `-1` as no row.
- Rejected alternatives:
  - `+0xf8` as row index: rejected because it is used as a boolean gate for release and set only to `1`.
  - `+0xf9` as current chat mode: rejected because current mode lives in the player/chat object at `dword_67A748+0x3eb4`; `+0xf9` is hover/hot row and is reset to `0xff`.
  - separate `+0xfa/+0xfb` fields: rejected because no reads/writes were found in target behavior beyond word-clearing alignment.
- Score/final-C++ impact: field semantics are strong enough for `86/91` and class declaration fields, but the shared `PaneMouseEvent` type and event enum names are not final enough for method-body C++.

### Action Dispatch And Mode Values
- Evidence checked: `0x004811c0` decompile/callees, [UID:0002FD] compact paint mode-label evidence, [UID:0003AU] string resources, [UID:0002FX] color pane constructor, and direct callee list.
- Best inference:
  - row 0 writes mode `0` then calls `sub_5A5110(dword_67A748)`: Talk/default input path.
  - row 1 writes mode `1` then calls `sub_5A5710(dword_67A748)`: Shout.
  - row 2 writes mode `2` then calls `0x005a5450`, currently polluted as `___std_parallel_algorithms_hw_threads@0_10`: Whisper. This is a project chat helper, not a standard-library routine.
  - row 3 writes mode `3` then calls `sub_5A5570`: Group.
  - row 4 writes mode `4` then calls `sub_5A5640`: Clan.
  - row 5 allocates `0x2ac` bytes and calls `sub_4824E0`: opens ChattingColorPane without changing the chat mode byte.
- Rejected alternatives:
  - Color as chat mode 5: rejected because no mode write occurs before the color-pane allocation.
  - `0x005a5450` as STL runtime: rejected because it is called in the exact Whisper row dispatch slot and receives the same chat context pattern as the other chat-mode helpers.
  - row order derived only from strings: rejected as insufficient alone, but validated by compact-paint labels and action dispatch order.
- Score/final-C++ impact: action semantics are strong enough for target docs and coverage rows. Method-body C++ remains blocked by final source names for the row action helpers and the polluted `0x005a5450` alias.

### Popup Dismissal, Compact Refresh, And Pane Adjustments
- Evidence checked: [UID:0002FK], [UID:0002FJ], [UID:0002FC], [UID:00001Y], [UID:0001EA] PaneCore, live `xrefs_to g_pChattingVarietyPane`, and vtable/callee facts.
- Best inference:
  - `this - 0xa0` in decompiled selector methods is the selector's Pane base subobject pointer under IDA's adjusted secondary-vtable view.
  - `this - 0x5c` points at the Pane rectangle/bounds region used for point-in-popup checks.
  - `0x00544690` is `Pane::MarkForDeletion`.
  - Calls through compact-pane vtable slot `+0x48` are best described as compact refresh/repaint/invalidate calls until the Pane virtual slot name is finalized.
- Rejected alternatives:
  - outside click deletes the compact pane: rejected because it calls `MarkForDeletion` on the selector base pointer, and compact pane is only refreshed.
  - `OnDismiss` as destructor: rejected because destructor is [UID:0002FI] at `0x00481150`; `OnDismiss` is a vtable method at `0x00614f88`.
- Score/final-C++ impact: behavior and ownership are clear; exact refresh virtual name and `OnDismiss` return type still block a formal method body.

### Paint, Background, Border, And Geometry Helpers
- Evidence checked: live `analyze_function` for `0x00481490`, `0x004816d0`, `0x00481750`, `0x00481ad0`; support [UID:0002FM]; GrafPort [UID:000162]; Surface/paint helper docs; ResourceLayoutTable lookup docs; [UID:0003AU] strings.
- Best inference:
  - `OnPaint` first invokes selector vtable slots `+0x48` and `+0x4c`, which correspond to `SetupBackground()` and `DrawBorder()`, then draws the six labels twice for shadow/foreground and frames the hot row.
  - `SetupBackground()` loads `SUBWIN`/tile 8 via the resource layout table, sets the inherited background-ready byte at `+0x70`, insets the pane bounds by one pixel, and fills/tiles the interior.
  - `DrawBorder()` draws 7-pixel `SUBWIN.EPF` border tiles in order: top 1, bottom 6, left 3, right 4, corners 0, 2, 5, 7.
  - [UID:000106] is the selector six-row hit-test helper. Row geometry is `(0, row*16+6, 67, row*16+22)` and miss returns `-1`.
- Rejected alternatives:
  - compact `(0,0,62,24)` geometry for selector hit-test: rejected because that geometry belongs to [UID:0002FF]/[UID:0002FG] compact helpers and [UID:0002FC]; selector rows use 67-wide, 16-pixel-spaced item rectangles.
  - one generic `DrawFrame` helper owner: rejected because the vtable slots and class owner make background/border selector methods, while lower-level EPF/Surface helpers stay shared dependencies.
  - final source names from generated output: rejected because generated output currently omits selector class/method bodies and is not authoritative for these helpers.
- Score/final-C++ impact: exact behavior supports `86/91` for paint/background/border/hit-test. Formal C++ remains blank until `EPFTileContext`, `ResourceLayoutTable`, `Surface`/`GrafPort`, `Rect`, and point-test helper declarations are settled.

### Generated-Output Pollution And Support Parent Readiness
- Evidence checked: current generated `auto-generated/NexusTK/social/Chatting.cpp`, previous [UID:00001Y] execution notes, by-class coverage row for [UID:00001Z], and current by-file `Chatting.md`.
- Best inference: generated output is incomplete for the selector and should not drive names. The correct repair is to make [UID:00001Z] emit a declaration-only class shell with fields/virtuals and `[[CHILDREN]]`, then keep method bodies on exact by-memory child pages.
- Rejected alternatives:
  - keeping [UID:00001Z] below 85 while children are raised: rejected by active parent-gate rule.
  - putting selector method bodies into the by-class formal block: rejected by Supervisor.md rule 24; class files should emit class-level code only.
  - moving selector to a new file: rejected because current source-tree and chat UI address clustering keep it in `social/Chatting.cpp`.
- Score/final-C++ impact: [UID:00001Z] should be `87/91`, with class-level C++ populated. Primary method bodies remain blank.

## Evidence Standards Used
- IDA MCP evidence:
  - `lookup_funcs` for `0x004810f0`, `0x00481150`, `0x004811c0`, `0x00481470`, `0x00481490`, `0x004816d0`, `0x00481750`, `0x00481a80`, `0x00481ad0`.
  - `xrefs_to` for `0x004810f0`, each selector vtable method, row helper addresses, `0x004824e0`, `0x0067add8`, and `0x0067addc`.
  - `callees` and `analyze_function` for `0x004811c0`, `0x00481490`, `0x004816d0`, `0x00481750`, and `0x00481ad0`.
- Documentation evidence:
  - [UID:00001Y] `ChattingVarietyPane`
  - [UID:00001Z] `ChattingVarietySelectPane`
  - [UID:0000I5] `Chatting`
  - [UID:0002FC]/[UID:0002FD] compact method-family report and executed docs
  - [UID:0002FM] selector row rectangle helper
  - [UID:0002X5]/[UID:0002X6]/[UID:0002XA]/[UID:0002XB] singleton docs
  - [UID:000162] GrafPort draw-state helper docs
  - [UID:0003AT]/[UID:0003AU] vtable/string data
- Negative evidence used:
  - no IDA function at `0x004810f0`
  - no xrefs to raw constructor entry
  - no pointer-table route to the raw constructor
  - generated `social/Chatting.cpp` does not contain selector method bodies

## IDA MCP Facts
- Function/range facts:
  - `0x004810f0`: no IDA function.
  - `0x00481150`: `ChattingVarietySelectPane_Destructor`, size `0x6c`.
  - `0x004811c0`: `sub_4811C0`, size `0x2a1`.
  - `0x00481470`: `sub_481470`, size `0x1f`.
  - `0x00481490`: `sub_481490`, size `0x23e`.
  - `0x004816d0`: `sub_4816D0`, size `0x71`.
  - `0x00481750`: `sub_481750`, size `0x322`.
  - `0x00481a80`: `sub_481A80`, size `0x4d`.
  - `0x00481ad0`: `sub_481AD0`, size `0x8b`.
- Xref facts:
  - `0x004810f0`: no direct xrefs.
  - `0x004811c0`: data xref from vtable `0x00614f84`.
  - `0x00481470`: data xref from vtable `0x00614f88`.
  - `0x00481490`: data xref from vtable `0x00614f70`.
  - `0x004816d0`: data xref from vtable `0x00614f74`.
  - `0x00481750`: data xref from vtable `0x00614f78`.
  - `0x00481a80`: caller `0x00481605` from selector `OnPaint`.
  - `0x00481ad0`: callers `0x0048124d` and `0x00481430` from selector `OnMouseEvent`.
  - `0x004824e0`: caller `0x00481386` from selector row 5 color path.
  - `0x0067addc`: seven xrefs, including compact mouse/paint, raw selector constructor write, selector destructor, and scalar deleting destructor.
- Callee facts:
  - `0x004811c0` calls `sub_481AD0`, `sub_5A5110`, `sub_544690`, `sub_5A5710`, polluted `0x005a5450`, `sub_5A5570`, `sub_5A5640`, allocator `sub_4F4AA0`, `sub_4824E0`, and `sub_4B7E80`.
  - `0x00481490` calls GrafPort move/text/color/line helpers and [UID:0002FM].
  - `0x004816d0` calls tile context init, resource layout lookup, and background fill/tile helper.
  - `0x00481750` calls tile context, rect copy, rect offset, resource layout lookup, and tile blit helper.
  - `0x00481ad0` calls the rect setter and point-in-rect helper.
- Padding facts:
  - `0x004810ea-0x004810f0`: six bytes of `0xcc` before raw constructor.
  - `0x00481146-0x00481150`: ten bytes of `0xcc` before destructor.
  - existing padding rows around `0x004811bc-0x004811c0` and method boundaries remain valid.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Direct Parent | Current | Recommended | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004810f0-0x00481146` | [UID:0002FH](../../../by-memory/0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md) | raw selector constructor body | [UID:00001Z] | `82/90` | `84/91` | no-85 defended, blank C++ |
| `0x004811c0-0x00481461` | [UID:0002FJ](../../../by-memory/0x004811c0-0x00481461.ChattingVarietySelectPaneOnMouseEvent.md) | selector mouse dispatcher | [UID:00001Z] | `82/90` | `86/91` | above gate, blank C++ |
| `0x00481470-0x0048148f` | [UID:0002FK](../../../by-memory/0x00481470-0x0048148f.ChattingVarietySelectPaneOnDismiss.md) | selector dismiss virtual | [UID:00001Z] | `82/90` | `86/91` | above gate, blank C++ |
| `0x00481490-0x004816ce` | [UID:0002FL](../../../by-memory/0x00481490-0x004816ce.ChattingVarietySelectPaneOnPaint.md) | selector paint virtual | [UID:00001Z] | `82/90` | `86/91` | above gate, blank C++ |
| `0x004816d0-0x00481741` | [UID:0002FN](../../../by-memory/0x004816d0-0x00481741.ChattingVarietySelectPaneSetupBackground.md) | selector background virtual | [UID:00001Z] | `82/90` | `86/91` | above gate, blank C++ |
| `0x00481750-0x00481a72` | [UID:0002FO](../../../by-memory/0x00481750-0x00481a72.ChattingVarietySelectPaneDrawBorder.md) | selector border virtual | [UID:00001Z] | `82/90` | `86/91` | above gate, blank C++ |
| `0x00481ad0-0x00481b5b` | [UID:000106](../../../by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md) | selector six-row hit-test helper | [UID:00001Z] | `82/90` | `86/91` | above gate, blank C++ |

## Documentation Evidence And IDA Status
- Existing docs validated:
  - [UID:00001Z] correctly owns the selector constructor/method/helper family and correctly treats [UID:0002FF]/[UID:0002FG] as related compact-pane helpers rather than selector-owned row geometry.
  - [UID:0000I5] correctly places `ChattingVarietySelectPane` under `Chatting.cpp`.
  - [UID:0002FM] and [UID:000106] row geometry matches live IDA: `(0, row*16+6, 67, row*16+22)`.
- Existing docs needing update:
  - [UID:00001Z] should no longer keep final field naming and unxrefed helper surface as open blockers after this pass. Use `m_pressCaptured`, `m_hotRow`, and the raw constructor no-entry cap.
  - [UID:0002FJ] should name event kinds, state fields, row actions, and the `0x005a5450` callee as the Whisper-mode helper candidate, not STL.
  - [UID:0002FL]/[UID:0002FN]/[UID:0002FO] should name the selector virtuals and resource/tile roles while still marking formal C++ blank due shared render dependency declarations.
  - [UID:000106] should name the helper as `ChattingVarietySelectPane::HitTest(int x, int y)` or file-local `HitTestChatVarietyRow`, with selector-class ownership unchanged.

## Ranked Ownership Analysis

### 1. [UID:00001Z] ChattingVarietySelectPane Under [UID:0000I5] Chatting
- Evidence for: selector vtables, selector singleton, constructor/destructor lifetime, exact vtable slots, chat-mode row dispatch, compact-pane caller/consumer relationship, row geometry, and source-tree grouping.
- Evidence against: raw constructor entry is not an IDA function and has no direct xrefs.
- Decision: accepted. The raw constructor liveness caveat caps only [UID:0002FH], not the modeled selector virtual methods.

### 2. [UID:00001Y] ChattingVarietyPane
- Evidence for: compact pane allocates/opens and refreshes/dismisses selector.
- Evidence against: selector methods are vtable methods on selector object, use selector singleton and selector state fields, and have their own destructor/lifecycle.
- Decision: rejected as owner for assigned targets. Keep compact helpers [UID:0002FF]/[UID:0002FG] with [UID:00001Y].

### 3. [UID:00001T] ChattingColorPane
- Evidence for: selector row 5 constructs color pane.
- Evidence against: only a callee/consumer of one row action, separate allocation size and constructor at `0x004824e0`, separate class docs.
- Decision: rejected as owner. Mention only as row 5 dependency.

### 4. Shared GrafPort/Surface/Resource Helpers
- Evidence for: paint/background/border calls rely on these helpers.
- Evidence against: these are dependencies, not owners; selector vtable slots and state remain class-specific.
- Decision: rejected as owner. Use them as support dependencies and final-C++ blockers.

## Negative Evidence Summary
- Raw constructor:
  - Checked live IDA `lookup_funcs`, `analyze_function`, and `xrefs_to`.
  - No IDA function entry, no entry xrefs, no callback/vtable/pointer-table route.
  - This prevents [UID:0002FH] from reaching 85 completion or driving method-body de-duplication.
- Generated source:
  - Current generated `social/Chatting.cpp` does not prove selector method names/bodies and should not be used as name authority.
- Helper-name pollution:
  - `0x005a5450` has a generated STL-like name, but caller context proves it is the Whisper chat-mode helper candidate. The report rejects the generated name but does not invent an original symbol.
- Parent score:
  - [UID:00001Z] is currently below 85 completion; this report supplies the support-class update needed before supervisor raises children above the gate.

## First-Draft C++ Recommendation

### Primary Targets
- [UID:0002FH] `ChattingVarietySelectPaneConstructorRaw`: do not populate formal C++. It is below 85 completion after this pass (`84/91`) because no callable entry/liveness route is proven.
- [UID:0002FJ] `OnMouseEvent`: do not populate formal method C++ yet. Although the score should be `86/91`, method-body C++ would depend on unsettled `PaneMouseEvent` declaration/enum names, compact refresh virtual name, final chat-mode helper names, the polluted Whisper helper alias at `0x005a5450`, `ChattingColorPane` constructor source shape, and Pane subobject adjustment names.
- [UID:0002FK] `OnDismiss`: do not populate formal method C++ yet. Behavior is resolved, but final source still depends on the compact refresh virtual slot name and the dismiss virtual's return type convention.
- [UID:0002FL] `OnPaint`: do not populate formal method C++ yet. Behavior is resolved, but source-ready C++ depends on final GrafPort/DrawWideText/LineTo/color helper declarations, `Rect` type, [UID:0002FM] row-rect helper readiness, and selector field naming being installed in the class page first.
- [UID:0002FN] `SetupBackground`: do not populate formal method C++ yet. It depends on final `EPFTileContext`, `ResourceLayoutTable` lookup, `SUBWIN` resource/palette declarations, inherited background-ready byte naming, and fill/tile helper signatures.
- [UID:0002FO] `DrawBorder`: do not populate formal method C++ yet. It depends on final tile-context, surface-blit, rectangle offset/copy, and resource lookup declarations.
- [UID:000106] `HitTest`: do not populate formal helper C++ yet. Its behavior is simple and exact, but final source should share `GetVarietyItemRect`/`Rect`/point-test declarations with [UID:0002FM] and the selector method bodies rather than introducing isolated placeholder helper types.

### Support Class [UID:00001Z] First-Draft C++
- Recommendation: populate [UID:00001Z] with declaration-only class C++. This is class-level code, not method-body code, and is safe under Supervisor.md rule 24. It is also necessary to let the above-gate method children attach to a parent that clears the gate.

```cpp
class ChattingColorPane;
struct PaneMouseEvent;

class ChattingVarietySelectPane : public Pane
{
public:
    ChattingVarietySelectPane();
    virtual ~ChattingVarietySelectPane();

protected:
    virtual void OnPaint();
    virtual void SetupBackground();
    virtual void DrawBorder();
    virtual bool OnMouseEvent(const PaneMouseEvent *event);
    virtual bool OnDismiss();

private:
    unsigned char m_pressCaptured;     // +0xf8; set while a press inside the popup is active.
    signed char m_hotRow;              // +0xf9; row 0..5, or -1 when no selector row is hot.
    unsigned char m_reservedFA[2];     // +0xfa..+0xfb; no independent selector fields proven.

    [[CHILDREN]]
};
```

- Safety notes:
  - The base `Pane` inheritance is supported by constructor/destructor calls, Pane virtual slots, and subobject adjustments.
  - The fields are the only selector-specific bytes with target-family reads/writes beyond inherited Pane storage.
  - Method bodies remain exact by-memory children; the class block should not include body logic.
  - The dismiss return type remains inferred from the zero return and vtable use. If the broader Pane virtual type later proves `void`/`int`, this class declaration can be mechanically adjusted without invalidating the ownership/source recommendations.

## Exact Metadata Recommendations
- [UID:0002FH]:
  - `COMPLETION: 84`
  - `CONFIDENCE: 91`
  - Owner/emitter unchanged: [UID:00001Z] `ChattingVarietySelectPane`
  - `RECONSTRUCTION_CPP`: keep blank.
- [UID:0002FJ], [UID:0002FK], [UID:0002FL], [UID:0002FN], [UID:0002FO], [UID:000106]:
  - `COMPLETION: 86`
  - `CONFIDENCE: 91`
  - Owner/emitter unchanged: [UID:00001Z] `ChattingVarietySelectPane`
  - `RECONSTRUCTION_CPP`: keep blank with the explicit target-specific reasons above.
- Support [UID:00001Z]:
  - `COMPLETION: 87`
  - `CONFIDENCE: 91`
  - Owner/emitter unchanged: [UID:0000I5] `Chatting`
  - Populate declaration-only class C++ above.

## Exact Target-Doc Update Recommendations
- [UID:0002FH]: replace open constructor liveness wording with: "IDA still has no function entry or inbound xrefs at `0x004810f0`; the bytes are constructor-shaped and source-equivalent to `ChattingVarietySelectPane::ChattingVarietySelectPane()`, but the documentation should not claim a proven callable out-of-line constructor. This caps completion at 84 and keeps final C++ blank."
- [UID:0002FJ]: add the resolved event/field/action text: "`event+4` values are hover `0`, press `1`, and release `3`; `event+8/+0xc` are x/y. `+0xf8` is `m_pressCaptured`, `+0xf9` is `m_hotRow`. Rows map Talk/Shout/Whisper/Group/Clan/Color. `0x005a5450` is the Whisper-mode helper candidate despite its generated STL-like alias."
- [UID:0002FK]: add: "`OnDismiss` refreshes `g_pChattingVarietyPane` through its repaint/refresh virtual, then calls `Pane::MarkForDeletion` on the selector base. It is not the destructor and does not delete the compact pane."
- [UID:0002FL]: add: "`OnPaint` calls `SetupBackground` and `DrawBorder`, paints Talk/Shout/Whisper/Group/Clan/-Color- labels twice for shadow/foreground, and frames `m_hotRow` using [UID:0002FM] geometry with color order flipped by `m_pressCaptured`."
- [UID:0002FN]: add: "`SetupBackground` loads the `SUBWIN` tile context, sets the inherited background-ready byte at `+0x70`, insets bounds by one pixel, and fills/tiles the interior."
- [UID:0002FO]: add: "`DrawBorder` uses `SUBWIN.EPF` tiles 1/6/3/4 for top/bottom/left/right and 0/2/5/7 for corners, with 7-pixel edge loops."
- [UID:000106]: add: "`HitTest(int x, int y)` loops rows 0..5, tests rectangles `(0,row*16+6,67,row*16+22)`, returns the row id or `-1`, and is called only from selector `OnMouseEvent`."
- [UID:00001Z] support class: update the "Notes / Open Questions" section to remove unresolved field naming and raw helper ownership uncertainty for this selector family, preserve the raw constructor no-entry cap, and add the declaration-only class C++ shown above.

## Exact Coverage Row Recommendations

Placement context: replace the existing rows for [UID:0002FH], [UID:0002FJ], [UID:0002FK], [UID:0002FL], [UID:0002FN], [UID:0002FO], and [UID:000106] in `by-memory/-coverage-report.md` around the current `0x004810f0-0x00481b5b` Chatting selector block. Do not alter padding rows.

```markdown
        - [UID:0002FH][0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw](by-memory/0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md) 0x004810f0-0x00481146 | raw constructor body | ChattingVarietySelectPaneConstructorRaw : reconstructable : 84% : very strong : B003 selector source-quality reanalysis confirms this raw body is source-equivalent to `ChattingVarietySelectPane::ChattingVarietySelectPane()`: it calls the Pane base constructor, writes `g_pChattingVarietySelectPane`, clears `m_pressCaptured`, initializes `m_hotRow` to `-1`, installs selector vtables `0x00614f2c/0x00614f80/0x00614fb0`, and aligns before the destructor; completion stays below 85 because live IDA still has no modeled function, direct xref, callback route, or pointer-table route to `0x004810f0`, so formal C++ remains blank and this body should not by itself de-duplicate the compact popup construction.
        - [UID:0002FJ][0x004811c0-0x00481461.ChattingVarietySelectPaneOnMouseEvent](by-memory/0x004811c0-0x00481461.ChattingVarietySelectPaneOnMouseEvent.md) 0x004811c0-0x00481461 | class method | ChattingVarietySelectPaneOnMouseEvent : reconstructable : 86% : very strong : B003 selector source-quality reanalysis resolves this vtable method as `ChattingVarietySelectPane::OnMouseEvent(const PaneMouseEvent *)`; live IDA confirms the local-player input-lock gate, hover/press/release event kinds `0/1/3`, point fields at `event+8/+0xc`, `m_pressCaptured` at `+0xf8`, `m_hotRow` at `+0xf9`, selector hit-test callers, outside-click dismiss, Talk/Shout/Whisper/Group/Clan mode writes `0..4`, row 5 ChattingColorPane allocation/constructor, compact-pane refresh, and rejection of the polluted `0x005a5450` STL-like name as the Whisper helper; formal C++ remains blank pending final Pane event/refresh types, row-command helper names, and ChattingColorPane source declarations.
        - [UID:0002FK][0x00481470-0x0048148f.ChattingVarietySelectPaneOnDismiss](by-memory/0x00481470-0x0048148f.ChattingVarietySelectPaneOnDismiss.md) 0x00481470-0x0048148f | class method | ChattingVarietySelectPaneOnDismiss : reconstructable : 86% : very strong : B003 selector source-quality reanalysis resolves this vtable method as selector dismiss handling: it refreshes the compact `g_pChattingVarietyPane`, calls `Pane::MarkForDeletion` on the selector base, returns zero, and is distinct from the destructor; formal C++ remains blank pending final compact refresh virtual name and Pane dismiss return-type convention.
        - [UID:0002FL][0x00481490-0x004816ce.ChattingVarietySelectPaneOnPaint](by-memory/0x00481490-0x004816ce.ChattingVarietySelectPaneOnPaint.md) 0x00481490-0x004816ce | class method | ChattingVarietySelectPaneOnPaint : reconstructable : 86% : very strong : B003 selector source-quality reanalysis resolves this vtable method as `ChattingVarietySelectPane::OnPaint`: it calls selector `SetupBackground` and `DrawBorder`, draws Talk/Shout/Whisper/Group/Clan/-Color- labels with shadow/foreground passes, uses [UID:0002FM] row geometry for `m_hotRow`, and flips highlight frame colors by `m_pressCaptured`; formal C++ remains blank pending final GrafPort/text/line/color helper declarations and shared Rect/row helper types.
        - [UID:0002FN][0x004816d0-0x00481741.ChattingVarietySelectPaneSetupBackground](by-memory/0x004816d0-0x00481741.ChattingVarietySelectPaneSetupBackground.md) 0x004816d0-0x00481741 | class method | ChattingVarietySelectPaneSetupBackground : reconstructable : 86% : very strong : B003 selector source-quality reanalysis resolves this vtable method as selector background setup: it initializes a tile context, loads `SUBWIN` tile 8 through the resource layout table, sets the inherited background-ready byte at `+0x70`, insets pane bounds by one pixel, and fills/tiles the interior; formal C++ remains blank pending final EPFTileContext/ResourceLayoutTable/Surface helper declarations.
        - [UID:0002FO][0x00481750-0x00481a72.ChattingVarietySelectPaneDrawBorder](by-memory/0x00481750-0x00481a72.ChattingVarietySelectPaneDrawBorder.md) 0x00481750-0x00481a72 | class method | ChattingVarietySelectPaneDrawBorder : reconstructable : 86% : very strong : B003 selector source-quality reanalysis resolves this vtable method as selector `SUBWIN.EPF` border drawing with top/bottom/left/right tiles `1/6/3/4`, corner tiles `0/2/5/7`, 7-pixel edge loops, and shared tile-context/resource-lookup/blit helpers; formal C++ remains blank pending final EPF/Surface/Rect helper declarations.
        - [UID:000106][0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest](by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md) 0x00481ad0-0x00481b5b | file-local helper | ChattingVarietySelectPaneHitTest : reconstructable : 86% : very strong : B003 selector source-quality reanalysis resolves this as the selector six-row `HitTest(int x, int y)` helper with exclusive callers from `OnMouseEvent`, row rectangles `(0,row*16+6,67,row*16+22)`, returns `0..5` or `-1`, rejects the compact-button helper interpretation, and keeps ChattingVarietySelectPane ownership; formal C++ remains blank pending shared Rect/point-test declarations and [UID:0002FM] row-rect helper code readiness.
```

Support class coverage row, if supervisor updates [UID:00001Z] in `by-class/-coverage-report.md`:

```markdown
- [UID:00001Z][ChattingVarietySelectPane](by-class/ChattingVarietySelectPane.md) : reconstructable : 87% : very strong : B003 selector source-quality reanalysis raises the popup selector class after resolving parent-gate blockers: selector ownership under Chatting.cpp, declaration-only `Pane`-derived class shape, constructor/destructor/method/helper inventory, `m_pressCaptured` at `+0xf8`, `m_hotRow` at `+0xf9`, Talk/Shout/Whisper/Group/Clan/Color row semantics, compact-versus-selector helper boundary, and raw constructor no-entry cap are documented; method bodies remain in exact by-memory children and formal class C++ should contain only the class declaration with `[[CHILDREN]]`.
```

## Support-Doc Update Recommendations
- [UID:00001Z] `ChattingVarietySelectPane`: update score to `87/91`, add declaration-only C++, add field/action notes above, and replace old unresolved field/final-helper wording with evidence-bounded wording.
- [UID:0000I5] `Chatting`: no score change required, but update the selector row to state that the selector class now has a declaration-only emission route and exact child method family at `0x004810f0-0x00481b5b`.
- [UID:00001Y] `ChattingVarietyPane`: no score change required. Keep compact helper and popup construction notes, but do not claim the raw selector constructor proves final method-body de-duplication.
- [UID:0002FM] `ChattingVarietySelectPaneGetItemRect`: no required score change in this assignment, but support text should align with the same `(0,row*16+6,67,row*16+22)` geometry and `GetVarietyItemRect`/`GetSelectorRowRect` source-name direction.
- [UID:0002FX] `ChattingColorPaneConstructor`: no score change required; mention [UID:0002FJ] row 5 as the sole selector color-flow caller.
- [UID:000162] GrafPort draw-state helpers, Surface paint helpers, and ResourceLayoutTable docs: no ownership changes; keep as dependencies for final method-body C++.

## Validation Commands For Supervisor
Run after applying target/support changes:

> Executable block R001 was removed from this report and preserved verbatim in [0002FH-0002FJ-0002FK-0002FL-0002FN-0002FO-000106-chatting-variety-select-pane-source-quality-removed.md](0002FH-0002FJ-0002FK-0002FL-0002FN-0002FO-000106-chatting-variety-select-pane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Changed Files
- Created:
  - `tools/leaser/Agents/Agent-B003/research/0002FH-0002FJ-0002FK-0002FL-0002FN-0002FO-000106-chatting-variety-select-pane-source-quality.md`
- Modified:
  - none outside B003 research.
- Leases used:
  - none.
- Blockers:
  - [UID:0002FH] cannot safely reach 85 completion without a direct entry/caller/pointer route or original symbol evidence.
  - Primary selector method/helper formal C++ should remain blank until shared Pane event/refresh, chat-command helper, ChattingColorPane, EPF/Surface/GrafPort, and Rect declarations are stable.

## Final Recommendation
- Apply the score/metadata row changes above.
- Populate declaration-only C++ for support class [UID:00001Z].
- Do not populate formal C++ for any primary by-memory target in this assignment.
- Keep all primary target owner/emitter routes under [UID:00001Z] -> [UID:0000I5] `Chatting`.
- Do not split this family further.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002FH-0002FJ-0002FK-0002FL-0002FN-0002FO-000106-chatting-variety-select-pane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:28","uid":"0002FH"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002FH-0002FJ-0002FK-0002FL-0002FN-0002FO-000106-chatting-variety-select-pane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002FH-0002FJ-0002FK-0002FL-0002FN-0002FO-000106-chatting-variety-select-pane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002FH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
