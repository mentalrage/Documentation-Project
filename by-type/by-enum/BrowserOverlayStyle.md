*** UID:0001SM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:62 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BrowserOverlayStyle

## Status

- Confidence: strong for observed values and owner; medium for original enum/constant name.
- Current source evidence: IDA MCP decompilation of `BrowserControlPaneOld::DrawBrowserStatusOverlay`; generated source names are lead material only.
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md), likely browser-private constants.
- Reconstructable: yes as browser overlay constants if final source keeps symbolic names, but do not emit C++ until the text/style helper prototypes and source names are settled.

## Values

| Value | Name hypothesis | Meaning |
| --- | --- | --- |
| `128` | `kBrowserOverlayDrawStyle` | Style/opacity value applied before drawing the browser status overlay text. |
| `236` | `kBrowserStatusStringId` | Language/string-table id used for the browser status overlay text. |

## Evidence

- IDA MCP confirms `BrowserControlPaneOld::DrawBrowserStatusOverlay` at `0x0046f220-0x0046f30f`.
- IDA MCP decompilation shows the function first checks a flag at `*(_DWORD *)(this + 272) + 546` before drawing.
- The function fetches language/string-table id `236` through `0x004f0350`, measures and centers the returned wide string inside the pane rectangle, then applies style value `128` through `0x004b9680` before drawing the text.
- The constants are therefore confirmed in the overlay draw path, but their final source-level names are still naming hypotheses.

## Placement

Keep this as browser UI overlay state. Do not move it to generic text-control constants unless later xrefs prove the values are shared outside browser overlay drawing.

## Open Questions

- Determine whether `236` should be documented primarily in the localized string table/resource docs rather than as a browser enum value.
- Determine whether `128` is a generic text/style flag shared by other panes or a browser-specific style constant passed through the generic draw helper.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md)
- [UID:0000ZF][0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers.md)
