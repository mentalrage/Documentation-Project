# Auto Completion Stats

Scores use `COMPLETION` and `CONFIDENCE` metadata from validator-scanned by-* Markdown files.
`0` means unevaluated. `-1` means ignored and is excluded from low-score lists.
`Combined` is the average of completion and confidence.
Scored tables are split by `RECONSTRUCTABLE:true` versus every other reconstructable state.

## Summary

- Tracked files: 6689
- Scored files: 6513
- Scored reconstructable files: 4871
- Scored not reconstructable/blank files: 1642
- Ignored files: 176
- Reconstructable row limit per scored section: 125
- Not reconstructable row limit per scored section: 34

## projected_path_completion

By-file documents whose `PROPOSED_RECONSTRUCTION_PATH` is blank or invalid. `NONE` marks a reviewed non-standalone page and is excluded.

_All by-file documents have valid projected reconstruction paths or reviewed non-standalone dispositions._
## Low_Completion_Reconstructable

Lowest-scored files whose `RECONSTRUCTABLE` metadata is `true`.

| UID | Completion | Confidence | Combined | Path |
| --- | ---: | ---: | ---: | --- |
| `00041T` | 84 | 88 | 86.0 | `by-memory/0x004df1e0-0x004df2b7.ItemObjImageLibDrawItemImageUnscaled.md` |
| `000049` | 85 | 86 | 85.5 | `by-class/EffectObjectPane.md` |
| `0000AJ` | 85 | 86 | 85.5 | `by-class/PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_.md` |
| `0000AK` | 85 | 86 | 85.5 | `by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md` |
| `00000J` | 85 | 87 | 86.0 | `by-class/ArticleDialog.md` |
| `00000Y` | 85 | 87 | 86.0 | `by-class/BlueAlertPane.md` |
| `000018` | 85 | 87 | 86.0 | `by-class/BrowserDialogOld.md` |
| `00005Y` | 85 | 87 | 86.0 | `by-class/GroupPane.md` |
| `00009B` | 85 | 87 | 86.0 | `by-class/NewSystemMessageModifyHeightPane.md` |
| `0004EW` | 85 | 87 | 86.0 | `by-memory/0x005566b0-0x005566ba.RingBufferFullPredicateAlias.md` |
| `00044Z` | 85 | 87 | 86.0 | `by-memory/0x005609e0-0x00560a04.ScrollNewGroupPaneStyleByteSetterRaw.md` |
| `00000K` | 85 | 88 | 86.5 | `by-class/ArticleListDialog.md` |
| `00001A` | 85 | 88 | 86.5 | `by-class/BrowserThread.md` |
| `00001B` | 85 | 88 | 86.5 | `by-class/BrowserWindow.md` |
| `00001T` | 85 | 88 | 86.5 | `by-class/ChattingColorPane.md` |
| `00002T` | 85 | 88 | 86.5 | `by-class/CloudFilterEffecter.md` |
| `00003W` | 85 | 88 | 86.5 | `by-class/DIError.md` |
| `000045` | 85 | 88 | 86.5 | `by-class/DSError.md` |
| `000041` | 85 | 88 | 86.5 | `by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md` |
| `00004K` | 85 | 88 | 86.5 | `by-class/ErrorMessage.md` |
| `000057` | 85 | 88 | 86.5 | `by-class/FlyingObjectPane.md` |
| `00005K` | 85 | 88 | 86.5 | `by-class/FunctionObject.md` |
| `00005L` | 85 | 88 | 86.5 | `by-class/FunctionObject0.md` |
| `00005S` | 85 | 88 | 86.5 | `by-class/GiveAllInputPane.md` |
| `00005U` | 85 | 88 | 86.5 | `by-class/GiveInputPane.md` |
| `00005Z` | 85 | 88 | 86.5 | `by-class/GroupPane2.md` |
| `00006N` | 85 | 88 | 86.5 | `by-class/InterfaceEfx.md` |
| `00006P` | 85 | 88 | 86.5 | `by-class/InternetConnectionError.md` |
| `00006Q` | 85 | 88 | 86.5 | `by-class/InternetError.md` |
| `00009T` | 85 | 88 | 86.5 | `by-class/OldSystemMessagePane.md` |
| `0000AI` | 85 | 88 | 86.5 | `by-class/PixelEffecter.md` |
| `0000DE` | 85 | 88 | 86.5 | `by-class/SolidColorFilterEffecter.md` |
| `0000EH` | 85 | 88 | 86.5 | `by-class/TerminalSetupPane.md` |
| `000014` | 85 | 88 | 86.5 | `by-class/browser__Notification.md` |
| `0000YR` | 85 | 88 | 86.5 | `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md` |
| `000123` | 85 | 88 | 86.5 | `by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md` |
| `0003LP` | 85 | 88 | 86.5 | `by-memory/0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor.md` |
| `0002R4` | 85 | 88 | 86.5 | `by-memory/0x00543670-0x005436f4.PaletteCollectionColorTransformRaw.md` |
| `0003OB` | 85 | 88 | 86.5 | `by-memory/0x0055b4c0-0x0055b5c3.YFlipEffecterApplyEffect.md` |
| `0003HC` | 85 | 88 | 86.5 | `by-memory/0x0055b860-0x0055b866.LakeEffecterResetVtable.md` |
| `00044Y` | 85 | 88 | 86.5 | `by-memory/0x005609b0-0x005609d7.ScrollNewGroupPaneSkinIndexSetterRaw.md` |
| `0003QG` | 85 | 88 | 86.5 | `by-memory/0x005671a0-0x005671b7.SelfLookPaneSpelledEntryRemoveForwarderRaw.md` |
| `0003R4` | 85 | 88 | 86.5 | `by-memory/0x00570b80-0x00570b9a.SelfLookPane2SpelledEntryUpdateForwarderRaw.md` |
| `0003R5` | 85 | 88 | 86.5 | `by-memory/0x00570ba0-0x00570bb7.SelfLookPane2SpelledEntryRemoveForwarderRaw.md` |
| `0003R6` | 85 | 88 | 86.5 | `by-memory/0x00570bc0-0x00570bde.SelfLookPane2RefreshSpelledChildRaw.md` |
| `0003R7` | 85 | 88 | 86.5 | `by-memory/0x00570be0-0x00570bf1.SelfLookPane2RefreshSpelledChildStateRaw.md` |
| `0003YL` | 85 | 88 | 86.5 | `by-memory/0x00575580-0x0057564e.PacketBufferHostAddressResolutionHelpers.md` |
| `0003YO` | 85 | 88 | 86.5 | `by-memory/0x005757d0-0x00575a07.PacketBufferStringWriteHelpers.md` |
| `0003A6` | 85 | 88 | 86.5 | `by-memory/0x00576570-0x00576623.SocketReconnectEndpointRaw.md` |
| `0003A7` | 85 | 88 | 86.5 | `by-memory/0x00577610-0x0057779e.SocketOpenSerialTransportRaw.md` |
| `0003FD` | 85 | 88 | 86.5 | `by-memory/0x00593f00-0x0059403b.DrawTextRunCallbackThiscallRaw.md` |
| `0003FK` | 85 | 88 | 86.5 | `by-memory/0x005b4760-0x005b47dc.SendDropAllItemPacketRaw.md` |
| `0003FL` | 85 | 88 | 86.5 | `by-memory/0x005b4af0-0x005b4b6c.SendDropItemPacketRaw.md` |
| `0003FM` | 85 | 88 | 86.5 | `by-memory/0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw.md` |
| `0003FN` | 85 | 88 | 86.5 | `by-memory/0x005b4ef0-0x005b4f6c.SendGiveAllItemPacketRaw.md` |
| `0003FO` | 85 | 88 | 86.5 | `by-memory/0x005b5230-0x005b52ac.SendGiveItemPacketRaw.md` |
| `0003NX` | 85 | 88 | 86.5 | `by-memory/0x005b5ab0-0x005b5b2c.SendThrowItemPacketRaw.md` |
| `0003AH` | 85 | 88 | 86.5 | `by-memory/0x005bc890-0x005bc96a.MenuVarietyPaneButtonRectHelpers.md` |
| `0003AJ` | 85 | 88 | 86.5 | `by-memory/0x005bffe0-0x005c0034.MenuVarietyLabelVectorAppendMoveHelper.md` |
| `0003O4` | 85 | 88 | 86.5 | `by-memory/0x005c2a20-0x005c2a5b.SnowingLayerPaneScalarDeletingDestructor.md` |
| `0003ST` | 85 | 88 | 86.5 | `by-memory/0x005c50f0-0x005c5156.WorldMapPaneUpdateHoverFromMouseStrict.md` |
| `0003SU` | 85 | 88 | 86.5 | `by-memory/0x005c5160-0x005c519c.WorldMapPaneFindPredecessorNode.md` |
| `0003SV` | 85 | 88 | 86.5 | `by-memory/0x005c51a0-0x005c51fb.WorldMapPaneScreenPointHelper.md` |
| `0001VH` | 85 | 88 | 86.5 | `by-type/by-struct/PaneLayout.md` |
| `000028` | 85 | 89 | 87.0 | `by-class/ClanChangeNameInputDialog.md` |
| `00002M` | 85 | 89 | 87.0 | `by-class/ClanSummonNameInputDialog.md` |
| `00004Z` | 85 | 89 | 87.0 | `by-class/FittingEquipmentState.md` |
| `00021D` | 85 | 89 | 87.0 | `by-memory/0x00485440-0x004854a5.SendClanStatusRefreshRequestPacket.md` |
| `00021I` | 85 | 89 | 87.0 | `by-memory/0x00485780-0x00485867.ClanDepositMoneyRequestAndSubmitPacketHelpers.md` |
| `00021J` | 85 | 89 | 87.0 | `by-memory/0x00485870-0x00485955.ClanDepositItemRequestAndSubmitPacketHelpers.md` |
| `000377` | 85 | 89 | 87.0 | `by-memory/0x00516c40-0x00516c9a.MenuPaneFindPreviousEnabledItemRaw.md` |
| `000378` | 85 | 89 | 87.0 | `by-memory/0x00516ca0-0x00516cf3.MenuPaneFindNextEnabledItemRaw.md` |
| `0001CO` | 85 | 89 | 87.0 | `by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md` |
| `0003QA` | 85 | 89 | 87.0 | `by-memory/0x00565890-0x00566f24.SelfLookPaneOnReceiveCharacterData.md` |
| `0003QK` | 85 | 89 | 87.0 | `by-memory/0x00567280-0x005672b0.SelfLookPaneActivateView.md` |
| `0003QL` | 85 | 89 | 87.0 | `by-memory/0x005672b0-0x0056737f.SelfLookPaneDeactivateResetRaw.md` |
| `0003QM` | 85 | 89 | 87.0 | `by-memory/0x00567380-0x00567472.SelfLookPaneDeactivateView.md` |
| `0003QO` | 85 | 89 | 87.0 | `by-memory/0x00568bd0-0x00568ca9.SelfLookPaneOnKeyPress.md` |
| `0003QR` | 85 | 89 | 87.0 | `by-memory/0x00569860-0x00569c80.SelfLookPaneOnShowHelp.md` |
| `0003QS` | 85 | 89 | 87.0 | `by-memory/0x00569c80-0x00569cce.SelfLookPaneOnGetRect.md` |
| `0003QT` | 85 | 89 | 87.0 | `by-memory/0x00569cd0-0x00569d75.SelfLookPaneOnTransformRect.md` |
| `00039L` | 85 | 89 | 87.0 | `by-memory/0x005729e0-0x00572b54.SelfLookPane2PacketSendRawHelpers.md` |
| `0003RJ` | 85 | 89 | 87.0 | `by-memory/0x0059f500-0x0059f604.UserLookPaneNonDeletingDestructor.md` |
| `0003AI` | 85 | 89 | 87.0 | `by-memory/0x005bd960-0x005bd9ad.MenuVarietySelectPaneRowRectHelper.md` |
| `0003SE` | 85 | 89 | 87.0 | `by-memory/0x005c3420-0x005c346d.WorldMapPaneSetViewPosition.md` |
| `0003SF` | 85 | 89 | 87.0 | `by-memory/0x005c34c0-0x005c3508.WorldMapPaneStartViewAnimation.md` |
| `0003SH` | 85 | 89 | 87.0 | `by-memory/0x005c3630-0x005c36c8.WorldMapPaneSendTravelPacket.md` |
| `0003SL` | 85 | 89 | 87.0 | `by-memory/0x005c3e50-0x005c402b.WorldMapPaneHandleKeyEvent.md` |
| `0003SM` | 85 | 89 | 87.0 | `by-memory/0x005c40c0-0x005c4245.WorldMapPaneHandleMouseEvent.md` |
| `0003SO` | 85 | 89 | 87.0 | `by-memory/0x005c46f0-0x005c4733.WorldMapPaneOnTimerTick.md` |
| `0003SQ` | 85 | 89 | 87.0 | `by-memory/0x005c48b0-0x005c4bd0.WorldMapPaneDrawPlayerMarker.md` |
| `0003NI` | 85 | 89 | 87.0 | `by-memory/0x0061a374-0x0061a37c.AddItemWithCountDialogQuantityFormatString.md` |
| `0001TN` | 85 | 89 | 87.0 | `by-type/by-struct/AddEmployeeItemDialogLayout.md` |
| `00000U` | 85 | 90 | 87.5 | `by-class/BalloonObjectPane.md` |
| `00005N` | 85 | 90 | 87.5 | `by-class/FunctionObjectT_near_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t____const___.md` |
| `0000PV` | 85 | 90 | 87.5 | `by-global/g_browserWindowClassName.md` |
| `0000RU` | 85 | 90 | 87.5 | `by-global/g_pNewSystemMessagePane.md` |
| `0000UD` | 85 | 90 | 87.5 | `by-item/DecodePcxToRgb565Buffer_00549410.md` |
| `0000US` | 85 | 90 | 87.5 | `by-item/HalfBlendSpan16Blocks_00460C10.md` |
| `0000V7` | 85 | 90 | 87.5 | `by-item/PhoneBookListHelpers_58cfa0_58dcb0.md` |
| `0000VE` | 85 | 90 | 87.5 | `by-item/ScreenEffecterSmallConstructorBoundaries.md` |
| `00020U` | 85 | 90 | 87.5 | `by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md` |
| `00021E` | 85 | 90 | 87.5 | `by-memory/0x004854b0-0x00485518.SendClanEnlistRequestRefreshPacket.md` |
| `00021F` | 85 | 90 | 87.5 | `by-memory/0x00485520-0x00485588.SendClanJoinListRefreshPacket.md` |
| `00021H` | 85 | 90 | 87.5 | `by-memory/0x00485690-0x004856f9.SendClanLeaveRequestPacket.md` |
| `000139` | 85 | 90 | 87.5 | `by-memory/0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor.md` |
| `0003LZ` | 85 | 90 | 87.5 | `by-memory/0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable.md` |
| `00037O` | 85 | 90 | 87.5 | `by-memory/0x004f3980-0x004f398b.SortedListClear.md` |
| `0003HW` | 85 | 90 | 87.5 | `by-memory/0x00537d60-0x00537d7f.FlyingObjectPaneNonDeletingDestructor.md` |
| `000394` | 85 | 90 | 87.5 | `by-memory/0x00559dd0-0x00559e2d.ScreenDimmerOnPaint.md` |
| `0003Q9` | 85 | 90 | 87.5 | `by-memory/0x005657e0-0x00565887.SelfLookPaneNonDeletingDestructor.md` |

## Low_Completion_Not_Reconstructable

Lowest-scored files whose `RECONSTRUCTABLE` metadata is false, blank, or invalid.

