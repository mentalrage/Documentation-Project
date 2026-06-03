*** UID:000019 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BrowserPane

## Summary

`BrowserPane` is a `DialogPane`-derived UI pane for browser-related command handling and selection behavior. It handles browser command codes, keyboard filtering, selection state, timer/sound delegation, and item activation.

Current confidence is strong for browser-module ownership, the command/key/sound methods, alert-string usage, and source parent placement under [UID:0000HV][Browser](by-file/Browser.md). It remains capped at 80 because Wave3's projected constructor start at `0x0046a860` is still not an IDA-modeled function, and several control-list helpers used by BrowserPane are shared `DialogPane` infrastructure rather than Browser-private methods.

## Likely Original Placement

- Source: [UID:0000HV][Browser](by-file/Browser.md)
- Proposed path: `browser/Browser.cpp`
- Confidence: strong for browser subsystem ownership; medium for whether the original source split had a separate `BrowserPane.cpp`.

## Methods

- `0x0046a860` Wave3-projected constructor - initializes `DialogPane` base and three vtable pointers; IDA currently has no function at this start.
- `0x0046a8e0` `OnKeyEvent`.
- `0x0046a910` `OnCommand` - handles command codes including `BCdp`, `BCfl`, and `BCto`, using direct alert strings at [UID:0001OD][0x00613a20-0x00613ab0.BrowserAlertStrings](by-memory/0x00613a20-0x00613ab0.BrowserAlertStrings.md).
- `0x0046ad80` resized input handler installed through the BrowserDialog/BrowserPane vtable cluster.
- `0x00470690` scalar deleting destructor.
- `0x00470fc0` `ScheduleTimer`.
- `0x004710d0` `PlaySound`.

## Shared Dialog-Control Helpers Used By BrowserPane

- [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md) owns the shared item lookup, selection, pending-item update, and activation helpers around `0x0049dd20-0x0049dfc4`.
- Treat the Browser call sites as consumers of that helper cluster, not as proof that those helper bodies are BrowserPane-private methods.

## Evidence

- Wave3 notes a 617-byte `DialogPane`-derived structure, triple vtable installation, and command codes `BCdp`, `BCfl`, and `BCto`.
- IDA MCP confirms `OnKeyEvent` at `0x0046a8e0-0x0046a901`, `OnCommand` at `0x0046a910-0x0046aa34`, and helper methods under `0x0049dd20-0x0049dfc3`.
- IDA MCP confirms `PlaySound` at `0x004710d0-0x004710df`, with BrowserPane vtable refs at `0x00613350`, `0x00613400`, `0x00613640`, and `0x006136f0`.
- IDA MCP reports no function at Wave3's `0x0046a860` constructor start. The previous function is `0x0046a630-0x0046a6ea`, and the next function is `0x0046a8a0-0x0046a8bf`.
- `OnCommand` uses direct UTF-16 string literals for alert text. Current generated names [UID:0000QC][g_pBrowserFileLoadText](by-global/g_pBrowserFileLoadText.md) and [UID:0000QF][g_pBrowserTimeoutText](by-global/g_pBrowserTimeoutText.md) resolve to `Navigation Failed` at `0x00613a30` and `Navigation Timeout` at `0x00613a54`; no separate pointer-global storage is confirmed.
- [UID:0000HV][Browser](by-file/Browser.md) is scored `84/88`, has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/browser/"`, and groups BrowserPane with the dense browser/OLE module after IDA-backed boundary, helper, and global ownership checks.
- [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md) is scored `74/84`, attached to [UID:0000IT][DialogPane](by-file/DialogPane.md), and records broad non-browser caller distribution for the selection helpers.

## Open Questions

- Review the `0x0046a860` projected constructor boundary before assigning final constructor names, source lines, or a declaration/body.
- Finalize whether the original source used a standalone `BrowserPane.cpp` or kept BrowserPane in the broader `Browser.cpp` module.

## Cross-References

- File: [UID:0000HV][Browser](by-file/Browser.md)
- Related classes: [UID:000017][BrowserDialog](by-class/BrowserDialog.md), [UID:00003T][DialogPane](by-class/DialogPane.md)
- Globals: [UID:0000PP][g_activeBrowserPane](by-global/g_activeBrowserPane.md), [UID:0000QC][g_pBrowserFileLoadText](by-global/g_pBrowserFileLoadText.md), [UID:0000QF][g_pBrowserTimeoutText](by-global/g_pBrowserTimeoutText.md)
- Memory: [UID:0000Z5][0x0046a860-0x0046ad0a.BrowserPaneAndDialog](by-memory/0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md), [UID:00020X][0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals](by-memory/0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals.md), [UID:000217][0x004710d0-0x004710df.BrowserPanePlaySound](by-memory/0x004710d0-0x004710df.BrowserPanePlaySound.md), [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md), [UID:0001OD][0x00613a20-0x00613ab0.BrowserAlertStrings](by-memory/0x00613a20-0x00613ab0.BrowserAlertStrings.md)

## Changes

- Before: the main memory reference pointed at `0x0046a860-0x0046ad09.BrowserPaneAndDialog`.
- Changed to: the reference now points at `0x0046a860-0x0046ad0a.BrowserPaneAndDialog`, and the related `0x0046ad10-0x0046b51d` resized-input/draw/helper cluster is linked separately.
- Summary/evidence: IDA MCP corrected the BrowserDialog constructor endpoint to `0x0046ad0a` and shows `0x0046ad80` installed through the BrowserDialog/BrowserPane vtable region.

- What existed before: the page documented BrowserPane behavior and range corrections, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `70/76`.
- Summary and evidence: command handling, keyboard behavior, alert strings, timer/sound delegates, and helper references are covered; the projected constructor and possible shared helper ownership limit confidence.
- 2026-06-03 parent attachment and shared-helper correction:
  - What existed before: the page was reconstructable in substance but had blank autogen metadata, still listed shared selection helpers as BrowserPane methods, and kept `70/76` scoring.
  - Changed to: `COMPLETION:74`, `CONFIDENCE:80`, `RECONSTRUCTABLE:TRUE`, and parent [UID:0000HV][Browser](by-file/Browser.md); the `0x0049dd20-0x0049dfc4` helpers are now explicitly treated as shared [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md) consumers rather than Browser-private bodies.
  - Summary/evidence: Browser parent placement is supported by the `84/88` Browser file doc, command/key/sound methods and alert strings remain Browser-specific, while the shared-helper page records broad dialog/control caller evidence. C++ remains blank because the projected constructor boundary and final source split are below the 95+ reconstruction gate.
