*** UID:000034 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
/*
[UID:000034] No standalone class-level C++ is emitted from this class page.
ConfirmDeleteMailAlert owns exact children including [UID:0002SF][0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest](by-memory/0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest.md) for the delete-request action. The class page remains an index/support page and must not duplicate child method bodies.
*/
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ConfirmDeleteMailAlert

## Status

- Confidence: strong for raw constructor bytes, delete-packet behavior, vtable placement, and direct parent routing; medium-high for exact mail context field names and final source split.
- Likely source file: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), or a private section of [UID:0000KZ][MailDialogs](by-file/MailDialogs.md).
- Current recovered file: `source-3/simroot_v2/class_ConfirmDeleteMailAlert.cpp`
- Companion memory range: [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
- Current evidence status: live IDA MCP action checks were refreshed on 2026-06-03; raw constructor, construction mirrors, vtable refs, and padding boundaries were refreshed on 2026-06-13.

## Role

`ConfirmDeleteMailAlert` is the mail-specific delete confirmation alert. Its constructor builds the localized `Delete`/`Cancel` alert shell and stores a delete-mode byte at `this + 0x270`; its confirmed action serializes one or more opcode `0x3b`, subcommand `0x05` mail delete packets using ids from the active mail context.

## Methods

| Range | Method | Notes |
| --- | --- | --- |
| [UID:0003MZ][0x0047e4b0-0x0047e508.ConfirmDeleteMailAlertRawConstructor](by-memory/0x0047e4b0-0x0047e508.ConfirmDeleteMailAlertRawConstructor.md) | raw constructor | Builds the localized `Delete`/`Cancel` alert, stores the caller-supplied delete-mode byte at `this + 0x270`, and installs the three `ConfirmDeleteMailAlert` vtables. IDA does not define this start as a function, but live IDA MCP confirms the exact raw bytes, padding, and vtable stores. |
| [UID:0002SF][0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest](by-memory/0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest.md) | `SendDeleteRequest` | IDA confirms this function; it serializes single or multi-delete packets and updates the active player mail context before processing the bulletin queue. |

## Construction And Mode Evidence

| Site | Evidence | Mode byte |
| --- | --- | --- |
| [UID:0003MZ][0x0047e4b0-0x0047e508.ConfirmDeleteMailAlertRawConstructor](by-memory/0x0047e4b0-0x0047e508.ConfirmDeleteMailAlertRawConstructor.md) | Raw constructor pushes the `Cancel` and `Delete` resources, the caller context, and `0x40`; calls `sub_4F0350` then `sub_49FEB0`; stores `[ebp+0x0c]` to `this + 0x270`; and writes vtables `0x006146c8`, `0x00614730`, and `0x00614760`. | Caller-supplied. |
| `0x0047a060` mail-list command case | Modeled path allocates `0x274` bytes, uses the same helper/resource/vtable sequence, and sets `this + 0x270` on the new alert. | `1` |
| `0x0047a280` compact mail-list helper | Same allocation/helper/vtable sequence as the raw constructor. | `1` |
| `0x0047c500` mail-read/dialog command case | Same allocation/helper/vtable sequence, then creates the single-delete confirmation variant. | `0` |
| `0x0047c950` compact mail-read helper | Same allocation/helper/vtable sequence as the `0x0047c500` path. | `0` |

## Evidence Map

| Evidence | Impact |
| --- | --- |
| [UID:0003MZ][0x0047e4b0-0x0047e508.ConfirmDeleteMailAlertRawConstructor](by-memory/0x0047e4b0-0x0047e508.ConfirmDeleteMailAlertRawConstructor.md) | Exact raw constructor child records the body bytes, predecessor/successor padding, no-function/no-start-xref status, `Delete`/`Cancel` operands, `this + 0x270` mode-byte store, vtable stores, and four modeled construction mirrors with mode-byte variants. |
| [UID:0002SF][0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest](by-memory/0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest.md) | Exact action child page records opcode `0x3b`, subcommand `0x05`, the `0x0047e510-0x0047e694` IDA boundary, packet/layout offsets, vtable slot `0x00614724`, and live IDA MCP decompile evidence. |
| [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) | Places this class in the shared bulletin/mail alert wrapper family and now clears the strict `85/85` parent gate for both constructor and action children. |
| [UID:000322][MailAlertCompanionVtables](by-type/by-vtable/MailAlertCompanionVtables.md) | Provides exact owner-specific vtable evidence for the mail alert companion classes, including `ConfirmDeleteMailAlert` bases `0x006146c8`, `0x00614730`, and `0x00614760`. |
| [UID:00007L][MailListDialog](by-class/MailListDialog.md) | B007 2026-06-20 MailListDialog reanalysis records list delete action paths, including helper pocket `0x0047a280`, that allocate/construct this alert with mode byte `1` for selected-mail delete confirmation. This is caller/context evidence only; implementation ownership remains [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md). |

## Reconstruction Notes

- Reconstructable: true as an owning class shell plus confirmed action child.
- Parent: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), position `60`, until a more exact original file split is proven.
- C++: intentionally blank. The constructor and action are now documented, but source-quality helper names, the base/context storage at `this + 0x26c`, and final mail-context field names remain unresolved.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The class now has exact constructor/action children, raw constructor bytes and padding evidence, decoded `Delete`/`Cancel` resources through sibling evidence, construction-mode callsite variants, vtable-family placement, packet-shape documentation, source-owner rationale, and explicit C++/open-question limits. |
| Confidence | 89 | Confidence is strong because live IDA MCP verifies the raw constructor byte body, exact action child, vtable refs, four modeled construction mirrors, and parent file gate. It remains below final-audit confidence because the raw constructor is still not an IDA function object and helper/context field names remain provisional. |

