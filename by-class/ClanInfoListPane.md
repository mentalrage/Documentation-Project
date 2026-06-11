*** UID:00002E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanInfoListPane

## Status

- Confidence: strong for purpose, inline construction, and confirmed virtuals; medium for class reconstruction while the standalone constructor boundary remains projected.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Memory evidence: [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md), [UID:00021T][0x004885a0-0x00488602.ClanInfoListPaneRawConstructor](by-memory/0x004885a0-0x00488602.ClanInfoListPaneRawConstructor.md), [UID:0002NN][0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual](by-memory/0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual.md), and [UID:0002NO][0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual](by-memory/0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual.md)
- Parent routing: attached to the [UID:0000I8][Clan](by-file/Clan.md) source file; child memory pages now attach back to this class now that both sides meet the parent gate.

## Class Purpose

`ClanInfoListPane` is a specialized read-only `TextEditPane` child created inline by `ClanStatusPane`. Its confirmed virtual methods hard-disable two action paths, making it a passive clan information view rather than an interactive list.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| projected/raw constructor | [UID:00021T][0x004885a0-0x00488602.ClanInfoListPaneRawConstructor](by-memory/0x004885a0-0x00488602.ClanInfoListPaneRawConstructor.md) | Constructor-shaped bytes that install `ClanInfoListPane` vtables; IDA reports this is not a function and has no xrefs. |
| inline setup in `ClanStatusPane` constructor | `0x004840b2-0x00484135` | Allocates the 372-byte `TextEditPane` child, installs `ClanInfoListPane` vtables, stores it at `ClanStatusPane + 0x2510`, shows it, and marks it read-only. |
| `CanExecuteAction` | [UID:0002NN][0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual](by-memory/0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual.md) | Returns false; vtable data xref at `0x00615678`. |
| `CanExecuteAlternateAction` | [UID:0002NO][0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual](by-memory/0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual.md) | Returns false; vtable data xref at `0x00615658`. |

## Evidence Notes

- IDA MCP rechecked on 2026-05-24 and 2026-05-27: `0x004885a0` is not an IDA function and has no xrefs, but [UID:00021T][0x004885a0-0x00488602.ClanInfoListPaneRawConstructor](by-memory/0x004885a0-0x00488602.ClanInfoListPaneRawConstructor.md) records the constructor-shaped byte body and vtable stores.
- `ClanStatusPane::ClanStatusPane` allocates 372 bytes, calls the `TextEditPane` constructor helper with `(156, 192, 156, 192, 128, 0, 0, 1, 2, helper-result, 1, 0)`, where the helper call is at `0x004b60b0`, and installs `ClanInfoListPane` vtables at object offsets `+0x0`, `+0xa0`, and `+0xa4`.
- IDA confirms the two false-return virtuals at `0x00488610` and `0x00488620`.
- IDA MCP recheck on 2026-05-26 reconfirms `0x00488610` and `0x00488620` as five-byte false-return functions and places them in `ClanInfoListPane` vtable slots at `0x00615678` and `0x00615658`.
- 2026-05-31 IDA MCP recheck split those false-return virtuals into exact memory pages [UID:0002NN][0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual](by-memory/0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual.md) and [UID:0002NO][0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual](by-memory/0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual.md).
- 2026-06-05 live IDA refreshes on [UID:00021T][0x004885a0-0x00488602.ClanInfoListPaneRawConstructor](by-memory/0x004885a0-0x00488602.ClanInfoListPaneRawConstructor.md), [UID:0002NN][0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual](by-memory/0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual.md), and [UID:0002NO][0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual](by-memory/0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual.md) reconfirm raw constructor-shaped bytes, exact false-return bodies, vtable-only xrefs, no direct callers for the tiny virtuals, and Clan source ownership.
- The projected constructor should not be used as a rename/source-map anchor until the `0x004885a0` body is represented as final source-quality callable constructor proof.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md)
- [UID:00021T][0x004885a0-0x00488602.ClanInfoListPaneRawConstructor](by-memory/0x004885a0-0x00488602.ClanInfoListPaneRawConstructor.md)
- [UID:00010I][0x00488610-0x004888f1.ClanListPaneVirtuals](by-memory/0x00488610-0x004888f1.ClanListPaneVirtuals.md)
- [UID:0002NN][0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual](by-memory/0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual.md)
- [UID:0002NO][0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual](by-memory/0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual.md)
- [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md)

## Changes

- 2026-05-27: The constructor entry previously described `0x004885a0` only as a projected start to avoid. Changed it to [UID:00021T][0x004885a0-0x00488602.ClanInfoListPaneRawConstructor](by-memory/0x004885a0-0x00488602.ClanInfoListPaneRawConstructor.md): a real constructor-shaped byte body with no IDA function object or inbound xrefs. Evidence: IDA MCP raw disassembly shows `ClanInfoListPane` vtable stores at `+0x0`, `+0xa0`, and `+0xa4`, while xref/function scans remain negative.
- What existed before: the page documented inline construction, passive read-only behavior, false-return virtuals, and raw constructor caveats, but metadata still read `0/0`.
- What it was changed to: scores were set to `78/84`.
- Summary and evidence: inline allocation/setup, vtable slots, raw constructor bytes, and read-only virtual behavior are covered; source-facing declaration and standalone constructor modeling remain incomplete.
- 2026-05-31: Replaced raw false-virtual addresses with exact by-memory links. Evidence: IDA MCP `lookup_funcs`, `decompile`, and `xrefs_to` confirm the two five-byte bodies and their vtable xrefs.
- 2026-06-05: Marked reconstructable, but left `AUTOGEN_PARENT_UID` blank because the class was `78/84`, below the 80/80 parent-attachment gate, even though [UID:0000I8][Clan](by-file/Clan.md) remained the likely owner. Live IDA MCP `lookup_funcs` confirmed the false-return virtuals at `0x00488610` and `0x00488620`, and reconfirmed that `0x004885a0` is not an IDA function.
- 2026-06-05: Updated to `82/88`, attached parent `0000I8`, removed stale external recovered-file and projected-start issue references, converted helper-call evidence to address-based wording, and routed [UID:00021T][0x004885a0-0x00488602.ClanInfoListPaneRawConstructor](by-memory/0x004885a0-0x00488602.ClanInfoListPaneRawConstructor.md), [UID:0002NN][0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual](by-memory/0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual.md), and [UID:0002NO][0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual](by-memory/0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual.md) under this class now that the class and children meet the parent gate. Evidence: the same-day child refreshes document the raw constructor-shaped bytes, exact false-return bodies, vtable-only xrefs, no direct callers for the tiny virtuals, and Clan source ownership.
