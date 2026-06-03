*** UID:0000IJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# CreateUserDialogPane

## Status

- Confidence: strong for old create-user dialog behavior; medium for exact split from helper controls.
- Proposed module: `login/CreateUserDialogPane.cpp`
- Umbrella doc: [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- Current recovered source: `source-3/simroot_v2/class_CreateUserDialogPane.cpp`
- Evidence basis: `simroot_v2` method anchors plus IDA MCP lookup/caller/callee/xref/decompile/disassembly checks through 2026-06-03.

## File Role

`CreateUserDialogPane.cpp` should own the older `DLGNEW3` create-user dialog: username/password fields, gender/body selection, hair/face controls, preview pane, validation, and create-user packet submission.

The older hair/face/color/preview controls may either live here or in [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md) depending on final source size.

Keep [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md) separate despite the similar name; it is the account-registration/password dialog. The create-character variants are [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md) and [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md).

## Proposed Contents

| Range | Current method family | Notes |
| --- | --- | --- |
| `0x0052dd30-0x0052e6ea` | constructor | Builds `DLGNEW3`, text edits, gender/body controls, older hair/face selectors, color lists, and preview pane. |
| `0x0052e770-0x0052e957` | selection helpers | Updates body, gender, hair-color, and face-color state. |
| `0x0052ea80-0x0052ed05` | command/key/show handlers | Handles dialog commands, listed key handling, and dialog show behavior. Some methods are not currently emitted in active generated source. |
| `0x0052ed80-0x0052ef4b` | submit path | Validates create-user fields and sends the create-character request. |
| `0x0052f800-0x0052f86b` | scalar deleting destructor | Tears down dialog state and clears singleton-style state. |

## Evidence Notes

- IDA MCP confirms `0x0052dd30` as a `0x9bb`-byte constructor and `0x0052ed80` as a `0x1cc`-byte submit helper.
- IDA MCP caller checks show constructor calls from `0x004f7a82` and [UID:00019P][0x004f8fa0-0x004f9055.OpenCreateUserDialog](by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md) at `0x004f8ff8`.
- Active generated output omits some methods listed by class metadata (`SetHairColorIndex`, `SetFaceColorIndex`, `OnKeyEvent`, and `OnDialogShow`), so use the class/memory docs during migration rather than the active `.cpp` alone.
- 2026-06-03 IDA MCP recheck confirms the old-dialog method island used by this source page: constructor `0x0052dd30`, body/gender helpers `0x0052e770`, `0x0052e850`, and `0x0052e8c0`, color setters `0x0052e930` and `0x0052e950`, command dispatcher `0x0052ea80`, submit validator `0x0052ed80`, packet/payload helpers `0x0052ef50`, `0x0052f160`, response handler `0x0052f390`, singleton clear `0x0052f710`, adjustor thunks `0x0052f73b`/`0x0052f746`, and scalar deleting destructor `0x0052f800`.
- 2026-06-03 IDA MCP xrefs confirm `0x0061fe3c` vtable references from constructor/destructor code and `0x0069b890` singleton references from the constructor, cleanup helper, and scalar deleting destructor. This ties the class, vtable data, and singleton slot to the same source module.
- 2026-06-03 IDA MCP decompilation confirms the omitted color setters are real source-level methods called by the older hair/face color-list controls, and confirms the submit validator reads the name/password/confirmation controls, enforces the password digit rule, compares confirmation with `wcscmp`, reports failures through alert panes, and calls `0x0052ef50` on success.

## Cross-References

- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md)
- [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md)
- [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md)
- [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:76`.
  - Summary/evidence: old create-user dialog role, method-family ranges, construction callers, active generated-output omissions, umbrella relationships, and helper-control split caveats are documented; confidence is capped by the unresolved split from appearance controls and newer dialog variants.
- 2026-06-03 MCP verification and projected path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the page was scored `80/76`, leaving it in projected-path cleanup and below the 80-confidence parent-attachment threshold.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/"`, `COMPLETION:82`, and `CONFIDENCE:80`.
  - Summary/evidence: fresh IDA MCP lookup, caller/callee, xref, decompile, and disassembly checks confirmed the method island, constructor callers, vtable/singleton ownership, omitted color setters, submit validation, packet handoff, and destructor thunk shape. Confidence remains capped at 80 because exact source split from appearance controls and final field/helper naming still need reconstruction-grade review.
