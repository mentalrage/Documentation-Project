*** UID:0000PO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_activeBrowserControlPane

## Status

- Confidence: strong for address and active `BrowserControlPane*` role, medium for final exported name/source split.
- Current Wave3 kind: `global-data`.
- Current generated owner file: `class_BrowserControlPane.cpp`.
- IDA storage candidate: `0x0067ab28` (`DAT_0067ab28` / `g_activeBrowserControlPane` alias family).
- Memory doc: [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md)
- Proposed owner: [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md) / [UID:0000HV][Browser](by-file/Browser.md), exposed to application and surface/presentation helpers.

## Observed Evidence

Generated `BrowserControlPane::BrowserControlPane` writes `DAT_0067ab28 = this` during construction. Generated cleanup paths clear the same storage through either `DAT_0067ab28` or `g_activeBrowserControlPane`, depending on the Wave3 emission pass.

IDA xrefs to `0x0067ab28` include browser constructor/destructor paths, but also broader UI/frame/timer references outside the browser cluster.

2026-05-25 IDA MCP `py_eval` reports `dword_67AB28` as a four-byte `.data` item with 24 direct xrefs. Ten refs are in the browser dense code neighborhood, while later refs around `0x00557140-0x00558601` remain outside the browser source family.

2026-05-26 IDA decompilation narrows the broad refs: `Application::RunMessageLoop` calls `0x0046c550`, which queries the browser active object at `dword_67AB28 + 0x120` for accelerator translation; `SurfacePresentation` / screenshot paths call `sub_46bfd0(dword_67AB28, activeSurface)` and redraw the hosted browser HWND at `dword_67AB28 + 0x11c`. These are cross-module consumers of the active browser control, not evidence for a non-browser owner.

## Ownership Hypothesis

The storage is the active embedded browser control-pane pointer. It is set by the `BrowserControlPane` constructor, cleared by destructor/unwind paths, and read by application/presentation code that must coordinate the hosted browser window with the main message pump and frame presentation.

The safest source reconstruction is a browser-owned declaration exposed through a browser header or accessor, with non-browser direct users called out during rewrite. The exact original symbol name remains provisional because IDA has only `dword_67AB28` and Wave3 emits both raw `DAT_0067ab28` and named aliases.

## Type Hypothesis

Likely browser-use declaration:

```cpp
static BrowserControlPane* g_activeBrowserControlPane;
```

Keep this provisional. It may be an alias of a broader active pane/controller global that Wave3 currently names through one browser use.

## Follow-Up

- Reconcile `DAT_0067ab28` and `g_activeBrowserControlPane` as one storage location in generated output.
- Name the application accelerator helper at `0x0046c550` and the presentation/browser-sync call at `0x0046bfd0`.
- During source reconstruction, avoid hiding the cross-module consumers; they likely need a browser header declaration or a small accessor.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md)
- [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md)
- [Browser global-data issue](../wave3_data_issues.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `82/78`. Summary/evidence: the page documents storage, generated owner, browser constructor/destructor writes, cross-module consumers, type hypothesis, and follow-up items; exact exported name and source split remain provisional.
