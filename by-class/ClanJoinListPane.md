*** UID:00002H | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanJoinListPane

## Status

- Confidence: strong for existence, owner, and inline construction; medium for recovered method names.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Current recovered file: none in `source-3/simroot_v2`; evidence comes from IDA vtables and `ClanStatusPane` constructor decompilation.

## Class Purpose

`ClanJoinListPane` is a `ListPane` child created inline by `ClanStatusPane` for clan join/status list rows. It shares the clan string row renderer and adds a selected-row action slot that forwards the selected row text to [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| inline setup in `ClanStatusPane` constructor | `0x0048413f-0x0048419b` | Allocates the 332-byte `ListPane` child, installs `ClanJoinListPane` vtables, stores it at `ClanStatusPane + 0x2514`, and shows it. |
| selected-row action | [UID:0002NR][0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction](by-memory/0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction.md) | Vtable slot `+0x7c`; if selected index at `this + 0x134` is nonnegative, reads the selected row text through `0x004f3dc0` and calls [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md). |
| key/event handler | `0x00488900-0x00488968` | Vtable slot `0x006157d4`; delegates to the base list-pane event handler, then sends the selected join-list row on Enter. See [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md). |
| `DrawItem` | [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) | Shared clan string row renderer at vtable slot `+0x80`. |

## Evidence Notes

- IDA MCP rechecked on 2026-05-24: `ClanStatusPane::ClanStatusPane` installs `ClanJoinListPane` vtables at object offsets `+0x0`, `+0xa0`, and `+0xa4`.
- IDA MCP rechecked on 2026-05-26: `0x004888d0-0x004888f1` is the selected-row action function and has a vtable data xref at `0x006157ec`; `0x004887d0-0x004888c1` remains the shared row renderer at `0x006157f0`.
- 2026-05-31 IDA MCP split those methods into exact pages [UID:0002NR][0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction](by-memory/0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction.md) and [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md).
- IDA vtable symbol `??_7ClanJoinListPane@@6B@` starts at `0x00615770`; slot `+0x7c` points to `0x004888d0` and slot `+0x80` points to `0x004887d0`.
- IDA MCP checked on 2026-05-27: `0x00488900-0x00488968` has a vtable data xref from `0x006157d4` and calls [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md) from its Enter-key path.
- The generated `simroot_v2` tree does not currently emit a dedicated `class_ClanJoinListPane.cpp`, so source migration should treat this as a vtable/constructor-only class until Wave3 data is repaired.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md)
- [UID:00002L][ClanStringListPane](by-class/ClanStringListPane.md)
- [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md)
- [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md)
- [UID:0002NR][0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction](by-memory/0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction.md)
- [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md)
- [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md)
- [Clan data issue note](../wave3_data_issues.md)

## Changes

- 2026-05-27: Replaced the raw `0x00485590` helper reference with [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md). Evidence: IDA MCP confirms `sub_485590` sends opcode `0x4b`, subtype `2`, action `1`, with selected row text, and callers include the `0x004888d0` selected-row action.
- 2026-05-27: The method inventory previously stopped at the `0x004888d0` selected-row action. Added the vtable-backed `0x00488900-0x00488968` key/event handler from [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md). Evidence: IDA MCP data xref `0x006157d4 -> 0x00488900`, decompilation, and call to [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md).
- What existed before: the page documented inline construction, selected-row action, key/event handler, and join-list packet helper, but metadata was still `0/0`.
- What it was changed to: scores were set to `76/82`.
- Summary and evidence: constructor setup, vtable slots, shared row renderer, selected-row send, and Enter-key path are covered; recovered method names and source-facing declaration remain incomplete.
- 2026-05-31: Replaced raw draw/action addresses with exact by-memory links. Evidence: IDA MCP `lookup_funcs`, `decompile`, and `xrefs_to` confirm the shared draw method, selected-row action method, and vtable slots.
