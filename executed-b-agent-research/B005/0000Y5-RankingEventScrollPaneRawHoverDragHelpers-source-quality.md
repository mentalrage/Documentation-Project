** TARGET-REPORT-UID:0000Y5 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID0000Y5 RankingEventScrollPaneRawHoverDragHelpers Source-Quality Report

## Finalized Report / Current Recommendation

This is the completed research and implementation-callback artifact for [UID:0000Y5]
`by-memory/0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers.md`.
C01-C27 are incorporated. Scoped validators and final waited autogen completed; no
report lifecycle, manual generated/coverage/tracker/supervisor edit, or IDA mutation was
performed.

The range contains three complete source-shaped `RankingEventScrollPane` methods and
one internal alignment island. UID0000Y5 is now a non-emitting split index with three
exact registered children:

| Exact child | Source-facing method | Binary extent | `Nested` delta | Resulting cumulative indent |
| --- | --- | --- | --- | --- |
| [UID:0004J0] `by-memory/0x0045a990-0x0045a9ff.RankingEventScrollPaneSetHighlightedPartRaw.md` | `SetHighlightedPart(RankingScrollPart)` | `0x0045a990-0x0045aa00` half-open | `+4` | `63` spaces |
| [UID:0004J1] `by-memory/0x0045aa00-0x0045ab48.RankingEventScrollPaneBeginPartInteractionRaw.md` | `BeginPartInteraction(RankingScrollPart, int mouseY, int mouseX)` | `0x0045aa00-0x0045ab49` half-open | `0` | `63` spaces |
| [UID:0004J2] `by-memory/0x0045ab50-0x0045ac0f.RankingEventScrollPaneUpdateActiveInteractionRaw.md` | `UpdateActiveInteraction()` | `0x0045ab50-0x0045ac10` half-open | `0` | `63` spaces |

Validator registration commands `000000008819-000000008821` allocated UIDs `0004J0`,
`0004J1`, and `0004J2` in path order without fabricated/reused identifiers. Their exact
paths, ranges, metadata, bodies, and ordering are implemented below.

The three methods are retained source methods whose ordinary callsites were optimized
or inlined. The lack of IDA function objects and lack of raw-start xrefs is not a valid
blank-C++ reason: the raw instruction bodies, source-family matches, modeled caller
copies, fields, calls, signatures, boundaries, and returns jointly resolve the methods.
The parent remains owned by [UID:0000BO] `RankingEventScrollPane` and emitted through
[UID:0000MZ] `RankingDialog` at `NexusTK/ui/dialogs/RankingDialog.cpp`.

## Supporting Research

Research used the complete target/class/type/file documentation, current generated
`RankingDialog.cpp`, relevant accepted sibling reports and pages, raw executable bytes,
PE section mapping, and read-only IDA MCP evidence collected from database session
`bf5519ae`. The MCP pass began with fresh `tools/list` schema inspection, `idb_list`,
and `server_health`; the database was the only listed NexusTK IDB session and reported
ready auto-analysis, Hex-Rays, and string cache state.

The closest source-family controls were checked rather than used as blind templates:

- `FittingRoomScrollPane` provides byte-identical normalized bodies for the highlight
  setter and active-interaction updater and the same begin-interaction structure.
- `ScrollNewGroupPane` and `ScrollCollectionPane` establish the project vocabulary
  `SetHighlightedPart`, `BeginPartInteraction`, `UpdateActiveInteraction`,
  `ResetInteractionState`, y-first/x-second coordinates, and the owner scroll callback.
- Ranking-specific geometry, fixed vertical thumb span, owner class, field offsets, and
  `SetScrollPosition(0, oldPosition, newPosition)` contract were independently checked
  and are not imported from an analog.
- Accepted B003 UID0000Y6 report
  `tools/leaser/Agents/Agent-B003/research/0000Y6-RankingEventScrollPaneDragToPosition-source-quality.md`,
  exact SHA256 `197763CFB8A279D81C02392E482DF0DFD10DE52B3328D9F473A733EA01C7258C`,
  is the controlling narrow artifact for Destination 6. This B005 rebase preserves its
  exact sentinel, arithmetic, owner-accessor, factorization, score, and support findings.
- The current executed B003 baseline is
  `executed-b-agent-research/B003/0000Y6-RankingEventScrollPaneDragToPosition-source-quality.md`,
  archived SHA256 `C7A3747FC681D5CB6ED5518C02A39335D84284B5B4FF6135D4692862FBC9E721`.
  Its implemented Y6 body, `90/92` score, evidence, and history are immutable inputs to
  the B005 callback except for the required post-insertion relative `Nested:-4` delta.

## Target

- UID: `0000Y5`.
- Current path: `by-memory/0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers.md`.
- Current score: `COMPLETION:90`, `CONFIDENCE:93`.
- Current canonical owner: `0000BO` (`RankingEventScrollPane`).
- Current emitter: `0000BO`, which routes through file owner `0000MZ` (`RankingDialog`).
- Current reconstructable state: `TRUE`.
- Current formal C++: non-emitting split-index marker.
- Current `Nested`: `0`.

## Current Target State

UID0000Y5 is now `90/93`, `Nested:0`, and non-emitting, with exact children UID0004J0,
UID0004J1, and UID0004J2. The seven-byte `0x0045ab49-0x0045ab50` alignment island is
parent-only. Provisional names and blank child C++ are superseded by exact source-ready
bodies. UID0000BO is `89/92` with the accepted class declaration; UID0000Y7 is `89/92`
with `ResetInteractionState`; executed UID0000Y6 remains `90/92` and byte-identical in
formal C++, with only relative `Nested:-4` changed.

The accepted UID0000Y2 raw constructor/setter page is a distinct island. Its blank
formal block and no-standalone proof remain valid and are not weakened by this report.
The implemented class declaration deliberately does not invent callable UID0000Y2
constructor/setter APIs.

## Executive Recommendation

1. Applied: converted UID0000Y5 to a reconstructable, non-emitting split index at `90/93`, retained
   owner/emitter route `0000BO -> 0000MZ`, preserve its correct relative `Nested:0`, and
   keep its formal body blank with an exact non-emitting marker.
2. Applied: created the three exact children above, owned/emitted by UID0000BO, at three contiguous
   class-child emitter positions allocated together immediately before UID0000Y6. Set
   only the first child to `Nested:4`; set the second and third to `Nested:0`.
3. Applied: inserted the exact managed C++ blocks below for all three children.
4. Applied: preserved B003's exact UID0000Y6 `DragToPosition(int y, int x)` implementation and
   `90/92` score, including both sentinel-controlled rectangle initializations,
   no-change return, `GetOwnerPane()`, and factorized owner call; give UID0000Y7 exact
   `ResetInteractionState()` C++ at `89/92`. Change only Y6's relative `Nested` metadata
   from `0` to `-4` so it returns from the new children to the existing sibling level;
   preserve Y7 and following UID0000Y8 at `Nested:0`.
