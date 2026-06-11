*** UID:0000AV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000P0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ProfilePane

## Status

- Confidence: strong for behavior; strong that this is the `UserLookPane` child pane, not the profile-edit dialog.
- Likely source file: [UID:0000P0][UserLookPane](by-file/UserLookPane.md)
- Address range: [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md)
- Current recovered file: `source-3/simroot_v2/class_ProfilePane.cpp`

## Class Purpose

`ProfilePane` is a minimal read-only child pane used by `UserLookPane` for profile and biography text views. It should not be confused with `ProfileDialog`, which owns the profile editing/storage UI.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `AlwaysFalse` | `0x005a23c0-0x005a23c5` | Virtual gate that always returns false. |
| `AlwaysFalse2` | `0x005a23d0-0x005a23d5` | Second virtual gate that always returns false. |

## Evidence Notes

- Wave3 reports `ProfilePane` grade `97.5`, two active methods, and no missing refs.
- IDA xrefs to the two functions are vtable slots at `0x0062ee8c` and `0x0062ee6c`.
- IDA decompilation of `UserLookPane::UserLookPane` allocates a `372`-byte pane, calls the common pane constructor, installs `ProfilePane` vtables, and stores it at `UserLookPane::this[63]`.
- `UserLookPane::ShowProfileView` and `UserLookPane::ShowBioView` both lay out this child pane through the stored pointer.

## Cross-References

- [UID:0000FP][UserLookPane](by-class/UserLookPane.md)
- [UID:0000P0][UserLookPane](by-file/UserLookPane.md)
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)
- [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md)
- [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md)

## Changes

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and assigned parent `0000P0`.
  - Before: reconstruction autogen classification and parent were blank despite documented vtable-backed virtual gate methods in the remote user-look/profile pane family.
  - After: classified as reconstructable source attached to [UID:0000P0][UserLookPane](by-file/UserLookPane.md).
  - Evidence: live IDA MCP `lookup_funcs` confirms modeled starts at `0x005a23c0` and `0x005a23d0`; existing [UID:0000P0][UserLookPane](by-file/UserLookPane.md) evidence keeps `ProfilePane` as a read-only child pane rather than the editable `ProfileDialog`. The class score is `82/88` and parent file score is `88/80`, satisfying the 80/80 attach gate.

- 2026-05-30: Changed completion/confidence from `0/0` to `82/88`.
  - Before: The page was unevaluated even though it described the pane's narrow purpose and two confirmed virtual gates.
  - After: Scored as high confidence and good completion for a small child pane, with no claim that it is the editable profile dialog.
  - Evidence: Existing evidence notes tie both functions to vtable slots and to `UserLookPane` construction/show-profile/show-bio usage.
