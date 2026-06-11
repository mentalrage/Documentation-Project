*** UID:000019 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BrowserPane

## Summary

`BrowserPane` is a `DialogPane`-derived UI pane for browser-related command handling and selection behavior. It handles browser command codes, keyboard filtering, selection state, timer/sound delegation, and item activation.

Current confidence is high for browser-module ownership, the command/key/timer/sound methods, alert-string usage, vtable placement, and source parent placement under [UID:0000HV][Browser](by-file/Browser.md). It remains capped below final-reconstruction quality because the constructor-shaped block at `0x0046a860` is still not an IDA-modeled function or referenced call target, and several control-list helpers used by BrowserPane are shared `DialogPane` infrastructure rather than Browser-private methods.

## Likely Original Placement

- Source: [UID:0000HV][Browser](by-file/Browser.md)
- Proposed path: `browser/Browser.cpp`
- Confidence: strong for browser subsystem ownership; medium for whether the original source split had a separate `BrowserPane.cpp`.

## Methods

- `0x0046a860` constructor-shaped raw block - initializes the `DialogPane` base and installs the three BrowserPane vtable views; IDA currently has no function at this start.
- `0x0046a8a0` vtable reset / base cleanup wrapper.
- `0x0046a8e0` `OnKeyEvent`.
- `0x0046a910` `OnCommand` - handles command codes including `BCdp`, `BCfl`, and `BCto`, using direct alert strings at [UID:0001OD][0x00613a20-0x00613ab0.BrowserAlertStrings](by-memory/0x00613a20-0x00613ab0.BrowserAlertStrings.md).
- `0x0046ad80` resized input handler installed through the BrowserDialog/BrowserPane vtable cluster.
- `0x00470690` scalar deleting destructor.
- `0x00470fc0` `ScheduleTimer`.
- `0x004710d0` `PlaySound`.

## Shared Dialog-Control Helpers Used By BrowserPane

- [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md) owns the shared item lookup, selection, pending-item update, and activation helpers around `0x0049dd20-0x0049dfc4`.
- Treat the Browser call sites as consumers of that helper cluster, not as proof that those helper bodies are BrowserPane-private methods.

## Live IDA Evidence

- IDA MCP reports no function at `0x0046a860`. The previous function is `sub_46A630` at `0x0046a630-0x0046a6ea`, and the next modeled function is `sub_46A8A0` at `0x0046a8a0-0x0046a8bf`.
- Raw disassembly for `0x0046a860-0x0046a898` calls `sub_49D8A0` with `word_60DB20`, then stores BrowserPane vtable views at `this+0x00 -> 0x006132ec`, `this+0xa0 -> 0x00613360`, and `this+0xa4 -> 0x00613390`, returning with `retn 8`. IDA finds no refs to `0x0046a860` and no pointer slots containing that address in the browser vtable region.
- `sub_46A8A0` at `0x0046a8a0-0x0046a8bf` restores the same three BrowserPane vtable views and calls `sub_49D9F0` / `boost::exception::~exception`.
- `sub_46A8E0` at `0x0046a8e0-0x0046a901` consumes the key event when `a2[4] == 8` and `a2[8] == 0x90`; otherwise it delegates to `sub_49E6E0(this, a2)`. Vtable data refs place it at `0x00613368`, `0x00613418`, and `0x00613708`.
- `sub_46A910` at `0x0046a910-0x0046aa34` handles commands `1111712880` (`BCdp`), `1111713388` (`BCfl`), `1111716975` (`BCto`), and `1394`; each handled case allocates `624` bytes via `sub_4F4AA0`, calls `sub_49FEB0` with a direct alert string and the shared `OK` text at `0x00613a18`, then closes through `sub_49DF20(this)`.
- Direct alert string refs from `sub_46A910` are `0x0046a97e -> 0x00613a20` (`Dispose`), `0x0046a9d5 -> 0x00613a30` (`Navigation Failed`), `0x0046aa06 -> 0x00613a54` (`Navigation Timeout`), and `0x0046a9ab -> 0x00613a7c` (`Web Board Request Timeout`).
- BrowserPane vtable slots confirm `OnCommand` at `0x00613348`, `0x006133f8`, `0x00613638`, and `0x006136e8`; timer delegation at `0x0061334c`, `0x006133fc`, `0x0061363c`, and `0x006136ec`; sound delegation at `0x00613350`, `0x00613400`, `0x00613640`, and `0x006136f0`.
- `sub_470FC0` at `0x00470fc0-0x00470fdc` delegates timer scheduling through `sub_5975E0(this+0xa4, a2, a3, 0, 0)`, and `sub_4710D0` at `0x004710d0-0x004710df` delegates sound through `sub_597610(this+0xa4, a2)`.
- `sub_470690` at `0x00470690-0x004706e5` is the scalar deleting destructor slot at `0x006132ec`; it restores all three BrowserPane vtable views, calls `sub_49D9F0`, and conditionally frees through `sub_4F4AC0` when the delete flag permits.
- [UID:0000HV][Browser](by-file/Browser.md) is scored `86/88`, has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/browser/"`, and groups BrowserPane with the dense browser/OLE module after IDA-backed boundary, helper, and global ownership checks.
- [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md) is scored `74/84`, attached to [UID:0000IT][DialogPane](by-file/DialogPane.md), and records broad non-browser caller distribution for the selection helpers.

