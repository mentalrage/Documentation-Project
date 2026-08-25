*** UID:0000NP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Session

## Status

- Confidence: very strong that the shipped executable has no distinct generic `Session.cpp`, `GameSession.cpp`, `Session.h`, or `GameSession.h` source root.
- Disposition: reviewed non-standalone negative source boundary, not an unresolved planning placeholder.
- Projected path status: `NONE`. Keep this page out of generated source roots.
- Canonical owner: `NONE`. There is no generic Session class, global, type, lifetime object, coherent source island, or emitted facade to own.
- Current source-root decision: all session-labeled and session-shaped behavior redirects to specialized owners. The literal source families are [UID:0000IU][DialogSession](by-file/DialogSession.md) and [UID:0000HX][BulletinSession](by-file/BulletinSession.md); transport, lifecycle, dispatch, login, diagnostics, launcher, and HTTP state remain with their existing modules.
- Primary notes: [UID:0001QH][client_network](by-meta/client_network.md)

## File Role

This page is a documentation-only exclusion/index boundary. Exhaustive current binary, documentation, generated-output, and source-routing evidence supports no generic Session compilation unit. The page prevents UI dialog sessions, transport state, packet serialization, thread queues, login/application state, world dispatch, diagnostics logging, launcher vendor APIs, and WinINet handles from being merged into a reverse-engineered facade that the original binary does not support.

The complete final split is:

- `class_DialogSession.cpp` and `class_DialogInSession.cpp` are UI/dialog session stack code and are documented under [UID:0000IU][DialogSession](by-file/DialogSession.md), with exact memory at [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md).
- `class_BulletinSession.cpp` is board/mail social-dialog session code and is documented under [UID:0000HX][BulletinSession](by-file/BulletinSession.md), with exact memory at [UID:0000ZH][0x00471150-0x00471ff1.BulletinSessionCore](by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md).
- Stateful transport and `g_packetSender` lifetime belong to [UID:0000NS][Socket](by-file/Socket.md); serialization/cursors belong to [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md); transforms/key state belong to [UID:0000M9][PacketTransform](by-file/PacketTransform.md); generic request posting belongs to [UID:0000OR][Thread](by-file/Thread.md).
- Login/server choice belongs to [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md) and Application/Config/login UI; in-game packet dispatch belongs to [UID:0000L3][MapPane](by-file/MapPane.md).
- Connection status/reconnect UI belongs to [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md), [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md), and [UID:0000OI][TerminalPane](by-file/TerminalPane.md).
- HTTP/API session handles belong to [UID:0000JC][FileDownloader](by-file/FileDownloader.md), cash-shop modules, or [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md). They are WinINet handle scopes, not a game-session object.
- LG/Channel-i startup-session parsing belongs to [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md); FPS logging sessions belong to [UID:0000JK][FpsPane](by-file/FpsPane.md).

Therefore no `network/Session.cpp` or generic header should be created. [UID:0000MV][ProtocolSend](by-file/ProtocolSend.md) remains a separate reviewed placeholder for cross-feature free send helpers; it must not be merged with this negative boundary merely to manufacture a source root.

## 2026-08-15 B006 Exhaustive Recheck

### Canonical Evidence Baseline