| UID | Completion | Confidence | Combined | Path |
| --- | ---: | ---: | ---: | --- |
| `0004B1` | 82 | 86 | 84.0 | `by-memory/0x0054a960-0x0054aa96.PowerDialogPaneUnreferencedApplyAllThresholdsRaw.md` |
| `0004B2` | 82 | 86 | 84.0 | `by-memory/0x0054aaa0-0x0054ab87.PowerDialogPaneUnreferencedSelectedPowerSlotRaw.md` |
| `0001MO` | 82 | 88 | 85.0 | `by-memory/0x005b6120-0x005b62c8.SpellSpellInputPane.md` |
| `00043Z` | 84 | 86 | 85.0 | `by-memory/0x0052b950-0x0052b981.NewUserDialogPane2ClearGenderSelectionButtonsRaw.md` |
| `000440` | 84 | 86 | 85.0 | `by-memory/0x0052b990-0x0052b9ed.NewUserDialogPane2ClearTotemSelectionButtonsRaw.md` |
| `00021B` | 84 | 88 | 86.0 | `by-memory/0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup.md` |
| `0001ZV` | 84 | 90 | 87.0 | `by-memory/0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport.md` |
| `0001ZW` | 84 | 90 | 87.0 | `by-memory/0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport.md` |
| `0001ZX` | 84 | 90 | 87.0 | `by-memory/0x00442090-0x00443a55.JsonCppWriterRuntimeTailSupport.md` |
| `0000ZM` | 84 | 90 | 87.0 | `by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md` |
| `000102` | 84 | 90 | 87.0 | `by-memory/0x0047ef40-0x0047ef4b.ClearChangeManSingleton.md` |
| `0002GI` | 84 | 90 | 87.0 | `by-memory/0x004839c0-0x00483ef7.ChattingUiDestructorGlueFamily.md` |
| `00017C` | 84 | 90 | 87.0 | `by-memory/0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster.md` |
| `0001AF` | 84 | 90 | 87.0 | `by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md` |
| `0001CK` | 84 | 90 | 87.0 | `by-memory/0x00528290-0x005283d5.CashShopRequestAuthDirectory.md` |
| `00039J` | 84 | 90 | 87.0 | `by-memory/0x00573970-0x00573979.ZeroInitializePointerHelper.md` |
| `0003CE` | 84 | 90 | 87.0 | `by-memory/0x00620c68-0x00620c6c.SharedMinimumFloatConstant.md` |
| `0001VU` | 84 | 90 | 87.0 | `by-type/by-struct/ResourceLayoutStore.md` |
| `00039H` | 84 | 91 | 87.5 | `by-memory/0x00573880-0x005738fc.SpelledPaneEntryVectorCopyHelper.md` |
| `0002EE` | 85 | 87 | 86.0 | `by-memory/0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md` |
| `00000E` | 85 | 88 | 86.5 | `by-class/ApplicationHelper_4A6C40.md` |
| `0000HE` | 85 | 88 | 86.5 | `by-file/AlertPanes.md` |
| `0000WT` | 85 | 88 | 86.5 | `by-memory/0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland.md` |
| `000229` | 85 | 88 | 86.5 | `by-memory/0x004a60a0-0x004a60cb.MsvcInt64RuntimeHelpers.md` |
| `00014X` | 85 | 88 | 86.5 | `by-memory/0x004b08cd-0x004b08e3.ExchangeAlertPaneAdjustorThunks.md` |
| `00014Y` | 85 | 88 | 86.5 | `by-memory/0x004b0ab5-0x004b0acb.ExchangeMoneyEditControlPaneAdjustorThunks.md` |
| `00019I` | 85 | 88 | 86.5 | `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md` |
| `00019U` | 85 | 88 | 86.5 | `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md` |
| `0003VP` | 85 | 88 | 86.5 | `by-memory/0x00516040-0x00516045.MemoryManNoXrefReturnZeroStub.md` |
| `0003QB` | 85 | 88 | 86.5 | `by-memory/0x00566f30-0x00566f31.SelfLookPaneNullStub.md` |
| `0003R0` | 85 | 88 | 86.5 | `by-memory/0x00570930-0x00570931.SelfLookPane2NullStub.md` |
| `0003RL` | 85 | 88 | 86.5 | `by-memory/0x005a0630-0x005a0631.UserLookPaneNullStub.md` |
| `0002S8` | 85 | 88 | 86.5 | `by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md` |

## Low_Confidence_Reconstructable

Lowest-scored files whose `RECONSTRUCTABLE` metadata is `true`.

| UID | Completion | Confidence | Combined | Path |
| --- | ---: | ---: | ---: | --- |
| `000049` | 85 | 86 | 85.5 | `by-class/EffectObjectPane.md` |
| `0000AJ` | 85 | 86 | 85.5 | `by-class/PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_.md` |
| `0000AK` | 85 | 86 | 85.5 | `by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md` |
| `0000CP` | 86 | 86 | 86.0 | `by-class/ScrollWidget.md` |
| `0003GY` | 86 | 86 | 86.0 | `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md` |
| `00000J` | 85 | 87 | 86.0 | `by-class/ArticleDialog.md` |
| `00000Y` | 85 | 87 | 86.0 | `by-class/BlueAlertPane.md` |
| `000018` | 85 | 87 | 86.0 | `by-class/BrowserDialogOld.md` |
| `00005Y` | 85 | 87 | 86.0 | `by-class/GroupPane.md` |
| `00009B` | 85 | 87 | 86.0 | `by-class/NewSystemMessageModifyHeightPane.md` |
| `0004EW` | 85 | 87 | 86.0 | `by-memory/0x005566b0-0x005566ba.RingBufferFullPredicateAlias.md` |
| `00044Z` | 85 | 87 | 86.0 | `by-memory/0x005609e0-0x00560a04.ScrollNewGroupPaneStyleByteSetterRaw.md` |
| `0000E0` | 86 | 87 | 86.5 | `by-class/StaticCloudFilterEffecter.md` |
| `0000EA` | 86 | 87 | 86.5 | `by-class/SystemMessagePane.md` |
| `0000GC` | 86 | 87 | 86.5 | `by-class/XWaveEffecter.md` |
| `00041A` | 86 | 87 | 86.5 | `by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md` |
| `00041T` | 84 | 88 | 86.0 | `by-memory/0x004df1e0-0x004df2b7.ItemObjImageLibDrawItemImageUnscaled.md` |
| `00000K` | 85 | 88 | 86.5 | `by-class/ArticleListDialog.md` |
| `00001A` | 85 | 88 | 86.5 | `by-class/BrowserThread.md` |
| `00001B` | 85 | 88 | 86.5 | `by-class/BrowserWindow.md` |
| `00001T` | 85 | 88 | 86.5 | `by-class/ChattingColorPane.md` |
| `00002T` | 85 | 88 | 86.5 | `by-class/CloudFilterEffecter.md` |
| `00003W` | 85 | 88 | 86.5 | `by-class/DIError.md` |
| `000045` | 85 | 88 | 86.5 | `by-class/DSError.md` |
| `000041` | 85 | 88 | 86.5 | `by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md` |
| `00004K` | 85 | 88 | 86.5 | `by-class/ErrorMessage.md` |
| `000057` | 85 | 88 | 86.5 | `by-class/FlyingObjectPane.md` |
| `00005K` | 85 | 88 | 86.5 | `by-class/FunctionObject.md` |
| `00005L` | 85 | 88 | 86.5 | `by-class/FunctionObject0.md` |
| `00005S` | 85 | 88 | 86.5 | `by-class/GiveAllInputPane.md` |
| `00005U` | 85 | 88 | 86.5 | `by-class/GiveInputPane.md` |
| `00005Z` | 85 | 88 | 86.5 | `by-class/GroupPane2.md` |
| `00006N` | 85 | 88 | 86.5 | `by-class/InterfaceEfx.md` |
| `00006P` | 85 | 88 | 86.5 | `by-class/InternetConnectionError.md` |
| `00006Q` | 85 | 88 | 86.5 | `by-class/InternetError.md` |
| `00009T` | 85 | 88 | 86.5 | `by-class/OldSystemMessagePane.md` |
| `0000AI` | 85 | 88 | 86.5 | `by-class/PixelEffecter.md` |
| `0000DE` | 85 | 88 | 86.5 | `by-class/SolidColorFilterEffecter.md` |
| `0000EH` | 85 | 88 | 86.5 | `by-class/TerminalSetupPane.md` |
| `000014` | 85 | 88 | 86.5 | `by-class/browser__Notification.md` |
| `0000YR` | 85 | 88 | 86.5 | `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md` |
| `000123` | 85 | 88 | 86.5 | `by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md` |
| `0003LP` | 85 | 88 | 86.5 | `by-memory/0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor.md` |
| `0002R4` | 85 | 88 | 86.5 | `by-memory/0x00543670-0x005436f4.PaletteCollectionColorTransformRaw.md` |
| `0003OB` | 85 | 88 | 86.5 | `by-memory/0x0055b4c0-0x0055b5c3.YFlipEffecterApplyEffect.md` |
| `0003HC` | 85 | 88 | 86.5 | `by-memory/0x0055b860-0x0055b866.LakeEffecterResetVtable.md` |
| `00044Y` | 85 | 88 | 86.5 | `by-memory/0x005609b0-0x005609d7.ScrollNewGroupPaneSkinIndexSetterRaw.md` |
| `0003QG` | 85 | 88 | 86.5 | `by-memory/0x005671a0-0x005671b7.SelfLookPaneSpelledEntryRemoveForwarderRaw.md` |
| `0003R4` | 85 | 88 | 86.5 | `by-memory/0x00570b80-0x00570b9a.SelfLookPane2SpelledEntryUpdateForwarderRaw.md` |
| `0003R5` | 85 | 88 | 86.5 | `by-memory/0x00570ba0-0x00570bb7.SelfLookPane2SpelledEntryRemoveForwarderRaw.md` |
| `0003R6` | 85 | 88 | 86.5 | `by-memory/0x00570bc0-0x00570bde.SelfLookPane2RefreshSpelledChildRaw.md` |
| `0003R7` | 85 | 88 | 86.5 | `by-memory/0x00570be0-0x00570bf1.SelfLookPane2RefreshSpelledChildStateRaw.md` |
| `0003YL` | 85 | 88 | 86.5 | `by-memory/0x00575580-0x0057564e.PacketBufferHostAddressResolutionHelpers.md` |
| `0003YO` | 85 | 88 | 86.5 | `by-memory/0x005757d0-0x00575a07.PacketBufferStringWriteHelpers.md` |
| `0003A6` | 85 | 88 | 86.5 | `by-memory/0x00576570-0x00576623.SocketReconnectEndpointRaw.md` |
| `0003A7` | 85 | 88 | 86.5 | `by-memory/0x00577610-0x0057779e.SocketOpenSerialTransportRaw.md` |
| `0003FD` | 85 | 88 | 86.5 | `by-memory/0x00593f00-0x0059403b.DrawTextRunCallbackThiscallRaw.md` |
| `0003FK` | 85 | 88 | 86.5 | `by-memory/0x005b4760-0x005b47dc.SendDropAllItemPacketRaw.md` |
| `0003FL` | 85 | 88 | 86.5 | `by-memory/0x005b4af0-0x005b4b6c.SendDropItemPacketRaw.md` |
| `0003FM` | 85 | 88 | 86.5 | `by-memory/0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw.md` |
| `0003FN` | 85 | 88 | 86.5 | `by-memory/0x005b4ef0-0x005b4f6c.SendGiveAllItemPacketRaw.md` |
| `0003FO` | 85 | 88 | 86.5 | `by-memory/0x005b5230-0x005b52ac.SendGiveItemPacketRaw.md` |
| `0003NX` | 85 | 88 | 86.5 | `by-memory/0x005b5ab0-0x005b5b2c.SendThrowItemPacketRaw.md` |
| `0003AH` | 85 | 88 | 86.5 | `by-memory/0x005bc890-0x005bc96a.MenuVarietyPaneButtonRectHelpers.md` |
| `0003AJ` | 85 | 88 | 86.5 | `by-memory/0x005bffe0-0x005c0034.MenuVarietyLabelVectorAppendMoveHelper.md` |
| `0003O4` | 85 | 88 | 86.5 | `by-memory/0x005c2a20-0x005c2a5b.SnowingLayerPaneScalarDeletingDestructor.md` |
| `0003ST` | 85 | 88 | 86.5 | `by-memory/0x005c50f0-0x005c5156.WorldMapPaneUpdateHoverFromMouseStrict.md` |
| `0003SU` | 85 | 88 | 86.5 | `by-memory/0x005c5160-0x005c519c.WorldMapPaneFindPredecessorNode.md` |
| `0003SV` | 85 | 88 | 86.5 | `by-memory/0x005c51a0-0x005c51fb.WorldMapPaneScreenPointHelper.md` |
| `0001VH` | 85 | 88 | 86.5 | `by-type/by-struct/PaneLayout.md` |
| `00001C` | 86 | 88 | 87.0 | `by-class/BulletinDialog.md` |
| `00001S` | 86 | 88 | 87.0 | `by-class/ChattingColorListPane.md` |
| `000042` | 86 | 88 | 87.0 | `by-class/DropAllInputPane.md` |
| `000044` | 86 | 88 | 87.0 | `by-class/DropInputPane.md` |
| `000047` | 86 | 88 | 87.0 | `by-class/EatInputPane.md` |
| `00005M` | 86 | 88 | 87.0 | `by-class/FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____.md` |
| `000070` | 86 | 88 | 87.0 | `by-class/LakeEffecter.md` |
| `00007Y` | 86 | 88 | 87.0 | `by-class/MenuQuestionDialogLarger.md` |
| `00007Z` | 86 | 88 | 87.0 | `by-class/MenuQuestionItemList.md` |
| `00008B` | 86 | 88 | 87.0 | `by-class/MiniMapButtonPane.md` |
| `00008E` | 86 | 88 | 87.0 | `by-class/MiniMapImageControlPane.md` |
| `00008F` | 86 | 88 | 87.0 | `by-class/MiniMapRenderer.md` |
| `0000AL` | 86 | 88 | 87.0 | `by-class/PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6.md` |
| `0000F5` | 86 | 88 | 87.0 | `by-class/TransferReplyAlert.md` |
| `0000FA` | 86 | 88 | 87.0 | `by-class/TreeItor_near_class_EventHandler___.md` |
| `0000FG` | 86 | 88 | 87.0 | `by-class/UseInputPane.md` |
| `0000GD` | 86 | 88 | 87.0 | `by-class/YFlipEffecter.md` |
| `0000TO` | 86 | 88 | 87.0 | `by-global/VectorGrowMotion.md` |
| `0000PQ` | 86 | 88 | 87.0 | `by-global/g_activeDialogCount.md` |
| `0000QE` | 86 | 88 | 87.0 | `by-global/g_pBrowserThread.md` |
| `00040A` | 86 | 88 | 87.0 | `by-memory/0x0046a8e0-0x0046a901.BrowserPaneOnKeyEvent.md` |
| `0003KT` | 86 | 88 | 87.0 | `by-memory/0x004a2450-0x004a2531.EmployeeInventoryItemCommandHelper.md` |
| `00016Z` | 86 | 88 | 87.0 | `by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md` |
| `000417` | 86 | 88 | 87.0 | `by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md` |
| `000419` | 86 | 88 | 87.0 | `by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md` |
| `00041C` | 86 | 88 | 87.0 | `by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md` |
| `00041D` | 86 | 88 | 87.0 | `by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md` |
| `00041E` | 86 | 88 | 87.0 | `by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md` |
| `00041F` | 86 | 88 | 87.0 | `by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md` |
| `00041G` | 86 | 88 | 87.0 | `by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md` |
| `00035T` | 86 | 88 | 87.0 | `by-memory/0x004f2320-0x004f242f.LineInputPaneUpdateChildLayout.md` |
| `00035U` | 86 | 88 | 87.0 | `by-memory/0x004f2430-0x004f24b5.LineInputPaneAttachChildren.md` |
| `00035V` | 86 | 88 | 87.0 | `by-memory/0x004f24c0-0x004f24e5.LineInputPaneShowChildren.md` |
| `00035W` | 86 | 88 | 87.0 | `by-memory/0x004f24f0-0x004f257a.LineInputPaneHitTestForwarder.md` |
| `00035X` | 86 | 88 | 87.0 | `by-memory/0x004f2580-0x004f2598.LineInputPaneActiveChildForwarder.md` |
| `00035Z` | 86 | 88 | 87.0 | `by-memory/0x004f2760-0x004f2783.LineInputPaneTextEditForwarder.md` |
| `000361` | 86 | 88 | 87.0 | `by-memory/0x004f27a0-0x004f2813.NumberInputPaneConstructor.md` |
| `000362` | 86 | 88 | 87.0 | `by-memory/0x004f2820-0x004f289b.NumberInputPaneKeyFilter.md` |
| `000363` | 86 | 88 | 87.0 | `by-memory/0x004f28a0-0x004f2913.CharInputPaneConstructor.md` |
| `000365` | 86 | 88 | 87.0 | `by-memory/0x004f29d0-0x004f2a05.ConfirmInputPaneCompleteDestructor.md` |
| `000367` | 86 | 88 | 87.0 | `by-memory/0x004f2a60-0x004f2ad3.CharArgsInputPaneConstructor.md` |

## Low_Confidence_Not_Reconstructable

Lowest-scored files whose `RECONSTRUCTABLE` metadata is false, blank, or invalid.

