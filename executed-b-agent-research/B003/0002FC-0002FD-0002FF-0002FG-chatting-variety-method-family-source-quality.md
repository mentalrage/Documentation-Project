** TARGET-REPORT-UID:0002FC **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002FC/0002FD/0002FF/0002FG ChattingVariety Method Family Source-Quality Research

## Finalized Report / Current Recommendation

- Assignment: `B003-goal2-chatting-variety-method-family-source-quality-0002FC-0002FD-0002FF-0002FG-20260617`.
- Current recommendation: keep all four targets owned/emitted by [UID:00001Y] `ChattingVarietyPane` under [UID:0000I5] `Chatting`; raise the two modeled virtual methods [UID:0002FC] and [UID:0002FD] above the active 85/85 source-quality gate; keep the two raw helpers [UID:0002FF] and [UID:0002FG] at `82/90` with a defended no-85 completion result.
- Final disposition:
  - [UID:0002FC] `0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent.md`: `82/90 -> 86/91`, `RECONSTRUCTABLE:TRUE`, owner/emitter unchanged as [UID:00001Y], formal C++ blank.
  - [UID:0002FD] `0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint.md`: `82/90 -> 86/91`, `RECONSTRUCTABLE:TRUE`, owner/emitter unchanged as [UID:00001Y], formal C++ blank.
  - [UID:0002FF] `0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md`: keep `82/90`, `RECONSTRUCTABLE:TRUE`, owner/emitter unchanged as [UID:00001Y], formal C++ blank.
  - [UID:0002FG] `0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest.md`: keep `82/90`, `RECONSTRUCTABLE:TRUE`, owner/emitter unchanged as [UID:00001Y], formal C++ blank.
- Required action: supervisor should update the two modeled method pages and coverage rows with the exact text/directions below. No split is required; the raw helpers already have exact child pages and evidence-bounded completion caps.
- Confidence: high for ownership, ranges, semantics, and source placement; medium for final shared UI/GrafPort helper names, which is the reason formal method C++ should stay blank even for the two targets that clear the code-entry score gate.

## Target

| UID | Path | Current | Recommended | Direct owner/emitter | C++ policy |
| --- | --- | ---: | ---: | --- | --- |
| [UID:0002FC] | `by-memory/0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent.md` | `82/90` | `86/91` | [UID:00001Y] `ChattingVarietyPane` | Keep blank |
| [UID:0002FD] | `by-memory/0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint.md` | `82/90` | `86/91` | [UID:00001Y] `ChattingVarietyPane` | Keep blank |
| [UID:0002FF] | `by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md` | `82/90` | `82/90` | [UID:00001Y] `ChattingVarietyPane` | Keep blank |
| [UID:0002FG] | `by-memory/0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest.md` | `82/90` | `82/90` | [UID:00001Y] `ChattingVarietyPane` | Keep blank |

## Supervisor Active Recheck

- This is report-only B-agent work. I did not edit by-* docs, generated reports/source, source files, IDA DB, or `by-memory/-coverage-report.md`.
- Existing executed B report checked: `tools/leaser/Agents/Agent-B003/research/executed/00001Y-chatting-variety-pane-source-quality.md`. It is now authoritative only as a lead that was accepted/executed; this report reuses its IDA facts where they were already incorporated into current by-* docs and current coverage rows.
- Current primary/support docs checked: the four target pages, [UID:00001Y] `by-class/ChattingVarietyPane.md`, [UID:00001Z] `by-class/ChattingVarietySelectPane.md`, [UID:0000I5] `by-file/Chatting.md`, current `by-memory/-coverage-report.md`, and supporting Pane/GrafPort/EPF/Surface docs referenced by the target pages.
- Split-first result: no new split is safe or needed. [UID:0002FC] and [UID:0002FD] are exact modeled functions. [UID:0002FF] and [UID:0002FG] are already exact raw-helper children with surrounding padding documented; their blocker is not missing split structure, but missing entry/caller/source-declaration proof.

## Executive Recommendation

[UID:0002FC] should be documented as `bool ChattingVarietyPane::OnMouseEvent(const PaneMouseEvent *event)` in source-facing prose. It is a vtable-owned compact button mouse handler. The three open questions in the current page can be closed:

- `dword_67A748 + 0x13eb1d` is best documented as a broad local-player/UserPane input-lock byte, not a chat-owned global. It gates both compact and selector input.
- `0x00544690` is `Pane::MarkForDeletion` / deferred-dismiss, not focus, raise, or toggle. `PaneCore` documents `+0xf4` as the dismissed/deferred-delete marker and the helper queues the Pane in the BlackHole/deferred-deletion route.
- The inline selector allocation is source-equivalent to creating a `ChattingVarietySelectPane`, but the binary duplicates the raw selector constructor body in this method while [UID:0002FH] remains raw/no-xref. The target should say source likely used constructor-shaped code or an inlined constructor, but formal C++ should not yet commit to a clean `new ChattingVarietySelectPane()` method body.

[UID:0002FD] should be documented as `void ChattingVarietyPane::OnPaint()`. Its open questions can be closed:

- `dword_67A748 + 0x3eb4` is best documented as `currentChatMode` / `currentChatVarietyMode`, with values `0 Talk`, `1 Shout`, `2 Whisper`, `3 Group`, `4 Clan`.
- `0x004b9670` is the shared [UID:000162] GrafPort draw/display-mode setter, not `ChattingVarietyPane` code.
- `OnPaint` is the best source-facing method name. The generated `Initialize` name is rejected because the function is in a paint vtable slot and draws `CHATVAR.EPF`/`CHATVAR.PAL` plus text each call.

[UID:0002FF] and [UID:0002FG] should remain exact compact-helper pages attached to `ChattingVarietyPane`, not selector rows. They should not be raised above 85 completion or receive formal C++ until one of these appears: a direct caller, an indirect pointer route, a recovered original symbol, or raw-binary evidence showing a source declaration route. The best descriptive names are `ChattingVarietyPaneCompactButtonRectHelper` and `ChattingVarietyPaneCompactButtonHitTest`.

## Heuristic / Inference Reanalysis And Validation

### [UID:0002FC] Mouse handler name/signature

- Best defensible source direction: `bool ChattingVarietyPane::OnMouseEvent(const PaneMouseEvent *event)` or the project-local equivalent returning handled state.
- Evidence checked: current [UID:0002FC] page records the function range `0x00480cd0-0x00480e80`, vtable data xref `0x00614ef4`, event byte `event+4 == 1`, point fields `event+8/+0xc`, compact hit-test, popup creation/dismissal, and owner refresh. [UID:00001Y] formal class declaration now uses `virtual bool OnMouseEvent(const PaneMouseEvent *event)`.
- Rejected alternatives: generated `OnChatMessage` is contradicted by coordinate/event input and popup toggling; a generic `OnCommand` is contradicted by mouse-event point fields; selector ownership is contradicted by the `this+0xfc` compact-pane selector pointer and [UID:00001Y] vtable slot.
- Impact: raises [UID:0002FC] above gate because name, source owner, event role, and prior open behavior questions are resolved. It does not justify formal C++ because shared event/Pane setup names are still not final enough.

### [UID:0002FC] local-player/UserPane input-lock byte

- Best defensible field direction: `g_pCollectionData->localPlayerInputLocked` / `UserPane` UI input-lock byte at `+0x13eb1d`, not a `ChattingVarietyPane` field and not a chat-only option.
- Evidence checked: [UID:00001Y] executed report and current class doc record this as a broader local-player/UserPane input-lock gate; selector mouse uses the same gate; [UID:0002FC] current raw evidence shows the guard before event handling.
- Rejected alternatives: a chat variety mode byte is rejected because the actual mode field is `+0x3eb4` and is read by paint/selector mode logic; a modal-popup-local flag is rejected because the byte lives in `dword_67A748`, outside the compact/selector objects.
- Impact: close the target doc's "Confirm global state byte" question. Source-facing prose should avoid naming it as a definitive original symbol, but it is strong enough for score `86/91`.

### [UID:0002FC] existing-popup helper `0x00544690`

- Best defensible helper direction: `Pane::MarkForDeletion` / deferred-dismiss helper.
- Evidence checked: current `PaneCore` documentation at `0x00544690-0x005446ad` records the helper setting pane byte `+0xf4` and queuing the pane through the deferred-deletion route. [UID:0002FK] selector dismiss page also refreshes the compact button and calls this same helper.
- Rejected alternatives: focus/raise is rejected because the helper sets a deletion/dismiss marker and calls the BlackHole/deferred-delete route; visibility toggle is rejected because no visibility field clear or layer attach/detach branch is present; "existing popup path creates another selector" is rejected because it calls the helper on `this+0xfc` instead of allocating.
- Impact: close the target doc's "dismisses/focuses/toggles" question. This is a material completion gain for [UID:0002FC].

### [UID:0002FC] selector construction and popup setup

