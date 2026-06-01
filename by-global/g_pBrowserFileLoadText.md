*** UID:0000QC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pBrowserFileLoadText

## Status

- Confidence: medium for browser alert text role.
- Current generated form: unresolved identifier used by `BrowserPane::OnCommand`.
- Current generated owner file: `browser/Browser.cpp`.
- Current memory evidence: [UID:0001OD][0x00613a20-0x00613ab0.BrowserAlertStrings](by-memory/0x00613a20-0x00613ab0.BrowserAlertStrings.md), direct UTF-16 string `Navigation Failed`.
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md) as a static browser alert string literal.

## Observed Evidence

Generated `BrowserPane::OnCommand` uses `g_pBrowserFileLoadText` for command id `1111713388` (`BCfl` in older notes). IDA decompilation resolves that generated symbol to the direct string literal at `0x00613a30`, text `Navigation Failed`. The handler creates an alert pane with this text and then activates the current browser dialog item.

A 2026-05-25 current-state recheck found the active generated reference in `simroot_v2/browser/Browser.cpp`. `rg` finds no active `global-data` declaration for this name in current `simroot_v2`, so treat this page as an alias note over the literal storage, not proof of writable pointer storage.

## Ownership Hypothesis

This is browser UI text/static state for the file-load/navigation-failure alert path. It belongs near `BrowserPane`.

The `g_p...` spelling is generated data naming, not confirmed original source naming. Current IDA evidence shows direct static string storage, not a separate pointer global.

## Type Hypothesis

Likely source-level declaration:

```cpp
static const wchar_t kBrowserNavigationFailedText[] = L"Navigation Failed";
```

If the original source used a pointer alias, no separate storage for that alias has been recovered yet.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:000019][BrowserPane](by-class/BrowserPane.md)
- [UID:0001OD][0x00613a20-0x00613ab0.BrowserAlertStrings](by-memory/0x00613a20-0x00613ab0.BrowserAlertStrings.md)
- [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `76/74`. Summary/evidence: the page documents the browser navigation-failure text, direct UTF-16 literal evidence, command-path use, ownership hypothesis, and generated-alias caveat; no separate writable pointer storage is currently proven.
