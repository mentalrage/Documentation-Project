*** UID:000016 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BrowserControlPaneOld

## Summary

`BrowserControlPaneOld` is the legacy browser control pane. It combines `ControlPane` and `MSGHandler` behavior, owns or references a COM-style `Browser` object, spawns/uses `BrowserThread`, draws status overlays, handles legacy browser private messages, and forwards unhandled messages through its embedded `MSGHandler` subobject to the previously installed application handler.

It is not the same class as the newer [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md). The old pane belongs to the legacy browser dialog path and uses a separate browser-thread/message-forwarding model, but the source owner is still the Browser module because the old and new browser classes share COM helpers, browser private enums, static vtable/string data, and browser-owned globals.

## Likely Original Placement

- Source: [UID:0000HV][Browser](by-file/Browser.md)
- Proposed path: `browser/Browser.cpp`
- Confidence: strong for browser folder, medium for exact file split
- Autogen parent: [UID:0000HV][Browser](by-file/Browser.md). Class-level C++ remains blank because the final header/source split, public helper names, and inherited pane-view spelling are not final-source quality. Method-level source can still emit on exact children where the evidence is complete, such as [UID:00032S][0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor](by-memory/0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor.md), [UID:00032T][0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay](by-memory/0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay.md), [UID:00032U][0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage](by-memory/0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage.md), and source-ready constructor [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md). UID0002P3 is now `90/92` and emits first-draft constructor C++ through support declarations on [UID:000013][Browser](by-class/Browser.md) and [UID:00001A][BrowserThread](by-class/BrowserThread.md).

## Methods

- [UID:00032S][0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor](by-memory/0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor.md) ordinary source-bearing destructor body; emits first-draft empty `BrowserControlPaneOld::~BrowserControlPaneOld()`.
- [UID:00032T][0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay](by-memory/0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay.md) source-ready `DrawBrowserStatusOverlay`; first-draft C++ now emits on the exact child, with remaining caveats limited to Browser `+0x222`/`m_showBrowserAfterLoad` semantics, overlay string id `236`, style/color immediate `128`, and exact inherited bounds spelling, not helper names.
- [UID:00032U][0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage](by-memory/0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage.md) source-facing `DispatchMessage(MSG *message)` old-pane override plus switch table; first-draft C++ is ready on the exact child while the by-memory title remains descriptive.
- [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md) source-ready constructor; first-draft C++ emits on the exact child using `ControlPane(8, bounds)`, `MSGHandler()`, `new Browser(initialUrl)`, `new BrowserThread(browser, *bounds)`, `g_pBrowserThread = thread`, `thread->StartThread()`, and `m_browser = browser`.
- [UID:00032X][0x004704f0-0x00470579.BrowserControlPaneOldScalarDeletingDestructorAndAdjustors](by-memory/0x004704f0-0x00470579.BrowserControlPaneOldScalarDeletingDestructorAndAdjustors.md) no-code MSVC scalar deleting destructor plus adjustor thunks generated from the ordinary destructor.
- `0x00470558` and `0x0047056e` adjustor thunks.
- `0x00528de0-0x00528dec` `BrowserControlPaneOldDispatch` fallback bridge.

## Class Layout Model

Best current source-facing model:

```cpp
class BrowserControlPaneOld : public ControlPane, public MSGHandler
{
    // ControlPane / pane-family base views:
    //   +0x000 primary view
    //   +0x0a0 secondary view
    //   +0x0a4 tertiary view
    //
    // MSGHandler secondary base:
    //   +0x108 vptr
    //   +0x10c MSGHandler::m_previousHandler
    //
    Browser *m_browser; // +0x110
};
```

The complete object size is `0x114`, proven by the guarded/vector-delete path in [UID:00032X][0x004704f0-0x00470579.BrowserControlPaneOldScalarDeletingDestructorAndAdjustors](by-memory/0x004704f0-0x00470579.BrowserControlPaneOldScalarDeletingDestructorAndAdjustors.md). The inherited ControlPane/pane-family secondary view names at `+0xa0` and `+0xa4` are still descriptive, but their existence is supported by constructor/destructor/scalar-wrapper vtable writes and adjustor thunks.

