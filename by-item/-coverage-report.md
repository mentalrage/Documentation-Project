*** UID:0000TR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# by-item Coverage Report

## Summary

- Last generated: 2026-05-26
- Folder: `by-item`
- Coverage summary: 64 covered reconstructable rows, 0 covered ignored rows, 1 uncovered inventory placeholder row.
- Confidence summary: baseline report generated from existing documentation pages and `-ignored.md`; ignored rows are driven by the local ignored ledger, while reconstructable row confidence is heuristic until IDA/MCP or manual verification raises it.
- Ordering: alphabetic by item name, except `by-memory`, which is sorted by the first address in the row.

## Covered Items To Replicate

- [UID:0000TT][AddEmployeeItemDialogInlineConstruction_004A339F](by-item/AddEmployeeItemDialogInlineConstruction_004A339F.md) : reconstructable : 82% : strong : Live EmployeeDialogPane inline construction anchor for AddEmployeeItemDialog with allocation, base constructor, vtable stores, owner pointer, and raw-constructor caveat documented.
- [UID:0000TU][AILFileOpenCallback_0057B630](by-item/AILFileOpenCallback_0057B630.md) : reconstructable : 80% : strong : Miles AIL file-open callback with DAT/loose-file selection, DATFile/StdioFile construction, callback family, and SoundManager ownership documented.
- [UID:0000TV][AlphaBlendSpan16_00460500](by-item/AlphaBlendSpan16_00460500.md) : reconstructable : 88% : strong : - Confidence: strong for behavior, exact range, block-helper split, and SoftwareBlend16 ownership.
- [UID:0000TW][AlphaBlendSpan16Blocks_00460B00](by-item/AlphaBlendSpan16Blocks_00460B00.md) : reconstructable : 84% : strong : RGB565 weighted four-pixel block blend helper with exact range, direct AlphaBlendSpan16 caller, and SoftwareBlend16 ownership documented.
- [UID:0000TX][AlphaSurfaceReleaseOwnedPixels_00462260](by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md) : reconstructable : 86% : strong : Vtable release slot that frees owned pixel data at `+0x14` when ownership byte `+0x24` is set and leaves object storage intact.
- [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md) : reconstructable : 76% : strong : Argumented item purchase confirm/quantity/send helpers with function boundaries, behavior, source placement, and retained-path caveats documented.
- [UID:0000TZ][BlendRgb555_004C0710](by-item/BlendRgb555_004C0710.md) : reconstructable : 84% : strong : - Confidence: strong for behavior, exact range, and compatibility render caller group; medium for final original name.
- [UID:0000U0][BlendRgb565Pair_004C60D0](by-item/BlendRgb565Pair_004C60D0.md) : reconstructable : 80% : strong : Packed RGB565 pair weighted blend helper with exact range, render-neighborhood callers, adjacent pixel helper, and SoftwareBlend16 ownership documented.
- [UID:0000U1][BlendRgb565Pixel_004C6050](by-item/BlendRgb565Pixel_004C6050.md) : reconstructable : 86% : strong : RGB565 single-pixel weighted blend helper with exact range, broad render callers, metadata grade, and SoftwareBlend16 ownership documented.
- [UID:0000U2][BuildAboveFrameBorder_00461310](by-item/BuildAboveFrameBorder_00461310.md) : reconstructable : 80% : strong : AboveFrame border factory with exact boundary, startup callers, constructor calls, frame-slot writes, and frame-chrome ownership documented.
- [UID:0000U3][BuildClippedAlphaSurfaceView_00462320](by-item/BuildClippedAlphaSurfaceView_00462320.md) : reconstructable : 84% : strong : Generic alpha-surface clipped-view builder used by StaticObjImageLib; output view offsets and source-surface offsets are IDA-backed.
- [UID:0000U4][BuildEffectArchiveTable_004DE420](by-item/BuildEffectArchiveTable_004DE420.md) : reconstructable : 78% : strong : Effect EPF archive table builder with scan/merge/rebase/sentinel behavior, sole EffectObjImageLib caller, and owner decision documented.
- [UID:0000U5][BuildFramePartPanes_004B7120](by-item/BuildFramePartPanes_004B7120.md) : promoted : -1 : strong : Retained by-item index; canonical reconstructable range documentation is [UID:00022F][0x004b7120-0x004b731f.BuildFramePartPanes](by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md).
- [UID:0000U6][BuildTilecArchiveTable_004DDA60](by-item/BuildTilecArchiveTable_004DDA60.md) : reconstructable : 78% : strong : TILEC EPF archive-table builder with shard scan, metadata merge/rebase/sentinel behavior, one StaticObjImageLib caller, and owner decision documented.
- [UID:0000U7][CheckBoxControlPaneStateTypeHelper_00499EC0](by-item/CheckBoxControlPaneStateTypeHelper_00499EC0.md) : reconstructable : 74% : strong : CheckBoxControlPane vtable-only state/type refresh helper with behavior, vtable ownership, generated omission, and unresolved final method name documented.
- [UID:0000U8][CheckTimerSkewAndSendHeartbeat_466CA0](by-item/CheckTimerSkewAndSendHeartbeat_466CA0.md) : reconstructable : 82% : strong : - Confidence: strong for boundary, behavior, sole Application message-loop caller, heartbeat packet construction, and timer/global dependencies; medium for final source-facing name and placement.
- [UID:0000U9][CreateDIBitmapFromPcxBuffer_004A18B0](by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md) : reconstructable : 82% : strong : PCX-to-DIB helper with decode/allocation/validation/copy/free failure behavior, one LoadPcxImage caller, and ImageLoaders ownership documented.
- [UID:0000UA][CurlWriteCallback_00581B80](by-item/CurlWriteCallback_00581B80.md) : reconstructable : 84% : strong : StartupWindow libcurl write callback with callback setup xrefs, ANSI SSO append behavior, text-only caveat, and ownership decision documented.
- [UID:0000UB][DATAudioResources](by-item/DATAudioResources.md) : reconstructable : 72% : strong : DAT-backed SoundManager sound-effect and zone-music resource selection with naming policy, archive dependency, and unresolved audio payload handoff documented.
- [UID:0000UC][DATEntryRecord](by-item/DATEntryRecord.md) : reconstructable : 76% : strong : DAT mapped entry table record layout with 17-byte stride, next-offset size calculation, sentinel/final-offset interpretation, and on-disk questions documented.
- [UID:0000UD][DecodePcxToRgb565Buffer_00549410](by-item/DecodePcxToRgb565Buffer_00549410.md) : reconstructable : 82% : strong : PCX RLE/palette/remap to RGB565 decoder with allocation outputs, transparent-index handling, single caller, and ImageLoaders ownership documented.
- [UID:0000UE][DeserializePredefinedFormArticleEntries_478650](by-item/DeserializePredefinedFormArticleEntries_478650.md) : reconstructable : 84% : strong : Predefined article form payload parser with input/output model, field parsing, visible-row count behavior, exact boundary, and file-local xrefs documented.
- [UID:0000UF][DestroyDATFileMgr_467380](by-item/DestroyDATFileMgr_467380.md) : reconstructable : 84% : strong : Tiny cleanup helper; deletes `g_pDATFileMgr` through the virtual deleting destructor in paired fatal resource-load cleanup paths.
- [UID:0000UG][DestroyExceptionHandler_4673A0](by-item/DestroyExceptionHandler_4673A0.md) : reconstructable : 84% : strong : Tiny cleanup helper; deletes `g_pCrashTarget` through the virtual deleting destructor in paired fatal resource-load cleanup paths.
- [UID:0000UH][DrawEncodedAlphaFrame_00462F20](by-item/DrawEncodedAlphaFrame_00462F20.md) : reconstructable : 84% : strong : Shared alpha-mask blitter for encoded signed-run frame rows; caller set and blend-mode behavior are IDA-backed, frame-source type remains provisional.
- [UID:0000UI][DrawFrameWithBlendMode_00462E10](by-item/DrawFrameWithBlendMode_00462E10.md) : reconstructable : 82% : strong : Live IDA MCP on 2026-05-30 verified `sub_462E10` as the alpha-mask frame draw helper with exact bounds, two LightObjImageLib callers, clip/intersect setup, and mode dispatch to byte copy/add/subtract row helpers.
- [UID:0000UJ][DrawTextInRect_004BAD70](by-item/DrawTextInRect_004BAD70.md) : reconstructable : 76% : strong : Shared wrapped text renderer with exact memory-page evidence for boundary, 130 callers, callee list, draw-state offsets, bounded line copy, and range-check path; final source owner remains open.
- [UID:0000UK][DrawTextRunCallback_00593DB0](by-item/DrawTextRunCallback_00593DB0.md) : reconstructable : 70% : strong : - Confidence: strong for IDA callback bounds, address-taking xrefs, and text-run rendering behavior.
- [UID:0000UL][EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0](by-item/EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0.md) : reconstructable : 78% : strong : EmployeeDialogPane helper wrapper with live IDA function bounds, dispatcher/parser xrefs, quantity-dialog construction callers, and raw `0x004a3be0` update-record caveat.
- [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md) : reconstructable : 72% : strong : - IDA-confirmed TextEdit serialization helper at `0x0058e490-0x0058e691`; owner remains medium confidence because incoming xref is a raw thunk at `0x00498c4a`.
- [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md) : reconstructable : 72% : strong : - Confidence: strong for IDA-confirmed loader behavior and in-memory stride/sentinel shape, medium for original type names.
- [UID:0000UO][FolderTreePaneOwnerPollution_47f280_58a8e0](by-item/FolderTreePaneOwnerPollution_47f280_58a8e0.md) : routing : 72% : strong : FolderTreePane owner-pollution index with canonical owner map for filesystem tree-control, chat UI, surface/presentation, screenshot, and system-message ranges; not a code-emitting parent.
- [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md) : reconstructable : 78% : strong : - IDA confirms inbound map opcode `0x6a`, global flag `byte_66DEE0`, outbound opcode `0x77`, raw mirror handler, and FriendListDialog save-path sender.
- [UID:0000UQ][GetItemGlyphBounds_004DF460](by-item/GetItemGlyphBounds_004DF460.md) : reconstructable : 82% : strong : - IDA confirms `0x004df460-0x004df4f9`, 48 callers, item-id remap policy, EPF/EPD lookup, and tile-midpoint centering.
- [UID:0000UR][GetSpriteBounds_004DE2A0](by-item/GetSpriteBounds_004DE2A0.md) : reconstructable : 78% : strong : - IDA confirms `0x004de2a0-0x004de3d2`, two effect-object callers, modern/legacy effect atlas lookup, empty-rect fallback, and tile-midpoint centering.
- [UID:0000US][HalfBlendSpan16Blocks_00460C10](by-item/HalfBlendSpan16Blocks_00460C10.md) : reconstructable : 70% : strong : - Confidence: strong for behavior and source ownership.
- [UID:0000UT][HasDATEntry_0049C700](by-item/HasDATEntry_0049C700.md) : reconstructable : 70% : strong : - Confidence: strong
- [UID:0000UU][InitAlphaSurfaceView_004623C0](by-item/InitAlphaSurfaceView_004623C0.md) : promoted : -1 : strong : Retained by-item index; canonical reconstructable range documentation is [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md).
- [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) : reconstructable : 70% : strong : - Confidence: strong for boundary, caller, and high-level behavior.
- [UID:0000UW][LoadDatFileBuffer_004BB120](by-item/LoadDatFileBuffer_004BB120.md) : reconstructable : 70% : strong : - Confidence: strong
- [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md) : reconstructable : 76% : strong : Exact by-memory page documents IDA MCP boundary, caller/callee inventory, broad raw xrefs, projection behavior, table offsets, and the resolved next-record boundary/span relation.
- [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md) : reconstructable : 82% : strong : IDA-backed ImageFrameTable helper index with exact boundary, parent assignment, direct/merge loader behavior, prefix literals, caller grouping, callee family, and final type-name caveats.
- [UID:0000UZ][LoadPcxImage_004A17B0](by-item/LoadPcxImage_004A17B0.md) : reconstructable : 50% : medium : - Confidence: strong for behavior and caller family.
- [UID:0000V0][LoadTileEpfMetadata_004D1B80](by-item/LoadTileEpfMetadata_004D1B80.md) : reconstructable : 70% : strong : - Confidence: strong for behavior and owner.
- [UID:0000V1][PacketBufferHelpers](by-item/PacketBufferHelpers.md) : reconstructable : 70% : strong : - Confidence: strong for helper behavior and broad utility role.
- [UID:0000V2][PacketDigest_00515380](by-item/PacketDigest_00515380.md) : reconstructable : 50% : medium : - Confidence: strong for behavior; medium for final signature.
- [UID:0000V3][PacketTransformHelpers](by-item/PacketTransformHelpers.md) : reconstructable : 50% : medium : - Confidence: strong for behavior, medium for exact original filenames.
- [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md) : reconstructable : 70% : strong : - Confidence: strong for slot numbers and filenames loaded by `PaletteLib::PaletteLib`.
- [UID:0000V5][ParseEntries_004A5E60](by-item/ParseEntries_004A5E60.md) : reconstructable : 70% : strong : - Confidence: strong
- [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md) : reconstructable : 74% : strong : Shared wide-path `_wstat64i32` existence helper now attached to [UID:0000MI][PathUtil](by-file/PathUtil.md) for autogen tracking; final C++ remains blank pending dispatch-pointer/source-split cleanup.
- [UID:0000V7][PhoneBookListHelpers_58cfa0_58dcb0](by-item/PhoneBookListHelpers_58cfa0_58dcb0.md) : reconstructable : 50% : medium : - Confidence: strong for phone-book ownership of `0x0058cfa0`; medium for final name of `0x0058dcb0`.
- [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md) : reconstructable : 50% : medium : - Address range: `0x0049af00-0x0049af11`
- [UID:0000V9][ProfileDialogDestructorAndRefreshHelpers_53fda0_53fe90](by-item/ProfileDialogDestructorAndRefreshHelpers_53fda0_53fe90.md) : reconstructable : 72% : strong : - Confidence: strong for helper behavior, medium for final emitted-source modeling policy.
- [UID:0000VA][ResolveSpritePartPath_004E19D0](by-item/ResolveSpritePartPath_004E19D0.md) : reconstructable : 50% : medium : - Confidence: strong for behavior, medium for final type names.
- [UID:0000VB][ResourceLayoutEntry](by-item/ResourceLayoutEntry.md) : reconstructable : 50% : medium : - Confidence: strong for in-memory field order, medium for original type name.
- [UID:0000VC][ScaleDirectionOffsetToPixels_00505100](by-item/ScaleDirectionOffsetToPixels_00505100.md) : reconstructable : 50% : medium : - Confidence: strong for exact function range and behavior; medium for final source name.
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md) : reconstructable : 70% : strong : - Confidence: strong for the defect pattern and example function boundaries.
- [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md) : reconstructable : 50% : medium : - Entity kind: raw constructor-boundary evidence.
- [UID:0000VF][ScreenshotProofPacket_00558240](by-item/ScreenshotProofPacket_00558240.md) : reconstructable : 70% : strong : Proof helper builds opcode `0x83` from a masked MD5 digest, inserts random pad bytes, and queues 49 bytes; owner remains unproven.
- [UID:0000VG][ServerSelectHelpers_574510_5745b0](by-item/ServerSelectHelpers_574510_5745b0.md) : reconstructable : 50% : medium : - Confidence: strong for server-select ownership, medium for final helper names.
- [UID:0000VH][SpellMenuActionButtonState_51d6c0_51e600](by-item/SpellMenuActionButtonState_51d6c0_51e600.md) : reconstructable : 70% : strong : - Confidence: strong for behavior and spell-menu ownership.
- [UID:0000VI][StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f](by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md) : reconstructable : 76% : strong : StartupWindow raw notice helper boundary-debt tracker backed by the stronger [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) aggregate and exact [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md) child; remaining raw starts still need exact child pages.
- [UID:0000VJ][TransferServerDialogPaneThunks_599220_5993e0](by-item/TransferServerDialogPaneThunks_599220_5993e0.md) : reconstructable : 50% : medium : - Confidence: strong for helper behavior, medium for final modeling policy.
- [UID:0000VK][VectorGrowArchiveIndex_004E5990](by-item/VectorGrowArchiveIndex_004E5990.md) : reconstructable : 70% : strong : - Entity kind: free helper

## Covered Items To Ignore

- None recorded yet.

## Uncovered Items

- by-item inventory baseline : uncovered : 0% : open : Full authoritative inventory for by-item is not yet proven complete; compare this report against Wave3 when OPERATIONAL, simroot_v2, and IDA/MCP evidence.
