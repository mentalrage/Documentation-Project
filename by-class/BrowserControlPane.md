*** UID:000015 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BrowserControlPane

## Summary

`BrowserControlPane` is the newer embedded browser control pane. It wraps an IE/COM browser window, synchronizes browser window bounds with pane layout, draws browser content/backdrop, handles browser dispatch events, and implements COM interface entry points.

The canonical executable aggregate is [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md), with later scalar-delete/adjustor support in [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md).

## Likely Original Placement

- Source: [UID:0000HV][Browser](by-file/Browser.md)
- Proposed path: `browser/Browser.cpp` or `browser/BrowserControlPane.cpp`
- Confidence: strong for the browser module and parent source root, medium for exact one-file versus split-file layout.
- Autogen parent: [UID:0000HV][Browser](by-file/Browser.md). C++ remains blank because final COM interface declarations, helper names, and the promoted/raw child-window handler source shape are still below the reconstruction gate.

## Methods

- `0x0046b520-0x0046b98e` constructor: pane/base setup, browser child window registration/creation, COM object creation, connection-point advise, active global writes, and initial navigation.
- `0x0046b990-0x0046ba32` destructor: browser-control teardown and active global clearing.
- `0x0046ba40-0x0046ba89` child-window redraw helper.
- `0x0046ba90-0x0046bb95` shutdown helper: unadvises, releases browser state, hides/destroys the child `HWND`, and restores focus.
- `0x0046bba0-0x0046bc69` active/cursor state helper.
- `0x0046bc70-0x0046bd30` raw state/property helper island for URL/command/flag fields.
- `0x0046bd30-0x0046be81` navigation helper using `BrowserVariantFromString`.
- `0x0046be90-0x0046bfd0` raw browser-document property helpers.
- `0x0046bfd0-0x0046c247` promoted browser blit helpers.
- `0x0046c250-0x0046c390` raw browser blit helper.
- `0x0046c390-0x0046c549` backdrop update and bounds synchronization.
- `0x0046c550-0x0046c65a` key/accelerator bridge through the active browser-control storage.
- `0x0046c65a-0x0046c670` switch metadata for the key bridge.
- `0x0046c670-0x0046c7bc` `QueryInterface`.
- `0x0046c7c0-0x0046c958` COM client-site/doc-host stubs.
- `0x0046c960-0x0046caf0` browser dispatch event handler.
- `0x0046caf0-0x0046cbc0` dispatch switch metadata.
- `0x0046cbc0-0x0046ccf5` secondary COM/doc-host stubs.
- `0x0046cd00-0x0046ce55` promoted WndProc-like browser child handler.
- `0x0046ce55-0x0046ced0` switch metadata for the promoted handler.
- `0x0046ced0-0x0046cfe0` raw WndProc-like browser child handler.
- [UID:000339][0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor](by-memory/0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor.md) scalar deleting destructor.
- `0x00470fc0-0x004710b7` browser pane/control/window adjustor and delegation thunks, including the `0x00471004-0x00471086` BrowserControlPane-related adjustor group.

## Evidence