| UID | Completion | Confidence | Combined | Path |
| --- | ---: | ---: | ---: | --- |
| `0000I8` | 90 | 85 | 87.5 | `by-file/Clan.md` |
| `0000KC` | 90 | 85 | 87.5 | `by-file/ItemActionInputPanes.md` |
| `00024H` | 90 | 85 | 87.5 | `by-memory/0x0060c43a-0x0060c440.AlignmentPaddingBeforeUniAPIInitCleanup.md` |
| `00024I` | 90 | 85 | 87.5 | `by-memory/0x0060c44b-0x0060c450.AlignmentPaddingBeforeUserPanePoolCleanup.md` |
| `00024K` | 90 | 85 | 87.5 | `by-memory/0x0060c4ac-0x0060d000.TextSectionTailFill.md` |
| `00028H` | 90 | 85 | 87.5 | `by-memory/0x0067a730-0x0067a738.CrtStdioOptionsStorage.md` |
| `0002B6` | 90 | 85 | 87.5 | `by-memory/0x0067adec-0x0067adf0.UnreferencedInitializedDword_67ADEC.md` |
| `0002AX` | 90 | 85 | 87.5 | `by-memory/0x0069af21-0x0069b328.UnreferencedInitializedBytes_69AF21.md` |
| `00029P` | 90 | 85 | 87.5 | `by-memory/0x0069b381-0x0069b39c.UnreferencedInitializedBytes_69B381.md` |
| `00027G` | 100 | 85 | 92.5 | `by-memory/0x0066da9a-0x0066da9c.DisplayDimensionPadding.md` |
| `00027H` | 100 | 85 | 92.5 | `by-memory/0x0066da9e-0x0066daa0.MapTileDimensionPadding.md` |
| `00027X` | 100 | 85 | 92.5 | `by-memory/0x0066dee1-0x0066dee4.FriendNameOptionPalettePadding.md` |
| `000280` | 100 | 85 | 92.5 | `by-memory/0x0066ed20-0x0066eea0.HeadSelectDialogLayoutPadding.md` |
| `000282` | 100 | 85 | 92.5 | `by-memory/0x0066fce4-0x0066fe40.HeadSelectToSelfLookPadding.md` |
| `000285` | 100 | 85 | 92.5 | `by-memory/0x0066fe4a-0x0066fe50.SpelledPaneToPacketTransformPadding.md` |
| `0004B1` | 82 | 86 | 84.0 | `by-memory/0x0054a960-0x0054aa96.PowerDialogPaneUnreferencedApplyAllThresholdsRaw.md` |
| `0004B2` | 82 | 86 | 84.0 | `by-memory/0x0054aaa0-0x0054ab87.PowerDialogPaneUnreferencedSelectedPowerSlotRaw.md` |
| `00043Z` | 84 | 86 | 85.0 | `by-memory/0x0052b950-0x0052b981.NewUserDialogPane2ClearGenderSelectionButtonsRaw.md` |
| `000440` | 84 | 86 | 85.0 | `by-memory/0x0052b990-0x0052b9ed.NewUserDialogPane2ClearTotemSelectionButtonsRaw.md` |
| `0000L8` | 87 | 86 | 86.5 | `by-file/MenuVarietyPanes.md` |
| `0002EE` | 85 | 87 | 86.0 | `by-memory/0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md` |
| `0001MO` | 82 | 88 | 85.0 | `by-memory/0x005b6120-0x005b62c8.SpellSpellInputPane.md` |
| `00021B` | 84 | 88 | 86.0 | `by-memory/0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup.md` |
| `00000E` | 85 | 88 | 86.5 | `by-class/ApplicationHelper_4A6C40.md` |
| `0000HE` | 85 | 88 | 86.5 | `by-file/AlertPanes.md` |
| `0000WT` | 85 | 88 | 86.5 | `by-memory/0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland.md` |
| `000229` | 85 | 88 | 86.5 | `by-memory/0x004a60a0-0x004a60cb.MsvcInt64RuntimeHelpers.md` |
| `00014X` | 85 | 88 | 86.5 | `by-memory/0x004b08cd-0x004b08e3.ExchangeAlertPaneAdjustorThunks.md` |
| `00014Y` | 85 | 88 | 86.5 | `by-memory/0x004b0ab5-0x004b0acb.ExchangeMoneyEditControlPaneAdjustorThunks.md` |
| `00019I` | 85 | 88 | 86.5 | `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md` |
| `00019U` | 85 | 88 | 86.5 | `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md` |
| `0003VP` | 85 | 88 | 86.5 | `by-memory/0x00516040-0x00516045.MemoryManNoXrefReturnZeroStub.md` |
| `0003QB` | 85 | 88 | 86.5 | `by-memory/0x00566f30-0x00566f31.SelfLookPaneNullStub.md` |

## Low_Both_Reconstructable

Lowest-scored files whose `RECONSTRUCTABLE` metadata is `true`.

| UID | Completion | Confidence | Combined | Path |
| --- | ---: | ---: | ---: | --- |
| `000049` | 85 | 86 | 85.5 | `by-class/EffectObjectPane.md` |
| `0000AJ` | 85 | 86 | 85.5 | `by-class/PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_.md` |
| `0000AK` | 85 | 86 | 85.5 | `by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md` |
| `00041T` | 84 | 88 | 86.0 | `by-memory/0x004df1e0-0x004df2b7.ItemObjImageLibDrawItemImageUnscaled.md` |
| `00000J` | 85 | 87 | 86.0 | `by-class/ArticleDialog.md` |
| `00000Y` | 85 | 87 | 86.0 | `by-class/BlueAlertPane.md` |
| `000018` | 85 | 87 | 86.0 | `by-class/BrowserDialogOld.md` |
| `00005Y` | 85 | 87 | 86.0 | `by-class/GroupPane.md` |
| `00009B` | 85 | 87 | 86.0 | `by-class/NewSystemMessageModifyHeightPane.md` |
| `0004EW` | 85 | 87 | 86.0 | `by-memory/0x005566b0-0x005566ba.RingBufferFullPredicateAlias.md` |
| `00044Z` | 85 | 87 | 86.0 | `by-memory/0x005609e0-0x00560a04.ScrollNewGroupPaneStyleByteSetterRaw.md` |
| `0000CP` | 86 | 86 | 86.0 | `by-class/ScrollWidget.md` |
| `0003GY` | 86 | 86 | 86.0 | `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md` |
| `00000K` | 85 | 88 | 86.5 | `by-class/ArticleListDialog.md` |
| `00001A` | 85 | 88 | 86.5 | `by-class/BrowserThread.md` |
| `00001B` | 85 | 88 | 86.5 | `by-class/BrowserWindow.md` |
| `00001T` | 85 | 88 | 86.5 | `by-class/ChattingColorPane.md` |
| `00002T` | 85 | 88 | 86.5 | `by-class/CloudFilterEffecter.md` |
| `00003W` | 85 | 88 | 86.5 | `by-class/DIError.md` |
| `000045` | 85 | 88 | 86.5 | `by-class/DSError.md` |
| `000041` | 85 | 88 | 86.5 | `by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md` |
| `00004K` | 85 | 88 | 86.5 | `by-class/ErrorMessage.md` |
| `000057` | 85 | 88 | 86.5 | `by-class/FlyingObjectPane.md` |
| `00005K` | 85 | 88 | 86.5 | `by-class/FunctionObject.md` |
| `00005L` | 85 | 88 | 86.5 | `by-class/FunctionObject0.md` |
| `00005S` | 85 | 88 | 86.5 | `by-class/GiveAllInputPane.md` |
| `00005U` | 85 | 88 | 86.5 | `by-class/GiveInputPane.md` |
| `00005Z` | 85 | 88 | 86.5 | `by-class/GroupPane2.md` |
| `00006N` | 85 | 88 | 86.5 | `by-class/InterfaceEfx.md` |
| `00006P` | 85 | 88 | 86.5 | `by-class/InternetConnectionError.md` |
| `00006Q` | 85 | 88 | 86.5 | `by-class/InternetError.md` |
| `00009T` | 85 | 88 | 86.5 | `by-class/OldSystemMessagePane.md` |
| `0000AI` | 85 | 88 | 86.5 | `by-class/PixelEffecter.md` |
| `0000DE` | 85 | 88 | 86.5 | `by-class/SolidColorFilterEffecter.md` |
| `0000EH` | 85 | 88 | 86.5 | `by-class/TerminalSetupPane.md` |
| `000014` | 85 | 88 | 86.5 | `by-class/browser__Notification.md` |
| `0000YR` | 85 | 88 | 86.5 | `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md` |
| `000123` | 85 | 88 | 86.5 | `by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md` |
| `0003LP` | 85 | 88 | 86.5 | `by-memory/0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor.md` |
| `0002R4` | 85 | 88 | 86.5 | `by-memory/0x00543670-0x005436f4.PaletteCollectionColorTransformRaw.md` |
| `0003OB` | 85 | 88 | 86.5 | `by-memory/0x0055b4c0-0x0055b5c3.YFlipEffecterApplyEffect.md` |
| `0003HC` | 85 | 88 | 86.5 | `by-memory/0x0055b860-0x0055b866.LakeEffecterResetVtable.md` |
| `00044Y` | 85 | 88 | 86.5 | `by-memory/0x005609b0-0x005609d7.ScrollNewGroupPaneSkinIndexSetterRaw.md` |
| `0003QG` | 85 | 88 | 86.5 | `by-memory/0x005671a0-0x005671b7.SelfLookPaneSpelledEntryRemoveForwarderRaw.md` |
| `0003R4` | 85 | 88 | 86.5 | `by-memory/0x00570b80-0x00570b9a.SelfLookPane2SpelledEntryUpdateForwarderRaw.md` |
| `0003R5` | 85 | 88 | 86.5 | `by-memory/0x00570ba0-0x00570bb7.SelfLookPane2SpelledEntryRemoveForwarderRaw.md` |
| `0003R6` | 85 | 88 | 86.5 | `by-memory/0x00570bc0-0x00570bde.SelfLookPane2RefreshSpelledChildRaw.md` |
| `0003R7` | 85 | 88 | 86.5 | `by-memory/0x00570be0-0x00570bf1.SelfLookPane2RefreshSpelledChildStateRaw.md` |
| `0003YL` | 85 | 88 | 86.5 | `by-memory/0x00575580-0x0057564e.PacketBufferHostAddressResolutionHelpers.md` |
| `0003YO` | 85 | 88 | 86.5 | `by-memory/0x005757d0-0x00575a07.PacketBufferStringWriteHelpers.md` |
| `0003A6` | 85 | 88 | 86.5 | `by-memory/0x00576570-0x00576623.SocketReconnectEndpointRaw.md` |
| `0003A7` | 85 | 88 | 86.5 | `by-memory/0x00577610-0x0057779e.SocketOpenSerialTransportRaw.md` |
| `0003FD` | 85 | 88 | 86.5 | `by-memory/0x00593f00-0x0059403b.DrawTextRunCallbackThiscallRaw.md` |
| `0003FK` | 85 | 88 | 86.5 | `by-memory/0x005b4760-0x005b47dc.SendDropAllItemPacketRaw.md` |
| `0003FL` | 85 | 88 | 86.5 | `by-memory/0x005b4af0-0x005b4b6c.SendDropItemPacketRaw.md` |
| `0003FM` | 85 | 88 | 86.5 | `by-memory/0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw.md` |
| `0003FN` | 85 | 88 | 86.5 | `by-memory/0x005b4ef0-0x005b4f6c.SendGiveAllItemPacketRaw.md` |
| `0003FO` | 85 | 88 | 86.5 | `by-memory/0x005b5230-0x005b52ac.SendGiveItemPacketRaw.md` |
| `0003NX` | 85 | 88 | 86.5 | `by-memory/0x005b5ab0-0x005b5b2c.SendThrowItemPacketRaw.md` |
| `0003AH` | 85 | 88 | 86.5 | `by-memory/0x005bc890-0x005bc96a.MenuVarietyPaneButtonRectHelpers.md` |
| `0003AJ` | 85 | 88 | 86.5 | `by-memory/0x005bffe0-0x005c0034.MenuVarietyLabelVectorAppendMoveHelper.md` |
| `0003O4` | 85 | 88 | 86.5 | `by-memory/0x005c2a20-0x005c2a5b.SnowingLayerPaneScalarDeletingDestructor.md` |
| `0003ST` | 85 | 88 | 86.5 | `by-memory/0x005c50f0-0x005c5156.WorldMapPaneUpdateHoverFromMouseStrict.md` |
| `0003SU` | 85 | 88 | 86.5 | `by-memory/0x005c5160-0x005c519c.WorldMapPaneFindPredecessorNode.md` |
| `0003SV` | 85 | 88 | 86.5 | `by-memory/0x005c51a0-0x005c51fb.WorldMapPaneScreenPointHelper.md` |
| `0001VH` | 85 | 88 | 86.5 | `by-type/by-struct/PaneLayout.md` |
| `0000E0` | 86 | 87 | 86.5 | `by-class/StaticCloudFilterEffecter.md` |
| `0000EA` | 86 | 87 | 86.5 | `by-class/SystemMessagePane.md` |
| `0000GC` | 86 | 87 | 86.5 | `by-class/XWaveEffecter.md` |
| `00041A` | 86 | 87 | 86.5 | `by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md` |
| `000028` | 85 | 89 | 87.0 | `by-class/ClanChangeNameInputDialog.md` |
| `00002M` | 85 | 89 | 87.0 | `by-class/ClanSummonNameInputDialog.md` |
| `00004Z` | 85 | 89 | 87.0 | `by-class/FittingEquipmentState.md` |
| `00021D` | 85 | 89 | 87.0 | `by-memory/0x00485440-0x004854a5.SendClanStatusRefreshRequestPacket.md` |
| `00021I` | 85 | 89 | 87.0 | `by-memory/0x00485780-0x00485867.ClanDepositMoneyRequestAndSubmitPacketHelpers.md` |
| `00021J` | 85 | 89 | 87.0 | `by-memory/0x00485870-0x00485955.ClanDepositItemRequestAndSubmitPacketHelpers.md` |
| `000377` | 85 | 89 | 87.0 | `by-memory/0x00516c40-0x00516c9a.MenuPaneFindPreviousEnabledItemRaw.md` |
| `000378` | 85 | 89 | 87.0 | `by-memory/0x00516ca0-0x00516cf3.MenuPaneFindNextEnabledItemRaw.md` |
| `0001CO` | 85 | 89 | 87.0 | `by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md` |
| `0003QA` | 85 | 89 | 87.0 | `by-memory/0x00565890-0x00566f24.SelfLookPaneOnReceiveCharacterData.md` |
| `0003QK` | 85 | 89 | 87.0 | `by-memory/0x00567280-0x005672b0.SelfLookPaneActivateView.md` |
| `0003QL` | 85 | 89 | 87.0 | `by-memory/0x005672b0-0x0056737f.SelfLookPaneDeactivateResetRaw.md` |
| `0003QM` | 85 | 89 | 87.0 | `by-memory/0x00567380-0x00567472.SelfLookPaneDeactivateView.md` |
| `0003QO` | 85 | 89 | 87.0 | `by-memory/0x00568bd0-0x00568ca9.SelfLookPaneOnKeyPress.md` |
| `0003QR` | 85 | 89 | 87.0 | `by-memory/0x00569860-0x00569c80.SelfLookPaneOnShowHelp.md` |
| `0003QS` | 85 | 89 | 87.0 | `by-memory/0x00569c80-0x00569cce.SelfLookPaneOnGetRect.md` |
| `0003QT` | 85 | 89 | 87.0 | `by-memory/0x00569cd0-0x00569d75.SelfLookPaneOnTransformRect.md` |
| `00039L` | 85 | 89 | 87.0 | `by-memory/0x005729e0-0x00572b54.SelfLookPane2PacketSendRawHelpers.md` |
| `0003RJ` | 85 | 89 | 87.0 | `by-memory/0x0059f500-0x0059f604.UserLookPaneNonDeletingDestructor.md` |
| `0003AI` | 85 | 89 | 87.0 | `by-memory/0x005bd960-0x005bd9ad.MenuVarietySelectPaneRowRectHelper.md` |
| `0003SE` | 85 | 89 | 87.0 | `by-memory/0x005c3420-0x005c346d.WorldMapPaneSetViewPosition.md` |
| `0003SF` | 85 | 89 | 87.0 | `by-memory/0x005c34c0-0x005c3508.WorldMapPaneStartViewAnimation.md` |
| `0003SH` | 85 | 89 | 87.0 | `by-memory/0x005c3630-0x005c36c8.WorldMapPaneSendTravelPacket.md` |
| `0003SL` | 85 | 89 | 87.0 | `by-memory/0x005c3e50-0x005c402b.WorldMapPaneHandleKeyEvent.md` |
| `0003SM` | 85 | 89 | 87.0 | `by-memory/0x005c40c0-0x005c4245.WorldMapPaneHandleMouseEvent.md` |
| `0003SO` | 85 | 89 | 87.0 | `by-memory/0x005c46f0-0x005c4733.WorldMapPaneOnTimerTick.md` |
| `0003SQ` | 85 | 89 | 87.0 | `by-memory/0x005c48b0-0x005c4bd0.WorldMapPaneDrawPlayerMarker.md` |
| `0003NI` | 85 | 89 | 87.0 | `by-memory/0x0061a374-0x0061a37c.AddItemWithCountDialogQuantityFormatString.md` |
| `0001TN` | 85 | 89 | 87.0 | `by-type/by-struct/AddEmployeeItemDialogLayout.md` |
| `00001C` | 86 | 88 | 87.0 | `by-class/BulletinDialog.md` |
| `00001S` | 86 | 88 | 87.0 | `by-class/ChattingColorListPane.md` |
| `000042` | 86 | 88 | 87.0 | `by-class/DropAllInputPane.md` |
| `000044` | 86 | 88 | 87.0 | `by-class/DropInputPane.md` |
| `000047` | 86 | 88 | 87.0 | `by-class/EatInputPane.md` |
| `00005M` | 86 | 88 | 87.0 | `by-class/FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____.md` |
| `000070` | 86 | 88 | 87.0 | `by-class/LakeEffecter.md` |
| `00007Y` | 86 | 88 | 87.0 | `by-class/MenuQuestionDialogLarger.md` |
| `00007Z` | 86 | 88 | 87.0 | `by-class/MenuQuestionItemList.md` |
| `00008B` | 86 | 88 | 87.0 | `by-class/MiniMapButtonPane.md` |
| `00008E` | 86 | 88 | 87.0 | `by-class/MiniMapImageControlPane.md` |
| `00008F` | 86 | 88 | 87.0 | `by-class/MiniMapRenderer.md` |

