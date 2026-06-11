*** UID:0002W3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pDeleteReplyAlert

## Status

- Address: `0x0067adb8`
- Storage page: [UID:0002W4][0x0067adb8-0x0067adbc.g_pDeleteReplyAlert](by-memory/0x0067adb8-0x0067adbc.g_pDeleteReplyAlert.md)
- Type hypothesis: `DeleteReplyAlert *`
- Owner: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- Confidence: strong for address, class owner, and lifecycle; medium for final source split between shared alert wrappers and board-dialog-private helpers.

## Evidence

The slot stores the active [UID:00003O][DeleteReplyAlert](by-class/DeleteReplyAlert.md) instance. Existing IDA-backed docs report six refs to `dword_67ADB8`: constructor/destructor/getter/action-family code around `0x0047e2f0`, `0x0047e350`, `0x0047e380`, and `0x0047eb30` write, clear, read, or return the singleton.

[UID:00003O][DeleteReplyAlert](by-class/DeleteReplyAlert.md) identifies `0x0047e380-0x0047e385` as the singleton getter and documents the board/article reply-list delete behavior. [UID:0002AI][0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons](by-memory/0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons.md) records the original adjacent pair and the split rationale.

## Assignment Gate

This global is attached to [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), which is `85/86`. The relationship is direct because the file page owns the shared reply/delete alert wrapper bucket and already owns the `DeleteReplyAlert` class family. C++ stays blank because the page is below the final-source threshold.

## Cross-References

- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:00003O][DeleteReplyAlert](by-class/DeleteReplyAlert.md)
- [UID:0002AI][0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons](by-memory/0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons.md)

## Changes

- 2026-06-07 A008 Batch 037 split:
  - Created as the canonical global page for the `0x0067adb8` board/article reply-delete alert singleton split from the mixed adjacent pair.
  - Summary/evidence: existing IDA-backed docs provide six refs, getter identity, class ownership, and shared alert-wrapper parent placement.
