*** UID:00002H | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanJoinListPane

## Status

- Confidence: strong for existence, inline construction, vtable slots, selected-row action, key/event handler, and shared row renderer; medium for final class declaration and source-facing method names.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Parent attachment: attached to [UID:0000I8][Clan](by-file/Clan.md) because the class page and Clan source-layout page are above the parent-attachment gate.

## Class Purpose

`ClanJoinListPane` is a `ListPane` child created inline by `ClanStatusPane` for clan join/status list rows. It shares the clan string row renderer and adds a selected-row action slot that forwards the selected row text to [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| inline setup in `ClanStatusPane` constructor | `0x0048413f-0x0048419b` | Allocates the 332-byte `ListPane` child, installs `ClanJoinListPane` vtables, stores it at `ClanStatusPane + 0x2514`, and shows it. |
| selected-row action | [UID:0002NR][0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction](by-memory/0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction.md) | Vtable slot `+0x7c`; if the selected index at object offset `+0x134` is nonnegative, reads the selected row text through `0x004f3dc0` and calls [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md). |
| key/event handler | `0x00488900-0x00488968` | Vtable slot `0x006157d4`; delegates to the base list-pane event handler, then sends the selected join-list row on Enter. See [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md). |
| `DrawItem` | [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) | Shared clan string row renderer at vtable slot `+0x80`. |

## Evidence Notes

- IDA MCP rechecked on 2026-05-24: `ClanStatusPane::ClanStatusPane` installs `ClanJoinListPane` vtables at object offsets `+0x0`, `+0xa0`, and `+0xa4`.
- 2026-06-05 live IDA refresh of [UID:0002NR][0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction](by-memory/0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction.md) reconfirms exact `0x21` bounds, the `0x004888f1` successor byte outside the function, vtable-only xref at `0x006157ec`, no direct callers, selected-index guard at object offset `+0x134`, selected-text retrieval through `0x004f3dc0`, clan status singleton/global load from `0x0067ade4`, and downstream packet call to `0x00485590`.
- [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md) documents the adjacent `0x00488900-0x00488968` key/event handler at vtable slot `0x006157d4`; the page stays file-parented because the range also contains `ClanEnlistListPane` handlers.
- [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) documents the shared row renderer, with the `ClanJoinListPane` vtable using it at `0x006157f0`.
- IDA vtable symbol `??_7ClanJoinListPane@@6B@` starts at `0x00615770`; slot `+0x7c` points to `0x004888d0` and slot `+0x80` points to `0x004887d0`.
- With the selected-row action at `82/90`, the shared input-handler cluster at `82/88`, the shared draw method at `84/90`, and inline construction evidence in [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md), this class now clears the semantic parent gate for the single-owner selected-row action.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md)
- [UID:00002L][ClanStringListPane](by-class/ClanStringListPane.md)
- [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md)
- [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md)
- [UID:0002NR][0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction](by-memory/0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction.md)
- [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md)
- [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md)

## Changes

- 2026-05-27: Replaced the raw `0x00485590` helper reference with [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md). Evidence: IDA MCP confirms the helper sends opcode `0x4b`, subtype `2`, action `1`, with selected row text, and callers include the `0x004888d0` selected-row action.
- 2026-05-27: The method inventory previously stopped at the `0x004888d0` selected-row action. Added the vtable-backed `0x00488900-0x00488968` key/event handler from [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md). Evidence: IDA MCP data xref `0x006157d4 -> 0x00488900`, decompilation, and call to [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md).
- What existed before: the page documented inline construction, selected-row action, key/event handler, and join-list packet helper, but metadata was still `0/0`.
- What it was changed to: scores were set to `76/82`.
- Summary and evidence: constructor setup, vtable slots, shared row renderer, selected-row send, and Enter-key path are covered; recovered method names and source-facing declaration remain incomplete.
- 2026-05-31: Replaced raw draw/action addresses with exact by-memory links. Evidence: IDA MCP `lookup_funcs`, `decompile`, and `xrefs_to` confirm the shared draw method, selected-row action method, and vtable slots.
- 2026-06-05: Raised from `76/82` to `82/88`, attached to [UID:0000I8][Clan](by-file/Clan.md), removed stale recovered-file and issue-note provenance, and promoted [UID:0002NR][0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction](by-memory/0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction.md) from file-parent routing to semantic class parent `00002H`. Evidence: live IDA MCP child refreshes reconfirm selected-row action bounds and vtable-only xref, the shared input-handler page documents the adjacent join-list event override, the shared draw page documents the row renderer slot, and inline construction remains anchored in [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md).
