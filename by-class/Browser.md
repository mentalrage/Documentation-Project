*** UID:000013 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Browser

## Status

- Confidence: strong for subsystem placement, Browser COM/event-sink identity, exact promoted method ranges, vtable anchors, connection cleanup, and dispatch-event behavior; medium for final multiple-inheritance/interface declaration details.
- Likely source module: [UID:0000HV][Browser](by-file/Browser.md)
- Current relevant ranges: Browser method body cluster `0x0046f480-0x00470406`, notification helper evidence at `0x00470740-0x00470782` / `0x00470f20-0x00470fb9`, connection helpers `0x004708d0-0x00470a00`, GUID helper `0x004710e0-0x0047110e`, and Browser vtable slices at `0x00613830-0x00613908`.
- Evidence basis: live IDA MCP function-boundary, decompile, call/xref, and vtable checks plus linked browser subsystem documentation.

## Responsibility

`Browser` is a COM-style embedded browser object/event sink used by the older browser-control path. The live binary shows five vtable slices stored at offsets `+0x00`, `+0x04`, `+0x08`, `+0x0c`, and `+0x10`, QueryInterface paths over browser COM GUID data, advisory connection cleanup, dispatch-event handling, browser teardown, and notification posting.

## Methods

Active methods:

- `0x0046f480-0x0046f53e` `~Browser`
- `0x0046f540-0x0046f66f` `QueryInterface`
- `0x0046f7e0-0x0046f7e8` `QueryService_NotImpl`
- `0x0046f7f0-0x0046f7f8` `QueryStatus_NotImpl`
- `0x0046f800-0x0046f808` `TranslateAccelerator_NotImpl`
- `0x0046f810-0x0046fab6` `Invoke`
- `0x00470330-0x00470406` `ScalarDeletingDestructor`

Disabled/adjustor-like methods:

- `0x00470fdc`
- `0x00470fe6`
- `0x00470ff0`
- `0x00470ffa`
- `0x0047105e`

## Ownership Notes

- `Browser::~Browser` and `ScalarDeletingDestructor` call `UnadviseConnectionPoint`, release COM interfaces, destroy hosted windows, and clear URL/string state.
- `Browser::Invoke` handles browser event dispatch IDs such as download begin/complete, navigation, and new-window cases.
- This class should stay with `BrowserWindow`, `BrowserThread`, `BrowserControlPaneOld`, `browser__Notification`, and the COM helper globals in the browser module.
- The shared COM event id and IID evidence is tracked in [UID:0001SJ][BrowserDispatchEventId](by-type/by-enum/BrowserDispatchEventId.md) and [UID:0000T2][DIID_DWebBrowserEvents2](by-global/DIID_DWebBrowserEvents2.md).

## Assignment Decision

`AUTOGEN_PARENT_UID` is [UID:0000HV][Browser](by-file/Browser.md). The child class is now `85/86`, and the direct file parent is `86/88`, so both sides clear the corrected `85/85` gate. The file parent is a direct owner because it documents the cohesive browser/OLE source module containing `Browser`, `BrowserWindow`, `BrowserThread`, `BrowserControlPaneOld`, `browser::Notification`, browser COM helpers, and the related vtable/string data. Final C++ remains blank because the exact source-level COM interface declarations and multiple-inheritance spelling remain below the `95/95` reconstruction-code gate.

## IDA Evidence

