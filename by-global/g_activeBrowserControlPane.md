*** UID:0000PO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_activeBrowserControlPane

## Status

- Confidence: strong for address, lifetime, active `BrowserControlPane*` role, and browser owner; medium-high for final exported name/source split.
- IDA storage candidate: `0x0067ab28` (`DAT_0067ab28` / `g_activeBrowserControlPane` alias family).
- Memory doc: [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md)
- Proposed owner: [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md) / [UID:0000HV][Browser](by-file/Browser.md), exposed to application and surface/presentation helpers.
- Rebuild handling: source-declared module/global pointer storage; the exact `dd ?` slot is linker-generated data for the source declaration.
- Autogen parent: [UID:0000HV][Browser](by-file/Browser.md); C++ remains blank because the final exported declaration/accessor split is below the `95+` source gate.

## Observed Evidence

`BrowserControlPane::BrowserControlPane` writes `DAT_0067ab28 = this` during construction. Cleanup paths clear the same storage through either `DAT_0067ab28` or `g_activeBrowserControlPane` aliases.

IDA xrefs to `0x0067ab28` include browser constructor/destructor paths, but also broader UI/frame/timer references outside the browser cluster.

2026-05-25 IDA MCP `py_eval` reports `dword_67AB28` as a four-byte `.data` item with 24 direct xrefs. Ten refs are in the browser dense code neighborhood, while later refs around `0x00557140-0x00558601` remain outside the browser source family.

2026-05-26 IDA decompilation narrows the broad refs: `Application::RunMessageLoop` calls `0x0046c550`, which queries the browser active object at `dword_67AB28 + 0x120` for accelerator translation; `SurfacePresentation` / screenshot paths call `sub_46bfd0(dword_67AB28, activeSurface)` and redraw the hosted browser HWND at `dword_67AB28 + 0x11c`. These are cross-module consumers of the active browser control, not evidence for a non-browser owner.
2026-06-05 IDA MCP recheck confirmed xrefs to `0x0067ab28` from browser constructor/destructor paths and application/surface presentation consumers, including `sub_46C550` and browser presentation helpers.

## Evidence Table

| Site | Use | Interpretation |
| --- | --- | --- |
| `0x0046b58d` / `0x0046b594` | Constructor stores active pointer or zero. | BrowserControlPane lifetime owner; exact storage documented by [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md). |
| `0x0046ba13`, `0x00470210`, `0x00470493` | Destructor/cleanup/scalar paths clear the pointer. | Browser-control teardown, not application ownership. |
| `0x00464d7b`, `0x00464e67`, `0x004660cd` | Application guards/consumer reads. | Message-loop or setup code checks the active browser control through browser-visible storage. |
| `0x0046c575` | Accelerator translation helper reads the pointer. | Browser helper uses the object at `+0x120` for hosted-browser keyboard handling. |
| `0x005571f6` through `0x00558601` cluster | Presentation/screenshot consumers. | Surface presentation sync/redraw paths call browser helpers and use the hosted HWND at `+0x11c`. |

## Ownership Hypothesis

The storage is the active embedded browser control-pane pointer. It is set by the `BrowserControlPane` constructor, cleared by destructor/unwind paths, and read by application/presentation code that must coordinate the hosted browser window with the main message pump and frame presentation.

The safest source reconstruction is a browser-owned declaration exposed through a browser header or accessor, with non-browser direct users called out during rewrite. The exact original symbol name remains provisional because IDA has only `dword_67AB28` plus alias names.

Do not move this storage into `Application`, `Surface`, screenshot, or generic UI-core ownership. Those modules are confirmed consumers; the constructor/destructor writes and active browser-control object offsets make the declaration browser-owned.

## Type Hypothesis

Likely browser-use declaration:

```cpp
static BrowserControlPane* g_activeBrowserControlPane;
```

Keep this provisional. It may be an alias of a broader active pane/controller global currently named through one browser use.

## Follow-Up

- Reconcile `DAT_0067ab28` and `g_activeBrowserControlPane` as one storage location in source-facing docs.
- Name the application accelerator helper at `0x0046c550` and the presentation/browser-sync call at `0x0046bfd0`.
- During source reconstruction, avoid hiding the cross-module consumers; they likely need a browser header declaration or a small accessor.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md)
- [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md)
- [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md)
- [UID:00020U][0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage](by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md)

## Changes

- 2026-06-06 A010 evidence consolidation:
  - Before: `COMPLETION:82`, `CONFIDENCE:78`, with broad xref notes but no lifecycle/consumer table, rebuild-handling classification, or explicit source-gate note.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`, source-declared storage handling, autogen/source-gate note, detailed constructor/destructor/application/presentation evidence table, and clearer owner separation from application/surface consumers.
  - Summary/evidence: [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md) records the exact `dd ?` storage, 24 direct xrefs, constructor writes at `0x0046b58d`/`0x0046b594`, teardown clears at `0x0046ba13`, `0x00470210`, and `0x00470493`, and app/presentation consumer clusters. Confidence remains below final-audit because the final exported declaration/accessor shape is unresolved.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `82/78`. Summary/evidence: the page documents storage, browser constructor/destructor writes, cross-module consumers, type hypothesis, and follow-up items; exact exported name and source split remain provisional.
- 2026-06-05: Marked reconstructable and attached to [UID:0000HV][Browser](by-file/Browser.md).
  - Reason: live IDA MCP recheck confirms this is source-declared active browser-control storage written by browser lifetime code and consumed by application/surface bridge paths through browser headers or accessors.
