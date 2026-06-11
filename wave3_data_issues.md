# NOTICE #
THIS DOCUMENT IS FOR REPORTING ISSUES WITH THE WAVE3.PY DATA. ISSUES WHERE AGENT HAS INCORRECTLY INTERPRETED DATA, ATTACHED CLASSES/STRUCTURES TO WRONG OWNERS, INCORRECTLY NAMED CLASSES, MEMORY MAPPING ISSUES, ETC. IF YOU HAVE ISSUES WITH THE ACTUAL WAVE3.PY PROGRAM (COMMANDS WORKING INCORRECTLY/BUGS/IMPROVEMENTS) PLEASE REPORT THOSE IN E:\NTK\GhidraBridge\source-3\project-documentation\wave3_noticed_problems.md. PLEASE USE FORMATTING SIMILAR TO THAT DOCUMENT FOR REPORTS HERE.

- IF YOU ARE THE AGENT WORKING ON THESE ISSUES (NOT REPORTING THEM) THEN:
1. ALL FIXED ISSUES SHOULD BE MOVED TO `wave3_data_issuues-fixed.md` AND REMOVED FROM THIS DOCUMENT
2. All PARTIALLY FIXED ISSUES, OR ISSUES THAT CANNOT BE FIXED CURRENTLY SHOULD BE MOVED TO `wave3_data_issuues-deferred.md` AND REMOVED FROM THIS DOCUMENT
3. ALL ISSUES REPORTED HERE THAT ARE FOUND TO BE INCORRECT/NOT ACTUAL ISSUES SHOULD BE MOVED TO `wave3_data_issuues-not_an_issue.md` AND REMOVED FROM THIS DOCUMENT


# Wave3 Data Noticed Problems

## Data Issues

### 2026-05-30 - ScrollVolumePane emitted helpers still carry stale TextEditPane signatures

Observed:

- Current `source-3/simroot_v2/ui/controls/class_ScrollVolumePane.cpp` emits helper bodies at `0x00564e30`, `0x005652a0`, and `0x00565360`.
- `class_ScrollVolumePane.cpp.source_map.json` and `class_ScrollVolumePane.meta_wave3` place those addresses in the active `ScrollVolumePane` file/method partition.
- The generated C++ body still gives those helpers stale `TextEditPane::*` signatures: `TextEditPane::TrackScrollButtonF`, `TextEditPane::HandleScrollbarMouseF`, and `TextEditPane::TrackScrollThumbF`.
- Existing documentation records IDA caller/field evidence tying these helpers to `ScrollVolumePane` mouse/focus/value-change behavior, not ordinary `TextEditPane` ownership.

Expected:

- Wave3/simroot should keep the helpers in `ScrollVolumePane` and emit neutral or `ScrollVolumePane::*` names until final source names are settled.
- Do not use the stale `TextEditPane` signatures as ownership evidence when migrating this source.

Impact:

- Updated [ScrollVolumePane class](by-class/ScrollVolumePane.md), [ScrollVolumePane file](by-file/ScrollVolumePane.md), [ScrollVolumePane memory](by-memory/0x00564710-0x005654ec.ScrollVolumePane.md), and the three helper memory pages to distinguish current active emission from stale generated signatures.

Follow-up:

- Recheck with IDA MCP after it is reachable again, then fix Wave3 owner/name data for `0x00564e30`, `0x005652a0`, and `0x00565360`.

### 2026-05-30 - CheckTimerSkewAndSendHeartbeat generated recovered source file is referenced but absent

Observed:

- Existing documentation and current `simroot_v2` metadata reference a recovered owner file named `CheckTimerSkewAndSendHeartbeat_00466CA0.cpp`.
- `rg --files source-3/simroot_v2` found no matching recovered source file for `0x00466ca0`.
- IDA MCP still confirms the underlying function is real project code at `0x00466ca0-0x004670ad`, with a sole direct caller from `Application::RunMessageLoop` at `0x00464d26`.

Expected:

- Wave3/simroot output should either emit the recovered helper source file or stop advertising the missing file as an owner path.
- Documentation should rely on IDA MCP for this helper until the generated output is reconciled.

Impact:

- Updated [CheckTimerSkewAndSendHeartbeat memory](by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md) and [item](by-item/CheckTimerSkewAndSendHeartbeat_466CA0.md) to treat the missing recovered file path as stale lead data rather than evidence.

Follow-up:

- Recheck Wave3/simroot generation for `0x00466ca0` after the data pipeline is refreshed.

### 2026-05-30 - FittingRoomListPane raw slot helper starts are missing current IDA function records

Observed:

- Generated/simroot data documents `FittingRoomListPane` paint/input behavior, but the raw byte review found additional helper starts inside the block that are not current IDA function records.
- IDA MCP function inventory models `0x00420840` and `0x00420b60`, but not raw helper starts at `0x00420950`, `0x00420a10`, `0x00420a90`, `0x00420d50`, or `0x00420db0`.
- Manual disassembly shows valid source-level helper bodies at those starts: slot rectangle generation, special-slot hit testing, slot-origin computation, and scratch-resource cleanup.
- The span `0x004207ce-0x00420840` is generated switch/jump-table data for `FittingRoomListPane::OnInputEvent`, not padding.

Expected:

- Keep the raw helper spans documented as real list-pane behavior while marking the function-boundary mismatch.
- Keep the jump-table span ignored as standalone source but covered as generated binary data owned by the input handler.

Impact:

- Added by-memory pages for `FittingRoomListPaneOnPaint`, `OnKeyScroll`, `OnInputEvent`, input jump tables, `OnScrollStep`, raw slot rectangle helpers, `HitTestSlot`, `ValidateFittingSelectionIndex`, raw slot-layout helpers, and the selection/vector helper island.
- Updated `FittingRoomListPane`, `FittingRoom`, `FittingRoomUiCore`, `by-memory/-coverage-report.md`, and `by-memory/-ignored.md`.

Follow-up:

- Recheck these starts after Wave3/IDA boundary fixes. If the tool gains exact function records, keep the documented ranges and remove only the raw-boundary caveats.

### 2026-05-30 - FittingRoomScrollPane generated helper starts are raw bodies, not current IDA functions

Observed:

- Generated/simroot data identifies fitting-room scrollbar helper starts at `0x0041e780`, `0x0041e7f0`, and `0x0041eb30`.
- IDA MCP `lookup_funcs` reports those addresses as not current function records, and `xrefs_to` reports no direct external references to the raw starts.
- Manual byte/disassembly review shows normal source-level helper bodies: `0x0041e780-0x0041e7f0` hot-part invalidation/state update, `0x0041e7f0-0x0041e8af` active-part/thumb-drag setup, and `0x0041eb30-0x0041eb8c` reset-state/timer-stop cleanup.

Expected:

- Keep these bodies documented as real raw source behavior while marking the IDA function-boundary mismatch.
- Do not treat the surrounding padding as one large unknown gap or merge the bodies into adjacent modeled functions.

Impact:

- Added [FittingRoomScrollPane raw part-state helpers](by-memory/0x0041e780-0x0041e8af.FittingRoomScrollPaneRawPartStateHelpers.md) and [FittingRoomScrollPane reset-state raw helper](by-memory/0x0041eb30-0x0041eb8c.FittingRoomScrollPaneResetScrollStateRaw.md).
- Updated [FittingRoomScrollPane](by-class/FittingRoomScrollPane.md), [FittingRoom](by-file/FittingRoom.md), [FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md), and [by-memory coverage](by-memory/-coverage-report.md).

Follow-up:

- Recheck these starts after Wave3/IDA boundary fixes. If IDA gains function records, keep the same documented ranges and remove the raw-boundary caveat.

### 2026-05-28 - IconsPane raw action dispatcher is not modeled as a normal function

Observed:

- The gap `0x004cf8d5-0x004cf980` between `IconsPane` core and `TabPane` was not all padding.
- IDA MCP shows `0x004cf8d5-0x004cf8df` and `0x004cf975-0x004cf97f` are `0xcc` alignment padding.
- IDA MCP shows `0x004cf8e0-0x004cf975` is function-shaped executable code with an eight-entry jump table at `0x004cf954`.
- IDA has no function object and no direct external xrefs for `0x004cf8e0`, but the body duplicates the `IconsPane::OnMouseEvent` click-action switch at `0x004cf6d8-0x004cf712`, including the `dword_67A764 + 1008` input-lock gate and calls to the same action helpers.

Expected:

- Keep `0x004cf8e0-0x004cf975` documented as real raw code until a source/build explanation proves whether it is live code or an unreferenced duplicate.
- Do not classify the whole `0x004cf8d5-0x004cf980` span as padding.

Impact:

- Added [IconsPane action dispatch raw body](by-memory/0x004cf8e0-0x004cf975.IconsPaneActionDispatchRawBody.md).
- Updated [IconsPane core](by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md), [IconsPane](by-class/IconsPane.md), [IconsPane file](by-file/IconsPane.md), and [by-memory coverage](by-memory/-coverage-report.md).

Follow-up:

- Recheck `0x004cf8e0` after Wave3/IDA boundary fixes. If a caller is found, promote this from raw action-dispatch candidate to the appropriate `IconsPane` helper. If no caller exists, decide whether final source should omit a separate helper while preserving the documented behavior as emitted binary code.
- 2026-05-30 source-map/source follow-up: current `simroot_v2/class_IconsPane.cpp` now emits `Cleanup` at `0x004cf260`, `HitTestIcon` at `0x004cf7d0`, `SetIconHighlight` at `0x004cf870`, and the scalar deleting destructor at `0x004cfda0` with the `flags & 4` no-delete guard. The remaining active issue for this note is the raw `0x004cf8e0` action-dispatch body, plus compiler-generated adjustor thunk handling in the shared destructor tail.

### 2026-05-24 - MapPane weather handler is emitted at a raw start not modeled by IDA

Observed:

- Active `source-3/simroot_v2/class_MapPane.cpp` emits `MapPane::HandleWeatherPacket` at `0x00510400`.
- IDA MCP `lookup_funcs` reports `0x00510400` as `Not a function`.
- 2026-05-24 MCP recheck still reports `0x00510400` as `Not a function`, while neighboring `0x005104d0` is modeled as `sub_5104D0` size `0x488` and `0x0050db50` is modeled as `sub_50DB50` size `0x163`.
- IDA MCP disassembly at `0x00510400` still shows normal function-shaped bytes beginning with `push ebp; mov ebp, esp`, packet byte reads, day/night blend table use, and a return path.
- The same dispatcher family has IDA-confirmed function starts for neighboring handlers such as `0x0050fb00`, `0x005104d0`, `0x00510960`, `0x00511440`, `0x00511db0`, and `0x00512d60`.
- Current `MapPane::HandlePacket` case `0x20` already contains an inline day/night blend body equivalent to the generated `HandleWeatherPacket` logic, while case `0x1f` calls `SetMapState`/`sub_50DB50`; this makes the generated standalone `HandleWeatherPacket` boundary especially suspect until the dispatcher split is reconciled.
- 2026-05-25 IDA MCP recheck confirms `0x00510400` and `0x005104c0` are still not functions; the raw body is `0x00510400-0x005104c7` end-exclusive, has no direct callers/xrefs, and duplicates the dispatcher case `0x20` body at `0x00507e45-0x00507f04`.

Expected:

- Preserve `0x00510400` as a real raw code start or materialize the IDA/Wave3 function boundary before source migration.
- Do not silently merge the generated `HandleWeatherPacket` body into an adjacent handler only because IDA lacks a function object.
- Keep the boundary caveat visible in [MapPane](by-file/MapPane.md), [MapPane packet memory](by-memory/0x0050e4c0-0x00514e1a.MapPanePacketHandlersAndDelete.md), and [MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md).

Impact:

- Added [client map system](by-meta/client_map_system.md) and [MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md) with the `0x00510400` boundary caveat.
- Updated `MapPane` file/class/memory docs so the weather handler is not treated as a fully IDA-confirmed function boundary.
- Added [MapPane day/night packet raw body](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md) so the exact raw range is documented without promoting it to a final method boundary.

Follow-up:

- Recheck generated output and IDA boundaries after Wave3 data fixes for `0x00510400`, `0x005104c0`, `0x005104d0`, `0x0050db50`, and the `MapPane::HandlePacket` dispatch cases `0x1f`/`0x20`.
- 2026-05-25 endpoint correction: `0x005104c6` is the last byte of the `retn 4` instruction, not the end-exclusive raw-body endpoint. Use `0x00510400-0x005104c7` for the raw body and `0x005104d0-0x00510958` for the modeled neighbor.

### 2026-05-24 - Weather layer global-data has unresolved tables and a misleading `g_pWeatherState` alias

Observed:

- Current `source-3/simroot_v2/class_RainingLayerPane.cpp` references unresolved weather global-data symbols for rain coordinate tables and `g_pWeatherState`; the Wave3 indexes report zero memory ranges for those rows.
- After the 2026-05-24 v2 issue-index repair, `issues --refresh --kind global_data_issue` and `inspect global-data g_pWeatherState` report active stored issues for both missing normalized type and missing true owning file. The file-side `class_RainingLayerPane.cpp` evidence remains usage/provenance evidence, not proof of true source ownership.
- IDA decompilation of `0x005c1460` and `0x005c1810` shows concrete rain table starts at `0x006702c8`, `0x00670478`, `0x006704d0`, `0x00670528`, `0x006706d8`, and `0x00670730`.
- IDA decompilation shows generated `g_pWeatherState` is actually `dword_67A764`, the same storage as [g_activeMapPane](by-global/g_activeMapPane.md), with weather drawing checking byte `+0x3f0`.
- Snow table names from Wave2/Wave3 are useful, but IDA shows two descriptor sets and guards at `0x0069bf98`, `0x0069bfe8`, `0x0069bff0`, and `0x0069c040`, plus threshold/pattern data in the exact byte range `0x00670784-0x006707d0`.
- 2026-05-24 IDA/data recheck found `dword_67A764` has high-volume active-map use, with 360 data refs, so final migration should not create a separate weather singleton for the same storage.
- 2026-05-25 follow-up: live `show memory-at 0x0067a764 --include-ignored --include-allowed` resolves the storage to `global-data:dword_67A764`; `show global-data g_activeMapPane --summary` now fails fast as an unknown alias rather than blocking the cache. The remaining data issue is alias/name reconciliation, not a missing memory-range row for `dword_67A764`.

Expected:

- Materialize rain/snow weather static tables as real global-data ranges or otherwise document them as weather-layer source-family data.
- Merge or alias generated `g_pWeatherState` into `g_activeMapPane` instead of creating a separate singleton at the same address.
- Keep render callback pointers `0x0069b3e0`, `0x0069b3e4`, `0x0069b3e8`, and `0x0069b3fc` as shared render dependencies until a broader render/global pass owns them.

Impact:

- Added [WeatherLayerGlobals](by-global/WeatherLayerGlobals.md) and [WeatherLayerDataLayouts](by-type/by-struct/WeatherLayerDataLayouts.md).
- Updated weather layer file/class/memory docs and [g_activeMapPane](by-global/g_activeMapPane.md) so source migration does not duplicate the active map-pane singleton as `g_pWeatherState`.
- Added exact range-centered docs for [rain coordinate tables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md), [snow pattern byte tables](by-memory/0x00670784-0x006707d0.SnowPatternByteTables.md), [snow lookup descriptor storage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md), and [active map-pane singleton storage](by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md).

Follow-up:

- Recheck generated output after Wave3 data fixes for `g_pWeatherState`, `g_minimapRainStreaks`, `g_rainStreakCoords`, `g_snowLookupTables`, `g_snowLookupTablesAlt`, and related weather table globals.
- Decide whether final ownership is `map/WeatherLayerPane.cpp` static data or a small `map/WeatherTables.cpp`/render-effects support file.
- 2026-05-25 IDA MCP range follow-up: table xrefs remain confined to the weather-layer methods, `0x006707d0` starts unrelated string data after the snow byte tables, and `0x0067a764-0x0067a768` remains the single active map-pane pointer storage behind generated `g_pWeatherState`.

### 2026-05-24 - ExceptionHandler active output omits crash helper family and Crasher ordinary destructor

Observed:

- Active `source-3/simroot_v2/class_ExceptionHandler.cpp` emits the constructor and scalar deleting destructor, but does not emit the top-level filter/report helper family at `0x004ab740`, `0x004ab830`, `0x004ab870`, `0x004abd10`, `0x004abfa0`, and `0x004ac230`.
- IDA confirms those helper starts and end-exclusive ranges: [CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md), [TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md), [ExceptionCrashReportWriter](by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md), [ExceptionCodeStringHelper](by-memory/0x004abd10-0x004abe4a.ExceptionCodeStringHelper.md), [ExceptionLogicalAddressHelper](by-memory/0x004abfa0-0x004ac035.ExceptionLogicalAddressHelper.md), and [ImageHlpStackWalkHelper](by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md).
- Active `source-3/simroot_v2/class_Crasher.cpp` emits the constructor, crash trigger, and scalar deleting destructor, but omits the ordinary destructor at `0x0049bb30`.
- IDA confirms [Crasher](by-class/Crasher.md) construction from `Application::Initialize` at `0x004646ec` and confirms [ExceptionHandler](by-class/ExceptionHandler.md) construction from the same method at `0x00463e3a`.

Expected:

- Attach or explicitly account for the full [ExceptionHandler](by-file/ExceptionHandler.md) helper family in active generated output, including `TopLevelExceptionFilter` and the `BCrash.nfo` report writer.
- Materialize `Crasher::~Crasher` at `0x0049bb30` in active output rather than only the scalar deleting destructor at `0x0049bb90`.
- Preserve [g_pCrashTarget](by-global/g_pCrashTarget.md) and [g_pCrasher](by-global/g_pCrasher.md) ownership links so application startup/cleanup does not incorrectly absorb the implementation.

Impact:

- Added/updated [ExceptionHandler](by-file/ExceptionHandler.md), [Crasher](by-file/Crasher.md), [g_pCrashTarget](by-global/g_pCrashTarget.md), [g_pCrasher](by-global/g_pCrasher.md), [client crash diagnostics](by-meta/client_crash_diagnostics.md), aggregate memory docs, and exact helper memory pages for the omitted ExceptionHandler helper family.
- Added [DestroyExceptionHandler](by-item/DestroyExceptionHandler_4673A0.md) and paired [DestroyDATFileMgr](by-item/DestroyDATFileMgr_467380.md) to track the small cleanup helpers used by resource/image load failure paths.

Follow-up:

- Recheck generated output after Wave3 data fixes for `0x004ab740`, `0x004ab830`, `0x004ab870`, `0x004abd10`, `0x004abfa0`, `0x004ac230`, `0x0049bb30`, and ownership of `0x00467380`/`0x004673a0`.

### 2026-05-24 - MiscWorkThread request wrappers are mis-owned as CashShopRequest auth/directory methods

Observed:

- Existing docs and generated ownership treated `0x00528290-0x005283d4` as [CashShopRequest](by-class/CashShopRequest.md) methods named `SendHashRequest`, `SendAuthRequest`, and `SendDirectoryRequest`.
- IDA MCP decompiles `0x00528290` and `0x00528310` as `__thiscall` wrappers that allocate one or two `SimpleUString` payloads and call generic [Thread](by-class/Thread.md) async dispatch helper `0x00596960`.
- IDA xrefs show callers read [g_pMiscWorkThread](by-global/g_pMiscWorkThread.md) before invoking those wrappers.
- Raw aligned disassembly at `0x005283b0` is a real browse-directory submission helper that dispatches message `0x42446972`, but IDA does not currently model it as a function.
- [MiscWorkThread::ProcessWorkItem](by-memory/0x005277c0-0x005285dc.MiscWorkThreadAndNotifications.md) handles the same message ids `0x42446972`, `0x47654874`, and `0x4e434175`.

Expected:

- Re-own `0x00528290`, `0x00528310`, and raw `0x005283b0` under [MiscWorkThread](by-class/MiscWorkThread.md).
- Keep [CashShopRequest](by-class/CashShopRequest.md) focused on cash-shop item/fitting-room/named request and packet-send queue behavior.
- Materialize or explicitly account for the raw `0x005283b0` helper as real code instead of leaving it hidden behind the stale CashShop range.

Impact:

- Added [MiscWorkThread](by-file/MiscWorkThread.md), [MiscWorkThread class](by-class/MiscWorkThread.md), [g_pMiscWorkThread](by-global/g_pMiscWorkThread.md), [g_pMiscWorkThread memory](by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md), notification class docs, and [MiscWorkThread memory](by-memory/0x005277c0-0x005285dc.MiscWorkThreadAndNotifications.md).
- Converted [0x00528290-0x005283d4 CashShopRequestAuthDirectory](by-memory/0x00528290-0x005283d4.CashShopRequestAuthDirectory.md) into a stale ownership correction page.
- Updated [CashShopRequest](by-file/CashShopRequest.md), [Application](by-file/Application.md), [Thread](by-file/Thread.md), [PatchPane](by-file/PatchPane.md), [NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md), [client threading](by-meta/client_threading.md), and [proposed source tree](by-project-structure/proposed-source-tree.md) to use the corrected owner.

Follow-up:

- Recheck generated output after Wave3 data fixes for `0x00528290`, `0x00528310`, `0x005283b0`, `0x00527fe0`, and `g_pMiscWorkThread`.
- Decide whether `app/MiscWorkThread.cpp` or `network/MiscWorkThread.cpp` better matches original source layout after notification handler callers are fully mapped.

### 2026-05-24 - LodePNG library still needs full helper-island mapping

Observed:

- Active `source-3/simroot_v2/class_LodePNGState.cpp` now emits both the ordinary destructor at `0x00448520` and scalar deleting destructor at `0x00448530`.
- `0x00443c80-0x00443d60`, `0x004460f0-0x004461f5`, and `0x004466b0-0x00446fea` are now marked as `library` memory segments for bundled `LodePNG` with version still unknown.
- `0x00448520-0x00448526` and `0x00448530-0x00448556` are now marked as `library` method ranges for bundled `LodePNG`.
- Active `source-3/simroot_v2/recovered/WriteRGBA8PNGFile_00443E40.cpp` still emits the RGBA8 wrapper and declares `WritePNGFileWithFormat_443DB0`, while much of the neighboring LodePNG helper island remains anonymous prewave-only code.
- IDA strings identify the surrounding code as LodePNG: `LodePNG`, `.?AULodePNGState@@`, `.?AVState@lodepng@@`, PNG error strings, and `LodePNGEncoderSettings.filter_strategy`.
- IDA/prewave callers show `0x00443c80` is called by `WritePNGFileWithFormat_443DB0` and by internal LodePNG helpers, so it is not a screenshot-only helper.

Expected:

- Finish mapping the exact full LodePNG helper span around `0x00443c80`, `0x004460f0`, `0x004466b0`, `0x00448520`, `0x00448530`, and neighboring `0x0044xxxx`/`0x0045xxxx` helpers.
- Keep confirmed LodePNG internals classified as bundled third-party library code unless later evidence proves a smaller split.
- Keep `WritePNGFileWithFormat_443DB0` and `WriteRGBA8PNGFile_443E40` as small [ImageWriters](by-file/ImageWriters.md) wrappers over the [LodePNG](by-file/LodePNG.md) backend.
- Do not migrate LodePNG internals into DAT/resource, screenshot capture, or generic render modules.

Impact:

- New [LodePNG](by-file/LodePNG.md), [LodePNGState](by-class/LodePNGState.md), [LodePNG encode front end](by-memory/0x00443c80-0x00443e5d.LodePngEncodeFrontEnd.md), and [LodePNGState destructors](by-memory/0x00448520-0x00448557.LodePNGStateDestructors.md) docs preserve the corrected ownership.
- [ImageWriters](by-file/ImageWriters.md), [ScreenshotCapture](by-file/ScreenshotCapture.md), [DATArchive](by-file/DATArchive.md), and [proposed source tree](by-project-structure/proposed-source-tree.md) now point to the wrapper/library split.
- Added [LodePNG helper island inventory](by-memory/0x00443a60-0x00450c9f.LodePngHelperIslandInventory.md): IDA-modeled inventory now supports a corrected `0x00443a60-0x00450c9f` helper-island candidate, with direct encode-root callgraph reachability through `0x00450b5e` plus local caller evidence for `0x00450b60-0x00450c9f`.

Completed:

- `0x00448520` is active in `class_LodePNGState.cpp` rather than disabled.
- `0x00443c80`, `0x004460f0`, `0x004466b0`, `0x00448520`, and `0x00448530` are explicitly accounted for as bundled LodePNG/library ranges.
- IDA confirms `0x00444740`, `0x00444af0`, `0x00444b20`, `0x00444b70`, and `0x00444bb0` are not modeled as functions, but disassembly shows LodePNG error-string/default/init/free helper code in that raw block.
- 2026-05-25 IDA-only follow-up: the previous `0x00443a60-0x00456031` provisional upper bound was too broad. `0x00450ca0` is already [MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md), `0x00453df0+` is [MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b4.MiniMapRendererAndControls.md), and old-tail helpers have direct callers from UI/metadata/audio/menu code.
- 2026-05-25 IDA/source follow-up: added [LodePNG raw error/settings helpers](by-memory/0x00444740-0x00444be0.LodePngRawErrorAndSettingsHelpers.md). The raw span now has provisional upstream matches for `lodepng_error_text`, decompression/compression settings initialization, `lodepng_color_mode_init`, and palette cleanup while remaining unmodeled by IDA/Wave3 function boundaries.

Follow-up:

- Recheck generated output after additional Wave3 data fixes for `0x00443db0`, `0x00443e40`, and the remaining anonymous helper functions adjacent to the classified spans.
- Continue mapping exact per-function LodePNG names before any final source migration, especially whether the raw [0x00444740-0x00444be0](by-memory/0x00444740-0x00444be0.LodePngRawErrorAndSettingsHelpers.md) helper block should be split into individual Wave3/IDA function starts. Keep `0x00450ca0+` excluded under MiniMap/shared support owners.

### 2026-05-24 - zlib 1.1.4 support is emitted as many standalone recovered globals

Observed:

- Active `source-3/simroot_v2/recovered` contains many separate zlib one-global files, including `Uncompress_00414390.cpp`, `Crc32_00414430.cpp`, `Adler32_00415EE0.cpp`, `ZlibFree_00415ED0.cpp`, and multiple `Inflate*.cpp`/`Deflate*.cpp` files.
- The confirmed `0x004142c0-0x00419e56` zlib island is now marked as a `library` memory segment with `library=zlib` and `version=1.1.4`.
- IDA strings identify the island as zlib 1.1.4: ` deflate 1.1.4 Copyright 1995-2002 Jean-loup Gailly ` and ` inflate 1.1.4 Copyright 1995-2002 Mark Adler `.
- IDA strings also include canonical zlib diagnostics such as `incorrect header check`, `invalid distance code`, and `insufficient memory`.
- IDA caller evidence shows NexusTK resource and metadata code calls public wrappers such as `Uncompress` and `Crc32`, while inflate/deflate internals call each other.

Expected:

- Keep `0x004142c0-0x00419e56` grouped as bundled [Zlib](by-file/Zlib.md) support code.
- Do not migrate `Crc32`, `Adler32`, `InflateFast`, or other inflate/deflate helpers into [DATArchive](by-file/DATArchive.md), `MetaTable`, palette, startup-logo, or image-library source files.
- Treat current one-global recovered files as useful review staging, not a plausible original source layout.

Impact:

- New [Zlib](by-file/Zlib.md) and [zlib core](by-memory/0x004142c0-0x00419e56.ZlibCore.md) docs resolve the old `Crc32`/`Adler32` ownership ambiguity.
- [DATArchive](by-file/DATArchive.md), [MetaTable](by-class/MetaTable.md), [client DAT specifications](by-meta/client_dat_specifications.md), and [proposed source tree](by-project-structure/proposed-source-tree.md) now point to the third-party support-library split.

Completed:

- `0x004142c0-0x00419e56` is explicitly accounted for as bundled zlib 1.1.4 library memory and no longer counts as product source needing reconstruction.
- Added [zlib deflate/tree internals](by-memory/0x00414820-0x00417b97.ZlibDeflateAndTrees.md): IDA MCP now maps the anonymous `0x00414820-0x004158aa` range as zlib `deflate.c` workers and `0x00416010-0x00417b97` as deflate `trees.c`-style Huffman/bit-output helpers.
- Corrected the source-structure note that `0x00416010-0x00417b97` is not inflate internals; it is reached from deflate reset/flush paths and should be grouped with `deflate.c`/`trees.c` under bundled zlib.

Follow-up:

- Recheck generated output after additional Wave3 data fixes for the zlib family, especially whether the one-global files gain a shared source-bundle owner.
- Keep exact static helper names provisional until a side-by-side stock zlib 1.1.4 source comparison is performed.

### 2026-05-24 - MD5 helper island is only partially modeled and packet digest ownership is misleading

Observed:

- `source-3/simroot_v2/class_Socket.cpp` names the `0x00515380` call as `ComputePacketDigest`, but there is no dedicated generated MD5 source file.
- IDA MCP confirms `0x00515380` is part of a larger MD5 helper island at `0x005151f0-0x00515f48`, with string, byte-buffer, file-path, stream, update, final, and transform helpers.
- IDA currently does not materialize function objects for raw helper starts at `0x00515310` and `0x00515450`, even though disassembly shows complete MD5 wrapper bodies there. A 2026-05-25 xref check found no direct code/data refs to either start, so their liveness remains provisional.
- `simroot_v2/recovered/SendScreenshotProofPacket_00558240.cpp` still calls the stream helper as raw `sub_515570`, while `StartupWindow` callers use the string helper at `0x00515290`.
- `RegistryConfig::LoadFromRegistry` calls the caller-output digest wrapper `0x005153e0` at `0x004928ba`; current `class_RegistryConfig.cpp` still omits the containing load body.
- The packet raw digest wrapper decompiles as returning a pointer to transient digest storage, so the final safe C++ signature needs manual review instead of direct trust in generated output.

Expected:

- Materialize or explicitly account for the raw MD5 helper starts at `0x00515310` and `0x00515450`, including their current no-xref status.
- Emit the MD5 family as one shared utility module, not as packet-transform-owned code.
- Normalize names for `0x005151f0`, `0x00515290`, `0x00515380`, `0x005153e0`, `0x00515570`, `0x00515690`, `0x00515750`, and `0x00515840`.
- Keep adjacent default-codepage wrappers at `0x005151b0` and `0x005151d0` out of the MD5 ownership group.

Impact:

- New [MD5](by-file/MD5.md), [MD5 hash helpers](by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md), [Md5BytesHex](by-memory/0x00515310-0x00515375.Md5BytesHex.md), [Md5FilePathHex](by-memory/0x00515450-0x00515568.Md5FilePathHex.md), and [Packet digest helper](by-item/PacketDigest_00515380.md) docs preserve the safe ownership and boundary caveats.
- Do not migrate `ComputePacketDigest` into [PacketTransform](by-file/PacketTransform.md); use it as a dependency from the shared MD5 utility.
- Keep the `RegistryConfig::LoadFromRegistry` call to `0x005153e0` as a config-to-MD5 dependency.

Follow-up:

- Recheck generated output after Wave3 data fixes for `0x005151f0`, `0x00515290`, `0x00515310`, `0x00515380`, `0x005153e0`, `0x00515450`, `0x00515570`, `0x00515690`, `0x00515750`, and `0x00515840`.

### 2026-05-24 - Packet transform generated output has helper/signature inconsistencies

Observed:

- `source-3/simroot_v2/recovered/XorTransformBuffer_00578E00.cpp` emits `XorTransformBuffer` returning `std::uint8_t`, and IDA decompiles the function as returning a byte-like value.
- `source-3/simroot_v2/class_Socket.cpp` declares the same helper as `extern void XorTransformBuffer(...)` in the `TransformFramePayload` section.
- The recovered helper signature uses `std::uint32_t*` source/destination and `int keyPtr`, but the cleaned Socket call sites are byte-oriented and sometimes pass `const std::uint8_t*` / `std::uint8_t*` / table pointers without consistent casts.
- Wave3 emits `InitializePacketNonce`, `BuildHandshakeBlock`, and `XorTransformBuffer` as separate recovered globals, while `class_Socket.cpp` also emits transform-table globals near the Socket class. This is structurally useful, but source ownership should be treated as provisional.
- Current `simroot_v2` recheck still shows the issue: `class_Socket.cpp` declares `extern void XorTransformBuffer(std::uint32_t* ... int keyPtr ...)`, `recovered/XorTransformBuffer_00578E00.cpp` defines a `std::uint8_t` return, and `Socket::BuildEncryptedPacket` passes byte pointers without matching that extern prototype.
- IDA MCP decompiles `0x00578e00` as a byte-returning helper that treats source, destination, and key as integer addresses, which supports a source-facing byte-buffer prototype rather than the current mixed generated declarations.
- A 2026-05-25 IDA disassembly pass pins the transform globals but shows more generated declaration drift: `g_packetTransformLut` is emitted as a byte array even though command `13` writes 256 dwords at `0x0066fe58`, and `XorTransformBuffer` reads dword key words from the supplied key pointer.
- 2026-05-25 current-state follow-up without running `wave3.py`: `class_Socket.cpp` still emits `WAVE3 OMITTED METHOD BODY` marker comments before `TransformFramePayload` and `BuildEncryptedPacket`, but generated bodies follow both markers. IDA confirms [TransformFramePayload](by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md) as `0x00578b20-0x00578c40` and [BuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md) as `0x00578c40-0x00578df1`.
- 2026-05-26 IDA recheck again confirms the transform globals are address-backed protocol state: `0x0066fe50` initializes to size `9`, `0x0066fe58` is dword-indexed in the socket command handler, `0x0069ba58` is Socket lifetime key/process storage, `0x0069ba5c` is handshake stride, `0x0069ba60` is the packet sequence byte, and `0x0069ba64` / `0x0069ba94` are primary/alternate transform tables.

Expected:

- Use one consistent helper prototype for all generated call sites, probably byte-buffer oriented with a byte return that callers may ignore.
- Keep `InitializePacketNonce`, `BuildHandshakeBlock`, and `XorTransformBuffer` grouped as packet transform support rather than scalar [PacketBuffer](by-file/PacketBuffer.md) helpers.
- Make the generated global declarations for transform tables/counters consistent between `class_Socket.cpp` and the recovered helper files.
- Emit or normalize global state with address-backed declarations: alternate size `0x0066fe50`, dword LUT `0x0066fe58`, handshake seed `0x0069ba40`, nonce scratch `0x0069ba4c`, process/key pointer `0x0069ba58`, stride `0x0069ba5c`, packet sequence byte `0x0069ba60`, primary table `0x0069ba64`, and alternate table `0x0069ba94`.

Impact:

- New [PacketTransform](by-file/PacketTransform.md), [Packet transform helpers](by-item/PacketTransformHelpers.md), [Packet transform globals](by-global/PacketTransformGlobals.md), [BuildHandshakeBlock](by-memory/0x00577030-0x0057713d.BuildHandshakeBlock.md), and [XorTransformBuffer](by-memory/0x00578e00-0x00578e94.XorTransformBuffer.md) docs preserve the safe ownership and signature/global declaration caveats.
- Added exact Socket sequencing pages for [TransformFramePayload](by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md) and [BuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md), including callers, callees, digest dependency, nonce handling, and generated marker/prototype caveats.
- Do not migrate the current generated Socket transform call sites verbatim without normalizing helper prototypes and pointer types.

Follow-up:

- Recheck generated output after Wave3 data fixes for `0x00575cb0`, `0x00577030`, `0x00578b20`, `0x00578c40`, and `0x00578e00`.
- Normalize `XorTransformBuffer` declarations across recovered global files and `class_Socket.cpp` before compiling or migrating the packet transform module.

### 2026-05-24 - Item menu item list output mixes real list code with shared/polluted helpers

Observed:

- Active `source-3/simroot_v2/class_ServerItemMenuItemList.cpp` contains useful server item-menu list virtuals, but it also owns article/mail pagination helpers at `0x00474da0` and `0x0047ac30`, selected-entry helpers at `0x004aec80`, and shared list-count helper `0x004f3bd0`. IDA caller fanout shows these are not private item-menu list methods.
- IDA reports no function object at `0x0051ae90`, but raw disassembly confirms an out-of-line `ServerItemMenuItemList` constructor through `0x0051aefb`.
- Active `ServerItemMenuItemList::HandleMenuEvent` at `0x0051b2c0` is structurally corrupted in emitted source: the file begins an event struct and then flows into the `DrawListEntry` install marker instead of the real handler body.
- Active `class_ServerItemMenuItemList.cpp` omits raw helper bodies at `0x0051af00`, `0x0051af40`, `0x0051afd0`, and `0x0051b190`.
- Disabled `class_ServerItemMenuItemList.cpp` lists `0x00520b13` as missing code, but IDA confirms it is a real `0xb` adjustor thunk forwarding to `0x00520ce0` with `this - 0xa0`.
- Active `source-3/simroot_v2/class_ClientItemMenuItemList.cpp` omits raw helper bodies at `0x0051c4e0`, `0x0051c550`, and `0x0051c610`.
- Disabled `class_ClientItemMenuItemList.cpp` lists `0x00520ad1` as missing code, but IDA confirms it is a real `0xb` adjustor thunk forwarding to `0x00520c20` with `this - 0xa0`.
- Active `class_ClientItemMenuItemList.cpp` treats `0x004f3b60` and `0x00520c20` as client-item-list destructors, but IDA xrefs show broad shared `ListPane` cleanup and vtable refs from `ClientItemMenuItemList`, `ServerSpellMenuItemList`, and `ClientSpellMenuItemList`.

Expected:

- Keep the item-menu-specific list code with [ItemMenuDialogs](by-file/ItemMenuDialogs.md), but re-own article/mail paging and shared `ListPane` helpers away from `ServerItemMenuItemList`.
- Preserve raw helper ranges `0x0051ae90-0x0051b0f8`, `0x0051b190-0x0051b2a8`, `0x0051c4e0-0x0051c6ac`, and materialize or explicitly account for their function-boundary gaps.
- Emit the real `0x0051b2c0` event-handler body instead of the malformed active output.
- Materialize `0x00520b13` and `0x00520ad1` as confirmed adjustor thunks.
- Treat `0x004f3b60`/`0x00520c20` as shared list-pane destructor glue unless stronger class-specific evidence appears.

Impact:

- New [ItemMenuDialogs](by-file/ItemMenuDialogs.md), [ServerItemMenuItemList](by-class/ServerItemMenuItemList.md), [ClientItemMenuItemList](by-class/ClientItemMenuItemList.md), and exact memory docs preserve the safe source ownership and caveats.
- Do not migrate current `class_ServerItemMenuItemList.cpp` or `class_ClientItemMenuItemList.cpp` verbatim into final source without separating shared/polluted helpers and restoring omitted raw list helpers.

Follow-up:

- Recheck generated output after Wave3 data fixes for `0x00474da0`, `0x0047ac30`, `0x004aec80`, `0x004f3bd0`, `0x0051ae90`, `0x0051af00`, `0x0051af40`, `0x0051afd0`, `0x0051b190`, `0x0051b2c0`, `0x0051c4e0`, `0x0051c550`, `0x0051c610`, `0x00520ad1`, `0x00520b13`, and shared destructor ownership around `0x004f3b60`/`0x00520c20`.

### 2026-05-24 - MerchantDialogPane output omits shared vtable virtual and has raw constructor boundary

Observed:

- Active `source-3/simroot_v2/class_MerchantDialogPane.cpp` emits constructor-shaped code at `0x00517d30`, but IDA reports that address as not currently modeled as a function. Raw disassembly confirms a coherent constructor ending at `0x00517d71`.
- Active output omits the real shared virtual at `0x00517d80-0x00517ebf`. IDA models it as `sub_517D80` and shows vtable data refs from `MerchantDialogPane`, `TextMenuDialog`, `TextInputMenuDialog`, `ServerItemMenuDialog`, `ClientItemMenuDialog`, `ServerSpellMenuDialog`, `ClientSpellMenuDialog`, and `ArgumentedMenuMenuDialog`.
- 2026-05-24 current `simroot_v2` recheck still shows only the constructor in `class_MerchantDialogPane.cpp`; IDA MCP still reports `0x00517d30` as "Not a function", `0x00517d80-0x00517ebf` as `sub_517D80`, and `0x00517ec0` as the next modeled function.
- 2026-05-25 IDA/simroot recheck without running `wave3.py`: `class_MerchantDialogPane.cpp` still omits the virtual; `lookup_funcs` reports `0x00517d80` as `sub_517D80` size `0x13f`, `callers` reports no direct code callers, and `xrefs_to` reports only the expected merchant/text/item/spell/argumented menu vtable slots.

Expected:

- Keep `0x00517d30` as a boundary caveat until IDA/function metadata is reconciled.
- Attach or explicitly account for the shared `MerchantDialogPane` virtual at `0x00517d80`, rather than migrating it under whichever derived menu class references it first.

Impact:

- New [MerchantDialogPane](by-file/MerchantDialogPane.md), class docs, and exact memory docs use IDA-confirmed vtable evidence and preserve the raw-constructor caveat. The focused [MerchantDialogPane action-string virtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md) page now records the exact omitted body.
- Text, item, spell, and argumented menu docs should treat `0x00517d80` as shared base code.

Follow-up:

- Recheck generated output after Wave3 data fixes for `0x00517d30` function-boundary handling and `0x00517d80` ownership/materialization.

### 2026-05-24 - TextDialog/Nexonclub dialog cluster has shared helper ownership and omitted registration helpers

Observed:

- `source-3/simroot_v2/class_TextDialog.cpp` owns previous/next/current dialog packet helpers at `0x0054cc30`, `0x0054ccd0`, and `0x0054cd70`, but IDA caller evidence crosses `MessageDialog`, `MessageDialogLarger`, `MenuQuestionDialog`, `MenuQuestionDialogLarger`, and `TextDialog`.
- The helpers are shared opcode `0x3a` dialog-navigation packet senders, not private `TextDialog` methods.
- `source-3/simroot_v2/class_NexonclubRegistrationDialog.cpp` emits constructor/destructor/command/status/scalar-deleting methods, but IDA confirms additional real registration-dialog helper functions at `0x00530020`, `0x00530230`, `0x005304c0`, and `0x005304f0`.
- `0x00530230` handles registration response/status flow, `0x005304c0` reads the account text field, and `0x005304f0` creates localized result/status alerts. These helpers are part of the registration dialog flow even when current generated metadata attaches or aliases them elsewhere.
- Disabled generated output lists `0x00530565` as missing code, but IDA confirms a real thunk start in the registration destructor/thunk island.
- `source-3/simroot_v2/class_NexonclubProxyDialog.cpp.disabled` labels the small `0x005539ce` thunk through an unrelated dialog/base path; treat that as owner/base-label pollution until inheritance is reconciled.
- 2026-05-24 IDA MCP recheck still confirms the navigation-helper caller split, the four omitted registration helpers, the real `0x00530565` thunk, and the `0x005539ce` adjustor thunk.
- 2026-05-25 IDA/simroot recheck without running `wave3.py`: active `class_NexonclubRegistrationDialog.cpp` still omits `0x00530020`, `0x00530230`, `0x005304c0`, and `0x005304f0`; `lookup_funcs` confirms real function sizes `0x32`, `0x1bf`, `0x21`, and `0x75`; disabled output still says missing code for `0x00530565`, while IDA disassembly shows `this -= 0xa0` then `jmp 0x00530580`.

Expected:

- Represent `0x0054cc30-0x0054ce0e` as shared dialog packet helper infrastructure, even if staged under [TextDialog](by-file/TextDialog.md).
- Attach or explicitly account for `0x00530020`, `0x00530230`, `0x005304c0`, and `0x005304f0` under [NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md).
- Materialize or mark `0x00530565` as confirmed compiler thunk support instead of missing code.
- Keep the proxy thunk at `0x005539ce` as compiler glue with neutral base-owner labeling.

Impact:

- New [TextDialog](by-file/TextDialog.md), [TextDialog class](by-class/TextDialog.md), [TextDialog core](by-memory/0x00552110-0x00553608.TextDialogCore.md), and [DialogNavigationPacketHelpers](by-memory/0x0054cc30-0x0054ce0e.DialogNavigationPacketHelpers.md) docs preserve the shared-helper caveat.
- New [NexonclubProxyDialog](by-file/NexonclubProxyDialog.md), [NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md), and exact memory docs preserve the registration helper omissions and ownership decisions. The focused [NexonclubRegistrationDialog support helpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md) page records the omitted helper bodies and confirmed `0x00530565` thunk.
- Do not migrate active `class_TextDialog.cpp`, `class_NexonclubProxyDialog.cpp`, or `class_NexonclubRegistrationDialog.cpp` directly without reviewing these helper ownership/data issues.

Follow-up:

- Recheck generated output after Wave3 data fixes for `0x0054cc30`, `0x0054ccd0`, `0x0054cd70`, `0x00530020`, `0x00530230`, `0x005304c0`, `0x005304f0`, `0x00530565`, and `0x005539ce`.
- Decide whether the final original source kept the shared dialog-navigation helpers in `TextDialog.cpp`, `MessageDialogs.cpp`, or a local helper section common to both.

### 2026-05-24 - HeadSelectDialog output owns a shared category helper and has disabled thunk gaps

Observed:

- `source-3/simroot_v2/class_HeadSelectDialog.cpp` owns `SwitchCategory` at `0x0049dd00`, but IDA caller evidence crosses `HeadSelectDialog`, fitting-room setup at `0x0041cdc0`, and another dialog rebuild path at `0x0046e2a0`.
- The helper only forwards a category id through a control-list vtable with `refreshSelection = 1`; it does not inspect head-selection state.
- IDA confirms disabled thunk starts at `0x005538fe` and `0x00553909`, but `class_HeadSelectDialog.cpp.disabled` reports missing code for `0x00553909`.
- 2026-05-25 IDA/simroot recheck without running `wave3.py`: `0x0049dd00` is still generated as `HeadSelectDialog::SwitchCategory`; IDA reports `sub_49DD00` size `0x17` with callers at `0x0041ce03`, `0x0046e2dc`, `0x0046e2e5`, and `0x00551394`. Disabled output still says missing code for `0x00553909`, while IDA reports it as a real `0xb` byte thunk that subtracts `0xa4` and jumps to `0x00553920`.

Expected:

- `0x0049dd00` should be re-owned or at least documented as shared dialog/control-list infrastructure before source migration.
- Disabled thunk code should be emitted or explicitly marked as intentionally omitted compiler glue.

Impact:

- New [HeadSelectDialog](by-file/HeadSelectDialog.md), [HeadSelectDialog class](by-class/HeadSelectDialog.md), [HeadSelectDialog memory](by-memory/0x00551030-0x005520e4.HeadSelectDialogCore.md), [DialogCategorySwitch](by-memory/0x0049dd00-0x0049dd17.DialogCategorySwitch.md), and [HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md) docs keep the shared helper and thunk caveats visible.
- Do not migrate `0x0049dd00` as a private `HeadSelectDialog` method based only on current generated ownership.

Follow-up:

- Reconcile the `0x0049dd00` owner against `DialogPane`, control-list classes, fitting-room callers, and `HeadSelectDialog::PopulateHeadButtons`.
- Recheck `0x00553909` after Wave3 data fixes.

### 2026-05-24 - Picture and scrolled-picture pane generated output has owner/name pollution

Observed:

- `source-3/simroot_v2/class_PictureViewPane.cpp` labels the close path as `BulletinSession::MarkForDeletion`, but IDA shows the handlers at `0x00549b00` and `0x00549b30` only test message bytes and call a broad owner deletion helper after a `this - 0xa0` adjustment.
- The `PictureViewPane` bodies do not inspect article, board, or bulletin-session state, and `PhotoPane::~PhotoPane` chains through `PictureViewPane`, so bulletin ownership should not be inferred from the generated helper name alone.
- `source-3/simroot_v2/class_ScrolledPictureControlPane.cpp` includes generated owner/base names such as `HeadSelectDialog`, `FittingRoomDialog`, `FittingRoomListPane`, and `TextButtonExControlPane::~Pane` inside a generic EPF picture-scroller control.
- IDA confirms the `ScrolledPictureControlPane` constructor/timer/paint/destructor functions at `0x004ff7d0`, `0x004ff970`, `0x004ff9e0`, `0x004ffa60`, and `0x00502ab0`, but current caller checks did not find a direct constructor caller.
- Older report text mentions a `DrawPictureObjectPane` caller for `LoadFrameDrawRecord_004D1600`; current IDA/simroot evidence resolves the referenced `0x0055b5d0` path to `WaterFilterEffecter::UpdateCausticEffect`, not a materialized picture-object pane.
- 2026-05-24 IDA MCP recheck: `0x00549b00` and `0x00549b30` still decompile to message-byte tests plus `sub_544690(this - 160)`; `0x004ff7d0` still has no direct constructor callers; and `0x0055b5d0` still behaves as a 60 ms / 32-frame caustic update path using `LoadFrameDrawRecord_004D1600`.
- 2026-05-25 IDA MCP recheck: `0x00549b00` is size `0x22`, `0x00549b30` is size `0x1d`, and the generated `BulletinSession::MarkForDeletion` name is still unsupported by the handler bodies. The adjacent `0x00549b4d` and `0x00549b58` starts are adjustor thunks that subtract `0xa0`/`0xa4` and jump to the scalar deleting destructor.
- 2026-05-25 IDA MCP recheck: `0x00502550` and `0x0050255b` are `ScrolledPictureControlPane` destructor adjustor thunks to `0x00502ab0`. `0x00502ab0` resets scroller vtables, destroys the owned image block, tears down the base pane/control state, and conditionally deletes storage.
- 2026-05-25 IDA MCP recheck: the `ScrolledPictureControlPane` constructor/timer/paint bodies remain generic frame-table, palette, timer, and render-callback code. `0x004ffa60` calls `sub_4B9660`, `dword_69B3FC`, and `dword_69B3E8`; it does not support the generated `FittingRoomListPane::SetTextColor` owner label.
- 2026-05-25 IDA MCP recheck: `0x0055b5d0-0x0055b698` remains `WaterFilterEffecter::UpdateCausticEffect`. It advances the caustic frame, calls `LoadFrameDrawRecord_004D1600`, and renders through the shared tiled-background helper; do not create `DrawPictureObjectPane` docs from that stale report row.

Expected:

- `PictureViewPane` close handlers should use neutral owner-close/delete naming until the `this - 0xa0` owner type is proven.
- `ScrolledPictureControlPane` should remain a reusable `ui/controls` picture scroller unless a real construction path ties it to a feature module.
- Generated base/destructor labels should be neutralized before source migration.

Impact:

- New [PhotoPane](by-file/PhotoPane.md), [PictureViewPane](by-class/PictureViewPane.md), [ScrolledPictureControlPane](by-file/ScrolledPictureControlPane.md), [Photo/Picture memory](by-memory/0x00549620-0x00549bc4.PhotoAndPicturePanes.md), and [ScrolledPicture memory](by-memory/0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore.md) docs use IDA behavior as the ownership anchor.
- 2026-05-25 follow-up docs add exact pages for [PictureViewPane close handlers and thunks](by-memory/0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks.md), [ScrolledPictureControlPane destructor thunks](by-memory/0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks.md), [ScrolledPictureControlPane scalar deleting destructor](by-memory/0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor.md), and [WaterFilterEffecter::UpdateCausticEffect](by-memory/0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect.md).
- Do not migrate these generated files verbatim without correcting the polluted owner/base names and resolving the scrolled-picture constructor path.

Follow-up:

- Resolve the exact type/name of the owner deletion helper reached by `PictureViewPane` through `this - 0xa0`.
- Search for construction/factory/config paths that instantiate `ScrolledPictureControlPane::ScrolledPictureControlPane` at `0x004ff7d0`.
- Reconcile field offsets in `ScrolledPictureControlPane::OnTimerEvent` before committing final structure layout names.
- Do not create `DrawPictureObjectPane` docs from the stale `0x0055b5d0` report row unless a separate current function/class is found.

### 2026-05-24 - LanguageMan/LanguageManager source split and range metadata are inconsistent

Observed:

- `source-3/simroot_v2/class_LanguageMan.cpp` emits a full `str.res` loader body. The constructor range now covers the imported wrapper range `0x004f0010-0x004f004b` plus the manually verified loader segment `0x004f0050-0x004f028a`.
- IDA MCP confirms the actual constructor function as `0x004f0010-0x004f028c`.
- `source-3/simroot_v2/class_LanguageManager.cpp` emits `GetLocalizedString` at `0x004f0350` as a separate class, but the method reads the layout initialized by `LanguageMan`: string table at `+0x4` and count at `+0x8`, with callers passing `g_pLanguageMan`.
- Active output omits real adjacent helpers: non-deleting cleanup body `0x004f0290`, string-copy lookup helper `0x004f0380`, and singleton clear helper `0x004f03c0`.
- IDA names `0x004f0290` as a Boost exception destructor even though behavior is `LanguageMan` table cleanup and singleton clearing.
- IDA confirms `0x004f0310` as a real no-xref zero-initializer in the same neighborhood; current evidence does not prove it belongs to localization.
- 2026-05-24 recheck: active `class_LanguageMan.cpp` still emits only constructor/deleting destructor, and active `class_LanguageManager.cpp` still emits the lookup as a separate class.
- 2026-05-24 IDA recheck still shows `0x004f0350` with broad callers, `0x004f0380` called from `0x00530b40` and `0x005c07b0`, `0x004f0310` with no direct callers, and `0x004f03c0` referenced from the constructor cleanup path.
- 2026-05-26 recheck: current `simroot_v2` still emits only `LanguageMan` constructor/deleting destructor and separate `LanguageManager::GetLocalizedString`. IDA MCP still reports `0x004f0290` as a polluted Boost destructor name even though it frees the LanguageMan string table and clears `dword_67A750`.
- 2026-05-26 recheck: IDA MCP reconfirms `0x004f0380` as a string-copy lookup helper with callers at `0x00530b40` and `0x005c07b0`, `0x004f03c0` as a singleton-clear helper referenced from constructor cleanup metadata, and `0x004f0310` as an unreferenced zero-initializer that should remain unresolved.
- 2026-05-26 IDA `py_eval` recheck found 351 xrefs to `0x004f0350`, 192 xrefs to `g_pLanguageMan` at `0x0067a750`, and RTTI/name evidence for `LanguageMan` / `Singleton<LanguageMan>` but not `LanguageManager`.

Expected:

- `LanguageManager` should be folded into `LanguageMan` or explicitly modeled as an alias/view over `g_pLanguageMan`.
- `0x004f0290`, `0x004f0380`, and `0x004f03c0` should be emitted, attached, or explicitly documented as omitted support helpers.
- `0x004f0310` should be assigned or excluded only after xref/raw-code review, not by locality alone.
- Stored method names should be sanitized before source migration.

Impact:

- New [LanguageMan](by-file/LanguageMan.md), [LanguageMan class](by-class/LanguageMan.md), [LanguageManager alias](by-class/LanguageManager.md), [LanguageMan memory](by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md), [g_pLanguageMan](by-global/g_pLanguageMan.md), and [str.res resource](by-resource/str-res-localized-strings.md) docs use IDA-confirmed boundaries and treat the generated two-class split as provisional.
- 2026-05-26 follow-up docs add exact pages for [LanguageMan cleanup destructor](by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md), [localization-adjacent zero initializer](by-memory/0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer.md), [LanguageMan lookup and singleton helpers](by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md), [LanguageMan scalar deleting destructor](by-memory/0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor.md), and [g_pLanguageMan memory](by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md).
- 2026-05-26 follow-up moves `LanguageManager` to [by-class ignored](by-class/-ignored.md) as a generated alias while keeping the lookup helper reconstructable under [LanguageMan](by-class/LanguageMan.md).

Completed:

- The emitted `LanguageMan::LanguageMan` body now has memory coverage for its resource-loading segment. `show memory-at 0x004f0200 --include-ignored --include-allowed` resolves to method `0x004f0010` and class aggregate `LanguageMan`, and `inspect source-map class_LanguageMan.cpp --summary` reports zero missing memory-range lines.

Follow-up:

- Recheck Wave3 output after fixes for `0x004f0010`, `0x004f0290`, `0x004f0350`, `0x004f0380`, `0x004f03c0`, and `0x004f03d0`; as of 2026-05-26, the generated split/omissions remain active in `simroot_v2`.
- Decide whether final canonical class name should be `LanguageMan` or `LanguageManager` before applying file-ownership migrations.

### 2026-05-24 - Security and input generated output omits real helpers and has base/name pollution

Observed:

- Active `source-3/simroot_v2/class_VirusChecker.cpp` emits only the constructor/destructor wrappers, but IDA confirms a larger scanner/helper island at `0x005c0460-0x005c0fe1`, including AhnLab V3 DLL loading at `0x005c05a0`, process/module scanning at `0x005c07b0`, tree insertion helpers, and recursive node cleanup at `0x005c0fa0`.
- 2026-05-24 `simroot_v2` recheck still shows the same active-output gap: `class_VirusChecker.cpp` has lifecycle methods only, with recursive cleanup emitted separately under `recovered/DestroyVirusCheckerProcessTreeNodes_005C0FA0.cpp` and no active class coverage for `0x005c05a0-0x005c0ea6`.
- Current IDA xrefs do not prove live construction or activation of `VirusChecker`; no direct caller was found for the constructor or scanner load/scan helpers during this pass.
- `source-3/simroot_v2/class_KeySpeedMgr.cpp.disabled` contains real `RestoreSystemKeyboardSettings` code at `0x004eff30` with direct cleanup/deactivation/exception/WinMain xrefs, but active output omits that restore method. Active output also omits the non-deleting destructor at `0x004efee0` and the file-local fast-repeat helper at `0x004effa0`.
- `class_KeySpeedMgr.meta_wave3` reports `vtable_count: 0`, but IDA confirms an RTTI-backed vtable at `0x0061c9c8`; see [KeySpeedMgr vtable](by-type/by-vtable/KeySpeedMgrVtable.md).
- `source-3/simroot_v2/class_CheatDetector.cpp.disabled` contains a real vtable method at `0x00483fe0` that returns true. Active output omits the singleton clear helper at `0x00483ff0`.
- `CheatDetector` destructor output labels base teardown as `EventDispatcher`, while constructor behavior and vtable locality point to a compact timer-handler style singleton; treat the generated base owner as polluted until inheritance is resolved.
- 2026-05-26 IDA vtable recheck: `class_CheatDetector.meta_wave3` and `class_VirusChecker.meta_wave3` both report `vtable_count: 0`, but IDA confirms RTTI-backed object vptrs at `0x00615564` and `0x006310e0`. `VirusChecker` active output also names object offset `+0x08` as `m_state`, while IDA tree insertion/destruction evidence shows it behaves as the path-tree node count.
- 2026-05-26 recheck using `simroot_v2` and IDA MCP only: the issue remains active. IDA confirms exact helper pages for [VirusChecker V3 load/scan](by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md), [VirusChecker tree helpers](by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md), [KeySpeedMgr restore](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md), [KeySpeedMgr fast-repeat apply](by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md), and [CheatDetector virtual/clear/destructor helpers](by-memory/0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor.md).

Expected:

- `VirusChecker` generated output should attach or explicitly exclude the scanner/load/tree helper island instead of showing only lifecycle wrappers.
- `KeySpeedMgr` generated output should expose the restore method and tiny adjacent helpers or mark them as intentionally omitted support functions.
- `CheatDetector` output should include the true-return virtual slot and singleton clear helper, with neutral base teardown naming until the actual base type is proven.
- Generated vtable inventory should record `CheatDetector` vptr `0x00615564`, `VirusChecker` vptr `0x006310e0`, and `KeySpeedMgr` vptr `0x0061c9c8`; `VirusChecker` field naming should treat `+0x08` as a tree count unless stronger state evidence appears.

Impact:

- New [CheatDetector](by-file/CheatDetector.md), [VirusChecker](by-file/VirusChecker.md), [KeySpeedMgr](by-file/KeySpeedMgr.md), [CheatDetector memory](by-memory/0x00483f00-0x0048402c.CheatDetector.md), [VirusChecker memory](by-memory/0x005c0460-0x005c0fe1.VirusChecker.md), and [KeySpeedMgr memory](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md) docs use IDA-confirmed ranges as the ownership anchor.
- Added exact singleton storage pages for [g_pCheatDetector](by-memory/0x0067ab3c-0x0067ab40.g_pCheatDetector.md), [g_pKeySpeedMgr](by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md), and [g_pVirusChecker](by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md).
- Added [security singleton vtables](by-type/by-vtable/SecuritySingletonVtables.md) and [VirusChecker process tree layout](by-type/by-struct/VirusCheckerProcessTreeLayout.md) so migration has IDA-verified vtable and field-layout anchors.
- Added [KeySpeedMgr layout](by-type/by-struct/KeySpeedMgrLayout.md) and [KeySpeedMgr vtable](by-type/by-vtable/KeySpeedMgrVtable.md) so the input singleton has an IDA-verified object-size, field-offset, and vptr anchor.
- Do not migrate the active `class_VirusChecker.cpp`, `class_KeySpeedMgr.cpp`, or `class_CheatDetector.cpp` output directly without reviewing the omitted/disabled functions above.

Follow-up:

- Recheck generated output after Wave3 fixes land and verify `0x005c05a0`, `0x005c07b0`, `0x005c0940`, `0x005c09f0`, `0x005c0aa0`, `0x005c0ac0`, `0x005c0b40`, `0x005c0ca0`, `0x005c0eb0`, `0x005c0fa0`, `0x006310e0`, `0x004eff30`, `0x004efee0`, `0x004effa0`, `0x0061c9c8`, `0x00483fe0`, `0x00483ff0`, and `0x00615564`.
- Continue xref hunting for a live `VirusChecker` activation path before treating it as active runtime anti-cheat.

### 2026-05-24 - CursorManager and ScreenPane singleton alias conflict

Observed:

- `source-3/simroot_v2/class_CursorManager.cpp` emits `SetActiveCursor`, `GetScreenWidth`, and `GetScreenHeight` as methods on `CursorManager`, and metadata describes calls through `DAT_0067a7cc / g_pCursorManager`.
- IDA MCP decompilation of `ScreenPane::ScreenPane` at `0x00556910` writes `dword_67A7CC = this`, initializes the same screen width/height fields returned by the generated `CursorManager` getters, and installs `ScreenPane` vtables.
- IDA MCP decompilation of `~ScreenPane` at `0x00556a60` clears `dword_67A7CC = 0`.
- IDA MCP decompilation of `0x005573f0` confirms cursor switching behavior on the same root object layout, with an `HCURSOR` table and active cursor index.

Expected:

- `0x0067a7cc` should remain canonical as `g_pScreenPane` unless later evidence proves a separate allocated cursor manager object.
- `g_pCursorManager` should be represented as a typed alias or helper view for cursor/dimension calls, not as a second independent singleton.
- Final source migration should either fold the helper island into `ScreenPane.cpp` or keep a small adjacent `CursorManager.cpp` with explicit ScreenPane ownership notes.

Impact:

- New [CursorManager](by-file/CursorManager.md), [CursorManager class](by-class/CursorManager.md), [screen cursor helper memory](by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md), and [g_pScreenPane](by-global/g_pScreenPane.md) docs use the ScreenPane singleton as the ownership anchor.
- 2026-05-26 follow-up added [g_pCursorManager](by-global/g_pCursorManager.md) as an explicit generated-alias page over [g_pScreenPane storage](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md). IDA MCP reports `0x0067a7cc` as a 4-byte `.data` item named `dword_67A7CC` with 145 refs.
- 2026-05-26 follow-up IDA decompilation of `ScreenPane::ScreenPane` confirms initialization of the singleton, vtables, root layer list at `+0x10c`, dimensions at `+0x112/+0x114/+0x116`, and frame/fade fields. It does not show writes to the cursor handle table later used at `+0x550`, so cursor-resource initialization remains unresolved.
- 2026-05-26 follow-up IDA decompilation of `0x00557380`, `0x005573b0`, and `0x005573f0` strengthens ScreenPane ownership: dirty/update state is at `+0x118/+0x11c`, the repaint/timer helper uses the `+0xa4` subobject, and cursor switching reads active cursor/table state from `+0x580/+0x550` on the same object.
- Do not migrate generated `class_CursorManager.cpp` as proof of a standalone process-wide manager until the root object layout is resolved.

Follow-up:

- Inspect the cursor handle initialization/load path to decide whether the original source used a separate `CursorManager.cpp`, private ScreenPane methods, or an embedded helper struct. Root screen construction itself now favors ScreenPane-owned helper code.
- Reconcile generated names `DAT_0067a7cc`, `dword_67A7CC`, `g_pScreenPane`, and `g_pCursorManager` before global-data ownership changes.
- After the next `simroot_v2` refresh, recheck whether `class_CursorManager.cpp` still emits duplicate synthetic `CursorManagerLayout` declarations and whether browser output still calls `CursorManager::SetActiveCursor(g_pCursorManager, ...)`.

### 2026-05-24 - IME pane generated source has helper-owner pollution and omitted thunks

Observed:

- `class_FittingRoomDownloadControlPane.cpp` currently emits `SetCompositionString` at `0x004e7470` and `ShowCandidateList` at `0x004e7930`.
- IDA MCP confirms both functions live in the contiguous IME pane neighborhood `0x004e70f0-0x004e8ae6`; `0x004e7470` is directly called by `IMECompositionPane::OnKeyEvent` at `0x004e782d`.
- IDA and generated source show both functions use `g_pIMEPane` / `0x0069b458`, composition/candidate popup geometry, text-edit caret position, and candidate-string queue data rather than fitting-room state.
- `class_IMECompositionPane.cpp` and `class_IMEStatusPane.cpp` scalar destructors currently label base teardown as `TextButtonExControlPane::~Pane`.
- `class_IMECandidatePane.cpp.disabled` omits body for adjustor thunk `0x004e85e7`; `class_IMEStatusPane.cpp.disabled` omits body for adjustor thunk `0x004e8629`, while IDA confirms both as real 0xb thunk functions.
- 2026-05-26 recheck: `0x004e7930` has direct caller `0x004e7d13` inside `IMECandidatePane::HandleIMEMessage`; `0x0069b458` is a 4-byte `.data` singleton with 17 data references; `0x004e85dc-0x004e8634` is an eight-thunk compiler adjustor island.

Expected:

- `0x004e7470` should be owned by `IMECompositionPane` or a file-local IME composition helper.
- `0x004e7930` should be owned by `IMECandidatePane` or a file-local IME candidate helper.
- IME pane destructor paths should use neutral pane base teardown names until inheritance is resolved.
- Disabled thunk views should either emit the confirmed tiny thunk bodies or explicitly mark them as intentionally omitted compiler glue.

Impact:

- New [IMEPanes](by-file/IMEPanes.md), [IMEPane](by-class/IMEPane.md), [IMECompositionPane](by-class/IMECompositionPane.md), [IMECandidatePane](by-class/IMECandidatePane.md), [IMEStatusPane](by-class/IMEStatusPane.md), [CandidateStringQueue](by-class/CandidateStringQueue.md), and [g_pIMEPane](by-global/g_pIMEPane.md) docs use IDA ownership anchors and treat the fitting-room/helper labels as suspect.
- Exact pages now anchor [IMECompositionPane::SetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md), [IMECandidatePane::ShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md), [IME adjustor thunks](by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md), and [g_pIMEPane storage](by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md).
- 2026-05-26 follow-up: IDA MCP string/xref/decompile checks identify generated `CandidateStringQueue` helper methods as MSVC/Dinkumware `std::deque<std::wstring>`-style template support, not a handwritten NexusTK queue class. Added [Candidate string deque template](by-type/by-template/CandidateStringDequeTemplate.md) and marked exact helper ranges in [by-memory/-ignored.md](by-memory/-ignored.md), while keeping the IME pane and `InputMan` callers as reconstructable product code.

Follow-up:

- After Wave3 data fixes are available, regenerate or inspect `class_FittingRoomDownloadControlPane.cpp`, `class_IMECompositionPane.cpp`, `class_IMECandidatePane.cpp`, and disabled IME thunk files against the IDA-confirmed `0x004e70f0-0x004e8ae6` range.
- Recheck whether Wave3 continues materializing `class_CandidateStringQueue.cpp` as a product class. Expected handling is STL/template support for the exact helper ranges, with source-level container usage remaining in `IMEPanes` and `InputMan`.
- Reconcile `DAT_0069b458` / `dword_69B458` aliases to `g_pIMEPane` where the dataflow clearly targets the IME singleton.

### 2026-05-24 - Help and item tooltip generated source has owner/type pollution

Observed:

- `class_HelpPane.cpp` and related help-pane generated files contain stray unrelated type artifacts, including a `BackGroundPane` deleting-destructor typedef in the help-pane source neighborhood.
- Help/tooltip destructors and teardown labels include unrelated base-owner names such as `TextButtonExControlPane`, even when IDA confirms the functions belong to `HelpPane`, `SimpleHelpPane`, `SimpleHelpPane2`, `ItemHelpPane`, `WillBeChangedItemPane`, or `WillBeChangedSpellPane` ranges.
- `SimpleHelpPane` and `SimpleHelpPane2` event methods are rendered through `BulletinSession` owner-offset names, which appears to be type-owner pollution rather than real bulletin ownership.
- IDA names `0x004c8b20` as `??1exception@boost@@MAE@XZ_2`, but the surrounding decompile/source behavior is `ItemHelpPane::~ItemHelpPane`.
- Several disabled help/tooltip thunk files omit useful tiny bodies, even though IDA confirms starts in the destructor island at `0x004ce34b-0x004ce724`.
- 2026-05-26 recheck: IDA confirms a real `SimpleHelpPane2` factory/helper at `0x004c7680-0x004c77e0`, directly called from `0x0045213c`, but active `simroot_v2` `.cpp` output does not emit a standalone body for it.
- 2026-05-28 recheck: IDA raw disassembly confirms adjacent `SimpleHelpPane2` factory wrappers and anchor/cursor predicate code at `0x004c77e0-0x004c78db`; active `simroot_v2` `.cpp` output does not emit standalone bodies for these raw helper starts either.
- 2026-05-28 recheck: IDA confirms mixed help-tooltip support helpers at `0x004ce160-0x004ce34b`, including a string helper called from `ItemHelpPane::PopulateItemData`, a vector helper called from `HelpPane::HelpPane`, and singleton-clear unwind helpers. The prior `ItemHelpPaneCore` documentation endpoint was corrected from `0x004ce15f` to `0x004ce160`.
- 2026-05-26 storage recheck confirms help/tooltip singleton globals at `0x0069ae00`, `0x0067a7d4`, `0x0069ae04`, and `0x0069b414`.

Expected:

- Generated help/tooltip source should use neutral base teardown labels until the real pane inheritance graph is resolved.
- Event methods should remain on their help-pane classes unless direct evidence proves a shared bulletin/session subobject.
- `ItemHelpPane` destructor naming should be corrected away from Boost exception ownership.
- Confirmed tiny thunks should be consistently emitted or explicitly marked as intentionally omitted compiler glue.
- `0x004c7680-0x004c78db` should be owned by `HelpPanes` / `SimpleHelpPane2` as factory/helper code rather than left only as a raw generated metadata call from `MiniMapDialog` or omitted due to missing IDA function objects.

Impact:

- New [HelpPanes](by-file/HelpPanes.md), [HelpPane](by-class/HelpPane.md), [SimpleHelpPane](by-class/SimpleHelpPane.md), [SimpleHelpPane2](by-class/SimpleHelpPane2.md), [ItemHelpPane](by-class/ItemHelpPane.md), [WillBeChangedItemPane](by-class/WillBeChangedItemPane.md), and [WillBeChangedSpellPane](by-class/WillBeChangedSpellPane.md) docs use IDA ranges as the ownership anchor and treat those generated labels as suspect.
- Exact pages now anchor [SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md), [SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md), [HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md), [g_pSimpleHelpPane](by-global/g_pSimpleHelpPane.md), [g_pSimpleHelpPane2](by-global/g_pSimpleHelpPane2.md), [g_pItemHelpPane](by-global/g_pItemHelpPane.md), and [g_pWillBeChangedItemPane](by-global/g_pWillBeChangedItemPane.md).

Follow-up:

- After Wave3 data fixes are available, compare regenerated `class_HelpPane.cpp`, `class_SimpleHelpPane.cpp`, `class_SimpleHelpPane2.cpp`, `class_ItemHelpPane.cpp`, and disabled thunk files against the IDA-confirmed `0x004c65a0-0x004ce724` ranges.
- Recheck whether `0x004c7680-0x004c78db` becomes active `HelpPanes` / `SimpleHelpPane2` helper bodies rather than only appearing in generated metadata or raw unmodeled bytes.
- Reconcile event-handler subobject naming before migrating help-pane source into the proposed `ui/controls/HelpPanes.cpp`.

### 2026-05-24 - AlertPane family generated source has BlueAlert and type-owner pollution

Observed:

- `class_BlueAlertPane.cpp` emits constructor `0x005008c0` as if it uses `DIALOG2.DLG`, parent dimensions, and a single OK button.
- IDA MCP decompilation of `0x005008c0` on 2026-05-24 instead shows a dynamic alert-style constructor: blank `DialogPane` initialization, `BlueAlertPane` vtables, layout-reference anchor/rect measurement, text measurement, optional primary/secondary buttons, dialog show, slide animation, and layout-reference storage.
- IDA `xrefs_to 0x005008c0` currently reports no direct constructor callers, even though `BlueAlertPane` virtual methods and destructor/vtable refs exist.
- `class_VersatileAlertPane.cpp` contains a stray `BackGroundPane` deleting-destructor typedef and labels base teardown as `TransferReplyAlert::~TransferReplyAlert`.
- `class_BlueAlertPane.cpp` destructor text also labels teardown through `TransferReplyAlert`.
- `class_AlertPane.meta_wave3` reports `vtable_count: 0` even though IDA confirms `AlertPane` vtable bases at `0x00618b00`, `0x00618b68`, and `0x00618b98`. The active source names vtable placeholders, but the metadata inventory omits the real bases.
- `class_VersatileAlertPane.meta_wave3` reports `vtable_count: 0` even though IDA confirms `VersatileAlertPane` vtable bases at `0x00618ba4`, `0x00618c0c`, and `0x00618c3c`, with constructor stores at `0x004a06b6`, `0x004a06bc`, and `0x004a06c6`.
- Active `class_VersatileAlertPane.cpp` does not represent the unreferenced cleanup-shaped body at `0x004a06e0-0x004a0714`; IDA disassembly shows it reinstalling the same three vtables, releasing callback offset `+0x270`, and jumping to alert base teardown. IDA currently reports no callers and does not model it as a function.
- `class_BlueAlertPane.meta_wave3` reports `vtable_count: 0` even though IDA confirms `BlueAlertPane` vtable bases at `0x0061dcd8`, `0x0061dd40`, and `0x0061dd70`, with constructor stores at `0x00500920`, `0x00500926`, and `0x00500930`.
- `class_UrlAlertPane.meta_wave3` reports `vtable_count: 0` even though IDA confirms `UrlAlertPane` vtable bases at `0x0062e584`, `0x0062e5ec`, and `0x0062e61c`, with constructor stores at `0x00599aac`, `0x00599ab2`, and `0x00599abc`.
- Existing UrlAlert docs and generated shape treated `0x00599bd0-0x00599bf1` as one adjustor-thunk span. IDA shows `0x00599bd0-0x00599bda` is a singleton-clear helper used by constructor exception cleanup, while `0x00599bdb` and `0x00599be6` are the actual vtable adjustor thunks.
- Active `class_UrlAlertPane.cpp` still contains `WAVE3 OMITTED METHOD BODY` for constructor `0x00599a40` even though following generated pseudo-code and IDA disassembly recover the core constructor behavior.
- `class_BlueAlertPane.cpp` emits a `global-data g_uiTileRenderer` record and renders `DrawBorderFrame` through `g_uiTileRenderer->BeginFrame`, `SelectTile`, and `Blit`.
- IDA MCP decompile/disassembly of `0x00500d70` and `0x00500e20` on 2026-05-24 shows no real `g_uiTileRenderer` storage load. The actual path uses `dword_67A744` / `g_pEPFLib` frame lookup through `0x004d02f0` plus render callbacks including `dword_69B3E8` and `dword_69B3EC`.
- The address neighborhood between `VersatileAlertPane` callbacks and destructor includes IDA-confirmed `ModelessDialogPane` and dialog event support at `0x004a0760-0x004a0c8e`; it should not be folded into `VersatileAlertPane` by address locality.
- 2026-05-26 recheck: IDA vtable refs show `0x0048c550-0x0048c58b` is a shared `AlertPane`-family scalar deleting destructor, not BlueAlert-only or Clan-only. `0x0048c315-0x0048c32b` are compiler adjustor thunks into it. Referencing vtables include `ClanLeaveConfirmDialog` (`0x00615f38/0x00615fa0/0x00615fd0`), `AlertPane` (`0x00618b00/0x00618b68/0x00618b98`), `BlueAlertPane` (`0x0061dcd8/0x0061dd40/0x0061dd70`), `CopyWindow` (`0x00622e7c/0x00622ee4/0x00622f14`), and `QuitDialog` (`0x0062f0e0/0x0062f148/0x0062f178`).
- 2026-05-26 current-state recheck: IDA MCP still reports no direct callers/code xrefs for `BlueAlertPane::BlueAlertPane` or the four custom virtual handler bodies. `class_BlueAlertPane.meta_wave3` still lists `g_uiTileRenderer` as incomplete `global-data` with no memory ranges.

Expected:

- `BlueAlertPane::BlueAlertPane` should be regenerated or rewritten from IDA evidence before migration.
- `VersatileAlertPane` and `BlueAlertPane` destructor paths should use neutral alert/dialog base teardown names until the true type graph is resolved.
- `0x0048c550` should be treated as a shared alert/dialog base deleting destructor; generated `boost::exception` and `TransferReplyAlert` labels are owner/type pollution.
- `g_uiTileRenderer` should remain a documented generated alias until a render/global pass proves actual backing storage and final callback types.
- `0x004a0760-0x004a0c8e` should remain assigned to modeless/dialog event infrastructure, not alert ownership.

Impact:

- New [AlertPanes](by-file/AlertPanes.md), [BlueAlertPane](by-class/BlueAlertPane.md), [VersatileAlertPane](by-class/VersatileAlertPane.md), [g_uiTileRenderer](by-global/g_uiTileRenderer.md), and related memory docs use IDA as the source-layout anchor and treat the generated constructor/destructor/renderer text as suspect.
- Added [AlertPane vtables](by-type/by-vtable/AlertPaneVtables.md) to preserve IDA-confirmed constructor stores, shared destructor slots, and callback extension slots missing from Wave3 vtable inventory.
- Added [VersatileAlertPane vtables](by-type/by-vtable/VersatileAlertPaneVtables.md) to preserve IDA-confirmed constructor stores, callback extension slots, destructor slots, and the cleanup-shaped `0x004a06e0` body missing from active generated source.
- 2026-05-26 follow-up: added exact [VersatileAlertPane raw cleanup](by-memory/0x004a06e0-0x004a0714.VersatileAlertPaneRawCleanup.md) documentation. Current IDA still does not wrap `0x004a06e0` as a function, but raw disassembly and prewave confirm the `VersatileAlertPane` vtable stores, callback release, and base teardown jump.
- Added [BlueAlertPane vtables](by-type/by-vtable/BlueAlertPaneVtables.md) to preserve IDA-confirmed constructor stores and custom drawing/action slots missing from Wave3 vtable inventory.
- Added [UrlAlertPane vtables](by-type/by-vtable/UrlAlertPaneVtables.md) to preserve IDA-confirmed constructor/destructor stores, the `OnConfirm` callback slot, and the corrected split between singleton-clear helper and destructor adjustor thunks.
- Exact pages now anchor [AlertPane shared scalar destructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md) and [AlertPane adjustor thunks](by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md).
- 2026-05-26 follow-up: added [AlertPane layout](by-type/by-struct/AlertPaneLayout.md) for IDA-confirmed three-view vptr offsets `+0x00/+0xa0/+0xa4`, base layout-reference offset `+0x26c`, and derived wrapper offsets `+0x270/+0x274`. Current generated metadata still reports `vtable_count: 0` for the family, and inherited `DialogPane` field names remain provisional.
- 2026-05-26 follow-up: added `g_uiTileRenderer` to [by-global/-ignored.md](by-global/-ignored.md) as a stale generated global alias. Keep [SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md), [g_pEPFLib](by-global/g_pEPFLib.md), and [ResourceLayoutTable](by-file/ResourceLayoutTable.md) as the real owner anchors.

Follow-up:

- After Wave3 tool work resumes, compare regenerated `class_BlueAlertPane.cpp` against IDA for `0x005008c0`.
- Repair generated vtable inventory so `AlertPane` records the three IDA-confirmed vtable bases instead of `vtable_count: 0`.
- Repair generated vtable inventory so `VersatileAlertPane` records the three IDA-confirmed vtable bases instead of `vtable_count: 0`.
- Decide whether [0x004a06e0-0x004a0714](by-memory/0x004a06e0-0x004a0714.VersatileAlertPaneRawCleanup.md) should stay an internal cleanup/unwind body, be emitted as a non-deleting destructor helper, or be suppressed as compiler glue; do not treat it as `ModelessDialogPane`.
- Repair generated vtable inventory so `BlueAlertPane` records the three IDA-confirmed vtable bases instead of `vtable_count: 0`.
- Repair generated vtable inventory so `UrlAlertPane` records the three IDA-confirmed vtable bases instead of `vtable_count: 0`, and split `0x00599bd0` from the real adjustor thunks in generated summaries.
- Recheck live constructor paths for `BlueAlertPane`; `0x0048c550` vtable refs are now documented as shared alert-family destructor evidence.
- Reconcile generated base-owner names for `VersatileAlertPane` and `BlueAlertPane` destructors.
- Use [SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) as the render-global anchor for `0x0069b3e8`, `0x0069b3ec`, and `0x0069b3fc` before accepting generated `g_uiTileRenderer`, `g_pfnBlitTileFrame`, or composition-renderer aliases as final names.

### 2026-05-24 - FolderTreePane generated source mixes filesystem tree, chat, surface, and help/system-message ownership

Observed:

- Active `class_FolderTreePane.cpp` contains the real filesystem tree-control core at `0x004b1b90-0x004b32c9`, but also contains chat-message methods at `0x0047f280-0x004805d4`, generic surface/presentation helpers at `0x004b8be0`, `0x004b9820-0x004ba24a`, and `0x00557140-0x00559a0f`, plus help/system-message code at `0x00585360-0x0058a8e0`.
- IDA MCP confirms additional folder-tree-local function starts that active Wave3 output does not model cleanly: `0x004b1a00`, `0x004b2680`, and `0x004b3090`.
- Active generated source marks `FolderTreePane::SetSelection` at `0x004b3210` but omits the function body; IDA decompilation shows real selection/scroll-into-view behavior.
- Wave3 records `Tree_struct_FolderTreePane__TreeElem_::~Tree_struct...` at `0x004b5650`, but IDA decompilation for that query resolves to the `0x004b1b90` constructor pseudocode. Treat the `0x004b5650` boundary/name as suspect until raw disassembly review.
- 2026-05-25 raw disassembly review resolved the `0x004b5650` caveat: the bytes are real destructor-shaped tree cleanup, but IDA associates the block with `FolderTreePane` constructor exception cleanup. `xrefs_to` shows an EH-thunk reference from `0x005fe944`, while ordinary `callers` reports no direct callers.
- Disabled thunks `0x004b59d5` and `0x004b59e0` are IDA-confirmed tiny functions; Wave3 currently emits one as missing code and one as a disabled adjustor thunk.
- 2026-05-26 IDA-only recheck: `0x004b3210` is a real `SetSelection` body with direct callers from `SelectNodeByPath`, `OnKeyEvent`, and `OnMouseEvent`; it copies the iterator, computes node bounds, scrolls selection into view, and invalidates/updates the pane.
- 2026-05-26 IDA-only recheck: `0x004b59d5` and `0x004b59e0` are 0xb-byte compiler adjustor thunks that subtract `0xa0` or `0xa4` from `this` and jump to `FolderTreePane` scalar deleting destructor `0x004b5a70`.
- 2026-05-26 IDA vtable recheck: current `class_FolderTreePane.meta_wave3` still reports `vtable_count: 0`, but IDA confirms concrete vtables at `0x0061a500`, `0x0061a510`, `0x0061a518`, `0x0061a58c`, and `0x0061a5bc`.
- Current generated methods include false `virt_meth_0x430049` and `virt_meth_0x450045` rows. IDA shows these values come from UTF-16 `TREEICON.EPF` string data beginning at `0x0061a5c4` immediately after the tertiary `FolderTreePane` vtable, not from real vtable slots.

Expected:

- `FolderTreePane.cpp` migration should use the verified filesystem tree ranges `0x004b1b90-0x004b32c9` and `0x004b3350-0x004b5c3f`.
- Chat-message, surface/presentation, and help/system-message methods should be reassigned or explicitly documented before migrating active generated source.
- `0x004b3210` should regain its body in generated output or be represented as an omitted-body data issue.
- `0x004b5650` should be represented as `Tree<FolderTreePane::TreeElem>` destructor/EH-cleanup support rather than used as proof for a standalone original source method.
- Vtable inventory should record the three `FolderTreePane` vtable views and the two local tree-helper vtables, and generated virtual rows derived from `TREEICON.EPF` string dwords should be removed/quarantined.

Impact:

- New [FolderTreePane](by-file/FolderTreePane.md), [FolderSelectDialog](by-file/FolderSelectDialog.md), and [FolderTreePaneOwnerPollution_47f280_58a8e0](by-item/FolderTreePaneOwnerPollution_47f280_58a8e0.md) docs treat the active generated file as polluted and split the verified folder-picker/control source from unrelated owners.
- Added [Folder tree destructor cleanup](by-memory/0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup.md) and [FolderTreePane tree templates](by-type/by-template/FolderTreePaneTreeTemplates.md) to keep the generated template support tied to `FolderTreePane.cpp`.
- Added exact docs for [FolderTreePane SetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md) and [FolderTreePane adjustor thunks](by-memory/0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks.md). The adjustor thunks are also listed in [by-memory ignored ranges](by-memory/-ignored.md).
- 2026-05-26 follow-up: added [FolderTreePane vtables](by-type/by-vtable/FolderTreePaneVtables.md) and marked the adjacent `TREEICON.EPF` string data at `0x0061a5c4-0x0061a5dc` in [by-memory ignored ranges](by-memory/-ignored.md) so it is not decoded as virtual methods.

Follow-up:

- Re-run Wave3 inspection after data fixes and verify `show method 0x004b3210`, `show method 0x004b5650`, `show method 0x004b1a00`, `show method 0x004b2680`, and `show method 0x004b3090`; specifically confirm whether `0x004b3210` regains its body and whether `0x004b5650` can be marked as cleanup/projected rather than a normal direct-called method.
- Confirm regenerated output keeps `0x004b59d5-0x004b59eb` as ignored compiler thunks instead of importing them as source methods.
- Confirm regenerated output records `0x0061a500`, `0x0061a510`, `0x0061a518`, `0x0061a58c`, and `0x0061a5bc` in vtable inventory and drops/quarantines `virt_meth_0x430049` and `virt_meth_0x450045`.
- Decide whether the chat-message subset remains a real chat list subclass currently named `FolderTreePane` or should be moved wholly under [Chatting](by-file/Chatting.md).

### 2026-05-24 - TransferReplyPredefinedAlert active body disagrees with IDA

Observed:

- Active `class_TransferReplyPredefinedAlert.cpp` emits `0x004790a0` as a text-edit/predefined-reply action that finds a tab pane, sets reply text, and optionally submits a predefined reply.
- IDA MCP decompilation of `0x004790a0` on 2026-05-24 instead shows the same article navigation-packet pattern as `TransferReplyAlert::OnConfirm`: close/hide alert, find previous bulletin dialog entry, call article navigation helper `0x004751c0`, and optionally pop the session.
- IDA confirms `0x004790a0` as a real function start, but does not define Wave3-projected constructor start `0x00479050` as a function.
- Related alert constructor starts at `0x00478f90`, `0x0047e040`, `0x0047e100`, `0x0047e4b0`, and `0x0047e6a0` are also Wave3-projected starts that IDA does not currently define as functions.
- 2026-05-26 IDA-only recheck: `lookup_funcs 0x004790a0` reports size `0x6f`, `xrefs_to` reports a vtable/data reference at `0x006141f0`, and `callees` matches `TransferReplyAlert::OnConfirm` exactly: `0x004a1250`, `0x004751c0`, and `0x004a10e0`.
- 2026-05-26 live follow-up reconfirmed exact range `0x004790a0-0x0047910f`, no function/xrefs at projected constructor start `0x00479050`, and callsites `0x004790b6`, `0x004790f1`, and `0x00479107`. The by-memory coverage row is now medium for the IDA-backed binary behavior while this generated-body mismatch remains an active Wave3 data issue.

Expected:

- `TransferReplyPredefinedAlert::OnAlertAction` should be reconciled against IDA before source migration.
- Constructor boundaries for the small bulletin/mail alert wrappers should be treated as projected until raw disassembly or function-boundary cleanup confirms them.

Impact:

- The active generated `TransferReplyPredefinedAlert` body can mislead file/class documentation and reconstructed source if trusted over IDA.
- Alert wrappers may look more behaviorally diverse than they are; IDA currently groups `TransferReplyAlert` and `TransferReplyPredefinedAlert` by nearly identical navigation-packet actions.

Current documentation:

- [BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [TransferReplyPredefinedAlert](by-class/TransferReplyPredefinedAlert.md)
- [Bulletin/mail alert companion memory](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
- Added exact action evidence in [TransferReplyPredefinedAlert OnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md).

Follow-up:

- Re-run Wave3 inspection after data fixes and compare emitted body for `0x004790a0`.
- Confirm regenerated output uses the article-navigation acknowledgement body for `0x004790a0`, or explicitly records any reason the IDA-equivalent body should differ from `TransferReplyAlert::OnConfirm`.
- Decide whether the projected constructors should be imported as functions, left as class construction snippets, or excluded until an IDA boundary pass creates function objects.

### 2026-05-24 - MessageShowPane text-update helper had FittingRoomDownloadControlPane ownership pollution

Observed:

- IDA MCP confirms `0x00522530-0x005226ea` as a real function that replaces the active message overlay text, recomputes wrap metrics, reapplies bounds, and refreshes the text area.
- IDA xrefs show the only direct caller is `0x005ac070` at `0x005ac150`, the message overlay packet handler that uses `g_pMessageShowPane` to update or create [MessageShowPane](by-file/MessageShowPane.md).
- Older Wave3/Wave2-derived data owned method `0x00522530` through `class_FittingRoomDownloadControlPane.cpp`, and older Wave2 cache code names it `FittingRoomDownloadControlPane::SetWrappedText`.
- `class_MessageShowPane.cpp` also omits tiny singleton clear helper `0x005226f0-0x005226fa`; IDA confirms it and reports an unwind/constructor xref.
- Rename registry evidence for `DAT_0069b4f4` conflicts between `g_pMessageShowPane` and a later `g_pExtendedUIPane` alias.
- 2026-05-26 `simroot_v2` recheck: current `class_MessageShowPane.cpp` now emits `MessageShowPane::SetWrappedText` at `0x00522530`, so the active file-owner portion of this issue has improved. Older Wave2/Wave3 data and this issue remain useful provenance for why fitting-room ownership should not be restored.
- 2026-05-26 IDA-only recheck: `0x005226f0` is an 0xb-byte singleton-clear EH helper with no ordinary direct callers; `0x005226fb` and `0x00522706` are 0xb-byte compiler adjustor thunks into scalar deleting destructor `0x00522720`.

Expected:

- `0x00522530` should be owned by `MessageShowPane` or a message-overlay local helper, not by fitting-room UI.
- `0x005226f0` should be modeled, explicitly excluded, or documented as a tiny compiler/unwind helper.
- `0x0069b4f4` naming should be reconciled after reviewing the surrounding `0x0069b4xx` pane singleton group.

Impact:

- New [MessageShowPane](by-file/MessageShowPane.md) docs use IDA caller and data-flow evidence for the overlay split and treat the fitting-room owner as historical polluted data.
- Added exact docs for [MessageShowPane SetWrappedText](by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md), [MessageShowPane singleton-clear EH helper](by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md), [MessageShowPane adjustor thunks](by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md), [MessageShowPane scalar deleting destructor](by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md), and [g_pMessageShowPane memory](by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md). The EH helper and adjustor thunks are listed in [by-memory ignored ranges](by-memory/-ignored.md).

Follow-up:

- Recheck generated output after Wave3 data fixes and make sure `0x00522530` remains under `MessageShowPane`, not `FittingRoomDownloadControlPane`.
- Keep `0x005226f0-0x00522711` out of handwritten source migration: `0x005226f0` is EH cleanup glue, and `0x005226fb-0x00522711` are compiler adjustor thunks.
- Reconcile `g_pMessageShowPane` versus `g_pExtendedUIPane` naming for `0x0069b4f4`.

### 2026-05-24 - NewPredefinedFormArticleDialog has destructor owner pollution

Observed:

- `class_NewPredefinedFormArticleDialog.cpp` emits the scalar deleting destructor at `0x0047ec30` with a call labeled `ArticleDialog::~ArticleDialog()`.
- The class behavior, constructor, source-file evidence, and vtables are for `NewPredefinedFormArticleDialog`, a bulletin/predefined-form article composer. Treating the base teardown as `ArticleDialog` risks folding predefined-form article cleanup into the wrong class/file.
- Disabled thunk `0x0047e931` is IDA-confirmed as a real tiny function but the disabled view only says `missing code for 0x0047e931`; sibling thunk `0x0047e93c` is emitted as an adjustor thunk.

Expected:

- The destructor should name the real base teardown or use a neutral unresolved base helper until inheritance/teardown ownership is proven.
- Disabled vtable thunks should either have explicit omitted-body metadata or be consistently represented as compiler thunks.

Impact:

- New [NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md) docs treat the destructor label as owner pollution and use the constructor/parser cluster as the source-layout anchor.

Recheck:

- 2026-05-25 using current `simroot_v2` and IDA MCP only: `0x0047ec30` decompiles as a deleting-destructor wrapper that calls `0x004a1450`, then optionally frees storage. `0x004a1450` is [DialogInSession](by-class/DialogInSession.md)'s non-deleting destructor, not ArticleDialog-specific teardown.
- Neighboring wrappers `0x0047e950` (`ArticleDialog`) and `0x0047ea10` (`BulletinDialog`) also call `0x004a1450`; they differ mainly in object-size guard constants (`0x278`, `0x274`, versus `0x5368` for NewPredefinedFormArticleDialog).
- `0x0047e931` has real two-instruction thunk body `sub ecx, 0xa0; jmp 0x0047ec30`; sibling `0x0047e93c` is `sub ecx, 0xa4; jmp 0x0047ec30`. The disabled output's missing-code marker for `0x0047e931` is still a data/emission issue.
- 2026-05-26 IDA-only recheck: `lookup_funcs` reports `0x0047e931` and `0x0047e93c` as 0xb-byte thunks and `0x0047ec30` as a 0x3b-byte scalar deleting destructor. `xrefs_to 0x004a1450` shows the same base cleanup called by sibling dialog destructor wrappers, confirming the generated `ArticleDialog` base label is pollution.
- Added exact docs for [NewPredefinedFormArticleDialog adjustor thunks](by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md) and [NewPredefinedFormArticleDialog scalar deleting destructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md). The adjustor thunks are now listed in [by-memory ignored ranges](by-memory/-ignored.md).

Follow-up:

- After the next `simroot_v2` refresh or Wave3 regeneration, verify that `0x0047ec30` uses neutral `DialogInSession` base cleanup naming and that `0x0047e931` receives the same emitted thunk body style as `0x0047e93c`.
- Keep `0x0047e931-0x0047e947` ignored as compiler glue even if generated output starts emitting both thunk bodies.

### 2026-05-24 - Ranking dialog source data has owner pollution and raw helper starts

Observed:

- `class_RankingDialog.cpp` emits non-ranking functions, including WebBoardDialogOld helpers at `0x0046e2a0`, `0x0046e640`, and `0x0046eaa0`; Exchange helpers at `0x004add40` and `0x004ade60`; generic dialog animation helpers at `0x0049eac0`, `0x0049eb90`, raw starts `0x0049ee50` and `0x0049ef60`; and popup/menu or packet helpers at `0x004fee40`, `0x00516510`, `0x00516670`, `0x00516dd0`, `0x00516e50`, and `0x00544710`.
- 2026-05-28 IDA MCP recheck places `0x004fee40` in the [UID:00022W] `ChangePasswordDialogPacketHelpers` account/password reply helper cluster, not in `RankingDialog`.
- 2026-05-25 IDA MCP recheck confirms `0x0049eac0` and `0x0049eb90` are shared `DialogPane` animation helpers with 47 and 69 direct callers across unrelated dialog families. It also confirms `0x0049ee50` and `0x0049ef60` are raw complete helper bodies with no IDA function object and no direct callers/xrefs in the current IDB.
- `RankingEventScrollPane` has valid raw code starts at `0x004598b0`, `0x0045a990`, and `0x0045add0`, but IDA MCP currently reports no function object at those addresses.
- 2026-05-25 IDA MCP recheck confirms additional raw starts inside the same scroll-pane helper islands: `0x00459910`, `0x00459940`, `0x00459970`, `0x004599d0`, `0x00459a00`, `0x00459a20`, `0x00459a40`, `0x0045aa00`, and `0x0045ab50` are also not modeled as functions, while `0x00459a60`, `0x0045a710`, `0x0045ac10`, and `0x0045ae30` are modeled.
- `class_RankingEventScrollPane.meta_wave3` reports `vtable_count: 0` even though IDA confirms three class vtable views at `0x00610a4c`, `0x00610a98`, and `0x00610ac8`. The active source names vtable placeholders, but the metadata inventory does not record the real bases.
- Current `source-3/simroot_v2/class_RankingEventScrollPane.cpp` has an `OnMouseEvent` scoped marker at `0x00459a60`, but the active source emits only local structure declarations before `HasActiveEffect`; the `OnMouseEvent` method body is missing from the generated file.
- 2026-05-25 IDA MCP recheck also confirms `0x0045a400-0x0045a70b` as a modeled `RankingEventScrollPane` hit-test helper called only from `OnMouseEvent`, but the active generated source does not emit it.
- `0x0045ac10-0x0045adc3` is modeled and called from `OnMouseEvent` plus raw drag helpers, but it is also missing as an active emitted method in the current `class_RankingEventScrollPane.cpp`.
- 2026-05-26 IDA MCP recheck confirms the broader ranking vtable family at `0x00610984-0x00610d68`: `RankingDialog`, `RankingEventListPane`, `RankingRewardInfoDialog`, and `RankingUserListPane` all have primary/secondary/tertiary vtable views, but active `simroot_v2` metadata still reports `vtable_count: 0` for each.
- `RankingDialog` secondary vtable slot `0x006109f4` points to real function `0x00459210`, which handles opcode `0x7d` subcommands `1`, `2`, `3`, and `6`; this was not represented in the class docs before the 2026-05-26 pass.
- 2026-05-26 IDA `py_eval` recheck reconfirms the `RankingDialog` function boundaries from `0x00458610` through `0x00459840`, `RankingEventListPane` boundaries from `0x0045ae30` through `0x0045be00`, the six vtable bases/stores for those two classes, and the `0x00459210` packet-handler vtable reference.
- The generated method partitions include several destructor adjustor thunks as class methods. IDA confirms these are compiler-generated pointer-normalization stubs at `0x0045981b-0x00459830`, `0x0045bddd-0x0045bdf2`, `0x0045f0a8-0x0045f0bd`, and `0x0045f97d-0x0045f992`.
- `RankingCategoryRecord` has useful IDA-confirmed accessors/helpers at `0x0045bf60`, `0x0045bf80`, `0x0045bf90`, `0x0045bfb0`, `0x0045bfd0`, `0x0045bfe0`, and `0x0045c240` that are disabled or not cleanly emitted in the active class source. 2026-05-27 IDA recheck also found `0x0045c050`, `0x0045c100`, and `0x0045c1e0` inside the same range; these are missing from both active and disabled generated `class_RankingCategoryRecord` output.
- `RankingCategoryCollection` active output emits only constructor/accessor methods, but IDA confirms packet parser/helper starts at `0x0045c2a0`, `0x0045c560`, `0x0045cb10`, `0x0045cdc0`, and vector growth/copy helpers through `0x0045d4f8`, plus storage helpers at `0x0045d530-0x0045d740`.
- Active `class_RankingCategoryCollection.cpp` initializes `selectedCategoryId = -1` in the constructor projection, but IDA disassembly of `0x0045c260` writes only the three vector pointers at offsets `+0x00`, `+0x04`, and `+0x08`; no selected-id write to `+0x0c` exists at that function.
- `RankingRewardInfoDialog` active output omits the secondary-vtable packet handler at `0x0045ddd0`, even though IDA confirms it handles opcode `0x7d` subcommand `5`, validates the selected category id, parses reward entries, appends them to the dialog vector, and invalidates the dialog.
- `RankingRewardInfoDialog` active output also omits the reward-entry parser/accessors at `0x0045d7e0-0x0045db54` and reward vector helper islands at `0x0045eae0-0x0045efd0`, `0x0045f020-0x0045f0a7`, and `0x0045f130-0x0045f33a`; IDA confirms 560-byte reward entries, 520-byte item rows, nested item-vector ownership, and deep-copy/destruction semantics.
- `class_RankingEventListPane.cpp` emits generic draw/render helpers around `0x004b9690+`; these should be owned by shared drawing/rendering modules rather than by ranking.
- `class_RankingUserListPane.cpp` emits generic `LineTo` at `0x004b98f0`, and its generated destructor/base labels appear polluted by unrelated text-button owner names.

Expected:

- `RankingDialog.cpp` migration should include the ranking-owned cluster and exclude WebBoardDialogOld, Exchange, generic popup/menu, generic animation, and shared rendering helpers.
- Raw non-IDA helper starts should be marked projected/raw-code starts, or the IDA function table should be corrected if later analysis proves they are real functions.
- Disabled but IDA-confirmed ranking category accessors should be owned, explicitly excluded, or represented in class/memory docs before migration.
- `RankingCategoryCollection` generated source should emit or explicitly account for the parser/helper cluster and remove the unsupported selected-id constructor initialization.
- `RankingRewardInfoDialog` generated source should emit or explicitly account for the reward-info packet handler, reward-entry parser, and reward vector helper clusters rather than relying only on constructor/paint/destructor output.

Impact:

- New [RankingDialog](by-file/RankingDialog.md) docs use IDA-confirmed function boundaries plus explicit raw-code caveats.
- Added exact raw memory docs for [RankingEventScrollPane constructor/setters](by-memory/0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters.md), [hover/drag helpers](by-memory/0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers.md), and [reset state](by-memory/0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState.md).
- Added modeled helper docs for [RankingEventScrollPane OnMouseEvent](by-memory/0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent.md), [hit-test](by-memory/0x0045a400-0x0045a70b.RankingEventScrollPaneHitTest.md), [drag-to-position](by-memory/0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition.md), [RankingEventScrollPane layout](by-type/by-struct/RankingEventScrollPaneLayout.md), and [RankingEventScrollPane vtables](by-type/by-vtable/RankingEventScrollPaneVtables.md).
- Added [RankingDialog vtable family](by-type/by-vtable/RankingDialogVtableFamily.md), [RankingDialog clear singleton helper](by-memory/0x00459810-0x0045981a.RankingDialogClearSingletonHelper.md), [RankingDialog adjustor thunks](by-memory/0x0045981b-0x00459830.RankingDialogAdjustorThunks.md), [RankingEventListPane adjustor thunks](by-memory/0x0045bddd-0x0045bdf2.RankingEventListPaneAdjustorThunks.md), [RankingRewardInfoDialog clear singleton helper](by-memory/0x0045efe0-0x0045efeb.RankingRewardInfoDialogClearSingletonHelper.md), [RankingRewardInfoDialog adjustor thunks](by-memory/0x0045f0a8-0x0045f0bd.RankingRewardInfoDialogAdjustorThunks.md), and [RankingUserListPane adjustor thunks](by-memory/0x0045f97d-0x0045f992.RankingUserListPaneAdjustorThunks.md).
- Added [RankingCategoryRecord memory](by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md) and [layout](by-type/by-struct/RankingCategoryRecordLayout.md) docs to explicitly preserve the disabled-but-live accessor/helper evidence.
- Added [RankingCategoryCollection memory](by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md) and [RankingCategoryVectorStorageHelpers](by-memory/0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers.md) after IDA confirmed packet parser dispatch, function starts, record/user-entry strides, and the generated constructor mismatch.
- Added reward-info memory docs for [UID:0001ZF], [UID:0001ZG], [UID:0001ZH], [UID:0001ZI], [UID:0001ZK], and [UID:0001ZJ] after IDA confirmed the missing packet handler, parser/accessors, reward-entry/item vector strides, nested vector deep-copy, and cleanup helpers.
- Added [DialogPane slide animation](by-memory/0x0049eac0-0x0049f07e.DialogPaneSlideAnimation.md) docs and reclassified the old clan-only animation note as a historical alias.
- Do not migrate `RankingDialog.cpp`, `RankingEventListPane.cpp`, or `RankingUserListPane.cpp` directly from current emitted source without reassigning the polluted helpers.

Follow-up:

- Decide whether the raw starts in `0x004598b0-0x00459a59`, `0x0045a990-0x0045ac0f`, and `0x0045add0-0x0045ae2b` should become modeled functions or remain documented raw helper bodies.
- Repair generated vtable inventory so `RankingDialog`, `RankingEventScrollPane`, `RankingEventListPane`, `RankingRewardInfoDialog`, and `RankingUserListPane` record their IDA-confirmed vtable bases instead of `vtable_count: 0`.
- Keep the four documented ranking adjustor-thunk ranges ignored as compiler glue even if generated output starts emitting both thunk bodies.
- Repair or explicitly classify the missing active `OnMouseEvent`, hit-test, and drag-to-position bodies at `0x00459a60`, `0x0045a400`, and `0x0045ac10`.
- Reassign the WebBoard, Exchange, popup/menu, animation, and drawing helpers currently emitted through ranking owners. Treat `0x0049eac0-0x0049f07e` as `DialogPane` shared animation code unless later source evidence proves a separate utility file.
- Re-enable or explicitly document the disabled/missing `RankingCategoryRecord` helpers if they remain part of the projected source layout, including packed date/time setters `0x0045c050`/`0x0045c100` and user-entry append helper `0x0045c1e0`.
- Re-enable or explicitly document the missing `RankingCategoryCollection` parser/helper methods and reconcile constructor initialization with the IDA-confirmed three-pointer constructor body.
- Re-enable or explicitly document the missing `RankingRewardInfoDialog` packet/parser/storage helper methods in generated source, especially `0x0045ddd0`, `0x0045d7e0`, `0x0045eae0`, `0x0045ec50`, `0x0045ef50`, `0x0045f020`, `0x0045f160`, `0x0045f1d0`, `0x0045f290`, and `0x0045f300`.

### 2026-05-24 - ExchangeDialog source data omits helpers and includes non-IDA starts

Observed:

- IDA MCP confirms `0x004ad320-0x004ad7b2` as the main exchange server packet dispatcher for opcode `0x42`, but current `class_ExchangeDialog.cpp` does not emit it.
- IDA MCP confirms additional `ExchangeDialog` helpers at `0x004ada90-0x004adb01`, `0x004add40-0x004ade5e`, and `0x004ade60-0x004adfab`; current emitted source omits them.
- Wave3 lists `ExchangeDialog::OnExchangePacket` at `0x004adca0`, but IDA reports `Not a function`; raw bytes still form a complete money-update helper ending at `0x004add33`.
- Wave3 lists `ExchangeItemListPane::ExchangeItemListPane` at `0x004ae060`, but IDA reports `Not a function`; raw bytes form a complete constructor ending at `0x004ae0a3`.
- Raw exchange item-list helpers at `0x004ae0b0-0x004ae166` and `0x004ae170-0x004ae1ab` look valid by prologue/return/data layout, but IDA has no function objects or xrefs for those starts.

Expected:

- The omitted IDA-confirmed exchange helpers should be imported, owned, or explicitly excluded before migrating `ExchangeDialog.cpp`.
- Raw non-IDA starts should be marked as projected/raw-code starts, or the IDA function table should be corrected if these are real functions.

Impact:

- New [ExchangeDialog](by-file/ExchangeDialog.md) docs use IDA-confirmed functions plus explicit raw-code caveats.
- Do not migrate the exchange source directly from current emitted `.cpp` files without manually accounting for the omitted dispatcher and alert helpers.

Follow-up:

- Review whether `0x004adca0` duplicates the money case inside `0x004ad320` or should become a separate owned helper.
- Decide whether `0x004ae0b0` and `0x004ae170` are vtable-only `ExchangeItemListPane` methods, dead helpers, or missing xref artifacts.

2026-05-26 IDA/simroot follow-up:

- Current `simroot_v2` still omits the IDA-confirmed exchange helpers at `0x004ad320`, `0x004ada90`, `0x004add40`, and `0x004ade60`.
- Current `simroot_v2` still emits the raw `0x004adca0-0x004add33` money-update body as active `ExchangeDialog::OnExchangePacket`; IDA still reports no function object or xrefs at `0x004adca0`.
- Current `simroot_v2` still emits the raw `0x004ae060-0x004ae0a3` constructor as active, but does not emit the raw upsert/find helpers at `0x004ae0b0-0x004ae166` and `0x004ae170-0x004ae1ab`.
- IDA raw-byte recheck corrected the upsert helper end: a reachable duplicate-row removal block lives at `0x004ae156-0x004ae166`, after the first epilogue path.
- IDA confirms `ExchangeMoneyEditControlPane` has two destructor adjustor thunks, `0x004b0ab5` and `0x004b0ac0`; current disabled `class_ExchangeMoneyEditControlPane.cpp.disabled` only emits the second one.
- IDA confirms item-dialog vtable bases for `AddItemDialog` (`0x00619e8c`, `0x00619eec`, `0x00619f1c`), `AddItemWithCountDialog` (`0x00619fec`, `0x0061a04c`, `0x0061a07c`), `MixItemDialog` (`0x0061a088`, `0x0061a0e8`, `0x0061a118`), and `AddMixingItemDialog` (`0x0061a124`, `0x0061a184`, `0x0061a1b4`). Current `simroot_v2` metadata for all four checked classes still reports `vtable_count: 0`.
- Added exact anchors for [Exchange packet dispatcher](by-memory/0x004ad320-0x004ad7b2.ExchangeDialogPacketDispatcher.md), [Exchange add-item-with-count helper](by-memory/0x004ada90-0x004adb01.ExchangeDialogAddItemWithCountHelper.md), [Exchange raw money update](by-memory/0x004adca0-0x004add33.ExchangeDialogRawMoneyUpdate.md), [Exchange cancel alert helper](by-memory/0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper.md), [Exchange ready alert helper](by-memory/0x004ade60-0x004adfab.ExchangeDialogReadyAlertHelper.md), [Exchange item-list raw constructor](by-memory/0x004ae060-0x004ae0a3.ExchangeItemListPaneRawConstructor.md), [Exchange item-list raw upsert helper](by-memory/0x004ae0b0-0x004ae166.ExchangeItemListPaneRawUpsertHelper.md), [Exchange item-list raw find helper](by-memory/0x004ae170-0x004ae1ab.ExchangeItemListPaneRawFindHelper.md), [ExchangeMoney adjustor thunks](by-memory/0x004b0ab5-0x004b0acb.ExchangeMoneyEditControlPaneAdjustorThunks.md), and [generic string append helper / false starts](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md).
- Added [Item dialog vtable family](by-type/by-vtable/ItemDialogVtableFamily.md) and wired it into [ItemDialogs](by-file/ItemDialogs.md), the item exchange/mix memory page, the affected class docs, the mix callback page, and the proposed source tree.

### 2026-05-23 - Terminal/phone dialog helpers have unowned and polluted ownership

Observed:

- IDA MCP confirms real terminal helper functions at `0x0058b130-0x0058b44b` and `0x0058b620-0x0058b64e`, but `python source-3\wave3d.py show method 0x0058b130 --summary` and `show method 0x0058b620 --summary` both report `Unknown method`.
- IDA MCP confirms a real modem response parser at `0x0058da20-0x0058db94`, but `show method 0x0058da20 --summary` reports `Unknown method`.
- IDA MCP confirms `0x0058dbe0-0x0058dbea` and `0x0058dcb0-0x0058dcd2` as real helper functions in the local terminal/phone thunk neighborhood, but Wave3 does not currently model them.
- `PhoneBookDialog::OnCommand` currently emits phone-list helper calls through `ChattingColorListPane` and delete/list helpers through `ArticleListPane`.
- `show method 0x0058cfa0 --summary` owns the selected-entry text helper as `ChattingColorListPane::GetSelectedEntryData`, even though the address is inside the phone-book neighborhood and the confirmed caller is `PhoneBookDialog::OnCommand`.

Expected:

- Terminal byte-stream and reconnect/leave callback helpers should be owned by `TerminalPane` or neutral file-local helpers.
- Phone-book selected-entry/list helpers should be owned by `PhoneBookDialog.cpp`, `PhoneBookListPane`, or a neutral list helper, not chat/color or article UI unless a shared base helper is proven.
- Real helper starts in the terminal/phone neighborhood should be imported, owned, excluded, or explicitly recorded as unresolved.

Impact:

- New [TerminalPane](by-file/TerminalPane.md) and [PhoneBookDialog](by-file/PhoneBookDialog.md) docs use IDA-confirmed boundaries and treat the affected helpers as cleanup targets.
- Do not migrate `ChattingColorListPane::GetSelectedEntryData` as chat code without reviewing phone-book caller/data flow.

Follow-up:

- Import or assign `0x0058b130`, `0x0058b620`, and `0x0058da20` after naming review.
- Review `0x0058cfa0` callers and re-own it if it is phone-list-specific.
- Decide whether `0x0058dbe0` and `0x0058dcb0` are class helpers, global helpers, or compiler/runtime glue.

2026-05-24 follow-up:

- IDA `xrefs_to 0x0058cfa0` reports only one direct caller, `PhoneBookDialog::OnCommand` at `0x0058cd8c`; new [PhoneBookListHelpers_58cfa0_58dcb0](by-item/PhoneBookListHelpers_58cfa0_58dcb0.md) treats this as phone-book-specific owner pollution.
- IDA decompilation of `0x0058dcb0` shows a varargs formatted wide write wrapper; direct xrefs include `PhoneBookDialog::SavePhoneBook` at `0x0058ce94` and `0x0058cea6`, plus raw refs in the phone-list rendering neighborhood.
- IDA `xrefs_to 0x0069bdf8` supports [g_pTerminalPane](by-global/g_pTerminalPane.md) as the terminal singleton consumed by phone-entry/dial dialogs and cleared by `0x0058dbe0` / `0x0058dc60`.

2026-05-26 IDA/simroot follow-up:

- Current `simroot_v2/class_TerminalPane.cpp` still omits the IDA-confirmed terminal stream parser at `0x0058b130-0x0058b44b` and reconnect/leave callback at `0x0058b620-0x0058b64e`.
- Current `simroot_v2/class_DialDialog.cpp` still omits the IDA-confirmed modem response parser at `0x0058da20-0x0058db94`.
- Current `simroot_v2/class_PhoneBookListPane.cpp` now emits `0x0058cfa0-0x0058cfdb` as `PhoneBookListPane::GetSelectedEntryData`, but `PhoneBookDialog::OnCommand` still calls the helper through a polluted `ChattingColorListPane` cast and uses an `ArticleListPane` cast for delete/list helpers.
- IDA MCP confirms `0x0058b130` and `0x0058da20` are data/vtable callback targets with refs at `0x0062da80` and `0x0062ddb4`, not ordinary direct calls.
- IDA MCP confirms `0x0058b620` is referenced from `TerminalPane::OnDisconnect` callback construction at `0x0058b56d`.
- IDA MCP confirms `0x0058dbe0-0x0058dbea` is constructor EH/unwind cleanup that clears `g_pTerminalPane`, and `0x0058dbeb-0x0058dc00` / `0x0058dc01-0x0058dc16` are destructor adjustor thunks for `DialDialog` and `TerminalPane`.
- Added exact anchors for [TerminalPane stream parser](by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md), [TerminalPane reconnect/leave callback](by-memory/0x0058b620-0x0058b64e.TerminalPaneReconnectLeaveCallback.md), [PhoneBook selected-entry helper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md), [DialDialog modem response parser](by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md), [TerminalPane singleton clear EH helper](by-memory/0x0058dbe0-0x0058dbea.ClearTerminalPaneSingletonEH.md), [PhoneBook formatted write helper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md), [DialDialog adjustor thunks](by-memory/0x0058dbeb-0x0058dc00.DialDialogAdjustorThunks.md), and [TerminalPane adjustor thunks](by-memory/0x0058dc01-0x0058dc16.TerminalPaneAdjustorThunks.md).

### 2026-05-23 - ProfileDialog has an unmodeled helper and base-destructor owner pollution

Observed:

- IDA MCP confirms `0x0053fda0-0x0053fdbe` as a real function inside the `ProfileDialog` core, between constructor `0x0053f940` and action handler `0x0053fdc0`, but `python source-3\wave3d.py show method 0x0053fda0 --summary` reports `Unknown method`.
- Current `class_ProfileDialog.cpp` emits the scalar deleting destructor with a call labeled `TransferReplyAlert::~DialogPane`, even though the class is a profile dialog and constructor evidence flows through `DialogPane`.
- The older by-memory documentation used a broad `0x0053f2c0-0x00542735.FriendListDialog.md` range that crossed into `ProfileDialog`; documentation has now been split, but the underlying owner/thunk island should still be reviewed before migration.

Expected:

- `0x0053fda0` should be owned, explicitly excluded, or marked as a file-local profile dialog helper.
- Base destructor labels should use the real base teardown or a neutral unresolved name until ownership is proven.
- FriendListDialog and ProfileDialog ranges should remain separate in memory and ownership migration.

Impact:

- New [ProfileDialog](by-file/ProfileDialog.md) docs use IDA-confirmed boundaries and record the helper/destructor caveat before source migration.

Follow-up:

- Review `0x0053fda0` bytes/xrefs and decide whether it is a vtable/setup helper or should be merged into the constructor model.
- Reconcile `ProfileDialog` destructor base-owner labels with the underlying `DialogPane` teardown target.

2026-05-24 follow-up:

- IDA MCP decompilation shows `0x0053fda0` is a non-deleting destructor helper, not ordinary setup logic: it restores the three `ProfileDialog` vtables and calls shared base teardown helper `0x0049d9f0`. `xrefs_to 0x0053fda0` reports no direct xrefs.
- IDA decompilation of `0x005429a0` shows the same vtable restore/base teardown pattern before conditional delete. Thunks `0x00542639` and `0x00542644` forward to it from secondary vtable offsets.
- IDA confirms `0x0053fe90-0x0053fe9a` as a tiny wrapper around `RefreshSelectedProfileData` at `0x005063e0`; new [ProfileDialogDestructorAndRefreshHelpers_53fda0_53fe90](by-item/ProfileDialogDestructorAndRefreshHelpers_53fda0_53fe90.md) and [ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md) document the cleanup/refresh split.
- The generated `TransferReplyAlert::~DialogPane` label should be treated as base-owner pollution; keep the helper island with `ProfileDialog.cpp` and the real sidecar refresh implementation with `ProfileStorage.cpp`.

### 2026-05-23 - TransferServerDialogPane has destructor/helper modeling caveats

Observed:

- IDA MCP confirms `0x00599220-0x00599248` as a real non-deleting destructor helper for `TransferServerDialogPane`, but `python source-3\wave3d.py show method 0x00599220 --summary` reports `Unknown method`.
- IDA MCP confirms helper/thunk starts at `0x005993b0`, `0x005993bb`, and `0x005993c6`; `show method 0x005993b0 --summary` reports `Unknown method`.
- Current generated destructor source calls `TextButtonExControlPane::~Pane(this)` even though the constructor begins with `Pane::Pane(3)` and the class is an animated overlay pane.

Expected:

- The non-deleting destructor helper and adjustor thunk island should be owned, explicitly excluded, or consistently omitted with metadata.
- Base teardown should be named through the real pane base or a neutral unresolved helper rather than a text-button owner.

Impact:

- New [TransferServerDialogPane](by-file/TransferServerDialogPane.md) docs use IDA-confirmed boundaries and flag the destructor/helper caveats before source migration.

Follow-up:

- Review vtable refs around `0x00609c11` and helper calls around `0x005993b0-0x005993e0`.
- Reconcile the base destructor target and update generated source labels.

2026-05-24 follow-up:

- IDA MCP decompilation shows `0x00599220` and `0x005993e0` both restore the `TransferServerDialogPane` vtables, clear [g_pTransferServerDialog](by-global/g_pTransferServerDialog.md) at `0x0069b4b0`, and call base teardown helper `0x00544580`; this supports treating generated `TextButtonExControlPane::~Pane` as base-owner pollution.
- `0x005993b0` is a pure singleton-clear helper, while `0x005993bb` and `0x005993c6` are adjustor thunks into `0x005993e0` with vtable/data refs at `0x0062e4cc` and `0x0062e4fc`.
- New [TransferServerDialogPaneThunks_599220_5993e0](by-item/TransferServerDialogPaneThunks_599220_5993e0.md) keeps the helper island with `TransferServerDialogPane.cpp`.

### 2026-05-23 - ServerSelectPane has projected constructor and helper-owner pollution

Observed:

- Wave3 records `ServerSelectMenuItemList` constructor range `0x005744a0-0x005744f7`, but IDA MCP reports no function at `0x005744a0`.
- IDA MCP confirms real server-selection helper `0x00574510-0x0057454d`, called from `ServerSelectPane::OnDialogAction`, but Wave3 currently owns it as `ChattingColorListPane::ApplySelectedColor`.
- IDA MCP confirms helper `0x005745b0-0x0057465d`, called by the `0x00574510` helper, but `show method 0x005745b0 --summary` reports `Unknown method`.
- IDA MCP confirms `0x00574310-0x00574338` as a non-deleting destructor-like helper for `ServerSelectPane`, but Wave3 does not currently model it as a method.

Expected:

- `0x005744a0` should be marked projected/non-function or realigned to IDA-confirmed code if later evidence supports it.
- Server-selection helpers should be owned by `ServerSelectPane.cpp` or neutral file-local helpers, not by chat/color UI.
- The destructor-like helper at `0x00574310` should be owned, explicitly excluded, or documented as an unresolved compiler helper.

Impact:

- New [ServerSelectPane](by-file/ServerSelectPane.md) docs use IDA-confirmed boundaries and flag helper ownership before source migration.
- Do not move `ChattingColorListPane::ApplySelectedColor` as chat code without first reviewing the `0x00574510` server-select caller/data flow.

Follow-up:

- Review bytes/xrefs around `0x005744a0` and either delete, mark, or realign the projected constructor.
- Reassign or rename `0x00574510` and import/assign `0x005745b0` if server-select ownership is confirmed.
- Decide whether `0x00574310` should be a modeled non-deleting destructor for `ServerSelectPane`.

2026-05-24 follow-up:

- IDA MCP `xrefs_to 0x00574510` reports only two code xrefs, both from `ServerSelectPane::OnDialogAction` at `0x00574399` and `0x005743db`; new [ServerSelectHelpers_574510_5745b0](by-item/ServerSelectHelpers_574510_5745b0.md) treats it as server-selection owner pollution, not chat-color code.
- IDA decompilation of `0x00574510` copies the selected server name into the config/current-server buffer and calls `0x005745b0`; `0x005745b0` sends the `0x57` select-server packet and stores selected endpoint/session state.
- IDA `xrefs_to 0x0069b4ac` supports [g_pServerSelectPane](by-global/g_pServerSelectPane.md) as the active server-select singleton touched by main-menu cleanup/startup and the constructor/destructor family.

### 2026-05-23 - Spell menu generated source has remaining owner-name pollution

Observed:

- `source-3/simroot_v2/class_ClientSpellMenuDialog.cpp` emits `ClientSpellMenuDialog::UpdateActionButtonState` with the spell list typed as `ChattingColorListPane*`.
- The function behavior and IDA boundary are spell-menu specific: it fetches child slot `6`, counts enabled entries in the spell list, and enables/disables the action button.
- Existing Wave2 report notes mention prior wrong wrapper aliases involving `ClientSpellMenuItemList` and `ServerSpellMenuItemList`; the current list classes are now documented by behavior, but the dialog source still carries a chat owner label in a local type.

Expected:

- Spell-list local/state types should use neutral spell-menu names or the actual `ClientSpellMenuItemList` owner.
- Chatting/color list owner names should not appear in spell-menu source unless a real shared base/helper relationship is proven.

Impact:

- New [SpellMenuDialogs](by-file/SpellMenuDialogs.md) docs treat the generated source as behavior evidence but do not trust the `ChattingColorListPane` type label.
- Source migration should avoid importing chat owner names into spell-menu headers or class layouts.

Follow-up:

- Rename or neutralize the polluted local spell-list type in `ClientSpellMenuDialog::UpdateActionButtonState`.
- Recheck spell-menu generated source after any owner/type cleanup around list-pane shared helpers.

2026-05-24 follow-up:

- IDA MCP decompilation of `0x0051d6c0` and `0x0051e600` confirms both spell-menu action-button-state helpers fetch child slot `1` as the action button and child slot `6` as the spell list, then call the enabled-entry count helper before dispatching the action-button enable/disable virtual.
- IDA decompilation of `0x0051e640` and `0x0051e890` confirms `ClientSpellMenuItemList` vtable setup/context fields and row text from `entry + 4`, supporting the client spell-list owner over the generated `ChattingColorListPane*` local type.
- `xrefs_to 0x00482fb0` for the real `ChattingColorListPane` constructor reports only chat-color pane callers at `0x00482837` and `0x0048295d`; new [SpellMenuActionButtonState_51d6c0_51e600](by-item/SpellMenuActionButtonState_51d6c0_51e600.md) records this caveat for migration.

### 2026-05-23 - Object image controls have destructor-thunk and base-owner caveats

Observed:

- `ObjectImageControlPane` has excluded Wave3 thunk methods at `0x00520afd` and `0x00520b08`; IDA MCP confirms both as real adjustor thunks forwarding to `0x00520ca0`.
- `ObjectImageButtonPane` has its own adjustor thunks at `0x00520ae7` and `0x00520af2`, but the old documentation range `0x00520ae7-0x00520c9a` also contained functions owned by `ObjectImageControlPane`, `ClientItemMenuItemList`, and other nearby classes.
- Generated destructors for `ObjectImageControlPane` and `ObjectImageButtonPane` name `TextButtonExControlPane`/`Pane` teardown paths even though constructor evidence flows through `ControlPane` and `ObjectImageControlPane`.

Expected:

- Compiler adjustor thunks should be represented as explicit excluded thunk rows or omitted consistently from emitted source.
- Destructor/base-owner labels should use shared pane-base teardown helper `0x00544580`, not the polluted `TextButtonExControlPane`/`Pane` labels currently emitted in generated source.
- Documentation and migrations should use IDA-confirmed discontiguous ranges rather than claiming the whole `0x00520ae7-0x00520c9a` span for `ObjectImageButtonPane`.

Impact:

- New [ObjectImageControlPane](by-file/ObjectImageControlPane.md) docs use IDA-confirmed ranges and record the shared pane-base teardown path.
- Source migration should not infer that these object-image controls derive from `TextButtonExControlPane` solely from current generated destructor labels.
- 2026-05-24 IDA MCP decompilation resolves the destructor/base path: `0x00520c60` and `0x00520ca0` both call shared pane-base teardown helper `0x00544580`, then conditionally call delete helper `0x004f4ac0`.
- `ObjectImageButtonPane` should now be grouped with [ObjectImageControlPane](by-file/ObjectImageControlPane.md), or an adjacent sibling source file, rather than kept in the generic [SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) bucket.

Follow-up:

- Retag generated destructor labels that currently name `TextButtonExControlPane`/`Pane` for `ObjectImageControlPane` and `ObjectImageButtonPane`; the verified call target is the shared pane-base helper at `0x00544580`.
- Remove or retag generic `SpecializedButtonPanes.cpp` ownership for `ObjectImageButtonPane` in generated/projected source metadata unless later source-file evidence proves a separate original file.
- Keep thunk rows discontiguous and owner-specific in memory docs.

### 2026-05-24 - Specialized button constructor starts and owner rows need reconciliation

Observed:

- `GenderButtonControlPane` has a generated method row at `0x004fb630-0x004fbfcf`, but IDA MCP confirms that range is `NewUserMiscDialogPane::NewUserMiscDialogPane`, not a gender-button method.
- Wave3 treats `GenderButtonControlPane::GenderButtonControlPane` at `0x00500640` and `DirectionButtonControlPane::DirectionButtonControlPane` at `0x005007a0` as constructor ranges, but IDA MCP reports no function, callers, or xrefs at either start.
- IDA MCP confirms the real virtual methods/destructors are vtable-referenced: `GenderButtonControlPane` uses `0x005006d0`, `0x00500700`, and deleting destructor `0x00502700`; `DirectionButtonControlPane` uses `0x005007f0`, `0x00500820`, and deleting destructor `0x005026a0`.
- `NewUserMiscDialogPane::NewUserMiscDialogPane` inlines setup for gender-button and direction-button child controls, explaining the generated child-vtable associations.
- 2026-05-26 follow-up: IDA MCP vtable/layout review confirms the class behavior and fields, but also confirms the adjustor thunks at `0x0050248a`, `0x00502495`, `0x005024a0`, and `0x005024ab` are compiler-generated vtable glue rather than standalone handwritten methods.
- 2026-05-27 follow-up: IDA MCP still reports `0x00500640` and `0x005007a0` as `NOFUNC` with no xrefs, and a raw dword scan across loaded segments found no pointers to either projected constructor start. The same raw scan found no dword pointer hits for `0x004fb630`; that range remains confirmed by its code caller `0x004fa74e` and decompiled parent-dialog body, not by gender-button ownership.

Expected:

- Parent-dialog constructors should stay under the parent class even when they write child-control vtables.
- Non-IDA constructor ranges should be marked projected/inline-only until a callable function boundary is proven.
- Specialized button docs should use vtable-referenced virtual methods/destructors for class behavior evidence.
- Destructor adjustor thunks should be suppressed or marked as compiler-generated glue during source reconstruction.

Impact:

- Updated [GenderButtonControlPane](by-class/GenderButtonControlPane.md), [DirectionButtonControlPane](by-class/DirectionButtonControlPane.md), [SpecializedButtonPanes](by-file/SpecializedButtonPanes.md), [specialized button memory](by-memory/0x00500640-0x00502754.SpecializedButtonPanes.md), [SpecializedButtonPane layouts](by-type/by-struct/SpecializedButtonPaneLayouts.md), and [SpecializedButtonPane vtables](by-type/by-vtable/SpecializedButtonPaneVtables.md) docs keep `0x004fb630` under `NewUserMiscDialogPane`, mark `0x00500640`/`0x005007a0` as unproven starts with no raw pointer hits, and record the real field/vtable evidence.

Follow-up:

- Remove or retag the generated `0x004fb630` gender-button owner row.
- Decide whether projected constructor ranges `0x00500640` and `0x005007a0` should remain as non-function inline setup notes, be excluded, or be backed by manually created IDA/Wave3 function boundaries after byte-level review. Current IDA evidence does not show typed xrefs or untyped raw pointers to either address.
- Keep `0x0050248a-0x005024b6` out of handwritten source output except as compiler-generated adjustor thunk artifacts.

### 2026-05-23 - Argumented item input helper ownership has unowned and false-start caveats

Observed:

- IDA MCP confirms `0x0051f510-0x0051f5a5` as a real function that sends quantity `1` directly or opens `ArgumentedItemQuantityInputDialogPane`, but `python source-3\wave3.py show method 0x0051f510 --summary` reports `Unknown method: 0x0051f510`.
- `ShowBuyConfirmDialog` at `0x0051f450` is currently owned by `ChattingColorListPane`, but its behavior creates `ArgumentedItemConfirmInputDialogPane` from selected argumented menu entry fields.

Expected:

- `0x0051f510` should be imported/owned or explicitly recorded as an unowned helper.
- `0x0051f450` ownership should be reviewed before migrating `ChattingColorListPane` or argumented menu/input files.

Impact:

- New [ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md) docs treat the helper ownership as under review and use IDA MCP for boundaries.
- Do not run ownership migrations for this cluster until `0x0051f510` and `0x0051f450` are reconciled.

Follow-up:

- Add or assign `0x0051f510` as a file-local argumented item purchase helper.
- Move or mark `0x0051f450` as an argumented menu/list helper if caller evidence supports it.
2026-05-24 follow-up:

- IDA MCP `lookup_funcs` confirms `0x0051f450`, `0x0051f510`, and `0x0051f640` as real functions with sizes `0xae`, `0x95`, and `0xc6`.
- IDA MCP `xrefs_to 0x0051f450` and `xrefs_to 0x0051f510` reports no direct xrefs in the current IDB, but both decompile as argumented item purchase helpers. Treat them as retained or indirectly reached helper paths until raw caller provenance is resolved.
- IDA MCP `xrefs_to 0x0051f640` reports calls from `0x0051f504`, `0x0051f58d`, `0x0052008e`, and `0x00520501`, covering direct helper dispatch plus the quantity/confirm input-dialog handlers.
- New [ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md) records the ownership decision: keep these with `ArgumentedItemInputDialogs.cpp` or folded `ArgumentedMenuDialogs.cpp`, not with `ChattingColorListPane`.

2026-05-25 Wave3 tool follow-up:

- `show memory-at 0x0051f510 --include-ignored --include-allowed` now reports `lower_layer_matches.prewave_functions` for the uncovered prewave function `0x0051f510-0x0051f5a4` and links to `show prewave-function`, `show xref`, `show decomp`, and add/classify memory-range commands.
- This fixes discoverability of the lower-layer evidence from memory coverage views. It does not import or assign `0x0051f510`; the helper still needs a Wave3 method/global ownership decision before source migration.

### 2026-05-23 - Text/argumented menu metadata has helper/thunk and non-function caveats

Observed:

- Wave3 lists an `ArgumentedMenuMenuItemList` method at `0x0051f310`, but IDA MCP reports no function and no name at that address.
- IDA confirms vtable adjustor thunks for the text-menu family that are absent or unevenly represented in current emitted class files: `TextInputMenuDialog` thunks at `0x00520b29`/`0x00520b34`, `TextMenuDialog` thunks at `0x00520b3f`/`0x00520b4a`, `TextMenuItemList` thunks at `0x00520b55`/`0x00520b60`, and `ArgumentedMenuMenuItemList` thunks at `0x00520abb`/`0x00520ac6`.
- Current generated source has useful class behavior, but file-level documentation for this cluster must rely on IDA-confirmed function boundaries for excluded thunks and the `0x0051f310` non-function entry.

Expected:

- Wave3 metadata should either remove or clearly mark `0x0051f310` as a non-function/projection artifact.
- Emitted source should consistently include explicit omitted-body markers for excluded but known vtable helper/thunk functions, or consistently keep them out of source while exposing them through class/memory docs.

Impact:

- New [TextMenuDialogs](by-file/TextMenuDialogs.md), [Text menu memory](by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md), and [Argumented menu memory](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md) docs use IDA MCP as boundary authority.
- Do not migrate these classes solely from emitted `.cpp` text without accounting for the destructor/thunk island and the `0x0051f310` metadata caveat.

Follow-up:

- Reconcile or remove the `0x0051f310` `ArgumentedMenuMenuItemList` method entry.
- Decide whether compiler thunks should be represented as omitted source markers or only in metadata, then apply the policy consistently for this cluster.

2026-05-25 Wave3 tool follow-up:

- `list memory-range method 0x0051f310` reports the current excluded Wave3 method range `0x0051f310-0x0051f37b`.
- `show memory-at 0x0051f310 --include-ignored --include-allowed` now surfaces that targeted Wave3 range through `address_index_source: targeted_entity_range_fallback` and also reports the lower prewave function evidence. This fixes the address-lookup inconsistency; it does not resolve the IDA boundary caveat or decide whether the method entry should remain.

### 2026-05-23 - Popup/menu pane source data has omitted helper/thunk bodies

Observed:

- Wave3 class inspection lists active helper/thunk methods for `PopupMenuControlPane`, `MenuPane`, `RightButtonMenuPane`, `MenuVarietyPane`, and `MenuVarietySelectPane` that are IDA-confirmed but missing from current emitted source files.
- Examples include `PopupMenuControlPane` helper `0x0049af95`, `MenuPane` helpers `0x005172be` and `0x005172c9`, `RightButtonMenuPane` helpers `0x00556212` and `0x0055621d`, `MenuVarietyPane` helpers `0x005bc660`, `0x005bc880`, `0x005bfc0b`, and `0x005bfc16`, and `MenuVarietySelectPane` helpers `0x005bfbd0` and `0x005bfc21`.
- The long template callback helper source exists as `class_PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.cpp` and IDA confirms `0x0049af00-0x0049af11`, but exact class-name lookup with the displayed C++ template name timed out.

Expected:

- Emitted menu source files should either include active helper/thunk methods or explicit omitted-body markers.
- Complex template helper classes should have a stable searchable display name or alias.

Impact:

- New menu docs use IDA-confirmed ranges for ownership and explicitly include omitted helpers in memory pages.
- Do not migrate the menu files directly from emitted C++ text without accounting for the missing tiny helpers/thunks.

Follow-up:

- Re-emit or mark omitted helper/thunk methods in the affected menu source files.
- 2026-05-24 follow-up: added [PopupMenuSelectionCallback](by-item/PopupMenuSelectionCallback_0049AF00.md) as the short alias for the `0x0049af00` helper, so agents do not need to query the full C++ template display name.

2026-05-26 menu item vtable/layout follow-up:

- Added [menu item vtables](by-type/by-vtable/MenuItemVtables.md) and [menu item layouts](by-type/by-struct/MenuItemLayouts.md) after IDA resolved decorated vtable symbols for `MenuItem` (`0x0061eb98`), `StringMenuItem` (`0x0061ebb4`), and `SeparatorMenuItem` (`0x0061ebd0`).
- Current `source-3/simroot_v2/class_MenuItem.meta_wave3`, `class_StringMenuItem.meta_wave3`, and `class_SeparatorMenuItem.meta_wave3` still report `vtable_count: 0` despite constructor/destructor writes and vtable slot data refs in IDA.
- IDA confirms `StringMenuItem` text storage begins at byte offset `+0x18` and is copied with capacity `0x80` wide characters. Generated source is behaviorally useful here, but metadata should expose the vtable/layout evidence before source migration.

### 2026-05-23 - System message pane source data has emitted-body caveats

Observed:

- `OldSystemMessagePane::OldSystemMessagePane` at `0x00588e30` is listed by Wave3 class inspection and confirmed by IDA MCP as `0x00588e30-0x00589173`, but current `class_OldSystemMessagePane.cpp` omits its body.
- Active tiny virtual/helper/thunk methods for `SystemMessagePane`, `NewSystemMessagePane`, and `OldSystemMessagePane` are listed by Wave3 and confirmed by IDA, but not emitted in their current generated files.
- `NewSystemMessagePane::NewSystemMessagePane` at `0x00588560` is IDA-confirmed and owns `g_pNewSystemMessagePane`, but active `class_NewSystemMessagePane.cpp` omits it while active `class_NewSystemMessageModifyHeightPane.cpp` emits the constructor body.
- `NewSystemMessageModifyHeightPane` active output omits IDA-confirmed non-deleting cleanup `0x005882c0` and singleton clear helper `0x0058aaa0`.
- Active `class_ColorStringSystemMessage.cpp` emits `GetLineCount` at `0x00587ae0` as a no-argument constant `1` helper, but IDA decompilation shows the method structurally calls helper `0x004bb070(text, wcslen(text), width)` and clamps the result to at least one line.
- IDA decompilation of `0x004bb070` itself currently returns constant `1`, so the generated `GetLineCount` body is behaviorally equivalent but loses the helper-call/source-structure shape.
- `HeaderSystemMessage` and `FooterSystemMessage` vtables use shared tiny boolean helpers at `0x0055c1b0` and `0x0055c1c0`; active generated files do not expose those slots under the marker classes.

Expected:

- System-message pane docs should separate confirmed function boundaries from source-body availability.
- Source migration should not assume the generated files are complete just because class inspection reports high grades.
- `0x00588560` should be represented as `NewSystemMessagePane` constructor ownership, not as part of `NewSystemMessageModifyHeightPane`.
- `ColorStringSystemMessage::GetLineCount` should either preserve the `0x004bb070` helper-call shape or explicitly document that the helper currently returns one; it should not be described as a recovered wrapped-text counter unless that helper changes.

Impact:

- New `SystemMessagePanes` docs use IDA-confirmed ranges for ownership and mark emitted-source omissions as caveats.
- Do not migrate the old/new/current system-message pane files directly from emitted C++ text without adding the missing methods manually or fixing Wave3 emission.
- New [ColorStringSystemMessage](by-class/ColorStringSystemMessage.md), [HeaderSystemMessage](by-class/HeaderSystemMessage.md), [FooterSystemMessage](by-class/FooterSystemMessage.md), [NewSystemMessageModifyHeightPane](by-class/NewSystemMessageModifyHeightPane.md), [g_pHeightModifyPane](by-global/g_pHeightModifyPane.md), and [g_pNewSystemMessagePane](by-global/g_pNewSystemMessagePane.md) docs capture the corrected class/global ownership.
- Added [ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md) to pin the current helper behavior.

Follow-up:

- Re-emit or reconstruct `OldSystemMessagePane::OldSystemMessagePane`.
- Add explicit emitted stubs/markers or real bodies for the missing tiny virtual helpers and destructor thunks.
- Repartition `0x00588560` into `class_NewSystemMessagePane.cpp` and recheck `class_NewSystemMessageModifyHeightPane.cpp` after fixes.
- Re-emit or correct `ColorStringSystemMessage::GetLineCount` at `0x00587ae0`, preserving the current helper-call shape if source fidelity is desired.

2026-05-25 follow-up:

- Current `source-3/simroot_v2/class_ColorStringSystemMessage.cpp` still emits `GetLineCount` at `0x00587ae0` as `return 1u`; IDA decompiles it as a call to `0x004bb070(text, wcslen(text), width)` clamped to at least one line, and `0x004bb070` itself decompiles to `return 1`.
- Current `source-3/simroot_v2/class_NewSystemMessageModifyHeightPane.cpp` still emits `NewSystemMessagePane::NewSystemMessagePane` at `0x00588560`; IDA confirms the constructor is directly called from `GeneralPurposePanel2` construction at `0x004b88ae`, writes `g_pNewSystemMessagePane`, and creates the height handle, `SpelledPane`, and child `SystemMessagePane`.
- Current `source-3/simroot_v2/class_OldSystemMessagePane.cpp` still has only an omitted-body marker for constructor `0x00588e30`; IDA confirms a direct caller from the legacy main UI graph path at `0x004f8861`.
- IDA decompiles `0x005882c0`, `0x0058aaa0`, and `0x0058aab0` as singleton cleanup paths for `g_pHeightModifyPane` and `g_pNewSystemMessagePane`, supporting the existing system-message ownership docs.

### 2026-05-23 - Message/menu dialog source data has materialization caveats

Observed:

- `class_MessageDialog.cpp` currently contains placeholder `...` expressions in emitted source for packet offsets/resource arguments.
- `class_MenuQuestionDialogLarger.cpp` omits the constructor body for `0x0054fb30`, even though Wave3 class inspection lists the method and IDA MCP confirms `0x0054fb30-0x00550afb` as a real function.
- `MenuQuestionDialog` generated branch comments around `g_useHighResLayout` appear internally suspect and should not be treated as authoritative layout labels without checking asset dimensions/control coordinates.

Expected:

- Generated source used for migration should contain concrete packet offsets/control arguments or explicit unknown markers that do not look like compilable code.
- Class pages and file-layout docs should distinguish IDA-confirmed function boundaries from incomplete generated source bodies.

Impact:

- New `MessageDialogs` docs use IDA-confirmed ranges for boundaries and treat current generated source as behavioral evidence only.
- Do not migrate `MessageDialog` or `MenuQuestionDialogLarger` directly from emitted C++ text until the placeholder/missing-body issues are fixed or manually reconstructed.
- 2026-05-25 IDA MCP recheck partially resolves the `MessageDialog` packet-offset placeholders for documentation, but `simroot_v2` still needs source-generation cleanup before migration.

Follow-up:

- Re-emit or manually reconstruct `MessageDialog::MessageDialog` packet offsets.
- Restore or explain the omitted `MenuQuestionDialogLarger::MenuQuestionDialogLarger` body.
- Verify `g_useHighResLayout` branch labels against real asset/control dimensions.

2026-05-25 follow-up:

- Current `source-3/simroot_v2/class_MessageDialog.cpp` still has omitted placeholder comments for button state words, text length/data, and `LoadDialogResource(...)`.
- IDA decompilation of `0x0054ce10` shows the state words at `packet + objectDescriptorLength + 10` and `packet + objectDescriptorLength + 12`, followed by two boolean flags; the text-bearing branch reads byte length at `packet + objectDescriptorLength + 16` and copies text bytes from `packet + objectDescriptorLength + 18`.
- Current `source-3/simroot_v2/class_MenuQuestionDialogLarger.cpp` still omits constructor `0x0054fb30`, while IDA confirms a full constructor body and caller paths from `HandleDialogPacket_54C200` at `0x0054c2fa`/`0x0054c339` plus wrapper paths at `0x0054c795`/`0x0054c855`.
- IDA decompilation of `HandleDialogPacket_54C200` confirms `packet[1]` bit `0x10` selects the larger dialog family and the low nibble selects message/menu-question variants; this supports keeping the four dialog constructors together in [MessageDialogs](by-file/MessageDialogs.md).

2026-05-26 follow-up:

- Current `simroot_v2` still emits `g_useHighResLayout` in many UI/dialog files. IDA confirms the underlying storage is `byte_66DA97` / [g_useEpfAssets](by-global/g_useEpfAssets.md), a broad EPF/current-layout selector forced to `1` by `StartupWindow::StartupWindow`.
- Treat `g_useHighResLayout` as a generated alias over the same byte, not proof of a separate high-resolution-only global. Branch labels still need asset/control-coordinate review before migration.

### 2026-05-23 - Login/create-user dialog data has naming, ownership, and emitted-body caveats

Observed:

- `inspect class CreateUserDialogPane` lists methods at `0x0052e930`, `0x0052e950`, `0x0052ecc0`, and `0x0052ed00`, but the current `simroot_v2\class_CreateUserDialogPane.cpp` file does not emit bodies or markers for those methods.
- `NewUserDialogPane2` method `0x0052a540` is named `~NewUserDialogPane2` by Wave3 even though its signature is `NewUserDialogPane2::NewUserDialogPane2()` and the generated source is constructor-like.
- `class_NewUserMiscDialogPane.cpp` currently starts with the projected destructor row and omits the IDA-confirmed constructor at `0x004fb630` even though `lookup_funcs 0x004fb630` reports a `0x99f`-byte function and decompilation shows `DLGNEW02.EPD` setup plus vtable installation.
- `NewUserMiscDialogPane::~NewUserMiscDialogPane` is recorded at `0x004fbfd0`, but IDA MCP does not currently define a function there. The bytes are destructor-shaped and the next confirmed method starts at `0x004fc010`, so this should be treated as a boundary caveat until reviewed.
- `class_GenderButtonControlPane.cpp` and related docs previously treated `0x004fb630-0x004fbfcf` as `GenderButtonControlPane` cleanup. IDA confirms that range is `NewUserMiscDialogPane::NewUserMiscDialogPane`; the gender-button association came from child-control vtable writes inside the parent dialog constructor.
- IDA currently names `0x004f9060` as `___std_parallel_algorithms_hw_threads@0_0`, and earlier docs inherited that as a runtime/library classification. A 2026-05-24 IDA MCP decompile shows it allocates `620` bytes and calls `ChangePasswordDialogPane::ChangePasswordDialogPane`, so it is a retained password-change launcher, not library code.
- `NewUserMiscDialogPane::HandleCommand` at `0x004fc010` is a real function of size `0x56e`, but `callers 0x004fc010` currently returns none and `xrefs_to 0x004fc010` only reports vtable/data xref `0x0061d46c`; command dispatch is virtual rather than directly called.
- `ConnStatusPane` inspection lists `SetConnecting`, `SetDisconnected`, and `SetConnected` at `0x00544db0`, `0x00544dc0`, and `0x00544dd0`, but those rows have `owner_file: class_Pane.cpp`, broad base-pane xrefs, and existing Wave2 notes classify the canonical owner as `Pane`.

Expected:

- Method names should match constructor/destructor behavior.
- Class inspection should make canonical-owner versus shadow-owner rows obvious.
- Generated class files should emit all active methods listed by class inspection or clearly mark why a method body is intentionally omitted.
- Projected/non-IDA boundaries should be explicitly marked before source migration.
- Parent-dialog constructors that instantiate child controls should not be imported as child-control methods only because they write child vtables.
- Runtime-looking names should be verified by body behavior before being used for source ownership.

Impact:

- New login/create-user docs treat `0x0052a540` as a constructor despite the current Wave3 display name.
- New `CreateUserDialogPane` docs call out missing emitted bodies before any source migration.
- New `ConnStatusPane` docs keep `0x00544d*` state wrappers under base `Pane` unless further vtable evidence proves otherwise.
- New `NewUserMiscDialogPane` docs add the confirmed `0x004fb630` constructor and still treat `0x004fbfd0` as a boundary caveat.
- New `GenderButtonControlPane` and `SpecializedButtonPanes` docs remove `0x004fb630` from gender-button ownership.
- 2026-05-27 IDA MCP follow-up found no raw dword pointer hits for `0x004fb630`, `0x00500640`, or `0x005007a0`; keep the constructor ownership correction, and keep the gender/direction standalone constructor starts projected pending byte-level review.
- New `OpenChangePasswordDialog_4F9060` docs correct the stale runtime/library classification and keep the helper in the login/main-menu account family.
- 2026-05-26 IDA recheck still finds no code or data refs to `0x004f9060`; keep it as real retained code with weak live reachability.
- 2026-05-27 IDA raw-pointer scan across loaded segments found no dword equal to `0x004f9060`, so no obvious untyped callback table currently points at it.

Follow-up:

- Correct the `0x0052a540` display name to `NewUserDialogPane2::NewUserDialogPane2`.
- Re-emit or explain omitted `CreateUserDialogPane` methods.
- Emit or import `NewUserMiscDialogPane::NewUserMiscDialogPane` at `0x004fb630`.
- Review bytes/xrefs around `0x004fbfd0` and decide whether to create an IDA/Wave3 function boundary or mark it projected.
- Resolve the exact top-level trigger for the `0x004fa0f0 -> 0x004fa5b0 -> 0x004fb630` NewUserMisc construction path.
- Remove or retag the `0x004fb630-0x004fbfcf` `GenderButtonControlPane` owner row from Wave3 data.
- Rename or annotate `0x004f9060` in IDA/Wave3 as `OpenChangePasswordDialog_4F9060` or equivalent to avoid future runtime-helper misclassification.
- Reconcile `ConnStatusPane` shadow method rows with canonical `Pane` ownership.

### 2026-05-23 - Config/GameServerConfig emitted and boundary data has source-layout caveats

Observed:

- `class_RegistryConfig.cpp` emits markers and local structs for `RegistryConfig::SaveToRegistry` at `0x00491b30` and `RegistryConfig::LoadFromRegistry` at `0x004926a0`, but the current emitted file does not contain either method body after the markers.
- Wave3 metadata still grades both methods and `show method --summary` reports valid summaries/signatures, while IDA MCP confirms real functions:
  - `0x00491b30-0x00492695`.
  - `0x004926a0-0x00493e29`.
- `GameServerConfig::InitializeNationEntryTable` is recorded at `0x005039f0`. IDA MCP does not currently define a function there, but disassembly from `0x005039f0-0x00503a41` is valid constructor-like code that installs `GameServerConfig` and `ProtectedArray<GameServerConfig::NationEntry>` vtables and stores the global table pointer.
- IDA shows destructor-like code at `0x00503a50-0x00503a78` in the same local block, but Wave3 does not currently model it as a method.
- `GameServerConfig::CopyNationEntryOrFallback` at `0x00503a80` and `GameServerConfig::RequestNationEntries` at `0x00503c70` are listed by `inspect class GameServerConfig`, but `show method` marks both as `excluded: true` and the emitted `class_GameServerConfig.cpp` does not include their bodies.

Expected:

- Emitted source for non-excluded, graded methods should include the method body or clearly mark body omission as incomplete/stubbed.
- Valid code starts that IDA has not promoted to functions should be marked as boundary caveats rather than silently treated as normal confirmed function starts.
- Excluded methods should not appear as ordinary active class methods without an explicit excluded/inactive signal in class inspection output.

Impact:

- New config/profile docs use IDA-confirmed ranges for `RegistryConfig` ownership but call out the missing emitted bodies before source migration.
- New GameServerConfig docs treat `0x005039f0` as valid code but not an IDA function record, and treat `0x00503a80`/`0x00503c70` as strong behavioral evidence but active/emission caveats.
- Do not bulk-migrate `GameServerConfig` or `RegistryConfig` from emitted source alone until these caveats are resolved or manually accounted for.

Follow-up:

- Restore or re-emit `RegistryConfig::SaveToRegistry` and `RegistryConfig::LoadFromRegistry` bodies in `class_RegistryConfig.cpp`.
- Decide whether to create an IDA/Wave3 function boundary for `0x005039f0` and whether `0x00503a50` should be modeled as a non-deleting destructor.
- Reconcile excluded status for `0x00503a80` and `0x00503c70` with their appearance in `inspect class GameServerConfig`.

2026-05-25 follow-up:

- Current `source-3/simroot_v2/class_RegistryConfig.cpp` still has omitted-body markers for `SaveToRegistry` at `0x00491b30` and `LoadFromRegistry` at `0x004926a0`; IDA confirms both remain real functions. `SaveToRegistry` writes the `Software\Nexon\Kingdom of the Winds` registry family, including option/server/color values, and `LoadFromRegistry` also creates/reads CLSID state under `HKEY_CLASSES_ROOT`.
- IDA `lookup_funcs` still reports `0x005039f0` and `0x00503a50` as not functions. Disassembly confirms `0x005039f0-0x00503a41` is constructor-shaped nation-table setup and `0x00503a50-0x00503a78` is destructor-shaped table cleanup.
- IDA confirms `0x00503a80`, `0x00503c70`, `0x00504110`, `0x00514d50`, and `0x00514d80` as real functions. Current `source-3/simroot_v2/class_GameServerConfig.cpp` still omits `0x00503a80` and `0x00503c70`.
- `0x00504110` writes `g_activeMapPane` at `0x0067a764`, installs `MapPane` vtables, loads `SOBJ.TBL`, fills `g_objectNationMap`, and allocates `g_gameServerNationTable`; this supports keeping `GameServerConfig` out of `config/` and treating the current `g_activeGameServerConfig` alias as map-pane owner pollution.

### 2026-05-23 - Error wrapper constructors include projected starts not recognized by IDA

Observed:

- During the error/exception source-layout pass, Wave3 listed three constructor starts that IDA MCP does not recognize as functions:
  - `DIError::DIError` at `0x004a61b0`.
  - `DSError::DSError` at `0x004a6330`.
  - `ErrorMessage::ErrorMessage` at `0x004a63e0`.
- IDA MCP confirms neighboring real functions:
  - `Win32Error::FormatErrorMessage` at `0x004a6100-0x004a61a3`.
  - `DIError::FormatErrorMessage` at `0x004a61e0-0x004a625b`.
  - `DDError::DDError` at `0x004a6260-0x004a6284`.
  - `DDError::FormatErrorMessage` at `0x004a6290-0x004a6330`.
  - `DSError::FormatErrorMessage` at `0x004a6360-0x004a63db`.
  - `FileError::FileError` at `0x004a6430-0x004a646f`.

Expected:

- Constructor records should either align with IDA function starts or be marked as projected/non-function setup records.
- Source migration should not use the projected constructor addresses as rename anchors until reviewed.

Impact:

- The new error wrapper docs use confirmed function starts for migration anchors and explicitly mark the three projected starts as data caveats.
- Keep `DIError`, `DSError`, and `ErrorMessage` in the shared `util/Error.cpp` hypothesis, but avoid trusting their projected constructors for code-range ownership.
- 2026-05-25 IDA recheck found two additional real helpers in the projected-constructor neighborhood that current generated output omits: `0x004a6400` and `0x004a6410`.

Follow-up:

- Review bytes and xrefs around `0x004a61b0`, `0x004a6330`, and `0x004a63e0`.
- Decide whether Wave3 should delete these constructor entries, model them as non-function projected setup, or realign them to nearby confirmed starts if evidence supports that.
- Add, exclude, or otherwise account for the real helpers at `0x004a6400` and `0x004a6410`.

2026-05-25 follow-up:

- IDA `lookup_funcs` still reports `0x004a61b0`, `0x004a6330`, and `0x004a63e0` as not functions, and `callers`/`xrefs_to` find no direct callers or data refs for those starts.
- IDA disassembly nevertheless shows constructor-shaped raw bytes at those starts: `0x004a61b0` installs the `DIError` vtable and stores the HRESULT, `0x004a6330` installs the `DSError` vtable and stores the HRESULT, and `0x004a63e0` installs the `ErrorMessage` vtable.
- Current `source-3/simroot_v2/class_DIError.cpp`, `class_DSError.cpp`, and `class_ErrorMessage.cpp` still emit source bodies for those projected starts, so treat them as raw-code evidence rather than confirmed function boundaries.
- IDA confirms `0x004a6400` as a real base `Error` cleanup helper and `0x004a6410` as a real wide-message copy helper. Current `simroot_v2` output does not emit either helper.

2026-05-25 vtable/layout follow-up:

- Added [Error hierarchy vtables](by-type/by-vtable/ErrorHierarchyVtables.md) and [Error object layouts](by-type/by-struct/ErrorObjectLayouts.md) after IDA disassembly confirmed the shared five-slot error interface and the main vtable run at `0x00619340-0x00619448`.
- IDA confirms `0x004a6480` as a real `FileError` message-copy vtable slot helper. Current active `source-3/simroot_v2/class_FileError.cpp` still omits this helper.
- IDA resolves `??_7PasswordError@@6B@` to `0x006125a8`, and xrefs show `PasswordError::PasswordError` writes that vtable at `0x00467172`.
- Current active `source-3/simroot_v2/class_PasswordError.cpp` emits `GetErrorDescriptor` at `0x00467400` as `return reinterpret_cast<wchar_t*>(&PasswordError_vtable);`. IDA decompilation/disassembly shows the function returns `0x006125bc`, descriptor/string data adjacent to the `PasswordError` vtable, not the vtable pointer.
- Treat `PasswordError::GetErrorDescriptor` generated code as a data issue during source migration. The owning class/file remains [PasswordError](by-class/PasswordError.md) / [Error](by-file/Error.md), but the generated return expression should be corrected or annotated before rewrite work.

2026-05-26 exact-helper documentation follow-up:

- Added exact memory pages for the generated-output omissions at [0x004a6400](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md), [0x004a6410](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md), and [0x004a6480](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md).
- IDA MCP reconfirmed `0x004a6410` as the `ErrorMessage` vtable message-copy slot via data xref `0x006193c8`, and `0x004a6480` as the `FileError` vtable message-copy slot via data xref `0x006193e0`.
- `0x004a6400` has no direct xrefs, but IDA confirms it as a real `0x0b` function that resets the base `Error` vtable and calls inherited `LObject` cleanup. Keep it documented as project-owned teardown code unless later evidence proves a compiler-only exclusion.

2026-05-26 wrapper vtable follow-up:

- IDA MCP rechecked concrete wrapper starts and vtable writes: `Win32Error` `0x004a60d0` / vtable `0x0061935c`, `DDError` `0x004a6260` / `0x0061938c`, `WSAError` `0x004a64a0` / `0x006193ec`, `InternetError` `0x004a6550` / `0x00619404`, and `InternetConnectionError` `0x004a6690` / `0x0061941c`.
- Updated the small wrapper class docs with these vtable anchors and function-size evidence so source reconstruction can group them under `util/Error.cpp` without trusting generated one-class file splits.

### 2026-05-26 - SelectionControlPane is likely not a standalone original source file

Observed:

- Current `source-3/simroot_v2/class_SelectionControlPane.cpp` emits only `SelectionControlPane::SetSelectionAndRefresh` at `0x00495cb0`.
- Current metadata reports no constructor or vtable inventory for `SelectionControlPane`; the file is a Wave3 default one-class file imported from a Wave2 missing-ref restoration.
- IDA MCP confirms `0x00495cb0` as a real `0x19` function that writes selected value offset `+0x10c` and tail-calls vtable slot `+0x20`.
- IDA MCP finds one direct caller at `0x0052a1e2` inside `MusicControlDialog::TogglePauseState`, where control id `12` receives selected values `37` and `48`.

Expected:

- Treat `SelectionControlPane` as a generic button/choice-control helper attached to [ButtonControlPane](by-file/ButtonControlPane.md), not as a standalone original `.cpp` file or music-dialog-owned code.

Impact:

- Added exact memory page [0x00495cb0-0x00495cc9](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md) and field note [SelectionControlPane +0x10c](by-type/by-field/SelectionControlPaneSelectedValue_0x10c.md).
- Source-layout migration should attach this helper to the button/choice-control module unless later constructor/vtable evidence proves a separate original class file.

Follow-up:

- Search for indirect/vtable users of the same `+0x10c` selected-value field in nearby button, image-button, radio, and slider control paint paths before finalizing the source-level field name.

### 2026-05-23 - Fitting-room records include projected starts and generic UI/text helper pollution

Observed:

- During the fitting-room/cash-shop source-layout pass, Wave3 listed several method starts that IDA MCP does not recognize as function starts:
  - `FittingRoomDownloadControlPane::FittingRoomDownloadControlPane` at `0x0041b9e0`; nearby confirmed IDA starts include `0x0041b9b0`, `0x0041ba20`, and `0x0041ba40`.
  - `FittingRoomDialog::~FittingRoomDialog` at `0x0041c250`; IDA shows `0x0041bdd0-0x0041c250` as the preceding function and the next confirmed dialog method at `0x0041c310`.
  - `FittingRoomScrollPane::FittingRoomScrollPane` at `0x0041d6c0`; nearby confirmed starts include tiny helpers at `0x0041d690`, `0x0041d6a0`, `0x0041d6b0`, and the strong scroll method at `0x0041d870`.
- `FittingRoomDownloadControlPane` currently owns unrelated-looking field-map helpers (`0x004b1130`, `0x004b11a0`), generic text helpers (`0x004ba9a0`, `0x004bab70`, `0x00593b20+`), and IME/text-edit helpers (`0x004e7470`, `0x004e7930`).
- Follow-up FieldMapPane review on 2026-05-24 confirmed `0x004b11a0` is called only from FieldMapPane input handlers in current IDA xrefs and should be documented with `map/FieldMapPane.cpp`. `0x004b1130` is function-shaped code from `0x004b1130-0x004b119a`, but IDA currently has no function object or xrefs for that start.
- `FittingRoomListPane::SetTextColor` at `0x004b9660` has 162 IDA caller functions, so it is likely generic drawing/control infrastructure rather than fitting-room-private code.
- `FittingRoomUserImageControlPane` currently owns a second constructor-like function at `0x00495450`, but IDA caller evidence points to `0x00517f30`, not the fitting-room dialog constructor.
- `FittingRoomTextButtonControlPane` currently includes generic event/motion helpers at `0x004a89f0` and `0x00544df0+`.

Expected:

- Projected starts should be marked non-IDA/projected or realigned to confirmed function starts before source migration.
- Generic UI, text, IME, field-map, and motion helpers should not be treated as fitting-room class ownership without caller/vtable evidence.

Impact:

- New fitting-room docs use the confirmed local `0x0041ba40-0x004245f5` core for source-layout decisions and treat later scattered helpers as owner-pollution candidates.
- Do not move all current `FittingRoom*` Wave3 methods into `cashshop/FittingRoom.cpp` blindly.

Follow-up:

- Review bytes and xrefs around `0x0041b9e0`, `0x0041c250`, and `0x0041d6c0` to decide whether Wave3 should delete, merge, or mark those projected records.
- Re-own or neutralize generic helpers at `0x004b9660`, `0x004e7470`, `0x004e7930`, `0x00593b20+`, `0x004a89f0`, and `0x00544df0+`.
- Review `0x00495450` against its caller `0x00517f30` before keeping it under `FittingRoomUserImageControlPane`.

2026-05-25 follow-up:

- IDA `lookup_funcs` still reports `0x0041b9e0`, `0x0041c250`, and `0x0041d6c0` as not functions, and `xrefs_to` reports no current references to those starts.
- IDA disassembly nevertheless shows raw constructor/destructor-shaped bytes at those addresses: `0x0041b9e0` installs `FittingRoomDownloadControlPane` vtables, `0x0041c250` starts a `FittingRoomDialog` destructor-shaped body, and `0x0041d6c0` initializes `FittingRoomScrollPane` state/vtables.
- IDA decompilation of `FittingRoomListPane::FittingRoomListPane` at `0x0041eb90` shows scrollbar child setup inlined after a `272` byte allocation; it does not call the generated `0x0041d6c0` record.
- IDA decompilation of `0x00495450` shows generic `ButtonControlPane` then `TextButtonExControlPane` construction and an attached text-provider child. Current callers show only `0x00517f30`, not the fitting-room dialog constructor, so this method should be re-owned away from `FittingRoomUserImageControlPane`.
- `simroot_v2` still emits the above projected starts and generic FieldMap/IME/text helpers under fitting-room owner names, so downstream agents should treat those owner labels as generated data issues.

2026-05-27 follow-up:

- The low-address coverage pass split `0x0041b69f-0x0041ba40` with IDA evidence. `0x0041b9e0-0x0041ba20` is now documented as [FittingRoomDownloadControlPane raw constructor bytes](by-memory/0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor.md), and `0x0041ba20-0x0041ba3f` as [FittingRoomDownloadControlPane raw destructor bytes](by-memory/0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor.md).
- This does not make the Wave3 projected `0x0041b9e0` record migration-ready. IDA still has no function object and no xrefs at that start; the correct current treatment is "real raw code bytes, projected function boundary/data issue."
- The same pass also identified `0x0041b6d0-0x0041b9a0` and `0x0041b9a0-0x0041b9de` as MSVC STL/CRT support, not fitting-room or cash-shop product code.
- IDA MCP reports `FittingRoomUserImageControlPane` scalar-deleting destructor `sub_4245A0` at `0x004245a0` has size `0x55`, ending at `0x004245f5`. Current `simroot_v2/class_FittingRoomUserImageControlPane.meta_wave3` still reports `end: 0x004245f4`, so generated range data appears to miss the final byte of the `retn 4` instruction.
- The remaining gap before JsonCpp was split into padding plus [JsonCpp pre-exception flag initializers](by-memory/0x00424600-0x00424629.JsonCppPreExceptionFlagInitializers.md), not fitting-room product code.

2026-05-25 text-helper follow-up:

- IDA caller checks show `0x004ba9a0` has 111 direct callers, `0x004baa70` has 60, `0x004baaa0` has 62, `0x004bab70` has 188, and `0x004bacd0` has 31. These are broad UI/render helpers, not fitting-room-private routines.
- The covered bodies read GrafPort draw-state fields and call `FontImageLib` through `g_pFontImageLib` / `dword_67AB24`; `0x004bb5e0` is the per-glyph helper called only by `0x004bab20` and `0x004bab70`.
- Documentation now tracks these as [GrafPort text run helpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md) and [GrafPort DrawGlyph](by-memory/0x004bb5e0-0x004bb7df.GrafPortDrawGlyph.md). Wave3 data should eventually re-own or neutralize the generated `FittingRoomDownloadControlPane`, `CollectionEntryControlPane`, and `RankingEventListPane` labels for this helper family.

2026-05-25 draw-state helper follow-up:

- IDA caller checks show `0x004b9600` has 217 direct callers, `0x004b9660` has 305, `0x004b9680` has 255, and `0x004b9690` has 40. Current generated owners split these leaf GrafPort accessors across FittingRoom, Ranking, Collection, and TargetOption classes.
- IDA confirms `0x004b96c0-0x004b9767` as a real clip-rect helper with 42 direct callers and Region-helper callees, while `simroot_v2` emits it as `RankingEventListPane::GetClipRect`.
- Documentation now tracks these as [GrafPort draw-state accessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md) and [GrafPort clip rect helper](by-memory/0x004b96c0-0x004b9767.GrafPortClipRectHelper.md). Wave3 data should eventually re-own or neutralize the generated feature-class labels for this helper family.

2026-05-26 equipment-state follow-up:

- IDA confirms `0x0041d5e0` as a real `FittingEquipmentState::ResetEntries` helper with the only current caller at `FittingRoomDialog::OnCommand + 0xf4` (`0x0041c404`).
- The caller passes `this + 0x504`, and the `FittingRoomDialog` constructor initializes the same subobject through `0x00422020`, so the generated standalone `class_FittingEquipmentState.cpp` should be treated as a recovered helper/layout view inside fitting-room item-state code, not proof of an original standalone file.
- Added [FittingEquipmentState ResetEntries](by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md) and [FittingEquipmentStateLayout](by-type/by-struct/FittingEquipmentStateLayout.md) docs to keep the method and vector layout visible while preserving the source-placement caveat.

### 2026-05-26 - Macro dialog classes have IDA vtable families but Wave3 reports zero vtables

Observed:

- Current `simroot_v2` metadata reports `vtable_count: 0` for `MacroDialog`, `SpellMacroDialog`, `NewMacroDialog`, `IntegrateMacroDialog`, `SpellMacroEditControlPane`, `NewMacroEditControlPane`, and `IntegrateMacroEditControlPane`.
- IDA symbol enumeration finds decorated MSVC vtable and RTTI symbols for all seven classes, including `??_7MacroDialog@@6B@` at `0x00620d10`, `??_7SpellMacroDialog@@6B@` at `0x00620dac`, `??_7NewMacroDialog@@6B@` at `0x00620e48`, `??_7IntegrateMacroDialog@@6B@` at `0x00621130`, `??_7SpellMacroEditControlPane@@6B@` at `0x0062d1e4`, `??_7NewMacroEditControlPane@@6B@` at `0x0062d288`, and `??_7IntegrateMacroEditControlPane@@6B@` at `0x0062d32c`.
- Constructors, non-deleting teardown helpers, and scalar deleting destructors write the expected primary/secondary/tertiary vtable views.

Expected:

- Wave3 vtable inventory should record these RTTI-backed vtable families rather than leaving the classes at `vtable_count: 0`.

Impact:

- Source migration should use [MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md) for ABI/layout evidence until generated vtable metadata is repaired.

Follow-up:

- Rebuild or repair vtable extraction for the macro-dialog and macro-edit-control classes, then check that the generated class metadata records the primary/secondary/tertiary views and their adjustor slots.

### 2026-05-23 - SoundManager owns generic timer helper wrappers with broad caller evidence

Observed:

- Wave3 emits `SoundManager::CancelTimer` at `0x00597610` and `SoundManager::CancelPendingTimersExceptEvent` at `0x00597630`.
- IDA confirms both are real tiny functions:
  - `0x00597610-0x00597626` calls timer-manager helper `0x00597b80` through global `dword_67AB80`.
  - `0x00597630-0x00597646` calls timer-manager helper `0x00597ca0` through global `dword_67AB80`.
- IDA caller evidence for `0x00597610` includes many non-audio functions, while `0x00597630` has a non-SoundManager caller at `0x0053a96d`.

Expected:

- These helpers should either be modeled as generic timer helper methods/functions, or Wave3 should record why `SoundManager` is their true owner despite broad caller evidence.

Impact:

- Keep the main `SoundManager` audio range `0x005797b0-0x0057bc58` separate from the timer wrapper range `0x00597610-0x00597645` in documentation and source-layout planning.
- Do not use the timer helper wrappers as strong evidence that unrelated timer callers belong in `audio/SoundManager.cpp`.

Follow-up:

- Review `TimerHandler`, `TimerMgr`, and caller xrefs around `0x00597610`, `0x00597630`, `0x00597b80`, and `0x00597ca0`.
- Re-own the wrappers to a timer/core module if no SoundManager-specific state is involved.

2026-05-24 follow-up:

- IDA MCP recheck decompiles `0x00597610` as `sub_597B80(dword_67AB80, this, eventId)` and `0x00597630` as `sub_597CA0(dword_67AB80, this, keepEventId)`.
- `0x00597610` has broad non-audio caller evidence; `0x00597630` is called from the living-object sprite configuration path at `0x0053a96d`.
- The memory doc has been renamed to [TimerHandlerWrappers](by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md). Treat active `class_SoundManager.cpp` ownership for these two rows as stale generated data.
- Active `class_LivingObjectPane.cpp` still calls these wrappers as `SoundManager::CancelTimer` and `SoundManager::CancelPendingTimersExceptEvent` in sprite, movement, and animation paths. Treat those names as stale generated labels for generic timer wrapper calls, not evidence that `LivingObjectPane` depends on `audio/SoundManager.cpp` for actor timers.

### 2026-05-23 - Clan bank/item records have one projected constructor, unowned helper functions, and two outlier owners

Observed:

- During Clan bank/item source-layout documentation, IDA MCP reported no function at Wave3's `ClanItemDialog::ClanItemDialog` projected start `0x0048a0c0`.
- IDA confirms nearby real starts:
  - `0x0048a100` and `0x0048a120` for `ClanItemDialog` helper/confirm behavior.
  - `0x0048a690`, `0x0048acf0`, and `0x0048b600` for small vtable-reset/destructor-helper functions adjacent to `ClanDepItemDialog`, `ClanWidItemDialog`, and `ClanBankPane`.
- Wave3 `show memory-at` had no clean owner for those small helper functions during the bank/item pass.
- `ClanBankItemListPane::AppendEntryString` is recorded at `0x00430041`, but IDA resolves the containing function as `sub_430040` with real start `0x00430040`; behavior looks like a generic string/vector append helper, not clan-bank-specific code.
- `ClanBankItemListPane::virt_meth_0x4c0043` is excluded in Wave3 but still appears in class inspection; IDA resolves it inside large function `sub_4BEE40`, a SIMD/bit-manipulation helper with no clan-bank behavior.

Expected:

- `ClanItemDialog` constructor data should either align with an IDA function start or be clearly marked as projected/non-function.
- Small real clan-bank helper functions should have an owner, exclusion, or explicit unresolved-helper status.
- `0x00430041` and `0x004c0043` should not appear as usable `ClanBankItemListPane` ownership evidence.

Impact:

- The new `ClanBank` docs use confirmed IDA starts for migration anchors and treat `0x0048a0c0`, `0x00430041`, and `0x004c0043` as data caveats.
- Do not migrate `ClanBankItemListPane` by blindly attaching all current Wave3 methods.

Follow-up:

- Review bytes/xrefs around `0x0048a0c0` and `0x0048a100` to decide how Wave3 should model the projected constructor.
- Re-own or explicitly exclude the helper starts `0x0048a100`, `0x0048a690`, `0x0048acf0`, and `0x0048b600`.
- Reassign/exclude `0x00430041` and `0x004c0043` from `ClanBankItemListPane` after reviewing their caller sets.

2026-05-25 Wave3 tool follow-up:

- Live `show method 0x00430041 --summary` still models `ClanBankItemListPane::AppendEntryString` as active with range `0x00430041-0x00430065`.
- Active conflicts center on the unresolved `0x00430041` method start, which begins one byte after the real generic helper prologue at `0x00430040`.

2026-05-27 focused gap follow-up:

- Documented `0x0048b7e0-0x0048b8bc` as raw `ClanBankPane` packet-helper-shaped bytes. IDA reports no function object or inbound xrefs at `0x0048b7e0` or `0x0048b870`, but both bodies build opcode `0x36` packets through `g_pNetConnection`; keep them as unresolved raw helpers in documentation until Wave3 models or excludes them explicitly.

2026-05-26 IDA/simroot follow-up:

- The shared helper is now documented under [generic string append helper / false starts](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md).
- `0x00430041` starts one byte after the real helper prologue at `0x00430040` and should be excluded or re-owned away from feature classes after caller review.

### 2026-05-23 - Clan core has projected constructor starts and two unowned packet helpers

Observed:

- During Clan source-layout documentation, IDA MCP reported no function at Wave3 constructor starts:
  - `ClanInfoListPane::ClanInfoListPane` at `0x004885a0`.
  - `ClanStringListPane::ClanStringListPane` at `0x00488630`.
  - `ClanDepMoneyInputDialog::ClanDepMoneyInputDialog` at `0x00488fa0`.
  - `ClanWidMoneyInputDialog::ClanWidMoneyInputDialog` at `0x00489070`.
  - `ClanExpelNameInputDialog::ClanExpelNameInputDialog` at `0x00489140`.
  - `ClanSummonNameInputDialog::ClanSummonNameInputDialog` at `0x00489270`.
  - `ClanAppearNameInputDialog::ClanAppearNameInputDialog` at `0x004893a0`.
  - `ClanChangeNameInputDialog::ClanChangeNameInputDialog` at `0x004894d0`.
  - `ClanEnlistInputDialog::ClanEnlistInputDialog` at `0x00489f80`.
  - `ClanChangeInputDialog::ClanChangeInputDialog` at `0x00489ff0`.
  - `ClanLeaveConfirmDialog::ClanLeaveConfirmDialog` at `0x0048a060`.
- IDA MCP confirms nearby real submitter/helper starts at `0x00488fe0`, `0x004890b0`, `0x00489180`, `0x004892b0`, `0x004893e0`, `0x00489510`, `0x00489fc0`, `0x0048a030`, `0x0048a0a0`, and `0x0048a0b0`.
- Wave3 `show memory-at` reports no owner for confirmed Clan packet helpers `0x00486330` and `0x00487600`.
- IDA decompilation and Wave2 missing-ref annotations show `0x00486330` sends opcode `0x4b` subtype `10` attribute-change packets from `ClanChangeInputDialog::SubmitClanChange`, while `0x00487600` maps `ClanStatusPane` row clicks to opcode `0x4b` row action packets.
- Current simroot/Wave3 data models `0x00487370` as `ClanEnlistInputDialog::HideAllControls`, but IDA evidence shows it refreshes `ClanStatusPane` child panes at offsets `+0x2510`, `+0x2514`, and `+0x2518`; `ClanEnlistInputDialog` vtables do not contain a pointer to `0x00487370`.
- 2026-05-24 follow-up: IDA xrefs show no references to `0x004885a0` or `0x00488630`; `ClanStatusPane::ClanStatusPane` instead constructs the child panes inline at `0x004840b2-0x00484135`, `0x0048413f-0x0048419b`, and `0x004841a0-0x00484201`.
- `ClanStringListPane::DrawItem` at `0x004887d0` has three vtable data refs, corresponding to `ClanStringListPane + 0x80`, `ClanJoinListPane + 0x80`, and `ClanEnlistListPane + 0x80`.
- `0x004888d0` is an IDA-confirmed function with a `ClanJoinListPane + 0x7c` vtable data ref, but current `simroot_v2` does not emit a dedicated `class_ClanJoinListPane.cpp`.
- 2026-05-26 follow-up: IDA reconfirmed the exact list-pane virtual boundaries and vtable refs, and reconfirmed no function/xrefs at projected constructor starts `0x004885a0` and `0x00488630`. Documentation confidence for the exact virtual-method island is now medium, while the projected constructor records remain data-cleanup targets.
- 2026-05-27 follow-up: IDA MCP family pass found no function, inbound xrefs, or raw dword pointer hits for projected Clan dialog constructor starts `0x00488fa0`, `0x00489070`, `0x00489140`, `0x00489270`, `0x004893a0`, `0x004894d0`, `0x00489f80`, `0x00489ff0`, and `0x0048a060`. The bytes are still constructor-shaped and contain base-constructor calls plus derived vtable stores, so the data issue is boundary/reachability modeling, not false class identity.
- 2026-05-27 focused gap pass documented `0x00488fa0-0x00488fd5` as the `ClanDepMoneyInputDialog` raw constructor-shaped body, while preserving the no-function/no-xref caveat.
- 2026-05-27 focused gap pass documented `0x00489f80-0x00489fb5` as the `ClanEnlistInputDialog` raw constructor-shaped body and split the following `0x00489fb5-0x00489fc0` bytes as alignment padding before confirmed submitter `0x00489fc0`.
- 2026-05-27 focused gap pass documented `0x0048a0c0-0x0048a0fb` as the `ClanItemDialog` raw constructor-shaped body and split the surrounding `0x0048a0be-0x0048a0c0` and `0x0048a0fb-0x0048a100` bytes as alignment padding around the confirmed `ClanItemDialog` core at `0x0048a100`.

Expected:

- Projected constructors should either align with IDA function starts or be clearly marked projected/non-IDA in Wave3 data.
- Real Clan packet helpers at `0x00486330` and `0x00487600` should have an owner, exclusion, or explicit unresolved status.
- `0x00487370` should be re-owned away from `ClanEnlistInputDialog` and treated as `ClanStatusPane` child-pane refresh behavior.
- `ClanJoinListPane` and `ClanEnlistListPane` should be represented as class owners or explicit constructor/vtable-only child classes so their vtable slots are not hidden under `ClanStringListPane` only.

Impact:

- The Clan module docs can use confirmed IDA method starts and restored globals, but constructor-specific rename/source-map work should not use the projected starts listed above.
- `0x00486330` and `0x00487600` should be treated as Clan file-local helper candidates during source-layout planning even though Wave3 has no owner for them.
- `0x00487370` should not be used as evidence for `ClanEnlistInputDialog` method layout; it belongs with `ClanStatusPane` and the adjacent raw view-switch helpers.
- Added class docs for `ClanJoinListPane` and `ClanEnlistListPane` and expanded the `ClanStatusPane` constructor memory doc to preserve the inline child setup evidence.

Follow-up:

- Inspect bytes/xrefs around each projected constructor start and nearby confirmed submitter to decide whether the projection should be removed, merged, or represented as non-function setup data.
- Materialize or otherwise annotate the Clan helpers at `0x00486330` and `0x00487600`.
- Repair the `0x00487370` owner in generated data and check whether the neighboring raw helpers `0x004872e0`, `0x004873c0`, `0x00487480`, and `0x00487540` should be materialized under `ClanStatusPane`.
- Review whether the no-xref sibling helpers in `0x00487c40-0x00488594` should be materialized as file-local Clan packet/dialog helper functions or kept as retained source-function caveats.
- Recheck generated output after Wave3 data fixes for `0x004887d0`, `0x004888d0`, `0x00488900`, `0x00488970`, `0x004889a0`, and whether dedicated `ClanJoinListPane`/`ClanEnlistListPane` class files are emitted.
- Review remaining unresolved neighboring functions after `0x00488b40` before migrating a broad `Clan.cpp` block.

2026-05-27 partial resolution:

- IDA MCP resolved `0x00484f70-0x0048540b` as a `ClanStatusPane` secondary-vtable opcode `0x43` packet dispatcher and resolved `0x00485440-0x004867f2` as opcode `0x4b` packet request/helper clusters. These ranges are now documented in `by-memory`; generated Wave3 ownership still needs repair/materialization if the tool output is expected to emit these helpers.
- IDA MCP resolved `0x004872e0-0x004875f5` as `ClanStatusPane` row eligibility, child-pane refresh, and info/join/enlist view-switch helpers, with surrounding jump tables/alignment recorded in `by-memory/-ignored.md`. This specifically corrects the generated `0x00487370` `ClanEnlistInputDialog::HideAllControls` owner.
- IDA MCP resolved `0x004877d0-0x00488594` as a Clan opcode `0x43` packet/dialog helper island and `0x004885a0-0x00488602` as constructor-shaped `ClanInfoListPane` bytes with no IDA function object or inbound xrefs. Generated data should keep the direct `ClanEnlistInputDialog` packet handlers, but should not overstate xref-backed reachability for the no-xref sibling openers or the raw constructor start.
- IDA MCP resolved `0x00488900-0x00488b3d` as `ClanJoinListPane`/`ClanEnlistListPane` vtable-backed input/action handlers, with surrounding/internal alignment recorded in `by-memory/-ignored.md`. Generated data should materialize or attach these methods to the list-pane classes instead of leaving them as an unknown neighbor span.
- IDA MCP resolved the following `0x00488f9f-0x00488fe0` neighbor: `0x00488f9f` is the final byte of `ClanNameInputDialog::OnInputEvent`, `0x00488fa0-0x00488fd5` is raw `ClanDepMoneyInputDialog` constructor-shaped bytes, and `0x00488fd5-0x00488fe0` is alignment. Generated data should keep the constructor as projected/non-IDA unless reachability is later proven.

2026-05-26 layout follow-up:

- Added [Clan input dialog layouts](by-type/by-struct/ClanInputDialogLayouts.md) after IDA decompilation confirmed `ClanNameInputDialog` control-host use at `+0x1fc` and `ClanAttrInputDialog` submitted-field storage at `+0x26c`, `+0x46c`, `+0x66c`, and `+0x86c`.
- This supports the existing source-layout decision: the one-field and multi-field clan input shells should stay together with [Clan](by-file/Clan.md) or the [ClanDialogs](by-file/ClanDialogs.md) split candidate, while projected derived constructor starts remain data-cleanup targets.

2026-05-26 submitter/vtable follow-up:

- IDA MCP rechecked the one-field derived submitter functions and primary vtable xrefs: `0x00488fe0` and `0x004890b0` are `0x82`-byte real functions; `0x00489180`, `0x004892b0`, `0x004893e0`, and `0x00489510` are `0xee`-byte real functions.
- Primary vtable xrefs confirm class identity despite non-IDA constructor starts: `ClanDepMoneyInputDialog` `0x00615998`, `ClanWidMoneyInputDialog` `0x00615a38`, `ClanExpelNameInputDialog` `0x00615ad8`, `ClanSummonNameInputDialog` `0x00615b78`, `ClanAppearNameInputDialog` `0x00615c18`, and `ClanChangeNameInputDialog` `0x00615cb8`.
- Updated the six thin derived dialog class docs with vtable anchors and IDA-backed submitter evidence so source reconstruction does not depend on generated projected constructor starts.
- 2026-05-27: Updated Clan class/file/memory/vtable docs with raw-pointer-negative constructor-boundary evidence while preserving the constructor-shaped byte evidence and confirmed vtable ownership.

### 2026-05-23 - SayToPlanMessageInputPane has plan/clan naming ambiguity

Observed:

- `SayToPlanMessageInputPane` owns the chat-mode `4` branch and generated source uses `Clan => ` prompt text, so the current `Plan` class name may be a historical, transliteration, or attribution artifact.

Expected:

- The plan/clan target-message naming should be reviewed against strings, packet context, and original game terminology before source migration.

Impact:

- The `SayInputPanes` docs can use confirmed IDA starts for default say, shout submit, direct-message, group-message, and mode dispatch behavior.
- `SayToPlanMessageInputPane` should remain medium-confidence by name even though its method boundaries are strong.

Follow-up:

- Review strings and caller context around `0x005a5110`, `0x005b22d0`, and `0x005b2390` to settle whether `SayToPlanMessageInputPane` should be renamed to a clan-message input class.

### 2026-05-23 - Group pane records include scroll/list owner boundary conflicts

Observed:

- IDA MCP confirms nearby functions at `0x0056bb00`, `0x0056bb10`, and `0x0056bb20`. The `0x0056bb20` decompilation installs `SpelledPane`/text-edit style vtables and is called from non-group UI functions, so it is not clean `GroupListPane` ownership evidence yet.
- 2026-05-26 recheck: IDA still reports `0x0056baa0` as not an auto-function, but raw disassembly from `0x0056baa0-0x0056bafd` is a real constructor-shaped island that installs `GroupListPane` vtables `0x00624214`, `0x0062428c`, and `0x006242bc`.
- `GroupPane::GroupPane` and `GroupPane2::GroupPane2` inline the same `GroupListPane` child setup at `0x0056c55e-0x0056c56e` and `0x0056c80e-0x0056c81e`; this confirms the class relationship even though `0x0056baa0` lacks a call xref.
- The `0x00573273-0x005732b5` group-pane thunk island is compiler-generated destructor adjustment for `GroupPane2`, `GroupPane`, and `NewGroupPane`, not feature logic.
- Current simroot ownership still places `0x00561420`, `0x00561b00`, and `0x00561bc0` under generated `TextEditPane` scrollbar helpers, even though they sit directly in the `ScrollNewGroupPane` interaction neighborhood.
- 2026-05-26 recheck: IDA xrefs now tie `0x00561420`, `0x00561b00`, and `0x00561bc0` to the `ScrollNewGroupPane` event/update path, not ordinary `TextEditPane` ownership. `0x00561bc0` calls `NewGroupPane::SetScrollPosition` at `0x0056df00`.
- Raw disassembly shows complete method bodies at non-IDA starts `0x005619d0`, `0x00561a40`, and `0x00561d50`; these are documented as `ScrollNewGroupPane` raw/manual helper boundaries.

Expected:

- `ScrollNewGroupPane` memory coverage should not imply ownership over unrelated nearby `TextEditPane` or `ScrollCollectionPane` helpers outside the corrected `0x00561420-0x00561d4c` interaction family.
- Conversely, `TextEditPane` scrollbar-variant coverage should no longer absorb the `0x00561420-0x00561d4c` `ScrollNewGroupPane` interaction helper family.

Impact:

- Group source-layout documentation can use confirmed `GroupPane`, `GroupPane2`, `NewGroupPane`, `SayToGroupMessageInputPane`, and marker helper anchors.
- `GroupListPane` can be documented as a real child class with a manual/raw constructor boundary, but migrations should not depend on IDA auto-function metadata at `0x0056baa0`.
- `ScrollNewGroupPane` is strong for the `0x00560900-0x00561db0` scrollbar implementation, with medium confidence only for whether the original file was `Group.cpp` or a reusable scrollbar source.

Follow-up:

- Remaining work is source-file placement: decide whether `ScrollNewGroupPane` stays in `Group.cpp` or moves to a reusable scrollbar source after comparing the neighboring scroll-control families.
- Continue scroll-control comparison against `ScrollCollectionPane`, `ScrollVolumePane`, and remaining `TextEditPane` scrollbar variants before mass migration.

### 2026-05-23 - Chatting UI records include polluted color-pane ownership and a helper signature mismatch

Observed:

- `source-3/simroot_v2/class_ChattingColorPane.cpp` starts with unrelated `SpellInventoryPane`, history viewing, music path, music playback, and localized alert methods before/after the actual chat color pane core.
- `ChattingColorPane` currently owns later ranges such as `0x0049dad0`, `0x00529ee0`, `0x0052a120`, `0x005304c0`, and `0x005304f0`; those behaviors are not reliable chat-color ownership evidence.
- `ChattingColorListPane` has a strong local color-list core at `0x00482fb0-0x00483486`, but Wave3 also attaches many unrelated board/article, item menu, user-list, and generic list-looking methods to the class.
- The generated `ChattingHandlePane::OnMouseEvent` call site passes `this,eventData` to `GetChatButtonAtPoint`, while `recovered/GetChatButtonAtPoint_00482400.cpp` has a body/signature shaped as `GetChatButtonAtPoint(int mouseX, int mouseY)`.

Expected:

- `ChattingColorPane` and `ChattingColorListPane` should not own unrelated feature-dialog or music-control methods without explicit owner evidence.
- The `GetChatButtonAtPoint` caller and global function signature should agree on whether the helper receives coordinates or a mouse event/context object.

Impact:

- The chat UI source-layout docs can use the verified local `0x0047efb0-0x00483ef7` anchors, but migrations should not use the polluted color-pane/list-pane tail methods as rename/source-map anchors.
- `ChattingColorPane` should remain medium-confidence until unrelated methods are reassigned or excluded.
- `ChattingColorListPane` should use only the local color swatch core for chat source ownership until a focused owner pass reviews the later attached methods.

Follow-up:

- Review and reassign or exclude the non-chat `ChattingColorPane` ranges and the non-local `ChattingColorListPane` methods.
- `GetChatButtonAtPoint` call-site/signature reconciliation is resolved by the 2026-05-26 follow-up below; remaining work is generated call-site cleanup.

2026-05-26 IDA/simroot follow-up:

- IDA MCP confirms [GetChatButtonAtPoint](by-memory/0x00482400-0x004824c8.GetChatButtonAtPoint.md) is a real function at `0x00482400-0x004824c8` with exactly two code callers, `0x00481dca` and `0x00481ec9`, both inside `ChattingHandlePane::OnMouseEvent`.
- IDA disassembly at both call sites pushes `eventData + 0x08` and `eventData + 0x0c` coordinate fields before the call, so the recovered helper signature `GetChatButtonAtPoint(int mouseX, int mouseY)` is correct.
- Current `simroot_v2/class_ChattingHandlePane.cpp` still emits the mouse-down call as `GetChatButtonAtPoint(this, eventData)`, which is a generated call-site/signature error rather than a reason to change the helper signature.
- Added exact anchors for [GetChatButtonAtPoint memory](by-memory/0x00482400-0x004824c8.GetChatButtonAtPoint.md) and [GetChatButtonAtPoint global symbol](by-global/GetChatButtonAtPoint.md). The helper should be file-local in `social/Chatting.cpp` beside `ChattingHandlePane`, not a standalone recovered source file.

### 2026-05-23 - EmotionInputPane current source body is still missing

Observed:

- During command-input pane documentation, Wave3 records `EmotionInputPane::OnCharInput` at `0x005b2a70-0x005b2f67` with a useful summary and notes, but `show method 0x005b2a70` reports `current_code` containing only `struct EmotionMenuList`; the emitted `class_EmotionInputPane.cpp` also lacks the actual function body.
- 2026-05-26 IDA follow-up: live decompilation confirms the missing body reads one character through shared input helpers, lowercases `A-Z`, maps `a-p` to [SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md), and opens a localized emotion menu on `?`. The documentation coverage for the binary method cluster is now medium, but generated source remains incomplete until the emitted `OnCharInput` body is restored.
- The method is now marked incomplete with manual grade `70`, so the remaining issue is the missing source body, not false completion status.
- After the 2026-05-24 body-grader fix, `show grade method 0x005b2a70` fails required `body_not_stub` with `missing_function_definition`; the data issue remains the absent body, not a hidden completion/scoring bug.

Expected:

- `EmotionInputPane::OnCharInput` should contain a recovered function body before source-complete migration.

Impact:

- `EmotionInputPane` behavior can be documented from notes and IDA boundaries, but source reconstruction cannot trust the current emitted method body.

Follow-up:

- Use IDA MCP `decompile` or `analyze_funcs` on `0x005b2a70` and replace the struct-only current code with an actual `OnCharInput` implementation when doing rewrite work.

### 2026-05-24 - `LineInputPane::HandleKeyInput` active output omits real body

Observed:

- Active `source-3/simroot_v2/class_LineInputPane.cpp` has a scoped marker for `LineInputPane::HandleKeyInput` at `0x004f25a0`, but the emitted section contains only local struct declarations before moving on to the next method.
- After the 2026-05-24 body-grader fix, `show grade method 0x004f25a0` fails required `body_not_stub` with `missing_function_definition`, so the high imported/manual score no longer makes the method complete.
- IDA MCP confirms `0x004f25a0-0x004f2753` is a real function.
- IDA decompilation shows the missing body handles Enter/Escape/Tab, pending submit state, active pane dismissal, owner notification, and menu-state cleanup.

Expected:

- Active generated output should emit the real `LineInputPane::HandleKeyInput` body or explicitly mark it as omitted.
- Source migration for input panes should use IDA-confirmed range docs until this emitted body is restored.

Impact:

- New [InputPanes](by-file/InputPanes.md), [LineInputPane](by-class/LineInputPane.md), and [input pane base memory](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md) docs record the IDA-confirmed behavior and the active-output omission.
- Do not migrate `class_LineInputPane.cpp` directly without reconstructing `0x004f25a0`.

Follow-up:

- Recheck `class_LineInputPane.cpp` after Wave3 fixes for `0x004f25a0`.
- Confirm whether the shared pane-base teardown label in `LineInputPane` should remain generic or resolve to a named pane base class.

### 2026-05-23 - Item-action input panes have nearby unowned IDA functions

Observed:

- Wave3 `show memory-at` reports no owner for real IDA functions near this pass:
  - `0x005b6500-0x005b6560` between `WieldInputPane` and `WearInputPane`.
  - `0x005b2f70-0x005b2fcb` before `ChangeItemSlotInputPane`.
  - `0x005aed40-0x005aedcb` and `0x005af2f0-0x005af383` inside the `ItemWhoInputPane` neighborhood.

Expected:

- Real IDA functions in documented neighborhoods should have an owner, exclusion, or explicit unresolved status.

Impact:

- `WieldInputPane` and `WearInputPane` memory docs can stay separate with a documented boundary: `0x005b6500` belongs to the wield side, while `WearInputPane` starts at `0x005b6560`.
- `ItemWhoInputPane` final file placement remains medium-confidence because of shared spell/item target-selection behavior, not because the `0x005aed40` or `0x005af2f0` functions are unknown.

Follow-up:

- Documentation pass on 2026-05-26 resolved ownership from IDA without running Wave3:
  - `0x005b6500-0x005b6560` is [SendWieldPacket](by-memory/0x005b6500-0x005b6560.SendWieldPacket.md), called only by `WieldInputPane::OnSubmitInput`.
  - `0x005b2f70-0x005b2fcb` is [SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md), called only by `EmotionInputPane::OnCharInput`.
  - `0x005aed40-0x005aedcb` is [ItemWhoInputPane's non-deleting destructor](by-memory/0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor.md).
  - `0x005af2f0-0x005af383` is [ItemWhoInputPane's object-list virtual](by-memory/0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual.md), reached through vtable data.
- 2026-05-26 IDA/simroot follow-up: IDA confirms direct item-action input-pane vtable bases from `0x0062f92c` through `0x006305b4`, including `DropAllInputPane`, `DropInputPane`, `DropGoldInputPane`, `GiveAllInputPane`, `GiveInputPane`, `GiveGoldInputPane`, `TakeOffInputPane`, `ChangeItemSlotInputPane`, `ThrowInputPane`, `ThrowReallyInputPane`, `UseInputPane`, `EatInputPane`, `WieldInputPane`, and `WearInputPane`. Current `simroot_v2` metadata for all checked classes still reports `vtable_count: 0`.
- 2026-05-27 IDA raw-disassembly follow-up: [ChangeItemSlotInputPane raw constructor](by-memory/0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor.md) is constructor-shaped code, but `lookup_funcs 0x005b2fd0` still reports `Not a function` and `xrefs_to 0x005b2fd0` reports no direct references. The inline command factory at `0x005a93b0` allocates/constructs the same class and stores vtables `0x0062fa44`, `0x0062fa94`, and `0x0062fac4`.
- 2026-05-27 IDA raw-disassembly follow-up: [DropGoldInputPane raw constructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md) and [GiveGoldInputPane raw constructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md) are constructor-shaped code, but `lookup_funcs` still reports both raw starts as `Not a function` and neither has direct xrefs. The active `DropInputPane` and `GiveInputPane` submit handlers inline equivalent construction branches.
- 2026-05-27 IDA raw-disassembly follow-up: [TakeOffInputPane raw constructor](by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md) and [ThrowReallyInputPane raw constructor](by-memory/0x005b5b30-0x005b5b80.ThrowReallyInputPaneRawConstructor.md) are constructor-shaped code, but `lookup_funcs` still reports both raw starts as `Not a function`. Inline construction paths in command/user helpers store the same vtables, so generated constructor boundaries should remain provisional.
- 2026-05-27 IDA follow-up: [SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md) is a real standalone helper called by both `TakeOffInputPane` and `SelfLookPane`. Do not force it into `TakeOffInputPane` as a private method without preserving the shared caller evidence.
- 2026-05-27 IDA follow-up: [g_equipmentSlotKeys](by-global/g_equipmentSlotKeys.md) is a real fixed table at `0x00630bd8`; [g_activeDialogCount](by-global/g_activeDialogCount.md) is a broader UI/input gate byte at `0x0069b380`. Current generated names are useful leads, but final source names/owners should stay open until the wider UI xrefs are reviewed.
- 2026-05-27 IDA follow-up: [WieldInputPane](by-memory/0x005b62d0-0x005b64fa.WieldInputPane.md), [SendWieldPacket](by-memory/0x005b6500-0x005b6560.SendWieldPacket.md), and [WearInputPane](by-memory/0x005b6560-0x005b6760.WearInputPane.md) have clean IDA-modeled function boundaries and confirmed slot-index formulas. Active `class_WearInputPane.cpp` still contains omitted placeholder comments for lowercase/uppercase slot conversion even though IDA confirms lowercase `input - 0x60` and uppercase `input - 0x26`.
- 2026-05-27 IDA follow-up: [ThrowInputPane](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md), [UseInputPane](by-class/UseInputPane.md), and [EatInputPane](by-class/EatInputPane.md) have clean IDA-modeled function boundaries and confirmed slot-index formulas. `UseInputPane` calls [UseInventorySlotDispatch](by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md); keep the generated `UseSpellSlot` name provisional because inventory-tab and input-pane evidence points to an item-use path. Generated aliases such as `g_pGameData` / `g_pStringTable` for `dword_67A748` / `dword_67A750` should normalize to the player-state and `g_pLanguageMan` docs unless a different address is verified.
- 2026-05-26 IDA disassembly/xref follow-up: `0x005b77c8-0x005b77de` is shared input-pane compiler adjustor glue, not handwritten `TakeOffInputPane` behavior. Added [Shared input-pane adjustor thunks](by-memory/0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks.md), added the range to [by-memory ignored](by-memory/-ignored.md), and added [Item action input pane vtable family](by-type/by-vtable/ItemActionInputPaneVtableFamily.md).
- 2026-05-26 IDA/simroot follow-up: IDA confirms command/social input-pane vtable bases for `EmotionInputPane`, `GroupInputPane`, `PostInputPane`, `SelfSaveInputPane`, `SpellSpellInputPane`, `BlockListenInputPane`, `AddToBlockListenInputPane`, and `DeleteFromBlockListenInputPane`. Current `simroot_v2` metadata for all checked classes still reports `vtable_count: 0`. Added [Command input pane vtable family](by-type/by-vtable/CommandInputPaneVtableFamily.md) as the layout anchor while generated metadata catches up.
- Wave3 should still eventually assign active owners or explicit helper rows for these functions; the data issue is no longer a research blocker.

### 2026-05-23 - DAT archive xref includes a caller boundary mismatch

Observed:

- Wave3 method inspection for `DATFileResolver::Destroy` reported a caller address at `0x0049c750`.
- IDA MCP reports no function at `0x0049c750`; the previous function is `0x0049c720-0x0049c74b`, and the next function is `0x0049c800-0x0049cac4`.
- 2026-05-26 IDA/raw-disassembly follow-up: [0x0049c750-0x0049c7f6](by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md) is real `_DATFileMgr` ordinary destructor-shaped code even though IDA still reports `Not a function` at the start. The resolver destroy call is specifically at `0x0049c7e8`; the modeled scalar deleting destructor calls the same [DATFileResolver destroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md) at `0x0049d462`.
- 2026-05-26 vtable follow-up: IDA confirms one-slot vtables for `DATFileMgr` at `0x00618914` and `_DATFileMgr` at `0x006189cc`, but current `class_DATFileMgr.meta_wave3` and `class__DATFileMgr.meta_wave3` both report `vtable_count: 0`. Added [DAT manager vtables](by-type/by-vtable/DATManagerVtables.md) to record the short boundaries and adjacent-data caveat.

Expected:

- Xref/caller summaries should use IDA-aligned function starts, or clearly label raw non-function starts such as `0x0049c750` as projected/raw code boundaries.

Impact:

- Do not treat `0x0049c750` as an IDA-modeled function, arbitrary data, or a separate source file. It should be restored or tracked as `_DATFileMgr` raw ordinary destructor cleanup.

Follow-up:

- Recheck after Wave3 function-boundary fixes: expected result is a raw/restored `_DATFileMgr` destructor row for [0x0049c750-0x0049c7f6](by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md), with the `0x0049c7e8` resolver-destroy call attached to it.
- Recheck after Wave3 vtable extraction fixes: expected `vtable_count` is at least one for `DATFileMgr` (`0x00618914`) and at least one for `_DATFileMgr` (`0x006189cc`), without reading into adjacent `DATFileContainer` RTTI or `"../"` string data.
- Keep `DATFileResolver` represented as an embedded `_DATFileMgr` resolver/hash-table member unless stronger source-layout evidence proves it was a standalone original class.

### 2026-05-23 - LoadFrameDrawRecord has real code but no notes/manual grade

Observed:

- `search symbol LoadFrameDrawRecord --limit 20` finds global `0x004d1600` and recovered file `LoadFrameDrawRecord_004D1600.cpp`.
- `show global 0x004d1600 --summary` reports no summary, no notes, and no manual/effective grade.
- IDA MCP confirms `0x004d1600-0x004d165d` as a real function and reports ten caller functions across map tile, static/effect/item/new-human, and UI/effect draw paths.
- Generated source uses generic/synthetic names such as `FrameDrawRecord_4D1600`, `reserved`, `reserved2`, `reserved0`, and `reserved8`.

Expected:

- This helper should have a documented summary, stable source-level table/output type names, and a manual grade once the output struct layout is reviewed.

Impact:

- New docs place it under [ImageFrameTable](by-file/ImageFrameTable.md), but source migration should treat the output field names as provisional.

Follow-up:

- Deep-review callers of `0x004d1600` and rename the output struct fields from actual use.
- Check whether the generated `entry[10] - entry[5]` height expression reflects a real wider output record or a decompiler/indexing artifact.

### 2026-05-23 - LoadPcxImage xrefs include non-IDA function caller at 0x005818d0

Observed:

- `show xref 0x004a17b0` reports two caller addresses for `LoadPcxImage`: `0x00581100` and `0x005818d0`.
- IDA MCP confirms `0x00581100-0x005815aa` is `StartupWindow::UpdateCheckWindowProc` and contains six direct calls to `LoadPcxImage`.
- IDA MCP reports no function at `0x005818d0`, `0x005818f1`, or `0x00581984`.
- IDA MCP function enumeration around the area jumps from `0x005817a0-0x005817dd` to `0x00581b80-0x00581ce6`, leaving the `0x005818d0` region outside current IDA function coverage.
- Wave3 `show memory-at 0x005818d0 --include-ignored --include-allowed` reports no owner.
- 2026-05-24 IDA raw-disassembly follow-up, without running `wave3.py`, shows valid unmodeled code starts at `0x005815b0`, `0x005817e0`, `0x00581860`, `0x005818d0`, and `0x005819d0`.
- The raw `0x005818d0-0x005819c9` body lazily loads `brm_main.pcx`, `brm_st_a.pcx`, `brm_st_b.pcx`, `brm_st_c.pcx`, `brm_ex_a.pcx`, and `brm_ex_b.pcx`, then initializes notice button rectangles.

Expected:

- Xref reports should distinguish IDA-confirmed function callers from Ghidra/projected callers in unowned/non-function memory.
- StartupWindow raw helper bodies should become explicit owned functions/helpers or be represented as raw-code boundary records before source migration.

Impact:

- [ImageLoaders](by-file/ImageLoaders.md) treats `0x00581100` as the confirmed startup-window PCX caller and keeps `0x005818d0` as follow-up data debt.
- New [StartupWindow](by-file/StartupWindow.md), [StartupWindow class](by-class/StartupWindow.md), [StartupWindow update memory](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md), [startup update notice resources](by-resource/startup-update-notice-resources.md), and [unmodeled notice helper](by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md) docs capture the helper-family boundary problem.

Follow-up:

- Inspect bytes/decompilation around `0x005818d0-0x00581990` to decide whether IDA missed a function, Ghidra over-created one, or the xrefs point into data/inline jump material.
- Review `0x005819d0` to determine whether it is alternate/dead startup notice setup or an unreferenced helper that still needs source ownership.

### 2026-05-23 - ArticleListPane may include generic helper ownership

Observed:

- The active `BulletinDialog` destructor at `0x0047ea10-0x0047ea4a` is a real IDA function and should remain usable.
- Active `source-3/simroot_v2/class_BulletinDialog.cpp` emits `BulletinDialog::BulletinDialog` at `0x00472000`, but IDA MCP `lookup_funcs` reports `0x00472000` as `Not a function`.
- 2026-05-26 IDA raw disassembly shows `0x00472000-0x0047203a` is still constructor-shaped project code: it calls `0x004a1400`, stores `BulletinDialog` vtables, and returns with `retn 8`.
- `class_BulletinDialog.meta_wave3` reports `vtable_count: 0` even though IDA confirms vtable bases `0x00613ba8`, `0x00613c0c`, and `0x00613c3c`.
- Active `class_BulletinDialog.cpp` does not cleanly document the real vtable-referenced callback at `0x00472040-0x00472069`, which is shared by the board/article dialog secondary tables.
- 2026-05-26 IDA `list_globals` and vtable xref checks confirm three-view vtable bases for `BoardListDialog`, `BoardListPane`, `ArticleListDialog`, `ArticleListPane`, `ArticleDialog`, `NewArticleDialog`, `NewPredefinedFormArticleDialog`, `TransferReplyAlert`, `TransferReplyPredefinedAlert`, `ConfirmDeleteAlert`, and `DeleteReplyAlert`, but each checked current metadata file still reports `vtable_count: 0`.
- Wave3 also attaches several generic-looking helpers to `ArticleListPane` at `0x004f3c00+`, including insertion, removal, sort toggle, and selected-index collection. IDA confirms those are real functions, but the final owner may be shared list-pane infrastructure rather than the article-list feature.

Expected:

- `BulletinDialog::BulletinDialog` should be represented as a raw/projected constructor body or reconciled with IDA function-boundary data before migration.
- Generated vtable inventory should record the three IDA-confirmed `BulletinDialog` table bases instead of `vtable_count: 0`.
- Generated vtable inventory should also record the neighboring board/article dialog, pane, and alert companion table bases now listed in [BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md).
- The shared `0x00472040` secondary-vtable callback should be attached to the board/dialog base family or otherwise documented as shared virtual behavior.
- Generic list helpers should not be treated as final board/article source ownership without a focused caller/owner review.

Impact:

- Added [BulletinDialog raw constructor](by-memory/0x00472000-0x0047203a.BulletinDialogRawConstructor.md), [BoardDialog command-one virtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md), [BulletinDialog vtables](by-type/by-vtable/BulletinDialogVtables.md), and [BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md). Updated [BulletinDialog](by-class/BulletinDialog.md), [BoardDialogs](by-file/BoardDialogs.md), and [board/article dialog memory](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md).
- The `0x004f3c00+` helpers should remain under review before moving them into `BoardDialogs.cpp`.

Follow-up:

- Recheck generated output after Wave3 fixes so `BulletinDialog` does not lose the raw constructor boundary, vtable bases, or shared `0x00472040` virtual callback.
- Recheck generated output after Wave3 fixes so board/article dialog-family metadata does not leave confirmed table bases at `vtable_count: 0`.
- Review callers and shared state for `0x004f3c00`, `0x004f3d60`, `0x004f3dd0`, and `0x004f3e80` before final method-owner changes.

### 2026-05-23 - Application/input/event/platform generated data has owner-name mismatches

Observed:

- Wave3 attaches `0x00597580` to `EventDispatcher::~EventDispatcher`; IDA does define `0x00597580-0x005975c3`, but currently names it `??1exception@boost@@MAE@XZ_4` and it has many unrelated-looking cleanup callers.
- `ApplicationHelper_4A6C40` may be a generated owner for message-loop/event-dispatch helper routines rather than a real original class.
- Earlier AutoInit notes saying only the deleting destructor was visible are stale. IDA now confirms ordinary destructor `0x0046efe0`, scalar deleting destructor `0x00470300`, static shutdown thunk `0x0060c0f0`, and vtable `0x0061373c`; only the final source-file grouping remains unresolved.

Expected:

- Destructor/helper ownership should not be treated as final where IDA naming and caller sets suggest possible owner pollution.

Impact:

- Documentation can still use these ranges, but migration actions such as `rename class`, `attach class`, `set method-owner`, or source-file regrouping should not rely on these disputed entries without a focused follow-up.

Follow-up:

- Decide whether `ApplicationHelper_4A6C40` should be demoted to a file-local scheduler/helper rather than a project class.

2026-05-24 follow-up:

- IDA decompilation of `0x00597580` writes `TimerHandler::vftable` and calls `sub_597A10(dword_67AB80, this)`, so this is timer-handler base cleanup rather than `EventDispatcher` source.
- The old memory page has been replaced with [TimerHandler destructor](by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md). Keep `EventDispatcher` as a timer consumer/derived owner only.

2026-05-26 follow-up:

- IDA MCP recheck confirms `ApplicationHelper_4A6C40` exact ranges: [idle work scheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md) and [baseline capture](by-memory/0x004a7120-0x004a712b.ApplicationIdleTickBaseline.md).
- The helper should remain a generated-owner/source-structure caveat. It is called by `Application::RunMessageLoop`, but its body is scheduler glue spanning [BlackHole](by-file/BlackHole.md), [TimerMgr](by-file/TimerMgr.md), `EventDispatcher::RebuildHandlerTraversalOrder`, and [FrameMgr](by-file/FrameMgr.md), so final source migration should not emit `ApplicationHelper_4A6C40.cpp` as a standalone module.

## Migrated From Wave3 Program Notices - 2026-05-23

These reports were moved from wave3_noticed_problems.md because they describe reconstructed-source/data accuracy problems, not defects in the Wave3 program itself. Fix them with normal Wave3 reconstruction commands and evidence review.

### 2026-05-23 - Button and choice control generated data has helper-owner pollution

Observed:

- `class_ButtonControlPane.cpp` ends the base constructor with `InitializeFittingRoomUserImage(true)`, even though IDA MCP shows `ButtonControlPane::ButtonControlPane` at `0x00494eb0` has generic derived-control callers, including image, gender, direction, and pretty button construction.
- `class_TextButtonExControlPane.cpp` declares destructor helper types through `BowGaugeObjectPane` and emits a copied `Pane::~Pane` body at `0x00544580` inside the text-button file.
- `class_SliderControlPane.cpp` summaries describe a scrollbar and `FittingRoomScrollPane` key dispatch. This may describe behavior, but it should not be treated as proof that the slider class belongs to fitting-room source.
- 2026-05-25 IDA MCP follow-up: `CheckBoxControlPane` primary vtable slot `0x00618520` points at real helper `0x00499ec0`, but active `class_CheckBoxControlPane.cpp` omits that method. The generated constructor names the second copied string `labelName`, while MiniMap/NewMail callers and paint behavior show it is a palette/resource name such as `BUTTON.PAL`.
- 2026-05-26 IDA MCP follow-up: `CheckBoxControlPane` secondary/tertiary destructor thunks `0x0049af27` and `0x0049af32` are real 0xb-byte compiler adjustors into scalar deleting destructor `0x0049b110`. Active disabled output still omits the first thunk body and emits only a decompiler-shaped second thunk body.

Expected:

- Generic button/control helpers should be neutral or use verified owner names instead of feature-pane names.

Impact:

- File ownership research can incorrectly merge generic controls into fitting-room, bow-gauge, or character-creation modules.

Follow-up:

- Verify the target of the `InitializeFittingRoomUserImage`-named call from `ButtonControlPane::ButtonControlPane` and rename/re-own it if generic.
- Revisit `TextButtonExControlPane` destructor ownership after base `Pane` teardown is modeled cleanly.
- `0x00499ec0` is now classified as [CheckBoxControlPane state/type helper](by-item/CheckBoxControlPaneStateTypeHelper_00499EC0.md), but active generated output still omits it.
- Rename the `+0x128` string field to a palette/resource name, and keep `g_pEPFLib` ownership with [ImageLib](by-file/ImageLib.md), not the checkbox file.
- The exact `0x0049af27-0x0049af3d` adjustor-thunk pair is now documented and ignored through [CheckBoxControlPane adjustor thunks](by-memory/0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks.md).

### 2026-05-23 - Scroll core generated code has cross-subsystem helper name pollution

Observed:

- `source-3/simroot_v2/class_ScrollPane.cpp` uses feature-class names such as `RankingEventListPane::GetClipRect`, `FittingRoomDownloadControlPane::RenderTileFrame`, and `FittingRoomListPane::SetTextColor` inside generic `ScrollPane::OnDraw` helper paths.
- `source-3/simroot_v2/class_CScrollBarBackPane.cpp` types destructor support through `BowGaugeObjectPane`, calls `TextButtonExControlPane::~TextButtonExControlPane`, and uses `FittingRoomDownloadControlPane::MoveTo` for fixed scrollbar backplate drawing.
- `source-3/simroot_v2/class_ScrollableControlPane.cpp` similarly calls `TextButtonExControlPane::~TextButtonExControlPane` in the scalar deleting destructor even though the constructor path is `ControlPane` based.

Expected:

- Generic drawing helpers and base-subobject teardown paths should be named through their real owner (`GrafPort`, `Pane`, or another shared UI/drawing helper), or left unresolved until ownership is proven.

Impact:

- File-ownership research can be misled into tying scroll core to fitting-room, ranking-event, bow-gauge, or text-button feature code.
- Automated scoring may over-count unrelated feature-class dependencies for scroll classes.

Follow-up:

- Verify the underlying helper addresses and vtable/subobject offsets, then rename or re-own the generic draw and destructor helpers.
- Recheck `ScrollPane`, `CScrollBarBackPane`, and `ScrollableControlPane` grades after the helper owner names are corrected.

### 2026-05-23 - Text-edit generated code has helper-name and alias owner pollution

Observed:

- `source-3/simroot_v2/class_TextEditPane.cpp` contains generic helper declarations with unrelated feature names, including `OwnerInvalidateFn = void(*)(RankingEventListPane*, RECT*)`.
- `source-3/simroot_v2/recovered/DrawTextRunCallback_00593DB0.meta_wave3` records alias `InvalidateRectFn` with owner contexts from `ScrollSpellInventoryPane` and `ScrollVolumePane`, even though the callback is a text-edit run-render callback used by `TextEditPane::OnDraw` and `TextEditPane::InvalidateSelection`.
- `class_EPFTextEditObject.cpp` has high manual confidence but low auto grade because `LObject`, `EPFFrame`, and EPF resource globals are still unresolved at grading time.

Expected:

- Shared draw/clip helper aliases should keep neutral names or the verified owner, not unrelated feature-pane class names.
- Class auto grades should distinguish missing declaration/type data from bad ownership when the method body and memory ranges are otherwise strong.

Impact:

- File-ownership research can be misled into tying text-edit core to ranking, scroll-volume, or fitting-room feature code.
- `EPFTextEditObject` may look lower-confidence than the actual constructor/destructor evidence supports.

Follow-up:

- Verify the underlying helper addresses used by `DrawTextRunCallback` and `TextEditPane` invalidation, then re-own or neutralize polluted aliases.
- Recheck `EPFTextEditObject` after resolving `LObject`, `EPFFrame`, `g_pEPFResourceManager`, and `g_useEPFFormat` declarations/types.

2026-05-25 text-run callback follow-up:

- IDA MCP reports `0x00593b20` and `0x00593f00` are not functions and have no xrefs, even though current `simroot_v2/class_FittingRoomDownloadControlPane.cpp` emits projected markers there.
- IDA confirms the real nearby callback at `0x00593c20-0x00593ce4`; it has callback-style data xrefs from TextEditPane layout/formatting code and calls only `CountVisibleChars` plus the shared GrafPort text-width helper.
- Documentation now tracks `0x00593c20` as [TextRunMeasureCallback](by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md), a TextEditPane file-local/free callback. Wave3 data should remove or realign the stale `0x00593b20` / `0x00593f00` fitting-room records.

### 2026-05-23 - Static/scrolled text control generated data has owner-name pollution

Observed:

- `source-3/simroot_v2/class_StaticTextControlPane2__SimpleHelpTextPartPane.cpp` references unrelated generated owner names such as `BowGaugeObjectPane` and `TextButtonExControlPane` in destructor support.
- `source-3/simroot_v2/class_ScrolledTextControlPane.cpp` and `class_ScrolledTextControlPaneForMadeBy.cpp` also use provisional base/destructor names such as `TextButtonExControlPane::~Pane` while their constructors clearly build `ControlPane` type `8` scrolled text controls.

Expected:

- Generic static/scrolled text control helpers should not be typed through fitting-room, bow-gauge, or text-button owners unless the underlying vtable/subobject evidence proves that ownership.

Impact:

- File-ownership research can wrongly tie generic text controls to feature-specific classes.

Follow-up:

- Verify destructor/base-subobject addresses for `SimpleHelpTextPartPane`, `ScrolledTextControlPane`, and `ScrolledTextControlPaneForMadeBy`, then neutralize or re-own polluted helper names.

### 2026-05-22 - Alpha-mask surface ownership appears incomplete around `0x00462260-0x004632c0`

Observed:

- Wave3 imports `AlphaMaskSurface` methods at `0x00462170`, `0x004622d0`, `0x00462300`, `0x00462520`, `0x00462680`, and `0x00462870`.
- 2026-05-26 simroot recheck: `class_AlphaMaskSurface.meta_wave3` still lists only those six active methods and reports `vtable_count: 0`, even though IDA confirms the `off_6112EC` vtable references in the constructor/helper/destructor family.
- 2026-05-26 IDA MCP raw-disassembly recheck found constructor-shaped bytes at `0x00462120-0x00462161` that initialize an empty owning alpha surface, but `lookup_funcs` and `xrefs_to` do not prove a callable function boundary.
- 2026-05-26 IDA MCP recheck found `0x00462230-0x00462258` as a compiler-generated EH cleanup target: it restores `off_6112EC`, releases owned pixels, and is reached only from the `0x005fa593` C++ EH funclet.
- IDA MCP decompilation shows nearby functions at `0x00462260`, `0x00462320`, and `0x004623c0` using the same `{bounds,pixels,width,height,stride,ownsBuffer}` layout.
- IDA MCP decompilation shows `0x00462f20` drawing signed-run encoded frame rows into an alpha surface with replace/add/subtract modes; it has nine render/image-library callers but is not currently emitted as a recovered source file.
- 2026-05-26 IDA MCP caller/xref recheck maps the six modeled `0x00462f20` callers to `MonsterImageLib::RenderMonsterImage`, `StaticObjImageLib::RenderStaticObject`, `EffectObjImageLib::RenderEffectFrame`, `ItemObjImageLib::DrawItemImage`, `ItemObjImageLib::DrawItemImageIn43x43Slot`, and `NewHumanImageLib::RenderPreparedComposition`. The remaining raw xrefs at `0x004d5ea6`, `0x004d6b16`, and `0x004dcca5` still have no containing IDA function but disassemble as the same overlay-strength setup before calling `0x00462f20`.
- `IntAlphaSurface` only has a destructor recovered at `0x00463270-0x004632b1`, leaving its constructor/full owner family unidentified.
- IDA MCP identifies `off_6112EC` as the `IntAlphaSurface` vtable. Slot 0 points to `0x00463270`, slot 1 points to `0x00462260`, and data references to the vtable come from `0x0046217b`, `0x00462237`, `0x00462415`, and `0x0046327a`.
- `validate memory-range method 0x00463270` reports exact duplicate coverage between method `0x00463270` and class aggregate `IntAlphaSurface` over `0x00463270-0x004632b0`. This is a one-method-class modeling issue rather than a second implementation body.

Expected:

- Shared alpha-surface helpers should either be owned by `AlphaMaskSurface`/a surface helper file or explicitly recorded as standalone render helpers.
- Raw non-IDA constructor-shaped bytes should be marked as raw/projected evidence until IDA/Wave3 function-boundary metadata is reconciled.

Impact:

- File migration could split one original surface/blitter source file across unrelated staging files and leave the widely used encoded-alpha helper undocumented.
- Added [AlphaMaskSurface raw default constructor](by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md), [AlphaSurfaceReleaseOwnedPixels](by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md), [BuildClippedAlphaSurfaceView](by-item/BuildClippedAlphaSurfaceView_00462320.md), and [InitAlphaSurfaceView](by-item/InitAlphaSurfaceView_004623C0.md) docs so the omitted/raw pieces are visible before source migration.
- Added [IntAlphaSurface unwind cleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md) and marked it in [ignored memory ranges](by-memory/-ignored.md), so the EH-only cleanup target is not mistaken for a missing handwritten method.

Follow-up:

- 2026-05-25 IDA MCP follow-up:
  - `0x00462260` is a real `IntAlphaSurface` vtable-slot helper that frees owned pixel storage and clears the pointer. It has no direct code callers in the current IDA database, but `xrefs_to` ties it to vtable slot data at `0x006112f0`.
  - `0x00462320` is a real clipped alpha-surface view builder with a live `StaticObjImageLib` caller at `0x004dd66a`.
  - `0x004623c0` is a real view initializer that writes `off_6112EC` and constructs a full or clipped `IntAlphaSurface`-style view object. It has no direct code callers in the current IDA database.
  - `0x00462f20` remains a real omitted render helper with nine code xrefs and six directly resolved caller functions. The modeled callers are image-library overlay paths, not independent ownership evidence. It should be imported or assigned after final naming.
  - `0x004632c0` is resolved out of the alpha-surface family. It uses vtable `0x00612574`, participates in static initializer `0x00419e80` and atexit cleanup `0x0060c0b0`, and is now documented as [Application error-state cleanup](by-memory/0x004632c0-0x0046330a.ApplicationErrorStateCleanup.md).
- Reconcile `IntAlphaSurface` with neighboring surface classes once its constructor or full vtable owner is recovered. Current docs keep [IntAlphaSurface](by-file/IntAlphaSurface.md) as a provisional standalone file anchor.
- Recover or classify the three raw `DrawEncodedAlphaFrame` call-site neighborhoods at `0x004d5ea6`, `0x004d6b16`, and `0x004dcca5`; do not create new source owners from those raw call sites until their containing image-library function boundaries are reviewed.
- Review whether Wave3 should allow or ignore exact duplicate class/method ranges when the class aggregate contains exactly one method, or whether `IntAlphaSurface` should remain method-only until more methods are recovered.
- Repair generated vtable inventory so `AlphaMaskSurface`/`IntAlphaSurface` metadata records `off_6112EC` instead of `vtable_count: 0`.

### 2026-05-23 - Palette source grouping has unowned helpers and unresolved singleton storage provenance

Observed:

- `show global-data g_pPaletteLib --summary` now reports `type/type_string: PaletteLib*`, true owner file `class_PaletteLib.cpp`, and no active `global_data_issue`.
- `g_pPaletteLib` still has `primary_address: null`, unresolved memory ranges, and no exact source-line provenance row for the declaration.
- IDA/Wave3 evidence ties `PaletteLib` and `DLPalette` to `render/Palette.cpp`, but the global-data owner has not been assigned to that palette source family.
- `show memory-at 0x00542fa0`, `0x00543450`, and `0x005443a0` returns no active Wave3 memory owner. IDA/prewave show:
  - `0x00542fa0-0x00543020`: slot-state reset helper called by `ScreenPanePaletteState_543D30::ResetSlots`.
  - `0x00543450-0x005435a5`: helper that deep-copies `DLPalette` objects into a `List`; current IDA output reports no direct code xrefs.
  - `0x005443a0-0x005443ab`: tiny constructor-unwind cleanup helper referenced only from `PaletteLib::PaletteLib` unwind metadata; it clears `g_pPaletteLib`.

Expected:

- `g_pPaletteLib` should keep the reviewed `PaletteLib*` type and `class_PaletteLib.cpp` owner unless a later source-layout pass creates a reviewed `render/Palette.cpp` replacement and moves the declaration intentionally.
- Recover or classify the singleton storage address/provenance if IDA/prewave evidence can identify it safely.
- Palette helper functions that are real source behavior should either be imported/named or explicitly marked as lower-only documented helpers; compiler-only unwind artifacts should be excluded/ignored.

Impact:

- Source migration could still omit palette slot-state helpers or lose singleton storage provenance if only emitted C++ text is used.

Follow-up:

- 2026-05-25 IDA MCP follow-up:
  - `g_pPaletteLib` storage is confirmed at `0x0067a7e0` with broad render/UI/image data refs. Constructor/destructor/unwind paths write or clear it at `0x00543743`, `0x00543cfe`, and `0x005443a0`.
  - `0x00542fa0` is documented as [ApplyPaletteEntryMovesToSlotState](by-memory/0x00542fa0-0x0054301f.ApplyPaletteEntryMovesToSlotState.md), called by `ScreenPanePaletteState_543D30::ResetSlots`.
  - `0x00543450` is documented as a real but currently unreferenced [Palette list clone helper](by-memory/0x00543450-0x00543664.PaletteListAndEntryMoveHelpers.md); keep the live/dead decision open.
  - `0x00543f60` and `0x00543f80` are reassigned from `ScreenPanePaletteState` to [PaletteLib palette-filter helpers](by-memory/0x00543f60-0x005440ef.PaletteLibPaletteFilterHelpers.md), because callers load `g_pPaletteLib` into `ecx` before calling them.
- 2026-05-26 IDA MCP follow-up:
  - `ScreenPane::HandleMessage` / `sub_556d50` calls `ScreenPanePaletteState_543D30::SetMode` (`0x00543d30`) and `ResetSlots` (`0x00543ee0`) with `g_pPaletteLib` / `dword_67A7E0` as `this`.
  - `PaletteLib::PaletteLib` initializes the same `+0x04`, `+0x08`, and 25-entry bank fields used by those methods.
  - Treat active `class_ScreenPanePaletteState_543D30.cpp` as a generated/recovered facet or base-class view over `PaletteLib`, not as evidence for a separate `ScreenPane.cpp`-owned singleton.
- Decide whether future Wave3 import should add `0x00542fa0`, `0x00543f60`, and `0x00543f80` as active recovered methods/helpers. `0x00543450` should stay documented-only unless a caller or source-order cue proves it is live.
- Decide whether future Wave3 output should keep `ScreenPanePaletteState_543D30` as a named base/facet class or fold `0x00543d30` and `0x00543ee0` into `PaletteLib` ownership while preserving cross-links from `ScreenPane`.
- Keep [Palette](by-file/Palette.md) as the umbrella source-grouping anchor until these helpers are resolved.

### 2026-05-23 - Generic surface helpers have caller-biased Wave3 owners

Observed:

- `show method 0x004b9820 --summary` reports `FolderTreePane::UpdateSurfaceInfo`, but IDA MCP reports 28 direct callers across unrelated pane/render code. The behavior is surface pitch/height refresh from cached state or a DirectDraw descriptor.
- The paint helper cluster around `0x004b9820-0x004ba24a` has current owners split across `FolderTreePane`, `RankingUserListPane`, `MapPane`, and `FittingRoomDownloadControlPane`.
- `show memory-at 0x004b99f0` returns no active Wave3 owner, while prewave/IDA identify it as a real helper at `0x004b99f0` with callers from `0x004b5810` and `0x005c3950`; IDA later confirmed size `0x73`, so the inclusive range is `0x004b99f0-0x004b9a62`.
- Presentation helpers around `0x00557140-0x00559a0f` are mostly attached to `MapPane`, while `BlitSurfaceToDisplay` is attached to `FolderTreePane`; their summaries and IDA ranges are DirectDraw surface/presentation behavior.
- `g_pfnLockSurface` was initially only typed as a raw reference owned by `class_EPFImageControlPane.cpp`; Wave3 type suggestion only reported that it is called like a function pointer.

Expected:

- Shared surface helpers should have a stable render/surface owner or be explicitly documented as provisional helper functions, rather than being migrated into whichever feature class first exposed them.
- `g_pfnLockSurface` should get a reviewed function-pointer type and source owner once its real target/call convention is recovered.

Impact:

- Source migration could incorrectly place generic paint, scroll-buffer, and presentation routines into chat/tree/ranking/fitting-room/map files.

Follow-up:

- Use [Surface](by-file/Surface.md) as the provisional source-boundary anchor.
- Review the `0x004b9820-0x004ba24a` and `0x00557140-0x00559a0f` helper ranges against class layouts before reassigning Wave3 owners.
- Keep the now-documented `0x004b99f0` helper under [Surface](by-file/Surface.md) until Wave3 can import/assign it without caller-biased ownership.

2026-05-25 follow-up:

- IDA MCP recheck confirms `0x004b99f0` is a real 0x73-byte helper, now documented as [ForwardToTileFrameBlitHelper](by-memory/0x004b99f0-0x004b9a62.ForwardToTileFrameBlitHelper.md). It builds an offset rectangle and forwards through `dword_69B3E8`; direct call sites are `0x004b5917`, `0x005c3b60`, and `0x005c3db0`.
- `g_pfnLockSurface` resolves to generated alias [g_pfnLockSurface](by-global/g_pfnLockSurface.md) over [SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) slot `dword_69B3FC` at `0x0069b3fc`. IDA shows `EPFImageControlPane::LoadAndRenderImage` calling `dword_69B3FC(this, this + 68)`, so the active one-argument generated signature remains a data issue.
- Remaining open work is broader: verify final names/signatures for the whole callback table and review the rest of `0x004b9820-0x004ba24a` before doing Wave3 ownership moves.

2026-05-26 follow-up:

- `class_GrafPort.meta_wave3` emits unresolved global-data `g_maxSurfacePitch` from method `0x004b8e20`, but IDA decompile/disassembly of `GrafPort::UpdateRenderRegion` shows the operand is `word_66DA94` at `0x0066da94`.
- `word_66DA94` is now documented as [g_screenWidth](by-global/g_screenWidth.md), a 16-bit display-width global initialized to `1024`. Its paired height global is [g_screenHeight](by-global/g_screenHeight.md) at `0x0066da98`, initialized to `768`.
- Future Wave3 output should retire or alias `g_maxSurfacePitch`; it should not create a separate `std::uint32_t` surface-pitch global from this evidence.

### 2026-05-22 - `g_pEPFLib` type/owner conflicts between `ImageLib` and `ResourceLayoutTable`

Observed:

- `source-3/simroot_v2/class_ImageLib.cpp` shows `ImageLib::ImageLib` at `0x004cffb0` assigning `g_pEPFLib = this`.
- The same file's destructor at `0x004e64a0` clears `g_pEPFLib`.
- `source-3/simroot_v2/class_ResourceLayoutTable.cpp` owns the `0x004d0120`/`0x004d02f0` lookup family, and generated consumers call those methods through `g_pEPFLib`.
- Several generated files declare `g_pEPFLib` as `ResourceLayoutTable*`, while `ImageLib` constructor/destructor evidence says the global object's concrete lifetime owner is `ImageLib`.

Expected:

- Wave3 ownership/type data should reconcile this as either one `ImageLib` class with EPF layout methods, a documented base/helper slice, or a clearly modeled inheritance/containment relationship.

Impact:

- Documentation should not create two independent globals or assume `ResourceLayoutTable` is a standalone singleton.
- File migration should keep `ImageLib`, `ResourceLayoutTable`, and `g_pEPFLib` together until the class boundary is resolved.

Follow-up:

- Inspect vtable `0x0061b654`, the caller at application initialization `0x004644f4`, and the `List` element shape at `0x2c` bytes.
- Decide whether to merge the `ResourceLayoutTable` method family into `ImageLib` or record a real base/helper relationship before doing Wave3 ownership moves.

2026-05-25 follow-up:

- IDA MCP recheck confirms `0x0067a744` is global storage and `0x0061b654` is vtable data, not functions.
- `xrefs_to 0x0061b654` still only reports the ImageLib constructor/destructor family, while the broad `g_pEPFLib` consumer set continues to call the `ResourceLayoutTable` method family through the same singleton pointer.
- Keep the source-layout decision as [ImageLib](by-file/ImageLib.md) owning `g_pEPFLib`, with [ResourceLayoutTable](by-file/ResourceLayoutTable.md) documented as a close helper/facet until a real base/helper boundary is proven.
- `source-3/simroot_v2/class_CheckBoxControlPane.cpp` also emits a local `ResourceLayoutTable* g_pEPFLib` declaration because the checkbox paint path consumes EPF frames. Treat that as a consumer dependency, not global ownership by the checkbox/control module.

## Additional Data Issues - 2026-05-23

### 2026-05-23 - `MusicControlDialog` helper ownership is split across unknown and `ChattingColorPane` records

Observed:

- Wave3 reports `MusicControlDialog` with five modeled methods, but IDA MCP confirms additional starts inside the same `0x00528e60-0x0052a535` island: `0x00529770`, `0x00529be0`, `0x00529c60`, `0x0052a010`, `0x0052a2d0`, and `0x0052a310`.
- `source-3/simroot_v2/class_MusicControlDialog.cpp` currently calls `ChattingColorPane::ApplyMusicPlaybackState(this)`, assigns the folder callback target as `ChattingColorPane::OnFolderPathSelected`, and calls `ChattingColorPane::CloseDialog(this)`.
- Wave3 owns `0x00529ee0` as `ChattingColorPane::OnMusicPathInput` and `0x0052a120` as `ChattingColorPane::ApplyMusicPlaybackState`, but IDA xrefs tie those helpers to `MusicControlDialog::HandleControlCommand` and the folder-path callback path.
- IDA confirms `0x0052a540` begins the next create-user dialog block, so the music-dialog helper island has a clear upper boundary.

Expected:

- Music-dialog-specific folder-path, playback-state, drive-popup, SFX-enable, and playback-output helpers should be owned by `MusicControlDialog` or a local `MusicControlDialog.cpp` helper group unless contrary evidence appears.
- `ChattingColorPane` should not own music-control methods that are only called by `MusicControlDialog` paths.

Impact:

- Source-layout documentation should use [MusicControlDialog](by-file/MusicControlDialog.md) and [0x00528e60-0x0052a535](by-memory/0x00528e60-0x0052a535.MusicControlDialog.md) as the current anchor, not the polluted `ChattingColorPane` ownership.
- Future Wave3 class/file migrations may otherwise split one original music dialog source across chat-color, generic function-object, and unknown-helper files.

Follow-up:

- Reassign or import the unmodeled IDA-confirmed helper starts after final naming.
- Move or alias `0x00529ee0` and `0x0052a120` out of `ChattingColorPane` ownership if the next Wave3 ownership pass supports edits.
- Recheck the `0x0049dad0` close helper separately; it may be common dialog close behavior rather than either chat-color or music-dialog specific ownership.

### 2026-05-23 - `UserListDialogPane` and `PartySearchEditPane` source data has materialization and naming caveats

Observed:

- `show class UserListDialogPane --summary` reports a low effective class grade because the current generated source has missing helper references, synthetic layout overlays, unresolved `UserListPane`/`AddUserListSourceMessage_59DE60` references, and a stale `UserListDialogPane::OnInputEvent` dependency that older notes identify as a `DialogPane` duplicate-shadow.
- `class_UserListDialogPane.cpp` emits useful behavior but should not be treated as migration-ready source until the helper/class references are materialized cleanly.
- Wave3 names `0x0059e0d0` like `~PartySearchEditPane`, but its signature, generated body, and IDA behavior are constructor-shaped: it calls `DialogPane::DialogPane`, installs party-search vtables, creates `DLGSETUP.EPF` controls, and returns `this`.
- IDA MCP confirms generic `CheckBoxTextControlPane` functions are physically interleaved with the user-list/party-search island at `0x0059ded0-0x0059e0ab` and `0x0059efeb-0x0059f0a4`.
- 2026-05-24 follow-up: IDA decompiles `0x004214c0` as a tiny helper returning constant `22` (`0x16`), so the current Wave3 summary "Returns the checked state of the checkbox" is incorrect.
- 2026-05-24 follow-up: `0x0059ded0` has constructor-shaped bytes but no IDA function object or direct code xrefs; `PartySearchEditPane::PartySearchEditPane` inlines equivalent `CheckBoxTextControlPane` setup at `0x0059e22f-0x0059e265`.
- 2026-05-24 follow-up: IDA recognizes `0x0059df30` as a separate vtable/base teardown helper for `CheckBoxTextControlPane`, but it is not present in the active generated partition.
- 2026-05-26 follow-up: IDA MCP vtable/layout review confirms `CheckBoxTextControlPane` vtables at `0x0062e99c`, `0x0062ea04`, and `0x0062ea34`; the adjustor thunks at `0x0059efeb` and `0x0059eff6` are compiler-generated vtable glue into scalar deleting destructor `0x0059f050`.

Expected:

- `UserListDialogPane`, `UserListPane`, `PartySearchEditPane`, and `AddUserListSourceMessage_59DE60` should materialize with stable helper/class references before source migration.
- `0x0059e0d0` should be named as the `PartySearchEditPane` constructor unless a later boundary review proves otherwise.
- Generic checkbox controls should stay owned by reusable control documentation rather than being absorbed into `social/UserListDialogPane.cpp` solely because of physical locality.
- `0x004214c0` should be summarized/named as a control-type helper, not checked-state access; checked state is the byte at offset `+0x108`.
- `0x0059df30` should be modeled, excluded with rationale, or otherwise accounted for during `CheckBoxTextControlPane` ownership review.
- `0x0059efeb-0x0059f001` should be marked as compiler-generated adjustor thunk glue, not reconstructed as normal source methods.

Impact:

- New [UserListDialogPane](by-file/UserListDialogPane.md) and [0x0059bc90-0x0059f25b](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md) docs use IDA-confirmed boundaries and explicitly exclude the interleaved checkbox-control ranges.
- Future ownership moves should not rely only on the current generated `class_UserListDialogPane.cpp` text or the misleading `~PartySearchEditPane` display name.
- `CheckBoxTextControlPane` documentation now records the `0x004214c0` summary mismatch, the non-IDA constructor bytes at `0x0059ded0`, the unmodeled IDA function at `0x0059df30`, and the verified field/vtable evidence in [SpecializedButtonPane layouts](by-type/by-struct/SpecializedButtonPaneLayouts.md) and [SpecializedButtonPane vtables](by-type/by-vtable/SpecializedButtonPaneVtables.md).

Follow-up:

- Recheck `UserListDialogPane` source generation after `UserListPane` and `AddUserListSourceMessage_59DE60` are available to the materializer.
- Rename or correct the canonical method metadata for `0x0059e0d0`.
- Keep `CheckBoxTextControlPane` under `ui/controls` unless caller/layout evidence proves a different original grouping.
- Correct `0x004214c0` method summary and decide whether `0x0059df30` should be imported as a method or marked as an intentional helper/exclusion.
- Keep `0x0059efeb-0x0059f001` out of handwritten source output except as compiler-generated adjustor thunk artifacts.

### 2026-05-23 - `OptionPane`/`NewOptionPane` helper ownership and materialization is incomplete

Observed:

- IDA MCP confirms real option-pane helper starts at `0x0053dd50`, `0x0053e1e0`, and `0x0053e380` inside the older `OptionPane` neighborhood, but Wave3 does not list them as `OptionPane` methods/globals.
- IDA MCP confirms real `NewOptionPane` neighborhood functions at `0x00540db0` and `0x00541040`; `show method` and `show global` report unknown rows for both.
- Wave3 models `NewOptionPane::ApplyServerOptions` at `0x00540f50`, but IDA does not currently define a function at that address even though the bytes are function-prologue-shaped.
- `0x00541660` and `0x005416d0` are currently owned by `FittingRoomDownloadControlPane`, but IDA xrefs in this pass tie them to `NewOptionPane::OnPaint`, and their behavior is option-button text/tile drawing.
- 2026-05-25 follow-up: IDA MCP `lookup_funcs` confirms `0x00541660` size `0x70` and `0x005416d0` size `0x183`; `callers` reports every direct caller for both helpers inside `NewOptionPane::OnPaint` at `0x00540600`.
- `source-3/simroot_v2/class_NewOptionPane.cpp` calls `DrawSectionHeader` and `DrawOptionButton`, but those bodies are not emitted in that file; `source-3/simroot_v2/class_FittingRoomDownloadControlPane.cpp` currently emits the corresponding bodies as `DrawBoldText` and `DrawButtonItem`.
- `SendOptionPacket11B_540E50` is modeled as a global helper, while the older `0x0053e380` opcode `0x11b` sender in the `OptionPane` block is not modeled, so option packet helper ownership is uneven.

Expected:

- Older `OptionPane` helper/destructor/update functions should be owned, explicitly excluded, or documented as unresolved local helpers.
- `0x00540db0` and `0x00541040` should be imported/owned or recorded as unowned option helpers before source migration.
- `0x00540f50` should be marked as a projected/non-IDA boundary or aligned with an IDA-confirmed function record after focused boundary review.
- Option paint helpers should not remain under fitting-room ownership if caller review confirms they are local to `NewOptionPane::OnPaint`.
- Duplicate or parallel opcode `0x11b` send helpers should be named consistently and grouped by real caller/use.

Impact:

- New [OptionPane](by-file/OptionPane.md), [0x0053d820-0x0053e3c0](by-memory/0x0053d820-0x0053e3c0.OptionPane.md), and [0x0053ff90-0x00541b2a](by-memory/0x0053ff90-0x00541b2a.NewOptionPane.md) docs use IDA-confirmed boundaries and mark the helper caveats before migration.
- Added exact helper pages for [0x00541660](by-memory/0x00541660-0x005416cf.NewOptionPaneDrawBoldText.md) and [0x005416d0](by-memory/0x005416d0-0x00541852.NewOptionPaneDrawOptionButtonItem.md), documenting the likely `NewOptionPane` owner and the current fitting-room owner pollution.
- Added exact helper pages for [0x0053e1e0](by-memory/0x0053e1e0-0x0053e377.OptionPaneServerOptionResponse.md), [0x0053e380](by-memory/0x0053e380-0x0053e3c0.OptionPaneSendOptionPacket11B.md), [0x00540db0-0x00541114](by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md), [0x00540e50](by-memory/0x00540e50-0x00540e90.SendOptionPacket11B.md), and [SendOptionPacket11B_540E50](by-global/SendOptionPacket11B_540E50.md).
- Do not migrate `FittingRoomDownloadControlPane::DrawBoldText` or `DrawButtonItem` as fitting-room code without reviewing the `NewOptionPane::OnPaint` caller evidence.

Follow-up:

- Import or assign `0x0053e1e0`, `0x0053e380`, `0x00540db0`, and `0x00541040` after applying the naming review recorded in the new memory pages.
- Review `0x00540f50` after IDA/Wave3 boundary cleanup; it is now documented as the raw/projected `NewOptionPane::ApplyServerOptions` body inside the helper island.
- Move `0x00541660` and `0x005416d0` to `NewOptionPane` or a neutral option-paint helper owner after correcting the generated owner metadata; provisional names are `DrawSectionHeader` and `DrawOptionButton`.
- `0x0053e380` and `SendOptionPacket11B_540E50` should share the `SendOptionPacket11B` naming pattern, but stay separate old/local and new/shared function bodies because IDA caller sets differ.

### 2026-05-23 - Macro edit-control helper/thunk materialization is incomplete

Observed:

- IDA MCP confirms real macro edit-control helper starts at `0x0057f7b0` and `0x0057fa80`, but `show method` reports unknown rows for both.
- IDA MCP confirms the tiny function run `0x00580640-0x00580686` immediately before `IntegrateMacroEditControlPane::ScalarDeletingDestructor`; current Wave3 class listings do not expose each thunk/helper consistently.
- `0x0057f6a0-0x0057f741` is a `SpellInventoryPane` destructor immediately before the macro edit-control island, so physical locality alone can mislead range ownership around the start of the macro-control docs.
- 2026-05-24 follow-up: IDA decompiles `0x0057f7b0` and `0x0057fa80` as vtable-reset/base-teardown helpers for `SpellMacroEditControlPane` and `NewMacroEditControlPane`, respectively. Current `xrefs_to` reports no direct references to either helper.
- 2026-05-24 follow-up: IDA decompiles `0x00580645`/`0x00580650`, `0x0058065b`/`0x00580666`, and `0x00580671`/`0x0058067c` as adjustor thunks to `IntegrateMacroEditControlPane`, `NewMacroEditControlPane`, and `SpellMacroEditControlPane` scalar deleting destructors. `0x00580640` is a vtable thunk to `RadioGroupControlPane::Activate`.

Expected:

- Macro edit-control helper and destructor-thunk starts should be owned, explicitly excluded, or consistently represented as omitted compiler/vtable helpers.
- The `SpellInventoryPane` destructor should remain excluded from macro ownership despite adjacency.

Impact:

- New [MacroDialogs](by-file/MacroDialogs.md) and [0x0057f750-0x005807c5](by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md) docs use IDA-confirmed ranges and now cross-reference the reviewed helper/thunk pages before migration.
- Do not migrate macro edit controls directly from generated source without accounting for the unknown helper starts.
- The macro edit-control class docs now record the resolved helper/thunk meanings and should be used as the source-layout anchor until Wave3 data is refreshed.
- Added exact reviewed helper/thunk pages for [0x0057f7b0](by-memory/0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper.md), [0x0057fa80](by-memory/0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper.md), and [0x00580640-0x00580686](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md).

Follow-up:

- Treat `0x0057f7b0`, `0x0057fa80`, and `0x00580640-0x00580686` as reviewed destructor/vtable support. They may be imported as explicit helpers/thunks if the materializer needs them for class layout, but they should not be renamed as macro-row behavior.
- Keep the macro-control range start at `0x0057f750` unless new evidence moves the preceding `SpellInventoryPane` destructor ownership.

### 2026-05-23 - `GeneralPurposePanel` child-tab helpers are owned by `SpellOneArgInputPane`

Observed:

- IDA MCP confirms child lookup and tab-switch helpers in the `GeneralPurposePanel` neighborhood at `0x004b85f0`, `0x004b8620`, `0x004b8630`, and `0x004b8650`.
- Wave3 currently owns all four helpers as `SpellOneArgInputPane`, even though IDA decompilation shows they index the general-purpose panel child array, use the active pane id, and lay out active child panes.
- IDA MCP confirms `0x004b89a0` as the analogous one-child activation/layout helper for `GeneralPurposePanel2`, but Wave3 currently reports it as unknown.
- 2026-05-25 follow-up: IDA MCP `lookup_funcs` confirms all panel helper starts and sizes; `0x004b8a80` clears `dword_69B358` / `g_pGeneralPurposePanel2`, while `0x004b8a90` clears `dword_67A874` / `g_pGeneralPurposePanel`.
- 2026-05-25 follow-up: `source-3/simroot_v2/class_GeneralPurposePanel.cpp` and `class_GeneralPurposePanel2.cpp` emit constructor/destructor/global-data rows but still omit or mis-own the active child/tab helpers; `class_SpellOneArgInputPane.cpp` still emits the four seven-child helpers.
- Generated `PanelPane::~PanelPane` calls a `TextButtonExControlPane`-named teardown path even though `PanelPane::PanelPane` constructs through `Pane::Pane(this, 1)`.
- Disabled `source-3/simroot_v2/class_PanelPane.cpp.disabled` lists `0x005450ef` as missing code, but IDA MCP confirms `0x005450ef-0x005450f9` as a real 0xb-byte adjustor thunk with vtable data xref at `0x00621ac0`.

Expected:

- `0x004b85f0`, `0x004b8620`, `0x004b8630`, and `0x004b8650` should be re-owned to `GeneralPurposePanel` or a neutral panel helper after review.
- `0x004b89a0` should be imported/owned or explicitly recorded as an unresolved `GeneralPurposePanel2` helper.
- `PanelPane` destructor/base teardown should use a real base-pane owner or neutral unresolved label rather than a text-button feature owner.
- `0x005450ef` should be materialized or explicitly classified as a real PanelPane adjustor thunk rather than missing code.

Impact:

- New [GeneralPurposePanel](by-file/GeneralPurposePanel.md), [PanelPane](by-file/PanelPane.md), [0x004b83d0-0x004b8bd3](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md), and [0x00545090-0x00545164](by-memory/0x00545090-0x00545164.PanelPane.md) docs use IDA-confirmed boundaries and flag the helper ownership caveats.
- Added exact helper/global docs for [GeneralPurposePanel child accessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md), [GeneralPurposePanel::SwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md), [GeneralPurposePanel2::SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7e.GeneralPurposePanel2SwitchActiveChild.md), [singleton clear helpers](by-memory/0x004b8a80-0x004b8a9a.GeneralPurposePanelSingletonClearHelpers.md), [g_pGeneralPurposePanel](by-global/g_pGeneralPurposePanel.md), and [g_pGeneralPurposePanel2](by-global/g_pGeneralPurposePanel2.md).
- 2026-05-26 follow-up: added [PanelPane vtables](by-type/by-vtable/PanelPaneVtables.md) and [PanelPane adjustor thunks](by-memory/0x005450ef-0x00545104.PanelPaneAdjustorThunks.md). IDA confirms vtable bases at `0x00621a70`, `0x00621ac0`, and `0x00621af0`; `0x005450ef` and `0x005450fa` are real 11-byte adjustor thunks, not missing code.
- Do not migrate those helper methods with spell input or text-button code until ownership is corrected.

Follow-up:

- Correct the generated owner metadata so `0x004b85f0`, `0x004b8620`, `0x004b8630`, and `0x004b8650` belong to `GeneralPurposePanel`, and `0x004b89a0` belongs to `GeneralPurposePanel2`.
- Reconcile `PanelPane` destructor base-owner labels with the real `Pane` teardown path, and materialize/classify `0x005450ef` as a real adjustor thunk instead of missing code.

### 2026-05-23 - `UserLookPane` local child panes and destructor helper need ownership cleanup

Observed:

- Wave3 splits `MoreInfoPane`, `ProfilePane`, and `LegendPane` into separate class-first emitted files, but IDA shows `MoreInfoPane` and `ProfilePane` are allocated directly inside `UserLookPane::UserLookPane` and only provide two always-false vtable gates each.
- IDA confirms `LegendPane::LegendPane` at `0x0056c400-0x0056c493` with xrefs from `0x0056571c`, `0x0056ff6e`, and `0x0059f428`; the last is `UserLookPane::UserLookPane`, while the first two are self-look paths. This makes `LegendPane` a shared look child rather than a strictly user-look-local class.
- IDA confirms a real function at `0x0059f500-0x0059f604` that decompiles as the non-deleting `UserLookPane` cleanup/destructor body, but `python source-3\wave3d.py show method 0x0059f500 --summary` reports `Unknown method`.
- Wave3 correctly models the scalar deleting destructor at `0x005a23f0`, which contains the same cleanup body plus the conditional delete branch.

Expected:

- `MoreInfoPane` and `ProfilePane` should either be represented as local classes in `UserLookPane.cpp` or have explicit source-layout notes explaining why they remain separate files.
- `LegendPane` should be assigned after self-look caller review instead of being treated as exclusively owned by `UserLookPane`.
- `0x0059f500` should be imported/owned or explicitly excluded as compiler-generated EH/non-deleting destructor support for `UserLookPane`.

Impact:

- New [UserLookPane](by-file/UserLookPane.md), [0x0059f260-0x005a2523](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md), and [0x0056c400-0x0056c493](by-memory/0x0056c400-0x0056c493.LegendPane.md) docs use the IDA-confirmed boundaries and mark the shared `LegendPane` caveat before migration.
- Do not migrate four separate original source files solely from the current Wave3 class-first emitted file split.

Follow-up:

- Review `SelfLookPane` and the `0x0056571c` / `0x0056ff6e` callers before finalizing `LegendPane` file ownership.
- Add or exclude `0x0059f500` in Wave3 metadata with a clear destructor-helper role.

### 2026-05-23 - `SelfLookPane`/`SelfLookPane2` helper boundaries are incomplete

Observed:

- IDA confirms real `SelfLookPane` functions at `0x005657e0`, `0x005671e0`, and `0x005693d0`, but `show method` reports unknown rows for these starts.
- IDA confirms real `SelfLookPane2` functions at `0x00570030`, `0x00572120`, `0x00572f30`, and `0x00572fd0`, but `show method` reports unknown rows for these starts.
- Wave3 models `SelfLookPane2::ToggleBodyOption`, `ToggleFaceOption`, and `ToggleHairOption` at `0x00570940`, `0x00570a00`, and `0x00570ac0`; IDA currently has no function records at those exact starts, no exact xrefs, and only function-prologue-shaped bytes there.
- `SpelledPane` and `LegendPane` are emitted as separate class-first files. IDA caller evidence shows they are shared child panes: `SpelledPane` is constructed by `SelfLookPane`, `SelfLookPane2`, and a system-message/new-system-message path; `LegendPane` is constructed by `SelfLookPane`, `SelfLookPane2`, and `UserLookPane`.

Expected:

- The IDA-confirmed self-look helper/destructor/event functions should be imported/owned or explicitly excluded with reasons.
- `SelfLookPane2` projected toggle starts should be reconciled with IDA function boundaries before migration.
- Shared child panes should have explicit source-layout ownership notes instead of being treated as one-class original `.cpp` files by default.

Impact:

- New [SelfLookPane](by-file/SelfLookPane.md), [SpelledPane](by-file/SpelledPane.md), [LegendPane](by-file/LegendPane.md), [0x00565610-0x0056a373](by-memory/0x00565610-0x0056a373.SelfLookPane.md), [0x0056fe80-0x005729c3](by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md), and [0x0056bb20-0x0056c3f1](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md) docs use IDA-confirmed ranges and mark boundary caveats before migration.
- Do not migrate `SelfLookPane2` toggle helpers or destructor support solely from Wave3 projected boundaries without reviewing IDA boundary creation/ownership.

Follow-up:

- Review and assign `0x005657e0`, `0x005671e0`, `0x005693d0`, `0x00570030`, `0x00572120`, `0x00572f30`, and `0x00572fd0`.
- Decide whether IDA should define functions at `0x00570940`, `0x00570a00`, and `0x00570ac0` or whether Wave3 should mark those as projected/non-IDA boundaries.
- Use the extra `SpelledPane` xref from `0x005886bd` during final `SpelledPane.cpp` versus `SelfLookPane.cpp` source split review.

### 2026-05-23 - `UserPane` source ownership is polluted by adjacent helpers

Observed:

- IDA confirms `UserPane` constructor/destructor and virtual anchors at `0x005a2530`, `0x005a2c60`, `0x005a40d0`, `0x005a4310`, `0x005a5b80`, `0x005a5bd0`, `0x005a76c0`, `0x005a83b0`, `0x005a8840`, `0x005a8e70`, `0x005a8f60`, and `0x005b8230`.
- Wave3 reports unknown rows for IDA-confirmed `UserPane`-local starts `0x005a2c60` and `0x005a2d80`.
- The same address neighborhood contains many non-`UserPane` functions. Wave3 already identifies examples as `LivingObjectPane`: `0x005a2e00`, `0x005a4530`, `0x005a5a90`, `0x005a87e0`, `0x005a88d0`, and `0x005a8cf0`.
- Wave3 currently lists chat/history helpers such as `0x005a4930`, `0x005a4990`, `0x005a49e0`, `0x005a4ab0`, and `0x005a4c30` under `UserPane`, but existing social docs tie that family to chat/say-input behavior and callers.

Expected:

- `0x005a2c60` should be imported/owned or explicitly excluded as the `UserPane` non-deleting destructor helper.
- `0x005a2d80` should be assigned or documented as a user-name/global label helper.
- Chat/history helpers should be reviewed for movement to [SayInputPanes](by-file/SayInputPanes.md) or [Chatting](by-file/Chatting.md), not migrated blindly with `UserPane`.
- `LivingObjectPane` helpers should stay with living-object/movement docs.

Impact:

- New [UserPane](by-file/UserPane.md) and [0x005a2530-0x005b8395](by-memory/0x005a2530-0x005b8395.UserPane.md) docs use IDA-confirmed anchors and mark adjacent exclusions before migration.
- Do not use the broad `class_UserPane.cpp` emitted file as a one-to-one original source layout without pruning the adjacent social and living-object helper ownership.

Follow-up:

- Review `0x005a4930-0x005a4c8b` against `ChatInputPane`, `SayInputPane`, and `SayToUserNameInputPane` callers before deciding final file ownership.
- Use the new `LivingObjectPane` class/file docs for the movement/object helpers interleaved around `UserPane`.

### 2026-05-23 - `LivingObjectPane` has projected helper starts that are not IDA function boundaries

Observed:

- Wave3 reports `LivingObjectPane` grade `94.8`, 78 modeled methods, and zero missing target refs.
- IDA confirms the main core and local-player extension anchors, including constructors/destructors at `0x0053a110`, `0x0053a360`, `0x0053a5a0`, `0x0053d430`, movement/action anchors at `0x005a2e00`, `0x005a5a90`, `0x005a88d0`, `0x005a8cf0`, and packet/action anchors at `0x005aa480`, `0x005aa710`, `0x005aac80`, `0x005ab090`, `0x005ab410`, `0x005ab860`, `0x005abda0`, `0x005ac280`, `0x005acc30`, and `0x005ad360`.
- IDA does not currently define functions at Wave3-projected `LivingObjectPane` starts `0x005a3a20`, `0x005a9250`, `0x005aaff0`, `0x005ac1b0`, `0x005ac7e0`, or `0x005ac9a0`.
- `LivingObjectPane__BoxRotator` is emitted as a separate class/file, but IDA references `0x0053d030` from `??_7BoxRotator@LivingObjectPane@@6B@`, suggesting a nested/private helper in `LivingObjectPane.cpp`.

Expected:

- The projected helper starts should be reviewed against IDA disassembly before source migration, rename propagation, or memory-range claims.
- If those starts are real hidden functions, create or repair IDA/Wave3 boundaries. If they are internal labels or bad splits, Wave3 should mark them as projected/non-IDA and avoid treating them as confirmed function boundaries.
- `LivingObjectPane__BoxRotator` should likely be documented/migrated as `LivingObjectPane::BoxRotator` or a private helper under `LivingObjectPane.cpp`, not as an independent gameplay source file.

Impact:

- New [LivingObjectPane](by-file/LivingObjectPane.md), [LivingObjectPane class](by-class/LivingObjectPane.md), [0x0053a110-0x0053d817](by-memory/0x0053a110-0x0053d817.LivingObjectPaneCore.md), and [0x005a2de0-0x005ad440](by-memory/0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions.md) docs use IDA-confirmed anchors and mark projected starts separately.
- Do not use the broad `class_LivingObjectPane.cpp` emitted file as a one-to-one original source layout without checking the projected helper starts.

Follow-up:

- Review IDA bytes/callers for `0x005a3a20`, `0x005a9250`, `0x005aaff0`, `0x005ac1b0`, `0x005ac7e0`, and `0x005ac9a0`.
- Decide whether to repair Wave3 boundaries or annotate those rows as non-function projections.

### 2026-05-23 - Object-pane companion callers and balloon refresh boundary need cleanup

Observed:

- Wave3 reports `BalloonObjectPane::RefreshBubbleSurface` at `0x00468250` as an active method with imported code range `0x00468250-0x004682bb`, and `inspect method 0x00468250 --include-code` includes a Ghidra assembly/decompiled payload with a normal prologue and return.
- IDA MCP currently reports no function record at `0x00468250`, even though IDA confirms the surrounding `BalloonObjectPane` functions at `0x00467b30`, `0x004682c0`, `0x00468520`, `0x00468800`, `0x00468ab0`, `0x00468ae0`, `0x00468b90`, and `0x00468f80`.
- IDA confirms real MapPane-side constructor caller functions for object-pane companions that Wave3 currently reports as unknown, including `0x0050dfa0`, `0x0050e100`, `0x0050e690`, and `0x0050ef00`.
- Current generated `BowGaugeObjectPane::OnPaint` calls helpers named through fitting-room classes, but IDA shows `BowGaugeObjectPane` is constructed by `UserPane::UserPane` at `0x005a2956` and constructs through `Pane`, not the fitting-room dialog path or the attached-object base.

Expected:

- `0x00468250` should either be defined/aligned in IDA, marked as a Wave3/Ghidra-only recovered function with a boundary caveat, or reconciled if the IDA database intentionally excludes it.
- The MapPane caller starts should be imported/owned, explicitly excluded, or recorded as unresolved packet/helper functions so companion class docs do not rely on unknown rows.
- Bow gauge drawing helper names should be reviewed and neutralized if they are generic render helpers mislabeled through fitting-room owners.

Impact:

- New [ItemObjectPane](by-file/ItemObjectPane.md), [AttachedObjectPane](by-file/AttachedObjectPane.md), [BowGaugeObjectPane](by-file/BowGaugeObjectPane.md), and related by-memory docs use IDA-confirmed ranges where possible and mark `0x00468250` separately.
- Do not migrate `0x0050dfa0`, `0x0050e100`, `0x0050e690`, or `0x0050ef00` as unknown/unowned gaps without first reviewing their MapPane packet roles.
- Do not move `BowGaugeObjectPane` into `cashshop/FittingRoom.cpp` solely because the current generated method body contains fitting-room helper owner labels.

Follow-up:

- Create or repair IDA/Wave3 function ownership for `0x00468250`, `0x0050dfa0`, `0x0050e100`, `0x0050e690`, and `0x0050ef00`.
- Review the helpers called from `BowGaugeObjectPane::OnPaint` and assign them to generic render/UI helpers or the real owning classes.

### 2026-05-24 - Runtime effecter source-layout still has non-IDA constructor caveats

Observed:

- 2026-05-26 recheck: IDA still reports `0x0055a2a0`, `0x0055b000`, `0x0055b090`, `0x0055b110`, `0x0055b4a0`, and `0x0055b810` as not function records, but raw disassembly confirms constructor-shaped project code at each start.
- 2026-05-26 documentation follow-up: added [ScreenEffecter small constructor boundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md) with exact constructor ranges, vtable stores, and the distinction between raw-code evidence and IDA-modeled function records.
- 2026-05-26 global-data follow-up: old `g_pScreenEffecterList` output is a stale alias for `dword_69B364` / `0x0069b364`. IDA shows startup writes at `0x004f6268`, shutdown release/clear at `0x004f64ff`/`0x004f6594`, broad `InitializeMainUiGraph` pane setup use, and `SolidColorFilterEffecter` only as one consumer at `0x0055ae9a`. Do not create a `ScreenEffecterList` type or keep this global under `render/Effects.cpp`.
- Wave3 memory ranges for those six constructors are now marked `non_ida_function_boundary` with explicit marker reasons.
- Active output still emits these effecters as one-class files; `Effects.cpp` is not currently an active Wave3 file, so the remaining issue is source-layout migration/ownership, not missing range metadata.

Expected:

- Keep the confirmed larger methods grouped with the runtime effects module when that source file is created or attached.
- Do not treat the small constructor-only rows as IDA-confirmed function boundaries unless IDA function records are later created.
- Treat fitting-room/download labels in overlay effecter output as helper provenance, not source-file ownership.

Impact:

- Source migration should use [Effects](by-file/Effects.md) and [runtime screen effecter memory](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) as the grouping evidence instead of taking active one-class filenames as final source layout.

Follow-up:

- Create/attach the runtime effects source module when ownership migration is ready, then recheck generated output and update effecter docs if IDA function definitions are created.

### 2026-05-24 - Browser global-data aliases have broad owner/type pollution

Observed:

- `BrowserControlPane` generated source uses both `DAT_0067ab28` and `g_activeBrowserControlPane` for the active control-pane slot. IDA xrefs to `0x0067ab28` include browser constructor/destructor paths, but also broader UI/frame/timer references outside the browser cluster.
- `BrowserControlPane::HandleBrowserDispatchEvent` uses `g_browserRuntime` in the default dispatch case. IDA MCP follow-up on 2026-05-25 resolves this generated name to `dword_67A7CC`, the same storage now documented as [g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md).
- 2026-05-26 IDA `py_eval` recheck confirms `0x0067a7cc` is a 4-byte `.data` item named `dword_67A7CC` with 145 xrefs, `BrowserControlPane::HandleBrowserDispatchEvent` at `0x0046c960-0x0046caf0` reads it, and no IDA name contains `browserRuntime`.
- `g_browserControlKeyCallback` is used by browser Tab/Escape forwarding, but IDA xrefs to the candidate storage include non-browser network/transport functions. Generated browser sources also call the same broad role `g_pTransportCallback`.
- 2026-05-26 IDA `py_eval` recheck confirms `0x0069bec4` is initialized to `0xffffffff`, has one modeled startup/setup write at `0x0041a474`, two raw writes at `0x005997ae` and `0x005999e4`, two browser calls, and many transport/socket calls. Treat `g_browserControlKeyCallback` as a browser consumer alias over app/transport callback storage, not browser-owned state.
- 2026-05-26 IDA decompilation recheck of `0x0067ab28` narrows the earlier `g_activeBrowserControlPane` concern: the broad application/presentation refs use the active `BrowserControlPane*` for accelerator translation, active-surface synchronization, and hosted browser HWND redraw. The remaining Wave3 issue is alias/name cleanup (`DAT_0067ab28` vs `g_activeBrowserControlPane`), not evidence for a non-browser owner.
- The browser overlay-layer alias `g_pBrowserOverlayLayer` has useful source evidence but still needs final shared-layout type/name ownership in Wave3 metadata.
- 2026-05-25 follow-up: IDA resolves generated `g_pBrowserOverlayLayer` to [shared layout context 69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md). It has browser and non-browser UI xrefs, so it should remain a generated alias/shared-layout data issue rather than browser-owned storage.

Expected:

- `DAT_0067ab28` and `g_activeBrowserControlPane` should be reconciled as one storage location in generated output.
- `g_browserRuntime` should be treated as a generated alias of `g_pScreenPane`, not emitted as browser-owned storage. `g_browserStatusTextPane`, `dword_67A7CC`, and cursor/runtime aliases still need cleanup before header generation.
- `g_browserControlKeyCallback` should not be owned by `Browser.cpp` unless non-browser transport xrefs prove the callback is actually browser-private.
- `g_pBrowserOverlayLayer` now has a storage candidate but still needs final shared-layout type/name ownership.

Impact:

- New browser by-global docs distinguish browser-owned candidates from browser-coupled consumers.
- Added exact storage docs for [g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md), [g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md), and [g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md).
- Added exact storage documentation for [g_pScreenPane / g_browserRuntime alias storage](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md).
- 2026-05-26 follow-up marks [g_browserRuntime](by-global/g_browserRuntime.md) ignored as a generated global alias; canonical ownership remains [g_pScreenPane](by-global/g_pScreenPane.md).
- Added exact storage documentation for [shared layout context 69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md), and updated [g_pBrowserOverlayLayer](by-global/g_pBrowserOverlayLayer.md) to treat the generated name as a browser consumer alias.
- Do not migrate the ambiguous globals into [Browser](by-file/Browser.md) solely because generated browser class files reference them.

Follow-up:

- Continue reconciling `g_browserStatusTextPane` and any remaining `dword_67A7CC` aliases against the canonical [g_pScreenPane](by-global/g_pScreenPane.md) storage.
- Normalize alias names/types and move final ownership to browser, UI runtime, cursor manager, or network/transport based on xrefs.

### 2026-05-24 - `DATIndexVector` has a likely missing class-owned remove helper at `0x00457310`

Observed:

- `source-3/simroot_v2/class_DATIndexVector.cpp` emits `ResizeAndFill`, `InsertNode`, destructor, and `FindNodeByKey`, but not `0x00457310`.
- IDA MCP `lookup_funcs` reports `0x00457310` as `sub_457310` size `0xa3`.
- IDA MCP `callers` reports only one caller: `DATIndexVector::InsertNode` at `0x00457100`.
- 2026-05-25 follow-up: IDA disassembly places the call at `0x00457301` in the post-return EH/unwind cleanup block inside `sub_457100`; the main decompilation and `simroot_v2/class_DATIndexVector.cpp` do not show it as a normal straight-line call.
- IDA MCP decompilation shows `0x00457310` hashes the node key with the same four-byte FNV-1a bucket selection, repairs bucket first/last links, unlinks the node, decrements the count, frees it, and returns the next node through an out parameter.

Expected:

- The helper should be attached to `DATIndexVector` ownership as a private file-local cleanup helper; current documentation favors an internal exception-cleanup name such as `RemoveNodeForInsertUnwind` over a public `RemoveNode`/`EraseNode` API.
- `DATIndexVector` source placement should remain standalone; the caller fanout rules out folding it into `DATFileMgr.cpp`.

Impact:

- New docs record the helper as [DATIndexVector remove helper](by-memory/0x00457310-0x004573b2.DATIndexVectorRemoveNodeHelper.md), but Wave3 active class output does not yet expose it.
- Generated class/file migration could miss a real helper if only the active `class_DATIndexVector.cpp` method list is used.

Follow-up:

- Once Wave3 work resumes, inspect generated ownership for `0x00457310`, then attach or keep it documented as an internal helper in `DATIndexVector.cpp`.
- Recheck the final generated helper name only if new normal-call evidence appears; current IDA evidence supports exception cleanup inside `InsertNode`.

### 2026-05-25 - `MiniMapVersionManager` omits lookup helper at `0x004570b0`

Observed:

- `source-3/simroot_v2/class_MiniMapVersionManager.cpp` emits constructor, destructor, `LoadHashFile`, `UpdateHashList`, `GetVersionString`, and scalar deleting destructor, but not `0x004570b0`.
- `simroot_v2/class_MiniMapVersionManager.meta_wave3` active methods list omits `0x004570b0`.
- IDA MCP `lookup_funcs` reports `0x004570b0` as `sub_4570B0` size `0x30`.
- IDA MCP `callers` reports two callers: `MiniMapRenderer::PrepareMapFileAndCheckVersion` at `0x0045433c` and `MiniMapRenderer::HasCurrentVersion` at `0x00454dad`.
- IDA MCP decompilation/disassembly shows the helper calling `DATIndexVector::FindNodeByKey` on `this + 0x48`, comparing the result against the sentinel at `this + 0x4c`, and returning node payload `+0x0c` or null.

Expected:

- Attach `0x004570b0` to `MiniMapVersionManager` as a class method/helper, likely `GetExpectedVersionForMapId`.
- Keep `DATIndexVector::FindNodeByKey` in [DATIndexVector](by-file/DATIndexVector.md); `0x004570b0` is a minimap-specific wrapper over the manager's hash-index subobject.

Impact:

- Added [MiniMapVersion lookup by map id](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md) and [MiniMapVersionNode](by-type/by-struct/MiniMapVersionNode.md).
- Updated [MiniMapVersionManager](by-class/MiniMapVersionManager.md), [MiniMapVersionManager memory](by-memory/0x004563c0-0x00457546.MiniMapVersionManager.md), [MiniMap](by-file/MiniMap.md), and renderer/DATIndexVector cross-references.
- 2026-05-26 follow-up: added [MiniMapVersionManager file/module](by-file/MiniMapVersionManager.md), [g_pMiniMapVersionManager](by-global/g_pMiniMapVersionManager.md), and exact singleton storage [0x0067a7dc-0x0067a7e0](by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md). IDA reconfirmed the method caller split and singleton xrefs; the generated `g_pMiniMapVersionMgr`/`g_pMiniMapVersionManager` spelling remains alias cleanup work.

Follow-up:

- Recheck generated output after the next `simroot_v2` refresh or Wave3 regeneration for owner attachment of `0x004570b0`.

### 2026-05-24 - `SortedList` and `HierList` omit real container helpers from active generated output

Observed:

- `source-3/simroot_v2/class_SortedList.cpp` emits the constructor, destructor, `GetElementAt`, `Clear`, and `RemoveRange`, but not IDA-confirmed `0x004f3690-0x004f377b` or `0x004f3780-0x004f3803`.
- IDA MCP decompilation shows `0x004f3690` is sorted insertion using the comparator at `SortedList + 0x14`, and `0x004f3780` is a `bsearch`-based lookup that scans backward to the first equal element.
- `source-3/simroot_v2/class_HierList.cpp` omits IDA-confirmed `0x004ce760-0x004ce7d1`, `0x004ceb00-0x004ceb45`, and `0x004cec30-0x004ced0f`.
- IDA MCP shows `0x004ce760` is a non-deleting destructor body, `0x004ceb00` removes a found hierarchy node and deletes its child list, and `0x004cec30` recursively finds a node by payload data.
- The generated `HierList::~HierList()` body references a delete flag while the emitted signature has no such parameter.
- Generated `SortedList` metadata names the `+0x14` field `sortContext`, but IDA calls it as a comparator function pointer.
- 2026-05-25 follow-up: `simroot_v2` still omits these helpers. IDA caller checks show `SortedList` insert/search used by `ChangeMan` helpers, `HierList::RemoveNode` used by `Layer::RemoveChild`, and `HierList::FindNodeByData` used by insert/remove plus recursive descent.

Expected:

- Real container helpers should be attached to or emitted with their owning classes before source migration.
- `SortedList + 0x14` should be named as a compare callback or equivalent function pointer, not a passive context integer.
- `HierList` destructor emission should use the correct non-deleting body and scalar deleting wrapper signatures.

Impact:

- New [SortedList](by-class/SortedList.md), [HierList](by-class/HierList.md), [SortedList memory](by-memory/0x004f3600-0x004f3a43.SortedList.md), and [HierList memory](by-memory/0x004ce730-0x004cee52.HierList.md) docs include the missing functions and should be used before migration.

Follow-up:

- Attach or restore `0x004f3690`, `0x004f3780`, `0x004ce760`, `0x004ceb00`, and `0x004cec30` in Wave3 metadata.
- Correct `SortedList` field naming and `HierList` destructor signatures in generated output.

### 2026-05-24 - `ObjectList` and `MapPaneSpatialIndex` appear split across one concrete layout

Observed:

- `source-3/simroot_v2/class_ObjectList.cpp` emits only `ObjectList::ObjectList`, `ObjectList::~ObjectList`, and `ObjectList::ScalarDeletingDestructor`.
- IDA MCP confirms a larger adjacent helper island at `0x00532530-0x00532f67` whose accessors return fields initialized by `ObjectList::ObjectList`.
- Wave3 currently emits the early accessor subset as `class_MapPaneSpatialIndex.cpp`, but generated `class_MapPane.cpp` calls adjacent helpers as `ObjectList::DetachAll`, `ObjectList::GetInternalList`, `ObjectList::FindObjectAt`, `ObjectList::ShiftAll`, and `ObjectList::GetRow`.
- Constructor callers are only `MapPane::ChangeMap` and `MapPane::HandleEffectPacket`, both replacing the map object index.
- 2026-05-25 follow-up: `simroot_v2` still has lifecycle-only `class_ObjectList.cpp` plus early accessor-only `class_MapPaneSpatialIndex.cpp`. IDA MCP recheck confirms helper starts/sizes through `0x00532eb0`, and caller checks keep the island in MapPane render/scroll/hit-test/object cleanup with FpsPane diagnostics as read-only consumers.

Expected:

- The `0x00532530-0x00532f67` helper island should likely be attached to `ObjectList`, or `MapPaneSpatialIndex` should be represented as a documented view over the same concrete `ObjectList` layout.
- `MapPane + 0x424` field naming should normalize to one object-index pointer rather than alternating between `ObjectList`, `ObjectGrid`, and `MapPaneSpatialIndex`.

Impact:

- New [ObjectList](by-class/ObjectList.md), [ObjectList file](by-file/ObjectList.md), [ObjectList lifecycle](by-memory/0x00530ee0-0x00531472.ObjectListLifecycle.md), and [ObjectList helper island](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md) docs treat `ObjectList` as the final source owner.
- Existing [MapPaneSpatialIndex](by-class/MapPaneSpatialIndex.md) docs are preserved as a provisional alias so old links and current Wave3 output remain understandable.

Follow-up:

- Re-own or attach `0x00532530-0x00532f67` in Wave3 metadata after one more render-layer naming pass.
- Review `MapPane` generated field names around `+0x418` through `+0x424` and settle the final `ObjectList*` member names.

### 2026-05-24 - EmployeeDialogPane has omitted helpers and a raw non-IDA method start

Observed:

- Active `source-3/simroot_v2/class_EmployeeDialogPane.cpp` omits IDA-confirmed employee helpers `0x004a2450-0x004a2530` and `0x004a2f60-0x004a322b`.
- IDA MCP decompilation shows `0x004a2450` handles selected inventory items for the employee dialog, opening `EmployeeQuantityInputDialogPane` or dispatching command `5` directly.
- IDA MCP decompilation shows `0x004a2f60` is the employee response packet dispatcher for packet bytes `0x4f, 0x01`, covering load/upsert/remove/update/status cases.
- Wave3 emits `EmployeeDialogPane::UpdateEmployeeRecord` at `0x004a3be0`, but IDA MCP `lookup_funcs 0x004a3be0` reports `Not a function`. Raw IDA disassembly still shows a complete prologue/body that calls `DeserializeEmployeeRecord`, searches/copies a `0x41c` record, rebuilds the selection list, and repaints.
- `EmployeeItemPropertyDialogPane::ScalarDeletingDestructor` currently calls `TransferReplyAlert::~DialogPane`, which is base-owner pollution.
- `AddEmployeeItemDialog::AddEmployeeItemDialog` at `0x004a4ae0` remains a projected non-IDA function start; a 2026-05-24 IDA recheck shows construction is actually `EmployeeDialogPane::OnButtonAction` constructing `AddItemDialog` and patching vtables to `AddEmployeeItemDialog`.
- 2026-05-25 follow-up: IDA still reports `0x004a3be0` and `0x004a4ae0` as `Not a function`. Raw disassembly shows both are function-shaped, but `xrefs_to` reports no direct xrefs to either start; `OnButtonAction` still contains the live AddItemDialog constructor/vtable patch sequence. IDA decompilation of `0x004a4e30` also has base-type pollution, rendering the property-dialog destructor as `boost::exception::~exception`.
- 2026-05-26 follow-up: IDA MCP confirms `0x004a4ae0-0x004a4b1f` as raw constructor-shaped bytes that call `AddItemDialog`, store the employee owner pointer at `+0x270`, and install `AddEmployeeItemDialog` vtables, but `lookup_funcs` and `xrefs_to` still do not prove a callable function boundary.
- 2026-05-27 follow-up: IDA still reports no function/xrefs at `0x004a4ae0`, and a raw-pointer scan across loaded segments found no dword equal to `0x004a4ae0`. Keep the raw constructor as reconstructable evidence, but prefer the live inline construction sequence for source-map anchoring.
- 2026-05-26 follow-up: IDA MCP confirms live [AddEmployeeItemDialog inline construction](by-item/AddEmployeeItemDialogInlineConstruction_004A339F.md) inside `EmployeeDialogPane::OnButtonAction` at `0x004a3381-0x004a33be`, including the `0x274` allocation, base `AddItemDialog` call at `0x004a339f`, three vtable writes, and owner pointer store at `+0x270`.
- 2026-05-26 follow-up: IDA MCP confirms `0x004a4cb1-0x004a4cf3` as six compiler-generated destructor adjustor thunks for `AddEmployeeItemDialog`, `EmployeeDialogPane`, and `EmployeeItemPropertyDialogPane`; these should be ignored for handwritten source reconstruction.
- 2026-05-26 follow-up: IDA MCP confirms `EmployeeQuantityInputDialogPane` vtables at `0x00619038`, `0x00619098`, and `0x006190c8`, with constructor stores at `0x004a47cc`, `0x004a47d2`, and `0x004a47dc`, but `class_EmployeeQuantityInputDialogPane.meta_wave3` still reports `vtable_count: 0`. Its metadata also retains a constructor method name with a trailing control character.
- `class_AddEmployeeItemDialog.meta_wave3` reports `vtable_count: 0` even though IDA confirms vtable bases `0x006190d4`, `0x00619134`, and `0x00619164`. The active source names placeholder vtables, but the metadata inventory omits the real bases.
- Current `source-3/simroot_v2/class_AddEmployeeItemDialog.cpp` names address `0x00613a18` as `g_addEmployeeAlertCallbacks`, but IDA decodes `0x00613a18-0x00613a1e` as UTF-16 `OK` and reports 88 dialog/alert data xrefs. In `AddEmployeeItemDialog::OnButtonClick`, it is the primary button label for the multi-selection warning, not a callback table.
- IDA decodes `0x0061929c-0x006192c6` as the Korean multi-selection warning text `한번에 여러개를 추가할 수 없습니다.`, with the only xref from `0x004a4bc1` inside `AddEmployeeItemDialog::OnButtonClick`.
- 2026-05-26 follow-up: IDA MCP confirms `EmployeeItemPropertyDialogPane` is allocated as `0x284` bytes, with parent pointer `+0x26c`, icon rectangle `+0x270`, and item record pointer `+0x280`. Active generated source represents these as local overlay structs rather than a durable class layout.

Expected:

- `0x004a2450` and `0x004a2f60` should be attached, emitted, or explicitly excluded with employee-dialog ownership.
- `0x004a3be0` should either become an IDA-aligned function boundary or be marked raw/projected in Wave3 metadata before migration.
- The property-dialog destructor should use the real base dialog teardown label or a neutral unresolved helper.
- `AddEmployeeItemDialog` should be attached to `EmployeeDialogPane.cpp` or explicitly cross-owned there, while generic `AddItemDialog` remains in `ItemDialogs.cpp`.
- `0x004a4cb1-0x004a4cf3` should be suppressed or marked as compiler-generated vtable glue, not reconstructed as ordinary methods.
- `0x00613a18` should be typed/named as a shared OK button string, not as employee alert callbacks.

Impact:

- New [EmployeeDialogPane](by-file/EmployeeDialogPane.md), [Employee dialog memory](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md), [Employee dialog helper](by-item/EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0.md), [AddEmployeeItemDialog inline construction](by-item/AddEmployeeItemDialogInlineConstruction_004A339F.md), [EmployeeRecord](by-type/by-struct/EmployeeRecord.md), [EmployeeDialogPane vtables](by-type/by-vtable/EmployeeDialogPaneVtables.md), [AddEmployeeItemDialog raw constructor](by-memory/0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor.md), and [employee dialog adjustor thunks](by-memory/0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks.md) docs use IDA-confirmed boundaries and record these migration blockers.
- Added [AddEmployeeItemDialog layout](by-type/by-struct/AddEmployeeItemDialogLayout.md) to preserve the `AddItemDialog` base size, derived owner pointer at `+0x270`, and live inline-construction evidence.
- Added [EmployeeQuantityInputDialogPane layout](by-type/by-struct/EmployeeQuantityInputDialogPaneLayout.md) and expanded [EmployeeDialogPane vtables](by-type/by-vtable/EmployeeDialogPaneVtables.md) so the quantity dialog's IDA-confirmed vtables and shared dialog/alert destructor thunks are not lost.
- Added [EmployeeItemPropertyDialogPane layout](by-type/by-struct/EmployeeItemPropertyDialogPaneLayout.md) to pin the property dialog's `0x284` size, parent pointer, icon rect, and selected employee record pointer.
- Added [employee dialog resources](by-resource/employee-dialog-resources.md), [AddEmployee single-selection alert text](by-memory/0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText.md), and [Dialog OK button string](by-memory/0x00613a18-0x00613a1e.DialogOkButtonString.md) to correct the generated callback/string alias.

Follow-up:

- Restore or attach `0x004a2450` and `0x004a2f60` in Wave3 metadata.
- Decide whether raw `0x004a3be0` should become a function object, remain a raw-code helper, or be folded into the dispatcher model.
- Repair generated vtable inventory so `EmployeeQuantityInputDialogPane` records the three IDA-confirmed vtable bases instead of `vtable_count: 0`, and remove the trailing control character from the constructor method name.
- Repair generated vtable inventory so `AddEmployeeItemDialog` records the three IDA-confirmed vtable bases instead of `vtable_count: 0`.
- Reconcile `EmployeeItemPropertyDialogPane` destructor base label and `AddEmployeeItemDialog` projected constructor metadata before source migration.
- Keep `0x004a4cb1-0x004a4cf3` out of handwritten source output except as compiler-generated adjustor thunk artifacts.
- Rename/retype `g_addEmployeeAlertCallbacks` / `0x00613a18` as a shared `OK` button string in generated metadata/source.

### 2026-05-24 - `FpsPane` diagnostics are split with `ParcelPane` and have IDA boundary gaps

Observed:

- Current `source-3/simroot_v2/class_FpsPane.cpp` emits `FpsPane::FpsPane` at `0x004b6410`, `FpsPane::UpdateFpsLogSession` at `0x004b64a0`, `FpsPane::OnPaint` at `0x004b67b0`, `FpsPane::UpdateStatistics` at `0x004b68b0`, and `FpsPane::ScalarDeletingDestructor` at `0x004b6c50`.
- IDA MCP confirms functions at `0x004b6470`, `0x004b67b0`, `0x004b68b0`, `0x004b6c2b`, `0x004b6c36`, and `0x004b6c50`, but currently reports no function at `0x004b6410`, `0x004b64a0`, `0x004b69b0`, or `0x004b6ae0`.
- `source-3/simroot_v2/class_ParcelPane.cpp` no longer emits the `0x004b64a0` method body, but still emits `g_fpsDebugActive` and `g_fpsLogEnabled` global-data rows; `class_ParcelPane.meta_wave3` still has stale owner-method references back to `0x004b64a0`.
- IDA raw disassembly shows callerless FpsPane-shaped helper starts at `0x004b69b0` and `0x004b6ae0`; they reset/start and finalize/write the same FPS logging session state used by `0x004b64a0`.
- `FpsPane::UpdateStatistics` reads `ObjectList` counts through `0x00532670`, `0x005326d0`, and `0x00532610`.
- 2026-05-26 follow-up: IDA MCP reconfirmed `0x004b6c2b` and `0x004b6c36` as 0xb-byte destructor adjustor thunks with vtable-only data refs at `0x0061a66c` and `0x0061a69c`. These are compiler-generated and should be ignored for handwritten source output.
- 2026-05-26 follow-up: IDA layout review resolved the apparent field mismatch in `0x004b68b0`: `UpdateStatistics` is invoked through the timer/update subobject at owner offset `+0xa4`, so Hex-Rays offsets normalize by adding `0xa4`. This aligns `OnPaint`, `UpdateStatistics`, and raw logging helpers on owner fields `+0xf8`, `+0x100`, and `+0x104-+0x168`.

Expected:

- `0x004b64a0-0x004b67a7` should remain owned by `FpsPane` unless future evidence proves a nearby shared diagnostics helper.
- `0x004b6410`, `0x004b64a0`, `0x004b69b0`, and `0x004b6ae0` boundaries need cross-disassembler review before source migration.
- `g_fpsDebugActive` and `g_fpsLogEnabled` should be treated as FpsPane diagnostics globals unless broader xrefs prove otherwise.
- `0x004b6c2b-0x004b6c41` should be suppressed or marked as compiler-generated vtable glue, not reconstructed as ordinary source methods.

Impact:

- New [FpsPane](by-file/FpsPane.md), [FpsPane class](by-class/FpsPane.md), [FpsPane diagnostics memory](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md), and related global/vtable docs track the diagnostics ownership.
- Added exact docs for the raw constructor/destructor/helper bodies under [FpsPane diagnostics memory](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md).
- Added exact docs for [FpsPane adjustor thunks](by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md) and listed the range in [by-memory ignored ranges](by-memory/-ignored.md).
- Added [FpsPane layout](by-type/by-struct/FpsPaneLayout.md) so the timer-subobject-relative offsets and logging-session fields are preserved outside incomplete generated struct metadata.
- Do not migrate stale ParcelPane metadata/global-data references as parcel UI evidence.

Follow-up:

- Repair generated FpsPane layout/vtable metadata: current `class_FpsPane.meta_wave3` reports `vtable_count: 0` and only models fields through `+0x100`, omitting the IDA-confirmed logging fields `+0x104-+0x168`.
- Decide whether raw helper starts `0x004b69b0` and `0x004b6ae0` should be imported as private methods, folded into a logging helper model, or excluded as callerless duplicate/dead code.
- Keep `0x004b6c2b-0x004b6c41` out of handwritten source output except as compiler-generated adjustor thunk artifacts.

### 2026-05-24 - `ParcelPane` family has omitted helpers and mixed generated ownership

Observed:

- Active `source-3/simroot_v2/class_ParcelPane.cpp` emits the main pane methods, but IDA MCP also confirms an omitted non-deleting `ParcelPane` destructor body at `0x00546440-0x005464ac`.
- IDA MCP confirms `ParcelIconPane` constructor candidate `0x00545e40-0x0054606a`, which allocates and initializes a child `ParcelPane`; active `class_ParcelIconPane.cpp` emits only destructor-side code.
- IDA MCP confirms an omitted `ParcelIconPane` packet/update callback at `0x005461c0-0x0054628d`.
- Searches show `0x00546f40` appears in many generated metadata containers as a referenced owner/context, even though IDA decompilation and canonical generated source identify it as `ParcelIconPane::ScalarDeletingDestructor`.
- 2026-05-25 recheck: active `class_ParcelPane.cpp` no longer emits the unrelated FPS diagnostics body at `0x004b64a0`, but still emits the FPS global-data rows and stale ParcelPane metadata still references the old FPS owner context.
- 2026-05-25 IDA MCP xrefs place `0x005461c0` at ParcelIconPane secondary-vtable slot `0x00621c10`, so the helper should be owned by `ParcelIconPane` rather than by `ParcelPane` directly.
- 2026-05-26 IDA/raw-disassembly follow-up: active `class_FlyingParcelPane.cpp` omits `0x00546b80-0x00546bb5` and `0x00546bc0-0x00546d64`. Current IDA `lookup_funcs` also misses these starts, but raw IDA disassembly and prewave/Ghidra function records show a real `FlyingParcelPane` cleanup body and animation-start/configure body.
- 2026-05-26 vtable follow-up: disabled `class_FlyingParcelPane.cpp` emits a false `0x00420054` method row by reading past the short `FlyingParcelPane` tertiary vtable into adjacent `ALERTBTN` string data. The same disabled output marks `0x00546e8b` as missing code even though IDA disassembly confirms a normal destructor adjustor thunk.
- 2026-05-26 layout follow-up: active `class_ParcelPane.cpp` also emits `0x005051c0` and `0x00544c50` as `ParcelPane` methods. IDA shows `0x00544c50` is the shared `Pane` layer-membership helper, while `0x005051c0` paints visible tiles from `this + 0x428`. The `ParcelIconPane` constructor allocates the child `ParcelPane` as only `0x124` bytes, so `0x005051c0` cannot be a `ParcelPane` method.

Expected:

- `0x005461c0` should be emitted or attached under `ParcelIconPane` as the parcel packet/update callback; `0x00546440` should be emitted or attached under `ParcelPane` as the non-deleting destructor.
- `ParcelIconPane` constructor coverage should be restored or documented as intentionally folded into a different generated owner.
- `0x00546f40` should use canonical `ParcelIconPane` ownership where it appears as copied reference context in unrelated metadata.
- `0x00546b80` and `0x00546bc0` should be emitted or attached under `FlyingParcelPane`, or explicitly marked as raw/IDA-boundary-gap methods until the owning function records are repaired.
- `0x00546e8b-0x00546ecd` should be classified as compiler-generated adjustor thunk glue. The false `0x00420054` row should be quarantined as post-vtable string/data, not as a `FlyingParcelPane` method.
- `0x005051c0` should be removed from `ParcelPane` ownership and moved to the shared screen/render review bucket; `0x00544c50` should be treated as `Pane` core infrastructure, not a parcel-specific helper.

Impact:

- New [ParcelPane](by-file/ParcelPane.md), [ParcelPane class](by-class/ParcelPane.md), [FlyingParcelPane](by-class/FlyingParcelPane.md), [ParcelIconPane](by-class/ParcelIconPane.md), [g_pParcelPane](by-global/g_pParcelPane.md), and [parcel memory](by-memory/0x00545e40-0x005470ac.ParcelNotificationPanes.md) docs use IDA boundaries and keep the parcel family separate from FpsPane and PatchPane.
- 2026-05-25 follow-up: added exact docs for the `ParcelIconPane` constructor, destructor, packet/update callback, and scalar deleting destructor, plus the omitted `ParcelPane` destructor/scalar destructor and [g_pParcelIconPane](by-global/g_pParcelIconPane.md).
- 2026-05-26 follow-up: added [Parcel notification vtable family](by-type/by-vtable/ParcelNotificationVtableFamily.md), [FlyingParcelPane raw lifecycle/start body](by-memory/0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart.md), [FlyingParcelPane scalar deleting destructor](by-memory/0x00546ed0-0x00546f36.FlyingParcelPaneScalarDeletingDestructor.md), and [parcel notification adjustor thunks](by-memory/0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks.md).
- 2026-05-26 layout follow-up: added [Parcel notification pane layouts](by-type/by-struct/ParcelNotificationPaneLayouts.md) and [draw visible tiles helper](by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md), and updated [Pane core](by-memory/0x00544460-0x00545085.PaneCore.md) to place `0x00544c50` with base `Pane`.

Follow-up:

- Attach or restore `0x00545e40`, `0x005461c0`, and `0x00546440` in Wave3 output with the corrected `ParcelIconPane`/`ParcelPane` ownership split.
- Attach or restore `0x00546b80` and `0x00546bc0` under `FlyingParcelPane`; current active simroot omits both, and current IDA does not create function records for them.
- Recheck `class_FlyingParcelPane.meta_wave3` names before using them in generated C++.
- Normalize copied `0x00546f40` owner contexts to `ParcelIconPane` or make them non-owning references.
- Quarantine the disabled `0x00420054` row and any similar post-vtable string/data reads.
- Quarantine or reassign active `class_ParcelPane.cpp` rows for `0x005051c0` and `0x00544c50`; both are real code, but neither is owned by `ParcelPane`.

### 2026-05-24 - `PatchPane` and `PatchPane2` have omitted helpers and a bad `0x00549020` start

Observed:

- IDA MCP confirms a patch/update function island at `0x005470b0-0x0054940f`, beginning immediately after the ParcelPane family and ending before unrelated decoder-like code at `0x00549410`.
- Active `class_PatchPane.cpp` omits IDA-confirmed `0x005474f0-0x0054784f`, the central patch packet/entry response handler.
- Active `class_PatchPane__PatchFileSlice.cpp` emits `0x00548430` but omits IDA-confirmed constructor/destructor helpers at `0x005483a0` and `0x00548410`.
- Active `class_PatchPane2.cpp` omits IDA-confirmed `0x00548a80-0x00548f19`, which Wave3 metadata itself describes as the main patching loop.
- Wave3 lists `PatchPane2::AdvancePatchStep` at `0x00549020`, but IDA MCP `lookup_funcs` reports `0x00549020` is not a function. IDA confirms real starts at `0x00549080` and `0x00549220`.
- Current metadata reports `vtable_count: 0` for the PatchPane family, but IDA confirms concrete vtables at `0x00621dbc`, `0x00621dc4`, `0x00621dcc`, `0x00621e2c`, `0x00621e5c`, `0x00621f40`, `0x00621fa0`, and `0x00621fd0`.
- Current `class_PatchPane2.cpp` emits the `0x00549356` adjustor thunk as a normal-looking `VtableAdjustorThunk_Dtor` method and disables `0x0054934b`; both are compiler-generated destructor adjustor thunks, not handwritten patch logic.

Expected:

- `0x005474f0`, `0x005483a0`, `0x00548410`, `0x00548a80`, `0x00548f30`, `0x00549080`, and `0x00549340` should be emitted, attached, or explicitly marked as omitted helpers.
- The `0x00549020` row should be removed, realigned, or marked as a bad/projected start before source migration.
- Vtable inventory should record the IDA-confirmed PatchPane/PatchPane2/PatchFileData/PatchFileSlice vtables, and compiler adjustor thunks should be documented as ignored thunks rather than promoted as source methods.

Impact:

- New [PatchPane](by-file/PatchPane.md), [PatchPane class](by-class/PatchPane.md), [PatchPane2](by-class/PatchPane2.md), [PatchFileData](by-class/PatchPane__PatchFileData.md), [PatchFileSlice](by-class/PatchPane__PatchFileSlice.md), [g_pPatchPane2](by-global/g_pPatchPane2.md), and [patch memory](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md) docs use IDA-confirmed boundaries and flag the incomplete generated output.
- 2026-05-25 follow-up: added exact memory pages for [PatchPane packet response](by-memory/0x005474f0-0x00547850.PatchPanePacketResponseHandler.md), [PatchFileSlice constructor](by-memory/0x005483a0-0x005483bb.PatchFileSliceConstructor.md), [PatchFileSlice destructor](by-memory/0x00548410-0x00548425.PatchFileSliceDestructor.md), [PatchPane2 main loop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md), [PatchPane2 work-event predicate](by-memory/0x00548f30-0x00548f41.PatchPane2WorkEventPredicate.md), [PatchPane2 close/rename helper](by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md), [PatchPane2 SendDownloadRequest](by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md), and [ClearPatchPane2Singleton](by-memory/0x00549340-0x0054934b.ClearPatchPane2Singleton.md). IDA MCP recheck confirmed `0x00549020` is still not a function and has no xrefs.
- 2026-05-26 follow-up: added [PatchPane vtable family](by-type/by-vtable/PatchPaneVtableFamily.md), [PatchPane2 layout](by-type/by-struct/PatchPane2Layout.md), [PatchPane adjustor thunks](by-memory/0x005484db-0x005484f0.PatchPaneAdjustorThunks.md), and [PatchPane2 adjustor thunks](by-memory/0x0054934b-0x00549360.PatchPane2AdjustorThunks.md). IDA MCP confirmed `0x00549020` still has no xrefs, while vtable slots reference the omitted callback bodies and compiler thunks.

Follow-up:

- Repair or attach the omitted helpers in Wave3 metadata, especially `0x00548a80`.
- Replace or remove the `0x00549020` method row after reviewing Ghidra/Wave3 boundary provenance.
- Restore vtable inventory for the PatchPane family and keep `0x005484db`, `0x005484e6`, `0x0054934b`, and `0x00549356` out of handwritten source.
- Decide whether final simpath should be one `patch/PatchPane.cpp` or separate `patch/PatchPane.cpp` plus `patch/PatchPane2.cpp`.

### 2026-05-24 - `CollectionPane` and `CollectionDialogPane` have omitted helpers and IDA alignment caveats

Observed:

- Active `class_CollectionPane.cpp` omits IDA-confirmed `0x0056f800-0x0056f804` and `0x0056fc80-0x0056fd60`. The latter is the key open/request helper that either sends a collection-detail request packet or constructs `CollectionDialogPane`.
- Active `class_CollectionPane2.cpp` emits `CollectionPane2::CollectionPane2` at `0x0056fd70`, but IDA MCP `lookup_funcs` reports `0x0056fd70` is not a function. Raw IDA disassembly still shows constructor instructions at `0x0056fd70-0x0056fd9f`.
- Active `class_CollectionPane2.cpp` omits `0x0056fda0-0x0056fdbf`, `0x0056fdc0-0x0056fdcb`, and `0x0056fe70-0x0056fe74`.
- Active `class_CollectionEntryControlPane.cpp` omits the non-deleting destructor body at `0x0048d480-0x0048d49f`.
- Active `class_CollectionDialogPane.cpp` omits the singleton-clear helper at `0x0048e140-0x0048e14a`.
- Related `class_ScrollCollectionPane.cpp` has additional boundary/output gaps: IDA does not model Wave3 starts `0x00562e80` or `0x00563200` as functions even though raw bytes are valid code, Wave3 omits raw/IDA-confirmed helpers at `0x00562ef0`, `0x00562fb0`, and `0x00563070`, and the IDA-confirmed hit-test helper at `0x005628d0` is called by generated source but not emitted as a scoped method.
- Wave3 aliases `0x0067a748` as `g_pCollectionData`, `g_pPlayerData`, and `g_collectionProgressTable` in different collection files.
- 2026-05-27 follow-up: `ChangeSpellSlotInputPane::SubmitSpellSlotChange` uses the same storage `dword_67A748` as a spell-slot/player-state view at `+0x13a6ec + slot * 0x148` and clears byte `+0x13ead4`. This confirms the alias issue is broader than collection output; generated `g_pClientState`/collection aliases should converge on a canonical player/client-state global with typed views.

Expected:

- The omitted helpers should be restored, emitted, or explicitly marked omitted with reasons.
- The `0x0056fd70` constructor should be made IDA-aligned or documented as a manual raw-code function boundary before migration.
- Collection use of `0x0067a748` should converge on a canonical player-data global with collection-specific typed views.
- Spell-slot/player-state use of `0x0067a748` should be included in that canonicalization, not documented as collection ownership.

Impact:

- New [CollectionPane](by-file/CollectionPane.md), [CollectionDialogPane](by-file/CollectionDialogPane.md), [ScrollCollectionPane](by-file/ScrollCollectionPane.md), [collection pane memory](by-memory/0x0056e940-0x0056fe75.CollectionPane.md), [collection dialog memory](by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md), [g_pCollectionData](by-global/g_pCollectionData.md), [g_pCollectionData memory](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md), and [CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md) docs use the IDA-checked boundaries.
- 2026-05-25 follow-up: added exact pages for [CollectionPane false stub](by-memory/0x0056f800-0x0056f805.CollectionPaneFalseStub.md), [CollectionPane open/request detail](by-memory/0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail.md), [CollectionPane2 raw constructor](by-memory/0x0056fd70-0x0056fda0.CollectionPane2RawConstructor.md), [CollectionPane2 destructor](by-memory/0x0056fda0-0x0056fdbf.CollectionPane2Destructor.md), [CollectionPane2 forwarding thunk](by-memory/0x0056fdc0-0x0056fdcc.CollectionPane2ForwardingThunk.md), [CollectionPane2 false stub](by-memory/0x0056fe70-0x0056fe75.CollectionPane2FalseStub.md), [CollectionEntryControlPane destructor](by-memory/0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor.md), [ClearCollectionDialogPaneSingleton](by-memory/0x0048e140-0x0048e14b.ClearCollectionDialogPaneSingleton.md), and the [ScrollCollectionPane tail helpers](by-memory/0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers.md). IDA MCP recheck still reports `0x0056fd70`, `0x00562e80`, `0x00562ef0`, and `0x00563200` as non-function raw starts.
- 2026-05-26 follow-up: added [ScrollCollectionPane hit-test helper](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md), [ScrollCollectionPaneLayout](by-type/by-struct/ScrollCollectionPaneLayout.md), and [ScrollCollectionPaneVtables](by-type/by-vtable/ScrollCollectionPaneVtables.md) after IDA confirmed constructor vtables `0x00623fa4`, `0x00623ff0`, and `0x00624020`.
- 2026-05-27 follow-up: updated [ChangeSpellSlotInputPane](by-class/ChangeSpellSlotInputPane.md), [ChangeSpellSlotInputPane memory](by-memory/0x005b3220-0x005b340e.ChangeSpellSlotInputPane.md), [g_pCollectionData](by-global/g_pCollectionData.md), and [g_pCollectionData memory](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md) to record the non-collection spell-slot typed view of `0x0067a748`.

Follow-up:

- Attach or restore `0x0056fc80`, `0x0056f800`, `0x0056fda0`, `0x0056fdc0`, `0x0056fe70`, `0x0048d480`, and `0x0048e140`.
- Restore or explicitly mark the `ScrollCollectionPane` omitted helper methods in generated data: `0x005628d0`, `0x00562ef0`, `0x00562fb0`, and `0x00563070`; keep `0x00562e80` and `0x00563200` as manual raw boundaries until function recovery changes.
- Decide whether `CollectionDialogPane.cpp` should live under `ui/dialogs/` or beside `CollectionPane.cpp` under `ui/panels/`.

### 2026-05-24 - `BackPane` generated output includes scattered helpers and raw projected starts

Observed:

- `source-3/simroot_v2/class_BackPane.cpp` correctly emits the core `BackPane` constructor/destructor/paint island at `0x00467830-0x00467b2d`, and IDA confirms those function starts.
- The same generated file also emits scattered methods at `0x004806d0`, `0x004b8e00`, `0x004eaf20`, `0x004ede80`, `0x004ef510`, `0x00506ce0`, `0x005388a0`, and `0x005c2760-0x005c2930`.
- IDA MCP confirms `0x004b8e00`, `0x004eaf20`, `0x004ede80`, `0x004ef510`, `0x00506ce0`, `0x005388a0`, and `0x005c2930` as real functions, but reports `0x005c2760` and `0x005c2840` as `Not a function`.
- Manual IDA raw disassembly now confirms function-shaped code bodies at `0x005c2760-0x005c2835` and `0x005c2840-0x005c292e`, but `xrefs_to` reports no refs to either start. Their field offsets and the raw call from `0x005c291d` to `0x005c2930` match `SwallowLayerPane`, not `BackPane`.
- `BackStoryDialogPane` is a concrete generated class at `0x00500090-0x0050040d`, but IDA `xrefs_to 0x00500090` found no direct constructor callers during this pass. `CloseMainMenuDialogSingletons_004F69A0` still closes `g_pBackStoryDialogPane`.
- IDA decompilation for `BackStoryDialogPane` destructor support at `0x00502600` labels the base type as `boost::exception`; generated source and vtable context indicate this is decompiler type pollution over dialog teardown.

Expected:

- Keep `BackPane` core ownership documented at `0x00467510-0x00467b2d`, with `BackGroundPane` in the same provisional source module.
- Exclude `0x005c2760-0x005c292e` and `0x005c2930` from `BackPane`; document them under `SwallowLayerPane` raw/weather helper ownership unless later xrefs prove they are dead code.
- Review remaining scattered `BackPane` helper rows independently before migration.
- Resolve whether `BackStoryDialogPane` is an indirect/live menu path or retained older dialog code.
- Correct destructor base typing for `BackStoryDialogPane` before using generated source as compile-ready code.

Impact:

- New [BackPane](by-file/BackPane.md), [BackPane class](by-class/BackPane.md), [BackGroundPane](by-class/BackGroundPane.md), [BackPane memory](by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md), [BackStoryDialogPane](by-file/BackStoryDialogPane.md), [BackStoryDialogPane memory](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md), [background resources](by-resource/backpane-background-resources.md), [main-menu story resources](by-resource/main-menu-story-resources.md), and [Swallow raw flight helper](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md) docs record the split and caveats.
- 2026-05-25 follow-up: current `simroot_v2` still emits the scattered `class_BackPane.cpp` rows. Added exact memory pages for `0x004806d0`, `0x004b8e00`, `0x004eaf20`, `0x004ede80`, `0x004ef510`, `0x00506ce0`, and `0x005388a0`; IDA recheck still reports `0x005c2760` and `0x005c2840` as non-functions and confirms `g_pBackStoryDialogPane` storage at `0x0069b498`.
- 2026-05-26 follow-up: live IDA caller checks now resolve `0x004806d0` to the chat-height layout path (`ChattingModifyHeightPane::OnMouseEvent`), `0x00506ce0` to MapPane/target-selection mouse hit testing, and `0x005388a0` to MapPane packet/object timer setup. Updated the BackPane, Chatting, MapPane, and TargetSelectionInputPanes docs to keep those rows out of `map/BackPane.cpp`.

Follow-up:

- Recheck generated output after Wave3 fixes to ensure `0x004806d0`, `0x00506ce0`, `0x005388a0`, `0x005c2760`, `0x005c2840`, and `0x005c2930` are no longer emitted under `BackPane`.
- Decode the `InitializeMainUiGraph` frame-resource pointers passed into `BackPane::BackPane`.
- Trace `g_pBackStoryDialogPane` writes/calls beyond direct constructor xrefs to determine if the class is live or obsolete.

### 2026-05-24 - `SnowingLayerPane` legacy aggregate crosses `SwallowLayerPane`

Observed:

- The older `0x005c1bd0-0x005c2a5a` Snowing aggregate range crosses `SwallowLayerPane`, which starts at `0x005c2230`.
- IDA MCP confirms Snowing owns `0x005c1bd0`, `0x005c1c80`, `0x005c1f50`, `0x005c20e0`, adjustor thunks `0x005c29ec` and `0x005c29f7`, and scalar deleting destructor `0x005c2a20`.
- IDA MCP confirms Swallow owns `0x005c2230`, `0x005c2340`, `0x005c2360`, `0x005c2430`, `0x005c2500`, `0x005c26b0`, `0x005c2930`, adjustor thunks `0x005c2a02` and `0x005c2a0d`, and scalar deleting destructor `0x005c2a60`.
- `0x005c2760` and `0x005c2840` remain raw function-shaped Swallow helper bodies with no IDA function objects/xrefs and polluted generated `BackPane` ownership.

Expected:

- Use per-method ownership inside `0x005c1bd0-0x005c2ab5`; do not migrate the older Snowing aggregate as a single class-owned block.
- Keep all of this under the map weather source family unless later source evidence proves a render-effects module.
- Treat the raw `0x005c2760` and `0x005c2840` helpers as Swallow-owned raw/orphan helpers, not BackPane methods.

Impact:

- New [Snowing/Swallow memory island](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md) records the per-method ownership and thunk targets.
- [WeatherLayerPane](by-file/WeatherLayerPane.md), [SnowingLayerPane](by-file/SnowingLayerPane.md), [SwallowLayerPane](by-file/SwallowLayerPane.md), [MapPane](by-file/MapPane.md), and [proposed source tree](by-project-structure/proposed-source-tree.md) now point at the shared island.

Follow-up:

- Recheck generated output after Wave3 fixes for the legacy Snowing aggregate range, the Swallow destructor tail, and the raw helper ownership at `0x005c2760`/`0x005c2840`.

### 2026-05-24 - Startup logo/video panes have omitted helpers and mixed base ownership

Observed:

- `source-3/simroot_v2/class_LogoPane.cpp` omits IDA-confirmed `0x004f4eb0-0x004f4f29`, a non-deleting `LogoPane` cleanup body.
- `source-3/simroot_v2/class_LogoPane.cpp` includes unrelated `HeadSelectDialog` type pollution in a file-level `RefreshFn` alias.
- `source-3/simroot_v2/class_LogoPlayerPane.cpp` omits IDA-confirmed `0x004f5640-0x004f5669`, which disassembles as `_AUTOBUF<unsigned char>` construction rather than a pane method.
- `LogoPlayerPane::OpenBinkVideo` at `0x005c0110` is emitted with a `filePath`-style signature, but callers pass pointers into an in-memory AUTOBUF segment after reading the whole startup movie payload. IDA plus Bink flag decoding shows `67633152 == 0x04080000`, consistent with `BINKFROMMEMORY | BINKNOSKIP`.
- `0x005c0090` is emitted as `LogoPlayerPane::~LogoPlayerPane`, but IDA behavior matches the non-deleting `VideoPlayerPane` base destructor body used during derived cleanup.
- Disabled thunk output for `LogoPlayerPane` at `0x004f566a` contains a nonsensical adjusted-this expression; `0x004f5675` is missing code.
- `VideoPlayerPane` active metadata omits the non-deleting destructor body at `0x005c0090`, while the class island in IDA spans `0x005c0040-0x005c045b`.
- 2026-05-24 follow-up: IDA confirms `LogoPane` thunks `0x004f52de`/`0x004f52e9`, `LogoPlayerPane` thunks `0x004f566a`/`0x004f5675`, and `VideoPlayerPane` thunks `0x005c037b`/`0x005c0386` as real `0xb` adjustor thunks. Each pair subtracts `0xa0`/`0xa4` and forwards to its scalar deleting destructor.
- Current active `class_LogoPane.cpp` still contains a stray `HeadSelectDialog` file-level `RefreshFn` alias and duplicate normalized include comments.
- 2026-05-26 follow-up: IDA `callers` reports the direct code caller for `_AUTOBUF<unsigned char>` constructor `0x004f5640` as `MapPane::LoadMapFromFile` at `0x00504d49`, not the visible `LogoPlayerPane` constructor. `LogoPlayerPane` still uses the same embedded layout but initializes it inline.

Expected:

- Attach or explicitly model `0x004f4eb0` as `LogoPane` destructor support.
- Model `0x004f5640` as `_AUTOBUF<unsigned char>` template support, not `LogoPlayerPane` or `MapPane` source ownership.
- Reconcile `0x005c0090` with `VideoPlayerPane` base teardown ownership.
- Rename or type `OpenBinkVideo` parameters to reflect memory-backed Bink segment input; preserve the currently unused segment-size argument until its original purpose is understood.
- Clean the stray `HeadSelectDialog` alias and invalid thunk body before source migration.
- Materialize or classify the real adjustor thunks instead of leaving `0x004f52e9`, `0x004f5675`, and `0x005c037b` as missing code or emitting bad adjusted-this expressions.

Impact:

- New [StartupLogoPanes](by-file/StartupLogoPanes.md), [VideoPlayerPane](by-file/VideoPlayerPane.md), [LogoPane](by-class/LogoPane.md), [LogoPlayerPane](by-class/LogoPlayerPane.md), [VideoPlayerPane class](by-class/VideoPlayerPane.md), [LogoPane memory](by-memory/0x004f4c10-0x004f53a8.LogoPane.md), [LogoPlayerPane memory](by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md), [AUTOBUF constructor memory](by-memory/0x004f5640-0x004f5669.AUTOBUFUnsignedCharConstructor.md), [VideoPlayerPane memory](by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md), [startup logo media](by-resource/startup-logo-media.md), [MapPane](by-file/MapPane.md), and [AUTOBUF<unsigned char>](by-type/by-template/AUTOBUF_unsigned_char.md) docs capture the corrected ownership model.

Follow-up:

- Add `0x004f4eb0`, `0x004f5640`, and `0x005c0090` to the appropriate Wave3 owners or mark them as explicit support helpers.
- Decide whether final source layout uses one `app/StartupLogoPanes.cpp` or split `app/LogoPane.cpp` plus `app/LogoPlayerPane.cpp`.
- Decide final owner for `0x005c0110`: protected `VideoPlayerPane` memory-open helper versus startup-local `LogoPlayerPane` helper.

### 2026-05-24 - `SimpleUString`, `SimpleUStringVector`, and `StringIter` have split layout evidence and generated boundary issues

Observed:

- Active `source-3/simroot_v2/class_SimpleUString.cpp` only emits the early SSO-7 UTF-16 helper subset around `0x00421310` and `0x00421590`.
- Disabled/generated `SimpleUString` output contains real later helpers at `0x00583210`, `0x00583280`, and `0x005845b0`; IDA MCP confirms these as functions inside a larger string-helper island.
- The early `0x00421310-0x004216cb` helpers use an inline UTF-16 small-string layout, while the later `0x00583210+` family looks pointer-backed. These should not be blindly collapsed into one struct layout without reconciling storage fields.
- 2026-05-30 documentation split: IDA MCP confirms the historical `0x00421310-0x004216cb.SimpleUStringSso7` page was overbroad as a `SimpleUString` range. Only `0x00421310-0x00421362` and `0x00421590-0x004216cb` are early SSO-7 string helpers; the middle contains pane/fitting-room cleanup, checkbox control-type, generated thunk/padding, and MSVC vector/runtime helpers.
- `class_SimpleUString.meta_wave3` notes nearby raw SSO-15 byte-string helpers around `0x0041b300` and `0x0041d3b0`; those are intentionally not merged into `SimpleUString` docs yet.
- `SimpleUStringVector::GrowAndInsert` is emitted from `0x0049cc40`, but IDA confirms size `0x209`, with last executable byte `0x0049ce48` and end-exclusive address `0x0049ce49`; generated metadata has previously shown a shorter end around `0x0049ce23`.
- Active `source-3/simroot_v2/class_StringIter.cpp` emits `StringIter::StringIter` at `0x00584dc0`, but IDA MCP `lookup_funcs` reports `0x00584dc0` is not a function.

Expected:

- Attach or restore the omitted `SimpleUString` helpers at `0x00583210`, `0x00583280`, and `0x005845b0`, or explicitly mark them as related helper functions outside the active class source.
- Keep the early SSO-7 endpoint helpers, later pointer-backed layout, and nearby byte-string SSO-15 helpers separate until field evidence proves a merge. Do not use the full `0x00421310-0x004216cb` aggregate as `SimpleUString` ownership proof.
- Align `SimpleUStringVector::GrowAndInsert` end metadata with the IDA-confirmed function range.
- Review or remove the generated `0x00584dc0` `StringIter` row.

Impact:

- New [StringUtil](by-file/StringUtil.md), [SimpleUString](by-class/SimpleUString.md), [SimpleUStringVector](by-class/SimpleUStringVector.md), [StringIter](by-class/StringIter.md), [client string handling](by-meta/client_string_handling.md), [SimpleUString SSO-7 aggregate memory](by-memory/0x00421310-0x004216cb.SimpleUStringSso7.md), [SimpleUString clear endpoint](by-memory/0x00421310-0x00421362.SimpleUStringClear.md), [SimpleUString counted wide endpoint](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md), [SimpleUString pointer-backed memory](by-memory/0x00583210-0x005845eb.SimpleUStringPointerBacked.md), [SimpleUStringVector memory](by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md), and [StringIter memory](by-memory/0x00584d80-0x00584e9e.StringIter.md) docs use IDA-confirmed boundaries and call out generated-data caveats.

Follow-up:

- Reconcile `SimpleUString` storage fields before writing compile-ready class declarations.
- Decide whether final source keeps all wide-string helpers in `util/StringUtil.cpp` or splits container/iterator helpers into companion files.
- Recheck `0x00584dc0` with raw disassembly before importing it as a real method boundary.

### 2026-05-24 - `LObject` generated owner merges base-object, string-base, and FolderTreePane helper code

Observed:

- Active `source-3/simroot_v2/class_LObject.cpp` contains a tiny true base-object/runtime shell around `0x004f4a80-0x004f4c0d`.
- The same generated owner contains a large ref-counted ANSI/UTF-16 string-buffer family from `0x00582500` through `0x00584d7d`, using shared empty sentinels, fixed-capacity pool globals, and a 12-byte header before the data pointer.
- `class_LObject.meta_wave3` explicitly notes that a true virtual base class and a reference-counted string class are merged under `LObject`; older/generated field names describe the string data pointer as `vftptr_0x0` or `m_vtable`.
- Active `class_LObject.cpp` also emits FolderTreePane traversal/search helpers at `0x004b3400`, `0x004b3650`, `0x004b3850`, and `0x004b3af0`; IDA caller checks tie those to `FolderTreePane` core functions.
- The active generated file has mixed method owners such as `SimpleString::GrowAnsiBuffer`, `SimpleUString::CopyInitWide`, and `SimpleUString::FindWide` inside `class_LObject.cpp`.

Expected:

- Keep the base-object/runtime shell, string-buffer implementation, and FolderTreePane callbacks as separate migration concerns.
- Do not treat the generated `m_vtable`/`vftptr_0x0` names in string methods as proof of a real vtable field.
- Move or mark the `0x004b3400-0x004b3d41` helpers as FolderTreePane-local callbacks in final ownership data.
- Reconcile whether the string-buffer family belongs to `LObject.cpp`, `StringUtil.cpp`, or a future `StringBase.cpp`.

Impact:

- New [LObject](by-file/LObject.md), [LObject class](by-class/LObject.md), [runtime shell memory](by-memory/0x004f4a80-0x004f4c0d.LObjectRuntimeShell.md), [string construction/COW memory](by-memory/0x00582500-0x00583206.LObjectStringConstructionAndCow.md), [string release/format/mutation memory](by-memory/0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation.md), [RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md), [PoolAllocator](by-file/PoolAllocator.md), [PoolAllocator class](by-class/PoolAllocator.md), [PoolAllocator core memory](by-memory/0x004b13d0-0x004b1585.PoolAllocatorCore.md), [PoolAllocatorLayout](by-type/by-struct/PoolAllocatorLayout.md), and [StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md) docs separate the current generated owner into source-migration concerns.

Follow-up:

- Recheck the final owner for `0x005832f0-0x00584d7d`, which continues the string implementation beyond the construction/COW memory page.
- Recheck active `class_PoolAllocator.cpp` after data fixes: it currently omits constructor/init `0x004b13d0`, free-list return `0x004b14c0`, destructor/cleanup `0x004b1520`, and the `0x00549bd0` chunk helper, while `class_ThreadSafeNodeList.cpp` owns the shared free-list push behavior.

#### 2026-05-26 follow-up - PoolAllocator/ThreadSafeNodeList ownership still needs data correction

Observed:

- IDA MCP confirms `sub_4B13D0` (`0x30` bytes), `sub_4B1400` (`0xb8` bytes), `sub_4B14C0` (`0x2f` bytes), `sub_4B1520` (`0x65` bytes), and `sub_549BD0` (`0x21` bytes).
- Active `class_PoolAllocator.cpp` still only address-scopes `PoolAllocator::Allocate` and materializes `AllocatePoolChunk` as a synthetic helper without the real `0x00549bd0` address.
- Active `class_ThreadSafeNodeList.cpp` still owns `0x004b14c0` as `ThreadSafeNodeList::PushFront`, but IDA xrefs from `ReleaseAnsiBuffer` and `ReleaseWideBuffer` prove allocator free-list return use for the string pools.
- IDA decompilation of the nineteen static constructor wrappers shows eleven concrete object/class pools and eight string-buffer pools; active generated data does not present this static-pool inventory as a coherent ownership map.
- Static constructor/destructor wrappers for the pools are compiler-generated and should not become source methods. Exact docs now split the wrappers around `WideApiDispatchInit` and around `0x0060c440`, which is `UniAPIInit` cleanup rather than a pool destructor wrapper.
- Constructor-failure pool-free wrappers at `0x00502420`, `0x00514ae0-0x00514d1e`, and `0x0053ce50` are compiler-generated cleanup/delete wrappers over concrete pools. They should be ignored as standalone source even though their pool targets are project-owned.

Expected:

- PoolAllocator data should own or cross-own constructor/init `0x004b13d0`, allocate `0x004b1400`, free-list return `0x004b14c0`, destructor/cleanup `0x004b1520`, and allocator-private chunk helper `0x00549bd0`.
- `ThreadSafeNodeList` should be demoted to behavior alias until a real standalone layout owner or non-allocator use is proven.
- Concrete static pool globals should be assigned near their consuming modules rather than collapsed into `PoolAllocator.cpp` or hidden under anonymous generated globals.

Impact:

- File/class documentation now treats [ThreadSafeNodeList](by-file/ThreadSafeNodeList.md) as an alias candidate and [PoolAllocator](by-file/PoolAllocator.md) as the stronger owner for the allocator island.
- [PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md) now tracks object-pane, `Motion`, `UserPane`, and string-buffer pool globals from IDA constructor/destructor evidence.
- Static init/cleanup wrapper docs now mark `0x0041a040-0x0041a27d`, `0x0041a4b0`, `0x0060c320-0x0060c43a`, and `0x0060c450` as compiler-generated wrapper evidence rather than reconstruction targets.
- New wrapper docs and `by-memory/-ignored.md` entries record the constructor-failure cleanup wrappers so they do not become false file/class methods during source reconstruction.
- Source reconstruction could otherwise create a false standalone `ThreadSafeNodeList.cpp` and omit needed PoolAllocator lifecycle functions.

Follow-up:

- Use the static-pool inventory to repair generated global ownership for the concrete pool addresses from `0x0069b894` through `0x0069bf34`.
- After Wave3 data fixes, re-materialize `class_PoolAllocator.cpp` and confirm `0x004b14c0` is either attached as `PoolAllocator::Free` or represented as a deliberate shared alias.

2026-05-26 documentation follow-up:

- Rechecked IDA MCP for `0x004b14c0`: decompilation is exactly a locked head-push using `this + 0x0c` and `this + 0x10`, and `lookup_funcs` confirms the surrounding `PoolAllocator` island plus chunk helper.
- Added `ThreadSafeNodeList` to [ignored class records](by-class/-ignored.md) and `ThreadSafeNodeList.cpp` to [ignored file/module candidates](by-file/-ignored.md) as generated aliases. This ignores the standalone class/file identity only; [0x004b14c0-0x004b14ef](by-memory/0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront.md) remains reconstructable allocator code.

### 2026-05-24 - `TimerMgr` and `TimerHandler` generated output omits real scheduler helpers

Observed:

- Active `class_TimerHandler.cpp` emits only `0x00597570` and scalar deleting destructor `0x00597650`.
- IDA confirms additional `TimerHandler`/timer wrapper functions at `0x00597580`, `0x005975d0`, `0x005975e0`, `0x00597600`, `0x00597610`, and `0x00597630`.
- IDA decompiles `0x00597580` as a `boost::exception` destructor, but the body installs the `TimerHandler` vtable and unregisters the object from `g_pTimerMgr`.
- Active `class_TimerMgr.cpp` omits IDA-confirmed timer queue helpers at `0x00597dc0`, `0x00597eb0`, `0x00597f20`, and `0x005980f0`.
- Active `class_TimerMgrTimerQueue.cpp` only emits the queue destructor at `0x00597fe0`; queue grow/insert/remove helpers are emitted under `TimerMgr` or omitted.
- IDA names/decompiles `0x00597780` through a `sub_60C270` static destructor artifact even though the instruction body is the static `TimerMgr` destructor for instance storage at `0x0069b3ac`.
- Existing docs previously treated `0x00597610-0x00597645` as sound-manager timer wrappers; caller and body evidence show these are generic `TimerHandler` wrappers forwarding to `g_pTimerMgr`.
- Existing docs previously treated `0x00597580` as `EventDispatcher` and `0x00597600` as `InterfaceEfx`; current exact memory pages resolve them as [TimerHandler destructor](by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md) and [TimerHandler schedule/remove wrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md).

Expected:

- Restore or explicitly attach the omitted `TimerHandler` and queue helper functions to the timer scheduler module.
- Correct the `0x00597580` owner/type away from `boost::exception` before migration.
- Keep `TimerMgr`, `TimerMgrTimerQueue`, likely `TimerHandler`, and queue helper functions together for source migration.
- Keep `TimerPane` separate; it starts at `0x005986e0`, immediately after `TimerMgr::InsertTimer`.

Impact:

- Updated [TimerMgr](by-file/TimerMgr.md), new [TimerMgr class](by-class/TimerMgr.md), [TimerMgrTimerQueue](by-class/TimerMgrTimerQueue.md), [TimerHandler](by-class/TimerHandler.md), [timer memory](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md), [g_pTimerMgr](by-global/g_pTimerMgr.md), [ScheduledTimerEvent](by-type/by-struct/ScheduledTimerEvent.md), [TimerMgrLayout](by-type/by-struct/TimerMgrLayout.md), and [client timing](by-meta/client_timing.md) docs record the corrected ownership model.

Follow-up:

- Attach or restore `0x00597580`, `0x005975d0`, `0x005975e0`, `0x00597600`, `0x00597610`, `0x00597630`, `0x00597dc0`, `0x00597eb0`, `0x00597f20`, and `0x005980f0`.
- Decide whether final source has one `util/TimerMgr.cpp` or a tiny `util/TimerHandler.cpp` companion.

2026-05-24 follow-up:

- Documentation now has exact `TimerHandler` pages for `0x00597580-0x005975c3`, `0x005975e0-0x0059760d`, and `0x00597610-0x00597645`.
- Documentation now has an exact [TimerMgr queue helper](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md) page for `0x00597dc0`, `0x00597eb0`, `0x00597f20`, `0x005980f0`, `0x00598290`, and `0x00598480`.
- Remaining generated-data follow-up is to restore/attach the omitted rows in Wave3 output; source migration should use the documentation pages as the ownership guide.

### 2026-05-24 - `TimerPane` active output omits configuration and teardown helpers

Observed:

- Active `source-3/simroot_v2/class_TimerPane.cpp` emits constructor `0x005986e0`, timer callback `0x00598900`, draw `0x00598960`, digit draw `0x00598b40`, and scalar deleting destructor `0x00598c60`.
- IDA MCP confirms active output omits real functions at `0x00598850`, `0x00598880`, and `0x00598c30`.
- `0x00598880` is required behavior: MapPane packet opcode `0x67` and helper `0x005140a0` call it to set timer mode, value, start time, and expiration time.
- Disabled output marks `0x00598c3b` as missing code, but IDA confirms it is a real destructor adjustor thunk that forwards to `0x00598c60`.
- Disabled output includes `0x00598c46`, but active output does not include the paired `0x00598c3b`/`0x00598c46` thunk set or the singleton-clear helper `0x00598c30`.
- Generated destructor text calls `TextButtonExControlPane::~Pane(this)`; IDA behavior indicates shared pane-base cleanup through `0x00544580`, so the generated base label is suspicious.
- The TimerPane range must end before `0x00598cc0`, which IDA confirms as the next class (`TotemFrame`).

Expected:

- Restore or explicitly attach `0x00598850`, `0x00598880`, `0x00598c30`, `0x00598c3b`, and `0x00598c46` to `TimerPane`.
- Preserve `TimerPane` as UI/map overlay code, not part of the `TimerMgr` scheduler source.
- Correct destructor/base labels before using generated source as migration-ready C++.
- Keep MapPane packet opcode `0x67` naming linked to `TimerPane::SetTimer`.

Impact:

- New [TimerPane](by-file/TimerPane.md), [TimerPane class](by-class/TimerPane.md), [TimerPane memory](by-memory/0x005986e0-0x00598cbe.TimerPane.md), [g_pTimerPane](by-global/g_pTimerPane.md), [TimerPaneLayout](by-type/by-struct/TimerPaneLayout.md), and [timer number resources](by-resource/timerpane-number-resources.md) docs use IDA-confirmed boundaries and record the missing active-output helpers.

Follow-up:

- Attach or restore the omitted helper functions in Wave3 metadata.
- Rename `sub_598880` as the canonical timer configuration method after packet-mode semantics are finalized.
- Decide whether final source layout uses `map/TimerPane.cpp` or folds the class into `map/MapPane.cpp` as a private companion.

### 2026-05-24 - `TotemFrame` active output omits cleanup helpers and has bad thunk recovery

Observed:

- Active `source-3/simroot_v2/class_TotemFrame.cpp` emits constructor `0x00598cc0`, paint `0x00598dd0`, and scalar deleting destructor `0x00598e70`.
- IDA MCP confirms active output omits real functions at `0x00598da0` and `0x00598e40`.
- `0x00598da0` is the non-deleting cleanup body: it reinstalls vtables, clears `g_pTotemFrame`, and calls pane base cleanup.
- `0x00598e40` is a singleton-clear helper for `g_pTotemFrame`.
- Disabled output marks `0x00598e4b` as missing code, but IDA confirms it is a destructor adjustor thunk that forwards to `0x00598e70`.
- Disabled output emits `0x00598e56` with a nonsensical adjusted-this expression; IDA confirms it is the sibling adjustor thunk that subtracts `0xa4`.
- Generated destructor text calls `TextButtonExControlPane::~Pane(this)`; IDA behavior indicates shared pane-base cleanup through `0x00544580`, so the generated base label is suspicious.
- The TotemFrame range must end before `0x00598ed0`, which IDA confirms as [TransferServerDialogPane](by-file/TransferServerDialogPane.md).

Expected:

- Restore or explicitly attach `0x00598da0`, `0x00598e40`, `0x00598e4b`, and `0x00598e56` to `TotemFrame`.
- Correct destructor/base labels before using generated source as migration-ready C++.
- Keep `g_pTotemFrame` at `0x0069b35c` with the totem/status frame source, not generic frame chrome.

Impact:

- Updated [TotemFrame](by-file/TotemFrame.md), [TotemFrame class](by-class/TotemFrame.md), and [TotemFrame memory](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md), plus new [g_pTotemFrame](by-global/g_pTotemFrame.md) and [totem frame resources](by-resource/totem-frame-resources.md), record the IDA-confirmed helper set and source-owner caveats.

Follow-up:

- Attach or restore the omitted helper functions in Wave3 metadata.
- Decode the frame-index helper at `0x005bdc60` to name the `TOTFRAME.EPD` frame selection semantics.
- Decide whether final source layout uses `ui/panels/TotemFrame.cpp` or folds the class into the old user-status/totem UI source.

### 2026-05-24 - `UserStatusPane` family active output omits packet/update helpers and shared destructor tail pieces

Observed:

- Active `source-3/simroot_v2/class_UserStatusPane.cpp` emits constructor `0x005b83b0`, cleanup `0x005b8530`, `SetStatusIconId` `0x005b86e0`, hover `0x005b8a10`, paint `0x005b8c70`, glyph draw `0x005ba020`, and scalar deleting destructor `0x005bff20`.
- IDA MCP confirms omitted real `UserStatusPane` functions at `0x005b85b0`, `0x005b85d0`, `0x005b85f0`, `0x005b8600`, `0x005b8610`, `0x005b8620`, `0x005b8630`, `0x005b8640`, `0x005b8650`, `0x005b8660`, `0x005b8670`, `0x005b86a0`, `0x005b8700`, `0x005b9db0`, and `0x005ba4a0`.
- Active `source-3/simroot_v2/class_CharacterSummaryRecord.cpp` emits most of `0x005b85b0-0x005b86ca` as a standalone recovered class. IDA recheck shows those methods are `UserStatusPane` accessors over fields initialized by `UserStatusPane::UserStatusPane` at `0x005b83b0`; `DAT_0069ae0c` is `g_activeUserStatusPane`, not a separate `CharacterSummaryRecord` object.
- `class_CharacterSummaryRecord.cpp` still omits sibling getter `0x005b8660`.
- Active `class_UserStatusPane2.cpp` omits `0x005bac80`, `0x005bbe60`, `0x005bc420`, and the first destructor adjustor thunk `0x005bfc4d`.
- Active `class_OldUserStatusPane.cpp` omits `0x005bdcb0`, `0x005bf150`, `0x005bf7c0`, the singleton clear helper `0x005bfbe0`, and the first destructor adjustor thunk `0x005bfc37`.
- Disabled status-pane output marks several real thunks as missing (`0x005bfc63`, `0x005bfc4d`, `0x005bfc37`) or emits bad adjusted-this expressions (`0x005bfc6e`, `0x005bfc42`).
- `class_OldUserStatusPane.cpp` contains literal `` `n`n`` text in the constructor body after `wcscpy_s(...)`.
- The shared tail at `0x005bfbd0-0x005c0034` interleaves singleton clear helpers, adjustor thunks, scalar deleting destructors, and one generic vector helper across `UserStatusPane`, `UserStatusPane2`, `OldUserStatusPane`, `MenuVarietyPane`, and `MenuVarietySelectPane`; it should not be assigned as one class-owned contiguous range.
- IDA confirms `0x005bc610` starts `MenuVarietyPane`, so `UserStatusPane2` must end at `0x005bc60c`.
- 2026-05-26 IDA recheck confirms `0x005bd9b0-0x005bda3b` is the [MenuVarietySelectPane hit-test helper](by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md), immediately before `OldUserStatusPane`; do not extend `OldUserStatusPane` backward over it.

Expected:

- Restore or explicitly attach the omitted status-pane accessors, packet routers, rect helpers, status payload application helpers, singleton clear helpers, destructor adjustors, and scalar deleting destructors.
- Do not migrate `CharacterSummaryRecord.cpp` as a standalone original source file; fold it into `UserStatusPane.cpp` or document it as a private field-layout slice.
- Correct bad thunk adjusted-this recovery before treating generated source as migration-ready C++.
- Clean the literal `` `n`n`` artifact from `class_OldUserStatusPane.cpp`.
- Preserve [MenuVarietyPanes](by-file/MenuVarietyPanes.md) as a separate file despite address adjacency.

Impact:

- New [UserStatusPane](by-file/UserStatusPane.md), [UserStatusPane class](by-class/UserStatusPane.md), [UserStatusPane2](by-class/UserStatusPane2.md), [OldUserStatusPane](by-class/OldUserStatusPane.md), status memory pages, [UI pane destructor/thunk tail](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md), user-status globals, [user status resources](by-resource/user-status-resources.md), [CharacterSummaryRecord generated split](by-file/CharacterSummaryRecord.md), and [UserStatusPaneSummaryFields](by-type/by-struct/UserStatusPaneSummaryFields.md) document the IDA-confirmed source grouping and exclusions.
- 2026-05-26 follow-up: added [UserStatusPane summary accessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md) as the exact memory anchor for the generated `CharacterSummaryRecord` pseudo-class island. IDA MCP confirms all twelve function starts, including omitted sibling getter `0x005b8660`, and related file/class/type docs now cross-link the exact island.

Follow-up:

- Promote `0x005b8700`, `0x005ba4a0`, `0x005bac80`, `0x005bc420`, `0x005bdcb0`, and `0x005bf7c0` into the correct status-pane class data.
- Decide whether `TotemFrame` remains `ui/panels/TotemFrame.cpp` or becomes a private companion in `UserStatusPane.cpp`.

### 2026-05-24 - `SoundStatusPane` active output omits cleanup helpers and has bad thunk recovery

Observed:

- Active `source-3/simroot_v2/class_SoundStatusPane.cpp` emits constructor `0x0057bf70`, hotkey handler `0x0057c080`, caption refresh `0x0057c160`, and scalar deleting destructor `0x0057c270`.
- IDA MCP confirms active output omits real functions at `0x0057c050` and `0x0057c240`.
- `0x0057c050` is a non-deleting cleanup body: it reinstalls SoundStatusPane vtables, clears `g_pSoundStatusPane`, and calls shared pane cleanup.
- `0x0057c240` is a singleton-clear helper for `g_pSoundStatusPane`.
- Disabled output marks `0x0057c24b` as missing code, but IDA confirms it is a destructor adjustor thunk that subtracts `0xa0` and forwards to `0x0057c270`.
- Disabled output emits `0x0057c256` with a bad adjusted-this expression; IDA confirms it is the sibling adjustor thunk that subtracts `0xa4`.
- Generated destructor text calls `TextButtonExControlPane::~Pane(this)`; IDA behavior indicates shared pane-base cleanup through `0x00544580`, so the generated base label is provisional.
- The SoundStatusPane range must end before `0x0057c2d0`, which IDA confirms as `SpellInventoryPane`.

Expected:

- Restore or explicitly attach `0x0057c050`, `0x0057c240`, `0x0057c24b`, and `0x0057c256` to `SoundStatusPane`.
- Correct bad thunk adjusted-this recovery before treating generated source as migration-ready C++.
- Keep `SoundStatusPane` as `ui/panels/` HUD code, not part of `audio/SoundManager.cpp`.
- Preserve `g_pSoundStatusPane` at `0x0069b4d4` with the UI pane source.

Impact:

- New [SoundStatusPane](by-file/SoundStatusPane.md), [SoundStatusPane class](by-class/SoundStatusPane.md), [SoundStatusPane memory](by-memory/0x0057bf70-0x0057c2cf.SoundStatusPane.md), and [g_pSoundStatusPane](by-global/g_pSoundStatusPane.md) docs use IDA-confirmed boundaries and record the omitted helper/thunk caveats.

Follow-up:

- Attach or restore the omitted helper functions in Wave3 metadata.
- Recheck `class_SoundStatusPane.cpp` after Wave3 fixes for `0x0057c050`, `0x0057c240`, `0x0057c24b`, and `0x0057c256`.
- Resolve the exact inherited base class for the status-text/control pane before compile-oriented migration.

### 2026-05-24 - `MiniMapButtonPane` active output omits cleanup helpers and overlaps old MapNamePane aggregate range

Observed:

- Active `source-3/simroot_v2/class_MiniMapButtonPane.cpp` emits constructor `0x00503580`, paint `0x00503650`, mouse handler `0x005036a0`, and scalar deleting destructor `0x00503900`.
- IDA MCP confirms active output omits real functions at `0x00503620` and `0x00503800`.
- `0x00503620` is a non-deleting cleanup body: it reinstalls MiniMapButtonPane vtables, clears `g_pMiniMapButtonPane`, and calls shared pane cleanup.
- `0x00503800` is a singleton-clear helper for `g_pMiniMapButtonPane`.
- IDA confirms MiniMapButtonPane destructor adjustor thunks at `0x00503821` and `0x0050382c`.
- The local island is interleaved with `MapNamePane`: `MapNamePane` owns `0x0050380b`, `0x00503816`, and scalar deleting destructor `0x00503840`, while `MiniMapButtonPane` owns the surrounding `0x00503821`, `0x0050382c`, and `0x00503900` destructor tail.
- Older docs used `0x005031f0-0x005038fd` as a MapName-only aggregate range; that crosses MiniMapButtonPane code beginning at `0x00503580`.
- Generated `MiniMapButtonPane::OnPaint` uses a polluted `FittingRoomDownloadControlPane::RenderTileFrame` helper label; behavior is minimap button tile-frame rendering, not cash-shop ownership.

2026-05-26 follow-up:

- Added exact pages for [MiniMapButtonPane cleanup](by-memory/0x00503620-0x00503648.MiniMapButtonPaneCleanup.md) and [MiniMapButtonPane clear/thunks](by-memory/0x00503800-0x00503836.MiniMapButtonPaneClearAndThunks.md). IDA MCP confirms starts at `0x00503620`, `0x00503800`, `0x00503821`, and `0x0050382c`; decompilation shows `0x00503620` and `0x00503800` clear `dword_69B4B8`, while the thunks adjust by `0xa0` and `0xa4` before forwarding to `0x00503900`.

Expected:

- Restore or explicitly attach `0x00503620`, `0x00503800`, `0x00503821`, and `0x0050382c` to `MiniMapButtonPane`.
- Use per-method ownership inside `0x005031f0-0x0050395f`; do not migrate the old MapName-only aggregate span as one class-owned block.
- Keep MiniMapButtonPane with the minimap/map UI source family despite the helper-label pollution.

Impact:

- New [MiniMapButtonPane](by-class/MiniMapButtonPane.md), [g_pMiniMapButtonPane](by-global/g_pMiniMapButtonPane.md), and [MapName/MiniMapButton memory island](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md) docs record the IDA-confirmed interleaving and source-owner caveats. A 2026-05-28 IDA recheck corrected the island end from `0x0050395e` to `0x0050395f`; the previous end omitted the final `retn 4` immediate byte.
- 2026-05-24 follow-up: [MapPane](by-file/MapPane.md), [proposed source tree](by-project-structure/proposed-source-tree.md), and the legacy [MapName aggregate](by-memory/0x005031f0-0x005038fd.MapNamePane.md) now describe the older range as per-method owned, with `MiniMapButtonPane` beginning at `0x00503580`.

Follow-up:

- Recheck `class_MiniMapButtonPane.cpp` after Wave3 fixes for `0x00503620` and `0x00503800`.
- Resolve whether final source placement is `map/MiniMap.cpp`, a standalone `map/MiniMapButtonPane.cpp`, or a private main-HUD helper beside minimap UI code.

### 2026-05-24 - `MiniMapDialog` generated output includes non-IDA starts and broad shared helper ownership

Observed:

- Active `source-3/simroot_v2/class_MiniMapDialog.cpp` emits local minimap methods plus shared dialog/control helpers.
- IDA MCP confirms real minimap starts at `0x00450ca0`, `0x00451330`, `0x004518b0`, `0x004519b0`, `0x00451a10`, `0x00451c90`, `0x004521a0`, `0x00452260`, `0x004523d0`, `0x00452d20`, `0x00452f70`, `0x004537bc`, `0x004537c7`, and `0x004537e0`.
- IDA MCP reports generated rows `0x004517a0` and `0x00452ce0` are not current IDA function starts.
- Active output attaches broad shared helpers `0x0049db60`, `0x0049dc10`, `0x0049dca0`, `0x0049dd80`, and `0x0049ddd0` to `MiniMapDialog`; IDA caller checks show broad cross-dialog/control use, including hundreds of callers for `0x0049dc10`.

2026-05-26 follow-up:

- Added [GetControlLayout_452260](by-global/GetControlLayout_452260.md) and exact memory page [0x00452260-0x0045239a](by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md). Current `simroot_v2` emits it at `recovered/GetControlLayout_00452260.cpp`; IDA MCP confirms start `0x00452260`, size `0x13a`, seven callers inside `MiniMapDialog::MiniMapDialog`, and that `0x004517a0` / `0x00452ce0` are still not function starts.

Expected:

- `0x004517a0` and `0x00452ce0` should be marked projected/internal labels, realigned, or given IDA/Wave3 function boundaries only if raw disassembly proves they are real functions.
- Shared dialog/control helpers should not be treated as minimap source ownership merely because they are emitted in `class_MiniMapDialog.cpp`.
- `GetControlLayout_452260` should remain minimap-specific free helper ownership; IDA confirms seven constructor calls inside `MiniMapDialog::MiniMapDialog`.

Impact:

- New [MiniMapDialog](by-class/MiniMapDialog.md), [MiniMapRenderer](by-class/MiniMapRenderer.md), [MiniMapImageControlPane](by-class/MiniMapImageControlPane.md), [MiniMapSymbolControlPane](by-class/MiniMapSymbolControlPane.md), [MiniMap dialog memory](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md), and [MiniMap renderer/control memory](by-memory/0x00453df0-0x004563b4.MiniMapRendererAndControls.md) docs use IDA-confirmed anchors and mark the broad helper pollution separately.

Follow-up:

- Recheck `class_MiniMapDialog.cpp` after Wave3 fixes for `0x004517a0`, `0x00452ce0`, and the `0x0049db60+` shared helper ownership.
- Review renderer support helpers around `0x004550d0-0x00455b40` before deciding whether they are minimap file-local helpers or generic collection/string support.

### 2026-05-24 - `WorldMapPane` active output owns generic frame-registry wrappers

Observed:

- Active `source-3/simroot_v2/class_WorldMapPane.cpp` emits `0x004b6d00` as `WorldMapPane::RegisterFrameCallback` and `0x004b6d20` as `WorldMapPane::StopAnimation`.
- IDA MCP confirms both are real functions, but `0x004b6d00` only calls `FrameMgr::Insert(g_frameRegistry, this, currentFrame + 1)` and `0x004b6d20` only calls `FrameMgr::RemoveFrame(g_frameRegistry, this)`.
- Caller/xref checks show broad callers for both wrappers from living-object, screen/effect, and world-map paths. They are not world-map-private code.

Expected:

- Keep `0x004b6d00` and `0x004b6d20` with [FrameMgr And FrameHandler](by-file/FrameMgr.md) / [Frame scheduler memory](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md).
- WorldMapPane docs should reference these wrappers as generic frame scheduling dependencies, not proposed `map/WorldMapPane.cpp` contents.

Impact:

- Updated [WorldMapPane](by-file/WorldMapPane.md), [WorldMapPane class](by-class/WorldMapPane.md), [WorldMap memory](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md), and frame scheduler docs now exclude the wrapper ownership from the world-map source module.

Follow-up:

- Recheck generated WorldMap ownership after Wave3 frame-wrapper ownership fixes.
- Consider renaming the wrappers generically in data/model output as `FrameHandler::ScheduleNextFrame` and `FrameHandler::RemoveFrame` or equivalent.

### 2026-05-24 - `InterfaceEfxMgr` active output omits manager helpers and helper labels are polluted

Observed:

- Active `source-3/simroot_v2/class_InterfaceEfxMgr.cpp` emits constructor `0x004e9d00`, periodic frame-effect spawner `0x004e9f40`, and scalar deleting destructor `0x004ea090`.
- IDA MCP confirms active output omits real manager functions at `0x004e9ee0` and `0x004ea060`.
- `0x004e9ee0` is a trigger helper called by [GeneralPurposePanel](by-file/GeneralPurposePanel.md) at `0x004b880b`; it plays one of the persistent character/item/magic interface effects when the client option flag is enabled.
- `0x004ea060` is a singleton-clear helper for `g_pInterfaceEfxMgr`.
- Active output also omits the destructor adjustor thunks at `0x004ea06b` and `0x004ea076`, although generated metadata records them as excluded compiler thunks.
- Active `source-3/simroot_v2/class_InterfaceEfx.cpp` contains helper/base labels such as `FittingRoomListPane::OnRender` and `TextButtonExControlPane::~Pane`; current behavior ties the range to interface-effect rendering and shared pane cleanup, not fitting-room or text-button ownership.
- IDA confirms `0x004ea130` starts an `InventoryPane`-side constructor that allocates/uses an `InterfaceEfx`; it should not be absorbed into the `InterfaceEfxMgr` range.

Expected:

- Restore or explicitly attach `0x004e9ee0`, `0x004ea060`, `0x004ea06b`, and `0x004ea076` to `InterfaceEfxMgr`.
- Keep `0x004e97b0-0x004ea121` as the InterfaceEfx/InterfaceEfxMgr ownership island. IDA MCP recheck on 2026-05-28 showed the prior `0x004ea120` end was one byte short: `0x004ea120` is the final byte of the scalar deleting destructor's `retn 4`, `0x004ea121-0x004ea130` is alignment, and `0x004ea130` starts the `InventoryPane` constructor-side code.
- Treat fitting-room/text-button labels inside `class_InterfaceEfx.cpp` as provisional shared-helper/base labels until pane inheritance is resolved.
- Keep the module as old-layout UI/interface effect code, separate from the map/screen overlay effecter source family.

Impact:

- New [InterfaceEfx](by-file/InterfaceEfx.md), [InterfaceEfx class](by-class/InterfaceEfx.md), [InterfaceEfxMgr](by-class/InterfaceEfxMgr.md), [InterfaceEfx/manager memory](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md), [g_pInterfaceEfxMgr](by-global/g_pInterfaceEfxMgr.md), and [interface effect resources](by-resource/interface-efx-resources.md) docs use the IDA-confirmed boundaries and call out the omitted active-output helpers. Exact pages now cover the omitted [trigger helper](by-memory/0x004e9ee0-0x004e9f2c.InterfaceEfxMgrTriggerInterfaceEffect.md) and [singleton/thunk helpers](by-memory/0x004ea060-0x004ea080.InterfaceEfxMgrSingletonAndThunks.md). The former `0x00597600` InterfaceEfx helper page has been replaced by generic [TimerHandler schedule/remove wrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md).

Follow-up:

- Recheck `class_InterfaceEfxMgr.cpp` after Wave3 fixes for `0x004e9ee0`, `0x004ea060`, `0x004ea06b`, and `0x004ea076`.
- Resolve whether final source placement is one `ui/InterfaceEfx.cpp` file or a split `ui/InterfaceEfx.cpp` plus `ui/InterfaceEfxMgr.cpp`.

### 2026-05-24 - `SelfSaveOKPane` active output mixes SpelledPane and shared text-control ownership

Observed:

- Active `source-3/simroot_v2/class_SelfSaveOKPane.cpp` emits the small `SelfSaveOKPane` constructor/timer island at `0x005147d0-0x00514913`, but also attaches much later methods from unrelated source families.
- 2026-05-26 IDA MCP recheck shows the small pane is packet-created UI: `MapPane::HandlePacket` case `0x21` inlines the same construction sequence around `0x00508516-0x005085ed`, a standalone factory-like helper exists at `0x00513800`, and `SelfSaveOKPane::OnTimerExpired` is present in the timer-facet vtable at `0x0061e850`.
- 2026-05-26 IDA `py_eval` recheck reconfirms `0x00508516` is inside `MapPane::HandlePacket` (`0x00507c90`), installs the three SelfSaveOKPane vtables at `0x0050855b`, `0x00508561`, and `0x0050856b`, fetches localized string id `61`, and uses the same text-setting helper as the standalone constructor/factory.
- IDA MCP confirms `0x0056bca0`, `0x0056be20`, `0x0056bea0`, and `0x0056c0e0` are real functions, but caller evidence ties them to [SpelledPane](by-class/SpelledPane.md) entry state. `0x0056c300` adjusts from a frame-handler subobject back to the owner before calling the same rebuild helper.
- IDA MCP confirms `0x00572fd0` and `0x00573900` are vector insert/erase helpers for the same entry records, not meaningful `SelfSaveOKPane` behavior.
- IDA MCP caller fanout for `0x0058e270`, `0x0058ea80`, `0x0058fef0`, and `0x005905f0` is broad across UI controls, so those methods should be reviewed with [TextEditPane](by-class/TextEditPane.md) / [TextBoxPane](by-class/TextBoxPane.md), not migrated as SelfSave-specific code.
- Current `source-3/simroot_v2/class_SelfSaveOKPane.meta_wave3` still reports `vtable_count: 0` and `method_count: 24`, even though IDA confirms three SelfSaveOKPane vtable bases and the extra methods have non-SelfSave caller evidence.

Expected:

- Keep [SelfSaveOKPane](by-class/SelfSaveOKPane.md) limited to the `0x005147d0-0x00514914` island unless new caller/vtable evidence expands it.
- Reassign or exclude `0x0056bca0-0x0056c0da`, `0x00572fd0`, and `0x00573900` from the active `SelfSaveOKPane` class/file in favor of SpelledPane entry storage.
- Reassign or exclude the `0x0058e270-0x005905f0` text-control methods from `SelfSaveOKPane`; they are shared text-edit/text-box behavior.

Impact:

- New [SelfSaveOKPane](by-class/SelfSaveOKPane.md), [SelfSaveOKPane file](by-file/SelfSaveOKPane.md), [SelfSaveOKPane memory](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md), [SelfSaveOKPane factory helper](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md), and [SelfSaveOKPane vtables](by-type/by-vtable/SelfSaveOKPane_vtables.md) docs define the narrow safe island and packet-created lifecycle.
- Updated [SpelledPane](by-class/SpelledPane.md), [SpelledPane file](by-file/SpelledPane.md), and [SpelledPane memory](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md) docs assign the entry-list helpers as provisional SpelledPane ownership.

Follow-up:

- Recheck `class_SelfSaveOKPane.cpp` after Wave3 ownership fixes for the entry-list cluster and text-control methods.
- Recheck whether the standalone constructor at `0x005147d0` should remain source-facing or be treated as a duplicate of the inline packet/factory construction sequence; the small pane itself is now confirmed as packet-created UI.

### 2026-05-24 - `BulletinSession` active output includes broad base/helper methods

Observed:

- Active `source-3/simroot_v2/class_BulletinSession.cpp` has a strong session core at `0x00471150-0x00471ff1`, destructor at `0x0047ea90`, and stack helpers at `0x004a0f40-0x004a1390`.
- The same generated class also attaches scattered helpers including `0x00544690` as `MarkForDeletion` and `0x00538c40` as `RemoveFromUpdateScheduler`.
- IDA MCP caller checks show `0x00544690` has very broad caller fanout across many pane/dialog classes and should be treated as shared pane/dialog infrastructure, not BulletinSession-specific source.
- 2026-05-26 IDA MCP recheck resolves `0x00538c40` as BowGauge/UserPane timer cleanup: it forwards `this + 0xa4` to the timer removal routine and is called only from `UserPane` destructor/hide paths through `g_pBowGaugeObjectPane`.
- 2026-05-26 IDA MCP recheck resolves scattered helper `0x00481ad0` as the six-row `ChattingVarietySelectPane` hit-test helper called only from `ChattingVarietySelectPane::OnMouseEvent`.
- 2026-05-26 IDA MCP recheck resolves scattered helper `0x004ffd40` as the `HistoryViewingPane` advance-page helper called only from `HistoryViewingPane::OnKeyDown`.
- 2026-05-26 IDA MCP recheck resolves generated `BulletinSession::GetMenuIndexFromPoint` at `0x005bd9b0` as the ten-row `MenuVarietySelectPane` hit-test helper called only from `MenuVarietySelectPane::HandleMenuMouseEvent`.
- `0x005556f0` has since been resolved as a `RightButtonMenuPane` hit-test helper, while `0x00556070` has since been resolved as a `VoteMenuPane` hit-test helper.

Expected:

- Keep [BulletinSession](by-class/BulletinSession.md) ownership focused on the core session/dialog-flow and dialog-stack ranges.
- Reassign or exclude `0x00544690` from `BulletinSession` in favor of the pane/dialog base owner.
- Keep `0x00538c40`, `0x00481ad0`, `0x004ffd40`, and `0x005bd9b0` out of `BulletinSession` source migration; they now have concrete non-bulletin owners.

Impact:

- New [BulletinSession](by-class/BulletinSession.md), [BulletinSession file](by-file/BulletinSession.md), [BulletinSession core memory](by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md), [BulletinSession dialog stack memory](by-memory/0x004a0f40-0x004a14a7.BulletinSessionDialogStack.md), and [g_pBulletinSession](by-global/g_pBulletinSession.md) docs preserve the safe ownership split.
- 2026-05-26: Added [BowGauge timer cleanup](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md), [g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md), [g_pBowGaugeObjectPane memory](by-memory/0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane.md), [ChattingVarietySelectPane hit-test](by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md), [HistoryViewingPane advance-page support](by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md), and [MenuVarietySelectPane hit-test](by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md); updated the class/file owners to remove these helpers from BulletinSession.

Follow-up:

- Perform any remaining base-owner pass for `0x00544690` only. The prior `0x00538c40`, `0x00481ad0`, `0x004ffd40`, `0x005bd9b0`, `0x005556f0`, and `0x00556070` helper ownership questions are now covered by their concrete owner docs.

### 2026-05-24 - `Motion` and `Region` generated output conflates multiple source families

Observed:

- Active `source-3/simroot_v2/class_Motion.cpp` mixes timer-driven animation methods (`0x00539bc0-0x0053d613`), rectangle/dirty-region helpers (`0x005546f0-0x00554ae0`), a message/menu-question dialog packet dispatcher (`0x0054c200`), and a stale base destructor label at `0x004f4a90`.
- Active `source-3/simroot_v2/class_Region.cpp` contains the real local Region rectangle constructor/destructor range around `0x00554680-0x00554b00`, but also emits unrelated methods such as `GetUsagePercent`, `ToLong`, a wide-string constructor, and `SimpleUString::c_str`.
- 2026-05-27 IDA recheck resolves generated `Region::GetUsagePercent` at `0x0041a580` as [FittingRoomDownloadProgressState](by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md): its only direct caller is `FittingRoomDialog::HandleFittingAction` at `0x0041cbbc`, where it computes a fitting-room/download progress percentage from a request-state pointer plus `4`.
- 2026-05-26 IDA `py_eval` recheck confirms all mapped dirty-rectangle starts from `0x00554680` through `0x00554b00`, `Region` vtable `0x00622f58`, constructor store `0x005546c1`, and `Region` RTTI/name records. The valid local `Region` identity is stronger than the polluted generated file.
- IDA MCP caller/callee checks show `0x0054c200` constructs message/menu-question dialogs and belongs with [MessageDialogs](by-file/MessageDialogs.md), not Motion.
- IDA MCP caller checks show [VectorGrowMotion](by-global/VectorGrowMotion.md) at `0x004e5240` is only called from `NewHumanImageLib::LoadMotionTable`, and [DestroyMotionVector](by-global/DestroyMotionVector.md) at `0x004e5dd0` is called from NewHuman cleanup. These are `Motion.tbl` vector helpers, not Motion class methods.
- Older Wave2 notes identify `0x004f4a90` as `LObject` base destructor behavior despite trace labels like `Motion::~LObject`.

Expected:

- Keep [Motion](by-class/Motion.md) documentation split between animation and rectangle/dirty-region families.
- Reassign `0x0054c200` to [MessageDialogs](by-file/MessageDialogs.md).
- Reassign or exclude unrelated generated `Region` methods outside the local rectangle range.
- Reassign `0x0041a580` and sibling helpers at `0x0041a550-0x0041a5c1` to fitting-room/download progress state, not `Region`.
- Keep `VectorGrowMotion` and `DestroyMotionVector` with [NewHumanImageLib](by-file/NewHumanImageLib.md).

Impact:

- New [Motion](by-file/Motion.md), [Motion class](by-class/Motion.md), [Region class](by-class/Region.md), [Region vtable](by-type/by-vtable/RegionVtable.md), [Motion animation memory](by-memory/0x00539bc0-0x0053d613.MotionAnimation.md), [Region/Motion rectangle memory](by-memory/0x00554680-0x00554b37.RegionAndMotionRect.md), and [new human motion tables](by-resource/new-human-motion-tables.md) docs preserve the safe split.

Follow-up:

- Perform a focused vtable/struct pass to decide whether the animation object and dirty-rectangle object share a final `Motion` class name or need separate canonical names.
- Recheck `class_Motion.cpp` and `class_Region.cpp` after Wave3 ownership fixes for `0x0054c200`, `0x004f4a90`, and the unrelated Region/string methods.

### 2026-05-24 - `ListPane` shared helpers are split across feature owners

Observed:

- Active `source-3/simroot_v2/class_ListPane.cpp` contains the constructor, scroll metric virtuals, input/key/paint handlers, selection update, navigation helpers, and destructor for the reusable list control at `0x004f3a50-0x004f4a77`.
- Several adjacent shared helpers are emitted under unrelated owners:
  - `0x004f3bd0` as `ServerItemMenuItemList::GetItemCount`.
  - `0x004f3c00`, `0x004f3d60`, `0x004f3dd0`, and `0x004f3e80` under `ArticleListPane`.
  - `0x004f3c50`, `0x004f3dc0`, and `0x004f3f00` under `ChattingColorListPane`.
  - `0x004f3e20` as standalone `SelectionState`.
- IDA MCP caller checks show these helpers have broad fanout across board/mail, clan, exchange, item/menu, spell-menu, server-select, phone-book, user-list, and other UI list users.
- IDA MCP reports `0x004f4820` is not a function, even though disabled `class_ListPane.cpp` has a missing-code method at that address.

Expected:

- Reassign the shared list helpers to [ListPane](by-class/ListPane.md) / [ListPane.cpp](by-file/ListPane.md).
- Treat `SelectionState` as a generated alias over `ListPane` selection fields unless separate constructor/vtable evidence appears.
- Rename `0x004f3dd0` away from `SetSortEnabled`; the body sets the selection-mode byte, clears selection flags, and invalidates the selection region.
- Remove or ignore the stale disabled `0x004f4820` method unless a future IDA/function-boundary pass proves a real function there.

Impact:

- New [ListPane class](by-class/ListPane.md), [ListPane file](by-file/ListPane.md), [ListPane memory](by-memory/0x004f3a50-0x004f4a77.ListPane.md), and [SelectionState alias](by-class/SelectionState.md) docs define the safe source ownership.
- 2026-05-26 IDA `py_eval` recheck confirms `0x004f3e20-0x004f3e74` has 14 xrefs, no `SelectionState` names/RTTI, and nearby confirmed `ListPane` selection helpers at `0x004f3dd0`, `0x004f3e80`, and `0x004f3f00`. [SelectionState](by-class/SelectionState.md) is now marked ignored as a generated class alias, while the helper remains reconstructable under [ListPane](by-class/ListPane.md).
- [ArticleListPane](by-class/ArticleListPane.md) and [BoardDialogs](by-file/BoardDialogs.md) now treat the `0x004f3c00+` helpers as inherited/shared list control code, not board-private code.

Follow-up:

- Recheck the generated owners after Wave3 data fixes for the `0x004f3bd0-0x004f3f1b` helper block.
- Perform a later naming pass for exact original `ListPane` method names and field names at offsets `+0x130`, `+0x134`, `+0x138`, `+0x13c`, `+0x140`, `+0x144`, `+0x148`, and `+0x149`.

### 2026-05-24 - `PowerDialogPane` constructor is emitted under `PowerListPane`

Observed:

- Active `source-3/simroot_v2/class_PowerListPane.cpp` emits `0x00549c20` as `PowerListPane::InitializeFromData`.
- The body calls `DialogPane::DialogPane(L"Power", -1, 1)`, installs three `PowerDialogPane` vtables, creates seven header/image buttons, creates four embedded list controls, parses packet data, sorts the four list models, attaches the dialog, and stores the singleton pointer.
- `MapPane::HandlePacket` packet case `0x46` allocates `740` bytes and calls `0x00549c20` with the payload, matching full dialog construction rather than embedded list behavior.
- IDA MCP confirms `0x00549c20` is one real function of size `0x852` and confirms the embedded list-control methods at `0x0054b000`, `0x0054b220`, `0x0054b350`, and `0x0054b580`.
- IDA MCP reports `0x0054aec0` is not a function, even though disabled `class_PowerListPane.cpp` lists a missing-code method there.
- IDA MCP reports `0x0054b4fb` and `0x0054b511` are real `0xb` thunk starts, even though the disabled generated files list them as missing code.
- Generated global naming is split between `g_pPowerDialog` and `g_activePowerListPane`; IDA xrefs prove both names refer to the same `0x0069ba34` storage and the canonical owner is the power dialog singleton.
- 2026-05-26 IDA MCP recheck reconfirms the main boundaries, finds `0x0054a480` and `0x0054a4b0` as real singleton cleanup/getter helpers with no direct callers/xrefs, and reports an additional `0x00549c20` caller at `0x00513b93` under a stale `___std_parallel_algorithms_hw_threads@0_2` label.

Expected:

- Move or re-own `0x00549c20` under [PowerDialogPane](by-class/PowerDialogPane.md) / [PowerDialogPane.cpp](by-file/PowerDialogPane.md).
- Keep the real embedded list-control methods at `0x0054b000-0x0054b5d5` as [PowerListPane](by-class/PowerListPane.md), but in the same likely original source module as the dialog.
- Exclude or remove the stale disabled `0x0054aec0` generated method.
- Materialize or account for the real thunk starts at `0x0054b4fb` and `0x0054b511`.
- Normalize `0x0069ba34` as [g_pPowerDialog](by-global/g_pPowerDialog.md); do not materialize a separate `g_activePowerListPane` global.
- Normalize generated `g_powerThresholdConfig` uses to `g_pConfig` / `dword_67A7C8` field offsets until config-field names are recovered.

Impact:

- New [PowerDialogPane class](by-class/PowerDialogPane.md), [PowerListPane class](by-class/PowerListPane.md), [PowerDialogPane file](by-file/PowerDialogPane.md), and [Power dialog memory](by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md) docs use the IDA-confirmed ownership split.
- New [g_pPowerDialog global](by-global/g_pPowerDialog.md) and [g_pPowerDialog memory](by-memory/0x0069ba34-0x0069ba38.g_pPowerDialog.md) docs resolve the `g_pPowerDialog` / `g_activePowerListPane` alias conflict. The same pass found the generated `g_powerThresholdConfig` name is really `g_pConfig` / `dword_67A7C8` at offsets `0x28de94` through `0x28de9a`, while `g_defaultPaneStyle` is broad UI style storage at `dword_69B36C`.
- [Proposed source tree](by-project-structure/proposed-source-tree.md) now includes `ui/dialogs/PowerDialogPane.cpp` as a feature-dialog module.
- 2026-05-26: Added exact docs for [PowerDialogPane constructor](by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md), [PowerDialogPane singleton helpers](by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md), and [PowerDialogPane/PowerListPane adjustor thunks](by-memory/0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks.md). The four thunks are now entered in [by-memory ignored ranges](by-memory/-ignored.md) as compiler-generated adjustors.

Follow-up:

- Recheck `class_PowerListPane.cpp` and `class_PowerDialogPane.cpp` after Wave3 data fixes for `0x00549c20`, `0x0054a480`, `0x0054a4b0`, `0x0054aec0`, `0x0054b4fb`, and `0x0054b511`. Also recheck the extra `0x00513b93` caller currently carrying a stale/misleading IDA label.
- Recheck the generated global names after Wave3 data fixes: `g_activePowerListPane` should disappear or become `g_pPowerDialog`, and `g_powerThresholdConfig` should become a `g_pConfig` field access.

### 2026-05-24 - `StaffsDialogPane` omits singleton clear helper and one real thunk

Observed:

- Active `source-3/simroot_v2/class_StaffsDialogPane.cpp` emits the constructor at `0x004ffaa0`, action handler at `0x004ffd20`, and scalar deleting destructor at `0x00502cc0`.
- IDA MCP confirms an additional real `0xb` function at `0x00502410` that clears `g_pStaffsDialog` (`0x0069b490`), but the active generated class file does not emit it.
- Disabled `class_StaffsDialogPane.cpp` emits the `0x00502592` adjustor thunk, but lists `0x0050259d` as missing code; IDA MCP confirms `0x0050259d` is also a real `0xb` thunk.
- IDA MCP reports no direct callers for `0x004ffaa0`, `0x004ffd20`, or `0x00502cc0` in the current database. This is an unresolved reachability question, not proof that the class should be removed.
- Generated inherited helper labels in this class include mini-map, ranking, chat-color, fitting-room, and transfer-alert names. The behavior is a main-menu staff/credits dialog and should not migrate to those feature sources.

Expected:

- Attach or account for `0x00502410` as a `StaffsDialogPane` singleton clear helper or global helper for [g_pStaffsDialog](by-global/g_pStaffsDialog.md).
- Materialize or explicitly mark `0x0050259d` as a real destructor adjustor thunk instead of missing code.
- Keep [StaffsDialogPane](by-class/StaffsDialogPane.md) in the login/main-menu source family despite the lack of direct constructor caller evidence.

Impact:

- New [StaffsDialogPane class](by-class/StaffsDialogPane.md), [StaffsDialogPane file](by-file/StaffsDialogPane.md), [StaffsDialogPane core memory](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md), [g_pStaffsDialog](by-global/g_pStaffsDialog.md), and [staff dialog resources](by-resource/staff-dialog-resources.md) docs record the safe ownership and caveats.
- Added exact non-contiguous memory docs for [the singleton clear helper](by-memory/0x00502410-0x0050241b.StaffsDialogPaneSingletonClear.md), [the destructor thunks](by-memory/0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks.md), [the scalar deleting destructor](by-memory/0x00502cc0-0x00502d05.StaffsDialogPaneDestructor.md), and [g_pStaffsDialog storage](by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md).
- 2026-05-26 recheck: IDA MCP reconfirmed `0x00502410` as a one-assignment constructor EH cleanup helper and `0x00502592`/`0x0050259d` as vtable destructor adjustor thunks. Added both compiler-generated spans to [by-memory ignored ranges](by-memory/-ignored.md) so final source reconstruction models the constructor/destructor/inheritance rather than handwritten helper stubs.

Follow-up:

- Recheck `class_StaffsDialogPane.cpp` after Wave3 data fixes for `0x00502410` and `0x0050259d`; expected disposition is ignored compiler-generated cleanup/thunk metadata, not feature source methods.
- Investigate indirect menu action or vtable/global paths that may construct `StaffsDialogPane`; direct IDA caller lookup currently returns none.

### 2026-05-24 - `ForcedInformMessageDialog` support helpers are omitted or marked missing

Observed:

- Active `source-3/simroot_v2/class_ForcedInformMessageDialog.cpp` emits constructor `0x00587bb0`, non-deleting destructor `0x00588080`, button/key handlers `0x00588110` and `0x00588160`, and scalar deleting destructor `0x0058abf0`.
- IDA MCP confirms an additional real `0xb` singleton clear helper at `0x0058aa90` that clears `g_pForcedInformMessageDialog` (`0x0069b4a0`), but active generated output omits it.
- Disabled `class_ForcedInformMessageDialog.cpp` lists `0x0058aadb` as missing code, but IDA MCP confirms it is a real `0xb` destructor adjustor thunk. `0x0058aae6` is also a real `0xb` thunk and is emitted as a thunk.
- IDA MCP confirms `EnsureLoginDialogPane_4F8B30` is called only from the two `ForcedInformMessageDialog` destructor paths in the current caller set.
- IDA MCP `xrefs_to 0x0069b4a0` shows `CloseMainMenuDialogSingletons_004F69A0` reads the singleton, while constructor/destructor/support helpers write or clear it.
- `ForcedInformMessageDialog` is physically adjacent to [SystemMessagePanes](by-file/SystemMessagePanes.md), but its resource family and login-dialog teardown behavior make it a login/main-menu forced-notice dialog, not system-message viewport code.

Expected:

- Attach or account for `0x0058aa90` as a `ForcedInformMessageDialog` singleton clear helper or global helper for [g_pForcedInformMessageDialog](by-global/g_pForcedInformMessageDialog.md).
- Materialize or explicitly mark `0x0058aadb` as a real destructor adjustor thunk instead of missing code.
- Keep [ForcedInformMessageDialog](by-class/ForcedInformMessageDialog.md) out of [SystemMessagePanes](by-file/SystemMessagePanes.md) despite address locality.

Impact:

- New [ForcedInformMessageDialog class](by-class/ForcedInformMessageDialog.md), [ForcedInformMessageDialog file](by-file/ForcedInformMessageDialog.md), [ForcedInformMessageDialog core memory](by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md), [g_pForcedInformMessageDialog](by-global/g_pForcedInformMessageDialog.md), and [forced inform message resources](by-resource/forced-inform-message-resources.md) docs record the safe ownership.
- Added exact non-contiguous memory docs for [the singleton clear helper](by-memory/0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear.md), [the destructor thunks](by-memory/0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks.md), [the scalar deleting destructor](by-memory/0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor.md), and [g_pForcedInformMessageDialog storage](by-memory/0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog.md).
- [SystemMessagePanes](by-file/SystemMessagePanes.md) and [System message pane memory](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) now explicitly mark the forced-message dialog as a neighboring non-system-message island.
- 2026-05-26 recheck: IDA MCP reconfirmed `0x0058aa90` as a one-assignment constructor EH cleanup helper and `0x0058aadb`/`0x0058aae6` as vtable destructor adjustor thunks. Added both compiler-generated spans to [by-memory ignored ranges](by-memory/-ignored.md) so final source reconstruction models the constructor/destructor/inheritance rather than handwritten helper stubs.

Follow-up:

- Recheck `class_ForcedInformMessageDialog.cpp` after Wave3 data fixes for `0x0058aa90` and `0x0058aadb`; expected disposition is ignored compiler-generated cleanup/thunk metadata, not feature source methods.
- Investigate the indirect construction path for `0x00587bb0`; direct IDA caller lookup currently returns none.

### 2026-05-24 - HistoryViewingPane/NewHistoryDialogPane generated output omits singleton helpers and has owner pollution

Observed:

- Active `source-3/simroot_v2/class_HistoryViewingPane.cpp` emits the constructor, input/draw handlers, one thunk, and scalar deleting destructor, but IDA MCP confirms an additional real `0xb` singleton clear helper at `0x005023b0` that clears `g_pHistoryViewingPane` (`0x0069b494`).
- Disabled `class_HistoryViewingPane.cpp` lists `0x005024c1` as missing code, but IDA MCP confirms it is a real `0xb` destructor adjustor thunk forwarding to `0x00502760`.
- `source-3/simroot_v2/class_ChattingColorPane.cpp` also emits `HistoryViewingPane::OnKeyDown` at `0x004fff10`, which is owner pollution. IDA/main-menu caller evidence ties the method to `HistoryViewingPane`, not chat-color UI.
- IDA MCP confirms real retained story/history launch helpers at `0x004f90c0` and `0x004f9140`; no standalone `simroot_v2` recovered source file was found for either helper during this pass. Both allocate `HistoryViewingPane`, but IDA reports no direct callers/xrefs to the helper starts.
- Active `source-3/simroot_v2/class_NewHistoryDialogPane.cpp` emits constructor/input handlers and scalar deleting destructor, but IDA MCP confirms an additional real `0xb` singleton clear helper at `0x005023e0` that clears `g_pNewHistoryDialog` (`0x0069b49c`).
- Disabled `class_NewHistoryDialogPane.cpp` lists `0x00502503` as missing code, but IDA MCP confirms it is a real `0xb` destructor adjustor thunk forwarding to `0x00502920`.
- Older scrolled-text docs described `ScrolledTextControlPaneForMadeBy::OnTimerEvent` as closing a generic active dialog. IDA `xrefs_to 0x0069b49c` ties that path specifically to `g_pNewHistoryDialog`.

Expected:

- Active generated output should attach or explicitly list `0x005023b0` for `HistoryViewingPane` and `0x005023e0` for `NewHistoryDialogPane`.
- Disabled generated output should emit or explicitly mark `0x005024c1` and `0x00502503` as confirmed compiler thunks rather than missing code.
- `0x004fff10` should not be emitted under `ChattingColorPane`.
- Real launch helpers `0x004f90c0` and `0x004f9140` should be represented as retained main-menu helpers, explicit dead-code exclusions, or callback targets after xref review.
- The scrolled-text end-of-scroll close target should use `g_pNewHistoryDialog` or an explicit alias, not an unrelated generic active-dialog name.

Impact:

- New [HistoryViewingPane](by-file/HistoryViewingPane.md), [NewHistoryDialogPane](by-file/NewHistoryDialogPane.md), [HistoryViewingPane class](by-class/HistoryViewingPane.md), [NewHistoryDialogPane class](by-class/NewHistoryDialogPane.md), [g_pHistoryViewingPane](by-global/g_pHistoryViewingPane.md), [g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md), and exact memory docs use IDA-confirmed boundaries.
- Added exact non-contiguous memory docs for [HistoryViewingPane singleton clear](by-memory/0x005023b0-0x005023bb.HistoryViewingPaneSingletonClear.md), [HistoryViewingPane destructor thunks](by-memory/0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks.md), [HistoryViewingPane destructor](by-memory/0x00502760-0x005027cc.HistoryViewingPaneDestructor.md), [g_pHistoryViewingPane storage](by-memory/0x0069b494-0x0069b498.g_pHistoryViewingPane.md), [NewHistoryDialogPane singleton clear](by-memory/0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonClear.md), [NewHistoryDialogPane destructor thunks](by-memory/0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks.md), [NewHistoryDialogPane destructor](by-memory/0x00502920-0x00502965.NewHistoryDialogPaneDestructor.md), and [g_pNewHistoryDialog storage](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md).
- New [OpenStoryViewingPane_4F90C0](by-global/OpenStoryViewingPane_4F90C0.md), [OpenHistoryViewingPane_4F9140](by-global/OpenHistoryViewingPane_4F9140.md), and [HistoryViewingPane launch helpers memory](by-memory/0x004f90c0-0x004f91bf.HistoryViewingPaneLaunchHelpers.md) docs treat the wrappers as real but not proven live.
- 2026-05-26 IDA recheck still finds zero code refs and zero data refs to `0x004f90c0` and `0x004f9140`; keep both as retained helpers with weak live reachability.
- 2026-05-27 IDA raw-pointer scan across loaded segments found no dwords equal to `0x004f90c0` or `0x004f9140`; no obvious untyped callback table currently points at either retained helper.
- Do not migrate active `class_HistoryViewingPane.cpp`, `class_NewHistoryDialogPane.cpp`, or `class_ChattingColorPane.cpp` directly without correcting the omitted helpers, thunk rows, and ownership pollution above.
- 2026-05-26 recheck: IDA MCP reconfirmed `0x005023b0` and `0x005023e0` as one-assignment constructor EH cleanup helpers, and `0x005024b6`/`0x005024c1` plus `0x005024f8`/`0x00502503` as vtable destructor adjustor thunks. Added those compiler-generated spans to [by-memory ignored ranges](by-memory/-ignored.md) so final source reconstruction models the constructors/destructors/inheritance instead of handwritten helper stubs.

Follow-up:

- Recheck generated output after Wave3 fixes for `0x004fff10`, `0x005023b0`, `0x005024c1`, `0x005023e0`, and `0x00502503`; expected disposition for the singleton clear helpers and destructor thunks is ignored compiler-generated cleanup/thunk metadata, not feature source methods.
- Recheck generated output and IDA xrefs for `0x004f90c0` and `0x004f9140` before final disposition.
- Investigate the unresolved direct constructor path for `NewHistoryDialogPane::NewHistoryDialogPane` at `0x00500410`; IDA direct caller lookup currently returns none.

### 2026-05-24 - QuitDialog/QuitInputPane generated ownership and boundary caveats

Observed:

- Active `source-3/simroot_v2/class_QuitInputPane.cpp` emits `0x004f2300` and `0x004f2310` as `QuitInputPane::ReadInputText` and `QuitInputPane::GetInputLength`, but IDA caller fanout crosses many typed input panes. These are shared [LineInputPane](by-class/LineInputPane.md) helpers and should belong to [InputPanes](by-file/InputPanes.md).
- Active `class_QuitInputPane.cpp` emits a constructor marker at `0x005adcc0`; IDA MCP `lookup_funcs` currently says `Not a function`, but raw disassembly confirms a real constructor-shaped body ending at `0x005add17`.
- Disabled `class_QuitInputPane.cpp` lists destructor adjustors `0x005b7836` and `0x005b7841`; IDA MCP confirms both are real `0xb` functions that forward to `0x005b7b30`.
- Do not confuse `g_pQuitInputPane` with `0x0069b504`; the latter's xrefs belong to unrelated code during this pass.
- `class_QuitDialog.meta_wave3` contains an intermediate method-name history entry with a carriage return in `QuitDialog\r`; the active emitted source is cleaned back to `QuitDialog::QuitDialog()`.
- `0x005a94b0-0x005a95d2` is a real quit-prompt launcher that constructs either `QuitDialog` or `QuitInputPane`, but no standalone active generated source body was found for it during this pass.

Expected:

- Own `0x004f2300` and `0x004f2310` from the reusable input-pane base source, not from `QuitInputPane`.
- Preserve the real `0x005adcc0` constructor bytes even if the current IDA function table omits the function object.
- Materialize or explicitly retain `0x005b7836` and `0x005b7841` as confirmed `QuitInputPane` destructor thunks.
- Represent `0x005a94b0` as a quit dialog/input prompt launcher or private helper in [QuitDialogs](by-file/QuitDialogs.md).

Impact:

- New [QuitDialogs](by-file/QuitDialogs.md), [QuitDialog](by-class/QuitDialog.md), [QuitInputPane](by-class/QuitInputPane.md), [g_pQuitInputPane](by-global/g_pQuitInputPane.md), [OpenQuitPrompt_5A94B0](by-global/OpenQuitPrompt_5A94B0.md), and exact memory docs record the safe ownership and boundaries.
- Added exact [g_pQuitInputPane storage](by-memory/0x0069bf5c-0x0069bf60.g_pQuitInputPane.md) memory doc tying the singleton to `0x0069bf5c` and separating it from unrelated `0x0069b504`.
- 2026-05-26 recheck: IDA MCP reconfirmed `0x005b7836` and `0x005b7841` as vtable destructor adjustor thunks into `0x005b7b30`. Added [QuitInputPane destructor thunks](by-memory/0x005b7836-0x005b784c.QuitInputPaneDestructorThunks.md) to [by-memory ignored ranges](by-memory/-ignored.md); `0x005adcc0` remains reconstructable raw/projected constructor bytes, not ignored.

Follow-up:

- Recheck generated output after Wave3 fixes for `0x004f2300`, `0x004f2310`, `0x005adcc0`, `0x005a94b0`, `0x005b7836`, and `0x005b7841`; expected disposition for `0x005b7836` and `0x005b7841` is ignored compiler-generated thunk metadata, not feature source methods.

### 2026-05-24 - Block-list input panes have projected constructors, missing helper, and data-fragment methods

Observed:

- Active `source-3/simroot_v2/class_BlockListenInputPane.cpp`, `class_AddToBlockListenInputPane.cpp`, and `class_DeleteFromBlockListenInputPane.cpp` emit constructors at `0x005b68c0`, `0x005b6c80`, and `0x005b7100`.
- IDA MCP `lookup_funcs` reports those constructor starts as `Not a function`, but limited IDA disassembly confirms real constructor-shaped bodies at `0x005b68c0-0x005b6900`, `0x005b6c80-0x005b6cc0`, and `0x005b7100-0x005b7140`.
- IDA MCP confirms handlers at `0x005b6900`, `0x005b6a20`, `0x005b6cc0`, and `0x005b7140`.
- IDA MCP confirms a real helper at `0x005b74e0-0x005b7553`, called only by add/delete block-list handlers during this pass. `python source-3\wave3.py inspect method 0x005b74e0` returned `Unknown method: 0x005b74e0` while `wave3-status.md` was still `OPERATIONAL`.
- Wave3 attaches excluded `DeleteFromBlockListenInputPane` methods `0x00680067` and `0x00690052`; IDA says neither is a function. They are bogus pointer values read from UTF-16 `"Right click look :ON"` / `"Right click look :OFF"` string data at `0x006307ec`, `0x006307f0`, `0x00630818`, and `0x0063081c`; the target addresses themselves are undefined `0xff` filler bytes.
- The block-list handlers use shared input helpers `0x004f2300` and `0x004f2310`; older generated history names these through `QuitInputPane::meth_*`, but IDA caller fanout shows they are reusable input-pane helpers.

Expected:

- Preserve constructor bytes at `0x005b68c0`, `0x005b6c80`, and `0x005b7100` as projected/raw constructor starts or create IDA-compatible function records after review.
- Add or attach the real helper `0x005b74e0` as [FindBlockListEntry_5B74E0](by-global/FindBlockListEntry_5B74E0.md) under [BlockListenInputPanes](by-file/BlockListenInputPanes.md).
- Remove or quarantine `0x00680067` and `0x00690052` from `DeleteFromBlockListenInputPane` method ownership; they should be data/string fragments, not methods.
- Keep `0x004f2300` and `0x004f2310` owned by [InputPanes](by-file/InputPanes.md).

Impact:

- New [BlockListenInputPanes](by-file/BlockListenInputPanes.md), class docs, [FindBlockListEntry_5B74E0](by-global/FindBlockListEntry_5B74E0.md), and exact per-body memory docs record the safe ownership and caveats.
- 2026-05-26 recheck: IDA MCP reconfirmed `0x005b74e0` as a real helper with only add/delete block-list callers, and reconfirmed `0x00680067` / `0x00690052` as non-functions with data xrefs only. Added the two false generated method starts to [by-memory ignored ranges](by-memory/-ignored.md) as string/data-fragment artifacts; the raw constructor-shaped starts remain reconstructable project code and are not ignored.

Follow-up:

- Recheck generated output after Wave3 fixes for `0x005b68c0`, `0x005b6c80`, `0x005b7100`, `0x005b74e0`, `0x00680067`, and `0x00690052`; expected disposition for `0x00680067` and `0x00690052` is ignored/quarantined data-fragment metadata, not class methods.

2026-05-25 Wave3 tool follow-up:

- Live `show method 0x005b74e0 --summary` still reports unknown because Wave3 currently models the helper as `global:0x005b74e0`, not a method.
- Live `show global 0x005b74e0 --summary` reports `FindBlockedNameInRange_5B74E0`, owner file `FindBlockedNameInRange_005B74E0.cpp`, and resolved memory coverage `0x005b74e0-0x005b7552`. Remaining work is source-family ownership/naming, not missing memory coverage.

### 2026-05-24 - ProgressBarControlPane omits projected private helpers

Observed:

- Active `source-3/simroot_v2/class_ProgressBarControlPane.cpp` emits only `ProgressBarControlPane::ProgressBarControlPane` at `0x00494c80` and `DrawProgressBar` at `0x00494de0`.
- IDA MCP confirms real functions at `0x00494c80-0x00494daa` and `0x00494de0-0x00494eb0`, and confirms the constructor's direct caller at `0x005472d7` inside `PatchPane::PatchPane`.
- IDA MCP `lookup_funcs` currently reports `0x00494a90`, `0x00494af0`, and `0x00494db0` as `Not a function`, but raw disassembly shows function-shaped private helper code with `thiscall` field updates and `retn 4` or tail-dispatched invalidation.
- The helper code operates on the same `ProgressBarControlPane` fields used by the constructor and draw virtual: `0xf8`, `0xfa`, and `0xfc`.
- `class_ProgressBarControlPane.meta_wave3` reports `vtable_count: 0`, but IDA confirms vtable bases at `0x00617b34`, `0x00617b9c`, and `0x00617bcc`. The paint virtual is primary-table slot `+0x44` at `0x00617b78`.

Expected:

- Keep `0x00494a90`, `0x00494af0`, and `0x00494db0` grouped as projected private `ProgressBarControlPane` helpers or explicitly quarantine them as code-shaped non-function starts until IDA/Wave3 function ownership is repaired.
- Do not attach these helpers to [ControlPane](by-file/ControlPane.md), `RadioGroupControlPane`, or [ButtonControlPane](by-file/ButtonControlPane.md) simply because of address locality.

Impact:

- New [ProgressBarControlPane file](by-file/ProgressBarControlPane.md), [ProgressBarControlPane class](by-class/ProgressBarControlPane.md), and exact per-body memory docs record the safe ownership and caveats.
- Existing broad [ControlPane memory](by-memory/0x004949e0-0x00494bf6.ControlPane.md) and [Button/choice control memory](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md) docs now mark the progress-bar ranges as deliberate exclusions from those modules.
- 2026-05-26 recheck: IDA MCP still reports `0x00494a90`, `0x00494af0`, and `0x00494db0` as `Not a function`, with no direct xrefs. Keep these as projected private `ProgressBarControlPane` helper bytes and do not add them to ignored ranges; they are likely project code pending function-boundary repair.
- 2026-05-26 vtable follow-up: added [ProgressBarControlPane vtables](by-type/by-vtable/ProgressBarControlPaneVtables.md) to preserve the three table bases, constructor stores, and draw slot while generated metadata catches up.

Follow-up:

- Recheck generated output after Wave3 fixes for `0x00494a90`, `0x00494af0`, `0x00494db0`, and vtable inventory `0x00617b34`, `0x00617b9c`, and `0x00617bcc`; expected disposition is projected/private class helper coverage unless later disassembly contradicts it.

### 2026-05-24 - NumericStringControlPane and RectangleControlPane have small control-owner cleanup issues

Observed:

- Active `source-3/simroot_v2/class_NumericStringControlPane.cpp` emits the core methods at `0x00499910`, `0x004999d0`, `0x00499a50`, and `0x0049b2f0`; disabled metadata lists adjustor thunks `0x0049af7f` and `0x0049af8a`.
- IDA MCP confirms all six NumericString starts as real functions/thunks with end-exclusive boundaries `0x004999c1`, `0x00499a4e`, `0x00499be7`, `0x0049af95`, and `0x0049b3af`. Constructor callers are `0x00451143` and `0x004511d8` inside `MiniMapDialog::MiniMapDialog`.
- `class_NumericStringControlPane.meta_wave3` summary says "numeric string input validation", but the IDA/simroot body is a numeric glyph renderer, not input validation.
- Active `class_NumericStringControlPane.cpp` starts with an unused `ChattingColorPane` deleting-destructor typedef; this is owner/name pollution.
- `class_NumericStringControlPane.meta_wave3` reports `vtable_count: 0`, but IDA confirms vtable bases `0x00618390`, `0x006183f8`, and `0x00618428`; see [NumericStringControlPane and RectangleControlPane vtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md).
- Active `source-3/simroot_v2/class_RectangleControlPane.cpp` emits core methods at `0x00499c60`, `0x00499d00`, `0x0049b490`, and `0x0049b8f0`; disabled metadata lists adjustor thunks `0x0049afc1` and `0x0049afcc`.
- IDA MCP confirms all six Rectangle starts as real functions/thunks with end-exclusive boundaries `0x00499cd2`, `0x00499d37`, `0x0049afd7`, `0x0049b4e5`, and `0x0049b8f5`. Constructor caller is `0x0045252c` inside `MiniMapDialog::RenderSymbols`.
- Active `RectangleControlPane::ScalarDeletingDestructor` source references `TextButtonExControlPane::~TextButtonExControlPane`; IDA decompilation shows a generic base teardown helper, so this name should not be treated as button ownership.
- `class_RectangleControlPane.meta_wave3` reports `vtable_count: 0`, but IDA confirms vtable bases `0x00618434`, `0x0061849c`, and `0x006184cc`; see [NumericStringControlPane and RectangleControlPane vtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md).

Expected:

- Update `NumericStringControlPane` summary/metadata to describe fixed-width numeric glyph rendering.
- Remove the stray `ChattingColorPane` typedef from active NumericString output.
- Keep `0x0049af7f`, `0x0049af8a`, `0x0049afc1`, and `0x0049afcc` as confirmed compiler thunks, not missing code.
- Clean Rectangle destructor owner naming so it does not imply `TextButtonExControlPane` source ownership.

Recheck:

- 2026-05-26 IDA MCP `lookup_funcs`, `decompile`, `xrefs_to`, and `callers` confirm the four adjustor starts are real `0xb` functions but only compiler-generated `this` adjustors into scalar deleting destructors: NumericString `0x0049af7f -> 0x0049b2f0` after `this - 0xa0`, NumericString `0x0049af8a -> 0x0049b2f0` after `this - 0xa4`, Rectangle `0x0049afc1 -> 0x0049b490` after `this - 0xa0`, and Rectangle `0x0049afcc -> 0x0049b490` after `this - 0xa4`.
- Added the ranges `0x0049af7f-0x0049af95` and `0x0049afc1-0x0049afd7` to [by-memory ignored](by-memory/-ignored.md). Expected disposition is now source exclusion for the adjustor wrappers only; keep `0x0049b2f0-0x0049b3af` and `0x0049b490-0x0049b4e5` as reconstructable scalar deleting destructors.

Impact:

- New [NumericStringControlPane file](by-file/NumericStringControlPane.md), [RectangleControlPane file](by-file/RectangleControlPane.md), class docs, and exact per-body memory docs record safe UI-control ownership.
- New [NumericStringControlPane and RectangleControlPane vtable page](by-type/by-vtable/NumericRectangleControlPaneVtables.md) records IDA-confirmed table bases, key slots, constructor/destructor stores, and Wave3 `vtable_count: 0` caveats.
- [MiniMap](by-file/MiniMap.md) now records these classes as generic controls consumed by the minimap dialog, not minimap-owned classes.

Follow-up:

- Recheck generated output after Wave3 fixes for `NumericStringControlPane` summary cleanup, the stray `ChattingColorPane` typedef, and Rectangle destructor owner naming. The four adjustor thunk rows have been resolved as ignored compiler glue and should stay out of source-level reconstruction.

### 2026-05-24 - Target-selection input panes omit helpers/destructors and mark real thunks as missing

Observed:

- Active `source-3/simroot_v2/class_SelectObjectWithKeyboardPane.cpp` emits the constructor at `0x005af5f0`, key handler at `0x005af710`, mouse handler at `0x005afa10`, and scalar deleting destructor at `0x005b7bc0`.
- IDA MCP confirms additional real `SelectObjectWithKeyboardPane` functions at `0x005af6e0`, `0x005afc90`, `0x005afd30`, and `0x005afe70`. These are not emitted in the active generated file.
- Disabled `class_SelectObjectWithKeyboardPane.cpp` lists `0x005b786d` as missing code, but IDA confirms it is a real 0xb destructor adjustor thunk forwarding to `0x005b7bc0`.
- Active `source-3/simroot_v2/class_TargetObjectWithKeyboardPane.cpp` emits the constructor at `0x005afef0`, key handler at `0x005b0010`, mouse handler at `0x005b0290`, one adjustor thunk at `0x005b7912`, and scalar deleting destructor at `0x005b81d0`.
- IDA MCP confirms an additional real `TargetObjectWithKeyboardPane` non-deleting destructor at `0x005affe0`.
- Disabled `class_TargetObjectWithKeyboardPane.cpp` lists `0x005b791d` as missing code, but IDA confirms it is a real 0xb destructor adjustor thunk forwarding to `0x005b81d0`.
- `0x005af4f0` and `0x005af580` are real shared packet helpers called by item/spell/target flows, but no stable generated class owner is present in the active target-pane files.
- Generated one-method files `class_SpellInputPaneState.cpp` and `class_ItemWhoInputPaneState.cpp` are structurally useful, but their helpers are shared target/spell state helpers and should not drive one-file-per-helper source layout.

Expected:

- Attach or explicitly list `0x005af6e0`, `0x005afc90`, `0x005afd30`, and `0x005afe70` under `SelectObjectWithKeyboardPane`.
- Attach or explicitly list `0x005affe0` under `TargetObjectWithKeyboardPane`.
- Materialize `0x005b786d` and `0x005b791d` as confirmed compiler adjustor thunks instead of missing code.
- Represent `0x005af4f0` and `0x005af580` as shared packet helpers near the target-selection/input-pane family or a future protocol helper module.
- Keep `SpellInputPaneState::SetInputModeFlag` and `ItemWhoInputPaneState::SetInputModeFlag` grouped with shared target/spell input state rather than as standalone source files.

Recheck:

- 2026-05-26 IDA MCP confirms `0x005b7862`, `0x005b786d`, `0x005b7912`, and `0x005b791d` are real `0xb` destructor adjustor thunks. The first pair forwards to `0x005b7bc0`; the second pair forwards to `0x005b81d0`; offsets are `this - 0xa0` and `this - 0xa4` for each class.
- Added `0x005b7862-0x005b7878` and `0x005b7912-0x005b7928` to [by-memory ignored](by-memory/-ignored.md). Expected disposition is now source exclusion for those adjustor wrappers only; keep `0x005b7bc0-0x005b7c1f` and `0x005b81d0-0x005b822f` as reconstructable scalar deleting destructors.
- The same IDA pass reconfirmed real helper/function starts at `0x005af6e0`, `0x005afc90`, `0x005afd30`, `0x005afe70`, `0x005affe0`, `0x005af4f0`, and `0x005af580`; keep those documented under [TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md).

Impact:

- New [TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md), [SelectObjectWithKeyboardPane](by-class/SelectObjectWithKeyboardPane.md), [TargetObjectWithKeyboardPane](by-class/TargetObjectWithKeyboardPane.md), [SpellInputPaneState](by-class/SpellInputPaneState.md), [ItemWhoInputPaneState](by-class/ItemWhoInputPaneState.md), and exact memory docs record the safe ownership and caveats.
- 2026-05-25 follow-up: exact per-body pages now exist for the `0x005af390-0x005b050d` target-selection cluster and the `0x005b7862`/`0x005b7bc0`/`0x005b7912`/`0x005b81d0` destructor-thunk islands. The broad target-selection memory page is now a grouping index, not the canonical range source.
- [ItemActionInputPanes](by-file/ItemActionInputPanes.md) now treats `ItemWhoInputPane` as a cross-referenced target-input class, not conclusively part of direct item-command input code.

Follow-up:

- Recheck generated output after Wave3 fixes for `0x005af6e0`, `0x005afc90`, `0x005afd30`, `0x005afe70`, `0x005affe0`, `0x005af4f0`, and `0x005af580`. The `0x005b786d` and `0x005b791d` rows have been resolved as ignored compiler glue and should stay out of source-level reconstruction.

### 2026-05-24 - SpellWhoInputPane generated output omits real helper/destructor functions

Observed:

- Active `source-3/simroot_v2/class_SpellWhoInputPane.cpp` emits the constructor at `0x005ae2a0`, key handler at `0x005ae410`, pointer handler at `0x005ae730`, and scalar deleting destructor at `0x005b8100`.
- IDA MCP confirms additional real `SpellWhoInputPane` functions at `0x005ae380` and `0x005aea60`. These are not emitted in the active generated class file.
- `0x005ae380` is a non-deleting destructor that resets `SpellWhoInputPane` vtables, clears the active target input-state helper through `0x0057d0a0` or `0x0057c430`, and calls shared line-input cleanup.
- `0x005aea60` is a vtable helper that parses underscore-prefixed object-id payloads and falls back to the local player when the saved spell target disappears.
- Recovered global `source-3/simroot_v2/recovered/DeactivateSavedSpellWhoTarget_005AEB00.cpp` emits `0x005aeb00`; IDA caller evidence ties it directly to `SpellWhoInputPane` key/pointer handlers.
- Disabled `class_SpellWhoInputPane.cpp` lists `0x005b7907` as missing code, but IDA confirms it is a real 0xb destructor adjustor thunk forwarding to `0x005b8100`.
- Active `class_SpellWhoInputPane.cpp` starts with a `BackGroundPane` deleting-destructor typedef and the active scalar destructor uses generic base cleanup naming; these should not imply source ownership outside `SpellWhoInputPane`/input-pane base cleanup.

Expected:

- Attach or explicitly list `0x005ae380` and `0x005aea60` under `SpellWhoInputPane`.
- Treat `0x005aeb00` as a tiny helper local to [SpellWhoInputPane](by-class/SpellWhoInputPane.md) / [TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md), not as evidence for a standalone original source file.
- Materialize `0x005b7907` as a confirmed compiler adjustor thunk instead of missing code.
- Clean stray `BackGroundPane`/generic destructor typedef naming from the emitted source if the generator can do so safely.

Recheck:

- 2026-05-26 IDA MCP confirms `0x005b78fc` and `0x005b7907` are real `0xb` destructor adjustor thunks forwarding to `0x005b8100` after `this - 0xa0` and `this - 0xa4`.
- Added `0x005b78fc-0x005b7912` to [by-memory ignored](by-memory/-ignored.md). Expected disposition is source exclusion for the adjustor wrappers only; keep `0x005b8100-0x005b81c4` as a reconstructable scalar deleting destructor.
- The same IDA pass reconfirmed real function starts at `0x005ae380`, `0x005aea60`, and `0x005aeb00`; keep them documented under [SpellWhoInputPane](by-class/SpellWhoInputPane.md) and [TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md).

Impact:

- New [SpellWhoInputPane](by-class/SpellWhoInputPane.md) and [SpellWhoInputPane memory](by-memory/0x005ae2a0-0x005aeb1f.SpellWhoInputPane.md) docs record the safe ownership and exact boundaries.
- 2026-05-25 follow-up: exact per-body pages now exist for the spell target constructor, destructor, keyboard handler, pointer handler, object-list virtual, local deactivate helper, adjustor thunks, and scalar deleting destructor. The broad `SpellWhoInputPane` memory page is now a grouping index.
- [TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md) and the proposed source tree now include the spell-side target-selection pane alongside item/object target selectors.

Follow-up:

- Recheck generated output after Wave3 fixes for `0x005ae380`, `0x005aea60`, `0x005aeb00`, and destructor/base-name pollution in `class_SpellWhoInputPane.cpp`. The `0x005b7907` row has been resolved as ignored compiler glue and should stay out of source-level reconstruction.

### 2026-05-24 - Spell input panes have owner pollution, projected constructor, and missing-code thunk rows

Observed:

- Active `source-3/simroot_v2/class_SpellOneArgInputPane.cpp` includes [GeneralPurposePanel](by-file/GeneralPurposePanel.md) child/tab helpers at `0x004b85f0`, `0x004b8620`, `0x004b8630`, and `0x004b8650`; existing docs and IDA evidence show these are panel helpers, not spell input class methods.
- Active `class_SpellOneArgInputPane.cpp` emits `SpellOneArgInputPane::__wtol` at `0x005cea43`, but IDA identifies the function as `unknown_libname_24` / CRT `__wtol` and `xrefs_to` shows broad runtime/library fanout outside spell input code.
- Disabled generated spell input files mark second destructor adjustor thunks as missing code: `0x005b7883`, `0x005b7899`, `0x005b78af`, `0x005b78c5`, `0x005b78db`, and `0x005b78f1`. IDA confirms all six are real 0xb thunks forwarding to the relevant scalar deleting destructor with `this - 41`.
- 2026-05-25 follow-up: exact [0x005b7878-0x005b78fc](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md) docs now cover all paired string/numeric/slot spell-input adjustor thunks and the six disabled `missing code` rows.
- Active `source-3/simroot_v2/class_ChangeSpellSlotInputPane.cpp` emits a constructor at `0x005b3220`; IDA `lookup_funcs` says it is not a function, but IDA disassembly confirms a constructor-shaped body ending at `0x005b325f`.
- Generated destructor bodies across the numeric/string/slot spell input panes call base cleanup through names like `TakeOffInputPane::~TakeOffInputPane`; treat this as base-helper naming pollution, not source ownership.

Expected:

- Keep `0x004b85f0`, `0x004b8620`, `0x004b8630`, and `0x004b8650` owned by [GeneralPurposePanel](by-file/GeneralPurposePanel.md).
- Exclude or runtime-classify `0x005cea43` rather than emitting it as `SpellOneArgInputPane::__wtol`.
- Materialize the six second adjustor thunks as confirmed compiler thunks rather than missing code.
- Preserve the `0x005b3220-0x005b325f` raw constructor bytes for `ChangeSpellSlotInputPane` despite the current IDA function-table gap.
- Clean destructor/base-helper names so they do not imply item-input ownership.

Recheck:

- 2026-05-26 IDA MCP confirms `0x005cea43-0x005cea6d` as `unknown_libname_24` / Microsoft Visual C runtime `__wtol`, with decompilation through `__crt_strtox::parse_integer` and broad caller fanout. Added [CRT wtol wrapper](by-memory/0x005cea43-0x005cea6d.CrtWtolWrapper.md) and [by-memory ignored](by-memory/-ignored.md) entries; this should not be emitted as a `SpellOneArgInputPane` method.
- 2026-05-26 IDA MCP reconfirmed all twelve spell argument adjustor starts in `0x005b7878-0x005b78fc` as real `0xb` vtable thunks. The disabled `missing code` starts `0x005b7883`, `0x005b7899`, `0x005b78af`, `0x005b78c5`, `0x005b78db`, and `0x005b78f1` are the second `this - 0xa4` thunk in each class pair.
- Added `0x005b7878-0x005b78fc` to [by-memory ignored](by-memory/-ignored.md). Expected disposition is source exclusion for adjustor wrappers only; keep the scalar deleting destructors at `0x005b7c20`, `0x005b7cf0`, `0x005b7dc0`, `0x005b7e90`, `0x005b7f60`, and `0x005b8030` reconstructable.
- IDA MCP still reports `0x005b3220` as `Not a function`, so keep [ChangeSpellSlotInputPane raw constructor](by-memory/0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor.md) as raw/projected constructor bytes rather than ignoring it.
- IDA MCP caller recheck still shows broad callers for `0x004b85f0`, `0x004b8620`, `0x004b8630`, and `0x004b8650`; keep them owned by [GeneralPurposePanel](by-file/GeneralPurposePanel.md), not `SpellOneArgInputPane`.

Impact:

- New [SpellInputPanes](by-file/SpellInputPanes.md), class docs, [SpellStringInputPane memory](by-memory/0x005adf40-0x005ae1a4.SpellStringInputPane.md), [spell argument input memory](by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md), and [ChangeSpellSlotInputPane memory](by-memory/0x005b3220-0x005b340e.ChangeSpellSlotInputPane.md) record safe source grouping and boundaries.
- Added [SpellInputPane adjustor thunk island](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md) so those rows are preserved as reviewed compiler/vtable support rather than unresolved missing code.
- 2026-05-25 follow-up: exact per-body pages now exist for each numeric/slot spell argument constructor, submit handler, and scalar deleting destructor; the broad spell argument memory page is now a grouping index.
- 2026-05-25 follow-up: exact per-body pages now also exist for the shared spell prompt helper, `SpellStringInputPane` constructor/confirm handler, and its scalar deleting destructor; the broad string pane memory page is now a grouping index.
- 2026-05-25 follow-up: exact per-body pages now also exist for the `ChangeSpellSlotInputPane` raw constructor/key/submit bodies and `SpellSpellInputPane` constructor/key/accept bodies.

Follow-up:

- Recheck generated output after Wave3 fixes for GeneralPurposePanel helper ownership, `0x005cea43`, `0x005b3220`, and destructor/base-helper name pollution. The six missing-code adjustor rows have been resolved as ignored compiler glue and should stay out of source-level reconstruction.

### 2026-05-24 - User create appearance controls have generic brush-helper ownership and missing-code thunk rows

Observed:

- Active `source-3/simroot_v2/class_UserHairColorSelectListPane.cpp` emits `GetBrushHandle` at `0x004b96a0` and `SetBrushHandle` at `0x004b96b0` as `UserHairColorSelectListPane` methods.
- IDA MCP `xrefs_to 0x004b96a0` and `0x004b96b0` reports callers outside the hair-color list, including `0x00467b30` and `0x004836a0`, plus the face/hair color draw methods. This looks like generic pane/draw-context brush state, not hair-color-list ownership.
- Disabled generated files mark several real 0xb adjustor thunks as missing code: `UserCreatePreviewControlPane` `0x005025b3`, `UserFaceSelectControlPane` `0x005025c9`, `UserHairSelectControlPane` `0x005025df`, `UserShapeSelectControlPane` `0x005025f5`, and `UserInfoDialogPane` `0x0059bc2d`.
- IDA MCP confirms the above thunk addresses as real functions.

Expected:

- Re-own or neutralize `0x004b96a0` and `0x004b96b0` as generic pane/drawing helpers unless a later pass proves they are intentionally class-local.
- Materialize the missing-code thunk rows as compiler adjustor thunks rather than unresolved bodies.
- Keep the old create-user appearance controls grouped through [UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md) and exact memory docs until ownership is cleaned.

Recheck:

- 2026-05-26 IDA MCP reconfirmed `0x004b96a0` and `0x004b96b0` as real draw-state helpers with broad callers outside `UserHairColorSelectListPane`; keep them under [DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md) / [GrafPort](by-file/GrafPort.md), not hair-color-list ownership.
- 2026-05-26 IDA MCP confirms `0x005025a8-0x005025ff` and `0x0059bc2d-0x0059bc43` are real `0xb` destructor adjustor thunk ranges. The disabled missing-code starts are second thunks forwarding after `this - 0xa4`; the first thunks forward after `this - 0xa0`.
- Added `0x005025a8-0x005025ff` and `0x0059bc2d-0x0059bc43` to [by-memory ignored](by-memory/-ignored.md). Expected disposition is source exclusion for adjustor wrappers only; keep the target scalar deleting destructors reconstructable.

Impact:

- New [UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md), [UserInfoDialogPane](by-file/UserInfoDialogPane.md), class pages, and exact memory pages document safe source grouping and the caveats.
- 2026-05-25: Added exact range docs for [draw-context brush helpers](by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md), [create-user appearance adjustor thunks](by-memory/0x005025a8-0x005025ff.UserCreateAppearanceAdjustorThunks.md), and [UserInfoDialogPane adjustor thunks](by-memory/0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks.md). IDA MCP reconfirmed all listed helper/thunk starts and broad brush-helper callers.

Follow-up:

- Recheck generated output after Wave3 fixes for `0x004b96a0` and `0x004b96b0` owner classification. The listed missing-code thunk rows have been resolved as ignored compiler glue and should stay out of source-level reconstruction.

### 2026-05-24 - EditablePaperPane and TextPad have helper/thunk ownership gaps

Observed:

- Disabled `source-3/simroot_v2/class_EditablePaperPane.cpp` emits `0x0045004e` as `EditablePaperPane::virt_meth_0x45004e`, but IDA places the address inside the real function `0x00450030-0x0045007b`, a generic binary-search/lower-bound helper. IDA callers at `0x0044ceb2` and `0x0044ced0` are not paper-specific.
- Disabled `class_EditablePaperPane.cpp` lists `0x00545ddd` as missing code and emits `0x00545de8` as a thunk. IDA confirms both `0x00545ddd` and `0x00545de8` are real 0xb destructor adjustor thunks forwarding to `0x00545e00`.
- Active `source-3/simroot_v2/class_TextPad.cpp` calls `TextPad_SendText(this, textBuffer)`, but the real helper body at `0x00595be0-0x00595f26` is not emitted in the active file or class method list. IDA confirms the helper is called only from `TextPad::OnKeyInput`.
- IDA disassembly for `0x00595be0` shows command prefixes `Open `, `Save `, `SetFont `, and `SetColor ` with local file I/O and text formatting behavior.

Expected:

- Re-own or neutralize `0x00450030-0x0045007b` as a generic helper instead of attaching the interior address `0x0045004e` to `EditablePaperPane`.
- Materialize `0x00545ddd` and `0x00545de8` as compiler adjustor thunks rather than missing/unresolved methods.
- Attach or explicitly list `0x00595be0-0x00595f26` as a private `TextPad` command helper.

Recheck:

- 2026-05-26 IDA MCP reconfirmed `0x0045004e` maps inside the real `0x00450030-0x0045007b` LodePNG lower-bound helper. The broad LodePNG ignored range already covers it; keep the false `EditablePaperPane` method row out of project reconstruction.
- 2026-05-26 IDA MCP confirms `0x00545ddd` and `0x00545de8` are real `0xb` destructor adjustor thunks forwarding to `0x00545e00` after `this - 0xa0` and `this - 0xa4`. Added `0x00545ddd-0x00545df3` to [by-memory ignored](by-memory/-ignored.md); keep `0x00545e00-0x00545e3b` reconstructable.
- 2026-05-26 vtable follow-up: added [EditablePaperPane vtables](by-type/by-vtable/EditablePaperPaneVtables.md). IDA confirms constructor writes to `0x00621afc`, `0x00621b60`, and `0x00621b90`; the tertiary table stops before `0x00621b98`, where adjacent `LINE001.EPD` string/data begins. The address-like `0x0045004e` value appears in that adjacent data, not in the paper-pane vtable.
- 2026-05-26 IDA MCP confirms `0x00595be0-0x00595f26` has a single direct caller, `0x00595b64` inside `TextPad::OnKeyInput`; keep it as private [TextPad command helper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md), not ignored.

Impact:

- New [EditablePaperPane](by-file/EditablePaperPane.md), [TextPad](by-file/TextPad.md), class pages, and exact memory pages document the safe ownership and generated-data caveats.
- 2026-05-25: Added exact range docs for [LodePNG lower-bound helper](by-memory/0x00450030-0x0045007b.LodePngLowerBoundHelper.md), [EditablePaperPane adjustor thunks](by-memory/0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md), and [TextPad command helper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md). IDA MCP reconfirmed the `0x0045004e` interior mapping, the thunk adjustments, and the single `TextPad::OnKeyInput` caller.

Follow-up:

- Recheck generated output after Wave3 fixes for `0x0045004e`, `0x00450030`, and `0x00595be0` ownership. The `0x00545ddd` and `0x00545de8` rows have been resolved as ignored compiler glue and should stay out of source-level reconstruction.

### 2026-05-24 - NumberInputDialog has destructor/thunk and resource-string data issues

Observed:

- Active `source-3/simroot_v2/class_NumberInputDialog.cpp` emits an ordinary destructor at `0x00530b00`, but IDA `lookup_funcs 0x00530b00` reports no function. IDA disassembly still confirms real destructor-shaped bytes at end-exclusive range `0x00530b00-0x00530b35`.
- Disabled `source-3/simroot_v2/class_NumberInputDialog.cpp.disabled` emits `0x00530c78` as an adjustor thunk with `this - 0x1dc`, but IDA decompiles it as a real 0xb thunk forwarding to `0x00530c90` with `this - 160`.
- The same disabled file lists `0x00530c83` as missing code. IDA confirms it is a real 0xb destructor adjustor thunk forwarding to `0x00530c90` with `this - 164`.
- Active generated constructor text prints the older EPD palette as `L"NP"`, but IDA string bytes at symbol `aNp` decode to `NPAL8.PAL`.

Expected:

- Preserve `0x00530b00-0x00530b35` as the ordinary `NumberInputDialog` destructor body even while the IDA function-table gap exists.
- Fix/generated-materialize both destructor adjustor thunks at `0x00530c78` and `0x00530c83` with the correct `this - 160` and `this - 164` adjustments.
- Use `NPAL8.PAL` for the EPD layout resource evidence unless a later binary check proves a different runtime string path.

Recheck:

- 2026-05-26 IDA MCP still reports `0x00530b00` as `Not a function` and `0x00530b40` as the next real function. Keep [raw destructor bytes](by-memory/0x00530b00-0x00530b35.NumberInputDialogRawDestructor.md) as reconstructable raw/projected destructor code.
- 2026-05-26 IDA MCP confirms `0x00530c78` and `0x00530c83` are real `0xb` destructor adjustor thunks forwarding to `0x00530c90` after `this - 0xa0` and `this - 0xa4`. Added `0x00530c78-0x00530c8e` to [by-memory ignored](by-memory/-ignored.md); keep `0x00530c90-0x00530cf7` reconstructable.
- 2026-05-26 IDA MCP reconfirmed constructor data xrefs for `NPAL8.PAL` at `0x005308eb` and `DLGEXC3.EPD` at `0x005308f8` / `0x00530a79`; keep the generated `L"NP"` text treated as a resource decoding issue.

Impact:

- New [NumberInputDialog](by-file/NumberInputDialog.md), [NumberInputDialog class](by-class/NumberInputDialog.md), and [NumberInputDialog memory](by-memory/0x00530640-0x00530cf7.NumberInputDialog.md) docs record the safe ownership and generated-data caveats.
- 2026-05-25: Added exact docs for [raw destructor bytes](by-memory/0x00530b00-0x00530b35.NumberInputDialogRawDestructor.md), [adjustor thunks](by-memory/0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks.md), and [NumberInputDialog resources](by-resource/number-input-dialog-resources.md). IDA MCP reconfirmed the missing function-table row, thunk adjustments, and `aNp` UTF-16 `NPAL8.PAL` string with constructor xref `0x005308eb`.
- 2026-05-25 follow-up: added exact per-body pages for the constructor, action handler, and scalar deleting destructor; the broad `0x00530640-0x00530cf7` page is now an index.

Follow-up:

- Recheck generated output after Wave3 fixes for `0x00530b00` function-table/import handling and the `DLGEXC3.EPD` palette string. The two adjustor thunk rows have been resolved as ignored compiler glue and should stay out of source-level reconstruction.

### 2026-05-24 - PursuitMessageDialogPane has raw constructor and shared destructor glue ownership

Observed:

- Active `source-3/simroot_v2/class_PursuitMessageDialogPane.cpp` emits constructor `0x0054cab0`, but IDA `lookup_funcs 0x0054cab0` reports no function. IDA disassembly still confirms a constructor-shaped body from `0x0054cab0-0x0054cae8` that calls `DialogPane::DialogPane(L"", 1, 1)` and installs three `PursuitMessageDialogPane` vtables.
- Disabled `class_PursuitMessageDialogPane.cpp.disabled` lists `0x00520aa5` as missing code. IDA confirms it is a real 0xb this-adjustor thunk forwarding to `0x00520b70` with `this - 160`.
- The same disabled file emits `0x00520ab0` as a class-specific adjustor thunk. IDA confirms the thunk body, but `xrefs_to` shows broad vtable data refs across many dialog classes, so ownership should be neutral/shared rather than uniquely `PursuitMessageDialogPane`.
- Active output emits scalar deleting destructor `0x00520b70` under `PursuitMessageDialogPane`, but IDA `xrefs_to` reports broad vtable refs and no unique vtable reset in the decompiled body. This looks like shared default dialog destructor glue.
- `class_PursuitMessageDialogPane.meta_wave3` reports `vtable_count: 0` even though IDA confirms vtable bases `0x00622428`, `0x00622488`, and `0x006224b8`, with raw constructor stores at `0x0054cac8`, `0x0054cad0`, and `0x0054cada`.
- IDA confirms `0x0054caf0-0x0054cc2f` as a real vtable-referenced message-dialog response handler, but current active `simroot_v2` output does not emit the body under `PursuitMessageDialogPane` or sibling message-dialog sources.

Expected:

- Preserve raw constructor bytes at `0x0054cab0-0x0054cae9` as `PursuitMessageDialogPane` while noting the IDA function-table gap.
- Restore/generated vtable inventory should include bases `0x00622428`, `0x00622488`, and `0x006224b8`.
- Preserve `0x0054caf0-0x0054cc2f` as shared [MessageDialogs](by-file/MessageDialogs.md) project behavior rather than dropping it from active output.
- Materialize both `0x00520aa5` and `0x00520ab0` as real shared/default destructor adjustor thunks.
- Keep `0x00520b70-0x00520bab` as a shared default scalar deleting destructor instead of assigning exclusive class ownership from one vtable ref.

Recheck:

- 2026-05-26 IDA MCP still reports `0x0054cab0` as `Not a function`, `0x0054caf0` as the next real function, and no direct xrefs to the raw constructor. Keep [PursuitMessageDialogPane constructor](by-memory/0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor.md) reconstructable as raw/projected code.
- 2026-05-26 IDA MCP vtable pass confirms `0x00622428`, `0x00622488`, and `0x006224b8`; current metadata still reports `vtable_count: 0`.
- 2026-05-26 IDA MCP confirms `0x0054caf0` is a real size-`0x13f` function with vtable data refs at `0x00622498`, `0x00622534`, `0x006225d0`, `0x0062266c`, `0x00622708`, `0x0062292c`, `0x006229c8`, and `0x00622cc8`.
- 2026-05-26 IDA MCP confirms `0x00520aa5` and `0x00520ab0` are real `0xb` shared adjustor thunks forwarding to `0x00520b70` after `this - 0xa0` and `this - 0xa4`, with broad vtable refs across multiple dialog classes.
- 2026-05-26 IDA MCP confirms `0x00520b70-0x00520bab` remains a shared default scalar deleting destructor with no unique class vtable reset and broad vtable refs. Added `0x00520aa5-0x00520abb` and `0x00520b70-0x00520bab` to [by-memory ignored](by-memory/-ignored.md).

Impact:

- New [PursuitMessageDialogPane](by-class/PursuitMessageDialogPane.md), [constructor memory](by-memory/0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor.md), [PursuitMessageDialogPane vtables](by-type/by-vtable/PursuitMessageDialogPaneVtables.md), [message-dialog response virtual](by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md), [shared thunk memory](by-memory/0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks.md), and [shared scalar destructor memory](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md) docs record the safe ownership and caveats.
- 2026-05-25: IDA MCP recheck reconfirmed the raw constructor gap at `0x0054cab0`, the next function at `0x0054caf0`, no direct constructor xrefs, shared thunk adjustments `this - 160` and `this - 164`, and broad vtable refs for the shared destructor glue.

Follow-up:

- Recheck generated output after Wave3 fixes for `0x0054cab0` function-table/import handling, `0x0054caf0` body emission, vtable inventory, and shared ownership naming. The `0x00520aa5`, `0x00520ab0`, and `0x00520b70` rows have been resolved as ignored shared compiler glue and should stay out of source-level reconstruction.

### 2026-05-24 - StdioFile active output omits real vtable methods and has an unresolved stat-size placeholder

Observed:

- Active `source-3/simroot_v2/class_StdioFile.cpp` omits real `StdioFile` virtual methods that are present only in `class_StdioFile.cpp.disabled`: `GetSize` at `0x004f5ad0`, `GetPosition` at `0x00582200`, `Seek` at `0x00582210`, and `Read` at `0x00582230`.
- IDA vtable data at `0x0062d5ac` confirms those disabled methods are live `StdioFile` virtual slots.
- Active `StdioFile::Open` at `0x005820d0` contains the placeholder `statBuffer_size`; IDA decompilation shows the stored value is the file-size field from the local `_wstat` buffer copied into object offset `+8`.

Expected:

- Materialize the four disabled `StdioFile` vtable methods into the active class output.
- Replace `statBuffer_size` with the correct stat-buffer field expression/name when the structure is modeled.
- Keep the adjacent [PathExistsViaStat](by-item/PathExistsViaStat_00582460.md) helper as a recovered/global utility or assign it to the final file I/O module, not to a caller-specific class.

Recheck:

- 2026-05-26 IDA MCP reconfirmed real function boundaries for `0x004f5ad0`, `0x005820d0`, `0x00582200`, `0x00582210`, `0x00582230`, `0x00582460`, and `0x005824a0`.
- `GetSize`, `GetPosition`, `Seek`, and `Read` are still live `StdioFile` virtuals. `GetPosition` and `Seek` show vtable-only refs, while `Read` also has direct callers at `0x00504cc8`, `0x00504cfb`, and `0x00504d0f`.
- `StdioFile::Open` still copies the local `_wstat` size field into `this[2]`; generated `statBuffer_size` is a placeholder/name issue, not a separate global.
- `PathExistsViaStat` remains a shared utility with callers from startup/logo, application startup, map loading, and the Miles AIL file-open callback. No ignored-ledger change is needed because these are reconstructable project functions.

Impact:

- New [FileIO](by-file/FileIO.md), [File](by-class/File.md), [StdioFile](by-class/StdioFile.md), [StdioFile memory](by-memory/0x00582070-0x005824f6.StdioFile.md), [StdioFile GetSize memory](by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md), and [PathExistsViaStat memory](by-memory/0x00582460-0x00582495.PathExistsViaStat.md) docs record safe ownership and generated-data caveats.
- 2026-05-25: Added exact docs for [StdioFile::Open](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md) and [StdioFile virtual position/read methods](by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md). IDA MCP recheck confirmed vtable slots at `0x0062d5c0`, `0x0062d5c4`, `0x0062d5c8`, and `0x0062d5cc`, and confirmed `Open` copies the stat-buffer size dword into object offset `+8`.
- 2026-05-25 follow-up: promoted the remaining main-island methods to exact pages for constructor, destructor, close, line reads, read-remaining, and scalar deleting destructor; corrected end-exclusive filenames for `Open`, `GetSize`, virtual position/read methods, `PathExistsViaStat`, and the main `StdioFile` index.

Follow-up:

- Recheck generated output after Wave3 fixes for `0x004f5ad0`, `0x005820d0`, `0x00582200`, `0x00582210`, `0x00582230`, and the `StdioFile` vtable at `0x0062d5ac`; expected disposition is materialized project code, not ignored/runtime code.

### 2026-05-24 - Encoder/Decoder output omits codec vtable slots and the raw Decoder reader family

Observed:

- Active `source-3/simroot_v2/class_Encoder.cpp` emits the constructor/writer/finalize/destructor methods, but omits the real `Encoder` no-op virtual at `0x004a5630`. IDA vtable data at `0x006192cc` confirms the slot.
- Active `source-3/simroot_v2/class_Decoder.cpp` emits only scalar deleting destructor `0x004a5e00`; disabled output emits only no-op virtual `0x004a5df0`.
- Current `class_Encoder.meta_wave3` and `class_Decoder.meta_wave3` both report `vtable_count: 0`, even though IDA confirms two-slot vtables at `0x006192cc` and `0x006192d8`.
- IDA decompiles real Decoder-shaped modeled functions at `0x004a5640` (constructor), `0x004a5670` (ordinary destructor), and `0x004a5dd0` (reset/finalize), none of which appear in the active generated class.
- IDA disassembly shows aligned raw Decoder reader starts at `0x004a5680`, `0x004a5690`, `0x004a56c0`, `0x004a5710`, `0x004a5770`, `0x004a57e0`, `0x004a5870`, `0x004a5930`, `0x004a5a40`, `0x004a5bb0`, `0x004a5c80`, `0x004a5cd0`, `0x004a5d80`, and `0x004a5db0`, but IDA currently does not model those starts as functions and xref checks found no direct callers.
- `class_Decoder.meta_wave3` reports a 4-byte class layout, but the constructor, initializer, reset/finalizer, and raw reader code use the same 18-byte buffer/cursor/flags layout as `Encoder`.
- IDA confirms `0x0058e490-0x0058e690` as the only direct caller of the active `Encoder` write family. The helper serializes text-edit table buffers, but current generated output does not cleanly materialize it as a text-edit helper.

Expected:

- Emit or explicitly account for `Encoder` no-op virtual `0x004a5630`.
- Attach or explicitly account for Decoder constructor/destructor/reset/finalize starts `0x004a5640`, `0x004a5670`, and `0x004a5dd0`.
- Model the raw Decoder reader family in `0x004a5680-0x004a5db0`, or quarantine it with clear "raw code start / no formal function" status until function recovery improves.
- Correct `Decoder` layout metadata to reflect the stream cursor fields rather than a 4-byte minimal base.
- Attach `0x0058e490` to [TextEditPane](by-file/TextEditPane.md) or a text-edit control wrapper, not to `Encoder` or an unrelated generated owner.

Impact:

- New [BinaryCodec](by-file/BinaryCodec.md), [Encoder](by-class/Encoder.md), [Decoder](by-class/Decoder.md), exact memory docs, and [EncodeTextEditState](by-item/EncodeTextEditState_0058E490.md) record the safe ownership and caveats.
- Do not migrate active `class_Decoder.cpp` directly; it is missing nearly all observed reader behavior.
- 2026-05-25: IDA MCP recheck reconfirmed modeled functions at `0x004a5630`, `0x004a5640`, `0x004a5670`, `0x004a5dd0`, `0x004a5df0`, `0x004a5e00`, `0x004a5e30`, and `0x0058e490`; every raw Decoder reader start remains `Not a function` with empty xrefs. Added [Decoder raw reader family](by-memory/0x004a5680-0x004a5dce.DecoderRawReaderFamily.md) for the missing raw code family.
- 2026-05-25 follow-up: promoted the modeled Encoder writer methods and Encoder/Decoder vtable glue to exact per-body pages, corrected end-exclusive index filenames to [Encoder core](by-memory/0x004a4e70-0x004a5621.EncoderCore.md) and [Decoder/codecs vtable glue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md).
- 2026-05-26: IDA MCP recheck again found the same modeled function set and the same raw Decoder `Not a function` starts. The raw Decoder starts still have empty `xrefs_to`, but remain reconstructable project code with missing function-boundary data, not ignored ranges. Encoder writer/finalize methods still report direct callers only inside `0x0058e490`; that helper still has one raw thunk xref at `0x00498c4a` and no formal modeled caller.
- 2026-05-26 follow-up: added [Decoder primitive readers](by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md) for exact raw disassembly of `0x004a5680`, `0x004a5690`, `0x004a56c0`, `0x004a5710`, and `0x004a5770`. IDA still reports these starts as `Not a function` with empty xrefs.
- 2026-05-26 follow-up: added [Decoder string/blob readers](by-memory/0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders.md) for exact raw disassembly of `0x004a57e0`, `0x004a5870`, `0x004a5930`, `0x004a5a40`, `0x004a5bb0`, `0x004a5c80`, `0x004a5cd0`, `0x004a5d80`, and `0x004a5db0`. IDA still reports these starts as `Not a function` with empty xrefs.
- 2026-05-26 follow-up: added [BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md) for vtables `0x006192cc` and `0x006192d8`, plus [BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md) for the shared cursor fields through `+0x11`. IDA xrefs confirm vtable refs only from constructors/destructors/scalar destructors.

Follow-up:

- Recheck generated output after Wave3 fixes for vtables `0x006192cc`/`0x006192d8`, `0x004a5630`, `0x004a5640`, `0x004a5670`, `0x004a5680`, `0x004a5690`, `0x004a56c0`, `0x004a5710`, `0x004a5770`, `0x004a57e0`, `0x004a5870`, `0x004a5930`, `0x004a5a40`, `0x004a5bb0`, `0x004a5c80`, `0x004a5cd0`, `0x004a5d80`, `0x004a5db0`, `0x004a5dd0`, `0x004a5df0`, `0x004a5e00`, `0x004a5e30`, and `0x0058e490`.

### 2026-05-24 - ThreadMan simroot output has improved coverage but still has stale rows and low-fidelity message-loop modeling

Observed:

- Current `source-3/simroot_v2/class_ThreadMan.cpp` emits `ThreadMan::ThreadMan`, `RunMessagePump`, `ScalarDeletingDestructor`, global `ThreadManWorkerEntry`, and global `ClearThreadManSingleton_5974E0`.
- IDA confirms the worker loop at `0x00596e10` handles real Win32 messages `0x0464-0x0468` through `PeekMessage` and mutates 20-byte watchdog records in a `List(20, 16)`.
- 2026-05-25 recheck: IDA raw disassembly shows omitted ThreadMan helpers at `0x00596d20-0x00596e0b`: a non-deleting destructor plus `PostThreadMessageW` wrappers for messages `0x0464-0x0468`. `lookup_funcs` reports those starts as `Not a function` and `xrefs_to` currently finds no direct callers.
- The emitted `RunMessagePump` has a very low score and replaces the concrete message-loop logic with fake helper declarations such as `PollThreadManMessage` and `DispatchThreadManTask`.
- The emitted `ThreadManWorkerEntry` contains an omitted placeholder line in the `catch (...)` region; IDA callers/callees show exception handling that can format an error, show `MessageBoxW`, and request application exit.
- `class_ThreadMan.cpp.disabled` still contains stale rows for `0x0045004b` and `0x004e0052`. IDA shows `0x0045004b` is inside a small array/binary-search helper at `0x00450030`, while `0x004e0052` is inside `NewHumanImageLib::NewHumanImageLib` at `0x004dfd10`.
- `0x00597570` is adjacent but not ThreadMan; IDA decompilation installs `TimerHandler::vftable`, matching the timer scheduler docs.

Expected:

- Keep `0x00596bf0-0x0059756e` under `ThreadMan`/`util/Thread.cpp`.
- Account for raw starts `0x00596d20`, `0x00596d70`, `0x00596d90`, `0x00596db0`, `0x00596dd0`, and `0x00596df0` under ThreadMan, or explicitly preserve them as raw helper starts until function recovery improves.
- Model `0x00596e10` using the Win32 message ids and the 20-byte watchdog record layout, not the fake helper declarations from generated output.
- Keep `0x00597100` as a ThreadMan-local `CreateThread` entry helper, but re-check the exception region before migration.
- Leave `0x0045004b`, `0x004e0052`, and `0x00597570` out of ThreadMan ownership.

Impact:

- Added [ThreadMan worker loop](by-memory/0x00596e10-0x005970df.ThreadManWorkerLoop.md), [ThreadMan worker entry](by-memory/0x00597100-0x005971ad.ThreadManWorkerEntry.md), [ThreadManLayout](by-type/by-struct/ThreadManLayout.md), [ThreadManWatchRecord](by-type/by-struct/ThreadManWatchRecord.md), and [ThreadManMessageId](by-type/by-enum/ThreadManMessageId.md).
- Updated [Thread](by-file/Thread.md), [ThreadMan](by-class/ThreadMan.md), [Thread/ThreadMan memory](by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md), and [client threading](by-meta/client_threading.md) to reflect current `simroot_v2` state.
- 2026-05-25: Added [ThreadMan raw message wrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md) to document the missing destructor/post-message helper family.
- 2026-05-25: Corrected the aggregate Thread/ThreadMan range to end-exclusive `0x00596250-0x0059756e` and added exact pages for [ThreadMan constructor](by-memory/0x00596bf0-0x00596d13.ThreadManConstructor.md), [singleton clear helper](by-memory/0x005974e0-0x005974eb.ClearThreadManSingleton.md), and [ThreadMan scalar deleting destructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md).
- 2026-05-26: IDA MCP recheck reconfirmed modeled ThreadMan functions at `0x00596bf0`, `0x00596e10`, `0x00597100`, `0x005974e0`, and `0x005974f0`; raw wrapper starts `0x00596d20`, `0x00596d70`, `0x00596d90`, `0x00596db0`, `0x00596dd0`, and `0x00596df0` still report `Not a function` with empty xrefs. False-positive disabled rows still resolve outside ThreadMan: `0x0045004b` is inside `sub_450030`, `0x004e0052` is inside `NewHumanImageLib::NewHumanImageLib`, and `0x00597570` is `TimerHandler::TimerHandler`.

Follow-up:

- Recheck generated output after Wave3 fixes for `0x00596d20`, `0x00596d70`, `0x00596d90`, `0x00596db0`, `0x00596dd0`, `0x00596df0`, `0x00596e10`, `0x00597100`, `0x0045004b`, `0x004e0052`, and `0x00597570`.

### 2026-05-24 - ChangeMan active output omits register and filtered-unregister methods

Observed:

- Current `source-3/simroot_v2/class_ChangeMan.cpp` emits constructor `0x0047ec70`, dispatch `0x0047ee20`, broad unregister `0x0047eea0`, scalar deleting destructor `0x0047ef50`, and `g_pChangeMan`.
- IDA confirms two additional ChangeMan methods between constructor and dispatch: `0x0047ed50` builds a 16-byte registration record and inserts it through `SortedList::InsertSorted`; `0x0047ed80` removes matching records by owner/listener/scope/message filters.
- IDA callers for the omitted methods are application wrappers `0x004f4b30` and `0x004f4b50`.
- The omitted methods are source-structure relevant because they complete the `ChangeMan` public wrapper set with `Application::ForwardMessage` at `0x004f4b70`.
- Current `source-3/simroot_v2/class_ChangeMan.meta_wave3` still reports `vtable_count: 0`, even though IDA confirms the primary `ChangeMan` vtable at `0x00614cd0`.
- The active metadata summary says "Manager singleton for handling character transformations", which conflicts with the IDA-confirmed change/message-router behavior.

Expected:

- Emit or otherwise account for `0x0047ed50` and `0x0047ed80` under `ChangeMan`.
- Keep the wrapper methods at `0x004f4b30`, `0x004f4b50`, and `0x004f4b70` under `Application`.
- Preserve the 16-byte [ChangeManEntry](by-type/by-struct/ChangeManEntry.md) layout and the `SortedList(0x10, CompareChangeEntries, 100)` construction model.
- Include the `0x00614cd0` [ChangeMan vtable](by-type/by-vtable/ChangeManVtable.md) in generated vtable inventory and keep the class summary aligned with change/message routing.

Impact:

- Added [ChangeMan](by-file/ChangeMan.md), [ChangeMan class](by-class/ChangeMan.md), [ChangeMan memory](by-memory/0x0047ec70-0x0047efae.ChangeMan.md), [g_pChangeMan](by-global/g_pChangeMan.md), and [ChangeManEntry](by-type/by-struct/ChangeManEntry.md).
- Updated [Application](by-file/Application.md), [BackPane](by-file/BackPane.md), and [proposed source tree](by-project-structure/proposed-source-tree.md) with the app-level ownership decision.
- 2026-05-25: Converted ChangeMan and Application wrapper pages to end-exclusive ranges, added exact method pages for [constructor](by-memory/0x0047ec70-0x0047ed20.ChangeManConstructor.md), [register](by-memory/0x0047ed50-0x0047ed80.ChangeManRegister.md), [filtered unregister](by-memory/0x0047ed80-0x0047ee18.ChangeManUnregisterFiltered.md), [dispatch](by-memory/0x0047ee20-0x0047ee95.ChangeManDispatchMessage.md), [broad unregister](by-memory/0x0047eea0-0x0047eedf.ChangeManUnregisterObject.md), [comparator](by-memory/0x0047ef20-0x0047ef3f.CompareChangeEntries.md), [destructor](by-memory/0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor.md), and the two exact Application wrapper bodies under [Application ChangeMan register wrappers](by-memory/0x004f4b30-0x004f4b6c.ApplicationChangeManRegisterWrappers.md).
- 2026-05-26: IDA MCP recheck reconfirmed the omitted methods `0x0047ed50` and `0x0047ed80` as modeled functions with only Application wrapper callers, reconfirmed `0x004f4b30`, `0x004f4b50`, and `0x004f4b70` as Application wrappers, and added [ClearChangeManSingleton](by-memory/0x0047ef40-0x0047ef4b.ClearChangeManSingleton.md) for the tiny `g_pChangeMan` clear helper in the ChangeMan range.
- 2026-05-26: Added [ChangeMan vtable](by-type/by-vtable/ChangeManVtable.md) and [ChangeMan constructor cleanup](by-memory/0x0047ed20-0x0047ed50.ChangeManConstructorCleanup.md), and marked the cleanup fragment in [ignored memory ranges](by-memory/-ignored.md).
- 2026-05-26 follow-up: Added [ChangeMan layout](by-type/by-struct/ChangeManLayout.md) and exact [g_pChangeMan memory](by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md). IDA reconfirmed `Application::Initialize` allocation size `0x08`, `g_pChangeMan` writes at `0x0047ecb2`/`0x0047ecb9`, cleanup writes at `0x0047ed3f`, `0x0047ef40`, and `0x0047ef72`, and wrapper reads at `0x004f4b3d`, `0x004f4b5d`, and `0x004f4b77`.

Follow-up:

- Recheck generated output after Wave3 fixes for `0x0047ed50`, `0x0047ed80`, `0x004f4b30`, `0x004f4b50`, `0x00614cd0`, `0x0067ab2c`, `ChangeMan` layout size, and the active `ChangeMan` summary.

### 2026-05-24 - AttachedObjectPaneHelper_53AEC0 is a generated one-method split and aliases the layout mode byte

Observed:

- Active `source-3/simroot_v2/class_AttachedObjectPaneHelper_53AEC0.cpp` emits a standalone `AttachedObjectPaneHelper_53AEC0::DetachAttachedObject` method at `0x0053aec0`.
- IDA confirms `sub_53AEC0` is a real function with size `0x152`, but `callers` and `xrefs_to` report only one code caller: `0x005382b0` inside `AttachedObjectPane::~AttachedObjectPane`.
- IDA decompilation of `AttachedObjectPane::~AttachedObjectPane` shows the call shape `sub_53AEC0(*(this + 0x128), this)`, so the generated helper's `this` pointer is the owner/registry object stored by `AttachedObjectPane`, not evidence for a standalone source file.
- The helper reads the detached object's type byte at `+0xf8`, removes type `2` and type `4` entries from lists at registry offsets `+0x170` and `+0x174`, and clears singleton slots at `+0x1d8`, `+0x1dc`, `+0x1e0`, and `+0x1e4`.
- The generated global alias `g_attachmentModeFlag` is misleading. IDA names the same address `byte_66DA97` at `0x0066da97`, and a 2026-05-24 IDA xref count found 366 references across UI/render/layout code.

Expected:

- Fold `0x0053aec0-0x0053b011` into [AttachedObjectPane](by-file/AttachedObjectPane.md) as private registry cleanup unless later constructor/setup evidence recovers a real named manager class.
- Normalize `g_attachmentModeFlag` to [g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97` in docs and generated-name review.
- Keep the registry layout offsets in [AttachedObjectRegistryLayout](by-type/by-struct/AttachedObjectRegistryLayout.md) and avoid using the generated helper filename as original source-layout evidence.

Impact:

- Added [AttachedObjectPaneHelper_53AEC0](by-file/AttachedObjectPaneHelper_53AEC0.md), [AttachedObjectPaneHelper_53AEC0 class artifact](by-class/AttachedObjectPaneHelper_53AEC0.md), [AttachedObject detach registry memory](by-memory/0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md), [AttachedObjectRegistryLayout](by-type/by-struct/AttachedObjectRegistryLayout.md), and [g_useEpfAssets](by-global/g_useEpfAssets.md).

Recheck:

- 2026-05-25 using current `simroot_v2` and IDA MCP only: generated output still emits the standalone helper file and `g_attachmentModeFlag`; IDA still reports `sub_53AEC0` size `0x152`, only caller/xref `0x005382b0`, call shape `sub_53AEC0(*(this + 0x128), this)`, and 366 xrefs to `byte_66DA97`.
- 2026-05-26 using current `simroot_v2` and IDA MCP only: generated output still emits the standalone helper and `g_attachmentModeFlag`; IDA still reports `sub_53AEC0` size `0x152`, the sole caller/xref at `0x005382b0`, call shape `sub_53AEC0(*(this + 0x128), this)`, unchanged registry offsets `+0x170`, `+0x174`, `+0x1d8`, `+0x1dc`, `+0x1e0`, and `+0x1e4`, EPF/current-mode-only type `8` clearing, and 366 xrefs to `byte_66DA97`.

Follow-up:

- Recheck after the next `simroot_v2` refresh or Wave3 regeneration for `0x0053aec0`, `AttachedObjectPane + 0x128`, and the global alias at `0x0066da97`.

### 2026-05-24 - CopyWindow active output misses live open helper and over-narrows active TextEditPane global

Observed:

- Active `source-3/simroot_v2/class_CopyWindow.cpp` emits constructor `0x005544c0`, `OnAccept` at `0x00554520`, and `OnCancel` at `0x00554540`.
- IDA confirms `0x00554520` and `0x00554540` as real callback functions with vtable data xrefs, but `lookup_funcs 0x005544c0` reports "Not a function" even though disassembly at `0x005544c0-0x00554512` is valid constructor-shaped code.
- IDA decompilation of `0x00553e60-0x00553f35` shows a live helper with a stale/bogus symbol name. It checks `dword_69BE00`, calls a text-edit state/count helper, allocates 624 bytes, and constructs a `CopyWindow` inline by calling `AlertPane::AlertPane` and installing `CopyWindow` vtables.
- Generated `g_pCopyWindowTextEditPane` is too narrow. IDA xrefs show the same address, `dword_69BE00` / `0x0069be00`, is set by `TextEditPane::TextEditPane`, cleared by `TextEditPane::~TextEditPane`, and consumed by `CopyWindow` callbacks.

Expected:

- Account for the live `0x00553e60-0x00553f35` helper when migrating the reconnect/connection-closed dialog cluster; keep its conditional `CopyWindow` construction cross-referenced but do not migrate the helper into `CopyWindow.cpp` by default.
- Either model `0x005544c0` as a function or keep it explicitly documented as a raw constructor start until IDA/Wave3 function recovery agrees.
- Normalize the global alias to [g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md), not `g_pCopyWindowTextEditPane`.

Impact:

- Added [CopyWindow](by-file/CopyWindow.md), [CopyWindow class](by-class/CopyWindow.md), [CopyWindow memory](by-memory/0x005544c0-0x0055454a.CopyWindow.md), [ConnectionClosedDialog init helper memory](by-memory/0x00553e60-0x00553f35.ConnectionClosedDialogInitHelper.md), and [g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md).
- Updated [TextEditPane](by-file/TextEditPane.md), [AlertPanes](by-file/AlertPanes.md), and [proposed source tree](by-project-structure/proposed-source-tree.md).

Follow-up:

- Recheck generated output after Wave3 fixes for `0x00553e60`, `0x005544c0`, `0x00554520`, `0x00554540`, and global `0x0069be00`.
- 2026-05-25 follow-up: `g_pActiveTextEditPane` is now typed as `TextEditPane*` with reviewed memory range `0x0069be00-0x0069be03`. Live `validate memory-range global-data g_pActiveTextEditPane` returns zero issues, `show memory-at 0x0069be00 --include-ignored --include-allowed` resolves `global-data:g_pActiveTextEditPane`, and `show global-data g_pActiveTextEditPane --summary` reports complete/resolved.
- 2026-05-25 follow-up: `g_pCopyWindowTextEditPane` remains alias/name pollution rather than a separate storage slot. Do not add a duplicate range over `0x0069be00`; fix this through a safe global-data alias/merge workflow so CopyWindow references canonical `g_pActiveTextEditPane` without creating two global-data records for one address.
- 2026-05-25 IDA-only follow-up: `0x00553e60` has callers at `0x00553ca8`, `0x00553d55`, and `0x005543bb`, so docs now treat it as a `ConnectionClosedDialog`/reconnect-flow init helper with a conditional `CopyWindow` side path rather than a CopyWindow-owned open method.
- 2026-05-26 IDA/simroot follow-up: `0x00553e60` still has the same three callers, stale IDA debug symbol, and `0xd6` size. Current `class_ConnectionClosedDialog.cpp` calls the helper as `InitializeConnectionState()` but still does not emit the helper body in the active source view. Current `class_CopyWindow.cpp` still emits `g_pCopyWindowTextEditPane`, while `class_TextEditPane.cpp` owns canonical `g_pActiveTextEditPane` at `0x0069be00`.

### 2026-05-24 - SelfSaveInputPane misses factory/raw helper and has non-IDA constructor start

Observed:

- Active `source-3/simroot_v2/class_SelfSaveInputPane.cpp` emits constructor `0x005b67c0` and `OnConfirmInput` at `0x005b6800`.
- IDA confirms `0x005b6800` as a real function with a vtable data xref from `0x00630608`, but `lookup_funcs 0x005b67c0` reports "Not a function" even though disassembly at `0x005b67c0-0x005b67ff` is valid constructor-shaped code.
- IDA disassembly shows an adjacent raw helper at `0x005b6870-0x005b68b0` that sends the same opcode `0x25` without reading input. IDA does not currently model this start as a function.
- IDA vtable xrefs and decompilation show a discontiguous factory/helper at `0x005aa140-0x005aa1bf` that allocates 264 bytes, calls `CharInputPane::CharInputPane`, and installs `SelfSaveInputPane` vtables inline. Active generated output does not include this helper.
- The class sends through the broad shared `dword_67A7EC` packet object; generated type/name `g_packetSender` remains unresolved project-wide.

Expected:

- Account for `0x005b67c0`, `0x005b6800`, raw helper `0x005b6870`, and factory `0x005aa140` together before migrating `SelfSaveInputPane`.
- Treat the final owner as [CommandInputPanes](by-file/CommandInputPanes.md) or an adjacent command-prompt source unless stronger evidence recovers a dedicated original `SelfSaveInputPane.cpp`.
- Keep `0x005b68c0+` with [BlockListenInputPanes](by-file/BlockListenInputPanes.md), not SelfSave.

Impact:

- Added [SelfSaveInputPane](by-file/SelfSaveInputPane.md), [SelfSaveInputPane class](by-class/SelfSaveInputPane.md), [SelfSaveInputPane memory](by-memory/0x005b67c0-0x005b68b0.SelfSaveInputPane.md), and [SelfSaveInputPane factory memory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md).
- Updated [CommandInputPanes](by-file/CommandInputPanes.md) and [proposed source tree](by-project-structure/proposed-source-tree.md).

Recheck:

- 2026-05-25 using current `simroot_v2` and IDA MCP only: `lookup_funcs` still reports `0x005b67c0` and `0x005b6870` as not functions, while `0x005b6800` is `sub_5B6800` size `0x6c` and `0x005aa140` is `sub_5AA140` size `0x80`.
- 2026-05-25 IDA decompilation reconfirms `OnConfirmInput` reads a one-character prompt response, accepts `y`/`Y`, writes opcode `0x25`, and queues one byte through `dword_67A7EC`; raw disassembly confirms `0x005b6870` sends the same opcode without reading input.
- 2026-05-25 IDA reports no direct callers for `0x005aa140`; docs now also track the sender as [g_packetSender](by-global/g_packetSender.md) / [0x0067a7ec-0x0067a7f0](by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md).
- 2026-05-26 using current `simroot_v2` and IDA MCP only: active `class_SelfSaveInputPane.cpp` still emits only constructor plus `OnConfirmInput`; `0x005b6870` and `0x005aa140` remain absent from active source. IDA results are unchanged: raw constructor/helper starts at `0x005b67c0` and `0x005b6870`, `0x005b6800` size `0x6c` with only vtable data xref `0x00630608`, `0x005aa140` size `0x80` with no direct callers/xrefs, and 489 xrefs to `dword_67A7EC`.

Follow-up:

- Recheck generated output after the next `simroot_v2` refresh or Wave3 regeneration for `0x005b67c0`, `0x005b6800`, `0x005b6870`, `0x005aa140`, and sender global `0x0067a7ec`.

### 2026-05-25 - ScreenshotCapture generated output omits raw JPEG capture path

Observed:

- Current `source-3/simroot_v2/class_ScreenshotCapture.cpp` emits `SaveScreenshotBMP` at `0x00557aa0` and `SaveScreenshotPNG` at `0x00557e80`, but no method for the raw function-shaped body at `0x00557840-0x00557a95`.
- IDA does not model `0x00557840` as a function start, but disassembly shows a normal prologue at `0x00557840`, stack frame setup, `Documents\NexusTK\ScreenShots` creation, timestamped `TK_%04d%02d%02d%02d%02d%02d.jpg` formatting, active-surface capture, a call to JPEG writer `0x004efbc0` at `0x005579d3`, saved-file chat/status output, screenshot proof submission through `0x00558240`, and a normal epilogue/return at `0x00557a95`.
- IDA `xrefs_to 0x004efbc0` reports the code xref at `0x005579d3`, but `callers 0x00557840` reports none because the start is not modeled as a function.

Expected:

- Track `0x00557840-0x00557a95` as a `ScreenshotCapture` raw/retained JPG capture path until Wave3/IDA function recovery decides whether it is live, indirect, or dead legacy code.
- Track `0x004efbc0-0x004efe94` as a project-owned JPEG writer wrapper and adjacent local JPEG callback support island under `ImageWriters`, not as stock IJG source.

Impact:

- Added [JPEG screenshot capture path](by-memory/0x00557840-0x00557a95.ScreenshotJpegCapturePath.md) and [JPEG screenshot writer](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md).
- Updated [ScreenshotCapture](by-file/ScreenshotCapture.md), [ScreenshotCapture class](by-class/ScreenshotCapture.md), [ImageWriters](by-file/ImageWriters.md), [LibJPEG](by-file/LibJPEG.md), [client libraries](by-meta/client_libraries.md), and [proposed source tree](by-project-structure/proposed-source-tree.md).

Follow-up:

- Recheck after the next `simroot_v2` refresh or Wave3 regeneration for function recovery at `0x00557840`, call reachability to that raw path, and owner attachment for `0x004efbc0`.
- 2026-05-26 using current `simroot_v2` and IDA MCP only: active `class_ScreenshotCapture.cpp` still emits only BMP/PNG capture methods and still omits the raw JPG body. IDA now models the adjacent flag setters `0x00557820` and `0x00557830` as 8-byte functions with one caller each, but `0x00557840` remains not-a-function with no callers/xrefs. `xrefs_to` still shows the JPG writer call at `0x005579d3` and proof-submit call at `0x00557a78`, while BMP/PNG/proof/LodePNG function sizes and EventDispatcher hotkey call sites remain unchanged.

### 2026-05-25 - Wide API dispatch table has generated ownership and boundary drift

Observed:

- Current `source-3/simroot_v2/class_UniAPIInit.cpp` emits the wide Win32 API dispatch initializer as `UniAPIInit::~UniAPIInit` at `0x005995b0`.
- IDA MCP `lookup_funcs 0x005995b0` reports "Not a function". The matching real initializer is `0x0041a280-0x0041a4a8`; IDA decompilation shows `GetVersionExA`, NT-family selection, wide Win32 API pointer assignments, `_wfopen` assigned to `dword_69BE14`, `_wstat64i32` assigned to `dword_69BE18`, and `_atexit(sub_60C440)`.
- IDA MCP confirms `sub_60C440` at `0x0060c440-0x0060c44b` as the static cleanup wrapper registered by the real initializer. It only writes `UniAPIInit::vftable` to `0x006702c4`.
- Current `source-3/simroot_v2/recovered/PathExistsViaStat_00582460.cpp` emits `void* dword_69BE18` beside `PathExistsViaStat`, which can imply local PathUtil ownership. IDA xrefs show `dword_69BE18` is a platform dispatch-table entry written by `0x0041a280`, read by `StdioFile::Open`, and read by `PathExistsViaStat`.
- `dword_69BE14` has many direct file-open consumers in addition to `StdioFile::Open`, reinforcing that it is process-wide platform data rather than a `StdioFile` field.

Expected:

- Re-anchor the generated `UniAPIInit` dispatch setup to the real initializer at `0x0041a280-0x0041a4a8`, or explicitly model the generated `0x005995b0` body as a raw/provenance artifact until function recovery is corrected.
- Treat `0x0060c440-0x0060c44b` as compiler/static-lifetime cleanup for `UniAPIInit`, not as an allocator cleanup wrapper or normal handwritten platform method.
- Own `dword_69BE14`, `dword_69BE18`, and neighboring `0x0069be14-0x0069bed0` API pointers under `platform/PlatformApi.cpp` / `WideApiDispatchTable`.
- Keep `StdioFile`, `PathUtil`, image, map, startup, and audio docs as consumers of table entries, not owners of the table.

Impact:

- Added [WideApiDispatchTable](by-global/WideApiDispatchTable.md), [WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md), and [UniAPIInit static cleanup wrapper](by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md).
- Updated [PlatformApi](by-file/PlatformApi.md), [UniAPIInit](by-class/UniAPIInit.md), [UniAPIInit memory](by-memory/0x005995b0-0x00599a34.UniAPIInit.md), [FileIO](by-file/FileIO.md), [PathUtil](by-file/PathUtil.md), [PathExistsViaStat](by-item/PathExistsViaStat_00582460.md), [PathExistsViaStat memory](by-memory/0x00582460-0x00582495.PathExistsViaStat.md), [StdioFile::Open](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md), and [proposed source tree](by-project-structure/proposed-source-tree.md).

Follow-up:

- After Wave3 ownership/boundary fixes, recheck `0x0041a280`, `0x005995b0`, `0x00599a10`, `0x0069be14`, and `0x0069be18` against generated output and global-data ownership.
- 2026-05-26 using current `simroot_v2` and IDA MCP only: `class_UniAPIInit.cpp` still emits the initializer as `~UniAPIInit` at `0x005995b0`. IDA still reports `0x005995b0` as not-a-function with no callers/xrefs, `0x0041a280` as the real `0x228`-byte dispatch initializer with startup-table data xref `0x0060d71c`, `0x0060c440` as the `0x0b`-byte static cleanup wrapper with the only `0x006702c4` data xref, and `0x00599a10` as the `0x24`-byte scalar deleting destructor with vtable data ref `0x0062e57c`. `dword_69BE14`/`dword_69BE18` initializer writes and consumer xrefs remain table-wide platform evidence, not StdioFile/PathUtil ownership.

### 2026-05-25 - FrameChrome slot helpers and raw cleanup are under-modeled

Observed:

- Current `source-3/simroot_v2/class_FramePartPane.cpp` emits the main `FramePartPane` methods, but does not emit the raw cleanup body at `0x004b7320-0x004b73a3`. IDA does not model this range as a function, but disassembly shows it releases and clears the five global frame-part slots `0x0069b33c-0x0069b350`.
- IDA MCP `xrefs_to 0x0069b33c-0x0069b34c` shows the slots are written by `BuildFramePartPanes` at `0x004b7120`, cleared by the raw cleanup body at `0x004b7320`, and cleared by `FramePartPane::OnNotification` at `0x004b73b0`.
- IDA MCP `callers 0x004b7120` reports no direct callers, so the live construction path for the five `FramePartPane` slots remains unresolved.
- IDA currently labels the adjacent `0x004615d0-0x00461657` dynamic `AboveFrame` creator as `__std_parallel_algorithms_hw_threads`, but decompilation shows `operator_new(308)`, `AboveFrame::AboveFrame`, and assignment to `dword_67A840`. This is frame-chrome behavior, not C++ standard-library code.
- `GeneralPurposePanel` switch helpers call the `0x004615b0` / adjacent creator pair after tab switches. These helpers operate on `AboveFrame` slot state, not `GeneralPurposePanel` ownership.

Expected:

- Track `0x004b7320-0x004b73a3` as frame-chrome raw cleanup or compiler EH cleanup until the function boundary/reachability model is decided.
- Own `0x0069b33c-0x0069b350` under `FrameChromeSlots`, not as unrelated file-local globals.
- Treat `0x004615b0-0x00461657` as `AboveFrame` refresh/rebuild support and keep it with `FrameChrome`, despite calls from `GeneralPurposePanel`.
- Do not rely on the current IDA `__std_parallel_algorithms_hw_threads` label for source ownership around `0x004615d0`.

Impact:

- Added [FrameChromeSlots](by-global/FrameChromeSlots.md), [AboveFrame slots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md), [FramePartPane slots](by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md), [AboveFrame refresh helpers](by-memory/0x004615b0-0x00461657.AboveFrameRefreshHelpers.md), and [FramePartPane slot cleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md).
- Updated [FrameChrome](by-file/FrameChrome.md), [AboveFrame](by-class/AboveFrame.md), [FramePartPane](by-class/FramePartPane.md), [GeneralPurposePanel](by-file/GeneralPurposePanel.md), the exact frame/panel memory docs, and [proposed source tree](by-project-structure/proposed-source-tree.md).

Follow-up:

- Recheck generated output after Wave3 boundary/ownership fixes for `0x004615b0`, `0x004615d0`, `0x004b7120`, `0x004b7320`, `0x0067a840`, and `0x0069b33c-0x0069b34c`.
- 2026-05-26 using current `simroot_v2` and IDA MCP only: the issue remains current. `class_FramePartPane.cpp` still omits `0x004b7320-0x004b73a3`; `lookup_funcs 0x004b7320` still reports not-a-function; `callers 0x004b7120` and `callers 0x004b7320` are empty; slot xrefs still show `0x004b7120` writes, raw cleanup reads/clears, and `FramePartPane::OnNotification` clears. The `0x004615d0` creator is still mislabeled by IDA as `___std_parallel_algorithms_hw_threads@0` despite decompiling to `AboveFrame` allocation into `dword_67A840`.
- 2026-05-26 exact xref follow-up: `AboveFrame::AboveFrame` has ten direct refs in the frame-chrome island, nine from `BuildAboveFrameBorder` and one from the dynamic recreate helper. Do not describe all ten as belonging to the border factory; the recreate helper is the separate `dword_67A840` refresh path.
- 2026-05-26 exact boundary follow-up: IDA models `BuildFramePartPanes` as `0x004b7120-0x004b731f` end-exclusive. Older documentation that used `0x004b7311` was too short; the live caller problem remains unresolved because direct caller lookup is still empty.

### 2026-05-26 - DIBitmap and DirectX vtables/helpers are under-modeled

Observed:

- `class_DIBitmap.meta_wave3` reports `vtable_count: 0`, but IDA confirms the primary `DIBitmap` vtable at `0x00618e54`. Xrefs land at constructor store `0x004a1638`, raw destructor store `0x004a1746`, inline factory construction `0x004a195c`, and scalar destructor store `0x004a1b19`.
- Active `source-3/simroot_v2/class_DIBitmap.cpp` emits the constructor and scalar deleting destructor but omits the real `0x004a1740-0x004a17ad` half-open cluster: raw non-deleting destructor/cleanup, `GetBits`, `GetBitmapHandle`, guarded width/height accessors, and guarded aligned-width accessor.
- Current `class_DIBitmap.meta_wave3` reports a `0x60`-byte object with noisy undefined byte fields, while IDA-confirmed constructor/accessor/destructor evidence only requires fields through `+0x38` in the checked cluster.
- `class_DirectX.meta_wave3` reports `vtable_count: 0`, but IDA confirms the primary `DirectX` vtable at `0x00618e64`. Xrefs land at `0x004a1bbf`, `0x004a1c88`, and `0x004a1cf8`.
- Active `source-3/simroot_v2/class_DirectX.cpp` omits the real helper at `0x004a1cc0-0x004a1ccb`, which only clears `dword_67AB20` / `g_pDirectX` and returns. IDA shows a cref from the constructor unwind/chunk context at `0x005fd71e`.

Expected:

- Generated vtable inventory should record `DIBitmap` vtable `0x00618e54` and `DirectX` vtable `0x00618e64` instead of leaving both classes at `vtable_count: 0`.
- Generated source or generated docs should account for the `DIBitmap` `0x004a1740-0x004a17ad` half-open tiny-method cluster and the `DirectX` `0x004a1cc0` singleton-clear helper, even if some starts remain raw/not modeled as IDA functions.

Impact:

- Added [DIBitmap destructor and accessors](by-memory/0x004a1740-0x004a17ad.DIBitmapDestructorAndAccessors.md), [DIBitmap and DirectX vtables](by-type/by-vtable/DIBitmapDirectXVtables.md), and [g_pDirectX](by-global/g_pDirectX.md).
- Added [DIBitmap layout](by-type/by-struct/DIBitmapLayout.md) to pin the IDA-confirmed object offsets separately from generated layout noise.
- Updated [DIBitmap](by-file/DIBitmap.md), [DIBitmap class](by-class/DIBitmap.md), [DIBitmap and PCX memory](by-memory/0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders.md), [DirectX](by-file/DirectX.md), [DirectX class](by-class/DirectX.md), [DirectX memory](by-memory/0x004a1b60-0x004a1d6a.DirectX.md), and [proposed source tree](by-project-structure/proposed-source-tree.md).

Follow-up:

- Recheck generated output after Wave3 vtable and raw-function recovery fixes for `0x00618e54`, `0x00618e64`, `0x004a1740`, `0x004a1760`, `0x004a1770`, `0x004a1780`, `0x004a1790`, `0x004a17a0`, and `0x004a1cc0`.

### 2026-05-26 - CachedHashTable omits raw helper block and vtable inventory

Observed:

- Active `source-3/simroot_v2/class_CachedHashTable.cpp` emits only the constructor, ordinary destructor, and scalar deleting destructor.
- Active `source-3/simroot_v2/class_CachedHashTable.meta_wave3` reports `vtable_count: 0`, but IDA confirms the primary `CachedHashTable` vtable at `0x0061aac4`, with RTTI pointer at `0x0061aac0`.
- 2026-05-26 IDA MCP recheck reports `0x004c64b0` and `0x004c64c0` as real `0x4`-byte count accessor functions, but active generated source still omits them.
- IDA `lookup_funcs` reports `0x004c62d0`, `0x004c63d0`, `0x004c63f0`, `0x004c6420`, `0x004c6450`, and `0x004c64d0` as not-a-function starts, but raw disassembly shows complete `CachedHashTable` helper bodies between the ordinary destructor and scalar deleting destructor.
- 2026-05-26 manual IDA `py_eval` recheck reconfirmed the same helper/function split and vtable sequence: RTTI at `0x0061aac0`, slots `0x004c64f0`, `0x004f4b10`, `0x0041b6c0`, and next RTTI at `0x0061aad0`.
- The helper island operates only on the confirmed `CachedHashTable` fields: entry buffer, slot-state buffer, entry size, slot count, and entry count.

Expected:

- Generated class output or generated documentation should account for the helper island at `0x004c62d0-0x004c64de`, including modeled accessors and raw/non-IDA helper starts.
- Generated vtable inventory should record the `0x0061aac4` vtable instead of leaving `CachedHashTable` at `vtable_count: 0`.

Impact:

- Added [CachedHashTable vtable](by-type/by-vtable/CachedHashTableVtable.md) and [CachedHashTable raw helpers](by-memory/0x004c62d0-0x004c64de.CachedHashTableRawHelpers.md).
- Added [CachedHashTable count accessors](by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md) after IDA modeled `0x004c64b0` and `0x004c64c0` as real functions.
- Updated [CachedHashTable](by-file/CachedHashTable.md), [CachedHashTable class](by-class/CachedHashTable.md), [CachedHashTable layout](by-type/by-struct/CachedHashTableLayout.md), [CachedHashTable lifecycle memory](by-memory/0x004c6160-0x004c659b.CachedHashTableLifecycle.md), and [proposed source tree](by-project-structure/proposed-source-tree.md).

Follow-up:

- Recheck generated output after Wave3 raw-function and vtable recovery fixes for `0x004c62d0`, `0x004c63d0`, `0x004c63f0`, `0x004c6420`, `0x004c6450`, `0x004c64b0`, `0x004c64c0`, `0x004c64d0`, and `0x0061aac4`.

### 2026-05-26 - RGB555/RGB565 blit helper island is not emitted as standalone render support

Observed:

- Current `source-3/simroot_v2` does not emit standalone recovered files for `0x0045fa00`, `0x0045faa0`, `0x0045fb80`, `0x0045fe40`, `0x00460370`, or `0x00460410`.
- Generated `class_RankingEventListPane` metadata references some of the helpers as unresolved `FUN_...` externs from process-wide render callback bodies, but this does not make them Ranking UI code.
- IDA MCP confirms real functions from `0x0045fa00-0x004604f4`; callers tie the RGB555 helpers to compatibility callbacks at `0x004bc090` and `0x004bdf40`, and the RGB565 helpers to callbacks at `0x004c0f80` and `0x004c3cf0`.
- Older Wave2 missing-ref annotations describe these as low-level render support and mark them as no-standalone-restore support glue. For source reconstruction, they still need documented render ownership because the code is project software-render behavior, not CRT/library code.

Expected:

- Generated docs/output should represent the helper island under render software-blit support, likely [SoftwareBlend16](by-file/SoftwareBlend16.md) or a sibling `SoftwareRender` source, rather than only as unresolved externs inside Ranking callback output.
- The helpers should not be moved to `RankingDialog.cpp` / `RankingEventListPane.cpp`.

Impact:

- Added [RGB555/RGB565 blit helper island](by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md).
- Updated [SoftwareBlend16](by-file/SoftwareBlend16.md), the software render callback family pages, [BlendRgb555](by-item/BlendRgb555_004C0710.md), rendering-mode meta docs, and [proposed source tree](by-project-structure/proposed-source-tree.md).

Follow-up:

- Recheck generated output after Wave3 missing-ref restoration for `0x0045fa00`, `0x0045faa0`, `0x0045fb80`, `0x0045fe40`, `0x0045ff60`, `0x0045fff0`, `0x00460120`, `0x00460230`, `0x004602b0`, `0x00460370`, and `0x00460410`.

### 2026-05-26 - `FontImageLib` omits ordinary destructor and vtable inventory

Observed:

- Active `source-3/simroot_v2/class_FontImageLib.cpp` emits constructor, metrics, glyph measurement, lazy font-slot load, glyph decode, and scalar deleting destructor, but omits the ordinary non-deleting destructor at `0x004b5f60-0x004b5fe6`.
- Active `class_FontImageLib.meta_wave3` reports `vtable_count: 0`, but IDA confirms `FontImageLib` vtable `0x0061a5f4` with slots `0x004b6350`, `0x004f4b10`, and `0x0041b6c0`.
- IDA confirms [g_pFontImageLib](by-global/g_pFontImageLib.md) at `0x0067ab24`; several generated UI text consumers still carry stale/raw receiver forms such as `extern char* g_pFontImageLib` or adjacent `g_pDirectX`-style aliases.

Expected:

- Generated class output or generated documentation should account for ordinary destructor `0x004b5f60` in addition to scalar deleting destructor `0x004b6350`.
- Generated vtable inventory should record `0x0061a5f4` instead of leaving `FontImageLib` at `vtable_count: 0`.
- Generated text consumers should normalize `0x0067ab24` reads to `g_pFontImageLib` and avoid confusing them with adjacent `g_pDirectX` at `0x0067ab20`.

Impact:

- Added [g_pFontImageLib](by-global/g_pFontImageLib.md), [singleton storage](by-memory/0x0067ab24-0x0067ab28.g_pFontImageLib.md), [FontImageLib ordinary destructor](by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md), [FontImageLib vtable](by-type/by-vtable/FontImageLibVtable.md), [FontImageLib layout](by-type/by-struct/FontImageLibLayout.md), [FontSlotStorage](by-type/by-struct/FontSlotStorage.md), and [FontGlyphRecord](by-type/by-struct/FontGlyphRecord.md).
- Updated [FontImageLib](by-file/FontImageLib.md), [FontImageLib class](by-class/FontImageLib.md), [FontImageLib memory](by-memory/0x004b5f00-0x004b6409.FontImageLib.md), [Application](by-file/Application.md), [client_new_rendering_mode](by-meta/client_new_rendering_mode.md), and [proposed source tree](by-project-structure/proposed-source-tree.md).

Follow-up:

- Recheck generated output after Wave3 vtable/raw-function recovery fixes for `0x004b5f60`, `0x004b6350`, `0x0061a5f4`, and `0x0067ab24`.

### 2026-05-26 - WaitableTimer omits raw start/cancel helpers and mislabels event-gate field

Observed:

- Current active `source-3/simroot_v2/class_WaitableTimer.cpp` emits the constructor, cleanup body, scalar deleting destructor, and `WaitableTimerCompletion_5C11C0` callback, but omits raw helper bodies at `0x005c1120-0x005c1167` and `0x005c1170-0x005c11b4`.
- IDA MCP `lookup_funcs` reports `0x005c1120`, `0x005c1130`, `0x005c1140`, `0x005c1150`, and `0x005c11a0` as not-a-function starts, but gap disassembly shows complete `thiscall`-shaped start/register and cancel/reset helpers.
- The raw start/register helper at `0x005c1120` creates an event through `dword_69BE3C`, stores it at `+0x28`, registers callback `0x005c11c0` through `timeSetEvent`, stores the timer id at `+0x24`, and signals the `+0x28` event after registration succeeds.
- [WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) assigns `CreateEventW` to `dword_69BE3C` at `0x0041a30c`, so generated field name `m_hWorkerThread` for `+0x28` is incorrect or at least unsupported.
- Current `class_WaitableTimer.meta_wave3` reports `vtable_count: 0`, but IDA confirms the one-slot `WaitableTimer` vtable at `0x00631188`; the next dword `0x0063118c` is `WeatherLayerPane` RTTI, not another `WaitableTimer` slot.
- Older metadata text says the constructor likely uses `CreateWaitableTimer`; IDA and the platform dispatch table confirm `CreateEventW`.

Expected:

- Generated output should recover or explicitly account for raw helper starts `0x005c1120` and `0x005c1170` under `WaitableTimer`.
- Generated layout should rename or mark `+0x28` as event-gate state rather than a worker-thread handle unless later caller evidence proves a different role.
- Generated vtable inventory should record `0x00631188` instead of `vtable_count: 0`.
- Generated summaries should not describe the constructor as `CreateWaitableTimer`-based.

Impact:

- Added [WaitableTimer raw start/cancel helpers](by-memory/0x005c1120-0x005c11b4.WaitableTimerRawStartStop.md), [WaitableTimer layout](by-type/by-struct/WaitableTimerLayout.md), and [WaitableTimer vtable](by-type/by-vtable/WaitableTimerVtable.md).
- Updated [WaitableTimer file](by-file/WaitableTimer.md), [WaitableTimer class](by-class/WaitableTimer.md), [WaitableTimer aggregate memory](by-memory/0x005c0ff0-0x005c129a.WaitableTimer.md), [Wide API dispatch table](by-global/WideApiDispatchTable.md), and [proposed source tree](by-project-structure/proposed-source-tree.md).

Follow-up:

- Recheck generated output after Wave3 raw-function, layout-name, and vtable recovery fixes for `0x005c1120`, `0x005c1170`, `0x005c11c0`, `0x00631188`, `0x0069be3c`, and WaitableTimer offset `+0x28`.

### 2026-05-26 - `LightObjImageLib` omits ordinary destructor and vtable inventory

Observed:

- Active `source-3/simroot_v2/class_LightObjImageLib.cpp` emits constructor `0x004df7e0`, virtual draw modes `0x004dfbb0` and `0x004dfc60`, and scalar deleting destructor `0x004e65e0`, but does not model the ordinary non-deleting destructor body at `0x004dfab0-0x004dfb36`.
- Active `class_LightObjImageLib.meta_wave3` reports `vtable_count: 0`, but IDA confirms `LightObjImageLib` vtable `0x0061b754` with slots `0x004e65e0`, `0x004f4b10`, `0x0041b6c0`, `0x004dfbb0`, and `0x004dfc60`.
- IDA also confirms the adjacent `ProtectedArray<LightInfo>` vtable at `0x0061b74c`, singleton storage [g_pLightObjImageLib](by-global/g_pLightObjImageLib.md) at `0x0069b450`, and singleton-clear helper `0x004e5bb0-0x004e5bbb`.
- The generated class effective grade is `41.5` even though modeled method bodies are high-scoring, so the generated file can look useful while still missing class inventory data needed for source reconstruction.

Expected:

- Generated class output or generated documentation should account for ordinary destructor `0x004dfab0` in addition to scalar deleting destructor `0x004e65e0`.
- Generated vtable inventory should record `0x0061b754` and adjacent `0x0061b74c` instead of leaving `LightObjImageLib` at `vtable_count: 0`.
- Generated type/layout output should surface the `0x1c`-byte `LightInfo` record and `LightObjImageLib` offsets `+0x08`, `+0x0c`, `+0x10`, and fallback record `+0x14`.

Impact:

- Added [g_pLightObjImageLib](by-global/g_pLightObjImageLib.md), [singleton storage](by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md), [LightObjImageLib ordinary destructor](by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md), [LightObjImageLib singleton clear helper](by-memory/0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper.md), [LightObjImageLib vtable](by-type/by-vtable/LightObjImageLibVtable.md), [LightObjImageLib layout](by-type/by-struct/LightObjImageLibLayout.md), and [LightInfo](by-type/by-struct/LightInfo.md).
- Updated [LightObjImageLib](by-file/LightObjImageLib.md), [LightObjImageLib class](by-class/LightObjImageLib.md), [LightObjImageLib memory](by-memory/0x004df7e0-0x004e669c.LightObjImageLib.md), [EPFImageResources](by-file/EPFImageResources.md), [Application](by-file/Application.md), [client_new_rendering_mode](by-meta/client_new_rendering_mode.md), and [proposed source tree](by-project-structure/proposed-source-tree.md).

Follow-up:

- Recheck generated output after Wave3 raw-function, vtable, global, and layout recovery fixes for `0x004dfab0`, `0x004e5bb0`, `0x004e65e0`, `0x0061b754`, `0x0061b74c`, `0x0069b450`, and the `LightInfo` row layout.

### 2026-05-26 - `RidingImageLib` omits ordinary destructor/vtable and splits a field as global-data

Observed:

- Active `source-3/simroot_v2/class_RidingImageLib.cpp` emits `LoadRidingDefinitions` `0x004dc420`, constructor `0x004dc690`, and deleting destructor `0x004e68b0`, but does not model the ordinary non-deleting destructor body at `0x004dc730-0x004dc7d8`.
- Active `class_RidingImageLib.meta_wave3` reports `vtable_count: 0`, but IDA confirms `RidingImageLib` vtable `0x0061b6f4` with slots `0x004e68b0`, `0x004f4b10`, and `0x0041b6c0`.
- Active global-data metadata lists `g_pRidingImageLib`, `g_ridingDefinitionBuckets`, and `g_ridingDefinitionGroups` with unresolved `memory_ranges`.
- IDA confirms [g_pRidingImageLib](by-global/g_pRidingImageLib.md) at `0x0069b444`, singleton-clear helper `0x004e5bf0-0x004e5bfb`, and the global default riding table at `0x0069b430`.
- IDA disassembly shows `dword_69B438` / generated `g_ridingDefinitionBuckets` is the `+0x08` pointer field of the 12-byte global table object at `0x0069b430`, not an independent global allocation. `LoadRidingDefinitions` passes `offset dword_69B430` to the helper at `0x005289d0`, then walks the `+0x08` entry pointer.
- 2026-05-26 IDA `py_eval` recheck expands [MonsterImageLibTables](by-file/MonsterImageLibTables.md) from the old allocation-only range to `0x00528950-0x00528d28`. Current active `class_MonsterImageLibTable_5289D0.cpp` / `class_MonsterImageLibTable_528BE0.cpp` omit modeled cleanup/unwind helpers at `0x00528950`, `0x00528a70`, `0x00528b60`, and `0x00528c80`.

Expected:

- Generated class output or generated documentation should account for ordinary destructor `0x004dc730` in addition to deleting destructor `0x004e68b0`.
- Generated vtable inventory should record `0x0061b6f4` instead of leaving `RidingImageLib` at `vtable_count: 0`.
- Generated global-data metadata should anchor `g_pRidingImageLib` to `0x0069b444` and model the riding definition globals as a 12-byte object at `0x0069b430` with a `+0x08` entry-pointer field rather than as two unrelated globals.
- Generated type/layout output should surface `RidingImageLib` offsets `+0x04`, `+0x08`, `+0x0c`, plus the `RidingDefinition`, `RidingBucket`, and `RidingBucketEntry` row layouts.
- Generated monster/riding table helper output should account for lifecycle helpers around the allocation/getter methods, not only the currently emitted allocation and lookup functions.

Impact:

- Added [g_pRidingImageLib](by-global/g_pRidingImageLib.md), [RidingDefinitionGlobalTable](by-global/RidingDefinitionGlobalTable.md), [singleton storage](by-memory/0x0069b444-0x0069b448.g_pRidingImageLib.md), [riding global table memory](by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md), [RidingImageLib ordinary destructor](by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md), [RidingImageLib singleton clear helper](by-memory/0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper.md), [RidingImageLib vtable](by-type/by-vtable/RidingImageLibVtable.md), [RidingImageLib layout](by-type/by-struct/RidingImageLibLayout.md), and [RidingDefinition](by-type/by-struct/RidingDefinition.md).
- Updated [RidingImageLib](by-file/RidingImageLib.md), [RidingImageLib class](by-class/RidingImageLib.md), [RidingImageLib memory](by-memory/0x004dc420-0x004e6980.RidingImageLib.md), [MonsterImageLibTables](by-file/MonsterImageLibTables.md), [EPFImageResources](by-file/EPFImageResources.md), [Application](by-file/Application.md), [client_dat_specifications](by-meta/client_dat_specifications.md), [client_new_rendering_mode](by-meta/client_new_rendering_mode.md), and [proposed source tree](by-project-structure/proposed-source-tree.md).
- 2026-05-26 follow-up: moved the table-helper memory page to [0x00528950-0x00528d28.MonsterImageLibTables](by-memory/0x00528950-0x00528d28.MonsterImageLibTables.md), added the missing lifecycle helpers, and raised the address-derived helper classes from low to medium documentation confidence.

Follow-up:

- Recheck generated output after Wave3 raw-function, vtable, global-data memory-range, and field-vs-global modeling fixes for `0x004dc730`, `0x004e5bf0`, `0x004e68b0`, `0x00528950`, `0x00528a70`, `0x00528b60`, `0x00528c80`, `0x0061b6f4`, `0x0069b430`, `0x0069b438`, `0x0069b444`, and the `RidingDefinition` row layout.

### 2026-05-26 - `RingBuffer` raw helper bytes are covered in metadata but omitted from active source bodies

Observed:

- Current `source-3/simroot_v2/util/RingBuffer.cpp` now emits the main `RingBuffer` methods and `RingBufferIterator` methods in one `util/RingBuffer.cpp` output.
- Current `source-3/simroot_v2/util/RingBuffer.meta_wave3` now correctly reports one `RingBuffer` vtable at `0x006230cc` and one `RingBufferIterator` vtable at `0x006230dc`.
- Current metadata/source maps track raw helper ranges `0x00556670-0x0055667a`, `0x005566a0-0x005566a8`, `0x005566b0-0x005566ba`, and `0x00556700-0x00556714` as reviewed `ida_raw_bytes`, but the active `.cpp` still has no source bodies for those helpers.
- 2026-05-26 IDA `py_eval` recheck confirms those starts are raw non-function starts in IDA. The first three are small empty/full predicates over `+0x14` capacity and `+0x1c` count; `0x00556700` computes an iterator previous/end position from the owning buffer write index and capacity.

Expected:

- Generated source or generated documentation should either emit these raw helper bodies as local/private helpers or explicitly list them as reviewed raw helper coverage in the emitted source comments.
- Future Wave3 function-boundary recovery should not drop these bytes simply because IDA has no function object at the starts.

Impact:

- Updated [RingBuffer](by-file/RingBuffer.md), [RingBuffer class](by-class/RingBuffer.md), [RingBufferIterator](by-class/RingBufferIterator.md), and [RingBuffer memory](by-memory/0x005563d0-0x005568c8.RingBuffer.md) to reflect the current fixed vtable metadata and the remaining raw-helper gap.

Follow-up:

- Recheck generated output after raw helper emission/boundary handling changes for `0x00556670`, `0x005566a0`, `0x005566b0`, and `0x00556700`.

### 2026-05-27 - `0x00430040` false Exchange/ClanBank starts are actually JsonCpp writer support

Observed:

- Existing Wave3/data notes already treated `0x00430041` and `0x00430058` as false starts inside the real helper at `0x00430040`, but the helper owner was still left as generic/unresolved support.
- IDA MCP reports the containing helper as `sub_430040`, size `0x52`, so the half-open range is `0x00430040-0x00430092`; the earlier `0x00430040-0x00430091` endpoint left one byte incorrectly uncovered.
- IDA MCP caller checks now show all real calls to `0x00430040` come from `0x0042f870`, now documented as JsonCpp `StyledWriter::writeValue`-style code inside [JsonCpp legacy writer core](by-memory/0x0042f3f0-0x00430040.JsonCppLegacyWriterCore.md).
- IDA MCP decompilation of `0x00430040` matches JsonCpp `StyledWriter::pushValue`-style behavior: it appends either to a child-value vector when the state flag is set or to the document string otherwise.

Expected:

- Wave3 ownership should not emit `ClanBankItemListPane::AppendEntryString` at `0x00430041` or `ExchangeMoneyEditControlPane::GetClassName` at `0x00430058` as project methods.
- The real helper at `0x00430040-0x00430092` should be treated as JsonCpp writer support or otherwise excluded from NexusTK-owned reconstruction.

Impact:

- Updated [generic string append helper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md), [JsonCpp legacy writer core](by-memory/0x0042f3f0-0x00430040.JsonCppLegacyWriterCore.md), [JsonCpp writer tail and OurReader prelude](by-memory/0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude.md), [JsonCpp](by-file/JsonCpp.md), [client libraries](by-meta/client_libraries.md), [by-memory ignored ledger](by-memory/-ignored.md), and [by-memory coverage](by-memory/-coverage-report.md).

### 2026-05-27 - `ClanStatusPane` scalar deleting destructor endpoint is short by one byte

Observed:

- Current `source-3/simroot_v2/class_ClanStatusPane.meta_wave3` and `class_ClanStatusPane.cpp.source_map.json` report method `0x0048c590` ending at `0x0048c63e`.
- IDA MCP `lookup_funcs` reports `sub_48C590` with size `0xaf`, so the end-exclusive address is `0x0048c63f`.
- Direct PE byte review of `E:\NTK\Resources\NexusTK\NexusTK.exe` shows `8b c6 5e 5d c2 04 00 cc 55 8b...` at `0x0048c638`, making `0x0048c63e` the final `00` immediate byte of `retn 04`; only `0x0048c63f` is alignment before `sub_48C640`.

Expected:

- Wave3 memory/source-map data for `ClanStatusPane::ScalarDeletingDestructor` should use `0x0048c590-0x0048c63f`.
- The byte at `0x0048c63e` should not be left as an uncovered/unknown gap.

Impact:

- Updated [Clan destructor band](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md), [by-memory ignored ledger](by-memory/-ignored.md), and [by-memory coverage](by-memory/-coverage-report.md).
- Converted the former `0x0048c63e-0x0048c640` UNKNOWN gap into a corrected function endpoint plus one-byte padding row `0x0048c63f-0x0048c640`.

Follow-up:

- Recheck generated output after Wave3 boundary fixes for method `0x0048c590` and remove this issue once the source map and metadata no longer use the short `0x0048c63e` endpoint.

### 2026-05-27 - Config raw table helpers are omitted before `InitializeConfigEntry`

Observed:

- The by-memory gap `0x0048e305-0x0048e480` was not empty. Direct PE byte review shows padding at `0x0048e305-0x0048e310`, a helper body at `0x0048e310-0x0048e408`, padding at `0x0048e408-0x0048e410`, a second helper body at `0x0048e410-0x0048e479`, and padding at `0x0048e479-0x0048e480`.
- `resources/exported_data/master_function_list.json` includes a Ghidra/GhidrAssist entry for `0x0048e310` summarized as a config wide-string table lookup/append helper, but active `simroot_v2` does not emit a source body for `0x0048e310`.
- No active generated source or metadata entry was found for the raw helper body at `0x0048e410`, which clears the same 100-row, `0x6894`-stride config table layout used by `Config::Config`.

Expected:

- Generated output should account for `0x0048e310-0x0048e479` as Config/RegistryConfig table-support code or explicitly mark it as reviewed raw helper coverage.
- The span should not remain an UNKNOWN gap and should not be attached to the preceding collection dialog island.

Impact:

- Added [Config raw table helpers](by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md).
- Updated [Config](by-file/Config.md), [Config class](by-class/Config.md), [Config and registry defaults](by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md), [by-memory ignored ledger](by-memory/-ignored.md), and [by-memory coverage](by-memory/-coverage-report.md).

Follow-up:

- Recheck generated output after Wave3 raw-helper recovery for `0x0048e310` and `0x0048e410`, and decide whether these should become private helpers in `config/Config.cpp` or be represented as reviewed raw coverage only.

### 2026-05-27 - Registry command-line parser island is omitted between defaults and persistence

Observed:

- The by-memory gap `0x0048f3f1-0x00491b30` was not one empty span. Direct PE byte review shows fifteen `0xcc` bytes at `0x0048f3f1-0x0048f400`, a source-authored helper island at `0x0048f400-0x00491b28`, and eight `0xcc` bytes at `0x00491b28-0x00491b30`.
- `resources/exported_data/master_function_list.json` lists starts throughout the island at `0x0048f400`, `0x0048f4d0`, `0x0048f6d0`, `0x0048fca0`, `0x00490200`, `0x00490510`, `0x00490810`, `0x00490b10`, `0x004910d0`, `0x00491450`, `0x00491790`, and `0x004918e0`.
- Export summaries and strings indicate command-line, login/session, DNS/host, port, `/lgi`, `/KWG`, and `/GameBill` parsing behavior, but this range was still represented as an UNKNOWN gap rather than reviewed project code.

Expected:

- Generated ownership should account for `0x0048f400-0x00491b28` as RegistryConfig/config-adjacent command-line/session startup helpers, or explicitly mark the island as reviewed raw helper coverage.
- The padding before and after the helper island should be ignored as compiler alignment, not treated as missing project code.

Impact:

- Added [Registry command-line parsers](by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md).
- Updated [RegistryConfig](by-file/RegistryConfig.md), [RegistryConfig class](by-class/RegistryConfig.md), [Config and registry defaults](by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md), [registry persistence and cleanup](by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md), [by-memory ignored ledger](by-memory/-ignored.md), and [by-memory coverage](by-memory/-coverage-report.md).

Follow-up:

- 2026-05-30 documentation update: the aggregate page was split into exact child by-memory pages after IDA MCP boundary/string/call checks. Still recheck generated output after Wave3 raw-helper recovery for `0x0048f400-0x00491b28` so ownership/import data can catch up with the documentation.

### 2026-05-27 - MSVC COM and CRT helper island was left as an UNKNOWN gap before `ConnStatusPane`

Observed:

- The by-memory gap `0x004941d5-0x00494520` included one byte that belongs to `ConfigEntryBlock::ReleaseOwnedBuffers`, plus a reviewed runtime/helper island and alignment padding.
- IDA MCP `lookup_funcs` reports `sub_494130` size `0xa6`, so `ConfigEntryBlock::ReleaseOwnedBuffers` ends at `0x004941d6`; the previous `0x004941d5` endpoint was short by one byte.
- IDA MCP reports helper starts at `0x004941e0`, `0x004943a0`, `0x00494440`, `0x004944a0`, `0x004944c0`, and `0x004944f0`, with `ConnStatusPane::ConnStatusPane` beginning at `0x00494520`.
- Decompilation matches MSVC COM smart-pointer support, `_freea` sentinel cleanup, and CRT formatting/scanning wrappers, including the already reviewed `WideStringScanf_4944F0` helper.

Expected:

- `ConfigEntryBlock::ReleaseOwnedBuffers` should use end-exclusive range `0x00494130-0x004941d6`.
- `0x004941e0-0x00494519` should be treated as reviewed MSVC COM/CRT support and ignored for NexusTK-owned reconstruction, not left as unknown project code.

Impact:

- Renamed/updated [registry persistence and cleanup](by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md).
- Added [MSVC COM and formatting helpers](by-memory/0x004941e0-0x00494519.MsvcComAndFormattingHelpers.md).
- Updated [Config](by-file/Config.md), [ConfigEntryBlock](by-class/ConfigEntryBlock.md), [RegistryConfig](by-file/RegistryConfig.md), [by-memory ignored ledger](by-memory/-ignored.md), and [by-memory coverage](by-memory/-coverage-report.md).

Follow-up:

- If Wave3 imports this island later, keep the helper functions excluded or mapped to MSVC/CRT support rather than attaching them to `ConnStatusPane`, registry persistence, or gameplay UI classes.

### 2026-05-27 - Static/control helper tail was left as an UNKNOWN gap before `Crasher`

Observed:

- The by-memory gap `0x0049b914-0x0049bae0` was not empty and started one byte too early.
- IDA MCP reports `sub_49B910` size `0x5`, so `StaticTextControlPane2::GetControlTypeId` ends at `0x0049b915`; byte `0x0049b914` is part of the `retn 8` immediate, not padding.
- IDA MCP reports additional real helper bodies at `0x0049b920`, `0x0049b930`, `0x0049b970`, `0x0049b9b0`, `0x0049b9f0`, `0x0049ba30`, and `0x0049baa0`, with `Crasher` beginning at `0x0049bae0`.

Expected:

- `StaticTextControlPane2` should use end-exclusive range `0x0049a410-0x0049b915`.
- `StaticTextControlPane::GetControlTypeId` should be documented as `0x0049b920-0x0049b925`.
- The scroll/selection offset helpers at `0x0049b930-0x0049ba2b` should be recovered as project code, while `0x0049ba30-0x0049bad9` should be treated as MSVC aligned allocation/free support.

Impact:

- Renamed/updated [StaticTextControlPane2](by-memory/0x0049a410-0x0049b915.StaticTextControlPane2.md).
- Added [StaticTextControlPane type id](by-memory/0x0049b920-0x0049b925.StaticTextControlPaneTypeId.md), [control-pane scroll offset helpers](by-memory/0x0049b930-0x0049ba2b.ControlPaneScrollOffsetHelpers.md), and [MSVC aligned allocation helpers](by-memory/0x0049ba30-0x0049bad9.MsvcAlignedArrayAllocationHelpers.md).
- Updated [StaticTextControlPane file](by-file/StaticTextControlPane.md), [StaticTextControlPane class](by-class/StaticTextControlPane.md), [StaticTextControlPane2 class](by-class/StaticTextControlPane2.md), [by-memory ignored ledger](by-memory/-ignored.md), and [by-memory coverage](by-memory/-coverage-report.md).

Follow-up:

- Recheck Wave3 range generation for fixed-return helpers ending in `retn 8`; at least this neighborhood had end-exclusive ranges that were one byte short.
- Resolve final owner/class names for the four `0x0049b930-0x0049ba2b` offset helpers after documenting caller ranges `0x00497780` and `0x00497c60`.

### 2026-05-27 - Checksum and critical-section helper tail was left as an UNKNOWN gap before `CriticalSectionLock`

Observed:

- The by-memory gap `0x0049bbef-0x0049bcf0` was not empty. It contains one byte of padding, four table-driven 16-bit checksum helper bodies, more padding, a critical-section API wrapper family, and final padding before `CriticalSectionLock`.
- IDA/raw disassembly shows checksum helpers at `0x0049bbf0`, `0x0049bc10`, `0x0049bc50`, and `0x0049bc70`; these use `word_66D480` and `word_66D680`.
- IDA MCP decompiles `0x0049bcb0` as an `InitializeCriticalSection` wrapper and disassembles `0x0049bcc0`, `0x0049bcd0`, and `0x0049bce0` as delete/enter/leave critical-section wrappers.

Expected:

- `0x0049bbf0-0x0049bca9` should be tracked as checksum helper code, not an UNKNOWN gap.
- `0x0049bcb0-0x0049bce8` should be tracked as synchronization helper code near `CriticalSectionLock`/`Monitor`.
- The padding at `0x0049bbef-0x0049bbf0`, `0x0049bca9-0x0049bcb0`, and `0x0049bce8-0x0049bcf0` should be ignored as alignment.

Impact:

- Added [checksum table helpers](by-memory/0x0049bbf0-0x0049bca9.ChecksumTableHelpers.md) and [critical-section API wrappers](by-memory/0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers.md).
- Updated [Monitor](by-file/Monitor.md), [CriticalSectionLock](by-class/CriticalSectionLock.md), [CriticalSectionLock memory](by-memory/0x0049bcf0-0x0049bd19.CriticalSectionLock.md), [by-memory ignored ledger](by-memory/-ignored.md), and [by-memory coverage](by-memory/-coverage-report.md).

Follow-up:

- Identify any indirect or table-based callers for the checksum helpers and decide whether `word_66D480`/`word_66D680` should get dedicated global/type documentation.

### 2026-05-27 - DAT manager find-entry forwarder was left as an UNKNOWN gap before `DATFileMgr`

Observed:

- The by-memory gap `0x0049bd19-0x0049bd30` was not empty. It contains padding at `0x0049bd19-0x0049bd20`, a small DAT manager forwarding wrapper at `0x0049bd20-0x0049bd2c`, and padding at `0x0049bd2c-0x0049bd30`.
- IDA/raw disassembly shows the wrapper loading `ecx = [ecx+4]` and tail-jumping to `_DATFileMgr::FindEntryByName` at `0x0049cad0`.
- IDA does not currently promote `0x0049bd20` as a function object, so generated coverage missed it between `CriticalSectionLock` and `DATFileMgr::DATFileMgr`.

Expected:

- `0x0049bd20-0x0049bd2c` should be tracked as a public `DATFileMgr` wrapper over the internal manager's name lookup method.
- The surrounding `0xcc` bytes should be ignored as alignment padding.

Impact:

- Added [DATFileMgr find-entry forwarder](by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md).
- Updated [DATFileMgr](by-file/DATFileMgr.md), [DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md), [by-memory ignored ledger](by-memory/-ignored.md), and [by-memory coverage](by-memory/-coverage-report.md).

Follow-up:

- When `_DATFileMgr::FindEntryByName` is rewritten, keep this wrapper as the public `DATFileMgr` forwarding method rather than a free helper.

### 2026-05-27 - DATManagers aggregate end was one byte short before `DescPane`

Observed:

- The by-memory UNKNOWN gap `0x0049d6ec-0x0049d6f0` was partly caused by a one-byte-short `DATManagers` aggregate endpoint.
- IDA MCP reports `sub_49D5E0` / `_DATFileMgr::FindNodeByKey` size `0x10d`, so the function's end-exclusive bound is `0x0049d6ed`.
- Raw bytes show `c2 08 00` at `0x0049d6ea-0x0049d6ec`; byte `0x0049d6ec` is part of the `retn 8` immediate, not padding. The following `0x0049d6ed-0x0049d6f0` bytes are `0xcc` alignment before `DescPane`.

Expected:

- `DATManagers` should use range `0x0049bd30-0x0049d6ed`.
- Only `0x0049d6ed-0x0049d6f0` should be ignored as alignment padding.

Impact:

- Renamed/updated [DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md).
- Updated [by-memory ignored ledger](by-memory/-ignored.md) and [by-memory coverage](by-memory/-coverage-report.md).

Follow-up:

- Recheck generated end-exclusive ranges around short `retn imm16` tails when UNKNOWN gaps start on the final byte of a nearby function.

### 2026-05-27 - Single-byte padding was left as UNKNOWN between `DescPane` and `DialogPane`

Observed:

- The by-memory UNKNOWN gap `0x0049d89f-0x0049d8a0` is a single alignment byte, not undocumented project code.
- IDA MCP reports the `DescPane` scalar deleting destructor at `0x0049d840` with size `0x5f`, ending at `0x0049d89f`, and `DialogPane` starts at `0x0049d8a0`.
- Raw bytes at `0x0049d89c` are `c2 04 00 cc 55 8b ec 6a`, confirming `0x0049d89f` is the only padding byte.

Expected:

- `0x0049d89f-0x0049d8a0` should be ignored as alignment padding.

Impact:

- Updated [by-memory ignored ledger](by-memory/-ignored.md) and [by-memory coverage](by-memory/-coverage-report.md).

Follow-up:

- None unless a later automated range generator reintroduces this as an UNKNOWN row.

### 2026-05-27 - `DialogPane` aggregate end was one byte short before `AlertPane`

Observed:

- The by-memory UNKNOWN gap `0x0049fead-0x0049feb0` was partly caused by a one-byte-short `DialogPane` endpoint.
- IDA MCP reports `sub_49FE20` size `0x8e`, so the final `DialogPane` method in the aggregate ends at `0x0049feae`.
- Raw bytes show `c3 cc cc` at `0x0049fead-0x0049feaf`; byte `0x0049fead` is the `retn`, while `0x0049feae-0x0049feb0` is padding before `AlertPane`.

Expected:

- `DialogPane` should use range `0x0049d8a0-0x0049feae`.
- Only `0x0049feae-0x0049feb0` should be ignored as alignment padding.

Impact:

- Renamed/updated [DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md).
- Updated [by-memory ignored ledger](by-memory/-ignored.md) and [by-memory coverage](by-memory/-coverage-report.md).

Follow-up:

- Recheck generated end-exclusive ranges around single-byte `retn` tails when an UNKNOWN gap starts exactly on the last instruction byte.

### 2026-05-27 - Padding was left as UNKNOWN between `AlertPaneCore` and `VersatileAlertPane`

Observed:

- The by-memory UNKNOWN gap `0x004a0686-0x004a0690` is alignment padding, not undocumented project code.
- IDA MCP reports `sub_4A0580` size `0x106`, so the final `AlertPaneCore` method ends at `0x004a0686`.
- Raw bytes after the `retn 8` show ten `0xcc` bytes before `VersatileAlertPane` starts at `0x004a0690`.

Expected:

- `0x004a0686-0x004a0690` should be ignored as compiler/linker alignment padding.

Impact:

- Updated [by-memory ignored ledger](by-memory/-ignored.md) and [by-memory coverage](by-memory/-coverage-report.md).

Follow-up:

- None unless a later automated range generator reintroduces this as an UNKNOWN row.

### 2026-05-27 - Padding was left as UNKNOWN between `VersatileAlertPane` and `ModelessDialogPane`

Observed:

- The by-memory UNKNOWN gap `0x004a0752-0x004a0760` is alignment padding, not undocumented project code.
- IDA/raw disassembly shows the final `VersatileAlertPane` callback in the neighborhood returning at `0x004a0751`.
- Raw bytes from `0x004a0752` through `0x004a075f` are all `0xcc`, followed by the `ModelessDialogPane` prologue at `0x004a0760`.

Expected:

- `0x004a0752-0x004a0760` should be ignored as compiler/linker alignment padding.

Impact:

- Updated [by-memory ignored ledger](by-memory/-ignored.md) and [by-memory coverage](by-memory/-coverage-report.md).

Follow-up:

- None unless a later automated range generator reintroduces this as an UNKNOWN row.

### 2026-05-27 - ModelessDialogPane switch table was left as UNKNOWN before `VersatileAlertPane`

Observed:

- The by-memory UNKNOWN gap `0x004a0c8e-0x004a0cb0` is not handwritten code. It contains two alignment bytes followed by a switch jump table for `ModelessDialogPane::HandleMouseEvent`.
- IDA MCP reports `sub_4A0840` size `0x44e`, ending at `0x004a0c8e`.
- `xrefs_to 0x004a0c90` reports a data reference from `sub_4A0840` at `0x004a0871`, and raw bytes at `0x004a0c90` are eight little-endian addresses inside the handler.

Expected:

- `0x004a0c8e-0x004a0c90` should be ignored as alignment padding.
- `0x004a0c90-0x004a0cb0` should be ignored as compiler-generated switch jump-table data, regenerated from recovered source rather than hand-ported.

Impact:

- Updated [ModelessDialogPane memory](by-memory/0x004a0760-0x004a0c8e.ModelessDialogPane.md), [by-memory ignored ledger](by-memory/-ignored.md), and [by-memory coverage](by-memory/-coverage-report.md).

Follow-up:

- When rewriting the `0x004a0840` handler, keep the source-level `switch` structure clear enough for the compiler to regenerate this jump table naturally.

### 2026-05-27 - Help-pane singleton close helpers were left as UNKNOWN before `DialogSessionCore`

Observed:

- The by-memory UNKNOWN gap `0x004a0d37-0x004a0d80` contains padding plus two real helper functions at `0x004a0d40` and `0x004a0d60`.
- IDA MCP decompiles `0x004a0d40` as a `dword_69AE04` / `g_pItemHelpPane` null-check followed by virtual slot `0` call with flag `1`.
- IDA MCP decompiles `0x004a0d60` as a `dword_69AE00` / `g_pSimpleHelpPane` null-check followed by virtual slot `0` call with flag `1`.
- Surrounding bytes are `0xcc` alignment between the previous `VersatileAlertPane` destructor island and `DialogSessionCore`.

Expected:

- `0x004a0d40-0x004a0d71` should be tracked as help-pane singleton close helper code.
- `0x004a0d37-0x004a0d40` and `0x004a0d71-0x004a0d80` should be ignored as alignment padding.

Impact:

- Added [HelpPane singleton close helpers](by-memory/0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers.md).
- Updated [HelpPanes](by-file/HelpPanes.md), [g_pItemHelpPane](by-global/g_pItemHelpPane.md), [g_pSimpleHelpPane](by-global/g_pSimpleHelpPane.md), [by-memory ignored ledger](by-memory/-ignored.md), and [by-memory coverage](by-memory/-coverage-report.md).

Follow-up:

- Use these helpers as cleanup/replacement calls when rewriting item menu and simple help popup flows.

### 2026-05-27 - Padding was left as UNKNOWN between `DialogSessionCore` and DIBitmap loaders

Observed:

- The by-memory UNKNOWN gap `0x004a15f8-0x004a1600` is alignment padding, not undocumented project code.
- IDA MCP reports the final `DialogSessionCore` function `sub_4A1500` size `0xf8`, ending at `0x004a15f8`.
- Raw bytes after the `retn 4` are eight `0xcc` bytes before the DIBitmap/PCX loader range starts at `0x004a1600`.

Expected:

- `0x004a15f8-0x004a1600` should be ignored as compiler/linker alignment padding.

Impact:

- Updated [by-memory ignored ledger](by-memory/-ignored.md) and [by-memory coverage](by-memory/-coverage-report.md).

Follow-up:

- None unless a later automated range generator reintroduces this as an UNKNOWN row.

### 2026-05-27 - DIBitmap aggregate end was one byte short before `DirectX`

Observed:

- The by-memory UNKNOWN gap `0x004a1b5d-0x004a1b60` was partly caused by a one-byte-short `DIBitmapAndPcxLoaders` endpoint.
- IDA MCP maps `0x004a1b5d` to `sub_4A1B10`; this is the final byte of the `retn 4` instruction in the DIBitmap scalar deleting destructor.
- Raw bytes show `c2 04 00 cc cc` at `0x004a1b5b-0x004a1b5f`, so only `0x004a1b5e-0x004a1b60` is padding.

Expected:

- `DIBitmapAndPcxLoaders` should use range `0x004a1600-0x004a1b5e`.
- `0x004a1b5e-0x004a1b60` should be ignored as compiler/linker alignment padding.

Impact:

- Renamed/updated [DIBitmapAndPcxLoaders](by-memory/0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders.md).
- Updated [by-memory ignored ledger](by-memory/-ignored.md) and [by-memory coverage](by-memory/-coverage-report.md).

Follow-up:

- Recheck generated end-exclusive ranges around `retn imm16` tails when UNKNOWN gaps start on the last instruction byte.

### 2026-05-27 - Padding was left as UNKNOWN between `DirectX` and `EmployeeDialogPanes`

Observed:

- The by-memory UNKNOWN gap `0x004a1d6a-0x004a1d70` is alignment padding, not undocumented project code.
- IDA MCP reports `sub_4A1B60` size `0xf6`, ending at `0x004a1d6a`.
- Raw bytes after the final `retn 4` are six `0xcc` bytes before `EmployeeDialogPanes` starts at `0x004a1d70`.

Expected:

- `0x004a1d6a-0x004a1d70` should be ignored as compiler/linker alignment padding.

Impact:

- Updated [by-memory ignored ledger](by-memory/-ignored.md) and [by-memory coverage](by-memory/-coverage-report.md).

Follow-up:

- None unless a later automated range generator reintroduces this as an UNKNOWN row.

### 2026-05-27 - Encoder/codec/error-wrapper alignment and MSVC runtime helpers were left as UNKNOWN

Observed:

- Several by-memory UNKNOWN rows around the employee dialog, binary codec, parser, and error-wrapper neighborhood were not NexusTK project code.
- `0x004a4e6b-0x004a4e70`, `0x004a5621-0x004a5630`, and `0x004a5e54-0x004a5e60` are `0xcc` alignment spans between confirmed function clusters.
- `0x004a609f-0x004a60d0` contains one leading `0xcc`, a raw helper-shaped body at `0x004a60a0-0x004a60c0`, IDA-modeled `unknown_libname_12` at `0x004a60c0-0x004a60cb`, and final `0xcc` padding before `ErrorWrappers`.
- IDA decompilation labels `0x004a60c0` as Microsoft Visual C runtime and decompiles it as `HIDWORD(a1) | a1`; `xrefs_to` currently reports no direct xrefs to either helper start.

Expected:

- The pure `0xcc` spans should be ignored as compiler/linker alignment padding.
- `0x004a60a0-0x004a60cb` should be tracked as runtime/compiler helper code, not reconstructed as NexusTK source.

Impact:

- Added [MSVC int64 runtime helpers](by-memory/0x004a60a0-0x004a60cb.MsvcInt64RuntimeHelpers.md).
- Updated [by-memory ignored ledger](by-memory/-ignored.md) and [by-memory coverage](by-memory/-coverage-report.md).

Follow-up:

- If future compiler/runtime-library matching identifies exact helper names for `0x004a60a0` or `0x004a60c0`, rename the ignored helper page and update its evidence, but keep it excluded from handwritten NexusTK reconstruction.

### 2026-05-28 - MainMenu opcode `0x66` helper and adjacent raw UI helpers need IDA-backed ownership

Observed:

- `simroot_v2/class_MainMenuPane.cpp` declares `HandleAnsiTextDialogPacket_502E30` and routes opcode decimal `102` (`0x66`) to it, but the generated prototype is marked as unresolved during grading.
- IDA MCP confirms the real helper range is `0x00502e30-0x0050305c`, called from `MainMenuPane::OnServerMessage` at `0x004f74c2`, and that it constructs `UrlAlertPane` at `0x00503034`.
- IDA MCP also confirms nearby helper `0x00502e10-0x00502e21` is called from `MainMenuPane::OnServerMessage` at `0x004f733a` and tears down the active `g_pScreenDimmer`.
- Raw bytes at `0x00503060-0x005031e1` decode as three function-shaped UI/resource text helpers, but IDA currently has no function objects or xrefs to those starts.

Expected:

- Keep `0x00502e10-0x0050305c` documented as `MainMenuPane` packet helper code and do not move it into `AlertPanes` just because it constructs `UrlAlertPane`.
- Keep `0x00503060-0x005031e1` as a preserved raw helper cluster until caller/vtable evidence proves an owner.

Impact:

- Added [MainMenuAnsiTextDialogPacketHelpers](by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md).
- Added [UnreferencedUiResourceTextHelpers](by-memory/0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md).
- Updated by-memory coverage and ignored alignment ranges for the former `0x00502d05-0x005031f0` UNKNOWN gap.

Follow-up:

- Recheck `HandleAnsiTextDialogPacket_502E30` naming and exact `dword_69B3D0` ownership during a future MainMenu/packet-global cleanup.
- Search for non-standard function tables, EH references, or manually recovered vtable slots that may reference `0x00503060`, `0x005030c0`, or `0x00503110`.