- 2026-06-04 live IDA MCP evidence from `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` (image base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`) confirms `~Browser` at `0x0046f480-0x0046f53e`, `QueryInterface` at `0x0046f540-0x0046f66f`, not-implemented COM stubs at `0x0046f7e0`, `0x0046f7f0`, and `0x0046f800`, `Invoke` at `0x0046f810-0x0046fab6`, and `ScalarDeletingDestructor` at `0x00470330-0x00470406`.
- Live vtable xrefs show Browser vtable slices stored by the destructor, constructor/setup path, and scalar deleting destructor around `0x0046f4ad-0x0046f4c8`, `0x00470009-0x00470024`, and `0x0047035d-0x00470378`.
- `QueryInterface` compares browser COM GUID/IID data around `0x00631580-0x00631610`, including a call to [UID:000218][0x004710e0-0x0047110e.BrowserGuidCompareHelper](by-memory/0x004710e0-0x0047110e.BrowserGuidCompareHelper.md).
- `~Browser` and `ScalarDeletingDestructor` both reset Browser vtables, release string/state at offset `+0x228`, call `UnadviseConnectionPoint` at `0x00470980` for the connection point/interface at `+0x18` / cookie at `+0x1c`, release the COM interface, destroy the hosted window at `+0x14`, and clean up the wide/string field at `+0x230`.
- `Browser::Invoke` handles dispatch/event cases including `104`, `106`, `250`, `251`, `263`, and `270`, posts thread message `0x500` for close/resource redirects, calls `0x00470dd0` navigation helper for close handling, and constructs/posts [UID:000014][browser__Notification](by-class/browser__Notification.md) payloads inline or through `0x00470f20`.
- 2026-06-07 Batch080 live IDA MCP `py_eval` rechecked the promoted Browser method starts: `0x0046f480-0x0046f53e`, `0x0046f540-0x0046f66f`, `0x0046f7e0-0x0046f7e8`, `0x0046f7f0-0x0046f7f8`, `0x0046f800-0x0046f808`, `0x0046f810-0x0046fab6`, and `0x00470330-0x00470406`. The same pass confirmed Browser vtable-slice xrefs at `0x00613830` and `0x00613908` from `0x0046f480`, `0x0046ff50`, and `0x00470330`, matching destructor, setup, and scalar-delete vptr stores.

## Score Rationale

- Completion `85`: the page now carries exact Browser method boundaries, vtable-slice xrefs, QueryInterface GUID/helper evidence, connection cleanup behavior, dispatch-event behavior, notification posting, and a corrected direct-file parent assignment. Remaining work is detailed COM interface layout and final header/source spelling.
- Confidence `86`: class identity and direct browser-module ownership are backed by live IDA MCP and linked browser data pages. Confidence stays below higher levels because the final source declarations for the five interface slices remain provisional.

## Open Questions

- The current `ScalarDeletingDestructor` naming is still compiler-artifact flavored and should eventually become a normal destructor/delete wrapper representation.
- The exact multiple-inheritance/interface declaration needs class-layout work before final header placement.
- Confirm whether modern and old browser classes coexisted in one file or were separate `.cpp` files in the original project.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)
- [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md)
- [UID:000218][0x004710e0-0x0047110e.BrowserGuidCompareHelper](by-memory/0x004710e0-0x0047110e.BrowserGuidCompareHelper.md)
- [UID:0001OB][0x006131b4-0x006139df.BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md)

## Changes

- What existed before: the page documented the COM/browser responsibility, major methods, ownership notes, and IDA evidence, but completion/confidence metadata remained `0/0`.
- What it was changed to: scores were set to `72/78`.
- Summary and evidence: destructor, QueryInterface, Invoke, scalar delete, GUID helper, and vtable/string references make the class identity strong; exact multiple-inheritance layout and final old/new browser source split still need deeper reconstruction.
- 2026-06-04 live IDA evidence update:
  - What existed before: `COMPLETION:72` and `CONFIDENCE:78`, with stale generated-output evidence references and only partial method-boundary notes.
  - Changed to: `COMPLETION:78` and `CONFIDENCE:84`.
  - Summary/evidence: live IDA confirms exact ranges for the destructor, QueryInterface, COM stubs, Invoke, scalar deleting destructor, Browser vtable-slice stores, GUID comparison helper, connection-point cleanup, hosted-window destruction, string cleanup, and browser notification posting. Completion remains below high because final COM interface declarations, vtable slice naming, and old/new browser source split still need a full layout pass.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE`. Current IDA MCP `lookup_funcs` reconfirmed the destructor, QueryInterface, Invoke, and scalar deleting destructor starts at `0x0046f480`, `0x0046f540`, `0x0046f810`, and `0x00470330`. `AUTOGEN_PARENT_UID` remains blank even though [UID:0000HV][Browser](by-file/Browser.md) is the likely owner because the class completion score is still below the 80+ attachment gate.
- 2026-06-07 Batch080 class coverage pass:
  - Changed score from `78/84` to `85/86`.
  - Set `AUTOGEN_PARENT_UID:0000HV` because this class and the direct [UID:0000HV][Browser](by-file/Browser.md) source root both clear the corrected `85/85` gate.
  - Evidence: live IDA MCP rechecked all promoted Browser method boundaries and Browser vtable-slice xrefs from destructor/setup/scalar-delete stores; linked browser file and read-only-data docs support direct source-module ownership. C++ remains blank because the final COM interface declaration is not at `95/95`.
