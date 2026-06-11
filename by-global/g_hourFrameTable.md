*** UID:0002ZE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_hourFrameTable

## Status

- Address: `0x0066db04`
- Exact storage: `by-memory/0x0066db04-0x0066db1c.HourPaneFrameTable.md`.
- Current IDA name: `word_66DB04`.
- Kind: twelve-entry HourPane frame lookup table.
- Likely type: `uint16_t[12]`.
- Source owner: [UID:0000JX][HourPane](by-file/HourPane.md).
- Rebuild handling: source-declared table; exact address is linker-produced.

## Role

`HourPane::OnPaint` uses this table to map `(currentHour / 2) % 12` onto the resource frame number passed to the `TIME.EPF` or `TIME.EPD` draw path. The table reorders the two-hour buckets as `10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9`.

## Evidence

- 2026-06-07 A007 IDA MCP byte read confirms the exact twelve words at `0x0066db04-0x0066db1c`.
- `xrefs_to 0x0066db04` reports only `0x004cf060` and `0x004cf0f7`, both in the HourPane paint function `0x004cf010-0x004cf139`.
- Instruction windows show both branches divide the current hour by two, take modulo 12, load `word_66DB04[edx*2]`, then pass the selected frame to the current `TIME.EPF` path or legacy `TIME.EPD` path.
- The former tail at `0x0066db1c-0x0066db3c` has no direct xrefs and is split separately, so it is not part of this global table.

## Source Ownership

Keep this declaration with HourPane/time-resource behavior. It is not a resource payload: the EPF/EPD/PAL bytes belong to asset packaging, while this table is source-declared frame ordering data.

`AUTOGEN_PARENT_UID:0000JX` is now justified because this global is `88/91` and direct parent [UID:0000JX][HourPane](by-file/HourPane.md) now clears the strict parent gate at `88/85`. The exact by-memory child [UID:00027K][0x0066db04-0x0066db1c.HourPaneFrameTable](by-memory/0x0066db04-0x0066db1c.HourPaneFrameTable.md) also clears the gate and is now assigned directly to the same file parent, because source-declared static data belongs to `HourPane.cpp` rather than to a by-global parent in generated memory coverage.

## Cross-References

- [UID:0000JX][HourPane](by-file/HourPane.md)
- [UID:000068][HourPane](by-class/HourPane.md)
- [UID:00016Y][0x004cee60-0x004cf1ef.HourPane](by-memory/0x004cee60-0x004cf1ef.HourPane.md)
- [UID:0001RC][hourpane-time-resources](by-resource/hourpane-time-resources.md)

## Changes

- 2026-06-07 A007 Batch 052: Created exact by-global parent for the split HourPane frame table after live IDA confirmed the table bytes, two HourPane paint refs, and non-ownership of the old tail constants.
- 2026-06-07 A007 Batch 076 coverage-error repair: documented that [UID:00027K][0x0066db04-0x0066db1c.HourPaneFrameTable](by-memory/0x0066db04-0x0066db1c.HourPaneFrameTable.md) must remain autogen-unassigned while generated memory coverage rejects by-global parent UIDs. This page remains the exact semantic/evidence anchor at `88/91`.
- 2026-06-10 A001 parent-gate repair:
  - Changed `AUTOGEN_PARENT_UID` from blank to `0000JX`.
  - Summary/evidence: direct parent [UID:0000JX][HourPane](by-file/HourPane.md) is now `88/85`, this global is `88/91`, and exact memory child [UID:00027K][0x0066db04-0x0066db1c.HourPaneFrameTable](by-memory/0x0066db04-0x0066db1c.HourPaneFrameTable.md) is `90/92`, so the corrected strict `85/85` global-to-file gate clears. C++ remains blank below the final `95/95` gate.
