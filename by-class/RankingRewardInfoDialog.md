*** UID:0000BP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RankingRewardInfoDialog

## Status

- Likely source file: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Address range: [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- Exact class core: [UID:0001ZG][0x0045dba0-0x0045f12c.RankingRewardInfoDialogCore](by-memory/0x0045dba0-0x0045f12c.RankingRewardInfoDialogCore.md)
- Autogen parent: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md).
- Confidence: strong for dialog purpose, packet handler, reward-entry layout, and internal reward container helpers.

## Class Purpose

`RankingRewardInfoDialog` is the modal reward-detail dialog opened from the main ranking window. It requests reward info for the selected category, parses reward rows, draws rank/reward/item reward columns, and tracks its own active singleton.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `RankingRewardInfoDialog` | `0x0045dba0-0x0045dd55` | Constructs dialog, stores [UID:0000S3][g_pRankingRewardInfoDialog](by-global/g_pRankingRewardInfoDialog.md), adds OK button, requests reward info with opcode `0x7d` subcommand `5`, and slides open. |
| `OnClose` | `0x0045dda0-0x0045ddc1` | Closes/dismisses dialog when button id `0` is used. |
| `HandleRewardInfoPacket` | [UID:0001ZH][0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler](by-memory/0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler.md) | Parses opcode `0x7d`, subcommand `5` reward-info response. |
| `OnPaint` | `0x0045df90-0x0045ea12` | Draws `WEBBOARD` frame/background, reward table headers, rank ranges, symbol icons, and item rewards. |
| `ParseRewardEntry` / accessors | [UID:0001ZF][0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors](by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md) | Parses one reward entry and exposes rank/symbol text fields. |
| `RewardVectorStorageHelpers` | [UID:0001ZI][0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers](by-memory/0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers.md) | Appends/clones reward entries and nested item vectors. |
| `ClearSingletonHelper` | `0x0045efe0-0x0045efeb` | Constructor-unwind helper that clears [UID:0000S3][g_pRankingRewardInfoDialog](by-global/g_pRankingRewardInfoDialog.md). |
| `RewardContainerDestroy` | [UID:0001ZK][0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy](by-memory/0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy.md) | Frees nested reward entry/item vectors. |
| `AdjustorThunks` | `0x0045f0a8-0x0045f0bd` | Compiler-generated destructor adjustor thunks for the secondary and tertiary vtable views. |
| `ScalarDeletingDestructor` | `0x0045f0c0-0x0045f12b` | Destroys reward container, clears singleton, tears down dialog, and optionally frees storage. |
| `RewardVectorRangeAllocationHelpers` | [UID:0001ZJ][0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers](by-memory/0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers.md) | Range destroy/deep-copy and item-vector allocation/free support. |

## Data Notes

- `g_pRankingRewardInfoDialog` is `dword_67A7E8` at `0x0067a7e8`.
- Reward entries are 560-byte records: `rankStart[8]` at `+0x00`, `rankEnd[8]` at `+0x10`, `symbolText[256]` at `+0x20`, symbol bytes at `+0x220/+0x221`, and an item-vector triplet at `+0x224`.
- Item reward rows are 520-byte records containing `name[256]`, quantity, icon id, and palette/index.
- Item reward rows draw item icons through `g_pItemObjImageLib` and labels formatted as `%s(%d)`.
- IDA confirms primary, secondary, and tertiary vtables at `0x00610bc4`, `0x00610c24`, and `0x00610c54`.
- Use the exact `by-memory` pages above for reconstruction of the packet-handler, parser, and storage helper bodies.

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000BM][RankingDialog](by-class/RankingDialog.md)
- [UID:0000BK][RankingCategoryCollection](by-class/RankingCategoryCollection.md)
- [UID:0001ZG][0x0045dba0-0x0045f12c.RankingRewardInfoDialogCore](by-memory/0x0045dba0-0x0045f12c.RankingRewardInfoDialogCore.md)
- [UID:0001ZF][0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors](by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md)
- [UID:0001ZH][0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler](by-memory/0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler.md)
- [UID:0001ZI][0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers](by-memory/0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers.md)
- [UID:0001ZK][0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy](by-memory/0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy.md)
- [UID:0001ZJ][0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers](by-memory/0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers.md)
- [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md)
- [UID:0000YA][0x0045efe0-0x0045efeb.RankingRewardInfoDialogClearSingletonHelper](by-memory/0x0045efe0-0x0045efeb.RankingRewardInfoDialogClearSingletonHelper.md)
- [UID:0000YB][0x0045f0a8-0x0045f0bd.RankingRewardInfoDialogAdjustorThunks](by-memory/0x0045f0a8-0x0045f0bd.RankingRewardInfoDialogAdjustorThunks.md)
- [UID:0001RK][ranking-ui-resources](by-resource/ranking-ui-resources.md)

## Changes

### 2026-06-04 - Parent assignment and stale source cleanup

- Before: class score was already `84/88`, but reconstructable/autogen metadata was blank and the page still referenced stale recovered-source artifacts.
- Changed to: marked reconstructable, attached to [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), and removed stale recovered-source wording without changing the score.
- Summary/evidence: live IDA reconfirmed [UID:0001ZF][0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors](by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md) as ranking reward-info behavior called from the opcode `0x7d` subcommand `5` packet handler.

### 2026-05-30 - Grading update

- Before: this class had exact packet/parser/storage memory coverage and data layout notes but remained unevaluated by the completion/confidence header.
- Changed to: score is now `84/88`, reflecting documented dialog construction/close/paint/destructor, opcode `0x7d` subcommand `5` handler, reward-entry/item layout, vtables, globals, and nested vector storage helpers.
- Summary/evidence: linked memory pages record the core dialog range, reward-entry parser/accessors, packet handler, vector storage, vector destroy, range allocation helpers, 560-byte reward records, and 520-byte item rows.

### 2026-05-27 - Added exact packet/parser/storage memory coverage

- Before: the class listed `HandleRewardInfoPacket` and reward containers by address only, and did not identify that active generated source omits the packet-handler and helper bodies.
- Changed to: linked exact memory pages for the core class range, reward-entry parser/accessors, packet handler, vector storage helpers, reward-entry vector destroy helper, and range allocation helpers.
- Summary/evidence: IDA confirms the `0x0045ddd0` opcode `0x7d` subcommand `5` handler, parser call to `0x0045d7e0`, 560-byte reward-entry records, 520-byte item rows, and nested-vector deep-copy/destruction helpers through `0x0045f33a`.
