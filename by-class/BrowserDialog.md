*** UID:000017 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BrowserDialog

## Summary

`BrowserDialog` is the singleton URL browser dialog used by the newer browser-control path. It owns a title area and an embedded `BrowserControlPane`, and forwards URL navigation into an already-open browser pane.

## Likely Original Placement

- Source: [UID:0000HV][Browser](by-file/Browser.md)
- Proposed path: `browser/Browser.cpp` or `browser/BrowserDialog.cpp`
- Confidence: strong for the browser module and parent attachment; medium-high for exact file split between a monolithic `Browser.cpp` and a separate `BrowserDialog.cpp`

## Methods

| Range | Current interpretation | Notes |
| --- | --- | --- |
| `0x0046a8c0-0x0046a8d7` | `BrowserDialog::NavigateToUrl` | Thin singleton/dialog wrapper that forwards the URL into the embedded browser control through `0x0046bd30`. |
| `0x0046aa40-0x0046ad0a` | constructor | Creates the singleton dialog, installs BrowserPane and BrowserDialog vtables, builds title/browser child panes, and calls the child-rect helper twice. |
| `0x0046ad10-0x0046ad39` | destructor body | Clears `dword_67AB98`, restores BrowserPane vtables, and chains to the base dialog teardown. |
| `0x0046ad40-0x0046ad7b` | close/teardown virtual | Shuts down the embedded `BrowserControlPane`, refreshes/closes the dialog, and unregisters it from the pane registry when the action argument is zero. |
| `0x0046ad80-0x0046aea8` | browser-window resize/input virtual | Handles resize/input, calls `GetClientRect`/`MoveWindow`, and refreshes the active screen. |
| `0x0046aeb0-0x0046b02d` | visual refresh helper | Draws state-dependent browser-dialog UI pieces after clearing transient pane state. |
| `0x0046b030-0x0046b0c3` | title/content draw helper | Uses `off_60DB5C` and `off_60DB78` to draw browser-dialog title/content art. |
| `0x0046b0d0-0x0046b4af` | frame/chrome draw helper | Tiles the EPF frame/chrome using the `off_60DB94` and `off_60DBB0` resource tables. |
| `0x0046b4b0-0x0046b51d` | child-rect helper | Computes slot `0` title bounds and slot `1` browser-content bounds from the dialog width/height fields. |
| [UID:00033A][0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor](by-memory/0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor.md) | scalar deleting destructor | Clears the newer browser-dialog singleton, restores BrowserPane vtables, runs base teardown, and optionally frees `this`. |

## Evidence

- Live IDA MCP recheck on 2026-06-04 used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, image base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- IDA confirms `NavigateToUrl` at `0x0046a8c0-0x0046a8d7`; it is called from `0x00513e7f` inside the `0x00513da0` MapPane packet helper and calls the embedded browser-control navigation helper at `0x0046bd30`.
- IDA confirms the constructor at `0x0046aa40-0x0046ad0a`, with direct callers at `0x00513ebe` inside the MapPane packet helper and `0x005a7079` inside `UserPane::OnKeyEvent`.
- Constructor data refs install BrowserPane vtables at `0x006132ec`, `0x00613360`, and `0x00613390`, then BrowserDialog vtables at `0x0061339c`, `0x00613410`, and `0x00613440`.
- Constructor refs write `dword_67AB98` at `0x0046aab7` and `0x0046aabe`, call the child-rect helper at `0x0046ab1d` and `0x0046ab5f`, and call the embedded `BrowserControlPane` constructor at `0x0046ab86`.
- Singleton `dword_67AB98` xrefs are now mapped: constructor writes at `0x0046aab7`/`0x0046aabe`, destructor clear at `0x0046ad10`, Browser-family clears at `0x00470220` and `0x00470586`, and reads from MapPane/UserPane/browser-launch paths at `0x00508d68`, `0x00513e67`, `0x005145ac`, `0x005a7005`, and `0x005a7037`.
- Vtable slots in the `0x0061339c-0x00613440` BrowserDialog group point to the destructor/delete thunks and virtual helpers; the key source-behavior slots include `0x006133e0 -> 0x0046aeb0`, `0x006133e4 -> 0x0046ad40`, `0x006133ec -> 0x0046b030`, `0x006133f0 -> 0x0046b0d0`, and `0x00613414 -> 0x0046ad80`.
- IDA confirms the child-rect helper returns title bounds `(width - 63) / 2, height - 32, 63, 24` for slot `0`, and browser content bounds `11, 42, width - 22, height - 82` for slot `1`.
- Byte checks confirm `0x0046ad0a-0x0046ad10` and `0x0046b51d-0x0046b520` are `0xcc` alignment padding between the constructor, virtual cluster, and `BrowserControlPane` constructor.
- B001-024 exact child [UID:00033A][0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor](by-memory/0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor.md) documents `sub_470580`, vtable ref `0x0061339c`, adjustor callers at `0x00470294`/`0x0047029f`, singleton clear `dword_67AB98`, base teardown, and delete flag behavior.

