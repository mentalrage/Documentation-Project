*** UID:0001YJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RankingDialog Vtable Family

## Status

- Confidence: very strong for addresses, slot boundaries, constructor/destructor stores, and the exact RankingDialog primary `+0x48` `OnControlCommand(int,int)` contract; original private lexical names elsewhere in the family remain a bounded uncertainty.
- Source owner: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Rebuild handling: `source-declared/generated-binary`
- Autogen parent: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Classes covered: [UID:0000BM][RankingDialog](by-class/RankingDialog.md), [UID:0000BN][RankingEventListPane](by-class/RankingEventListPane.md), [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md), and [UID:0000BQ][RankingUserListPane](by-class/RankingUserListPane.md)
- Companion page: [UID:0001YK][RankingEventScrollPaneVtables](by-type/by-vtable/RankingEventScrollPaneVtables.md)
- Exact read-only-data child: [UID:0002ON][0x00610980-0x00610e38.RankingDialogReadOnlyData](by-memory/0x00610980-0x00610e38.RankingDialogReadOnlyData.md)

## Assignment Decision

`AUTOGEN_PARENT_UID` is set to [UID:0000MZ][RankingDialog](by-file/RankingDialog.md). This vtable-family page clears the corrected child-side gate at `86/92`, and the direct source-file parent clears the parent-side gate at `88/91`.

The direct parent is the source file, not an individual class page. The page intentionally covers four sibling private ranking UI classes (`RankingDialog`, `RankingEventListPane`, `RankingRewardInfoDialog`, and `RankingUserListPane`) in one contiguous ranking read-only-data island, while [UID:0001YK][RankingEventScrollPaneVtables](by-type/by-vtable/RankingEventScrollPaneVtables.md) remains the separate companion page for the scroll-pane vtables. All covered vtable sets route through the same [UID:0000MZ][RankingDialog](by-file/RankingDialog.md) feature module, so this is a file-level vtable declaration family rather than a mixed-owner aggregate.

## Vtable Inventory

| Class / subobject | Vtable address | Key slots |
| --- | --- | --- |
| `RankingDialog` primary | `0x00610984` | `+0x00` -> `0x00459840` scalar deleting destructor; `+0x44` -> `0x00458b50` paint; `+0x48` cell `0x006109cc` -> `0x00458a10` `void RankingDialog::OnControlCommand(int controlIndex, int notifyCode)`. |
| `RankingDialog` secondary `+0xa0` | `0x006109e4` | `+0x00` -> `0x0045981b` adjustor thunk; `+0x10` -> `0x00459210` ranking opcode `0x7d` packet handler. |
| `RankingDialog` tertiary `+0xa4` | `0x00610a14` | `+0x00` -> `0x00459826` adjustor thunk; `+0x04` -> `0x00459330` modal predicate. |
| `RankingEventListPane` primary | `0x00610ad4` | `+0x00` -> `0x0045be00` scalar deleting destructor; `+0x0c` -> `0x0045af70` resize; `+0x2c` -> `0x0045b000` origin update; `+0x30` -> `0x0045b250` insert; `+0x38` -> `0x0045b2c0` detach; `+0x44` -> `0x0045b2e0` paint. |
| `RankingEventListPane` secondary `+0xa0` | `0x00610b3c` | `+0x00` -> `0x0045bddd` adjustor thunk; `+0x04` -> `0x0045b460` mouse/wheel event handler; `+0x08` -> `0x0045b450` focus predicate. |
| `RankingEventListPane` tertiary `+0xa4` | `0x00610b6c` | `+0x00` -> `0x0045bde8` adjustor thunk; `+0x04` -> inherited/default `0x00544e90`. |
| `RankingRewardInfoDialog` primary | `0x00610bc4` | `+0x00` -> `0x0045f0c0` scalar deleting destructor; `+0x44` -> `0x0045df90` paint; `+0x48` -> `0x0045dda0` close action. |
| `RankingRewardInfoDialog` secondary `+0xa0` | `0x00610c24` | `+0x00` -> `0x0045f0a8` adjustor thunk; `+0x10` -> [UID:0001ZH][0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler](by-memory/0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler.md), source-emitting `HandlePacketEvent(Event *event)`. |
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

