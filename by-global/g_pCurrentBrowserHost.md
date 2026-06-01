*** UID:0000QO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pCurrentBrowserHost

## Status

- Confidence: strong for temporary browser-host role, medium for exact final type.
- Current Wave3 kind: `global-data`
- Current generated owner file: `class_BrowserThread.cpp`
- IDA storage candidate: `0x0067ab8c` (`dword_67AB8C`)
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md)

## Observed Evidence

`BrowserThread::InitializeBrowserHost` writes the pending host object into `dword_67AB8C` immediately before creating the browser host window, then clears it after associating the host with the window through `SetWindowLongA`.

IDA xrefs to `0x0067ab8c` are limited to the browser host window path:

- `0x0046fcee` in the browser host window procedure neighborhood.
- `0x00470b3c` and `0x00470be3` in `BrowserThread::InitializeBrowserHost`.

## Ownership Hypothesis

This is a short-lived construction bridge used by the browser host window procedure while a new `BrowserWindow`/host object is being created.

## Type Hypothesis

Likely declaration:

```cpp
static BrowserWindow* g_pCurrentBrowserHost;
```

The exact type may be `Browser*`, `BrowserWindow*`, or a host-interface base until the host object layout is finalized.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:00001A][BrowserThread](by-class/BrowserThread.md)
- [UID:00001B][BrowserWindow](by-class/BrowserWindow.md)
- [UID:0000ZF][0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `78/78`. Summary/evidence: the page documents the temporary browser-host bridge role, storage candidate, limited IDA xrefs, owner/type hypotheses, and browser refs; exact final host type remains unresolved.
