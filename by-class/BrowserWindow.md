*** UID:00001B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BrowserWindow

## Summary

`BrowserWindow` is an embedded Internet Explorer ActiveX host. It implements COM client-site and dispatch-style interfaces, creates and manages the hosted browser object, handles reference counting and interface queries, navigates to URLs, and releases the browser object during shutdown.

## Likely Original Placement

- Source: [UID:0000HV][Browser](by-file/Browser.md)
- Proposed path: `browser/Browser.cpp` or `browser/BrowserWindow.cpp`
- Confidence: strong for the browser source root, medium for exact one-file versus split-file layout inside the browser folder.

## Methods

- [UID:0000Z4][0x00469640-0x0046a39c.BrowserWindowCore](by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md) remains the routed source-authored core aggregate, but its formal output is only an explicit no-code/split marker. It must not emit one synthetic body for all of the methods and raw islands below.
- `0x00469640` constructor - creates and wires the embedded browser control.
- `0x00469a20` destructor.
- `0x00469a90` `ShutdownBrowserWindow`.
- `0x00469b60` `SetBrowserActiveState`.
- `0x00469ca0` `NavigateBrowser`.
- `0x00469f60` `QueryInterface`.
- `0x0046a0b0` `AddRef`.
- `0x0046a0c0` `Release`.
- `0x0046a0d0-0x0046a120` IOleClientSite stubs.
- `0x0046a220-0x0046a39c` IDispatch stubs and Invoke behavior.
- `0x0046a3d0-0x0046a505` source-ready `IDocHostUIHandler` and `IDocHostShowUI` callback method bodies, documented by [UID:00020T][0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs](by-memory/0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs.md).
- `0x0046a510-0x0046a617` BrowserWindow-specific accelerator translation helper, source-facing name inferred as `BrowserWindowTranslateAcceleratorMessage(MSG *message)`.
- `0x0046a630-0x0046a6ea` registered BrowserWindow host window procedure, source-facing name inferred as `BrowserWindowHostWndProc`, emitted as a file-static Browser helper unless a future `BrowserWindow.cpp` split is proven.
- `0x0046a760-0x0046a855` non-emitting retained raw WndProc-like clone with no proven caller/registration route; keep documented under Browser routing with blank emitter metadata, but do not treat as the live BrowserWindow WndProc or a second callable callback/method.
- `0x0047102c-0x004710cc` COM interface adjustor thunks, including non-emitting release-adjustor tail thunks at `0x004710b8` and `0x004710c2` generated from the BrowserWindow COM inheritance/base layout.

Future exact source-bearing children should split constructor `0x00469640-0x00469a17`, non-deleting destructor `0x00469a20-0x00469a8a`, shutdown `0x00469a90-0x00469b5c`, active-state `0x00469b60-0x00469c09`, navigation `0x00469ca0-0x00469e17`, `QueryInterface` `0x00469f60-0x0046a0a8`, client-site/dispatch stubs `0x0046a0b0-0x0046a248`, and `Invoke` `0x0046a250-0x0046a39c`. Create those pages only after the BrowserWindow COM declaration, field names, method dependencies, and source-facing names are ready.

## Evidence

