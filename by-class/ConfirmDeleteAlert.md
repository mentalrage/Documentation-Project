*** UID:000033 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
/*
[UID:000033] No standalone class-level C++ is emitted from this class page.
ConfirmDeleteAlert owns exact children: [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md) emits the constructor, and [UID:0002SE][0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest](by-memory/0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest.md) emits the delete-request action. The class page remains an index/support page and must not duplicate child method bodies.
*/
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ConfirmDeleteAlert

## Status

- Confidence: strong for delete-packet behavior, raw constructor body, construction-mode variants, and vtable placement; medium-high for exact final source split and owner/list field names.
- Likely source file: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), or a private section of [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md).
- Generated source lead: `class_ConfirmDeleteAlert.cpp`; use as a search hint only, not as ownership authority.
- Companion memory range: [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)

## Role

`ConfirmDeleteAlert` is a localized delete-confirmation alert for board/article bulletin items. Its constructor asks [UID:0001OS][0x0067a750-0x0067a754.g_pLanguageMan](by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md) for `STR.RES` id `0x40` / text `Are you sure you want to delete this?`, passes `L"Delete"` and `L"Cancel"` to `AlertPane::AlertPane`, stores `ConfirmDeleteAlert::m_multiDelete` at object offset `0x270`, and sends opcode `0x3b`, subcommand `0x05` delete packets either for one selected entry or for each selected entry in a multi-delete list.

## Methods

| Range | Method | Notes |
| --- | --- | --- |
| [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md) | raw constructor | Source-ready retained constructor: `AlertPane(g_pLanguageMan->GetLocalizedString(0x40), layoutReference, L"Delete", L"Cancel")`, then `m_multiDelete = multiDelete`, followed by compiler vptr stores for the three `ConfirmDeleteAlert` vtables. IDA does not define this start as a function, but B002 MCP session `80de0a67` confirms the exact raw body, bytes, resource operands, zero raw-start xrefs, zero VA/RVA pointer hits, mirrored construction sites, and padding. |
| [UID:0002SE][0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest](by-memory/0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest.md) | `SendDeleteRequest` | IDA confirms this function; it serializes delete packets, updates the active player/delete context, and processes the bulletin queue. |

## Construction And Mode Evidence

| Site | Evidence | Mode byte |
| --- | --- | --- |
| [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md) | Raw constructor pushes `L"Cancel"`, `L"Delete"`, caller `Pane *layoutReference`, `0x40`, calls `LanguageMan::GetLocalizedString` through `g_pLanguageMan`, calls `AlertPane::AlertPane`, stores `[ebp+0x0c]` as `m_multiDelete` at `this + 0x270`, and writes vtables `0x00614580`, `0x006145e8`, `0x00614618`. | Caller-supplied `bool multiDelete`. |
| `0x00473e00` board/article switch path | Modeled function allocates `0x274` bytes, calls the same localization/base helpers with `off_612588` and `off_614CBC`, writes all three `ConfirmDeleteAlert` vtables, and sets `this + 0x270`. | `1` |
| `0x004740d0` compact construction path | Same allocation/helper/vtable sequence as the raw constructor and `0x00473e00`. | `1` |
| `0x00476410` article navigation switch path | Same allocation/helper/vtable sequence, then uses its own switch cases for article navigation/delete packet work. | `0` |
| `0x00476820` compact construction path | Same allocation/helper/vtable sequence as `0x00476410`. | `0` |

## Evidence Map

| Evidence | Impact |
| --- | --- |
| [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md) | Exact raw constructor child records the `0x0047e100-0x0047e158` body, `0x58` / 88-byte size (Verified with int_convert.py), bytes, `STR.RES` id `0x40`, `Delete`/`Cancel` operands, three vtable stores, `m_multiDelete` at `this + 0x270`, no-function/no-start-xref status, zero VA/RVA pointer hits, duplicate construction sites, unique byte signature, padding boundaries, and first-draft constructor C++ despite no IDA function object. |
| [UID:0002SE][0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest](by-memory/0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest.md) | Exact action child page records opcode `0x3b`, subcommand `0x05`, single/multi-delete behavior, and prior IDA MCP function-start evidence. |
| [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) | Places this class in the shared bulletin/mail alert wrapper family; the file parent is now `85/86`, so the existing parent attachment clears the strict `85/85` gate. |
| [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md) | Provides vtable family evidence for the board/article alert class family and records the constructor/store xrefs. |
| `entity_query 0x00614570-0x006146c8` | Live IDA MCP places `ConfirmDeleteAlert` tables after the `MailTransferReplyAlert` tertiary table and before `DeleteReplyAlert`/`ConfirmDeleteMailAlert`, supporting the shared board/article alert wrapper split rather than mail-only ownership. |