- Live read-only IDA MCP research used canonical IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x00400000`, image size `0x002b3000`, 8,113 functions, 2,172 named functions, 4,780 unnamed functions, and 2,068 cached strings.
- Binary identity: MD5 `4247e04e20b65d6414c7238aa8ff5515`; SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- Primary research session `b002_uid0000hq_rollback_20260815` and final availability session `supervisor_uid0000li_rollback_20260815` both resolved the same canonical IDB. The final public runtime attestation at `2026-08-16T00:29:17.790832+00:00` returned schema `1`, `ok:true`, `errors:[]`; `server_health` remained `status:ok`, Hex-Rays ready, and the 2,068-string cache ready.
- `auto_analysis_ready:false` did not prevent any bounded name, type, decompile, xref, byte, pointer-route, or entity query used for this decision.

### Complete Binary Lexical Inventory

| Category | Exact count | Result |
| --- | ---: | --- |
| Functions with Session identity | 3 | All are specialized BulletinSession/DialogInSession/UserPane helpers. |
| Globals/named data | 37 | Specialized BulletinSession/DialogSession/DialogInSession vtables, RTTI/COL/CHD/base records, `g_pBulletinSession`, and the LG vendor export string. |
| Names | 40 | The same 37 data names plus the 3 functions. |
| Strings | 5 | `WaitForSessionParameter` and four specialized Dialog/Bulletin RTTI names. |
| Local types | 3 | Incomplete `BulletinSession`, `DialogInSession`, and `DialogSession`. |
| Imports | 0 | No generic Session/GameSession import. |

No `Session`, `GameSession`, `NetworkSession`, or `LoginSession` class, type, global, constructor, destructor, vtable, RTTI record, import, source path, or lifecycle object exists.

### Specialized Function Inventory

| Address/range | Current identity and body evidence | Exact inbound route | Final owner |
| --- | --- | --- | --- |
| `0x00471480`, `[0x00471480,0x004714a3)`, size `0x23`, SHA256 `F765E06998F113EE41119835E5A4AD1DAE07B4A04B8AADD23ABDCBECB876E4A1` | `bool __thiscall BulletinSession__HandlePacketEvent(BulletinSession *, Event *)`; checks opcode `0x31` and forwards to the Bulletin dispatcher. | Vtable data xref `0x00613b7c`; no direct code caller. | BulletinSession EventHandler override. |
| `0x004a1400`, `[0x004a1400,0x004a144e)`, size `0x4e`, SHA256 `74685B80DE9B8260D1629500B61D28E6B8E16B623742C03854064B425401F30F` | Typed `DialogInSession` constructor with `DialogSession *session`, `unsigned short dialogConfigId`, and `unsigned char dialogType`; fields land at `+0x270` and `+0x26c`. | Nine code refs: `0x472012`, `0x4720c8`, `0x472cf8`, `0x475445`, `0x476c51`, `0x4777e9`, `0x479168`, `0x47b282`, `0x47d09c`. | DialogSession/DialogInSession. |
| `0x005a50a0`, `[0x005a50a0,0x005a5103)`, size `0x63`, SHA256 `AB984DCF3498C673B8D3D7E39EB5528E8A6F5BA3A633EEB1D85C50C0CD3631A7` | `EnsureNormalBulletinSession`; checks `g_pBulletinSession`, allocates `0x104`, and calls the BulletinSession constructor. | `0x4cf6fd`, `0x4cf92e`, `0x5a6d18`, `0x5abe8c`. | UserPane/local-player helper, [UID:0004US][0x005a50a0-0x005a5103.EnsureNormalBulletinSession](by-memory/0x005a50a0-0x005a5103.EnsureNormalBulletinSession.md). |

`g_pBulletinSession` at `0x0067adc0` remains typed `BulletinSession *` and has eleven data refs at `0x4711a2`, `0x4711a9`, `0x47128a`, `0x47e840`, `0x47eab0`, `0x508776`, `0x513bd3`, `0x5466e8`, `0x5a50c3`, `0x5a60c8`, and `0x5bd0f4`. That specialized singleton route does not imply a generic transport session.

### Source-Bearing Inventory For Generic Session

| Category | Count | Disposition |
| --- | ---: | --- |
| Source-authored functions/methods | 0 | No generic receiver, namespace, source island, or caller cluster. |
| Constructors/destructors/compiler wrappers | 0 | All Session-named lifecycle belongs to DialogSession or BulletinSession. |
| Globals/statics/constants/tables | 0 | Specialized Bulletin singleton/compiler data and Socket/Config state stay elsewhere. |
| Types/layouts/enums/vtables/RTTI | 0 | Only three specialized Session types exist. |
| Strings/imports/resources | 0 | The LG vendor export string belongs to RegistryConfig; no target resource/import exists. |
| Exact memory ranges/children | 0 | Every plausible range has an existing specialized owner. |
| CPP/H generated roots | 0 | Generic Session/GameSession CPP/H are intentionally absent. |

### Complete 40-Path Session-Named Documentation Inventory

| UID | Exact path | Final disposition |
| --- | --- | --- |
| UID0000NP | `by-file/Session.md` | This reviewed negative boundary; path/owner NONE. |
| UID0000IU | `by-file/DialogSession.md` | DialogSession source owner. |
| UID00003U | `by-class/DialogSession.md` | DialogSession class owner. |
| UID00003S | `by-class/DialogInSession.md` | DialogInSession class owner. |
| UID0001U5 | `by-type/by-struct/DialogSessionLayouts.md` | DialogSession/DialogInSession layouts. |
| UID0001XD | `by-type/by-vtable/DialogSessionVtables.md` | DialogSession vtable/RTTI owner. |
| UID000131 | `by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md` | DialogSession core source range. |
| UID000132 | `by-memory/0x004a0f40-0x004a14a7.BulletinSessionDialogStack.md` | Legacy cross-link; final owner DialogSession. |
| UID000134 | `by-memory/0x004a146f-0x004a149b.DialogSessionAdjustorThunks.md` | DialogSession compiler thunks. |
| UID0002NB | `by-memory/0x00618d2c-0x00618e50.DialogSessionVtableData.md` | DialogSession compiler data. |
| UID0003Q2 | `by-memory/0x0047e850-0x0047e855.DialogSessionDestructorJumpThunk.md` | DialogSession compiler jump thunk. |
| UID0000HX | `by-file/BulletinSession.md` | BulletinSession source owner. |
| UID00001D | `by-class/BulletinSession.md` | BulletinSession class owner. |
| UID0000QG | `by-global/g_pBulletinSession.md` | BulletinSession singleton-global owner. |
| UID0001PA | `by-memory/0x0067adc0-0x0067adc4.g_pBulletinSession.md` | BulletinSession singleton storage. |
| UID0000ZH | `by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md` | BulletinSession aggregate core. |
| UID0004FS | `by-memory/0x00471150-0x0047126c.BulletinSessionConstructor.md` | BulletinSession constructor. |
| UID0004FT | `by-memory/0x00471270-0x00471299.BulletinSessionCleanup.md` | BulletinSession cleanup. |
| UID0004FU | `by-memory/0x004712a0-0x004712ac.BulletinSessionActivateScreenDimmer.md` | BulletinSession dimmer helper. |
| UID0004FV | `by-memory/0x004712b0-0x004712e5.BulletinSessionDialogRectRawNoRoute.md` | Bulletin raw/no-route evidence; retain current non-emitting disposition. |
| UID0004FW | `by-memory/0x004712f0-0x004713a6.BulletinSessionOpenNewArticleDialog.md` | Bulletin article-dialog method. |
| UID0004FX | `by-memory/0x004713b0-0x00471476.BulletinSessionOpenReplyDialog.md` | Bulletin reply-dialog method. |
| UID0004FY | `by-memory/0x00471480-0x004714a3.BulletinSessionPacketForwarder.md` | Bulletin packet-event override. |
| UID0004FZ | `by-memory/0x004714b0-0x004714fc.BulletinSessionSendBoardListRequestRawNoRoute.md` | Bulletin raw/no-route request helper. |
| UID0004G0 | `by-memory/0x00471500-0x0047154c.BulletinSessionSendPredefinedFormRequestRawNoRoute.md` | Bulletin raw/no-route request helper. |
| UID0004G1 | `by-memory/0x00471550-0x00471872.BulletinSessionPacketDispatcher.md` | Bulletin packet dispatcher. |
| UID0004G2 | `by-memory/0x00471872-0x00471898.BulletinSessionDispatcherJumpTable.md` | Bulletin dispatcher jump table. |
| UID0004G3 | `by-memory/0x004718a0-0x00471956.BulletinSessionOpenBoardListDialog.md` | Bulletin board-list method. |
| UID0004G4 | `by-memory/0x00471960-0x00471a26.BulletinSessionOpenArticleListDialog.md` | Bulletin article-list method. |
| UID0004G5 | `by-memory/0x00471a30-0x00471bfd.BulletinSessionHandleArticleAction.md` | Bulletin article-action handler. |
| UID0004G6 | `by-memory/0x00471c00-0x00471dcd.BulletinSessionHandlePredefinedFormAction.md` | Bulletin predefined-form handler. |
| UID0004G7 | `by-memory/0x00471dd0-0x00471e96.BulletinSessionOpenMailListDialog.md` | Bulletin mail-list method. |
| UID0004G8 | `by-memory/0x00471ea0-0x00471ff1.BulletinSessionHandleMailReadResult.md` | Bulletin mail-result handler. |
| UID0003Q1 | `by-memory/0x0047e840-0x0047e84b.BulletinSessionConstructorUnwindSingletonClear.md` | Bulletin compiler-unwind singleton clear. |
| UID0003Q4 | `by-memory/0x0047ea90-0x0047eaef.BulletinSessionScalarDeletingDestructor.md` | Bulletin scalar deleting destructor. |
| UID0004US | `by-memory/0x005a50a0-0x005a5103.EnsureNormalBulletinSession.md` | UserPane-owned Bulletin creation helper. |
| UID0004UT | `by-memory/0x00613b1c-0x00613ba4.BulletinSessionVtableData.md` | Bulletin compiler data. |
| UID0002BK | `by-memory/0x00490200-0x0049050a.LgInternetSessionLauncherParser.md` | RegistryConfig file-static LG/Channel-i launcher parser. |
| UID00015F | `by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md` | FpsPane diagnostics logging. |
| UID00015I | `by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md` | FpsPane diagnostics logging. |

All 39 support pages already have specialized ownership or an explicit raw/compiler/non-emitting disposition. This audit changes no support metadata, owner, emitter, score, range, or formal source.

### Session-Shaped Redirect Matrix

| Candidate | Exact evidence | Final disposition |
| --- | --- | --- |
| Socket transport | `0x005747e0` constructs Socket from `Application::Startup`, initializes Thread state, publishes `g_packetSender`, and owns transport buffers; `0x00574bb0` has 417 inbound refs and queues send command 8. | Keep Socket; do not rename or facade it as Session. |
| PacketBuffer | Shared scalar/string serialization and cursor helpers with broad callers. | Keep PacketBuffer; it has no lifecycle ownership. |
| PacketTransform | Transform/key helpers and state are separate; Socket owns sequencing/lifetime. | Keep PacketTransform. |
| Thread queue | `0x00596960` enqueues a six-dword request record and releases a semaphore; 22 callers span Socket, FileDownloader, and unrelated workers. | Generic Thread infrastructure. |
| Server selection | `0x005745b0` writes opcode `0x57`, selected server id, endpoint state, and Config/Application fields. | ServerSelectPane/login ownership; no returned/stored Session object. |
| Game dispatch | `0x00507c90` is a 0x1176-byte, 192-block MapPane vtable dispatcher at data xref `0x0061e778`. | MapPane world/UI ownership. |
| Reconnect/terminal | `0x00553e60` and related dialogs consume Socket reset/drain/send/position helpers. | ReconnectDialog/TerminalPane UI ownership. |
| Application/Config/current character | State is distributed through established application/config/login/UI fields; no generic bridge object exists. | Preserve existing owners. |
| ConnStatusPane | Latency/status UI and selected packet events consume network state. | Network UI consumer, not a session owner. |
| FileDownloader/cash shop/MiscWorkThread | Local WinINet handles and HTTP request scopes. | API-handle sessions, not game-session source. |
| ProtocolSend | Feature packet builders remain feature-local; shared serializers and transport already have owners. | Separate reviewed placeholder; no merge with Session. |
| Packet-name debug data | Logging/table support has no generic Session identity or lifecycle. | Socket/protocol-debug support. |
| No-route Thread wrapper | No caller, receiver, message, pointer, or vtable route proves Session ownership. | Retain its independent no-owner disposition. |

### False Lexical Matches

- Raw LG/Channel-i parser `[0x00490200,0x0049050a)` is 778 bytes, SHA256 `78A695ABEB1816DDD01CF2D83B6A76DF1318B45A6B914C6458FC5E0ED63C73B3`, with sixteen leading and six trailing `0xcc` bytes. IDA has no modeled function at the start, and start/end/VA/RVA/raw-pointer scans found no inbound route.
- `WaitForSessionParameter` at `0x00616f38` has exactly one data xref, `0x004902bb`, inside that raw parser. The body recognizes `/lgi`, loads `chigamec.dll`, resolves the vendor export, parses host/IP/port/session strings, and writes RegistryConfig startup fields. It does not define a game-session class or file.
- [UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md) and [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md) use “session” for one diagnostics logging interval under FpsPane.
- WinINet variables named `session` are local API handles in HTTP/application workers. They do not survive as a generic game-session object.

### Generated Output Audit

- Generic `auto-generated/NexusTK/network/Session.cpp`, `Session.h`, `GameSession.cpp`, and `GameSession.h` are absent.
- The only generated filenames containing `Session` are specialized `auto-generated/NexusTK/ui/dialogs/DialogSession.cpp` and `BulletinSession.cpp`.
- Dated validator command `000000024431` snapshot: `DialogSession.cpp` was 1,385 bytes / 49 lines / SHA256 `48417D2B31C4A1589CB0FF04875295E7C69754D1691E22A6E0F19462FF30EA52`; `BulletinSession.cpp` was 5,784 bytes / 167 lines / SHA256 `9C307AE21CA7C6975D10EE39EEA8818285B76427921994A1004140EEDC58CCEC`.
- The same snapshot kept `network/Socket.cpp` at 14,717 bytes / 355 lines / SHA256 `F8221554CF5B837B57F61D7C6387DD4D505B254317AF6D6E84D79E1F385A4F1D` and `Socket.h` at 2,475 bytes / 56 lines / SHA256 `84B0ED0432D77AB219B586E1F8E433039D9BDF5D4927205D502680181C8381CE`.
- `config/RegistryConfig.cpp` contains the LG launcher parser; `ui/diagnostics/FpsPane.cpp` contains the FPS logging methods. Generated references to specialized Session classes or local WinINet session handles are dependencies, not missing UID0000NP fragments.
- Validator-temporary files are transient and confer no canonical source-root evidence.

## Historical 2026-06-16 A001 Review

This review correctly rejected generic promotion but still treated `Session.cpp` as an ordinary future placeholder. Its old raw-parser attribution/range was preliminary and is superseded by the exact `[0x00490200,0x0049050a)` LG/Channel-i RegistryConfig parser evidence above. The historical observations are retained because they explain how the negative boundary developed.

Live IDA MCP session `b001_selflookpane_0001H7_20260616` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64` found no function names matching `Session`. The matching globals are the already documented `DialogSession`, `DialogInSession`, and `BulletinSession` vtable/RTTI objects plus `aWaitforsession`; the matching strings are the same RTTI/type names and one `WaitForSession` literal.