- Wave3 reports 23 methods, 21 active and 2 disabled adjustor thunks.
- IDA MCP confirms constructor at `0x0046b520-0x0046b98e` with callers from `BrowserDialog` and other browser setup paths.
- IDA MCP confirms the constructor calls `AdviseConnectionPoint` and `UnadviseConnectionPoint` helpers.
- IDA MCP confirms `BrowserVariantFromString` is called from the navigation method at `0x0046bdb6`.
- IDA MCP confirms `HandleBrowserDispatchEvent` at `0x0046c960-0x0046caef`; that method owns the strongest evidence for [UID:0001SJ][BrowserDispatchEventId](by-type/by-enum/BrowserDispatchEventId.md), [UID:0000PP][g_activeBrowserPane](by-global/g_activeBrowserPane.md), and [UID:0000PU][g_browserRuntime](by-global/g_browserRuntime.md) as a browser consumer.
- IDA MCP confirms the constructor writes [UID:0000PO][g_activeBrowserControlPane](by-global/g_activeBrowserControlPane.md) at `0x0067ab28` and destructor/unwind paths clear it. Application and surface/presentation code read the same storage to route browser accelerators and synchronize/redraw the hosted browser HWND.
- IDA MCP shows `QueryInterface` uses [UID:000218][0x004710e0-0x0047110e.BrowserGuidCompareHelper](by-memory/0x004710e0-0x0047110e.BrowserGuidCompareHelper.md) for 16-byte COM GUID/IID comparisons.
- [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md) is scored `84/90` and attached to [UID:0000HV][Browser](by-file/Browser.md); it records 54 promoted functions in the core range, the missing promoted bodies at `0x0046ba40`, `0x0046bfd0`, and `0x0046c550`, and raw helper islands at `0x0046bc70`, `0x0046be90`, `0x0046c250`, and `0x0046ced0`.
- The same core page records COM stub vtable data refs, GUID constants used by `QueryInterface`, the `0x0046c960` dispatch switch over browser DISPIDs, the `0x0046c550` accelerator bridge, and boundary/switch metadata that should not become standalone source bodies.
- [UID:000339][0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor](by-memory/0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor.md) records the exact B001-024 scalar deleting destructor range, vtable ref `0x0061344c`, adjustor callers at `0x0047027e`/`0x00470289`, active-global clear, base teardown, and delete flag behavior.
- [UID:0000HV][Browser](by-file/Browser.md) is scored `84/88`, assigns the browser subsystem to `NexusTK/browser/`, and lists this class as part of the dense `0x00469290-0x004710b7` browser/OLE cluster.
- [UID:0000PO][g_activeBrowserControlPane](by-global/g_activeBrowserControlPane.md) and [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md) document the active `BrowserControlPane*` slot, constructor writes, destructor/cleanup clears, and application/presentation consumers.
- [UID:0000PP][g_activeBrowserPane](by-global/g_activeBrowserPane.md) documents the active browser-pane callback/owner slot used by the constructor and dispatch-event paths; [UID:0000PU][g_browserRuntime](by-global/g_browserRuntime.md) is explicitly an alias over [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md), not browser-owned storage.

## Touched State And Dependencies

| State or dependency | Evidence | Reconstruction implication |
| --- | --- | --- |
| `0x0067ab28` / [UID:0000PO][g_activeBrowserControlPane](by-global/g_activeBrowserControlPane.md) | Constructor writes at `0x0046b58d`/`0x0046b594`; destructor and scalar-delete paths clear it. | Browser-owned active control pointer, exposed to application/presentation consumers. |
| `0x0067ab84` / [UID:0000PP][g_activeBrowserPane](by-global/g_activeBrowserPane.md) | Constructor writes the browser-pane owner/callback target; dispatch cases read it for close/new-window/document-complete callbacks. | Browser module state, final C++ type still provisional. |
| `0x0067a7cc` / [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) | Dispatch fallback uses the generated `g_browserRuntime` alias. | Do not emit a separate browser-runtime global. |
| Child `HWND` at object offset `+0x11c` | Shutdown, redraw, presentation, and child-window handlers use this hosted-browser window. | Final class layout needs a named child-window field. |
| Browser COM object at object offset `+0x120` | Constructor creates it; shutdown/destructor release it; accelerator bridge queries through it. | Final layout needs an owned browser/COM host pointer. |
| URL/state fields around `+0x12c`, `+0x32c`, `+0x330`, and `+0x331` | Raw helper island records wide URL text plus command/flag fields. | Field names remain provisional until source-level rewrite. |
| Browser dispatch IDs [UID:0001SJ][BrowserDispatchEventId](by-type/by-enum/BrowserDispatchEventId.md) | `HandleBrowserDispatchEvent` handles `104`, `250`, `251`, `252`, `259`, `263`, and `270`. | Constants belong in browser COM/event declarations. |
| Shared helpers `BrowserVariantFromString`, `AdviseConnectionPoint`, and `UnadviseConnectionPoint` | Navigation and constructor/shutdown call the browser-local helper family in [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md). | Keep helper declarations in the browser module, not generic UI controls. |

## Score Rationale

