*** UID:0000PT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_browserControlKeyCallback

## Status

- Confidence: strong for address and callback storage role; medium for final owner/name.
- Current Wave3 kind: `global-data`
- Current generated owner file: `class_BrowserControlPaneOld.cpp`
- IDA storage candidate: `0x0069bec4` (`dword_69BEC4`)
- Memory doc: [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md)
- Proposed owner: unresolved app/transport callback storage; browser is a consumer, not storage owner.

## Observed Evidence

`BrowserControlPaneOld::HandleBrowserMessage` uses this callback when legacy browser messages for Tab or Escape arrive. `BrowserThread::RunMessageLoop` uses the same callback for Tab forwarding from the private browser thread message loop.

IDA xrefs to `0x0069bec4` include:

- `0x0046f0e6` in `BrowserThread::RunMessageLoop`.
- `0x0046f34d` in `BrowserControlPaneOld::HandleBrowserMessage`.
- Many non-browser network/transport call sites around `0x005747e0`, `0x005749e0`, `0x00575e60`, `0x00576660`, and related functions.

2026-05-25 IDA MCP `py_eval` reports `dword_69BEC4` as a four-byte `.data` item with 17 direct xrefs. Only two are in the browser dense code neighborhood; most are in transport/network or setup paths.

2026-05-26 IDA `py_eval` recheck confirms the item is initialized to `0xffffffff`, has one modeled startup/setup write at `0x0041a474`, two raw writes at `0x005997ae` and `0x005999e4`, two browser calls at `0x0046f0e6` and `0x0046f34d`, and transport/socket calls in `Socket` lifecycle and send paths such as `0x005747e0`, `0x005749e0`, `0x00575e60`, `0x00576660`, `0x00576d90`, and `0x005795a0`.

## Ownership Hypothesis

This is a broad application/transport callback, not a browser-owned global. Browser code uses it to forward Tab/Escape from embedded browser windows to the main client window or transport callback path.

## Type Hypothesis

Generated source implies:

```cpp
using BrowserControlKeyCallback = int (*)(int ownerHandle, unsigned int messageId, int keyCode, unsigned int keyFlags);
```

BrowserThread generated source also names the same role `g_pTransportCallback`. Keep both names under review.

## Follow-Up

- Resolve the raw writer sites at `0x005997ae` and `0x005999e4` before finalizing owner or name.
- If the callback is application-wide, move final ownership to an app/platform/network callback page and leave this as a browser consumer note.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:0001SL][BrowserMessageId](by-type/by-enum/BrowserMessageId.md)
- [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md)
- [UID:00001A][BrowserThread](by-class/BrowserThread.md)
- [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `82/76`. Summary/evidence: the page documents storage, browser and transport xrefs, initialization value, generated callback type, owner hypothesis, and follow-up writer sites; final owner/name remains unresolved.