## Batch 106 Parent-Gate Refresh

2026-06-08 read-only IDA MCP `py_eval` reconfirmed the BrowserPane method evidence used by this class page:

| Range | Current IDA function | Vtable refs / notes |
| --- | --- | --- |
| `0x0046a860` | no modeled IDA function | Still a raw constructor-shaped block; this remains the main final-layout caveat. |
| `0x0046a8a0-0x0046a8bf` | `sub_46A8A0` | Cleanup/reset wrapper, with EH/table xrefs outside the browser vtable slots. |
| `0x0046a8e0-0x0046a901` | `sub_46A8E0` | Key-event virtual slot refs at `0x00613368`, `0x00613418`, and `0x00613708`. |
| `0x0046a910-0x0046aa34` | `sub_46A910` | Command virtual slot refs at `0x00613348`, `0x006133f8`, `0x00613638`, and `0x006136e8`. |
| `0x00470690-0x004706e5` | `sub_470690` | Scalar deleting destructor refs include BrowserPane primary vtable slot `0x006132ec`. |
| `0x00470fc0-0x00470fdc` | `sub_470FC0` | Timer delegation slot refs at `0x0061334c`, `0x006133fc`, `0x0061363c`, and `0x006136ec`. |
| `0x004710d0-0x004710df` | `sub_4710D0` | Sound delegation slot refs at `0x00613350`, `0x00613400`, `0x00613640`, and `0x006136f0`. |

[UID:0000HV][Browser](by-file/Browser.md) is now scored `86/88`, so the direct parent side clears the corrected `85/85` gate. This class now clears `85/86`; retaining `AUTOGEN_PARENT_UID:0000HV` is justified for class-level routing, while exact constructor/source split questions continue to block final C++.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | The class page now documents the BrowserPane command/key/timer/sound virtuals, scalar destructor, vtable refs, browser alert strings, shared DialogPane helper boundary, Browser source parent, and the exact remaining raw-constructor caveat. |
| Confidence | 86 | BrowserPane ownership and the tail `PlaySound` parent relationship are supported by current IDA MCP function/vtable refs and the Browser source page. Confidence remains below higher levels because the `0x0046a860` constructor-shaped block is not an IDA-modeled function and final field names/source split are open. |
| Parent | [UID:0000HV][Browser](by-file/Browser.md) | Child `85/86` and parent `86/88` clear the strict gate; Browser is the direct source root for this class cluster, while exact one-file versus split-file layout remains a source organization caveat. |

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
- 2026-06-04 live IDA refresh:
  - What existed before: BrowserPane was scored `74/80` and still depended on stale constructor phrasing while omitting several exact vtable slots and method-body facts.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:84`, with the C++ reconstruction intentionally left blank.
  - Summary/evidence: live IDA confirms the raw constructor-shaped block at `0x0046a860-0x0046a898`, the three BrowserPane vtable writes at `0x006132ec`, `0x00613360`, and `0x00613390`, method ranges for `sub_46A8A0`, `sub_46A8E0`, `sub_46A910`, `sub_470690`, `sub_470FC0`, and `sub_4710D0`, command-to-alert-string refs, and vtable slots for command/timer/sound dispatch. The score remains capped because `0x0046a860` is still not an IDA-modeled function or referenced call target, helper ownership remains partly shared with `DialogPane`, and the original source split is not proven to the final reconstruction bar.
- 2026-06-08 A007 Batch 106 parent-gate refresh:
  - Changed score from `82/84` to `85/86`.
  - Retained `AUTOGEN_PARENT_UID:0000HV` because [UID:0000HV][Browser](by-file/Browser.md) is now `86/88`, and this class now clears the corrected `85/85` gate.
  - Evidence: read-only IDA MCP reconfirmed the modeled BrowserPane key, command, destructor, timer, and sound helpers and their BrowserPane-family vtable refs; the unresolved `0x0046a860` raw constructor-shaped block remains documented as the completion/confidence cap rather than a routing blocker for [UID:000217][0x004710d0-0x004710df.BrowserPanePlaySound](by-memory/0x004710d0-0x004710df.BrowserPanePlaySound.md).