| Field | Rationale |
| --- | --- |
| Completion `85` | The page now mirrors the canonical core aggregate's method-family map, records parent source ownership, adds touched state/dependency evidence, distinguishes source bodies from switch metadata/raw helper islands, and has an exact B001-024 scalar deleting destructor child. Completion remains below final reconstruction because final class layout, COM declarations, and source split are still unresolved. |
| Confidence `87` | Browser ownership is supported by the Browser file, the core memory aggregate, global-storage pages, COM/event enum pages, and the exact scalar deleting destructor/vtable evidence. Confidence stays below the core memory page because final source names/COM slots are still open. |

## Open Questions

- Resolve exact COM interface slots and the `kSlot*InterfaceId` globals before final header work.
- Review whether the old and new control panes were separate original files or one browser source module.
- Name the final class fields for the child `HWND`, browser COM object, active pane owner, URL text, navigation token, command tag, and state flags.
- Resolve the source-level relationship between the promoted `0x0046cd00` child-window handler and raw `0x0046ced0` duplicate-like handler before writing final C++.

## Cross-References

- File: [UID:0000HV][Browser](by-file/Browser.md)
- Related classes: [UID:000017][BrowserDialog](by-class/BrowserDialog.md), [UID:00001B][BrowserWindow](by-class/BrowserWindow.md)
- Globals/enums: [UID:0000T2][DIID_DWebBrowserEvents2](by-global/DIID_DWebBrowserEvents2.md), [UID:0000PP][g_activeBrowserPane](by-global/g_activeBrowserPane.md), [UID:0000PO][g_activeBrowserControlPane](by-global/g_activeBrowserControlPane.md), [UID:0000QD][g_pBrowserOverlayLayer](by-global/g_pBrowserOverlayLayer.md), [UID:0000PU][g_browserRuntime](by-global/g_browserRuntime.md), [UID:0001SJ][BrowserDispatchEventId](by-type/by-enum/BrowserDispatchEventId.md)
- Memory: [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md), [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md), [UID:000218][0x004710e0-0x0047110e.BrowserGuidCompareHelper](by-memory/0x004710e0-0x0047110e.BrowserGuidCompareHelper.md), [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md), [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md), [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md)

## Changes

- 2026-06-10 B001-024 parent-gate repair:
  - Before: `COMPLETION:82`, `CONFIDENCE:86`, with the scalar deleting destructor only listed as an unresolved later range.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:87`, and linked exact child [UID:000339][0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor](by-memory/0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor.md).
  - Summary/evidence: live IDA MCP confirms `sub_470410` at `0x00470410-0x004704ec`, vtable ref `0x0061344c`, adjustor callers `0x0047027e`/`0x00470289`, `g_activeBrowserControlPane` clear, base teardown, and delete flag behavior. This clears the strict `85/85` parent gate for assigning the destructor child.
- 2026-06-07 A005 class consolidation:
  - Before: `COMPLETION:76`, `CONFIDENCE:82`, parent blank, method list missing the current core aggregate's promoted/raw helper coverage, and no class-level state/dependency table.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:86`, `AUTOGEN_PARENT_UID:0000HV`, expanded method-family ranges, touched-state/dependency table, and explicit score rationale.
  - Summary/evidence: [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md) already documents the IDA-backed 54-function core, promoted helper additions, raw islands, COM stubs, dispatch switch, key bridge, and source gate; [UID:0000HV][Browser](by-file/Browser.md) is `84/88` and groups this class in `NexusTK/browser/`; active global pages document the `0x0067ab28`/`0x0067ab84` state. A005 live MCP spot-check attempts timed out three times during this pass, so no new live-IDA-only claims were added.
- What existed before: the page documented the newer browser control pane, method list, evidence, and references, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `76/82`.
- Summary and evidence: constructor/destructor, COM QueryInterface, dispatch event handling, browser-window synchronization, and active-global usage are documented; exact COM slot typing and final source-file split remain incomplete.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE`. Current IDA MCP `lookup_funcs` reconfirmed the constructor/destructor/QueryInterface/dispatch/scalar-deleting starts at `0x0046b520`, `0x0046b990`, `0x0046c670`, `0x0046c960`, and `0x00470410`, and `callers` shows construction from browser dialog/setup paths. At that time `AUTOGEN_PARENT_UID` stayed blank even though [UID:0000HV][Browser](by-file/Browser.md) was the likely owner because the class completion score was still below the 80+ attachment gate.
