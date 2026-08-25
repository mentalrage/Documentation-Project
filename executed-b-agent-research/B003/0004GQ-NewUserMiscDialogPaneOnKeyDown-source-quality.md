** TARGET-REPORT-UID:0004GQ **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# UID0004GQ NewUserMiscDialogPaneOnKeyDown Source-Quality Report

## Finalized Report / Current Recommendation

Implementation callback disposition: UID0004GQ is now a source-ready emitting `NewUserMiscDialogPane::OnKeyDown(KeyEvent *event)` child.

Applied target metadata is `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:00009F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009F`, and blank `EMITTER_POSITION_OPTIONAL`. The target is a real `0x18c` / 396 byte (Verified with int_convert.py) virtual method at `0x004fc5f0-0x004fc77c`, reached only through vtable slot data `0x0061d48c`; the previous blank-emitter coverage blocker has been resolved in the by-* docs.

The implementation callback inserted the formal C++ block from this report into the target, not a body-only sample. Confidence remains capped below final-audit range because exact original spelling for `KeyEvent` fields, the inherited base key-handler name, and navigation-control state methods at virtual slots `+0x4c` / 76 and `+0x50` / 80 are still inferred.

## Supporting Research

Read gates and evidence sources used:

- Assigned goal: `tools/leaser/Agents/Agent-B003/goal.md`.
- Project workflow and structure rules: `ntk-b-agent-workflow`, `by-structure.md` IDA MCP output discipline, by-memory C++/emitter gate, and `tools/int_convert.py`.
- Target and support docs: target UID0004GQ, class UID00009F, file UID0000LX, parent index UID0002Q7, helper core UID0002Q8, `UserShapeSelectControlPane` class UID0000FR, `DialogPane` file UID0000IT, and sibling `NewUserDialogPane2` shape-key/shift children.
- Generated read-only state: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp`.
- Prior report search terms: `0004GQ`, `0x004fc5f0`, `NewUserMiscDialogPaneOnKeyDown`, `NewUserMiscDialogPane::OnKeyDown`, `0x004fd070`, `0x004fd0d0`.
- Matching executed lead opened/used as context: B013 UID0002Q7 split report, which established the parent non-emitting index and named UID0004GQ as an exact child emitter candidate. Current conclusions below are rechecked against live MCP session `eb7ce28b`.

## Target

- UID: `0004GQ`.
- Target path: `by-memory/0x004fc5f0-0x004fc77c.NewUserMiscDialogPaneOnKeyDown.md`.
- Current target title: `0x004fc5f0-0x004fc77c - NewUserMiscDialogPane OnKeyDown`.
- Source family: `NexusTK/login/NewUserMiscDialogPane.cpp` through [UID:0000LX] `by-file/NewUserMiscDialogPane.md`.
- Direct semantic owner: [UID:00009F] `by-class/NewUserMiscDialogPane.md`.
- Parent executable index: [UID:0002Q7] `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md`.

## Current Target State

Current target metadata after the implementation callback:

| Field | Current value |
| --- | --- |
| `COMPLETION` | `89` |
| `CONFIDENCE` | `91` |
| `CANONICAL_OWNER` | `00009F` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `00009F` |
| `EMITTER_POSITION_OPTIONAL` | blank |
| Formal C++ | `bool NewUserMiscDialogPane::OnKeyDown(KeyEvent *event)` inserted |

Before this callback, the page recorded prior MCP session `3a33af0b` with size `0x18c`, vtable data xref `0x0061d48c`, and callees `0x004fd0d0` / `0x004fd070`, but still said emitter and formal C++ remained blank pending child-level source-body review. That stale blocker has been replaced with MCP session `eb7ce28b` evidence, formal C++ in the target, and generated output refreshed by validator command `000000005950`.

## Heuristic / Inference Reanalysis And Validation

The stale blocker was not ownership or reachability. Current evidence shows a normal class virtual method: `xrefs_to 0x004fc5f0` returns only the vtable data entry `0x0061d48c`, which is the expected route for a dialog key handler. No code xref is required for source emission.

The behavior is now recoverable enough for a first-draft source body:

- The handler retrieves six child controls from the inherited dialog control manager: navigation controls `9` and `10`, plus four `UserShapeSelectControlPane` controls `5`, `6`, `7`, and `8`. The decompiler receiver offset `this[87]` is the secondary-view adjusted form of the dialog control manager route; it should not appear in source.
- It normalizes the key byte from event byte `+0x08` and fallback/IME byte `+0x10a` / 266 (Verified with int_convert.py). If the fallback byte is nonzero, the event is consumed.
- For key values `0x80` / `0x81` under event kind `8`, it steps the four shape controls backward using `UserShapeSelectControlPane::StepShapeBackward` at `0x004fd0d0`. The call order is controls `5`, `6`, `7`, `8`; the first result controls the navigation edge behavior.
- For key values `0x82` / `0x83` under event kind `8`, it steps forward using `UserShapeSelectControlPane::StepShapeForward` at `0x004fd070`. The first edge-tested call is control `8`, then controls `5`, `6`, `7`.
- Enter `0x0d` / 13 and Escape `0x1b` / 27 (Verified with int_convert.py) delegate to the inherited dialog key-control handler `0x0049e6e0`; other nonmatching keys are consumed with `true`.

The `UserShapeSelectControlPane` support docs already name and emit the two helper methods with the needed edge semantics: forward increments `+0x10c` / 268 and returns `-1` on `8 -> 9`, while backward decrements `+0x10c` / 268 and returns `-1` on `1 -> 0`. Sibling `NewUserDialogPane2` left/right shape helpers provide a source-shape precedent for moving four shape controls and using dialog-level key-event wrappers, but UID0004GQ remains owned by `NewUserMiscDialogPane`, not the newer `NewUserDialogPane2` class.

## Evidence Standards Used

- Current IDA MCP evidence was mandatory and was gathered against active session `eb7ce28b`.
- MCP calls were exact-address and bounded: `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to` with `limit=40`, `callees`, `get_bytes` with three small regions, `decompile` for one target function, and `int_convert`.
- A schema correction was applied for `get_bytes`: the current tool requires `regions`. The rejected older `addr`/`size` form had no side effects and was rerun with schema-current parameters.
- Numeric values cited as decimal are verified with `tools/int_convert.py`; MCP `int_convert` returned the same values.
- Generated and old reports were treated as leads only. Current MCP `eb7ce28b` and current by-* docs are the proof sources for the final recommendation.

## Evidence Checked

Current MCP session and health:

- `idb_list`: one active worker session `eb7ce28b` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active, not analyzing, worker pid `17696`.
- `server_health(database=eb7ce28b)`: `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.

