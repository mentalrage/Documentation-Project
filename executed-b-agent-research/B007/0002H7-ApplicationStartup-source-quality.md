** TARGET-REPORT-UID:0002H7 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B007 Report: [UID:0002H7] ApplicationStartup Source Quality

Report-only research for:

- Target: [UID:0002H7] `by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md`
- Required disposition: report first; no by-* edits until supervisor acceptance callback.
- Agent/session: B007, assignment `B007-report-0002H7-application-startup-source-quality-20260626`.
- Current live target before this report: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:00000D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000D`, blank formal C++.

## Recommendation

Update [UID:0002H7] from `86/90` to `90/91`.

Preserve:

- `CANONICAL_OWNER:00000D` / [UID:00000D] `Application`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00000D`
- Empty `EMITTER_POSITION_OPTIONAL`

Replace the formal `RECONSTRUCTION_CPP CODE` marker/block with the exact formal block supplied in this report. This target is an exact source-authored `Application::Startup` method, has a valid Application owner/emitter route, and is already above the code-entry gate. The earlier blank-C++/no-code recommendation is superseded by the rework pass: unresolved exact original spellings are handled as inferred source-facing names and support-document repair items, not as a reason to omit code.

The formal code below is first-draft source reconstruction, not final original-source proof. It preserves the observed runtime behavior and uses the best current project source-facing names for dependencies. Remaining uncertainty around exact helper/member/slot spellings caps confidence and requires support synchronization, but it does not block target-level code emission.

## MCP Provenance

IDA MCP was available and used. Current read-only availability check:

- MCP endpoint `127.0.0.1:13337` was listening.
- MCP `initialize` returned server `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`.
- MCP `tools/list` returned 65 tools.
- MCP `idb_list` through `tools/call` returned one active session:
  - `session_id:80de0a67`
  - input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
  - `is_active:true`
  - `is_analyzing:false`
  - backend `worker`
  - `pid/worker_pid:26892`
  - last accessed `2026-06-26T06:53:29.002621` on the report rework check
- MCP `server_health` through `tools/call` on `80de0a67` returned:
  - `status:"ok"`
  - module `NexusTK.exe`
  - imagebase `0x400000`
  - `auto_analysis_ready:true`
  - `hexrays_ready:true`
  - `strings_cache_ready:true`
  - strings cache size `2067`

MCP tools used for the target evidence: `lookup_funcs`, `xrefs_to`, `get_bytes`, `callees`, `disasm`, `decompile`, and MCP `int_convert`. Local `tools/int_convert.py` was also run from `E:\NTK\GhidraBridge\source-3\project-documentation` with `--single --text` for the documented numeric conversions below.

Rework pass note: current `tools/list` schema requires `database:'80de0a67'` inside IDB-backed tool arguments. A first retry used a malformed PowerShell variable and returned only `"database is required"` schema errors; the server stayed responsive. The corrected calls with `database:'80de0a67'` returned `server_health` status ok, `lookup_funcs`, `xrefs_to`, `callees`, and `decompile` results matching the original MCP-backed report. No IDA mutation was made.

No IDA DB mutation, rename, type edit, generated file edit, coverage-report edit, validator-state edit, or by-* documentation edit was performed during this report-only pass.

## Current Binary Facts

### Function And Boundary Facts

| Item | Current evidence |
| --- | --- |
| Target function | MCP `lookup_funcs 0x004f5fb0` -> `sub_4F5FB0`, size `0x4e0` / 1248 (Verified with tools/int_convert.py). |
| Predecessor boundary | MCP `lookup_funcs 0x004f5faf` -> not a function. MCP `get_bytes 0x004f5fa8 size 16` returns tail bytes ending `... 8b e5 5d c3 cc 55 8b ec ...`; `0x004f5faf` is one `0xcc` alignment byte before the startup prologue. |
| Successor boundary | MCP `lookup_funcs 0x004f6490` -> `sub_4F6490`, size `0x215`. MCP `get_bytes 0x004f6480 size 32` shows the startup epilogue ending before `0x004f6490`, then the next prologue bytes `56 8b f1 ...`. |
| Direct code route | MCP `xrefs_to 0x004f5fb0` reports exactly two refs: code caller `_WinMain@16` at `0x004f5e78` and data/vtable slot `0x0061d124`. |
| Neighbor route | MCP `xrefs_to 0x004f6490` reports `_WinMain@16` caller at `0x004f5e8e` and vtable slot `0x0061d128`, confirming the following Application shutdown method is separate. |
| Padding exclusion | MCP `xrefs_to 0x004f5faf` reports zero refs. Do not split or document `0x004f5faf` as code. |
| EH cleanup fragments | MCP disassembly lists generated SEH/allocation cleanup fragments at `0x0060103d-0x0060114d`; these are compiler cleanup artifacts for guarded allocations, not source child ranges and not part of the half-open target range. |

### Current Decompile And Callee Shape

MCP `decompile 0x004f5fb0` still returns decompiler-shaped:

- `int __thiscall sub_4F5FB0(HWND *this)`
- many `sub_` callees
- six `unk_69B36x/unk_69B37x` slot globals
- callback vtable name `PlainMemberFunctionObject0<void (__thiscall BaramApp::*)(void),BaramApp>`

The decompiler return type and `HWND *this` are not source-facing. They are artifacts of tail constructor returns and `this[522]` indexing for `Application + 0x828`; the formal block should use `void Application::Startup()`. `_WinMain@16` calls startup then shutdown and ignores any return value, while the decompile's `return result` comes only from constructor-tail propagation in the final branch.

MCP `callees 0x004f5fb0` reports the direct dependencies:

`0x004639d0`, `0x004f4aa0`, `0x004cfe60`, `0x005965e0`, `0x004dec30`, `0x004d1860`, `0x004dcf60`, `0x004dfd10`, `0x004daec0`, `0x004dc690`, `0x004ddf60`, `0x004df7e0`, `operator new`, `0x00595760`, `0x005227d0`, `0x00558840`, `0x00543700`, `0x00558f70`, Win32 `ShowWindow`, `UpdateWindow`, `SetForegroundWindow`, `0x00465bb0`, `0x005573b0`, `0x004f0480`, `0x00556ce0`, `0x004e7f20`, `0x00557440`, `0x004f5710`, `0x00597e90`, `0x004f4a80`, `0x00582460`, `0x004f4c10`, `0x00557430`, and `0x0058af50`.

### Behavior Table