## Notes

- This is a mail-context sibling of [UID:000033][ConfirmDeleteAlert](by-class/ConfirmDeleteAlert.md). Keep it with mail/dialog alert code, not generic packet transport.

## Cross-References

- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md)
- [UID:000322][MailAlertCompanionVtables](by-type/by-vtable/MailAlertCompanionVtables.md)
- [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
- [UID:00007K][MailDialog](by-class/MailDialog.md)
- [UID:00007L][MailListDialog](by-class/MailListDialog.md)

## B006 2026-06-29 Implementation Callback

- Accepted C04: this class page clears the empty marker with a formal no-code/index comment plus `[[CHILDREN]]` insertion point, while [UID:0002SF][0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest](by-memory/0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest.md) owns the source-authored mail delete-request action body through this class route.
- Current source-placement caveat remains: `BulletinReplyAlerts.cpp` is the active source bucket, with a private `MailDialogs` split retained only as historical placement uncertainty.

## Changes

- 2026-06-20 supervisor-worker Rule 26 incorporation of B007 `00007L-MailListDialog-class-source-quality.md`: added MailListDialog selected-delete/list-mode construction context, including helper `0x0047a280` and mode byte `1`, while preserving current shared alert ownership.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `64/76`.
  - Summary/evidence: the mail delete-packet action behavior, companion memory range, file ownership candidates, and mail-dialog relationship are documented; remaining uncertainty is the constructor boundary and exact mail context layout.
- 2026-06-02:
  - Before: class had only aggregate range references for the confirmed action.
  - After: scored as `70/80`, marked reconstructable, and attached under [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).
  - Summary/evidence: exact action child [UID:0002SF][0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest](by-memory/0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest.md) now captures packet behavior and prior IDA evidence; C++ remains blank pending field/layout recovery.
- 2026-06-03:
  - Before: class score still relied on prior aggregate/action-start evidence and the action page used an off-by-one half-open range.
  - After: scored as `76/84` after live IDA MCP confirmed the action boundary, vtable action slot, call graph, single/multi delete packet paths, and mail-context offsets.
  - C++ remains blank because the constructor boundary is still projected and the recovered field/helper names are not source-quality.
- 2026-06-13 Agent-A002 Goal 2 low-score repair:
  - Before: class remained at `76/84` because the constructor was only a projected start.
  - After: scored as `86/89`; parent remains [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) at position `60`, which clears the strict `85/85` gate; C++ remains blank below final-source quality.
  - Summary/evidence: live IDA MCP session `a003_goal2_rtti_type_descriptors` confirmed exact raw constructor child [UID:0003MZ][0x0047e4b0-0x0047e508.ConfirmDeleteMailAlertRawConstructor](by-memory/0x0047e4b0-0x0047e508.ConfirmDeleteMailAlertRawConstructor.md), predecessor/successor padding, no-function/no-start-xref status, vtable stores, unique byte signature, and four modeled mail construction mirrors with mode-byte variants. The exact action child [UID:0002SF][0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest](by-memory/0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest.md) remains the packet behavior authority.