`MSGHandler` is best modeled as secondary-base inheritance, not a composed member. The constructor calls `MSGHandler::MSGHandler` at `this+0x108`, then installs the BrowserControlPaneOld `MSGHandler` secondary-base vtable `0x00613824`; the ordinary destructor restores that same view and calls `MSGHandler::~MSGHandler`; and the scalar wrapper has a `this -= 0x108` deleting adjustor. A composed member could explain constructor/destructor calls, but it does not explain the secondary deleting-destructor adjustor and override vtable as cleanly as inheritance.

Current reconstruction should consume the `MSGHandler` declaration from [UID:0000LM][MSGHandler](by-file/MSGHandler.md) / `app/MSGHandler.cpp`. The inherited base provides `m_previousHandler` at outer `+0x10c`; the Browser object pointer remains separate at outer `+0x110`, and the browser fallback bridge must not be folded into generic `MSGHandler` output.

## Class State And Dependencies

| Item | Role | Evidence/caveat |
| --- | --- | --- |
| `MSGHandler` secondary base | Lets the legacy browser path receive and forward private browser messages. | [UID:00032S][0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor](by-memory/0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor.md), [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md), [UID:00032X][0x004704f0-0x00470579.BrowserControlPaneOldScalarDeletingDestructorAndAdjustors](by-memory/0x004704f0-0x00470579.BrowserControlPaneOldScalarDeletingDestructorAndAdjustors.md), and [UID:0001CO][0x00528de0-0x00528dec.BrowserControlPaneOldDispatch](by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md) resolve the base at outer `+0x108`, with `MSGHandler::m_previousHandler` at outer `+0x10c`. |
| Embedded/owned `Browser` object | Owns/holds a `Browser *` for old-pane UI/thread paths, but does not own Browser's COM method source. | [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md) records Browser allocation, state word `0x0101`, URL copy, and object layout evidence; B001 2026-06-16 IDA evidence and B011 destructor parity place the Browser pointer at outer `+0x110` while the fallback bridge uses the saved handler at outer `+0x10c`. B007 reanalysis keeps [UID:000013][Browser](by-class/Browser.md) as owner of its destructor, QueryInterface, Invoke, Navigate, and COM stubs. B009 UID0002P3 support sync adds `Browser::Browser(const wchar_t *initialUrl)` so the old-pane constructor does not write Browser private fields directly. |
| [UID:0000QE][g_pBrowserThread](by-global/g_pBrowserThread.md) | Legacy browser worker-thread singleton. | Constructor child records BrowserThread allocation/start and global storage; [UID:0000HV][Browser](by-file/Browser.md) keeps the singleton with browser ownership. |
| [UID:0000PT][g_browserControlKeyCallback](by-global/g_browserControlKeyCallback.md) | Stale browser-facing alias for keyboard forwarding through `SendMessageW`. | [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) proves the storage belongs to PlatformApi's wide dispatch table; BrowserControlPaneOld is a consumer only. |
| Browser vtable/static data | Legacy control pane vtables and browser strings. | [UID:0001OB][0x006131b4-0x006139df.BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md) records `0x00613780-0x00613824` as BrowserControlPaneOld vtables with constructor/destructor/scalar-destructor setup xrefs. |
| Browser enum/type pages | Browser private message ids, overlay styles, and init flags. | [UID:0001SL][BrowserMessageId](by-type/by-enum/BrowserMessageId.md), [UID:0001SM][BrowserOverlayStyle](by-type/by-enum/BrowserOverlayStyle.md), and [UID:0001SK][BrowserInitFlags](by-type/by-enum/BrowserInitFlags.md) are driven partly by this class's old-path constructor, overlay, and message handling evidence. |

## Evidence

