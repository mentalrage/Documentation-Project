*** UID:00001C | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BulletinDialog

## Status

- Confidence: strong for raw constructor bytes and vtable bases, medium for live reachability and final virtual names.
- Likely source file: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- Address range: raw constructor [UID:0000ZI][0x00472000-0x0047203a.BulletinDialogRawConstructor](by-memory/0x00472000-0x0047203a.BulletinDialogRawConstructor.md), shared virtual [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md), board/article cluster [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md), with destructor companion at `0x0047ea10-0x0047ea4a`
- Exact vtable data: [UID:0002MI][0x00613ba4-0x00613c44.BulletinDialogVtableData](by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md)
- Current recovered file: `source-3/simroot_v2/class_BulletinDialog.cpp`

## Class Purpose

`BulletinDialog` is the common bulletin-board dialog base over `DialogInSession`. IDA confirms the raw constructor bytes, three vtable views, one shared secondary-interface command bridge, and the active scalar deleting destructor. The constructor remains unmodeled as an IDA function, so this page should distinguish raw/projected constructor evidence from normal function-boundary evidence.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `BulletinDialog` | [UID:0000ZI][0x00472000-0x0047203a.BulletinDialogRawConstructor](by-memory/0x00472000-0x0047203a.BulletinDialogRawConstructor.md) | Raw constructor-shaped body. Calls [UID:00003S][DialogInSession](by-class/DialogInSession.md) constructor `0x004a1400`, installs vtables, and returns `this`; IDA MCP still reports no function object at `0x00472000`. |
| shared command-one virtual | [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) | Secondary-vtable callback shared by board/article dialog subclasses. Checks command string `'1'`, then forwards through the primary vtable slot at `+0x5c`. |
| adjustor thunks | [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) | Compiler-generated secondary/tertiary deleting-destructor thunks that subtract `0xa0` or `0xa4` and tail-call `0x0047ea10`; do not write as handwritten methods. |
| `ScalarDeletingDestructor` | `0x0047ea10-0x0047ea4a` | Active deleting-destructor wrapper. Calls [UID:00003S][DialogInSession](by-class/DialogInSession.md) base cleanup at `0x004a1450` and optionally frees storage. |

## Evidence Notes

- Wave3 summary identifies this as a bulletin-board dialog base extending `DialogInSession`.
- IDA MCP on 2026-05-23 reports `0x00472000` is not a function; previous function is `0x00471ea0-0x00471ff1`, next function is `0x00472040-0x00472069`.
- 2026-05-26 IDA raw disassembly confirms `0x00472000-0x0047203a` is constructor-shaped code that calls `0x004a1400` and stores vtables at `this + 0x00`, `this + 0xa0`, and `this + 0xa4`.
- 2026-05-26 IDA `list_globals *BulletinDialog*` confirms vtable bases `0x00613ba8`, `0x00613c0c`, and `0x00613c3c`; see [UID:0001X5][BulletinDialogVtables](by-type/by-vtable/BulletinDialogVtables.md).
- 2026-05-31 IDA dword scan confirms exact `BulletinDialog` RTTI/vtable data range [UID:0002MI][0x00613ba4-0x00613c44.BulletinDialogVtableData](by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md), bounded by the preceding slot at `0x00613ba0` and following `BoardListDialog` RTTI at `0x00613c44`.
- 2026-05-26 IDA decompilation confirms `0x00472040` is a real vtable-referenced callback shared by the board/article dialog family.
- IDA MCP confirms the destructor at `0x0047ea10` with size `0x3b`.
- 2026-05-25 IDA decompilation confirms the destructor calls `DialogInSession` non-deleting destructor `0x004a1450`; generated labels that render this as `ArticleDialog` cleanup are base-owner pollution.
- Older by-memory notes mention inactive inherited/default virtuals around `0x0041d6b0`; those should not be used as bulletin feature logic.

## Cross-References

- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0000ZI][0x00472000-0x0047203a.BulletinDialogRawConstructor](by-memory/0x00472000-0x0047203a.BulletinDialogRawConstructor.md)
- [UID:0002MI][0x00613ba4-0x00613c44.BulletinDialogVtableData](by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md)
- [UID:0001X5][BulletinDialogVtables](by-type/by-vtable/BulletinDialogVtables.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md)
- [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md)
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- [wave3_data_issues](../wave3_data_issues.md)
- [UID:00000J][ArticleDialog](by-class/ArticleDialog.md)
- [UID:00003S][DialogInSession](by-class/DialogInSession.md)
- [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md)

## Changes

- What existed before: the page distinguished raw constructor evidence, vtables, destructor thunks, and board-dialog ownership, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `70/78`.
- Summary and evidence: raw constructor bytes, vtable bases, destructor, and shared command virtual are documented; live reachability, final virtual names, and complete header/layout remain unresolved.
- 2026-05-31: Changed reconstructable from blank to `TRUE` and scores from `70/78` to `72/82`. Evidence: exact vtable data is now split and IDA-verified in [UID:0002MI][0x00613ba4-0x00613c44.BulletinDialogVtableData](by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md). Parent attachment and C++ code remain blank because final class header/source shape is not at the `95+` gate.
