*** UID:0000BM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

# RankingDialog

## Status

- Likely source file: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Address range: [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- Current recovered file: `source-3/simroot_v2/class_RankingDialog.cpp`
- Confidence: very strong for core methods, packet dispatch, vtables, singleton lifecycle, file placement, and the `OnControlCommand`/`RequestRewardClaim` source relationship; medium-high for final generated-source cleanliness because unrelated helpers are documented but not yet fully removed from current generated output.

## Class Purpose

`RankingDialog` is the main in-game ranking board dialog. It creates the close, event-list, user-list, page navigation, reward-info, and reward-claim controls; tracks selected ranking category and current page; sends ranking request packets; and owns the active ranking singleton.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `RankingDialog` | `0x00458610-0x0045894a` | Constructs the dialog, child controls, category collection, and sends initial opcode `0x7d` subcommand `3`. |
| `SetSelectedCategory` | `0x00458990-0x00458a09` | Changes category, resets page state, refreshes buttons, requests the first page, and clears user list display. |
| `OnControlCommand(int controlIndex, int notifyCode)` | `0x00458a10-0x00458b32` | Primary `DialogPane` vtable `+0x48` override. It handles close, previous/next page, reward-info open, and reward-claim request; case `6` contains the compiler-inlined call-site body for private `RequestRewardClaim()`. |
| `OnPaint` | `0x00458b50-0x0045920d` | Draws the `WBOARDBK` background and `WEBBOARD` frame tiles. |
| `HandleRankingPacket` | `0x00459210-0x00459317` | Secondary-vtable packet handler for opcode `0x7d`, dispatching category/page/reward subcommands. |
| `RankingCategoryCollection::ApplyRewardClaimStatusResponse` | [UID:0003WU][0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse](by-memory/0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse.md) | Dispatcher case `6` response handler: reads category id from packet `+2`, requires a nonzero result/status byte at `+6`, marks the first matching category record state `1`, then returns to the dialog dispatcher for button refresh. |
| `IsModal` | `0x00459330-0x00459334` | Returns true. |
| `GetControlLayout` | `0x00459340-0x0045943b` | File-local helper that returns rectangles for the seven controls. |
| `RequestRankingPage` | `0x004594d0-0x0045957d` | Sends opcode `0x7d`, subcommand `2`, selected category id, and rank range for the current page. |
| `RequestRewardClaim` | [UID:0004ZM][0x00459580-0x004595f3.RankingDialogRawRewardClaimRequestHelper](by-memory/0x00459580-0x004595f3.RankingDialogRawRewardClaimRequestHelper.md) | Source-ready private method at `92/94`. It selects `m_categories.GetSelectedRecord()`, returns on null, builds exact request `0x7d/6/BE32 category id/zero`, and sends six bytes through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md). The exact child owns formal CPP; the compiler inlined its visible case-6 call while retaining this out-of-line body. Validator-assigned UID0004ZM belongs to this exact path; copied UID000420 is rejected because it remains canonically assigned to MapPane. |
| `RawPreviousPageHelper` | UID000422 [0x00459600-0x00459623.RankingDialogRawPreviousPageHelper](by-memory/0x00459600-0x00459623.RankingDialogRawPreviousPageHelper.md) | Raw no-function helper that decrements current page when positive, calls `RequestRankingPage`, and tail-jumps to action-button invalidation; formal C++ blank pending source-shape route. |
| `RawNextPageHelper` | UID000424 [0x00459630-0x00459655.RankingDialogRawNextPageHelper](by-memory/0x00459630-0x00459655.RankingDialogRawNextPageHelper.md) | Raw no-function helper that increments current page when below max page, calls `RequestRankingPage`, and tail-jumps to action-button invalidation; formal C++ blank pending source-shape route. |
| `UpdateMaxPageFromSelectedRecord` | UID000425 [0x00459660-0x004596a1.RankingDialogUpdateMaxPageFromSelectedRecord](by-memory/0x00459660-0x004596a1.RankingDialogUpdateMaxPageFromSelectedRecord.md) | Live modeled helper called from packet subcommands `2` and `3`; computes `m_maxPage = max(totalRankCount - 1, 0) / 10` and calls reward/navigation update. First-draft C++ is populated on the exact child page. |
| `UpdateRewardAndNavigationButtons` | [UID:0004YX][0x004596b0-0x004597ae.RankingDialogUpdateRewardAndNavigationButtons](by-memory/0x004596b0-0x004597ae.RankingDialogUpdateRewardAndNavigationButtons.md) | Source-ready exact child at `92/94`. Uses `m_categories.GetSelectedRecord()`, typed controls `3..6`, `GetChild<T>()`, `Enable()`, `Disable()`, `IsEnabled()`, and `m_currentPage/m_maxPage`; the exact method child owns populated formal C++. |
| `InvalidateActionButtons` | UID000427 [0x004597b0-0x00459804.RankingDialogInvalidateActionButtons](by-memory/0x004597b0-0x00459804.RankingDialogInvalidateActionButtons.md) | Invalidates controls `3`, `4`, `5`, and `6` after category, page, or reward-state changes; replaces the older broad `UpdateButtonStates` label. |
| `SingletonBaseDestructor` | [UID:0000Y0][0x00459810-0x0045981a.RankingDialogSingletonBaseDestructor](by-memory/0x00459810-0x0045981a.RankingDialogSingletonBaseDestructor.md) | Non-emitting `source-declared/generated-binary` out-of-line `Singleton<RankingDialog>` base-destructor instantiation used only by constructor EH; not a handwritten class helper. |
| `AdjustorThunks` | `0x0045981b-0x00459830` | Compiler-generated destructor adjustor thunks for the secondary and tertiary vtable views. |
| `ScalarDeletingDestructor` | `0x00459840-0x004598ab` | Destroys category collection, clears [UID:0000S2][g_pRankingDialog](by-global/g_pRankingDialog.md), tears down `DialogPane`, and optionally frees storage. |

