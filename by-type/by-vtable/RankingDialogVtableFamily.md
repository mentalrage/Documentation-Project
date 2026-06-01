*** UID:0001YJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RankingDialog Vtable Family

## Status

- Confidence: strong for addresses, slot boundaries, and constructor/destructor store evidence.
- Source owner: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Classes covered: [UID:0000BM][RankingDialog](by-class/RankingDialog.md), [UID:0000BN][RankingEventListPane](by-class/RankingEventListPane.md), [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md), and [UID:0000BQ][RankingUserListPane](by-class/RankingUserListPane.md)
- Companion page: [UID:0001YK][RankingEventScrollPaneVtables](by-type/by-vtable/RankingEventScrollPaneVtables.md)
- Exact read-only-data child: [UID:0002ON][0x00610980-0x00610e38.RankingDialogReadOnlyData](by-memory/0x00610980-0x00610e38.RankingDialogReadOnlyData.md)

## Vtable Inventory

| Class / subobject | Vtable address | Key slots |
| --- | --- | --- |
| `RankingDialog` primary | `0x00610984` | `+0x00` -> `0x00459840` scalar deleting destructor; `+0x44` -> `0x00458b50` paint; `+0x48` -> `0x00458a10` button/action handler. |
| `RankingDialog` secondary `+0xa0` | `0x006109e4` | `+0x00` -> `0x0045981b` adjustor thunk; `+0x10` -> `0x00459210` ranking opcode `0x7d` packet handler. |
| `RankingDialog` tertiary `+0xa4` | `0x00610a14` | `+0x00` -> `0x00459826` adjustor thunk; `+0x04` -> `0x00459330` modal predicate. |
| `RankingEventListPane` primary | `0x00610ad4` | `+0x00` -> `0x0045be00` scalar deleting destructor; `+0x0c` -> `0x0045af70` resize; `+0x2c` -> `0x0045b000` origin update; `+0x30` -> `0x0045b250` insert; `+0x38` -> `0x0045b2c0` detach; `+0x44` -> `0x0045b2e0` paint. |
| `RankingEventListPane` secondary `+0xa0` | `0x00610b3c` | `+0x00` -> `0x0045bddd` adjustor thunk; `+0x04` -> `0x0045b460` mouse/wheel event handler; `+0x08` -> `0x0045b450` focus predicate. |
| `RankingEventListPane` tertiary `+0xa4` | `0x00610b6c` | `+0x00` -> `0x0045bde8` adjustor thunk; `+0x04` -> inherited/default `0x00544e90`. |
| `RankingRewardInfoDialog` primary | `0x00610bc4` | `+0x00` -> `0x0045f0c0` scalar deleting destructor; `+0x44` -> `0x0045df90` paint; `+0x48` -> `0x0045dda0` close action. |
| `RankingRewardInfoDialog` secondary `+0xa0` | `0x00610c24` | `+0x00` -> `0x0045f0a8` adjustor thunk; `+0x10` -> `0x0045ddd0` reward-info packet handler. |
| `RankingRewardInfoDialog` tertiary `+0xa4` | `0x00610c54` | `+0x00` -> `0x0045f0b3` adjustor thunk; `+0x04` -> inherited/default `0x00544e90`. |
| `RankingUserListPane` primary | `0x00610cd0` | `+0x00` -> `0x0045f9a0` scalar deleting destructor; `+0x44` -> `0x0045f3a0` paint. |
| `RankingUserListPane` secondary `+0xa0` | `0x00610d38` | `+0x00` -> `0x0045f97d` adjustor thunk. |
| `RankingUserListPane` tertiary `+0xa4` | `0x00610d68` | `+0x00` -> `0x0045f988` adjustor thunk; `+0x04` -> inherited/default `0x00544e90`. |

The short tertiary tables stop before adjacent UTF-16 resource and label strings. Do not extend these tables into the following data:

- `0x00610a1c` -> `RewardInfo`, and `0x00610a34` -> `GetReward`.
- `0x00610b74` -> `SUBWIN.EPF`, and `0x00610b8c` -> `SUBWIN.PAL`.
- `0x00610c5c` -> `Rank`, `0x00610c68` -> `Reward Legend`, `0x00610c84` -> `Reward Items`, `0x00610ca4` -> `SYMBOLS.EPF`, and `0x00610cbc` -> `%s(%d)`.
- `0x00610d70` -> `Total : %d`, `0x00610d88` -> `From : %02d/%02d/%04d %02d:%02d:%02d`, `0x00610dd8` -> `To : %02d/%02d/%04d %02d:%02d:%02d`, `0x00610e20` -> `Name`, and `0x00610e2c` -> `Score`.

