*** UID:0001RJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# NumberInputDialog Resources

## Status

- Confidence: strong for resource names and layout split.
- Covered file/module: [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md)
- Main code range: [UID:0001CW][0x00530640-0x00530cf7.NumberInputDialog](by-memory/0x00530640-0x00530cf7.NumberInputDialog.md)

## Resource Map

| Asset mode | Background | Palette | Layout notes |
| --- | --- | --- | --- |
| EPF mode | `DLGEXC3.EPF` | `PAL01.PAL` | `239x283` background, OK image `14`, cancel image `22`, prompt label control `3`, edit control `4`. |
| EPD mode | `DLGEXC3.EPD` | `NPAL8.PAL` | `287x277` background, OK image `14`, cancel image `22`, prompt label control `3`, edit control `4`. |

## Source/Resource Contract

| Area | Source-owned behavior | Resource-owned data |
| --- | --- | --- |
| Asset-mode branch | `NumberInputDialog` owns the runtime branch on the client asset-mode flag and the choice of EPF versus EPD layout geometry. | `DLGEXC3.EPF`/`DLGEXC3.EPD` own the background art payloads; `PAL01.PAL`/`NPAL8.PAL` own palette data. |
| Control layout | The constructor owns dialog size, prompt/edit rectangles, control IDs `1` through `4`, OK/cancel default behavior, focus assignment, and slide-open positioning. | Button image indexes `14` and `22` are resource-frame selections consumed by the source layout rather than separate dialog behaviors. |
| Validation and alerts | The action handler owns integer parsing, min/max checks, callback dispatch, and use of the shared alert path for localized error string id `217`. | The localized error text belongs to the language/string system and alert shell resources; this page only records the number-dialog dependency on that shared path. |
| Caller prompts | Item-mixing callers own the prompt text, min/max values, and callback object they pass into the dialog. | This resource page does not own item-specific quantity text or callback payloads. |

## Shared Resource Boundaries

- `DLGEXC3.EPF` is shared by other dialog constructors according to the current IDA evidence. Keep this page scoped to the `NumberInputDialog` use of that background, palette, and geometry rather than claiming exclusive asset ownership.
- `PAL01.PAL` and `NPAL8.PAL` are shared UI palettes. Rebuild code should reference the central palette/resource layer instead of creating number-dialog-private palette globals.
- The generated `L"NP"` EPD palette in active output is a string decoding defect. The resource contract for this dialog remains `NPAL8.PAL` unless future IDA evidence proves a different string path.
- The `AlertPane` shown for out-of-range input is a shared dialog dependency, not a number-input resource asset. Keep alert-frame/button-string ownership on [UID:0001R5][alert-dialog-resources](by-resource/alert-dialog-resources.md).

## IDA Evidence

Checked on 2026-05-25, 2026-05-26, and reverified through IDA MCP:

- The UTF-16 string `DLGEXC3.EPF` at `0x00619284` has xrefs at `0x00530711` and `0x00530889` inside `0x00530640-0x00530b00`; the same string is shared by other dialog constructors.
- The UTF-16 string `PAL01.PAL` at `0x00618cfc` is the EPF-mode palette operand used by `NumberInputDialog` at `0x00530718` through the current IDA decompilation symbol `off_618CFC`; the palette is shared across many UI art paths.
- The UTF-16 string symbol `aNp` at `0x0061484c` decodes to `NPAL8.PAL`; IDA reports a `NumberInputDialog` constructor xref at `0x005308eb`.
- The UTF-16 string symbol `aDlgexc3Epd` at `0x0062026c` decodes to `DLGEXC3.EPD`; IDA reports constructor xrefs at `0x005308f8` and `0x00530a79`.
- Active `source-3/simroot_v2/class_NumberInputDialog.cpp` currently renders the EPD palette argument as `L"NP"`, which truncates the actual `NPAL8.PAL` string.
- 2026-05-26 IDA `xrefs_to` still reports the constructor data xref at `0x005308eb` for `NPAL8.PAL` and `0x005308f8` / `0x00530a79` for `DLGEXC3.EPD`.
- IDA decompilation of `0x00530640-0x00530b00` confirms the EPF branch uses `239x283`, OK image `14`, cancel image `22`, prompt rect `(28,35)-(211,107)`, and edit rect `(28,111)-(211,123)`. The EPD branch uses `287x277`, OK image `14`, cancel image `22`, prompt rect `(37,36)-(249,119)`, and edit rect `(52,129)-(234,141)`.

## Ownership Decision

Use `NPAL8.PAL` for the EPD branch unless later binary evidence proves a different runtime string path. Treat `L"NP"` in generated output as a data/string decoding issue.

The reusable number dialog owns the source behavior for building the prompt, edit field, buttons, validation path, and callback handoff. Item-mixing dialogs remain callers, not resource owners, and the resource page should not absorb their prompt text or stack-count business rules.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 80 | Known EPF/EPD backgrounds, palettes, branch geometry, button/control IDs, string-decoding caveat, owner file/class/memory links, source/resource contract, shared palette/background boundaries, alert dependency, and caller-owned prompt boundaries are documented. It remains below high completion because final DAT packaging, original declarations/macros, and broader `DLGEXC3` sharing inventory are not fully proven here. |
| Confidence | 90 | Resource filenames, palette strings, xrefs, geometry, and generated-data correction are backed by existing IDA MCP evidence in this page and linked NumberInputDialog docs. Confidence remains below maximum because the exact original source representation and full shared-resource inventory are not final. |

## Cross-References

- [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md)
- [UID:00009K][NumberInputDialog](by-class/NumberInputDialog.md)
- [UID:0001CW][0x00530640-0x00530cf7.NumberInputDialog](by-memory/0x00530640-0x00530cf7.NumberInputDialog.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Before: page had concrete IDA notes but was still scored `0/0`.
- Changed to: `COMPLETION:78`, `CONFIDENCE:90`, with current IDA MCP verification of resource strings, xrefs, branch dimensions, and layout rectangles.
- Evidence: IDA MCP UTF-16 string/xref search and decompilation of `0x00530640-0x00530b00`.
- 2026-06-07 A002 source/resource contract pass:
  - Before: the page listed verified resource names and layout facts, but did not separate source-owned dialog behavior from shared asset and palette data.
  - After: raised to `COMPLETION:80` with source/resource contracts, shared `DLGEXC3`/palette boundaries, alert dependency scope, caller prompt ownership, and explicit score rationale.
