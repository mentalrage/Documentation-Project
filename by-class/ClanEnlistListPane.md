*** UID:00002C | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanEnlistListPane

## Status

- Confidence: strong for existence, inline construction, vtable slots, shared row renderer, selected-row action, and key/event handler evidence; medium for final class declaration and source-facing method names.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Parent attachment: attached to [UID:0000I8][Clan](by-file/Clan.md) because the class page and Clan source-layout page are above the parent-attachment gate.

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
- 2026-06-05 live IDA refresh of [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) reconfirms the shared draw method at `0x004887d0` with size `0xf1`, no direct callers, and the `ClanEnlistListPane` vtable xref at `0x006158b4`.
- [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md) documents the `0x00488970-0x00488991` selected-row action and `0x004889a0-0x00488b3d` key/event handler, including vtable-only xrefs at `0x006158b0` and `0x00615898`.
- IDA vtable symbol `??_7ClanEnlistListPane@@6B@` starts at `0x00615834`; slot `+0x80` points to `0x004887d0`.
- The shared handler cluster stays attached to [UID:0000I8][Clan](by-file/Clan.md) because the range also includes a `ClanJoinListPane` handler; this class page records the `ClanEnlistListPane` ownership of the two enlist slots.
- With shared draw at `84/90`, the list-handler cluster at `82/88`, subtype `6` packet helpers at `84/90`, and inline construction evidence in [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md), this class now clears the parent-attachment gate.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md)
- [UID:00002L][ClanStringListPane](by-class/ClanStringListPane.md)
- [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md)
- [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md)
- [UID:00021K][0x00485960-0x00485abe.ClanSubtype6PacketHelpers](by-memory/0x00485960-0x00485abe.ClanSubtype6PacketHelpers.md)
- [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md)

## Changes

- 2026-05-27: The class purpose and method inventory previously stated no unique action method was confirmed. Added the confirmed `0x00488970-0x00488991` selected-row action and `0x004889a0-0x00488b3d` key/event handler from [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md). Evidence: IDA MCP data xrefs from `ClanEnlistListPane` vtable slots `0x006158b0` and `0x00615898`, decompilation, and calls to [UID:00021K][0x00485960-0x00485abe.ClanSubtype6PacketHelpers](by-memory/0x00485960-0x00485abe.ClanSubtype6PacketHelpers.md).
- What existed before: the page documented inline construction and vtable-backed methods, but metadata was still `0/0`.
- What it was changed to: scores were set to `76/82`.
- Summary and evidence: inline setup, row renderer, selected-row action, key/event handler, vtable slots, and subtype `6` packet helpers are covered; complete source-facing class declaration remains incomplete.
- 2026-05-31: Replaced the raw shared draw address with the exact by-memory link. Evidence: IDA MCP `lookup_funcs`, `decompile`, and `xrefs_to` confirm the shared draw body and `ClanEnlistListPane` vtable slot.
- 2026-06-05: Raised from `76/82` to `82/88`, attached to [UID:0000I8][Clan](by-file/Clan.md), and removed stale recovered-file and issue-note provenance. Evidence: live IDA child pages reconfirm the shared draw slot at `0x006158b4`, the selected-row action and key/event handler vtable refs at `0x006158b0` and `0x00615898`, subtype `6` packet-helper dependency, and inline construction anchored in [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md). No child parent reroute was made because the concrete handler page spans both join and enlist list-pane classes and remains correctly file-parented.
