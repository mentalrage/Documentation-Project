*** UID:0000I8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/social/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Clan

## Status

- Confidence: strong for `ClanStatusPane`, `ClanNameInputDialog`, `ClanAttrInputDialog`, the name/action submitters, confirmed packet helpers, and the clan bank/item dialog cluster; medium for constructor-only derived dialog records because many Wave3 starts are projected and not IDA functions.
- Proposed module folder: `social/`
- Proposed source file: `social/Clan.cpp`
- Documented split files: [UID:0000I9][ClanBank](by-file/ClanBank.md) as likely `social/ClanBank.cpp`; possible further split `social/ClanItemDialogs.cpp`
- Other possible split file: `ui/dialogs/ClanDialogs.cpp`
- Evidence basis: Wave3 class/file inspection, generated `simroot_v2` sources, Wave2 missing-ref/global records for Clan packet helpers, and IDA MCP boundary/decompilation/vtable checks on 2026-05-23, 2026-05-24, and 2026-05-26.

## Hypothesis

The original Clan source was probably a feature-owned social module, not one source file per reconstructed class. The dense early address cluster around `0x00484030-0x0048c63f` combines the visible clan status pane, clan attribute/list packet parsing, clan name/attribute modal dialogs, row action packet dispatch, leave confirmation, and destructor/thunk companions. The common signs are clan resource names (`CLAN1.EPF`, `CLAN2.EPF`, `CLAN3.EPF`, `CLANBUT.EPF`, `DLGCLAN1.EPF`, `DLGCLAN2.EPF`), opcode `0x4b` packet builders, shared sender globals, and vtable families installed by derived dialogs.

The bank/item classes are feature-related but larger and more self-contained. They now have a dedicated [UID:0000I9][ClanBank](by-file/ClanBank.md) pass. Keep them as a probable `ClanBank.cpp` or `ClanItemDialogs.cpp` split unless later source-layout evidence proves the original code kept the whole clan feature in one large `Clan.cpp`.