- Wave3 reports 7 methods, 5 active and 2 disabled adjustor thunks.
- IDA MCP confirms `DrawBrowserStatusOverlay` at `0x0046f220-0x0046f30f` and constructor at `0x0046ff50-0x00470159`.
- IDA MCP shows the constructor is called from `BrowserDialogOld` at `0x0046936e`.
- IDA MCP confirms the `BrowserControlPaneOldDispatch` fallback bridge at `0x00528de0-0x00528dec`, called from the legacy message path at `0x0046f36d`.
- `DrawBrowserStatusOverlay`, source-facing `DispatchMessage(MSG*)` on [UID:00032U][0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage](by-memory/0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage.md), and the constructor provide the current evidence for [UID:0001SM][BrowserOverlayStyle](by-type/by-enum/BrowserOverlayStyle.md), [UID:0001SL][BrowserMessageId](by-type/by-enum/BrowserMessageId.md), and [UID:0001SK][BrowserInitFlags](by-type/by-enum/BrowserInitFlags.md).
- [UID:0000HV][Browser](by-file/Browser.md) is scored `86/88`, assigned to `NexusTK/browser/`, and groups the legacy control pane with the browser/OLE helper module.
- [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md) is scored `90/92`, reconstructable, source-emitting, and attached to this class; it records the constructor bounds, phased `ControlPane`/`MSGHandler`/Browser/BrowserThread construction, Browser allocation/layout evidence, URL copy, BrowserThread allocation/start, `g_pBrowserThread` storage, current MCP negative UDT evidence, null-bounds quirk, and rejected raw/decompiler alternatives.
- [UID:0001CO][0x00528de0-0x00528dec.BrowserControlPaneOldDispatch](by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md) is scored `85/89` and records the old-pane unhandled-message fallback bridge outside generic `MSGHandler` ownership. Its authoritative half-open range is `0x00528de0-0x00528dec`; live IDA shows it forwards through the saved previous handler at the embedded `MSGHandler` subobject slot `+4`, not through the Browser object pointer at outer `+0x110`.
- The B001 older dispatch audit rejects the generated/simroot `DispatchToBrowser` interpretation for [UID:0001CO][0x00528de0-0x00528dec.BrowserControlPaneOldDispatch](by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md): the body is byte-identical to generic `MSGHandler::DispatchMessage`, but `0x00528de0` has no generic MSGHandler vtable reference and no Browser-object caller. For [UID:00032U][0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage](by-memory/0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage.md), the accepted source-facing dependency spelling is `DispatchToPreviousHandler(message)`; UID0001CO itself remains C++ blank until a separate helper-body callback accepts its exact declaration/source shape.
- [UID:0001OB][0x006131b4-0x006139df.BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md) records the `BrowserControlPaneOld` vtable slices at `0x00613780-0x00613824`, with setup xrefs from construction, destruction, and scalar-deleting destructor paths.
- [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) resolves the keyboard-forwarding callback as a `SendMessageW` platform dispatch slot, so the browser page should keep the browser use but not claim storage ownership.
- Current-session note: IDA MCP was unreachable on 2026-06-07, so this pass improves the class summary from existing IDA-backed memory, file, global, and type pages rather than claiming fresh disassembly.
- 2026-06-10 B001-024 live IDA MCP rechecked the old-pane children inside [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md): the raw destructor at `0x0046f1e0-0x0046f216` writes BrowserControlPaneOld vtables and calls `MSGHandler`/base teardown, `DrawBrowserStatusOverlay` at `0x0046f220-0x0046f30f` has vtable ref `0x006137c4`, `HandleBrowserMessage` at `0x0046f310-0x0046f378` plus table bytes through `0x0046f47b` has vtable ref `0x00613828`, and the scalar deleting destructor/adjustors at `0x004704f0-0x00470579` share BrowserControlPaneOld vtable refs and teardown callees.
- 2026-06-21 B011 Rule 26 source-quality reanalysis resolves the previous `MSGHandler` spelling blocker: the old pane inherits `MSGHandler` as a secondary base at `+0x108`; the saved previous handler is `MSGHandler::m_previousHandler` at outer `+0x10c`; `m_browser` remains at `+0x110`; [UID:00032S][0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor](by-memory/0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor.md) is the source-bearing empty ordinary destructor; and [UID:00032X][0x004704f0-0x00470579.BrowserControlPaneOldScalarDeletingDestructorAndAdjustors](by-memory/0x004704f0-0x00470579.BrowserControlPaneOldScalarDeletingDestructorAndAdjustors.md) is no-code compiler deleting-destructor/adjustor glue.
- 2026-07-02 B006 UID00032T implementation callback: [UID:00032T][0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay](by-memory/0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay.md) is now `88/90` and emits first-draft `BrowserControlPaneOld::DrawBrowserStatusOverlay()` on the exact child. Current MCP evidence confirms `0x0046f220` size `0xef`, no direct code callers, vtable data xref `0x006137c4`, `m_browser` at outer `+0x110`, Browser status byte `+0x222`, localized id `236`, text color/style immediate `128`, centered coordinate math, and helper calls through `g_pLanguageMan`/`g_pScreenPane` plus GrafPort text/draw methods. Current `STR.RES` id `236` text is `Please wait for a while...`, but source keeps the localized lookup. Preserve BrowserControlPaneOld as owner/emitter route; `g_pScreenPane`, `g_pLanguageMan`, and GrafPort helpers are dependencies only.