The `WaitForSession` literal at `0x00616f38` has one xref at `0x004902bb`, inside the large command-line/COM helper body `0x0048fca0-0x004901f0`. That function uses `GetCommandLineW`, file/COM/network setup calls, `thrunet.clsURLCHK`, `__loaddll`, and dynamic API lookup style code; this string does not prove a game-session class or source root.

The same pass reconfirmed the positive owners that should not be merged here: `DialogSession` anchors at `0x004a0d80` and `0x004a1400`, `BulletinSession` anchors at `0x00471150`, `0x0047ea90`, and `0x005a50a0`, and the network send/transport anchors at `0x005747e0`, `0x00575e60`, `0x00574bb0`, `0x00576660`, and `0x00596960`. At that date, `by-project-structure/proposed-source-tree.md` still listed `Session.cpp` as a network placeholder pending a caller cluster; the 2026-08-15 exhaustive recheck supersedes that open-ended planning assumption.

## Proven Session-Labeled Ranges

| Range | Owner | Disposition |
| --- | --- | --- |
| [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md) | [UID:0000IU][DialogSession](by-file/DialogSession.md) | Dialog stack/session pane infrastructure. |
| [UID:000132][0x004a0f40-0x004a14a7.BulletinSessionDialogStack](by-memory/0x004a0f40-0x004a14a7.BulletinSessionDialogStack.md) | [UID:0000IU][DialogSession](by-file/DialogSession.md) | Legacy cross-link page for stack helpers; final owner is DialogSession, not generic Session. |
| [UID:0000ZH][0x00471150-0x00471ff1.BulletinSessionCore](by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md) | [UID:0000HX][BulletinSession](by-file/BulletinSession.md) | Board/mail session coordinator. |
| [UID:0001PA][0x0067adc0-0x0067adc4.g_pBulletinSession](by-memory/0x0067adc0-0x0067adc4.g_pBulletinSession.md) | [UID:0000QG][g_pBulletinSession](by-global/g_pBulletinSession.md) | Bulletin/mail singleton storage, not generic network-session storage. |