Function and boundary checks:

- `lookup_funcs`: `0x004fc5f0` is `sub_4FC5F0`, size `0x18c` / 396 (Verified with int_convert.py).
- `lookup_funcs`: `0x004fc5e6` and `0x004fc77c` are not functions; `0x004fc780` is the successor `sub_4FC780`, size `0x267` / 615 (Verified with int_convert.py).
- `lookup_funcs`: helper functions `0x004fd070` size `0x59` / 89 and `0x004fd0d0` size `0x56` / 86 (Verified with int_convert.py), inherited handler `0x0049e6e0` size `0x379`, key-normalization helper at `0x004a8b10` size `0x0a`.
- `get_bytes 0x004fc5e0, size 32`: preceding wrapper tail is followed by ten `0xcc` bytes from `0x004fc5e6` through `0x004fc5ef`, then target prologue starts at `0x004fc5f0`.
- `get_bytes 0x004fc760, size 40`: target tail includes Enter/Escape compares, call to `0x0049e6e0`, epilogue and `retn 4` ending at exclusive end `0x004fc77c`, then four `0xcc` bytes before successor prologue at `0x004fc780`.
- `get_bytes 0x0061d480, size 32`: vtable-region bytes include `0x0061d488 -> 0x004fc780`, `0x0061d48c -> 0x004fc5f0`, `0x0061d490 -> 0x0049ea60`, and `0x0061d494 -> 0x004fc5c0`.

Reachability and body checks:

- `xrefs_to 0x004fc5f0`: exactly one data xref at `0x0061d48c`.
- `xrefs_to 0x004fc77c`: zero xrefs to the exclusive end.
- `xrefs_to 0x004fc780`: one data xref at `0x0061d488`, proving successor `ShowControlHelp` is separate.
- `xrefs_to 0x004fd070`: 18 code refs, including target call sites `0x004fc70f`, `0x004fc71a`, `0x004fc722`, `0x004fc72a`, command-handler refs in `0x004fc010`, and `NewUserDialogPane2` right-shift refs in `0x0052b1d0`.
- `xrefs_to 0x004fd0d0`: 18 code refs, including target call sites `0x004fc6a2`, `0x004fc6ad`, `0x004fc6b5`, `0x004fc6bd`, command-handler refs in `0x004fc010`, and `NewUserDialogPane2` left-shift refs in `0x0052b090`.
- `xrefs_to 0x0049e6e0`: includes target fallback call at `0x004fc76e`, plus accepted same-family/dialog key-event callers.
- `callees 0x004fc5f0`: `0x004a8b10`, `0x004fd0d0`, `0x004fd070`, and `0x0049e6e0`; helper callees for `0x004fd070` and `0x004fd0d0` are empty.
- `decompile 0x004fc5f0`: confirms the six control lookups, event bytes `+0x04`, `+0x08`, `+0x10a`, previous-key branch, next-key branch, edge return checks against `-1`, navigation-control state byte `+0x101` / 257, virtual calls through slots `+0x4c` / 76 and `+0x50` / 80, Enter/Escape fallback, and `true` consumption for other paths.

Pre-callback read-only documentation/generated checks:

- `by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md` already documents and emits `StepShapeForward` and `StepShapeBackward`.
- `by-class/UserShapeSelectControlPane.md` already records method names, field offset `+0x10c`, and caller fanout from UID0004GQ.
- `by-memory/0x0052b890-0x0052b910.NewUserDialogPane2HandleShapeKeyEvent.md`, `0x0052b090-0x0052b1cb`, and `0x0052b1d0-0x0052b30d` provide sibling shape-key and shift source-shape comparisons.
- Generated tracker row listed UID0004GQ at `82/89`, combined `85.5`, reconstructable true, reports `0`.
- Generated memory coverage listed UID0004GQ as `non-emits`.
- Generated `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` was refreshed at validator command `000000005895` and lacked UID0004GQ output before this callback. After implementation, validator command `000000005950` refreshed the file and line 123 contains `bool NewUserMiscDialogPane::OnKeyDown(KeyEvent *event)`.

