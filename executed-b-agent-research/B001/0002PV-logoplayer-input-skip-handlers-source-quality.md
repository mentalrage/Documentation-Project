** TARGET-REPORT-UID:0002PV **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002PV LogoPlayerPane Input Skip Handlers Source-Quality Report

Assignment: `B001-goal2-logoplayer-input-skip-handlers-source-quality-0002PV-20260617`

Primary target: [UID:0002PV] `by-memory/0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers.md`

Report author: Agent-B001

Date: 2026-06-17

## Finalized Report / Current Recommendation

Current recommendation: keep [UID:0002PV] as a reconstructable, emitting `LogoPlayerPane` range that covers the adjacent key and mouse virtual skip handlers.

Final disposition:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `82` | `87` |
| `CONFIDENCE` | `88` | `90` |
| `CANONICAL_OWNER` | `00007H` | `00007H` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `00007H` | `00007H` |
| Formal `RECONSTRUCTION_CPP` | blank | keep blank |

Required action: supervisor should update the target/support docs and the coverage row if accepting this report. B001 did not edit by-* docs, generated reports, generated source, IDA DB, or `by-memory/-coverage-report.md`.

Confidence: strong. The remaining uncertainty is not ownership or behavior; it is final source declaration spelling for the shared EventHandler/KeyEvent/MouseEvent interfaces.

## Target

- Target UID: `0002PV`
- Target path: `by-memory/0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers.md`
- Current score: `82/88`
- Current owner/emitter: [UID:00007H] `LogoPlayerPane`
- Source route: [UID:00007H] `LogoPlayerPane` -> [UID:0000O4] `StartupLogoPanes` -> `NexusTK/app/StartupLogoPanes.cpp`
- Current coverage row kind: `vtable method pair`

## Supervisor Active Recheck

The supervisor assigned report-only source-quality work. No split repair or by-* edit was authorized for B001 in this pass.

The target contains two real adjacent functions:

- key handler: `0x004f55d0-0x004f55fc`
- internal alignment: `0x004f55fc-0x004f5600`
- mouse handler: `0x004f5600-0x004f561d`

Because both functions have the same direct class owner, same source module, same secondary EventHandler interface route, same single callee, and one shared source purpose, this report does not recommend an immediate split. A stricter future one-method-per-page cleanup would be safe, but it is not required to resolve ownership/source placement or remove [UID:0002PV] from the low-score queue.

## Evidence Standards Used

Evidence types used:

- existing target and support docs;
- current `by-structure.md`, `by-memory/-guidance.md`, `inference_research.md`, and proposed source-tree guidance;
- live IDA MCP in session `b003_00018a_ime_comp_20260617`;
- IDA `server_health`, `lookup_funcs`, `analyze_function`, `disasm`, and `xrefs_to`;
- generated source only as a lead, not authority;
- `tools/int_convert.py` for numeric conversion checks.

IDA session state:

- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- Image base: `0x400000`
- Auto-analysis ready: `true`
- Hex-Rays ready: `true`
- Strings cache ready: `true`, size `2067`

## Supporting Documentation Reviewed

- [UID:0002PV] target page.
- [UID:00007H] `LogoPlayerPane` class.
- [UID:00019D] `LogoPlayerPane` aggregate.
- [UID:0000O4] `StartupLogoPanes` file.
- [UID:0002PU] `LogoPlayerPaneAdvanceToNextSegment`.
- [UID:0002PW] `LogoPlayerPaneOnClose`.
- [UID:0002PX] `LogoPlayerPaneDeletingDestructorThunks`.
- [UID:0002PY] `LogoPlayerPaneScalarDeletingDestructor`.
- [UID:0000FV], [UID:0000P4], and [UID:0001NT] `VideoPlayerPane` class/file/memory pages.
- [UID:0000A2] `Pane`, [UID:0001VH] `PaneLayout`.
- [UID:00004N] `EventHandler`, [UID:00014A] `EventHandlerBase`.
- [UID:00004L] `Event`, [UID:0000J6] `Event`.
- [UID:00004M] `EventDispatcher`, [UID:0000J7] `EventDispatcher`.
- `by-project-structure/proposed-source-tree.md`.
- Prior executed B-agent reports were searched for `LogoPlayerPane`, `0x004f55d0`, `0x004f5600`, `OnKeyEvent`, `OnMouseEvent`, event type `8`, and event type `3`; no prior executed B report for this exact target was found.