## Boundary Rules

- Keep `Socket.cpp` as the stateful transport owner.
- Keep feature packet senders with feature modules unless a focused pass proves shared session ownership.
- Keep `ProtocolSend.cpp` as a separate placeholder for possible shared outbound wrappers.
- Do not move `DialogSession`, `DialogInSession`, or `BulletinSession` here; their `Session` naming is UI/social-dialog behavior, not network-session ownership.
- Do not merge Socket, Application, MapPane, Thread, login UI, reconnect UI, diagnostics, RegistryConfig, or HTTP workers. That would cross class, vtable, lifetime, folder, and behavior boundaries.
- Do not create a header-only abstraction, type alias, empty/no-op translation unit, forwarding facade, comments-only emitter, split child, class/global/type page, or synthetic owner for UID0000NP.
- Keep `PROPOSED_RECONSTRUCTION_PATH:"NONE"` and `CANONICAL_OWNER:NONE` unless materially new direct evidence overturns this page.

## Source Placement And Formal C++/Header Disposition

- Exact path: `NONE`; no `network/Session.cpp`, `Session.h`, `GameSession.cpp`, or `GameSession.h`.
- Formal CPP: absent/not applicable because UID0000NP owns no source-authored function, data definition, include-only translation unit, or compiler-covered implementation.
- Formal H: absent/not applicable because no consumer, base, parameter, pointer, enum, global, vtable, RTTI record, or local type requires a generic Session declaration.
- Range/split: no owned VA range exists to split, merge, or cover. Every source-bearing candidate already has an exact page and specialized owner.
- Generated route: no emitter or child route. The by-file page remains documentation-only.

