*** UID:0000IJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# CreateUserDialogPane

## Status

- Confidence: strong for old create-user dialog behavior, lifecycle ownership, singleton/vtable evidence, and login placement; medium-high for exact split from helper controls.
- Proposed module: `login/CreateUserDialogPane.cpp`
- Umbrella doc: [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- Current recovered source: `source-3/simroot_v2/class_CreateUserDialogPane.cpp`
- Evidence basis: `simroot_v2` method anchors plus IDA MCP lookup/caller/callee/xref/decompile/disassembly checks through 2026-06-03, with 2026-06-07 A001 live singleton-slot recheck for the file-local `CreateUserDialogPane` global.

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

Exact child coverage is now split between [UID:0002QT][0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore.md), which owns the old dialog constructor, selector handlers, submit path, packet encoder, payload builder, and reply handler, and [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md), which owns singleton clear helpers, adjustor thunks, helper destructors, and the three create-user scalar deleting destructors.

## Evidence Notes

- IDA MCP confirms `0x0052dd30` as a `0x9bb`-byte constructor and `0x0052ed80` as a `0x1cc`-byte submit helper.
- IDA MCP caller checks show constructor calls from `0x004f7a82` and [UID:00019P][0x004f8fa0-0x004f9055.OpenCreateUserDialog](by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md) at `0x004f8ff8`.
- Active generated output omits some methods listed by class metadata (`SetHairColorIndex`, `SetFaceColorIndex`, `OnKeyEvent`, and `OnDialogShow`), so use the class/memory docs during migration rather than the active `.cpp` alone.
- [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) is attached to this file page and links the old-dialog core, destructor/thunk island, [UID:0002SI][0x0061fe3c-0x0061fecc.CreateUserDialogPaneVtableData](by-memory/0x0061fe3c-0x0061fecc.CreateUserDialogPaneVtableData.md), and [UID:0002B3][0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot](by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md).
- 2026-06-03 IDA MCP recheck confirms the old-dialog method island used by this source page: constructor `0x0052dd30`, body/gender helpers `0x0052e770`, `0x0052e850`, and `0x0052e8c0`, color setters `0x0052e930` and `0x0052e950`, command dispatcher `0x0052ea80`, submit validator `0x0052ed80`, packet/payload helpers `0x0052ef50`, `0x0052f160`, response handler `0x0052f390`, singleton clear `0x0052f710`, adjustor thunks `0x0052f73b`/`0x0052f746`, and scalar deleting destructor `0x0052f800`.
- 2026-06-03 IDA MCP xrefs confirm `0x0061fe3c` vtable references from constructor/destructor code and `0x0069b890` singleton references from the constructor, cleanup helper, and scalar deleting destructor. This ties the class, vtable data, and singleton slot to the same source module.
- 2026-06-07 A001 live IDA recheck confirms `0x0069b890-0x0069b894` is a four-byte `dword_69B890` singleton slot initialized as `ff ff ff ff`, with five direct refs at `0x0052dd87`, `0x0052dd8e`, `0x0052e71a`, `0x0052f710`, and `0x0052f82d` inside constructor, singleton-clear, and scalar deleting destructor code.
- 2026-06-03 IDA MCP decompilation confirms the omitted color setters are real source-level methods called by the older hair/face color-list controls, and confirms the submit validator reads the name/password/confirmation controls, enforces the password digit rule, compares confirmation with `wcscmp`, reports failures through alert panes, and calls `0x0052ef50` on success.
- [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md) remains the practical split candidate for older shape/hair/face/preview/color-list controls, but its xref evidence keeps those controls tightly coupled to this constructor and its color setter callbacks.

## Score Rationale

The page moves to `85/85` because the exact old-dialog method child, lifecycle/thunk island, class parent, vtable block, singleton slot, constructor callers, appearance-control callbacks, and 2026-06-07 live singleton xrefs are now linked from the file-level source candidate. The remaining cap is source-shape risk: the active generated `.cpp` omits several real methods, the helper controls may remain split into [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md), and final field/helper names still need reconstruction-grade review.

## Cross-References

- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md)
- [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md)
- [UID:0002QT][0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore.md)
- [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md)
- [UID:0002SI][0x0061fe3c-0x0061fecc.CreateUserDialogPaneVtableData](by-memory/0x0061fe3c-0x0061fecc.CreateUserDialogPaneVtableData.md)
- [UID:0002B3][0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot](by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md)
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
- 2026-06-07 A010 class/core synchronization:
  - What existed before: the page was scored `82/80` and captured the old-dialog method island, but did not yet link the exact old-dialog child page, lifecycle/thunk island, vtable data page, singleton-slot page, or class-parent synchronization.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:84`, exact child coverage links, class/vtable/singleton evidence notes, and a score rationale describing why helper-control split risk still caps the page.
  - Summary/evidence: synchronized file-level documentation with existing [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md), [UID:0002QT][0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore.md), and [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md) evidence; no new live IDA facts were introduced.
- 2026-06-07 A001 Batch 045 parent-gate refresh:
  - What existed before: the page was scored `84/84`, just below the corrected child-and-parent assignment gate for the exact singleton-slot memory page.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:85`, and added the live `0x0069b890` singleton bytes/xrefs/function-family evidence.
  - Summary/evidence: current IDA confirms the singleton is file-local `CreateUserDialogPane` lifecycle state, so this page now clears the direct-parent gate for [UID:0002B3][0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot](by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md).
