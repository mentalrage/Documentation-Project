*** UID:0000F5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
/*
[UID:0000F5] No standalone class-level C++ is emitted from this class page.
TransferReplyAlert owns exact child pages: [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md) emits the constructor and [UID:0002EL][0x00478fe0-0x0047904f.TransferReplyAlertOnConfirm](by-memory/0x00478fe0-0x0047904f.TransferReplyAlertOnConfirm.md) emits the confirm action. The class page remains an index/support page and must not duplicate child bodies.
*/
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TransferReplyAlert

## Status

- Confidence: strong for exact raw constructor bytes, vtable stores, confirm behavior, and paired predefined-alert comparison; medium-high for source placement because `BulletinReplyAlerts.cpp` now passes the corrected parent gate but the board-dialog private-helper split remains a plausible alternative.
- Likely source file: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), or a private section of [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md).
- Recovered source lead: `class_TransferReplyAlert.cpp`; current ownership and scoring are based on IDA/by-* evidence, not generated source authority.
- Constructor memory range: [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md)
- Companion memory range: [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)

## Role

`TransferReplyAlert` is an `AlertPane` subclass used by article/bulletin transfer-reply acknowledgements. Confirming the alert hides/closes it, finds the previous bulletin dialog entry, sends an article navigation packet for the selected reply context, and optionally pops the current `BulletinSession` dialog.

## Methods

| Range | Method | Notes |
| --- | --- | --- |
| [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md) | constructor, raw IDA bytes | Initializes `AlertPane`, stores the optional pop flag, and installs three alert vtables. IDA does not currently define this start as a function, but raw disassembly confirms constructor-shaped code. |
| [UID:0002EL][0x00478fe0-0x0047904f.TransferReplyAlertOnConfirm](by-memory/0x00478fe0-0x0047904f.TransferReplyAlertOnConfirm.md) | `OnConfirm` | Exact vtable-dispatched confirm/action callback; it closes the alert, resolves the previous bulletin dialog, calls the article navigation helper at `0x004751c0`, and optionally pops the bulletin session. |
| [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) | adjustor thunks | Secondary/tertiary vtable thunks to scalar deleting destructor `0x0047eaf0`. |
| `0x0047eaf0-0x0047eb2a` | scalar deleting destructor | Runs base alert/dialog destruction and optional delete. |

## Notes

- Treat destructor `0x0049d9f0` as shared `DialogPane` cleanup, not a `TransferReplyAlert`-specific body. Generated `TransferReplyAlert::~DialogPane` labels in unrelated classes are base-owner pollution.
- [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md) is scored `85/90` and records exact body bytes, surrounding `0xcc` padding, no IDA function object at the raw start, the shared `0x0049feb0` constructor-helper call, the `this+0x270` flag store, and the three `TransferReplyAlert` vtable stores at `0x006140f0`, `0x00614158`, and `0x00614188`.
- [UID:0002EL][0x00478fe0-0x0047904f.TransferReplyAlertOnConfirm](by-memory/0x00478fe0-0x0047904f.TransferReplyAlertOnConfirm.md) is scored `85/90` and gives the exact modeled callback range, vtable xref `0x0061414c`, raw instruction flow, owner/session offsets, control id `7`, selected article id offset, mode-derived packet offset, and optional session-pop branch.
- The closely related [UID:0000F6][TransferReplyPredefinedAlert](by-class/TransferReplyPredefinedAlert.md) action body is documented at [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md). IDA shows the same callee set and article-navigation behavior as this method; the active generated predefined-alert body remains a data issue.
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md) records the primary/secondary/tertiary `TransferReplyAlert` table bases and constructor-store evidence, tying the raw constructor and confirm callback to the board/article alert layout neighborhood.

## Parent And Score Rationale

| Topic | Rationale |
| --- | --- |
| Parent assignment | Retained under [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) at position `10` because the likely source-owner bucket is now `85/86` and this class is `85/86`, so both sides pass the corrected `85/85` gate. [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) remains a plausible alternate placement, so no final C++ is emitted. |
| Constructor evidence | The raw constructor child is exact and source-relevant despite missing IDA function metadata: it has fixed bytes, padding, vtable stores, and the `this+0x270` flag store. |
| Action evidence | The confirm callback is an IDA-modeled function with vtable xref and a concrete article-navigation packet path, paired behaviorally with the predefined transfer-reply alert callback. |
| Remaining blockers | The final source split between `BulletinReplyAlerts.cpp`, board dialog private helpers, and predefined-form article helpers remains open; constructor helper names, final field names, and destructor ownership are below final-C++ quality. |

## Batch108 Parent-Gate Repair

2026-06-08 IDA MCP recheck supports raising this direct class parent to the corrected `85/85` gate for its two exact children:

- `0x00478f90` remains raw constructor-shaped bytes with no IDA function object and no inbound xrefs, bounded by `cc cc` before the body and eight `0xcc` bytes before `0x00478fe0`.
- `0x00478fe0-0x0047904f` remains modeled as `sub_478FE0`, size `0x6f`, with the action slot data xref at `0x0061414c`.
- The primary `TransferReplyAlert` vtable neighborhood records RTTI at `0x006140ec`, scalar destructor `0x0047eaf0`, and the action slot `0x0061414c -> 0x00478fe0`.
- Constructor stores to `0x006140f0`, `0x00614158`, and `0x00614188` are cross-referenced at `0x00478fb7`, `0x00478fbd`, and `0x00478fc7`, and the same table bases are also used by nearby alert-family constructors.
- Direct file parent [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) is already `85/86`, so this class can retain file attachment under the corrected gate.

Assignment decision: retain this class under [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), and allow the exact constructor/action children to attach to this class. Final C++ remains blank because the shared constructor helper name, `+0x270` field name, full declaration, and original private-vs-shared file split remain provisional.

## Cross-References

- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md)
- [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md)
- [UID:0002EL][0x00478fe0-0x0047904f.TransferReplyAlertOnConfirm](by-memory/0x00478fe0-0x0047904f.TransferReplyAlertOnConfirm.md)
- [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md)

## B006 2026-06-29 Implementation Callback

- Accepted C13: this class page is an index/no-code row with `[[CHILDREN]]` as the insertion point for exact child output. [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md) and [UID:0002EL][0x00478fe0-0x0047904f.TransferReplyAlertOnConfirm](by-memory/0x00478fe0-0x0047904f.TransferReplyAlertOnConfirm.md) now own the emitted constructor and confirm-action source, so class-level C++ would duplicate child bodies.

## Changes

- 2026-06-06 A008:
  - Before: completion/confidence were `82/78`, the confirm callback was cited only as a raw address range in the method table, and the parent rationale did not include the newer exact constructor/action child scores.
  - After: changed completion/confidence to `84/82`, kept `AUTOGEN_PARENT_UID` blank, linked exact confirm-action child [UID:0002EL][0x00478fe0-0x0047904f.TransferReplyAlertOnConfirm](by-memory/0x00478fe0-0x0047904f.TransferReplyAlertOnConfirm.md), and added parent/score rationale.
  - Evidence: [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md) and [UID:0002EL][0x00478fe0-0x0047904f.TransferReplyAlertOnConfirm](by-memory/0x00478fe0-0x0047904f.TransferReplyAlertOnConfirm.md) are both exact `82/90` children, [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md) carries the matching vtable bases, and [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) remains below the parent-attachment gate at `78/86`.
- 2026-06-07 A004:
  - Changed to: attached to [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) with parent position `10`; score remains `84/82`.
  - Summary/evidence: the file parent was refreshed to `82/86` with exact transfer/delete child-family evidence, so the 80/80 parent gate passed. Historical note: this older entry left C++ blank under a `95/95` gate; B006 now leaves only the class page no-code while child pages [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md) and [UID:0002EL][0x00478fe0-0x0047904f.TransferReplyAlertOnConfirm](by-memory/0x00478fe0-0x0047904f.TransferReplyAlertOnConfirm.md) emit source.
- 2026-06-08 A009 Batch108 parent-gate repair:
  - Before: scores were `84/82`, so exact child pages could not attach under the corrected `85/85` gate even though the file parent had already reached `85/86`.
  - After: raised to `85/86`; retained [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) as direct file parent.
  - Summary/evidence: IDA MCP reconfirmed the raw constructor boundary/no-function-object status, exact constructor vtable stores, the modeled confirm callback at `0x00478fe0-0x0047904f`, the vtable action slot at `0x0061414c`, and the primary/secondary/tertiary vtable store xrefs. Remaining source-split and final-name caveats keep the score conservative and C++ blank.

- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` while leaving `AUTOGEN_PARENT_UID` blank.
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the alert action, adjustor thunks, and scalar deleting destructor starts at `0x00478fe0`, `0x0047e855`, `0x0047e860`, and `0x0047eaf0`; the constructor at `0x00478f90` remains a raw non-function constructor-shaped start documented by [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md). Historical note: this old pass predated the B006 source-quality promotion of child method bodies.
- 2026-05-27: The constructor was previously recorded only as Wave3-projected `0x00478f90`. Updated it to raw IDA-confirmed range [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md). Evidence: IDA raw disassembly shows constructor-shaped code, `0x0049feb0` helper call, optional-pop flag store at `this+0x270`, and `TransferReplyAlert` vtable stores at `0x00478fb7`, `0x00478fbd`, and `0x00478fc7`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:78`.
  - Summary/evidence: scored from the raw constructor evidence, IDA-confirmed confirm action, alert-family ownership notes, destructor-thunk mapping, and documented constructor-boundary/base-owner caveats.
