*** UID:00002H | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanJoinListPane : public ClanStringListPane
{
public:
    ClanJoinListPane();

protected:
    virtual int OnSelectedRowAction();
    virtual bool OnKeyEvent(const PaneKeyEvent *event);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ClanJoinListPane

## Status

- Confidence: strong for existence, inline construction, vtable slots, selected-row action, key/event handler, shared row renderer, selected-text packet helper, and Clan owner routing; medium-high for final class declaration and source-facing method names.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Parent attachment: attached to [UID:0000I8][Clan](by-file/Clan.md) because the class page and Clan source-layout page are above the parent-attachment gate.

## Class Purpose

`ClanJoinListPane` is a `ListPane` child created inline by `ClanStatusPane` for clan join/status list rows. It shares the clan string row renderer and adds a selected-row action slot that forwards the selected row text to [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md), now modeled as `ClanStatusPane::SendClanJoinListSelectionPacket(const wchar_t *selectedClanName)`. This class supplies the selected text; it is not the packet helper owner.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| inline setup in `ClanStatusPane` constructor | `0x0048413f-0x0048419b` | Allocates the 332-byte `ListPane` child, installs `ClanJoinListPane` vtables, stores it at `ClanStatusPane + 0x2514`, and calls `Pane::SetMode(1)`. |
| selected-row action | [UID:0002NR][0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction](by-memory/0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction.md) | Vtable slot `+0x7c`; if the selected index at object offset `+0x134` is nonnegative, reads the selected row text through `0x004f3dc0`, loads `g_pClanStatusPane`, and calls [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md) as a `ClanStatusPane` receiver method. |
| key handler | [UID:000411][0x00488900-0x00488968.ClanJoinListPaneOnKeyEvent](by-memory/0x00488900-0x00488968.ClanJoinListPaneOnKeyEvent.md) | Vtable slot `0x006157d4`; `ClanJoinListPane::OnKeyEvent(const PaneKeyEvent *event)` delegates to `ListPane::OnKeyEvent`, narrows the event key, reads inherited `m_selectedIndex`, fetches the selected row through `GetSelectedEntry`, then loads `g_pClanStatusPane` and sends the selected join-list row through `ClanStatusPane::SendClanJoinListSelectionPacket` on Enter (`0x0d`). |
| inherited/shared `DrawItem` | [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) | Reuses `ClanStringListPane::DrawItem(int rowIndex, const wchar_t *rowText, const RectBounds *rowBounds)` at vtable slot `+0x80`; this class does not own a separate draw body. |

## Evidence Notes

- IDA MCP rechecked on 2026-05-24: `ClanStatusPane::ClanStatusPane` installs `ClanJoinListPane` vtables at object offsets `+0x0`, `+0xa0`, and `+0xa4`.
- 2026-06-16 A002 continuation audit in live IDA MCP session `a002_goal65_20260616` reconfirmed `sub_484030` size `0x1f2` and constructor vtable store xref `0x0048416f -> 0x00615770` for the primary `ClanJoinListPane` table.
- 2026-06-05 live IDA refresh of [UID:0002NR][0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction](by-memory/0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction.md) reconfirms exact `0x21` bounds, the `0x004888f1` successor byte outside the function, vtable-only xref at `0x006157ec`, no direct callers, selected-index guard at object offset `+0x134`, selected-text retrieval through `0x004f3dc0`, clan status singleton/global load from `0x0067ade4`, and downstream packet call to `0x00485590`.
- 2026-06-16 `lookup_funcs` reconfirmed `sub_4888D0` size `0x21`, `sub_488900` size `0x68`, and the packet helper `sub_485590` size `0xf2`. `xref_query` reports the selected-row action has a vtable-only data ref at `0x006157ec`, the key/event handler has a vtable-only data ref at `0x006157d4`, and the helper `0x00485590` has exactly two code callers in this join-list path (`0x004888ea` and `0x00488951`).
- 2026-06-16 decompilation shows both join-list paths reading selected index `+0x134`, resolving the selected text through `0x004f3dc0`, and calling `0x00485590`. The key/event handler delegates to `0x004f4300`, narrows the event byte through the process ctype object, and gates the send on Enter (`0x0d`).
- 2026-06-16 decompilation of `0x00485590` reconfirmed packet bytes `75, 2, 1` (`0x4b`, subtype `2`, action `1`), `WideCharToMultiByte` conversion, the `< 0x100` conversion and `< 0x80` packet-length guards, and final send through [UID:0001P0][0x0067a7ec-0x0067a7f0.g_packetSender](by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md) / `0x0067a7ec`.
- 2026-06-21 B008 reanalysis updates the packet-helper ownership conclusion: both join-list paths supply row text from inherited `ListPane` storage but explicitly change the receiver to `g_pClanStatusPane` before the call. Therefore [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md) is owned/emitted by [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md); this class remains the selected-text caller/data source.
- [UID:000411][0x00488900-0x00488968.ClanJoinListPaneOnKeyEvent](by-memory/0x00488900-0x00488968.ClanJoinListPaneOnKeyEvent.md) is the exact class-owned key handler split from the mixed [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md) index. It carries first-draft `ClanJoinListPane::OnKeyEvent(const PaneKeyEvent *event)` C++ and preserves the vtable-only/no-direct-caller proof at `0x006157d4`.
- [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) documents the shared row renderer, with the `ClanJoinListPane` vtable using it at `0x006157f0`. The source body remains emitted once as `ClanStringListPane::DrawItem(int rowIndex, const wchar_t *rowText, const RectBounds *rowBounds)`, while this class's vtable reuses that implementation through the inherited `ListPane` draw slot.
- 2026-06-22 B014 PE/Capstone revalidation confirms this class's reused draw slot is one of exactly three absolute refs to `0x004887d0`; no direct rel32 or RVA route exists, and adjacent `ClanJoinListPane` slots stay separate (`+0x7c` at `0x006157ec -> 0x004888d0`, `+0x64` at `0x006157d4 -> 0x00488900`). This reinforces that `ClanJoinListPane` is a reuse context and should not get a duplicate draw-body emitter.
- IDA vtable symbol `??_7ClanJoinListPane@@6B@` starts at `0x00615770`; slot `+0x7c` points to `0x004888d0` and slot `+0x80` points to `0x004887d0`.
- 2026-06-16 `get_bytes` confirmed only `0xcc` padding at `0x004888c1-0x004888d0`, `0x004888f1-0x00488900`, and `0x00488968-0x00488970`.
- 2026-06-16 A002 continuation audit also checked `auto-generated/NexusTK/social/Clan.cpp`; the root is still zero bytes, matching the blank final-C++ block while inherited `ListPane` slot names, selected-entry helper names, subtype/action enum names, and final class declaration spelling remain source-quality blockers.
- With the selected-row action at `82/90`, the shared input-handler cluster at `84/90`, the shared draw method at `84/90`, exact vtable data at `86/91`, and inline construction evidence in [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md), this class now clears the stricter `85/85` target gate for the single-owner selected-row action and the shared handler evidence.
- 2026-06-17 B002 source-quality pass raises [UID:0002NR][0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction](by-memory/0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction.md) to `87/91` and populates first-draft C++ as `ClanJoinListPane::OnSelectedRowAction()`. Raw bytes prove the negative-index early return and positive-path packet-helper return preservation, so the child uses an `int` return unless later source declarations prove the vtable return is ignored.

## Blocker Investigation

- Owner/emitter: unchanged as [UID:0000I8][Clan](by-file/Clan.md). The selected-row action can remain semantically attached to this class, while the shared input-handler range remains file-parented because it also contains `ClanEnlistListPane` methods.
- Split/merge/range: the old mixed [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md) aggregate is now only a non-emitting index. This class owns exact child [UID:000411][0x00488900-0x00488968.ClanJoinListPaneOnKeyEvent](by-memory/0x00488900-0x00488968.ClanJoinListPaneOnKeyEvent.md), while [UID:00002C][ClanEnlistListPane](by-class/ClanEnlistListPane.md) owns the adjacent enlist children. Padding before and after the join key handler remains `0xcc` alignment, not source.
- Field/type/helper names: selected index `+0x134`, selected-entry retrieval, subtype `2` action `1` packet shape, `g_pClanStatusPane` receiver setup, and `g_packetSender` send dependency are verified. Source-facing names for the common `ListPane` virtual slots, the helper at `0x004f3dc0`, and the packet subtype enum remain unsafe because no source-quality names were found in IDA or current support docs.
- Final C++: the class declaration remains blank. The selected-row child now has first-draft C++; the class-level declaration still waits on inherited slot names, common `ListPane` declarations, and source enum/helper names.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md)
- [UID:00002L][ClanStringListPane](by-class/ClanStringListPane.md)
- [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md)
- [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md)
- [UID:0002NR][0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction](by-memory/0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction.md)
- [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md)
- [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md)
- [UID:000411][0x00488900-0x00488968.ClanJoinListPaneOnKeyEvent](by-memory/0x00488900-0x00488968.ClanJoinListPaneOnKeyEvent.md)
- [UID:0002MQ][0x00615570-0x006158f4.ClanPaneListVtableData](by-memory/0x00615570-0x006158f4.ClanPaneListVtableData.md)
- [UID:0001P0][0x0067a7ec-0x0067a7f0.g_packetSender](by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md)