The modal dialog vtable cluster is documented separately in [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md). Use that page and [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md) as class-layout anchors when reconciling projected constructor records in current generated output.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `ClanStatusPane` | `0x00484030`, cleanup [UID:00021B][0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup](by-memory/0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup.md), `0x00484a60-0x00484f16`, `0x00486800-0x004875f5`, destructor `0x0048c590` | `class_ClanStatusPane.cpp` | Main clan status UI, tab switching, row drawing, row hit-testing, action dispatch, child-pane refresh/view switching, and owned child list panes. Cleanup fragment is compiler-generated, not handwritten source. |
| `ClanEnlistInputDialog` | parser `0x004842b0`, packet handlers in [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md), raw constructor [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md), submitter [UID:0002O3][0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment](by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment.md) | `class_ClanEnlistInputDialog.cpp` | Parses clan attribute/list/member packets and submits enlistment data through `SendClanAttributePacket`. |
| `ClanInfoListPane` | inline setup `0x004840b2-0x00484135`; raw constructor [UID:00021T][0x004885a0-0x00488602.ClanInfoListPaneRawConstructor](by-memory/0x004885a0-0x00488602.ClanInfoListPaneRawConstructor.md); false virtuals [UID:0002NN][0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual](by-memory/0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual.md) and [UID:0002NO][0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual](by-memory/0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual.md) | `class_ClanInfoListPane.cpp` | Read-only `TextEditPane`-style clan info child. Raw constructor-shaped bytes have no IDA function object or inbound xrefs; inline setup remains the primary construction anchor. |
| `ClanStringListPane` | raw constructor [UID:0002NP][0x00488630-0x00488674.ClanStringListPaneRawConstructor](by-memory/0x00488630-0x00488674.ClanStringListPaneRawConstructor.md); shared draw [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) | `class_ClanStringListPane.cpp` | Shared clan string-list row renderer. Standalone constructor-shaped bytes are raw/non-IDA and have no inbound xrefs. |
| `ClanJoinListPane` | inline setup `0x0048413f-0x0048419b`; selected-row action [UID:0002NR][0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction](by-memory/0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction.md); key/event handler [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md); shared draw [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) | no current generated class file | Clan status join-list child created inline by `ClanStatusPane`. |
| `ClanEnlistListPane` | inline setup `0x004841a0-0x00484201`; action/event handlers [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md); shared draw [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) | no current generated class file | Clan status enlist-list child created inline by `ClanStatusPane`. |
| `ClanNameInputDialog` | [UID:00010J][0x00488b40-0x00488fa0.ClanNameInputDialogCore](by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md) `0x00488b40-0x00488fa0` | `class_ClanNameInputDialog.cpp` | Shared modal name/text input dialog built on `DLGCLAN1.EPF`. |
| `ClanDepMoneyInputDialog` | raw constructor [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md); submitter [UID:0002NS][0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney](by-memory/0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney.md) | `class_ClanDepMoneyInputDialog.cpp` | Deposit-money variant using base name/input dialog shell. |
| `ClanWidMoneyInputDialog` | raw constructor [UID:0002NT][0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor](by-memory/0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor.md); submitter [UID:0002NU][0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney](by-memory/0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney.md) | `class_ClanWidMoneyInputDialog.cpp` | Withdraw-money variant using base name/input dialog shell. |
| `ClanExpelNameInputDialog` | raw constructor [UID:0002NV][0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor](by-memory/0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor.md); submitter [UID:0002NW][0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName](by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md) | `class_ClanExpelNameInputDialog.cpp` | Sends clan expel name packet. |
| `ClanSummonNameInputDialog` | raw constructor [UID:0002NX][0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor](by-memory/0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor.md); submitter [UID:0002NY][0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName](by-memory/0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName.md) | `class_ClanSummonNameInputDialog.cpp` | Sends clan summon name packet. |
| `ClanAppearNameInputDialog` | raw constructor [UID:0002NZ][0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor](by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md); submitter [UID:0002O0][0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName](by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md) | `class_ClanAppearNameInputDialog.cpp` | Sends clan appearance name packet. |
| `ClanChangeNameInputDialog` | raw constructor [UID:0002O1][0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor](by-memory/0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor.md); submitter [UID:0002O2][0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName](by-memory/0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName.md) | `class_ClanChangeNameInputDialog.cpp` | Sends clan rename packet. |
| `ClanAttrInputDialog` | `0x00489600-0x00489f80`, destructor `0x0048c390` | `class_ClanAttrInputDialog.cpp` | Multi-field attribute dialog built on `DLGCLAN2.EPF`; validates required controls and stores submitted text/value fields. |
| `ClanChangeInputDialog` | raw constructor [UID:0002O4][0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor](by-memory/0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md); submitter [UID:0002O5][0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange](by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange.md) | `class_ClanChangeInputDialog.cpp` | Derived attribute dialog that submits clan name/description/flag/type changes through helper `0x00486330`. |
| `ClanLeaveConfirmDialog` | raw constructor [UID:0002O6][0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor](by-memory/0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor.md); confirm [UID:0002O7][0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm](by-memory/0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm.md); cancel [UID:0002O8][0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel](by-memory/0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel.md) | `class_ClanLeaveConfirmDialog.cpp` | Alert-derived leave confirmation that calls `SendClanLeaveResponse`. |
| `ClanItemDialog` | raw constructor [UID:00021X][0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor](by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md), vtable reset [UID:0002OC][0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail](by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md), confirm validation [UID:0002OB][0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation](by-memory/0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation.md); destructor `0x0048c470` | `class_ClanItemDialog.cpp` | Shared item-selection dialog base for clan item deposit/withdraw flows. |
| `ClanDepItemDialog` | `0x0048a1c0-0x0048a805`, animation `0x0049ec80` | `class_ClanDepItemDialog.cpp` | Clan-bank item deposit dialog and opcode `0x4b` subtype `5` packet sender. |
| `ClanWidItemDialog` | `0x0048a810-0x0048ae65` | `class_ClanWidItemDialog.cpp` | Clan-bank item withdraw dialog and opcode `0x4b` subtype `12` packet sender. |
| `ClanItemListPane` | `0x0048ae70-0x0048b1b1`, text helpers `0x004ba820-0x004ba991` | `class_ClanItemListPane.cpp` | Compact item list used by clan item dialogs. |
| `ClanBankPane` | `0x0048b1c0-0x0048b7dc`, raw packet helpers [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md), animation `0x0049ed60`, destructor `0x0048c410` | `class_ClanBankPane.cpp` | Main clan bank dialog, item/gold mode selection, bank close/submit packet handling, and `g_pClanBankPane`. |
| `ClanBankItemListPane` | `0x0048b8c0-0x0048c251`, destructor `0x0048c3d0` | `class_ClanBankItemListPane.cpp` | Clan bank inventory packet parser, display-name sort, and item-row renderer. |
| `ClanStatusPacketDispatcher` | [UID:00021C][0x00484f70-0x0048540b.ClanStatusPacketDispatcher](by-memory/0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md) | not materialized by Wave3 | Secondary-vtable opcode `0x43` clan packet dispatcher that updates clan state and opens modal clan dialogs. |
| `SendClanOpcode4BSubtype0Request` | [UID:00021D][0x00485440-0x004854a5.SendClanOpcode4BSubtype0Request](by-memory/0x00485440-0x004854a5.SendClanOpcode4BSubtype0Request.md) | not materialized by Wave3 | Raw opcode `0x4b`, subtype `0`, zero-payload request helper. |
| `SendClanOpcode4BSubtype1Request` | [UID:00021E][0x004854b0-0x00485518.SendClanOpcode4BSubtype1Request](by-memory/0x004854b0-0x00485518.SendClanOpcode4BSubtype1Request.md) | not materialized by Wave3 | Raw opcode `0x4b`, subtype `1`, action/value `0` request helper. |
| `SendClanJoinListRefreshPacket` | [UID:00021F][0x00485520-0x00485588.SendClanJoinListRefreshPacket](by-memory/0x00485520-0x00485588.SendClanJoinListRefreshPacket.md) | not materialized by Wave3 | Raw opcode `0x4b`, subtype `2`, action/value `0` join-list request helper. |
| `SendClanJoinListSelectionPacket` | [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md) | not materialized by Wave3 | Sends opcode `0x4b`, subtype `2`, action `1`, and a selected clan-list name from `ClanJoinListPane`. |
| `SendClanLeaveRequestPacket` | [UID:00021H][0x00485690-0x004856f9.SendClanLeaveRequestPacket](by-memory/0x00485690-0x004856f9.SendClanLeaveRequestPacket.md) | not materialized by Wave3 | Raw opcode `0x4b`, subtype `3`, action/value `0` leave-request helper. |
| `SendClanLeaveResponse` | `0x00485700-0x00485778` | `recovered/SendClanLeaveResponse_00485700.cpp` | Sends opcode `0x4b`, subtype `3`, action `1`, accept/cancel byte. |
| `ClanDepositMoneyPacketHelpers` | [UID:00021I][0x00485780-0x00485867.ClanDepositMoneyPacketHelpers](by-memory/0x00485780-0x00485867.ClanDepositMoneyPacketHelpers.md) | not materialized by Wave3 | Raw opcode `0x4b`, subtype `4`, action `0`/`1` helper pair. |
| `ClanDepositItemPacketHelpers` | [UID:00021J][0x00485870-0x00485955.ClanDepositItemPacketHelpers](by-memory/0x00485870-0x00485955.ClanDepositItemPacketHelpers.md) | not materialized by Wave3 | Raw opcode `0x4b`, subtype `5`, action `0`/`1` helper pair. |
| `ClanSubtype6PacketHelpers` | [UID:00021K][0x00485960-0x00485abe.ClanSubtype6PacketHelpers](by-memory/0x00485960-0x00485abe.ClanSubtype6PacketHelpers.md) | not materialized by Wave3 | Opcode `0x4b`, subtype `6`, action `0`/`1` helpers adjacent to `SendClanAttributePacket`; called by enlist-list handlers in [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md). |
| `SendClanAttributePacket` | `0x00485ac0-0x00485cbd` | `recovered/SendClanAttributePacket_00485AC0.cpp` | Sends opcode `0x4b`, subtype `6`, action `2`, three length-prefixed strings, and a big-endian attribute value. |
| `ClanNameActionPacketHelpers` | [UID:00021L][0x00485cc0-0x0048632e.ClanNameActionPacketHelpers](by-memory/0x00485cc0-0x0048632e.ClanNameActionPacketHelpers.md) | not materialized by Wave3 | Raw opcode `0x4b`, subtype `6` action `3`, and subtype `7-10` action `0`/`1` helper strip. |
| `SubmitClanChangeHelper_486330` | [UID:00010F][0x00486330-0x0048652d.SubmitClanChangeHelper](by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md) | not materialized by Wave3 | Sends opcode `0x4b`, subtype `10`, action `2`, three length-prefixed converted strings, and a 16-bit value from `ClanChangeInputDialog::SubmitClanChange`. |
| `ClanWithdrawAndNoticePacketHelpers` | [UID:00021M][0x00486530-0x004867f2.ClanWithdrawAndNoticePacketHelpers](by-memory/0x00486530-0x004867f2.ClanWithdrawAndNoticePacketHelpers.md) | not materialized by Wave3 | Raw opcode `0x4b`, subtype `11-13` helper strip. |
| `ClanStatusPaneRowEligibilityHelper` | [UID:00021N][0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper](by-memory/0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper.md) | not materialized by Wave3 | Raw row-index switch helper that gates clan status action availability through `ClanStatusPane` state bytes `+0xf8` and `+0xf9`. |
| `ClanStatusPaneRefreshChildPanes` | [UID:00021O][0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes](by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md) | misattributed by Wave3/simroot as `ClanEnlistInputDialog::HideAllControls` | Refreshes/clears the info, join-list, and enlist-list child panes at `+0x2510`, `+0x2514`, and `+0x2518`. |
| `ClanStatusPaneShowInfoList` | [UID:00021P][0x004873c0-0x00487475.ClanStatusPaneShowInfoList](by-memory/0x004873c0-0x00487475.ClanStatusPaneShowInfoList.md) | not materialized by Wave3 | Sets `ClanStatusPane` view byte `+0xf8` to `2`, configures the info-list child, and invalidates the pane. |
| `ClanStatusPaneShowJoinList` | [UID:00021Q][0x00487480-0x00487535.ClanStatusPaneShowJoinList](by-memory/0x00487480-0x00487535.ClanStatusPaneShowJoinList.md) | not materialized by Wave3 | Sets `ClanStatusPane` view byte `+0xf8` to `3`, configures the join-list child, and invalidates the pane. |
| `ClanStatusPaneShowEnlistList` | [UID:00021R][0x00487540-0x004875f5.ClanStatusPaneShowEnlistList](by-memory/0x00487540-0x004875f5.ClanStatusPaneShowEnlistList.md) | not materialized by Wave3 | Sets `ClanStatusPane` view byte `+0xf8` to `4`, configures the enlist-list child, and invalidates the pane. |
| `ClanStatusRowActionPacket` | [UID:00010H][0x00487600-0x0048779f.ClanStatusRowActionPacket](by-memory/0x00487600-0x0048779f.ClanStatusRowActionPacket.md) | not materialized by Wave3 | IDA-verified `ClanStatusPane::OnMouseEvent` row-action helper. Maps status rows `2-13` to opcode `0x4b` subtype packets `{ 0x4b, subtype, 0 }`; row `7` branches to [UID:00021K][0x00485960-0x00485abe.ClanSubtype6PacketHelpers](by-memory/0x00485960-0x00485abe.ClanSubtype6PacketHelpers.md) for subtype `6`. |
| `ClanStatusPacketDialogHandlers` | [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md) | partially materialized/misattributed by Wave3 | Clan opcode `0x43` subtype helper island for enlist/list/member packet handling and clan modal dialog openers. |
| `ClanListPaneInputHandlers` | [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md) | not materialized by Wave3 | Vtable-backed `ClanJoinListPane`/`ClanEnlistListPane` event and selected-row handlers immediately before `ClanNameInputDialog`. |