5. Applied: replaced the blank [UID:0000BO] class formal block with the exact declaration below,
   including `RankingScrollPart`, all source-ready methods, the accepted tail fields,
   and `[[CHILDREN]]`; raise the class from `87/89` to `89/92`.
6. Applied: synchronized the layout, vtable, file, and list-owner support prose without changing
   their accepted ownership routes or inventing code in non-emitting type pages.

## Supervisor Active Recheck

The evidence pass was performed on 2026-07-12 against NexusTK IDB database session
`bf5519ae`. At evidence time:

- fresh `idb_list` returned only `bf5519ae`, active for `NexusTK.exe.i64`;
- `server_health` returned `status: ok`, imagebase `0x00400000`, analysis ready,
  Hex-Rays ready, and a populated strings cache;
- `lookup_funcs`, `insn_query`, `disasm`, `decompile`, `xref_query`, `find`,
  `find_bytes`, and `make_signature_for_range` were used read-only;
- no MCP process-management or IDA mutation call was made.

These are evidence-time facts and do not assert that the transient session remains alive
after this report was written.

The overlap rebase used the supervisor-accepted B003 artifact at exact SHA256
`197763CFB8A279D81C02392E482DF0DFD10DE52B3328D9F473A733EA01C7258C` as controlling
Y6 evidence. No new MCP recheck was required because the rebase changed no independent
binary claim and B003's accepted requests already resolved the exact disputed source
shape.

## Inference Research Guidance Check

The report distinguishes direct facts from source-shape inference:

- Direct: bytes, prologues, returns, stack cleanup, fields, calls, branch conditions,
  xrefs, absence of pointer encodings, padding, modeled neighbor boundaries, and vtables.
- Strong inference: human method names and the explicit source-level call from
  `BeginPartInteraction` to `UpdateActiveInteraction`, supported by three homologous
  custom scrollbar families and by the exact inlined Ranking body.
- Rejected inference: generic scrollbar ownership, a standalone free helper, callback
  table entry, compiler-generated code, or a single monolithic source function.
- Conservative declaration decision: accepted UID0000Y2 raw APIs remain undeclared;
  only methods with source-ready bodies or existing accepted formal children are added.

No unresolved item is deferred as generic future research. Operational UID registration
for new files is not an evidence question and must occur only during an authorized
implementation callback.

## Heuristic / Inference Reanalysis And Validation

### Child 1: SetHighlightedPart

`0x0045a990` compares the incoming byte with signed byte `this+0x103`. If unchanged it
returns. If changed, each non-`-1` old/new part is passed to `GetPartRect`, followed by
primary vtable slot `+0x20` invalidation, and the new byte is stored. The method has one
explicit stack argument and `retn 4`.

`SetHoverIndexRaw` is superseded. The accepted field is `m_highlightPart`, the accepted
part type is `RankingScrollPart`, and exact sibling-family source uses
`SetHighlightedPart`. `SetHotPart` and `SetHoverIndex` describe behavior but lose the
project's established source vocabulary.

### Child 2: BeginPartInteraction

`0x0045aa00` has three explicit arguments and `retn 0x0c`. The first is the part byte;
the second is mouse Y; the third is mouse X. For thumb part `2`, it forces thumb
highlight through the same old/new invalidation sequence, gets the thumb rectangle, and
stores `(mouseY - rect.top, mouseX - rect.left)` through `InitPointPair` at
`m_thumbDragOffset +0x108/+0x10c`. It then stores `m_activePart` at `+0x104`, executes a
complete inlined copy of Child 3, and schedules `(0, 200, 0, 0)` through the timer helper.

The best human source is a normal `BeginPartInteraction` method that calls
`UpdateActiveInteraction()` before `ScheduleTimer`. The compiler inlined that call in
the retained raw body. Treating the duplicated instructions as hand-copied source would
be less plausible than the exact homologous FittingRoom/NewGroup source families.

### Child 3: UpdateActiveInteraction

`0x0045ab50` has no explicit stack arguments and a plain `retn`. It obtains the global
cursor and pane screen origin, returns only for the exact invalid-origin pair
`(-1000, -1000)`, and computes local Y then local X. If the active part is thumb `2`, it
calls `DragToPosition(localY, localX)` and returns. Otherwise it calls
`HitTestPart(localY, localX)` and invokes `DragToPosition` only when the hit part equals
`m_activePart`. Finally, any non-none highlight is invalidated and cleared to `-1`.

The early `retn` at `0x0045abbe` belongs to the invalid-origin branch inside this method;
it is not a fourth function boundary. Control continues at the hit-test branch for
valid origins and ends at `0x0045ac0f`.

### DragToPosition

Modeled function `0x0045ac10` has size `0x1b4`, 140 instructions, 21 basic blocks,
cyclomatic complexity 11, two explicit arguments, and `retn 8`. It reads old position,
gets the thumb rectangle, performs two distinct cursor/origin helper pairs, and uses
y-first, x-second drag coordinates. After each sample, that sample's leading or trailing
`m_bounds` copy and orientation-specific edge collapse occur only when
`origin.y != -1000 || origin.x != -1000`. The exact source therefore preserves two
sentinel-controlled initializations and the executable's possible uninitialized local
behavior when both origin components equal `-1000`; unconditional rectangle copies or a
new fallback are rejected.

Horizontal mode uses `x`, `m_thumbDragOffset.x`, and `+1`, clamps the thumb left edge,
and maps it with signed `m_scrollRange` arithmetic and truncating signed division.
Vertical mode uses `y`, `m_thumbDragOffset.y`, and `+1`, clamps the thumb top edge, maps
with `m_scrollRange + 1` through signed truncating division, and then caps to
`m_scrollRange`. There is no denominator guard, nearest rounding, or horizontal
post-cap. Equal old/new position returns before owner lookup or any side effect. On
change, inherited primary vtable slot `+0x1c` is represented by source-facing
`GetOwnerPane()`, and the compiler inlines `RankingEventListPane::SetScrollPosition`.

The independently modeled owner method at `0x0045b200` ends in `retn 0x0c`: argument 1
is an integer and is unused by the body, argument 2 is the old short position, and
argument 3 is the new short position. Both direct calls from `HandleEvent` push `0`, old,
new in that order. The source-facing Y6 tail is therefore
`static_cast<RankingEventListPane *>(GetOwnerPane())->SetScrollPosition(0,
oldPosition, newPosition)`, not a guessed one-argument overload or generic parent-accessor
variant.
The binary's apparent integer/short return is an incidental live register; all callers
ignore it and the behavior is source-level `void`.

### ResetInteractionState

The raw reset at `0x0045add0` removes pending timers, stores `-1` to `m_activePart`, and
invalidates/clears a non-none `m_highlightPart`. Its normalized body matches the accepted
FittingRoom and ScrollNewGroup reset family. `ResetStateRaw` is superseded by the more
specific `ResetInteractionState`.

## Evidence Standards Used

- Exact machine boundaries are recorded half-open in prose and inclusive in established
  by-memory filenames.
