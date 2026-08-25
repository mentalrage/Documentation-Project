** TARGET-REPORT-UID:00014A **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00014A EventHandler Base Source-Quality / Ownership Research

## Finalized Report / Current Recommendation
- Current recommendation: update [UID:00014A] as a single `EventHandler` class-method island; do not split it.
- Final disposition: keep `CANONICAL_OWNER:00004N`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00004N`. The current emitted route through [UID:00004N] `EventHandler` to [UID:0000J7] `EventDispatcher` and `auto-generated/NexusTK/ui/core/EventDispatcher.cpp` is valid.
- Required action: supervisor/A-agent should update the target page to include the missing pure-virtual default false bodies at `0x004a8990-0x004a89e4` and the dispatcher-forwarding default at `0x004a89f0-0x004a8a09`, then raise the target to `88/90`.
- Confidence: high for range, ownership, vtable layout, and source route; medium for exact original virtual names and final header/source split.

## Supporting Research

## Target
- Target UID: `00014A`
- Target path: `by-memory/0x004a8970-0x004a8a84.EventHandlerBase.md`
- Source queue/report row: supervisor assignment `B001-goal2-eventhandler-base-source-quality-00014A-20260617`; current generated report route is `auto-generated/NexusTK/ui/core/EventDispatcher.cpp`.
- Current supervisor classification: report-only B work for source-quality, naming, ownership/emitter, range, and final-C++ policy.
- Current scores and parent state: `COMPLETION:82`, `CONFIDENCE:88`, `CANONICAL_OWNER:00004N`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004N`. The direct owner [UID:00004N] `EventHandler` is `85/89` and emits through [UID:0000J7] `EventDispatcher`, which is `89/85`.

## Executive Recommendation
- Keep [UID:00014A] directly owned by [UID:00004N] `EventHandler`. The target is a true class-method island, not a mixed owner range.
- Keep the generated output route through [UID:00004N] to [UID:0000J7] `EventDispatcher`. The base interface is dispatcher-facing UI event infrastructure; `Pane` consumes and overrides it but is not the direct owner.
- Update the target documentation because it currently omits material source bodies inside its range:
  - six local default false-return bodies at `0x004a8990`, `0x004a89a0`, `0x004a89b0`, `0x004a89c0`, `0x004a89d0`, and `0x004a89e0`;
  - the dispatcher-forwarding default virtual at `0x004a89f0-0x004a8a09`.
- Do not populate the formal `RECONSTRUCTION_CPP CODE` block yet. The item clears the numeric gate after the recommended score raise, but final C++ depends on coordinated class declarations, pure-virtual/default-body treatment, exact event-family method names, and a final header placement decision across `EventDispatcher`, `EventHandler`, and `Pane`.

## Supervisor Active Recheck
- The supervisor asked for report-only normal B work. No by-* docs, source files, generated files, IDA DB, or coverage report were edited.
- The assigned item does not require split repair. It requires a method-inventory/source-quality correction within the existing range.
- Every source-bearing subrange in `0x004a8970-0x004a8a84` was rechecked against live IDA MCP, the EventHandler class page, the EventHandler vtable-data page, Pane vtable docs, Event/EventDispatcher docs, generated reports, simroot leads, and prior executed B reports.

## Inference Research Guidance Check
- `by-structure.md` directs narrow semantic ownership: class methods belong to the class UID, while `EMITTER_UIDS` is only source-output routing. That supports `CANONICAL_OWNER:00004N` rather than a direct by-file or Pane owner.
- `inference_research.md` was applied by separating IDA facts from generated/simroot leads and by rejecting address adjacency or consumer xrefs alone as ownership proof.
- Existing docs were treated as leads, not authority. The target page was stale/incomplete because it skipped `0x004a8990-0x004a8a09`, while [UID:00004N] and [UID:0003I6] already contained stronger current vtable evidence.

## Heuristic / Inference Reanalysis And Validation

