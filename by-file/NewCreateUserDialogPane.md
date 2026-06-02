*** UID:0000LP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# NewCreateUserDialogPane

## Status

- Confidence: strong for newer create-user dialog behavior and login/create-user placement; medium-high for exact split and live reachability.
- Proposed module: `login/NewCreateUserDialogPane.cpp`
- Umbrella doc: [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- Current recovered source: `source-3/simroot_v2/class_NewCreateUserDialogPane.cpp`
- Evidence basis: `simroot_v2` method anchors plus IDA MCP lookup/caller checks through 2026-05-24.

## File Role

`NewCreateUserDialogPane.cpp` is the newer/high-resolution create-user dialog source candidate. It uses the newer create-user resource family, drives gender/body/style controls, and shares validation/submission behavior with the broader create-user flow.

## Boundary Notes

Keep [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md) adjacent. It may remain a separate source file if the final tree preserves the reusable shape-preview control.

Keep [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md) as the alternate 640x480 create-character variant until final migration decides whether the two new create-user variants were one source file or adjacent files. Keep [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md) out of this module; that class is account registration, not character creation.

## Proposed Contents

| Range | Current method family | Notes |
| --- | --- | --- |
| `0x0052c360-0x0052cd48` | constructor | Builds the newer full-screen create-user dialog and instantiates `NewUserShapeSelectControlPane`. |
| `0x0052cef0-0x0052d0ff` | gender/totem helpers | Updates gender, totem, and male/female selector state. |
| `0x0052d210-0x0052d33b` | command/event/notify handlers | Dispatches dialog commands and simple event/notify behavior. |
| `0x0052d3e0-0x0052d5ab` | submit path | Validates create-user fields and sends the create-character request. |
| `0x0052f751-0x0052f875` | destructor support | Adjustor thunk and scalar deleting destructor. |

## Evidence Notes

- IDA MCP confirms `0x0052c360` as a `0x9e9`-byte constructor and `0x0052d3e0` as a `0x1cc`-byte submit helper.
- IDA MCP caller checks currently show no direct callers for `0x0052c360`. Treat this as a retained/newer dialog variant or indirect dispatch candidate until launcher reachability is reviewed.
- IDA MCP caller checks show [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md) constructor `0x004fd520` is called from `0x0052c7aa` inside this constructor.

## Score Rationale

The projected path is now `NexusTK/login/` because [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md), the proposed source tree, and [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md) already place the newer create-user variants in the login/create-user source family. [UID:0002QS][0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore](by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md) provides exact constructor, selector, submit, packet, singleton, vtable, and boundary evidence. Confidence remains capped because no direct constructor caller is currently observed.

## Cross-References

- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:00008Z][NewCreateUserDialogPane](by-class/NewCreateUserDialogPane.md)
- [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md)
- [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md)
- [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `72`, confidence `68`.
- Summary/evidence: the page has source-role, boundary, method-family, and shape-control caller evidence, but it remains lighter than nearby pages and has unresolved live reachability plus split questions.
- 2026-06-02 path and confidence update:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the page was scored `72/68`.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/"`, completion `76`, and confidence `80`.
  - Summary/evidence: the create-user umbrella, proposed source tree, aggregate memory page, and exact child memory page all place this retained/newer create-character dialog in the login/create-user source family.