## Boundary And Data Notes

- IDA confirms the main Clan starts listed in the memory docs. Use IDA starts as migration anchors, not Wave3 projected constructor starts.
- IDA reports no function at `0x004885a0`, `0x00488630`, `0x00488fa0`, `0x00489070`, `0x00489140`, `0x00489270`, `0x004893a0`, `0x004894d0`, `0x00489f80`, `0x00489ff0`, `0x0048a060`, or `0x0048a0c0`. Some of those starts are still valid raw constructor-shaped bytes even though IDA does not model them as functions.
- Wave3 has no memory owner for confirmed IDA functions `0x00486330` and `0x00487600`. Wave2 annotations and IDA decompilation show both are Clan packet helpers, so they should be kept with this module for source-layout planning.
- Wave3 has no clean memory owner for small real Clan bank/item helper functions `0x0048a100`, `0x0048a690`, `0x0048acf0`, and `0x0048b600`; IDA shows vtable-reset/destructor-helper behavior adjacent to the owning dialogs.
- `ClanBankItemListPane` contains two outlier records: `0x00430041` resolves inside [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md), and `0x004c0043` resolves inside large excluded IDA function `sub_4BEE40`. Do not migrate those as clan-bank class code without a focused owner repair.
- IDA confirms [UID:00021C][0x00484f70-0x0048540b.ClanStatusPacketDispatcher](by-memory/0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md), the opcode `0x4b` helper cluster [UID:00021D][0x00485440-0x004854a5.SendClanOpcode4BSubtype0Request](by-memory/0x00485440-0x004854a5.SendClanOpcode4BSubtype0Request.md) through [UID:00021M][0x00486530-0x004867f2.ClanWithdrawAndNoticePacketHelpers](by-memory/0x00486530-0x004867f2.ClanWithdrawAndNoticePacketHelpers.md), the `ClanStatusPane` row/view helper island [UID:00021N][0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper](by-memory/0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper.md) through [UID:00021R][0x00487540-0x004875f5.ClanStatusPaneShowEnlistList](by-memory/0x00487540-0x004875f5.ClanStatusPaneShowEnlistList.md), [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md), and the list-pane input handler cluster [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md).
- `ClanStatusPane::ClanStatusPane` constructs `ClanInfoListPane`, `ClanJoinListPane`, and `ClanEnlistListPane` inline. Do not use the projected `ClanInfoListPane`/`ClanStringListPane` starts `0x004885a0` and `0x00488630` as constructor anchors; IDA reports no functions or xrefs there.
- `0x00484230-0x004842ad` is now documented as [UID:00021B][0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup](by-memory/0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup.md), a compiler-generated cleanup fragment for partially constructed `ClanStatusPane` children. Do not migrate it as a standalone source method.
- `ClanStringListPane::DrawItem` at `0x004887d0` is shared by three vtable slots: `ClanStringListPane + 0x80` (`0x0061572c`), `ClanJoinListPane + 0x80` (`0x006157f0`), and `ClanEnlistListPane + 0x80` (`0x006158b4`).
- `0x004888d0` is a real selected-row action vtable slot for `ClanJoinListPane + 0x7c` (`0x006157ec`). It should be kept with the clan list-pane family even though no dedicated `class_ClanJoinListPane.cpp` exists in current generated output.
- `0x00488900`, `0x00488970`, and `0x004889a0` are real list-pane vtable slots for `ClanJoinListPane`/`ClanEnlistListPane` and should be kept with the clan list-pane family. IDA data xrefs are `0x006157d4`, `0x006158b0`, and `0x00615898`.
- 2026-05-26 IDA MCP recheck reconfirms exact function boundaries and vtable refs for [UID:00010I][0x00488610-0x004888f0.ClanListPaneVirtuals](by-memory/0x00488610-0x004888f0.ClanListPaneVirtuals.md), and reconfirms no function/xrefs at projected list-pane constructor starts `0x004885a0` and `0x00488630`.
- IDA confirms modal Clan dialog vtable records from `0x006158f8` through `0x00615fd0`, while current generated metadata reports `vtable_count: 0` for the checked classes. Treat generated vtable absence as a data issue, not evidence that the classes lack virtual layout.
- IDA decompilation confirms `ClanNameInputDialog` fetches controls through inherited control-host offset `+0x1fc`, and `ClanAttrInputDialog` stores submitted attribute fields at `+0x26c`, `+0x46c`, `+0x66c`, and `+0x86c`.
- 2026-05-27 and 2026-05-31 IDA MCP family passes checked projected constructor starts `0x00488fa0`, `0x00489070`, `0x00489140`, `0x00489270`, `0x004893a0`, `0x004894d0`, `0x00489f80`, `0x00489ff0`, and `0x0048a060`: none is an IDA function or has inbound xrefs/raw pointer hits, but all inspected bytes have constructor prologues, base-constructor calls, and derived vtable stores. The `0x00488fa0-0x00488fd5` body is documented as [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md), `0x00489f80-0x00489fb5` is documented as [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md), `0x00489ff0-0x0048a025` is documented as [UID:0002O4][0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor](by-memory/0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md), and `0x0048a060-0x0048a09e` is documented as [UID:0002O6][0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor](by-memory/0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor.md); keep class/file ownership based on vtables and confirmed submitter functions while constructor reachability remains open.