## Low_Both_Not_Reconstructable

Lowest-scored files whose `RECONSTRUCTABLE` metadata is false, blank, or invalid.

| UID | Completion | Confidence | Combined | Path |
| --- | ---: | ---: | ---: | --- |
| `0004B1` | 82 | 86 | 84.0 | `by-memory/0x0054a960-0x0054aa96.PowerDialogPaneUnreferencedApplyAllThresholdsRaw.md` |
| `0004B2` | 82 | 86 | 84.0 | `by-memory/0x0054aaa0-0x0054ab87.PowerDialogPaneUnreferencedSelectedPowerSlotRaw.md` |
| `0001MO` | 82 | 88 | 85.0 | `by-memory/0x005b6120-0x005b62c8.SpellSpellInputPane.md` |
| `00043Z` | 84 | 86 | 85.0 | `by-memory/0x0052b950-0x0052b981.NewUserDialogPane2ClearGenderSelectionButtonsRaw.md` |
| `000440` | 84 | 86 | 85.0 | `by-memory/0x0052b990-0x0052b9ed.NewUserDialogPane2ClearTotemSelectionButtonsRaw.md` |
| `00021B` | 84 | 88 | 86.0 | `by-memory/0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup.md` |
| `0002EE` | 85 | 87 | 86.0 | `by-memory/0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md` |
| `00000E` | 85 | 88 | 86.5 | `by-class/ApplicationHelper_4A6C40.md` |
| `0000HE` | 85 | 88 | 86.5 | `by-file/AlertPanes.md` |
| `0000WT` | 85 | 88 | 86.5 | `by-memory/0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland.md` |
| `000229` | 85 | 88 | 86.5 | `by-memory/0x004a60a0-0x004a60cb.MsvcInt64RuntimeHelpers.md` |
| `00014X` | 85 | 88 | 86.5 | `by-memory/0x004b08cd-0x004b08e3.ExchangeAlertPaneAdjustorThunks.md` |
| `00014Y` | 85 | 88 | 86.5 | `by-memory/0x004b0ab5-0x004b0acb.ExchangeMoneyEditControlPaneAdjustorThunks.md` |
| `00019I` | 85 | 88 | 86.5 | `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md` |
| `00019U` | 85 | 88 | 86.5 | `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md` |
| `0003VP` | 85 | 88 | 86.5 | `by-memory/0x00516040-0x00516045.MemoryManNoXrefReturnZeroStub.md` |
| `0003QB` | 85 | 88 | 86.5 | `by-memory/0x00566f30-0x00566f31.SelfLookPaneNullStub.md` |
| `0003R0` | 85 | 88 | 86.5 | `by-memory/0x00570930-0x00570931.SelfLookPane2NullStub.md` |
| `0003RL` | 85 | 88 | 86.5 | `by-memory/0x005a0630-0x005a0631.UserLookPaneNullStub.md` |
| `0002S8` | 85 | 88 | 86.5 | `by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md` |
| `0003EV` | 85 | 88 | 86.5 | `by-memory/0x006247f0-0x00624804.SharedCommaEpfResourceString.md` |
| `0003EX` | 85 | 88 | 86.5 | `by-memory/0x006248cc-0x006248e0.SharedCommaPalResourceString.md` |
| `00035O` | 85 | 88 | 86.5 | `by-memory/0x0066d412-0x0066d414.PaddingBeforeBalloonObjectPaneMasks.md` |
| `0000L8` | 87 | 86 | 86.5 | `by-file/MenuVarietyPanes.md` |
| `0001ZV` | 84 | 90 | 87.0 | `by-memory/0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport.md` |
| `0001ZW` | 84 | 90 | 87.0 | `by-memory/0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport.md` |
| `0001ZX` | 84 | 90 | 87.0 | `by-memory/0x00442090-0x00443a55.JsonCppWriterRuntimeTailSupport.md` |
| `0000ZM` | 84 | 90 | 87.0 | `by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md` |
| `000102` | 84 | 90 | 87.0 | `by-memory/0x0047ef40-0x0047ef4b.ClearChangeManSingleton.md` |
| `0002GI` | 84 | 90 | 87.0 | `by-memory/0x004839c0-0x00483ef7.ChattingUiDestructorGlueFamily.md` |
| `00017C` | 84 | 90 | 87.0 | `by-memory/0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster.md` |
| `0001AF` | 84 | 90 | 87.0 | `by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md` |
| `0001CK` | 84 | 90 | 87.0 | `by-memory/0x00528290-0x005283d5.CashShopRequestAuthDirectory.md` |

## By Folder

### by-class_Reconstructable

| UID | Completion | Confidence | Combined | Path |
| --- | ---: | ---: | ---: | --- |
| `000049` | 85 | 86 | 85.5 | `by-class/EffectObjectPane.md` |
| `0000AJ` | 85 | 86 | 85.5 | `by-class/PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_.md` |
| `0000AK` | 85 | 86 | 85.5 | `by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md` |
| `00000J` | 85 | 87 | 86.0 | `by-class/ArticleDialog.md` |
| `00000Y` | 85 | 87 | 86.0 | `by-class/BlueAlertPane.md` |
| `000018` | 85 | 87 | 86.0 | `by-class/BrowserDialogOld.md` |
| `00005Y` | 85 | 87 | 86.0 | `by-class/GroupPane.md` |
| `00009B` | 85 | 87 | 86.0 | `by-class/NewSystemMessageModifyHeightPane.md` |
| `0000CP` | 86 | 86 | 86.0 | `by-class/ScrollWidget.md` |
| `00000K` | 85 | 88 | 86.5 | `by-class/ArticleListDialog.md` |
| `00001A` | 85 | 88 | 86.5 | `by-class/BrowserThread.md` |
| `00001B` | 85 | 88 | 86.5 | `by-class/BrowserWindow.md` |
| `00001T` | 85 | 88 | 86.5 | `by-class/ChattingColorPane.md` |
| `00002T` | 85 | 88 | 86.5 | `by-class/CloudFilterEffecter.md` |
| `00003W` | 85 | 88 | 86.5 | `by-class/DIError.md` |
| `000045` | 85 | 88 | 86.5 | `by-class/DSError.md` |
| `000041` | 85 | 88 | 86.5 | `by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md` |
| `00004K` | 85 | 88 | 86.5 | `by-class/ErrorMessage.md` |
| `000057` | 85 | 88 | 86.5 | `by-class/FlyingObjectPane.md` |
| `00005K` | 85 | 88 | 86.5 | `by-class/FunctionObject.md` |
| `00005L` | 85 | 88 | 86.5 | `by-class/FunctionObject0.md` |
| `00005S` | 85 | 88 | 86.5 | `by-class/GiveAllInputPane.md` |
| `00005U` | 85 | 88 | 86.5 | `by-class/GiveInputPane.md` |
| `00005Z` | 85 | 88 | 86.5 | `by-class/GroupPane2.md` |
| `00006N` | 85 | 88 | 86.5 | `by-class/InterfaceEfx.md` |
| `00006P` | 85 | 88 | 86.5 | `by-class/InternetConnectionError.md` |
| `00006Q` | 85 | 88 | 86.5 | `by-class/InternetError.md` |
| `00009T` | 85 | 88 | 86.5 | `by-class/OldSystemMessagePane.md` |
| `0000AI` | 85 | 88 | 86.5 | `by-class/PixelEffecter.md` |
| `0000DE` | 85 | 88 | 86.5 | `by-class/SolidColorFilterEffecter.md` |
| `0000EH` | 85 | 88 | 86.5 | `by-class/TerminalSetupPane.md` |
| `000014` | 85 | 88 | 86.5 | `by-class/browser__Notification.md` |
| `0000E0` | 86 | 87 | 86.5 | `by-class/StaticCloudFilterEffecter.md` |
| `0000EA` | 86 | 87 | 86.5 | `by-class/SystemMessagePane.md` |
| `0000GC` | 86 | 87 | 86.5 | `by-class/XWaveEffecter.md` |
| `000028` | 85 | 89 | 87.0 | `by-class/ClanChangeNameInputDialog.md` |
| `00002M` | 85 | 89 | 87.0 | `by-class/ClanSummonNameInputDialog.md` |
| `00004Z` | 85 | 89 | 87.0 | `by-class/FittingEquipmentState.md` |
| `00001C` | 86 | 88 | 87.0 | `by-class/BulletinDialog.md` |
| `00001S` | 86 | 88 | 87.0 | `by-class/ChattingColorListPane.md` |
| `000042` | 86 | 88 | 87.0 | `by-class/DropAllInputPane.md` |
| `000044` | 86 | 88 | 87.0 | `by-class/DropInputPane.md` |
| `000047` | 86 | 88 | 87.0 | `by-class/EatInputPane.md` |
| `00005M` | 86 | 88 | 87.0 | `by-class/FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____.md` |
| `000070` | 86 | 88 | 87.0 | `by-class/LakeEffecter.md` |
| `00007Y` | 86 | 88 | 87.0 | `by-class/MenuQuestionDialogLarger.md` |
| `00007Z` | 86 | 88 | 87.0 | `by-class/MenuQuestionItemList.md` |
| `00008B` | 86 | 88 | 87.0 | `by-class/MiniMapButtonPane.md` |
| `00008E` | 86 | 88 | 87.0 | `by-class/MiniMapImageControlPane.md` |
| `00008F` | 86 | 88 | 87.0 | `by-class/MiniMapRenderer.md` |
| `0000AL` | 86 | 88 | 87.0 | `by-class/PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6.md` |
| `0000F5` | 86 | 88 | 87.0 | `by-class/TransferReplyAlert.md` |
| `0000FA` | 86 | 88 | 87.0 | `by-class/TreeItor_near_class_EventHandler___.md` |
| `0000FG` | 86 | 88 | 87.0 | `by-class/UseInputPane.md` |
| `0000GD` | 86 | 88 | 87.0 | `by-class/YFlipEffecter.md` |
| `00000U` | 85 | 90 | 87.5 | `by-class/BalloonObjectPane.md` |
| `00005N` | 85 | 90 | 87.5 | `by-class/FunctionObjectT_near_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t____const___.md` |
| `00001U` | 86 | 89 | 87.5 | `by-class/ChattingColorSelectPane.md` |
| `00002J` | 86 | 89 | 87.5 | `by-class/ClanNameInputDialog.md` |
| `00002N` | 86 | 89 | 87.5 | `by-class/ClanWidItemDialog.md` |
| `00007W` | 86 | 89 | 87.5 | `by-class/MenuPane.md` |
| `00008C` | 86 | 89 | 87.5 | `by-class/MiniMapDialog.md` |
| `0000AF` | 86 | 89 | 87.5 | `by-class/PhoneEntryDialog.md` |
| `0000F6` | 86 | 89 | 87.5 | `by-class/TransferReplyPredefinedAlert.md` |
| `000043` | 87 | 88 | 87.5 | `by-class/DropGoldInputPane.md` |
| `000046` | 87 | 88 | 87.5 | `by-class/EarthquakeEffecter.md` |
| `00009V` | 87 | 88 | 87.5 | `by-class/OptionPane.md` |
| `0000A9` | 87 | 88 | 87.5 | `by-class/PatchPane.md` |
| `0000CM` | 87 | 88 | 87.5 | `by-class/ScrollPane.md` |
| `0000CT` | 87 | 88 | 87.5 | `by-class/SelectObjectWithKeyboardPane.md` |
| `0000DX` | 87 | 88 | 87.5 | `by-class/SpellWhoInputPane.md` |
| `0000ED` | 87 | 88 | 87.5 | `by-class/TargetObjectWithKeyboardPane.md` |
| `0000GB` | 87 | 88 | 87.5 | `by-class/WSAError.md` |
| `0000G7` | 87 | 88 | 87.5 | `by-class/Win32Error.md` |
| `00002A` | 86 | 90 | 88.0 | `by-class/ClanDepMoneyInputDialog.md` |
| `00002C` | 86 | 90 | 88.0 | `by-class/ClanEnlistListPane.md` |
| `00002D` | 86 | 90 | 88.0 | `by-class/ClanExpelNameInputDialog.md` |
| `00002F` | 86 | 90 | 88.0 | `by-class/ClanItemDialog.md` |
| `00002H` | 86 | 90 | 88.0 | `by-class/ClanJoinListPane.md` |
| `00002O` | 86 | 90 | 88.0 | `by-class/ClanWidMoneyInputDialog.md` |
| `000052` | 86 | 90 | 88.0 | `by-class/FittingRoomDownloadControlPane.md` |
| `00008D` | 86 | 90 | 88.0 | `by-class/MiniMapDownloader.md` |
| `0000C9` | 86 | 90 | 88.0 | `by-class/ScreenEffecter.md` |
| `0000EY` | 86 | 90 | 88.0 | `by-class/ThrowInputPane.md` |
| `0000FZ` | 86 | 90 | 88.0 | `by-class/WaterFilterEffecter.md` |
| `000016` | 87 | 89 | 88.0 | `by-class/BrowserControlPaneOld.md` |
| `000033` | 87 | 89 | 88.0 | `by-class/ConfirmDeleteAlert.md` |
| `00005T` | 87 | 89 | 88.0 | `by-class/GiveGoldInputPane.md` |
| `00007X` | 87 | 89 | 88.0 | `by-class/MenuQuestionDialog.md` |
| `000080` | 87 | 89 | 88.0 | `by-class/MenuQuestionItemListLarger.md` |
| `000085` | 87 | 89 | 88.0 | `by-class/MessageDialog.md` |
| `00008Y` | 87 | 89 | 88.0 | `by-class/NewArticleDialog.md` |
| `000097` | 87 | 89 | 88.0 | `by-class/NewOptionPane.md` |
| `0000AE` | 87 | 89 | 88.0 | `by-class/PhoneBookListPane.md` |
| `0000BN` | 87 | 89 | 88.0 | `by-class/RankingEventListPane.md` |
| `0000EZ` | 87 | 89 | 88.0 | `by-class/ThrowReallyInputPane.md` |
| `00000L` | 88 | 88 | 88.0 | `by-class/ArticleListPane.md` |
| `0003GK` | 86 | 91 | 88.5 | `by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md` |
| `00001Q` | 87 | 90 | 88.5 | `by-class/ChatInputPane.md` |
| `000025` | 87 | 90 | 88.5 | `by-class/ClanBankItemListPane.md` |
| `000026` | 87 | 90 | 88.5 | `by-class/ClanBankPane.md` |
| `000029` | 87 | 90 | 88.5 | `by-class/ClanDepItemDialog.md` |
| `00002G` | 87 | 90 | 88.5 | `by-class/ClanItemListPane.md` |
| `00002L` | 87 | 90 | 88.5 | `by-class/ClanStringListPane.md` |
| `000034` | 87 | 90 | 88.5 | `by-class/ConfirmDeleteMailAlert.md` |
| `000040` | 87 | 90 | 88.5 | `by-class/DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528.md` |
| `000056` | 87 | 90 | 88.5 | `by-class/FittingRoomUserImageControlPane.md` |
| `00006Y` | 87 | 90 | 88.5 | `by-class/ItemWhoInputPaneState.md` |
| `00007N` | 87 | 90 | 88.5 | `by-class/MailTransferReplyAlert.md` |
| `000081` | 87 | 90 | 88.5 | `by-class/MenuVarietyPane.md` |
| `000082` | 87 | 90 | 88.5 | `by-class/MenuVarietySelectPane.md` |
| `0000BQ` | 87 | 90 | 88.5 | `by-class/RankingUserListPane.md` |
| `0000DM` | 87 | 90 | 88.5 | `by-class/SpellInputPaneState.md` |
| `00003L` | 88 | 89 | 88.5 | `by-class/DDError.md` |
| `00005A` | 88 | 89 | 88.5 | `by-class/FolderTreePane.md` |
| `0000AD` | 88 | 89 | 88.5 | `by-class/PhoneBookDialog.md` |
| `0000CQ` | 88 | 89 | 88.5 | `by-class/SelectBoxControlPane.md` |
| `0000DA` | 88 | 89 | 88.5 | `by-class/SimpleUStringVector.md` |

### by-class_Not_Reconstructable