## Changes

- 2026-05-27: Replaced the raw `0x00485590` helper reference with [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md). Evidence: IDA MCP confirms the helper sends opcode `0x4b`, subtype `2`, action `1`, with selected row text, and callers include the `0x004888d0` selected-row action.
- 2026-05-27: The method inventory previously stopped at the `0x004888d0` selected-row action. Added the vtable-backed `0x00488900-0x00488968` key/event handler from [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md). Evidence: IDA MCP data xref `0x006157d4 -> 0x00488900`, decompilation, and call to [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md).
- What existed before: the page documented inline construction, selected-row action, key/event handler, and join-list packet helper, but metadata was still `0/0`.
- What it was changed to: scores were set to `76/82`.
- Summary and evidence: constructor setup, vtable slots, shared row renderer, selected-row send, and Enter-key path are covered; recovered method names and source-facing declaration remain incomplete.
- 2026-05-31: Replaced raw draw/action addresses with exact by-memory links. Evidence: IDA MCP `lookup_funcs`, `decompile`, and `xrefs_to` confirm the shared draw method, selected-row action method, and vtable slots.
- 2026-06-05: Raised from `76/82` to `82/88`, attached to [UID:0000I8][Clan](by-file/Clan.md), removed stale recovered-file and issue-note provenance, and promoted [UID:0002NR][0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction](by-memory/0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction.md) from file-parent routing to semantic class parent `00002H`. Evidence: live IDA MCP child refreshes reconfirm selected-row action bounds and vtable-only xref, the shared input-handler page documents the adjacent join-list event override, the shared draw page documents the row renderer slot, and inline construction remains anchored in [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md).
- 2026-06-16 A002 Goal 2 class-completion refresh:
  - Raised from `82/88` to `86/90`.
  - Owner/emitter remains [UID:0000I8][Clan](by-file/Clan.md).
  - Evidence: live IDA MCP session `a002_goal65_20260616` reconfirmed constructor/vtable reachability, selected-row and key/event handler function sizes, vtable-only refs at `0x006157ec` and `0x006157d4`, shared draw slot `0x006157f0`, selected-row retrieval through `0x004f3dc0`, Enter-gated calls to `0x00485590`, subtype `2` action `1` packet serialization, `g_packetSender` send dependency, and surrounding `0xcc` padding.
  - Remaining cap: final class declaration, common `ListPane` virtual slot names, selected-entry helper name, and source enum names for the packet subtype/action remain unresolved.
