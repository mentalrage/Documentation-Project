*** UID:0001SM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Classification: provisional browser overlay constants. Keep this page in `by-enum` as current inventory, but do not treat either value as a final enum declaration yet.

## Values

| Value | Name hypothesis | Meaning |
| --- | --- | --- |
| `128` | `kBrowserOverlayDrawStyle` | Style/opacity value applied before drawing the browser status overlay text. |
| `236` | `kBrowserStatusStringId` | Language/string-table id used for the browser status overlay text. |

## Value Use Map

| Observed value | Use site | Current interpretation | Remaining risk |
| --- | --- | --- | --- |
| `236` | Passed to `0x004f0350` from `BrowserControlPaneOld::DrawBrowserStatusOverlay`. | Localized string id for the browser status overlay text. | The string-id mapping belongs with `str.res` once the concrete text is recovered. |
| `128` | Passed to text/style helper `0x004b9680` immediately before drawing the overlay text. | Overlay text draw style, opacity, color, or flag value. | The helper may be generic, so the final declaration could be shared text-rendering state rather than browser-private data. |
| Browser flag at `*(_DWORD *)(this + 272) + 546` | Checked before the overlay text path runs. | Gate for whether the status overlay is drawn. | This is control state, not a member of this constants page. |

## Evidence

- IDA MCP confirms `BrowserControlPaneOld::DrawBrowserStatusOverlay` at `0x0046f220-0x0046f30f`.
- IDA MCP decompilation shows the function first checks a flag at `*(_DWORD *)(this + 272) + 546` before drawing.
- The function fetches language/string-table id `236` through `0x004f0350`, measures and centers the returned wide string inside the pane rectangle, then applies style value `128` through `0x004b9680` before drawing the text.
- The constants are therefore confirmed in the overlay draw path, but their final source-level names are still naming hypotheses.
- [UID:0000HV][Browser](by-file/Browser.md) already groups this page with browser UI constants, and [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md) identifies `DrawBrowserStatusOverlay` as the evidence source for this page.
- [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md) documents the `0x004f0350` language/string lookup helper used by the `236` path.

## Placement And Classification

Keep this as browser UI overlay state. Do not move it to generic text-control constants unless later xrefs prove the values are shared outside browser overlay drawing.

The current evidence proves two immediate values in the browser overlay draw path, but it does not prove that the original source declared a named enum. The safest reconstruction stance is browser-owned constant candidates: `236` is a localization id consumed by browser overlay code, while `128` is a draw-style value passed through a helper whose owner is still unresolved.

## Autogen Status

- Reconstructable: true, as browser overlay constant candidates.
- Parent: [UID:0000HV][Browser](by-file/Browser.md).
- C++: intentionally blank; final declarations should wait for text/style helper naming and `str.res` string-id mapping.

## Score Rationale

Completion is raised for the parent attachment, explicit value-use map, placement decision, and cross-resource evidence. Confidence rises modestly because the use sites are exact, but the final declaration form and owner of the style helper remain open.

## Open Questions

- Determine whether `236` should be documented primarily in the localized string table/resource docs rather than as a browser enum value.
- Determine whether `128` is a generic text/style flag shared by other panes or a browser-specific style constant passed through the generic draw helper.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md)
- [UID:0000ZF][0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers.md)
- [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md)

## Changes

- 2026-06-02:
  - What existed before: the page was `62/82`, reconstructable, but had no parent attachment and only summarized the two observed values.
  - Changed to: completion/confidence `72/84`, `AUTOGEN_PARENT_UID:0000HV`, explicit value-use map, autogen status, placement/classification notes, and localization cross-reference.
  - Summary/evidence: `BrowserControlPaneOld::DrawBrowserStatusOverlay` confirms both immediate values; Browser already groups this page as browser UI constants, and `str.res` docs confirm the language lookup helper behind the `236` string-id path.
