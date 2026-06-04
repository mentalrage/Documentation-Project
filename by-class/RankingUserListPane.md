*** UID:0000BQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RankingUserListPane

## Status

- Likely source file: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Address range: [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- Confidence: strong for class identity, method boundaries, vtables, and paint behavior; remaining uncertainty is exact row-layout naming inside `RankingCategoryRecord`.

## Class Purpose

`RankingUserListPane` draws the current ranking page selected in `RankingDialog`. It renders summary title/count/date fields, column headers, up to ten rank/name/score rows, and the local player's rank footer.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `RankingUserListPane` | `0x0045f340-0x0045f377` | Constructs the `ControlPane` base with control id `8` and installs the three class vtable views. |
| `NonDeletingDestructorBody` | `0x0045f380-0x0045f39f` | Reinstalls the three class vtables and calls base `Pane` teardown helper `0x00544580`; currently has no direct xrefs in IDA. |
| `OnPaint` | `0x0045f3a0-0x0045f945` | Draws ranking title, total count, from/to timestamps, row table, and local-player footer. |
| `FormatWide64_45F950` | `0x0045f950-0x0045f97d` | Adjacent fixed 64-wide-character CRT formatting wrapper; all nine callers are inside `OnPaint`, so it remains tracked as ignored helper code. |
| `AdjustorThunks` | `0x0045f97d-0x0045f993` | Destructor adjustor thunks for the secondary and tertiary vtable views. |
| `ScalarDeletingDestructor` | `0x0045f9a0-0x0045f9f5` | Reinstalls vtables, runs base teardown, and conditionally frees through `0x004f4ac0` when the deleting flags request ownership release. |

## IDA Evidence

- Live IDA recheck on 2026-06-04 used `NexusTK.exe` at image base `0x00400000` with MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- Constructor `0x0045f340-0x0045f377` has one code caller at `0x0045875f` in the `RankingDialog` constructor; it calls `0x004949e0`, then writes vtables `0x00610cd0`, `0x00610d38`, and `0x00610d68`.
- `OnPaint` initializes the EPF tile context (`0x00457a60`), loads the layout resource through `0x004d02f0(dword_67A744, off_60DB5C, ...)`, marks `this+0x70`, paints the background with `0x004ba6b0`, and reads the selected ranking category from `dword_67A7E4 + 0x26c` through `0x0045ce70`.
- The paint body draws the category title, `"Total : %d"`, `"From : %02d/%02d/%04d %02d:%02d:%02d"`, `"To : %02d/%02d/%04d %02d:%02d:%02d"`, and the `Rank`/`Name`/`Score` headers, then loops over ten `0x0045bfe0(category, index)` row lookups.
- Row rendering formats rank from `row+4`, name from `row+8`, score from `row+72`, draws separator lines with `0x004b9600`/`0x004b98f0`, and draws the local-player footer when category field `+0x268` is positive.
- `0x0045f950-0x0045f97d` wraps `__stdio_common_vswprintf_s` with a fixed `0x40` character buffer count and has exactly nine callers, all from `OnPaint`.
- The destructor thunks at `0x0045f97d` and `0x0045f988` subtract `0xa0` and `0xa4` respectively before tail-calling scalar destructor `0x0045f9a0`.

## Evidence Notes

- `RankingDialog` creates this pane as child control `2`; the constructor xref at `0x0045875f` is inside the dialog construction path.
- IDA confirms `0x0045f950` / `FormatWide64_45F950` is only a fixed `0x40`-wide-character CRT formatting wrapper used by `OnPaint`; it is tracked in [UID:0000VN][-ignored](by-memory/-ignored.md), not as ranking-owned handwritten logic.
- `LineTo` helper `0x004b98f0` is a generic drawing helper, not ranking-specific owner code.
- High-level row labels remain provisional until the `RankingCategoryRecord` user-entry fields are named from layout evidence.
- IDA confirms primary, secondary, and tertiary vtables at `0x00610cd0`, `0x00610d38`, and `0x00610d68`.
- The tertiary table ends after `+0x04`. The following UTF-16 `Total`, `From`, and `To` format strings are label data, not additional virtual slots.

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000BM][RankingDialog](by-class/RankingDialog.md)
- [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md)
- [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md)
- [UID:0000YC][0x0045f97d-0x0045f992.RankingUserListPaneAdjustorThunks](by-memory/0x0045f97d-0x0045f992.RankingUserListPaneAdjustorThunks.md)

## Changes

- 2026-06-04: Grading changed from `72/78` to `84/88`; marked reconstructable and attached to parent [UID:0000MZ][RankingDialog](by-file/RankingDialog.md).
  - Before: page identified the class and broad paint path but still carried stale recovered-source wording, inclusive method endpoints, no parent attachment, and only aggregate evidence for the score.
  - After: live IDA evidence records exact exclusive method ranges, constructor caller, vtable stores/xrefs, `OnPaint` resource/category/row/footer flow, formatter caller isolation, and destructor thunk behavior.
  - Reasoning: the child page now has direct current-disassembly support for identity and behavior, while the parent `RankingDialog` file is already `82/86`; remaining row-layout naming uncertainty keeps the page below the final C++ threshold.
- 2026-05-30: Grading changed from `0/0` to `72/78`.
  - Before: page documented class purpose, known methods, vtables, and paint/data caveats but remained unevaluated.
  - After: score reflects documented constructor, destructor-shaped body, paint path, destructor thunks, scalar deleting destructor, vtables, and formatter/render-helper ownership caveats.
  - Evidence: ranking aggregate [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md) records the user-list range, vtable family, and adjacent ignored `FormatWide64_45F950` helper; remaining confidence was limited by helper-name/layout pollution.