- 2026-07-09 B002 UID0000Z4 MCP session `12526619-f80d-472e-8680-44bbfd0aac73` used IDB `supervisor_nexustk_20260709` with `server_health` ok. It reconfirmed 30 promoted functions in the core aggregate, five constructor/destructor-referenced BrowserWindow vtable slices, and exactly five refs to `g_pActiveBrowserWindow` storage.
- The same current pass found no recovered `BrowserWindow`, `IDocHostUIHandler`, `IDocHostShowUI`, or `DWebBrowserEvents2` type rows. It also found no IDA function object and zero xrefs for raw starts `0x00469c10`, `0x00469c30`, `0x00469c70`, `0x00469c80`, `0x00469c90`, `0x00469e20`, and `0x00469ea0`; those islands stay aggregate-documented and non-emitting.
- Generated Browser output previously showed UID0000Z4 only as an empty-emitter marker. The accepted formal no-code/split comment resolves that generic state without duplicating UID00020T DocHost methods, UID00020V host WndProc, UID0002T5 active-global declaration, UID000216 compiler thunks, UID0001SJ event constants, or Browser GUID/vtable/SDK-inline support pages.
- Wave3 reports 25 methods, 22 active and 3 disabled.
- IDA MCP confirms the constructor at `0x00469640-0x00469a17`, with calls to the browser connection-point helpers and navigation setup.
- Historical note: `0x00470dd0-0x00470f10` was previously listed here as late `BrowserWindow::Navigate`. B013 local PE reanalysis rejects that owner/name and reassigns the page to [UID:000013][Browser](by-class/Browser.md) as [UID:00033K][0x00470dd0-0x00470f10.BrowserNavigate](by-memory/0x00470dd0-0x00470f10.BrowserNavigate.md). BrowserWindow's own navigation helper remains `0x00469ca0-0x00469e17` `NavigateBrowser`.
- B007 Rule 26 reanalysis keeps that correction: `BrowserWindow` owns the modern Win32/browser host path and its own `0x00469ca0` `NavigateBrowser`; it does not own the legacy [UID:000013][Browser](by-class/Browser.md) COM client/event-sink methods, `Browser::Invoke`, or [UID:00033K][0x00470dd0-0x00470f10.BrowserNavigate](by-memory/0x00470dd0-0x00470f10.BrowserNavigate.md).
- IDA MCP shows `BrowserVariantFromString`, `AdviseConnectionPoint`, and `UnadviseConnectionPoint` are called from this class.
- Current B010 MCP evidence confirms [UID:000216][0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks](by-memory/0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks.md) is BrowserWindow semantic compiler glue, not handwritten method bodies: `sub_4710B8` and `sub_4710C2` are 0xa-byte adjusted-this tail thunks with deltas `0x10` and `0x0c`, their only direct refs are BrowserWindow vtable slots `0x006132dc` and `0x00613290`, and both tail-jump to canonical `BrowserWindow::Release` at `0x0046a0c0`.
- Generated constructor/destructor evidence tracks [UID:0000Q6][g_pActiveBrowserWindow](by-global/g_pActiveBrowserWindow.md), while `Invoke` shares the browser COM event id family with [UID:0001SJ][BrowserDispatchEventId](by-type/by-enum/BrowserDispatchEventId.md).
- 2026-07-04 B004 UID0002T5 implementation sync, refreshed after the supervisor MCP restart: exact storage [UID:0002T5][0x0067ab94-0x0067ab98.g_pActiveBrowserWindow](by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md) now emits `static BrowserWindow *g_pActiveBrowserWindow;` through by-global [UID:0000Q6][g_pActiveBrowserWindow](by-global/g_pActiveBrowserWindow.md). Current MCP session `ba171fe4` proves zero-filled `unk_67AB94` storage, five constructor/destructor/accelerator/clear-thunk refs, no interior refs, separate successor `0x0067ab98` refs, and no recovered source symbol/UDT. Prior `ddf5b602` proof is historical. This class remains type/lifecycle evidence for the singleton; it is not the direct declaration owner.
- 2026-06-14 live IDA MCP decompilation confirms `0x00613970` / `"Baram.Browser.Window"` is copied into the constructor's local `ClassName` buffer and used for `WNDCLASSA.lpszClassName`, `RegisterClassA`, and the `CreateWindowExA` class-name parameter; the caption/window-name argument is separate.
- 2026-06-07 Batch080 live IDA MCP `py_eval` rechecked key BrowserWindow functions: constructor `0x00469640-0x00469a17`, teardown `0x00469a20-0x00469a8a`, shutdown `0x00469a90-0x00469b5c`, active/cursor helper `0x00469b60-0x00469c09`, navigation helper `0x00469ca0-0x00469e17`, QueryInterface `0x00469f60-0x0046a0a8`, dispatch `Invoke` `0x0046a250-0x0046a39c`, DocHost stub island beginning `0x0046a3d0`, accelerator helper `0x0046a510-0x0046a617`, host WndProc `0x0046a630-0x0046a6ea`, and release-adjustor tail thunks `0x004710b8-0x004710cc`. The same historical pass also listed `0x00470dd0-0x00470f10` as a late navigation helper, but B013 later reowned that routine to Browser after checking caller object identity and body field usage.
- The same MCP pass confirmed five BrowserWindow vtable slices at `0x00613200`, `0x00613228`, `0x00613268`, `0x00613288`, and `0x006132d4`, each referenced from constructor stores around `0x004696b7-0x004696d2` and teardown stores around `0x00469a42-0x00469a5d`.
- 2026-06-08 Batch105 parent/source recheck confirmed [UID:00020T][0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs](by-memory/0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs.md) as a direct BrowserWindow child: all 17 function starts are DocHost/UI-handler vtable stubs, each has one BrowserWindow vtable data xref, `0x0046a505` is not a function start, and the next helper begins at `0x0046a510`.
- 2026-07-07 B005 UID00020T implementation callback resolves the DocHost stub island as source-ready BrowserWindow method bodies. Current MCP session `ef57d27f` confirms server health ok, exact range `0x0046a3d0-0x0046a505`, 17 starts, no function at `0x0046a505`, one BrowserWindow vtable data xref per callback, `0x0046a505-0x0046a510` as eleven `cc` bytes before successor UID00020U, and BrowserWindow constructor stores for the two DocHost views at `0x004696cb` and `0x004696d2`.
- The UID00020T interface-slice proof is now explicit: object offset `+0x0c` uses the `0x00613288` `IDocHostUIHandler`-shaped slice, object offset `+0x10` uses the `0x006132d4` `IDocHostShowUI`-shaped slice, and `QueryInterface` at `0x00469f60` returns those views for `IID_IDocHostUIHandler` (`0x00631630`) and `IID_IDocHostShowUI` (`0x00631640`). `GetHostInfo` uses byte `this+0x15`; `m_enableScrollBars` is only a descriptive first-draft field name until the full BrowserWindow field layout proves original spelling.
- 2026-06-16 B001 source-quality recheck treats [UID:00020U][0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage](by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md) as a file-static BrowserWindow-specific accelerator helper. It reads `g_pActiveBrowserWindow + 0x18`, queries `IID_IOleInPlaceActiveObject`, handles `Ctrl+N` and `Escape`, then forwards to `IOleInPlaceActiveObject::TranslateAccelerator`. No direct caller/table route was found after xref, pointer, WndProc, constructor, vtable-neighborhood, and Application-loop checks; the active Application pump route is the distinct BrowserControlPane helper at `0x0046c550`.
- 2026-06-19 B009 source-quality reanalysis confirms [UID:00020V][0x0046a630-0x0046a6ea.BrowserWindowHostWndProc](by-memory/0x0046a630-0x0046a6ea.BrowserWindowHostWndProc.md) is the registered BrowserWindow host callback: the constructor assigns `0x0046a630` to `WNDCLASSA.lpfnWndProc` at `0x00469758`, and [UID:0000PV][g_browserWindowClassName](by-global/g_browserWindowClassName.md) supplies the `"Baram.Browser.Window"` class-name registration context. B010's 2026-06-28 empty-emitter repair confirms the adjacent raw clone [UID:00020W][0x0046a760-0x0046a855.BrowserRawWindowProcClone](by-memory/0x0046a760-0x0046a855.BrowserRawWindowProcClone.md) remains unregistered/no-xref/no-pointer and is a non-emitting retained duplicate with blank `EMITTER_UIDS:` and blank formal C++.

