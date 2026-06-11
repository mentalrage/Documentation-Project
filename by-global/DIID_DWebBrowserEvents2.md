*** UID:0000T2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DIID_DWebBrowserEvents2

## Status

- Confidence: strong for browser COM event-sink role, Browser ownership, storage/xref set, exact value, and standard symbolic identity.
- IDA storage: `0x00631610` (`unk_631610` in IDA decompilation)
- Previous working name: `IID_BrowserEventSink`
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md)
- Containing data range: [UID:000272][0x00631570-0x00632560.BrowserComGuidReadOnlyData](by-memory/0x00631570-0x00632560.BrowserComGuidReadOnlyData.md)

## Observed Evidence

The GUID-sized value at `0x00631610` is the standard `DIID_DWebBrowserEvents2` dispatch event interface id:

```text
bytes: a0 15 a7 34 87 65 d0 11 92 4a 00 20 af c7 ac 4d
guid:  34a715a0-6587-11d0-924a-0020afc7ac4d
```

IDA xrefs to `0x00631610` include browser host setup, shutdown, `QueryInterface`, connection-point advise/unadvise, and browser object cleanup:

- `0x00469908` and `0x00469989` in BrowserWindow setup/query paths.
- `0x00469b02` in `BrowserWindow::ShutdownBrowserWindow`.
- `0x0046a023` in `BrowserWindow::QueryInterface`.
- `0x0046b88a` and `0x0046b914` in BrowserControlPane setup/query paths.
- `0x0046bb14` in `BrowserControlPane::ShutdownBrowserWindow`.
- `0x0046c73a` in `BrowserControlPane::QueryInterface`.
- `0x0046f4e9` and `0x0046f5fc` in the legacy `Browser` object.
- `0x00470399` in the Browser scalar-deleting cleanup path.
- `0x00470cba` and `0x00470d61` in `BrowserThread::InitializeBrowserHost`.

Neighboring COM id constants in the same browser/OLE data range now decode to standard browser/OLE values including `IID_IUnknown`, `IID_IOleClientSite`, `IID_IOleObject`, `IID_IOleInPlaceObject`, `IID_IDispatch`, `IID_IWebBrowser2`, `CLSID_WebBrowser`, `IID_IDocHostUIHandler`, and `IID_IDocHostShowUI`. The adjacent COM map/interface constants likely describe the same multi-interface browser host/control layout.

## Reconstruction Evidence

- [UID:0000HV][Browser](by-file/Browser.md) is scored `86/88`, has the valid proposed path `NexusTK/browser/`, and explicitly classifies this symbol as browser COM data.
- [UID:000272][0x00631570-0x00632560.BrowserComGuidReadOnlyData](by-memory/0x00631570-0x00632560.BrowserComGuidReadOnlyData.md) covers the surrounding browser/OLE GUID and COM interface-map data, is reconstructable, and is attached to [UID:0000HV][Browser](by-file/Browser.md).
- [UID:0001OB][0x006131b4-0x006139df.BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md) records browser COM GUID inspection around `0x00631580-0x00631640` and links this global to the broader browser `.rdata` island.
- [UID:000218][0x004710e0-0x0047110e.BrowserGuidCompareHelper](by-memory/0x004710e0-0x0047110e.BrowserGuidCompareHelper.md) documents the 16-byte GUID/IID comparison helper used by BrowserWindow, BrowserControlPane, and Browser `QueryInterface` paths.
- [UID:00001A][BrowserThread](by-class/BrowserThread.md) records host initialization references to browser COM GUID data at `0x006315a0`, `0x006315d0`, `0x00631600`, `0x00631610`, and `0x00631620`, followed by connection-point advise/unadvise calls in the same setup/cleanup flow.
- [UID:00001B][BrowserWindow](by-class/BrowserWindow.md) links this IID global with the BrowserWindow `QueryInterface` path and the browser COM helper memory pages.
- The old `IID_BrowserEventSink` working name is retired in favor of `DIID_DWebBrowserEvents2`; source reconstruction should still decide whether to reference the SDK declaration or provide a local static GUID declaration.

## Autogen Status

- Reconstructable: true. The rebuilt browser module needs named GUID/IID declarations or equivalent COM interface-map declarations for this data.
- Parent: [UID:0000HV][Browser](by-file/Browser.md). The containing browser GUID range and owner file both support this attachment.
- Code: intentionally blank. The exact value/name are now confirmed, but final source should choose between SDK-provided declarations and local static declarations during the COM header pass.

## Score Rationale

- Completion is raised to 88 because storage, exact bytes, standard GUID identity, Browser owner, containing GUID range, xrefs, neighboring constants, and declaration-policy caveat are documented.
- Confidence is raised to 92 for browser ownership and reconstructability because current IDA bytes/xrefs identify the value as `DIID_DWebBrowserEvents2`, and the containing data page, browser file page, vtable/string data page, GUID compare helper, BrowserThread host-initialization page, and BrowserWindow/BrowserControlPane/Browser class pages all agree on browser/OLE usage.
- Confidence remains below final-audit quality only because final source declaration policy and the surrounding interface-map tail still need the later COM header pass.

## Ownership

The browser COM IIDs should be referenced or declared near the browser host/control COM interface declarations, likely in `browser/Browser.cpp` with private/static linkage or in `browser/Browser.h` if class declarations need them. `DIID_DWebBrowserEvents2` is standard WebBrowser event-sink data, not a NexusTK-custom IID.

## Follow-Up

- Decide whether final reconstructed source should include a local `DIID_DWebBrowserEvents2` definition or rely on the platform/SDK declaration.
- Continue naming interface-map records after the primary GUID band in [UID:000272][0x00631570-0x00632560.BrowserComGuidReadOnlyData](by-memory/0x00631570-0x00632560.BrowserComGuidReadOnlyData.md).

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
- 2026-06-06: Raised to `80/84`, removed generated/Wave authority wording, and added BrowserThread host-initialization plus BrowserWindow `QueryInterface` support. C++ remains blank because the exact 16-byte GUID value and final source symbol are still unresolved.
- 2026-06-08 A007 Batch 106 GUID identification:
  - Renamed page from `IID_BrowserEventSink` to `DIID_DWebBrowserEvents2`.
  - Raised score from `80/84` to `88/92`.
  - Evidence: read-only IDA MCP decoded `0x00631610` as bytes `a0 15 a7 34 87 65 d0 11 92 4a 00 20 af c7 ac 4d`, GUID `34a715a0-6587-11d0-924a-0020afc7ac4d`, and reconfirmed 13 browser setup/shutdown/query/advise/cleanup xrefs. The neighboring GUID band was also identified as standard COM/OLE/WebBrowser IDs, so the old provisional event-sink name is no longer needed.
