# A006 Notes

Pending locked-file follow-ups from Batch 140. The target by-struct docs and `by-class/SimpleUString.md` were edited under normal leases, and `by-class/-coverage-report.md` was updated directly. Manual struct report synchronization was blocked because `by-type/by-struct/-coverage-report.md` was leased by Agent-A008 when Batch140 edits were made and by Agent-A003 on the final lease check.

- `by-type/by-struct/-coverage-report.md`
  - Replace UID:0001V0 row with:
    `[UID:0001V0][ListNode](by-type/by-struct/ListNode.md) : reconstructable : 85% : very strong : Attached to [UID:0000KR][LinkedList](by-file/LinkedList.md) after Batch140 raised the child to 85/90 and the direct parent was already 85/85; IDA-confirmed 16-byte node with next/prev links, two caller-specific payload dwords, self-linked sentinel allocation, payload wrapper copy into +0x08/+0x0c, cleanup traversal, cross-feature caller spread, and remaining typedef/payload-name caveat.`
  - Replace UID:0001W4 row with:
    `[UID:0001W4][SimpleUStringPointerBackedLayout](by-type/by-struct/SimpleUStringPointerBackedLayout.md) : reconstructable : 86% : strong : Attached to [UID:0000OA][StringBase](by-file/StringBase.md) after Batch140 raised the child to 86/88 and the direct parent was already 88/86; pointer-backed ANSI/UTF-16 data pointer with 12-byte ref-counted header, empty sentinel initialization, ANSI/wide format-worker capacity/retry/detach behavior, data[-2] wide literal compare convention, preserved mystr::StringBase<wchar_t,...> metadata, and explicit SSO-7 exclusion.`
  - Replace UID:0001W5 row with:
    `[UID:0001W5][SimpleUStringSso7Layout](by-type/by-struct/SimpleUStringSso7Layout.md) : reconstructable : 85% : strong : Attached to [UID:0000D9][SimpleUString](by-class/SimpleUString.md) after Batch140 raised the child to 85/88 and the direct class parent to 85/87; inferred 24-byte UTF-16 SSO-7 layout with exact clear/assign endpoint helpers, inline/heap capacity gate, length/capacity/growth semantics, concrete empty static-object instance, mixed aggregate exclusion, and explicit pointer-backed StringBase boundary.`

Pending locked-file follow-ups from Batch 135. The target docs, direct `StringBase` by-file parent, `by-global/-coverage-report.md`, and `by-type/by-template/-coverage-report.md` were edited under normal leases. Manual report synchronization was blocked because `by-file/-coverage-report.md` and `by-type/by-struct/-coverage-report.md` were leased by Agent-A007 on the first attempt and by Agent-A003 on the final lease check.

- `by-file/-coverage-report.md`
  - Replace UID:0000OA row with:
    `[UID:0000OA][StringBase](by-file/StringBase.md) : reconstructable : 88% : strong : Ref-counted ANSI/UTF-16 string-buffer implementation split from the true LObject runtime shell and promoted to the direct parent for StringBase template/header/global storage pages; Batch135 live IDA reconfirmed key allocation/release/format/compare helper bounds, `23`/`16` sentinel refs, `8` trim-pointer refs, four-ref pool-storage pattern, preserved `mystr::StringBase<wchar_t,mystr::mychar_traits<wchar_t>>` vtable/RTTI names, exact child aggregate attachments, and remaining final header/API spelling caveat.`

- `by-type/by-struct/-coverage-report.md`
  - Replace UID:0001VQ row with:
    `[UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md) : reconstructable : 86% : strong : Attached to [UID:0000OA][StringBase](by-file/StringBase.md) after Batch135 raised the direct parent to `88/86`; twelve-byte string header verified through ANSI/wide allocation, release, empty-sentinel, sharing, copy-on-write, `InterlockedDecrement(data - 0x0c)`, `data - 0x08` length use, capacity/pool switching, and StringUtil/SimpleUString non-direct-owner rationale.`