## Assignment Decision

`CANONICAL_OWNER` and `EMITTER_UIDS` point to [UID:0000HV][Browser](by-file/Browser.md). The child is now `85/88`, and the direct file parent is `86/88`, so both sides clear the corrected `85/85` gate. This is a direct file assignment, not a claim that the original source definitely had no separate `BrowserWindow.cpp`; the parent page explicitly allows either one cohesive `Browser.cpp` or a small browser folder while owning this class cluster.

## Score Rationale

- Completion `85`: class responsibilities, constructor/destructor/shutdown/navigation/QueryInterface/Invoke, stub islands, host WndProc, adjustor thunks, active-browser singleton, vtable slices, and exact memory pages are now documented at class level.
- Confidence `88`: live IDA MCP and exact by-memory pages strongly corroborate the class identity and Browser file ownership. Confidence remains below near-final because COM interface names, field names, and final source split are still provisional.

## Open Questions

- Finalize the full COM interface layout, exact class/header declaration, and field names at `+0x15`, `+0x18`, `+0x1c`, `+0x22`, `+0x24`, `+0x224`, `+0x228`, `+0x229`, and `+0x22a` before creating the UID0000Z4 method children. UID00020T method names and first-draft method bodies are resolved, but the broader BrowserWindow declaration and source spellings remain open.
- Prove caller/table/vtable entry routes before promoting the seven raw UID0000Z4 helper starts; current no-function and zero-xref evidence is a deliberate non-emission result, not an invitation to infer hidden methods.
- Decide whether `BrowserWindow` was separated from the other browser classes or kept in a single `Browser.cpp`.