## 2026-07-13 B004 Singleton Base Lifetime Disposition

- Original decorated RTTI `.?AV?$Singleton@VRankingDialog@@@@` proves that `RankingDialog` has a direct non-virtual `Singleton<RankingDialog>` base. The primary hierarchy descriptor `0x00641ae0` has eight entries, and base descriptor `0x00641b30` records `mdisp=0x26c`, `pdisp=-1`, `vdisp=0`, attributes `0x40`.
- The empty Singleton base and the category collection both occupy `+0x26c` through empty-base optimization. This is not a stored guard field: constructor order builds/publishes the Singleton base before the collection, and unwind order destroys the collection before the Singleton base.
- Constructor `0x00458610-0x0045894b` records state `0` at `0x00458655`, publishes complete `this` through the `this+0x26c` base at `0x00458666`, performs the adjusted-null fallback clear at `0x0045866d`, and sets state `1` at `0x00458677`. It installs RankingDialog vtables, constructs the category collection at `0x00458695`, and sets state `2` at `0x0045869d`.
- `FuncInfo 0x006589ac` (`0x19930522`, max state `10`, unwind map `0x006589d0`) routes state `0` to lower-base teardown `0x005fa130`, state `1` through action `0x005fa138` and tail-jump `0x005fa141` to UID0000Y0, and state `2` through `0x005fa146/0x005fa14f` to category destruction. UID0000Y0 is the action's callee, not the action funclet itself.
- Ordinary destruction at `0x00458950-0x0045898a` destroys the collection then clears the singleton at `0x0045897a`; scalar wrapper `0x00459840-0x004598ac` does the same at `0x00459866/0x0045986d` before base teardown and delete-flag handling. Together with constructor fallback `0x0045866d` and UID0000Y0 `0x00459810`, these are the only four exact zero-store copies.
- Source contract: preserve `Singleton<RankingDialog>` as a base and [UID:0000S2][g_pRankingDialog](by-global/g_pRankingDialog.md) as the accepted typed storage definition. UID0000Y0 is non-emitting compiler output with semantic class context only; no `ClearSingletonHelper` declaration/body, explicit specialization, manual catch, scope guard, or late-success publication belongs in class source.
- Comparator evidence: `Singleton<RankingRewardInfoDialog>` has the same `+0x26c` base and EH-only 11-byte clear specialization; BrowserDialog research independently records the same template-base pattern. UID0000YA remains a separate unchanged target.
- Class score, owner/emitter route, and blank formal class C++ remain unchanged. Original Singleton header/static-member spelling is not recovered, but that lexical uncertainty does not affect the base identity or lifetime behavior.

