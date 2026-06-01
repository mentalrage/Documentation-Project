*** UID:0000BQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RankingUserListPane

## Status

- Likely source file: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Address range: [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- Current recovered file: `source-3/simroot_v2/class_RankingUserListPane.cpp`
- Confidence: medium; generated source has likely helper-name pollution.

## Class Purpose

`RankingUserListPane` draws the current ranking page selected in `RankingDialog`. It renders summary title/count/date fields, column headers, up to ten rank/name/score rows, and the local player's rank footer.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `RankingUserListPane` | `0x0045f340-0x0045f376` | Constructs `ControlPane` and installs vtables. |
| `NonDeletingDestructorBody` | `0x0045f380-0x0045f39e` | Reinstalls the three class vtables and calls base `Pane` teardown helper `0x00544580`; currently has no direct xrefs in IDA. |
| `OnPaint` | `0x0045f3a0-0x0045f944` | Draws ranking title, total count, from/to timestamps, row table, and local-player footer. |
| `AdjustorThunks` | `0x0045f97d-0x0045f992` | Compiler-generated destructor adjustor thunks for the secondary and tertiary vtable views. |
| `ScalarDeletingDestructor` | `0x0045f9a0-0x0045f9f4` | Destructor path currently named through an unrelated base; needs base-owner cleanup before migration. |

## Evidence Notes

- `RankingDialog` creates this pane as child control `2`.
- IDA confirms `0x0045f950` / `FormatWide64_45F950` is only a fixed `0x40`-wide-character CRT formatting wrapper used by `OnPaint`; it is tracked in [UID:0000VN][-ignored](by-memory/-ignored.md), not as ranking-owned handwritten logic.
- Current generated `LineTo` helper at `0x004b98f0` is a generic drawing helper, not ranking-specific owner code.
- The generated source references high-level `RankingSnapshot`/`RankingRow` names that are useful behavior labels but still need layout confirmation against `RankingCategoryRecord` user-entry fields.
- IDA confirms primary, secondary, and tertiary vtables at `0x00610cd0`, `0x00610d38`, and `0x00610d68`; current generated metadata still reports `vtable_count: 0`.
- The tertiary table ends after `+0x04`. The following UTF-16 `Total`, `From`, and `To` format strings are label data, not additional virtual slots.

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000BM][RankingDialog](by-class/RankingDialog.md)
- [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md)
- [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md)
- [UID:0000YC][0x0045f97d-0x0045f992.RankingUserListPaneAdjustorThunks](by-memory/0x0045f97d-0x0045f992.RankingUserListPaneAdjustorThunks.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `72/78`.
  - Before: page documented class purpose, known methods, vtables, and paint/data caveats but remained unevaluated.
  - After: score reflects documented constructor, destructor-shaped body, paint path, destructor thunks, scalar deleting destructor, vtables, and formatter/render-helper ownership caveats.
  - Evidence: ranking aggregate [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md) records the user-list range, vtable family, and adjacent ignored `FormatWide64_45F950` helper; remaining confidence is limited by generated helper-name/layout pollution.
