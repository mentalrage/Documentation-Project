** TARGET-REPORT-UID:00018B **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00018B IMECandidate ShowCandidateList Source-Quality Report

Assignment: `B001-goal2-ime-candidate-show-list-source-quality-00018B-20260617`

Primary target: [UID:00018B] `by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md`

Report author: Agent-B001

Date: 2026-06-17

## Executive Recommendation

Keep [UID:00018B] as a reconstructable exact method owned and emitted by [UID:00006F] `IMECandidatePane`, routed through [UID:0000K5] `IMEPanes` / `NexusTK/input/IMEPanes.cpp`.

Recommended metadata:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `82` | `87` |
| `CONFIDENCE` | `88` | `90` |
| `CANONICAL_OWNER` | `00006F` | `00006F` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `00006F` | `00006F` |
| Formal `RECONSTRUCTION_CPP` | blank | keep blank |

Reason: live IDA, by-file, by-class, and adjacent source-context evidence all converge on a pane-side IME candidate-popup method. The prior generated `FittingRoomDownloadControlPane` name is owner pollution. The target has one direct code caller, [UID support context] `IMECandidatePane::HandleIMEMessage` at `0x004e7d00`, and that caller adjusts from a secondary event-handler subobject back to the primary `IMECandidatePane` object before dispatching Event type `15` to this method.

Do not split the target. `0x004e7930-0x004e7b6c` is one exact 0x23c-byte function body; the next function begins at `0x004e7b70`, with only alignment padding between them.

## Evidence Checked

Documentation reviewed:

- Target: `by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md`
- IME aggregate and route: `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`, `by-class/IMECandidatePane.md`, `by-class/IMEPane.md`, `by-file/IMEPanes.md`
- Candidate queue helpers: `by-class/CandidateStringQueue.md`, `by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md`
- Producer side: `by-file/InputMan.md`, `by-memory/0x004e8af0-0x004e970d.InputMan.md`
- Event side: `by-file/Event.md`, `by-class/Event.md`, `by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md`
- Shared helper owners: `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md`, `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`, `by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md`, `by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md`, `by-global/g_pIMEPane.md`
- Rejected generated owner context: `by-file/FittingRoom.md`, `by-class/FittingRoomDownloadControlPane.md`
- Focus-pane context: `by-file/TextEditPane.md`, `by-file/TextBoxPane.md`