## Historical 2026-06-16 C001 Live Evidence Refresh

- Live IDA MCP session `c001_midiplayer_rdata_20260615` reports `NexusTK.exe.i64`, image base `0x00400000`, Hex-Rays ready, and strings cache ready.
- `lookup_funcs` reconfirmed the current class method boundaries: constructor `0x00458610-0x0045894b`, selection `0x00458990-0x00458a0a`, button/action `0x00458a10-0x00458b33`, paint `0x00458b50-0x0045920e`, packet handler `0x00459210-0x00459318`, modal predicate `0x00459330-0x00459335`, control-layout helper `0x00459340-0x0045943c`, request helper `0x004594d0-0x0045957e`, button-state helper `0x004597b0-0x00459804`, clear helper `0x00459810-0x0045981b`, and scalar deleting destructor `0x00459840-0x004598ac`.
- `xrefs_to 0x00459210` reconfirmed the packet handler is vtable-only via secondary slot `0x006109f4`. `analyze_function 0x00459210` reconfirmed opcode `0x7d` dispatch for subcommands `1`, `2`, `3`, and `6`, calling the category parse/update helpers and invalidating the event/user child panes.
- `xrefs_to` for primary/secondary/tertiary vtable bases `0x00610984`, `0x006109e4`, and `0x00610a14` reconfirmed constructor/destructor stores at `0x0045867b`/`0x00458681`/`0x0045868b`, constructor-unwind cleanup stores around `0x00458959`, and scalar deleting destructor stores at `0x0045984c`/`0x00459852`/`0x0045985c`.
- `xrefs_to 0x0067a7e4` reconfirmed all 17 singleton references: constructor publish/fallback clear, constructor-unwind helper clear, scalar destructor clear, ranking child-pane consumers, reward-info/user-list readers, and command dispatcher case `0x005bd27d`.
- At that evidence time, an IDA DB source-quality update recorded `sub_459210 -> RankingDialog_HandleRankingPacket`, `sub_459810 -> RankingDialog_ClearSingletonHelper`, `sub_459840 -> RankingDialog_ScalarDeletingDestructor`, and data name `dword_67A7E4 -> g_pRankingDialog`. The later evidence-time IDB again names UID0000Y0 `sub_459810`; `RankingDialog_ClearSingletonHelper` is retained only as a historical search alias and is superseded by the RTTI-proven Singleton-base identity.
- IDA DB candidates skipped: constructor, paint, button, layout, request, and field/helper local renames were left unchanged because final source signatures and member names for the control collection, packet wrapper, and pane lookup interface still need a broader class-layout pass.

## 2026-06-23 B001 Current MCP Evidence

- Current MCP session `80de0a67` reports active `NexusTK.exe.i64`, Hex-Rays ready, and the same [UID:0000MZ][RankingDialog](by-file/RankingDialog.md) file route.
- `lookup_funcs` confirms modeled helpers `0x00459660` size `0x41`, `0x004596b0` size `0xfe`, and `0x004597b0` size `0x54`. It also confirms raw/no-function starts at `0x00459580`, `0x00459600`, and `0x00459630`.
- `xrefs_to 0x00459660`: calls from `RankingDialog_HandleRankingPacket` at `0x00459281` and `0x004592d5`.
- `xrefs_to 0x004596b0`: calls from `RankingDialog_HandleRankingPacket` at `0x00459309` and from max-page update at `0x0045969a`.
- `xrefs_to 0x004597b0`: calls from constructor, `SetSelectedCategory`, button handler, and raw previous/next helper tail jumps at `0x0045961c` and `0x00459650`.
- Decompilation confirms `0x00459660` recomputes max page from selected record `m_totalRankCount`; `0x004596b0` toggles reward/navigation controls; `0x004597b0` invalidates controls `3`, `4`, `5`, and `6`.
- Packet helper labels are normalized to [UID:0003YJ][0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers](by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md), [UID:0000Q5][g_packetSender](by-global/g_packetSender.md), and [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md). Raw labels such as `dword_67A7EC` remain historical aliases only.

