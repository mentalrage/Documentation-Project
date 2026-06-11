*** UID:000090 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewGroupPane

## Status

- Confidence: strong for group UI ownership and packet behavior; medium for the projected `UpdateGroupEntry` boundary.
- Likely source file: [UID:0000JS][Group](by-file/Group.md)
- Address range: [UID:0001HC][0x0056c4c0-0x0056e939.GroupPanes](by-memory/0x0056c4c0-0x0056e939.GroupPanes.md); exact vtable data [UID:0002NL][0x00624550-0x006245dc.NewGroupPaneVtableData](by-memory/0x00624550-0x006245dc.NewGroupPaneVtableData.md); destructor thunks at [UID:0001HM][0x00573273-0x005732b5.GroupPaneAdjustorThunks](by-memory/0x00573273-0x005732b5.GroupPaneAdjustorThunks.md)
- Current recovered file: `source-3/simroot_v2/class_NewGroupPane.cpp`
- Autogen status: attached to direct file parent [UID:0000JS][Group](by-file/Group.md), which is currently `89/85`; final C++ remains blank because raw helper names, exact member names, and final source declaration are not source-quality.

## Class Purpose

`NewGroupPane` is the main party/group management pane. It requests the group member list, owns a custom scroll child, lays out normal and expanded views, renders member rows with status and HP/MP information, handles keyboard/mouse input, parses group list packets into player data, updates map markers, and toggles expanded mode.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `NewGroupPane` | `0x0056ca20-0x0056caea` | Constructs panel state, loads number font data, creates `ScrollNewGroupPane`, and initializes collapsed/expanded state. |
| `RequestGroupList` | `0x0056cb80-0x0056cbe5` | Sends group list request opcode `0x2d`, subcommand `1`. |
| `OnLayout` | `0x0056cbf0-0x0056cc77` | Places the scroll child and updates scroll range. |
| `OnActivate` | `0x0056cc80-0x0056cd24` | Computes normal or expanded pane bounds. |
| `UpdateScrollRange` | `0x0056cd30-0x0056ce4a` | Clamps and applies scroll range/position from member count. |
| `OnPaint` | `0x0056ce50-0x0056da02` | Draws background, member rows, names, class/status, HP/MP bars, and number strings. |
| `OnKeyPress` | `0x0056da10-0x0056daf6` | Handles keyboard navigation/toggle actions. |
| `OnMouseClick` | `0x0056db00-0x0056dd45` | Handles row/toggle interaction. |
| `HandleGroupPacket` | `0x0056dd50-0x0056def6` | Secondary-vtable packet handler; accepts packet opcode `99`, dispatches subtype `2` to the full group-list parser, and handles subtype `3` member-position/status updates. |
| `SetScrollPosition` | `0x0056df00-0x0056df37` | Applies scroll-position callback from scrollbar. |
| `OnOpen` / `OnClose` | `0x0056df40-0x0056dfc5` | Attaches/detaches pane behavior around opening and closing. |
| `GetToggleButtonRect` | `0x0056dfd0-0x0056e026` | Returns the expanded/collapsed toggle rect. |
| `ParseGroupListPacket` | `0x0056e130-0x0056e565` | Parses group list packet, updates cached members, refreshes map markers, and repaints. |
| raw entry update helper | `0x0056e570-0x0056e6c1` | Wave3 projected `UpdateGroupEntry` body; IDA does not recognize this as a function start and current xrefs remain empty, but the aggregate page records it as a raw member-entry update helper. |
| `DrawNumberString` | `0x0056e6d0-0x0056e813` | Draws digits and punctuation from `9X11FONT.BIN`/comma EPF assets. |
| `ToggleExpandedMode` | `0x0056e8c0-0x0056e939` | Toggles expanded view and relayouts/repaints. |

## Evidence Notes

