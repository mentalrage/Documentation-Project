*** UID:0000LW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# NewUserDialogPane2

## Status

- Confidence: strong for behavior; medium for final standalone source split.
- Proposed module: `login/NewUserDialogPane2.cpp`, or folded into [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md).
- Umbrella doc: [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- Current recovered source: `source-3/simroot_v2/class_NewUserDialogPane2.cpp`
- Main class: [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md)

## File Role

`NewUserDialogPane2.cpp` is the alternate 640x480 create-character dialog candidate. It uses `DLGNEW02.EPD` and `NPAL3.PAL`, displays several shape previews, handles gender/totem/body-shape/direction selection, and submits the create-user request.

This is not the same source role as [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md). `NewUserDialogPane` is the older account-registration dialog; `NewUserDialogPane2` belongs to the character creation UI family with [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md) and [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md).

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `NewUserDialogPane2` constructor | `0x0052a540` | Builds the alternate 640x480 create-character dialog. |
| shape/gender/totem selectors | `0x0052b090-0x0052b5c0` | Rotates and applies preview/selection state. |
| command/event handlers | `0x0052b760-0x0052b940` | Dispatches dialog commands and notifications. |
| `SubmitCreateUser` | `0x0052b9f0` | Validates and sends the create-user request. |
| destructor family | `0x0052f767`, `0x0052f772`, `0x0052f8e0` | Adjustor and scalar deleting destructor logic. |

## Boundary Notes

- Wave3 currently names the `0x0052a540` row like a destructor, but the generated body and IDA-confirmed behavior are constructor-like.
- Keep the shape-preview control implementation in [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md) unless final source-size review folds it into this file.
- Keep account registration/password-only behavior in [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md) and [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md).

## Cross-References

- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md)
- [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md)
- [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md)
- [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `74`, confidence `72`.
- Summary/evidence: the page documents the alternate create-character role, major method families, boundary distinctions, and cross-references; confidence is limited by final standalone-source split and the generated constructor/destructor naming issue.
