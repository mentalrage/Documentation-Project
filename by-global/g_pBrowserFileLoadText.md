*** UID:0000QC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pBrowserFileLoadText

## Status

- Confidence: strong for browser alert text role and browser-module ownership; medium for the generated `g_p...` alias spelling.
- Current generated form: unresolved identifier used by `BrowserPane::OnCommand`.
- Current generated owner file: `browser/Browser.cpp`.
- Current memory evidence: [UID:0001OD][0x00613a20-0x00613ab0.BrowserAlertStrings](by-memory/0x00613a20-0x00613ab0.BrowserAlertStrings.md), direct UTF-16 string `Navigation Failed`.
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md) as a static browser alert string literal.
- Autogen parent: [UID:0000HV][Browser](by-file/Browser.md); no C++ emitted here because [UID:0001OD][0x00613a20-0x00613ab0.BrowserAlertStrings](by-memory/0x00613a20-0x00613ab0.BrowserAlertStrings.md) owns the exact string range and final literal names are below the `95+` source gate.

## Observed Evidence

Generated `BrowserPane::OnCommand` uses `g_pBrowserFileLoadText` for command id `1111713388` (`BCfl` in older notes). IDA decompilation resolves that generated symbol to the direct string literal at `0x00613a30`, text `Navigation Failed`. The handler creates an alert pane with this text and then activates the current browser dialog item.

A 2026-05-25 current-state recheck found the active generated reference in `simroot_v2/browser/Browser.cpp`. `rg` finds no active `global-data` declaration for this name in current `simroot_v2`, so treat this page as an alias note over the literal storage, not proof of writable pointer storage.

[UID:0001OD][0x00613a20-0x00613ab0.BrowserAlertStrings](by-memory/0x00613a20-0x00613ab0.BrowserAlertStrings.md) now records the exact string range at `82/88`, marks it reconstructable, and attaches it to [UID:0000HV][Browser](by-file/Browser.md). That page includes the 2026-06-02 IDA MCP `BrowserPane::OnCommand` decompile/xref evidence and the exact `0x00613a30-0x00613a54` UTF-16 literal boundary for `Navigation Failed`.

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
- 2026-06-03 autogen attachment pass:
  - Before: the generated alias page remained unparented at `76/74`, even though its exact string-range page and browser parent had stronger evidence.
  - Changed to: completion/confidence `78/82`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000HV`.
  - Evidence: [UID:0000HV][Browser](by-file/Browser.md) is `84/88`; [UID:0001OD][0x00613a20-0x00613ab0.BrowserAlertStrings](by-memory/0x00613a20-0x00613ab0.BrowserAlertStrings.md) is `82/88`, reconstructable, attached to Browser, and records the IDA-confirmed `0x00613a30-0x00613a54` `Navigation Failed` literal used by `BrowserPane::OnCommand`. C++ remains blank because this page is a generated alias note, not a separate proven pointer-storage definition, and final literal naming is below the `95+` code-emission gate.
