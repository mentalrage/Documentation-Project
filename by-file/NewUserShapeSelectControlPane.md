*** UID:0000LY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# NewUserShapeSelectControlPane

## Status

- Confidence: strong for control behavior, state layout, and login/create-user placement; medium-high for standalone original file versus folding into `NewCreateUserDialogPane.cpp`.
- Proposed module: `login/NewUserShapeSelectControlPane.cpp`
- Umbrella doc: [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- Current recovered source: `source-3/simroot_v2/class_NewUserShapeSelectControlPane.cpp`
- Evidence basis: `simroot_v2` method anchors plus IDA MCP lookup/caller checks through 2026-05-24; current-session MCP was unavailable, so this pass only synchronizes already-written class/core/file evidence.

## File Role

`NewUserShapeSelectControlPane.cpp` should own the newer body-shape preview/selection control used by create-user dialogs. It is adjacent to login/create-user code, not a generic game UI control.

## Boundary Notes

This file may fold into [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md) if final reconstruction favors fewer login/create-user source files. Keep it separate while shape-selector caller reuse and resource ownership are still under review.

It is also adjacent to [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md), the alternate 640x480 create-character dialog. Keep it out of [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md), which is account-registration UI rather than shape-selection UI.

The exact core child ends at `0x004fdd33`, with padding before the adjacent [UID:0002QA][0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore](by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md) region. Keep the `0x00502a70-0x00502aaa` scalar deleting destructor support associated with this file, but treat final destructor ownership as follow-up until the surrounding login/control destructor island is audited together.

## Proposed Contents

| Range | Current method family | Notes |
| --- | --- | --- |
| [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md) | constructor, direction, timer, mouse, paint, and point-to-shape helpers | Exact child page covering the newer shape selector's constructor, descriptor/direction helpers, tail chunks, timer/mouse handlers, paint path, and point-to-shape conversion. |
| `0x00502a70-0x00502aaa` | scalar deleting destructor | Destructor support shared with the surrounding login/create-user control island. |

## Evidence Notes

- IDA MCP confirms `0x004fd520` as a `0xeb`-byte constructor, `0x004fd970` as a `0xbd`-byte mouse handler, and `0x004fda30` as a `0x25f`-byte paint helper.
- IDA MCP caller checks currently show the constructor is directly called only from [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md) at `0x0052c7aa`.
- [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md) is now attached to this file page as its class parent after the file/class/core set reached the 80/80 reconstruction gate.
- [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md) records constructor writes for vtables, selected shape/page/direction/animation fields, and a 200 ms timer registration.
- The same exact core page records the `+0x110` direction field advancing modulo four, tail chunks at `0x004fd680` and `0x004fd6a0` writing mode values through `+0x10c`, and `0x004fdc90-0x004fdd33` converting mouse coordinates into the selected shape/page state before redraw.
- Because no direct caller from [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md) is currently observed, keep reuse by `NewUserDialogPane2` as a proximity/source-layout hypothesis rather than confirmed caller evidence.
- Current-session IDA MCP tool listing failed with `Unable to connect to the remote server`; no new live IDA facts were added during the 2026-06-07 A010 pass.

## Score Rationale

The projected path is now `NexusTK/login/` because [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md), [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md), and the IDA-backed [UID:00019U][0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs](by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md) aggregate all place this control in the login/create-user source family. Confidence rises because [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md) and [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md) are both at 84 confidence and record exact method starts, constructor caller evidence, field-offset behavior, and the control's timer/mouse/paint/select responsibilities. The score remains below high confidence because direct reuse outside `NewCreateUserDialogPane` is still unconfirmed and the final file split may fold this small control into a larger create-user source file.

## Cross-References

- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md)
- [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md)
- [UID:00019U][0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs](by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md)
- [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md)
- [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md)
- [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md)
- [UID:0000LX][NewUserMiscDialogPane](by-file/NewUserMiscDialogPane.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `76`, confidence `72`.
- Summary/evidence: the page documents control role, boundary decisions, method-family ranges, constructor caller evidence, and create-user cross-references; confidence remains limited by standalone-file uncertainty and unconfirmed reuse beyond `NewCreateUserDialogPane`.
- 2026-06-03 path and confidence update:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, the page was scored `76/72`, and the proposed contents used unlinked method-family rows.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/"`, score `80/82`, and proposed contents now point to exact child page [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md).
  - Summary/evidence: the create-user umbrella, proposed source tree, class page, and exact memory page all support login/create-user placement; final standalone-vs-folded source split remains open.
- 2026-06-07 A010 evidence-sync update:
  - What existed before: the page was scored `80/82` and documented method-family/caller evidence, but did not yet summarize the class-parent attachment, exact state fields, timer interval, tail-chunk mode writes, or the current MCP limitation.
  - Changed to: completion `82`, confidence `84`, stronger evidence notes for [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md) and [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md), and explicit boundary text for the `0x004fdd33` core end before [UID:0002QA][0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore](by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md).
  - Summary/evidence: synchronized the by-file page with existing class/core documentation only; current-session IDA MCP was unavailable, so no new live IDA facts were introduced.