| UID | Completion | Confidence | Combined | Path |
| --- | ---: | ---: | ---: | --- |
| `00000E` | 85 | 88 | 86.5 | `by-class/ApplicationHelper_4A6C40.md` |
| `00001G` | 85 | 90 | 87.5 | `by-class/CandidateStringQueue.md` |
| `00001N` | 88 | 92 | 90.0 | `by-class/CharacterSummaryRecord.md` |
| `00003E` | 88 | 92 | 90.0 | `by-class/CursorManager.md` |
| `0000CC` | 90 | 94 | 92.0 | `by-class/ScreenPanePaletteState_543D30.md` |
| `0000G8` | 90 | 94 | 92.0 | `by-class/WorldMapNodeEntryVector.md` |
| `0000CD` | 91 | 93 | 92.0 | `by-class/ScreenshotCapture.md` |
| `0000FD` | 91 | 94 | 92.5 | `by-class/UInt32Vector.md` |
| `0000GA` | 91 | 94 | 92.5 | `by-class/WorldMapReachabilityBitSet.md` |
| `0000BS` | 92 | 93 | 92.5 | `by-class/RecordVector_4E57C0.md` |
| `00003P` | 91 | 95 | 93.0 | `by-class/Deque.md` |
| `0000DI` | 91 | 95 | 93.0 | `by-class/SoundPathVector.md` |
| `00006T` | 92 | 94 | 93.0 | `by-class/ItemCatalog.md` |
| `0000BX` | 92 | 95 | 93.5 | `by-class/RequestSyncGate.md` |
| `0000F2` | 92 | 96 | 94.0 | `by-class/TimerMgrScheduledEventDequeCompilerSupport.md` |
| `00000O` | 93 | 95 | 94.0 | `by-class/AttachmentAnchorResolver.md` |
| `00008O` | 94 | 94 | 94.0 | `by-class/MonsterImageLibTable_5289D0.md` |
| `00008P` | 94 | 94 | 94.0 | `by-class/MonsterImageLibTable_528BE0.md` |
| `00000N` | 94 | 95 | 94.5 | `by-class/AttachedObjectPaneHelper_53AEC0.md` |
| `00000C` | 95 | 95 | 95.0 | `by-class/AlphaMaskSurface.md` |
| `00003K` | 95 | 95 | 95.0 | `by-class/DATIndexVector.md` |
| `00003J` | 96 | 97 | 96.5 | `by-class/DATFileResolver.md` |

### by-external-research_Reconstructable

_No scored files._

### by-external-research_Not_Reconstructable

_No scored files._

### by-file_Reconstructable

_No scored files._

### by-file_Not_Reconstructable

| UID | Completion | Confidence | Combined | Path |
| --- | ---: | ---: | ---: | --- |
| `0000HE` | 85 | 88 | 86.5 | `by-file/AlertPanes.md` |
| `0000L8` | 87 | 86 | 86.5 | `by-file/MenuVarietyPanes.md` |
| `0000HT` | 87 | 88 | 87.5 | `by-file/BoardDialogs.md` |
| `0000I8` | 90 | 85 | 87.5 | `by-file/Clan.md` |
| `0000KC` | 90 | 85 | 87.5 | `by-file/ItemActionInputPanes.md` |
| `0000LE` | 87 | 89 | 88.0 | `by-file/MiniMap.md` |
| `0000MN` | 88 | 88 | 88.0 | `by-file/PopupMenuControls.md` |
| `0000JE` | 88 | 90 | 89.0 | `by-file/FittingRoom.md` |
| `0000O9` | 88 | 90 | 89.0 | `by-file/StdioFile.md` |
| `0000IZ` | 90 | 88 | 89.0 | `by-file/Effects.md` |
| `0000OH` | 90 | 88 | 89.0 | `by-file/TargetSelectionInputPanes.md` |
| `0000MZ` | 88 | 91 | 89.5 | `by-file/RankingDialog.md` |
| `0000J5` | 89 | 90 | 89.5 | `by-file/Error.md` |
| `0000O4` | 89 | 90 | 89.5 | `by-file/StartupLogoPanes.md` |
| `0000I9` | 90 | 89 | 89.5 | `by-file/ClanBank.md` |
| `0000JO` | 90 | 89 | 89.5 | `by-file/FunctionObjects.md` |
| `0000NR` | 90 | 89 | 89.5 | `by-file/SnowingLayerPane.md` |
| `0000OC` | 90 | 89 | 89.5 | `by-file/Surface.md` |

### by-function_Reconstructable

_No scored files._

### by-function_Not_Reconstructable

_No scored files._

### by-global_Reconstructable

| UID | Completion | Confidence | Combined | Path |
| --- | ---: | ---: | ---: | --- |
| `0000TO` | 86 | 88 | 87.0 | `by-global/VectorGrowMotion.md` |
| `0000PQ` | 86 | 88 | 87.0 | `by-global/g_activeDialogCount.md` |
| `0000QE` | 86 | 88 | 87.0 | `by-global/g_pBrowserThread.md` |
| `0000PV` | 85 | 90 | 87.5 | `by-global/g_browserWindowClassName.md` |
| `0000RU` | 85 | 90 | 87.5 | `by-global/g_pNewSystemMessagePane.md` |
| `0000R2` | 86 | 89 | 87.5 | `by-global/g_pHeightModifyPane.md` |
| `0000SN` | 86 | 89 | 87.5 | `by-global/g_pUserStatusPane2.md` |
| `0000PH` | 86 | 90 | 88.0 | `by-global/CloseMainMenuDialogSingletons_4F69A0.md` |
| `0000PI` | 86 | 90 | 88.0 | `by-global/ComputeMenuItemRect_4F8B90.md` |
| `0000SZ` | 86 | 90 | 88.0 | `by-global/HandleLegacyMainMenuPacket_4F8D00.md` |
| `0000T1` | 86 | 90 | 88.0 | `by-global/HitTestMenuItem_4F8C10.md` |
| `0000TB` | 86 | 90 | 88.0 | `by-global/OpenCreateUserDialog_4F8FA0.md` |
| `0000TC` | 86 | 90 | 88.0 | `by-global/OpenHistoryViewingPane_4F9140.md` |
| `0000TE` | 86 | 90 | 88.0 | `by-global/OpenStoryViewingPane_4F90C0.md` |
| `0000TF` | 86 | 90 | 88.0 | `by-global/OpenTerminalPane_4F91C0.md` |
| `0000QL` | 86 | 90 | 88.0 | `by-global/g_pCollectionDialogPane.md` |
| `0003ED` | 86 | 90 | 88.0 | `by-global/g_pOldSystemMessagePane.md` |
| `0000RV` | 86 | 90 | 88.0 | `by-global/g_pOldUserStatusPane.md` |
| `0000T9` | 87 | 89 | 88.0 | `by-global/MidiPlayerWinMMState.md` |
| `0000PJ` | 87 | 90 | 88.5 | `by-global/CreateScreenDimmer_4A12B0.md` |
| `000308` | 87 | 90 | 88.5 | `by-global/g_pChatInputPane.md` |
| `0002WZ` | 87 | 90 | 88.5 | `by-global/g_pChattingBackPane.md` |
| `0002WV` | 87 | 90 | 88.5 | `by-global/g_pChattingViewport.md` |
| `0000QO` | 87 | 90 | 88.5 | `by-global/g_pCurrentBrowserHost.md` |
| `0003EE` | 87 | 90 | 88.5 | `by-global/g_pInputBlockerPane.md` |
| `0000RJ` | 87 | 90 | 88.5 | `by-global/g_pMenuVarietySelectPane.md` |
| `0000S9` | 87 | 90 | 88.5 | `by-global/g_pSimpleHelpPane.md` |
| `0000Q2` | 88 | 89 | 88.5 | `by-global/g_metaAliasTableName.md` |
| `0000QU` | 89 | 88 | 88.5 | `by-global/g_pEPFLib.md` |
| `0000SY` | 87 | 91 | 89.0 | `by-global/GetControlLayout_452260.md` |
| `0000RI` | 87 | 91 | 89.0 | `by-global/g_pMenuVarietyPane.md` |
| `0000RO` | 87 | 91 | 89.0 | `by-global/g_pMiniMapDownloader.md` |
| `0000SP` | 87 | 91 | 89.0 | `by-global/g_pVoteMenuPane.md` |
| `0000T8` | 88 | 90 | 89.0 | `by-global/MemoryAllocationHelpers.md` |
| `0000TA` | 88 | 90 | 89.0 | `by-global/OpenChangePasswordDialog_4F9060.md` |
| `0003MS` | 88 | 90 | 89.0 | `by-global/StaticSimpleUStringVector_69B39C.md` |
| `0002ZX` | 88 | 90 | 89.0 | `by-global/g_bShowHuntersListOnly.md` |
| `0000QB` | 88 | 90 | 89.0 | `by-global/g_pBrowserDialogOld.md` |
| `0000RN` | 88 | 90 | 89.0 | `by-global/g_pMiniMapButtonPane.md` |
| `0000SW` | 88 | 90 | 89.0 | `by-global/g_useEpfAssets.md` |
| `0000Q1` | 89 | 89 | 89.0 | `by-global/g_gameServerNationTable.md` |
| `0000Q4` | 89 | 89 | 89.0 | `by-global/g_objectRecordCount.md` |
| `0000SM` | 87 | 92 | 89.5 | `by-global/g_pUrlAlertPane.md` |
| `0000PK` | 88 | 91 | 89.5 | `by-global/DestroyMotionVector.md` |
| `0002XJ` | 88 | 91 | 89.5 | `by-global/g_pClanBankPane.md` |
| `0000SF` | 88 | 91 | 89.5 | `by-global/g_pTerminalPane.md` |
| `0002CG` | 88 | 91 | 89.5 | `by-global/g_selfLookLastHoverEquipmentSlotId.md` |
| `0000Q3` | 89 | 90 | 89.5 | `by-global/g_objectNationMap.md` |
| `0000QK` | 89 | 90 | 89.5 | `by-global/g_pCollectionData.md` |
| `0000RL` | 89 | 90 | 89.5 | `by-global/g_pMetaMan.md` |
| `0000PM` | 87 | 93 | 90.0 | `by-global/FindBlockListEntry_5B74E0.md` |
| `0000T2` | 88 | 92 | 90.0 | `by-global/DIID_DWebBrowserEvents2.md` |
| `0000SX` | 88 | 92 | 90.0 | `by-global/GetChatButtonAtPoint.md` |
| `0000T4` | 88 | 92 | 90.0 | `by-global/LoadDatFileBuffer_4BB120.md` |
| `0002ZH` | 88 | 92 | 90.0 | `by-global/StartupLogoBinkRestartFlag.md` |
| `0002XG` | 88 | 92 | 90.0 | `by-global/g_pClanStatusPane.md` |
| `0000QV` | 88 | 92 | 90.0 | `by-global/g_pExchangeAlertPane.md` |
| `0000S2` | 88 | 92 | 90.0 | `by-global/g_pRankingDialog.md` |
| `0000S3` | 88 | 92 | 90.0 | `by-global/g_pRankingRewardInfoDialog.md` |
| `0000SI` | 88 | 92 | 90.0 | `by-global/g_pTimerMgr.md` |
| `0000Q6` | 89 | 91 | 90.0 | `by-global/g_pActiveBrowserWindow.md` |
| `0000RB` | 89 | 91 | 90.0 | `by-global/g_pKeySpeedMgr.md` |
| `0000PX` | 90 | 90 | 90.0 | `by-global/g_equipmentSlotKeys.md` |
| `0000R7` | 90 | 90 | 90.0 | `by-global/g_pIMEPane.md` |
| `0000RH` | 90 | 90 | 90.0 | `by-global/g_pMemoryMan.md` |
| `0000PO` | 89 | 92 | 90.5 | `by-global/g_activeBrowserControlPane.md` |
| `0002W3` | 89 | 92 | 90.5 | `by-global/g_pDeleteReplyAlert.md` |
| `0002W5` | 89 | 92 | 90.5 | `by-global/g_pMailDeleteReplyAlert.md` |
| `0000RM` | 89 | 92 | 90.5 | `by-global/g_pMidiPlayer.md` |
| `0000TJ` | 90 | 91 | 90.5 | `by-global/RidingDefinitionGlobalTable.md` |
| `0000PP` | 90 | 91 | 90.5 | `by-global/g_activeBrowserPane.md` |
| `0000QH` | 90 | 91 | 90.5 | `by-global/g_pCashShopRequest.md` |
| `0000S4` | 90 | 91 | 90.5 | `by-global/g_pRidingImageLib.md` |
| `0000Q5` | 90 | 91 | 90.5 | `by-global/g_packetSender.md` |
| `0000QI` | 91 | 90 | 90.5 | `by-global/g_pChangeMan.md` |
| `0000SJ` | 89 | 93 | 91.0 | `by-global/g_pTimerPane.md` |
| `0000T6` | 90 | 92 | 91.0 | `by-global/MainUiLayerSlots.md` |
| `0000TG` | 90 | 92 | 91.0 | `by-global/PacketTransformGlobals.md` |
| `0000SE` | 90 | 92 | 91.0 | `by-global/g_pTabPane.md` |
| `00020K` | 90 | 93 | 91.5 | `by-global/AesBlockCipherStateAndTables.md` |
| `0002ZF` | 90 | 93 | 91.5 | `by-global/ImageDecodeJpegEoiMarker.md` |
| `0000TH` | 90 | 93 | 91.5 | `by-global/ParseEntries_004A5E60.md` |
| `0000RT` | 90 | 93 | 91.5 | `by-global/g_pNewHumanImageLib.md` |
| `0000SL` | 90 | 93 | 91.5 | `by-global/g_pTransferServerDialog.md` |
| `0000SO` | 90 | 93 | 91.5 | `by-global/g_pVirusChecker.md` |
| `0000ST` | 90 | 93 | 91.5 | `by-global/g_screenHeight.md` |
| `0000SU` | 90 | 93 | 91.5 | `by-global/g_screenWidth.md` |
| `0000T7` | 91 | 92 | 91.5 | `by-global/MapTilePixelDimensions.md` |
| `0000PR` | 91 | 92 | 91.5 | `by-global/g_activeMapPane.md` |
| `0000RR` | 91 | 92 | 91.5 | `by-global/g_pMonsterImageLib.md` |
| `0000TQ` | 92 | 91 | 91.5 | `by-global/WideApiDispatchTable.md` |
| `0002ZJ` | 90 | 94 | 92.0 | `by-global/MapPaneCmapSignaturePointer.md` |
| `0000QQ` | 90 | 94 | 92.0 | `by-global/g_pDATFileMgr.md` |
| `0000RQ` | 90 | 94 | 92.0 | `by-global/g_pMiscWorkThread.md` |
| `0000S1` | 90 | 94 | 92.0 | `by-global/g_pQuitInputPane.md` |
| `0000SQ` | 90 | 94 | 92.0 | `by-global/g_pWebBoardDialog.md` |
| `0000SR` | 90 | 94 | 92.0 | `by-global/g_pWebBoardDialogOld.md` |
| `0000TD` | 91 | 93 | 92.0 | `by-global/OpenQuitPrompt_5A94B0.md` |
| `0002CF` | 91 | 93 | 92.0 | `by-global/g_movementSubstepScale.md` |
| `0004SO` | 91 | 93 | 92.0 | `by-global/g_pConnectionClosedDialog.md` |
| `0004SP` | 91 | 93 | 92.0 | `by-global/g_pReconnectDialog.md` |
| `0000RG` | 91 | 94 | 92.5 | `by-global/g_pMapTileImageLib.md` |
| `0000PW` | 92 | 93 | 92.5 | `by-global/g_emptySimpleUString.md` |
| `0000Q7` | 92 | 93 | 92.5 | `by-global/g_pActiveTextEditPane.md` |
| `0004Y3` | 92 | 93 | 92.5 | `by-global/g_pCreateUserDialogPane.md` |
| `0002ZG` | 92 | 94 | 93.0 | `by-global/JpegScreenshotEoiMarker.md` |
| `0002ZI` | 92 | 94 | 93.0 | `by-global/StaffsDialogEpfResourcePointer.md` |
| `0000PS` | 92 | 94 | 93.0 | `by-global/g_activeUserStatusPane.md` |
| `0000PY` | 92 | 94 | 93.0 | `by-global/g_fpsDebugActive.md` |
| `0000PG` | 92 | 94 | 93.0 | `by-global/g_friendNameListSyncEnabled.md` |
| `0002ZE` | 92 | 94 | 93.0 | `by-global/g_hourFrameTable.md` |
| `0000Q9` | 92 | 94 | 93.0 | `by-global/g_pBackStoryDialogPane.md` |
| `0000QA` | 92 | 94 | 93.0 | `by-global/g_pBowGaugeObjectPane.md` |
| `0000QG` | 92 | 94 | 93.0 | `by-global/g_pBulletinSession.md` |
| `0002WX` | 92 | 94 | 93.0 | `by-global/g_pChattingDisplayPane.md` |
| `0002XE` | 92 | 94 | 93.0 | `by-global/g_pChattingHandlePane.md` |
| `0002X1` | 92 | 94 | 93.0 | `by-global/g_pChattingModifyHeightPane.md` |
| `0002X5` | 92 | 94 | 93.0 | `by-global/g_pChattingVarietyPane.md` |
| `0002XA` | 92 | 94 | 93.0 | `by-global/g_pChattingVarietySelectPane.md` |
| `0000QJ` | 92 | 94 | 93.0 | `by-global/g_pCheatDetector.md` |
| `0000QN` | 92 | 94 | 93.0 | `by-global/g_pCrashTarget.md` |
| `0000QR` | 92 | 94 | 93.0 | `by-global/g_pDescPane.md` |

