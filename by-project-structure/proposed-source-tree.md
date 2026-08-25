*** UID:0001R1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Proposed Source Tree

## UID0000LO Accepted Item/List Source-Tree Closure - 2026-08-14

The current tree folds MyItemListPane into `ui/dialogs/ItemDialogs.cpp` and
`ItemDialogs.h`; the former standalone `MyItemListPane.cpp` entry is retired as
a historical split alias. Within ItemDialogs, AddItemDialog, MyItemListPane,
and AddItemWithCountDialog emit in positions `10/20/30`.

The shared dependency route is explicit: `ui/core/ScrollBar.cpp` pairs with
`ScrollBar.h`, whose generated H owns the ScrollablePane declaration, and
`ui/controls/ListPane.cpp` pairs with `ListPane.h`, whose generated H owns the
ListPane class and ordered child declarations. Derived feature panes consume
these headers rather than recreating either base declaration. The finalized
standalone sibling `SimpleListPane.cpp` pairs with `SimpleListPane.h`, and that
header includes `ListPane.h` for the complete base declaration.

## Status

- Confidence: medium
- Scope: initial source-layout hypothesis for Wave3 file ownership work
- Evidence basis: `source-3\simroot_v2`, Wave2 readonly class/global JSON, Wave3 project status counts, generated `builder\NexusTK.vcproj`, current file-family naming, and targeted IDA MCP checks where noted.

## Observed Baseline

- Wave3 project status reported 582 classes, 196 globals, and 782 file containers.
- `simroot_v2` currently emits mostly one-class/default files such as `class_Browser.cpp`.
- The older generated `builder\NexusTK.vcproj` lists many bare one-class `.cpp` files under `simroot`, which is generated structure, not strong original source layout evidence.
- Wave2 `Original.source_file` is also mostly one class per file. Only `TimerMgr.cpp` currently has two imported classes (`TimerMgr`, `TimerMgrTimerQueue`), so original grouping must come from subsystem evidence rather than trusting that field alone.
- Every `.cpp` name in the top-level proposed tree now has a same-name [by-file](../by-file) page. Some pages are split candidates or placeholders that redirect to stronger grouped docs; their existence means "indexed for source-layout review", not "migration-ready".

## Tree Visibility Convention

When updating this tree, keep likely file contents visible by nesting major owned items under the file entry when practical. This includes classes, globals, large helper structs, callback tables, vtables, and major data tables that should belong to the file but should not appear as standalone original source files.

Use this style for future edits where the ownership is useful to see:

```text
Subsystem/
  SourceFile.cpp
    ClassName
    HelperStructName
    g_moduleGlobal
    VtableOrCallbackTable
```

Do not batch-rewrite the existing tree only to add nested contents. Add nesting opportunistically when a file entry is already being corrected, renamed, split, merged, or otherwise researched.

## Proposed Top-Level Layout

```text
NexusTK/
  app/
    Application.cpp
    ChangeMan.cpp
    MiscWorkThread.cpp
    IdleWatcher.cpp
    MSGHandler.cpp
    StartupWindow.cpp
    StartupLogoPanes.cpp
    WinMain.cpp
  auth/
    PasswordGuard.cpp
  security/
    CheatDetector.cpp
    VirusChecker.cpp
  config/
    Config.cpp
    RegistryConfig.cpp
  localization/
    LanguageMan.cpp
  metadata/
    MetaMan.cpp
  input/
    InputMan.cpp
    KeySpeedMgr.cpp
    IMEPanes.cpp
  platform/
    PlatformApi.cpp
    AutoInit.cpp
    ExceptionHandler.cpp
    Crasher.cpp
  patch/
    PatchPane.cpp
  profile/
    ProfileStorage.cpp
    ProfileDialog.cpp
  login/
    MainMenuPane.cpp
    BackStoryDialogPane.cpp
    HistoryViewingPane.cpp
    NewHistoryDialogPane.cpp
    StaffsDialogPane.cpp
    ForcedInformMessageDialog.cpp
    LoginDialogPane.cpp
    ServerSelectPane.cpp
    TerminalPane.cpp
    PhoneBookDialog.cpp
    UserInfoDialogPane.cpp
    NewUserDialogPane.cpp
    ChangePasswordDialogPane.cpp
    CreateUserDialogPane.cpp
    UserCreateAppearanceControls.cpp
    NewCreateUserDialogPane.cpp
    NewUserDialogPane2.cpp
    NewUserMiscDialogPane.cpp
    NewUserShapeSelectControlPane.cpp
  browser/
    Browser.cpp
  ui/
    MainUiGraph.cpp
    InterfaceEfx.cpp
    core/
      Pane.cpp
      BlackHole.cpp
      Layer.cpp
      RectBounds.cpp
      Region.cpp
      ScreenPane.cpp
      ScreenDimmer.cpp
      ScreenFadeOut.cpp
      VideoPlayerPane.cpp
      DialogPane.cpp
      ModelessDialogPane.cpp
      ControlPane.cpp
      PanelPane.cpp
      Event.cpp
      EventDispatcher.cpp
      FrameMgr.cpp
      FrameChrome.cpp
      ScrollBar.h
      ScrollBar.cpp
      ScrollCollectionPane.cpp
    menu/
      PopupMenuControls.cpp
      RightButtonMenuPane.cpp
      VoteMenuPane.cpp
      MenuVarietyPanes.cpp
    dialogs/
      MerchantDialogPane.cpp
      ItemDialogs.cpp
      ItemMenuDialogs.cpp
      EmployeeDialogPane.cpp
      ExchangeDialog.cpp
      RankingDialog.cpp
      SpellMenuDialogs.cpp
      InputPanes.cpp
      NumberInputDialog.cpp
      ItemActionInputPanes.cpp
      TextMenuDialogs.cpp
      ArgumentedMenuDialogs.cpp
      ArgumentedItemInputDialogs.cpp
      HeadSelectDialog.cpp
      TextDialog.cpp
      EditablePaperPane.cpp
      TextPad.cpp
      NexonclubProxyDialog.cpp
      NexonclubRegistrationDialog.cpp
      CommandInputPanes.cpp
      SelfSaveOKPane.cpp
      PowerDialogPane.cpp
      AlertPanes.cpp
      QuitDialogs.cpp
      MessageDialogs.cpp
      MessageShowPane.cpp
      MailDialogs.cpp
      BoardDialogs.cpp
      BulletinSession.cpp
      BulletinReplyAlerts.cpp
      WebBoardDialog.cpp
      NewPredefinedFormArticleDialog.cpp
      TransferServerDialogPane.cpp
      MusicControlDialog.cpp
      FolderSelectDialog.cpp
      OptionPane.cpp
      TargetOptionDialog.cpp
      MacroDialogs.cpp
    inventory/
      InventoryPane.cpp
      NewInventoryPane.cpp
      SpellInventoryPane.cpp
      NewSpellInventoryPane.cpp
      ScrollSpellInventoryPane.cpp
      InventoryScrollPane.cpp
    controls/
      ButtonControlPane.cpp
      PrettyButtonControlPane.cpp
      SpecializedButtonPanes.cpp
      ProgressBarControlPane.cpp
      NumericStringControlPane.cpp
      RectangleControlPane.cpp
      TextButtonControlPane.cpp
      TextButtonControlPane.h
      CheckBoxControlPane.cpp
      StaticTextControlPane.cpp
      FontStyle.cpp
      FontStyle.h
      DescPane.cpp
      HelpPanes.cpp
      ScrolledTextControlPane.cpp
      ScrolledPictureControlPane.cpp
      TextEditPane.cpp
      TextEditControlPane.cpp
      TextFilter.cpp
      ScrollableControlPane.cpp
      ScrollVolumePane.cpp
      ListPane.h
      ListPane.cpp
      SimpleListPane.h
      SimpleListPane.cpp
      FolderTreePane.h
      FolderTreePane.cpp
      EPFImageControlPane.cpp
      ObjectImageControlPane.cpp
    diagnostics/
      FpsPane.cpp
    panels/
      GeneralPurposePanel.cpp
      SelfLookPane.cpp
      SpelledPane.cpp
      LegendPane.cpp
      UserPane.cpp
      BowGaugeObjectPane.cpp
      ParcelPane.cpp
      CollectionPane.cpp
      UserLookPane.cpp
      UserStatusPane.cpp
      SoundStatusPane.cpp
      SoundStatusPane.h
      HourPane.cpp
      IconsPane.cpp
      TabPane.cpp
      TotemFrame.cpp
  render/
    DirectX.cpp
    GrafPort.cpp
    DIBitmap.cpp
    ImageLoaders.cpp
    ImageWriters.cpp
    Surface.h
    Surface.cpp
    ScreenshotCapture.cpp
    SoftwareBlend16.cpp
    AlphaMaskSurface.cpp
    IntAlphaSurface.cpp
    Palette.cpp
    Effects.cpp
    Motion.cpp
    ImageLib.cpp
    EPFTileContext.h
    EPFTileContext.cpp
    ResourceLayoutTable.cpp
    ImageFrameTable.cpp
    FontImageLib.cpp
    MapTileImageLib.cpp
    StaticObjImageLib.cpp
    EffectObjImageLib.cpp
    ItemObjImageLib.cpp
    HumanImageLib.cpp
    NewHumanImageLib.cpp
    MonsterImageLib.cpp
    MonsterImageLibTables.cpp
    RidingImageLib.cpp
    LightObjImageLib.cpp
  archive/
    DATFile.cpp
    DATFileMgr.cpp
  audio/
    SoundManager.cpp
    SoundManager.h
    MidiPlayer.cpp
    MidiPlayer.h
  third_party/
    lodepng.cpp
    libjpeg/
      jconfig.h
      jinclude.h
      jmorecfg.h
      jpeglib.h
      jpegint.h
      jerror.h
      jversion.h
      jmemsys.h
      jcapimin.c
      jcapistd.c
      jcinit.c
      jcmarker.c
      jcparam.c
      jcomapi.c
      jdatadst.c
      jdapimin.c
      jdapistd.c
      jdinput.c
      jdmarker.c
      jdmaster.c
      jutils.c
      jmemmgr.c
      jmemnobs.c
      jdcoefct.c
      jdmainct.c
      jdhuff.c
      jdphuff.c
      jddctmgr.c
      jdpostct.c
      jdsample.c
      jdcolor.c
      jdmerge.c
      jquant1.c
      jquant2.c
      jcmainct.c
      jccoefct.c
      jchuff.c
      jcphuff.c
      jcdctmgr.c
      jcprepct.c
      jcsample.c
      jccolor.c
      jcmaster.c
      jidctint.c
      jidctfst.c
      jidctflt.c
      jidctred.c
      jfdctint.c
      jfdctfst.c
      jfdctflt.c
    jsoncpp/
      include/json/
        assertions.h
        autolink.h
        config.h
        features.h
        forwards.h
        json.h
        reader.h
        value.h
        version.h
        writer.h
      src/lib_json/
        json_reader.cpp
        json_tool.h
        json_value.cpp
        json_valueiterator.inl
        json_writer.cpp
    zlib/
      adler32.c
      compress.c
      crc32.c
      deflate.c
      infblock.c
      infcodes.c
      inffast.c
      inflate.c
      infutil.c
      inftrees.c
      trees.c
      uncompr.c
      zutil.c
  network/
    Socket.cpp
    PacketBuffer.cpp
    FileDownloader.cpp
    ProtocolSend.cpp
    ConnStatusPane.cpp
    ReconnectDialog.cpp
  cashshop/
    CashShopRequest.cpp
    ItemCatalog.cpp
    FittingRoom.cpp
  map/
    BackPane.cpp
    MapPane.cpp
    ObjectList.cpp
    ObjectStatusBlob.cpp
    ObjectPane.cpp
    ItemObjectPane.cpp
    StaticObjectPane.cpp
    LightingObjectPane.cpp
    SoundObjectPane.cpp
    AttachedObjectPane.cpp
    LivingObjectPane.cpp
    GameServerConfig.cpp
    PhotoPane.cpp
    MapNamePane.cpp
    MapRefreshDimmer.cpp
    TimerPane.cpp
    WeatherLayerPane.cpp
    FieldMapPane.cpp
    WorldMapPane.cpp
    MiniMap.cpp
  social/
    Chatting.cpp
    SystemMessagePanes.cpp
    SayInputPanes.cpp
    BlockListenInputPanes.cpp
    UserListDialogPane.cpp
    FriendListDialog.cpp
    Group.cpp
    Clan.cpp
    ClanBank.cpp
  util/
    LObject.h
    StringBase.h
    Tree.h
    LObject.cpp
    FunctionObjects.cpp
    AUTOBUF.h
    ProtectedArray.h
    List.cpp
    # LinkedList helper bodies are non-emitting STL/Dinkumware support; no standalone source file.
    Queue.cpp
    # Deque helper bodies are compiler/STL support; no standalone Deque.cpp.
    CachedHashTable.cpp
    PrimeNumberGenerator.h
    PrimeNumberGenerator.cpp
    SortedList.cpp
    HierList.cpp
    Thread.cpp
    RingBuffer.cpp
    Monitor.cpp
    CriticalSection.cpp
    CriticalSection.h
    WaitableTimer.cpp
    PoolAllocator.h
    PoolAllocator.cpp
    TimerMgr.cpp
    StringUtil.cpp
    StringBase.cpp
    BinaryCodec.cpp          # complete adjacent Encoder/Decoder implementation
    BinaryCodec.h            # complete standalone 0x14 Encoder/Decoder declarations
    File.cpp
    StdioFile.cpp
    PathUtil.h
    PathUtil.cpp
    MD5.cpp
    Crc16.cpp
    AesBlockCipher.cpp
    Error.cpp
```

This is a working reconstruction map, not a final declaration of original paths.

## Strong Initial Modules

### `app/Application.cpp`

See [UID:0000HG][Application](by-file/Application.md). This is the process-level shell module:

- `Application` owns singleton lifecycle, window creation, patch continuation, DAT validation, DirectDraw entry, message loop, license validation, startup, and shutdown.
- [UID:0001R6][application-startup-dat-archives](by-resource/application-startup-dat-archives.md) documents the product-specific fixed, numbered, music, BINT, and world-map archive load order that belongs with this startup module.
- [UID:0000T5][LoadIndexedDATSeries](by-global/LoadIndexedDATSeries.md) is a startup helper in the `0x00467410-0x004674ed` range that scans numbered DAT archive families for `Application::Initialize`.
- `BaramApp` owns the game-specific activate/deactivate policy for map-pane visibility, event timers, background work, keyboard restore, and audio pause/resume.
- [UID:0000I2][ChangeMan](by-file/ChangeMan.md) is constructed by `Application::Initialize` and owns the app-wide change/message listener router.
- [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md) is constructed by `Application::Initialize` and owns the app-wide miscellaneous worker for folder browsing, HTTP fetch, and NCA auth/update tasks.
- [UID:0000LM][MSGHandler](by-file/MSGHandler.md) is a small application message-target swap helper and should remain in the app folder even if emitted as a separate `MSGHandler.cpp`.
- [UID:0000K0][IdleWatcher](by-file/IdleWatcher.md) is constructed by `Application::Startup`, but should stay as a startup-owned helper rather than being absorbed into the large application shell by default.
- [UID:0000YT][0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat](by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md) is called only by `Application::RunMessageLoop`; keep it in `Application.cpp` or a small adjacent app timing helper, not in `Socket`, `CashShopRequest`, `ExceptionHandler`, or `CheatDetector`.
- [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md) and [UID:0000II][Crasher](by-file/Crasher.md) are constructed and cleaned up by `Application`, but their source ownership belongs with platform/crash diagnostics rather than the app shell.
- [UID:0000UF][DestroyDATFileMgr_467380](by-item/DestroyDATFileMgr_467380.md) and [UID:0000UG][DestroyExceptionHandler_4673A0](by-item/DestroyExceptionHandler_4673A0.md) are paired fatal resource-load cleanup helpers. Keep the owned objects in `archive/DATFileMgr.cpp` and `platform/ExceptionHandler.cpp`; the helper bodies may remain near application/fatal-load glue if later source evidence supports that.

Rationale: IDA MCP confirms the main `Application` method boundaries, shows `Startup` constructing the render/UI/input singleton managers, shows `Application::Initialize` constructing `ChangeMan`, `ExceptionHandler`, and `Crasher`, and shows `BaramApp` activation methods adjacent to the application lifecycle range. The 2026-05-25 IDA MCP pass confirms [UID:0000YX][0x00467410-0x004674ed.LoadIndexedDATSeries](by-memory/0x00467410-0x004674ed.LoadIndexedDATSeries.md) is called only by `Application::Initialize`, and the surrounding [UID:0001R6][application-startup-dat-archives](by-resource/application-startup-dat-archives.md) inventory is product startup policy even though it uses the DAT manager API. The same pass confirms the `0x00467380`/`0x004673a0` cleanup helpers are small paired failure cleanup bodies, not image-library ownership. A 2026-05-26 IDA MCP recheck confirms [UID:0000YT][0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat](by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md) has exactly one direct caller, `Application::RunMessageLoop` at `0x00464d26`, despite its network and crash-diagnostic dependencies. Wave3's `BaramApp::BaramApp` boundary at `0x004f5f20` is not an IDA function and must be reviewed before bulk renaming.

### `app/ChangeMan.cpp`, `app/MiscWorkThread.cpp`, `app/IdleWatcher.cpp`, and `app/MSGHandler.cpp`

See [UID:0000I2][ChangeMan](by-file/ChangeMan.md), [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md), [UID:0000K0][IdleWatcher](by-file/IdleWatcher.md), and [UID:0000LM][MSGHandler](by-file/MSGHandler.md). These are small app-adjacent helper modules:

- `ChangeMan` owns the singleton change/message subscription router at `0x0047ec70-0x0047efae`, [UID:0001P4][0x0067ab2c-0x0067ab30.g_pChangeMan](by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md), the 8-byte [UID:0001TW][ChangeManLayout](by-type/by-struct/ChangeManLayout.md), and [UID:0000ZX][0x0047ed50-0x0047ee18.ChangeManRegistrationMethods](by-memory/0x0047ed50-0x0047ee18.ChangeManRegistrationMethods.md), with application wrapper methods at [UID:000199][0x004f4b30-0x004f4b6c.LObjectChangeManRegisterWrappers](by-memory/0x004f4b30-0x004f4b6c.LObjectChangeManRegisterWrappers.md) and [UID:00019B][0x004f4b70-0x004f4b86.LObjectForwardMessage](by-memory/0x004f4b70-0x004f4b86.LObjectForwardMessage.md).
- `MiscWorkThread` owns the singleton background worker at `0x005277c0-0x005285dd`, with WinInet HTTP fetches, NCA auth/update probes, and shell browse-directory notification flow.
- `IdleWatcher` owns the startup-created idle/timer watcher singleton at `0x004cfe60-0x004cffae`, with two disabled adjustor thunks at `0x004cff37` and `0x004cff42`.
- `MSGHandler` owns application message-handler swapping and generic dispatch forwarding at `0x00528d60-0x00528e55`; the nested `0x00528de0-0x00528dec` BrowserControlPaneOld fallback bridge is routed through the Browser module because its only code caller is the old browser message handler.

Rationale: these are app-owned helpers with direct application lifecycle/dispatch relationships, but they are not general application shell logic. `MiscWorkThread` has network dependencies, but its singleton ownership and mixed app tasks fit better as an app background-service module than as a socket/transport source file. These may become private classes in `Application.cpp` if later source evidence shows the original project grouped small helpers there.

### `app/StartupWindow.cpp`

See [UID:0000O5][StartupWindow](by-file/StartupWindow.md). This is the pre-game update/news notice module:

- `StartupWindow` owns the small notice HWND, update-check message loop, button WndProc, and update/close result handoff to `_WinMain@16`.
- It embeds [UID:0000HV][Browser](by-file/Browser.md) / `BrowserWindow` for the news panel but should not own browser COM/OLE implementation.
- It fetches update metadata and minimap hash data with libcurl, then delegates minimap persistence to [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md).
- It owns [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md) at `0x00581b80` as private libcurl glue; the callback is not libcurl source.
- It consumes [UID:0000UZ][LoadPcxImage_004A17B0](by-item/LoadPcxImage_004A17B0.md) for `brm_*.pcx` notice assets; PCX loading remains [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md) code.

Rationale: IDA MCP confirms constructor and `RunUpdateCheck` are only called from `_WinMain@16`, and confirms the notice/update neighborhood around `0x005807d0-0x0058206e`. The curl callback at `0x00581b80` has data xrefs from `RunUpdateCheck` callback setup sites at `0x00580c6f` and `0x00580efb`. Several raw helper starts in `0x005815b0-0x00581b7f` are real code but not current IDA functions, so migrate this module only with the boundary caveats from [UID:0000VI][StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f](by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md).

### `app/StartupLogoPanes.cpp`

See [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md). This startup module owns the logo/intro transition panes:

- `LogoPane` owns the static startup logo load/render path, `NEXON.LGO`-style image and palette decoding, delayed advance timer, click skip path, and completion callback.
- `LogoPlayerPane` owns startup Bink segment-file loading, keyboard/mouse skip behavior, segment advancement, and completion callback.
- [UID:0000P4][VideoPlayerPane](by-file/VideoPlayerPane.md) should remain a reusable base pane in `ui/core/VideoPlayerPane.cpp`; this file consumes it for startup movie sequencing.
- `_AUTOBUF<unsigned char>` helper code emitted near `LogoPlayerPane` should be treated as template support rather than a pane method.

Rationale: IDA MCP confirms the `LogoPane` island at `0x004f4c10-0x004f53a8`, the `LogoPlayerPane` island at `0x004f53b0-0x004f570c`, and a constructor call from application startup around `0x004f643c`. The classes are startup-flow UI, not generic dialogs.

### `input/InputMan.cpp`

See [UID:0000K6][InputMan](by-file/InputMan.md). This is a strong standalone input module:

- `InputMan` owns the custom IME context, active input-target list, window-message bridge, composition/candidate handling, and `g_pInputMan`.
- helper code around candidate-list creation and composition extraction should stay with input until event subclasses are fully named.
- candidate-list storage should be written as ordinary wide-string/deque operations. The current `CandidateStringQueue` helper bodies are [UID:0001WO][CandidateStringDequeTemplate](by-type/by-template/CandidateStringDequeTemplate.md) support, not an original `InputMan` product class.
- [UID:0000K5][IMEPanes](by-file/IMEPanes.md) is the neighboring pane-side source candidate for `IMEPane`, `IMEStatusPane`, `IMECompositionPane`, `IMECandidatePane`, the candidate-string container member, and `g_pIMEPane`.

Rationale: IDA MCP confirms all six methods in `0x004e8af0-0x004e970c`, with construction from `Application::Initialize` and message handling from the app window procedure path. The behavior is too IME-specific to merge into `Application.cpp`.

### `input/KeySpeedMgr.cpp`

See [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md). This is a small input/platform module:

- `KeySpeedMgr` owns saved Windows keyboard repeat delay/speed state and `g_pKeySpeedMgr`.
- `Application::Initialize` constructs it and records current keyboard settings.
- cleanup, deactivate, exception-filter, and `WinMain` exit paths restore the saved settings.
- [UID:0001UV][KeySpeedMgrLayout](by-type/by-struct/KeySpeedMgrLayout.md) confirms the `0x0c` object shape and [UID:0001XX][KeySpeedMgrVtable](by-type/by-vtable/KeySpeedMgrVtable.md) confirms the RTTI-backed vptr at `0x0061c9c8`.
- It should remain separate from `InputMan`; it calls `SystemParametersInfoW` and does not own Win32 message or IME routing.
- Current active `simroot_v2/class_KeySpeedMgr.cpp` remains incomplete for migration because [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md) is disabled, the adjacent destructor and [UID:00018Q][0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings](by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md) are omitted from the active class file, and the raw two-argument setter at [UID:0002IS][0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw](by-memory/0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw.md) was only discovered through IDA byte review.

Rationale: IDA MCP confirms the compact range `0x004efea0-0x004f0008`, `0x0c` allocation, direct construction/load from `Application::Initialize`, restore callers from app deactivation and crash/exit paths, RTTI-backed vtable `0x0061c9c8`, singleton storage at [UID:0001P7][0x0067ab48-0x0067ab4c.g_pKeySpeedMgr](by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md), and internal child boundaries/padding. Current active generated source omits the real disabled restore function at `0x004eff30` and the raw setter helper at `0x004eff60`, so migration should use the memory/class/type docs as the ownership anchor.

### `input/IMEPanes.cpp`

See [UID:0000K5][IMEPanes](by-file/IMEPanes.md). This is a strong pane-side IME module candidate:

- `IMEPanes.cpp` owns the visible and hidden UI panes that react to IME events: status label, composition popup, candidate popup, and root `IMEPane` singleton.
- The current `CandidateStringQueue` output should be treated as generated `std::deque<std::wstring>`-style template support for candidate-list text copied from IMM data into the candidate popup and built by `InputMan::HandleWindowMessage`.
- `g_pIMEPane` belongs here because it is written by `IMEPane::IMEPane`, cleared by `IMEPane` teardown, and used by text-entry controls to register/unregister focus panes.
- Keep this separate from `InputMan.cpp`: the input manager owns Win32/IMM event production, while `IMEPanes.cpp` owns pane state and rendering.

Rationale: IDA MCP confirms a contiguous pane-side cluster at `0x004e70f0-0x004e8ae6`, immediately preceding `InputMan` at `0x004e8af0`. Current generated source places `0x004e7470` and `0x004e7930` under `FittingRoomDownloadControlPane`, but IDA/dataflow evidence anchors both as IME composition/candidate helpers. A 2026-05-26 IDA check also ties the generated `CandidateStringQueue` helper implementation to STL deque/wstring support through `deque<T> too long`, 0x18-byte SSO-7 wide-string entries, and MSVC-style deque map growth, so the proposed tree should not include a standalone original `CandidateStringQueue.cpp`.

### `ui/core/EventDispatcher.cpp`

See [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md). This module owns UI event routing:

- `EventDispatcher`, its handler tree/list helpers, modal-list insertion, recursive child dispatch, translated-child dispatch, and handler calls.
- `EventHandler`, `Tree<EventHandler*>`, `TreeItor<EventHandler*>`, and `HandlerFindFunc` should be treated as `EventDispatcher`/UI-core support declarations rather than standalone feature modules.
- [UID:0000J6][Event](by-file/Event.md), or a tiny adjacent `Event.cpp`, remains nearby as the base event object and event producer/factory layer.
- `ApplicationHelper_4A6C40` is likely an event-dispatch/message-loop scheduler helper, despite being called by `Application::RunMessageLoop`; exact pages now split [UID:000142][0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md) and [UID:000143][0x004a7120-0x004a712c.ApplicationIdleTickBaseline](by-memory/0x004a7120-0x004a712c.ApplicationIdleTickBaseline.md).

Rationale: IDA MCP confirms `EventDispatcher` construction from `Application::Initialize`, broad `DispatchEvent` call-in, and message-loop idle calls into the helper at `0x004a6c40`. The helper drains `BlackHole`, runs `TimerMgr`, rebuilds event traversal state, and dispatches frame callbacks through `g_frameRegistry`; its physical memory locality and dependency mix favor UI core ownership over app ownership.

### `ui/core/Event.cpp`

See [UID:0000J6][Event](by-file/Event.md). This is the event object and event-factory companion to `EventDispatcher.cpp`:

- `Event` owns base event construction/destruction at `0x004a8a90`, `0x004a8ab0`, and `0x004ab3f0`.
- `EventMan` owns input event production at `0x004a8b40-0x004ab476`: cursor, mouse buttons, mouse wheel, key down/release state, text input, composition text, timer polling, and `g_pEventMan`.
- Free helper factories at `0x004a9a40-0x004aa1b3` package IME status/composition/candidate events and packet/payload events into stack `Event` records.
- Keep this near `EventDispatcher`; the memory span is shared with adjacent event subclass/helper code and should not be treated as a standalone feature module.

Rationale: IDA confirms the base `Event` anchors, `EventMan` method boundaries, `Application::Initialize` construction of `EventMan`, `InputMan::HandleWindowMessage` calls into the IME event factories, and repeated `g_pEventDispatcher` dispatch calls from the helper bodies. `EventDispatcher.cpp` routes events; this file creates them.

### `ui/core/VideoPlayerPane.cpp`

See [UID:0000P4][VideoPlayerPane](by-file/VideoPlayerPane.md). This reusable UI/media pane owns Bink playback:

- `VideoPlayerPane` owns playback start/stop, `OnPaint` frame decode/copy/present work, `term` notification handling, TimerHandler `OnTimer` completion for exact id `'ViSD'` (`0x56695344`), virtual `OnClose`, and Bink handle teardown.
- `0x005c0090` is the source-bearing non-deleting `VideoPlayerPane` destructor body; `LogoPlayerPane` calls it as base teardown but does not own it.
- `0x005c0110` is protected `VideoPlayerPane::OpenBinkVideo(const void *segmentData, unsigned int segmentSize)`. Its current direct callers are `LogoPlayerPane`, but its generic Bink-open setup, class-state use, and physical placement make it a base-class helper.
- `0x005c0180`, `0x005c01a0`, and `0x005c01d0` are retained private `CloseBinkVideo`, `SetBinkSoundEnabled`, and `SeekBinkFrame` bodies. They have zero current xrefs and zero encoded VA/RVA pointer routes, but are exact source-shaped methods that operate exclusively on the `VideoPlayerPane` Bink handle; preserve that negative liveness evidence without dropping or relocating the methods.
- [UID:0000FV][VideoPlayerPane](by-class/VideoPlayerPane.md) emits the complete class declaration through `VideoPlayerPane.h`, while [UID:0001NT][0x005c0040-0x005c045b.VideoPlayerPane](by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md) emits only authored method definitions through `VideoPlayerPane.cpp`. [UID:0002Z5][0x0063104c-0x006310dc.VideoPlayerPaneVtableData](by-memory/0x0063104c-0x006310dc.VideoPlayerPaneVtableData.md) is class-owned covered-by evidence for the 21-slot primary, 11-slot EventHandler, and 2-slot TimerHandler vtables; vtables, RTTI, adjustor thunks, scalar deleting glue, and padding remain compiler-owned rather than handwritten source.

Rationale: IDA MCP confirms the video pane function island at `0x005c0040-0x005c045b`, the complete 21/11/2 vtable family at `0x0063104c-0x006310dc`, direct `Pane` inheritance with inherited EventHandler and TimerHandler facets at `+0xa0/+0xa4`, and direct use from `LogoPlayerPane`. It is reusable NexusTK UI/media wrapper code, not Bink middleware source, and should live with UI core unless later source evidence shows a dedicated media folder.

### `platform/PlatformApi.cpp`

See [UID:0000ML][PlatformApi](by-file/PlatformApi.md). This is a platform compatibility module:

- `UniAPIInit` initializes wide-char Win32 API dispatch pointers on NT-family Windows and keeps ANSI fallback behavior otherwise.
- The exact IDA-backed dispatch initializer is [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md), which owns the [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md) at `0x0069be14-0x0069bed0`.
- [UID:000249][0x00599440-0x005995a7.PlatformStringConversionHelpers](by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md) contains default-codepage allocation/free helpers used by MAPI and the UTF-16 stream-reader target assigned into `dword_69BE1C`; keep these visible under the platform module unless later source evidence proves a smaller utility owner.
- The `atexit` cleanup wrapper at [UID:0001O9][0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper](by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md) belongs to `UniAPIInit` static lifetime and is ignored as standalone source; it is not part of the adjacent pool cleanup wrappers.
- `AutoInit` / `InitializeOleSupport` is currently a small process-wide OLE startup/shutdown helper. IDA confirms `0x00419ee0` calls `OleInitialize(0)` and registers the `0x0060c0f0` `OleUninitialize` thunk through `atexit`; it also confirms the ordinary destructor at `0x0046efe0`, the scalar deleting destructor at `0x00470300`, and the one-slot vtable at `0x0061373c`. Final placement may still move to browser/OLE as a source grouping choice, but it is not missing initializer evidence anymore.

Rationale: generated source shows a large `g_pfn*` Win32 dispatch table and NT-vs-9x selection. IDA MCP confirms `UniAPIInit` has a Wave3 boundary mismatch at `0x005995b0`; the matching concrete initializer is `0x0041a280`, where `_wfopen` is written to `dword_69BE14`, `_wstat64i32` is written to `dword_69BE18`, `sub_599570` is written to `dword_69BE1C`, many neighboring wide Win32 pointers are installed, and `sub_60C440` is registered as the static cleanup wrapper. IDA also confirms the nearby `0x00599440` / `0x005994b0` helpers are called by `MapiSendMailHelper`, so this module owns shared platform string glue rather than only the dispatch initializer.

### `patch/PatchPane.cpp`

See [UID:0000MH][PatchPane](by-file/PatchPane.md). This is the startup update/patching UI module:

- `PatchPane` owns the original `Auto Patch` dialog, opcode `0x48` script/entry request flow, received patch-data file writing, patch script `get` rule parsing, and external `patcher.exe` launch path.
- `PatchPane2` owns an alternate/newer patch download dialog using a packed file list, `g_patchDownloadUrl`, `g_patcherExePath`, and the miscellaneous work-thread download path.
- `PatchPane::PatchFileData` and `PatchPane::PatchFileSlice` are nested support helpers for patch data storage and should not become standalone feature files.
- `Application` should remain the caller/decision owner; patch dialog implementation should stay in this module.

Rationale: IDA MCP confirms the patch island from `0x005470b0-0x0054940f` immediately after parcel notification code. Both `PatchPane` and `PatchPane2` constructors are called from the same startup patch-decision function, and their strings/resources are dedicated to patching.

Boundary caveat: active generated output still omits confirmed bodies at `0x005474f0`, `0x005483a0`, `0x00548410`, `0x00548a80`, `0x00548f30`, `0x00549080`, and `0x00549340`, and it projects `PatchPane2::AdvancePatchStep` at bad start `0x00549020`. Use the exact PatchPane memory docs before migrating this module.

Structure caveat: [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md) confirms primary/secondary/tertiary vtables that generated metadata currently misses, and [UID:0001VJ][PatchPane2Layout](by-type/by-struct/PatchPane2Layout.md) pins the `PatchPane2` tail fields. Compiler-generated adjustor thunks at `0x005484db-0x005484f0` and `0x0054934b-0x00549360` are documented ignored ranges, not source methods.

### `util/Error.cpp`, `auth/PasswordGuard.cpp`, `platform/ExceptionHandler.cpp`, and `platform/Crasher.cpp`

See [UID:0000J5][Error](by-file/Error.md), [UID:0000MG][PasswordGuard](by-file/PasswordGuard.md), [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md), [UID:0000II][Crasher](by-file/Crasher.md), [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md), [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md), and [UID:0001QB][client_crash_diagnostics](by-meta/client_crash_diagnostics.md). These form the shared error/crash/password-protection infrastructure:

- `Error.cpp` likely owns `Error`, `ErrorMessage`, `MyError`, `PasswordError`, `Win32Error`, `DDError`, `DIError`, `DSError`, `FileError`, `WSAError`, `InternetError`, and `InternetConnectionError`.
- `PasswordGuard.cpp` likely owns `SetProtectedPasswordToken`, `ValidateChatInputOrThrowPasswordError`, `g_protectedPasswordToken`, and `g_passwordProtectSeed`; final folder may move to chat/login after caller review.
- `ExceptionHandler.cpp` owns the top-level unhandled-exception-filter singleton, `g_pCrashTarget`, file-static `TopLevelExceptionFilter`, [UID:00014G][0x004ab870-0x004abd10.ExceptionCrashReportWriter](by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md), [UID:0004WT][0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions](by-memory/0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions.md), [UID:0004WU][0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk](by-memory/0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk.md), [UID:00014J][0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper](by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md), private static exception/logical-address helpers, Windows-directory `BCrash.nfo` writing, and the class-owned diagnostic text packet helper [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md). The Init and Intel definitions are retained zero-xref bodies whose calls were inlined into GenerateExceptionReport; exact children emit them once while the aggregate remains blank/child-only. Dynamic ImageHlp lookup, no failure-path `FreeLibrary`, and the x86 EBP fallback are source behavior, not grounds for a separate diagnostics or stack utility file.
- `Crasher.cpp` owns the small `Pane`-derived deliberate crash singleton, `g_pCrasher`, and the `0x0049bae0-0x0049bbef` constructor/destructor/trigger range. Keep it separate from `ExceptionHandler.cpp` until source-order evidence proves the original file folded it in.
- `FatalError` is still a split candidate between `app/Application.cpp`, `util/Error.cpp`, or a tiny fatal-dialog source.

Rationale: IDA MCP confirms the `0x004a60d0-0x004a6a76` error wrapper implementation cluster as mostly real functions and identifies Wave3 projected/non-IDA starts for `DIError`, `DSError`, and `ErrorMessage` constructors. A 2026-05-25 recheck confirms those three starts are constructor-shaped raw bytes with no function records/xrefs, and also finds real omitted helpers at `0x004a6400`, `0x004a6410`, and `0x004a6480`. The vtable run at `0x00619340-0x00619448` plus `PasswordError::vftable` at `0x006125a8` confirms the shared interface and storage families. Password guard helpers at `0x004657d0` and `0x00465890` are confirmed real functions with broad text-input caller evidence, while `ExceptionHandler` and `Crasher` are Windows/platform diagnostics objects constructed from `Application::Initialize` at `0x00463e3a` and `0x004646ec`.

### `util/MemoryMan.cpp`

See [UID:0000L7][MemoryMan](by-file/MemoryMan.md), [UID:0000T8][MemoryAllocationHelpers](by-global/MemoryAllocationHelpers.md), and [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md). This is the project heap/allocation policy source family:

- `MemoryMan` owns the 4-byte singleton object, [UID:0000RH][g_pMemoryMan](by-global/g_pMemoryMan.md), constructor/reset/destructor behavior, and `GetMemoryMan`.
- `AllocateBufferMemory`, `FreeBufferMemory`, `ReallocateOrThrow`, the zero-initializing allocation helper, and copy wrappers belong with the same utility family.
- `operator_new` at `0x004f4aa0` is a global allocation front-end that touches `GetMemoryMan` and forwards to `AllocateBufferMemory`.
- Allocation failure constructs [UID:0000G7][Win32Error](by-class/Win32Error.md) and throws through the original C++ exception runtime, so this source family depends on `util/Error.cpp` but should not be merged into it.

Rationale: the compact `0x00516000-0x0051628e` island contains constructor/accessor/allocation/free/realloc/copy/destructor helpers and is followed by unrelated `MenuPane` code at `0x00516290`. Current generated output splits this family into one-class and one-global files, but cached prewave and Wave2 metadata show a shared `MemoryMan.cpp`/memory utility source is more plausible than leaving these as feature-owned fragments.

### `security/CheatDetector.cpp` and `security/VirusChecker.cpp`

