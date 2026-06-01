*** UID:0000LY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# NewUserShapeSelectControlPane

## Status

- Confidence: strong for control behavior; medium for standalone original file.
- Proposed module: `login/NewUserShapeSelectControlPane.cpp`
- Umbrella doc: [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- Current recovered source: `source-3/simroot_v2/class_NewUserShapeSelectControlPane.cpp`
- Evidence basis: `simroot_v2` method anchors plus IDA MCP lookup/caller checks through 2026-05-24.

## File Role

`NewUserShapeSelectControlPane.cpp` should own the newer body-shape preview/selection control used by create-user dialogs. It is adjacent to login/create-user code, not a generic game UI control.

## Boundary Notes

This file may fold into [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md) if final reconstruction favors fewer login/create-user source files. Keep it separate while shape-selector caller reuse and resource ownership are still under review.

It is also adjacent to [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md), the alternate 640x480 create-character dialog. Keep it out of [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md), which is account-registration UI rather than shape-selection UI.

## Proposed Contents

| Range | Current method family | Notes |
| --- | --- | --- |
| `0x004fd520-0x004fd60a` | constructor | Initializes selected shape/gender state and animation/timer-related fields. |
| `0x004fd660-0x004fd6d7` | direction helper | Rotates preview direction. |
| `0x004fd910-0x004fda2c` | timer and mouse handlers | Advances animation and hit-tests shape clicks. |
| `0x004fda30-0x004fdc8e` | paint frame | Draws current body-shape preview frames. |
| `0x004fdc90-0x004fdd32` | point-to-shape selector | Converts local point to selected body shape. |
| `0x00502a70-0x00502aaa` | scalar deleting destructor | Destructor support shared with the surrounding login/create-user control island. |

## Evidence Notes

- IDA MCP confirms `0x004fd520` as a `0xeb`-byte constructor, `0x004fd970` as a `0xbd`-byte mouse handler, and `0x004fda30` as a `0x25f`-byte paint helper.
- IDA MCP caller checks currently show the constructor is directly called only from [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md) at `0x0052c7aa`.
- Because no direct caller from [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md) is currently observed, keep reuse by `NewUserDialogPane2` as a proximity/source-layout hypothesis rather than confirmed caller evidence.

## Cross-References

- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md)
- [UID:00019U][0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs](by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md)
- [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md)
- [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md)
- [UID:0000LX][NewUserMiscDialogPane](by-file/NewUserMiscDialogPane.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `76`, confidence `72`.
- Summary/evidence: the page documents control role, boundary decisions, method-family ranges, constructor caller evidence, and create-user cross-references; confidence remains limited by standalone-file uncertainty and unconfirmed reuse beyond `NewCreateUserDialogPane`.