- A method name is accepted only when body semantics and source-family vocabulary agree.
- Absence evidence includes code/data xrefs, absolute VA, RVA, file-offset encodings,
  immediate search, branch-target scan, vtable/callback tables, and modeled callers.
- Decompiler failure at a non-function raw start is treated as a modeling limitation,
  not as evidence that source code did not exist.
- Formal code preserves observable calls, coordinate order, both Y6 sentinel-controlled
  rectangle initializations, invalidation, timer values, signedness-sensitive state,
  no-change behavior, and owner callback behavior.

## Evidence Checked

1. Full current target, class, layout, vtable, file owner, list owner, generated source,
   modeled mouse/paint/hit-test/rectangle neighbors, Y6/Y7, and accepted archived reports.
2. MCP database/session identity and health after fresh schema discovery.
3. Function lookup at every target start, internal boundary, predecessor, and successor.
4. Complete raw disassembly for `0x0045a990-0x0045ac10` (232 instructions, untruncated).
5. Prologue, return opcode, stack-cleanup, and padding bytes for every child.
6. Raw-start xref queries in both directions and modeled caller/callee inventories.
7. Code/data/immediate searches and absolute VA/RVA/file-offset pointer-byte searches.
8. Read-only PE `.text` relative branch scan for `E8/E9/0F8x` targets.
9. Range signatures for all three children and homologous scrollbar methods.
10. Modeled Y6 and owner callback disassembly/decompilation, including callsite pushes.
11. Accepted B003 UID0000Y6 artifact at exact SHA256 `197763CFB8A279D81C02392E482DF0DFD10DE52B3328D9F473A733EA01C7258C`,
    including its correction requests `1201-1206`, exact formal block, sentinels,
    no-change return, signed arithmetic, `GetOwnerPane`, and factorization rationale.
12. Executed B003 artifact at archived SHA256
    `C7A3747FC681D5CB6ED5518C02A39335D84284B5B4FF6135D4692862FBC9E721`
    and current UID0000Y6 page read-only: `90/92`, owner/emitter UID0000BO, current
    `Nested:0`, and formal block exactly equal to Destination 6.
13. Current generated `NexusTK/ui/dialogs/RankingDialog.cpp` read-only for executed B003
    UID0000Y6 output plus the remaining Y5/Y7/class marker state.
14. Current generated by-memory coverage read-only for exact local cumulative indent
    `59`, plus validator source sort key `(start,-end,path)` and README relative-delta
    semantics; registered next row after Y7 is UID0000Y8.

Historical report-only phases ran no validators. The accepted callback validator record
is complete under `## Validator Results`; no lifecycle command was run.

## Claim And Incorporation Ledger

| Claim | Accepted recommendation | Evidence | Destination | Callback state |
| --- | --- | --- | --- | --- |
| C01 | UID0000Y5 becomes a non-emitting split index while preserving correct relative `Nested:0`. | Three prologues/returns, internal CC island, and validator relative-delta rules. | UID0000Y5 | Applied/validated `90/93` |
| C02 | Child 1 exact inclusive filename range is `0x45a990-0x45a9ff`; it sorts after same-start wider parent and uses `Nested:4`. | `retn 4` at `0x45a9fd`; sort key `(start,-end,path)`; parent cumulative 59 -> child 63. | UID0004J0 | Applied/validated |
| C03 | Child 1 name/signature is `void SetHighlightedPart(RankingScrollPart)`. | `+0x103`, one arg, sibling-family exact match. | UID0004J0/class | Applied/validated |
| C04 | Child 2 exact inclusive filename range is `0x45aa00-0x45ab48`; it uses `Nested:0` and remains at cumulative 63. | `retn 0x0c` ends at `0x45ab49`; address sort follows child 1. | UID0004J1 | Applied/validated |
| C05 | Child 2 signature is part, mouseY, mouseX. | Stack reads, anchor subtraction, `retn 0x0c`. | UID0004J1/class | Applied/validated |
| C06 | Child 2 calls `UpdateActiveInteraction` at source level. | Exact inlined child-3 body and homologous source family. | UID0004J1 | Applied/validated |
| C07 | Child 2 schedules `(0,200,0,0)`. | Call setup at `0x45ab32`. | UID0004J1 | Applied/validated |
| C08 | `0x45ab49-0x45ab50` is seven-byte padding, not code. | Seven `0xcc` bytes between returns/prologue. | UID0000Y5/children | Applied/validated |
| C09 | Child 3 exact inclusive filename range is `0x45ab50-0x45ac0f`; it uses `Nested:0` and remains at cumulative 63. | Prologue `0x45ab50`, final `retn` `0x45ac0f`; address sort follows child 2. | UID0004J2 | Applied/validated |
| C10 | Child 3 is `void UpdateActiveInteraction()`. | No args, cursor/origin/hit/drag/clear behavior, family match. | UID0004J2/class | Applied/validated |
| C11 | Coordinates are y-first/x-second everywhere. | Event, Point layout, hit-test, anchor, drag arithmetic. | children/Y6/class/layout | Applied/validated |
| C12 | Invalid origin means both coordinates equal `-1000`. | Paired comparisons before early return. | UID0004J2 | Applied/validated |
| C13 | Thumb active path calls DragToPosition unconditionally. | `+0x104 == 2` branch. | UID0004J2 | Applied/validated |
| C14 | Non-thumb path requires hit part equal active part. | `HitTestPart` result compare. | UID0004J2 | Applied/validated |
| C15 | Stale highlight is invalidated then cleared. | `GetPartRect`, vslot `+0x20`, store `0xff`. | UID0004J2/Y7 | Applied/validated |
| C16 | Raw children are retained source methods despite zero direct routes. | Inlined active callsites, byte-identical families, complete bodies. | target/children/class/vtable | Applied/validated |
| C17 | UID0000Y6 preserves B003's exact block, score, and history; only relative `Nested:0 -> -4` changes. | Executed B003 artifact plus validator address-sort/delta rules. | UID0000Y6 | Applied; formal block exact |
| C18 | Changed Y6 path uses `GetOwnerPane()` and `SetScrollPosition(0, old, new)`. | Slot `+0x1c`, `0x45b200 retn 0x0c`, and both modeled callers. | Y6/list/class prose | Preserved/synchronized |
| C19 | UID0000Y7 is `ResetInteractionState` and preserves relative `Nested:0` at cumulative indent 59. | Exact raw body/family match and post-Y6 address order. | UID0000Y7/class | Applied/validated `89/92` |
| C20 | Class block declares all currently source-ready methods and tail fields. | Existing emitted children, layout, vtables, this report. | UID0000BO | Applied/validated `89/92` |
| C21 | UID0000Y2 remains blank/no-standalone and is not split here. | Accepted exhaustive prior proof. | UID0000Y2 | Preserved; generated empty marker verified |
| C22 | Owner/emitter/source route remains `0000BO -> 0000MZ`. | Local vtables, class fields/calls, RankingEventListPane child. | all changed docs | Applied/preserved |
| C23 | Layout/vtable pages remain non-emitting support. | Compiler-generated layout/table role. | UID0001VO/UID0001YK | Applied/validated `88/91`, `88/92` |
| C24 | Generated output refreshes only through validators. | Project workflow and command `000000008841`. | validator-owned output | Completed/read-only verified |
| C25 | No manual coverage/tracker text is required. | Validator-owned generated reports. | external lifecycle | Preserved; no manual edit |
| C26 | B005 rebases on and preserves executed B003 Y6 before broader split/class/Y7 changes. | Supervisor overlap decision and executed B003 SHA. | callback ordering/all shared docs | Applied in required order |
| C27 | Exact order/deltas are ZB `0`/59, Y5 `0`/59, children `+4/0/0` at 63, Y6 `-4`/59, Y7/Y8 `0`/59. | Sort key, README rule, generated command `000000008841`. | parent/children/Y6/Y7/generated coverage | Applied and exact |