## Reward Claim Source Shape

- Accepted live MCP session `b3b2bf88` resolves `[0x00459580,0x004595f3)` as one retained out-of-line private `RankingDialog::RequestRewardClaim()` definition. The complete `0x73`-byte body uses full-dialog ECX, adjusts to `m_categories +0x26c`, null-checks the selected record, and emits the exact six-byte request.
- The matching case-6 sequence in `OnControlCommand` spans `0x00458ac4-0x00458b17`. It repeats the same receiver adjustment, null guard, opcode/subcommand writers, category-id accessor, BE32 writer, explicit zero, sender global, and six-byte send. The two-write prefix has exactly two matches at `0x00458ad9` and `0x004595a6`.
- Source form is one `OnControlCommand` call to private `RequestRewardClaim()` plus one out-of-line definition. The inlined case body is compiler output and must not be copied as a second handwritten packet body.
- Zero inbound xrefs to raw start/end and zero VA/RVA/raw-offset pointer hits remain valid negative evidence against a surviving ordinary caller, callback, or stored pointer. They no longer justify blank child CPP because the exact inline copy proves the source relationship.
- Ownership remains this class: the category collection supplies selected-record data, while `RankingDialog` owns virtual control dispatch and packet-action policy. Collection ownership, packet-subsystem ownership, file-local free-helper placement, inline-only source, and two handwritten copies are rejected.
- Source-facing name `RequestRewardClaim` is inferred rather than symbol-proven. It is preferred over `SendRewardClaimRequest`, `ClaimReward`, and raw-helper labels because it matches neighboring `RequestRankingPage` verb-object style and describes network intent without implying immediate local award.

## Data And Controls

- `g_pRankingDialog` is `dword_67A7E4` at `0x0067a7e4`.
- The direct empty `Singleton<RankingDialog>` base and the embedded category collection both begin at dialog offset `+0x26c` (`this + 620`) through EBO; they are distinct source objects with reverse destruction order, not one guard/member object.
- `+0x27c` and `+0x280` are current page and max page in current generated source.
- Child control ids are close `0`, event list `1`, user list `2`, previous page `3`, next page `4`, reward-info `5`, and reward-claim `6`.
- Controls `3/4` are `ImageButtonControlPane` previous/next buttons, constructed with image ids `44/45`. Controls `5/6` are `FittingRoomTextButtonControlPane` instances built from the exact UTF-16 labels `RewardInfo` and `GetReward`.
- [UID:00003T][DialogPane](by-class/DialogPane.md) provides `ControlPane *GetChildControl(int) const` and inline `template <class T> T *GetChild(int) const`; [UID:000038][ControlPane](by-class/ControlPane.md) provides virtual `Enable()`/`Disable()` and inline `IsEnabled() const`. Exact children UID0003N3/UID0003N4 bind the mutations to slots `+0x4c/+0x50`, and `IsEnabled()` reads `m_enabled +0x101`.

## 2026-07-31 B007 UID0004YX Source-Ready Method Evidence