The final reconstructed project should retain ordinary human-written specialized source modules rather than a reverse-engineered architecture facade. This is both behaviorally safer and closer to the likely original source shape.

## Rejected Alternatives

1. **Rename Socket to Session/GameSession:** rejected by direct Socket class identity, Thread inheritance, constructor/lifetime, transport buffers, `g_packetSender`, and coherent generated CPP/H.
2. **Use Application or Config as Session:** rejected because state is distributed through established fields and no generic object bridges startup/login/gameplay.
3. **Treat MapPane as GameSession:** rejected because its receiver, vtable, fields, and handlers are world/UI specific.
4. **Treat Thread/worker queues as Session:** rejected because `0x00596960` is generic infrastructure shared by unrelated workers.
5. **Generalize DialogSession/BulletinSession:** rejected by exact specialized RTTI, layouts, vtables, methods, dialog stacks, and board/mail behavior.
6. **Merge ProtocolSend and Session placeholders:** rejected because feature builders remain feature-local and shared layers already have owners.
7. **Create a header-only interface/facade:** rejected because no binary type, pointer, parameter, base, include consumer, generated declaration, or lifetime route requires it.

## Reopening Criteria

This reviewed negative boundary should reopen only for materially different direct evidence, such as:

- an original PDB, linker map, source archive, build manifest, source path, or source-control record naming `Session.cpp` or `GameSession.cpp`;
- a newly recovered generic class/global/lifetime object that bridges login/server selection, Socket, character identity, and MapPane/game dispatch;
- a coherent method/data cluster not already represented by the 39 specialized support pages.

