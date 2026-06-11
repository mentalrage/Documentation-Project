*** UID:000018 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BrowserDialogOld

## Summary

`BrowserDialogOld` is the legacy web browser dialog with navigation controls and a legacy `BrowserControlPaneOld` child. It handles keyboard close behavior, mouse bounds checks, navigation message posting, child rectangle layout, and dialog bounds state.

## Likely Original Placement

- Source: [UID:0000HV][Browser](by-file/Browser.md)
- Proposed path: `browser/Browser.cpp`
- Confidence: strong for browser folder and legacy dialog class shape, medium for exact file/header split and live old-path reachability.
- Autogen parent: [UID:0000HV][Browser](by-file/Browser.md). C++ is intentionally blank because the old-path source split, exact header placement, and legacy lifetime model are not final-source quality.

## Methods

- `0x00469290-0x00469426` constructor.
- `0x00469430-0x0046949c` destructor.
- `0x00469530-0x004695a9` `OnKeyEvent`.
- `0x004695b0-0x0046961c` `OnMouseEvent`.
- `0x00469620-0x0046963c` `OnNavigateAction`.
- `0x0046b4b0-0x0046b51d` `GetChildRect`.
- [UID:00033B][0x004705e0-0x0047068d.BrowserDialogOldScalarDeletingDestructor](by-memory/0x004705e0-0x0047068d.BrowserDialogOldScalarDeletingDestructor.md) scalar deleting destructor.
- `0x0049dae0-0x0049db14` `SetDialogBounds`.

## Evidence

- Live IDA evidence now anchors the core constructor/destructor/event methods, secondary vtable slots, scalar deleting destructor, adjustor thunks, and far dialog-bounds helper.
- IDA MCP confirms constructor at `0x00469290-0x00469426`.
- IDA MCP shows the constructor calls `BrowserControlPaneOld::BrowserControlPaneOld` at `0x0046ff50`.
- IDA MCP confirms the far `SetDialogBounds` helper at `0x0049dae0-0x0049db14`.
- 2026-06-05 live IDA MCP confirms method ranges: constructor `sub_469290` `0x00469290-0x00469426`, destructor `sub_469430` `0x00469430-0x0046949c`, key handler `sub_469530` `0x00469530-0x004695a9`, mouse handler `sub_4695B0` `0x004695b0-0x0046961c`, navigate handler `sub_469620` `0x00469620-0x0046963c`, child-rect helper `sub_46B4B0` `0x0046b4b0-0x0046b51d`, scalar deleting destructor `sub_4705E0` `0x004705e0-0x0047068d`, and bounds helper `sub_49DAE0` `0x0049dae0-0x0049db14`.
- 2026-06-05 live constructor disassembly shows the legacy singleton lifecycle and vtables: `0x004692ed` stores the constructed object into `dword_67AB90`, the fallback path at `0x004692f4` clears it, `0x004692fe` writes primary vtable `off_613154`, `0x00469304` writes the secondary BrowserDialogOld vtable to `+0xa0`, and `0x0046930e` writes the tertiary vtable to `+0xa4`.
- 2026-06-05 live constructor call scan confirms `0x0046936e call sub_46FF50` constructs the embedded [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md), `0x004693d4 call sub_49DAE0` applies dialog bounds, and `0x00469403 call dword ptr [edx+10h]` dispatches through the child at `[esi+0x1fc]`.
- 2026-06-05 live destructor disassembly shows `0x0046945a` restores the primary vtable, `0x00469477 call sub_49E210` tears down dialog/control state, and `0x00469484` clears `dword_67AB90`.
- 2026-06-05 live xrefs show constructor and destructor have no direct xrefs, while virtual handlers are referenced through vtable data only: mouse handler from `0x006131b8`, key handler from `0x006131bc`, navigate handler from `0x006131e8`, and scalar deleting destructor from `0x00613154` plus two adjustor jumps at `0x004702aa` and `0x004702b5`.
- 2026-06-05 live xrefs show `GetChildRect` is still reached by the shared browser pane/dialog path at `0x0046ab1d` and `0x0046ab5f`; `SetDialogBounds` is shared, with BrowserDialogOld's constructor call at `0x004693d4` and additional callers outside this class.
- 2026-06-05 live event evidence confirms `OnKeyEvent` gates against bytes at event offsets `+0x10a`, `+0x8`, and key code `0x0a`, then posts message `0x500`; `OnMouseEvent` uses active browser-pane global `dword_67AB88`, bounds helper `sub_4B7E80`, and coordinate helper `sub_557440`; `OnNavigateAction` posts message `0x501` through `PostThreadMessageA` using `dword_67AB88`.
- 2026-06-05 live bounds helper evidence confirms `sub_49DAE0` marks `[ecx+0x229] = 1` and copies rectangle fields into offsets including `+0x22c` and `+0x230`.
- Constructor/destructor evidence tracks [UID:0000QB][g_pBrowserDialogOld](by-global/g_pBrowserDialogOld.md) as the legacy browser dialog singleton.
- [UID:0000HV][Browser](by-file/Browser.md) is scored `84/88`, assigned to `NexusTK/browser/`, and groups `BrowserDialogOld`, `BrowserControlPaneOld`, `BrowserThread`, browser COM helpers, browser-specific globals, and the legacy/new browser control family under the browser module.
- [UID:0000Z3][0x00469290-0x0046963c.BrowserDialogOldCore](by-memory/0x00469290-0x0046963c.BrowserDialogOldCore.md) is scored `84/90` and records the corrected constructor/destructor/key/mouse/navigate boundaries, raw helper bodies, constructor call into `BrowserControlPaneOld`, singleton global, and browser-module ownership.
- [UID:0000QB][g_pBrowserDialogOld](by-global/g_pBrowserDialogOld.md) documents the legacy browser dialog singleton role and ownership hypothesis with this dialog/control path.
- [UID:00033B][0x004705e0-0x0047068d.BrowserDialogOldScalarDeletingDestructor](by-memory/0x004705e0-0x0047068d.BrowserDialogOldScalarDeletingDestructor.md) records the exact B001-024 scalar deleting destructor, vtable ref `0x00613154`, adjustor callers at `0x004702aa`/`0x004702b5`, legacy cleanup calls, singleton clear, base teardown, and delete flag behavior.