## Range / Split / Padding / Reclassification Analysis

No split is recommended. The half-open range `0x004fc5f0-0x004fc77c` is exact:

- Predecessor `sub_4FC5C0` ends at `0x004fc5e6`; ten `0xcc` bytes separate it from the target prologue.
- Target starts with a normal frame at `0x004fc5f0`, has size `0x18c` / 396 (Verified with int_convert.py), and ends with `retn 4` immediately before `0x004fc77c`.
- Four `0xcc` bytes at `0x004fc77c-0x004fc77f` separate target from successor `sub_4FC780`.
- Successor `0x004fc780` is the distinct `ShowControlHelp` child and has its own vtable slot at `0x0061d488`.

Reclassification: keep `RECONSTRUCTABLE:TRUE`. This is source-authored dialog method code, not padding, switch data, raw no-route helper code, or parent aggregate-only coverage.

## Function / Child Inventory

| Address/range | Current role | UID/doc status |
| --- | --- | --- |
| `0x004fc5c0-0x004fc5e6` | `NewUserMiscDialogPane` packet wrapper | Sibling UID0004GP; separate source-authored child. |
| `0x004fc5e6-0x004fc5f0` | `0xcc` padding | Not a function; predecessor/target boundary proof. |
| `0x004fc5f0-0x004fc77c` | Target `NewUserMiscDialogPane::OnKeyDown` | UID0004GQ; source-ready after this report. |
| `0x004fc77c-0x004fc780` | `0xcc` padding | Not a function; target/successor boundary proof. |
| `0x004fc780-0x004fc9e7` | `NewUserMiscDialogPane::ShowControlHelp` | Sibling UID0004GR; separate vtable slot `0x0061d488`. |
| `0x004fd070-0x004fd0c9` | `UserShapeSelectControlPane::StepShapeForward` | Helper owned/emitted by UID0002Q8/UID0000FR; already source-ready. |
| `0x004fd0d0-0x004fd126` | `UserShapeSelectControlPane::StepShapeBackward` | Helper owned/emitted by UID0002Q8/UID0000FR; already source-ready. |
| `0x0049e6e0` | inherited `DialogPane` key-control handler | Base dialog dependency, not target ownership. |

## Positive Evidence Summary

- Current live MCP session `eb7ce28b` is active and IDB-backed for the expected NexusTK IDB.
- The target is an IDA-modeled function with exact size `0x18c` / 396 and clean padding on both sides.
- The only inbound xref to the target is vtable data `0x0061d48c`, exactly matching a virtual key handler. The absence of direct code callers is positive virtual-dispatch evidence, not a no-route blocker.
- Adjacent vtable bytes put `ShowControlHelp` at `0x0061d488`, target `OnKeyDown` at `0x0061d48c`, an inherited slot at `0x0061d490`, and packet wrapper `0x004fc5c0` at `0x0061d494`.
- The target body is behaviorally coherent: it handles key-down event kind `8`, four arrow-like key codes, `UserShapeSelectControlPane` shape stepping, navigation-control edge state, Enter/Escape inherited fallback, and default consumption.
- Helper method names and edge behavior are already documented and emitted by UID0002Q8, so the target can call source-facing `StepShapeForward` / `StepShapeBackward` instead of raw IDA labels.
- The owner chain is already above gate: UID0004GQ direct owner UID00009F is `85/88` and emits through UID0000LX; UID0000LX is a valid by-file source root at `NexusTK/login/`.

## Negative Evidence Summary

- There is no evidence that UID0004GQ belongs to `UserShapeSelectControlPane`; that class owns only the helper methods at `0x004fd070` and `0x004fd0d0`. UID0004GQ coordinates dialog controls and fallback key handling.
- There is no evidence that `DialogPane` owns the target. `0x0049e6e0` is a fallback dependency reached only for Enter/Escape.
- There is no evidence that the parent UID0002Q7 should emit this method. UID0002Q7 is already proven as a non-emitting nested index over multiple exact child bodies, raw islands, switch data, and padding.
- There is no evidence that `CreateUserDialogs`, `NewUserDialogPane2`, `CashShopRequest`, `SpecializedButtonPanes`, or the mixed UID00019U aggregate should own the target. Those are umbrella, sibling, dependency, reusable-control, or mixed-index contexts.
- There is no evidence for raw `sub_4FC5F0`, `sub_4FD070`, `sub_4FD0D0`, `_DWORD **`, `_BYTE *`, `this[87]`, or decompiler temporary names as source-facing output.
- The end address `0x004fc77c` has zero xrefs and starts padding, so it must not become a child/function target.
- The source names for navigation-control state methods at virtual slots `+0x4c` and `+0x50` are not symbol-proven; the report recommends conservative source-facing names and keeps confidence capped.

## IDA Rename / Type / Comment Recommendations

Recommended source-facing names/types/comments for documentation and generated source:

- Use `NewUserMiscDialogPane::OnKeyDown(KeyEvent *event)` for UID0004GQ. Evidence: vtable-only slot `0x0061d48c`, sibling key-event pages, Enter/Escape fallback to `0x0049e6e0`, and current target filename/class docs.
- Use `UserShapeSelectControlPane::StepShapeForward()` and `UserShapeSelectControlPane::StepShapeBackward()` for calls to `0x004fd070` and `0x004fd0d0`. Evidence: UID0002Q8 and UID0000FR already document and emit those names with exact edge behavior.
- Use descriptive event fields such as `eventKind`, `translatedKey`, and `imeState` or equivalent source-project names for offsets `+0x04`, `+0x08`, and `+0x10a`; document that exact original member spelling is inferred.
- Use descriptive control names `previousPageControl`, `nextPageControl`, and four `shapeControl` variables for control ids `9`, `10`, and `5-8`. Exact original variable/member names are not recovered.
- Add a target comment/evidence note that `0x0061d48c` is the vtable-only reachability route and that direct-call xref absence does not block emission.

Items intentionally left unchanged or rejected:

- IDA DB renames were not requested or performed. This report/callback recommends documentation/source names only.
- Do not promote raw IDA names `sub_4FC5F0`, `sub_4FD070`, `sub_4FD0D0`, `sub_49E6E0`, `a2`, `v3`, `v4`, `_DWORD **`, `_BYTE *`, or `this[87]` into by-* prose or source output except as quoted evidence aliases.
- Do not rename the inherited base handler conclusively beyond a documented alias. Current support docs use `DialogPane::OnKeyEvent`, `HandleKeyInput`, and similar names for `0x0049e6e0`; source output can use the accepted alias chosen by the class declaration, but this target should preserve that exact spelling as a confidence cap.
- Do not rename the navigation-control virtual slot methods in IDA without a broader control-class slot audit. The formal C++ uses `IsSelected`, `Select`, and `ClearSelection` as source-facing descriptive names, not proven original symbols.