| Address / block | Behavior and source-quality interpretation |
| --- | --- |
| `0x004f5fd7` | Calls [UID:0002H0] `Application::Initialize` / `0x004639d0`; keep Application ownership. |
| `0x004f5fdc-0x004f5ffe` | Allocates `0x100` / 256 bytes (Verified with tools/int_convert.py), then calls `0x004cfe60` with `0x4e20` / 20000 (Verified with tools/int_convert.py). This is IdleWatcher construction; constructor publishes `g_pIdleWatcher`, so startup is caller/creator, not the global storage owner. |
| `0x004f6003-0x004f6010` | Loads `dword_67A7EC`, documented as [UID:0000Q5] `g_packetSender`, and calls `0x005965e0`. Do not call this `g_pCashShopRequest`: support docs explicitly separate `dword_67A7EC` packet sender from `dword_67A738` FileDownloader/download dispatcher. `0x005965e0` is currently documented as `FileDownloader::StartThread`/generic worker-thread start helper with broad callers; the source-facing role in this target should be "start packet/network worker thread through the shared thread-start helper", not Application-local code and not FileDownloader-specific ownership. |
| `0x004f6017-0x004f6139` | Constructs eight image-library singletons: ItemObjImageLib (`0x28` / 40), MapTileImageLib (`0x0c` / 12), StaticObjImageLib (`0x14` / 20), NewHumanImageLib (`0x60` / 96), MonsterImageLib (`0x5c` / 92), RidingImageLib (`0x10` / 16), EffectObjImageLib (`0x60` / 96), and LightObjImageLib (`0x30` / 48). All conversions Verified with tools/int_convert.py. These are dependencies, not source merged into `Application.cpp`. |
| `0x004f613e-0x004f6185` | Allocates `0x04` / 4 and `0x14` / 20 (Verified with tools/int_convert.py), then calls `0x00595760` and `0x005227d0`. Current support resolves these as `new TextFilter` and `new MetaMan`: [UID:00041H] `TextFilter::TextFilter()` publishes `g_pTextFilter`, and [UID:0001C8] covers `MetaMan::MetaMan()` and `g_pMetaMan`. These names are safe for the target formal block. |
| `0x004f618a-0x004f61c9` | Loads [UID:0000S7] `g_pScreenPane` from `dword_67A7CC`, calls `0x00558840`, allocates `0x25c8` / 9672 (Verified with tools/int_convert.py), constructs `PaletteLib` through `0x00543700`, and calls [UID:00039X] `ScreenPaneCursorResourceLoader` / `0x00558f70`. Support docs identify `0x00558840` as Surface/render callback-table initializer territory, `0x00543700` as `PaletteLib::PaletteLib`, and `0x00558f70` as a ScreenPane cursor-resource loader with one startup caller. The target code should use inferred source-facing calls `g_pScreenPane->InitializeSurfacePresentation()`, `new PaletteLib`, and `g_pScreenPane->LoadCursorResources()` while documenting that the exact original spellings remain final-audit caps on the support pages. |
| `0x004f61d0-0x004f61ee` | Calls `ShowWindow`, `UpdateWindow`, and `SetForegroundWindow` on `Application + 0x828` / decimal 2088 (Verified with tools/int_convert.py), currently best field name `m_hMainWnd`. |
| `0x004f61f6` | Calls [UID:0002GW] `Application::DestroyLoadingDialog`, which destroys `Application + 0x82c` / decimal 2092 (Verified with tools/int_convert.py), currently best field name `m_hLoadingDlg`. |
| `0x004f6203` | Calls virtual slot `+0x3c` on `g_pScreenPane` with two zero arguments. Pane vtable support maps this slot to `Pane::SetPaneOrder` / dispatcher order helper, so the target formal block should use `g_pScreenPane->SetPaneOrder(0, 0)` rather than preserving the vtable expression. |
| `0x004f6208` | Calls [UID:0001G7] `0x005573b0`, documented as `ScreenPane::RequestPresentAndTimers` candidate; use `g_pScreenPane->RequestPresentAndTimers()` as the source-facing inferred method name and keep exact spelling as a final-audit cap. |
| `0x004f620f-0x004f632c` | Allocates six `0x08` / 8 byte layer-style objects (Verified with tools/int_convert.py), calls [UID:00018W] Layer constructor `0x004f0480`, and stores into `0x0069b368`, `0x0069b364`, `0x0069b36c`, `0x0069b374`, `0x0069b378`, `0x0069b37c`. The slot addresses were Verified with tools/int_convert.py. Formal code should use `g_mainUiLayerSlots.rootPaneLayerContext`, `effectPaneLayerContext`, `overlayPaneLayerContext`, `layoutPaneLayerContext`, `statusPaneLayerContext`, and `fpsOverlayLayerContext` in that binary store order. `overlayPaneLayerContext` is already used by accepted LogoPane code; the other spellings are inferred/descriptive support repairs. |
| `0x004f6331-0x004f637c` | Registers those six slots through six calls to `0x00556ce0`. Support docs call this a ScreenPane `SetLayerFrame`/layer-registration helper, so the formal target block should call `g_pScreenPane->SetLayerFrame(slot, 0)` for each slot. MainUiLayerSlots exact original spellings and global-vs-object declaration shape remain support-score caps, not blockers for ApplicationStartup C++. |
| `0x004f6386-0x004f639e` | Allocates `0x120` / 288 bytes (Verified with tools/int_convert.py) and calls `0x004e7f20`. The current target's "startup patch/update pane" wording is stale. [UID:0000R7] `g_pIMEPane` support says `0x004e7f20-0x004e7ff5` constructs the root `IMEPane`, publishes `this` at `0x004e7f68`, clears on constructor fallback at `0x004e7f6f`, and has the only direct caller at `0x004f639e` inside Application startup. |
| `0x004f63b0` | Calls `0x00557440`, documented as `ShowCursor(FALSE)` helper, with `g_pScreenPane`. |
| `0x004f63b5` | Calls [UID:00022T] startup-logo Bink playback split index / exact child [UID:0003K6] `PlayStartupLogoBinkFile`. [UID:00022T] is now non-emitting split/index; do not put its children inside Application startup. |
| `0x004f63c0` | Calls [UID:0002KZ] `TimerMgr::RefreshCurrentTick()` / `0x00597e90` through `unk_67AB80`; this exact child now has formal C++, but Application startup only calls it. |
| `0x004f63c7-0x004f63fa` | Allocates `0x18` / 24 bytes (Verified with tools/int_convert.py), calls `0x004f4a80` to initialize the function-object shell, stores `PlainMemberFunctionObject0<BaramApp>` vtable `0x0061d238` (address Verified with tools/int_convert.py), stores target [UID:0002Q0] `0x004f5f50` at slot `+8`, zeros slot `+0x0c`, and captures `this` at slot `+0x10`. The target `0x004f5f50` is BaramApp-owned callback glue. Use inferred source-facing member name `BaramApp::OpenTerminalPaneAfterStartupLogo`; exact original spelling remains a callback support-page cap, not a blocker for the startup method body. |
| `0x004f6401-0x004f643c` | Checks `0x0061d24c` / `NEXON.LGO` (address Verified with tools/int_convert.py) through [UID:0001IZ] `PathExistsViaStat`; if present, allocates `0x354` / 852 bytes (Verified with tools/int_convert.py) and constructs [UID:0002PL] `LogoPane::LogoPane(const wchar_t *, FunctionObject0 *)` with the logo path and completion callback. [UID:0002PL] is now source-ready formal C++, but this target is only the caller/branch owner. |
| `0x004f6452-0x004f647a` | Missing-logo fallback calls `0x00557430` / `ShowCursor(TRUE)`, allocates `0x270` / 624 bytes (Verified with tools/int_convert.py), and calls [UID:0001JB] `TerminalPane::TerminalPane` / `0x0058af50`. TerminalPane implementation remains in TerminalPane support, not Application startup. |

## Current Xref Highlights

MCP `xrefs_to` on current session `80de0a67` confirms:

- `0x004f5fb0`: two refs only, `_WinMain@16` code ref and `0x0061d124` vtable data ref.
- `0x005965e0`: six callers, including startup at `0x004f6010`; this rejects an Application-local interpretation.
- `0x00597e90`: two callers, including startup at `0x004f63c0`; TimerMgr owns the method.
- `0x00582460`: six callers, including startup-logo helper refs and startup at `0x004f640d`; PathUtil owns the helper.
- `0x00558840`: one direct startup caller at `0x004f6199`, but the support docs route the callback-table initializer through Surface/render infrastructure.
- `0x00558f70`: one direct startup caller at `0x004f61c9`; support docs route this to ScreenPane cursor resource loading.
- `0x00543700`: one direct startup caller at `0x004f61bb`; support docs route this to `PaletteLib`.
- `0x004e7f20`: one direct startup caller at `0x004f639e`; support docs route this to IMEPane, correcting stale target wording.
- `0x00556ce0`: ten refs, six from startup slot registration and others from UI graph/ScreenPane contexts; not Application-owned.
- `0x005573b0`: one startup caller at `0x004f6208`; ScreenPane-owned present/timer helper candidate.
- `0x00557430`: eight refs including callback `0x004f5f79` and startup fallback `0x004f6458`; shared cursor-show helper, not startup-private.
- `0x00557440`: five refs including startup `0x004f63b0`; shared cursor-hide helper.
- `0x0061d238`: one startup data xref at `0x004f63e6`; callback wrapper vtable.
- `0x0061d24c`: two startup data xrefs at `0x004f6401` and `0x004f6435`; `NEXON.LGO`.
- UI slot xrefs include startup writes/inits and shutdown releases:
  - `0x0069b364`: startup `0x004f6268` and `0x004f6338`; shutdown refs `0x004f64f3`, `0x004f6584`, `0x004f6594`.
  - `0x0069b368`: broad UI refs; startup store is documented at `0x004f6239` and startup init at `0x004f6331`.
  - `0x0069b36c`: broad UI refs; startup store/init documented at `0x004f6297` and `0x004f634f`.
  - `0x0069b374`: startup `0x004f62c6` and `0x004f6356`; shutdown refs `0x004f64d1`, `0x004f65b8`.
  - `0x0069b378`: startup `0x004f62f5` and `0x004f6365`; shutdown refs `0x004f64c6`, `0x004f6550`, `0x004f6560`.
  - `0x0069b37c`: startup `0x004f632c` and `0x004f6374`; shutdown refs `0x004f6515`, `0x004f6536`, `0x004f6546`.