## Migration Notes

Start migrations from confirmed IDA-backed code and attach projected constructors only after a boundary cleanup pass. A future dry-run should probably build `Clan.cpp` around the status/dialog/packet core first, then decide whether the reviewed bank/item cluster becomes `social/ClanBank.cpp` or folds into the same module.

```powershell
python source-3\wave3.py create file Clan.cpp --kind source --simpath social/Clan.cpp --dry-run
python source-3\wave3.py attach class ClanStatusPane --to-file Clan.cpp --dry-run
python source-3\wave3.py attach class ClanNameInputDialog --to-file Clan.cpp --dry-run
python source-3\wave3.py attach class ClanAttrInputDialog --to-file Clan.cpp --dry-run
python source-3\wave3.py attach class ClanEnlistInputDialog --to-file Clan.cpp --dry-run
python source-3\wave3.py create file ClanBank.cpp --kind source --simpath social/ClanBank.cpp --dry-run
python source-3\wave3.py attach class ClanBankPane --to-file ClanBank.cpp --dry-run
python source-3\wave3.py attach class ClanBankItemListPane --to-file ClanBank.cpp --dry-run
```

Before non-dry-run attach operations, decide whether the `SendClan*` restored globals, unowned packet helpers `0x00486330`/`0x00487600`, and raw `ClanStatusPane` helper island [UID:00021N][0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper](by-memory/0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper.md) through [UID:00021R][0x00487540-0x004875f5.ClanStatusPaneShowEnlistList](by-memory/0x00487540-0x004875f5.ClanStatusPaneShowEnlistList.md) should become file-local functions under `Clan.cpp`; also resolve the [UID:0000I9][ClanBank](by-file/ClanBank.md) outliers `0x00430041` and `0x004c0043`.