### 1. Base EventHandler source shape
- Best inference: `EventHandler` is an abstract UI event-handler interface with source-defined default bodies for several pure virtual event-family methods. The base vtable still points those slots to `__purecall`, which means the methods were likely declared pure virtual, but out-of-line default definitions exist and are reused by `Pane`/derived default wrappers.
- Evidence checked: live IDA `get_bytes` over `0x004a8970-0x004a8a90`; `entity_query` function list; `xrefs_to` for local false bodies and Pane thunks; [UID:0003I6] vtable dwords; [UID:0003CA] Pane vtable data; direct disassembly/decompilation of `0x00544db0-0x00544e00`.
- Rejected alternatives:
  - Dead padding: rejected because `0x00544db0`, `0x00544dc0`, `0x00544dd0`, `0x00544de0`, `0x00544df0`, and `0x00544e00` jump to `0x004a8990-0x004a89e0`.
  - Pane-owned bodies: rejected for the target bytes because the bodies sit in the EventHandler source island and are reached by Pane thunks; the thunks themselves belong with Pane.
  - Non-abstract base interface: rejected because the `EventHandler` base vtable uses six `__purecall` entries at `0x00619678-0x0061968c`.
- Impact: raise completion because the current by-memory page omits real code bodies; keep confidence below final-audit because exact original method names remain inferred.

### 2. Virtual slot names and signatures
- Best defensible slot map:
  - slot `+0x00`: scalar deleting destructor.
  - slots `+0x04`, `+0x08`, `+0x0c`, `+0x10`, `+0x14`, `+0x18`: six event-family handler slots. EventDispatcher classifiers route event types `0..7`, `8..10`, `11..17`, `18`, `20..22`, and explicit `19` into these slots.
  - slot `+0x1c`: dispatcher-forwarding/order support default at `0x004a89f0`.
  - slots `+0x20` and `+0x24`: two pair-output/position-like virtuals. The base defaults zero two dwords; Pane overrides copy/compute two-dword positions.
  - slot `+0x28`: predispatch acceptance predicate. `EventDispatcher::CallHandler` calls it before routing; base `0x004a8a50` returns true.
- Evidence checked: `EventDispatcher::CallHandler` at `0x004a77d0` virtual calls offsets `+0x04` through `+0x18` and `+0x28`; Event helper classifiers at `0x004a8ac0-0x004a8b00`; Pane overrides at `0x00544e10`, `0x00544e30`, and `0x00544e70`.
- Rejected alternatives:
  - Keep `ResetHandlerPairA/B` as final names: useful as generated/descriptive names, but too vague and do not capture the Pane override behavior.
  - Rename `AlwaysHandleEvent` as a final original name: behavior is confirmed, but original naming is not proven. Best report wording is `AcceptsEventByDefault`, `ShouldHandleEvent`, or `AlwaysHandleEvent` as descriptive.
  - Claim exact mouse/key/packet names for all six pure slots: rejected because the Event classifier names are still open in [UID:00014C], even though the type-family ranges are known.
- Impact: source-quality evidence supports owner/emitter and score raise, but blocks formal final C++ naming.

### 3. Constructor, destructor, and scalar deleting destructor treatment
- Best inference: `0x004a8970` and `0x004a8980` are source-authored constructor/ordinary destructor bodies that install/reinstall the `EventHandler` vftable. `0x004a8a60` is MSVC scalar deleting destructor ABI support: it reinstalls the base vtable, conditionally calls delete when flag bit `1` is set, and returns `this`.
- Evidence checked: disassembly/decompilation of `0x004a8970`, `0x004a8980`, and `0x004a8a60`; xrefs to `0x00619674`; delete callee `0x005c7526`.
- Rejected alternatives:
  - Ignore scalar deleting destructor as non-source: rejected because the compiler emits it from the class declaration/destructor; it must be documented as ABI-generated support, not hand-authored business logic.
  - Move constructor/destructor ownership to Pane: rejected because Pane calls these as embedded/subobject initialization and teardown; the vtable and methods are EventHandler-owned.
- Impact: keep the scalar deleting destructor in the target page and code inventory, but final C++ should model the destructor declaration rather than handwritten vtable stores.