See [UID:0000I6][CheatDetector](by-file/CheatDetector.md), [UID:0000P5][VirusChecker](by-file/VirusChecker.md), and [UID:0001Q7][client_anticheat](by-meta/client_anticheat.md). These are the current security/integrity module candidates:

- `CheatDetector.cpp` owns the sole zero [UID:0000QJ][g_pCheatDetector](by-global/g_pCheatDetector.md) definition backed by false/non-emitting [UID:0001P5][0x0067ab3c-0x0067ab40.g_pCheatDetector](by-memory/0x0067ab3c-0x0067ab40.g_pCheatDetector.md), plus the complete 0x20-byte `CheatDetector : Singleton<CheatDetector>, TimerHandler` declaration in that source order. Exact handwritten definitions are [UID:0004UO][0x00483f00-0x00483f86.CheatDetectorConstructor](by-memory/0x00483f00-0x00483f86.CheatDetectorConstructor.md), private retained [UID:0002EN][0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper](by-memory/0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper.md), and [UID:0004UP][0x00483fe0-0x00483fe5.CheatDetectorOnTimer](by-memory/0x00483fe0-0x00483fe5.CheatDetectorOnTimer.md), with an inline empty virtual destructor as the ordinary source carrier. Constructor-unwind clear UID0004UQ, scalar deleting wrapper UID0004UR, two-slot vtable UID0003JE, and backing RTTI/vtable data UID00024Y are source-declared/generated-binary exclusions and emit no handwritten bodies or tables. Application startup/cleanup remain consumers; the helper's exhaustive no-route result caps active detection claims without changing source placement.
- `VirusChecker.cpp` owns the retained AhnLab V3 scanner wrapper at `0x005c0460-0x005c0fe1`, including [UID:0001NV][0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan](by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md), [UID:0001NW][0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers](by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md), the [UID:0001WG][VirusCheckerProcessTreeLayout](by-type/by-struct/VirusCheckerProcessTreeLayout.md), [UID:0001Q3][0x0069bf94-0x0069bf98.g_pVirusChecker](by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md), typed zero-filled V3 module-static globals, and scan-result shutdown behavior. [UID:0000FW][VirusChecker](by-class/VirusChecker.md) now carries first-draft class/source-shape C++; exact method bodies remain on child pages as helper names settle.
- Keep [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md) in input/platform ownership. Its keyboard-repeat side effect is security-adjacent, but the implementation is a settings manager rather than detector/scanner logic.
- Keep [UID:0000MG][PasswordGuard](by-file/PasswordGuard.md) under `auth/` for now because its evidence is password/chat input validation rather than executable integrity.
- Current active `simroot_v2` class files should not be used as complete source for these modules yet: `CheatDetector` has a disabled real vtable slot and omitted singleton clear helper, `VirusChecker` omits its DLL-load/scan/tree helper island from the active class file, and both generated metadata files still report `vtable_count: 0` despite IDA-confirmed RTTI-backed vtables.

Rationale: IDA MCP confirms both compact ranges and the application constructor xref for `CheatDetector`. `VirusChecker` has no proven live constructor caller, load-helper caller, scanner caller, or external singleton consumer in the current evidence, but its DLL names, imports, zero-filled module-static globals, one-slot vtable, and process/module scanner behavior are cohesive enough to document as retained project security source instead of library/runtime support or no-owner code.

### `browser/Browser.cpp`

See [UID:0000HV][Browser](by-file/Browser.md). This is the clearest early migration candidate. It groups:

- `Browser`, `BrowserWindow`, `BrowserThread`, `BrowserControlPane`, `BrowserControlPaneOld`
- `BrowserDialog`, `BrowserDialogOld`, `BrowserPane`, `browser__Notification`
- `BrowserVariantFromString`, `AdviseConnectionPoint`, `UnadviseConnectionPoint`, `PostBrowserNotification`
- browser-specific enums, globals, and static strings such as [UID:0001SL][BrowserMessageId](by-type/by-enum/BrowserMessageId.md), [UID:0001SJ][BrowserDispatchEventId](by-type/by-enum/BrowserDispatchEventId.md), [UID:0000QE][g_pBrowserThread](by-global/g_pBrowserThread.md), [UID:0000QB][g_pBrowserDialogOld](by-global/g_pBrowserDialogOld.md), [UID:0000PV][g_browserWindowClassName](by-global/g_browserWindowClassName.md), and [UID:0001OD][0x00613a20-0x00613ab0.BrowserAlertStrings](by-memory/0x00613a20-0x00613ab0.BrowserAlertStrings.md)

Rationale: dense memory locality, shared COM browser helpers, browser-specific notification channel, and strongly named global/static state. Some generated browser-coupled globals remain unsafe to declare in `Browser.cpp` until alias cleanup, especially `g_activeBrowserControlPane`, `g_browserRuntime`, `g_browserStatusTextPane`, and the broad `dword_67A7CC`/callback families. Current IDA evidence also shows generated `g_pBrowserFileLoadText` and `g_pBrowserTimeoutText` are aliases for direct string literals, so source migration should emit browser alert strings as static text unless separate pointer storage is later recovered.

### `config/Config.cpp` and `config/RegistryConfig.cpp`

See [UID:0000IE][Config](by-file/Config.md) and [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md). This is the lower-level client configuration module:

- `Config` owns the global in-memory configuration object, fixed settings rows, string/list storage, and config-entry array.
- `RegistryConfig` owns built-in defaults, Windows registry load/save, command-line normalization, and user-data default reset.
- `ConfigEntryBlock`, `InitializeConfigEntry`, and `DestroyConfigEntry` belong near this module as config-entry storage helpers.

Rationale: IDA MCP confirms the config/default/registry functions as real starts in `0x0048e480-0x004941d6`. `LoadUserProfileData` depends on `RegistryConfig::InitializeUserDataDefaults`, but that dependency should not move the registry class into profile storage. Current generated `RegistryConfig` still omits the `SaveToRegistry` and `LoadFromRegistry` bodies, while IDA confirms the functions open `Software\Nexon\Kingdom of the Winds`, manage CLSID/registry state, and load/save option/server/color values. The following `0x004941e0-0x00494519` island is reviewed MSVC COM/CRT support, not a `RegistryConfig.cpp` source-owned method family.

### `localization/LanguageMan.cpp`

See [UID:0000KK][LanguageMan](by-file/LanguageMan.md) and [UID:0001QF][client_localization](by-meta/client_localization.md). This source owns the localized string table:

- `LanguageMan` loads `str.res` through [UID:0000IN][DATFile](by-file/DATFile.md), converts line records to owned wide strings, and exposes the table through `g_pLanguageMan`.
- `LanguageManager` is currently best treated as a generated alias or method view over the same concrete layout.
- `0x004f0350` returns `const wchar_t*` text by numeric id; `0x004f0380` copies the selected string into a string object for callers such as number-input and scanner messages.
- 2026-05-26 recheck keeps the omitted support helpers under this module: [UID:00018S][0x004f0290-0x004f0310.LanguageManCleanupDestructor](by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md), [UID:00018U][0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers](by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md), [UID:00018V][0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor](by-memory/0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor.md), and [UID:0001OS][0x0067a750-0x0067a754.g_pLanguageMan](by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md). The neighboring [UID:00018T][0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer](by-memory/0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer.md) remains unresolved.

Rationale: IDA MCP confirms the constructor call from `Application::Initialize` at `0x00464108`, broad lookup callers across UI/dialog/gameplay code, and a compact lifecycle/lookup range at `0x004f0010-0x004f0476`. This is a DAT consumer but not archive infrastructure, so it should not be merged into `DATFile.cpp`.

### `metadata/MetaMan.cpp`

See [UID:0000LC][MetaMan](by-file/MetaMan.md). This source owns the client metadata-table subsystem:

- `MetaMan`, the process-wide metadata manager behind [UID:0000RL][g_pMetaMan](by-global/g_pMetaMan.md).
- `MetaTable`, the per-table payload/decode/tree object, including [UID:0001CC][0x00524870-0x00524c55.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md), [UID:0001CD][0x00524d10-0x00525914.MetaTableRowTreeHelpers](by-memory/0x00524d10-0x00525914.MetaTableRowTreeHelpers.md), and [UID:0001V7][MetaTableRowNode](by-type/by-struct/MetaTableRowNode.md).
- Loose [UID:0001RH][meta-dat-metadata-cache](by-resource/meta-dat-metadata-cache.md) load/save helpers.
- Metadata packet synchronization over opcode `123`.
- Alias-aware lookup globals such as [UID:0000Q2][g_metaAliasTableName](by-global/g_metaAliasTableName.md) and the shared empty lookup result [UID:0000PW][g_emptySimpleUString](by-global/g_emptySimpleUString.md).

Rationale: IDA MCP checks on 2026-05-24 confirm a compact manager/table island from `0x005227d0` through `0x005258f1`, with `MetaMan` constructed from startup, session/network packet dispatch feeding `HandleMetaPacket`, and UI/resource consumers reading through `g_pMetaMan`. A 2026-05-25 follow-up confirms the decoded payload materializer at `0x00524870`, the row-tree lookup helper at `0x005245c0`, and the row helper island through `0x00525914`; the next modeled function at `0x00525920` starts MIDI/audio. The loose `Meta.dat` cache is metadata state, not packed DAT archive parsing, so this should not be placed under `archive/DATFile.cpp`.

### `profile/ProfileStorage.cpp`

See [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md), [UID:0001QL][client_profile_storage](by-meta/client_profile_storage.md), and [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md). This compilation unit owns exactly three free functions:

- `ImportLegacyUserProfileData` at `0x004f9280-0x004f95a2`, which imports the older quoted UTF-16 `.cfg` profile, closes and deletes it after successful import, and does not directly write the modern `.usr` file;
- `LoadUserProfileData` at `0x004f95b0-0x004f9d28`, which reads the eight-section `.usr` stream and falls back to the legacy importer when the current file is absent; and
- `SaveUserSettings` at `0x0050aba0-0x0050b078`, which serializes the same eight sections in the exact loader order.

The interval `[0x004f95a2,0x004f95b0)` is 14 bytes of compiler padding between the importer and loader and emits no source.

The file owns the local `Documents\NexusTK\users` path construction, `.usr` serializer/loader pair, legacy `.cfg` migration, and direct access to the documented `Config` profile-storage fields. Its only runtime-derived config boundary is the narrow call to `RegistryConfig::InitializeUserDataDefaults`; it does not own the config classes.

The similarly named selected-profile sidecar family is explicitly excluded. [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md), [UID:00027P][0x0066dd60-0x0066dd78.ImageExtensionPointerTable](by-memory/0x0066dd60-0x0066dd78.ImageExtensionPointerTable.md), and [UID:0003IV][0x0061e964-0x0061e9fc.ProfileSidecarImageStrings](by-memory/0x0061e964-0x0061e9fc.ProfileSidecarImageStrings.md) remain MapPane-owned sidecar/JPF behavior. [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md) remains a ProfileDialog-owned forwarder into that MapPane route. None is a fourth `ProfileStorage.cpp` function.

Rationale: exact code ranges, caller sets, paired `.usr` format behavior, and the legacy migration call establish the three-function source unit. The sidecar functions use a different owner, asset/table family, and emitter route, so grouping them here merely because they contain "profile" would conflate separate source responsibilities.

### `profile/ProfileDialog.cpp`

See [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md). This is the profile UI dialog companion:

- `ProfileDialog` owns profile dialog construction, old/new profile resource layouts, displayed profile text, accept/cancel handling, profile text sanitation, `g_profileNameBuffer` writes, and dialog close notification.
- Keep profile file loading/saving in `ProfileStorage.cpp`; the dialog consumes profile/config state but should not own the serializer. `0x0053fe90` is only a tiny ProfileDialog-side wrapper around `RefreshSelectedProfileData`.
- `ProfilePane` is now documented as a read-only child pane of [UID:0000P0][UserLookPane](by-file/UserLookPane.md), not as part of `ProfileDialog.cpp`.

Rationale: IDA MCP confirms the profile dialog core at `0x0053f940-0x0053fe87`, with exact child spans `0x0053f940-0x0053fd95`, `0x0053fda0-0x0053fdbf`, and `0x0053fdc0-0x0053fe87`; adjacent wrapper `0x0053fe90-0x0053fe9b`; and non-contiguous destructor/thunk island at `0x00542639`, `0x00542644`, and `0x005429a0`. These are separate from the preceding FriendListDialog block and separate from profile file helpers at `0x004f9280`, `0x004f95b0`, and `0x005063e0`.

- 2026-06-01 IDA MCP sync: `ProfileDialog.cpp` now has validator path `NexusTK/profile/`; child docs attach to [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md) after current xref/callee/boundary evidence raised parent confidence above the attachment threshold.

### `login/MainMenuPane.cpp`, `login/BackStoryDialogPane.cpp`, `login/HistoryViewingPane.cpp`, `login/NewHistoryDialogPane.cpp`, `login/StaffsDialogPane.cpp`, `login/ForcedInformMessageDialog.cpp`, `login/LoginDialogPane.cpp`, `login/ChangePasswordDialogPane.cpp`, `login/ServerSelectPane.cpp`, `login/TerminalPane.cpp`, `login/PhoneBookDialog.cpp`, `login/UserInfoDialogPane.cpp`, `login/CreateUserDialogPane.cpp`, `login/NewCreateUserDialogPane.cpp`, `login/NewUserDialogPane2.cpp`, `login/NewUserMiscDialogPane.cpp`, and `login/UserCreateAppearanceControls.cpp`

See [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md), [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md), [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md), [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md), [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md), [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md), [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md), [UID:0000I3][ChangePasswordDialogPane](by-file/ChangePasswordDialogPane.md), [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md), [UID:0000OI][TerminalPane](by-file/TerminalPane.md), [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md), [UID:0000OY][UserInfoDialogPane](by-file/UserInfoDialogPane.md), [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md), [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md), [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md), [UID:0000LX][NewUserMiscDialogPane](by-file/NewUserMiscDialogPane.md), and [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md). This source family owns the pre-login UI and account/create-user dialogs:

- `MainMenuPane` owns the login-screen menu, input handling, paint, pre-login server-message handling, and dispatch into create-user/login/password/story/history/exit flows.
- `MainMenuPane` also owns nearby free helpers [UID:0000PH][CloseMainMenuDialogSingletons_4F69A0](by-global/CloseMainMenuDialogSingletons_4F69A0.md), [UID:0000PI][ComputeMenuItemRect_4F8B90](by-global/ComputeMenuItemRect_4F8B90.md), [UID:0000T1][HitTestMenuItem_4F8C10](by-global/HitTestMenuItem_4F8C10.md), [UID:0000SZ][HandleLegacyMainMenuPacket_4F8D00](by-global/HandleLegacyMainMenuPacket_4F8D00.md), [UID:0000TB][OpenCreateUserDialog_4F8FA0](by-global/OpenCreateUserDialog_4F8FA0.md), [UID:0000TA][OpenChangePasswordDialog_4F9060](by-global/OpenChangePasswordDialog_4F9060.md), [UID:0000TE][OpenStoryViewingPane_4F90C0](by-global/OpenStoryViewingPane_4F90C0.md), [UID:0000TC][OpenHistoryViewingPane_4F9140](by-global/OpenHistoryViewingPane_4F9140.md), and [UID:0000TF][OpenTerminalPane_4F91C0](by-global/OpenTerminalPane_4F91C0.md), unless later xrefs prove a separate callback source.
- `BackStoryDialogPane` owns the older/story text dialog using `STORY.EPF`/`STORY.EPD`, `PAL01.PAL`/`NPAL8.PAL`, and `BACKTALE`. It is cleaned through the main-menu singleton cleanup helper via [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md) and should remain in the login/main-menu family even if the live constructor path is currently indirect or unclear.
- `HistoryViewingPane` owns the full-screen story/history frame viewer opened directly by `MainMenuPane::ActivateMenuItem` with `STORY.EPF`/`STORY.EPD` or `HISTORY.EPF`/`HISTORY.EPD`.
- `NewHistoryDialogPane` owns the newer full-screen `HISTORYN.EPF` / `MADEBY` history-credits dialog. IDA currently shows no direct constructor caller, but its resources and `g_pMainMenuPane` parent path keep it in the login/main-menu family.
- `StaffsDialogPane` owns the main-menu staff/credits dialog using `STAFF.EPF`, `NPAL8.PAL`, `STAFFS`, and `STAFFS2`; keep it with pre-login/main-menu code, not in in-game staff/admin features.
- `ForcedInformMessageDialog` owns the mandatory accept/decline information dialog using `DLGSTAFF.EPF`/`DLGSTAFF.EPD`; its teardown can reopen the login dialog through `EnsureLoginDialogPane_4F8B30`.
- `LoginDialogPane`, `NewUserDialogPane`, and `ChangePasswordDialogPane` own username/password entry, validation, alert display, and login/account/password packet submission.
- `ServerSelectPane` and `ServerSelectMenuItemList` own the pre-login server-selection dialog and `DLGSERV` list UI at `0x00573d20-0x005747df`, plus [UID:0000S8][g_pServerSelectPane](by-global/g_pServerSelectPane.md) and the selected-server helper pair at `0x00574510-0x0057465d`.
- `TerminalPane` and `TerminalSetupPane` own the pre-login terminal/modem connection pane, terminal setup dialog, [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md), [UID:0001JC][0x0058b130-0x0058b44b.TerminalPaneStreamParser](by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md), [UID:0001JD][0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md), and [UID:000247][0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor](by-memory/0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor.md) at `0x0058af50-0x0058c350`.
- `PhoneBookDialog`, `PhoneBookListPane`, `PhoneEntryDialog`, and `DialDialog` own the terminal phone-book and modem dialing flow at `0x0058c350-0x0058dc5b`; [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md) is now documented as a phone-book selected-entry helper, [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md) is a CRT/runtime `fwprintf`-style wrapper that should remain no-code/no-owner while PhoneBook callers use normal formatted output, and [UID:0001JH][0x0058da20-0x0058db94.DialDialogModemResponseParser](by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md) is the dial modem-response parser. The phone-book block also has retained no-direct-xref dialog/list wrappers, so source should emit through exact child pages rather than aggregate C++. The final split from `TerminalPane.cpp` remains provisional.
- `UserInfoDialogPane` owns the account/user-information form at `0x00599cc0-0x0059bc8b`; keep it near login/account UI rather than the adjacent user-list dialog.
- `CreateUserDialogPane`, `NewCreateUserDialogPane`, `NewUserDialogPane2`, `NewUserMiscDialogPane`, and `NewUserShapeSelectControlPane` own the older/newer create-character setup dialogs and body-shape preview controls. Do not confuse account-registration `NewUserDialogPane.cpp` with create-character `NewUserDialogPane2.cpp`.
- `UserCreateAppearanceControls` covers the older `CreateUserDialogPane` appearance widgets: `UserShapeSelectControlPane`, hair/face selectors, final preview pane, and hair/face color swatch lists. These can be reconstructed as a helper file or folded into `CreateUserDialogPane.cpp` after source size is evaluated.
- [UID:0000PL][EnsureLoginDialogPane_4F8B30](by-global/EnsureLoginDialogPane_4F8B30.md) and `SendLoginRequest` are nearby helper candidates; [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) remains a global UI bootstrap despite being called by the login-success path.

Rationale: IDA MCP confirms dense login/account boundaries in `0x004f6700-0x004fb62a`, including exact main-menu helper boundaries at `0x004f8c10`, `0x004f8d00`, `0x004f8fa0`, `0x004f9060`, `0x004f90c0`, `0x004f9140`, and `0x004f91c0`; the `HistoryViewingPane` core at `0x004ffd80-0x0050008b`; the staff dialog core at `0x004ffaa0-0x004ffd3d`; the `BackStoryDialogPane` core at `0x00500090-0x0050040d`; the `NewHistoryDialogPane` core at `0x00500410-0x00500632`; the forced inform dialog core at `0x00587bb0-0x005881ed`; the create-user dialog family in `0x0052a540-0x0052f94c`; the old create-user appearance controls at `0x004fcd80-0x004fd520` and `0x00501150-0x00502383`; the user-info form at `0x00599cc0-0x0059bc8b`; the server-selection dialog at `0x00573d20-0x005747df`; the terminal/setup block at `0x0058af50-0x0058c350`; the phone-book/dial blocks at `0x0058c350-0x0058dc5b`; and helper/control boundaries around `0x004fb630-0x004fe782`. `MainMenuPane::ActivateMenuItem` directly constructs the login, create-user, password-dialog, history/story viewer, and terminal classes; `0x004f9060` is another password-dialog allocation wrapper despite its current misleading IDA runtime-style name. `ServerSelectPane` and `TerminalPane` are part of the same pre-login singleton/startup family. `BackStoryDialogPane`, `NewHistoryDialogPane`, `StaffsDialogPane`, `ForcedInformMessageDialog`, and `UserInfoDialogPane` currently have no direct IDA constructor callers, and retained helpers `0x004f8fa0`, `0x004f9060`, `0x004f90c0`, `0x004f9140`, and `0x004f91c0` currently have no direct xrefs, so treat exact menu/server/account entry paths as open while keeping source placement with the main-menu/login resource family. The 2026-05-25 singleton recheck confirms `g_pBackStoryDialogPane` at `0x0069b498` is still read by `CloseMainMenuDialogSingletons` and written/cleared by `BackStoryDialogPane` lifecycle code. The 2026-05-24 server-select recheck confirms `0x00574510` is called only from `ServerSelectPane::OnDialogAction`, not from chat-color UI. The 2026-05-26 terminal/phone recheck confirms `0x0058b130`, `0x0058b620`, and `0x0058da20` are data/vtable callback functions, while `0x0058dbe0`, `0x0058dbeb-0x0058dc00`, and `0x0058dc01-0x0058dc16` are constructor-unwind or destructor-thunk glue and should not shape handwritten source files. The 2026-05-28 boundary pass confirms [UID:000247][0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor](by-memory/0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor.md) as the normal `TerminalPane` scalar deleting destructor.

### `ui/MainUiGraph.cpp`

See [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md), [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md), and [UID:0000RF][g_pMainMenuPane](by-global/g_pMainMenuPane.md). This is the post-login in-game UI bootstrap:

- `InitializeMainUiGraph` owns the live UI graph construction after login success, not the login dialog itself.
- The newer layout branch constructs `BackPane`, `MapPane`, chat panes, `MapNamePane`, mini-map button UI, `TabPane`, `HourPane`, `UserStatusPane`, `UserStatusPane2`, `SoundStatusPane`, and `UserPane`.
- The older layout branch constructs `BackPane`, `MapPane`, `MapNamePane`, `IconsPane`, `HourPane`, `ConnStatusPane`, `OldSystemMessagePane`, `OldUserStatusPane`, `SoundStatusPane`, `UserPane`, and the legacy interface effect manager.
- Both layout branches consume [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) for playfield bounds before delegating to the current `GameServerConfig::InitializeMapPane` attribution.
- The common tail loads user profile data, refreshes screen/root state, registers the graph, calls ready hooks, retargets input, starts the delayed timer path, and sets the application ready flag.

Rationale: IDA MCP confirms `0x004f7d10-0x004f8b2a` as one function with the next function at `0x004f8b30`, and confirms the only executable caller at `0x004fac9b` inside `LoginDialogPane::OnServerMessage`. The caller loads `dword_67ABA4`/`g_pMainUiGraph` into `ecx` before the call. This behavior is too broad for `login/LoginDialogPane.cpp` and too UI-specific for the process-shell side of `app/Application.cpp`, so `ui/MainUiGraph.cpp` is the current best source-layout hypothesis.

### `ui/InterfaceEfx.cpp`

See [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md), [UID:00006N][InterfaceEfx](by-class/InterfaceEfx.md), [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md), and [UID:0000R8][g_pInterfaceEfxMgr](by-global/g_pInterfaceEfxMgr.md). This is a UI/interface visual-effect module:

- `InterfaceEfx` owns `.EPD`/`.PAD` backed interface animation objects, play/render/tick behavior, scheduler removal, and effect-frame state.
- `InterfaceEfxMgr` owns the old-layout persistent character/magic/item interface effects and periodic left/right frame effects.
- The manager is created by [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) only in the older layout branch.
- Keep this separate from `render/Effects.cpp` for now: `Effects.cpp` owns map/screen overlay/filter effecters, while `InterfaceEfx.cpp` owns pane-like UI art and scheduler-backed interface resources.

Rationale: IDA confirms `0x004e97b0-0x004ea121` as a compact `InterfaceEfx`/`InterfaceEfxMgr` island, with the previous function `0x004e9710` outside the class family and `0x004ea121-0x004ea130` only alignment before the following `InventoryPane`-side construction function at `0x004ea130`. The previously non-contiguous `0x00597600` helper is now resolved as generic [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md) code consumed by InterfaceEfx, not InterfaceEfx-owned source. Active generated output omits `InterfaceEfxMgr` helper `0x004e9ee0` and singleton clear `0x004ea060`, so use the new docs rather than only the emitted `.cpp` files for migration planning.

### `network/ConnStatusPane.cpp` and `network/ReconnectDialog.cpp`

See [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md) and [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md). These are network-session UI companions:

- `ConnStatusPane` owns the in-game connection status indicator, latency sampling, `CONNSTAT.EPD` frame rendering, and selected packet/opcode handling for connection/parcel notification state.
- `ReconnectDialog` and `ConnectionClosedDialog` own connection-loss and reconnect alerts, reconnect timeout handling, disconnect cleanup, and reconnect/leave/cancel packet flows.
- The helper at `0x00553e60` belongs with `ConnectionClosedDialog`/reconnect init flow even though it can conditionally construct `CopyWindow`.

Rationale: IDA confirms the compact `ConnStatusPane` block at `0x00494520-0x004949df` and reconnect dialog neighborhood at `0x00553c10-0x00554635`. Current exact evidence places the complete retained [UID:0001FV][0x005544c0-0x0055454b.CopyWindow](by-memory/0x005544c0-0x0055454b.CopyWindow.md) at `0x005544c0-0x0055454b` and covers it through the private [UID:000039][CopyWindow](by-class/CopyWindow.md) class emitted inside `network/ReconnectDialog.cpp`, before the same-unit connection-state helper uses it. The former `ui/dialogs/CopyWindow.cpp` route is an explicitly superseded historical inference from the 2026-05-25 recheck, not current placement. The remaining connection/reconnect classes are UI classes, but their behavior is driven by network/session state, making `network/` a stronger initial placement than generic `ui/dialogs/`.

### `util/List.cpp`, `util/LinkedList` support, `util/Queue.cpp`, template helpers, `util/PrimeNumberGenerator.h` / `.cpp`, and utility containers

See [UID:0000KS][List](by-file/List.md), [UID:0000KR][LinkedList](by-file/LinkedList.md), [UID:0000MW][Queue](by-file/Queue.md), [UID:0000IR][Deque](by-file/Deque.md), [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md), [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md), [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md), [UID:0000HZ][CachedHashTable](by-file/CachedHashTable.md), [UID:0000MQ][PrimeNumberGenerator](by-file/PrimeNumberGenerator.md), and [UID:0001QA][client_containers](by-meta/client_containers.md). These are cross-subsystem containers/algorithm helpers, not UI list widgets:

- `List` owns the `elementSize`, page size, count, and data-buffer layout used by generic callers.
- `LinkedList` is a non-emitting support index for the MSVC/Dinkumware `std::list<T>` helper bodies at `0x00457550`, `0x004570e0`, and `0x00457430`. These ranges are shared by `FrameMgr`, `MiniMapVersionManager`, `MonsterImageLib`, and `DATIndexVector` teardown, but they should not be emitted as custom NexusTK `LinkedList.cpp` source; the typed caller modules should express the source containers.
- `SortedList` appears adjacent in RTTI/vtable layout and may belong in the same source file or a nearby `SortedList.cpp`; use the [UID:000193][0x004f3600-0x004f3a43.SortedList](by-memory/0x004f3600-0x004f3a43.SortedList.md) page for omitted insert/search helpers at `0x004f3690` and `0x004f3780`.
- `HierList` is a tree-aware container built on `List`; it has import provenance as `HierList.cpp`, is consumed by `Layer`, and needs the [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md) page for the omitted destructor/remove/find helpers.
- `ImageLib` uses `List::List(44, 10)` for the EPF/EPD resource-layout registry, while many UI, map, and object systems use the same container for unrelated data.
- `Queue.cpp` owns a compact fixed-slot circular queue cluster at `0x005539e0-0x00553c07`; active generated output currently omits several helper methods.
- `AUTOBUF<unsigned char>` is byte-buffer template support used by startup media and look/profile packet parsing.
- `ProtectedArray<T>` is a header/template-style dynamic array with fallback record support; concrete emitted instantiations belong to image-library modules and `GameServerConfig`, not one source file per generated class.
- [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md) is a non-emitting documentation index with `PROPOSED_RECONSTRUCTION_PATH:"NONE"`, not an entry in the physical source tree. Synthetic `UInt32Vector`/`RecordVector_4E57C0` indexes and exact shared vector/fill lowerings remain compiler-covered evidence; feature modules own the real typed `std::vector<T>` declarations and operations, and no custom `VectorHelpers.h` or `.cpp` should be reconstructed.
- The historical `Deque.cpp` proposal assigned non-contiguous 4-byte-entry helper bodies at `0x00439e00`, `0x0043e0b0`, `0x004a88e0`, `0x0054c0c0`, `0x0054c160`, and `0x0057b9e0` to custom project source. That route is retired: [UID:0000IR][Deque](by-file/Deque.md) is a documentation index with `NONE` source placement, and UID0001FC/UID0001FD remain non-emitting MSVC/Dinkumware `std::deque<int>` support expressed through typed caller source.
- `CachedHashTable.cpp` owns a fixed-entry hash/cache island at [UID:00016O][0x004c6160-0x004c659c.CachedHashTableLifecycle](by-memory/0x004c6160-0x004c659c.CachedHashTableLifecycle.md), including the helper island at [UID:00016P][0x004c62d0-0x004c64e1.CachedHashTableRawHelpers](by-memory/0x004c62d0-0x004c64e1.CachedHashTableRawHelpers.md), modeled [UID:00016Q][0x004c64b0-0x004c64c4.CachedHashTableCountAccessors](by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md), primary vtable [UID:0001X6][CachedHashTableVtable](by-type/by-vtable/CachedHashTableVtable.md), and exact vtable-data child [UID:0002M7][0x0061aac0-0x0061aad0.CachedHashTableVtableData](by-memory/0x0061aac0-0x0061aad0.CachedHashTableVtableData.md); current IDA and PE route checks show no direct users, so treat it as source-authored retained utility/legacy code.
- `PrimeNumberGenerator.h` owns the polymorphic class declaration, temporary sieve pointer, native `std::deque<int>`, constructor/destructor declarations, and exact accessor declaration. `PrimeNumberGenerator.cpp` owns the raw accessor at `0x0054bcc0`, exact clamp/seed/paired-wheel-sieve constructor at `0x0054bcf0`, empty virtual destructor source cause, and comment-only compiler-vtable marker. The one-slot [UID:0001YG][PrimeNumberGeneratorVtable](by-type/by-vtable/PrimeNumberGeneratorVtable.md) and exact [UID:0002OK][0x0062241c-0x00622424.PrimeNumberGeneratorVtableData](by-memory/0x0062241c-0x00622424.PrimeNumberGeneratorVtableData.md) remain documentation/generated-binary evidence. Raw cleanup, scalar deleting-destructor, EH, RTTI, layout, and Deque helper bodies remain documented compiler consequences rather than custom source.
- `PrimeNumberGenerator` remains a retained utility/legacy source route because current IDA has no direct constructor or accessor caller; that bounded negative-use result does not make the complete local source non-reconstructable.

Rationale: IDA MCP caller checks show `List::List` fan-in from render/resource code, UI panes, object lists, map helpers, and other systems. `LinkedList` caller/xref checks span frame scheduling, minimap hashes, monster image archive-bound lists, and DATIndexVector list teardown, while the 2026-06-17 B001 source-quality pass ties those helper bodies to `"list<T> too long"` diagnostics, runtime allocation/free thunks, and standard `std::list` node/state layout. `Deque` caller checks span EventDispatcher, FolderTreePane, MapPane, WorldMapPane, and SoundManager, and the 2026-05-25 recheck identifies a non-emitted element-address helper used by `PrimeNumberGenerator`; those are typed compiler/STL consequences, not evidence for a standalone custom Deque source. `Queue` has a compact class/vtable cluster even though no direct constructor caller is currently modeled. `AUTOBUF` and `ProtectedArray` retain real header/template source roles with concrete feature-owned instantiations. By contrast, the complete VectorHelpers audit found six cross-module MSVC/Dinkumware vector/fill lowerings, no product API/header/symbol/global, and only typed caller-owned source consequences, so the old `util/VectorHelpers.h` proposal is removed rather than preserved as reverse-engineering scaffolding. `CachedHashTable` and `PrimeNumberGenerator` have generic utility behavior and import-source provenance but no active caller evidence, making `util/` safer than feature ownership; the 2026-05-26 `CachedHashTable` pass adds a raw helper block and vtable that active `simroot_v2` missed, but still finds no feature-specific callers. `SortedList` and `HierList` have standalone RTTI/vtables and source-file provenance, but both are utility containers; 2026-05-25 IDA rechecks confirm their omitted helper functions are real and class-local despite active `simroot_v2` omissions. That breadth supports `util/List.cpp`, `util/Queue.cpp`, `util/AUTOBUF.h`, `util/ProtectedArray.h`, `util/CachedHashTable.cpp`, `util/PrimeNumberGenerator.h`, `util/PrimeNumberGenerator.cpp`, `util/SortedList.cpp`, and `util/HierList.cpp`; Deque, VectorHelpers, and LinkedList remain support indexes rather than emitted custom source files.

### `util/LObject.cpp` and `util/StringBase.cpp`

See [UID:0000KV][LObject](by-file/LObject.md), [UID:0000OA][StringBase](by-file/StringBase.md), [UID:00007D][LObject](by-class/LObject.md), and [UID:0001QS][client_string_handling](by-meta/client_string_handling.md). Current evidence supports a cautious split:

- `LObject.cpp` owns the tiny runtime/base shell: no-op virtual `0x0041b6c0`, constructor `0x004f4a80`, runtime-class accessor `0x004f4b10`, and scalar-deleting destructor `0x004f4b90`.
- `StringBase.cpp` is the preferred source owner for the large ref-counted ANSI/UTF-16 string-buffer family at `0x00582500-0x00584d7d`; generated output currently places it under `LObject`, but IDA and metadata evidence show field `0x00` is a string data pointer rather than an `LObject` vtable.
- FolderTreePane traversal/search callbacks at `0x004b3400-0x004b3d41` are generated under `LObject` but should remain with [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md).
- The ref-counted string buffers use the inferred [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md) layout, the [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md) type-name evidence, and shared [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md).

Rationale: `class_LObject.meta_wave3` explicitly warns that a true virtual base object and a reference-counted string class were merged under one recovered owner. IDA MCP confirms the base shell as a compact range immediately before `LogoPane`. IDA decompilation of `0x00582d80`, `0x00582e30`, `0x005833a0`, and `0x005845b0` confirms the 12-byte-prefixed string-buffer layout and pool-backed ANSI/wide storage, while `0x0052a460` preserves `mystr::StringBase<wchar_t,mystr::mychar_traits<wchar_t>>` in a callback-template vtable. Caller checks show broad string utility fan-in, and the tree methods remain FolderTreePane-local callbacks.

### `util/FunctionObjects.cpp` / `util/FunctionObjects.h`

See [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), [UID:0001Q9][client_callback_dispatch](by-meta/client_callback_dispatch.md), [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md), [UID:00005K][FunctionObject](by-class/FunctionObject.md), and [UID:00005L][FunctionObject0](by-class/FunctionObject0.md). Current evidence supports a shared callback-object utility family:

- `FunctionObject` and `FunctionObject0` own base destructor/pure-virtual callback support; [UID:0003LP][0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor](by-memory/0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor.md) is the confirmed base `FunctionObject::vftable` scalar deleting destructor, while [UID:000123][0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor](by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md) is separate 24-byte callback-template scalar deleting destructor support reused by concrete FunctionObject callback vtables.
- `PlainMemberFunctionObject*` and `DoubleParamMemberFunctionObject*` wrappers bind target object pointers, member-function pointers, `this` adjustments, and small captured arguments; [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md) is the confirmed popup-menu selection wrapper.
- Feature files such as [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md), [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md), [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md), [UID:0000HG][Application](by-file/Application.md), and [UID:0000P1][UserPane](by-file/UserPane.md) own construction and callback target behavior.
- Long generated `class_*FunctionObject*.cpp` files are compiler/template staging containers, not strong evidence for separate original source files.
- Current generated metadata also assigns `0x004d0050` to the popup-menu callback wrapper, but IDA resolves that address inside `ImageLib::ImageLib`; keep it out of confirmed callback ownership until the data issue is fixed.

Rationale: IDA MCP confirms representative callback bodies as tiny real functions reached by vtable/data xrefs, while generated source consistently shows callback pointer, target object, optional adjustment, and optional captured-argument layouts. The original source was likely header-heavy; `FunctionObjects.cpp` is listed as the source-tree placeholder so migration has one owner for emitted base/destructor support.

### `util/File.cpp`, `util/StdioFile.cpp`, and `util/PathUtil.cpp`

See [UID:0000JD][FileIO](by-file/FileIO.md), [UID:00004V][File](by-class/File.md), [UID:0000E6][StdioFile](by-class/StdioFile.md), [UID:0000MI][PathUtil](by-file/PathUtil.md), [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md), [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md), canonical source-bearing [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md), its non-emitting [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md) mirror, and sibling [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md). The archive-specific companion docs are indexed through [UID:0000IM][DATArchive](by-file/DATArchive.md), but DAT ownership stays in `archive/` rather than this utility layer. Current evidence supports a small utility file I/O layer:

- `File.cpp` owns the abstract [UID:00004V][File](by-class/File.md) base, vtable contract, and scalar deleting destructor at `0x0049d390-0x0049d3cd`.
- `StdioFile.cpp` owns the loose-file implementation at `0x00582070-0x005824f5`, plus the non-contiguous `GetSize` virtual at `0x004f5ad0-0x004f5ad3`.
- [UID:0000MI][PathUtil](by-file/PathUtil.md) is the current canonical complete `PathUtil.cpp/.h` source root for exactly two free helpers. [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md) owns the position-10 include preamble, exact `_wstat64i32`-based probe, and complete two-declaration header; [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md) owns the position-20 `_wfopen`/`fclose` probe. The header is required by nine calls in seven functions across DAT, monster-image, startup, menu, map, and audio units. [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md) is a non-reconstructable evidence mirror owned by UID0001IZ and emits no duplicate body. Folding these state-free helpers into `StdioFile.cpp` is retained only as a rejected historical compact-file theory, not a current source-placement or declaration blocker.
- [UID:0000ML][PlatformApi](by-file/PlatformApi.md) owns the `_wfopen` / `_wstat64i32` dispatch entries consumed here; file I/O should reference [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md) instead of declaring `dword_69BE14` or `dword_69BE18` as local source globals.
- [UID:0000IN][DATFile](by-file/DATFile.md) remains in `archive/DATFile.cpp`: it is another `File` implementation but owns mapped DAT entry state and archive lookup behavior.
- [UID:0000NV][SoundManager](by-file/SoundManager.md) owns the Miles AIL callback bridge at `0x0057b630-0x0057b7e7`, even though those callbacks instantiate `DATFile` or `StdioFile`.