## IDA MCP Facts

Function/range facts:

| Address | IDA result | Meaning |
| --- | --- | --- |
| `0x004f55d0` | `sub_4F55D0`, size `0x2c` | key handler, 44 bytes (Verified with `int_convert.py`) |
| `0x004f55fc` | not a function | end of key handler and start of internal padding |
| `0x004f5600` | `sub_4F5600`, size `0x1d` | mouse handler, 29 bytes (Verified with `int_convert.py`) |
| `0x004f561d` | not a function | end of mouse handler |
| `0x004f5620` | `sub_4F5620`, size `0x14` | next function, `LogoPlayerPaneOnClose` |
| `0x004f5570` | `sub_4F5570`, size `0x58` | `LogoPlayerPaneAdvanceToNextSegment` |

Target handler facts:

- `0x004f55d0` checks event byte `+0x04` for value `8`, reads event byte `+0x08`, compares it against `0x0d`, `0x1b`, and `0x20`, adjusts `ecx` by `-0xa0`, calls `0x004f5570`, and returns `1`.
- `0x004f5600` checks event byte `+0x04` for value `3`, adjusts `ecx` by `-0xa0`, calls `0x004f5570`, and returns `1`.
- `0xa0` is 160 decimal, `0x0d` is 13 decimal, `0x1b` is 27 decimal, and `0x20` is 32 decimal, verified with `tools/int_convert.py`.

Xref facts:

| Item | Xrefs | Meaning |
| --- | --- | --- |
| `0x004f55d0` | one data xref from `0x0061d078` | key handler is vtable-only |
| `0x004f5600` | one data xref from `0x0061d074` | mouse handler is vtable-only |
| `0x004f5570` | code xrefs at `0x004f55f1` and `0x004f5612` | both handlers call only the segment-advance helper |
| `0x0061d070` | constructor/destructor/scalar-destructor vtable-store refs | secondary `LogoPlayerPane` EventHandler view |
| `0x0061d0a0` | constructor/destructor/scalar-destructor vtable-store refs | tertiary handler/timer view |

Event producer facts from live IDA EventMan functions:

- `0x004a96a0` builds and dispatches Event type `8` from the key-down path. It updates keyboard state, translates the key through `ToAscii` or the EventMan key table, stores type `8`, stores the translated key byte in the field consumed at event `+0x08`, and dispatches the Event.
- `0x004a98a0` constructs Event type `9` in the key-release path, but the verified body does not dispatch the temporary Event in the normal path. This makes type `8` the active key-down event used by pane key handlers.
- `0x004a9120` dispatches type `1` for left-button down and type `2` for left double-click.
- `0x004a9260` dispatches type `3`, then dispatches type `0` for cursor state. This identifies type `3` as left-button release/up.
- `0x004a9360` dispatches type `4` for right-button down and type `5` for right double-click.
- `0x004a94a0` dispatches type `6`, then type `0`, identifying type `6` as right-button release/up.
- `0x004a95a0` dispatches type `7` for mouse-wheel input, then type `0`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004f55d0-0x004f55fc` | contained in [UID:0002PV] | `LogoPlayerPane::OnKeyEvent` body | true | [UID:00007H] | in target | keep contained |
| `0x004f55fc-0x004f5600` | contained in [UID:0002PV] | four `0xcc` alignment bytes | compiler padding | [UID:00007H] range context | in target | keep as internal padding |
| `0x004f5600-0x004f561d` | contained in [UID:0002PV] | `LogoPlayerPane::OnMouseEvent` body | true | [UID:00007H] | in target | keep contained |
| `0x004f5570-0x004f55c8` | [UID:0002PU] | `LogoPlayerPaneAdvanceToNextSegment` | true | [UID:00007H] | `84/90` | callee |
| `0x004f5620-0x004f5634` | [UID:0002PW] | close/completion virtual | true | [UID:00007H] | `82/90` | next function |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004f55d0` | vtable data xref only from `0x0061d078` | normal virtual reachability; no direct caller expected |
| `0x004f5600` | vtable data xref only from `0x0061d074` | normal virtual reachability; no direct caller expected |
| `0x004f55f1` | key handler call to `0x004f5570` | triggered by key-down Enter/Escape/Space |
| `0x004f5612` | mouse handler call to `0x004f5570` | triggered by left-button release/up |
| `0x004f5570` | exactly two direct xrefs from this target | input skip handlers are the complete caller set for the segment-advance helper |

