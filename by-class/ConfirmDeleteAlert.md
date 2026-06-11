*** UID:000033 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:40 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ConfirmDeleteAlert

## Status

- Confidence: strong for delete-packet behavior, confirmed action ownership, and raw constructor body; medium for exact board/article owner and field names.
- Likely source file: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), or a private section of [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md).
- Current recovered file: `source-3/simroot_v2/class_ConfirmDeleteAlert.cpp`
- Companion memory range: [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)

## Role

`ConfirmDeleteAlert` is a localized delete-confirmation alert for board/article bulletin items. It sends opcode `0x3b`, subcommand `0x05` delete packets either for one selected entry or for each selected entry in a multi-delete list.

## Methods

| Range | Method | Notes |
| --- | --- | --- |
| [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md) | raw constructor | Builds the localized alert with a Cancel button, stores the delete mode at `this + 0x270`, and installs the three `ConfirmDeleteAlert` vtables. IDA does not define this start as a function, but restarted IDA MCP confirms the exact raw body and padding. |
| [UID:0002SE][0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest](by-memory/0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest.md) | `SendDeleteRequest` | IDA confirms this function; it serializes delete packets, updates the active player/delete context, and processes the bulletin queue. |

## Evidence Map

| Evidence | Impact |
| --- | --- |
| [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md) | Exact raw constructor child records the `0x0047e100-0x0047e158` body, three vtable stores, `this + 0x270` delete-mode field, and padding boundaries despite no IDA function object. |
| [UID:0002SE][0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest](by-memory/0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest.md) | Exact action child page records opcode `0x3b`, subcommand `0x05`, single/multi-delete behavior, and prior IDA MCP function-start evidence. |
| [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) | Places this class in the shared bulletin/mail alert wrapper family; the file parent is now `82/86`, so the existing parent attachment passes the 80/80 gate. |
| [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md) | Provides vtable family evidence for the board/article alert class family. |

## Reconstruction Notes

- Reconstructable: true as an owning class shell plus confirmed action child.
- Parent: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), position `40`, until a more exact original file split is proven.
- C++: intentionally blank. The constructor and action are now documented, but helper/resource parameter names and board/article context field names remain unresolved.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 80 | The class now has exact child pages for both the raw constructor and the delete-request action, plus source-owner, vtable-family, packet-shape, field-role, and sibling-mail evidence. It remains capped at 80 because board/article context field names, helper/resource names, and final source split are still unresolved. |
| Confidence | 84 | Confidence stays strong because the constructor and action are backed by written IDA MCP boundary/raw-byte evidence and the parent file now passes the attachment gate. It is not raised because the constructor is still a raw non-function body in IDA and final names/layout are not source-quality. |

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
- 2026-06-02:
  - Before: class had only aggregate range references for the confirmed action.
  - After: scored as `70/80`, marked reconstructable, and attached under [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).
  - Summary/evidence: exact action child [UID:0002SE][0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest](by-memory/0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest.md) now captures packet behavior and prior IDA evidence; C++ remains blank pending field/layout recovery.
- 2026-06-03:
  - Before: constructor ownership remained a Wave3-projected `0x0047e100` start and the class score stayed limited by missing constructor evidence.
  - After: scored as `76/84`; method/evidence tables now link exact raw constructor child [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md).
  - Summary/evidence: restarted IDA MCP confirms the raw constructor body through `retn 8` at `0x0047e155`, successor padding `0x0047e158-0x0047e160`, preceding padding `0x0047e0ff-0x0047e100`, no IDA function object, vtable stores, and the `this + 0x270` delete-mode byte; C++ remains blank pending final helper/resource names and context layout.
- 2026-06-07 A004:
  - Before: page was attached to [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) but remained at `76/84`, below the completion side of the 80/80 attachment gate.
  - After: completion raised to `80`; confidence remains `84`; parent stays [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) at position `40`.
  - Summary/evidence: exact constructor child [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md), exact action child [UID:0002SE][0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest](by-memory/0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest.md), refreshed `BulletinReplyAlerts` parent score `82/86`, and vtable-family evidence support the gate-aligned score. C++ remains blank because field/helper names and final source split are not near-final.