## Numeric Constants Verified

These constants should be marked in the target as `(Verified with tools/int_convert.py)` if carried over:

| Hex | Decimal | Use |
| --- | ---: | --- |
| `0x4e0` | 1248 | Target function size. |
| `0x100` | 256 | IdleWatcher allocation size. |
| `0x4e20` | 20000 | IdleWatcher interval argument. |
| `0x28` | 40 | ItemObjImageLib allocation. |
| `0x0c` | 12 | MapTileImageLib allocation. |
| `0x14` | 20 | StaticObjImageLib allocation and later setup allocation. |
| `0x60` | 96 | NewHumanImageLib and EffectObjImageLib allocations. |
| `0x5c` | 92 | MonsterImageLib allocation. |
| `0x10` | 16 | RidingImageLib allocation. |
| `0x30` | 48 | LightObjImageLib allocation. |
| `0x04` | 4 | Small post-image-library setup allocation. |
| `0x25c8` | 9672 | Large startup helper/PaletteLib-adjacent allocation before `0x00543700`. |
| `0x828` | 2088 | `Application + 0x828`, `m_hMainWnd`. |
| `0x82c` | 2092 | `Application + 0x82c`, `m_hLoadingDlg`. |
| `0x838` | 2104 | Existing Application field `m_isRunning`; support context, not directly set here. |
| `0x83a` | 2106 | Existing Application field `m_exitRequested`; support context. |
| `0x83c` | 2108 | Existing Application field `m_hShutdownEvent`; support context. |
| `0x844` | 2116 | Existing Application active message handler field support context. |
| `0x08` | 8 | Each Layer-style MainUiLayerSlots allocation. |
| `0x120` | 288 | IMEPane allocation before `0x004e7f20`. |
| `0x18` | 24 | `PlainMemberFunctionObject0<BaramApp>` wrapper allocation. |
| `0x354` | 852 | `LogoPane` allocation. |
| `0x270` | 624 | `TerminalPane` fallback allocation. |
| `0x0061d124` | 6410532 | Startup vtable slot address. |
| `0x0061d238` | 6410808 | `PlainMemberFunctionObject0<BaramApp>` vtable address. |
| `0x0061d24c` | 6410828 | `NEXON.LGO` path literal address. |
| `0x0069b364` | 6927204 | MainUiLayerSlots slot address. |
| `0x0069b368` | 6927208 | MainUiLayerSlots slot address. |
| `0x0069b36c` | 6927212 | MainUiLayerSlots slot address. |
| `0x0069b374` | 6927220 | MainUiLayerSlots slot address. |
| `0x0069b378` | 6927224 | MainUiLayerSlots slot address. |
| `0x0069b37c` | 6927228 | MainUiLayerSlots slot address. |

## Source Placement

The target should remain an `Application` method emitted through [UID:00000D] `Application` and [UID:0000HG] `Application` / `NexusTK/app/Application.cpp`.

Positive owner evidence:

- The only direct code caller is `_WinMain@16`, which invokes the Application virtual/lifecycle method.
- The data route is the Application/BaramApp vtable slot at `0x0061d124`.
- The method's first operation is `Application::Initialize`.
- It uses Application fields at `+0x828` and `+0x82c`.
- Class/file docs already route `Startup` under Application.
- The parent aggregate [UID:00019H] explicitly treats `Application::Startup` and `Application::Shutdown` as exact Application child methods inside a mixed BaramApp/Application startup cluster.

Rejected owners:

- `WinMain`: rejected. `_WinMain@16` is the caller/entry point and vtable dispatch context, not the owner of the startup body.
- `BaramApp`: rejected for the target body. BaramApp owns the callback target [UID:0002Q0], callback vtable data, and logo string resources, but this method executes Application lifecycle work and accesses Application fields. The `PlainMemberFunctionObject0<BaramApp>` wrapper is a dependency inside the method, not ownership proof for the whole method.
- `StartupLogoPanes`: rejected. Startup calls the Bink playback helper and constructs `LogoPane` only through child-owned pages. The startup body is not a startup-logo source unit.
- `LogoPane`: rejected. [UID:0002PL] owns the constructor body; startup only selects and invokes it after checking `NEXON.LGO`.
- `TerminalPane`: rejected. Startup and callback paths call `TerminalPane::TerminalPane`; implementation remains with TerminalPane.
- `MainUiGraph` / `MainUiLayerSlots`: rejected for the method. The six slot globals are created and registered here, but their final declarations and consumer graph belong to MainUiGraph/MainUiLayerSlots.
- `ScreenPane`, `Surface`, `CursorManager`, `PaletteLib`, `IMEPanes`, `TimerMgr`, `PathUtil`, `FileDownloader`, `Socket`: rejected as direct owners. Each owns a called helper, singleton, or storage dependency; none owns the Application startup orchestration body.

## Corrected Stale Assumptions

1. `0x004e7f20` is not a startup patch/update pane constructor.

   Current support page [UID:0000R7] `g_pIMEPane` says `0x004e7f20-0x004e7ff5` constructs the root `IMEPane`; its only direct caller is startup at `0x004f639e`. The target should replace stale "startup patch/update pane" wording with "root IMEPane construction" and link or reference `g_pIMEPane` / `IMEPanes`.

2. `0x005965e0(dword_67A7EC)` should not be documented as FileDownloader-specific state.

   [UID:0000Q5] `g_packetSender` owns `dword_67A7EC`. [UID:0000QH] `g_pCashShopRequest` is a separate `dword_67A738` downloader/request singleton. [UID:0000JC] `by-file/FileDownloader.md` support says `0x005965e0` is currently a `StartThread` helper with broad callers and may ultimately be shared Thread infrastructure. The target can say "starts the packet/network worker through the shared thread-start helper" but should not conflate this with FileDownloader request singleton storage.

3. The old "LogoPane constructor still blocks target code" assumption is stale.

   [UID:0002PL] now carries formal `LogoPane::LogoPane(const wchar_t *logoPath, FunctionObject0 *completionCallback)` C++ and exact caller evidence from startup at `0x004f643c`. This supports a formal startup body that constructs `LogoPane` through the accepted child rather than inlining the constructor. Remaining dependency names are handled as inferred source-facing names and support repairs, not as a reason to keep startup C++ blank.

4. The target's generated tracker rows are stale relative to live by-* metadata.

   `auto-generated/-ag-research-tracker.md` still lists [UID:0002H7] as `76/88` and `auto-generated/-ag-coverage-report-by-memory.md` still lists it as `76%`, while the live source page is `86/90`. Do not manually edit generated files; a callback should update source metadata and run scoped validators / supervisor execute-report lifecycle to refresh generated state.

5. The old "missing exact `0x004e7f20` constructor page blocks code" assumption is stale.

   [UID:0000R7] `g_pIMEPane` already supplies enough direct evidence for this target: allocation size `0x120`, constructor range `0x004e7f20-0x004e7ff5`, publication at `0x004e7f68`, fallback clear at `0x004e7f6f`, and the only direct caller at startup `0x004f639e`. An exact child constructor page could improve IMEPane documentation later, but startup can safely emit `new IMEPane` now.

