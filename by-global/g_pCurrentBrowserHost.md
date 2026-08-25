*** UID:0000QO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Source declaration for g_pCurrentBrowserHost is emitted by [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pCurrentBrowserHost

## Status

- Confidence: strong for browser-owned temporary host-bridge role, exact storage, and `Browser *` type; medium-high for exact original declaration/linkage spelling.
- Active IDA MCP label: `unk_67AB8C` in B010 accepted session `80de0a67`.
- Source-facing reconstruction name: `g_pCurrentBrowserHost`.
- IDA storage: [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md), slot `0x0067ab8c`; older docs may mention a saved label, but the active B010 MCP session renders the slot as `unk_67AB8C`.
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md)
- Rebuild handling: `source-authored` browser module static/global storage. The accepted first-draft declaration is emitted by the paired storage page [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md) as `static Browser *g_pCurrentBrowserHost;`. This symbol page remains the per-global evidence record and should not duplicate the paired declaration unless the emitter strategy changes.
- Formal output for this symbol page is therefore a source-coverage comment to [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md), not a duplicate declaration.

## Observed Evidence

`BrowserThread::InitializeBrowserHost` writes the pending host object into the active `unk_67AB8C` / source-facing `g_pCurrentBrowserHost` slot immediately before creating the browser host window, then clears it after associating the host with the window through `SetWindowLongA`.

IDA xrefs to `0x0067ab8c` are limited to the browser host window path:

- `0x0046fcee` in the browser host window procedure neighborhood.
- `0x00470b3c` and `0x00470be3` in `BrowserThread::InitializeBrowserHost`.

2026-06-27 B010 accepted live MCP session `80de0a67` confirms exactly these three refs and no active saved data label:

| Address | Function/context | Meaning |
| --- | --- | --- |
| `0x0046fcee` | [UID:000333][0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc](by-memory/0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc.md) | Fallback read after `GetWindowLongA(hwnd, GWL_USERDATA)` returns null during early host setup. |
| `0x00470b3c` | [UID:00032W][0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost](by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md) | Publishes `[BrowserThread + 0x68]`, the legacy `Browser` object pointer, before the host HWND has user data. |
| `0x00470be3` | [UID:00032W][0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost](by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md) | Clears the bridge after `SetWindowLongA(hwnd, GWL_USERDATA, browser)` installs the same pointer on the HWND. |

The B010 accepted pass also rechecked zero-filled bytes over the surrounding Browser pointer neighborhood and found the active IDB name `unk_67AB8C`; `g_pCurrentBrowserHost` is the source-facing reconstruction name.

The exact storage page [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md) records this slot as the second browser thread/host global, adjacent to [UID:0000QE][g_pBrowserThread](by-global/g_pBrowserThread.md). [UID:00001A][BrowserThread](by-class/BrowserThread.md) separately records `InitializeBrowserHost` at `0x00470a00-0x00470dc9`, the write/clear sites at `0x00470b3c` and `0x00470be3`, and the browser host creation/COM setup flow. [UID:00032W][0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost](by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md) now carries the exact child method evidence: sole caller from `RunMessageLoop`, Win32/OLE setup calls, COM GUID references, connection-point setup/cleanup, and the navigate handoff.

[UID:000333][0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc](by-memory/0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc.md) records the consumer side: the legacy browser host WndProc obtains the host pointer from `GetWindowLongA(hwnd, -21)` and falls back to the current-host bridge while the host is still being connected. That read pattern explains why this slot is a temporary construction bridge rather than a long-lived active-browser singleton.

2026-06-16 C001 live IDA MCP saved `g_pCurrentBrowserHost`, `BrowserLegacyHostWndProc`, and `BrowserThread_InitializeBrowserHost`. Current `get_bytes 0x0067ab80 size 0x14` shows zero-filled storage across the browser/thread pointer neighborhood. `xrefs_to 0x0067ab8c` still reports only the three setup-bridge refs: fallback read at `0x0046fcee`, publish at `0x00470b3c`, and clear at `0x00470be3`. Fresh decompilation of the saved functions shows the WndProc first tries `GetWindowLongA(hwnd, -21)`, then falls back to this global, while `BrowserThread_InitializeBrowserHost` writes the pending host object before `CreateWindowExA` and clears it immediately after `SetWindowLongA`.