### 4. Reset pair semantics
- Best inference: the two base defaults zero a caller-provided two-dword output pair. They likely correspond to local/origin and screen/absolute position hooks or handler-order coordinate hooks rather than generic "reset" commands.
- Evidence checked: `0x004a8a10` and `0x004a8a30` write `[out+4]=0` then `[out]=0`; Pane slot `0x00544e10` copies two stored dwords from the secondary view; Pane slot `0x00544e30` computes a two-dword chain position when attached to a layer and otherwise zeroes the pair.
- Rejected alternatives:
  - Treat the pair as handler pointer pair: weak. The Pane overrides behave like coordinate/offset output, not pointer clearing.
  - Assign final field names: rejected because the exact pair meaning depends on unresolved Pane/EventHandler layout names.
- Impact: recommended page wording should say "two-dword pair output defaults" and record the position-like Pane evidence, while preserving generated `ResetHandlerPairA/B` only as provisional search names.

### 5. AlwaysHandleEvent semantics
- Best inference: `0x004a8a50` is a predicate that allows normal dispatch. `EventDispatcher::CallHandler` first calls vtable offset `+0x28`; if it returns false and the event is in the cursor/key gate families, the dispatcher suppresses delivery. The base default returns true, so the base does not filter.
- Evidence checked: `0x004a8a50` disassembly is `mov al,1; ret`; `0x004a77d0` calls `(*vtable + 0x28)` before event-family dispatch; Pane override `0x00544e70` checks Pane state before accepting.
- Rejected alternatives:
  - "Always handled event body": rejected because this slot is not one of the event-family handler slots; it is a predispatch predicate.
  - "Is visible" as final name: Pane override includes visibility/state checks, but base interface role is broader.
- Impact: keep `AlwaysHandleEvent` as a descriptive/generated name or rename to `CanHandleEvent`/`ShouldAcceptEvent` after broader vtable naming cleanup.

### 6. Source/header placement
- Best inference: declare `EventHandler` in shared UI-core event/pane headers, with out-of-line bodies emitted through `EventDispatcher.cpp` for now. A future `ui/core/EventHandler.h` may be the cleanest declaration home, but no new by-file source root is justified yet.
- Evidence checked: code locality with EventDispatcher/Event ranges; EventDispatcher file page lists `EventHandler` as likely file content; Pane file/class pages embed/override the handler view; proposed source tree has `ui/core/EventDispatcher.cpp`, `Event.cpp`, and `Pane.cpp`, but no current `EventHandler.cpp`.
- Rejected alternatives:
  - Move target to `Pane.cpp`: rejected because Pane is a major consumer/derived owner, not the base interface owner.
  - Create standalone `EventHandler.cpp` now: possible but not supported strongly enough. The binary neighborhood and existing source tree support keeping small event infrastructure with `EventDispatcher`.
  - Move target to `Event.cpp`: rejected because `Event.cpp` owns event records/factories/producers, not handler registration/dispatch traversal.
- Impact: current owner/emitter route is correct; source placement remains a final-C++ blocker only.

### 7. Generated-output pollution
- Best inference: simroot/generator output under `ui/core/EventDispatcher.cpp` is useful but incomplete for this target. It emits constructor/destructor, pair resets, `AlwaysHandleEvent`, and scalar deleting destructor, but omits the pure-default false bodies and `0x004a89f0`, uses vtable-store scaffolding, and preserves provisional names.
- Evidence checked: `simroot_v2/ui/core/EventDispatcher.cpp` lines around EventHandler methods; generated `-ag-memory-coverage.md` row marks `00014A` as routed to `EventDispatcher.cpp` with no page C++ block.
- Rejected alternative: accept simroot code as final source. Rejected because it is not range-complete and uses generated ABI scaffolding that should not be copied into final C++.
- Impact: do not populate the formal target code block yet.

## Evidence Standards Used
- Live IDA MCP evidence: `idb_open`, `server_health`, `tools/list`, `lookup_funcs`, `entity_query`, `get_bytes`, `disasm`, `decompile`, `analyze_component`, and `xrefs_to`.
- Documentation evidence: target page, [UID:00004N] `EventHandler`, [UID:00004M] `EventDispatcher`, [UID:0000J7] `EventDispatcher` file, [UID:0000A2]/[UID:0000MC] `Pane`, [UID:0003I6] EventHandler vtable data, [UID:0003CA] Pane vtable data, Event/EventMan pages, proposed source tree, generated memory coverage, completion stats, unresolved report, and wave3 data issues.
- Prior B report search: searched executed reports for `00014A`, sibling `00014B`/`00014C`, `EventHandlerBase`, and `0x004a89f0`. No previous B report for `00014A` was found; older `00014C` EventMan reports and the `000129` Crasher report were used only as leads.
- Strength: direct IDA bytes/xrefs/vtable data prove range and ownership. Remaining uncertainty is source naming and declaration layout, not behavior.