Rationale: IDA MCP vtable inspection shows `File` has pure virtual file operations, while `StdioFile` and `DATFile` fill the same slots with their loose-file and archive-entry implementations. Caller checks show `PathExistsViaStat` is shared by startup, menu, map, and audio code, so it should not be owned by any one caller module.

### `util/BinaryCodec.cpp` and `util/BinaryCodec.h`

See [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md), [UID:00004F][Encoder](by-class/Encoder.md), and [UID:00003M][Decoder](by-class/Decoder.md). The 2026-08-15 whole-file analysis supersedes the provisional three-root split:

- `BinaryCodec.cpp` owns all 18 Encoder definitions followed by all 18 Decoder definitions in address order. The broad Encoder/Decoder aggregate pages remain non-emitting indexes.
- `BinaryCodec.h` owns the two complete standalone `0x14` class declarations. Signed cursor/capacity fields, one-byte bool endian/state fields, and virtual destructor/no-op declarations preserve the observed ABI.
- [UID:0000J1][Encoder](by-file/Encoder.md) and [UID:0000IQ][Decoder](by-file/Decoder.md) remain path-`NONE` historical/support aliases, not source roots.
- The shared [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md) covers the buffer/capacity/cursor/flags fields, while [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md) records the compact two-slot vtables at `0x006192cc` and `0x006192d8`.
- [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md) is the only confirmed direct `Encoder` behavioral caller, but it belongs with [UID:0000ON][TextEditPane](by-file/TextEditPane.md) because it serializes text-edit tables.

Rationale: the mirrored contiguous code island, adjacent RTTI/vtables, shared `0x14` layouts, and absence of contrary object-path evidence support one historical BinaryCodec translation unit. The former separate Encoder/Decoder root proposal is retained only as dated superseded history.

### `util/Thread.cpp`, `util/RingBuffer.cpp`, `util/Monitor.cpp`, `util/CriticalSection.cpp`, `util/CriticalSection.h`, `util/WaitableTimer.cpp`, `util/PoolAllocator.cpp`, and `util/PoolAllocator.h`

See [UID:0000OR][Thread](by-file/Thread.md), [UID:0000N8][RingBuffer](by-file/RingBuffer.md), [UID:0000LI][Monitor](by-file/Monitor.md), [UID:00051U][CriticalSection](by-file/CriticalSection.md), [UID:00051V][CriticalSection](by-class/CriticalSection.md), [UID:00003C][CriticalSectionLock](by-class/CriticalSectionLock.md), [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md), [UID:0000OS][ThreadSafeNodeList](by-file/ThreadSafeNodeList.md), [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md), and [UID:0001QT][client_threading](by-meta/client_threading.md). Current evidence supports a utility threading/synchronization and fixed-block allocation family:

- `Thread.cpp` owns the generic [UID:0000EV][Thread](by-class/Thread.md) base and [UID:0000EW][ThreadMan](by-class/ThreadMan.md) singleton/watchdog at `0x00596250-0x0059756e`, including the raw [UID:0001K1][0x00596d20-0x00596e0b.ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md), plus [UID:0000SH][g_pThreadMan](by-global/g_pThreadMan.md).
- `RingBuffer.cpp` owns the blocking queue at `0x005563d0-0x005568c8`; it is consumed by `Thread` message queues, uses `Monitor`/`MonitorCondition` internally, and carries the short [UID:0001YN][RingBufferVtables](by-type/by-vtable/RingBufferVtables.md) at `0x006230cc` and `0x006230dc`.
- `Monitor.cpp` owns [UID:00008L][Monitor](by-class/Monitor.md) and [UID:00008M][MonitorCondition](by-class/MonitorCondition.md). [UID:0000BX][RequestSyncGate](by-class/RequestSyncGate.md) is historical, non-emitting support for the already-owned `Monitor::Lock` and `Monitor::Unlock` bodies; it is not a separate source class and emits no duplicate code.
- [UID:00051U][CriticalSection](by-file/CriticalSection.md) owns `CriticalSection.cpp` and `CriticalSection.h`, [UID:00051V][CriticalSection](by-class/CriticalSection.md), [UID:00003C][CriticalSectionLock](by-class/CriticalSectionLock.md), and the six exact method children [UID:000520][0x0049bcb0-0x0049bcbe.CriticalSectionConstructor](by-memory/0x0049bcb0-0x0049bcbe.CriticalSectionConstructor.md), [UID:00051W][0x0049bcc0-0x0049bcc8.CriticalSectionDestructorSharedTail](by-memory/0x0049bcc0-0x0049bcc8.CriticalSectionDestructorSharedTail.md), [UID:000524][0x0049bcd0-0x0049bcd8.CriticalSectionEnterRaw](by-memory/0x0049bcd0-0x0049bcd8.CriticalSectionEnterRaw.md), [UID:000521][0x0049bce0-0x0049bce8.CriticalSectionLeaveRaw](by-memory/0x0049bce0-0x0049bce8.CriticalSectionLeaveRaw.md), [UID:00051X][0x0049bcf0-0x0049bd09.CriticalSectionLockConstructor](by-memory/0x0049bcf0-0x0049bd09.CriticalSectionLockConstructor.md), and [UID:000522][0x0049bd10-0x0049bd19.CriticalSectionLockDestructor](by-memory/0x0049bd10-0x0049bd19.CriticalSectionLockDestructor.md). The module preserves the exact 24-byte `CriticalSection` layout and four-byte `CriticalSectionLock` layout. [UID:0000HG][Application](by-file/Application.md) owns and consumes its static [UID:000529][0x0067a9a4-0x0067a9bc.ApplicationMessageHandlerCriticalSection](by-memory/0x0067a9a4-0x0067a9bc.ApplicationMessageHandlerCriticalSection.md); Application does not own the reusable utility source.
- Superseded historical grouping: earlier reconstruction-map revisions placed `RequestSyncGate` and `CriticalSectionLock` under `Monitor.cpp`. That grouping is retained here as historical evidence only; the current source reconstruction narrows Monitor to Monitor/MonitorCondition and routes the distinct low-address CriticalSection family through `CriticalSection.cpp/.h`.
- `WaitableTimer.cpp` owns the multimedia timer/event wrapper at `0x005c0ff0-0x005c129a`, including raw start/cancel helpers at `0x005c1120` and `0x005c1170`, [UID:0001WI][WaitableTimerLayout](by-type/by-struct/WaitableTimerLayout.md), and [UID:0001Z2][WaitableTimerVtable](by-type/by-vtable/WaitableTimerVtable.md); keep it separate from `TimerMgr.cpp` until caller evidence proves a merge.
- `PoolAllocator.cpp` owns the authored fixed-block allocator corridor through `0x004b1585`, excluding the compiler cleanup `[0x004b14f0,0x004b151e)`, plus file-local helpers `0x00549bd0-0x00549bf1` and `0x00549c00-0x00549c18`. `PoolAllocator.h` is the sole complete `0x28` public declaration/layout authority. The CPP order is header include, `<new>`, two private records, two helper prototypes, constructor, Allocate, Free, destructor, AllocatePoolChunk, and by-value FreePoolChunkList.
- Concrete [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md) stay beside their consuming modules: object-pane pools with the corresponding `map/*ObjectPane.cpp` files, the `Motion` pool with animation/motion code, the `UserPane` pool with `ui/panels/UserPane.cpp`, and the eight string-buffer pools with `util/StringBase.cpp` through UID0000TM.
- Static initialization/cleanup wrappers at `0x0041a040-0x0041a27d`, `0x0041a4b0`, `0x0060c320-0x0060c43a`, and `0x0060c450` are compiler-generated wrappers for those concrete globals; they should guide static-pool placement but should stay in `by-memory/-ignored.md`.
- Constructor-failure pool-free wrappers at `0x00502420`, `0x00514ae0-0x00514d1e`, and `0x0053ce50` are compiler-generated cleanup/delete thunks around this pool policy; keep them in `by-memory/-ignored.md`, not as source files.
- The former `ThreadSafeNodeList.cpp` tree entry is retired. [UID:0000OS][ThreadSafeNodeList](by-file/ThreadSafeNodeList.md) and [UID:0000EX][ThreadSafeNodeList](by-class/ThreadSafeNodeList.md) remain path-`NONE`, non-emitting historical alias indexes for exact `PoolAllocator::Free`; they do not represent a physical source path.

Rationale: IDA MCP confirms exact function islands, vtable anchors, and caller relationships. Current `simroot_v2` output has improved coverage for the `Thread`/`ThreadMan`, `RingBuffer`, and `WaitableTimer` islands, but it still has polluted owner names, omitted raw ThreadMan message wrappers, low-fidelity ThreadMan message-loop reconstruction, raw RingBuffer helper starts without modeled functions, raw WaitableTimer start/cancel helpers without modeled functions, and several metadata files with `vtable_count: 0`. The file split should be driven by the memory/class/type docs rather than only by active generated `.cpp` contents.

### `util/StringUtil.cpp`

See [UID:0000OB][StringUtil](by-file/StringUtil.md), [UID:0000OA][StringBase](by-file/StringBase.md), [UID:0000D9][SimpleUString](by-class/SimpleUString.md), [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md), [UID:0000E7][StringIter](by-class/StringIter.md), and [UID:0001QS][client_string_handling](by-meta/client_string_handling.md). Current evidence supports a shared Unicode string utility module rather than feature-local ownership:

- `SimpleUString` owns the UTF-16 small-string construction/clear helpers at `0x00421310-0x004216cb`, plus a later pointer-backed construction/compare family at `0x00583210-0x005845eb`.
- `StringBase.cpp` is the preferred first owner for the ref-counted ANSI/UTF-16 string-buffer helpers currently emitted under `LObject` at `0x00582500-0x00584d7d`.
- `SimpleUStringVector` owns the 4-byte pointer-backed string-handle vector helpers used by DAT/profile/patch/string-replacement call sites: destructor `0x00493f10-0x00493f79`, grow/insert `0x0049cc40-0x0049ce48`, and push-back `0x00584910-0x0058498b`.
- `StringIter` owns the UTF-16 iteration helper at `0x00584d80-0x00584e9e`; the generated `0x00584dc0` constructor row is not an IDA-recognized function and should remain a manual-boundary caveat until rechecked.
- The ref-counted string-buffer helpers use empty sentinels at `0x00670278` and `0x00670290`, plus eight [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md)-backed pools at `0x0069bacc-0x0069bbe4`; [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md) tracks the preserved `mystr::StringBase` type-name evidence.
- Layout notes are split into [UID:0001W5][SimpleUStringSso7Layout](by-type/by-struct/SimpleUStringSso7Layout.md), [UID:0001W4][SimpleUStringPointerBackedLayout](by-type/by-struct/SimpleUStringPointerBackedLayout.md), and [UID:0001W6][SimpleUStringVectorLayout](by-type/by-struct/SimpleUStringVectorLayout.md) so source migration does not collapse incompatible generated views too early.

Rationale: IDA MCP caller checks show broad use from startup, UI, patching, sound, profile/config, and object text paths. Active generated output is incomplete for the later `0x00583210+` string family and has at least one non-IDA `StringIter` start, so final placement should be driven by the cross-subsystem utility role and exact memory documentation, not by the current generated one-class file split.

### `util/MD5.cpp`

See [UID:0000L6][MD5](by-file/MD5.md), [UID:0001B6][0x005151f0-0x00515f48.MD5HashHelpers](by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md), [UID:0001B7][0x00515310-0x00515375.Md5BytesHex](by-memory/0x00515310-0x00515375.Md5BytesHex.md), [UID:0001B8][0x00515450-0x00515568.Md5FilePathHex](by-memory/0x00515450-0x00515568.Md5FilePathHex.md), and [UID:0000V2][PacketDigest_00515380](by-item/PacketDigest_00515380.md). Current evidence supports a shared algorithm utility module:

- `MD5.cpp` owns digest formatting, string/byte/file/stream one-shot wrappers, `Md5Update`, `Md5Final`, and the MD5 block transform from `0x005151f0-0x00515f48`.
- `Socket::BuildEncryptedPacket` consumes the raw byte digest wrapper at `0x00515380`, but packet transform/key-table helpers remain in `network/PacketTransform.cpp`.
- `StartupWindow::RunUpdateCheck` consumes the string hash wrapper at `0x00515290`, and screenshot proof submission consumes the stream hash wrapper at `0x00515570`.
- `RegistryConfig::LoadFromRegistry` consumes the caller-output digest wrapper at `0x005153e0` during registry/CLSID setup.
- Raw helper starts at `0x00515310` and `0x00515450` need manual function-boundary treatment because current IDA does not materialize them as functions; the 2026-05-25 xref check found no direct refs, so liveness remains provisional.

Rationale: the helper island implements standard MD5 with cross-subsystem callers. That breadth supports a utility hash source file rather than socket-local or startup-local ownership. The original filename may have been lowercase `md5.c` or part of a broader hash utility, so `util/MD5.cpp` is a reconstruction target rather than a final source-name claim.

### `util/Crc16.cpp`

See [UID:00032J][Crc16](by-file/Crc16.md), [UID:000225][0x0049bbf0-0x0049bca9.ChecksumTableHelpers](by-memory/0x0049bbf0-0x0049bca9.ChecksumTableHelpers.md), [UID:00032K][0x0049bbf0-0x0049bc0d.Crc16WordStep](by-memory/0x0049bbf0-0x0049bc0d.Crc16WordStep.md), [UID:00032L][0x0049bc10-0x0049bc47.Crc16WordBuffer](by-memory/0x0049bc10-0x0049bc47.Crc16WordBuffer.md), [UID:00032M][0x0049bc50-0x0049bc70.Crc16ByteStep](by-memory/0x0049bc50-0x0049bc70.Crc16ByteStep.md), [UID:00032N][0x0049bc70-0x0049bca9.Crc16ByteBuffer](by-memory/0x0049bc70-0x0049bca9.Crc16ByteBuffer.md), and [UID:00027A][0x0066d47c-0x0066d880.ChecksumLookupTablesData](by-memory/0x0066d47c-0x0066d880.ChecksumLookupTablesData.md). Current evidence supports a narrow CRC-16/CCITT utility source file:

- `Crc16.cpp` owns four raw helper bodies: word-step, word-buffer, byte-step, and byte-buffer CRC16 updates over the `0x1021` table shape.
- The paired lookup-table data at `0x0066d47c-0x0066d880` belongs with this source owner because IDA xrefs to `word_66D480` and `word_66D680` are limited to the four Crc16 helper bodies.
- [UID:000225][0x0049bbf0-0x0049bca9.ChecksumTableHelpers](by-memory/0x0049bbf0-0x0049bca9.ChecksumTableHelpers.md) remains a non-emitting aggregate/index over the exact children and internal alignment padding.
- The separate [UID:00027N][0x0066db4c-0x0066dd50.MapPaneChecksumLookupTable](by-memory/0x0066db4c-0x0066dd50.MapPaneChecksumLookupTable.md) stays with `MapPane` despite identical opening table bytes because its xrefs are MapPane packet/tile checksum consumers.
- Bundled zlib/LodePNG checksum helpers are excluded because they are stock third-party CRC-32/Adler/PNG support at unrelated ranges.

Rationale: B001-019 live IDA evidence finds no direct callers, raw pointer constants, or direct call/jump encodings for the four raw helper starts, but the helper bodies and two private lookup tables form a coherent retained utility module. A narrow `util/Crc16.cpp` owner is more faithful than attaching the code to MapPane, zlib/LodePNG, neighboring Crasher/Monitor code, or leaving four reconstructable children and their exclusive tables parentless.

### `util/AesBlockCipher.cpp`

See [UID:00020J][AesBlockCipher](by-file/AesBlockCipher.md), [UID:00020K][AesBlockCipherStateAndTables](by-global/AesBlockCipherStateAndTables.md), [UID:00020L][0x00461790-0x0046189b.AesCbcEncryptRaw](by-memory/0x00461790-0x0046189b.AesCbcEncryptRaw.md), [UID:00020M][0x004618a0-0x004619b8.AesCbcDecryptRaw](by-memory/0x004618a0-0x004619b8.AesCbcDecryptRaw.md), [UID:00020N][0x004619c0-0x00461c07.AesEncryptBlock](by-memory/0x004619c0-0x00461c07.AesEncryptBlock.md), [UID:00020O][0x00461c10-0x00461dc7.AesDecryptBlock](by-memory/0x00461c10-0x00461dc7.AesDecryptBlock.md), [UID:00020P][0x00461dd0-0x00461fd4.AesInvMixColumns](by-memory/0x00461dd0-0x00461fd4.AesInvMixColumns.md), [UID:00020Q][0x00461fe0-0x00462114.AesKeySchedule128](by-memory/0x00461fe0-0x00462114.AesKeySchedule128.md), [UID:0002JU][0x00610fe8-0x006112e8.AesReadOnlyTables](by-memory/0x00610fe8-0x006112e8.AesReadOnlyTables.md), and [UID:00028Y][0x0067a878-0x0067a934.AesMutableStateAndKeySchedule](by-memory/0x0067a878-0x0067a934.AesMutableStateAndKeySchedule.md). Current evidence supports a small AES/Rijndael utility module:

- `AesBlockCipher.cpp` owns raw CBC encrypt/decrypt wrappers at `0x00461790` and `0x004618a0`.
- The block transforms, inverse MixColumns helper, key expansion helper, forward/inverse S-boxes, Rcon table, and loader-zeroed file-static `AesBlockCipherState` mutable storage belong with the same module.
- IDA currently finds no direct xrefs, stored function pointers, or literal VA references to the raw wrappers, so this may be dead linked-in support code or an indirectly reached path not represented in current analysis.
- If later evidence identifies the exact third-party AES implementation, this module should move under the appropriate vendored/static-embed third-party folder.

Rationale: IDA MCP decompilation and byte checks identify standard AES-128 structures: 16-byte state, 10 rounds, forward S-box at `0x00610fe8`, inverse S-box at `0x006110e8`, Rcon at `0x006111e8`, and a 176-byte expanded key schedule at `0x0067a880-0x0067a92f`. No subsystem caller evidence is present yet, so utility placement is safer than assigning it to network, auth, or file/storage modules.

### `util/TimerMgr.cpp`

See [UID:0000OT][TimerMgr](by-file/TimerMgr.md), [UID:0000F1][TimerMgr](by-class/TimerMgr.md), [UID:0000F2][TimerMgrScheduledEventDequeCompilerSupport](by-class/TimerMgrScheduledEventDequeCompilerSupport.md), [UID:0000F0][TimerHandler](by-class/TimerHandler.md), and [UID:0001QU][client_timing](by-meta/client_timing.md). This remains a strong multi-class utility module:

- `TimerMgr` owns singleton lifecycle, multimedia timer period setup, `timeGetTime` tick mirrors, scheduling, dispatch, and cancellation.
- `TimerMgrTimerQueue` owns the embedded sorted ring queue and queue insert/splice/grow helpers.
- `TimerHandler` is probably a small companion base class for callback owners; keep it near `TimerMgr` even if final source uses a separate tiny `TimerHandler.cpp`.
- Queue helpers at `0x00597dc0`, `0x00597eb0`, `0x00597f20`, `0x005980f0`, `0x00598290`, and `0x00598480` should migrate with this module even when active generated output omits them or emits them under `class_TimerMgr.cpp`; see [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md).

Rationale: Wave2 import/source provenance groups `TimerMgr` and `TimerMgrTimerQueue` under `TimerMgr.cpp`. IDA MCP confirms a compact scheduler cluster from `0x00597570-0x005986da`, followed immediately by `TimerPane` at `0x005986e0`, and caller checks show broad cross-subsystem timer use through `g_pTimerMgr`.

### `map/BackPane.cpp`

See [UID:0000HO][BackPane](by-file/BackPane.md). This is the root/backdrop pane module for the live game UI:

- `BackPane` owns the root background pane created by `InitializeMainUiGraph`, its frame-resource load, global singleton pointer, [UID:000161][0x004b8e00-0x004b8e11.GrafPortGetBounds](by-memory/0x004b8e00-0x004b8e11.GrafPortGetBounds.md), help-popup placement helpers, and `FRAME.PAL` versus `NPAL5.PAL` paint branch.
- `BackGroundPane` is an adjacent small tile-frame background pane with the same `Pane` plus `EPFTileContext` construction/destructor pattern and should migrate with `BackPane` unless later source evidence proves it was separate.
- [UID:0000L3][MapPane](by-file/MapPane.md) remains separate: it owns map tiles, objects, packet handlers, and world rendering, while `BackPane` owns the root backdrop/container surface beneath those systems.
- Do not migrate generated `BackPane` rows at `0x005c2760`, `0x005c2840`, or `0x005c2930` into `BackPane.cpp`; those belong with [UID:0000OD][SwallowLayerPane](by-file/SwallowLayerPane.md) if retained.

Rationale: IDA MCP confirms the compact `BackGroundPane`/`BackPane` island at `0x00467510-0x00467b2d`, ending immediately before `BalloonObjectPane` at `0x00467b30`. `InitializeMainUiGraph_004F7D10` constructs `BackPane` in both EPF and legacy layout branches, and Wave2 annotations already treat `BackPane::OnPaint` and `BackPane::GetBounds` as integrated. The 2026-05-25 recheck added exact docs for the scattered generated rows at `0x004806d0`, `0x004b8e00`, `0x004eaf20`, `0x004ede80`, `0x004ef510`, `0x00506ce0`, and `0x005388a0`; keep `0x00506ce0` and `0x005388a0` under review before migration because their caller sets are outside the compact BackPane island.

### `map/MapPane.cpp`

See [UID:0000L3][MapPane](by-file/MapPane.md) and [UID:0001QG][client_map_system](by-meta/client_map_system.md). This is the primary live-world gameplay pane and should be treated as a major source module:

- `MapPane` owns tile buffers, map coordinate conversion, visible-bounds calculation, object-pane indexing, map file load/save, weather/day-night state, render invalidation, input/timer handling, and the main map packet dispatcher.
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) are shared globals consumed by MapPane setup and coordinate helpers, not MapPane instance fields. Keep them visible as map/render layout configuration during source reconstruction.
- `ObjectList` is the concrete object-index class around `MapPane + 0x424`, exposing flat lists, row buckets, and object cleanup/shift helpers used by render and hit-test paths. `MapPaneSpatialIndex` is now best treated as a provisional alias over part of this `ObjectList` surface.
- [UID:0000L2][MapNamePane](by-file/MapNamePane.md), [UID:0000L4][MapRefreshDimmer](by-file/MapRefreshDimmer.md), and the weather layer family ([UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md), [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md), [UID:0000NR][SnowingLayerPane](by-file/SnowingLayerPane.md), [UID:0000OD][SwallowLayerPane](by-file/SwallowLayerPane.md)) are map UI/weather companions. They may be separate `.cpp` files, but they belong under `map/` rather than generic UI or render folders.
- [UID:0000MK][PhotoPane](by-file/PhotoPane.md) is a map-photo/viewer companion created from map packet/UI paths. It consumes map DAT files, tile/static-object render helpers, and human/avatar rendering, so it belongs under `map/` even though it derives from a generic picture-view pane.
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md) tracks the current `MapPane::HandlePacket` dispatcher constants and should be treated as a working opcode index, not final protocol naming.
- `GameServerConfig` / the nation-entry table is a map/gameplay helper rather than a general config module. Its final placement may be `map/GameServerConfig.cpp` or private code inside `MapPane.cpp`.
- Current `simroot_v2/class_MapPane.cpp` includes generated-owner pollution from shared UI/render helpers. Keep `0x005446e0-0x00544b7d` with [UID:0000MC][Pane](by-file/Pane.md) dirty/motion infrastructure, `0x00556ce0-0x00556d41` with [UID:0000NB][ScreenPane](by-file/ScreenPane.md) root layer-list infrastructure, and `0x00557140-0x00559aef` under [UID:0000OC][Surface](by-file/Surface.md) presentation review instead of migrating those ranges into `map/MapPane.cpp`.

Rationale: IDA MCP confirms the key MapPane anchor functions, including map file load/save, packet dispatch, render view, paint, map change, and weather/tile helpers. The subsystem is tightly coupled to server map state and game-world rendering, not merely generic pane logic.

### `map/ObjectList.cpp`

See [UID:0000M4][ObjectList](by-file/ObjectList.md). This is the map-specific object index used by `MapPane`:

- `ObjectList` owns the 68-byte layout initialized by [UID:0002JS][0x00530ee0-0x0053125d.ObjectListConstructor](by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md), with padded map bounds, two flat/cell lists, four row-list arrays, and six global object-list tiers; [UID:0002JT][0x00531260-0x00531473.ObjectListDestructor](by-memory/0x00531260-0x00531473.ObjectListDestructor.md) tears down the same ownership surface.
- The discontiguous helper at `0x00530d00-0x00530ed9` should migrate with `ObjectList`; it walks the same row/global object lists by object id before the constructor/lifecycle island.
- The helper cluster at `0x00531480-0x00532530` should migrate with `ObjectList`; it owns type-dispatch categorization, removal, lookup, and embedded switch-table data.
- The helper island at `0x00532530-0x00532f67` should migrate with `ObjectList`; current `class_MapPaneSpatialIndex.cpp` is a generated alias for the early accessor subset.
- The extended helper family at `0x00532f70-0x0053728e` should migrate with `ObjectList`; it owns encoded object-list key helpers, type-specific list lookups, and list removal/search helpers.
- Keep this separate from `util/List.cpp`. `ObjectList` allocates and owns many generic `List` instances, but its stored elements and callers are specific to map object panes.

Rationale: IDA MCP caller checks show constructor calls only from `MapPane::ChangeMap` and `MapPane::HandleEffectPacket`; helper callers are MapPane render, scroll, hit-test, object cleanup, and diagnostics paths. The 2026-05-25 recheck confirms `simroot_v2` still splits lifecycle into `class_ObjectList.cpp` and the early accessor subset into `class_MapPaneSpatialIndex.cpp`, so migration should use [UID:00023D][0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper](by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md), [UID:00023E][0x00531480-0x00532530.ObjectListCategorizeLookupHelpers](by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md), [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md), and [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md) as the complete method inventory. That supports a `map/ObjectList.cpp` companion rather than a generic utility module or a standalone `MapPaneSpatialIndex.cpp`.

### `map/MapNamePane.cpp`, `map/MapRefreshDimmer.cpp`, and `map/WeatherLayerPane.cpp`

See [UID:0000L2][MapNamePane](by-file/MapNamePane.md), [UID:0000L4][MapRefreshDimmer](by-file/MapRefreshDimmer.md), [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md), [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md), [UID:0000NR][SnowingLayerPane](by-file/SnowingLayerPane.md), and [UID:0000OD][SwallowLayerPane](by-file/SwallowLayerPane.md). These are map companion modules rather than generic UI/render files:

- `MapNamePane` owns current-map-name resource setup, centered map-name text drawing, global active-pane state, and teardown.
- `MapRefreshDimmer` owns the short-lived map-refresh/loading fade helper and timer-driven self-destruction.
- `WeatherLayerPane.cpp/.h` is the selected current compilation-unit root for the complete weather family. `WeatherLayerPane` owns the base bounds/timer logic, while `RainingLayerPane`, `SnowingLayerPane`, and `SwallowLayerPane` are concrete classes in the same source/header pair selected by `MapPane` weather setup. The combined header emits ordered complete declarations for the shared `SnowParticleEntry` layout and `WeatherLayerPane`, `RainingLayerPane`, `SnowingLayerPane`, and `SwallowLayerPane`; it includes the complete `EPFTileContext` definition required by by-value members before those class declarations.
- Weather static tables currently migrate with `WeatherLayerPane.cpp`, not as arbitrary globals, a dedicated snow-table source, or a new `WeatherTables.cpp` helper. [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md) emits the six exact writable rain arrays through [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) at position `0`; [UID:0001OO][0x00670784-0x006707d4.SnowPatternByteTables](by-memory/0x00670784-0x006707d4.SnowPatternByteTables.md) follows at position `1` with six exact writable snow arrays through the same owner/emitter. [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md) is separate zero-filled method-local descriptor/guard backing storage whose executable initialization remains covered by the SnowingLayerPane consumer methods rather than emitted as standalone globals. Historical `RainingLayerPane.cpp`/`SnowingLayerPane.cpp` table placement remains a documented alternative only.
- [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md) remains a non-emitting index over an interleaved local island: Snowing owns `0x005c1bd0-0x005c2227`, `0x005c29ec`, `0x005c29f7`, and `0x005c2a20`, while Swallow begins at `0x005c2230` and owns the `0x005c2a02`/`0x005c2a0d`/`0x005c2a60-0x005c2ab5` tail pieces. Exact source-bearing and compiler-only children prevent the aggregate from duplicating source.
- [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md) is a retained-method index, not a source emitter and not a `BackPane` route. [UID:00054Q][0x005c2760-0x005c2835.SwallowLayerPaneStartSwallowFlight](by-memory/0x005c2760-0x005c2835.SwallowLayerPaneStartSwallowFlight.md) and [UID:00054R][0x005c2840-0x005c292e.SwallowLayerPaneStepSwallowFlight](by-memory/0x005c2840-0x005c292e.SwallowLayerPaneStepSwallowFlight.md) emit the two human-written private methods even though their surviving call sites were inlined and the binary starts have no inbound references.
- [UID:00054K][0x005c2230-0x005c2340.SwallowLayerPaneConstructor](by-memory/0x005c2230-0x005c2340.SwallowLayerPaneConstructor.md), [UID:00054L][0x005c2340-0x005c235f.SwallowLayerPaneDestructor](by-memory/0x005c2340-0x005c235f.SwallowLayerPaneDestructor.md), [UID:00054M][0x005c2360-0x005c2423.SwallowLayerPaneOnPaint](by-memory/0x005c2360-0x005c2423.SwallowLayerPaneOnPaint.md), [UID:00054N][0x005c2430-0x005c24fa.SwallowLayerPaneMoveBy](by-memory/0x005c2430-0x005c24fa.SwallowLayerPaneMoveBy.md), [UID:00054O][0x005c2500-0x005c26a6.SwallowLayerPaneOnTimer](by-memory/0x005c2500-0x005c26a6.SwallowLayerPaneOnTimer.md), [UID:00054P][0x005c26b0-0x005c275c.SwallowLayerPaneDrawOnTarget](by-memory/0x005c26b0-0x005c275c.SwallowLayerPaneDrawOnTarget.md), [UID:00054Q][0x005c2760-0x005c2835.SwallowLayerPaneStartSwallowFlight](by-memory/0x005c2760-0x005c2835.SwallowLayerPaneStartSwallowFlight.md), [UID:00054R][0x005c2840-0x005c292e.SwallowLayerPaneStepSwallowFlight](by-memory/0x005c2840-0x005c292e.SwallowLayerPaneStepSwallowFlight.md), [UID:00054S][0x005c2930-0x005c299f.SwallowLayerPaneInvalidateSwallowRect](by-memory/0x005c2930-0x005c299f.SwallowLayerPaneInvalidateSwallowRect.md), and [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md) provide all ten Swallow definitions in source order. [UID:00054T][0x005c2a02-0x005c2a18.SwallowLayerPaneDestructorAdjustorThunks](by-memory/0x005c2a02-0x005c2a18.SwallowLayerPaneDestructorAdjustorThunks.md), [UID:00054U][0x005c2a60-0x005c2ab5.SwallowLayerPaneScalarDeletingDestructor](by-memory/0x005c2a60-0x005c2ab5.SwallowLayerPaneScalarDeletingDestructor.md), [UID:0002ZA][0x0063133c-0x006313cc.SwallowLayerPaneVtableData](by-memory/0x0063133c-0x006313cc.SwallowLayerPaneVtableData.md), and [UID:0002ZB][0x006313cc-0x006313fc.SwallowLayerResourceStrings](by-memory/0x006313cc-0x006313fc.SwallowLayerResourceStrings.md) are compiler/data evidence and emit no authored duplicate bodies.

Rationale: IDA confirms `MapNamePane` owns the method ranges `0x005031f0-0x0050349e`, thunks at `0x0050380b` and `0x00503816`, and scalar deleting destructor `0x00503840-0x005038fd`; [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md) begins inside the older aggregate at `0x00503580`, so use the [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md) for per-method migration. IDA also confirms `MapRefreshDimmer` at `0x00514920-0x00514e5a` and the weather layer family at `0x005c12a0-0x005c2ab5`, including their small compiler/vtable thunk islands. `MapPane` weather setup at `0x0050db50` constructs the concrete weather panes, so their call-in and behavior are map-screen specific. Earlier `RainingLayerPane.cpp`, `SnowingLayerPane.cpp`, and `SwallowLayerPane.cpp` proposals remain useful historical split hypotheses, but the current complete emitter graph selects one `map/WeatherLayerPane.cpp/.h` compilation unit and prevents duplicate empty roots.

### `map/PhotoPane.cpp`

See [UID:0000MK][PhotoPane](by-file/PhotoPane.md). This is a map snapshot/viewer module rather than a generic image control:

- `PhotoPane` owns the `0x00549620-0x00549afe` map-photo implementation: `C%04d.MAP` load, off-screen `GrafPort` composition, tile/static-object drawing, avatar drawing, paint blit, and cleanup.
- `PictureViewPane` owns the adjacent `0x00549a30-0x00549bc4` full-screen picture-view base/close behavior used by `PhotoPane`; exact close handlers and thunks are documented at [UID:0001F3][0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks](by-memory/0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks.md).
- `MapPane::HandlePacket` is a confirmed constructor caller for `PhotoPane`, while the constructor itself consumes [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md), [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md), and [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md).
- Keep the generated `BulletinSession` close-helper names provisional. The `PictureViewPane` handlers call a broad owner-deletion helper after a `this - 0xa0` adjustment; IDA rechecked on 2026-05-25 and this still does not prove bulletin ownership.

Rationale: IDA MCP confirms a compact `PhotoPane`/`PictureViewPane` island at `0x00549620-0x00549bc5`, and the behavior is map-resource snapshot rendering. The final original-source split may be `PhotoPane.cpp` plus `PictureViewPane.cpp`, but placing both under the map photo/viewer feature is the safest initial migration anchor.

### `map/TimerPane.cpp`

See [UID:0000OU][TimerPane](by-file/TimerPane.md). This is a map/session UI timer companion rather than generic scheduler code:

- `TimerPane` owns the server-controlled countdown/count-up overlay at `0x005986e0-0x00598cbe`.
- [UID:0000SJ][g_pTimerPane](by-global/g_pTimerPane.md) is the active timer overlay singleton at `0x0069b4d8`.
- `MapPane::HandlePacket` opcode `0x67` creates or updates the pane and passes timer mode/value state into `TimerPane::SetTimer`.
- Keep the class separate from [UID:0000OT][TimerMgr](by-file/TimerMgr.md): `TimerPane` consumes timer callbacks through a subobject, but the implementation is display/resource/UI behavior.

Rationale: IDA MCP confirms the compact `TimerPane` island from `0x005986e0-0x00598cbe`, immediately after the `TimerMgr` cluster and before `TotemFrame` at `0x00598cc0`. The constructor/configuration callers are map packet handlers, and the resource path uses `NUMBER.EPF`/`NUMBER.EPD` digit frames. Final migration may make this a private helper in `MapPane.cpp`, but `map/TimerPane.cpp` is the clearer initial source candidate.

### `map/ObjectPane.cpp`

See [UID:0000M5][ObjectPane](by-file/ObjectPane.md). This is now a strong base game-object pane module candidate:

- `ObjectPane` owns the common renderable map-object base: object type, sprite/frame/palette ids, attached object imagery, packed object data, local bounds, and map-position update hooks.
- Keep it separate from `ui/core/Pane.cpp`; `Pane` owns generic UI hierarchy/layer/event behavior, while `ObjectPane` is game-world object infrastructure on top of `Pane`.
- Keep `LivingObjectPane.cpp` separate. `LivingObjectPane` derives through this base and owns actor movement, animation, commands, and server packet handlers.
- Item/object overlay classes are now split into [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md) and [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) companion modules rather than automatically merged into base `ObjectPane.cpp`.

Rationale: Wave3 reports `ObjectPane` grade `96.4` with 12 modeled methods and zero missing target refs. IDA confirms the compact core at `0x005372d0-0x005378fa` plus scattered vtable rect helpers at `0x00469050` and `0x00469080`. The only materialization caveat found in this pass is `ObjectPane::SetObjectData` at `0x00537800`, whose IDA body is real but whose emitted Wave3 source currently contains only struct scaffolding.

### `map/ItemObjectPane.cpp`

See [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md). This is now a strong item-object companion module candidate:

- `ItemObjectPane` owns ground item object construction, centered glyph bounds, and item-image action/draw dispatch.
- `FlyingObjectPane` owns temporary thrown/flying item visuals, arc bounds, timer stepping, impact sounds/effects, and final drop/removal behavior.
- Keep this separate from `ObjectPane.cpp`; the base object pane should not absorb item-specific render/action and projectile logic.

Rationale: IDA MCP confirms the compact item/flying cluster at `0x00537b40-0x005380af`, plus scalar deleting destructors at `0x0053d1a0` and `0x0053d2e0`. Wave3 reports high grades and zero missing target refs for both classes. `ItemObjectPane` is constructed by `MapPane::CreateOrUpdateObjectPane`; `FlyingObjectPane` is constructed by MapPane packet/update handlers, including `0x00512d60`.

### `map/LightingObjectPane.cpp`

See [UID:0000KO][LightingObjectPane](by-file/LightingObjectPane.md). The file and matching header own the complete nine-method `LightingObjectPane` family in `[0x0053c5e0,0x0053ca1b)`:

- Existing constructor, ordinary destructor, and `SetLightImageIndex` remain source ordered with `GetBrightness`, `GetAnchorScreenPoint`, `GetLightBounds`, `QueueLightBounds`, `ApplyLightAtAnchor`, and `ApplyLightMode2AtAnchor`.
- The exact class tail is light image index, local Y/X offsets, and borrowed `ObjectPane *m_anchorSource`; helper methods are not a nested or standalone AttachmentAnchorResolver object.
- Scalar deleting destructor, two adjustor thunks, RTTI, and three vtable views remain compiler-generated from the ordinary virtual declaration.
- Cross-unit dependencies are `AttachedObjectPane::GetAttachedScreenPosition`, LightObjImageLib bounds/brightness/draw APIs, the reusable ProtectedArray header, and MapPane friendship/RectBounds queue contract.