- Live MCP session `f608d7c2`, pre-transaction IDB SHA256 `CF18895C73C8ED240D9B1351AFBD66E73E8C9D6F56F193479ECCA4FEEE2C7F96`, reconfirmed exact method `[0x004596b0,0x004597ae)`, 254 bytes, calls at `0x00459309` and `0x0045969a`, clean `0xcc` predecessor/successor padding, and no source-visible explicit argument.
- Historical IDA prestate `_BYTE **__usercall@<eax>(int@<ecx>, int@<edi>)` was rejected for source. EDI is assigned the selected-record return after entry, neither caller consumes a result, and the accepted source-facing signature is `void RankingDialog::UpdateRewardAndNavigationButtons()`.
- `m_categories.GetSelectedRecord()` supplies the optional record. A non-null record enables control `5`; state `0` enables control `6`; states `1/2` disable it; other state values leave control `6` unchanged. A null record disables controls `5/6`.
- Previous control `3` is disabled at page zero and enabled at positive pages only when its state must change. Next control `4` is disabled at or above `m_maxPage` and enabled below it only when its state must change. Navigation controls retain null checks; mandatory reward controls retain the binary's no-null-defense assumption.
- Exact by-memory children own their complete formal CPP bodies. This class page is `88/92`, owned/emitted by [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), with blank formal class CPP/H because unrelated layout, helper, and generated-output cleanup remains broader than any one child.
- Ownership alternatives remain rejected: generic `DialogPane`/`ControlPane` APIs are dependencies, `RankingCategoryRecord` supplies state but owns no controls, and `RankingRewardInfoDialog` does not own the main dialog's page fields.
- Supervisor catalog entry `0379` applied and saved the corresponding IDA identity at dated checkpoint SHA256 `4B5F2EC3F83106BAC18640D079C51CD2E2FB56797577EFE7D994EF483D9A696A`, `143,192,707` bytes, saved `2026-07-31T04:26:38.9922636-04:00`; backup SHA256 `CF18895C...2C7F96` is the dated prestate. Authoritative current saved IDB is SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, `143,192,751` bytes, saved `2026-07-31T06:21:13.3464834-04:00`, session `f608d7c2`; bounded read-only target/helper/getter/predecessor/successor readback found no UID0004YX drift.
- Current IDA name/type are exactly `RankingDialog__UpdateRewardAndNavigationButtons` and `void __thiscall(RankingDialog *this)`. The current function-regular comment is `Updates reward-info, reward-claim, previous-page, and next-page enabled states from the selected ranking category and current page bounds.` Other target comment channels remain absent.
- Catalog0379 also confirms the same range, bytes, two callers, return-only frame, pads, neighbors, and protected UID000425/UID000427/UID0002K2 state. No class metadata, formal class block, layout, local, frame, or unrelated method changed.

## Reward-Claim Request/Response Flow

- Private `RequestRewardClaim()` is emitted by [UID:0004ZM][0x00459580-0x004595f3.RankingDialogRawRewardClaimRequestHelper](by-memory/0x00459580-0x004595f3.RankingDialogRawRewardClaimRequestHelper.md). `OnControlCommand` case `6` calls it in human source; the compiler inlined that call. The method sends the exact six-byte outbound opcode `0x7d`, subcommand `6`, and big-endian selected category id after a selected-record null guard.
- Ranking dispatcher case `6` passes the seven-byte response to [UID:0003WU][0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse](by-memory/0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse.md). The collection reads the big-endian category id at packet `+2`, tests the response byte at `+6`, scans its records, and changes only the first matching record to claimed state `1`.
- The dispatcher then calls [UID:0004YX][0x004596b0-0x004597ae.RankingDialogUpdateRewardAndNavigationButtons](by-memory/0x004596b0-0x004597ae.RankingDialogUpdateRewardAndNavigationButtons.md). State `1` disables reward-claim control `6`, making the UI refresh the direct consumer of the collection mutation.
- This request/response/UI sequence is RankingDialog-specific. PacketBuffer and queue/send routines are dependencies, not alternative source owners.

## UID0002KA Page-Request Reset Contract

`RankingDialog::RequestRankingPage` is the sole caller of [UID:0002KA][0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries](by-memory/0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries.md), at `0x004594f7`. The selected record has already been obtained from `m_categories` and null-checked. The call compiles from `record->ResetUserEntries();`; instruction `0x004594fc` immediately overwrites `EAX`, proving that no source return is consumed and supporting `void RankingCategoryRecord::ResetUserEntries()` rather than the historical decompiler return.

The callee sets the vector end at record `+0x25c` to begin `+0x258` and writes `-1` to `m_localPlayerRank` at `+0x268`. It preserves the allocation and capacity at `+0x260`, so this is `m_userEntries.clear()` rather than destruction/free. It also preserves the record's category id, loaded-row category id, total count, reserved local-player footer tail, and local-player score. The separately modeled vector destructor at `0x0045d5f0` owns storage release.

Only after that reset does the dialog build the opcode `0x7d` / subcommand `2` request containing the selected category id and the one-based inclusive interval `10 * page + 1` to `10 * (page + 1)`. The matching row parser performs the same end=begin and rank=`-1` reset before appending replacement rows. This ordering prevents stale rows and stale local-rank footer state while deliberately reusing vector capacity.