## Heuristic / Inference Reanalysis And Validation

### Source-facing method names and signatures

Best source-facing names:

```cpp
bool LogoPlayerPane::OnKeyEvent(const KeyEvent* event);
bool LogoPlayerPane::OnMouseEvent(const MouseEvent* event);
```

`OnKeyEvent` and `OnMouseEvent` are the strongest descriptive names because:

- existing class/file/aggregate docs already use these names;
- generated source uses these names as a lead;
- EventHandler/Pane docs describe the secondary interface as event-family virtuals;
- the key handler consumes a key-family event type and key byte;
- the mouse handler consumes a mouse-family event type and no other pane state.

The return type should be source-facing `bool`, not raw `char`, because both bodies return `1` as a handled predicate. The raw IDA `char` return is ABI/decompiler shape.

Rejected alternatives:

- `HandleInputEvent`: too broad; the two functions occupy specific EventHandler key and mouse virtual slots.
- `SkipMovieOnInput`: describes shared behavior but not the vtable interface method names.
- `OnKeyDown` / `OnLeftMouseUp` as method names: event-type semantics are correct, but the vtable methods are the broader key and mouse event-family handlers.
- `VideoPlayerPane::OnKeyEvent` / `VideoPlayerPane::OnMouseEvent`: rejected because the callee and state are derived startup segment logic, not generic video playback.

Impact: update target docs to state source-facing methods as `LogoPlayerPane::OnKeyEvent` and `LogoPlayerPane::OnMouseEvent`, with event-specific conditions inside each method.

### Event type `8`

Best semantic name: `KeyDown`, `KeyPressed`, or `KeyInputDown`. Use `KeyDown` as the preferred descriptive name.

Evidence:

- EventMan key-down producer at `0x004a96a0` sets Event type byte to `8`, updates key-down keyboard state, runs `ToAscii`/key-table translation, stores the translated key byte, and dispatches the Event.
- EventMan key-release producer at `0x004a98a0` uses type `9` after clearing key state, so type `8` is not key-up.
- The target key handler only checks type `8` before looking at event `+0x08`.

The key byte at event `+0x08` is best described as a translated key code or narrow key byte. For Enter, Escape, and Space the numeric values match both ASCII/control-code values and Windows `VK_RETURN`, `VK_ESCAPE`, and `VK_SPACE`; do not over-specify the field as a raw virtual-key code for all keys because EventMan has already performed translation/fallback before dispatch.

Rejected alternatives:

- `KeyUp`: contradicted by `0x004a98a0` using type `9`.
- `CharInput`: contradicted by the key-down producer path and by separate EventMan character-input dispatch at `0x004a97e0`.
- Raw Windows message ID: contradicted by EventMan packaging into a stack Event object before dispatch.

Impact: the target open question for event type `8` should be closed as high-confidence `KeyDown`.

### Enter/Escape/Space handling

The key handler tests the byte at event `+0x08` after confirming Event type `8`:

| Compare | Decimal | Name | Action |
| --- | ---: | --- | --- |
| `0x0d` | 13 | Enter / Return | call `AdvanceToNextSegment` |
| `0x1b` | 27 | Escape | call `AdvanceToNextSegment` |
| `0x20` | 32 | Space | call `AdvanceToNextSegment` |

The decimal conversions above were verified with `tools/int_convert.py`.

If the event is not type `8`, or if the key byte is not one of these three values, the handler does not advance the segment and still returns handled.

Impact: source reconstruction must preserve the always-handled return outside the key cases.

### Event type `3`

Best semantic name: `LeftMouseUp` or `LeftButtonRelease`. Use `LeftButtonUp` / `LeftButtonRelease` wording in docs.

Evidence:

