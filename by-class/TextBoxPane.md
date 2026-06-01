*** UID:0000EI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TextBoxPane

## Status

- Confidence: medium-strong.
- Likely source file: [UID:0000OJ][TextBoxPane](by-file/TextBoxPane.md)
- Main address ranges: `0x00591300-0x005913f8` and `0x00595390-0x005954b2`
- Current recovered file: `source-3/simroot_v2/class_TextBoxPane.cpp`

## Class Purpose

`TextBoxPane` is a [UID:0000EO][TextEditPane](by-class/TextEditPane.md) derivative that customizes cursor visibility and line invalidation for a bordered or constrained text box. It can construct with optional initial text, multiline mode, and scrollbar support.

## Method Families

| Range | Function | Role |
| --- | --- | --- |
| `0x00591300-0x00591369` | `EnsureCursorVisible` | Convert cursor line to visible bounds and apply clip bounds. |
| `0x00591370-0x005913f8` | `InvalidateLineRange` | Build affected line regions and apply clip bounds to each. |
| `0x00595390-0x005954b2` | `TextBoxPane::TextBoxPane` | Construct `TextEditPane` base, install vtables, set initial text, update style, and refresh cursor/line visibility. |

## Evidence Notes

- Wave3 reports base relationship `TextBoxPane->TextEditPane`.
- IDA MCP reports eight direct constructor callers.
- Constructor uses `g_pIMEPane->SetFocusPane` while setting up the text box style.

## Cross-References

- [UID:0000OJ][TextBoxPane](by-file/TextBoxPane.md)
- [UID:0001JO][0x00591300-0x005954b2.TextBoxPane](by-memory/0x00591300-0x005954b2.TextBoxPane.md)
- [UID:0000EO][TextEditPane](by-class/TextEditPane.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `78`, confidence `76`.
- Evidence: the page documents the `TextEditPane` derivative role, constructor and cursor/line invalidation helpers, direct constructor callers, and IME focus behavior; completion remains limited because broader text-box virtual/destructor coverage and exact style fields are not yet detailed.