IDA DB edits are not requested and should be treated as unsafe for this callback unless a later supervisor task explicitly authorizes a broader type/rename pass.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | ---: | --- | --- | --- | --- |
| C-0004GQ-001 | Target is exact function `0x004fc5f0-0x004fc77c`, size `0x18c` / 396. | 96 | MCP `lookup_funcs`, bytes, int_convert.py. | Target metadata/evidence. | incorporate | applied: target `## Current MCP Evidence` and `## Function, Range, And Boundary Proof` record MCP session `eb7ce28b`, exact range, size `0x18c` / 396, and int conversion. |
| C-0004GQ-002 | Target has vtable-only reachability via `0x0061d48c`; no direct caller is expected. | 94 | MCP `xrefs_to`, vtable bytes. | Target evidence; class/file method notes. | incorporate | applied: target `## Vtable Reachability`, class method row/evidence notes, file Proposed Contents/boundary notes, and parent row now cite slot `0x0061d48c` as vtable-only reachability. |
| C-0004GQ-003 | Predecessor and successor boundaries are padded and separate; no split/merge needed. | 95 | MCP `lookup_funcs`, `get_bytes`, zero xrefs to `0x004fc77c`. | Target range/padding evidence. | incorporate | applied: target range/boundary proof records predecessor padding, successor padding before `0x004fc780`, and zero end xrefs to `0x004fc77c`; class/file/parent summaries preserve exact range. |
| C-0004GQ-004 | Body fetches controls ids `9`, `10`, `5`, `6`, `7`, `8` through inherited dialog control manager. | 90 | MCP decompile and offset conversion. | Target behavior details. | incorporate | applied: target behavior and formal C++ block use IDs `9`, `10`, `5`, `6`, `7`, `8`; class/file/parent evidence repeats the control-id detail. |
| C-0004GQ-005 | Previous-key branch uses `StepShapeBackward` on controls `5-8`, with edge behavior from the first call. | 92 | MCP decompile, xrefs to `0x004fd0d0`, UID0002Q8 helper docs. | Target behavior and C++ block. | incorporate | applied: target formal C++ and behavior notes call `StepShapeBackward` in `5,6,7,8` order and preserve the first-result edge behavior; class/file/parent notes include the same order. |
| C-0004GQ-006 | Next-key branch uses `StepShapeForward` on control `8` first, then `5-7`. | 92 | MCP decompile, xrefs to `0x004fd070`, UID0002Q8 helper docs. | Target behavior and C++ block. | incorporate | applied: target formal C++ and behavior notes call `StepShapeForward` in `8,5,6,7` order; class/file/parent notes include the same order. |
| C-0004GQ-007 | Enter/Escape delegate to inherited `0x0049e6e0`; other nonmatching paths consume the event. | 91 | MCP decompile and xrefs_to `0x0049e6e0`. | Target behavior and C++ block. | incorporate | applied: target formal C++ delegates Enter/Escape to `DialogPane::OnKeyEvent(event)` and records inherited callee `0x0049e6e0`; support docs repeat Enter/Escape fallback and retain base-handler alias confidence cap. |
| C-0004GQ-008 | Direct owner remains UID00009F and source route is UID00009F -> UID0000LX. | 93 | Current class/file docs, vtable slot, source-family context. | Target metadata/source placement. | incorporate | applied: target keeps `CANONICAL_OWNER:00009F`, sets `EMITTER_UIDS:00009F`, class route emits through UID00009F, and file route records output into `NexusTK/login/NewUserMiscDialogPane.cpp`. |
| C-0004GQ-009 | Set target to `89/91`, keep reconstructable true, set emitter to UID00009F. | 90 | Evidence resolves emitter/C++ blocker while preserving name caps. | Target metadata. | incorporate | applied: target metadata is `COMPLETION:89`, `CONFIDENCE:91`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009F`, optional position blank; validator command `000000005942` passed. |
| C-0004GQ-010 | Formal first-draft C++ should be inserted into target block. | 88 | Combined score gate, confirmed emitter route, complete body behavior. | Target formal `RECONSTRUCTION_CPP CODE`. | incorporate | applied: target formal `RECONSTRUCTION_CPP CODE` block now contains `bool NewUserMiscDialogPane::OnKeyDown(KeyEvent *event)` with the accepted source-like body; generated output includes the same method after validator refresh command `000000005950`. |
| C-0004GQ-011 | Support helper docs UID0002Q8/UID0000FR already contain same-or-greater `StepShapeForward/Backward` detail. | 91 | Current by-memory and by-class helper docs. | Report checklist/support ledger. | already-present | already-present: reviewed `by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md`, `by-class/UserShapeSelectControlPane.md`, and `by-file/UserCreateAppearanceControls.md`; they already document/emitted `StepShapeForward` and `StepShapeBackward` with edge behavior and UID0004GQ caller fanout, so no helper edits were made. |
| C-0004GQ-012 | Reject ownership by helper class, DialogPane, NewUserDialogPane2, CreateUserDialogs, CashShopRequest, specialized controls, parent UID0002Q7, and mixed UID00019U. | 91 | Call/dependency direction, owner docs, parent split report, MCP xrefs. | Target/support negative evidence. | reject-invalid | applied: target negative evidence and class/file/parent support notes preserve dependency-only helper/DialogPane/sibling/module relationships, reject parent aggregate emission, and retain confidence caps for exact source-facing names. |

## Ranked Ownership Analysis

| Rank | Candidate | Evidence for | Evidence against | Decision |
| ---: | --- | --- | --- | --- |
| 1 | [UID:00009F] `NewUserMiscDialogPane` | Vtable slot belongs to NewUserMisc dialog region; target coordinates dialog controls, sibling command/packet/help methods, and inherited fallback. | Exact original method/parameter spelling is inferred. | Direct canonical owner; recommended emitter UID. |
| 2 | [UID:0000LX] `NewUserMiscDialogPane.cpp` | Valid source file root and current generated route for singleton/class marker. | By-structure says class method should use class owner/emitter route, not bypass direct class owner. | Final source file route only. |
| 3 | [UID:0000FR] `UserShapeSelectControlPane` | Target calls its step helpers four times per arrow branch. | Helpers are callees reused by command handler and NewUserDialogPane2; target coordinates a dialog-level key event. | Dependency only. |
| 4 | [UID:00003T]/[UID:0000IT] `DialogPane` | Target delegates Enter/Escape to inherited `0x0049e6e0`. | Only a fallback call; body-specific control coordination belongs to derived dialog. | Dependency only. |
| 5 | [UID:00009E] `NewUserDialogPane2` | Sibling shape-key and shift helpers use similar source idiom. | Different class, range, vtable, and control ids. | Sibling comparison only. |
| 6 | [UID:0002Q7] parent memory index | Contains the target range and child inventory. | Parent is reviewed non-emitting nested index; child pages carry bodies. | Keep parent non-emitting. |
| 7 | `CreateUserDialogs`, `CashShopRequest`, specialized controls, UID00019U aggregate | Source-family, packet dependency, reusable controls, or broad mixed neighborhood. | No direct ownership evidence for this method. | Rejected owners/emitters. |

## Source Placement

Recommended placement:

- `CANONICAL_OWNER:00009F` remains correct because the function is a `NewUserMiscDialogPane` method.
- `EMITTER_UIDS:00009F` should be set so the method emits through the class route into [UID:0000LX] `NewUserMiscDialogPane.cpp`.
- `EMITTER_POSITION_OPTIONAL` should remain blank. Existing method ordering under the class/file route is sufficient; no accepted by-structure rule requires a new explicit position for this child.
- Generated C++ now appears under `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` after scoped validators: header line `validator-command-id: 000000005950`, refreshed at `2026-07-04T00:37:39-04:00`, and the file contains `bool NewUserMiscDialogPane::OnKeyDown(KeyEvent *event)` after the constructor output. This was validator-generated output; B003 did not manually edit generated files.

## First-Draft C++ Recommendation

Insert this exact formal block in the target if the report is accepted. It is source-like and intentionally avoids raw IDA names; exact original field/member names remain a confidence cap.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool NewUserMiscDialogPane::OnKeyDown(KeyEvent *event)
{
    const unsigned char kPreviousShapeKey0 = 0x80;
    const unsigned char kPreviousShapeKey1 = 0x81;
    const unsigned char kNextShapeKey0 = 0x82;
    const unsigned char kNextShapeKey1 = 0x83;
    const unsigned char kEscapeKey = 0x1b;

    ControlPane *previousPageControl = m_controlManager->GetControl(9);
    ControlPane *nextPageControl = m_controlManager->GetControl(10);
    UserShapeSelectControlPane *shapeControl0 =
        static_cast<UserShapeSelectControlPane *>(m_controlManager->GetControl(5));
    UserShapeSelectControlPane *shapeControl1 =
        static_cast<UserShapeSelectControlPane *>(m_controlManager->GetControl(6));
    UserShapeSelectControlPane *shapeControl2 =
        static_cast<UserShapeSelectControlPane *>(m_controlManager->GetControl(7));
    UserShapeSelectControlPane *shapeControl3 =
        static_cast<UserShapeSelectControlPane *>(m_controlManager->GetControl(8));

    const unsigned char key = event->translatedKey;
    if (event->imeState != 0) {
        return true;
    }

    if (event->eventKind == kEventKeyDown &&
        (key == kPreviousShapeKey0 || key == kPreviousShapeKey1))
    {
        if (previousPageControl->IsSelected()) {
            const int edgeResult = shapeControl0->StepShapeBackward();
            shapeControl1->StepShapeBackward();
            shapeControl2->StepShapeBackward();
            shapeControl3->StepShapeBackward();

            if (edgeResult == -1) {
                previousPageControl->ClearSelection();
            } else if (!nextPageControl->IsSelected()) {
                nextPageControl->Select();
            }
        }

        return true;
    }

    if (event->eventKind == kEventKeyDown &&
        (key == kNextShapeKey0 || key == kNextShapeKey1))
    {
        if (!nextPageControl->IsSelected()) {
            return true;
        }

        const int edgeResult = shapeControl3->StepShapeForward();
        shapeControl0->StepShapeForward();
        shapeControl1->StepShapeForward();
        shapeControl2->StepShapeForward();

        if (edgeResult == -1) {
            nextPageControl->ClearSelection();
        } else if (!previousPageControl->IsSelected()) {
            previousPageControl->Select();
        }

        return true;
    }

    if (key == '\r' || key == kEscapeKey) {
        return DialogPane::OnKeyEvent(event);
    }

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Confidence caps on this draft:

- `KeyEvent`, `eventKind`, `translatedKey`, and `imeState` are source-facing field/type names inferred from existing event docs and bytes `+0x04`, `+0x08`, `+0x10a`.
- `m_controlManager` is the source-facing inherited control-manager route for the adjusted secondary receiver; the raw decompiler form `this[87]` must not be used.
- `IsSelected`, `Select`, and `ClearSelection` are conservative names for the navigation-control state byte at `+0x101` and virtual slots `+0x4c` / `+0x50`. A later control-class slot audit may refine exact spellings without changing the target behavior.
- The inherited base handler name may need to match the final `DialogPane` declaration alias (`OnKeyEvent`, `HandleKeyEvent`, or `HandleKeyInput`). Do not lower the target below source-ready solely because this alias is not final-audit proven.

## Final Recommendation

Implementation callback is complete for UID0004GQ. B003 applied target metadata, emitter routing, formal C++ insertion, and report-level evidence detail to UID0004GQ, then updated stale support docs:

- Class/file/parent index now say UID0004GQ is source-ready key-down method output through UID00009F/UID0000LX.
- Helper docs for `StepShapeForward` / `StepShapeBackward` were reviewed and left already-present.
- Rejected alternatives and confidence caps were preserved so the generated method is not mistaken for final original-symbol proof.
- B003 did not run `execute_report`, lifecycle/archive commands, generated/manual edits, coverage edits, validator-state edits, or supervisor-ledger edits.

## Recommended Target Doc Changes

For `by-memory/0x004fc5f0-0x004fc77c.NewUserMiscDialogPaneOnKeyDown.md`:

- Set `COMPLETION:89`.
- Set `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:00009F`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Set `EMITTER_UIDS:00009F`.
- Keep `EMITTER_POSITION_OPTIONAL` blank.
- Insert the formal C++ block from `## First-Draft C++ Recommendation`.
- Replace the pre-callback blank-emitter/source-body-review blocker wording with current source-ready behavior.
- Add current MCP `eb7ce28b` evidence: session health, exact range, size, bytes/padding, vtable-only xref, zero end xrefs, callees, helper fanout, event offsets, control ids, step-order details, Enter/Escape inherited fallback, and generated-output non-emits state before implementation.
- Preserve negative evidence rejecting raw names, helper-class ownership, DialogPane ownership, sibling NewUserDialogPane2 ownership, parent aggregate emission, and padding/no-code treatment.
- Preserve confidence caps for exact event/member names, inherited handler alias, and navigation-control virtual slot names.