## Open Questions

- Decide whether this old control pane should remain compiled in the reconstructed source or be isolated as legacy code.
- For UID0001CO itself, decide the exact helper-body declaration/source shape if it is later promoted from support dependency to direct source emission; UID00032U currently consumes the accepted inferred dependency spelling `DispatchToPreviousHandler(message)`.
- Verify whether the old-path source lived in `Browser.cpp` beside the newer control pane or in a legacy compatibility section/file inside the browser folder.
- Recover the final names for inherited ControlPane/pane-family secondary views at `+0xa0` and `+0xa4`, and the remaining Browser object fields outside the destructor path.

## Cross-References

- File: [UID:0000HV][Browser](by-file/Browser.md)
- Related classes: [UID:000018][BrowserDialogOld](by-class/BrowserDialogOld.md), [UID:00001A][BrowserThread](by-class/BrowserThread.md), [UID:000013][Browser](by-class/Browser.md), [UID:00008S][MSGHandler](by-class/MSGHandler.md)
- Globals/enums: [UID:0000QE][g_pBrowserThread](by-global/g_pBrowserThread.md), [UID:0000PT][g_browserControlKeyCallback](by-global/g_browserControlKeyCallback.md), [UID:0001SL][BrowserMessageId](by-type/by-enum/BrowserMessageId.md), [UID:0001SM][BrowserOverlayStyle](by-type/by-enum/BrowserOverlayStyle.md), [UID:0001SK][BrowserInitFlags](by-type/by-enum/BrowserInitFlags.md)
- Memory: [UID:00032S][0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor](by-memory/0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor.md), [UID:00032T][0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay](by-memory/0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay.md), [UID:00032U][0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage](by-memory/0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage.md), [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md), [UID:00032X][0x004704f0-0x00470579.BrowserControlPaneOldScalarDeletingDestructorAndAdjustors](by-memory/0x004704f0-0x00470579.BrowserControlPaneOldScalarDeletingDestructorAndAdjustors.md), [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md), [UID:0001CO][0x00528de0-0x00528dec.BrowserControlPaneOldDispatch](by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md)

## Changes

- 2026-07-03 B009 UID0002P3 implementation callback:
  - Score unchanged at `87/89`.
  - Summary/evidence: synchronized [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md) as a source-ready `90/92` child. Current MCP session `b010_00032w_20260703` confirms exact constructor range/size/boundary bytes, sole BrowserDialogOld caller, `ControlPane(8,bounds)`, `MSGHandler()` secondary base at outer `+0x108`, `m_browser` at outer `+0x110`, Browser allocation/layout and URL copy, BrowserThread setup/global handoff/start, no IDA UDT entries, and the null-bounds rectangle-helper quirk. UID0002P3 now emits first-draft constructor C++ through Browser and BrowserThread support declarations; class-level C++ remains blank pending final header/source split and inherited pane-view spelling.