Pending locked-file follow-ups from Batch 035. `by-memory/-coverage-report.md` was updated and validated directly after the lease became available. `by-global/-coverage-report.md` was applied by A006 on 2026-06-08. `by-file/-coverage-report.md` remained leased by A003 when the Batch 105 session started.

- `by-file/-coverage-report.md`
  - Replace UID:0000II row with:
    `[UID:0000II][Crasher](by-file/Crasher.md) : reconstructable : 86% : very strong : Diagnostic crash pane companion with refreshed live IDA evidence for g_pCrasher storage, constructor/destructor singleton writes/clears, application cleanup read, function-boundary/caller evidence, singleton/vtable ownership, exception-handler flag interaction, deliberate crash behavior, standalone platform placement rationale, and remaining source-split questions documented.`
  - Replace UID:0000K6 row with:
    `[UID:0000K6][InputMan](by-file/InputMan.md) : reconstructable : 86% : very strong : Win32/IMM input manager with refreshed g_pInputMan storage/xref/boundary evidence, projected NexusTK/input path, corrected executable island inventory, class state layout, singleton lifecycle, vtable/read-only boundary, Windows/IMM dispatch table relationship, Application/window-message callers, IME pane/Event/KeySpeed boundaries, and unresolved helper/global typing caveats.`
  - Replace UID:0000N0 row with:
    `[UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) : reconstructable : 86% : very strong : ConnectionClosedDialog/ReconnectDialog network dialog module with refreshed exact singleton storage child UID:0002VT, constructor/cleanup write-clear evidence for both slots, caller evidence for reconnect and connection-closed creation, and mixed-range split rationale recorded.`
  - Replace UID:0000HO row with:
    `[UID:0000HO][BackPane](by-file/BackPane.md) : reconstructable : 86% : very strong : Root BackPane/BackGroundPane map backdrop module with refreshed exact g_pBackGroundPane child UID:0002VV, root g_pBackPane storage, BackGroundPane lifecycle slot evidence, vtable/resource references, InitializeMainUiGraph construction evidence, and rejected generated-owner pollution documented.`

Pending locked-file follow-ups from Batch 048. The target docs, associated docs, and `by-memory/-ignored.md` were edited and validated. `by-memory/-coverage-report.md` was applied by A006 on 2026-06-08. `by-class/-coverage-report.md` and `by-file/-coverage-report.md` remained leased by A003 when the Batch 105 session started.

- `by-class/-coverage-report.md`
  - Replace UID:0000BY row with:
    `[UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) : reconstructable : 87% : strong : ResourceLayoutTable/ImageLib facet with refreshed IDA-exclusive child ranges, live method boundaries, lazy EPF/EPD registry behavior, row layout, g_pEPFLib/ImageLib singleton ownership, no separate vtable evidence, and corrected parent gate through ImageLib at 86/85.`
  - Replace UID:0000G0 row with:
    `[UID:0000G0][WearInputPane](by-class/WearInputPane.md) : reconstructable : 87% : very strong : Equipment-wear prompt with IDA-confirmed constructor/key/submit methods, prompt id 33, vtables, slot conversion bounds, opcode 0x1e packet sender path, and exact adjacent SendWearPacket child UID 0002YP.`

- `by-file/-coverage-report.md`
  - Replace UID:0000K2 row with:
    `[UID:0000K2][ImageLib](by-file/ImageLib.md) : reconstructable : 86% : strong : NexusTK/render/ImageLib.cpp EPF image-library manager with corrected IDA method bounds, g_pEPFLib, vtable/layout anchors, cache-list lifecycle, signature correction, ResourceLayoutTable facet ownership, and refreshed 85-confidence parent-gate evidence.`
  - Replace UID:0000N5 row with:
    `[UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) : reconstructable : 86% : medium-high : ImageLib/EPF layout registry helper-split placeholder with public API, singleton/list ownership, IDA evidence, ownership exclusions, corrected exclusive child links, and exact modeled methods 0002KO, 0002KP, 0002KR, 0002KS, 0002KU, 0002KV, and 0002KW attaching through ResourceLayoutTable class/facet UID 0000BY to ImageLib.cpp; raw/helper pages 0002KQ and 0002KT remain unattached.`