- 2026-06-11 A002 IDA MCP `py_eval` reconfirmed exact range `0x00610980-0x00610e38` with size `0x4b8`; the first covered vtable remains `??_7RankingDialog@@6B@` at `0x00610984`, and the next eight bytes at `0x00610e38` are `de7bde7bde7bde7b`, the adjacent software-blend constants.
- The same 2026-06-11 pass reconfirmed slot-zero destructor/thunk targets for every covered Ranking family vtable: `0x00459840` / `0x0045981b` / `0x00459826`, `0x0045be00` / `0x0045bddd` / `0x0045bde8`, `0x0045f0c0` / `0x0045f0a8` / `0x0045f0b3`, and `0x0045f9a0` / `0x0045f97d` / `0x0045f988`.
- Representative 2026-06-11 xrefs still tie the vtable bases to constructor/destructor stores: `0x00610984` from `0x00458610` and `0x00459840`, `0x00610ad4` from `0x0045ae30` and `0x0045be00`, `0x00610bc4` from `0x0045dba0` and `0x0045f0c0`, and `0x00610cd0` from `0x0045f340`, `0x0045f380`, and `0x0045f9a0`.
- 2026-06-01 IDA MCP `py_eval` recheck confirms exact ranking read-only-data bounds `0x00610980-0x00610e38`: `0x00610980` is `??_R4RankingDialog@@6B@`, the first vtable is `0x00610984`, and `0x00610e38` starts adjacent software-blend constants rather than Ranking data.
- IDA names the vtable symbols from `0x00610984` through `0x00610d68`, plus the [UID:0001YK][RankingEventScrollPaneVtables](by-type/by-vtable/RankingEventScrollPaneVtables.md) at `0x00610a4c`, `0x00610a98`, and `0x00610ac8`.
- The same IDA pass confirms the `Name` and `Score` strings at `0x00610e20` and `0x00610e2c` are referenced from `RankingUserListPane` paint/range formatting at `0x0045f5ee` and `0x0045f603`.
- `xrefs_to` confirms constructor and scalar-destructor vtable stores for `RankingDialog`, `RankingEventListPane`, `RankingRewardInfoDialog`, and `RankingUserListPane`.
- `xrefs_to 0x00459210` reports the only direct data reference from `RankingDialog` secondary vtable slot `0x006109f4`; decompilation shows opcode `0x7d` dispatch for subcommands `1`, `2`, `3`, and `6`.
- Accepted UID0004ZM session `b3b2bf88` reconfirmed that primary cell `0x006109cc` is the sole inbound data xref to `[0x00458a10,0x00458b33)`. The target returns with stack cleanup for two arguments and switches on the first, matching the established `DialogPane` primary `+0x48` `OnControlCommand(int,int)` contract rather than the historical generic `OnButtonClick`/button-action label.
- `OnControlCommand` case `6` at `0x00458ac4-0x00458b17` contains the exact compiler-inlined call-site semantics of private [UID:0004ZM][0x00459580-0x004595f3.RankingDialogRawRewardClaimRequestHelper](by-memory/0x00459580-0x004595f3.RankingDialogRawRewardClaimRequestHelper.md) `RequestRewardClaim()`. The retained out-of-line child owns the source definition; the vtable and inline copy do not emit separate handwritten code.
- `lookup_funcs` confirms every listed adjustor thunk as an `0xb`-byte function. Decompilation shows the secondary thunks subtract `0xa0` from `this`, and tertiary thunks subtract `0xa4`, then forward to the owning scalar deleting destructor.
- `0x0045f380` is a small `RankingUserListPane` non-deleting destructor-shaped body that reinstalls the three class vtable pointers and calls the base `Pane` teardown helper `0x00544580`. The scalar deleting destructor `0x0045f9a0` inlines the same vtable reset and base teardown before optional free.

## RankingDialog RTTI Hierarchy And UID0000Y0