- 2026-07-02 B006 UID00032T implementation callback:
  - Score unchanged at `87/89`.
  - Summary/evidence: synchronized [UID:00032T][0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay](by-memory/0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay.md) as source-ready first draft under the BrowserControlPaneOld route. The accepted method now emits `DrawBrowserStatusOverlay`, with current MCP evidence for exact range, vtable slot, no direct callers, `m_browser` at outer `+0x110`, Browser `+0x222` overlay/show gate, localized id `236`, style/color `128`, centered coordinate math, and source-ready helper names. Broader old-browser source split and exact original constant/field spelling remain support-level caveats.
- 2026-06-29 B002 UID00032U implementation callback:
  - Score unchanged at `87/89`.
  - Summary/evidence: incorporated accepted [UID:00032U][0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage](by-memory/0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage.md) source-facing method spelling as `BrowserControlPaneOld::DispatchMessage(MSG *message)`, with first-draft C++ now emitted on the exact child. The old `HandleBrowserMessage` title remains descriptive; the stale `DispatchToBrowser` helper interpretation remains rejected; `DispatchToPreviousHandler(message)` is the accepted inferred dependency spelling for UID00032U while [UID:0001CO][0x00528de0-0x00528dec.BrowserControlPaneOldDispatch](by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md) stays C++ blank pending a separate helper-body decision. Caveats for inferred helper/member spellings such as `InvalidateRect(0)` and `m_browser->m_hWnd` remain support-level risk, not blockers for the accepted child emission.
- 2026-06-21 B009 MSGHandler source-route sync:
  - Score unchanged at `87/89`.
  - Clarified that the old browser class should use the `MSGHandler` declaration from [UID:0000LM][MSGHandler](by-file/MSGHandler.md), while [UID:0001CO][0x00528de0-0x00528dec.BrowserControlPaneOldDispatch](by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md) remains BrowserControlPaneOld-owned and separate from generic [UID:0001CN][0x00528d60-0x00528e55.MSGHandler](by-memory/0x00528d60-0x00528e55.MSGHandler.md) output.
  - Summary/evidence: B009 rechecked the generic MSGHandler field/signature route, the Application exchange helper, BrowserControlPaneOld constructor/destructor secondary-base layout, and the old browser dispatch bridge. The support data keeps `MSGHandler::m_previousHandler` at outer `+0x10c` and `m_browser` at outer `+0x110`.
- 2026-06-22 Rule 26 B001 older dispatch audit support sync:
  - Score unchanged at `87/89`.
  - Added the explicit rejection of stale generated `DispatchToBrowser`/Browser-object ownership for [UID:0001CO][0x00528de0-0x00528dec.BrowserControlPaneOldDispatch](by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md), while preserving BrowserControlPaneOld ownership and the open final helper-spelling question.

- What existed before: validator autogen metadata did not mark `BrowserControlPaneOld` reconstructable, so confirmed child methods could not attach to the class.
- What it was changed to: `RECONSTRUCTABLE` is now `TRUE`, and the autogen parent is [UID:0000HV][Browser](by-file/Browser.md).
- Summary and evidence: the page already documents IDA-confirmed legacy browser control-pane methods, constructor, dispatch bridge, and browser-thread/global links. The new focused constructor child [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md) requires a reconstructable class parent, and the Browser by-file page/proposed source tree identify `browser/Browser.cpp` as the current browser subsystem source root. No class-level C++ is emitted yet because layout and source shape remain incomplete.

- What existed before: the page had legacy-browser control behavior, methods, and supporting evidence, but completion/confidence metadata remained `0/0`.
- What it was changed to: scores were set to `70/78`.
- Summary and evidence: constructor, draw/message/dispatch paths, BrowserThread links, and enum references are documented; final MSGHandler layout and whether the old path should remain built are still unresolved.
- 2026-06-03 evidence/score refresh:
  - What existed before: the page was already reconstructable and attached to [UID:0000HV][Browser](by-file/Browser.md), but remained in low-both at `70/78`.
  - Changed to: `COMPLETION:74` and `CONFIDENCE:82`.
  - Summary/evidence: the Browser file doc, focused constructor child [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md), dispatch bridge [UID:0001CO][0x00528de0-0x00528dec.BrowserControlPaneOldDispatch](by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md), and browser enum/global pages support stronger source ownership. C++ remains blank because final `MSGHandler` layout, Browser field names, and old-path source split are below the 95+ reconstruction gate.