The source method remains owned and declared by [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md); this dialog page documents the calling policy and does not duplicate its CPP/H. Historical names that treated `+0x268` as a selected-user index or treated the residual `EAX` as an authored return are disproved by parser, paint, and immediate caller-flow evidence.

## Open Questions

- Generated `class_RankingDialog.cpp` includes unrelated methods at `0x0046e2a0`, `0x0046e640`, `0x0046eaa0`, `0x0049eac0`, `0x0049eb90`, `0x0049ee50`, `0x0049ef60`, `0x004add40`, `0x004ade60`, `0x004fee40`, `0x00516510`, `0x00516670`, `0x00516dd0`, `0x00516e50`, and `0x00544710`; these should be re-owned before source migration. The `0x0046e2a0`, `0x0046e640`, and `0x0046eaa0` functions are now documented as [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md) code, the `0x0049eac0-0x0049f07e` animation helpers are documented as [UID:00012U][0x0049eac0-0x0049f081.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f081.DialogPaneSlideAnimation.md) code, and the generated `0x004add40`/`0x004ade60` outliers are [UID:00014O][0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper](by-memory/0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper.md) and [UID:00014P][0x004ade60-0x004adfab.ExchangeDialogReadyAlertHelper](by-memory/0x004ade60-0x004adfab.ExchangeDialogReadyAlertHelper.md).
- The packet response handlers that populate categories and user rows are currently attached mainly to `RankingCategoryCollection` and `RankingRewardInfoDialog`; final naming should make the dispatch path explicit.
- Current generated metadata reports `vtable_count: 0`, but IDA confirms primary, secondary, and tertiary `RankingDialog` vtables. Use [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md) as the source of truth.
- 2026-05-26 IDA `py_eval` recheck confirms the main `RankingDialog` method boundaries from constructor `0x00458610-0x0045894b` through scalar deleting destructor `0x00459840-0x004598ac`. It also reconfirms vtable bases `0x00610984`, `0x006109e4`, and `0x00610a14` with stores from the constructor/destructor, and confirms packet handler `0x00459210` is referenced from secondary vtable slot `0x006109f4`.
- Final C++ remains blank even though the page now clears the score gate. The class still needs source-quality field names for the category collection/page state/control lookup array, packet helper signatures, and a generated-output cleanup pass that keeps the documented WebBoard, popup, render, and slide-animation exclusions out of the final `RankingDialog.cpp`.
- 2026-06-23 B001 no-code proof, now historical in part: class-level C++ remains blank because exact method children own safe method bodies. At that time UID0004ZM/previous/next raw helpers were all left blank for lack of ordinary start xrefs. Accepted UID0004ZM session `b3b2bf88` supersedes only the reward-claim conclusion: its exact case-6 inline copy now proves a private `RequestRewardClaim()` source call and the child emits formal CPP. Previous/next and UID000427 retain their own independent dispositions. UID0004YX likewise owns populated formal CPP after its inherited API blocker was resolved. This paragraph preserves the earlier rationale without presenting it as current state.

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000BN][RankingEventListPane](by-class/RankingEventListPane.md)
- [UID:0000BQ][RankingUserListPane](by-class/RankingUserListPane.md)
- [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md)
- [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md)
- [UID:0000Y0][0x00459810-0x0045981a.RankingDialogSingletonBaseDestructor](by-memory/0x00459810-0x0045981a.RankingDialogSingletonBaseDestructor.md)
- [UID:0000Y1][0x0045981b-0x00459830.RankingDialogAdjustorThunks](by-memory/0x0045981b-0x00459830.RankingDialogAdjustorThunks.md)
- [UID:0004ZM][0x00459580-0x004595f3.RankingDialogRawRewardClaimRequestHelper](by-memory/0x00459580-0x004595f3.RankingDialogRawRewardClaimRequestHelper.md)
- [UID:0003WU][0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse](by-memory/0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse.md)
- UID000422 [0x00459600-0x00459623.RankingDialogRawPreviousPageHelper](by-memory/0x00459600-0x00459623.RankingDialogRawPreviousPageHelper.md)
- UID000424 [0x00459630-0x00459655.RankingDialogRawNextPageHelper](by-memory/0x00459630-0x00459655.RankingDialogRawNextPageHelper.md)
- UID000425 [0x00459660-0x004596a1.RankingDialogUpdateMaxPageFromSelectedRecord](by-memory/0x00459660-0x004596a1.RankingDialogUpdateMaxPageFromSelectedRecord.md)
- [UID:0004YX][0x004596b0-0x004597ae.RankingDialogUpdateRewardAndNavigationButtons](by-memory/0x004596b0-0x004597ae.RankingDialogUpdateRewardAndNavigationButtons.md)
- UID000427 [0x004597b0-0x00459804.RankingDialogInvalidateActionButtons](by-memory/0x004597b0-0x00459804.RankingDialogInvalidateActionButtons.md)
- [UID:00012U][0x0049eac0-0x0049f081.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f081.DialogPaneSlideAnimation.md)
- [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md)

