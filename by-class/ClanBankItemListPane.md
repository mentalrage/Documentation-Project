*** UID:000025 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanBankItemListPane

## Status

- Confidence: strong for constructor/draw/destructor; low for outlier methods `0x00430041` and `0x004c0043`.
- Likely source file: [UID:0000I9][ClanBank](by-file/ClanBank.md)
- Current recovered file: `source-3/simroot_v2/class_ClanBankItemListPane.cpp`

## Class Purpose

`ClanBankItemListPane` parses clan bank inventory packets and renders bank item rows. It caches up to 255 slots, handles full-list, remove-slot, and update packet variants, sorts by display name for full lists, adds list entries, and draws each row with the item icon, display name, and count suffix.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClanBankItemListPane` | `0x0048b8c0-0x0048c034` | Initializes the list, decodes bank packet cases `10`, `15`, and `16`, converts names to wide text, sorts rows, and adds active entries. |
| `DrawListEntry` | `0x0048c040-0x0048c251` | Draws selection highlight, item glyph, count-suffixed row text, and width-limited name. |
| destructor/thunks | `0x0048c2a7`, `0x0048c2b2`, `0x0048c3d0-0x0048c40a` | Vtable thunks and scalar deleting destructor. |
| `AppendEntryString` | Wave3 `0x00430041`; IDA function [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md) | Generic string/vector append helper, not class-owned under current evidence. |
| excluded outlier | Wave3 `0x004c0043`; IDA containing function `0x004bee40-0x004c069d` | Excluded SIMD bit helper, not clan-bank behavior. |

## Evidence Notes

- IDA confirms the real local starts at `0x0048b8c0`, `0x0048c040`, and `0x0048c3d0`.
- 2026-05-27 boundary pass reports constructor/list parser end `0x0048c034` and `DrawListEntry` end `0x0048c251`; byte `0x0048c250` is the final immediate byte of `retn 0Ch`.
- IDA resolves `0x00430041` to `sub_430040`, one byte before the Wave3 method address, and current evidence points to a generic append helper rather than a clan-bank list method. The same enclosing helper also contains the false `ExchangeMoneyEditControlPane::GetClassName` start at `0x00430058`.
- IDA resolves `0x004c0043` inside `sub_4BEE40`, a large unrelated bit-manipulation function. Keep that out of clan migration.

## Cross-References

- [UID:0000I9][ClanBank](by-file/ClanBank.md)
- [UID:00010S][0x0048b8c0-0x0048c251.ClanBankItemListPane](by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md)
- [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md)
- [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md)
- [UID:000026][ClanBankPane](by-class/ClanBankPane.md)

## Changes

- 2026-05-27: Corrected local method ends from `0x0048c033`/`0x0048c250` to exclusive ends `0x0048c034`/`0x0048c251`. Evidence: IDA MCP reports `sub_48B8C0` at `0x0048b8c0-0x0048c034` and `sub_48C040` at `0x0048c040-0x0048c251`.
- What existed before: the page documented clan-bank inventory parsing/drawing and outlier method exclusions, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `76/80`.
- Summary and evidence: constructor/parser, draw method, destructor band, packet cases, sorting/rendering behavior, and wrong-owner outliers are documented; exact entry struct layout and final field names still need deeper work.
