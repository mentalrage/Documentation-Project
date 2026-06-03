*** UID:0000PP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_activeBrowserPane

## Status

- Confidence: strong for address, browser ownership, and active owner/callback role; medium-high for final C++ type/linkage.
- Current Wave3 kind: `global-data`
- Current generated owner file: `class_BrowserControlPane.cpp`
- IDA storage: `0x0067ab84` / `dword_67AB84`, documented at [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md)
- Memory doc: [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md)
- Owner: [UID:0000HV][Browser](by-file/Browser.md), pending final type cleanup.

## Observed Evidence

Generated `BrowserControlPane::BrowserControlPane` stores its owner tag/parent pointer into `DAT_0067ab84`. Generated `BrowserControlPane::HandleBrowserDispatchEvent` uses `g_activeBrowserPane` to notify the owning browser pane on internal-close, new-window, and document-complete events.

IDA xrefs to `0x0067ab84` include:

- `0x0046b62d` inside `BrowserControlPane` construction.
- `0x0046c9f4`, `0x0046ca77`, and `0x0046cabb` inside the browser dispatch event handler.
- Additional app/browser setup references at `0x00464e70`, `0x0046a5d4`, and `0x0046c617`.

2026-05-25 IDA MCP `py_eval` reports `dword_67AB84` as a four-byte `.data` item with 8 direct xrefs, 7 of which sit in the browser dense code neighborhood.

The exact memory page [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md) records a later 2026-06-02 IDA refresh: uninitialized four-byte storage at `0x0067ab84`, neighboring dword boundaries, the constructor write at `0x0046b62d`, Escape handling through `sub_49DF20(dword_67AB84)`, and browser dispatch consumers at `0x0046c9f4`, `0x0046ca77`, and `0x0046cabb`.

## Ownership Hypothesis

This is browser-pane/control active owner state. It should remain with the browser module. The exact source type should still be reviewed because generated code currently uses a broad `void*`, while the observed consumers behave like a browser-pane owner/callback target.

## Type Hypothesis

Likely declaration:

```cpp
static BrowserPane* g_activeBrowserPane;
```

It may instead be a `DialogPane*` or browser-owner callback target if non-browser xrefs prove broader use.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md)
- [UID:000019][BrowserPane](by-class/BrowserPane.md)
- [UID:0001SJ][BrowserDispatchEventId](by-type/by-enum/BrowserDispatchEventId.md)
- [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `78/72`. Summary/evidence: the page documents storage, browser construction/dispatch uses, IDA xrefs, ownership/type hypotheses, and refs, but the final type and source-facing name remain medium-confidence.
- Before: confidence stayed at `72` and autogen metadata was blank even though the exact memory page had been refreshed to `82/84` and attached to Browser.
- Changed to: score `82/84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000HV`.
- Summary/evidence: [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md) records the exact storage, boundary, constructor write, 8-xref set, accelerator/Escape consumers, and browser dispatch-event uses. Final C++ type/linkage remains below the 95+ reconstruction gate.