## Cross-References

- File: [UID:0000HV][Browser](by-file/Browser.md)
- Related classes: [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md), [UID:00001A][BrowserThread](by-class/BrowserThread.md), [UID:000013][Browser](by-class/Browser.md)
- Globals/enums: [UID:0000Q6][g_pActiveBrowserWindow](by-global/g_pActiveBrowserWindow.md), [UID:0000PV][g_browserWindowClassName](by-global/g_browserWindowClassName.md), [UID:0000T2][DIID_DWebBrowserEvents2](by-global/DIID_DWebBrowserEvents2.md), [UID:0001SJ][BrowserDispatchEventId](by-type/by-enum/BrowserDispatchEventId.md)
- Memory: [UID:0000Z4][0x00469640-0x0046a39c.BrowserWindowCore](by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md), [UID:00020T][0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs](by-memory/0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs.md), [UID:00020U][0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage](by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md), [UID:00020V][0x0046a630-0x0046a6ea.BrowserWindowHostWndProc](by-memory/0x0046a630-0x0046a6ea.BrowserWindowHostWndProc.md), [UID:00020W][0x0046a760-0x0046a855.BrowserRawWindowProcClone](by-memory/0x0046a760-0x0046a855.BrowserRawWindowProcClone.md), [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md), [UID:000216][0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks](by-memory/0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks.md), [UID:000218][0x004710e0-0x0047110e.InlineIsEqualGUID](by-memory/0x004710e0-0x0047110e.InlineIsEqualGUID.md)

## Changes

- 2026-07-12 B002 UID0000Z4 implementation callback:
  - Score and Browser owner/emitter route remain `85/88`, owner/emitter `0000HV`.
  - Added the accepted UID0000Z4 formal no-code/split policy, exact future child method ranges, current MCP and raw-helper negative evidence, unresolved COM/field gates, and explicit non-duplication boundaries for existing exact BrowserWindow/Browser support pages.
