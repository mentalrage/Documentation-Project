*** UID:0000QB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Source declaration for g_pBrowserDialogOld is emitted by [UID:0002WH][0x0067ab90-0x0067ab94.g_pBrowserDialogOld](by-memory/0x0067ab90-0x0067ab94.g_pBrowserDialogOld.md).
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pBrowserDialogOld

## Status

- Confidence: strong for legacy browser dialog singleton role, address/lifetime evidence, and browser source ownership.
- IDA storage: `0x0067ab90` (current active label `unk_67AB90`; older `dword_67AB90`/`DAT_0067ab90` labels are historical).
- Exact storage page: [UID:0002WH][0x0067ab90-0x0067ab94.g_pBrowserDialogOld](by-memory/0x0067ab90-0x0067ab94.g_pBrowserDialogOld.md).
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md).
- Likely type: `BrowserDialogOld*`
- Rebuild handling: source-declared module/global singleton pointer; the exact storage address is linker-generated data for the source declaration.
- Autogen parent: [UID:0000HV][Browser](by-file/Browser.md); the exact storage page now emits the source declaration, while this by-global page remains a symbol/evidence support page with a coverage comment to avoid a duplicate definition.

## Observed Evidence

`BrowserDialogOld::BrowserDialogOld` writes this global immediately after constructing the `DialogPane` base. The ordinary destructor clears it during legacy browser dialog teardown; the scalar deleting destructor wrapper at [UID:00033B][0x004705e0-0x0047068d.BrowserDialogOldScalarDeletingDestructor](by-memory/0x004705e0-0x0047068d.BrowserDialogOldScalarDeletingDestructor.md) repeats that clear as compiler-generated lowering, not as an independent source-owned singleton policy.

B014 MCP session `ddf5b602` rechecked the current IDB state: bytes at `0x0067ab90` and the neighboring browser-dialog singleton slots are zero-filled, `u32le 0x0067ab90 == 0`, there is no recovered `g_pBrowserDialogOld` names/globals row, no local `BrowserDialogOld` UDT, and `trace_data_flow` names the storage as `unk_67AB90`. This supersedes older `0xffffffff` initializer wording while preserving the same eight lifecycle/consumer xrefs.

IDA evidence identifies `g_pBrowserDialogOld` as the global singleton for the old browser dialog. The dialog constructs a `BrowserControlPaneOld` child, posts browser private messages `0x500` and `0x501`, and uses the quarter-screen legacy browser layout.

## Lifetime Evidence

| Site | Use | Evidence owner |
| --- | --- | --- |
| `0x00469290-0x00469426` | Constructor publishes the legacy dialog singleton after base construction and child setup; current exact set/fallback-clear refs are `0x004692ed` and `0x004692f4`. | [UID:0000Z3][0x00469290-0x0046963c.BrowserDialogOldCore](by-memory/0x00469290-0x0046963c.BrowserDialogOldCore.md) and [UID:0002WH][0x0067ab90-0x0067ab94.g_pBrowserDialogOld](by-memory/0x0067ab90-0x0067ab94.g_pBrowserDialogOld.md). |
| `0x00469430-0x0046949c` | Destructor restores vtables, tears down dialog helpers, clears the singleton at `0x0046947d`, and base-cleans. | Same BrowserDialogOld core page and exact storage child. |
| `0x00470230` | Tiny cleanup thunk clears the singleton. | Exact storage child. |
| `0x004705e0` family | Compiler-generated scalar deleting destructor wrapper clears the singleton at `0x00470634`, duplicating ordinary destructor teardown before delete/free mechanics. | [UID:00033B][0x004705e0-0x0047068d.BrowserDialogOldScalarDeletingDestructor](by-memory/0x004705e0-0x0047068d.BrowserDialogOldScalarDeletingDestructor.md). |
| `0x00508da9`, `0x005145f3`, `0x00556fbe` | Non-local consumers compare/use the old-dialog singleton for browser dialog selection or close handling. | Exact storage child records current B014 xref inventory. |
| `0x00469530`, `0x004695b0`, `0x00469620` | Vtable-backed old-dialog key/mouse/navigation methods rely on old browser-thread/control state. | These methods confirm the singleton belongs to the retained legacy browser dialog path. |

## Ownership Hypothesis

This belongs with the legacy browser dialog/control path. It should migrate with [UID:000018][BrowserDialogOld](by-class/BrowserDialogOld.md), [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md), and [UID:00001A][BrowserThread](by-class/BrowserThread.md).

Keep the declaration under [UID:0000HV][Browser](by-file/Browser.md), not generic dialog infrastructure. The old dialog uses `DialogPane`, but its singleton, child construction, private browser messages, and thread/control dependencies are all browser-specific.

## Type Hypothesis

Accepted source declaration, emitted once by [UID:0002WH][0x0067ab90-0x0067ab94.g_pBrowserDialogOld](by-memory/0x0067ab90-0x0067ab94.g_pBrowserDialogOld.md):

```cpp
BrowserDialogOld *g_pBrowserDialogOld;
```

This by-global page uses a formal coverage comment plus `[[CHILDREN]]` insertion marker instead of a duplicate definition. The exact child supplies the declaration during generated assembly; final header/export placement remains a confidence cap.

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
- 2026-07-02 B010 scalar-wrapper clarification:
  - Summary/evidence: clarified that the `0x00470634` clear from [UID:00033B][0x004705e0-0x0047068d.BrowserDialogOldScalarDeletingDestructor](by-memory/0x004705e0-0x0047068d.BrowserDialogOldScalarDeletingDestructor.md) is duplicated compiler lowering of ordinary `BrowserDialogOld::~BrowserDialogOld()` cleanup. The source declaration remains the Browser-owned singleton pointer; the scalar wrapper is non-reconstructable no-code glue.
- 2026-07-04 B014 UID0002WH implementation callback:
  - Changed to: `COMPLETION:88`, `CONFIDENCE:90`, formal coverage comment plus `[[CHILDREN]]` insertion marker to the exact storage child, current active label `unk_67AB90`, current zero-byte evidence, and accepted non-`static` declaration text documented as emitted by [UID:0002WH][0x0067ab90-0x0067ab94.g_pBrowserDialogOld](by-memory/0x0067ab90-0x0067ab94.g_pBrowserDialogOld.md).
  - Summary/evidence: MCP session `ddf5b602` confirms zero-filled storage, no recovered name/global/type rows, eight exact refs, and scalar-wrapper clearing as duplicate compiler lowering. This supersedes older `0xffffffff` and body-blank support wording without duplicating the source definition.