Historical note: the earlier tree staged `AttachmentAnchorResolver.cpp` as a neighboring synthetic module and considered folding it into `AttachedObjectPane.cpp`. Complete constructor/layout/source-order/caller evidence disproved both alternatives. UID0000HL/UID00000O remain searchable history indexes but produce no physical source file.

### `map/AttachedObjectPane.cpp`

See [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md). This is now a strong attached/floating map-object overlay module candidate:

- `AttachedObjectPane` owns attach/detach payload lifecycle, back-pane depth adjustment, map invalidation, and viewport synchronization.
- The generated `AttachedObjectPaneHelper_53AEC0` one-method split should fold into this source for now as private registry cleanup; `0x0053aec0` is only called by `AttachedObjectPane::~AttachedObjectPane`.
- `BalloonObjectPane` owns speech balloon text wrapping, cached bubble surface refresh, frame/tail/text drawing, and owner-relative placement.
- `ObjectInfoObjectPane` owns floating object/name labels and tooltip rendering.
- `HitBarObjectPane` and `DamageNumberObjectPane` own combat overlays attached to map objects.
- AttachedObjectPane contributes its own `GetAttachedScreenPosition(MapPoint *) const` dependency at `0x005386c0`; it does not own the LightingObjectPane helper receiver or a private AttachmentAnchorResolver fold. The former neighboring/fold proposal is preserved in the LightingObjectPane historical note above.
- Keep [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md) separate despite its generated name; it constructs through `Pane` and is allocated by `UserPane`, not the attached object base.

Rationale: IDA MCP confirms `AttachedObjectPane` at `0x005380b0-0x005386bd`, the shared attached-position helper at `0x005386c0`, the detach registry helper at `0x0053aec0-0x0053b011`, `BalloonObjectPane` around `0x00467b30-0x0046904e`, and the hit/damage/info overlay cluster at `0x00538d50-0x00539bb2`, with companion destructors at `0x0053cfa0-0x0053d65b`. Wave3/Ghidra also recover `BalloonObjectPane::RefreshBubbleSurface` at `0x00468250-0x004682bb`, but IDA currently lacks a function record there, so migration should keep the boundary caveat visible.

### `map/LivingObjectPane.cpp`

See [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md). This is now a strong live-map actor module candidate:

- `LivingObjectPane` owns living actor construction/destruction, sprite/render state, linked ground/shadow/EPF/nameplate objects, special effects, movement timers, predictive movement history, spell/command slot use, local movement packets, and server movement/state packet handlers.
- `LivingObjectPane::BoxRotator` is currently emitted as `class_LivingObjectPane__BoxRotator.cpp`, but IDA references it through `??_7BoxRotator@LivingObjectPane@@6B@`; treat it as nested/private `LivingObjectPane` code unless later evidence proves a separate original source file.
- Timer calls emitted as `SoundManager::*` inside `class_LivingObjectPane.cpp` should be migrated as generic `TimerHandler`/`TimerMgr` calls. IDA shows `SetSpriteConfig`, `PlayAnimation`, `ScheduleAnimationStep`, and `CancelAnimationTimer` use `0x00597610`, `0x00597630`, and `0x00597910` for actor timers, not audio behavior.
- 2026-06-01 IDA MCP evidence splits the core block into [UID:0002R0][0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup](by-memory/0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup.md), [UID:0002R1][0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer](by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md), [UID:0002R2][0x0053bb20-0x0053beb6.LivingObjectPaneRenderFrameMethods](by-memory/0x0053bb20-0x0053beb6.LivingObjectPaneRenderFrameMethods.md), and [UID:0002R3][0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor](by-memory/0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor.md), all attached under this file path.
- Keep `UserPane.cpp` separate. `UserPane` owns local player UI/event surface methods; `LivingObjectPane` owns world actor state and movement/command packet behavior.
- Keep `Chatting.cpp` and `SayInputPanes.cpp` separate even though `LivingObjectPane` has a chat-message packet handler; that handler routes server data into chat systems rather than owning chat pane classes.

Rationale: Wave3 reports `LivingObjectPane` grade `94.8` with 78 modeled methods and zero missing target refs. IDA confirms the core class anchors at `0x0053a110-0x0053d818` and the UserPane-adjacent movement/action anchors at `0x005a2de0`, `0x005a2e00`, `0x005a36f0`, `0x005a3770`, `0x005a3870`, `0x005a3e30`, `0x005a4530`, `0x005a5a90`, `0x005a87e0`, `0x005a8810`, `0x005a88d0`, `0x005a8cf0`, `0x005aa480`, `0x005aa710`, `0x005aac80`, `0x005ab090`, `0x005ab410`, `0x005ab860`, `0x005abda0`, `0x005ac280`, `0x005acc30`, and `0x005ad360`. A 2026-05-24 IDA check confirms the sprite/animation timer path forwards through [UID:0000OT][TimerMgr](by-file/TimerMgr.md). Several Wave3-projected starts in this neighborhood are not IDA functions yet, so migration should use the new docs as a boundary-reviewed anchor map.

### `map/GameServerConfig.cpp`

See [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md). This is a map/nation-table helper, not part of `config/`:

- `GameServerConfig::InitializeNationEntryTable`
- `GameServerConfig::CopyNationEntryOrFallback`
- `GameServerConfig::RequestNationEntries`
- `ProtectedArray<GameServerConfig::NationEntry>` cleanup
- possibly only the nation-table slice of the current `GameServerConfig::InitializeMapPane`

Rationale: `InitializeMapPane` constructs `MapPane` state, sets [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md), and loads [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md) into [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md) plus [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md), while the other methods serve [UID:0000Q1][g_gameServerNationTable](by-global/g_gameServerNationTable.md) and its 68-byte [UID:0001UP][GameServerNationEntry](by-type/by-struct/GameServerNationEntry.md) records used by map/status UI. IDA confirms `0x00503a80`, `0x00503c70`, `0x00504110`, `0x00514d50`, and `0x00514d80` as function starts; `0x005039f0` and `0x00503a50` are valid constructor/destructor-shaped code but not currently IDA function records, so both are boundary caveats for migration.

### `map/WorldMapPane.cpp`

See [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md). This should remain separate from `MapPane.cpp`:

- `WorldMapPane` owns the scrollable world-map/travel UI, node hit testing, special-region hit testing, view animation, frame callback usage, and travel packet send.
- `WorldMapNodeEntryVector` and `WorldMapReachabilityBitSet` are private implementation helpers for node storage and reachability scans.

Rationale: `MapPane` creates or triggers the world-map pane from packet handling, but IDA MCP confirms the world-map implementation sits in a compact `0x005c2ac0+` neighborhood with its own helper classes. Wave3's `0x00590053` WorldMapPane method is not an IDA function and is tracked as data debt rather than source-layout evidence.

### `map/FieldMapPane.cpp`

See [UID:0000JA][FieldMapPane](by-file/FieldMapPane.md). This is a smaller map/UI module:

- `FieldMapPane` owns a selectable field-map pane, field-entry metadata, mouse/keyboard selection, and entry rendering.
- `0x004b11a0` is a FieldMap request-packet helper called only by FieldMapPane mouse/key handlers in current IDA xrefs; do not leave it under fitting-room download ownership.
- `0x004b8220` is a nearby path-stem helper used by the constructor before appending `.EPF`.
- `0x004b1130` is function-shaped rect-calculation code with no current IDA function object or xrefs; document it as boundary/data debt before importing.
- Final placement could move to a larger field dialog module if caller evidence later ties it to a specific dialog source.

Rationale: the class is map-domain UI and IDA MCP confirms its constructor/render/input/request boundaries. It is not part of generic render asset loading or the fitting-room download control despite shared generated helper names.

### `ui/inventory/InventoryPane.cpp` and `ui/inventory/SpellInventoryPane.cpp`

See [UID:0000KA][InventoryPane](by-file/InventoryPane.md) and [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md). These form a gameplay inventory UI folder:

- Item inventory: `InventoryPane`, `InventoryPane2`, `NewInventoryPane`, and `ScrollInventoryPane`; the private scrollbar layout and vtables are tracked in [UID:0001W0][ScrollInventoryPaneLayout](by-type/by-struct/ScrollInventoryPaneLayout.md) and [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md).
- Spell inventory: `SpellInventoryPane`, `SpellInventoryPane2`, `NewSpellInventoryPane`, and `ScrollSpellInventoryPane`; the sibling scrollbar layout and vtables are tracked in [UID:0001W1][ScrollSpellInventoryPaneLayout](by-type/by-struct/ScrollSpellInventoryPaneLayout.md) and [UID:0001YS][ScrollSpellInventoryPaneVtables](by-type/by-vtable/ScrollSpellInventoryPaneVtables.md).
- Keep item inventory separate from `render/ItemObjImageLib.cpp`; inventory panes consume item icons and item data, but do not own item asset parsing.
- Keep spell inventory separate from generic spell-effect rendering; it owns learned-spell list display and cast/input dispatch.

Rationale: IDA MCP confirms the major constructor/render/input anchors for both item and spell inventory panes. Wave3 has several projected constructor/reset starts that are not IDA functions, so the source-layout decision should use the verified render/input/lifecycle blocks rather than the disputed starts.

### `ui/dialogs/DialogSession.cpp`, `ui/dialogs/MailDialogs.cpp`, `ui/dialogs/BoardDialogs.cpp`, `ui/dialogs/BulletinSession.cpp`, `ui/dialogs/BulletinReplyAlerts.cpp`, and `ui/dialogs/WebBoardDialog.cpp`

See [UID:0000IU][DialogSession](by-file/DialogSession.md), [UID:0000KZ][MailDialogs](by-file/MailDialogs.md), [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), [UID:0000HX][BulletinSession](by-file/BulletinSession.md), and [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md). These form a strong message/social dialog family:

- `DialogSession.cpp` owns the shared session-bound dialog stack/list APIs and the `DialogInSession` base.
- IDA confirms `DialogSession` vtables at `0x00618d30`, `0x00618d7c`, and `0x00618dac`, and `DialogInSession` vtables at `0x00618db8`, `0x00618e18`, and `0x00618e48`; see [UID:0001XD][DialogSessionVtables](by-type/by-vtable/DialogSessionVtables.md).
- `BulletinSession.cpp` owns the singleton board/mail session and packet/dialog dispatch over the shared session stack.
- `MailDialogs.cpp` likely owns `MailListDialog`, `MailListPane`, `MailDialog`, and `NewMailDialog`.
- `BoardDialogs.cpp` or a split `ArticleDialogs.cpp` likely owns `BulletinDialog`, `BoardListDialog`, `BoardListPane`, `ArticleListDialog`, `ArticleListPane`, `ArticleDialog`, and `NewArticleDialog`.
- `BulletinReplyAlerts.cpp` is a medium-confidence split candidate for `TransferReplyAlert`, `TransferReplyPredefinedAlert`, `MailTransferReplyAlert`, `ConfirmDeleteAlert`, `DeleteReplyAlert`, `ConfirmDeleteMailAlert`, and `MailDeleteReplyAlert`; these may instead be private classes inside the board/mail dialog source files. Use [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md) rather than the current generated text-edit body when reconstructing predefined transfer-reply behavior.
- `WebBoardDialog.cpp` is now the preferred owner for active [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md) and legacy [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md). Behavior is board-specific, but the implementation is browser-backed and sits in the browser/control address region.
- `NewPredefinedFormArticleDialog.cpp` is now a strong split candidate for template/form article composition and the file-local parser [UID:0000UE][DeserializePredefinedFormArticleEntries_478650](by-item/DeserializePredefinedFormArticleEntries_478650.md).

Rationale: IDA MCP confirms the compact `BulletinSession` core at `0x00471150-0x00471ff1`, the shared `DialogSession` core at `0x004a0d80-0x004a15f8`, the board/article core at `0x00472070-0x00477790`, the mail-dialog cluster at `0x00479110-0x0047ec2b`, and the alert companion functions around `0x00478fe0-0x0047ec6b`. The dialogs share session UI, packet opcode handling, list panes, and alert/delete/transfer response flows. Wave3's `BulletinDialog::BulletinDialog` boundary at `0x00472000`, several alert constructor starts, and `DialogSession`/`DialogInSession` `vtable_count: 0` metadata are not IDA-backed source-layout evidence, so source migration should use the verified board/article/mail/action anchors and vtable stores rather than projected/generated rows.

### `ui/dialogs/TransferServerDialogPane.cpp`

See [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md). This is a transfer/transition overlay source:

- `TransferServerDialogPane` owns `TRANSSVR` frame-bound calculation, parcel/cursor-relative positioning, opacity/frame timers, auto-close timer, frame painting, [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md), and singleton cleanup/thunk helpers at `0x00599220` and `0x005993b0-0x0059943f`.
- The constructor is called from login/main UI and map/session paths, but the implementation is an animated UI overlay rather than map packet logic.

Rationale: IDA MCP confirms the compact transfer overlay block at `0x00598ed0-0x0059943f`, with older Wave2 report coverage for `ResetOpacityAndRepaint` and `OnPaintFrame`. The 2026-05-24 recheck confirms singleton address `0x0069b4b0`, vtable adjustor thunks at `0x005993bb` and `0x005993c6`, and a shared pane-base teardown helper at `0x00544580`.

### `ui/dialogs/MusicControlDialog.cpp`

See [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md). This is the in-client music/sound settings dialog:

- `MusicControlDialog` owns `DLGSCNTL.EPF` dialog construction, sound-effect and music playback control dispatch, music-folder selection, CD-drive popup population, previous/pause/next buttons, and close/accept handling.
- Keep playback implementation in `audio/SoundManager.cpp`; this file is the UI/control-policy layer over `SoundManager`, config fields, [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md), and shared control panes.
- `OnMusicPathInput` at `0x00529ee0` and `ApplyMusicPlaybackState` at `0x0052a120` are currently Wave3-owned by `ChattingColorPane`, but IDA caller evidence ties them to `MusicControlDialog`.

Rationale: IDA MCP confirms the compact music-dialog island at `0x00528e60-0x0052a535`, ending before the create-user dialog block at `0x0052a540`. The island includes constructor, command handler, control-state refresh, folder-path callback target, playback-state helper, pause toggle, callback function-object support, and destructor/thunks.

### `ui/dialogs/FolderSelectDialog.cpp` and `ui/controls/FolderTreePane.cpp`

See [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md) and [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md). These are the folder-picker dialog and reusable filesystem tree control used by the music settings UI:

- `FolderSelectDialog` owns `DialogPane` construction, drive-list population through `GetLogicalDrives`, OK/cancel command handling, and callback result dispatch.
- `FolderTreePane` owns the `ScrollablePane` tree control, embedded `Tree<FolderTreePane::TreeElem>` at `+0x130`, selected iterator at `+0x170`, lazy filesystem expansion, sorting, painting, selected-path construction, and [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md).
- Shared `TreeNode<T>`, `TreeStorage<T>`, `Tree<T>`, and symbol-backed `TreeItor<T>` declarations/definitions belong in [UID:0004YK][Tree](by-file/Tree.md) `util/Tree.h`; no `Tree.cpp` is supported. `FolderTreePane.h` owns the exact 12-byte nested `TreeElem` payload, while `FolderTreePane.cpp` owns payload-specific reset and consumer traversal specializations over 36-byte `TreeNode<TreeElem>` records.
- [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md) anchors the `Tree`, `TreeItor`, and three-view `FolderTreePane` vtables. The adjacent `TREEICON.EPF` string at `0x0061a5c4` should remain data, not generated virtual methods.
- Active `class_FolderTreePane.cpp` is polluted with chat-message, surface, help/system-message methods, and false string-derived virtual rows. Use the verified folder-tree ranges `0x004b1b90-0x004b32c9` and `0x004b3350-0x004b5c3f` as migration anchors, while keeping [UID:000159][0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks](by-memory/0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks.md) as ignored compiler adjustor thunks.

Rationale: IDA MCP confirms `FolderSelectDialog` at `0x004b1590-0x004b1b87`, `FolderTreePane` core at `0x004b1b90-0x004b32c9`, and local tree/sort helpers at `0x004b3350-0x004b5c3f`. The constructor xref currently flows from `MusicControlDialog::HandleControlCommand` to `FolderSelectDialog`, then to `FolderTreePane`, making the dialog/control split stronger than folding this code into `MusicControlDialog.cpp`.

### `ui/dialogs/OptionPane.cpp` and `ui/dialogs/TargetOptionDialog.cpp`

See [UID:0000M7][OptionPane](by-file/OptionPane.md) and [UID:0000OG][TargetOptionDialog](by-file/TargetOptionDialog.md). These are now strong options/settings UI module candidates:

- `OptionPane.cpp` owns the older `OptionPane`, the newer page-based `NewOptionPane`, option-page layout/state, volume slider integration policy, option packet dispatch, and option-entry drawing helpers under review.
- 2026-06-01 IDA MCP recheck anchors the old option pane under this file with exact function records at `0x0053d820-0x0053dd4f`, `0x0053dd50-0x0053dd6f`, `0x0053ddb0-0x0053e191`, `0x0053e1e0-0x0053e377`, and `0x0053e380-0x0053e3c1`, plus raw helper bodies at `0x0053e3d0` and `0x0053e420`.
- 2026-06-01 IDA MCP recheck anchors `NewOptionPane` with exact modeled spans from `0x0053ff90-0x00541b2b`, raw server/config helpers at `0x00540ea0`, `0x00540ef0`, `0x00540f50`, and `0x00540ff0`, the mouse-click jump table after `0x00540d37`, and paint helpers called only from `NewOptionPane::OnPaint`.
- [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md) owns the reusable vertical volume-slider control constructed/configured by `NewOptionPane`; its [UID:0001YT][ScrollVolumePaneVtables](by-type/by-vtable/ScrollVolumePaneVtables.md) follows the same three-view pane pattern as the other scroll controls. Keep the class under `ui/controls` rather than absorbing it into options UI.
- `TargetOptionDialog.cpp` owns `TargetOptionDialog` and `TargetOptionEditControlPane`, the target-option config dialog and its custom row control.
- `SendOptionPacket11B_540E50` is a shared option packet helper and should be cross-referenced from the option pane source unless later packet-helper review moves it to a protocol module. The old option dialog has a distinct local copy at `0x0053e380`; use a shared naming pattern but do not merge the function bodies.
- Keep macro setup dialogs out of this file for now. `MacroDialog`, `NewMacroDialog`, and `IntegrateMacroDialog` are physically adjacent but substantial enough for a separate macro-dialog source review.

Rationale: IDA confirms the old option pane at `0x0053d820-0x0053e520`, the new option pane at `0x0053ff90-0x00541b2b`, the target option dialog at `0x00542270-0x0054259f`, and the target edit control at `0x004993b0-0x0049980c`. `NewOptionPane` is constructed from `GeneralPurposePanel`, while `TargetOptionDialog` is opened from the menu-variety action path. Current Wave3 data has several unmodeled option helpers and suspicious fitting-room ownership for option paint helpers, so migration should use the new docs and IDA boundaries as the source-layout anchor.

### `ui/dialogs/MacroDialogs.cpp`

See [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md). This is now a strong macro setup dialog module candidate:

- `MacroDialog`, `SpellMacroDialog`, and `NewMacroDialog` own older, spell-specific, and newer paged macro setup dialogs.
- `IntegrateMacroDialog` owns the integrated macro sequence editor opened from user/menu paths.
- `SpellMacroEditControlPane`, `NewMacroEditControlPane`, and `IntegrateMacroEditControlPane` own the custom row controls used by those dialogs.
- Keep this file separate from `OptionPane.cpp` even though the older option command handler opens some macro dialogs; macro setup has enough dialog/control code to justify its own source candidate.

Rationale: IDA confirms the older macro dialog cluster at `0x0053e520-0x0053f2b6`, the integrated macro dialog at `0x00541b30-0x00542265`, and the macro edit-control island at `0x0057f750-0x005807c5`. The adjacent boundaries are clear: `OptionPane` helpers end at `0x0053e520`, `FriendListDialog` starts at `0x0053f2c0`, and `TargetOptionDialog` starts at `0x00542270`.

The exact teardown/thunk support ranges are now documented at [UID:0001IL][0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper](by-memory/0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper.md), [UID:0001IM][0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper](by-memory/0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper.md), and [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md). Treat them as reviewed destructor/vtable support, not separate macro feature behavior.

### `ui/dialogs/AlertPanes.cpp`

See [UID:0000HE][AlertPanes](by-file/AlertPanes.md). This is now a strong shared alert/dialog infrastructure source candidate:

- `AlertPane` owns the dynamic modal alert base used by many client subsystems, including text measurement, static/scrolled message controls, optional button controls, modal-list insertion, and slide animation.
- `VersatileAlertPane` is a generic callback-backed accept/cancel wrapper over `AlertPane`; keep the raw cleanup body at [UID:00012Y][0x004a06e0-0x004a0715.VersatileAlertPaneDestructor](by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneDestructor.md) with this class unless later xrefs prove it is only suppressible unwind glue.
- `BlueAlertPane` is a blue-framed alert variant with custom `BDFRAME.EPF` border/content drawing; its generated constructor text conflicts with IDA and the generated `g_uiTileRenderer` source should be treated as a resource/render alias artifact before migration.
- `UrlAlertPane` owns URL confirmation, active singleton [UID:0000SM][g_pUrlAlertPane](by-global/g_pUrlAlertPane.md), heap-owned URL storage, `ShellExecuteA`, and optional post-confirm application exit.
- Feature-specific alert subclasses such as `ExchangeAlertPane`, reconnect/connection alerts, board/mail reply alerts, and [UID:0000IH][CopyWindow](by-file/CopyWindow.md) should stay with their feature modules unless later xrefs prove a common alert-helper source.

Rationale: IDA MCP confirms the shared alert base at `0x0049feb0-0x004a0686`, shared alert-family destructor at [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md), compiler adjustor thunks at [UID:00010V][0x0048c315-0x0048c32b.AlertPaneAdjustorThunks](by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md), `VersatileAlertPane` constructor/callbacks at `0x004a0690-0x004a0752`, raw cleanup at [UID:00012Y][0x004a06e0-0x004a0715.VersatileAlertPaneDestructor](by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneDestructor.md), the separated `VersatileAlertPane` destructor island at `0x004a0cb0-0x004a0d37`, `BlueAlertPane` core at `0x005008c0-0x0050114d`, and `UrlAlertPane` at `0x00599a40-0x00599cb3`. The intervening `0x004a0760-0x004a0c8e` range is modeless-dialog/event support, not alert ownership.

### Historical `ui/dialogs/CopyWindow.cpp` placement; current private class in `network/ReconnectDialog.cpp`

See [UID:0000IH][CopyWindow](by-file/CopyWindow.md), now a non-emitting historical index, and [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md), the current source root. `CopyWindow` is a small text-edit alert/dialog companion emitted as a private same-unit class:

- `CopyWindow` derives from `AlertPane` and owns accept/cancel callbacks at `0x00554520` and `0x00554540`.
- Historical pre-Gate-2B evidence recorded the raw constructor body at `0x005544c0` as not yet IDA-modeled. Current canonical IDA state instead models exact function `[0x005544c0,0x00554513)` as `CopyWindow__CopyWindow` with persisted type `CopyWindow *__thiscall(CopyWindow *this)`; the exact disassembly/body evidence, zero inbound xrefs, and retained/inline source-liveness analysis remain valid.
- The reconnect init helper at `0x00553e60` allocates a `CopyWindow` inline when [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md) has eligible state, but caller evidence now places that helper with [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) / `ConnectionClosedDialog` init flow rather than `CopyWindow.cpp`.
- Keep semantic class ownership separate from [UID:0000HE][AlertPanes](by-file/AlertPanes.md) and [UID:0000ON][TextEditPane](by-file/TextEditPane.md), but emit the private class inside `network/ReconnectDialog.cpp`. It has no external complete-type consumer or independent header contract, and Wave2 standalone-file evidence is not current authority.

Rationale: IDA MCP confirms the callbacks and vtable xrefs, active text-edit global ownership in TextEditPane, the retained constructor body at `0x005544c0-0x00554512`, zero direct constructor routes, and live inline `CopyWindow` construction in the `0x00553e60` ConnectionClosed helper. A private class in the helper's translation unit explains the inlining and generated declaration dependency without inventing a standalone file/header. The earlier dedicated-file placement is retained only as a superseded inference from class/vtable identity and older generated/source-tree leads.

### `ui/core/ModelessDialogPane.cpp`

See [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md). This is a shared dialog infrastructure module candidate:

- `ModelessDialogPane` owns the `0x004a0760-0x004a0c8e` non-modal dialog shell and mouse-event router.
- It derives from [UID:0000IT][DialogPane](by-file/DialogPane.md), returns non-modal state, registers a secondary-subobject pointer with the event dispatcher/list manager, and handles drag/click/hover/activation behavior for modeless dialogs.
- IDA confirms its three vtables at [UID:0001Y6][ModelessDialogPaneVtables](by-type/by-vtable/ModelessDialogPaneVtables.md), installed by the constructor at `0x004a07bd`, `0x004a07c4`, and `0x004a07ca`.
- Keep this separate from [UID:0000HE][AlertPanes](by-file/AlertPanes.md): its range is address-adjacent to `VersatileAlertPane`, but the vtable refs and behavior are modeless dialog core, not alert UI.

Rationale: IDA MCP confirms function starts at `0x004a0760`, `0x004a0830`, and `0x004a0840`, with vtable data refs for the virtual methods at `0x618cb0` and `0x618cac`. The constructor currently has no direct IDA caller, but the method bodies, constructor vtable stores, RTTI names, and secondary-subobject event registration support a real base/dialog-infrastructure class under `ui/core/`.

### `ui/dialogs/MessageDialogs.cpp`

See [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md). This is now a strong packet-driven NPC/message dialog module candidate:

- `MessageDialog` and `MessageDialogLarger` own normal/larger message packet parsing, object/portrait/text layout, and previous/next/current action handling.
- `PursuitMessageDialogPane` is a tiny base/companion class for this family; keep its raw constructor at `0x0054cab0-0x0054cae9` here unless later xrefs prove a separate source.
- `MenuQuestionDialog` and `MenuQuestionDialogLarger` own selectable NPC menu packets, optional description/object layout, and opcode `0x3a` selection replies.
- `MenuQuestionItemList` and `MenuQuestionItemListLarger` are private list widgets for menu-question rows and highlighted selected-entry drawing.
- `MessageShowPane.cpp` is now a strong split candidate for the floating message overlay, active singleton [UID:0000RK][g_pMessageShowPane](by-global/g_pMessageShowPane.md), and wrapped-text update helper [UID:0001C4][0x00522530-0x005226ea.MessageShowPaneSetWrappedText](by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md). Current `simroot_v2` emits the helper under `MessageShowPane`; older `FittingRoomDownloadControlPane` ownership is data-history pollution.

Rationale: IDA MCP confirms the dialog family functions from `0x0054ce10-0x00551021`, with constructor xrefs from the dialog-packet dispatch area around `0x0054c200`. The small `PursuitMessageDialogPane` constructor at `0x0054cab0-0x0054cae9` is raw constructor-shaped code immediately before this cluster; IDA currently has no function object or direct caller for it, but generated `MessageDialogLarger` embeds a `PursuitMessageDialogPane` base. This is distinct from generic popup/menu infrastructure such as `MenuPane` and from scrolling system-message UI such as `SystemMessagePane`. Current Wave3 source has materialization caveats for this cluster: `MessageDialog` still has generated placeholder packet offsets, and `MenuQuestionDialogLarger` still omits its constructor body. Migration should use the IDA-confirmed ranges and decompiled packet-offset behavior rather than generated source text alone.

### `ui/menu/PopupMenuControls.cpp`, `ui/menu/RightButtonMenuPane.cpp`, `ui/menu/VoteMenuPane.cpp`, and `ui/menu/MenuVarietyPanes.cpp`

See [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md), [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md), [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md), and [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md). These form a menu UI source area:

- `PopupMenuControls.cpp` likely owns the reusable `PopupMenuControlPane`, `MenuPane`, `MenuItem`, `StringMenuItem`, `SeparatorMenuItem`, and the small callback helper used by popup selection.
- `RightButtonMenuPane.cpp` owns the player/target right-click context menu with Look, Trade, Whisper, Group, and Info actions.
- `VoteMenuPane.cpp` owns the right-click vote popup with Promote/Demote rows, its `g_pVoteMenuPane` singleton, and the two-row hit-test/submit helpers currently generated under `BulletinSession`.
- `MenuVarietyPanes.cpp` owns the in-game menu button and selector for Userlook, Board, Mail, UserList, Friends, Target, Hotkey, Profile, Ranking, and Quit.
- The Ranking menu action opens [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), but the ranking dialog implementation should live in `ui/dialogs/RankingDialog.cpp`, not in this menu source.
- The Quit menu action opens [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md), but the quit confirmation implementation should live in `ui/dialogs/QuitDialogs.cpp`, not in this menu source.

Rationale: IDA MCP confirms the reusable popup-control code at `0x00498040-0x0049b8e5` and `0x00516290-0x00517441`, the right-click target menu core at `0x00554b40-0x0055577b` plus destructor ranges at `0x00556212-0x00556314`, the vote popup at `0x005558d0-0x005563cd` with non-contiguous destructor ranges, and menu-variety panes at `0x005bc610-0x005bfd98`. These are all menu UI code, but the gameplay-specific panes should not be collapsed into the reusable popup-menu framework.

### `ui/dialogs/QuitDialogs.cpp`

See [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md). This is now a strong quit confirmation dialog module candidate:

- `QuitDialog` owns the modal Yes/No quit confirmation, keyboard shortcuts, and parcel/main-menu OK action.
- `QuitInputPane` owns the older typed `Y/y` quit prompt and active singleton [UID:0000S1][g_pQuitInputPane](by-global/g_pQuitInputPane.md).
- `OpenQuitPrompt_5A94B0` owns the runtime choice between the modal alert path and typed prompt path.
- Keep shared line-input helpers `0x004f2300` and `0x004f2310` in [UID:0000K7][InputPanes](by-file/InputPanes.md) even though active generated output emits them under `QuitInputPane`.

Rationale: IDA MCP confirms the mode-gated launcher at `0x005a94b0-0x005a95d2`, the `QuitInputPane` core at `0x005adcc0-0x005add8a`, the `QuitDialog` core at `0x005addf0-0x005adf2e`, and the `QuitInputPane` destructor/thunk ranges at `0x005b7836-0x005b784c` and `0x005b7b30-0x005b7b75`. The menu selector constructs the dialog but does not own the confirmation implementation.

### `ui/dialogs/MerchantDialogPane.cpp`

See [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md). This is now a medium-confidence shared menu-dialog base module candidate:

- `MerchantDialogPane` owns the small `DialogPane`-derived base constructor at `0x00517d30-0x00517d71`.
- It also owns the [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md), which is referenced from text, item, spell, and argumented menu dialog vtables.
- Final migration may keep this as a tiny source file or fold it into a broader menu-dialog source, but it should remain under `ui/dialogs/`, not reusable `ui/menu/`.

Rationale: IDA MCP confirms `0x00517d80` as a real vtable-referenced helper shared by `MerchantDialogPane`, `TextMenuDialog`, `TextInputMenuDialog`, `ServerItemMenuDialog`, `ClientItemMenuDialog`, `ServerSpellMenuDialog`, `ClientSpellMenuDialog`, and `ArgumentedMenuMenuDialog`. The exact virtual page records the current `simroot_v2` omission and packet-send behavior. The raw constructor at `0x00517d30` is valid code but not currently an IDA function object, so source migration should carry the boundary caveat.

### `ui/dialogs/ItemDialogs.cpp`, `ui/dialogs/ItemMenuDialogs.cpp`, and `ui/dialogs/MixItemDialog.cpp`

See [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md). This is now a stronger item-action dialog family:

- `AddItemDialog` and `AddItemWithCountDialog` own reusable item selection, including pickers invoked by exchange-style workflows.
- `MyItemListPane` owns the reusable player-inventory list picker used by add-item, mix-item, and clan-deposit flows. Its accepted physical route is inside `ItemDialogs.cpp`/`ItemDialogs.h` between AddItemDialog and AddItemWithCountDialog; UID0000LO preserves the former standalone split only as history.
- `MixItemDialog` and `AddMixingItemDialog` own item mixing and the filtered add-item flow for mixes.
- [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md) anchors the three-view dialog layouts for `AddItemDialog`, `AddItemWithCountDialog`, `MixItemDialog`, and `AddMixingItemDialog`, plus the mix quantity callback vtable.
- [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) is the distinct `ItemMenuDialogs.cpp`/`ItemMenuDialogs.h` companion module. `ServerItemMenuDialog`, `ServerItemMenuItemList`, `ClientItemMenuDialog`, and `ClientItemMenuItemList`, their two row structs, and all 21 authored item-menu bodies belong there over the shared [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md) base; they do not fold into `ItemDialogs.cpp`.
- Direct item action input panes such as drop/give/use/wear/wield/take-off still need a later pass before deciding whether they live in `ItemDialogs.cpp` or a separate item-action input file.

Rationale: IDA MCP confirms the exchange/mix item dialog cluster at `0x004ae4c0-0x004b0b15`, with AddItemDialog followed contiguously by `MyItemListPane` constructor/accessor/draw at `0x004aeb30-0x004af031` and AddItemWithCountDialog at `0x004af040`; those items share `ItemDialogs.cpp`/`.h`. The separate closed item-menu dialog/list island is `[0x0051a520,0x0051ca3c)`, with adjacent item-menu RTTI/vtables, two server and two client factory routes, private row-list construction, and the independent `SpellMenuDialogs` successor at `0x0051ca40`. Those signals require the distinct `ItemMenuDialogs.cpp`/`.h` companion rather than an ItemDialogs fold. The 2026-05-26 vtable pass confirms item-dialog table bases from `0x00619e8c` through `0x0061a1b4` and the `MixItemDialog` callback table at `0x0061a3b0`; these compiler tables remain non-source. `AddEmployeeItemDialog::AddEmployeeItemDialog` at `0x004a4ae0` is a Wave3 projected boundary that IDA does not recognize as a function, and the 2026-05-24 employee pass shows the actual construction path lives in `EmployeeDialogPane::OnButtonAction`; keep the base picker here and migrate the employee-specific subclass with `EmployeeDialogPane.cpp`.

### `ui/dialogs/NumberInputDialog.cpp`

See [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md). This is a reusable numeric prompt module candidate:

- `NumberInputDialog` owns the `0x00530640-0x00530cf7` modal number-entry dialog, dual EPF/EPD layout resources, min/max validation, confirm/cancel callback dispatch, and destructor thunks.
- Current direct callers are item/mix quantity paths at `0x004afdce` and `0x004b03d6`, but the class is generic enough to keep as a standalone dialog source rather than folding into `ItemDialogs.cpp`.
- The adjacent previous range is [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md); `0x00530640` is a separate class boundary.

Rationale: IDA MCP confirms constructor/action/destructor-thunk starts at `0x00530640`, `0x00530b40`, `0x00530c78`, `0x00530c83`, and `0x00530c90`, plus direct constructor callers from the item-mixing flow. IDA does not currently define the ordinary destructor at `0x00530b00`, but disassembly confirms a destructor-shaped body before the aligned `0x00530b40` action handler. The active generated source has a resource-string caveat for the EPD palette (`NPAL8.PAL`) and a missing-code caveat for the second destructor adjustor thunk.

### `ui/dialogs/ExchangeDialog.cpp`

See [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md). This is now a strong player-to-player trade dialog module candidate:

- `ExchangeDialog` owns the live trade window, packet dispatcher, money submission, ready/cancel flow, and `DL_20` layout.
- `ExchangeItemListPane` and `ExchangeMoneyEditControlPane` are private controls used only by the exchange window.
- `ExchangeAlertPane` owns exchange-specific cancellation/confirmation alerts and the active alert singleton [UID:0000QV][g_pExchangeAlertPane](by-global/g_pExchangeAlertPane.md).
- `AddItemDialog` and `AddItemWithCountDialog` remain in `ItemDialogs.cpp`; exchange invokes them as pickers but does not own their implementation.

Rationale: IDA MCP confirms the main exchange cluster at `0x004ac8a0-0x004ae4b5` and the interleaved alert/destructor/control tail at `0x004b0490-0x004b0ba4`. The main dialog handles opcode `0x4A` sends and opcode `0x42` server exchange updates, while item picker dialogs start at `0x004ae4c0` and remain generic item-dialog code.

Follow-up boundary notes: active `simroot_v2` still omits the IDA-confirmed exchange helpers at [UID:00014L][0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md), [UID:00014M][0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper](by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md), [UID:00014O][0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper](by-memory/0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper.md), and [UID:00014P][0x004ade60-0x004adfab.ExchangeDialogReadyAlertHelper](by-memory/0x004ade60-0x004adfab.ExchangeDialogReadyAlertHelper.md). Raw item-list helpers [UID:00014R][0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper](by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md) and [UID:00014S][0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper](by-memory/0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md) need metadata cleanup before migration. The generated `ExchangeMoneyEditControlPane::GetClassName` at `0x00430058` is a false method start inside [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md), not part of `ExchangeDialog.cpp`.

### `ui/dialogs/EmployeeDialogPane.cpp`

See [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md). This is now a strong employee-shop dialog module candidate:

- `EmployeeDialogPane` owns the `SELLER.EPF` employee/shop dialog, employee record array, 10 visible slot buttons, status/tooltip drawing, opcode `0x54` employee command packets, and packet response handling.
- `EmployeeItemPropertyDialogPane` and `EmployeeQuantityInputDialogPane` are feature-private subdialogs for item price editing and quantity entry.
- `AddEmployeeItemDialog` should migrate with this module even though it reuses `AddItemDialog` construction, because the confirmed owner path patches its vtables from `EmployeeDialogPane::OnButtonAction` and its action handler dispatches employee commands. The raw constructor-shaped bytes at [UID:000139][0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor](by-memory/0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor.md) are reconstructable evidence but still not an IDA function boundary.
- `DeserializeEmployeeRecord` and the recovered `EmployeeRecord` layout belong near this module unless later evidence proves a broader employee protocol source file.

Rationale: IDA MCP confirms a compact employee-dialog island at `0x004a1d70-0x004a4e6b`, including omitted helpers at `0x004a2450` and `0x004a2f60`, the record parser at `0x004a34d0`, property and quantity dialogs, and the employee-specific add-item subclass/thunk island. Wave3 currently omits `0x004a2450` and `0x004a2f60` from active output and models raw `0x004a3be0` as a method even though IDA has no function object there, so migration should wait for metadata cleanup. See [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md) and [UID:00013B][0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks](by-memory/0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks.md) for the 2026-05-26 vtable/thunk split.

### `ui/dialogs/RankingDialog.cpp`

See [UID:0000MZ][RankingDialog](by-file/RankingDialog.md). This is now a strong ranking board dialog module candidate:

- `RankingDialog` owns the main ranking window, category selection, page navigation, reward-info open, reward-claim action, and active singleton [UID:0000S2][g_pRankingDialog](by-global/g_pRankingDialog.md).
- `RankingEventListPane`, `RankingEventScrollPane`, and `RankingUserListPane` are private ranking UI controls for category/event selection and the current ranking-page display.
- `RankingCategoryRecord` and `RankingCategoryCollection` own parsed event/category records, selected category state, ranking rows, and packet update helpers; exact category storage helpers are nested under the ranking file/class docs for visibility.
- `RankingRewardInfoDialog` owns the modal reward list, reward response parse path, reward drawing, and active singleton [UID:0000S3][g_pRankingRewardInfoDialog](by-global/g_pRankingRewardInfoDialog.md). Keep the reward-entry parser [UID:0001ZF][0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors](by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md), packet handler [UID:0001ZH][0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler](by-memory/0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler.md), and reward vector helpers [UID:0001ZI][0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers](by-memory/0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers.md), [UID:0001ZK][0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy](by-memory/0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy.md), and [UID:0001ZJ][0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers](by-memory/0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers.md) nested under this source module rather than splitting them into unrelated utility files.
- Use [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md) for the IDA-confirmed primary/secondary/tertiary vtable views, packet-handler virtual at `0x00459210`, singleton clear helpers, and destructor adjustor thunk split.
- Keep this separate from `MenuVarietyPanes.cpp`: the menu only opens ranking, while opcode `0x7d`, board resources, and ranking data containers are owned here.

Rationale: IDA MCP confirms the compact ranking cluster at `0x00458610-0x0045f9f5`, with raw non-IDA helper starts at `0x004598b0`, `0x0045a990`, and `0x0045add0` documented separately. The scroll-pane mouse path also has modeled helpers at `0x00459a60`, `0x0045a400`, and `0x0045ac10` that current generated source does not fully emit, so migration should use the ranking docs and memory range rather than taking the generated source file wholesale. A 2026-05-26 IDA pass confirmed the ranking vtable block at `0x00610984-0x00610d68`, while current `simroot_v2` metadata still reports `vtable_count: 0` for the ranking UI classes; the adjustor thunks should remain compiler glue and the short tertiary vtables must not be read into adjacent resource strings. A 2026-05-27 IDA pass confirmed that active `class_RankingRewardInfoDialog.cpp` omits the reward-info packet handler and parser/storage helpers even though they belong to the ranking reward module. The generated `class_RankingDialog.cpp` currently includes [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md), Exchange, popup/menu, and generic dialog-animation helpers.

### `ui/dialogs/SpellMenuDialogs.cpp`

See [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md). This is now a strong spell-action menu module candidate:

- `ServerSpellMenuDialog` and `ServerSpellMenuItemList` own server-provided spell menu rows at `0x0051ca40-0x0051db37`.
- `ClientSpellMenuDialog` and `ClientSpellMenuItemList` own client-local spell action rows at `0x0051db40-0x0051e998`.
- The server and client dialogs share `DLGMERC1` layout resources, action/request/cancel buttons, object preview controls, static text, scrollable spell-list setup, and the shared [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md) base virtual.
- Keep this file adjacent to item/text menu dialogs but separate because the payload model and local spell-table population path are spell-specific. The current generated `ChattingColorListPane*` local type inside `ClientSpellMenuDialog::UpdateActionButtonState` is documented as owner-name pollution, not a source-layout dependency.

Rationale: IDA MCP confirms the full spell-menu block immediately after item-menu dialogs and immediately before argumented-menu dialogs. This looks like a compact original source family rather than one-off feature code. The 2026-05-24 recheck confirms both server/client action-button-state helpers use child `6` as a spell list and that the real `ChattingColorListPane` constructor has only chat-color pane callers.

### `ui/dialogs/ItemActionInputPanes.cpp`

See [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md). This is now a strong direct item-command input module candidate:

- Drop/give prompts: `DropAllInputPane`, `DropInputPane`, `DropGoldInputPane`, `GiveAllInputPane`, `GiveInputPane`, and `GiveGoldInputPane`.
- Equipment/action prompts: `TakeOffInputPane`, `ChangeItemSlotInputPane`, `ThrowInputPane`, `ThrowReallyInputPane`, `UseInputPane`, `EatInputPane`, `WieldInputPane`, its private packet helper at `0x005b6500`, and `WearInputPane`.
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md) anchors the direct item-command prompt layouts and separates shared adjustor thunks from handwritten prompt code.
- Target-use prompt: `ItemWhoInputPane` remains cross-referenced here, but the target-selection pass now favors [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md) for the shared target helpers and keyboard target panes.
- Keep adjacent `GroupInputPane`, `PostInputPane`, and `SpellSpellInputPane` out of this file until their own pass confirms whether the original source was a broader command-input module.

Rationale: Wave3 and IDA place most direct item command panes in compact `0x005b44b0-0x005b6760` neighborhoods with shared slot-letter parsing, help-panel shortcut handling, prompt localization, and packet-send patterns. IDA confirms the main method starts and the vtable block from `0x0062f92c` through `0x006305b4`; the 2026-05-26 recheck resolves `0x005b6500` as a Wield packet helper rather than a Wear prelude and resolves `0x005b77c8-0x005b77de` as shared compiler adjustor thunks. Several Wave3 projected constructor starts are still tracked as data issues and should not drive migration.

### `ui/dialogs/TargetSelectionInputPanes.cpp`

See [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md). This is now a medium-to-strong shared target-input module candidate:

- `SpellWhoInputPane` owns the spell-target line-input prompt and saved target id `dword_69BF20`.
- `ItemWhoInputPane` owns the use-on-target line-input prompt and saved target id `dword_69BF24`.
- `SelectObjectWithKeyboardPane` owns the generic object interaction selector, selected id `dword_69BF28`, and active singleton `dword_69BF60`.
- `TargetObjectWithKeyboardPane` owns the target-dispatch selector, selected id `dword_69BF2C`, and active singleton `dword_69BF64`.
- `SpellInputPaneState` and `ItemWhoInputPaneState` own matching one-byte state flag helpers at offset `+0xfa`.
- Shared packet helpers at `0x005af4f0` and `0x005af580` should stay near this module until a broader client-command packet pass decides whether they belong in protocol code instead.

Rationale: IDA MCP confirms coherent spell/item/object target-selection islands at `0x005ae2a0-0x005aeb1e` and `0x005af390-0x005b050d`, with vtable/destructor islands at `0x005b78fc-0x005b822e`. The current `simroot_v2` one-class files are useful evidence but omit several real helper/destructor functions and mark real adjustor thunks as missing code, so migration should use the documentation boundaries rather than active generated output alone.

### `ui/dialogs/SpellInputPanes.cpp`

See [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md). This is now a strong spell argument/input prompt module candidate:

- `SpellStringInputPane` owns string-argument spell input, plus the shared prompt text/layout helper at `0x004f20a0`.
- `SpellFourArgsInputPane`, `SpellThreeArgsInputPane`, `SpellTwoArgsInputPane`, and `SpellOneArgInputPane` own numeric spell argument prompts that serialize opcode `0x0f` payloads.
- `SpellSlotInputPane` owns spell-slot letter prompt behavior.
- `ChangeSpellSlotInputPane` owns comma-separated spell slot reorder input and slot-change packet submission.
- `SpellSpellInputPane` should probably migrate here from [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md), although it remains cross-referenced there because of address locality with command prompts.
- `SpellWhoInputPane` remains in [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md) because it is map-target-selection code, but it is constructed by spell inventory dispatch paths.

Rationale: IDA MCP confirms the spell argument input island at `0x005b0780-0x005b14e5`, the string input block at `0x005adf40-0x005ae1a3`, the slot-change input block at `0x005b3220-0x005b340d`, and the spell-to-spell prompt at `0x005b6120-0x005b62c8`. Generated output currently includes GeneralPurposePanel helpers and CRT `__wtol` under `SpellOneArgInputPane`, so final migration must exclude those owner-polluted entries.

### `ui/dialogs/InputPanes.cpp`

See [UID:0000K7][InputPanes](by-file/InputPanes.md). This is the reusable input-prompt base module:

- `LineInputPane` owns the one-line prompt shell, label/edit child creation, normal/high-resolution geometry, active input registration, key handling, teardown, and chat recipient-history navigation helper.
- `CharInputPane`, `NumberInputPane`, `CharArgsInputPane`, `NumberArgsInputPane`, `MultiLineInputPane`, and `ConfirmInputPane` are small reusable typed-input variants.
- Keep item/social/spell command prompts in their feature files while linking them back to these base classes.

Rationale: IDA MCP confirms a compact base cluster at `0x004f1c00-0x004f3017`, plus non-contiguous but behaviorally tied helpers at `0x005b3e80` and `0x005b75d0`. The [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md) confirms the three-view vtables at `0x0061ca58-0x0061ce20`, even though current generated metadata reports `vtable_count: 0` for the base input-pane classes. `LineInputPane::HandleKeyInput` is currently omitted from active generated source, so migrations should use the IDA-confirmed memory docs rather than the emitted `class_LineInputPane.cpp` body alone.

### `ui/dialogs/TextMenuDialogs.cpp` and `ui/dialogs/ArgumentedMenuDialogs.cpp`

See [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md). This is now a strong packet-driven merchant/NPC menu dialog family candidate:

- `MerchantDialogPane` owns the shared merchant/NPC dialog base constructor and action-string virtual.
- `TextMenuDialog` owns server-sent text menu packet parsing, small/direct-button versus scrollable-list layout, and opcode `0x39` menu-selection replies.
- [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) owns the packet subtype factory dispatch and wrapper helpers that allocate text, item, spell, and argumented merchant/menu dialogs.
- `TextMenuItemList` is the private list-pane row renderer for scrollable text menu entries and should migrate with `TextMenuDialog`.
- `TextInputMenuDialog` owns the text-entry variant that submits user input through the same opcode `0x39` response family.
- `ArgumentedMenuMenuDialog` and `ArgumentedMenuMenuItemList` own the parameterized item/menu variant using `DLGMERC3.EPF`, item-row metadata, contextual item help, and buy-confirm dispatch into `ArgumentedItemConfirmInputDialogPane`.
- [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md) is the exact dialog child slice; it records corrected half-open endpoints and the unreferenced raw `0x0051f140` island that should not drive source naming until reachability is proven.
- `ArgumentedItemInputDialogs.cpp` is the likely split for `ArgumentedItemConfirmInputDialogPane`, `ArgumentedItemQuantityInputDialogPane`, and `SendArgumentedItemQuantityPacket`, but it may fold into `ArgumentedMenuDialogs.cpp` if final migration prefers one argumented-menu source file.
- The argumented classes may split into `ArgumentedMenuDialogs.cpp` if final migration prefers a smaller item-argument source file, but they should stay adjacent to `TextMenuDialogs.cpp`.

Rationale: IDA MCP confirms the shared menu-dialog factory helper cluster at `0x00517450-0x00517d23`, the shared `MerchantDialogPane` base at `0x00517d30-0x00517ebf`, the main text-menu cluster at `0x00517ec0-0x0051a417`, the argumented-menu cluster at `0x0051e9a0-0x0051fc8d`, and the shared destructor/thunk island at `0x00520abb-0x00520e2b`. The classes share packet-driven dialog construction, `DialogPane`/merchant-dialog control setup, and cancellation through `TextMenuDialog::SendMenuRequestPacket`, making `ui/dialogs/` a stronger owner than generic `ui/menu/`.

### `ui/dialogs/HeadSelectDialog.cpp`

See [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md). This is a packet-driven appearance/head-selection dialog:

- `HeadSelectDialog` owns the `0x00551030-0x005520e5` constructor, preview refresh, page state, head-button population, action handling, and dialog cleanup core, plus [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md).
- It composes [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md), [UID:00006D][ImageButtonControlPane](by-class/ImageButtonControlPane.md), [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md), [UID:00009N][ObjectImageButtonPane](by-class/ObjectImageButtonPane.md), and [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md).
- Keep it separate from [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md). Both use human/head image data, but this dialog is an in-game packet/NPC flow with price/text fields and a paged 5 by 2 head grid.
- Treat the current [UID:00012T][0x0049dd00-0x0049dd17.DialogCategorySwitch](by-memory/0x0049dd00-0x0049dd17.DialogCategorySwitch.md) owner as provisional because IDA callers include fitting-room and other dialog code.

Rationale: Wave3 import provenance names `HeadSelectDialog.cpp`, and IDA MCP confirms the dialog core starts, the constructor wrapper at `0x0054ca50`, vtable refs for action/destructor paths, and unrelated neighboring dialog functions after `0x00552110`. The 2026-05-25 recheck confirms `0x00553909` is a real adjustor thunk even though disabled generated output reports missing code. This supports a dedicated dialog file rather than folding the class into generic image controls or create-user UI.

### `ui/dialogs/TextDialog.cpp`, `ui/dialogs/NexonclubProxyDialog.cpp`, and `ui/dialogs/NexonclubRegistrationDialog.cpp`

See [UID:0000OL][TextDialog](by-file/TextDialog.md), [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md), and [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md). These are adjacent packet-driven dialog/registration modules:

- `TextDialog` owns the constructor/action source methods at `0x00552110-0x0055317a` and `0x00553180-0x00553338`; the local `0x00553338-0x005534a0` tail is switch data, padding, and a no-route raw submit-packet island. B007 2026-06-19 rechecked that raw island and still found no VA/RVA/direct-branch route into it, so `TextDialog.cpp` should not emit it unless future route evidence appears. `0x005534a0-0x00553609` belongs to `NexonclubProxyDialog`.
- The previous/next/current helpers at `0x0054cc30-0x0054ce0f` are currently recovered under `TextDialog`, but they are shared by [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) action handlers as well as `TextDialog`.
- `NexonclubProxyDialog` owns the compact proxy constructor at `0x00553610-0x005538fd`; it parses a proxy packet and launches `NexonclubRegistrationDialog`.
- `NexonclubRegistrationDialog` owns the account-registration form and response flow at `0x0052f950-0x00530636`, including request submission, pending/status alerts, server response handling, and destructor/thunk support.
- Active `simroot_v2` currently omits several real registration helpers at `0x00530020`, `0x00530230`, `0x005304c0`, and `0x005304f0`; the focused [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md) also records the real `0x00530565` adjustor thunk that disabled output marks missing. Final migration should use the memory docs and [wave3_data_issues](../wave3_data_issues.md) rather than active generated source alone.

Rationale: IDA MCP confirms the exact starts for the TextDialog core, the shared dialog-navigation helpers, the Nexonclub proxy constructor, and the omitted registration support helpers. The source-order adjacency is real, but the vtable installs and behavior split the cluster into three feature-level dialog files rather than one address-locality bucket.

### `ui/dialogs/EditablePaperPane.cpp` and `ui/dialogs/TextPad.cpp`

See [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md) and [UID:0000OQ][TextPad](by-file/TextPad.md). These are text-editing dialog modules that should stay separate from the packet-driven `TextDialog`/Nexonclub range:

- `EditablePaperPane` owns the `0x00545170-0x00545e3b` server-opened paper UI: editable/read-only packet parsing, `LINE001.EPD` paper border rendering, embedded text editor setup, opcode `0x23` save serialization, destructor thunks, and the three vtable views at `0x00621afc`, `0x00621b60`, and `0x00621b90`.
- `MapPane::HandlePacket` directly constructs `EditablePaperPane` for opcode `0x1b` in editable mode and opcode `0x35` in read-only mode.
- `TextPad` owns the `0x00595900-0x00596242` full-screen local text pad/editor: two `TextEditControlPane` children, Enter-key command dispatch, close/hide handling, a null virtual, the private command helper at `0x00595be0`, and the standalone file/insert helper island at [UID:000248][0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers](by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md).
- `TextPad` has no confirmed constructor caller yet. Its `Open`, `Save`, `SetFont`, and `SetColor` command prefixes make it a local text editor/diagnostic-style UI, not a server dialog packet class.

Rationale: IDA MCP confirms the exact `EditablePaperPane` method starts, the `MapPane` opcode callers, the vtable bases in [UID:0001XF][EditablePaperPaneVtables](by-type/by-vtable/EditablePaperPaneVtables.md), and the two real destructor adjustor thunks at `0x00545ddd` and `0x00545de8`. IDA also confirms `TextPad::OnKeyInput` calls the omitted helper at `0x00595be0`, and that helper is only called from `TextPad`. The generated disabled `EditablePaperPane` row at `0x0045004e` is a generic binary-search helper inside `0x00450030`, not paper code; active `TextPad` output omits `0x00595be0`, so migration should use these docs and [wave3_data_issues](../wave3_data_issues.md) rather than generated files alone.

### `ui/dialogs/ArgumentedItemInputDialogs.cpp`

See [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md). This is a strong companion source candidate for argumented item purchase input:

- `ArgumentedItemConfirmInputDialogPane` asks the user to confirm the selected row price, alerts on mismatch, and either sends quantity `1` or opens a quantity dialog.
- `ArgumentedItemQuantityInputDialogPane` validates a quantity in `1..100` and sends the final argumented item packet.
- `SendArgumentedItemQuantityPacket` serializes the fixed 14-byte opcode `0x39` payload from `ArgumentedMenuMenuItemList` context fields.
- Adjacent helpers `0x0051f450` and `0x0051f510` should be imported or assigned before migration; `0x0051f450` is currently generated under `ChattingColorListPane`, while current Wave3 method lookup does not know `0x0051f510` even though IDA confirms it as a real function.

Rationale: IDA MCP confirms the input-dialog class range at `0x0051fc90-0x00520539` plus the preceding helper functions `0x0051f450`, `0x0051f510`, and `0x0051f640`. The behavior is specific to the argumented merchant/menu purchase flow, not generic item command prompts.

### `ui/dialogs/CommandInputPanes.cpp`

See [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md). This is a medium-confidence neighboring command-prompt module candidate:

- `EmotionInputPane` owns the emotion command prompt, the `a` through `p` emotion index mapping, and the private packet helper at `0x005b2f70`.
- `GroupInputPane` owns a line-input group command sender and opcode `0x2e`.
- `PostInputPane` owns a post-selection prompt, the corrected `0x005b5630-0x005b5890` method/helper island, and opcode `0x34`. B001 2026-06-17 models `0x005b5830-0x005b5890` as a retained file-local/private post packet helper rather than padding, compiler glue, or successor `ThrowInputPane` code.
- `SpellSpellInputPane` owns spell-to-spell selection prompt behavior and may move to a later spell-input source.
- `SelfSaveInputPane` owns a one-character self-save confirmation prompt and opcode `0x25`; review it as a command-input family member, with constructor/factory/retained-helper boundary caveats from [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md) and shared sender state via [UID:0000Q5][g_packetSender](by-global/g_packetSender.md). B007 2026-06-19 corrects the retained helper to `0x005b6870-0x005b68b1`: `0x005b68b0` is the helper `ret`, `0x005b68b1-0x005b68c0` is padding, and the best source shape is private/file-local `SendSelfSavePacket()` with no ordinary route.
- [UID:0000NN][SelfSaveOKPane](by-file/SelfSaveOKPane.md) remains a separate weak-placement guardrail for the small `TextBoxPane`-based confirmation/status pane at `0x005147d0-0x00514914`; do not fold its generated `SpelledPane` or text-control pollution into `CommandInputPanes.cpp`.
- Block-list command prompts are adjacent to this command-input neighborhood, but current evidence favors [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md) as a separate social feature file.
- IDA confirms the three-view vtable layout for the core command prompts and adjacent spell/block-list prompts; use [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md) as the layout anchor because current generated metadata still reports `vtable_count: 0` for the checked classes.
- Keep this as a separate candidate from `ItemActionInputPanes.cpp` unless later evidence proves the original file was one broad command-input pane module.

Rationale: these classes sit in the same `0x005b29c0-0x005b68b1` command-input neighborhood when the range includes the full retained SelfSave raw helper, and share prompt/input idioms with item panes, but their gameplay domains are emotion/social/spell/self-save rather than item actions. `EmotionInputPane::OnCharInput` currently has an incomplete emitted body, and the 2026-05-26 IDA recheck resolves adjacent `0x005b2f70` as its private emotion packet helper rather than a `ChangeItemSlotInputPane` constructor. The 2026-05-26 vtable pass strengthens the shared layout evidence for `EmotionInputPane`, `GroupInputPane`, `PostInputPane`, and `SelfSaveInputPane`, while preserving source-split caveats for spell and block-list prompts. B001's 2026-06-17 PostInputPane source-quality pass rejects `InputPanes.cpp`, `SpellInputPanes.cpp`, `ItemActionInputPanes.cpp`, and standalone `PostInputPane.cpp` placement; `CommandInputPanes.cpp` remains the best source-root because the constructor/key/confirm/raw-helper island is Post-specific but source-adjacent to Emotion and Group command prompts. `GroupInputPane::GroupInputPane` is a projected non-IDA function start, so migration should wait for data cleanup. `SelfSaveInputPane` adds another projected constructor/factory case at `0x005b67c0` and `0x005aa140`; B007's PE/Capstone recheck confirms the adjacent raw send helper at `0x005b6870-0x005b68b1`, proves no rel32/pointer route to it, and keeps a coordinated-family move requirement for [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md), [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md), the factory, constructor, handler, retained helper, and vtable pages rather than moving only the helper. [UID:0000NN][SelfSaveOKPane](by-file/SelfSaveOKPane.md) is included in the tree as an unresolved small dialog/pane candidate rather than a command-input class, because current caller evidence is weak and generated output contains unrelated `SpelledPane`/text-control methods. The block-list prompts continue this neighborhood at `0x005b68c0-0x005b7553`, but their config vector and opcode `0x0d` behavior make `social/BlockListenInputPanes.cpp` a stronger current source candidate.

### `ui/dialogs/PowerDialogPane.cpp`

See [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md). This is a strong feature-dialog module candidate:

- `PowerDialogPane` owns the packet-opened `Power` dialog, `POWER.EPF` painting, four threshold edit values, 5x5 row-total grid, and opcode `0x4c` apply packets.
- `PowerListPane` is the feature-private embedded list control for the four power-entry lists; it draws color swatches, handles selection/drag behavior, and should remain adjacent to the dialog rather than becoming a separate original source file.
- The current generated `PowerListPane::InitializeFromData` method at `0x00549c20` should migrate to `PowerDialogPane`, because the body calls the `DialogPane` constructor, installs `PowerDialogPane` vtables, creates the dialog controls, parses packet data, and attaches the dialog to the root pane.

Rationale: IDA MCP confirms a compact power-dialog/list island at `0x00549c20-0x0054b5d5`, ending before [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md). `MapPane::HandlePacket` packet case `0x46` allocates `740` bytes and calls `0x00549c20`, while IDA callees for that constructor include `DialogPane`, `ListPane`, list append/sort helpers, and `MultiByteToWideChar`. IDA also confirms the stale disabled `0x0054aec0` entry is not a function, so migration should use the verified range and ignore that generated method.

### `social/Chatting.cpp`

See [UID:0000I5][Chatting](by-file/Chatting.md). This is now a strong chat UI module candidate:

- `ChattingPane`, `ChattingBackPane`, `ChattingModifyHeightPane`, `ChattingVarietyPane`, `ChattingVarietySelectPane`, `ChattingHandlePane`, and `ColorStringChattingMessage`.
- Chat color UI classes: `ChattingColorPane` with exact child pages through `0x00482ca0`, `ChattingColorSelectPane` with exact child pages through `0x00482fb0`, and `ChattingColorListPane` with exact child pages through `0x00483490`.
- Chat message class: `ColorStringChattingMessage` with exact child pages through `0x004839c0`, plus compiler-generated destructor glue through `0x00483ef7`.
- `ChatInputPane`, or a split `social/ChatInputPane.cpp`, for chat history navigation and opcode `0x0e` packet send.
- [UID:000107][0x00482400-0x004824e0.GetChatButtonAtPoint](by-memory/0x00482400-0x004824e0.GetChatButtonAtPoint.md) as a file-local helper for chat handle hit-testing.
- Historical Wave2/Wave3 attachment of chat-display methods to `FolderTreePane` is superseded. `AddChattingMessage`, `AddIncomingMessage`, and source-ready `SetVisibleRowCount` are direct [UID:00001X][ChattingPane](by-class/ChattingPane.md) methods; packet helpers that are file-local remain owned by [UID:0000I5][Chatting](by-file/Chatting.md). These sources route through `social/Chatting.cpp`, while filesystem tree-control code remains separately owned by [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md).

Rationale: IDA MCP confirms a compact chat UI neighborhood at `0x0047efb0-0x00483ef7`, including the display pane, background, resize handle, variety selector, handle pane, color picker core, color message object, and destructor/thunk family. The `ChattingColorPane` local core is now split exactly through `0x00482ca0`, covering constructor, destructor body, button response, raw selector refresh, raw list sync, and padding. The `ChattingColorSelectPane` selector cluster is now split exactly through `0x00482fb0`, covering constructor, two raw helpers, draw-item, selection-changed, labels, vtable slots, and padding. The `ChattingColorListPane` swatch-list cluster is now split exactly through `0x00483490`, covering constructor, select-current helper, raw selected-color accessor, find-index helper, draw-item virtual, selected-item virtual, color-table constants, vtable slots, and padding. The `ColorStringChattingMessage` cluster is now split through `0x00483ef7`, covering constructor, destructor body, clone, line-count, draw with switch/mapping tail data, and compiler-generated destructor glue for the chat UI family. `ChatInputPane` sits later at `0x005b3940-0x005b3bba` but is feature-tied by chat history, text filtering, packet send, and `g_pChatInputPane`. Migration should wait for cleanup of the `ChattingColorPane`/`ChattingColorListPane` owner pollution and the projected non-IDA starts at `0x004810f0` and `0x005b38e0`. The 2026-05-26 recheck confirms `GetChatButtonAtPoint` is a coordinate-based file-local helper; current generated `ChattingHandlePane` call-site syntax is wrong if it passes the pane and event object.

### `social/SystemMessagePanes.cpp`

See [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md). This is now a strong chat/session message viewport module candidate:

- `SystemMessagePane` owns the scrollable system-message viewport, high/normal-resolution row metrics, help shortcut, and message row/separator drawing.
- `ColorStringSystemMessage`, `HeaderSystemMessage`, and `FooterSystemMessage` are tiny message-entry classes for colored text rows and marker entries; keep them with the system-message pane source instead of turning them into standalone original files.
- `NewSystemMessageModifyHeightPane` owns the resize grip for the newer panel and persists the saved height through the config object.
- `OldSystemMessagePane` owns the legacy fixed-row scrollable system-message pane and collection/tile cleanup.
- `NewSystemMessagePane` owns the newer panel wrapper that rebuilds child message panes, repaints the tiled frame, and refreshes its embedded world-map child.

Rationale: IDA MCP confirms the system-message pane family from `0x00584ea0-0x0058af3b`, plus non-contiguous marker/shared boolean helpers at `0x00514e60` and `0x0055c1b0-0x0055c1c3` (`SharedBooleanVirtualStubs`). These panes are chat-adjacent through `g_pChattingViewport`, but their old/new/current class family, entry-record vtables, resize-grip singleton globals, and child-pane rebuilding behavior make a separate `SystemMessagePanes.cpp` split more plausible than folding them directly into the already-large `Chatting.cpp` source candidate. Current Wave3 emitted source omits several tiny helper/thunk bodies, misplaces `NewSystemMessagePane` constructor `0x00588560` in the height-pane file, emits `ColorStringSystemMessage::GetLineCount` as a simplified constant, and omits the old constructor body, so migration should use the verified IDA ranges and behavior.

### `social/UserListDialogPane.cpp`

See [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md). This is now a strong social user-list dialog module candidate:

- `UserListDialogPane` owns the users dialog construction, high/low resolution layout variants, five user category/list buckets, sort controls, selected-user packet updates, and category/filter refresh.
- `UserListPane` owns the repeated list widget used by the dialog for drawing user rows, tracking selection, opening whisper/direct-message input, and double-click source/message actions.
- `PartySearchEditPane` is opened by the user-list command surface and owns the hunters-list/party-search settings dialog and opcode `0x84` submission path.
- `AddUserListSourceMessage_59DE60` should be kept with the user-list feature source unless later caller review proves a broader chat-output helper.
- Keep the physically interleaved `CheckBoxTextControlPane` ranges with reusable controls documentation; locality alone is not enough to absorb that generic checkbox control into this file.

Rationale: IDA MCP confirms the main user-list/user-list-pane/party-search island from `0x0059bc90-0x0059f25b`, with generic `CheckBoxTextControlPane` interleaves at `0x0059ded0-0x0059e0ab` and `0x0059efeb-0x0059f0a4`. The `UserListPane` constructor is called from the `UserListDialogPane` constructor, `PartySearchEditPane` is called from `UserListDialogPane::OnControlCommand`, and `AddUserListSourceMessage_59DE60` is called by both `UserListDialogPane::HandleUserListPacket` and `UserListPane::OnDoubleClick`. Current Wave3 source for this cluster has materialization and naming caveats, including a constructor named like `~PartySearchEditPane`, so migrations should use the IDA-confirmed boundaries and the new class/file docs as the source-layout anchor.

### `social/Group.cpp`

See [UID:0000JS][Group](by-file/Group.md). This is now a strong group/party UI module candidate, with several boundary issues to clean before migration:

- `NewGroupPane` owns the main group management UI: list request opcode `0x2d`, layout, scroll child, member row rendering, group list packet parsing, map marker update, and expanded/collapsed mode.
- `GroupPane` and `GroupPane2` are older or alternate group list panel shells and should probably stay in the same feature source file.
- `GroupListPane` is a real text-list child for `GroupPane`/`GroupPane2`; its standalone constructor at `0x0056baa0-0x0056bafd` is a raw/manual boundary, and the same setup is inlined inside both parent constructors.
- `ScrollNewGroupPane` is directly constructed by `NewGroupPane`; IDA xrefs now tie `0x00561420-0x00561d4c` to this class even though current simroot data places several helpers under `TextEditPane`.
- `RefreshGroupMemberMarkers_5ADC20` and `ClearGroupMemberMarkers_5ADC70` are group-member map-marker bridge helpers and should be cross-referenced from the group source even if their final file becomes a map/options helper.
- `SayToGroupMessageInputPane` is group-specific by payload and prompt, but may fit better in a future `social/SayInputPanes.cpp`.
- Keep `GroupInputPane` in `CommandInputPanes.cpp` unless later evidence proves the original source grouped it with the main group pane.

Rationale: IDA MCP confirms the group pane anchors from `0x0056c4c0` through `0x0056e939`, the group scrollbar from `0x00560900-0x00561db0`, the group-chat input at `0x005b1ec0-0x005b2152`, and the marker helpers at `0x005adc20`/`0x005adc70`. Wave3 currently has projected non-IDA starts at `0x0056e570`, so source migration should use confirmed IDA starts and leave that disputed boundary for cleanup. The `0x0056baa0`, `0x005619d0`, `0x00561a40`, and `0x00561d50` cases are different: IDA has no function objects, but raw disassembly confirms method-shaped islands that should be modeled manually.

### `social/Clan.cpp`

See [UID:0000I8][Clan](by-file/Clan.md) and [UID:0000I9][ClanBank](by-file/ClanBank.md). This is now a strong social clan module candidate, with the bank/item dialogs documented as a likely split file:

2026-08-14 source-placement correction: [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md) is a non-standalone, non-emitting modal-family index with path/owner `NONE`. `ui/dialogs/ClanDialogs.cpp` has been removed from the active tree. The earlier split proposal is retained in UID0000IA's historical section, but all modal class declarations and exact method/constructor children remain routed through `NexusTK/social/Clan.cpp` and `Clan.h` unless direct historical translation-unit evidence is recovered.

- `ClanStatusPane` owns the visible clan status panel, opcode `0x43` subtype `0` attribute parsing, `CLAN*.EPF` painting, keyboard/mouse tab handling, row geometry, row drawing, and owned child list panes.
- `ClanNameInputDialog` owns the shared `DLGCLAN1.EPF` name/text input shell used by deposit, withdrawal, expel, summon, appearance-name, and rename flows.
- `ClanAttrInputDialog` owns the `DLGCLAN2.EPF` multi-field attribute dialog; `ClanChangeInputDialog` derives from it for multi-field clan changes.
- `ClanEnlistInputDialog` owns the enlistment modal constructor/submit path; generated packet-parser labels in this area need IDA owner checks because `0x004842b0` is a `ClanStatusPane` parser.
- `ClanLeaveConfirmDialog`, `SendClanLeaveResponse`, `SendClanAttributePacket`, `SubmitClanChangeHelper_486330`, and the row-action helper at `0x00487600` are Clan opcode `0x4b` packet helpers/dispatchers.
- `ClanBankPane`, `ClanBankItemListPane`, `ClanItemDialog`, `ClanItemListPane`, `ClanDepItemDialog`, and `ClanWidItemDialog` form a documented `social/ClanBank.cpp` or `social/ClanItemDialogs.cpp` split candidate.

Rationale: IDA MCP confirms the main Clan status/dialog helper starts at `0x00484030`, `0x004842b0`, `0x00484a60`, `0x00484cd0`, `0x00484db0`, `0x00485700`, `0x00485ac0`, `0x00486330`, `0x00486800`, `0x00486d20`, `0x00486f90`, `0x00487600`, `0x00488b40`, `0x00488eb0`, `0x00488f30`, `0x00488f70`, `0x00488fe0`, `0x004890b0`, `0x00489180`, `0x004892b0`, `0x004893e0`, `0x00489510`, `0x00489600`, `0x00489df0`, `0x00489ec0`, `0x00489f50`, `0x00489fc0`, `0x0048a030`, `0x0048a0a0`, `0x0048a0b0`, and `0x0048c590`. The bank/item split adds confirmed starts at `0x0048a100`, `0x0048a120`, `0x0048a1c0`, `0x0048a6b0`, `0x0048a790`, `0x0048a810`, `0x0048ad10`, `0x0048adf0`, `0x0048ae70`, `0x0048b0a0`, `0x0048b1c0`, `0x0048b630`, `0x0048b8c0`, `0x0048c040`, `0x0049ec80`, `0x0049ed60`, `0x004ba820`, and `0x004ba8b0`. Wave3 projected many constructor starts in this neighborhood that IDA reports are not functions, so migrations should anchor to the confirmed starts and treat those constructors as projected until cleanup.

### `social/SayInputPanes.cpp`

See [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md). This is now a strong social chat-input module candidate:

- `SayToPlanMessageInputPane` currently owns chat-mode dispatch helpers that open default say, shout, whisper/direct-message, group, and plan/clan-style message panes.
- `SayInputPane` owns default say input, chat history navigation, and opcode `0x0e` subtype `0`.
- `ShoutInputPane` owns shout input and opcode `0x0e` subtype `1`.
- `SayToUserNameInputPane`, `SayToUserMessageInputPane`, and `NewSayToUserMessageInputPane` own legacy and modern whisper/direct-message flows.
- `SayToGroupMessageInputPane` is cross-owned by the group feature and may either stay here or move to `social/Group.cpp`.
- `ChatInputPane` remains documented under `social/Chatting.cpp`, but its address locality and packet shape should be considered during final source split review.

Rationale: IDA MCP confirms mode/helper functions at `0x005a4b60-0x005a5791`, target-message panes at `0x005b1570-0x005b2562`, default say at `0x005b34d0-0x005b37ea`, recipient-name flow at `0x005b3cb0-0x005b4219`, and shout submit at `0x005b4260-0x005b43bc`. Wave3 projected constructor starts at `0x005b3490` and `0x005b4220` are not IDA functions, so migrations should use the confirmed starts.

### `social/BlockListenInputPanes.cpp`

See [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md). This is now a strong block-list command prompt module candidate:

- `BlockListenInputPane` owns the top-level block-list command prompt, Ctrl+`?` list display, add/delete action dispatch, and localized list-state alerts.
- `AddToBlockListenInputPane` owns add-name validation, local config vector insertion, config persistence, and opcode `0x0d` subcommand `0x02`.
- `DeleteFromBlockListenInputPane` owns matching entry removal, vector erase, config persistence, and opcode `0x0d` subcommand `0x03`.
- `FindBlockListEntry_5B74E0` is a private helper used by both add and delete handlers.
- Keep shared line-input helpers `0x004f2300` and `0x004f2310` in [UID:0000K7][InputPanes](by-file/InputPanes.md).
- Use [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md) for the three-view vtable layout shared by the block-list prompt trio.

Rationale: IDA MCP confirms handlers at `0x005b6900`, `0x005b6a20`, `0x005b6cc0`, `0x005b7140`, and a private helper at `0x005b74e0`. The constructor starts at `0x005b68c0`, `0x005b6c80`, and `0x005b7100` are real constructor-shaped bytes but not IDA function objects. This cluster is near command-input panes, but the state and packets are a social block-list feature.

### `social/FriendListDialog.cpp`

See [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md). This is a strong one-class social dialog file candidate:

- `FriendListDialog` builds a fixed 20-slot friend-name editor in two columns.
- It supports both `FRIEND.EPF`/`FRIEND.PAL` and fallback `FRIEND.EPD`/`NPAL8.PAL` asset layouts.
- `OnOkButton` writes the edited friend names back to the config string table, saves settings, and closes the dialog.

Rationale: IDA MCP confirms constructor, OK handler, focus handler, thunk, and destructor starts at `0x0053f2c0`, `0x0053f830`, `0x0053f930`, `0x005425b5`, `0x005425c0`, and `0x005426e0`. The class is small and feature-specific enough that it likely lived in its own dialog file or a social dialogs file, not in generic `DialogPane.cpp`. A 2026-05-25 send-helper pass also shows `OnOkButton` calls [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md), which reads the same 20 config friend-name slots and serializes opcode `0x77`; [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md) identifies the other trigger as `MapPane` inbound case `0x6a`. Keep the editor in `social/FriendListDialog.cpp` while leaving the queued-send helper in the request-sender cluster until that interface is resolved.

### `audio/SoundManager.cpp/.h` and `audio/MidiPlayer.cpp/.h`

See [UID:0000NV][SoundManager](by-file/SoundManager.md), [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md), and [UID:0001Q8][client_audio](by-meta/client_audio.md). These are now strong audio module candidates:

- `SoundManager` owns Miles Sound System setup, stream/sample volume policy, DAT-backed `%03d.wav` sound-effect cache, DAT-backed `%08d.LST`/`%08d.LSR`/`%08d.MP3` zone music selection, local music-directory scanning, and Redbook/CD fallback.
- `MidiPlayer` owns the WinMM MIDI stream singleton, [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md), MIDI buffer/header lifetime, the `MidiPlayer_ResetStream`/`ReleaseMidiBuffers_525B10` helper family at `0x00525b10-0x0052664b`, the [UID:00023B][0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers](by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md) Standard MIDI File reader/parser island, and the [UID:00023C][0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers](by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md) document-load/stream-fill island.
- `SoundManager.h` is now a closed standalone route: UID0004UF opens one guard with seven direct platform/project includes, bounded local Miles ABI declarations and all 37 imports plus `g_pSoundManager` extern; UID0000DG emits the complete class and closes the guard. No unavailable SDK header, new shim, or PCH-only dependency is assumed.
- `MidiPlayer.h` now contains the complete `0x0c` class declaration and `g_pMidiPlayer` extern, while `MidiPlayer.cpp` begins with its own header include before existing child source.
- [UID:0000DI][SoundPathVector](by-class/SoundPathVector.md) is the restored begin/end/capacity path-vector helper for SoundManager playlist and scanned music-path storage. Keep it in `SoundManager.cpp` or a small audio helper file until wider callers are found.
- Keep `DATFile` and [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) in archive/resource modules; `SoundManager` consumes them but does not own DAT parsing.
- Timer wrappers at `0x00597610` and `0x00597630` are generic `TimerHandler` wrappers and should not be migrated with audio despite current generated SoundManager ownership.

Rationale: IDA MCP confirms all main `SoundManager` starts from `0x005797b0` through `0x0057bb30`. Decompilation confirms playlist files, DAT lookups, Miles AIL calls, Win32 loose-file scanning, and Redbook helper behavior in one class-centered audio cluster. Cached prewave/metadata evidence ties `MidiPlayer` and its reset/buffer helpers to the WinMM MIDI path rather than Miles/MP3 playback. A 2026-05-28 IDA recheck resolves the former gap after `0x0052664b` as MIDI file/adapter read, SMF track parse, stream-event encoding helpers, and SMF document load/stream-fill helpers through `0x005277bb`, so it should stay under `audio/MidiPlayer.cpp` unless later evidence proves a separate MIDI document file. A 2026-05-24 IDA recheck shows `0x00597610` and `0x00597630` forward through `g_pTimerMgr` and have non-audio caller evidence, so those wrappers belong to the timer scheduler module.

### `network/Socket.cpp`, `network/PacketBuffer.cpp`, `network/PacketTransform.cpp`, `network/FileDownloader.cpp`, and `cashshop/CashShopRequest.cpp`

See [UID:0000NS][Socket](by-file/Socket.md), [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md), [UID:0000M9][PacketTransform](by-file/PacketTransform.md), [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md), [UID:0000L6][MD5](by-file/MD5.md), [UID:0000JC][FileDownloader](by-file/FileDownloader.md), [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md), and [UID:0001QH][client_network](by-meta/client_network.md). The packet/transport layer now has stronger file-level anchors:

- `Socket.cpp` owns the stateful transport class: TCP mode 5, mode 6 callback dispatch, COM/serial transport, receive parsing, transform sequencing, final outbound framing, and [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) lifetime.
- `PacketBuffer.cpp` owns the shared C-style scalar packet helpers around `0x00575380-0x00575abb`.
- `PacketTransform.cpp` owns handshake/key-table helpers and transform globals around `0x00575cb0`, `0x00577030`, and `0x00578e00`, plus address-backed state at `0x0066fe50`, `0x0066fe58`, and `0x0069ba40+`; it may fold into a private `Socket.cpp` helper section if later source evidence proves a monolithic socket file.
- `util/MD5.cpp` owns the digest helper family around `0x005151f0-0x00515f48`; [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md) calls into it at `0x00515380` for packet trailer digest bytes.
- `FileDownloader.cpp` owns the shared WinINet worker-thread dispatcher for downloader messages `10000`, `10001`, and `10002`, plus the currently associated minimap file and cash-shop version/catalog HTTP helper calls. A 2026-05-25 xref pass also ties `dword_67A738` / [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) lifetime writes to the FileDownloader constructor/destructor family.
- `CashShopRequest.cpp` currently owns request payload setup, synchronous wait/result helpers, and the broad `QueueAndSendPacket` funnel, but the `g_packetSender` lifetime evidence and current `Thread::DispatchRequest` emission make the queue/send method boundary provisional. The adjacent downloader request submission helpers at `0x0041b180`, `0x0041b200`, and `0x0041b270` are also provisional because live callers pass the FileDownloader-lifetime singleton. The `0x00574d40-0x00575377` send/status tail is real, but not cash-shop-specific by caller evidence: [UID:0001HW][0x00574d40-0x00574e44.QueueClientVersionStatusPacket](by-memory/0x00574d40-0x00574e44.QueueClientVersionStatusPacket.md) is reconnect/terminal-facing, [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md) is the [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md) upload response to inbound map case `0x6a`, and [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md) is map-packet-facing.
- `Thread.cpp` owns the generic `0x00596960` queue post primitive unless later class-layout evidence proves a derived override or wrapper.
- `ProtocolSend.cpp` should remain a placeholder until cross-feature free send helpers or a request-sender interface are clustered; it should not absorb `Socket`, base-thread queue primitives, packet scalar helpers, or packet transform helpers by default.
- Historical `Session.cpp` planning placeholder: rejected by the 2026-08-15 exhaustive [UID:0000NP][Session](by-file/Session.md) audit. Complete function/global/name/string/type/import searches, all 40 Session-named documentation paths, generated output, and login/transport/thread/game-dispatch candidate analysis found no generic class, global, lifetime bridge, source island, header consumer, or emitted fragment. Keep the physical tree entry absent. Reopen only for external build provenance or a newly recovered direct generic object/cluster; another caller of existing Socket/Thread helpers is not sufficient. This decision does not affect the separate `ProtocolSend.cpp` placeholder.

Rationale: IDA MCP confirms exact packet helper starts from `0x00575380` through `0x00575a90`, with `WriteByteZ_575380` alone having 1114 code refs from 662 unique calling functions. IDA also confirms [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) at `0x00574bb0-0x00574c13` with 416 refs from 380 unique calling functions, while `Socket::SendEncodedPacket` at `0x00576660-0x00576c75` has only three direct callers and performs the final transport framing/write. Current `simroot_v2/class_Thread.cpp` emits `0x00596960` as `Thread::DispatchRequest`, and IDA decompilation shows a generic six-dword queue record plus semaphore release. A 2026-05-25 IDA MCP xref sweep for `0x0067a7ec` found 489 xrefs and five direct writes, all in the Socket constructor/destructor family; [UID:0001I6][0x005794c0-0x005794cb.ClearPacketSenderGlobal](by-memory/0x005794c0-0x005794cb.ClearPacketSenderGlobal.md) is the constructor-unwind clear helper and `0x005795a0` is the Socket vtable deleting destructor. The packet transform helpers form a separate protocol-support group: `InitializePacketNonce` at `0x00575cb0` is called only by [UID:0001I3][0x00578b20-0x00578c40.SocketTransformFramePayload](by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md) and [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md), `BuildHandshakeBlock` at `0x00577030` is called by the Socket constructor and command `14`, and `XorTransformBuffer` at `0x00578e00` is the shared inbound/outbound XOR primitive. A 2026-05-25 disassembly pass ties this helper family to [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md), including the dword LUT at `0x0066fe58` and the `0x0069ba40+` handshake/nonce table block. The digest helper called by `BuildEncryptedPacket` at `0x00515380` belongs to the separate MD5 island because the same utility family is used by startup/minimap hash handling and screenshot proof submission. Separately, IDA confirms `FileDownloader::OnMessage` at `0x0041b110` dispatching WinINet helpers and confirms `FileDownloader::StartThread` has broad worker-thread callers, so HTTP download dispatch should not be merged into `Socket.cpp` or inferred as pure cash-shop code. A companion `0x0067a738` xref sweep found 9 refs and five direct writes, all FileDownloader constructor/destructor-family writes, with [UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md) covering the constructor-unwind clear helper. This supports utility helper files, a request queue class file, an HTTP downloader file, a packet transform helper file, and a transport class file rather than one monolithic network source.

### `cashshop/FittingRoom.cpp`, `cashshop/ItemCatalog.cpp`, and `cashshop/CashShopVersionRequest.cpp`

See [UID:0000JE][FittingRoom](by-file/FittingRoom.md), [UID:0000KD][ItemCatalog](by-file/ItemCatalog.md), and [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md). The cash-shop fitting-room feature is now a stronger module candidate:

- `FittingRoom.cpp` owns the dialog shell, preview user-image pane, fitting-room item list, fitting-room scrollbar, action buttons, equipment-state reset, download-progress pane, and item-cache state.
- `ItemCatalog.cpp` is a small optional split for the embedded catalog lookup at `g_pFittingRoomDialog + 0x504`; it may fold back into `FittingRoom.cpp`.
- `CashShopVersionRequest.cpp` owns the tiny version-request payload semantics. The version request submission helper at `0x0041b270` currently dispatches through the FileDownloader-lifetime `dword_67A738` singleton, so its final file owner remains tied to the FileDownloader/CashShopRequest boundary review. The WinINet item-shop version/catalog helpers are dispatched through [UID:0000JC][FileDownloader](by-file/FileDownloader.md) and may either stay as file-local downloader helpers or become fitting-room/cash-shop static helpers after ownership review.

Rationale: IDA MCP confirms the compact fitting-room UI/state core around `0x0041ba40-0x004245f5`, plus item-shop download helpers at `0x0041aa00` and `0x0041ae20` and version request submission at `0x0041b270`. Generated source shows `ItemShop.jbn` cache handling, the `itemshop.json` WinINet download, and `FittingRoomDialog` constructing the dialog controls and sending the version request. Wave3 currently has projected starts and helper pollution in this area, so the confirmed local fitting-room core should drive migration before broad method ownership moves. A 2026-05-25 IDA recheck found no current xrefs to projected starts `0x0041b9e0`, `0x0041c250`, or `0x0041d6c0`; `FittingRoomListPane` instead inlines scrollbar child setup at `0x0041eb90`. The generated `FittingRoomUserImageControlPane` owner for `0x00495450` is also polluted; decompilation places that function in the generic `TextButtonExControlPane` / `ButtonControlPane` family.

### `map/MiniMap*.cpp`

See [UID:0000LE][MiniMap](by-file/MiniMap.md). This is a strong feature-folder candidate, while the exact file split remains open:

- [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md), [UID:00008F][MiniMapRenderer](by-class/MiniMapRenderer.md), `MiniMapDownloader`, `MiniMapVersionManager`
- [UID:00008E][MiniMapImageControlPane](by-class/MiniMapImageControlPane.md), [UID:00008G][MiniMapSymbolControlPane](by-class/MiniMapSymbolControlPane.md), [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md)
- `DownloadMinimap`, `GetControlLayout_452260`; `DownloadMinimapFile` currently cross-links through [UID:0000JC][FileDownloader](by-file/FileDownloader.md)

IDA MCP confirms `DownloadMinimap` is called from the minimap downloader task callback, `GetControlLayout_452260` is called repeatedly from the minimap dialog constructor, and `MiniMapVersionManager` construction/use crosses startup/update-check code while retaining minimap-owned version state. A 2026-05-24 recheck confirms the local [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md) and the [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md), while generated `MiniMapDialog` rows at `0x004517a0` and `0x00452ce0` are not IDA function starts and `0x0049db60+` helper rows have broad shared-dialog caller evidence. A 2026-05-25 recheck adds [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md) as a missing active-output `MiniMapVersionManager` method used by renderer version checks. `MiniMapButtonPane` is constructed from [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) at `0x004f80c2` and sits in the [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md), so migrate it by method ownership rather than by the older MapName-only aggregate span. `DownloadMinimapFile_41A750` downloads the same `.mnm` family but is reached through `FileDownloader::OnMessage` message `10000`, so keep it linked to the shared downloader until the old/new minimap download paths are reconciled.

### `render/Palette.cpp`

See [UID:0000MA][Palette](by-file/Palette.md). This groups:

- `PaletteLib`, `DLPalette`, `g_pPaletteLib`, and the `ScreenPanePaletteState_543D30` screen-palette facet/base methods
- palette slot constants/table for `TILE.PAL`, `ITEM.PAL`, `EFFECT.PAL`, `ALL.PAL`, `BACK.PAL`, and related sprite-family palettes
- `LoadedPaletteEntry`, `ApplyPaletteEntryMovesToCollection`, palette-list clone/reset helpers, the raw palette collection color-transform helper, and `PaletteLib` runtime palette-filter helpers.

Rationale: `PaletteLib` constructs and owns many `DLPalette` objects, loads all category palette sets during startup, and provides the runtime palette-selection API used by EPF/tile/image rendering. It depends on `DATFile` for stream reads but is not archive parsing code. A 2026-05-25 IDA MCP pass identifies `g_pPaletteLib` at `0x0067a7e0` and promotes `0x00543f60`/`0x00543f80` into `PaletteLib`. A 2026-05-26 IDA MCP pass shows `ScreenPanePaletteState_543D30::SetMode` and `ResetSlots` are also called with `g_pPaletteLib` as `this`, and `PaletteLib::PaletteLib` initializes their mode/list/bank fields; keep their separate docs as a generated-class/facet view, not as evidence for `ui/core/ScreenPane.cpp` ownership. A 2026-06-01 IDA MCP pass corrects `DLPalette` to the primary cluster `0x00542ac0-0x00543149` plus scalar deleting destructor `0x005443b0-0x00544411`, corrects the palette-list/move helpers to `0x00543450-0x00543665`, splits raw helper `0x00543670-0x005436f4`, and confirms related alignment padding before `PaletteLib::PaletteLib` and `PaletteLib::ScalarDeletingDestructor`.

### `render/Effects.cpp`

See [UID:0000IZ][Effects](by-file/Effects.md). This groups the runtime visual effecter family currently emitted as many one-class files:

- `ScreenEffecter`, `PixelEffecter`, `OverlayEffecter`, and `FilterEffecter` base classes.
- Overlay effecters: `OverlayImageEffecter`, `OverlayFrameImageEffecter`, `OverlayImageOnPointEffecter`, and `OverlayMovingImageEffecter`.
- Filter and map/pixel effects: `SolidColorFilterEffecter`, `CloudFilterEffecter`, `StaticCloudFilterEffecter`, `WaterFilterEffecter`, `EarthquakeEffecter`, `XWaveEffecter`, `YFlipEffecter`, and `LakeEffecter`. The exact `WaterFilterEffecter::UpdateCausticEffect` body at [UID:0001GF][0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect](by-memory/0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect.md) is not a `DrawPictureObjectPane` function.
- `EffectObjectPane` as a likely neighboring runtime effect-object class, pending final split review.
- Do not include generated `g_pScreenEffecterList` as an effects global; IDA/simroot review resolves it as a stale alias for `dword_69B364`, a shared main UI graph layer/context slot.

Rationale: the effecter methods cluster tightly at `0x0055a260-0x0055c1ff`, share `ScreenEffecter`/pane/vtable setup patterns, and orchestrate runtime drawing over `MapPane`/render layers. [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md) now records the IDA-confirmed vtable order from `0x006235a4` through `0x00623cf8`, including the four-view overlay/filter object shape. Keep [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md) separate because it owns effect sprite asset tables and archive loading rather than runtime effect application.

Keep [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md) and [UID:00036Q][ScreenFadeOut](by-file/ScreenFadeOut.md) separate from `render/Effects.cpp` for now. `ScreenDimmer` and `ScreenFadeOut` form adjacent generic UI overlay pane files at `0x00559b90-0x0055a252`, immediately before but not part of the `ScreenEffecter` runtime effecter cluster.

### `render/MapTileImageLib.cpp`, `render/StaticObjImageLib.cpp`, `render/EffectObjImageLib.cpp`

See [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md), [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md), and [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md). These are now stronger separate render/image module candidates:

- `MapTileImageLib` owns `TILE.TBL`, `TILE.TBD`, `TILE%d.EPF`, [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md), [UID:0001Y3][MapTileImageLibVtable](by-type/by-vtable/MapTileImageLibVtable.md), [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md), [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md), and [UID:0000V0][LoadTileEpfMetadata_004D1B80](by-item/LoadTileEpfMetadata_004D1B80.md).
- `StaticObjImageLib` owns `SOBJ.TBL`, `TILEC.TBL`/`TILEC.TBD`, `TILEC.EPF`/`TILEC.EPD`, [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md), [UID:0001YX][StaticObjImageLibVtable](by-type/by-vtable/StaticObjImageLibVtable.md), [UID:0001W9][StaticObjImageLibLayout](by-type/by-struct/StaticObjImageLibLayout.md), [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md), [UID:0001WC][TileClassEntry](by-type/by-struct/TileClassEntry.md), [UID:00017J][0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject](by-memory/0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject.md), and [UID:0000U6][BuildTilecArchiveTable_004DDA60](by-item/BuildTilecArchiveTable_004DDA60.md).
- `EffectObjImageLib` owns `EFFECT.TBL`, `EFFECT.FRM`, `EFFECT.EPF`/`EFFECT.EPD`, [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md), [UID:0001XG][EffectObjImageLibVtable](by-type/by-vtable/EffectObjImageLibVtable.md), [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md), [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md), [UID:0001U7][EffectFrameRecord](by-type/by-struct/EffectFrameRecord.md), [UID:0001UA][EffectPixMapInfo](by-type/by-struct/EffectPixMapInfo.md), [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md), [UID:0000U4][BuildEffectArchiveTable_004DE420](by-item/BuildEffectArchiveTable_004DE420.md), and the effect-specific [UID:0000UR][GetSpriteBounds_004DE2A0](by-item/GetSpriteBounds_004DE2A0.md) helper.

Rationale: each class has one startup constructor caller, a distinct global singleton, distinct resource families, and one-caller archive-table builder helpers. IDA confirms `MapTileImageLib` also has an ordinary destructor at `0x004d19a0`, a singleton-clear helper at `0x004e5bc0`, and a primary vtable at `0x0061b664`; active Wave3 output currently misses those details. IDA similarly confirms `StaticObjImageLib` has an ordinary destructor at `0x004dd1e0`, a disabled-but-real renderer at `0x004dd2c0`, a singleton-clear helper at `0x004e5c00`, and a primary vtable at `0x0061b704`. IDA confirms `EffectObjImageLib` has an ordinary destructor at `0x004de050`, a disabled-but-real renderer at `0x004de190`, a singleton-clear helper at `0x004e5b70`, singleton storage at `0x0069b44c`, and a primary vtable at `0x0061b724`. This supports separate original `.cpp` files rather than merging all asset libraries into `ImageLib.cpp`.

### `render/ItemObjImageLib.cpp`, `render/RidingImageLib.cpp`, `render/LightObjImageLib.cpp`

See [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md), [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md), and [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md). These continue the per-asset image-library split:

- `ItemObjImageLib` owns `ITEM.TBL`/`ITEM.TBD`, item draw variants, `ITEM.EPF`/`ITEM.EPD` frame lookup, [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md), [UID:0001XW][ItemObjImageLibVtable](by-type/by-vtable/ItemObjImageLibVtable.md), [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md), [UID:0001UT][ItemInfo](by-type/by-struct/ItemInfo.md), [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md), and likely the shared [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md) helper or a neighboring item-image helper file.
- `RidingImageLib` owns `RIDINGS.DNA`, `RIDINGS.EPF`, [UID:0000S4][g_pRidingImageLib](by-global/g_pRidingImageLib.md), [UID:0001YM][RidingImageLibVtable](by-type/by-vtable/RidingImageLibVtable.md), [UID:0001VW][RidingImageLibLayout](by-type/by-struct/RidingImageLibLayout.md), [UID:0001VV][RidingDefinition](by-type/by-struct/RidingDefinition.md), [UID:0000TJ][RidingDefinitionGlobalTable](by-global/RidingDefinitionGlobalTable.md), the [UID:00017G][0x004dc730-0x004dc7d8.RidingImageLibDestructor](by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md), the [UID:000183][0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper](by-memory/0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper.md), and the constructor-only `LoadRidingDefinitions` parser.
- `LightObjImageLib` owns `LIGHT.TBL`, generated radial light frames, [UID:0002IU][0x004df7e0-0x004dfaa6.LightObjImageLibConstructor](by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md), [UID:0002IV][0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds](by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md), [UID:0002IW][0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1](by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md), [UID:0002IX][0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2](by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md), [UID:0000RD][g_pLightObjImageLib](by-global/g_pLightObjImageLib.md), [UID:0001XY][LightObjImageLibVtable](by-type/by-vtable/LightObjImageLibVtable.md), [UID:0001UX][LightObjImageLibLayout](by-type/by-struct/LightObjImageLibLayout.md), [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md), the [UID:00017Q][0x004dfab0-0x004dfb36.LightObjImageLibDestructor](by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md), the [UID:00017Z][0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper](by-memory/0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper.md), and the [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md).

Rationale: each class has a startup singleton constructor, a distinct resource family, and asset-specific parse/render policy. IDA confirms `ItemObjImageLib` has a primary vtable at `0x0061b73c`, unmodeled ordinary destructor at `0x004dee20`, and singleton-clear helper at `0x004e5ba0`; active generated metadata currently reports `vtable_count: 0`. IDA confirms `RidingImageLib` has a primary vtable at `0x0061b6f4`, unmodeled ordinary destructor at `0x004dc730`, singleton-clear helper at `0x004e5bf0`, singleton storage at `0x0069b444`, and a global default riding table at `0x0069b430`; active generated metadata reports `vtable_count: 0` and splits `g_ridingDefinitionBuckets` as if it were standalone global-data even though IDA shows it is the `+0x08` field of the global table object. IDA likewise confirms `LightObjImageLib` has a primary vtable at `0x0061b754`, adjacent `ProtectedArray<LightInfo>` vtable at `0x0061b74c`, unmodeled ordinary destructor at `0x004dfab0`, singleton-clear helper at `0x004e5bb0`, and singleton storage at `0x0069b450`; active generated metadata also reports `vtable_count: 0` for this class. `RidingImageLib` still depends on the shared EPF frame-table loader, while `LightObjImageLib` is DAT-backed but procedural rather than EPF-table-backed.

### `render/HumanImageLib.cpp`, `render/NewHumanImageLib.cpp`, `render/MonsterImageLib.cpp`

See [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md), [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md), and [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md). These are strong per-family image-library modules:

- `HumanImageLib` owns old-format human/equipment frame-table resources loaded through `LoadImageFrameTable_4D0F50`, [UID:0000R5][g_pHumanImageLib](by-global/g_pHumanImageLib.md) at `0x0069b43c`, [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md), vtable `0x0061b6d4`, and the ordinary destructor/cleanup body at `0x004d4ad0`.
- `NewHumanImageLib` owns the newer table-driven human composition pipeline around `Motion.tbl`, `Layer.tbl`, `Part.tbl`, per-part descriptor tables, `acc2drw.tbl`, `HAIRCOL.TBL`, [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md), [UID:0001Y9][NewHumanImageLibVtable](by-type/by-vtable/NewHumanImageLibVtable.md), [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md), and `ResolveSpritePartPath`.
- `MonsterImageLib` owns `MONSTER.DNA`/`MONSTER.DND`, numbered `DATA/MON%d.DAT` archive indexing, [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md), [UID:0001Y7][MonsterImageLibVtable](by-type/by-vtable/MonsterImageLibVtable.md), [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md), [UID:0001VC][MonsterImageEntry](by-type/by-struct/MonsterImageEntry.md), [UID:0001VA][MonsterArchiveBoundsBucket](by-type/by-struct/MonsterArchiveBoundsBucket.md), monster render callbacks/config globals, lazy bounds buckets, and cache teardown.
- [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md) documents two small helper classes shared by the monster and riding parsers; current projected placement is `NexusTK/render/MonsterImageLibTables.cpp`, while the final neutral helper type names remain open.

Rationale: each class has distinct resource families and singleton/render policy. They are DAT/EPF consumers, not archive parser code, and are large enough that a single monolithic `ImageLib.cpp` would be an unlikely final reconstruction target. IDA confirms `NewHumanImageLib` has singleton storage at `0x0067a760`, primary vtable `0x0061b76c`, ordinary destructor `0x004e0250`, and singleton-clear helper `0x004e5be0`; active generated metadata currently reports `vtable_count: 0` and emits multiple caller-biased shared render globals in this class file. IDA confirms `MonsterImageLib` has singleton storage at `0x0069b440`, primary vtable `0x0061b6e4`, ordinary destructor `0x004db010`, singleton-clear helper `0x004e5bd0`, and disabled-but-real archive-bounds loader `0x004dbe60`; active generated metadata currently reports `vtable_count: 0` and incomplete global memory coverage for this class.

### `render/FontImageLib.cpp`

See [UID:0000JH][FontImageLib](by-file/FontImageLib.md). This is a strong render/text-support module:

- `FontImageLib`, `g_pFontImageLib`, and two large font slots.
- `BARAM00.EFT`/`BARAM01.EFT` DAT-backed font archives loaded lazily through `EnsureFontSlotLoaded`.
- `GetFontMetrics`, `MeasureGlyphWidth`, and `DecodeGlyphBitmap` for UI text measurement and glyph materialization.
- [UID:0001XM][FontImageLibVtable](by-type/by-vtable/FontImageLibVtable.md) at `0x0061a5f4`, [UID:0001UL][FontImageLibLayout](by-type/by-struct/FontImageLibLayout.md), and the ordinary destructor at [UID:00015B][0x004b5f60-0x004b5fe6.FontImageLibDestructor](by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md), all verified through IDA because current Wave3 metadata omits the vtable/destructor.

Rationale: this class owns a distinct font resource family and a large private glyph table layout. It depends on `DATFile` and `EPFTileContext`, but is not an archive parser or generic image-library class.

### `render/EPFTileContext.cpp` and `render/ImageFrameTable.cpp`

See [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md), [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md), and the umbrella [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md) page. Current evidence supports two shared render-resource support files:

- `EPFTileContext` owns decoded EPF/EPD frame pixel buffers, bounds, row stride, auxiliary data, and the encoded RLE transparency mask cache.
- `ImageFrameTable` owns `LoadImageFrameTable_4D0F50`, `LoadFrameDrawRecord_4D1600`, and the shared frame-record/table shape used by old human/equipment, riding, static object, UI/effect, and related render callers.
- Asset-specific one-caller table builders still stay with their owning image-library files: `LoadTileEpfMetadata` with `MapTileImageLib`, `BuildTilecArchiveTable` with `StaticObjImageLib`, `BuildEffectArchiveTable` with `EffectObjImageLib`, and `ResolveSpritePartPath` with `NewHumanImageLib`.

Rationale: `EPFTileContext` is a small reusable context object with broad callers, while `ImageFrameTable` is the generic frame metadata loader/projection helper. Both depend on the DAT API but are render-resource code rather than archive parsing.

### `render/ImageLib.cpp` and `render/ResourceLayoutTable.cpp`

See [UID:0000K2][ImageLib](by-file/ImageLib.md) and [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md). Current evidence supports `ImageLib` as the owner of:

- `ImageLib`, the process-wide EPF/EPD image/layout registry singleton.
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / `DAT_0067a744`, initialized and cleared by `ImageLib`.
- [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md) at `0x0061b654`, whose three slots prove the layout API is not virtual on `ImageLib`.
- [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md), the 0x14-byte object layout with `List*` registry at `+0x0c`.
- The unmodeled ordinary destructor at [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md), which performs the same registry payload cleanup as the scalar deleting destructor without deleting `this`.
- A `+0x0c` [UID:000079][List](by-class/List.md) of 44-byte [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md) rows. [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md) and [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md) are provisional aliases over this list-backed model.

The `ResourceLayoutTable` method family is a close helper/facet over the same singleton object: it is non-virtual relative to the observed `ImageLib` vtable and may either fold into `ImageLib.cpp` or remain a nearby `ResourceLayoutTable.cpp` helper. The suspected store vtable owner is now resolved as the generic `List` vtable at `0x0061ce2c`. A 2026-05-26 recheck still supports preserving the two-argument `ImageLib` constructor API even though the current body only uses the first stack argument.

Rationale: IDA MCP xrefs show the `0x0067a744` global writes in `ImageLib` construction/destruction, while ResourceLayoutTable methods and hundreds of UI/render calls consume the singleton. The same pass shows `ImageLib::ImageLib` calls `List::List(44, 10)` for the registry field, and vtable xrefs to `0x0061b654` land only in the ImageLib constructor/destructor family. Treating it as a second independent global, a per-control owner, or a custom store class would make the reconstructed source less faithful.

### `render/DIBitmap.cpp` and `render/ImageLoaders.cpp`

See [UID:0000IV][DIBitmap](by-file/DIBitmap.md) and [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md). Current evidence supports:

- `DIBitmap` as the Win32 16-bit top-down DIB wrapper.
- [UID:0001U6][DIBitmapLayout](by-type/by-struct/DIBitmapLayout.md) as the IDA-confirmed field map for the wrapper, replacing the current generated metadata's noisy `0x60` layout for reconstruction purposes.
- `DIBitmap` destructor/accessor helpers at `0x004a1740-0x004a17ad` half-open, including the raw non-deleting destructor body and guarded width/height accessors currently omitted from active generated source.
- `LoadPcxImage` and `CreateDIBitmapFromPcxBuffer` as adjacent startup PCX helpers.
- `DecodePcxToRgb565Buffer` as a likely codec/helper translation unit because it links far from the DIB wrapper cluster.
- [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md) as shared legacy image decode glue for `ZPF`/`FPF`, raw `FPF`, `JPF`, 8-bit `BM`, raw JPEG, and PNG file/resource tile-context loads.

Rationale: the startup PCX loader is DAT-aware but owns GDI bitmap creation and PCX/RGB565 conversion. The `0x004d05f0-0x004d0f4a` helpers are likewise resource/profile/minimap/PNG decode boundaries over project formats and tile contexts. They should remain in render/image-loader support, not `archive/`, `profile/`, or `map/`. A compact original file could have combined `DIBitmap` and the two adjacent PCX helpers, but the proposed tree keeps the free loader/codec pipeline visible as `ImageLoaders.cpp`. The [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md) and raw/accessor cluster confirm that the wrapper itself still needs a real `DIBitmap.cpp` ownership node even where generated source collapses or omits tiny methods.

### `render/ImageWriters.cpp` and `render/ScreenshotCapture.cpp`

See [UID:0000K4][ImageWriters](by-file/ImageWriters.md), [UID:0000KW][LodePNG](by-file/LodePNG.md), [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md), [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md), [UID:0001G8][0x00557840-0x00557a96.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md), and [UID:0000VF][ScreenshotProofPacket_00558240](by-item/ScreenshotProofPacket_00558240.md). Current evidence supports a split between reusable image output, bundled codec code, and screenshot workflow code:

- [UID:0000KW][LodePNG](by-file/LodePNG.md) owns the PNG file-output APIs at `0x00443db0` and `0x00443e40`; source comparison now maps them to stock `lodepng_encode_file` and `lodepng_encode32_file`.
- `ImageWriters.cpp` owns [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md) at `0x004efbc0`, a project-owned JPEG output wrapper over IJG libjpeg. Any NexusTK-local PNG wrapper above `lodepng_encode32_file` remains unproven.
- `third_party/lodepng.cpp` owns the bundled LodePNG encode front end at `0x00443c80`, `LodePNGState`, and the anonymous encoder helper cluster; the corrected helper-island candidate spans `0x00443a60-0x00450c9f`.
- `ScreenshotCapture.cpp` owns raw/retained `SaveScreenshotJPG` at `0x00557840`, `SaveScreenshotBMP` at `0x00557aa0`, `SaveScreenshotPNG` at `0x00557e80`, and `SendScreenshotProofPacket` at `0x00558240`.
- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) owns the screenshot hotkey routing, not the file output.
- [UID:0000L6][MD5](by-file/MD5.md), [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md), and [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) are dependencies of screenshot proof submission, not owners of screenshot-specific proof layout.

Rationale: generated output attaches BMP/PNG capture to `FolderTreePane`, but IDA MCP caller checks show the modeled capture functions are triggered from event-dispatch hotkey branches and operate over the active render surface pointer. IDA disassembly also shows a raw `.jpg` capture body immediately before the BMP path; it has no modeled caller yet, but its behavior is the same screenshot workflow. IDA strings and decompilation identify the PNG backend as LodePNG and the JPG backend as IJG libjpeg. The file-save/proof workflow is more faithfully represented as a screenshot feature module, with small reusable writer wrappers kept separate from the bundled codecs.

### `third_party/lodepng.cpp`

See [UID:0000KW][LodePNG](by-file/LodePNG.md), [UID:0000XE][0x00443a60-0x00450c9f.LodePngHelperIslandInventory](by-memory/0x00443a60-0x00450c9f.LodePngHelperIslandInventory.md), [UID:0000XG][0x00444740-0x00444be0.LodePngRawErrorAndSettingsHelpers](by-memory/0x00444740-0x00444be0.LodePngRawErrorAndSettingsHelpers.md), and [UID:00007E][LodePNGState](by-class/LodePNGState.md). This third-party module should own:

- the LodePNG encode-to-memory front end at `0x00443c80`;
- `LodePNGState` construction/destructor support, including the vtable-backed destructor pair at `0x00448520` and `0x00448530`;
- the helper island at `0x00443a60-0x00450c9f`, including the raw `0x00444740-0x00444be0` LodePNG error/settings block, the main encode core at `0x004466b0`, IDA-modeled helpers through `0x00450b5e`, and the adjacent local helper at `0x00450b60-0x00450c9f`;
- LodePNG-specific error strings and settings such as `LodePNGEncoderSettings.filter_strategy`.

Rationale: the binary contains direct LodePNG identity strings and C++ RTTI-ish names for `LodePNGState` / `lodepng::State`. The screenshot-facing callee `0x00443e40` is stock `lodepng_encode32_file`, and the encoder implementation is bundled library code that should not be migrated as NexusTK render or DAT source. A 2026-05-25 IDA follow-up rejects the previous `0x00456031` upper bound: `0x00450ca0` begins [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md), and `0x00453df0+` is [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md).

Rebuild note: treat this as vendored third-party source. The project should use upstream `lodepng.cpp`/`lodepng.h` from commit `c6cf08b8910d91b0830666c07845116df1e9b6fc` / version `20160501`, then keep any proven NexusTK-local image output wrappers outside the library. The third-party folder is the rebuild owner for the public PNG file helpers and the full `0x00443a60-0x00450c9f` island.

### `third_party/zlib/`

See [UID:0000PC][Zlib](by-file/Zlib.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md), [UID:0000W3][0x004142c0-0x00419e56.ZlibCore](by-memory/0x004142c0-0x00419e56.ZlibCore.md), [UID:0000W2][0x004142c0-0x00414565.ZlibPublicCompressChecksum](by-memory/0x004142c0-0x00414565.ZlibPublicCompressChecksum.md), [UID:0000W4][0x00414820-0x004158aa.ZlibDeflateWorkers](by-memory/0x00414820-0x004158aa.ZlibDeflateWorkers.md), [UID:0000W5][0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler](by-memory/0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler.md), [UID:0004IK][0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers](by-memory/0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md), [UID:0000W6][0x00417ba0-0x00419e56.ZlibInflateInternals](by-memory/0x00417ba0-0x00419e56.ZlibInflateInternals.md), and [UID:0004IL][0x00632560-0x006325d8.ZlibDeflateConfigurationTable](by-memory/0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md). This third-party support folder should own:

- `Compress`/`Uncompress` style public wrappers at `0x004142c0` and `0x00414390`;
- `Crc32` at `0x00414430`, `Adler32` at `0x00415ee0`, and the CRC table at `dword_63211C`;
- deflate setup/reset and `deflate.c` internal helpers from `0x00414570-0x004158aa`, including [UID:0000W4][0x00414820-0x004158aa.ZlibDeflateWorkers](by-memory/0x00414820-0x004158aa.ZlibDeflateWorkers.md);
- `deflate.c` support data [UID:0004IL][0x00632560-0x006325d8.ZlibDeflateConfigurationTable](by-memory/0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md), the zlib `configuration_table[10]` referenced by `deflate` and source-covered by UID0000W4's sole `deflate.c` import;
- deflate tree/bit-output helpers from exact `trees.c` importer [UID:0004IK][0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers](by-memory/0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md);
- inflate setup/reset/blocks/codes/tree/fast helpers from `0x004158b0-0x00415e77` and `0x00417ba0-0x00419e56`.

Rationale: IDA strings identify zlib 1.1.4 directly with deflate/inflate copyright text, and source comparison against staged official `zlib-1.1.4` now maps the binary to the stock source files (`compress.c`, `uncompr.c`, `crc32.c`, `deflate.c`, `inflate.c`, `zutil.c`, `adler32.c`, `trees.c`, `infblock.c`, `infcodes.c`, `inftrees.c`, `infutil.c`, and `inffast.c`). `MetaTable`, palette, startup-logo, and image-resource code consume zlib; they should not own zlib helpers. Canonical MIDI UIDs 00041N/00041O are unrelated; fresh exact Zlib UIDs 0004IK/0004IL supersede the historical duplicate-header misroutes.

### `third_party/libjpeg/`

See [UID:0000KN][LibJPEG](by-file/LibJPEG.md), [UID:0000VP][0x00401000-0x00414283.LibJpeg6bCore](by-memory/0x00401000-0x00414283.LibJpeg6bCore.md), [UID:0000VR][0x00401b00-0x0040391f.LibJpegMarkerReader](by-memory/0x00401b00-0x0040391f.LibJpegMarkerReader.md), [UID:00045N][0x00406ee0-0x004075b7.LibJpegDecompressCoefficientController](by-memory/0x00406ee0-0x004075b7.LibJpegDecompressCoefficientController.md), [UID:00045P][0x00408a60-0x004090b0.LibJpegHuffmanDecoder](by-memory/0x00408a60-0x004090b0.LibJpegHuffmanDecoder.md), [UID:000462][0x0040fc20-0x004101e9.LibJpegForwardDctManager](by-memory/0x0040fc20-0x004101e9.LibJpegForwardDctManager.md), [UID:000466][0x00411960-0x004124b8.LibJpegCompressMasterController](by-memory/0x00411960-0x004124b8.LibJpegCompressMasterController.md), [UID:00046D][0x00414020-0x00414283.LibJpegFloatForwardDct](by-memory/0x00414020-0x00414283.LibJpegFloatForwardDct.md), and [UID:0001QE][client_libraries](by-meta/client_libraries.md). This third-party folder should own the statically linked IJG libjpeg 6b code currently bounded at `0x00401000-0x00414283`; [UID:0000VP][0x00401000-0x00414283.LibJpeg6bCore](by-memory/0x00401000-0x00414283.LibJpeg6bCore.md) is a non-emitting split/index and source-bearing stock children use formal validator inline import directives rooted at `third_party_embeds/libjpeg/` with blank multiline bodies rather than marker comments, copied upstream bodies, or hand-written product C++.