- 2026-06-06 dispatch-child refresh:
  - Changed to: dispatch method range text updated to `0x00528de0-0x00528dec`, and the [UID:0001CO][0x00528de0-0x00528dec.BrowserControlPaneOldDispatch](by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md) score reference updated to `80/88`.
  - Summary/evidence: live IDA MCP confirms the child body size `0x0c`, single legacy-browser caller at `0x0046f36d`, indirect virtual dispatch through the embedded target object, and `0xcc` padding around the helper. The class score is unchanged because broader final layout/source-shape questions remain open.
- 2026-06-16 B001 dispatch range/semantics sync:
  - Changed to: [UID:0001CO][0x00528de0-0x00528dec.BrowserControlPaneOldDispatch](by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md) score reference updated to `85/89` after the filename/range normalization and saved-previous-handler fallback evidence.
  - Summary/evidence: B001 live IDA MCP evidence separates the generic MSGHandler vtable dispatch at `0x00528dd0` from the BrowserControlPaneOld-only caller path at `0x0046f36d`, and the constructor layout distinguishes the saved handler at subobject slot `+4` from the Browser object pointer at outer `+0x110`.
- 2026-06-07 class-state refresh:
  - Changed to: `COMPLETION:80` and `CONFIDENCE:84`.
  - Summary/evidence: added class-state/dependency table covering the embedded `MSGHandler` role, Browser object allocation/state, BrowserThread singleton, platform `SendMessageW` dispatch-slot consumer caveat, vtable/static data support, and browser enum/type links. Existing IDA-backed Browser file, constructor child, dispatch child, vtable/string data, platform-dispatch, and type pages support the stronger class ownership picture. C++ remains blank because final `MSGHandler` declaration, old-path source split, and exact Browser field names are still below the reconstruction-code gate.
- 2026-06-07 A004 constructor-child sync:
  - Changed to: constructor child reference updated from `74/88` to `80/88`.
  - Summary/evidence: [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md) now records construction phases, caller/callee evidence, allocation sizes, URL ownership, BrowserThread handoff, and score rationale. The class score is unchanged because broader class layout and source-split questions remain open.
- 2026-06-10 B001-024 exact-child split:
  - Changed to: `COMPLETION:85`, `CONFIDENCE:87`.
  - Summary/evidence: exact child pages now cover the raw non-deleting destructor, status overlay draw method, message handler plus switch table, constructor, and scalar deleting destructor/adjustors with fresh IDA-backed vtable/callee evidence. This raises the class to the strict parent gate for direct child assignments. C++ remains blank because final `MSGHandler` declaration, Browser object field names, and old-path source split are still below final-code quality.
- 2026-06-20 B007 Browser class boundary sync:
  - Clarified that BrowserControlPaneOld owns/holds a `Browser *` and dispatches old UI/thread commands, but Browser's COM methods remain on [UID:000013][Browser](by-class/Browser.md), including `Browser::Navigate`, `Browser::Invoke`, QueryInterface, destructor, and stubs.
- 2026-06-21 B011 BrowserControlPaneOld destructor/source-quality sync:
  - Changed to: `COMPLETION:87`, `CONFIDENCE:89`.
  - Summary/evidence: incorporated the [UID:00032S][0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor](by-memory/0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor.md) source-quality result, resolving the `MSGHandler` subobject as a secondary base at `+0x108`, documenting `m_previousHandler` at outer `+0x10c`, preserving `m_browser` at `+0x110`, marking [UID:00032S][0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor](by-memory/0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor.md) as the source-emitting empty destructor, and marking [UID:00032X][0x004704f0-0x00470579.BrowserControlPaneOldScalarDeletingDestructorAndAdjustors](by-memory/0x004704f0-0x00470579.BrowserControlPaneOldScalarDeletingDestructorAndAdjustors.md) as no-code compiler glue.