## Changes

- 2026-08-04 B005 UID0002KA caller/request callback:
  - Preserved class metadata, formal channels, all reward/navigation evidence, and existing broader class caveats.
  - Added the exact sole call at `0x004594f7`, immediate `EAX` overwrite at `0x004594fc`, `void` return decision, clear-without-free and rank-sentinel behavior, and the opcode `0x7d` subcommand `2` request interval that follows the reset.
  - Kept method emission on UID0002KA/UID0000BL and retained selected-user/return interpretations only as disproved history.

- 2026-08-02 B001 UID0004ZM ordinary implementation callback:
  - Raised `87/90 -> 88/92`; preserved owner/emitter UID0000MZ, reconstructable state, and blank class CPP/H.
  - Corrected primary `+0x48` method identity from historical `OnButtonClick` to `OnControlCommand(int,int)`, identified UID0004ZM as private `RequestRewardClaim()`, and added exact retained-body/inlined-case evidence.
  - Reconciled the six-byte request/seven-byte response/UI-refresh flow and preserved the earlier no-start-xref conclusion as explicit superseded history rather than deleting its negative evidence.
- 2026-07-31 B009 UID0003WU ordinary implementation callback:
  - Preserved class metadata at `87/90`, blank formal class CPP/H, B007 UID0004YX source-ready evidence, and all catalog0379/current-IDB history.
  - Added the exact opcode `0x7d` subcommand `6` request/response/UI sequence through UID0004ZM, UID0003WU, and UID0004YX.
  - Rejected the copied reward-helper UID000420 link. Validator command `000000020264` allocated UID0004ZM to the exact `0x00459580-0x004595f3` helper path; UID000420 remains canonically assigned to `MapPaneGetClampedVisibleTileBounds`.
- 2026-07-31 B007 UID0004YX Gate 2A support repair:
  - Restored both UID000425 references to the exact RankingDialog max-page child after registry rewriting had pointed them at unrelated MapPane collision content.
  - Restored UID000422, UID000424, and UID000427 inventory/cross-reference routes to the exact RankingDialog helper pages. Literal UID text prevents duplicate validator-registry entries from redirecting these links to unrelated MapPane pages.
  - Preserved all B009 UID0003WU reward-claim response/UI-refresh detail and rebound active UID0004YX IDA evidence to current saved IDB `B7CC899D...58277`; catalog0379 SHA `4B5F...A696A` remains dated history.
- 2026-07-31 B007 UID0004YX source-quality callback:
  - Updated only the UID0004YX method inventory and target-specific evidence from inherited-API-blocked/blank to source-ready exact-child formal CPP.
  - Added exact session/range/signature, controls `3..6`, resource labels, selected-record/state policy, navigation transition behavior, inherited API contracts, ownership exclusions, and historical correction.
  - Preserved class `87/90`, owner/emitter UID0000MZ, blank class formal CPP/H, all unrelated method/helper rows, singleton/vtable history, and broader generated-output caveats.
- 2026-07-31 supervisor catalog0379 post-IDA sync:
  - Added current saved target identity/type/comment and backup/postsave evidence while retaining the former `sub_4596B0`/`__usercall` shape only as historical prestate.
  - Preserved class `87/90`, owner/emitter UID0000MZ, blank class formal CPP/H, exact method body routing to UID0004YX, and all unrelated class history.