Live IDA MCP evidence checked in read-only IDB session `b003_00018a_ime_comp_20260617`, IDB path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`:

- `lookup_funcs` for `0x004e7930`, `0x004e7b6c`, `0x004e7b70`, `0x004e7d00`, `0x004e7d13`, `0x004e7d30`, `0x004e81b0`, `0x004e8450`, `0x004e8af0`, and Event factories around `0x004a9e50`.
- `analyze_function` / decompile for `0x004e7930`, `0x004e7d00`, `0x004e8de0`, `0x004a9e50`, and `0x004a9f00`.
- `xrefs_to` for `0x004e7930`, `0x004e7d00`, `0x004e8450`, `0x0069b458`, and `0x004a9e50`.
- `callees` for the target and producer/helper functions.

## Function Boundary And Liveness

IDA reports `sub_4E7930` at `0x004e7930` with size `0x23c`; the half-open function range is `0x004e7930-0x004e7b6c`.

The next function is `sub_4E7B70` at `0x004e7b70`, so the four bytes from `0x004e7b6c-0x004e7b70` are padding/alignment, not target code.

Direct code xrefs:

| Referenced address | Xref evidence | Interpretation |
| --- | --- | --- |
| `0x004e7930` | one code xref at `0x004e7d13` from `sub_4E7D00` | target is live through the candidate-pane IME event handler |
| `0x004e7d00` | data xref from vtable data near `0x0061c4cc`; no direct code caller | handler is virtual/event-dispatch reachable, not dead |
| `0x004e8450` | one code xref at `0x004e7b3d` from target | target assigns the candidate string deque/range |
| `0x0069b458` (`g_pIMEPane`) | 17 refs including target read at `0x004e7a83` | target consults root IME pane state for popup clamping |
| `0x004a9e50` | one caller from `InputMan::HandleWindowMessage` at `0x004e927d` | producer-side candidate-list event factory is live |

The target is not a no-route raw body. Its direct caller is virtual-only, but the vtable data and caller body establish normal runtime reachability.

## Caller/Subobject Adjustment At `0x004e7d13`

`sub_4E7D00` decompiles to:

```c
char __thiscall sub_4E7D00(int *this, int event)
{
    if (*(BYTE *)(event + 4) != 15)
        return 0;
    sub_4E7930(this - 40, event);
    return 1;
}
```

The assembly performs `add ecx, 0FFFFFF60h` before the call. That is a `-0xa0` adjustment, or `-40` dwords, from a secondary event-handler subobject back to the primary `IMECandidatePane` object.

Best source-facing interpretation:

- `0x004e7d00` is an `IMECandidatePane` event/IME-message handler reached through an embedded handler/interface subobject at offset `+0xa0`.
- It filters Event type `15`, then calls `IMECandidatePane::ShowCandidateList` on the primary object.
- The adjustment is not evidence for a FittingRoom object, TextEdit object, or standalone helper class.

This resolves the required `0x004e7d13` subobject-adjustment issue.

## Heuristic / Inference Reanalysis And Validation

### Generated FittingRoom owner pollution

Best recommendation: discard `FittingRoomDownloadControlPane::ShowCandidateList` as generated owner pollution.

Evidence:

- `by-file/FittingRoom.md` and `by-class/FittingRoomDownloadControlPane.md` already flag both `0x004e7470` and `0x004e7930` as generated pollution and route them to IME.
- Live target caller is `0x004e7d13` inside `IMECandidatePane::HandleIMEMessage`, not a FittingRoom method.
- Target callees are IME/Event/UI helpers: candidate deque assign, GrafPort text metrics, RectBounds offset, screen width/height, and `g_pIMEPane`.
- No live xref, field access, pool, vtable, or module evidence connects the target to FittingRoom download progress controls.

Rejected alternative: keeping any FittingRoom direct owner/emitter. The only evidence for that name is generated labeling; all executable and documentation evidence points elsewhere.

Impact: keep direct owner/emitter as [UID:00006F] `IMECandidatePane`, and keep file placement under [UID:0000K5] `IMEPanes`.

### Source-facing method name and signature

Best source-facing method:

```cpp
void IMECandidatePane::ShowCandidateList(const Event* event);
```

Equivalent acceptable spelling if the project standard uses references:

```cpp
void IMECandidatePane::ShowCandidateList(const Event& event);
```

The decompiler returns an `int` because the final inherited invalidate call returns a value, but the sole caller ignores the result and the method is conceptually a UI state update. The best source-facing return type is `void`.

Payload interpretation:

- Event type byte at `event + 0x04` equals `15`, checked by the caller.
- Event field at `event + 0x08` is a pointer to the candidate string deque/list.
- Event field at `event + 0x0c` is the selected row within the visible candidate page.

Rejected alternatives:

- `int` or `bool` source return: decompiler artifact, no caller uses the value.
- FittingRoom method signature: contradicted by caller, global, helper, and support-doc evidence.
- InputMan method signature: InputMan produces the event but does not own the pane display logic.

Impact: the target should document the source-facing method as `IMECandidatePane::ShowCandidateList`, consuming an IME candidate-list Event payload.

### IME candidate payload and queue fields

Best payload model:

- Event type `15`: IME candidate-list event.
- `event + 0x08`: pointer to a `std::deque<std::wstring>`-like container containing the currently visible candidate strings.
- `event + 0x0c`: selected candidate row relative to that visible list.

Producer evidence from `InputMan::HandleWindowMessage` at `0x004e8de0`:

- Handles `WM_IME_NOTIFY` candidate-list subcommands for open/change candidate.
- Queries IMM candidate-list data through the function pointer currently documented around `unk_69BEC0`.
- Interprets `CANDIDATELIST` fields:
  - count from `Block[2]`
  - selection from `Block[3]`
  - page start from `Block[4]`
  - page size from `Block[5]`
- Defaults page size to `9` when the IMM page size is zero.
- Appends candidate strings from page start through visible page end by calling the deque append helper at `0x004e9710`.
- Calls `0x004a9e50` with `selectedRow = dwSelection - pageStart`, candidate deque pointer, and `GetMessageTime()`.

Event factory evidence from `0x004a9e50`:

- Constructs a stack Event.
- Stores Event type `15`.
- Stores the candidate deque pointer in the event payload field consumed at target offset `+0x08`.
- Stores the selected row in the event payload field consumed at target offset `+0x0c`.
- Dispatches through the event dispatcher and tears down the temporary Event.

Target-side deque evidence:

- The target reads the candidate container pointer from `event + 0x08`.
- It reads container offsets `+0x0c` and `+0x10` to compute begin/end offsets for iteration.
- Those fields are MSVC/Dinkumware deque internals (`_Myoff` and `_Mysize`-style fields), not product-authored IME payload fields.
- It later calls `0x004e8450` to assign/copy that range into the pane-local deque at `this + 0xf8`.

Best naming:

| Address/offset | Best source-facing name | Rationale |
| --- | --- | --- |
| `event + 0x08` | `candidateStrings` or `visibleCandidates` | producer has already reduced IMM data to the visible page |
| `event + 0x0c` | `selectedCandidateRow` | value is `dwSelection - pageStart`, not absolute IMM index |
| deque `+0x0c` | deque `_Myoff` / `beginOffset` in documentation only | compiler/library layout, not source member |
| deque `+0x10` | deque `_Mysize` / `count` in documentation only | compiler/library layout, not source member |
| `this + 0xf8` | `m_visibleCandidates` | pane-local display deque |
| `this + 0x10c` | `m_selectedCandidateRow` | selected row copied from event |

Rejected alternative: naming queue offsets `visibleStart` and `visibleCount` as custom IME fields. Those names are acceptable as explanatory prose, but the source-facing type should be `std::deque<std::wstring>` or a thin typedef such as `CandidateStringList`, not a handwritten `CandidateStringQueue` class with product-owned fields.

Impact: this resolves the visible-start/visible-count and selected-row blockers. It also supports keeping `CandidateStringQueue` as a non-source/generated STL label rather than creating a product class owner.

### Anchor, active child pane, and screen-bound fields

Target field recommendations:

| Offset | Best inferred name | Evidence |
| --- | --- | --- |
| `this + 0x110` | `m_candidateAnchorX` or `m_popupAnchorX` | used as popup anchor coordinate when building the target rect |
| `this + 0x114` | `m_candidateAnchorY` or `m_popupAnchorY` | paired with `+0x110`; used before screen clamping |
| `g_pIMEPane + 0xfc` | `IMEPane::m_activeChildPane` | consulted only when the popup would exceed the screen bottom; its virtual rect/bounds method is used for alternate vertical placement |

The target computes a candidate popup rectangle from anchor coordinates, measured maximum candidate width, and accumulated row height. It then clamps the rectangle:

- if the right edge exceeds screen width, it offsets left;
- if the bottom edge exceeds screen height and `g_pIMEPane->m_activeChildPane` is present, it positions relative to the active child pane bounds with an 8-pixel gap;
- if no active child pane is present, it offsets upward to fit screen height;
- if the left edge is negative, it offsets right.

Rejected alternatives:

- Treating `g_pIMEPane + 0xfc` as a FittingRoom, TextEdit, or InputMan field. The global is the root IME pane singleton, and the target only reads this field for display geometry.
- Treating anchor fields as absolute selected-row fields. The selected row is stored separately at `this + 0x10c`; `+0x110/+0x114` participate in rectangle construction.

Open bound: exact original spellings (`m_candidateAnchorX` versus `m_popupAnchorX`, `m_activeChildPane` versus `m_activePopupPane`) are not provable from current binaries/docs. The recommended names are source-facing semantic names, not final symbol spellings.

Impact: field roles are strong enough for 87/90, but exact spelling remains a formal-C++ blocker.

### Text measurement, rectangle, and screen helper names

Best helper ownership and naming:

| Address | Best source-facing role | Owner route |
| --- | --- | --- |
| `0x004ba9a0` | `GrafPort::MeasureTextWidth` / `TextWidth` | [UID:0000JR] `GrafPort` |
| `0x004baaa0` | `GrafPort::GetLineHeight` | [UID:0000JR] `GrafPort` |
| `0x004b7e10` | `RectBounds::OffsetRect` or `OffsetRect` | [UID:0000JQ] `RectBounds` |
| `0x00557450` | `GetScreenWidth` | [UID:0001G7] screen/cursor helper island, ScreenPane route |
| `0x00557460` | `GetScreenHeight` | [UID:0001G7] screen/cursor helper island, ScreenPane route |
| `0x004e8450` | `std::deque<std::wstring>::assign`-style range assign | IME candidate deque/STL helper island |

Rejected alternatives:

- FittingRoom-named text helpers. The `GrafPortTextRunHelpers` page documents broad render/text fan-in and rejects caller-biased generated names.
- IMECandidatePane ownership for `OffsetRect`, text metrics, or screen helpers. The target calls shared UI/render helpers; it does not own them.

Impact: helper-source placement is resolved, and the target can name calls semantically without stealing helper ownership.

### Pane geometry virtuals

The target uses inherited virtual calls:

- active child pane virtual slot `+0x28` with a stack rectangle output, best interpreted as `GetBounds` / `GetPaneRect`;
- target virtual slot `+0x2c` with the computed rectangle, best interpreted as `SetBounds` / `SetPaneRect` / `MoveToRect`;
- target virtual slot `+0x20` with `this + 0x44`, best interpreted as invalidation/redraw for the current bounds.

Evidence checked: target decompilation and caller/callee/vtable-use pattern. The current support docs do not yet provide a final Pane virtual slot naming contract for this exact call sequence.

Rejected alternatives:

- Naming these as candidate-specific helpers. The calls are inherited pane geometry/invalidator virtuals.
- Blocking owner/source placement on exact virtual names. The roles are clear enough for ownership and scoring, but exact spelling still blocks formal final C++.

Impact: source behavior is resolved at the semantic level; formal C++ should remain blank until Pane virtual declarations are coordinated.

### IMEPane versus FittingRoom/TextEdit/InputMan source placement

Ranked source-placement decision:

1. [UID:00006F] `IMECandidatePane`, emitted via [UID:0000K5] `IMEPanes`: best direct owner and file route. The method updates pane-local candidate popup state and geometry.
2. [UID:0000K5] `IMEPanes` file-level route: correct file/module route, but less precise than the class owner.
3. [UID:0000K6] `InputMan`: producer of candidate-list event payloads; reject as target owner because target displays the event and has no IMM calls.
4. [UID:0000J6] `Event`: owns the event factory at `0x004a9e50`; reject as target owner because target is a pane method.
5. `TextEditPane` / `TextBoxPane`: focus registration context only; reject as target owner.
6. `GrafPort`, `RectBounds`, `ScreenPane`: helper owners only; reject as target owner.
7. [UID:000052] `FittingRoomDownloadControlPane`: generated pollution; reject.

Impact: owner/emitter should remain [UID:00006F] with stronger evidence.

### Open questions resolved or bounded

Resolved:

- Generated FittingRoom owner is pollution.
- Direct owner/emitter is `IMECandidatePane`.
- Event type is candidate-list type `15`.
- Event payload `+0x08` is the candidate deque/list pointer.
- Event payload `+0x0c` is selected row within the visible page.
- Deque offsets `+0x0c/+0x10` are STL deque internals, not product source fields.
- Local pane candidate storage is at `this + 0xf8`.
- Selected candidate row is at `this + 0x10c`.
- Popup anchor fields are at `this + 0x110/+0x114`.
- `g_pIMEPane + 0xfc` is the active child-pane pointer used for vertical clamping.
- Helper owners are shared GrafPort, RectBounds, ScreenPane/screen-helper, Event, and STL helper islands, not FittingRoom.
- No range split is needed.

Bounded but not finally named:

- Exact original field spellings for candidate anchor and active child pane.
- Exact original Event subtype declaration and payload field names.
- Exact inherited Pane virtual names for get-bounds, set-bounds, and invalidate.
- Exact source typedef name for the candidate list if the codebase used a typedef instead of spelling `std::deque<std::wstring>` inline.

Why these cannot be safely resolved further in this pass:

- The binary provides layout and call-role evidence but not original member spellings.
- Existing support docs intentionally keep Event and Pane declarations below final-source confidence.
- Inventing exact spellings now would risk baking decompiler-shaped field names into formal C++.

Impact: these bounded names do not prevent score raise to 87/90 or owner/source placement, but they do prevent formal C++ population.

## First-Draft C++ Recommendation

Formal `RECONSTRUCTION_CPP` should remain blank for [UID:00018B] in this pass.

This is an explicit do-not-populate recommendation. Even though the target should be raised above the current first-draft gate as reconstructable and emitting, formal C++ would currently depend on shared declarations that are not finalized:

- Event subtype and candidate-list payload field declarations;
- Pane virtual names for bounds retrieval, bounds assignment, and invalidation;
- final `IMECandidatePane` field spellings for anchor/selected-row/candidate deque;
- source policy for representing the STL deque helper island versus a local typedef;
- final names for screen-width/screen-height helper accessors.

Review-only source shape:

```cpp
// Review-only. Do not enter this as formal RECONSTRUCTION_CPP yet.
void IMECandidatePane::ShowCandidateList(const Event* event)
{
    const CandidateStringList* candidates = event->imeCandidateStrings;
    const int selectedRow = event->imeCandidateSelectedRow;

    int maxTextWidth = 0;
    int popupHeight = 4;
    const int lineStep = GetLineHeight() + 2;

    for (const std::wstring& text : *candidates) {
        maxTextWidth = std::max(maxTextWidth, MeasureTextWidth(text.c_str(), text.length()));
        popupHeight += lineStep;
    }

    RectBounds bounds(
        m_candidateAnchorX,
        m_candidateAnchorY,
        m_candidateAnchorX + maxTextWidth + 6,
        m_candidateAnchorY + popupHeight);

    ClampCandidatePopupToScreenAndActiveChild(bounds);

    SetBounds(bounds);
    m_visibleCandidates.assign(candidates->begin(), candidates->end());
    m_selectedCandidateRow = selectedRow;
    Invalidate();
}
```

This shape is useful for reviewers, but it intentionally uses unresolved source declarations and helper names. The supervisor should not place it in the target formal C++ block.

## Score And Metadata Rationale

Recommended score: `87/90`.

Why not keep `82/88`:

- The main 82-level blockers are now resolved: generated FittingRoom pollution, caller/subobject adjustment, producer Event payload, queue-layout meaning, selected-row semantics, helper ownership, and split/range boundary.
- Live IDA evidence confirms the exact function size, sole direct caller, vtable-reachable handler, and producer-side Event factory route.

Why not higher than `87/90`:

- Exact original spellings for Event payload fields, Pane virtuals, and several `IMECandidatePane` members are still not recoverable from current evidence.
- Formal C++ should remain blank pending a coordinated Event/Pane/IME declaration pass.

Confidence should be `90`, not just `88`, because ownership, route, range, and behavior now have independent confirmation from target decompilation, caller xrefs, producer-side `InputMan`, Event factory, and support docs.

## Support Docs To Update

Recommended supervisor updates:

- Target `by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md`
  - Change score to `87/90`.
  - Keep owner/emitter [UID:00006F] and `RECONSTRUCTABLE:TRUE`.
  - Replace old first-draft gate language with the current gate and explicit do-not-populate final-C++ decision.
  - Add the caller/subobject adjustment evidence at `0x004e7d13`.
  - Add producer-side Event evidence from `InputMan::HandleWindowMessage` and `DispatchCandidateListEvent`.
  - Clarify that deque offsets `+0x0c/+0x10` are STL internals, while Event payload fields are `+0x08/+0x0c`.
  - Add recommended field/helper names and rejected alternatives.

- `by-class/IMECandidatePane.md`
  - Update the `ShowCandidateList` method row to `87/90`.
  - Add field-role notes for `m_visibleCandidates` (`+0xf8`), `m_selectedCandidateRow` (`+0x10c`), and candidate popup anchor fields (`+0x110/+0x114`).
  - Keep `CandidateStringQueue` language as generated/STL helper context rather than a product-owned class.

- `by-file/IMEPanes.md`
  - Note this B001 pass confirms `0x004e7930` as IMECandidatePane/IMEPanes source and rejects FittingRoom, InputMan, TextEdit, and helper-owner alternatives.

- `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`
  - Update the target child score/status and remove target-specific uncertainty around candidate payload/selected-row/queue-layout where appropriate.

- `by-file/InputMan.md` and `by-memory/0x004e8af0-0x004e970d.InputMan.md`
  - Optional but recommended: document that the candidate-list branch builds the visible candidate deque from `CANDIDATELIST` page-start/page-size data and dispatches Event type `15` with `selectedRow = dwSelection - pageStart`.

- `by-file/Event.md` and/or `by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md`
  - Optional but recommended: document `0x004a9e50` as `DispatchCandidateListEvent`, storing candidate deque pointer and selected row for IME candidate display.

- Generated reports and `project-level/-auto-completion-stats.md`
  - Regenerate after supervisor-owned doc/coverage updates.

## Supervisor-Owned Coverage Row

Do not let B001 edit `by-memory/-coverage-report.md` directly. If the supervisor accepts this recommendation, replace the current [UID:00018B] row under the `0x004e...` coverage section with this exact row:

```text
        - [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md) 0x004e7930-0x004e7b6c | method | IMECandidatePane::ShowCandidateList : reconstructable : 87% : strong : B001 2026-06-17 source-quality reanalysis keeps owner/emitter [UID:00006F][IMECandidatePane] and models the method as the pane-side `IMECandidatePane::ShowCandidateList` consumer of Event type 15; live IDA confirms exact 0x23c-byte body, sole caller `0x004e7d13` from `IMECandidatePane::HandleIMEMessage` with `this-0xa0` subobject adjustment, no fitting-room callee/state route, InputMan producer path from `WM_IME_NOTIFY` candidate-list handling through `ImmGetCandidateListW`, Event factory `0x004a9e50` storing candidate deque pointer at event +0x08 and selected row at +0x0c, local visible-candidate deque at +0xf8, selected row at +0x10c, anchor fields +0x110/+0x114, screen and active-child clamping through `g_pIMEPane+0xfc`, shared GrafPort text metrics, RectBounds `OffsetRect`, and exact next boundary at 0x004e7b70. Formal C++ remains blank pending coordinated Event/Pane/IME field-name declarations.
```

Placement context: replace the existing row that currently begins:

```text
        - [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList]
```

No insertion of a new row is required.

## Validation Commands For Supervisor

Run after applying accepted doc and coverage edits:

> Executable block R001 was removed from this report and preserved verbatim in [00018B-ime-candidate-show-candidate-list-source-quality-removed.md](00018B-ime-candidate-show-candidate-list-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the optional InputMan/Event support updates are also applied, validate them too:

> Executable block R002 was removed from this report and preserved verbatim in [00018B-ime-candidate-show-candidate-list-source-quality-removed.md](00018B-ime-candidate-show-candidate-list-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

B001 did not run validators on by-* docs because this assignment is report-only and no by-* docs or coverage report were edited.

## Changed Files By B001

Created only this report:

- `tools/leaser/Agents/Agent-B001/research/00018B-ime-candidate-show-candidate-list-source-quality.md`

No by-* docs, generated reports, generated source, IDA database files, source files, or `by-memory/-coverage-report.md` were edited by B001.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00018B-ime-candidate-show-candidate-list-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"00018B"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00018B-ime-candidate-show-candidate-list-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/00018B-ime-candidate-show-candidate-list-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00018B"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