2026-06-21 B010 Rule 26 reanalysis sharpens the type evidence for the [UID:000333][0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc](by-memory/0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc.md) path: local PE recheck of `BrowserThread::InitializeBrowserHost` shows `[BrowserThread + 0x68]` published to `0x0067ab8c` at `0x00470b3c`, stored into window user data through `SetWindowLongA(hwnd, GWL_USERDATA, browser)` at `0x00470bd5`, and cleared at `0x00470be3`. [UID:00033K][0x00470dd0-0x00470f10.BrowserNavigate](by-memory/0x00470dd0-0x00470f10.BrowserNavigate.md) and [UID:000013][Browser](by-class/Browser.md) identify `BrowserThread +0x68` as the legacy `Browser` object. For this callback path, treat the bridge as `Browser *g_pCurrentBrowserHost` or the project-approved legacy Browser host pointer spelling, not as an equally likely `BrowserWindow *`.

2026-06-27 B010 accepted implementation locks this path down for first-draft C++: the paired storage page [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md) now emits `static Browser *g_pCurrentBrowserHost;` next to `static BrowserThread *g_pBrowserThread;`. Exact original linkage and header/source split remain open, but the behavior and type are no longer blockers.

## Lifecycle Matrix

| Phase | Evidence | Interpretation |
| --- | --- | --- |
| Storage | [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md) places `unk_67AB8C` / `g_pCurrentBrowserHost` beside `g_pBrowserThread`. | Browser module static/global storage, not application-wide state. |
| Publish | `BrowserThread::InitializeBrowserHost` writes the pending host at `0x00470b3c`. | Makes the object visible to the host WndProc during creation. |
| Consume | Legacy browser host WndProc reads the slot at `0x0046fcee` after the `GetWindowLongA(hwnd, -21)` path. | Fallback bridge before user data is installed on the window. |
| Clear | `InitializeBrowserHost` clears the slot at `0x00470be3` after `SetWindowLongA` associates the host with the window. | Confirms temporary scope; normal message handling should use window user data. |
| Source owner | [UID:0000HV][Browser](by-file/Browser.md) owns BrowserThread, BrowserWindow/host helpers, and browser globals. | Direct file parent clears the strict `85/85` gate at `86/88`. |

## Ownership Hypothesis

This is a short-lived construction bridge used by the browser host window procedure while a new legacy `Browser` host object is being connected to its HWND.

The owner/emitter route remains [UID:0000HV][Browser](by-file/Browser.md). The slot is file/module-level browser storage rather than a BrowserThread field: the producer is `BrowserThread::InitializeBrowserHost`, but the consumer is a Win32 WndProc callback whose entry signature is not a class method. The direct Browser file parent and this global satisfy the corrected strict child/direct-parent assignment gate.

## Type Hypothesis

Current best declaration shape for the [UID:000333][0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc](by-memory/0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc.md) path:

```cpp
static Browser *g_pCurrentBrowserHost;
```

The declaration is now first-draft ready through [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md). The exact source spelling may still use a legacy host typedef/base name depending on final Browser headers, but `BrowserWindow *` should no longer be presented as an equally likely type for this slot because the producer publishes the `BrowserThread +0x68` Browser object and this callback reads Browser fields `+0x14`/`+0x18`.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | Exact storage, producer/consumer/clear sites, temporary lifecycle, BrowserThread method child, legacy WndProc consumer, source owner, and parent gate are documented. |
| Confidence | 87 | Existing IDA-backed docs consistently limit the slot to the browser host creation path. This older score was capped by then-open pointer-type and source-linkage questions; the later B010 result resolves the source-facing type as `Browser *` and leaves only exact original linkage/source split open. |