- Best defensible source direction: the create branch is source-equivalent to constructing a `ChattingVarietySelectPane`, storing it in `m_selectPane` and `g_pChattingVarietySelectPane`, setting popup bounds `(7,617,74,727)`, attaching it to a main UI layer slot, then invoking an inherited order/dispatcher setup method.
- Evidence checked: [UID:0002FC] decompilation records allocation size `0xfc`, `Pane` base constructor `0x00544460`, selector vtable stores, `+0xf8=0`, `+0xf9=0xff`, selector pointer at compact `+0xfc`, popup rectangle, vtable slot `+0x30`, vtable slot `+0x3c`, and owner refresh. [UID:0002FH] records a raw constructor-shaped selector body with the same constructor bytes but no modeled function/xrefs. Pane vtable docs identify slot `+0x30` as inherited `Pane::AddToLayer`; slot `+0x3c` is the inherited `Pane::SetPaneOrder`/dispatcher helper. `MainUiLayerSlots` documents `dword_69B364` as a broad main UI layer/context slot, not a final source name.
- Rejected alternatives: emitting this as `Detach(this->m_selectPane)` from generated output is wrong because the existing branch calls `MarkForDeletion`; emitting this as a selector-owned method is wrong because allocation and pointer storage happen inside the compact pane click handler; pretending the raw selector constructor is proven as a normal callable method is unsafe because [UID:0002FH] still has no function model or xref.
- Impact: behavior is solved, but formal [UID:0002FC] C++ remains unsafe because code would have to commit to final `ChattingVarietySelectPane` constructor de-duplication, `Pane` slot `+0x3c` naming, and `dword_69B364` source name before those supporting docs are code-ready.

### [UID:0002FD] paint method name and mode field

- Best defensible source direction: `void ChattingVarietyPane::OnPaint()` renders the compact mode button and label. The mode field is `currentChatMode` / `currentChatVarietyMode` at `dword_67A748 + 0x3eb4`.
- Evidence checked: [UID:0002FD] current page records vtable-only xref `0x00614ee4`, `CHATVAR.EPF`, `CHATVAR.PAL`, popup-state frame argument from `g_pChattingVarietySelectPane`, mode read at `+0x3eb4`, labels `Talk/Shout/Whisper/Group/Clan`, text centering, and two `DrawWideText` passes. [UID:00001Y] executed class report validated `OnPaint` as the declaration name and rejected generated `Initialize`.
- Rejected alternatives: `Initialize` is rejected because the method draws every call and is placed in the paint vtable slot; `Draw` is a weaker generic name because the class declaration and sibling Pane virtual naming use `OnPaint`; adding `Color` as stored mode `5` is rejected because row 5 opens color selection and current paint labels only cover values 0-4.
- Impact: close all current [UID:0002FD] open questions except final shared helper declarations. Score can rise to `86/91`.

### [UID:0002FD] shared render/GrafPort dependencies

- Best defensible helper/source direction: `0x00457a60` initializes an `EPFTileContext`; `0x004d02f0` looks up the `CHATVAR.EPF` frame; `0x004b9980` renders the frame with `CHATVAR.PAL`; `0x004b9670`, `0x004b9680`, `0x004b9600`, and `0x004bab70` are shared GrafPort draw/display mode, background-color, MoveTo, and DrawWideText helpers.
- Evidence checked: [UID:0000XY], [UID:0002KP], [UID:000165], [UID:000162], and [UID:00016C] support docs all own those helper islands. Current [UID:000162] explicitly records `0x004b9670` as a shared draw/display-mode setter used by `ChattingVarietyPane::OnPaint`; [UID:00001Y] removed it from class-owned helper inventory.
- Rejected alternatives: treating `0x004b9670` as a `ChattingVarietyPane` method is owner pollution; emitting support helper declarations in [UID:0002FD] would exceed this method's range and duplicate shared owners; using generated FittingRoom names is contradicted by current Chatting/GrafPort support docs.
- Impact: source placement under `social/Chatting.cpp` is strong, but formal [UID:0002FD] C++ should remain blank until those shared helper/type names are code-ready or formal wrapper names are accepted.

### [UID:0002FF] raw rectangle helper liveness and source name

