*** UID:0000T2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:64 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# IID_BrowserEventSink

## Status

- Confidence: strong for browser COM interface-id role, medium for exact symbolic IID names.
- Current Wave3 kind: `global-data`
- Current generated owner file: `class_BrowserControlPane.cpp`
- IDA storage candidate: `0x00631610` (`unk_631610` in IDA decompilation)
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md)

## Observed Evidence

Generated `BrowserControlPane::ShutdownBrowserWindow` and related setup code name this value `IID_BrowserEventSink`. IDA xrefs to `0x00631610` include browser host setup, shutdown, `QueryInterface`, connection-point advise/unadvise, and browser object cleanup:

- `0x00469b02` in `BrowserWindow::ShutdownBrowserWindow`.
- `0x0046bb14` in `BrowserControlPane::ShutdownBrowserWindow`.
- `0x0046c73a` in `BrowserControlPane::QueryInterface`.
- `0x0046f4e9` and `0x0046f5fc` in the legacy `Browser` object.
- `0x00470cba` and `0x00470d61` in `BrowserThread::InitializeBrowserHost`.

Neighboring COM id constants in the same generated owner include `DAT_006315a0`, `DAT_006315d0`, `DAT_00631600`, and `DAT_00631620`. Generated `BrowserControlPane` also has `kSlot*InterfaceId` arrays that likely describe the same multi-interface COM object layout.

## Ownership Hypothesis

The browser COM IIDs should be declared near the browser host/control COM interface declarations, likely in `browser/Browser.cpp` with private/static linkage or in `browser/Browser.h` if class declarations need them.

## Follow-Up

- Name the neighboring IID constants by comparing GUID bytes with standard COM IIDs such as `IUnknown`, `IDispatch`, `IOleObject`, `IOleInPlaceObject`, `IOleClientSite`, and `DWebBrowserEvents2`.
- Decide whether `IID_BrowserEventSink` is a real custom IID, a browser event sink IID alias, or a recovered name for `DWebBrowserEvents2`.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md)
- [UID:00001B][BrowserWindow](by-class/BrowserWindow.md)
- [UID:00001A][BrowserThread](by-class/BrowserThread.md)
- [UID:0001OB][0x006131b4-0x006139df.BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `64/74`.
  - Before: page documented browser COM IID role, storage candidate, xrefs, neighboring constants, and follow-up naming work but remained unevaluated.
  - After: score reflects useful ownership/xref documentation, with lower completion/confidence because the exact GUID/IID symbolic names are still unresolved.
  - Evidence: recorded xrefs tie `0x00631610` to browser setup/shutdown, QueryInterface, connection-point advise/unadvise, and browser cleanup paths.
