*** UID:0000LP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# NewCreateUserDialogPane

## Status

- Confidence: strong for the newer create-user dialog role, exact method/vtable evidence, and login/create-user placement; capped below final-source quality by unresolved direct constructor reachability and field/layout names.
- Proposed module: `login/NewCreateUserDialogPane.cpp`
- Umbrella doc: [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- Evidence basis: live IDA MCP function, xref, vtable, singleton, command-dispatch, and boundary checks through 2026-06-04.

## File Role

`NewCreateUserDialogPane.cpp` is the newer/high-resolution create-user dialog source candidate. It uses the newer create-user resource family, drives gender/body/style controls, and shares validation/submission behavior with the broader create-user flow.

## Boundary Notes

Keep [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md) adjacent. It may remain a separate source file if the final tree preserves the reusable shape-preview control.

Keep [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md) as the alternate 640x480 create-character variant until final migration decides whether the two new create-user variants were one source file or adjacent files. Keep [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md) out of this module; that class is account registration, not character creation.

## Proposed Contents

| Range | Current method family | Notes |
| --- | --- | --- |
| `0x0052c360-0x0052cd49` | constructor | Builds the newer full-screen create-user dialog, writes the `0x0069b4a8` singleton, installs the three `NewCreateUserDialogPane` vtable slots, and instantiates `NewUserShapeSelectControlPane`. |
| `0x0052cef0-0x0052d0ff` | gender/totem helpers | Updates gender, totem, and male/female selector state. |
| `0x0052d210-0x0052d33b` | command/event/notify handlers | Dispatches dialog commands and simple event/notify behavior. |
| `0x0052d3e0-0x0052d5ab` | submit path | Validates create-user fields and sends the create-character request. |
| `0x0052f720`, `0x0052f751`, `0x0052f75c`, `0x0052f870-0x0052f8db` | destructor support | Singleton clear helper, two adjustor thunks, and scalar deleting destructor for this variant. |

## Evidence Notes

- 2026-06-04 live IDA MCP enumerates the exact core starts at `0x0052c360`, `0x0052cef0`, `0x0052cf80`, `0x0052d050`, `0x0052d060`, `0x0052d0b0`, `0x0052d100`, `0x0052d1e0`, `0x0052d210`, `0x0052d2f0`, `0x0052d300`, `0x0052d330`, `0x0052d3e0`, `0x0052d5b0`, `0x0052d7c0`, and `0x0052d9a0`.
- Live IDA MCP confirms constructor-side writes to singleton `0x0069b4a8` at `0x0052c3b8`/`0x0052c3bf` and vtable slots `0x0061fda0`, `0x0061fe00`, and `0x0061fe30` at `0x0052c3d3`, `0x0052c3d9`, and `0x0052c3e3`.
- Live IDA MCP caller checks still show no direct callers for `0x0052c360`. Treat this as a retained/newer dialog variant or indirect dispatch candidate until launcher reachability is reviewed.
- Live IDA MCP confirms [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md) constructor `0x004fd520` is called from `0x0052c7aa` inside this constructor.
- The `0x0052d210` command dispatcher uses a 16-case jump table: case 17 calls the submit helper `0x0052d3e0`, cases 4/5 call gender selectors `0x0052d060`/`0x0052d0b0`, and cases 9-14 call the totem/style selector helpers `0x0052cef0`/`0x0052cf80`.
- The submit path at `0x0052d3e0` calls packet helper `0x0052d5b0` at `0x0052d5a2`; reply handling at `0x0052d9a0` calls the shape-control payload builder `0x0052d7c0` at `0x0052daf6`.

## Score Rationale

The projected path remains `NexusTK/login/` because [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md), the proposed source tree, and [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md) place the newer create-user variants in the login/create-user source family. [UID:0002QS][0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore](by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md) and [UID:0002SJ][0x0061fda0-0x0061fe30.NewCreateUserDialogPaneVtableData](by-memory/0x0061fda0-0x0061fe30.NewCreateUserDialogPaneVtableData.md) now attach directly to this file page. Confidence remains capped because no direct constructor caller is currently observed and final source field names are not audited.

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
- 2026-06-04 live IDA evidence and child attachment update:
  - What existed before: completion/confidence were `76/80`; the page still cited stale recovered-source provenance and the exact memory children were attached to the create-user umbrella.
  - Changed to: completion `82`, confidence `86`; stale provenance was replaced with live IDA MCP evidence; exact core/vtable children now attach to this file page.
  - Summary/evidence: live IDA confirms the constructor, selector helpers, command dispatcher, submit/packet/reply flow, singleton writes, three vtable slots, destructor support, and boundary bytes. The remaining cap is the absent direct constructor caller and unresolved final field/layout naming.
