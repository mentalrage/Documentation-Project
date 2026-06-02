*** UID:0000PT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_browserControlKeyCallback / SendMessageW Dispatch Alias

## Status

- Confidence: strong for address, stale browser alias, and actual `SendMessageW` dispatch role; medium-high for final source-level symbol name.
- Current Wave3 kind: `global-data`
- Current generated owner file: `class_BrowserControlPaneOld.cpp`
- IDA storage candidate: `0x0069bec4` (`dword_69BEC4`)
- Memory doc: [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md)
- Owner: [UID:0000ML][PlatformApi](by-file/PlatformApi.md) / [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md).
- Status of this name: stale generated browser/transport alias for the `SendMessageW` dispatch entry.

## Observed Evidence

`BrowserControlPaneOld::HandleBrowserMessage` uses this callback when legacy browser messages for Tab or Escape arrive. `BrowserThread::RunMessageLoop` uses the same callback for Tab forwarding from the private browser thread message loop.

IDA xrefs to `0x0069bec4` include:

- `0x0046f0e6` in `BrowserThread::RunMessageLoop`.
- `0x0046f34d` in `BrowserControlPaneOld::HandleBrowserMessage`.
- Many non-browser network/transport call sites around `0x005747e0`, `0x005749e0`, `0x00575e60`, `0x00576660`, and related functions.

2026-05-25 IDA MCP `py_eval` reports `dword_69BEC4` as a four-byte `.data` item with 17 direct xrefs. Only two are in the browser dense code neighborhood; most are in transport/network or setup paths.

2026-05-26 IDA `py_eval` recheck confirms the item is initialized to `0xffffffff`, has one modeled startup/setup write at `0x0041a474`, two raw writes at `0x005997ae` and `0x005999e4`, two browser calls at `0x0046f0e6` and `0x0046f34d`, and socket/message calls in `Socket` lifecycle and send paths such as `0x005747e0`, `0x005749e0`, `0x00575e60`, `0x00576660`, `0x00576d90`, and `0x005795a0`.

2026-06-02 IDA MCP decompilation resolves the modeled startup/setup write: [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) writes `SendMessageW` to `dword_69BEC4` at `0x0041a474`. The adjacent assignments are `ImmGetCandidateListW` at `0x0041a46a`, `GetLocaleInfoW` at `0x0041a47e`, and `SetFileAttributesW` at `0x0041a488`, proving this address is part of the wide API dispatch table.

The raw writer neighborhoods at `0x005997ae` and `0x005999e4` are duplicate `UniAPIInit` table-assignment bodies. Disassembly shows they write the same sequence of version/IME/message/locale/file-attribute API pointers and do not establish browser or socket ownership.

## Ownership Hypothesis

This is not a browser-owned global. Browser code uses the platform dispatch entry to forward Tab/Escape from embedded browser windows through `SendMessageW`. Socket code uses the same dispatch entry in mode-6 message-forwarding paths. Final source ownership belongs with [UID:0000ML][PlatformApi](by-file/PlatformApi.md).

## Type Hypothesis

Generated browser source previously implied:

```cpp
using BrowserControlKeyCallback = int (*)(int ownerHandle, unsigned int messageId, int keyCode, unsigned int keyFlags);
```

BrowserThread generated source also names the same role `g_pTransportCallback`. Keep both names under review.

Current IDA evidence instead supports a `SendMessageW`-compatible dispatch entry, likely declared with a Win32 API function-pointer type inside the wide API dispatch table.

## Follow-Up

- Rename or supersede this generated alias when the wide API dispatch table receives final source-level symbol names.
- Keep browser and socket call sites as consumers only.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:0000ML][PlatformApi](by-file/PlatformApi.md)
- [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md)
- [UID:0001SL][BrowserMessageId](by-type/by-enum/BrowserMessageId.md)
- [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md)
- [UID:00001A][BrowserThread](by-class/BrowserThread.md)
- [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `82/76`. Summary/evidence: the page documents storage, browser and transport xrefs, initialization value, generated callback type, owner hypothesis, and follow-up writer sites; final owner/name remains unresolved.
- 2026-06-02 dispatch reclassification:
  - What existed before: the page treated `0x0069bec4` as unresolved browser/app/transport callback storage.
  - Changed to: the page now treats `g_browserControlKeyCallback` as a stale generated alias for the [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md) `SendMessageW` entry.
  - Summary/evidence: IDA MCP decompilation of [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) writes `SendMessageW` at `0x0041a474`, and raw writer sites are duplicate `UniAPIInit` table-assignment bodies.
