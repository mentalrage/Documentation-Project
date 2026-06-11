*** UID:000016 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BrowserControlPaneOld

## Summary

`BrowserControlPaneOld` is the legacy browser control pane. It combines `ControlPane` and `MSGHandler` behavior, owns or references a COM-style `Browser` object, spawns/uses `BrowserThread`, draws status overlays, and forwards messages to the embedded browser handler.

It is not the same class as the newer [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md). The old pane belongs to the legacy browser dialog path and uses a separate browser-thread/message-forwarding model, but the source owner is still the Browser module because the old and new browser classes share COM helpers, browser private enums, static vtable/string data, and browser-owned globals.

## Likely Original Placement

- Source: [UID:0000HV][Browser](by-file/Browser.md)
- Proposed path: `browser/Browser.cpp`
- Confidence: strong for browser folder, medium for exact file split
- Autogen parent: [UID:0000HV][Browser](by-file/Browser.md). C++ remains blank because the final `MSGHandler` subobject layout, Browser object fields, and old-path source split are not final-source quality.

## Methods

- [UID:00032S][0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor](by-memory/0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor.md) non-deleting destructor body.
- [UID:00032T][0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay](by-memory/0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay.md) `DrawBrowserStatusOverlay`.
- [UID:00032U][0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage](by-memory/0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage.md) `HandleBrowserMessage` plus switch table.
- [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md) constructor.
- [UID:00032X][0x004704f0-0x00470579.BrowserControlPaneOldScalarDeletingDestructorAndAdjustors](by-memory/0x004704f0-0x00470579.BrowserControlPaneOldScalarDeletingDestructorAndAdjustors.md) scalar deleting destructor plus adjustor thunks.
- `0x00470558` and `0x0047056e` adjustor thunks.
- `0x00528de0-0x00528dec` `DispatchToBrowser`.

## Class State And Dependencies

| Item | Role | Evidence/caveat |
| --- | --- | --- |
| Embedded `MSGHandler` subobject | Lets the legacy browser path receive and forward private browser messages. | The generic [UID:0001CN][0x00528d60-0x00528e55.MSGHandler](by-memory/0x00528d60-0x00528e55.MSGHandler.md) page records the nearby infrastructure and constructor/destructor callers; the exact subobject declaration remains a final-header blocker. |
| Embedded/owned `Browser` object | Receives forwarded dispatch calls from `DispatchToBrowser` and owns COM/browser state. | [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md) records Browser allocation, state word `0x0101`, URL copy, and object layout evidence. |
| [UID:0000QE][g_pBrowserThread](by-global/g_pBrowserThread.md) | Legacy browser worker-thread singleton. | Constructor child records BrowserThread allocation/start and global storage; [UID:0000HV][Browser](by-file/Browser.md) keeps the singleton with browser ownership. |
| [UID:0000PT][g_browserControlKeyCallback](by-global/g_browserControlKeyCallback.md) | Stale browser-facing alias for keyboard forwarding through `SendMessageW`. | [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) proves the storage belongs to PlatformApi's wide dispatch table; BrowserControlPaneOld is a consumer only. |
| Browser vtable/static data | Legacy control pane vtables and browser strings. | [UID:0001OB][0x006131b4-0x006139df.BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md) records `0x00613780-0x00613824` as BrowserControlPaneOld vtables with constructor/destructor/scalar-destructor setup xrefs. |
| Browser enum/type pages | Browser private message ids, overlay styles, and init flags. | [UID:0001SL][BrowserMessageId](by-type/by-enum/BrowserMessageId.md), [UID:0001SM][BrowserOverlayStyle](by-type/by-enum/BrowserOverlayStyle.md), and [UID:0001SK][BrowserInitFlags](by-type/by-enum/BrowserInitFlags.md) are driven partly by this class's old-path constructor, overlay, and message handling evidence. |

## Evidence

- Wave3 reports 7 methods, 5 active and 2 disabled adjustor thunks.
- IDA MCP confirms `DrawBrowserStatusOverlay` at `0x0046f220-0x0046f30f` and constructor at `0x0046ff50-0x00470159`.
- IDA MCP shows the constructor is called from `BrowserDialogOld` at `0x0046936e`.
- IDA MCP confirms `DispatchToBrowser` at `0x00528de0-0x00528dec`, called from the legacy message path at `0x0046f36d`.
- `DrawBrowserStatusOverlay`, `HandleBrowserMessage`, and the constructor provide the current evidence for [UID:0001SM][BrowserOverlayStyle](by-type/by-enum/BrowserOverlayStyle.md), [UID:0001SL][BrowserMessageId](by-type/by-enum/BrowserMessageId.md), and [UID:0001SK][BrowserInitFlags](by-type/by-enum/BrowserInitFlags.md).
- [UID:0000HV][Browser](by-file/Browser.md) is scored `86/88`, assigned to `NexusTK/browser/`, and groups the legacy control pane with the browser/OLE helper module.
- [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md) is scored `85/89`, reconstructable, and attached to this class; it records the constructor bounds, phased `MSGHandler`/Browser/BrowserThread construction, Browser allocation/layout evidence, URL copy, BrowserThread allocation/start, and `g_pBrowserThread` storage.
- [UID:0001CO][0x00528de0-0x00528deb.BrowserControlPaneOldDispatch](by-memory/0x00528de0-0x00528deb.BrowserControlPaneOldDispatch.md) is scored `80/88` and records the browser-specific dispatch bridge outside generic `MSGHandler` ownership. Its authoritative half-open range is `0x00528de0-0x00528dec`; the link target retains the stale filename until shared coverage/generated files can be renamed together.
- [UID:0001OB][0x006131b4-0x006139df.BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md) records the `BrowserControlPaneOld` vtable slices at `0x00613780-0x00613824`, with setup xrefs from construction, destruction, and scalar-deleting destructor paths.
- [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) resolves the keyboard-forwarding callback as a `SendMessageW` platform dispatch slot, so the browser page should keep the browser use but not claim storage ownership.
- Current-session note: IDA MCP was unreachable on 2026-06-07, so this pass improves the class summary from existing IDA-backed memory, file, global, and type pages rather than claiming fresh disassembly.
- 2026-06-10 B001-024 live IDA MCP rechecked the old-pane children inside [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md): the raw destructor at `0x0046f1e0-0x0046f216` writes BrowserControlPaneOld vtables and calls `MSGHandler`/base teardown, `DrawBrowserStatusOverlay` at `0x0046f220-0x0046f30f` has vtable ref `0x006137c4`, `HandleBrowserMessage` at `0x0046f310-0x0046f378` plus table bytes through `0x0046f47b` has vtable ref `0x00613828`, and the scalar deleting destructor/adjustors at `0x004704f0-0x00470579` share BrowserControlPaneOld vtable refs and teardown callees.

