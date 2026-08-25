*** UID:0002ZE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static short g_hourFrameTable[12] =
{
    10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_hourFrameTable

## Status

- Address: `0x0066db04`
- Exact storage: `by-memory/0x0066db04-0x0066db1c.HourPaneFrameTable.md`.
- Current IDA name: `word_66DB04`.
- Kind: twelve-entry HourPane frame lookup table.
- Exact source type: writable file-local `short[12]`.
- Source owner: [UID:0000JX][HourPane](by-file/HourPane.md).
- Rebuild handling: source-declared table; exact address is linker-produced.

## Role

`HourPane::OnPaint` uses this table to map `(currentHour / 2) % 12` onto the resource frame number passed to the `TIME.EPF` or `TIME.EPD` draw path. The table reorders the two-hour buckets as `10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9`.

## Evidence

- 2026-06-07 A007 IDA MCP byte read confirms the exact twelve words at `0x0066db04-0x0066db1c`.
- `xrefs_to 0x0066db04` reports only `0x004cf060` and `0x004cf0f7`, both in the HourPane paint function `0x004cf010-0x004cf139`.
- Instruction windows show both branches divide the current hour by two, take modulo 12, load `word_66DB04[edx*2]`, then pass the selected frame to the current `TIME.EPF` path or legacy `TIME.EPD` path.
- The former tail at `0x0066db1c-0x0066db3c` has no direct xrefs and is split separately, so it is not part of this global table.
- Exact little-endian values are `10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9`; all are nonnegative, so signedness does not change runtime indexing, while current source style and consumer promotion support `short`.
- Storage resides in writable data rather than read-only resource bytes. No write xref is present after image initialization, so the source definition is writable by placement but behaviorally constant.
- The symbol has no external consumer, declaration route, or address-taking evidence outside UID0004NN `HourPane::OnPaint`. File-local `static` linkage is therefore the best source reconstruction and is explicitly confidence-capped by absent original symbols.

## Source Ownership

Keep this declaration with HourPane/time-resource behavior. It is not a resource payload: the EPF/EPD/PAL bytes belong to asset packaging, while this table is source-declared frame ordering data.

UID0000JX owns this global at source position 20. Exact by-memory storage UID00027K emits later at position 110 as a covered-by marker through the same file route. The table belongs to `HourPane.cpp`, not an asset payload, generic timekeeping module, or extension into adjacent unreferenced data.

## Negative And Historical Evidence

- Reject `uint16_t` as the preferred written declaration, a 28-entry extension through `0x0066db3c`, read-only resource ownership, class-member storage, external linkage, and ownership by the paint callback.
- The former tail-extension possibility is superseded by the exact two-xref set, modulo-12 bound, and separate successor range. No tail value is addressed by HourPane.
- The prior blank managed block reflected a score gate, not a source-shape blocker. Exact Destination 12 now carries the only source definition; UID00027K carries only its covered-by marker.

## Cross-References

- [UID:0000JX][HourPane](by-file/HourPane.md)
- [UID:000068][HourPane](by-class/HourPane.md)
- [UID:00016Y][0x004cee60-0x004cf1ef.HourPane](by-memory/0x004cee60-0x004cf1ef.HourPane.md)
- [UID:0001RC][hourpane-time-resources](by-resource/hourpane-time-resources.md)

## Changes

- 2026-07-14 B005 callback: raised `88/91 -> 92/94`, set source position 20, applied the exact file-local twelve-short definition, preserved writable-data/two-xref evidence, and rejected tail extension and alternate ownership/type routes.
- 2026-06-07 A007 Batch 052: Created exact by-global parent for the split HourPane frame table after live IDA confirmed the table bytes, two HourPane paint refs, and non-ownership of the old tail constants.
- 2026-06-07 A007 Batch 076 coverage-error repair: documented that [UID:00027K][0x0066db04-0x0066db1c.HourPaneFrameTable](by-memory/0x0066db04-0x0066db1c.HourPaneFrameTable.md) must remain autogen-unassigned while generated memory coverage rejects by-global parent UIDs. This page remains the exact semantic/evidence anchor at `88/91`.
- 2026-06-10 A001 parent-gate repair:
  - Changed `AUTOGEN_PARENT_UID` from blank to `0000JX`.
  - Summary/evidence: direct parent [UID:0000JX][HourPane](by-file/HourPane.md) is now `88/85`, this global is `88/91`, and exact memory child [UID:00027K][0x0066db04-0x0066db1c.HourPaneFrameTable](by-memory/0x0066db04-0x0066db1c.HourPaneFrameTable.md) is `90/92`, so the corrected strict `85/85` global-to-file gate clears. C++ remains blank below the final `95/95` gate.
