*** UID:000014 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# browser::Notification

## Summary

`browser::Notification` is the browser-specific notification payload type used by `PostBrowserNotification`. It carries browser notification data on the `'Bros'` notification channel and destroys its owned string/base-object state in the deleting destructor.

## Likely Original Placement

- Source: [UID:0000HV][Browser](by-file/Browser.md)
- Proposed path: `browser/Browser.cpp`
- Confidence: strong

## Methods

- `0x00470740` scalar deleting destructor.

## Evidence

- Wave3 reports one active method at `0x00470740-0x00470781`.
- IDA MCP confirms the function at `0x00470740-0x00470782`.
- Wave3 reports `PostBrowserNotification` at `0x00470f20` builds this payload and posts it on the `'Bros'` notification channel.
- IDA MCP decompilation confirms `PostBrowserNotification` allocates this payload and posts tag `1114795891` (`'Bros'`).

## Open Questions

- Recover the payload fields and exact notification enum names.

## Cross-References

- File: [UID:0000HV][Browser](by-file/Browser.md)
- Related classes: [UID:00001A][BrowserThread](by-class/BrowserThread.md), [UID:000013][Browser](by-class/Browser.md)
- Memory: [UID:0000ZF][0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers.md), [UID:0001OB][0x006131b4-0x006139df.BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:72` and `CONFIDENCE:78`.
  - Summary/evidence: scored from the browser notification purpose, deleting destructor, `PostBrowserNotification` channel evidence, and browser memory/vtable references; completion remains moderate because payload fields and exact notification enum names are still open.
