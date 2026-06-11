*** UID:0000BL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:50 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RankingCategoryRecord

## Status

- Likely source file: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Address range: [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- Confidence: strong for method boundaries and layout offsets; medium for final field/type names.

## Class Purpose

`RankingCategoryRecord` stores one ranking event/category definition plus its loaded user rows. The record includes list index, category id, state code, start/end time parts, title text, and a vector-like user-entry buffer.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GetListIndex` | `0x0045bf60-0x0045bf63` | Returns the record list index. |
| `GetCategoryId` | `0x0045bf70-0x0045bf73` | Returns the category id at record offset `+4`. |
| `GetStateCode` | `0x0045bf80-0x0045bf83` | Returns state code at record offset `+8`. |
| `CopyStartTimeParts` | `0x0045bf90-0x0045bfae` | Copies start-time/date parts from record offset `+12`. |
| `CopyEndTimeParts` | `0x0045bfb0-0x0045bfce` | Copies end-time/date parts from record offset `+48`. |
| `GetTitleText` | `0x0045bfd0-0x0045bfd3` | Returns wide title pointer at record offset `+84`. |
| `GetUserEntryAt` | `0x0045bfe0-0x0045c01a` | Bounds-checked lookup into user-entry vector at record offset `+600`. |
| `SetStartTimeFromPackedDateTime` | `0x0045c050-0x0045c0f8` | Splits packed date/time integers into the start time/date block. |
| `SetEndTimeFromPackedDateTime` | `0x0045c100-0x0045c1a8` | Splits packed date/time integers into the end time/date block. |
| `AppendUserEntry` | `0x0045c1e0-0x0045c238` | Appends one 76-byte ranking user row to the vector, growing through `0x0045d1b0` when full. |
| `ResetUserEntries` | `0x0045c240-0x0045c256` | Resets current user-entry end to begin and selected user index to `-1`. |

## Layout Notes

- IDA collection parser and deep-copy helpers prove a record stride of `688` bytes.
- User-entry stride is `76` bytes.
- Start/end packed date-time setters split `YYYYMMDD`-like and `HHMMSS`-like integers into six dword fields inside each 36-byte date/time block.
- Wide title text begins at offset `+84`.
- User-entry vector fields begin around offset `+600`.
- See [UID:0001VN][RankingCategoryRecordLayout](by-type/by-struct/RankingCategoryRecordLayout.md) for the current offset table.

## Evidence Notes

- 2026-05-25 IDA MCP confirms every method start listed above as a normal function.
- 2026-05-27 IDA MCP confirms three additional function starts in the same record range: `0x0045c050`, `0x0045c100`, and `0x0045c1e0`.
- Caller evidence shows these disabled helpers are still live in the ranking cluster: `GetListIndex` is called from `RankingEventListPane::HandleEvent` at `0x0045b511`, start/end copy helpers are called from `RankingUserListPane::OnPaint` at `0x0045f4fe` and `0x0045f56f`, `GetTitleText` is used by both event/reward/user drawing paths, `GetUserEntryAt` is called from `RankingUserListPane::OnPaint`, and `ResetUserEntries` is called from the category-selection/update path at `0x004594f7`.

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000Y9][0x0045bf60-0x0045c257.RankingCategoryRecord](by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md)
- [UID:0001VN][RankingCategoryRecordLayout](by-type/by-struct/RankingCategoryRecordLayout.md)
- [UID:0000BK][RankingCategoryCollection](by-class/RankingCategoryCollection.md)
- [UID:0000BN][RankingEventListPane](by-class/RankingEventListPane.md)
- [UID:0000BQ][RankingUserListPane](by-class/RankingUserListPane.md)

## Changes

- 2026-06-05: Raised from `82/86` to `84/88` after live IDA reconfirmed all eleven method starts/caller sets, the category parser and ranking-row parser relationships, the 688-byte record stride, and the 76-byte user-entry vector behavior. Removed recovered-output status wording and kept final C++ blank under the 95/95 gate.
- 2026-05-31: Marked the class as reconstructable and attached it to [UID:0000MZ][RankingDialog](by-file/RankingDialog.md) after the method range was split into exact by-memory children.
  - Before: class page had strong method/layout evidence but validator autogen metadata was blank.
  - After: `RECONSTRUCTABLE:TRUE` with the file parent set, while final C++ remains blank because field/type names and source declarations are not at the 95+ final-source threshold.
  - Evidence: IDA MCP reconfirmed all eleven method starts, live callers, 688-byte record stride in collection parsers, and 76-byte user-entry operations.
- 2026-05-30: Grading changed from `0/0` to `80/84`.
  - Before: page documented method boundaries, layout offsets, live disabled/generated omissions, and caller evidence but remained unevaluated.
  - After: score reflects documented accessors, packed date/time setters, title/user-entry vector access, append/reset helpers, layout notes, and active generated-source omissions.
  - Evidence: IDA notes confirm all listed function starts, live callers from ranking event/user-list/category paths, 688-byte record stride, 76-byte user-entry stride, and links to [UID:0001VN][RankingCategoryRecordLayout](by-type/by-struct/RankingCategoryRecordLayout.md).
- 2026-05-27: Changed the method inventory from eight methods to eleven methods. Added the missing start/end packed date-time setters and user-entry append helper after IDA function enumeration/decompilation confirmed `0x0045c050`, `0x0045c100`, and `0x0045c1e0` are live `RankingCategoryRecord` functions inside the already documented aggregate range.