- Best defensible source direction: retained/file-local compact helper, descriptive name `ChattingVarietyPaneCompactButtonRectHelper` / `GetCompactButtonRect`. It writes `(0,0,62,24)` for index `0` and `(-1,-1,-1,-1)` otherwise.
- Evidence checked: current [UID:0002FF] records no modeled function at `0x00481010`, exact `0x00481010-0x00481056` body, `ret 8`, surrounding `0xcc` padding, two `sub_4B7C50` calls, no direct `callers`/`xrefs_to`, and geometry shared with [UID:0002FC] and [UID:0002FG]. The executed [UID:00001Y] report additionally records `trace_data_flow backward 0x00481010` returning no inbound refs.
- Rejected alternatives: selector row helper is rejected because selector rows have six-row geometry in [UID:0002FM]/[UID:000106]; compiler thunk is rejected because the helper contains handwritten rectangle logic and calls the rectangle setter; dead CRT/library code is rejected because it sits in the chat UI cluster and uses project rectangle helpers; raising above 85 is rejected because no caller, pointer route, or original symbol proves a source declaration/call shape.
- Impact: ownership and compact/source placement are solved, but completion must stay below 85. Confidence can remain `90` because the bytes and semantics are exact.

### [UID:0002FG] raw hit-test helper liveness and source name

- Best defensible source direction: retained/file-local compact helper, descriptive name `ChattingVarietyPaneCompactButtonHitTest` / `HitTestCompactButton`, taking point-like `x,y` arguments and returning byte-like row `0` or `0xff`.
- Evidence checked: current [UID:0002FG] records no modeled function at `0x00481060`, exact `0x00481060-0x004810ea` body, stack-cookie exits, surrounding padding, `sub_4B7C50`/`sub_4B7E80` calls, one-candidate loop, return `0` on hit and `0xff` on miss, no direct `callers`/`xrefs_to`, and same compact geometry as [UID:0002FF]/[UID:0002FC]. The executed [UID:00001Y] report records `trace_data_flow backward 0x00481060` returning no inbound refs.
- Rejected alternatives: selector initial row hit-test is rejected because the popup selector has six rows and its real hit-test is [UID:000106]; compiler artifact is rejected because the body is source-shaped geometry logic; declaring a formal private static helper is rejected until entry liveness/source declaration is proven.
- Impact: ownership and compact/source placement are solved, but completion must stay below 85 for the same evidence reason as [UID:0002FF].

## Evidence Standards Used