## IDA MCP Facts
- Function/range facts:
  - `lookup_funcs` reports `0x004a8970` size `0x09`, `0x004a8980` size `0x07`, `0x004a89f0` size `0x1a`, `0x004a8a10` size `0x17`, `0x004a8a30` size `0x17`, `0x004a8a50` size `0x03`, and `0x004a8a60` size `0x24`.
  - `entity_query functions 0x004a8970-0x004a8a90` lists modeled functions at `0x004a8970`, `0x004a8980`, `0x004a89f0`, `0x004a8a10`, `0x004a8a30`, `0x004a8a50`, `0x004a8a60`, and successor `0x004a8a90`.
  - IDA does not model `0x004a8990-0x004a89e4` as separate functions, but raw bytes and xrefs prove they are jump targets containing `xor al,al; retn 4` bodies.
  - `0x004a8a84` is not a function; `0x004a8a84-0x004a8a90` is `0xcc` padding before `0x004a8a90`.
- Data/table/padding facts:
  - `get_bytes 0x00619660-0x006196b0` shows `0x00619670 -> 0x00647068`, `0x00619674 -> 0x004a8a60`, six `0x005ca28c` entries, `0x00619690 -> 0x004a89f0`, `0x00619694 -> 0x004a8a10`, `0x00619698 -> 0x004a8a30`, and `0x0061969c -> 0x004a8a50`.
  - `lookup_funcs 0x005ca28c` identifies `__purecall`, confirming the six base vtable pure slots.
- Xref facts:
  - `xrefs_to 0x00619674` reports refs from `0x004a8970`, `0x004a8980`, and `0x004a8a6a`.
  - `xrefs_to 0x004a8a10`, `0x004a8a30`, `0x004a8a50`, and `0x004a8a60` are vtable-data refs from the EventHandler vtable.
  - `xrefs_to 0x004a8990-0x004a89e0` report code refs from the six Pane thunk functions `0x00544db0-0x00544e00`.
  - `xrefs_to 0x004a89f0` reports 383 data xrefs, showing broad inherited/default secondary-view use.
- Vtable/global/type facts:
  - [UID:0003I6] exactly maps the EventHandler COL/vtable range.
  - Pane secondary vtables use the inherited sequence `0x00544db0` through `0x00544e70`, including `0x004a89f0`.
