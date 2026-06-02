*** UID:0000T2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Containing data range: [UID:000272][0x00631570-0x00632560.BrowserComGuidReadOnlyData](by-memory/0x00631570-0x00632560.BrowserComGuidReadOnlyData.md)

## Observed Evidence

Generated `BrowserControlPane::ShutdownBrowserWindow` and related setup code name this value `IID_BrowserEventSink`. IDA xrefs to `0x00631610` include browser host setup, shutdown, `QueryInterface`, connection-point advise/unadvise, and browser object cleanup:

- `0x00469b02` in `BrowserWindow::ShutdownBrowserWindow`.
- `0x0046bb14` in `BrowserControlPane::ShutdownBrowserWindow`.
- `0x0046c73a` in `BrowserControlPane::QueryInterface`.
- `0x0046f4e9` and `0x0046f5fc` in the legacy `Browser` object.
- `0x00470cba` and `0x00470d61` in `BrowserThread::InitializeBrowserHost`.

Neighboring COM id constants in the same generated owner include `DAT_006315a0`, `DAT_006315d0`, `DAT_00631600`, and `DAT_00631620`. Generated `BrowserControlPane` also has `kSlot*InterfaceId` arrays that likely describe the same multi-interface COM object layout.

## Reconstruction Evidence

- [UID:0000HV][Browser](by-file/Browser.md) is scored `84/88`, has the valid proposed path `NexusTK/browser/`, and explicitly classifies this symbol as browser COM data.
- [UID:000272][0x00631570-0x00632560.BrowserComGuidReadOnlyData](by-memory/0x00631570-0x00632560.BrowserComGuidReadOnlyData.md) covers the surrounding browser/OLE GUID and COM interface-map data, is reconstructable, and is attached to [UID:0000HV][Browser](by-file/Browser.md).
- [UID:0001OB][0x006131b4-0x006139df.BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md) records browser COM GUID inspection around `0x00631580-0x00631640` and links this global to the broader browser `.rdata` island.
- [UID:000218][0x004710e0-0x0047110e.BrowserGuidCompareHelper](by-memory/0x004710e0-0x0047110e.BrowserGuidCompareHelper.md) documents the 16-byte GUID/IID comparison helper used by BrowserWindow, BrowserControlPane, and Browser `QueryInterface` paths.
- The symbol remains below final-source quality because the actual 16-byte GUID value and exact public symbolic name still need value-by-value identification against COM/browser interface IDs.

## Autogen Status

- Reconstructable: true. The rebuilt browser module needs named GUID/IID declarations or equivalent COM interface-map declarations for this data.
- Parent: [UID:0000HV][Browser](by-file/Browser.md). The containing browser GUID range and owner file both support this attachment.
- Code: intentionally blank. Do not emit a GUID declaration until the exact GUID value and final symbolic name are confirmed.

## Score Rationale

- Completion is raised to 74 because storage, owner, containing GUID range, browser xrefs, neighboring constants, and follow-up naming work are documented.
- Confidence is raised to 82 for browser ownership and reconstructability because the containing data page, browser file page, vtable/string data page, and GUID compare helper all agree on browser/OLE usage.
- Confidence remains capped by unresolved GUID identity: `IID_BrowserEventSink` may be a custom IID, an event-sink alias, or a generated name over a standard COM/browser event IID.

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
- [UID:000272][0x00631570-0x00632560.BrowserComGuidReadOnlyData](by-memory/0x00631570-0x00632560.BrowserComGuidReadOnlyData.md)
- [UID:000218][0x004710e0-0x0047110e.BrowserGuidCompareHelper](by-memory/0x004710e0-0x0047110e.BrowserGuidCompareHelper.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `64/74`.
  - Before: page documented browser COM IID role, storage candidate, xrefs, neighboring constants, and follow-up naming work but remained unevaluated.
  - After: score reflects useful ownership/xref documentation, with lower completion/confidence because the exact GUID/IID symbolic names are still unresolved.
  - Evidence: recorded xrefs tie `0x00631610` to browser setup/shutdown, QueryInterface, connection-point advise/unadvise, and browser cleanup paths.
- 2026-06-02: Raised to `74/82`, marked reconstructable, attached to [UID:0000HV][Browser](by-file/Browser.md), and added containing GUID-range, browser data, GUID-compare helper, autogen, and score-rationale evidence. C++ remains blank until the exact GUID value/name is identified.
