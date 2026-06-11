*** UID:00003O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:50 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DeleteReplyAlert

## Status

- Confidence: strong for reply-list deletion behavior and singleton lifecycle.
- Likely source file: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), or a private section of [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md).
- Current recovered file: `source-3/simroot_v2/class_DeleteReplyAlert.cpp`
- Companion memory range: [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
- Parent attachment: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), position `50`, now that the file parent is `82/86` and this class is at the 80/80 child-side gate.

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

## Evidence Map

| Evidence | Impact |
| --- | --- |
| [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md) | Records the modeled constructor/destructor/getter/action starts, the destructor wrapper strip, and the source-neighborhood relationship to the other bulletin/mail alert classes. |
| [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) | Provides the shared source-owner bucket for reply/delete alert wrappers; now `82/86`, so the parent gate passes. |
| [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md) | Anchors the board/article alert vtable family and supports keeping this class with the bulletin alert wrappers instead of generic dialog/session code. |
| [UID:000033][ConfirmDeleteAlert](by-class/ConfirmDeleteAlert.md) | Sibling delete-confirm class now documents exact constructor/action children and the shared board/article delete-alert context. |

## Autogen And Score Rationale

- Reconstructable: true for the source-owned alert wrapper class.
- Parent: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), position `50`.
- Code: intentionally blank. The class has modeled method starts and clear behavior, but there are no exact per-method by-memory children yet and final owner-dialog/list field names are unresolved.
- Completion is raised to `80` because the page records the complete modeled method surface, singleton lifecycle, confirm behavior, scalar destructor, companion range, source-owner bucket, vtable-family evidence, sibling relationship, and parent gate status.
- Confidence remains `86` because the function starts and singleton behavior are IDA-backed in existing docs, but final source split and owner-dialog field naming still need a focused pass before higher confidence or C++ output.

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
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains blank because the class completion score is below the 80% attachment gate.
  - Evidence: live IDA MCP confirms modeled starts at `0x0047e2f0`, `0x0047e350`, `0x0047e380`, `0x0047e390`, and `0x0047eb30`, with constructor callers from board/reply paths at `0x0047442f`, `0x004748c5`, `0x004769c7`, and `0x00476add`.
- 2026-06-07 A004:
  - Before: page was reconstructable but unattached at `78/86` because it missed the completion side of the parent gate.
  - After: completion raised to `80`, attached to [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) at position `50`; confidence remains `86`.
  - Summary/evidence: existing IDA-backed method starts, singleton lifecycle, confirm/delete behavior, [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md), refreshed `BulletinReplyAlerts` parent score `82/86`, and sibling [UID:000033][ConfirmDeleteAlert](by-class/ConfirmDeleteAlert.md) support attachment. C++ remains blank because exact child pages and final owner-dialog field names remain open.
