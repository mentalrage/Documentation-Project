*** UID:00004H | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EPFTextEditObject

## Status

- Confidence: strong for behavior; medium for exact original file split.
- Likely source file: [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- Main address ranges: `0x005954c0-0x0059558f` and `0x00595630-0x0059566d`
- Current recovered file: `source-3/simroot_v2/class_EPFTextEditObject.cpp`

## Class Purpose

`EPFTextEditObject` is a [UID:0000EN][TextEditObject](by-class/TextEditObject.md) derivative that attaches an `EPFFrame` symbol image to a text-edit object. It chooses `SYMBOLS.EPF` or `SYMBOLS.EPD` based on `g_useEPFFormat`, checks the frame count through `g_pEPFResourceManager`, and loads the selected frame into its embedded frame object.

## Method Families

| Address | Function | Role |
| --- | --- | --- |
| `0x005954c0-0x0059558f` | `EPFTextEditObject::EPFTextEditObject` | Initialize base text object and load the requested symbol frame. |
| `0x00595630-0x0059566d` | scalar deleting destructor | Deleting-destructor vtable entry. |

## Evidence Notes

- Wave3 notes identify a 60-byte object with an `EPFFrame` at offset `0x14`.
- IDA MCP reports direct constructor references at `0x00566da3`, `0x005707c1`, and `0x005a0277`.
- The constructor uses `g_pEPFResourceManager` and `g_useEPFFormat`, then loads either `SYMBOLS.EPF` or `SYMBOLS.EPD`.

## Current Caveats

- Wave3 reports high manual confidence but a low auto grade because generated source still treats `LObject`, `EPFFrame`, and EPF resource globals as unresolved at grading time. Treat the class behavior as strong, and the auto grade as a data-quality issue.

## Cross-References

- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000EN][TextEditObject](by-class/TextEditObject.md)
- [UID:0001JT][0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter](by-memory/0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `72/80`.
  - Summary/evidence: symbol-frame text-edit object role, constructor/destructor ranges, EPF/EPD resource selection, constructor callers, and Wave3 grading caveat are documented; remaining work is exact original file split and fuller embedded `EPFFrame` layout detail.