## Cross-References

- [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md)
- [UID:00002B][ClanEnlistInputDialog](by-class/ClanEnlistInputDialog.md)
- [UID:00002E][ClanInfoListPane](by-class/ClanInfoListPane.md)
- [UID:00002L][ClanStringListPane](by-class/ClanStringListPane.md)
- [UID:00002H][ClanJoinListPane](by-class/ClanJoinListPane.md)
- [UID:00002C][ClanEnlistListPane](by-class/ClanEnlistListPane.md)
- [UID:00002J][ClanNameInputDialog](by-class/ClanNameInputDialog.md)
- [UID:00002A][ClanDepMoneyInputDialog](by-class/ClanDepMoneyInputDialog.md)
- [UID:00002O][ClanWidMoneyInputDialog](by-class/ClanWidMoneyInputDialog.md)
- [UID:00002D][ClanExpelNameInputDialog](by-class/ClanExpelNameInputDialog.md)
- [UID:00002M][ClanSummonNameInputDialog](by-class/ClanSummonNameInputDialog.md)
- [UID:000023][ClanAppearNameInputDialog](by-class/ClanAppearNameInputDialog.md)
- [UID:000028][ClanChangeNameInputDialog](by-class/ClanChangeNameInputDialog.md)
- [UID:000024][ClanAttrInputDialog](by-class/ClanAttrInputDialog.md)
- [UID:000027][ClanChangeInputDialog](by-class/ClanChangeInputDialog.md)
- [UID:00002I][ClanLeaveConfirmDialog](by-class/ClanLeaveConfirmDialog.md)
- [UID:0000I9][ClanBank](by-file/ClanBank.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md)
- [UID:00002F][ClanItemDialog](by-class/ClanItemDialog.md)
- [UID:000029][ClanDepItemDialog](by-class/ClanDepItemDialog.md)
- [UID:00002N][ClanWidItemDialog](by-class/ClanWidItemDialog.md)
- [UID:00002G][ClanItemListPane](by-class/ClanItemListPane.md)
- [UID:000026][ClanBankPane](by-class/ClanBankPane.md)
- [UID:000025][ClanBankItemListPane](by-class/ClanBankItemListPane.md)
- [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md)
- [UID:0002MQ][0x00615570-0x006158f4.ClanPaneListVtableData](by-memory/0x00615570-0x006158f4.ClanPaneListVtableData.md)
- [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md)
- [UID:00021B][0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup](by-memory/0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup.md)
- [UID:00010I][0x00488610-0x004888f0.ClanListPaneVirtuals](by-memory/0x00488610-0x004888f0.ClanListPaneVirtuals.md)
- [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md)
- [UID:00010B][0x004842b0-0x00484a50.ClanAttributePacketParser](by-memory/0x004842b0-0x00484a50.ClanAttributePacketParser.md)
- [UID:00010C][0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput](by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md)
- [UID:00021C][0x00484f70-0x0048540b.ClanStatusPacketDispatcher](by-memory/0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md)
- [UID:00021D][0x00485440-0x004854a5.SendClanOpcode4BSubtype0Request](by-memory/0x00485440-0x004854a5.SendClanOpcode4BSubtype0Request.md)
- [UID:00021E][0x004854b0-0x00485518.SendClanOpcode4BSubtype1Request](by-memory/0x004854b0-0x00485518.SendClanOpcode4BSubtype1Request.md)
- [UID:00021F][0x00485520-0x00485588.SendClanJoinListRefreshPacket](by-memory/0x00485520-0x00485588.SendClanJoinListRefreshPacket.md)
- [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md)
- [UID:00021H][0x00485690-0x004856f9.SendClanLeaveRequestPacket](by-memory/0x00485690-0x004856f9.SendClanLeaveRequestPacket.md)
- [UID:00010D][0x00485700-0x00485778.SendClanLeaveResponse](by-memory/0x00485700-0x00485778.SendClanLeaveResponse.md)
- [UID:00021I][0x00485780-0x00485867.ClanDepositMoneyPacketHelpers](by-memory/0x00485780-0x00485867.ClanDepositMoneyPacketHelpers.md)
- [UID:00021J][0x00485870-0x00485955.ClanDepositItemPacketHelpers](by-memory/0x00485870-0x00485955.ClanDepositItemPacketHelpers.md)
- [UID:00021K][0x00485960-0x00485abe.ClanSubtype6PacketHelpers](by-memory/0x00485960-0x00485abe.ClanSubtype6PacketHelpers.md)
- [UID:00010E][0x00485ac0-0x00485cbd.SendClanAttributePacket](by-memory/0x00485ac0-0x00485cbd.SendClanAttributePacket.md)
- [UID:00021L][0x00485cc0-0x0048632e.ClanNameActionPacketHelpers](by-memory/0x00485cc0-0x0048632e.ClanNameActionPacketHelpers.md)
- [UID:00010F][0x00486330-0x0048652d.SubmitClanChangeHelper](by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md)
- [UID:00021M][0x00486530-0x004867f2.ClanWithdrawAndNoticePacketHelpers](by-memory/0x00486530-0x004867f2.ClanWithdrawAndNoticePacketHelpers.md)
- [UID:00010G][0x00486800-0x00487291.ClanStatusPaneRows](by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md)
- [UID:00021N][0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper](by-memory/0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper.md)
- [UID:00021O][0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes](by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md)
- [UID:00021P][0x004873c0-0x00487475.ClanStatusPaneShowInfoList](by-memory/0x004873c0-0x00487475.ClanStatusPaneShowInfoList.md)
- [UID:00021Q][0x00487480-0x00487535.ClanStatusPaneShowJoinList](by-memory/0x00487480-0x00487535.ClanStatusPaneShowJoinList.md)
- [UID:00021R][0x00487540-0x004875f5.ClanStatusPaneShowEnlistList](by-memory/0x00487540-0x004875f5.ClanStatusPaneShowEnlistList.md)
- [UID:00010H][0x00487600-0x0048779f.ClanStatusRowActionPacket](by-memory/0x00487600-0x0048779f.ClanStatusRowActionPacket.md)
- [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md)
- [UID:00021T][0x004885a0-0x00488602.ClanInfoListPaneRawConstructor](by-memory/0x004885a0-0x00488602.ClanInfoListPaneRawConstructor.md)
- [UID:00010J][0x00488b40-0x00488fa0.ClanNameInputDialogCore](by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md)
- [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md)
- [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md)
- [UID:0002NS][0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney](by-memory/0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney.md)
- [UID:0002NT][0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor](by-memory/0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor.md)
- [UID:0002NU][0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney](by-memory/0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney.md)
- [UID:0002NV][0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor](by-memory/0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor.md)
- [UID:0002NW][0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName](by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md)
- [UID:0002NX][0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor](by-memory/0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor.md)
- [UID:0002NY][0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName](by-memory/0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName.md)
- [UID:0002NZ][0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor](by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md)
- [UID:0002O0][0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName](by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md)
- [UID:0002O1][0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor](by-memory/0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor.md)
- [UID:0002O2][0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName](by-memory/0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName.md)
- [UID:00010L][0x00489600-0x00489f80.ClanAttrInputDialogCore](by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md)
- [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md)
- [UID:00010M][0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters](by-memory/0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters.md)
- [UID:0002O3][0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment](by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment.md)
- [UID:0002O4][0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor](by-memory/0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md)
- [UID:0002O5][0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange](by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange.md)
- [UID:0002O6][0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor](by-memory/0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor.md)
- [UID:0002O7][0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm](by-memory/0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm.md)
- [UID:0002O8][0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel](by-memory/0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel.md)
- [UID:00021X][0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor](by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md)
- [UID:00010N][0x0048a100-0x0048a1be.ClanItemDialogCore](by-memory/0x0048a100-0x0048a1be.ClanItemDialogCore.md)
- [UID:0002OC][0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail](by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md)
- [UID:0002OB][0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation](by-memory/0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation.md)
- [UID:00010O][0x0048a1c0-0x0048a805.ClanDepItemDialog](by-memory/0x0048a1c0-0x0048a805.ClanDepItemDialog.md)
- [UID:00010P][0x0048a810-0x0048ae65.ClanWidItemDialog](by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md)
- [UID:00010Q][0x0048ae70-0x0048b1b1.ClanItemListPane](by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md)
- [UID:00010R][0x0048b1c0-0x0048b7dc.ClanBankPane](by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md)
- [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md)
- [UID:00010S][0x0048b8c0-0x0048c251.ClanBankItemListPane](by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md)
- [UID:00012V][0x0049ec80-0x0049ee41.ClanDialogSlideAnimation](by-memory/0x0049ec80-0x0049ee41.ClanDialogSlideAnimation.md)
- [UID:00016B][0x004ba820-0x004ba991.TextFitAndSuffixHelpers](by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md)
- [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md)

