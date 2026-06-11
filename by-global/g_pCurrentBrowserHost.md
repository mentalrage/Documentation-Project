*** UID:0000QO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pCurrentBrowserHost

## Status

- Confidence: strong for browser-owned temporary host-bridge role and exact storage, medium-high for exact final type/linkage.
- IDA storage: [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md), slot `0x0067ab8c` (`dword_67AB8C`)
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md)
- Rebuild handling: `source-authored` browser module static/global storage. The declaration is needed in the rebuilt browser host code, but final C++ remains blank until the pointer type and linkage spelling are proven.

## Observed Evidence

`BrowserThread::InitializeBrowserHost` writes the pending host object into `dword_67AB8C` immediately before creating the browser host window, then clears it after associating the host with the window through `SetWindowLongA`.

IDA xrefs to `0x0067ab8c` are limited to the browser host window path:

- `0x0046fcee` in the browser host window procedure neighborhood.
- `0x00470b3c` and `0x00470be3` in `BrowserThread::InitializeBrowserHost`.

The exact storage page [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md) records this slot as the second browser thread/host global, adjacent to [UID:0000QE][g_pBrowserThread](by-global/g_pBrowserThread.md). [UID:00001A][BrowserThread](by-class/BrowserThread.md) separately records `InitializeBrowserHost` at `0x00470a00-0x00470dc9`, the write/clear sites at `0x00470b3c` and `0x00470be3`, and the browser host creation/COM setup flow. [UID:00032W][0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost](by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md) now carries the exact child method evidence: sole caller from `RunMessageLoop`, Win32/OLE setup calls, COM GUID references, connection-point setup/cleanup, and the navigate handoff.

[UID:000333][0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc](by-memory/0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc.md) records the consumer side: the legacy browser host WndProc obtains the host pointer from `GetWindowLongA(hwnd, -21)` and falls back to `dword_67AB8C` while the host is still being connected. That read pattern explains why this slot is a temporary construction bridge rather than a long-lived active-browser singleton.

## Lifecycle Matrix

| Phase | Evidence | Interpretation |
| --- | --- | --- |
| Storage | [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md) places `dword_67AB8C` beside `g_pBrowserThread`. | Browser module static/global storage, not application-wide state. |
| Publish | `BrowserThread::InitializeBrowserHost` writes the pending host at `0x00470b3c`. | Makes the object visible to the host WndProc during creation. |
| Consume | Legacy browser host WndProc reads the slot at `0x0046fcee` after the `GetWindowLongA(hwnd, -21)` path. | Fallback bridge before user data is installed on the window. |
| Clear | `InitializeBrowserHost` clears the slot at `0x00470be3` after `SetWindowLongA` associates the host with the window. | Confirms temporary scope; normal message handling should use window user data. |
| Source owner | [UID:0000HV][Browser](by-file/Browser.md) owns BrowserThread, BrowserWindow/host helpers, and browser globals. | Direct file parent clears the strict `85/85` gate at `86/88`. |

## Ownership Hypothesis

This is a short-lived construction bridge used by the browser host window procedure while a new `BrowserWindow`/host object is being created.

`AUTOGEN_PARENT_UID` remains [UID:0000HV][Browser](by-file/Browser.md). The slot is file/module-level browser storage rather than a BrowserThread field: the producer is `BrowserThread::InitializeBrowserHost`, but the consumer is a Win32 WndProc callback whose entry signature is not a class method. The direct Browser file parent and this global now both satisfy the corrected strict `85/85` child/direct-parent assignment gate.

## Type Hypothesis

Likely declaration:

```cpp
static BrowserWindow* g_pCurrentBrowserHost;
```

The exact type may be `Browser*`, `BrowserWindow*`, or a host-interface base until the host object layout is finalized.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | Exact storage, producer/consumer/clear sites, temporary lifecycle, BrowserThread method child, legacy WndProc consumer, source owner, and parent gate are documented. |
| Confidence | 87 | Existing IDA-backed docs consistently limit the slot to the browser host creation path. Confidence remains below final-audit quality because the final pointer type and source linkage spelling are still unresolved. |

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:00001A][BrowserThread](by-class/BrowserThread.md)
- [UID:00001B][BrowserWindow](by-class/BrowserWindow.md)
- [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md)
- [UID:000333][0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc](by-memory/0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc.md)
- [UID:00032W][0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost](by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md)
- [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `78/78`. Summary/evidence: the page documents the temporary browser-host bridge role, storage candidate, limited IDA xrefs, owner/type hypotheses, and browser refs; exact final host type remains unresolved.
- 2026-06-05: Marked reconstructable under [UID:0000HV][Browser](by-file/Browser.md). Evidence: live IDA MCP reports three xrefs to `0x0067ab8c`; decompilation confirms `0x00470a00` writes `dword_67AB8C` immediately before browser host window creation, the window procedure at `0x0046fcb0` reads it, and `0x00470a00` clears it after `SetWindowLongA` associates the host object.
- 2026-06-06: Raised to `82/84` after tying the global page to exact storage child [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md) and the stronger [UID:00001A][BrowserThread](by-class/BrowserThread.md) host-initialization evidence. The final declaration remains code-blank because the exact host pointer type and linkage spelling are not yet final-source confidence.
- 2026-06-10 A001 by-global gate refresh:
  - Changed score from `82/84` to `86/87`.
  - Summary/evidence: linked the newer exact BrowserThread host-initialization child [UID:00032W][0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost](by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md) and legacy host WndProc consumer [UID:000333][0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc](by-memory/0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc.md), added a lifecycle matrix for publish/read/clear, and documented why the Browser file parent is the direct source owner under the strict `85/85` gate. No fresh live IDA call was needed; this pass relies on already-written IDA-backed support pages.