- IDA facts used from current target/support docs and executed B003 report: function boundaries, raw byte boundaries, padding, vtable data xrefs, call/callee sets, no-xref/no-function status, decompilation observations, and negative trace-data-flow for raw helper starts.
- Documentation evidence used: current target pages, [UID:00001Y] class page, [UID:00001Z] selector class page, [UID:0000I5] file page, [UID:0001EA] PaneCore/Pane layout docs, [UID:000162]/[UID:00016C]/[UID:000165] GrafPort/Surface docs, [UID:0000XY] EPFTileContext, [UID:0002KP] ResourceLayoutTable lookup, and `by-memory/-coverage-report.md`.
- Generated output evidence: current generated `social/Chatting.cpp` has only class-level declaration output for [UID:00001Y]; method bodies remain omitted. `source-3/simroot_v2/class_ChattingVarietyPane.cpp` remains non-authoritative and polluted (`OnChatMessage`, `Initialize`, wrong existing-popup behavior, and FittingRoom/GrafPort owner pollution).
- Why evidence is enough: the modeled methods have exact functions, vtable slots, and behavior/callee evidence. The raw helpers have exact bytes and semantics but no entry/caller route, so their ownership can be high-confidence while their completion remains capped.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct parent | Recommended score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00480cd0-0x00480e80` | [UID:0002FC] `ChattingVarietyPaneOnMouseEvent` | compact button mouse handler | TRUE | [UID:00001Y] | `86/91` | raise; C++ blank |
| `0x00480e80-0x00480ff1` | [UID:0002FD] `ChattingVarietyPaneOnPaint` | compact button paint method | TRUE | [UID:00001Y] | `86/91` | raise; C++ blank |
| `0x00481010-0x00481056` | [UID:0002FF] compact rectangle helper | raw compact button rect helper | TRUE | [UID:00001Y] | `82/90` | defended no-85; C++ blank |
| `0x00481060-0x004810ea` | [UID:0002FG] compact hit-test helper | raw compact button hit-test helper | TRUE | [UID:00001Y] | `82/90` | defended no-85; C++ blank |

## Direct Xref / Caller Inventory

| Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| [UID:0002FC] | vtable data xref `0x00614ef4`; calls `sub_4B7C50`, `sub_4B7E80`, allocator `0x004f4aa0`, `Pane` base constructor `0x00544460`, `Pane::MarkForDeletion` `0x00544690` | live compact mouse virtual |
| [UID:0002FD] | vtable data xref `0x00614ee4`; calls EPFTileContext init, ResourceLayoutTable lookup, Surface frame render, GrafPort draw/text helpers | live compact paint virtual |
| [UID:0002FF] | no modeled function, no inbound callers/xrefs; calls `sub_4B7C50` twice | raw retained compact rectangle helper, route not proven |
| [UID:0002FG] | no modeled function, no inbound callers/xrefs; calls `sub_4B7C50` and `sub_4B7E80` | raw retained compact hit-test helper, route not proven |

## Documentation Evidence And IDA Status

- [UID:00001Y] currently emits a declaration-only `ChattingVarietyPane` class at `87/92`, with `OnMouseEvent`, `OnPaint`, `m_compactButtonState`, padding, `m_selectPane`, and `[[CHILDREN]]`. This supports the method owner/emitter route.
- [UID:00001Z] keeps [UID:0002FF]/[UID:0002FG] as related adjacency/opening helpers only, not selector-owned row methods. The selector's true row helpers remain [UID:0002FM] and [UID:000106].
- [UID:0000I5] `Chatting` already places the compact variety pane range through [UID:0002FG] in `social/Chatting.cpp` and treats [UID:000162] as a paint dependency, not a Chatting method.
- Current [UID:0002FC] and [UID:0002FD] pages still contain open questions. This report resolves them and supplies exact replacement guidance.
- Current [UID:0002FF] and [UID:0002FG] pages already contain the compact-owner resolution and evidence-bounded blank-C++ policy. This report validates those pages and explains why they cannot safely clear 85 completion now.

## Ranked Ownership Analysis

### 1. [UID:00001Y] ChattingVarietyPane

- Evidence for: vtable slots for [UID:0002FC]/[UID:0002FD] are `ChattingVarietyPane`; class field `+0xfc` is the active selector pointer used by [UID:0002FC]; [UID:0002FF]/[UID:0002FG] compact geometry `(0,0,62,24)` matches [UID:0002FC]; [UID:00001Y] class page and [UID:0000I5] file page are both above 85/85 and already route to generated `social/Chatting.cpp`.
- Evidence against: [UID:0002FF]/[UID:0002FG] filenames still carry stale advanced-scan selector labels, and those raw helpers have no direct caller. This affects completion/C++ readiness, not semantic owner.
- Decision: keep as direct owner/emitter for all four targets.

### 2. [UID:00001Z] ChattingVarietySelectPane

- Evidence for: [UID:0002FF]/[UID:0002FG] sit immediately before the raw selector constructor and support opening the selector popup.
- Evidence against: their geometry is the compact opener button, not selector rows; [UID:00001Z] owns separate six-row geometry helpers [UID:0002FM]/[UID:000106]; [UID:0002FC] compact mouse handler uses the same `(0,0,62,24)` test before creating or dismissing the selector.
- Decision: reject as owner. Keep only related adjacency/opening context.

### 3. Shared Pane/GrafPort/EPF owners

- Evidence for: [UID:0002FC] and [UID:0002FD] depend on shared Pane, GrafPort, ResourceLayoutTable, EPFTileContext, and Surface helpers.
- Evidence against: dependencies are callees/consumers, not the receiver class owner; no shared helper owns the compact selector pointer, vtable slots, or `CHATVAR` UI method bodies.
- Decision: reject as target owners. Keep as source dependencies and C++ blockers.

## First-Draft C++ Recommendation

Formal C++ should remain blank for all four targets in this pass.

[UID:0002FC] clears the active score gate with the recommended `86/91`, but **do not populate formal C++**. The method body depends on source decisions not final enough for executable reconstruction: the selector constructor is duplicated inline while [UID:0002FH] is raw/no-xref; inherited Pane slot `+0x3c` still has a provisional source-facing name/signature; `dword_69B364` is only a broad main UI layer/context slot; and the shared `PaneMouseEvent`/local-player state names are not formal type declarations. A first draft would either overfit generated polluted code or introduce placeholders into final output.

[UID:0002FD] clears the active score gate with the recommended `86/91`, but **do not populate formal C++**. The behavior is solved, but final-output code would require stable declarations for `EPFTileContext`, ResourceLayoutTable lookup, Surface frame rendering, GrafPort draw/display-mode/background/move/text helpers, and the `g_pCollectionData` mode field. The supporting helper docs themselves keep formal C++ blank or provisional for these names, so emitting this method now would create a placeholder-heavy body around not-yet-code-ready shared APIs.

[UID:0002FF] and [UID:0002FG] do not clear 85 completion and **must keep formal C++ blank**. They are source-shaped raw helpers, but no modeled function, direct caller, pointer route, or original symbol proves their source declaration/call shape. The best names should be recorded in prose and coverage text only.

Review-only source direction, not for formal insertion:

- [UID:0002FC]: `ChattingVarietyPane::OnMouseEvent` checks the local-player input lock, handles left/button event type `1`, tests compact rect `(0,0,62,24)`, dismisses an existing selector with `Pane::MarkForDeletion`, otherwise constructs/attaches a selector popup at `(7,617,74,727)`, refreshes the owner, and returns handled.
- [UID:0002FD]: `ChattingVarietyPane::OnPaint` renders `CHATVAR.EPF`/`CHATVAR.PAL`, picks frame by `g_pChattingVarietySelectPane != nullptr`, labels `currentChatMode` as Talk/Shout/Whisper/Group/Clan, and draws shadow/foreground text centered near the bottom.
- [UID:0002FF]/[UID:0002FG]: compact helper declarations should wait until a caller or original symbol route is recovered.

## Exact Metadata Recommendations

- [UID:0002FC]:
  - `COMPLETION:86`
  - `CONFIDENCE:91`
  - Keep `CANONICAL_OWNER:00001Y`
  - Keep `RECONSTRUCTABLE:TRUE`
  - Keep `EMITTER_UIDS:00001Y`
  - Keep `RECONSTRUCTION_CPP` blank with a note that formal code is held for selector-constructor de-duplication, Pane slot/main-layer naming, and shared event/type declarations.
- [UID:0002FD]:
  - `COMPLETION:86`
  - `CONFIDENCE:91`
  - Keep `CANONICAL_OWNER:00001Y`
  - Keep `RECONSTRUCTABLE:TRUE`
  - Keep `EMITTER_UIDS:00001Y`
  - Keep `RECONSTRUCTION_CPP` blank with a note that formal code is held for EPF/Surface/GrafPort helper/type declarations and `currentChatMode` field typing.
- [UID:0002FF]:
  - Keep `COMPLETION:82`
  - Keep `CONFIDENCE:90`
  - Keep `CANONICAL_OWNER:00001Y`
  - Keep `RECONSTRUCTABLE:TRUE`
  - Keep `EMITTER_UIDS:00001Y`
  - Keep `RECONSTRUCTION_CPP` blank.
- [UID:0002FG]:
  - Keep `COMPLETION:82`
  - Keep `CONFIDENCE:90`
  - Keep `CANONICAL_OWNER:00001Y`
  - Keep `RECONSTRUCTABLE:TRUE`
  - Keep `EMITTER_UIDS:00001Y`
  - Keep `RECONSTRUCTION_CPP` blank.

## Exact Target-Doc Update Recommendations

[UID:0002FC] should replace its current `Behavior` first paragraph/branch caveat with wording equivalent to:

```markdown
This method is `ChattingVarietyPane::OnMouseEvent`. It refuses input when the broad local-player/UserPane input-lock byte at `dword_67A748 + 0x13eb1d` is set. On event subtype `1`, it reads the point fields at `event+8`/`event+0xc`, hit-tests the compact chat-variety button rectangle `(0,0,62,24)`, and returns handled only when the point lands inside the button.