- 2026-07-07 B005 UID00020T implementation callback:
  - Score unchanged at `85/88`.
  - Summary/evidence: synchronized the class page with accepted source-ready [UID:00020T][0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs](by-memory/0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs.md) details. MCP session `ef57d27f` proves the 17-method BrowserWindow DocHost callback island, one vtable slot xref per method, object offsets `+0x0c` / `+0x10` for `IDocHostUIHandler` / `IDocHostShowUI`, constructor stores at `0x004696cb` / `0x004696d2`, and QueryInterface returns for `IID_IDocHostUIHandler` / `IID_IDocHostShowUI`. The method page now emits first-draft callback bodies while this class page keeps broader header/layout work and the `this+0x15` field spelling caveat open.
- 2026-07-04 B004 UID0002T5 implementation callback:
  - Score unchanged at `85/88`.
  - Summary/evidence: synchronized this class with the accepted active BrowserWindow singleton declaration on exact storage [UID:0002T5][0x0067ab94-0x0067ab98.g_pActiveBrowserWindow](by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md). BrowserWindow constructor/destructor behavior and vtable evidence support the `BrowserWindow *` type, while the direct declaration owner remains by-global [UID:0000Q6][g_pActiveBrowserWindow](by-global/g_pActiveBrowserWindow.md) and Browser source root [UID:0000HV][Browser](by-file/Browser.md).
- Before: the memory cross-reference pointed to `0x00469640-0x0046a39b.BrowserWindowCore`, and the method list stopped the IDispatch/Invoke area at the start of `0x0046a250`.
- Changed to: the memory cross-reference now points to `0x00469640-0x0046a39c.BrowserWindowCore`, and the newly documented `0x0046a3d0-0x0046a855` browser-adjacent method/table cluster is linked from this class page.
- Summary/evidence: IDA MCP confirms `sub_46A250` ends at `0x0046a39c`, `0x0046a3d0-0x0046a505` is referenced by BrowserWindow vtable slices, `0x0046a630` is referenced from the BrowserWindow constructor, and `0x0046a760-0x0046a855` is a raw WndProc-like browser-adjacent body with no current IDA function record.

- Before: the COM adjustor-thunk list stopped at `0x004710ae`, matching the earlier browser/OLE aggregate endpoint.
- Changed to: the adjustor-thunk list now includes `0x004710b8` and `0x004710c2` through [UID:000216][0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks](by-memory/0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks.md).
- Summary/evidence: IDA MCP confirms both thunks are vtable-referenced BrowserWindow interface slices that subtract `0x10` or `0x0c` from the interface pointer and tail-jump to `BrowserWindow::Release` at `0x0046a0c0`.

- What existed before: the page had detailed browser-host evidence and previous range/thunk changes, but metadata still read `0/0`.
- What it was changed to: scores were set to `78/82`.
- Summary and evidence: constructor/destructor, browser object creation, COM interface methods, navigation, host window procedure, adjustor thunks, globals, and memory references are documented; exact COM layout and final source split remain open.
- 2026-06-05: Reclassified metadata from unclassified to `RECONSTRUCTABLE:TRUE`. Current IDA MCP `lookup_funcs` reconfirmed the browser host constructor, destructor, shutdown, navigation, QueryInterface, Release, IDispatch stub, and navigation helper starts at `0x00469640`, `0x00469a20`, `0x00469a90`, `0x00469ca0`, `0x00469f60`, `0x0046a0c0`, `0x0046a220`, and `0x00470dd0`; `callers` shows construction from the startup/browser setup path. Owner/emitter metadata remained blank at that time even though [UID:0000HV][Browser](by-file/Browser.md) was the likely owner because the class completion score was still below the then-active attachment gate.
- 2026-06-07 Batch080 class coverage pass:
  - Changed score from `78/82` to `85/88`.
  - Set owner/emitter metadata to [UID:0000HV][Browser](by-file/Browser.md) because this class and the direct Browser source root both clear the corrected `85/85` gate.
  - Evidence: live IDA MCP rechecked the key function ranges and the five BrowserWindow vtable-slice constructor/teardown refs; exact by-memory pages cover the core aggregate, DocHost stubs, accelerator helper, host WndProc, late navigation helper, and release adjustor thunks.
