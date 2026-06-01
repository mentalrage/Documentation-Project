*** UID:000033 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:64 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ConfirmDeleteAlert

## Status

- Confidence: strong for delete-packet behavior; medium for constructor boundary and exact board/article owner.
- Likely source file: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), or a private section of [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md).
- Current recovered file: `source-3/simroot_v2/class_ConfirmDeleteAlert.cpp`
- Companion memory range: [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)

## Role

`ConfirmDeleteAlert` is a localized delete-confirmation alert for board/article bulletin items. It sends opcode `0x3b`, subcommand `0x05` delete packets either for one selected entry or for each selected entry in a multi-delete list.

## Methods

| Range | Method | Notes |
| --- | --- | --- |
| `0x0047e100` | constructor, Wave3-projected | Builds the localized alert with a Cancel button and stores the delete mode. IDA does not currently define this start as a function. |
| `0x0047e160-0x0047e2e3` | `SendDeleteRequest` | IDA confirms this function; it serializes delete packets, updates the active player/delete context, and processes the bulletin queue. |

## Notes

- [UID:000034][ConfirmDeleteMailAlert](by-class/ConfirmDeleteMailAlert.md) has a sibling implementation with the same packet shape but mail-specific context offsets.
- The delete packet shape is feature-owned; do not move this logic into generic socket code just because it calls the packet queue helper.

## Cross-References

- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `64/76`.
  - Summary/evidence: the delete-packet action behavior, companion file ownership, and sibling mail alert relationship are documented; remaining uncertainty is the constructor boundary and exact board/article owner state layout.
