*** UID:0000UE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DeserializePredefinedFormArticleEntries 0x00478650

## Status

- Confidence: strong
- Entity kind: global/file-local helper
- Current Wave3 form: recovered global function
- Current recovered file: `source-3/simroot_v2/recovered/DeserializePredefinedFormArticleEntries_00478650.cpp`
- Likely source module: [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md)
- Exact range: `0x00478650-0x00478932`

## Behavior

`DeserializePredefinedFormArticleEntries_478650` parses a serialized predefined article form payload into `PredefinedFormArticleEntry` records used by `NewPredefinedFormArticleDialog`.

Input/output model:

- `serialized`: source byte stream. `serialized[1]` is the first title length; parsing starts at offset `2`.
- `entries`: output array of `0x40c` byte entry records.
- `outVisibleRowCount`: receives the row count used to size the variable-height dialog.
- `outEntryCount`: receives the number of parsed entries.

Algorithm summary:

- Loops until the next title length byte is zero.
- Copies title bytes into a local ANSI buffer, converts to wide text with `MultiByteToWideChar`, stores title length and text.
- Reads `usesUserImagePane`, `textLineCount`, body length, body bytes, and `hasExtraRowAdvance`.
- Converts body bytes to wide text. The literal body value `empty` becomes an empty body with zero length.
- Updates visible-row count using the extra-row flag and the `textLineCount`-based height calculation for multiline body fields.
- Writes final entry count and visible row count to the caller outputs and returns the visible row count.

## Xref Evidence

IDA MCP checked on 2026-05-24:

- Function boundary: `0x00478650-0x00478932`.
- Code xrefs are only from `NewPredefinedFormArticleDialog::NewPredefinedFormArticleDialog` at `0x00477848` and `0x00477d0c`.

This caller set strongly supports treating the helper as file-local to the predefined-form article dialog rather than a shared parser module.

## Cross-References

- [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md)
- [UID:000098][NewPredefinedFormArticleDialog](by-class/NewPredefinedFormArticleDialog.md)
- [UID:0000ZL][0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog](by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `84/88`.
  - Before: page documented predefined article payload parsing behavior, input/output model, algorithm summary, and xref evidence but remained unevaluated.
  - After: score reflects detailed parser behavior and strong file-local ownership for the predefined-form article dialog.
  - Evidence: IDA MCP confirms the exact function boundary and only two xrefs from `NewPredefinedFormArticleDialog::NewPredefinedFormArticleDialog`.