Pending locked-file follow-ups from Batch 060. The target docs, split children, associated parent docs, and `by-global/-coverage-report.md` were edited and validated. `by-memory/-coverage-report.md` was applied by A006 on 2026-06-08. `by-file/-coverage-report.md` and `by-class/-coverage-report.md` remained leased by A003 when the Batch 105 session started.

- `by-file/-coverage-report.md`
  - Replace UID:0000L8 row with:
    `[UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md) : reconstructable : 86% : strong : Menu button/select-pane source with refreshed selector singleton parent-gate evidence, seven-reference g_pMenuVarietySelectPane lifecycle, constructor caller from MenuVarietyPane click handling, selector destructor/clear-helper ownership, old-user-status boundary, and ranking/quit/popup split documented.`

- `by-class/-coverage-report.md`
  - Replace UID:0000FS row with:
    `[UID:0000FS][UserStatusPane](by-class/UserStatusPane.md) : reconstructable : 88% : strong : Newer local status summary pane with Batch 060 validator-state repair, exact status-icon setter child UID:0002LP, constructor/cleanup/accessors/packet router/paint/rect/glyph helpers/payload parser/fields/resources/singleton coverage, and corrected parent validity for memory children.`

Pending locked-file follow-ups from Batch 072. The target docs were edited/validated and the UID:0001OJ generated coverage error was cleared by validator; generated memory coverage now lists UID:0001OJ as unassigned rather than `autogen_parent_unknown`. A006 applied the UID:0000X6 and UID:0000XK rows on 2026-06-08; the UID:0001OJ row remains pending because the live coverage report currently contains newer Batch 028 wording and was not overwritten during Batch 105 startup cleanup.

- `by-memory/-coverage-report.md`
  - Replace UID:0001OJ row with:
    `[UID:0001OJ][0x0066da9c-0x0066da9e.g_mapTilePixelWidth](by-memory/0x0066da9c-0x0066da9e.g_mapTilePixelWidth.md) 0x0066da9c-0x0066da9e | global-data word | g_mapTilePixelWidth : reconstructable : 86% : strong : Two-byte map tile pixel-width global; Batch 072 repaired generated coverage by clearing invalid AUTOGEN_PARENT_UID 0000T7 because MapTilePixelDimensions is the canonical by-global cross-reference but not an autogen root until it has a valid file parent; IDA evidence remains item size 2, value 0x0030/48, local bytes 30 00 00 00 30 00 00 00, 89 xrefs, and separate padding/height boundaries.`

Pending locked-file follow-ups from Batch 083. The target class docs and direct by-file parents were edited and validated; generated class coverage assigns UID:00003I -> UID:0000IO, UID:00003V -> UID:0000IV, and UID:00003P -> UID:0000IR. Manual report synchronization was blocked because `by-class/-coverage-report.md` and `by-file/-coverage-report.md` were leased by Agent-A003 until `2026-06-07T21:48:35Z` when final report synchronization was attempted.

- `by-class/-coverage-report.md`
  - Replace UID:00003I row with:
    `[UID:00003I][DATFileMgr](by-class/DATFileMgr.md) : reconstructable : 86% : strong : Public DAT manager wrapper assigned to direct file parent [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md); Batch 083 live IDA reconfirmed public wrapper constructor/load/destructor, raw find-forwarder and ordinary internal cleanup starts, internal manager helper boundaries, resolver cleanup, public/internal vtable references, and one-source-module public/private manager ownership.`
  - Replace UID:00003P row with:
    `[UID:00003P][Deque](by-class/Deque.md) : reconstructable : 86% : very strong : Shared 4-byte-entry deque assigned to direct utility file parent [UID:0000IR][Deque](by-file/Deque.md); Batch 083 live IDA reconfirmed all six non-contiguous helper ranges, refreshed caller counts, raw PrimeNumberGenerator-adjacent element-address call, broad event/folder-tree/map/world-map/sound caller spread, and corrected +0x00/+0x04/+0x08/+0x0c/+0x10 layout.`
  - Replace UID:00003V row with:
    `[UID:00003V][DIBitmap](by-class/DIBitmap.md) : reconstructable : 85% : strong : Win32 DIB-section wrapper assigned to direct file parent [UID:0000IV][DIBitmap](by-file/DIBitmap.md); Batch 083 live IDA reconfirmed constructor, scalar deleting destructor, modeled accessors, raw destructor/accessor starts, vtable references from constructor/factory/destructors, compact layout, and PCX factory/decode relationship while leaving free PCX helpers outside the class.`