- 2026-06-16 A002 same-task continuation audit:
  - Scores remain `86/90`; owner/emitter remains [UID:0000I8][Clan](by-file/Clan.md).
  - Evidence checked: live IDA `lookup_funcs`, `xrefs_to`, `decompile`, `get_bytes`, linked helper pages, class/file coverage rows, and the generated `Clan.cpp` root. The remaining source-facing method/helper/enum names could not be resolved safely because no checked source-quality evidence exposes original declarations beyond vtable slots, offsets, synthetic helper labels, and packet bytes.
- 2026-06-17 B002 source-quality pass:
  - Class score unchanged, but [UID:0002NR][0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction](by-memory/0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction.md) is now source-ready as first-draft `OnSelectedRowAction()`.
  - Evidence: selected index at inherited `ListPane +0x134`, selected text through `0x004f3dc0`, `g_pClanStatusPane` from `0x0067ade4`, join-list subtype `2` action `1` helper call, vtable-only slot `0x006157ec`, and rejection of generic `ListPane`, key/event handler, and refresh-helper ownership.
- 2026-06-20 Rule 26 shared-draw update:
  - Clarified that `ClanJoinListPane` reuses [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) as `ClanStringListPane::DrawItem(...)`; no separate `ClanJoinListPane` draw implementation or emitter route is created.
  - Evidence: B001 source-quality reanalysis ties the reused vtable slot `0x006157f0` to the same row renderer body and to the `ListPane::OnPaint` `(rowIndex, itemPayload, rowBounds)` dispatch shape.
- 2026-06-22 B014 shared-draw support sync:
  - Confirmed the `0x006157f0` draw slot through direct PE absolute-reference scanning and kept `ClanJoinListPane` as a caller/reuse context only.
  - Evidence: the only route to [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) is the shared vtable slot; class-specific action and key handlers are adjacent separate slots, so draw C++ remains emitted once by [UID:00002L][ClanStringListPane](by-class/ClanStringListPane.md).
- 2026-06-21 B008 support sync:
  - Clarified that this class supplies selected row text to [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md), while [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md) owns/emits the packet helper because both callers load `g_pClanStatusPane` into `ECX`.
  - No class score change; the change corrects caller-versus-helper ownership and leaves final class declaration blockers unchanged.
- 2026-06-22 Rule 26 split-child support sync:
  - Replaced stale mixed-handler wording with exact child [UID:000411][0x00488900-0x00488968.ClanJoinListPaneOnKeyEvent](by-memory/0x00488900-0x00488968.ClanJoinListPaneOnKeyEvent.md).
  - Evidence: B015 raw PE recheck confirms the `0x00488900-0x00488968` body, vtable-only pointer `0x006157d4`, zero direct rel32 callers, `ListPane::OnKeyEvent` delegation, event-byte narrowing, selected-row fetch, Enter gate, and `g_pClanStatusPane->SendClanJoinListSelectionPacket` route.
