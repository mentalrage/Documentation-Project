*** UID:00002C | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanEnlistListPane : public ClanStringListPane
{
public:
    ClanEnlistListPane();

protected:
    virtual int OnSelectedRowAction();
    virtual bool OnKeyEvent(const PaneKeyEvent *event);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ClanEnlistListPane

## Status

- Confidence: strong for existence, inline construction, vtable slots, shared row renderer, selected-row action, key/event handler evidence, subtype `6` packet wiring, and Clan owner routing; medium-high for final class declaration and source-facing method names.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Parent attachment: attached to [UID:0000I8][Clan](by-file/Clan.md) because the class page and Clan source-layout page are above the parent-attachment gate.

## Class Purpose

`ClanEnlistListPane` is a `ListPane` child created inline by `ClanStatusPane` for clan enlistment list rows. It shares the clan string row renderer with `ClanStringListPane` and `ClanJoinListPane`, and owns enlist-list action/event handlers that submit the selected row through clan subtype `6` packet helpers.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| inline setup in `ClanStatusPane` constructor | `0x004841a0-0x00484201` | Allocates the 332-byte `ListPane` child, installs `ClanEnlistListPane` vtables, stores it at `ClanStatusPane + 0x2518`, and calls `Pane::SetMode(1)`. |
| inherited/shared `DrawItem` | [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) | Reuses `ClanStringListPane::DrawItem(int rowIndex, const wchar_t *rowText, const RectBounds *rowBounds)` at vtable slot `+0x80`; this class does not own a separate draw body. |
| selected-row action | [UID:000412][0x00488970-0x00488991.ClanEnlistListPaneSelectedRowAction](by-memory/0x00488970-0x00488991.ClanEnlistListPaneSelectedRowAction.md) | Vtable slot `0x006158b0`; `ClanEnlistListPane::OnSelectedRowAction()` checks selected index `+0x134`, returns the negative index when no row is selected, retrieves the selected applicant row through `GetSelectedEntry`, loads `g_pClanStatusPane`, and submits it through [UID:00021K][0x00485960-0x00485abe.ClanEnlistListRefreshAndSelectionPacketHelpers](by-memory/0x00485960-0x00485abe.ClanEnlistListRefreshAndSelectionPacketHelpers.md) / `ClanStatusPane::SendClanEnlistListSelectionPacket`. |
| key handler | [UID:000413][0x004889a0-0x00488b3d.ClanEnlistListPaneOnKeyEvent](by-memory/0x004889a0-0x00488b3d.ClanEnlistListPaneOnKeyEvent.md) | Vtable slot `0x00615898`; `ClanEnlistListPane::OnKeyEvent(const PaneKeyEvent *event)` delegates to `ListPane::OnKeyEvent`, handles Enter (`0x0d`) through `ClanStatusPane::SendClanEnlistListSelectionPacket`, and handles narrowed key code `0x84` through an inline `{0x4b, 6, 3}` selected-name packet followed by `ClanStatusPane::SendClanEnlistListRefreshPacket`. |

## Evidence Notes

- IDA MCP rechecked on 2026-05-24: `ClanStatusPane::ClanStatusPane` installs `ClanEnlistListPane` vtables at object offsets `+0x0`, `+0xa0`, and `+0xa4`.
- 2026-06-16 A002 continuation audit in live IDA MCP session `a002_goal65_20260616` reconfirmed `sub_484030` size `0x1f2` and constructor vtable store xref `0x004841d5 -> 0x00615834` for the primary `ClanEnlistListPane` table.
- 2026-06-05 live IDA refresh of [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) reconfirms the shared draw method at `0x004887d0` with size `0xf1`, no direct callers, and the `ClanEnlistListPane` vtable xref at `0x006158b4`.
- 2026-06-20 Rule 26 incorporation of B001 source-quality research clarifies that the `0x006158b4` slot reuses the same source body emitted once as `ClanStringListPane::DrawItem(int rowIndex, const wchar_t *rowText, const RectBounds *rowBounds)`. `ClanEnlistListPane` supplies the list payload context through inherited `ListPane` dispatch but does not own a duplicate draw implementation.
- 2026-06-22 B014 PE/Capstone revalidation confirms this class's reused draw slot is one of exactly three absolute refs to `0x004887d0`; no direct rel32 or RVA route exists, and adjacent `ClanEnlistListPane` slots stay separate (`+0x7c` at `0x006158b0 -> 0x00488970`, `+0x64` at `0x00615898 -> 0x004889a0`). This reinforces that `ClanEnlistListPane` is a reuse context and should not get a duplicate draw-body emitter.
- 2026-06-16 `lookup_funcs` reconfirmed the selected-row action as `sub_488970`, size `0x21`, and the input handler as `sub_4889A0`, size `0x19d`; `xref_query` reports vtable-only refs `0x006158b0 -> 0x00488970` and `0x00615898 -> 0x004889a0`.
- 2026-06-16 decompilation shows `0x00488970` reading selected index `this[77]` (`+0x134`), calling `0x004f3dc0`, and then calling `0x004859d0`. The larger handler first delegates to `0x004f4300`, narrows the incoming event through the process ctype object, sends Enter through `0x004859d0`, and for key `132` (`0x84`) writes packet bytes `75, 6, 3` (`0x4b, 6, 3`), converts the selected wide row text, enforces the `< 0x100` conversion and `< 0x80` packet-length guards, sends through [UID:0001P0][0x0067a7ec-0x0067a7f0.g_packetSender](by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md) / `0x0067a7ec`, then calls `0x00485960`.
- 2026-06-19 B015 reanalysis resolves the `0x004859d0` call as `g_pClanStatusPane->SendClanEnlistListSelectionPacket(applicantName)` and the `0x00485960` follow-up as `g_pClanStatusPane->SendClanEnlistListRefreshPacket()`. `applicantName` is descriptive/inferred from selected enlist-list row context. `ClanEnlistListPane` remains a caller/consumer, not the direct owner, because the callers pass `g_pClanStatusPane` as the receiver.
- [UID:000412][0x00488970-0x00488991.ClanEnlistListPaneSelectedRowAction](by-memory/0x00488970-0x00488991.ClanEnlistListPaneSelectedRowAction.md) and [UID:000413][0x004889a0-0x00488b3d.ClanEnlistListPaneOnKeyEvent](by-memory/0x004889a0-0x00488b3d.ClanEnlistListPaneOnKeyEvent.md) are the exact class-owned children split from the mixed [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md) index. They carry first-draft C++ and preserve the vtable-only/no-direct-caller proof at `0x006158b0` and `0x00615898`.
- IDA vtable symbol `??_7ClanEnlistListPane@@6B@` starts at `0x00615834`; slot `+0x80` points to `0x004887d0`.
- 2026-06-16 `get_bytes` confirmed only `0xcc` alignment around the handler bodies: `0x00488968-0x00488970`, `0x00488991-0x004889a0`, and `0x00488b3d-0x00488b40`.
- 2026-06-16 A002 continuation audit also checked `auto-generated/NexusTK/social/Clan.cpp`; the root is still zero bytes, matching the blank final-C++ block while inherited `ListPane` slot names, final packet-helper names, class declaration spelling, and key `0x84` semantics remain source-quality blockers.
- The shared handler cluster stays attached to [UID:0000I8][Clan](by-file/Clan.md) because the range also includes a `ClanJoinListPane` handler; this class page records the `ClanEnlistListPane` ownership of the two enlist slots.
- With shared draw at `84/90`, the list-handler cluster at `84/90`, subtype `6` packet helpers at `84/90`, exact vtable data at `86/91`, and inline construction evidence in [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md), this class now clears the stricter `85/85` target gate.

## Blocker Investigation

- Owner/emitter: unchanged as [UID:0000I8][Clan](by-file/Clan.md). The executable handlers are vtable-backed Clan list-pane methods, and the only direct source-family evidence is the surrounding Clan status/list cluster.
- Split/merge/range: the old shared [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md) range has been accepted as a non-emitting index. This class owns exact children [UID:000412][0x00488970-0x00488991.ClanEnlistListPaneSelectedRowAction](by-memory/0x00488970-0x00488991.ClanEnlistListPaneSelectedRowAction.md) and [UID:000413][0x004889a0-0x00488b3d.ClanEnlistListPaneOnKeyEvent](by-memory/0x004889a0-0x00488b3d.ClanEnlistListPaneOnKeyEvent.md); `0xcc` padding before and between them remains ignored alignment.
- Field/type/helper names: selected index `+0x134`, the selected-entry helper, subtype `6` action `0/1/3` packet shapes, and the sender global are verified. Final field names, the common `ListPane` virtual slot names, and a user-facing meaning for key/event code `0x84` remain unsafe because this pass did not find source-quality names beyond decompiler generic helpers and numeric protocol values.
- Final C++: intentionally blank. The class and methods are reconstructable, but source-ready class declaration, inherited `ListPane` slot names, and final packet helper names are not yet at final-C++ quality.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md)
- [UID:00002L][ClanStringListPane](by-class/ClanStringListPane.md)
- [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md)
- [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md)
- [UID:00021K][0x00485960-0x00485abe.ClanEnlistListRefreshAndSelectionPacketHelpers](by-memory/0x00485960-0x00485abe.ClanEnlistListRefreshAndSelectionPacketHelpers.md)
- [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md)
- [UID:000412][0x00488970-0x00488991.ClanEnlistListPaneSelectedRowAction](by-memory/0x00488970-0x00488991.ClanEnlistListPaneSelectedRowAction.md)
- [UID:000413][0x004889a0-0x00488b3d.ClanEnlistListPaneOnKeyEvent](by-memory/0x004889a0-0x00488b3d.ClanEnlistListPaneOnKeyEvent.md)
- [UID:0002MQ][0x00615570-0x006158f4.ClanPaneListVtableData](by-memory/0x00615570-0x006158f4.ClanPaneListVtableData.md)
- [UID:0001P0][0x0067a7ec-0x0067a7f0.g_packetSender](by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md)