- `by-file/-coverage-report.md`
  - Replace UID:0000IO row with:
    `[UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) : reconstructable : 89% : strong : Public/private DAT manager assigned to `NexusTK/archive/DATFileMgr.cpp`; Batch 083 live IDA reconfirmed direct class-parent gate, public wrapper methods, raw forwarder/cleanup starts, internal helper boundaries, container/resolver helpers, singleton/global helper ownership, exact ranges, container layout, dependencies, and public/internal vtable references.`
  - Replace UID:0000IR row with:
    `[UID:0000IR][Deque](by-file/Deque.md) : reconstructable : 85% : strong : Shared `NexusTK/util/Deque.cpp` utility container with Batch 083 direct class-parent gate, six non-contiguous helper ranges, refreshed caller counts, broad utility caller fanout, raw PrimeNumberGenerator-adjacent helper, source-structure decision, IDA-corrected layout, generated-output caveats, and boundary corrections documented.`
  - Replace UID:0000IV row with:
    `[UID:0000IV][DIBitmap](by-file/DIBitmap.md) : reconstructable : 85% : strong : `NexusTK/render/DIBitmap.cpp` DIB wrapper with Batch 083 direct class-parent gate, live constructor/destructor/accessor/raw-start recheck, vtable reference set, compact layout fields, PCX factory/decode relationship, exact vtable child, omitted accessor cluster, and render/archive boundary documented.`

Pending locked-file follow-ups from Batch 090. The target class docs and direct by-file parents were edited and validated; generated class coverage assigns UID:000067 -> UID:0000HJ, UID:00006A -> UID:0000JY, and UID:00006I -> UID:0000K5. Manual report synchronization was blocked because `by-class/-coverage-report.md` and `by-file/-coverage-report.md` were leased by Agent-A007 until `2026-06-07T22:01:15Z` when final report synchronization was attempted.

- `by-class/-coverage-report.md`
  - Replace UID:000067 row with:
    `[UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md) : reconstructable : 85% : very strong : Attached hit/health bar overlay assigned to direct file parent [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md); Batch 090 live IDA reconfirmed single/dual constructors, unwind cleanup, bounds refresh and active flag helpers, bounds/offset/render methods, scalar deleting destructor, pool gate byte_69B934, MapPane caller anchors, and attached-overlay ownership.`
  - Replace UID:00006A row with:
    `[UID:00006A][HumanImageLib](by-class/HumanImageLib.md) : reconstructable : 85% : strong : Legacy old-human/equipment image library assigned to direct file parent [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md); Batch 090 live IDA reconfirmed constructor/destructor/clear/scalar-wrapper boundaries, singleton/vtable xrefs, ProtectedArray and frame-table ownership, old/new human split, and blank final C++ pending field/source declaration audit.`
  - Replace UID:00006I row with:
    `[UID:00006I][IMEStatusPane](by-class/IMEStatusPane.md) : reconstructable : 85% : very strong : Bottom-right IME/ENG status label assigned to direct file parent [UID:0000K5][IMEPanes](by-file/IMEPanes.md); Batch 090 live IDA reconfirmed SetText, constructor, destructor, mode-change, paint, scalar deleting destructor, SetText callers, adjustor-thunk/destructor island evidence, and IME pane-family ownership.`