### by-global_Not_Reconstructable

| UID | Completion | Confidence | Combined | Path |
| --- | ---: | ---: | ---: | --- |
| `0000PT` | 86 | 88 | 87.0 | `by-global/g_browserControlKeyCallback.md` |
| `0000QC` | 86 | 90 | 88.0 | `by-global/g_pBrowserFileLoadText.md` |
| `0000QD` | 86 | 90 | 88.0 | `by-global/g_pBrowserOverlayLayer.md` |
| `0000QF` | 86 | 90 | 88.0 | `by-global/g_pBrowserTimeoutText.md` |
| `0000SV` | 86 | 90 | 88.0 | `by-global/g_uiTileRenderer.md` |
| `0000T0` | 86 | 91 | 88.5 | `by-global/HasDATEntry_49C700.md` |
| `0000PL` | 88 | 90 | 89.0 | `by-global/EnsureLoginDialogPane_4F8B30.md` |
| `0000TL` | 88 | 91 | 89.5 | `by-global/SendOptionPacket11B_540E50.md` |
| `0000T5` | 88 | 92 | 90.0 | `by-global/LoadIndexedDATSeries.md` |
| `0000TI` | 89 | 92 | 90.5 | `by-global/PoolAllocatorStaticInstances.md` |
| `0000QW` | 90 | 92 | 91.0 | `by-global/g_pfnLockSurface.md` |
| `0000PN` | 91 | 93 | 92.0 | `by-global/FrameChromeSlots.md` |
| `0000T3` | 92 | 96 | 94.0 | `by-global/InitializeOleSupport.md` |

### by-item_Reconstructable

| UID | Completion | Confidence | Combined | Path |
| --- | ---: | ---: | ---: | --- |
| `0000UD` | 85 | 90 | 87.5 | `by-item/DecodePcxToRgb565Buffer_00549410.md` |
| `0000US` | 85 | 90 | 87.5 | `by-item/HalfBlendSpan16Blocks_00460C10.md` |
| `0000V7` | 85 | 90 | 87.5 | `by-item/PhoneBookListHelpers_58cfa0_58dcb0.md` |
| `0000VE` | 85 | 90 | 87.5 | `by-item/ScreenEffecterSmallConstructorBoundaries.md` |
| `0000UL` | 86 | 89 | 87.5 | `by-item/EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0.md` |
| `0000V2` | 86 | 89 | 87.5 | `by-item/PacketDigest_00515380.md` |
| `0000U1` | 86 | 90 | 88.0 | `by-item/BlendRgb565Pixel_004C6050.md` |
| `0000V0` | 86 | 90 | 88.0 | `by-item/LoadTileEpfMetadata_004D1B80.md` |
| `0000V8` | 86 | 90 | 88.0 | `by-item/PopupMenuSelectionCallback_0049AF00.md` |
| `0000VC` | 86 | 90 | 88.0 | `by-item/ScaleDirectionOffsetToPixels_00505100.md` |
| `0000TW` | 86 | 91 | 88.5 | `by-item/AlphaBlendSpan16Blocks_00460B00.md` |
| `0000TZ` | 86 | 91 | 88.5 | `by-item/BlendRgb555_004C0710.md` |
| `0000U9` | 86 | 91 | 88.5 | `by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md` |
| `0000V4` | 86 | 91 | 88.5 | `by-item/PaletteSlotTable.md` |
| `0000UZ` | 87 | 90 | 88.5 | `by-item/LoadPcxImage_004A17B0.md` |
| `0000VA` | 87 | 91 | 89.0 | `by-item/ResolveSpritePartPath_004E19D0.md` |
| `0000U0` | 88 | 90 | 89.0 | `by-item/BlendRgb565Pair_004C60D0.md` |
| `0000UR` | 88 | 91 | 89.5 | `by-item/GetSpriteBounds_004DE2A0.md` |
| `0000TV` | 88 | 92 | 90.0 | `by-item/AlphaBlendSpan16_00460500.md` |
| `0000UW` | 88 | 92 | 90.0 | `by-item/LoadDatFileBuffer_004BB120.md` |
| `0000U6` | 89 | 91 | 90.0 | `by-item/BuildTilecArchiveTable_004DDA60.md` |
| `0000U4` | 89 | 92 | 90.5 | `by-item/BuildEffectArchiveTable_004DE420.md` |
| `0000V5` | 89 | 92 | 90.5 | `by-item/ParseEntries_004A5E60.md` |
| `0000V9` | 89 | 93 | 91.0 | `by-item/ProfileDialogDestructorAndRefreshHelpers_53fda0_53fe90.md` |
| `0000UN` | 90 | 92 | 91.0 | `by-item/EPFArchiveMetadataTable.md` |
| `0000V1` | 90 | 92 | 91.0 | `by-item/PacketBufferHelpers.md` |
| `0000UK` | 91 | 91 | 91.0 | `by-item/DrawTextRunCallback_00593DB0.md` |
| `0000V3` | 91 | 93 | 92.0 | `by-item/PacketTransformHelpers.md` |
| `0000VG` | 91 | 94 | 92.5 | `by-item/ServerSelectHelpers_574510_5745b0.md` |
| `0000VB` | 92 | 94 | 93.0 | `by-item/ResourceLayoutEntry.md` |
| `0000VF` | 92 | 94 | 93.0 | `by-item/ScreenshotProofPacket_00558240.md` |
| `0000UM` | 93 | 94 | 93.5 | `by-item/EncodeTextEditState_0058E490.md` |
| `00054J` | 93 | 94 | 93.5 | `by-item/HistoryViewingPaneFileShell.md` |
| `0004WV` | 93 | 94 | 93.5 | `by-item/SoundManagerMilesCallbackDeclarations.md` |
| `0000U2` | 93 | 95 | 94.0 | `by-item/BuildAboveFrameBorder_00461310.md` |
| `0000UC` | 94 | 96 | 95.0 | `by-item/DATEntryRecord.md` |

### by-item_Not_Reconstructable

| UID | Completion | Confidence | Combined | Path |
| --- | ---: | ---: | ---: | --- |
| `0000TT` | 85 | 90 | 87.5 | `by-item/AddEmployeeItemDialogInlineConstruction_004A339F.md` |
| `0000UA` | 86 | 89 | 87.5 | `by-item/CurlWriteCallback_00581B80.md` |
| `0000U8` | 86 | 90 | 88.0 | `by-item/CheckTimerSkewAndSendHeartbeat_466CA0.md` |
| `0000UO` | 86 | 90 | 88.0 | `by-item/FolderTreePaneOwnerPollution_47f280_58a8e0.md` |
| `0000UT` | 86 | 91 | 88.5 | `by-item/HasDATEntry_0049C700.md` |
| `0000VK` | 86 | 91 | 88.5 | `by-item/VectorGrowArchiveIndex_004E5990.md` |
| `0000UY` | 87 | 91 | 89.0 | `by-item/LoadImageFrameTable_004D0F50.md` |
| `0000TY` | 88 | 90 | 89.0 | `by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md` |
| `0000VI` | 88 | 90 | 89.0 | `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md` |
| `0000TX` | 88 | 91 | 89.5 | `by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md` |
| `0000VH` | 88 | 92 | 90.0 | `by-item/SpellMenuActionButtonState_51d6c0_51e600.md` |
| `0000UX` | 89 | 93 | 91.0 | `by-item/LoadFrameDrawRecord_004D1600.md` |
| `0000UP` | 90 | 93 | 91.5 | `by-item/FriendNameListSyncOpcodes.md` |
| `0000UV` | 91 | 93 | 92.0 | `by-item/InitializeMainUiGraph_004F7D10.md` |
| `0000V6` | 91 | 94 | 92.5 | `by-item/PathExistsViaStat_00582460.md` |
| `0000VJ` | 91 | 94 | 92.5 | `by-item/TransferServerDialogPaneThunks_599220_5993e0.md` |
| `0000UE` | 92 | 94 | 93.0 | `by-item/DeserializePredefinedFormArticleEntries_478650.md` |
| `0000U7` | 92 | 95 | 93.5 | `by-item/CheckBoxControlPaneSetVisualState_00499EC0.md` |
| `0000U3` | 95 | 95 | 95.0 | `by-item/BuildClippedAlphaSurfaceView_00462320.md` |

### by-memory_Reconstructable

| UID | Completion | Confidence | Combined | Path |
| --- | ---: | ---: | ---: | --- |
| `00041T` | 84 | 88 | 86.0 | `by-memory/0x004df1e0-0x004df2b7.ItemObjImageLibDrawItemImageUnscaled.md` |
| `0004EW` | 85 | 87 | 86.0 | `by-memory/0x005566b0-0x005566ba.RingBufferFullPredicateAlias.md` |
| `00044Z` | 85 | 87 | 86.0 | `by-memory/0x005609e0-0x00560a04.ScrollNewGroupPaneStyleByteSetterRaw.md` |
| `0003GY` | 86 | 86 | 86.0 | `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md` |
| `0000YR` | 85 | 88 | 86.5 | `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md` |
| `000123` | 85 | 88 | 86.5 | `by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md` |
| `0003LP` | 85 | 88 | 86.5 | `by-memory/0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor.md` |
| `0002R4` | 85 | 88 | 86.5 | `by-memory/0x00543670-0x005436f4.PaletteCollectionColorTransformRaw.md` |
| `0003OB` | 85 | 88 | 86.5 | `by-memory/0x0055b4c0-0x0055b5c3.YFlipEffecterApplyEffect.md` |
| `0003HC` | 85 | 88 | 86.5 | `by-memory/0x0055b860-0x0055b866.LakeEffecterResetVtable.md` |
| `00044Y` | 85 | 88 | 86.5 | `by-memory/0x005609b0-0x005609d7.ScrollNewGroupPaneSkinIndexSetterRaw.md` |
| `0003QG` | 85 | 88 | 86.5 | `by-memory/0x005671a0-0x005671b7.SelfLookPaneSpelledEntryRemoveForwarderRaw.md` |
| `0003R4` | 85 | 88 | 86.5 | `by-memory/0x00570b80-0x00570b9a.SelfLookPane2SpelledEntryUpdateForwarderRaw.md` |
| `0003R5` | 85 | 88 | 86.5 | `by-memory/0x00570ba0-0x00570bb7.SelfLookPane2SpelledEntryRemoveForwarderRaw.md` |
| `0003R6` | 85 | 88 | 86.5 | `by-memory/0x00570bc0-0x00570bde.SelfLookPane2RefreshSpelledChildRaw.md` |
| `0003R7` | 85 | 88 | 86.5 | `by-memory/0x00570be0-0x00570bf1.SelfLookPane2RefreshSpelledChildStateRaw.md` |
| `0003YL` | 85 | 88 | 86.5 | `by-memory/0x00575580-0x0057564e.PacketBufferHostAddressResolutionHelpers.md` |
| `0003YO` | 85 | 88 | 86.5 | `by-memory/0x005757d0-0x00575a07.PacketBufferStringWriteHelpers.md` |
| `0003A6` | 85 | 88 | 86.5 | `by-memory/0x00576570-0x00576623.SocketReconnectEndpointRaw.md` |
| `0003A7` | 85 | 88 | 86.5 | `by-memory/0x00577610-0x0057779e.SocketOpenSerialTransportRaw.md` |
| `0003FD` | 85 | 88 | 86.5 | `by-memory/0x00593f00-0x0059403b.DrawTextRunCallbackThiscallRaw.md` |
| `0003FK` | 85 | 88 | 86.5 | `by-memory/0x005b4760-0x005b47dc.SendDropAllItemPacketRaw.md` |
| `0003FL` | 85 | 88 | 86.5 | `by-memory/0x005b4af0-0x005b4b6c.SendDropItemPacketRaw.md` |
| `0003FM` | 85 | 88 | 86.5 | `by-memory/0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw.md` |
| `0003FN` | 85 | 88 | 86.5 | `by-memory/0x005b4ef0-0x005b4f6c.SendGiveAllItemPacketRaw.md` |
| `0003FO` | 85 | 88 | 86.5 | `by-memory/0x005b5230-0x005b52ac.SendGiveItemPacketRaw.md` |
| `0003NX` | 85 | 88 | 86.5 | `by-memory/0x005b5ab0-0x005b5b2c.SendThrowItemPacketRaw.md` |
| `0003AH` | 85 | 88 | 86.5 | `by-memory/0x005bc890-0x005bc96a.MenuVarietyPaneButtonRectHelpers.md` |
| `0003AJ` | 85 | 88 | 86.5 | `by-memory/0x005bffe0-0x005c0034.MenuVarietyLabelVectorAppendMoveHelper.md` |
| `0003O4` | 85 | 88 | 86.5 | `by-memory/0x005c2a20-0x005c2a5b.SnowingLayerPaneScalarDeletingDestructor.md` |
| `0003ST` | 85 | 88 | 86.5 | `by-memory/0x005c50f0-0x005c5156.WorldMapPaneUpdateHoverFromMouseStrict.md` |
| `0003SU` | 85 | 88 | 86.5 | `by-memory/0x005c5160-0x005c519c.WorldMapPaneFindPredecessorNode.md` |
| `0003SV` | 85 | 88 | 86.5 | `by-memory/0x005c51a0-0x005c51fb.WorldMapPaneScreenPointHelper.md` |
| `00041A` | 86 | 87 | 86.5 | `by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md` |
| `00021D` | 85 | 89 | 87.0 | `by-memory/0x00485440-0x004854a5.SendClanStatusRefreshRequestPacket.md` |
| `00021I` | 85 | 89 | 87.0 | `by-memory/0x00485780-0x00485867.ClanDepositMoneyRequestAndSubmitPacketHelpers.md` |
| `00021J` | 85 | 89 | 87.0 | `by-memory/0x00485870-0x00485955.ClanDepositItemRequestAndSubmitPacketHelpers.md` |
| `000377` | 85 | 89 | 87.0 | `by-memory/0x00516c40-0x00516c9a.MenuPaneFindPreviousEnabledItemRaw.md` |
| `000378` | 85 | 89 | 87.0 | `by-memory/0x00516ca0-0x00516cf3.MenuPaneFindNextEnabledItemRaw.md` |
| `0001CO` | 85 | 89 | 87.0 | `by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md` |
| `0003QA` | 85 | 89 | 87.0 | `by-memory/0x00565890-0x00566f24.SelfLookPaneOnReceiveCharacterData.md` |
| `0003QK` | 85 | 89 | 87.0 | `by-memory/0x00567280-0x005672b0.SelfLookPaneActivateView.md` |
| `0003QL` | 85 | 89 | 87.0 | `by-memory/0x005672b0-0x0056737f.SelfLookPaneDeactivateResetRaw.md` |
| `0003QM` | 85 | 89 | 87.0 | `by-memory/0x00567380-0x00567472.SelfLookPaneDeactivateView.md` |
| `0003QO` | 85 | 89 | 87.0 | `by-memory/0x00568bd0-0x00568ca9.SelfLookPaneOnKeyPress.md` |
| `0003QR` | 85 | 89 | 87.0 | `by-memory/0x00569860-0x00569c80.SelfLookPaneOnShowHelp.md` |
| `0003QS` | 85 | 89 | 87.0 | `by-memory/0x00569c80-0x00569cce.SelfLookPaneOnGetRect.md` |
| `0003QT` | 85 | 89 | 87.0 | `by-memory/0x00569cd0-0x00569d75.SelfLookPaneOnTransformRect.md` |
| `00039L` | 85 | 89 | 87.0 | `by-memory/0x005729e0-0x00572b54.SelfLookPane2PacketSendRawHelpers.md` |
| `0003RJ` | 85 | 89 | 87.0 | `by-memory/0x0059f500-0x0059f604.UserLookPaneNonDeletingDestructor.md` |
| `0003AI` | 85 | 89 | 87.0 | `by-memory/0x005bd960-0x005bd9ad.MenuVarietySelectPaneRowRectHelper.md` |
| `0003SE` | 85 | 89 | 87.0 | `by-memory/0x005c3420-0x005c346d.WorldMapPaneSetViewPosition.md` |
| `0003SF` | 85 | 89 | 87.0 | `by-memory/0x005c34c0-0x005c3508.WorldMapPaneStartViewAnimation.md` |
| `0003SH` | 85 | 89 | 87.0 | `by-memory/0x005c3630-0x005c36c8.WorldMapPaneSendTravelPacket.md` |
| `0003SL` | 85 | 89 | 87.0 | `by-memory/0x005c3e50-0x005c402b.WorldMapPaneHandleKeyEvent.md` |
| `0003SM` | 85 | 89 | 87.0 | `by-memory/0x005c40c0-0x005c4245.WorldMapPaneHandleMouseEvent.md` |
| `0003SO` | 85 | 89 | 87.0 | `by-memory/0x005c46f0-0x005c4733.WorldMapPaneOnTimerTick.md` |
| `0003SQ` | 85 | 89 | 87.0 | `by-memory/0x005c48b0-0x005c4bd0.WorldMapPaneDrawPlayerMarker.md` |
| `0003NI` | 85 | 89 | 87.0 | `by-memory/0x0061a374-0x0061a37c.AddItemWithCountDialogQuantityFormatString.md` |
| `00040A` | 86 | 88 | 87.0 | `by-memory/0x0046a8e0-0x0046a901.BrowserPaneOnKeyEvent.md` |
| `0003KT` | 86 | 88 | 87.0 | `by-memory/0x004a2450-0x004a2531.EmployeeInventoryItemCommandHelper.md` |
| `00016Z` | 86 | 88 | 87.0 | `by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md` |
| `000417` | 86 | 88 | 87.0 | `by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md` |
| `000419` | 86 | 88 | 87.0 | `by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md` |
| `00041C` | 86 | 88 | 87.0 | `by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md` |
| `00041D` | 86 | 88 | 87.0 | `by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md` |
| `00041E` | 86 | 88 | 87.0 | `by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md` |
| `00041F` | 86 | 88 | 87.0 | `by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md` |
| `00041G` | 86 | 88 | 87.0 | `by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md` |
| `00035T` | 86 | 88 | 87.0 | `by-memory/0x004f2320-0x004f242f.LineInputPaneUpdateChildLayout.md` |
| `00035U` | 86 | 88 | 87.0 | `by-memory/0x004f2430-0x004f24b5.LineInputPaneAttachChildren.md` |
| `00035V` | 86 | 88 | 87.0 | `by-memory/0x004f24c0-0x004f24e5.LineInputPaneShowChildren.md` |
| `00035W` | 86 | 88 | 87.0 | `by-memory/0x004f24f0-0x004f257a.LineInputPaneHitTestForwarder.md` |
| `00035X` | 86 | 88 | 87.0 | `by-memory/0x004f2580-0x004f2598.LineInputPaneActiveChildForwarder.md` |
| `00035Z` | 86 | 88 | 87.0 | `by-memory/0x004f2760-0x004f2783.LineInputPaneTextEditForwarder.md` |
| `000361` | 86 | 88 | 87.0 | `by-memory/0x004f27a0-0x004f2813.NumberInputPaneConstructor.md` |
| `000362` | 86 | 88 | 87.0 | `by-memory/0x004f2820-0x004f289b.NumberInputPaneKeyFilter.md` |
| `000363` | 86 | 88 | 87.0 | `by-memory/0x004f28a0-0x004f2913.CharInputPaneConstructor.md` |
| `000365` | 86 | 88 | 87.0 | `by-memory/0x004f29d0-0x004f2a05.ConfirmInputPaneCompleteDestructor.md` |
| `000367` | 86 | 88 | 87.0 | `by-memory/0x004f2a60-0x004f2ad3.CharArgsInputPaneConstructor.md` |
| `000368` | 86 | 88 | 87.0 | `by-memory/0x004f2ae0-0x004f2b74.CharArgsInputPaneKeyFilter.md` |
| `000369` | 86 | 88 | 87.0 | `by-memory/0x004f2b80-0x004f2bf3.NumberArgsInputPaneConstructor.md` |
| `00036A` | 86 | 88 | 87.0 | `by-memory/0x004f2c00-0x004f2c85.NumberArgsInputPaneKeyFilter.md` |
| `00036B` | 86 | 88 | 87.0 | `by-memory/0x004f2c90-0x004f2cc5.MultiLineInputPaneConstructor.md` |
| `00036C` | 86 | 88 | 87.0 | `by-memory/0x004f2cd0-0x004f2dcb.MultiLineInputPaneKeyHandler.md` |
| `00042B` | 86 | 88 | 87.0 | `by-memory/0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch.md` |
| `00042C` | 86 | 88 | 87.0 | `by-memory/0x005057d0-0x005058ac.MapPaneRawObjectCleanupSweep.md` |
| `0003VO` | 86 | 88 | 87.0 | `by-memory/0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem.md` |
| `0002BC` | 86 | 88 | 87.0 | `by-memory/0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers.md` |
| `0003Z8` | 86 | 88 | 87.0 | `by-memory/0x0053c390-0x0053c5da.LivingObjectPaneTryStepForward.md` |
| `0003LS` | 86 | 88 | 87.0 | `by-memory/0x00543450-0x005435a5.CloneDLPaletteList.md` |
| `0004ES` | 86 | 88 | 87.0 | `by-memory/0x00556670-0x0055667a.RingBufferIsFullRawPredicate.md` |
| `0004EV` | 86 | 88 | 87.0 | `by-memory/0x005566a0-0x005566a8.RingBufferEmptyPredicateAlias.md` |
| `00039T` | 86 | 88 | 87.0 | `by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md` |
| `00039U` | 86 | 88 | 87.0 | `by-memory/0x00558680-0x00558688.UnresolvedPresentationFlagSetter.md` |
| `00042X` | 86 | 88 | 87.0 | `by-memory/0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md` |
| `0003M8` | 86 | 88 | 87.0 | `by-memory/0x005954c0-0x00595760.TextEditSupportObjectsAfterTextBoxPane.md` |
| `0003V7` | 86 | 88 | 87.0 | `by-memory/0x005971b0-0x005974da.ThreadManWatchListRawHelpers.md` |
| `0002B7` | 86 | 88 | 87.0 | `by-memory/0x0067adf0-0x0069adf0.WideCharStrGlobalBuffer.md` |
| `00020U` | 85 | 90 | 87.5 | `by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md` |
| `00021E` | 85 | 90 | 87.5 | `by-memory/0x004854b0-0x00485518.SendClanEnlistRequestRefreshPacket.md` |
| `00021F` | 85 | 90 | 87.5 | `by-memory/0x00485520-0x00485588.SendClanJoinListRefreshPacket.md` |
| `00021H` | 85 | 90 | 87.5 | `by-memory/0x00485690-0x004856f9.SendClanLeaveRequestPacket.md` |
| `000139` | 85 | 90 | 87.5 | `by-memory/0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor.md` |
| `0003LZ` | 85 | 90 | 87.5 | `by-memory/0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable.md` |
| `00037O` | 85 | 90 | 87.5 | `by-memory/0x004f3980-0x004f398b.SortedListClear.md` |
| `0003HW` | 85 | 90 | 87.5 | `by-memory/0x00537d60-0x00537d7f.FlyingObjectPaneNonDeletingDestructor.md` |
| `000394` | 85 | 90 | 87.5 | `by-memory/0x00559dd0-0x00559e2d.ScreenDimmerOnPaint.md` |
| `0003Q9` | 85 | 90 | 87.5 | `by-memory/0x005657e0-0x00565887.SelfLookPaneNonDeletingDestructor.md` |
| `0003SI` | 85 | 90 | 87.5 | `by-memory/0x005c36d0-0x005c37d6.WorldMapPaneApplyVisibleClipRect.md` |
| `0003NK` | 85 | 90 | 87.5 | `by-memory/0x0061a1bc-0x0061a1c0.ExchangeAlertPaneRttiLocatorPointer.md` |
| `0003NH` | 85 | 90 | 87.5 | `by-memory/0x0061a344-0x0061a374.AddItemDialogResourceStrings.md` |
| `0003OM` | 85 | 90 | 87.5 | `by-memory/0x0061ce84-0x0061cf44.ListPaneVtableData.md` |
| `0003CH` | 85 | 90 | 87.5 | `by-memory/0x006222b4-0x006222d4.PowerDialogResourceStrings.md` |