## Changes

- 2026-06-19 B015 source-quality report accepted by supervisor:
  - Updated selected-row and input-handler notes to use [UID:00021K][0x00485960-0x00485abe.ClanEnlistListRefreshAndSelectionPacketHelpers](by-memory/0x00485960-0x00485abe.ClanEnlistListRefreshAndSelectionPacketHelpers.md), `ClanStatusPane::SendClanEnlistListSelectionPacket`, and `ClanStatusPane::SendClanEnlistListRefreshPacket`.
  - Preserved the distinction that `ClanEnlistListPane` supplies selected-row/applicant text and event context, while [UID:00021K][0x00485960-0x00485abe.ClanEnlistListRefreshAndSelectionPacketHelpers](by-memory/0x00485960-0x00485abe.ClanEnlistListRefreshAndSelectionPacketHelpers.md) is directly owned/emitted by [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md).
- 2026-05-27: The class purpose and method inventory previously stated no unique action method was confirmed. Added the confirmed `0x00488970-0x00488991` selected-row action and `0x004889a0-0x00488b3d` key/event handler from [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md). Evidence: IDA MCP data xrefs from `ClanEnlistListPane` vtable slots `0x006158b0` and `0x00615898`, decompilation, and calls now documented by [UID:00021K][0x00485960-0x00485abe.ClanEnlistListRefreshAndSelectionPacketHelpers](by-memory/0x00485960-0x00485abe.ClanEnlistListRefreshAndSelectionPacketHelpers.md).
- What existed before: the page documented inline construction and vtable-backed methods, but metadata was still `0/0`.
- What it was changed to: scores were set to `76/82`.
- Summary and evidence: inline setup, row renderer, selected-row action, key/event handler, vtable slots, and subtype `6` packet helpers are covered; complete source-facing class declaration remains incomplete.
- 2026-05-31: Replaced the raw shared draw address with the exact by-memory link. Evidence: IDA MCP `lookup_funcs`, `decompile`, and `xrefs_to` confirm the shared draw body and `ClanEnlistListPane` vtable slot.
- 2026-06-05: Raised from `76/82` to `82/88`, attached to [UID:0000I8][Clan](by-file/Clan.md), and removed stale recovered-file and issue-note provenance. Evidence: live IDA child pages reconfirm the shared draw slot at `0x006158b4`, the selected-row action and key/event handler vtable refs at `0x006158b0` and `0x00615898`, subtype `6` packet-helper dependency, and inline construction anchored in [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md). No child parent reroute was made because the concrete handler page spans both join and enlist list-pane classes and remains correctly file-parented.
- 2026-06-16 A002 Goal 2 class-completion refresh:
  - Raised from `82/88` to `86/90`.
  - Owner/emitter remains [UID:0000I8][Clan](by-file/Clan.md).
  - Evidence: live IDA MCP session `a002_goal65_20260616` reconfirmed constructor/vtable reachability, `0x00488970` and `0x004889a0` function sizes, vtable-only refs at `0x006158b0` and `0x00615898`, shared draw slot `0x006158b4`, selected-row retrieval through `0x004f3dc0`, subtype `6` action `1` send through `0x004859d0`, inline `{0x4b, 6, 3}` action path with `g_packetSender`, action `0` follow-up helper `0x00485960`, and surrounding `0xcc` padding.
  - Remaining cap: final class declaration, common `ListPane` virtual slot names, and semantic naming for key/event `0x84` are still not source-quality.
