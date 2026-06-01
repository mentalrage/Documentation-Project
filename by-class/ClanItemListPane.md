*** UID:00002G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanItemListPane

## Status

- Confidence: strong for list parsing/drawing; medium for final owner of text-fitting helpers.
- Likely source file: [UID:0000I9][ClanBank](by-file/ClanBank.md)
- Current recovered file: `source-3/simroot_v2/class_ClanItemListPane.cpp`

## Class Purpose

`ClanItemListPane` is the compact item list used by clan item deposit/withdraw dialogs. It decodes item slot records from packet data, stores active slots, adds rows for active items, and draws each row with icon-aware selection and truncated wide text.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClanItemListPane` | `0x0048ae70-0x0048b08b` | Initializes list storage, parses packet item count/slot/item-id/name records, converts names to wide text, and adds active rows. |
| `DrawListItem` | `0x0048b0a0-0x0048b1b1` | Draws selected/unselected item row, gets item glyph bounds, truncates display name, and draws wide text. |
| destructor/thunks | `0x0048c2ff`, `0x0048c30a`, `0x0048c510-0x0048c54a` | Vtable thunks and scalar deleting destructor. |
| `SetEntryText` | `0x004ba820-0x004ba8a1` | Truncates a string to fit a pixel width and appends a suffix. |
| `CountCharsFittingWidth` | `0x004ba8b0-0x004ba990` | Counts visible wide characters that fit a measured width. |

## Evidence Notes

- IDA confirms all listed starts.
- `CountCharsFittingWidth` currently references `g_pDirectX` in generated source, but earlier global-data triage indicates font measurement should likely use `g_pFontImageLib`. Keep this as a known Wave3 data cleanup issue.
- The two text-fitting helpers may be shared UI text code. They remain documented here because Wave3 currently owns them under `ClanItemListPane` and the class uses them directly.

## Cross-References

- [UID:0000I9][ClanBank](by-file/ClanBank.md)
- [UID:00010Q][0x0048ae70-0x0048b1b1.ClanItemListPane](by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md)
- [UID:00016B][0x004ba820-0x004ba991.TextFitAndSuffixHelpers](by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md)

## Changes

- 2026-05-27: Corrected `DrawListItem` from `0x0048b0a0-0x0048b1b0` to exclusive end `0x0048b1b1`. Evidence: IDA MCP reports `sub_48B0A0` at `0x0048b0a0-0x0048b1b1`, with `retn 0Ch` occupying bytes `0x0048b1ae-0x0048b1b0`.
- [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md)
- What existed before: the page documented item-list parsing/drawing and text-fitting helper caveats, but metadata remained `0/0`.
- What it was changed to: scores were set to `72/80`.
- Summary and evidence: constructor/parser, draw method, destructor/thunks, and text-fitting helpers are covered; final helper ownership, entry layout, and font/global naming remain incomplete.
