*** UID:00009G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewUserShapeSelectControlPane

## Status

- Confidence: strong
- Likely source file: [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md), under the [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) umbrella
- Address range: [UID:00019U][0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs](by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_NewUserShapeSelectControlPane.cpp`
- Parent attachment: attached to [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md) because the file page, exact core memory page, and this class page now meet the 80/80 attachment gate.
- 2026-06-07 note: local IDA MCP was unavailable earlier in this session, so this refresh consolidates existing by-file/by-memory evidence rather than adding new live disassembly.

## Class Purpose

`NewUserShapeSelectControlPane` is the animated body-shape preview/selection control used by newer create-user dialogs. It owns direction cycling, timer-based animation, hit testing, frame painting, and point-to-shape selection.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `NewUserShapeSelectControlPane` | `0x004fd520` | Constructs control, seeds selected shape/gender state, schedules animation timer. |
| `AdvanceDirection` | `0x004fd660` | Rotates preview direction. |
| `OnTimerEvent` | `0x004fd910` | Advances animation frame and schedules next timer. |
| `OnMouseEvent` | `0x004fd970` | Hit-tests shape area and delegates shape selection. |
| `OnPaintFrame` | `0x004fda30` | Draws current shape preview frames. |
| `SelectShapeAtPoint` | `0x004fdc90` | Converts mouse position to selected shape. |
| Destructor family | `0x0050253a`, `0x00502545`, `0x00502a70` | Adjustor and scalar deleting destructor logic. |

## State And Layout Anchors

| Evidence | Class-level meaning |
| --- | --- |
| [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md) records constructor initialization through selected shape/page/direction/animation fields and a `200` ms timer registration. | Confirms this class owns the animated body-shape selector state rather than merely delegating to `NewCreateUserDialogPane`. |
| Direction helper `0x004fd660` advances field `+0x110` modulo four. | Supports the preview-facing direction field, while the final source field name remains provisional. |
| Tail chunks `0x004fd680` and `0x004fd6a0` write mode values `2` and `6` at `+0x10c` and redraw through vtable slot `+0x20`. | Records the create-user owner interaction and the need to preserve tail-chunk caveats before final C++ is emitted. |
| `SelectShapeAtPoint` at `0x004fdc90-0x004fdd33` converts local mouse coordinates into page/shape selection state and dispatches redraw. | Confirms point-to-shape conversion belongs on this class, not on the surrounding dialog. |
| The exact core range ends at `0x004fdd33`, followed by padding before [UID:0002QA][0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore](by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md). | Keeps the class boundary separate from adjacent password-dialog code in the mixed aggregate. |

## Reconstruction State

- Reconstructable: true, because this is NexusTK-owned create-user selector behavior and class declarations must rebuild its vtables/methods.
- Parent: [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md), with [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) as the umbrella family.
- Final C++ remains blank. The class role, parent, method starts, and state model are strong, but field names, tail-chunk ownership, destructor-family details, and standalone-vs-folded source shape are still below the 95/95 final-source gate.

## Evidence Notes

- IDA confirms all local method starts.
- IDA MCP caller checks on 2026-05-24 show `NewCreateUserDialogPane` constructs this control from its create-user layout at `0x0052c7aa`; no direct `NewUserDialogPane2` caller is currently observed.
- Exact core memory coverage records the constructor at `0x004fd520-0x004fd60b`, descriptor helper, direction helper, timer handler, mouse handler, paint/render helper, and point-to-shape helper as one class-method cluster.
- The file page documents `NexusTK/login/` placement and keeps the possible fold into [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md) open until source-layout evidence is final.

## Score Rationale

Completion is raised to `80` because the page now records parent attachment, state/layout anchors, exact core memory-page relationships, reconstruction state, and final-source blockers in addition to the method inventory. Confidence remains `84`: existing IDA-backed docs support method starts and the NewCreateUserDialogPane caller, but current-session MCP was unavailable and direct reuse by `NewUserDialogPane2` remains unconfirmed.

## Cross-References

- [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:00008Z][NewCreateUserDialogPane](by-class/NewCreateUserDialogPane.md)
- [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md)

## Changes

- 2026-06-07 (A010): Raised completion from `74` to `80` and attached the class to [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md).
  - Evidence added: exact core range/state model from [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md), login/create-user parent rationale, boundary before ChangePasswordDialogPane, reconstruction-state notes, and final-C++ blockers.
  - Limitation: IDA MCP was unavailable earlier in this session, so this pass consolidates existing by-* evidence.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed shape-control constructor/direction/timer/mouse/paint/select/thunk/deleting-destructor starts at `0x004fd520`, `0x004fd660`, `0x004fd910`, `0x004fd970`, `0x004fda30`, `0x004fdc90`, `0x0050253a`, `0x00502545`, and `0x00502a70`. Left `AUTOGEN_PARENT_UID` blank because this class is below the 80 completion attachment gate even though [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md) is the likely source-module parent.
- Before: completion/confidence metadata were `0/0` even though the page already described purpose, method boundaries, caller evidence, destructor family, and create-user relationships.
- Changed to: `COMPLETION:74` and `CONFIDENCE:84`.
- Evidence: IDA confirms all local method starts and the page documents direction cycling, timer animation, hit testing, painting, shape selection, and constructor use by `NewCreateUserDialogPane`; remaining gaps are detailed field layout and unconfirmed direct construction from `NewUserDialogPane2`.