- Negative IDA facts:
  - No IDA evidence supports moving the base EventHandler vtable or methods to a feature pane.
  - No IDA evidence supports making `0x004a8990-0x004a89e0` padding or ignored data.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004a8970-0x004a8978` | part of `00014A` | `EventHandler` constructor, installs base vtable | true | `00004N` | included in proposed `88/90` | keep |
| `0x004a8980-0x004a8986` | part of `00014A` | ordinary destructor, reinstalls base vtable | true | `00004N` | included | keep |
| `0x004a8990-0x004a89e4` | part of `00014A` | six pure-virtual default false bodies used by Pane thunks | true | `00004N` | included | add to page |
| `0x004a89f0-0x004a8a09` | part of `00014A` | dispatcher-forwarding/order default virtual | true | `00004N` | included | add to page |
| `0x004a8a10-0x004a8a26` | part of `00014A` | pair-output default A, zeroes two dwords | true | `00004N` | included | keep, refine semantics |
| `0x004a8a30-0x004a8a46` | part of `00014A` | pair-output default B, zeroes two dwords | true | `00004N` | included | keep, refine semantics |
| `0x004a8a50-0x004a8a52` | part of `00014A` | predispatch acceptance predicate, returns true | true | `00004N` | included | keep, refine semantics |
| `0x004a8a60-0x004a8a84` | part of `00014A` | scalar deleting destructor ABI support | true | `00004N` | included | keep |
| `0x00619670-0x006196a0` | [UID:0003I6] | EventHandler COL/vtable data | true | `00004N` | `85/91` | support doc confirms slot map |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004a8970` | caller `0x0054449d` in `Pane::Pane` path | Pane constructs embedded/base handler view |
| `0x004a8980` | callers `0x00544669`, `0x00545040`, and cleanup ref `0x00605a51` | Pane destruction/cleanup tears down handler |
| `0x004a8990` | code xref from `0x00544db4` | Pane thunk jumps to default false body |
| `0x004a89a0` | code xref from `0x00544dc4` | Pane thunk jumps to default false body |
| `0x004a89b0` | code xref from `0x00544dd4` | Pane thunk jumps to default false body |
| `0x004a89c0` | code xref from `0x00544de4` | Pane thunk jumps to default false body |
| `0x004a89d0` | code xref from `0x00544df4` | Pane thunk jumps to default false body |
| `0x004a89e0` | code xref from `0x00544e04` | Pane thunk jumps to default false body |
| `0x004a89f0` | 383 data xrefs | broadly inherited secondary-view default slot |
| `0x004a8a01` | call to `0x004a6ce0` with global dispatcher in `ecx` | default forwards through EventDispatcher with zero flag |
| `0x004a8a10`, `0x004a8a30`, `0x004a8a50` | EventHandler vtable slots at `0x00619694`, `0x00619698`, `0x0061969c` | base defaults |
| `0x00619674` | refs from constructor/destructor/scalar deleting destructor | class vtable identity |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion:
  - [UID:00004N] already records `0x004a89f0`, the vtable slot map, and the direct source chain through [UID:0000J7].
  - [UID:0003I6] records exact EventHandler COL/vtable dwords and confirms the base purecall/default slot layout.
  - [UID:0000J7] lists `EventHandler` as part of EventDispatcher UI event infrastructure.
  - [UID:0000MC]/[UID:0000A2] document Pane as the consumer/embedded handler owner, not the base class owner.
- Existing docs that are stale or incomplete:
  - The target [UID:00014A] omits `0x004a8990-0x004a8a09` from the Covered Ranges table.
  - The target status says final C++ is blank because names/header placement are open, but it does not document the stronger reason: the source shape includes pure virtual default bodies and cross-file Pane thunks.
  - Simroot `ui/core/EventDispatcher.cpp` omits the six pure-default false bodies and `0x004a89f0`, while using raw vtable-store scaffolding.
- Generated/coverage report state:
  - `auto-generated/-ag-memory-coverage.md` lists [UID:00014A] as `emits` via owner/emitter `00004N`, routed to `auto-generated/NexusTK/ui/core/EventDispatcher.cpp`, with no formal C++ emitted.
  - `project-level/-auto-completion-stats.md` lists `00014A` at `82/88`, average `85.0`.
  - `project-level/-unresolved.md` only flags textual `sub_4A8A60` occurrences on the target page; this is not an ownership blocker.

## Ranked Ownership Analysis

### 1. [UID:00004N] EventHandler, emitting through [UID:0000J7] EventDispatcher
- Evidence for: class vtable `??_7EventHandler@@6B@`; constructor/destructor/scalar destructor write the EventHandler vtable; [UID:0003I6] exact vtable page is class-owned; EventDispatcher dispatches through the interface; source locality places this between EventDispatcher support and Event/EventMan code.
- Evidence against: Pane embeds/overrides the handler, and generated source hint says `class_EventHandler.cpp`, so the final project might eventually add a small `EventHandler.h` or `EventHandler.cpp`.
- Decision: accepted. Keep `CANONICAL_OWNER:00004N` and `EMITTER_UIDS:00004N`; no new file root is justified now.

### 2. [UID:0000MC]/[UID:0000A2] Pane
- Evidence for: Pane constructor/destructor call EventHandler ctor/dtor; Pane secondary vtables and thunks reuse the default false bodies and override the pair/predicate slots.
- Evidence against: consumer and derived override evidence is not base ownership. The EventHandler vtable and base method island are not Pane-specific, and the dispatcher directly defines the interface semantics.
- Decision: rejected as direct owner; retain as major consumer/support doc.