### by-memory_Not_Reconstructable

| UID | Completion | Confidence | Combined | Path |
| --- | ---: | ---: | ---: | --- |
| `0004B1` | 82 | 86 | 84.0 | `by-memory/0x0054a960-0x0054aa96.PowerDialogPaneUnreferencedApplyAllThresholdsRaw.md` |
| `0004B2` | 82 | 86 | 84.0 | `by-memory/0x0054aaa0-0x0054ab87.PowerDialogPaneUnreferencedSelectedPowerSlotRaw.md` |
| `0001MO` | 82 | 88 | 85.0 | `by-memory/0x005b6120-0x005b62c8.SpellSpellInputPane.md` |
| `00043Z` | 84 | 86 | 85.0 | `by-memory/0x0052b950-0x0052b981.NewUserDialogPane2ClearGenderSelectionButtonsRaw.md` |
| `000440` | 84 | 86 | 85.0 | `by-memory/0x0052b990-0x0052b9ed.NewUserDialogPane2ClearTotemSelectionButtonsRaw.md` |
| `00021B` | 84 | 88 | 86.0 | `by-memory/0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup.md` |
| `0002EE` | 85 | 87 | 86.0 | `by-memory/0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md` |
| `0000WT` | 85 | 88 | 86.5 | `by-memory/0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland.md` |
| `000229` | 85 | 88 | 86.5 | `by-memory/0x004a60a0-0x004a60cb.MsvcInt64RuntimeHelpers.md` |
| `00014X` | 85 | 88 | 86.5 | `by-memory/0x004b08cd-0x004b08e3.ExchangeAlertPaneAdjustorThunks.md` |
| `00014Y` | 85 | 88 | 86.5 | `by-memory/0x004b0ab5-0x004b0acb.ExchangeMoneyEditControlPaneAdjustorThunks.md` |
| `00019I` | 85 | 88 | 86.5 | `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md` |
| `00019U` | 85 | 88 | 86.5 | `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md` |
| `0003VP` | 85 | 88 | 86.5 | `by-memory/0x00516040-0x00516045.MemoryManNoXrefReturnZeroStub.md` |
| `0003QB` | 85 | 88 | 86.5 | `by-memory/0x00566f30-0x00566f31.SelfLookPaneNullStub.md` |
| `0003R0` | 85 | 88 | 86.5 | `by-memory/0x00570930-0x00570931.SelfLookPane2NullStub.md` |
| `0003RL` | 85 | 88 | 86.5 | `by-memory/0x005a0630-0x005a0631.UserLookPaneNullStub.md` |
| `0002S8` | 85 | 88 | 86.5 | `by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md` |
| `0003EV` | 85 | 88 | 86.5 | `by-memory/0x006247f0-0x00624804.SharedCommaEpfResourceString.md` |
| `0003EX` | 85 | 88 | 86.5 | `by-memory/0x006248cc-0x006248e0.SharedCommaPalResourceString.md` |
| `00035O` | 85 | 88 | 86.5 | `by-memory/0x0066d412-0x0066d414.PaddingBeforeBalloonObjectPaneMasks.md` |
| `0001ZV` | 84 | 90 | 87.0 | `by-memory/0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport.md` |
| `0001ZW` | 84 | 90 | 87.0 | `by-memory/0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport.md` |
| `0001ZX` | 84 | 90 | 87.0 | `by-memory/0x00442090-0x00443a55.JsonCppWriterRuntimeTailSupport.md` |
| `0000ZM` | 84 | 90 | 87.0 | `by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md` |
| `000102` | 84 | 90 | 87.0 | `by-memory/0x0047ef40-0x0047ef4b.ClearChangeManSingleton.md` |
| `0002GI` | 84 | 90 | 87.0 | `by-memory/0x004839c0-0x00483ef7.ChattingUiDestructorGlueFamily.md` |
| `00017C` | 84 | 90 | 87.0 | `by-memory/0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster.md` |
| `0001AF` | 84 | 90 | 87.0 | `by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md` |
| `0001CK` | 84 | 90 | 87.0 | `by-memory/0x00528290-0x005283d5.CashShopRequestAuthDirectory.md` |
| `00039J` | 84 | 90 | 87.0 | `by-memory/0x00573970-0x00573979.ZeroInitializePointerHelper.md` |
| `0003CE` | 84 | 90 | 87.0 | `by-memory/0x00620c68-0x00620c6c.SharedMinimumFloatConstant.md` |
| `0001Z5` | 85 | 89 | 87.0 | `by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md` |

### by-meta_Reconstructable

_No scored files._

### by-meta_Not_Reconstructable

_No scored files._

### by-project-structure_Reconstructable

_No scored files._

### by-project-structure_Not_Reconstructable

_No scored files._

### by-resource_Reconstructable

_No scored files._

### by-resource_Not_Reconstructable

| UID | Completion | Confidence | Combined | Path |
| --- | ---: | ---: | ---: | --- |
| `0001RM` | 87 | 92 | 89.5 | `by-resource/staff-dialog-resources.md` |
| `0001RQ` | 87 | 92 | 89.5 | `by-resource/timerpane-number-resources.md` |
| `0001RR` | 87 | 92 | 89.5 | `by-resource/totem-frame-resources.md` |
| `0001RT` | 87 | 92 | 89.5 | `by-resource/webboard-dialog-resources.md` |
| `0001RK` | 88 | 91 | 89.5 | `by-resource/ranking-ui-resources.md` |
| `0001R5` | 88 | 92 | 90.0 | `by-resource/alert-dialog-resources.md` |
| `0001R7` | 88 | 92 | 90.0 | `by-resource/backpane-background-resources.md` |
| `0001RE` | 88 | 92 | 90.0 | `by-resource/interface-efx-resources.md` |
| `0001RO` | 88 | 92 | 90.0 | `by-resource/startup-update-notice-resources.md` |
| `0001RN` | 87 | 94 | 90.5 | `by-resource/startup-logo-media.md` |
| `0001R9` | 88 | 93 | 90.5 | `by-resource/employee-dialog-resources.md` |
| `0001RB` | 88 | 93 | 90.5 | `by-resource/forced-inform-message-resources.md` |
| `0001RI` | 88 | 93 | 90.5 | `by-resource/new-human-motion-tables.md` |
| `0001RJ` | 88 | 93 | 90.5 | `by-resource/number-input-dialog-resources.md` |
| `0001RC` | 89 | 92 | 90.5 | `by-resource/hourpane-time-resources.md` |
| `0001RD` | 89 | 92 | 90.5 | `by-resource/iconspane-icon-resources.md` |
| `0001RG` | 89 | 92 | 90.5 | `by-resource/main-menu-story-resources.md` |
| `0001RH` | 89 | 92 | 90.5 | `by-resource/meta-dat-metadata-cache.md` |
| `0001RA` | 88 | 94 | 91.0 | `by-resource/exchange-dialog-resources.md` |
| `0001R8` | 89 | 93 | 91.0 | `by-resource/collection-ui-resources.md` |
| `0001R6` | 90 | 92 | 91.0 | `by-resource/application-startup-dat-archives.md` |
| `0001RS` | 90 | 92 | 91.0 | `by-resource/user-status-resources.md` |
| `0001RF` | 90 | 93 | 91.5 | `by-resource/main-menu-history-resources.md` |
| `0001RL` | 90 | 93 | 91.5 | `by-resource/sobj-tbl.md` |
| `00055D` | 91 | 94 | 92.5 | `by-resource/argumented-item-input-dialog-resources.md` |
| `0004SY` | 92 | 94 | 93.0 | `by-resource/dialog-frame-resources.md` |

### by-type_Reconstructable

