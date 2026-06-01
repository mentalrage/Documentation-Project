*** UID:0000QB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pBrowserDialogOld

## Status

- Confidence: strong for legacy browser dialog singleton role.
- Current Wave3 kind: `global-data`.
- Current generated owner file: `class_BrowserDialogOld.cpp`.
- IDA/Wave3 storage candidate: `0x0067ab90` (`DAT_0067ab90`).
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md).

## Observed Evidence

Generated `BrowserDialogOld::BrowserDialogOld` writes this global immediately after constructing the `DialogPane` base. The destructor and scalar deleting destructor clear it during legacy browser dialog teardown.

Wave3 notes identify `g_pBrowserDialogOld` as the global singleton for the old browser dialog. The dialog constructs a `BrowserControlPaneOld` child, posts browser private messages `0x500` and `0x501`, and uses the quarter-screen legacy browser layout.

## Ownership Hypothesis

This belongs with the legacy browser dialog/control path. It should migrate with [UID:000018][BrowserDialogOld](by-class/BrowserDialogOld.md), [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md), and [UID:00001A][BrowserThread](by-class/BrowserThread.md).

## Type Hypothesis

Likely declaration:

```cpp
static BrowserDialogOld* g_pBrowserDialogOld;
```

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:000018][BrowserDialogOld](by-class/BrowserDialogOld.md)
- [UID:0000Z3][0x00469290-0x0046963c.BrowserDialogOldCore](by-memory/0x00469290-0x0046963c.BrowserDialogOldCore.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `82/78`. Summary/evidence: the page documents the legacy browser-dialog singleton role, generated constructor/destructor behavior, ownership/type hypothesis, and refs; exact storage confirmation remains less detailed than stronger singleton pages.
