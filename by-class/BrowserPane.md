*** UID:000019 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BrowserPane

## Summary

`BrowserPane` is a `DialogPane`-derived UI pane for browser-related command handling and selection behavior. It handles browser command codes, keyboard filtering, selection state, timer/sound delegation, and item activation.

## Likely Original Placement

- Source: [UID:0000HV][Browser](by-file/Browser.md)
- Proposed path: `browser/Browser.cpp` or `browser/BrowserPane.cpp`
- Confidence: medium

## Methods

- `0x0046a860` Wave3-projected constructor - initializes `DialogPane` base and three vtable pointers; IDA currently has no function at this start.
- `0x0046a8e0` `OnKeyEvent`.
- `0x0046a910` `OnCommand` - handles command codes including `BCdp`, `BCfl`, and `BCto`, using direct alert strings at [UID:0001OD][0x00613a20-0x00613ab0.BrowserAlertStrings](by-memory/0x00613a20-0x00613ab0.BrowserAlertStrings.md).
- `0x0046ad80` resized input handler installed through the BrowserDialog/BrowserPane vtable cluster.
- `0x00470690` scalar deleting destructor.
- `0x00470fc0` `ScheduleTimer`.
- `0x004710d0` `PlaySound`.
- `0x0049dd20` `FindItemById`.
- `0x0049de00` `SetSelection`.
- `0x0049de70` `UpdatePendingItemState`.
- `0x0049df20` `ActivateItem`.

## Evidence

- Wave3 notes a 617-byte `DialogPane`-derived structure, triple vtable installation, and command codes `BCdp`, `BCfl`, and `BCto`.
- IDA MCP confirms `OnKeyEvent` at `0x0046a8e0-0x0046a901`, `OnCommand` at `0x0046a910-0x0046aa34`, and helper methods under `0x0049dd20-0x0049dfc3`.
- IDA MCP confirms `PlaySound` at `0x004710d0-0x004710df`, with BrowserPane vtable refs at `0x00613350`, `0x00613400`, `0x00613640`, and `0x006136f0`.
- IDA MCP reports no function at Wave3's `0x0046a860` constructor start. The previous function is `0x0046a630-0x0046a6ea`, and the next function is `0x0046a8a0-0x0046a8bf`.
- `OnCommand` uses direct UTF-16 string literals for alert text. Current generated names [UID:0000QC][g_pBrowserFileLoadText](by-global/g_pBrowserFileLoadText.md) and [UID:0000QF][g_pBrowserTimeoutText](by-global/g_pBrowserTimeoutText.md) resolve to `Navigation Failed` at `0x00613a30` and `Navigation Timeout` at `0x00613a54`; no separate pointer-global storage is confirmed.

## Open Questions

- Review the `0x0046a860` projected constructor boundary before assigning names or source lines.
- Determine whether the selection helpers at `0x0049dd20-0x0049dfc3` are really BrowserPane-specific or inherited/shared dialog-control helpers.

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
