*** UID:0000QB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pBrowserDialogOld

## Status

- Confidence: strong for legacy browser dialog singleton role, address/lifetime evidence, and browser source ownership.
- IDA storage: `0x0067ab90` (`dword_67AB90` / `DAT_0067ab90`).
- Exact storage page: [UID:0002WH][0x0067ab90-0x0067ab94.g_pBrowserDialogOld](by-memory/0x0067ab90-0x0067ab94.g_pBrowserDialogOld.md).
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md).
- Likely type: `BrowserDialogOld*`
- Rebuild handling: source-declared module/global singleton pointer; the exact storage address is linker-generated data for the source declaration.
- Autogen parent: [UID:0000HV][Browser](by-file/Browser.md); C++ remains blank because final declaration placement and old-browser source split are below the `95+` source gate.

## Observed Evidence

`BrowserDialogOld::BrowserDialogOld` writes this global immediately after constructing the `DialogPane` base. The destructor and scalar deleting destructor clear it during legacy browser dialog teardown.

IDA evidence identifies `g_pBrowserDialogOld` as the global singleton for the old browser dialog. The dialog constructs a `BrowserControlPaneOld` child, posts browser private messages `0x500` and `0x501`, and uses the quarter-screen legacy browser layout.

## Lifetime Evidence

| Site | Use | Evidence owner |
| --- | --- | --- |
| `0x00469290-0x00469426` | Constructor publishes the legacy dialog singleton after base construction and child setup. | [UID:0000Z3][0x00469290-0x0046963c.BrowserDialogOldCore](by-memory/0x00469290-0x0046963c.BrowserDialogOldCore.md). |
| `0x00469430-0x0046949c` | Destructor restores vtables, tears down dialog helpers, clears the singleton, and base-cleans. | Same BrowserDialogOld core page. |
| `0x004705e0` family | Teardown/scalar path clears the singleton. | Browser legacy cleanup path referenced by the current page's 2026-06-05 IDA recheck. |
| `0x00469530`, `0x004695b0`, `0x00469620` | Vtable-backed old-dialog key/mouse/navigation methods rely on old browser-thread/control state. | These methods confirm the singleton belongs to the retained legacy browser dialog path. |

## Ownership Hypothesis

This belongs with the legacy browser dialog/control path. It should migrate with [UID:000018][BrowserDialogOld](by-class/BrowserDialogOld.md), [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md), and [UID:00001A][BrowserThread](by-class/BrowserThread.md).

Keep the declaration under [UID:0000HV][Browser](by-file/Browser.md), not generic dialog infrastructure. The old dialog uses `DialogPane`, but its singleton, child construction, private browser messages, and thread/control dependencies are all browser-specific.

## Type Hypothesis

Likely declaration:

```cpp
static BrowserDialogOld* g_pBrowserDialogOld;
```

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:000018][BrowserDialogOld](by-class/BrowserDialogOld.md)
- [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md)
- [UID:00001A][BrowserThread](by-class/BrowserThread.md)
- [UID:0000Z3][0x00469290-0x0046963c.BrowserDialogOldCore](by-memory/0x00469290-0x0046963c.BrowserDialogOldCore.md)
- [UID:0002WH][0x0067ab90-0x0067ab94.g_pBrowserDialogOld](by-memory/0x0067ab90-0x0067ab94.g_pBrowserDialogOld.md)
- [UID:0000QE][g_pBrowserThread](by-global/g_pBrowserThread.md)

## Changes

- 2026-06-06 A010 legacy singleton evidence consolidation:
  - Before: `COMPLETION:82`, `CONFIDENCE:78`, with the singleton role and constructor/destructor behavior summarized but limited exact-lifetime detail.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`, likely pointer type, source-declared storage handling, autogen/source-gate note, lifetime evidence table, and stronger browser-vs-generic-dialog ownership rationale.
  - Summary/evidence: [UID:0000Z3][0x00469290-0x0046963c.BrowserDialogOldCore](by-memory/0x00469290-0x0046963c.BrowserDialogOldCore.md) documents the exact old-dialog constructor/destructor range, vtable slots, child BrowserControlPaneOld construction, `g_pBrowserDialogOld` set/clear behavior, private browser message paths, and padding boundaries. Confidence remains below final-audit because old-browser source split and final declaration placement are still open.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `82/78`. Summary/evidence: the page documents the legacy browser-dialog singleton role, constructor/destructor behavior, ownership/type hypothesis, and refs; exact storage confirmation remains less detailed than stronger singleton pages.
- 2026-06-05: Marked reconstructable under [UID:0000HV][Browser](by-file/Browser.md). Evidence: live IDA MCP reports eight xrefs to `0x0067ab90`; decompilation confirms `0x00469290` writes `dword_67AB90` during old browser-dialog construction and `0x004705e0` clears it during teardown.
- 2026-06-07 A004 Batch 046 split:
  - Before: this global page named the storage address but did not link an exact by-memory storage child.
  - Changed to: linked [UID:0002WH][0x0067ab90-0x0067ab94.g_pBrowserDialogOld](by-memory/0x0067ab90-0x0067ab94.g_pBrowserDialogOld.md).
  - Summary/evidence: the exact child records the initialized four-byte storage, eight refs, constructor stores, destructor/cleanup clears, and direct assignment back to this global page.