## Positive Evidence Summary

- Three ordinary prologues and three ordinary method endings resolve the split.
- Child 1 and Child 3 normalized signatures exactly match independently documented
  source-family methods.
- Child 2 includes the complete Child 3 body, proving an inlined source call rather than
  unrelated adjacent logic.
- The raw children call only established Ranking helpers and shared Pane/EventMan APIs.
- Modeled OnMouseEvent duplicates the same hover/press/drag behavior at active callsites.
- Accepted `RankingScrollPart`, fields, rectangle helper, hit test, and coordinate order
  make the bodies source-ready without provisional decompiler types.
- B003's accepted Y6 pass and the list-owner method jointly resolve both sentinel-gated
  rectangle construction and the exact three-argument owner callback.
- Y7 exact signature match resolves its source name and body.

## IDA MCP Facts

- No IDA function object exists at `0x45a990`, `0x45aa00`, `0x45ab50`, or internal
  endpoints. Predecessor `GetPartRect` is modeled at `0x45a710`; successor Y6 is modeled
  at `0x45ac10`.
- The target raw range contains 232 decoded instructions with no truncation.
- Raw child decompile attempts fail specifically because no function object exists.
- Calls in the three raw bodies include `GetPartRect`, invalidation vslot `+0x20`,
  `InitPointPair`, `EventMan::GetCursorPosition`, `GetScreenOffset`, `HitTestPart`,
  `DragToPosition`, `ScheduleTimer`, and security-cookie checks.
- `0x544e90`, installed at tertiary vtable slot `+0x04`, decompiles as a base/default
  return-true/no-op update callback; it is not these source helpers.
- `0x45b200` ends `retn 0x0c` and implements owner/list scroll synchronization.

## Function / Child Inventory

| Address | IDA status | Resolved source role | Return |
| --- | --- | --- | --- |
| `0x45a710-0x45a98b` | modeled | `GetPartRect` predecessor | `retn 8` |
| `0x45a98b-0x45a990` | padding | five `0xcc` bytes | none |
| `0x45a990-0x45aa00` | raw | `SetHighlightedPart` | `retn 4` |
| `0x45aa00-0x45ab49` | raw | `BeginPartInteraction` | `retn 0x0c` |
| `0x45ab49-0x45ab50` | padding | seven `0xcc` bytes | none |
| `0x45ab50-0x45ac10` | raw | `UpdateActiveInteraction` | plain `retn` |
| `0x45ac10-0x45adc4` | modeled | `DragToPosition` | `retn 8` |
| `0x45adc4-0x45add0` | padding | twelve `0xcc` bytes | none |
| `0x45add0-0x45ae2c` | raw | `ResetInteractionState` | plain `retn` |

## Direct Xref / Caller Inventory

No raw child start has an incoming code or data xref. No vtable slot points to a child.
No callback/data table contains a child address. No direct relative branch in `.text`
targets a raw child start.

The meaningful route is optimization/inlining:

- modeled `OnMouseEvent` contains the active hover/begin/update/reset behavior;
- Child 2 contains a complete inlined Child 3 body;
- Child 3 calls modeled `DragToPosition` at `0x45abab` and `0x45abd4`;
- Child 2's inlined updater calls Y6 at `0x45aad8` and `0x45aaf4`;
- modeled OnMouseEvent calls Y6 at `0x459c1c` and `0x459c38`.

## Documentation Evidence And IDA Status

Current documents already establish the source route, vtables, part enum, fields,
painting, mouse event behavior, hit testing, and rectangle geometry. This report closes
the remaining interaction island and its immediately coupled Y6/Y7/class blockers. It
does not overwrite accepted evidence from UID0000Y2, Y3, Y4, Z9, ZA, or ZB.

At the original evidence point, generated `RankingDialog.cpp` contained exact
Y3/Z9/ZA/Y4/ZB bodies but empty markers for UID0000BO, UID0000Y5, UID0000Y6, and
UID0000Y7. B003 owns replacement of the historical UID0000Y6 marker. The later B005
callback must consume that generated/doc state without rewriting Y6, then add the Y5
children, broader class block, and Y7. The historical markers are not reasons to weaken
any reconstructed body.

## Ranked Ownership Analysis

1. **RankingEventScrollPane / RankingDialog: accepted.** All fields are within the
   accepted `0x110` layout, every class-local call resolves to Ranking helpers or
   inherited Pane APIs, active callers are Ranking mouse logic, and the class vtables
   and list-child construction are local to RankingDialog.
2. **Generic custom scrollbar source: rejected.** Homologous bodies prove source-family
   naming but use different classes, resources, owner callbacks, and geometry constants.
3. **RankingEventListPane ownership: rejected as direct owner.** It consumes the scroll
   result and allocates the child but does not own these `this+0xf8..0x10c` methods.
4. **Compiler-generated/runtime ownership: rejected.** The methods contain UI policy,
   project types, timers, invalidation, and drag geometry; only inlining is compiler work.

## Source Placement

- Direct class owner/emitter: [UID:0000BO] `RankingEventScrollPane`.
- Direct source file owner: [UID:0000MZ] `RankingDialog`.
- Generated route: `NexusTK/ui/dialogs/RankingDialog.cpp`.
- The three children should be ordered immediately after UID0001ZB `GetPartRect` and
  before UID0000Y6 `DragToPosition`, preserving executable/source-family order.
- UID0000Y7 follows Y6 after its existing padding boundary.

## Range / Split / Padding / Reclassification Analysis

The current inclusive filename range `0x45a990-0x45ac0f` should remain as an index
because it is an established tracker target and useful source-family container. It must
not emit code once exact children exist. The split excludes only the seven-byte internal
padding island. No byte is duplicated between child pages, and neighboring GetPartRect,
Y6, and Y7 remain separate existing pages.

Child 3's early return at `0x45abbe` is an internal basic-block exit, not a split. Child
2's body is not split again at its inlined updater because there is no second prologue or
independent return boundary; source-level factorization is represented by the explicit
`UpdateActiveInteraction()` call in the C++ draft.

