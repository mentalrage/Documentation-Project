*** UID:0000SM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pUrlAlertPane

## Status

- Symbol kind: process-wide singleton pointer.
- Address: `0x0069b4dc`
- Current generated owner: `class_UrlAlertPane.cpp`
- Likely source module: [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- Confidence: strong.

## Purpose

`g_pUrlAlertPane` tracks the active [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md), if one is displayed. The constructor stores the new pane pointer, and both destructor paths clear it.

## Evidence Notes

- IDA decompilation of `0x00599a40` writes `this` to `0x0069b4dc` after calling `AlertPane::AlertPane`.
- IDA decompilation of `0x00599b20` and `0x00599c00` clears the same address during teardown.
- IDA MCP `py_eval` rechecked `0x0069b4dc` on 2026-05-31 and confirmed IDA name `dword_69B4DC`, initial dword `0xffffffff`, and 6 data xrefs: one external active-alert check at `0x00508fd6`, constructor writes at `0x00599a94` and `0x00599a9b`, destructor clear at `0x00599b73`, constructor-cleanup clear at `0x00599bd0`, and scalar deleting destructor clear at `0x00599c5a`.

## Cross-References

- [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md)
- [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md)
- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)

## Changes

- 2026-05-31: Updated reconstruction metadata and scores from live IDA evidence.
  - Before: completion/confidence were `0/0`, reconstructable state was blank, and no parent file UID was assigned.
  - After: `COMPLETION:70`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000HE` for [UID:0000HE][AlertPanes](by-file/AlertPanes.md). `RECONSTRUCTION_CPP CODE` remains blank because the page is below the 95+ final-source threshold.
  - Evidence: IDA MCP rechecked `0x0069b4dc` as a 4-byte singleton pointer with 6 data xrefs spanning active-alert checks, UrlAlertPane construction, cleanup, normal destructor, and scalar deleting destructor.