- `by-file/-coverage-report.md`
  - Replace UID:0000HJ row with:
    `[UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) : reconstructable : 85% : strong : `NexusTK/map/AttachedObjectPane.cpp` source root with Batch 090 parent gate repair for HitBarObjectPane, attached base, registry detach helper, anchor resolver, speech balloons, object labels, hit bars, damage numbers, durable by-* evidence, MapPane/static-pool support, helper/anchor boundary notes, destructor island evidence, and raw 0x00468250 caveat documented.`
  - Replace UID:0000JY row with:
    `[UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) : reconstructable : 85% : strong : `NexusTK/render/HumanImageLib.cpp` old human/equipment image-library source module with Batch 090 parent gate repair, corrected IDA bounds, singleton/vtable/layout anchors, constructor/destructor/clear/scalar-wrapper evidence, destructor release behavior, ProtectedArray/frame-table ownership, and separation from NewHumanImageLib documented.`
  - Replace UID:0000K5 row with:
    `[UID:0000K5][IMEPanes](by-file/IMEPanes.md) : reconstructable : 88% : strong : `NexusTK/input/IMEPanes.cpp` IME pane family with Batch 090 parent gate repair for IMEStatusPane, status/composition/candidate/root panes, g_pIMEPane singleton, focus list, candidate deque support, generated owner pollution closures, InputMan boundary, adjustor/destructor island evidence, and exact memory refs documented.`

Pending locked-file follow-ups from Batch 105. The target docs and associated class/source parent docs were edited under normal leases. A006 applied the `by-memory/-coverage-report.md` rows on 2026-06-08 after the report lease became available. Manual class report synchronization remains pending because `by-class/-coverage-report.md` was leased when the continuation sync was checked.

- `by-class/-coverage-report.md`
  - Replace UID:00000S row with:
    `[UID:00000S][BackPane](by-class/BackPane.md) : reconstructable : 85% : very strong : Root in-game background pane assigned to BackPane file parent; Batch 105 split exact constructor/destructor and activate/paint/deleting-destructor memory children around the cross-owned Application shutdown-message helper, with live IDA constructor caller, singleton lifecycle, paint, and next-owner boundary evidence documented.`
  - Replace UID:0000G3 row with:
    `[UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md) : reconstructable : 88% : strong : Legacy browser-backed web-board dialog assigned to WebBoardDialog file parent; Batch 105 parent-gate refresh raised confidence using live IDA checks for the modeled no-xref layout helper, raw no-xref mode-rect helper, two old-constructor callers, and five g_pWebBoardDialogOld lifecycle refs while retaining raw-helper/source-name caveats.`