If `g_pChattingVarietySelectPane` already exists, the method calls `Pane::MarkForDeletion` (`0x00544690`) on `this+0xfc`, so the existing selector popup is dismissed/deferred-deleted; this is not a focus/raise/toggle helper. Otherwise it allocates `0xfc` bytes and performs constructor-shaped `ChattingVarietySelectPane` setup inline: `Pane` base construction, selector vtable stores, `g_pChattingVarietySelectPane` and `m_selectPane` stores, `+0xf8=0`, `+0xf9=0xff`, popup bounds `(7,617,74,727)`, inherited `Pane::AddToLayer` through slot `+0x30` with `dword_69B364`, and inherited order/dispatcher setup through slot `+0x3c`. The create branch is source-equivalent to constructing a selector popup, but formal C++ should not rewrite it as a clean `new ChattingVarietySelectPane()` until the raw selector constructor [UID:0002FH] and Pane slot names are code-ready.
```

[UID:0002FC] should replace `Open Questions` with:

```markdown
## Open Questions

- Closed by B003 2026-06-17 source-quality pass: `dword_67A748 + 0x13eb1d` is best documented as a broad local-player/UserPane input-lock byte, not a chat-owned field.
- Closed by B003 2026-06-17 source-quality pass: `0x00544690` is `Pane::MarkForDeletion` / deferred popup dismissal, not focus/raise/toggle behavior.
- Remaining final-C++ blocker: the create branch is constructor-shaped selector setup, but [UID:0002FH] still has no modeled callable constructor/xref and the popup setup uses inherited Pane slot `+0x3c` plus `dword_69B364` names that are not source-final. Keep formal C++ blank until those dependencies are finalized.
```

[UID:0002FD] should replace its `Open Questions` with:

```markdown
## Open Questions