`tools/validator_background.py` sorts memory rows by `(start, -end, normalized path)`.
`tools/validator_README.txt` defines `Nested` as a relative indentation delta from the
previous sorted row, not a child count. The current generated coverage row for preceding
UID0001ZB and the Y5/Y6/Y7 neighborhood has cumulative indentation `59` spaces. Adding
the proposed paths produces this exact order and transition plan:

| Sort order | Row | Start/end used by sort | Relative `Nested` | Cumulative indent | Reason |
| --- | --- | --- | --- | --- | --- |
| 1 | UID0001ZB `GetPartRect` | `0x45a710-0x45a98a` | existing `0` | `59` | preceding sibling baseline |
| 2 | UID0000Y5 parent | `0x45a990-0x45ac0f` | preserve `0` | `59` | sibling split index |
| 3 | new `SetHighlightedPart` | `0x45a990-0x45a9ff` | `+4` | `63` | same start as parent; wider parent sorts first because `-end` |
| 4 | new `BeginPartInteraction` | `0x45aa00-0x45ab48` | `0` | `63` | second child at same child level |
| 5 | new `UpdateActiveInteraction` | `0x45ab50-0x45ac0f` | `0` | `63` | third child at same child level |
| 6 | executed UID0000Y6 | `0x45ac10-0x45adc3` | change `0 -> -4` | `59` | leave child group for sibling Y6 |
| 7 | UID0000Y7 | `0x45add0-0x45ae2b` | preserve `0` | `59` | following sibling reset |
| 8 | UID0000Y8 adjustor thunks | `0x45bddd-0x45bdf2` | preserve `0` | `59` | next registered address-sorted row |

There is no registered exact row at modeled successor `0x45ae30`; the next registered
row after Y7 is UID0000Y8. The only same-start pair introduced here is the Y5 parent and
Child 1, and the larger parent end guarantees parent-first order. The first child alone
opens one four-space nesting level. Child 2 and Child 3 do not deepen it. Y6 alone closes
that level with `-4`; Y7 and Y8 therefore require no metadata edit.

## Negative Evidence Summary

- Zero direct code/data xrefs to all three raw starts.
- Zero absolute-VA byte hits for `0x0045a990`, `0x0045aa00`, `0x0045ab50`.
- Zero RVA byte hits for `0x0005a990`, `0x0005aa00`, `0x0005ab50`.
- Zero file-offset byte hits for `0x00059d90`, `0x00059e00`, `0x00059f50`; mapping uses
  `.text` RVA `0x1000`, raw offset `0x400`.
- Zero `.text` relative E8/E9/0F8x branches to the three starts.
- No vtable/callback slot or modeled function object at the starts.
- No evidence for free-function ownership, a fourth function at `0x45abbe`, a generic
  scrollbar file, x-first parameters, or standalone emitted aggregate code.

These negatives cap original-symbol certainty but do not defeat reconstruction because
the executable bodies and inlined active routes are exhaustive.

## IDA Rename / Type / Comment Recommendations

No IDA mutation is part of this report. If an authorized IDA curation pass occurs
separately, the evidence supports function creation and names equivalent to:

- `RankingEventScrollPane__SetHighlightedPart` at `0x0045a990`;
- `RankingEventScrollPane__BeginPartInteraction` at `0x0045aa00`;
- `RankingEventScrollPane__UpdateActiveInteraction` at `0x0045ab50`;
- `RankingEventScrollPane__DragToPosition` at `0x0045ac10`;
- `RankingEventScrollPane__ResetInteractionState` at `0x0045add0`.

Recommended prototypes are the exact class declarations below. The seven `0xcc` bytes
must remain alignment, not a function tail or data object.

## First-Draft C++ Recommendation

### Destination 1: UID0000Y5 parent split index

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0000Y5] Non-emitting split index. Exact child pages own the three methods.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 2: by-class/RankingEventScrollPane.md

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
enum RankingScrollPart {
    kRankingScrollPartLeading = 0,
    kRankingScrollPartPageBeforeThumb = 1,
    kRankingScrollPartThumb = 2,
    kRankingScrollPartPageAfterThumb = 3,
    kRankingScrollPartTrailing = 4,
    kRankingScrollPartNone = -1
};

const int kRankingScrollThumbSpan = 38;

class RankingEventScrollPane : public Pane {
public:
    virtual bool OnMouseEvent(const PaneMouseEvent& event);
    virtual bool HasActiveEffect();
    virtual void OnPaint();

private:
    RankingScrollPart HitTestPart(int y, int x);
    void GetPartRect(RankingScrollPart part, RectBounds *outRect);
    void SetHighlightedPart(RankingScrollPart part);
    void BeginPartInteraction(RankingScrollPart part, int mouseY, int mouseX);
    void UpdateActiveInteraction();
    void DragToPosition(int y, int x);
    void ResetInteractionState();

