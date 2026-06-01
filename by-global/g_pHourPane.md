*** UID:0000R4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pHourPane

## Status

- Confidence: strong for address and lifecycle, medium for final declaration owner.
- Address: `0x0069b418`
- Current aliases: `dword_69B418`, `DAT_0069b418`, generated `g_pItemShopPane`
- Kind: process-wide singleton pointer to [UID:000068][HourPane](by-class/HourPane.md)
- Proposed owner module: [UID:0000JX][HourPane](by-file/HourPane.md)
- Evidence basis: `simroot_v2` generated source plus IDA MCP xrefs/decompilation on 2026-05-24.

## Lifecycle

- Set in `HourPane::HourPane` at `0x004cee85`, with a null/sentinel branch when the adjusted owner pointer would be null.
- Cleared by the non-deleting cleanup helper at `0x004ceeb0`.
- Cleared by the scalar deleting destructor at `0x004cf190`.
- Read during main UI shutdown at `0x00504a18`; if non-null, the client passes it to the pane-child removal helper at `0x00504a24`.

## Ownership Notes

The generated name `g_pItemShopPane` is not consistent with the xrefs. The global is written only by the `HourPane` constructor/cleanup/destructor paths in this island, while the next singleton `0x0069b41c` is written by `IconsPane` at `0x004cf1f0`. Treat `g_pHourPane` as the canonical documentation name until source migration proves otherwise.

## Data Caveats

Active generated output uses `g_pItemShopPane` for this address and omits some functions that clear/update related HourPane state. Do not migrate the generated global name directly into source ownership.

## Cross-References

- [UID:000068][HourPane](by-class/HourPane.md)
- [UID:0000JX][HourPane](by-file/HourPane.md)
- [UID:00016Y][0x004cee60-0x004cf1ef.HourPane](by-memory/0x004cee60-0x004cf1ef.HourPane.md)
- [UID:0001RC][hourpane-time-resources](by-resource/hourpane-time-resources.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `82/78`. Summary/evidence: the page documents address, aliases, HourPane singleton role, lifecycle set/clear/read sites, ownership notes, generated-name caveat, and refs; final declaration owner remains medium-confidence.