### 3. [UID:0000J6] Event
- Evidence for: neighboring event-object code starts at `0x004a8a90`, and Event/EventMan classify and produce records consumed by the handler interface.
- Evidence against: Event owns payload records and factories; handler traversal, pair hooks, and acceptance predicate belong to the dispatcher/handler interface.
- Decision: rejected as direct owner.

### 4. New `ui/core/EventHandler.cpp` file
- Evidence for: generated source hint names `class_EventHandler.cpp`; `EventHandler` could plausibly be its own tiny source/header unit.
- Evidence against: proposed source tree does not currently list it; code locality and current file docs place handler support with `EventDispatcher`; creating a new file would not solve final name/header uncertainty.
- Decision: do not create now. Reconsider only during a coordinated UI-core header/source split.

## Negative Evidence Summary
- Address adjacency to Pane thunks at `0x00544db0-0x00544e00` does not move the EventHandler bodies to Pane; the thunks are outside the target and jump into base default definitions.
- The six `__purecall` base vtable slots do not make the local false bodies ignorable; C++ pure virtual functions can still have definitions, and the derived thunks prove these definitions are used.
- The broad 383-vtable-xref fan-in to `0x004a89f0` proves shared inherited/default use, not a feature owner.
- Simroot ownership and method names are generated leads only and are incomplete for this range.

## First-Draft C++ Recommendation

Do not populate the formal `RECONSTRUCTION_CPP CODE` block for [UID:00014A] yet.

Concrete blockers:
- The six event-family virtual names are not source-final. IDA proves event-type ranges, not original method names.
- The source shape likely needs pure virtual declarations with out-of-line default false definitions; that must be coordinated with Pane secondary vtable declarations and thunks.
- The `0x004a89f0` virtual calls `EventDispatcher::SetPaneOrder`/`sub_4A6CE0` with two arguments and a zero flag, but the source-facing name and argument types are still provisional.
- The pair-output slots need final point/pair type and field names after Pane layout cleanup.
- The final declaration home is still `EventDispatcher.h` versus `Pane.h` versus a small `EventHandler.h`.

Non-populatable first-draft source shape for review only:

```cpp
// Review-only shape. Do not paste into RECONSTRUCTION_CPP yet.
struct EventPointPair
{
    int x;
    int y;
};

class EventHandler
{
public:
    EventHandler();
    virtual ~EventHandler();

    virtual bool HandleCursorOrMouseEvent(Event* event) = 0;
    virtual bool HandleKeyEvent(Event* event) = 0;
    virtual bool HandleTextOrImeEvent(Event* event) = 0;
    virtual bool HandlePacketEvent(Event* event) = 0;
    virtual bool HandleSystemEvent(Event* event) = 0;
    virtual bool HandleType19Event(Event* event) = 0;

    virtual bool ForwardHandlerOrder(EventHandler* first, EventHandler* second);
    virtual void GetLocalEventPair(EventPointPair* out);
    virtual void GetScreenEventPair(EventPointPair* out);
    virtual bool ShouldAcceptEvent() const;
};

// The six pure-virtual default definitions are present in the binary and
// return false, but the base vtable still points those slots to __purecall.
bool EventHandler::HandleCursorOrMouseEvent(Event*) { return false; }
bool EventHandler::HandleKeyEvent(Event*) { return false; }
bool EventHandler::HandleTextOrImeEvent(Event*) { return false; }
bool EventHandler::HandlePacketEvent(Event*) { return false; }
bool EventHandler::HandleSystemEvent(Event*) { return false; }
bool EventHandler::HandleType19Event(Event*) { return false; }

bool EventHandler::ForwardHandlerOrder(EventHandler* first, EventHandler* second)
{
    return g_pEventDispatcher->SetPaneOrder(first, second, 0);
}

void EventHandler::GetLocalEventPair(EventPointPair* out)
{
    out->x = 0;
    out->y = 0;
}

void EventHandler::GetScreenEventPair(EventPointPair* out)
{
    out->x = 0;
    out->y = 0;
}

bool EventHandler::ShouldAcceptEvent() const
{
    return true;
}
```