- Closed by B003 2026-06-17 source-quality pass: `dword_67A748 + 0x3eb4` is best documented as `currentChatMode` / `currentChatVarietyMode`, with values `0 Talk`, `1 Shout`, `2 Whisper`, `3 Group`, and `4 Clan`.
- Closed by B003 2026-06-17 source-quality pass: `0x004b9670` is the shared [UID:000162] GrafPort draw/display-mode setter, not a `ChattingVarietyPane` method.
- Closed by B003 2026-06-17 source-quality pass: the source-facing method name is `ChattingVarietyPane::OnPaint`; generated `Initialize` is rejected as owner/name pollution.
- Remaining final-C++ blocker: formal code should wait for code-ready EPFTileContext, ResourceLayoutTable, Surface/GrafPort helper declarations, and a stable declaration for the `currentChatMode` field.
```

[UID:0002FD] should add a short source-quality note:

```markdown
Source-quality reanalysis: this method belongs in `social/Chatting.cpp` as the exact `ChattingVarietyPane::OnPaint` body, but it depends on shared render/GrafPort helper APIs. Do not emit placeholder wrappers under `ChattingVarietyPane`; keep the body blank until those shared source names/types are formalized.
```

[UID:0002FF] and [UID:0002FG] need no required body edits beyond optionally adding this validation note:

```markdown
2026-06-17 B003 method-family recheck: the compact-owner conclusion is still valid. The helper is source-shaped and reconstructable, but completion remains capped below 85 because live IDA documentation still shows no modeled function, direct xref/caller, pointer route, or original symbol for the helper entry. The best descriptive names remain `ChattingVarietyPaneCompactButtonRectHelper` and `ChattingVarietyPaneCompactButtonHitTest`.
```

## Support-Doc Update Recommendations

- [UID:00001Y] `by-class/ChattingVarietyPane.md`: no score change required. It already contains the declaration-only class C++ and records the compact/source boundary. Optionally add that [UID:0002FC]/[UID:0002FD] are now source-quality raised to `86/91` but still own their method-body C++ blockers locally.
- [UID:00001Z] `by-class/ChattingVarietySelectPane.md`: no score change required. Keep [UID:0002FF]/[UID:0002FG] as related compact opener helpers only; do not restore them to selector-owned method rows.
- [UID:0000I5] `by-file/Chatting.md`: no score change required. Optionally refresh the `ChattingVarietyPane` row to say [UID:0002FC]/[UID:0002FD] are source-quality reviewed and formal method bodies are held for shared Pane/GrafPort/type names.
- [UID:000162] `GrafPortDrawStateAccessors`: no change required; it already records `0x004b9670` as the shared draw/display-mode setter used by `ChattingVarietyPane::OnPaint`.

## Exact Supervisor-Owned `by-memory/-coverage-report.md` Row Text

Placement context: replace the existing [UID:0002FC] and [UID:0002FD] rows currently adjacent to each other around lines 812-813. [UID:0002FF] and [UID:0002FG] rows do not require replacement unless the supervisor wants to restamp the no-change validation text; current rows are already pasteable and consistent with this report.

Replace [UID:0002FC] row with:

```markdown
        - [UID:0002FC][0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent](by-memory/0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent.md) 0x00480cd0-0x00480e80 | virtual method | ChattingVarietyPaneOnMouseEvent : reconstructable : 86% : very strong : B003 method-family source-quality reanalysis resolves this as `ChattingVarietyPane::OnMouseEvent(const PaneMouseEvent *)`; live IDA/current docs confirm the exact vtable-only range, local-player/UserPane input-lock gate at `dword_67A748+0x13eb1d`, event kind `1` and point fields, compact `(0,0,62,24)` hit-test, existing popup dismissal through `Pane::MarkForDeletion`, inline/new `ChattingVarietySelectPane` construction with `g_pChattingVarietySelectPane`, selector popup bounds `(7,617,74,727)`, inherited `Pane::AddToLayer` and order/dispatcher setup through `dword_69B364`, owner refresh, and rejection of generated `OnChatMessage`; formal C++ remains blank pending selector-constructor de-duplication, Pane slot `+0x3c` naming, main UI layer-slot naming, and shared event/type declarations.