## Recommended Support Doc Changes

Support docs to update if the accepted detail is absent or stale:

- `by-class/NewUserMiscDialogPane.md`: update the `OnKeyDown` method row and evidence notes from generic "keyboard/help path" to source-ready key-down handler detail: vtable slot `0x0061d48c`, exact range/size, shape-control stepper calls, navigation-control edge behavior, Enter/Escape inherited fallback, and remaining name caps. Score can remain `85/88`; if raised, justify only from UID0004GQ now having formal source output.
- `by-file/NewUserMiscDialogPane.md`: update Proposed Contents/source-output notes so UID0004GQ emits `NewUserMiscDialogPane::OnKeyDown(KeyEvent *event)` through UID00009F into `NexusTK/login/NewUserMiscDialogPane.cpp`. Keep file-level standalone-vs-umbrella and raw-island blockers.
- `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md`: update the UID0004GQ child row and evidence notes to say this exact child is source-ready/emitting while the parent remains `RECONSTRUCTABLE:FALSE` and non-emitting.
- `by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md`: expected already-present. It already documents and emits `StepShapeForward` / `StepShapeBackward`; only add a cross-reference from the caller set if the supervisor wants the current `eb7ce28b` call-site addresses repeated.
- `by-class/UserShapeSelectControlPane.md` and `by-file/UserCreateAppearanceControls.md`: expected already-present for helper ownership/source route; do not edit unless current wording contradicts this report.
- No NewUserMisc vtable-data page was found for `0x0061d48c`; do not create one during this implementation unless the supervisor explicitly expands scope.