- 2026-06-16 A002 same-task continuation audit:
  - Scores remain `86/90`; owner/emitter remains [UID:0000I8][Clan](by-file/Clan.md).
  - Evidence checked: live IDA `lookup_funcs`, `xrefs_to`, `decompile`, `get_bytes`, linked helper pages, class/file coverage rows, and the generated `Clan.cpp` root. The unresolved names above could not be safely resolved because the current IDB and support docs expose only vtable offsets, synthetic helper names, offsets, and numeric packet values, not original source declarations.
- 2026-06-20 Rule 26 shared-draw update:
  - Clarified that `ClanEnlistListPane` reuses [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) as `ClanStringListPane::DrawItem(...)`; no separate `ClanEnlistListPane` draw implementation or emitter route is created.
  - Evidence: B001 source-quality reanalysis ties the reused vtable slot `0x006158b4` to the same row renderer body and to the `ListPane::OnPaint` `(rowIndex, itemPayload, rowBounds)` dispatch shape.
- 2026-06-22 B014 shared-draw support sync:
  - Confirmed the `0x006158b4` draw slot through direct PE absolute-reference scanning and kept `ClanEnlistListPane` as a caller/reuse context only.
  - Evidence: the only route to [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) is the shared vtable slot; class-specific selected-row and key handlers are adjacent separate slots, so draw C++ remains emitted once by [UID:00002L][ClanStringListPane](by-class/ClanStringListPane.md).
- 2026-06-22 Rule 26 split-child support sync:
  - Replaced stale no-split wording with exact children [UID:000412][0x00488970-0x00488991.ClanEnlistListPaneSelectedRowAction](by-memory/0x00488970-0x00488991.ClanEnlistListPaneSelectedRowAction.md) and [UID:000413][0x004889a0-0x00488b3d.ClanEnlistListPaneOnKeyEvent](by-memory/0x004889a0-0x00488b3d.ClanEnlistListPaneOnKeyEvent.md).
  - Evidence: B015 raw PE recheck confirms the `0x00488970-0x00488991` and `0x004889a0-0x00488b3d` bodies, vtable-only pointers `0x006158b0` and `0x00615898`, zero direct rel32 callers, selected-entry retrieval, `g_pClanStatusPane` action `1` send route, inline subtype `6` action `3` packet bytes, `g_packetSender` send path, and action `0` refresh follow-up.