## Open Questions

- Determine how `MSGHandler` inheritance/subobject ownership is represented in the final header.
- Decide whether this old control pane should remain compiled in the reconstructed source or be isolated as legacy code.
- Rename or coordinated-retarget [UID:0001CO][0x00528de0-0x00528deb.BrowserControlPaneOldDispatch](by-memory/0x00528de0-0x00528deb.BrowserControlPaneOldDispatch.md) to its authoritative `0x00528de0-0x00528dec` half-open range once shared/generated references can be updated safely.
- Verify whether the old-path source lived in `Browser.cpp` beside the newer control pane or in a legacy compatibility section/file inside the browser folder.

## Cross-References

- File: [UID:0000HV][Browser](by-file/Browser.md)
- Related classes: [UID:000018][BrowserDialogOld](by-class/BrowserDialogOld.md), [UID:00001A][BrowserThread](by-class/BrowserThread.md), [UID:000013][Browser](by-class/Browser.md), [UID:00008S][MSGHandler](by-class/MSGHandler.md)
- Globals/enums: [UID:0000QE][g_pBrowserThread](by-global/g_pBrowserThread.md), [UID:0000PT][g_browserControlKeyCallback](by-global/g_browserControlKeyCallback.md), [UID:0001SL][BrowserMessageId](by-type/by-enum/BrowserMessageId.md), [UID:0001SM][BrowserOverlayStyle](by-type/by-enum/BrowserOverlayStyle.md), [UID:0001SK][BrowserInitFlags](by-type/by-enum/BrowserInitFlags.md)
- Memory: [UID:00032S][0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor](by-memory/0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor.md), [UID:00032T][0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay](by-memory/0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay.md), [UID:00032U][0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage](by-memory/0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage.md), [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md), [UID:00032X][0x004704f0-0x00470579.BrowserControlPaneOldScalarDeletingDestructorAndAdjustors](by-memory/0x004704f0-0x00470579.BrowserControlPaneOldScalarDeletingDestructorAndAdjustors.md), [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md), [UID:0001CO][0x00528de0-0x00528deb.BrowserControlPaneOldDispatch](by-memory/0x00528de0-0x00528deb.BrowserControlPaneOldDispatch.md)

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
- 2026-06-06 dispatch-child refresh:
  - Changed to: dispatch method range text updated to `0x00528de0-0x00528dec`, and the [UID:0001CO][0x00528de0-0x00528deb.BrowserControlPaneOldDispatch](by-memory/0x00528de0-0x00528deb.BrowserControlPaneOldDispatch.md) score reference updated to `80/88`.
  - Summary/evidence: live IDA MCP confirms the child body size `0x0c`, single legacy-browser caller at `0x0046f36d`, indirect virtual dispatch through the embedded target object, and `0xcc` padding around the helper. The class score is unchanged because broader final layout/source-shape questions remain open.
- 2026-06-07 class-state refresh:
  - Changed to: `COMPLETION:80` and `CONFIDENCE:84`.
  - Summary/evidence: added class-state/dependency table covering the embedded `MSGHandler` role, Browser object allocation/state, BrowserThread singleton, platform `SendMessageW` dispatch-slot consumer caveat, vtable/static data support, and browser enum/type links. Existing IDA-backed Browser file, constructor child, dispatch child, vtable/string data, platform-dispatch, and type pages support the stronger class ownership picture. C++ remains blank because final `MSGHandler` declaration, old-path source split, and exact Browser field names are still below the reconstruction-code gate.
- 2026-06-07 A004 constructor-child sync:
  - Changed to: constructor child reference updated from `74/88` to `80/88`.
  - Summary/evidence: [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md) now records construction phases, caller/callee evidence, allocation sizes, URL ownership, BrowserThread handoff, and score rationale. The class score is unchanged because broader class layout and source-split questions remain open.
- 2026-06-10 B001-024 exact-child split:
  - Changed to: `COMPLETION:85`, `CONFIDENCE:87`.
  - Summary/evidence: exact child pages now cover the raw non-deleting destructor, status overlay draw method, message handler plus switch table, constructor, and scalar deleting destructor/adjustors with fresh IDA-backed vtable/callee evidence. This raises the class to the strict parent gate for direct child assignments. C++ remains blank because final `MSGHandler` declaration, Browser object field names, and old-path source split are still below final-code quality.
