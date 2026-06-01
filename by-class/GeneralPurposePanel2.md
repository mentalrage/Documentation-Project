*** UID:00005R | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GeneralPurposePanel2

## Status

- Confidence: strong for behavior; medium for exact feature meaning of the single child pane.
- Likely source file: [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md)
- Main address doc: [UID:00015V][0x004b83d0-0x004b8bd3.GeneralPurposePanel](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md)
- Current recovered file: `source-3/simroot_v2/class_GeneralPurposePanel2.cpp`

## Functionality

`GeneralPurposePanel2` is a smaller alternate general-purpose panel shell. It constructs one child pane, exposes index-based child lookup, tracks a single active state value, and clears `g_pGeneralPurposePanel2` during teardown.

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| constructor | `0x004b8830-0x004b88e0` | Constructs the alternate panel and one child pane. |
| destructor | `0x004b88f0-0x004b8943` | Releases the child pane and clears singleton. |
| `GetChildPaneByIndex` | `0x004b8950-0x004b8968` | Returns the single child for index `0`, otherwise null. |
| active switch helper | [UID:00015Y][0x004b89a0-0x004b8a7e.GeneralPurposePanel2SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7e.GeneralPurposePanel2SwitchActiveChild.md) | IDA-confirmed one-child activation/layout helper currently omitted from active generated output. |
| scalar deleting destructor | `0x004b8aa0-0x004b8b31` | Deleting destructor wrapper. |

## Cross References

- [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md)
- [UID:00005Q][GeneralPurposePanel](by-class/GeneralPurposePanel.md)
- [UID:0000R1][g_pGeneralPurposePanel2](by-global/g_pGeneralPurposePanel2.md)
- [UID:00015Y][0x004b89a0-0x004b8a7e.GeneralPurposePanel2SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7e.GeneralPurposePanel2SwitchActiveChild.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `72/78`. Summary: alternate one-child panel role, singleton, core methods, and missing active-switch helper are documented; exact feature meaning of the single child pane remains medium-confidence. Evidence: shared `GeneralPurposePanel` memory page, `GeneralPurposePanel2SwitchActiveChild`, and `g_pGeneralPurposePanel2`.
