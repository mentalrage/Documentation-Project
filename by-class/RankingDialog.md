*** UID:0000BM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RankingDialog

## Status

- Likely source file: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Address range: [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- Current recovered file: `source-3/simroot_v2/class_RankingDialog.cpp`
- Confidence: strong for core methods, packet dispatch, vtables, and file placement; medium for current generated-source cleanliness because unrelated helpers are still emitted in the same generated file.

## Class Purpose

`RankingDialog` is the main in-game ranking board dialog. It creates the close, event-list, user-list, page navigation, reward-info, and reward-claim controls; tracks selected ranking category and current page; sends ranking request packets; and owns the active ranking singleton.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `RankingDialog` | `0x00458610-0x0045894a` | Constructs the dialog, child controls, category collection, and sends initial opcode `0x7d` subcommand `3`. |
| `SetSelectedCategory` | `0x00458990-0x00458a09` | Changes category, resets page state, refreshes buttons, requests the first page, and clears user list display. |
| `OnButtonClick` | `0x00458a10-0x00458b32` | Handles close, previous/next page, reward-info open, and reward-claim request. |
| `OnPaint` | `0x00458b50-0x0045920d` | Draws the `WBOARDBK` background and `WEBBOARD` frame tiles. |
| `HandleRankingPacket` | `0x00459210-0x00459317` | Secondary-vtable packet handler for opcode `0x7d`, dispatching category/page/reward subcommands. |
| `IsModal` | `0x00459330-0x00459334` | Returns true. |
| `GetControlLayout` | `0x00459340-0x0045943b` | File-local helper that returns rectangles for the seven controls. |
| `RequestRankingPage` | `0x004594d0-0x0045957d` | Sends opcode `0x7d`, subcommand `2`, selected category id, and rank range for the current page. |
| `UpdateButtonStates` | `0x004597b0-0x00459803` | Invalidates navigation/reward buttons after category or page changes. |
| `ClearSingletonHelper` | `0x00459810-0x0045981a` | Constructor-unwind helper that clears [UID:0000S2][g_pRankingDialog](by-global/g_pRankingDialog.md). |
| `AdjustorThunks` | `0x0045981b-0x00459830` | Compiler-generated destructor adjustor thunks for the secondary and tertiary vtable views. |
| `ScalarDeletingDestructor` | `0x00459840-0x004598ab` | Destroys category collection, clears [UID:0000S2][g_pRankingDialog](by-global/g_pRankingDialog.md), tears down `DialogPane`, and optionally frees storage. |

## Data And Controls

- `g_pRankingDialog` is `dword_67A7E4` at `0x0067a7e4`.
- The embedded category collection begins at dialog offset `+0x26c` in IDA decompilation (`this + 620`).
- `+0x27c` and `+0x280` are current page and max page in current generated source.
- Child control ids are close `0`, event list `1`, user list `2`, previous page `3`, next page `4`, reward-info `5`, and reward-claim `6`.

## Open Questions

- Generated `class_RankingDialog.cpp` includes unrelated methods at `0x0046e2a0`, `0x0046e640`, `0x0046eaa0`, `0x0049eac0`, `0x0049eb90`, `0x0049ee50`, `0x0049ef60`, `0x004add40`, `0x004ade60`, `0x004fee40`, `0x00516510`, `0x00516670`, `0x00516dd0`, `0x00516e50`, and `0x00544710`; these should be re-owned before source migration. The `0x0046e2a0`, `0x0046e640`, and `0x0046eaa0` functions are now documented as [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md) code, and the `0x0049eac0-0x0049f07e` animation helpers are documented as [UID:00012U][0x0049eac0-0x0049f07e.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f07e.DialogPaneSlideAnimation.md) code.
- The packet response handlers that populate categories and user rows are currently attached mainly to `RankingCategoryCollection` and `RankingRewardInfoDialog`; final naming should make the dispatch path explicit.
- Current generated metadata reports `vtable_count: 0`, but IDA confirms primary, secondary, and tertiary `RankingDialog` vtables. Use [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md) as the source of truth.
- 2026-05-26 IDA `py_eval` recheck confirms the main `RankingDialog` method boundaries from constructor `0x00458610-0x0045894b` through scalar deleting destructor `0x00459840-0x004598ac`. It also reconfirms vtable bases `0x00610984`, `0x006109e4`, and `0x00610a14` with stores from the constructor/destructor, and confirms packet handler `0x00459210` is referenced from secondary vtable slot `0x006109f4`.

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000BN][RankingEventListPane](by-class/RankingEventListPane.md)
- [UID:0000BQ][RankingUserListPane](by-class/RankingUserListPane.md)
- [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md)
- [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md)
- [UID:0000Y0][0x00459810-0x0045981a.RankingDialogClearSingletonHelper](by-memory/0x00459810-0x0045981a.RankingDialogClearSingletonHelper.md)
- [UID:0000Y1][0x0045981b-0x00459830.RankingDialogAdjustorThunks](by-memory/0x0045981b-0x00459830.RankingDialogAdjustorThunks.md)
- [UID:00012U][0x0049eac0-0x0049f07e.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f07e.DialogPaneSlideAnimation.md)
- [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `82/86`.
  - Before: page documented core ranking dialog methods, controls, globals, packet dispatch, vtables, and owner-pollution caveats but remained unevaluated.
  - After: score reflects documented constructor, selection, button, paint, packet-handler, layout, request, singleton, and destructor behavior, with generated-source pollution still called out as the main caveat.
  - Evidence: linked aggregate [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md) records IDA-confirmed method boundaries, vtable bases/stores, opcode `0x7d` packet-handler slot, and non-ranking helper exclusions.