Another feature caller of existing Socket, PacketBuffer, PacketTransform, Thread, or packet-sender helpers is not enough. The binary cannot prove that a never-linked historical file did not exist, but unverifiable dead source is not a reconstruction target.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 94 | The page now contains the complete binary lexical/type/import inventory, exact specialized function/caller evidence, all 40 Session-named documentation paths, every nonlexical redirect, false-match analysis, generated-output audit, source-tree/no-code/no-header disposition, rejected alternatives, and exact reopening rule. |
| Confidence | 96 | Fresh canonical IDA evidence, current docs, generated output, class/type/lifetime routing, and independent negative checks converge on no generic source unit. Confidence remains below 100 only because stripped source cannot prove that no never-linked historical file existed. |

Reason not higher:

- No PDB, linker map, original source archive, or build manifest survives to prove the exact historical file list.
- The shipped binary cannot prove nonexistence of a dead file that contributed no code/data.
- Some private names in specialized modules remain inferred, but none affects this boundary.

Reason not lower:

- The executable's complete Session lexical surface is enumerated: 3 functions, 37 globals, 40 names, 5 strings, 3 types, and 0 imports.
- All 40 Session-named pages and every plausible session-shaped subsystem have final owners/dispositions.
- The generated tree exactly matches the specialized split and contains no missing generic target fragment.
- The no-source conclusion preserves behavior and plausible original source shape better than an invented facade.

## Cross-References

