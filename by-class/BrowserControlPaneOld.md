*** UID:000016 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BrowserControlPaneOld

## Summary

`BrowserControlPaneOld` is the legacy browser control pane. It combines `ControlPane` and `MSGHandler` behavior, owns or references a COM-style `Browser` object, spawns/uses `BrowserThread`, draws status overlays, and forwards messages to the embedded browser handler.

## Likely Original Placement

- Source: [UID:0000HV][Browser](by-file/Browser.md)
- Proposed path: `browser/Browser.cpp`
- Confidence: strong for browser folder, medium for exact file split
- Autogen parent: [UID:0000HV][Browser](by-file/Browser.md). C++ remains blank because the final `MSGHandler` subobject layout, Browser object fields, and old-path source split are not final-source quality.

## Methods

- `0x0046f220` `DrawBrowserStatusOverlay`.
- `0x0046f310` `HandleBrowserMessage`.
- `0x0046ff50` constructor.
- `0x004704f0` scalar deleting destructor.
- `0x00470558` and `0x0047056e` adjustor thunks.
- `0x00528de0` `DispatchToBrowser`.

## Evidence

- Wave3 reports 7 methods, 5 active and 2 disabled adjustor thunks.
- IDA MCP confirms `DrawBrowserStatusOverlay` at `0x0046f220-0x0046f30f` and constructor at `0x0046ff50-0x00470159`.
- IDA MCP shows the constructor is called from `BrowserDialogOld` at `0x0046936e`.
- IDA MCP confirms `DispatchToBrowser` at `0x00528de0-0x00528dec`, called from the legacy message path at `0x0046f36d`.
- `DrawBrowserStatusOverlay`, `HandleBrowserMessage`, and the constructor provide the current evidence for [UID:0001SM][BrowserOverlayStyle](by-type/by-enum/BrowserOverlayStyle.md), [UID:0001SL][BrowserMessageId](by-type/by-enum/BrowserMessageId.md), and [UID:0001SK][BrowserInitFlags](by-type/by-enum/BrowserInitFlags.md).
- [UID:0000HV][Browser](by-file/Browser.md) is scored `84/88`, assigned to `NexusTK/browser/`, and groups the legacy control pane with the browser/OLE helper module.
- [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md) is scored `74/88`, reconstructable, and attached to this class; it records the constructor bounds, `MSGHandler` subobject construction, Browser allocation/layout evidence, URL copy, BrowserThread allocation/start, and `g_pBrowserThread` storage.
- [UID:0001CO][0x00528de0-0x00528deb.BrowserControlPaneOldDispatch](by-memory/0x00528de0-0x00528deb.BrowserControlPaneOldDispatch.md) is scored `70/85` and records the browser-specific dispatch bridge outside generic `MSGHandler` ownership.

## Open Questions

- Determine how `MSGHandler` inheritance/subobject ownership is represented in the final header.
- Decide whether this old control pane should remain compiled in the reconstructed source or be isolated as legacy code.

## Cross-References

- File: [UID:0000HV][Browser](by-file/Browser.md)
- Related classes: [UID:000018][BrowserDialogOld](by-class/BrowserDialogOld.md), [UID:00001A][BrowserThread](by-class/BrowserThread.md), [UID:000013][Browser](by-class/Browser.md), [UID:00008S][MSGHandler](by-class/MSGHandler.md)
- Globals/enums: [UID:0000QE][g_pBrowserThread](by-global/g_pBrowserThread.md), [UID:0000PT][g_browserControlKeyCallback](by-global/g_browserControlKeyCallback.md), [UID:0001SL][BrowserMessageId](by-type/by-enum/BrowserMessageId.md), [UID:0001SM][BrowserOverlayStyle](by-type/by-enum/BrowserOverlayStyle.md), [UID:0001SK][BrowserInitFlags](by-type/by-enum/BrowserInitFlags.md)
- Memory: [UID:0000ZF][0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers.md), [UID:0001CO][0x00528de0-0x00528deb.BrowserControlPaneOldDispatch](by-memory/0x00528de0-0x00528deb.BrowserControlPaneOldDispatch.md)

## Changes

- What existed before: validator autogen metadata did not mark `BrowserControlPaneOld` reconstructable, so confirmed child methods could not attach to the class.
- What it was changed to: `RECONSTRUCTABLE` is now `TRUE`, and the autogen parent is [UID:0000HV][Browser](by-file/Browser.md).
- Summary and evidence: the page already documents IDA-confirmed legacy browser control-pane methods, constructor, dispatch bridge, and browser-thread/global links. The new focused constructor child [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md) requires a reconstructable class parent, and the Browser by-file page/proposed source tree identify `browser/Browser.cpp` as the current browser subsystem source root. No class-level C++ is emitted yet because layout and source shape remain incomplete.

- What existed before: the page had legacy-browser control behavior, methods, and supporting evidence, but completion/confidence metadata remained `0/0`.
- What it was changed to: scores were set to `70/78`.
- Summary and evidence: constructor, draw/message/dispatch paths, BrowserThread links, and enum references are documented; final MSGHandler layout and whether the old path should remain built are still unresolved.
- 2026-06-03 evidence/score refresh:
  - What existed before: the page was already reconstructable and attached to [UID:0000HV][Browser](by-file/Browser.md), but remained in low-both at `70/78`.
  - Changed to: `COMPLETION:74` and `CONFIDENCE:82`.
  - Summary/evidence: the Browser file doc, focused constructor child [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md), dispatch bridge [UID:0001CO][0x00528de0-0x00528deb.BrowserControlPaneOldDispatch](by-memory/0x00528de0-0x00528deb.BrowserControlPaneOldDispatch.md), and browser enum/global pages support stronger source ownership. C++ remains blank because final `MSGHandler` layout, Browser field names, and old-path source split are below the 95+ reconstruction gate.