## Changes

- 2026-05-27: The `ClanStatusPane` row previously skipped the raw `0x00484230-0x004842ad` cleanup bytes between constructor and parser coverage. Added [UID:00021B][0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup](by-memory/0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup.md) and marked it compiler-generated cleanup, not a standalone source method. Evidence: IDA raw disassembly shows vtable restoration, child-pane cleanup, singleton/global clear, and base teardown tail jump.
- 2026-05-27: The boundary note previously described the whole `0x00484f70-0x004889a0` span as needing owner review. Resolved [UID:00021C][0x00484f70-0x0048540b.ClanStatusPacketDispatcher](by-memory/0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md) and the adjacent opcode `0x4b` helper cluster [UID:00021D][0x00485440-0x004854a5.SendClanOpcode4BSubtype0Request](by-memory/0x00485440-0x004854a5.SendClanOpcode4BSubtype0Request.md) through [UID:00021H][0x00485690-0x004856f9.SendClanLeaveRequestPacket](by-memory/0x00485690-0x004856f9.SendClanLeaveRequestPacket.md) into the Clan module. Evidence: IDA MCP decompilation/disassembly, vtable xref at `0x006155cc`, packet opcode/subtype writes, and callers into [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md).
- 2026-05-27: The `0x00485778-0x00485ac0` gap after `SendClanLeaveResponse` was previously unresolved. Added [UID:00021I][0x00485780-0x00485867.ClanDepositMoneyPacketHelpers](by-memory/0x00485780-0x00485867.ClanDepositMoneyPacketHelpers.md), [UID:00021J][0x00485870-0x00485955.ClanDepositItemPacketHelpers](by-memory/0x00485870-0x00485955.ClanDepositItemPacketHelpers.md), and [UID:00021K][0x00485960-0x00485abe.ClanSubtype6PacketHelpers](by-memory/0x00485960-0x00485abe.ClanSubtype6PacketHelpers.md), then reduced the still-unreviewed neighbor note to `0x00485cbd-0x004889a0`. Evidence: IDA MCP raw disassembly, decompilation of `sub_485960`/`sub_4859D0`, and xrefs from `0x00487600`, `0x00488970`, and `0x004889a0`.
- 2026-05-27: The `0x00485cbd-0x00486330` gap before `SubmitClanChangeHelper_486330` was previously unresolved. Added [UID:00021L][0x00485cc0-0x0048632e.ClanNameActionPacketHelpers](by-memory/0x00485cc0-0x0048632e.ClanNameActionPacketHelpers.md), then reduced the still-unreviewed neighbor note to `0x0048652d-0x004889a0`. Evidence: IDA MCP raw disassembly showing repeated opcode `0x4b` subtype `6-10` helper patterns and alignment before `sub_486330`.
- 2026-05-27: The `0x0048652d-0x00486800` gap before `ClanStatusPaneRows` was previously unresolved. Added [UID:00021M][0x00486530-0x004867f2.ClanWithdrawAndNoticePacketHelpers](by-memory/0x00486530-0x004867f2.ClanWithdrawAndNoticePacketHelpers.md), then reduced the still-unreviewed neighbor note to `0x00487291-0x004889a0`. Evidence: IDA MCP raw disassembly showing opcode `0x4b` subtype `11-13` helper patterns and alignment before `sub_486800`.
- 2026-05-27: The `0x00487291-0x00487600` gap before `ClanStatusRowActionPacket` was previously unresolved, and `0x00487370` had been listed under `ClanEnlistInputDialog`. Added [UID:00021N][0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper](by-memory/0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper.md) through [UID:00021R][0x00487540-0x004875f5.ClanStatusPaneShowEnlistList](by-memory/0x00487540-0x004875f5.ClanStatusPaneShowEnlistList.md), then reduced the still-unreviewed neighbor note to `0x0048779f-0x004889a0`. Evidence: IDA MCP item/xref audit, `ClanStatusPane` child offsets `+0x2510/+0x2514/+0x2518`, and negative vtable scan for `0x00487370` in `ClanEnlistInputDialog`.
- 2026-05-27: Corrected `ClanAttrInputDialog` core end from `0x00489f7f` to `0x00489f80` and promoted the `ClanEnlistInputDialog` projected constructor at `0x00489f80` to bounded raw constructor [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md). Evidence: IDA MCP reports `sub_489F50` at `0x00489f50-0x00489f80`, constructor-shaped bytes at `0x00489f80-0x00489fb5`, then padding before `sub_489FC0`.
- 2026-05-27: Promoted the `ClanItemDialog` projected constructor at `0x0048a0c0` to bounded raw constructor [UID:00021X][0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor](by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md). Evidence: IDA MCP reports constructor-shaped bytes that install `ClanItemDialog` vtables, surrounded by alignment padding at `0x0048a0be-0x0048a0c0` and `0x0048a0fb-0x0048a100`.
- 2026-05-31: Split the `ClanItemDialog` core helper references into exact child pages.
  - What existed before: this source-layout page listed `0x0048a100` and `0x0048a120` only as raw helper addresses.
  - Changed to: linked [UID:0002OC][0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail](by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md) and [UID:0002OB][0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation](by-memory/0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation.md).
  - Summary and evidence: IDA MCP confirms both function bounds and shows the confirm callback calls reusable [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder.md), so text-control implementation remains outside clan ownership.