6. The old "packet sender / StartThread ambiguity blocks startup code" assumption is stale.

   `dword_67A7EC` is accepted `g_packetSender`, not `g_pCashShopRequest` or FileDownloader request state. `0x005965e0` remains a broad shared thread-start helper, but the source-facing target call can be represented as `g_packetSender->StartThread()` while support docs continue to note that the helper may ultimately live in generic thread/socket infrastructure.

## C++ Disposition: Formal First-Draft Target Block

The previous blank-C++/no-code disposition is superseded. [UID:0002H7] covers a complete source-authored method with a direct Application owner/emitter route. The method is not compiler glue, padding, an index page, or behavior wholly covered by another child. The best current reconstruction is to emit `void Application::Startup()` and use inferred source-facing names where original spellings are not recoverable from current evidence.

Why the formal block is safe enough now:

- The decompiler's `int __thiscall sub_4F5FB0(HWND *this)` is an artifact. `_WinMain@16` ignores the call result, and the apparent `return result` comes from constructor-tail returns in the final branch. `void Application::Startup()` matches the source role and existing class/file route.
- `0x00595760` and `0x005227d0` are resolved by support docs as `TextFilter::TextFilter()` and `MetaMan::MetaMan()`.
- `0x004e7f20` is sufficiently resolved by `g_pIMEPane` support as root `IMEPane` construction; the lack of a separate exact constructor page does not block `new IMEPane`.
- `0x005965e0(dword_67A7EC)` is represented as `g_packetSender->StartThread()`: receiver identity is resolved, and the broad helper-owner caveat belongs in support docs.
- `0x00558840`, `0x00558f70`, `0x005573b0`, `0x00557430`, `0x00557440`, and `0x00556ce0` remain exact-spelling caps, but their source-facing roles are sufficiently constrained for first-draft code: ScreenPane surface presentation setup, cursor-resource loading, present/timer request, cursor show/hide, and layer-frame registration.
- MainUiLayerSlots exact original slot spellings remain inferred. The formal block uses descriptive names mapped to the observed binary store order and requires support-doc synchronization rather than raw `unk_69B36x` labels.
- `0x004f5f50` is a BaramApp callback target. Use inferred member name `BaramApp::OpenTerminalPaneAfterStartupLogo`; exact original spelling remains a support-page confidence cap.
- `PathExistsViaStat`, `PlayStartupLogoBinkFile`, `TimerMgr::RefreshCurrentTick`, `LogoPane::LogoPane`, and `TerminalPane::TerminalPane` are already documented enough for caller-level use.

