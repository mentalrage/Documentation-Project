*** UID:0000PO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Source declaration for g_activeBrowserControlPane is emitted by [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_activeBrowserControlPane

## Status

- Confidence: strong for address, lifetime, active `BrowserControlPane *` role, browser owner, exact storage-page definition, and consumer separation; medium-high for exact original header/private-header/accessor spelling.
- IDA storage: `0x0067ab28`. Older C001 work saved `g_activeBrowserControlPane`, but the current B006 live MCP session renders the active worker IDB as `unk_67AB28` / `dword_67AB28`; keep `g_activeBrowserControlPane` as the source-facing name and optional future IDA rename/type target.
- Memory doc: [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md)
- Proposed owner: [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md) / [UID:0000HV][Browser](by-file/Browser.md), exposed to application and surface/presentation helpers.
- Rebuild handling: source-declared module/global pointer storage; the exact `dd ?` slot is linker-generated data for the source declaration.
- Autogen parent: [UID:0000HV][Browser](by-file/Browser.md); this symbol page emits a coverage comment because the exact storage page [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md) now emits the single source definition `BrowserControlPane *g_activeBrowserControlPane;`.

## Observed Evidence

`BrowserControlPane::BrowserControlPane` writes the raw/decompiled `0x0067ab28` storage during construction. Cleanup paths clear the same storage through raw IDA labels or the accepted source-facing `g_activeBrowserControlPane` name; final source should use `g_activeBrowserControlPane`, not `DAT_0067ab28`, `unk_67AB28`, or `dword_67AB28`.

IDA xrefs to `0x0067ab28` include browser constructor/destructor paths, but also broader UI/frame/timer references outside the browser cluster.

2026-05-25 IDA MCP `py_eval` reports `dword_67AB28` as a four-byte `.data` item with 24 direct xrefs. Ten refs are in the browser dense code neighborhood, while later refs around `0x00557140-0x00558601` remain outside the browser source family.

2026-05-26 IDA decompilation narrows the broad refs: `Application::RunMessageLoop` calls `0x0046c550`, which queries the browser active object at `dword_67AB28 + 0x120` for accelerator translation; `SurfacePresentation` / screenshot paths call `sub_46bfd0(dword_67AB28, activeSurface)` and redraw the hosted browser HWND at `dword_67AB28 + 0x11c`. These are cross-module consumers of the active browser control, not evidence for a non-browser owner.
2026-06-05 IDA MCP recheck confirmed xrefs to `0x0067ab28` from browser constructor/destructor paths and application/surface presentation consumers, including the accelerator helper and browser presentation helpers.

2026-06-16 C001 live IDA MCP recheck on session `b001_selflookpane_0001H7_20260616` reconfirmed zero-initialized pointer bytes (`00 00 00 00`), exactly 24 direct xrefs, and the same constructor/destructor/application/presentation spread. The IDB was safely updated from `unk_67AB28` to `g_activeBrowserControlPane`, and the verified lifecycle helpers were labeled `BrowserControlPaneConstructor`, `BrowserControlPaneDestructor`, `ClearActiveBrowserControlPane`, `BrowserControlPaneScalarDeletingDestructor`, and `BrowserControlPaneTranslateAcceleratorMessage`.

2026-06-21 B010 source-quality reanalysis ties this storage directly to [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md): the constructor publishes the active control pane, the ordinary/scalar cleanup paths clear it, `BrowserControlPaneTranslateAcceleratorMessage` reads it to query `m_webBrowser` at object offset `+0x120` for `IID_IOleInPlaceActiveObject`, and presentation/screenshot consumers use it for `BlitBrowserSurfaceToRenderTarget` and hosted-child `HWND` redraw through offset `+0x11c`. This reinforces Browser ownership while requiring a browser header/accessor for non-browser consumers.

2026-07-07 B006 live MCP session `supervisor-nexustk-20260707` rechecked the same target against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` with `server_health: ok`, imagebase `0x400000`, ready auto-analysis, and ready Hex-Rays. The current worker IDB has no live `g_activeBrowserControlPane` name row; `get_global_value` returns `0x0` for `0x0067ab28`, `unk_67AB28`, and `dword_67AB28`, while `g_activeBrowserControlPane` is not found as a live MCP symbol. `get_bytes 0x0067ab1c size 36` returns all zero bytes, `lookup_funcs` confirms `0x0067ab28`/`0x0067ab2c` are not functions, and `xrefs_to`/`xref_query` both report exactly 24 direct data xrefs. Current decompilation confirms constructor publication at `0x0046b58d` and null fallback at `0x0046b594`, ordinary destructor clear at `0x0046ba13`, clear helper `0x00470210`, scalar-wrapper duplicate clear at `0x00470493`, Application/browser guard consumers, and presentation/screenshot redraw consumers.

## Evidence Table

| Site | Use | Interpretation |
| --- | --- | --- |
| `0x0046b58d` / `0x0046b594` | `BrowserControlPaneConstructor` stores active pointer or zero. | BrowserControlPane lifetime owner; exact storage documented by [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md). |
| `0x0046ba13` | [UID:0004DG][0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor](by-memory/0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor.md) clears the pointer. | Source-authored `BrowserControlPane::~BrowserControlPane()` teardown: release hosted browser object, clear the active control pointer, then enter base pane teardown. |
| `0x00470210` | `ClearActiveBrowserControlPane` clear helper writes `0`. | Browser-control cleanup helper, not application ownership. |
| `0x00470493` | [UID:000339][0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor](by-memory/0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor.md) duplicates the clear. | Compiler scalar-deleting wrapper coverage for [UID:0004DG][0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor](by-memory/0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor.md), not separate source ownership. |
| `0x00464d7b`, `0x00464e67`, `0x004660cd` | Application guards/consumer reads. | Message-loop or setup code checks the active browser control through browser-visible storage. |
| `0x0046c575` | `BrowserControlPaneTranslateAcceleratorMessage` reads the pointer. | Browser helper uses the object at `+0x120` for hosted-browser keyboard handling. |
| `0x005571f6` through `0x00558601` cluster | Presentation/screenshot consumers. | Surface presentation sync/redraw paths call browser helpers and use the hosted HWND at `+0x11c`. |

## Ownership Hypothesis

The storage is the active embedded browser control-pane pointer. It is set by the `BrowserControlPane` constructor, cleared by destructor/unwind paths, and read by application/presentation code that must coordinate the hosted browser window with the main message pump and frame presentation.

B008's accepted destructor split resolves the destructor clear route: [UID:0004DG][0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor](by-memory/0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor.md) owns the source-authored ordinary destructor clear at `0x0046ba13`, while [UID:000339][0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor](by-memory/0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor.md) is compiler scalar-delete wrapper coverage with a duplicate clear at `0x00470493`.

The safest source reconstruction is a browser-owned non-static storage definition on [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md), exposed through a browser header/private-header declaration or accessor for non-browser direct users. The exact original header/accessor spelling remains inferred, but the source-facing symbol name and storage type are now strong enough for the exact storage page to emit.

Do not move this storage into `Application`, `Surface`, screenshot, or generic UI-core ownership. Those modules are confirmed consumers; the constructor/destructor writes and active browser-control object offsets make the declaration browser-owned.

## Accepted Type And Emission Model

Accepted source-facing storage definition on the exact by-memory page:

```cpp
BrowserControlPane *g_activeBrowserControlPane;
```

Do not emit a duplicate definition on this by-global page. This page is the semantic symbol/evidence record and emits only the formal coverage comment to [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md). Do not use the former `static BrowserControlPane*` hypothesis as the default source form: Application and presentation/screenshot code directly read the slot, so a file-local definition would be wrong unless a later source rewrite replaces those direct consumers with a browser accessor.

## Follow-Up

- Keep `g_activeBrowserControlPane` as the source-facing storage label and optional future IDA rename/type target unless a later final-source audit proves a different exported name.
- The application accelerator helper at `0x0046c550` is now labeled; the presentation/browser-sync call at `0x0046bfd0` still needs a final source-quality helper name.
- B010 best-names the presentation/browser-sync helper at `0x0046bfd0` as `BrowserControlPane::BlitBrowserSurfaceToRenderTarget` / `CopyBrowserSurfaceToTarget`; exact render-surface parameter types remain the remaining source-quality caveat.
- During source reconstruction, avoid hiding the cross-module consumers; they likely need a browser header declaration or a small accessor.
- Do not duplicate the storage definition here; exact storage emission is owned by [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md).

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md)
- [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md)
- [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md)
- [UID:0004DG][0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor](by-memory/0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor.md)
- [UID:000339][0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor](by-memory/0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor.md)
- [UID:00020U][0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage](by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md)
- [UID:000212][0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks](by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md) is a direct active-browser consumer at `0x0046e964`: `WebBoardDialogOld::HandlePointerOrMouseEvent(Event *)` loads `g_activeBrowserControlPane`, reads `BrowserControlPane::m_browserHostHwnd` at object offset `+0x11c`, and passes that hosted child `HWND` to `GetClientRect`. This is consumer evidence only; it does not move source ownership or the single definition away from [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md).

## Changes

- 2026-08-03 B002 UID000212 implementation callback:
  - Score and formals remain `89/92`, the exact-storage coverage comment, and blank H.
  - Added the direct old-dialog consumer at `0x0046e964`, including the exact `m_browserHostHwnd +0x11c` hosted-window read and the ownership boundary that keeps the definition on UID0001P3.

- 2026-06-06 A010 evidence consolidation:
  - Before: `COMPLETION:82`, `CONFIDENCE:78`, with broad xref notes but no lifecycle/consumer table, rebuild-handling classification, or explicit source-gate note.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`, source-declared storage handling, autogen/source-gate note, detailed constructor/destructor/application/presentation evidence table, and clearer owner separation from application/surface consumers.
  - Summary/evidence: [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md) records the exact `dd ?` storage, 24 direct xrefs, constructor writes at `0x0046b58d`/`0x0046b594`, teardown clears at `0x0046ba13`, `0x00470210`, and `0x00470493`, and app/presentation consumer clusters. Confidence remains below final-audit because the final exported declaration/accessor shape is unresolved.
- 2026-06-16 C001 global/IDA refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:86`.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:90`.
  - Evidence: live IDA MCP reconfirmed zero-initialized storage bytes, 24 direct xrefs, constructor/destructor/clear-helper writes, application and presentation consumers, and accelerator behavior. Applied and saved safe IDA labels for the storage plus five verified lifecycle/accelerator functions. Final C++ remained blank in that historical pass because the exported declaration/accessor and `0x0046bfd0` presentation helper name were still treated as source-quality blockers; the 2026-07-07 B006 source-quality implementation below supersedes that blank-C++ disposition with coverage-comment handling on this by-global page and the exact definition on UID0001P3.
- 2026-06-21 B010 BrowserControlPane core sync:
  - Added source-quality closure tying this global to the resolved BrowserControlPane field layout, `BrowserControlPaneTranslateAcceleratorMessage`, and `BlitBrowserSurfaceToRenderTarget`/hosted-HWND presentation consumers while retaining the exported declaration/accessor caveat.
- 2026-07-02 B008 destructor split implementation:
  - Score unchanged at `88/90`.
  - Summary/evidence: separated the source-authored ordinary destructor clear at `0x0046ba13` on [UID:0004DG][0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor](by-memory/0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor.md) from the duplicate scalar-wrapper clear at `0x00470493` on [UID:000339][0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor](by-memory/0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor.md).
- 2026-07-07 B006 source-quality implementation:
  - Raised from `88/90` to `89/92`; owner/emitter/reconstructable remain [UID:0000HV][Browser](by-file/Browser.md), [UID:0000HV][Browser](by-file/Browser.md), and `TRUE`.
  - Formal C++ now emits a coverage comment to exact storage page [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md), which emits `BrowserControlPane *g_activeBrowserControlPane;`.
  - Summary/evidence: accepted B006 report `0001P3-g_activeBrowserControlPane-source-quality.md` and MCP session `supervisor-nexustk-20260707` confirm zero-filled storage/value `0x0`, not-a-function status, exactly 24 xrefs, constructor publish/null fallback, ordinary destructor clear, clear helper, scalar wrapper duplicate clear, Application/browser guard consumers, presentation/screenshot consumers, and current live-IDB `unk_67AB28` / `dword_67AB28` label caveat. The former `static BrowserControlPane*` hypothesis is rejected unless future source rewrite replaces direct non-Browser consumers with an accessor.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `82/78`. Summary/evidence: the page documents storage, browser constructor/destructor writes, cross-module consumers, type hypothesis, and follow-up items; exact exported name and source split remain provisional.
- 2026-06-05: Marked reconstructable and attached to [UID:0000HV][Browser](by-file/Browser.md).
  - Reason: live IDA MCP recheck confirms this is source-declared active browser-control storage written by browser lifetime code and consumed by application/surface bridge paths through browser headers or accessors.
