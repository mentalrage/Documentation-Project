*** UID:0000BK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RankingCategoryCollection

## Status

- Likely source file: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Address range: [UID:0001ZC][0x0045c260-0x0045d4f8.RankingCategoryCollection](by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md)
- Related storage helpers: [UID:0001ZD][0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers](by-memory/0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers.md)
- Parent range: [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- Confidence: strong for collection role and core IDA boundaries; medium for final parser/helper names.

## Class Purpose

`RankingCategoryCollection` is a vector-like container embedded in `RankingDialog`. It owns all ranking category/event records, tracks the selected category id, parses ranking category and ranking-page packet payloads, and frees per-record user-entry storage.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `RankingCategoryCollection` | `0x0045c260-0x0045c281` | Initializes begin/end/capacity pointers only. IDA does not show a selected-category-id write at this address. |
| `~RankingCategoryCollection` | `0x0045c290-0x0045c295` and `0x0045d530-0x0045d5b5` | `0x0045c290` is a tail-jump thunk to the vector teardown helper at `0x0045d530`. |
| `ParseCategoryList` | `0x0045c2a0-0x0045c556` | Packet parse helper for category/event records. |
| `ParseCategoryListExtended` | `0x0045c560-0x0045cb0a` | Larger packet parse/update helper that reads category/event metadata. |
| `ParseRankingRows` | `0x0045cb10-0x0045cdb4` | Parses user ranking rows into the selected category's user-entry vector. |
| `ApplyCategoryStatus` | `0x0045cdc0-0x0045ce2b` | Updates selected category state from packet category id and flag. |
| `SetSelectedCategoryId` | `0x0045ce30-0x0045ce3d` | Stores selected category id. |
| `GetCount` | `0x0045ce40-0x0045ce57` | Returns category count from begin/end stride. |
| `GetSelectedCategoryId` | `0x0045ce60-0x0045ce64` | Returns selected category id. |
| `GetSelected` | `0x0045ce70-0x0045ceab` | Finds record matching selected category id. |
| `GetByIndex` | `0x0045cf00-0x0045cf44` | Bounds-checked indexed record lookup. |
| `InsertCategoryRecordWithGrowth` | `0x0045cf50-0x0045d1ad` | Grows/reallocates the 688-byte category-record vector and deep-copies records. |
| `InsertUserEntryWithGrowth` | `0x0045d1b0-0x0045d317` | Grows/reallocates a 76-byte user-entry vector. |
| `CopyCategoryRecordDeep` | `0x0045d420-0x0045d4f8` | Deep-copies a category record, including the embedded user-entry vector. |

## Evidence Notes

- `RankingDialog` embeds this collection at offset `+0x26c` and calls it for selected category and packet request state.
- IDA shows packet handler `0x00459210` dispatching opcode `0x7d` subcommands `1`, `2`, `3`, and `6` to this class's parser/update methods.
- `RankingEventListPane` uses the collection for event/category display and click selection.
- `RankingRewardInfoDialog` uses the selected category id when requesting reward information.
- 2026-06-04 live IDA MCP reverified every method/helper range listed above, the constructor call at `0x00458695`, destructor calls/unwind at `0x00458973`, `0x00459866`, and `0x005fa14f`, and packet-handler calls at `0x00459243`, `0x00459276`, `0x004592ca`, and `0x004592e4`.

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000BM][RankingDialog](by-class/RankingDialog.md)
- [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md)
- [UID:0000BN][RankingEventListPane](by-class/RankingEventListPane.md)
- [UID:0001ZC][0x0045c260-0x0045d4f8.RankingCategoryCollection](by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md)
- [UID:0001ZD][0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers](by-memory/0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers.md)

## Changes

### 2026-05-30 - Grading update

- Before: this class had exact IDA-backed parser/helper coverage but remained unevaluated by the completion/confidence header.
- Changed to: score is now `82/86`, reflecting documented collection construction, packet parsing, selected-category state, accessors, category/user-entry vector growth, deep copy, and storage-helper ownership.
- Summary/evidence: linked memory pages [UID:0001ZC][0x0045c260-0x0045d4f8.RankingCategoryCollection](by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md) and [UID:0001ZD][0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers](by-memory/0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers.md) record IDA-confirmed starts, opcode `0x7d` dispatch, constructor mismatch, and vector helper behavior.

### 2026-05-27 - Added exact IDA-backed memory coverage

- Before: this class pointed only to the broad `RankingDialog` memory page, repeated an unsupported constructor claim that `selectedCategoryId` is initialized to `-1`, and did not list the vector growth/copy helper tail.
- Changed to: linked the exact collection and storage-helper `by-memory` pages, corrected constructor behavior to the three pointer writes shown by IDA, and added the IDA-confirmed helper methods through `0x0045d4f8`.
- Summary/evidence: IDA disassembly of `0x0045c260` shows writes only to `[ecx]`, `[ecx+4]`, and `[ecx+8]`; IDA function inventory confirms the parser/accessor/helper starts from `0x0045c260` through `0x0045d740`; packet handler `0x00459210` calls the parser methods for ranking opcode `0x7d`.

### 2026-06-04 - Parent and live-boundary update

- Before: scored `82/86`, but `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, leaving the class unclassified in generated coverage.
- Changed to: scored `84/88`, marked `RECONSTRUCTABLE:TRUE`, and attached to [UID:0000MZ][RankingDialog](by-file/RankingDialog.md).
- Summary/evidence: live IDA MCP reverified exact half-open ranges for every listed method/helper, constructor/destructor call sites, opcode `0x7d` parser dispatch, selected-id/count/index accessor bodies, 688-byte category-record stride, and 76-byte user-entry vector growth behavior. Final C++ remains blank because final parser/helper names and source abstraction choices are not 95+.