## Open Questions

- Decide whether "Old" browser classes were retained source files or dead legacy paths still linked into the client.
- Confirm non-dialog callers of [UID:0000QB][g_pBrowserDialogOld](by-global/g_pBrowserDialogOld.md), if any, before final header placement.

## Score Rationale

Completion is raised to `85` because live IDA now verifies method ranges, vtable slot/xref ownership, singleton set/clear behavior, child `BrowserControlPaneOld` construction, dialog bounds setup, message posting, shared helper boundaries, and the exact B001-024 scalar deleting destructor child at class scope. Confidence is raised to `87` because the legacy dialog shape is now strongly supported by current disassembly and cross-references, but remains below final reconstruction because constructor/destructor entry reachability is still indirect or absent and final source/header placement is not proven.

## Cross-References

- File: [UID:0000HV][Browser](by-file/Browser.md)
- Related classes: [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md), [UID:00001A][BrowserThread](by-class/BrowserThread.md)
- Globals: [UID:0000QB][g_pBrowserDialogOld](by-global/g_pBrowserDialogOld.md)
- Memory: [UID:0000Z3][0x00469290-0x0046963c.BrowserDialogOldCore](by-memory/0x00469290-0x0046963c.BrowserDialogOldCore.md), [UID:00033B][0x004705e0-0x0047068d.BrowserDialogOldScalarDeletingDestructor](by-memory/0x004705e0-0x0047068d.BrowserDialogOldScalarDeletingDestructor.md), [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md)

## Changes

- 2026-06-10 B001-024 parent-gate repair:
  - Before: `COMPLETION:82`, `CONFIDENCE:86`, with scalar deleting destructor evidence recorded but no exact destructor child attached.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:87`, and linked exact child [UID:00033B][0x004705e0-0x0047068d.BrowserDialogOldScalarDeletingDestructor](by-memory/0x004705e0-0x0047068d.BrowserDialogOldScalarDeletingDestructor.md).
  - Summary/evidence: live IDA MCP confirms `sub_4705E0`, vtable ref `0x00613154`, adjustor callers, cleanup calls, `g_pBrowserDialogOld` clear, base teardown, and delete flag behavior. This clears the strict `85/85` parent gate for the destructor child.
- What existed before: the legacy dialog page documented role, methods, evidence, globals, and references, but completion/confidence metadata was `0/0`.
- What it was changed to: scores were set to `68/78`.
- Summary and evidence: constructor, old control-pane construction, singleton global, and bounds helper are covered; old-path reachability and final file/header placement remain unresolved.
- 2026-06-03 parent attachment pass:
  - What existed before: the page was reconstructable in substance but had blank autogen metadata and remained in the low-completion/low-both tables at `68/78`.
  - Changed to: `COMPLETION:72`, `CONFIDENCE:82`, `RECONSTRUCTABLE:TRUE`, and parent [UID:0000HV][Browser](by-file/Browser.md).
  - Summary/evidence: the Browser file doc, exact old-dialog core memory page, `BrowserControlPaneOld` constructor linkage, and singleton global page support browser-module source ownership. C++ remains blank because old-path reachability, final file/header split, and legacy lifetime details are below the 95+ reconstruction gate.
- 2026-06-04 evidence-reference refresh:
  - What existed before: the evidence list still described the method inventory through stale source metadata and referenced the core page at its old `70/85` score.
  - Changed to: the evidence list now points to live IDA coverage and the updated [UID:0000Z3][0x00469290-0x0046963c.BrowserDialogOldCore](by-memory/0x00469290-0x0046963c.BrowserDialogOldCore.md) `84/90` score.
  - Summary/evidence: IDA MCP confirmed the core constructor/destructor/key/mouse/navigation functions, raw helper bodies, vtable anchors, and singleton set/clear behavior on 2026-06-04; class-level scores stay unchanged until the non-core methods and final source split are refreshed at class scope.
- 2026-06-05 class-scope IDA refresh:
  - What existed before: the class remained `72/82`, with live evidence mostly delegated to the memory page and final-source blockers listed at a high level.
  - Changed to: completion `82`, confidence `86`, exact method ranges in the method list, and refreshed class-scope evidence for vtable xrefs, singleton lifecycle, child construction, bounds setup, event message posting, and shared helper calls.
  - Summary/evidence: live IDA confirms constructor/destructor have no direct xrefs, virtual handlers are vtable-referenced, constructor `0x0046936e` calls `sub_46FF50`, constructor/destructor set and clear `dword_67AB90`, `GetChildRect` remains called by `sub_46AA40`, and `SetDialogBounds` is shared beyond this class. Scores stay below final because old-path reachability and exact source/header split remain unresolved.