## Open Questions

- Add a dedicated global page for the newer `BrowserDialog *g_pBrowserDialog` singleton if final header placement needs it.
- Finalize source-facing names for the frame/chrome helpers and resource-table globals before writing C++.
- Decide whether the original source split was one `Browser.cpp` or a separate `BrowserDialog.cpp` inside the browser module.

## Cross-References

- File: [UID:0000HV][Browser](by-file/Browser.md)
- Related classes: [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md), [UID:000019][BrowserPane](by-class/BrowserPane.md)
- Memory: [UID:0000Z5][0x0046a860-0x0046ad0a.BrowserPaneAndDialog](by-memory/0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md), [UID:00020X][0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals](by-memory/0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals.md), [UID:00033A][0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor](by-memory/0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor.md)

## Changes

- 2026-06-10 B001-024 parent-gate repair:
  - Before: `COMPLETION:84`, `CONFIDENCE:88`; scalar deleting destructor behavior was documented only in the class summary.
  - Changed to: `COMPLETION:85`, linked exact child [UID:00033A][0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor](by-memory/0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor.md).
  - Summary/evidence: live IDA MCP confirms `sub_470580` at `0x00470580-0x004705df`, vtable ref `0x0061339c`, adjustor callers, singleton clear `dword_67AB98`, BrowserPane vtable restore, base teardown, and delete flag behavior. This clears the strict `85/85` parent gate for the destructor child.
- 2026-06-04: Raised completion/confidence from `72/80` to `84/88`, marked reconstructable, and attached to [UID:0000HV][Browser](by-file/Browser.md).
  - Before: the page identified the constructor and virtual cluster but still carried stale provenance wording, was not attached to the Browser parent, and did not record the singleton/vtable/child-rect evidence in enough detail to justify leaving the low-score queue.
  - After: live IDA evidence records the binary identity, exact method ranges, MapPane/UserPane callers, BrowserDialog vtable stores/slots, singleton reads and clears, embedded `BrowserControlPane` construction, child-rect arithmetic, and alignment padding.
  - Reasoning: the class is clearly source-authored browser-module code and the parent file is already high-confidence enough for attachment. Final C++ remains blank because frame-resource typing, exact virtual names, and the one-file versus split-file decision are still below the 95/95 reconstruction bar.
- Before: this page only listed `NavigateToUrl` and the constructor, and its memory reference pointed at a range ending in `0x0046ad09`.
- Changed to: the constructor endpoint is now `0x0046ad0a`, and the adjacent destructor/virtual helper cluster at `0x0046ad10-0x0046b51d` is included.
- Summary/evidence: IDA MCP reports `sub_46AA40` ends at `0x0046ad0a`, and vtable xrefs place `sub_46AD40`, `sub_46AD80`, `sub_46AEB0`, `sub_46B030`, and `sub_46B0D0` in the BrowserDialog vtable region.

- What existed before: the page had browser-dialog evidence and prior range corrections, but completion/confidence metadata still read `0/0`.
- What it was changed to: scores were set to `72/80`.
- Summary and evidence: constructor, singleton behavior, BrowserControlPane ownership, and vtable-neighboring virtuals are documented; singleton typing and final source split remain open.