- 2026-05-27: Corrected `ClanItemListPane` from `0x0048ae70-0x0048b1b0` to `0x0048ae70-0x0048b1b1`. Evidence: IDA MCP reports `sub_48B0A0` through `0x0048b1b1`, then alignment padding before `ClanBankPane`.
- 2026-05-27: Corrected `ClanBankPane` from `0x0048b1c0-0x0048b7db` to `0x0048b1c0-0x0048b7dc` and added raw bank packet helpers [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md). Evidence: IDA MCP byte audit found helper-shaped opcode `0x36` packet bodies between `ClanBankPane` and `ClanBankItemListPane`.
- 2026-05-27: Corrected `ClanBankItemListPane` from `0x0048b8c0-0x0048c250` to `0x0048b8c0-0x0048c251`. Evidence: IDA MCP reports `sub_48C040` through `0x0048c251`, then alignment padding before the destructor band.
- 2026-05-27: The `0x0048779f-0x00488610` gap before `ClanListPaneVirtuals` was previously unresolved. Added [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md), [UID:00021T][0x004885a0-0x00488602.ClanInfoListPaneRawConstructor](by-memory/0x004885a0-0x00488602.ClanInfoListPaneRawConstructor.md), and classified the row-action switch table plus alignment padding in [UID:0000VN][-ignored](by-memory/-ignored.md), then reduced the still-unreviewed neighbor note to `0x004888f0-0x00488b40`. Evidence: IDA MCP function inventory, decompilation, xrefs, and raw byte audit on 2026-05-27.
- 2026-05-27: The `0x004888f0-0x00488b40` gap before `ClanNameInputDialogCore` was previously unresolved. Added [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md), corrected the `sub_4888D0` end to `0x004888f1`, and classified surrounding/internal alignment in [UID:0000VN][-ignored](by-memory/-ignored.md). Evidence: IDA MCP function inventory, vtable data xrefs at `0x006157d4`, `0x00615898`, and `0x006158b0`, decompilation, and raw byte audit on 2026-05-27.
- 2026-05-27: The `0x00488f9f-0x00488fe0` gap before `ClanNameDialogSubmitters` was previously unresolved. Corrected [UID:00010J][0x00488b40-0x00488fa0.ClanNameInputDialogCore](by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md) to end at `0x00488fa0`, added [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md), and classified `0x00488fd5-0x00488fe0` alignment in [UID:0000VN][-ignored](by-memory/-ignored.md). Evidence: IDA MCP disassembly of `sub_488F70`, raw-head audit at `0x00488fa0`, and vtable stores to `0x00615998`, `0x006159fc`, and `0x00615a2c`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:90` and `CONFIDENCE:82`.
  - Summary/evidence: the page now gives a detailed top-level clan module map, status/dialog/list/bank relationships, packet helper ownership, many exact by-memory anchors, raw-constructor caveats, migration notes, and extensive change evidence; confidence remains below maximum because final Clan/ClanBank/ClanDialogs file splitting and several projected constructor boundaries are still open.
- 2026-05-31: Filled validator projected path and linked direct constructor evidence.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though this page and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) both place `Clan.cpp` under `social/`.
  - After: projected path is `NexusTK/social/`, and the page links the exact clan pane/list vtable and singleton slot docs used by `ClanStatusPane::ClanStatusPane`.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `social/Clan.cpp`; IDA MCP `xrefs_to` confirms the constructor writes the clan status singleton and installs the clan pane/list vtables.
- 2026-05-31: Replaced the address-only `SubmitClanChangeHelper_486330` contents row with the exact by-memory link.
  - Before: the row listed only `0x00486330-0x0048652d` and a short packet-shape note.
  - After: the row points to [UID:00010F][0x00486330-0x0048652d.SubmitClanChangeHelper](by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md) and summarizes the verified three-string clan-change packet.
  - Evidence: IDA MCP recheck of `0x00486330` and `0x0048a030` confirms the exact helper boundary, caller field offsets, and packet-buffer/send dependency chain.
- 2026-05-31: Replaced the address-only `ClanStatusRowActionPacket` contents row with the exact by-memory link and expanded the packet summary.
  - Before: the row listed only `0x00487600-0x0048779f` and a short row-to-subcommand note.
  - After: the row points to [UID:00010H][0x00487600-0x0048779f.ClanStatusRowActionPacket](by-memory/0x00487600-0x0048779f.ClanStatusRowActionPacket.md) and records the verified `{ 0x4b, subtype, 0 }` packet family plus the row `7` subtype `6` delegate.
  - Evidence: IDA MCP recheck of `0x00487600` confirms the exact function boundary, one caller at `0x00484e91` inside `ClanStatusPane::OnMouseEvent`, switch-table xref at `0x004877a0`, calls to the shared packet writer/send helpers, and row `7` delegation to `0x00485960`.
- 2026-05-31: Split `ClanListPaneVirtuals` contents into exact child memory pages.
  - Before: `ClanInfoListPane`, `ClanStringListPane`, `ClanJoinListPane`, and `ClanEnlistListPane` rows used raw addresses for the list-pane virtual island and treated `0x00488630` only as a projected constructor start.
  - After: rows link exact docs for the `ClanInfoListPane` false virtuals, raw `ClanStringListPane` constructor-shaped block, shared draw method, and `ClanJoinListPane` selected-row action.
  - Evidence: IDA MCP 2026-05-31 `lookup_funcs`, `decompile`, `xrefs_to`, `callers`, and `py_eval` checks confirm child boundaries, vtable xrefs, no direct callers for virtual dispatch, no function/xrefs at `0x00488630`, and internal alignment spans.
- 2026-05-31: Split `ClanNameDialogSubmitters` contents into exact child memory pages.
  - Before: `ClanDepMoneyInputDialog` through `ClanChangeNameInputDialog` rows used raw submitter addresses and projected constructor addresses under broad [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md).
  - After: rows link exact docs for six submitter functions, five newly bounded raw constructor-shaped bodies, and the existing `ClanDepMoneyInputDialog` raw constructor page.
  - Evidence: IDA MCP 2026-05-31 `lookup_funcs`, `xrefs_to`, `callers`, `callees`, decompilation, raw constructor disassembly, and byte audit confirm exact function sizes, vtable data refs, constructor-shaped vtable stores, no raw-constructor xrefs, and all internal `0xcc` alignment spans.
- 2026-05-31: Split `ClanEnlistChangeLeaveSubmitters` contents into exact child memory pages.
  - Before: `ClanEnlistInputDialog`, `ClanChangeInputDialog`, and `ClanLeaveConfirmDialog` rows used raw addresses or projected constructor starts under broad [UID:00010M][0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters](by-memory/0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters.md).
  - After: rows link exact docs for the enlist submitter, change raw constructor and submitter, leave raw constructor, and leave confirm/cancel callbacks, with internal padding tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).
  - Evidence: IDA MCP 2026-05-31 `lookup_funcs`, `xrefs_to`, `callers`, `callees`, decompilation, raw constructor disassembly, and byte audit confirm exact function sizes, vtable data refs, helper calls, constructor-shaped vtable stores, no raw-constructor function objects, and all internal `0xcc` alignment spans.