## Score And Metadata Recommendation

| Field | Before | Recommended | Rationale |
| --- | --- | --- | --- |
| `COMPLETION` | `82` | `89` | Current MCP resolves range, padding, reachability, body behavior, helper ownership, source route, and formal C++ readiness. Not higher because event/control member spellings are inferred. |
| `CONFIDENCE` | `89` | `91` | Evidence is strong for behavior and owner/emitter route. Capped by exact original `KeyEvent`/navigation-control method names and inherited handler alias. |
| `CANONICAL_OWNER` | `00009F` | `00009F` | Direct semantic owner remains `NewUserMiscDialogPane`. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Source-authored virtual method. |
| `EMITTER_UIDS` | blank | `00009F` | The class route surfaces to by-file UID0000LX and clears the emitter gate. |
| `EMITTER_POSITION_OPTIONAL` | blank | blank | No explicit ordering requirement found. |

## Open Questions With Attempted Resolution

| Question | Attempted resolution | Current impact |
| --- | --- | --- |
| Exact inherited method name: `OnKeyDown`, `OnKeyEvent`, `HandleKeyEvent`, or `HandleKeyInput`? | Checked target filename/class docs, `CreateUserDialogPane` key-event page, `NewUserDialogPane2` shape-key page, and `DialogPane` file aliases. | Use target-facing `NewUserMiscDialogPane::OnKeyDown`; base fallback alias remains a confidence cap, not a blocker. |
| Exact `KeyEvent` field names for bytes `+0x04`, `+0x08`, `+0x10a`? | Checked event/key-handler docs and MCP decompile. Existing project source uses `KeyEvent` style names, but original field spelling is not recovered. | Draft uses descriptive `eventKind`, `translatedKey`, `imeState`; cap confidence at 91. |
| Exact navigation-control methods for slots `+0x4c` and `+0x50`? | Searched support docs for slot names and checked decompile. Broader control-class slot audit is outside scope. | Draft uses `Select` / `ClearSelection`; preserve as inferred and do not request IDA DB renames. |
| Could UID0004GQ belong to `UserShapeSelectControlPane` because it calls its steppers? | Checked helper docs and xref fanout. Helpers are shared methods called by command handler and `NewUserDialogPane2` siblings. | Rejected. UID0004GQ remains dialog-level coordinator. |
| Should the parent UID0002Q7 emit this method instead? | Checked executed B013 report and current parent doc. Parent is reviewed non-emitting nested index. | Rejected. Exact child emits. |

## Validator Results

Scoped validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` for every edited by-* file. All exited `0` with `ok: 1`; no warnings or errors were reported.

| File | Command | command_id | command_timestamp | Exit | ok | Relevant side effects / generated refresh |
| --- | --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x004fc5f0-0x004fc77c.NewUserMiscDialogPaneOnKeyDown.md` | `python .\tools\validator.py --mode file --file by-memory/0x004fc5f0-0x004fc77c.NewUserMiscDialogPaneOnKeyDown.md --apply --queue-timeout 240` | `000000005942` | `2026-07-04T00:31:12-04:00` | 0 | 1 | `generated_refresh: deferred`; `autogen_registry_update: 3`, `completion_update: 1`, `confidence_update: 1`, `projected_stats_update: 1`, `reference_index_add: 8`, `stats_incremental_noop: 1`. |
| `by-class/NewUserMiscDialogPane.md` | `python .\tools\validator.py --mode file --file by-class/NewUserMiscDialogPane.md --apply --queue-timeout 240` | `000000005949` | `2026-07-04T00:37:34-04:00` | 0 | 1 | `generated_refresh: deferred`; `autogen_registry_update: 1`, `projected_stats_update: 1`, `stats_row_update: 4`. |
| `by-file/NewUserMiscDialogPane.md` | `python .\tools\validator.py --mode file --file by-file/NewUserMiscDialogPane.md --apply --queue-timeout 240` | `000000005950` | `2026-07-04T00:37:39-04:00` | 0 | 1 | `generated_refresh: deferred`; `projected_stats_update: 1`, `stats_row_update: 3`. Generated file `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` refreshed from this command. |
| `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md` | `python .\tools\validator.py --mode file --file by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md --apply --queue-timeout 240` | `000000005951` | `2026-07-04T00:37:49-04:00` | 0 | 1 | `generated_refresh: deferred`; `projected_stats_update: 1`, `stats_incremental_noop: 1`. |