- EventMan left-button release function at `0x004a9260` dispatches type `3`, then dispatches type `0` cursor state.
- EventMan left-button down/double-click function at `0x004a9120` dispatches type `1` or `2`.
- EventMan right-button release function at `0x004a94a0` dispatches type `6`, then type `0`.
- EventMan wheel function at `0x004a95a0` dispatches type `7`.
- Prior UI handler reports and docs treat mouse kind `3` as release/up behavior in other panes.

Rejected alternatives:

- Generic mouse-up without button specificity: too weak; EventMan has separate right release type `6`, so type `3` is specifically left-button release/up.
- Mouse-down: contradicted by type `1` left-down evidence.
- Double-click: contradicted by type `2` and type `5` double-click evidence.
- Mouse move/cursor update: contradicted by the separate type `0` dispatch immediately after release/wheel paths.

Impact: the target open question should be closed. The mouse handler skips the movie on left mouse button release/up, not on arbitrary mouse events.

### Secondary `this - 0xa0` interface/base meaning

Best interpretation: `0x004f55d0` and `0x004f5600` are source-authored `LogoPlayerPane` event-handler override bodies reached through the `Pane`/`EventHandler` secondary view at object offset `+0xa0`.

Evidence:

- [UID:0001VH] `PaneLayout` documents `+0xa0` as the event-handler secondary vptr and `+0xa4` as the tertiary timer/event view.
- `LogoPlayerPane` constructor/destructor/scalar destructor pages document three vtable views at `+0`, `+0xa0`, and `+0xa4`.
- The key and mouse handler entries are vtable-only at secondary table slots `0x0061d078` and `0x0061d074`.
- Both handler bodies run with the secondary-interface `this` pointer and subtract `0xa0` only before calling the primary-object helper `LogoPlayerPaneAdvanceToNextSegment`.
- The nearby deleting-destructor thunks at [UID:0002PX] independently confirm `-0xa0` and `-0xa4` secondary/tertiary adjustor routes.

This is not a separate `InputHandler` class ownership route. It is Pane/EventHandler-style multiple inheritance or embedded interface layout. It is also not a pure adjustor thunk because the functions contain the real event filtering and always-handled return behavior before/after the adjustment.

Impact: source-facing ownership remains `LogoPlayerPane`; implementation notes should explain that the binary body is compiled against the secondary EventHandler view.

### Vtable-only reachability and no-direct-caller treatment

Best interpretation: no direct callers is expected virtual-method evidence, not dead-code evidence.

Evidence:

- `xrefs_to 0x004f55d0` reports only vtable data `0x0061d078`.
- `xrefs_to 0x004f5600` reports only vtable data `0x0061d074`.
- `callers` via `analyze_function` returns no normal code callers for both handlers.
- `LogoPlayerPane` and `VideoPlayerPane` use the same Pane/EventHandler vtable-view pattern for other virtuals and destructor adjustor thunks.
- EventDispatcher/Pane infrastructure routes events through handler vtables, so static direct callers are not expected.

Rejected alternatives:

- Dead or orphan code: contradicted by live vtable entries.
- Raw no-route helper: contradicted by vtable ownership and normal EventHandler dispatch model.
- Compiler-only thunk: contradicted by source-authored event checks and calls to `AdvanceToNextSegment`.

Impact: keep reconstructable/emitting state and do not lower confidence for lack of direct callers.

### Always-handled return semantics

Both handlers return `1` in all branches.

Source behavior:

- `OnKeyEvent` advances only for Event type `8` and key byte Enter/Escape/Space, but returns `true` even for other key types/keys.
- `OnMouseEvent` advances only for Event type `3`, but returns `true` for all mouse events passed to it.
- Neither handler forwards unmatched events to `VideoPlayerPane`, `Pane`, or a base EventHandler default.

Rejected alternative: returning `false` for non-triggering events or forwarding to base. That would change event propagation and is not what the binary does.

Impact: any future formal C++ must preserve the unconditional handled return.

### Relationship to `AdvanceToNextSegment`

Best interpretation: [UID:0002PV] is an input-skip wrapper pair over [UID:0002PU] `LogoPlayerPaneAdvanceToNextSegment`.

Evidence:

- Both target functions have exactly one callee: `0x004f5570`.
- `xrefs_to 0x004f5570` finds exactly the two target callsites.
- `AdvanceToNextSegment` owns the actual segment guard, progress check, AUTOBUF pointer arithmetic, `OpenBinkVideo` call, playback start, and delete-on-failure logic.
- The target handlers do not modify logo/video fields directly.

Impact: source docs should keep state/segment logic in [UID:0002PU] and describe [UID:0002PV] as dispatch/skip input entry points.

### Source placement and ownership alternatives

Accepted:

- [UID:00007H] `LogoPlayerPane`: direct class owner. The handlers trigger a derived startup movie segment operation and are vtable slots on the derived object.
- [UID:0000O4] `StartupLogoPanes`: correct source file route. Startup logo/movie input skip behavior belongs in `NexusTK/app/StartupLogoPanes.cpp`.

Rejected:

- [UID:0000FV] / [UID:0000P4] `VideoPlayerPane`: base class owns reusable Bink playback and idle/message behavior, but these handlers call derived `LogoPlayerPaneAdvanceToNextSegment` and implement startup-specific skip policy.
- [UID:0000A2] / [UID:0000MC] `Pane`: Pane owns the common secondary EventHandler layout and dispatch plumbing, not this derived policy.
- [UID:00004N] `EventHandler`: EventHandler owns base interface/defaults, not derived movie skipping.
- [UID:00004L]/[UID:0000J6] `Event`: Event/EventMan define event payloads and producers, not pane-specific handling.
- New `InputHandler` file/class: no evidence for a separate source owner; `+0xa0` resolves to the already documented Pane/EventHandler secondary view.

Impact: keep owner/emitter unchanged.

### Range and split policy

Best recommendation: no immediate split.

Evidence:

- Both source methods are exact IDA functions and both are in the same current range.
- The internal padding is only four `0xcc` bytes.
- Both methods share owner, emitter, interface view, behavior category, and callee.
- The target is already explicitly documented as an adjacent virtual input handler pair, not mislabeled as one function.

Optional future split, if the supervisor wants strict one-method pages:

- `0x004f55d0-0x004f55fc.LogoPlayerPaneOnKeyEvent`
- `0x004f55fc-0x004f5600` ignored alignment row
- `0x004f5600-0x004f561d.LogoPlayerPaneOnMouseEvent`

This optional split would not change ownership, source placement, or behavior. It is not required for this assignment's source-quality decision.

### Remaining final-C++ blockers

Resolved or high-probability closed:

- event type `8` = key down;
- event type `3` = left mouse button release/up;
- key byte handling for Enter/Escape/Space;
- secondary `this - 0xa0` = Pane/EventHandler secondary view;
- vtable-only reachability;
- always-handled returns;
- source owner and file route;
- range and internal padding.

Still not final-source exact:

- exact original enum names for Event type `8` and type `3`;
- exact `KeyEvent` and `MouseEvent` struct/class names and field spellings;
- exact EventHandler virtual declaration names/order in headers;
- final source policy for a two-method by-memory C++ block versus future exact child split.

These uncertainties do not block the score increase or owner/emitter state. They do block formal C++ population.

## First-Draft C++ Recommendation

Formal `RECONSTRUCTION_CPP` should remain blank for [UID:0002PV] in this pass.

This is an explicit do-not-populate recommendation. The item clears the numeric/emitter gate under the recommended score, but copy/paste-ready final C++ still depends on shared declarations that are not settled:

- original EventHandler virtual names and header placement;
- exact `KeyEvent` and `MouseEvent` source types;
- exact event enum names for key down and left-button release;
- whether [UID:0002PV] remains a two-method source-bearing pair or is later split into exact method pages.

Review-only source shape:

```cpp
// Review-only. Do not enter this as formal RECONSTRUCTION_CPP yet.
bool LogoPlayerPane::OnKeyEvent(const KeyEvent* event)
{
    if (event->type == kEventKeyDown) {
        const unsigned char key = event->keyCode;
        if (key == 0x0d || key == 0x1b || key == 0x20)
            AdvanceToNextSegment();
    }

    return true;
}

bool LogoPlayerPane::OnMouseEvent(const MouseEvent* event)
{
    if (event->type == kMouseLeftButtonUp)
        AdvanceToNextSegment();

    return true;
}
```

