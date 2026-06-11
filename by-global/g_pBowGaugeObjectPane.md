*** UID:0000QA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pBowGaugeObjectPane

## Status

- Address: `0x0069ba24`
- Primary memory doc: [UID:0001PY][0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane](by-memory/0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane.md)
- Type kind: inferred singleton pointer.
- Owner class: [UID:000011][BowGaugeObjectPane](by-class/BowGaugeObjectPane.md)
- Likely owner source: [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md), possibly grouped privately with [UID:0000P1][UserPane](by-file/UserPane.md)
- Confidence: strong.

## Symbol Role

`g_pBowGaugeObjectPane` stores the active local-player bow gauge child pane. `BowGaugeObjectPane::BowGaugeObjectPane` writes it, the scalar deleting destructor clears it, and `UserPane` show/hide/destructor paths use it to position, hide, remove timers from, or delete the bow-gauge pane.

## Evidence Notes

- IDA MCP `xrefs_to 0x0069ba24` reports constructor write evidence at `0x00538be4` and destructor clear evidence at `0x0053cfe6`.
- The same xrefs include `UserPane` non-deleting destructor, `ShowNameLabel`, `HideNameLabel`, and scalar deleting destructor paths.
- The tiny timer cleanup helper at [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md) is called only through these `UserPane` cleanup/hide paths.

## Cross-References

- [UID:000011][BowGaugeObjectPane](by-class/BowGaugeObjectPane.md)
- [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md)
- [UID:0001PY][0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane](by-memory/0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane.md)
- [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md)
- [UID:0000P1][UserPane](by-file/UserPane.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/84`. Summary/evidence: the page documents address, memory page, owner class/source, singleton role, constructor/destructor xrefs, UserPane consumers, timer cleanup helper, and refs.
- 2026-06-05: Marked reconstructable under [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md). Evidence: live IDA MCP reports constructor/destructor xrefs plus UserPane consumers for `0x0069ba24`; decompilation confirms `0x00538bc0` writes `dword_69BA24` and `0x0053cfe0` clears it.