## Reconstruction Notes

- Reconstructable: true as an owning class shell plus confirmed action child.
- Parent: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), position `40`, until a more exact original file split is proven.
- C++: class-level C++ stays blank because the action child still needs synchronized board/article context field, list/provider type, packet helper, and queue helper declarations before an aggregate class draft is safe. The constructor child [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md) no longer has a blank-C++ blocker and now owns first-draft constructor C++.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The class now has exact constructor/action children, raw constructor byte and operand evidence, decoded `Delete`/`Cancel` resources, `STR.RES` id `0x40` text, `m_multiDelete` at `+0x270`, construction-mode callsite variants, vtable-family placement, packet-shape documentation, source-owner rationale, and explicit class-level C++ limits. It remains below final audit because action-specific helper/type declarations and the final board/article versus shared-alert source split are not source-quality. |
| Confidence | 88 | Confidence is strong because live IDA MCP verifies the raw constructor body, exact action child, vtable table order, duplicate construction sites, helper/global/base-constructor naming, and parent file gate. It remains below 95 because the raw constructor is still not an IDA function object, has no direct raw-start route, and action-specific names/layout details are still provisional. |

## Notes

- [UID:000034][ConfirmDeleteMailAlert](by-class/ConfirmDeleteMailAlert.md) has a sibling implementation with the same packet shape but mail-specific context offsets.
- The delete packet shape is feature-owned; do not move this logic into generic socket code just because it calls the packet queue helper.

## Cross-References

- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)

## B006 2026-06-29 Implementation Callback

- Accepted C02: this class page clears the empty marker with a formal no-code/index comment plus `[[CHILDREN]]` insertion point. [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md) is the already-emitted constructor child and [UID:0002SE][0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest](by-memory/0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest.md) now emits the delete-request action body through this class route.
- Current source-placement caveat remains: `BulletinReplyAlerts.cpp` is the active source bucket, while a private `BoardDialogs` split remains plausible history and only caps confidence.

## Changes

- 2026-06-25 B002 accepted constructor source-quality implementation:
  - Before: class notes still treated constructor helper/resource names as unresolved and kept C++ blank as a class-wide blocker.
  - After: constructor row, construction evidence, role text, and reconstruction notes now identify `LanguageMan::GetLocalizedString`, `g_pLanguageMan`, `AlertPane::AlertPane`, `STR.RES` id `0x40`, `L"Delete"`, `L"Cancel"`, and `ConfirmDeleteAlert::m_multiDelete`; class-level C++ remains blank only because the action child still blocks aggregate C++.
  - Summary/evidence: [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md) carries B002 MCP session `80de0a67` evidence, first-draft constructor C++, zero raw-start xrefs, zero VA/RVA pointer hits, and mirrored `m_multiDelete` values.
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
  - Summary/evidence: exact constructor child [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md), exact action child [UID:0002SE][0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest](by-memory/0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest.md), refreshed `BulletinReplyAlerts` parent score `82/86`, and vtable-family evidence support the gate-aligned score. At that time C++ remained blank; the 2026-06-25 B002 entry supersedes the constructor helper-name blocker while action-specific declarations and final source split still cap class-level aggregate C++.
- 2026-06-13 Agent-A001 Goal 2 low-score repair:
  - Before: class was the direct parent for [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md) but only scored `80/84`, below the supervisor-required `85/85` parent gate.
  - After: scored as `86/88`; parent remains [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) at position `40`, which already clears `85/85`; C++ remained blank at that time. The constructor-specific blank-C++ blocker is superseded by the 2026-06-25 B002 entry, while class-level aggregate C++ still waits on action-specific declarations.
  - Summary/evidence: live IDA MCP session `a002_batch_clear_timer` reconfirmed the raw constructor bytes/body and `Delete`/`Cancel` resource operands, the exact action child remains documented, `xrefs_to` the vtable bases shows four modeled board/article construction sites plus the raw constructor stores, and `entity_query` confirms the vtable order between `MailTransferReplyAlert`, `DeleteReplyAlert`, and `ConfirmDeleteMailAlert`. This makes [UID:000033] a justified direct parent for [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md).