- 2026-06-08 A006 Batch105 continuation: clarified that [UID:00020T][0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs](by-memory/0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs.md) is directly owned by this class; the score remains `85/88` because COM interface naming and final Browser.cpp versus BrowserWindow.cpp source split are still open.
- 2026-06-14 A001 support sync: updated the browser string global reference from `g_browserWindowCaption` to [UID:0000PV][g_browserWindowClassName](by-global/g_browserWindowClassName.md). Live IDA MCP shows the string is used as the host window class name, not the CreateWindow caption/title.
- 2026-06-16 B001 source-quality sync: updated the accelerator helper entry for [UID:00020U][0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage](by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md) to record the inferred `BrowserWindowTranslateAcceleratorMessage(MSG *message)` name and the researched retained/no-xref route classification.
- 2026-06-19 B009 WndProc source-quality sync: updated the method inventory and evidence so [UID:00020V][0x0046a630-0x0046a6ea.BrowserWindowHostWndProc](by-memory/0x0046a630-0x0046a6ea.BrowserWindowHostWndProc.md) is the registered host callback with first-draft C++ in its target page, while [UID:00020W][0x0046a760-0x0046a855.BrowserRawWindowProcClone](by-memory/0x0046a760-0x0046a855.BrowserRawWindowProcClone.md) remained retained raw/no-code at that time; B010's 2026-06-28 repair below supersedes that old deferred wording with a final non-emitting disposition.
- 2026-06-28 B010 BrowserRawWindowProcClone empty-emitter repair: finalized [UID:00020W][0x0046a760-0x0046a855.BrowserRawWindowProcClone](by-memory/0x0046a760-0x0046a855.BrowserRawWindowProcClone.md) as BrowserWindow-adjacent retained raw code, not a second callable BrowserWindow callback/method. Live MCP session `b009_0001Q4_20260628` found no function/decompile route, xrefs, data-ref/immediate/pointer hits, or registration for `0x0046a760`; [UID:00020V][0x0046a630-0x0046a6ea.BrowserWindowHostWndProc](by-memory/0x0046a630-0x0046a6ea.BrowserWindowHostWndProc.md) remains the only live emitted BrowserWindow host WndProc via `0x00469758/0x0046975e`.
- 2026-07-05 B010 UID000216 implementation callback:
  - Score unchanged at `85/88`.
  - Summary/evidence: synchronized [UID:000216][0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks](by-memory/0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks.md) as BrowserWindow semantic compiler glue rather than handwritten method bodies. Current MCP session `supervisor_recovery_20260705` confirms two 0xa-byte adjusted-this Release tail thunks, vtable-only refs at `0x006132dc` and `0x00613290`, and tail jumps to canonical Release `0x0046a0c0`; source responsibility remains the BrowserWindow COM inheritance/base layout plus canonical Release, with the exact thunk page non-emitting.
- 2026-06-19 B013 support correction:
  - Removed `0x00470dd0` from active BrowserWindow method ownership and kept it as a historical assumption that proved incorrect.
  - Summary/evidence: B013 local PE caller/body reanalysis shows checked callers pass Browser objects (`BrowserThread +0x68`, adjusted Browser interface state, and BrowserControlPaneOld child storage `+0x110`), and the body reads Browser fields `+0x18` and `+0x228`. BrowserWindow keeps the separate `0x00469ca0` `NavigateBrowser` method.
- 2026-06-20 B007 Browser class boundary sync:
  - Reconfirmed BrowserWindow does not own [UID:000013][Browser](by-class/Browser.md) COM methods or [UID:00033K][0x00470dd0-0x00470f10.BrowserNavigate](by-memory/0x00470dd0-0x00470f10.BrowserNavigate.md); BrowserWindow owns the separate modern host/window path and `0x00469ca0` navigation helper.
