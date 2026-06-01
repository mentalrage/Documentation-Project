*** UID:00003O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DeleteReplyAlert

## Status

- Confidence: strong for reply-list deletion behavior and singleton lifecycle.
- Likely source file: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), or a private section of [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md).
- Current recovered file: `source-3/simroot_v2/class_DeleteReplyAlert.cpp`
- Companion memory range: [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)

## Role

`DeleteReplyAlert` confirms local deletion of bulletin/article reply entries after the server has acknowledged or when a reply-delete action should be reflected in the list. It supports deleting all selected replies or deleting a single reply by id, refreshes the owning dialog, and clears `g_pDeleteReplyAlert` during teardown.

## Methods

| Range | Method | Notes |
| --- | --- | --- |
| `0x0047e2f0-0x0047e34a` | constructor | IDA confirms this function; it initializes `AlertPane`, installs vtables, stores mode/gate bytes, and writes the singleton pointer. |
| `0x0047e350-0x0047e378` | non-deleting destructor | Resets vtables, clears the singleton, and destroys the base alert/dialog state. |
| `0x0047e380-0x0047e385` | singleton getter | Returns `g_pDeleteReplyAlert` (`dword_67ADB8`). |
| `0x0047e390-0x0047e4a5` | `OnConfirm` | Removes selected or single reply rows from the previous/owner dialog and refreshes/populates the session view. |
| [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) | adjustor thunks | Secondary/tertiary vtable thunks to scalar deleting destructor `0x0047eb30`. |
| `0x0047eb30-0x0047eb8e` | scalar deleting destructor | Clears the singleton, destroys base state, and optionally frees memory. |

## Cross-References

- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:000033][ConfirmDeleteAlert](by-class/ConfirmDeleteAlert.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `78/86`.
  - Summary/evidence: constructor, non-deleting destructor, singleton getter, confirm behavior, adjustors, scalar deleting destructor, and bulletin-alert ownership are documented; remaining work is detailed owner-dialog field naming.