| UID | Completion | Confidence | Combined | Path |
| --- | ---: | ---: | ---: | --- |
| `0001VH` | 85 | 88 | 86.5 | `by-type/by-struct/PaneLayout.md` |
| `0001TN` | 85 | 89 | 87.0 | `by-type/by-struct/AddEmployeeItemDialogLayout.md` |
| `0001SK` | 86 | 88 | 87.0 | `by-type/by-enum/BrowserInitFlags.md` |
| `0001UE` | 86 | 88 | 87.0 | `by-type/by-struct/ErrorObjectLayouts.md` |
| `0001X5` | 86 | 88 | 87.0 | `by-type/by-vtable/BulletinDialogVtables.md` |
| `0001UI` | 85 | 90 | 87.5 | `by-type/by-struct/FittingRoomDownloadProgressState.md` |
| `0001SM` | 86 | 89 | 87.5 | `by-type/by-enum/BrowserOverlayStyle.md` |
| `0001XU` | 86 | 89 | 87.5 | `by-type/by-vtable/ItemActionInputPaneVtableFamily.md` |
| `0001SL` | 85 | 91 | 88.0 | `by-type/by-enum/BrowserMessageId.md` |
| `0001YR` | 85 | 91 | 88.0 | `by-type/by-vtable/ScrollNewGroupPaneVtables.md` |
| `0001SJ` | 86 | 90 | 88.0 | `by-type/by-enum/BrowserDispatchEventId.md` |
| `0001UF` | 86 | 90 | 88.0 | `by-type/by-struct/EventDispatcherHandlerTreeLayouts.md` |
| `0001US` | 86 | 90 | 88.0 | `by-type/by-struct/ImageLibLayout.md` |
| `0001XI` | 86 | 90 | 88.0 | `by-type/by-vtable/ErrorHierarchyVtables.md` |
| `0001XX` | 86 | 90 | 88.0 | `by-type/by-vtable/KeySpeedMgrVtable.md` |
| `0001Y9` | 86 | 90 | 88.0 | `by-type/by-vtable/NewHumanImageLibVtable.md` |
| `0001YZ` | 86 | 90 | 88.0 | `by-type/by-vtable/UrlAlertPaneVtables.md` |
| `0001W4` | 87 | 89 | 88.0 | `by-type/by-struct/SimpleUStringPointerBackedLayout.md` |
| `0001UC` | 86 | 91 | 88.5 | `by-type/by-struct/EmployeeQuantityInputDialogPaneLayout.md` |
| `0001VW` | 86 | 91 | 88.5 | `by-type/by-struct/RidingImageLibLayout.md` |
| `0001X3` | 86 | 91 | 88.5 | `by-type/by-vtable/BlueAlertPaneVtables.md` |
| `0001X7` | 86 | 91 | 88.5 | `by-type/by-vtable/ChangeManVtable.md` |
| `0001YH` | 86 | 91 | 88.5 | `by-type/by-vtable/ProgressBarControlPaneVtables.md` |
| `0001YM` | 86 | 91 | 88.5 | `by-type/by-vtable/RidingImageLibVtable.md` |
| `0001V6` | 87 | 90 | 88.5 | `by-type/by-struct/MetaTableDecodedPayload.md` |
| `0001VD` | 87 | 90 | 88.5 | `by-type/by-struct/MonsterImageLibLayout.md` |
| `0001W6` | 87 | 90 | 88.5 | `by-type/by-struct/SimpleUStringVectorLayout.md` |
| `0001VC` | 88 | 89 | 88.5 | `by-type/by-struct/MonsterImageEntry.md` |
| `00036L` | 86 | 92 | 89.0 | `by-type/by-vtable/FolderTreePaneTreeItorVtable.md` |
| `0001YF` | 86 | 92 | 89.0 | `by-type/by-vtable/PatchPaneVtableFamily.md` |
| `0001YJ` | 86 | 92 | 89.0 | `by-type/by-vtable/RankingDialogVtableFamily.md` |
| `0001SV` | 87 | 91 | 89.0 | `by-type/by-field/SelectionControlPaneSelectedValue_0x10c.md` |
| `0001UA` | 87 | 91 | 89.0 | `by-type/by-struct/EffectPixMapInfo.md` |
| `0001VB` | 87 | 91 | 89.0 | `by-type/by-struct/MonsterArchiveBoundsEntry.md` |
| `0001VM` | 87 | 91 | 89.0 | `by-type/by-struct/ProtectedArrayLayout.md` |
| `000320` | 87 | 91 | 89.0 | `by-type/by-vtable/ArgumentedMenuDialogVtables.md` |
| `0003HJ` | 87 | 91 | 89.0 | `by-type/by-vtable/ChangeSpellSlotInputPaneVtables.md` |
| `0001SF` | 88 | 90 | 89.0 | `by-type/by-constant/DownloaderMessageIds.md` |
| `0001SN` | 88 | 90 | 89.0 | `by-type/by-enum/HttpGetNotificationState.md` |
| `0001SO` | 88 | 90 | 89.0 | `by-type/by-enum/MapServerPacketOpcode.md` |
| `0001U7` | 88 | 90 | 89.0 | `by-type/by-struct/EffectFrameRecord.md` |
| `0001U8` | 88 | 90 | 89.0 | `by-type/by-struct/EffectInfo.md` |
| `0001V1` | 88 | 90 | 89.0 | `by-type/by-struct/MacroHotkeyRecord.md` |
| `0001V7` | 88 | 90 | 89.0 | `by-type/by-struct/MetaTableRowNode.md` |
| `0001WB` | 88 | 90 | 89.0 | `by-type/by-struct/ThreadManWatchRecord.md` |
| `0001WQ` | 88 | 90 | 89.0 | `by-type/by-template/FunctionObjectTemplates.md` |
| `0003HF` | 87 | 92 | 89.5 | `by-type/by-vtable/ClanBankVtables.md` |
| `0003HE` | 87 | 92 | 89.5 | `by-type/by-vtable/ClanModalDialogVtables.md` |
| `0001Y7` | 87 | 92 | 89.5 | `by-type/by-vtable/MonsterImageLibVtable.md` |
| `0001SP` | 88 | 91 | 89.5 | `by-type/by-enum/MiscWorkThreadMessageId.md` |
| `0001SR` | 88 | 91 | 89.5 | `by-type/by-enum/ThreadManMessageId.md` |
| `0001UP` | 88 | 91 | 89.5 | `by-type/by-struct/GameServerNationEntry.md` |
| `0001UV` | 88 | 91 | 89.5 | `by-type/by-struct/KeySpeedMgrLayout.md` |
| `0001V3` | 88 | 91 | 89.5 | `by-type/by-struct/MapTileRecord.md` |
| `0001VA` | 88 | 91 | 89.5 | `by-type/by-struct/MonsterArchiveBoundsBucket.md` |
| `0001VO` | 88 | 91 | 89.5 | `by-type/by-struct/RankingEventScrollPaneLayout.md` |
| `0001WS` | 88 | 91 | 89.5 | `by-type/by-template/StringBaseTemplate.md` |
| `0001TY` | 88 | 92 | 90.0 | `by-type/by-struct/ClanInputDialogLayouts.md` |
| `0001UD` | 88 | 92 | 90.0 | `by-type/by-struct/EmployeeRecord.md` |
| `0003IE` | 88 | 92 | 90.0 | `by-type/by-vtable/AddItemWithCountDialogVtables.md` |
| `0003IF` | 88 | 92 | 90.0 | `by-type/by-vtable/AddMixingItemDialogVtables.md` |
| `0001WZ` | 88 | 92 | 90.0 | `by-type/by-vtable/AlertPaneVtables.md` |
| `0003HN` | 88 | 92 | 90.0 | `by-type/by-vtable/BlockListenInputPaneFamilyVtables.md` |
| `0001XJ` | 88 | 92 | 90.0 | `by-type/by-vtable/ExchangeAlertPaneVtables.md` |
| `0003IH` | 88 | 92 | 90.0 | `by-type/by-vtable/MixItemDialogDoubleParamCallbackVtable.md` |
| `0001YK` | 88 | 92 | 90.0 | `by-type/by-vtable/RankingEventScrollPaneVtables.md` |
| `0001YO` | 88 | 92 | 90.0 | `by-type/by-vtable/ScreenEffecterVtableFamily.md` |
| `0001V4` | 89 | 91 | 90.0 | `by-type/by-struct/MemoryManLayout.md` |
| `0004HP` | 90 | 90 | 90.0 | `by-type/by-struct/MapPaneTileRecord.md` |
| `0001SQ` | 88 | 93 | 90.5 | `by-type/by-enum/NcauthNotificationState.md` |
| `0001UB` | 88 | 93 | 90.5 | `by-type/by-struct/EmployeeItemPropertyDialogPaneLayout.md` |
| `0003I2` | 88 | 93 | 90.5 | `by-type/by-vtable/AboveFrameVtables.md` |
| `0001X4` | 88 | 93 | 90.5 | `by-type/by-vtable/BoardArticleDialogVtableFamily.md` |
| `0003J9` | 88 | 93 | 90.5 | `by-type/by-vtable/ControlPaneVtables.md` |
| `0003HO` | 88 | 93 | 90.5 | `by-type/by-vtable/DIBitmapVtable.md` |
| `00036J` | 88 | 93 | 90.5 | `by-type/by-vtable/FolderTreePaneTreeVtable.md` |
| `0001XR` | 88 | 93 | 90.5 | `by-type/by-vtable/ImageLibVtable.md` |
| `0003I1` | 88 | 93 | 90.5 | `by-type/by-vtable/StdioFileVtable.md` |
| `0001VQ` | 90 | 91 | 90.5 | `by-type/by-struct/RefCountedStringBufferHeader.md` |
| `00036N` | 89 | 93 | 91.0 | `by-type/by-vtable/FolderTreePaneClassVtables.md` |
| `0003I3` | 89 | 93 | 91.0 | `by-type/by-vtable/FramePartPaneVtables.md` |
| `00038Q` | 89 | 93 | 91.0 | `by-type/by-vtable/UserLookPaneFamilyVtables.md` |
| `0001UQ` | 90 | 92 | 91.0 | `by-type/by-struct/HierListNode.md` |
| `0001UT` | 90 | 92 | 91.0 | `by-type/by-struct/ItemInfo.md` |
| `0001UW` | 90 | 92 | 91.0 | `by-type/by-struct/LightInfo.md` |
| `0001VE` | 90 | 92 | 91.0 | `by-type/by-struct/MyItemListPaneEntryLayouts.md` |
| `0001VR` | 90 | 92 | 91.0 | `by-type/by-struct/RegistryConfigUserProfileBlock.md` |
| `0001VV` | 90 | 92 | 91.0 | `by-type/by-struct/RidingDefinition.md` |
| `0004P6` | 90 | 92 | 91.0 | `by-type/by-struct/UserCreateAppearanceControlLayouts.md` |
| `0001WG` | 89 | 94 | 91.5 | `by-type/by-struct/VirusCheckerProcessTreeLayout.md` |
| `0001XS` | 89 | 94 | 91.5 | `by-type/by-vtable/InputPaneBaseVtableFamily.md` |
| `0001V8` | 90 | 93 | 91.5 | `by-type/by-struct/MiniMapVersionNode.md` |
| `0001W5` | 90 | 93 | 91.5 | `by-type/by-struct/SimpleUStringSso7Layout.md` |
| `0003H2` | 90 | 93 | 91.5 | `by-type/by-struct/StdioFileLayout.md` |
| `0003ID` | 90 | 93 | 91.5 | `by-type/by-vtable/AddItemDialogVtables.md` |
| `0003IR` | 90 | 93 | 91.5 | `by-type/by-vtable/NumericStringControlPaneVtables.md` |
| `0001UH` | 91 | 92 | 91.5 | `by-type/by-struct/FittingEquipmentStateLayout.md` |
| `0001W8` | 90 | 94 | 92.0 | `by-type/by-struct/StaticObjEntry.md` |
| `0001WA` | 90 | 94 | 92.0 | `by-type/by-struct/ThreadManLayout.md` |
| `0003JB` | 90 | 94 | 92.0 | `by-type/by-vtable/DialogPaneVtables.md` |
| `0003HI` | 90 | 94 | 92.0 | `by-type/by-vtable/EmotionInputPaneVtables.md` |
| `0001XP` | 90 | 94 | 92.0 | `by-type/by-vtable/GroupPaneFamilyVtables.md` |
| `00038P` | 90 | 94 | 92.0 | `by-type/by-vtable/LegendPaneVtables.md` |
| `0003JA` | 90 | 94 | 92.0 | `by-type/by-vtable/PaneVtables.md` |
| `0001YI` | 90 | 94 | 92.0 | `by-type/by-vtable/PursuitMessageDialogPaneVtables.md` |
| `0003HM` | 90 | 94 | 92.0 | `by-type/by-vtable/SelfSaveInputPaneVtables.md` |
| `0003HL` | 90 | 94 | 92.0 | `by-type/by-vtable/SpellSpellInputPaneVtables.md` |
| `0004L5` | 90 | 94 | 92.0 | `by-type/by-vtable/StaticTextControlPane2Vtables.md` |
| `0001WC` | 90 | 95 | 92.5 | `by-type/by-struct/TileClassEntry.md` |
| `0001UJ` | 91 | 94 | 92.5 | `by-type/by-struct/FolderTreePane__TreeElem.md` |
| `0003HK` | 91 | 94 | 92.5 | `by-type/by-vtable/GroupPostInputPaneVtables.md` |
| `0001YT` | 91 | 94 | 92.5 | `by-type/by-vtable/ScrollVolumePaneVtables.md` |
| `0001UR` | 92 | 93 | 92.5 | `by-type/by-struct/HumanImageLibLayout.md` |
| `0004R0` | 92 | 93 | 92.5 | `by-type/by-struct/MapPoint.md` |
| `0001VF` | 92 | 93 | 92.5 | `by-type/by-struct/NewHumanImageLibLayout.md` |
| `0001VZ` | 92 | 93 | 92.5 | `by-type/by-struct/ScrollCollectionPaneLayout.md` |
| `0001Y6` | 91 | 95 | 93.0 | `by-type/by-vtable/ModelessDialogPaneVtables.md` |
| `00038M` | 91 | 95 | 93.0 | `by-type/by-vtable/SelfLookPaneFamilyVtables.md` |
| `0001YY` | 91 | 95 | 93.0 | `by-type/by-vtable/TextFilterVtable.md` |
| `0003JF` | 91 | 95 | 93.0 | `by-type/by-vtable/VirusCheckerVtable.md` |
| `000559` | 92 | 94 | 93.0 | `by-type/by-struct/ArgumentedItemConfirmInputDialogPaneLayout.md` |
| `000556` | 92 | 94 | 93.0 | `by-type/by-struct/ArgumentedItemQuantityInputDialogPaneLayout.md` |

### by-type_Not_Reconstructable

| UID | Completion | Confidence | Combined | Path |
| --- | ---: | ---: | ---: | --- |
| `0001VU` | 84 | 90 | 87.0 | `by-type/by-struct/ResourceLayoutStore.md` |
| `0001WO` | 85 | 90 | 87.5 | `by-type/by-template/CandidateStringDequeTemplate.md` |
| `0001VS` | 86 | 91 | 88.5 | `by-type/by-struct/ResourceLayoutBucket.md` |
| `000322` | 87 | 90 | 88.5 | `by-type/by-vtable/MailAlertCompanionVtables.md` |
| `0001Y0` | 88 | 91 | 89.5 | `by-type/by-vtable/LookPaneVtableFamily.md` |
| `0001UZ` | 88 | 92 | 90.0 | `by-type/by-struct/LinkedListState.md` |
| `0001V0` | 88 | 92 | 90.0 | `by-type/by-struct/ListNode.md` |
| `0001VY` | 88 | 92 | 90.0 | `by-type/by-struct/ScreenOverlayPaneLayouts.md` |
| `0001X9` | 88 | 92 | 90.0 | `by-type/by-vtable/ClanDialogVtableFamily.md` |
| `0001XA` | 88 | 92 | 90.0 | `by-type/by-vtable/CommandInputPaneVtableFamily.md` |
| `0001XB` | 88 | 92 | 90.0 | `by-type/by-vtable/DATManagerVtables.md` |
| `0001XL` | 88 | 92 | 90.0 | `by-type/by-vtable/FolderTreePaneVtables.md` |
| `00031X` | 88 | 92 | 90.0 | `by-type/by-vtable/SpellMenuDialogVtables.md` |
| `0001XE` | 89 | 93 | 91.0 | `by-type/by-vtable/DIBitmapDirectXVtables.md` |
| `0001XO` | 89 | 93 | 91.0 | `by-type/by-vtable/FrameChromeVtableFamily.md` |
| `0001YU` | 89 | 93 | 91.0 | `by-type/by-vtable/SecuritySingletonVtables.md` |
| `0001WH` | 90 | 92 | 91.0 | `by-type/by-struct/VoteMenuPaneLayout.md` |
| `0001UG` | 90 | 93 | 91.5 | `by-type/by-struct/FileStreamLayouts.md` |
| `0001XV` | 90 | 93 | 91.5 | `by-type/by-vtable/ItemDialogVtableFamily.md` |
| `0001Y2` | 90 | 93 | 91.5 | `by-type/by-vtable/MailDialogVtableFamily.md` |
| `0001Y5` | 90 | 93 | 91.5 | `by-type/by-vtable/MerchantMenuDialogVtableFamily.md` |
| `0001YA` | 90 | 93 | 91.5 | `by-type/by-vtable/NumericRectangleControlPaneVtables.md` |
| `0001Z1` | 90 | 93 | 91.5 | `by-type/by-vtable/VoteMenuPaneVtables.md` |
| `0001WE` | 90 | 94 | 92.0 | `by-type/by-struct/TimerPaneLayout.md` |
| `0001XK` | 90 | 94 | 92.0 | `by-type/by-vtable/FileStreamVtables.md` |
| `0001VL` | 91 | 93 | 92.0 | `by-type/by-struct/PrimeNumberGeneratorLayout.md` |
| `0001YC` | 91 | 93 | 92.0 | `by-type/by-vtable/PaneCoreVtableFamily.md` |
| `0001U5` | 91 | 94 | 92.5 | `by-type/by-struct/DialogSessionLayouts.md` |
| `0001UY` | 91 | 94 | 92.5 | `by-type/by-struct/LineIteratorLayout.md` |
| `0003H9` | 91 | 94 | 92.5 | `by-type/by-struct/ScreenFadeOutLayout.md` |
| `0004N3` | 91 | 94 | 92.5 | `by-type/by-struct/TransferServerDialogPaneLayout.md` |
| `0001WF` | 91 | 94 | 92.5 | `by-type/by-struct/UserStatusPaneSummaryFields.md` |
| `0001WN` | 91 | 94 | 92.5 | `by-type/by-template/AUTOBUF_unsigned_char.md` |
| `00031W` | 91 | 94 | 92.5 | `by-type/by-vtable/MerchantDialogPaneVtables.md` |
