*** UID:00001C | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BulletinDialog

## Status

- Confidence: strong for raw constructor bytes and vtable bases, medium for live reachability and final virtual names.
- Assigned source file: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md). C++ is intentionally blank because the raw constructor is still not an IDA function object and live construction reachability is unresolved.
- Address range: raw constructor [UID:0000ZI][0x00472000-0x0047203a.BulletinDialogRawConstructor](by-memory/0x00472000-0x0047203a.BulletinDialogRawConstructor.md), shared virtual [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md), board/article split inventory [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md), with non-emitting shared destructor companion [UID:00033P][0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor](by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md)
- Exact vtable data: [UID:0002MI][0x00613ba4-0x00613c44.BulletinDialogVtableData](by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md)

## Class Purpose

`BulletinDialog` is the common bulletin-board dialog base over `DialogInSession`. IDA confirms the raw constructor bytes, three vtable views, one shared secondary-interface command bridge, and the active scalar deleting destructor. The constructor remains unmodeled as an IDA function, so this page should distinguish raw/projected constructor evidence from normal function-boundary evidence.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `BulletinDialog` | [UID:0000ZI][0x00472000-0x0047203a.BulletinDialogRawConstructor](by-memory/0x00472000-0x0047203a.BulletinDialogRawConstructor.md) | Raw constructor-shaped body. Calls [UID:00003S][DialogInSession](by-class/DialogInSession.md) constructor `0x004a1400`, installs vtables, and returns `this`; IDA MCP still reports no function object at `0x00472000`. |
| shared command-one virtual | [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) | Secondary-vtable callback shared by board/article dialog subclasses. Checks command string `'1'`, then forwards through the primary vtable slot at `+0x5c`. |
| adjustor thunks | [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) | Compiler-synthesized secondary/tertiary deleting-destructor thunks that subtract `0xa0` or `0xa4` and tail-call `0x0047ea10`; do not write as handwritten methods. |
| `ScalarDeletingDestructor` | [UID:00033P][0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor](by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md) | Active non-emitting deleting-destructor wrapper shared by bulletin/board/article dialog vtables. Calls [UID:00003S][DialogInSession](by-class/DialogInSession.md) base cleanup at `0x004a1450` and optionally frees storage. |

## Evidence Notes

- Live IDA confirms this as a bulletin-board dialog base extending `DialogInSession`.
- 2026-06-05 live IDA MCP reports `0x00472000` is not a function; previous function is `sub_471EA0` at `0x00471ea0-0x00471ff1`, next function is `sub_472040` at `0x00472040-0x00472069`.
- 2026-06-05 live raw disassembly confirms the constructor-shaped body from `0x00472000` through `0x00472037 retn 8`, followed by alignment at `0x0047203a` before `sub_472040`.
- 2026-06-05 live raw constructor disassembly shows pushes of `[ebp+0x0c]`, constant `2`, and `[ebp+0x08]`, call to `sub_4A1400`, then vtable stores at `0x00472017`, `0x0047201f`, and `0x00472029`.
- 2026-06-05 live function lookup confirms `sub_4A1400` at `0x004a1400-0x004a144e` and `sub_4A1450` at `0x004a1450-0x004a146f` as the [UID:00003S][DialogInSession](by-class/DialogInSession.md) constructor/destructor helpers used by this class family.
- 2026-06-05 live `xrefs_to 0x00472000` is empty, so constructor reachability remains unresolved.
- 2026-06-05 live vtable-base xrefs confirm `0x00613ba8`, `0x00613c0c`, and `0x00613c3c` are referenced only by the raw constructor stores at `0x00472017`, `0x0047201f`, and `0x00472029`.
- 2026-06-05 live vtable slot scan confirms `0x00613ba4` is `??_R4BulletinDialog@@6B@`, primary slot `0x00613ba8` targets `sub_47EA10`, secondary slot `0x00613c0c` targets adjustor thunk `sub_47E897`, secondary slot `0x00613c1c` targets command bridge `sub_472040`, tertiary slot `0x00613c3c` targets adjustor thunk `sub_47E8A2`, and `0x00613c40` is the final slot before the following `BoardListDialog` data at `0x00613c44`.
- 2026-06-05 live command bridge disassembly confirms `sub_472040` checks command byte `'1'` at `[arg+0x0c]`, returns false for other commands, adjusts `this` by `-0xa0`, and forwards through primary vtable slot `+0x5c`.
- 2026-06-05 live destructor disassembly confirms `sub_47EA10` calls `sub_4A1450`, tests deleting flags, optionally calls `sub_4F4AC0`, and returns `this`; the secondary and tertiary adjustor thunks at `0x0047e897` and `0x0047e8a2` subtract `0xa0` or `0xa4` and tail-call `sub_47EA10`.
- 2026-06-10 B001-025 created exact non-emitting companion [UID:00033P][0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor](by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md); IDA reports adjustor-thunk refs and shared vtable/data refs at `0x00613ba8`, `0x00613c48`, `0x00613fb0`, and `0x0061443c`.
- 2026-05-26 IDA raw disassembly confirms `0x00472000-0x0047203a` is constructor-shaped code that calls `0x004a1400` and stores vtables at `this + 0x00`, `this + 0xa0`, and `this + 0xa4`.
- 2026-05-26 IDA `list_globals *BulletinDialog*` confirms vtable bases `0x00613ba8`, `0x00613c0c`, and `0x00613c3c`; see [UID:0001X5][BulletinDialogVtables](by-type/by-vtable/BulletinDialogVtables.md).
- 2026-05-31 IDA dword scan confirms exact `BulletinDialog` RTTI/vtable data range [UID:0002MI][0x00613ba4-0x00613c44.BulletinDialogVtableData](by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md), bounded by the preceding slot at `0x00613ba0` and following `BoardListDialog` RTTI at `0x00613c44`.
- 2026-05-26 IDA decompilation confirms `0x00472040` is a real vtable-referenced callback shared by the board/article dialog family.
- IDA MCP confirms the destructor at `0x0047ea10` with size `0x3b`.
- 2026-05-25 IDA decompilation confirms the destructor calls `DialogInSession` non-deleting destructor `0x004a1450`; labels that render this as `ArticleDialog` cleanup are base-owner pollution.
- Older by-memory notes mention inactive inherited/default virtuals around `0x0041d6b0`; those should not be used as bulletin feature logic.
- 2026-06-08 Batch 107 raised the direct [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) parent to `85/86` and attached [UID:0000ZI][0x00472000-0x0047203a.BulletinDialogRawConstructor](by-memory/0x00472000-0x0047203a.BulletinDialogRawConstructor.md) here after both child and class cleared the corrected `85/85` gate.