Pending locked-file follow-ups from Batch 118. The target docs and associated parent/source docs were edited under normal leases. Manual report synchronization was blocked because `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, and `by-file/-coverage-report.md` were leased by Agent-A005 when the Batch 118 sync was first attempted, then by Agent-A010 on the retry at 2026-06-08T08:41:50Z.

- `by-memory/-coverage-report.md`
  - Replace UID:00022J row with:
    `[UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) 0x004b81a0-0x004b81eb | raw-function | WideStringHashHelper : reconstructable : 83% : strong : Batch 118 live IDA reconfirmed raw unmodeled UTF-16 string hash body, exact bytes/padding, unique 1000003 multiply/XOR shape, no direct xrefs, and checked StringUtil/CachedHashTable/RectBounds/PathUtil candidates; completion remains below gate because no direct source owner or caller is proven.`
  - Rename/replace UID:00015Y row with:
    `[UID:00015Y][0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md) 0x004b89a0-0x004b8a7f | class-method | GeneralPurposePanel2SwitchActiveChild : reconstructable : 86% : very strong : Batch 118 corrected exclusive end from 0x004b8a7e to 0x004b8a7f so the final retn byte is included, assigned to GeneralPurposePanel2 after raising class/file parents; live IDA reconfirmed one caller, one-child gate, active-index/child-slot writes, bounds, virtual calls, and frame-refresh dependency.`

- `by-class/-coverage-report.md`
  - Replace UID:00005R row with:
    `[UID:00005R][GeneralPurposePanel2](by-class/GeneralPurposePanel2.md) : reconstructable : 85% : very strong : One-child alternate panel assigned to GeneralPurposePanel file parent; Batch 118 corrected and attached exact switch helper UID:00015Y with fixed 0x004b8a7f boundary, constructor/destructor/accessor/singleton/vtable evidence, NewSystemMessagePane child construction, active-index/child-slot behavior, and user-pane caller documented.`

- `by-file/-coverage-report.md`
  - Replace UID:0000JQ row with:
    `[UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md) : reconstructable : 85% : strong : General-purpose side-panel source root with seven-child primary panel and one-child GeneralPurposePanel2, Batch 118 corrected and attached switch helper UID:00015Y, singleton/vtable/lifecycle evidence, child-index map, frame-chrome boundaries, and source path under ui/panels documented.`

Pending locked-file follow-ups from Batch 127. The target docs, `FolderTreePane` class parent, `FolderTreePane::TreeElem` struct parent, `by-memory/-ignored.md`, and `by-type/by-struct/-coverage-report.md` were edited under normal leases. Manual report synchronization was blocked because `by-memory/-coverage-report.md` and `by-class/-coverage-report.md` were leased by Agent-A003 when the Batch 127 sync was first prepared, then by Agent-A009 on the post-validation check at 2026-06-08T09:00Z.

- `by-memory/-coverage-report.md`
  - Replace UID:0002MW row with:
    `[UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) 0x004b55e0-0x004b564d | record copy helper | FolderTreeElemCopyConstruct : reconstructable : 85% : strong : Batch 127 assigned to FolderTreePane::TreeElem after refreshing the direct type/class parent gate; live IDA reconfirmed exact copy helper bounds, five callers, sole SimpleUString copy callee, copied link/string/row/depth/flag fields, and source-declared/generated-binary handling.`
  - Replace UID:0002MX row with:
    `[UID:0002MX][0x004b56e0-0x004b575f.FolderTreeStorageDestructor](by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md) 0x004b56e0-0x004b575f | template destructor | FolderTreeStorageDestructor : reconstructable : 85% : strong : Batch 127 assigned to TreeStorage<FolderTreePane::TreeElem> after direct parent gate cleared; live IDA reconfirmed exact destructor bounds, three cleanup/destructor callers, string-field destruction at +0x14, aligned free validation, free helper, invalid-parameter guard, and begin/end/capacity zeroing.`
  - Replace UID:00015Z row with:
    `[UID:00015Z][0x004b8a80-0x004b8a9a.GeneralPurposePanelSingletonClearHelpers](by-memory/0x004b8a80-0x004b8a9a.GeneralPurposePanelSingletonClearHelpers.md) 0x004b8a80-0x004b8a9a | constructor cleanup helper | GeneralPurposePanelSingletonClearHelpers : ignored : 86% : strong : Batch 127 reclassified as RECONSTRUCTABLE:FALSE compiler cleanup support; live IDA reconfirmed two exact 0xb singleton-null helpers, no ordinary callers, no callees, cleanup-table xrefs only at 0x005ff294 and 0x005ff1fe, direct lifecycle coverage in panel constructors/destructors/globals, and matching by-memory/-ignored ledger entry.`

- `by-class/-coverage-report.md`
  - Replace UID:00005A row with:
    `[UID:00005A][FolderTreePane](by-class/FolderTreePane.md) : reconstructable : 85% : strong : Filesystem tree control with Batch 127 parent-gate repair for nested FolderTreePane::TreeElem; live IDA refresh ties TreeElem layout, copy helper, storage destructor, lazy child enumeration flags, expand/collapse, iterator traversal, core methods, vtables, and FolderTreePane.cpp source ownership while retaining final field/header spelling caveats.`
