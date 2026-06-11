*** UID:00002K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanStatusPane

## Status

- Confidence: strong for confirmed methods and feature ownership; medium for nearby unowned helper functions.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Exact vtable/global anchors: [UID:0002MQ][0x00615570-0x006158f4.ClanPaneListVtableData](by-memory/0x00615570-0x006158f4.ClanPaneListVtableData.md), [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md)
- Parent attachment: [UID:0000I8][Clan](by-file/Clan.md), which is `90/85` and meets the corrected completion/confidence gate.

## Class Purpose

`ClanStatusPane` is the main visible clan status panel. It owns child panes for clan information, join lists, and enlist lists, draws the `AN*.EPF` status backgrounds and `ANBUT.EPF` selection overlay, switches between status/manage tabs, hit-tests action rows, and calls a row-action packet helper for server-side clan operations.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClanStatusPane` | `0x00484030-0x00484221` | Constructs base `Pane`, installs singleton `g_pClanStatusPane`, creates `ClanInfoListPane`, `ClanJoinListPane`, and `ClanEnlistListPane` children. |
| constructor cleanup | [UID:00021B][0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup](by-memory/0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup.md) | Compiler-generated cleanup for partially constructed child panes; ignore as handwritten source. |
| `ParseClanAttributePacket` | [UID:00010B][0x004842b0-0x00484a50.ClanAttributePacketParser](by-memory/0x004842b0-0x00484a50.ClanAttributePacketParser.md) | Handles opcode `0x43` subtype `0`, decodes attribute/status strings into `ClanStatusPane` storage, refreshes child panes, and invalidates/redraws the pane. |
| `OnPaintFrame` | `0x00484a60-0x00484cb0` | Draws `AN1.EPF`, `AN2.EPF`, or `AN3.EPF`, selection overlay `ANBUT.EPF`, and visible text rows. |
| `OnKeyInput` | `0x00484cd0-0x00484da2` | Handles Page Up/Page Down tab switching and Escape close/reset behavior. |
| `OnMouseEvent` | `0x00484db0-0x00484f16` | Hit-tests row clicks, toggles tabs, invalidates selection rectangles, and dispatches row actions through `0x00487600`. |
| packet/event dispatcher | [UID:00021C][0x00484f70-0x0048540b.ClanStatusPacketDispatcher](by-memory/0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md) | Secondary-vtable handler for opcode `0x43` clan packets; updates clan state and opens clan modal dialogs. |
| `DrawInfoRow` | `0x00486800-0x00486cde` | Draws centered row text from per-row storage offsets. |
| `GetRowRect` | `0x00486d20-0x00486f3f` | Computes fixed clickable row rectangles by current view mode. |
| `HitTestRow` | `0x00486f90-0x00487291` | Iterates rows `0-15` and returns the row containing a mouse point. |
| `IsRowActionAllowed` | [UID:00021N][0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper](by-memory/0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper.md) | Raw helper that gates row action availability using state bytes at `+0xf8` and `+0xf9`. |
| `RefreshChildPanes` | [UID:00021O][0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes](by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md) | Refreshes or clears the info, join-list, and enlist-list child panes. |
| `ShowInfoList` | [UID:00021P][0x004873c0-0x00487475.ClanStatusPaneShowInfoList](by-memory/0x004873c0-0x00487475.ClanStatusPaneShowInfoList.md) | Sets view byte `+0xf8` to `2`, configures the info child pane at `+0x2510`, and invalidates the pane. |
| `ShowJoinList` | [UID:00021Q][0x00487480-0x00487535.ClanStatusPaneShowJoinList](by-memory/0x00487480-0x00487535.ClanStatusPaneShowJoinList.md) | Sets view byte `+0xf8` to `3`, configures the join-list child pane at `+0x2514`, and invalidates the pane. |
| `ShowEnlistList` | [UID:00021R][0x00487540-0x004875f5.ClanStatusPaneShowEnlistList](by-memory/0x00487540-0x004875f5.ClanStatusPaneShowEnlistList.md) | Sets view byte `+0xf8` to `4`, configures the enlist-list child pane at `+0x2518`, and invalidates the pane. |
| destructor/thunks | `0x0048c32b`, `0x0048c336`, `0x0048c590-0x0048c63f` | Vtable thunk and scalar deleting destructor; destroys child panes and clears `g_pClanStatusPane`. |

## Evidence Notes

- IDA confirms all listed method starts and sizes.
- 2026-06-05 IDA MCP recheck confirms the frame/input virtual band at [UID:00010C][0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput](by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md) uses `ClanStatusPane` vtable entries `0x006155b4`, `0x006155c0`, and `0x006155c4`; `OnPaintFrame` selects `AN1.EPF`/`AN2.EPF`/`AN3.EPF` and `ANBUT.EPF` through [UID:0002MP][0x006163dc-0x006164f0.ClanResourceStringData](by-memory/0x006163dc-0x006164f0.ClanResourceStringData.md); `OnKeyInput` calls `ClanStatusPaneRefreshChildPanes`; and `OnMouseEvent` hit-tests rows and dispatches row-action packets through `0x00487600`.
- 2026-06-05 IDA MCP recheck confirms [UID:00010G][0x00486800-0x00487291.ClanStatusPaneRows](by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md) is the local row layout block used by the frame/input virtuals: `DrawInfoRow` renders rows `0` and `2-13` from fixed text storage offsets, `GetRowRect` returns view-gated rectangles for rows `2-15`, and `HitTestRow` loops those rectangles for mouse input.
- The row-action helper at `0x00487600` is a real IDA function; it is called from `OnMouseEvent` and sends opcode `0x4b` row subcommands.
- The packet/event dispatcher at [UID:00021C][0x00484f70-0x0048540b.ClanStatusPacketDispatcher](by-memory/0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md) has a vtable/data xref at `0x006155cc`, accepts opcode `0x43` clan packets, and dispatches 13 packet subtypes.
- IDA confirms [UID:00021O][0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes](by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md) has callers in the clan attribute packet parser and `ClanStatusPane::OnKeyInput`. IDA vtable scans show no pointer to `0x00487370` in `ClanEnlistInputDialog` vtables, so the older `HideAllControls` owner label is stale.
- [UID:00021O][0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes](by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md) is an exact `85/88` direct child candidate: it touches only the three `ClanStatusPane` child-pane fields documented here, has exactly two status-pane callers, and has no direct callees because all work is child-pane virtual dispatch.
- 2026-06-05 IDA MCP recheck confirms [UID:00010B][0x004842b0-0x00484a50.ClanAttributePacketParser](by-memory/0x004842b0-0x00484a50.ClanAttributePacketParser.md) is reached from dispatcher case `0` with `this - 0xa0`, calls `ClanStatusPaneRefreshChildPanes`, and writes `ClanStatusPane` status/text storage; it is not a `ClanEnlistInputDialog` receiver.
- The raw view-switch helpers at [UID:00021P][0x004873c0-0x00487475.ClanStatusPaneShowInfoList](by-memory/0x004873c0-0x00487475.ClanStatusPaneShowInfoList.md), [UID:00021Q][0x00487480-0x00487535.ClanStatusPaneShowJoinList](by-memory/0x00487480-0x00487535.ClanStatusPaneShowJoinList.md), and [UID:00021R][0x00487540-0x004875f5.ClanStatusPaneShowEnlistList](by-memory/0x00487540-0x004875f5.ClanStatusPaneShowEnlistList.md) all refresh the three child panes, configure one child pointer, and invalidate receiver offset `+0x44`.
- Constructor-created child panes install `ClanInfoListPane`, `ClanJoinListPane`, and `ClanEnlistListPane` vtables, tying this class to the broader Clan module. The child setup is inline in this constructor rather than separate IDA-backed child constructors.
- 2026-05-31 IDA MCP recheck confirms the constructor writes [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md) at `0x0067ade4` and installs `ClanStatusPane` vtables at `0x00615570`, `0x006155bc`, and `0x006155ec`, matching [UID:0002MQ][0x00615570-0x006158f4.ClanPaneListVtableData](by-memory/0x00615570-0x006158f4.ClanPaneListVtableData.md).

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md)
- [UID:00010B][0x004842b0-0x00484a50.ClanAttributePacketParser](by-memory/0x004842b0-0x00484a50.ClanAttributePacketParser.md)
- [UID:0002MQ][0x00615570-0x006158f4.ClanPaneListVtableData](by-memory/0x00615570-0x006158f4.ClanPaneListVtableData.md)
- [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md)
- [UID:00010C][0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput](by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md)
- [UID:00021C][0x00484f70-0x0048540b.ClanStatusPacketDispatcher](by-memory/0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md)
- [UID:00010G][0x00486800-0x00487291.ClanStatusPaneRows](by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md)
- [UID:00021N][0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper](by-memory/0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper.md)
- [UID:00021O][0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes](by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md)
- [UID:00021P][0x004873c0-0x00487475.ClanStatusPaneShowInfoList](by-memory/0x004873c0-0x00487475.ClanStatusPaneShowInfoList.md)
- [UID:00021Q][0x00487480-0x00487535.ClanStatusPaneShowJoinList](by-memory/0x00487480-0x00487535.ClanStatusPaneShowJoinList.md)
- [UID:00021R][0x00487540-0x004875f5.ClanStatusPaneShowEnlistList](by-memory/0x00487540-0x004875f5.ClanStatusPaneShowEnlistList.md)
- [UID:00010H][0x00487600-0x0048779f.ClanStatusRowActionPacket](by-memory/0x00487600-0x0048779f.ClanStatusRowActionPacket.md)
- [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md)
- [UID:00002E][ClanInfoListPane](by-class/ClanInfoListPane.md)
- [UID:00002L][ClanStringListPane](by-class/ClanStringListPane.md)
- [UID:00002H][ClanJoinListPane](by-class/ClanJoinListPane.md)
- [UID:00002C][ClanEnlistListPane](by-class/ClanEnlistListPane.md)
- [UID:00021B][0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup](by-memory/0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup.md)

## Score Rationale

- Completion is raised to `85` because the class page now covers the constructor, cleanup exclusion, attribute parser, frame/input band, packet dispatcher, row helpers, refresh/view helpers, row-action helper, destructor/thunk companions, exact vtable data, singleton storage, and direct parent/file placement with the corrected `85/85` gate.
- Confidence remains `86` because live IDA evidence consistently supports `ClanStatusPane` ownership for the documented method family and singleton/vtable anchors; it stays below final-source quality because exact full object layout, final child virtual slot names, and the Clan/ClanDialogs/ClanBank source split are still not fully settled.

## Changes

- 2026-05-27: The constructor support row previously omitted raw cleanup bytes at `0x00484230-0x004842ad`. Added [UID:00021B][0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup](by-memory/0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup.md) as compiler-generated cleanup rather than a handwritten method. Evidence: IDA raw disassembly shows vtable restoration, child-pane delete calls, singleton/global clear, and base teardown tail jump with no function object at the start.
- 2026-05-27: The packet/event dispatcher after `OnMouseEvent` was previously only a nearby unowned helper region. Added [UID:00021C][0x00484f70-0x0048540b.ClanStatusPacketDispatcher](by-memory/0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md) as a likely `ClanStatusPane` secondary-vtable handler. Evidence: IDA vtable/data xref at `0x006155cc`, opcode `0x43` packet check, and 13-case packet switch.
- 2026-05-27: The `0x00487291-0x00487600` region was previously undocumented and `0x00487370` was indirectly treated as `ClanEnlistInputDialog::HideAllControls` through generated data. Added [UID:00021N][0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper](by-memory/0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper.md) through [UID:00021R][0x00487540-0x004875f5.ClanStatusPaneShowEnlistList](by-memory/0x00487540-0x004875f5.ClanStatusPaneShowEnlistList.md) as `ClanStatusPane` helpers. Evidence: IDA callers from `ClanStatusPane`/clan parser paths, child-pointer offsets `+0x2510/+0x2514/+0x2518`, and no `0x00487370` pointer in `ClanEnlistInputDialog` vtables.
- What existed before: the page had detailed constructor, frame/input, packet dispatcher, row helpers, child-pane helper, destructor, and ownership evidence, but metadata was still `0/0`.
- What it was changed to: scores were set to `84/86`.
- Summary and evidence: major class behavior, child pane setup, packet dispatch, row drawing/hit-testing/action eligibility, view switching, and wrong-owner cleanup are documented; exact full object layout and a few nearby helper ownership questions keep it below complete.
- 2026-05-31: Marked class reconstructable and added direct constructor/vtable/singleton anchors.
  - Before: the page relied on the constructor row and class text for vtable/global evidence, and `RECONSTRUCTABLE` was blank.
  - After: the class links exact vtable data and singleton storage, and is marked `RECONSTRUCTABLE:TRUE` while leaving autogen parent/code blank until final-source confidence is much higher.
  - Evidence: IDA MCP `py_eval`/`xrefs_to` confirmed constructor writes to `0x0067ade4` and vtable stores to the `ClanStatusPane` table bases.
- 2026-06-05: Added [UID:00010B][0x004842b0-0x00484a50.ClanAttributePacketParser](by-memory/0x004842b0-0x00484a50.ClanAttributePacketParser.md) as a `ClanStatusPane` method.
  - Before: this class page mentioned the parser only indirectly through dispatcher/refresh evidence, while the exact parser page still used a `ClanEnlistInputDialog` owner label.
  - After: the method table and evidence notes record the parser as `ClanStatusPane` state parsing/refresh behavior.
  - Evidence: live IDA MCP decompilation of `0x00484f70` shows the case `0` call uses the receiver adjusted by `-0xa0`, and the parser body calls the status-pane child refresh helper and writes status-pane storage.
- 2026-06-05: Corrected the status-panel frame/input evidence.
  - Before: class purpose and `OnPaintFrame` still called the status resources `CLAN*.EPF`/`CLANBUT.EPF`.
  - After: the class page records the live `AN1.EPF`, `AN2.EPF`, `AN3.EPF`, and `ANBUT.EPF` names and links the frame/input method band's vtable, resource, refresh, and row-action evidence.
  - Evidence: IDA MCP decompilation of `0x00484a60`, `0x00484cd0`, and `0x00484db0`, plus resource-string page [UID:0002MP][0x006163dc-0x006164f0.ClanResourceStringData](by-memory/0x006163dc-0x006164f0.ClanResourceStringData.md).
- 2026-06-05: Tightened the row layout helper evidence.
  - Before: row drawing/geometry methods were listed but still relied on the exact memory page's placeholder scoring.
  - After: the class page notes the row storage offsets, rectangle gates, and hit-test relationship captured by [UID:00010G][0x00486800-0x00487291.ClanStatusPaneRows](by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md).
  - Evidence: IDA MCP decompilation and callers for `0x00486800`, `0x00486d20`, and `0x00486f90`.
- 2026-06-05: Removed stale recovered-file/projection wording from the constructor and helper notes, attached the class to [UID:0000I8][Clan](by-file/Clan.md), and refreshed [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md) to `84/90`.
  - Evidence: live IDA MCP lookup, callers, xrefs, callees, decompilation, disassembly, and byte reads for `0x00484030-0x004842ad`.
- 2026-06-08 A010 Batch109: Raised completion from `84` to `85` while keeping confidence at `86`.
  - Summary/evidence: added corrected gate and direct-child evidence for [UID:00021O][0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes](by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md), which touches only the documented `ClanStatusPane` child-pane fields and is called only by the clan attribute parser and `OnKeyInput`. [UID:0000I8][Clan](by-file/Clan.md) is now `90/85`, so the class and file parent relationship also clears the corrected `85/85` gate.