- IDA MCP confirms the listed real function starts and the constructor xref from `GeneralPurposePanel` at `0x004b84f5`.
- IDA confirms `ParseGroupListPacket` at `0x0056e130`; it calls `MapPane`-style marker helpers at `0x0050e810` and `0x0050e4c0`.
- IDA reports no function at Wave3's `UpdateGroupEntry` start `0x0056e570`; source layout work should not use that address as a hard anchor.
- Primary, secondary, and tertiary vtables are `0x00624554`, `0x006245a4`, and `0x006245d4`; the secondary/tertiary destructor slots use adjustor thunks `0x0057329f` and `0x005732aa`, and the scalar deleting destructor is `0x00573570-0x00573634` in [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md).
- 2026-05-31 IDA MCP confirms the exact vtable-data child [UID:0002NL][0x00624550-0x006245dc.NewGroupPaneVtableData](by-memory/0x00624550-0x006245dc.NewGroupPaneVtableData.md): the range starts at `NewGroupPane` RTTI and ends before `CollectionPane`.
- 2026-06-07 A001 Batch094 live IDA `lookup_funcs` reconfirmed the modeled NewGroupPane functions from constructor `0x0056ca20-0x0056caeb` through toggle `0x0056e8c0-0x0056e939`, including the previously omitted secondary-vtable handler `0x0056dd50-0x0056def6`.
- 2026-06-07 `xrefs_to` reconfirmed constructor call `0x004b84f5`, secondary-vtable handler data ref `0x006245b4`, parser call `0x0056dd84 -> 0x0056e130`, no xrefs to raw `0x0056e570`, and constructor/destructor stores to vtable bases `0x00624554`, `0x006245a4`, and `0x006245d4`.
- 2026-06-07 decompilation of `0x0056dd50` shows packet opcode byte `99`; subtype `2` dispatches to `0x0056e130`, while subtype `3` decodes a member id/name/position payload, updates cached group member fields, calls `MapPane` marker helper `0x0050e4c0`, refreshes the scroll range through `0x0056cd30`, and invalidates the pane through vtable slot `+0x20`.
- 2026-06-07 parent-gate check: direct parent [UID:0000JS][Group](by-file/Group.md) is `89/85`, and this class now clears the corrected child-and-parent `85/85` gate.

## Cross-References

- [UID:0000JS][Group](by-file/Group.md)
- [UID:0001HC][0x0056c4c0-0x0056e939.GroupPanes](by-memory/0x0056c4c0-0x0056e939.GroupPanes.md)
- [UID:0002NL][0x00624550-0x006245dc.NewGroupPaneVtableData](by-memory/0x00624550-0x006245dc.NewGroupPaneVtableData.md)
- [UID:0001XP][GroupPaneFamilyVtables](by-type/by-vtable/GroupPaneFamilyVtables.md)
- [UID:0001HM][0x00573273-0x005732b5.GroupPaneAdjustorThunks](by-memory/0x00573273-0x005732b5.GroupPaneAdjustorThunks.md)
- [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md)
- [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md)
- [UID:0001KR][0x005adc20-0x005adcb3.GroupMemberMarkers](by-memory/0x005adc20-0x005adcb3.GroupMemberMarkers.md)

## Changes

- Before: destructor ownership was documented through the secondary/tertiary thunk starts only.
- Changed to: the scalar deleting destructor range `0x00573570-0x00573634` is now linked through [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md).
- Evidence: 2026-05-28 IDA MCP reports `sub_573570` as the `NewGroupPane` scalar deleting destructor and `0x0057329f` / `0x005732aa` as adjustor thunks into it.
- Before: completion/confidence metadata were `0/0` despite detailed class, method, vtable, and packet-flow notes.
- Changed to: `COMPLETION:78` and `CONFIDENCE:76`.
- Evidence: the page covers construction, layout, painting, input, packet parsing, scrolling, vtable/destructor ownership, and known IDA-backed caveats; confidence remains limited by the projected `UpdateGroupEntry` boundary.
- 2026-05-31: Added exact vtable-data child and raised metadata from `78/76` to `82/84`.
  - Before: vtable evidence was only linked through the family page, and confidence stayed lower because the family range was not split from neighboring collection data.
  - After: exact vtable-data bounds, constructor/destructor stores, and adjustor-thunk slots are linked directly; confidence remains below final-audit level because the projected `UpdateGroupEntry` boundary is still unresolved.
  - Evidence: IDA MCP `py_eval` and `xrefs_to` checks on `0x00624550-0x006245dc` confirmed the RTTI boundaries and store sites.
- 2026-06-07 A001 Batch094 strict parent-gate update:
  - Before: `82/84`, reconstructable, but unassigned because the child side did not clear the corrected gate.
  - After: `85/86` and `AUTOGEN_PARENT_UID:0000JS`.
  - Evidence: live IDA reconfirmed all modeled method bounds, added the omitted secondary-vtable packet handler `0x0056dd50-0x0056def6`, documented opcode `99` subtype `2/3` packet behavior, reconfirmed constructor/parser/vtable xrefs, and retained the raw `0x0056e570` no-xref caveat. Final C++ remains blank pending source-quality field/helper names.