Updated score after the 2026-06-16 safe IDA refresh:

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 87 | Adds current storage bytes, saved IDA labels, exact current xref inventory, and fresh producer/consumer/clear decompilation. |
| Confidence | 90 | Current IDA bytes, exact three-ref inventory, and matching producer/consumer decompilation make the temporary bridge semantics very strong. Confidence stays below final audit because exact original source declaration spelling/linkage and the final browser source split are still unresolved; the best current type for this path is `Browser *`. |

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:00001A][BrowserThread](by-class/BrowserThread.md)
- [UID:00001B][BrowserWindow](by-class/BrowserWindow.md)
- [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md)
- [UID:000333][0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc](by-memory/0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc.md)
- [UID:00032W][0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost](by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md)
- [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md)

## Changes

- 2026-06-29 B002 Browser empty-emitter first-batch implementation:
  - Score unchanged at `87/90`.
  - Summary/evidence: inserted formal coverage comment `// Source declaration for g_pCurrentBrowserHost is emitted by [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md).` This resolves the empty emitter without duplicating the paired storage declaration `static Browser *g_pCurrentBrowserHost;` already emitted by [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md).
- 2026-06-27 B010 accepted implementation callback:
  - Summary/evidence: updated active IDA label state to `unk_67AB8C` from MCP session `80de0a67`, recorded the exact three-xref inventory, and marked the source-facing declaration `static Browser *g_pCurrentBrowserHost;` first-draft ready through the paired storage emitter [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md).
  - Source-quality disposition: keep Browser file ownership/emission through [UID:0000HV][Browser](by-file/Browser.md); reject persistent `BrowserWindow *`, `BrowserThread *`, PlatformApi ownership, and long-lived active-browser singleton interpretations for this path. The remaining uncertainty is exact original linkage/source split, not behavior or pointer type.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `78/78`. Summary/evidence: the page documents the temporary browser-host bridge role, storage candidate, limited IDA xrefs, owner/type hypotheses, and browser refs; exact final host type was unresolved at that time and is superseded by the later `Browser *` route evidence.
- 2026-06-05: Marked reconstructable under [UID:0000HV][Browser](by-file/Browser.md). Evidence: live IDA MCP reports three xrefs to `0x0067ab8c`; decompilation confirms `0x00470a00` writes `dword_67AB8C` immediately before browser host window creation, the window procedure at `0x0046fcb0` reads it, and `0x00470a00` clears it after `SetWindowLongA` associates the host object.
- 2026-06-06: Raised to `82/84` after tying the global page to exact storage child [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md) and the stronger [UID:00001A][BrowserThread](by-class/BrowserThread.md) host-initialization evidence. The final declaration remains code-blank because the exact host pointer type and linkage spelling are not yet final-source confidence.
- 2026-06-10 A001 by-global gate refresh:
  - Changed score from `82/84` to `86/87`.
  - Summary/evidence: linked the newer exact BrowserThread host-initialization child [UID:00032W][0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost](by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md) and legacy host WndProc consumer [UID:000333][0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc](by-memory/0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc.md), added a lifecycle matrix for publish/read/clear, and documented why the Browser file parent is the direct source owner under the strict `85/85` gate. No fresh live IDA call was needed; this pass relies on already-written IDA-backed support pages.
- 2026-06-16 C001 safe IDA refresh:
  - Before: `86/87`, with generic IDA labels for the bridge storage, host WndProc, and initialize helper in the active IDB.
  - Changed to: `87/90`; saved `g_pCurrentBrowserHost`, `BrowserLegacyHostWndProc`, and `BrowserThread_InitializeBrowserHost`.
  - Summary/evidence: live IDA reconfirmed zero-filled storage, exactly three direct xrefs, the write-before-window-create/read-as-WndProc-fallback/clear-after-SetWindowLongA lifecycle, and Browser file ownership. Final C++ remained blank at that time because the precise source declaration spelling and pointer type were not final; the pointer type is now resolved as `Browser *` for the accepted first draft.
- 2026-06-21 B010 Rule 26 type-route sync:
  - Summary/evidence: local PE reanalysis for [UID:000333][0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc](by-memory/0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc.md) shows the slot publishes `BrowserThread +0x68`, the same Browser object later stored into `GWL_USERDATA`; the best source-facing type is therefore `Browser *` or a legacy Browser host typedef, while `BrowserWindow *` is rejected for this path.