- RankingDialog's primary complete-object locator at `0x00610980` points into its RTTI family. The class hierarchy descriptor at `0x00641ae0` records multiple inheritance with eight entries: `RankingDialog`, `DialogPane`, `Pane`, `GrafPort`, `LObject`, `EventHandler`, `TimerHandler`, and original decorated type `.?AV?$Singleton@VRankingDialog@@@@`.
- The `Singleton<RankingDialog>` base-class descriptor is `0x00641b30`, referenced from base-array cell `0x00641b0c`. It is direct/non-virtual with `mdisp=620/0x26c`, `pdisp=-1`, `vdisp=0`, and attributes `0x40`.
- The category collection begins at the same `+0x26c` through empty-base optimization. Constructor order publishes through the Singleton base before category construction; EH order destroys the category member before state-1 Singleton destruction. This proves a base/member overlap, not an added guard field.
- Constructor `FuncInfo 0x006589ac` and unwind map `0x006589d0` route state `1` action `0x005fa138` through adjusted receiver `+0x26c` and tail-jump `0x005fa141` to non-emitting [UID:0000Y0][0x00459810-0x0045981a.RankingDialogSingletonBaseDestructor](by-memory/0x00459810-0x0045981a.RankingDialogSingletonBaseDestructor.md). UID0000Y0 is not a vtable slot, adjustor thunk, ordinary class method, or the EH funclet itself.
- The primary/secondary/tertiary vtables continue to route scalar wrapper `0x00459840` and adjustors `0x0045981b/0x00459826`; they do not route UID0000Y0. The target has no vtable/function-pointer data reference and remains compiler-instantiated from the source-visible Singleton base contract.
- `Singleton<RankingRewardInfoDialog>` has the same `+0x26c` direct-base displacement and an analogous EH-only 11-byte clear specialization. It is comparator evidence only; UID0000YA and all reward vtable slots remain unchanged.
- At the 2026-07-13 UID0000Y0 synchronization, vtable-family score `85/90`, owner/emitter UID0000MZ, reconstructable state, complete slot inventory, and blank formal block were unchanged. The later UID0004ZM pass raises the current page to `86/92` for the exact primary command contract while preserving that RTTI/source-disposition evidence.

## Generated-Data Caveat