Rationale: IDA strings identify IJG libjpeg directly through `Copyright (C) 1998, Thomas G. Lane`, `6b  27-Mar-1998`, and canonical JPEG diagnostics such as `Wrong JPEG library version`, `Not a JPEG file`, `Invalid JPEG file structure`, and `JPEGMEM`. The complete source/binary audit shows `0x00401000` installing the 124-entry `jpeg_std_message_table` over `[0x00631660,0x00631850)`: indices `0..123`, no nulls or duplicates, exact source order, and zero mismatch against staged `jerror.h`. [UID:00028D][0x006707d4-0x00671a74.LibJpeg6bDataMessagesAndMemoryStrings](by-memory/0x006707d4-0x00671a74.LibJpeg6bDataMessagesAndMemoryStrings.md) contains those 124 diagnostics plus `jerror.c` `%s\n` and `jmemmgr.c` `JPEGMEM`/`%ld%c`; each of its 127 named anchors has exactly one expected xref. The former 121-entry range omitted the final three pointer slots, while 123 is the inclusive final message index rather than a count. The resolved source map now covers public API, marker, memory, controller, entropy, coefficient, sample, color, quantizer, DCT, and IDCT files through new children [UID:00045M][0x00401000-0x004011a1.LibJpegErrorManager](by-memory/0x00401000-0x004011a1.LibJpegErrorManager.md)-[UID:00046D][0x00414020-0x00414283.LibJpegFloatForwardDct](by-memory/0x00414020-0x00414283.LibJpegFloatForwardDct.md), plus existing [UID:0000VQ][0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd](by-memory/0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd.md)-[UID:0000W1][0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend](by-memory/0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend.md). Product wrappers now include [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md) and [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md), but IJG internals should not be assigned to render feature files. PNG wrappers inside [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md) similarly belong to `ImageLoaders.cpp` while LodePNG internals remain under [UID:0000KW][LodePNG](by-file/LodePNG.md).

Rebuild note: obtain or use the staged official `jpegsrc.v6b` source and compile it under `third_party/libjpeg/` instead of replacing stock helpers with generated C++ bodies. Required error/data and memory headers include `jinclude.h`, `jpeglib.h`, `jconfig.h`, `jmorecfg.h`, `jpegint.h`, `jerror.h`, `jversion.h`, and `jmemsys.h`; source-bearing pages import them from paths beginning `third_party_embeds/libjpeg/`. Current source anchors now cover `jerror.c`, `jdapimin.c`, `jdapistd.c`, `jdmarker.c`, `jcapimin.c`, `jcapistd.c`, `jcparam.c`, `jdatadst.c`, `jcomapi.c`, `jdinput.c`, `jmemmgr.c`, `jdmaster.c`, `jutils.c`, `jcmarker.c`, `jcinit.c`, `jmemnobs.c`, `jdcoefct.c`, `jdmainct.c`, `jdhuff.c`, `jdphuff.c`, `jddctmgr.c`, `jdpostct.c`, `jdsample.c`, `jdcolor.c`, `jdmerge.c`, `jquant1.c`, `jquant2.c`, `jcmainct.c`, `jccoefct.c`, `jchuff.c`, `jcphuff.c`, `jcdctmgr.c`, `jcprepct.c`, `jcsample.c`, `jccolor.c`, `jcmaster.c`, `jidctint.c`, `jidctfst.c`, `jidctflt.c`, `jidctred.c`, `jfdctint.c`, `jfdctfst.c`, and `jfdctflt.c`. Stock `jdatasrc.c` remains unproven for active product decode because NexusTK uses a local in-memory source setup helper at `0x004e7030`. Exclude `0x00414290-0x004142b5` because it is Miles `_AIL_shutdown@0` thunk/atexit glue, and treat `0x004142c0+` as [UID:0000W3][0x004142c0-0x00419e56.ZlibCore](by-memory/0x004142c0-0x00419e56.ZlibCore.md). The earlier `0x00469640-0x00470dc9` hypothesis is rejected because IDA decompiles that neighborhood as BrowserWindow/WebBrowser COM code.

### `third_party/jsoncpp/`

See [UID:0000KI][JsonCpp](by-file/JsonCpp.md), [UID:0000WY][0x00424630-0x00428b4b.JsonCppValueCore](by-memory/0x00424630-0x00428b4b.JsonCppValueCore.md), [UID:0000WZ][0x00428b4b-0x004298f0.JsonCppValuePathIteratorAndCrtNumericSupport](by-memory/0x00428b4b-0x004298f0.JsonCppValuePathIteratorAndCrtNumericSupport.md), [UID:0000X0][0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds](by-memory/0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds.md), [UID:0000X1][0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers](by-memory/0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers.md), [UID:0003WL][0x0042ace0-0x0042ad27.JsonCppLegacyReaderReadCStyleComment](by-memory/0x0042ace0-0x0042ad27.JsonCppLegacyReaderReadCStyleComment.md), [UID:0003WM][0x0042ad30-0x0042ad66.JsonCppLegacyReaderReadCppStyleComment](by-memory/0x0042ad30-0x0042ad66.JsonCppLegacyReaderReadCppStyleComment.md), [UID:0003WN][0x0042ad70-0x0042ada3.JsonCppLegacyReaderReadString](by-memory/0x0042ad70-0x0042ada3.JsonCppLegacyReaderReadString.md), [UID:0003WO][0x0042adb0-0x0042ae88.JsonCppLegacyReaderReadNumber](by-memory/0x0042adb0-0x0042ae88.JsonCppLegacyReaderReadNumber.md), [UID:0000X7][0x00431d50-0x00431f1c.JsonCppOurReaderParse](by-memory/0x00431d50-0x00431f1c.JsonCppOurReaderParse.md), [UID:0001ZR][0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers](by-memory/0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers.md), [UID:0000X2][0x0042ae90-0x0042e850.JsonCppReaderAndBuilderPreludeIsland](by-memory/0x0042ae90-0x0042e850.JsonCppReaderAndBuilderPreludeIsland.md), [UID:0000X8][0x00432e10-0x004345ee.JsonCppSecondParserIsland](by-memory/0x00432e10-0x004345ee.JsonCppSecondParserIsland.md), [UID:0000X9][0x004345f0-0x00434887.JsonCppNumberTokenParseHelper](by-memory/0x004345f0-0x00434887.JsonCppNumberTokenParseHelper.md), [UID:0001ZS][0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter](by-memory/0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter.md), [UID:0000X3][0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland](by-memory/0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland.md), [UID:0000X4][0x0042f3f0-0x00430040.JsonCppLegacyWriterCore](by-memory/0x0042f3f0-0x00430040.JsonCppLegacyWriterCore.md), [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md), [UID:0000X6][0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude](by-memory/0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude.md), [UID:0000XC][0x004417e0-0x00441d24.JsonCppValidReaderKeys](by-memory/0x004417e0-0x00441d24.JsonCppValidReaderKeys.md), [UID:0000XD][0x00441d30-0x00442084.JsonCppValidWriterKeys](by-memory/0x00441d30-0x00442084.JsonCppValidWriterKeys.md), and [UID:0001QE][client_libraries](by-meta/client_libraries.md). This third-party folder should own the statically linked JsonCpp parser/writer implementation from the current best upstream commit candidate.

Rationale: IDA strings/RTTI identify JsonCpp through `Json::Value` diagnostics, parser settings such as `collectComments`, `allowDroppedNullPlaceholders`, `rejectDupKeys`, and `allowSpecialFloats`, plus builder-era classes `CharReaderBuilder`, `StreamWriterBuilder`, `OurCharReader`, and `BuiltStyledStreamWriter`. Cash-shop/download modules own URLs, request flow, and catalog semantics; JsonCpp owns generic JSON parse/serialize support.

Rebuild note: staged official JsonCpp archives now include `0.10.6`, `1.7.0-1.7.7`, and commit `b299d3581f4dc670734f1fe1a34fce1282337802`. A 2026-05-25 source/IDA discriminator rejects `0.10.6` and release tag `1.7.5+`; value-core checks also reject tags `1.7.0-1.7.4` as exact matches. The current best source snapshot is official upstream commit `b299d3581f4dc670734f1fe1a34fce1282337802`, between `1.7.4` and `1.7.5`. The extracted candidate has no generated `dist/jsoncpp.cpp` amalgamation directory, so the first rebuild layout should preserve the upstream multi-file source tree under `include/json/` and `src/lib_json/`. The retained raw helpers at `0x0042ace0`, `0x0042ad30`, `0x0042ad70`, and `0x0042adb0` are exact legacy `Reader` methods in `src/lib_json/json_reader.cpp`; they are not product code and should not become separate hand-written generated `JsonCpp.cpp` snippets.

### `render/DirectX.cpp`, `render/GrafPort.cpp`, and `render/SoftwareBlend16.cpp`

See [UID:0000IW][DirectX](by-file/DirectX.md), [UID:0000JR][GrafPort](by-file/GrafPort.md), and [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md). Current evidence supports a split between device lifetime, render target state, and free pixel helpers:

- `DirectX` owns DirectDraw initialization, [UID:0000QS][g_pDirectX](by-global/g_pDirectX.md), the stored DirectDraw interface, primary vtable `0x00618e64`, and the `0x004a1cc0` singleton-clear helper used by constructor unwind cleanup.
- `GrafPort` owns pane/render backing storage, dirty/exposed regions, RGB565 DirectDraw surface creation, software-buffer fallback, shared draw-state accessors around `0x004b95e0-0x004b9767`, the shared [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md) and [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md) helpers, and likely the shared text-run/glyph drawing helpers around `0x004ba9a0-0x004bad66` and `0x004bb5e0-0x004bb7e0`.
- `SoftwareBlend16` owns RGB565/RGB555 pixel, pair, span, and block blend helpers such as `AlphaBlendSpan16`, `BlendRgb565Pixel`, `BlendRgb555_4C0710`, and the [UID:0000YD][0x0045fa00-0x004604f4.Rgb555565BlitHelpers](by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md) RGB555/RGB565 blit helper island.
- The larger callback implementations selected by `SurfaceRenderCallbackTable` are now tracked separately as [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md) and [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md). Their shared [UID:00016H][0x004bb2e0-0x004bb5a5.LineClipHelpers](by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md) are called only by the software line callbacks. Current active simroot emits many of these under `RankingEventListPane`, but they are render-dispatch code rather than ranking UI source.

Rationale: `DirectX` is a startup singleton wrapper, `GrafPort` is per-port surface/region/text infrastructure, and the blend helpers are state-free drawing primitives shared by render neighborhoods. Keeping the three roles separate matches a plausible VC6-era render folder better than merging everything into one generated class file. The text helpers currently emitted under FittingRoom, Collection, and Ranking owners read GrafPort draw state and call `FontImageLib`, so they should not drive feature-file placement.

### `render/Surface.h` and `render/Surface.cpp`

See [UID:0000OC][Surface](by-file/Surface.md). This provisional module groups generic surface helpers that currently have caller-biased Wave3 owners:

- paint lifecycle and surface metadata helpers around `0x004b9820-0x004ba24a`, including the now-documented `0x004b99f0` shared forwarding helper;
- shared blit/draw-effect helpers around `0x004ba250-0x004ba81d`, including [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md), [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md), [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md), and [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md);
- presentation/minimap/display blit helpers around `0x00557140-0x00559aef`;
- the `0x0069b3e0-0x0069b410` render callback table, with source-visible callback typedefs and `extern` declarations in `Surface.h` and one definition per slot in `Surface.cpp`;
- source-ready slot 6: `Surface.h` declares `SurfaceBitmaskBlitProc` as `void (__thiscall *)(GrafPort *, const unsigned char *, const RectBounds *, unsigned char)` and `extern SurfaceBitmaskBlitProc g_pfnBlitBitmask`; `Surface.cpp` defines the slot once and contains file-local [UID:0002TE][0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback](by-memory/0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback.md) and [UID:0002TI][0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback](by-memory/0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback.md) providers selected by the Surface initializer;
- the two slot-6 providers share exact destination clipping and MSB-first packed 1bpp traversal plus copy/color-key/blend modes, while retaining separate RGB555 `BlendRgb555Half` and RGB565 `BlendRgb565Pixel(..., 16)` behavior; their local jump tables/alignment regenerate from structured switches and are not handwritten data;
- generated aliases such as `g_pfnLockSurface` / `dword_69B3FC` remain review evidence for nearby surface globals, but raw IDA labels are not final source declarations;
- display-dimension dependencies such as [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md), [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md), and map/render layout dependencies such as [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md). Current generated `g_maxSurfacePitch` metadata is a bad alias over `g_screenWidth`, not a real Surface-owned global.
- review links to specialized alpha-surface modules.

Rationale: current owners such as `FolderTreePane`, `RankingUserListPane`, `FittingRoomDownloadControlPane`, and `MapPane` describe observed call paths, but many helpers are generic DirectDraw/surface utilities. A 2026-05-25 IDA pass also shows `0x00559410` invoking [UID:0000MC][Pane](by-file/Pane.md) dirty/motion helpers, reinforcing that nearby presentation traversal is shared UI/render code rather than map gameplay source. `Surface.h` centralizes shared callback ABIs used across consumers, while `Surface.cpp` keeps the storage, initializer, and pixel-format-specific implementations together without feature ownership pollution.

### `ui/core/Pane.cpp`, `ui/core/Layer.cpp`, `ui/core/RectBounds.cpp`, `ui/core/Region.cpp`, `ui/core/DialogPane.cpp`, `ui/core/ControlPane.cpp`, `ui/core/ScreenPane.cpp`, cursor-helper placement, and screen overlay helpers

See [UID:0001QV][client_ui_core](by-meta/client_ui_core.md), [UID:0000MC][Pane](by-file/Pane.md), [UID:0000KL][Layer](by-file/Layer.md), [UID:0000N2][RectBounds](by-file/RectBounds.md), [UID:0000N3][Region](by-file/Region.md), [UID:0000IT][DialogPane](by-file/DialogPane.md), [UID:0000IG][ControlPane](by-file/ControlPane.md), [UID:0000ME][PanelPane](by-file/PanelPane.md), [UID:0000NB][ScreenPane](by-file/ScreenPane.md), [UID:0000IL][CursorManager](by-file/CursorManager.md), [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md), and [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md). Current evidence supports:

- `Pane` owns the base UI object on top of `GrafPort`, event/timer handlers, dirty/clip regions, and layer attach/remove APIs.
- The `0x00544690-0x00544b7d` dirty/motion helper family belongs with `Pane`: IDA shows deletion marking, active/pending motion-region copy/subtract, motion comparison, and paint-state helpers used by layer recursion and shared presentation traversal. Current `class_MapPane.cpp` ownership for this range is generated pollution.
- [UID:0000HR][BlackHole](by-file/BlackHole.md) is the RTTI-backed singleton deferred deletion queue. Current generated [UID:0000MD][PaneChildRegistry](by-file/PaneChildRegistry.md) data is a stale alias for the pane-specific `BlackHole` queue helper at `0x00469180`.
- `Layer` owns the pane tree, z-order/clip bounds, dirty-region propagation, motion updates, and recursive render traversal.
- `RectBounds` is finalized as the separate `ui/core/RectBounds.cpp/.h` compilation unit. It owns the exact four-int geometry value object, eight-byte `Point`, fourteen member methods, twelve public/free geometry helpers including nested `RectArea`, and four file-local anchor helpers. The source route stays separate from `Region`; compiler-pooled literals, anchor switch tables, and alignment spans regenerate without authored data bodies. [UID:00016H][0x004bb2e0-0x004bb5a5.LineClipHelpers](by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md) is finalized under `render/Surface.cpp` because its direct callers are exclusively the software line callbacks; it is a RectBounds consumer, not part of this compilation unit.
- Historical placement note: before the 2026-08-18 UID0000N2 whole-file closure, `util/RectBounds.cpp`/`util/Geometry.cpp` and a shared RectBounds/render-geometry review bucket for LineClip remained open alternatives. Complete caller, owner, emitter, and generated-source reconciliation rejected those current placements while retaining them as dated research history.
- `Region` owns the safe `0x00554680-0x00554b38` region/rectangle helper island. Keep this UI-core dirty-rectangle code separate from timer-driven [UID:0000LL][Motion](by-file/Motion.md) animation and `NewHumanImageLib` `Motion.tbl` helpers.
- `DialogPane` owns common modal/modeless dialog behavior, control focus/hover/selection state, config-backed dialog positioning, and lifecycle hooks.
- [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md) is now documented as a small adjacent `ui/core/ModelessDialogPane.cpp` candidate for the non-modal dialog shell and mouse-event router.
- `ControlPane` owns generic control-pane construction and hit-test/default control metadata.
- `PanelPane` owns the reusable `Pane`-derived base for panel-style feature panes. IDA caller checks show direct constructor calls from inventory, `NewOptionPane`, self-look, group, collection, spell-inventory, `NewSystemMessagePane`, and user-look/profile panes; keep it in `ui/core` rather than folding it into any one feature source.
- `ScreenPane` owns the startup full-screen pane singleton, fade/frame callbacks, and DirectDraw surface/display-mode cleanup.
- The `0x00556ce0-0x00556d41` root layer-list helpers belong with `ScreenPane`: IDA shows operations through the screen object's layer-list field at offset `0x10c`, with callers from application startup/shutdown and map/world-map layer changes.
- `CursorManager` is a historical non-emitting typed view, not a standalone manager or source file. Current [UID:0000IL][CursorManager](by-file/CursorManager.md), [UID:00003E][CursorManager](by-class/CursorManager.md), [UID:00039X][0x00558f70-0x005590da.ScreenPaneCursorResourceLoader](by-memory/0x00558f70-0x005590da.ScreenPaneCursorResourceLoader.md), and [UID:0003CJ][0x0062317c-0x00623480.ScreenPaneResourceStringData](by-memory/0x0062317c-0x00623480.ScreenPaneResourceStringData.md) close the source route: `0x0067a7cc` is the ScreenPane singleton storage, the ten cursor paths are inline arguments in one ScreenPane-owned startup loader, and no separate allocation, constructor, vtable, storage, or lifetime exists. Do not create `CursorManager.cpp`; keep cursor loading and table state in `ScreenPane.cpp`.

Historical 2026-05-26 state: active `simroot_v2/class_CursorManager.cpp` emitted a standalone generated view with repeated synthetic `CursorManagerLayout` declarations, and the cursor-table setup path had not yet been identified. That open point is superseded: UID00039X models the startup loader and UID0003CJ maps its ten exact `.ani`-first/`.cur`-fallback literals at `0x00623304-0x0062345c`, with one loader xref per path. The earlier provisional adjacent-file option is rejected.

- UID0003CJ itself creates no source file. Its 772-byte `.rdata` range is a non-emitting compiler pool whose screenshot/proof values regenerate in `render/ScreenshotCapture.cpp`, cursor values in `ui/core/ScreenPane.cpp`, and `0.03125`/`RECT {0,0,2000,2000}` values in `render/Surface.cpp`. Do not add `ScreenPaneResources.cpp`, `ScreenLiteralPool.cpp`, global literal arrays, or raw data output merely to mirror linker adjacency.
- [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md) owns the generic modal dimmer overlay: `ScreenDimmer`, [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md), [UID:0000PJ][CreateScreenDimmer_4A12B0](by-global/CreateScreenDimmer_4A12B0.md), and the dimmer singleton-clear helper. [UID:00036Q][ScreenFadeOut](by-file/ScreenFadeOut.md) owns the peer fade-transition overlay class and its generated vtable/adjustor family. Keep [UID:0000L4][MapRefreshDimmer](by-file/MapRefreshDimmer.md) under `map/` as the timer-backed map-refresh wrapper.
- Historical TextButton placement left `DrawTextInRect` open as broad shared UI text-rendering support that might move. UID0000OK whole-file closure supersedes that uncertainty: `TextButtonControlPane.cpp/.h` remain under `ui/controls/`, while `DrawTextInRect` is an established [UID:0000JR][GrafPort](by-file/GrafPort.md) dependency and does not move with the class.

Rationale: constructor fan-in is high for `Pane` (95 direct callers), `ControlPane` (52 direct callers), and `DialogPane` (84 direct callers), while `Layer` is called directly by pane attach/remove methods. `RectBounds` and its free helper island have even broader cross-subsystem caller fanout, including IDA output showing `InitRectBounds` truncated after 10 entries with 1560 more callers. These are base UI/render infrastructure files, not feature-dialog files.

### `ui/panels/GeneralPurposePanel.cpp`

See [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md). This is now a strong in-game panel shell module candidate:

- `GeneralPurposePanel` owns the seven-child side-panel composition for self look, user look/profile, inventory, spell inventory, group, collection, and options.
- `GeneralPurposePanel2` owns a smaller alternate one-child panel shell.
- Shared child lookup, active-child refresh, and tab/page switching helpers at `0x004b85f0-0x004b8822` are documented as `GeneralPurposePanel` helpers despite current `SpellOneArgInputPane` generated ownership. See [UID:00015W][0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md) and [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md).
- The tab-switch path calls [UID:0000YI][0x004615b0-0x00461658.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md), but those helpers remain [UID:0000JL][FrameChrome](by-file/FrameChrome.md) dependencies because they release/rebuild the `0x0067a840` frame slot. The dynamic helper consumes `g_pGeneralPurposePanel->m_activeChildIndex + 5`; that field input is not ownership evidence for moving the helpers out of FrameChrome.
- Keep the child feature panes in their own source files; this module owns composition and page switching, not each child pane implementation.

Rationale: IDA confirms the compact panel shell range at `0x004b83d0-0x004b8bd3`, with constructor xrefs from main UI initialization paths and decompiled helper behavior matching child-array lookup and active-pane switching. Current Wave3 ownership labels for several helper methods are polluted by spell-input names, so migration should use the IDA-confirmed panel range and the new file/class docs as anchors.

### `ui/panels/SelfLookPane.cpp`, `ui/panels/SpelledPane.cpp`, and `ui/panels/LegendPane.cpp`

See [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md), [UID:0000NZ][SpelledPane](by-file/SpelledPane.md), and [UID:0000KM][LegendPane](by-file/LegendPane.md). This is now a stronger self-look/status panel family:

- `SelfLookPane` owns the main player self-look panel: character-data parsing, equipment slot rendering, body/equipment/stat toggle packets, world-map refresh bridging, help, input, and slot hit testing.
- [UID:0002CG][g_selfLookLastHoverEquipmentSlotId](by-global/g_selfLookLastHoverEquipmentSlotId.md) is source-owned/static `SelfLookPane.cpp` state for the equipment-slot hover timer branch.
- `SelfLookPane2` is a compact sibling with default/spelled/legend view switching, button geometry, button hit testing, stat text drawing, and input handling.
- `SpelledPane` is a reusable child text pane constructed by both self-look classes and by a system-message/new-system-message path, so it may deserve a small standalone source file instead of being duplicated into `SelfLookPane.cpp`.
- `LineIterator` is currently best treated as a private helper used by `SpelledPane::ParseAndLoadEntries`; its 16-byte layout and one-slot vtable are documented separately, but no broader callers justify a standalone `LineIterator.cpp` yet.
- `LegendPane` is constructed by both self-look classes and `UserLookPane`; keep it as a shared look/status child source candidate while the final split is reviewed.
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md) records the IDA-confirmed vtable bases and the exact [UID:0001HN][0x005732b5-0x00573302.LookPaneAdjustorThunks](by-memory/0x005732b5-0x00573302.LookPaneAdjustorThunks.md) that should remain compiler-generated layout glue.

Rationale: IDA confirms `SelfLookPane` core starts in `0x00565610-0x0056a373`, `SelfLookPane2` core starts in `0x0056fe80-0x005729c3`, `SpelledPane` in `0x0056bb20-0x0056c3f1`, and `LegendPane` at `0x0056c400`. Both self-look constructors allocate `SpelledPane` and `LegendPane`, while `SpelledPane` also has an xref from `0x005886bd` and `LegendPane` has an xref from `UserLookPane::UserLookPane`. IDA xrefs to `word_66FE40` are limited to the `SelfLookPane` hover-slot branch, so the global cache should migrate with `SelfLookPane.cpp`. Current Wave3 source has boundary mismatches around several self-look helpers, projected `SelfLookPane2` toggle methods, and omitted vtable inventories, so migration should use the IDA-confirmed ranges and the new docs as anchors.

### `ui/panels/UserLookPane.cpp`

See [UID:0000P0][UserLookPane](by-file/UserLookPane.md). This is now a strong remote look/profile panel module candidate:

- `UserLookPane` owns remote-character look/profile packet parsing, portrait payload storage, child text-pane population, look rendering, button hit-testing, and profile/biography/legend page switching.
- `MoreInfoPane` and `ProfilePane` are tiny read-only child panes allocated directly by the `UserLookPane` constructor and should migrate with the user-look source unless later evidence proves wider reuse.
- `LegendPane` is constructed by `UserLookPane` and self-look paths, so keep it cross-referenced here but defer final ownership until a self-look pass decides whether it belongs in `SelfLookPane.cpp`, standalone `LegendPane.cpp`, or a broader look-pane source.
- Keep [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md) separate; it is profile editing/storage UI, while `ProfilePane` here is a child display pane inside the remote look panel.
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md) records the `UserLookPane`, `MoreInfoPane`, and `ProfilePane` vtable bases missing from current generated metadata.

Rationale: IDA confirms the `UserLookPane` island at `0x0059f260-0x005a2523`, including the constructor xref from `GeneralPurposePanel` at `0x004b8477`, view-switch methods at `0x005a1cd0-0x005a2188`, `MoreInfoPane` stubs at `0x005a2340`/`0x005a2350`, `ProfilePane` stubs at `0x005a23c0`/`0x005a23d0`, and the scalar deleting destructor at `0x005a23f0`. IDA also confirms `LegendPane::LegendPane` at `0x0056c400`, with xrefs from both user-look and self-look paths, so it should not be absorbed into user-look solely because `UserLookPane` constructs one child instance. Current generated metadata omits all three user-look child table groups, so source reconstruction should use the IDA-backed vtable page until Wave3 data catches up.

### `ui/panels/UserStatusPane.cpp`

See [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md). This is now a strong local-player status HUD module candidate:

- `UserStatusPane` owns the newer right-side status summary pane: name/title text, nation/totem/class icons, selected status icon, bars, numeric values, hover help, and bitflagged status payload updates.
- [UID:0000I4][CharacterSummaryRecord](by-file/CharacterSummaryRecord.md) is a generated field-accessor artifact over the `UserStatusPane` tail, not a separate original source file. Fold those accessors into `UserStatusPane.cpp` or a private `UserStatusPaneSummaryFields` layout helper.
- `UserStatusPane2` owns the newer compact meter pane with `BAR.EPF`, `COMMA.EPF`, and 9x11 glyph text.
- `OldUserStatusPane` owns the legacy `USERSTAT.EPD` status panel, legacy hover zones, old status value layout, and the legacy status payload update path.
- `TotemFrame` is a status/totem companion. It may remain as adjacent `ui/panels/TotemFrame.cpp`, but it should cross-reference `UserStatusPane.cpp` because both `0x005ba4a0` and `0x005bf7c0` create or invalidate it and `TotemFrame::OnPaint` reads `OldUserStatusPane::GetSpiritId`.
- Keep `MenuVarietyPanes.cpp` separate even though it is address-adjacent between `UserStatusPane2` and `OldUserStatusPane`; it owns the game menu button/selector, not status rendering.

Rationale: `InitializeMainUiGraph` constructs `UserStatusPane` and `UserStatusPane2` in the newer layout at `0x004f837a` and `0x004f83ea`, and constructs `OldUserStatusPane` in the older layout at `0x004f8951`. IDA confirms clean main ranges at `0x005b83b0-0x005baafe`, `0x005bab00-0x005bc60c`, and `0x005bda40-0x005bfbc1`, plus a shared cleanup/thunk tail at `0x005bfbd0-0x005c0034`. Current generated output omits several update helpers and emits bad thunk/body artifacts, so migration should use the new class/file/memory docs as the boundary anchor.

The first helper in the shared tail, `0x005bfbd0`, is now resolved as `g_pMenuVarietySelectPane` cleanup for [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md), not status-pane code.

### `ui/panels/SoundStatusPane.cpp/.h`

See [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md). This is now a strong main-HUD sound/music status module candidate:

- `SoundStatusPane` owns the compact always-present sound/music status caption and hotkey surface. Its header declares direct Pane plus `Singleton<SoundStatusPane>` inheritance, four geometry integers, both overrides, and exact size `0x108`.
- It is constructed by `InitializeMainUiGraph` in both newer and older layouts at `0x004f8460` and `0x004f89c7`; each call is immediately preceded by `operator new(0x108)`.
- The pane consumes standalone `SoundManager.h` and `MidiPlayer.h` plus Config/Event/Pane/Surface/Application contracts. Lowercase Control+`m` coordinates effects state and Config; uppercase Control+`M` makes paired MidiPlayer and SoundManager music calls. It remains under `ui/panels/` because it owns UI event handling, repaint, and caption formatting rather than audio state.
- Keep [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md) separate; it owns the full settings dialog while `SoundStatusPane` owns the HUD shortcut/caption.

Rationale: IDA confirms the compact SoundStatusPane island at `0x0057bf70-0x0057c2cf`: four ordinary source methods plus constructor-unwind cleanup, two adjustor thunks, and scalar deleting destructor as compiler coverage. UID0000SB emits the sole pointer definition and two Singleton specializations; UID0000DJ/UID0001IG emit the complete class and four ordinary methods. The former empty/partial generated state is superseded; callback-time generated hashes and command authority are recorded in the UID0000NX report.

### `ui/panels/HourPane.cpp`

See [UID:0000JX][HourPane](by-file/HourPane.md). This is now a strong main-HUD hour/clock module candidate:

- `HourPane` owns the compact hour indicator, server/message hour update handler, localized hover tooltip, and `TIME.EPF`/`TIME.EPD` drawing path.
- It is constructed by `InitializeMainUiGraph` in both the newer and older layouts at `0x004f81a0` and `0x004f877c`.
- The pane consumes `g_pLanguageMan`, `g_pSecurityCallback`, `byte_66DA97`, `word_66DB04`, and time-art resources, but should remain under `ui/panels/` because it owns UI event handling, invalidation, and HUD resource painting.
- Keep [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md) and [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md) separate; all three are persistent HUD/status panes, but each owns a different subsystem surface.

Rationale: IDA confirms the compact HourPane island at `0x004cee60-0x004cf1ef`, with constructor, cleanup helper, hour update handler, mouse tooltip handler, paint, destructor adjustor thunks, and scalar deleting destructor. The next function at `0x004cf1f0` is `IconsPane`, confirming the end boundary. Current generated output omits `0x004ceeb0` and `0x004ceee0`, mishandles `0x004cf173`/`0x004cf17e`, and gives singleton `0x0069b418` the wrong generated name `g_pItemShopPane`; use the new class/file/memory/global/resource docs as the boundary anchor.

### `ui/panels/IconsPane.cpp` and `ui/panels/TabPane.cpp`

See [UID:0000JZ][IconsPane](by-file/IconsPane.md) and [UID:0000OF][TabPane](by-file/TabPane.md). These are now strong old-layout HUD control module candidates:

- `IconsPane` owns the old-layout icon strip: full/reduced visibility mode, `ICONS.EPD` painting, localized tooltips, mouse capture/highlight state, and icon click dispatch.
- `TabPane` owns a six-region tab/action input surface that dispatches a related subset of UI action helpers.
- The two classes should initially be kept as adjacent `ui/panels/` modules, with an open question over whether the original project combined them into one old-HUD controls source file.
- Keep them separate from [UID:0000M7][OptionPane](by-file/OptionPane.md): option UI reads and toggles `IconsPane` state, but it does not own the icon strip implementation.

Rationale: IDA confirms `IconsPane` core at `0x004cf1f0-0x004cf8d5`, `TabPane` core at `0x004cf980-0x004cfd4d`, and interleaved destructor glue at `0x004cfd6c-0x004cfe5f`. `InitializeMainUiGraph` constructs `TabPane` at `0x004f812d` and `IconsPane` at `0x004f8706`; option UI calls `IconsPane::IsShowingAllIcons`, `ShowAllIcons`, and `ShowReducedIcons` at `0x0053da83`, `0x0053ded2`, and `0x0053dee0`. Current generated output omits multiple helpers and mishandles destructor thunks, so migration should use the new class/file/memory/global/resource docs as the boundary anchor.

### `ui/panels/UserPane.cpp`

See [UID:0000P1][UserPane](by-file/UserPane.md). This is now a stronger local user/player pane module candidate:

- `UserPane` owns local user pane construction, the active user pane singleton, very large per-user state arrays, bounds/key/server-message/animation/clip virtuals, slot label formatting, and floating name-label visibility.
- `BowGaugeObjectPane` is constructed from `UserPane::UserPane` and may remain either a private `UserPane.cpp` child or a small adjacent `ui/panels/BowGaugeObjectPane.cpp` file.
- Keep `LivingObjectPane` movement/combat/object helpers out of this file even when they are physically adjacent in `0x005a2e00-0x005a8cf0`.
- Keep chat history and say-input mode helpers in [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) or [UID:0000I5][Chatting](by-file/Chatting.md), not in `UserPane.cpp`, unless a later original-source review proves those helpers were intentionally colocated.

Rationale: IDA confirms `UserPane::UserPane` at `0x005a2530-0x005a2c5b`, including the `BowGaugeObjectPane` constructor call at `0x005a2956`, the non-deleting destructor helper at `0x005a2c60`, slot label helpers at `0x005a40d0`/`0x005a4310`, main virtuals at `0x005a5b80`, `0x005a5bd0`, `0x005a76c0`, `0x005a83b0`, `0x005a8840`, `0x005a8e70`, `0x005a8f60`, and the scalar deleting destructor at `0x005b8230`. The same IDA pass shows many neighboring functions are owned by `LivingObjectPane` or social input files, so migration should use the new class/file docs as an exclusion-aware anchor.

### `ui/panels/BowGaugeObjectPane.cpp`

See [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md). This is a medium-confidence local-player HUD companion module:

- `BowGaugeObjectPane` owns bow gauge pane construction, `g_pBowGaugeObjectPane`, `BGAUGE.EPF` frame drawing, show/timer behavior, and teardown.
- Final source placement may be standalone under `ui/panels/` or private inside `UserPane.cpp`, depending on whether later xrefs show reuse outside local-player UI.
- Generated fitting-room helper names in `OnPaint` are likely polluted shared-helper labels and should not move the class to `cashshop/`.
- The `0x004ba540` pixel compositor used by `OnPaint` is not BowGauge-owned source: IDA callers also include TextEditPane draw/invalidation paths, so keep it in [UID:0000JR][GrafPort](by-file/GrafPort.md) / [UID:0000OC][Surface](by-file/Surface.md) review.

Rationale: IDA confirms the `0x00538bc0-0x00538d4b` class anchors and constructor xref from `UserPane::UserPane`, plus the destructor at `0x0053cfe0`. Unlike attached map-object overlays, this class constructs through `Pane`, not `ObjectPane` or `AttachedObjectPane`. The 2026-05-25 caller pass confirms the `0x004ba540` compositor is shared with TextEditPane, so it should not migrate with `BowGaugeObjectPane.cpp`.

### `ui/panels/ParcelPane.cpp`

See [UID:0000MF][ParcelPane](by-file/ParcelPane.md). This is a medium-confidence parcel notification/HUD module:

- `ParcelPane` owns the small two-slot parcel alert pane, slot-state update path, timer animation, mouse/key handling, and `ALERTBTN` rendering.
- `FlyingParcelPane` and `ParcelIconPane` should likely live in the same source unit or as private helper classes because they are adjacent, share parcel globals/resources, and manipulate `g_pParcelPane` / `g_pParcelIconPane`.
- The `0x005461c0` packet/update callback is a `ParcelIconPane` secondary-vtable method that forwards derived slot counts into the child `ParcelPane`, so it belongs in this module but should not be modeled as a direct `ParcelPane` method.
- The `FlyingParcelPane` raw cleanup/start bodies at `0x00546b80-0x00546d64` belong here. Active simroot omits them, while IDA raw disassembly shows real reconstructable parcel animation/lifecycle code now split into exact child ranges `0x00546b80-0x00546bb5` and `0x00546bc0-0x00546d64`.
- [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md) confirms all three classes share the `+0x00`, `+0xa0`, and `+0xa4` vtable-view pattern. Keep the destructor adjustor thunks as compiler-generated glue and do not read short tertiary tables into adjacent RTTI/string data.
- Keep [UID:0000JK][FpsPane](by-file/FpsPane.md) separate; stale ParcelPane metadata/global-data references to the `0x004b64a0` FPS logging range are data issues.
- Keep `PatchPane` separate; IDA confirms it starts at `0x005470b0`, after the parcel notification destructor cluster.

Rationale: IDA MCP confirms the parcel notification family from `0x00545e40-0x005470ac`, including the `ParcelIconPane` constructor that allocates a `ParcelPane` child, the `ParcelIconPane` packet/update callback at secondary vtable slot `0x00621c10`, the `ParcelPane` constructor/core virtuals, and `FlyingParcelPane` animation methods. IDA raw disassembly fills the current function-boundary gap at `0x00546b80-0x00546d64`; a 2026-06-01 pass confirms cleanup body `0x00546b80-0x00546bb5`, start/configure body `0x00546bc0-0x00546d64`, and surrounding `0xcc` alignment. The shared `ALERTBTN`/`LETTER` resources and parcel singleton xrefs support a HUD/panel source module.

### `ui/panels/CollectionPane.cpp` and `ui/dialogs/CollectionDialogPane.cpp`

See [UID:0000IC][CollectionPane](by-file/CollectionPane.md) and [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md). Current evidence supports a feature split between the main collection panel and its detail dialog:

- `CollectionPane` owns the five-row collection summary panel, metadata load path, scroll child ownership, click/scroll input, and the omitted open/request helper at `0x0056fc80`.
- `CollectionPane2` is a lightweight alternate collection inventory frame pane and should migrate with `CollectionPane.cpp`.
- `CollectionDialogPane` owns the 668x468 detail dialog, page buttons, category lookup, singleton lifecycle, and six-entry page switching.
- `CollectionEntryControlPane` and `CollectionBarControlPane` are private detail-dialog controls and should migrate with `CollectionDialogPane.cpp`, not as standalone feature files.
- `ScrollCollectionPane` is a dependency and should remain in a generic scrollbar/core UI source until a scroll-control pass proves it was collection-private.

Rationale: IDA MCP confirms the dialog/control island at `0x0048c640-0x0048e305` and the main collection pane island at `0x0056e940-0x0056fe75`. The omitted helper `0x0056fc80` bridges the two islands by constructing `CollectionDialogPane` or sending a detail request packet. The `CLT*` resource family and shared [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md) support feature grouping, while the generic scrollbar behavior supports keeping `ScrollCollectionPane` separate.

### `ui/core/FrameMgr.cpp` and `ui/core/FrameChrome.cpp`

See [UID:0000JM][FrameMgr](by-file/FrameMgr.md), [UID:0000JL][FrameChrome](by-file/FrameChrome.md), and [UID:0000OV][TotemFrame](by-file/TotemFrame.md). Current evidence supports separate frame meanings:

- `FrameMgr`/`FrameHandler` own the frame-callback scheduler through `g_frameRegistry`.
- `FrameChrome` owns visible frame-border panes built from `FRMPART.EPF`, `FRMPART.EPD`, `TABS.EPF`, and the shared `goog` notification tag.
- [UID:0000PN][FrameChromeSlots](by-global/FrameChromeSlots.md) records the two global pointer families: `AboveFrame` slots at `0x0067a834-0x0067a874` and `FramePartPane` slots at `0x0069b33c-0x0069b350`.
- [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md) records the IDA-confirmed `AboveFrame` and `FramePartPane` table bases, the compiler-generated adjustor thunks, and the short `AboveFrame` tertiary-table boundary before `FRMPART.EPF` string data.
- [UID:0000YI][0x004615b0-0x00461658.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md) are called from [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md) tab switches, but source ownership stays with frame chrome because they release/rebuild `AboveFrame` slot `0x0067a840`.
- `TotemFrame` is a totem/status feature frame using `TOTFRAME.EPD`, `NPAL7.PAL`, [UID:0000SK][g_pTotemFrame](by-global/g_pTotemFrame.md), and [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md) frame-index data; keep it separate from generic frame chrome unless later evidence proves a shared original file. The current source candidate is `ui/panels/TotemFrame.cpp` beside [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md).

Rationale: the scheduler is tick/animation infrastructure and is used by `ScreenPane`/`WorldMapPane` style frame handlers. The chrome classes are pane/resource objects with their own vtable families and global slot lifetimes. `TotemFrame` is created from status-update handlers at `0x005ba4a0` and `0x005bf7c0`, and `TotemFrame::OnPaint` calls `OldUserStatusPane::GetSpiritId` at `0x005bdc60`, so its stronger initial placement is beside user-status/totem panel code, not generic frame chrome. The same English word "frame" should not force these into one source file.

### `ui/core/ScrollBar.cpp` and `ui/controls/ScrollableControlPane.cpp`

See [UID:0000NF][ScrollBar](by-file/ScrollBar.md), [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md), and [UID:0000NE][ScrollableControlPane](by-file/ScrollableControlPane.md). Current evidence supports a split between pane-level scrollbar infrastructure and a generic control wrapper:

- `ScrollBar.cpp` owns `ScrollPane`, `ScrollWidget`, `ScrollablePane`, and scrollbar size tables. CScrollBarBackPane is excluded by the dated correction below.
- Historical 2026-06-01 IDA MCP sync: [UID:0000NF][ScrollBar](by-file/ScrollBar.md) received validator path `NexusTK/ui/core/`; CScrollBarBackPane child docs were attached after evidence confirmed constructor bytes `0x0053fea0-0x0053fed2`, then-described cleanup helper `0x0053fee0-0x0053feff`, draw method `0x0053ff00-0x0053ff8d`, destructor `0x00542680-0x005426d5`, vtable refs, and padding. This was a name-similarity placement hypothesis, not the current route.
- 2026-07-29 UID0001DV correction: [UID:00003D][CScrollBarBackPane](by-class/CScrollBarBackPane.md) CScrollBarBackPane is an OptionPane-local NewOptionPane volume-slider backplate support class. Its declaration and exact constructor, ordinary destructor, and OnPaint children route through [UID:0000M7][OptionPane](by-file/OptionPane.md) OptionPane; [UID:0000NF][ScrollBar](by-file/ScrollBar.md) ScrollBar retains only generic ScrollPane, ScrollWidget, and ScrollablePane infrastructure. The former ScrollBar placement was a name-similarity hypothesis superseded by two inline NewOptionPane constructions, +0x12cc/+0x12d0 fields, paired 120x5 layout, shared deletion lifetime, and code/RTTI adjacency.
- `ScrollPane` owns classic `SCRL001` rendering and newer EPF scrollbar rendering through `SLIDEBG`, `SCRBUTT`, and `BUTTON` resources.
- `ScrollCollectionPane` owns another EPF-backed scrollbar family at `0x00561db0-0x0056325b`; despite the name and direct use by `CollectionPane`, current evidence favors generic scrollbar ownership rather than collection-feature ownership.
- `ScrollablePane` owns optional horizontal/vertical scrollbar children and content viewport clipping.
- `ScrollableControlPane.cpp` owns the `ControlPane`-derived wrapper used by many dialogs to host a scrollable content object.
- `ScrollVolumePane.cpp` owns the vertical volume slider at `0x00564710-0x005654ec` and its constructor-installed vtables at `0x006240b4`, `0x00624100`, and `0x00624130`; it consumes pane/scroll geometry ideas but stays separate from generic `ScrollBar.cpp` and from [UID:0000M7][OptionPane](by-file/OptionPane.md).
- `TextEditPane` contains many scrollbar-specific handlers, but it remains a separate rich text editor candidate; its handlers consume `ScrollPane` geometry rather than proving text editing belongs in `ScrollBar.cpp`.

Rationale: `ScrollablePane` constructor fan-in is limited to pane classes that need scrollable content, while `ScrollableControlPane` has 44 direct constructor references across dialogs and menu panes and returns control type `0x12`. Keeping the wrapper in `ui/controls` avoids mixing generic scrollbar drawing with dialog control adaptation.

### `ui/controls/ListPane.cpp/.h` and `ui/controls/SimpleListPane.cpp/.h`

See [UID:0000KT][ListPane](by-file/ListPane.md) and [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md). This is now a strong reusable list-control module candidate:

- `ListPane` owns the selectable, scrollable list/grid base at `0x004f3a50-0x004f4a77`.
- `ListPane.h` owns the guarded complete `0x14c` class declaration, exact recovered tail fields/padding, constructor/destructor and selection declarations, and all exact child declarations; `ListPane.cpp` includes it and `../../util/List.h` before emitting ordered child bodies.
- `SimpleListPane.cpp/.h` is the finalized standalone sibling. It owns the bounds-driven constructor plus append, insert, remove, replace, and source destructor methods across `0x005739a0-0x00573c38`; `SimpleListPane.h` includes `ListPane.h` and declares all six methods.
- The adjustor thunks and scalar deleting destructor at `0x00573c38-0x00573d15`, layout marker, vtables, complete-object locators, and RTTI are compiler-generated from the class declaration and emit no raw wrapper/table source.
- Shared helpers currently emitted under `ArticleListPane`, `ChattingColorListPane`, `ServerItemMenuItemList`, and `SelectionState` should be migrated into `ListPane.cpp`.
- Feature modules should keep their derived row/data classes, such as board article rows, mail rows, clan lists, exchange item lists, item/spell menu rows, phone-book rows, and user-list rows.

Rationale: IDA MCP confirms broad helper caller fanout for `0x004f3bd0`, `0x004f3c50`, `0x004f3dc0`, `0x004f3e20`, `0x004f3e80`, and `0x004f3f00`, crossing many independent UI features. It also confirms a coherent SimpleListPane class island with six source-authored behaviors, later compiler wrappers, three vtable views, and exact class RTTI. That evidence supports two sibling control modules with an explicit header dependency, while `ScrollablePane` remains in `ScrollBar.cpp` as scrollbar/viewport infrastructure.

### `ui/controls/TextEditPane.cpp`, `ui/controls/TextEditControlPane.cpp`, and `ui/controls/TextFilter.cpp`

See [UID:0000ON][TextEditPane](by-file/TextEditPane.md), [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md), and [UID:0000OO][TextFilter](by-file/TextFilter.md). Current evidence supports a split between the editor implementation, its control wrapper, and a broader text-filter singleton:

- `TextEditPane.cpp` owns `TextEditPane`, fieldless `TextBoxPane`, `TextEditScrap`, `TextEditObject`, `EPFTextEditObject`, `TextRunMeasureCallback`, `DrawTextRunCallback`, and tightly coupled text-edit helpers. UID0000OJ is a non-emitting source-family alias rather than a standalone file.
- `TextEditPane` owns styled UTF-16 storage, line and format tables, caret/selection state, clipboard scrap handling, text-run iteration/drawing, keyboard/mouse input, wrapping, and editor scrollbar variants.
- Deterministic validator assembly routes the 141 TextEditPane/file-local body keys through 50 ordered child nodes. UID0001JM, UID0001JP, and UID0001JS are non-emitting covered-by indexes; their former crossing aggregates are replaced by the exact UID00056B-UID00056T split pages without changing this file/module ownership.
- `TextEditControlPane.cpp` owns the `ControlPane` adapter that returns control type `5`, allocates/configures a `TextEditPane`, forwards layer/show/hide/focus behavior, and paints the wrapper border.
- `TextFilter.cpp` owns the `TextFilter` singleton, [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md), the one-slot [UID:0001YY][TextFilterVtable](by-type/by-vtable/TextFilterVtable.md), and likely the neighboring [UID:0000TK][SanitizeWideTextForChat](by-global/SanitizeWideTextForChat.md) helper, but final folder placement remains medium-confidence because sanitizer callers span chat, mail, article, whisper, spell-string, and party-search submission paths.

Rationale: IDA MCP reports 85 direct callers to the full `TextEditControlPane` constructor at `0x00498920`, matching a reusable dialog control adapter. `TextEditPane` itself has 26 constructor callers and a large internal method family through `0x00594e11`; its support objects are tightly clustered afterward at `0x00594e60-0x00595758`. `TextFilter` is adjacent, but its startup singleton at `0x00595760`, singleton pointer `0x0067adc8`, one-slot vtable `0x0062e188`, omitted non-deleting destructor-like body at `0x005957a0`, and broad submit-path sanitizer use make it safer to document as a neighboring text module instead of forcing it into the editor source file.

### `ui/controls/StaticTextControlPane.cpp`, `ui/controls/FontStyle.cpp` / `FontStyle.h`, `ui/controls/ScrolledTextControlPane.cpp`, and `ui/controls/ScrolledPictureControlPane.cpp`

See [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md), [UID:0000JI][FontStyle](by-file/FontStyle.md), [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md), and [UID:0000NH][ScrolledPictureControlPane](by-file/ScrolledPictureControlPane.md). Current evidence supports neighboring static/scrolled control modules; [UID:0000OJ][TextBoxPane](by-file/TextBoxPane.md) is retained separately only as a non-emitting historical/evidence alias for the UID0000ON source family.

- `StaticTextControlPane.cpp` owns `StaticTextControlPane`, `StaticTextControlPane2`, and `StaticTextControlPane2::SimpleHelpTextPartPane`.
- `FontStyle.cpp` owns the three authored methods at `0x00499f10-0x00499fda`; required sibling `FontStyle.h` owns the complete reusable `FontStyleRule`/`FontStyle` declaration used by minimap labels, mail compose labels, static text controls, and `HelpPane`. The discontiguous `0x004536e0-0x00453732` body is compiler-emitted implicit vector destruction, not authored `ClearRules` or an empty destructor, and `0x0049ac60-0x0049ad74` is compiler vector growth represented by `m_rules.push_back(rule)`.
- `StaticTextControlPane` is the older broad dialog label/control wrapper; IDA MCP reports 104 direct constructor callers.
- `StaticTextControlPane2` is an extended help/static text pane with multiline measurement, alignment, screen clamping, opacity/fade style, and an embedded text part for outlined/shadowed lines. Its fixed type-id helper ends at `0x0049b915`; `StaticTextControlPane` has a neighboring type-id helper at [UID:000222][0x0049b920-0x0049b925.StaticTextControlPaneTypeId](by-memory/0x0049b920-0x0049b925.StaticTextControlPaneTypeId.md).
- `ScrolledTextControlPane.cpp` owns `ScrolledTextControlPane` and `ScrolledTextControlPaneForMadeBy`, which load DAT text, render it once through a temporary `TextEditPane`, and scroll the rendered image by timer.
- `ScrolledPictureControlPane.cpp` owns the EPF/palette picture-scroller control at `0x004ff7d0-0x004ffa9e`, with later thunk/destructor support at [UID:0001AD][0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks](by-memory/0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks.md) and [UID:0001AI][0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor](by-memory/0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor.md).

Rationale: the static text classes are tightly adjacent around `0x00498dd0-0x0049b925`, with text-effect helpers at `0x004bafa0-0x004bb0da`. `FontStyle` has one compact three-method authored cluster and cross-unit by-value consumers that require a shared complete header. Its discontiguous destructor/growth bodies are compiler products, so they do not weaken standalone `FontStyle.cpp`/`.h` placement or transfer ownership to minimap, mail, StaticText, or HelpPane. The scrolled text classes are parallel around `0x004ff040-0x00502cbd`, while the picture scroller starts immediately afterward at `0x004ff7d0` and shares the same timer/control shape but not the text-rendering pipeline. A 2026-05-25 IDA recheck still finds no direct constructor caller for `0x004ff7d0`; generated fitting-room/head-selection labels remain owner pollution until a factory/config construction path is found. UID0000OJ's complete merge audit supersedes the earlier tentative standalone TextBox placement.

## UID0000OJ TextEdit Source-Tree Incorporation - 2026-08-16

The accepted whole-file audit removes standalone `TextBoxPane.cpp/.h`. Fieldless TextBoxPane and its constructor are source-ordered inside `TextEditPane.cpp/.h`; the two formerly TextBox-local invalidation bodies are TextEditPane members. TextEditObject, TextEditScrap, and EPFTextEditObject remain in the same merged implementation/header. This incorporates C0000OJ-049 while preserving UID0000OJ as a documentation alias.

### `ui/controls/HelpPanes.cpp`

See [UID:0000JU][HelpPanes](by-file/HelpPanes.md). Current evidence supports a tooltip/help-overlay support source near the other controls:

- `HelpPanes.cpp` owns `HelpPane`, `HelpPane::SimpleHelpTextPartPane`, `SimpleHelpPane`, `SimpleHelpPane2`, `WillBeChangedItemPane`, `WillBeChangedSpellPane`, and `ItemHelpPane`.
- `HelpPane` and `SimpleHelpPane` are generic timed tooltip infrastructure with text measurement, placement, screen clamping, timer expiry, and singleton cleanup.
- `SimpleHelpPane2` also has a file-local factory/helper at [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md), raw factory helpers at [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md), and neighboring support helpers at [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md) that active `.cpp` output currently omits or does not cleanly model.
- `WillBeChangedItemPane` and `WillBeChangedSpellPane` are temporary drag/change-preview overlays. They are not generic text controls, but their memory locality and overlay behavior make them plausible neighbors.
- `ItemHelpPane` is the large item-tooltip renderer. It may eventually deserve `ItemHelpPane.cpp`, but the current source-order cluster and tooltip role make `HelpPanes.cpp` the conservative first file candidate.
- Keep `HelpPane::SimpleHelpTextPartPane` separate from `StaticTextControlPane2::SimpleHelpTextPartPane`; the names and text effects are similar, but IDA and generated-file locality show different parent classes and source neighborhoods.

Rationale: IDA MCP confirms contiguous tooltip/helper ranges at `0x004c65a0-0x004ce34b`, the `SimpleHelpPane2` factory/helper sequence at `0x004c7680-0x004c78db`, singleton storage at `0x0069ae00`, `0x0067a7d4`, `0x0069ae04`, and `0x0069b414`, with destructor thunks in `0x004ce34b-0x004ce724`. Constructor xrefs show broad UI callers for `SimpleHelpPane`, item/inventory callers for `ItemHelpPane`, and feature-specific callers for the will-be-changed preview panes.

### `ui/controls/ButtonControlPane.cpp`, `ui/controls/PrettyButtonControlPane.cpp`, and specialized button panes

See [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md), [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md), [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md), and [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md). Current evidence supports a generic button/choice-control module, a settled standalone CheckBox module, and smaller specialized button modules:

- `ButtonControlPane.cpp` owns the shared generic button/choice-control subset: `ButtonControlPane`, `ImageButtonControlPane`, `TextButtonExControlPane`, `RadioGroupControlPane`, `SliderControlPane`, `SelectBoxControlPane`, and `SelectionControlPane` under their current documented routes. It does not currently own `CheckBoxControlPane` source.
- `TextButtonControlPane.cpp` and `TextButtonControlPane.h` form a dedicated reusable controls module under [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md). Exact authored source is the four-method band `[0x00495040,0x00495450)` and a complete `0x110` `ButtonControlPane`-derived declaration routed by [UID:0000EJ][TextButtonControlPane](by-class/TextButtonControlPane.md). UID0002YD adjusted deleting entries, UID0002YE scalar deleting wrapper, the three-view vtable/RTTI island, and alignment are compiler-covered and create no separate source. `DrawTextInRect` remains a GrafPort call dependency; the old may-move language is preserved above only as superseded history.
- `CheckBoxControlPane.cpp` and `CheckBoxControlPane.h` own the complete `0x150` checkbox declaration and authored methods. Source order is UID000021 at `10` for the header/CPP preamble, UID00011S at `20` for constructor/accessors/EventHandler/paint/SetVisualState, and UID0004Y2 at `30` for `HitTestPart(int,int)` returning byte `20`.
- UID0002M9 RTTI/vtable bytes, UID0001X8 vtable support, UID0001TX layout support, UID00011Z adjusted deleting entries, and UID0004Y1 scalar deleting entry are non-emitting compiler/layout evidence. They must not create vtable arrays, raw wrapper functions, or Empty Emitter Markers in the source tree.
- `ImageButtonControlPane` is especially broad: IDA MCP reports 306 direct constructor xrefs to `0x00495bf0`.
- `PrettyButtonControlPane.cpp` groups `PrettyButtonControlPane` and `PrettyButtonControlPane2` around `0x0054b5e0-0x0054bcbd`; IDA MCP reports 30 direct xrefs to the first constructor and 2 to the alternate constructor.
- `ObjectImageControlPane.cpp` owns the reusable object/character image preview control at `0x00520540-0x00520816`; `ObjectImageButtonPane` should move with it or to an adjacent `ObjectImageButtonPane.cpp` because it immediately follows at `0x00520820`, calls the base constructor directly, and shares the destructor/thunk neighborhood.
- `SpecializedButtonPanes.cpp` is a provisional bucket for `DirectionButtonControlPane`, `GenderButtonControlPane`, and `CheckBoxTextControlPane`. `ObjectImageButtonPane` was previously listed there, but current evidence supports moving it to the object-image control source family. `DirectionButtonControlPane` and `GenderButtonControlPane` have IDA-confirmed virtual methods/destructors, but their Wave3 constructor starts are not IDA function starts; child setup is currently observed inline in `NewUserMiscDialogPane`. 2026-06-03 IDA MCP rechecked the raw constructor starts, vtable slots, and store xrefs, so the by-file page now uses `NexusTK/ui/controls/` as a provisional generated-root path while preserving the final split caveat. See [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md) and [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md) for the verified field/vtable evidence.
- `CheckBoxControlPane` remains a related generic choice-control family member, but its dedicated method cluster, complete class topology, cross-feature MiniMap/Mail consumers, exact three-view RTTI/vtables, and stable 10/20/30 emitter order resolve standalone source as the current highest-probability organization. The former direct fold into ButtonControlPane.cpp is preserved only as rejected historical grouping context.

Rationale: the button/choice controls share `ControlPane`-derived construction, vtable-adjustor/destructor neighborhoods, and EPF-backed state painting. That family relationship does not require one source file. For CheckBox, exact `[0x00499d40,0x00499f0e)` locality, its separate `0x150` declaration, standalone file root, and exact terminal virtual outweigh destructor-band adjacency. Generated helper names in this area remain polluted, so ownership follows xrefs, address locality, complete class topology, and behavior rather than isolated generated labels.

2026-07-26 B002 UID0002M9 source-tree reconciliation preserves the prior broad-family proposal as historical evidence but settles `CheckBoxControlPane.cpp/.h` as current placement. No unrelated control-file placement changed.

2026-08-13 B006 UID0000OK callback adds the required TextButton sibling header and closes the GrafPort dependency boundary at accepted report SHA256 `252A1CEB3A98F1ED96A6A65DF6B76D74330C4A085840A5CB388804D6F16B93BD`. Scores remain the by-project-structure schema default; no unrelated module placement changed.

### `ui/controls/ProgressBarControlPane.cpp`

See [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md). Current evidence supports a separate reusable progress-control module:

- `ProgressBarControlPane` owns constructor and draw behavior at `0x00494c80-0x00494eaf`.
- Projected private helpers at `0x00494a90`, `0x00494af0`, and `0x00494db0` adjust the same range/current fields, but IDA does not currently model them as functions.
- [UID:0000MH][PatchPane](by-file/PatchPane.md) is the only confirmed direct constructor caller and uses the control for the `Auto Patch` dialog.
- Keep this separate from [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md). The address neighborhood overlaps the button/radio-control area, but the behavior is a plain progress indicator rather than a button or choice control.

Rationale: the class is a small `ControlPane`-derived visual control with its own vtable target and range math. Patch code consumes it, but the widget is generic UI infrastructure and belongs under `ui/controls`.

### `ui/controls/NumericStringControlPane.cpp` and `ui/controls/RectangleControlPane.cpp`

See [UID:0000M2][NumericStringControlPane](by-file/NumericStringControlPane.md) and [UID:0000N1][RectangleControlPane](by-file/RectangleControlPane.md). Current evidence supports small reusable visual-control modules:

- `NumericStringControlPane` owns numeric-glyph text rendering at `0x00499910-0x00499be6`, plus destructor/thunk support in the local control destructor island.
- `RectangleControlPane` owns constructor, ordinary destructor, and `OnPaint` at `[0x00499c60,0x00499d37)`, plus terminal `HitTestPart(int,int)` at `[0x0049b8f0,0x0049b8f5)` returning part code `21`. Deleting wrappers, adjustors, vtables, and RTTI are compiler-generated support rather than handwritten definitions.
- [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md) is the currently confirmed consumer: coordinate value controls use `NumericStringControlPane`, and symbol rendering uses `RectangleControlPane` for background rectangles.
- Keep both classes under `ui/controls`. The former possibility that these controls were folded into a broad `BasicControlPanes.cpp` is retained as historical speculation but rejected for RectangleControlPane: its dedicated method island, RTTI/vtables, complete class surface, and standalone project topology provide stronger source-placement evidence.

Rationale: both classes are generic `ControlPane` derivatives. Their direct callers are minimap-specific today, but the behavior and recovered source-file names are reusable control infrastructure rather than map-domain logic.

### `ui/controls/ObjectImageControlPane.cpp`

See [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md). Current evidence supports a reusable object-image control module:

- `ObjectImageControlPane` owns constructor and paint behavior at `0x00520540-0x00520816`, plus non-contiguous destructor/thunk methods at `0x00520afd`, `0x00520b08`, and `0x00520ca0`.
- `ObjectImageButtonPane` should be kept in the same original file or an adjacent sibling file because it derives from the plain control, begins immediately afterward at `0x00520820`, calls the base constructor at `0x00520830`, and has only head-selection-specific direct construction outside the object-image module.
- Constructor callers span text menus, argumented menus, client/server item and spell menus, message/menu-question dialogs, head selection, and object preview dialogs, so the module belongs under reusable UI controls rather than any one dialog feature.

Rationale: the class is a broad dialog control whose core job is rendering a centered object/character descriptor. The object-image button is a subclass/wrapper over the same descriptor renderer; inheritance, code locality, and direct base-constructor evidence now outweigh the generic specialized-button grouping.

### `ui/diagnostics/FpsPane.cpp`

See [UID:0000JK][FpsPane](by-file/FpsPane.md). This module likely owns the in-client FPS overlay and diagnostics logging path:

- `FpsPane` owns the overlay singleton, `OnPaint`, one-second FPS/statistics update callback, scalar deleting destructor, and the three FpsPane vtable views. The destructor adjustor thunks at [UID:00015K][0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks](by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md) are compiler-generated and should not be emitted as handwritten source.
- `g_pFpsPane`, `g_fpsDebugActive`, and `g_fpsLogEnabled` should stay with this module unless later xref review proves a broader diagnostics owner.
- `0x004b64a0-0x004b67a7` is now active as `FpsPane::UpdateFpsLogSession`; stale ParcelPane metadata/global-data references should not pull it into `ParcelPane.cpp`.
- `FpsPane::UpdateStatistics` reads `MapPane` visible bounds and `ObjectList` row-bucket counts only for diagnostics; those calls should not pull map/object-index ownership into this module.

Rationale: IDA MCP confirms `0x004b6470`, the compact `0x004b67b0-0x004b6caf` FpsPane virtual/timer/destructor cluster, and vtable links, while raw disassembly shows additional constructor/session/helper starts at `0x004b6410`, `0x004b64a0`, `0x004b69b0`, and `0x004b6ae0` that need boundary review. The behavior and strings are FPS-specific, not parcel UI. A 2026-05-26 recheck split the adjustor thunk pair into [UID:0000VN][-ignored](by-memory/-ignored.md), leaving only the scalar deleting destructor as reconstructable source behavior.

### `archive/DATFile.cpp`

See [UID:0000IN][DATFile](by-file/DATFile.md). This module should own:

- `DATFile`, the 20-byte per-entry reader for named DAT resources.
- [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md), the complete open/read/close convenience wrapper around `DATFile`.
- [UID:0000TH][ParseEntries_004A5E60](by-global/ParseEntries_004A5E60.md) as private/static-style support, because IDA shows it is called only by `DATFile::ReadAllEntries` and `DATFile::ReadAllEntriesAlt`.

Rationale: this file is the stream-style DAT API used by image, palette, sound, dialog, and map-name code. Its caller fanout proves it is shared archive infrastructure, not a render/UI/audio-owned helper.

### `archive/DATFileMgr.cpp`

See [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md). This module should own:

- `DATFileMgr`, the public singleton-facing manager wrapper.
- `_DATFileMgr`, the internal archive-vector and uppercase-name index manager.
- [UID:00012F][0x0049c750-0x0049c7f6._DATFileMgrRawDestructor](by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md), a non-modeled IDA function-boundary gap that should still reconstruct as internal manager cleanup.
- [UID:0001XB][DATManagerVtables](by-type/by-vtable/DATManagerVtables.md), both single-slot and adjacent to unrelated RTTI/string data.
- [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md), the 12-byte public wrapper over `_DATFileMgr::LoadDATFileIndex`.
- `DATFileContainer`, the mapped archive file owner.
- [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md), likely as embedded resolver/hash-table cleanup rather than a final standalone class file.
- [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), the global existence probe used across render/resource/audio paths.
- [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) and object ownership for [UID:0000UF][DestroyDATFileMgr_467380](by-item/DestroyDATFileMgr_467380.md), even if the helper function itself is finally placed with application/fatal-load glue.

Rationale: these entities jointly manage archive discovery, memory mapping, entry-table indexing, and name lookup. The current `class_*.cpp` split is a recovery artifact; the behavior is one manager source unit with helper structs/classes. The `ForwardLoadDATFileIndex_49BE70` recovery alias should resolve to the `DATFileMgr::LoadDATFile` method wrapper in this module, not to a separate global source file. The 2026-05-26 IDA pass confirms `0x0049c750` is raw destructor code, not an independent source file or arbitrary data.

### Historical `archive/DATIndexVector.cpp` Proposal - Superseded 2026-08-18

[UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) remains a non-emitting compiler-family index, not a source-tree node. Its seven folded bodies and node/bucket overlays are old-MSVC/Dinkumware standard-container lowering shared by DAT manager, minimap, fitting-room, and monster-image typed containers. That cross-consumer breadth disproves a private DAT helper but does not prove a standalone project module. Consumer-owned typed map/vector/list declarations generate the exact bodies. The historical `DATIndexVector`, node, bucket, and private-remove-helper source proposal is retained here only to explain why it was rejected.

The archive source tree therefore has exactly two authored units: `DATFile.cpp/.h` for the concrete entry reader and its file-local helpers, and `DATFileMgr.cpp/.h` for the public/private manager, mapped container, singleton, lookup API, packed record/location declarations, and typed standard-container members.

### `render/AlphaMaskSurface.cpp`

See [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md). This module likely groups:

- `AlphaMaskSurface`, clipped buffer view helpers, rect fills, radial and elliptic alpha gradients.
- The shared [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md) object layout and [UID:0001TQ][AlphaSurfaceBufferView](by-type/by-struct/AlphaSurfaceBufferView.md) POD view record.
- `DrawFrameWithBlendMode`, the byte-mask frame blitter used by `LightObjImageLib`.
- The provisional `DrawEncodedAlphaFrame` helper at `0x00462f20`, which draws encoded frame runs into alpha masks for `MonsterImageLib`, `StaticObjImageLib`, `EffectObjImageLib`, `ItemObjImageLib`, `NewHumanImageLib`, and three still-raw image-library call-site neighborhoods.
- The raw [UID:0000YK][0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor](by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md) at `0x00462120-0x00462161`, pending final function-boundary reconciliation.
- The [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md) at `0x00462230-0x00462258` is compiler-generated EH cleanup and should not become a source method.
- The real clipped/view helpers at [UID:0000TX][AlphaSurfaceReleaseOwnedPixels_00462260](by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md), [UID:0000U3][BuildClippedAlphaSurfaceView_00462320](by-item/BuildClippedAlphaSurfaceView_00462320.md), and [UID:0000UU][InitAlphaSurfaceView_004623C0](by-item/InitAlphaSurfaceView_004623C0.md), pending final class naming.
- Possibly `IntAlphaSurface`, pending constructor/caller recovery.

Rationale: these are shared render-surface and alpha-mask primitives consumed by light/effect/item/human image libraries. They are too general to be owned by any one asset library. A 2026-05-26 IDA MCP recheck maps six modeled `DrawEncodedAlphaFrame` call sites to established image-library render methods and leaves three raw call-site neighborhoods for boundary recovery, reinforcing that the helper is shared overlay infrastructure. A 2026-05-25 IDA MCP recheck excludes nearby `0x004632c0`; that function uses vtable `0x00612574` and belongs to application error-state cleanup, not alpha rendering.

### `render/IntAlphaSurface.cpp`

See [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md). This provisional module currently contains:

- `IntAlphaSurface::ScalarDeletingDestructor` at `0x00463270-0x004632b1`.
- The [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md) at `0x006112ec`, whose first two slots point to `0x00463270` and `0x00462260`.
- The nearby [UID:0000UU][InitAlphaSurfaceView_004623C0](by-item/InitAlphaSurfaceView_004623C0.md) and raw [UID:0000YK][0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor](by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md) write the same vtable and should stay near this source family until constructor recovery resolves the final split.
- The [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md) writes the same vtable too, but it is EH-only compiler cleanup reached from `0x005fa593`, not evidence for another handwritten method.

Rationale: Wave3 only recovers the destructor, but the vtable name and teardown semantics prove a distinct surface type. IDA vtable references from the adjacent `AlphaMaskSurface` constructor/helper region mean this could later fold into `AlphaMaskSurface.cpp` or a broader `Surface.cpp`; keep the separate tree node until the constructor or full vtable owner is recovered.

## Medium-Confidence Families To Research Next

- `archive/`: the current authored split is exactly [UID:0000IN][DATFile](by-file/DATFile.md) and [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md). [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) is a path-NONE compiler-family index, not a third module. [UID:0000TH][ParseEntries_004A5E60](by-global/ParseEntries_004A5E60.md) is `DATFile.cpp` private/static-style support. [UID:0000T5][LoadIndexedDATSeries](by-global/LoadIndexedDATSeries.md) is `app/Application.cpp` startup policy, while [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md) remains archive-manager API. EPF/image, audio, startup, and loose metadata code remain consumers or adjacent owners, never extra archive units.
- `metadata/`: [UID:0000LC][MetaMan](by-file/MetaMan.md) and [UID:000089][MetaTable](by-class/MetaTable.md) now form the first documented metadata source module. The `0x00523a00-0x00525914` lookup/materializer/row-tree helper chain is now source-structure documented; remaining work is exact outer `Meta.dat` header fields and per-table decoded value semantics.
- `audio/`: remaining work is mostly private MIDI stream/global names and [UID:0000DI][SoundPathVector](by-class/SoundPathVector.md) method boundaries. `SoundManager.cpp/.h` and [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md) `.cpp/.h` now have explicit producer routes, including singleton externs and a standalone local Miles boundary; the former timer-wrapper question is resolved to [UID:0000OT][TimerMgr](by-file/TimerMgr.md). UI consumers such as [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md) and [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md) stay in UI folders while calling into audio modules.
- `render/`: DirectDraw/DirectInput/DirectSound error wrappers and remaining surface/blit classes around the already documented `DirectX`, `GrafPort`, `SoftwareBlend16`, `DIBitmap`, `ImageWriters`, `FontImageLib`, `Palette`, `ImageLib`, `ResourceLayoutTable`, `EPFTileContext`, `ImageFrameTable`, asset image libraries, `AlphaMaskSurface`, and provisional `IntAlphaSurface`. LodePNG and zlib are now third-party codec/support dependencies rather than render-owned implementations.
- `ui/core` versus `render/` for [UID:0000LL][Motion](by-file/Motion.md): dirty-rectangle helpers are UI-core/render-bridge code, while timer-driven animation motion may belong nearer render/game animation. Keep the split explicit until a later owner pass resolves final folders.
- `network/`: remaining work is `ProtocolSend.cpp` helper/interface clustering after the now documented `Socket`, `PacketBuffer`, `FileDownloader`, and `CashShopRequest` send-queue pass. [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md) uses WinInet but is currently placed under `app/` because it is application-owned and multiplexes non-network shell work too. The historical `Session.cpp` planning placeholder is closed as a reviewed no-source-root boundary by [UID:0000NP][Session](by-file/Session.md) and is no longer a physical tree candidate. `g_packetSender` lifetime should stay with `Socket.cpp`, and `0x00596960` should stay with [UID:0000OR][Thread](by-file/Thread.md), while the queue/send interface remains under review.
- `cashshop/`: remaining work after the now documented [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md), [UID:0000JE][FittingRoom](by-file/FittingRoom.md), [UID:0000KD][ItemCatalog](by-file/ItemCatalog.md), and [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md) modules. Follow-up should focus on cleaning fitting-room projected starts/helper pollution and reviewing any remaining cash-shop UI/download helpers not in the `0x0041ba40-0x004245f5` core.
- `map/`: `MapPane` and broader field-map ownership beyond the already documented minimap cluster. The weather layer family now has first-pass docs for [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md), [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md), [UID:0000NR][SnowingLayerPane](by-file/SnowingLayerPane.md), and [UID:0000OD][SwallowLayerPane](by-file/SwallowLayerPane.md). The map-object companion pass now documents [UID:0000M6][ObjectStatusBlob](by-file/ObjectStatusBlob.md), [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md), [UID:0000KO][LightingObjectPane](by-file/LightingObjectPane.md), and [UID:0000NW][SoundObjectPane](by-file/SoundObjectPane.md); UID0000HL AttachmentAnchorResolver is a historical index folded into LightingObjectPane rather than a physical source candidate. Remaining map work should focus on exact packet/state ownership and whether other weather/object companions stay separate files or fold into broader object-pane sources.
- `social/`: remaining follow-up ownership for broader friend/social helpers and any cross-owned say/group/clan input panes beyond the now documented [UID:0000I5][Chatting](by-file/Chatting.md), [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md), [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md), [UID:0000JS][Group](by-file/Group.md), [UID:0000I8][Clan](by-file/Clan.md), [UID:0000I9][ClanBank](by-file/ClanBank.md), [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md), and [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md) modules.
- `ui/core/`: scroll controls, generic input panes, and remaining base-pane helpers around the now documented `Pane`, `Layer`, `DialogPane`, `ControlPane`, `ScreenPane`, `FrameMgr`, and `FrameChrome` clusters.

## File Grouping Rules For Migration

- Prefer folder/module grouping only after at least two independent evidence types agree: names, memory locality, xrefs/callers, shared globals, resource strings, or shared helper functions.
- Treat `class_*.cpp` and single-global recovered files as Wave3 staging containers.
- Keep UI feature dialogs split by feature family when a single module would become too broad.
- Keep library/runtime code excluded from project modules even when heavily called.
- Record every proposed migration in `by-file` first, then run Wave3 dry-run commands before mutating ownership.

## Open Questions

- Whether the original project used feature folders or a flatter Visual C++ project with grouped source files.
- Whether "Old" browser/UI classes represent retained legacy source files or compiler/linker leftovers from older implementations.
- How much generated recovered global code should become free helper functions inside feature `.cpp` files versus utility modules.
- Whether header emission should be enabled later to reflect `.h`/`.cpp` pairs once file ownership stabilizes.

## Next Research Targets

1. Continue archive-consumer documentation around image-loader/surface/palette helpers without reopening the resolved two-unit archive split; `ResourceLayoutStore` is a `List`-backed alias and the historical DATIndex helper ranges are compiler/template evidence.
2. Expand map research from the minimap cluster into `MapPane` and field-map ownership.
3. Continue UI-core boundary cleanup using [UID:0001QV][client_ui_core](by-meta/client_ui_core.md), especially shared layout/text helpers and generated base-destructor owner pollution.
4. Follow up on browser only for data cleanup: reconcile `g_activeBrowserControlPane`, `g_browserRuntime`, `g_browserStatusTextPane`, `dword_67A7CC`, and the broad transport callback alias family.
5. Profile/config format-level follow-up now has first-pass docs in [UID:0001QL][client_profile_storage](by-meta/client_profile_storage.md), [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md), and [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md). The former full-entry `type == 0` caveat is resolved as a corrupt-state writer hazard rather than expected runtime state, and macro/hotkey states `2`/`3` are resolved as spell-tab `S` versus inventory/item-tab `I`; remaining work is final semantic naming for the non-macro profile fields and final source names for the linked `LivingObjectPane` dispatch helpers.
6. Create `by-memory` docs for exact ranges only when they justify ownership or exclusion decisions.

## 2026-08-22 UID0000MM PoolAllocator Tree Closure

- `NexusTK/util/PoolAllocator.h` and `NexusTK/util/PoolAllocator.cpp` are the accepted standalone sibling pair.
- The authored PoolAllocator core ends at `0x004b1585`; file-local helpers at `0x00549bd0-0x00549bf1` and `0x00549c00-0x00549c18` remain part of the same CPP despite non-contiguity.
- The CPP order is header include, `<new>`, two private records, two helper prototypes, constructor, Allocate, Free, destructor, AllocatePoolChunk, and by-value FreePoolChunkList. The H is the single complete 0x28 class declaration authority.
- The former `ThreadSafeNodeList.cpp` tree entry is retired. [UID:0000OS][ThreadSafeNodeList](by-file/ThreadSafeNodeList.md) and [UID:0000EX][ThreadSafeNodeList](by-class/ThreadSafeNodeList.md) remain non-emitting historical alias pages for `PoolAllocator::Free`; they do not represent a physical source path.
- StringBase, StringUtil, map-object, render/Motion, and UserPane units are consumers. Their nineteen static pool declarations remain in the consumer CPPs and include the standalone PoolAllocator header.