## IDA Evidence

- 2026-06-01 IDA MCP `py_eval` recheck confirms exact ranking read-only-data bounds `0x00610980-0x00610e38`: `0x00610980` is `??_R4RankingDialog@@6B@`, the first vtable is `0x00610984`, and `0x00610e38` starts adjacent software-blend constants rather than Ranking data.
- IDA names the vtable symbols from `0x00610984` through `0x00610d68`, plus the [UID:0001YK][RankingEventScrollPaneVtables](by-type/by-vtable/RankingEventScrollPaneVtables.md) at `0x00610a4c`, `0x00610a98`, and `0x00610ac8`.
- The same IDA pass confirms the `Name` and `Score` strings at `0x00610e20` and `0x00610e2c` are referenced from `RankingUserListPane` paint/range formatting at `0x0045f5ee` and `0x0045f603`.
- `xrefs_to` confirms constructor and scalar-destructor vtable stores for `RankingDialog`, `RankingEventListPane`, `RankingRewardInfoDialog`, and `RankingUserListPane`.
- `xrefs_to 0x00459210` reports the only direct data reference from `RankingDialog` secondary vtable slot `0x006109f4`; decompilation shows opcode `0x7d` dispatch for subcommands `1`, `2`, `3`, and `6`.
- `lookup_funcs` confirms every listed adjustor thunk as an `0xb`-byte function. Decompilation shows the secondary thunks subtract `0xa0` from `this`, and tertiary thunks subtract `0xa4`, then forward to the owning scalar deleting destructor.
- `0x0045f380` is a small `RankingUserListPane` non-deleting destructor-shaped body that reinstalls the three class vtable pointers and calls the base `Pane` teardown helper `0x00544580`. The scalar deleting destructor `0x0045f9a0` inlines the same vtable reset and base teardown before optional free.

## Generated-Data Caveat

Current `source-3/simroot_v2` metadata reports `vtable_count: 0` for `RankingDialog`, `RankingEventListPane`, `RankingRewardInfoDialog`, `RankingUserListPane`, and `RankingEventScrollPane`. Treat the generated metadata as incomplete for ranking polymorphism and use the IDA-confirmed vtable bases above during source reconstruction.

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- [UID:0000Y0][0x00459810-0x0045981a.RankingDialogClearSingletonHelper](by-memory/0x00459810-0x0045981a.RankingDialogClearSingletonHelper.md)
- [UID:0000Y1][0x0045981b-0x00459830.RankingDialogAdjustorThunks](by-memory/0x0045981b-0x00459830.RankingDialogAdjustorThunks.md)
- [UID:0000Y8][0x0045bddd-0x0045bdf2.RankingEventListPaneAdjustorThunks](by-memory/0x0045bddd-0x0045bdf2.RankingEventListPaneAdjustorThunks.md)
- [UID:0000YA][0x0045efe0-0x0045efeb.RankingRewardInfoDialogClearSingletonHelper](by-memory/0x0045efe0-0x0045efeb.RankingRewardInfoDialogClearSingletonHelper.md)
- [UID:0000YB][0x0045f0a8-0x0045f0bd.RankingRewardInfoDialogAdjustorThunks](by-memory/0x0045f0a8-0x0045f0bd.RankingRewardInfoDialogAdjustorThunks.md)
- [UID:0000YC][0x0045f97d-0x0045f992.RankingUserListPaneAdjustorThunks](by-memory/0x0045f97d-0x0045f992.RankingUserListPaneAdjustorThunks.md)
- [UID:0002ON][0x00610980-0x00610e38.RankingDialogReadOnlyData](by-memory/0x00610980-0x00610e38.RankingDialogReadOnlyData.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-06-01:
  - Before: the page had stale `0/0` metadata and described the ranking string tail only through the `To : ...` date format at `0x00610dd8`.
  - Changed to: marked the page reconstructable at `84/90`, linked exact child [UID:0002ON][0x00610980-0x00610e38.RankingDialogReadOnlyData](by-memory/0x00610980-0x00610e38.RankingDialogReadOnlyData.md), added the `Name`/`Score` tail strings, and recorded the exact `0x00610980` start / `0x00610e38` end.
  - Summary/evidence: IDA MCP `py_eval` on 2026-06-01 confirmed the RTTI/vtable bases, constructor/destructor store xrefs, string references, and the following software-blend constant boundary.
