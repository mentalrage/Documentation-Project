*** UID:0000R4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pHourPane

## Status

- Confidence: strong for address, lifecycle, and owner; medium-high for final source declaration spelling.
- Address: `0x0069b418`
- Exact storage doc: [UID:00029I][0x0069b418-0x0069b41c.g_pHourPane](by-memory/0x0069b418-0x0069b41c.g_pHourPane.md)
- Current aliases: `dword_69B418`, `DAT_0069b418`, noncanonical `g_pItemShopPane`
- Kind: process-wide singleton pointer to [UID:000068][HourPane](by-class/HourPane.md)
- Likely type: `HourPane*`
- Proposed owner module: [UID:0000JX][HourPane](by-file/HourPane.md)
- Rebuild handling: source-declared module/global singleton pointer; exact address and binary initializer are rebuilt by the linker.
- Autogen parent: [UID:0000JX][HourPane](by-file/HourPane.md); final C++ remains blank because the exact static declaration/header placement is below the `95+` source gate.
- Evidence basis: IDA MCP xrefs/decompilation.

## Lifecycle

- Set in `HourPane::HourPane` at `0x004cee85`, with a null/sentinel branch when the adjusted owner pointer would be null.
- Cleared by the non-deleting cleanup helper at `0x004ceeb0`.
- Cleared by the scalar deleting destructor at `0x004cf190`.
- Read during main UI shutdown at `0x00504a18`; if non-null, the client passes it to the pane-child removal helper at `0x00504a24`.

## Evidence Table

| Site | Use | Evidence owner |
| --- | --- | --- |
| `0x004cee85` | Constructor stores the active `HourPane` singleton. | [UID:00016Y][0x004cee60-0x004cf1ef.HourPane](by-memory/0x004cee60-0x004cf1ef.HourPane.md) and [UID:0000JX][HourPane](by-file/HourPane.md). |
| `0x004ceeb0` | Non-deleting cleanup helper clears the singleton while restoring HourPane vtables. | Same HourPane range and file owner. |
| `0x004cf190` | Scalar deleting destructor clears the singleton before base cleanup/delete handling. | Same HourPane range and file owner. |
| `0x00504a18` / `0x00504a24` | Main UI shutdown reads the pointer and removes the pane from the child graph if present. | [UID:0000JX][HourPane](by-file/HourPane.md) records creation/shutdown ownership through the main UI graph. |

## Ownership Notes

The alias `g_pItemShopPane` is not consistent with the xrefs. The global is written only by the `HourPane` constructor/cleanup/destructor paths in this island, while the next singleton `0x0069b41c` is written by `IconsPane` at `0x004cf1f0`. Treat `g_pHourPane` as the canonical documentation name until source migration proves otherwise.

Keep this global with `HourPane.cpp` rather than a broader main-UI singleton bucket. Main UI shutdown is a consumer of the pointer; the lifecycle owner is the clock/hour HUD panel source.

## Data Caveats

Do not migrate the `g_pItemShopPane` alias directly into source ownership; the storage xrefs prove this address is the `HourPane` singleton.

## Cross-References

- [UID:000068][HourPane](by-class/HourPane.md)
- [UID:0000JX][HourPane](by-file/HourPane.md)
- [UID:00016Y][0x004cee60-0x004cf1ef.HourPane](by-memory/0x004cee60-0x004cf1ef.HourPane.md)
- [UID:00029I][0x0069b418-0x0069b41c.g_pHourPane](by-memory/0x0069b418-0x0069b41c.g_pHourPane.md)
- [UID:0001RC][hourpane-time-resources](by-resource/hourpane-time-resources.md)
- [UID:0000R6][g_pIconsPane](by-global/g_pIconsPane.md)

## Changes

- 2026-06-06 A010 singleton evidence consolidation:
  - Before: `COMPLETION:82`, `CONFIDENCE:78`, with lifecycle bullets but no explicit rebuild handling, likely pointer type, source-gate note, or evidence table.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`, source-declared singleton handling, likely `HourPane*` type, final declaration caveat, lifecycle evidence table, and clearer separation from the adjacent `IconsPane` singleton.
  - Summary/evidence: existing IDA-backed docs record constructor store at `0x004cee85`, cleanup/destructor clears at `0x004ceeb0` and `0x004cf190`, and main UI shutdown read/removal at `0x00504a18`/`0x00504a24`; the by-file page owns the hour HUD panel under `NexusTK/ui/panels/`.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `82/78`. Summary/evidence: the page documents address, aliases, HourPane singleton role, lifecycle set/clear/read sites, ownership notes, alias caveat, and refs; final declaration owner remains medium-confidence.
- 2026-06-05: Marked reconstructable under [UID:0000JX][HourPane](by-file/HourPane.md). Evidence: live IDA MCP reports four xrefs to `0x0069b418`; decompilation confirms constructor `0x004cee60`, cleanup helper `0x004ceeb0`, and scalar deleting destructor `0x004cf190` write/clear `dword_69B418`, with main UI shutdown reading it at `0x00504a18`.
- 2026-06-07 A007 Batch 041 split-link update: added the exact by-memory storage doc [UID:00029I][0x0069b418-0x0069b41c.g_pHourPane](by-memory/0x0069b418-0x0069b41c.g_pHourPane.md) after the mixed Hour/Icons singleton range was split into separate `HourPane` and `IconsPane` slots.