Generated freshness observation:

- `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` header now shows `validator-command-id: 000000005950`, `validator-refreshed-at: 2026-07-04T00:37:39-04:00`, and `validator-refresh-source: deferred-generated-refresh`.
- Grep proof after validation: line 2 has `validator-command-id: 000000005950`, line 9 names `UID0004GL and UID0004GQ`, and line 123 contains `bool NewUserMiscDialogPane::OnKeyDown(KeyEvent *event)`.
- B003 did not manually edit generated files.

## Changed Files

Implementation callback changed these by-* docs and this report:

- `by-memory/0x004fc5f0-0x004fc77c.NewUserMiscDialogPaneOnKeyDown.md`
- `by-class/NewUserMiscDialogPane.md`
- `by-file/NewUserMiscDialogPane.md`
- `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md`
- `tools/leaser/Agents/Agent-B003/research/0004GQ-NewUserMiscDialogPaneOnKeyDown-source-quality.md`

Generated refresh side effect, not manually edited by B003:

- `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` refreshed by validator command `000000005950` and now contains UID0004GQ output.

No coverage reports, lifecycle/archive files, supervisor ledgers, manual generated files, or report lifecycle files were edited, and no `execute_report` or lifecycle/archive command was run.

## Lease Usage

- Target lease: B003 leased `by-memory/0x004fc5f0-0x004fc77c.NewUserMiscDialogPaneOnKeyDown.md` immediately before target edit/validator batch and released it immediately after validator command `000000005942`; lease release output was `Success`.
- Support lease batch: B003 leased `by-class/NewUserMiscDialogPane.md`, `by-file/NewUserMiscDialogPane.md`, and `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md` immediately before support edits/validators and released all three immediately after validator command `000000005951`; lease release output was `Success` for each file.
- Helper docs were review-only/already-present and were not leased or edited.

## Implementation Tracking Checklist

Implementation callback status:

- [x] Target `by-memory/0x004fc5f0-0x004fc77c.NewUserMiscDialogPaneOnKeyDown.md`: set metadata to `COMPLETION:89`, `CONFIDENCE:91`, kept owner/reconstructable, set `EMITTER_UIDS:00009F`, and kept optional emitter position blank.
- [x] Target formal C++: inserted the exact formal block from `## First-Draft C++ Recommendation`, not a body-only sample.
- [x] Target evidence: added current MCP session `eb7ce28b`, active IDB/session facts, exact function/range/size, bytes/padding, vtable slot `0x0061d48c`, zero end xrefs, callees, helper call orders, event offset/key facts, and generated pre-implementation non-emits state.
- [x] Target negative evidence: preserved rejection of raw `sub_`/decompiler names, padding/no-code treatment, helper-class ownership, DialogPane ownership, NewUserDialogPane2 ownership, CreateUserDialogs umbrella ownership, CashShopRequest/specialized-control ownership, parent aggregate emission, and mixed UID00019U ownership.
- [x] Target confidence caps: preserved exact original spelling caveats for `KeyEvent` parameter/member names, base handler alias, `m_controlManager`, and navigation-control state methods at slots `+0x4c`/`+0x50`.
- [x] `by-class/NewUserMiscDialogPane.md`: updated the method row/evidence notes for source-ready `OnKeyDown` with vtable slot, exact range/size, stepper calls, navigation edge behavior, Enter/Escape fallback, and name caps.
- [x] `by-file/NewUserMiscDialogPane.md`: updated source-output/Proposed Contents notes so UID0004GQ emits through UID00009F into `NexusTK/login/NewUserMiscDialogPane.cpp`.
- [x] `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md`: updated child inventory/evidence to source-ready exact child while preserving parent `RECONSTRUCTABLE:FALSE`, blank emitter, and blank aggregate C++.
- [x] `by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md`, `by-class/UserShapeSelectControlPane.md`, and `by-file/UserCreateAppearanceControls.md`: reviewed helper details and marked already-present for `StepShapeForward/Backward`; no helper edits were needed.
- [x] Ran scoped file validators from `source-3/project-documentation` for every changed by-* file and recorded command, command_id, command_timestamp, exit code, ok count, warnings/errors, and generated refresh state.
- [x] Updated this report's ledger/checklist after callback with `applied` or `already-present` proof for every accepted claim.
- [x] Did not run `execute_report`, dry-run/probing lifecycle commands, registry lifecycle commands, archive commands, manual generated-file edits, coverage edits, validator-state edits, or manual report moves.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000005988","destination_path":"executed-b-agent-research/B003/0004GQ-NewUserMiscDialogPaneOnKeyDown-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0004GQ-NewUserMiscDialogPaneOnKeyDown-source-quality.md","timestamp":"2026-07-04T00:53:41-04:00","uid":"0004GQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