Current `source-3/simroot_v2` metadata reports `vtable_count: 0` for `RankingDialog`, `RankingEventListPane`, `RankingRewardInfoDialog`, `RankingUserListPane`, and `RankingEventScrollPane`. Treat the generated metadata as incomplete for ranking polymorphism and use the IDA-confirmed vtable bases above during source reconstruction.

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- [UID:0000Y0][0x00459810-0x0045981a.RankingDialogSingletonBaseDestructor](by-memory/0x00459810-0x0045981a.RankingDialogSingletonBaseDestructor.md)
- [UID:0000Y1][0x0045981b-0x00459830.RankingDialogAdjustorThunks](by-memory/0x0045981b-0x00459830.RankingDialogAdjustorThunks.md)
- [UID:0000Y8][0x0045bddd-0x0045bdf2.RankingEventListPaneAdjustorThunks](by-memory/0x0045bddd-0x0045bdf2.RankingEventListPaneAdjustorThunks.md)
- [UID:0000YA][0x0045efe0-0x0045efeb.RankingRewardInfoDialogClearSingletonHelper](by-memory/0x0045efe0-0x0045efeb.RankingRewardInfoDialogClearSingletonHelper.md)
- [UID:0000YB][0x0045f0a8-0x0045f0bd.RankingRewardInfoDialogAdjustorThunks](by-memory/0x0045f0a8-0x0045f0bd.RankingRewardInfoDialogAdjustorThunks.md)
- [UID:0000YC][0x0045f97d-0x0045f992.RankingUserListPaneAdjustorThunks](by-memory/0x0045f97d-0x0045f992.RankingUserListPaneAdjustorThunks.md)
- [UID:0002ON][0x00610980-0x00610e38.RankingDialogReadOnlyData](by-memory/0x00610980-0x00610e38.RankingDialogReadOnlyData.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

### 2026-08-02 - B001 UID0004ZM primary-slot source-contract sync

- Raised `85/90 -> 86/92`; preserved owner/emitter UID0000MZ, reconstructable true, all vtable addresses/bounds/RTTI/string boundaries, and blank compiler-generated formal CPP/H.
- Replaced the generic RankingDialog primary `+0x48` button/action label with exact cell `0x006109cc -> 0x00458a10`, source signature `void RankingDialog::OnControlCommand(int controlIndex, int notifyCode)`.
- Added the sole vtable xref, two-argument stack cleanup/dispatch evidence, and case-6 relationship to source-emitting UID0004ZM `RequestRewardClaim()` without changing any unrelated slot.

### 2026-07-13 - B004 UID0000Y0 RTTI/source-disposition sync

- Preserved `85/90`, owner/emitter UID0000MZ, reconstructable true, blank formal C++, all vtable addresses/slots/string boundaries, UID0000Y1 adjustors, and UID0000YA comparator state.
- Added primary COL/CHD/base-array evidence, original `Singleton<RankingDialog>` RTTI identity, BCD `0x00641b30` at `+0x26c`, EBO ordering, constructor-EH adjusted receiver route, and the proof that renamed UID0000Y0 is non-emitting base-destructor support rather than a slot/helper/adjustor.

### 2026-07-12 - B002 UID0001ZH packet-slot source closure

- Linked the `RankingRewardInfoDialog +0xa0` secondary vtable `+0x10` cell directly to source-emitting UID0001ZH and the accepted EventHandler signature `HandlePacketEvent(Event *event)`.
- Current MCP database `cfa0ae1a` reconfirmed the sole data xref `0x00610c34 -> 0x0045ddd0`; vtable-family metadata and all other slots remain unchanged.

### 2026-07-12 - B002 UID0001ZG exact child links

- Added exact source-child links for [UID:0004I9][0x0045dda0-0x0045ddc2.RankingRewardInfoDialogOnDialogAction](by-memory/0x0045dda0-0x0045ddc2.RankingRewardInfoDialogOnDialogAction.md) and [UID:0004IA][0x0045df90-0x0045ea13.RankingRewardInfoDialogOnPaint](by-memory/0x0045df90-0x0045ea13.RankingRewardInfoDialogOnPaint.md), plus non-emitting [UID:0004IE][0x0045f0c0-0x0045f12c.RankingRewardInfoDialogScalarDeletingDestructor](by-memory/0x0045f0c0-0x0045f12c.RankingRewardInfoDialogScalarDeletingDestructor.md).
- The existing slot map remains exact: primary `0x00610bc4` routes `+0x00/+0x44/+0x48` to wrapper/paint/action, secondary `0x00610c24` routes packet handling, and inherited DialogPane supplies the secondary/tertiary views. Score and metadata are unchanged; stale Wave3 material was not used.

- 2026-06-11 A002 assignment pass:
  - Before: the page was `84/90`, reconstructable, and documented strong vtable evidence, but remained unassigned.
  - Changed to: raised completion to `85`, set `AUTOGEN_PARENT_UID:0000MZ`, added the file-level assignment rationale, and recorded a fresh live IDA check.
  - Summary/evidence: IDA MCP `py_eval` reconfirmed the `0x00610980-0x00610e38` / `0x4b8` bounds, slot-zero targets for the RankingDialog/EventList/RewardInfo/UserList vtables, constructor/destructor store xrefs, and the `0x00610e38` render-constant boundary. The page attaches to [UID:0000MZ][RankingDialog](by-file/RankingDialog.md) because the family spans sibling private classes under one source module rather than one class owner, and both child `85/90` and parent `85/86` clear the strict gate.
- 2026-06-01:
  - Before: the page had stale `0/0` metadata and described the ranking string tail only through the `To : ...` date format at `0x00610dd8`.
  - Changed to: marked the page reconstructable at `84/90`, linked exact child [UID:0002ON][0x00610980-0x00610e38.RankingDialogReadOnlyData](by-memory/0x00610980-0x00610e38.RankingDialogReadOnlyData.md), added the `Name`/`Score` tail strings, and recorded the exact `0x00610980` start / `0x00610e38` end.
  - Summary/evidence: IDA MCP `py_eval` on 2026-06-01 confirmed the RTTI/vtable bases, constructor/destructor store xrefs, string references, and the following software-blend constant boundary.