Exact formal target-block replacement content follows. The implementation callback should replace the target's entire formal marker block with this content, including marker lines. Do not insert a Markdown fence into the by-* page.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Application::Startup()
{
    Initialize();

    new IdleWatcher(20000);
    g_packetSender->StartThread();

    new ItemObjImageLib;
    new MapTileImageLib;
    new StaticObjImageLib;
    new NewHumanImageLib;
    new MonsterImageLib;
    new RidingImageLib;
    new EffectObjImageLib;
    new LightObjImageLib;

    new TextFilter;
    new MetaMan;

    g_pScreenPane->InitializeSurfacePresentation();
    new PaletteLib;
    g_pScreenPane->LoadCursorResources();

    ShowWindow(m_hMainWnd, SW_SHOW);
    UpdateWindow(m_hMainWnd);
    SetForegroundWindow(m_hMainWnd);

    DestroyLoadingDialog();
    g_pScreenPane->SetPaneOrder(0, 0);
    g_pScreenPane->RequestPresentAndTimers();

    g_mainUiLayerSlots.rootPaneLayerContext = new Layer;
    g_mainUiLayerSlots.effectPaneLayerContext = new Layer;
    g_mainUiLayerSlots.overlayPaneLayerContext = new Layer;
    g_mainUiLayerSlots.layoutPaneLayerContext = new Layer;
    g_mainUiLayerSlots.statusPaneLayerContext = new Layer;
    g_mainUiLayerSlots.fpsOverlayLayerContext = new Layer;

    g_pScreenPane->SetLayerFrame(g_mainUiLayerSlots.rootPaneLayerContext, 0);
    g_pScreenPane->SetLayerFrame(g_mainUiLayerSlots.effectPaneLayerContext, 0);
    g_pScreenPane->SetLayerFrame(g_mainUiLayerSlots.overlayPaneLayerContext, 0);
    g_pScreenPane->SetLayerFrame(g_mainUiLayerSlots.layoutPaneLayerContext, 0);
    g_pScreenPane->SetLayerFrame(g_mainUiLayerSlots.statusPaneLayerContext, 0);
    g_pScreenPane->SetLayerFrame(g_mainUiLayerSlots.fpsOverlayLayerContext, 0);

    new IMEPane;

    g_pScreenPane->ShowCursor(false);
    PlayStartupLogoBinkFile();
    g_pTimerMgr->RefreshCurrentTick();

    typedef void (__thiscall BaramApp::*BaramAppCallback0)();
    FunctionObject0 *terminalCallback =
        new PlainMemberFunctionObject0<BaramAppCallback0, BaramApp>(
            &BaramApp::OpenTerminalPaneAfterStartupLogo, 0, static_cast<BaramApp *>(this));

    const wchar_t *startupLogoPath = L"NEXON.LGO";
    if (PathExistsViaStat(startupLogoPath)) {
        new LogoPane(startupLogoPath, terminalCallback);
    } else {
        g_pScreenPane->ShowCursor(true);
        new TerminalPane;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

This code intentionally does not inline called helper bodies, constructor bodies, Bink playback logic, LogoPane/TerminalPane internals, TimerMgr internals, or PathUtil internals. It uses the source-facing API shape that an implementation callback should synchronize into support docs. It should not introduce `sub_`, `dword_`, `unk_`, decompiler local names, or raw address-shaped helper names into final C++.

## Positive Evidence Summary

- Current MCP session `80de0a67` confirms the server and IDB are healthy.
- Exact half-open range `0x004f5fb0-0x004f6490` is confirmed by function lookup, predecessor non-function/padding byte, successor `Application::Shutdown`, and byte checks.
- Direct reachability is exactly `_WinMain@16` plus vtable data slot `0x0061d124`.
- Disassembly/decompile agree on startup order: `Application::Initialize`, IdleWatcher, worker/thread start, image libraries, Surface/PaletteLib/cursor resource setup, window activation, loading-dialog teardown, screen present/timer work, six layer slots, IMEPane construction, startup logo playback, TimerMgr refresh, BaramApp callback wrapper, logo path check, LogoPane branch, terminal fallback.
- Current support docs resolve several older raw labels:
  - `dword_67A7EC` -> `g_packetSender`, not `g_pCashShopRequest`.
  - `0x004e7f20` -> IMEPane constructor path, not patch/update pane.
  - `0x00595760` -> `TextFilter::TextFilter()` / `new TextFilter`.
  - `0x005227d0` -> `MetaMan::MetaMan()` / `new MetaMan`.
  - `0x00582460` -> PathExistsViaStat / PathUtil.
  - `0x00597e90` -> `TimerMgr::RefreshCurrentTick()`.
  - `0x004f4c10` -> formal `LogoPane::LogoPane(...)`.
  - `0x00556ce0` -> `ScreenPane::SetLayerFrame`-style layer registration.
  - `0x00557430` / `0x00557440` -> `ShowCursor(TRUE/FALSE)` helpers.
  - `0x005573b0` -> `ScreenPane::RequestPresentAndTimers` candidate, source-facing enough for target code.
  - `0x00558f70` -> ScreenPane cursor-resource loader.
  - `0x00543700` -> PaletteLib construction/singleton publication.
- The formal block removes placeholder leakage by choosing source-facing inferred names for every previously raw label: `InitializeSurfacePresentation`, `LoadCursorResources`, `RequestPresentAndTimers`, `SetLayerFrame`, `ShowCursor(bool)`, `g_mainUiLayerSlots.*LayerContext`, and `BaramApp::OpenTerminalPaneAfterStartupLogo`.
- Existing accepted generated/source docs already use the same callback-template family (`PlainMemberFunctionObject0`) and `FunctionObject0` argument shape for startup-logo panes, so the BaramApp callback wrapper is source-shaped rather than decompiler-shaped.
- Local `tools/int_convert.py` verified the relevant sizes, offsets, and addresses carried in this report.

## Negative Evidence Summary

- No function exists at `0x004f5faf`; it is one `0xcc` byte before the Application startup prologue. Do not split it.
- `0x0060103d-0x0060114d` is compiler-generated SEH/allocation cleanup, not a source child region.
- `_WinMain@16` only calls startup/shutdown and should not absorb the Application body.
- BaramApp owns callback glue and `.rdata` resources but not the Application startup method.
- MainUiLayerSlots owns final slot declarations and naming; Application startup owns construction/registration order only.
- ScreenPane/Surface/PaletteLib/IMEPanes/TimerMgr/PathUtil/FileDownloader/Socket are dependency owners, not the owner of this orchestration method.
- `LogoPane` constructor is source-ready but remains child-owned; the Application startup formal block must call it without absorbing its constructor body.
- No current evidence proves the exact original spelling of every helper/member/slot name. This is negative evidence against a final/high-90s score, not against first-draft formal C++: the report supplies inferred source-facing names and callback-ready support repairs.
- Rejected code alternatives: a decompiler-shaped body using `sub_558840`, `sub_556CE0`, `dword_67A7EC`, and `unk_69B36x`; a body using the decompiler `int __thiscall sub_4F5FB0(HWND *this)` signature; folding LogoPane/TerminalPane/TimerMgr/PathUtil helper bodies into ApplicationStartup; or reassigning the method to WinMain, BaramApp, ScreenPane, Surface, MainUiLayerSlots, FileDownloader, or StartupLogoPanes.

## Support Docs Checked

Required support synchronization if accepted:

- `by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md`
- `by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md`
- `by-class/Application.md`
- `by-file/Application.md`
- `by-memory/0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory.md`
  - Repair the old "member name unresolved blocks ApplicationStartup C++" wording. The page should identify the target as inferred `BaramApp::OpenTerminalPaneAfterStartupLogo`, explain that it restores cursor visibility and constructs `TerminalPane`, and keep exact original spelling as the callback child score cap.
- `by-class/BaramApp.md`
  - Add or update the callback/method row for inferred `OpenTerminalPaneAfterStartupLogo`; record that ApplicationStartup's formal block uses it as the `PlainMemberFunctionObject0<BaramAppCallback0, BaramApp>` target while exact original spelling remains unproven.
- `by-global/MainUiLayerSlots.md`
- `by-memory/0x0069b364-0x0069b370.MainUiLayerSlotsHead.md`
- `by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md`
- `by-memory/0x0069b378-0x0069b380.MainUiLayerSlotsTail.md`
  - Synchronize inferred slot names used by the formal target block:
    - `0x0069b368` -> `rootPaneLayerContext`
    - `0x0069b364` -> `effectPaneLayerContext`
    - `0x0069b36c` -> `overlayPaneLayerContext`
    - `0x0069b374` -> `layoutPaneLayerContext`
    - `0x0069b378` -> `statusPaneLayerContext`
    - `0x0069b37c` -> `fpsOverlayLayerContext`
  - Preserve the caveat that exact original spellings and global-vs-object declaration shape remain unresolved for MainUiLayerSlots itself.
- `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md`
  - Add the ApplicationStartup support mapping that the target formal block uses inferred `g_pScreenPane->InitializeSurfacePresentation()` for this one-caller startup setup, while direct support ownership remains Surface/render/presentation initialization.
- `by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md`
  - Add B007 mapping for `g_pScreenPane->RequestPresentAndTimers()` and paired `g_pScreenPane->ShowCursor(false/true)` use in ApplicationStartup. Keep exact source spelling of the tiny cursor wrappers as a support-page cap.
- `by-memory/0x00558f70-0x005590da.ScreenPaneCursorResourceLoader.md`
  - Ensure the startup call is explicitly source-facing as `g_pScreenPane->LoadCursorResources()` or already-present equal detail; retain cursor-table naming caveats.
- `by-memory/0x00556910-0x00557132.ScreenPane.md`
  - Ensure the `0x00556ce0` row/support wording is source-facing enough for `g_pScreenPane->SetLayerFrame(slot, 0)` in ApplicationStartup, with exact original spelling still inferred.

No-edit-required support pages because they already carry equal-or-greater detail for this target's dependencies:

- `by-file/WinMain.md`: already treats Application methods as called Application children, not WinMain-owned code.
- `by-memory/0x004f5710-0x004f5ac7.StartupLogoBinkPlaybackLoop.md`: already reclassified as non-emitting split/index with exact child pages and sole startup caller at `0x004f63b5`.
- `by-memory/0x004f4c10-0x004f4eac.LogoPaneConstructor.md`: already source-ready formal C++ and records startup caller `0x004f643c`, `NEXON.LGO`, `0x354` allocation, and callback argument.
- `by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md`: already records TerminalPane constructor callers including startup/callback paths; broad aggregate C++ remains blank for its own reasons.
- `by-global/g_pScreenPane.md` and `by-file/CursorManager.md`: already document ScreenPane/cursor ownership at global/file level; specific inferred helper names are synchronized on the by-memory support pages listed above.
- `by-file/FileDownloader.md`, `by-global/g_packetSender.md`, `by-global/g_pCashShopRequest.md`, and `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`: already separate `dword_67A7EC` packet sender from `dword_67A738` downloader/request singleton and document `0x005965e0` as broad StartThread/generic helper caveat.
- `by-memory/0x00595760-0x00595795.TextFilterConstructor.md`: already provides formal `TextFilter::TextFilter()` and the one startup caller at `0x004f615f`.
- `by-memory/0x005227d0-0x00524581.MetaMan.md` and `by-global/g_pMetaMan.md`: already identify `0x005227d0-0x0052285c` as `MetaMan::MetaMan()` and `g_pMetaMan` publication.
- `by-memory/0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick.md`: already source-ready and records startup caller `0x004f63c0`.
- `by-memory/0x00582460-0x00582495.PathExistsViaStat.md`: already attaches helper to PathUtil, records startup caller `0x004f640d`, and keeps C++ blank for dispatch/source-split reasons.
- `by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md`: already proves `0x004e7f20` is root `IMEPane` construction with startup caller `0x004f639e`; the target should cite this but the support page does not need an edit.
- `by-memory/0x0061d234-0x0061d24c.BaramAppCallbackVtableData.md` and `by-memory/0x0061d24c-0x0061d260.BaramAppLogoResourceString.md`: already carry callback vtable / `NEXON.LGO` ownership facts; no edit required for this report.
- `by-memory/0x004639d0-0x00464a52.ApplicationInitialize.md`: already owns the initialization callee; no edit required unless supervisor wants a backward link to this report.

## Score Rationale

Recommended completion `90`:

- Adds current B007 MCP session proof, not just older A002 evidence.
- Corrects stale `0x004e7f20` role to IMEPane construction.
- Clarifies `dword_67A7EC` / `0x005965e0` as packet sender plus broad StartThread helper rather than FileDownloader/request singleton.
- Carries exact current xrefs, boundary bytes, call order, support ownership, and int_convert-verified sizes.
- Replaces the invalid blank-C++ disposition with exact formal `RECONSTRUCTION_CPP CODE` marker/block content for `void Application::Startup()`.
- Resolves the named blockers into either safe target-level source calls (`new TextFilter`, `new MetaMan`, `new IMEPane`, `g_packetSender->StartThread()`, `PathExistsViaStat`, `PlayStartupLogoBinkFile`, `LogoPane`, `TerminalPane`) or implementation-ready support repairs for inferred names (`InitializeSurfacePresentation`, `LoadCursorResources`, `RequestPresentAndTimers`, `SetLayerFrame`, `ShowCursor(bool)`, MainUiLayerSlots fields, `OpenTerminalPaneAfterStartupLogo`).

Not higher than `90`:

- Formal target C++ is first draft rather than final original-source proof.
- Several helper/member names are inferred/descriptive and must be synchronized into support docs rather than proven from original symbols.
- MainUiLayerSlots final slot names and global-vs-object declaration shape remain unresolved for that support family.
- Callback target original member name/header spelling remains inferred as `BaramApp::OpenTerminalPaneAfterStartupLogo`.
- `0x00558840` direct support owner remains Surface/render/presentation infrastructure even though the target code uses a ScreenPane-facing call shape.
- Decompiler signature remains non-source-facing and is explicitly rejected.

Recommended confidence `91`:

- Current MCP evidence is direct and agrees with the Application, BaramApp aggregate, LogoPane, ScreenPane, MainUiLayerSlots, TimerMgr, PathUtil, IMEPane, and FileDownloader/packet-sender support docs.
- Confidence remains below final because exact original source spelling/prototypes are still not recovered for enough dependencies to treat the target as final/audit-clean. Those uncertainties cap score but do not block first-draft target C++.

## Implementation Tracking Checklist

Callback implementation status: complete.  B007 applied the accepted implementation callback details, ran scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation`, and confirmed that no active B007 leases remained after the edit/validator batch.  The original unchecked checklist items below are now checked because each item was either edited, validated, or explicitly verified as no-edit-needed with proof in this section.

### Callback Proof Summary

- [x] Lease proof: B007 leased the immediate edit batch before writing.  After validation, `python tools\leaser\leaser.py B007 unlease ...` returned `Rejected[No active lease]` for the batch because no B007 lease was active by then, and `tools/leaser/Agents/current_leases.md` reported `No active leases.`
- [x] Target metadata proof: `by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md` now has `COMPLETION:90`, `CONFIDENCE:91`, preserves `CANONICAL_OWNER:00000D`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00000D`, and contains the accepted `void Application::Startup()` formal C++ only inside the target `RECONSTRUCTION_CPP CODE` block.
- [x] Generated/manual-edit proof: I did not manually edit `auto-generated/*`, project-level generated files, validator queue/cache/state, IDA DB state, `by-memory/-coverage-report.md`, or any `-coverage-report.md`.  The scoped validators reported `generated_refresh: deferred`; any generated/project/tool-state file changes visible afterward were validator/leaser side effects, not manual edits.

### Validator Proof

All validator commands used this exact form from `E:\NTK\GhidraBridge\source-3\project-documentation`: `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`.

| Edited path | command_id | command_timestamp | exit | ok | generated refresh | warnings/actions proof |
|---|---:|---|---:|---:|---|---|
| `by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md` | `000000002710` | `2026-06-26T14:36:56-04:00` | 0 | 1 | deferred | `completion_update 90`, `confidence_update 91`, `canonical_owner_update 1`, `insert_header_blank 1`, `reference_index_add 5`; no validation failure. |
| `by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md` | `000000002711` | `2026-06-26T14:37:06-04:00` | 0 | 1 | deferred | `completion_update 86`, `confidence_update 90`, `uid_link_insert 2`, `reference_index_add 1`; pre-existing `missing_ref_target 1` for old `0000YR` ApplicationLifecycle path remained non-fatal. |
| `by-class/Application.md` | `000000002712` | `2026-06-26T14:37:07-04:00` | 0 | 1 | deferred | `projected_stats_update 1`; pre-existing `missing_ref_target 7` for old `0002JY`/`0000YR` paths remained non-fatal. |
| `by-file/Application.md` | `000000002713` | `2026-06-26T14:37:09-04:00` | 0 | 1 | deferred | `uid_link_insert 3`, `uid_link_update 1`, `reference_index_add 3`; pre-existing `missing_ref_target 9` and `missing_ref_uid 2` for `0003OY` remained non-fatal. |
| `by-memory/0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory.md` | `000000002714` | `2026-06-26T14:37:19-04:00` | 0 | 1 | deferred | `completion_update 86`, `confidence_update 90`, `uid_link_insert 1`, `reference_index_add 3`; no validation failure. |
| `by-class/BaramApp.md` | `000000002715` | `2026-06-26T14:37:21-04:00` | 0 | 1 | deferred | `completion_update 86`, `reference_index_add 3`; pre-existing `missing_ref_target 1` and `missing_ref_uid 11` remained non-fatal. |
| `by-global/MainUiLayerSlots.md` | `000000002716` | `2026-06-26T14:37:22-04:00` | 0 | 1 | deferred | `uid_link_update 1`, `reference_index_add 4`; no validation failure. |
| `by-memory/0x0069b364-0x0069b370.MainUiLayerSlotsHead.md` | `000000002717` | `2026-06-26T14:37:24-04:00` | 0 | 1 | deferred | `insert_header_blank 1`, `reference_index_add 1`; no validation failure. |
| `by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md` | `000000002718` | `2026-06-26T14:37:27-04:00` | 0 | 1 | deferred | `insert_header_blank 1`, `uid_link_update 1`, `reference_index_add 1`; no validation failure. |
| `by-memory/0x0069b378-0x0069b380.MainUiLayerSlotsTail.md` | `000000002719` | `2026-06-26T14:37:38-04:00` | 0 | 1 | deferred | `insert_header_blank 1`, `uid_link_update 1`, `reference_index_add 1`; no validation failure. |
| `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md` | `000000002720` | `2026-06-26T14:37:48-04:00` | 0 | 1 | deferred | `path_update 1` new UID mapping, `completion_update 86`, `confidence_update 88`, `reference_index_add 8`; absent UID warnings `00039S`/`00039Z` remained non-fatal. |
| `by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md` | `000000002721` | `2026-06-26T14:37:49-04:00` | 0 | 1 | deferred | `completion_update 86`, `confidence_update 90`, `reference_index_add 1`; absent UID warning `0003A3` remained non-fatal. |
| `by-memory/0x00558f70-0x005590da.ScreenPaneCursorResourceLoader.md` | `000000002723` | `2026-06-26T14:37:51-04:00` | 0 | 1 | deferred | `path_update 1` new UID mapping, `completion_update 86`, `confidence_update 89`, `uid_link_update 1`, `reference_index_add 6`; no validation failure. |
| `by-memory/0x00556910-0x00557132.ScreenPane.md` | `000000002724` | `2026-06-26T14:37:52-04:00` | 0 | 1 | deferred | `reference_index_add 8`; absent UID warnings for ScreenPane child refs remained non-fatal. |

### No-Edit Proof

- [x] `by-file/WinMain.md`: no edit required.  Read-only review showed it already keeps WinMain at process entry/message-loop scope and routes lifecycle work to Application-owned children rather than folding `Application::Startup` into WinMain.
- [x] Startup-logo support: no edit required for `by-memory/0x004f5710-0x004f5ac7.StartupLogoBinkPlaybackLoop.md` or `by-memory/0x004f5710-0x004f59c6.PlayStartupLogoBinkFile.md`; both already record the startup caller at `0x004f63b5` and keep logo playback in the StartupLogoPanes route.
- [x] `by-memory/0x004f4c10-0x004f4eac.LogoPaneConstructor.md`: no edit required; it already records the startup caller `0x004f643c`, `NEXON.LGO`, `0x354`, callback argument, and its own first-draft constructor.
- [x] `by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md`: no edit required; it already records `TerminalPane::TerminalPane()` and terminal setup scope, and its aggregate remains blank for its own TerminalPane reasons rather than Application startup.
- [x] Broad ScreenPane/cursor pages outside the edited helpers: no edit required for `by-global/g_pScreenPane.md` and `by-file/CursorManager.md`; they already carry ownership/global context, while the accepted source-facing caller mappings were added to the exact helper pages.
- [x] Packet/download/thread support: no edit required for `by-global/g_packetSender.md`, `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`, `by-global/g_pCashShopRequest.md`, or `by-file/FileDownloader.md`; they already separate `dword_67A7EC` as packet sender from the real cash-shop/download globals and retain the generic thread-helper caveat.
- [x] TextFilter/MetaMan support: no edit required for `by-memory/0x00595760-0x00595795.TextFilterConstructor.md`, `by-memory/0x005227d0-0x00524581.MetaMan.md`, or `by-global/g_pMetaMan.md`; they already document `TextFilter::TextFilter()`, `MetaMan::MetaMan()`, `g_pMetaMan`, and the startup call/use context.
- [x] Path/timer/IME/resource support: no edit required for `by-memory/0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick.md`, `by-memory/0x00582460-0x00582495.PathExistsViaStat.md`, `by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md`, `by-global/g_pIMEPane.md`, `by-memory/0x0061d234-0x0061d24c.BaramAppCallbackVtableData.md`, or `by-memory/0x0061d24c-0x0061d260.BaramAppLogoResourceString.md`; the corrected IMEPane, timer, path check, callback-vtable, and `NEXON.LGO` facts were already present at sufficient detail.
- [x] `by-memory/0x004639d0-0x00464a52.ApplicationInitialize.md`: no edit required; it already owns `Application::Initialize` and records the caller relationship from `[UID:0002H7]`.

- [x] Edit `by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md`.
  - Set `COMPLETION:90`, `CONFIDENCE:91`.
  - Preserve `CANONICAL_OWNER:00000D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000D`, and blank `EMITTER_POSITION_OPTIONAL`.
  - Replace the entire formal `RECONSTRUCTION_CPP CODE` marker/block with the exact formal target-block content from `## C++ Disposition: Formal First-Draft Target Block`, including marker lines. Do not insert the Markdown fence.
  - Replace the stale Item Summary/final-C++ rationale with a source-ready first-draft summary for `void Application::Startup()`, while retaining the no-original-symbol/final-audit caveat.
  - Carry the current B007 MCP session proof: server `ida-pro-mcp` `1.0.0`, session `80de0a67`, active IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, health ok, auto-analysis/Hex-Rays/strings ready.
  - Add current function/boundary table: target `0x004f5fb0-0x004f6490`, `0x4e0` / 1248 (Verified with tools/int_convert.py), no function at `0x004f5faf`, one-byte `0xcc` predecessor padding, successor `0x004f6490` ApplicationShutdown, and generated EH cleanup fragments `0x0060103d-0x0060114d` excluded.
  - Add caller/vtable route: `_WinMain@16` at `0x004f5e78`, vtable slot `0x0061d124`, successor shutdown vtable slot `0x0061d128`.
  - Add current behavior table with address-level call order: ApplicationInitialize, IdleWatcher, `g_packetSender->StartThread()`, eight image-library allocations, `new TextFilter`, `new MetaMan`, `g_pScreenPane->InitializeSurfacePresentation()`, `new PaletteLib`, `g_pScreenPane->LoadCursorResources()`, `m_hMainWnd +0x828`, `DestroyLoadingDialog` / `m_hLoadingDlg +0x82c`, `SetPaneOrder(0, 0)`, `RequestPresentAndTimers()`, six MainUiLayerSlots allocations/registrations, `new IMEPane`, cursor hide, `PlayStartupLogoBinkFile()`, `g_pTimerMgr->RefreshCurrentTick()`, BaramApp callback wrapper, `NEXON.LGO`, LogoPane branch, cursor show, and TerminalPane fallback.
  - Replace stale `0x004f6386-0x004f639e` "startup patch/update pane" wording with root `IMEPane` construction through `0x004e7f20`, citing `g_pIMEPane` support and startup caller `0x004f639e`.
  - Correct `0x005965e0(dword_67A7EC)` wording to packet sender / broad worker-thread start helper; explicitly reject `g_pCashShopRequest` / `dword_67A738` conflation.
  - Add inferred-name policy: `InitializeSurfacePresentation`, `LoadCursorResources`, `RequestPresentAndTimers`, `SetLayerFrame`, `ShowCursor(bool)`, MainUiLayerSlots field names, and `BaramApp::OpenTerminalPaneAfterStartupLogo` are source-facing inferred names selected to avoid placeholder leakage; exact original spelling remains a score cap.
  - Add all constants from this report with `(Verified with tools/int_convert.py)` markings.
  - Add rejected owner/split candidates and negative evidence summary.
  - Add score rationale for `90/91`: formal first-draft code now present, not higher because several support names remain inferred.
  - Add a B007/session `80de0a67` change note.
  - Validator to run after callback edit:
    `python .\tools\validator.py --mode file --file by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md --apply --queue-timeout 240`

- [x] Edit `by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md`.
  - Update the [UID:0002H7] child row/status to `90/91` source-ready formal child C++.
  - Preserve aggregate owner/emitter [UID:0000HG] Application and blank aggregate C++.
  - Add a B007/session `80de0a67` note summarizing current startup function size, caller/vtable route, corrected IMEPane role, packet sender/StartThread correction, TextFilter/MetaMan resolution, MainUiLayerSlots inferred field names, callback wrapper facts, and formal child C++ disposition.
  - Keep existing raw constructor/callback/shutdown/thunk/padding boundaries unchanged.
  - Validator:
    `python .\tools\validator.py --mode file --file by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md --apply --queue-timeout 240`

- [x] Edit `by-class/Application.md`.
  - Expand the [UID:0002H7] `Startup` method row beyond the current one-word entry to summarize current startup orchestration, formal child C++ in the exact by-memory page, and exact child path.
  - Keep broad class C++ blank.
  - Carry field/use facts for `m_hMainWnd +0x828`, `m_hLoadingDlg +0x82c`, and existing support fields `+0x838`, `+0x83a`, `+0x83c`, `+0x844` as context only.
  - Add `void Application::Startup()` signature rationale: decompiler `int __thiscall sub_4F5FB0(HWND *this)` is rejected as constructor-tail and array-index artifact.
  - Add B007/session `80de0a67` change note with corrected IMEPane and packet-sender/StartThread wording plus formal child C++ status.
  - Validator:
    `python .\tools\validator.py --mode file --file by-class/Application.md --apply --queue-timeout 240`

- [x] Edit `by-file/Application.md`.
  - Update the `Startup` responsibilities bullet to current report detail: Application-owned second-stage startup through `NexusTK/app/Application.cpp`, with exact child [UID:0002H7] carrying formal first-draft `Application::Startup` C++.
  - Correct stale or broad wording that implies `InputMan` or FileDownloader request-singleton ownership inside `Startup`; `Initialize` owns InputMan creation, while this startup call reads `g_packetSender` and invokes broad `StartThread`/thread helper `0x005965e0`.
  - Add corrected `0x004e7f20` IMEPane construction note.
  - Preserve `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/"` and broad file-level C++ blank policy.
  - Add B007/session `80de0a67` change note.
  - Validator:
    `python .\tools\validator.py --mode file --file by-file/Application.md --apply --queue-timeout 240`

- [x] Edit `by-memory/0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory.md`.
  - Replace "member name unresolved blocks ApplicationStartup C++" wording with inferred source-facing name `BaramApp::OpenTerminalPaneAfterStartupLogo`.
  - Preserve behavior facts: wrapper allocation `0x18`, vtable `0x0061d238`, target store `0x004f63ec`, captured object slot `+0x10`, ShowCursor(TRUE), terminal allocation `0x270`, and TerminalPane constructor.
  - State exact original spelling remains unproven and caps the callback child score/C++; it does not block ApplicationStartup formal C++.
  - Validator:
    `python .\tools\validator.py --mode file --file by-memory/0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory.md --apply --queue-timeout 240`

- [x] Edit `by-class/BaramApp.md`.
  - Add/update a callback row for inferred `OpenTerminalPaneAfterStartupLogo`, with [UID:0002Q0] `0x004f5f50-0x004f5faf` as the implementation target.
  - Record that [UID:0002H7] builds a `PlainMemberFunctionObject0<BaramAppCallback0, BaramApp>` pointing at this method and captures the live Application/BaramApp object.
  - Keep exact original callback method spelling as inferred/descriptive.
  - Validator:
    `python .\tools\validator.py --mode file --file by-class/BaramApp.md --apply --queue-timeout 240`

- [x] Edit `by-global/MainUiLayerSlots.md`.
  - Add/update inferred field mapping used by ApplicationStartup formal code: `rootPaneLayerContext` (`0x0069b368`), `effectPaneLayerContext` (`0x0069b364`), `overlayPaneLayerContext` (`0x0069b36c`), `layoutPaneLayerContext` (`0x0069b374`), `statusPaneLayerContext` (`0x0069b378`), and `fpsOverlayLayerContext` (`0x0069b37c`).
  - Preserve caveat that exact original field/global declarations remain uncertain for MainUiLayerSlots itself.
  - Validator:
    `python .\tools\validator.py --mode file --file by-global/MainUiLayerSlots.md --apply --queue-timeout 240`

- [x] Edit `by-memory/0x0069b364-0x0069b370.MainUiLayerSlotsHead.md`.
  - Carry the inferred names for `0x0069b364`, `0x0069b368`, and `0x0069b36c` and the startup store/register order from this report.
  - Preserve shutdown release/clear xrefs and global-vs-object caveat.
  - Validator:
    `python .\tools\validator.py --mode file --file by-memory/0x0069b364-0x0069b370.MainUiLayerSlotsHead.md --apply --queue-timeout 240`

- [x] Edit `by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md`.
  - Carry inferred name `layoutPaneLayerContext` for `0x0069b374`; preserve startup/shutdown xrefs and exact-spelling caveat.
  - Validator:
    `python .\tools\validator.py --mode file --file by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md --apply --queue-timeout 240`

- [x] Edit `by-memory/0x0069b378-0x0069b380.MainUiLayerSlotsTail.md`.
  - Carry inferred names `statusPaneLayerContext` (`0x0069b378`) and `fpsOverlayLayerContext` (`0x0069b37c`); preserve startup/shutdown xrefs and exact-spelling caveat.
  - Validator:
    `python .\tools\validator.py --mode file --file by-memory/0x0069b378-0x0069b380.MainUiLayerSlotsTail.md --apply --queue-timeout 240`

- [x] Edit `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md`.
  - Add support mapping that ApplicationStartup formal code uses inferred call `g_pScreenPane->InitializeSurfacePresentation()` for `0x00558840`.
  - Preserve current Surface/render/minimap direct-owner reasoning and one startup caller `0x004f6199`.
  - State exact original helper name/callback-table declaration shape remains a support cap.
  - Validator:
    `python .\tools\validator.py --mode file --file by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md --apply --queue-timeout 240`

- [x] Edit `by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md`.
  - Add B007 mapping that ApplicationStartup formal code uses `g_pScreenPane->RequestPresentAndTimers()`, `g_pScreenPane->ShowCursor(false)`, and `g_pScreenPane->ShowCursor(true)`.
  - Preserve paired wrapper addresses `0x00557440` / FALSE and `0x00557430` / TRUE plus startup/callback caller facts.
  - State exact original tiny-helper spellings remain support caps.
  - Validator:
    `python .\tools\validator.py --mode file --file by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md --apply --queue-timeout 240`

- [x] Edit `by-memory/0x00558f70-0x005590da.ScreenPaneCursorResourceLoader.md` only if it does not already say `g_pScreenPane->LoadCursorResources()` or equivalent source-facing detail.
  - Required if stale: add one startup caller `0x004f61c9`, source-facing inferred call `LoadCursorResources`, and cursor-table naming caveat.
  - If already equal-or-greater detail, record no-edit proof in the report checklist during callback instead.
  - Validator if edited:
    `python .\tools\validator.py --mode file --file by-memory/0x00558f70-0x005590da.ScreenPaneCursorResourceLoader.md --apply --queue-timeout 240`

- [x] Edit `by-memory/0x00556910-0x00557132.ScreenPane.md` only if the `0x00556ce0` row does not already support `g_pScreenPane->SetLayerFrame(slot, 0)` at equal-or-greater detail.
  - Required if stale: add six ApplicationStartup callers `0x004f6331`, `0x004f6340`, `0x004f634f`, `0x004f635e`, `0x004f636d`, `0x004f637c`, and source-facing inferred `SetLayerFrame` wording.
  - If already equal-or-greater detail, record no-edit proof in the report checklist during callback instead.
  - Validator if edited:
    `python .\tools\validator.py --mode file --file by-memory/0x00556910-0x00557132.ScreenPane.md --apply --queue-timeout 240`

- [x] Record no-edit proof for `by-file/WinMain.md`.
  - Proof to record in implementation checklist: it already treats Application startup/shutdown as called Application-owned children and rejects folding them into WinMain.

- [x] Record no-edit proof for startup-logo support unless stale text directly contradicts this report.
  - `by-memory/0x004f5710-0x004f5ac7.StartupLogoBinkPlaybackLoop.md`
  - `by-memory/0x004f5710-0x004f59c6.PlayStartupLogoBinkFile.md`
  - Proof: split/index and exact child already cover startup-logo Bink behavior; ApplicationStartup formal code should call `PlayStartupLogoBinkFile()` and not inline those helpers.

- [x] Record no-edit proof for `by-memory/0x004f4c10-0x004f4eac.LogoPaneConstructor.md`.
  - Proof: already formal first-draft `LogoPane::LogoPane(const wchar_t *logoPath, FunctionObject0 *completionCallback)`, startup caller `0x004f643c`, `NEXON.LGO`, `0x354`, and callback argument.

- [x] Record no-edit proof for `by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md`.
  - Proof: already records TerminalPane constructor callers including startup/callback paths; target only calls it.

- [x] Record no-edit proof for broad ScreenPane/cursor support not edited:
  - `by-global/g_pScreenPane.md`
  - `by-file/CursorManager.md`
  - Proof: broad global/file pages already document ownership; specific helper name repairs are on the by-memory pages above.

- [x] Record no-edit proof for packet/download/thread support:
  - `by-global/g_packetSender.md`
  - `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`
  - `by-global/g_pCashShopRequest.md`
  - `by-file/FileDownloader.md`
  - Proof: already separate `dword_67A7EC` from `dword_67A738`, document alias pollution, and record `0x005965e0` as broad StartThread/generic thread helper caveat; no support edit required unless stale wording is found during callback.

- [x] Record no-edit proof for TextFilter/MetaMan support:
  - `by-memory/0x00595760-0x00595795.TextFilterConstructor.md`
  - `by-memory/0x005227d0-0x00524581.MetaMan.md`
  - `by-global/g_pMetaMan.md`
  - Proof: already resolve the startup calls as `TextFilter::TextFilter()` and `MetaMan::MetaMan()`/`g_pMetaMan`; no further support repair is required for ApplicationStartup.

- [x] Record no-edit proof for path/timer/IME/resource support:
  - `by-memory/0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick.md`
  - `by-memory/0x00582460-0x00582495.PathExistsViaStat.md`
  - `by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md`
  - `by-global/g_pIMEPane.md`
  - `by-memory/0x0061d234-0x0061d24c.BaramAppCallbackVtableData.md`
  - `by-memory/0x0061d24c-0x0061d260.BaramAppLogoResourceString.md`
  - Proof: already document TimerMgr startup caller `0x004f63c0`, PathExists startup caller `0x004f640d`, IMEPane constructor caller `0x004f639e`, callback vtable `0x0061d238`, and `NEXON.LGO` refs `0x004f6401`/`0x004f6435`.

- [x] Record no-edit proof for `by-memory/0x004639d0-0x00464a52.ApplicationInitialize.md`.
  - Proof: already owns `Application::Initialize`; ApplicationStartup formal code should call `Initialize()` and not inline that body.

- [x] Do not edit generated files, project-level files, validator state/cache, IDA DB, `by-memory/-coverage-report.md`, or any `-coverage-report.md`.
  - Generated refresh expectation: update accepted source by-* docs and run scoped validators only; generated `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/-ag-memory-coverage.md` may refresh through validator/supervisor lifecycle and must not be manually patched.

- [x] Release all B007 leases immediately after the implementation callback edit/validator batch and record lease release proof. Implementation callback leases were released/cleared after validation; no active B007 leases remained.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0002H7-ApplicationStartup-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0002H7-ApplicationStartup-source-quality.md","timestamp":"2026-06-26T14:51:53","uid":"0002H7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