```

Replace [UID:0002FD] row with:

```markdown
        - [UID:0002FD][0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint](by-memory/0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint.md) 0x00480e80-0x00480ff1 | paint method | ChattingVarietyPaneOnPaint : reconstructable : 86% : very strong : B003 method-family source-quality reanalysis resolves the vtable method as `ChattingVarietyPane::OnPaint`, rejects generated `Initialize`, confirms `CHATVAR.EPF`/`CHATVAR.PAL` rendering through EPFTileContext/ResourceLayoutTable/Surface paint helpers, uses `g_pChattingVarietySelectPane` as the alternate frame selector, identifies `dword_67A748+0x3eb4` as current chat variety mode with Talk/Shout/Whisper/Group/Clan labels, confirms shared GrafPort draw/display-mode, background-color, MoveTo, and DrawWideText dependencies, and documents centered shadow/foreground label placement; formal C++ remains blank pending final EPFTileContext/Surface/GrafPort helper declarations and `g_pCollectionData` field typing.
```

No replacement required for [UID:0002FF]/[UID:0002FG]. If the supervisor wants to keep all four assignment rows together in the applied review, leave their current rows unchanged:

```markdown
        - [UID:0002FF][0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper](by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md) 0x00481010-0x00481056 | compact button rectangle helper | ChattingVarietyPaneCompactButtonRectHelper : reconstructable : 82% : strong : B003 source-quality reanalysis keeps this as a source-shaped compact chat-variety button rectangle helper owned by ChattingVarietyPane, not the popup selector; IDA still has no modeled function or inbound xrefs, but exact bytes, two sub_4B7C50 rectangle setter calls, compact (0,0,62,24) and empty (-1,-1,-1,-1) outputs, padding spans, and selector-row alternative rejection are documented, so C++ remains blank pending caller or original symbol evidence.
        - [UID:0002FG][0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest](by-memory/0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest.md) 0x00481060-0x004810ea | compact button hit-test helper | ChattingVarietyPaneCompactButtonHitTest : reconstructable : 82% : strong : B003 source-quality reanalysis keeps this as a source-shaped compact chat-variety button hit-test helper owned by ChattingVarietyPane, not the popup selector; IDA still has no modeled function or inbound xrefs, but exact bytes, one-candidate compact (0,0,62,24) loop, sub_4B7C50/sub_4B7E80 calls, row 0 hit and 0xff miss returns, padding spans, and selector six-row alternative rejection are documented, so C++ remains blank pending caller or original symbol evidence.
```

## Validation Commands For Supervisor

Run after applying target/support/coverage edits:

> Executable block R001 was removed from this report and preserved verbatim in [0002FC-0002FD-0002FF-0002FG-chatting-variety-method-family-source-quality-removed.md](0002FC-0002FD-0002FF-0002FG-chatting-variety-method-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Optional generated-output check after supervisor applies metadata/C++ decisions:

> Executable block R002 was removed from this report and preserved verbatim in [0002FC-0002FD-0002FF-0002FG-chatting-variety-method-family-source-quality-removed.md](0002FC-0002FD-0002FF-0002FG-chatting-variety-method-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Remaining Blockers

- [UID:0002FC] formal method C++: blocked by selector-constructor de-duplication, [UID:0002FH] raw/no-xref state, Pane slot `+0x3c` naming, `dword_69B364` source name, and shared `PaneMouseEvent`/state type declarations. These do not block raising completion to 86 because behavior and source owner are solved.
- [UID:0002FD] formal method C++: blocked by shared EPFTileContext/Surface/GrafPort helper declarations and final `currentChatMode` field typing. These do not block raising completion to 86 because method behavior, owner, and source name are solved.
- [UID:0002FF]/[UID:0002FG] completion: blocked below 85 by no modeled function, no xref/caller, no pointer route, and no original symbol/source declaration proof. This is a real completion cap, not generic future work.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/0002FC-0002FD-0002FF-0002FG-chatting-variety-method-family-source-quality.md`.
- Modified: none outside this report.
- Leases used: none.
- Generated/source/IDA changes: none.

## Next Useful Follow-Up

- After supervisor applies this report, a future B/A pass can target [UID:0002FH] raw selector constructor plus Pane slot naming if the project wants formal [UID:0002FC] method C++.
- A separate shared GrafPort/Surface/EPFTileContext code-readiness pass would unblock formal [UID:0002FD] method C++ without forcing placeholder helper names into `ChattingVarietyPane`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002FC-0002FD-0002FF-0002FG-chatting-variety-method-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:28","uid":"0002FC"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002FC-0002FD-0002FF-0002FG-chatting-variety-method-family-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002FC-0002FD-0002FF-0002FG-chatting-variety-method-family-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002FC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