## Assignment Decision

`AUTOGEN_PARENT_UID` remains [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md). The class is now `85/87`, and the direct file parent is now `85/86`, so both sides clear the corrected `85/85` gate. The assignment is direct because `BoardDialogs` owns the common `BulletinDialog` base, the shared command virtual, the scalar deleting destructor, and the board/article vtable family. Final C++ stays blank because the raw constructor has no IDA function object or direct construction xrefs.

## Cross-References

- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0000ZI][0x00472000-0x0047203a.BulletinDialogRawConstructor](by-memory/0x00472000-0x0047203a.BulletinDialogRawConstructor.md)
- [UID:0002MI][0x00613ba4-0x00613c44.BulletinDialogVtableData](by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md)
- [UID:0001X5][BulletinDialogVtables](by-type/by-vtable/BulletinDialogVtables.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md)
- [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md)
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- [UID:00000J][ArticleDialog](by-class/ArticleDialog.md)
- [UID:00003S][DialogInSession](by-class/DialogInSession.md)
- [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md)
- [UID:00033P][0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor](by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md)

## Score Rationale

Completion is raised to `85` because the page now records the raw constructor bytes, function-boundary gap, vtable base xrefs, vtable slot ownership, command bridge behavior, destructor body, adjustor thunks, exact vtable-data child, direct file parent, and child raw-constructor attachment. Confidence is raised to `87` because the class layout and source ownership are strongly supported by live disassembly and the `BoardDialogs` parent now clears the corrected gate, but the score remains below final because `0x00472000` is still not modeled as a function and constructor reachability/final virtual names are unresolved.

## Changes

- What existed before: the page distinguished raw constructor evidence, vtables, destructor thunks, and board-dialog ownership, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `70/78`.
- Summary and evidence: raw constructor bytes, vtable bases, destructor, and shared command virtual are documented; live reachability, final virtual names, and complete header/layout remain unresolved.
- 2026-05-31: Changed reconstructable from blank to `TRUE` and scores from `70/78` to `72/82`. Evidence: exact vtable data is now split and IDA-verified in [UID:0002MI][0x00613ba4-0x00613c44.BulletinDialogVtableData](by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md). Parent attachment and C++ code remain blank because final class header/source shape is not at the `95+` gate.
- 2026-06-05 live IDA refresh:
  - What existed before: the class was `72/82`, reconstructable, and unassigned, with stale source references and a raw-constructor summary delegated to child pages.
  - Changed to: completion `82`, confidence `86`, parent [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), stale source references removed, and class-scope evidence added for the raw constructor, vtable xrefs, command bridge, destructor, and adjustor thunks.
  - Summary/evidence: live IDA confirms no function object and no direct xrefs at `0x00472000`, constructor-shaped code ending at `0x00472037`, vtable stores at `0x00472017/0x0047201f/0x00472029`, command bridge `sub_472040`, destructor `sub_47EA10`, and adjustors `sub_47E897`/`sub_47E8A2`. C++ remains blank because the raw constructor boundary and live reachability are still below the final reconstruction gate.
- 2026-06-08 A008 Batch 107:
  - Before: `COMPLETION:82`, `CONFIDENCE:86`; the class was assigned to a file parent that was still below the corrected `85/85` gate.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:87`; assignment to [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) is now gate-valid because that file reached `85/86`.
  - Summary/evidence: Batch 107 reconfirmed the raw constructor's exact range/no-function status through [UID:0000ZI][0x00472000-0x0047203a.BulletinDialogRawConstructor](by-memory/0x00472000-0x0047203a.BulletinDialogRawConstructor.md), synced the direct file parent, and attached the raw constructor child to this class. C++ remains blank because constructor reachability and final virtual names are unresolved.
- 2026-06-10 B001-025:
  - Changed: replaced the raw destructor range note with exact shared non-emitting companion [UID:00033P][0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor](by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md).
  - Summary/evidence: IDA MCP confirms the wrapper's bounds, `DialogInSession` destructor call, scalar-delete free logic, adjustor refs, and shared vtable/data refs spanning bulletin/board/article dialog classes.
