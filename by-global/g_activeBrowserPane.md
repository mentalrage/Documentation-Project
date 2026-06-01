*** UID:0000PP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_activeBrowserPane

## Status

- Confidence: medium.
- Current Wave3 kind: `global-data`
- Current generated owner file: `class_BrowserControlPane.cpp`
- IDA storage candidate: `0x0067ab84` (`DAT_0067ab84`)
- Memory doc: [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md)
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md), pending name/type cleanup.

## Observed Evidence

Generated `BrowserControlPane::BrowserControlPane` stores its owner tag/parent pointer into `DAT_0067ab84`. Generated `BrowserControlPane::HandleBrowserDispatchEvent` uses `g_activeBrowserPane` to notify the owning browser pane on internal-close, new-window, and document-complete events.

IDA xrefs to `0x0067ab84` include:

- `0x0046b62d` inside `BrowserControlPane` construction.
- `0x0046c9f4`, `0x0046ca77`, and `0x0046cabb` inside the browser dispatch event handler.
- Additional app/browser setup references at `0x00464e70`, `0x0046a5d4`, and `0x0046c617`.

2026-05-25 IDA MCP `py_eval` reports `dword_67AB84` as a four-byte `.data` item with 8 direct xrefs, 7 of which sit in the browser dense code neighborhood.

## Ownership Hypothesis

This is browser-pane/control active owner state. It should remain with the browser module, but the final type should be reviewed because generated code currently uses a broad `void*`.

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