The source shape above captures the behavior, including unconditional handled returns, but uses provisional names. It should stay review-only until the UI-core event declarations are coordinated.

## Ranked Ownership Analysis

### 1. [UID:00007H] `LogoPlayerPane`

Evidence for:

- target vtable slots are in the `LogoPlayerPane` vtable family;
- both handlers normalize `this - 0xa0` before calling the derived segment-advance helper;
- the advance helper is startup movie segment-specific;
- existing class and aggregate docs already model these as LogoPlayerPane methods.

Evidence against:

- binary receives the secondary EventHandler view rather than the primary object pointer; this is an ABI/layout detail, not a semantic owner problem.

Decision: accepted direct owner/emitter.

### 2. [UID:0000O4] `StartupLogoPanes`

Evidence for:

- `StartupLogoPanes.cpp` owns the startup logo/video flow, `LogoPane`, `LogoPlayerPane`, and standalone startup Bink playback helpers;
- proposed source tree places `StartupLogoPanes.cpp` under `NexusTK/app/`;
- target behavior is startup intro skip policy.

Evidence against:

- direct owner is more precise as [UID:00007H] `LogoPlayerPane`.

Decision: accepted source-file route through the class emitter chain.

### 3. [UID:0000FV]/[UID:0000P4] `VideoPlayerPane`

Evidence for:

- `LogoPlayerPane` derives from `VideoPlayerPane`;
- the target ultimately affects Bink playback through `AdvanceToNextSegment` and `OpenBinkVideo`.

Evidence against:

- target callee is the derived segment helper, not base video start/stop/idle logic;
- the skip policy is startup-segment-specific;
- no target field/callee evidence requires moving the handlers into `VideoPlayerPane`.

Decision: reject as direct owner; keep as dependency/base context.

### 4. [UID:00004N] `EventHandler` / [UID:0000A2] `Pane`

Evidence for:

- target is reached through the `+0xa0` EventHandler secondary view;
- Pane/EventHandler own the virtual dispatch infrastructure.

Evidence against:

- target implements derived behavior and calls a derived helper;
- EventHandler/Panecore only provide base interface and registration mechanics.

Decision: reject as direct owner; keep as interface/layout support.

### 5. Event/EventMan or a new InputHandler source

Evidence for:

- EventMan defines the event type semantics.

Evidence against:

- EventMan produces the event; it does not own pane-specific event consumption;
- no new InputHandler class/source file is needed because `+0xa0` resolves to the documented Pane/EventHandler view.

Decision: reject.

## Final Recommendation

Recommended target changes:

