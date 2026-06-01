*** UID:0001RJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

## Cross-References

- [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md)
- [UID:00009K][NumberInputDialog](by-class/NumberInputDialog.md)
- [UID:0001CW][0x00530640-0x00530cf7.NumberInputDialog](by-memory/0x00530640-0x00530cf7.NumberInputDialog.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Before: page had concrete IDA notes but was still scored `0/0`.
- Changed to: `COMPLETION:78`, `CONFIDENCE:90`, with current IDA MCP verification of resource strings, xrefs, branch dimensions, and layout rectangles.
- Evidence: IDA MCP UTF-16 string/xref search and decompilation of `0x00530640-0x00530b00`.
