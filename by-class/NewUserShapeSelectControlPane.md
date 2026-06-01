*** UID:00009G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

## Evidence Notes

- IDA confirms all local method starts.
- IDA MCP caller checks on 2026-05-24 show `NewCreateUserDialogPane` constructs this control from its create-user layout at `0x0052c7aa`; no direct `NewUserDialogPane2` caller is currently observed.

## Cross-References

- [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:00008Z][NewCreateUserDialogPane](by-class/NewCreateUserDialogPane.md)
- [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page already described purpose, method boundaries, caller evidence, destructor family, and create-user relationships.
- Changed to: `COMPLETION:74` and `CONFIDENCE:84`.
- Evidence: IDA confirms all local method starts and the page documents direction cycling, timer animation, hit testing, painting, shape selection, and constructor use by `NewCreateUserDialogPane`; remaining gaps are detailed field layout and unconfirmed direct construction from `NewUserDialogPane2`.