- [UID:0001QH][client_network](by-meta/client_network.md)
- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0000MV][ProtocolSend](by-file/ProtocolSend.md)
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md)
- [UID:0000M9][PacketTransform](by-file/PacketTransform.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)
- [UID:0000IU][DialogSession](by-file/DialogSession.md)
- [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md)
- [UID:0000HX][BulletinSession](by-file/BulletinSession.md)
- [UID:0000ZH][0x00471150-0x00471ff1.BulletinSessionCore](by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md)
- [UID:0000OR][Thread](by-file/Thread.md)
- [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md)
- [UID:0000OI][TerminalPane](by-file/TerminalPane.md)
- [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md)
- [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md)
- [UID:0000JK][FpsPane](by-file/FpsPane.md)

## Changes

- 2026-08-15 B006 exhaustive whole-file closure:
  - Before: score `86/88`; path/owner `NONE` were directionally correct, but the page remained an open-ended `Session.cpp` planning placeholder.
  - Changed to: score `94/96`; retained path `NONE` and owner `NONE`; converted the page into an exhaustive reviewed negative source boundary.
  - Evidence added: canonical binary identity, complete function/global/name/string/type/import counts, three specialized function/caller dispositions, typed singleton route, zero source-bearing target inventory, literal 40-path documentation inventory, all session-shaped redirects, LG/FpsPane/WinINet false matches, generated generic absence/specialized presence, exact source/no-code/no-header/no-split decision, rejected alternatives, and narrow external/direct-evidence reopening criteria.
  - No formal CPP/H, emitter, split, merge, new child, new UID, support metadata change, or IDA mutation is justified.
  - The earlier Session.cpp placeholder hypothesis remains below as dated historical context and is explicitly superseded.
- 2026-06-16 A001 file/item completion refresh:
  - Before: score `85/86`; `PROPOSED_RECONSTRUCTION_PATH:"NONE"` and `CANONICAL_OWNER:NONE` were already correct.
  - Changed to: score `86/88`; no owner/emitter/path promotion.
  - Evidence: live IDA MCP `entity_query`, `xrefs_to`, `lookup_funcs`, `get_bytes`, and `analyze_function` found no generic `Session` function owner, limited session-named globals/strings to the existing DialogSession/BulletinSession/RTTI evidence plus one `WaitForSession` dynamic-lookup literal, reconfirmed the real UI/social session owners, and reconfirmed the separate Socket/request/Thread transport path. The remaining blocker is real source evidence for a distinct game-session owner, not missing documentation.
- 2026-06-14 A001 non-promotion refresh:
  - Before: score `82/84`; the page had the correct `NONE` path but still used stale recovered-source phrasing and lacked a score rationale for the stronger negative boundary.
  - Changed to: score `85/86`; `PROPOSED_RECONSTRUCTION_PATH:"NONE"` and `CANONICAL_OWNER:NONE` remain unchanged.
  - Summary/evidence: live IDA MCP session `b001_0003gy` reconfirmed the proven session-labeled UI/social roots and the separate Socket/request/Thread network path, while no generic `Session.cpp` owner was identified. The page remains a planning placeholder, not an output root.
- 2026-06-05: Marked the projected reconstruction path as `NONE`.
  - Before: the path was intentionally blank, which left this planning placeholder in file-coverage error state.
  - After: the page is explicitly non-standalone; `network/Session.cpp` remains a planning placeholder and should not emit until a generic game-session owner is proven.
  - Evidence: live IDA MCP `lookup_funcs` confirms the currently proven session-labeled code remains in `DialogSession` at `0x004a0d80` and `BulletinSession` at `0x00471150`, matching the documented non-promotion boundary.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `80` and confidence to `72`.
  - Evidence: document clearly records the placeholder status, proven session-labeled ranges, boundary rules, promotion criteria, and network/session cross-references; confidence stays lower because a distinct original generic `Session.cpp` source unit is not yet proven.
- 2026-06-03: Non-promotion boundary confidence update.
  - Before: the page scored the placeholder as `80/72`, which made the documented negative boundary look less reliable than the supporting network/dialog evidence.
  - After: set completion to `82` and confidence to `84`, with the projected reconstruction path still intentionally out of generated roots.
  - Evidence: [UID:0001QH][client_network](by-meta/client_network.md) records stronger current owners for Socket, packet buffers/transforms, FileDownloader, and request/send queue behavior; [UID:0000IU][DialogSession](by-file/DialogSession.md) and [UID:0000HX][BulletinSession](by-file/BulletinSession.md) own the emitted `Session`-named UI/social modules. No C++ is emitted because no generic game-session source root is proven.