- 2026-07-13 B004 UID0000Y0 source-disposition sync:
  - Preserved class `87/90`, owner/emitter [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), blank formal class C++, every unrelated method/helper row, and all existing source-output blockers.
  - Replaced the source-facing `ClearSingletonHelper` row with non-emitting [UID:0000Y0][0x00459810-0x0045981a.RankingDialogSingletonBaseDestructor](by-memory/0x00459810-0x0045981a.RankingDialogSingletonBaseDestructor.md); added the eight-entry RTTI hierarchy, direct `Singleton<RankingDialog>` base at `+0x26c`, EBO, constructor states/EH actions, ordinary/scalar duplicate clears, four-store lifecycle, comparator boundary, and exhaustive no-helper disposition.
  - Historicalized the old custom IDA helper rename without discarding it as a search alias. No class declaration/body, explicit specialization, catch, guard field, or late-publication expression was added.

- 2026-06-23 B001 accepted helper implementation:
  - Before: `85/88`, with broad core method inventory but missing exact children for `0x00459580-0x00459804`.
  - Changed to: `87/90`; owner/emitter remain [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), and class-level C++ remains blank.
  - Historical identity correction: that pass identified exact helper ranges and behaviors but copied MapPane UIDs into several RankingDialog helper links. UID000420 remains the legitimate identity of [0x00505290-0x00505304.MapPaneGetClampedVisibleTileBounds](by-memory/0x00505290-0x00505304.MapPaneGetClampedVisibleTileBounds.md), not the ranking reward helper. The reward helper now has validator-assigned [UID:0004ZM][0x00459580-0x004595f3.RankingDialogRawRewardClaimRequestHelper](by-memory/0x00459580-0x004595f3.RankingDialogRawRewardClaimRequestHelper.md). The other historical copied helper identities remain outside UID0003WU scope and are retained only as historical search context.

- 2026-06-17 B002 ExchangeDialog pollution sync:
  - Summary/evidence: incorporated B002's [UID:00014O][0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper](by-memory/0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper.md) generated-output pollution finding by naming `0x004add40` and `0x004ade60` as ExchangeDialog helpers, not RankingDialog methods. Score unchanged.

- 2026-06-16 C001 class-completion refresh:
  - Before: `82/86`, with strong older method/vtable evidence but stale generated-source-pollution and vtable metadata notes.
  - Changed to: `85/88`; owner/emitter remain [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), and reconstruction C++ remains blank.
  - Summary/evidence: live IDA MCP reconfirmed method boundaries, opcode `0x7d` packet-handler behavior, vtable-store xrefs, all 17 `g_pRankingDialog` xrefs, and the support chain through [UID:0002ON][0x00610980-0x00610e38.RankingDialogReadOnlyData](by-memory/0x00610980-0x00610e38.RankingDialogReadOnlyData.md), [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md), and [UID:0000MZ][RankingDialog](by-file/RankingDialog.md). IDA DB names were updated for the packet handler, clear helper, scalar deleting destructor, and singleton global; constructor/field/helper/source-output cleanup remains below final C++ quality.

- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and assigned parent `0000MZ`.
  - Before: The main ranking dialog remained unclassified in autogen coverage even though the page and parent file both met the 80/80 attach gate.
  - After: The class contributes to `RankingDialog.cpp` as a reconstructable child without emitting final C++ yet.
  - Evidence: Live IDA MCP lookup confirms the core ranking methods from `0x00458610` through `0x00459840`; the parent [UID:0000MZ][RankingDialog](by-file/RankingDialog.md) records the same boundaries, ranking opcode `0x7d` ownership, and generated-source pollution caveats.

- 2026-05-30: Grading changed from `0/0` to `82/86`.
  - Before: page documented core ranking dialog methods, controls, globals, packet dispatch, vtables, and owner-pollution caveats but remained unevaluated.
  - After: score reflects documented constructor, selection, button, paint, packet-handler, layout, request, singleton, and destructor behavior, with generated-source pollution still called out as the main caveat.
  - Evidence: linked aggregate [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md) records IDA-confirmed method boundaries, vtable bases/stores, opcode `0x7d` packet-handler slot, and non-ranking helper exclusions.