    short m_scrollSkinIndex;
    unsigned char m_scrollStyle;
    bool m_thumbDragActive;
    unsigned char m_orientation;
    short m_scrollPosition;
    short m_scrollRange;
    bool m_enabled;
    signed char m_highlightPart;
    signed char m_activePart;
    Point m_thumbDragOffset;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

This declaration intentionally omits raw UID0000Y2 constructor/setter candidates. It is
complete for all accepted source-ready emitted member definitions and preserves natural
compiler padding at `+0xfd` and `+0x105..+0x107`.

### Destination 3: new SetHighlightedPart child

Exact path:
`by-memory/0x0045a990-0x0045a9ff.RankingEventScrollPaneSetHighlightedPartRaw.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void RankingEventScrollPane::SetHighlightedPart(RankingScrollPart part)
{
    RectBounds rect;
    const RankingScrollPart oldPart =
        static_cast<RankingScrollPart>(m_highlightPart);

    if (oldPart == part)
        return;

    if (oldPart != kRankingScrollPartNone) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
    }

    if (part != kRankingScrollPartNone) {
        GetPartRect(part, &rect);
        InvalidateRect(&rect);
    }

    m_highlightPart = static_cast<signed char>(part);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4: new BeginPartInteraction child

Exact path:
`by-memory/0x0045aa00-0x0045ab48.RankingEventScrollPaneBeginPartInteractionRaw.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void RankingEventScrollPane::BeginPartInteraction(RankingScrollPart part,
                                                  int mouseY,
                                                  int mouseX)
{
    RectBounds rect;

    if (part == kRankingScrollPartThumb) {
        if (m_highlightPart != kRankingScrollPartThumb) {
            if (m_highlightPart != kRankingScrollPartNone) {
                GetPartRect(static_cast<RankingScrollPart>(m_highlightPart),
                            &rect);
                InvalidateRect(&rect);
            }

            GetPartRect(kRankingScrollPartThumb, &rect);
            InvalidateRect(&rect);
            m_highlightPart =
                static_cast<signed char>(kRankingScrollPartThumb);
        }

        GetPartRect(kRankingScrollPartThumb, &rect);
        InitPointPair(&m_thumbDragOffset,
                      mouseY - rect.top,
                      mouseX - rect.left);
    }

    m_activePart = static_cast<signed char>(part);
    UpdateActiveInteraction();
    ScheduleTimer(0, 200, 0, 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 5: new UpdateActiveInteraction child

Exact path:
`by-memory/0x0045ab50-0x0045ac0f.RankingEventScrollPaneUpdateActiveInteractionRaw.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void RankingEventScrollPane::UpdateActiveInteraction()
{
    Point cursor;
    Point origin;
    RectBounds rect;

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);

    if (origin.y == -1000 && origin.x == -1000)
        return;

    const int localY = cursor.y - origin.y;
    const int localX = cursor.x - origin.x;

    if (m_activePart == kRankingScrollPartThumb) {
        DragToPosition(localY, localX);
        return;
    }

    if (HitTestPart(localY, localX) ==
        static_cast<RankingScrollPart>(m_activePart)) {
        DragToPosition(localY, localX);
    }

    if (m_highlightPart != kRankingScrollPartNone) {
        GetPartRect(static_cast<RankingScrollPart>(m_highlightPart), &rect);
        InvalidateRect(&rect);
        m_highlightPart =
            static_cast<signed char>(kRankingScrollPartNone);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 6: UID0000Y6 DragToPosition

This is the exact accepted B003 managed block. It is retained here as the shared
class/split preservation baseline, not as a competing B005 rewrite.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void RankingEventScrollPane::DragToPosition(int y, int x)
{
    const short oldPosition = m_scrollPosition;
    RectBounds thumbRect;
    RectBounds leadingRect;
    RectBounds trailingRect;
    Point cursor;
    Point origin;

    GetPartRect(kRankingScrollPartThumb, &thumbRect);

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    if (origin.y != -1000 || origin.x != -1000) {
        leadingRect = m_bounds;
        if (m_orientation != 0) {
            leadingRect.right = leadingRect.left;
        } else {
            leadingRect.bottom = leadingRect.top;
        }
    }

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    if (origin.y != -1000 || origin.x != -1000) {
        trailingRect = m_bounds;
        if (m_orientation != 0) {
            trailingRect.left = trailingRect.right;
        } else {
            trailingRect.top = trailingRect.bottom;
        }
    }

    short newPosition;
    if (m_orientation != 0) {
        int thumbStart = x - m_thumbDragOffset.x + 1;
        const int trackStart = leadingRect.right;
        if (thumbStart < trackStart) {
            thumbStart = trackStart;
        }

        const int maxThumbStart = trailingRect.left +
            thumbRect.left - thumbRect.right;
        if (thumbStart > maxThumbStart) {
            thumbStart = maxThumbStart;
        }

        const int trackSpan = trailingRect.left + thumbRect.left -
            thumbRect.right - leadingRect.right;
        newPosition = static_cast<short>(
            (m_scrollRange * (thumbStart - leadingRect.right)) /
            trackSpan);
    } else {
        int thumbStart = y - m_thumbDragOffset.y + 1;
        const int trackStart = leadingRect.bottom;
        if (thumbStart < trackStart) {
            thumbStart = trackStart;
        }

        const int maxThumbStart = trailingRect.top +
            thumbRect.top - thumbRect.bottom;
        if (thumbStart > maxThumbStart) {
            thumbStart = maxThumbStart;
        }

        const int trackSpan = trailingRect.top + thumbRect.top -
            thumbRect.bottom - leadingRect.bottom;
        newPosition = static_cast<short>(
            ((m_scrollRange + 1) *
             (thumbStart - leadingRect.bottom)) /
            trackSpan);

        if (newPosition > m_scrollRange) {
            newPosition = m_scrollRange;
        }
    }

    if (oldPosition == newPosition) {
        return;
    }

    RankingEventListPane *owner =
        static_cast<RankingEventListPane *>(GetOwnerPane());
    owner->SetScrollPosition(0, oldPosition, newPosition);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 7: UID0000Y7 RawResetState

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void RankingEventScrollPane::ResetInteractionState()
{
    RectBounds rect;
    const RankingScrollPart oldPart =
        static_cast<RankingScrollPart>(m_highlightPart);

    RemovePendingTimers();
    m_activePart = static_cast<signed char>(kRankingScrollPartNone);

    if (oldPart != kRankingScrollPartNone) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
        m_highlightPart =
            static_cast<signed char>(kRankingScrollPartNone);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

There are exactly seven destination-specific managed blocks. Destination 6 is the exact
B003-owned upstream block and must be preserved rather than independently rewritten by
B005. No other C++ declaration, body, or code edit is proposed elsewhere in this report.

## Final Recommendation

C01-C27 were applied in the accepted order. B005 rebased on executed B003 Y6, verified
Destination 6 unchanged, changed only Y6 relative `Nested:0 -> -4`, then applied the Y5
split, UIDs 0004J0/0004J1/0004J2, class shell, Y7, and combined support evidence without
overwriting Y6 code or research. UID0000Y2 remains the intentional empty emitter marker.
Layout/vtable/file/list support is synchronized without speculative managed code.

## Recommended Target Doc Changes

- Preserved UID, owner, emitter route, reconstructable state, and inclusive parent range.
- Changed score `86/90 -> 90/93`.
- Preserved `Nested:0`; it keeps the parent at cumulative indent 59 after preceding
  UID0001ZB and is not a count of the three children.
- Changed disposition to non-emitting split index.
- Added the exact child table, boundary/padding inventory, raw liveness evidence,
  source-method/inlining disposition, positive and negative evidence, exact
  address-sort/nesting table, and changes entry.
- Inserted Destination 1 formal marker only.

## Recommended Support Doc Changes

- `by-class/RankingEventScrollPane.md`: inserted Destination 2 and updated names,
  inventory, fields, split, inlining, Y6/Y7, liveness, and score to `89/92` from the
  executed B003 `88/90` baseline without altering Y6 formal C++.
- Created UID0004J0/UID0004J1/UID0004J2 with Destinations 3-5, owner/emitter UID0000BO,
  reconstructable true, source order before Y6, and `Nested:4/0/0`.
- UID0000Y6: preserved Destination 6, `90/92`, sentinel behavior, history, and owner
  factorization; changed only `Nested:0 -> Nested:-4`.
- UID0000Y7: inserted Destination 7, adopted `ResetInteractionState`, retained path/UID
  and `Nested:0`, and changed score `86/90 -> 89/92`.
- UID0000Y8: not edited; verified existing `Nested:0` at cumulative indent 59.
- UID0001VO layout: kept formal blank and owner/emitter/route unchanged; synchronized
  the full tail lifecycle and changed executed B003 `87/91 -> 88/91`.
- UID0001YK vtables: kept formal blank and owner/emitter/route unchanged; added complete
  nonvirtual/raw-route negative evidence and changed `86/90 -> 88/92`.
- UID0000BN RankingEventListPane: kept score/metadata/formal block unchanged and added
  exact Y5 child-consumer context while preserving three-argument Y6 factorization.
- UID0000MZ RankingDialog: kept score/metadata/path unchanged and synchronized the exact
  split/class/reset/generated inventory.
- UID0000Y2/Y3/Y4/Z9/ZA/ZB formal blocks, scores, metadata, and accepted evidence were
  preserved.

## Score And Metadata Recommendation

| Document | Before | After | Relative `Nested` / cumulative indent | Metadata disposition |
| --- | --- | --- | --- | --- |
| UID0000Y5 parent | `86/90` | `90/93` | preserve `0` / `59` | same owner/emitter; non-emitting index |
| UID0004J0 SetHighlightedPart | new | `90/93` | `+4` / `63` | owner/emitter 0000BO; reconstructable true |
| UID0004J1 BeginPartInteraction | new | `90/92` | `0` / `63` | owner/emitter 0000BO; reconstructable true |
| UID0004J2 UpdateActiveInteraction | new | `90/93` | `0` / `63` | owner/emitter 0000BO; reconstructable true |
| UID0000Y6 | executed `90/92` | preserve `90/92` | `0 -> -4` / `59` | preserve B003 code/owner/emitter/range/history |
| UID0000Y7 | `86/90` | `89/92` | preserve `0` / `59` | same owner/emitter/range/path |
| UID0000Y8 following row | unchanged | unchanged | preserve `0` / `59` | read-only ordering verification |
| UID0000BO class | executed B003 `88/90` | `89/92` | n/a | same owner/emitter/source route |
| UID0001VO layout | executed B003 `87/91` | `88/91` | n/a | same owner/emitter; formal blank |
| UID0001YK vtables | `86/90` | `88/92` | n/a | same owner/emitter; formal blank |

The class remains below nominal completion 90 because UID0000Y2's accepted raw
constructor/setter API surface is intentionally not declared. Confidence can reach 92
because all currently emitted/source-ready methods, layout tail, and virtual slots are
resolved. Support-file/list scores remain unchanged where this pass does not re-audit
their entire class surface. B003's narrow support outcomes are preserved as the callback
baseline: class `88/90`, layout `87/91`, vtable `86/90`, list unchanged, and file
unchanged after Y6. B005 then applied class `89/92`, layout `88/91`, and vtable `88/92`
with added Y5/Y7/class evidence without deleting or compressing B003's Y6 evidence.

## Open Questions With Attempted Resolution

### Were the raw methods ever directly callable?

All available direct-route mechanisms were exhausted and returned none. The inlined
active copies and homologous retained methods resolve them as ordinary source methods
optimized away as standalone call targets in this build. No further liveness route is
needed to justify source reconstruction.

### Is Child 2 one method or two fused methods?

One binary method. It has one prologue, one stack frame, one security cookie, and one
`retn 0x0c`. Source factorization is a call to Child 3 that the compiler inlined.

### Is Child 3's early return another method end?

No. It is reached only from the invalid-origin branch and shares the same frame/cookie;
valid control flow continues to the hit-test path.

### Is the owner callback one argument or three?

Three. `0x45b200` uses old/new shorts, ends in `retn 0x0c`, and its modeled callers push
an additional leading zero. Y6's inlined form is source-equivalent to obtaining the
owner through `GetOwnerPane()` and calling
`SetScrollPosition(0, oldPosition, newPosition)`.

### Are the Y6 leading and trailing rectangles initialized unconditionally?

No. B003's accepted full disassembly proves two independent cursor/origin samples. Each
rectangle copy and edge collapse is guarded by
`origin.y != -1000 || origin.x != -1000`. Destination 6 preserves that exact behavior,
including the binary's possible uninitialized local state when both sentinel components
are `-1000`; unconditional initialization and a defensive fallback are rejected.

### Is `Nested` the number of children?

No. The validator adds each row's signed delta to the prior address-sorted cumulative
indent. Current generated rows establish the local baseline as 59 spaces. The same-start
wider Y5 parent sorts before Child 1, so the exact transitions are parent `0`/59, Child 1
`+4`/63, Child 2 `0`/63, Child 3 `0`/63, executed Y6 `-4`/59, Y7 `0`/59, and next
registered UID0000Y8 `0`/59. Parent `Nested:0` is therefore correct.

### Should the class declare raw UID0000Y2 methods?

No. Its accepted exhaustive proof establishes behavior but not callable source APIs.
The class block is intentionally complete for current source-ready emitters while
preserving that specific uncertainty.

### Does `Point` use x/y or y/x storage?

The project type stores `y` at the first dword and `x` at the second. Event arguments,
anchor subtraction, hit test, and drag branches all independently confirm y-first,
x-second parameter order.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

None. The affected coverage/tracker artifacts are validator-owned generated output.
The durable source of truth is the approved `by-*` metadata and child registration;
their generated representation should be produced only by normal validator refresh.
This report makes no claim about any future or archived report count.

## Follow-Up Actions

All B005 research and implementation-callback responsibilities are complete. C01-C27
are incorporated and generated output is verified. Executed B003 Y6 remains the
preserved baseline except for its required relative nesting delta. Gate 2 review,
report execution, count/path state, movement, and archival remain supervisor-owned
external lifecycle state and are not pending B005 implementation work.

## Confidence

- Boundary/split confidence: `99%`.
- Field, coordinate, return, and call semantics: `97%`.
- Class/file ownership and emitter route: `99%`.
- Source method-vs-inline disposition: `94%`.
- Source-facing names: `92%` overall; exact original spelling cannot be proven without
  symbols, but accepted family vocabulary and behavior converge strongly.
- Formal body behavioral fidelity: `94%`; B003's accepted Y6 sentinels, signed division,
  no-change return, `GetOwnerPane`, owner call, and incidental-return rejection are
  preserved exactly rather than normalized into cleaner but inaccurate code.

## Validator Results

All commands ran from `source-3/project-documentation`, used `--apply --queue-timeout
240`, and exited `0`. `ok` is the count of literal `ok:` result rows; new-file UID
allocation commands instead report `insert_uid/path_update` mutations.

| File / purpose | command_id | command_timestamp | exit | ok | Generated state / result |
| --- | --- | --- | --- | --- | --- |
| UID0004J0 allocate/register/validate | `000000008819` | `2026-07-12T21:21:11-04:00` | `0` | `0` | UID `0004J0`; refresh deferred |
| UID0004J1 allocate/register/validate | `000000008820` | `2026-07-12T21:21:39-04:00` | `0` | `0` | UID `0004J1`; refresh deferred |
| UID0004J2 allocate/register/validate | `000000008821` | `2026-07-12T21:21:53-04:00` | `0` | `0` | UID `0004J2`; refresh deferred |
| UID0000Y5 parent | `000000008822` | `2026-07-12T21:22:56-04:00` | `0` | `1` | `90/93`, marker block; refresh deferred |
| executed UID0000Y6 metadata | `000000008824` | `2026-07-12T21:23:17-04:00` | `0` | `1` | `Nested:-4`; refresh deferred |
| UID0000Y7 reset | `000000008831` | `2026-07-12T21:24:02-04:00` | `0` | `1` | `89/92`, formal block; refresh deferred |
| UID0000BO class | `000000008835` | `2026-07-12T21:25:00-04:00` | `0` | `1` | `89/92`, class block; refresh deferred |
| UID0001VO layout | `000000008837` | `2026-07-12T21:25:55-04:00` | `0` | `1` | `88/91`; refresh deferred |
| UID0001YK vtables | `000000008838` | `2026-07-12T21:26:31-04:00` | `0` | `1` | `88/92`; refresh deferred |
| UID0000BN list support | `000000008839` | `2026-07-12T21:27:04-04:00` | `0` | `1` | metadata unchanged; refresh deferred |
| UID0000MZ file support | `000000008840` | `2026-07-12T21:27:50-04:00` | `0` | `1` | metadata unchanged; refresh deferred |
| final autogen `--wait-generated` | `000000008841` | `2026-07-12T21:28:15-04:00` | `0` | `0` | foreground generated refresh completed |

Generated headers equal final command `000000008841` and timestamp
`2026-07-12T21:28:15-04:00`. Read-only proof:

- `auto-generated/-ag-coverage-report-by-memory.md` orders UID0001ZB 59, UID0000Y5 59,
  UID0004J0/UID0004J1/UID0004J2 63, UID0000Y6 59, UID0000Y7 59, UID0000Y8 59.
- `auto-generated/NexusTK/ui/dialogs/RankingDialog.cpp` contains one class declaration,
  one `SetHighlightedPart`, one `BeginPartInteraction`, one `UpdateActiveInteraction`,
  one byte-preserved `DragToPosition`, and one `ResetInteractionState`, in method order.
- UID0000Y5 emits its non-empty split marker and has no Empty Emitter Marker. UID0000Y2
  remains the expected Empty Emitter Marker. No duplicate Y5/Y6/Y7 method exists.
- Destination 6 still compares exactly with current executed UID0000Y6 formal C++.

Lease sequencing note: all manual child creation occurred while the existing parent
split lease was held. For UID0004J0, the combined lease-wrapper command used the wrong
working directory, so validator `000000008819` registered the already-created file after
the parent lease release; B005 then explicitly leased/released UID0004J0 without a
second validator to preserve the one-validator-per-file rule. Every other edited file
was leased successfully before edit/validation and released immediately afterward.

## Changed Files

- Updated callback artifact:
  `tools/leaser/Agents/Agent-B005/research/0000Y5-RankingEventScrollPaneRawHoverDragHelpers-source-quality.md`.
- Created and registered:
  - `by-memory/0x0045a990-0x0045a9ff.RankingEventScrollPaneSetHighlightedPartRaw.md` (UID0004J0).
  - `by-memory/0x0045aa00-0x0045ab48.RankingEventScrollPaneBeginPartInteractionRaw.md` (UID0004J1).
  - `by-memory/0x0045ab50-0x0045ac0f.RankingEventScrollPaneUpdateActiveInteractionRaw.md` (UID0004J2).
- Modified and scoped-validated:
  - `by-memory/0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers.md`.
  - `by-memory/0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition.md` (`Nested` only).
  - `by-memory/0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState.md`.
  - `by-class/RankingEventScrollPane.md`.
  - `by-class/RankingEventListPane.md`.
  - `by-type/by-struct/RankingEventScrollPaneLayout.md`.
  - `by-type/by-vtable/RankingEventScrollPaneVtables.md`.
  - `by-file/RankingDialog.md`.
- Leases: parent split lease plus each listed existing/new destination; every successful
  B005 lease was released. Current lease report has no B005 entry.
- Generated/coverage files changed only by validators. No generated, coverage, tracker,
  supervisor, MCP/IDA, or lifecycle file was manually edited.

## Implementation Tracking Checklist

### Completed report-only research

- [x] Read the full updated B005 goal and complete project B-agent workflow/standards.
- [x] Read target, class, layout, vtable, file, owner, neighboring methods, generated
      source, analogs, and relevant accepted prior evidence.
- [x] Refreshed MCP schema/session list and verified evidence-time IDB health.
- [x] Revalidated every prologue, return, stack cleanup, exact range, and padding island.
- [x] Exhausted modeled/raw/xref/immediate/VA/RVA/file-offset/vtable/callback/branch routes.
- [x] Resolved hover, active part, drag anchor, timer, coordinates, invalidation,
      hit-test, rectangle, Y6 mapping, owner callback, and reset semantics.
- [x] Resolved source method versus inline disposition and source-facing names.
- [x] Rebased every Y6 claim and Destination 6 on accepted B003 SHA256
      `197763CFB8A279D81C02392E482DF0DFD10DE52B3328D9F473A733EA01C7258C`.
- [x] Preserved B003's two sentinel-controlled rectangle initializations, signed
      arithmetic, vertical-only cap, no-change return, `GetOwnerPane`, owner call, and
      `90/92` score.
- [x] Calculated validator sort order `(start,-end,path)`, current cumulative indent 59,
      child cumulative indent 63, and exact row deltas through following UID0000Y8.
- [x] Supplied exactly seven destination-specific managed blocks and no prose-only C++.
- [x] Supplied C01-C27 ledger, scores, metadata, negative evidence, manual-text
      disposition, validator state, and callback checklist.

### Completed implementation callback

- [x] Registered exact children UID0004J0/UID0004J1/UID0004J2 without fabricated UIDs;
      parent remains `Nested:0`, children are `4/0/0`.
- [x] Preserved executed B003 Destination 6/UID0000Y6 `90/92` and changed only relative
      `Nested:0 -> -4`.
- [x] Applied C01-C27 and all B005-owned managed blocks; preserved UID0000Y2 and accepted
      Y3/Y4/Z9/ZA/ZB/Y6 formal bodies/scores.
- [x] Used short leases and one scoped validator per changed by-* file; recorded the
      UID0004J0 lease-wrapper sequencing exception exactly; released all leases.
- [x] Completed waited autogen command `000000008841` and verified class shell, exact
      child order/bodies, one byte-preserved Y6, one Y7, no duplicate methods, no Y5
      empty marker, and expected UID0000Y2 marker.
- [x] Verified generated cumulative indentation: Y5 parent 59, children 63/63/63, Y6 59,
      Y7 59, and UID0000Y8 59.
- [x] Updated ledger states, validator IDs/timestamps/exits/ok counts, generated proof,
      changed files, leases, and archive-neutral current wording in this report.
- [x] Report execution/lifecycle/move/archive commands were not run; supervisor Gate 2
      and later lifecycle remain external.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000008868","destination_path":"executed-b-agent-research/B005/0000Y5-RankingEventScrollPaneRawHoverDragHelpers-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0000Y5-RankingEventScrollPaneRawHoverDragHelpers-source-quality.md","timestamp":"2026-07-12T21:41:50-04:00","uid":"0000Y5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
