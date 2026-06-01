*** UID:00002C | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanEnlistListPane

## Status

- Confidence: strong for existence, owner, and inline construction; medium for complete method coverage.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Current recovered file: none in `source-3/simroot_v2`; evidence comes from IDA vtables and `ClanStatusPane` constructor decompilation.

## Class Purpose

`ClanEnlistListPane` is a `ListPane` child created inline by `ClanStatusPane` for clan enlistment list rows. It shares the clan string row renderer with `ClanStringListPane` and `ClanJoinListPane`, and owns enlist-list action/event handlers that submit the selected row through clan subtype `6` packet helpers.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| inline setup in `ClanStatusPane` constructor | `0x004841a0-0x00484201` | Allocates the 332-byte `ListPane` child, installs `ClanEnlistListPane` vtables, stores it at `ClanStatusPane + 0x2518`, and shows it. |
| `DrawItem` | [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) | Shared clan string row renderer at vtable slot `+0x80`. |
| selected-row action | `0x00488970-0x00488991` | Vtable slot `0x006158b0`; submits the selected row through [UID:00021K][0x00485960-0x00485abe.ClanSubtype6PacketHelpers](by-memory/0x00485960-0x00485abe.ClanSubtype6PacketHelpers.md) helper `0x004859d0`. |
| key/event handler | `0x004889a0-0x00488b3d` | Vtable slot `0x00615898`; handles Enter through helper `0x004859d0` and key code `0x84` through an inline subtype `6`, action `3` packet followed by helper `0x00485960`. See [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md). |

## Evidence Notes

- IDA MCP rechecked on 2026-05-24: `ClanStatusPane::ClanStatusPane` installs `ClanEnlistListPane` vtables at object offsets `+0x0`, `+0xa0`, and `+0xa4`.
- IDA MCP rechecked on 2026-05-26: `0x004887d0-0x004888c1` remains the shared row renderer and has the `ClanEnlistListPane` vtable data xref at `0x006158b4`.
- 2026-05-31 IDA MCP split the shared draw method into exact page [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md).
- IDA vtable symbol `??_7ClanEnlistListPane@@6B@` starts at `0x00615834`; slot `+0x80` points to `0x004887d0`.
- IDA MCP checked on 2026-05-27: vtable slot `0x00615898` points to `0x004889a0`, and slot `0x006158b0` points to `0x00488970`; both use [UID:00021K][0x00485960-0x00485abe.ClanSubtype6PacketHelpers](by-memory/0x00485960-0x00485abe.ClanSubtype6PacketHelpers.md) clan subtype `6` packet helpers.
- The generated `simroot_v2` tree does not currently emit a dedicated `class_ClanEnlistListPane.cpp`, so source migration should treat this as a vtable/constructor-only class until Wave3 data is repaired.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md)
- [UID:00002L][ClanStringListPane](by-class/ClanStringListPane.md)
- [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md)
- [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md)
- [UID:00021K][0x00485960-0x00485abe.ClanSubtype6PacketHelpers](by-memory/0x00485960-0x00485abe.ClanSubtype6PacketHelpers.md)
- [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md)
- [Clan data issue note](../wave3_data_issues.md)

## Changes

- 2026-05-27: The class purpose and method inventory previously stated no unique action method was confirmed. Added the confirmed `0x00488970-0x00488991` selected-row action and `0x004889a0-0x00488b3d` key/event handler from [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md). Evidence: IDA MCP data xrefs from `ClanEnlistListPane` vtable slots `0x006158b0` and `0x00615898`, decompilation, and calls to [UID:00021K][0x00485960-0x00485abe.ClanSubtype6PacketHelpers](by-memory/0x00485960-0x00485abe.ClanSubtype6PacketHelpers.md).
- What existed before: the page documented inline construction and vtable-backed methods, but metadata was still `0/0`.
- What it was changed to: scores were set to `76/82`.
- Summary and evidence: inline setup, row renderer, selected-row action, key/event handler, vtable slots, and subtype `6` packet helpers are covered; complete source-facing class declaration and generated-data repair remain incomplete.
- 2026-05-31: Replaced the raw shared draw address with the exact by-memory link. Evidence: IDA MCP `lookup_funcs`, `decompile`, and `xrefs_to` confirm the shared draw body and `ClanEnlistListPane` vtable slot.