- Raise [UID:0002PV] to `COMPLETION:87`, `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:00007H`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:00007H`.
- Keep formal `RECONSTRUCTION_CPP` blank.
- Replace the target's open questions with resolved/high-probability conclusions:
  - event type `8` is key down;
  - event type `3` is left mouse button release/up;
  - `this - 0xa0` is the Pane/EventHandler secondary view;
  - no-direct-caller state is normal vtable dispatch;
  - handlers always return handled.

No direct IDA DB edit, by-* edit, generated-source edit, or coverage edit was performed by B001.

## Support Docs To Update

Recommended supervisor updates:

- Target [UID:0002PV]:
  - update score to `87/90`;
  - add current IDA MCP session/evidence summary;
  - close the event type `8` and type `3` open questions;
  - document type `3` as specifically left-button release/up;
  - document `+0xa0` as Pane/EventHandler secondary view, not a new InputHandler owner;
  - keep final C++ blank with explicit source declaration blockers.

- [UID:00007H] `LogoPlayerPane`:
  - update method row/status for the input handler pair;
  - refine "mouse-up" wording to "left mouse button release/up";
  - keep `OnKeyEvent`/`OnMouseEvent` as source-facing method names.

- [UID:00019D] `LogoPlayerPane` aggregate:
  - update the [UID:0002PV] child row and score;
  - mention that no split is required, with optional exact method split available later.

- [UID:0000O4] `StartupLogoPanes`:
  - update child status and note the resolved event semantics.

- [UID:0000J6] `Event` or [UID:00014C] `EventManAndEventFactoryHelpers`:
  - optional support update documenting EventMan type mapping: `0` cursor, `1` left down, `2` left double-click, `3` left up, `4` right down, `5` right double-click, `6` right up, `7` wheel, `8` key down, `9` key release construction path.

- [UID:00004N] `EventHandler` / [UID:0001VH] `PaneLayout`:
  - optional support note that [UID:0002PV] validates derived event-family overrides reached through the `+0xa0` secondary view.

## Supervisor-Owned Coverage Row

Do not let B001 edit `by-memory/-coverage-report.md` directly. If the supervisor accepts this recommendation, replace the current [UID:0002PV] row under the `0x004f...` LogoPlayerPane coverage block with this exact row:

```text
        - [UID:0002PV][0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers](by-memory/0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers.md) 0x004f55d0-0x004f561d | vtable method pair | LogoPlayerPaneInputSkipHandlers : reconstructable : 87% : strong : B001 2026-06-17 source-quality reanalysis keeps owner/emitter [UID:00007H][LogoPlayerPane] and models the range as the source-authored `OnKeyEvent`/`OnMouseEvent` virtual pair reached through the Pane/EventHandler secondary view at +0xa0; live IDA confirms exact key handler `0x004f55d0-0x004f55fc`, internal `0xcc` padding `0x004f55fc-0x004f5600`, mouse handler `0x004f5600-0x004f561d`, vtable-only xrefs `0x0061d078` and `0x0061d074`, no direct code callers, EventMan type `8` as key-down with translated key byte +0x08 matching Enter/Escape/Space (`0x0d/0x1b/0x20`, verified with int_convert.py), EventMan type `3` as left-button release, `this-0xa0` normalization before both calls to `LogoPlayerPaneAdvanceToNextSegment`, always-handled returns even for nontriggering events, and LogoPlayerPane/StartupLogoPanes ownership over VideoPlayerPane/Pane/Event alternatives. Formal C++ remains blank pending coordinated EventHandler/KeyEvent/MouseEvent declaration names.
```

Placement context: replace the row currently beginning:

```text
        - [UID:0002PV][0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers]
```

No insert/delete rows are required unless the supervisor chooses the optional future split.

## Validation Commands For Supervisor

Run after applying accepted doc and coverage edits:

> Executable block R001 was removed from this report and preserved verbatim in [0002PV-logoplayer-input-skip-handlers-source-quality-removed.md](0002PV-logoplayer-input-skip-handlers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If optional Event/EventHandler support notes are applied, validate those pages too:

> Executable block R002 was removed from this report and preserved verbatim in [0002PV-logoplayer-input-skip-handlers-source-quality-removed.md](0002PV-logoplayer-input-skip-handlers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

B001 did not run validators on by-* docs because this assignment is report-only and no by-* docs or coverage report were edited.

## Tooling Notes And Blockers

No blockers remain for supervisor execution.

Tool note: one initial `int_convert.py` invocation passed multiple values as one argument and returned an invalid-number error. B001 retried with one value per invocation and verified the needed conversions successfully.

No IDA MCP timeout or transient multi-agent blocker affected the final evidence.

## Follow-Up Work

Useful next work:

- coordinated UI-core Event/EventHandler declaration pass for final enum names, `KeyEvent`/`MouseEvent` field names, and virtual slot names;
- source-quality pass on [UID:0002PU] `LogoPlayerPaneAdvanceToNextSegment` to settle `+0xfc`, `+0x104`, `+0x108`, `+0x110`, `+0x114`, `OpenBinkVideo`, and playback virtual names;
- optional exact split of [UID:0002PV] into separate key/mouse pages only if the supervisor wants stricter one-method coverage rows.

## Changed Files And Leases

Created:

- `tools/leaser/Agents/Agent-B001/research/0002PV-logoplayer-input-skip-handlers-source-quality.md`

Modified:

- none outside this report.

Leases used:

- none. No lease is required for creating a research report inside the Agent-B001 research folder, and B001 did not edit any leased-scope by-* file.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002PV-logoplayer-input-skip-handlers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002PV"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002PV-logoplayer-input-skip-handlers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0002PV-logoplayer-input-skip-handlers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002PV"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