## Final Recommendation
- Exact metadata recommendations for [UID:00014A]:
  - `COMPLETION:88`
  - `CONFIDENCE:90`
  - `CANONICAL_OWNER:00004N`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:00004N`
  - `RECONSTRUCTION_CPP CODE` remains blank.
- Exact coverage-report replacement row, in the same placement between the padding row `0x004a8966-0x004a8970` and the padding row `0x004a8a84-0x004a8a90`:

```text
    - [UID:00014A][0x004a8970-0x004a8a84.EventHandlerBase](by-memory/0x004a8970-0x004a8a84.EventHandlerBase.md) 0x004a8970-0x004a8a84 | class-method-island | EventHandlerBase : reconstructable : 88% : strong : Base EventHandler method island parented to EventHandler; constructor/destructor/scalar-deleting destructor, six pure-virtual default false bodies at 0x004a8990-0x004a89e4 used by Pane thunks, dispatcher-forwarding default at 0x004a89f0, two pair-output zero defaults, always-true predispatch predicate, vtable slot map, and padding boundaries are IDA-confirmed; exact original virtual names and final EventHandler header placement remain source-quality blockers for formal C++.
```

- Target page content recommendations:
  - Add a `Covered Ranges` row for `0x004a8990-0x004a89e4`: six pure-virtual default false bodies, each `xor al, al; retn 4`, reached by Pane thunks.
  - Add a `Covered Ranges` row for `0x004a89f0-0x004a8a09`: dispatcher-forwarding/order default virtual.
  - Update evidence to cite [UID:0003I6] and live vtable dwords, including purecall slot behavior.
  - Replace "final virtual slot names remain open" with the more specific slot map and blockers above.
- Support docs to update after target change:
  - [UID:00004N] `EventHandler`: add the six pure-default false bodies to Method Notes and clarify that pure slots use `__purecall` in the base vtable despite source-defined defaults.
  - [UID:0003I6] `EventHandlerVtableData`: optional note that local false bodies are not vtable entries for the abstract base; the vtable's six pure slots remain `__purecall`.
  - [UID:0000A2]/[UID:0000MC] `Pane` and [UID:0003JA]/[UID:0003CA] Pane vtable docs: optional wording that `0x00544db0-0x00544e00` are Pane-side wrappers/thunks to EventHandler pure-default false bodies.
  - `wave3_data_issues.md`: optional generated-data issue noting that simroot EventDispatcher output omits `0x004a8990-0x004a8a09` from EventHandler source.

## Follow-Up Actions
- Supervisor actions:
  - Apply the target page inventory/score updates and coverage row replacement if accepted.
  - Keep `RECONSTRUCTION_CPP CODE` blank despite the numeric gate.
- A-agent actions:
  - Update [UID:00014A], [UID:00004N], and optional vtable/support docs with the slot-map wording.
  - Coordinate final `EventHandler` declaration naming with Pane and EventDispatcher before entering formal C++.
- B001 future research actions:
  - A separate pass could name the six event-family virtuals by correlating more derived vtable overrides and Event type constants, but it is not needed for owner/emitter correctness.

## Confidence
- Recommendation confidence: high for keeping the current owner/emitter and route.
- Score confidence: `88/90` is justified after adding the missing code bodies and slot map. Scores should stay below `95` because original virtual names and header placement are not final.
- Remaining uncertainty: exact original names for the six event-family handlers, the dispatcher-forwarding slot, pair-output slots, and acceptance predicate; final `EventHandler.h` versus `EventDispatcher.h`/`Pane.h` declaration home.

## Validator Results
- Commands run for this report: none. Report-only work changed only this file under `tools/leaser/Agents/Agent-B001/research`.
- Recommended validation after supervisor/A-agent applies by-* edits:

> Executable block R001 was removed from this report and preserved verbatim in [00014A-eventhandler-base-source-quality-removed.md](00014A-eventhandler-base-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Any unresolved validator warnings/errors: none observed because validator was not run.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B001/research/00014A-eventhandler-base-source-quality.md`
- Modified: none outside this report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00014A-eventhandler-base-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:18","uid":"00014A"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00014A-eventhandler-base-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/00014A-eventhandler-base-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00014A"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
